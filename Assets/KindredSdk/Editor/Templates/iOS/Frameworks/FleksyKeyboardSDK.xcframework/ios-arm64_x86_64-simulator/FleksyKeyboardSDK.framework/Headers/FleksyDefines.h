//
//  FleksyDefines.h
//  FleksyFramework
//
//  Created by Tusi Chowdhury on 2014-09-30.
//  Copyright (c) 2014 Thingthing, Ltd. All rights reserved.
//

#ifndef FleksyFramework_FleksyDefines_h

#define FleksyFramework_FleksyDefines_h

#include <Foundation/NSString.h>

static inline void NS_FORMAT_FUNCTION(1, 2) _FSLogNull(NSString *format, ...) { (void)format; }

//#define FLEKSY_BUILDING_FOR_APPSTORE

//GLOBALS
#if defined(DEBUG) && DEBUG
  #define FSLOG(format, ...)  NSLog(@"%@(%d): " format, @(__PRETTY_FUNCTION__), __LINE__, ##__VA_ARGS__)
#else
  #define FSLOG(format, ...) _FSLogNull(format, ##__VA_ARGS__)
#endif

#define LOG_TOUCHES 1
#if LOG_TOUCHES
#define FSTLOG(format, ...) FSLOG(@"Touch Log: %@(%d): " format, @(__PRETTY_FUNCTION__), __LINE__, ##__VA_ARGS__)
#else
#define FSTLOG(format, ...) _FSLogNull(format, ##__VA_ARGS__)
#endif

#define LOG_TEXT_INPUT_INTERACTION 1
#if LOG_TOUCHES
#define FSTILOG(format, ...) FSLOG(@"Touch Log: %@(%d): " format, @(__PRETTY_FUNCTION__), __LINE__, ##__VA_ARGS__)
#else
#define FSTILOG(format, ...) _FSLogNull(format, ##__VA_ARGS__)
#endif

#define FLKeyboardSize_ORIGINAL_Str @"FLKeyboardSize_ORIGINAL"
#define FLKeyboardSize_SMALL_Str @"FLKeyboardSize_SMALL"
#define FLKeyboardSize_LARGE_Str @"FLKeyboardSize_LARGE"

extern NSString *const FleksyCloudSettingsAheadOfLocalSettingsNotification;

extern NSString *const kDefaultThemeString;

static NSString * const FLEKSY_DID_RECOGNIZE_PAN  = @"FleksyInputViewDidRecognizePanGesture";
static NSString * const FLEKSY_KEYBOARD_ID_DID_CHANGE = @"FleksyKeyboardIDDidChange";

extern NSString * const FLEKSY_SETTINGS_FLEKSY_USER_ID_KEY;
extern NSString * const FLEKSY_SETTINGS_USER_AUTO_CORRECTION;
extern NSString * const FLEKSY_SETTINGS_USER_AUTO_CAPITALIZATION;
extern NSString * const FLEKSY_SETTINGS_FAST_DELETE;

