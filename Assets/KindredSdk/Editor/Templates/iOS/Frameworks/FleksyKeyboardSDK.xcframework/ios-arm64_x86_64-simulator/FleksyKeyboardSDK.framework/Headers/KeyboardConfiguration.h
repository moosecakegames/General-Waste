//
//  KeyboardConfiguration.h
//  FleksyKeyboardSDK
//
//  Created by Xevi on 19/04/2020.
//  Copyright © 2020 Thingthing,Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "AppearanceObject.h"
#import "AppearancePopup.h"
#import "AppearanceLongPress.h"

NS_ASSUME_NONNULL_BEGIN

/**
 - captureOutput_file : store the content of the data capture in a file as JSon format
 - captureOutput_string  : send the data captured via delegate as String as JSon format
 - captureOutput_dictionary : send the data captured via delegate as Dictionary format
 */
typedef NS_ENUM(NSUInteger, enumCaptureOutput){
  captureOutput_file,
  captureOutput_string,
  captureOutput_dictionary
};

/**
 - dataCaptureCoordinate_screenPixel :
 - dataCaptureCoordinate_keyboardPixel :
 - dataCaptureCoordinate_keyboard :
 - dataCaptureCoordinate_internalKeyboard :
 */
typedef NS_ENUM(NSUInteger, enumDataCaptureCoordinate){
  dataCaptureCoordinate_screenPixel,
  dataCaptureCoordinate_keyboardPixel,
  dataCaptureCoordinate_keyboard,
  dataCaptureCoordinate_internalKeyboard
};

//
// Specific data to capture if we want to customise what we capture
//
@interface FLDataConfiguration : NSObject

@property (nonatomic, nullable, readonly) NSMutableDictionary* configuration;

- (instancetype) init;

- (instancetype) initWithDictionary:(NSDictionary*) dict;

- (instancetype) initWithText:(BOOL) dataText swipe:(BOOL) dataSwipe emoji:(BOOL) dataEmoji
                       layout:(BOOL) dataLayout textField:(BOOL) dataTextField lang:(BOOL) dataLang
                        press:(BOOL) dataPress position:(BOOL) dataPosition type:(BOOL) dataType
                         area:(BOOL) dataArea code:(BOOL) dataCode keyPress:(BOOL) dataKeyPress
                    keyCenter:(BOOL) dataKeyCenter keyBounds:(BOOL) dataKeyBounds
                   coordinate:(enum enumDataCaptureCoordinate) dataCaptureCoordinate;

- (NSString*) convertDictionaryToJSON;
- (void) addPropertySizeInMm:(CGSize) sizeMm;
- (void) addPropertySizeInPx:(CGSize) sizePx;
- (void) addPropertySizeInPts:(CGSize) sizePts;
- (void) addPropertyToConfiguration:(NSString*) key objectNumber:(NSNumber*) object;
- (void) addPropertyToConfiguration:(NSString*) key objectString:(NSString*) object;

@end

//
//  CaptureConfiguration with all the capture parameters
//
@interface CaptureConfiguration : NSObject

- (instancetype) initWith:(BOOL) enabled output:(enumCaptureOutput) output;
- (instancetype) initWith:(BOOL) enabled output:(enumCaptureOutput) output dataConfig:(FLDataConfiguration*) dataConfig;

@property (nonatomic) BOOL enabled;
@property (nonatomic) enumCaptureOutput output;
@property (nonatomic) FLDataConfiguration* dataConfig;

// Enable to receive analytics report automatically generated
// by the KeyboardSDK
// It contains autocorrection errors, ...
@property (nonatomic) BOOL enabledReportAnalytics;

@end

//
// SpaceBar Configuration to configure logo / languages in the spacebar
//
typedef NS_ENUM(NSUInteger, enumSpacebarStyle){
  spacebarStyle_Automatic     = 0,
  spacebarStyle_LogoOnly      = 1,
  spacebarStyle_LanguageOnly  = 2
};

@interface StyleConfiguration : NSObject

- (instancetype) initWithTheme:(NSDictionary*) dictTheme
                 withDarkTheme:(NSDictionary*) dictDarkTheme;

@property (nonatomic) NSDictionary* dictForceTheme;
@property (nonatomic) NSDictionary* dictForceDarkTheme;

@property (nonatomic) NSString* spacebarLogo;
@property (nonatomic) BOOL fitSpacebarLogo;
@property (nonatomic) enumSpacebarStyle spacebarStyle;

@end


@interface AppearanceConfiguration : NSObject

- (instancetype) initWithObjPopup:(nullable AppearancePopup*) objPoup
                         objTouch:(nullable AppearanceObject*) objTouch
                     objLongpress:(nullable AppearanceLongPress*)  objLongpress;
