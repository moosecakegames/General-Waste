//
//  AppearanceLongPress.h
//  FleksyKeyboardSDK
//
//  Created by Xevi on 02/06/2020.
//  Copyright © 2020 Thingthing. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface AppearanceLongPress : NSObject

/**
 *  Get position of the view respect the 0,0 over the key
 *  CGSizeZero position it's over the same key
 */
- (CGSize) getPosition;

/**
 *  Margin left, right of the popup view
 */
- (CGFloat) getMarginPopupLeft;
- (CGFloat) getMarginPopupRight;

/**
 *  Padding of the key
 */
- (CGFloat) getPaddingKeyX;
- (CGFloat) getPaddingKeyY;

/**
 * Create the path of the shape of the popups at longpress
 */
- (UIBezierPath*) createPath:(CGRect) rect sizeElement:(CGSize) sizeElement position:(NSUInteger) position total:(NSUInteger) total;

/**
 *  Create path of the shape of some of the popups at longpress
 *  // This is a simplified version of the previous createPath, thought it's mandatory to have it implemented
 */
- (UIBezierPath*) createPath:(CGRect) rect sizeElement:(CGSize) sizeElement position:(NSUInteger) multiplier toRight:(BOOL) right;

@end

NS_ASSUME_NONNULL_END
