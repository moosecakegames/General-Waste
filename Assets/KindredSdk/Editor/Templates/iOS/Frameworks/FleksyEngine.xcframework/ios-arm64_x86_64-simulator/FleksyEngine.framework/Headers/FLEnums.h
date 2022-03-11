//
//  FLEnums.h
//  FleksySDK
//
//  Copyright (c) 2013 Thingthing, Ltd. All rights reserved.
//
#ifndef FleksyEngine_FLEnums_h
#define FleksyEngine_FLEnums_h

#include <stdint.h>

#ifdef __cplusplus
#define FL_EXTERN_C extern "C"
#else
#define FL_EXTERN_C extern
#endif


/*
 FLButtonType
 
 If you add a button type here, and want it to work properly when loading from a
 keyboard file, you need to update FLButton::_stringToButtonTypeMap to include
 your new button type.

 Why is this different from the other enums? We're doing an experiment.
 To communicate with Android, we basically end up converting enums to ints and back
 constantly. It is totally sucky. So, we're trying the old-fashioned way with just
 defining them as static consts. Similarly, they are ints because that makes things
 easier when talking with Android.
 */
typedef int FLButtonType;
static const int FLButtonType_Other          = 0;
static const int FLButtonType_Letter         = 1;
static const int FLButtonType_Shift_Off      = 2;
static const int FLButtonType_Enter          = 3;
static const int FLButtonType_Spacer         = 4;
static const int FLButtonType_Space          = 5;
static const int FLButtonType_Backspace      = 6;
static const int FLButtonType_Emoji          = 7;
static const int FLButtonType_Symbols        = 8;
static const int FLButtonType_Henkan_Left    = 9;
static const int FLButtonType_Henkan_Right   = 10;
static const int FLButtonType_Language       = 11;
static const int FLButtonType_Letters_Switch = 12; //Button for lettersLayout
static const int FLButtonType_Magic          = 13;
static const int FLButtonType_Punctuation    = 14;
static const int FLButtonType_Numbers        = 15;
static const int FLButtonType_Next           = 16;
static const int FLButtonType_Previous       = 17;
static const int FLButtonType_Mic_On         = 19;
static const int FLButtonType_Mic_Off        = 20;
static const int FLButtonType_Numpad_Symbols = 21;
static const int FLButtonType_Shift_On       = 22;
static const int FLButtonType_Caps_On        = 23;
static const int FLButtonType_Language_Left  = 24;
static const int FLButtonType_Language_Right = 25;
static const int FLButtonType_Letter_Button  = 26;
static const int FLButtonType_CandidateView2D= 27;
static const int FLButtonType_FlickPunc      = 28; // Appears only on ja-JP Flick layout.
static const int FLButtonType_DropDown       = 29;
static const int FLButtonType_ReturnToEmoji  = 30;

typedef int FleksyLayout;
static const int  FleksyLayout_INVISIBLE     = 2;
static const int  FleksyLayout_TRANSPARENT   = 3;
static const int  FleksyLayout_MINI          = 4;
static const int  FleksyLayout_FULL          = 5;

typedef int FleksyOrientation;
static const int  FleksyOrientation_PORTRAIT  = 100;
static const int  FleksyOrientation_LANDSCAPE = 101;

