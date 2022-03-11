using System;
using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class KindredExample : MonoBehaviour
{
    public InputField UserIdField;
    public InputField UserCurrencyField;
    public InputField UserCountryField;

    public Button SetUserIdBtn;
    public Button SetUserCurrencyBtn;
    public Button SetUserCountryBtn;
    public Button ShowSettingsBtn;

    public Text UserIdFeedback;
    public Text UserCurrencyFeedback;
    public Text UserCountryFeedback;

    private void Start()
    {
        SetUserIdBtn.onClick.AddListener(SetUserId);
        SetUserCurrencyBtn.onClick.AddListener(SetUserCurrency);
        SetUserCountryBtn.onClick.AddListener(SetUserCountry);
        ShowSettingsBtn.onClick.AddListener(ShowKeyboardSettings);

        UserIdField.onValueChanged.AddListener(UserIdTextChanged);
        UserCurrencyField.onValueChanged.AddListener(UserCurrencyTextChanged);
        UserCountryField.onValueChanged.AddListener(UserCountryTextChanged);
    }

    private void UserCountryTextChanged(string arg0)
    {
        UserCountryFeedback.text = "";
    }

    private void UserCurrencyTextChanged(string arg0)
    {
        UserCurrencyFeedback.text = "";
    }

    private void UserIdTextChanged(string arg0)
    {
        UserIdFeedback.text = "";
    }

    public void SetUserId()
    {
        KindredSdkBridge.SetUserId(UserIdField.text);
        UserIdFeedback.text = "The user ID has been successfully set";
    }

    public void SetUserCurrency()
    {
        KindredSdkBridge.SetUserCurrency(UserCurrencyField.text);
        UserCurrencyFeedback.text = "The user currency has been successfully set";
    }

    public void SetUserCountry()
    {
        KindredSdkBridge.SetUserCountry(UserCountryField.text);
        UserCountryFeedback.text = "The user country has been successfully set";
    }

    public void ShowKeyboardSettings()
    {
        KindredSdkBridge.ShowKeyboardSettings();
    }
}
