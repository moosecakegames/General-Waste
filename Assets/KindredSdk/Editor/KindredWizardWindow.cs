using System;
using System.Collections;
using System.Collections.Generic;
using System.IO;
using UnityEditor;
using UnityEngine;

namespace KindredSDK.Editor
{
#if UNITY_EDITOR

    public class KindredWizardWindow : EditorWindow
    {
        private PropertiesData _propertiesData;
        private WizardAction _actionAndroid;
        private WizardAction _actioniOS;
        private Texture2D _appIcon;
        private Texture2D _active1x;
        private Texture2D _active2x;
        private Texture2D _active3x;
        private Texture2D _inactive1x;
        private Texture2D _inactive2x;
        private Texture2D _inactive3x;
        private float _leftPanelWidth = 170;
        private const int KEY_LENGTH = 44;
        Vector2 _scrollPos;
        string _pluginsAndroidPath;

        [MenuItem("Kindred/Configuration")]
        public static void CreateWindow()
        {
            GetWindow<KindredWizardWindow>("Kindred Setup Wizard");
        }

        private void OnEnable()
        {
            _propertiesData = new PropertiesData();
            _propertiesData.LoadFromPrefs();

            _actionAndroid = new ConfigureAndroidAction(_propertiesData);
            _actioniOS = new ConfigureiOSAction(_propertiesData);

            _appIcon = AssetDatabase.LoadAssetAtPath<Texture2D>(_propertiesData.APP_ICON);
            _active1x = AssetDatabase.LoadAssetAtPath<Texture2D>(_propertiesData.ACTIVE_APP_ICON_1X);
            _active2x = AssetDatabase.LoadAssetAtPath<Texture2D>(_propertiesData.ACTIVE_APP_ICON_2X);
            _active3x = AssetDatabase.LoadAssetAtPath<Texture2D>(_propertiesData.ACTIVE_APP_ICON_3X);
            _inactive1x = AssetDatabase.LoadAssetAtPath<Texture2D>(_propertiesData.INACTIVE_APP_ICON_1X);
            _inactive2x = AssetDatabase.LoadAssetAtPath<Texture2D>(_propertiesData.INACTIVE_APP_ICON_2X);
            _inactive3x = AssetDatabase.LoadAssetAtPath<Texture2D>(_propertiesData.INACTIVE_APP_ICON_3X);

            _pluginsAndroidPath = Path.Combine(Application.dataPath, "Plugins", "Android");
        }

        private void OnGUI()
        {
            DrawPropertyFields();
        }

