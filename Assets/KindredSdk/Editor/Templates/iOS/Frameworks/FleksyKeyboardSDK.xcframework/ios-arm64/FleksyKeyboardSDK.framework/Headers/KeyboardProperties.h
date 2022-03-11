//
//  KeyboardProperties.h
//  FleksyKeyboardSDK
//
//  Created by Xevi on 3/3/21.
//  Copyright © 2021 Thingthing. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface KeyboardProperties : NSObject

- (instancetype) initWithAppName:(NSString*) name keyboardType:(UIKeyboardType) type;

@property (nonatomic, readonly) NSString* appName;
@property (nonatomic, readonly) UIKeyboardType textFieldType;


@end

NS_ASSUME_NONNULL_END
