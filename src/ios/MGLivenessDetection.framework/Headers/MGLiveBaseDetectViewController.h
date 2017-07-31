//
//  MGLiveBaseDetectViewController.h
//  MGLivenessDetection
//
//  Created by 张英堂 on 16/8/5.
//  Copyright © 2016年 megvii. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <MGBaseKit/MGBaseKit.h>

#import "MGLiveConfig.h"
#import "MGLiveBundle.h"
#import "MGLiveDetectionManager.h"


@interface MGLiveBaseDetectViewController : UIViewController<MGLiveDetectionDelegate, MGVideoDelegate>

/**
 *  默认设置的初始化方法 --当你不想设置一大堆参数的时候可以使用该方法
 *
 *  @return 实例化对象
 */
- (instancetype)initWithDefauleSetting;

/**
 *   视频流管理器 不使用默认配置设置的时候，必须设置该对象
 */
@property (nonatomic, strong) MGVideoManager *videoManager;

/**
 *   活体检测管理器 不使用默认配置设置的时候，必须设置该对象
 */
@property (nonatomic, strong) MGLiveDetectionManager *liveManager;


/**
 *  质量检测阶段，抛出错误。
 *  在质量检测时，出现错误，会调用该方法，子类重写即可。
 *  @param error 错误信息
 */
- (void)qualitayErrorMessage:(NSString *)error;

/**
 *  播放动作提示动画
 *  在活体动作改变的时候会被调用，子类需要重写
 *  @param type    动作类型
 *  @param step    当前第几个动作
 *  @param timeOut 剩余超时时间
 */
- (void)starAnimation:(MGLivenessDetectionType)type
                 step:(NSInteger)step
              timeOut:(NSUInteger)timeOut;


/**
 *  活体检测结束处理
 *  在活体检测成功或者失败时候被调用，子类需要重写
 *  @param type          失败类型
 *  @param check         活体检测是否成功，如果为 YES，则 type 参数无效
 *  @param detectionType 活体检测模式
 */
- (void)liveDetectionFinish:(MGLivenessDetectionFailedType)type checkOK:(BOOL)check liveDetectionType:(MGLiveDetectionType)detectionType;

/**
 *  即将启动活体检测
 */
- (void)willStatLiveness;

/** 开启活体检测流程 */
- (void)liveFaceDetection;

/**
 *  停止视频检测
 */
- (void)stopVideoWriter;


/**
 取消活体检测
 */
- (void)cancelDetect;

/**
 活体检测过程中出现人脸过大情况
 */
- (void)detectionFaceToLarge;

/**
 活体检测过程中人脸过大情况恢复
 */
- (void)detectionFaceRecover;





/**
 *  视频预览layer， 通过 videoManager 来获取
 */
@property (nonatomic, strong) AVCaptureVideoPreviewLayer *previewLayer;



@end
