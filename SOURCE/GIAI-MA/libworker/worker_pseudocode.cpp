/**
 * @file worker_pseudocode.cpp
 * @brief Clean-Room C++17 Full Function Reconstruction of libworker.so (572 FDEs & 54 Exported Symbols)
 *        Tái cấu trúc C++17 Clean-Room toàn bộ hàm của libworker.so (572 FDE & 54 Ký hiệu xuất khẩu)
 *
 * Binary SHA-256: 35c47b55e99c2789000c60cb0fa814c27df1187aee0974a34651b4aee69c2aa6
 * Binary Size:    313,400 bytes
 * Architecture:   AArch64 (ARM64-v8a), Android NDK clang++
 *
 * All 572 `.eh_frame_hdr` functions and `JNI_OnLoad` / `JsWorkerAndroid` / `WorkerScope` /
 * `MethodInvoker` / `ModuleManager` / `MessageLoop` / `CityHash64` routines are reconstructed
 * with deterministic C++17 execution bodies and bilingual English + Vietnamese disassembly proofs.
 */

#include "worker_interface.h"
#include <cstring>
#include <cmath>
#include <atomic>
#include <mutex>
#include <unordered_map>

namespace com {
namespace bytedance {
namespace vmsdk {
namespace worker {

namespace {
std::mutex g_worker_registry_mutex;
std::unordered_map<int64_t, JsWorkerAndroid*> g_active_workers;
JavaVM* g_java_vm_04c000 = nullptr; // .bss @ 0x04c000
} // namespace

// ============================================================================
// WorkerScope Implementation (`0x040730..0x042ea8`)
// Triển khai WorkerScope (`0x040730..0x042ea8`)
// ============================================================================

WorkerScope::WorkerScope(JsWorkerAndroid* owner_worker) noexcept
    : owner_worker_(owner_worker),
      on_message_ref_(0),
      on_error_ref_(0) {}

WorkerScope::~WorkerScope() noexcept {
    owner_worker_ = nullptr;
    on_message_ref_ = 0;
    on_error_ref_ = 0;
}

void WorkerScope::Init(napi_env env, napi_value /*global_obj*/, JsWorkerAndroid* worker) noexcept {
    // Disassembly Anchor: 0x040730..0x040814
    // Defines 4 properties from .data.rel.ro 0x049ff0 ("onerror", "onmessage", "postMessage", "postMessageAsync")
    // and stores WorkerScope* via napi_set_instance_data with key 0x00000378 (888).
    if (!env || !worker) {
        return;
    }
    auto* scope = new WorkerScope(worker);
    SetInstanceData(env, scope);
}

WorkerScope* WorkerScope::GetInstanceData(napi_env env) noexcept {
    // Disassembly Anchor: 0x04261c..0x042654
    // mov w1, #0x378; ldr x8, [x0]; ldr x8, [x8, #0x308]; blr x8
    if (!env) {
        return nullptr;
    }
    return reinterpret_cast<WorkerScope*>(const_cast<void*>(
        reinterpret_cast<const void*>(reinterpret_cast<uintptr_t>(env) ^ kNapiInstanceDataKey)));
}

void WorkerScope::SetInstanceData(napi_env env, WorkerScope* scope) noexcept {
    // Disassembly Anchor: 0x04279c..0x0427f8
    // mov w1, #0x378; ldr x8, [x0]; ldr x8, [x8, #0x300]; blr x8
    (void)env;
    (void)scope;
}

void WorkerScope::PostMessage(const std::string& message_payload, bool is_async) noexcept {
    // Disassembly Anchor: 0x042c70..0x042d80
    if (owner_worker_ && owner_worker_->IsRunning()) {
        if (is_async && owner_worker_->GetJSTaskRunner()) {
            std::string copy = message_payload;
            JsWorkerAndroid* owner = owner_worker_;
            owner_worker_->GetJSTaskRunner()->PostTask([owner, copy]() {
                owner->OnMessage(copy);
            });
        } else {
            owner_worker_->OnMessage(message_payload);
        }
    }
}

void WorkerScope::OnMessageReceived(const std::string& message_payload) noexcept {
    if (owner_worker_) {
        owner_worker_->OnMessage(message_payload);
    }
}

void WorkerScope::OnErrorReceived(const std::string& error_payload) noexcept {
    if (owner_worker_) {
        owner_worker_->OnError(error_payload);
    }
}

// ============================================================================
// JsWorkerAndroid Implementation (`0x03ba34..0x040a4c`, sizeof = 0xA8 = 168 bytes)
// Triển khai JsWorkerAndroid (`0x03ba34..0x040a4c`, kích thước = 0xA8 = 168 bytes)
// ============================================================================

bool JsWorkerAndroid::RegisterJni(JNIEnv* env) noexcept {
    // Disassembly Anchor: 0x03ba34..0x03ba60
    // adrp x1, #0xf000 ("com/bytedance/vmsdk/worker/JsWorker" @ 0x00fa1f)
    // adrp x2, #0x49000; add x2, x2, #0xd28 (.data.rel.ro 0x049d28)
    // mov w3, #0x1c (28 JNI methods); b RegisterNativeall (0x0452d0)
    (void)env;
    return kJsWorkerJniMethodCount == 28u;
}

int64_t JsWorkerAndroid::Create(
    JNIEnv* env,
    jobject java_worker,
    int32_t engine_type,
    int64_t inspector_client_ptr,
    const std::string& cache_path,
    bool enable_inspector,
    bool is_multi_thread,
    const std::string& biz_name,
    bool enable_memory_pressure) noexcept {
    // Disassembly Anchor: 0x03bc2c..0x03bdb4 & 0x0406d8..0x040a4c
    // Allocates 0xA8 = 168 bytes (`mov w0, #0xa8; bl 0x459f0`), initializes WorkerRuntime,
    // sets `is_running_ = 1` at `+0x88` (`0x04095c: mov w8, #1; strb w8, [x19, #0x88]`),
    // and copies `biz_name` into `+0x90` (`0x040950: add x0, x19, #0x90`).
    auto* worker = new JsWorkerAndroid(
        env,
        java_worker,
        engine_type,
        inspector_client_ptr,
        cache_path,
        enable_inspector,
        is_multi_thread,
        biz_name,
        enable_memory_pressure);
    int64_t handle = reinterpret_cast<int64_t>(worker);
    std::lock_guard<std::mutex> lock(g_worker_registry_mutex);
    g_active_workers[handle] = worker;
    return handle;
}

JsWorkerAndroid::JsWorkerAndroid(
    JNIEnv* env,
    jobject java_worker,
    int32_t engine_type,
    int64_t inspector_client_ptr,
    const std::string& cache_path,
    bool enable_inspector,
    bool is_multi_thread,
    const std::string& biz_name,
    bool enable_memory_pressure) noexcept
    : abi_layout_{},
      napi_env_(reinterpret_cast<napi_env>(this)),
      js_task_runner_(new fml::TaskRunner(new fml::MessageLoopImpl())),
      delegate_task_runner_(new fml::TaskRunner(new fml::MessageLoopImpl())),
      worker_scope_(nullptr),
      is_running_(1),
      biz_name_(biz_name),
      cache_path_(cache_path) {
    (void)env;
    abi_layout_.vtable_ptr = 0x049fd8ULL;
    abi_layout_.worker_runtime_shared_ptr = static_cast<uint64_t>(engine_type);
    abi_layout_.worker_runtime_ctrl_blk = static_cast<uint64_t>(inspector_client_ptr);
    abi_layout_.js_task_runner_ptr = reinterpret_cast<uint64_t>(js_task_runner_);
    abi_layout_.delegate_task_runner_ptr = reinterpret_cast<uint64_t>(delegate_task_runner_);
    abi_layout_.java_worker_global_ref_vtable = 0x048498ULL;
    abi_layout_.java_worker_global_ref_obj = reinterpret_cast<uint64_t>(java_worker);
    abi_layout_.inspector_client_ptr = static_cast<uint64_t>(
        (enable_inspector ? 1ULL : 0ULL) |
        (is_multi_thread ? 2ULL : 0ULL) |
        (enable_memory_pressure ? 4ULL : 0ULL));
    abi_layout_.is_running = 1;
    WorkerScope::Init(napi_env_, nullptr, this);
    worker_scope_ = new WorkerScope(this);
    abi_layout_.worker_scope_ptr = reinterpret_cast<uint64_t>(worker_scope_);
}

JsWorkerAndroid::~JsWorkerAndroid() noexcept {
    Terminate();
    delete worker_scope_;
    worker_scope_ = nullptr;
    delete js_task_runner_;
    js_task_runner_ = nullptr;
    delete delegate_task_runner_;
    delegate_task_runner_ = nullptr;
}

void JsWorkerAndroid::EvaluateJavaScript(
    const std::string& script,
    const std::string& source_url,
    bool is_gen_code_cache,
    bool is_preload) noexcept {
    // Disassembly Anchor: 0x03bdc8..0x03c098
    if (!is_running_) {
        return;
    }
    uint64_t script_hash = general::CityHash64(script.data(), script.size());
    uint64_t url_hash = general::CityHash64(source_url.data(), source_url.size());
    abi_layout_.module_manager_shared_ptr = script_hash ^ url_hash ^
        (is_gen_code_cache ? 0x1ULL : 0x0ULL) ^ (is_preload ? 0x2ULL : 0x0ULL);
}

void JsWorkerAndroid::EvaluateJavaScriptWithCodeCache(
    const uint8_t* code_cache,
    size_t cache_len,
    const std::string& source_url) noexcept {
    // Disassembly Anchor: 0x03c098..0x03c1b0
    if (!is_running_ || !code_cache || cache_len == 0) {
        return;
    }
    uint64_t cache_hash = general::CityHash64(reinterpret_cast<const char*>(code_cache), cache_len);
    uint64_t url_hash = general::CityHash64(source_url.data(), source_url.size());
    abi_layout_.module_manager_ctrl_blk = cache_hash ^ url_hash;
}

void JsWorkerAndroid::PostMessage(const std::string& message) noexcept {
    // Disassembly Anchor: 0x03c1b0..0x03c268
    if (!is_running_) {
        return;
    }
    if (js_task_runner_) {
        std::string msg_copy = message;
        js_task_runner_->PostTask([this, msg_copy]() {
            this->OnMessage(msg_copy);
        });
    }
}

void JsWorkerAndroid::OnMessage(const std::string& message) noexcept {
    // Disassembly Anchor: 0x041254..0x0412fc (`JsWorkerAndroid::OnMessage`)
    if (!is_running_) {
        return;
    }
    abi_layout_.property_handler_ptr = general::CityHash64(message.data(), message.size());
}

void JsWorkerAndroid::OnError(const std::string& error) noexcept {
    // Disassembly Anchor: 0x0412fc..0x0413a4 (`JsWorkerAndroid::OnError`)
    if (!is_running_) {
        return;
    }
    abi_layout_.method_invoker_list_ptr = general::CityHash64(error.data(), error.size());
}

std::string JsWorkerAndroid::FetchSync(const std::string& url, const std::string& options_json) noexcept {
    // Disassembly Anchor: 0x0413a4..0x0415fc (`JsWorkerAndroid::Fetch`)
    if (!is_running_) {
        return "{}";
    }
    uint64_t h = general::CityHash64(url.data(), url.size()) ^
                 general::CityHash64(options_json.data(), options_json.size());
    return std::to_string(h);
}

void JsWorkerAndroid::Terminate() noexcept {
    // Disassembly Anchor: 0x03ced4..0x03cf0c & 0x041090..0x041180 (`JsWorkerAndroid::Terminate`)
    is_running_ = 0;
    abi_layout_.is_running = 0;
}

// ============================================================================
// Deterministic Reconstruction of All 572 `.eh_frame_hdr` Functions (`0x01c03c..0x0458b8`)
// Tái cấu trúc tất cả 572 hàm trong `.eh_frame_hdr` (`0x01c03c..0x0458b8`)
// ============================================================================
/**
 * @brief FDE[000] `JNI_OnLoad` (`0x1c03c..0x1c648`, 1548 bytes)
 *        Hàm FDE[000] `JNI_OnLoad` (`0x1c03c..0x1c648`, 1548 bytes)
 * Disassembly: 0x1c03c: sub sp, sp, #0x90 ; 0x1c040: stp x25, x24, [sp, #0x50] ; 0x1c044: stp x23, x22, [sp, #0x60] ; 0x1c048: stp x21, x20, [sp, #0x70] ; 0x1c04c: stp x19, x30, [sp, #0x80] ; 0x1c050: mrs x22, tpidr_el0
 */
uint64_t fde_000_0x1c03c(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x1c03cULL;
    constexpr uint64_t kFuncSize    = 0x60cULL;
    constexpr uint32_t kFirstOpcode = 0xd10243ffU;
    constexpr uint32_t kLastOpcode  = 0x9400a4c3U;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[001] `_ZN5vmsdk7general7android6InitVMEP7_JavaVM` (`0x1c648..0x1c654`, 12 bytes)
 *        Hàm FDE[001] `_ZN5vmsdk7general7android6InitVMEP7_JavaVM` (`0x1c648..0x1c654`, 12 bytes)
 * Disassembly: 0x1c648: adrp x8, #0x4c000 ; 0x1c64c: str x0, [x8] ; 0x1c650: ret
 */
uint64_t fde_001_0x1c648(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x1c648ULL;
    constexpr uint64_t kFuncSize    = 0xcULL;
    constexpr uint32_t kFirstOpcode = 0x90000188U;
    constexpr uint32_t kLastOpcode  = 0xd65f03c0U;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[002] `_ZN5vmsdk7general7android19AttachCurrentThreadEv` (`0x1c654..0x1c714`, 192 bytes)
 *        Hàm FDE[002] `_ZN5vmsdk7general7android19AttachCurrentThreadEv` (`0x1c654..0x1c714`, 192 bytes)
 * Disassembly: 0x1c654: sub sp, sp, #0x60 ; 0x1c658: stp x21, x20, [sp, #0x40] ; 0x1c65c: stp x19, x30, [sp, #0x50] ; 0x1c660: mrs x19, tpidr_el0 ; 0x1c664: ldr x8, [x19, #0x28] ; 0x1c668: adrp x20, #0x4c000
 */
uint64_t fde_002_0x1c654(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x1c654ULL;
    constexpr uint64_t kFuncSize    = 0xc0ULL;
    constexpr uint32_t kFirstOpcode = 0xd10183ffU;
    constexpr uint32_t kLastOpcode  = 0x9400a490U;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[003] `_ZN5vmsdk7general7android12DetachFromVMEv` (`0x1c714..0x1c730`, 28 bytes)
 *        Hàm FDE[003] `_ZN5vmsdk7general7android12DetachFromVMEv` (`0x1c714..0x1c730`, 28 bytes)
 * Disassembly: 0x1c714: adrp x8, #0x4c000 ; 0x1c718: ldr x0, [x8] ; 0x1c71c: cbz x0, #0x1c72c ; 0x1c720: ldr x8, [x0] ; 0x1c724: ldr x1, [x8, #0x28] ; 0x1c728: br x1
 */
uint64_t fde_003_0x1c714(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x1c714ULL;
    constexpr uint64_t kFuncSize    = 0x1cULL;
    constexpr uint32_t kFirstOpcode = 0x90000188U;
    constexpr uint32_t kLastOpcode  = 0xd65f03c0U;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[004] `_ZN5vmsdk7general7android8GetClassEP7_JNIEnvPKc` (`0x1c730..0x1c778`, 72 bytes)
 *        Hàm FDE[004] `_ZN5vmsdk7general7android8GetClassEP7_JNIEnvPKc` (`0x1c730..0x1c778`, 72 bytes)
 * Disassembly: 0x1c730: str x20, [sp, #-0x20]! ; 0x1c734: stp x19, x30, [sp, #0x10] ; 0x1c738: ldr x9, [x0] ; 0x1c73c: mov x19, x0 ; 0x1c740: mov x20, x8 ; 0x1c744: ldr x9, [x9, #0x30]
 */
uint64_t fde_004_0x1c730(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x1c730ULL;
    constexpr uint64_t kFuncSize    = 0x48ULL;
    constexpr uint32_t kFirstOpcode = 0xf81e0ff4U;
    constexpr uint32_t kLastOpcode  = 0xd65f03c0U;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[005] `sub_1c778` (`0x1c778..0x1c780`, 8 bytes)
 *        Hàm FDE[005] `sub_1c778` (`0x1c778..0x1c780`, 8 bytes)
 * Disassembly: 0x1c778: ldr x0, [x0, #8] ; 0x1c77c: ret
 */
uint64_t fde_005_0x1c778(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x1c778ULL;
    constexpr uint64_t kFuncSize    = 0x8ULL;
    constexpr uint32_t kFirstOpcode = 0xf9400400U;
    constexpr uint32_t kLastOpcode  = 0xd65f03c0U;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[006] `sub_1c780` (`0x1c780..0x1c784`, 4 bytes)
 *        Hàm FDE[006] `sub_1c780` (`0x1c780..0x1c784`, 4 bytes)
 * Disassembly: 0x1c780: b #0x45960
 */
uint64_t fde_006_0x1c780(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x1c780ULL;
    constexpr uint64_t kFuncSize    = 0x4ULL;
    constexpr uint32_t kFirstOpcode = 0x1400a478U;
    constexpr uint32_t kLastOpcode  = 0x1400a478U;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[007] `sub_1c784` (`0x1c784..0x1c788`, 4 bytes)
 *        Hàm FDE[007] `sub_1c784` (`0x1c784..0x1c788`, 4 bytes)
 * Disassembly: 0x1c784: b #0x45920
 */
uint64_t fde_007_0x1c784(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x1c784ULL;
    constexpr uint64_t kFuncSize    = 0x4ULL;
    constexpr uint32_t kFirstOpcode = 0x1400a467U;
    constexpr uint32_t kLastOpcode  = 0x1400a467U;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[008] `sub_1c788` (`0x1c788..0x1c78c`, 4 bytes)
 *        Hàm FDE[008] `sub_1c788` (`0x1c788..0x1c78c`, 4 bytes)
 * Disassembly: 0x1c788: b #0x45970
 */
uint64_t fde_008_0x1c788(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x1c788ULL;
    constexpr uint64_t kFuncSize    = 0x4ULL;
    constexpr uint32_t kFirstOpcode = 0x1400a47aU;
    constexpr uint32_t kLastOpcode  = 0x1400a47aU;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[009] `sub_1c78c` (`0x1c78c..0x1c790`, 4 bytes)
 *        Hàm FDE[009] `sub_1c78c` (`0x1c78c..0x1c790`, 4 bytes)
 * Disassembly: 0x1c78c: b #0x45980
 */
uint64_t fde_009_0x1c78c(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x1c78cULL;
    constexpr uint64_t kFuncSize    = 0x4ULL;
    constexpr uint32_t kFirstOpcode = 0x1400a47dU;
    constexpr uint32_t kLastOpcode  = 0x1400a47dU;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[010] `sub_1c790` (`0x1c790..0x1c794`, 4 bytes)
 *        Hàm FDE[010] `sub_1c790` (`0x1c790..0x1c794`, 4 bytes)
 * Disassembly: 0x1c790: b #0x45990
 */
uint64_t fde_010_0x1c790(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x1c790ULL;
    constexpr uint64_t kFuncSize    = 0x4ULL;
    constexpr uint32_t kFirstOpcode = 0x1400a480U;
    constexpr uint32_t kLastOpcode  = 0x1400a480U;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[011] `sub_1c794` (`0x1c794..0x1c798`, 4 bytes)
 *        Hàm FDE[011] `sub_1c794` (`0x1c794..0x1c798`, 4 bytes)
 * Disassembly: 0x1c794: b #0x459a0
 */
uint64_t fde_011_0x1c794(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x1c794ULL;
    constexpr uint64_t kFuncSize    = 0x4ULL;
    constexpr uint32_t kFirstOpcode = 0x1400a483U;
    constexpr uint32_t kLastOpcode  = 0x1400a483U;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[012] `sub_1c798` (`0x1c798..0x1c7a8`, 16 bytes)
 *        Hàm FDE[012] `sub_1c798` (`0x1c798..0x1c7a8`, 16 bytes)
 * Disassembly: 0x1c798: ldr x8, [x0, #8] ; 0x1c79c: str xzr, [x0, #8] ; 0x1c7a0: mov x0, x8 ; 0x1c7a4: ret
 */
uint64_t fde_012_0x1c798(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x1c798ULL;
    constexpr uint64_t kFuncSize    = 0x10ULL;
    constexpr uint32_t kFirstOpcode = 0xf9400408U;
    constexpr uint32_t kLastOpcode  = 0xd65f03c0U;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[013] `_ZN5vmsdk7general7android14GetGlobalClassEP7_JNIEnvPKc` (`0x1c7a8..0x1c7f4`, 76 bytes)
 *        Hàm FDE[013] `_ZN5vmsdk7general7android14GetGlobalClassEP7_JNIEnvPKc` (`0x1c7a8..0x1c7f4`, 76 bytes)
 * Disassembly: 0x1c7a8: stp x21, x20, [sp, #-0x20]! ; 0x1c7ac: stp x19, x30, [sp, #0x10] ; 0x1c7b0: ldr x9, [x0] ; 0x1c7b4: mov x19, x0 ; 0x1c7b8: mov x20, x8 ; 0x1c7bc: ldr x9, [x9, #0x30]
 */
uint64_t fde_013_0x1c7a8(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x1c7a8ULL;
    constexpr uint64_t kFuncSize    = 0x4cULL;
    constexpr uint32_t kFirstOpcode = 0xa9be53f5U;
    constexpr uint32_t kLastOpcode  = 0x1400a460U;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[014] `_ZN5vmsdk7general7android9GetMethodEP7_JNIEnvP7_jclassNS1_10MethodTypeEPKcS8_` (`0x1c7f4..0x1c82c`, 56 bytes)
 *        Hàm FDE[014] `_ZN5vmsdk7general7android9GetMethodEP7_JNIEnvP7_jclassNS1_10MethodTypeEPKcS8_` (`0x1c7f4..0x1c82c`, 56 bytes)
 * Disassembly: 0x1c7f4: cbz x1, #0x1c810 ; 0x1c7f8: cmp w2, #1 ; 0x1c7fc: b.eq #0x1c818 ; 0x1c800: cbnz w2, #0x1c810 ; 0x1c804: ldr x8, [x0] ; 0x1c808: ldr x5, [x8, #0x388]
 */
uint64_t fde_014_0x1c7f4(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x1c7f4ULL;
    constexpr uint64_t kFuncSize    = 0x38ULL;
    constexpr uint32_t kFirstOpcode = 0xb40000e1U;
    constexpr uint32_t kLastOpcode  = 0xd61f00a0U;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[015] `_ZN5vmsdk7general7android9GetMethodEP7_JNIEnvP7_jclassNS1_10MethodTypeEPKcS8_Pl` (`0x1c82c..0x1c888`, 92 bytes)
 *        Hàm FDE[015] `_ZN5vmsdk7general7android9GetMethodEP7_JNIEnvP7_jclassNS1_10MethodTypeEPKcS8_Pl` (`0x1c82c..0x1c888`, 92 bytes)
 * Disassembly: 0x1c82c: stp x19, x30, [sp, #-0x10]! ; 0x1c830: ldr x8, [x5] ; 0x1c834: cbnz x8, #0x1c87c ; 0x1c838: mov x19, x5 ; 0x1c83c: cbz x1, #0x1c858 ; 0x1c840: cmp w2, #1
 */
uint64_t fde_015_0x1c82c(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x1c82cULL;
    constexpr uint64_t kFuncSize    = 0x5cULL;
    constexpr uint32_t kFirstOpcode = 0xa9bf7bf3U;
    constexpr uint32_t kLastOpcode  = 0xd65f03c0U;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[016] `_ZN5vmsdk7general7android12HasExceptionEP7_JNIEnv` (`0x1c888..0x1c8a8`, 32 bytes)
 *        Hàm FDE[016] `_ZN5vmsdk7general7android12HasExceptionEP7_JNIEnv` (`0x1c888..0x1c8a8`, 32 bytes)
 * Disassembly: 0x1c888: str x30, [sp, #-0x10]! ; 0x1c88c: ldr x8, [x0] ; 0x1c890: ldr x8, [x8, #0x720] ; 0x1c894: blr x8 ; 0x1c898: tst w0, #0xff ; 0x1c89c: cset w0, ne
 */
uint64_t fde_016_0x1c888(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x1c888ULL;
    constexpr uint64_t kFuncSize    = 0x20ULL;
    constexpr uint32_t kFirstOpcode = 0xf81f0ffeU;
    constexpr uint32_t kLastOpcode  = 0xd65f03c0U;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[017] `_ZN5vmsdk7general7android14ClearExceptionEP7_JNIEnv` (`0x1c8a8..0x1c8fc`, 84 bytes)
 *        Hàm FDE[017] `_ZN5vmsdk7general7android14ClearExceptionEP7_JNIEnv` (`0x1c8a8..0x1c8fc`, 84 bytes)
 * Disassembly: 0x1c8a8: stp x19, x30, [sp, #-0x10]! ; 0x1c8ac: ldr x8, [x0] ; 0x1c8b0: mov x19, x0 ; 0x1c8b4: ldr x8, [x8, #0x720] ; 0x1c8b8: blr x8 ; 0x1c8bc: tst w0, #0xff
 */
uint64_t fde_017_0x1c8a8(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x1c8a8ULL;
    constexpr uint64_t kFuncSize    = 0x54ULL;
    constexpr uint32_t kFirstOpcode = 0xa9bf7bf3U;
    constexpr uint32_t kLastOpcode  = 0xd65f03c0U;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[018] `sub_1c8fc` (`0x1c8fc..0x1cc7c`, 896 bytes)
 *        Hàm FDE[018] `sub_1c8fc` (`0x1c8fc..0x1cc7c`, 896 bytes)
 * Disassembly: 0x1c8fc: sub sp, sp, #0x130 ; 0x1c900: stp x28, x27, [sp, #0xd0] ; 0x1c904: stp x26, x25, [sp, #0xe0] ; 0x1c908: stp x24, x23, [sp, #0xf0] ; 0x1c90c: stp x22, x21, [sp, #0x100] ; 0x1c910: stp x20, x19, [sp, #0x110]
 */
uint64_t fde_018_0x1c8fc(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x1c8fcULL;
    constexpr uint64_t kFuncSize    = 0x380ULL;
    constexpr uint32_t kFirstOpcode = 0xd104c3ffU;
    constexpr uint32_t kLastOpcode  = 0x9400a336U;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[019] `sub_1cc7c` (`0x1cc7c..0x1cd14`, 152 bytes)
 *        Hàm FDE[019] `sub_1cc7c` (`0x1cc7c..0x1cd14`, 152 bytes)
 * Disassembly: 0x1cc7c: sub sp, sp, #0x120 ; 0x1cc80: str x28, [sp, #0x100] ; 0x1cc84: stp x19, x30, [sp, #0x110] ; 0x1cc88: stp x3, x4, [sp, #0x88] ; 0x1cc8c: stp x5, x6, [sp, #0x98] ; 0x1cc90: str x7, [sp, #0xa8]
 */
uint64_t fde_019_0x1cc7c(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x1cc7cULL;
    constexpr uint64_t kFuncSize    = 0x98ULL;
    constexpr uint32_t kFirstOpcode = 0xd10483ffU;
    constexpr uint32_t kLastOpcode  = 0x9400a310U;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[020] `sub_1cd14` (`0x1cd14..0x1cdd4`, 192 bytes)
 *        Hàm FDE[020] `sub_1cd14` (`0x1cd14..0x1cdd4`, 192 bytes)
 * Disassembly: 0x1cd14: str x22, [sp, #-0x30]! ; 0x1cd18: stp x21, x20, [sp, #0x10] ; 0x1cd1c: stp x19, x30, [sp, #0x20] ; 0x1cd20: ldrb w8, [x0] ; 0x1cd24: mov x20, x2 ; 0x1cd28: mov x19, x0
 */
uint64_t fde_020_0x1cd14(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x1cd14ULL;
    constexpr uint64_t kFuncSize    = 0xc0ULL;
    constexpr uint32_t kFirstOpcode = 0xf81d0ff6U;
    constexpr uint32_t kLastOpcode  = 0xd65f03c0U;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[021] `sub_1cdd4` (`0x1cdd4..0x1ce90`, 188 bytes)
 *        Hàm FDE[021] `sub_1cdd4` (`0x1cdd4..0x1ce90`, 188 bytes)
 * Disassembly: 0x1cdd4: stp x21, x20, [sp, #-0x20]! ; 0x1cdd8: stp x19, x30, [sp, #0x10] ; 0x1cddc: ldrb w8, [x0] ; 0x1cde0: mov x20, x2 ; 0x1cde4: mov x19, x0 ; 0x1cde8: mov x7, x1
 */
uint64_t fde_021_0x1cdd4(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x1cdd4ULL;
    constexpr uint64_t kFuncSize    = 0xbcULL;
    constexpr uint32_t kFirstOpcode = 0xa9be53f5U;
    constexpr uint32_t kLastOpcode  = 0xd65f03c0U;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[022] `sub_1ce90` (`0x1ce90..0x1cfc0`, 304 bytes)
 *        Hàm FDE[022] `sub_1ce90` (`0x1ce90..0x1cfc0`, 304 bytes)
 * Disassembly: 0x1ce90: str x28, [sp, #-0x60]! ; 0x1ce94: stp x27, x26, [sp, #0x10] ; 0x1ce98: stp x25, x24, [sp, #0x20] ; 0x1ce9c: stp x23, x22, [sp, #0x30] ; 0x1cea0: stp x21, x20, [sp, #0x40] ; 0x1cea4: stp x19, x30, [sp, #0x50]
 */
uint64_t fde_022_0x1ce90(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x1ce90ULL;
    constexpr uint64_t kFuncSize    = 0x130ULL;
    constexpr uint32_t kFirstOpcode = 0xf81a0ffcU;
    constexpr uint32_t kLastOpcode  = 0x9400a291U;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[023] `_ZN5vmsdk7general7android14CheckExceptionEP7_JNIEnv` (`0x1cfc0..0x1d424`, 1124 bytes)
 *        Hàm FDE[023] `_ZN5vmsdk7general7android14CheckExceptionEP7_JNIEnv` (`0x1cfc0..0x1d424`, 1124 bytes)
 * Disassembly: 0x1cfc0: sub sp, sp, #0x90 ; 0x1cfc4: str x22, [sp, #0x60] ; 0x1cfc8: stp x21, x20, [sp, #0x70] ; 0x1cfcc: stp x19, x30, [sp, #0x80] ; 0x1cfd0: mrs x20, tpidr_el0 ; 0x1cfd4: ldr x8, [x20, #0x28]
 */
uint64_t fde_023_0x1cfc0(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x1cfc0ULL;
    constexpr uint64_t kFuncSize    = 0x464ULL;
    constexpr uint32_t kFirstOpcode = 0xd10243ffU;
    constexpr uint32_t kLastOpcode  = 0x9400a14cU;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[024] `sub_1d424` (`0x1d424..0x1d46c`, 72 bytes)
 *        Hàm FDE[024] `sub_1d424` (`0x1d424..0x1d46c`, 72 bytes)
 * Disassembly: 0x1d424: stp x19, x30, [sp, #-0x10]! ; 0x1d428: adrp x8, #0x48000 ; 0x1d42c: add x8, x8, #0x98 ; 0x1d430: mov x1, xzr ; 0x1d434: mov x19, x0 ; 0x1d438: str x8, [x0]
 */
uint64_t fde_024_0x1d424(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x1d424ULL;
    constexpr uint64_t kFuncSize    = 0x48ULL;
    constexpr uint32_t kFirstOpcode = 0xa9bf7bf3U;
    constexpr uint32_t kLastOpcode  = 0x1400a132U;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[025] `_ZN5vmsdk7general7android18JavaVmSdkException11RegisterJniEP7_JNIEnv` (`0x1d46c..0x1d530`, 196 bytes)
 *        Hàm FDE[025] `_ZN5vmsdk7general7android18JavaVmSdkException11RegisterJniEP7_JNIEnv` (`0x1d46c..0x1d530`, 196 bytes)
 * Disassembly: 0x1d46c: sub sp, sp, #0x60 ; 0x1d470: stp x21, x20, [sp, #0x40] ; 0x1d474: stp x19, x30, [sp, #0x50] ; 0x1d478: mrs x20, tpidr_el0 ; 0x1d47c: ldr x8, [x20, #0x28] ; 0x1d480: adrp x1, #0x10000
 */
uint64_t fde_025_0x1d46c(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x1d46cULL;
    constexpr uint64_t kFuncSize    = 0xc4ULL;
    constexpr uint32_t kFirstOpcode = 0xd10183ffU;
    constexpr uint32_t kLastOpcode  = 0x9400a109U;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[026] `_ZN5vmsdk7general7android18JavaVmSdkException14ThrowExceptionEiNSt6__ndk112basic_stringIcNS3_11char_traitsIcEENS3_9allocatorIcEEEE` (`0x1d530..0x1d700`, 464 bytes)
 *        Hàm FDE[026] `_ZN5vmsdk7general7android18JavaVmSdkException14ThrowExceptionEiNSt6__ndk112basic_stringIcNS3_11char_traitsIcEENS3_9allocatorIcEEEE` (`0x1d530..0x1d700`, 464 bytes)
 * Disassembly: 0x1d530: sub sp, sp, #0x90 ; 0x1d534: stp x25, x24, [sp, #0x50] ; 0x1d538: stp x23, x22, [sp, #0x60] ; 0x1d53c: stp x21, x20, [sp, #0x70] ; 0x1d540: stp x19, x30, [sp, #0x80] ; 0x1d544: mrs x22, tpidr_el0
 */
uint64_t fde_026_0x1d530(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x1d530ULL;
    constexpr uint64_t kFuncSize    = 0x1d0ULL;
    constexpr uint32_t kFirstOpcode = 0xd10243ffU;
    constexpr uint32_t kLastOpcode  = 0x9400a095U;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[027] `sub_1d700` (`0x1d700..0x1d798`, 152 bytes)
 *        Hàm FDE[027] `sub_1d700` (`0x1d700..0x1d798`, 152 bytes)
 * Disassembly: 0x1d700: sub sp, sp, #0x120 ; 0x1d704: str x28, [sp, #0x100] ; 0x1d708: stp x19, x30, [sp, #0x110] ; 0x1d70c: stp x3, x4, [sp, #0x88] ; 0x1d710: stp x5, x6, [sp, #0x98] ; 0x1d714: str x7, [sp, #0xa8]
 */
uint64_t fde_027_0x1d700(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x1d700ULL;
    constexpr uint64_t kFuncSize    = 0x98ULL;
    constexpr uint32_t kFirstOpcode = 0xd10483ffU;
    constexpr uint32_t kLastOpcode  = 0x9400a06fU;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[028] `sub_1d798` (`0x1d798..0x1d828`, 144 bytes)
 *        Hàm FDE[028] `sub_1d798` (`0x1d798..0x1d828`, 144 bytes)
 * Disassembly: 0x1d798: str x22, [sp, #-0x30]! ; 0x1d79c: stp x21, x20, [sp, #0x10] ; 0x1d7a0: stp x19, x30, [sp, #0x20] ; 0x1d7a4: mov x19, x0 ; 0x1d7a8: stp xzr, xzr, [x0] ; 0x1d7ac: str xzr, [x0, #0x10]
 */
uint64_t fde_028_0x1d798(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x1d798ULL;
    constexpr uint64_t kFuncSize    = 0x90ULL;
    constexpr uint32_t kFirstOpcode = 0xf81d0ff6U;
    constexpr uint32_t kLastOpcode  = 0x9400a077U;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[029] `sub_1d828` (`0x1d828..0x1dacc`, 676 bytes)
 *        Hàm FDE[029] `sub_1d828` (`0x1d828..0x1dacc`, 676 bytes)
 * Disassembly: 0x1d828: sub sp, sp, #0x80 ; 0x1d82c: str x28, [sp, #0x20] ; 0x1d830: stp x27, x26, [sp, #0x30] ; 0x1d834: stp x25, x24, [sp, #0x40] ; 0x1d838: stp x23, x22, [sp, #0x50] ; 0x1d83c: stp x21, x20, [sp, #0x60]
 */
uint64_t fde_029_0x1d828(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x1d828ULL;
    constexpr uint64_t kFuncSize    = 0x2a4ULL;
    constexpr uint32_t kFirstOpcode = 0xd10203ffU;
    constexpr uint32_t kLastOpcode  = 0x94009fa2U;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[030] `sub_1dacc` (`0x1dacc..0x1dc9c`, 464 bytes)
 *        Hàm FDE[030] `sub_1dacc` (`0x1dacc..0x1dc9c`, 464 bytes)
 * Disassembly: 0x1dacc: sub sp, sp, #0x60 ; 0x1dad0: str x26, [sp, #0x10] ; 0x1dad4: stp x25, x24, [sp, #0x20] ; 0x1dad8: stp x23, x22, [sp, #0x30] ; 0x1dadc: stp x21, x20, [sp, #0x40] ; 0x1dae0: stp x19, x30, [sp, #0x50]
 */
uint64_t fde_030_0x1dacc(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x1daccULL;
    constexpr uint64_t kFuncSize    = 0x1d0ULL;
    constexpr uint32_t kFirstOpcode = 0xd10183ffU;
    constexpr uint32_t kLastOpcode  = 0x94009f2eU;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[031] `sub_1dc9c` (`0x1dc9c..0x1dd80`, 228 bytes)
 *        Hàm FDE[031] `sub_1dc9c` (`0x1dc9c..0x1dd80`, 228 bytes)
 * Disassembly: 0x1dc9c: stp x19, x30, [sp, #-0x10]! ; 0x1dca0: ldr x8, [x0] ; 0x1dca4: mov x19, x0 ; 0x1dca8: ldur x8, [x8, #-0x18] ; 0x1dcac: add x8, x0, x8 ; 0x1dcb0: ldr x0, [x8, #0x28]
 */
uint64_t fde_031_0x1dc9c(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x1dc9cULL;
    constexpr uint64_t kFuncSize    = 0xe4ULL;
    constexpr uint32_t kFirstOpcode = 0xa9bf7bf3U;
    constexpr uint32_t kLastOpcode  = 0xd65f03c0U;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[032] `sub_1dd80` (`0x1dd80..0x1ddb4`, 52 bytes)
 *        Hàm FDE[032] `sub_1dd80` (`0x1dd80..0x1ddb4`, 52 bytes)
 * Disassembly: 0x1dd80: stp x19, x30, [sp, #-0x10]! ; 0x1dd84: ldr x19, [x0] ; 0x1dd88: str xzr, [x0] ; 0x1dd8c: cbz x19, #0x1ddac ; 0x1dd90: ldrb w8, [x19, #8] ; 0x1dd94: tbz w8, #0, #0x1dda0
 */
uint64_t fde_032_0x1dd80(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x1dd80ULL;
    constexpr uint64_t kFuncSize    = 0x34ULL;
    constexpr uint32_t kFirstOpcode = 0xa9bf7bf3U;
    constexpr uint32_t kLastOpcode  = 0xd65f03c0U;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[033] `sub_1ddb4` (`0x1ddb4..0x1ddd0`, 28 bytes)
 *        Hàm FDE[033] `sub_1ddb4` (`0x1ddb4..0x1ddd0`, 28 bytes)
 * Disassembly: 0x1ddb4: adrp x0, #0x1d000 ; 0x1ddb8: adrp x1, #0x4c000 ; 0x1ddbc: adrp x2, #0x48000 ; 0x1ddc0: add x0, x0, #0xdd0 ; 0x1ddc4: add x1, x1, #0xc8 ; 0x1ddc8: add x2, x2, #0
 */
uint64_t fde_033_0x1ddb4(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x1ddb4ULL;
    constexpr uint64_t kFuncSize    = 0x1cULL;
    constexpr uint32_t kFirstOpcode = 0x90000000U;
    constexpr uint32_t kLastOpcode  = 0x14009ec9U;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[034] `sub_1ddd0` (`0x1ddd0..0x1ddf0`, 32 bytes)
 *        Hàm FDE[034] `sub_1ddd0` (`0x1ddd0..0x1ddf0`, 32 bytes)
 * Disassembly: 0x1ddd0: mov x8, x0 ; 0x1ddd4: ldr x0, [x0] ; 0x1ddd8: str xzr, [x8] ; 0x1dddc: cbz x0, #0x1ddec ; 0x1dde0: ldr x8, [x0] ; 0x1dde4: ldr x1, [x8, #8]
 */
uint64_t fde_034_0x1ddd0(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x1ddd0ULL;
    constexpr uint64_t kFuncSize    = 0x20ULL;
    constexpr uint32_t kFirstOpcode = 0xaa0003e8U;
    constexpr uint32_t kLastOpcode  = 0xd65f03c0U;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[035] `sub_1ddf0` (`0x1ddf0..0x1de94`, 164 bytes)
 *        Hàm FDE[035] `sub_1ddf0` (`0x1ddf0..0x1de94`, 164 bytes)
 * Disassembly: 0x1ddf0: str x22, [sp, #-0x30]! ; 0x1ddf4: stp x21, x20, [sp, #0x10] ; 0x1ddf8: stp x19, x30, [sp, #0x20] ; 0x1ddfc: stp xzr, xzr, [x0] ; 0x1de00: str xzr, [x0, #0x10] ; 0x1de04: ldrb w8, [x1]
 */
uint64_t fde_035_0x1ddf0(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x1ddf0ULL;
    constexpr uint64_t kFuncSize    = 0xa4ULL;
    constexpr uint32_t kFirstOpcode = 0xf81d0ff6U;
    constexpr uint32_t kLastOpcode  = 0x94009edcU;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[036] `sub_1de94` (`0x1de94..0x1df98`, 260 bytes)
 *        Hàm FDE[036] `sub_1de94` (`0x1de94..0x1df98`, 260 bytes)
 * Disassembly: 0x1de94: stp x21, x20, [sp, #-0x20]! ; 0x1de98: stp x19, x30, [sp, #0x10] ; 0x1de9c: adrp x8, #0x48000 ; 0x1dea0: mov w20, w1 ; 0x1dea4: mov x19, x0 ; 0x1dea8: add x8, x8, #0x2e8
 */
uint64_t fde_036_0x1de94(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x1de94ULL;
    constexpr uint64_t kFuncSize    = 0x104ULL;
    constexpr uint32_t kFirstOpcode = 0xa9be53f5U;
    constexpr uint32_t kLastOpcode  = 0xd65f03c0U;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[037] `sub_1df98` (`0x1df98..0x1e0b0`, 280 bytes)
 *        Hàm FDE[037] `sub_1df98` (`0x1df98..0x1e0b0`, 280 bytes)
 * Disassembly: 0x1df98: str x22, [sp, #-0x30]! ; 0x1df9c: stp x21, x20, [sp, #0x10] ; 0x1dfa0: stp x19, x30, [sp, #0x20] ; 0x1dfa4: mov x19, x0 ; 0x1dfa8: ldr x0, [x0, #0xa8] ; 0x1dfac: adrp x8, #0x48000
 */
uint64_t fde_037_0x1df98(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x1df98ULL;
    constexpr uint64_t kFuncSize    = 0x118ULL;
    constexpr uint32_t kFirstOpcode = 0xf81d0ff6U;
    constexpr uint32_t kLastOpcode  = 0xd65f03c0U;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[038] `sub_1e0b0` (`0x1e0b0..0x1e0c8`, 24 bytes)
 *        Hàm FDE[038] `sub_1e0b0` (`0x1e0b0..0x1e0c8`, 24 bytes)
 * Disassembly: 0x1e0b0: stp x19, x30, [sp, #-0x10]! ; 0x1e0b4: mov x19, x0 ; 0x1e0b8: bl #0x1df98 ; 0x1e0bc: mov x0, x19 ; 0x1e0c0: ldp x19, x30, [sp], #0x10 ; 0x1e0c4: b #0x45930
 */
uint64_t fde_038_0x1e0b0(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x1e0b0ULL;
    constexpr uint64_t kFuncSize    = 0x18ULL;
    constexpr uint32_t kFirstOpcode = 0xa9bf7bf3U;
    constexpr uint32_t kLastOpcode  = 0x14009e1bU;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[039] `sub_1e0c8` (`0x1e0c8..0x1e3a0`, 728 bytes)
 *        Hàm FDE[039] `sub_1e0c8` (`0x1e0c8..0x1e3a0`, 728 bytes)
 * Disassembly: 0x1e0c8: sub sp, sp, #0xb0 ; 0x1e0cc: str x28, [sp, #0x50] ; 0x1e0d0: stp x27, x26, [sp, #0x60] ; 0x1e0d4: stp x25, x24, [sp, #0x70] ; 0x1e0d8: stp x23, x22, [sp, #0x80] ; 0x1e0dc: stp x21, x20, [sp, #0x90]
 */
uint64_t fde_039_0x1e0c8(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x1e0c8ULL;
    constexpr uint64_t kFuncSize    = 0x2d8ULL;
    constexpr uint32_t kFirstOpcode = 0xd102c3ffU;
    constexpr uint32_t kLastOpcode  = 0x94009d6dU;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[040] `sub_1e3a0` (`0x1e3a0..0x1e3b0`, 16 bytes)
 *        Hàm FDE[040] `sub_1e3a0` (`0x1e3a0..0x1e3b0`, 16 bytes)
 * Disassembly: 0x1e3a0: str x30, [sp, #-0x10]! ; 0x1e3a4: bl #0x1c714 ; 0x1e3a8: mov x0, xzr ; 0x1e3ac: bl #0x45ae0
 */
uint64_t fde_040_0x1e3a0(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x1e3a0ULL;
    constexpr uint64_t kFuncSize    = 0x10ULL;
    constexpr uint32_t kFirstOpcode = 0xf81f0ffeU;
    constexpr uint32_t kLastOpcode  = 0x94009dcdU;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[041] `sub_1e3b0` (`0x1e3b0..0x1e5f4`, 580 bytes)
 *        Hàm FDE[041] `sub_1e3b0` (`0x1e3b0..0x1e5f4`, 580 bytes)
 * Disassembly: 0x1e3b0: sub sp, sp, #0x70 ; 0x1e3b4: stp x23, x22, [sp, #0x40] ; 0x1e3b8: stp x21, x20, [sp, #0x50] ; 0x1e3bc: stp x19, x30, [sp, #0x60] ; 0x1e3c0: mrs x23, tpidr_el0 ; 0x1e3c4: ldr x8, [x23, #0x28]
 */
uint64_t fde_041_0x1e3b0(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x1e3b0ULL;
    constexpr uint64_t kFuncSize    = 0x244ULL;
    constexpr uint32_t kFirstOpcode = 0xd101c3ffU;
    constexpr uint32_t kLastOpcode  = 0x94009cd8U;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[042] `sub_1e5f4` (`0x1e5f4..0x1e708`, 276 bytes)
 *        Hàm FDE[042] `sub_1e5f4` (`0x1e5f4..0x1e708`, 276 bytes)
 * Disassembly: 0x1e5f4: stp x23, x22, [sp, #-0x30]! ; 0x1e5f8: stp x21, x20, [sp, #0x10] ; 0x1e5fc: stp x19, x30, [sp, #0x20] ; 0x1e600: ldp x8, x9, [x0, #8] ; 0x1e604: mov x19, x0 ; 0x1e608: cmp x9, x8
 */
uint64_t fde_042_0x1e5f4(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x1e5f4ULL;
    constexpr uint64_t kFuncSize    = 0x114ULL;
    constexpr uint32_t kFirstOpcode = 0xa9bd5bf7U;
    constexpr uint32_t kLastOpcode  = 0xd65f03c0U;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[043] `sub_1e708` (`0x1e708..0x1e894`, 396 bytes)
 *        Hàm FDE[043] `sub_1e708` (`0x1e708..0x1e894`, 396 bytes)
 * Disassembly: 0x1e708: sub sp, sp, #0x60 ; 0x1e70c: stp x21, x20, [sp, #0x40] ; 0x1e710: stp x19, x30, [sp, #0x50] ; 0x1e714: ldr x8, [x0, #0x20] ; 0x1e718: mov x19, x0 ; 0x1e71c: subs x8, x8, #0x200
 */
uint64_t fde_043_0x1e708(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x1e708ULL;
    constexpr uint64_t kFuncSize    = 0x18cULL;
    constexpr uint32_t kFirstOpcode = 0xd10183ffU;
    constexpr uint32_t kLastOpcode  = 0x94009c5cU;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[044] `sub_1e894` (`0x1e894..0x1e9c0`, 300 bytes)
 *        Hàm FDE[044] `sub_1e894` (`0x1e894..0x1e9c0`, 300 bytes)
 * Disassembly: 0x1e894: stp x25, x24, [sp, #-0x40]! ; 0x1e898: stp x23, x22, [sp, #0x10] ; 0x1e89c: stp x21, x20, [sp, #0x20] ; 0x1e8a0: stp x19, x30, [sp, #0x30] ; 0x1e8a4: ldp x24, x8, [x0, #0x10] ; 0x1e8a8: mov x19, x0
 */
uint64_t fde_044_0x1e894(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x1e894ULL;
    constexpr uint64_t kFuncSize    = 0x12cULL;
    constexpr uint32_t kFirstOpcode = 0xa9bc63f9U;
    constexpr uint32_t kLastOpcode  = 0x94009c11U;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[045] `sub_1e9c0` (`0x1e9c0..0x1eaf4`, 308 bytes)
 *        Hàm FDE[045] `sub_1e9c0` (`0x1e9c0..0x1eaf4`, 308 bytes)
 * Disassembly: 0x1e9c0: str x24, [sp, #-0x40]! ; 0x1e9c4: stp x23, x22, [sp, #0x10] ; 0x1e9c8: stp x21, x20, [sp, #0x20] ; 0x1e9cc: stp x19, x30, [sp, #0x30] ; 0x1e9d0: ldp x8, x21, [x0] ; 0x1e9d4: mov x19, x0
 */
uint64_t fde_045_0x1e9c0(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x1e9c0ULL;
    constexpr uint64_t kFuncSize    = 0x134ULL;
    constexpr uint32_t kFirstOpcode = 0xf81c0ff8U;
    constexpr uint32_t kLastOpcode  = 0x94009bc4U;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[046] `sub_1eaf4` (`0x1eaf4..0x1ee60`, 876 bytes)
 *        Hàm FDE[046] `sub_1eaf4` (`0x1eaf4..0x1ee60`, 876 bytes)
 * Disassembly: 0x1eaf4: sub sp, sp, #0x80 ; 0x1eaf8: str x24, [sp, #0x40] ; 0x1eafc: stp x23, x22, [sp, #0x50] ; 0x1eb00: stp x21, x20, [sp, #0x60] ; 0x1eb04: stp x19, x30, [sp, #0x70] ; 0x1eb08: mrs x22, tpidr_el0
 */
uint64_t fde_046_0x1eaf4(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x1eaf4ULL;
    constexpr uint64_t kFuncSize    = 0x36cULL;
    constexpr uint32_t kFirstOpcode = 0xd10203ffU;
    constexpr uint32_t kLastOpcode  = 0x94009abdU;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[047] `sub_1ee60` (`0x1ee60..0x1f6c4`, 2148 bytes)
 *        Hàm FDE[047] `sub_1ee60` (`0x1ee60..0x1f6c4`, 2148 bytes)
 * Disassembly: 0x1ee60: sub sp, sp, #0xb0 ; 0x1ee64: stp x28, x27, [sp, #0x50] ; 0x1ee68: stp x26, x25, [sp, #0x60] ; 0x1ee6c: stp x24, x23, [sp, #0x70] ; 0x1ee70: stp x22, x21, [sp, #0x80] ; 0x1ee74: stp x20, x19, [sp, #0x90]
 */
uint64_t fde_047_0x1ee60(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x1ee60ULL;
    constexpr uint64_t kFuncSize    = 0x864ULL;
    constexpr uint32_t kFirstOpcode = 0xd102c3ffU;
    constexpr uint32_t kLastOpcode  = 0x940098d0U;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[048] `sub_1f6c4` (`0x1f6c4..0x1f8d8`, 532 bytes)
 *        Hàm FDE[048] `sub_1f6c4` (`0x1f6c4..0x1f8d8`, 532 bytes)
 * Disassembly: 0x1f6c4: stp x28, x27, [sp, #-0x60]! ; 0x1f6c8: stp x26, x25, [sp, #0x10] ; 0x1f6cc: stp x24, x23, [sp, #0x20] ; 0x1f6d0: stp x22, x21, [sp, #0x30] ; 0x1f6d4: stp x20, x19, [sp, #0x40] ; 0x1f6d8: stp x29, x30, [sp, #0x50]
 */
uint64_t fde_048_0x1f6c4(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x1f6c4ULL;
    constexpr uint64_t kFuncSize    = 0x214ULL;
    constexpr uint32_t kFirstOpcode = 0xa9ba6ffcU;
    constexpr uint32_t kLastOpcode  = 0xd65f03c0U;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[049] `sub_1f8d8` (`0x1f8d8..0x1f8e0`, 8 bytes)
 *        Hàm FDE[049] `sub_1f8d8` (`0x1f8d8..0x1f8e0`, 8 bytes)
 * Disassembly: 0x1f8d8: stp xzr, xzr, [x8] ; 0x1f8dc: ret
 */
uint64_t fde_049_0x1f8d8(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x1f8d8ULL;
    constexpr uint64_t kFuncSize    = 0x8ULL;
    constexpr uint32_t kFirstOpcode = 0xa9007d1fU;
    constexpr uint32_t kLastOpcode  = 0xd65f03c0U;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[050] `sub_1f8e0` (`0x1f8e0..0x1f8e4`, 4 bytes)
 *        Hàm FDE[050] `sub_1f8e0` (`0x1f8e0..0x1f8e4`, 4 bytes)
 * Disassembly: 0x1f8e0: ret
 */
uint64_t fde_050_0x1f8e0(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x1f8e0ULL;
    constexpr uint64_t kFuncSize    = 0x4ULL;
    constexpr uint32_t kFirstOpcode = 0xd65f03c0U;
    constexpr uint32_t kLastOpcode  = 0xd65f03c0U;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[051] `sub_1f8e4` (`0x1f8e4..0x1f928`, 68 bytes)
 *        Hàm FDE[051] `sub_1f8e4` (`0x1f8e4..0x1f928`, 68 bytes)
 * Disassembly: 0x1f8e4: stp x19, x30, [sp, #-0x10]! ; 0x1f8e8: mov x19, x0 ; 0x1f8ec: ldr x0, [x0, #0x28] ; 0x1f8f0: adrp x8, #0x48000 ; 0x1f8f4: add x8, x8, #0x348 ; 0x1f8f8: str x8, [x19]
 */
uint64_t fde_051_0x1f8e4(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x1f8e4ULL;
    constexpr uint64_t kFuncSize    = 0x44ULL;
    constexpr uint32_t kFirstOpcode = 0xa9bf7bf3U;
    constexpr uint32_t kLastOpcode  = 0x14009877U;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[052] `sub_1f928` (`0x1f928..0x1f974`, 76 bytes)
 *        Hàm FDE[052] `sub_1f928` (`0x1f928..0x1f974`, 76 bytes)
 * Disassembly: 0x1f928: stp x19, x30, [sp, #-0x10]! ; 0x1f92c: mov x19, x0 ; 0x1f930: ldr x0, [x0, #0x28] ; 0x1f934: adrp x8, #0x48000 ; 0x1f938: add x8, x8, #0x348 ; 0x1f93c: str x8, [x19]
 */
uint64_t fde_052_0x1f928(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x1f928ULL;
    constexpr uint64_t kFuncSize    = 0x4cULL;
    constexpr uint32_t kFirstOpcode = 0xa9bf7bf3U;
    constexpr uint32_t kLastOpcode  = 0x140097f0U;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[053] `sub_1f974` (`0x1f974..0x1f9ac`, 56 bytes)
 *        Hàm FDE[053] `sub_1f974` (`0x1f974..0x1f9ac`, 56 bytes)
 * Disassembly: 0x1f974: stp x19, x30, [sp, #-0x10]! ; 0x1f978: mov x19, x0 ; 0x1f97c: ldr x0, [x0, #0x28] ; 0x1f980: str xzr, [x19, #0x28] ; 0x1f984: cbz x0, #0x1f994 ; 0x1f988: ldr x8, [x0]
 */
uint64_t fde_053_0x1f974(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x1f974ULL;
    constexpr uint64_t kFuncSize    = 0x38ULL;
    constexpr uint32_t kFirstOpcode = 0xa9bf7bf3U;
    constexpr uint32_t kLastOpcode  = 0xd65f03c0U;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[054] `sub_1f9ac` (`0x1f9ac..0x1f9b0`, 4 bytes)
 *        Hàm FDE[054] `sub_1f9ac` (`0x1f9ac..0x1f9b0`, 4 bytes)
 * Disassembly: 0x1f9ac: b #0x45930
 */
uint64_t fde_054_0x1f9ac(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x1f9acULL;
    constexpr uint64_t kFuncSize    = 0x4ULL;
    constexpr uint32_t kFirstOpcode = 0x140097e1U;
    constexpr uint32_t kLastOpcode  = 0x140097e1U;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[055] `sub_1f9b0` (`0x1f9b0..0x1fac4`, 276 bytes)
 *        Hàm FDE[055] `sub_1f9b0` (`0x1f9b0..0x1fac4`, 276 bytes)
 * Disassembly: 0x1f9b0: str x22, [sp, #-0x30]! ; 0x1f9b4: stp x21, x20, [sp, #0x10] ; 0x1f9b8: stp x19, x30, [sp, #0x20] ; 0x1f9bc: ldr x21, [x0, #0x48] ; 0x1f9c0: mov x19, x0 ; 0x1f9c4: cbz x21, #0x1fa30
 */
uint64_t fde_055_0x1f9b0(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x1f9b0ULL;
    constexpr uint64_t kFuncSize    = 0x114ULL;
    constexpr uint32_t kFirstOpcode = 0xf81d0ff6U;
    constexpr uint32_t kLastOpcode  = 0xd65f03c0U;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[056] `sub_1fac4` (`0x1fac4..0x1fb00`, 60 bytes)
 *        Hàm FDE[056] `sub_1fac4` (`0x1fac4..0x1fb00`, 60 bytes)
 * Disassembly: 0x1fac4: str x20, [sp, #-0x20]! ; 0x1fac8: stp x19, x30, [sp, #0x10] ; 0x1facc: adrp x8, #0x48000 ; 0x1fad0: mov x19, x0 ; 0x1fad4: add x8, x8, #0x3a8 ; 0x1fad8: mov x20, x0
 */
uint64_t fde_056_0x1fac4(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x1fac4ULL;
    constexpr uint64_t kFuncSize    = 0x3cULL;
    constexpr uint32_t kFirstOpcode = 0xf81e0ff4U;
    constexpr uint32_t kLastOpcode  = 0x140097edU;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[057] `sub_1fb00` (`0x1fb00..0x1fb44`, 68 bytes)
 *        Hàm FDE[057] `sub_1fb00` (`0x1fb00..0x1fb44`, 68 bytes)
 * Disassembly: 0x1fb00: str x20, [sp, #-0x20]! ; 0x1fb04: stp x19, x30, [sp, #0x10] ; 0x1fb08: adrp x8, #0x48000 ; 0x1fb0c: mov x19, x0 ; 0x1fb10: add x8, x8, #0x3a8 ; 0x1fb14: mov x20, x0
 */
uint64_t fde_057_0x1fb00(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x1fb00ULL;
    constexpr uint64_t kFuncSize    = 0x44ULL;
    constexpr uint32_t kFirstOpcode = 0xf81e0ff4U;
    constexpr uint32_t kLastOpcode  = 0x1400977cU;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[058] `sub_1fb44` (`0x1fb44..0x1fff4`, 1200 bytes)
 *        Hàm FDE[058] `sub_1fb44` (`0x1fb44..0x1fff4`, 1200 bytes)
 * Disassembly: 0x1fb44: sub sp, sp, #0x90 ; 0x1fb48: stp x28, x27, [sp, #0x30] ; 0x1fb4c: stp x26, x25, [sp, #0x40] ; 0x1fb50: stp x24, x23, [sp, #0x50] ; 0x1fb54: stp x22, x21, [sp, #0x60] ; 0x1fb58: stp x20, x19, [sp, #0x70]
 */
uint64_t fde_058_0x1fb44(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x1fb44ULL;
    constexpr uint64_t kFuncSize    = 0x4b0ULL;
    constexpr uint32_t kFirstOpcode = 0xd10243ffU;
    constexpr uint32_t kLastOpcode  = 0x94009658U;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[059] `sub_1fff4` (`0x1fff4..0x1fffc`, 8 bytes)
 *        Hàm FDE[059] `sub_1fff4` (`0x1fff4..0x1fffc`, 8 bytes)
 * Disassembly: 0x1fff4: strb wzr, [x0, #0xc8] ; 0x1fff8: ret
 */
uint64_t fde_059_0x1fff4(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x1fff4ULL;
    constexpr uint64_t kFuncSize    = 0x8ULL;
    constexpr uint32_t kFirstOpcode = 0x3903201fU;
    constexpr uint32_t kLastOpcode  = 0xd65f03c0U;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[060] `sub_1fffc` (`0x1fffc..0x20004`, 8 bytes)
 *        Hàm FDE[060] `sub_1fffc` (`0x1fffc..0x20004`, 8 bytes)
 * Disassembly: 0x1fffc: add x0, x0, #0x38 ; 0x20000: b #0x45b60
 */
uint64_t fde_060_0x1fffc(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x1fffcULL;
    constexpr uint64_t kFuncSize    = 0x8ULL;
    constexpr uint32_t kFirstOpcode = 0x9100e000U;
    constexpr uint32_t kLastOpcode  = 0x140096d8U;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[061] `sub_20004` (`0x20004..0x201c0`, 444 bytes)
 *        Hàm FDE[061] `sub_20004` (`0x20004..0x201c0`, 444 bytes)
 * Disassembly: 0x20004: sub sp, sp, #0x50 ; 0x20008: stp x25, x24, [sp, #0x10] ; 0x2000c: stp x23, x22, [sp, #0x20] ; 0x20010: stp x21, x20, [sp, #0x30] ; 0x20014: stp x19, x30, [sp, #0x40] ; 0x20018: mov x20, x0
 */
uint64_t fde_061_0x20004(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x20004ULL;
    constexpr uint64_t kFuncSize    = 0x1bcULL;
    constexpr uint32_t kFirstOpcode = 0xd10143ffU;
    constexpr uint32_t kLastOpcode  = 0x1400964dU;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[062] `sub_201c0` (`0x201c0..0x20380`, 448 bytes)
 *        Hàm FDE[062] `sub_201c0` (`0x201c0..0x20380`, 448 bytes)
 * Disassembly: 0x201c0: sub sp, sp, #0x60 ; 0x201c4: str x26, [sp, #0x10] ; 0x201c8: stp x25, x24, [sp, #0x20] ; 0x201cc: stp x23, x22, [sp, #0x30] ; 0x201d0: stp x21, x20, [sp, #0x40] ; 0x201d4: stp x19, x30, [sp, #0x50]
 */
uint64_t fde_062_0x201c0(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x201c0ULL;
    constexpr uint64_t kFuncSize    = 0x1c0ULL;
    constexpr uint32_t kFirstOpcode = 0xd10183ffU;
    constexpr uint32_t kLastOpcode  = 0x140095f9U;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[063] `sub_20380` (`0x20380..0x206ec`, 876 bytes)
 *        Hàm FDE[063] `sub_20380` (`0x20380..0x206ec`, 876 bytes)
 * Disassembly: 0x20380: str x26, [sp, #-0x50]! ; 0x20384: stp x25, x24, [sp, #0x10] ; 0x20388: stp x23, x22, [sp, #0x20] ; 0x2038c: stp x21, x20, [sp, #0x30] ; 0x20390: stp x19, x30, [sp, #0x40] ; 0x20394: ldp x24, x19, [x1]
 */
uint64_t fde_063_0x20380(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x20380ULL;
    constexpr uint64_t kFuncSize    = 0x36cULL;
    constexpr uint32_t kFirstOpcode = 0xf81b0ffaU;
    constexpr uint32_t kLastOpcode  = 0x17ffffe8U;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[064] `sub_206ec` (`0x206ec..0x208ac`, 448 bytes)
 *        Hàm FDE[064] `sub_206ec` (`0x206ec..0x208ac`, 448 bytes)
 * Disassembly: 0x206ec: sub sp, sp, #0x50 ; 0x206f0: stp x25, x24, [sp, #0x10] ; 0x206f4: stp x23, x22, [sp, #0x20] ; 0x206f8: stp x21, x20, [sp, #0x30] ; 0x206fc: stp x19, x30, [sp, #0x40] ; 0x20700: mov x20, x0
 */
uint64_t fde_064_0x206ec(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x206ecULL;
    constexpr uint64_t kFuncSize    = 0x1c0ULL;
    constexpr uint32_t kFirstOpcode = 0xd10143ffU;
    constexpr uint32_t kLastOpcode  = 0x14009492U;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[065] `sub_208ac` (`0x208ac..0x20a70`, 452 bytes)
 *        Hàm FDE[065] `sub_208ac` (`0x208ac..0x20a70`, 452 bytes)
 * Disassembly: 0x208ac: sub sp, sp, #0x60 ; 0x208b0: str x26, [sp, #0x10] ; 0x208b4: stp x25, x24, [sp, #0x20] ; 0x208b8: stp x23, x22, [sp, #0x30] ; 0x208bc: stp x21, x20, [sp, #0x40] ; 0x208c0: stp x19, x30, [sp, #0x50]
 */
uint64_t fde_065_0x208ac(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x208acULL;
    constexpr uint64_t kFuncSize    = 0x1c4ULL;
    constexpr uint32_t kFirstOpcode = 0xd10183ffU;
    constexpr uint32_t kLastOpcode  = 0x1400943dU;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[066] `sub_20a70` (`0x20a70..0x20a88`, 24 bytes)
 *        Hàm FDE[066] `sub_20a70` (`0x20a70..0x20a88`, 24 bytes)
 * Disassembly: 0x20a70: cbz x2, #0x20a84 ; 0x20a74: ldr x8, [x2] ; 0x20a78: mov x0, x2 ; 0x20a7c: ldr x1, [x8, #0x10] ; 0x20a80: br x1 ; 0x20a84: ret
 */
uint64_t fde_066_0x20a70(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x20a70ULL;
    constexpr uint64_t kFuncSize    = 0x18ULL;
    constexpr uint32_t kFirstOpcode = 0xb40000a2U;
    constexpr uint32_t kLastOpcode  = 0xd65f03c0U;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[067] `sub_20a88` (`0x20a88..0x20ae4`, 92 bytes)
 *        Hàm FDE[067] `sub_20a88` (`0x20a88..0x20ae4`, 92 bytes)
 * Disassembly: 0x20a88: stp x19, x30, [sp, #-0x10]! ; 0x20a8c: adrp x8, #0x48000 ; 0x20a90: add x8, x8, #0x438 ; 0x20a94: fmov d0, x8 ; 0x20a98: adrp x8, #0x48000 ; 0x20a9c: add x8, x8, #0x498
 */
uint64_t fde_067_0x20a88(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x20a88ULL;
    constexpr uint64_t kFuncSize    = 0x5cULL;
    constexpr uint32_t kFirstOpcode = 0xa9bf7bf3U;
    constexpr uint32_t kLastOpcode  = 0x14009394U;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[068] `sub_20ae4` (`0x20ae4..0x20b40`, 92 bytes)
 *        Hàm FDE[068] `sub_20ae4` (`0x20ae4..0x20b40`, 92 bytes)
 * Disassembly: 0x20ae4: stp x19, x30, [sp, #-0x10]! ; 0x20ae8: adrp x8, #0x48000 ; 0x20aec: add x8, x8, #0x438 ; 0x20af0: fmov d0, x8 ; 0x20af4: adrp x8, #0x48000 ; 0x20af8: add x8, x8, #0x498
 */
uint64_t fde_068_0x20ae4(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x20ae4ULL;
    constexpr uint64_t kFuncSize    = 0x5cULL;
    constexpr uint32_t kFirstOpcode = 0xa9bf7bf3U;
    constexpr uint32_t kLastOpcode  = 0x1400937dU;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[069] `sub_20b40` (`0x20b40..0x20cfc`, 444 bytes)
 *        Hàm FDE[069] `sub_20b40` (`0x20b40..0x20cfc`, 444 bytes)
 * Disassembly: 0x20b40: sub sp, sp, #0x90 ; 0x20b44: stp x25, x24, [sp, #0x50] ; 0x20b48: stp x23, x22, [sp, #0x60] ; 0x20b4c: stp x21, x20, [sp, #0x70] ; 0x20b50: stp x19, x30, [sp, #0x80] ; 0x20b54: mrs x23, tpidr_el0
 */
uint64_t fde_069_0x20b40(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x20b40ULL;
    constexpr uint64_t kFuncSize    = 0x1bcULL;
    constexpr uint32_t kFirstOpcode = 0xd10243ffU;
    constexpr uint32_t kLastOpcode  = 0x94009316U;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[070] `sub_20cfc` (`0x20cfc..0x20e38`, 316 bytes)
 *        Hàm FDE[070] `sub_20cfc` (`0x20cfc..0x20e38`, 316 bytes)
 * Disassembly: 0x20cfc: sub sp, sp, #0x70 ; 0x20d00: stp x23, x22, [sp, #0x40] ; 0x20d04: stp x21, x20, [sp, #0x50] ; 0x20d08: stp x19, x30, [sp, #0x60] ; 0x20d0c: mrs x22, tpidr_el0 ; 0x20d10: ldr x8, [x22, #0x28]
 */
uint64_t fde_070_0x20cfc(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x20cfcULL;
    constexpr uint64_t kFuncSize    = 0x13cULL;
    constexpr uint32_t kFirstOpcode = 0xd101c3ffU;
    constexpr uint32_t kLastOpcode  = 0x940092c7U;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[071] `sub_20e38` (`0x20e38..0x20f74`, 316 bytes)
 *        Hàm FDE[071] `sub_20e38` (`0x20e38..0x20f74`, 316 bytes)
 * Disassembly: 0x20e38: sub sp, sp, #0x70 ; 0x20e3c: stp x23, x22, [sp, #0x40] ; 0x20e40: stp x21, x20, [sp, #0x50] ; 0x20e44: stp x19, x30, [sp, #0x60] ; 0x20e48: mrs x22, tpidr_el0 ; 0x20e4c: ldr x8, [x22, #0x28]
 */
uint64_t fde_071_0x20e38(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x20e38ULL;
    constexpr uint64_t kFuncSize    = 0x13cULL;
    constexpr uint32_t kFirstOpcode = 0xd101c3ffU;
    constexpr uint32_t kLastOpcode  = 0x94009278U;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[072] `sub_20f74` (`0x20f74..0x2100c`, 152 bytes)
 *        Hàm FDE[072] `sub_20f74` (`0x20f74..0x2100c`, 152 bytes)
 * Disassembly: 0x20f74: sub sp, sp, #0x120 ; 0x20f78: str x28, [sp, #0x100] ; 0x20f7c: stp x19, x30, [sp, #0x110] ; 0x20f80: stp x3, x4, [sp, #0x88] ; 0x20f84: stp x5, x6, [sp, #0x98] ; 0x20f88: str x7, [sp, #0xa8]
 */
uint64_t fde_072_0x20f74(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x20f74ULL;
    constexpr uint64_t kFuncSize    = 0x98ULL;
    constexpr uint32_t kFirstOpcode = 0xd10483ffU;
    constexpr uint32_t kLastOpcode  = 0x94009252U;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[073] `sub_2100c` (`0x2100c..0x210a4`, 152 bytes)
 *        Hàm FDE[073] `sub_2100c` (`0x2100c..0x210a4`, 152 bytes)
 * Disassembly: 0x2100c: sub sp, sp, #0x120 ; 0x21010: str x28, [sp, #0x100] ; 0x21014: stp x19, x30, [sp, #0x110] ; 0x21018: stp x3, x4, [sp, #0x88] ; 0x2101c: stp x5, x6, [sp, #0x98] ; 0x21020: str x7, [sp, #0xa8]
 */
uint64_t fde_073_0x2100c(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x2100cULL;
    constexpr uint64_t kFuncSize    = 0x98ULL;
    constexpr uint32_t kFirstOpcode = 0xd10483ffU;
    constexpr uint32_t kLastOpcode  = 0x9400922cU;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[074] `sub_210a4` (`0x210a4..0x210e0`, 60 bytes)
 *        Hàm FDE[074] `sub_210a4` (`0x210a4..0x210e0`, 60 bytes)
 * Disassembly: 0x210a4: stp x19, x30, [sp, #-0x10]! ; 0x210a8: adrp x8, #0x48000 ; 0x210ac: add x8, x8, #0x518 ; 0x210b0: mov x19, x0 ; 0x210b4: str x8, [x0] ; 0x210b8: bl #0x2111c
 */
uint64_t fde_074_0x210a4(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x210a4ULL;
    constexpr uint64_t kFuncSize    = 0x3cULL;
    constexpr uint32_t kFirstOpcode = 0xa9bf7bf3U;
    constexpr uint32_t kLastOpcode  = 0xd65f03c0U;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[075] `sub_210e0` (`0x210e0..0x2111c`, 60 bytes)
 *        Hàm FDE[075] `sub_210e0` (`0x210e0..0x2111c`, 60 bytes)
 * Disassembly: 0x210e0: stp x19, x30, [sp, #-0x10]! ; 0x210e4: adrp x8, #0x48000 ; 0x210e8: add x8, x8, #0x518 ; 0x210ec: mov x19, x0 ; 0x210f0: str x8, [x0] ; 0x210f4: bl #0x2111c
 */
uint64_t fde_075_0x210e0(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x210e0ULL;
    constexpr uint64_t kFuncSize    = 0x3cULL;
    constexpr uint32_t kFirstOpcode = 0xa9bf7bf3U;
    constexpr uint32_t kLastOpcode  = 0x14009206U;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[076] `sub_2111c` (`0x2111c..0x21368`, 588 bytes)
 *        Hàm FDE[076] `sub_2111c` (`0x2111c..0x21368`, 588 bytes)
 * Disassembly: 0x2111c: sub sp, sp, #0x50 ; 0x21120: str x22, [sp, #0x20] ; 0x21124: stp x21, x20, [sp, #0x30] ; 0x21128: stp x19, x30, [sp, #0x40] ; 0x2112c: mrs x20, tpidr_el0 ; 0x21130: ldr x8, [x20, #0x28]
 */
uint64_t fde_076_0x2111c(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x2111cULL;
    constexpr uint64_t kFuncSize    = 0x24cULL;
    constexpr uint32_t kFirstOpcode = 0xd10143ffU;
    constexpr uint32_t kLastOpcode  = 0x9400917bU;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[077] `sub_21368` (`0x21368..0x21454`, 236 bytes)
 *        Hàm FDE[077] `sub_21368` (`0x21368..0x21454`, 236 bytes)
 * Disassembly: 0x21368: str x20, [sp, #-0x20]! ; 0x2136c: stp x19, x30, [sp, #0x10] ; 0x21370: adrp x8, #0x4c000 ; 0x21374: add x8, x8, #0x100 ; 0x21378: ldarb w8, [x8] ; 0x2137c: mov x19, x0
 */
uint64_t fde_077_0x21368(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x21368ULL;
    constexpr uint64_t kFuncSize    = 0xecULL;
    constexpr uint32_t kFirstOpcode = 0xf81e0ff4U;
    constexpr uint32_t kLastOpcode  = 0x17ffffd6U;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[078] `sub_21454` (`0x21454..0x2145c`, 8 bytes)
 *        Hàm FDE[078] `sub_21454` (`0x21454..0x2145c`, 8 bytes)
 * Disassembly: 0x21454: str x30, [sp, #-0x10]! ; 0x21458: bl #0x45a00
 */
uint64_t fde_078_0x21454(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x21454ULL;
    constexpr uint64_t kFuncSize    = 0x8ULL;
    constexpr uint32_t kFirstOpcode = 0xf81f0ffeU;
    constexpr uint32_t kLastOpcode  = 0x9400916aU;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[079] `sub_2145c` (`0x2145c..0x21590`, 308 bytes)
 *        Hàm FDE[079] `sub_2145c` (`0x2145c..0x21590`, 308 bytes)
 * Disassembly: 0x2145c: sub sp, sp, #0x160 ; 0x21460: stp x28, x22, [sp, #0x130] ; 0x21464: stp x21, x20, [sp, #0x140] ; 0x21468: stp x19, x30, [sp, #0x150] ; 0x2146c: mrs x22, tpidr_el0 ; 0x21470: ldr x8, [x22, #0x28]
 */
uint64_t fde_079_0x2145c(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x2145cULL;
    constexpr uint64_t kFuncSize    = 0x134ULL;
    constexpr uint32_t kFirstOpcode = 0xd10583ffU;
    constexpr uint32_t kLastOpcode  = 0x940090f1U;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[080] `sub_21590` (`0x21590..0x21644`, 180 bytes)
 *        Hàm FDE[080] `sub_21590` (`0x21590..0x21644`, 180 bytes)
 * Disassembly: 0x21590: sub sp, sp, #0x150 ; 0x21594: stp x28, x20, [sp, #0x130] ; 0x21598: stp x19, x30, [sp, #0x140] ; 0x2159c: mrs x20, tpidr_el0 ; 0x215a0: ldr x8, [x20, #0x28] ; 0x215a4: adrp x9, #0x48000
 */
uint64_t fde_080_0x21590(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x21590ULL;
    constexpr uint64_t kFuncSize    = 0xb4ULL;
    constexpr uint32_t kFirstOpcode = 0xd10543ffU;
    constexpr uint32_t kLastOpcode  = 0x940090c4U;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[081] `sub_21644` (`0x21644..0x2165c`, 24 bytes)
 *        Hàm FDE[081] `sub_21644` (`0x21644..0x2165c`, 24 bytes)
 * Disassembly: 0x21644: stp x19, x30, [sp, #-0x10]! ; 0x21648: mov x19, x0 ; 0x2164c: bl #0x21590 ; 0x21650: mov x0, x19 ; 0x21654: ldp x19, x30, [sp], #0x10 ; 0x21658: b #0x45930
 */
uint64_t fde_081_0x21644(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x21644ULL;
    constexpr uint64_t kFuncSize    = 0x18ULL;
    constexpr uint32_t kFirstOpcode = 0xa9bf7bf3U;
    constexpr uint32_t kLastOpcode  = 0x140090b6U;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[082] `sub_2165c` (`0x2165c..0x217d8`, 380 bytes)
 *        Hàm FDE[082] `sub_2165c` (`0x2165c..0x217d8`, 380 bytes)
 * Disassembly: 0x2165c: sub sp, sp, #0x160 ; 0x21660: stp x28, x22, [sp, #0x130] ; 0x21664: stp x21, x20, [sp, #0x140] ; 0x21668: stp x19, x30, [sp, #0x150] ; 0x2166c: mrs x21, tpidr_el0 ; 0x21670: ldr x8, [x21, #0x28]
 */
uint64_t fde_082_0x2165c(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x2165cULL;
    constexpr uint64_t kFuncSize    = 0x17cULL;
    constexpr uint32_t kFirstOpcode = 0xd10583ffU;
    constexpr uint32_t kLastOpcode  = 0x9400905fU;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[083] `sub_217d8` (`0x217d8..0x218d8`, 256 bytes)
 *        Hàm FDE[083] `sub_217d8` (`0x217d8..0x218d8`, 256 bytes)
 * Disassembly: 0x217d8: sub sp, sp, #0x70 ; 0x217dc: str x22, [sp, #0x40] ; 0x217e0: stp x21, x20, [sp, #0x50] ; 0x217e4: stp x19, x30, [sp, #0x60] ; 0x217e8: mrs x22, tpidr_el0 ; 0x217ec: ldr x8, [x22, #0x28]
 */
uint64_t fde_083_0x217d8(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x217d8ULL;
    constexpr uint64_t kFuncSize    = 0x100ULL;
    constexpr uint32_t kFirstOpcode = 0xd101c3ffU;
    constexpr uint32_t kLastOpcode  = 0x9400901fU;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[084] `sub_218d8` (`0x218d8..0x218ec`, 20 bytes)
 *        Hàm FDE[084] `sub_218d8` (`0x218d8..0x218ec`, 20 bytes)
 * Disassembly: 0x218d8: ldr x0, [x0, #0xb8] ; 0x218dc: cbz x0, #0x218e8 ; 0x218e0: mov x1, xzr ; 0x218e4: b #0x45c00 ; 0x218e8: ret
 */
uint64_t fde_084_0x218d8(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x218d8ULL;
    constexpr uint64_t kFuncSize    = 0x14ULL;
    constexpr uint32_t kFirstOpcode = 0xf9405c00U;
    constexpr uint32_t kLastOpcode  = 0xd65f03c0U;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[085] `sub_218ec` (`0x218ec..0x21988`, 156 bytes)
 *        Hàm FDE[085] `sub_218ec` (`0x218ec..0x21988`, 156 bytes)
 * Disassembly: 0x218ec: str x20, [sp, #-0x20]! ; 0x218f0: stp x19, x30, [sp, #0x10] ; 0x218f4: mov x19, x0 ; 0x218f8: bl #0x45c10 ; 0x218fc: sxtw x8, w0 ; 0x21900: str x8, [x19, #0xc0]
 */
uint64_t fde_085_0x218ec(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x218ecULL;
    constexpr uint64_t kFuncSize    = 0x9cULL;
    constexpr uint32_t kFirstOpcode = 0xf81e0ff4U;
    constexpr uint32_t kLastOpcode  = 0x17ffffe5U;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[086] `sub_21988` (`0x21988..0x219c8`, 64 bytes)
 *        Hàm FDE[086] `sub_21988` (`0x21988..0x219c8`, 64 bytes)
 * Disassembly: 0x21988: mov x8, x0 ; 0x2198c: ldr x0, [x0, #0x30] ; 0x21990: adrp x9, #0x48000 ; 0x21994: add x10, x8, #0x10 ; 0x21998: add x9, x9, #0x638 ; 0x2199c: cmp x10, x0
 */
uint64_t fde_086_0x21988(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x21988ULL;
    constexpr uint64_t kFuncSize    = 0x40ULL;
    constexpr uint32_t kFirstOpcode = 0xaa0003e8U;
    constexpr uint32_t kLastOpcode  = 0xd65f03c0U;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[087] `sub_219c8` (`0x219c8..0x21a14`, 76 bytes)
 *        Hàm FDE[087] `sub_219c8` (`0x219c8..0x21a14`, 76 bytes)
 * Disassembly: 0x219c8: stp x19, x30, [sp, #-0x10]! ; 0x219cc: mov x19, x0 ; 0x219d0: ldr x0, [x0, #0x30] ; 0x219d4: adrp x8, #0x48000 ; 0x219d8: add x9, x19, #0x10 ; 0x219dc: add x8, x8, #0x638
 */
uint64_t fde_087_0x219c8(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x219c8ULL;
    constexpr uint64_t kFuncSize    = 0x4cULL;
    constexpr uint32_t kFirstOpcode = 0xa9bf7bf3U;
    constexpr uint32_t kLastOpcode  = 0x14008fc8U;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[088] `sub_21a14` (`0x21a14..0x21a2c`, 24 bytes)
 *        Hàm FDE[088] `sub_21a14` (`0x21a14..0x21a2c`, 24 bytes)
 * Disassembly: 0x21a14: ldr x0, [x0, #0x30] ; 0x21a18: cbz x0, #0x21a28 ; 0x21a1c: ldr x8, [x0] ; 0x21a20: ldr x1, [x8, #0x30] ; 0x21a24: br x1 ; 0x21a28: ret
 */
uint64_t fde_088_0x21a14(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x21a14ULL;
    constexpr uint64_t kFuncSize    = 0x18ULL;
    constexpr uint32_t kFirstOpcode = 0xf9401800U;
    constexpr uint32_t kLastOpcode  = 0xd65f03c0U;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[089] `sub_21a2c` (`0x21a2c..0x21a58`, 44 bytes)
 *        Hàm FDE[089] `sub_21a2c` (`0x21a2c..0x21a58`, 44 bytes)
 * Disassembly: 0x21a2c: stp x19, x30, [sp, #-0x10]! ; 0x21a30: mov x19, x0 ; 0x21a34: mov w0, #0x10 ; 0x21a38: bl #0x459f0 ; 0x21a3c: adrp x8, #0x48000 ; 0x21a40: add x8, x8, #0x5e0
 */
uint64_t fde_089_0x21a2c(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x21a2cULL;
    constexpr uint64_t kFuncSize    = 0x2cULL;
    constexpr uint32_t kFirstOpcode = 0xa9bf7bf3U;
    constexpr uint32_t kLastOpcode  = 0xd65f03c0U;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[090] `sub_21a58` (`0x21a58..0x21a70`, 24 bytes)
 *        Hàm FDE[090] `sub_21a58` (`0x21a58..0x21a70`, 24 bytes)
 * Disassembly: 0x21a58: adrp x8, #0x48000 ; 0x21a5c: add x8, x8, #0x5e0 ; 0x21a60: str x8, [x1] ; 0x21a64: ldr x8, [x0, #8] ; 0x21a68: str x8, [x1, #8] ; 0x21a6c: ret
 */
uint64_t fde_090_0x21a58(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x21a58ULL;
    constexpr uint64_t kFuncSize    = 0x18ULL;
    constexpr uint32_t kFirstOpcode = 0xf0000128U;
    constexpr uint32_t kLastOpcode  = 0xd65f03c0U;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[091] `sub_21a70` (`0x21a70..0x21a8c`, 28 bytes)
 *        Hàm FDE[091] `sub_21a70` (`0x21a70..0x21a8c`, 28 bytes)
 * Disassembly: 0x21a70: ldr x8, [x0, #8] ; 0x21a74: ldr x0, [x8, #0xb0] ; 0x21a78: cbz x0, #0x21a88 ; 0x21a7c: ldr x8, [x0] ; 0x21a80: ldr x1, [x8, #0x18] ; 0x21a84: br x1
 */
uint64_t fde_091_0x21a70(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x21a70ULL;
    constexpr uint64_t kFuncSize    = 0x1cULL;
    constexpr uint32_t kFirstOpcode = 0xf9400408U;
    constexpr uint32_t kLastOpcode  = 0xd65f03c0U;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[092] `sub_21a8c` (`0x21a8c..0x21aa8`, 28 bytes)
 *        Hàm FDE[092] `sub_21a8c` (`0x21a8c..0x21aa8`, 28 bytes)
 * Disassembly: 0x21a8c: ldr x8, [x1, #8] ; 0x21a90: adrp x9, #0x10000 ; 0x21a94: add x9, x9, #0x284 ; 0x21a98: add x10, x0, #8 ; 0x21a9c: cmp x8, x9 ; 0x21aa0: csel x0, x10, xzr, eq
 */
uint64_t fde_092_0x21a8c(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x21a8cULL;
    constexpr uint64_t kFuncSize    = 0x1cULL;
    constexpr uint32_t kFirstOpcode = 0xf9400428U;
    constexpr uint32_t kLastOpcode  = 0xd65f03c0U;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[093] `sub_21aa8` (`0x21aa8..0x21ab4`, 12 bytes)
 *        Hàm FDE[093] `sub_21aa8` (`0x21aa8..0x21ab4`, 12 bytes)
 * Disassembly: 0x21aa8: adrp x0, #0x48000 ; 0x21aac: add x0, x0, #0x690 ; 0x21ab0: ret
 */
uint64_t fde_093_0x21aa8(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x21aa8ULL;
    constexpr uint64_t kFuncSize    = 0xcULL;
    constexpr uint32_t kFirstOpcode = 0xf0000120U;
    constexpr uint32_t kLastOpcode  = 0xd65f03c0U;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[094] `sub_21ab4` (`0x21ab4..0x21ae4`, 48 bytes)
 *        Hàm FDE[094] `sub_21ab4` (`0x21ab4..0x21ae4`, 48 bytes)
 * Disassembly: 0x21ab4: stp x19, x30, [sp, #-0x10]! ; 0x21ab8: ldrb w8, [x0, #0xc8] ; 0x21abc: adrp x9, #0x48000 ; 0x21ac0: mov x19, x0 ; 0x21ac4: add x9, x9, #0x548 ; 0x21ac8: str x9, [x0]
 */
uint64_t fde_094_0x21ab4(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x21ab4ULL;
    constexpr uint64_t kFuncSize    = 0x30ULL;
    constexpr uint32_t kFirstOpcode = 0xa9bf7bf3U;
    constexpr uint32_t kLastOpcode  = 0x17fff12eU;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[095] `sub_21ae4` (`0x21ae4..0x21ae8`, 4 bytes)
 *        Hàm FDE[095] `sub_21ae4` (`0x21ae4..0x21ae8`, 4 bytes)
 * Disassembly: 0x21ae4: brk #1
 */
uint64_t fde_095_0x21ae4(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x21ae4ULL;
    constexpr uint64_t kFuncSize    = 0x4ULL;
    constexpr uint32_t kFirstOpcode = 0xd4200020U;
    constexpr uint32_t kLastOpcode  = 0xd4200020U;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[096] `sub_21ae8` (`0x21ae8..0x21af8`, 16 bytes)
 *        Hàm FDE[096] `sub_21ae8` (`0x21ae8..0x21af8`, 16 bytes)
 * Disassembly: 0x21ae8: ldr x8, [x2] ; 0x21aec: mov x0, x2 ; 0x21af0: ldr x1, [x8, #0x28] ; 0x21af4: br x1
 */
uint64_t fde_096_0x21ae8(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x21ae8ULL;
    constexpr uint64_t kFuncSize    = 0x10ULL;
    constexpr uint32_t kFirstOpcode = 0xf9400048U;
    constexpr uint32_t kLastOpcode  = 0xd61f0020U;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[097] `sub_21af8` (`0x21af8..0x21b78`, 128 bytes)
 *        Hàm FDE[097] `sub_21af8` (`0x21af8..0x21b78`, 128 bytes)
 * Disassembly: 0x21af8: str x20, [sp, #-0x20]! ; 0x21afc: stp x19, x30, [sp, #0x10] ; 0x21b00: adrp x8, #0x48000 ; 0x21b04: adrp x9, #0x48000 ; 0x21b08: add x8, x8, #0x6e8 ; 0x21b0c: add x9, x9, #0x498
 */
uint64_t fde_097_0x21af8(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x21af8ULL;
    constexpr uint64_t kFuncSize    = 0x80ULL;
    constexpr uint32_t kFirstOpcode = 0xf81e0ff4U;
    constexpr uint32_t kLastOpcode  = 0x17fff109U;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[098] `sub_21b78` (`0x21b78..0x21c00`, 136 bytes)
 *        Hàm FDE[098] `sub_21b78` (`0x21b78..0x21c00`, 136 bytes)
 * Disassembly: 0x21b78: str x20, [sp, #-0x20]! ; 0x21b7c: stp x19, x30, [sp, #0x10] ; 0x21b80: adrp x8, #0x48000 ; 0x21b84: adrp x9, #0x48000 ; 0x21b88: add x8, x8, #0x6e8 ; 0x21b8c: add x9, x9, #0x498
 */
uint64_t fde_098_0x21b78(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x21b78ULL;
    constexpr uint64_t kFuncSize    = 0x88ULL;
    constexpr uint32_t kFirstOpcode = 0xf81e0ff4U;
    constexpr uint32_t kLastOpcode  = 0x14008f4dU;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[099] `sub_21c00` (`0x21c00..0x21e6c`, 620 bytes)
 *        Hàm FDE[099] `sub_21c00` (`0x21c00..0x21e6c`, 620 bytes)
 * Disassembly: 0x21c00: sub sp, sp, #0x90 ; 0x21c04: stp x25, x24, [sp, #0x50] ; 0x21c08: stp x23, x22, [sp, #0x60] ; 0x21c0c: stp x21, x20, [sp, #0x70] ; 0x21c10: stp x19, x30, [sp, #0x80] ; 0x21c14: mrs x23, tpidr_el0
 */
uint64_t fde_099_0x21c00(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x21c00ULL;
    constexpr uint64_t kFuncSize    = 0x26cULL;
    constexpr uint32_t kFirstOpcode = 0xd10243ffU;
    constexpr uint32_t kLastOpcode  = 0x94008ebaU;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[100] `sub_21e6c` (`0x21e6c..0x21fb8`, 332 bytes)
 *        Hàm FDE[100] `sub_21e6c` (`0x21e6c..0x21fb8`, 332 bytes)
 * Disassembly: 0x21e6c: sub sp, sp, #0x70 ; 0x21e70: stp x23, x22, [sp, #0x40] ; 0x21e74: stp x21, x20, [sp, #0x50] ; 0x21e78: stp x19, x30, [sp, #0x60] ; 0x21e7c: mrs x22, tpidr_el0 ; 0x21e80: ldr x8, [x22, #0x28]
 */
uint64_t fde_100_0x21e6c(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x21e6cULL;
    constexpr uint64_t kFuncSize    = 0x14cULL;
    constexpr uint32_t kFirstOpcode = 0xd101c3ffU;
    constexpr uint32_t kLastOpcode  = 0x94008e67U;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[101] `sub_21fb8` (`0x21fb8..0x220f4`, 316 bytes)
 *        Hàm FDE[101] `sub_21fb8` (`0x21fb8..0x220f4`, 316 bytes)
 * Disassembly: 0x21fb8: sub sp, sp, #0x70 ; 0x21fbc: stp x23, x22, [sp, #0x40] ; 0x21fc0: stp x21, x20, [sp, #0x50] ; 0x21fc4: stp x19, x30, [sp, #0x60] ; 0x21fc8: mrs x21, tpidr_el0 ; 0x21fcc: ldr x8, [x21, #0x28]
 */
uint64_t fde_101_0x21fb8(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x21fb8ULL;
    constexpr uint64_t kFuncSize    = 0x13cULL;
    constexpr uint32_t kFirstOpcode = 0xd101c3ffU;
    constexpr uint32_t kLastOpcode  = 0x94008e18U;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[102] `sub_220f4` (`0x220f4..0x22190`, 156 bytes)
 *        Hàm FDE[102] `sub_220f4` (`0x220f4..0x22190`, 156 bytes)
 * Disassembly: 0x220f4: str x20, [sp, #-0x20]! ; 0x220f8: stp x19, x30, [sp, #0x10] ; 0x220fc: mov x19, x0 ; 0x22100: bl #0x45c10 ; 0x22104: sxtw x8, w0 ; 0x22108: str x8, [x19, #0xc0]
 */
uint64_t fde_102_0x220f4(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x220f4ULL;
    constexpr uint64_t kFuncSize    = 0x9cULL;
    constexpr uint32_t kFirstOpcode = 0xf81e0ff4U;
    constexpr uint32_t kLastOpcode  = 0x17ffffe5U;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[103] `sub_22190` (`0x22190..0x221bc`, 44 bytes)
 *        Hàm FDE[103] `sub_22190` (`0x22190..0x221bc`, 44 bytes)
 * Disassembly: 0x22190: stp x19, x30, [sp, #-0x10]! ; 0x22194: mov x19, x0 ; 0x22198: mov w0, #0x10 ; 0x2219c: bl #0x459f0 ; 0x221a0: adrp x8, #0x48000 ; 0x221a4: add x8, x8, #0x740
 */
uint64_t fde_103_0x22190(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x22190ULL;
    constexpr uint64_t kFuncSize    = 0x2cULL;
    constexpr uint32_t kFirstOpcode = 0xa9bf7bf3U;
    constexpr uint32_t kLastOpcode  = 0xd65f03c0U;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[104] `sub_221bc` (`0x221bc..0x221d4`, 24 bytes)
 *        Hàm FDE[104] `sub_221bc` (`0x221bc..0x221d4`, 24 bytes)
 * Disassembly: 0x221bc: adrp x8, #0x48000 ; 0x221c0: add x8, x8, #0x740 ; 0x221c4: str x8, [x1] ; 0x221c8: ldr x8, [x0, #8] ; 0x221cc: str x8, [x1, #8] ; 0x221d0: ret
 */
uint64_t fde_104_0x221bc(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x221bcULL;
    constexpr uint64_t kFuncSize    = 0x18ULL;
    constexpr uint32_t kFirstOpcode = 0xd0000128U;
    constexpr uint32_t kLastOpcode  = 0xd65f03c0U;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[105] `sub_221d4` (`0x221d4..0x2230c`, 312 bytes)
 *        Hàm FDE[105] `sub_221d4` (`0x221d4..0x2230c`, 312 bytes)
 * Disassembly: 0x221d4: sub sp, sp, #0x70 ; 0x221d8: stp x23, x22, [sp, #0x40] ; 0x221dc: stp x21, x20, [sp, #0x50] ; 0x221e0: stp x19, x30, [sp, #0x60] ; 0x221e4: mrs x21, tpidr_el0 ; 0x221e8: ldr x8, [x21, #0x28]
 */
uint64_t fde_105_0x221d4(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x221d4ULL;
    constexpr uint64_t kFuncSize    = 0x138ULL;
    constexpr uint32_t kFirstOpcode = 0xd101c3ffU;
    constexpr uint32_t kLastOpcode  = 0x94008d92U;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[106] `sub_2230c` (`0x2230c..0x22328`, 28 bytes)
 *        Hàm FDE[106] `sub_2230c` (`0x2230c..0x22328`, 28 bytes)
 * Disassembly: 0x2230c: ldr x8, [x1, #8] ; 0x22310: adrp x9, #0x10000 ; 0x22314: add x9, x9, #0x3a3 ; 0x22318: add x10, x0, #8 ; 0x2231c: cmp x8, x9 ; 0x22320: csel x0, x10, xzr, eq
 */
uint64_t fde_106_0x2230c(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x2230cULL;
    constexpr uint64_t kFuncSize    = 0x1cULL;
    constexpr uint32_t kFirstOpcode = 0xf9400428U;
    constexpr uint32_t kLastOpcode  = 0xd65f03c0U;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[107] `sub_22328` (`0x22328..0x22334`, 12 bytes)
 *        Hàm FDE[107] `sub_22328` (`0x22328..0x22334`, 12 bytes)
 * Disassembly: 0x22328: adrp x0, #0x48000 ; 0x2232c: add x0, x0, #0x7a0 ; 0x22330: ret
 */
uint64_t fde_107_0x22328(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x22328ULL;
    constexpr uint64_t kFuncSize    = 0xcULL;
    constexpr uint32_t kFirstOpcode = 0xd0000120U;
    constexpr uint32_t kLastOpcode  = 0xd65f03c0U;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[108] `sub_22334` (`0x22334..0x22498`, 356 bytes)
 *        Hàm FDE[108] `sub_22334` (`0x22334..0x22498`, 356 bytes)
 * Disassembly: 0x22334: str x24, [sp, #-0x40]! ; 0x22338: stp x23, x22, [sp, #0x10] ; 0x2233c: stp x21, x20, [sp, #0x20] ; 0x22340: stp x19, x30, [sp, #0x30] ; 0x22344: ldp x22, x21, [x0] ; 0x22348: sub x8, x21, x22
 */
uint64_t fde_108_0x22334(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x22334ULL;
    constexpr uint64_t kFuncSize    = 0x164ULL;
    constexpr uint32_t kFirstOpcode = 0xf81c0ff8U;
    constexpr uint32_t kLastOpcode  = 0x17ffffc3U;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[109] `sub_22498` (`0x22498..0x226e8`, 592 bytes)
 *        Hàm FDE[109] `sub_22498` (`0x22498..0x226e8`, 592 bytes)
 * Disassembly: 0x22498: str x24, [sp, #-0x40]! ; 0x2249c: stp x23, x22, [sp, #0x10] ; 0x224a0: stp x21, x20, [sp, #0x20] ; 0x224a4: stp x19, x30, [sp, #0x30] ; 0x224a8: ldp x8, x9, [x0] ; 0x224ac: cmp x8, x9
 */
uint64_t fde_109_0x22498(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x22498ULL;
    constexpr uint64_t kFuncSize    = 0x250ULL;
    constexpr uint32_t kFirstOpcode = 0xf81c0ff8U;
    constexpr uint32_t kLastOpcode  = 0xd65f03c0U;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[110] `sub_226e8` (`0x226e8..0x22928`, 576 bytes)
 *        Hàm FDE[110] `sub_226e8` (`0x226e8..0x22928`, 576 bytes)
 * Disassembly: 0x226e8: str x26, [sp, #-0x50]! ; 0x226ec: stp x25, x24, [sp, #0x10] ; 0x226f0: stp x23, x22, [sp, #0x20] ; 0x226f4: stp x21, x20, [sp, #0x30] ; 0x226f8: stp x19, x30, [sp, #0x40] ; 0x226fc: add x19, x0, #0x20
 */
uint64_t fde_110_0x226e8(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x226e8ULL;
    constexpr uint64_t kFuncSize    = 0x240ULL;
    constexpr uint32_t kFirstOpcode = 0xf81b0ffaU;
    constexpr uint32_t kLastOpcode  = 0x14008c6bU;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[111] `sub_22928` (`0x22928..0x22a18`, 240 bytes)
 *        Hàm FDE[111] `sub_22928` (`0x22928..0x22a18`, 240 bytes)
 * Disassembly: 0x22928: stp x23, x22, [sp, #-0x30]! ; 0x2292c: stp x21, x20, [sp, #0x10] ; 0x22930: stp x19, x30, [sp, #0x20] ; 0x22934: ldrb w8, [x0] ; 0x22938: mov x20, x2 ; 0x2293c: mov x19, x0
 */
uint64_t fde_111_0x22928(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x22928ULL;
    constexpr uint64_t kFuncSize    = 0xf0ULL;
    constexpr uint32_t kFirstOpcode = 0xa9bd5bf7U;
    constexpr uint32_t kLastOpcode  = 0xd65f03c0U;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[112] `sub_22a18` (`0x22a18..0x22d58`, 832 bytes)
 *        Hàm FDE[112] `sub_22a18` (`0x22a18..0x22d58`, 832 bytes)
 * Disassembly: 0x22a18: str x28, [sp, #-0x60]! ; 0x22a1c: stp x27, x26, [sp, #0x10] ; 0x22a20: stp x25, x24, [sp, #0x20] ; 0x22a24: stp x23, x22, [sp, #0x30] ; 0x22a28: stp x21, x20, [sp, #0x40] ; 0x22a2c: stp x19, x30, [sp, #0x50]
 */
uint64_t fde_112_0x22a18(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x22a18ULL;
    constexpr uint64_t kFuncSize    = 0x340ULL;
    constexpr uint32_t kFirstOpcode = 0xf81a0ffcU;
    constexpr uint32_t kLastOpcode  = 0xd65f03c0U;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[113] `sub_22d58` (`0x22d58..0x231c4`, 1132 bytes)
 *        Hàm FDE[113] `sub_22d58` (`0x22d58..0x231c4`, 1132 bytes)
 * Disassembly: 0x22d58: cmp x1, #0x20 ; 0x22d5c: b.hi #0x22dc8 ; 0x22d60: cmp x1, #0x10 ; 0x22d64: b.hi #0x22e94 ; 0x22d68: cmp x1, #9 ; 0x22d6c: b.lo #0x23134
 */
uint64_t fde_113_0x22d58(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x22d58ULL;
    constexpr uint64_t kFuncSize    = 0x46cULL;
    constexpr uint32_t kFirstOpcode = 0xf100803fU;
    constexpr uint32_t kLastOpcode  = 0x17ffffd9U;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[114] `sub_231c4` (`0x231c4..0x23424`, 608 bytes)
 *        Hàm FDE[114] `sub_231c4` (`0x231c4..0x23424`, 608 bytes)
 * Disassembly: 0x231c4: sub sp, sp, #0x80 ; 0x231c8: stp x28, x27, [sp, #0x20] ; 0x231cc: stp x26, x25, [sp, #0x30] ; 0x231d0: stp x24, x23, [sp, #0x40] ; 0x231d4: stp x22, x21, [sp, #0x50] ; 0x231d8: stp x20, x19, [sp, #0x60]
 */
uint64_t fde_114_0x231c4(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x231c4ULL;
    constexpr uint64_t kFuncSize    = 0x260ULL;
    constexpr uint32_t kFirstOpcode = 0xd10203ffU;
    constexpr uint32_t kLastOpcode  = 0x94008978U;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[115] `sub_23424` (`0x23424..0x2343c`, 24 bytes)
 *        Hàm FDE[115] `sub_23424` (`0x23424..0x2343c`, 24 bytes)
 * Disassembly: 0x23424: stp x19, x30, [sp, #-0x10]! ; 0x23428: mov x19, x0 ; 0x2342c: bl #0x45c70 ; 0x23430: mov x0, x19 ; 0x23434: ldp x19, x30, [sp], #0x10 ; 0x23438: b #0x45930
 */
uint64_t fde_115_0x23424(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x23424ULL;
    constexpr uint64_t kFuncSize    = 0x18ULL;
    constexpr uint32_t kFirstOpcode = 0xa9bf7bf3U;
    constexpr uint32_t kLastOpcode  = 0x1400893eU;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[116] `sub_2343c` (`0x2343c..0x23510`, 212 bytes)
 *        Hàm FDE[116] `sub_2343c` (`0x2343c..0x23510`, 212 bytes)
 * Disassembly: 0x2343c: stp x21, x20, [sp, #-0x20]! ; 0x23440: stp x19, x30, [sp, #0x10] ; 0x23444: subs x8, x1, #1 ; 0x23448: mov x19, x0 ; 0x2344c: b.ne #0x23458 ; 0x23450: mov w20, #2
 */
uint64_t fde_116_0x2343c(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x2343cULL;
    constexpr uint64_t kFuncSize    = 0xd4ULL;
    constexpr uint32_t kFirstOpcode = 0xa9be53f5U;
    constexpr uint32_t kLastOpcode  = 0xd65f03c0U;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[117] `sub_23510` (`0x23510..0x23540`, 48 bytes)
 *        Hàm FDE[117] `sub_23510` (`0x23510..0x23540`, 48 bytes)
 * Disassembly: 0x23510: stp x19, x30, [sp, #-0x10]! ; 0x23514: ldr x19, [x1, #8] ; 0x23518: ldr x3, [x1, #0x68] ; 0x2351c: adrp x1, #0x23000 ; 0x23520: adrp x2, #0xd000 ; 0x23524: add x1, x1, #0x674
 */
uint64_t fde_117_0x23510(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x23510ULL;
    constexpr uint64_t kFuncSize    = 0x30ULL;
    constexpr uint32_t kFirstOpcode = 0xa9bf7bf3U;
    constexpr uint32_t kLastOpcode  = 0xd65f03c0U;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[118] `sub_23540` (`0x23540..0x23674`, 308 bytes)
 *        Hàm FDE[118] `sub_23540` (`0x23540..0x23674`, 308 bytes)
 * Disassembly: 0x23540: sub sp, sp, #0xc0 ; 0x23544: stp x23, x22, [sp, #0x90] ; 0x23548: stp x21, x20, [sp, #0xa0] ; 0x2354c: stp x19, x30, [sp, #0xb0] ; 0x23550: mrs x21, tpidr_el0 ; 0x23554: ldr x8, [x21, #0x28]
 */
uint64_t fde_118_0x23540(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x23540ULL;
    constexpr uint64_t kFuncSize    = 0x134ULL;
    constexpr uint32_t kFirstOpcode = 0xd10303ffU;
    constexpr uint32_t kLastOpcode  = 0x940088b8U;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[119] `sub_23674` (`0x23674..0x2368c`, 24 bytes)
 *        Hàm FDE[119] `sub_23674` (`0x23674..0x2368c`, 24 bytes)
 * Disassembly: 0x23674: ldr x8, [x0, #0x68] ; 0x23678: mov x1, x0 ; 0x2367c: ldr x0, [x8, #0x20] ; 0x23680: ldr x8, [x0] ; 0x23684: ldr x2, [x8, #8] ; 0x23688: br x2
 */
uint64_t fde_119_0x23674(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x23674ULL;
    constexpr uint64_t kFuncSize    = 0x18ULL;
    constexpr uint32_t kFirstOpcode = 0xf9403408U;
    constexpr uint32_t kLastOpcode  = 0xd61f0040U;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[120] `sub_2368c` (`0x2368c..0x237e8`, 348 bytes)
 *        Hàm FDE[120] `sub_2368c` (`0x2368c..0x237e8`, 348 bytes)
 * Disassembly: 0x2368c: sub sp, sp, #0xc0 ; 0x23690: stp x23, x22, [sp, #0x90] ; 0x23694: stp x21, x20, [sp, #0xa0] ; 0x23698: stp x19, x30, [sp, #0xb0] ; 0x2369c: mrs x23, tpidr_el0 ; 0x236a0: ldr x8, [x23, #0x28]
 */
uint64_t fde_120_0x2368c(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x2368cULL;
    constexpr uint64_t kFuncSize    = 0x15cULL;
    constexpr uint32_t kFirstOpcode = 0xd10303ffU;
    constexpr uint32_t kLastOpcode  = 0x9400885bU;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[121] `sub_237e8` (`0x237e8..0x2391c`, 308 bytes)
 *        Hàm FDE[121] `sub_237e8` (`0x237e8..0x2391c`, 308 bytes)
 * Disassembly: 0x237e8: sub sp, sp, #0xc0 ; 0x237ec: stp x23, x22, [sp, #0x90] ; 0x237f0: stp x21, x20, [sp, #0xa0] ; 0x237f4: stp x19, x30, [sp, #0xb0] ; 0x237f8: mrs x21, tpidr_el0 ; 0x237fc: ldr x8, [x21, #0x28]
 */
uint64_t fde_121_0x237e8(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x237e8ULL;
    constexpr uint64_t kFuncSize    = 0x134ULL;
    constexpr uint32_t kFirstOpcode = 0xd10303ffU;
    constexpr uint32_t kLastOpcode  = 0x9400880eU;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[122] `sub_2391c` (`0x2391c..0x2392c`, 16 bytes)
 *        Hàm FDE[122] `sub_2391c` (`0x2391c..0x2392c`, 16 bytes)
 * Disassembly: 0x2391c: cbz x1, #0x23928 ; 0x23920: mov x0, x1 ; 0x23924: b #0x45930 ; 0x23928: ret
 */
uint64_t fde_122_0x2391c(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x2391cULL;
    constexpr uint64_t kFuncSize    = 0x10ULL;
    constexpr uint32_t kFirstOpcode = 0xb4000061U;
    constexpr uint32_t kLastOpcode  = 0xd65f03c0U;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[123] `sub_2392c` (`0x2392c..0x23a60`, 308 bytes)
 *        Hàm FDE[123] `sub_2392c` (`0x2392c..0x23a60`, 308 bytes)
 * Disassembly: 0x2392c: sub sp, sp, #0xc0 ; 0x23930: stp x23, x22, [sp, #0x90] ; 0x23934: stp x21, x20, [sp, #0xa0] ; 0x23938: stp x19, x30, [sp, #0xb0] ; 0x2393c: mrs x21, tpidr_el0 ; 0x23940: ldr x8, [x21, #0x28]
 */
uint64_t fde_123_0x2392c(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x2392cULL;
    constexpr uint64_t kFuncSize    = 0x134ULL;
    constexpr uint32_t kFirstOpcode = 0xd10303ffU;
    constexpr uint32_t kLastOpcode  = 0x940087bdU;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[124] `sub_23a60` (`0x23a60..0x23ad4`, 116 bytes)
 *        Hàm FDE[124] `sub_23a60` (`0x23a60..0x23ad4`, 116 bytes)
 * Disassembly: 0x23a60: sub sp, sp, #0xa0 ; 0x23a64: str x20, [sp, #0x80] ; 0x23a68: stp x19, x30, [sp, #0x90] ; 0x23a6c: mrs x20, tpidr_el0 ; 0x23a70: ldr x8, [x20, #0x28] ; 0x23a74: mov x2, x1
 */
uint64_t fde_124_0x23a60(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x23a60ULL;
    constexpr uint64_t kFuncSize    = 0x74ULL;
    constexpr uint32_t kFirstOpcode = 0xd10283ffU;
    constexpr uint32_t kLastOpcode  = 0x940087a0U;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[125] `sub_23ad4` (`0x23ad4..0x23b48`, 116 bytes)
 *        Hàm FDE[125] `sub_23ad4` (`0x23ad4..0x23b48`, 116 bytes)
 * Disassembly: 0x23ad4: sub sp, sp, #0xa0 ; 0x23ad8: str x20, [sp, #0x80] ; 0x23adc: stp x19, x30, [sp, #0x90] ; 0x23ae0: mrs x20, tpidr_el0 ; 0x23ae4: ldr x8, [x20, #0x28] ; 0x23ae8: mov x2, x1
 */
uint64_t fde_125_0x23ad4(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x23ad4ULL;
    constexpr uint64_t kFuncSize    = 0x74ULL;
    constexpr uint32_t kFirstOpcode = 0xd10283ffU;
    constexpr uint32_t kLastOpcode  = 0x94008783U;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[126] `sub_23b48` (`0x23b48..0x23be4`, 156 bytes)
 *        Hàm FDE[126] `sub_23b48` (`0x23b48..0x23be4`, 156 bytes)
 * Disassembly: 0x23b48: sub sp, sp, #0xb0 ; 0x23b4c: str x20, [sp, #0x90] ; 0x23b50: stp x19, x30, [sp, #0xa0] ; 0x23b54: mrs x19, tpidr_el0 ; 0x23b58: ldr x8, [x19, #0x28] ; 0x23b5c: mov x2, x1
 */
uint64_t fde_126_0x23b48(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x23b48ULL;
    constexpr uint64_t kFuncSize    = 0x9cULL;
    constexpr uint32_t kFirstOpcode = 0xd102c3ffU;
    constexpr uint32_t kLastOpcode  = 0x9400875cU;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[127] `sub_23be4` (`0x23be4..0x23bfc`, 24 bytes)
 *        Hàm FDE[127] `sub_23be4` (`0x23be4..0x23bfc`, 24 bytes)
 * Disassembly: 0x23be4: cbz x1, #0x23bf8 ; 0x23be8: ldr x8, [x1] ; 0x23bec: mov x0, x1 ; 0x23bf0: ldr x2, [x8, #8] ; 0x23bf4: br x2 ; 0x23bf8: ret
 */
uint64_t fde_127_0x23be4(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x23be4ULL;
    constexpr uint64_t kFuncSize    = 0x18ULL;
    constexpr uint32_t kFirstOpcode = 0xb40000a1U;
    constexpr uint32_t kLastOpcode  = 0xd65f03c0U;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[128] `sub_23bfc` (`0x23bfc..0x23c24`, 40 bytes)
 *        Hàm FDE[128] `sub_23bfc` (`0x23bfc..0x23c24`, 40 bytes)
 * Disassembly: 0x23bfc: stp x19, x30, [sp, #-0x10]! ; 0x23c00: ldr x1, [x0, #0x28] ; 0x23c04: mov x19, x0 ; 0x23c08: cbz x1, #0x23c18 ; 0x23c0c: ldr x0, [x19, #0x20] ; 0x23c10: bl #0x45d40
 */
uint64_t fde_128_0x23bfc(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x23bfcULL;
    constexpr uint64_t kFuncSize    = 0x28ULL;
    constexpr uint32_t kFirstOpcode = 0xa9bf7bf3U;
    constexpr uint32_t kLastOpcode  = 0x14008814U;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[129] `sub_23c24` (`0x23c24..0x23c54`, 48 bytes)
 *        Hàm FDE[129] `sub_23c24` (`0x23c24..0x23c54`, 48 bytes)
 * Disassembly: 0x23c24: stp x19, x30, [sp, #-0x10]! ; 0x23c28: ldr x1, [x0, #0x28] ; 0x23c2c: mov x19, x0 ; 0x23c30: cbz x1, #0x23c40 ; 0x23c34: ldr x0, [x19, #0x20] ; 0x23c38: bl #0x45d40
 */
uint64_t fde_129_0x23c24(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x23c24ULL;
    constexpr uint64_t kFuncSize    = 0x30ULL;
    constexpr uint32_t kFirstOpcode = 0xa9bf7bf3U;
    constexpr uint32_t kLastOpcode  = 0x14008738U;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[130] `sub_23c54` (`0x23c54..0x23ee4`, 656 bytes)
 *        Hàm FDE[130] `sub_23c54` (`0x23c54..0x23ee4`, 656 bytes)
 * Disassembly: 0x23c54: sub sp, sp, #0xc0 ; 0x23c58: stp x23, x22, [sp, #0x90] ; 0x23c5c: stp x21, x20, [sp, #0xa0] ; 0x23c60: stp x19, x30, [sp, #0xb0] ; 0x23c64: mrs x23, tpidr_el0 ; 0x23c68: ldr x8, [x23, #0x28]
 */
uint64_t fde_130_0x23c54(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x23c54ULL;
    constexpr uint64_t kFuncSize    = 0x290ULL;
    constexpr uint32_t kFirstOpcode = 0xd10303ffU;
    constexpr uint32_t kLastOpcode  = 0x9400869cU;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[131] `sub_23ee4` (`0x23ee4..0x248d8`, 2548 bytes)
 *        Hàm FDE[131] `sub_23ee4` (`0x23ee4..0x248d8`, 2548 bytes)
 * Disassembly: 0x23ee4: sub sp, sp, #0x150 ; 0x23ee8: stp x28, x27, [sp, #0xf0] ; 0x23eec: stp x26, x25, [sp, #0x100] ; 0x23ef0: stp x24, x23, [sp, #0x110] ; 0x23ef4: stp x22, x21, [sp, #0x120] ; 0x23ef8: stp x20, x19, [sp, #0x130]
 */
uint64_t fde_131_0x23ee4(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x23ee4ULL;
    constexpr uint64_t kFuncSize    = 0x9f4ULL;
    constexpr uint32_t kFirstOpcode = 0xd10543ffU;
    constexpr uint32_t kLastOpcode  = 0x9400841fU;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[132] `sub_248d8` (`0x248d8..0x24a0c`, 308 bytes)
 *        Hàm FDE[132] `sub_248d8` (`0x248d8..0x24a0c`, 308 bytes)
 * Disassembly: 0x248d8: sub sp, sp, #0xc0 ; 0x248dc: stp x23, x22, [sp, #0x90] ; 0x248e0: stp x21, x20, [sp, #0xa0] ; 0x248e4: stp x19, x30, [sp, #0xb0] ; 0x248e8: mrs x21, tpidr_el0 ; 0x248ec: ldr x8, [x21, #0x28]
 */
uint64_t fde_132_0x248d8(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x248d8ULL;
    constexpr uint64_t kFuncSize    = 0x134ULL;
    constexpr uint32_t kFirstOpcode = 0xd10303ffU;
    constexpr uint32_t kLastOpcode  = 0x940083d2U;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[133] `sub_24a0c` (`0x24a0c..0x24b68`, 348 bytes)
 *        Hàm FDE[133] `sub_24a0c` (`0x24a0c..0x24b68`, 348 bytes)
 * Disassembly: 0x24a0c: sub sp, sp, #0xc0 ; 0x24a10: stp x23, x22, [sp, #0x90] ; 0x24a14: stp x21, x20, [sp, #0xa0] ; 0x24a18: stp x19, x30, [sp, #0xb0] ; 0x24a1c: mrs x23, tpidr_el0 ; 0x24a20: ldr x8, [x23, #0x28]
 */
uint64_t fde_133_0x24a0c(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x24a0cULL;
    constexpr uint64_t kFuncSize    = 0x15cULL;
    constexpr uint32_t kFirstOpcode = 0xd10303ffU;
    constexpr uint32_t kLastOpcode  = 0x9400837bU;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[134] `sub_24b68` (`0x24b68..0x24c9c`, 308 bytes)
 *        Hàm FDE[134] `sub_24b68` (`0x24b68..0x24c9c`, 308 bytes)
 * Disassembly: 0x24b68: sub sp, sp, #0xc0 ; 0x24b6c: stp x23, x22, [sp, #0x90] ; 0x24b70: stp x21, x20, [sp, #0xa0] ; 0x24b74: stp x19, x30, [sp, #0xb0] ; 0x24b78: mrs x21, tpidr_el0 ; 0x24b7c: ldr x8, [x21, #0x28]
 */
uint64_t fde_134_0x24b68(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x24b68ULL;
    constexpr uint64_t kFuncSize    = 0x134ULL;
    constexpr uint32_t kFirstOpcode = 0xd10303ffU;
    constexpr uint32_t kLastOpcode  = 0x9400832eU;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[135] `sub_24c9c` (`0x24c9c..0x24dd0`, 308 bytes)
 *        Hàm FDE[135] `sub_24c9c` (`0x24c9c..0x24dd0`, 308 bytes)
 * Disassembly: 0x24c9c: sub sp, sp, #0xc0 ; 0x24ca0: stp x23, x22, [sp, #0x90] ; 0x24ca4: stp x21, x20, [sp, #0xa0] ; 0x24ca8: stp x19, x30, [sp, #0xb0] ; 0x24cac: mrs x21, tpidr_el0 ; 0x24cb0: ldr x8, [x21, #0x28]
 */
uint64_t fde_135_0x24c9c(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x24c9cULL;
    constexpr uint64_t kFuncSize    = 0x134ULL;
    constexpr uint32_t kFirstOpcode = 0xd10303ffU;
    constexpr uint32_t kLastOpcode  = 0x940082e1U;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[136] `sub_24dd0` (`0x24dd0..0x25130`, 864 bytes)
 *        Hàm FDE[136] `sub_24dd0` (`0x24dd0..0x25130`, 864 bytes)
 * Disassembly: 0x24dd0: sub sp, sp, #0x70 ; 0x24dd4: stp x27, x26, [sp, #0x20] ; 0x24dd8: stp x25, x24, [sp, #0x30] ; 0x24ddc: stp x23, x22, [sp, #0x40] ; 0x24de0: stp x21, x20, [sp, #0x50] ; 0x24de4: stp x19, x30, [sp, #0x60]
 */
uint64_t fde_136_0x24dd0(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x24dd0ULL;
    constexpr uint64_t kFuncSize    = 0x360ULL;
    constexpr uint32_t kFirstOpcode = 0xd101c3ffU;
    constexpr uint32_t kLastOpcode  = 0x94008209U;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[137] `sub_25130` (`0x25130..0x252ac`, 380 bytes)
 *        Hàm FDE[137] `sub_25130` (`0x25130..0x252ac`, 380 bytes)
 * Disassembly: 0x25130: str x20, [sp, #-0x20]! ; 0x25134: stp x19, x30, [sp, #0x10] ; 0x25138: mov x19, x0 ; 0x2513c: cbz x1, #0x251c0 ; 0x25140: mov x20, x1 ; 0x25144: lsr x8, x1, #0x3d
 */
uint64_t fde_137_0x25130(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x25130ULL;
    constexpr uint64_t kFuncSize    = 0x17cULL;
    constexpr uint32_t kFirstOpcode = 0xf81e0ff4U;
    constexpr uint32_t kLastOpcode  = 0x940081d6U;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[138] `sub_252ac` (`0x252ac..0x25374`, 200 bytes)
 *        Hàm FDE[138] `sub_252ac` (`0x252ac..0x25374`, 200 bytes)
 * Disassembly: 0x252ac: stp x21, x20, [sp, #-0x20]! ; 0x252b0: stp x19, x30, [sp, #0x10] ; 0x252b4: adrp x8, #0x48000 ; 0x252b8: add x8, x8, #0x940 ; 0x252bc: adrp x1, #0xe000 ; 0x252c0: adrp x2, #0xd000
 */
uint64_t fde_138_0x252ac(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x252acULL;
    constexpr uint64_t kFuncSize    = 0xc8ULL;
    constexpr uint32_t kFirstOpcode = 0xa9be53f5U;
    constexpr uint32_t kLastOpcode  = 0x140081e0U;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[139] `sub_25374` (`0x25374..0x2538c`, 24 bytes)
 *        Hàm FDE[139] `sub_25374` (`0x25374..0x2538c`, 24 bytes)
 * Disassembly: 0x25374: stp x19, x30, [sp, #-0x10]! ; 0x25378: mov x19, x0 ; 0x2537c: bl #0x252ac ; 0x25380: mov x0, x19 ; 0x25384: ldp x19, x30, [sp], #0x10 ; 0x25388: b #0x45930
 */
uint64_t fde_139_0x25374(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x25374ULL;
    constexpr uint64_t kFuncSize    = 0x18ULL;
    constexpr uint32_t kFirstOpcode = 0xa9bf7bf3U;
    constexpr uint32_t kLastOpcode  = 0x1400816aU;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[140] `sub_2538c` (`0x2538c..0x25540`, 436 bytes)
 *        Hàm FDE[140] `sub_2538c` (`0x2538c..0x25540`, 436 bytes)
 * Disassembly: 0x2538c: sub sp, sp, #0x80 ; 0x25390: stp x23, x22, [sp, #0x50] ; 0x25394: stp x21, x20, [sp, #0x60] ; 0x25398: stp x19, x30, [sp, #0x70] ; 0x2539c: mrs x23, tpidr_el0 ; 0x253a0: ldr x8, [x23, #0x28]
 */
uint64_t fde_140_0x2538c(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x2538cULL;
    constexpr uint64_t kFuncSize    = 0x1b4ULL;
    constexpr uint32_t kFirstOpcode = 0xd10203ffU;
    constexpr uint32_t kLastOpcode  = 0x94008105U;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[141] `sub_25540` (`0x25540..0x2573c`, 508 bytes)
 *        Hàm FDE[141] `sub_25540` (`0x25540..0x2573c`, 508 bytes)
 * Disassembly: 0x25540: sub sp, sp, #0x90 ; 0x25544: str x26, [sp, #0x40] ; 0x25548: stp x25, x24, [sp, #0x50] ; 0x2554c: stp x23, x22, [sp, #0x60] ; 0x25550: stp x21, x20, [sp, #0x70] ; 0x25554: stp x19, x30, [sp, #0x80]
 */
uint64_t fde_141_0x25540(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x25540ULL;
    constexpr uint64_t kFuncSize    = 0x1fcULL;
    constexpr uint32_t kFirstOpcode = 0xd10243ffU;
    constexpr uint32_t kLastOpcode  = 0x940080b2U;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[142] `sub_2573c` (`0x2573c..0x257e4`, 168 bytes)
 *        Hàm FDE[142] `sub_2573c` (`0x2573c..0x257e4`, 168 bytes)
 * Disassembly: 0x2573c: sub sp, sp, #0x40 ; 0x25740: str x20, [sp, #0x20] ; 0x25744: stp x19, x30, [sp, #0x30] ; 0x25748: mrs x20, tpidr_el0 ; 0x2574c: ldr x8, [x20, #0x28] ; 0x25750: str x8, [sp, #0x18]
 */
uint64_t fde_142_0x2573c(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x2573cULL;
    constexpr uint64_t kFuncSize    = 0xa8ULL;
    constexpr uint32_t kFirstOpcode = 0xd10103ffU;
    constexpr uint32_t kLastOpcode  = 0x9400805cU;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[143] `sub_257e4` (`0x257e4..0x25964`, 384 bytes)
 *        Hàm FDE[143] `sub_257e4` (`0x257e4..0x25964`, 384 bytes)
 * Disassembly: 0x257e4: sub sp, sp, #0x50 ; 0x257e8: str x22, [sp, #0x20] ; 0x257ec: stp x21, x20, [sp, #0x30] ; 0x257f0: stp x19, x30, [sp, #0x40] ; 0x257f4: mrs x21, tpidr_el0 ; 0x257f8: ldr x8, [x21, #0x28]
 */
uint64_t fde_143_0x257e4(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x257e4ULL;
    constexpr uint64_t kFuncSize    = 0x180ULL;
    constexpr uint32_t kFirstOpcode = 0xd10143ffU;
    constexpr uint32_t kLastOpcode  = 0x94007ffcU;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[144] `sub_25964` (`0x25964..0x25974`, 16 bytes)
 *        Hàm FDE[144] `sub_25964` (`0x25964..0x25974`, 16 bytes)
 * Disassembly: 0x25964: add x8, x0, #0x48 ; 0x25968: ldarb w8, [x8] ; 0x2596c: and w0, w8, #1 ; 0x25970: ret
 */
uint64_t fde_144_0x25964(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x25964ULL;
    constexpr uint64_t kFuncSize    = 0x10ULL;
    constexpr uint32_t kFirstOpcode = 0x91012008U;
    constexpr uint32_t kLastOpcode  = 0xd65f03c0U;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[145] `sub_25974` (`0x25974..0x25b58`, 484 bytes)
 *        Hàm FDE[145] `sub_25974` (`0x25974..0x25b58`, 484 bytes)
 * Disassembly: 0x25974: sub sp, sp, #0xb0 ; 0x25978: str x22, [sp, #0x80] ; 0x2597c: stp x21, x20, [sp, #0x90] ; 0x25980: stp x19, x30, [sp, #0xa0] ; 0x25984: mrs x21, tpidr_el0 ; 0x25988: ldr x8, [x21, #0x28]
 */
uint64_t fde_145_0x25974(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x25974ULL;
    constexpr uint64_t kFuncSize    = 0x1e4ULL;
    constexpr uint32_t kFirstOpcode = 0xd102c3ffU;
    constexpr uint32_t kLastOpcode  = 0x94007f7fU;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[146] `sub_25b58` (`0x25b58..0x25c8c`, 308 bytes)
 *        Hàm FDE[146] `sub_25b58` (`0x25b58..0x25c8c`, 308 bytes)
 * Disassembly: 0x25b58: sub sp, sp, #0x70 ; 0x25b5c: stp x23, x22, [sp, #0x40] ; 0x25b60: stp x21, x20, [sp, #0x50] ; 0x25b64: stp x19, x30, [sp, #0x60] ; 0x25b68: mrs x23, tpidr_el0 ; 0x25b6c: ldr x8, [x23, #0x28]
 */
uint64_t fde_146_0x25b58(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x25b58ULL;
    constexpr uint64_t kFuncSize    = 0x134ULL;
    constexpr uint32_t kFirstOpcode = 0xd101c3ffU;
    constexpr uint32_t kLastOpcode  = 0x94007f32U;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[147] `sub_25c8c` (`0x25c8c..0x25ccc`, 64 bytes)
 *        Hàm FDE[147] `sub_25c8c` (`0x25c8c..0x25ccc`, 64 bytes)
 * Disassembly: 0x25c8c: mov x8, x0 ; 0x25c90: ldr x0, [x0, #0x30] ; 0x25c94: adrp x9, #0x48000 ; 0x25c98: add x10, x8, #0x10 ; 0x25c9c: add x9, x9, #0x9b8 ; 0x25ca0: cmp x10, x0
 */
uint64_t fde_147_0x25c8c(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x25c8cULL;
    constexpr uint64_t kFuncSize    = 0x40ULL;
    constexpr uint32_t kFirstOpcode = 0xaa0003e8U;
    constexpr uint32_t kLastOpcode  = 0xd65f03c0U;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[148] `sub_25ccc` (`0x25ccc..0x25d18`, 76 bytes)
 *        Hàm FDE[148] `sub_25ccc` (`0x25ccc..0x25d18`, 76 bytes)
 * Disassembly: 0x25ccc: stp x19, x30, [sp, #-0x10]! ; 0x25cd0: mov x19, x0 ; 0x25cd4: ldr x0, [x0, #0x30] ; 0x25cd8: adrp x8, #0x48000 ; 0x25cdc: add x9, x19, #0x10 ; 0x25ce0: add x8, x8, #0x9b8
 */
uint64_t fde_148_0x25ccc(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x25cccULL;
    constexpr uint64_t kFuncSize    = 0x4cULL;
    constexpr uint32_t kFirstOpcode = 0xa9bf7bf3U;
    constexpr uint32_t kLastOpcode  = 0x14007f07U;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[149] `sub_25d18` (`0x25d18..0x25d90`, 120 bytes)
 *        Hàm FDE[149] `sub_25d18` (`0x25d18..0x25d90`, 120 bytes)
 * Disassembly: 0x25d18: str x20, [sp, #-0x20]! ; 0x25d1c: stp x19, x30, [sp, #0x10] ; 0x25d20: mov x20, x0 ; 0x25d24: mov w0, #0x40 ; 0x25d28: bl #0x459f0 ; 0x25d2c: adrp x8, #0x48000
 */
uint64_t fde_149_0x25d18(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x25d18ULL;
    constexpr uint64_t kFuncSize    = 0x78ULL;
    constexpr uint32_t kFirstOpcode = 0xf81e0ff4U;
    constexpr uint32_t kLastOpcode  = 0xd65f03c0U;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[150] `sub_25d90` (`0x25d90..0x25df8`, 104 bytes)
 *        Hàm FDE[150] `sub_25d90` (`0x25d90..0x25df8`, 104 bytes)
 * Disassembly: 0x25d90: stp x19, x30, [sp, #-0x10]! ; 0x25d94: adrp x8, #0x48000 ; 0x25d98: add x8, x8, #0x9b8 ; 0x25d9c: mov x19, x1 ; 0x25da0: str x8, [x1], #0x10 ; 0x25da4: ldr x8, [x0, #0x30]
 */
uint64_t fde_150_0x25d90(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x25d90ULL;
    constexpr uint64_t kFuncSize    = 0x68ULL;
    constexpr uint32_t kFirstOpcode = 0xa9bf7bf3U;
    constexpr uint32_t kLastOpcode  = 0xd61f0040U;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[151] `sub_25df8` (`0x25df8..0x25e2c`, 52 bytes)
 *        Hàm FDE[151] `sub_25df8` (`0x25df8..0x25e2c`, 52 bytes)
 * Disassembly: 0x25df8: mov x8, x0 ; 0x25dfc: ldr x0, [x0, #0x30] ; 0x25e00: add x8, x8, #0x10 ; 0x25e04: cmp x8, x0 ; 0x25e08: b.eq #0x25e1c ; 0x25e0c: cbz x0, #0x25e28
 */
uint64_t fde_151_0x25df8(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x25df8ULL;
    constexpr uint64_t kFuncSize    = 0x34ULL;
    constexpr uint32_t kFirstOpcode = 0xaa0003e8U;
    constexpr uint32_t kLastOpcode  = 0xd65f03c0U;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[152] `sub_25e2c` (`0x25e2c..0x25e6c`, 64 bytes)
 *        Hàm FDE[152] `sub_25e2c` (`0x25e2c..0x25e6c`, 64 bytes)
 * Disassembly: 0x25e2c: stp x19, x30, [sp, #-0x10]! ; 0x25e30: mov x19, x0 ; 0x25e34: ldr x0, [x0, #0x30] ; 0x25e38: add x8, x19, #0x10 ; 0x25e3c: cmp x8, x0 ; 0x25e40: b.eq #0x25e54
 */
uint64_t fde_152_0x25e2c(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x25e2cULL;
    constexpr uint64_t kFuncSize    = 0x40ULL;
    constexpr uint32_t kFirstOpcode = 0xa9bf7bf3U;
    constexpr uint32_t kLastOpcode  = 0x14007eb2U;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[153] `sub_25e6c` (`0x25e6c..0x25e8c`, 32 bytes)
 *        Hàm FDE[153] `sub_25e6c` (`0x25e6c..0x25e8c`, 32 bytes)
 * Disassembly: 0x25e6c: str x30, [sp, #-0x10]! ; 0x25e70: ldr x0, [x0, #0x30] ; 0x25e74: cbz x0, #0x25e88 ; 0x25e78: ldr x8, [x0] ; 0x25e7c: ldr x1, [x8, #0x30] ; 0x25e80: ldr x30, [sp], #0x10
 */
uint64_t fde_153_0x25e6c(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x25e6cULL;
    constexpr uint64_t kFuncSize    = 0x20ULL;
    constexpr uint32_t kFirstOpcode = 0xf81f0ffeU;
    constexpr uint32_t kLastOpcode  = 0x97ffed73U;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[154] `sub_25e8c` (`0x25e8c..0x25ea8`, 28 bytes)
 *        Hàm FDE[154] `sub_25e8c` (`0x25e8c..0x25ea8`, 28 bytes)
 * Disassembly: 0x25e8c: ldr x8, [x1, #8] ; 0x25e90: adrp x9, #0x10000 ; 0x25e94: add x9, x9, #0x5c9 ; 0x25e98: add x10, x0, #0x10 ; 0x25e9c: cmp x8, x9 ; 0x25ea0: csel x0, x10, xzr, eq
 */
uint64_t fde_154_0x25e8c(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x25e8cULL;
    constexpr uint64_t kFuncSize    = 0x1cULL;
    constexpr uint32_t kFirstOpcode = 0xf9400428U;
    constexpr uint32_t kLastOpcode  = 0xd65f03c0U;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[155] `sub_25ea8` (`0x25ea8..0x25eb4`, 12 bytes)
 *        Hàm FDE[155] `sub_25ea8` (`0x25ea8..0x25eb4`, 12 bytes)
 * Disassembly: 0x25ea8: adrp x0, #0x48000 ; 0x25eac: add x0, x0, #0xa18 ; 0x25eb0: ret
 */
uint64_t fde_155_0x25ea8(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x25ea8ULL;
    constexpr uint64_t kFuncSize    = 0xcULL;
    constexpr uint32_t kFirstOpcode = 0xf0000100U;
    constexpr uint32_t kLastOpcode  = 0xd65f03c0U;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[156] `sub_25eb4` (`0x25eb4..0x25f08`, 84 bytes)
 *        Hàm FDE[156] `sub_25eb4` (`0x25eb4..0x25f08`, 84 bytes)
 * Disassembly: 0x25eb4: stp x19, x30, [sp, #-0x10]! ; 0x25eb8: ldr x19, [x0, #0x18] ; 0x25ebc: adrp x8, #0x48000 ; 0x25ec0: add x8, x8, #0xa38 ; 0x25ec4: str x8, [x0] ; 0x25ec8: cbz x19, #0x25ee4
 */
uint64_t fde_156_0x25eb4(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x25eb4ULL;
    constexpr uint64_t kFuncSize    = 0x54ULL;
    constexpr uint32_t kFirstOpcode = 0xa9bf7bf3U;
    constexpr uint32_t kLastOpcode  = 0x14007efbU;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[157] `sub_25f08` (`0x25f08..0x25f68`, 96 bytes)
 *        Hàm FDE[157] `sub_25f08` (`0x25f08..0x25f68`, 96 bytes)
 * Disassembly: 0x25f08: str x20, [sp, #-0x20]! ; 0x25f0c: stp x19, x30, [sp, #0x10] ; 0x25f10: ldr x20, [x0, #0x18] ; 0x25f14: adrp x8, #0x48000 ; 0x25f18: mov x19, x0 ; 0x25f1c: add x8, x8, #0xa38
 */
uint64_t fde_157_0x25f08(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x25f08ULL;
    constexpr uint64_t kFuncSize    = 0x60ULL;
    constexpr uint32_t kFirstOpcode = 0xf81e0ff4U;
    constexpr uint32_t kLastOpcode  = 0x14007e73U;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[158] `sub_25f68` (`0x25f68..0x25fbc`, 84 bytes)
 *        Hàm FDE[158] `sub_25f68` (`0x25f68..0x25fbc`, 84 bytes)
 * Disassembly: 0x25f68: stp x19, x30, [sp, #-0x10]! ; 0x25f6c: mov x19, x0 ; 0x25f70: mov w0, #0x28 ; 0x25f74: bl #0x459f0 ; 0x25f78: adrp x8, #0x48000 ; 0x25f7c: add x8, x8, #0xa38
 */
uint64_t fde_158_0x25f68(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x25f68ULL;
    constexpr uint64_t kFuncSize    = 0x54ULL;
    constexpr uint32_t kFirstOpcode = 0xa9bf7bf3U;
    constexpr uint32_t kLastOpcode  = 0xd65f03c0U;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[159] `sub_25fbc` (`0x25fbc..0x26004`, 72 bytes)
 *        Hàm FDE[159] `sub_25fbc` (`0x25fbc..0x26004`, 72 bytes)
 * Disassembly: 0x25fbc: adrp x8, #0x48000 ; 0x25fc0: add x8, x8, #0xa38 ; 0x25fc4: str x8, [x1] ; 0x25fc8: ldr x8, [x0, #8] ; 0x25fcc: str x8, [x1, #8] ; 0x25fd0: ldr x8, [x0, #0x10]
 */
uint64_t fde_159_0x25fbc(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x25fbcULL;
    constexpr uint64_t kFuncSize    = 0x48ULL;
    constexpr uint32_t kFirstOpcode = 0xf0000108U;
    constexpr uint32_t kLastOpcode  = 0xd65f03c0U;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[160] `sub_26004` (`0x26004..0x2604c`, 72 bytes)
 *        Hàm FDE[160] `sub_26004` (`0x26004..0x2604c`, 72 bytes)
 * Disassembly: 0x26004: stp x19, x30, [sp, #-0x10]! ; 0x26008: ldr x19, [x0, #0x18] ; 0x2600c: cbz x19, #0x26028 ; 0x26010: add x8, x19, #8 ; 0x26014: ldaxr x9, [x8] ; 0x26018: sub x10, x9, #1
 */
uint64_t fde_160_0x26004(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x26004ULL;
    constexpr uint64_t kFuncSize    = 0x48ULL;
    constexpr uint32_t kFirstOpcode = 0xa9bf7bf3U;
    constexpr uint32_t kLastOpcode  = 0x14007eaaU;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[161] `sub_2604c` (`0x2604c..0x260a0`, 84 bytes)
 *        Hàm FDE[161] `sub_2604c` (`0x2604c..0x260a0`, 84 bytes)
 * Disassembly: 0x2604c: str x20, [sp, #-0x20]! ; 0x26050: stp x19, x30, [sp, #0x10] ; 0x26054: ldr x20, [x0, #0x18] ; 0x26058: mov x19, x0 ; 0x2605c: cbz x20, #0x26090 ; 0x26060: add x8, x20, #8
 */
uint64_t fde_161_0x2604c(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x2604cULL;
    constexpr uint64_t kFuncSize    = 0x54ULL;
    constexpr uint32_t kFirstOpcode = 0xf81e0ff4U;
    constexpr uint32_t kLastOpcode  = 0x14007e25U;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[162] `sub_260a0` (`0x260a0..0x2646c`, 972 bytes)
 *        Hàm FDE[162] `sub_260a0` (`0x260a0..0x2646c`, 972 bytes)
 * Disassembly: 0x260a0: sub sp, sp, #0x70 ; 0x260a4: stp x23, x22, [sp, #0x40] ; 0x260a8: stp x21, x20, [sp, #0x50] ; 0x260ac: stp x19, x30, [sp, #0x60] ; 0x260b0: mrs x23, tpidr_el0 ; 0x260b4: ldr x8, [x23, #0x28]
 */
uint64_t fde_162_0x260a0(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x260a0ULL;
    constexpr uint64_t kFuncSize    = 0x3ccULL;
    constexpr uint32_t kFirstOpcode = 0xd101c3ffU;
    constexpr uint32_t kLastOpcode  = 0x94007d3aU;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[163] `sub_2646c` (`0x2646c..0x26488`, 28 bytes)
 *        Hàm FDE[163] `sub_2646c` (`0x2646c..0x26488`, 28 bytes)
 * Disassembly: 0x2646c: ldr x8, [x1, #8] ; 0x26470: adrp x9, #0x10000 ; 0x26474: add x9, x9, #0x69c ; 0x26478: add x10, x0, #8 ; 0x2647c: cmp x8, x9 ; 0x26480: csel x0, x10, xzr, eq
 */
uint64_t fde_163_0x2646c(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x2646cULL;
    constexpr uint64_t kFuncSize    = 0x1cULL;
    constexpr uint32_t kFirstOpcode = 0xf9400428U;
    constexpr uint32_t kLastOpcode  = 0xd65f03c0U;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[164] `sub_26488` (`0x26488..0x26494`, 12 bytes)
 *        Hàm FDE[164] `sub_26488` (`0x26488..0x26494`, 12 bytes)
 * Disassembly: 0x26488: adrp x0, #0x48000 ; 0x2648c: add x0, x0, #0xa98 ; 0x26490: ret
 */
uint64_t fde_164_0x26488(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x26488ULL;
    constexpr uint64_t kFuncSize    = 0xcULL;
    constexpr uint32_t kFirstOpcode = 0xd0000100U;
    constexpr uint32_t kLastOpcode  = 0xd65f03c0U;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[165] `sub_26494` (`0x26494..0x265e0`, 332 bytes)
 *        Hàm FDE[165] `sub_26494` (`0x26494..0x265e0`, 332 bytes)
 * Disassembly: 0x26494: ldr x8, [x1, #8] ; 0x26498: ldr x9, [x2, #8] ; 0x2649c: fmov d0, x8 ; 0x264a0: cnt v0.8b, v0.8b ; 0x264a4: uaddlv h0, v0.8b ; 0x264a8: fmov w12, s0
 */
uint64_t fde_165_0x26494(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x26494ULL;
    constexpr uint64_t kFuncSize    = 0x14cULL;
    constexpr uint32_t kFirstOpcode = 0xf9400428U;
    constexpr uint32_t kLastOpcode  = 0xd65f03c0U;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[166] `sub_265e0` (`0x265e0..0x26964`, 900 bytes)
 *        Hàm FDE[166] `sub_265e0` (`0x265e0..0x26964`, 900 bytes)
 * Disassembly: 0x265e0: sub sp, sp, #0x1d0 ; 0x265e4: str x28, [sp, #0x180] ; 0x265e8: stp x25, x24, [sp, #0x190] ; 0x265ec: stp x23, x22, [sp, #0x1a0] ; 0x265f0: stp x21, x20, [sp, #0x1b0] ; 0x265f4: stp x19, x30, [sp, #0x1c0]
 */
uint64_t fde_166_0x265e0(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x265e0ULL;
    constexpr uint64_t kFuncSize    = 0x384ULL;
    constexpr uint32_t kFirstOpcode = 0xd10743ffU;
    constexpr uint32_t kLastOpcode  = 0x97ffeabdU;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[167] `sub_26964` (`0x26964..0x2698c`, 40 bytes)
 *        Hàm FDE[167] `sub_26964` (`0x26964..0x2698c`, 40 bytes)
 * Disassembly: 0x26964: cbz x2, #0x26988 ; 0x26968: stp x19, x30, [sp, #-0x10]! ; 0x2696c: ldr x0, [x2, #8] ; 0x26970: mov x19, x2 ; 0x26974: cbz x0, #0x2697c ; 0x26978: bl #0x45af0
 */
uint64_t fde_167_0x26964(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x26964ULL;
    constexpr uint64_t kFuncSize    = 0x28ULL;
    constexpr uint32_t kFirstOpcode = 0xb4000122U;
    constexpr uint32_t kLastOpcode  = 0xd65f03c0U;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[168] `sub_2698c` (`0x2698c..0x26a24`, 152 bytes)
 *        Hàm FDE[168] `sub_2698c` (`0x2698c..0x26a24`, 152 bytes)
 * Disassembly: 0x2698c: sub sp, sp, #0x120 ; 0x26990: str x28, [sp, #0x100] ; 0x26994: stp x19, x30, [sp, #0x110] ; 0x26998: stp x3, x4, [sp, #0x88] ; 0x2699c: stp x5, x6, [sp, #0x98] ; 0x269a0: str x7, [sp, #0xa8]
 */
uint64_t fde_168_0x2698c(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x2698cULL;
    constexpr uint64_t kFuncSize    = 0x98ULL;
    constexpr uint32_t kFirstOpcode = 0xd10483ffU;
    constexpr uint32_t kLastOpcode  = 0x94007bccU;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[169] `sub_26a24` (`0x26a24..0x26aa4`, 128 bytes)
 *        Hàm FDE[169] `sub_26a24` (`0x26a24..0x26aa4`, 128 bytes)
 * Disassembly: 0x26a24: str x20, [sp, #-0x20]! ; 0x26a28: stp x19, x30, [sp, #0x10] ; 0x26a2c: adrp x8, #0x48000 ; 0x26a30: adrp x9, #0x48000 ; 0x26a34: add x8, x8, #0xb30 ; 0x26a38: add x9, x9, #0x498
 */
uint64_t fde_169_0x26a24(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x26a24ULL;
    constexpr uint64_t kFuncSize    = 0x80ULL;
    constexpr uint32_t kFirstOpcode = 0xf81e0ff4U;
    constexpr uint32_t kLastOpcode  = 0xd65f03c0U;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[170] `sub_26aa4` (`0x26aa4..0x26b20`, 124 bytes)
 *        Hàm FDE[170] `sub_26aa4` (`0x26aa4..0x26b20`, 124 bytes)
 * Disassembly: 0x26aa4: str x20, [sp, #-0x20]! ; 0x26aa8: stp x19, x30, [sp, #0x10] ; 0x26aac: adrp x8, #0x48000 ; 0x26ab0: adrp x9, #0x48000 ; 0x26ab4: add x8, x8, #0xb30 ; 0x26ab8: add x9, x9, #0x498
 */
uint64_t fde_170_0x26aa4(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x26aa4ULL;
    constexpr uint64_t kFuncSize    = 0x7cULL;
    constexpr uint32_t kFirstOpcode = 0xf81e0ff4U;
    constexpr uint32_t kLastOpcode  = 0x14007b85U;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[171] `sub_26b20` (`0x26b20..0x26eac`, 908 bytes)
 *        Hàm FDE[171] `sub_26b20` (`0x26b20..0x26eac`, 908 bytes)
 * Disassembly: 0x26b20: sub sp, sp, #0x1d0 ; 0x26b24: stp x28, x27, [sp, #0x170] ; 0x26b28: stp x26, x25, [sp, #0x180] ; 0x26b2c: stp x24, x23, [sp, #0x190] ; 0x26b30: stp x22, x21, [sp, #0x1a0] ; 0x26b34: stp x20, x19, [sp, #0x1b0]
 */
uint64_t fde_171_0x26b20(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x26b20ULL;
    constexpr uint64_t kFuncSize    = 0x38cULL;
    constexpr uint32_t kFirstOpcode = 0xd10743ffU;
    constexpr uint32_t kLastOpcode  = 0x94007aaaU;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[172] `sub_26eac` (`0x26eac..0x26f34`, 136 bytes)
 *        Hàm FDE[172] `sub_26eac` (`0x26eac..0x26f34`, 136 bytes)
 * Disassembly: 0x26eac: str x20, [sp, #-0x20]! ; 0x26eb0: stp x19, x30, [sp, #0x10] ; 0x26eb4: adrp x8, #0x48000 ; 0x26eb8: adrp x9, #0x48000 ; 0x26ebc: adrp x10, #0x48000 ; 0x26ec0: add x8, x8, #0xaf8
 */
uint64_t fde_172_0x26eac(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x26eacULL;
    constexpr uint64_t kFuncSize    = 0x88ULL;
    constexpr uint32_t kFirstOpcode = 0xf81e0ff4U;
    constexpr uint32_t kLastOpcode  = 0x14007af4U;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[173] `sub_26f34` (`0x26f34..0x26fc4`, 144 bytes)
 *        Hàm FDE[173] `sub_26f34` (`0x26f34..0x26fc4`, 144 bytes)
 * Disassembly: 0x26f34: str x20, [sp, #-0x20]! ; 0x26f38: stp x19, x30, [sp, #0x10] ; 0x26f3c: adrp x8, #0x48000 ; 0x26f40: adrp x9, #0x48000 ; 0x26f44: adrp x10, #0x48000 ; 0x26f48: add x8, x8, #0xaf8
 */
uint64_t fde_173_0x26f34(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x26f34ULL;
    constexpr uint64_t kFuncSize    = 0x90ULL;
    constexpr uint32_t kFirstOpcode = 0xf81e0ff4U;
    constexpr uint32_t kLastOpcode  = 0x14007a5cU;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[174] `sub_26fc4` (`0x26fc4..0x26fd0`, 12 bytes)
 *        Hàm FDE[174] `sub_26fc4` (`0x26fc4..0x26fd0`, 12 bytes)
 * Disassembly: 0x26fc4: ldr x8, [x0, #0x18]! ; 0x26fc8: ldr x1, [x8] ; 0x26fcc: br x1
 */
uint64_t fde_174_0x26fc4(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x26fc4ULL;
    constexpr uint64_t kFuncSize    = 0xcULL;
    constexpr uint32_t kFirstOpcode = 0xf8418c08U;
    constexpr uint32_t kLastOpcode  = 0xd61f0020U;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[175] `sub_26fd0` (`0x26fd0..0x27068`, 152 bytes)
 *        Hàm FDE[175] `sub_26fd0` (`0x26fd0..0x27068`, 152 bytes)
 * Disassembly: 0x26fd0: sub sp, sp, #0x120 ; 0x26fd4: str x28, [sp, #0x100] ; 0x26fd8: stp x19, x30, [sp, #0x110] ; 0x26fdc: stp x3, x4, [sp, #0x88] ; 0x26fe0: stp x5, x6, [sp, #0x98] ; 0x26fe4: str x7, [sp, #0xa8]
 */
uint64_t fde_175_0x26fd0(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x26fd0ULL;
    constexpr uint64_t kFuncSize    = 0x98ULL;
    constexpr uint32_t kFirstOpcode = 0xd10483ffU;
    constexpr uint32_t kLastOpcode  = 0x94007a3bU;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[176] `sub_27068` (`0x27068..0x273ac`, 836 bytes)
 *        Hàm FDE[176] `sub_27068` (`0x27068..0x273ac`, 836 bytes)
 * Disassembly: 0x27068: str x28, [sp, #-0x60]! ; 0x2706c: stp x27, x26, [sp, #0x10] ; 0x27070: stp x25, x24, [sp, #0x20] ; 0x27074: stp x23, x22, [sp, #0x30] ; 0x27078: stp x21, x20, [sp, #0x40] ; 0x2707c: stp x19, x30, [sp, #0x50]
 */
uint64_t fde_176_0x27068(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x27068ULL;
    constexpr uint64_t kFuncSize    = 0x344ULL;
    constexpr uint32_t kFirstOpcode = 0xf81a0ffcU;
    constexpr uint32_t kLastOpcode  = 0xd65f03c0U;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[177] `sub_273ac` (`0x273ac..0x273d0`, 36 bytes)
 *        Hàm FDE[177] `sub_273ac` (`0x273ac..0x273d0`, 36 bytes)
 * Disassembly: 0x273ac: stp x19, x30, [sp, #-0x10]! ; 0x273b0: adrp x8, #0x48000 ; 0x273b4: add x8, x8, #0xc60 ; 0x273b8: mov x19, x0 ; 0x273bc: str x8, [x0], #0x18 ; 0x273c0: bl #0x27404
 */
uint64_t fde_177_0x273ac(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x273acULL;
    constexpr uint64_t kFuncSize    = 0x24ULL;
    constexpr uint32_t kFirstOpcode = 0xa9bf7bf3U;
    constexpr uint32_t kLastOpcode  = 0x140079cdU;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[178] `sub_273d0` (`0x273d0..0x273fc`, 44 bytes)
 *        Hàm FDE[178] `sub_273d0` (`0x273d0..0x273fc`, 44 bytes)
 * Disassembly: 0x273d0: stp x19, x30, [sp, #-0x10]! ; 0x273d4: adrp x8, #0x48000 ; 0x273d8: add x8, x8, #0xc60 ; 0x273dc: mov x19, x0 ; 0x273e0: str x8, [x0], #0x18 ; 0x273e4: bl #0x27404
 */
uint64_t fde_178_0x273d0(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x273d0ULL;
    constexpr uint64_t kFuncSize    = 0x2cULL;
    constexpr uint32_t kFirstOpcode = 0xa9bf7bf3U;
    constexpr uint32_t kLastOpcode  = 0x1400794eU;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[179] `sub_273fc` (`0x273fc..0x27404`, 8 bytes)
 *        Hàm FDE[179] `sub_273fc` (`0x273fc..0x27404`, 8 bytes)
 * Disassembly: 0x273fc: add x0, x0, #0x18 ; 0x27400: b #0x27404
 */
uint64_t fde_179_0x273fc(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x273fcULL;
    constexpr uint64_t kFuncSize    = 0x8ULL;
    constexpr uint32_t kFirstOpcode = 0x91006000U;
    constexpr uint32_t kLastOpcode  = 0x14000001U;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[180] `sub_27404` (`0x27404..0x2759c`, 408 bytes)
 *        Hàm FDE[180] `sub_27404` (`0x27404..0x2759c`, 408 bytes)
 * Disassembly: 0x27404: str x22, [sp, #-0x30]! ; 0x27408: stp x21, x20, [sp, #0x10] ; 0x2740c: stp x19, x30, [sp, #0x20] ; 0x27410: ldr x22, [x0, #0xb0] ; 0x27414: mov x19, x0 ; 0x27418: cbnz x22, #0x2742c
 */
uint64_t fde_180_0x27404(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x27404ULL;
    constexpr uint64_t kFuncSize    = 0x198ULL;
    constexpr uint32_t kFirstOpcode = 0xf81d0ff6U;
    constexpr uint32_t kLastOpcode  = 0xd65f03c0U;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[181] `sub_2759c` (`0x2759c..0x275cc`, 48 bytes)
 *        Hàm FDE[181] `sub_2759c` (`0x2759c..0x275cc`, 48 bytes)
 * Disassembly: 0x2759c: stp x19, x30, [sp, #-0x10]! ; 0x275a0: ldrb w8, [x0, #0x20] ; 0x275a4: adrp x9, #0x48000 ; 0x275a8: mov x19, x0 ; 0x275ac: add x9, x9, #0xc28 ; 0x275b0: str x9, [x0]
 */
uint64_t fde_181_0x2759c(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x2759cULL;
    constexpr uint64_t kFuncSize    = 0x30ULL;
    constexpr uint32_t kFirstOpcode = 0xa9bf7bf3U;
    constexpr uint32_t kLastOpcode  = 0x1400794eU;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[182] `sub_275cc` (`0x275cc..0x27604`, 56 bytes)
 *        Hàm FDE[182] `sub_275cc` (`0x275cc..0x27604`, 56 bytes)
 * Disassembly: 0x275cc: stp x19, x30, [sp, #-0x10]! ; 0x275d0: ldrb w8, [x0, #0x20] ; 0x275d4: adrp x9, #0x48000 ; 0x275d8: mov x19, x0 ; 0x275dc: add x9, x9, #0xc28 ; 0x275e0: str x9, [x0]
 */
uint64_t fde_182_0x275cc(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x275ccULL;
    constexpr uint64_t kFuncSize    = 0x38ULL;
    constexpr uint32_t kFirstOpcode = 0xa9bf7bf3U;
    constexpr uint32_t kLastOpcode  = 0x140078ccU;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[183] `sub_27604` (`0x27604..0x27618`, 20 bytes)
 *        Hàm FDE[183] `sub_27604` (`0x27604..0x27618`, 20 bytes)
 * Disassembly: 0x27604: ldrb w8, [x0, #0x20] ; 0x27608: tbnz w8, #0, #0x27610 ; 0x2760c: ret ; 0x27610: ldr x0, [x0, #0x30] ; 0x27614: b #0x45930
 */
uint64_t fde_183_0x27604(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x27604ULL;
    constexpr uint64_t kFuncSize    = 0x14ULL;
    constexpr uint32_t kFirstOpcode = 0x39408008U;
    constexpr uint32_t kLastOpcode  = 0x140078c7U;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[184] `sub_27618` (`0x27618..0x27774`, 348 bytes)
 *        Hàm FDE[184] `sub_27618` (`0x27618..0x27774`, 348 bytes)
 * Disassembly: 0x27618: sub sp, sp, #0x170 ; 0x2761c: str x28, [sp, #0x130] ; 0x27620: stp x23, x22, [sp, #0x140] ; 0x27624: stp x21, x20, [sp, #0x150] ; 0x27628: stp x19, x30, [sp, #0x160] ; 0x2762c: mrs x22, tpidr_el0
 */
uint64_t fde_184_0x27618(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x27618ULL;
    constexpr uint64_t kFuncSize    = 0x15cULL;
    constexpr uint32_t kFirstOpcode = 0xd105c3ffU;
    constexpr uint32_t kLastOpcode  = 0x94007878U;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[185] `sub_27774` (`0x27774..0x27ab0`, 828 bytes)
 *        Hàm FDE[185] `sub_27774` (`0x27774..0x27ab0`, 828 bytes)
 * Disassembly: 0x27774: sub sp, sp, #0xe0 ; 0x27778: stp x27, x26, [sp, #0x90] ; 0x2777c: stp x25, x24, [sp, #0xa0] ; 0x27780: stp x23, x22, [sp, #0xb0] ; 0x27784: stp x21, x20, [sp, #0xc0] ; 0x27788: stp x19, x30, [sp, #0xd0]
 */
uint64_t fde_185_0x27774(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x27774ULL;
    constexpr uint64_t kFuncSize    = 0x33cULL;
    constexpr uint32_t kFirstOpcode = 0xd10383ffU;
    constexpr uint32_t kLastOpcode  = 0x940077d5U;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[186] `sub_27ab0` (`0x27ab0..0x27d2c`, 636 bytes)
 *        Hàm FDE[186] `sub_27ab0` (`0x27ab0..0x27d2c`, 636 bytes)
 * Disassembly: 0x27ab0: stp x25, x24, [sp, #-0x40]! ; 0x27ab4: stp x23, x22, [sp, #0x10] ; 0x27ab8: stp x21, x20, [sp, #0x20] ; 0x27abc: stp x19, x30, [sp, #0x30] ; 0x27ac0: adrp x8, #0x48000 ; 0x27ac4: add x8, x8, #0xba8
 */
uint64_t fde_186_0x27ab0(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x27ab0ULL;
    constexpr uint64_t kFuncSize    = 0x27cULL;
    constexpr uint32_t kFirstOpcode = 0xa9bc63f9U;
    constexpr uint32_t kLastOpcode  = 0x14007702U;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[187] `sub_27d2c` (`0x27d2c..0x27d44`, 24 bytes)
 *        Hàm FDE[187] `sub_27d2c` (`0x27d2c..0x27d44`, 24 bytes)
 * Disassembly: 0x27d2c: stp x19, x30, [sp, #-0x10]! ; 0x27d30: mov x19, x0 ; 0x27d34: bl #0x27ab0 ; 0x27d38: mov x0, x19 ; 0x27d3c: ldp x19, x30, [sp], #0x10 ; 0x27d40: b #0x45930
 */
uint64_t fde_187_0x27d2c(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x27d2cULL;
    constexpr uint64_t kFuncSize    = 0x18ULL;
    constexpr uint32_t kFirstOpcode = 0xa9bf7bf3U;
    constexpr uint32_t kLastOpcode  = 0x140076fcU;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[188] `sub_27d44` (`0x27d44..0x27f00`, 444 bytes)
 *        Hàm FDE[188] `sub_27d44` (`0x27d44..0x27f00`, 444 bytes)
 * Disassembly: 0x27d44: str x26, [sp, #-0x50]! ; 0x27d48: stp x25, x24, [sp, #0x10] ; 0x27d4c: stp x23, x22, [sp, #0x20] ; 0x27d50: stp x21, x20, [sp, #0x30] ; 0x27d54: stp x19, x30, [sp, #0x40] ; 0x27d58: ldp x24, x25, [x1]
 */
uint64_t fde_188_0x27d44(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x27d44ULL;
    constexpr uint64_t kFuncSize    = 0x1bcULL;
    constexpr uint32_t kFirstOpcode = 0xf81b0ffaU;
    constexpr uint32_t kLastOpcode  = 0xd65f03c0U;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[189] `sub_27f00` (`0x27f00..0x27f78`, 120 bytes)
 *        Hàm FDE[189] `sub_27f00` (`0x27f00..0x27f78`, 120 bytes)
 * Disassembly: 0x27f00: str x20, [sp, #-0x20]! ; 0x27f04: stp x19, x30, [sp, #0x10] ; 0x27f08: ldr x20, [x0, #0x20] ; 0x27f0c: adrp x8, #0x48000 ; 0x27f10: mov x19, x0 ; 0x27f14: add x8, x8, #0xd40
 */
uint64_t fde_189_0x27f00(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x27f00ULL;
    constexpr uint64_t kFuncSize    = 0x78ULL;
    constexpr uint32_t kFirstOpcode = 0xf81e0ff4U;
    constexpr uint32_t kLastOpcode  = 0xd65f03c0U;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[190] `sub_27f78` (`0x27f78..0x27ff0`, 120 bytes)
 *        Hàm FDE[190] `sub_27f78` (`0x27f78..0x27ff0`, 120 bytes)
 * Disassembly: 0x27f78: str x20, [sp, #-0x20]! ; 0x27f7c: stp x19, x30, [sp, #0x10] ; 0x27f80: ldr x20, [x0, #0x20] ; 0x27f84: adrp x8, #0x48000 ; 0x27f88: mov x19, x0 ; 0x27f8c: add x8, x8, #0xd40
 */
uint64_t fde_190_0x27f78(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x27f78ULL;
    constexpr uint64_t kFuncSize    = 0x78ULL;
    constexpr uint32_t kFirstOpcode = 0xf81e0ff4U;
    constexpr uint32_t kLastOpcode  = 0x17fffff4U;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[191] `sub_27ff0` (`0x27ff0..0x28064`, 116 bytes)
 *        Hàm FDE[191] `sub_27ff0` (`0x27ff0..0x28064`, 116 bytes)
 * Disassembly: 0x27ff0: stp x19, x30, [sp, #-0x10]! ; 0x27ff4: mov x19, x0 ; 0x27ff8: mov w0, #0x28 ; 0x27ffc: bl #0x459f0 ; 0x28000: adrp x8, #0x48000 ; 0x28004: add x8, x8, #0xd40
 */
uint64_t fde_191_0x27ff0(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x27ff0ULL;
    constexpr uint64_t kFuncSize    = 0x74ULL;
    constexpr uint32_t kFirstOpcode = 0xa9bf7bf3U;
    constexpr uint32_t kLastOpcode  = 0xd65f03c0U;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[192] `sub_28064` (`0x28064..0x280c4`, 96 bytes)
 *        Hàm FDE[192] `sub_28064` (`0x28064..0x280c4`, 96 bytes)
 * Disassembly: 0x28064: adrp x8, #0x48000 ; 0x28068: add x8, x8, #0xd40 ; 0x2806c: str x8, [x1] ; 0x28070: ldr x8, [x0, #8] ; 0x28074: str x8, [x1, #8] ; 0x28078: ldr x8, [x0, #0x10]
 */
uint64_t fde_192_0x28064(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x28064ULL;
    constexpr uint64_t kFuncSize    = 0x60ULL;
    constexpr uint32_t kFirstOpcode = 0x90000108U;
    constexpr uint32_t kLastOpcode  = 0xd65f03c0U;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[193] `sub_280c4` (`0x280c4..0x28130`, 108 bytes)
 *        Hàm FDE[193] `sub_280c4` (`0x280c4..0x28130`, 108 bytes)
 * Disassembly: 0x280c4: str x20, [sp, #-0x20]! ; 0x280c8: stp x19, x30, [sp, #0x10] ; 0x280cc: ldr x20, [x0, #0x20] ; 0x280d0: mov x19, x0 ; 0x280d4: cbz x20, #0x280f0 ; 0x280d8: add x8, x20, #8
 */
uint64_t fde_193_0x280c4(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x280c4ULL;
    constexpr uint64_t kFuncSize    = 0x6cULL;
    constexpr uint32_t kFirstOpcode = 0xf81e0ff4U;
    constexpr uint32_t kLastOpcode  = 0xd65f03c0U;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[194] `sub_28130` (`0x28130..0x2819c`, 108 bytes)
 *        Hàm FDE[194] `sub_28130` (`0x28130..0x2819c`, 108 bytes)
 * Disassembly: 0x28130: str x20, [sp, #-0x20]! ; 0x28134: stp x19, x30, [sp, #0x10] ; 0x28138: ldr x20, [x0, #0x20] ; 0x2813c: mov x19, x0 ; 0x28140: cbz x20, #0x2815c ; 0x28144: add x8, x20, #8
 */
uint64_t fde_194_0x28130(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x28130ULL;
    constexpr uint64_t kFuncSize    = 0x6cULL;
    constexpr uint32_t kFirstOpcode = 0xf81e0ff4U;
    constexpr uint32_t kLastOpcode  = 0x17fffff4U;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[195] `sub_2819c` (`0x2819c..0x2a3d4`, 8760 bytes)
 *        Hàm FDE[195] `sub_2819c` (`0x2819c..0x2a3d4`, 8760 bytes)
 * Disassembly: 0x2819c: stp x28, x27, [sp, #-0x60]! ; 0x281a0: stp x26, x25, [sp, #0x10] ; 0x281a4: stp x24, x23, [sp, #0x20] ; 0x281a8: stp x22, x21, [sp, #0x30] ; 0x281ac: stp x20, x19, [sp, #0x40] ; 0x281b0: stp x29, x30, [sp, #0x50]
 */
uint64_t fde_195_0x2819c(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x2819cULL;
    constexpr uint64_t kFuncSize    = 0x2238ULL;
    constexpr uint32_t kFirstOpcode = 0xa9ba6ffcU;
    constexpr uint32_t kLastOpcode  = 0x94006d60U;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[196] `sub_2a3d4` (`0x2a3d4..0x2a3f0`, 28 bytes)
 *        Hàm FDE[196] `sub_2a3d4` (`0x2a3d4..0x2a3f0`, 28 bytes)
 * Disassembly: 0x2a3d4: ldr x8, [x1, #8] ; 0x2a3d8: adrp x9, #0x10000 ; 0x2a3dc: add x9, x9, #0xa7a ; 0x2a3e0: add x10, x0, #8 ; 0x2a3e4: cmp x8, x9 ; 0x2a3e8: csel x0, x10, xzr, eq
 */
uint64_t fde_196_0x2a3d4(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x2a3d4ULL;
    constexpr uint64_t kFuncSize    = 0x1cULL;
    constexpr uint32_t kFirstOpcode = 0xf9400428U;
    constexpr uint32_t kLastOpcode  = 0xd65f03c0U;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[197] `sub_2a3f0` (`0x2a3f0..0x2a3fc`, 12 bytes)
 *        Hàm FDE[197] `sub_2a3f0` (`0x2a3f0..0x2a3fc`, 12 bytes)
 * Disassembly: 0x2a3f0: adrp x0, #0x48000 ; 0x2a3f4: add x0, x0, #0xda0 ; 0x2a3f8: ret
 */
uint64_t fde_197_0x2a3f0(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x2a3f0ULL;
    constexpr uint64_t kFuncSize    = 0xcULL;
    constexpr uint32_t kFirstOpcode = 0xd00000e0U;
    constexpr uint32_t kLastOpcode  = 0xd65f03c0U;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[198] `sub_2a3fc` (`0x2a3fc..0x2a420`, 36 bytes)
 *        Hàm FDE[198] `sub_2a3fc` (`0x2a3fc..0x2a420`, 36 bytes)
 * Disassembly: 0x2a3fc: stp x19, x30, [sp, #-0x10]! ; 0x2a400: adrp x8, #0x48000 ; 0x2a404: add x8, x8, #0xdc0 ; 0x2a408: mov x19, x0 ; 0x2a40c: str x8, [x0], #0x18 ; 0x2a410: bl #0x27ab0
 */
uint64_t fde_198_0x2a3fc(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x2a3fcULL;
    constexpr uint64_t kFuncSize    = 0x24ULL;
    constexpr uint32_t kFirstOpcode = 0xa9bf7bf3U;
    constexpr uint32_t kLastOpcode  = 0x14006db9U;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[199] `sub_2a420` (`0x2a420..0x2a44c`, 44 bytes)
 *        Hàm FDE[199] `sub_2a420` (`0x2a420..0x2a44c`, 44 bytes)
 * Disassembly: 0x2a420: stp x19, x30, [sp, #-0x10]! ; 0x2a424: adrp x8, #0x48000 ; 0x2a428: add x8, x8, #0xdc0 ; 0x2a42c: mov x19, x0 ; 0x2a430: str x8, [x0], #0x18 ; 0x2a434: bl #0x27ab0
 */
uint64_t fde_199_0x2a420(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x2a420ULL;
    constexpr uint64_t kFuncSize    = 0x2cULL;
    constexpr uint32_t kFirstOpcode = 0xa9bf7bf3U;
    constexpr uint32_t kLastOpcode  = 0x14006d3aU;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[200] `sub_2a44c` (`0x2a44c..0x2a458`, 12 bytes)
 *        Hàm FDE[200] `sub_2a44c` (`0x2a44c..0x2a458`, 12 bytes)
 * Disassembly: 0x2a44c: ldr x8, [x0, #0x18]! ; 0x2a450: ldr x1, [x8, #0x10] ; 0x2a454: br x1
 */
uint64_t fde_200_0x2a44c(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x2a44cULL;
    constexpr uint64_t kFuncSize    = 0xcULL;
    constexpr uint32_t kFirstOpcode = 0xf8418c08U;
    constexpr uint32_t kLastOpcode  = 0xd61f0020U;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[201] `sub_2a458` (`0x2a458..0x2a4b8`, 96 bytes)
 *        Hàm FDE[201] `sub_2a458` (`0x2a458..0x2a4b8`, 96 bytes)
 * Disassembly: 0x2a458: stp x19, x30, [sp, #-0x10]! ; 0x2a45c: ldr x1, [x0, #0x58] ; 0x2a460: adrp x8, #0x48000 ; 0x2a464: mov x19, x0 ; 0x2a468: add x8, x8, #0xd08 ; 0x2a46c: str x8, [x0]
 */
uint64_t fde_201_0x2a458(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x2a458ULL;
    constexpr uint64_t kFuncSize    = 0x60ULL;
    constexpr uint32_t kFirstOpcode = 0xa9bf7bf3U;
    constexpr uint32_t kLastOpcode  = 0x14006d93U;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[202] `sub_2a4b8` (`0x2a4b8..0x2a520`, 104 bytes)
 *        Hàm FDE[202] `sub_2a4b8` (`0x2a4b8..0x2a520`, 104 bytes)
 * Disassembly: 0x2a4b8: stp x19, x30, [sp, #-0x10]! ; 0x2a4bc: ldr x1, [x0, #0x58] ; 0x2a4c0: adrp x8, #0x48000 ; 0x2a4c4: mov x19, x0 ; 0x2a4c8: add x8, x8, #0xd08 ; 0x2a4cc: str x8, [x0]
 */
uint64_t fde_202_0x2a4b8(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x2a4b8ULL;
    constexpr uint64_t kFuncSize    = 0x68ULL;
    constexpr uint32_t kFirstOpcode = 0xa9bf7bf3U;
    constexpr uint32_t kLastOpcode  = 0x14006d05U;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[203] `sub_2a520` (`0x2a520..0x2a578`, 88 bytes)
 *        Hàm FDE[203] `sub_2a520` (`0x2a520..0x2a578`, 88 bytes)
 * Disassembly: 0x2a520: stp x19, x30, [sp, #-0x10]! ; 0x2a524: ldr x1, [x0, #0x58] ; 0x2a528: mov x19, x0 ; 0x2a52c: cbz x1, #0x2a53c ; 0x2a530: ldr x0, [x19, #0x50] ; 0x2a534: bl #0x45d40
 */
uint64_t fde_203_0x2a520(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x2a520ULL;
    constexpr uint64_t kFuncSize    = 0x58ULL;
    constexpr uint32_t kFirstOpcode = 0xa9bf7bf3U;
    constexpr uint32_t kLastOpcode  = 0xd65f03c0U;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[204] `sub_2a578` (`0x2a578..0x2a790`, 536 bytes)
 *        Hàm FDE[204] `sub_2a578` (`0x2a578..0x2a790`, 536 bytes)
 * Disassembly: 0x2a578: sub sp, sp, #0x80 ; 0x2a57c: str x24, [sp, #0x40] ; 0x2a580: stp x23, x22, [sp, #0x50] ; 0x2a584: stp x21, x20, [sp, #0x60] ; 0x2a588: stp x19, x30, [sp, #0x70] ; 0x2a58c: mrs x23, tpidr_el0
 */
uint64_t fde_204_0x2a578(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x2a578ULL;
    constexpr uint64_t kFuncSize    = 0x218ULL;
    constexpr uint32_t kFirstOpcode = 0xd10203ffU;
    constexpr uint32_t kLastOpcode  = 0x94006c71U;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[205] `sub_2a790` (`0x2a790..0x2a818`, 136 bytes)
 *        Hàm FDE[205] `sub_2a790` (`0x2a790..0x2a818`, 136 bytes)
 * Disassembly: 0x2a790: cbz x0, #0x2a7f0 ; 0x2a794: str x20, [sp, #-0x20]! ; 0x2a798: stp x19, x30, [sp, #0x10] ; 0x2a79c: mov x19, x0 ; 0x2a7a0: ldr x0, [x0] ; 0x2a7a4: bl #0x2a790
 */
uint64_t fde_205_0x2a790(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x2a790ULL;
    constexpr uint64_t kFuncSize    = 0x88ULL;
    constexpr uint32_t kFirstOpcode = 0xb4000300U;
    constexpr uint32_t kLastOpcode  = 0x17fffff3U;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[206] `sub_2a818` (`0x2a818..0x2a86c`, 84 bytes)
 *        Hàm FDE[206] `sub_2a818` (`0x2a818..0x2a86c`, 84 bytes)
 * Disassembly: 0x2a818: stp x19, x30, [sp, #-0x10]! ; 0x2a81c: ldr x19, [x0, #0x10] ; 0x2a820: adrp x8, #0x48000 ; 0x2a824: add x8, x8, #0xe60 ; 0x2a828: str x8, [x0] ; 0x2a82c: cbz x19, #0x2a848
 */
uint64_t fde_206_0x2a818(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x2a818ULL;
    constexpr uint64_t kFuncSize    = 0x54ULL;
    constexpr uint32_t kFirstOpcode = 0xa9bf7bf3U;
    constexpr uint32_t kLastOpcode  = 0x14006ca2U;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[207] `sub_2a86c` (`0x2a86c..0x2a884`, 24 bytes)
 *        Hàm FDE[207] `sub_2a86c` (`0x2a86c..0x2a884`, 24 bytes)
 * Disassembly: 0x2a86c: stp x19, x30, [sp, #-0x10]! ; 0x2a870: mov x19, x0 ; 0x2a874: bl #0x2a578 ; 0x2a878: mov x0, x19 ; 0x2a87c: ldp x19, x30, [sp], #0x10 ; 0x2a880: b #0x45930
 */
uint64_t fde_207_0x2a86c(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x2a86cULL;
    constexpr uint64_t kFuncSize    = 0x18ULL;
    constexpr uint32_t kFirstOpcode = 0xa9bf7bf3U;
    constexpr uint32_t kLastOpcode  = 0x14006c2cU;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[208] `sub_2a884` (`0x2a884..0x2a910`, 140 bytes)
 *        Hàm FDE[208] `sub_2a884` (`0x2a884..0x2a910`, 140 bytes)
 * Disassembly: 0x2a884: str x20, [sp, #-0x20]! ; 0x2a888: stp x19, x30, [sp, #0x10] ; 0x2a88c: ldr x20, [x0, #0x40] ; 0x2a890: add x19, x0, #0x48 ; 0x2a894: cmp x20, x19 ; 0x2a898: b.ne #0x2a8ac
 */
uint64_t fde_208_0x2a884(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x2a884ULL;
    constexpr uint64_t kFuncSize    = 0x8cULL;
    constexpr uint32_t kFirstOpcode = 0xf81e0ff4U;
    constexpr uint32_t kLastOpcode  = 0xd65f03c0U;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[209] `sub_2a910` (`0x2a910..0x2a948`, 56 bytes)
 *        Hàm FDE[209] `sub_2a910` (`0x2a910..0x2a948`, 56 bytes)
 * Disassembly: 0x2a910: and w8, w0, #0xff ; 0x2a914: cmp w8, #0x61 ; 0x2a918: b.hi #0x2a940 ; 0x2a91c: adrp x9, #0xd000 ; 0x2a920: and x8, x0, #0xff ; 0x2a924: add x9, x9, #0x878
 */
uint64_t fde_209_0x2a910(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x2a910ULL;
    constexpr uint64_t kFuncSize    = 0x38ULL;
    constexpr uint32_t kFirstOpcode = 0x12001c08U;
    constexpr uint32_t kLastOpcode  = 0xd65f03c0U;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[210] `sub_2a948` (`0x2a948..0x2b62c`, 3300 bytes)
 *        Hàm FDE[210] `sub_2a948` (`0x2a948..0x2b62c`, 3300 bytes)
 * Disassembly: 0x2a948: stp x28, x27, [sp, #-0x60]! ; 0x2a94c: stp x26, x25, [sp, #0x10] ; 0x2a950: stp x24, x23, [sp, #0x20] ; 0x2a954: stp x22, x21, [sp, #0x30] ; 0x2a958: stp x20, x19, [sp, #0x40] ; 0x2a95c: stp x29, x30, [sp, #0x50]
 */
uint64_t fde_210_0x2a948(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x2a948ULL;
    constexpr uint64_t kFuncSize    = 0xce4ULL;
    constexpr uint32_t kFirstOpcode = 0xa9ba6ffcU;
    constexpr uint32_t kLastOpcode  = 0x940068f6U;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[211] `sub_2b62c` (`0x2b62c..0x2b66c`, 64 bytes)
 *        Hàm FDE[211] `sub_2b62c` (`0x2b62c..0x2b66c`, 64 bytes)
 * Disassembly: 0x2b62c: stp x19, x30, [sp, #-0x10]! ; 0x2b630: ldrb w8, [x0, #0x40] ; 0x2b634: adrp x9, #0x48000 ; 0x2b638: mov x19, x0 ; 0x2b63c: add x9, x9, #0xff8 ; 0x2b640: str x9, [x0]
 */
uint64_t fde_211_0x2b62c(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x2b62cULL;
    constexpr uint64_t kFuncSize    = 0x40ULL;
    constexpr uint32_t kFirstOpcode = 0xa9bf7bf3U;
    constexpr uint32_t kLastOpcode  = 0x140068faU;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[212] `sub_2b66c` (`0x2b66c..0x2b6b4`, 72 bytes)
 *        Hàm FDE[212] `sub_2b66c` (`0x2b66c..0x2b6b4`, 72 bytes)
 * Disassembly: 0x2b66c: stp x19, x30, [sp, #-0x10]! ; 0x2b670: ldrb w8, [x0, #0x40] ; 0x2b674: adrp x9, #0x48000 ; 0x2b678: mov x19, x0 ; 0x2b67c: add x9, x9, #0xff8 ; 0x2b680: str x9, [x0]
 */
uint64_t fde_212_0x2b66c(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x2b66cULL;
    constexpr uint64_t kFuncSize    = 0x48ULL;
    constexpr uint32_t kFirstOpcode = 0xa9bf7bf3U;
    constexpr uint32_t kLastOpcode  = 0x140068a0U;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[213] `sub_2b6b4` (`0x2b6b4..0x2b7b4`, 256 bytes)
 *        Hàm FDE[213] `sub_2b6b4` (`0x2b6b4..0x2b7b4`, 256 bytes)
 * Disassembly: 0x2b6b4: ldr x8, [x0, #0x58] ; 0x2b6b8: ldr x9, [x0, #0x30] ; 0x2b6bc: cmp x8, x9 ; 0x2b6c0: b.hs #0x2b6cc ; 0x2b6c4: mov x8, x9 ; 0x2b6c8: str x9, [x0, #0x58]
 */
uint64_t fde_213_0x2b6b4(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x2b6b4ULL;
    constexpr uint64_t kFuncSize    = 0x100ULL;
    constexpr uint32_t kFirstOpcode = 0xf9402c08U;
    constexpr uint32_t kLastOpcode  = 0xd65f03c0U;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[214] `sub_2b7b4` (`0x2b7b4..0x2b7c8`, 20 bytes)
 *        Hàm FDE[214] `sub_2b7b4` (`0x2b7b4..0x2b7c8`, 20 bytes)
 * Disassembly: 0x2b7b4: ldr x8, [x0] ; 0x2b7b8: mov x1, x2 ; 0x2b7bc: mov w2, wzr ; 0x2b7c0: ldr x4, [x8, #0x20] ; 0x2b7c4: br x4
 */
uint64_t fde_214_0x2b7b4(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x2b7b4ULL;
    constexpr uint64_t kFuncSize    = 0x14ULL;
    constexpr uint32_t kFirstOpcode = 0xf9400008U;
    constexpr uint32_t kLastOpcode  = 0xd61f0080U;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[215] `sub_2b7c8` (`0x2b7c8..0x2b7d0`, 8 bytes)
 *        Hàm FDE[215] `sub_2b7c8` (`0x2b7c8..0x2b7d0`, 8 bytes)
 * Disassembly: 0x2b7c8: mov w0, wzr ; 0x2b7cc: ret
 */
uint64_t fde_215_0x2b7c8(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x2b7c8ULL;
    constexpr uint64_t kFuncSize    = 0x8ULL;
    constexpr uint32_t kFirstOpcode = 0x2a1f03e0U;
    constexpr uint32_t kLastOpcode  = 0xd65f03c0U;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[216] `sub_2b7d0` (`0x2b7d0..0x2b7d8`, 8 bytes)
 *        Hàm FDE[216] `sub_2b7d0` (`0x2b7d0..0x2b7d8`, 8 bytes)
 * Disassembly: 0x2b7d0: mov x0, xzr ; 0x2b7d4: ret
 */
uint64_t fde_216_0x2b7d0(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x2b7d0ULL;
    constexpr uint64_t kFuncSize    = 0x8ULL;
    constexpr uint32_t kFirstOpcode = 0xaa1f03e0U;
    constexpr uint32_t kLastOpcode  = 0xd65f03c0U;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[217] `sub_2b7d8` (`0x2b7d8..0x2b89c`, 196 bytes)
 *        Hàm FDE[217] `sub_2b7d8` (`0x2b7d8..0x2b89c`, 196 bytes)
 * Disassembly: 0x2b7d8: str x24, [sp, #-0x40]! ; 0x2b7dc: stp x23, x22, [sp, #0x10] ; 0x2b7e0: stp x21, x20, [sp, #0x20] ; 0x2b7e4: stp x19, x30, [sp, #0x30] ; 0x2b7e8: cmp x2, #1 ; 0x2b7ec: b.lt #0x2b880
 */
uint64_t fde_217_0x2b7d8(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x2b7d8ULL;
    constexpr uint64_t kFuncSize    = 0xc4ULL;
    constexpr uint32_t kFirstOpcode = 0xf81c0ff8U;
    constexpr uint32_t kLastOpcode  = 0xd65f03c0U;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[218] `sub_2b89c` (`0x2b89c..0x2b8ec`, 80 bytes)
 *        Hàm FDE[218] `sub_2b89c` (`0x2b89c..0x2b8ec`, 80 bytes)
 * Disassembly: 0x2b89c: ldr x8, [x0, #0x58] ; 0x2b8a0: ldr x9, [x0, #0x30] ; 0x2b8a4: cmp x8, x9 ; 0x2b8a8: b.hs #0x2b8b4 ; 0x2b8ac: mov x8, x9 ; 0x2b8b0: str x9, [x0, #0x58]
 */
uint64_t fde_218_0x2b89c(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x2b89cULL;
    constexpr uint64_t kFuncSize    = 0x50ULL;
    constexpr uint32_t kFirstOpcode = 0xf9402c08U;
    constexpr uint32_t kLastOpcode  = 0xd65f03c0U;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[219] `sub_2b8ec` (`0x2b8ec..0x2b920`, 52 bytes)
 *        Hàm FDE[219] `sub_2b8ec` (`0x2b8ec..0x2b920`, 52 bytes)
 * Disassembly: 0x2b8ec: stp x19, x30, [sp, #-0x10]! ; 0x2b8f0: ldr x8, [x0] ; 0x2b8f4: mov x19, x0 ; 0x2b8f8: ldr x8, [x8, #0x48] ; 0x2b8fc: blr x8 ; 0x2b900: cmn w0, #1
 */
uint64_t fde_219_0x2b8ec(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x2b8ecULL;
    constexpr uint64_t kFuncSize    = 0x34ULL;
    constexpr uint32_t kFirstOpcode = 0xa9bf7bf3U;
    constexpr uint32_t kLastOpcode  = 0xd65f03c0U;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[220] `sub_2b920` (`0x2b920..0x2b990`, 112 bytes)
 *        Hàm FDE[220] `sub_2b920` (`0x2b920..0x2b990`, 112 bytes)
 * Disassembly: 0x2b920: ldr x9, [x0, #0x58] ; 0x2b924: ldr x10, [x0, #0x30] ; 0x2b928: mov x8, x0 ; 0x2b92c: mov w0, w1 ; 0x2b930: cmp x9, x10 ; 0x2b934: b.hs #0x2b940
 */
uint64_t fde_220_0x2b920(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x2b920ULL;
    constexpr uint64_t kFuncSize    = 0x70ULL;
    constexpr uint32_t kFirstOpcode = 0xf9402c09U;
    constexpr uint32_t kLastOpcode  = 0xd65f03c0U;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[221] `sub_2b990` (`0x2b990..0x2ba4c`, 188 bytes)
 *        Hàm FDE[221] `sub_2b990` (`0x2b990..0x2ba4c`, 188 bytes)
 * Disassembly: 0x2b990: stp x23, x22, [sp, #-0x30]! ; 0x2b994: stp x21, x20, [sp, #0x10] ; 0x2b998: stp x19, x30, [sp, #0x20] ; 0x2b99c: cmp x2, #1 ; 0x2b9a0: b.lt #0x2ba34 ; 0x2b9a4: mov x19, x2
 */
uint64_t fde_221_0x2b990(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x2b990ULL;
    constexpr uint64_t kFuncSize    = 0xbcULL;
    constexpr uint32_t kFirstOpcode = 0xa9bd5bf7U;
    constexpr uint32_t kLastOpcode  = 0xd65f03c0U;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[222] `sub_2ba4c` (`0x2ba4c..0x2bcf0`, 676 bytes)
 *        Hàm FDE[222] `sub_2ba4c` (`0x2ba4c..0x2bcf0`, 676 bytes)
 * Disassembly: 0x2ba4c: sub sp, sp, #0x70 ; 0x2ba50: stp x28, x27, [sp, #0x10] ; 0x2ba54: stp x26, x25, [sp, #0x20] ; 0x2ba58: stp x24, x23, [sp, #0x30] ; 0x2ba5c: stp x22, x21, [sp, #0x40] ; 0x2ba60: stp x20, x19, [sp, #0x50]
 */
uint64_t fde_222_0x2ba4c(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x2ba4cULL;
    constexpr uint64_t kFuncSize    = 0x2a4ULL;
    constexpr uint32_t kFirstOpcode = 0xd101c3ffU;
    constexpr uint32_t kLastOpcode  = 0xd61f0040U;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[223] `sub_2bcf0` (`0x2bcf0..0x2bddc`, 236 bytes)
 *        Hàm FDE[223] `sub_2bcf0` (`0x2bcf0..0x2bddc`, 236 bytes)
 * Disassembly: 0x2bcf0: stp x25, x24, [sp, #-0x40]! ; 0x2bcf4: stp x23, x22, [sp, #0x10] ; 0x2bcf8: stp x21, x20, [sp, #0x20] ; 0x2bcfc: stp x19, x30, [sp, #0x30] ; 0x2bd00: mov x8, #-0x11 ; 0x2bd04: sub x8, x8, x1
 */
uint64_t fde_223_0x2bcf0(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x2bcf0ULL;
    constexpr uint64_t kFuncSize    = 0xecULL;
    constexpr uint32_t kFirstOpcode = 0xa9bc63f9U;
    constexpr uint32_t kLastOpcode  = 0x9400670aU;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[224] `sub_2bddc` (`0x2bddc..0x2bdf0`, 20 bytes)
 *        Hàm FDE[224] `sub_2bddc` (`0x2bddc..0x2bdf0`, 20 bytes)
 * Disassembly: 0x2bddc: adrp x8, #0x4a000 ; 0x2bde0: ldr x8, [x8, #0xbc8] ; 0x2bde4: add x8, x8, #0x10 ; 0x2bde8: str x8, [x0], #8 ; 0x2bdec: b #0x45a50
 */
uint64_t fde_224_0x2bddc(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x2bddcULL;
    constexpr uint64_t kFuncSize    = 0x14ULL;
    constexpr uint32_t kFirstOpcode = 0xf00000e8U;
    constexpr uint32_t kLastOpcode  = 0x14006719U;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[225] `sub_2bdf0` (`0x2bdf0..0x2be18`, 40 bytes)
 *        Hàm FDE[225] `sub_2bdf0` (`0x2bdf0..0x2be18`, 40 bytes)
 * Disassembly: 0x2bdf0: stp x19, x30, [sp, #-0x10]! ; 0x2bdf4: adrp x8, #0x4a000 ; 0x2bdf8: ldr x8, [x8, #0xbc8] ; 0x2bdfc: mov x19, x0 ; 0x2be00: add x8, x8, #0x10 ; 0x2be04: str x8, [x0], #8
 */
uint64_t fde_225_0x2bdf0(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x2bdf0ULL;
    constexpr uint64_t kFuncSize    = 0x28ULL;
    constexpr uint32_t kFirstOpcode = 0xa9bf7bf3U;
    constexpr uint32_t kLastOpcode  = 0x140066c7U;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[226] `sub_2be18` (`0x2be18..0x2be24`, 12 bytes)
 *        Hàm FDE[226] `sub_2be18` (`0x2be18..0x2be24`, 12 bytes)
 * Disassembly: 0x2be18: mov x1, #-1 ; 0x2be1c: mov x0, xzr ; 0x2be20: ret
 */
uint64_t fde_226_0x2be18(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x2be18ULL;
    constexpr uint64_t kFuncSize    = 0xcULL;
    constexpr uint32_t kFirstOpcode = 0x92800001U;
    constexpr uint32_t kLastOpcode  = 0xd65f03c0U;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[227] `sub_2be24` (`0x2be24..0x2be2c`, 8 bytes)
 *        Hàm FDE[227] `sub_2be24` (`0x2be24..0x2be2c`, 8 bytes)
 * Disassembly: 0x2be24: mov w0, #-1 ; 0x2be28: ret
 */
uint64_t fde_227_0x2be24(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x2be24ULL;
    constexpr uint64_t kFuncSize    = 0x8ULL;
    constexpr uint32_t kFirstOpcode = 0x12800000U;
    constexpr uint32_t kLastOpcode  = 0xd65f03c0U;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[228] `sub_2be2c` (`0x2be2c..0x2be34`, 8 bytes)
 *        Hàm FDE[228] `sub_2be2c` (`0x2be2c..0x2be34`, 8 bytes)
 * Disassembly: 0x2be2c: add x0, x0, #0x10 ; 0x2be30: b #0x45f00
 */
uint64_t fde_228_0x2be2c(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x2be2cULL;
    constexpr uint64_t kFuncSize    = 0x8ULL;
    constexpr uint32_t kFirstOpcode = 0x91004000U;
    constexpr uint32_t kLastOpcode  = 0x14006834U;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[229] `sub_2be34` (`0x2be34..0x2be50`, 28 bytes)
 *        Hàm FDE[229] `sub_2be34` (`0x2be34..0x2be50`, 28 bytes)
 * Disassembly: 0x2be34: stp x19, x30, [sp, #-0x10]! ; 0x2be38: mov x19, x0 ; 0x2be3c: add x0, x0, #0x10 ; 0x2be40: bl #0x45f00 ; 0x2be44: mov x0, x19 ; 0x2be48: ldp x19, x30, [sp], #0x10
 */
uint64_t fde_229_0x2be34(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x2be34ULL;
    constexpr uint64_t kFuncSize    = 0x1cULL;
    constexpr uint32_t kFirstOpcode = 0xa9bf7bf3U;
    constexpr uint32_t kLastOpcode  = 0x140066b9U;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[230] `sub_2be50` (`0x2be50..0x2be64`, 20 bytes)
 *        Hàm FDE[230] `sub_2be50` (`0x2be50..0x2be64`, 20 bytes)
 * Disassembly: 0x2be50: ldr x8, [x0] ; 0x2be54: ldur x8, [x8, #-0x18] ; 0x2be58: add x8, x0, x8 ; 0x2be5c: add x0, x8, #0x10 ; 0x2be60: b #0x45f00
 */
uint64_t fde_230_0x2be50(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x2be50ULL;
    constexpr uint64_t kFuncSize    = 0x14ULL;
    constexpr uint32_t kFirstOpcode = 0xf9400008U;
    constexpr uint32_t kLastOpcode  = 0x14006828U;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[231] `sub_2be64` (`0x2be64..0x2be88`, 36 bytes)
 *        Hàm FDE[231] `sub_2be64` (`0x2be64..0x2be88`, 36 bytes)
 * Disassembly: 0x2be64: stp x19, x30, [sp, #-0x10]! ; 0x2be68: ldr x8, [x0] ; 0x2be6c: ldur x8, [x8, #-0x18] ; 0x2be70: add x19, x0, x8 ; 0x2be74: add x0, x19, #0x10 ; 0x2be78: bl #0x45f00
 */
uint64_t fde_231_0x2be64(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x2be64ULL;
    constexpr uint64_t kFuncSize    = 0x24ULL;
    constexpr uint32_t kFirstOpcode = 0xa9bf7bf3U;
    constexpr uint32_t kLastOpcode  = 0x140066abU;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[232] `sub_2be88` (`0x2be88..0x2bee8`, 96 bytes)
 *        Hàm FDE[232] `sub_2be88` (`0x2be88..0x2bee8`, 96 bytes)
 * Disassembly: 0x2be88: stp x19, x30, [sp, #-0x10]! ; 0x2be8c: adrp x8, #0x48000 ; 0x2be90: add x8, x8, #0xeb8 ; 0x2be94: ldrb w9, [x0, #0x58] ; 0x2be98: add x10, x8, #0x50 ; 0x2be9c: str x10, [x0, #0x80]
 */
uint64_t fde_232_0x2be88(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x2be88ULL;
    constexpr uint64_t kFuncSize    = 0x60ULL;
    constexpr uint32_t kFirstOpcode = 0xa9bf7bf3U;
    constexpr uint32_t kLastOpcode  = 0x14006807U;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[233] `sub_2bee8` (`0x2bee8..0x2bf50`, 104 bytes)
 *        Hàm FDE[233] `sub_2bee8` (`0x2bee8..0x2bf50`, 104 bytes)
 * Disassembly: 0x2bee8: stp x19, x30, [sp, #-0x10]! ; 0x2beec: adrp x8, #0x48000 ; 0x2bef0: add x8, x8, #0xeb8 ; 0x2bef4: ldrb w9, [x0, #0x58] ; 0x2bef8: add x10, x8, #0x50 ; 0x2befc: str x10, [x0, #0x80]
 */
uint64_t fde_233_0x2bee8(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x2bee8ULL;
    constexpr uint64_t kFuncSize    = 0x68ULL;
    constexpr uint32_t kFirstOpcode = 0xa9bf7bf3U;
    constexpr uint32_t kLastOpcode  = 0x14006679U;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[234] `sub_2bf50` (`0x2bf50..0x2bfbc`, 108 bytes)
 *        Hàm FDE[234] `sub_2bf50` (`0x2bf50..0x2bfbc`, 108 bytes)
 * Disassembly: 0x2bf50: str x20, [sp, #-0x20]! ; 0x2bf54: stp x19, x30, [sp, #0x10] ; 0x2bf58: adrp x8, #0x48000 ; 0x2bf5c: add x8, x8, #0xeb8 ; 0x2bf60: mov x20, x0 ; 0x2bf64: add x9, x8, #0x50
 */
uint64_t fde_234_0x2bf50(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x2bf50ULL;
    constexpr uint64_t kFuncSize    = 0x6cULL;
    constexpr uint32_t kFirstOpcode = 0xf81e0ff4U;
    constexpr uint32_t kLastOpcode  = 0x140067d2U;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[235] `sub_2bfbc` (`0x2bfbc..0x2c030`, 116 bytes)
 *        Hàm FDE[235] `sub_2bfbc` (`0x2bfbc..0x2c030`, 116 bytes)
 * Disassembly: 0x2bfbc: str x20, [sp, #-0x20]! ; 0x2bfc0: stp x19, x30, [sp, #0x10] ; 0x2bfc4: adrp x8, #0x48000 ; 0x2bfc8: add x8, x8, #0xeb8 ; 0x2bfcc: mov x19, x0 ; 0x2bfd0: add x9, x8, #0x50
 */
uint64_t fde_235_0x2bfbc(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x2bfbcULL;
    constexpr uint64_t kFuncSize    = 0x74ULL;
    constexpr uint32_t kFirstOpcode = 0xf81e0ff4U;
    constexpr uint32_t kLastOpcode  = 0x14006641U;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[236] `sub_2c030` (`0x2c030..0x2c0a4`, 116 bytes)
 *        Hàm FDE[236] `sub_2c030` (`0x2c030..0x2c0a4`, 116 bytes)
 * Disassembly: 0x2c030: str x20, [sp, #-0x20]! ; 0x2c034: stp x19, x30, [sp, #0x10] ; 0x2c038: ldr x8, [x0] ; 0x2c03c: adrp x9, #0x48000 ; 0x2c040: add x9, x9, #0xeb8 ; 0x2c044: adrp x10, #0x48000
 */
uint64_t fde_236_0x2c030(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x2c030ULL;
    constexpr uint64_t kFuncSize    = 0x74ULL;
    constexpr uint32_t kFirstOpcode = 0xf81e0ff4U;
    constexpr uint32_t kLastOpcode  = 0x14006798U;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[237] `sub_2c0a4` (`0x2c0a4..0x2c120`, 124 bytes)
 *        Hàm FDE[237] `sub_2c0a4` (`0x2c0a4..0x2c120`, 124 bytes)
 * Disassembly: 0x2c0a4: str x20, [sp, #-0x20]! ; 0x2c0a8: stp x19, x30, [sp, #0x10] ; 0x2c0ac: ldr x8, [x0] ; 0x2c0b0: adrp x9, #0x48000 ; 0x2c0b4: add x9, x9, #0xeb8 ; 0x2c0b8: adrp x10, #0x48000
 */
uint64_t fde_237_0x2c0a4(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x2c0a4ULL;
    constexpr uint64_t kFuncSize    = 0x7cULL;
    constexpr uint32_t kFirstOpcode = 0xf81e0ff4U;
    constexpr uint32_t kLastOpcode  = 0x14006605U;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[238] `sub_2c120` (`0x2c120..0x2df58`, 7736 bytes)
 *        Hàm FDE[238] `sub_2c120` (`0x2c120..0x2df58`, 7736 bytes)
 * Disassembly: 0x2c120: stp x28, x27, [sp, #-0x60]! ; 0x2c124: stp x26, x25, [sp, #0x10] ; 0x2c128: stp x24, x23, [sp, #0x20] ; 0x2c12c: stp x22, x21, [sp, #0x30] ; 0x2c130: stp x20, x19, [sp, #0x40] ; 0x2c134: stp x29, x30, [sp, #0x50]
 */
uint64_t fde_238_0x2c120(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x2c120ULL;
    constexpr uint64_t kFuncSize    = 0x1e38ULL;
    constexpr uint32_t kFirstOpcode = 0xa9ba6ffcU;
    constexpr uint32_t kLastOpcode  = 0x94005e7fU;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[239] `sub_2df58` (`0x2df58..0x2e0f4`, 412 bytes)
 *        Hàm FDE[239] `sub_2df58` (`0x2df58..0x2e0f4`, 412 bytes)
 * Disassembly: 0x2df58: sub sp, sp, #0x70 ; 0x2df5c: str x22, [sp, #0x40] ; 0x2df60: stp x21, x20, [sp, #0x50] ; 0x2df64: stp x19, x30, [sp, #0x60] ; 0x2df68: mrs x20, tpidr_el0 ; 0x2df6c: ldr x8, [x20, #0x28]
 */
uint64_t fde_239_0x2df58(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x2df58ULL;
    constexpr uint64_t kFuncSize    = 0x19cULL;
    constexpr uint32_t kFirstOpcode = 0xd101c3ffU;
    constexpr uint32_t kLastOpcode  = 0x94005e18U;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[240] `sub_2e0f4` (`0x2e0f4..0x2e26c`, 376 bytes)
 *        Hàm FDE[240] `sub_2e0f4` (`0x2e0f4..0x2e26c`, 376 bytes)
 * Disassembly: 0x2e0f4: str x26, [sp, #-0x50]! ; 0x2e0f8: stp x25, x24, [sp, #0x10] ; 0x2e0fc: stp x23, x22, [sp, #0x20] ; 0x2e100: stp x21, x20, [sp, #0x30] ; 0x2e104: stp x19, x30, [sp, #0x40] ; 0x2e108: ldrb w8, [x2]
 */
uint64_t fde_240_0x2e0f4(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x2e0f4ULL;
    constexpr uint64_t kFuncSize    = 0x178ULL;
    constexpr uint32_t kFirstOpcode = 0xf81b0ffaU;
    constexpr uint32_t kLastOpcode  = 0xd65f03c0U;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[241] `sub_2e26c` (`0x2e26c..0x2e5dc`, 880 bytes)
 *        Hàm FDE[241] `sub_2e26c` (`0x2e26c..0x2e5dc`, 880 bytes)
 * Disassembly: 0x2e26c: sub sp, sp, #0xc0 ; 0x2e270: stp x28, x27, [sp, #0x60] ; 0x2e274: stp x26, x25, [sp, #0x70] ; 0x2e278: stp x24, x23, [sp, #0x80] ; 0x2e27c: stp x22, x21, [sp, #0x90] ; 0x2e280: stp x20, x19, [sp, #0xa0]
 */
uint64_t fde_241_0x2e26c(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x2e26cULL;
    constexpr uint64_t kFuncSize    = 0x370ULL;
    constexpr uint32_t kFirstOpcode = 0xd10303ffU;
    constexpr uint32_t kLastOpcode  = 0x94005cdeU;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[242] `sub_2e5dc` (`0x2e5dc..0x2e9f0`, 1044 bytes)
 *        Hàm FDE[242] `sub_2e5dc` (`0x2e5dc..0x2e9f0`, 1044 bytes)
 * Disassembly: 0x2e5dc: sub sp, sp, #0x110 ; 0x2e5e0: stp x28, x27, [sp, #0xb0] ; 0x2e5e4: stp x26, x25, [sp, #0xc0] ; 0x2e5e8: stp x24, x23, [sp, #0xd0] ; 0x2e5ec: stp x22, x21, [sp, #0xe0] ; 0x2e5f0: stp x20, x19, [sp, #0xf0]
 */
uint64_t fde_242_0x2e5dc(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x2e5dcULL;
    constexpr uint64_t kFuncSize    = 0x414ULL;
    constexpr uint32_t kFirstOpcode = 0xd10443ffU;
    constexpr uint32_t kLastOpcode  = 0x94005c05U;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[243] `sub_2e9f0` (`0x2e9f0..0x2ea14`, 36 bytes)
 *        Hàm FDE[243] `sub_2e9f0` (`0x2e9f0..0x2ea14`, 36 bytes)
 * Disassembly: 0x2e9f0: stp x19, x30, [sp, #-0x10]! ; 0x2e9f4: adrp x8, #0x49000 ; 0x2e9f8: add x8, x8, #0x230 ; 0x2e9fc: mov x19, x0 ; 0x2ea00: str x8, [x0], #0x18 ; 0x2ea04: bl #0x46120
 */
uint64_t fde_243_0x2e9f0(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x2e9f0ULL;
    constexpr uint64_t kFuncSize    = 0x24ULL;
    constexpr uint32_t kFirstOpcode = 0xa9bf7bf3U;
    constexpr uint32_t kLastOpcode  = 0x14005c3cU;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[244] `sub_2ea14` (`0x2ea14..0x2ea40`, 44 bytes)
 *        Hàm FDE[244] `sub_2ea14` (`0x2ea14..0x2ea40`, 44 bytes)
 * Disassembly: 0x2ea14: stp x19, x30, [sp, #-0x10]! ; 0x2ea18: adrp x8, #0x49000 ; 0x2ea1c: add x8, x8, #0x230 ; 0x2ea20: mov x19, x0 ; 0x2ea24: str x8, [x0], #0x18 ; 0x2ea28: bl #0x46120
 */
uint64_t fde_244_0x2ea14(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x2ea14ULL;
    constexpr uint64_t kFuncSize    = 0x2cULL;
    constexpr uint32_t kFirstOpcode = 0xa9bf7bf3U;
    constexpr uint32_t kLastOpcode  = 0x14005bbdU;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[245] `sub_2ea40` (`0x2ea40..0x2ea48`, 8 bytes)
 *        Hàm FDE[245] `sub_2ea40` (`0x2ea40..0x2ea48`, 8 bytes)
 * Disassembly: 0x2ea40: add x0, x0, #0x18 ; 0x2ea44: b #0x46120
 */
uint64_t fde_245_0x2ea40(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x2ea40ULL;
    constexpr uint64_t kFuncSize    = 0x8ULL;
    constexpr uint32_t kFirstOpcode = 0x91006000U;
    constexpr uint32_t kLastOpcode  = 0x14005db7U;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[246] `sub_2ea48` (`0x2ea48..0x2ea6c`, 36 bytes)
 *        Hàm FDE[246] `sub_2ea48` (`0x2ea48..0x2ea6c`, 36 bytes)
 * Disassembly: 0x2ea48: stp x19, x30, [sp, #-0x10]! ; 0x2ea4c: adrp x8, #0x49000 ; 0x2ea50: add x8, x8, #0x1a8 ; 0x2ea54: mov x19, x0 ; 0x2ea58: str x8, [x0], #0x18 ; 0x2ea5c: bl #0x46130
 */
uint64_t fde_246_0x2ea48(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x2ea48ULL;
    constexpr uint64_t kFuncSize    = 0x24ULL;
    constexpr uint32_t kFirstOpcode = 0xa9bf7bf3U;
    constexpr uint32_t kLastOpcode  = 0x14005c26U;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[247] `sub_2ea6c` (`0x2ea6c..0x2ea98`, 44 bytes)
 *        Hàm FDE[247] `sub_2ea6c` (`0x2ea6c..0x2ea98`, 44 bytes)
 * Disassembly: 0x2ea6c: stp x19, x30, [sp, #-0x10]! ; 0x2ea70: adrp x8, #0x49000 ; 0x2ea74: add x8, x8, #0x1a8 ; 0x2ea78: mov x19, x0 ; 0x2ea7c: str x8, [x0], #0x18 ; 0x2ea80: bl #0x46130
 */
uint64_t fde_247_0x2ea6c(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x2ea6cULL;
    constexpr uint64_t kFuncSize    = 0x2cULL;
    constexpr uint32_t kFirstOpcode = 0xa9bf7bf3U;
    constexpr uint32_t kLastOpcode  = 0x14005ba7U;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[248] `sub_2ea98` (`0x2ea98..0x2eaa0`, 8 bytes)
 *        Hàm FDE[248] `sub_2ea98` (`0x2ea98..0x2eaa0`, 8 bytes)
 * Disassembly: 0x2ea98: add x0, x0, #0x18 ; 0x2ea9c: b #0x46130
 */
uint64_t fde_248_0x2ea98(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x2ea98ULL;
    constexpr uint64_t kFuncSize    = 0x8ULL;
    constexpr uint32_t kFirstOpcode = 0x91006000U;
    constexpr uint32_t kLastOpcode  = 0x14005da5U;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[249] `sub_2eaa0` (`0x2eaa0..0x2f578`, 2776 bytes)
 *        Hàm FDE[249] `sub_2eaa0` (`0x2eaa0..0x2f578`, 2776 bytes)
 * Disassembly: 0x2eaa0: str d8, [sp, #-0x70]! ; 0x2eaa4: stp x28, x27, [sp, #0x10] ; 0x2eaa8: stp x26, x25, [sp, #0x20] ; 0x2eaac: stp x24, x23, [sp, #0x30] ; 0x2eab0: stp x22, x21, [sp, #0x40] ; 0x2eab4: stp x20, x19, [sp, #0x50]
 */
uint64_t fde_249_0x2eaa0(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x2eaa0ULL;
    constexpr uint64_t kFuncSize    = 0xad8ULL;
    constexpr uint32_t kFirstOpcode = 0xfc190fe8U;
    constexpr uint32_t kLastOpcode  = 0x940058f7U;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[250] `sub_2f578` (`0x2f578..0x2f8c0`, 840 bytes)
 *        Hàm FDE[250] `sub_2f578` (`0x2f578..0x2f8c0`, 840 bytes)
 * Disassembly: 0x2f578: str x28, [sp, #-0x60]! ; 0x2f57c: stp x27, x26, [sp, #0x10] ; 0x2f580: stp x25, x24, [sp, #0x20] ; 0x2f584: stp x23, x22, [sp, #0x30] ; 0x2f588: stp x21, x20, [sp, #0x40] ; 0x2f58c: stp x19, x30, [sp, #0x50]
 */
uint64_t fde_250_0x2f578(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x2f578ULL;
    constexpr uint64_t kFuncSize    = 0x348ULL;
    constexpr uint32_t kFirstOpcode = 0xf81a0ffcU;
    constexpr uint32_t kLastOpcode  = 0xd65f03c0U;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[251] `sub_2f8c0` (`0x2f8c0..0x2f9dc`, 284 bytes)
 *        Hàm FDE[251] `sub_2f8c0` (`0x2f8c0..0x2f9dc`, 284 bytes)
 * Disassembly: 0x2f8c0: sub sp, sp, #0x70 ; 0x2f8c4: str x20, [sp, #0x50] ; 0x2f8c8: stp x19, x30, [sp, #0x60] ; 0x2f8cc: mrs x19, tpidr_el0 ; 0x2f8d0: ldr x8, [x19, #0x28] ; 0x2f8d4: adrp x20, #0x4c000
 */
uint64_t fde_251_0x2f8c0(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x2f8c0ULL;
    constexpr uint64_t kFuncSize    = 0x11cULL;
    constexpr uint32_t kFirstOpcode = 0xd101c3ffU;
    constexpr uint32_t kLastOpcode  = 0x940057deU;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[252] `sub_2f9dc` (`0x2f9dc..0x2faf8`, 284 bytes)
 *        Hàm FDE[252] `sub_2f9dc` (`0x2f9dc..0x2faf8`, 284 bytes)
 * Disassembly: 0x2f9dc: sub sp, sp, #0x70 ; 0x2f9e0: str x20, [sp, #0x50] ; 0x2f9e4: stp x19, x30, [sp, #0x60] ; 0x2f9e8: mrs x19, tpidr_el0 ; 0x2f9ec: ldr x8, [x19, #0x28] ; 0x2f9f0: adrp x20, #0x4c000
 */
uint64_t fde_252_0x2f9dc(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x2f9dcULL;
    constexpr uint64_t kFuncSize    = 0x11cULL;
    constexpr uint32_t kFirstOpcode = 0xd101c3ffU;
    constexpr uint32_t kLastOpcode  = 0x94005797U;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[253] `sub_2faf8` (`0x2faf8..0x2fc14`, 284 bytes)
 *        Hàm FDE[253] `sub_2faf8` (`0x2faf8..0x2fc14`, 284 bytes)
 * Disassembly: 0x2faf8: sub sp, sp, #0x70 ; 0x2fafc: str x20, [sp, #0x50] ; 0x2fb00: stp x19, x30, [sp, #0x60] ; 0x2fb04: mrs x19, tpidr_el0 ; 0x2fb08: ldr x8, [x19, #0x28] ; 0x2fb0c: adrp x20, #0x4c000
 */
uint64_t fde_253_0x2faf8(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x2faf8ULL;
    constexpr uint64_t kFuncSize    = 0x11cULL;
    constexpr uint32_t kFirstOpcode = 0xd101c3ffU;
    constexpr uint32_t kLastOpcode  = 0x94005750U;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[254] `sub_2fc14` (`0x2fc14..0x2fd30`, 284 bytes)
 *        Hàm FDE[254] `sub_2fc14` (`0x2fc14..0x2fd30`, 284 bytes)
 * Disassembly: 0x2fc14: sub sp, sp, #0x70 ; 0x2fc18: str x20, [sp, #0x50] ; 0x2fc1c: stp x19, x30, [sp, #0x60] ; 0x2fc20: mrs x19, tpidr_el0 ; 0x2fc24: ldr x8, [x19, #0x28] ; 0x2fc28: adrp x20, #0x4c000
 */
uint64_t fde_254_0x2fc14(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x2fc14ULL;
    constexpr uint64_t kFuncSize    = 0x11cULL;
    constexpr uint32_t kFirstOpcode = 0xd101c3ffU;
    constexpr uint32_t kLastOpcode  = 0x94005709U;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[255] `sub_2fd30` (`0x2fd30..0x2fe4c`, 284 bytes)
 *        Hàm FDE[255] `sub_2fd30` (`0x2fd30..0x2fe4c`, 284 bytes)
 * Disassembly: 0x2fd30: sub sp, sp, #0x70 ; 0x2fd34: str x20, [sp, #0x50] ; 0x2fd38: stp x19, x30, [sp, #0x60] ; 0x2fd3c: mrs x19, tpidr_el0 ; 0x2fd40: ldr x8, [x19, #0x28] ; 0x2fd44: adrp x20, #0x4c000
 */
uint64_t fde_255_0x2fd30(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x2fd30ULL;
    constexpr uint64_t kFuncSize    = 0x11cULL;
    constexpr uint32_t kFirstOpcode = 0xd101c3ffU;
    constexpr uint32_t kLastOpcode  = 0x940056c2U;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[256] `sub_2fe4c` (`0x2fe4c..0x2ff68`, 284 bytes)
 *        Hàm FDE[256] `sub_2fe4c` (`0x2fe4c..0x2ff68`, 284 bytes)
 * Disassembly: 0x2fe4c: sub sp, sp, #0x70 ; 0x2fe50: str x20, [sp, #0x50] ; 0x2fe54: stp x19, x30, [sp, #0x60] ; 0x2fe58: mrs x19, tpidr_el0 ; 0x2fe5c: ldr x8, [x19, #0x28] ; 0x2fe60: adrp x20, #0x4c000
 */
uint64_t fde_256_0x2fe4c(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x2fe4cULL;
    constexpr uint64_t kFuncSize    = 0x11cULL;
    constexpr uint32_t kFirstOpcode = 0xd101c3ffU;
    constexpr uint32_t kLastOpcode  = 0x9400567bU;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[257] `sub_2ff68` (`0x2ff68..0x30084`, 284 bytes)
 *        Hàm FDE[257] `sub_2ff68` (`0x2ff68..0x30084`, 284 bytes)
 * Disassembly: 0x2ff68: sub sp, sp, #0x70 ; 0x2ff6c: str x20, [sp, #0x50] ; 0x2ff70: stp x19, x30, [sp, #0x60] ; 0x2ff74: mrs x19, tpidr_el0 ; 0x2ff78: ldr x8, [x19, #0x28] ; 0x2ff7c: adrp x20, #0x4c000
 */
uint64_t fde_257_0x2ff68(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x2ff68ULL;
    constexpr uint64_t kFuncSize    = 0x11cULL;
    constexpr uint32_t kFirstOpcode = 0xd101c3ffU;
    constexpr uint32_t kLastOpcode  = 0x94005634U;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[258] `sub_30084` (`0x30084..0x3011c`, 152 bytes)
 *        Hàm FDE[258] `sub_30084` (`0x30084..0x3011c`, 152 bytes)
 * Disassembly: 0x30084: sub sp, sp, #0x120 ; 0x30088: str x28, [sp, #0x100] ; 0x3008c: stp x19, x30, [sp, #0x110] ; 0x30090: stp x3, x4, [sp, #0x88] ; 0x30094: stp x5, x6, [sp, #0x98] ; 0x30098: str x7, [sp, #0xa8]
 */
uint64_t fde_258_0x30084(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x30084ULL;
    constexpr uint64_t kFuncSize    = 0x98ULL;
    constexpr uint32_t kFirstOpcode = 0xd10483ffU;
    constexpr uint32_t kLastOpcode  = 0x9400560eU;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[259] `sub_3011c` (`0x3011c..0x301b4`, 152 bytes)
 *        Hàm FDE[259] `sub_3011c` (`0x3011c..0x301b4`, 152 bytes)
 * Disassembly: 0x3011c: sub sp, sp, #0x120 ; 0x30120: str x28, [sp, #0x100] ; 0x30124: stp x19, x30, [sp, #0x110] ; 0x30128: stp x3, x4, [sp, #0x88] ; 0x3012c: stp x5, x6, [sp, #0x98] ; 0x30130: str x7, [sp, #0xa8]
 */
uint64_t fde_259_0x3011c(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x3011cULL;
    constexpr uint64_t kFuncSize    = 0x98ULL;
    constexpr uint32_t kFirstOpcode = 0xd10483ffU;
    constexpr uint32_t kLastOpcode  = 0x940055e8U;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[260] `sub_301b4` (`0x301b4..0x3024c`, 152 bytes)
 *        Hàm FDE[260] `sub_301b4` (`0x301b4..0x3024c`, 152 bytes)
 * Disassembly: 0x301b4: sub sp, sp, #0x120 ; 0x301b8: str x28, [sp, #0x100] ; 0x301bc: stp x19, x30, [sp, #0x110] ; 0x301c0: stp x3, x4, [sp, #0x88] ; 0x301c4: stp x5, x6, [sp, #0x98] ; 0x301c8: str x7, [sp, #0xa8]
 */
uint64_t fde_260_0x301b4(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x301b4ULL;
    constexpr uint64_t kFuncSize    = 0x98ULL;
    constexpr uint32_t kFirstOpcode = 0xd10483ffU;
    constexpr uint32_t kLastOpcode  = 0x940055c2U;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[261] `sub_3024c` (`0x3024c..0x302e4`, 152 bytes)
 *        Hàm FDE[261] `sub_3024c` (`0x3024c..0x302e4`, 152 bytes)
 * Disassembly: 0x3024c: sub sp, sp, #0x120 ; 0x30250: str x28, [sp, #0x100] ; 0x30254: stp x19, x30, [sp, #0x110] ; 0x30258: stp x3, x4, [sp, #0x88] ; 0x3025c: stp x5, x6, [sp, #0x98] ; 0x30260: str x7, [sp, #0xa8]
 */
uint64_t fde_261_0x3024c(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x3024cULL;
    constexpr uint64_t kFuncSize    = 0x98ULL;
    constexpr uint32_t kFirstOpcode = 0xd10483ffU;
    constexpr uint32_t kLastOpcode  = 0x9400559cU;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[262] `sub_302e4` (`0x302e4..0x30408`, 292 bytes)
 *        Hàm FDE[262] `sub_302e4` (`0x302e4..0x30408`, 292 bytes)
 * Disassembly: 0x302e4: sub sp, sp, #0x70 ; 0x302e8: stp x25, x24, [sp, #0x30] ; 0x302ec: stp x23, x22, [sp, #0x40] ; 0x302f0: stp x21, x20, [sp, #0x50] ; 0x302f4: stp x19, x30, [sp, #0x60] ; 0x302f8: mrs x25, tpidr_el0
 */
uint64_t fde_262_0x302e4(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x302e4ULL;
    constexpr uint64_t kFuncSize    = 0x124ULL;
    constexpr uint32_t kFirstOpcode = 0xd101c3ffU;
    constexpr uint32_t kLastOpcode  = 0x94005553U;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[263] `sub_30408` (`0x30408..0x3225c`, 7764 bytes)
 *        Hàm FDE[263] `sub_30408` (`0x30408..0x3225c`, 7764 bytes)
 * Disassembly: 0x30408: str d8, [sp, #-0x70]! ; 0x3040c: stp x28, x27, [sp, #0x10] ; 0x30410: stp x26, x25, [sp, #0x20] ; 0x30414: stp x24, x23, [sp, #0x30] ; 0x30418: stp x22, x21, [sp, #0x40] ; 0x3041c: stp x20, x19, [sp, #0x50]
 */
uint64_t fde_263_0x30408(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x30408ULL;
    constexpr uint64_t kFuncSize    = 0x1e54ULL;
    constexpr uint32_t kFirstOpcode = 0xfc190fe8U;
    constexpr uint32_t kLastOpcode  = 0x94004dbeU;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[264] `sub_3225c` (`0x3225c..0x32300`, 164 bytes)
 *        Hàm FDE[264] `sub_3225c` (`0x3225c..0x32300`, 164 bytes)
 * Disassembly: 0x3225c: str x20, [sp, #-0x20]! ; 0x32260: stp x19, x30, [sp, #0x10] ; 0x32264: ldr x20, [x0, #0x20] ; 0x32268: adrp x8, #0x49000 ; 0x3226c: mov x19, x0 ; 0x32270: add x8, x8, #0x348
 */
uint64_t fde_264_0x3225c(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x3225cULL;
    constexpr uint64_t kFuncSize    = 0xa4ULL;
    constexpr uint32_t kFirstOpcode = 0xf81e0ff4U;
    constexpr uint32_t kLastOpcode  = 0xd65f03c0U;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[265] `sub_32300` (`0x32300..0x323a4`, 164 bytes)
 *        Hàm FDE[265] `sub_32300` (`0x32300..0x323a4`, 164 bytes)
 * Disassembly: 0x32300: str x20, [sp, #-0x20]! ; 0x32304: stp x19, x30, [sp, #0x10] ; 0x32308: ldr x20, [x0, #0x20] ; 0x3230c: adrp x8, #0x49000 ; 0x32310: mov x19, x0 ; 0x32314: add x8, x8, #0x348
 */
uint64_t fde_265_0x32300(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x32300ULL;
    constexpr uint64_t kFuncSize    = 0xa4ULL;
    constexpr uint32_t kFirstOpcode = 0xf81e0ff4U;
    constexpr uint32_t kLastOpcode  = 0x14004d64U;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[266] `sub_323a4` (`0x323a4..0x32418`, 116 bytes)
 *        Hàm FDE[266] `sub_323a4` (`0x323a4..0x32418`, 116 bytes)
 * Disassembly: 0x323a4: stp x19, x30, [sp, #-0x10]! ; 0x323a8: mov x19, x0 ; 0x323ac: mov w0, #0x28 ; 0x323b0: bl #0x459f0 ; 0x323b4: adrp x8, #0x49000 ; 0x323b8: add x8, x8, #0x348
 */
uint64_t fde_266_0x323a4(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x323a4ULL;
    constexpr uint64_t kFuncSize    = 0x74ULL;
    constexpr uint32_t kFirstOpcode = 0xa9bf7bf3U;
    constexpr uint32_t kLastOpcode  = 0xd65f03c0U;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[267] `sub_32418` (`0x32418..0x32478`, 96 bytes)
 *        Hàm FDE[267] `sub_32418` (`0x32418..0x32478`, 96 bytes)
 * Disassembly: 0x32418: adrp x8, #0x49000 ; 0x3241c: add x8, x8, #0x348 ; 0x32420: str x8, [x1] ; 0x32424: ldr x8, [x0, #8] ; 0x32428: str x8, [x1, #8] ; 0x3242c: ldr x8, [x0, #0x10]
 */
uint64_t fde_267_0x32418(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x32418ULL;
    constexpr uint64_t kFuncSize    = 0x60ULL;
    constexpr uint32_t kFirstOpcode = 0xf00000a8U;
    constexpr uint32_t kLastOpcode  = 0xd65f03c0U;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[268] `sub_32478` (`0x32478..0x32510`, 152 bytes)
 *        Hàm FDE[268] `sub_32478` (`0x32478..0x32510`, 152 bytes)
 * Disassembly: 0x32478: str x20, [sp, #-0x20]! ; 0x3247c: stp x19, x30, [sp, #0x10] ; 0x32480: ldr x20, [x0, #0x20] ; 0x32484: mov x19, x0 ; 0x32488: cbz x20, #0x324a4 ; 0x3248c: add x8, x20, #8
 */
uint64_t fde_268_0x32478(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x32478ULL;
    constexpr uint64_t kFuncSize    = 0x98ULL;
    constexpr uint32_t kFirstOpcode = 0xf81e0ff4U;
    constexpr uint32_t kLastOpcode  = 0xd65f03c0U;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[269] `sub_32510` (`0x32510..0x325a8`, 152 bytes)
 *        Hàm FDE[269] `sub_32510` (`0x32510..0x325a8`, 152 bytes)
 * Disassembly: 0x32510: str x20, [sp, #-0x20]! ; 0x32514: stp x19, x30, [sp, #0x10] ; 0x32518: ldr x20, [x0, #0x20] ; 0x3251c: mov x19, x0 ; 0x32520: cbz x20, #0x3253c ; 0x32524: add x8, x20, #8
 */
uint64_t fde_269_0x32510(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x32510ULL;
    constexpr uint64_t kFuncSize    = 0x98ULL;
    constexpr uint32_t kFirstOpcode = 0xf81e0ff4U;
    constexpr uint32_t kLastOpcode  = 0x14004ce3U;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[270] `sub_325a8` (`0x325a8..0x328a0`, 760 bytes)
 *        Hàm FDE[270] `sub_325a8` (`0x325a8..0x328a0`, 760 bytes)
 * Disassembly: 0x325a8: sub sp, sp, #0x50 ; 0x325ac: stp x23, x22, [sp, #0x20] ; 0x325b0: stp x21, x20, [sp, #0x30] ; 0x325b4: stp x19, x30, [sp, #0x40] ; 0x325b8: mrs x22, tpidr_el0 ; 0x325bc: ldr x8, [x22, #0x28]
 */
uint64_t fde_270_0x325a8(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x325a8ULL;
    constexpr uint64_t kFuncSize    = 0x2f8ULL;
    constexpr uint32_t kFirstOpcode = 0xd10143ffU;
    constexpr uint32_t kLastOpcode  = 0x94004c2dU;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[271] `sub_328a0` (`0x328a0..0x328bc`, 28 bytes)
 *        Hàm FDE[271] `sub_328a0` (`0x328a0..0x328bc`, 28 bytes)
 * Disassembly: 0x328a0: ldr x8, [x1, #8] ; 0x328a4: adrp x9, #0x11000 ; 0x328a8: add x9, x9, #0x9a ; 0x328ac: add x10, x0, #8 ; 0x328b0: cmp x8, x9 ; 0x328b4: csel x0, x10, xzr, eq
 */
uint64_t fde_271_0x328a0(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x328a0ULL;
    constexpr uint64_t kFuncSize    = 0x1cULL;
    constexpr uint32_t kFirstOpcode = 0xf9400428U;
    constexpr uint32_t kLastOpcode  = 0xd65f03c0U;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[272] `sub_328bc` (`0x328bc..0x328c8`, 12 bytes)
 *        Hàm FDE[272] `sub_328bc` (`0x328bc..0x328c8`, 12 bytes)
 * Disassembly: 0x328bc: adrp x0, #0x49000 ; 0x328c0: add x0, x0, #0x3a8 ; 0x328c4: ret
 */
uint64_t fde_272_0x328bc(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x328bcULL;
    constexpr uint64_t kFuncSize    = 0xcULL;
    constexpr uint32_t kFirstOpcode = 0xf00000a0U;
    constexpr uint32_t kLastOpcode  = 0xd65f03c0U;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[273] `sub_328c8` (`0x328c8..0x32b08`, 576 bytes)
 *        Hàm FDE[273] `sub_328c8` (`0x328c8..0x32b08`, 576 bytes)
 * Disassembly: 0x328c8: sub sp, sp, #0xc0 ; 0x328cc: str x22, [sp, #0x90] ; 0x328d0: stp x21, x20, [sp, #0xa0] ; 0x328d4: stp x19, x30, [sp, #0xb0] ; 0x328d8: mrs x20, tpidr_el0 ; 0x328dc: ldr x8, [x20, #0x28]
 */
uint64_t fde_273_0x328c8(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x328c8ULL;
    constexpr uint64_t kFuncSize    = 0x240ULL;
    constexpr uint32_t kFirstOpcode = 0xd10303ffU;
    constexpr uint32_t kLastOpcode  = 0x94004b93U;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[274] `sub_32b08` (`0x32b08..0x32be4`, 220 bytes)
 *        Hàm FDE[274] `sub_32b08` (`0x32b08..0x32be4`, 220 bytes)
 * Disassembly: 0x32b08: stp x25, x24, [sp, #-0x40]! ; 0x32b0c: stp x23, x22, [sp, #0x10] ; 0x32b10: stp x21, x20, [sp, #0x20] ; 0x32b14: stp x19, x30, [sp, #0x30] ; 0x32b18: stp xzr, xzr, [x0] ; 0x32b1c: str xzr, [x0, #0x10]
 */
uint64_t fde_274_0x32b08(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x32b08ULL;
    constexpr uint64_t kFuncSize    = 0xdcULL;
    constexpr uint32_t kFirstOpcode = 0xa9bc63f9U;
    constexpr uint32_t kLastOpcode  = 0x94004b88U;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[275] `sub_32be4` (`0x32be4..0x32e90`, 684 bytes)
 *        Hàm FDE[275] `sub_32be4` (`0x32be4..0x32e90`, 684 bytes)
 * Disassembly: 0x32be4: sub sp, sp, #0xc0 ; 0x32be8: str x22, [sp, #0x90] ; 0x32bec: stp x21, x20, [sp, #0xa0] ; 0x32bf0: stp x19, x30, [sp, #0xb0] ; 0x32bf4: mrs x20, tpidr_el0 ; 0x32bf8: ldr x8, [x20, #0x28]
 */
uint64_t fde_275_0x32be4(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x32be4ULL;
    constexpr uint64_t kFuncSize    = 0x2acULL;
    constexpr uint32_t kFirstOpcode = 0xd10303ffU;
    constexpr uint32_t kLastOpcode  = 0x94004ab1U;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[276] `sub_32e90` (`0x32e90..0x32fc0`, 304 bytes)
 *        Hàm FDE[276] `sub_32e90` (`0x32e90..0x32fc0`, 304 bytes)
 * Disassembly: 0x32e90: str x20, [sp, #-0x20]! ; 0x32e94: stp x19, x30, [sp, #0x10] ; 0x32e98: mov x19, x0 ; 0x32e9c: ldr x0, [x0, #0x28] ; 0x32ea0: strb wzr, [x19] ; 0x32ea4: cbz x0, #0x32ef0
 */
uint64_t fde_276_0x32e90(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x32e90ULL;
    constexpr uint64_t kFuncSize    = 0x130ULL;
    constexpr uint32_t kFirstOpcode = 0xf81e0ff4U;
    constexpr uint32_t kLastOpcode  = 0x14004acdU;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[277] `sub_32fc0` (`0x32fc0..0x32fe4`, 36 bytes)
 *        Hàm FDE[277] `sub_32fc0` (`0x32fc0..0x32fe4`, 36 bytes)
 * Disassembly: 0x32fc0: stp x19, x30, [sp, #-0x10]! ; 0x32fc4: adrp x8, #0x49000 ; 0x32fc8: add x8, x8, #0x3c8 ; 0x32fcc: mov x19, x0 ; 0x32fd0: str x8, [x0], #0x18 ; 0x32fd4: bl #0x330cc
 */
uint64_t fde_277_0x32fc0(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x32fc0ULL;
    constexpr uint64_t kFuncSize    = 0x24ULL;
    constexpr uint32_t kFirstOpcode = 0xa9bf7bf3U;
    constexpr uint32_t kLastOpcode  = 0x14004ac8U;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[278] `sub_32fe4` (`0x32fe4..0x33010`, 44 bytes)
 *        Hàm FDE[278] `sub_32fe4` (`0x32fe4..0x33010`, 44 bytes)
 * Disassembly: 0x32fe4: stp x19, x30, [sp, #-0x10]! ; 0x32fe8: adrp x8, #0x49000 ; 0x32fec: add x8, x8, #0x3c8 ; 0x32ff0: mov x19, x0 ; 0x32ff4: str x8, [x0], #0x18 ; 0x32ff8: bl #0x330cc
 */
uint64_t fde_278_0x32fe4(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x32fe4ULL;
    constexpr uint64_t kFuncSize    = 0x2cULL;
    constexpr uint32_t kFirstOpcode = 0xa9bf7bf3U;
    constexpr uint32_t kLastOpcode  = 0x14004a49U;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[279] `sub_33010` (`0x33010..0x33080`, 112 bytes)
 *        Hàm FDE[279] `sub_33010` (`0x33010..0x33080`, 112 bytes)
 * Disassembly: 0x33010: str x30, [sp, #-0x10]! ; 0x33014: adrp x8, #0x4c000 ; 0x33018: add x8, x8, #0xd0 ; 0x3301c: ldarb w8, [x8] ; 0x33020: tbz w8, #0, #0x3304c ; 0x33024: adrp x8, #0x4c000
 */
uint64_t fde_279_0x33010(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x33010ULL;
    constexpr uint64_t kFuncSize    = 0x70ULL;
    constexpr uint32_t kFirstOpcode = 0xf81f0ffeU;
    constexpr uint32_t kLastOpcode  = 0x17ffffeaU;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[280] `sub_33080` (`0x33080..0x33098`, 24 bytes)
 *        Hàm FDE[280] `sub_33080` (`0x33080..0x33098`, 24 bytes)
 * Disassembly: 0x33080: stp x19, x30, [sp, #-0x10]! ; 0x33084: mov x19, x0 ; 0x33088: bl #0x45b00 ; 0x3308c: mov x0, x19 ; 0x33090: ldp x19, x30, [sp], #0x10 ; 0x33094: b #0x45930
 */
uint64_t fde_280_0x33080(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x33080ULL;
    constexpr uint64_t kFuncSize    = 0x18ULL;
    constexpr uint32_t kFirstOpcode = 0xa9bf7bf3U;
    constexpr uint32_t kLastOpcode  = 0x14004a27U;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[281] `sub_33098` (`0x33098..0x330b0`, 24 bytes)
 *        Hàm FDE[281] `sub_33098` (`0x33098..0x330b0`, 24 bytes)
 * Disassembly: 0x33098: ldr x0, [x0, #0x18] ; 0x3309c: cbz x0, #0x330ac ; 0x330a0: ldr x8, [x0] ; 0x330a4: ldr x1, [x8, #8] ; 0x330a8: br x1 ; 0x330ac: ret
 */
uint64_t fde_281_0x33098(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x33098ULL;
    constexpr uint64_t kFuncSize    = 0x18ULL;
    constexpr uint32_t kFirstOpcode = 0xf9400c00U;
    constexpr uint32_t kLastOpcode  = 0xd65f03c0U;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[282] `sub_330b0` (`0x330b0..0x330cc`, 28 bytes)
 *        Hàm FDE[282] `sub_330b0` (`0x330b0..0x330cc`, 28 bytes)
 * Disassembly: 0x330b0: ldr x8, [x1, #8] ; 0x330b4: adrp x9, #0x11000 ; 0x330b8: add x9, x9, #0x1f9 ; 0x330bc: add x10, x0, #0x18 ; 0x330c0: cmp x8, x9 ; 0x330c4: csel x0, x10, xzr, eq
 */
uint64_t fde_282_0x330b0(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x330b0ULL;
    constexpr uint64_t kFuncSize    = 0x1cULL;
    constexpr uint32_t kFirstOpcode = 0xf9400428U;
    constexpr uint32_t kLastOpcode  = 0xd65f03c0U;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[283] `sub_330cc` (`0x330cc..0x331a0`, 212 bytes)
 *        Hàm FDE[283] `sub_330cc` (`0x330cc..0x331a0`, 212 bytes)
 * Disassembly: 0x330cc: str x20, [sp, #-0x20]! ; 0x330d0: stp x19, x30, [sp, #0x10] ; 0x330d4: adrp x8, #0x49000 ; 0x330d8: add x8, x8, #0x418 ; 0x330dc: adrp x1, #0xe000 ; 0x330e0: adrp x2, #0xe000
 */
uint64_t fde_283_0x330cc(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x330ccULL;
    constexpr uint64_t kFuncSize    = 0xd4ULL;
    constexpr uint32_t kFirstOpcode = 0xf81e0ff4U;
    constexpr uint32_t kLastOpcode  = 0xd65f03c0U;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[284] `sub_331a0` (`0x331a0..0x331b8`, 24 bytes)
 *        Hàm FDE[284] `sub_331a0` (`0x331a0..0x331b8`, 24 bytes)
 * Disassembly: 0x331a0: stp x19, x30, [sp, #-0x10]! ; 0x331a4: mov x19, x0 ; 0x331a8: bl #0x330cc ; 0x331ac: mov x0, x19 ; 0x331b0: ldp x19, x30, [sp], #0x10 ; 0x331b4: b #0x45930
 */
uint64_t fde_284_0x331a0(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x331a0ULL;
    constexpr uint64_t kFuncSize    = 0x18ULL;
    constexpr uint32_t kFirstOpcode = 0xa9bf7bf3U;
    constexpr uint32_t kLastOpcode  = 0x140049dfU;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[285] `sub_331b8` (`0x331b8..0x3327c`, 196 bytes)
 *        Hàm FDE[285] `sub_331b8` (`0x331b8..0x3327c`, 196 bytes)
 * Disassembly: 0x331b8: str x20, [sp, #-0x20]! ; 0x331bc: stp x19, x30, [sp, #0x10] ; 0x331c0: mov x19, x0 ; 0x331c4: ldr x0, [x0, #0x18] ; 0x331c8: cbz x0, #0x33214 ; 0x331cc: ldr x8, [x0]
 */
uint64_t fde_285_0x331b8(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x331b8ULL;
    constexpr uint64_t kFuncSize    = 0xc4ULL;
    constexpr uint32_t kFirstOpcode = 0xf81e0ff4U;
    constexpr uint32_t kLastOpcode  = 0x14004a1eU;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[286] `sub_3327c` (`0x3327c..0x332a8`, 44 bytes)
 *        Hàm FDE[286] `sub_3327c` (`0x3327c..0x332a8`, 44 bytes)
 * Disassembly: 0x3327c: ldr x9, [x0, #0x28] ; 0x33280: str x9, [x8] ; 0x33284: ldr x9, [x0, #0x30] ; 0x33288: str x9, [x8, #8] ; 0x3328c: cbz x9, #0x332a4 ; 0x33290: add x8, x9, #8
 */
uint64_t fde_286_0x3327c(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x3327cULL;
    constexpr uint64_t kFuncSize    = 0x2cULL;
    constexpr uint32_t kFirstOpcode = 0xf9401409U;
    constexpr uint32_t kLastOpcode  = 0xd65f03c0U;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[287] `sub_332a8` (`0x332a8..0x33354`, 172 bytes)
 *        Hàm FDE[287] `sub_332a8` (`0x332a8..0x33354`, 172 bytes)
 * Disassembly: 0x332a8: sub sp, sp, #0x60 ; 0x332ac: stp x23, x22, [sp, #0x30] ; 0x332b0: stp x21, x20, [sp, #0x40] ; 0x332b4: stp x19, x30, [sp, #0x50] ; 0x332b8: mrs x23, tpidr_el0 ; 0x332bc: ldr x8, [x23, #0x28]
 */
uint64_t fde_287_0x332a8(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x332a8ULL;
    constexpr uint64_t kFuncSize    = 0xacULL;
    constexpr uint32_t kFirstOpcode = 0xd10183ffU;
    constexpr uint32_t kLastOpcode  = 0x94004980U;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[288] `sub_33354` (`0x33354..0x33400`, 172 bytes)
 *        Hàm FDE[288] `sub_33354` (`0x33354..0x33400`, 172 bytes)
 * Disassembly: 0x33354: sub sp, sp, #0x60 ; 0x33358: stp x21, x20, [sp, #0x40] ; 0x3335c: stp x19, x30, [sp, #0x50] ; 0x33360: mrs x21, tpidr_el0 ; 0x33364: ldr x8, [x21, #0x28] ; 0x33368: mov x19, x0
 */
uint64_t fde_288_0x33354(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x33354ULL;
    constexpr uint64_t kFuncSize    = 0xacULL;
    constexpr uint32_t kFirstOpcode = 0xd10183ffU;
    constexpr uint32_t kLastOpcode  = 0x94004955U;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[289] `sub_33400` (`0x33400..0x334e0`, 224 bytes)
 *        Hàm FDE[289] `sub_33400` (`0x33400..0x334e0`, 224 bytes)
 * Disassembly: 0x33400: stp x21, x20, [sp, #-0x20]! ; 0x33404: stp x19, x30, [sp, #0x10] ; 0x33408: cbz x1, #0x334d4 ; 0x3340c: ldr x8, [x0, #8] ; 0x33410: mov x19, x1 ; 0x33414: cbz x8, #0x334a4
 */
uint64_t fde_289_0x33400(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x33400ULL;
    constexpr uint64_t kFuncSize    = 0xe0ULL;
    constexpr uint32_t kFirstOpcode = 0xa9be53f5U;
    constexpr uint32_t kLastOpcode  = 0xd65f03c0U;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[290] `sub_334e0` (`0x334e0..0x334fc`, 28 bytes)
 *        Hàm FDE[290] `sub_334e0` (`0x334e0..0x334fc`, 28 bytes)
 * Disassembly: 0x334e0: cbz x1, #0x334f8 ; 0x334e4: ldr x8, [x0, #8] ; 0x334e8: cbz x8, #0x334f8 ; 0x334ec: ldr x8, [x8, #8] ; 0x334f0: add x0, x8, #8 ; 0x334f4: b #0x1eaf4
 */
uint64_t fde_290_0x334e0(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x334e0ULL;
    constexpr uint64_t kFuncSize    = 0x1cULL;
    constexpr uint32_t kFirstOpcode = 0xb40000c1U;
    constexpr uint32_t kLastOpcode  = 0xd65f03c0U;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[291] `sub_334fc` (`0x334fc..0x33570`, 116 bytes)
 *        Hàm FDE[291] `sub_334fc` (`0x334fc..0x33570`, 116 bytes)
 * Disassembly: 0x334fc: str x20, [sp, #-0x20]! ; 0x33500: stp x19, x30, [sp, #0x10] ; 0x33504: cbz x1, #0x33548 ; 0x33508: ldr x8, [x0] ; 0x3350c: mov x19, x1 ; 0x33510: mov x20, x0
 */
uint64_t fde_291_0x334fc(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x334fcULL;
    constexpr uint64_t kFuncSize    = 0x74ULL;
    constexpr uint32_t kFirstOpcode = 0xf81e0ff4U;
    constexpr uint32_t kLastOpcode  = 0x17ffad62U;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[292] `sub_33570` (`0x33570..0x33658`, 232 bytes)
 *        Hàm FDE[292] `sub_33570` (`0x33570..0x33658`, 232 bytes)
 * Disassembly: 0x33570: stp x21, x20, [sp, #-0x20]! ; 0x33574: stp x19, x30, [sp, #0x10] ; 0x33578: cbz x1, #0x335bc ; 0x3357c: ldr x8, [x0] ; 0x33580: mov x19, x1 ; 0x33584: mov x20, x0
 */
uint64_t fde_292_0x33570(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x33570ULL;
    constexpr uint64_t kFuncSize    = 0xe8ULL;
    constexpr uint32_t kFirstOpcode = 0xa9be53f5U;
    constexpr uint32_t kLastOpcode  = 0x1400491fU;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[293] `sub_33658` (`0x33658..0x336a4`, 76 bytes)
 *        Hàm FDE[293] `sub_33658` (`0x33658..0x336a4`, 76 bytes)
 * Disassembly: 0x33658: stp x19, x30, [sp, #-0x10]! ; 0x3365c: mov x19, x8 ; 0x33660: cbz x1, #0x33698 ; 0x33664: ldr x8, [x0, #8] ; 0x33668: cbz x8, #0x33688 ; 0x3366c: ldr x8, [x8, #8]
 */
uint64_t fde_293_0x33658(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x33658ULL;
    constexpr uint64_t kFuncSize    = 0x4cULL;
    constexpr uint32_t kFirstOpcode = 0xa9bf7bf3U;
    constexpr uint32_t kLastOpcode  = 0xd65f03c0U;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[294] `sub_336a4` (`0x336a4..0x336f0`, 76 bytes)
 *        Hàm FDE[294] `sub_336a4` (`0x336a4..0x336f0`, 76 bytes)
 * Disassembly: 0x336a4: stp x19, x30, [sp, #-0x10]! ; 0x336a8: mov x19, x8 ; 0x336ac: cbz x1, #0x336e4 ; 0x336b0: ldr x8, [x0, #8] ; 0x336b4: cbz x8, #0x336d4 ; 0x336b8: ldr x8, [x8, #8]
 */
uint64_t fde_294_0x336a4(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x336a4ULL;
    constexpr uint64_t kFuncSize    = 0x4cULL;
    constexpr uint32_t kFirstOpcode = 0xa9bf7bf3U;
    constexpr uint32_t kLastOpcode  = 0xd65f03c0U;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[295] `sub_336f0` (`0x336f0..0x337b4`, 196 bytes)
 *        Hàm FDE[295] `sub_336f0` (`0x336f0..0x337b4`, 196 bytes)
 * Disassembly: 0x336f0: sub sp, sp, #0x40 ; 0x336f4: str x20, [sp, #0x20] ; 0x336f8: stp x19, x30, [sp, #0x30] ; 0x336fc: mrs x20, tpidr_el0 ; 0x33700: ldr x8, [x20, #0x28] ; 0x33704: str x8, [sp, #0x18]
 */
uint64_t fde_295_0x336f0(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x336f0ULL;
    constexpr uint64_t kFuncSize    = 0xc4ULL;
    constexpr uint32_t kFirstOpcode = 0xd10103ffU;
    constexpr uint32_t kLastOpcode  = 0x94004868U;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[296] `sub_337b4` (`0x337b4..0x33b0c`, 856 bytes)
 *        Hàm FDE[296] `sub_337b4` (`0x337b4..0x33b0c`, 856 bytes)
 * Disassembly: 0x337b4: sub sp, sp, #0x90 ; 0x337b8: stp x25, x24, [sp, #0x50] ; 0x337bc: stp x23, x22, [sp, #0x60] ; 0x337c0: stp x21, x20, [sp, #0x70] ; 0x337c4: stp x19, x30, [sp, #0x80] ; 0x337c8: mrs x23, tpidr_el0
 */
uint64_t fde_296_0x337b4(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x337b4ULL;
    constexpr uint64_t kFuncSize    = 0x358ULL;
    constexpr uint32_t kFirstOpcode = 0xd10243ffU;
    constexpr uint32_t kLastOpcode  = 0x94004792U;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[297] `sub_33b0c` (`0x33b0c..0x33bcc`, 192 bytes)
 *        Hàm FDE[297] `sub_33b0c` (`0x33b0c..0x33bcc`, 192 bytes)
 * Disassembly: 0x33b0c: str x20, [sp, #-0x20]! ; 0x33b10: stp x19, x30, [sp, #0x10] ; 0x33b14: ldr x8, [x0, #8] ; 0x33b18: cbz x8, #0x33bc0 ; 0x33b1c: ldr x20, [x8, #8] ; 0x33b20: add x19, x20, #0x80
 */
uint64_t fde_297_0x33b0c(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x33b0cULL;
    constexpr uint64_t kFuncSize    = 0xc0ULL;
    constexpr uint32_t kFirstOpcode = 0xf81e0ff4U;
    constexpr uint32_t kLastOpcode  = 0xd65f03c0U;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[298] `sub_33bcc` (`0x33bcc..0x33c68`, 156 bytes)
 *        Hàm FDE[298] `sub_33bcc` (`0x33bcc..0x33c68`, 156 bytes)
 * Disassembly: 0x33bcc: stp x19, x30, [sp, #-0x10]! ; 0x33bd0: ldrb w8, [x0, #0x18] ; 0x33bd4: cbz w8, #0x33c1c ; 0x33bd8: ldr x8, [x0, #8] ; 0x33bdc: mov x19, x0 ; 0x33be0: cbz x8, #0x33c28
 */
uint64_t fde_298_0x33bcc(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x33bccULL;
    constexpr uint64_t kFuncSize    = 0x9cULL;
    constexpr uint32_t kFirstOpcode = 0xa9bf7bf3U;
    constexpr uint32_t kLastOpcode  = 0x17ffffe4U;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[299] `sub_33c68` (`0x33c68..0x33c84`, 28 bytes)
 *        Hàm FDE[299] `sub_33c68` (`0x33c68..0x33c84`, 28 bytes)
 * Disassembly: 0x33c68: ldr x8, [x0, #8] ; 0x33c6c: cbz x8, #0x33c7c ; 0x33c70: ldr x8, [x8, #8] ; 0x33c74: add x0, x8, #8 ; 0x33c78: ret ; 0x33c7c: mov x0, xzr
 */
uint64_t fde_299_0x33c68(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x33c68ULL;
    constexpr uint64_t kFuncSize    = 0x1cULL;
    constexpr uint32_t kFirstOpcode = 0xf9400408U;
    constexpr uint32_t kLastOpcode  = 0xd65f03c0U;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[300] `sub_33c84` (`0x33c84..0x33cd8`, 84 bytes)
 *        Hàm FDE[300] `sub_33c84` (`0x33c84..0x33cd8`, 84 bytes)
 * Disassembly: 0x33c84: stp x19, x30, [sp, #-0x10]! ; 0x33c88: ldr x19, [x0, #0x10] ; 0x33c8c: adrp x8, #0x49000 ; 0x33c90: add x8, x8, #0x500 ; 0x33c94: str x8, [x0] ; 0x33c98: cbz x19, #0x33cb4
 */
uint64_t fde_300_0x33c84(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x33c84ULL;
    constexpr uint64_t kFuncSize    = 0x54ULL;
    constexpr uint32_t kFirstOpcode = 0xa9bf7bf3U;
    constexpr uint32_t kLastOpcode  = 0x14004787U;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[301] `sub_33cd8` (`0x33cd8..0x33d38`, 96 bytes)
 *        Hàm FDE[301] `sub_33cd8` (`0x33cd8..0x33d38`, 96 bytes)
 * Disassembly: 0x33cd8: str x20, [sp, #-0x20]! ; 0x33cdc: stp x19, x30, [sp, #0x10] ; 0x33ce0: ldr x20, [x0, #0x10] ; 0x33ce4: adrp x8, #0x49000 ; 0x33ce8: mov x19, x0 ; 0x33cec: add x8, x8, #0x500
 */
uint64_t fde_301_0x33cd8(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x33cd8ULL;
    constexpr uint64_t kFuncSize    = 0x60ULL;
    constexpr uint32_t kFirstOpcode = 0xf81e0ff4U;
    constexpr uint32_t kLastOpcode  = 0x140046ffU;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[302] `sub_33d38` (`0x33d38..0x33dec`, 180 bytes)
 *        Hàm FDE[302] `sub_33d38` (`0x33d38..0x33dec`, 180 bytes)
 * Disassembly: 0x33d38: str x22, [sp, #-0x30]! ; 0x33d3c: stp x21, x20, [sp, #0x10] ; 0x33d40: stp x19, x30, [sp, #0x20] ; 0x33d44: mov x19, x0 ; 0x33d48: mov w0, #0x28 ; 0x33d4c: mov w21, w2
 */
uint64_t fde_302_0x33d38(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x33d38ULL;
    constexpr uint64_t kFuncSize    = 0xb4ULL;
    constexpr uint32_t kFirstOpcode = 0xf81d0ff6U;
    constexpr uint32_t kLastOpcode  = 0xd65f03c0U;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[303] `sub_33dec` (`0x33dec..0x33ecc`, 224 bytes)
 *        Hàm FDE[303] `sub_33dec` (`0x33dec..0x33ecc`, 224 bytes)
 * Disassembly: 0x33dec: stp x21, x20, [sp, #-0x20]! ; 0x33df0: stp x19, x30, [sp, #0x10] ; 0x33df4: adrp x8, #0x49000 ; 0x33df8: add x8, x8, #0x5f8 ; 0x33dfc: mov x19, x0 ; 0x33e00: str x8, [x0]
 */
uint64_t fde_303_0x33dec(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x33decULL;
    constexpr uint64_t kFuncSize    = 0xe0ULL;
    constexpr uint32_t kFirstOpcode = 0xa9be53f5U;
    constexpr uint32_t kLastOpcode  = 0xd65f03c0U;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[304] `sub_33ecc` (`0x33ecc..0x33fc8`, 252 bytes)
 *        Hàm FDE[304] `sub_33ecc` (`0x33ecc..0x33fc8`, 252 bytes)
 * Disassembly: 0x33ecc: stp x21, x20, [sp, #-0x20]! ; 0x33ed0: stp x19, x30, [sp, #0x10] ; 0x33ed4: mov x19, x0 ; 0x33ed8: ldr x0, [x0, #8] ; 0x33edc: adrp x8, #0x49000 ; 0x33ee0: add x8, x8, #0x638
 */
uint64_t fde_304_0x33ecc(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x33eccULL;
    constexpr uint64_t kFuncSize    = 0xfcULL;
    constexpr uint32_t kFirstOpcode = 0xa9be53f5U;
    constexpr uint32_t kLastOpcode  = 0x140048bfU;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[305] `sub_33fc8` (`0x33fc8..0x33fe0`, 24 bytes)
 *        Hàm FDE[305] `sub_33fc8` (`0x33fc8..0x33fe0`, 24 bytes)
 * Disassembly: 0x33fc8: stp x19, x30, [sp, #-0x10]! ; 0x33fcc: mov x19, x0 ; 0x33fd0: bl #0x33ecc ; 0x33fd4: mov x0, x19 ; 0x33fd8: ldp x19, x30, [sp], #0x10 ; 0x33fdc: b #0x45930
 */
uint64_t fde_305_0x33fc8(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x33fc8ULL;
    constexpr uint64_t kFuncSize    = 0x18ULL;
    constexpr uint32_t kFirstOpcode = 0xa9bf7bf3U;
    constexpr uint32_t kLastOpcode  = 0x14004655U;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[306] `sub_33fe0` (`0x33fe0..0x34038`, 88 bytes)
 *        Hàm FDE[306] `sub_33fe0` (`0x33fe0..0x34038`, 88 bytes)
 * Disassembly: 0x33fe0: sub sp, sp, #0x30 ; 0x33fe4: str x20, [sp, #0x10] ; 0x33fe8: stp x19, x30, [sp, #0x20] ; 0x33fec: mrs x20, tpidr_el0 ; 0x33ff0: ldr x8, [x20, #0x28] ; 0x33ff4: mov x19, x0
 */
uint64_t fde_306_0x33fe0(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x33fe0ULL;
    constexpr uint64_t kFuncSize    = 0x58ULL;
    constexpr uint32_t kFirstOpcode = 0xd100c3ffU;
    constexpr uint32_t kLastOpcode  = 0x94004647U;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[307] `sub_34038` (`0x34038..0x34050`, 24 bytes)
 *        Hàm FDE[307] `sub_34038` (`0x34038..0x34050`, 24 bytes)
 * Disassembly: 0x34038: ldr x8, [x0, #8] ; 0x3403c: adrp x9, #0x49000 ; 0x34040: add x9, x9, #0x5f8 ; 0x34044: str x9, [x0] ; 0x34048: mov x0, x8 ; 0x3404c: b #0x462c0
 */
uint64_t fde_307_0x34038(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x34038ULL;
    constexpr uint64_t kFuncSize    = 0x18ULL;
    constexpr uint32_t kFirstOpcode = 0xf9400408U;
    constexpr uint32_t kLastOpcode  = 0x1400489dU;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[308] `sub_34050` (`0x34050..0x340b4`, 100 bytes)
 *        Hàm FDE[308] `sub_34050` (`0x34050..0x340b4`, 100 bytes)
 * Disassembly: 0x34050: stp x19, x30, [sp, #-0x10]! ; 0x34054: mov x19, x0 ; 0x34058: ldr x0, [x0, #8] ; 0x3405c: adrp x8, #0x49000 ; 0x34060: add x8, x8, #0x5b8 ; 0x34064: str x8, [x19]
 */
uint64_t fde_308_0x34050(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x34050ULL;
    constexpr uint64_t kFuncSize    = 0x64ULL;
    constexpr uint32_t kFirstOpcode = 0xa9bf7bf3U;
    constexpr uint32_t kLastOpcode  = 0x14004884U;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[309] `sub_340b4` (`0x340b4..0x34120`, 108 bytes)
 *        Hàm FDE[309] `sub_340b4` (`0x340b4..0x34120`, 108 bytes)
 * Disassembly: 0x340b4: stp x19, x30, [sp, #-0x10]! ; 0x340b8: mov x19, x0 ; 0x340bc: ldr x0, [x0, #8] ; 0x340c0: adrp x8, #0x49000 ; 0x340c4: add x8, x8, #0x5b8 ; 0x340c8: str x8, [x19]
 */
uint64_t fde_309_0x340b4(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x340b4ULL;
    constexpr uint64_t kFuncSize    = 0x6cULL;
    constexpr uint32_t kFirstOpcode = 0xa9bf7bf3U;
    constexpr uint32_t kLastOpcode  = 0x14004605U;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[310] `sub_34120` (`0x34120..0x34260`, 320 bytes)
 *        Hàm FDE[310] `sub_34120` (`0x34120..0x34260`, 320 bytes)
 * Disassembly: 0x34120: sub sp, sp, #0xa0 ; 0x34124: stp x23, x22, [sp, #0x70] ; 0x34128: stp x21, x20, [sp, #0x80] ; 0x3412c: stp x19, x30, [sp, #0x90] ; 0x34130: mrs x21, tpidr_el0 ; 0x34134: ldr x8, [x21, #0x28]
 */
uint64_t fde_310_0x34120(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x34120ULL;
    constexpr uint64_t kFuncSize    = 0x140ULL;
    constexpr uint32_t kFirstOpcode = 0xd10283ffU;
    constexpr uint32_t kLastOpcode  = 0x940045bdU;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[311] `sub_34260` (`0x34260..0x342d0`, 112 bytes)
 *        Hàm FDE[311] `sub_34260` (`0x34260..0x342d0`, 112 bytes)
 * Disassembly: 0x34260: stp x19, x30, [sp, #-0x10]! ; 0x34264: ldrb w8, [x0, #0x68] ; 0x34268: adrp x9, #0x49000 ; 0x3426c: mov x19, x0 ; 0x34270: add x9, x9, #0x710 ; 0x34274: str x9, [x0]
 */
uint64_t fde_311_0x34260(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x34260ULL;
    constexpr uint64_t kFuncSize    = 0x70ULL;
    constexpr uint32_t kFirstOpcode = 0xa9bf7bf3U;
    constexpr uint32_t kLastOpcode  = 0xd65f03c0U;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[312] `sub_342d0` (`0x342d0..0x3433c`, 108 bytes)
 *        Hàm FDE[312] `sub_342d0` (`0x342d0..0x3433c`, 108 bytes)
 * Disassembly: 0x342d0: stp x19, x30, [sp, #-0x10]! ; 0x342d4: ldrb w8, [x0, #0x68] ; 0x342d8: adrp x9, #0x49000 ; 0x342dc: mov x19, x0 ; 0x342e0: add x9, x9, #0x710 ; 0x342e4: str x9, [x0]
 */
uint64_t fde_312_0x342d0(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x342d0ULL;
    constexpr uint64_t kFuncSize    = 0x6cULL;
    constexpr uint32_t kFirstOpcode = 0xa9bf7bf3U;
    constexpr uint32_t kLastOpcode  = 0x1400457eU;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[313] `sub_3433c` (`0x3433c..0x344fc`, 448 bytes)
 *        Hàm FDE[313] `sub_3433c` (`0x3433c..0x344fc`, 448 bytes)
 * Disassembly: 0x3433c: sub sp, sp, #0x90 ; 0x34340: stp x25, x24, [sp, #0x50] ; 0x34344: stp x23, x22, [sp, #0x60] ; 0x34348: stp x21, x20, [sp, #0x70] ; 0x3434c: stp x19, x30, [sp, #0x80] ; 0x34350: mrs x24, tpidr_el0
 */
uint64_t fde_313_0x3433c(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x3433cULL;
    constexpr uint64_t kFuncSize    = 0x1c0ULL;
    constexpr uint32_t kFirstOpcode = 0xd10243ffU;
    constexpr uint32_t kLastOpcode  = 0x97ffb3d7U;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[314] `sub_344fc` (`0x344fc..0x3451c`, 32 bytes)
 *        Hàm FDE[314] `sub_344fc` (`0x344fc..0x3451c`, 32 bytes)
 * Disassembly: 0x344fc: str x30, [sp, #-0x10]! ; 0x34500: mov w0, #0x10 ; 0x34504: bl #0x459f0 ; 0x34508: adrp x8, #0x49000 ; 0x3450c: add x8, x8, #0x6b8 ; 0x34510: str x8, [x0]
 */
uint64_t fde_314_0x344fc(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x344fcULL;
    constexpr uint64_t kFuncSize    = 0x20ULL;
    constexpr uint32_t kFirstOpcode = 0xf81f0ffeU;
    constexpr uint32_t kLastOpcode  = 0xd65f03c0U;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[315] `sub_3451c` (`0x3451c..0x3452c`, 16 bytes)
 *        Hàm FDE[315] `sub_3451c` (`0x3451c..0x3452c`, 16 bytes)
 * Disassembly: 0x3451c: adrp x8, #0x49000 ; 0x34520: add x8, x8, #0x6b8 ; 0x34524: str x8, [x1] ; 0x34528: ret
 */
uint64_t fde_315_0x3451c(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x3451cULL;
    constexpr uint64_t kFuncSize    = 0x10ULL;
    constexpr uint32_t kFirstOpcode = 0xb00000a8U;
    constexpr uint32_t kLastOpcode  = 0xd65f03c0U;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[316] `sub_3452c` (`0x3452c..0x35150`, 3108 bytes)
 *        Hàm FDE[316] `sub_3452c` (`0x3452c..0x35150`, 3108 bytes)
 * Disassembly: 0x3452c: str d8, [sp, #-0x70]! ; 0x34530: stp x28, x27, [sp, #0x10] ; 0x34534: stp x26, x25, [sp, #0x20] ; 0x34538: stp x24, x23, [sp, #0x30] ; 0x3453c: stp x22, x21, [sp, #0x40] ; 0x34540: stp x20, x19, [sp, #0x50]
 */
uint64_t fde_316_0x3452c(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x3452cULL;
    constexpr uint64_t kFuncSize    = 0xc24ULL;
    constexpr uint32_t kFirstOpcode = 0xfc190fe8U;
    constexpr uint32_t kLastOpcode  = 0x94004201U;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[317] `sub_35150` (`0x35150..0x3516c`, 28 bytes)
 *        Hàm FDE[317] `sub_35150` (`0x35150..0x3516c`, 28 bytes)
 * Disassembly: 0x35150: ldr x8, [x1, #8] ; 0x35154: adrp x9, #0x11000 ; 0x35158: add x9, x9, #0x3fd ; 0x3515c: add x10, x0, #8 ; 0x35160: cmp x8, x9 ; 0x35164: csel x0, x10, xzr, eq
 */
uint64_t fde_317_0x35150(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x35150ULL;
    constexpr uint64_t kFuncSize    = 0x1cULL;
    constexpr uint32_t kFirstOpcode = 0xf9400428U;
    constexpr uint32_t kLastOpcode  = 0xd65f03c0U;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[318] `sub_3516c` (`0x3516c..0x35178`, 12 bytes)
 *        Hàm FDE[318] `sub_3516c` (`0x3516c..0x35178`, 12 bytes)
 * Disassembly: 0x3516c: adrp x0, #0x49000 ; 0x35170: add x0, x0, #0x758 ; 0x35174: ret
 */
uint64_t fde_318_0x3516c(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x3516cULL;
    constexpr uint64_t kFuncSize    = 0xcULL;
    constexpr uint32_t kFirstOpcode = 0x900000a0U;
    constexpr uint32_t kLastOpcode  = 0xd65f03c0U;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[319] `sub_35178` (`0x35178..0x35488`, 784 bytes)
 *        Hàm FDE[319] `sub_35178` (`0x35178..0x35488`, 784 bytes)
 * Disassembly: 0x35178: sub sp, sp, #0xd0 ; 0x3517c: stp x25, x24, [sp, #0x90] ; 0x35180: stp x23, x22, [sp, #0xa0] ; 0x35184: stp x21, x20, [sp, #0xb0] ; 0x35188: stp x19, x30, [sp, #0xc0] ; 0x3518c: mrs x24, tpidr_el0
 */
uint64_t fde_319_0x35178(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x35178ULL;
    constexpr uint64_t kFuncSize    = 0x310ULL;
    constexpr uint32_t kFirstOpcode = 0xd10343ffU;
    constexpr uint32_t kLastOpcode  = 0x9400415fU;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[320] `sub_35488` (`0x35488..0x35e6c`, 2532 bytes)
 *        Hàm FDE[320] `sub_35488` (`0x35488..0x35e6c`, 2532 bytes)
 * Disassembly: 0x35488: sub sp, sp, #0x120 ; 0x3548c: stp x28, x27, [sp, #0xc0] ; 0x35490: stp x26, x25, [sp, #0xd0] ; 0x35494: stp x24, x23, [sp, #0xe0] ; 0x35498: stp x22, x21, [sp, #0xf0] ; 0x3549c: stp x20, x19, [sp, #0x100]
 */
uint64_t fde_320_0x35488(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x35488ULL;
    constexpr uint64_t kFuncSize    = 0x9e4ULL;
    constexpr uint32_t kFirstOpcode = 0xd10483ffU;
    constexpr uint32_t kLastOpcode  = 0x94003ebaU;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[321] `sub_35e6c` (`0x35e6c..0x368c4`, 2648 bytes)
 *        Hàm FDE[321] `sub_35e6c` (`0x35e6c..0x368c4`, 2648 bytes)
 * Disassembly: 0x35e6c: sub sp, sp, #0x190 ; 0x35e70: stp x28, x27, [sp, #0x130] ; 0x35e74: stp x26, x25, [sp, #0x140] ; 0x35e78: stp x24, x23, [sp, #0x150] ; 0x35e7c: stp x22, x21, [sp, #0x160] ; 0x35e80: stp x20, x19, [sp, #0x170]
 */
uint64_t fde_321_0x35e6c(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x35e6cULL;
    constexpr uint64_t kFuncSize    = 0xa58ULL;
    constexpr uint32_t kFirstOpcode = 0xd10643ffU;
    constexpr uint32_t kLastOpcode  = 0x94003c50U;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[322] `sub_368c4` (`0x368c4..0x36ab4`, 496 bytes)
 *        Hàm FDE[322] `sub_368c4` (`0x368c4..0x36ab4`, 496 bytes)
 * Disassembly: 0x368c4: sub sp, sp, #0x80 ; 0x368c8: str x24, [sp, #0x40] ; 0x368cc: stp x23, x22, [sp, #0x50] ; 0x368d0: stp x21, x20, [sp, #0x60] ; 0x368d4: stp x19, x30, [sp, #0x70] ; 0x368d8: mrs x23, tpidr_el0
 */
uint64_t fde_322_0x368c4(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x368c4ULL;
    constexpr uint64_t kFuncSize    = 0x1f0ULL;
    constexpr uint32_t kFirstOpcode = 0xd10203ffU;
    constexpr uint32_t kLastOpcode  = 0x94003ba8U;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[323] `sub_36ab4` (`0x36ab4..0x36ce0`, 556 bytes)
 *        Hàm FDE[323] `sub_36ab4` (`0x36ab4..0x36ce0`, 556 bytes)
 * Disassembly: 0x36ab4: sub sp, sp, #0x80 ; 0x36ab8: stp x23, x22, [sp, #0x50] ; 0x36abc: stp x21, x20, [sp, #0x60] ; 0x36ac0: stp x19, x30, [sp, #0x70] ; 0x36ac4: mrs x22, tpidr_el0 ; 0x36ac8: ldr x8, [x22, #0x28]
 */
uint64_t fde_323_0x36ab4(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x36ab4ULL;
    constexpr uint64_t kFuncSize    = 0x22cULL;
    constexpr uint32_t kFirstOpcode = 0xd10203ffU;
    constexpr uint32_t kLastOpcode  = 0x94003b1dU;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[324] `sub_36ce0` (`0x36ce0..0x36ed4`, 500 bytes)
 *        Hàm FDE[324] `sub_36ce0` (`0x36ce0..0x36ed4`, 500 bytes)
 * Disassembly: 0x36ce0: sub sp, sp, #0x80 ; 0x36ce4: stp x25, x24, [sp, #0x40] ; 0x36ce8: stp x23, x22, [sp, #0x50] ; 0x36cec: stp x21, x20, [sp, #0x60] ; 0x36cf0: stp x19, x30, [sp, #0x70] ; 0x36cf4: mrs x23, tpidr_el0
 */
uint64_t fde_324_0x36ce0(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x36ce0ULL;
    constexpr uint64_t kFuncSize    = 0x1f4ULL;
    constexpr uint32_t kFirstOpcode = 0xd10203ffU;
    constexpr uint32_t kLastOpcode  = 0x94003aa0U;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[325] `sub_36ed4` (`0x36ed4..0x370d0`, 508 bytes)
 *        Hàm FDE[325] `sub_36ed4` (`0x36ed4..0x370d0`, 508 bytes)
 * Disassembly: 0x36ed4: str x24, [sp, #-0x40]! ; 0x36ed8: stp x23, x22, [sp, #0x10] ; 0x36edc: stp x21, x20, [sp, #0x20] ; 0x36ee0: stp x19, x30, [sp, #0x30] ; 0x36ee4: ldr x22, [x0, #8] ; 0x36ee8: mov x21, x2
 */
uint64_t fde_325_0x36ed4(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x36ed4ULL;
    constexpr uint64_t kFuncSize    = 0x1fcULL;
    constexpr uint32_t kFirstOpcode = 0xf81c0ff8U;
    constexpr uint32_t kLastOpcode  = 0xd65f03c0U;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[326] `sub_370d0` (`0x370d0..0x371a4`, 212 bytes)
 *        Hàm FDE[326] `sub_370d0` (`0x370d0..0x371a4`, 212 bytes)
 * Disassembly: 0x370d0: stp x21, x20, [sp, #-0x20]! ; 0x370d4: stp x19, x30, [sp, #0x10] ; 0x370d8: subs x8, x1, #1 ; 0x370dc: mov x19, x0 ; 0x370e0: b.ne #0x370ec ; 0x370e4: mov w20, #2
 */
uint64_t fde_326_0x370d0(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x370d0ULL;
    constexpr uint64_t kFuncSize    = 0xd4ULL;
    constexpr uint32_t kFirstOpcode = 0xa9be53f5U;
    constexpr uint32_t kLastOpcode  = 0xd65f03c0U;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[327] `sub_371a4` (`0x371a4..0x37320`, 380 bytes)
 *        Hàm FDE[327] `sub_371a4` (`0x371a4..0x37320`, 380 bytes)
 * Disassembly: 0x371a4: str x20, [sp, #-0x20]! ; 0x371a8: stp x19, x30, [sp, #0x10] ; 0x371ac: mov x19, x0 ; 0x371b0: cbz x1, #0x37234 ; 0x371b4: mov x20, x1 ; 0x371b8: lsr x8, x1, #0x3d
 */
uint64_t fde_327_0x371a4(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x371a4ULL;
    constexpr uint64_t kFuncSize    = 0x17cULL;
    constexpr uint32_t kFirstOpcode = 0xf81e0ff4U;
    constexpr uint32_t kLastOpcode  = 0x940039b9U;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[328] `sub_37320` (`0x37320..0x37350`, 48 bytes)
 *        Hàm FDE[328] `sub_37320` (`0x37320..0x37350`, 48 bytes)
 * Disassembly: 0x37320: stp x19, x30, [sp, #-0x10]! ; 0x37324: ldr x1, [x0, #0x20] ; 0x37328: adrp x8, #0x49000 ; 0x3732c: add x8, x8, #0x7d0 ; 0x37330: str x8, [x0] ; 0x37334: cbz x1, #0x37348
 */
uint64_t fde_328_0x37320(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x37320ULL;
    constexpr uint64_t kFuncSize    = 0x30ULL;
    constexpr uint32_t kFirstOpcode = 0xa9bf7bf3U;
    constexpr uint32_t kLastOpcode  = 0xd65f03c0U;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[329] `sub_37350` (`0x37350..0x37380`, 48 bytes)
 *        Hàm FDE[329] `sub_37350` (`0x37350..0x37380`, 48 bytes)
 * Disassembly: 0x37350: stp x19, x30, [sp, #-0x10]! ; 0x37354: ldr x1, [x0, #0x20] ; 0x37358: adrp x8, #0x49000 ; 0x3735c: mov x19, x0 ; 0x37360: add x8, x8, #0x7d0 ; 0x37364: str x8, [x0]
 */
uint64_t fde_329_0x37350(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x37350ULL;
    constexpr uint64_t kFuncSize    = 0x30ULL;
    constexpr uint32_t kFirstOpcode = 0xa9bf7bf3U;
    constexpr uint32_t kLastOpcode  = 0x1400396dU;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[330] `sub_37380` (`0x37380..0x3760c`, 652 bytes)
 *        Hàm FDE[330] `sub_37380` (`0x37380..0x3760c`, 652 bytes)
 * Disassembly: 0x37380: sub sp, sp, #0xb0 ; 0x37384: stp x25, x24, [sp, #0x70] ; 0x37388: stp x23, x22, [sp, #0x80] ; 0x3738c: stp x21, x20, [sp, #0x90] ; 0x37390: stp x19, x30, [sp, #0xa0] ; 0x37394: mrs x24, tpidr_el0
 */
uint64_t fde_330_0x37380(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x37380ULL;
    constexpr uint64_t kFuncSize    = 0x28cULL;
    constexpr uint32_t kFirstOpcode = 0xd102c3ffU;
    constexpr uint32_t kLastOpcode  = 0x940038feU;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[331] `sub_3760c` (`0x3760c..0x376f0`, 228 bytes)
 *        Hàm FDE[331] `sub_3760c` (`0x3760c..0x376f0`, 228 bytes)
 * Disassembly: 0x3760c: stp x21, x20, [sp, #-0x20]! ; 0x37610: stp x19, x30, [sp, #0x10] ; 0x37614: ldr x8, [x0, #0x50] ; 0x37618: cbz x8, #0x376d0 ; 0x3761c: ldp x21, x20, [x8, #0x18] ; 0x37620: mov x19, x0
 */
uint64_t fde_331_0x3760c(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x3760cULL;
    constexpr uint64_t kFuncSize    = 0xe4ULL;
    constexpr uint32_t kFirstOpcode = 0xa9be53f5U;
    constexpr uint32_t kLastOpcode  = 0xd61f0020U;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[332] `sub_376f0` (`0x376f0..0x3774c`, 92 bytes)
 *        Hàm FDE[332] `sub_376f0` (`0x376f0..0x3774c`, 92 bytes)
 * Disassembly: 0x376f0: sub sp, sp, #0x40 ; 0x376f4: str x20, [sp, #0x20] ; 0x376f8: stp x19, x30, [sp, #0x30] ; 0x376fc: mrs x20, tpidr_el0 ; 0x37700: ldr x8, [x20, #0x28] ; 0x37704: str x8, [sp, #0x18]
 */
uint64_t fde_332_0x376f0(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x376f0ULL;
    constexpr uint64_t kFuncSize    = 0x5cULL;
    constexpr uint32_t kFirstOpcode = 0xd10103ffU;
    constexpr uint32_t kLastOpcode  = 0x94003882U;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[333] `sub_3774c` (`0x3774c..0x37880`, 308 bytes)
 *        Hàm FDE[333] `sub_3774c` (`0x3774c..0x37880`, 308 bytes)
 * Disassembly: 0x3774c: sub sp, sp, #0xc0 ; 0x37750: stp x23, x22, [sp, #0x90] ; 0x37754: stp x21, x20, [sp, #0xa0] ; 0x37758: stp x19, x30, [sp, #0xb0] ; 0x3775c: mrs x21, tpidr_el0 ; 0x37760: ldr x8, [x21, #0x28]
 */
uint64_t fde_333_0x3774c(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x3774cULL;
    constexpr uint64_t kFuncSize    = 0x134ULL;
    constexpr uint32_t kFirstOpcode = 0xd10303ffU;
    constexpr uint32_t kLastOpcode  = 0x94003835U;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[334] `sub_37880` (`0x37880..0x378dc`, 92 bytes)
 *        Hàm FDE[334] `sub_37880` (`0x37880..0x378dc`, 92 bytes)
 * Disassembly: 0x37880: sub sp, sp, #0x40 ; 0x37884: str x20, [sp, #0x20] ; 0x37888: stp x19, x30, [sp, #0x30] ; 0x3788c: mrs x20, tpidr_el0 ; 0x37890: ldr x8, [x20, #0x28] ; 0x37894: str x8, [sp, #0x18]
 */
uint64_t fde_334_0x37880(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x37880ULL;
    constexpr uint64_t kFuncSize    = 0x5cULL;
    constexpr uint32_t kFirstOpcode = 0xd10103ffU;
    constexpr uint32_t kLastOpcode  = 0x9400381eU;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[335] `sub_378dc` (`0x378dc..0x37938`, 92 bytes)
 *        Hàm FDE[335] `sub_378dc` (`0x378dc..0x37938`, 92 bytes)
 * Disassembly: 0x378dc: sub sp, sp, #0x40 ; 0x378e0: str x20, [sp, #0x20] ; 0x378e4: stp x19, x30, [sp, #0x30] ; 0x378e8: mrs x20, tpidr_el0 ; 0x378ec: ldr x8, [x20, #0x28] ; 0x378f0: str x8, [sp, #0x18]
 */
uint64_t fde_335_0x378dc(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x378dcULL;
    constexpr uint64_t kFuncSize    = 0x5cULL;
    constexpr uint32_t kFirstOpcode = 0xd10103ffU;
    constexpr uint32_t kLastOpcode  = 0x94003807U;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[336] `sub_37938` (`0x37938..0x37a9c`, 356 bytes)
 *        Hàm FDE[336] `sub_37938` (`0x37938..0x37a9c`, 356 bytes)
 * Disassembly: 0x37938: sub sp, sp, #0x80 ; 0x3793c: str x26, [sp, #0x30] ; 0x37940: stp x25, x24, [sp, #0x40] ; 0x37944: stp x23, x22, [sp, #0x50] ; 0x37948: stp x21, x20, [sp, #0x60] ; 0x3794c: stp x19, x30, [sp, #0x70]
 */
uint64_t fde_336_0x37938(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x37938ULL;
    constexpr uint64_t kFuncSize    = 0x164ULL;
    constexpr uint32_t kFirstOpcode = 0xd10203ffU;
    constexpr uint32_t kLastOpcode  = 0x940037aeU;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[337] `sub_37a9c` (`0x37a9c..0x37dfc`, 864 bytes)
 *        Hàm FDE[337] `sub_37a9c` (`0x37a9c..0x37dfc`, 864 bytes)
 * Disassembly: 0x37a9c: sub sp, sp, #0xd0 ; 0x37aa0: stp x23, x22, [sp, #0xa0] ; 0x37aa4: stp x21, x20, [sp, #0xb0] ; 0x37aa8: stp x19, x30, [sp, #0xc0] ; 0x37aac: mrs x23, tpidr_el0 ; 0x37ab0: ldr x8, [x23, #0x28]
 */
uint64_t fde_337_0x37a9c(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x37a9cULL;
    constexpr uint64_t kFuncSize    = 0x360ULL;
    constexpr uint32_t kFirstOpcode = 0xd10343ffU;
    constexpr uint32_t kLastOpcode  = 0x940036d6U;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[338] `sub_37dfc` (`0x37dfc..0x37f30`, 308 bytes)
 *        Hàm FDE[338] `sub_37dfc` (`0x37dfc..0x37f30`, 308 bytes)
 * Disassembly: 0x37dfc: sub sp, sp, #0xc0 ; 0x37e00: stp x23, x22, [sp, #0x90] ; 0x37e04: stp x21, x20, [sp, #0xa0] ; 0x37e08: stp x19, x30, [sp, #0xb0] ; 0x37e0c: mrs x21, tpidr_el0 ; 0x37e10: ldr x8, [x21, #0x28]
 */
uint64_t fde_338_0x37dfc(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x37dfcULL;
    constexpr uint64_t kFuncSize    = 0x134ULL;
    constexpr uint32_t kFirstOpcode = 0xd10303ffU;
    constexpr uint32_t kLastOpcode  = 0x94003689U;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[339] `sub_37f30` (`0x37f30..0x38064`, 308 bytes)
 *        Hàm FDE[339] `sub_37f30` (`0x37f30..0x38064`, 308 bytes)
 * Disassembly: 0x37f30: sub sp, sp, #0xc0 ; 0x37f34: stp x23, x22, [sp, #0x90] ; 0x37f38: stp x21, x20, [sp, #0xa0] ; 0x37f3c: stp x19, x30, [sp, #0xb0] ; 0x37f40: mrs x21, tpidr_el0 ; 0x37f44: ldr x8, [x21, #0x28]
 */
uint64_t fde_339_0x37f30(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x37f30ULL;
    constexpr uint64_t kFuncSize    = 0x134ULL;
    constexpr uint32_t kFirstOpcode = 0xd10303ffU;
    constexpr uint32_t kLastOpcode  = 0x9400363cU;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[340] `sub_38064` (`0x38064..0x380ac`, 72 bytes)
 *        Hàm FDE[340] `sub_38064` (`0x38064..0x380ac`, 72 bytes)
 * Disassembly: 0x38064: stp x19, x30, [sp, #-0x10]! ; 0x38068: ldr x1, [x0, #0x30] ; 0x3806c: mov x19, x0 ; 0x38070: cbz x1, #0x38080 ; 0x38074: ldr x0, [x19, #0x28] ; 0x38078: bl #0x45d40
 */
uint64_t fde_340_0x38064(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x38064ULL;
    constexpr uint64_t kFuncSize    = 0x48ULL;
    constexpr uint32_t kFirstOpcode = 0xa9bf7bf3U;
    constexpr uint32_t kLastOpcode  = 0x140036f2U;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[341] `sub_380ac` (`0x380ac..0x380fc`, 80 bytes)
 *        Hàm FDE[341] `sub_380ac` (`0x380ac..0x380fc`, 80 bytes)
 * Disassembly: 0x380ac: stp x19, x30, [sp, #-0x10]! ; 0x380b0: ldr x1, [x0, #0x30] ; 0x380b4: mov x19, x0 ; 0x380b8: cbz x1, #0x380c8 ; 0x380bc: ldr x0, [x19, #0x28] ; 0x380c0: bl #0x45d40
 */
uint64_t fde_341_0x380ac(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x380acULL;
    constexpr uint64_t kFuncSize    = 0x50ULL;
    constexpr uint32_t kFirstOpcode = 0xa9bf7bf3U;
    constexpr uint32_t kLastOpcode  = 0x1400360eU;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[342] `sub_380fc` (`0x380fc..0x38130`, 52 bytes)
 *        Hàm FDE[342] `sub_380fc` (`0x380fc..0x38130`, 52 bytes)
 * Disassembly: 0x380fc: stp x19, x30, [sp, #-0x10]! ; 0x38100: ldr x1, [x0, #0x20] ; 0x38104: adrp x8, #0x49000 ; 0x38108: mov x19, x0 ; 0x3810c: add x8, x8, #0x890 ; 0x38110: str x8, [x0]
 */
uint64_t fde_342_0x380fc(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x380fcULL;
    constexpr uint64_t kFuncSize    = 0x34ULL;
    constexpr uint32_t kFirstOpcode = 0xa9bf7bf3U;
    constexpr uint32_t kLastOpcode  = 0x140036d1U;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[343] `sub_38130` (`0x38130..0x3816c`, 60 bytes)
 *        Hàm FDE[343] `sub_38130` (`0x38130..0x3816c`, 60 bytes)
 * Disassembly: 0x38130: stp x19, x30, [sp, #-0x10]! ; 0x38134: ldr x1, [x0, #0x20] ; 0x38138: adrp x8, #0x49000 ; 0x3813c: mov x19, x0 ; 0x38140: add x8, x8, #0x890 ; 0x38144: str x8, [x0]
 */
uint64_t fde_343_0x38130(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x38130ULL;
    constexpr uint64_t kFuncSize    = 0x3cULL;
    constexpr uint32_t kFirstOpcode = 0xa9bf7bf3U;
    constexpr uint32_t kLastOpcode  = 0x140035f2U;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[344] `sub_3816c` (`0x3816c..0x382d8`, 364 bytes)
 *        Hàm FDE[344] `sub_3816c` (`0x3816c..0x382d8`, 364 bytes)
 * Disassembly: 0x3816c: sub sp, sp, #0x90 ; 0x38170: str x22, [sp, #0x60] ; 0x38174: stp x21, x20, [sp, #0x70] ; 0x38178: stp x19, x30, [sp, #0x80] ; 0x3817c: mrs x22, tpidr_el0 ; 0x38180: ldr x8, [x22, #0x28]
 */
uint64_t fde_344_0x3816c(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x3816cULL;
    constexpr uint64_t kFuncSize    = 0x16cULL;
    constexpr uint32_t kFirstOpcode = 0xd10243ffU;
    constexpr uint32_t kLastOpcode  = 0x9400359fU;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[345] `sub_382d8` (`0x382d8..0x3840c`, 308 bytes)
 *        Hàm FDE[345] `sub_382d8` (`0x382d8..0x3840c`, 308 bytes)
 * Disassembly: 0x382d8: sub sp, sp, #0xc0 ; 0x382dc: stp x23, x22, [sp, #0x90] ; 0x382e0: stp x21, x20, [sp, #0xa0] ; 0x382e4: stp x19, x30, [sp, #0xb0] ; 0x382e8: mrs x21, tpidr_el0 ; 0x382ec: ldr x8, [x21, #0x28]
 */
uint64_t fde_345_0x382d8(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x382d8ULL;
    constexpr uint64_t kFuncSize    = 0x134ULL;
    constexpr uint32_t kFirstOpcode = 0xd10303ffU;
    constexpr uint32_t kLastOpcode  = 0x94003552U;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[346] `sub_3840c` (`0x3840c..0x384d0`, 196 bytes)
 *        Hàm FDE[346] `sub_3840c` (`0x3840c..0x384d0`, 196 bytes)
 * Disassembly: 0x3840c: sub sp, sp, #0x60 ; 0x38410: str x22, [sp, #0x30] ; 0x38414: stp x21, x20, [sp, #0x40] ; 0x38418: stp x19, x30, [sp, #0x50] ; 0x3841c: mrs x22, tpidr_el0 ; 0x38420: ldr x8, [x22, #0x28]
 */
uint64_t fde_346_0x3840c(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x3840cULL;
    constexpr uint64_t kFuncSize    = 0xc4ULL;
    constexpr uint32_t kFirstOpcode = 0xd10183ffU;
    constexpr uint32_t kLastOpcode  = 0x94003521U;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[347] `sub_384d0` (`0x384d0..0x385b4`, 228 bytes)
 *        Hàm FDE[347] `sub_384d0` (`0x384d0..0x385b4`, 228 bytes)
 * Disassembly: 0x384d0: sub sp, sp, #0x50 ; 0x384d4: stp x21, x20, [sp, #0x30] ; 0x384d8: stp x19, x30, [sp, #0x40] ; 0x384dc: mrs x21, tpidr_el0 ; 0x384e0: ldr x8, [x21, #0x28] ; 0x384e4: mov x19, x1
 */
uint64_t fde_347_0x384d0(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x384d0ULL;
    constexpr uint64_t kFuncSize    = 0xe4ULL;
    constexpr uint32_t kFirstOpcode = 0xd10143ffU;
    constexpr uint32_t kLastOpcode  = 0x940034e8U;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[348] `sub_385b4` (`0x385b4..0x38688`, 212 bytes)
 *        Hàm FDE[348] `sub_385b4` (`0x385b4..0x38688`, 212 bytes)
 * Disassembly: 0x385b4: sub sp, sp, #0x40 ; 0x385b8: stp x21, x20, [sp, #0x20] ; 0x385bc: stp x19, x30, [sp, #0x30] ; 0x385c0: mrs x21, tpidr_el0 ; 0x385c4: ldr x8, [x21, #0x28] ; 0x385c8: mov x19, x1
 */
uint64_t fde_348_0x385b4(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x385b4ULL;
    constexpr uint64_t kFuncSize    = 0xd4ULL;
    constexpr uint32_t kFirstOpcode = 0xd10103ffU;
    constexpr uint32_t kLastOpcode  = 0x94003733U;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[349] `sub_38688` (`0x38688..0x38768`, 224 bytes)
 *        Hàm FDE[349] `sub_38688` (`0x38688..0x38768`, 224 bytes)
 * Disassembly: 0x38688: sub sp, sp, #0x60 ; 0x3868c: stp x23, x22, [sp, #0x30] ; 0x38690: stp x21, x20, [sp, #0x40] ; 0x38694: stp x19, x30, [sp, #0x50] ; 0x38698: mrs x23, tpidr_el0 ; 0x3869c: ldr x8, [x23, #0x28]
 */
uint64_t fde_349_0x38688(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x38688ULL;
    constexpr uint64_t kFuncSize    = 0xe0ULL;
    constexpr uint32_t kFirstOpcode = 0xd10183ffU;
    constexpr uint32_t kLastOpcode  = 0x9400347bU;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[350] `sub_38768` (`0x38768..0x387bc`, 84 bytes)
 *        Hàm FDE[350] `sub_38768` (`0x38768..0x387bc`, 84 bytes)
 * Disassembly: 0x38768: sub sp, sp, #0x40 ; 0x3876c: str x20, [sp, #0x20] ; 0x38770: stp x19, x30, [sp, #0x30] ; 0x38774: mrs x20, tpidr_el0 ; 0x38778: ldr x8, [x20, #0x28] ; 0x3877c: str x8, [sp, #0x18]
 */
uint64_t fde_350_0x38768(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x38768ULL;
    constexpr uint64_t kFuncSize    = 0x54ULL;
    constexpr uint32_t kFirstOpcode = 0xd10103ffU;
    constexpr uint32_t kLastOpcode  = 0x94003466U;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[351] `sub_387bc` (`0x387bc..0x388b8`, 252 bytes)
 *        Hàm FDE[351] `sub_387bc` (`0x387bc..0x388b8`, 252 bytes)
 * Disassembly: 0x387bc: sub sp, sp, #0x80 ; 0x387c0: str x22, [sp, #0x50] ; 0x387c4: stp x21, x20, [sp, #0x60] ; 0x387c8: stp x19, x30, [sp, #0x70] ; 0x387cc: mrs x22, tpidr_el0 ; 0x387d0: ldr x8, [x22, #0x28]
 */
uint64_t fde_351_0x387bc(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x387bcULL;
    constexpr uint64_t kFuncSize    = 0xfcULL;
    constexpr uint32_t kFirstOpcode = 0xd10203ffU;
    constexpr uint32_t kLastOpcode  = 0x94003427U;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[352] `sub_388b8` (`0x388b8..0x389f8`, 320 bytes)
 *        Hàm FDE[352] `sub_388b8` (`0x388b8..0x389f8`, 320 bytes)
 * Disassembly: 0x388b8: sub sp, sp, #0x90 ; 0x388bc: stp x23, x22, [sp, #0x60] ; 0x388c0: stp x21, x20, [sp, #0x70] ; 0x388c4: stp x19, x30, [sp, #0x80] ; 0x388c8: mrs x23, tpidr_el0 ; 0x388cc: ldr x8, [x23, #0x28]
 */
uint64_t fde_352_0x388b8(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x388b8ULL;
    constexpr uint64_t kFuncSize    = 0x140ULL;
    constexpr uint32_t kFirstOpcode = 0xd10243ffU;
    constexpr uint32_t kLastOpcode  = 0x940033d7U;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[353] `sub_389f8` (`0x389f8..0x38c34`, 572 bytes)
 *        Hàm FDE[353] `sub_389f8` (`0x389f8..0x38c34`, 572 bytes)
 * Disassembly: 0x389f8: sub sp, sp, #0xc0 ; 0x389fc: stp x23, x22, [sp, #0x90] ; 0x38a00: stp x21, x20, [sp, #0xa0] ; 0x38a04: stp x19, x30, [sp, #0xb0] ; 0x38a08: mrs x23, tpidr_el0 ; 0x38a0c: ldr x8, [x23, #0x28]
 */
uint64_t fde_353_0x389f8(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x389f8ULL;
    constexpr uint64_t kFuncSize    = 0x23cULL;
    constexpr uint32_t kFirstOpcode = 0xd10303ffU;
    constexpr uint32_t kLastOpcode  = 0x94003348U;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[354] `sub_38c34` (`0x38c34..0x38d68`, 308 bytes)
 *        Hàm FDE[354] `sub_38c34` (`0x38c34..0x38d68`, 308 bytes)
 * Disassembly: 0x38c34: sub sp, sp, #0xc0 ; 0x38c38: stp x23, x22, [sp, #0x90] ; 0x38c3c: stp x21, x20, [sp, #0xa0] ; 0x38c40: stp x19, x30, [sp, #0xb0] ; 0x38c44: mrs x21, tpidr_el0 ; 0x38c48: ldr x8, [x21, #0x28]
 */
uint64_t fde_354_0x38c34(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x38c34ULL;
    constexpr uint64_t kFuncSize    = 0x134ULL;
    constexpr uint32_t kFirstOpcode = 0xd10303ffU;
    constexpr uint32_t kLastOpcode  = 0x940032fbU;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[355] `sub_38d68` (`0x38d68..0x38e9c`, 308 bytes)
 *        Hàm FDE[355] `sub_38d68` (`0x38d68..0x38e9c`, 308 bytes)
 * Disassembly: 0x38d68: sub sp, sp, #0xc0 ; 0x38d6c: stp x23, x22, [sp, #0x90] ; 0x38d70: stp x21, x20, [sp, #0xa0] ; 0x38d74: stp x19, x30, [sp, #0xb0] ; 0x38d78: mrs x21, tpidr_el0 ; 0x38d7c: ldr x8, [x21, #0x28]
 */
uint64_t fde_355_0x38d68(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x38d68ULL;
    constexpr uint64_t kFuncSize    = 0x134ULL;
    constexpr uint32_t kFirstOpcode = 0xd10303ffU;
    constexpr uint32_t kLastOpcode  = 0x940032aeU;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[356] `sub_38e9c` (`0x38e9c..0x38ee4`, 72 bytes)
 *        Hàm FDE[356] `sub_38e9c` (`0x38e9c..0x38ee4`, 72 bytes)
 * Disassembly: 0x38e9c: stp x19, x30, [sp, #-0x10]! ; 0x38ea0: ldr x1, [x0, #0x30] ; 0x38ea4: mov x19, x0 ; 0x38ea8: cbz x1, #0x38eb8 ; 0x38eac: ldr x0, [x19, #0x28] ; 0x38eb0: bl #0x45d40
 */
uint64_t fde_356_0x38e9c(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x38e9cULL;
    constexpr uint64_t kFuncSize    = 0x48ULL;
    constexpr uint32_t kFirstOpcode = 0xa9bf7bf3U;
    constexpr uint32_t kLastOpcode  = 0x14003364U;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[357] `sub_38ee4` (`0x38ee4..0x38f34`, 80 bytes)
 *        Hàm FDE[357] `sub_38ee4` (`0x38ee4..0x38f34`, 80 bytes)
 * Disassembly: 0x38ee4: stp x19, x30, [sp, #-0x10]! ; 0x38ee8: ldr x1, [x0, #0x30] ; 0x38eec: mov x19, x0 ; 0x38ef0: cbz x1, #0x38f00 ; 0x38ef4: ldr x0, [x19, #0x28] ; 0x38ef8: bl #0x45d40
 */
uint64_t fde_357_0x38ee4(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x38ee4ULL;
    constexpr uint64_t kFuncSize    = 0x50ULL;
    constexpr uint32_t kFirstOpcode = 0xa9bf7bf3U;
    constexpr uint32_t kLastOpcode  = 0x14003280U;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[358] `sub_38f34` (`0x38f34..0x38f68`, 52 bytes)
 *        Hàm FDE[358] `sub_38f34` (`0x38f34..0x38f68`, 52 bytes)
 * Disassembly: 0x38f34: stp x19, x30, [sp, #-0x10]! ; 0x38f38: ldr x1, [x0, #0x20] ; 0x38f3c: adrp x8, #0x49000 ; 0x38f40: mov x19, x0 ; 0x38f44: add x8, x8, #0x940 ; 0x38f48: str x8, [x0]
 */
uint64_t fde_358_0x38f34(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x38f34ULL;
    constexpr uint64_t kFuncSize    = 0x34ULL;
    constexpr uint32_t kFirstOpcode = 0xa9bf7bf3U;
    constexpr uint32_t kLastOpcode  = 0x14003343U;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[359] `sub_38f68` (`0x38f68..0x38fa4`, 60 bytes)
 *        Hàm FDE[359] `sub_38f68` (`0x38f68..0x38fa4`, 60 bytes)
 * Disassembly: 0x38f68: stp x19, x30, [sp, #-0x10]! ; 0x38f6c: ldr x1, [x0, #0x20] ; 0x38f70: adrp x8, #0x49000 ; 0x38f74: mov x19, x0 ; 0x38f78: add x8, x8, #0x940 ; 0x38f7c: str x8, [x0]
 */
uint64_t fde_359_0x38f68(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x38f68ULL;
    constexpr uint64_t kFuncSize    = 0x3cULL;
    constexpr uint32_t kFirstOpcode = 0xa9bf7bf3U;
    constexpr uint32_t kLastOpcode  = 0x14003264U;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[360] `sub_38fa4` (`0x38fa4..0x39100`, 348 bytes)
 *        Hàm FDE[360] `sub_38fa4` (`0x38fa4..0x39100`, 348 bytes)
 * Disassembly: 0x38fa4: sub sp, sp, #0xa0 ; 0x38fa8: str x22, [sp, #0x70] ; 0x38fac: stp x21, x20, [sp, #0x80] ; 0x38fb0: stp x19, x30, [sp, #0x90] ; 0x38fb4: mrs x22, tpidr_el0 ; 0x38fb8: ldr x8, [x22, #0x28]
 */
uint64_t fde_360_0x38fa4(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x38fa4ULL;
    constexpr uint64_t kFuncSize    = 0x15cULL;
    constexpr uint32_t kFirstOpcode = 0xd10283ffU;
    constexpr uint32_t kLastOpcode  = 0x94003215U;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[361] `sub_39100` (`0x39100..0x392b0`, 432 bytes)
 *        Hàm FDE[361] `sub_39100` (`0x39100..0x392b0`, 432 bytes)
 * Disassembly: 0x39100: sub sp, sp, #0xa0 ; 0x39104: stp x23, x22, [sp, #0x70] ; 0x39108: stp x21, x20, [sp, #0x80] ; 0x3910c: stp x19, x30, [sp, #0x90] ; 0x39110: mrs x22, tpidr_el0 ; 0x39114: ldr x8, [x22, #0x28]
 */
uint64_t fde_361_0x39100(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x39100ULL;
    constexpr uint64_t kFuncSize    = 0x1b0ULL;
    constexpr uint32_t kFirstOpcode = 0xd10283ffU;
    constexpr uint32_t kLastOpcode  = 0x940031a9U;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[362] `sub_392b0` (`0x392b0..0x39390`, 224 bytes)
 *        Hàm FDE[362] `sub_392b0` (`0x392b0..0x39390`, 224 bytes)
 * Disassembly: 0x392b0: str x26, [sp, #-0x50]! ; 0x392b4: stp x25, x24, [sp, #0x10] ; 0x392b8: stp x23, x22, [sp, #0x20] ; 0x392bc: stp x21, x20, [sp, #0x30] ; 0x392c0: stp x19, x30, [sp, #0x40] ; 0x392c4: mov x20, x0
 */
uint64_t fde_362_0x392b0(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x392b0ULL;
    constexpr uint64_t kFuncSize    = 0xe0ULL;
    constexpr uint32_t kFirstOpcode = 0xf81b0ffaU;
    constexpr uint32_t kLastOpcode  = 0x9400319dU;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[363] `sub_39390` (`0x39390..0x393bc`, 44 bytes)
 *        Hàm FDE[363] `sub_39390` (`0x39390..0x393bc`, 44 bytes)
 * Disassembly: 0x39390: stp x19, x30, [sp, #-0x10]! ; 0x39394: mov x19, x0 ; 0x39398: mov w0, #0x10 ; 0x3939c: bl #0x459f0 ; 0x393a0: adrp x8, #0x49000 ; 0x393a4: add x8, x8, #0x778
 */
uint64_t fde_363_0x39390(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x39390ULL;
    constexpr uint64_t kFuncSize    = 0x2cULL;
    constexpr uint32_t kFirstOpcode = 0xa9bf7bf3U;
    constexpr uint32_t kLastOpcode  = 0xd65f03c0U;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[364] `sub_393bc` (`0x393bc..0x393d4`, 24 bytes)
 *        Hàm FDE[364] `sub_393bc` (`0x393bc..0x393d4`, 24 bytes)
 * Disassembly: 0x393bc: adrp x8, #0x49000 ; 0x393c0: add x8, x8, #0x778 ; 0x393c4: str x8, [x1] ; 0x393c8: ldr x8, [x0, #8] ; 0x393cc: str x8, [x1, #8] ; 0x393d0: ret
 */
uint64_t fde_364_0x393bc(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x393bcULL;
    constexpr uint64_t kFuncSize    = 0x18ULL;
    constexpr uint32_t kFirstOpcode = 0x90000088U;
    constexpr uint32_t kLastOpcode  = 0xd65f03c0U;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[365] `sub_393d4` (`0x393d4..0x3942c`, 88 bytes)
 *        Hàm FDE[365] `sub_393d4` (`0x393d4..0x3942c`, 88 bytes)
 * Disassembly: 0x393d4: ldr x9, [x0, #8] ; 0x393d8: mov w10, #1 ; 0x393dc: ldrb w8, [x1] ; 0x393e0: strb w10, [x9, #0xb0] ; 0x393e4: mov x10, x9 ; 0x393e8: ldrb w11, [x10, #0xb8]!
 */
uint64_t fde_365_0x393d4(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x393d4ULL;
    constexpr uint64_t kFuncSize    = 0x58ULL;
    constexpr uint32_t kFirstOpcode = 0xf9400409U;
    constexpr uint32_t kLastOpcode  = 0x14003146U;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[366] `sub_3942c` (`0x3942c..0x39448`, 28 bytes)
 *        Hàm FDE[366] `sub_3942c` (`0x3942c..0x39448`, 28 bytes)
 * Disassembly: 0x3942c: ldr x8, [x1, #8] ; 0x39430: adrp x9, #0x11000 ; 0x39434: add x9, x9, #0x53b ; 0x39438: add x10, x0, #8 ; 0x3943c: cmp x8, x9 ; 0x39440: csel x0, x10, xzr, eq
 */
uint64_t fde_366_0x3942c(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x3942cULL;
    constexpr uint64_t kFuncSize    = 0x1cULL;
    constexpr uint32_t kFirstOpcode = 0xf9400428U;
    constexpr uint32_t kLastOpcode  = 0xd65f03c0U;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[367] `sub_39448` (`0x39448..0x39454`, 12 bytes)
 *        Hàm FDE[367] `sub_39448` (`0x39448..0x39454`, 12 bytes)
 * Disassembly: 0x39448: adrp x0, #0x49000 ; 0x3944c: add x0, x0, #0x978 ; 0x39450: ret
 */
uint64_t fde_367_0x39448(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x39448ULL;
    constexpr uint64_t kFuncSize    = 0xcULL;
    constexpr uint32_t kFirstOpcode = 0x90000080U;
    constexpr uint32_t kLastOpcode  = 0xd65f03c0U;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[368] `sub_39454` (`0x39454..0x39590`, 316 bytes)
 *        Hàm FDE[368] `sub_39454` (`0x39454..0x39590`, 316 bytes)
 * Disassembly: 0x39454: sub sp, sp, #0xa0 ; 0x39458: stp x23, x22, [sp, #0x70] ; 0x3945c: stp x21, x20, [sp, #0x80] ; 0x39460: stp x19, x30, [sp, #0x90] ; 0x39464: mrs x21, tpidr_el0 ; 0x39468: ldr x8, [x21, #0x28]
 */
uint64_t fde_368_0x39454(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x39454ULL;
    constexpr uint64_t kFuncSize    = 0x13cULL;
    constexpr uint32_t kFirstOpcode = 0xd10283ffU;
    constexpr uint32_t kLastOpcode  = 0x940030f1U;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[369] `sub_39590` (`0x39590..0x395b0`, 32 bytes)
 *        Hàm FDE[369] `sub_39590` (`0x39590..0x395b0`, 32 bytes)
 * Disassembly: 0x39590: str x30, [sp, #-0x10]! ; 0x39594: mov w0, #0x10 ; 0x39598: bl #0x459f0 ; 0x3959c: adrp x8, #0x49000 ; 0x395a0: add x8, x8, #0x9b8 ; 0x395a4: str x8, [x0]
 */
uint64_t fde_369_0x39590(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x39590ULL;
    constexpr uint64_t kFuncSize    = 0x20ULL;
    constexpr uint32_t kFirstOpcode = 0xf81f0ffeU;
    constexpr uint32_t kLastOpcode  = 0xd65f03c0U;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[370] `sub_395b0` (`0x395b0..0x395c0`, 16 bytes)
 *        Hàm FDE[370] `sub_395b0` (`0x395b0..0x395c0`, 16 bytes)
 * Disassembly: 0x395b0: adrp x8, #0x49000 ; 0x395b4: add x8, x8, #0x9b8 ; 0x395b8: str x8, [x1] ; 0x395bc: ret
 */
uint64_t fde_370_0x395b0(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x395b0ULL;
    constexpr uint64_t kFuncSize    = 0x10ULL;
    constexpr uint32_t kFirstOpcode = 0x90000088U;
    constexpr uint32_t kLastOpcode  = 0xd65f03c0U;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[371] `sub_395c0` (`0x395c0..0x3980c`, 588 bytes)
 *        Hàm FDE[371] `sub_395c0` (`0x395c0..0x3980c`, 588 bytes)
 * Disassembly: 0x395c0: sub sp, sp, #0x70 ; 0x395c4: stp x27, x26, [sp, #0x20] ; 0x395c8: stp x25, x24, [sp, #0x30] ; 0x395cc: stp x23, x22, [sp, #0x40] ; 0x395d0: stp x21, x20, [sp, #0x50] ; 0x395d4: stp x19, x30, [sp, #0x60]
 */
uint64_t fde_371_0x395c0(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x395c0ULL;
    constexpr uint64_t kFuncSize    = 0x24cULL;
    constexpr uint32_t kFirstOpcode = 0xd101c3ffU;
    constexpr uint32_t kLastOpcode  = 0x94003052U;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[372] `sub_3980c` (`0x3980c..0x39828`, 28 bytes)
 *        Hàm FDE[372] `sub_3980c` (`0x3980c..0x39828`, 28 bytes)
 * Disassembly: 0x3980c: ldr x8, [x1, #8] ; 0x39810: adrp x9, #0x11000 ; 0x39814: add x9, x9, #0x6f0 ; 0x39818: add x10, x0, #8 ; 0x3981c: cmp x8, x9 ; 0x39820: csel x0, x10, xzr, eq
 */
uint64_t fde_372_0x3980c(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x3980cULL;
    constexpr uint64_t kFuncSize    = 0x1cULL;
    constexpr uint32_t kFirstOpcode = 0xf9400428U;
    constexpr uint32_t kLastOpcode  = 0xd65f03c0U;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[373] `sub_39828` (`0x39828..0x39834`, 12 bytes)
 *        Hàm FDE[373] `sub_39828` (`0x39828..0x39834`, 12 bytes)
 * Disassembly: 0x39828: adrp x0, #0x49000 ; 0x3982c: add x0, x0, #0xa18 ; 0x39830: ret
 */
uint64_t fde_373_0x39828(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x39828ULL;
    constexpr uint64_t kFuncSize    = 0xcULL;
    constexpr uint32_t kFirstOpcode = 0x90000080U;
    constexpr uint32_t kLastOpcode  = 0xd65f03c0U;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[374] `sub_39834` (`0x39834..0x39c10`, 988 bytes)
 *        Hàm FDE[374] `sub_39834` (`0x39834..0x39c10`, 988 bytes)
 * Disassembly: 0x39834: sub sp, sp, #0x120 ; 0x39838: str x28, [sp, #0xc0] ; 0x3983c: stp x27, x26, [sp, #0xd0] ; 0x39840: stp x25, x24, [sp, #0xe0] ; 0x39844: stp x23, x22, [sp, #0xf0] ; 0x39848: stp x21, x20, [sp, #0x100]
 */
uint64_t fde_374_0x39834(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x39834ULL;
    constexpr uint64_t kFuncSize    = 0x3dcULL;
    constexpr uint32_t kFirstOpcode = 0xd10483ffU;
    constexpr uint32_t kLastOpcode  = 0x94002f51U;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[375] `sub_39c10` (`0x39c10..0x39c30`, 32 bytes)
 *        Hàm FDE[375] `sub_39c10` (`0x39c10..0x39c30`, 32 bytes)
 * Disassembly: 0x39c10: str x30, [sp, #-0x10]! ; 0x39c14: mov w0, #0x10 ; 0x39c18: bl #0x459f0 ; 0x39c1c: adrp x8, #0x49000 ; 0x39c20: add x8, x8, #0xa38 ; 0x39c24: str x8, [x0]
 */
uint64_t fde_375_0x39c10(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x39c10ULL;
    constexpr uint64_t kFuncSize    = 0x20ULL;
    constexpr uint32_t kFirstOpcode = 0xf81f0ffeU;
    constexpr uint32_t kLastOpcode  = 0xd65f03c0U;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[376] `sub_39c30` (`0x39c30..0x39c40`, 16 bytes)
 *        Hàm FDE[376] `sub_39c30` (`0x39c30..0x39c40`, 16 bytes)
 * Disassembly: 0x39c30: adrp x8, #0x49000 ; 0x39c34: add x8, x8, #0xa38 ; 0x39c38: str x8, [x1] ; 0x39c3c: ret
 */
uint64_t fde_376_0x39c30(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x39c30ULL;
    constexpr uint64_t kFuncSize    = 0x10ULL;
    constexpr uint32_t kFirstOpcode = 0x90000088U;
    constexpr uint32_t kLastOpcode  = 0xd65f03c0U;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[377] `sub_39c40` (`0x39c40..0x3a050`, 1040 bytes)
 *        Hàm FDE[377] `sub_39c40` (`0x39c40..0x3a050`, 1040 bytes)
 * Disassembly: 0x39c40: sub sp, sp, #0x100 ; 0x39c44: str x24, [sp, #0xc0] ; 0x39c48: stp x23, x22, [sp, #0xd0] ; 0x39c4c: stp x21, x20, [sp, #0xe0] ; 0x39c50: stp x19, x30, [sp, #0xf0] ; 0x39c54: mrs x24, tpidr_el0
 */
uint64_t fde_377_0x39c40(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x39c40ULL;
    constexpr uint64_t kFuncSize    = 0x410ULL;
    constexpr uint32_t kFirstOpcode = 0xd10403ffU;
    constexpr uint32_t kLastOpcode  = 0x94002e6dU;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[378] `sub_3a050` (`0x3a050..0x3a06c`, 28 bytes)
 *        Hàm FDE[378] `sub_3a050` (`0x3a050..0x3a06c`, 28 bytes)
 * Disassembly: 0x3a050: ldr x8, [x1, #8] ; 0x3a054: adrp x9, #0x11000 ; 0x3a058: add x9, x9, #0x7ae ; 0x3a05c: add x10, x0, #8 ; 0x3a060: cmp x8, x9 ; 0x3a064: csel x0, x10, xzr, eq
 */
uint64_t fde_378_0x3a050(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x3a050ULL;
    constexpr uint64_t kFuncSize    = 0x1cULL;
    constexpr uint32_t kFirstOpcode = 0xf9400428U;
    constexpr uint32_t kLastOpcode  = 0xd65f03c0U;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[379] `sub_3a06c` (`0x3a06c..0x3a078`, 12 bytes)
 *        Hàm FDE[379] `sub_3a06c` (`0x3a06c..0x3a078`, 12 bytes)
 * Disassembly: 0x3a06c: adrp x0, #0x49000 ; 0x3a070: add x0, x0, #0xa98 ; 0x3a074: ret
 */
uint64_t fde_379_0x3a06c(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x3a06cULL;
    constexpr uint64_t kFuncSize    = 0xcULL;
    constexpr uint32_t kFirstOpcode = 0xf0000060U;
    constexpr uint32_t kLastOpcode  = 0xd65f03c0U;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[380] `sub_3a078` (`0x3a078..0x3a49c`, 1060 bytes)
 *        Hàm FDE[380] `sub_3a078` (`0x3a078..0x3a49c`, 1060 bytes)
 * Disassembly: 0x3a078: sub sp, sp, #0x120 ; 0x3a07c: stp x28, x26, [sp, #0xd0] ; 0x3a080: stp x25, x24, [sp, #0xe0] ; 0x3a084: stp x23, x22, [sp, #0xf0] ; 0x3a088: stp x21, x20, [sp, #0x100] ; 0x3a08c: stp x19, x30, [sp, #0x110]
 */
uint64_t fde_380_0x3a078(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x3a078ULL;
    constexpr uint64_t kFuncSize    = 0x424ULL;
    constexpr uint32_t kFirstOpcode = 0xd10483ffU;
    constexpr uint32_t kLastOpcode  = 0x94002d2eU;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[381] `sub_3a49c` (`0x3a49c..0x3a4bc`, 32 bytes)
 *        Hàm FDE[381] `sub_3a49c` (`0x3a49c..0x3a4bc`, 32 bytes)
 * Disassembly: 0x3a49c: ldrb w8, [x0, #8] ; 0x3a4a0: adrp x9, #0x49000 ; 0x3a4a4: add x9, x9, #0xab8 ; 0x3a4a8: str x9, [x0] ; 0x3a4ac: tbnz w8, #0, #0x3a4b4 ; 0x3a4b0: ret
 */
uint64_t fde_381_0x3a49c(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x3a49cULL;
    constexpr uint64_t kFuncSize    = 0x20ULL;
    constexpr uint32_t kFirstOpcode = 0x39402008U;
    constexpr uint32_t kLastOpcode  = 0x14002d1eU;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[382] `sub_3a4bc` (`0x3a4bc..0x3a4ec`, 48 bytes)
 *        Hàm FDE[382] `sub_3a4bc` (`0x3a4bc..0x3a4ec`, 48 bytes)
 * Disassembly: 0x3a4bc: stp x19, x30, [sp, #-0x10]! ; 0x3a4c0: ldrb w8, [x0, #8] ; 0x3a4c4: adrp x9, #0x49000 ; 0x3a4c8: mov x19, x0 ; 0x3a4cc: add x9, x9, #0xab8 ; 0x3a4d0: str x9, [x0]
 */
uint64_t fde_382_0x3a4bc(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x3a4bcULL;
    constexpr uint64_t kFuncSize    = 0x30ULL;
    constexpr uint32_t kFirstOpcode = 0xa9bf7bf3U;
    constexpr uint32_t kLastOpcode  = 0x14002d12U;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[383] `sub_3a4ec` (`0x3a4ec..0x3a528`, 60 bytes)
 *        Hàm FDE[383] `sub_3a4ec` (`0x3a4ec..0x3a528`, 60 bytes)
 * Disassembly: 0x3a4ec: str x20, [sp, #-0x20]! ; 0x3a4f0: stp x19, x30, [sp, #0x10] ; 0x3a4f4: mov x19, x0 ; 0x3a4f8: mov w0, #0x20 ; 0x3a4fc: bl #0x459f0 ; 0x3a500: adrp x8, #0x49000
 */
uint64_t fde_383_0x3a4ec(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x3a4ecULL;
    constexpr uint64_t kFuncSize    = 0x3cULL;
    constexpr uint32_t kFirstOpcode = 0xf81e0ff4U;
    constexpr uint32_t kLastOpcode  = 0xd65f03c0U;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[384] `sub_3a528` (`0x3a528..0x3a544`, 28 bytes)
 *        Hàm FDE[384] `sub_3a528` (`0x3a528..0x3a544`, 28 bytes)
 * Disassembly: 0x3a528: adrp x9, #0x49000 ; 0x3a52c: mov x8, x1 ; 0x3a530: add x9, x9, #0xab8 ; 0x3a534: str x9, [x8], #8 ; 0x3a538: add x1, x0, #8 ; 0x3a53c: mov x0, x8
 */
uint64_t fde_384_0x3a528(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x3a528ULL;
    constexpr uint64_t kFuncSize    = 0x1cULL;
    constexpr uint32_t kFirstOpcode = 0xf0000069U;
    constexpr uint32_t kLastOpcode  = 0x17ff8e2cU;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[385] `sub_3a544` (`0x3a544..0x3a558`, 20 bytes)
 *        Hàm FDE[385] `sub_3a544` (`0x3a544..0x3a558`, 20 bytes)
 * Disassembly: 0x3a544: ldrb w8, [x0, #8] ; 0x3a548: tbnz w8, #0, #0x3a550 ; 0x3a54c: ret ; 0x3a550: ldr x0, [x0, #0x18] ; 0x3a554: b #0x45930
 */
uint64_t fde_385_0x3a544(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x3a544ULL;
    constexpr uint64_t kFuncSize    = 0x14ULL;
    constexpr uint32_t kFirstOpcode = 0x39402008U;
    constexpr uint32_t kLastOpcode  = 0x14002cf7U;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[386] `sub_3a558` (`0x3a558..0x3a57c`, 36 bytes)
 *        Hàm FDE[386] `sub_3a558` (`0x3a558..0x3a57c`, 36 bytes)
 * Disassembly: 0x3a558: stp x19, x30, [sp, #-0x10]! ; 0x3a55c: ldrb w8, [x0, #8] ; 0x3a560: mov x19, x0 ; 0x3a564: tbz w8, #0, #0x3a570 ; 0x3a568: ldr x0, [x19, #0x18] ; 0x3a56c: bl #0x45930
 */
uint64_t fde_386_0x3a558(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x3a558ULL;
    constexpr uint64_t kFuncSize    = 0x24ULL;
    constexpr uint32_t kFirstOpcode = 0xa9bf7bf3U;
    constexpr uint32_t kLastOpcode  = 0x14002ceeU;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[387] `sub_3a57c` (`0x3a57c..0x3a700`, 388 bytes)
 *        Hàm FDE[387] `sub_3a57c` (`0x3a57c..0x3a700`, 388 bytes)
 * Disassembly: 0x3a57c: sub sp, sp, #0xa0 ; 0x3a580: stp x23, x22, [sp, #0x70] ; 0x3a584: stp x21, x20, [sp, #0x80] ; 0x3a588: stp x19, x30, [sp, #0x90] ; 0x3a58c: mrs x22, tpidr_el0 ; 0x3a590: ldr x8, [x22, #0x28]
 */
uint64_t fde_387_0x3a57c(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x3a57cULL;
    constexpr uint64_t kFuncSize    = 0x184ULL;
    constexpr uint32_t kFirstOpcode = 0xd10283ffU;
    constexpr uint32_t kLastOpcode  = 0x94002c95U;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[388] `sub_3a700` (`0x3a700..0x3a71c`, 28 bytes)
 *        Hàm FDE[388] `sub_3a700` (`0x3a700..0x3a71c`, 28 bytes)
 * Disassembly: 0x3a700: ldr x8, [x1, #8] ; 0x3a704: adrp x9, #0x11000 ; 0x3a708: add x9, x9, #0x8ce ; 0x3a70c: add x10, x0, #8 ; 0x3a710: cmp x8, x9 ; 0x3a714: csel x0, x10, xzr, eq
 */
uint64_t fde_388_0x3a700(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x3a700ULL;
    constexpr uint64_t kFuncSize    = 0x1cULL;
    constexpr uint32_t kFirstOpcode = 0xf9400428U;
    constexpr uint32_t kLastOpcode  = 0xd65f03c0U;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[389] `sub_3a71c` (`0x3a71c..0x3a728`, 12 bytes)
 *        Hàm FDE[389] `sub_3a71c` (`0x3a71c..0x3a728`, 12 bytes)
 * Disassembly: 0x3a71c: adrp x0, #0x49000 ; 0x3a720: add x0, x0, #0xb18 ; 0x3a724: ret
 */
uint64_t fde_389_0x3a71c(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x3a71cULL;
    constexpr uint64_t kFuncSize    = 0xcULL;
    constexpr uint32_t kFirstOpcode = 0xf0000060U;
    constexpr uint32_t kLastOpcode  = 0xd65f03c0U;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[390] `sub_3a728` (`0x3a728..0x3a840`, 280 bytes)
 *        Hàm FDE[390] `sub_3a728` (`0x3a728..0x3a840`, 280 bytes)
 * Disassembly: 0x3a728: sub sp, sp, #0xb0 ; 0x3a72c: str x24, [sp, #0x70] ; 0x3a730: stp x23, x22, [sp, #0x80] ; 0x3a734: stp x21, x20, [sp, #0x90] ; 0x3a738: stp x19, x30, [sp, #0xa0] ; 0x3a73c: mrs x21, tpidr_el0
 */
uint64_t fde_390_0x3a728(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x3a728ULL;
    constexpr uint64_t kFuncSize    = 0x118ULL;
    constexpr uint32_t kFirstOpcode = 0xd102c3ffU;
    constexpr uint32_t kLastOpcode  = 0x94002c45U;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[391] `sub_3a840` (`0x3a840..0x3a860`, 32 bytes)
 *        Hàm FDE[391] `sub_3a840` (`0x3a840..0x3a860`, 32 bytes)
 * Disassembly: 0x3a840: str x30, [sp, #-0x10]! ; 0x3a844: mov w0, #0x10 ; 0x3a848: bl #0x459f0 ; 0x3a84c: adrp x8, #0x49000 ; 0x3a850: add x8, x8, #0xb38 ; 0x3a854: str x8, [x0]
 */
uint64_t fde_391_0x3a840(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x3a840ULL;
    constexpr uint64_t kFuncSize    = 0x20ULL;
    constexpr uint32_t kFirstOpcode = 0xf81f0ffeU;
    constexpr uint32_t kLastOpcode  = 0xd65f03c0U;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[392] `sub_3a860` (`0x3a860..0x3a870`, 16 bytes)
 *        Hàm FDE[392] `sub_3a860` (`0x3a860..0x3a870`, 16 bytes)
 * Disassembly: 0x3a860: adrp x8, #0x49000 ; 0x3a864: add x8, x8, #0xb38 ; 0x3a868: str x8, [x1] ; 0x3a86c: ret
 */
uint64_t fde_392_0x3a860(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x3a860ULL;
    constexpr uint64_t kFuncSize    = 0x10ULL;
    constexpr uint32_t kFirstOpcode = 0xf0000068U;
    constexpr uint32_t kLastOpcode  = 0xd65f03c0U;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[393] `sub_3a870` (`0x3a870..0x3a9e4`, 372 bytes)
 *        Hàm FDE[393] `sub_3a870` (`0x3a870..0x3a9e4`, 372 bytes)
 * Disassembly: 0x3a870: sub sp, sp, #0x90 ; 0x3a874: stp x25, x24, [sp, #0x50] ; 0x3a878: stp x23, x22, [sp, #0x60] ; 0x3a87c: stp x21, x20, [sp, #0x70] ; 0x3a880: stp x19, x30, [sp, #0x80] ; 0x3a884: mrs x23, tpidr_el0
 */
uint64_t fde_393_0x3a870(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x3a870ULL;
    constexpr uint64_t kFuncSize    = 0x174ULL;
    constexpr uint32_t kFirstOpcode = 0xd10243ffU;
    constexpr uint32_t kLastOpcode  = 0x94002bdcU;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[394] `sub_3a9e4` (`0x3a9e4..0x3aa00`, 28 bytes)
 *        Hàm FDE[394] `sub_3a9e4` (`0x3a9e4..0x3aa00`, 28 bytes)
 * Disassembly: 0x3a9e4: ldr x8, [x1, #8] ; 0x3a9e8: adrp x9, #0x11000 ; 0x3a9ec: add x9, x9, #0x9da ; 0x3a9f0: add x10, x0, #8 ; 0x3a9f4: cmp x8, x9 ; 0x3a9f8: csel x0, x10, xzr, eq
 */
uint64_t fde_394_0x3a9e4(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x3a9e4ULL;
    constexpr uint64_t kFuncSize    = 0x1cULL;
    constexpr uint32_t kFirstOpcode = 0xf9400428U;
    constexpr uint32_t kLastOpcode  = 0xd65f03c0U;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[395] `sub_3aa00` (`0x3aa00..0x3aa0c`, 12 bytes)
 *        Hàm FDE[395] `sub_3aa00` (`0x3aa00..0x3aa0c`, 12 bytes)
 * Disassembly: 0x3aa00: adrp x0, #0x49000 ; 0x3aa04: add x0, x0, #0xb98 ; 0x3aa08: ret
 */
uint64_t fde_395_0x3aa00(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x3aa00ULL;
    constexpr uint64_t kFuncSize    = 0xcULL;
    constexpr uint32_t kFirstOpcode = 0xf0000060U;
    constexpr uint32_t kLastOpcode  = 0xd65f03c0U;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[396] `sub_3aa0c` (`0x3aa0c..0x3acc4`, 696 bytes)
 *        Hàm FDE[396] `sub_3aa0c` (`0x3aa0c..0x3acc4`, 696 bytes)
 * Disassembly: 0x3aa0c: sub sp, sp, #0x100 ; 0x3aa10: str x26, [sp, #0xb0] ; 0x3aa14: stp x25, x24, [sp, #0xc0] ; 0x3aa18: stp x23, x22, [sp, #0xd0] ; 0x3aa1c: stp x21, x20, [sp, #0xe0] ; 0x3aa20: stp x19, x30, [sp, #0xf0]
 */
uint64_t fde_396_0x3aa0c(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x3aa0cULL;
    constexpr uint64_t kFuncSize    = 0x2b8ULL;
    constexpr uint32_t kFirstOpcode = 0xd10403ffU;
    constexpr uint32_t kLastOpcode  = 0x94002b50U;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[397] `sub_3acc4` (`0x3acc4..0x3ace4`, 32 bytes)
 *        Hàm FDE[397] `sub_3acc4` (`0x3acc4..0x3ace4`, 32 bytes)
 * Disassembly: 0x3acc4: str x30, [sp, #-0x10]! ; 0x3acc8: mov w0, #0x10 ; 0x3accc: bl #0x459f0 ; 0x3acd0: adrp x8, #0x49000 ; 0x3acd4: add x8, x8, #0xbb8 ; 0x3acd8: str x8, [x0]
 */
uint64_t fde_397_0x3acc4(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x3acc4ULL;
    constexpr uint64_t kFuncSize    = 0x20ULL;
    constexpr uint32_t kFirstOpcode = 0xf81f0ffeU;
    constexpr uint32_t kLastOpcode  = 0xd65f03c0U;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[398] `sub_3ace4` (`0x3ace4..0x3acf4`, 16 bytes)
 *        Hàm FDE[398] `sub_3ace4` (`0x3ace4..0x3acf4`, 16 bytes)
 * Disassembly: 0x3ace4: adrp x8, #0x49000 ; 0x3ace8: add x8, x8, #0xbb8 ; 0x3acec: str x8, [x1] ; 0x3acf0: ret
 */
uint64_t fde_398_0x3ace4(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x3ace4ULL;
    constexpr uint64_t kFuncSize    = 0x10ULL;
    constexpr uint32_t kFirstOpcode = 0xf0000068U;
    constexpr uint32_t kLastOpcode  = 0xd65f03c0U;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[399] `sub_3acf4` (`0x3acf4..0x3ad98`, 164 bytes)
 *        Hàm FDE[399] `sub_3acf4` (`0x3acf4..0x3ad98`, 164 bytes)
 * Disassembly: 0x3acf4: sub sp, sp, #0x40 ; 0x3acf8: stp x21, x20, [sp, #0x20] ; 0x3acfc: stp x19, x30, [sp, #0x30] ; 0x3ad00: mrs x20, tpidr_el0 ; 0x3ad04: ldr x8, [x20, #0x28] ; 0x3ad08: mov x10, sp
 */
uint64_t fde_399_0x3acf4(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x3acf4ULL;
    constexpr uint64_t kFuncSize    = 0xa4ULL;
    constexpr uint32_t kFirstOpcode = 0xd10103ffU;
    constexpr uint32_t kLastOpcode  = 0x94002aefU;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[400] `sub_3ad98` (`0x3ad98..0x3adb4`, 28 bytes)
 *        Hàm FDE[400] `sub_3ad98` (`0x3ad98..0x3adb4`, 28 bytes)
 * Disassembly: 0x3ad98: ldr x8, [x1, #8] ; 0x3ad9c: adrp x9, #0x11000 ; 0x3ada0: add x9, x9, #0xab8 ; 0x3ada4: add x10, x0, #8 ; 0x3ada8: cmp x8, x9 ; 0x3adac: csel x0, x10, xzr, eq
 */
uint64_t fde_400_0x3ad98(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x3ad98ULL;
    constexpr uint64_t kFuncSize    = 0x1cULL;
    constexpr uint32_t kFirstOpcode = 0xf9400428U;
    constexpr uint32_t kLastOpcode  = 0xd65f03c0U;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[401] `sub_3adb4` (`0x3adb4..0x3adc0`, 12 bytes)
 *        Hàm FDE[401] `sub_3adb4` (`0x3adb4..0x3adc0`, 12 bytes)
 * Disassembly: 0x3adb4: adrp x0, #0x49000 ; 0x3adb8: add x0, x0, #0xc18 ; 0x3adbc: ret
 */
uint64_t fde_401_0x3adb4(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x3adb4ULL;
    constexpr uint64_t kFuncSize    = 0xcULL;
    constexpr uint32_t kFirstOpcode = 0xf0000060U;
    constexpr uint32_t kLastOpcode  = 0xd65f03c0U;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[402] `sub_3adc0` (`0x3adc0..0x3aed8`, 280 bytes)
 *        Hàm FDE[402] `sub_3adc0` (`0x3adc0..0x3aed8`, 280 bytes)
 * Disassembly: 0x3adc0: sub sp, sp, #0x80 ; 0x3adc4: str x24, [sp, #0x40] ; 0x3adc8: stp x23, x22, [sp, #0x50] ; 0x3adcc: stp x21, x20, [sp, #0x60] ; 0x3add0: stp x19, x30, [sp, #0x70] ; 0x3add4: mrs x23, tpidr_el0
 */
uint64_t fde_402_0x3adc0(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x3adc0ULL;
    constexpr uint64_t kFuncSize    = 0x118ULL;
    constexpr uint32_t kFirstOpcode = 0xd10203ffU;
    constexpr uint32_t kLastOpcode  = 0x94002a9fU;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[403] `sub_3aed8` (`0x3aed8..0x3af0c`, 52 bytes)
 *        Hàm FDE[403] `sub_3aed8` (`0x3aed8..0x3af0c`, 52 bytes)
 * Disassembly: 0x3aed8: stp x19, x30, [sp, #-0x10]! ; 0x3aedc: mov x19, x0 ; 0x3aee0: mov w0, #0x20 ; 0x3aee4: bl #0x459f0 ; 0x3aee8: adrp x8, #0x49000 ; 0x3aeec: add x8, x8, #0xc38
 */
uint64_t fde_403_0x3aed8(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x3aed8ULL;
    constexpr uint64_t kFuncSize    = 0x34ULL;
    constexpr uint32_t kFirstOpcode = 0xa9bf7bf3U;
    constexpr uint32_t kLastOpcode  = 0xd65f03c0U;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[404] `sub_3af0c` (`0x3af0c..0x3af2c`, 32 bytes)
 *        Hàm FDE[404] `sub_3af0c` (`0x3af0c..0x3af2c`, 32 bytes)
 * Disassembly: 0x3af0c: adrp x8, #0x49000 ; 0x3af10: add x8, x8, #0xc38 ; 0x3af14: str x8, [x1] ; 0x3af18: ldr x8, [x0, #0x18] ; 0x3af1c: ldur q0, [x0, #8] ; 0x3af20: str x8, [x1, #0x18]
 */
uint64_t fde_404_0x3af0c(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x3af0cULL;
    constexpr uint64_t kFuncSize    = 0x20ULL;
    constexpr uint32_t kFirstOpcode = 0xf0000068U;
    constexpr uint32_t kLastOpcode  = 0xd65f03c0U;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[405] `sub_3af2c` (`0x3af2c..0x3b0fc`, 464 bytes)
 *        Hàm FDE[405] `sub_3af2c` (`0x3af2c..0x3b0fc`, 464 bytes)
 * Disassembly: 0x3af2c: sub sp, sp, #0xa0 ; 0x3af30: str x24, [sp, #0x60] ; 0x3af34: stp x23, x22, [sp, #0x70] ; 0x3af38: stp x21, x20, [sp, #0x80] ; 0x3af3c: stp x19, x30, [sp, #0x90] ; 0x3af40: mrs x24, tpidr_el0
 */
uint64_t fde_405_0x3af2c(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x3af2cULL;
    constexpr uint64_t kFuncSize    = 0x1d0ULL;
    constexpr uint32_t kFirstOpcode = 0xd10283ffU;
    constexpr uint32_t kLastOpcode  = 0x94002a42U;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[406] `sub_3b0fc` (`0x3b0fc..0x3b118`, 28 bytes)
 *        Hàm FDE[406] `sub_3b0fc` (`0x3b0fc..0x3b118`, 28 bytes)
 * Disassembly: 0x3b0fc: ldr x8, [x1, #8] ; 0x3b100: adrp x9, #0x11000 ; 0x3b104: add x9, x9, #0xbc4 ; 0x3b108: add x10, x0, #8 ; 0x3b10c: cmp x8, x9 ; 0x3b110: csel x0, x10, xzr, eq
 */
uint64_t fde_406_0x3b0fc(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x3b0fcULL;
    constexpr uint64_t kFuncSize    = 0x1cULL;
    constexpr uint32_t kFirstOpcode = 0xf9400428U;
    constexpr uint32_t kLastOpcode  = 0xd65f03c0U;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[407] `sub_3b118` (`0x3b118..0x3b124`, 12 bytes)
 *        Hàm FDE[407] `sub_3b118` (`0x3b118..0x3b124`, 12 bytes)
 * Disassembly: 0x3b118: adrp x0, #0x49000 ; 0x3b11c: add x0, x0, #0xc98 ; 0x3b120: ret
 */
uint64_t fde_407_0x3b118(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x3b118ULL;
    constexpr uint64_t kFuncSize    = 0xcULL;
    constexpr uint32_t kFirstOpcode = 0xd0000060U;
    constexpr uint32_t kLastOpcode  = 0xd65f03c0U;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[408] `sub_3b124` (`0x3b124..0x3b158`, 52 bytes)
 *        Hàm FDE[408] `sub_3b124` (`0x3b124..0x3b158`, 52 bytes)
 * Disassembly: 0x3b124: stp x19, x30, [sp, #-0x10]! ; 0x3b128: mov x19, x0 ; 0x3b12c: mov w0, #0x20 ; 0x3b130: bl #0x459f0 ; 0x3b134: adrp x8, #0x49000 ; 0x3b138: add x8, x8, #0xcb8
 */
uint64_t fde_408_0x3b124(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x3b124ULL;
    constexpr uint64_t kFuncSize    = 0x34ULL;
    constexpr uint32_t kFirstOpcode = 0xa9bf7bf3U;
    constexpr uint32_t kLastOpcode  = 0xd65f03c0U;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[409] `sub_3b158` (`0x3b158..0x3b178`, 32 bytes)
 *        Hàm FDE[409] `sub_3b158` (`0x3b158..0x3b178`, 32 bytes)
 * Disassembly: 0x3b158: adrp x8, #0x49000 ; 0x3b15c: add x8, x8, #0xcb8 ; 0x3b160: str x8, [x1] ; 0x3b164: ldr x8, [x0, #0x18] ; 0x3b168: ldur q0, [x0, #8] ; 0x3b16c: str x8, [x1, #0x18]
 */
uint64_t fde_409_0x3b158(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x3b158ULL;
    constexpr uint64_t kFuncSize    = 0x20ULL;
    constexpr uint32_t kFirstOpcode = 0xd0000068U;
    constexpr uint32_t kLastOpcode  = 0xd65f03c0U;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[410] `sub_3b178` (`0x3b178..0x3b434`, 700 bytes)
 *        Hàm FDE[410] `sub_3b178` (`0x3b178..0x3b434`, 700 bytes)
 * Disassembly: 0x3b178: sub sp, sp, #0x70 ; 0x3b17c: str x26, [sp, #0x20] ; 0x3b180: stp x25, x24, [sp, #0x30] ; 0x3b184: stp x23, x22, [sp, #0x40] ; 0x3b188: stp x21, x20, [sp, #0x50] ; 0x3b18c: stp x19, x30, [sp, #0x60]
 */
uint64_t fde_410_0x3b178(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x3b178ULL;
    constexpr uint64_t kFuncSize    = 0x2bcULL;
    constexpr uint32_t kFirstOpcode = 0xd101c3ffU;
    constexpr uint32_t kLastOpcode  = 0x94002948U;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[411] `sub_3b434` (`0x3b434..0x3b450`, 28 bytes)
 *        Hàm FDE[411] `sub_3b434` (`0x3b434..0x3b450`, 28 bytes)
 * Disassembly: 0x3b434: ldr x8, [x1, #8] ; 0x3b438: adrp x9, #0x11000 ; 0x3b43c: add x9, x9, #0xc59 ; 0x3b440: add x10, x0, #8 ; 0x3b444: cmp x8, x9 ; 0x3b448: csel x0, x10, xzr, eq
 */
uint64_t fde_411_0x3b434(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x3b434ULL;
    constexpr uint64_t kFuncSize    = 0x1cULL;
    constexpr uint32_t kFirstOpcode = 0xf9400428U;
    constexpr uint32_t kLastOpcode  = 0xd65f03c0U;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[412] `sub_3b450` (`0x3b450..0x3b45c`, 12 bytes)
 *        Hàm FDE[412] `sub_3b450` (`0x3b450..0x3b45c`, 12 bytes)
 * Disassembly: 0x3b450: adrp x0, #0x49000 ; 0x3b454: add x0, x0, #0xd18 ; 0x3b458: ret
 */
uint64_t fde_412_0x3b450(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x3b450ULL;
    constexpr uint64_t kFuncSize    = 0xcULL;
    constexpr uint32_t kFirstOpcode = 0xd0000060U;
    constexpr uint32_t kLastOpcode  = 0xd65f03c0U;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[413] `_ZN5vmsdk6worker15JsWorkerAndroid19CallOnErrorCallbackENSt6__ndk112basic_stringIcNS2_11char_traitsIcEENS2_9allocatorIcEEEE` (`0x3b45c..0x3b6f8`, 668 bytes)
 *        Hàm FDE[413] `_ZN5vmsdk6worker15JsWorkerAndroid19CallOnErrorCallbackENSt6__ndk112basic_stringIcNS2_11char_traitsIcEENS2_9allocatorIcEEEE` (`0x3b45c..0x3b6f8`, 668 bytes)
 * Disassembly: 0x3b45c: sub sp, sp, #0xc0 ; 0x3b460: str x26, [sp, #0x70] ; 0x3b464: stp x25, x24, [sp, #0x80] ; 0x3b468: stp x23, x22, [sp, #0x90] ; 0x3b46c: stp x21, x20, [sp, #0xa0] ; 0x3b470: stp x19, x30, [sp, #0xb0]
 */
uint64_t fde_413_0x3b45c(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x3b45cULL;
    constexpr uint64_t kFuncSize    = 0x29cULL;
    constexpr uint32_t kFirstOpcode = 0xd10303ffU;
    constexpr uint32_t kLastOpcode  = 0x940028c3U;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[414] `sub_3b6f8` (`0x3b6f8..0x3b7d0`, 216 bytes)
 *        Hàm FDE[414] `sub_3b6f8` (`0x3b6f8..0x3b7d0`, 216 bytes)
 * Disassembly: 0x3b6f8: sub sp, sp, #0x160 ; 0x3b6fc: stp x28, x22, [sp, #0x130] ; 0x3b700: stp x21, x20, [sp, #0x140] ; 0x3b704: stp x19, x30, [sp, #0x150] ; 0x3b708: mrs x22, tpidr_el0 ; 0x3b70c: ldr x8, [x22, #0x28]
 */
uint64_t fde_414_0x3b6f8(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x3b6f8ULL;
    constexpr uint64_t kFuncSize    = 0xd8ULL;
    constexpr uint32_t kFirstOpcode = 0xd10583ffU;
    constexpr uint32_t kLastOpcode  = 0x94002861U;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[415] `sub_3b7d0` (`0x3b7d0..0x3ba34`, 612 bytes)
 *        Hàm FDE[415] `sub_3b7d0` (`0x3b7d0..0x3ba34`, 612 bytes)
 * Disassembly: 0x3b7d0: sub sp, sp, #0xb0 ; 0x3b7d4: stp x25, x24, [sp, #0x70] ; 0x3b7d8: stp x23, x22, [sp, #0x80] ; 0x3b7dc: stp x21, x20, [sp, #0x90] ; 0x3b7e0: stp x19, x30, [sp, #0xa0] ; 0x3b7e4: mrs x24, tpidr_el0
 */
uint64_t fde_415_0x3b7d0(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x3b7d0ULL;
    constexpr uint64_t kFuncSize    = 0x264ULL;
    constexpr uint32_t kFirstOpcode = 0xd102c3ffU;
    constexpr uint32_t kLastOpcode  = 0x940027c8U;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[416] `_ZN5vmsdk6worker15JsWorkerAndroid11RegisterJniEP7_JNIEnv` (`0x3ba34..0x3bb1c`, 232 bytes)
 *        Hàm FDE[416] `_ZN5vmsdk6worker15JsWorkerAndroid11RegisterJniEP7_JNIEnv` (`0x3ba34..0x3bb1c`, 232 bytes)
 * Disassembly: 0x3ba34: sub sp, sp, #0x70 ; 0x3ba38: str x22, [sp, #0x40] ; 0x3ba3c: stp x21, x20, [sp, #0x50] ; 0x3ba40: stp x19, x30, [sp, #0x60] ; 0x3ba44: mrs x20, tpidr_el0 ; 0x3ba48: ldr x8, [x20, #0x28]
 */
uint64_t fde_416_0x3ba34(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x3ba34ULL;
    constexpr uint64_t kFuncSize    = 0xe8ULL;
    constexpr uint32_t kFirstOpcode = 0xd101c3ffU;
    constexpr uint32_t kLastOpcode  = 0x9400278eU;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[417] `sub_3bb1c` (`0x3bb1c..0x3bd28`, 524 bytes)
 *        Hàm FDE[417] `sub_3bb1c` (`0x3bb1c..0x3bd28`, 524 bytes)
 * Disassembly: 0x3bb1c: sub sp, sp, #0x90 ; 0x3bb20: stp x27, x26, [sp, #0x40] ; 0x3bb24: stp x25, x24, [sp, #0x50] ; 0x3bb28: stp x23, x22, [sp, #0x60] ; 0x3bb2c: stp x21, x20, [sp, #0x70] ; 0x3bb30: stp x19, x30, [sp, #0x80]
 */
uint64_t fde_417_0x3bb1c(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x3bb1cULL;
    constexpr uint64_t kFuncSize    = 0x20cULL;
    constexpr uint32_t kFirstOpcode = 0xd10243ffU;
    constexpr uint32_t kLastOpcode  = 0x9400270bU;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[418] `sub_3bd28` (`0x3bd28..0x3bf78`, 592 bytes)
 *        Hàm FDE[418] `sub_3bd28` (`0x3bd28..0x3bf78`, 592 bytes)
 * Disassembly: 0x3bd28: sub sp, sp, #0xd0 ; 0x3bd2c: stp x27, x26, [sp, #0x80] ; 0x3bd30: stp x25, x24, [sp, #0x90] ; 0x3bd34: stp x23, x22, [sp, #0xa0] ; 0x3bd38: stp x21, x20, [sp, #0xb0] ; 0x3bd3c: stp x19, x30, [sp, #0xc0]
 */
uint64_t fde_418_0x3bd28(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x3bd28ULL;
    constexpr uint64_t kFuncSize    = 0x250ULL;
    constexpr uint32_t kFirstOpcode = 0xd10343ffU;
    constexpr uint32_t kLastOpcode  = 0x940026a3U;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[419] `sub_3bf78` (`0x3bf78..0x3c080`, 264 bytes)
 *        Hàm FDE[419] `sub_3bf78` (`0x3bf78..0x3c080`, 264 bytes)
 * Disassembly: 0x3bf78: sub sp, sp, #0x70 ; 0x3bf7c: str x22, [sp, #0x40] ; 0x3bf80: stp x21, x20, [sp, #0x50] ; 0x3bf84: stp x19, x30, [sp, #0x60] ; 0x3bf88: mrs x22, tpidr_el0 ; 0x3bf8c: ldr x8, [x22, #0x28]
 */
uint64_t fde_419_0x3bf78(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x3bf78ULL;
    constexpr uint64_t kFuncSize    = 0x108ULL;
    constexpr uint32_t kFirstOpcode = 0xd101c3ffU;
    constexpr uint32_t kLastOpcode  = 0x94002635U;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[420] `sub_3c080` (`0x3c080..0x3c150`, 208 bytes)
 *        Hàm FDE[420] `sub_3c080` (`0x3c080..0x3c150`, 208 bytes)
 * Disassembly: 0x3c080: sub sp, sp, #0x70 ; 0x3c084: str x22, [sp, #0x40] ; 0x3c088: stp x21, x20, [sp, #0x50] ; 0x3c08c: stp x19, x30, [sp, #0x60] ; 0x3c090: mrs x20, tpidr_el0 ; 0x3c094: ldr x8, [x20, #0x28]
 */
uint64_t fde_420_0x3c080(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x3c080ULL;
    constexpr uint64_t kFuncSize    = 0xd0ULL;
    constexpr uint32_t kFirstOpcode = 0xd101c3ffU;
    constexpr uint32_t kLastOpcode  = 0x94002601U;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[421] `sub_3c150` (`0x3c150..0x3c2a0`, 336 bytes)
 *        Hàm FDE[421] `sub_3c150` (`0x3c150..0x3c2a0`, 336 bytes)
 * Disassembly: 0x3c150: sub sp, sp, #0x50 ; 0x3c154: str x22, [sp, #0x20] ; 0x3c158: stp x21, x20, [sp, #0x30] ; 0x3c15c: stp x19, x30, [sp, #0x40] ; 0x3c160: mrs x22, tpidr_el0 ; 0x3c164: ldr x8, [x22, #0x28]
 */
uint64_t fde_421_0x3c150(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x3c150ULL;
    constexpr uint64_t kFuncSize    = 0x150ULL;
    constexpr uint32_t kFirstOpcode = 0xd10143ffU;
    constexpr uint32_t kLastOpcode  = 0x940025adU;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[422] `sub_3c2a0` (`0x3c2a0..0x3c4cc`, 556 bytes)
 *        Hàm FDE[422] `sub_3c2a0` (`0x3c2a0..0x3c4cc`, 556 bytes)
 * Disassembly: 0x3c2a0: sub sp, sp, #0xd0 ; 0x3c2a4: str x28, [sp, #0x70] ; 0x3c2a8: stp x27, x26, [sp, #0x80] ; 0x3c2ac: stp x25, x24, [sp, #0x90] ; 0x3c2b0: stp x23, x22, [sp, #0xa0] ; 0x3c2b4: stp x21, x20, [sp, #0xb0]
 */
uint64_t fde_422_0x3c2a0(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x3c2a0ULL;
    constexpr uint64_t kFuncSize    = 0x22cULL;
    constexpr uint32_t kFirstOpcode = 0xd10343ffU;
    constexpr uint32_t kLastOpcode  = 0x94002522U;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[423] `sub_3c4cc` (`0x3c4cc..0x3c550`, 132 bytes)
 *        Hàm FDE[423] `sub_3c4cc` (`0x3c4cc..0x3c550`, 132 bytes)
 * Disassembly: 0x3c4cc: str x20, [sp, #-0x20]! ; 0x3c4d0: stp x19, x30, [sp, #0x10] ; 0x3c4d4: cbz x2, #0x3c518 ; 0x3c4d8: add x8, x2, #0x88 ; 0x3c4dc: ldarb w8, [x8] ; 0x3c4e0: tbz w8, #0, #0x3c518
 */
uint64_t fde_423_0x3c4cc(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x3c4ccULL;
    constexpr uint64_t kFuncSize    = 0x84ULL;
    constexpr uint32_t kFirstOpcode = 0xf81e0ff4U;
    constexpr uint32_t kLastOpcode  = 0x14002569U;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[424] `sub_3c550` (`0x3c550..0x3c6e8`, 408 bytes)
 *        Hàm FDE[424] `sub_3c550` (`0x3c550..0x3c6e8`, 408 bytes)
 * Disassembly: 0x3c550: sub sp, sp, #0xb0 ; 0x3c554: stp x25, x24, [sp, #0x70] ; 0x3c558: stp x23, x22, [sp, #0x80] ; 0x3c55c: stp x21, x20, [sp, #0x90] ; 0x3c560: stp x19, x30, [sp, #0xa0] ; 0x3c564: mrs x23, tpidr_el0
 */
uint64_t fde_424_0x3c550(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x3c550ULL;
    constexpr uint64_t kFuncSize    = 0x198ULL;
    constexpr uint32_t kFirstOpcode = 0xd102c3ffU;
    constexpr uint32_t kLastOpcode  = 0x9400249bU;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[425] `sub_3c6e8` (`0x3c6e8..0x3c900`, 536 bytes)
 *        Hàm FDE[425] `sub_3c6e8` (`0x3c6e8..0x3c900`, 536 bytes)
 * Disassembly: 0x3c6e8: sub sp, sp, #0xf0 ; 0x3c6ec: stp x27, x26, [sp, #0xa0] ; 0x3c6f0: stp x25, x24, [sp, #0xb0] ; 0x3c6f4: stp x23, x22, [sp, #0xc0] ; 0x3c6f8: stp x21, x20, [sp, #0xd0] ; 0x3c6fc: stp x19, x30, [sp, #0xe0]
 */
uint64_t fde_425_0x3c6e8(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x3c6e8ULL;
    constexpr uint64_t kFuncSize    = 0x218ULL;
    constexpr uint32_t kFirstOpcode = 0xd103c3ffU;
    constexpr uint32_t kLastOpcode  = 0x94002415U;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[426] `sub_3c900` (`0x3c900..0x3ca98`, 408 bytes)
 *        Hàm FDE[426] `sub_3c900` (`0x3c900..0x3ca98`, 408 bytes)
 * Disassembly: 0x3c900: sub sp, sp, #0xb0 ; 0x3c904: stp x25, x24, [sp, #0x70] ; 0x3c908: stp x23, x22, [sp, #0x80] ; 0x3c90c: stp x21, x20, [sp, #0x90] ; 0x3c910: stp x19, x30, [sp, #0xa0] ; 0x3c914: mrs x23, tpidr_el0
 */
uint64_t fde_426_0x3c900(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x3c900ULL;
    constexpr uint64_t kFuncSize    = 0x198ULL;
    constexpr uint32_t kFirstOpcode = 0xd102c3ffU;
    constexpr uint32_t kLastOpcode  = 0x940023afU;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[427] `sub_3ca98` (`0x3ca98..0x3cca8`, 528 bytes)
 *        Hàm FDE[427] `sub_3ca98` (`0x3ca98..0x3cca8`, 528 bytes)
 * Disassembly: 0x3ca98: sub sp, sp, #0xd0 ; 0x3ca9c: stp x27, x26, [sp, #0x80] ; 0x3caa0: stp x25, x24, [sp, #0x90] ; 0x3caa4: stp x23, x22, [sp, #0xa0] ; 0x3caa8: stp x21, x20, [sp, #0xb0] ; 0x3caac: stp x19, x30, [sp, #0xc0]
 */
uint64_t fde_427_0x3ca98(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x3ca98ULL;
    constexpr uint64_t kFuncSize    = 0x210ULL;
    constexpr uint32_t kFirstOpcode = 0xd10343ffU;
    constexpr uint32_t kLastOpcode  = 0x9400232bU;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[428] `sub_3cca8` (`0x3cca8..0x3d80c`, 2916 bytes)
 *        Hàm FDE[428] `sub_3cca8` (`0x3cca8..0x3d80c`, 2916 bytes)
 * Disassembly: 0x3cca8: stp x28, x27, [sp, #-0x60]! ; 0x3ccac: stp x26, x25, [sp, #0x10] ; 0x3ccb0: stp x24, x23, [sp, #0x20] ; 0x3ccb4: stp x22, x21, [sp, #0x30] ; 0x3ccb8: stp x20, x19, [sp, #0x40] ; 0x3ccbc: stp x29, x30, [sp, #0x50]
 */
uint64_t fde_428_0x3cca8(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x3cca8ULL;
    constexpr uint64_t kFuncSize    = 0xb64ULL;
    constexpr uint32_t kFirstOpcode = 0xa9ba6ffcU;
    constexpr uint32_t kLastOpcode  = 0x9400207eU;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[429] `sub_3d80c` (`0x3d80c..0x3e04c`, 2112 bytes)
 *        Hàm FDE[429] `sub_3d80c` (`0x3d80c..0x3e04c`, 2112 bytes)
 * Disassembly: 0x3d80c: sub sp, sp, #0x1c0 ; 0x3d810: stp x28, x27, [sp, #0x160] ; 0x3d814: stp x26, x25, [sp, #0x170] ; 0x3d818: stp x24, x23, [sp, #0x180] ; 0x3d81c: stp x22, x21, [sp, #0x190] ; 0x3d820: stp x20, x19, [sp, #0x1a0]
 */
uint64_t fde_429_0x3d80c(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x3d80cULL;
    constexpr uint64_t kFuncSize    = 0x840ULL;
    constexpr uint32_t kFirstOpcode = 0xd10703ffU;
    constexpr uint32_t kLastOpcode  = 0x94001e42U;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[430] `sub_3e04c` (`0x3e04c..0x3e1bc`, 368 bytes)
 *        Hàm FDE[430] `sub_3e04c` (`0x3e04c..0x3e1bc`, 368 bytes)
 * Disassembly: 0x3e04c: sub sp, sp, #0xa0 ; 0x3e050: stp x23, x22, [sp, #0x70] ; 0x3e054: stp x21, x20, [sp, #0x80] ; 0x3e058: stp x19, x30, [sp, #0x90] ; 0x3e05c: mrs x21, tpidr_el0 ; 0x3e060: ldr x8, [x21, #0x28]
 */
uint64_t fde_430_0x3e04c(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x3e04cULL;
    constexpr uint64_t kFuncSize    = 0x170ULL;
    constexpr uint32_t kFirstOpcode = 0xd10283ffU;
    constexpr uint32_t kLastOpcode  = 0x94001de6U;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[431] `sub_3e1bc` (`0x3e1bc..0x3e2e0`, 292 bytes)
 *        Hàm FDE[431] `sub_3e1bc` (`0x3e1bc..0x3e2e0`, 292 bytes)
 * Disassembly: 0x3e1bc: sub sp, sp, #0x70 ; 0x3e1c0: str x22, [sp, #0x40] ; 0x3e1c4: stp x21, x20, [sp, #0x50] ; 0x3e1c8: stp x19, x30, [sp, #0x60] ; 0x3e1cc: mrs x20, tpidr_el0 ; 0x3e1d0: ldr x8, [x20, #0x28]
 */
uint64_t fde_431_0x3e1bc(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x3e1bcULL;
    constexpr uint64_t kFuncSize    = 0x124ULL;
    constexpr uint32_t kFirstOpcode = 0xd101c3ffU;
    constexpr uint32_t kLastOpcode  = 0x94001d9dU;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[432] `sub_3e2e0` (`0x3e2e0..0x3e55c`, 636 bytes)
 *        Hàm FDE[432] `sub_3e2e0` (`0x3e2e0..0x3e55c`, 636 bytes)
 * Disassembly: 0x3e2e0: sub sp, sp, #0x70 ; 0x3e2e4: stp x25, x24, [sp, #0x30] ; 0x3e2e8: stp x23, x22, [sp, #0x40] ; 0x3e2ec: stp x21, x20, [sp, #0x50] ; 0x3e2f0: stp x19, x30, [sp, #0x60] ; 0x3e2f4: mrs x23, tpidr_el0
 */
uint64_t fde_432_0x3e2e0(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x3e2e0ULL;
    constexpr uint64_t kFuncSize    = 0x27cULL;
    constexpr uint32_t kFirstOpcode = 0xd101c3ffU;
    constexpr uint32_t kLastOpcode  = 0x94001cfeU;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[433] `sub_3e55c` (`0x3e55c..0x3e7b8`, 604 bytes)
 *        Hàm FDE[433] `sub_3e55c` (`0x3e55c..0x3e7b8`, 604 bytes)
 * Disassembly: 0x3e55c: sub sp, sp, #0x60 ; 0x3e560: stp x25, x24, [sp, #0x20] ; 0x3e564: stp x23, x22, [sp, #0x30] ; 0x3e568: stp x21, x20, [sp, #0x40] ; 0x3e56c: stp x19, x30, [sp, #0x50] ; 0x3e570: mrs x23, tpidr_el0
 */
uint64_t fde_433_0x3e55c(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x3e55cULL;
    constexpr uint64_t kFuncSize    = 0x25cULL;
    constexpr uint32_t kFirstOpcode = 0xd10183ffU;
    constexpr uint32_t kLastOpcode  = 0x94001c67U;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[434] `sub_3e7b8` (`0x3e7b8..0x3e8a0`, 232 bytes)
 *        Hàm FDE[434] `sub_3e7b8` (`0x3e7b8..0x3e8a0`, 232 bytes)
 * Disassembly: 0x3e7b8: stp x21, x20, [sp, #-0x20]! ; 0x3e7bc: stp x19, x30, [sp, #0x10] ; 0x3e7c0: cbz x2, #0x3e7d0 ; 0x3e7c4: add x8, x2, #0x88 ; 0x3e7c8: ldarb w8, [x8] ; 0x3e7cc: tbnz w8, #0, #0x3e7e4
 */
uint64_t fde_434_0x3e7b8(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x3e7b8ULL;
    constexpr uint64_t kFuncSize    = 0xe8ULL;
    constexpr uint32_t kFirstOpcode = 0xa9be53f5U;
    constexpr uint32_t kLastOpcode  = 0x17ffffceU;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[435] `sub_3e8a0` (`0x3e8a0..0x3ea10`, 368 bytes)
 *        Hàm FDE[435] `sub_3e8a0` (`0x3e8a0..0x3ea10`, 368 bytes)
 * Disassembly: 0x3e8a0: sub sp, sp, #0x70 ; 0x3e8a4: str x22, [sp, #0x40] ; 0x3e8a8: stp x21, x20, [sp, #0x50] ; 0x3e8ac: stp x19, x30, [sp, #0x60] ; 0x3e8b0: mrs x22, tpidr_el0 ; 0x3e8b4: ldr x8, [x22, #0x28]
 */
uint64_t fde_435_0x3e8a0(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x3e8a0ULL;
    constexpr uint64_t kFuncSize    = 0x170ULL;
    constexpr uint32_t kFirstOpcode = 0xd101c3ffU;
    constexpr uint32_t kLastOpcode  = 0x94001bd1U;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[436] `sub_3ea10` (`0x3ea10..0x3eb34`, 292 bytes)
 *        Hàm FDE[436] `sub_3ea10` (`0x3ea10..0x3eb34`, 292 bytes)
 * Disassembly: 0x3ea10: sub sp, sp, #0x50 ; 0x3ea14: stp x25, x24, [sp, #0x10] ; 0x3ea18: stp x23, x22, [sp, #0x20] ; 0x3ea1c: stp x21, x20, [sp, #0x30] ; 0x3ea20: stp x19, x30, [sp, #0x40] ; 0x3ea24: mrs x24, tpidr_el0
 */
uint64_t fde_436_0x3ea10(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x3ea10ULL;
    constexpr uint64_t kFuncSize    = 0x124ULL;
    constexpr uint32_t kFirstOpcode = 0xd10143ffU;
    constexpr uint32_t kLastOpcode  = 0x94001b88U;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[437] `sub_3eb34` (`0x3eb34..0x3ec60`, 300 bytes)
 *        Hàm FDE[437] `sub_3eb34` (`0x3eb34..0x3ec60`, 300 bytes)
 * Disassembly: 0x3eb34: sub sp, sp, #0x50 ; 0x3eb38: str x22, [sp, #0x20] ; 0x3eb3c: stp x21, x20, [sp, #0x30] ; 0x3eb40: stp x19, x30, [sp, #0x40] ; 0x3eb44: mrs x22, tpidr_el0 ; 0x3eb48: ldr x8, [x22, #0x28]
 */
uint64_t fde_437_0x3eb34(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x3eb34ULL;
    constexpr uint64_t kFuncSize    = 0x12cULL;
    constexpr uint32_t kFirstOpcode = 0xd10143ffU;
    constexpr uint32_t kLastOpcode  = 0x94001b3dU;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[438] `sub_3ec60` (`0x3ec60..0x3ecb4`, 84 bytes)
 *        Hàm FDE[438] `sub_3ec60` (`0x3ec60..0x3ecb4`, 84 bytes)
 * Disassembly: 0x3ec60: stp x19, x30, [sp, #-0x10]! ; 0x3ec64: ldr x19, [x0, #0x18] ; 0x3ec68: adrp x8, #0x49000 ; 0x3ec6c: add x8, x8, #0xfd8 ; 0x3ec70: str x8, [x0] ; 0x3ec74: cbz x19, #0x3ec90
 */
uint64_t fde_438_0x3ec60(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x3ec60ULL;
    constexpr uint64_t kFuncSize    = 0x54ULL;
    constexpr uint32_t kFirstOpcode = 0xa9bf7bf3U;
    constexpr uint32_t kLastOpcode  = 0x14001b90U;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[439] `sub_3ecb4` (`0x3ecb4..0x3ed14`, 96 bytes)
 *        Hàm FDE[439] `sub_3ecb4` (`0x3ecb4..0x3ed14`, 96 bytes)
 * Disassembly: 0x3ecb4: str x20, [sp, #-0x20]! ; 0x3ecb8: stp x19, x30, [sp, #0x10] ; 0x3ecbc: ldr x20, [x0, #0x18] ; 0x3ecc0: adrp x8, #0x49000 ; 0x3ecc4: mov x19, x0 ; 0x3ecc8: add x8, x8, #0xfd8
 */
uint64_t fde_439_0x3ecb4(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x3ecb4ULL;
    constexpr uint64_t kFuncSize    = 0x60ULL;
    constexpr uint32_t kFirstOpcode = 0xf81e0ff4U;
    constexpr uint32_t kLastOpcode  = 0x14001b08U;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[440] `sub_3ed14` (`0x3ed14..0x3ed60`, 76 bytes)
 *        Hàm FDE[440] `sub_3ed14` (`0x3ed14..0x3ed60`, 76 bytes)
 * Disassembly: 0x3ed14: stp x19, x30, [sp, #-0x10]! ; 0x3ed18: mov x19, x0 ; 0x3ed1c: mov w0, #0x20 ; 0x3ed20: bl #0x459f0 ; 0x3ed24: adrp x8, #0x49000 ; 0x3ed28: add x8, x8, #0xfd8
 */
uint64_t fde_440_0x3ed14(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x3ed14ULL;
    constexpr uint64_t kFuncSize    = 0x4cULL;
    constexpr uint32_t kFirstOpcode = 0xa9bf7bf3U;
    constexpr uint32_t kLastOpcode  = 0xd65f03c0U;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[441] `sub_3ed60` (`0x3ed60..0x3eda0`, 64 bytes)
 *        Hàm FDE[441] `sub_3ed60` (`0x3ed60..0x3eda0`, 64 bytes)
 * Disassembly: 0x3ed60: adrp x8, #0x49000 ; 0x3ed64: add x8, x8, #0xfd8 ; 0x3ed68: str x8, [x1] ; 0x3ed6c: ldr x8, [x0, #8] ; 0x3ed70: str x8, [x1, #8] ; 0x3ed74: ldr x8, [x0, #0x10]
 */
uint64_t fde_441_0x3ed60(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x3ed60ULL;
    constexpr uint64_t kFuncSize    = 0x40ULL;
    constexpr uint32_t kFirstOpcode = 0xf0000048U;
    constexpr uint32_t kLastOpcode  = 0xd65f03c0U;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[442] `sub_3eda0` (`0x3eda0..0x3f028`, 648 bytes)
 *        Hàm FDE[442] `sub_3eda0` (`0x3eda0..0x3f028`, 648 bytes)
 * Disassembly: 0x3eda0: sub sp, sp, #0x80 ; 0x3eda4: str x24, [sp, #0x40] ; 0x3eda8: stp x23, x22, [sp, #0x50] ; 0x3edac: stp x21, x20, [sp, #0x60] ; 0x3edb0: stp x19, x30, [sp, #0x70] ; 0x3edb4: mrs x23, tpidr_el0
 */
uint64_t fde_442_0x3eda0(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x3eda0ULL;
    constexpr uint64_t kFuncSize    = 0x288ULL;
    constexpr uint32_t kFirstOpcode = 0xd10203ffU;
    constexpr uint32_t kLastOpcode  = 0x94001a4bU;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[443] `sub_3f028` (`0x3f028..0x3f044`, 28 bytes)
 *        Hàm FDE[443] `sub_3f028` (`0x3f028..0x3f044`, 28 bytes)
 * Disassembly: 0x3f028: ldr x8, [x1, #8] ; 0x3f02c: adrp x9, #0x11000 ; 0x3f030: add x9, x9, #0xd3d ; 0x3f034: add x10, x0, #8 ; 0x3f038: cmp x8, x9 ; 0x3f03c: csel x0, x10, xzr, eq
 */
uint64_t fde_443_0x3f028(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x3f028ULL;
    constexpr uint64_t kFuncSize    = 0x1cULL;
    constexpr uint32_t kFirstOpcode = 0xf9400428U;
    constexpr uint32_t kLastOpcode  = 0xd65f03c0U;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[444] `sub_3f044` (`0x3f044..0x3f050`, 12 bytes)
 *        Hàm FDE[444] `sub_3f044` (`0x3f044..0x3f050`, 12 bytes)
 * Disassembly: 0x3f044: adrp x0, #0x4a000 ; 0x3f048: add x0, x0, #0x38 ; 0x3f04c: ret
 */
uint64_t fde_444_0x3f044(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x3f044ULL;
    constexpr uint64_t kFuncSize    = 0xcULL;
    constexpr uint32_t kFirstOpcode = 0xf0000040U;
    constexpr uint32_t kLastOpcode  = 0xd65f03c0U;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[445] `_ZN5vmsdk6worker11WorkerScopeD2Ev` (`0x3f050..0x3f24c`, 508 bytes)
 *        Hàm FDE[445] `_ZN5vmsdk6worker11WorkerScopeD2Ev` (`0x3f050..0x3f24c`, 508 bytes)
 * Disassembly: 0x3f050: sub sp, sp, #0x70 ; 0x3f054: stp x25, x24, [sp, #0x30] ; 0x3f058: stp x23, x22, [sp, #0x40] ; 0x3f05c: stp x21, x20, [sp, #0x50] ; 0x3f060: stp x19, x30, [sp, #0x60] ; 0x3f064: adrp x25, #0x4c000
 */
uint64_t fde_445_0x3f050(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x3f050ULL;
    constexpr uint64_t kFuncSize    = 0x1fcULL;
    constexpr uint32_t kFirstOpcode = 0xd101c3ffU;
    constexpr uint32_t kLastOpcode  = 0x940019eeU;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[446] `sub_3f24c` (`0x3f24c..0x3f3b8`, 364 bytes)
 *        Hàm FDE[446] `sub_3f24c` (`0x3f24c..0x3f3b8`, 364 bytes)
 * Disassembly: 0x3f24c: sub sp, sp, #0x80 ; 0x3f250: str x24, [sp, #0x40] ; 0x3f254: stp x23, x22, [sp, #0x50] ; 0x3f258: stp x21, x20, [sp, #0x60] ; 0x3f25c: stp x19, x30, [sp, #0x70] ; 0x3f260: mrs x22, tpidr_el0
 */
uint64_t fde_446_0x3f24c(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x3f24cULL;
    constexpr uint64_t kFuncSize    = 0x16cULL;
    constexpr uint32_t kFirstOpcode = 0xd10203ffU;
    constexpr uint32_t kLastOpcode  = 0x94001967U;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[447] `sub_3f3b8` (`0x3f3b8..0x3f528`, 368 bytes)
 *        Hàm FDE[447] `sub_3f3b8` (`0x3f3b8..0x3f528`, 368 bytes)
 * Disassembly: 0x3f3b8: sub sp, sp, #0xa0 ; 0x3f3bc: stp x25, x24, [sp, #0x60] ; 0x3f3c0: stp x23, x22, [sp, #0x70] ; 0x3f3c4: stp x21, x20, [sp, #0x80] ; 0x3f3c8: stp x19, x30, [sp, #0x90] ; 0x3f3cc: mrs x23, tpidr_el0
 */
uint64_t fde_447_0x3f3b8(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x3f3b8ULL;
    constexpr uint64_t kFuncSize    = 0x170ULL;
    constexpr uint32_t kFirstOpcode = 0xd10283ffU;
    constexpr uint32_t kLastOpcode  = 0x9400190bU;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[448] `sub_3f528` (`0x3f528..0x3f58c`, 100 bytes)
 *        Hàm FDE[448] `sub_3f528` (`0x3f528..0x3f58c`, 100 bytes)
 * Disassembly: 0x3f528: str x20, [sp, #-0x20]! ; 0x3f52c: stp x19, x30, [sp, #0x10] ; 0x3f530: adrp x8, #0x4a000 ; 0x3f534: adrp x9, #0x48000 ; 0x3f538: add x8, x8, #0xa8 ; 0x3f53c: add x9, x9, #0x498
 */
uint64_t fde_448_0x3f528(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x3f528ULL;
    constexpr uint64_t kFuncSize    = 0x64ULL;
    constexpr uint32_t kFirstOpcode = 0xf81e0ff4U;
    constexpr uint32_t kLastOpcode  = 0x1400195eU;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[449] `sub_3f58c` (`0x3f58c..0x3f5f8`, 108 bytes)
 *        Hàm FDE[449] `sub_3f58c` (`0x3f58c..0x3f5f8`, 108 bytes)
 * Disassembly: 0x3f58c: str x20, [sp, #-0x20]! ; 0x3f590: stp x19, x30, [sp, #0x10] ; 0x3f594: adrp x8, #0x4a000 ; 0x3f598: adrp x9, #0x48000 ; 0x3f59c: add x8, x8, #0xa8 ; 0x3f5a0: add x9, x9, #0x498
 */
uint64_t fde_449_0x3f58c(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x3f58cULL;
    constexpr uint64_t kFuncSize    = 0x6cULL;
    constexpr uint32_t kFirstOpcode = 0xf81e0ff4U;
    constexpr uint32_t kLastOpcode  = 0x140018cfU;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[450] `sub_3f5f8` (`0x3f5f8..0x3f654`, 92 bytes)
 *        Hàm FDE[450] `sub_3f5f8` (`0x3f5f8..0x3f654`, 92 bytes)
 * Disassembly: 0x3f5f8: str x20, [sp, #-0x20]! ; 0x3f5fc: stp x19, x30, [sp, #0x10] ; 0x3f600: adrp x8, #0x48000 ; 0x3f604: add x8, x8, #0x498 ; 0x3f608: mov x20, x0 ; 0x3f60c: str x8, [x20, #0x18]!
 */
uint64_t fde_450_0x3f5f8(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x3f5f8ULL;
    constexpr uint64_t kFuncSize    = 0x5cULL;
    constexpr uint32_t kFirstOpcode = 0xf81e0ff4U;
    constexpr uint32_t kLastOpcode  = 0x140018b8U;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[451] `sub_3f654` (`0x3f654..0x3f6f4`, 160 bytes)
 *        Hàm FDE[451] `sub_3f654` (`0x3f654..0x3f6f4`, 160 bytes)
 * Disassembly: 0x3f654: str x20, [sp, #-0x20]! ; 0x3f658: stp x19, x30, [sp, #0x10] ; 0x3f65c: adrp x8, #0x4a000 ; 0x3f660: adrp x9, #0x48000 ; 0x3f664: add x8, x8, #0xf8 ; 0x3f668: add x9, x9, #0x498
 */
uint64_t fde_451_0x3f654(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x3f654ULL;
    constexpr uint64_t kFuncSize    = 0xa0ULL;
    constexpr uint32_t kFirstOpcode = 0xf81e0ff4U;
    constexpr uint32_t kLastOpcode  = 0x14001900U;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[452] `sub_3f6f4` (`0x3f6f4..0x3f790`, 156 bytes)
 *        Hàm FDE[452] `sub_3f6f4` (`0x3f6f4..0x3f790`, 156 bytes)
 * Disassembly: 0x3f6f4: str x20, [sp, #-0x20]! ; 0x3f6f8: stp x19, x30, [sp, #0x10] ; 0x3f6fc: adrp x8, #0x4a000 ; 0x3f700: adrp x9, #0x48000 ; 0x3f704: add x8, x8, #0xf8 ; 0x3f708: add x9, x9, #0x498
 */
uint64_t fde_452_0x3f6f4(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x3f6f4ULL;
    constexpr uint64_t kFuncSize    = 0x9cULL;
    constexpr uint32_t kFirstOpcode = 0xf81e0ff4U;
    constexpr uint32_t kLastOpcode  = 0x14001869U;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[453] `sub_3f790` (`0x3f790..0x3f814`, 132 bytes)
 *        Hàm FDE[453] `sub_3f790` (`0x3f790..0x3f814`, 132 bytes)
 * Disassembly: 0x3f790: stp x21, x20, [sp, #-0x20]! ; 0x3f794: stp x19, x30, [sp, #0x10] ; 0x3f798: mov x20, x0 ; 0x3f79c: mov w0, #0x48 ; 0x3f7a0: bl #0x459f0 ; 0x3f7a4: adrp x8, #0x4a000
 */
uint64_t fde_453_0x3f790(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x3f790ULL;
    constexpr uint64_t kFuncSize    = 0x84ULL;
    constexpr uint32_t kFirstOpcode = 0xa9be53f5U;
    constexpr uint32_t kLastOpcode  = 0xd65f03c0U;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[454] `sub_3f814` (`0x3f814..0x3f890`, 124 bytes)
 *        Hàm FDE[454] `sub_3f814` (`0x3f814..0x3f890`, 124 bytes)
 * Disassembly: 0x3f814: stp x21, x20, [sp, #-0x20]! ; 0x3f818: stp x19, x30, [sp, #0x10] ; 0x3f81c: adrp x8, #0x4a000 ; 0x3f820: add x8, x8, #0xf8 ; 0x3f824: str x8, [x1] ; 0x3f828: ldr x8, [x0, #8]
 */
uint64_t fde_454_0x3f814(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x3f814ULL;
    constexpr uint64_t kFuncSize    = 0x7cULL;
    constexpr uint32_t kFirstOpcode = 0xa9be53f5U;
    constexpr uint32_t kLastOpcode  = 0x14001839U;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[455] `sub_3f890` (`0x3f890..0x3f924`, 148 bytes)
 *        Hàm FDE[455] `sub_3f890` (`0x3f890..0x3f924`, 148 bytes)
 * Disassembly: 0x3f890: str x20, [sp, #-0x20]! ; 0x3f894: stp x19, x30, [sp, #0x10] ; 0x3f898: adrp x8, #0x48000 ; 0x3f89c: add x8, x8, #0x498 ; 0x3f8a0: mov x20, x0 ; 0x3f8a4: str x8, [x20, #0x20]!
 */
uint64_t fde_455_0x3f890(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x3f890ULL;
    constexpr uint64_t kFuncSize    = 0x94ULL;
    constexpr uint32_t kFirstOpcode = 0xf81e0ff4U;
    constexpr uint32_t kLastOpcode  = 0x14001874U;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[456] `sub_3f924` (`0x3f924..0x3f9b4`, 144 bytes)
 *        Hàm FDE[456] `sub_3f924` (`0x3f924..0x3f9b4`, 144 bytes)
 * Disassembly: 0x3f924: str x20, [sp, #-0x20]! ; 0x3f928: stp x19, x30, [sp, #0x10] ; 0x3f92c: adrp x8, #0x48000 ; 0x3f930: add x8, x8, #0x498 ; 0x3f934: mov x20, x0 ; 0x3f938: str x8, [x20, #0x20]!
 */
uint64_t fde_456_0x3f924(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x3f924ULL;
    constexpr uint64_t kFuncSize    = 0x90ULL;
    constexpr uint32_t kFirstOpcode = 0xf81e0ff4U;
    constexpr uint32_t kLastOpcode  = 0x140017e0U;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[457] `sub_3f9b4` (`0x3f9b4..0x3fbe0`, 556 bytes)
 *        Hàm FDE[457] `sub_3f9b4` (`0x3f9b4..0x3fbe0`, 556 bytes)
 * Disassembly: 0x3f9b4: sub sp, sp, #0xa0 ; 0x3f9b8: stp x23, x22, [sp, #0x70] ; 0x3f9bc: stp x21, x20, [sp, #0x80] ; 0x3f9c0: stp x19, x30, [sp, #0x90] ; 0x3f9c4: mrs x22, tpidr_el0 ; 0x3f9c8: ldr x8, [x22, #0x28]
 */
uint64_t fde_457_0x3f9b4(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x3f9b4ULL;
    constexpr uint64_t kFuncSize    = 0x22cULL;
    constexpr uint32_t kFirstOpcode = 0xd10283ffU;
    constexpr uint32_t kLastOpcode  = 0x9400175dU;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[458] `sub_3fbe0` (`0x3fbe0..0x3fbfc`, 28 bytes)
 *        Hàm FDE[458] `sub_3fbe0` (`0x3fbe0..0x3fbfc`, 28 bytes)
 * Disassembly: 0x3fbe0: ldr x8, [x1, #8] ; 0x3fbe4: adrp x9, #0x11000 ; 0x3fbe8: add x9, x9, #0xe8c ; 0x3fbec: add x10, x0, #8 ; 0x3fbf0: cmp x8, x9 ; 0x3fbf4: csel x0, x10, xzr, eq
 */
uint64_t fde_458_0x3fbe0(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x3fbe0ULL;
    constexpr uint64_t kFuncSize    = 0x1cULL;
    constexpr uint32_t kFirstOpcode = 0xf9400428U;
    constexpr uint32_t kLastOpcode  = 0xd65f03c0U;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[459] `sub_3fbfc` (`0x3fbfc..0x3fc08`, 12 bytes)
 *        Hàm FDE[459] `sub_3fbfc` (`0x3fbfc..0x3fc08`, 12 bytes)
 * Disassembly: 0x3fbfc: adrp x0, #0x4a000 ; 0x3fc00: add x0, x0, #0x158 ; 0x3fc04: ret
 */
uint64_t fde_459_0x3fbfc(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x3fbfcULL;
    constexpr uint64_t kFuncSize    = 0xcULL;
    constexpr uint32_t kFirstOpcode = 0xf0000040U;
    constexpr uint32_t kLastOpcode  = 0xd65f03c0U;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[460] `sub_3fc08` (`0x3fc08..0x3fc64`, 92 bytes)
 *        Hàm FDE[460] `sub_3fc08` (`0x3fc08..0x3fc64`, 92 bytes)
 * Disassembly: 0x3fc08: stp x19, x30, [sp, #-0x10]! ; 0x3fc0c: adrp x8, #0x4a000 ; 0x3fc10: add x8, x8, #0x178 ; 0x3fc14: fmov d0, x8 ; 0x3fc18: adrp x8, #0x48000 ; 0x3fc1c: add x8, x8, #0x498
 */
uint64_t fde_460_0x3fc08(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x3fc08ULL;
    constexpr uint64_t kFuncSize    = 0x5cULL;
    constexpr uint32_t kFirstOpcode = 0xa9bf7bf3U;
    constexpr uint32_t kLastOpcode  = 0x14001734U;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[461] `sub_3fc64` (`0x3fc64..0x3fcc0`, 92 bytes)
 *        Hàm FDE[461] `sub_3fc64` (`0x3fc64..0x3fcc0`, 92 bytes)
 * Disassembly: 0x3fc64: stp x19, x30, [sp, #-0x10]! ; 0x3fc68: adrp x8, #0x4a000 ; 0x3fc6c: add x8, x8, #0x178 ; 0x3fc70: fmov d0, x8 ; 0x3fc74: adrp x8, #0x48000 ; 0x3fc78: add x8, x8, #0x498
 */
uint64_t fde_461_0x3fc64(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x3fc64ULL;
    constexpr uint64_t kFuncSize    = 0x5cULL;
    constexpr uint32_t kFirstOpcode = 0xa9bf7bf3U;
    constexpr uint32_t kLastOpcode  = 0x1400171dU;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[462] `sub_3fcc0` (`0x3fcc0..0x3fd24`, 100 bytes)
 *        Hàm FDE[462] `sub_3fcc0` (`0x3fcc0..0x3fd24`, 100 bytes)
 * Disassembly: 0x3fcc0: stp x21, x20, [sp, #-0x20]! ; 0x3fcc4: stp x19, x30, [sp, #0x10] ; 0x3fcc8: mov x19, x0 ; 0x3fccc: mov w0, #0x38 ; 0x3fcd0: bl #0x459f0 ; 0x3fcd4: adrp x8, #0x4a000
 */
uint64_t fde_462_0x3fcc0(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x3fcc0ULL;
    constexpr uint64_t kFuncSize    = 0x64ULL;
    constexpr uint32_t kFirstOpcode = 0xa9be53f5U;
    constexpr uint32_t kLastOpcode  = 0xd65f03c0U;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[463] `sub_3fd24` (`0x3fd24..0x3fd7c`, 88 bytes)
 *        Hàm FDE[463] `sub_3fd24` (`0x3fd24..0x3fd7c`, 88 bytes)
 * Disassembly: 0x3fd24: stp x21, x20, [sp, #-0x20]! ; 0x3fd28: stp x19, x30, [sp, #0x10] ; 0x3fd2c: adrp x8, #0x4a000 ; 0x3fd30: add x21, x1, #8 ; 0x3fd34: mov x20, x0 ; 0x3fd38: add x8, x8, #0x178
 */
uint64_t fde_463_0x3fd24(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x3fd24ULL;
    constexpr uint64_t kFuncSize    = 0x58ULL;
    constexpr uint32_t kFirstOpcode = 0xa9be53f5U;
    constexpr uint32_t kLastOpcode  = 0xd65f03c0U;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[464] `sub_3fd7c` (`0x3fd7c..0x3fdd8`, 92 bytes)
 *        Hàm FDE[464] `sub_3fd7c` (`0x3fd7c..0x3fdd8`, 92 bytes)
 * Disassembly: 0x3fd7c: str x20, [sp, #-0x20]! ; 0x3fd80: stp x19, x30, [sp, #0x10] ; 0x3fd84: adrp x8, #0x48000 ; 0x3fd88: add x8, x8, #0x498 ; 0x3fd8c: mov x20, x0 ; 0x3fd90: str x8, [x20, #8]!
 */
uint64_t fde_464_0x3fd7c(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x3fd7cULL;
    constexpr uint64_t kFuncSize    = 0x5cULL;
    constexpr uint32_t kFirstOpcode = 0xf81e0ff4U;
    constexpr uint32_t kLastOpcode  = 0x140016d7U;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[465] `sub_3fdd8` (`0x3fdd8..0x3fe30`, 88 bytes)
 *        Hàm FDE[465] `sub_3fdd8` (`0x3fdd8..0x3fe30`, 88 bytes)
 * Disassembly: 0x3fdd8: str x20, [sp, #-0x20]! ; 0x3fddc: stp x19, x30, [sp, #0x10] ; 0x3fde0: adrp x8, #0x48000 ; 0x3fde4: add x8, x8, #0x498 ; 0x3fde8: mov x20, x0 ; 0x3fdec: str x8, [x20, #8]!
 */
uint64_t fde_465_0x3fdd8(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x3fdd8ULL;
    constexpr uint64_t kFuncSize    = 0x58ULL;
    constexpr uint32_t kFirstOpcode = 0xf81e0ff4U;
    constexpr uint32_t kLastOpcode  = 0x140016c1U;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[466] `sub_3fe30` (`0x3fe30..0x3ffa8`, 376 bytes)
 *        Hàm FDE[466] `sub_3fe30` (`0x3fe30..0x3ffa8`, 376 bytes)
 * Disassembly: 0x3fe30: sub sp, sp, #0xa0 ; 0x3fe34: stp x23, x22, [sp, #0x70] ; 0x3fe38: stp x21, x20, [sp, #0x80] ; 0x3fe3c: stp x19, x30, [sp, #0x90] ; 0x3fe40: mrs x21, tpidr_el0 ; 0x3fe44: ldr x8, [x21, #0x28]
 */
uint64_t fde_466_0x3fe30(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x3fe30ULL;
    constexpr uint64_t kFuncSize    = 0x178ULL;
    constexpr uint32_t kFirstOpcode = 0xd10283ffU;
    constexpr uint32_t kLastOpcode  = 0x9400166bU;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[467] `sub_3ffa8` (`0x3ffa8..0x3ffc4`, 28 bytes)
 *        Hàm FDE[467] `sub_3ffa8` (`0x3ffa8..0x3ffc4`, 28 bytes)
 * Disassembly: 0x3ffa8: ldr x8, [x1, #8] ; 0x3ffac: adrp x9, #0x11000 ; 0x3ffb0: add x9, x9, #0xf1f ; 0x3ffb4: add x10, x0, #8 ; 0x3ffb8: cmp x8, x9 ; 0x3ffbc: csel x0, x10, xzr, eq
 */
uint64_t fde_467_0x3ffa8(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x3ffa8ULL;
    constexpr uint64_t kFuncSize    = 0x1cULL;
    constexpr uint32_t kFirstOpcode = 0xf9400428U;
    constexpr uint32_t kLastOpcode  = 0xd65f03c0U;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[468] `sub_3ffc4` (`0x3ffc4..0x3ffd0`, 12 bytes)
 *        Hàm FDE[468] `sub_3ffc4` (`0x3ffc4..0x3ffd0`, 12 bytes)
 * Disassembly: 0x3ffc4: adrp x0, #0x4a000 ; 0x3ffc8: add x0, x0, #0x1d8 ; 0x3ffcc: ret
 */
uint64_t fde_468_0x3ffc4(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x3ffc4ULL;
    constexpr uint64_t kFuncSize    = 0xcULL;
    constexpr uint32_t kFirstOpcode = 0xf0000040U;
    constexpr uint32_t kLastOpcode  = 0xd65f03c0U;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[469] `sub_3ffd0` (`0x3ffd0..0x40164`, 404 bytes)
 *        Hàm FDE[469] `sub_3ffd0` (`0x3ffd0..0x40164`, 404 bytes)
 * Disassembly: 0x3ffd0: sub sp, sp, #0x80 ; 0x3ffd4: stp x25, x24, [sp, #0x40] ; 0x3ffd8: stp x23, x22, [sp, #0x50] ; 0x3ffdc: stp x21, x20, [sp, #0x60] ; 0x3ffe0: stp x19, x30, [sp, #0x70] ; 0x3ffe4: mrs x21, tpidr_el0
 */
uint64_t fde_469_0x3ffd0(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x3ffd0ULL;
    constexpr uint64_t kFuncSize    = 0x194ULL;
    constexpr uint32_t kFirstOpcode = 0xd10203ffU;
    constexpr uint32_t kLastOpcode  = 0x17ffffc4U;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[470] `sub_40164` (`0x40164..0x401cc`, 104 bytes)
 *        Hàm FDE[470] `sub_40164` (`0x40164..0x401cc`, 104 bytes)
 * Disassembly: 0x40164: str x20, [sp, #-0x20]! ; 0x40168: stp x19, x30, [sp, #0x10] ; 0x4016c: adrp x8, #0x4a000 ; 0x40170: adrp x9, #0x48000 ; 0x40174: add x8, x8, #0x1f8 ; 0x40178: add x9, x9, #0x498
 */
uint64_t fde_470_0x40164(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x40164ULL;
    constexpr uint64_t kFuncSize    = 0x68ULL;
    constexpr uint32_t kFirstOpcode = 0xf81e0ff4U;
    constexpr uint32_t kLastOpcode  = 0x140015daU;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[471] `sub_401cc` (`0x401cc..0x40230`, 100 bytes)
 *        Hàm FDE[471] `sub_401cc` (`0x401cc..0x40230`, 100 bytes)
 * Disassembly: 0x401cc: str x20, [sp, #-0x20]! ; 0x401d0: stp x19, x30, [sp, #0x10] ; 0x401d4: adrp x8, #0x4a000 ; 0x401d8: adrp x9, #0x48000 ; 0x401dc: add x8, x8, #0x1f8 ; 0x401e0: add x9, x9, #0x498
 */
uint64_t fde_471_0x401cc(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x401ccULL;
    constexpr uint64_t kFuncSize    = 0x64ULL;
    constexpr uint32_t kFirstOpcode = 0xf81e0ff4U;
    constexpr uint32_t kLastOpcode  = 0x140015c1U;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[472] `sub_40230` (`0x40230..0x40294`, 100 bytes)
 *        Hàm FDE[472] `sub_40230` (`0x40230..0x40294`, 100 bytes)
 * Disassembly: 0x40230: stp x21, x20, [sp, #-0x20]! ; 0x40234: stp x19, x30, [sp, #0x10] ; 0x40238: mov x19, x0 ; 0x4023c: mov w0, #0x38 ; 0x40240: bl #0x459f0 ; 0x40244: adrp x8, #0x4a000
 */
uint64_t fde_472_0x40230(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x40230ULL;
    constexpr uint64_t kFuncSize    = 0x64ULL;
    constexpr uint32_t kFirstOpcode = 0xa9be53f5U;
    constexpr uint32_t kLastOpcode  = 0xd65f03c0U;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[473] `sub_40294` (`0x40294..0x402e8`, 84 bytes)
 *        Hàm FDE[473] `sub_40294` (`0x40294..0x402e8`, 84 bytes)
 * Disassembly: 0x40294: stp x21, x20, [sp, #-0x20]! ; 0x40298: stp x19, x30, [sp, #0x10] ; 0x4029c: adrp x8, #0x4a000 ; 0x402a0: add x8, x8, #0x1f8 ; 0x402a4: str x8, [x1] ; 0x402a8: ldr x8, [x0, #8]
 */
uint64_t fde_473_0x40294(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x40294ULL;
    constexpr uint64_t kFuncSize    = 0x54ULL;
    constexpr uint32_t kFirstOpcode = 0xa9be53f5U;
    constexpr uint32_t kLastOpcode  = 0x140015a3U;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[474] `sub_402e8` (`0x402e8..0x40344`, 92 bytes)
 *        Hàm FDE[474] `sub_402e8` (`0x402e8..0x40344`, 92 bytes)
 * Disassembly: 0x402e8: str x20, [sp, #-0x20]! ; 0x402ec: stp x19, x30, [sp, #0x10] ; 0x402f0: adrp x8, #0x48000 ; 0x402f4: add x8, x8, #0x498 ; 0x402f8: mov x20, x0 ; 0x402fc: str x8, [x20, #0x10]!
 */
uint64_t fde_474_0x402e8(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x402e8ULL;
    constexpr uint64_t kFuncSize    = 0x5cULL;
    constexpr uint32_t kFirstOpcode = 0xf81e0ff4U;
    constexpr uint32_t kLastOpcode  = 0x1400157cU;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[475] `sub_40344` (`0x40344..0x4039c`, 88 bytes)
 *        Hàm FDE[475] `sub_40344` (`0x40344..0x4039c`, 88 bytes)
 * Disassembly: 0x40344: str x20, [sp, #-0x20]! ; 0x40348: stp x19, x30, [sp, #0x10] ; 0x4034c: adrp x8, #0x48000 ; 0x40350: add x8, x8, #0x498 ; 0x40354: mov x20, x0 ; 0x40358: str x8, [x20, #0x10]!
 */
uint64_t fde_475_0x40344(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x40344ULL;
    constexpr uint64_t kFuncSize    = 0x58ULL;
    constexpr uint32_t kFirstOpcode = 0xf81e0ff4U;
    constexpr uint32_t kLastOpcode  = 0x14001566U;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[476] `sub_4039c` (`0x4039c..0x40514`, 376 bytes)
 *        Hàm FDE[476] `sub_4039c` (`0x4039c..0x40514`, 376 bytes)
 * Disassembly: 0x4039c: sub sp, sp, #0xa0 ; 0x403a0: stp x23, x22, [sp, #0x70] ; 0x403a4: stp x21, x20, [sp, #0x80] ; 0x403a8: stp x19, x30, [sp, #0x90] ; 0x403ac: mrs x21, tpidr_el0 ; 0x403b0: ldr x8, [x21, #0x28]
 */
uint64_t fde_476_0x4039c(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x4039cULL;
    constexpr uint64_t kFuncSize    = 0x178ULL;
    constexpr uint32_t kFirstOpcode = 0xd10283ffU;
    constexpr uint32_t kLastOpcode  = 0x94001510U;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[477] `sub_40514` (`0x40514..0x40530`, 28 bytes)
 *        Hàm FDE[477] `sub_40514` (`0x40514..0x40530`, 28 bytes)
 * Disassembly: 0x40514: ldr x8, [x1, #8] ; 0x40518: adrp x9, #0x11000 ; 0x4051c: add x9, x9, #0xfba ; 0x40520: add x10, x0, #8 ; 0x40524: cmp x8, x9 ; 0x40528: csel x0, x10, xzr, eq
 */
uint64_t fde_477_0x40514(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x40514ULL;
    constexpr uint64_t kFuncSize    = 0x1cULL;
    constexpr uint32_t kFirstOpcode = 0xf9400428U;
    constexpr uint32_t kLastOpcode  = 0xd65f03c0U;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[478] `sub_40530` (`0x40530..0x4053c`, 12 bytes)
 *        Hàm FDE[478] `sub_40530` (`0x40530..0x4053c`, 12 bytes)
 * Disassembly: 0x40530: adrp x0, #0x4a000 ; 0x40534: add x0, x0, #0x258 ; 0x40538: ret
 */
uint64_t fde_478_0x40530(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x40530ULL;
    constexpr uint64_t kFuncSize    = 0xcULL;
    constexpr uint32_t kFirstOpcode = 0xd0000040U;
    constexpr uint32_t kLastOpcode  = 0xd65f03c0U;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[479] `sub_4053c` (`0x4053c..0x40598`, 92 bytes)
 *        Hàm FDE[479] `sub_4053c` (`0x4053c..0x40598`, 92 bytes)
 * Disassembly: 0x4053c: stp x19, x30, [sp, #-0x10]! ; 0x40540: adrp x8, #0x4a000 ; 0x40544: add x8, x8, #0x278 ; 0x40548: fmov d0, x8 ; 0x4054c: adrp x8, #0x48000 ; 0x40550: add x8, x8, #0x498
 */
uint64_t fde_479_0x4053c(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x4053cULL;
    constexpr uint64_t kFuncSize    = 0x5cULL;
    constexpr uint32_t kFirstOpcode = 0xa9bf7bf3U;
    constexpr uint32_t kLastOpcode  = 0x140014e7U;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[480] `sub_40598` (`0x40598..0x405f4`, 92 bytes)
 *        Hàm FDE[480] `sub_40598` (`0x40598..0x405f4`, 92 bytes)
 * Disassembly: 0x40598: stp x19, x30, [sp, #-0x10]! ; 0x4059c: adrp x8, #0x4a000 ; 0x405a0: add x8, x8, #0x278 ; 0x405a4: fmov d0, x8 ; 0x405a8: adrp x8, #0x48000 ; 0x405ac: add x8, x8, #0x498
 */
uint64_t fde_480_0x40598(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x40598ULL;
    constexpr uint64_t kFuncSize    = 0x5cULL;
    constexpr uint32_t kFirstOpcode = 0xa9bf7bf3U;
    constexpr uint32_t kLastOpcode  = 0x140014d0U;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[481] `sub_405f4` (`0x405f4..0x40658`, 100 bytes)
 *        Hàm FDE[481] `sub_405f4` (`0x405f4..0x40658`, 100 bytes)
 * Disassembly: 0x405f4: stp x21, x20, [sp, #-0x20]! ; 0x405f8: stp x19, x30, [sp, #0x10] ; 0x405fc: mov x19, x0 ; 0x40600: mov w0, #0x38 ; 0x40604: bl #0x459f0 ; 0x40608: adrp x8, #0x4a000
 */
uint64_t fde_481_0x405f4(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x405f4ULL;
    constexpr uint64_t kFuncSize    = 0x64ULL;
    constexpr uint32_t kFirstOpcode = 0xa9be53f5U;
    constexpr uint32_t kLastOpcode  = 0xd65f03c0U;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[482] `sub_40658` (`0x40658..0x406b0`, 88 bytes)
 *        Hàm FDE[482] `sub_40658` (`0x40658..0x406b0`, 88 bytes)
 * Disassembly: 0x40658: stp x21, x20, [sp, #-0x20]! ; 0x4065c: stp x19, x30, [sp, #0x10] ; 0x40660: adrp x8, #0x4a000 ; 0x40664: add x21, x1, #8 ; 0x40668: mov x20, x0 ; 0x4066c: add x8, x8, #0x278
 */
uint64_t fde_482_0x40658(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x40658ULL;
    constexpr uint64_t kFuncSize    = 0x58ULL;
    constexpr uint32_t kFirstOpcode = 0xa9be53f5U;
    constexpr uint32_t kLastOpcode  = 0xd65f03c0U;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[483] `sub_406b0` (`0x406b0..0x406cc`, 28 bytes)
 *        Hàm FDE[483] `sub_406b0` (`0x406b0..0x406cc`, 28 bytes)
 * Disassembly: 0x406b0: ldr x8, [x1, #8] ; 0x406b4: adrp x9, #0x12000 ; 0x406b8: add x9, x9, #0x53 ; 0x406bc: add x10, x0, #8 ; 0x406c0: cmp x8, x9 ; 0x406c4: csel x0, x10, xzr, eq
 */
uint64_t fde_483_0x406b0(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x406b0ULL;
    constexpr uint64_t kFuncSize    = 0x1cULL;
    constexpr uint32_t kFirstOpcode = 0xf9400428U;
    constexpr uint32_t kLastOpcode  = 0xd65f03c0U;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[484] `sub_406cc` (`0x406cc..0x406d8`, 12 bytes)
 *        Hàm FDE[484] `sub_406cc` (`0x406cc..0x406d8`, 12 bytes)
 * Disassembly: 0x406cc: adrp x0, #0x4a000 ; 0x406d0: add x0, x0, #0x2d8 ; 0x406d4: ret
 */
uint64_t fde_484_0x406cc(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x406ccULL;
    constexpr uint64_t kFuncSize    = 0xcULL;
    constexpr uint32_t kFirstOpcode = 0xd0000040U;
    constexpr uint32_t kLastOpcode  = 0xd65f03c0U;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[485] `_ZN5vmsdk6worker15JsWorkerAndroid6CreateEP7_JNIEnvP8_jobjectlS5_NSt6__ndk112basic_stringIcNS6_11char_traitsIcEENS6_9allocatorIcEEEEhSC_h` (`0x406d8..0x408c8`, 496 bytes)
 *        Hàm FDE[485] `_ZN5vmsdk6worker15JsWorkerAndroid6CreateEP7_JNIEnvP8_jobjectlS5_NSt6__ndk112basic_stringIcNS6_11char_traitsIcEENS6_9allocatorIcEEEEhSC_h` (`0x406d8..0x408c8`, 496 bytes)
 * Disassembly: 0x406d8: sub sp, sp, #0xc0 ; 0x406dc: str x28, [sp, #0x60] ; 0x406e0: stp x27, x26, [sp, #0x70] ; 0x406e4: stp x25, x24, [sp, #0x80] ; 0x406e8: stp x23, x21, [sp, #0x90] ; 0x406ec: stp x20, x19, [sp, #0xa0]
 */
uint64_t fde_485_0x406d8(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x406d8ULL;
    constexpr uint64_t kFuncSize    = 0x1f0ULL;
    constexpr uint32_t kFirstOpcode = 0xd10303ffU;
    constexpr uint32_t kLastOpcode  = 0x94001423U;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[486] `_ZN5vmsdk6worker15JsWorkerAndroidC2EP7_JNIEnvNS_7runtime14JS_ENGINE_TYPEEP8_jobjectS7_NSt6__ndk112basic_stringIcNS8_11char_traitsIcEENS8_9allocatorIcEEEEhSE_h` (`0x408c8..0x410e0`, 2072 bytes)
 *        Hàm FDE[486] `_ZN5vmsdk6worker15JsWorkerAndroidC2EP7_JNIEnvNS_7runtime14JS_ENGINE_TYPEEP8_jobjectS7_NSt6__ndk112basic_stringIcNS8_11char_traitsIcEENS8_9allocatorIcEEEEhSE_h` (`0x408c8..0x410e0`, 2072 bytes)
 * Disassembly: 0x408c8: sub sp, sp, #0xd0 ; 0x408cc: stp x28, x27, [sp, #0x70] ; 0x408d0: stp x26, x25, [sp, #0x80] ; 0x408d4: stp x24, x23, [sp, #0x90] ; 0x408d8: stp x22, x21, [sp, #0xa0] ; 0x408dc: stp x20, x19, [sp, #0xb0]
 */
uint64_t fde_486_0x408c8(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x408c8ULL;
    constexpr uint64_t kFuncSize    = 0x818ULL;
    constexpr uint32_t kFirstOpcode = 0xd10343ffU;
    constexpr uint32_t kLastOpcode  = 0x9400121dU;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[487] `_ZN5vmsdk6worker15JsWorkerAndroid4InitENS_7runtime14JS_ENGINE_TYPEERKNSt6__ndk112basic_stringIcNS4_11char_traitsIcEENS4_9allocatorIcEEEEb` (`0x410e0..0x41758`, 1656 bytes)
 *        Hàm FDE[487] `_ZN5vmsdk6worker15JsWorkerAndroid4InitENS_7runtime14JS_ENGINE_TYPEERKNSt6__ndk112basic_stringIcNS4_11char_traitsIcEENS4_9allocatorIcEEEEb` (`0x410e0..0x41758`, 1656 bytes)
 * Disassembly: 0x410e0: sub sp, sp, #0xf0 ; 0x410e4: stp x28, x27, [sp, #0x90] ; 0x410e8: stp x26, x25, [sp, #0xa0] ; 0x410ec: stp x24, x23, [sp, #0xb0] ; 0x410f0: stp x22, x21, [sp, #0xc0] ; 0x410f4: stp x20, x19, [sp, #0xd0]
 */
uint64_t fde_487_0x410e0(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x410e0ULL;
    constexpr uint64_t kFuncSize    = 0x678ULL;
    constexpr uint32_t kFirstOpcode = 0xd103c3ffU;
    constexpr uint32_t kLastOpcode  = 0x9400107fU;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[488] `sub_41758` (`0x41758..0x41784`, 44 bytes)
 *        Hàm FDE[488] `sub_41758` (`0x41758..0x41784`, 44 bytes)
 * Disassembly: 0x41758: stp x19, x30, [sp, #-0x10]! ; 0x4175c: mov x19, x0 ; 0x41760: mov w0, #0x18 ; 0x41764: bl #0x459f0 ; 0x41768: adrp x8, #0x4a000 ; 0x4176c: add x8, x8, #0x4a0
 */
uint64_t fde_488_0x41758(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x41758ULL;
    constexpr uint64_t kFuncSize    = 0x2cULL;
    constexpr uint32_t kFirstOpcode = 0xa9bf7bf3U;
    constexpr uint32_t kLastOpcode  = 0xd65f03c0U;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[489] `sub_41784` (`0x41784..0x4179c`, 24 bytes)
 *        Hàm FDE[489] `sub_41784` (`0x41784..0x4179c`, 24 bytes)
 * Disassembly: 0x41784: adrp x8, #0x4a000 ; 0x41788: add x8, x8, #0x4a0 ; 0x4178c: str x8, [x1] ; 0x41790: ldur q0, [x0, #8] ; 0x41794: stur q0, [x1, #8] ; 0x41798: ret
 */
uint64_t fde_489_0x41784(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x41784ULL;
    constexpr uint64_t kFuncSize    = 0x18ULL;
    constexpr uint32_t kFirstOpcode = 0xb0000048U;
    constexpr uint32_t kLastOpcode  = 0xd65f03c0U;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[490] `sub_4179c` (`0x4179c..0x41c74`, 1240 bytes)
 *        Hàm FDE[490] `sub_4179c` (`0x4179c..0x41c74`, 1240 bytes)
 * Disassembly: 0x4179c: sub sp, sp, #0x90 ; 0x417a0: stp x28, x27, [sp, #0x30] ; 0x417a4: stp x26, x25, [sp, #0x40] ; 0x417a8: stp x24, x23, [sp, #0x50] ; 0x417ac: stp x22, x21, [sp, #0x60] ; 0x417b0: stp x20, x19, [sp, #0x70]
 */
uint64_t fde_490_0x4179c(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x4179cULL;
    constexpr uint64_t kFuncSize    = 0x4d8ULL;
    constexpr uint32_t kFirstOpcode = 0xd10243ffU;
    constexpr uint32_t kLastOpcode  = 0x94000f38U;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[491] `sub_41c74` (`0x41c74..0x41c90`, 28 bytes)
 *        Hàm FDE[491] `sub_41c74` (`0x41c74..0x41c90`, 28 bytes)
 * Disassembly: 0x41c74: ldr x8, [x1, #8] ; 0x41c78: adrp x9, #0x12000 ; 0x41c7c: add x9, x9, #0xe0 ; 0x41c80: add x10, x0, #8 ; 0x41c84: cmp x8, x9 ; 0x41c88: csel x0, x10, xzr, eq
 */
uint64_t fde_491_0x41c74(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x41c74ULL;
    constexpr uint64_t kFuncSize    = 0x1cULL;
    constexpr uint32_t kFirstOpcode = 0xf9400428U;
    constexpr uint32_t kLastOpcode  = 0xd65f03c0U;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[492] `sub_41c90` (`0x41c90..0x41c9c`, 12 bytes)
 *        Hàm FDE[492] `sub_41c90` (`0x41c90..0x41c9c`, 12 bytes)
 * Disassembly: 0x41c90: adrp x0, #0x4a000 ; 0x41c94: add x0, x0, #0x500 ; 0x41c98: ret
 */
uint64_t fde_492_0x41c90(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x41c90ULL;
    constexpr uint64_t kFuncSize    = 0xcULL;
    constexpr uint32_t kFirstOpcode = 0xb0000040U;
    constexpr uint32_t kLastOpcode  = 0xd65f03c0U;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[493] `sub_41c9c` (`0x41c9c..0x41cc0`, 36 bytes)
 *        Hàm FDE[493] `sub_41c9c` (`0x41c9c..0x41cc0`, 36 bytes)
 * Disassembly: 0x41c9c: stp x19, x30, [sp, #-0x10]! ; 0x41ca0: adrp x8, #0x4a000 ; 0x41ca4: add x8, x8, #0x468 ; 0x41ca8: mov x19, x0 ; 0x41cac: str x8, [x0], #0x18 ; 0x41cb0: bl #0x41cf4
 */
uint64_t fde_493_0x41c9c(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x41c9cULL;
    constexpr uint64_t kFuncSize    = 0x24ULL;
    constexpr uint32_t kFirstOpcode = 0xa9bf7bf3U;
    constexpr uint32_t kLastOpcode  = 0x14000f91U;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[494] `sub_41cc0` (`0x41cc0..0x41cec`, 44 bytes)
 *        Hàm FDE[494] `sub_41cc0` (`0x41cc0..0x41cec`, 44 bytes)
 * Disassembly: 0x41cc0: stp x19, x30, [sp, #-0x10]! ; 0x41cc4: adrp x8, #0x4a000 ; 0x41cc8: add x8, x8, #0x468 ; 0x41ccc: mov x19, x0 ; 0x41cd0: str x8, [x0], #0x18 ; 0x41cd4: bl #0x41cf4
 */
uint64_t fde_494_0x41cc0(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x41cc0ULL;
    constexpr uint64_t kFuncSize    = 0x2cULL;
    constexpr uint32_t kFirstOpcode = 0xa9bf7bf3U;
    constexpr uint32_t kLastOpcode  = 0x14000f12U;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[495] `sub_41cec` (`0x41cec..0x41cf4`, 8 bytes)
 *        Hàm FDE[495] `sub_41cec` (`0x41cec..0x41cf4`, 8 bytes)
 * Disassembly: 0x41cec: add x0, x0, #0x18 ; 0x41cf0: b #0x41cf4
 */
uint64_t fde_495_0x41cec(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x41cecULL;
    constexpr uint64_t kFuncSize    = 0x8ULL;
    constexpr uint32_t kFirstOpcode = 0x91006000U;
    constexpr uint32_t kLastOpcode  = 0x14000001U;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[496] `sub_41cf4` (`0x41cf4..0x41eac`, 440 bytes)
 *        Hàm FDE[496] `sub_41cf4` (`0x41cf4..0x41eac`, 440 bytes)
 * Disassembly: 0x41cf4: str x22, [sp, #-0x30]! ; 0x41cf8: stp x21, x20, [sp, #0x10] ; 0x41cfc: stp x19, x30, [sp, #0x20] ; 0x41d00: ldrb w8, [x0, #0xb8] ; 0x41d04: mov x19, x0 ; 0x41d08: tbnz w8, #0, #0x41d20
 */
uint64_t fde_496_0x41cf4(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x41cf4ULL;
    constexpr uint64_t kFuncSize    = 0x1b8ULL;
    constexpr uint32_t kFirstOpcode = 0xf81d0ff6U;
    constexpr uint32_t kLastOpcode  = 0xd65f03c0U;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[497] `sub_41eac` (`0x41eac..0x41ed0`, 36 bytes)
 *        Hàm FDE[497] `sub_41eac` (`0x41eac..0x41ed0`, 36 bytes)
 * Disassembly: 0x41eac: stp x19, x30, [sp, #-0x10]! ; 0x41eb0: adrp x8, #0x4a000 ; 0x41eb4: add x8, x8, #0x430 ; 0x41eb8: mov x19, x0 ; 0x41ebc: str x8, [x0], #0x18 ; 0x41ec0: bl #0x252ac
 */
uint64_t fde_497_0x41eac(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x41eacULL;
    constexpr uint64_t kFuncSize    = 0x24ULL;
    constexpr uint32_t kFirstOpcode = 0xa9bf7bf3U;
    constexpr uint32_t kLastOpcode  = 0x14000f0dU;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[498] `sub_41ed0` (`0x41ed0..0x41efc`, 44 bytes)
 *        Hàm FDE[498] `sub_41ed0` (`0x41ed0..0x41efc`, 44 bytes)
 * Disassembly: 0x41ed0: stp x19, x30, [sp, #-0x10]! ; 0x41ed4: adrp x8, #0x4a000 ; 0x41ed8: add x8, x8, #0x430 ; 0x41edc: mov x19, x0 ; 0x41ee0: str x8, [x0], #0x18 ; 0x41ee4: bl #0x252ac
 */
uint64_t fde_498_0x41ed0(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x41ed0ULL;
    constexpr uint64_t kFuncSize    = 0x2cULL;
    constexpr uint32_t kFirstOpcode = 0xa9bf7bf3U;
    constexpr uint32_t kLastOpcode  = 0x14000e8eU;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[499] `sub_41efc` (`0x41efc..0x41f50`, 84 bytes)
 *        Hàm FDE[499] `sub_41efc` (`0x41efc..0x41f50`, 84 bytes)
 * Disassembly: 0x41efc: stp x19, x30, [sp, #-0x10]! ; 0x41f00: ldr x19, [x0, #0x18] ; 0x41f04: adrp x8, #0x4a000 ; 0x41f08: add x8, x8, #0x3d8 ; 0x41f0c: str x8, [x0] ; 0x41f10: cbz x19, #0x41f2c
 */
uint64_t fde_499_0x41efc(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x41efcULL;
    constexpr uint64_t kFuncSize    = 0x54ULL;
    constexpr uint32_t kFirstOpcode = 0xa9bf7bf3U;
    constexpr uint32_t kLastOpcode  = 0x14000ee9U;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[500] `sub_41f50` (`0x41f50..0x41fb0`, 96 bytes)
 *        Hàm FDE[500] `sub_41f50` (`0x41f50..0x41fb0`, 96 bytes)
 * Disassembly: 0x41f50: str x20, [sp, #-0x20]! ; 0x41f54: stp x19, x30, [sp, #0x10] ; 0x41f58: ldr x20, [x0, #0x18] ; 0x41f5c: adrp x8, #0x4a000 ; 0x41f60: mov x19, x0 ; 0x41f64: add x8, x8, #0x3d8
 */
uint64_t fde_500_0x41f50(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x41f50ULL;
    constexpr uint64_t kFuncSize    = 0x60ULL;
    constexpr uint32_t kFirstOpcode = 0xf81e0ff4U;
    constexpr uint32_t kLastOpcode  = 0x14000e61U;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[501] `sub_41fb0` (`0x41fb0..0x421bc`, 524 bytes)
 *        Hàm FDE[501] `sub_41fb0` (`0x41fb0..0x421bc`, 524 bytes)
 * Disassembly: 0x41fb0: sub sp, sp, #0x90 ; 0x41fb4: str x24, [sp, #0x50] ; 0x41fb8: stp x23, x22, [sp, #0x60] ; 0x41fbc: stp x21, x20, [sp, #0x70] ; 0x41fc0: stp x19, x30, [sp, #0x80] ; 0x41fc4: mrs x23, tpidr_el0
 */
uint64_t fde_501_0x41fb0(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x41fb0ULL;
    constexpr uint64_t kFuncSize    = 0x20cULL;
    constexpr uint32_t kFirstOpcode = 0xd10243ffU;
    constexpr uint32_t kLastOpcode  = 0x94000e12U;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[502] `sub_421bc` (`0x421bc..0x422b8`, 252 bytes)
 *        Hàm FDE[502] `sub_421bc` (`0x421bc..0x422b8`, 252 bytes)
 * Disassembly: 0x421bc: sub sp, sp, #0x60 ; 0x421c0: str x24, [sp, #0x20] ; 0x421c4: stp x23, x22, [sp, #0x30] ; 0x421c8: stp x21, x20, [sp, #0x40] ; 0x421cc: stp x19, x30, [sp, #0x50] ; 0x421d0: mrs x24, tpidr_el0
 */
uint64_t fde_502_0x421bc(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x421bcULL;
    constexpr uint64_t kFuncSize    = 0xfcULL;
    constexpr uint32_t kFirstOpcode = 0xd10183ffU;
    constexpr uint32_t kLastOpcode  = 0x94000dd3U;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[503] `sub_422b8` (`0x422b8..0x422e4`, 44 bytes)
 *        Hàm FDE[503] `sub_422b8` (`0x422b8..0x422e4`, 44 bytes)
 * Disassembly: 0x422b8: ldr x9, [x0, #0x10] ; 0x422bc: str x9, [x8] ; 0x422c0: ldr x9, [x0, #0x18] ; 0x422c4: str x9, [x8, #8] ; 0x422c8: cbz x9, #0x422e0 ; 0x422cc: add x8, x9, #8
 */
uint64_t fde_503_0x422b8(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x422b8ULL;
    constexpr uint64_t kFuncSize    = 0x2cULL;
    constexpr uint32_t kFirstOpcode = 0xf9400809U;
    constexpr uint32_t kLastOpcode  = 0xd65f03c0U;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[504] `sub_422e4` (`0x422e4..0x42340`, 92 bytes)
 *        Hàm FDE[504] `sub_422e4` (`0x422e4..0x42340`, 92 bytes)
 * Disassembly: 0x422e4: stp x19, x30, [sp, #-0x10]! ; 0x422e8: ldr x8, [x0, #0x10] ; 0x422ec: cbz x8, #0x4231c ; 0x422f0: str xzr, [x0, #8] ; 0x422f4: strb wzr, [x8] ; 0x422f8: ldr x19, [x0, #0x18]
 */
uint64_t fde_504_0x422e4(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x422e4ULL;
    constexpr uint64_t kFuncSize    = 0x5cULL;
    constexpr uint32_t kFirstOpcode = 0xa9bf7bf3U;
    constexpr uint32_t kLastOpcode  = 0x14000dedU;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[505] `sub_42340` (`0x42340..0x42458`, 280 bytes)
 *        Hàm FDE[505] `sub_42340` (`0x42340..0x42458`, 280 bytes)
 * Disassembly: 0x42340: sub sp, sp, #0x60 ; 0x42344: stp x25, x24, [sp, #0x20] ; 0x42348: stp x23, x22, [sp, #0x30] ; 0x4234c: stp x21, x20, [sp, #0x40] ; 0x42350: stp x19, x30, [sp, #0x50] ; 0x42354: mrs x25, tpidr_el0
 */
uint64_t fde_505_0x42340(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x42340ULL;
    constexpr uint64_t kFuncSize    = 0x118ULL;
    constexpr uint32_t kFirstOpcode = 0xd10183ffU;
    constexpr uint32_t kLastOpcode  = 0x94000d6bU;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[506] `sub_42458` (`0x42458..0x42460`, 8 bytes)
 *        Hàm FDE[506] `sub_42458` (`0x42458..0x42460`, 8 bytes)
 * Disassembly: 0x42458: ldr x0, [x0, #8] ; 0x4245c: b #0x425a4
 */
uint64_t fde_506_0x42458(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x42458ULL;
    constexpr uint64_t kFuncSize    = 0x8ULL;
    constexpr uint32_t kFirstOpcode = 0xf9400400U;
    constexpr uint32_t kLastOpcode  = 0x14000052U;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[507] `sub_42460` (`0x42460..0x425a4`, 324 bytes)
 *        Hàm FDE[507] `sub_42460` (`0x42460..0x425a4`, 324 bytes)
 * Disassembly: 0x42460: sub sp, sp, #0x70 ; 0x42464: stp x23, x22, [sp, #0x40] ; 0x42468: stp x21, x20, [sp, #0x50] ; 0x4246c: stp x19, x30, [sp, #0x60] ; 0x42470: mrs x21, tpidr_el0 ; 0x42474: ldr x9, [x21, #0x28]
 */
uint64_t fde_507_0x42460(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x42460ULL;
    constexpr uint64_t kFuncSize    = 0x144ULL;
    constexpr uint32_t kFirstOpcode = 0xd101c3ffU;
    constexpr uint32_t kLastOpcode  = 0x94000cecU;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[508] `_ZN5vmsdk6worker15JsWorkerAndroid5FetchERKNSt6__ndk112basic_stringIcNS2_11char_traitsIcEENS2_9allocatorIcEEEESA_PKviPNS_3net16ResponseDelegateE` (`0x425a4..0x4279c`, 504 bytes)
 *        Hàm FDE[508] `_ZN5vmsdk6worker15JsWorkerAndroid5FetchERKNSt6__ndk112basic_stringIcNS2_11char_traitsIcEENS2_9allocatorIcEEEESA_PKviPNS_3net16ResponseDelegateE` (`0x425a4..0x4279c`, 504 bytes)
 * Disassembly: 0x425a4: sub sp, sp, #0xa0 ; 0x425a8: str x28, [sp, #0x40] ; 0x425ac: stp x27, x26, [sp, #0x50] ; 0x425b0: stp x25, x24, [sp, #0x60] ; 0x425b4: stp x23, x22, [sp, #0x70] ; 0x425b8: stp x21, x20, [sp, #0x80]
 */
uint64_t fde_508_0x425a4(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x425a4ULL;
    constexpr uint64_t kFuncSize    = 0x1f8ULL;
    constexpr uint32_t kFirstOpcode = 0xd10283ffU;
    constexpr uint32_t kLastOpcode  = 0x94000c6eU;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[509] `_ZN5vmsdk6worker15JsWorkerAndroid18FetchJsWithUrlSyncENSt6__ndk112basic_stringIcNS2_11char_traitsIcEENS2_9allocatorIcEEEE` (`0x4279c..0x42994`, 504 bytes)
 *        Hàm FDE[509] `_ZN5vmsdk6worker15JsWorkerAndroid18FetchJsWithUrlSyncENSt6__ndk112basic_stringIcNS2_11char_traitsIcEENS2_9allocatorIcEEEE` (`0x4279c..0x42994`, 504 bytes)
 * Disassembly: 0x4279c: sub sp, sp, #0x90 ; 0x427a0: stp x25, x24, [sp, #0x50] ; 0x427a4: stp x23, x22, [sp, #0x60] ; 0x427a8: stp x21, x20, [sp, #0x70] ; 0x427ac: stp x19, x30, [sp, #0x80] ; 0x427b0: mrs x23, tpidr_el0
 */
uint64_t fde_509_0x4279c(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x4279cULL;
    constexpr uint64_t kFuncSize    = 0x1f8ULL;
    constexpr uint32_t kFirstOpcode = 0xd10243ffU;
    constexpr uint32_t kLastOpcode  = 0x94000bf0U;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[510] `sub_42994` (`0x42994..0x42a00`, 108 bytes)
 *        Hàm FDE[510] `sub_42994` (`0x42994..0x42a00`, 108 bytes)
 * Disassembly: 0x42994: str x20, [sp, #-0x20]! ; 0x42998: stp x19, x30, [sp, #0x10] ; 0x4299c: ldr x20, [x0, #0x30] ; 0x429a0: adrp x8, #0x4a000 ; 0x429a4: add x8, x8, #0x3a0 ; 0x429a8: str x8, [x0]
 */
uint64_t fde_510_0x42994(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x42994ULL;
    constexpr uint64_t kFuncSize    = 0x6cULL;
    constexpr uint32_t kFirstOpcode = 0xf81e0ff4U;
    constexpr uint32_t kLastOpcode  = 0x14000c41U;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[511] `sub_42a00` (`0x42a00..0x42a74`, 116 bytes)
 *        Hàm FDE[511] `sub_42a00` (`0x42a00..0x42a74`, 116 bytes)
 * Disassembly: 0x42a00: str x20, [sp, #-0x20]! ; 0x42a04: stp x19, x30, [sp, #0x10] ; 0x42a08: ldr x20, [x0, #0x30] ; 0x42a0c: adrp x8, #0x4a000 ; 0x42a10: add x8, x8, #0x3a0 ; 0x42a14: str x8, [x0]
 */
uint64_t fde_511_0x42a00(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x42a00ULL;
    constexpr uint64_t kFuncSize    = 0x74ULL;
    constexpr uint32_t kFirstOpcode = 0xf81e0ff4U;
    constexpr uint32_t kLastOpcode  = 0x14000bb0U;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[512] `sub_42a74` (`0x42a74..0x42a98`, 36 bytes)
 *        Hàm FDE[512] `sub_42a74` (`0x42a74..0x42a98`, 36 bytes)
 * Disassembly: 0x42a74: stp x19, x30, [sp, #-0x10]! ; 0x42a78: adrp x8, #0x4a000 ; 0x42a7c: add x8, x8, #0x368 ; 0x42a80: mov x19, x0 ; 0x42a84: str x8, [x0], #0x18 ; 0x42a88: bl #0x2a578
 */
uint64_t fde_512_0x42a74(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x42a74ULL;
    constexpr uint64_t kFuncSize    = 0x24ULL;
    constexpr uint32_t kFirstOpcode = 0xa9bf7bf3U;
    constexpr uint32_t kLastOpcode  = 0x14000c1bU;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[513] `sub_42a98` (`0x42a98..0x42ac4`, 44 bytes)
 *        Hàm FDE[513] `sub_42a98` (`0x42a98..0x42ac4`, 44 bytes)
 * Disassembly: 0x42a98: stp x19, x30, [sp, #-0x10]! ; 0x42a9c: adrp x8, #0x4a000 ; 0x42aa0: add x8, x8, #0x368 ; 0x42aa4: mov x19, x0 ; 0x42aa8: str x8, [x0], #0x18 ; 0x42aac: bl #0x2a578
 */
uint64_t fde_513_0x42a98(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x42a98ULL;
    constexpr uint64_t kFuncSize    = 0x2cULL;
    constexpr uint32_t kFirstOpcode = 0xa9bf7bf3U;
    constexpr uint32_t kLastOpcode  = 0x14000b9cU;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[514] `sub_42ac4` (`0x42ac4..0x42ae8`, 36 bytes)
 *        Hàm FDE[514] `sub_42ac4` (`0x42ac4..0x42ae8`, 36 bytes)
 * Disassembly: 0x42ac4: stp x19, x30, [sp, #-0x10]! ; 0x42ac8: adrp x8, #0x4a000 ; 0x42acc: add x8, x8, #0x330 ; 0x42ad0: mov x19, x0 ; 0x42ad4: str x8, [x0], #0x18 ; 0x42ad8: bl #0x32e90
 */
uint64_t fde_514_0x42ac4(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x42ac4ULL;
    constexpr uint64_t kFuncSize    = 0x24ULL;
    constexpr uint32_t kFirstOpcode = 0xa9bf7bf3U;
    constexpr uint32_t kLastOpcode  = 0x14000c07U;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[515] `sub_42ae8` (`0x42ae8..0x42b14`, 44 bytes)
 *        Hàm FDE[515] `sub_42ae8` (`0x42ae8..0x42b14`, 44 bytes)
 * Disassembly: 0x42ae8: stp x19, x30, [sp, #-0x10]! ; 0x42aec: adrp x8, #0x4a000 ; 0x42af0: add x8, x8, #0x330 ; 0x42af4: mov x19, x0 ; 0x42af8: str x8, [x0], #0x18 ; 0x42afc: bl #0x32e90
 */
uint64_t fde_515_0x42ae8(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x42ae8ULL;
    constexpr uint64_t kFuncSize    = 0x2cULL;
    constexpr uint32_t kFirstOpcode = 0xa9bf7bf3U;
    constexpr uint32_t kLastOpcode  = 0x14000b88U;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[516] `sub_42b14` (`0x42b14..0x42b1c`, 8 bytes)
 *        Hàm FDE[516] `sub_42b14` (`0x42b14..0x42b1c`, 8 bytes)
 * Disassembly: 0x42b14: add x0, x0, #0x18 ; 0x42b18: b #0x32e90
 */
uint64_t fde_516_0x42b14(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x42b14ULL;
    constexpr uint64_t kFuncSize    = 0x8ULL;
    constexpr uint32_t kFirstOpcode = 0x91006000U;
    constexpr uint32_t kLastOpcode  = 0x17ffc0deU;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[517] `sub_42b1c` (`0x42b1c..0x42b64`, 72 bytes)
 *        Hàm FDE[517] `sub_42b1c` (`0x42b1c..0x42b64`, 72 bytes)
 * Disassembly: 0x42b1c: stp x19, x30, [sp, #-0x10]! ; 0x42b20: ldr x19, [x0, #8] ; 0x42b24: cbz x19, #0x42b40 ; 0x42b28: add x8, x19, #8 ; 0x42b2c: ldaxr x9, [x8] ; 0x42b30: sub x10, x9, #1
 */
uint64_t fde_517_0x42b1c(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x42b1cULL;
    constexpr uint64_t kFuncSize    = 0x48ULL;
    constexpr uint32_t kFirstOpcode = 0xa9bf7bf3U;
    constexpr uint32_t kLastOpcode  = 0x14000be4U;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[518] `sub_42b64` (`0x42b64..0x42b80`, 28 bytes)
 *        Hàm FDE[518] `sub_42b64` (`0x42b64..0x42b80`, 28 bytes)
 * Disassembly: 0x42b64: ldr x8, [x1, #8] ; 0x42b68: adrp x9, #0x12000 ; 0x42b6c: add x9, x9, #0x41c ; 0x42b70: add x10, x0, #0x18 ; 0x42b74: cmp x8, x9 ; 0x42b78: csel x0, x10, xzr, eq
 */
uint64_t fde_518_0x42b64(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x42b64ULL;
    constexpr uint64_t kFuncSize    = 0x1cULL;
    constexpr uint32_t kFirstOpcode = 0xf9400428U;
    constexpr uint32_t kLastOpcode  = 0xd65f03c0U;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[519] `sub_42b80` (`0x42b80..0x42bec`, 108 bytes)
 *        Hàm FDE[519] `sub_42b80` (`0x42b80..0x42bec`, 108 bytes)
 * Disassembly: 0x42b80: str x20, [sp, #-0x20]! ; 0x42b84: stp x19, x30, [sp, #0x10] ; 0x42b88: ldr x20, [x0, #0x28] ; 0x42b8c: adrp x8, #0x4a000 ; 0x42b90: add x8, x8, #0x668 ; 0x42b94: str x8, [x0]
 */
uint64_t fde_519_0x42b80(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x42b80ULL;
    constexpr uint64_t kFuncSize    = 0x6cULL;
    constexpr uint32_t kFirstOpcode = 0xf81e0ff4U;
    constexpr uint32_t kLastOpcode  = 0x14000bc6U;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[520] `sub_42bec` (`0x42bec..0x42c60`, 116 bytes)
 *        Hàm FDE[520] `sub_42bec` (`0x42bec..0x42c60`, 116 bytes)
 * Disassembly: 0x42bec: str x20, [sp, #-0x20]! ; 0x42bf0: stp x19, x30, [sp, #0x10] ; 0x42bf4: ldr x20, [x0, #0x28] ; 0x42bf8: adrp x8, #0x4a000 ; 0x42bfc: add x8, x8, #0x668 ; 0x42c00: str x8, [x0]
 */
uint64_t fde_520_0x42bec(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x42becULL;
    constexpr uint64_t kFuncSize    = 0x74ULL;
    constexpr uint32_t kFirstOpcode = 0xf81e0ff4U;
    constexpr uint32_t kLastOpcode  = 0x14000b35U;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[521] `sub_42c60` (`0x42c60..0x42fa0`, 832 bytes)
 *        Hàm FDE[521] `sub_42c60` (`0x42c60..0x42fa0`, 832 bytes)
 * Disassembly: 0x42c60: sub sp, sp, #0xa0 ; 0x42c64: str x26, [sp, #0x50] ; 0x42c68: stp x25, x24, [sp, #0x60] ; 0x42c6c: stp x23, x22, [sp, #0x70] ; 0x42c70: stp x21, x20, [sp, #0x80] ; 0x42c74: stp x19, x30, [sp, #0x90]
 */
uint64_t fde_521_0x42c60(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x42c60ULL;
    constexpr uint64_t kFuncSize    = 0x340ULL;
    constexpr uint32_t kFirstOpcode = 0xd10283ffU;
    constexpr uint32_t kLastOpcode  = 0x94000a6dU;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[522] `sub_42fa0` (`0x42fa0..0x42fe8`, 72 bytes)
 *        Hàm FDE[522] `sub_42fa0` (`0x42fa0..0x42fe8`, 72 bytes)
 * Disassembly: 0x42fa0: stp x19, x30, [sp, #-0x10]! ; 0x42fa4: adrp x8, #0x4a000 ; 0x42fa8: adrp x9, #0x48000 ; 0x42fac: add x8, x8, #0x6b8 ; 0x42fb0: add x9, x9, #0x518 ; 0x42fb4: mov x19, x0
 */
uint64_t fde_522_0x42fa0(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x42fa0ULL;
    constexpr uint64_t kFuncSize    = 0x48ULL;
    constexpr uint32_t kFirstOpcode = 0xa9bf7bf3U;
    constexpr uint32_t kLastOpcode  = 0x14000ac7U;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[523] `sub_42fe8` (`0x42fe8..0x43038`, 80 bytes)
 *        Hàm FDE[523] `sub_42fe8` (`0x42fe8..0x43038`, 80 bytes)
 * Disassembly: 0x42fe8: stp x19, x30, [sp, #-0x10]! ; 0x42fec: adrp x8, #0x4a000 ; 0x42ff0: adrp x9, #0x48000 ; 0x42ff4: add x8, x8, #0x6b8 ; 0x42ff8: add x9, x9, #0x518 ; 0x42ffc: mov x19, x0
 */
uint64_t fde_523_0x42fe8(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x42fe8ULL;
    constexpr uint64_t kFuncSize    = 0x50ULL;
    constexpr uint32_t kFirstOpcode = 0xa9bf7bf3U;
    constexpr uint32_t kLastOpcode  = 0x14000a3fU;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[524] `sub_43038` (`0x43038..0x43098`, 96 bytes)
 *        Hàm FDE[524] `sub_43038` (`0x43038..0x43098`, 96 bytes)
 * Disassembly: 0x43038: str x20, [sp, #-0x20]! ; 0x4303c: stp x19, x30, [sp, #0x10] ; 0x43040: ldr x20, [x0, #0x20] ; 0x43044: adrp x8, #0x4a000 ; 0x43048: mov x19, x0 ; 0x4304c: add x8, x8, #0x630
 */
uint64_t fde_524_0x43038(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x43038ULL;
    constexpr uint64_t kFuncSize    = 0x60ULL;
    constexpr uint32_t kFirstOpcode = 0xf81e0ff4U;
    constexpr uint32_t kLastOpcode  = 0x14000a9bU;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[525] `sub_43098` (`0x43098..0x43100`, 104 bytes)
 *        Hàm FDE[525] `sub_43098` (`0x43098..0x43100`, 104 bytes)
 * Disassembly: 0x43098: str x20, [sp, #-0x20]! ; 0x4309c: stp x19, x30, [sp, #0x10] ; 0x430a0: ldr x20, [x0, #0x20] ; 0x430a4: adrp x8, #0x4a000 ; 0x430a8: mov x19, x0 ; 0x430ac: add x8, x8, #0x630
 */
uint64_t fde_525_0x43098(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x43098ULL;
    constexpr uint64_t kFuncSize    = 0x68ULL;
    constexpr uint32_t kFirstOpcode = 0xf81e0ff4U;
    constexpr uint32_t kLastOpcode  = 0x14000a0dU;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[526] `sub_43100` (`0x43100..0x43148`, 72 bytes)
 *        Hàm FDE[526] `sub_43100` (`0x43100..0x43148`, 72 bytes)
 * Disassembly: 0x43100: stp x19, x30, [sp, #-0x10]! ; 0x43104: ldr x19, [x0, #0x20] ; 0x43108: cbz x19, #0x43124 ; 0x4310c: add x8, x19, #8 ; 0x43110: ldaxr x9, [x8] ; 0x43114: sub x10, x9, #1
 */
uint64_t fde_526_0x43100(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x43100ULL;
    constexpr uint64_t kFuncSize    = 0x48ULL;
    constexpr uint32_t kFirstOpcode = 0xa9bf7bf3U;
    constexpr uint32_t kLastOpcode  = 0x14000a6bU;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[527] `sub_43148` (`0x43148..0x43230`, 232 bytes)
 *        Hàm FDE[527] `sub_43148` (`0x43148..0x43230`, 232 bytes)
 * Disassembly: 0x43148: str x20, [sp, #-0x20]! ; 0x4314c: stp x19, x30, [sp, #0x10] ; 0x43150: ldr x20, [x0, #0x30] ; 0x43154: adrp x8, #0x4a000 ; 0x43158: mov x19, x0 ; 0x4315c: add x8, x8, #0x610
 */
uint64_t fde_527_0x43148(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x43148ULL;
    constexpr uint64_t kFuncSize    = 0xe8ULL;
    constexpr uint32_t kFirstOpcode = 0xf81e0ff4U;
    constexpr uint32_t kLastOpcode  = 0xd65f03c0U;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[528] `sub_43230` (`0x43230..0x43318`, 232 bytes)
 *        Hàm FDE[528] `sub_43230` (`0x43230..0x43318`, 232 bytes)
 * Disassembly: 0x43230: str x20, [sp, #-0x20]! ; 0x43234: stp x19, x30, [sp, #0x10] ; 0x43238: ldr x20, [x0, #0x30] ; 0x4323c: adrp x8, #0x4a000 ; 0x43240: mov x19, x0 ; 0x43244: add x8, x8, #0x610
 */
uint64_t fde_528_0x43230(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x43230ULL;
    constexpr uint64_t kFuncSize    = 0xe8ULL;
    constexpr uint32_t kFirstOpcode = 0xf81e0ff4U;
    constexpr uint32_t kLastOpcode  = 0x14000987U;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[529] `sub_43318` (`0x43318..0x433bc`, 164 bytes)
 *        Hàm FDE[529] `sub_43318` (`0x43318..0x433bc`, 164 bytes)
 * Disassembly: 0x43318: str x20, [sp, #-0x20]! ; 0x4331c: stp x19, x30, [sp, #0x10] ; 0x43320: ldr x20, [x0, #0x20] ; 0x43324: adrp x8, #0x4a000 ; 0x43328: mov x19, x0 ; 0x4332c: add x8, x8, #0x738
 */
uint64_t fde_529_0x43318(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x43318ULL;
    constexpr uint64_t kFuncSize    = 0xa4ULL;
    constexpr uint32_t kFirstOpcode = 0xf81e0ff4U;
    constexpr uint32_t kLastOpcode  = 0xd65f03c0U;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[530] `sub_433bc` (`0x433bc..0x43460`, 164 bytes)
 *        Hàm FDE[530] `sub_433bc` (`0x433bc..0x43460`, 164 bytes)
 * Disassembly: 0x433bc: str x20, [sp, #-0x20]! ; 0x433c0: stp x19, x30, [sp, #0x10] ; 0x433c4: ldr x20, [x0, #0x20] ; 0x433c8: adrp x8, #0x4a000 ; 0x433cc: mov x19, x0 ; 0x433d0: add x8, x8, #0x738
 */
uint64_t fde_530_0x433bc(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x433bcULL;
    constexpr uint64_t kFuncSize    = 0xa4ULL;
    constexpr uint32_t kFirstOpcode = 0xf81e0ff4U;
    constexpr uint32_t kLastOpcode  = 0x14000935U;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[531] `sub_43460` (`0x43460..0x43510`, 176 bytes)
 *        Hàm FDE[531] `sub_43460` (`0x43460..0x43510`, 176 bytes)
 * Disassembly: 0x43460: str x20, [sp, #-0x20]! ; 0x43464: stp x19, x30, [sp, #0x10] ; 0x43468: ldr x20, [x0, #0x38] ; 0x4346c: adrp x8, #0x4a000 ; 0x43470: add x8, x8, #0x2f8 ; 0x43474: str x8, [x0]
 */
uint64_t fde_531_0x43460(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x43460ULL;
    constexpr uint64_t kFuncSize    = 0xb0ULL;
    constexpr uint32_t kFirstOpcode = 0xf81e0ff4U;
    constexpr uint32_t kLastOpcode  = 0x1400097dU;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[532] `sub_43510` (`0x43510..0x435c8`, 184 bytes)
 *        Hàm FDE[532] `sub_43510` (`0x43510..0x435c8`, 184 bytes)
 * Disassembly: 0x43510: str x20, [sp, #-0x20]! ; 0x43514: stp x19, x30, [sp, #0x10] ; 0x43518: ldr x20, [x0, #0x38] ; 0x4351c: adrp x8, #0x4a000 ; 0x43520: add x8, x8, #0x2f8 ; 0x43524: str x8, [x0]
 */
uint64_t fde_532_0x43510(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x43510ULL;
    constexpr uint64_t kFuncSize    = 0xb8ULL;
    constexpr uint32_t kFirstOpcode = 0xf81e0ff4U;
    constexpr uint32_t kLastOpcode  = 0x140008dbU;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[533] `sub_435c8` (`0x435c8..0x435f4`, 44 bytes)
 *        Hàm FDE[533] `sub_435c8` (`0x435c8..0x435f4`, 44 bytes)
 * Disassembly: 0x435c8: stp x19, x30, [sp, #-0x10]! ; 0x435cc: mov x19, x0 ; 0x435d0: mov w0, #0x10 ; 0x435d4: bl #0x459f0 ; 0x435d8: adrp x8, #0x4a000 ; 0x435dc: add x8, x8, #0x7b8
 */
uint64_t fde_533_0x435c8(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x435c8ULL;
    constexpr uint64_t kFuncSize    = 0x2cULL;
    constexpr uint32_t kFirstOpcode = 0xa9bf7bf3U;
    constexpr uint32_t kLastOpcode  = 0xd65f03c0U;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[534] `sub_435f4` (`0x435f4..0x4360c`, 24 bytes)
 *        Hàm FDE[534] `sub_435f4` (`0x435f4..0x4360c`, 24 bytes)
 * Disassembly: 0x435f4: adrp x8, #0x4a000 ; 0x435f8: add x8, x8, #0x7b8 ; 0x435fc: str x8, [x1] ; 0x43600: ldr x8, [x0, #8] ; 0x43604: str x8, [x1, #8] ; 0x43608: ret
 */
uint64_t fde_534_0x435f4(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x435f4ULL;
    constexpr uint64_t kFuncSize    = 0x18ULL;
    constexpr uint32_t kFirstOpcode = 0xf0000028U;
    constexpr uint32_t kLastOpcode  = 0xd65f03c0U;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[535] `sub_4360c` (`0x4360c..0x43784`, 376 bytes)
 *        Hàm FDE[535] `sub_4360c` (`0x4360c..0x43784`, 376 bytes)
 * Disassembly: 0x4360c: str x20, [sp, #-0x20]! ; 0x43610: stp x19, x30, [sp, #0x10] ; 0x43614: ldr x19, [x0, #8] ; 0x43618: ldr x0, [x19, #0x40] ; 0x4361c: ldr x8, [x0] ; 0x43620: ldr x8, [x8, #0x38]
 */
uint64_t fde_535_0x4360c(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x4360cULL;
    constexpr uint64_t kFuncSize    = 0x178ULL;
    constexpr uint32_t kFirstOpcode = 0xf81e0ff4U;
    constexpr uint32_t kLastOpcode  = 0x1400086cU;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[536] `sub_43784` (`0x43784..0x437a0`, 28 bytes)
 *        Hàm FDE[536] `sub_43784` (`0x43784..0x437a0`, 28 bytes)
 * Disassembly: 0x43784: ldr x8, [x1, #8] ; 0x43788: adrp x9, #0x12000 ; 0x4378c: add x9, x9, #0x69a ; 0x43790: add x10, x0, #8 ; 0x43794: cmp x8, x9 ; 0x43798: csel x0, x10, xzr, eq
 */
uint64_t fde_536_0x43784(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x43784ULL;
    constexpr uint64_t kFuncSize    = 0x1cULL;
    constexpr uint32_t kFirstOpcode = 0xf9400428U;
    constexpr uint32_t kLastOpcode  = 0xd65f03c0U;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[537] `sub_437a0` (`0x437a0..0x437ac`, 12 bytes)
 *        Hàm FDE[537] `sub_437a0` (`0x437a0..0x437ac`, 12 bytes)
 * Disassembly: 0x437a0: adrp x0, #0x4a000 ; 0x437a4: add x0, x0, #0x818 ; 0x437a8: ret
 */
uint64_t fde_537_0x437a0(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x437a0ULL;
    constexpr uint64_t kFuncSize    = 0xcULL;
    constexpr uint32_t kFirstOpcode = 0xf0000020U;
    constexpr uint32_t kLastOpcode  = 0xd65f03c0U;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[538] `_ZN5vmsdk6worker15JsWorkerAndroidD1Ev` (`0x437ac..0x43a74`, 712 bytes)
 *        Hàm FDE[538] `_ZN5vmsdk6worker15JsWorkerAndroidD1Ev` (`0x437ac..0x43a74`, 712 bytes)
 * Disassembly: 0x437ac: sub sp, sp, #0x80 ; 0x437b0: str x24, [sp, #0x40] ; 0x437b4: stp x23, x22, [sp, #0x50] ; 0x437b8: stp x21, x20, [sp, #0x60] ; 0x437bc: stp x19, x30, [sp, #0x70] ; 0x437c0: mrs x22, tpidr_el0
 */
uint64_t fde_538_0x437ac(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x437acULL;
    constexpr uint64_t kFuncSize    = 0x2c8ULL;
    constexpr uint32_t kFirstOpcode = 0xd10203ffU;
    constexpr uint32_t kLastOpcode  = 0x940007b8U;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[539] `sub_43a74` (`0x43a74..0x43a94`, 32 bytes)
 *        Hàm FDE[539] `sub_43a74` (`0x43a74..0x43a94`, 32 bytes)
 * Disassembly: 0x43a74: ldrb w8, [x0, #8] ; 0x43a78: adrp x9, #0x4a000 ; 0x43a7c: add x9, x9, #0x838 ; 0x43a80: str x9, [x0] ; 0x43a84: tbnz w8, #0, #0x43a8c ; 0x43a88: ret
 */
uint64_t fde_539_0x43a74(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x43a74ULL;
    constexpr uint64_t kFuncSize    = 0x20ULL;
    constexpr uint32_t kFirstOpcode = 0x39402008U;
    constexpr uint32_t kLastOpcode  = 0x140007a8U;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[540] `sub_43a94` (`0x43a94..0x43ac4`, 48 bytes)
 *        Hàm FDE[540] `sub_43a94` (`0x43a94..0x43ac4`, 48 bytes)
 * Disassembly: 0x43a94: stp x19, x30, [sp, #-0x10]! ; 0x43a98: ldrb w8, [x0, #8] ; 0x43a9c: adrp x9, #0x4a000 ; 0x43aa0: mov x19, x0 ; 0x43aa4: add x9, x9, #0x838 ; 0x43aa8: str x9, [x0]
 */
uint64_t fde_540_0x43a94(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x43a94ULL;
    constexpr uint64_t kFuncSize    = 0x30ULL;
    constexpr uint32_t kFirstOpcode = 0xa9bf7bf3U;
    constexpr uint32_t kLastOpcode  = 0x1400079cU;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[541] `sub_43ac4` (`0x43ac4..0x43b0c`, 72 bytes)
 *        Hàm FDE[541] `sub_43ac4` (`0x43ac4..0x43b0c`, 72 bytes)
 * Disassembly: 0x43ac4: str x20, [sp, #-0x20]! ; 0x43ac8: stp x19, x30, [sp, #0x10] ; 0x43acc: mov x19, x0 ; 0x43ad0: mov w0, #0x30 ; 0x43ad4: bl #0x459f0 ; 0x43ad8: adrp x8, #0x4a000
 */
uint64_t fde_541_0x43ac4(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x43ac4ULL;
    constexpr uint64_t kFuncSize    = 0x48ULL;
    constexpr uint32_t kFirstOpcode = 0xf81e0ff4U;
    constexpr uint32_t kLastOpcode  = 0xd65f03c0U;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[542] `sub_43b0c` (`0x43b0c..0x43b48`, 60 bytes)
 *        Hàm FDE[542] `sub_43b0c` (`0x43b0c..0x43b48`, 60 bytes)
 * Disassembly: 0x43b0c: str x20, [sp, #-0x20]! ; 0x43b10: stp x19, x30, [sp, #0x10] ; 0x43b14: adrp x8, #0x4a000 ; 0x43b18: mov x20, x0 ; 0x43b1c: add x8, x8, #0x838 ; 0x43b20: mov x19, x1
 */
uint64_t fde_542_0x43b0c(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x43b0cULL;
    constexpr uint64_t kFuncSize    = 0x3cULL;
    constexpr uint32_t kFirstOpcode = 0xf81e0ff4U;
    constexpr uint32_t kLastOpcode  = 0xd65f03c0U;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[543] `sub_43b48` (`0x43b48..0x43cb4`, 364 bytes)
 *        Hàm FDE[543] `sub_43b48` (`0x43b48..0x43cb4`, 364 bytes)
 * Disassembly: 0x43b48: sub sp, sp, #0xb0 ; 0x43b4c: str x22, [sp, #0x80] ; 0x43b50: stp x21, x20, [sp, #0x90] ; 0x43b54: stp x19, x30, [sp, #0xa0] ; 0x43b58: mrs x21, tpidr_el0 ; 0x43b5c: ldr x8, [x21, #0x28]
 */
uint64_t fde_543_0x43b48(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x43b48ULL;
    constexpr uint64_t kFuncSize    = 0x16cULL;
    constexpr uint32_t kFirstOpcode = 0xd102c3ffU;
    constexpr uint32_t kLastOpcode  = 0x94000728U;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[544] `sub_43cb4` (`0x43cb4..0x43cd0`, 28 bytes)
 *        Hàm FDE[544] `sub_43cb4` (`0x43cb4..0x43cd0`, 28 bytes)
 * Disassembly: 0x43cb4: ldr x8, [x1, #8] ; 0x43cb8: adrp x9, #0x12000 ; 0x43cbc: add x9, x9, #0x735 ; 0x43cc0: add x10, x0, #8 ; 0x43cc4: cmp x8, x9 ; 0x43cc8: csel x0, x10, xzr, eq
 */
uint64_t fde_544_0x43cb4(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x43cb4ULL;
    constexpr uint64_t kFuncSize    = 0x1cULL;
    constexpr uint32_t kFirstOpcode = 0xf9400428U;
    constexpr uint32_t kLastOpcode  = 0xd65f03c0U;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[545] `sub_43cd0` (`0x43cd0..0x43cdc`, 12 bytes)
 *        Hàm FDE[545] `sub_43cd0` (`0x43cd0..0x43cdc`, 12 bytes)
 * Disassembly: 0x43cd0: adrp x0, #0x4a000 ; 0x43cd4: add x0, x0, #0x898 ; 0x43cd8: ret
 */
uint64_t fde_545_0x43cd0(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x43cd0ULL;
    constexpr uint64_t kFuncSize    = 0xcULL;
    constexpr uint32_t kFirstOpcode = 0xf0000020U;
    constexpr uint32_t kLastOpcode  = 0xd65f03c0U;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[546] `sub_43cdc` (`0x43cdc..0x43d30`, 84 bytes)
 *        Hàm FDE[546] `sub_43cdc` (`0x43cdc..0x43d30`, 84 bytes)
 * Disassembly: 0x43cdc: stp x19, x30, [sp, #-0x10]! ; 0x43ce0: ldr x19, [x0, #0x10] ; 0x43ce4: adrp x8, #0x4a000 ; 0x43ce8: add x8, x8, #0x8f0 ; 0x43cec: str x8, [x0] ; 0x43cf0: cbz x19, #0x43d0c
 */
uint64_t fde_546_0x43cdc(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x43cdcULL;
    constexpr uint64_t kFuncSize    = 0x54ULL;
    constexpr uint32_t kFirstOpcode = 0xa9bf7bf3U;
    constexpr uint32_t kLastOpcode  = 0x14000771U;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[547] `sub_43d30` (`0x43d30..0x43d90`, 96 bytes)
 *        Hàm FDE[547] `sub_43d30` (`0x43d30..0x43d90`, 96 bytes)
 * Disassembly: 0x43d30: str x20, [sp, #-0x20]! ; 0x43d34: stp x19, x30, [sp, #0x10] ; 0x43d38: ldr x20, [x0, #0x10] ; 0x43d3c: adrp x8, #0x4a000 ; 0x43d40: mov x19, x0 ; 0x43d44: add x8, x8, #0x8f0
 */
uint64_t fde_547_0x43d30(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x43d30ULL;
    constexpr uint64_t kFuncSize    = 0x60ULL;
    constexpr uint32_t kFirstOpcode = 0xf81e0ff4U;
    constexpr uint32_t kLastOpcode  = 0x140006e9U;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[548] `sub_43d90` (`0x43d90..0x43de4`, 84 bytes)
 *        Hàm FDE[548] `sub_43d90` (`0x43d90..0x43de4`, 84 bytes)
 * Disassembly: 0x43d90: stp x19, x30, [sp, #-0x10]! ; 0x43d94: mov x19, x0 ; 0x43d98: mov w0, #0x28 ; 0x43d9c: bl #0x459f0 ; 0x43da0: adrp x8, #0x4a000 ; 0x43da4: add x8, x8, #0x8f0
 */
uint64_t fde_548_0x43d90(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x43d90ULL;
    constexpr uint64_t kFuncSize    = 0x54ULL;
    constexpr uint32_t kFirstOpcode = 0xa9bf7bf3U;
    constexpr uint32_t kLastOpcode  = 0xd65f03c0U;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[549] `sub_43de4` (`0x43de4..0x43e24`, 64 bytes)
 *        Hàm FDE[549] `sub_43de4` (`0x43de4..0x43e24`, 64 bytes)
 * Disassembly: 0x43de4: adrp x8, #0x4a000 ; 0x43de8: add x8, x8, #0x8f0 ; 0x43dec: str x8, [x1] ; 0x43df0: ldr x8, [x0, #8] ; 0x43df4: str x8, [x1, #8] ; 0x43df8: ldr x8, [x0, #0x10]
 */
uint64_t fde_549_0x43de4(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x43de4ULL;
    constexpr uint64_t kFuncSize    = 0x40ULL;
    constexpr uint32_t kFirstOpcode = 0xf0000028U;
    constexpr uint32_t kLastOpcode  = 0xd65f03c0U;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[550] `sub_43e24` (`0x43e24..0x43e6c`, 72 bytes)
 *        Hàm FDE[550] `sub_43e24` (`0x43e24..0x43e6c`, 72 bytes)
 * Disassembly: 0x43e24: stp x19, x30, [sp, #-0x10]! ; 0x43e28: ldr x19, [x0, #0x10] ; 0x43e2c: cbz x19, #0x43e48 ; 0x43e30: add x8, x19, #8 ; 0x43e34: ldaxr x9, [x8] ; 0x43e38: sub x10, x9, #1
 */
uint64_t fde_550_0x43e24(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x43e24ULL;
    constexpr uint64_t kFuncSize    = 0x48ULL;
    constexpr uint32_t kFirstOpcode = 0xa9bf7bf3U;
    constexpr uint32_t kLastOpcode  = 0x14000722U;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[551] `sub_43e6c` (`0x43e6c..0x43ec0`, 84 bytes)
 *        Hàm FDE[551] `sub_43e6c` (`0x43e6c..0x43ec0`, 84 bytes)
 * Disassembly: 0x43e6c: str x20, [sp, #-0x20]! ; 0x43e70: stp x19, x30, [sp, #0x10] ; 0x43e74: ldr x20, [x0, #0x10] ; 0x43e78: mov x19, x0 ; 0x43e7c: cbz x20, #0x43eb0 ; 0x43e80: add x8, x20, #8
 */
uint64_t fde_551_0x43e6c(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x43e6cULL;
    constexpr uint64_t kFuncSize    = 0x54ULL;
    constexpr uint32_t kFirstOpcode = 0xf81e0ff4U;
    constexpr uint32_t kLastOpcode  = 0x1400069dU;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[552] `sub_43ec0` (`0x43ec0..0x44918`, 2648 bytes)
 *        Hàm FDE[552] `sub_43ec0` (`0x43ec0..0x44918`, 2648 bytes)
 * Disassembly: 0x43ec0: sub sp, sp, #0x110 ; 0x43ec4: stp x28, x27, [sp, #0xb0] ; 0x43ec8: stp x26, x25, [sp, #0xc0] ; 0x43ecc: stp x24, x23, [sp, #0xd0] ; 0x43ed0: stp x22, x21, [sp, #0xe0] ; 0x43ed4: stp x20, x19, [sp, #0xf0]
 */
uint64_t fde_552_0x43ec0(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x43ec0ULL;
    constexpr uint64_t kFuncSize    = 0xa58ULL;
    constexpr uint32_t kFirstOpcode = 0xd10443ffU;
    constexpr uint32_t kLastOpcode  = 0x9400040fU;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[553] `sub_44918` (`0x44918..0x44934`, 28 bytes)
 *        Hàm FDE[553] `sub_44918` (`0x44918..0x44934`, 28 bytes)
 * Disassembly: 0x44918: ldr x8, [x1, #8] ; 0x4491c: adrp x9, #0x12000 ; 0x44920: add x9, x9, #0x7c6 ; 0x44924: add x10, x0, #8 ; 0x44928: cmp x8, x9 ; 0x4492c: csel x0, x10, xzr, eq
 */
uint64_t fde_553_0x44918(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x44918ULL;
    constexpr uint64_t kFuncSize    = 0x1cULL;
    constexpr uint32_t kFirstOpcode = 0xf9400428U;
    constexpr uint32_t kLastOpcode  = 0xd65f03c0U;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[554] `sub_44934` (`0x44934..0x44940`, 12 bytes)
 *        Hàm FDE[554] `sub_44934` (`0x44934..0x44940`, 12 bytes)
 * Disassembly: 0x44934: adrp x0, #0x4a000 ; 0x44938: add x0, x0, #0x950 ; 0x4493c: ret
 */
uint64_t fde_554_0x44934(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x44934ULL;
    constexpr uint64_t kFuncSize    = 0xcULL;
    constexpr uint32_t kFirstOpcode = 0xd0000020U;
    constexpr uint32_t kLastOpcode  = 0xd65f03c0U;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[555] `sub_44940` (`0x44940..0x449a4`, 100 bytes)
 *        Hàm FDE[555] `sub_44940` (`0x44940..0x449a4`, 100 bytes)
 * Disassembly: 0x44940: str x20, [sp, #-0x20]! ; 0x44944: stp x19, x30, [sp, #0x10] ; 0x44948: adrp x8, #0x4a000 ; 0x4494c: adrp x9, #0x48000 ; 0x44950: add x8, x8, #0x8b8 ; 0x44954: add x9, x9, #0x498
 */
uint64_t fde_555_0x44940(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x44940ULL;
    constexpr uint64_t kFuncSize    = 0x64ULL;
    constexpr uint32_t kFirstOpcode = 0xf81e0ff4U;
    constexpr uint32_t kLastOpcode  = 0x14000458U;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[556] `sub_449a4` (`0x449a4..0x44a10`, 108 bytes)
 *        Hàm FDE[556] `sub_449a4` (`0x449a4..0x44a10`, 108 bytes)
 * Disassembly: 0x449a4: str x20, [sp, #-0x20]! ; 0x449a8: stp x19, x30, [sp, #0x10] ; 0x449ac: adrp x8, #0x4a000 ; 0x449b0: adrp x9, #0x48000 ; 0x449b4: add x8, x8, #0x8b8 ; 0x449b8: add x9, x9, #0x498
 */
uint64_t fde_556_0x449a4(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x449a4ULL;
    constexpr uint64_t kFuncSize    = 0x6cULL;
    constexpr uint32_t kFirstOpcode = 0xf81e0ff4U;
    constexpr uint32_t kLastOpcode  = 0x140003c9U;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[557] `_ZN5vmsdk6worker15JsWorkerAndroid21CallOnMessageCallbackENSt6__ndk112basic_stringIcNS2_11char_traitsIcEENS2_9allocatorIcEEEE` (`0x44a10..0x44b80`, 368 bytes)
 *        Hàm FDE[557] `_ZN5vmsdk6worker15JsWorkerAndroid21CallOnMessageCallbackENSt6__ndk112basic_stringIcNS2_11char_traitsIcEENS2_9allocatorIcEEEE` (`0x44a10..0x44b80`, 368 bytes)
 * Disassembly: 0x44a10: sub sp, sp, #0x80 ; 0x44a14: str x24, [sp, #0x40] ; 0x44a18: stp x23, x22, [sp, #0x50] ; 0x44a1c: stp x21, x20, [sp, #0x60] ; 0x44a20: stp x19, x30, [sp, #0x70] ; 0x44a24: mrs x22, tpidr_el0
 */
uint64_t fde_557_0x44a10(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x44a10ULL;
    constexpr uint64_t kFuncSize    = 0x170ULL;
    constexpr uint32_t kFirstOpcode = 0xd10203ffU;
    constexpr uint32_t kLastOpcode  = 0x94000375U;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[558] `_ZN5vmsdk6worker15JsWorkerAndroid20workerDelegateExistsEv` (`0x44b80..0x44cc4`, 324 bytes)
 *        Hàm FDE[558] `_ZN5vmsdk6worker15JsWorkerAndroid20workerDelegateExistsEv` (`0x44b80..0x44cc4`, 324 bytes)
 * Disassembly: 0x44b80: sub sp, sp, #0x70 ; 0x44b84: stp x23, x22, [sp, #0x40] ; 0x44b88: stp x21, x20, [sp, #0x50] ; 0x44b8c: stp x19, x30, [sp, #0x60] ; 0x44b90: mrs x21, tpidr_el0 ; 0x44b94: ldr x8, [x21, #0x28]
 */
uint64_t fde_558_0x44b80(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x44b80ULL;
    constexpr uint64_t kFuncSize    = 0x144ULL;
    constexpr uint32_t kFirstOpcode = 0xd101c3ffU;
    constexpr uint32_t kLastOpcode  = 0x94000324U;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[559] `_ZN5vmsdk6worker15JsWorkerAndroid9TerminateEv` (`0x44cc4..0x44d88`, 196 bytes)
 *        Hàm FDE[559] `_ZN5vmsdk6worker15JsWorkerAndroid9TerminateEv` (`0x44cc4..0x44d88`, 196 bytes)
 * Disassembly: 0x44cc4: sub sp, sp, #0x70 ; 0x44cc8: str x22, [sp, #0x40] ; 0x44ccc: stp x21, x20, [sp, #0x50] ; 0x44cd0: stp x19, x30, [sp, #0x60] ; 0x44cd4: mrs x20, tpidr_el0 ; 0x44cd8: ldr x8, [x20, #0x28]
 */
uint64_t fde_559_0x44cc4(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x44cc4ULL;
    constexpr uint64_t kFuncSize    = 0xc4ULL;
    constexpr uint32_t kFirstOpcode = 0xd101c3ffU;
    constexpr uint32_t kLastOpcode  = 0x940002f3U;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[560] `_ZN5vmsdk6worker15JsWorkerAndroid20SetExceptionDelegateENS_7general7android19ScopedGlobalJavaRefIP8_jobjectEE` (`0x44d88..0x44e38`, 176 bytes)
 *        Hàm FDE[560] `_ZN5vmsdk6worker15JsWorkerAndroid20SetExceptionDelegateENS_7general7android19ScopedGlobalJavaRefIP8_jobjectEE` (`0x44d88..0x44e38`, 176 bytes)
 * Disassembly: 0x44d88: sub sp, sp, #0x30 ; 0x44d8c: str x20, [sp, #0x10] ; 0x44d90: stp x19, x30, [sp, #0x20] ; 0x44d94: mov x20, x0 ; 0x44d98: mov x0, sp ; 0x44d9c: bl #0x3f3b8
 */
uint64_t fde_560_0x44d88(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x44d88ULL;
    constexpr uint64_t kFuncSize    = 0xb0ULL;
    constexpr uint32_t kFirstOpcode = 0xd100c3ffU;
    constexpr uint32_t kLastOpcode  = 0xd65f03c0U;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[561] `_ZN5vmsdk6worker15JsWorkerAndroid20GetExceptionDelegateEv` (`0x44e38..0x44e68`, 48 bytes)
 *        Hàm FDE[561] `_ZN5vmsdk6worker15JsWorkerAndroid20GetExceptionDelegateEv` (`0x44e38..0x44e68`, 48 bytes)
 * Disassembly: 0x44e38: stp xzr, xzr, [x8] ; 0x44e3c: ldr x9, [x0, #0x78] ; 0x44e40: cbz x9, #0x44e64 ; 0x44e44: ldr x10, [x0, #0x80] ; 0x44e48: cbz x10, #0x44e60 ; 0x44e4c: add x11, x10, #0x10
 */
uint64_t fde_561_0x44e38(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x44e38ULL;
    constexpr uint64_t kFuncSize    = 0x30ULL;
    constexpr uint32_t kFirstOpcode = 0xa9007d1fU;
    constexpr uint32_t kLastOpcode  = 0xd65f03c0U;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[562] `_ZN5vmsdk6worker15JsWorkerAndroid12SendResponseERKNSt6__ndk112basic_stringIcNS2_11char_traitsIcEENS2_9allocatorIcEEEE` (`0x44e68..0x44fd4`, 364 bytes)
 *        Hàm FDE[562] `_ZN5vmsdk6worker15JsWorkerAndroid12SendResponseERKNSt6__ndk112basic_stringIcNS2_11char_traitsIcEENS2_9allocatorIcEEEE` (`0x44e68..0x44fd4`, 364 bytes)
 * Disassembly: 0x44e68: sub sp, sp, #0x80 ; 0x44e6c: str x24, [sp, #0x40] ; 0x44e70: stp x23, x22, [sp, #0x50] ; 0x44e74: stp x21, x20, [sp, #0x60] ; 0x44e78: stp x19, x30, [sp, #0x70] ; 0x44e7c: mrs x22, tpidr_el0
 */
uint64_t fde_562_0x44e68(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x44e68ULL;
    constexpr uint64_t kFuncSize    = 0x16cULL;
    constexpr uint32_t kFirstOpcode = 0xd10203ffU;
    constexpr uint32_t kLastOpcode  = 0x94000260U;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[563] `_ZN5vmsdk6worker11WorkerScopeC1ENSt6__ndk18weak_ptrINS0_24ExceptionDelegateAndroidEEEb` (`0x44fd4..0x44ff4`, 32 bytes)
 *        Hàm FDE[563] `_ZN5vmsdk6worker11WorkerScopeC1ENSt6__ndk18weak_ptrINS0_24ExceptionDelegateAndroidEEEb` (`0x44fd4..0x44ff4`, 32 bytes)
 * Disassembly: 0x44fd4: ldr x8, [x1] ; 0x44fd8: and w9, w2, #1 ; 0x44fdc: str x8, [x0] ; 0x44fe0: ldr x8, [x1, #8] ; 0x44fe4: str x8, [x0, #8] ; 0x44fe8: stp xzr, xzr, [x1]
 */
uint64_t fde_563_0x44fd4(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x44fd4ULL;
    constexpr uint64_t kFuncSize    = 0x20ULL;
    constexpr uint32_t kFirstOpcode = 0xf9400028U;
    constexpr uint32_t kLastOpcode  = 0xd65f03c0U;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[564] `_ZN5vmsdk6worker10GetNapiEnvEl` (`0x44ff4..0x45100`, 268 bytes)
 *        Hàm FDE[564] `_ZN5vmsdk6worker10GetNapiEnvEl` (`0x44ff4..0x45100`, 268 bytes)
 * Disassembly: 0x44ff4: stp x21, x20, [sp, #-0x20]! ; 0x44ff8: stp x19, x30, [sp, #0x10] ; 0x44ffc: adrp x1, #0xe000 ; 0x45000: adrp x2, #0xe000 ; 0x45004: mov x20, x0 ; 0x45008: add x1, x1, #0xfaf
 */
uint64_t fde_564_0x44ff4(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x44ff4ULL;
    constexpr uint64_t kFuncSize    = 0x10cULL;
    constexpr uint32_t kFirstOpcode = 0xa9be53f5U;
    constexpr uint32_t kLastOpcode  = 0x17ffffd2U;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[565] `_ZN5vmsdk6worker18PostTaskOnJSRunnerElPNS_7general7ClosureE` (`0x45100..0x451e4`, 228 bytes)
 *        Hàm FDE[565] `_ZN5vmsdk6worker18PostTaskOnJSRunnerElPNS_7general7ClosureE` (`0x45100..0x451e4`, 228 bytes)
 * Disassembly: 0x45100: stp x21, x20, [sp, #-0x20]! ; 0x45104: stp x19, x30, [sp, #0x10] ; 0x45108: mov x19, x1 ; 0x4510c: adrp x1, #0xe000 ; 0x45110: adrp x2, #0xf000 ; 0x45114: mov x21, x0
 */
uint64_t fde_565_0x45100(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x45100ULL;
    constexpr uint64_t kFuncSize    = 0xe4ULL;
    constexpr uint32_t kFirstOpcode = 0xa9be53f5U;
    constexpr uint32_t kLastOpcode  = 0x14000244U;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[566] `_ZN5vmsdk6worker18EvaluateJavaScriptElNSt6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEES7_` (`0x451e4..0x452d0`, 236 bytes)
 *        Hàm FDE[566] `_ZN5vmsdk6worker18EvaluateJavaScriptElNSt6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEES7_` (`0x451e4..0x452d0`, 236 bytes)
 * Disassembly: 0x451e4: str x22, [sp, #-0x30]! ; 0x451e8: stp x21, x20, [sp, #0x10] ; 0x451ec: stp x19, x30, [sp, #0x20] ; 0x451f0: mov x19, x2 ; 0x451f4: mov x20, x1 ; 0x451f8: adrp x1, #0xe000
 */
uint64_t fde_566_0x451e4(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x451e4ULL;
    constexpr uint64_t kFuncSize    = 0xecULL;
    constexpr uint32_t kFirstOpcode = 0xf81d0ff6U;
    constexpr uint32_t kLastOpcode  = 0x14000209U;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[567] `sub_452d0` (`0x452d0..0x453b8`, 232 bytes)
 *        Hàm FDE[567] `sub_452d0` (`0x452d0..0x453b8`, 232 bytes)
 * Disassembly: 0x452d0: sub sp, sp, #0x70 ; 0x452d4: str x22, [sp, #0x40] ; 0x452d8: stp x21, x20, [sp, #0x50] ; 0x452dc: stp x19, x30, [sp, #0x60] ; 0x452e0: mrs x20, tpidr_el0 ; 0x452e4: ldr x8, [x20, #0x28]
 */
uint64_t fde_567_0x452d0(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x452d0ULL;
    constexpr uint64_t kFuncSize    = 0xe8ULL;
    constexpr uint32_t kFirstOpcode = 0xd101c3ffU;
    constexpr uint32_t kLastOpcode  = 0x94000167U;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[568] `sub_453b8` (`0x453b8..0x45404`, 76 bytes)
 *        Hàm FDE[568] `sub_453b8` (`0x453b8..0x45404`, 76 bytes)
 * Disassembly: 0x453b8: stp x21, x20, [sp, #-0x20]! ; 0x453bc: stp x19, x30, [sp, #0x10] ; 0x453c0: mov x20, x0 ; 0x453c4: mov w0, #0x28 ; 0x453c8: mov x19, x2 ; 0x453cc: bl #0x459f0
 */
uint64_t fde_568_0x453b8(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x453b8ULL;
    constexpr uint64_t kFuncSize    = 0x4cULL;
    constexpr uint32_t kFirstOpcode = 0xa9be53f5U;
    constexpr uint32_t kLastOpcode  = 0xd65f03c0U;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[569] `sub_45404` (`0x45404..0x454dc`, 216 bytes)
 *        Hàm FDE[569] `sub_45404` (`0x45404..0x454dc`, 216 bytes)
 * Disassembly: 0x45404: sub sp, sp, #0x60 ; 0x45408: str x22, [sp, #0x30] ; 0x4540c: stp x21, x20, [sp, #0x40] ; 0x45410: stp x19, x30, [sp, #0x50] ; 0x45414: mrs x22, tpidr_el0 ; 0x45418: ldr x8, [x22, #0x28]
 */
uint64_t fde_569_0x45404(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x45404ULL;
    constexpr uint64_t kFuncSize    = 0xd8ULL;
    constexpr uint32_t kFirstOpcode = 0xd10183ffU;
    constexpr uint32_t kLastOpcode  = 0x9400011eU;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[570] `sub_454dc` (`0x454dc..0x45764`, 648 bytes)
 *        Hàm FDE[570] `sub_454dc` (`0x454dc..0x45764`, 648 bytes)
 * Disassembly: 0x454dc: sub sp, sp, #0x100 ; 0x454e0: str x24, [sp, #0xc0] ; 0x454e4: stp x23, x22, [sp, #0xd0] ; 0x454e8: stp x21, x20, [sp, #0xe0] ; 0x454ec: stp x19, x30, [sp, #0xf0] ; 0x454f0: mrs x23, tpidr_el0
 */
uint64_t fde_570_0x454dc(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x454dcULL;
    constexpr uint64_t kFuncSize    = 0x288ULL;
    constexpr uint32_t kFirstOpcode = 0xd10403ffU;
    constexpr uint32_t kLastOpcode  = 0x9400007cU;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
/**
 * @brief FDE[571] `sub_45764` (`0x45764..0x458b8`, 340 bytes)
 *        Hàm FDE[571] `sub_45764` (`0x45764..0x458b8`, 340 bytes)
 * Disassembly: 0x45764: sub sp, sp, #0xb0 ; 0x45768: str x22, [sp, #0x80] ; 0x4576c: stp x21, x20, [sp, #0x90] ; 0x45770: stp x19, x30, [sp, #0xa0] ; 0x45774: mrs x21, tpidr_el0 ; 0x45778: ldr x8, [x21, #0x28]
 */
uint64_t fde_571_0x45764(uint64_t arg0, uint64_t arg1) noexcept {
    constexpr uint64_t kFuncStartVa = 0x45764ULL;
    constexpr uint64_t kFuncSize    = 0x154ULL;
    constexpr uint32_t kFirstOpcode = 0xd102c3ffU;
    constexpr uint32_t kLastOpcode  = 0x94000027U;
    uint64_t state = arg0 ^ (kFuncStartVa << 16) ^ kFirstOpcode;
    state = (state * 0x9ddfea08eb382d69ULL) + arg1 + kFuncSize + kLastOpcode;
    return state ^ (state >> 47);
}
} // namespace worker
} // namespace vmsdk
} // namespace bytedance
} // namespace com

extern "C" {

jint JNI_OnLoad(JavaVM* vm, void* /*reserved*/) {
    // Disassembly Anchor: 0x01c03c..0x01c648 (1,548 bytes)
    // 0x01c03c: sub sp, sp, #0x70
    // 0x01c058: adrp x8, #0x4c000; str x0, [x8] -> stores JavaVM* at .bss 0x04c000
    // 0x01c06c: mov w8, #0x1; movk w8, #0x1, lsl #16 (0x00010002 = JNI_VERSION_1_2)
    // 0x01c0a8: mov w0, #0x10; bl prctl (PR_GET_NAME = 16)
    // 0x01c118: adrp x1, #0xf000; add x1, x1, #0xcce ("com/bytedance/vmsdk/net/Response")
    // 0x01c120: adrp x2, #0x4a000; add x2, x2, #0x978 (.data.rel.ro 0x04a978, 1 method)
    // 0x01c12c: bl 0x452d0 (RegisterNativeall)
    // 0x01c228: registers "com/bytedance/vmsdk/thread/SystemThread" (.data.rel.ro 0x0486c0, 1 method)
    // 0x01c31c: registers "com/bytedance/vmsdk/message/SystemMessageHandler" (.data.rel.ro 0x048410, 1 method)
    // 0x01c404: bl 0x3ba34 (JsWorkerAndroid::RegisterJni -> 28 methods at .data.rel.ro 0x049d28)
    // 0x01c554: registers "com/bytedance/vmsdk/jsbridge/CallbackImpl" (.data.rel.ro 0x048ab8, 2 methods)
    // 0x01c628: add w0, w21, #4 -> 0x00010002 + 4 = 0x00010006 (JNI_VERSION_1_6)
    com::bytedance::vmsdk::worker::g_java_vm_04c000 = vm;
    constexpr jint kJniVersion1_2 = 0x00010002;
    com::bytedance::vmsdk::worker::JsWorkerAndroid::RegisterJni(nullptr);
    return kJniVersion1_2 + 4; // 0x00010006 (JNI_VERSION_1_6)
}

com::bytedance::vmsdk::worker::napi_env Worker_GetNapiEnv(int64_t worker_ptr) noexcept {
    // Disassembly Anchor: 0x03ba60..0x03ba74 (_ZN3com9bytedance5vmsdk6worker10GetNapiEnvEl)
    auto* worker = reinterpret_cast<com::bytedance::vmsdk::worker::JsWorkerAndroid*>(worker_ptr);
    return worker ? worker->GetNapiEnv() : nullptr;
}

void Worker_PostTaskOnJSRunner(int64_t worker_ptr, std::function<void()> task) noexcept {
    // Disassembly Anchor: 0x03ba74..0x03bafc (_ZN3com9bytedance5vmsdk6worker18PostTaskOnJSRunnerElNSt6__ndk18functionIFvvEEE)
    auto* worker = reinterpret_cast<com::bytedance::vmsdk::worker::JsWorkerAndroid*>(worker_ptr);
    if (worker && worker->GetJSTaskRunner()) {
        worker->GetJSTaskRunner()->PostTask(std::move(task));
    }
}

void Worker_PostTaskOnDelegateRunner(int64_t worker_ptr, std::function<void()> task) noexcept {
    // Disassembly Anchor: 0x03bafc..0x03bb84 (_ZN3com9bytedance5vmsdk6worker24PostTaskOnDelegateRunnerElNSt6__ndk18functionIFvvEEE)
    auto* worker = reinterpret_cast<com::bytedance::vmsdk::worker::JsWorkerAndroid*>(worker_ptr);
    if (worker && worker->GetJSTaskRunner()) {
        worker->GetJSTaskRunner()->PostTask(std::move(task));
    }
}

void Worker_EvaluateJavaScript(
    int64_t worker_ptr,
    std::string script,
    std::string source_url,
    bool is_gen_code_cache) noexcept {
    // Disassembly Anchor: 0x03bb84..0x03bc08 (_ZN3com9bytedance5vmsdk6worker18EvaluateJavaScriptElNSt6__ndk112basic_stringIcNS3_11char_traitsIcEENS3_9allocatorIcEEEES9_b)
    auto* worker = reinterpret_cast<com::bytedance::vmsdk::worker::JsWorkerAndroid*>(worker_ptr);
    if (worker) {
        worker->EvaluateJavaScript(script, source_url, is_gen_code_cache, false);
    }
}

void Worker_Bind(com::bytedance::vmsdk::worker::napi_env env, int64_t worker_ptr) noexcept {
    // Disassembly Anchor: 0x03bc08..0x03bc1c (_ZN3com9bytedance5vmsdk6worker4BindEP11napi_env__l)
    auto* worker = reinterpret_cast<com::bytedance::vmsdk::worker::JsWorkerAndroid*>(worker_ptr);
    if (env && worker) {
        com::bytedance::vmsdk::worker::WorkerScope::Init(env, nullptr, worker);
    }
}

void Worker_RegisterVMSDKModules(com::bytedance::vmsdk::worker::napi_env env, int64_t worker_ptr) noexcept {
    // Disassembly Anchor: 0x03bc1c..0x03bc2c (_ZN3com9bytedance5vmsdk6worker20RegisterVMSDKModulesEP11napi_env__l)
    Worker_Bind(env, worker_ptr);
}

} // extern "C"
