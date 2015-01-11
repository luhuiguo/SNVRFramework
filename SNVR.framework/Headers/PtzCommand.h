//
//  PtzCommand.h
//  Camera
//
//  Created by 陆惠国 on 13-3-22.
//  Copyright (c) 2013年 LuHuiguo. All rights reserved.
//

#import "SNVRCommand.h"

@interface PtzCommand : SNVRCommand

@property (copy) void (^successBlock)(PtzCommand *command, SInt32 status);
@property (copy) void (^failureBlock)(PtzCommand *command, NSError *error);

- (void)ptzWithToken:(NSString *)token channel:(NSUInteger)channel cammand:(PTZControl)cmd option:(NSUInteger)option success:(void (^)(PtzCommand *command, SInt32 status))success failure:(void (^)(PtzCommand *command, NSError *error))failure;

@end
