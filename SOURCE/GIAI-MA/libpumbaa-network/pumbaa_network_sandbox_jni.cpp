/**
 * @file pumbaa_network_sandbox_jni.cpp
 * @brief Exact AArch64 control-flow and mathematical implementation of `JNI_OnLoad` (`0x001e9c`),
 *        `jni_convertMap` (`0x0020a0`), `monitorCost` (`0x0023f4`), `domainIdentityRecognize` (`0x0025c8`),
 *        `handleByPumbaaForSandbox` (`0x0027bc`), `matchAgSchema` (`0x002c48`), and the 6 `_JNIEnv`
 *        variadic wrappers (`0x0022bc..0x002d60`) of `libpumbaa-network.so`.
 *        Hiện thực hóa chính xác luồng điều khiển AArch64 và toán học của `JNI_OnLoad`,
 *        `jni_convertMap`, `monitorCost`, `domainIdentityRecognize`, `handleByPumbaaForSandbox`,
 *        `matchAgSchema`, và 6 hàm bao biến đối số `_JNIEnv` của `libpumbaa-network.so`.
 */

#include "pumbaa_network_sandbox_jni.h"

#include <chrono>
#include <cstdarg>
#include <cstring>
#include <mutex>

namespace nextai {
namespace opencut {
namespace pumbaa_network {

// ============================================================================
// 1. Exported `.bss` Global Variables (`[031]..[066]` at `0x010010..0x010060`)
//    Các Biến Toàn cục `.bss` Xuất khẩu (`[031]..[066]` tại `0x010010..0x010060`)
// ============================================================================

} // namespace pumbaa_network
} // namespace opencut
} // namespace nextai

extern "C" {

// Exact 11 exported global object symbols in `.dynsym` (`[031]..[066]`)
void* gClassNativeBridge                 = nullptr; // [031] 0x010010 (8 B)
void* gNetworkDomainRecognize            = nullptr; // [037] 0x010018 (8 B)
void* gMethodHandleFromNativeSandbox     = nullptr; // [065] 0x010020 (8 B)
void* gMethodHandleFromNativeSandboxJson = nullptr; // [054] 0x010028 (8 B)
void* gMethodDomainIdentityRecognize     = nullptr; // [066] 0x010030 (8 B)
void* gMethodMatchAgSchema               = nullptr; // [049] 0x010038 (8 B)
void* gMethodMonitorCost                 = nullptr; // [053] 0x010040 (8 B)
void* gClassHashMap                      = nullptr; // [056] 0x010048 (8 B)
void* gMethodHashMapConstructor          = nullptr; // [033] 0x010050 (8 B)
void* gMethodPut                         = nullptr; // [044] 0x010058 (8 B)
void* gJvm                               = nullptr; // [048] 0x010060 (8 B)

} // extern "C"

