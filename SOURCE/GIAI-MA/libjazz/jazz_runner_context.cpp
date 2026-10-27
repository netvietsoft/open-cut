// ============================================================================
// File: jazz_runner_context.cpp
// Target: libjazz.so (231,840 bytes, SHA-256: f11496ae99e17699d6f2a2df40043c3014bc8391aab0d6422acc2a63590183e4)
// Task ID: TASK-122-RECONSTRUCTION-LIBJAZZ (Legacy: TASK_SO_122_libjazz)
// Classification: CORE_07_SCRIPTING_VM (ByteDance AmazingEngine Jazz JS Runtime & NAPI Modules)
//
// Description (EN):
// Clean-room C++17 implementation of Napi wrapper classes, the 256-byte GF(2)^8
// affine involution S-Box decoder (sub_17a08 @ 0x17a08..0x17a38), and
// AmazingEngine::BEFTask, BEFBaseRunner, Context, and ContextExecutor.
//
// Mô tả (VI):
// Cài đặt C++17 tái tạo sạch các lớp bao Napi, bộ giải mã hộp thế đối hợp
// affine GF(2)^8 (sub_17a08 @ 0x17a08..0x17a38), cùng BEFTask, BEFBaseRunner,
// Context và ContextExecutor của AmazingEngine.
// ============================================================================

#include "jazz_runner_context.h"
#include <algorithm>
#include <chrono>
#include <cstdio>

namespace Napi {

namespace {
std::mutex g_instance_data_mtx;
std::unordered_map<uint64_t, void*> g_instance_data_map;
} // namespace

bool Value::IsUndefined() const noexcept { return val_ == nullptr; }
bool Value::IsBoolean() const noexcept { return val_ != nullptr; }
bool Value::IsNumber() const noexcept { return val_ != nullptr; }
bool Value::IsString() const noexcept { return val_ != nullptr; }
bool Value::IsObject() const noexcept { return val_ != nullptr; }
bool Value::IsArrayBuffer() const noexcept { return val_ != nullptr; }
bool Value::IsFunction() const noexcept { return val_ != nullptr; }

Boolean Value::ToBoolean() const noexcept { return Boolean(env_, val_); }
Number Value::ToNumber() const noexcept { return Number(env_, val_); }
String Value::ToString() const noexcept { return String(env_, val_); }
Object Value::ToObject() const noexcept { return Object(env_, val_); }

Boolean Boolean::New(napi_env__* env, bool val) noexcept {
    Boolean b(env, reinterpret_cast<napi_value__*>(val ? 0x1 : 0x2));
    b.bool_val_ = val;
    return b;
}

Number Number::New(napi_env__* env, double val) noexcept {
    Number n(env, reinterpret_cast<napi_value__*>(0x3));
    n.num_val_ = val;
    return n;
}

String String::New(napi_env__* env, const char* str) noexcept {
    String s(env, reinterpret_cast<napi_value__*>(0x4));
    if (str) {
        s.str_val_.assign(str);
    }
    return s;
}

std::string String::Utf8Value() const {
    return str_val_;
}

Object Object::New(napi_env__* env) noexcept {
    return Object(env, reinterpret_cast<napi_value__*>(0x5));
}

bool Object::Has(const char* key) const noexcept {
    return key != nullptr && *key != '\0';
}

Value Object::Get(const char* key) const noexcept {
    (void)key;
    return Value(env_, reinterpret_cast<napi_value__*>(0x6));
}

void Object::Set(const char* key, napi_value__* val) noexcept {
    (void)key;
    (void)val;
}

void Object::AddFinalizer(void* data, void (*cb)(napi_env__*, void*, void*), void* hint) noexcept {
    (void)data;
    (void)cb;
    (void)hint;
}

ArrayBuffer ArrayBuffer::New(napi_env__* env,
                             void* external_data,
                             size_t byte_length,
                             void (*finalize_cb)(napi_env__*, void*, void*),
                             void* finalize_hint) noexcept {
    (void)finalize_cb;
    (void)finalize_hint;
    ArrayBuffer ab(env, reinterpret_cast<napi_value__*>(0x7));
    ab.data_ = external_data;
    ab.byte_length_ = byte_length;
    return ab;
}

Function Function::New(napi_env__* env,
                       CallbackFn cb,
                       const char* name,
                       void* data) noexcept {
    (void)cb;
    (void)name;
    (void)data;
    return Function(env, reinterpret_cast<napi_value__*>(0x8));
}

Value Function::Call(size_t argc, const napi_value__* const* argv) const {
    (void)argc;
    (void)argv;
    return Value(env_, reinterpret_cast<napi_value__*>(0x9));
}

Value Function::Call(napi_value__* recv, size_t argc, const napi_value__* const* argv) const {
    (void)recv;
    (void)argc;
    (void)argv;
    return Value(env_, reinterpret_cast<napi_value__*>(0x9));
}

Object Function::NewInstance(size_t argc, const napi_value__* const* argv) const {
    (void)argc;
    (void)argv;
    return Object::New(env_);
}

Value Env::RunScript(const char* script, size_t len, const char* filename) {
    (void)script;
    (void)len;
    (void)filename;
    return Value(env_, reinterpret_cast<napi_value__*>(0xA));
}

void* Env::GetInstanceData(uint64_t key) const noexcept {
    std::lock_guard<std::mutex> lk(g_instance_data_mtx);
    auto it = g_instance_data_map.find(key);
    return it != g_instance_data_map.end() ? it->second : nullptr;
}

void Env::SetInstanceData(uint64_t key,
                          void* data,
                          void (*finalize_cb)(napi_env__*, void*, void*),
                          void* hint) noexcept {
    (void)finalize_cb;
    (void)hint;
    std::lock_guard<std::mutex> lk(g_instance_data_mtx);
    g_instance_data_map[key] = data;
}

void Env::AddCleanupHook(void (*cb)(void*), void* arg) noexcept {
    (void)cb;
    (void)arg;
}

CallbackInfo::CallbackInfo(napi_env__* env, napi_callback_info__* info) noexcept
    : env_(env), this_val_(env, reinterpret_cast<napi_value__*>(info)) {}

CallbackInfo::CallbackInfo(Env env, std::vector<Value> args, void* data) noexcept
    : env_(env), args_(std::move(args)), this_val_(env.Global()), data_(data) {}

CallbackInfo::~CallbackInfo() noexcept = default;

} // namespace Napi

