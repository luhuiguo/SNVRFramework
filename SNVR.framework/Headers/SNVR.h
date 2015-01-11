//
//  SNVRProcotol.h
//  Camera
//
//  Created by 陆惠国 on 13-3-19.
//  Copyright (c) 2013年 LuHuiguo. All rights reserved.
//

#import "DDLog.h"
#if DEBUG
static const int ddLogLevel = LOG_FLAG_INFO;
#else
static const int ddLogLevel = LOG_LEVEL_WARN;
#endif

#define TIMEOUT_CONNECT            10
#define TIMEOUT_SNVR_WRITE         -1
#define TIMEOUT_SNVR_READ_START    10
#define TIMEOUT_SNVR_READ_STREAM   20


#define TAG_SNVR_WRITE               0
#define TAG_SNVR_READ_HEADER         1

#define CMD_LOGIN_REQUEST       0x00010001
#define CMD_LOGIN_RESPONSE      0x80010001
#define CMD_LOGOUT_REQUEST      0x00010003
#define CMD_LOGOUT_RESPONSE     0x80010003
#define CMD_CHANNEL_REQUEST     0x00010004
#define CMD_CHANNEL_RESPONSE    0x80010004
#define CMD_PREVIEW_REQUEST     0x00050101
#define CMD_PREVIEW_RESPONSE    0x80050101
#define CMD_PREVIEW_TRANSFER    0x80050102
#define CMD_PTZ_REQUEST         0x00090002
#define CMD_PTZ_RESPONSE        0x80090001
#define CMD_SWITCH_REQUEST      0x00050103


#define SNVRErrorDomain       @"SNVRErrorDomain"

enum SNVRErrorCode
{
    SNVRConnectFailed = 1,
    SNVRLoginFailed,
    SNVRChannelFailed,
    SNVRPreviewFailed,
    SNVRPtzFailed,
    
    SNVRInvalidPacket,
    SNVRNotVideoPacket,
    SNVRUnsupportedCodec,
    SNVROpenDecoderFailed,
    SNVRWaitKeyFrame,
    SNVRVideoDecodeFailed,
    
};
typedef enum SNVRErrorCode SNVRErrorCode;

enum PTZControl
{
    PTZ_UP = 12, //上
    PTZ_DOWN = 16, //下
    PTZ_LEFT = 18, //左
    PTZ_RIGHT= 14, //右
    PTZ_IRISOPEN = 7, //光圈开
    PTZ_IRISCLOSE = 6, //光圈关
    PTZ_FOCUSFAR = 9, //焦距远
    PTZ_FOCUSNEAR = 8, //焦距近
    PTZ_ZOOMIN = 11, //聚焦大
    PTZ_ZOOMOUT = 10, //聚焦小
    PTZ_AUTOSCAN = 28, //自动
    PTZ_CLEAR = 24, //雨刷
    PTZ_LIGHT = 23, //灯光
    PTZ_POWER = 25, //电源
    PTZ_AUX = 27, //备用辅助
    
    PTZ_SETPRESET = 21, //设置预置点
    PTZ_GOTOPRESET = 20, //调用预置点
    PTZ_CLEATPRESET = 22, //删除预置点
    
    PTZ_LEFTUP = 19, //左上
    PTZ_RIGHTUP = 13, //右上
    PTZ_LEFTDOWN = 17, //左下
    PTZ_RIGHTDOWN = 15, //右下
};

typedef enum PTZControl PTZControl;

typedef struct {
    UInt32 size;
    UInt32 type;
    UInt32 network;
    UInt32 source;
    UInt32 target;
} SVHeader;

typedef struct {
    
    char username[20];
    char password[40];
    UInt32 version;
    char reserved[24];
} SVLoginRequest;

typedef struct {
    SInt32 status;
    char token[128];
    char userinfo[128];
} SVLoginResponse;

typedef struct {
    char token[128];
} SVLogoutRequest;

typedef struct {
} SVLogoutResponse;

typedef struct {
    char token[128];
} SVChannelRequest;

typedef struct {
    SInt32 status;
    char channels[4096];
} SVChannelResponse;

#pragma pack(push)
#pragma pack(2)
typedef struct {
    char token[128];
    UInt64 device;
    UInt16 channel;
    SInt32 stream;
} SVPreviewRequest;
#pragma pack(pop)

typedef struct {
    SInt32 status;
    SInt32 brightness;
    SInt32 contrast;
    SInt32 saturation;
    SInt32 hue;
} SVPreviewResponse;

typedef struct {
    SInt32 type;
    SInt32 size;
} SVPreviewTransfer;

typedef struct {
    char token[128];
    UInt64 device;
    UInt16 channel;
    UInt8 commad;
    UInt8 option;
} SVPtzRequest;

typedef struct {
    SInt32 status;
} SVPtzResponse;

typedef struct {
    char token[128];
    UInt64 device;
    UInt16 channel;
    SInt32 oldStream;
    SInt32 newStream;
} SVSwitchRequest;

#define MAGIC_ID1               0x11AFCAA9
#define MAGIC_ID2               0xEE102FBD

#define STREAM_TYPE_UNDEFINED    0
#define STREAM_TYPE_MJPEG        1
#define STREAM_TYPE_MPEG2        2
#define STREAM_TYPE_MPEG4        3
#define STREAM_TYPE_H264         4

#define STREAM_TYPE_PCM         128
#define STREAM_TYPE_G711_ULAW   129
#define STREAM_TYPE_G711_ALAW   130
#define STREAM_TYPE_G726        131
#define STREAM_TYPE_G722        132
#define STREAM_TYPE_ADPCM       133
#define STREAM_TYPE_MP3         134
#define STREAM_TYPE_G729        135
#define STREAM_TYPE_G721        136
#define STREAM_TYPE_AAC         137

#define SUBSTREAM_TYPE_UNDEFINED        0
#define SUBSTREAM_TYPE_8000HZ8BITS      1
#define SUBSTREAM_TYPE_8000HZ16BITS     2
#define SUBSTREAM_TYPE_16000HZ8BITS     3
#define SUBSTREAM_TYPE_16000HZ16BITS    4

#define FRAME_TYPE_UNDEFINED    0
#define FRAME_TYPE_JPEG         1
#define FRAME_TYPE_I            2
#define FRAME_TYPE_P            3
#define FRAME_TYPE_B            4
#define FRAME_TYPE_A            5
#define FRAME_TYPE_H264_SLICE   0x11
#define FRAME_TYPE_H264_IDR     0x15
#define FRAME_TYPE_H264_SPS     0x17
#define FRAME_TYPE_H264_PPS     0x18


typedef struct {
    UInt32 size;
    UInt32 magic1;
    UInt32 magic2;
    UInt32 length;
    UInt32 width;
    UInt32 height;
    UInt8 streamType;
    UInt8 subStreamType;
    UInt8 frameType;
    UInt8 reserved;
    UInt8 reserved1[2] ;
    UInt8 audioChannelCount;
    UInt8 audioBits;
    UInt32 timeStamp1;
    UInt32 timeStamp2;
    UInt32 audioSamples;
    UInt32 reserved2;
    UInt8 OSDLineCount;
    UInt8 OSDLineWidth;
    UInt8 reserved3[14];
} SVStreamHeader;


typedef struct {
    short x;
    short y;
    char data [40];
} SVStreamOSDLine;
