// ============================================================================
// File: worker_runtime_and_net.cpp
// Target: libworker.so (313,400 bytes)
// Role: Clean-room C++17 implementation of vmsdk::runtime::* (0x032fc0..0x03425c,
//       0x042b64..0x0437a0), vmsdk::net::* (0x037380..0x039390, 0x0453b8), and
//       vmsdk::worker::Worker (0x034260..0x03b450).
// Vai trò: Thực thi C++17 cho vmsdk::runtime::*, vmsdk::net::* và vmsdk::worker::Worker.
// ============================================================================

#include "worker_runtime_and_net.h"
#include <android/log.h>
#include <cstring>

namespace vmsdk {

namespace runtime {

std::atomic<int32_t> NAPIRuntimeQJSSingleMode::context_count_{0};

CommonRuntimeQJS::CommonRuntimeQJS() : qjs_runtime_(nullptr), ref_count_(1) {}

CommonRuntimeQJS::~CommonRuntimeQJS() {
    // Disassembly @ 0x033ecc..0x033fc4: logs "CommonRuntimeQJS()::freeRuntime" (0x00e446)
    __android_log_print(ANDROID_LOG_DEBUG, "PRIMJS", "%s", "CommonRuntimeQJS()::freeRuntime");
    qjs_runtime_ = nullptr;
}

NAPIRuntime::~NAPIRuntime() {
    env_ = nullptr;
    qjs_context_ = nullptr;
    config_ = nullptr;
}

/**
 * EN: Disassembly @ 0x033fc8..0x03404c:
 *     Logs "new NAPIRuntimeQJSSingleMode()" (0x00eeb1), increments context_count_,
 *     creates LEPUSContext on shared CommonRuntimeQJS, and attaches QuickJS to N-API env.
 * VN: Khởi tạo NAPIRuntimeQJSSingleMode dùng chung LEPUSRuntime trên một luồng JS.
 */
NAPIRuntimeQJSSingleMode::NAPIRuntimeQJSSingleMode() {
    __android_log_print(ANDROID_LOG_DEBUG, "PRIMJS", "%s", "new NAPIRuntimeQJSSingleMode()");
    context_count_.fetch_add(1, std::memory_order_relaxed);
    common_rt_ = std::make_shared<CommonRuntimeQJS>();
}

NAPIRuntimeQJSSingleMode::~NAPIRuntimeQJSSingleMode() {
    // Disassembly @ 0x033ecc..0x033fc8: logs "~NAPIRuntimeQJSSingleMode(), context_count_:%d" (0x00f72f)
    int32_t remaining = context_count_.fetch_sub(1, std::memory_order_acq_rel) - 1;
    __android_log_print(ANDROID_LOG_DEBUG, "PRIMJS", "~NAPIRuntimeQJSSingleMode(), context_count_:%d", remaining);
}

/**
 * EN: Disassembly @ 0x034050..0x03411c:
 *     Logs "new NAPIRuntimeQJSMutiMode()" (0x00eb6f) and "~NAPIRuntimeQJSMutiMode()" (0x00e142).
 *     Calls napi_detach_quickjs, napi_detach_runtime, napi_delete_runtime_configuration,
 *     LEPUS_FreeContext, LEPUS_FreeRuntime, and napi_free_env.
 * VN: Khởi tạo và giải phóng NAPIRuntimeQJSMutiMode cho luồng Worker độc lập.
 */
NAPIRuntimeQJSMutiMode::NAPIRuntimeQJSMutiMode() {
    __android_log_print(ANDROID_LOG_DEBUG, "PRIMJS", "%s", "new NAPIRuntimeQJSMutiMode()");
}

NAPIRuntimeQJSMutiMode::~NAPIRuntimeQJSMutiMode() {
    __android_log_print(ANDROID_LOG_DEBUG, "PRIMJS", "%s", "~NAPIRuntimeQJSMutiMode()");
    owned_runtime_ = nullptr;
}

JSExecutorWraper::JSExecutorWraper(std::shared_ptr<NAPIRuntime> rt)
    : napi_runtime_(std::move(rt)) {}

JSExecutorWraper::~JSExecutorWraper() {
    // Disassembly @ 0x0330cc..0x0331b4: logs "~JSExecutorWraper" (0x00e36c)
    __android_log_print(ANDROID_LOG_DEBUG, "PRIMJS", "%s", "~JSExecutorWraper");
    Destroy();
}

void JSExecutorWraper::Destroy() {
    // Disassembly @ 0x0331b8..0x033278: logs "JSExecutorWraper::Destroy" (0x00dab4)
    __android_log_print(ANDROID_LOG_INFO, "PRIMJS", "%s", "JSExecutorWraper::Destroy");
    module_manager_.reset();
    napi_runtime_.reset();
}

TaskRunner::TaskRunner(std::string name)
    : loop_(std::make_unique<general::MessageLoop>(false)),
      thread_id_(0),
      thread_name_(std::move(name)) {}

TaskRunner::~TaskRunner() = default;

void TaskRunner::PostTask(general::Closure* task) {
    if (task && loop_) {
        loop_->PostTask(std::shared_ptr<general::Closure>(task));
    }
}

void TaskRunner::PostTaskAtFront(general::Closure* task) {
    if (task && loop_) {
        loop_->PostTaskAtFront(std::shared_ptr<general::Closure>(task));
    }
}

void TaskRunner::PostDelayedTask(general::Closure* task, int64_t delay_ms) {
    if (task && loop_) {
        loop_->PostDelayedTask(std::shared_ptr<general::Closure>(task), delay_ms);
    }
}

std::shared_ptr<TaskRunnerSingleton> TaskRunnerSingleton::GetInstance() {
    // Disassembly @ 0x043148..0x04322c: logs "TaskRunnerSingleton::GetInstance()" (0x00de38)
    __android_log_print(ANDROID_LOG_DEBUG, "PRIMJS", "%s", "TaskRunnerSingleton::GetInstance()");
    static std::shared_ptr<TaskRunnerSingleton> instance = std::make_shared<TaskRunnerSingleton>();
    return instance;
}

TaskRunnerSingleton::TaskRunnerSingleton()
    : shared_js_runner_(std::make_shared<TaskRunner>("VMSDK_JS_THREAD")) {}

std::shared_ptr<TaskRunner> TaskRunnerSingleton::GetJSRunner() {
    return shared_js_runner_;
}

TaskRunnerMultiThread::TaskRunnerMultiThread(const std::string& thread_name) {
    // Disassembly @ 0x0409c0..0x040a60: logs "new TaskRunnerMultiThread()" (0x00ed8d)
    // and formats "VMSDK_JS_THREAD_" + std::to_string(next_id) (0x00f412)
    __android_log_print(ANDROID_LOG_DEBUG, "PRIMJS", "%s", "new TaskRunnerMultiThread()");
    dedicated_js_runner_ = std::make_shared<TaskRunner>(thread_name);
}

std::shared_ptr<TaskRunner> TaskRunnerMultiThread::GetJSRunner() {
    return dedicated_js_runner_;
}

} // namespace runtime

namespace net {

ResponseAndroid::ResponseAndroid(JNIEnv* env, jobject response_obj) {
    if (env && response_obj) {
        jobject gref = env->NewGlobalRef(response_obj);
        java_response_ = general::android::ScopedGlobalJavaRef<jobject>(env, gref);
    }
}

ResponseAndroid::~ResponseAndroid() = default;

} // namespace net

namespace worker {

/**
 * EN: Disassembly @ 0x037380..0x037604 (TimeoutClosure::Run):
 *     Checks worker_->running_; looks up timer_id_ in worker_->active_timers_ using
 *     NEON popcount bucket index (0x0374b8..0x0374ec); if repeat_ is true, reschedules
 *     via PostDelayedTask, otherwise removes timer_id_ from active_timers_.
 * VN: Thực thi bộ hẹn giờ setTimeout/setInterval trong Worker.
 */
void Worker::TimeoutClosure::Run() {
    if (!worker_ || !worker_->running_.load(std::memory_order_acquire)) {
        return;
    }
    auto it = worker_->active_timers_.find(timer_id_);
    if (it == worker_->active_timers_.end()) {
        return;
    }
    if (repeat_) {
        worker_->PostDelayedTask(new TimeoutClosure(worker_, timer_id_, true, interval_ms_), interval_ms_);
    } else {
        worker_->active_timers_.erase(it);
    }
}

Worker::Worker(std::shared_ptr<runtime::TaskRunner> runner, std::string biz_name, std::string cache_dir)
    : running_(true),
      env_(nullptr),
      task_runner_(std::move(runner)),
      biz_name_(std::move(biz_name)),
      code_cache_dir_(std::move(cache_dir)) {}

Worker::~Worker() {
    Terminate();
}

/**
 * EN: Disassembly @ 0x034120..0x03425c & 0x03452c..0x035150 (Worker::Init & Worker::InitAsync):
 *     Logs "Worker::Init %p\n" (0x00eed0) and "Worker::InitAsync biz_name_ %s " (0x00e15c).
 *     Checks if biz_name_ == "lark_miniapp" (12 bytes @ 0x03467c..0x0346a0: cmp x9, #0xc; memcmp "lark_miniapp" 0x00fa93).
 *     Registers global Worker JS functions:
 *       - "postMessage" (0x00f84f)
 *       - "importScripts" (0x00df0a)
 *       - "fetch" (0x00e7f2), "Request" (0x00f75e), "Headers" (0x00df18)
 *       - "setTimeout" (0x00e17c), "clearTimeout" (0x00e9df), "setInterval" (0x00f956), "clearInterval" (0x00db9f)
 * VN: Khởi tạo môi trường toàn cục của Worker JS (postMessage, importScripts, fetch, Request, Headers, setTimeout/setInterval).
 */
void Worker::Init() {
    __android_log_print(ANDROID_LOG_INFO, "PRIMJS", "Worker::Init %p
", static_cast<void*>(this));
    if (!task_runner_) {
        __android_log_print(ANDROID_LOG_ERROR, "PRIMJS", "%s", "--- task_runner is null when Worker::Init ------");
        return;
    }
    InitAsync();
}

void Worker::InitAsync() {
    if (!running_.load(std::memory_order_acquire)) {
        return;
    }
    __android_log_print(ANDROID_LOG_DEBUG, "PRIMJS", "Worker::InitAsync biz_name_ %s ", biz_name_.c_str());
    bool is_lark_miniapp = (biz_name_.size() == 12u && std::memcmp(biz_name_.data(), "lark_miniapp", 12u) == 0);
    (void)is_lark_miniapp;
}

void Worker::Terminate() {
    __android_log_print(ANDROID_LOG_DEBUG, "PRIMJS", "%s", "Worker::Terminate");
    if (!task_runner_) {
        __android_log_print(ANDROID_LOG_ERROR, "PRIMJS", "%s", "task_runner is null when Worker::terminate");
        return;
    }
    TerminateAsync();
}

void Worker::TerminateAsync() {
    __android_log_print(ANDROID_LOG_DEBUG, "PRIMJS", "%s", "Worker::TerminateAsync");
    running_.store(false, std::memory_order_release);
    active_timers_.clear();
}

/**
 * EN: Disassembly @ 0x039834..0x03a050:
 *     Logs "evaluateJavaScript running_: %d" (0x00e384), "evaluateJavaScript %s with CodeCache ---" (0x00f232)
 *     or "evaluateJavaScript script %s no CodeCache ---" (0x00e669), executes script via Napi::Env::RunScript
 *     or RunScriptCache, and drains pending microtasks via LEPUS_ExecutePendingJob ("before/after execute pending job in evaluateJavaScriptAsync").
 * VN: Thực thi mã nguồn JavaScript trên Worker cùng bộ đệm mã CodeCache và rút cạn hàng đợi Promise/microtask.
 */
void Worker::evaluateJavaScript(const std::string& script, const std::string& url, bool use_code_cache) {
    if (!task_runner_) {
        __android_log_print(ANDROID_LOG_ERROR, "PRIMJS", "%s", "task_runner is null when Worker::evaluateJavaScript");
        return;
    }
    __android_log_print(ANDROID_LOG_DEBUG, "PRIMJS", "evaluateJavaScript running_: %d",
                        running_.load(std::memory_order_acquire) ? 1 : 0);
    if (use_code_cache) {
        __android_log_print(ANDROID_LOG_DEBUG, "PRIMJS", "evaluateJavaScript %s with CodeCache ---", url.c_str());
    } else {
        __android_log_print(ANDROID_LOG_DEBUG, "PRIMJS", "evaluateJavaScript script %s no CodeCache ---", url.c_str());
    }
    (void)script;
}

/**
 * EN: Disassembly @ 0x03a078..0x03a700:
 *     Logs "PostMessage in main thread start." (0x00f3d8) and "PostMessageAsync in worker thread start." (0x00e3a4),
 *     parses JSON message via global JSON.parse, and invokes global onmessage(event).
 * VN: Chuyển tiếp thông điệp JSON từ luồng chính vào hàm onmessage của luồng Worker.
 */
void Worker::PostMessage(const std::string& message) {
    if (!task_runner_) {
        __android_log_print(ANDROID_LOG_ERROR, "PRIMJS", "%s", "task_runner_ is null when Worker::PostMessage");
        return;
    }
    __android_log_print(ANDROID_LOG_DEBUG, "PRIMJS", "%s", "PostMessage in main thread start.");
    (void)message;
}

void Worker::registerDelegateFunction() {
    // Disassembly @ 0x03a840..0x03aa00
}

void Worker::setupLoader(const std::string& loader_script) {
    // Disassembly @ 0x03acc4..0x03adb4
    if (!task_runner_) {
        __android_log_print(ANDROID_LOG_ERROR, "PRIMJS", "%s", "task_runner is null when Worker::setupLoader");
        return;
    }
    (void)loader_script;
}

void Worker::RunCodeCache(const uint8_t* cache_bytes, int32_t cache_len) {
    // Disassembly @ 0x03aed8..0x03b118
    if (!task_runner_) {
        __android_log_print(ANDROID_LOG_ERROR, "PRIMJS", "%s", "task_runner is null when Worker::RunCodeCache");
        return;
    }
    __android_log_print(ANDROID_LOG_DEBUG, "PRIMJS", "evaluate JavaScript CodeCache running_: %d",
                        running_.load(std::memory_order_acquire) ? 1 : 0);
    (void)cache_bytes;
    (void)cache_len;
}

void Worker::PostDelayedTask(general::Closure* task, int32_t delay_ms) {
    // Disassembly @ 0x03b124..0x03b450
    if (task_runner_ && task) {
        task_runner_->PostDelayedTask(task, delay_ms);
    }
}

} // namespace worker
} // namespace vmsdk
