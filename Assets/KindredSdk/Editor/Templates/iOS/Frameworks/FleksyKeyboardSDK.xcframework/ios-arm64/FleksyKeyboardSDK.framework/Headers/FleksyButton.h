//
//  FleksyButton.h
//  FleksyKitContainerApp
//
//  Created by Tusi Chowdhury on 2014-07-29.
//  Copyright (c) 2014 Thingthing, Ltd. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "FleksyTheme.h"
#import "FleksyDefines.h"
#import "FleksyEngineUIUniqueIdentifiable.h"
#import "FleksyThemeableUI.h"
#import "FleksyCursorControllable.h"
#import "FleksyVibrantViewContainer.h"

typedef NS_OPTIONS(NSInteger, FleksyButtonStyleClass) {
  FleksyButtonStyleClassDefault       = 1 << 0,   // Full opacity title(icon), semi-transparent background
  FleksyButtonStyleClassTransparent   = 1 << 1,   // No background, semi-transparent title(icon), except when selected
  FleksyButtonStyleClassHomeRow       = 1 << 2,   // Background matches the home row
  FleksyButtonStyleClassRounded       = 1 << 3,   // Rounded corners
  FleksyButtonStyleClassShadow        = 1 << 4,   // TODO: Applies the shadow color at the bottom of the frame
  FleksyButtonStyleClassForeground    = 1 << 5,   //Transparent, but full opacity title
  FleksyButtonStyleClassLongPressHint = 1 << 6,   //Has three rounded circles indicating that it is possible to tap and hold on the button
  FleksyButtonStyleClassFlick         = 1 << 7,   // japanese hacks
};

typedef NS_ENUM(NSInteger, FleksyVibrancyStyle) {
  FleksyVibrancyStyleNone,
  FleksyVibrancyStyleLight,
  FleksyVibrancyStyleDark
};

/**
 A button which can manage its own theme and layouting, including corner buttons. Used for all keypad buttons.
 */
@interface FleksyButton : UIControl <FleksyEngineUIUniqueIdentifiable, FleksyThemeableUI, FleksyCursorControllable, FleksyVibrantViewContainer>

@property (nonatomic, strong) UIColor *backgroundColorFleksy;
@property (nonatomic) FleksyTheme *theme;
@property (nonatomic, strong) UIColor *selectedColor;
@property (nonatomic) FleksyVibrancyStyle vibrancyStyle;
@property (nonatomic, strong) UIVibrancyEffect *vibrancyEffect;
@property (nonatomic, readonly) NSString *currentTitle;

- (instancetype)initWithTitle:(NSString *)title
                        theme:(FleksyTheme *)theme
                   styleClass:(FleksyButtonStyleClass)styleClass; // should this also take a frame?
- (void)setShouldUseLabelShadowWithColor:(UIColor *)labelShadowColor;
- (void)triggerDisappearAnimationForView:(UIView *)disappearingView;
- (void)triggerDisappearAnimationForView:(UIView *)disappearingView
                             endingAlpha:(CGFloat)endingAlpha
                        andStartingAlpha:(CGFloat)startingAlpha;
- (void)setTitle:(NSString *)aTitle
        forState:(UIControlState)state;
- (void)setTitleColor:(UIColor *)color
             forState:(UIControlState)state;
- (NSString *)titleForState:(UIControlState)state;
- (UIColor *)titleColorForState:(UIControlState)state;
- (void)triggerFadeAnimationWithAlpha:(CGFloat)alpha;
- (void)changeType:(FLButtonType)type;
- (void)showTextLabel;
- (void)showLongPressHint;

@end
