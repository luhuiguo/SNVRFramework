//
//  SNVRContext.h
//  SNVR
//
//  Created by LuHuiguo on 15/1/10.
//  Copyright (c) 2015年 LuHuiguo. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface SNVRContext : NSObject

@property (nonatomic, copy) NSString *host;

@property (nonatomic) UInt16 port;

@property (nonatomic, copy) NSString *token;

- (id)initWithHost:(NSString *)host port:(UInt16)port;
- (id)initWithHost:(NSString *)host port:(UInt16)port token:(NSString *)token;

@end