extern NSString * const FLEKSY_SETTINGS_THEME;
extern NSString * const FLEKSY_SETTINGS_INVISIBLE;
extern NSString * const FLEKSY_SETTINGS_SPEAK;
extern NSString * const FLEKSY_SETTINGS_KEYBOARD_CLICKS;
extern NSString * const FLEKSY_SETTINGS_TYPING_SOUNDS;
extern NSString * const FLEKSY_SETTINGS_SPACEBAR_ROW;
extern NSString * const FLEKSY_SETTINGS_LANGUAGE_PACK_KEY;
extern NSString * const FLEKSY_SETTINGS_LANGUAGE_LAST_UPDATE;
extern NSString * const FLEKSY_SETTINGS_LANGUAGE_LETTER_LAYOUTS;
extern NSString * const FLEKSY_SETTINGS_LANGUAGE_INSTALLED_ORDER;
extern NSString * const FLEKSY_SETTINGS_RECENT_USED_EMOJIS;
extern NSString * const FLEKSY_SETTINGS_EMOJI_LAST_SECTION;
extern NSString * const FLEKSY_SETTINGS_EMOJI_RACE_PREFERENCES;
extern NSString * const FLEKSY_SETTINGS_COMPACT_MODE;
extern NSString * const FLEKSY_SETTINGS_DISPLAY_SUGGESTIONS;
extern NSString * const FLEKSY_SETTINGS_USE_ALL_ACCENTS;
extern NSString * const FLEKSY_SETTINGS_MAGIC_BUTTON_ORDER;
extern NSString * const FLEKSY_SETTINGS_DISPLAY_LANGUAGE;
extern NSString * const FLEKSY_SETTINGS_DOUBLE_TAP_PERIODS;
extern NSString * const FLEKSY_SETTINGS_KEYPAD_FONT;
extern NSString * const FLEKSY_SETTINGS_HOMEROW_VISIBLE;
extern NSString * const FLEKSY_SETTINGS_HOMEROW_ANIMATION;
extern NSString * const FLEKSY_SETTINGS_ASK_FOR_FEEDBACK;
extern NSString * const FLEKSY_SETTINGS_LONGPRESS_PUNCTUATION;
extern NSString * const FLEKSY_SETTINGS_AUTOCORRECT_WITH_PUNCTUATION;
extern NSString * const FLEKSY_SETTINGS_SHOW_WORD_PREDICTIONS;
extern NSString * const FLEKSY_SETTINGS_DISABLE_SMART_SPACING;
extern NSString * const FLEKSY_SETTINGS_EVENT_PROPERTIES;
extern NSString * const FLEKSY_SETTINGS_LAST_TIME;
extern NSString * const FLEKSY_SETTINGS_LAST_TIME_APPS;
extern NSString * const FLEKSY_SETTINGS_ENABLE_SWIPE_TOP_BAR;
extern NSString * const FLEKSY_SETTINGS_AUTOLEARN_FROM_USER;
extern NSString * const FLEKSY_SETTINGS_AUTODETECT_LANGUAGE;
extern NSString * const FLEKSY_SETTINGS_SWIPE_LENGTH;
extern NSString * const FLEKSY_SETTINGS_DO_NOT_TRACK;
extern NSString * const FLEKSY_SETTINGS_CONSENT_ACCEPTED;
extern NSString * const FLEKSY_SETTINGS_DELETE_CORRECTION;
extern NSString * const FLEKSY_SETTINGS_SWIPETYPING;
extern NSString * const FLEKSY_SETTINGS_KEYPRESS_AS_ACCENT;
extern NSString * const FLEKSY_SETTINGS_REPORT_ANALYTICS;
extern NSString * const FLEKSY_SETTINGS_EMOJI_SUGGESTION;
extern NSString * const FLEKSY_SETTINGS_EMOJI_PREDICTION;
extern NSString * const FLEKSY_SETTINGS_UNDERLINE_SPELL_CHECK;

extern NSString * const FLEKSY_SETTINGS_CONTENT_FILTER;

extern NSString * const FLEKSY_SETTINGS_KEYBOARD_SIZE;
extern NSString * const FLEKSY_SETTINGS_LAST_KEYBOARD;

extern NSString * const FLEKSY_PERMISSION_NOTIFICATIONS;

extern NSString * const FLEKSY_USER_EMAIL_SET;

extern NSString * const FLEKSY_EVENT_PUSH_NOTIFICATION_ASK;
extern NSString * const FLEKSY_EVENT_COUNT_WORDS_TYPED_MINIMAL;
extern NSString * const FLEKSY_EVENT_COUNT_WORDS_TYPED;
extern NSString * const FLEKSY_EVENT_COUNT_EMOJIS_TYPED;
extern NSString * const FLEKSY_EVENT_COUNT_SWIPES_LEFT;
extern NSString * const FLEKSY_EVENT_COUNT_SWIPES_RIGHT;
extern NSString * const FLEKSY_EVENT_COUNT_SWIPES_RIGHT_DOUBLE;
extern NSString * const FLEKSY_EVENT_COUNT_SWIPES_LEFT_DOUBLE;
extern NSString * const FLEKSY_EVENT_COUNT_SWIPES_UP;
extern NSString * const FLEKSY_EVENT_COUNT_SWIPES_DOWN;
extern NSString * const FLEKSY_EVENT_COUNT_SWIPES_UP_DOUBLE;
extern NSString * const FLEKSY_EVENT_COUNT_SWIPES_DOWN_DOUBLE;
extern NSString * const FLEKSY_EVENT_COUNT_AUTOCORRECTIONS;
extern NSString * const FLEKSY_EVENT_DISMISSED_XTRAS_HINT;
extern NSString * const FLEKSY_EVENT_HAS_DECIDED_TO_RATE_FLEKSY;
extern NSString * const FLEKSY_EVENT_LAST_ASKED_FOR_RATING;

