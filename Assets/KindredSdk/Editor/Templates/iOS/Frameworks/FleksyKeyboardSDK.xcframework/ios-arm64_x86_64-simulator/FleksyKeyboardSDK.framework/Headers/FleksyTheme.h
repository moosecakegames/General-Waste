//
//  FleksyTheme.h
//  FleksyKitContainerApp
//
//  Created by Tusi Chowdhury on 2014-07-23.
//  Copyright (c) 2014 Thingthing, Ltd. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "FleksyUtility+Sounds.h"
#import "FleksyEngine/FLEnums.h"

#define THEME_CHANGE_DURATION 0.5

typedef enum {
  FleksyThemeTypeDark = 0,
  FleksyThemeTypeLight,
} FleksyThemeType;

typedef enum {
  FleksyGraphicsHardwareEffectNone = 0,
  FleksyGraphicsHardwareEffectHeatmap,
  FleksyGraphicsHardwareEffectMountains
} FleksyGraphicsHardwareEffect;

extern NSArray * ExtensionDefaultJSONFields;
extern NSArray * ContainerDefaultJSONFields;
extern NSArray * AllJSONFields;

/**
 Encapsulates information about a theme.
 */
@interface FleksyTheme : NSObject

@property (nonatomic, copy) NSString *name;
@property (nonatomic, copy) NSString *jsonString;
@property (readonly, nonatomic) NSArray *backgroundColorArray;
@property (readonly, nonatomic) NSArray *graphicsHardwareEffectColorArray;
@property (nonatomic, readonly) UIImage *backgroundImage;
@property (nonatomic, readonly) NSArray *imageArray;
@property (nonatomic) UIViewContentMode scalingMode;
@property (nonatomic) CGFloat imageAlpha;
@property (readonly, nonatomic) UIColor *homeRowColor;
@property (readonly, nonatomic) UIColor *spacebarColor;
@property (readonly, nonatomic) UIColor *outerButtonColor;
@property (readonly, nonatomic) UIColor *innerButtonColor;
@property (readonly, nonatomic) UIColor *pressedButtonColor;
@property (readonly, nonatomic) UIColor *keyPopColor;
@property (readonly, nonatomic) UIColor *plainTileLetterColor;
@property (readonly, nonatomic) UIColor *popTileLetterColor;
@property (readonly, nonatomic) UIColor *keyboardTextColor;
@property (readonly, nonatomic) UIColor *swipeColor;
@property (readonly, nonatomic) UIColor *dimmedTextColor;
@property (readonly, nonatomic) UIColor *outlineColor;
@property (readonly, nonatomic) UIColor *hoverLetters;
@property (readonly, nonatomic) UIColor *hoverBackground;
@property (readonly, nonatomic) UIColor *hoverSelectedLetters;
@property (readonly, nonatomic) UIColor *hoverSelectedBackground;
@property (readonly, nonatomic) UIColor *hoverTouch;
@property (nonatomic, readonly) UIColor *swipeLine;
@property (readonly, nonatomic) UIColor *keyShadow;
@property (readonly, nonatomic) UIColor *buttonShadow;
@property (readonly, nonatomic) UIColor *trackPadCursorColor;

@property (readonly, nonatomic) UIColor *suggestionLetters;
@property (readonly, nonatomic) UIColor *suggestionSelectedLetters;
@property (readonly, nonatomic) UIColor *suggestionBackground;
@property (readonly, nonatomic) UIColor *suggestionSelectedBackground;

@property (nonatomic, readonly) UIColor *appSelectedBackground;
@property (nonatomic, readonly) UIColor *appSelectedLetters;
@property (nonatomic, readonly) UIColor *appSearchBarBackground;
@property (nonatomic, readonly) UIColor *appSearchBarLetters;
@property (nonatomic, readonly) UIColor *appSearchBarCursor;
@property (nonatomic, readonly) UIColor *appFilterSelected;
@property (nonatomic, readonly) UIColor *appFilterLetters;

@property (readonly, nonatomic) NSString *backgroundImageName;
@property (readonly, nonatomic) BOOL hasBackgroundImage;
@property (readonly, nonatomic) BOOL shouldUseImageTransform;
@property (readonly, nonatomic) UIFont *defaultKeyboardFont;
@property (nonatomic, strong) UIFont *fontKeyboardNormal;
@property (nonatomic, readonly) FleksyThemeType currentThemeType;
@property (nonatomic) FleksyGraphicsHardwareEffect graphicsHardwareEffect;
@property (nonatomic) BOOL isVibrant;
@property (nonatomic) BOOL isTransparent;
@property (nonatomic) BOOL isUsingGraphicsHardware;
@property (nonatomic) BOOL customColorEnabled;
@property (nonatomic) UIColor *customKeyPopColor;
@property (nonatomic, readonly) BOOL rainbowPopEnabled;
@property (nonatomic) BOOL isChameleon;
@property (nonatomic) BOOL isTimeLapse;
@property (nonatomic) BOOL isLogoMono;
@property (nonatomic) BOOL isLookFeelSystem;
@property (nonatomic) BOOL hasCustomTouchView;
@property (readonly, nonatomic) BOOL shouldUseOutline;
@property (readonly) BOOL isParallax;
@property (nonatomic, readonly) BOOL isDynamic;
@property (nonatomic, readonly) BOOL changesColorOnSwipe;
@property (nonatomic) CGAffineTransform imageTransform;
@property (nonatomic, readonly) NSString *themeKey;
@property (nonatomic, readonly) BOOL isUserTheme;
@property (nonatomic, readonly) BOOL hasCustomSounds;
/**
 Non-square key pops come from the fleksy font. If this is not 0, then
 it should be used instead of a normal key pop view.
 */
@property (nonatomic, readonly) unichar keypopCharacter;
@property (nonatomic) BOOL isUsingAlternateThemeColors;
/**
 A theme is generally created by reading a JSON string from the themes.json file 
 that ships with Fleksy.
 */
- (instancetype)initWithJSONString:(NSString *)json;
- (instancetype)initWithThemeDictionary:(NSDictionary *)dict;
- (void)resetThemeKey;
- (void)changeFontWithName:(NSString *)fontName;
- (UIColor *)rainbowPopColor;
- (BOOL)isEqualToTheme:(FleksyTheme *)other;
- (UIFont *)keypadFontForTraitCollection:(UITraitCollection *)traitCollection
                        isLetterKeyboard:(BOOL)isLetters
                            keyboardSize:(FLKeyboardSize)size
                               landscape:(BOOL)isInLandscape;
- (UIFont *)extensionsFontForTraitCollection:(UITraitCollection *)traitCollection
                            isLetterKeyboard:(BOOL)isLetters
                                keyboardSize:(FLKeyboardSize)size
                                   landscape:(BOOL)isInLandscape;
- (NSString *)soundFileNameForSound:(FleksySoundType)sound;
+ (NSString *)JSONStringForKey:(NSString *)themeKey
                    withFields:(NSArray *)fields;
+ (NSDictionary *) JSONDictionaryForKey:(NSString *)themeKey withFields:(NSArray *)fields;
+ (NSString *)keyForJSONString:(NSString *)themeJSON;
+ (NSDictionary *)themes;
+ (NSURL *)urlForThemeFile;
+ (BOOL)validateJSONDictionary:(NSDictionary *)dictionary;
+ (NSArray<NSString *> *)validThemeGlyphs;

@end

