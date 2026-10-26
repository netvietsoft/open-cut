/**
 * @file iesapplogger_reporter_jni.h
 * @brief AppLogReporter Singleton & JNI Bridge Declarations for libiesapplogger.so
 *        Khai báo Singleton AppLogReporter & Cầu nối JNI cho libiesapplogger.so
 *
 * Reconstructed from .text addresses 0x003eac..0x004a18, 0x004c70..0x005378.
 * Tái dựng từ các địa chỉ .text 0x003eac..0x004a18, 0x004c70..0x005378.
 */

#ifndef NEXTAI_OPENCUT_IESAPPLOGGER_REPORTER_JNI_H_
#define NEXTAI_OPENCUT_IESAPPLOGGER_REPORTER_JNI_H_

#include "iesapplogger_rbtree_stl.h"
#include "iesapplogger_types.h"
#include <cstdint>
#include <mutex>
#include <set>
#include <string>

namespace iesapplogger {

// ============================================================================
// 1. Minimal Standalone JNI VTable Structures for Host/Target Parity
//    Cấu trúc Bảng phương thức ảo JNI Tối giản để Kiểm thử Độc lập
// ============================================================================
struct MockJavaVM;
struct MockJNIEnv;
using jint = int32_t;
using jboolean = uint8_t;
using jsize = int32_t;
using jobject = void*;
using jclass = void*;
using jstring = void*;
using jbyteArray = void*;
using jmethodID = void*;

static constexpr jint kJniVersion1_6 = 0x00010006;
static constexpr jint kJniOk         = 0;
static constexpr jint kJniErr        = -1;

// ============================================================================
// 2. AppLogReporter Singleton Class (0x0043c0..0x0046e4) (OBSERVED)
//    Lớp Singleton AppLogReporter (0x0043c0..0x0046e4) (QUAN SÁT TRỰC TIẾP)
// ============================================================================

/**
 * @brief Reconstructs `AppLogReporter` exported in .dynsym [065, 090, 116, 122]
 *        and internal `setSampler` @ 0x0045d0.
 *        Tái dựng lớp `AppLogReporter` được xuất trong .dynsym [065, 090, 116, 122]
 *        và phương thức nội bộ `setSampler` @ 0x0045d0.
 */
class AppLogReporter {
public:
    /**
     * @brief Exact reconstruction of `_ZN14AppLogReporter12GetSingletonEv`
     *        at 0x0043c0..0x00443c (.dynsym [090]).
     *        Uses `std::call_once` (`0x014020`) to allocate the 80-byte (`0x50`) singleton
     *        at `0x014018` via init helper `0x004cf0`.
     *        Tái dựng chính xác `AppLogReporter::GetSingleton()` tại 0x0043c0..0x00443c (.dynsym [090]).
     */
    static AppLogReporter* GetSingleton();

    /**
     * @brief Exact reconstruction of `_ZN14AppLogReporter6reportEPKcS1_S1_b`
     *        at 0x004440..0x004534 (.dynsym [065]).
     *        Checks `enabled_` (+0x30) and optional `sampler_set_` (+0x38..+0x4F),
     *        acquires `mutex_` (+0x00..+0x27), and calls `report_func_` (+0x28).
     *        Tái dựng chính xác `AppLogReporter::report(...)` tại 0x004440..0x004534 (.dynsym [065]).
     */
    int report(const char* app_id,
               const char* event_name,
               const char* params_json,
               bool report_to_business);

    /**
     * @brief Exact reconstruction of `_ZN14AppLogReporter9isSampledERKNSt6__ndk112basic_stringIcNS0_11char_traitsIcEENS0_9allocatorIcEEEE`
     *        at 0x004538..0x0045c4 (.dynsym [122]).
     *        Returns true if `enabled_` (+0x30) is true AND (`sampler_set_` is empty OR contains `event_name`).
     *        Tái dựng chính xác `AppLogReporter::isSampled(const std::string&)` tại 0x004538..0x0045c4 (.dynsym [122]).
     */
    bool isSampled(const std::string& event_name);

    /**
     * @brief Exact reconstruction of `_ZN14AppLogReporter13setReportFuncEPFiPKcS1_S1_bE`
     *        at 0x0045c8..0x0045cc (.dynsym [116]): `str x1, [x0, #0x28]; ret`.
     *        Tái dựng chính xác `AppLogReporter::setReportFunc(...)` tại 0x0045c8..0x0045cc (.dynsym [116]).
     */
    void setReportFunc(AppLogReportCallback func) noexcept;