        private void DrawPropertyFields()
        {
            var isCommonConfigValid = true;

            var headerLabel = new GUIStyle()
            {
                alignment = TextAnchor.MiddleCenter,
                fontStyle = FontStyle.Bold,
                fontSize = 13,

            };
            headerLabel.normal.textColor = Color.white;

            _scrollPos = EditorGUILayout.BeginScrollView(_scrollPos);

            // Credentials
            EditorGUILayout.Space(5f);
            EditorGUILayout.LabelField("Credentials", headerLabel);
            EditorGUILayout.Space(5f);

            EditorGUI.BeginChangeCheck();

            _propertiesData.AUTH_CLIENT_ID = CustomTextField("Client ID", _propertiesData.AUTH_CLIENT_ID, "https://kindredsdkdocs.readme.io/docs/getting-started-1#auth-credentials");
            bool isValidClientID = Guid.TryParse(_propertiesData.AUTH_CLIENT_ID, out var guidOutput);
            if(!isValidClientID)
            {
                EditorGUILayout.HelpBox("Client ID is not valid", MessageType.Error);
                isCommonConfigValid = false;
            }    

            _propertiesData.AUTH_CLIENT_SECRET = CustomTextField("Client Secret", _propertiesData.AUTH_CLIENT_SECRET, "https://kindredsdkdocs.readme.io/docs/getting-started-1#auth-credentials");
            var isValidClientSecret = _propertiesData.AUTH_CLIENT_SECRET.Length == KEY_LENGTH;
            if (!isValidClientSecret)
            {
                EditorGUILayout.HelpBox("Client Secret is not valid", MessageType.Error);
                isCommonConfigValid = false;
            }

            _propertiesData.AUTH_SHARED_KEY = CustomTextField("Shared Key", _propertiesData.AUTH_SHARED_KEY, "https://kindredsdkdocs.readme.io/docs/getting-started-1#auth-credentials");
            var isValidSharedKey = _propertiesData.AUTH_SHARED_KEY.Length == KEY_LENGTH;
            if (!isValidSharedKey)
            {
                EditorGUILayout.HelpBox("Shared Key is not valid", MessageType.Error);
                isCommonConfigValid = false;
            }

            EditorGUILayout.LabelField("Settings", headerLabel);
            EditorGUILayout.Space(5f);

            _propertiesData.USER_CURRENCY = CustomTextField("Currency", _propertiesData.USER_CURRENCY, "https://kindredsdkdocs.readme.io/docs/getting-started-1#currency");
            if(string.IsNullOrEmpty(_propertiesData.USER_CURRENCY))
            {
                EditorGUILayout.HelpBox("User Currency is not valid", MessageType.Error);
                isCommonConfigValid = false;
            }

            _propertiesData.SHOW_WITHDRAWAL = CustomToggle("Show Withdrawal", _propertiesData.SHOW_WITHDRAWAL, "https://kindredsdkdocs.readme.io/docs/getting-started-1#show-withdrawals");

            var options = new string[] { "  Cashback", "  Donation" };
            _propertiesData.CASHBACK_LABEL_TYPE = CustomSelectionGrid("User Incentive Label Type", _propertiesData.CASHBACK_LABEL_TYPE, options, "https://kindredsdkdocs.readme.io/docs/getting-started-1#user-incentive-label-type");

            _propertiesData.CHARITY_ID = CustomTextField("Charity Id", _propertiesData.CHARITY_ID, "https://kindredsdkdocs.readme.io/docs/getting-started-1#charity");
            bool isValidCharityID = Guid.TryParse(_propertiesData.CHARITY_ID, out var charityIDGuid);
            if (!isValidCharityID)
            {
                EditorGUILayout.HelpBox("Charity ID is not valid", MessageType.Error);
                isCommonConfigValid = false;
            }

            _propertiesData.CHARITY_SHARE = CustomTextField("Charity Share (1-100)", _propertiesData.CHARITY_SHARE, "https://kindredsdkdocs.readme.io/docs/getting-started-1#charity");
            if (!int.TryParse(_propertiesData.CHARITY_SHARE, out int result))
            {
                _propertiesData.CHARITY_SHARE = "";
                EditorGUILayout.HelpBox("Charity Share is not valid", MessageType.Error);
                isCommonConfigValid = false;
            }
            else
            {
                if (result > 100) _propertiesData.CHARITY_SHARE = "100";
                else if (result < 1) _propertiesData.CHARITY_SHARE = "1";
            }

            EditorGUILayout.Space(8f);

            // Android
            EditorGUILayout.LabelField(_actionAndroid.Name, headerLabel);
            EditorGUILayout.Space(5f);

            var warningLabel = new GUIStyle()
            {
                alignment = TextAnchor.MiddleCenter,
                fontStyle = FontStyle.Bold,
                fontSize = 12,

            };
            warningLabel.normal.textColor = Color.yellow;

#if !UNITY_ANDROID
            EditorGUILayout.LabelField("Please switch your platform to Android to prepare the Android build.", warningLabel);
            EditorGUI.BeginDisabledGroup(true);
#endif
            var isAndroidConfigValid = true;

            _appIcon = CustomTextureField("App Icon", _appIcon, "https://kindredsdkdocs.readme.io/docs/getting-started-1#os-specific-configuration");
            if (_appIcon != null)
            {
                _propertiesData.APP_ICON = AssetDatabase.GetAssetPath(_appIcon);
            }
            else
            {
                isAndroidConfigValid = false;
                EditorGUILayout.HelpBox("Android logo is not valid", MessageType.Error);
            }

            EditorGUILayout.Space(1f);

            if (!isCommonConfigValid || !isAndroidConfigValid)
            {
                EditorGUI.BeginDisabledGroup(true);
            }

            if (GUILayout.Button("Prepare Android Build", GUILayout.Height(30)))
            {
                if ((File.Exists(Path.Combine(_pluginsAndroidPath, "AndroidManifest.xml")) ||
                    File.Exists(Path.Combine(_pluginsAndroidPath, "baseProjectTemplate.gradle")) ||
                    File.Exists(Path.Combine(_pluginsAndroidPath, "gradleTemplate.properties")) ||
                    File.Exists(Path.Combine(_pluginsAndroidPath, "mainTemplate.gradle"))))
                {
                    if (EditorUtility.DisplayDialog("Overwrite existing Android and Gradle templates?",
                    "Are you sure you want to overwrite existing Android and Gradle templates? (NOTE: Backups can be found in /Plugins/AndroidTemplatesBackups)", "Backup & Overwrite", "Do Not Overwrite"))
                    {
                        _actionAndroid.Configure();
                    }
                }
                else
                {
                    _actionAndroid.Configure();
                }
            }


            if (!isCommonConfigValid || !isAndroidConfigValid)
            {
                EditorGUI.EndDisabledGroup();
                EditorGUILayout.HelpBox("Configuration is not valid", MessageType.Error);
            }
#if !UNITY_ANDROID
            EditorGUI.EndDisabledGroup();
#endif

            EditorGUILayout.Space(20f);

            // iOS
            EditorGUILayout.LabelField(_actioniOS.Name, headerLabel);

            // Disable the jumping height control if canJump is false:
#if !UNITY_IOS
            EditorGUILayout.LabelField("Please switch your platform to iOS to prepare the iOS build.", warningLabel);
            EditorGUI.BeginDisabledGroup(true);
#endif
            EditorGUILayout.Space(5f);

            var isiOSConfigValid = true;

            _propertiesData.APP_GROUP_NAME = CustomTextField("App Group Name", _propertiesData.APP_GROUP_NAME, "https://kindredsdkdocs.readme.io/docs/getting-started-1#os-specific-configuration");
            if (string.IsNullOrEmpty(_propertiesData.APP_GROUP_NAME))
            {
                EditorGUILayout.HelpBox("App Group Name is not valid", MessageType.Error);
                isiOSConfigValid = false;
            }

            var isiOSLogosValid = true;

            // App Icon Begin
            GUILayout.BeginHorizontal();
            // Active app icon
            GUILayout.BeginVertical();
            CustomLabel("Active App Icon", "https://kindredsdkdocs.readme.io/docs/getting-started-1#os-specific-configuration");
            GUILayout.BeginHorizontal();
            _active1x = TextureField("Scale 1x", _active1x, false);
            if (_active1x != null)
            {
                _propertiesData.ACTIVE_APP_ICON_1X = AssetDatabase.GetAssetPath(_active1x);
            }
            else
            {
                isiOSLogosValid = false;
            }
            _active2x = TextureField("Scale 2x", _active2x, false);
            if (_active2x != null)
            {
                _propertiesData.ACTIVE_APP_ICON_2X = AssetDatabase.GetAssetPath(_active2x);
            }
            else
            {
                isiOSLogosValid = false;
            }
            _active3x = TextureField("Scale 3x", _active3x, false);
            if (_active3x != null)
            {
                _propertiesData.ACTIVE_APP_ICON_3X = AssetDatabase.GetAssetPath(_active3x);
            }
            else
            {
                isiOSLogosValid = false;
            }
            GUILayout.EndHorizontal();
            GUILayout.EndVertical();

            EditorGUILayout.Space(20f);

            // Inactive app icon
            GUILayout.BeginVertical();
            CustomLabel("Inactive App Icon", "https://kindredsdkdocs.readme.io/docs/getting-started-1#os-specific-configuration");
            GUILayout.BeginHorizontal();
            _inactive1x = TextureField("Scale 1x", _inactive1x, false);
            if (_inactive1x != null)
            {
                _propertiesData.INACTIVE_APP_ICON_1X = AssetDatabase.GetAssetPath(_inactive1x);
            }
            else
            {
                isiOSLogosValid = false;
            }

            _inactive2x = TextureField("Scale 2x", _inactive2x, false);
            if (_inactive2x != null)
            {
                _propertiesData.INACTIVE_APP_ICON_2X = AssetDatabase.GetAssetPath(_inactive2x);
            }
            else
            {
                isiOSLogosValid = false;
            }

            _inactive3x = TextureField("Scale 3x", _inactive3x, false);
            if (_inactive3x != null)
            {
                _propertiesData.INACTIVE_APP_ICON_3X = AssetDatabase.GetAssetPath(_inactive3x);
            }
            else
            {
                isiOSLogosValid = false;
            }

            GUILayout.EndHorizontal();
            GUILayout.EndVertical();
            // Inactive App Icon End
            GUILayout.EndHorizontal();
            // App Icon End

            if(!isiOSLogosValid)
            {
                EditorGUILayout.HelpBox("iOS Logos are not valid", MessageType.Error);
            }

            EditorGUILayout.Space(15f);

            if (!isCommonConfigValid || !isiOSConfigValid || !isiOSLogosValid)
            {
                EditorGUI.BeginDisabledGroup(true);
            }

            if (GUILayout.Button("Prepare iOS Build", GUILayout.Height(30)))
            {
                _actioniOS.Configure();
            }

            if (!isCommonConfigValid || !isiOSConfigValid || !isiOSLogosValid)
            {
                EditorGUI.EndDisabledGroup();
                EditorGUILayout.HelpBox("Configuration is not valid", MessageType.Error);
            }
#if !UNITY_IOS
            EditorGUI.EndDisabledGroup();
#endif

            EditorGUILayout.Space(15f);

            EditorGUILayout.EndScrollView();

            if (EditorGUI.EndChangeCheck())
            {
                _propertiesData.SaveToPrefs();
            }
        }

