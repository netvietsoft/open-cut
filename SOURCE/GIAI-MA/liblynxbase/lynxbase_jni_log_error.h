// ============================================================================
// File: lynxbase_jni_log_error.h
// Target: liblynxbase.so (232,080 bytes, SHA-256: 6f73cb643285f2b6f59960dde9c053141e6f546429faaf7fa66bbae9e1a0d61d)
// Subsystem: JNI_OnLoad, Android JNI Bridge (`lynx::base::android`),
//            `JNIConvertHelper`, `LynxError`, `ErrorStorage`,
//            `lynx::base::logging` & `lynx::base::trace`
//            (.text 0x01403c..0x01406c, 0x020944..0x029354, 0x02d660..0x02d680)
// Task ID: TASK-123-RECONSTRUCTION-LIBLYNXBASE (TASK_SO_121_liblynxbase)
// ============================================================================
// [EN] Clean-room C++17 header declaring the Android JNI bootstrap (`JNI_OnLoad`),
//      `lynx::base::android` reference wrappers (`JavaRef`, `ScopedJavaLocalRef`,
//      `ScopedGlobalJavaRef`, `ScopedJavaLocalFrame`, `JNIConvertHelper`),
//      `lynx::base::LynxError` & `ErrorStorage`, `lynx::base::logging` (`LogStream`,
//      `LogMessage`), and `lynx::base::trace::SetTraceBackend`.
// [VN] File header C++17 tái tạo sạch điểm vào `JNI_OnLoad`, cầu nối JNI Android
//      (`JavaRef`, `ScopedJavaLocalRef`, `ScopedGlobalJavaRef`, `ScopedJavaLocalFrame`,
//      `JNIConvertHelper`), hệ thống lỗi `LynxError` & `ErrorStorage`, hệ thống
//      nhật ký `lynx::base::logging`, và `lynx::base::trace::SetTraceBackend`.
// ============================================================================

#ifndef LYNXBASE_JNI_LOG_ERROR_H_
#define LYNXBASE_JNI_LOG_ERROR_H_

#include "lynxbase_types.h"

namespace lynx {
namespace base {

// ============================================================================
// 1. `lynx::base::android` JNI Subsystem (.text 0x020944..0x023fe8)
// ============================================================================
namespace android {

// [EN] `JavaRef<_jobject*>` (.text 0x023d74..0x023ff0, vtable @ 0x0344d8).
// [VN] Lớp cơ sở quản lý tham chiếu đối tượng Java (`JavaRef<_jobject*>`).
template <typename T>
class JavaRef;

template <>
class JavaRef<jobject> {
public:
    JavaRef() noexcept = default;
    explicit JavaRef(jobject obj) noexcept : m_obj(obj) {}
    virtual ~JavaRef() = default;

    void ResetLocalRef(JNIEnv* env);
    jobject ReleaseLocalRef() noexcept;
    jobject SetNewLocalRef(JNIEnv* env, jobject obj);

    void ResetGlobalRef(JNIEnv* env);
    void SetNewGlobalRef(JNIEnv* env, jobject obj);

    void ResetWeakGlobalRef(JNIEnv* env);
    void SetNewWeakGlobalRef(JNIEnv* env, jobject obj);

    jobject obj() const noexcept { return m_obj; }
    bool IsNull() const noexcept { return m_obj == nullptr; }

protected:
    jobject m_obj{nullptr};
};

template <typename T>
class ScopedJavaLocalRef : public JavaRef<jobject> {
public:
    ScopedJavaLocalRef() noexcept = default;
    ScopedJavaLocalRef(JNIEnv* env, T obj) noexcept
        : JavaRef<jobject>(reinterpret_cast<jobject>(obj)), m_env(env) {}
    ~ScopedJavaLocalRef() override { ResetLocalRef(m_env); }

    ScopedJavaLocalRef(ScopedJavaLocalRef&& other) noexcept
        : JavaRef<jobject>(other.ReleaseLocalRef()), m_env(other.m_env) {}

    ScopedJavaLocalRef& operator=(ScopedJavaLocalRef&& other) noexcept {
        if (this != &other) {
            ResetLocalRef(m_env);
            m_obj = other.ReleaseLocalRef();
            m_env = other.m_env;
        }
        return *this;
    }

    T Get() const noexcept { return reinterpret_cast<T>(m_obj); }

private:
    JNIEnv* m_env{nullptr};
};

template <typename T>
class ScopedGlobalJavaRef : public JavaRef<jobject> {
public:
    ScopedGlobalJavaRef() noexcept = default;
    ScopedGlobalJavaRef(JNIEnv* env, T obj) noexcept {
        SetNewGlobalRef(env, reinterpret_cast<jobject>(obj));
    }
    ~ScopedGlobalJavaRef() override { ResetGlobalRef(nullptr); }

