//
//  MGIDCardModel.h
//  MGIDCard
//
//  Created by 张英堂 on 16/3/28.
//  Copyright © 2016年 megvii. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "MGIDCardQualityAssessment.h"


@interface MGIDCardModel : NSObject

- (instancetype)initWithResult:(MGIDCardQualityResult *)result;


@property (nonatomic, strong) MGIDCardQualityResult *result;

@property (nonatomic, assign) MGIDCardSide cardSide;
@property (nonatomic, strong) UIImage *image;


-(UIImage*)croppedImageOfIDCard;

-(UIImage*)croppedImageOfPortrait;





@end
