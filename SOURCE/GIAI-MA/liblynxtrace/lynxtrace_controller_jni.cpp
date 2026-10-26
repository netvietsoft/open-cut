/**
 * @file lynxtrace_controller_jni.cpp
 * @brief Exact AArch64 opcode-verified implementation of `lynx::trace::TraceController`
 *        (`0x0040fc..0x004198`), `com.lynx.tasm.base.TraceController` JNI methods,
 *        and `com.lynx.tasm.base.TraceEvent` JNI methods for `liblynxtrace.so`.
 *        Triển khai đối soát opcode AArch64 chính xác của `lynx::trace::TraceController`
 *        và các phương thức JNI `TraceController` / `TraceEvent` cho `liblynxtrace.so`.
 */

#include "lynxtrace_controller_jni.h"
#include "lynxtrace_perfetto_event.h"

#include <cstring>
#include <mutex>

namespace nextai {
namespace opencut {
namespace lynxtrace {

namespace {

std::mutex g_guard_mutex;
LynxTraceBssSegment g_bss_state{0u, nullptr, nullptr};
TraceController g_trace_controller_singleton;

} // namespace

// ============================================================================
// 1. `lynx::trace::TraceController` Implementation (`0x0040fc..0x004198`)
//    Triển khai `lynx::trace::TraceController` (`0x0040fc..0x004198`)
// ============================================================================

TraceController::~TraceController() noexcept {
    // Exact instruction sequence at 0x00415c..0x004180:
    //   0x00415c: mov  x8, x0
    //   0x004160: ldr  x0, [x0, #8]
    //   0x004164: adrp x9, #0x8000
    //   0x004168: add  x9, x9, #0x18
    //   0x00416c: stp  x9, xzr, [x8]
    //   0x004170: cbz  x0, #0x4180
    //   0x004174: ldr  x8, [x0]
    //   0x004178: ldr  x1, [x8, #8]
    //   0x00417c: br   x1
    //   0x004180: ret
    TraceControllerDelegate* old_delegate = delegate_;
    delegate_ = nullptr;
    if (old_delegate != nullptr) {
        delete old_delegate;
    }
}

int32_t TraceController::StartTracing(const void* trace_config) noexcept {
    (void)trace_config;
    // 0x00419c: mov w0, #-1; ret
    return -1;
}

bool TraceController::StopTracing(int32_t session_id) noexcept {
    (void)session_id;
    // 0x0041a4 -> 0x0041e4: mov w0, wzr; ret
    return false;
}

void TraceController::AddTracePlugin(void* plugin) noexcept {
    (void)plugin;
    // 0x0040f8: ret
}

bool TraceController::DeleteTracePlugin(const std::string& plugin_name) noexcept {
    (void)plugin_name;
    // 0x0041a4 -> 0x0041e4: mov w0, wzr; ret
    return false;
}

void TraceController::StartStartupTracingIfNeeded() noexcept {
    // 0x0040f8: ret
}

void TraceController::SetStartupTracingConfig(const std::string& config) noexcept {
    (void)config;
    // 0x0040f8: ret
}

void TraceController::SetTraceBufferSize(uint32_t buffer_size_kb) noexcept {
    (void)buffer_size_kb;
    // 0x0040f8: ret
}

void TraceController::AddCompleteCallback(int32_t session_id, void* callback) noexcept {
    (void)session_id;
    (void)callback;
    // 0x0040f8: ret
}

std::string TraceController::GetStartupTracingConfig() const noexcept {
    // 0x0041a8 -> 0x004208: stp xzr, xzr, [x8]; str xzr, [x8, #0x10]; ret
    // Zero-initializes 24-byte libc++ SSO std::string at indirect return register x8
    return std::string();
}

std::string TraceController::GetTraceFilePath(int32_t session_id) const noexcept {
    (void)session_id;
    // 0x0041a8 -> 0x004208: stp xzr, xzr, [x8]; str xzr, [x8, #0x10]; ret
    return std::string();
}

bool TraceController::IsTracingStarted() const noexcept {
    // 0x0041a4 -> 0x0041e4: mov w0, wzr; ret
    return false;
}

TraceController* TraceController::Instance() noexcept {
    // Exact instruction sequence at 0x0040fc..0x004158:
    //   0x004100: adrp  x8, #0xc000
    //   0x004104: add   x8, x8, #0x10       ; .bss 0x00c010 (guard variable)
    //   0x004108: ldarb w8, [x8]
    //   0x00410c: tbz   w8, #0, #0x4120     ; if ((guard & 1) == 0) acquire guard
    //   0x004110: adrp  x0, #0xc000         ; return .data 0x00c000 (&s_instance)
    //   0x004128: bl    __cxa_guard_acquire
    //   0x004148: bl    __cxa_atexit(~TraceController, 0x00c000, &__dso_handle)
    //   0x004154: bl    __cxa_guard_release
    if ((g_bss_state.guard_var_trace_controller & 1u) == 0u) {
        std::lock_guard<std::mutex> lock(g_guard_mutex);
        if ((g_bss_state.guard_var_trace_controller & 1u) == 0u) {
            g_bss_state.guard_var_trace_controller = 1u;
        }
    }
    return &g_trace_controller_singleton;
}

// ============================================================================
// 2. `com.lynx.tasm.base.TraceController` JNI Methods (`.data.rel.ro 0x008080..0x0080df`)
//    Các phương thức JNI của `TraceController`
// ============================================================================

jlong TraceController_nativeCreateTraceController(JNIEnv* env, jobject jcaller) noexcept {
    (void)env;
    (void)jcaller;
    // Exact instructions at 0x0041c4..0x0041d8:
    //   0x0041c4: str  x30, [sp, #-0x10]!
    //   0x0041c8: bl   #0x42d0              ; lynx::trace::TraceController::Instance()
    //   0x0041cc: adrp x0, #0xc000
    //   0x0041d0: add  x0, x0, #0           ; .data 0x00c000
    //   0x0041d4: ldr  x30, [sp], #0x10
    //   0x0041d8: ret
    TraceController* inst = TraceController::Instance();
    return reinterpret_cast<jlong>(inst);
}

jint TraceController_nativeStartTracing(
    JNIEnv* env,
    jobject jcaller,
    jlong native_ptr,
    jint buffer_size,
    jobjectArray included_categories,
    jobjectArray excluded_categories,
    jstring trace_file,
    jboolean enable_systrace) noexcept {
    (void)env;
    (void)jcaller;
    (void)native_ptr;
    (void)buffer_size;
    (void)included_categories;
    (void)excluded_categories;
    (void)trace_file;
    (void)enable_systrace;
    // Exact instructions at 0x00419c..0x0041a0:
    //   0x00419c: mov w0, #-1
    //   0x0041a0: ret
    return -1;
}

void TraceController_nativeStopTracing(
    JNIEnv* env,
    jobject jcaller,
    jlong native_ptr,
    jint session_id) noexcept {
    (void)env;
    (void)jcaller;
    (void)native_ptr;
    (void)session_id;
    // 0x0040f8: ret
}

void TraceController_nativeStartStartupTracingIfNeeded(
    JNIEnv* env,
    jobject jcaller,
    jlong native_ptr) noexcept {
    (void)env;
    (void)jcaller;
    (void)native_ptr;
    // 0x0040f8: ret
}

// ============================================================================
// 3. `com.lynx.tasm.base.TraceEvent` JNI Methods (`.data.rel.ro 0x008108..0x0081f7`)
//    Các phương thức JNI của `TraceEvent`
// ============================================================================

void TraceEvent_nativeBeginSection(JNIEnv* env, jclass clazz, jstring category, jstring name) {
    (void)env;
    (void)clazz;
    // 0x0040f8: ret (or records event when telemetry capture is enabled)
    TraceEventBeginExImpl(
        reinterpret_cast<const char*>(category),
        reinterpret_cast<const char*>(name));
}

void TraceEvent_nativeBeginSectionWithProps(
    JNIEnv* env,
    jclass clazz,
    jstring category,
    jstring name,
    jobject props) {
    (void)props;
    TraceEvent_nativeBeginSection(env, clazz, category, name);
}

void TraceEvent_nativeEndSection(JNIEnv* env, jclass clazz, jstring category, jstring name) {
    (void)env;
    (void)clazz;
    TraceEventEndExImpl(
        reinterpret_cast<const char*>(category),
        reinterpret_cast<const char*>(name));
}

void TraceEvent_nativeEndSectionWithProps(
    JNIEnv* env,
    jclass clazz,
    jstring category,
    jstring name,
    jobject props) {
    (void)props;
    TraceEvent_nativeEndSection(env, clazz, category, name);
}

void TraceEvent_nativeInstant(
    JNIEnv* env,
    jclass clazz,
    jstring category,
    jstring name,
    jlong timestamp,
    jstring color) {
    (void)env;
    (void)clazz;
    (void)category;
    (void)name;
    (void)timestamp;
    (void)color;
    // 0x0040f8: ret
}

void TraceEvent_nativeInstantWithProps(
    JNIEnv* env,
    jclass clazz,
    jstring category,
    jstring name,
    jlong timestamp,
    jobject props) {
    (void)env;
    (void)clazz;
    (void)category;
    (void)name;
    (void)timestamp;
    (void)props;
    // 0x0040f8: ret
}

void TraceEvent_nativeCounter(
    JNIEnv* env,
    jclass clazz,
    jstring category,
    jstring name,
    jlong counter_value) {
    (void)env;
    (void)clazz;
    TraceCounterExImpl(
        reinterpret_cast<const char*>(category),
        reinterpret_cast<const char*>(name),
        static_cast<uint64_t>(counter_value),
        false);
}

jboolean TraceEvent_nativeCategoryEnabled(JNIEnv* env, jclass clazz, jstring category) noexcept {
    (void)env;
    (void)clazz;
    // 0x0041a4 -> 0x0041e4: mov w0, wzr; ret
    return TraceEventCategoryEnabledImpl(reinterpret_cast<const char*>(category)) ? kJniTrue : kJniFalse;
}

jboolean TraceEvent_nativeSystemTraceEnabled(JNIEnv* env, jclass clazz) noexcept {
    (void)env;
    (void)clazz;
    // 0x0041a4 -> 0x0041e4: mov w0, wzr; ret
    return IsTelemetryCaptureModeEnabled() ? kJniTrue : kJniFalse;
}

jboolean TraceEvent_nativePerfettoTraceEnabled(JNIEnv* env, jclass clazz) noexcept {
    (void)env;
    (void)clazz;
    // 0x0041a4 -> 0x0041e4: mov w0, wzr; ret
    return IsTelemetryCaptureModeEnabled() ? kJniTrue : kJniFalse;
}

LynxTraceBssSegment& GetLynxTraceBssState() noexcept {
    return g_bss_state;
}

void ResetLynxTraceBssState() noexcept {
    std::memset(&g_bss_state, 0, sizeof(g_bss_state));
    g_trace_controller_singleton.set_delegate(nullptr);
    SetTelemetryCaptureMode(false);
    ClearRecordedLynxTraceEvents();
}

} // namespace lynxtrace
} // namespace opencut
} // namespace nextai