    T Get() const noexcept { return reinterpret_cast<T>(m_obj); }
};

// [EN] `ScopedJavaLocalFrame` (.text 0x022dd8..0x022e3c): pushes a 16-slot
//      local reference frame (`mov w1, #0x10` at `0x022dec`) and pops on destruction.
// [VN] `ScopedJavaLocalFrame` (.text 0x022dd8..0x022e3c): đẩy khung 16 tham chiếu
//      cục bộ (`mov w1, #0x10`) và giải phóng khi hủy.
class ScopedJavaLocalFrame {
public:
    explicit ScopedJavaLocalFrame(JNIEnv* env);
    ~ScopedJavaLocalFrame();

private:
    JNIEnv* m_env{nullptr};
};

// [EN] VM lifecycle & JNI reflection helpers (.text 0x022e40..0x023d70).
// [VN] Quản lý vòng đời JavaVM và hàm phản chiếu JNI (.text 0x022e40..0x023d70).
void InitVM(JavaVM* vm);
JNIEnv* AttachCurrentThread();
void DetachFromVM();

ScopedJavaLocalRef<jclass> GetClass(JNIEnv* env, const char* class_name);
ScopedGlobalJavaRef<jclass> GetGlobalClass(JNIEnv* env, const char* class_name);

jmethodID GetMethod(JNIEnv* env,
                    jclass clazz,
                    MethodType type,
                    const char* method_name,
                    const char* jni_signature);

jmethodID GetMethod(JNIEnv* env,
                    jclass clazz,
                    MethodType type,
                    const char* method_name,
                    const char* jni_signature,
                    intptr_t* cached_method_id);

bool ClearException(JNIEnv* env);
bool HasException(JNIEnv* env);
void CheckAndPrintException(JNIEnv* env);
bool CheckException(JNIEnv* env);

void GetJavaExceptionInfo(JNIEnv* env,
                          jobject throwable,
                          std::string& out_message,
                          std::string& out_stack,
                          std::string& out_cause);

std::string& GetExceptionMessage();
std::string& GetOOMMessage();

// [EN] `GetAPILevel()` @ 0x023d3c: queries `"ro.build.version.sdk"`
//      (`.rodata 0x00cdf6`) and returns SDK int or `-1` (`0x12800000` @ 0x023d6c).
// [VN] `GetAPILevel()` @ 0x023d3c: truy vấn `"ro.build.version.sdk"` và trả về
//      mức API Android hoặc `-1`.
int GetAPILevel();

// [EN] `JNIConvertHelper` (.text 0x020944..0x022dd4).
// [VN] Bộ chuyển đổi kiểu dữ liệu C++ <-> JNI (`JNIConvertHelper` @ 0x020944..0x022dd4).
class JNIConvertHelper {
public:
    static std::string ConvertToString(JNIEnv* env, jstring j_str);
    static ScopedJavaLocalRef<jstring> ConvertToJNIStringUTF(JNIEnv* env, const std::string& str);
    static ScopedJavaLocalRef<jstring> ConvertToJNIString(JNIEnv* env,
                                                          const uint16_t* utf16_chars,
                                                          size_t len);
    static ScopedJavaLocalRef<jbyteArray> ConvertToJNIByteArray(JNIEnv* env,
                                                                const std::string& bytes);
    static std::vector<uint8_t> ConvertJavaBinary(JNIEnv* env, jbyteArray j_bytes);
    static ScopedJavaLocalRef<jobjectArray> ConvertStringVectorToJavaStringArray(
        JNIEnv* env,
        const std::vector<std::string>& vec);
    static ScopedJavaLocalRef<jobjectArray> ConvertStringSetToJavaStringArray(
        JNIEnv* env,
        const std::unordered_set<std::string>& set);
    static std::vector<std::string> ConvertJavaStringArrayToStringVector(
        JNIEnv* env,
        jobjectArray j_array);
    static ScopedJavaLocalRef<jstring> U16StringToJNIString(JNIEnv* env,
                                                            const std::u16string& u16_str);
    static int LinkGlobalMethod(void* native_fn_table);
};

// [EN] Native JNI registration functions invoked from `JNI_OnLoad` (`0x01403c`):
//      - `RegisterJNI_LynxBaseTrace` @ `0x029218`: `com/lynx/base/LynxBaseTrace`
//      - `RegisterJNI_Logging` @ `0x028bf0`: `com/lynx/tasm/base/LLog`
// [VN] Các hàm đăng ký JNI native được gọi từ `JNI_OnLoad` (`0x01403c`).
bool RegisterJNI_LynxBaseTrace(JNIEnv* env);
bool RegisterJNI_Logging(JNIEnv* env);

} // namespace android

// ============================================================================
// 2. `LynxError` (.text 0x024480..0x025128) & `ErrorStorage` (.text 0x02512c..0x025210)
// ============================================================================
struct LynxError {
    LynxError(int error_code,
              std::string error_message,
              std::string fix_suggestion = "",
              LynxErrorLevel level = LynxErrorLevel::ERROR,
              bool is_logbox_only = false);

    LynxError(int error_code, const char* fmt, ...);
    ~LynxError();

    void AddCallStack(const std::string& stack);
    void AddContextInfo(const std::string& key, const std::string& value);
    bool HasValidSuggestion() const;

