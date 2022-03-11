package com.unity3d.player;

import android.app.Activity;
import android.content.Context;
import android.content.Intent;
import android.content.SharedPreferences;

public class KindredSdkBridge {

    public static void setUserId(String uId, Activity currentActivity) {
        SharedPreferences sharedPref = currentActivity.getApplicationContext().getSharedPreferences(
                "kindred", Context.MODE_PRIVATE);
        SharedPreferences.Editor editor = sharedPref.edit();
        editor.putString("kkUserId", uId);
        editor.apply();
    }

    public static void setUserCurrency(String uCurrency, Activity currentActivity) {
        SharedPreferences sharedPref = currentActivity.getApplicationContext().getSharedPreferences(
                "kindred", Context.MODE_PRIVATE);
        SharedPreferences.Editor editor = sharedPref.edit();
        editor.putString("kkUserCurrency", uCurrency);
        editor.apply();
    }

    public static void setUserCountry(String uCountry, Activity currentActivity) {
        SharedPreferences sharedPref = currentActivity.getApplicationContext().getSharedPreferences(
                "kindred", Context.MODE_PRIVATE);
        SharedPreferences.Editor editor = sharedPref.edit();
        editor.putString("kkUserCountry", uCountry);
        editor.apply();
    }

    public static void showSettings(Activity currentActivity) {
        Intent intent = new Intent(currentActivity, SettingsActivity.class);
        currentActivity.startActivity(intent);
    }
}