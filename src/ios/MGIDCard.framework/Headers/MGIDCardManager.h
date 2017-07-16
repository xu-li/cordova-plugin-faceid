//
//  MGIDCardManager.h
//  MGIDCard
//
//  Created by 张英堂 on 15/12/28.
//  Copyright © 2015年 megvii. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <MGBaseKit/MGBaseKit.h>
#import "MGIDCardConfig.h"
#import "MGIDCardModel.h"


@interface MGIDCardManager : MGLicenseManager


/**
 *  设置屏幕方向，默认水平方向 MGIDCardScreenOrientationPortrait；
 */
@property (nonatomic, assign) MGIDCardScreenOrientation screenOrientation;

/**
 *  开启身份证检测
 *
 *  @param ViewController 启动的界面，最后结束返回该界面
 *  @param CardSide       身份证正反面
 *  @param finish         身份证检测完成 block
 *  @param error          用户检测取消
 */
- (void)IDCardStartDetection:(UIViewController *)ViewController
                  IdCardSide:(MGIDCardSide)CardSide
                      finish:(void(^)(MGIDCardModel *model))finish
                        errr:(void(^)(MGIDCardError errorType))error;



/**
 *  获取 身份证 SDK版本号
 *
 *  @return sdk 版本号
 */
+ (NSString *)IDCardVersion;



@end
