import Foundation

@objc public class KeyboardService: NSObject
{
    @objc public static let shared = KeyboardService()

    var defaults = UserDefaults()
    let userIdKey = "kkUserId"
    let userCurrencyKey = "kkUserCurrency"
    let userCountryKey = "kkUserCountry"

    @objc public func setUserId(userId:String) -> Void {
        if let groupName = Bundle.main.object(forInfoDictionaryKey: "AppGroupName") as? String {
            defaults = UserDefaults.init(suiteName: groupName)!
            defaults.setValue(userId, forKey: userIdKey)
        }
    }
    
    @objc public func setUserCurrency(userCurrency:String) -> Void {
        if let groupName = Bundle.main.object(forInfoDictionaryKey: "AppGroupName") as? String {
            defaults = UserDefaults.init(suiteName: groupName)!
            defaults.setValue(userCurrency, forKey: userCurrencyKey)
        }
    }
    
    @objc public func setUserCountry(userCountry:String) -> Void {
        if let groupName = Bundle.main.object(forInfoDictionaryKey: "AppGroupName") as? String {
            defaults = UserDefaults.init(suiteName: groupName)!
            defaults.setValue(userCountry, forKey: userCountryKey)
        }
    }
    
    @objc public func showSettings() -> Void {
        UIApplication.shared.open(URL(string: UIApplication.openSettingsURLString)!,
                                  options: [:],
                                  completionHandler: nil)
    }
}