        private void CustomLabel(string caption, string url = "https://www.google.com")
        {
            GUILayout.BeginHorizontal();
            var guiContent = new GUIContent(caption);
            var width = new GUIStyle(GUI.skin.label).CalcSize(guiContent).x;
            EditorGUILayout.LabelField(guiContent, GUILayout.Width(width));
            LinkButton("(?)", url);
            GUILayout.EndHorizontal();
        }

        private string CustomTextField(string caption, string textField, string url = "https://www.google.com")
        {
            GUILayout.BeginHorizontal();
            var guiContent = new GUIContent(caption);
            var width = new GUIStyle(GUI.skin.label).CalcSize(guiContent).x;
            EditorGUILayout.LabelField(guiContent, GUILayout.Width(width));
            LinkButton("(?)", url);
            EditorGUILayout.LabelField("", GUILayout.Width(_leftPanelWidth - width - 18));
            var tf = EditorGUILayout.TextField("", textField);
            GUILayout.EndHorizontal();
            EditorGUILayout.Space(8f);
            return tf;
        }

        private bool CustomToggle(string caption, bool toggleValue, string url = "https://www.google.com")
        {
            GUILayout.BeginHorizontal();
            var guiContent = new GUIContent(caption);
            var width = new GUIStyle(GUI.skin.label).CalcSize(guiContent).x;
            EditorGUILayout.LabelField(guiContent, GUILayout.Width(width));
            LinkButton("(?)", url);
            EditorGUILayout.LabelField("", GUILayout.Width(_leftPanelWidth - width - 18));
            var tv = EditorGUILayout.Toggle("", toggleValue);
            GUILayout.EndHorizontal();
            EditorGUILayout.Space(8f);
            return tv;
        }

