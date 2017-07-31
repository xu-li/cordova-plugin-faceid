//
//  TakePhotoVC.h
//  KoalaPhoto
//
//  Created by 张英堂 on 14/11/13.
//  Copyright (c) 2014年 visionhacker. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "MGLiveBaseDetectViewController.h"

#import "MGDefaultBottomManager.h"

/**
 *  活体检测页面
 */
@interface MGLiveDetectViewController: MGLiveBaseDetectViewController <MGLiveDetectionDelegate, MGVideoDelegate>


#pragma mark - 界面定制相关
/**
 *  类似 navigationbar样式遮罩的高度，navigationbar未隐藏的情况下为64，否则为0
 */
@property (nonatomic, assign) CGFloat topViewHeight;

/**
 *  动作提示界面
 */
@property (nonatomic, strong) MGBaseBottomManager *bottomView;

/**
 *  加载视频预览图层，如有需要子类重写。默认会在 viewWillAppear:时候被调用
 */
- (void)setUpCameraLayer;

/**
 *  人脸遮罩提示区域 长宽默认 1:1
 */
@property (strong, nonatomic) UIImageView *headerView;

/**
 *  创建组合显示界面，子类重写即可。 默认会在 viewdidload 的时候被调用
 */
- (void)creatView;


#pragma mark - 活体结束回调，使用block
/* 活体检测设置错误 */
@property (nonatomic, copy) faceSettingError settingError;




@end
