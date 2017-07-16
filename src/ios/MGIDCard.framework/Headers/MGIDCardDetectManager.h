//
//  CardCheckManger.h
//  OCRSDK_Test
//
//  Created by 张英堂 on 15/8/6.
//  Copyright (c) 2015年 megvii. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "MGIDCardConfig.h"
#import "MGIDCardQualityAssessment.h"

@protocol MGIDCardDetectDelegate;

@interface MGIDCardDetectManager : NSObject

-(instancetype)init DEPRECATED_ATTRIBUTE;

//+(instancetype)idCardCheckWithDelegate:(id<MGIDCardDetectDelegate>)delegate
//                              cardSide:(MGIDCardSide)side
//                     screenOrientation:(MGIDCardScreenOrientation)screenOrientation DEPRECATED_ATTRIBUTE;

/**
 *  初始化方法
 *
 *  @param side              身份证正反面
 *  @param screenOrientation 屏幕方向
 *  @return 实例化对象
 */
+(instancetype)idCardManagerWithCardSide:(MGIDCardSide)side
                       screenOrientation:(MGIDCardScreenOrientation)screenOrientation;

@property (nonatomic, assign) MGIDCardScale IDCardScaleRect;

@property (nonatomic, assign) id <MGIDCardDetectDelegate> delegate;

/**
 *  0 for 正面, 1 for 反面
 */
@property (nonatomic, assign) MGIDCardSide IDCardSide;

/**
 *  检测身份证图片，异步返回
 *  已经弃用，请使用 detectWithImage
 *  @param image 图片
 */
- (void)checkWithImage:(UIImage *)image DEPRECATED_ATTRIBUTE;

/**
 *  检测身份证图片，异步返回
 *
 *  @param image 图片
 */
- (void)detectWithImage:(UIImage *)image;

/**
 *  根据失败类型，获取错误信息
 *
 *  @param errorType 错误类型
 *
 *  @return 错误信息
 */
- (NSString *)getErrorShowString:(MGIDCardFailedType)errorType;

/**
 *  重置数据
 */
- (void)reset;

/**
 *  停止检测
 */
- (void)stopDetect;

/**
 *  获取截取区域位置
 */

-(CGRect)expandFaceWithImageSize:(CGSize)size;

@end


@protocol MGIDCardDetectDelegate <NSObject>

@required
/**
 *  每一张图片检测完成返回信息
 *
 *  @param manager 指针
 *  @param result  检测结果
 */
- (void)cardCheck:(MGIDCardDetectManager *)manager finish:(MGIDCardQualityResult *)result;

@end
