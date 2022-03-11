package com.unity3d.player

import android.content.Context
import com.kindred.sdk.KindredKeyboardService
import com.kindred.sdk.configuration.*

class KeyboardService : KindredKeyboardService() {

    override fun onCreate() {
        val sharedPref = this?.getSharedPreferences("kindred", Context.MODE_PRIVATE)
        val userId = sharedPref.getString("kkUserId", "")
        userId?.let { setUserId(it) }

        super.onCreate()
    }
    
    override val appIcon: Int = R.drawable.kindredlogo

    override fun configureKeyboard() = KeyboardConfiguration(
        api = ApiConfiguration(
            urlBase = BuildConfig.API_URL,
            clientID = BuildConfig.AUTH_CLIENT_ID,
            clientSecret = BuildConfig.AUTH_CLIENT_SECRET,
            sharedKey = BuildConfig.AUTH_SHARED_KEY
        ),
        cdn = CDNConfiguration(cdnUrl = BuildConfig.ASSETS_CDN_URL),
        user = getUserConfiguration(),
        display = KeyboardDisplayConfiguration(
            getCashbackDonationsFromSettings(),
            getShowWithdrawalFromSettings()
        ),
        charity = CharityConfiguration(
            charityId = BuildConfig.CHARITY_ID,
            charityShare = BuildConfig.CHARITY_SHARE
        )
    )

    private fun getUserConfiguration(): UserConfiguration {
        val sharedPref = this?.getSharedPreferences("kindred", Context.MODE_PRIVATE)

        val userCurrency = sharedPref.getString("kkUserCurrency", "")
        val uCurrency = if(userCurrency.isNullOrEmpty()) {
            BuildConfig.USER_CURRENCY
        } else {
            userCurrency
        }

        val userCountry = sharedPref.getString("kkUserCountry", "")
        val uCountry = if(userCountry.isNullOrEmpty()) {
            ""
        } else {
            userCountry
        }

        return UserConfiguration(
            userCurrency = uCurrency,
            userCountry = uCountry
        )
    }

    private fun getCashbackDonationsFromSettings(): KeyboardDisplayConfiguration.CashbackLabel {
        return if (BuildConfig.CASHBACK_LABEL_TYPE == 0) {
                KeyboardDisplayConfiguration.CashbackLabelType.CASHBACK
            } else {
                KeyboardDisplayConfiguration.CashbackLabelType.DONATIONS
            }
    }

    private fun getShowWithdrawalFromSettings(): KeyboardDisplayConfiguration.WithdrawalEnabled {
        return if (BuildConfig.SHOW_WITHDRAWAL) {
                KeyboardDisplayConfiguration.WithdrawalEnabled.ENABLED
            } else {
                KeyboardDisplayConfiguration.WithdrawalEnabled.DISABLED
            }
    }
}