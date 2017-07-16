//
//  LicenseManager.h
//  liveness
//
//  Created by 杨沐 on 15/12/23.
//  Copyright (c) 2015年 megvii. All rights reserved.
//

#import <Foundation/Foundation.h>

@protocol LicenseProtocolDelegate <NSObject>

@required
+(NSString*)getContextWithUUID: (NSString*)uuid;
/* <String, NSDate>, key: sdk_version, value: is_success flag */
+(NSDictionary*)setLicense:(NSString*) license;
/* <String, NSDate>, key: sdk_version, value: is_success flag */
+(NSDictionary*)takeLicenseFromNetworkWithUUID: (NSString*)uuid;
/* <String, NSDate>, key: sdk_version, value: expire date */
+(NSDictionary*)checkCachedLicense;

@end

@interface LicenseManager : NSObject<LicenseProtocolDelegate>

@end



//MegIDCardQuality