// Setting keys
FL_EXTERN_C const char * const USE_ALL_ACCENTS_KEY;
FL_EXTERN_C const char * const USE_APPLE_SYMBOLS_KEY;
FL_EXTERN_C const char * const USE_LEGACY_LAYOUT_KEY;
FL_EXTERN_C const char * const USE_STANDARD_LAYOUT_SYSTEM;
FL_EXTERN_C const char * const DONT_USE_AUTOCORRECT_KEY;
FL_EXTERN_C const char * const SWAP_ENTER_DELETE_KEY;
FL_EXTERN_C const char * const FLEKSY_LAYOUT_KEY;
FL_EXTERN_C const char * const USE_CASE_SENSITIVE_LAYOUT_KEY;
FL_EXTERN_C const char * const HAS_MICROPHONE_KEY;
FL_EXTERN_C const char * const ENABLE_NSP_KEY;
FL_EXTERN_C const char * const PACKAGE_NAME_KEY;
FL_EXTERN_C const char * const FINAL_LOGSCORE_THRESHOLD;
FL_EXTERN_C const char * const CONFIG_NEXT_SUGGESTIONS;
FL_EXTERN_C const char * const CONFIG_NLP_EMOJI_PREDICTION;
FL_EXTERN_C const char * const CONFIG_NLP_EMOJI_SUGGESTION;
FL_EXTERN_C const char * const CONFIG_NLP_EMOJI_SEARCH;
FL_EXTERN_C const char * const CONFIG_NLP_SWIPE;
FL_EXTERN_C const char * const DONT_CORRECT_DICT_WORDS_KEY;
FL_EXTERN_C const char * const ALLOW_CORRECTION_AFTER_REPARSING_KEY;
FL_EXTERN_C const char * const DOUBLE_SPACE_TAP_ADDS_PUNCT_KEY;
FL_EXTERN_C const char * const TRIPLE_SPACE_ADDS_SPACE_KEY;
FL_EXTERN_C const char * const ALLOW_BACKSPACE_TO_UNDO_AC;
FL_EXTERN_C const char * const DONT_CORRECT_AFTER_PUNCT;
FL_EXTERN_C const char * const DONT_CORRECT_UPPERCASE;
FL_EXTERN_C const char * const EXTERNAL_KEYBOARD_SIZE;
FL_EXTERN_C const char * const KEYBOARD_ORIENTATION;
FL_EXTERN_C const char * const CURRENT_WORD_PREDICTIONS;
FL_EXTERN_C const char * const ALLOW_AUTOLEARN_FROM_USER_KEY;
FL_EXTERN_C const char * const UI_DELIVER_KEYPRESS_AS_ACCENT;
FL_EXTERN_C const char * const DEVICE_IS_TABLET;

FL_EXTERN_C const char * const CONFIG_AC_SPACEBREAKS;
FL_EXTERN_C const char * const CONFIG_AC_MISSINGTAPS;
FL_EXTERN_C const char * const CONFIG_AC_TRANSPOSITION;
FL_EXTERN_C const char * const CONFIG_AC_INSERTION;


// Highlight keys
FL_EXTERN_C const char * const KEY_TILE_DEF;
FL_EXTERN_C const char * const KEY_TILE_SEL;
FL_EXTERN_C const char * const KEY_TILE_PRESS;
FL_EXTERN_C const char * const KEY_ICON_DEF;
FL_EXTERN_C const char * const KEY_ICON_OUT;
FL_EXTERN_C const char * const KEY_TEXT_DEF;
FL_EXTERN_C const char * const KEY_TEXT_OUT;
FL_EXTERN_C const char * const KEY_DISPLAY_TEXT;
FL_EXTERN_C const char * const KEY_DISPLAY_ICON;
FL_EXTERN_C const char * const KEY_EMOJI;
FL_EXTERN_C const char * const KEY_STYLE;
FL_EXTERN_C const char * const KEY_PROVIDERS;
FL_EXTERN_C const char * const KEY_PROVIDER_URX;
FL_EXTERN_C const char * const KEY_PROVIDER_IMOJI;
FL_EXTERN_C const char * const KEY_SEARCH;
FL_EXTERN_C const char * const KEY_PROVIDER_RIFFSY;
FL_EXTERN_C const char * const KEY_PROVIDER_FEATURED;

// Highlight events
FL_EXTERN_C const char * const HL_EVENT_POP;
FL_EXTERN_C const char * const HL_EVENT_KEYWORD_MATCH;
FL_EXTERN_C const char * const HL_EVENT_NSP;
FL_EXTERN_C const char * const HL_EVENT_NWP;
FL_EXTERN_C const char * const HL_EVENT_EMOJI;
FL_EXTERN_C const char * const HL_EVENT_ALL;

// NextEngine keys
FL_EXTERN_C const char * const NEXT_CURRENT_APP;
FL_EXTERN_C const char * const NEXT_CURRENT_LAYOUT;
FL_EXTERN_C const char * const NEXT_CURRENT_KEY_RETURN;
FL_EXTERN_C const char * const NEXT_DEVICE;
FL_EXTERN_C const char * const NEXT_COUNTRY;
FL_EXTERN_C const char * const NEXT_LANGUAGE;
FL_EXTERN_C const char * const NEXT_PLATFORM;

