//
//  SNVRCommand.h
//  Camera
//
//  Created by 陆惠国 on 13-3-22.
//  Copyright (c) 2013年 LuHuiguo. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "GCDAsyncSocket.h"
#import "SNVR.h"

@interface SNVRCommand : NSObject<GCDAsyncSocketDelegate>
{
    dispatch_queue_t _commandQueue;
    void *_commandQueueKey;
    
    dispatch_queue_t _successCallbackQueue;
    dispatch_queue_t _failureCallbackQueue;
    
    NSString *_host;
    UInt16 _port;
//    NSString* _token;
    BOOL _executed;
    GCDAsyncSocket *_socket;
    
}

@property (readonly) GCDAsyncSocket *socket;

@property (readonly) dispatch_queue_t commandQueue;
@property (readonly) void *commandQueueKey;

@property (nonatomic, assign) dispatch_queue_t successCallbackQueue;
@property (nonatomic, assign) dispatch_queue_t failureCallbackQueue;

@property (nonatomic, copy) NSString *host;
@property (nonatomic) UInt16 port;
@property (nonatomic) BOOL executed;

- (id)initWithHost:(NSString *)host port:(UInt16)port;
- (id)initWithDispatchQueue:(dispatch_queue_t)queue;
- (id)init;

- (BOOL)connect:(NSError **)errPtr;
- (void)disconnect;

- (void)sendWithHead:(NSData*)head body:(NSData*)body;

- (void)sendLogin:(SVLoginRequest)request;
- (void)sendLogout:(SVLogoutRequest)request;
- (void)sendChannel:(SVChannelRequest)request;
- (void)sendPreview:(SVPreviewRequest)request;
- (void)sendPtz:(SVPtzRequest)request;
- (void)sendSwitch:(SVSwitchRequest)request;

- (void)recvLogin:(SVLoginResponse)response;
- (void)recvLogout;
- (void)recvChannel:(SVChannelResponse)response;
- (void)recvPreview:(SVPreviewResponse)response;
- (void)recvPreviewData:(NSData*)data;
- (void)recvPtz:(SVPtzResponse)response;


- (NSString *)commandName;

@end


