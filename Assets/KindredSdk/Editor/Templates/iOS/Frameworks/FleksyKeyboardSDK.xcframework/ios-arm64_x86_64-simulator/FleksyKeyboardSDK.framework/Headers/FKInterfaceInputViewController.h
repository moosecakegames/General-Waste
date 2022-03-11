//
//  FKInterfaceInputViewController.h
//  FleksyKeyboardSDK
//
//  Created by Xevi on 03/07/2019.
//  Copyright © 2019 Thingthing. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "FKInputView.h"
#import "KeyboardConfiguration.h"
#import "KeyboardProperties.h"

NS_ASSUME_NONNULL_BEGIN

@class FKAppsGenericViewController;
@class FKAppsObject;
@protocol FKAppsGenericInteractionProtocol;

/**
 *  Data Collection protocol to implement in order to receive calls
 *  when we upload the data.
 *  Create an object extending this one and pass it via viewWillDissappearWithDataCollection(...)
 */
@protocol FKDataCollection <NSObject>

- (void) dataCollection:(NSString*) data;
- (void) dataCollectionFormatDict:(NSDictionary*) data;

@end

/**
 *  Interface to be implemented to receive any of these calls as a protocol
 */
@protocol FKInterfaceInputViewControllerDelegate <NSObject>

- (void) addKeyboardViewController:(UIViewController *) currentKeyboardVC;
- (void) addDisplayedViewController:(UIViewController<FleksyThemeableUI> *) displayVC;
- (void) addExtensionsViewController:(UIViewController*) extensionsVC;

- (void) triggerOpenApp;

- (void) dismissKeyboardButton;
- (void) changeKeyboardButton;

@optional

- (void) eventBus:(NSString*) event payload:(NSDictionary*) dictPayload;

// Implement those to receive data from the datacapture
// Only one of those would work at the same time
// In production environment use the object class FKDataCollection, as the data in this method
// comes from a different thread than the main one, at the deleting time.
- (void) dataCollection:(NSString*) data;

// Report Analytics is accumulative, which means, that accumulates all statistics for you
- (void) reportAnalytics:(NSDictionary*) data;
- (void) customMagicButton:(NSString*) element forAction:(int) action;

// Report Layout changes
- (void) onLayoutChanges:(NSDictionary*)dictLayout;

- (void) updateKeyboardAppsTextDocumentProxy:(nullable id<UITextDocumentProxy>) documentProxy;
- (FKAppsGenericViewController*) customKeyboadApp:(FKAppsObject*) object
                                     withDelegate:(id<FKAppsGenericInteractionProtocol>) delegate;

// Implement this method if you want to get all
// updates of the KeyboardProperties changes
- (void) contextPropertiesChanged:(KeyboardProperties*) properties;

@end

@class FKAppsObject;

/**
 * Main object to interact which owns the keyboard SDK
 */
@interface FKInterfaceInputViewController : NSObject

@property (nonatomic) FLKeyboardID keyboardID;

- (instancetype) initWith:(UIView*)inputView
                     view:(UIView*) view
        textDocumentProxy:(NSObject<UITextDocumentProxy>*) textDocumentProxy
          trailCollection:(UITraitCollection*) traitCollection
                 protocol:(NSObject<FKInterfaceInputViewControllerDelegate>*) protocol;

- (instancetype) initWith:(UIView*)inputView
        textDocumentProxy:(NSObject<UITextDocumentProxy>*) textDocumentProxy
          trailCollection:(UITraitCollection*) traitCollection
                 protocol:(NSObject<FKInterfaceInputViewControllerDelegate>*) protocol
            configuration:(KeyboardConfiguration*) config;

- (instancetype) initWith:(UIView*)inputView
        textDocumentProxy:(NSObject<UITextDocumentProxy>*) textDocumentProxy
          trailCollection:(UITraitCollection*) traitCollection
                 protocol:(NSObject<FKInterfaceInputViewControllerDelegate>*) protocol
                   output:(NSObject<FKDataCollection>*) output
            configuration:(KeyboardConfiguration*) config;

- (void) viewWillAppear;
- (void) viewDidAppear;
- (void) viewWillDisappear;

- (void)textWillChange:(nullable id<UITextInput>)textInput;
- (void)textDidChange:(nullable id<UITextInput>)textInput;

- (void)selectionWillChange:(nullable id<UITextInput>)textInput;
- (void)selectionDidChange:(nullable id<UITextInput>)textInput;

- (void) insertText:(NSString*) text;
- (void) replaceText:(NSString*) text inRange:(NSRange) range;
- (void) replaceAllTextWith:(NSString*) text;
- (void) deleteBackward;
- (void) deleteBackwardWord;

- (void) insertWordPrediction:(NSString*) prediction
                     withType:(FLWordPredictionType) type;

- (void) updateFlaggedWordsFile:(NSString*)filePath
                    forLanguage:(NSString*) language;

// This method is not going to be maitained, move to loadCollectionActions
- (void) enableCollectionActions:(BOOL) value
                  collectionText:(BOOL) text __deprecated;

- (void) loadCollectionActions:(CaptureConfiguration*) capture;
- (void) enableEncryptionWithKey:(NSString*) key;

- (void) subscribeEventBus:(NSArray*) arrayEvents;

- (UIView*) getPanelCustomTopbarView;

- (BOOL) reloadTheme:(NSDictionary*) theme;

- (BOOL) changeLanguageTo:(NSString *)languageCode layout:(NSString*) layout;

- (void) updateFullAccess:(BOOL) fullaccess;
- (void) updateKeyboardInsets:(UIEdgeInsets) insets;

- (void) addCustomActions:(NSDictionary*) dict;

// User Dictionary management
- (void) addWordUserDictionary:(NSString*) word;
- (NSArray*) listWordUserDictionary;
- (void) removeWordUserDictionary:(NSString*) word;
- (void) removeAllWordsUserDictionary;

// AutoLearn: delete the current learnings
- (void) deleteAutolearnDictionary;

// Reload Settings
- (void) reloadSettings;
// Reload Configuration to Emojis
- (void) reloadConfiguration:(EmojiConfiguration*) configuration;
// Reload Dynamic Configuration
- (void) reloadDynamicConfiguration:(KeyboardDynamicConfiguration*) configuration;

// Add extra Data to collected data
//
- (void) addCustomCollectedData:(NSDictionary*) dict;

// Data Collector Management
// This is intended to be used for Testing purposes
// You cannot relay on this method to get the data, as data depends on
// different process that could provoke inconsistency if you call this.
- (void) flushCollectedData __deprecated;

// DEBUG: This triggers all events at the end of a session
// This is intended to be used for Testing purposes and
// this will be the new method instead of flushCollectedData
- (void) debugFlushRestartTypingSession;

// DEUBG: This will help debugging the system to inject points
// that will be translated to keys, actions
- (void) debugSendPoint:(CGPoint)point endPoint:(CGPoint) endPoint diff:(NSTimeInterval)time;
- (void) debugSendPrediction:(CGPoint)point endPoint:(CGPoint) endPoint diff:(NSTimeInterval)time;

// KeyboardApp
- (NSArray*) availableKeyboardApp;
- (BOOL) registerKeyboardApp:(FKAppsObject*) keyboardApp;
- (void) unregisterKeyboardApp:(FKAppsObject*) keyboardApp;
- (void) displayKeyboardApp:(NSString*) keyboardAppName withTerm:(NSString*) term;
- (void) closeKeyboardApp;

@end

NS_ASSUME_NONNULL_END
