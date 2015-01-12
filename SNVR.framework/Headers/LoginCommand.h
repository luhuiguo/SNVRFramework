//
//  LoginCommand.h
//  Camera
//
//  Created by 陆惠国 on 13-3-22.
//  Copyright (c) 2013年 LuHuiguo. All rights reserved.
//

#import "SNVRCommand.h"

@interface LoginCommand : SNVRCommand

@property (copy) void (^successBlock)(LoginCommand *command, NSString *token);
@property (copy) void (^failureBlock)(LoginCommand *command, NSError *error);

- (void)loginWithUsername:(NSString *)username password:(NSString *)password success:(void (^)(LoginCommand *command, NSString *token))success failure:(void (^)(LoginCommand *command, NSError *error))failure;

@end

