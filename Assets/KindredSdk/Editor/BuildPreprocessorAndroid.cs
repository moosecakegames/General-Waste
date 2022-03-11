using System;
using System.IO;
#if UNITY_EDITOR
using UnityEditor;
using UnityEditor.Build;
using UnityEditor.Build.Reporting;
#endif
using UnityEngine;

namespace KindredSDK.Editor
{
#if UNITY_EDITOR
    class BuildPreprocessorAndroid : IPreprocessBuildWithReport
    {
        private string PathToFileTemplates => Path.Combine(Application.dataPath, "KindredSdk", "Editor", "Templates", "Android");

        public int callbackOrder { get { return 0; } }
        public void OnPreprocessBuild(BuildReport report)
        {
            if (report.summary.platform == BuildTarget.Android)
            {
                IsReady(report.summary.outputPath);
            }
        }

        private void IsReady(string buildPath)
        {
            CheckPluginsAndroidFolder();
            CheckPluginsKindredAndroidFolder();
        }

        private void CheckPluginsAndroidFolder()
        {
            var folderPath = Path.Combine(Application.dataPath, "Plugins", "Android");

            if (!File.Exists(Path.Combine(folderPath, "AndroidManifest.xml")) ||
                !File.Exists(Path.Combine(folderPath, "baseProjectTemplate.gradle")) ||
                !File.Exists(Path.Combine(folderPath, "gradleTemplate.properties")) ||
                !File.Exists(Path.Combine(folderPath, "mainTemplate.gradle")))
            {
                Debug.LogError("Prepare Android build from Kindred setup wizard before building!");
                // Rethrow exceptions during build postprocessing as BuildFailedException, so we don't pretend the build was fine.
                throw new BuildFailedException("Android Build is not configured properly.");
            }
        }

        private void CheckPluginsKindredAndroidFolder()
        {
            var folderPath = Path.Combine(Application.dataPath, "Plugins", "Kindred", "Android");

            if (!File.Exists(Path.Combine(folderPath, "KeyboardService.kt")) ||
                !File.Exists(Path.Combine(folderPath, "kindred-sdk-unity-release.aar")) ||
                !File.Exists(Path.Combine(folderPath, "KindredSdkBridge.java")) ||
                !File.Exists(Path.Combine(folderPath, "SettingsActivity.java")))
            {
                Debug.LogError("The plugin structure is not correct. Try reimporting the plugin.");
                // Rethrow exceptions during build postprocessing as BuildFailedException, so we don't pretend the build was fine.
                throw new BuildFailedException("The plugin structure is not correct.");
            }
        }

        private void StopBuild()
        {
            Debug.LogError("Prepare Android build from Kindred setup wizard before building!");
            // Rethrow exceptions during build postprocessing as BuildFailedException, so we don't pretend the build was fine.
            throw new BuildFailedException("Android Build is not configured properly.");
        }
    }
#endif
}