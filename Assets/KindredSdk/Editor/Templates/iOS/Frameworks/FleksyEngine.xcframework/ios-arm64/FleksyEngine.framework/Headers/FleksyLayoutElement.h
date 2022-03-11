//
//  FleksyLayoutElement.h
//  FleksyEngine
//
//  Created by Ben Pious on 3/3/15.
//  Copyright (c) 2015 Thingthing, Ltd. All rights reserved.
//

//#import <FleksyEngine/FLEnums.h>
#import "FLEnums.h"
#import <Foundation/Foundation.h>
#import <CoreGraphics/CGGeometry.h>

#ifndef FleksyLayoutElement_h
#define FleksyLayoutElement_h

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wobjc-interface-ivars"
@interface FleksyLayoutElement : NSObject
{
  CGRect _frame;
  FLButtonType _type;
  NSString *_primaryLabel;
  BOOL _shouldRequestTemporaryLayout;
  BOOL _isForTemporaryLayout;
  BOOL _isTransparent;
  int _buttonID;
}
#pragma clang diagnostic pop
@property (nonatomic) CGRect frame;
@property (nonatomic) FLButtonType type;
@property (nonatomic, readonly) BOOL isKey;
@property (nonatomic, copy) NSString *primaryLabel;
@property (nonatomic) BOOL shouldRequestTemporaryLayout;
@property (nonatomic) int buttonID;
@property (nonatomic) BOOL isTransparent;
@property (nonatomic, readonly) CGPoint center;
@property (nonatomic, readonly) CGRect bounds;
@property (nonatomic) BOOL isForTemporaryLayout;

- (instancetype) initWithFrame:(CGRect)frame
                          type:(FLButtonType)type
                         label:(NSString *)primaryLabel
  shouldRequestTemporaryLayout:(BOOL)shouldRequestTemporaryLayout
                      buttonID:(int)buttonID
                 isTransparent:(BOOL)isTransparent;

@end

#endif
