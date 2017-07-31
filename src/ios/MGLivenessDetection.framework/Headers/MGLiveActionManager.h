//
//  MGFaceActionManager.h
//  MGFaceDetection
//
//  Created by 张英堂 on 15/12/24.
//  Copyright © 2015年 megvii. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "LivenessEnumType.h"


/**
 *  活体检测动作管理器
 */
@interface MGLiveActionManager : NSObject

/**
 *  初始化方法，指定动作是否随机
 *
 *  @param actionRandom 是否动作随机
 *  @param actionArray  指定动作数组（在非随机动作情况下）
 *  @return 初始化对象
 */
+ (instancetype)LiveActionRandom:(BOOL)actionRandom
                     actionArray:(NSArray *)actionArray
                     actionCount:(NSUInteger)count;

/**
 *  获取动作数量
 *
 *  @return 动作数量
 */
- (NSUInteger)getActionCount;

/**
 *  恢复动作
 */
- (void)resetAction;


/**
 *  随机一个动作
 *
 *  @return 动作
 */
- (MGLivenessDetectionType)randomActionType;


/**
 *  恢复所有动作并且返回一个动作
 *
 *  @return 动作
 */
- (MGLivenessDetectionType)resetAndRandomActionType;


@end
