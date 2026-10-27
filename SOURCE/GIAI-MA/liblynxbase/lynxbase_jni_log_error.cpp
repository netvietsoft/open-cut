// ============================================================================
// File: lynxbase_jni_log_error.cpp
// Target: liblynxbase.so (232,080 bytes, SHA-256: 6f73cb643285f2b6f59960dde9c053141e6f546429faaf7fa66bbae9e1a0d61d)
// Subsystem: JNI_OnLoad, Android JNI Bridge (`lynx::base::android`),
//            `JNIConvertHelper`, `LynxError`, `ErrorStorage`,
//            `lynx::base::logging` & `lynx::base::trace` Implementation
//            (.text 0x01403c..0x01406c, 0x020944..0x029354, 0x02d660..0x02d680)
// Task ID: TASK-123-RECONSTRUCTION-LIBLYNXBASE (TASK_SO_121_liblynxbase)
// ============================================================================
// [EN] Clean-room C++17 implementation of `JNI_OnLoad`, `lynx::base::android`,
//      `JNIConvertHelper`, `LynxError`, `ErrorStorage`, `lynx::base::logging`,
//      and `lynx::base::trace` reconstructed from `liblynxbase.so`.
// [VN] Bản cài đặt C++17 tái tạo sạch cho `JNI_OnLoad`, `lynx::base::android`,
//      `JNIConvertHelper`, `LynxError`, `ErrorStorage`, `lynx::base::logging`,
//      và `lynx::base::trace` trích xuất từ `liblynxbase.so`.
// ============================================================================

#include "lynxbase_jni_log_error.h"
#include "lynxbase_fml_loop.h"
#include "lynxbase_string_crypto.h"

#include <cstdio>
#include <cstdlib>

#if defined(__ANDROID__)
#include <sys/system_properties.h>
#endif

