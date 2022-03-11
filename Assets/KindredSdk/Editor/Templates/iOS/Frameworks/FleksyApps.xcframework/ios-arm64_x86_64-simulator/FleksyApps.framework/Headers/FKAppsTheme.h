//
//  FKAppsTheme.h
//  FleksyApps
//
//  Created by Xevi on 19/07/2020.
//  Copyright © 2020 Thingthing,Ltd. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

static NSString *const kAppsThemeDictKeyAppSelectedBackground = @"app_selected_background";
static NSString *const kAppsThemeDictKeyAppSelectedLetters = @"app_selected_letters";
static NSString *const kAppsThemeDictKeyAppSearchBarBackground = @"app_searchbar_background";
static NSString *const kAppsThemeDictKeyAppSearchBarLetters = @"app_searchbar_letters";
static NSString *const kAppsThemeDictKeyAppSearchBarCursor = @"app_searchbar_cursor";
static NSString *const kAppsThemeDictKeyAppFilterSelected = @"app_filter_selected";
static NSString *const kAppsThemeDictKeyAppFilterLetters = @"app_filter_letters";

@interface FKAppsTheme : NSObject

@property (nonatomic, readonly) BOOL isChameleon;
@property (nonatomic, readonly) NSString* fontName;
@property (nonatomic, readonly) NSArray* arrayBackgroundColors;

@property (nonatomic, readonly) UIColor* colorSelectedBackground;
@property (nonatomic, readonly) UIColor* colorSelectedLetters;
@property (nonatomic, readonly) UIColor* colorSearchBarBackground;
@property (nonatomic, readonly) UIColor* colorSearchBarLetters;
@property (nonatomic, readonly) UIColor* colorSearchBarCursor;
@property (nonatomic, readonly) UIColor* colorFilterSelected;
@property (nonatomic, readonly) UIColor* colorFilterLetters;


- (instancetype) initWithBackgroundColor:(NSArray*) arrayColors
                                fontName:(NSString*) fontName
                               chameleon:(BOOL) chameleon
                          withDictColors:(NSDictionary*) dictColors;

@end

NS_ASSUME_NONNULL_END
