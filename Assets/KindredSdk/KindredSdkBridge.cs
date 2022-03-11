using System;
using System.Collections;
using System.Collections.Generic;
#if UNITY_IOS && !UNITY_EDITOR
using System.Runtime.InteropServices;
#endif
using UnityEngine;

public static class KindredSdkBridge
{
#if UNITY_IOS && !UNITY_EDITOR
    [DllImport("__Internal")]
    private static extern void SetKindredUserId(string userId);
    [DllImport("__Internal")]
    private static extern void SetKindredUserCurrency(string userCurrency);
    [DllImport("__Internal")]
    private static extern void SetKindredUserCountry(string userCountry);
    [DllImport("__Internal")]
    private static extern void ShowKindredSettings();
#endif

    public static void SetUserId(string userId)
    {
#if !UNITY_EDITOR
#if UNITY_ANDROID
        using (AndroidJavaClass keyboardService = new AndroidJavaClass("com.unity3d.player.KindredSdkBridge"))
        {
            AndroidJavaClass playerClass = new AndroidJavaClass ("com.unity3d.player.UnityPlayer");
            AndroidJavaObject currentActivityObject = playerClass.GetStatic<AndroidJavaObject> ("currentActivity");
            keyboardService.CallStatic("setUserId", userId, currentActivityObject);
        }
#elif UNITY_IOS
        SetKindredUserId(userId);
#endif
#endif
    }

    public static void SetUserCurrency(string userCurrency)
    {
#if !UNITY_EDITOR
#if UNITY_ANDROID
        using (AndroidJavaClass keyboardService = new AndroidJavaClass("com.unity3d.player.KindredSdkBridge"))
        {
            AndroidJavaClass playerClass = new AndroidJavaClass ("com.unity3d.player.UnityPlayer");
            AndroidJavaObject currentActivityObject = playerClass.GetStatic<AndroidJavaObject> ("currentActivity");
            keyboardService.CallStatic("setUserCurrency", userCurrency, currentActivityObject);
        }
#elif UNITY_IOS
        SetKindredUserCurrency(userCurrency);
#endif
#endif
    }

    public static void SetUserCountry(string userCountry)
    {
#if !UNITY_EDITOR
#if UNITY_ANDROID
        using (AndroidJavaClass keyboardService = new AndroidJavaClass("com.unity3d.player.KindredSdkBridge"))
        {
            AndroidJavaClass playerClass = new AndroidJavaClass ("com.unity3d.player.UnityPlayer");
            AndroidJavaObject currentActivityObject = playerClass.GetStatic<AndroidJavaObject> ("currentActivity");
            keyboardService.CallStatic("setUserCountry", userCountry, currentActivityObject);
        }
#elif UNITY_IOS
        SetKindredUserCountry(userCountry);
#endif
#endif
    }

    public static void ShowKeyboardSettings()
    {
#if !UNITY_EDITOR
#if UNITY_ANDROID
        using (AndroidJavaClass keyboardService = new AndroidJavaClass("com.unity3d.player.KindredSdkBridge"))
        {
            AndroidJavaClass playerClass = new AndroidJavaClass ("com.unity3d.player.UnityPlayer");
            AndroidJavaObject currentActivityObject = playerClass.GetStatic<AndroidJavaObject> ("currentActivity");
            keyboardService.CallStatic("showSettings", currentActivityObject);
        }
#elif UNITY_IOS
        ShowKindredSettings();
#endif
#endif
    }
}
