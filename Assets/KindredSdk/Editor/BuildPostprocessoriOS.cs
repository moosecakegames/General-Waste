using UnityEngine;
using System.IO;
using System;
#if UNITY_EDITOR_OSX
using UnityEditor;
using UnityEditor.iOS.Xcode;
using UnityEditor.iOS.Xcode.Extensions;
using UnityEditor.Callbacks;
#endif

namespace KindredSDK.Editor
{
    public class BuildPostprocessoriOS
    {
#if UNITY_EDITOR_OSX
        private static string AppAssetsPath;
        private static string AppGroupName => EditorPrefs.GetString("APP_GROUP_NAME", "");

        [PostProcessBuild]
        private static void PostProcessBuildiOS(BuildTarget target, string buildPath)
        {
            if (target == BuildTarget.iOS)
            {
                HandleiOSPostBuild(buildPath);
            }
        }

        private static void HandleiOSPostBuild(string buildPath)
        {
            AppAssetsPath = Path.Combine(Application.dataPath, "KindredSdk", "Editor", "Templates", "iOS");

            PBXProject project = new PBXProject();
            string projPath = PBXProject.GetPBXProjectPath(buildPath);
            project.ReadFromFile(projPath);

            var mainProjectGuid = project.GetUnityMainTargetGuid();
            string unityFrameworkGuid = project.GetUnityFrameworkTargetGuid();

            project.SetBuildProperty(mainProjectGuid, "ENABLE_BITCODE", "NO");
            project.SetBuildProperty(unityFrameworkGuid, "ENABLE_BITCODE", "NO");

            AddAppGroups(buildPath, project, projPath, mainProjectGuid);
            AddFrameworks(project, mainProjectGuid, unityFrameworkGuid, buildPath);
            AddKeyboardExtension(project, mainProjectGuid, projPath, buildPath);
            HandleBridge(project, mainProjectGuid, unityFrameworkGuid, buildPath);
            UpdatePlist(buildPath);

            project.WriteToFile(projPath);
        }

        private static void AddAppGroups(string buildPath, PBXProject project, string projPath, string mainProjectGuid)
        {
            var entitlementsName = "kindred-unity.entitlements";
            var entitlementsProjPath = Path.Combine("Unity-iPhone", entitlementsName);
            var projCapability = new ProjectCapabilityManager(projPath, entitlementsProjPath, targetGuid: mainProjectGuid);
            projCapability.AddAppGroups(new string[] { AppGroupName });
            projCapability.WriteToFile();
            var entitlementsGuid = project.AddFile(Path.Combine(buildPath, entitlementsProjPath), entitlementsName);
            project.SetBuildProperty(mainProjectGuid, "CODE_SIGN_ENTITLEMENTS", entitlementsProjPath);
        }

        private static void UpdatePlist(string buildPath)
        {
            var plistPath = Path.Combine(buildPath, "Info.plist");
            // Get plist
            PlistDocument plist = new PlistDocument();
            plist.ReadFromString(File.ReadAllText(plistPath));

            // Get root
            PlistElementDict rootDict = plist.root;

            // Add app group name for defaults
            rootDict.SetString("AppGroupName", AppGroupName);

            // Write to file
            File.WriteAllText(plistPath, plist.WriteToString());
        }

        private static void HandleBridge(PBXProject project, string mainProjectGuid, string unityFrameworkGuid, string buildPath)
        {
            // Modulemap
            project.AddBuildProperty(unityFrameworkGuid, "DEFINES_MODULE", "YES");

            var moduleFile = buildPath + "/UnityFramework/UnityFramework.modulemap";
            if (!File.Exists(moduleFile))
            {
                FileUtil.CopyFileOrDirectory("Assets/Plugins/Kindred/iOS/UnityFramework.modulemap", moduleFile);
                project.AddFile(moduleFile, "UnityFramework/UnityFramework.modulemap");
                project.AddBuildProperty(unityFrameworkGuid, "MODULEMAP_FILE", "$(SRCROOT)/UnityFramework/UnityFramework.modulemap");
            }

            // Headers
            string unityInterfaceGuid = project.FindFileGuidByProjectPath("Classes/Unity/UnityInterface.h");
            project.AddPublicHeaderToBuild(unityFrameworkGuid, unityInterfaceGuid);

            string unityForwardDeclsGuid = project.FindFileGuidByProjectPath("Classes/Unity/UnityForwardDecls.h");
            project.AddPublicHeaderToBuild(unityFrameworkGuid, unityForwardDeclsGuid);

            string unityRenderingGuid = project.FindFileGuidByProjectPath("Classes/Unity/UnityRendering.h");
            project.AddPublicHeaderToBuild(unityFrameworkGuid, unityRenderingGuid);

            string unitySharedDeclsGuid = project.FindFileGuidByProjectPath("Classes/Unity/UnitySharedDecls.h");
            project.AddPublicHeaderToBuild(unityFrameworkGuid, unitySharedDeclsGuid);
        }

