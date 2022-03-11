//
//  FKInputView.h
//  FleksyKeyboardSDK
//
//  Created by Xevi on 03/07/2019.
//  Copyright © 2019 Thingthing. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "FleksyThemeableUI.h"
#import "FleksyXtrasView.h"
#import "FleksyCursorControl.h"
#import "FleksySuggestionView.h"
#import "FleksyViewControllerPresenter.h"
#import <FleksyEngine/FLEnums.h>


NS_ASSUME_NONNULL_BEGIN

@class FleksyKeyPadView;
@class FleksyBaseView;

@protocol  FleksyInputViewDelegate

@property (nonatomic, readonly) NSArray<UIView<FleksyThemeableUI> *> *keyboardViews;
@property (nonatomic) FLKeyboardSize userSizePreference;
@property (nonatomic, readonly) FleksyCursorControl *cursorController;
- (void)onKeyboardFrameChanged:(CGRect)frame;
- (void)resetDisplayStateFromAlternateKeyboardViewController:(UIViewController *)controller;
- (void)onKeyboardOrientation:(CGSize) size;

@end

/**
 View at the root of our view hierarchy. Manages the height of the overall view.
 */
@interface FKInputView : UIInputView<UIInputViewAudioFeedback,
FleksyThemeableUI,
FleksyCursorControllable,
FleksyViewControllerPresenter>


#pragma mark - Keyboard Height
/**
 The height we want. *Not* necessarily the height we'll get.
 */
@property (nonatomic) CGFloat desiredHeight;
/**
 Current Height of the extensions view
 */
@property (nonatomic, readonly) CGFloat desiredHeightForExtensions;
/**
 Set so that the input view knows to start setting its constraints.
 */
@property (nonatomic) BOOL hasAppeared;
/**
 Runs hacks that fix an issue where the keyboard is drawn offset vertically. To be run as soon as possible after a keyboard instance is created
 */
- (void)fixiOSNineConstraints;

#pragma mark - Layout / Subviews

- (void)refreshKeyboardHeight;

/**
 Call to indicate to the reciver that a size transition has begun
 */
- (void)orientationChangeDidBeginWithTransitionSize:(CGSize)transitionSize;
/**
 Call to indicate to the receiver that a size transtion has ended
 */
- (void)orientationChangeDidEndWithTransitionCoordinator:(id<UIViewControllerTransitionCoordinator>)coordinator;
@property (nonatomic) FleksyKeyPadView *keypad;
@property (nonatomic) UIView *animatedView;
@property (nonatomic, readonly) FleksyBaseView *baseView; /* TODO: might be unnecessary to expose this */
@property (nonatomic) FleksySuggestionView *suggestionsView;
@property (nonatomic) UIView<FleksyThemeableUI> *alternateKeyboard;
@property (nonatomic) FleksyXtrasView *extensionsView;
@property (nonatomic, weak) id<FleksyInputViewDelegate> delegate;
@property (nonatomic, readonly) CGRect currentKeyboardFrame;
@property (nonatomic, readonly) CGFloat unexpandedExtensionRowHeight;

/**
 Indicates if the view believes that it is in landscape or portrait
 */
@property (nonatomic, readonly) BOOL isInLandscape;
@property (nonatomic, readonly) BOOL isShowingAlert;
@property (nonatomic) BOOL isShowingSuggestionsView;

/**
 Add insets in the keyboard to move to the right, left, up, down inside the view
 */
- (void) updateInsets:(UIEdgeInsets) insets;

#pragma mark - Alternate Keyboard Display Management

- (void)stopDisplayingAlternateKeyboardWithCompletion:(void (^)(void))completion;
- (void)showAlternateKeyboard:(UIView<FleksyThemeableUI> *)alternateKeyboard
            animationDuration:(NSTimeInterval)duration
isCurrentlyShowingEmojiKeyboard:(BOOL)isCurrentlyShowingEmojiKeyboard
                   completion:(void (^)(BOOL))completion;

#pragma mark - Keyboard Appearance Animations

- (void)playInitalAppearanceAnimationWithCompletion:(void (^)(void))block;
- (void)prepareForInitialAppearanceAnimation;

- (void) displayAppsView:(UIView*) view;
- (CGFloat) getDisplayViewHeight;
- (void) closeAppsView;

- (void) updateCustomHeight:(CGFloat) height;

@end

NS_ASSUME_NONNULL_END
