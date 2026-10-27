// ============================================================================
// File: worker_types.h
// Target: libworker.so (313,400 bytes, SHA-256: 35c47b55e99c2789000c60cb0fa814c27df1187aee0974a34651b4aee69c2aa6)
// Role: Clean-room C++17 ABI Type & Structure Definitions for ByteDance VMSDK
//       WebWorker / ServiceWorker JS Runtime & Piper JSB Engine.
// Vai trò: Định nghĩa kiểu dữ liệu & bố cục Struct ABI C++17 chuẩn xác cho
//          Động cơ WebWorker / ServiceWorker & Cầu nối Piper JSB của VMSDK.
// ============================================================================

#pragma once

#include <jni.h>
#include <cstdint>
#include <cstddef>
#include <atomic>
#include <string>
#include <vector>
#include <memory>
#include <functional>
#include <mutex>
#include <condition_variable>
#include <unordered_map>

// Forward declarations for N-API & QuickJS / LepusNG types imported from libnapi.so & libquick.so
// Khai báo chuyển tiếp cho các kiểu N-API & QuickJS / LepusNG nhập khẩu từ libnapi.so & libquick.so
struct napi_env__;
typedef napi_env__* napi_env;
struct napi_value__;
typedef napi_value__* napi_value;
struct napi_callback_info__;
typedef napi_callback_info__* napi_callback_info;
struct napi_ref__;
typedef napi_ref__* napi_ref;
struct napi_class__;
typedef napi_class__* napi_class;
struct napi_runtime_configuration__;
typedef napi_runtime_configuration__* napi_runtime_configuration;

struct LEPUSRuntime;
struct LEPUSContext;

namespace vmsdk {

namespace general {

namespace android {

/**
 * EN: Method lookup category used by vmsdk::general::android::GetMethod (0x01c7f4 & 0x01c82c).
 *     type == 0 -> JNIEnv::GetStaticMethodID (+0x388)
 *     type == 1 -> JNIEnv::GetMethodID (+0x108)
 * VN: Phân loại phương thức dùng bởi vmsdk::general::android::GetMethod (0x01c7f4 & 0x01c82c).
 *     type == 0 -> JNIEnv::GetStaticMethodID (+0x388)
 *     type == 1 -> JNIEnv::GetMethodID (+0x108)
 */
enum MethodType : int32_t {
    STATIC_METHOD = 0,
    INSTANCE_METHOD = 1,
};

/**
 * EN: Base polymorphic JNI reference wrapper (vtable @ 0x048070..0x0482c0, size = 16 bytes).
 *     Offset +0x00: vptr
 *     Offset +0x08: jobject obj_ (ldr x0, [x0, #8] @ 0x01c778)
 * VN: Lớp cơ sở bao bọc tham chiếu JNI đa hình (vtable @ 0x048070..0x0482c0, kích thước = 16 byte).
 *     Offset +0x00: con trỏ bảng ảo vptr
 *     Offset +0x08: jobject obj_ (ldr x0, [x0, #8] @ 0x01c778)
 */
template <typename T>
class JavaRef {
public:
    void* vptr_;
    T obj_;

    JavaRef() noexcept : vptr_(nullptr), obj_(nullptr) {}
    JavaRef(JNIEnv* /*env*/, T obj) noexcept : vptr_(nullptr), obj_(obj) {}
    virtual ~JavaRef() = default;

