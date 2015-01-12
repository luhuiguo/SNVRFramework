//
//  PreviewCommand.h
//  Camera
//
//  Created by 陆惠国 on 13-3-22.
//  Copyright (c) 2013年 LuHuiguo. All rights reserved.
//

#import "SNVRCommand.h"


@interface PreviewCommand : SNVRCommand
@property (copy) void (^successBlock)(PreviewCommand *command, SVPreviewResponse *response);
@property (copy) void (^failureBlock)(PreviewCommand *command, NSError *error);
@property (copy) void (^transferBlock)(PreviewCommand *command, NSData *data);

@property (nonatomic, assign) dispatch_queue_t transferQueue;

- (void)previewWithToken:(NSString *)token channel:(NSUInteger)channel stream:(NSUInteger)stream  success:(void (^)(PreviewCommand *command, SVPreviewResponse *response))success failure:(void (^)(PreviewCommand *command, NSError *error)) failure transfer:(void (^)(PreviewCommand *command,NSData *data))transfer;

@end
