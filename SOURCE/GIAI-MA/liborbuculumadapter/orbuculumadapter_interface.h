// ============================================================================
// File: orbuculumadapter_interface.h
// Target Binary: liborbuculumadapter.so (149,936 bytes)
// SHA-256: c79326a4419e98be93ce70b6b08f70a82852980d7322dadb3d5edac7ea179785
// Architecture: AArch64 (arm64-v8a)
//
// [EN] Public C/C++17 & JNI interface declarations for `liborbuculumadapter.so`,
//      including `JNI_OnLoad` (0x004540), `JNI_OnUnload` (0x004a00), the 8
//      `RegisterNatives` methods on `com.orbu.core.init.TTKNativeNetworkManager`
//      (.data 0x028000..0x0280b8), and the 5 native C entry points exported via
//      the ShadowHook `getenv` lookup table (.bss 0x028930).
// [VN] Khai báo giao diện công khai C/C++17 & JNI cho `liborbuculumadapter.so`,
//      bao gồm `JNI_OnLoad` (0x004540), `JNI_OnUnload` (0x004a00), 8 phương thức
//      `RegisterNatives` trên `com.orbu.core.init.TTKNativeNetworkManager`
//      (.data 0x028000..0x0280b8), và 5 điểm vào C native được xuất thông qua
//      bảng tra cứu ShadowHook `getenv` (.bss 0x028930).
// ============================================================================

#ifndef NEXTAI_OPENCUT_ORBUCULUMADAPTER_INTERFACE_H_
#define NEXTAI_OPENCUT_ORBUCULUMADAPTER_INTERFACE_H_

#include "orbuculumadapter_config_parser.h"
#include "orbuculumadapter_runtime_hooks.h"
#include "orbuculumadapter_types.h"

