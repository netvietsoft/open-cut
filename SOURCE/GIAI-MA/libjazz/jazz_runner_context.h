// ============================================================================
// File: jazz_runner_context.h
// Target: libjazz.so (231,840 bytes, SHA-256: f11496ae99e17699d6f2a2df40043c3014bc8391aab0d6422acc2a63590183e4)
// Task ID: TASK-122-RECONSTRUCTION-LIBJAZZ (Legacy: TASK_SO_122_libjazz)
// Classification: CORE_07_SCRIPTING_VM (ByteDance AmazingEngine Jazz JS Runtime & NAPI Modules)
//
// Description (EN):
// Clean-room C++17 header for AmazingEngine task runners, JS execution context,
// and context executor reconstructed from libjazz.so:
//   - BEFTask (0x00cdac..0x00e948): task closure with cancellation flag at +0x4C
//   - BEFBaseRunner (0x00caf4..0x00d3d8): immediate + delayed priority queues,
//     _PumpLoop (0x00cb34), GetNext (0x00cbc4), PostTask (0x00cde0),
//     PostDelayedTask (0x00ce74), CancelTask (0x00cf98), _Terminate (0x00d200),
//     PauseThreadForInspector (0x00d31c), ResumeThreadForInspector (0x00d360)
//   - Context (0x01047c..0x010e7c): AnalyzeErrorMessage (0x01047c),
//     init (0x010688), deinit (0x01069c), getContextHash (0x0106a4),
//     isValid (0x010750), RunScript (0x010764..0x010a54), GenScriptCodeCache,
//     EvaluateCodeCache, CallFunction (0x010b30..0x010bac), SendEvent (0x010c30),
//     CallFrameworkFunc (0x010d48)
//   - ContextExecutor (0x01109c..0x012690): getKey (0x01109c), init (0x0116a8),
//     deinit (0x0111d4), GetJSRunner (0x01163c), _SetupRunner (0x0118e8),
//     PostScript (0x011b00), _ExecuteBlock (0x011bf4), RunScript (0x011eec),
//     PostBlock (0x011f9c), RunBlock (0x011fe0), RequestGarbageCollect (0x012024),
//     PumpLoop (0x012388), GetContext (0x01263c), GetWorker (0x012668)
//
// Mô tả (VI):
// Header C++17 tái tạo sạch bộ chạy tác vụ (BEFTask, BEFBaseRunner), ngữ cảnh
// thực thi JS (Context) và bộ điều phối ngữ cảnh (ContextExecutor) từ libjazz.so.
// ============================================================================

#pragma once

#include "jazz_types.h"
#include <condition_variable>
#include <deque>
#include <thread>

namespace AmazingEngine {

class Engine;

// ============================================================================
// 1. BEFTask — Cancellable Task Closure (0x00cdac..0x00e948)
// Verified layout:
//   +0x00: vtable* (vtable at .data.rel.ro 0x3a300)
//   +0x10: std::function<void()> m_callback
//   +0x40: double m_targetTimeMs
//   +0x4C: bool m_cancelled (checked at 0x00cb78: ldrb w22, [x19, #0x4c])
// Lớp tác vụ có thể hủy BEFTask (0x00cdac..0x00e948).
// ============================================================================
class BEFTask {
public:
    BEFTask() noexcept;                                    // 0x00e8e4
    explicit BEFTask(std::function<void()> fn);            // 0x00e7a4
    virtual ~BEFTask() noexcept;                           // 0x00e8ac / 0x00e924

    virtual void Run();                                    // 0x00cdac
    void Cancel() noexcept { m_cancelled.store(true, std::memory_order_release); }
    bool IsCancelled() const noexcept { return m_cancelled.load(std::memory_order_acquire); }

