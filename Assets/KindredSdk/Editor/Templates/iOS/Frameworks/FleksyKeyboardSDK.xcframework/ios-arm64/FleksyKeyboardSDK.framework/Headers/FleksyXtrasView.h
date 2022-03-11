//
//  FleksyXtrasView.h
//  FleksyiOS
//
//  Created by Ben Pious on 1/27/16.
//  Copyright © 2016 Thingthing, Ltd. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "FleksyThemeableUI.h"
#import "FleksyExtensionsExpandable.h"

typedef NS_ENUM(NSUInteger, FleksyVOButtonDirection) {
  FleksyVOButtonDirectionLeft,
  FleksyVOButtonDirectionRight
};

@protocol FleksyXtrasViewDelegate <NSObject>

- (void)VOButtonPressedWithDirection:(FleksyVOButtonDirection)direction;
@property (nonatomic, readonly) NSUInteger enabledExtensionsCount;
@property (nonatomic, readonly) CGFloat heightForUnexpandedExtensionRow;

@end

@interface FleksyXtrasView : UIView <FleksyThemeableUI, FleksyExtensionsExpandable>

- (instancetype)initWithFrame:(CGRect)frame
                  isMinimized:(BOOL)isMinimized
                        theme:(FleksyTheme *)theme;

@property (nonatomic, readonly) BOOL isMinimized;
@property (nonatomic) BOOL isShowingVOButtons;
@property (nonatomic, strong) UIPageViewController *xtrasPageViewController;
@property (nonatomic, strong) UIViewController *xtrasContainer;
@property (nonatomic, weak) id<FleksyXtrasViewDelegate> delegate;
@property (nonatomic, readonly) NSUInteger enabledExtensionsCount;
@property (nonatomic, readonly) CGFloat desiredProportionalHeight;
@property (nonatomic, readonly) CGFloat proportionalUnexpandedHeight;

@end
