//
//  FleksyJapaneseKeyboardStatusProvider.h
//  FleksyiOS
//
//  Created by Ben Pious on 1/6/16.
//  Copyright © 2016 Thingthing, Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>

@protocol FleksyJapaneseKeyboardStatusProvider <NSObject>

@property (nonatomic, readonly) BOOL isJapanese;
@property (nonatomic, readonly) BOOL isFlickKeyboard;

@end