FL_EXTERN_C const char * const NEXT_SUGGESTIONS;

FL_EXTERN_C const char * const NEXT_SUGGESTION_ID;
FL_EXTERN_C const char * const NEXT_SUGGESTION_ACTION;
FL_EXTERN_C const char * const NEXT_SUGGESTION_TYPE;
FL_EXTERN_C const char * const NEXT_SUGGESTION_SHARE;
FL_EXTERN_C const char * const NEXT_SUGGESTION_TEXT;
FL_EXTERN_C const char * const NEXT_SUGGESTION_URL;
FL_EXTERN_C const char * const NEXT_SUGGESTION_KEYWORD;

FL_EXTERN_C const char * const APP_PLATFORM_IOS;
FL_EXTERN_C const char * const APP_PLATFORM_ANDROID;

FL_EXTERN_C const char * const NEXT_BACKEND_CAMPAIGNS;
FL_EXTERN_C const char * const NEXT_BACKEND_ID;
FL_EXTERN_C const char * const NEXT_BACKEND_DESC;
FL_EXTERN_C const char * const NEXT_BACKEND_LANGUAGE;
FL_EXTERN_C const char * const NEXT_BACKEND_URL;
FL_EXTERN_C const char * const NEXT_BACKEND_IMAGEURL;
FL_EXTERN_C const char * const NEXT_BACKEND_KEYWORDS;
FL_EXTERN_C const char * const NEXT_BACKEND_INTERESTS;

FL_EXTERN_C const char * const DATA_TEXT;
FL_EXTERN_C const char * const DATA_WORD;
FL_EXTERN_C const char * const DATA_SWIPE;
FL_EXTERN_C const char * const DATA_DELETE;
FL_EXTERN_C const char * const DATA_EMOJI;
FL_EXTERN_C const char * const DATA_LAYOUT;
FL_EXTERN_C const char * const DATA_KEY_PLANE;
FL_EXTERN_C const char * const DATA_TEXTFIELD;
FL_EXTERN_C const char * const DATA_LANG;
FL_EXTERN_C const char * const DATA_TYPE;
FL_EXTERN_C const char * const DATA_AREA;
FL_EXTERN_C const char * const DATA_CODE;
FL_EXTERN_C const char * const DATA_KEY_TEXT;
FL_EXTERN_C const char * const DATA_POSITION;
FL_EXTERN_C const char * const DATA_POSITION_END;
FL_EXTERN_C const char * const DATA_PRESS;
FL_EXTERN_C const char * const DATA_KEY_PRESS;
FL_EXTERN_C const char * const DATA_KEY_PRESS_END;
FL_EXTERN_C const char * const DATA_KEY_CENTER;
FL_EXTERN_C const char * const DATA_KEY_BOUNDS;
FL_EXTERN_C const char * const DATA_PREDICTIONS_TOUCH;
FL_EXTERN_C const char * const DATA_PREDICTION;
FL_EXTERN_C const char * const DATA_AUTOCORRECTION;
FL_EXTERN_C const char * const DATA_SCREEN_HEIGHT_MM;
FL_EXTERN_C const char * const DATA_SCREEN_HEIGHT_PX;
FL_EXTERN_C const char * const DATA_SCREEN_HEIGHT_BOTTOM_OFFSET_PX;
FL_EXTERN_C const char * const DATA_SCREEN_HEIGHT_PTS;
FL_EXTERN_C const char * const DATA_SCREEN_WIDTH_MM;
FL_EXTERN_C const char * const DATA_SCREEN_WIDTH_PX;
FL_EXTERN_C const char * const DATA_SCREEN_WIDTH_PTS;
FL_EXTERN_C const char * const DATA_CONFIG_COORDINATE;
FL_EXTERN_C const char * const DATA_CONFIG_FORMAT;

typedef enum{
  FLDataCaptureCoordinateScreenPixel = 0,
  FLDataCaptureCoordinateKeyboardPixel = 1,
  FLDataCaptureCoordinateKeyboard = 2,
  FLDataCaptureCoordinateInternalKeyboard = 3,
}FLDataCaptureCoordinate;

