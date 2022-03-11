using System;
using System.IO;
#if UNITY_EDITOR_OSX
using UnityEditor;
using UnityEditor.Build;
using UnityEditor.Build.Reporting;
using UnityEditor.iOS.Xcode;
#endif
using UnityEngine;

namespace KindredSDK.Editor
{
#if UNITY_EDITOR_OSX
    class BuildPreprocessoriOS : IPreprocessBuildWithReport
    {
        public int callbackOrder { get { return 0; } }
        public void OnPreprocessBuild(BuildReport report)
        {
            if (report.summary.platform == BuildTarget.iOS)
            {
                IsReady(report.summary.outputPath);
            }
        }

        private void IsReady(string buildPath)
        {
            CheckInfoPlist();
            CheckPluginsKindrediOSFolder();
        }

        private void CheckPluginsKindrediOSFolder()
        {
            var folderPath = Path.Combine(Application.dataPath, "Plugins", "Kindred", "iOS");

            if (!File.Exists(Path.Combine(folderPath, "KeyboardService.swift")) ||
                !File.Exists(Path.Combine(folderPath, "KindredSdkBridge.mm")) ||
                !Directory.Exists(Path.Combine(folderPath, "Settings.bundle")) ||
                !File.Exists(Path.Combine(folderPath, "UnityFramework.modulemap")))
            {
                Debug.LogError("The plugin structure is not correct. Try reimporting the plugin.");
                // Rethrow exceptions during build postprocessing as BuildFailedException, so we don't pretend the build was fine.
                throw new BuildFailedException("The plugin structure is not correct.");
            }
        }

        private void CheckInfoPlist()
        {
#if UNITY_IOS
            var plistPath = Path.Combine(Application.dataPath, "KindredSdk", "Editor", "Templates", "iOS", "KindredKeyboard", "Info.plist");
            // Get plist
            PlistDocument plist = new PlistDocument();
            plist.ReadFromString(File.ReadAllText(plistPath));

            // Get root
            PlistElementDict rootDict = plist.root;

            if (!rootDict.values.ContainsKey("AppGroupName"))
            {
                StopBuild();
                return;
            }

            if (!rootDict.values.ContainsKey("KindredKeyboard"))
            {
                StopBuild();
                return;
            }

            if (rootDict.values.ContainsKey("AppGroupName") && string.IsNullOrEmpty(rootDict["AppGroupName"].AsString()))
            {
                StopBuild();
                return;
            }
#endif
        }

        private void StopBuild()
        {
            Debug.LogError("Prepare iOS build from Kindred setup wizard before building!");
            // Rethrow exceptions during build postprocessing as BuildFailedException, so we don't pretend the build was fine.
            throw new BuildFailedException("iOS Build is not configured properly.");
        }
    }
#endif
}