//
//  FleksyCursorControl.h
//  FleksyiOS
//
//  Created by Tusi Chowdhury on 2014-11-21.
//  Copyright (c) 2014 Thingthing, Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "FleksyThemeableUI.h"
#import "FleksyCursorControllable.h"

@class FleksyLogoView;
@class FleksyEngineManager;

@interface FleksyCursorControl : NSObject

/**
 The engine manager object which will receive cursor control updates
 */
@property (nonatomic, weak) FleksyEngineManager *engineManager;
/**
 Indicates whether the receiver is currently in a cursor movement session.
 */
@property (nonatomic, readonly) BOOL cursorMovementStarted;
/**
 The UI being used for the cursor control
 */
@property (nonatomic, readonly) FleksyLogoView *cursorControlIndicatorView;
/**
 Invalidates the timer/perform requests that are used internally. It is necessary to call this method because this class may create a reference cycle with itself whilst the movement session is in progress
 */
- (void)invalidateTimer;
/**
 Designated initializer.
 */
- (instancetype)initWithHostViewController:(UIView*) view withTheme:(FleksyTheme*) theme delegate:(id<FleksyCursorControllable>) delegate;
/**
 @returns if the cursor control extension is currently enabled
 */
+ (BOOL)isEnabled;
/**
 Begins a cursor control movement session
 */
- (void)showCursorControlWithPoint:(CGPoint)point;
/**
 Stop showing the UI for the cursor control
 */
- (void)hideCursorControl;
/**
 Indicates to the receiver that the user's touch moved to point. Point should be in the coordinate system of the host view controller
 */
- (void)cursorTouchMoved:(CGPoint)point;

@end