typedef enum{
  FLDataCaptureFormatStandard = 0,
  FLDataCaptureFormatGroupbyTap = 1,
}FLDataCaptureFormat;

typedef enum {
  FLDictionaryWordType_DAWG,
  FLDictionaryWordType_USER,
  FLDictionaryWordType_SHORTCUT,
  FLDictionaryWordType_NOT_FOUND
}FLDictionaryWordType;

typedef enum {
  FLCapitalizationMode_CAP_SENTENCES,
  FLCapitalizationMode_CAP_WORDS,
  FLCapitalizationMode_CAP_ALL,
  FLCapitalizationMode_CAP_OFF
}FLCapitalizationMode;

typedef enum {
  FLKeyboardID_QWERTY_LOWER = 0,    // 0
  FLKeyboardID_QWERTY_UPPER,        // 1
  FLKeyboardID_NUMBERS,             // 2
  FLKeyboardID_SYMBOLS,             // 3
  FLKeyboardID_QWERTY_AC_OFF_LOWER, // 4
  FLKeyboardID_EMOJIS,              // 5
  FLKeyboardID_NUMBER_PAD,          // 6
  FLKeyboardID_NUMBER_PAD_SYMBOLS,  // 7
  FLKeyboardID_SHIFT_1,             // 8
  FLKeyboardID_SHIFT_2,             // 9
  FLKeyboardID_SHIFT_3,             // 10
  FLKeyboardID_NUMBERS_IOS,         // 11
  FLKeyboardID_SYMBOLS_IOS,         // 12
  FLKeyboardID_TEMP,                // 13
  FLKeyboardID_NUMBERS_MINI,        // 14
  FLKeyboardID_QWERTY_AC_OFF_UPPER, // 15
  FLKeyboardID_TWITTER_LOWER,       // 16
  FLKeyboardID_TWITTER_UPPER,       // 17
  FLKeyboardID_URL_LOWER,           // 18
  FLKeyboardID_URL_UPPER,           // 19
  FLKeyboardID_NUMBER_OF_KEYBOARDS, // 20
  FLKeyboardID_INVALID
}FLKeyboardID;

typedef enum {
  FLTempKeyboardOrder_FORWARD = 0,
  FLTempKeyboardOrder_REVERSE,
  FLTempKeyboardOrder_ALTERNATING
}FLTempKeyboardOrder;

typedef enum {
  FLCorrectionMode_URL, //In this mode, when . is entered previous TB is not corrected
  FLCorrectionMode_ALWAYS,
  FLCorrectionMode_OFF
}FLCorrectionMode;

typedef enum {
  FLFieldAction_SEARCH,
  FLFieldAction_GO,
  FLFieldAction_NEXT,
  FLFieldAction_SEND,
  FLFieldAction_NEW_LINE,
  FLFieldAction_DONE,
  FLFieldAction_EMOTICON,
  FLFieldAction_NONE
}FLFieldAction;

typedef enum {
  FLKeyboardSize_LARGE,
  FLKeyboardSize_ORIGINAL,
  FLKeyboardSize_SMALL,
  FLKeyboardSize_TINY,
  FLKeyboardSize_NOT_SET
}FLKeyboardSize;

typedef enum {
  FLKeyboardLayout_NO_SPACEBAR,
  FLKeyboardLayout_SPACEBAR,
  FLKeyboardLayout_NOT_SET
}FLKeyboardLayout;

typedef enum {
  FLKeyboardAlpha_FULL,
  FLKeyboardAlpha_TRANSPARENT,
  FLKeyboardAlpha_NOT_SET
}FLKeyboardAlpha;

typedef enum {
  FLMessageType_DEBUG,
  FLMessageType_NO_NEXT_SUGGESTION,
  FLMessageType_NO_PREVIOUS_SUGGESTION,
  FLMessageType_EVENT,
  FLMessageType_ERROR,
  FLMessageType_ERROR1,  // FLTypingController::correctToNextSuggestion
  FLMessageType_ERROR2,  // unused
  FLMessageType_ERROR3,  // FLTypingController::updateCandidatesView
  FLMessageType_ERROR4,  // unused
  FLMessageType_BACKSPACE,
  FLMessageType_SPACEBAR_STATE_PUNCTUATION,
  FLMessageType_SPACEBAR_STATE_CLEAR,
  FLMessageType_SD_WHILE_TYPING_SINCE_LAST_AU,
  FLMessageType_NEXT_SUGGESTION // Suggest NEXT to show up suggestions while browsing
}FLMessageType;

