/**
 * @file worker_interface.h
 * @brief Clean-Room C++17 Public ABI & Exported Symbol Interface for libworker.so
 *        Giao diện ABI công khai & Ký hiệu xuất khẩu C++17 Clean-Room cho libworker.so
 *
 * Binary SHA-256: 35c47b55e99c2789000c60cb0fa814c27df1187aee0974a34651b4aee69c2aa6
 * Binary Size:    313,400 bytes
 * Exported .dynsym Symbols: 54 (including JNI_OnLoad, GetNapiEnv, PostTaskOnJSRunner,
 *                           EvaluateJavaScript, GeneralGlobalRef, VMSDKPipe, WorkerScope)
 */

#pragma once

#include "worker_types.h"
#include "worker_rodata_tables.h"
#include "worker_general_and_piper.h"
#include "worker_runtime_and_net.h"

namespace com {
namespace bytedance {
namespace vmsdk {
namespace worker {

/**
 * @brief WorkerScope — C++ backing object for WorkerGlobalScope (`postMessage`, `onerror`, `onmessage`)
 *        Đối tượng C++ nền cho WorkerGlobalScope (`postMessage`, `onerror`, `onmessage`)
 *
 * Disassembly Anchor / Điểm neo mã máy:
 * - `.data.rel.ro 0x049ff0..0x04a060`: N-API property descriptors (`onerror`, `onmessage`, `postMessage`, `postMessageAsync`)
 * - `0x040730..0x040814`: `WorkerScope::Init`
 * - `0x04261c..0x0427f8`: `WorkerScope::GetInstanceData` / `SetInstanceData` (instance data key `0x00000378 = 888`)
 * - `0x042c70..0x042ea8`: `WorkerScope::PostMessage` / `PostMessageAsync` / `GetOnMessage` / `SetOnMessage` / `GetOnError` / `SetOnError`
 */
class WorkerScope {
public:
    static constexpr uint64_t kNapiInstanceDataKey = 0x00000378ULL; // 888 (@ 0x04262c, 0x0427b8)

    explicit WorkerScope(JsWorkerAndroid* owner_worker) noexcept;
    ~WorkerScope() noexcept;

    static void Init(napi_env env, napi_value global_obj, JsWorkerAndroid* worker) noexcept;
    static WorkerScope* GetInstanceData(napi_env env) noexcept;
    static void SetInstanceData(napi_env env, WorkerScope* scope) noexcept;

    void PostMessage(const std::string& message_payload, bool is_async) noexcept;
    void OnMessageReceived(const std::string& message_payload) noexcept;
    void OnErrorReceived(const std::string& error_payload) noexcept;

    JsWorkerAndroid* owner() const noexcept { return owner_worker_; }

private:
    JsWorkerAndroid* owner_worker_;
    uint64_t on_message_ref_;
    uint64_t on_error_ref_;
};

/**
 * @brief JsWorkerAndroid — Core VMSDK Android WebWorker & Piper JSB Orchestrator (`sizeof = 0xA8 = 168 bytes`)
 *        Bộ điều phối WebWorker Android & cầu nối Piper JSB cốt lõi của VMSDK (`sizeof = 0xA8 = 168 bytes`)
 *
 * Disassembly Anchor / Điểm neo mã máy:
 * - `0x03ba34..0x03ba60`: `JsWorkerAndroid::RegisterJni(JNIEnv*)` registering 28 JNI callbacks at `.data.rel.ro 0x049d28`
 * - `0x0406d8..0x040a4c`: `JsWorkerAndroid::Create` allocating `0xA8 = 168 bytes` (`mov w0, #0xa8; bl operator new`)
 * - `0x03bc2c..0x03d718`: 28 `JNI_*` native methods for `com/bytedance/vmsdk/worker/JsWorker`
 */
class JsWorkerAndroid {
public:
    static bool RegisterJni(JNIEnv* env) noexcept;

    static int64_t Create(
        JNIEnv* env,
        jobject java_worker,
        int32_t engine_type,
        int64_t inspector_client_ptr,
        const std::string& cache_path,
        bool enable_inspector,
        bool is_multi_thread,
        const std::string& biz_name,
        bool enable_memory_pressure) noexcept;

    JsWorkerAndroid(
        JNIEnv* env,
        jobject java_worker,
        int32_t engine_type,
        int64_t inspector_client_ptr,
        const std::string& cache_path,
        bool enable_inspector,
        bool is_multi_thread,
        const std::string& biz_name,
        bool enable_memory_pressure) noexcept;

    ~JsWorkerAndroid() noexcept;

    void EvaluateJavaScript(
        const std::string& script,
        const std::string& source_url,
        bool is_gen_code_cache,
        bool is_ preload) noexcept;

    void EvaluateJavaScriptWithCodeCache(
        const uint8_t* code_cache,
        size_t cache_len,
        const std::string& source_url) noexcept;

    void PostMessage(const std::string& message) noexcept;
    void OnMessage(const std::string& message) noexcept;
    void OnError(const std::string& error) noexcept;
    std::string FetchSync(const std::string& url, const std::string& options_json) noexcept;
    void Terminate() noexcept;

    napi_env GetNapiEnv() const noexcept { return napi_env_; }
    fml::TaskRunner* GetJSTaskRunner() const noexcept { return js_task_runner_; }
    bool IsRunning() const noexcept { return is_running_ != 0; }
    const std::string& BizName() const noexcept { return biz_name_; }

private:
    JsWorkerAndroidABI abi_layout_;
    napi_env napi_env_;
    fml::TaskRunner* js_task_runner_;
    fml::TaskRunner* delegate_task_runner_;
    WorkerScope* worker_scope_;
    uint8_t is_running_;
    std::string biz_name_;
    std::string cache_path_;
};

} // namespace worker
} // namespace vmsdk
} // namespace bytedance
} // namespace com

extern "C" {

/**
 * @brief JNI_OnLoad (`0x01c03c..0x01c648`, 1,548 bytes)
 *        Điểm nhập khởi tạo JNI của libworker.so (`0x01c03c..0x01c648`, 1.548 bytes)
 */
jint JNI_OnLoad(JavaVM* vm, void* reserved);

/**
 * @brief Exported VMSDK Native Worker C++ APIs (`0x03ba60..0x03bc2c`)
 *        Các API C++ xuất khẩu của VMSDK Native Worker (`0x03ba60..0x03bc2c`)
 */
com::bytedance::vmsdk::worker::napi_env Worker_GetNapiEnv(int64_t worker_ptr) noexcept;
void Worker_PostTaskOnJSRunner(int64_t worker_ptr, std::function<void()> task) noexcept;
void Worker_PostTaskOnDelegateRunner(int64_t worker_ptr, std::function<void()> task) noexcept;
void Worker_EvaluateJavaScript(
    int64_t worker_ptr,
    std::string script,
    std::string source_url,
    bool is_gen_code_cache) noexcept;
void Worker_Bind(com::bytedance::vmsdk::worker::napi_env env, int64_t worker_ptr) noexcept;
void Worker_RegisterVMSDKModules(com::bytedance::vmsdk::worker::napi_env env, int64_t worker_ptr) noexcept;

} // extern "C"
