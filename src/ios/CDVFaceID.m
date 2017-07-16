//
//  CDVWechat.m
//  cordova-plugin-wechat
//
//  Created by xu.li on 12/23/13.
//
//

#import "CDVFaceID.h"
#import <MGBaseKit/MGBaseKit.h>
#import <MGIDCard/MGIDCard.h>


@implementation CDVFaceID

- (void)auth:(CDVInvokedUrlCommand *)command
{
    // save the callback id
    self.callbackId = command.callbackId;
    
    [MGLicenseManager licenseForNetWokrFinish:^(bool success) {
        int code = success ? 1 : 0;
        
        CDVPluginResult *commandResult = [CDVPluginResult resultWithStatus:CDVCommandStatus_OK messageAsInt:code];
        [self.commandDelegate sendPluginResult:commandResult callbackId:self.callbackId];
    }];
}

- (void)takePicture:(CDVInvokedUrlCommand *)command
{
    // check license
    bool license = [MGIDCardManager getLicense];
    
    if (!license) {
        [self failWithCallbackID:command.callbackId withMessage:@"未完成授权"];
        return ;
    }
    
    // save the callback id
    self.callbackId = command.callbackId;
    
    
    // check arguments
    MGIDCardSide side = IDCARD_SIDE_FRONT;
    if ([command.arguments count] > 0) {
        NSNumber *front = [command.arguments objectAtIndex:0];
        
        if ([front boolValue] == NO) {
            side = IDCARD_SIDE_BACK;
        }
    }
    
    // start recording
    __unsafe_unretained CDVFaceID *weakSelf = self;
    
    MGIDCardManager *cardManager = [[MGIDCardManager alloc] init];
    cardManager.screenOrientation = MGIDCardScreenOrientationLandscapeLeft;
    
    [cardManager IDCardStartDetection:self.viewController
                           IdCardSide:side
                               finish:^(MGIDCardModel *model) {
                                   NSMutableDictionary *result = [[NSMutableDictionary alloc] init];
                                   
                                   NSString *imagePrefix = @"data:image/bmp;base64,";
                                   
                                   // side
                                   result[@"is_front_side"] = [NSNumber numberWithBool:model.cardSide == IDCARD_SIDE_FRONT];
                                   
                                   // id card
                                   UIImage *idCard = [model croppedImageOfIDCard];
                                   if (idCard != nil) {
                                       result[@"idcard_image"] = [NSString stringWithFormat:@"%@%@", imagePrefix, [self encodeUIImageToBase64String:idCard]];
                                   }
                                   
                                   // portait
                                   if (model.cardSide == IDCARD_SIDE_FRONT) {
                                       UIImage *portrait = [model croppedImageOfPortrait];
                                       result[@"portrait_image"] = [NSString stringWithFormat:@"%@%@", imagePrefix, [self encodeUIImageToBase64String:portrait]];
                                   }
                                   
                                   // send result
                                   CDVPluginResult *commandResult = [CDVPluginResult resultWithStatus:CDVCommandStatus_OK messageAsDictionary:result];
                                   [self.commandDelegate sendPluginResult:commandResult callbackId:weakSelf.callbackId];
                                   
                               }
                                 errr:^(MGIDCardError err) {
                                     if (err == MGIDCardErrorCancel) {
                                         NSMutableDictionary *result = [[NSMutableDictionary alloc] init];
                                         CDVPluginResult *commandResult = [CDVPluginResult resultWithStatus:CDVCommandStatus_OK messageAsDictionary:result];
                                         [self.commandDelegate sendPluginResult:commandResult callbackId:self.callbackId];
                                     } else {
                                         [self failWithCallbackID:weakSelf.callbackId withMessage:@"获取身份证失败"];
                                     }
                                 }];
    
}

- (void)failWithCallbackID:(NSString *)callbackID withMessage:(NSString *)message
{
    CDVPluginResult *commandResult = [CDVPluginResult resultWithStatus:CDVCommandStatus_ERROR messageAsString:message];
    [self.commandDelegate sendPluginResult:commandResult callbackId:callbackID];
}

- (NSString *)encodeUIImageToBase64String:(UIImage *)image
{
    return [UIImagePNGRepresentation(image) base64EncodedStringWithOptions:NSDataBase64Encoding64CharacterLineLength];
}


@end
