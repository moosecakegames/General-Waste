//
//  FleksyFontProvider.h
//  FleksyiOS
//
//  Created by Ben Pious on 11/11/15.
//  Copyright © 2015 Thingthing, Ltd. All rights reserved.
//

#ifndef FleksyFontProvider_h
#define FleksyFontProvider_h

#import <UIKit/UIKit.h>

@protocol FleksyFontProvider <NSObject>

@property (nonatomic, readonly) UIFont *keypadFont;
@property (nonatomic, readonly) UIFont *extensionKeysFont;

@end

#endif // _FleksyFontProvider_h_
