/**
 * @file pitayabdcomponent_alog_jni.h
 * @brief JNI Bridges (NpthStackReporter & ALogPrinter) and Dynamic Loader Fallback in libPitayaBdComponent.so (Target 46).
 *        Cầu nối JNI (NpthStackReporter & ALogPrinter) và Trình nạp động dự phòng trong libPitayaBdComponent.so (Mục tiêu 46).
 *
 * Binary Ground Truth / Thực tế Nhị phân:
 * - 0x00264c (296 B): JStringToStdString(JNIEnv*, jstring) (calls GetStringUTFChars @ vtable +0x548, ReleaseStringUTFChars @ +0x550)
 * - 0x002780 (132 B): Java_com_bytedance_pitaya_bdcomponentimpl_crash_NpthStackReporter_nativeGenerateAllStack
 * - 0x004c54 (340 B): Java_com_bytedance_pitaya_bdcomponentimpl_monitor_ALogPrinter_nativeGetFuncAddr
 *   - Primary path: dlopen("libalog.so", 0x102) -> dlsym(handle, "alog_write") -> logs "dl success!" (0x0124b8)
 *   - Fallback path: npth_dlopen("libalog.so") -> npth_dlsym(handle, "alog_write") -> logs "npth_dl success!" (0x0124b3)
 */

#ifndef NEXTAI_OPENCUT_PITAYABDCOMPONENT_ALOG_JNI_H_
#define NEXTAI_OPENCUT_PITAYABDCOMPONENT_ALOG_JNI_H_

#include "pitayabdcomponent_types.h"

#include <cstdint>
#include <string>
#include <vector>

// Minimal standalone JNI types when <jni.h> is not included in host test builds
// Kiểu dữ liệu JNI tối thiểu độc lập khi không nạp <jni.h> trên máy chủ kiểm thử
#ifndef JNIEXPORT
#define JNIEXPORT
#define JNICALL
typedef void* jobject;
typedef void* jstring;
typedef int64_t jlong;

struct JNINativeInterface_PitayaStub {
    void* reserved[169];  // 169 * 8 = 0x548 bytes
    const char* (*GetStringUTFChars)(void* env, jstring str, uint8_t* isCopy);      // +0x548
    void (*ReleaseStringUTFChars)(void* env, jstring str, const char* utf);         // +0x550
};

struct JNIEnv_PitayaStub {
    const JNINativeInterface_PitayaStub* functions;
};
typedef JNIEnv_PitayaStub JNIEnv;
#endif

// External C hooks imported from libnpth_dl.so / libdl.so (PLT 0x002440..0x0025a0)
// Các hàm C ngoại vi được nhập từ libnpth_dl.so / libdl.so (PLT 0x002440..0x0025a0)
extern "C" {
void* npth_dlopen(const char* filename);
void* npth_dlsym(void* handle, const char* symbol);
const char* npth_dlerror(void);

JNIEXPORT void JNICALL
Java_com_bytedance_pitaya_bdcomponentimpl_crash_NpthStackReporter_nativeGenerateAllStack(
    JNIEnv* env,
    jobject thiz,
    jstring dir_path);

JNIEXPORT jlong JNICALL
Java_com_bytedance_pitaya_bdcomponentimpl_monitor_ALogPrinter_nativeGetFuncAddr(
    JNIEnv* env,
    jobject thiz);
}

namespace pitaya {
namespace bdcomponent {

/**
 * Loader mode for deterministic testing of ALogPrinter_nativeGetFuncAddr (0x004c54).
 * Chế độ nạp động để kiểm thử tất định hàm ALogPrinter_nativeGetFuncAddr (0x004c54).
 */
enum class ALogLoaderSimMode : int {
    kPrimaryDlopenSuccess   = 0,  // dlopen("libalog.so", 0x102) + dlsym("alog_write") succeeds
    kPrimaryDlsymFail       = 1,  // dlopen succeeds, dlsym fails -> returns 0
    kFallbackNpthSuccess    = 2,  // dlopen fails -> npth_dlopen("libalog.so") + npth_dlsym("alog_write") succeeds
    kFallbackNpthDlopenFail = 3,  // Both dlopen and npth_dlopen fail -> returns 0
    kFallbackNpthDlsymFail  = 4   // dlopen fails, npth_dlopen succeeds, npth_dlsym fails -> returns 0
};

class ALogDynamicBridge {
public:
    /**
     * Converts a JNI jstring into std::string using JNIEnv vtable offsets +0x548 / +0x550.
     * Chuyển đổi jstring JNI sang std::string bằng độ lệch vtable JNIEnv +0x548 / +0x550.
     * Disassembly @ 0x00264c..0x00277c (296 bytes).
     */
    static std::string JStringToStdString(JNIEnv* env, jstring jstr);

    /**
     * Resolves "alog_write" from "libalog.so" using the exact two-tier dlopen -> npth_dlopen
     * state machine at 0x004c54..0x004da4 (340 bytes).
     * Phân giải "alog_write" từ "libalog.so" theo đúng máy trạng thái 2 tầng dlopen -> npth_dlopen
     * tại 0x004c54..0x004da4 (340 byte).
     */
    static jlong ResolveALogWriteFuncAddr();

    /**
     * Default simulated `alog_write` target function whose address is returned when resolved.
     * Hàm đích `alog_write` mô phỏng mặc định mà địa chỉ sẽ được trả về khi phân giải thành công.
     */
    static void SimulatedALogWrite(int level, const char* tag, const char* msg);

    static void SetSimulationMode(ALogLoaderSimMode mode);
    static ALogLoaderSimMode GetSimulationMode();
    static std::vector<std::string> GetDiagnosticLogs();
    static void ClearDiagnosticLogs();
};

}  // namespace bdcomponent
}  // namespace pitaya

#endif  // NEXTAI_OPENCUT_PITAYABDCOMPONENT_ALOG_JNI_H_
