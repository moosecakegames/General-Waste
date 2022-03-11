//
//  FleksyLayoutElement+KeypadUtilities.h
//  FleksyiOS
//
//  Created by Ben Pious on 1/6/16.
//  Copyright © 2016 Thingthing, Ltd. All rights reserved.
//

#import <FleksyEngine/FleksyEngine.h>
#import "FleksyEngineUIUniqueIdentifiable.h"
#import <UIKit/UIKit.h>

typedef NS_ENUM(NSUInteger, FleksyButtonAction) {
  FleksyButtonActionNoOp,
  FleksyButtonActionSetAutoCorrect,
  FleksyButtonActionSwitchSystemKeyboard,
  FleksyButtonActionDismissKeyboard,
  FleksyButtonActionOpenEmojiKeyboard,
  FleksyButtonActionInsertComma,
  FleksyButtonActionSwitchLanguage,
  FleksyButtonActionShowJapaneseSuggestions,
  FleksyButtonActionCustom
};

@interface FleksyLayoutElement (KeypadUtilities)

@property (nonatomic, readonly) NSString *displayLabel;
@property (nonatomic, readonly) BOOL needsSpecialAccessibilityLabel;
@property (nonatomic, readonly) CGRect displayFrame;
@property (nonatomic, readonly) Class classForUIElement;
@property (nonatomic, readonly) NSString *cornerIcon;
@property (nonatomic, readonly) FleksyButtonAction buttonAction;
@property (nonatomic, readonly) NSString *accessibilityLabel;
/**
 Returns an appropriate font for an element
 */
- (UIFont *)fontForElementFromFont:(UIFont *)font;
/**
 Prepares a user interface element to be reused by the keypad view
 @param interfaceElement a FleksyKey or FleksyButton
 @param font a font to apply to a FleksyKey. Has no affect on FleksyButtons
 */
- (void)prepareInterFaceElementForReuse:(UIView<FleksyEngineUIUniqueIdentifiable> *)interfaceElement
                                   font:(UIFont *)font;

@end