//passed in as a parameter in onDictionaryModified
typedef enum {
  FLDictionaryChangeEvent_ADD,
  FLDictionaryChangeEvent_REMOVE,
  FLDictionaryChangeEvent_WORD_AUTOLEARNED
}FLDictionaryChangeEvent;

//Result when called from JAVA
typedef enum {
  FLDictionaryChangeResult_SUCCESS,
  FLDictionaryChangeResult_EXISTS,
  FLDictionaryChangeResult_NOT_FOUND,
  FLDictionaryChangeResult_ERROR
}FLDictionaryChangeResult;

typedef enum {
  /**
   In this mode, swipe left always deletes whole words except in no-ac fields.
   */
  FLDeleteMode_WHOLE_WORD
}FLDeleteMode;

typedef enum {
  // This is equivalent to "smart spacing off".
  FLPunctuationSpaceMode_DEFAULT, //[hello]+ -> [hello]+[.]-[|]

  // This is for URL text fields, and such.
  FLPunctuationSpaceMode_DEL_PRECEEDING_SPACE, //[hello]+ -> [hello]-[.]-[|]

  // This is the default mode.
  FLPunctuationSpaceMode_DEL_AND_ADD_SPACE //[hello]+ -> [hello]-[.]+[|]
}FLPunctuationSpaceMode;

typedef enum {
  FLTextFieldType_REGULAR_TEXT,
  FLTextFieldType_PASSWORD,
  FLTextFieldType_URL,
  FLTextFieldType_EMAIL_ADDRESS,
  FLTextFieldType_NO_SUGGESTIONS,
  FLTextFieldType_USER_AC_OFF,
  FLTextFieldType_TWITTER_USER_AC_OFF,
  FLTextFieldType_NUMBERS,
  FLTextFieldType_TWITTER,
  FLTextFieldType_WEBSEARCH
}FLTextFieldType;

typedef enum {
  FLSuggestionsType_REGULAR,
  FLSuggestionsType_PUNCTUATION,
  FLSuggestionsType_CLEAR_SUGGESTIONS //UI should clear the suggestions
}FLSuggestionsType;

typedef enum {
  FLEventType_SL,
  FLEventType_SR,
  FLEventType_SU,
  FLEventType_SD,
  FLEventType_RSW,
  FLEventType_RSP,
  FLEventType_P,
  FLEventType_MC,
  FLEventType_SH,
  FLEventType_KB,
  FLEventType_STS,
  FLEventType_ETS,
  FLEventType_CAPS,
  FLEventType_AW,
  FLEventType_RW,
  FLEventType_AC,
  FLEventType_MS,
  FLEventType_NL,
  FLEventType_KS,
  FLEventType_ME,
  FLEventType_DEL,
  FLEventType_ST,
  FLEventType_ET,
  FLEventType_FA,
  FLEventType_WT,
  FLEventType_ATW,
  FLEventType_ALW,
  FLEventType_NEW_WORD,
  FLEventType_SEL_SUGGESTION_0,
  FLEventType_CC, //Characters Corrected
  FLEventType_WC,  //Word Corrected
  FLEventType_WC_INTERNAL,  //Word Corrected
  FLEventType_UNDO_WC, // Undo word corrected 
  FLEventType_MISSED_ALL_CHARS,
  FLEventType_SEL_DEL,
  FLEventType_REPARSE,
  FLEventType_TD, //Text block deleted
  FLEventType_TI,
  FLEventType_SUW,
  FLEventType_SUP,
  FLEventType_SDW,
  FLEventType_SDP,
  FLEventType_TBS,
  FLEventType_NEU, //Noise Estimation Update
  FLEventType_SEL2D, // send 2D suggestion candidate
  FLEventType_SEL_NWP, // send next word prediction candidate
  FLEventType_HL,  // henkan left
  FLEventType_HR,  // henkan right
  FLEventType_CE,   // characters entered, useful for Japanese and Chinese
  FLEventType_BACKSPACE, // key backspace
  FLEventType_NONE
}FLEventType;

