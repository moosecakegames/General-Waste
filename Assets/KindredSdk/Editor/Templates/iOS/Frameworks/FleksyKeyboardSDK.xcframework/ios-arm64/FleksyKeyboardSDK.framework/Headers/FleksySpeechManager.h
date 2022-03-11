//
//  FleksyUtility+Speech.h
//  FleksyFramework
//
//  Created by David Mazza on 11/3/14.
//  Copyright (c) 2014 Syntellia Inc. All rights reserved.
//

#ifndef FleksySpeechManager_h
#define FleksySpeechManager_h

#import "FleksyUtility.h"
#import "FleksyEngine/FLEnums.h"
#import <AVFoundation/AVFoundation.h>

/**
 Manages the playing of VO or voice feedback speech.
 */
@interface FleksySpeechManager : NSObject

@property (nonatomic) AVSpeechSynthesizer *speechEngine;
@property (nonatomic, readonly) BOOL shouldSpeak;

- (void)announceKeyboardForID:(FLKeyboardID)keyboardID;
- (NSString *)announcementForKeyboardID:(FLKeyboardID)keyboardID;
- (void)recreateSpeechEngine;
- (NSString*)getPhoneticStringFor:(NSString*) string;
- (void)performAudioFeedbackFromString:(NSString*) string;
- (void)stopSpeaking;
- (void)speakNoMoreTextToDelete;
- (void)speakDictionaryChangedEvent:(FLDictionaryChangeEvent)event
                               word:(NSString *)word;
- (void)overrideAppleVoiceFeedBackNotificationWithString:(NSString *)annoucement;

@end


#endif // FleksySpeechManager_h
