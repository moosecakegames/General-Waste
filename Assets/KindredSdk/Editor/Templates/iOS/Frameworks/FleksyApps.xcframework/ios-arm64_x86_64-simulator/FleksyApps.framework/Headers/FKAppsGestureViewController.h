//
//  FKAppsGestureViewController.h
//  FleksyiOS
//
//  Created by Xavier Farrarons on 01/09/2017.
//  Copyright © 2017 Thingthing, Ltd. All rights reserved.
//

#import <UIKit/UIKit.h>

/**
 Protocol to notify about all different gestures in the view
 */
@protocol FKAppsGestureProtocol <NSObject>

- (void) gestureMovingBack:(CGFloat) positionX;
- (void) gestureBackWithTime:(CGFloat) duration;
- (void) gestureResetWithTime:(CGFloat) duration;

@end

/**
 Controller for the control of gestures swipe back and all different gesture to move between 
 different UIViewControllers
 We only allow to keep track of one collectionview scroll - this is configurable...but right this is the way.
 */
@interface FKAppsGestureViewController : UIViewController <UIScrollViewDelegate>

/**
 *  if this is enabled or not --
 */
@property (nonatomic) BOOL boolEnableBackGesture;

- (instancetype) init NS_DESIGNATED_INITIALIZER;

/**
 Configure the gesture controller to know which type of collectionview we need to interact with.

 @param collectionView UICollectionView used to stop it when we scroll more than a size...
 @param protocol FKAppsGestureProtocol to notify aboutthe moving back
 */
- (void) configureWithCollectionView:(UICollectionView*) collectionView
                         andProtocol:(id<FKAppsGestureProtocol>) protocol;

@end
