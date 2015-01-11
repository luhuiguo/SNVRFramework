//
//  ChannelCommand.h
//  Camera
//
//  Created by 陆惠国 on 13-3-22.
//  Copyright (c) 2013年 LuHuiguo. All rights reserved.
//

#import "SNVRCommand.h"


@interface ChannelCommand : SNVRCommand

@property (copy) void (^successBlock)(ChannelCommand *command, NSArray *channels);
@property (copy) void (^failureBlock)(ChannelCommand *command, NSError *error);

- (void)channelWithToken:(NSString *)token success:(void (^)(ChannelCommand *command, NSArray *channels))success failure:(void (^)(ChannelCommand *command, NSError *error))failure;

@end
