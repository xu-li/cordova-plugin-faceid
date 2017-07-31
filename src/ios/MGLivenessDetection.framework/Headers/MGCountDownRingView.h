//
//  MGCountDownViewTwo.h
//  MGLivenessDetection
//
//  Created by 张英堂 on 16/4/13.
//  Copyright © 2016年 megvii. All rights reserved.
//
#import <UIKit/UIKit.h>
#import "MGBaseCountdownView.h"

@interface MGCountDownRingView : MGBaseCountdownView


/**
 *  显示倒计时的label
 */
@property (nonatomic, strong) UILabel *numLabel;


/**
 *  倒计时圆环
 */
@property (nonatomic, strong) CAShapeLayer *circleLayer;



@end
