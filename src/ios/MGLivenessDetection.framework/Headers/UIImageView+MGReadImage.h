//
//  UIImageView+ReadImage.h
//  LivenessDetection
//
//  Created by 张英堂 on 15/10/9.
//  Copyright © 2015年 megvii. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface UIImageView (MGReadImage)

- (void)MGSetImageWithBlund:(NSString *)imageName;

- (void)MGSetImageWithImageName:(NSString *)imageName;

@end

