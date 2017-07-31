//
//  UIImage+Resize.h
//  SCCaptureCameraDemo
//
//  Created by Aevitx on 14-1-17.
//  Copyright (c) 2014年 Aevitx. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface UIImage (MGFixOrientation)

- (UIImage *)MGCroppedImage:(CGRect)bounds;

- (UIImage *)MGFixOrientation;

@end