        private static void AddFrameworks(PBXProject project, string mainProjectGuid, string unityFrameworkGuid, string buildPath)
        {
            string[] requiredFrameworks = {
              "FleksyApps.xcframework",
              "FleksyEngine.xcframework",
              "FleksyHelperSDK.xcframework",
              "FleksyKeyboardSDK.xcframework",
              "KindredSDK.xcframework",
              "ServiceFramework.xcframework"
            };

            var unityLinkPhaseGuid = project.GetFrameworksBuildPhaseByTarget(mainProjectGuid);
            var unityFrameworkLinkPhaseGuid = project.GetFrameworksBuildPhaseByTarget(unityFrameworkGuid);

            Directory.CreateDirectory(Path.Combine(buildPath, "Frameworks"));

            foreach (var framework in requiredFrameworks)
            {
                string sourcePath = Path.Combine(AppAssetsPath, "Frameworks", framework);
                var destPath = Path.Combine(buildPath, "Frameworks", framework);
                FileUtil.CopyFileOrDirectory(sourcePath, destPath);

                var frameworkGuid = project.AddFile(destPath, Path.Combine("Frameworks", framework));

                // targetFrameworkGuid is guid of the binary you want to link with libraries.
                // If you provide the framework, you should use pbxProject.AddFile() 
                // and use the returned guid
                project.AddFileToBuildSection(mainProjectGuid, unityLinkPhaseGuid, frameworkGuid);
                project.AddFileToBuildSection(unityFrameworkGuid, unityFrameworkLinkPhaseGuid, frameworkGuid);

                project.AddFileToEmbedFrameworks(mainProjectGuid, frameworkGuid); // just embed and sign for main project
            }
        }

        private static void AddKeyboardExtension(PBXProject proj, string mainProjectGuid, string projPath, string buildPath)
        {
            var extensionName = "KindredKeyboard";

            string sourcePath = Path.Combine(AppAssetsPath, extensionName);
            var destPath = Path.Combine(buildPath, extensionName);
            FileUtil.CopyFileOrDirectory(sourcePath, destPath);

            var identifier = Application.identifier;
            string extGuid = proj.AddAppExtension(mainProjectGuid, extensionName, identifier + "." + extensionName, extensionName + "/Info.plist");

            proj.SetBuildProperty(extGuid, "IPHONEOS_DEPLOYMENT_TARGET", PlayerSettings.iOS.targetOSVersionString);
            proj.SetBuildProperty(extGuid, "TARGETED_DEVICE_FAMILY", "1,2");
            proj.SetBuildProperty(extGuid, "SWIFT_VERSION", "5.0");
            proj.SetBuildProperty(extGuid, "ENABLE_BITCODE", "NO");
            var archs = PlayerSettings.iOS.sdkVersion == iOSSdkVersion.DeviceSDK ? "arm64" : "x86_64";
            proj.SetBuildProperty(extGuid, "ARCHS", archs);  // "arm64", "armv7 arm64", "$(ARCHS_STANDARD)", "x86_64"

            // add info.plist reference to the extension
            var infoGuid = proj.AddFile(Path.Combine(buildPath, extensionName, "Info.plist"), Path.Combine(extensionName, "Info.plist"));

            // add KeyboardViewController reference to the extension
            var controllerGuid = proj.AddFile(Path.Combine(buildPath, extensionName, "KeyboardViewController.swift"), Path.Combine(extensionName, "KeyboardViewController.swift"));
            proj.AddFileToBuild(extGuid, controllerGuid); // to put it into "Compile Resources" in "Build Phase"

            // add fonts reference to the extension
            var fontGuid = proj.AddFile(Path.Combine(buildPath, extensionName, "fonts", "flicon.ttf"), Path.Combine(extensionName, "fonts", "flicon.ttf"));
            proj.AddFileToBuild(extGuid, fontGuid);   // to put it into "Copy Bundle Resources" in "Build Phase"

            // add images reference to the extension
            var imagesGuid = proj.AddFile(Path.Combine(buildPath, extensionName, "Images.xcassets"), Path.Combine(extensionName, "Images.xcassets"));
            proj.AddAssetTagForFile(extGuid, imagesGuid, "xcassets"); // introduce it as .xcassets
            proj.AddFileToBuild(extGuid, imagesGuid); // to put it into "Copy Bundle Resources" in "Build Phase"

            // add keyboard extension entitlements
            var entitlementsProjPath = Path.Combine("KindredKeyboard", "KindredKeyboard.entitlements");
            var projCapability = new ProjectCapabilityManager(projPath, entitlementsProjPath, targetGuid: mainProjectGuid);
            projCapability.AddAppGroups(new string[] { AppGroupName });
            projCapability.WriteToFile();
            var entitlementsGuid = proj.AddFile(Path.Combine(buildPath, entitlementsProjPath), entitlementsProjPath);
            proj.SetBuildProperty(extGuid, "CODE_SIGN_ENTITLEMENTS", entitlementsProjPath);
        }
#endif
    }
}