extern NSString* const  FLESKY_EVENT_COUNT_LOAD_KEYBOARD;

extern NSString* const  FLESKY_EVENT_DATE_DAY;
extern NSString* const  FLESKY_EVENT_DATE_WEEK;
extern NSString* const  FLESKY_EVENT_COUNT_TIME_SECONDS;
extern NSString* const  FLESKY_EVENT_COUNT_TIME_KEYBOARD_DAY;

extern NSString * const FLEKSY_EVENT_COUNT_QUESTION_MARK;
extern NSString * const FLEKSY_EVENT_COUNT_SENTENCES;
extern NSString * const FLEKSY_EVENT_TUTORIAL_FINISHED;
extern NSString * const FLEKSY_EVENT_SUBMITTED_FEEDBACK;

extern NSString * const FLEKSY_EVENT_DISMISSED_EMOJI_TUTORIAL;
extern NSString * const FleksyEventDismissedGIFTutorial;

extern NSString * const FLEKSY_EVENT_FIRST_TYPE;

extern NSString * const FLEKSY_SETTINGS_DidChangeNotification;
extern NSString * const FLEKSY_PERMISSION_didRespondToRequest;

extern NSString * const FLEKSY_AB_TEST_PARTICIPATION;

extern NSString * const FLEKSY_TUTORIAL_HINT_NEXTKEYBOARD_COUNT;
extern NSString * const FLEKSY_TUTORIAL_HINT_SPACEBAR_ON;
extern NSString * const FLEKSY_SETTINGS_KEYBOARDLAYOUT_SYSTEM;
extern NSString * const FLEKSY_SETTINGS_DISPLAY_LOWERCASE_LETTERS;

extern NSString * const FLEKSY_ENGINE_VERSION;

extern NSString * const FLEKSY_XTRAS_ENABLED;             //fleksy Xtras that are enabled by the user
extern NSString * const FLEKSY_XTRAS_ORDERED_KEYS;        //Xtras by key for use by Mixpanel in the keyboard.
extern NSString * const FLEKSY_XTRAS_HOTKEYS;
extern NSString * const FLEKSY_XTRAS_RECENT_GIFS;
extern NSString * const FLEKSY_XTRAS_SAVED_GIFS;
extern NSString * const FLEKSY_XTRAS_CUSTOM_KEYPOP_COLOR;
extern NSString * const FLEKSY_PURCHASES_LIST;

extern NSString * const FLEKSY_XTRAS_RECENT_FLG_GIFS;

extern NSString * const FLEKSY_KEYBOARD_STATE_ONEHANDED;  //Store 0,1, or 2 for not onhanded, onehanded-Left, onehanded-Right respectively
extern NSString * const FLEKSY_DISPLAY_XTRA;
extern NSString * const FLEKSY_XTRA_FOREMOST_INMENU;
extern NSString * const FLEKSY_XTRA_HOTKEY_INDEX;
extern NSString * const FLEKSY_SETTINGS_CONFIGURABLE_BUTTON;
extern NSString * const FLEKSY_SETTINGS_SHOW_JET_FILE_INFO;

extern NSString * const FLEKSY_SETTINGS_LAST_VERSION;

