//
//  FleksyUtility+Sounds.h
//  FleksyFramework
//
//  Created by David Mazza on 11/3/14.
//  Copyright (c) 2014 Thingthing Ltd. All rights reserved.
//

#ifndef FleksyiOS_FleksyUtility_Sounds_h
#define FleksyiOS_FleksyUtility_Sounds_h

#import "FleksyUtility.h"
#import "FleksyThemeableUI.h"

typedef enum {
  kSoundBackspace = 0,
  kSoundError,
  kSoundClick,
  kSoundUpDown,
  kNumSounds
} FleksySoundType;


@interface FleksyUtility (Sounds)

+ (void)initSoundsWithClient:(id<FleksyThemeableUI>)client;
+ (void)playTock;
+ (void)playFlickSound;
+ (void)playFlickUpdDownSound;
+ (void)playErrorSound;
+ (void)teardownSoundsForClient:(id<FleksyThemeableUI>)client;

@end

#endif
