//
//  UIView+DreawLine.h
//  text
//
//  Created by imht-ios on 14-5-20.
//  Copyright (c) 2014年 ymht. All rights reserved.
//

/*
 使用说明：
        直接用 View 调用即可。
 */


#import <UIKit/UIKit.h>
#import <QuartzCore/QuartzCore.h>



@interface UIView (MGDrawLine)

/**
 *  给View增加边框
 *  @param  radius 变的角度
 *  @param  width  线条宽度
 *  @param  color  线条颜色
 */
- (void)MGDrawRoundBoderWidth:(CGFloat)width andColor:(UIColor *)color andRadius:(CGFloat)radius;


/**
 *  把View转化为图片
 */
-(UIImage *)MGChangeToImage;





@end
