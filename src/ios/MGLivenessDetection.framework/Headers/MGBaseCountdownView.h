//
//  MGBaseCountdownView.h
//  MGLivenessDetection
//
//  Created by 张英堂 on 16/4/12.
//  Copyright © 2016年 megvii. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface MGBaseCountdownView : UIView

@property (nonatomic, assign, readonly) CGFloat maxTime;

/**
 *  设置倒计时时间
 *
 *  @param time 时间
 */
- (void)setMaxTime:(CGFloat)time;

/**
 *  开启动画
 */
- (void)startAnimation;

/**
 *  关闭动画
 */
- (void)stopAnimation;



/* 以下方法为 子类重写，每次倒计时改变都会被调用 */

/**
 *  倒计时改变
 *
 *  @param lastTime 剩余倒计时时间
 */
- (void)timerChangeAndViewAnimation:(CGFloat)lastTime;


/**
 *  创建倒计时界面 初始化时候被调用
 */
- (void)creatCountDownView;


@end
