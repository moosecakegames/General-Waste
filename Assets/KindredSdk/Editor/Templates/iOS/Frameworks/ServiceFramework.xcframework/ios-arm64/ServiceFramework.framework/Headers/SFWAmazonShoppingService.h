//
//  SFWAmazonShoppingService.h
//  ServiceFramework
//
//  Created by Francesc Garcia on 03/11/2017.
//  Copyright © 2017 Thingthing LTD. All rights reserved.
//

#import <ServiceFramework/ServiceFramework.h>

// Error handling
static NSString* const SFWAmazonShoppingServiceErrorDomain = @"SFWAmazonShoppingServiceErrorDomain";
typedef NS_ENUM(NSInteger, SFWAmazonShoppingServiceErrors) {
  SFWAmazonShoppingServiceStatusError,
  SFWAmazonShoppingServiceNotFoundError,
  SFWAmazonShoppingServiceAuthError,
};

@interface SFWAmazonShoppingService : SFWService

@end