@property (nonatomic) AppearancePopup* appearancePopup;
@property (nonatomic) AppearanceObject* appearanceTouch;
@property (nonatomic) AppearanceLongPress* appearanceLongpress;
@property (nonatomic) UIEdgeInsets insetsKeyboard;
@end


//
// Typing Configuration to configure some of the settings initially
//
@interface TypingConfiguration : NSObject

// If this array is present, SDK uses this array to show up when we long press in the "punctuation" key,
// next to the enter key
@property (nonatomic) NSArray<NSString*>* arrayPunctuationSymbols;

@end

//
// Emoji Configuration to configure emoji configuration
//
typedef NS_ENUM(NSUInteger, enumEmojiSkinTone){
  emojiSkinTone_Neutral       = 0,
  emojiSkinTone_Light         = 1,
  emojiSkinTone_Medium_Light  = 2,
  emojiSkinTone_Medium        = 3,
  emojiSkinTone_Medium_Dark   = 4,
  emojiSkinTone_Dark          = 5
};

@interface EmojiConfiguration : NSObject

- (instancetype) initWithSkinTone:(enumEmojiSkinTone) skinTone;

@property (nonatomic) enumEmojiSkinTone emojiSkinTone;

@end

//
// Debug Configuration to set up properties for debugging the SDK
//
@interface DebugConfiguration : NSObject

// Enable every possible flag to debug
- (instancetype) initDebug;

@property (nonatomic) BOOL registerLayoutChange;

@end

//
// Special Keys Configuration to set up Magic Button
//
// By default, we have keep the basic configuration for the SDK
// with different elements from the array
@interface SpecialKeysConfiguration: NSObject

// Long press on special key left to space bar appears
// different options, that we call "magic button actions"
@property (nonatomic) NSArray* arrayMagicButton;

@end

//
// Panel Configuration: topbar height, customTopBar View, ..
//
@interface PanelConfiguration: NSObject

// This flag enables customTopbar, by default, not enabled
@property (nonatomic) BOOL enableCustomTopBar;

// If this has a value, we use this value for the height of the topbar
@property (nonatomic) CGFloat heightTopBar;

@end


/// -- Keyboard Configuration --
@interface KeyboardConfiguration : NSObject

- (instancetype) initWithCustomView:(BOOL) custom
                       heightCustom:(float) height
                            capture:(nullable CaptureConfiguration*) capture
                              style:(nullable StyleConfiguration*) style;

- (instancetype) initWithCustomView:(BOOL) custom
                       heightCustom:(float) height
                            capture:(nullable CaptureConfiguration*) capture
                              style:(nullable StyleConfiguration*) style
                         appearance:(nullable AppearanceConfiguration*) appearance;

- (instancetype) initWithCustomView:(BOOL) custom
                       heightCustom:(float) height
                            capture:(nullable CaptureConfiguration*) capture
                              style:(nullable StyleConfiguration*) style
                         appearance:(nullable AppearanceConfiguration*) appearance
                             typing:(nullable TypingConfiguration*) typing;

- (instancetype) initWithCustomView:(BOOL) custom
                       heightCustom:(float) height
                            capture:(nullable CaptureConfiguration*) capture
                              style:(nullable StyleConfiguration*) style
                         appearance:(nullable AppearanceConfiguration*) appearance
                             typing:(nullable TypingConfiguration*) typing
                              debug:(nullable DebugConfiguration*) debug;

- (instancetype) initWithPanel:(nullable PanelConfiguration*) panel
                       capture:(nullable CaptureConfiguration*) capture
                         style:(nullable StyleConfiguration*) style
                    appearance:(nullable AppearanceConfiguration*) appearance
                        typing:(nullable TypingConfiguration*) typing
                   specialKeys:(nullable SpecialKeysConfiguration*) specialKeys
                         debug:(nullable DebugConfiguration*) debug;
                   

@property (nonatomic) BOOL customTopBar;
@property (nonatomic) float heightCustomTopBar;
@property (nonatomic) BOOL needsInputMethodSwitch;

@property (nonatomic) CaptureConfiguration *capture;
@property (nonatomic) StyleConfiguration *style;
@property (nonatomic) AppearanceConfiguration* appearance;
@property (nonatomic) TypingConfiguration *typing;
@property (nonatomic) EmojiConfiguration *emojiConfig;
@property (nonatomic) SpecialKeysConfiguration *specialKeys;
@property (nonatomic) PanelConfiguration *panel;
@property (nonatomic) DebugConfiguration *debugConfig;



@end


/// -- Keyboard Dynamic Configuration --
///  -- Configuration that is able to be reloaded at any time
@interface KeyboardDynamicConfiguration : NSObject

// If we have enabled custom top bar height, we can change the height of it dynamically
// In case that we do not have this enabled, we cannot change the height if we do not reload the keyboard
@property (nonatomic) float heightCustomTopBar;

@end

NS_ASSUME_NONNULL_END
