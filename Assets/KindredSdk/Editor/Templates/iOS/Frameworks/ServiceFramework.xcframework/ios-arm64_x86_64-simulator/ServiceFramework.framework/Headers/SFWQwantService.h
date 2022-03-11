//
//  SFWQwantService.h
//  ServiceFramework
//
//  Created by Francesc Garcia on 28/08/17.
//  Copyright © 2017 Thingthing LTD. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "SFWService.h"
#import "SFWRequest.h"

// Error handling
static NSString* const SFWQwantServiceErrorDomain = @"SFWQwantServiceErrorDomain";
typedef NS_ENUM(NSInteger, SFWQwantServiceErrors) {
  SFWQwantServiceStatusError,
};

@interface SFWQwantService : SFWService

-(SFWRequest*) autocompleteQuery:(NSString*)query completion:(SFWServiceResponseBlock) responseBlock;

-(SFWRequest*) webSearch:(NSString*)query forLocale:(NSString*)locale completion:(SFWServiceResponseBlock) responseBlock;
-(SFWRequest*) imageSearch:(NSString*)query forLocale:(NSString*)locale completion:(SFWServiceResponseBlock) responseBlock;
-(SFWRequest*) videoSearch:(NSString*)query forLocale:(NSString*)locale completion:(SFWServiceResponseBlock) responseBlock;
-(SFWRequest*) newsSearch:(NSString*)query forLocale:(NSString*)locale completion:(SFWServiceResponseBlock) responseBlock;
-(SFWRequest*) shoppingSearch:(NSString*)query forLocale:(NSString*)locale completion:(SFWServiceResponseBlock) responseBlock;
-(SFWRequest*) socialSearch:(NSString*)query forLocale:(NSString*)locale completion:(SFWServiceResponseBlock) responseBlock;
-(SFWRequest*) autocompleteSearch:(NSString*)query forLocale:(NSString*)locale completion:(SFWServiceResponseBlock) responseBlock;

@end
