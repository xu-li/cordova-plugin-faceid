//
//  LivenessEnumType.h
//  LivenessDetection
//
//  Created by 张英堂 on 15/1/12.
//  Edited by yangmu on 15/3/18.
//  Copyright (c) 2015年 megvii. All rights reserved.
//

/*!
 *  \file LivenessEnumType.h
 */

#ifndef LivenessDetection_LivenessEnumType_h
#define LivenessDetection_LivenessEnumType_h

#import <UIKit/UIKit.h>

/*!
 *  \enum MGLivenessDetectionType
 *  \brief 检测类型选项
 */
typedef enum MGLivenessDetectionType {
    DETECTION_TYPE_NONE = 0,                ///<初始状态
    DETECTION_TYPE_BLINK = 1,               ///<眨眼
    DETECTION_TYPE_MOUTH = 2,               ///<张嘴
    DETECTION_TYPE_POS_YAW = 3,             ///<左右转头
    DETECTION_TYPE_POS_PITCH = 4,           ///<上下点头
    DETECTION_TYPE_POS_YAW_LEFT = 5,        ///<向左转头
    DETECTION_TYPE_POS_YAW_RIGHT = 6,       ///<向右转头
    DETECTION_TYPE_POS_PITCH_UP = 7,        ///<抬头
    DETECTION_TYPE_POS_PITCH_DOWN = 8,      ///<低头
    DETECTION_TYPE_DONE = 9,                ///<结束状态
    DETECTION_TYPE_AIMLESS = -1             ///<持续监测
} MGLivenessDetectionType;


/*!
 *  \enum MGLivenessDetectionFailedType
 *  \brief 检测失败类型
 */

typedef enum MGLivenessDetectionFailedType {
    DETECTION_FAILED_TYPE_ACTIONBLEND = 0,          ///<动作错误
    DETECTION_FAILED_TYPE_NOTVIDEO,
    DETECTION_FAILED_TYPE_TIMEOUT,                  ///<超时
    DETECTION_FAILED_TYPE_FACELOSTNOTCONTINUOUS,
    DETECTION_FAILED_TYPE_TOOMANYFACELOST,
    DETECTION_FAILED_TYPE_FACENOTCONTINUOUS,
    DETECTION_FAILED_TYPE_MASK
} MGLivenessDetectionFailedType;


/*!
 *
 */
typedef enum MGLivenessFrameType {
    FRAME_TYPE_NONE = 0,                            ///<非特殊状态
    FRAME_TYPE_WAITINGNOMARL                        ///<正在等待用户将人脸归位
} MGLivenessFrameType;

/** @defgroup DetectorOptionKeys 检测器配置选项
 *  用于配置检测器的选项列表
 *  @{
 */

/** 模型路径 */
extern NSString* const MGLivenessDetectorModelPath;
/** 模型内容 */
extern NSString* const MGlivenessDetectorModelRawData;
/** 通信密钥 */
extern NSString* const MGLivenessDetectorCipher;
/** 每个检测环节的超时时限，默认10 */
extern NSString* const MGLivenessDetectorStepTimeLimit;
/** 质量判断－最小人脸大小 [100, 8192], 默认150 */
extern NSString* const MGLivenessDetectorMinFaceSize;
/** 质量判断－最大水平角度偏差 [0.0, 1.0]，默认0.17 */
extern NSString* const MGLivenessDetectorMaxYawAngle;
/** 质量判断－最大上下角度偏差 [0.0, 1.0]，默认0.17 */
extern NSString* const MGLivenessDetectorMaxPitchAngle;
/** 质量判断－人脸亮度最小平均值 [0, 255]，默认80 */
extern NSString* const MGLivenessDetectorMinBrightness;
/** 质量判断－人脸亮度最大平均值 [0, 255]，默认170 */
extern NSString* const MGLivenessDetectorMaxBrightness;
/** 质量判断－运动模糊阈值 [0.0, 1.0]，默认0.1 */
extern NSString* const MGLivenessDetectorMaxMotionBlurness;
/** 质量判断－高斯模糊阈值 [0.0, 1.0]，默认0.08 */
extern NSString* const MGLivenessDetectorMaxGaussianBlurness;
/** 质量判断－眼睛睁闭阈值 [0.0, 1.0]，默认0.3 */
extern NSString* const MGLivenessDetectorMaxEyeOpen;
/** 质量判断－嘴部开闭阈值 [0.0, 1.0]，默认0.4 */
extern NSString* const MGLivenessDetectorMaxMouthOpen;
/** 质量判断－有效面积比 */
extern NSString* const MGLivenessDetectorMinIntegrity;
/** 算法参数－主动配置算法参数，为空则使用默认配置 */
extern NSString* const MGLivenessDetectorAlgorithmConfig;

/*@}*/

#endif