    T obj() const noexcept { return obj_; }
    bool IsNull() const noexcept { return obj_ == nullptr; }
    T Release() noexcept {
        T tmp = obj_;
        obj_ = nullptr;
        return tmp;
    }
};

template <typename T>
class ScopedLocalJavaRef : public JavaRef<T> {
public:
    JNIEnv* env_;
    ScopedLocalJavaRef() noexcept : JavaRef<T>(), env_(nullptr) {}
    ScopedLocalJavaRef(JNIEnv* env, T obj) noexcept : JavaRef<T>(env, obj), env_(env) {}
};

template <typename T>
class ScopedGlobalJavaRef : public JavaRef<T> {
public:
    ScopedGlobalJavaRef() noexcept : JavaRef<T>() {}
    ScopedGlobalJavaRef(JNIEnv* env, T obj) noexcept : JavaRef<T>(env, obj) {}
};

template <typename T>
class ScopedWeakGlobalJavaRef : public JavaRef<T> {
public:
    ScopedWeakGlobalJavaRef() noexcept : JavaRef<T>() {}
    ScopedWeakGlobalJavaRef(JNIEnv* env, T obj) noexcept : JavaRef<T>(env, obj) {}
};

/**
 * EN: JavaVmSdkException static bridge (0x01d46c..0x01d6fc).
 *     Caches GlobalRef to "com/bytedance/vmsdk/worker/VmSdkException" at .bss 0x04c0a8
 *     and static method ID "throwVmSdkException" "(ILjava/lang/String;)V" at .bss 0x04c0b0.
 * VN: Cầu nối ngoại lệ JavaVmSdkException (0x01d46c..0x01d6fc).
 *     Lưu GlobalRef của lớp "com/bytedance/vmsdk/worker/VmSdkException" tại .bss 0x04c0a8
 *     và ID phương thức tĩnh "throwVmSdkException" "(ILjava/lang/String;)V" tại .bss 0x04c0b0.
 */
class JavaVmSdkException {
public:
    static bool RegisterJni(JNIEnv* env);
    static void ThrowException(int32_t code, std::string message);
};

} // namespace android

/**
 * EN: Base task closure interface (vtable @ 0x048668, _ZTSN5vmsdk7general7ClosureE @ 0x01026b).
 * VN: Giao diện bao đóng tác vụ cơ sở (vtable @ 0x048668, _ZTSN5vmsdk7general7ClosureE @ 0x01026b).
 */
class Closure {
public:
    virtual ~Closure() = default;
    virtual void Run() = 0;
};

/**
 * EN: Std::function-backed Closure (vtable @ 0x048630, _ZTSN5vmsdk7general16FunctionCallbackE @ 0x010248).
 * VN: Bao đóng Closure dùng std::function (vtable @ 0x048630).
 */
class FunctionCallback : public Closure {
public:
    std::function<void()> callback_;
    explicit FunctionCallback(std::function<void()> cb) : callback_(std::move(cb)) {}
    ~FunctionCallback() override = default;
    void Run() override {
        if (callback_) {
            callback_();
        }
    }
};

/**
 * EN: TimerNode scheduled in MessagePumpPosix min-heap (vtable @ 0x048340, _ZTS...TimerNode @ 0x010107).
 *     Offset +0x00: Closure* task_
 *     Offset +0x20: int64_t expire_time_ms_ (ldr x23, [x8, #0x20] @ 0x01fbe0)
 * VN: Nút hẹn giờ TimerNode trong hàng đợi ưu tiên MessagePumpPosix (vtable @ 0x048340).
 */
struct TimerNode {
    std::shared_ptr<Closure> closure;
    int64_t interval_ms{0};
    int64_t expire_time_ms{0}; // +0x20
    bool repeat{false};
};

class MessagePump {
public:
    class Delegate {
    public:
        virtual ~Delegate() = default;
        virtual bool DoWork() = 0;
        virtual bool DoIdleWork() = 0;
    };

