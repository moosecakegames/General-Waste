//
//  FleksyDisplayedXtraVC.h
//  FleksyiOS
//
//  Created by Ben Pious on 6/30/15.
//  Copyright (c) 2015 Thingthing, Ltd. All rights reserved.
//

#ifndef FleksyiOS_FleksyDisplayedXtraVC_h
#define FleksyiOS_FleksyDisplayedXtraVC_h

#import "FleksyThemeableUI.h"

/**
 An object that presents view controllers. This is distinctive from normal view controller presentation in that we have
 our own transition that we want to provide.
 */
@protocol FleksyViewControllerPresenter <NSObject>

/**
 Indicates that the user dragged up.
 @param offset the offset in the coordinate system of the presented view
 @param view the view to modify with the results of calculations in the receiver
 */
- (void)pullDownGestureWithOffset:(CGFloat)offset
                             view:(UIView *)view
          presentedViewController:(UIViewController *)controller;
- (void)pullDownGestureEndedWithOffset:(CGFloat)offset
                              velocity:(CGFloat)verticalVelocity
                                  view:(UIView *)view
               presentedViewController:(UIViewController *)controller;
@optional
/**
 Call to transmit notifications for the user to a xtra view controller that can handle it, if one is visible.
 */
- (void)notifyUserWithString:(NSString *)text;

@end

#endif
