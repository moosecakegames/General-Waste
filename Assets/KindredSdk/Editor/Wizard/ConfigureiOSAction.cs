using System;
using System.IO;
#if UNITY_EDITOR_OSX
using UnityEditor;
using UnityEditor.iOS.Xcode;
#endif
using UnityEngine;

namespace KindredSDK.Editor
{
    public class ConfigureiOSAction : WizardAction
    {
        private string PathToFileTemplates => Path.Combine(Application.dataPath,
            "KindredSdk", "Editor", "Templates", "iOS");
        private string PathToKindredKeyboard => Path.Combine(PathToFileTemplates, "KindredKeyboard");

        private readonly PropertiesData _propertiesData;
        public ConfigureiOSAction(PropertiesData propertiesData) : base("Configure iOS")
        {
            _propertiesData = propertiesData;
        }

        protected override bool CheckIfActionIsConfigured()
        {
            return false;
        }

        protected override void DoConfiguration()
        {
            UpdateKeyboardInfoPlist();
            PrepareLogos();
        }

        private void PrepareLogos()
        {
            CopyActiveLogos();
            CopyInactiveLogos();
#if UNITY_EDITOR_OSX
            AssetDatabase.Refresh();
#endif
        }

        private void CopyInactiveLogos()
        {
            var inactiveDirectoryPath = Path.Combine(PathToKindredKeyboard, "Images.xcassets", "LogoInactive.imageset");

            if (Directory.Exists(inactiveDirectoryPath))
            {
                // active icon 1x
                var inactive1xFrom = _propertiesData.INACTIVE_APP_ICON_1X;
                if (!string.IsNullOrEmpty(inactive1xFrom) && File.Exists(inactive1xFrom))
                {
                    var to = Path.Combine(inactiveDirectoryPath, "Kindred logo (1).png");
                    var fromTexture = LoadTextureFromAssetDatabase(inactive1xFrom);
                    var toTexture = ScaleTexture(fromTexture, 33, 33);
                    SaveTextureAsPNG(toTexture, to);
                }
                // active icon 2x
                var inactive2xFrom = _propertiesData.INACTIVE_APP_ICON_2X;
                if (!string.IsNullOrEmpty(inactive2xFrom) && File.Exists(inactive2xFrom))
                {
                    var to = Path.Combine(inactiveDirectoryPath, "Kindred logo.png");
                    var fromTexture = LoadTextureFromAssetDatabase(inactive2xFrom);
                    var toTexture = ScaleTexture(fromTexture, 66, 66);
                    SaveTextureAsPNG(toTexture, to);
                }
                // active icon 3x
                var inactive3xFrom = _propertiesData.INACTIVE_APP_ICON_3X;
                if (!string.IsNullOrEmpty(inactive3xFrom) && File.Exists(inactive3xFrom))
                {
                    var to = Path.Combine(inactiveDirectoryPath, "Kindred logo@3x.png");
                    var fromTexture = LoadTextureFromAssetDatabase(inactive3xFrom);
                    var toTexture = ScaleTexture(fromTexture, 99, 99);
                    SaveTextureAsPNG(toTexture, to);
                }
            }
        }

        private void CopyActiveLogos()
        {
            var activeDirectoryPath = Path.Combine(PathToKindredKeyboard, "Images.xcassets", "LogoActive.imageset");

            if (Directory.Exists(activeDirectoryPath))
            {
                // active icon 1x
                var active1xFrom = _propertiesData.ACTIVE_APP_ICON_1X;
                if (!string.IsNullOrEmpty(active1xFrom) && File.Exists(active1xFrom))
                {
                    var to = Path.Combine(activeDirectoryPath, "Kindred logo-1.png");
                    var fromTexture = LoadTextureFromAssetDatabase(active1xFrom);
                    var toTexture = ScaleTexture(fromTexture, 33, 33);
                    SaveTextureAsPNG(toTexture, to);
                }
                // active icon 2x
                var active2xFrom = _propertiesData.ACTIVE_APP_ICON_2X;
                if (!string.IsNullOrEmpty(active2xFrom) && File.Exists(active2xFrom))
                {
                    var to = Path.Combine(activeDirectoryPath, "Kindred logo.png");
                    var fromTexture = LoadTextureFromAssetDatabase(active2xFrom);
                    var toTexture = ScaleTexture(fromTexture, 66, 66);
                    SaveTextureAsPNG(toTexture, to);
                }
                // active icon 3x
                var active3xFrom = _propertiesData.ACTIVE_APP_ICON_3X;
                if (!string.IsNullOrEmpty(active3xFrom) && File.Exists(active3xFrom))
                {
                    var to = Path.Combine(activeDirectoryPath, "Kindred logo@3x.png");
                    var fromTexture = LoadTextureFromAssetDatabase(active3xFrom);
                    var toTexture = ScaleTexture(fromTexture, 99, 99);
                    SaveTextureAsPNG(toTexture, to);
                }
            }
        }

        private void UpdateKeyboardInfoPlist()
        {
#if UNITY_EDITOR && UNITY_IOS
            // Get plist
            string plistPath = Path.Combine(PathToKindredKeyboard, "Info.plist");
            PlistDocument plist = new PlistDocument();
            plist.ReadFromString(File.ReadAllText(plistPath));

            // Get root
            PlistElementDict rootDict = plist.root;

            // Add app group name for defaults
            rootDict.SetString("AppGroupName", _propertiesData.APP_GROUP_NAME);
            rootDict.SetString("CFBundleDisplayName", PlayerSettings.productName);

            var dict = rootDict.CreateDict("KindredKeyboard");
            dict.values.Add("AuthClientId", new PlistElementString(_propertiesData.AUTH_CLIENT_ID));
            dict.values.Add("AuthClientSecret", new PlistElementString(_propertiesData.AUTH_CLIENT_SECRET));
            dict.values.Add("AuthSharedKey", new PlistElementString(_propertiesData.AUTH_SHARED_KEY));
            dict.values.Add("UserCurrency", new PlistElementString(_propertiesData.USER_CURRENCY));
            dict.values.Add("BaseApiUrl", new PlistElementString("https://api-partners.kindred.co"));
            dict.values.Add("CDNUrl", new PlistElementString("https://cdn.kindred.co"));
            dict.values.Add("ShowWithdrawal", new PlistElementBoolean(_propertiesData.SHOW_WITHDRAWAL));
            dict.values.Add("CashbackLabelType", new PlistElementInteger(_propertiesData.CASHBACK_LABEL_TYPE));
            dict.values.Add("CharityId", new PlistElementString(_propertiesData.CHARITY_ID));
            if (int.TryParse(_propertiesData.CHARITY_SHARE, out int charityShare))
                dict.values.Add("CharityShare", new PlistElementInteger(charityShare));
            else
                dict.values.Add("CharityShare", new PlistElementInteger(1));

            // Write to file
            File.WriteAllText(plistPath, plist.WriteToString());
#endif
        }
    }
}