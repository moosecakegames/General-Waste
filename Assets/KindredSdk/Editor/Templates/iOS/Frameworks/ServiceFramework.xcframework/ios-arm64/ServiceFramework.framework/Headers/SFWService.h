//
//  SFWService.h
//  
//
//  Created by Francesc Garcia on 29/08/2017.
//
//

#import <Foundation/Foundation.h>

#ifndef SFWService_h
#define SFWService_h


// Error handling
static NSString* const SFWServiceErrorDomain = @"SFWServiceErrorDomain";
typedef NS_ENUM(NSInteger, SWFServiceErrors) {
  SWFServiceErrorNotImplemented,
  SWFServiceErrorFilterNotFound,
  SWFServiceErrorRequestFailed,
};

@class SFWRequest;

/**
 Generic Service item (common to all services)
 */
@interface SFWServiceItem : NSObject
@property NSString* url;
@property NSString* title;
@property NSString* subtitle;
@property NSString* category;
@property NSString* descr;
@property NSString* detail1;
@property NSString* detail2;
@property NSString* imageUrl;
@property NSString* thumbnailUrl;
@property NSString* priceLocale;
@property NSString* identifier;
@property long timestamp;
@property float rating;
@property int level;
@property int duration;  // In seconds
@property int thumbnailWidth;
@property int thumbnailHeight;
@property int distance;

-(id) initWithItem:(SFWServiceItem*)source;
@end


/**
 Service response complete block

 @param array Array with contents of the response
 @param error NSError with request errors
 */
typedef void (^SFWServiceResponseBlock)(NSArray<SFWServiceItem*>* array, NSError* error);

typedef void (^SFWServiceDetailsResponseBlock)(SFWServiceItem* item, NSError* error);

typedef void (^SFWDataServiceResponseBlock)(NSData* data, NSError* error);

typedef void (^SFWFiltersServiceResponseBlock)(NSArray<NSDictionary*>* filters, NSError* error);

typedef void (^SFWServiceProgressBlock)(float progress);

typedef void (^SFWSimpleServiceResponseBlock)(NSError* error);

@class SFWNetworkAPI;

/**
 @brief Service framework common interface.
 
 SFWService can't be used directly. It's the base class for all services.
 
 The way to use any subclass is to get the list of available filters and
 use those identifiers to call contentsFromFilter.
 
 contentsFromFilter will return results in a block that receives an NSArray of SFWServiceItems* and an error
 
 Some services implement autocompleteQuery that autocompletes partial queries for specific filters.
 */
@interface SFWService : NSObject

/**
 Internal network api
 */
@property SFWNetworkAPI* api;

/**
 List of filters supported by the service
 
 Each filter is a dictionary that contains:
 'id': Filter identifier (filter parameter for contentsFromFilter call)
 'label': Filter label
 'icon' (optional) : Image to put as filter

 */
@property (readonly) NSArray<NSDictionary*>* filters;

/**
 Subclasses need to map from filter names to internal selectors.
 The key is the name of the filter and the value an instance of a custom block to translate parameters
 TODO: Make it protected
 */
@property NSMutableArray<NSDictionary*>* filterCalls;

/**
 General service configuration
 @brief NSDictionary with service configuration parameters dependant of each service
 TODO: Make it protected
 */
@property NSDictionary<NSString*, NSString*>* config;

/**
 List of filters supported by the service (async call)
 
 Each filter is a dictionary that contains:
 'id': Filter identifier (filter parameter for contentsFromFilter call)
 'label': Filter label
 'icon' (optional) : Image to put as filter
 */
-(SFWRequest*) filtersWithCompletion:(SFWFiltersServiceResponseBlock) responseBlock;

/**
 Returns the contents of the filter making an optional search query.

 @param filter Filter id (one of the "id" values of the filters property)
 @param query Search query
 @param responseBlock SFWServiceResponseBlock that will be called when the call completes
 @return SFWRequest that will be executed against the network (and can be cancelled, returning a 'cancelled' error in the responseBlock)
 */
-(SFWRequest*) contentsFromFilter:(NSString*)filter withQuery:(NSString*)query completion:(SFWServiceResponseBlock) responseBlock;

/**
 Returns the contents of details of the itemId for the current category
 
 @param itemId NSString with an Identifier value to make a request to obtain the details
 @param category NSString with the category of the details
 @param responseBlock SFWserviceDetailsReponseBlock with the item detailes
 @return SFWRequest that will be executed against the network (it can be cancelled)
 */
-(SFWRequest*) contentDetails:(NSString*)itemId forCategory:(NSString*) category completion:(SFWServiceDetailsResponseBlock) responseBlock;

/**
 Returns a list of autocompletions for the specified partial query

 @param query Partial search query
 @param responseBlock SFWServiceResponseBlock that will be called when the call completes
 @return SFWRequest that will be executed against the network (and can be cancelled, returning a 'cancelled' error in the responseBlock)
 */
-(SFWRequest*) autocompleteQuery:(NSString*)query completion:(SFWServiceResponseBlock) responseBlock;


/**
 Returns the content of an url in raw format (binary)

 @param url           Absolute url to download from
 @param responseBlock SFWDataServiceResponseBlock that will be called when the download completes (or an error arises)
 @param progressBlock SFWServiceProgressBlock that will be called as the download progresses (% 0..100)

 @return SFWRequest that will be executed against the network (and can be cancelled, returning a 'cancelled' error in the responseBlock)
 */
-(SFWRequest*) downloadUrlData:(NSString*)url completion:(SFWDataServiceResponseBlock) responseBlock progress:(SFWServiceProgressBlock) progressBlock;


-(SFWRequest*) registerShareOfItem:(NSString*)itemId attribution:(NSString*)tag completion:(SFWSimpleServiceResponseBlock) responseBlock;

/**
 Sends a POST with the information passed as a NSDictionary to track something related with the service

 @param dictionary NSDictionary using the format of the service to track info
 @param responseBlock SFWSimpleServiceResponseBlock to answer if the request had succees or not
 @return SFWRequest that will be executed against the network
 */
-(SFWRequest*) trackEvent:(NSDictionary*) dictionary completion:(SFWSimpleServiceResponseBlock) responseBlock;

@end

#endif
