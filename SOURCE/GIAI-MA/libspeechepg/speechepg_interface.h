// ============================================================================
// RECONSTRUCTED C++ HEADER: speechepg_interface.h
// Target Library: libspeechepg.so (18,256 bytes, ELF64 AArch64)
// Module: All 18 Exported JNI Entry Points (.dynsym [037]..[054]) & Facade
// Reference Disassembly (.text @ 0x001f00..0x003244):
//   - [046] JNI_OnLoad                                                  @ 0x001f00
//   - [042] SpeechLogTracker_getInstanceToNative                        @ 0x0023dc
//   - [052] SpeechLogTracker_writeLogToNative                           @ 0x0023e4
//   - [043] SpeechPluginBridge_getVersionToNative                       @ 0x0023e8
//   - [044] SpeechPluginBridge_isEngineSupportedToNative                @ 0x00247c
//   - [050] SpeechPluginBridge_createEngineToNative                     @ 0x0024e0
//   - [048] SpeechPluginBridge_destroyEngineToNative                    @ 0x0026b0
//   - [047] SpeechPluginBridge_setOptionStringToNative                  @ 0x002728
//   - [053] SpeechPluginBridge_setOptionBooleanToNative                 @ 0x002910
//   - [041] SpeechPluginBridge_setOptionIntToNative                     @ 0x002a4c
//   - [038] SpeechPluginBridge_setOptionDoubleToNative                  @ 0x002b80
//   - [039] SpeechPluginBridge_initEngineToNative                       @ 0x002cb4
//   - [040] SpeechPluginBridge_sendDirectiveToNative                    @ 0x002d78
//   - [051] SpeechPluginBridge_feedAudioToNative                        @ 0x002ed0
//   - [037] SpeechPluginBridge_resetEngineToNative                      @ 0x002f78
//   - [054] SpeechPluginBridge_processAudioToNative                     @ 0x002fbc
//   - [045] SpeechPluginBridge_fetchResultToNative                      @ 0x003070
//   - [049] SpeechPluginBridge_fetchStringResultToNative                @ 0x00318c
// ============================================================================
// Tệp tiêu đề khai báo toàn bộ 18 điểm nhập JNI xuất xưởng (`.dynsym [037]..[054]`)
// của `libspeechepg.so` và lớp mặt tiền kiểm thử `SpeechepgEngine`.
// ============================================================================

#pragma once

#include "speechepg_types.h"
#include "speechepg_sdk_client.h"
#include "speechepg_jni_bridge.h"
#include <cstdint>
#include <string>
#include <vector>

namespace speechepg::jni {

struct SimulatedByteArray {
    std::vector<uint8_t> bytes;
};

} // namespace speechepg::jni

extern "C" {

// [046] 0x001f00 (size 128 B)
int32_t JNI_OnLoad(void* vm, void* reserved);

// [042] 0x0023dc (size 8 B: `mov x0, #-1; ret`)
int64_t Java_com_bytedance_speech_speechengine_log_1tracker_SpeechLogTracker_getInstanceToNative(
    void* env, void* thiz);

// [052] 0x0023e4 (size 4 B: `ret`)
void Java_com_bytedance_speech_speechengine_log_1tracker_SpeechLogTracker_writeLogToNative(
    void* env, void* thiz, int64_t tracker_handle, const char* log_msg);

// [043] 0x0023e8 (size 148 B)
const char* Java_com_bytedance_speech_speechengine_bridge_SpeechPluginBridge_getVersionToNative(
    void* env, void* thiz);

// [044] 0x00247c (size 100 B)
uint8_t Java_com_bytedance_speech_speechengine_bridge_SpeechPluginBridge_isEngineSupportedToNative(
    void* env, void* thiz, const char* engine_name);

// [050] 0x0024e0 (size 464 B)
int64_t Java_com_bytedance_speech_speechengine_bridge_SpeechPluginBridge_createEngineToNative(
    void* env, void* thiz, void* jcallback_obj);

// [048] 0x0026b0 (size 120 B)
void Java_com_bytedance_speech_speechengine_bridge_SpeechPluginBridge_destroyEngineToNative(
    void* env, void* thiz, int64_t handle);

// [047] 0x002728 (size 488 B)
void Java_com_bytedance_speech_speechengine_bridge_SpeechPluginBridge_setOptionStringToNative(
    void* env, void* thiz, int64_t handle, const char* key, const char* val);

// [053] 0x002910 (size 316 B)
void Java_com_bytedance_speech_speechengine_bridge_SpeechPluginBridge_setOptionBooleanToNative(
    void* env, void* thiz, int64_t handle, const char* key, uint8_t val);

// [041] 0x002a4c (size 308 B)
void Java_com_bytedance_speech_speechengine_bridge_SpeechPluginBridge_setOptionIntToNative(
    void* env, void* thiz, int64_t handle, const char* key, int32_t val);

// [038] 0x002b80 (size 308 B)
void Java_com_bytedance_speech_speechengine_bridge_SpeechPluginBridge_setOptionDoubleToNative(
    void* env, void* thiz, int64_t handle, const char* key, double val);

// [039] 0x002cb4 (size 196 B)
int32_t Java_com_bytedance_speech_speechengine_bridge_SpeechPluginBridge_initEngineToNative(
    void* env, void* thiz, int64_t handle, void* jasset_mgr);

// [040] 0x002d78 (size 344 B)
int32_t Java_com_bytedance_speech_speechengine_bridge_SpeechPluginBridge_sendDirectiveToNative(
    void* env, void* thiz, int64_t handle, int32_t directive_type, const char* data);

// [051] 0x002ed0 (size 168 B)
int32_t Java_com_bytedance_speech_speechengine_bridge_SpeechPluginBridge_feedAudioToNative(
    void* env, void* thiz, int64_t handle, const uint8_t* audio_bytes, int32_t byte_len);

// [037] 0x002f78 (size 68 B)
int32_t Java_com_bytedance_speech_speechengine_bridge_SpeechPluginBridge_resetEngineToNative(
    void* env, void* thiz, int64_t handle);

// [054] 0x002fbc (size 180 B)
int32_t Java_com_bytedance_speech_speechengine_bridge_SpeechPluginBridge_processAudioToNative(
    void* env, void* thiz, int64_t handle, const uint8_t* audio_bytes, int32_t byte_len, uint8_t is_last);

// [045] 0x003070 (size 284 B)
int32_t Java_com_bytedance_speech_speechengine_bridge_SpeechPluginBridge_fetchResultToNative(
    void* env, void* thiz, int64_t handle, int32_t result_type, speechepg::jni::SimulatedByteArray* out_buffer);

// [049] 0x00318c (size 188 B)
std::string Java_com_bytedance_speech_speechengine_bridge_SpeechPluginBridge_fetchStringResultToNative(
    void* env, void* thiz, int64_t handle, int32_t result_type);

} // extern "C"

namespace speechepg {

// ============================================================================
// SPEECHEPG VERIFICATION FACADE
// Lớp mặt tiền kiểm thử toàn diện cho libspeechepg.so
// ============================================================================
class SpeechepgEngine {
public:
    SpeechepgEngine();
    ~SpeechepgEngine();

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
    int         callback_dummy_obj_{0x504C474E}; // 'PLGN'
    std::string last_json_result_{};
    int32_t     last_err_code_{0};
};

} // namespace speechepg
