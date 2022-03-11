//
//  SFWPublicS3Service.h
//  ServiceFramework
//
//  Created by Francesc Garcia on 05/12/2017.
//  Copyright © 2017 Thingthing LTD. All rights reserved.
//

#import <ServiceFramework/ServiceFramework.h>

// Error handling
static NSString* const SFWPublicS3ServiceErrorDomain = @"SFWAmazonShoppingServiceErrorDomain";
typedef NS_ENUM(NSInteger, SFWPublicS3ServiceErrorDomainErrors) {
  SFWPublicS3ServiceErrorDomainStatusError,
  SFWPublicS3ServiceErrorDomainNotFoundError,
  SFWPublicS3ServiceErrorDomainAuthError,
};

@interface SFWPublicS3Service : SFWService

@end