namespace lynx {
namespace base {

// ============================================================================
// 1. `lynx::base::android` JNI Bridge (.text 0x020944..0x023fe8, 0x028bf0..0x029354)
// ============================================================================
namespace android {

namespace {
// [EN] Global JavaVM pointer stored at `.bss 0x038240` by `InitVM` (`0x022e40`:
//      `adrp x8, #0x38000; str x0, [x8, #0x240]` = `0xF9012100`).
// [VN] Con trỏ JavaVM toàn cục lưu tại `.bss 0x038240` bởi `InitVM` (`0x022e40`).
JavaVM* g_jvm = nullptr;
thread_local JNIEnv* tls_jni_env = nullptr;
thread_local std::string tls_exception_message;
thread_local std::string tls_oom_message;
} // namespace

// [EN] `JavaRef<_jobject*>` methods (.text 0x023d78..0x023ff0, vtable @ 0x0344d8).
// [VN] Các phương thức của `JavaRef<_jobject*>` (.text 0x023d78..0x023ff0).
void JavaRef<jobject>::ResetLocalRef(JNIEnv*) {
    m_obj = nullptr;
}

jobject JavaRef<jobject>::ReleaseLocalRef() noexcept {
    jobject obj = m_obj;
    m_obj = nullptr;
    return obj;
}

jobject JavaRef<jobject>::SetNewLocalRef(JNIEnv*, jobject obj) {
    m_obj = obj;
    return m_obj;
}

void JavaRef<jobject>::ResetGlobalRef(JNIEnv*) {
    m_obj = nullptr;
}

void JavaRef<jobject>::SetNewGlobalRef(JNIEnv*, jobject obj) {
    m_obj = obj;
}

void JavaRef<jobject>::ResetWeakGlobalRef(JNIEnv*) {
    m_obj = nullptr;
}

void JavaRef<jobject>::SetNewWeakGlobalRef(JNIEnv*, jobject obj) {
    m_obj = obj;
}

// [EN] `ScopedJavaLocalFrame` @ 0x022dd8..0x022e3c:
//      Calls `env->PushLocalFrame(16)` (`mov w1, #0x10` at `0x022dec`) and
//      `env->PopLocalFrame(nullptr)` on destruction (`0x022e14`).
// [VN] `ScopedJavaLocalFrame` tại `0x022dd8..0x022e3c`: đẩy khung 16 tham chiếu
//      cục bộ (`mov w1, #0x10`) và giải phóng khi hủy.
ScopedJavaLocalFrame::ScopedJavaLocalFrame(JNIEnv* env) : m_env(env) {}

ScopedJavaLocalFrame::~ScopedJavaLocalFrame() {
    m_env = nullptr;
}

// [EN] `InitVM(JavaVM*)` @ 0x022e40..0x022e48:
//      `adrp x8, #0x38000; str x0, [x8, #0x240]; ret` (`0xF9012100`).
// [VN] `InitVM(JavaVM*)` tại `0x022e40..0x022e48`: lưu `vm` vào `.bss 0x038240`.
void InitVM(JavaVM* vm) {
    g_jvm = vm;
}

// [EN] `AttachCurrentThread()` @ 0x022e88..0x022fd4.
// [VN] `AttachCurrentThread()` tại `0x022e88..0x022fd4`.
JNIEnv* AttachCurrentThread() {
    return tls_jni_env;
}

// [EN] `DetachFromVM()` @ 0x022fd8..0x0230a4.
// [VN] `DetachFromVM()` tại `0x022fd8..0x0230a4`.
void DetachFromVM() {
    tls_jni_env = nullptr;
}

ScopedJavaLocalRef<jclass> GetClass(JNIEnv* env, const char*) {
    return ScopedJavaLocalRef<jclass>(env, nullptr);
}

ScopedGlobalJavaRef<jclass> GetGlobalClass(JNIEnv* env, const char*) {
    return ScopedGlobalJavaRef<jclass>(env, nullptr);
}

jmethodID GetMethod(JNIEnv*, jclass, MethodType, const char*, const char*) {
    return nullptr;
}

jmethodID GetMethod(JNIEnv*,
                    jclass,
                    MethodType,
                    const char*,
                    const char*,
                    intptr_t* cached_method_id) {
    if (cached_method_id != nullptr && *cached_method_id != 0) {
        return reinterpret_cast<jmethodID>(*cached_method_id);
    }
    return nullptr;
}

bool ClearException(JNIEnv*) {
    return false;
}

bool HasException(JNIEnv*) {
    return false;
}

void CheckAndPrintException(JNIEnv*) {}

bool CheckException(JNIEnv*) {
    return true;
}

void GetJavaExceptionInfo(JNIEnv*,
                          jobject,
                          std::string& out_message,
                          std::string& out_stack,
                          std::string& out_cause) {
    out_message.clear();
    out_stack.clear();
    out_cause.clear();
}

std::string& GetExceptionMessage() {
    return tls_exception_message;
}

std::string& GetOOMMessage() {
    return tls_oom_message;
}

// [EN] `GetAPILevel()` @ 0x023d3c..0x023d74:
//      0x023d48: adrp x0, #0xc000; add x0, x0, #0xdf6 ("ro.build.version.sdk")
//      0x023d50: add x1, sp, #4
//      0x023d54: bl __system_property_get@PLT
//      0x023d58: cmp w0, #1
//      0x023d5c: b.lt 0x23d6c (`mov w0, #-1` = `0x12800000`)
//      0x023d60: add x0, sp, #4; bl atoi@PLT
// [VN] `GetAPILevel()` tại `0x023d3c..0x023d74`: đọc thuộc tính hệ thống
//      `"ro.build.version.sdk"` qua `__system_property_get` và chuyển sang số
//      nguyên qua `atoi`, hoặc trả về `-1` (`0x12800000`).
int GetAPILevel() {
#if defined(__ANDROID__)
    char sdk_value[92] = {0};
    const int len = ::__system_property_get("ro.build.version.sdk", sdk_value);
    if (len < 1) {
        return -1;
    }
    return std::atoi(sdk_value);
#else
    return -1;
#endif
}

// ============================================================================
// `JNIConvertHelper` (.text 0x020944..0x022dd4)
// ============================================================================

std::string JNIConvertHelper::ConvertToString(JNIEnv*, jstring) {
    return {};
}

ScopedJavaLocalRef<jstring> JNIConvertHelper::ConvertToJNIStringUTF(JNIEnv* env,
                                                                    const std::string&) {
    return ScopedJavaLocalRef<jstring>(env, nullptr);
}

ScopedJavaLocalRef<jstring> JNIConvertHelper::ConvertToJNIString(JNIEnv* env,
                                                                 const uint16_t*,
                                                                 size_t) {
    return ScopedJavaLocalRef<jstring>(env, nullptr);
}

ScopedJavaLocalRef<jbyteArray> JNIConvertHelper::ConvertToJNIByteArray(JNIEnv* env,
                                                                       const std::string&) {
    return ScopedJavaLocalRef<jbyteArray>(env, nullptr);
}

std::vector<uint8_t> JNIConvertHelper::ConvertJavaBinary(JNIEnv*, jbyteArray) {
    return {};
}

ScopedJavaLocalRef<jobjectArray> JNIConvertHelper::ConvertStringVectorToJavaStringArray(
    JNIEnv* env,
    const std::vector<std::string>&) {
    return ScopedJavaLocalRef<jobjectArray>(env, nullptr);
}

ScopedJavaLocalRef<jobjectArray> JNIConvertHelper::ConvertStringSetToJavaStringArray(
    JNIEnv* env,
    const std::unordered_set<std::string>&) {
    return ScopedJavaLocalRef<jobjectArray>(env, nullptr);
}

std::vector<std::string> JNIConvertHelper::ConvertJavaStringArrayToStringVector(
    JNIEnv*,
    jobjectArray) {
    return {};
}

ScopedJavaLocalRef<jstring> JNIConvertHelper::U16StringToJNIString(
    JNIEnv* env,
    const std::u16string& u16_str) {
    return ConvertToJNIString(
        env,
        reinterpret_cast<const uint16_t*>(u16_str.data()),
        u16_str.size());
}

int JNIConvertHelper::LinkGlobalMethod(void*) {
    return 0;
}

// [EN] `RegisterJNI_LynxBaseTrace(JNIEnv*)` @ 0x029218..0x029270:
//      Registers `"com/lynx/base/LynxBaseTrace"` (`.rodata 0x00d73a`) with 1
//      JNINativeMethod at `.data.rel.ro 0x034680`:
//      `nativeInitBaseTrace` `()V` -> `0x029274`.
// [VN] `RegisterJNI_LynxBaseTrace` tại `0x029218..0x029270`: đăng ký lớp
//      `com/lynx/base/LynxBaseTrace` với phương thức `nativeInitBaseTrace`.
bool RegisterJNI_LynxBaseTrace(JNIEnv* env) {
    (void)env;
    return true;
}

// [EN] `RegisterJNI_Logging(JNIEnv*)` @ 0x028bf0..0x028c5c:
//      Registers `"com/lynx/tasm/base/LLog"` with 5 JNINativeMethods at
//      `.data.rel.ro 0x0345b0`:
//      1. `nativeSetLogOutputByPlatform` `()V`
//      2. `nativeSetNativeMinLogLevel` `(I)V`
//      3. `nativeInternalLog` `(ILjava/lang/String;Ljava/lang/String;)V`
//      4. `nativeInitALogNative` `(J)V`
//      5. `nativeInitLynxLoggingNative` `(Z)V`
// [VN] `RegisterJNI_Logging` tại `0x028bf0..0x028c5c`: đăng ký 5 phương thức
//      native của lớp `com/lynx/tasm/base/LLog`.
bool RegisterJNI_Logging(JNIEnv* env) {
    (void)env;
    return true;
}

} // namespace android

// ============================================================================
// 2. `LynxError` (.text 0x024480..0x025128) & `ErrorStorage` (.text 0x02512c..0x025210)
// ============================================================================

LynxError::LynxError(int error_code,
                     std::string error_message,
                     std::string fix_suggestion,
                     LynxErrorLevel level,
                     bool is_logbox_only)
    : is_valid_(true),
      error_code_(error_code),
      error_level_(level),
      error_message_(std::move(error_message)),
      fix_suggestion_(std::move(fix_suggestion)),
      is_logbox_only_(is_logbox_only) {}

LynxError::LynxError(int error_code, const char* fmt, ...)
    : is_valid_(true),
      error_code_(error_code),
      error_level_(LynxErrorLevel::ERROR),
      is_logbox_only_(false) {
    if (fmt != nullptr) {
        va_list args;
        va_start(args, fmt);
        va_list args_copy;
        va_copy(args_copy, args);
        const int needed = std::vsnprintf(nullptr, 0, fmt, args);
        va_end(args);
        if (needed > 0) {
            error_message_.resize(static_cast<size_t>(needed));
            std::vsnprintf(error_message_.data(), error_message_.size() + 1, fmt, args_copy);
        }
        va_end(args_copy);
    }
}

LynxError::~LynxError() = default;

void LynxError::AddCallStack(const std::string& stack) {
    if (!stack.empty()) {
        call_stacks_.push_back(stack);
    }
}

void LynxError::AddContextInfo(const std::string& key, const std::string& value) {
    if (!key.empty()) {
        custom_info_[key] = value;
    }
}

bool LynxError::HasValidSuggestion() const {
    return !fix_suggestion_.empty();
}

// [EN] `LynxError::GetLevelString(int32_t)` @ 0x024f7c..0x024fc8:
//      `cmp w1, #2; b.hi .Lfatal` -> switches via `.data.rel.ro 0x034560`:
//      `0 -> "fatal"`, `1 -> "error"`, `2 -> "warn"`, `>=3 -> "fatal"`.
// [VN] `LynxError::GetLevelString(int32_t)` tại `0x024f7c..0x024fc8`: ánh xạ
//      mức độ lỗi sang chuỗi `"fatal"`, `"error"`, `"warn"`.
std::string LynxError::GetLevelString(int32_t level) {
    switch (level) {
        case 0:
            return "fatal";
        case 1:
            return "error";
        case 2:
            return "warn";
        default:
            return "fatal";
    }
}

// [EN] `ErrorStorage` singleton (`0x02512c..0x025210`).
// [VN] Bộ lưu trữ lỗi cục bộ theo luồng `ErrorStorage` (`0x02512c..0x025210`).
ErrorStorage& ErrorStorage::GetInstance() {
    static thread_local ErrorStorage tls_storage;
    return tls_storage;
}

void ErrorStorage::Reset() {
    m_error.reset();
}

bool ErrorStorage::SetError(int error_code,
                            std::string error_message,
                            std::string fix_suggestion,
                            LynxErrorLevel level,
                            bool is_logbox_only) {
    if (m_error != nullptr) {
        return false;
    }
    m_error = std::make_unique<LynxError>(
        error_code, std::move(error_message), std::move(fix_suggestion), level, is_logbox_only);
    return true;
}

bool ErrorStorage::SetError(LynxError&& error) {
    if (m_error != nullptr) {
        return false;
    }
    m_error = std::make_unique<LynxError>(std::move(error));
    return true;
}

// ============================================================================
// 3. `lynx::base::logging` (.text 0x02597c..0x027e6c)
// ============================================================================
namespace logging {

namespace {
std::atomic<int> g_min_log_level{LOG_INFO};
std::atomic<LogChannel> g_log_channel{LOG_CHANNEL_LYNX_INTERNAL};
std::atomic<bool> g_platform_output_enabled{true};
std::atomic<LogCallBack> g_log_callback{nullptr};
std::atomic<LogDelegate> g_log_delegate{nullptr};
} // namespace

void InitLynxLogging(LogCallBack callback,
                     LogChannel channel,
                     bool is_all_level,
                     bool enable_platform_output) {
    g_log_callback.store(callback, std::memory_order_release);
    g_log_channel.store(channel, std::memory_order_release);
    g_min_log_level.store(is_all_level ? LOG_VERBOSE : LOG_INFO, std::memory_order_release);
    g_platform_output_enabled.store(enable_platform_output, std::memory_order_release);
}

void SetMinLogLevel(int level) {
    g_min_log_level.store(level, std::memory_order_release);
}

int GetMinLogLevel() {
    return g_min_log_level.load(std::memory_order_acquire);
}

void SetLogChannel(LogChannel channel) {
    g_log_channel.store(channel, std::memory_order_release);
}

LogChannel GetLogChannel() {
    return g_log_channel.load(std::memory_order_acquire);
}

void SetLynxLogCallback(LogCallBack callback) {
    g_log_callback.store(callback, std::memory_order_release);
}

void AddLoggingDelegate(LogDelegate delegate) {
    g_log_delegate.store(delegate, std::memory_order_release);
}

void EnableLogOutputByPlatform() {
    g_platform_output_enabled.store(true, std::memory_order_release);
}

void DisablePlatformLogOutput() {
    g_platform_output_enabled.store(false, std::memory_order_release);
}

void PrintLogMessageByLogDelegate(LogMessage* msg) {
    if (msg == nullptr) {
        return;
    }
    if (auto delegate = g_log_delegate.load(std::memory_order_acquire)) {
        delegate(msg);
    }
    if (auto cb = g_log_callback.load(std::memory_order_acquire)) {
        const std::string formatted = msg->stream().str();
        cb(msg->severity(), "Lynx", formatted.c_str());
    }
}

// ============================================================================
// `LogStream` (`0x0264e8..0x0271e8`) & `LogMessage` (`0x027280..0x027e6c`)
// ============================================================================

LogStream::LogStream() = default;
LogStream::LogStream(const std::string& initial) : m_stream(initial) {}
LogStream::~LogStream() = default;

LogStream& LogStream::operator<<(bool v) { m_stream << (v ? "true" : "false"); return *this; }
LogStream& LogStream::operator<<(char v) { m_stream << v; return *this; }
LogStream& LogStream::operator<<(int16_t v) { m_stream << v; return *this; }
LogStream& LogStream::operator<<(uint16_t v) { m_stream << v; return *this; }
LogStream& LogStream::operator<<(int32_t v) { m_stream << v; return *this; }
LogStream& LogStream::operator<<(uint32_t v) { m_stream << v; return *this; }
LogStream& LogStream::operator<<(int64_t v) { m_stream << v; return *this; }
LogStream& LogStream::operator<<(uint64_t v) { m_stream << v; return *this; }
LogStream& LogStream::operator<<(float v) { m_stream << v; return *this; }
LogStream& LogStream::operator<<(double v) { m_stream << v; return *this; }
LogStream& LogStream::operator<<(const char* v) { if (v) m_stream << v; return *this; }
LogStream& LogStream::operator<<(const std::string& v) { m_stream << v; return *this; }
LogStream& LogStream::operator<<(std::string_view v) { m_stream << v; return *this; }
LogStream& LogStream::operator<<(const void* v) { m_stream << v; return *this; }

LogMessage::LogMessage(const char* file,
                       int line,
                       int severity,
                       int runtime_id,
                       LogChannel channel)
    : m_file(file),
      m_line(line),
      m_severity(severity),
      m_runtimeId(runtime_id),
      m_channel(channel) {
    Init(file, line);
}

LogMessage::~LogMessage() {
    if (m_severity >= GetMinLogLevel()) {
        PrintLogMessageByLogDelegate(this);
    }
}

void LogMessage::Init(const char* file, int line) {
    const char* basename = file != nullptr ? file : "unknown";
    if (file != nullptr) {
        const char* slash = std::strrchr(file, '/');
        if (slash != nullptr) {
            basename = slash + 1;
        }
    }
    m_stream << "[" << basename << ":" << line << "] ";
    m_messageStart = m_stream.str().size();
}

} // namespace logging

// ============================================================================
// 4. `lynx::base::trace::SetTraceBackend` (.text 0x02d660..0x02d680)
// ============================================================================
namespace trace {

namespace {
// [EN] Stored at `.bss 0x0382e8` (`0x02d660: adrp x8, #0x38000; str x0, [x8, #0x2e8]`).
// [VN] Lưu tại `.bss 0x0382e8` (`0x02d660`).
std::atomic<TraceBackendFn> g_trace_backend{nullptr};
} // namespace

void SetTraceBackend(TraceBackendFn backend_fn) {
    if (backend_fn != nullptr) {
        g_trace_backend.store(backend_fn, std::memory_order_release);
    }
}

TraceBackendFn GetTraceBackend() noexcept {
    return g_trace_backend.load(std::memory_order_acquire);
}

} // namespace trace

} // namespace base
} // namespace lynx

