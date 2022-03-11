//
//  SFWSpotifyService.h
//  ServiceFramework
//
//  Created by Francesc Garcia on 28/09/17.
//  Copyright © 2017 Thingthing LTD. All rights reserved.
//

#import <ServiceFramework/ServiceFramework.h>

#import "SFWRequest.h"

// Error handling
static NSString* const SFWSpotifyServiceErrorDomain = @"SFWSpotifyServiceErrorDomain";
typedef NS_ENUM(NSInteger, SFWSpotifyServiceErrors) {
  SFWSpotifyServiceStatusError,
  SFWSpotifyServiceNotFoundError,
  SFWSpotifyServiceAuthError,
};

@interface SFWSpotifyService : SFWService

@end
