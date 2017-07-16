//
//  MGIDCardDetectBaseViewController.h
//  MGIDCard
//
//  Created by 张英堂 on 16/8/10.
//  Copyright © 2016年 megvii. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <MGBaseKit/MGBaseKit.h>
#import "MGIDCardConfig.h"

#import "MGIDCardDetectManager.h"


@interface MGIDCardDetectBaseViewController : UIViewController<MGVideoDelegate, MGIDCardDetectDelegate>

/**
 *  如果使用默认设置，请使用该方法初始化！
 *
 *  @return 实例化对象
 */
- (instancetype)initWithDefaultSetting;

/**
 *  不使用默认配置设置的时候，必须设置该对象
 */
@property (nonatomic, strong) MGVideoManager *videoManager;
@property (nonatomic, strong) MGIDCardDetectManager *cardCheckManager;

/**
 *  视频预览layer
 */
@property (nonatomic, strong) AVCaptureVideoPreviewLayer *previewLayer;

/**
 *  检测身份证面  0 正面, 1 反面
 */
@property (nonatomic, assign) MGIDCardSide IDCardSide;

/**
 *  屏幕方向
 */
@property (nonatomic, assign) MGIDCardScreenOrientation screenOrientation;


/**
 *  检测到每一帧的错误
 *  子类重写即可
 *  @param errorArray 错误列表
 */
- (void)detectFrameError:(NSArray *)errorArray;

/**
 *  身份证检测失败的详情信息
 *  子类重写即可
 *  @param result 检测结果
 */
- (void)detectFrameErrorDetail:(MGIDCardQualityResult *)result;

/**
 *  身份证检测成功
 *  子类重写
 *  @param result 检测结果
 */
- (void)detectSucess:(MGIDCardQualityResult *)result;

@end