    void SetTargetTimeMs(double t) noexcept { m_target_time_ms = t; }
    double GetTargetTimeMs() const noexcept { return m_target_time_ms; }

private:
    std::function<void()> m_fn;
    double m_target_time_ms{0.0};
    std::atomic<bool> m_cancelled{false}; // +0x4C in binary ABI
};

// ============================================================================
// 2. BEFBaseRunner — Immediate & Delayed Task Runner (0x00caf4..0x00d3d8)
// Verified layout from _PumpLoop (0x00cb34), GetNext (0x00cbc4), PostDelayedTask (0x00ce74):
//   +0x00: vtable* (.data.rel.ro 0x3a280)
//   +0x08: bool m_terminated
//   +0x09: std::atomic<bool> m_pausedForInspector
//   +0x10: std::deque<std::shared_ptr<BEFTask>> m_taskQueue
//   +0x40: std::vector<DelayedEntry> m_delayedQueue
//   +0x60: std::mutex m_mutex
//   +0x88: std::condition_variable m_cond
// Bộ chạy tác vụ cơ sở hỗ trợ hàng đợi tức thời và trễ (BEFBaseRunner).
// ============================================================================
class BEFBaseRunner {
public:
    struct DelayedEntry {
        double target_time_ms = 0.0;
        std::shared_ptr<BEFTask> task;
    };

    BEFBaseRunner();                                                          // 0x00caf4
    virtual ~BEFBaseRunner() noexcept;                                        // 0x00d368 / 0x00d3b4

    virtual void StartRunner();                                               // 0x00d308
    virtual void Terminate();                                                 // 0x00d308
    virtual bool IsJsThread();                                                // 0x00d30c
    virtual bool IsCurrentThread();                                           // 0x00d314
    virtual void PauseThreadForInspector();                                   // 0x00d31c
    virtual void ResumeThreadForInspector();                                  // 0x00d360

    bool _PumpLoop(bool wait_for_next);                                       // 0x00cb34
    std::shared_ptr<BEFTask> GetNext(bool wait_for_next);                     // 0x00cbc4
    bool PostTask(std::shared_ptr<BEFTask> task, bool high_priority = false); // 0x00cde0
    bool PostDelayedTask(std::shared_ptr<BEFTask> task, double delay_ms);     // 0x00ce74
    void CancelTask(std::shared_ptr<BEFTask> task);                           // 0x00cf98
    void popTaskFromDelayedQueueNoLock(double now_ms);                        // 0x00d00c
    void _Terminate();                                                        // 0x00d200

    static double currentSteadyTimeMs() noexcept;                             // 0x00cf44

protected:
    bool m_terminated{false};                         // +0x08
    std::atomic<bool> m_paused_for_inspector{false};  // +0x09
    std::deque<std::shared_ptr<BEFTask>> m_task_queue;// +0x10
    std::vector<DelayedEntry> m_delayed_queue;        // +0x40
    mutable std::mutex m_mutex;                       // +0x60
    std::condition_variable m_cond;                   // +0x88
    std::thread::id m_owner_thread_id;
};

// ============================================================================
// 3. Context — JavaScript Execution Context Wrapper (0x01047c..0x010e7c)
// Verified from disassembly:
//   - Vtable at .data.rel.ro 0x3a520
//   - Wraps scripts in CommonJS/Require closure at 0x010820..0x010860:
//     "(function(require){const __filename='" + path +
//     "';const __dirname=__filename.slice(0, __filename.lastIndexOf('/') + 1);" +
//     code + "\n})"
//   - AnalyzeErrorMessage (0x01047c): extracts "message" (.rodata 0x25f21) and
//     "stack" (.rodata 0x25f87) and logs "MESSAGE: %s" / "STACK: %s"
//   - SendEvent (0x010c30): invokes "dispatchEvent" (.rodata 0x260a6)
//   - CallFrameworkFunc (0x010d48): invokes "nativeCall" (.rodata 0x260b4) on
//     "FrameworkModule" (.rodata 0x26e2f)
// Ngữ cảnh thực thi JavaScript của AmazingEngine (Context).
// ============================================================================
class Context {
public:
    Context();                                                                  // 0x010624
    virtual ~Context() noexcept;                                                // 0x0106f0 / 0x00eccc

    virtual void Enter();                                                       // 0x00d308
    virtual void Exit();                                                        // 0x00d308
    virtual bool GenScriptCodeCache(Napi::Env env,
                                    const std::string& script,
                                    std::string& out_cache);                    // 0x010ae0
    virtual bool GenScriptCodeCache(Napi::Env env,
                                    const char* script,
                                    const uint8_t** out_buf,
                                    int* out_len);                              // 0x010ae0
    virtual bool EvaluateCodeCache(Napi::Env env,
                                   const uint8_t* cache_buf,
                                   int cache_len,
                                   napi_value__** out_val);                     // 0x010ae0
    virtual Napi::Value EvaluateCodeCache(Napi::Env env,
                                          const std::string& script,
                                          const std::string& cache);            // 0x010ae4

