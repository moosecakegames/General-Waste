//
//  FKInterfaceHelper.h
//  FleksyHelperSDK
//
//  Created by Xevi Farrarons on 1/7/21.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface FKInterfaceHelper : NSObject

/**
 @param language NSString with the value of the language:  [language ISO 639-1]-[Country ISO 3166-alpha2]
 */
- (void) downloadLanguage:(NSString*) language progress:(void (^)(float progress))updateHandler completion:(void (^)(NSError *))completion;

/**
 Remove the language Installed
 */
- (void) removeLanguage:(NSString*) language;

@end

NS_ASSUME_NONNULL_END
