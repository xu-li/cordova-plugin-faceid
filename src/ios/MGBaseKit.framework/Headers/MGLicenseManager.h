//
//  MGBaseManager.h
//  MGKit
//
//  Created by 张英堂 on 15/12/16.
//  Copyright © 2015年 megvii. All rights reserved.
//

#import <UIKit/UIKit.h>

/**
 *  SDK 使用管理，包括授权信息
 */
@interface MGLicenseManager : NSObject


/**
 *  获取当前SDK是否授权--- 子类需要重写该方法，通过该类获取的 是否授权无法全部包括使用的SDK
 *
 *  @return 是否授权
 */
+ (BOOL)getLicense;


/**
 *  获取授权时间 -- 由子类重写该方法
 *
 *  @return 授权时间
 */
+ (NSDate *)getLicenseDate;


@end



@interface MGLicenseManager ()


/**
 *  请求网络授权 ---子类不需要重写，只需要APP打开时候，授权一次即可
 */
+ (void)licenseForNetWokrFinish:(void(^)(bool License))finish;


@end