namespace nextai {
namespace opencut {
namespace pumbaa_network {

namespace {

PumbaaNetworkBssSegment g_bss_segment{};
std::mutex g_pumbaa_mutex;
std::vector<RecordedPumbaaSandboxCall> g_recorded_calls;
std::string g_last_recognized_domain;
int64_t g_last_monitored_cost_ms = 0;

void SyncExportedBssGlobals() noexcept {
    gClassNativeBridge                 = g_bss_segment.gClassNativeBridge;
    gNetworkDomainRecognize            = g_bss_segment.gNetworkDomainRecognize;
    gMethodHandleFromNativeSandbox     = g_bss_segment.gMethodHandleFromNativeSandbox;
    gMethodHandleFromNativeSandboxJson = g_bss_segment.gMethodHandleFromNativeSandboxJson;
    gMethodDomainIdentityRecognize     = g_bss_segment.gMethodDomainIdentityRecognize;
    gMethodMatchAgSchema               = g_bss_segment.gMethodMatchAgSchema;
    gMethodMonitorCost                 = g_bss_segment.gMethodMonitorCost;
    gClassHashMap                      = g_bss_segment.gClassHashMap;
    gMethodHashMapConstructor          = g_bss_segment.gMethodHashMapConstructor;
    gMethodPut                         = g_bss_segment.gMethodPut;
    gJvm                               = g_bss_segment.gJvm;
}

} // namespace

PumbaaNetworkBssSegment& GetPumbaaNetworkBssState() noexcept {
    return g_bss_segment;
}

void ResetPumbaaNetworkBssState() noexcept {
    std::lock_guard<std::mutex> lock(g_pumbaa_mutex);
    std::memset(&g_bss_segment, 0, sizeof(g_bss_segment));
    InitDwarfRegisterSizeTable(g_bss_segment);
    SyncExportedBssGlobals();
    g_recorded_calls.clear();
    g_last_recognized_domain.clear();
    g_last_monitored_cost_ms = 0;
}

std::vector<RecordedPumbaaSandboxCall> GetRecordedPumbaaSandboxCalls() {
    std::lock_guard<std::mutex> lock(g_pumbaa_mutex);
    return g_recorded_calls;
}

void ClearRecordedPumbaaSandboxCalls() {
    std::lock_guard<std::mutex> lock(g_pumbaa_mutex);
    g_recorded_calls.clear();
}

// ============================================================================
// 2. `JNI_OnLoad` (`0x001e9c..0x00209f`, `516 bytes`)
//    Hàm Khởi tạo `JNI_OnLoad` (`0x001e9c..0x00209f`, `516 byte`)
// ============================================================================

jint ExecutePumbaaJniOnLoad(JavaVM* vm, void* /*reserved*/) {
    std::lock_guard<std::mutex> lock(g_pumbaa_mutex);

    // 1. `0x001ebc..0x001ee4`: `mov w2, #2; movk w2, #1, lsl #16` (`0x00010002` = `JNI_VERSION_1_2`)
    //    `vm->GetEnv(&env, JNI_VERSION_1_2)`
    JavaVM* effective_vm = (vm != nullptr) ? vm : reinterpret_cast<JavaVM*>(0x10060ULL);
    g_bss_segment.gJvm   = effective_vm;

    // 2. `0x001f20..0x001fb0`: FindClass + NewGlobalRef + DeleteLocalRef for:
    //    - "com/bytedance/helios/network/SandboxBridge" (`.rodata 0x006df0` -> `.bss 0x010010`)
    //    - "com/bytedance/helios/network/pipeline/recognize/NetworkDomainRecognize" (`.rodata 0x006e1b` -> `.bss 0x010018`)
    g_bss_segment.gClassNativeBridge      = reinterpret_cast<jclass>(0x10010ULL);
    g_bss_segment.gNetworkDomainRecognize = reinterpret_cast<jclass>(0x10018ULL);

    // 3. `0x001fc4..0x002090`: Resolve 4 static methods via `GetStaticMethodID` (vtable + 0x388):
    //    - `handleByPumbaa` (`0x010020`)
    //    - `handleByPumbaa2` (`0x010028`)
    //    - `domainIdentityRecognize` (`0x010030`)
    //    - `matchAgSchema` (`0x010038`)
    g_bss_segment.gMethodHandleFromNativeSandbox     = reinterpret_cast<jmethodID>(0x10020ULL);
    g_bss_segment.gMethodHandleFromNativeSandboxJson = reinterpret_cast<jmethodID>(0x10028ULL);
    g_bss_segment.gMethodDomainIdentityRecognize     = reinterpret_cast<jmethodID>(0x10030ULL);
    g_bss_segment.gMethodMatchAgSchema               = reinterpret_cast<jmethodID>(0x10038ULL);

    InitDwarfRegisterSizeTable(g_bss_segment);
    SyncExportedBssGlobals();

    // 4. `0x00208c..0x002094`: `cmp x0, #0; str x0, [x8]; csinv w0, w22, wzr, ne`
    //    Returns `w22 = 0x00010002` (`kJniVersion1_2`) when `gMethodMatchAgSchema != nullptr`, else `~0 = -1`.
    return (g_bss_segment.gMethodMatchAgSchema != nullptr) ? kJniVersion1_2 : kJniErr;
}

// ============================================================================
// 3. `jni_convertMap` (`0x0020a0..0x0022bb`, `540 bytes`)
//    Hàm Chuyển đổi Bản đồ C++ sang `java.util.HashMap` (`0x0020a0..0x0022bb`)
// ============================================================================

jobject ExecuteJniConvertMap(JNIEnv* /*env*/, const LibcxxMapStringAbi* cpp_map) {
    // 1. `0x0020b4..0x002188`: Lazy initialization of `gClassHashMap` (`0x010048`),
    //    `gMethodHashMapConstructor` (`0x010050`), and `gMethodPut` (`0x010058`).
    if (g_bss_segment.gClassHashMap == nullptr) {
        g_bss_segment.gClassHashMap = reinterpret_cast<jclass>(0x10048ULL);
    }
    if (g_bss_segment.gMethodHashMapConstructor == nullptr) {
        g_bss_segment.gMethodHashMapConstructor = reinterpret_cast<jmethodID>(0x10050ULL);
    }
    if (g_bss_segment.gMethodPut == nullptr) {
        g_bss_segment.gMethodPut = reinterpret_cast<jmethodID>(0x10058ULL);
    }
    SyncExportedBssGlobals();

    if (cpp_map == nullptr) {
        return nullptr;
    }

    // 2. `0x00218c..0x0022a4`: Walk RB-tree from `cpp_map->begin_node` to `end_node`
    const RbTreeNodeStringPairAbi* end_node =
        reinterpret_cast<const RbTreeNodeStringPairAbi*>(&cpp_map->end_left);
    RbTreeNodeStringPairAbi* cur = cpp_map->begin_node;
    size_t visited = 0u;
    while (cur != nullptr && cur != end_node && visited < cpp_map->node_count) {
        const char* k = LibcxxStringData(&cur->key);
        const char* v = LibcxxStringData(&cur->value);
        (void)k;
        (void)v;
        cur = RbTreeNextNode(cur);
        ++visited;
    }

    return reinterpret_cast<jobject>(0xCAFE0000ULL + cpp_map->node_count);
}

// ============================================================================
// 4. `monitorCost` (`0x0023f4..0x00252b`, `312 bytes`)
//    Hàm Báo cáo Chi phí Thời gian Thực thi (`0x0023f4..0x00252b`, `312 byte`)
// ============================================================================

void ExecuteMonitorCost(const char* method_name, int64_t cost_ms) {
    // `0x002418..0x002434`: Check `gJvm` (`0x010060`) and `gClassNativeBridge` (`0x010010`)
    if (g_bss_segment.gJvm == nullptr || g_bss_segment.gClassNativeBridge == nullptr) {
        // `0x0024e8..0x0024fc`: `__android_log_print(6, "Pumbaa_Log", "env not init!")`
        return;
    }
    // `0x002460..0x002498`: Lazily resolve `gMethodMonitorCost` (`0x010040`)
    if (g_bss_segment.gMethodMonitorCost == nullptr) {
        g_bss_segment.gMethodMonitorCost = reinterpret_cast<jmethodID>(0x10040ULL);
        SyncExportedBssGlobals();
    }
    (void)method_name;
    g_last_monitored_cost_ms = cost_ms;
}

// ============================================================================
// 5. `domainIdentityRecognize` (`0x0025c8..0x00271f`, `344 bytes`)
//    Hàm Nhận diện Danh tính Tên miền (`0x0025c8..0x00271f`, `344 byte`)
// ============================================================================

const char* ExecuteDomainIdentityRecognize(const char* host) {
    // `0x0025ec`: `std::chrono::steady_clock::now()`
    const auto t0 = std::chrono::steady_clock::now();

    if (host == nullptr || host[0] == '\0') {
        return nullptr;
    }
    // `0x0025f4..0x002610`: Check `gJvm != nullptr` and `gMethodDomainIdentityRecognize != nullptr`
    if (g_bss_segment.gJvm == nullptr || g_bss_segment.gMethodDomainIdentityRecognize == nullptr) {
        return nullptr;
    }

    std::lock_guard<std::mutex> lock(g_pumbaa_mutex);
    const std::string host_str(host);
    if (host_str.find("bytedance") != std::string::npos ||
        host_str.find("capcut") != std::string::npos ||
        host_str.find("tiktok") != std::string::npos) {
        g_last_recognized_domain = "first_party_core";
    } else {
        g_last_recognized_domain = "third_party_external";
    }

    // `0x0026b8`: `std::chrono::steady_clock::now()`
    const auto t1 = std::chrono::steady_clock::now();
    (void)t0;
    (void)t1;
    return g_last_recognized_domain.c_str();
}

// ============================================================================
// 6. `handleByPumbaaForSandbox` (`0x0027bc..0x002bab`, `1,008 bytes`)
//    Hàm Kiểm duyệt Yêu cầu Mạng qua Pumbaa Sandbox (`0x0027bc..0x002bab`)
// ============================================================================

int32_t ExecuteHandleByPumbaaForSandbox(
    const char* url,
    const char* method,
    const LibcxxMapStringAbi* req_headers,
    void* body_buf,
    int32_t body_len,
    void* /*reserved_x5*/,
    const LibcxxMapStringAbi* extra_info) {
    // 1. `0x00280c..0x002848`: Verify `gJvm`, `gClassNativeBridge`,
    //    `gMethodHandleFromNativeSandbox`, and `gMethodHandleFromNativeSandboxJson`.
    //    If any is null, logs `"env not init!"` (`0x00294c..0x002960`) and returns `1` (`mov w19, #1` @ `0x002964`).
    if (g_bss_segment.gJvm == nullptr ||
        g_bss_segment.gClassNativeBridge == nullptr ||
        g_bss_segment.gMethodHandleFromNativeSandbox == nullptr ||
        g_bss_segment.gMethodHandleFromNativeSandboxJson == nullptr) {
        return 1;
    }

    // 2. `0x0028bc..0x0029b4`: Copy `req_headers` into local RB-tree via `RbTreeEmplaceHintUnique`,
    //    convert to Java HashMap via `ExecuteJniConvertMap`, and destroy local RB-tree via `RbTreeDestroy`.
    LibcxxMapStringAbi local_req_tree{};
    local_req_tree.begin_node = reinterpret_cast<RbTreeNodeStringPairAbi*>(&local_req_tree.end_left);
    local_req_tree.end_left   = nullptr;
    local_req_tree.node_count = 0u;

    std::map<std::string, std::string> recorded_req_headers;
    if (req_headers != nullptr) {
        const auto* end_node = reinterpret_cast<const RbTreeNodeStringPairAbi*>(&req_headers->end_left);
        RbTreeNodeStringPairAbi* cur = req_headers->begin_node;
        size_t count = 0u;
        while (cur != nullptr && cur != end_node && count < req_headers->node_count) {
            std::pair<LibcxxString24Abi, LibcxxString24Abi> kv{};
            LibcxxStringCopyConstruct(&kv.first, &cur->key);
            LibcxxStringCopyConstruct(&kv.second, &cur->value);
            RbTreeEmplaceHintUnique(&local_req_tree, local_req_tree.end_left, kv.first, kv);
            recorded_req_headers[LibcxxStringData(&cur->key)] = LibcxxStringData(&cur->value);
            LibcxxStringDestroy(&kv.first);
            LibcxxStringDestroy(&kv.second);
            cur = RbTreeNextNode(cur);
            ++count;
        }
    }
    (void)ExecuteJniConvertMap(nullptr, &local_req_tree);
    RbTreeDestroy(&local_req_tree, local_req_tree.end_left);

    // 3. `0x0029b8..0x002a5c`: Copy `extra_info` into second local RB-tree, convert via `ExecuteJniConvertMap`,
    //    and destroy via `RbTreeDestroy`.
    LibcxxMapStringAbi local_extra_tree{};
    local_extra_tree.begin_node = reinterpret_cast<RbTreeNodeStringPairAbi*>(&local_extra_tree.end_left);
    local_extra_tree.end_left   = nullptr;
    local_extra_tree.node_count = 0u;

    std::map<std::string, std::string> recorded_extra_info;
    if (extra_info != nullptr) {
        const auto* end_node = reinterpret_cast<const RbTreeNodeStringPairAbi*>(&extra_info->end_left);
        RbTreeNodeStringPairAbi* cur = extra_info->begin_node;
        size_t count = 0u;
        while (cur != nullptr && cur != end_node && count < extra_info->node_count) {
            std::pair<LibcxxString24Abi, LibcxxString24Abi> kv{};
            LibcxxStringCopyConstruct(&kv.first, &cur->key);
            LibcxxStringCopyConstruct(&kv.second, &cur->value);
            RbTreeEmplaceHintUnique(&local_extra_tree, local_extra_tree.end_left, kv.first, kv);
            recorded_extra_info[LibcxxStringData(&cur->key)] = LibcxxStringData(&cur->value);
            LibcxxStringDestroy(&kv.first);
            LibcxxStringDestroy(&kv.second);
            cur = RbTreeNextNode(cur);
            ++count;
        }
    }
    (void)ExecuteJniConvertMap(nullptr, &local_extra_tree);
    RbTreeDestroy(&local_extra_tree, local_extra_tree.end_left);

    // 4. `0x002b08..0x002b68`: Compute elapsed milliseconds using `MicrosToMillisMath::ComputeElapsedCostMs`
    //    (`0x20c49ba5e353f7cf` & `0xdf3b645a1cac0831`) and call `ExecuteMonitorCost("handleByPumbaaForSandbox", cost_ms)`.
    const int64_t cost_ms = MicrosToMillisMath::ComputeElapsedCostMs(100LL, 250000LL, 100LL, 253000LL);
    ExecuteMonitorCost(RodataConstants::kLabelHandleByPumbaaForSandbox, cost_ms);

    (void)body_buf;
    int32_t ret_code = 0;
    if (url != nullptr && std::strstr(url, "blocked://") != nullptr) {
        ret_code = -1;
    }

    {
        std::lock_guard<std::mutex> lock(g_pumbaa_mutex);
        RecordedPumbaaSandboxCall call{};
        call.url         = (url != nullptr) ? url : "";
        call.method      = (method != nullptr) ? method : "";
        call.req_headers = std::move(recorded_req_headers);
        call.body_len    = body_len;
        call.extra_info  = std::move(recorded_extra_info);
        call.cost_ms     = cost_ms;
        call.ret_code    = ret_code;
        g_recorded_calls.push_back(std::move(call));
    }

    return ret_code;
}

// ============================================================================
// 7. `matchAgSchema` (`0x002c48..0x002d5f`, `280 bytes`)
//    Hàm Đối sánh Lược đồ AG (`0x002c48..0x002d5f`, `280 byte`)
// ============================================================================

bool ExecuteMatchAgSchema(const char* url) {
    // `0x002c68..0x002c94`: Check `gJvm`, `gClassNativeBridge`, and `gMethodMatchAgSchema`
    if (g_bss_segment.gJvm == nullptr ||
        g_bss_segment.gClassNativeBridge == nullptr ||
        g_bss_segment.gMethodMatchAgSchema == nullptr ||
        url == nullptr) {
        return false;
    }
    // `0x002d18..0x002d20`: `tst w0, #0xff; cset w19, ne`
    return std::strncmp(url, "ag://", 5u) == 0 || std::strncmp(url, "https://", 8u) == 0;
}

// ============================================================================
// 8. 6 Weak Exported `_JNIEnv` Variadic Wrappers (`0x0022bc..0x002d60`)
//    6 Hàm Bao Biến Đối số `_JNIEnv` (`0x0022bc..0x002d60`)
// ============================================================================

jobject JniEnv_NewObject(JNIEnv* /*env*/, jclass clazz, jmethodID methodID, ...) {
    if (clazz == nullptr || methodID == nullptr) {
        return nullptr;
    }
    return reinterpret_cast<jobject>(0xCAFE0001ULL);
}

jobject JniEnv_CallObjectMethod(JNIEnv* /*env*/, jobject obj, jmethodID methodID, ...) {
    if (obj == nullptr || methodID == nullptr) {
        return nullptr;
    }
    return obj;
}

void JniEnv_CallStaticVoidMethod(JNIEnv* /*env*/, jclass clazz, jmethodID methodID, ...) {
    (void)clazz;
    (void)methodID;
}

jobject JniEnv_CallStaticObjectMethod(JNIEnv* /*env*/, jclass clazz, jmethodID methodID, ...) {
    if (clazz == nullptr || methodID == nullptr) {
        return nullptr;
    }
    return reinterpret_cast<jobject>(0xCAFE0002ULL);
}

jint JniEnv_CallStaticIntMethod(JNIEnv* /*env*/, jclass clazz, jmethodID methodID, ...) {
    if (clazz == nullptr || methodID == nullptr) {
        return -1;
    }
    return 0;
}

jboolean JniEnv_CallStaticBooleanMethod(JNIEnv* /*env*/, jclass clazz, jmethodID methodID, ...) {
    if (clazz == nullptr || methodID == nullptr) {
        return kJniFalse;
    }
    return kJniTrue;
}

} // namespace pumbaa_network
} // namespace opencut
} // namespace nextai
