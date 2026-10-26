/**
 * @file pumbaa_network_sandbox_jni.h
 * @brief Declarations for `JNI_OnLoad` (`0x001e9c`), `jni_convertMap` (`0x0020a0`),
 *        `monitorCost` (`0x0023f4`), `domainIdentityRecognize` (`0x0025c8`),
 *        `handleByPumbaaForSandbox` (`0x0027bc`), `matchAgSchema` (`0x002c48`),
 *        and the 6 `_JNIEnv` variadic helpers (`0x0022bc`, `0x002358`, `0x00252c`,
 *        `0x002720`, `0x002bac`, `0x002d60`) of `libpumbaa-network.so`.
 *        Khai báo `JNI_OnLoad`, `jni_convertMap`, `monitorCost`, `domainIdentityRecognize`,
 *        `handleByPumbaaForSandbox`, `matchAgSchema` và 6 hàm biến đối số `_JNIEnv` của
 *        `libpumbaa-network.so`.
 */

#ifndef NEXTAI_OPENCUT_PUMBAA_NETWORK_SANDBOX_JNI_H_
#define NEXTAI_OPENCUT_PUMBAA_NETWORK_SANDBOX_JNI_H_

#include "pumbaa_network_rbtree_dwarf.h"
#include "pumbaa_network_types.h"

#include <cstdint>
#include <map>
#include <string>
#include <vector>