typedef enum {
  kLanguage_ar_AR,
  kLanguage_ar_EG,
  kLanguage_az_AZ,
  kLanguage_be_BY,
  kLanguage_bg_BG,
  kLanguage_ca_ES,
  kLanguage_cs_CZ,
  kLanguage_da_DK,
  kLanguage_de_DE,
  kLanguage_el_GR,
  kLanguage_en_AU,
  kLanguage_en_CA,
  kLanguage_en_FL,
  kLanguage_en_UK,
  kLanguage_en_US,
  kLanguage_es_ES,
  kLanguage_es_LA,
  kLanguage_es_US,
  kLanguage_et_EE,
  kLanguage_eu_ES,
  kLanguage_fa_IR,
  kLanguage_fi_FI,
  kLanguage_fr_CA,
  kLanguage_fr_FR,
  kLanguage_he_IL,
  kLanguage_hi_IN,
  kLanguage_hr_BA,
  kLanguage_hr_HR,
  kLanguage_hu_HU,
  kLanguage_hy_AM,
  kLanguage_id_ID,
  kLanguage_is_IS,
  kLanguage_it_IT,
  kLanguage_ja_JP,
  kLanguage_ka_GE,
  kLanguage_kk_KZ,
  kLanguage_ko_KR,
  kLanguage_ky_KG,
  kLanguage_lt_LT,
  kLanguage_lv_LV,
  kLanguage_mk_MK,
  kLanguage_mn_MN,
  kLanguage_ms_MY,
  kLanguage_nb_NO,
  kLanguage_nl_BE,
  kLanguage_nl_NL,
  kLanguage_no_NO,
  kLanguage_pl_PL,
  kLanguage_pt_BR,
  kLanguage_pt_PT,
  kLanguage_ro_RO,
  kLanguage_ru_RU,
  kLanguage_sk_SK,
  kLanguage_sl_SI,
  kLanguage_sq_AL,
  kLanguage_sr_RS,
  kLanguage_sv_SE,
  kLanguage_th_TH,
  kLanguage_tl_PH,
  kLanguage_tr_TR,
  kLanguage_uk_UA,
  kLanguage_uz_UZ,
  kLanguage_vi_VN,
  kLanguage_zh_CN,
  kLanguageUnknown,
  kLanguageAlphabetic
} kLanguage;

// Word Predictions definitions
typedef enum {
  FLWordPrediction_EnteredText = 0,               // Entered Text directly from the user
  FLWordPrediction_Suggestion = 1,                // Suggestion word
  FLWordPrediction_AutoCorrection = 2,            // Word that the engine will autocorrect
  FLWordPrediction_EnteredText_AutoCorrection = 3,// Word entered by the user is the same as the one that Engine will correct
  FLWordPrediction_Emoji = 4,                     // Emoji suggestion
  FLWordPrediction_Unknown = 5                    // Don't know or undefined
}FLWordPredictionType;


/// NEXT Actions, Type and Share definitions to work with the same language
typedef enum{
  FLNextSuggestionAction_WebSearch,      // Make a search action to the WebSearch
  FLNextSuggestionAction_ShowSuggestion, // Show a suggestion coming from the Engine (alias Ad)
  FLNextSuggestionAction_ShowText        // Show current text
}FLNextSuggestionAction;

typedef enum{
  FLNextSuggestionType_AutoComplete,
  FLNextSuggestionType_Text
}FLNextSuggestionType;

typedef enum{
  FLNextSuggestionShare_URL,
  FLNextSuggestionShare_Text
}FLNextSuggestionShare;


// Engine Events for set Data Configuration
typedef enum{
  FLEngineConfigEvent_Update_NextCampaigns,
}FLEngineConfigEvent;


// Used by listener.onSetComposingText()
typedef int32_t SetTextFlags;
static const int32_t FLSetComposingTextFlag_EmptyFlags = 0x0;
// The text being set is actually 'corrected', i.e., different from the use input.
static const int32_t FLSetComposingTextFlag_TextIsCorrected = 0x1;

//
static const unsigned int  FleksyMarginTouch = 3;

#endif /* defined(FleksyEngine_FLEnums_h) */