extern NSString *const FLEKSY_SETTINGS_LAST_CONTAINER_SETTINGS_UPDATE_URL_EXTENSION;
extern NSString *const FLEKSY_SETTINGS_LAST_EXTENSION_CONTAINER_SYNCH_DATE;

extern NSString * const FLEKSY_XTRAS_RECENT_IMOJIS;
extern NSString * const FLEKSY_XTRAS_SAVED_IMOJIS;

extern NSString * const FLEKSY_XTRAS_RECENT_STICKERS;
extern NSString * const FLEKSY_XTRAS_SAVED_STICKERS;

extern NSString * const FLEKSY_EARNED_LIST;
extern NSString * const FLEKSY_SETTINGS_CLOUD_LAST_SETTINGS_CHANGED_DATE;
extern NSString * const FLEKSY_SETTINGS_LAST_LOCAL_SETTINGS_CHANGED_DATE;
extern NSString * const FLEKSY_BADGES_LIST;

// Notifications to subscribe
extern NSString* const NOTIFICATION_KEY_PRESSED;
extern NSString* const NOTIFICATION_KEY_RELEASED;
extern NSString* const NOTIFICATION_KEY_SWIPE_RELEASED;
extern NSString* const NOTIFICATION_KEY_LONGPRESS_RELEASED;
extern NSString* const NOTIFICATION_KEY_NEW_NWP;


typedef enum {
  FleksyControlTypeShiftKey,
  FleksyControlTypeNumbersKey,
  FleksyControlTypeLettersKey,
  FleksyControlTypeSymbolsKey,
  FleksyControlTypeSpaceKey,
  FleksyControlTypeNumPadSpaceKey,
  FleksyControlTypeNumPadZeroKey,
  FleksyControlTypeBackspaceKey,
  FleksyControlTypeEnterKey,
  FleksyControlTypeGlobeKey,
  FleksyControlTypePeriodKey,
  FleksyControlTypeAtSignKey,
  FleksyControlTypeEmojiKey,
  FleksyControlTypeCommaKey,
  FleksyControlTypeHashKey,
  FleksyControlTypeHideKeyboardKey,
  FleksyControlTypeAutoCorrectOffKey,
  FleksyControlTypeTotalKeys,         // Total hardcoded keys. After these ones, we could add custom ones.
} FleksyControlType;

typedef NS_ENUM(NSUInteger, FleksyTouchType) {
  FleksyTouchTypeUnknown = 0,
  FleksyTouchTypeTap = 1,
  FleksyTouchTypeSwipeLeft = 2,
  FleksyTouchTypeSwipeRight = 3,
  FleksyTouchTypeSwipeUp = 4,
  FleksyTouchTypeSwipeDown = 5,
  FleksyTouchTypeTwoFingerSwipeUp = 6,
  FleksyTouchTypeTwoFingerSwipeDown = 7,
  FleksyTouchTypeLongPress = 8,
  FleksyTouchTypeForceTouch = 9,
};

typedef enum {
  FleksyPermissionNone,
  FleksyPermissionGranted,
  FleksyPermissionSoftRejected,
  FleksyPermissionRejected
} FleksyPermission;

typedef NS_ENUM(NSInteger, FleksyXtrasType) {
  FleksyXtraNull = -1,
  FleksyXtraOneHanded,
  FleksyXtraNumbersInLettersKeyboard,
  FleksyXtraRainbowKeyPop,
  FleksyXtraEditor,
  FleksyXtraGif,
  FleksyXtraHotkeys,
  FleksyXtraTips,
  FleksyXtraHeartShapedKeypop,
  FleksyXtraCustomPopColor,
  FleksyXtraImojiKeyboard,
  FleksyXtraEmojiSuggestions,
  FleksyXtraHighlights,
  FleksyXtraJapaneseNextWordPrediction,
  FleksyXtraTypeNextWordPrediction,
  FleksyXtraEmptyView,
};

typedef NS_ENUM(NSUInteger, FleksyTextChangeEventType) {
  FleksyTextChangeEventTypeNoChange,
  FleksyTextChangeEventTypeNewField,
  FleksyTextChangeEventTypeCursorPositionOrTextChange,
};

#endif
