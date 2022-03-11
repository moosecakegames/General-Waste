//
//  FleksyDebugSDK.h
//  FleksyKeyboardSDK
//
//  Created by Xevi on 15/11/2020.
//  Copyright © 2020 Thingthing. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <FleksyEngine/FLEnums.h>

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface FleksyDebugLayoutSDK : NSObject

@property(nonatomic, readonly) CGRect frame;
@property(nonatomic, readonly) FLButtonType type;
@property(nonatomic, readonly) NSString *label;

- (instancetype) initWithFrame:(CGRect)frame type:(FLButtonType)type label:(NSString*)label;

@end

@interface FleksyDebugRectSDK : NSObject

@property(nonatomic, readonly) CGRect frame;

- (instancetype) initWithFrame:(CGRect)frame;

@end

NS_ASSUME_NONNULL_END
