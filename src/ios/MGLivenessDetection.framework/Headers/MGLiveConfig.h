//
//  MGLiveConfig.h
//  MGLivenessDetection
//
//  Created by 张英堂 on 16/3/28.
//  Copyright © 2016年 megvii. All rights reserved.
//

#ifndef MGLiveConfig_h
#define MGLiveConfig_h


#import "LivenessEnumType.h"
#import "LivenessDetector.h"

#define KMGDEFAULTFACECENTER CGPointMake(0.5, 0.35)


/**
 *  倒计时显示类型
 */
typedef NS_ENUM(NSInteger, MGCountDownType) {
    /**  文本显示 */
    MGCountDownTypeText = 0,
    /** 倒计时圆环 */
    MGCountDownTypeRing,
    /** 自定义 */
    MGCountDownTypeCustom,
};


/**
 *  活体检测各项配置错误类型
 */
typedef NS_ENUM(NSInteger, MGLiveSettingErrorType) {
    /** 没有错误 */
    MGLiveSettingErrorNone,
    /** videoManager没有设置 */
    MGLiveSettingErrorVideoError,
    /**  videoManager 已经设置，但是没有实现 videoblcok 代理 */
    MGLiveSettingErrorVideoBlockError,
    /**  livedetecionManager 没有设置 */
    MGLiveSettingErrorDetectionError,
    /**  livedetecionManager 已经设置，但是没有设置代理对象*/
    MGLiveSettingErrorDetectionDelegateError,
};

static NSString *const MGLiveModelName = @"MegLive_model";
static NSString *const MGLiveModelType = @"";


typedef void(^faceSuccess)(FaceIDData *faceData, UIViewController *vc);
typedef void(^faceError)(MGLivenessDetectionFailedType errorType, UIViewController *vc);
typedef void(^faceSettingError)(MGLiveSettingErrorType errorType, UIViewController *vc);
typedef void(^faceQualitySuccess)(MGLivenessDetectionFrame *faceFrame, UIViewController *vc);



#endif /* MGLiveConfig_h */