    // [EN] `LynxError::GetLevelString(int32_t)` @ 0x024f7c:
    //      `0 -> "fatal"`, `1 -> "error"`, `2 -> "warn"`, `>=3 -> "fatal"`.
    // [VN] `LynxError::GetLevelString(int32_t)` tại `0x024f7c`: ánh xạ mã mức độ
    //      nghiêm trọng sang chuỗi `"fatal"`, `"error"`, `"warn"`.
    static std::string GetLevelString(int32_t level);

    bool is_valid_{true};
    int error_code_{0};
    LynxErrorLevel error_level_{LynxErrorLevel::ERROR};
    std::string error_message_;
    std::string fix_suggestion_;
    bool is_logbox_only_{false};
    std::unordered_map<std::string, std::string> custom_info_;
    std::vector<std::string> call_stacks_;
};

class ErrorStorage {
public:
    static ErrorStorage& GetInstance();

    void Reset();
    bool SetError(int error_code,
                  std::string error_message,
                  std::string fix_suggestion = "",
                  LynxErrorLevel level = LynxErrorLevel::ERROR,
                  bool is_logbox_only = false);
    bool SetError(LynxError&& error);

    const std::unique_ptr<LynxError>& GetError() const noexcept { return m_error; }

private:
    ErrorStorage() = default;
    std::unique_ptr<LynxError> m_error;
};

// ============================================================================
// 3. `lynx::base::logging` (.text 0x02597c..0x027e6c)
// ============================================================================
namespace logging {

enum LogSeverity : int32_t {
    LOG_VERBOSE = -1,
    LOG_INFO = 0,
    LOG_WARNING = 1,
    LOG_ERROR = 2,
    LOG_REPORT = 3,
    LOG_FATAL = 4,
};

enum LogChannel : int32_t {
    LOG_CHANNEL_LYNX_EXTERNAL = 0,
    LOG_CHANNEL_LYNX_INTERNAL = 1,
};

class LogMessage;
using LogCallBack = void (*)(int level, const char* tag, const char* msg);
using LogDelegate = void (*)(LogMessage* msg);

void InitLynxLogging(LogCallBack callback,
                     LogChannel channel,
                     bool is_all_level,
                     bool enable_platform_output);
void SetMinLogLevel(int level);
int GetMinLogLevel();
void SetLogChannel(LogChannel channel);
LogChannel GetLogChannel();
void SetLynxLogCallback(LogCallBack callback);
void AddLoggingDelegate(LogDelegate delegate);
void EnableLogOutputByPlatform();
void DisablePlatformLogOutput();
void PrintLogMessageByLogDelegate(LogMessage* msg);

class LogStream {
public:
    LogStream();
    explicit LogStream(const std::string& initial);
    ~LogStream();

    std::string str() const { return m_stream.str(); }
    void Clear() { m_stream.str(""); m_stream.clear(); }

    LogStream& operator<<(bool v);
    LogStream& operator<<(char v);
    LogStream& operator<<(int16_t v);
    LogStream& operator<<(uint16_t v);
    LogStream& operator<<(int32_t v);
    LogStream& operator<<(uint32_t v);
    LogStream& operator<<(int64_t v);
    LogStream& operator<<(uint64_t v);
    LogStream& operator<<(float v);
    LogStream& operator<<(double v);
    LogStream& operator<<(const char* v);
    LogStream& operator<<(const std::string& v);
    LogStream& operator<<(std::string_view v);
    LogStream& operator<<(const void* v);

private:
    std::ostringstream m_stream;
};

class LogMessage {
public:
    LogMessage(const char* file,
               int line,
               int severity,
               int runtime_id = -1,
               LogChannel channel = LOG_CHANNEL_LYNX_INTERNAL);
    ~LogMessage();

    LogStream& stream() noexcept { return m_stream; }
    int severity() const noexcept { return m_severity; }
    int line() const noexcept { return m_line; }
    const char* file() const noexcept { return m_file; }
    size_t message_start() const noexcept { return m_messageStart; }
    int runtime_id() const noexcept { return m_runtimeId; }
    LogChannel channel_type() const noexcept { return m_channel; }

private:
    void Init(const char* file, int line);

    const char* m_file{nullptr};
    int m_line{0};
    int m_severity{LOG_INFO};
    int m_runtimeId{-1};
    LogChannel m_channel{LOG_CHANNEL_LYNX_INTERNAL};
    size_t m_messageStart{0};
    LogStream m_stream;
};

} // namespace logging

// ============================================================================
// 4. `lynx::base::trace::SetTraceBackend` (.text 0x02d660..0x02d680)
// ============================================================================
namespace trace {

using TraceBackendFn = void (*)(const char* category,
                                const char* name,
                                BaseTraceEventType phase);

void SetTraceBackend(TraceBackendFn backend_fn);
TraceBackendFn GetTraceBackend() noexcept;

} // namespace trace

} // namespace base
} // namespace lynx

// [EN] Exported C ABI entry point `JNI_OnLoad` (.text 0x01403c..0x01406c).
// [VN] Điểm vào C ABI xuất khẩu `JNI_OnLoad` (.text 0x01403c..0x01406c).
extern "C" jint JNI_OnLoad(JavaVM* vm, void* reserved);

#endif // LYNXBASE_JNI_LOG_ERROR_H_
