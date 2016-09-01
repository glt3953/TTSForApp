//
//  SpeechSynthesizer.h
//  SpeechSynthesizer
//
//  Created by guoliting on 16/8/10.
//  Copyright © 2016年 DiDi. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "SpeechSynthesizerDelegate.h"

// 引擎错误
typedef enum EngineError{
    ENGINE_ERROR_OK = 0,
    ENGINE_ERROR_MASK = 10000,
    ENGINE_ERROR_PARTIAL_SYNTH,
    ENGINE_ERROR_CONFIG,
    ENGINE_ERROR_RESOURCE,
    ENGINE_ERROR_HANDLE,
    ENGINE_ERROR_PARMAM,
    ENGINE_ERROR_MEMORY,
    ENGINE_ERROR_MANY_TEXT,
    ENGINE_ERROR_RUN_TIME,
    ENGINE_ERROR_NO_TEXT,
    ENGINE_ERROR_LICENSE,
    ENGINE_ERROR_MALLOC,
    ENGINE_ERROR_ENGINE_NOT_INIT,
    ENGINE_ERROR_SESSION_NOT_INIT,
    ENGINE_ERROR_GET_LICENSE,
    ENGINE_ERROR_LICENSE_EXPIRED,
    ENGINE_ERROR_VERIFY_LICENSE,
    ENGINE_ERROR_INVALID_PARAM,
    ENGINE_ERROR_DATA_FILE_NOT_EXIST,
    ENGINE_ERROR_VERIFY_DATA_FILE,
    ENGINE_ERROR_GET_DATA_FILE_PARAM,
    ENGINE_ERROR_ENCODE_TEXT,
}EngineError;

/** 合成器错误列表 */
enum SpeechSynthError {
    SPEECH_SYNTH_OK = 0,
    /** 匹配包名是否合法 */
    SPEECH_SYNTH_AUTHENTICATION_FAILS = 2000,
    /** 合成器尚未初始化 */
    SPEECH_SYNTH_UNINITIALIZED_ERROR,
    /** 传入文本为空 */
    SPEECH_SYNTH_EMPTY_TEXT_ERROR,
    /** 传入文本过长 */
    SPEECH_SYNTH_TOO_LONG_TEXT_ERROR,
    /** 播放器未开始播放 */
    SPEECH_SYNTH_PLAYER_NOT_STARTED_ERROR
};

/**
 * @brief 合成器参数类型
 */
typedef enum SYNTH_SPEAK_TYPE
{
    SYNTH_SPEAK_CALLBACK = 0,
    SYNTH_SPEAK_VOLUME,
    SYNTH_SPEAK_SPEED,
    SYNTH_SPEAK_SPEECH_MODEL_FILE,
    SYNTH_SPEAK_TEXT_MODEL_FILE,
}SYNTH_SPEAK_TYPE;

// 输出的pcm音频数据类型: 16K（默认）/ 8K
typedef enum AUDIO_FORMAT_RATE
{
    AUDIO_FORMAT_RATE_PCM_16K, // 默认
    AUDIO_FORMAT_RATE_PCM_8K
}AUDIO_FORMAT_RATE;

// 播放器状态
typedef enum AudioPlayerStatus{
    AUDIO_PLAYER_STATUS_NOT_INIT = 0,
    AUDIO_PLAYER_STATUS_IDLE,
    AUDIO_PLAYER_STATUS_PLAYING,
    AUDIO_PLAYER_STATUS_PAUSE,
    AUDIO_PLAYER_STATUS_ERROR
}AudioPlayerStatus;

enum AudioPlayerError {
    AUDIO_PLAYER_FAILED_GET_STREAM_PROPERTIES = 8001,
    AUDIO_PLAYER_FAILED_OPEN_DEVICE,
    AUDIO_PLAYER_FAILED_OPEN_STREAM,
    AUDIO_PLAYER_ALLOC_FAIL,
    AUDIO_PLAYER_BAD_STREAM
};

typedef enum SynthesizerError{
    SYNTH_ERROR_BUSY = 1,
    SYNTH_ERROR_ENGINE_NOT_INIT,
    SYNTH_ERROR_PARAM_INVALID,
    SYNTH_ERROR_CREATE_ENGINE,
}SynthesizerError;

@interface SpeechSynthesizer : NSObject

/** TTS播报的category */
@property (nonatomic, copy) NSString *audioSessionCategory;

/**
 * @brief 初始化语音合成器
 *
 * @param params 初始化参数，主要包括app认证信息
 * @param delegate 代理对象，负责处理合成器各类事件
 *
 * @return 合成器对象
 */
- (SpeechSynthesizer *)initSynthesizer:(NSString *)params
                                 delegate:(id<SpeechSynthesizerDelegate>)delegate;

/**
 * @brief 设置合成参数，如果不设置，则使用默认值
 *
 * @param paramType 参数类型
 * @param value 参数的值
 *
 * @return 错误码
 */
- (NSInteger)setSynthesizeParam:(SYNTH_SPEAK_TYPE)paramType withValue:(NSString *)strValue;

/**
 * @brief 开始文本合成，是否朗读由isSpeak控制，如不播放，开发者需要通过DDSSpeechSynthesizerDelegate的
 *        synthesizerNewDataArrived:data:方法传回的数据自行播放
 *
 * @param text 需要语音合成的文本
 * @param isSpeak 是否朗读
 *
 * @return 错误码
 */
- (int)synthesizeAndSpeak:(NSString *)text isSpeak:(BOOL)isSpeak;

/**
 * @brief 取消本次合成并停止朗读
 */
- (void)cancel;

/**
 * @brief 暂停文本朗读
 *
 * @return 错误码
 */
- (int)pause;

/**
 * @brief 继续文本朗读
 *
 * @return 错误码
 */
- (int)resume;

@end