    virtual ~MessagePump() = default;
    virtual void Run(Delegate* delegate) = 0;
    virtual void Quit() = 0;
    virtual void ScheduleWork() = 0;
    virtual void ScheduleWorkAtFront() = 0;
    virtual void ScheduleDelayedWork(std::shared_ptr<Closure> closure, int64_t delay_ms) = 0;
};

/**
 * EN: Posix condition-variable message pump (vtable @ 0x0483a0, size = 0xD0 = 208 bytes).
 *     Offset +0x08: std::mutex mutex_ (48B)
 *     Offset +0x38: std::condition_variable cv_ (48B)
 *     Offset +0x68: std::vector<std::shared_ptr<TimerNode>> timer_heap_ (24B)
 *     Offset +0x88: std::mutex timer_mutex_ (40B)
 *     Offset +0xB0: std::vector<std::shared_ptr<Closure>> work_queue_ (24B)
 *     Offset +0xC8: bool keep_running_ (ldrb w8, [x0, #0xc8] @ 0x01fb74)
 *     Constant kNsPerMs = 0x000F4240 = 1,000,000 ns/ms (0x01fb7c..0x01fb84).
 * VN: Bộ bơm thông điệp Posix dùng biến điều kiện (vtable @ 0x0483a0, kích thước = 0xD0 = 208 byte).
 */
class MessagePumpPosix : public MessagePump {
public:
    static constexpr int64_t kNsPerMs = 0x000F4240; // 1,000,000
    std::mutex mutex_;
    std::condition_variable cv_;
    std::vector<std::shared_ptr<TimerNode>> timer_heap_;
    std::mutex timer_mutex_;
    std::vector<std::shared_ptr<Closure>> work_queue_;
    bool keep_running_{true};

    MessagePumpPosix();
    ~MessagePumpPosix() override;
    void Run(Delegate* delegate) override;
    void Quit() override;
    void ScheduleWork() override;
    void ScheduleWorkAtFront() override;
    void ScheduleDelayedWork(std::shared_ptr<Closure> closure, int64_t delay_ms) override;
};

/**
 * EN: Android SystemMessageHandler-backed message pump (vtable @ 0x048430, 0x020a70..0x020e38).
 *     Wraps com/bytedance/vmsdk/jsbridge/utils/SystemMessageHandler.create(long) and scheduleWork().
 * VN: Bộ bơm thông điệp gắn với Android SystemMessageHandler (vtable @ 0x048430).
 */
class MessagePumpAndroid : public MessagePump {
public:
    android::ScopedGlobalJavaRef<jobject> system_message_handler_ref_;
    Delegate* delegate_{nullptr};

    MessagePumpAndroid();
    ~MessagePumpAndroid() override;
    void Run(Delegate* delegate) override;
    void Quit() override;
    void ScheduleWork() override;
    void ScheduleWorkAtFront() override;
    void ScheduleDelayedWork(std::shared_ptr<Closure> closure, int64_t delay_ms) override;
};

/**
 * EN: MessageLoop implementing MessagePump::Delegate (vtable @ 0x0482e0, 0x01df98..0x01e500).
 *     Uses 16-byte SIMD vector {1ULL, -1ULL} from .rodata 0x00d860 at 0x01e0f0 & 0x01e444
 *     to update task counters and compact queue when front_index >= 0x400 (1024) at 0x01e450.
 * VN: Vòng lặp thông điệp thực thi MessagePump::Delegate (vtable @ 0x0482e0).
 */
class MessageLoop : public MessagePump::Delegate {
public:
    std::unique_ptr<MessagePump> pump_;
    std::vector<std::shared_ptr<Closure>> incoming_queue_;
    uint64_t front_index_{0};
    int64_t pending_count_{0};
    std::mutex queue_mutex_;
    bool running_{false};

