//
//  CDVWechat.h
//  cordova-plugin-wechat
//
//  Created by xu.li on 12/23/13.
//
//

#import <Cordova/CDV.h>

@interface CDVFaceID:CDVPlugin


@property (nonatomic, strong) NSString *callbackId;

- (void)auth:(CDVInvokedUrlCommand *)command;
- (void)takePicture:(CDVInvokedUrlCommand *)command;


@end
