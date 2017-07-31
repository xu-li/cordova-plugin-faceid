//
//  MGLiveDefaultDetectVC.h
//  MGLivenessDetection
//
//  Created by 张英堂 on 16/8/17.
//  Copyright © 2016年 megvii. All rights reserved.
//

#import <MGLivenessDetection/MGLivenessDetection.h>
#import "MGLiveDetectViewController.h"

@interface MGLiveDefaultDetectVC : MGLiveDetectViewController


#pragma mark - 活体结束回调，使用block
/**
 *  活体全步骤结束，成功的回调
 */
@property (nonatomic, copy) faceSuccess detectFinish;

/**
 *  活体全步骤结束，失败的回调
 */
@property (nonatomic, copy) faceError detectError;

/**
 *  在只有照镜子模式下的成功回调
 */
@property (nonatomic, copy) faceQualitySuccess Qualityfinish;



@end
