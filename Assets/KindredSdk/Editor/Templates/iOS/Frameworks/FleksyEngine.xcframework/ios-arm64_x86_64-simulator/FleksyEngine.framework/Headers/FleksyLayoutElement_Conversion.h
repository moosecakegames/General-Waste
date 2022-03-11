//
//  FleksyLayoutElement_Private.h
//  FleksyEngine
//
//  Created by Ben Pious on 3/3/15.
//  Copyright (c) 2015 Thingthing, Ltd. All rights reserved.
//

#ifndef FleksyEngine_FleksyLayoutElement_Private_h
#define FleksyEngine_FleksyLayoutElement_Private_h

#import "FleksyLayoutElement.h"
#import "FLButton.h"

@interface FleksyLayoutElement (Conversion)

- (instancetype)initWithFLButton:(const FLButton &)button;

@end

#endif
