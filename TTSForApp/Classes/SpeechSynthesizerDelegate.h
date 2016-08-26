//
//  SpeechSynthesizerDelegate.h
//  SpeechSynthesizer
//
//  Created by 滴滴 on 16-08-10.
//  Copyright (c) 2016年 滴滴. All rights reserved.
//

#import <Foundation/Foundation.h>
@class SpeechSynthesizer;

@protocol SpeechSynthesizerDelegate <NSObject>

/**
 * @brief 合成器开始工作
 *
 * @param speechSynthesizer 合成器对象
 */
@optional
- (void)synthesizerStartWorking:(SpeechSynthesizer *)speechSynthesizer;

/**
 * @brief 合成器开始朗读
 *
 * @param speechSynthesizer 合成器对象
 */
- (void)synthesizerSpeechStart:(SpeechSynthesizer *)speechSynthesizer;

/**
 * @brief 新的语音数据已经合成
 *
 * @param speechSynthesizer 合成器对象
 * @param data 语音数据
 * @param lastDataFlag 是否是最后一段数据
 */
- (void)synthesizerNewDataArrived:(SpeechSynthesizer *)speechSynthesizer data:(NSData *)newData isLastData:(BOOL)lastDataFlag;

/**
 * @brief 缓冲进度已更新
 *
 * @param speechSynthesizer 合成器对象
 * @param progress 已缓冲的进度，取值范围[0.0, 1.0]
 */
- (void)synthesizerBufferProgressChanged:(SpeechSynthesizer *)speechSynthesizer progress:(float)newProgress;

/**
 * @brief 播放进度已更新
 *
 * @param speechSynthesizer 合成器对象
 * @param progress 已播放进度，取值范围[0.0, 1.0]
 */
- (void)synthesizerSpeechProgressChanged:(SpeechSynthesizer *)speechSynthesizer progress:(float)newProgress;

/**
 * @brief 当前已缓冲到的文本长度已更新
 *
 * @param speechSynthesizer 合成器对象
 * @param length 以缓冲到的文本偏移量，取值范围[0, [text length]]
 */
- (void)synthesizerTextBufferedLengthChanged:(SpeechSynthesizer *)speechSynthesizer length:(int)newLength;

/**
 * @brief Gives an estimation about how many characters have been spoken so far.
 *
 * @param speechSynthesizer 合成器对象
 * @param length 以缓冲到的文本偏移量，取值范围[0, [text length]]
 */
- (void)synthesizerTextSpeakLengthChanged:(SpeechSynthesizer *)speechSynthesizer length:(int)newLength;

/**
 * @brief 朗读已暂停
 *
 * @param speechSynthesizer 合成器对象
 */
- (void)synthesizerSpeechDidPaused:(SpeechSynthesizer *)speechSynthesizer;

/**
 * @brief 朗读已继续
 *
 * @param speechSynthesizer 合成器对象
 */
- (void)synthesizerSpeechDidResumed:(SpeechSynthesizer *)speechSynthesizer;

/**
 * @brief 已取消
 *
 * @param speechSynthesizer 合成器对象
 */
- (void)synthesizerDidCanceled:(SpeechSynthesizer *)speechSynthesizer;

/**
 * @brief 朗读完成
 *
 * @param speechSynthesizer 合成器对象
 */
- (void)synthesizerSpeechDidFinished:(SpeechSynthesizer *)speechSynthesizer;

/**
 * @brief 合成器发生错误
 *
 * @param speechSynthesizer 合成器对象
 * @param error 错误对象
 */
- (void)synthesizerErrorOccurred:(SpeechSynthesizer *)speechSynthesizer error:(NSError *)error;

@end