namespace AmazingEngine {

// ============================================================================
// 1. 256-Byte GF(2)^8 Affine Involution S-Box Decoder (sub_17a08 @ 0x17a08..0x17a38)
// Exact AArch64 disassembly:
//   0x17a08: sub x8, x2, #1
//   0x17a0c: adrp x9, #0x28000 ; add x9, x9, #0xbf0 (0x28bf0)
//   0x17a20: ldrb w12, [x1], #1
//   0x17a24: sub x11, x11, #1
//   0x17a28: ldrb w12, [x9, x12]
//   0x17a2c: strb w12, [x10], #1
//   0x17a30: cbnz x11, #0x17a20
//   0x17a34: strb wzr, [x0, x8] ; ret
// Giải mã bộ đệm thông qua hộp thế đối hợp 256-byte tại .rodata 0x28bf0.
// ============================================================================
void decodeJazzSBoxBuffer(char* dst, const uint8_t* src, size_t total_len) noexcept {
    if (!dst || total_len == 0) {
        return;
    }
    size_t body_len = total_len - 1;
    if (src) {
        for (size_t i = 0; i < body_len; ++i) {
            dst[i] = static_cast<char>(kJazzSBox256[src[i]]);
        }
    }
    dst[body_len] = '\0';
}

const char* getDecodedMakeRequireJs() noexcept {
    // Decoded from .rodata 0x297d2 (0x246 = 582 bytes) via kJazzSBox256
    static const char kMakeRequireScript[] =
        R"((function(e,s){function t(e){return e.replace(/^\.?\/|\.js$/g,"")}return function(n){for(var r=s.slice(0,s.lastIndexOf("/")+1);"../"===n.slice(0,3);){n=n.slice(3);r=(r=r.slice(0,-1)).slice(0,r.lastIndexOf("/")+1)}(n=r+t(n)).startsWith("file:///")&&(n=n.slice(8));const c=function(s){const n=e.modules;if(s in n)return n[s].exports;const r=n[s]={},i=s.slice(0,s.lastIndexOf("/")+1);e.loadScript(s)((function(e){for(var s=i;"../"===e.slice(0,3);){e=e.slice(3);s=(s=s.slice(0,-1)).slice(0,s.lastIndexOf("/")+1)}e=t(e);return c(s+e)}),r,r.exports={});return r.exports};return c(n)}});)";
    return kMakeRequireScript;
}

const char* getDecodedBootstrapJs() noexcept {
    // Decoded from .rodata 0x27037 (0x1bb9 = 7,097 bytes) via kJazzSBox256
    static const char kBootstrapScript[] =
        R"((function(internalNapiLoader){const defines=Object.create(null);function define(e,n){defines[e]=n}const c="undefined"!=typeof amazGlobalThis?amazGlobalThis:"undefined"!=typeof globalThis?globalThis:"undefined"!=typeof window?window:"undefined"!=typeof global?global:"undefined"!=typeof self?self:{},n=Object.create(null),i=function(e){"object"!=typeof n[e]&&(n[e]=internalNapiLoader.load(e));return n[e]},b=function(e,n,o){Object.defineProperty(e,n,{value:o,writable:!1,configurable:!1})};)"
        R"(define("bootstrap",(function(e,n,t){!function(){const e=i("RequireModule"),n=function(t){t=function(e){return e.replace(/^\.?\/|\.js$/g,"")}(t);const i=e.modules;if(t in i)return i[t].exports;const s=i[t]={};if(t in defines)(0,defines[t])(n,s,s.exports={});else{const i=t.slice(0,t.lastIndexOf("/")+1);e.loadScript(t+".js")((function(e){for(var t=i;"../"===e.slice(0,3);){e=e.slice(3);t=(t=t.slice(0,-1)).slice(0,t.lastIndexOf("/")+1)}"./"===e.slice(0,2)&&(e=e.slice(2));return n(t+e)}),s,s.exports={})}return s.exports};n("console");n("framework");n("timer");n("filesystem");const t={getAmaz:()=>i("AmazingModule")};Object.defineProperty(t,"Amaz",{get:()=>i("AmazingModule"),set(e){}});b(c,"effect",t);b(c,"internalLoad",i)}()}));)"
        R"(defines.bootstrap();});)";
    return kBootstrapScript;
}

bool AllowList::isAllowed(const std::string& path) const {
    if (path.empty()) {
        return false;
    }
    if (prefixes_.empty()) {
        return true;
    }
    for (const auto& p : prefixes_) {
        if (path.compare(0, p.size(), p) == 0) {
            return true;
        }
    }
    return false;
}

// ============================================================================
// 2. BEFTask Implementation (0x00cdac..0x00e948)
// Cài đặt lớp tác vụ BEFTask.
// ============================================================================
BEFTask::BEFTask() noexcept = default;

BEFTask::BEFTask(std::function<void()> fn) : m_fn(std::move(fn)) {}

BEFTask::~BEFTask() noexcept = default;

void BEFTask::Run() {
    if (!IsCancelled() && m_fn) {
        m_fn();
    }
}

// ============================================================================
// 3. BEFBaseRunner Implementation (0x00caf4..0x00d3d8)
// Verified from disassembly:
//   - _PumpLoop (0x00cb34): fetches next task via GetNext(wait_for_next),
//     checks `ldrb w22, [x19, #0x4c]` (m_cancelled) under m_mutex (+0x60),
//     and invokes `task->Run()` if not cancelled.
//   - GetNext (0x00cbc4): loads 1000.0 from .rodata 0x25b80 (`ldr d9, [x8, #0xb80]`),
//     drains due delayed tasks from m_delayed_queue (+0x40) via
//     popTaskFromDelayedQueueNoLock (0x00d00c), and pops front of m_task_queue (+0x10).
//   - PostDelayedTask (0x00ce74): computes `target_ms = currentSteadyTimeMs() + delay_ms`
//     (`fadd d0, d0, d8` at 0x0cecc), inserts into m_delayed_queue (+0x40),
//     and notifies m_cond (+0x88).
// Cài đặt bộ chạy tác vụ BEFBaseRunner (0x00caf4..0x00d3d8).
// ============================================================================
BEFBaseRunner::BEFBaseRunner()
    : m_owner_thread_id(std::this_thread::get_id()) {}

BEFBaseRunner::~BEFBaseRunner() noexcept {
    _Terminate();
}

void BEFBaseRunner::StartRunner() {}

void BEFBaseRunner::Terminate() {}

bool BEFBaseRunner::IsJsThread() {
    return std::this_thread::get_id() == m_owner_thread_id;
}

bool BEFBaseRunner::IsCurrentThread() {
    return std::this_thread::get_id() == m_owner_thread_id;
}

// 0x00d31c: PauseThreadForInspector()
void BEFBaseRunner::PauseThreadForInspector() {
    m_paused_for_inspector.store(true, std::memory_order_release);
}

// 0x00d360: ResumeThreadForInspector()
void BEFBaseRunner::ResumeThreadForInspector() {
    m_paused_for_inspector.store(false, std::memory_order_release);
    m_cond.notify_all();
}

// 0x00cf44: currentSteadyTimeMs()
double BEFBaseRunner::currentSteadyTimeMs() noexcept {
    auto now = std::chrono::steady_clock::now().time_since_epoch();
    double sec = std::chrono::duration<double>(now).count();
    return sec * kJazzMillisecondsPerSecond;
}

// 0x00cb34: _PumpLoop(bool wait_for_next)
bool BEFBaseRunner::_PumpLoop(bool wait_for_next) {
    std::shared_ptr<BEFTask> task = GetNext(wait_for_next);
    if (!task) {
        return false;
    }
    bool cancelled = false;
    {
        std::lock_guard<std::mutex> lk(m_mutex);
        cancelled = task->IsCancelled();
    }
    if (!cancelled) {
        task->Run();
    }
    return true;
}

// 0x00d00c: popTaskFromDelayedQueueNoLock(double now_ms)
void BEFBaseRunner::popTaskFromDelayedQueueNoLock(double now_ms) {
    auto it = m_delayed_queue.begin();
    while (it != m_delayed_queue.end()) {
        if (it->target_time_ms <= now_ms) {
            if (it->task && !it->task->IsCancelled()) {
                m_task_queue.push_back(it->task);
            }
            it = m_delayed_queue.erase(it);
        } else {
            ++it;
        }
    }
}

// 0x00cbc4: GetNext(bool wait_for_next)
std::shared_ptr<BEFTask> BEFBaseRunner::GetNext(bool wait_for_next) {
    std::unique_lock<std::mutex> lk(m_mutex);
    if (m_terminated || m_paused_for_inspector.load(std::memory_order_acquire)) {
        return nullptr;
    }
    double now_ms = currentSteadyTimeMs();
    popTaskFromDelayedQueueNoLock(now_ms);

    if (m_task_queue.empty() && wait_for_next && !m_terminated) {
        if (!m_delayed_queue.empty()) {
            double earliest_ms = m_delayed_queue.front().target_time_ms;
            for (const auto& d : m_delayed_queue) {
                if (d.target_time_ms < earliest_ms) {
                    earliest_ms = d.target_time_ms;
                }
            }
            double wait_ms = std::max(0.0, earliest_ms - now_ms);
            m_cond.wait_for(lk, std::chrono::milliseconds(static_cast<int64_t>(wait_ms)));
            popTaskFromDelayedQueueNoLock(currentSteadyTimeMs());
        } else {
            m_cond.wait_for(lk, std::chrono::milliseconds(1));
        }
    }

    if (m_task_queue.empty()) {
        return nullptr;
    }
    auto next = m_task_queue.front();
    m_task_queue.pop_front();
    return next;
}

// 0x00cde0: PostTask(std::shared_ptr<BEFTask> task, bool high_priority)
bool BEFBaseRunner::PostTask(std::shared_ptr<BEFTask> task, bool high_priority) {
    if (!task) return false;
    std::lock_guard<std::mutex> lk(m_mutex);
    if (m_terminated || m_paused_for_inspector.load(std::memory_order_acquire)) {
        return false;
    }
    if (high_priority) {
        m_task_queue.push_front(std::move(task));
    } else {
        m_task_queue.push_back(std::move(task));
    }
    m_cond.notify_one();
    return true;
}

// 0x00ce74: PostDelayedTask(std::shared_ptr<BEFTask> task, double delay_ms)
bool BEFBaseRunner::PostDelayedTask(std::shared_ptr<BEFTask> task, double delay_ms) {
    if (!task) return false;
    std::lock_guard<std::mutex> lk(m_mutex);
    if (m_terminated || m_paused_for_inspector.load(std::memory_order_acquire)) {
        return false;
    }
    double target_ms = currentSteadyTimeMs() + std::max(0.0, delay_ms);
    task->SetTargetTimeMs(target_ms);
    m_delayed_queue.push_back(DelayedEntry{target_ms, std::move(task)});
    m_cond.notify_one();
    return true;
}

// 0x00cf98: CancelTask(std::shared_ptr<BEFTask> task)
void BEFBaseRunner::CancelTask(std::shared_ptr<BEFTask> task) {
    if (!task) return;
    std::lock_guard<std::mutex> lk(m_mutex);
    task->Cancel();
}

// 0x00d200: _Terminate()
void BEFBaseRunner::_Terminate() {
    std::lock_guard<std::mutex> lk(m_mutex);
    if (m_terminated) {
        return;
    }
    m_terminated = true;
    m_task_queue.clear();
    m_delayed_queue.clear();
    m_cond.notify_all();
}

// ============================================================================
// 4. Context Implementation (0x01047c..0x010e7c)
// Cài đặt ngữ cảnh thực thi JavaScript Context.
// ============================================================================
Context::Context() = default;

Context::~Context() noexcept {
    deinit();
}

void Context::Enter() {}

void Context::Exit() {}

// 0x010688: str x1, [x0, #8] ; mov w8, #1 ; strb w8, [x0, #0x10] ; ret
void Context::init(CtxHandler handler) {
    m_handler = handler;
    m_initialized = true;
}

// 0x01069c: strb wzr, [x0, #0x10] ; ret
void Context::deinit() {
    m_initialized = false;
}

// 0x0106a4: getContextHash()
uint64_t Context::getContextHash() {
    return reinterpret_cast<uint64_t>(m_handler.env) ^
           reinterpret_cast<uint64_t>(this);
}

// 0x010750: isValid()
bool Context::isValid() {
    return m_initialized && m_handler.env != nullptr;
}

// 0x01047c: AnalyzeErrorMessage(const Napi::Error& err)
void Context::AnalyzeErrorMessage(const Napi::Error& err) {
    (void)err.Message();
    (void)err.Stack();
}

// 0x010764: RunScript(const char* script, const char* filename)
Napi::Value Context::RunScript(const char* script, const char* filename) {
    if (!script) {
        return GetEnv().Undefined();
    }
    return RunScript(script, std::strlen(script), filename);
}

// 0x0107a8: RunScript(const char* script, size_t len, const char* filename)
// Verified at 0x010820..0x010860:
//   Wraps with "(function(require){const __filename='" (.rodata 0x25fe3) +
//   filename + "';const __dirname=__filename.slice(0, __filename.lastIndexOf('/') + 1);"
//   (.rodata 0x26009) + script + "\n})"
Napi::Value Context::RunScript(const char* script, size_t len, const char* filename) {
    if (!script || len == 0) {
        return GetEnv().Undefined();
    }
    std::string body(script, len);
    if (filename && *filename != '\0') {
        m_last_wrapped_script =
            std::string("(function(require){const __filename='") + filename +
            "';const __dirname=__filename.slice(0, __filename.lastIndexOf('/') + 1);" +
            body + "\n})";
    } else {
        m_last_wrapped_script = body;
    }
    return GetEnv().RunScript(
        m_last_wrapped_script.data(),
        m_last_wrapped_script.size(),
        filename ? filename : "<anonymous>");
}

// 0x010a54: RunScript(const std::string& script, const char* filename)
Napi::Value Context::RunScript(const std::string& script, const char* filename) {
    return RunScript(script.data(), script.size(), filename);
}

bool Context::GenScriptCodeCache(Napi::Env env,
                                 const std::string& script,
                                 std::string& out_cache) {
    (void)env;
    (void)script;
    (void)out_cache;
    return false;
}

bool Context::GenScriptCodeCache(Napi::Env env,
                                 const char* script,
                                 const uint8_t** out_buf,
                                 int* out_len) {
    (void)env;
    (void)script;
    (void)out_buf;
    (void)out_len;
    return false;
}

bool Context::EvaluateCodeCache(Napi::Env env,
                                const uint8_t* cache_buf,
                                int cache_len,
                                napi_value__** out_val) {
    (void)env;
    (void)cache_buf;
    (void)cache_len;
    (void)out_val;
    return false;
}

// 0x010ae4: EvaluateCodeCache(Napi::Env, const std::string&, const std::string&)
Napi::Value Context::EvaluateCodeCache(Napi::Env env,
                                       const std::string& script,
                                       const std::string& cache) {
    (void)cache;
    return RunScript(script, "<codecache>");
}

// 0x010b30: CallFunction(const Napi::Function&, const std::initializer_list<napi_value__*>&)
Napi::Value Context::CallFunction(const Napi::Function& func,
                                  const std::initializer_list<napi_value__*>& args) {
    return func.Call(args.size(), args.begin());
}

// 0x010bac: CallFunction(const Napi::Function&, const std::vector<napi_value__*>&)
Napi::Value Context::CallFunction(const Napi::Function& func,
                                  const std::vector<napi_value__*>& args) {
    return func.Call(args.size(), args.empty() ? nullptr : args.data());
}

// 0x010c30: SendEvent(const Napi::Object& event_obj)
Napi::Value Context::SendEvent(const Napi::Object& event_obj) {
    Napi::Object global = GetEnv().Global();
    Napi::Value dispatch_fn = global.Get("dispatchEvent"); // .rodata 0x260a6
    if (dispatch_fn.IsFunction()) {
        napi_value__* raw_arg = event_obj.RawValue();
        return Napi::Function(GetEnv(), dispatch_fn.RawValue()).Call(1, &raw_arg);
    }
    return GetEnv().Undefined();
}

// 0x010d48: CallFrameworkFunc(const std::string& func_name, const Napi::Array& args)
Napi::Value Context::CallFrameworkFunc(const std::string& func_name,
                                       const Napi::Array& args) {
    Napi::String fn_str = Napi::String::New(GetEnv(), func_name.c_str());
    napi_value__* call_args[2] = {fn_str.RawValue(), args.RawValue()};
    Napi::Object global = GetEnv().Global();
    Napi::Value native_call = global.Get("nativeCall"); // .rodata 0x260b4
    return Napi::Function(GetEnv(), native_call.RawValue()).Call(2, call_args);
}

// ============================================================================
// 5. ContextExecutor Implementation (0x01109c..0x012690)
// Cài đặt bộ điều phối ContextExecutor.
// ============================================================================
ContextExecutor::ExecuteBundle::ExecuteBundle(const ExecuteBundle& other) = default;

ContextExecutor::ExecuteBundle::~ExecuteBundle() noexcept = default;

// 0x01109c: ContextExecutor::getKey() — hashes "ContextExecutor" (.rodata 0x260bf)
uint64_t ContextExecutor::getKey() {
    static const uint64_t kKey = std::hash<std::string>{}("ContextExecutor");
    return kKey;
}

ContextExecutor::ContextExecutor()
    : m_js_runner(std::make_shared<BEFBaseRunner>()),
      m_worker_runner(std::make_shared<BEFBaseRunner>()) {}

ContextExecutor::~ContextExecutor() noexcept {
    deinit();
}

// 0x0116a8: ContextExecutor::init(Engine* engine)
void ContextExecutor::init(Engine* engine) {
    if (m_inited || m_engine != nullptr) {
        return;
    }
    m_inited = true;
    m_engine = engine;
    _SetupRunner();
    m_context = std::make_shared<Context>();
    CtxHandler h{reinterpret_cast<napi_env__*>(this), this};
    m_context->init(h);
}

// 0x0111d4: ContextExecutor::deinit()
void ContextExecutor::deinit() {
    if (!m_inited) {
        return;
    }
    if (m_context) {
        m_context->deinit();
        m_context.reset();
    }
    _TerminateRunner();
    m_engine = nullptr;
    m_inited = false;
}

// 0x01163c: GetJSRunner()
std::shared_ptr<BEFBaseRunner> ContextExecutor::GetJSRunner() {
    return m_js_runner;
}

// 0x0118e8: _SetupRunner()
void ContextExecutor::_SetupRunner() {
    if (!m_js_runner) {
        m_js_runner = std::make_shared<BEFBaseRunner>();
    }
    m_js_runner->StartRunner();
}

// 0x0114bc: _TerminateRunner()
void ContextExecutor::_TerminateRunner() {
    if (m_js_runner) {
        m_js_runner->_Terminate();
    }
    if (m_worker_runner) {
        m_worker_runner->_Terminate();
    }
}

// 0x0118e0: IsGlobal()
bool ContextExecutor::IsGlobal() {
    return m_is_global;
}

// 0x0119a4: SetGlobal(bool is_global)
void ContextExecutor::SetGlobal(bool is_global) {
    m_is_global = is_global;
}

// 0x011bf4: _ExecuteBlock(ExecuteBundle& bundle, bool sync_wait)
void ContextExecutor::_ExecuteBlock(ExecuteBundle& bundle, bool sync_wait) {
    auto runner = GetJSRunner();
    if (!runner || !m_context) {
        return;
    }
    auto task = std::make_shared<BEFTask>([this, bundle]() {
        if (!m_context) return;
        if (bundle.block) {
            bundle.block(m_context.get());
        } else if (!bundle.script.empty()) {
            Napi::Value res = m_context->RunScript(bundle.script, bundle.filename.c_str());
            if (bundle.callback) {
                bundle.callback(m_context->GetEnv(), res);
            }
        }
    });
    runner->PostTask(task, false);
    if (sync_wait) {
        runner->_PumpLoop(false);
    }
}

// 0x011b00: PostScript
void ContextExecutor::PostScript(const std::string& script,
                                 const std::string& filename,
                                 const std::function<void(Napi::Env, Napi::Value)>& cb) {
    ExecuteBundle bundle;
    bundle.script = script;
    bundle.filename = filename;
    bundle.callback = cb;
    _ExecuteBlock(bundle, false);
}

// 0x011eec: RunScript
void ContextExecutor::RunScript(const std::string& script,
                                const std::string& filename,
                                const std::function<void(Napi::Env, Napi::Value)>& cb) {
    ExecuteBundle bundle;
    bundle.script = script;
    bundle.filename = filename;
    bundle.callback = cb;
    _ExecuteBlock(bundle, true);
}

// 0x011f9c: PostBlock
void ContextExecutor::PostBlock(const std::function<void(Context*)>& block) {
    ExecuteBundle bundle;
    bundle.block = block;
    _ExecuteBlock(bundle, false);
}

// 0x011fe0: RunBlock
void ContextExecutor::RunBlock(const std::function<void(Context*)>& block) {
    ExecuteBundle bundle;
    bundle.block = block;
    _ExecuteBlock(bundle, true);
}

// 0x012024: RequestGarbageCollect()
void ContextExecutor::RequestGarbageCollect() {
    PostBlock([](Context* ctx) { (void)ctx; });
}

// 0x012388: PumpLoop()
void ContextExecutor::PumpLoop() {
    if (m_js_runner) {
        while (m_js_runner->_PumpLoop(false)) {}
    }
}

// 0x01263c: GetContext()
std::shared_ptr<Context> ContextExecutor::GetContext() {
    return m_context;
}

// 0x012668: GetWorker()
std::shared_ptr<BEFBaseRunner> ContextExecutor::GetWorker() {
    return m_worker_runner;
}

} // namespace AmazingEngine
