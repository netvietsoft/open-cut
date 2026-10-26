/**
 * @file bach_resource_finder_jni.h
 * @brief DownloadableResourceFinder, EPResourceFinder, ModelDownloadListener, JNI_OnLoad, and UTF-8 String Helpers
 *        for libbach-sdk-jni.so.
 *        Trình tìm tài nguyên DownloadableResourceFinder, EPResourceFinder, ModelDownloadListener, JNI_OnLoad
 *        và các hàm chuyển đổi chuỗi UTF-8 cho libbach-sdk-jni.so.
 *
 * Target Binary / Nhị phân mục tiêu:
 *   - File: libbach-sdk-jni.so (117,112 bytes)
 *   - SHA-256: 6330cb09b6721ef41639c6ed472b4d60e3b81a9f03c699f5d8c1cbefe5804929
 *   - Disassembly Ranges Covered / Dải mã máy bao phủ:
 *     * 0x00edd0..0x00f18b: `Java_com_bytedance_byted_1bach_1sdk_finder_DownloadableResourceFinder_nativeCreate`
 *     * 0x00f224..0x00f22b: `Java_com_bytedance_byted_1bach_1sdk_finder_DownloadableResourceFinder_nativeDestroy`
 *                           & `Java_com_bytedance_byted_1bach_1sdk_finder_EPResourceFinder_nativeDestroy` (alias)
 *     * 0x00f22c..0x00f55b: `Java_com_bytedance_byted_1bach_1sdk_finder_DownloadableResourceFinder_nativeDownloadModels`
 *     * 0x00f55c..0x00f61b: `Java_com_bytedance_byted_1bach_1sdk_finder_ModelDownloadListener_deleteNativeObject`
 *     * 0x00f61c..0x00f6ab: `Java_com_bytedance_byted_1bach_1sdk_finder_EPResourceFinder_nativeCreate`
 *     * 0x00f6ac..0x00f884: `NativeListener::onSuccess()`, `NativeListener::onFail(int, const std::string&)`, `~NativeListener()`
 *     * 0x0102b0..0x010334: `JNI_OnLoad` (`JNI_VERSION_1_6 = 0x00010006`, `.bss 0x0202b0..0x0202bf`)
 *     * 0x010338..0x010504: `stdStringToJString` & `jstringToStdString` (`getBytes("utf-8")`)
 */

#ifndef NEXTAI_OPENCUT_BACH_RESOURCE_FINDER_JNI_H_
#define NEXTAI_OPENCUT_BACH_RESOURCE_FINDER_JNI_H_

#include "bach_sdk_jni_types.h"

#include <cstdint>
#include <functional>
#include <string>
#include <unordered_map>
#include <vector>

