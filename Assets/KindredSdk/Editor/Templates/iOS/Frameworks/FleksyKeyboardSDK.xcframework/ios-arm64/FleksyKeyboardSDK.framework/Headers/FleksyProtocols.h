//
//  FleksyProtocols.h
//  FleksyKitContainerApp
//
//  Created by Tusi Chowdhury on 6/10/14.
//  Copyright (c) 2014 Thingthing, Ltd. All rights reserved.
//

#ifndef FleksyInputViewControllerDelegate_h
#define FleksyInputViewControllerDelegate_h

#import <UIKit/UIKit.h>
#import "FleksyEngine/FLEnums.h"
#import "FleksyDefines.h"
#import "FleksyViewControllerPresenter.h"
#import "FleksyFontProvider.h"
#import "FleksySpeechManager.h"

/**
 Delegate to the input view controller, for use in passing platform textfield events from the platform to the engine.
 */
@protocol FleksyInputViewControllerDelegate <NSObject>

- (void)textWillChange:(id<UITextInput>)textInput;
- (FleksyTextChangeEventType)textDidChange:(id<UITextInput>)textInput; //the bool represents whether the textField/View has changed (work around for iOS 8 beta 5 bug where textDidChange gets fired more than once for the first word
- (void)selectionWillChange:(id<UITextInput>)textInput;
- (void)selectionDidChange:(id<UITextInput>)textInput;

@end

@protocol FleksySuggestionViewDelegate <FleksyFontProvider>

- (BOOL)isInLandscape;

@end

@protocol FleksyXtraViewStateProtocol <NSObject>

- (BOOL)isExtensionVisible;
- (UIFont *)extensionFont;
- (FLKeyboardID)getCurrentKeyboardID;
@property (nonatomic, readonly) FleksySpeechManager *speechManager;

@end

@protocol FleksyEngineManagerAlternateInputSource <UIKeyInput>

@property (readonly)NSString *text;

@end

@protocol FleksyHighlightsContentViewControllerDelegate <FleksyViewControllerPresenter>

@property (readonly, nonatomic) BOOL isInLandscape;
- (void)notifyUserWithString:(NSString *)string;
- (void)directlyInsertText:(NSString *)text;
- (void)returnToKeyboardFromHighlights;

@end

@protocol FleksyDictionaryModificationPresenter <NSObject>

- (void)dictionaryModifiedWithEvent:(FLDictionaryChangeEvent)event
                               word:(NSString *)word;
- (void)showSuggestions:(NSArray *)suggestions
          selectedIndex:(int)selectedIndex
                   type:(FLSuggestionsType)type;
@end

#endif // FleksyInputViewControllerDelegate_h
