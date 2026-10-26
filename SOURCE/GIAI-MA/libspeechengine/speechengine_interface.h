// ============================================================================
// RECONSTRUCTED C++ HEADER: speechengine_interface.h
// Target Library: libspeechengine.so (18,256 bytes, ELF64 AArch64)
// Module: All 18 Exported JNI Entry Points (.dynsym [037]..[054]) & Facade
// Reference Disassembly (.text @ 0x001ef0..0x003238):
//   - [042] JNI_OnLoad                                                  @ 0x001ef0
//   - [037] SpeechEngineBridge_getVersionToNative                       @ 0x001f70
//   - [048] SpeechEngineBridge_isEngineSupportedToNative                @ 0x002004
//   - [047] SpeechEngineBridge_createEngineToNative                     @ 0x002068
//   - [045] SpeechEngineBridge_destroyEngineToNative                    @ 0x002238
//   - [044] SpeechEngineBridge_setOptionStringToNative                  @ 0x0022b0
//   - [051] SpeechEngineBridge_setOptionBooleanToNative                 @ 0x002498
//   - [039] SpeechEngineBridge_setOptionIntToNative                     @ 0x0025d4
//   - [052] SpeechEngineBridge_setOptionDoubleToNative                  @ 0x002708
//   - [053] SpeechEngineBridge_initEngineToNative                       @ 0x00283c
//   - [054] SpeechEngineBridge_sendDirectiveToNative                    @ 0x002900
//   - [038] SpeechEngineBridge_feedAudioToNative                        @ 0x002a58
//   - [043] SpeechEngineBridge_resetEngineToNative                      @ 0x002b00
//   - [049] SpeechEngineBridge_processAudioToNative                     @ 0x002b44
//   - [046] SpeechEngineBridge_fetchResultToNative                      @ 0x002bf8
//   - [040] SpeechEngineBridge_fetchStringResultToNative                @ 0x002d14
//   - [041] SpeechLogTracker_getInstanceToNative                        @ 0x00322c
//   - [050] SpeechLogTracker_writeLogToNative                           @ 0x003234
// ============================================================================
// Tệp tiêu đề khai báo toàn bộ 18 điểm nhập JNI xuất xưởng (`.dynsym [037]..[054]`)
// của `libspeechengine.so` và lớp mặt tiền kiểm thử `SpeechengineEngine`.
// ============================================================================

#pragma once

#include "speechengine_types.h"
#include "speechengine_sdk_client.h"
#include "speechengine_jni_bridge.h"
#include <cstdint>
#include <string>
#include <vector>

// ============================================================================
// 1. STANDALONE C++/JNI COMPATIBLE HANDLE TYPES
// Kiểu tương thích JNI phục vụ biên dịch độc lập và kết nối Android NDK
// ============================================================================
namespace speechengine::jni {

struct SimulatedByteArray {
    std::vector<uint8_t> bytes;
};

} // namespace speechengine::jni

