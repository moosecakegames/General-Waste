//
//  FleksyKeyPadView.h
//  FleksyKitContainerApp
//
//  Created by Tusi Chowdhury on 2014-07-15.
//  Copyright (c) 2014 Thingthing, Ltd. All rights reserved.
//

#import <UIKit/UIKit.h>

#import "FleksyDefines.h"
#import "FleksyButton.h"
#import "FleksyCursorControllable.h"
#import "FleksyFontProvider.h"
#import "FleksyJapaneseKeyboardStatusProvider.h"
#import "FleksyKeyboardDisplayStateInfoProvider.h"
#import "FleksyVibrantViewContainer.h"

@class FleksySpeechManager;
@class FleksyTheme;
@class FleksyKeyAppearance;
@protocol FleksyEngineUIUniqueIdentifiable;

@protocol FleksyKeyPadViewDelegate <FleksyFontProvider, FleksyJapaneseKeyboardStatusProvider, FleksyKeyboardDisplayStateInfoProvider>

- (NSArray *)getKeyboardLayoutInfoFromEngine;
- (NSString *)nearestCharacterForPoint:(CGPoint)point;
@property (nonatomic, readonly) BOOL currentInputHasAutocorrect;
@property (nonatomic, readonly) FLKeyboardID keyboardID;
@property (nonatomic, readonly) FleksySpeechManager *speechManager;
@property (nonatomic, readonly) BOOL shouldShowSpaceBarRow;
@property (nonatomic, readonly) BOOL hasMultipleLanguages;

@end

/**
 View that manages keypad UI.
 */
@interface FleksyKeyPadView : UIView <FleksyCursorControllable, FleksyThemeableUI, FleksyJapaneseKeyboardStatusProvider, FleksyKeyboardDisplayStateInfoProvider, FleksyVibrantViewContainer>

/**
 Determines whether tap and hold should cause key pops.
 */
@property (nonatomic) BOOL showUIForTapAndHold;
@property (nonatomic) BOOL isShowingTemporaryKeyboard;
@property (nonatomic) BOOL isShowingHomeRow;
@property (nonatomic) BOOL isAnimationHomeRow;
@property (nonatomic) FleksyKeyAppearance* appearance;
@property (nonatomic, weak) id<FleksyKeyPadViewDelegate> delegate;

- (instancetype)initWithFrame:(CGRect)frame
                        theme:(FleksyTheme *)currentTheme
                   appearance:(FleksyKeyAppearance*) appearance
                     delegate:(id<FleksyKeyPadViewDelegate>)delegate;
#pragma mark - keyboard touch response
- (void)popupKey:(NSString *)keyStr;
- (void)endKeyPopForKey:(NSString *)keyLabel;
- (void)longTapForKeyString:(NSString *)keyString
            temporaryLayout:(NSArray *)temporaryLayout
                      point:(CGPoint)point
                 forElement:(FleksyLayoutElement*) element;
- (void)longTapMoved:(CGPoint)point
           tappedStr:(NSString *)keyStr;
- (void)longTapEnded:(CGPoint)point
          withOrigin:(CGPoint)originalPoint;
- (void)typeChanged:(FLButtonType)type
   forButtonsOfType:(FLButtonType)oldType;
- (void)handleTapOnLayoutElement:(FleksyLayoutElement *)element;
#pragma mark - keyboard appearance updating
- (void)displayMsgView:(NSString *)msg;
- (void)animateHomeRowBasedOnSwipe:(FleksyTouchType)gesture
                         withTouch:(CGPoint)touch;
- (void)reloadKeyboard;
- (void)reloadKeyboardForCaseChange;
- (void)reloadEnterButton;
- (void)unHighlightEnterButton;
- (void)restorePoppedKeyIfAny;

// Style
- (void)setSpaceBarLogoImage:(NSString*) imageName configMode:(UIViewContentMode) mode;

// Swipe drawing
- (void)swipeTypingStream:(CGPoint) point;
- (void)swipeTypindEnded;

/**
 Call to show the langauge in the keyboard all the time
 */
- (void)showLanguageInKeyboard:(NSString *)languageName;
/**
 Call to show the langauge on a language switch
 */
- (void)showlanguageFadedInKeyboard:(NSString *)languageName;
- (void)restoreButtonState;
- (void)showCornerIconInButton;
- (void)showDotsInPunctuationAndMagicButtonViews;
- (void)fadeACOffIcon;
- (void)refreshAutoCorrectIndicator;
- (void)handleSwipeWithGestureType:(FleksyTouchType)gestureType
                        touchPoint:(CGPoint)point;
#pragma mark - keyboard initial apperance
- (void)playInitalAppearanceAnimationWithParticipants:(NSArray<UIView *> *)participants
                                           completion:(void (^)(void))completion;
- (void)prepareForInitialAppearanceAnimationWithParticipants:(NSArray<UIView *> *)participants;

@end
