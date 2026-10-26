/**
 * @file pitayabdcomponent_alog_jni.cpp
 * @brief Implementation of JNI Bridges (NpthStackReporter & ALogPrinter) and Dynamic Loader Fallback (Target 46).
 *        Triển khai cầu nối JNI (NpthStackReporter & ALogPrinter) và Trình nạp động dự phòng (Mục tiêu 46).
 *
 * Disassembly Reference / Tham chiếu Hợp ngữ AArch64:
 * - JStringToStdString(JNIEnv*, jstring)                @ 0x00264c..0x00277c (296 bytes)
 * - NpthStackReporter_nativeGenerateAllStack            @ 0x002780..0x002800 (132 bytes)
 * - ALogPrinter_nativeGetFuncAddr                       @ 0x004c54..0x004da4 (340 bytes)
 */

#include "pitayabdcomponent_alog_jni.h"
#include "pitayabdcomponent_npth_tombstone.h"

#include <cstdarg>
#include <cstdio>
#include <cstring>
#include <mutex>

namespace {

std::mutex g_alog_mutex;
pitaya::bdcomponent::ALogLoaderSimMode g_sim_mode =
    pitaya::bdcomponent::ALogLoaderSimMode::kPrimaryDlopenSuccess;
std::vector<std::string> g_diag_logs;
const char* g_last_dl_error = nullptr;
const char* g_last_npth_dl_error = nullptr;

/**
 * Formats and records __android_log_print(ANDROID_LOG_DEBUG=3, "PTY-", fmt, ...) messages.
 * Định dạng và ghi nhận các thông điệp __android_log_print(ANDROID_LOG_DEBUG=3, "PTY-", fmt, ...).
 * Disassembly call sites @ 0x004cc4, 0x004d00, 0x004d5c, 0x004d94 (bl #0x2450 PLT __android_log_print).
 */
void LogAndroidPrint(int prio, const char* tag, const char* fmt, ...) {
    char msg_buf[512];
    va_list args;
    va_start(args, fmt);
    std::vsnprintf(msg_buf, sizeof(msg_buf), fmt, args);
    va_end(args);

    char full_buf[600];
    std::snprintf(full_buf, sizeof(full_buf), "[prio=%d][%s] %s",
                  prio, tag != nullptr ? tag : "", msg_buf);
    g_diag_logs.emplace_back(full_buf);
}

void* SimulatedDlopen(const char* filename, int flags) {
    if (filename == nullptr || std::strcmp(filename, pitaya::bdcomponent::RodataStrings::kLibALogSo) != 0 ||
        flags != pitaya::bdcomponent::BinaryConstants::kDlopenFlags) {
        g_last_dl_error = "invalid library name or flags";
        return nullptr;
    }
    if (g_sim_mode == pitaya::bdcomponent::ALogLoaderSimMode::kPrimaryDlopenSuccess ||
        g_sim_mode == pitaya::bdcomponent::ALogLoaderSimMode::kPrimaryDlsymFail) {
        g_last_dl_error = nullptr;
        return reinterpret_cast<void*>(0x7f00a100ULL);
    }
    g_last_dl_error = nullptr;  // Triggers csel "unknow error" (@ 0x01243b) when dlerror() == nullptr
    return nullptr;
}

void* SimulatedDlsym(void* handle, const char* symbol) {
    if (handle == nullptr || symbol == nullptr ||
        std::strcmp(symbol, pitaya::bdcomponent::RodataStrings::kALogWriteSym) != 0) {
        return nullptr;
    }
    if (g_sim_mode == pitaya::bdcomponent::ALogLoaderSimMode::kPrimaryDlopenSuccess) {
        g_last_dl_error = nullptr;
        return reinterpret_cast<void*>(&pitaya::bdcomponent::ALogDynamicBridge::SimulatedALogWrite);
    }
    g_last_dl_error = nullptr;
    return nullptr;
}

const char* SimulatedDlerror() {
    return g_last_dl_error;
}

}  // namespace

