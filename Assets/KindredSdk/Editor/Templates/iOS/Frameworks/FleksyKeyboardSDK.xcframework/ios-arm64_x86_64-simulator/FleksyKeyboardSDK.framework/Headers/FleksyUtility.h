//
//  FleksyUtility.h
//  FleksyFramework
//
//  Created by Tusi Chowdhury on 2014-10-22.
//  Copyright (c) 2014 Thingthing, Ltd. All rights reserved.
//

#ifndef FleksyiOS_FleksyUtility_h
#define FleksyiOS_FleksyUtility_h

#import <Foundation/Foundation.h>
/**
 * A base class for various Utility catergories. Only global utility methods should live in the base class
 */
@interface FleksyUtility : NSObject

/**
 @returns if we are in the keyboard extension or not
 */
+ (BOOL)isExtension;


/**
 Get the default identifier of the app. - This uses the IDFA if it's possible to get it, if not, the device ID.

 @return NSString with the value of the identifier
 */
+ (NSString *)defaultIdentifier;

@end

#endif //  FleksyiOS_FleksyUtility_h
