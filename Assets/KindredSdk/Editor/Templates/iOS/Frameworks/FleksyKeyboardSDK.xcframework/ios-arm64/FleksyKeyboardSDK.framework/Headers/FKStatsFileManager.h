//
//  FKStatsFileManager.h
//  FleksyKit
//
//  Created by Xavier Farrarons Clusella on 05/04/2018.
//  Copyright © 2018 Thingthing, Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 *  In charge of managing the lenght of the stats file, what we store and how
 *  - to make it easy to upload
 */
@interface FKStatsFileManager : NSObject

+ (NSString*) getCurrentFolder;
+ (void) storeGenericContents:(NSString*) contents withKey:(NSString*) key;

@end
