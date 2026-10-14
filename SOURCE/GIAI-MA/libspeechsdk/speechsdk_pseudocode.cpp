// ===================================================================================
// NextAI OpenCut - Architecture & Interface Specification
// Copyright (c) 2026 NextAI Technology. All rights reserved.
// Module: libspeechsdk.so / libspeechengine.so (ByteDance AI Lab Speech Engine)
// File: speechsdk_pseudocode.cpp
// Description: Full implementation of SpeechEngineCoordinator, JNI Bridge & 10-point Self-Test
// Chú thích song ngữ: English & Vietnamese per Rule 12 AGENTS.md
// ===================================================================================

#include "speechsdk_interface.h"
#include <iostream>
#include <cmath>
#include <cassert>

namespace NextAI::OpenCut::speechsdk {

SpeechEngineCoordinator& SpeechEngineCoordinator::getInstance() {
    static SpeechEngineCoordinator instance;
    return instance;
}

jlong SpeechEngineCoordinator::createEngine() {
    std::lock_guard<std::mutex> lock(m_registry_mutex);
    jlong handle = m_handle_sequence.fetch_add(1);
    m_engines[handle] = std::make_unique<::lab::speech::client::Engine>();
    return handle;
}

void SpeechEngineCoordinator::destroyEngine(jlong handle) {
    std::lock_guard<std::mutex> lock(m_registry_mutex);
    m_engines.erase(handle);
}

::lab::speech::client::Engine* SpeechEngineCoordinator::getEngine(jlong handle) {
    std::lock_guard<std::mutex> lock(m_registry_mutex);
    auto it = m_engines.find(handle);
    return (it != m_engines.end()) ? it->second.get() : nullptr;
}

bool SpeechEngineCoordinator::runSelfTest() {
    auto& coord = getInstance();

    // 1. Kiểm tra tạo Engine và cấp phát Handle duy nhất
    jlong h1 = coord.createEngine();
    jlong h2 = coord.createEngine();
    if (h1 == 0 || h2 == 0 || h1 == h2) return false;

    auto* engine1 = coord.getEngine(h1);
    if (!engine1) return false;

    // 2. Kiểm tra thiết lập tùy chọn (Options)
    engine1->getOptions()->setString(::lab::speech::client::OptionsKey::APP_ID_STRING, "opencut_test");
    engine1->getOptions()->setInt(::lab::speech::client::OptionsKey::SAMPLE_RATE_INT, 16000);
    if (engine1->getOptions()->getString(::lab::speech::client::OptionsKey::APP_ID_STRING) != "opencut_test") return false;

    // 3. Kiểm tra khởi tạo Engine (Init)
    if (!engine1->Init(engine1->getOptions())) return false;

    // 4. Kiểm tra gửi chỉ lệnh START
    if (engine1->SendDirective(static_cast<int32_t>(::lab::speech::client::DirectiveId::START_ENGINE), "{}") != 0) return false;
    if (!engine1->isRunning()) return false;

    // 5. Kiểm tra nạp luồng âm thanh PCM (Feed)
    std::vector<int16_t> pcm(16000, 10000); // 1 giây âm thanh
    int32_t frames = engine1->Feed(pcm.data(), pcm.size());
    if (frames <= 0) return false;

    // 6. Kiểm tra gửi chỉ lệnh STOP
    if (engine1->SendDirective(static_cast<int32_t>(::lab::speech::client::DirectiveId::STOP_ENGINE), "{}") != 0) return false;
    if (engine1->isRunning()) return false;

    // 7. Kiểm tra trích xuất kết quả nhận dạng JSON (fetchResult)
    std::string res = engine1->fetchResult();
    if (res.find("\"words\":[") == std::string::npos) return false;

    // 8. Kiểm tra hủy Engine
    coord.destroyEngine(h1);
    if (coord.getEngine(h1) != nullptr) return false;
    coord.destroyEngine(h2);

    // 9. Kiểm tra tính toàn vẹn của Frontend và Fingerprint
    if (!::lab::speech::client::frontware::AcousticFrontend::runSelfTest()) return false;
    if (!::lab::speech::client::middleware::FingerPrintProcessor::runSelfTest()) return false;

    // 10. Kiểm tra phiên bản động cơ
    if (::lab::speech::client::Engine::GetVersion().empty()) return false;

    return true;
}

} // namespace NextAI::OpenCut::speechsdk

// ===================================================================================
// JNI Bridge Implementation
// ===================================================================================

