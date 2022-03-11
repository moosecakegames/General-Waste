using UnityEditor;

namespace KindredSDK.Editor
{
    public class PropertiesData
    {
        public string AUTH_CLIENT_ID;
        public string AUTH_CLIENT_SECRET;
        public string AUTH_SHARED_KEY;
        public string USER_CURRENCY;
        public string APP_ICON;
        public string ACTIVE_APP_ICON_1X;
        public string ACTIVE_APP_ICON_2X;
        public string ACTIVE_APP_ICON_3X;
        public string INACTIVE_APP_ICON_1X;
        public string INACTIVE_APP_ICON_2X;
        public string INACTIVE_APP_ICON_3X;
        public string APP_GROUP_NAME;
        public bool SHOW_WITHDRAWAL;
        public int CASHBACK_LABEL_TYPE;
        public string CHARITY_ID;
        public string CHARITY_SHARE;

        public void SaveToPrefs()
        {
#if UNITY_EDITOR
            EditorPrefs.SetString("AUTH_CLIENT_ID", AUTH_CLIENT_ID);
            EditorPrefs.SetString("AUTH_CLIENT_SECRET", AUTH_CLIENT_SECRET);
            EditorPrefs.SetString("AUTH_SHARED_KEY", AUTH_SHARED_KEY);
            EditorPrefs.SetString("USER_CURRENCY", USER_CURRENCY);
            EditorPrefs.SetString("APP_ICON", APP_ICON);
            EditorPrefs.SetString("ACTIVE_APP_ICON_1X", ACTIVE_APP_ICON_1X);
            EditorPrefs.SetString("ACTIVE_APP_ICON_2X", ACTIVE_APP_ICON_2X);
            EditorPrefs.SetString("ACTIVE_APP_ICON_3X", ACTIVE_APP_ICON_3X);
            EditorPrefs.SetString("INACTIVE_APP_ICON_1X", INACTIVE_APP_ICON_1X);
            EditorPrefs.SetString("INACTIVE_APP_ICON_2X", INACTIVE_APP_ICON_2X);
            EditorPrefs.SetString("INACTIVE_APP_ICON_3X", INACTIVE_APP_ICON_3X);
            EditorPrefs.SetString("APP_GROUP_NAME", APP_GROUP_NAME);
            EditorPrefs.SetBool("SHOW_WITHDRAWAL", SHOW_WITHDRAWAL);
            EditorPrefs.SetInt("CASHBACK_LABEL_TYPE", CASHBACK_LABEL_TYPE);
            EditorPrefs.SetString("CHARITY_ID", CHARITY_ID);
            EditorPrefs.SetString("CHARITY_SHARE", CHARITY_SHARE);
#endif
        }

        public void LoadFromPrefs()
        {
#if UNITY_EDITOR
            AUTH_CLIENT_ID = EditorPrefs.GetString("AUTH_CLIENT_ID", "");
            AUTH_CLIENT_SECRET = EditorPrefs.GetString("AUTH_CLIENT_SECRET", "");
            AUTH_SHARED_KEY = EditorPrefs.GetString("AUTH_SHARED_KEY", "");
            USER_CURRENCY = EditorPrefs.GetString("USER_CURRENCY", "");
            APP_ICON = EditorPrefs.GetString("APP_ICON", "");
            ACTIVE_APP_ICON_1X = EditorPrefs.GetString("ACTIVE_APP_ICON_1X", "");
            ACTIVE_APP_ICON_2X = EditorPrefs.GetString("ACTIVE_APP_ICON_2X", "");
            ACTIVE_APP_ICON_3X = EditorPrefs.GetString("ACTIVE_APP_ICON_3X", "");
            INACTIVE_APP_ICON_1X = EditorPrefs.GetString("INACTIVE_APP_ICON_1X", "");
            INACTIVE_APP_ICON_2X = EditorPrefs.GetString("INACTIVE_APP_ICON_2X", "");
            INACTIVE_APP_ICON_3X = EditorPrefs.GetString("INACTIVE_APP_ICON_3X", "");
            APP_GROUP_NAME = EditorPrefs.GetString("APP_GROUP_NAME", "");
            SHOW_WITHDRAWAL = EditorPrefs.GetBool("SHOW_WITHDRAWAL", false);
            CASHBACK_LABEL_TYPE = EditorPrefs.GetInt("CASHBACK_LABEL_TYPE", 0);
            CHARITY_ID = EditorPrefs.GetString("CHARITY_ID", "");
            CHARITY_SHARE = EditorPrefs.GetString("CHARITY_SHARE", "");
#endif
        }
    }
}