    explicit MessageLoop(bool is_android_pump = false);
    ~MessageLoop() override;
    bool DoWork() override;
    bool DoIdleWork() override;
    void PostTask(std::shared_ptr<Closure> task);
    void PostTaskAtFront(std::shared_ptr<Closure> task);
    void PostDelayedTask(std::shared_ptr<Closure> task, int64_t delay_ms);
};

} // namespace general

namespace runtime {

enum class JS_ENGINE_TYPE : int32_t {
    QUICKJS = 0,
    V8 = 1,
    JSC = 2,
};

/**
 * EN: N-API Runtime base & QuickJS single-mode / multi-mode implementations
 *     (vtables @ 0x049580, 0x0495b0, 0x0495f0, 0x049630; 0x033ecc..0x03425c).
 * VN: Lớp cơ sở N-API Runtime và các bản thực thi QuickJS đơn chế độ / đa chế độ.
 */
class CommonRuntimeQJS {
public:
    LEPUSRuntime* qjs_runtime_{nullptr};
    std::atomic<int32_t> ref_count_{0};
    CommonRuntimeQJS();
    virtual ~CommonRuntimeQJS();
};

class NAPIRuntime {
public:
    napi_env env_{nullptr};
    LEPUSContext* qjs_context_{nullptr};
    napi_runtime_configuration config_{nullptr};
    virtual ~NAPIRuntime();
    virtual napi_env GetEnv() const { return env_; }
};

class NAPIRuntimeQJSSingleMode : public NAPIRuntime {
public:
    static std::atomic<int32_t> context_count_;
    std::shared_ptr<CommonRuntimeQJS> common_rt_;
    NAPIRuntimeQJSSingleMode();
    ~NAPIRuntimeQJSSingleMode() override;
};

class NAPIRuntimeQJSMutiMode : public NAPIRuntime {
public:
    LEPUSRuntime* owned_runtime_{nullptr};
    NAPIRuntimeQJSMutiMode();
    ~NAPIRuntimeQJSMutiMode() override;
};

class JSRuntimeDelegate {
public:
    virtual ~JSRuntimeDelegate() = default;
    virtual void OnErrorOccurred(const std::string& error_msg) = 0;
};

} // namespace runtime

namespace net {

struct HttpRequestData {
    std::string url{"about:blank"};
    std::string method{"GET"};
    std::string mode{"cors"};
    std::unordered_map<std::string, std::string> headers;
    std::vector<uint8_t> body;
};

class ResponseDelegate {
public:
    virtual ~ResponseDelegate() = default;
    virtual void OnResponse(jobject response_obj) = 0;
    virtual void OnError(const std::string& error_msg) = 0;
};

class ResponseAndroid {
public:
    general::android::ScopedGlobalJavaRef<jobject> java_response_;
    int32_t status_code_{200};
    std::string url_;
    std::vector<uint8_t> body_bytes_;
    explicit ResponseAndroid(JNIEnv* env, jobject response_obj);
    ~ResponseAndroid();
};

} // namespace net

namespace worker {

class ExceptionDelegateAndroid {
public:
    general::android::ScopedGlobalJavaRef<jobject> delegate_ref_;
    explicit ExceptionDelegateAndroid(general::android::ScopedGlobalJavaRef<jobject> ref)
        : delegate_ref_(std::move(ref)) {}
    void OnError(const std::string& msg);
};

/**
 * EN: RAII Exception & Pending-Job Scope for Worker JS evaluation (0x044fd4 & 0x03f050, size = 24 bytes).
 *     Offset +0x00: std::weak_ptr<ExceptionDelegateAndroid> delegate_ (16 bytes)
 *     Offset +0x10: bool is_critical_ (1 byte, strb w9, [x0, #0x10] @ 0x044fec)
 * VN: Phạm vi RAII bắt ngoại lệ & chạy công việc đang chờ cho Worker JS (0x044fd4 & 0x03f050, 24 byte).
 */
class WorkerScope {
public:
    std::weak_ptr<ExceptionDelegateAndroid> exception_delegate_;
    bool is_critical_{false};

