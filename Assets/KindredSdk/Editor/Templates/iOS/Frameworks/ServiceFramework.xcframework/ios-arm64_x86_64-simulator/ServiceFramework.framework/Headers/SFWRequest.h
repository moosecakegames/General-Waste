//
//  SFWRequest.h
//  ServiceFramework
//
//  Created by Francesc Garcia on 28/08/17.
//  Copyright © 2017 Thingthing LTD. All rights reserved.
//

#import <Foundation/Foundation.h>

// Error handling
static NSString* const SFWRequestErrorDomain = @"SFWRequestErrorDomain";
typedef NS_ENUM(NSInteger, SWFRequestError) {
  SFWRequestTimeoutError,
  SFWRequestDeserializationError,
  SFWRequestNetworkError,
  SFWRequestCancelledError
};

@class SFWResponse;

/**
 Block to be called by async request calls

 @param response SFWResponse with the contents of the http call
 */
typedef void (^SFWResponseBlock)(SFWResponse* response);


/**
 Block to be called by request as data is coming

 @param progress % of the data received
 */
typedef void (^SFWProgressBlock)(float progress);


typedef NSString* SFWHTTPMethod;

// Available http methods
static const SFWHTTPMethod SFW_HTTP_GET = @"GET";
static const SFWHTTPMethod SFW_HTTP_POST = @"POST";
static const SFWHTTPMethod SFW_HTTP_PUT = @"PUT";
static const SFWHTTPMethod SFW_HTTP_DELETE = @"DELETE";
static const SFWHTTPMethod SFW_HTTP_HEAD = @"HEAD";
static const SFWHTTPMethod SFW_HTTP_OPTIONS = @"OPTIONS";

/**
 Network request
 */
@interface SFWRequest : NSObject

/**
 Request url
 */
@property NSString* url;


/**
 Request path part of the url
 */
@property NSString* path;


/**
 Raw contents of the body
 */
@property NSData* body;


/**
 Method to be used to make the http call
 */
@property SFWHTTPMethod method;

/**
 Cancels the request. Will return an error in the completion block linked to it
 */
-(void) cancel;


/**
 Adds a query parameter to the request url. It will be encoded internally

 @param param Name of the parameter
 @param value Value of the parameter
 */
-(void) addQueryParam:(NSString*)param withValue:(NSString*)value;


/**
 Adds an http header to the request

 @param header Header name
 @param value Value of the header
 */
-(void) addHeader:(NSString*)header withValue:(NSString*)value;


/**
 Serializes the object body as json data

 @param body Object to be serialized
 @return NSError with possible JSON serialization errors
 */
-(NSError*) setJsonBody:(id) body;


/**
 Sync call to return json results

 @return SFWResponse with the server response deserialized as json
 */
-(SFWResponse*) asJson;

/**
 Async call to return json results

 @param response An SFWResponseBlock that will be called when the request completes
 */
-(void) asJsonAsync:(SFWResponseBlock)response;

/**
 Async call to return xml results
 
 @param response An SFWResponseBlock that will be called when the request completes
 */
-(void) asXmlAsync:(SFWResponseBlock)response;

/**
 Sync call to return raw string results
 
 @return SFWResponse with the server response deserialized as an UTF-8 string
 */
-(SFWResponse*) asString;

/**
 Async call to return raw string results
 
 @param response An SFWResponseBlock that will be called when the request completes
 */
-(void) asStringAsync:(SFWResponseBlock)response;

/**
 Async call to return binary results
 
 @param responseBlock An SFWResponseBlock that will be called when the request completes
 @param progress An SFWProgressBlock that will be called as the download progresses
 */
-(void) asBinaryAsync:(SFWResponseBlock)responseBlock withProgress:(SFWProgressBlock) progress;

/**
 Controls if request use the cache (and doesn't use network at all if the cache is populated, if not go to the network) or use the protocol cache policy

 @param prioritizeCache YES for use first the cache then network, NO for use the protocol cache policy
 */
-(void) prioritizeCache:(BOOL)prioritizeCache;

/**
 Http request headers

 @return Request headers as NSDictionary
 */
-(NSDictionary*) headers;

@end
