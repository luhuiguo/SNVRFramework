//
//  Channel.h
//  Camera
//
//  Created by 陆惠国 on 13-3-25.
//  Copyright (c) 2013年 LuHuiguo. All rights reserved.
//
#import <UIKit/UIKit.h>
#import <Foundation/Foundation.h>

#import "PreviewCommand.h"

#import "SNVRContext.h"
#import "VideoExtractor.h"


@interface SNVRChannel : NSObject


@property (nonatomic, assign) NSInteger code;
@property (nonatomic, copy) NSString* name;
@property (nonatomic, strong) PreviewCommand *previewCommand;
@property (nonatomic, strong) VideoExtractor *videoExtractor;

@property (copy) void (^successBlock)(SNVRChannel *channel);
@property (copy) void (^failureBlock)(SNVRChannel *channel, NSError *error);
@property (copy) void (^extractorBlock)(SNVRChannel *channel);


- (void)previewWithContext:(SNVRContext *)context Stream:(NSUInteger)stream success:(void (^)(SNVRChannel *channel))success failure:(void (^)(SNVRChannel *channel, NSError *error)) failure extractor:(void (^)(SNVRChannel *channel))extractor;


- (void)stopPreview;


@end
