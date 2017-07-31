//
//  MGFaceBundle.h
//  MGFaceDetection
//
//  Created by 张英堂 on 15/12/23.
//  Copyright © 2015年 megvii. All rights reserved.
//

#import <UIKit/UIKit.h>

/** 要读取的文件类型 */
typedef NS_ENUM(NSInteger, MGBundleDirectory) {
    /** 图片 */
    MGBundleImage = 1,
    /** 语音 */
    MGBundleAudio,
    /** 其他类型 */
    MGBundleMain,
};

@interface MGLiveBundle : NSObject

/**
 *  读取 facebundle 的资源
 *
 *  @param name 资源名字
 *  @param type 资源类型
 *
 *  @return 资源路径
 */
+ (NSString *)LivePathForResource:(NSString *)name ofType:(NSString *)type;

+ (NSString *)LivePathForResource:(NSString *)name ofType:(NSString *)type inDirectory:(MGBundleDirectory)Directory;

/**
 *  返回语言
 *  @param key 字符串的 key
 *  @return 字符串
 */
+ (NSString *)LiveBundleString:(NSString *)key;

/**
 *  读取 facebundle的图片 -- 必须为 png格式
 *
 *  @param name 图片名字
 *
 *  @return 图片
 */
+ (UIImage *)LiveImageWithName:(NSString *)name;



@end
