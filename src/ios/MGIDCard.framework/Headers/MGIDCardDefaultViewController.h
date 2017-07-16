//
//  MGIDCardDefaultViewController.h
//  MGIDCard
//
//  Created by 张英堂 on 16/8/18.
//  Copyright © 2016年 megvii. All rights reserved.
//

#import <MGIDCard/MGIDCard.h>

@interface MGIDCardDefaultViewController : MGIDCardViewController


/**
 *  检测成功的block回调
 */
@property (nonatomic, copy) VoidBlock_result finishBlock;

/**
 *  检测失败的block回调
 */
@property (nonatomic, copy) VoidBlock_error errorBlcok;


@end
