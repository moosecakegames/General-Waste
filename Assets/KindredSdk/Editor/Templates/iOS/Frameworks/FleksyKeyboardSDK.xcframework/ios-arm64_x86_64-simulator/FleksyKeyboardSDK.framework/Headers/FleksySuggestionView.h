//
//  FLSuggestionViewController.h
//  FleksyKitContainerApp
//
//  Created by Tusi Chowdhury on 2014-07-02.
//  Copyright (c) 2014 Thingthing, Ltd. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "FleksyTheme.h"
#import "FleksyProtocols.h"
#import "FleksyThemeableUI.h"
#import "FleksyCursorControllable.h"

/**
 Controls the display of the suggestions on the top of the keypad.
 
 Should have a refactor at some point.
 */
@interface FleksySuggestionView : UIScrollView <FleksyThemeableUI, FleksyCursorControllable, FleksyDictionaryModificationPresenter>

@property (nonatomic) BOOL isPunctuation;
@property (nonatomic) UIFont *currentTextFont;
@property (nonatomic, weak) id<FleksySuggestionViewDelegate> suggestionsDelegate;
- (instancetype)initWithTheme:(FleksyTheme *)theme
               flKeyboardSize:(FLKeyboardSize)flKbSize
                       kbSize:(CGRect)kbSize;
- (void)showSuggestions:(NSArray *)suggestions
      withSelectedIndex:(int)selectedIndex;
- (void)displaySuggestionView:(BOOL)shouldDisplay; // prefer this if it's just changing visibility of suggestion View
- (void)fadeoutSuggestionsDefered:(BOOL)shouldDeffer;
- (void)selectSuggestionWithIndex:(int)selectedIndex;
- (void)respondToSizeChange:(FLKeyboardSize )size
                     kbSize:(CGRect)kbSz;

@end