    WorkerScope(std::weak_ptr<ExceptionDelegateAndroid> delegate, bool is_critical) noexcept;
    ~WorkerScope() noexcept;
};

class Worker;
class WorkerDelegateAndroid;

/**
 * EN: JsWorkerAndroid ABI Structure (allocated 0xA8 = 168 bytes via operator new(0xa8) @ 0x040708).
 *     Offset +0x00: std::shared_ptr<Worker> worker_ (16 bytes)
 *     Offset +0x10: std::shared_ptr<runtime::JSRuntime> js_runtime_ (16 bytes)
 *     Offset +0x20: std::shared_ptr<void> task_runner_holder_ (16 bytes)
 *     Offset +0x30: std::shared_ptr<void> module_manager_ (16 bytes)
 *     Offset +0x40: std::shared_ptr<void> module_delegate_ (16 bytes)
 *     Offset +0x50: general::android::ScopedGlobalJavaRef<jobject> java_worker_ref_ (16 bytes)
 *     Offset +0x60: std::shared_ptr<WorkerDelegateAndroid> worker_delegate_ (16 bytes)
 *     Offset +0x70: std::shared_ptr<ExceptionDelegateAndroid> exception_delegate_ (16 bytes)
 *     Offset +0x80: void* inspector_session_ (8 bytes)
 *     Offset +0x88: std::atomic<bool> is_running_ (1 byte, strb w8, [x22, #0x88] @ 0x04095c)
 *     Offset +0x90: std::string biz_name_ (24 bytes, add x0, x22, #0x90 @ 0x040950)
 * VN: Cấu trúc ABI của JsWorkerAndroid (cấp phát 0xA8 = 168 byte qua operator new(0xa8) @ 0x040708).
 */
class JsWorkerAndroid {
public:
    std::shared_ptr<Worker> worker_;                                     // +0x00..+0x0F
    std::shared_ptr<void> js_runtime_;                                   // +0x10..+0x1F
    std::shared_ptr<void> task_runner_holder_;                           // +0x20..+0x2F
    std::shared_ptr<void> module_manager_;                               // +0x30..+0x3F
    std::shared_ptr<void> module_delegate_;                              // +0x40..+0x4F
    general::android::ScopedGlobalJavaRef<jobject> java_worker_ref_;     // +0x50..+0x5F
    std::shared_ptr<WorkerDelegateAndroid> worker_delegate_;             // +0x60..+0x6F
    std::shared_ptr<ExceptionDelegateAndroid> exception_delegate_;       // +0x70..+0x7F
    void* inspector_session_{nullptr};                                   // +0x80..+0x87
    std::atomic<bool> is_running_{true};                                 // +0x88
    uint8_t padding_89_[7]{0};                                           // +0x89..+0x8F
    std::string biz_name_;                                               // +0x90..+0xA7

    static void RegisterJni(JNIEnv* env);
    static jlong Create(JNIEnv* env, jobject jcaller, jlong engine_type_or_ptr,
                        jobject module_manager, std::string biz_name,
                        uint8_t use_single_thread, std::string code_cache_dir,
                        uint8_t enable_inspector);

    JsWorkerAndroid(JNIEnv* env, runtime::JS_ENGINE_TYPE engine_type,
                    jobject jcaller, jobject module_manager,
                    std::string code_cache_dir, uint8_t use_single_thread,
                    std::string biz_name, uint8_t enable_inspector);
    ~JsWorkerAndroid();

    void Init(runtime::JS_ENGINE_TYPE engine_type, const std::string& code_cache_dir, bool enable_inspector);
    void Fetch(const std::string& url, const std::string& method_and_headers,
               const void* body_data, int32_t body_len, net::ResponseDelegate* delegate);
    std::string FetchJsWithUrlSync(std::string url);
    void CallOnErrorCallback(std::string error_msg);
    void CallOnMessageCallback(std::string message);
    bool workerDelegateExists();
    void Terminate();
    void SetExceptionDelegate(general::android::ScopedGlobalJavaRef<jobject> delegate);
    std::weak_ptr<ExceptionDelegateAndroid> GetExceptionDelegate();
    void SendResponse(const std::string& inspector_response);
};

napi_env GetNapiEnv(jlong worker_ptr);
void PostTaskOnJSRunner(jlong worker_ptr, general::Closure* task);
void EvaluateJavaScript(jlong worker_ptr, std::string script, std::string url);

} // namespace worker
} // namespace vmsdk
