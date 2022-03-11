//
//  FKAppsObject.h
//  FleksyiOS
//
//  Created by Xavier Farrarons on 30/08/2017.
//  Copyright © 2017 Thingthing, Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>

// This is temporal - We need to make this generic -
typedef NS_ENUM(NSUInteger, enumAppsValue){
  enumAppsValue_Qwant     = 0,
  enumAppsValue_Gifs      = 1,
  enumAppsValue_Stickers  = 2,
  enumAppsValue_Memes     = 3,
  enumAppsValue_Yelp      = 4,
  enumAppsValue_Spotify   = 5,
  enumAppsValue_Youtube   = 6,
  enumAppsValue_News      = 7,
  enumAppsValue_Shopping  = 8,
  enumAppsValue_Highlights= 9,
  enumAppsValue_Gift      =10,
  enumAppsValue_Vlipsy    =11,
  enumAppsValue_Custom    = 900,
  enumAppsValue_None      = 1000,
};


@interface FKAppsFilterObject : NSObject

@property (nonatomic, readonly, nonnull) NSString* nameFilter;
@property (nonatomic, readonly, nonnull) NSString* identifierFilter;
@property (nonatomic, nullable) NSString* imageIcon;

- (instancetype _Nonnull) initWithName:(NSString* _Nonnull) name withIdentifier:(NSString* _Nonnull) identifier;

@end

//
// AppsObject for the Element that
// we could add at the begining of the results from Network
//
static NSString* _Nonnull const AppsObjectWidth = @"width";
static NSString* _Nonnull const AppsObjectHeight = @"height";
static NSString* _Nonnull const AppsObjectImageURL = @"imageURL";

/**
 *  Simple object for grouping all Configuration elements and methods for one of the apps
 */
@interface FKAppsObject : NSObject

@property (nonatomic, readonly, nonnull) NSString* nameApp;
@property (nonatomic, readonly, nonnull) NSString* nameImage;
@property (nonatomic, readonly, nonnull) NSString* nameImageSearchBar;
@property (nonatomic, readonly, nonnull) NSString* apiKey;
@property (nonatomic, readonly, nonnull) NSArray* arrayFilters;
@property (nonatomic, readonly, nonnull) NSDictionary* dictConfig;
@property (nonatomic, readonly, nonnull) NSDictionary* dictElement;
@property (nonatomic, readonly) enum enumAppsValue appValue;

- (instancetype _Nonnull) initWithAppName:(NSString*_Nonnull) name
                                withImage:(nullable NSString*) nameImage
                       withImageSearchBar:(nullable NSString*) nameImageSearchBar
                             withAppValue:(enum enumAppsValue) value
                               withApiKey:(NSString*_Nonnull) apiKey
                              withFilters:(nullable NSArray*)  filters
                        withConfiguration:(nullable NSDictionary*) dict
                        withStaticElement:(nullable NSDictionary*) dictElement;

- (instancetype _Nonnull) initWithAppName:(NSString*_Nonnull) name
                       withImage:(NSString*_Nonnull) nameImage
              withImageSearchBar:(NSString*_Nonnull) nameImageSearchBar
                    withAppValue:(enum enumAppsValue) value
                      withApiKey:(NSString*_Nonnull) apiKey
                     withFilters:(nullable NSArray*)  filters;

- (instancetype _Nonnull ) initWithAppName:(NSString*_Nonnull) name
                       withImage:(NSString*_Nonnull) nameImage
              withImageSearchBar:(NSString*_Nonnull) nameImageSearchBar
                    withAppValue:(enum enumAppsValue) value
                     withFilters:(nullable NSArray*) filters;

- (instancetype _Nonnull) initWithAppName:(NSString*_Nonnull) name
                             withAppValue:(enum enumAppsValue) value
                               withApiKey:(NSString*_Nonnull) apiKey
                        withConfiguration:(nullable NSDictionary*) dict
                        withStaticElement:(nullable NSDictionary*) dictElement;

- (instancetype _Nonnull) initWithAppName:(NSString*_Nonnull) name
                             withAppValue:(enum enumAppsValue) value
                               withApiKey:(NSString*_Nonnull) apiKey
                              withFilters:(nullable NSArray*) filters
                        withConfiguration:(nullable NSDictionary*) dict
                        withStaticElement:(nullable NSDictionary*) dictElement;

- (instancetype _Nonnull) initWithAppName:(NSString*_Nonnull) name
                             withAppValue:(enum enumAppsValue) value
                               withApiKey:(NSString*_Nonnull) apiKey
                        withConfiguration:(nullable NSDictionary*) dict;

- (instancetype _Nonnull) initWithAppName:(NSString*_Nonnull) name
                    withAppValue:(enum enumAppsValue) value
                      withApiKey:(NSString*_Nonnull) apiKey;

- (instancetype _Nonnull) initWithAppName:(NSString*_Nonnull) name
                    withAppValue:(enum enumAppsValue) value;

@end
