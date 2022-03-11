//
//  SFWYoutubeService.h
//  ServiceFramework
//
//  Created by Francesc Garcia on 21/09/17.
//  Copyright © 2017 Thingthing LTD. All rights reserved.
//

#import <ServiceFramework/ServiceFramework.h>

#import "SFWRequest.h"

// Error handling
static NSString* const SFWYoutubeServiceErrorDomain = @"SFWYoutubeServiceErrorDomain";
typedef NS_ENUM(NSInteger, SFWYoutubeServiceErrors) {
  SFWYoutubeServiceStatusError,
};

@interface SFWYoutubeService : SFWService

-(SFWRequest*) youtubeSearch:(NSString*)query forLocale:(NSString*)locale completion:(SFWServiceResponseBlock) responseBlock;
-(SFWRequest*) youtubeSearch:(NSString*)query withCategory:(NSString*)category forLocale:(NSString*)locale completion:(SFWServiceResponseBlock) responseBlock;

@end
