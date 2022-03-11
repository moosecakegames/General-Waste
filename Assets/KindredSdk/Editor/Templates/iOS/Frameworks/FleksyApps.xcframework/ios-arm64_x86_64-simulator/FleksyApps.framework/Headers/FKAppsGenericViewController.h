//
//  FKAppsAbstractViewController.h
//  FleksyiOS
//
//  Created by Xavier Farrarons on 04/09/2017.
//  Copyright © 2017 Thingthing, Ltd. All rights reserved.
//

#import "FKAppsGestureViewController.h"

//
// This protocol is used from outside in order to call only the public methods
//
@protocol FKAppsGenericProtocol <NSObject>

@optional
- (void) searchWithText:(NSString*) text;
- (void) cleanMemory;

@end

//
// Protocol to interact with the user, sending notifications to the keyboard
// and sharing text directly to the textfield
//
@protocol FKAppsGenericInteractionProtocol <NSObject>

/**
 Share text
 
 @param text NSString with the text to share
 */
- (void) interactionShareText:(NSString*) text;

/**
 Notify the user about actions that we're taking
 
 @param text NSString with the text to print
 @param textBold NSString with the text to print
 */
- (void) interactionNotifyUserWithText:(NSString*) text andBoldText:(NSString*) textBold;


@end

//
// Protocol used internally to call parent implemented methods when people presses buttons
//
@protocol FKAppsGenericInternProtocol <NSObject>

@optional
- (void) buttonFromBackgroundWithIdentifier:(NSUInteger) identifier;

@end


@class FKAppsObject;

/**
 Generic interface for adding the main methods used in all different types of controllers
 
 */
@interface FKAppsGenericViewController : FKAppsGestureViewController <FKAppsGenericProtocol, FKAppsGenericInternProtocol>

- (instancetype) init NS_DESIGNATED_INITIALIZER;

/**
 Make initial configuration of the generic to adapt to the type of parent that we have.
 It requires a main CollectionView and an app to be configured.

 @param collectionView UICollectionView used to display messages
 @param view UIView parent of the collectionview
 @param object FKAppsObject with all the information regarding the app that we're using
 */
- (void) configureWithCollectionView:(UICollectionView *)collectionView onView:(UIView*) view forDisplayApp:(FKAppsObject*) object;


/**
 Action to interact - Show No Results information to the user
 */
- (void) showNoResults;

/**
 Action to show to the user the Error -
 
 @param error NSError used to show the text Error - it could be a generic Error.
 */
- (void) showTextError:(NSError*) error;

/**
 Action to show a background information for the location permission

 @param identifier NSUInteger of the button to click
 */
- (void) showLocationPermissionWithId:(NSUInteger) identifier;

/**
 Action to show a background information for the location permission error!

 @param identifier NSUInteger of the button to access the location permission ---- TODO
 */
- (void) showLocationNoPermissionWithId:(NSUInteger) identifier;

/**
 It removes any top view added that we don't need
 */
- (void) removeGenericTopViews;

@end
