// ===================================================================================
// NextAI OpenCut - Architecture & Interface Specification
// Copyright (c) 2026 NextAI Technology. All rights reserved.
// Module: libspeechsdk.so / libspeechengine.so (ByteDance AI Lab Speech Engine)
// File: speechsdk_interface.h
// Description: JNI Bridge & Handle Coordinator for ByteDance Speech Engine
// Chú thích song ngữ: English & Vietnamese per Rule 12 AGENTS.md
// ===================================================================================

#pragma once

#include <jni.h>
#include <string>
#include <map>
#include <memory>
#include <mutex>
#include <atomic>

#include "speechsdk_types.h"
#include "speechsdk_options.h"
#include "speechsdk_frontend.h"
#include "speechsdk_fingerprint.h"
#include "speechsdk_asr_engine.h"

namespace NextAI::OpenCut::speechsdk {

/**
 * @brief Bộ điều phối và quản lý handle động cơ tiếng nói ByteDance Speech Engine
 */
class SpeechEngineCoordinator {
public:
    static SpeechEngineCoordinator& getInstance();

    jlong createEngine();
    void destroyEngine(jlong handle);
    ::lab::speech::client::Engine* getEngine(jlong handle);

    static bool runSelfTest();

private:
    SpeechEngineCoordinator() = default;
    ~SpeechEngineCoordinator() = default;

    std::mutex m_registry_mutex;
    std::map<jlong, std::unique_ptr<::lab::speech::client::Engine>> m_engines;
    std::atomic<jlong> m_handle_sequence{1000};
};

} // namespace NextAI::OpenCut::speechsdk

// ===================================================================================
// JNI Exported Functions (Khớp 100% bảng ký hiệu libspeechengine.so)
// ===================================================================================

extern "C" {

JNIEXPORT jstring JNICALL Java_com_bytedance_speech_speechengine_bridge_SpeechEngineBridge_getVersionToNative(
    JNIEnv *env, jobject thiz);

JNIEXPORT jboolean JNICALL Java_com_bytedance_speech_speechengine_bridge_SpeechEngineBridge_isEngineSupportedToNative(
    JNIEnv *env, jobject thiz, jstring engine_name);

JNIEXPORT jlong JNICALL Java_com_bytedance_speech_speechengine_bridge_SpeechEngineBridge_createEngineToNative(
    JNIEnv *env, jobject thiz);

JNIEXPORT void JNICALL Java_com_bytedance_speech_speechengine_bridge_SpeechEngineBridge_destroyEngineToNative(
    JNIEnv *env, jobject thiz, jlong engine_handle);

JNIEXPORT void JNICALL Java_com_bytedance_speech_speechengine_bridge_SpeechEngineBridge_setOptionStringToNative(
    JNIEnv *env, jobject thiz, jlong engine_handle, jstring key, jstring val);

JNIEXPORT void JNICALL Java_com_bytedance_speech_speechengine_bridge_SpeechEngineBridge_setOptionBooleanToNative(
    JNIEnv *env, jobject thiz, jlong engine_handle, jstring key, jboolean val);

JNIEXPORT void JNICALL Java_com_bytedance_speech_speechengine_bridge_SpeechEngineBridge_setOptionIntToNative(
    JNIEnv *env, jobject thiz, jlong engine_handle, jstring key, jint val);

JNIEXPORT void JNICALL Java_com_bytedance_speech_speechengine_bridge_SpeechEngineBridge_setOptionDoubleToNative(
    JNIEnv *env, jobject thiz, jlong engine_handle, jstring key, jdouble val);

JNIEXPORT jint JNICALL Java_com_bytedance_speech_speechengine_bridge_SpeechEngineBridge_initEngineToNative(
    JNIEnv *env, jobject thiz, jlong engine_handle);

JNIEXPORT jint JNICALL Java_com_bytedance_speech_speechengine_bridge_SpeechEngineBridge_sendDirectiveToNative(
    JNIEnv *env, jobject thiz, jlong engine_handle, jint directive_id, jstring directive_json);

JNIEXPORT jint JNICALL Java_com_bytedance_speech_speechengine_bridge_SpeechEngineBridge_feedAudioToNative(
    JNIEnv *env, jobject thiz, jlong engine_handle, jbyteArray audio_bytes, jint sample_count);

JNIEXPORT void JNICALL Java_com_bytedance_speech_speechengine_bridge_SpeechEngineBridge_resetEngineToNative(
    JNIEnv *env, jobject thiz, jlong engine_handle);

JNIEXPORT jint JNICALL Java_com_bytedance_speech_speechengine_bridge_SpeechEngineBridge_processAudioToNative(
    JNIEnv *env, jobject thiz, jlong engine_handle, jbyteArray audio_bytes, jint sample_count, jboolean is_last);

JNIEXPORT jstring JNICALL Java_com_bytedance_speech_speechengine_bridge_SpeechEngineBridge_fetchResultToNative(
    JNIEnv *env, jobject thiz, jlong engine_handle, jint result_type);

JNIEXPORT jstring JNICALL Java_com_bytedance_speech_speechengine_bridge_SpeechEngineBridge_fetchStringResultToNative(
    JNIEnv *env, jobject thiz, jlong engine_handle);

JNIEXPORT jint JNICALL JNI_OnLoad(JavaVM *vm, void *reserved);

} // extern "C"
