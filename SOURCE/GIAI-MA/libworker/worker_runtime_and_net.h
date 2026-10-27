// ============================================================================
// File: worker_runtime_and_net.h
// Target: libworker.so (313,400 bytes)
// Role: Clean-room C++17 declarations for vmsdk::runtime::* (TaskRunner,
//       TaskRunnerSingleton, TaskRunnerMultiThread, JSExecutorWraper,
//       NAPIRuntimeQJSSingleMode/MutiMode), vmsdk::net::* (RequestWrap,
//       HeadersWrap, ResponseAndroid), and vmsdk::worker::Worker.
// Vai trò: Khai báo C++17 cho vmsdk::runtime::*, vmsdk::net::* và vmsdk::worker::Worker.
// ============================================================================

#pragma once

#include "worker_types.h"
#include "worker_rodata_tables.h"
#include "worker_general_and_piper.h"

namespace vmsdk {

namespace runtime {

class TaskRunner {
public:
    std::unique_ptr<general::MessageLoop> loop_;
    int32_t thread_id_{0};
    std::string thread_name_;

    explicit TaskRunner(std::string name = "VMSDK_JS_THREAD");
    virtual ~TaskRunner();
    void PostTask(general::Closure* task);
    void PostTaskAtFront(general::Closure* task);
    void PostDelayedTask(general::Closure* task, int64_t delay_ms);
};

class TaskRunnerManufacture {
public:
    virtual ~TaskRunnerManufacture() = default;
    virtual std::shared_ptr<TaskRunner> GetJSRunner() = 0;
};

class TaskRunnerSingleton : public TaskRunnerManufacture {
public:
    std::shared_ptr<TaskRunner> shared_js_runner_;
    static std::shared_ptr<TaskRunnerSingleton> GetInstance();
    TaskRunnerSingleton();
    ~TaskRunnerSingleton() override = default;
    std::shared_ptr<TaskRunner> GetJSRunner() override;
};

class TaskRunnerMultiThread : public TaskRunnerManufacture {
public:
    std::shared_ptr<TaskRunner> dedicated_js_runner_;
    explicit TaskRunnerMultiThread(const std::string& thread_name);
    ~TaskRunnerMultiThread() override = default;
    std::shared_ptr<TaskRunner> GetJSRunner() override;
};

class JSExecutor : public std::enable_shared_from_this<JSExecutor> {
public:
    virtual ~JSExecutor() = default;
    virtual void Destroy() = 0;
};

class JSExecutorWraper : public JSExecutor {
public:
    std::shared_ptr<NAPIRuntime> napi_runtime_;
    std::shared_ptr<piper::ModuleManagerAndroid> module_manager_;
    explicit JSExecutorWraper(std::shared_ptr<NAPIRuntime> rt);
    ~JSExecutorWraper() override;
    void Destroy() override;
};

} // namespace runtime

namespace worker {

/**
 * EN: Core cross-platform Worker engine (0x034260..0x03b450).
 *     Manages N-API environment, QuickJS code cache, setTimeout/setInterval/clearTimeout/clearInterval,
 *     importScripts, fetch(Request/Headers), postMessage, and onmessage dispatch.
 * VN: Động cơ Worker cốt lõi (0x034260..0x03b450) quản lý môi trường N-API, bộ đệm mã QuickJS,
 *     bộ định thời setTimeout/setInterval, importScripts, fetch và truyền thông điệp postMessage.
 */
class Worker {
public:
    class WorkerClosure : public general::Closure {
    public:
        Worker* worker_{nullptr};
        std::string arg1_;
        std::string arg2_;
        std::function<void(Worker*, std::string, std::string)> fn_;
        WorkerClosure(Worker* w, std::string a1, std::string a2,
                      std::function<void(Worker*, std::string, std::string)> fn)
            : worker_(w), arg1_(std::move(a1)), arg2_(std::move(a2)), fn_(std::move(fn)) {}
        ~WorkerClosure() override = default;
        void Run() override {
            if (fn_) {
                fn_(worker_, arg1_, arg2_);
            }
        }
    };

    class TimeoutClosure : public general::Closure {
    public:
        Worker* worker_{nullptr};
        uint32_t timer_id_{0};
        bool repeat_{false};
        int32_t interval_ms_{0};
        TimeoutClosure(Worker* w, uint32_t id, bool rep, int32_t ms)
            : worker_(w), timer_id_(id), repeat_(rep), interval_ms_(ms) {}
        ~TimeoutClosure() override = default;
        void Run() override;
    };

    std::atomic<bool> running_{false};
    napi_env env_{nullptr};
    std::shared_ptr<runtime::TaskRunner> task_runner_;
    std::shared_ptr<runtime::JSExecutorWraper> js_executor_;
    std::string biz_name_;
    std::string code_cache_dir_;
    std::unordered_map<uint32_t, bool> active_timers_;
    uint32_t next_timer_id_{1};

    Worker(std::shared_ptr<runtime::TaskRunner> runner, std::string biz_name, std::string cache_dir);
    ~Worker();

    void Init();
    void InitAsync();
    void Terminate();
    void TerminateAsync();
    void evaluateJavaScript(const std::string& script, const std::string& url, bool use_code_cache);
    void PostMessage(const std::string& message);
    void registerDelegateFunction();
    void setupLoader(const std::string& loader_script);
    void RunCodeCache(const uint8_t* cache_bytes, int32_t cache_len);
    void PostDelayedTask(general::Closure* task, int32_t delay_ms);
};

} // namespace worker
} // namespace vmsdk