namespace nextai {
namespace opencut {
namespace orbuculumadapter {

// ============================================================================
// 1. JNI LIFECYCLE & 8 REGISTERNATIVES METHODS (0x004540..0x0072fc)
// ============================================================================

/// @brief [EN] Method [0] `activesdk(IZI)I` at `0x004f6c` (.data `0x028000`)
///        [VN] Phương thức [0] `activesdk(IZI)I` tại `0x004f6c` (.data `0x028000`)
jint JniActiveSdk(
    JNIEnv* env,
    jobject thiz,
    jint sdk_enable_strategy,
    jboolean enable_callback,
    jint pumbaa_strategy);

/// @brief [EN] Method [1] `initcall(IZ)I` at `0x004fec` (.data `0x028018`)
///        [VN] Phương thức [1] `initcall(IZ)I` tại `0x004fec` (.data `0x028018`)
jint JniInitCall(
    JNIEnv* env,
    jobject thiz,
    jint sdk_report_strategy,
    jboolean hit_sample_drop);

/// @brief [EN] Method [2] `initnetconfig(Lcom/orbu/core/config/BootConfig;)V` at `0x005058` (.data `0x028030`)
///        [VN] Phương thức [2] `initnetconfig(Lcom/orbu/core/config/BootConfig;)V` tại `0x005058` (.data `0x028030`)
void JniInitNetConfig(
    JNIEnv* env,
    jobject thiz,
    jobject boot_config_obj);

/// @brief [EN] Method [3] `unhook()V` at `0x005c24` (.data `0x028048`)
///        [VN] Phương thức [3] `unhook()V` tại `0x005c24` (.data `0x028048`)
void JniUnhook(JNIEnv* env, jobject thiz);

/// @brief [EN] Method [4] `doNativeNetworkValidate(Ljava/lang/String;Ljava/lang/String;Ljava/util/Map;Ljava/lang/String;ILjava/lang/String;I)I` at `0x005c28` (.data `0x028060`)
///        [VN] Phương thức [4] `doNativeNetworkValidate(...)I` tại `0x005c28` (.data `0x028060`)
jint JniDoNativeNetworkValidate(
    JNIEnv* env,
    jobject thiz,
    jstring j_url,
    jstring j_method,
    jobject j_headers_map,
    jstring j_body,
    jint body_len,
    jstring j_dfid,
    jint validate_mode);

/// @brief [EN] Method [5] `setNativeHardBlockConfigInner(ZZZLjava/util/List;Ljava/util/List;)V` at `0x006874` (.data `0x028078`)
///        [VN] Phương thức [5] `setNativeHardBlockConfigInner(ZZZLjava/util/List;Ljava/util/List;)V` tại `0x006874` (.data `0x028078`)
void JniSetNativeHardBlockConfigInner(
    JNIEnv* env,
    jobject thiz,
    jboolean enable_network_hard_block,
    jboolean is_target_rule_group,
    jboolean enable_dynamic_check,
    jobject j_allow_code_list,
    jobject j_allow_dfid_list);

/// @brief [EN] Method [6] `isNativeNetworkResultNeedBlock(ILjava/lang/String;)Z` at `0x007174` (.data `0x028090`)
///        [VN] Phương thức [6] `isNativeNetworkResultNeedBlock(ILjava/lang/String;)Z` tại `0x007174` (.data `0x028090`)
jboolean JniIsNativeNetworkResultNeedBlock(
    JNIEnv* env,
    jobject thiz,
    jint result_code,
    jstring j_dfid);

/// @brief [EN] Method [7] `setNativeDebug(Z)V` at `0x0072ec` (.data `0x0280a8`)
///        [VN] Phương thức [7] `setNativeDebug(Z)V` tại `0x0072ec` (.data `0x0280a8`)
void JniSetNativeDebug(JNIEnv* env, jobject thiz, jboolean debug);

// ============================================================================
// 2. FIVE SHADOWHOOK GETENV-EXPORTED NATIVE ENTRY POINTS (.bss 0x028930)
// ============================================================================

/// @brief [EN] Export [0] `"orbuculumIsProceedRequest"` at `0x011178..0x011804`
///        [VN] Biểu tượng xuất [0] `"orbuculumIsProceedRequest"` tại `0x011178..0x011804`
int32_t OrbuculumIsProceedRequest(
    const char* url,
    const char* method,
    const char* headers_raw,
    const char* body,
    size_t body_len,
    const char* metadata_raw);

/// @brief [EN] Export [1] `"orbuculumIsProceedRequestForTTNet"` at `0x00eb48..0x00f6e8`
///        [VN] Biểu tượng xuất [1] `"orbuculumIsProceedRequestForTTNet"` tại `0x00eb48..0x00f6e8`
int32_t OrbuculumIsProceedRequestForTTNet(
    const std::string& url,
    const std::string& method,
    const std::map<std::string, std::string>& headers,
    const std::string& body,
    size_t body_len,
    const std::map<std::string, std::string>& metadata);

/// @brief [EN] Export [2] `"orbuculumIsProceedResponseImpl"` at `0x011808..0x011da0`
///        [VN] Biểu tượng xuất [2] `"orbuculumIsProceedResponseImpl"` tại `0x011808..0x011da0`
int32_t OrbuculumIsProceedResponseImpl(
    const char* url,
    const char* method,
    const char* req_headers,
    const char* req_body,
    size_t req_body_len,
    int32_t status_code,
    const char* resp_headers,
    const char* resp_body,
    size_t resp_body_len,
    const char* metadata_kv);

/// @brief [EN] Export [3] `"orbuculumRegisterLiveShutdownCallback"` at `0x00d490..0x00d574`
///        [VN] Biểu tượng xuất [3] `"orbuculumRegisterLiveShutdownCallback"` tại `0x00d490..0x00d574`
int32_t OrbuculumRegisterLiveShutdownCallback(LiveShutdownCallbackFn callback);

/// @brief [EN] Export [4] `"orbuculumIsProceedSeiField"` at `0x00d2e8..0x00d38c`
///        [VN] Biểu tượng xuất [4] `"orbuculumIsProceedSeiField"` tại `0x00d2e8..0x00d38c`
int32_t OrbuculumIsProceedSeiField(
    const char* sei_key,
    const SeiFieldPayload* sei_payload,
    const char* sei_channel);

}  // namespace orbuculumadapter
}  // namespace opencut
}  // namespace nextai

extern "C" {
jint JNI_OnLoad(JavaVM* vm, void* reserved);
void JNI_OnUnload(JavaVM* vm, void* reserved);
}

#endif  // NEXTAI_OPENCUT_ORBUCULUMADAPTER_INTERFACE_H_
