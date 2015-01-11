//
//  SwitchCommand.h
//  Camera
//
//  Created by 陆惠国 on 13-3-22.
//  Copyright (c) 2013年 LuHuiguo. All rights reserved.
//

#import "SNVRCommand.h"

@interface SwitchCommand : SNVRCommand

@property (copy) void (^successBlock)(SwitchCommand *command, SInt32 status);
@property (copy) void (^failureBlock)(SwitchCommand *command, NSError *error);

- (void)switchWithToken:(NSString *)token channel:(NSUInteger)channel oldStream:(NSUInteger)oldStream newStream:(NSUInteger)newStream success:(void (^)(SwitchCommand *command, SInt32 status))success failure:(void (^)(SwitchCommand *command, NSError *error))failure;

@end