namespace com {
namespace bytedance {
namespace bach_sdk {

namespace Bach {

// ============================================================================
// 1. DownloadableResourceFinderConfig & ModelDownloadListener Types
//    Cấu hình DownloadableResourceFinderConfig & Giao diện ModelDownloadListener [OBSERVED]
// ============================================================================

/**
 * @brief 152-byte (`0x98`) configuration struct populated on stack (`sp+0x48..sp+0xdf`) in
 *        `DownloadableResourceFinder_nativeCreate` (`0x00edd0..0x00f158`) and passed to
 *        `Bach::DownloadableResourceFinder::create(const DownloadableResourceFinderConfig&)` [OBSERVED].
 *        Cấu trúc cấu hình 152 byte (`0x98`) truyền vào `DownloadableResourceFinder::create`.
 *
 * Stack Layout at `sp+0x48..sp+0xdf` [OBSERVED at 0x00ee20..0x00f030]:
 *   +0x00 (`sp+0x48`): std::string host             (`getHost()Ljava/lang/String;` @ `.rodata 0x015a0a`)
 *   +0x18 (`sp+0x60`): std::string sdk_version      (`getSdkVersion()Ljava/lang/String;` @ `.rodata 0x015a24`)
 *   +0x30 (`sp+0x78`): std::string device_type      (`getDeviceType()Ljava/lang/String;` @ `.rodata 0x015a44`)
 *   +0x48 (`sp+0x90`): std::string device_platform  (`getDevicePlatform()Ljava/lang/String;` @ `.rodata 0x015a64`)
 *   +0x60 (`sp+0xa8`): std::string device_id        (`getDeviceId()Ljava/lang/String;` @ `.rodata 0x015a88`)
 *   +0x78 (`sp+0xc0`): std::string app_id           (`getAid()Ljava/lang/String;` @ `.rodata 0x015aa4`)
 *   +0x90 (`sp+0xd8`): std::string model_dir        (`jstring modelDir` arg `x3` @ `0x00f028`)
 */
struct DownloadableResourceFinderConfig {
    std::string host;            // +0x00
    std::string sdk_version;     // +0x18
    std::string device_type;     // +0x30
    std::string device_platform; // +0x48
    std::string device_id;       // +0x60
    std::string app_id;          // +0x78
    std::string model_dir;       // +0x90
};

/**
 * @brief Base class `Bach::ModelDownloadListener` with vtable at `.data.rel.ro 0x01f960`
 *        (`+0x10 = 0x01f970`) [OBSERVED at 0x00f394..0x00f884].
 *        Lớp cơ sở lắng nghe sự kiện tải mô hình `Bach::ModelDownloadListener`.
 *
 * Vtable Layout at `.data.rel.ro 0x01f970` [OBSERVED]:
 *   +0x00: void retain()
 *   +0x08: void release()
 *   +0x10: int  retainCount()
 *   +0x18: void onSuccess()                             (@ 0x00f6ac)
 *   +0x20: void onFail(int errorCode, const std::string& msg) (@ 0x00f798)
 *   +0x28: ~ModelDownloadListener() D1                  (@ 0x00f870)
 *   +0x30: ~ModelDownloadListener() D0                  (@ 0x00f874)
 */
class ModelDownloadListener : public AmazingEngine::RefBase {
public:
    ~ModelDownloadListener() noexcept override = default;
    virtual void onSuccess() = 0;
    virtual void onFail(int32_t error_code, const std::string& message) = 0;
};

/**
 * @brief `NativeListener` (32 bytes = `0x20` allocated at `0x00f394: mov w0, #0x20; bl operator new`)
 *        wrapping a JNI global reference (`+0x10`: `jobject`, `+0x18`: `bool attached`) [OBSERVED].
 *        Lớp triển khai `NativeListener` kích thước 32 byte (`0x20`) bọc đối tượng callback Java.
 */
class NativeListener : public ModelDownloadListener {
public:
    using SuccessCallback = std::function<void()>;
    using FailCallback = std::function<void(int32_t, const std::string&)>;

    explicit NativeListener(void* java_listener_global_ref = nullptr,
                            SuccessCallback on_success = nullptr,
                            FailCallback on_fail = nullptr) noexcept
        : java_listener_global_ref_(java_listener_global_ref),
          attached_thread_(false),
          on_success_cb_(std::move(on_success)),
          on_fail_cb_(std::move(on_fail)) {}

    ~NativeListener() noexcept override = default;

    void onSuccess() override;
    void onFail(int32_t error_code, const std::string& message) override;

    void* java_listener_global_ref() const noexcept { return java_listener_global_ref_; }
    void clear_java_listener_global_ref() noexcept { java_listener_global_ref_ = nullptr; }