namespace nextai {
namespace opencut {
namespace pumbaa_network {

// ============================================================================
// 1. Global `.bss` State Accessors (`0x010010..0x0102b0`)
//    Các Hàm Truy cập Trạng thái `.bss` Toàn cục (`0x010010..0x0102b0`)
// ============================================================================

PumbaaNetworkBssSegment& GetPumbaaNetworkBssState() noexcept;
void ResetPumbaaNetworkBssState() noexcept;

struct RecordedPumbaaSandboxCall {
    std::string                        url;
    std::string                        method;
    std::map<std::string, std::string> req_headers;
    int32_t                            body_len = 0;
    std::map<std::string, std::string> extra_info;
    int64_t                            cost_ms  = 0;
    int32_t                            ret_code = 0;
};

std::vector<RecordedPumbaaSandboxCall> GetRecordedPumbaaSandboxCalls();
void ClearRecordedPumbaaSandboxCalls();

// ============================================================================
// 2. Core Exported Sandbox & Domain Recognition Functions (`0x001e9c..0x002d5f`)
//    Các Hàm Xuất khẩu Cốt lõi Sandbox & Nhận diện Tên miền (`0x001e9c..0x002d5f`)
// ============================================================================

/**
 * @brief Reconstructs `JNI_OnLoad(JavaVM*, void*)` (`0x001e9c..0x00209f`, `516 bytes`).
 *        - Calls `vm->GetEnv(&env, 0x00010002)` (`0x001ebc..0x001ee4`).
 *        - Caches `gJvm` (`0x010060`), `gClassNativeBridge` (`0x010010` = `"com/bytedance/helios/network/SandboxBridge"`),
 *          and `gNetworkDomainRecognize` (`0x010018` = `"com/bytedance/helios/network/pipeline/recognize/NetworkDomainRecognize"`).
 *        - Resolves 4 static methods via `GetStaticMethodID` (vtable `+0x388`):
 *          - `gMethodHandleFromNativeSandbox` (`0x010020`: `"handleByPumbaa"`)
 *          - `gMethodHandleFromNativeSandboxJson` (`0x010028`: `"handleByPumbaa2"`)
 *          - `gMethodDomainIdentityRecognize` (`0x010030`: `"domainIdentityRecognize"`)
 *          - `gMethodMatchAgSchema` (`0x010038`: `"matchAgSchema"`)
 *        - Returns `csinv w0, w22, wzr, ne` (`0x002094`): `0x00010002` (`JNI_VERSION_1_2`) on success, `-1` on failure.
 */
jint ExecutePumbaaJniOnLoad(JavaVM* vm, void* reserved);

/**
 * @brief Reconstructs `jni_convertMap(JNIEnv*, const std::map<std::string, std::string>&)`
 *        (`0x0020a0..0x0022bb`, `540 bytes`).
 *        Lazily resolves `gClassHashMap` (`0x010048`), `gMethodHashMapConstructor` (`0x010050`),
 *        and `gMethodPut` (`0x010058`), constructs a `java/util/HashMap` with initial capacity
 *        `map.size()`, and inserts every key-value pair inside a `PushLocalFrame(3)` / `PopLocalFrame(nullptr)` scope.
 */
jobject ExecuteJniConvertMap(JNIEnv* env, const LibcxxMapStringAbi* cpp_map);

/**
 * @brief Reconstructs `_Z11monitorCostPKcx` (`monitorCost(const char*, long long)`,
 *        `0x0023f4..0x00252b`, `312 bytes`).
 *        Lazily resolves `gMethodMonitorCost` (`0x010040`: `"monitorCost"`, `"(Ljava/lang/String;J)V"`)
 *        and invokes `SandboxBridge.monitorCost(name, cost_ms)`. Logs `"env not init!"` (`Pumbaa_Log`)
 *        at `ANDROID_LOG_ERROR` (`6`) if `gJvm` or `gClassNativeBridge` is null.
 */
void ExecuteMonitorCost(const char* method_name, int64_t cost_ms);

/**
 * @brief Reconstructs `domainIdentityRecognize(const char* host)` (`0x0025c8..0x00271f`, `344 bytes`).
 *        Calls `std::chrono::steady_clock::now()` around `NetworkDomainRecognize.domainIdentityRecognize(host)`
 *        and returns the UTF-8 domain category string via `GetStringUTFChars`.
 */
const char* ExecuteDomainIdentityRecognize(const char* host);

/**
 * @brief Reconstructs `handleByPumbaaForSandbox` (`0x0027bc..0x002bab`, `1,008 bytes`).
 *        Converts `req_headers` and `extra_info` via `RbTreeEmplaceHintUnique` + `jni_convertMap`,
 *        wraps `body_buf` in `NewDirectByteBuffer(body_buf, body_len)`, invokes
 *        `SandboxBridge.handleByPumbaa(...)`, computes elapsed milliseconds via
 *        `0x20c49ba5e353f7cf` and `0xdf3b645a1cac0831` (`0x002b10..0x002b60`), and reports via `monitorCost`.
 */
int32_t ExecuteHandleByPumbaaForSandbox(
    const char* url,
    const char* method,
    const LibcxxMapStringAbi* req_headers,
    void* body_buf,
    int32_t body_len,
    void* reserved_x5,
    const LibcxxMapStringAbi* extra_info);

/**
 * @brief Reconstructs `matchAgSchema(const char* url)` (`0x002c48..0x002d5f`, `280 bytes`).
 *        Calls `SandboxBridge.matchAgSchema(url)` and returns `tst w0, #0xff; cset w19, ne`.
 */
bool ExecuteMatchAgSchema(const char* url);

// ============================================================================
// 3. 6 Weak Exported `_JNIEnv` Variadic Wrappers (`0x0022bc..0x002d60`)
//    6 Hàm Bao Biến Đối số `_JNIEnv` Xuất khẩu Yếu (`0x0022bc..0x002d60`)
// ============================================================================

jobject JniEnv_NewObject(JNIEnv* env, jclass clazz, jmethodID methodID, ...);
jobject JniEnv_CallObjectMethod(JNIEnv* env, jobject obj, jmethodID methodID, ...);
void    JniEnv_CallStaticVoidMethod(JNIEnv* env, jclass clazz, jmethodID methodID, ...);
jobject JniEnv_CallStaticObjectMethod(JNIEnv* env, jclass clazz, jmethodID methodID, ...);
jint    JniEnv_CallStaticIntMethod(JNIEnv* env, jclass clazz, jmethodID methodID, ...);
jboolean JniEnv_CallStaticBooleanMethod(JNIEnv* env, jclass clazz, jmethodID methodID, ...);

} // namespace pumbaa_network
} // namespace opencut
} // namespace nextai

#endif // NEXTAI_OPENCUT_PUMBAA_NETWORK_SANDBOX_JNI_H_
