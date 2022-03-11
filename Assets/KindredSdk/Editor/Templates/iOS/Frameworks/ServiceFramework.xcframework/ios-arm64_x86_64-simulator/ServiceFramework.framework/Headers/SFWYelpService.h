//
//  SFWYelpService.h
//  ServiceFramework
//
//  Created by Francesc Garcia on 07/09/17.
//  Copyright © 2017 Thingthing LTD. All rights reserved.
//

#import <ServiceFramework/ServiceFramework.h>

#import "SFWRequest.h"

// Error handling
static NSString* const SFWYelpServiceErrorDomain = @"SFWYelpServiceErrorDomain";
typedef NS_ENUM(NSInteger, SFWYelpServiceErrors) {
  SFWYelpServiceStatusError,
  SFWYelpServiceAuthError,
};

@interface SFWYelpService : SFWService

-(SFWRequest*) autocompleteQuery:(NSString*)query completion:(SFWServiceResponseBlock) responseBlock;

-(SFWRequest*) yelpSearch:(NSString*)query forLocale:(NSString*)locale completion:(SFWServiceResponseBlock) responseBlock;
-(SFWRequest*) yelpSearch:(NSString*)query withCategory:(NSString*)category forLocale:(NSString*)locale completion:(SFWServiceResponseBlock) responseBlock;

@end
