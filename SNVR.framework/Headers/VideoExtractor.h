//
//  VideoFrameExtractor.h
//  Camera
//
//  Created by 陆惠国 on 13-4-5.
//  Copyright (c) 2013年 LuHuiguo. All rights reserved.
//
#import <UIKit/UIKit.h>
#import <Foundation/Foundation.h>
#import "libavcodec/avcodec.h"
#import "libswscale/swscale.h"

@interface VideoExtractor : NSObject
{
    
    dispatch_queue_t _extractorQueue;
    void *_extractorQueueKey;
    dispatch_queue_t _successCallbackQueue;
    dispatch_queue_t _failureCallbackQueue;
    
    AVCodecContext *_pCodecCtx;
    AVCodec *_pCodec;
    AVFrame *_pFrame;
    AVPacket _packet;
	AVPicture _picture;
	struct SwsContext *_img_convert_ctx;
    UInt32 _lastWidth;
    UInt32 _lastHeight;
    UInt8 _lastStreamType;
    BOOL _waitKeyFrame;
    CGSize _outputSize;
    
    UIImage *_lastImage;
    
    NSMutableArray* _OSDLines;
    
//    
//    NSLock *_lock;
    
    
}

@property (nonatomic, assign) dispatch_queue_t successCallbackQueue;
@property (nonatomic, assign) dispatch_queue_t failureCallbackQueue;
@property (copy) void (^successBlock)(VideoExtractor *extractor);
@property (copy) void (^failureBlock)(VideoExtractor *extractor, NSError *error);

@property (nonatomic, readonly) UIImage *currentImage;
@property (nonatomic, readonly) NSString *currentOSD;

@property (nonatomic, readonly) CGSize sourceSize;

@property (nonatomic) CGSize outputSize;

- (id)init;

- (id)initWithExtractorQueue:(dispatch_queue_t)extractorQueue extractorQueueKey:(void *)extractorQueueKey;

- (int)processFrameData:(NSData*)data;

- (void)extractFrame:(NSData *)data success:(void (^)(VideoExtractor *extractor))success failure:(void (^)(VideoExtractor *extractor, NSError *error))failure;

- (void)convertFrameToRGB;
- (UIImage *)imageFromAVPicture:(AVPicture)pict width:(int)width height:(int)height;

- (UIImage *)imageFromAVPicture:(AVPicture)pict OSDLines:(NSArray*)lines width:(int)width height:(int)height;


@end