    /**
     * @brief Exact reconstruction of internal `AppLogReporter::setSampler(const RbTreeSetHeaderAbi&)`
     *        at 0x0045d0..0x0046e4.
     *        Locks `mutex_`, copies the RB-tree into `sampler_set_` (+0x38), and unlocks `mutex_`.
     *        Tái dựng chính xác hàm `setSampler` tại 0x0045d0..0x0046e4.
     */
    void setSamplerAbi(const RbTreeSetHeaderAbi& new_sampler);

    /**
     * @brief High-level C++ helper to set the sampler whitelist from `std::set<std::string>`.
     *        Hàm trợ giúp C++ mức cao để thiết lập danh sách lấy mẫu từ `std::set<std::string>`.
     */
    void setSampler(const std::set<std::string>& events);

    /**
     * @brief Enables or disables all reports (`strb w8, [x0, #0x30]` @ 0x00839c / 0x0083b4).
     *        Bật hoặc tắt toàn bộ báo cáo (`strb w8, [x0, #0x30]` @ 0x00839c / 0x0083b4).
     */
    void setEnabled(bool enabled) noexcept;
    bool isEnabled() const noexcept;

    /**
     * @brief Returns underlying 80-byte ABI layout (`AppLogReporterAbi*`).
     *        Trả về con trỏ cấu trúc ABI 80 byte (`AppLogReporterAbi*`).
     */
    AppLogReporterAbi* rawAbi() noexcept { return &abi_; }
    const AppLogReporterAbi* rawAbi() const noexcept { return &abi_; }

private:
    AppLogReporter();
    ~AppLogReporter();

    AppLogReporterAbi abi_;
    std::mutex        host_mutex_;
};

// ============================================================================
// 3. Exported C / JNI Functions (.dynsym [053, 099, 102, 112])
//    Các hàm C / JNI được xuất (.dynsym [053, 099, 102, 112])
// ============================================================================

/**
 * @brief Global JavaVM pointer exported at .dynsym [053] (`0x014010`).
 *        Con trỏ toàn cục JavaVM được xuất tại .dynsym [053] (`0x014010`).
 */
extern MockJavaVM* gJvm;

/**
 * @brief Exact reconstruction of `_Z6getEnvPi` at 0x003eac..0x003f5c (.dynsym [112]).
 *        Calls `gJvm->GetEnv(&env, 0x00010006)`:
 *          - If `JNI_OK (0)`, sets `*attached = 1`.
 *          - Otherwise calls `gJvm->AttachCurrentThread(&env, nullptr)` and sets `*attached = 0`.
 *        Tái dựng chính xác `_Z6getEnvPi` tại 0x003eac..0x003f5c (.dynsym [112]).
 */
MockJNIEnv* getEnv(int* attached) noexcept;

/**
 * @brief Exact reconstruction of `JNI_OnLoad` at 0x003f60..0x004128 (.dynsym [109]).
 *        Stores `vm` in `gJvm` (`0x014010`), attaches thread with RAII `shared_ptr` guard (`$_0`),
 *        initializes JNI IDs (`0x00412c`), and returns `0x00010006` (or `-1` on failure).
 *        Tái dựng chính xác `JNI_OnLoad` tại 0x003f60..0x004128 (.dynsym [109]).
 */
jint JNI_OnLoad_Reconstructed(MockJavaVM* vm, void* reserved);

/**
 * @brief Exact reconstruction of `Java_com_bytedance_ies_common_IESAppLogger_nativeSetSampler`
 *        at 0x0046e8..0x004a18 (.dynsym [099]).
 *        Iterates Java `Set<String>` via `iterator()`, `hasNext()`, `next()`, inserts each string
 *        into a temporary 24-byte `RbTreeSetHeaderAbi`, and calls `AppLogReporter::GetSingleton()->setSampler(...)`.
 *        Tái dựng chính xác `Java_com_bytedance_ies_common_IESAppLogger_nativeSetSampler` tại 0x0046e8..0x004a18 (.dynsym [099]).
 */
void Java_com_bytedance_ies_common_IESAppLogger_nativeSetSampler_Reconstructed(
    MockJNIEnv* env,
    jobject thiz,
    const std::vector<std::string>& java_sampler_set);

/**
 * @brief Default report callback `appLogFunc` at 0x004d3c..0x00510c.
 *        Converts `app_id`, `event_name`, `params_json` via `charPtrToJString` (`0x005110`)
 *        and invokes `IESAppLogger.sharedInstance().appLogOnEvent(...)`.
 *        Hàm callback mặc định `appLogFunc` tại 0x004d3c..0x00510c.
 */
int appLogFunc(const char* app_id,
               const char* event_name,
               const char* params_json,
               bool report_to_business);

}  // namespace iesapplogger

#endif  // NEXTAI_OPENCUT_IESAPPLOGGER_REPORTER_JNI_H_
