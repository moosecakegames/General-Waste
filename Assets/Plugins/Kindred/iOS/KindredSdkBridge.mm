#import <UnityFramework/UnityFramework-Swift.h>

extern "C"
{
    void SetKindredUserId(const char *userId)
    {
        [[KeyboardService shared] setUserIdWithUserId:[NSString stringWithUTF8String:userId]];
    }

    void SetKindredUserCurrency(const char *userCurrency)
    {
        [[KeyboardService shared] setUserCurrencyWithUserCurrency:[NSString stringWithUTF8String:userCurrency]];
    }

    void SetKindredUserCountry(const char *userCountry)
    {
        [[KeyboardService shared] setUserCountryWithUserCountry:[NSString stringWithUTF8String:userCountry]];
    }

    void ShowKindredSettings()
    {
        [[KeyboardService shared] showSettings];
    }
}
