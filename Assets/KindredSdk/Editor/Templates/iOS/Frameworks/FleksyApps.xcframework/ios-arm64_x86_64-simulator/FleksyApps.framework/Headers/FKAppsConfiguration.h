//
//  FKAppsConfiguration.h
//  FleksyApps
//
//  Created by Xevi on 21/06/2020.
//  Copyright © 2020 Thingthing,Ltd. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@class FKAppsTheme;

/**
  Configuration for the KeyboardApps
 */
@interface FKAppsConfiguration : NSObject

- (instancetype) initConfig:(NSArray*) services
                      theme:(FKAppsTheme*) theme
                 withHeight:(CGFloat) height
               isFullAccess:(BOOL) fullaccess
           enabledSwipeBack:(BOOL) swipeBack;

@property (nonatomic, readonly) BOOL isFullAccess;
@property (nonatomic, readonly) CGFloat height;
@property (nonatomic, readonly) NSArray* services;
@property (nonatomic, readonly) BOOL enabledEdgeSwipeBack;

// this means that we should always close the fleksyapps instead of going to the menu
// when you press close button
@property (nonatomic) BOOL isAlwaysCloseMode;

// theme for KeyboardApps
@property (nonatomic) FKAppsTheme* theme;

@end

NS_ASSUME_NONNULL_END
