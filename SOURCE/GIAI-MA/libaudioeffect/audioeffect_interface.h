// ===================================================================================
// NextAI OpenCut - Architecture & Interface Specification
// Copyright (c) 2026 NextAI Technology. All rights reserved.
// Module: libaudioeffect.so (ByteDance Mammon SAMICore Audio DSP Engine)
// File: audioeffect_interface.h
// Description: SAMICore Host Bridge JNI exports & AudioeffectEngine Coordinator
// ===================================================================================

#pragma once

#include <jni.h>
#include <string>
#include <vector>
#include <memory>
#include <mutex>
#include <unordered_map>

#include "audioeffect_types.h"
#include "audioeffect_biquad.h"
#include "audioeffect_reverb.h"
#include "audioeffect_pitch_tempo.h"
#include "audioeffect_cleaner.h"

namespace NextAI::OpenCut::audioeffect {

// ===================================================================================
// 1. C++ AUDIO EFFECT CORE ENGINE COORDINATOR
// Động cơ điều phối toàn diện chuỗi DSP: Denoise -> Pitch/Tempo -> EQ 10-Band -> Reverb
// ===================================================================================

class AudioeffectEngine {
public:
    AudioeffectEngine(float sample_rate = 44100.0f, int32_t channels = 2);
    virtual ~AudioeffectEngine();

    /// Đặt lại trạng thái toàn bộ chuỗi lọc
    void reset();

    /// Thay đổi tần số lấy mẫu hoạt động
    void setSampleRate(float sample_rate);
    float getSampleRate() const { return m_sample_rate; }

    /// Xử lý khối âm thanh đa kênh (Planar Audio Buffer: data[ch][samples])
    void process(float** data, int32_t num_samples);

    /// Thiết lập thuộc tính theo mã SAMICore Property ID
    void setProperty(int32_t prop_id, float value, int32_t extra_param = 0);

    /// Lấy giá trị thuộc tính theo mã SAMICore Property ID
    float getProperty(int32_t prop_id, int32_t extra_param = 0) const;

    /// Truy cập các module thành phần
    mammon::Equalizer* getEqualizer() { return m_equalizer.get(); }
    mammon::Reverb* getReverb() { return m_reverb.get(); }
    mammon::PitchTempoAdjuster* getPitchTempo() { return m_pitch_tempo.get(); }
    mammon::AudioCleaner* getCleaner() { return m_cleaner.get(); }

    /// Tự kiểm tra tính toàn vẹn toán học và xử lý DSP (8-Point Self-Test Suite)
    static bool runSelfTest();

private:
    float m_sample_rate;
    int32_t m_channels;

    std::unique_ptr<mammon::Equalizer> m_equalizer;
    std::unique_ptr<mammon::Reverb> m_reverb;
    std::unique_ptr<mammon::PitchTempoAdjuster> m_pitch_tempo;
    std::unique_ptr<mammon::AudioCleaner> m_cleaner;

    std::mutex m_engine_mutex;
};

// ===================================================================================
// 2. SAMICORE HOST BRIDGE HANDLE MANAGER
// Trình quản lý đối tượng SAMICore theo định danh con trỏ jlong an toàn luồng
// ===================================================================================

class SAMICoreHandleManager {
public:
    static SAMICoreHandleManager& getInstance();

    jlong createHandle(int32_t identify, float sample_rate = 44100.0f, int32_t channels = 2);
    bool destroyHandle(jlong handle);
    std::shared_ptr<AudioeffectEngine> getEngine(jlong handle);

private:
    SAMICoreHandleManager() : m_next_handle(1001) {}
    std::mutex m_map_mutex;
    jlong m_next_handle;
    std::unordered_map<jlong, std::shared_ptr<AudioeffectEngine>> m_handles;
};

// ===================================================================================
// 3. JNI EXPORTED METHODS (SAMICoreHostBridge 13 functions)
// Danh sách các hàm JNI export trích xuất từ bảng ký hiệu libaudioeffect.so
// ===================================================================================

extern "C" {
    JNIEXPORT jlong JNICALL Java_com_mammon_audiosdk_bridge_SAMICoreHostBridge_Native_1SAMICoreCreateHandleByIdentify(
        JNIEnv *env, jobject thiz, jint identify, jobject param);

    JNIEXPORT jint JNICALL Java_com_mammon_audiosdk_bridge_SAMICoreHostBridge_Native_1SAMICoreDestroyHandle(
        JNIEnv *env, jobject thiz, jlong handle);

    JNIEXPORT jint JNICALL Java_com_mammon_audiosdk_bridge_SAMICoreHostBridge_Native_1SAMICoreProcess(
        JNIEnv *env, jobject thiz, jlong handle, jobject in_block, jobject out_block);

    JNIEXPORT jint JNICALL Java_com_mammon_audiosdk_bridge_SAMICoreHostBridge_Native_1SAMICoreSetProperty(
        JNIEnv *env, jobject thiz, jlong handle, jint prop_id, jobject prop_val);

    JNIEXPORT jobject JNICALL Java_com_mammon_audiosdk_bridge_SAMICoreHostBridge_Native_1SAMICoreGetPropertyById(
        JNIEnv *env, jobject thiz, jlong handle, jint prop_id);

    JNIEXPORT jint JNICALL Java_com_mammon_audiosdk_bridge_SAMICoreHostBridge_Native_1SAMICoreInitContext(
        JNIEnv *env, jobject thiz, jobject context);

    JNIEXPORT jint JNICALL Java_com_mammon_audiosdk_bridge_SAMICoreHostBridge_Native_1SAMICoreReleaseContext(
        JNIEnv *env, jobject thiz);

    JNIEXPORT jint JNICALL Java_com_mammon_audiosdk_bridge_SAMICoreHostBridge_Native_1SAMICoreInitDebugConfig(
        JNIEnv *env, jobject thiz, jstring config);

    JNIEXPORT jint JNICALL Java_com_mammon_audiosdk_bridge_SAMICoreHostBridge_Native_1SAMICoreReleaseDebugConfig(
        JNIEnv *env, jobject thiz);

    JNIEXPORT jint JNICALL Java_com_mammon_audiosdk_bridge_SAMICoreHostBridge_Native_1SAMICoreRegisterLogger(
        JNIEnv *env, jobject thiz, jobject logger);

    JNIEXPORT jint JNICALL Java_com_mammon_audiosdk_bridge_SAMICoreHostBridge_Native_1SAMICoreUnregisterLogger(
        JNIEnv *env, jobject thiz);

    JNIEXPORT jint JNICALL Java_com_mammon_audiosdk_bridge_SAMICoreHostBridge_Native_1SAMICoreRegisterWakeupParamRequestCallback(
        JNIEnv *env, jobject thiz, jobject cb);

    JNIEXPORT jint JNICALL Java_com_mammon_audiosdk_bridge_SAMICoreHostBridge_Native_1SAMICoreRegisterTraceSpanCallback(
        JNIEnv *env, jobject thiz, jobject cb);
}

} // namespace NextAI::OpenCut::audioeffect
