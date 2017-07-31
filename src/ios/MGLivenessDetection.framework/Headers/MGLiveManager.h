//
//  MGFaceManager.h
//  MGFaceDetection
//
//  Created by 张英堂 on 15/12/22.
//  Copyright © 2015年 megvii. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "MGLiveDetectionManager.h"

#import <MGBaseKit/MGBaseKit.h>
#import "MGLiveConfig.h"

@interface MGLiveManager : MGLicenseManager


/**
 *  活体检测中是否开启录像 必须启动检测器之前设置，启动检测器之后是无法在开启录像的，默认 关闭
 */
@property (nonatomic, assign) BOOL detectionWithMovier;

/**
 *  活体检测中是否开启录制声音 必须启动检测器之前设置，启动检测器之后是无法在开启的，并且需要开启录像，设置才会有用。默认 关闭，
 */
@property (nonatomic, assign) BOOL detectionWithSound;


/**
 *  设置活体动作数量，最多4个，最少1个，默认3个
 */
@property (nonatomic, assign) NSUInteger actionCount;


/**
 *  每个活动动作的超时时间，单位秒， 默认10秒
 */
@property (nonatomic, assign) NSUInteger actionTimeOut;

/**
 *  是否动作为随机 默认 是
 */
@property (nonatomic, assign) BOOL randomAction;

///**
// *  隐藏navigationbar 默认 yes
// */
//@property (nonatomic, assign) BOOL hideNavigationBar DEPRECATED_ATTRIBUTE;

/**
 *  在活体动作非 随机的情况下，设置动作序列，默认（1，2，3，4）
 */
@property (nonatomic, strong) NSMutableArray <NSNumber*> *actionArray;


@property (nonatomic, assign) MGLiveDetectionType detectionType;

/**
 *  在只有照镜子模式下的成功回调
 */
@property (nonatomic, copy) faceQualitySuccess Qualityfinish;


@property (nonatomic, copy) faceSettingError settingError;

/**
 *  启动检测器 
 *
 *  @param viewController 开启活体检测器的 viewcontroller
 *  @param finish         成功的回调
 *  @param error          失败的回调
 *
 *  @return 实例化该对象
 */
-(void)startFaceDecetionViewController:(UIViewController *)viewController
                                finish:(void(^)(FaceIDData *faceData, UIViewController *vc))finish
                                 error:(void(^)(MGLivenessDetectionFailedType errorType, UIViewController *vc))error;


/**
 *  获取 活体检测 SDK版本号
 *
 *  @return sdk 版本号
 */
+ (NSString *)LiveDetectionVersion;


@end
