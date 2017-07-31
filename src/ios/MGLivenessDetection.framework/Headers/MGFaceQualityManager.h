//
//  MGFaceQualityManager.h
//  MGLivenessDetection
//
//  Created by 张英堂 on 16/3/28.
//  Copyright © 2016年 megvii. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "LivenessDetector.h"

/*
 * 每一帧检测出现的错误类型
 */
typedef NS_ENUM(NSInteger, MGFaceQualityErrorType) {
    MGFaceQualityErrorNone = 0,                   //没有错误
    MGFaceQualityErrorFaceNotFound,                     //没有人脸
    MGFaceQualityErrorFacePosDeviated,                   //yaw或pitch角度过大
    MGFaceQualityErrorFaceNonIntegrity,               //人脸的有效面积比过小
    MGFaceQualityErrorFaceTooDark,             //人脸亮度过小
    MGFaceQualityErrorFaceTooBright,           //人脸亮度过大
    MGFaceQualityErrorFaceTooSmall,               //人脸宽度过小
    MGFaceQualityErrorFaceTooLarge,               //人脸宽度过大
    MGFaceQualityErrorFaceTooBlurry,           //运动模糊度过大
    MGFaceQualityErrorFaceOutOfRect,                 //人脸偏移过大
    MGFaceQualityErrorFrameNeedHolding,                //需要连续一定帧数合格
};

@interface MGFaceQualityManager : NSObject

/**
 *  初始化方法，必须使用该方法初始化
 *
 *  @param faceCenter 人脸中心位置，相对值（0.5，0.5）
 *
 *  @return 实例化对象
 */
- (instancetype)initWithFaceCenter:(CGPoint)faceCenter;

/**
 *  默认值 3
 */
@property (nonatomic, assign) NSUInteger needHolding;

/**
 *  默认值 0.17
 */
@property (nonatomic, assign) float yawThreshold;

/**
 *  默认值 0.17
 */
@property (nonatomic, assign) float pitchThreshold;

/**
 *  人脸有效面积比 默认值 0.99
 */
@property (nonatomic, assign) float integrityThreshold;

/**
 *  人脸亮度 最大值默认值 230
 */
@property (nonatomic, assign) float maxBrightnessThreshold;

/**
 *  人脸亮度 最小值默认值 70
 */
@property (nonatomic, assign) float minBrightnessThreshold;


/**
 *  运动模糊最大值 默认值 0.20
 */
@property (nonatomic, assign) float motionBlurThreshold;

/**
 *  高斯模糊最大值 默认值 0.15
 */
@property (nonatomic, assign) float gaussianBlurThreshold;


/**
 *  视频图像中的人脸宽度，绝对值 默认 150
 */
@property (nonatomic, assign) float faceWidthThreshold;


/**
 *  视频图像中的人脸宽度，相对值 默认值 0.4
 */
@property (nonatomic, assign) float faceMaxSizeRatioThreshold;


/**
 *  检测每一帧错误，并且返回出错的原因
 *
 *  @param frame   活体的每一帧结果
 *
 *  @return 返回结果 检测的错误类型,多个错误并存
 */
- (NSArray *)feedFrame:(MGLivenessDetectionFrame *)frame;


@end
