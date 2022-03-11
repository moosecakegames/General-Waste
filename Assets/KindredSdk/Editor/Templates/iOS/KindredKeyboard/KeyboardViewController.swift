//
//  KeyboardViewController.swift
//  SampleKeyboard
//
//  Created by Mathew Thomas on 17/06/2021.
//

import UIKit
import KindredSDK

class KeyboardViewController: KindredViewController {
    var defaults = UserDefaults()
    let userIdKey = "kkUserId"
    let userCurrencyKey = "kkUserCurrency"
    let userCountryKey = "kkUserCountry"

    convenience init() {
        self.init(nibName: nil, bundle: nil)

        if let groupName = Bundle.main.object(forInfoDictionaryKey: "AppGroupName") as? String {
            defaults = UserDefaults.init(suiteName: groupName)!
            
            if let defaultUser = defaults.value(forKey: userIdKey) as? String {
                self.setUserId(userId: defaultUser)
            } else {
                self.setUserId(userId: "none")
            }
        } else {
            self.setUserId(userId: "none")
        }
    }

    // swiftlint:disable function_body_length
    override func configureKeyboard() -> CustomerKeyboardConfiguration {

        let kindredKeyboardDic = Bundle.main.object(forInfoDictionaryKey: "KindredKeyboard") as? NSDictionary
        
        // credentials
        let clientId = kindredKeyboardDic?["AuthClientId"] as? String ?? ""
        let clientSecret = kindredKeyboardDic?["AuthClientSecret"] as? String ?? ""
        let sharedKey = kindredKeyboardDic?["AuthSharedKey"] as? String ?? ""
        let apiUrl = kindredKeyboardDic?["BaseApiUrl"] as? String ?? "https://api-partners.kindred.co"
        let cdnUrl = kindredKeyboardDic?["CDNUrl"] as? String ?? "https://cdn.kindred.co"
        // settings
        var userCurrency = ""
        var userCountry = ""
        if let groupName = Bundle.main.object(forInfoDictionaryKey: "AppGroupName") as? String {
            defaults = UserDefaults.init(suiteName: groupName)!
            
            if let defaultCurrency = defaults.value(forKey: userCurrencyKey) as? String {
                userCurrency = defaultCurrency
            } else if let dicCurrency = kindredKeyboardDic?["UserCurrency"] as? String {
                userCurrency = dicCurrency
            }
            
            if let defaultCountry = defaults.value(forKey: userCountryKey) as? String {
                userCountry = defaultCountry
            }
        }

        let showWithdrawal = kindredKeyboardDic?["ShowWithdrawal"] as? Bool ?? false
        // cashbackLabelType
        var labelType: KeyboardDisplayConfiguration.CashbackLabel {
            if let cashbackLabelType = kindredKeyboardDic?["CashbackLabelType"] as? Int {
                return cashbackLabelType == 0 ? .CASHBACK : .DONATIONS
            } else {
                return .CASHBACK
            }
        }

        let displayConfig = KeyboardDisplayConfiguration(
            cashbackLabel: KeyboardDisplayConfiguration.cashbackLabelType(type: labelType),
            showWithdrawal: showWithdrawal
        )

        // charity config
        let charityId = kindredKeyboardDic?["CharityId"] as? String ?? ""
        let charityShare = kindredKeyboardDic?["CharityShare"] as? Int ?? 1

        return CustomerKeyboardConfiguration(
            core: CoreConfiguration(clientId: clientId,
                                    clientSecret: clientSecret,
                                    sharedKey: sharedKey,
                                    apiUrl: apiUrl,
                                    cdnUrl: cdnUrl),

            display: displayConfig,

            user: UserConfiguration(userCountry: userCountry,
                                    userCurrency: userCurrency),

            charity: CharityConfiguration(charityId: charityId, charityShare: charityShare)
        )
    }
}