extern "C" {

// [042] 0x001ef0 (size 128 B)
int32_t JNI_OnLoad(void* vm, void* reserved);

// [037] 0x001f70 (size 148 B)
const char* Java_com_bytedance_speech_speechengine_bridge_SpeechEngineBridge_getVersionToNative(
    void* env, void* thiz);

// [048] 0x002004 (size 100 B)
uint8_t Java_com_bytedance_speech_speechengine_bridge_SpeechEngineBridge_isEngineSupportedToNative(
    void* env, void* thiz, const char* engine_name);

// [047] 0x002068 (size 464 B)
int64_t Java_com_bytedance_speech_speechengine_bridge_SpeechEngineBridge_createEngineToNative(
    void* env, void* thiz, void* jcallback_obj, void* jasset_mgr);

// [045] 0x002238 (size 120 B)
void Java_com_bytedance_speech_speechengine_bridge_SpeechEngineBridge_destroyEngineToNative(
    void* env, void* thiz, int64_t handle);

// [044] 0x0022b0 (size 488 B)
void Java_com_bytedance_speech_speechengine_bridge_SpeechEngineBridge_setOptionStringToNative(
    void* env, void* thiz, int64_t handle, const char* key, const char* val);

// [051] 0x002498 (size 316 B)
void Java_com_bytedance_speech_speechengine_bridge_SpeechEngineBridge_setOptionBooleanToNative(
    void* env, void* thiz, int64_t handle, const char* key, uint8_t val);

// [039] 0x0025d4 (size 308 B)
void Java_com_bytedance_speech_speechengine_bridge_SpeechEngineBridge_setOptionIntToNative(
    void* env, void* thiz, int64_t handle, const char* key, int32_t val);

// [052] 0x002708 (size 308 B)
void Java_com_bytedance_speech_speechengine_bridge_SpeechEngineBridge_setOptionDoubleToNative(
    void* env, void* thiz, int64_t handle, const char* key, double val);

// [053] 0x00283c (size 196 B)
int32_t Java_com_bytedance_speech_speechengine_bridge_SpeechEngineBridge_initEngineToNative(
    void* env, void* thiz, int64_t handle);

// [054] 0x002900 (size 344 B)
int32_t Java_com_bytedance_speech_speechengine_bridge_SpeechEngineBridge_sendDirectiveToNative(
    void* env, void* thiz, int64_t handle, int32_t directive_type, const char* data);

// [038] 0x002a58 (size 168 B)
int32_t Java_com_bytedance_speech_speechengine_bridge_SpeechEngineBridge_feedAudioToNative(
    void* env, void* thiz, int64_t handle, const uint8_t* audio_bytes, int32_t byte_len);

// [043] 0x002b00 (size 68 B)
int32_t Java_com_bytedance_speech_speechengine_bridge_SpeechEngineBridge_resetEngineToNative(
    void* env, void* thiz, int64_t handle);

// [049] 0x002b44 (size 180 B)
int32_t Java_com_bytedance_speech_speechengine_bridge_SpeechEngineBridge_processAudioToNative(
    void* env, void* thiz, int64_t handle, const uint8_t* audio_bytes, int32_t byte_len, uint8_t is_last);

// [046] 0x002bf8 (size 284 B)
int32_t Java_com_bytedance_speech_speechengine_bridge_SpeechEngineBridge_fetchResultToNative(
    void* env, void* thiz, int64_t handle, int32_t result_type, speechengine::jni::SimulatedByteArray* out_buffer);

// [040] 0x002d14 (size 188 B)
std::string Java_com_bytedance_speech_speechengine_bridge_SpeechEngineBridge_fetchStringResultToNative(
    void* env, void* thiz, int64_t handle, int32_t result_type);

// [041] 0x00322c (size 8 B: `mov x0, #-1; ret`)
int64_t Java_com_bytedance_speech_speechengine_log_1tracker_SpeechLogTracker_getInstanceToNative(
    void* env, void* thiz);

// [050] 0x003234 (size 4 B: `ret`)
void Java_com_bytedance_speech_speechengine_log_1tracker_SpeechLogTracker_writeLogToNative(
    void* env, void* thiz, int64_t tracker_handle, const char* log_msg);

} // extern "C"

namespace speechengine {

// ============================================================================
// 2. SPEECHENGINE VERIFICATION FACADE
// Lớp mặt tiền kiểm thử toàn diện cho libspeechengine.so
// ============================================================================
class SpeechengineEngine {
public:
    SpeechengineEngine();
    ~SpeechengineEngine();

    bool Initialize();
    bool ExecuteCorePipeline(const uint8_t* input_data, size_t input_size,
                             std::vector<uint8_t>& output_data);
    void Shutdown();

    int64_t nativeHandle() const { return handle_; }
    const std::string& lastJsonResult() const { return last_json_result_; }
    int32_t lastErrorCode() const { return last_err_code_; }

private:
    bool        is_initialized_{false};
    int64_t     handle_{-1LL};
    int         callback_dummy_obj_{0x43424F42}; // 'CBOB'
    std::string last_json_result_{};
    int32_t     last_err_code_{0};
};

} // namespace speechengine
