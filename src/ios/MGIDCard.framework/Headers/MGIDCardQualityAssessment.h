//
//  MGIDCardQualityAssessment.h
//  MGIDCardFusion
//
//  Created by 张英堂 on 2016/10/20.
//  Copyright © 2016年 megvii. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import <MGBaseKit/MGBaseKit.h>

/* 初始化参数，二选一 */
extern NSString* const MGIDCardQualityAssessmentModelPath;
extern NSString* const MGIDCardQualityAssessmentModelRawData;


typedef NS_ENUM(NSInteger, MGIDCardSide) {
    IDCARD_SIDE_FRONT = 0,
    IDCARD_SIDE_BACK = 1
};

typedef NS_ENUM(NSInteger, MGIDCardFailedType) {
    QUALITY_FAILED_TYPE_NONE = 0,
    QUALITY_FAILED_TYPE_NOIDCARD,   //1
    QUALITY_FAILED_TYPE_WRONGSIDE,
    QUALITY_FAILED_TYPE_TILT,//3
    QUALITY_FAILED_TYPE_BLUR,
    QUALITY_FAILED_TYPE_SIZETOOSMALL,//5
    QUALITY_FAILED_TYPE_SIZETOOLARGE,
    QUALITY_FAILED_TYPE_SPECULARHIGHLIGHT,//7
    QUALITY_FAILED_TYPE_OUTSIDETHEROI,
    QUALITY_FAILED_TYPE_BRIGHTNESSTOOHIGH,//9
    QUALITY_FAILED_TYPE_BRIGHTNESSTOOLOW,
    QUALITY_FAILED_TYPE_FAKE,//11
    QUALITY_FAILED_TYPE_SHADOW
};

typedef NS_ENUM(NSInteger, MGIDCardType) {
    IDCARD_TYPE_NORMAL,
    IDCARD_TYPE_MONGOL
};

typedef struct{
    float low_quality;
    //  Whether in rect
    float in_bound;
    //  Whether it is IDCard
    float is_idcard;
    //  shadow
    bool has_shadow;
    int shadow_count;
    //  flare
    bool has_specular_highlight;
    int specular_highlight_count;
    /*!
     * Four corner of the idcard in the image.
     * point order: top-left, top-right, bottom-right, bottom-left
     */
    CGPoint corner_points[4];
    /*!
     * Where the portrait image lies. meaningful only when it is front side
     * point order: top-left, top-right, bottom-right, bottom-left
     */
    CGPoint portrait_points[4];
    /** x(yaw), y(pitch), z(roll) rotation angles, in radian */
    float angles[3];
    /** 0 for front, 1 for back */
    MGIDCardSide side;
    
    float brightness;
    MGIDCardType idcard_type;
    
    bool legality;
}MGIDCardAttr;

@interface MGIDCardQualityResult : NSObject

@property (readonly) MGIDCardAttr attr;
@property (readonly) NSArray *fails;
@property (readonly) UIImage *image;

- (BOOL)isValid;

- (UIImage*)croppedImageOfIDCard;
- (UIImage*)croppedImageOfIDCardWithMaxSize:(int)maxSize;

- (UIImage*)croppedImageOfPortrait;
- (UIImage*)croppedImageOfPortraitWithMaxSize:(int)maxSize;

- (NSData*)getImageDataWithMaxSize:(int)maxSize
                        isPortrait:(bool)isPortrait
         andJPEGCompressionQuality:(CGFloat)jpegQuality
                    andNeedEncrypt:(bool)encrypt
                  andNeedWatermark:(bool)watermark
                           andCode:(int) code;

@end

@interface MGIDCardQualityAssessment : NSObject <LicenseProtocolDelegate>

+ (MGIDCardQualityAssessment*)assessmentOfOptions:(NSDictionary*) options;

- (MGIDCardQualityResult*)getQualityWithImage:(UIImage*)image side:(MGIDCardSide)side;
- (MGIDCardQualityResult*)getQualityWithImage:(UIImage*)image side:(MGIDCardSide)side ROI:(CGRect)ROI;

+ (NSString*)getVersion;

/**  是否为身份证 默认值 0.5 （0 - 1.0）*/
@property (nonatomic, assign) float isIDCard;

/**  是否在引导框内 默认值 0.5 （0 - 1.0）*/
@property (nonatomic, assign) float inBound;

/**  是否清晰 默认值 0.5 （0 - 1.0） */
@property (nonatomic, assign) float clear;

/**  是否忽略光斑 默认值false */
@property (nonatomic, assign) BOOL isIgnoreHighlight;

/**  是否忽略阴影 默认值false */
@property (nonatomic, assign) BOOL isIgnoreShadow;

@end
