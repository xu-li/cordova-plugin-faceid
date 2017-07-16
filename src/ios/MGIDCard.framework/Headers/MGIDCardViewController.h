//
//  VideViewController.h
//  KoalaPad
//
//  Created by 张英堂 on 15/2/10.
//  Copyright (c) 2015年 megvii. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "MGIDCardDetectBaseViewController.h"
#import "MGIDCardModel.h"
#import "MGIDCardBundle.h"
#import "MGIDBoxLayer.h"

@interface MGIDCardViewController : MGIDCardDetectBaseViewController

/**
 *  默认使用 MGIDCardDefaultScale。
 */
@property (nonatomic, assign) MGIDCardScale IDCardScale;


/* 以下方法如有需要请重写即可。 */
/** 创建界面。 在 viewDidLoad 时被调用*/
- (void)creatView;

/** 加载视频预览图层预览。  在 viewWillAppear 被调用*/
- (void)setUpCameraLayer;

/** 显示错误信息，每一帧检测出错就会被调用 */
- (void)showErrorMessage:(NSString *)errorString;


/**
 *  停止身份证检测
 */
- (void)stopIDCardDetect;

/**
 *  取消身份证检测
 */
- (void)cancelIDCardDetect;


#pragma mark - 界面相关元素
@property (strong, nonatomic) UILabel *checkErroLabel; //错误提示显示
@property (strong, nonatomic) UIButton *backBTN;   //返回按钮
@property (strong, nonatomic) UIImageView *messageView; //身份证遮罩

@property (strong, nonatomic) MGIDBoxLayer *boxLayer;
@property (assign, nonatomic) CGRect IDCardBoxRect;

@end
