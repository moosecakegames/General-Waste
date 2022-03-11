//
//  FleksyUtility+ControlOpenURLs.h
//  FleksyKit
//
//  Created by Xavier Farrarons on 29/09/2017.
//  Copyright © 2017 Thingthing, Ltd. All rights reserved.
//

#import "FleksyUtility.h"

/**
 Category to implement the openURL to open other apps from the keyboard
 */
@interface FleksyUtility (ControlOpenURLs)

/**
 Open a URL which might be another app

 @param url NSString with the app/URL that we want to open
 @param vc UIViewController from where we want to open it
 @return YES / NO
 */
+ (BOOL) openURL:(NSString*)url fromViewController:(id)vc;

@end