    void init(CtxHandler handler);                                              // 0x010688
    void deinit();                                                              // 0x01069c
    uint64_t getContextHash();                                                  // 0x0106a4
    bool isValid();                                                             // 0x010750

    Napi::Value RunScript(const char* script, const char* filename);            // 0x010764
    Napi::Value RunScript(const char* script, size_t len, const char* filename);// 0x0107a8
    Napi::Value RunScript(const std::string& script, const char* filename);     // 0x010a54

    Napi::Value CallFunction(const Napi::Function& func,
                             const std::initializer_list<napi_value__*>& args); // 0x010b30
    Napi::Value CallFunction(const Napi::Function& func,
                             const std::vector<napi_value__*>& args);           // 0x010bac
    Napi::Value SendEvent(const Napi::Object& event_obj);                       // 0x010c30
    Napi::Value CallFrameworkFunc(const std::string& func_name,
                                  const Napi::Array& args);                     // 0x010d48

    static void AnalyzeErrorMessage(const Napi::Error& err);                    // 0x01047c
    Napi::Env GetEnv() const noexcept { return Napi::Env(m_handler.env); }
    const std::string& LastWrappedScript() const noexcept { return m_last_wrapped_script; }

private:
    CtxHandler m_handler{};
    bool m_initialized{false};
    std::string m_last_wrapped_script;
};

// ============================================================================
// 4. ContextExecutor — Asynchronous / Synchronous JS Context Dispatcher
//    (0x01109c..0x012690)
// Bộ điều phối thực thi kịch bản bất đồng bộ/đồng bộ trên Context (ContextExecutor).
// ============================================================================
class ContextExecutor {
public:
    struct ExecuteBundle {
        std::string script;
        std::string filename;
        std::function<void(Napi::Env, Napi::Value)> callback;
        std::function<void(Context*)> block;

        ExecuteBundle() = default;
        ExecuteBundle(const ExecuteBundle& other); // 0x013b04
        ~ExecuteBundle() noexcept;                 // 0x011eb4
    };

    static uint64_t getKey();                      // 0x01109c

    ContextExecutor();                             // 0x011164
    virtual ~ContextExecutor() noexcept;           // 0x01118c / 0x011518

    void init(Engine* engine);                     // 0x0116a8
    void deinit();                                 // 0x0111d4

    std::shared_ptr<BEFBaseRunner> GetJSRunner();  // 0x01163c
    void _SetupRunner();                           // 0x0118e8
    void _TerminateRunner();                       // 0x0114bc

    bool IsGlobal();                               // 0x0118e0
    void SetGlobal(bool is_global);                // 0x0119a4

    void PostScript(const std::string& script,
                    const std::string& filename,
                    const std::function<void(Napi::Env, Napi::Value)>& cb); // 0x011b00
    void RunScript(const std::string& script,
                   const std::string& filename,
                   const std::function<void(Napi::Env, Napi::Value)>& cb);  // 0x011eec
    void PostBlock(const std::function<void(Context*)>& block);             // 0x011f9c
    void RunBlock(const std::function<void(Context*)>& block);              // 0x011fe0
    void _ExecuteBlock(ExecuteBundle& bundle, bool sync_wait);              // 0x011bf4

    void RequestGarbageCollect();                  // 0x012024
    void PumpLoop();                               // 0x012388
    std::shared_ptr<Context> GetContext();         // 0x01263c
    std::shared_ptr<BEFBaseRunner> GetWorker();    // 0x012668

    uint32_t GetId() const noexcept { return m_executor_id; }
    void SetId(uint32_t id) noexcept { m_executor_id = id; }

private:
    uint32_t m_executor_id{0};
    Engine* m_engine{nullptr};                     // +0x18
    std::shared_ptr<Context> m_context;            // +0x20
    std::shared_ptr<BEFBaseRunner> m_js_runner;
    std::shared_ptr<BEFBaseRunner> m_worker_runner;
    bool m_inited{false};                          // +0x30
    bool m_is_global{false};
};

} // namespace AmazingEngine