        private int CustomSelectionGrid(string caption, int gridValue, string[] options, string url = "https://www.google.com")
        {
            GUILayout.BeginHorizontal();
            var guiContent = new GUIContent(caption);
            var width = new GUIStyle(GUI.skin.label).CalcSize(guiContent).x;
            EditorGUILayout.LabelField(guiContent, GUILayout.Width(width));
            LinkButton("(?)", url);
            EditorGUILayout.LabelField("", GUILayout.Width(_leftPanelWidth - width - 18));
            var gv = GUILayout.SelectionGrid(gridValue, options, 1, EditorStyles.radioButton);
            GUILayout.EndHorizontal();
            EditorGUILayout.Space(8f);
            return gv;
        }

        private Texture2D CustomTextureField(string caption, Texture2D texValue, string url = "https://www.google.com")
        {
            GUILayout.BeginHorizontal(GUILayout.Width(_leftPanelWidth));
            var guiContent = new GUIContent(caption);
            var width = new GUIStyle(GUI.skin.label).CalcSize(guiContent).x;
            EditorGUILayout.LabelField(guiContent, GUILayout.Width(width));
            LinkButton("(?)", url);
            EditorGUILayout.LabelField("", GUILayout.Width(_leftPanelWidth - width - 18));
            var tv = (Texture2D)EditorGUILayout.ObjectField(texValue, typeof(Texture2D), false, GUILayout.Width(70), GUILayout.Height(70));
            GUILayout.EndHorizontal();
            EditorGUILayout.Space(8f);
            return tv;
        }

        private static Texture2D TextureField(string name, Texture2D texture, bool isHorizontal = true, int width = 0, int height = 0)
        {
            if(isHorizontal)
                GUILayout.BeginHorizontal();
            else
                GUILayout.BeginVertical();

            var style = new GUIStyle(GUI.skin.label)
            {
                fixedWidth = width,
                fixedHeight = height
            };
            GUILayout.Label(name, style);
            var result = (Texture2D)EditorGUILayout.ObjectField(texture, typeof(Texture2D), false, GUILayout.Width(70), GUILayout.Height(70));

            if (isHorizontal)
                GUILayout.EndHorizontal();
            else
                GUILayout.EndVertical();

            return result;
        }

        private void LinkButton(string caption, string url = "https://www.google.com")
        {
            var style = new GUIStyle(GUI.skin.label)
            {
                richText = true
            };
            caption = string.Format("<color=#A0B4FF>{0}</color>", caption);

            bool bClicked = GUILayout.Button(caption, style, GUILayout.Width(18));

            var rect = GUILayoutUtility.GetLastRect();
            rect.width = style.CalcSize(new GUIContent(caption)).x;
            EditorGUIUtility.AddCursorRect(rect, MouseCursor.Link);

            if (bClicked)
                Application.OpenURL(url);
        }
    }
#endif
}