// ============================================================================
// External C NPTH Dynamic Loader Hooks (PLT 0x002440, 0x002540, 0x0025a0)
// Các hàm nạp động C NPTH ngoại vi (PLT 0x002440, 0x002540, 0x0025a0)
// ============================================================================
extern "C" {

void* npth_dlopen(const char* filename) {
    if (filename == nullptr ||
        std::strcmp(filename, pitaya::bdcomponent::RodataStrings::kLibALogSo) != 0) {
        g_last_npth_dl_error = "invalid npth library";
        return nullptr;
    }
    if (g_sim_mode == pitaya::bdcomponent::ALogLoaderSimMode::kFallbackNpthSuccess ||
        g_sim_mode == pitaya::bdcomponent::ALogLoaderSimMode::kFallbackNpthDlsymFail) {
        g_last_npth_dl_error = nullptr;
        return reinterpret_cast<void*>(0x7f00b200ULL);
    }
    g_last_npth_dl_error = nullptr;
    return nullptr;
}

void* npth_dlsym(void* handle, const char* symbol) {
    if (handle == nullptr || symbol == nullptr ||
        std::strcmp(symbol, pitaya::bdcomponent::RodataStrings::kALogWriteSym) != 0) {
        return nullptr;
    }
    if (g_sim_mode == pitaya::bdcomponent::ALogLoaderSimMode::kFallbackNpthSuccess) {
        g_last_npth_dl_error = nullptr;
        return reinterpret_cast<void*>(&pitaya::bdcomponent::ALogDynamicBridge::SimulatedALogWrite);
    }
    g_last_npth_dl_error = nullptr;
    return nullptr;
}

const char* npth_dlerror(void) {
    return g_last_npth_dl_error;
}

// ============================================================================
// 1. Exported JNI Function: NpthStackReporter_nativeGenerateAllStack (@ 0x002780)
//    Hàm JNI xuất khẩu: NpthStackReporter_nativeGenerateAllStack (@ 0x002780)
// ============================================================================
JNIEXPORT void JNICALL
Java_com_bytedance_pitaya_bdcomponentimpl_crash_NpthStackReporter_nativeGenerateAllStack(
    JNIEnv* env,
    jobject /*thiz*/,
    jstring dir_path) {
    // Disassembly @ 0x002780..0x002800 (132 bytes):
    //   0x0027a8: 94000017  bl   #0x2804   ; pitaya::PitayaNpthUtil::Instance()
    //   0x0027ac: f9400015  ldr  x21, [x0] ; x21 = shared_ptr.get()
    //   0x0027bc: 97ffffa4  bl   #0x264c   ; JStringToStdString(env, dir_path)
    //   0x0027c8: 94000034  bl   #0x2898   ; PitayaNpthUtil::GenerteTombstone(std::string)
    auto& instance_ptr = pitaya::PitayaNpthUtil::Instance();
    if (!instance_ptr) {
        return;
    }
    std::string converted_dir = pitaya::bdcomponent::ALogDynamicBridge::JStringToStdString(env, dir_path);
    instance_ptr->GenerteTombstone(std::move(converted_dir));
}

// ============================================================================
// 2. Exported JNI Function: ALogPrinter_nativeGetFuncAddr (@ 0x004c54)
//    Hàm JNI xuất khẩu: ALogPrinter_nativeGetFuncAddr (@ 0x004c54)
// ============================================================================
JNIEXPORT jlong JNICALL
Java_com_bytedance_pitaya_bdcomponentimpl_monitor_ALogPrinter_nativeGetFuncAddr(
    JNIEnv* /*env*/,
    jobject /*thiz*/) {
    // Disassembly @ 0x004c54..0x004da4 (340 bytes):
    return pitaya::bdcomponent::ALogDynamicBridge::ResolveALogWriteFuncAddr();
}

}  // extern "C"

