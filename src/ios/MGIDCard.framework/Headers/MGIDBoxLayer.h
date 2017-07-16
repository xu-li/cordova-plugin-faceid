//
//  MGIDBoxLayer.h
//  MGIDCard
//
//  Created by 张英堂 on 16/8/11.
//  Copyright © 2016年 megvii. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <QuartzCore/QuartzCore.h>
#import <MGBaseKit/MGBaseKit.h>
#import "MGIDCardQualityAssessment.h"

@interface MGIDBoxLayer : UIView

/**
 *  身份证区域
 */
@property (nonatomic, assign) CGRect IDCardBoxRect;
@property (nonatomic, assign) CGRect imageCutoutRect;

@property (nonatomic, assign) MGIDCardSide IDCardSide;

@property (nonatomic, assign) BOOL isDebug;
@property (nonatomic, copy) NSString* detailStr;

@end
