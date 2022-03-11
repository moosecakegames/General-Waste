//
//  AppearancePopup.h
//  FleksyKeyboardSDK
//
//  Created by Xevi on 30/05/2020.
//  Copyright © 2020 Thingthing. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface FleksyPopLabel : UILabel
@end

@class FleksyTheme;

// Inherite from this class to customise popup
@interface AppearancePopup : NSObject

/**
 @param bounds CGRect key pressed bounds
 @param letter NSString with the letter pressed
 @param letterFont UIFont with the font to be drawn the letter
 @param theme FleksyTheme with all different parameters
 */
- (UILabel*) popup:(CGRect) bounds
            letter:(NSString*) letter
              font:(UIFont*) letterFont
             theme:(FleksyTheme*) theme;

// Overridable methods for customisation
- (UILabel*) createPopup:(CGRect) bounds
                  letter:(NSString*) letter
                    font:(UIFont*) letterFont
                   theme:(FleksyTheme*)theme;
- (UILabel*) createPopupLeft:(CGRect) bounds
                      letter:(NSString*) letter
                        font:(UIFont*) letterFont
                       theme:(FleksyTheme*)theme;
- (UILabel*) createPopupRight:(CGRect) bounds
                       letter:(NSString*) letter
                         font:(UIFont*) letterFont
                        theme:(FleksyTheme*)theme;
@end

NS_ASSUME_NONNULL_END
