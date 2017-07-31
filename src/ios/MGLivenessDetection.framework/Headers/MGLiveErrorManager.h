//
//  MGFaceError.h
//  MGFaceDetection
//
//  Created by 张英堂 on 15/12/23.
//  Copyright © 2015年 megvii. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "LivenessDetector.h"
#import "MGFaceQualityManager.h"

/**
 *  照镜子成功返回的key
 */
static NSString *const MGFaceFinishKey = @"com.megvii.face.finish";


/**
 *  错误提示管理器,只在照镜子阶段调用，正式进入活体动作后，不再调用
 */
@interface MGLiveErrorManager : NSObject

/**
 *  请使用 initWithFaceCenter: 方法进行初始化！
 */
- (instancetype)init DEPRECATED_ATTRIBUTE;

/**
 *  请使用该方法初始化
 *  @param center 人脸中心位置 类似于 （0.5，0.5）之类相对值
 *  @return 实例化对象
 */
- (instancetype)initWithFaceCenter:(CGPoint)center;


/**
 *  检测每一帧的错误 manager
 */
@property (nonatomic, strong, readonly) MGFaceQualityManager *qualityManager;


/**
 *  抛出出错最多的错误, 防止连续显示错误，造成显示异常，默认 10 帧。
 */
@property (nonatomic, assign) NSInteger holdingErrorCount;


/**
 *  检测每一帧错误，并且返回要处理的事情
 *
 *  @param frame   活体的每一帧结果
 *  @param motionY 当前的 重力的 y轴值 如果忽略该判断，请设置该值为 1.0
 *
 *  @return 返回结果 （MGFaceFinishKey 为检测成功，可以进入活体动作）
 */
- (NSString *)checkImgWithMGFrame:(MGLivenessDetectionFrame *)frame motionY:(CGFloat)motionY;


/**
 *  重置失败列表
 */
- (void)resetErrorList;


@end
