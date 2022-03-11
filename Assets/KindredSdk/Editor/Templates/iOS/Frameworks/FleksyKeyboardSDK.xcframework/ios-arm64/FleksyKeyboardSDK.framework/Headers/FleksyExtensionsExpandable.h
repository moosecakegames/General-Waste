//
//  FleksyExtensionsExpandableView.h
//  FleksyiOS
//
//  Created by Ben Pious on 1/28/16.
//  Copyright © 2016 Thingthing, Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef NS_ENUM(NSUInteger, FleksyExtensionsViewHeightState) {
  FleksyExtensionsViewHeightStateMinimized,
  FleksyExtensionsViewHeightStateNormal,
  FleksyExtensionsViewHeightStateExtended,
};

@protocol FleksyExtensionsExpandable <NSObject>

@property (nonatomic) FleksyExtensionsViewHeightState heightState;

@end
