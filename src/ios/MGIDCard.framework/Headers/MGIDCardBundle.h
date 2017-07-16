//
//  MGIDCardBundle.h
//  MGIDCard
//
//  Created by 张英堂 on 15/12/28.
//  Copyright © 2015年 megvii. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface MGIDCardBundle : NSObject

+ (NSString *)IDCardPathForResource:(NSString *)name ofType:(NSString *)type;

+ (NSString *)MGIDBundleString:(NSString *)key;

+ (UIImage *)IDCardImageWithName:(NSString *)name;

@end