extern "C" {

JNIEXPORT jstring JNICALL Java_com_bytedance_speech_speechengine_bridge_SpeechEngineBridge_getVersionToNative(
    JNIEnv *env, jobject thiz) {
    std::string ver = ::lab::speech::client::Engine::GetVersion();
    return env->NewStringUTF(ver.c_str());
}

JNIEXPORT jboolean JNICALL Java_com_bytedance_speech_speechengine_bridge_SpeechEngineBridge_isEngineSupportedToNative(
    JNIEnv *env, jobject thiz, jstring engine_name) {
    if (!engine_name) return JNI_FALSE;
    const char* str = env->GetStringUTFChars(engine_name, nullptr);
    bool supported = false;
    if (str) {
        std::string s(str);
        if (s == "asr" || s == "tts" || s == "coversong" || s == "voiceconv") {
            supported = true;
        }
        env->ReleaseStringUTFChars(engine_name, str);
    }
    return supported ? JNI_TRUE : JNI_FALSE;
}

JNIEXPORT jlong JNICALL Java_com_bytedance_speech_speechengine_bridge_SpeechEngineBridge_createEngineToNative(
    JNIEnv *env, jobject thiz) {
    return NextAI::OpenCut::speechsdk::SpeechEngineCoordinator::getInstance().createEngine();
}

JNIEXPORT void JNICALL Java_com_bytedance_speech_speechengine_bridge_SpeechEngineBridge_destroyEngineToNative(
    JNIEnv *env, jobject thiz, jlong engine_handle) {
    NextAI::OpenCut::speechsdk::SpeechEngineCoordinator::getInstance().destroyEngine(engine_handle);
}

JNIEXPORT void JNICALL Java_com_bytedance_speech_speechengine_bridge_SpeechEngineBridge_setOptionStringToNative(
    JNIEnv *env, jobject thiz, jlong engine_handle, jstring key, jstring val) {
    auto* engine = NextAI::OpenCut::speechsdk::SpeechEngineCoordinator::getInstance().getEngine(engine_handle);
    if (!engine || !key || !val) return;

    const char* k_str = env->GetStringUTFChars(key, nullptr);
    const char* v_str = env->GetStringUTFChars(val, nullptr);
    if (k_str && v_str) {
        engine->getOptions()->setString(k_str, v_str);
    }
    if (k_str) env->ReleaseStringUTFChars(key, k_str);
    if (v_str) env->ReleaseStringUTFChars(val, v_str);
}

JNIEXPORT void JNICALL Java_com_bytedance_speech_speechengine_bridge_SpeechEngineBridge_setOptionBooleanToNative(
    JNIEnv *env, jobject thiz, jlong engine_handle, jstring key, jboolean val) {
    auto* engine = NextAI::OpenCut::speechsdk::SpeechEngineCoordinator::getInstance().getEngine(engine_handle);
    if (!engine || !key) return;

    const char* k_str = env->GetStringUTFChars(key, nullptr);
    if (k_str) {
        engine->getOptions()->setBool(k_str, val == JNI_TRUE);
        env->ReleaseStringUTFChars(key, k_str);
    }
}

JNIEXPORT void JNICALL Java_com_bytedance_speech_speechengine_bridge_SpeechEngineBridge_setOptionIntToNative(
    JNIEnv *env, jobject thiz, jlong engine_handle, jstring key, jint val) {
    auto* engine = NextAI::OpenCut::speechsdk::SpeechEngineCoordinator::getInstance().getEngine(engine_handle);
    if (!engine || !key) return;

    const char* k_str = env->GetStringUTFChars(key, nullptr);
    if (k_str) {
        engine->getOptions()->setInt(k_str, val);
        env->ReleaseStringUTFChars(key, k_str);
    }
}

JNIEXPORT void JNICALL Java_com_bytedance_speech_speechengine_bridge_SpeechEngineBridge_setOptionDoubleToNative(
    JNIEnv *env, jobject thiz, jlong engine_handle, jstring key, jdouble val) {
    auto* engine = NextAI::OpenCut::speechsdk::SpeechEngineCoordinator::getInstance().getEngine(engine_handle);
    if (!engine || !key) return;

    const char* k_str = env->GetStringUTFChars(key, nullptr);
    if (k_str) {
        engine->getOptions()->setDouble(k_str, val);
        env->ReleaseStringUTFChars(key, k_str);
    }
}

JNIEXPORT jint JNICALL Java_com_bytedance_speech_speechengine_bridge_SpeechEngineBridge_initEngineToNative(
    JNIEnv *env, jobject thiz, jlong engine_handle) {
    auto* engine = NextAI::OpenCut::speechsdk::SpeechEngineCoordinator::getInstance().getEngine(engine_handle);
    if (!engine) return -1;
    return engine->Init(engine->getOptions()) ? 0 : -1;
}

JNIEXPORT jint JNICALL Java_com_bytedance_speech_speechengine_bridge_SpeechEngineBridge_sendDirectiveToNative(
    JNIEnv *env, jobject thiz, jlong engine_handle, jint directive_id, jstring directive_json) {
    auto* engine = NextAI::OpenCut::speechsdk::SpeechEngineCoordinator::getInstance().getEngine(engine_handle);
    if (!engine) return -1;

    std::string json_str = "{}";
    if (directive_json) {
        const char* chars = env->GetStringUTFChars(directive_json, nullptr);
        if (chars) {
            json_str = chars;
            env->ReleaseStringUTFChars(directive_json, chars);
        }
    }
    return engine->SendDirective(directive_id, json_str);
}

JNIEXPORT jint JNICALL Java_com_bytedance_speech_speechengine_bridge_SpeechEngineBridge_feedAudioToNative(
    JNIEnv *env, jobject thiz, jlong engine_handle, jbyteArray audio_bytes, jint sample_count) {
    auto* engine = NextAI::OpenCut::speechsdk::SpeechEngineCoordinator::getInstance().getEngine(engine_handle);
    if (!engine || !audio_bytes || sample_count <= 0) return -1;

    jbyte* bytes = env->GetByteArrayElements(audio_bytes, nullptr);
    int32_t ret = -1;
    if (bytes) {
        const int16_t* pcm_samples = reinterpret_cast<const int16_t*>(bytes);
        ret = engine->Feed(pcm_samples, sample_count);
        env->ReleaseByteArrayElements(audio_bytes, bytes, JNI_ABORT);
    }
    return ret;
}

JNIEXPORT void JNICALL Java_com_bytedance_speech_speechengine_bridge_SpeechEngineBridge_resetEngineToNative(
    JNIEnv *env, jobject thiz, jlong engine_handle) {
    auto* engine = NextAI::OpenCut::speechsdk::SpeechEngineCoordinator::getInstance().getEngine(engine_handle);
    if (engine) engine->Reset();
}

JNIEXPORT jint JNICALL Java_com_bytedance_speech_speechengine_bridge_SpeechEngineBridge_processAudioToNative(
    JNIEnv *env, jobject thiz, jlong engine_handle, jbyteArray audio_bytes, jint sample_count, jboolean is_last) {
    auto* engine = NextAI::OpenCut::speechsdk::SpeechEngineCoordinator::getInstance().getEngine(engine_handle);
    if (!engine || !audio_bytes || sample_count <= 0) return -1;

    jbyte* bytes = env->GetByteArrayElements(audio_bytes, nullptr);
    int32_t ret = -1;
    if (bytes) {
        const int16_t* pcm_samples = reinterpret_cast<const int16_t*>(bytes);
        ret = engine->Process(pcm_samples, sample_count, is_last == JNI_TRUE);
        env->ReleaseByteArrayElements(audio_bytes, bytes, JNI_ABORT);
    }
    return ret;
}

JNIEXPORT jstring JNICALL Java_com_bytedance_speech_speechengine_bridge_SpeechEngineBridge_fetchResultToNative(
    JNIEnv *env, jobject thiz, jlong engine_handle, jint result_type) {
    auto* engine = NextAI::OpenCut::speechsdk::SpeechEngineCoordinator::getInstance().getEngine(engine_handle);
    if (!engine) return env->NewStringUTF("{}");
    std::string res = engine->fetchResult(result_type);
    return env->NewStringUTF(res.c_str());
}

JNIEXPORT jstring JNICALL Java_com_bytedance_speech_speechengine_bridge_SpeechEngineBridge_fetchStringResultToNative(
    JNIEnv *env, jobject thiz, jlong engine_handle) {
    return Java_com_bytedance_speech_speechengine_bridge_SpeechEngineBridge_fetchResultToNative(env, thiz, engine_handle, 0);
}

JNIEXPORT jint JNICALL JNI_OnLoad(JavaVM *vm, void *reserved) {
    return JNI_VERSION_1_6;
}

} // extern "C"
