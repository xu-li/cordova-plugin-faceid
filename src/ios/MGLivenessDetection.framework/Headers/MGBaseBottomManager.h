//
//  BottomAnimationView.h
//  LivenessDetection
//
//  Created by 张英堂 on 15/1/8.
//  Copyright (c) 2015年 megvii. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "LivenessEnumType.h"
#import "MGBaseCountdownView.h"
#import "MGPlayAudio.h"

#import "MGLiveConfig.h"
#import "MGLiveBundle.h"

/**
 *  显示该步骤要操作的动画
 */
@interface MGBaseBottomManager : UIView

/**
 *  倒计时样式，默认 MGCountDownTypeRing 样式,通过初始化设置
 */
@property (nonatomic, assign, readonly) MGCountDownType countDownType;

/**
 *  动画是否停止
 */
@property (nonatomic, assign, readonly) BOOL stopAnimaiton;


/**
 *  必须使用该方法初始化
 *
 *  @param frame         frame
 *  @param countDownType 倒计时动画类型
 *
 *  @return 初始化对象
 */
- (instancetype)initWithFrame:(CGRect)frame
             andCountDownType:(MGCountDownType)countDownType;


/**
 *  只有在 MGCountDownTypeCustom 模式下，请手动设置该类
 */
@property (nonatomic, strong) MGBaseCountdownView *countDownView;

/**
 *  提示信息label， 需要子类初始化
 */
@property (nonatomic, strong) UILabel *messageLabel;

/**
 *  开始动画
 */
- (void)startRollAnimation;

/**
 *  初始化 界面参数值，不包涵 view，子类不需要重写；
 */
- (void)recovery;

/**
 *  显示提示信息
 *
 *  @param message 信息
 */
- (void)showMessageView:(NSString *)message;

/**
 *  恢复初始状态，并显示信息
 *
 *  @param title 信息
 */
- (void)recoveryWithTitle:(NSString *)title;


#pragma mark - 用户可能重写的方法
/* 子类需要重写一下方法，并且重写时候调用 [super  method]; 方法 */
/**
 *  创建界面，除动画以外的界面，以及界面颜色之类的定制。 该类初始化时候被调用
 */
- (void)creatBottomView;

/**
 *  创建动画的界面，即两个imageview，进行动画提示。 该类初始化时候被调用
 */
- (void)creatAniamtionView;

/**
 *  恢复view的初始状态，主要负责动画的view
 */
- (void)recoveryView;

/**
 *  下一步 显示的动画，在动作结束进入下一个动作 被调用
 *
 *  @param state 动画类型
 *  @param time  倒计时间
 */
- (void)willChangeAnimation:(MGLivenessDetectionType)state
                    outTime:(CGFloat)time
                currentStep:(NSInteger)step;



@end
