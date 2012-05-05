//
//  Filters.h
//  Cngram
//
//  Created by Chen Changneng on 12-4-22.
//  Copyright (c) 2012年 __MyCompanyName__. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface Filters : NSObject
- (NSInteger) count;
- (NSString *) nameForIndex: (NSInteger) index;
- (NSString *) methodForIndex: (NSInteger) index;
- (NSString *) iconForIndex: (NSInteger) index;

@end
