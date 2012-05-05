//
//  Filters.m
//  Cngram
//
//  Created by Chen Changneng on 12-4-22.
//  Copyright (c) 2012年 __MyCompanyName__. All rights reserved.
//

#import "Filters.h"
#import "SBJson.h"

@interface Filters () {
    NSArray * _object;
}
@end

@implementation Filters
- (id) init {
    self = [super init];
    if (self) {
        NSString * filePath = [[NSBundle mainBundle] pathForResource:@"filters" ofType:@"json"];  
        NSString * jsonString = [NSString stringWithContentsOfFile:filePath encoding:NSUTF8StringEncoding error:nil];
        _object = [[[SBJsonParser alloc] init] objectWithString:jsonString];
    }
    return self;
}

- (NSInteger) count {
    return _object.count;
}

- (NSString *) nameForIndex:(NSInteger)index {
    return [[_object objectAtIndex:index] valueForKey:@"filterName"];
}

- (NSString *) methodForIndex:(NSInteger) index {
    return [[_object objectAtIndex:index] valueForKey:@"filterAction"];
}

- (NSString *) iconForIndex:(NSInteger) index {
    return [[_object objectAtIndex:index] valueForKey:@"previewImage"];
}


@end
