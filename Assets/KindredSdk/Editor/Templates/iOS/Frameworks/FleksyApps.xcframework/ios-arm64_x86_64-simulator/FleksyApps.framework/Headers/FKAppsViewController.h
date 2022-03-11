//
//  FKAppsViewController.h
//  FleksyiOS
//
//  Created by Xavier Farrarons on 23/08/2017.
//  Copyright © 2017 Thingthing, Ltd. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "FKAppsConfiguration.h"

@class FKAppsObject;
@class FKAppsGenericViewController;
@protocol FKAppsGenericInteractionProtocol;

/**
 Protocol designed to communicate FleksyApps with InputViewController -
 */
@protocol FKAppsViewControllerProtocol <UITextInputDelegate>

- (void) cancelApps;

- (void) openSettingsForApp;

- (void) openURL:(NSString*) url;

// Actions related to Engine, insert, delete and update textDocumentProxy
- (void) handleAppsInsertText:(NSString*) text;
- (void) handleAppsBackspace:(float) length;
- (void) handleAppsUpdateTextDocumentProxy:(id<UITextDocumentProxy>) keyInput;

// Custom KeyboardApp 
- (FKAppsGenericViewController*) createCustomKeyboadApp:(FKAppsObject*) object
                                           withDelegate:(id<FKAppsGenericInteractionProtocol>) delegate;
@end


@class FleksyPredictionObject;


/**
 Controller to handle everything that will happen inside the View of FleksyApps
 */
@interface FKAppsViewController : UIViewController

- (instancetype) initWithProtocol:(id<FKAppsViewControllerProtocol>) protocol
                withConfiguration:(FKAppsConfiguration*) configuration;

- (void) startWithConfigShift:(BOOL) isShifted;
- (void) closeAppsGesture;

- (void) openHighlights:(NSArray*) services withSearchString:(NSString*) term;

- (BOOL) isAbleToBeDismissedGesture;

- (void) displayAppWithName:(NSString*)app andSearchString:(NSString*)searchString;
- (void) displayAppforNSPHighlight:(FleksyPredictionObject *) highlight;
- (void) closeApps;
- (void) cleanUp;

- (void) updateTheme:(FKAppsTheme*) theme;

@end
