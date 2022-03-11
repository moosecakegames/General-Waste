//
//  FleksyUtility+Keyboard.h
//  FleksyFramework
//
//  Created by Tusi Chowdhury on 2014-10-22.
//  Copyright (c) 2014 Thingthing, Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "FleksyUtility.h"
#import "FleksyProtocols.h"

@interface FleksyUtility (Keyboard)
/**
 * This says whether it's displaying letter layout such as QWERTY, DVORAK and so on
 */
+ (BOOL)isLetterKeyboard:(FLKeyboardID)keyboardID;

/**
 @returns a corresponding FLKeyboardID for the platform's UIKeyboardType
 */
+ (FLKeyboardID)keyboardIDForKeyboardType:(UIKeyboardType)keyboardType;

/**
 Gets a height for the current width.
 */
+ (CGFloat)getKeyboardHeightForWidth:(CGFloat)width
                     traitCollection:(UITraitCollection *)traitCollection;
+ (CGRect)getDefaultFleksyKeyboardSizeWithTraitCollection:(UITraitCollection *)traitCollection;
+ (CGFloat)getDefaultFleksyHeightForWidth:(CGFloat)width
                          traitCollection:(UITraitCollection *)traitCollection;

/**
 Gets the user set keyboard size from the settingsmanager.
 */
+ (FLKeyboardSize)getFLKeyboardSize;
/**
 Uses the vertical and horizontal size classes of a trait collection to 
 determine if it indicates we are in a "ipad style" UI or not.
 
 This is necessary because we may be in a scaled for iPad iphone app.
 */
+ (BOOL)traitCollectionIsForIpad:(UITraitCollection *)traitCollection;
+ (BOOL)isCaseSwitchFromID:(FLKeyboardID)old
                      toID:(FLKeyboardID)new;
@end
