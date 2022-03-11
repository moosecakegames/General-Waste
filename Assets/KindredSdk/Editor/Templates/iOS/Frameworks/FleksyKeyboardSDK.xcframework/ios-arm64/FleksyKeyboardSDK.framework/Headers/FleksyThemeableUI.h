//
//  FleksyThemeableUI.h
//  FleksyiOS
//
//  Created by Ben Pious on 6/29/15.
//  Copyright (c) 2015 Thingthing, Ltd. All rights reserved.
//

#ifndef FleksyiOS_FleksyThemeableUI_h
#define FleksyiOS_FleksyThemeableUI_h

@class FleksyTheme;

/**
 Protocol for objects that take on a theme.
 
 @note this should be used by many UI elements that currently do not use it.
 */
@protocol FleksyThemeableUI <NSObject>

@property (nonatomic) FleksyTheme *theme;

@optional

- (instancetype)initWithTheme:(FleksyTheme *)theme;

@end

#endif