namespace pitaya {
namespace bdcomponent {

// ============================================================================
// 3. JStringToStdString (@ 0x00264c..0x00277c, 296 bytes)
//    Chuyển đổi jstring sang std::string (@ 0x00264c..0x00277c, 296 byte)
// ============================================================================
std::string ALogDynamicBridge::JStringToStdString(JNIEnv* env, jstring jstr) {
    // Disassembly @ 0x002678..0x00275c:
    //   0x002678: b40002e1  cbz  x1, #0x26d4        ; if (jstr == nullptr) return ""
    //   0x002680: f9400008  ldr  x8, [x0]           ; JNIEnv vtable
    //   0x002690: f942a508  ldr  x8, [x8, #0x548]   ; GetStringUTFChars
    //   0x002694: d63f0100  blr  x8
    //   0x002734: f942a908  ldr  x8, [x8, #0x550]   ; ReleaseStringUTFChars
    //   0x002738: d63f0100  blr  x8
    if (jstr == nullptr) {
        return std::string();
    }
    if (env != nullptr && env->functions != nullptr &&
        env->functions->GetStringUTFChars != nullptr) {
        uint8_t is_copy = 0;
        const char* utf_chars = env->functions->GetStringUTFChars(env, jstr, &is_copy);
        if (utf_chars == nullptr) {
            return std::string();
        }
        std::string result(utf_chars);
        if (env->functions->ReleaseStringUTFChars != nullptr) {
            env->functions->ReleaseStringUTFChars(env, jstr, utf_chars);
        }
        return result;
    }
    // Host test fallback when jstring is passed directly as a const char* pointer
    // Cơ chế dự phòng trên máy chủ kiểm thử khi jstring được truyền trực tiếp dưới dạng con trỏ const char*
    return std::string(reinterpret_cast<const char*>(jstr));
}

// ============================================================================
// 4. ResolveALogWriteFuncAddr (@ 0x004c54..0x004da4, 340 bytes)
//    Phân giải địa chỉ hàm alog_write (@ 0x004c54..0x004da4, 340 byte)
// ============================================================================
jlong ALogDynamicBridge::ResolveALogWriteFuncAddr() {
    std::lock_guard<std::mutex> lock(g_alog_mutex);

    // Step 1: Primary dlopen("libalog.so", 0x102) @ 0x004c60..0x004c70:
    //   0x004c60: d0000060  adrp x0, #0x12000
    //   0x004c64: 9110ac00  add  x0, x0, #0x42b ("libalog.so" @ 0x01242b)
    //   0x004c68: 52802041  mov  w1, #0x102     (RTLD_NOW | RTLD_GLOBAL)
    //   0x004c6c: 97fff60d  bl   #0x24a0        (dlopen)
    //   0x004c70: b4000160  cbz  x0, #0x4c9c
    void* handle = SimulatedDlopen(RodataStrings::kLibALogSo, BinaryConstants::kDlopenFlags);
    if (handle != nullptr) {
        // Step 1a: Primary dlsym(handle, "alog_write") @ 0x004c74..0x004c98:
        //   0x004c74: d0000061  adrp x1, #0x12000
        //   0x004c78: 91112021  add  x1, x1, #0x448 ("alog_write" @ 0x012448)
        //   0x004c7c: 97fff5f9  bl   #0x2460        (dlsym)
        //   0x004c84: b4000480  cbz  x0, #0x4d14
        void* sym = SimulatedDlsym(handle, RodataStrings::kALogWriteSym);
        if (sym != nullptr) {
            // Disassembly @ 0x004c88..0x004d04:
            //   x1 = "PTY-" (0x012436), x2 = "dl success!" (0x0124b8 = 0x0124b3 + 5)
            //   mov w0, #3; bl __android_log_print
            LogAndroidPrint(BinaryConstants::kAndroidLogDebug,
                            RodataStrings::kLogTag, "%s", RodataStrings::kDlSuccess);
            return static_cast<jlong>(reinterpret_cast<uintptr_t>(sym));
        }

        // Disassembly @ 0x004d14..0x004da4:
        //   Calls dlerror() (#0x2480); if nullptr, selects "unknow error" (@ 0x01243b).
        //   Logs "dlsym(handle, \"alog_write\"); error, msg is :%s" (@ 0x012484 = 0x01247f + 5) and returns 0.
        const char* err = SimulatedDlerror();
        const char* safe_err = (err != nullptr) ? err : RodataStrings::kUnknownError;
        LogAndroidPrint(BinaryConstants::kAndroidLogDebug,
                        RodataStrings::kLogTag, RodataStrings::kDlsymErrFmt, safe_err);
        return 0;
    }

    // Step 2: Primary dlopen failed (@ 0x004c9c..0x004cc4):
    //   Calls dlerror() (#0x2480); if nullptr, selects "unknow error" (@ 0x01243b).
    //   Logs "dlopen(\"libalog.so\") error, msg is :%s" (@ 0x012458 = 0x012453 + 5).
    {
        const char* err = SimulatedDlerror();
        const char* safe_err = (err != nullptr) ? err : RodataStrings::kUnknownError;
        LogAndroidPrint(BinaryConstants::kAndroidLogDebug,
                        RodataStrings::kLogTag, RodataStrings::kDlopenErrFmt, safe_err);
    }

    // Step 3: Fallback npth_dlopen("libalog.so") @ 0x004cc8..0x004cd4:
    //   0x004cc8: d0000060  adrp x0, #0x12000
    //   0x004ccc: 9110ac00  add  x0, x0, #0x42b ("libalog.so" @ 0x01242b)
    //   0x004cd0: 97fff5dc  bl   #0x2440        (npth_dlopen)
    //   0x004cd4: b4000340  cbz  x0, #0x4d3c
    void* npth_handle = npth_dlopen(RodataStrings::kLibALogSo);
    if (npth_handle != nullptr) {
        // Step 3a: Fallback npth_dlsym(npth_handle, "alog_write") @ 0x004cd8..0x004ce8:
        //   0x004cd8: d0000061  adrp x1, #0x12000
        //   0x004cdc: 91112021  add  x1, x1, #0x448 ("alog_write" @ 0x012448)
        //   0x004ce0: 97fff618  bl   #0x2540        (npth_dlsym)
        //   0x004ce8: b4000460  cbz  x0, #0x4d74
        void* npth_sym = npth_dlsym(npth_handle, RodataStrings::kALogWriteSym);
        if (npth_sym != nullptr) {
            // Disassembly @ 0x004cec..0x004d10:
            //   x1 = "PTY-" (0x012436), x2 = "npth_dl success!" (0x0124b3)
            //   mov w0, #3; bl __android_log_print
            LogAndroidPrint(BinaryConstants::kAndroidLogDebug,
                            RodataStrings::kLogTag, "%s", RodataStrings::kNpthDlSuccess);
            return static_cast<jlong>(reinterpret_cast<uintptr_t>(npth_sym));
        }

        // Disassembly @ 0x004d74..0x004da4:
        //   Calls npth_dlerror() (#0x25a0); if nullptr, selects "unknow error" (@ 0x01243b).
        //   Logs "npth_dlsym(handle, \"alog_write\"); error, msg is :%s" (@ 0x01247f) and returns 0.
        const char* err = npth_dlerror();
        const char* safe_err = (err != nullptr) ? err : RodataStrings::kUnknownError;
        LogAndroidPrint(BinaryConstants::kAndroidLogDebug,
                        RodataStrings::kLogTag, RodataStrings::kNpthDlsymErrFmt, safe_err);
        return 0;
    }

    // Step 4: Fallback npth_dlopen failed (@ 0x004d3c..0x004d70):
    //   Calls npth_dlerror() (#0x25a0); if nullptr, selects "unknow error" (@ 0x01243b).
    //   Logs "npth_dlopen(\"libalog.so\") error, msg is :%s" (@ 0x012453) and returns 0.
    {
        const char* err = npth_dlerror();
        const char* safe_err = (err != nullptr) ? err : RodataStrings::kUnknownError;
        LogAndroidPrint(BinaryConstants::kAndroidLogDebug,
                        RodataStrings::kLogTag, RodataStrings::kNpthDlopenErrFmt, safe_err);
    }
    return 0;
}

void ALogDynamicBridge::SimulatedALogWrite(int level, const char* tag, const char* msg) {
    std::lock_guard<std::mutex> lock(g_alog_mutex);
    LogAndroidPrint(level, tag != nullptr ? tag : RodataStrings::kLogTag,
                    "%s", msg != nullptr ? msg : "");
}

void ALogDynamicBridge::SetSimulationMode(ALogLoaderSimMode mode) {
    std::lock_guard<std::mutex> lock(g_alog_mutex);
    g_sim_mode = mode;
}

ALogLoaderSimMode ALogDynamicBridge::GetSimulationMode() {
    std::lock_guard<std::mutex> lock(g_alog_mutex);
    return g_sim_mode;
}

std::vector<std::string> ALogDynamicBridge::GetDiagnosticLogs() {
    std::lock_guard<std::mutex> lock(g_alog_mutex);
    return g_diag_logs;
}

void ALogDynamicBridge::ClearDiagnosticLogs() {
    std::lock_guard<std::mutex> lock(g_alog_mutex);
    g_diag_logs.clear();
}

}  // namespace bdcomponent
}  // namespace pitaya
