//
//  MGIDCardConfig.h
//  MGIDCard
//
//  Created by 张英堂 on 16/3/8.
//  Copyright © 2016年 megvii. All rights reserved.
//

#ifndef MGIDCardConfig_h
#define MGIDCardConfig_h


@class MGIDCardQualityAssessment;
@class MGIDCardModel;


static NSString *const IDCardModelName = @"MGIDCardModel";
static NSString *const IDCardModelType = @"model";

/**
 *  身份证检测失败类型
 */
typedef NS_ENUM(NSInteger, MGIDCardError) {
    /** 模拟器 */
    MGIDCardErrorSimulator,
    /**  取消检测 */
    MGIDCardErrorCancel,
};

/**
 *  身份证检测屏幕样式
 */
typedef NS_ENUM(NSInteger, MGIDCardScreenOrientation) {
    /**  屏幕竖直 样式 */
    MGIDCardScreenOrientationPortrait,
    /**  左横屏 样式 */
    MGIDCardScreenOrientationLandscapeLeft,
};


typedef void(^VoidBlock_error)(MGIDCardError errorType);
typedef void(^VoidBlock_result)(MGIDCardModel *model);

/**
 *  身份证区域相对于图片整体比例
 */
typedef struct {
    CGFloat x;              //距离左边的偏移，除去身份证宽度剩余部分的相对值(在竖屏模式下，直接为宽度的比例)
    CGFloat y;              //距离顶部的偏移 相对值
    CGFloat WHScale;        //身份证宽度与高度的比例
}MGIDCardScale;


CG_INLINE MGIDCardScale MGIDCardScaleMake(CGFloat x, CGFloat y){
    MGIDCardScale s;
    s.y = y;
    s.x = x;
    s.WHScale = 85.6 / 54.0;
    return s;
}

CG_INLINE BOOL MGIDCardScaleIsZero(MGIDCardScale scale){
    return !(scale.y || scale.x || scale.WHScale);
}

/**
 *  默认的身份证区域比例
 */
CG_INLINE  MGIDCardScale  MGIDCardDefaultScale(){
    return MGIDCardScaleMake(0.5, 0.2);
}
CG_INLINE  MGIDCardScale  MGIDCardScaleZero(){
    return MGIDCardScaleMake(0, 0);
}

#endif /* MGIDCardConfig_h */