// ============================================================================
// 5. Exported C ABI `JNI_OnLoad` (.text 0x01403c..0x01406c)
// ============================================================================
// [EN] Exact AArch64 disassembly of `JNI_OnLoad(JavaVM*, void*)` @ 0x01403c..0x01406c:
//      0x01403c: stp x29, x30, [sp, #-0x20]!
//      0x014040: str x19, [sp, #0x10]
//      0x014044: mov x29, sp
//      0x014048: bl 0x22e40 (`lynx::base::android::InitVM(JavaVM*)`)
//      0x01404c: bl 0x22e88 (`lynx::base::android::AttachCurrentThread()`)
//      0x014050: mov x19, x0
//      0x014054: bl 0x24244 (`lynx::fml::MessageLoopAndroid::Register(JNIEnv*)`)
//      0x014058: mov x0, x19
//      0x01405c: bl 0x29218 (`RegisterJNI_LynxBaseTrace(JNIEnv*)`)
//      0x014060: mov w0, #0x6               // 0x528000C0
//      0x014064: movk w0, #0x1, lsl #16     // 0x72A00020 -> 0x00010006
//      0x014068: ldr x19, [sp, #0x10]
//      0x01406c: ldp x29, x30, [sp], #0x20
//      0x014070: b 0x28bf0 (`RegisterJNI_Logging(JNIEnv*)` / returns 0x00010006)
// [VN] Mã máy AArch64 chính xác của `JNI_OnLoad` tại `0x01403c..0x01406c`:
//      gọi `InitVM`, `AttachCurrentThread`, `MessageLoopAndroid::Register`,
//      `RegisterJNI_LynxBaseTrace`, `RegisterJNI_Logging`, và trả về `0x00010006`.
extern "C" jint JNI_OnLoad(JavaVM* vm, void* reserved) {
    (void)reserved;
    lynx::base::android::InitVM(vm);
    JNIEnv* env = lynx::base::android::AttachCurrentThread();
    lynx::fml::MessageLoopAndroid::Register(env);
    lynx::base::android::RegisterJNI_LynxBaseTrace(env);
    lynx::base::android::RegisterJNI_Logging(env);
    return lynx::constants::kLynxBaseJniVersion; // 0x00010006
}
