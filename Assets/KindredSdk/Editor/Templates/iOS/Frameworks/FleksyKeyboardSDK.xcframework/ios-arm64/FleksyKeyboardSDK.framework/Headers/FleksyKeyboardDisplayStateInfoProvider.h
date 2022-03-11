//
//  FleksyKeyboardDisplayStateInfoProvider.h
//  FleksyiOS
//
//  Created by Ben Pious on 1/25/16.
//  Copyright © 2016 Thingthing, Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "FleksyLayoutElement+KeypadUtilities.h"

@protocol FleksyKeyboardDisplayStateInfoProvider <NSObject>

@property (nonatomic, readonly) NSString *magicButtonIcon;
@property (nonatomic, readonly) NSString *enterButtonIcon;

@end
