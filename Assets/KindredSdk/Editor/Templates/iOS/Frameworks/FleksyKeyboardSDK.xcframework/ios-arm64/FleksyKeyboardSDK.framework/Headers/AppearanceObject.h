//
//  AppearanceObject.h
//  FleksyKeyboardSDK
//
//  Created by Xevi on 23/05/2020.
//  Copyright © 2020 Thingthing. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSUInteger, enumAppearance){
  enumAppearanceProportion_None,
  enumAppearanceProportion_Equal_Width,
  enumAppearanceProportion_Equal_Height,
};

/**
 Appearance container for describing the appearance of different objects
 */
@interface AppearanceObject : NSObject

- (instancetype) initWithView:(nullable UIView*) view
                        shape:(nullable UIBezierPath*) shape
                     position:(CGSize) origin
                         size:(CGSize) size
                   proportion:(enum enumAppearance) enumProportion;

@property (nonatomic, readonly) UIView* viewShape;
@property (nonatomic, readonly) UIBezierPath* pathShape;
@property (nonatomic, readonly) CGSize origin;
@property (nonatomic, readonly) CGSize size;
@property (nonatomic, readonly) enum enumAppearance proportion;

@end

NS_ASSUME_NONNULL_END