    int32_t success_call_count() const noexcept { return success_call_count_; }
    int32_t fail_call_count() const noexcept { return fail_call_count_; }
    int32_t last_error_code() const noexcept { return last_error_code_; }
    const std::string& last_error_message() const noexcept { return last_error_message_; }

private:
    void* java_listener_global_ref_; // +0x10 [OBSERVED at 0x00f3b8: str x0, [x22, #0x10]]
    bool attached_thread_;           // +0x18 [OBSERVED at 0x00f3bc: strb wzr, [x22, #0x18]]
    SuccessCallback on_success_cb_;
    FailCallback on_fail_cb_;
    int32_t success_call_count_ = 0;
    int32_t fail_call_count_ = 0;
    int32_t last_error_code_ = 0;
    std::string last_error_message_;
};

/**
 * @brief `Bach::DownloadableResourceFinder` imported from `libbach-sdk.so` (`.dynsym [074]`) [OBSERVED].
 *        Lớp tìm tài nguyên có thể tải xuống `Bach::DownloadableResourceFinder`.
 *
 * Vtable Layout [OBSERVED at 0x00f3f8]:
 *   +0x00..+0x20: RefBase methods
 *   +0x28: findResourceUri(...)
 *   +0x30: void downloadModels(const std::unordered_map<std::string, std::vector<std::string>>& params,
 *                              ModelDownloadListener* listener) (@ 0x00f3f8: ldr x8, [x8, #0x30])
 */
class DownloadableResourceFinder : public AmazingEngine::RefBase {
public:
    explicit DownloadableResourceFinder(const DownloadableResourceFinderConfig& config)
        : config_(config) {}
    ~DownloadableResourceFinder() noexcept override = default;

    static DownloadableResourceFinder* create(const DownloadableResourceFinderConfig& config);

    virtual void downloadModels(
        const std::unordered_map<std::string, std::vector<std::string>>& requirements,
        ModelDownloadListener* listener);

    const DownloadableResourceFinderConfig& config() const noexcept { return config_; }
    const std::unordered_map<std::string, std::vector<std::string>>& last_requirements() const noexcept {
        return last_requirements_;
    }

private:
    DownloadableResourceFinderConfig config_;
    std::unordered_map<std::string, std::vector<std::string>> last_requirements_;
};

/**
 * @brief `Bach::EPResourceFinder` imported from `libbach-sdk.so` (`.dynsym [075]`) [OBSERVED].
 *        Lớp tìm tài nguyên EffectPlatform `Bach::EPResourceFinder`.
 */
class EPResourceFinder : public AmazingEngine::RefBase {
public:
    explicit EPResourceFinder(int64_t bef_effect_resource_finder_handle) noexcept
        : bef_handle_(bef_effect_resource_finder_handle) {}
    ~EPResourceFinder() noexcept override = default;

    static EPResourceFinder* create(int64_t bef_effect_resource_finder_handle);

    int64_t bef_handle() const noexcept { return bef_handle_; }

private:
    int64_t bef_handle_;
};

} // namespace Bach

// ============================================================================
// 2. JNI_OnLoad & UTF-8 String Conversion Helpers (0x0102b0..0x010504)
//    Hàm JNI_OnLoad và các hàm tiện ích chuyển đổi chuỗi UTF-8 [OBSERVED]
// ============================================================================

struct BachJniGlobalState {
    static constexpr int32_t kJniVersion1_6 = 0x00010006; // [OBSERVED at 0x0102cc: mov w2, #0x10006]
    void* java_vm = nullptr;                              // .bss 0x0202b8
    void* class_loader_global_ref = nullptr;              // .bss 0x0202b0
};

BachJniGlobalState& GetBachJniGlobalState() noexcept;

/**
 * @brief Executes `JNI_OnLoad` (`0x0102b0..0x010334`), verifying `vm != nullptr`, storing `g_JavaVM`
 *        at `.bss 0x0202b8`, and returning `0x00010006` (`JNI_VERSION_1_6`) on success or `-1` on error [OBSERVED].
 *        Thực thi `JNI_OnLoad` (`0x0102b0..0x010334`), trả về `0x00010006` (`JNI_VERSION_1_6`).
 */
int32_t ExecuteBachJniOnLoad(void* vm, bool env_lookup_ok = true) noexcept;

/**
 * @brief Converts UTF-8 byte buffer (`java.lang.String.getBytes("utf-8")`) to `std::string`
 *        matching `jstringToStdString` (`0x010464..0x010504`) [OBSERVED].
 *        Chuyển đổi mảng byte UTF-8 sang `std::string` khớp hàm `jstringToStdString` (`0x010464..0x010504`).
 */
std::string JstringUtf8BytesToStdString(const char* utf8_bytes, size_t byte_len);

} // namespace bach_sdk
} // namespace bytedance
} // namespace com

#endif // NEXTAI_OPENCUT_BACH_RESOURCE_FINDER_JNI_H_
