//
//  LogoutCommand.h
//  Camera
//
//  Created by 陆惠国 on 13-3-22.
//  Copyright (c) 2013年 LuHuiguo. All rights reserved.
//

#import "SNVRCommand.h"

@interface LogoutCommand : SNVRCommand

@property (copy) void (^successBlock)(LogoutCommand *command);
@property (copy) void (^failureBlock)(LogoutCommand *command, NSError *error);

- (void)logoutWithToken:(NSString *)token success:(void (^)(LogoutCommand *command))success failure:(void (^)(LogoutCommand *command, NSError *error))failure;


@end
