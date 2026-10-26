/**
 * @file lynxtrace_controller_jni.h
 * @brief Declarations for `lynx::trace::TraceController` (`0x0040fc..0x004198`,
 *        singleton at `.data 0x00c000`, 13-slot vtable at `.data.rel.ro 0x008018..0x008078`),
 *        the 4 `com.lynx.tasm.base.TraceController` JNI methods (`.data.rel.ro 0x008080..0x0080df`),
 *        and the 10 `com.lynx.tasm.base.TraceEvent` JNI methods (`.data.rel.ro 0x008108..0x0081f7`).
 *        Khai báo `lynx::trace::TraceController` (`0x0040fc..0x004198`), 4 phương thức JNI của
 *        `TraceController` và 10 phương thức JNI của `TraceEvent` trong `liblynxtrace.so`.
 */

#ifndef NEXTAI_OPENCUT_LYNXTRACE_CONTROLLER_JNI_H_
#define NEXTAI_OPENCUT_LYNXTRACE_CONTROLLER_JNI_H_

#include "lynxtrace_types.h"

#include <string>
#include <vector>

namespace nextai {
namespace opencut {
namespace lynxtrace {

// ============================================================================
// 1. `lynx::trace::TraceController` (`16 bytes` at `.data 0x00c000`)
//    Lớp `lynx::trace::TraceController` (`16 byte` tại `.data 0x00c000`)
// ============================================================================

/**
 * @brief Abstract interface for the optional delegate pointer at `TraceController + 0x08`
 *        destroyed in `~TraceController` (`0x00415c..0x004180`: `ldr x0, [x0, #8]; cbz x0, #0x4180;
 *        ldr x8, [x0]; ldr x1, [x8, #8]; br x1`).
 *        Giao diện trừu tượng cho con trỏ delegate tại `TraceController + 0x08` được hủy
 *        trong `~TraceController` (`0x00415c..0x004180`).
 */
class TraceControllerDelegate {
public:
    virtual ~TraceControllerDelegate() = default;
};

/**
 * @brief Exact 16-byte (`0x10`) reconstruction of `lynx::trace::TraceController`
 *        whose singleton resides at `.data 0x00c000..0x00c00f` with 13 virtual methods
 *        in `.data.rel.ro 0x008018..0x008078`.
 *        Tái dựng chính xác 16-byte (`0x10`) của `lynx::trace::TraceController`
 *        với singleton tại `.data 0x00c000..0x00c00f` và 13 phương thức ảo tại `0x008018..0x008078`.
 */
class TraceController {
public:
    TraceController() noexcept : delegate_(nullptr) {}

    // Slot [0] (0x008018 -> 0x00415c D1) & Slot [1] (0x008020 -> 0x004184 D0)
    virtual ~TraceController() noexcept;

    // Slot [2] (0x008028 -> 0x00419c: mov w0, #-1; ret)
    virtual int32_t StartTracing(const void* trace_config) noexcept;

    // Slot [3] (0x008030 -> 0x0041a4 -> 0x0041e4: mov w0, wzr; ret)
    virtual bool StopTracing(int32_t session_id) noexcept;

    // Slot [4] (0x008038 -> 0x0040f8: ret)
    virtual void AddTracePlugin(void* plugin) noexcept;

    // Slot [5] (0x008040 -> 0x0041a4 -> 0x0041e4: mov w0, wzr; ret)
    virtual bool DeleteTracePlugin(const std::string& plugin_name) noexcept;

    // Slot [6] (0x008048 -> 0x0040f8: ret)
    virtual void StartStartupTracingIfNeeded() noexcept;

    // Slot [7] (0x008050 -> 0x0040f8: ret)
    virtual void SetStartupTracingConfig(const std::string& config) noexcept;

    // Slot [8] (0x008058 -> 0x0040f8: ret)
    virtual void SetTraceBufferSize(uint32_t buffer_size_kb) noexcept;

    // Slot [9] (0x008060 -> 0x0040f8: ret)
    virtual void AddCompleteCallback(int32_t session_id, void* callback) noexcept;

    // Slot [10] (0x008068 -> 0x0041a8 -> 0x004208: stp xzr, xzr, [x8]; str xzr, [x8, #0x10]; ret)
    virtual std::string GetStartupTracingConfig() const noexcept;

    // Slot [11] (0x008070 -> 0x0041a8 -> 0x004208: stp xzr, xzr, [x8]; str xzr, [x8, #0x10]; ret)
    virtual std::string GetTraceFilePath(int32_t session_id) const noexcept;

    // Slot [12] (0x008078 -> 0x0041a4 -> 0x0041e4: mov w0, wzr; ret)
    virtual bool IsTracingStarted() const noexcept;

    /**
     * @brief `.dynsym [011]` `_ZN4lynx5trace15TraceController8InstanceEv` (`0x0040fc..0x004158`).
     *        Thread-safe singleton accessor using guard variable at `.bss 0x00c010`.
     *        Hàm lấy thực thể đơn thể an toàn đa luồng dùng biến bảo vệ tại `.bss 0x00c010`.
     */
    static TraceController* Instance() noexcept;

    void set_delegate(TraceControllerDelegate* delegate) noexcept { delegate_ = delegate; }
    TraceControllerDelegate* delegate() const noexcept { return delegate_; }

private:
    TraceControllerDelegate* delegate_; // +0x08 (.data 0x00c008)
};
static_assert(sizeof(TraceController) == 16, "TraceController must be 16 bytes (vptr + delegate_)");

// ============================================================================
// 2. `com.lynx.tasm.base.TraceController` 4 JNI Methods (`.data.rel.ro 0x008080..0x0080df`)
//    4 Phương thức JNI của `com.lynx.tasm.base.TraceController`
// ============================================================================

// 0x008080: nativeCreateTraceController ()J -> 0x0041c4
jlong TraceController_nativeCreateTraceController(JNIEnv* env, jobject jcaller) noexcept;

// 0x008098: nativeStartTracing (JI[Ljava/lang/String;[Ljava/lang/String;Ljava/lang/String;Z)I -> 0x00419c
jint TraceController_nativeStartTracing(
    JNIEnv* env,
    jobject jcaller,
    jlong native_ptr,
    jint buffer_size,
    jobjectArray included_categories,
    jobjectArray excluded_categories,
    jstring trace_file,
    jboolean enable_systrace) noexcept;

// 0x0080b0: nativeStopTracing (JI)V -> 0x0040f8
void TraceController_nativeStopTracing(
    JNIEnv* env,
    jobject jcaller,
    jlong native_ptr,
    jint session_id) noexcept;

// 0x0080c8: nativeStartStartupTracingIfNeeded (J)V -> 0x0040f8
void TraceController_nativeStartStartupTracingIfNeeded(
    JNIEnv* env,
    jobject jcaller,
    jlong native_ptr) noexcept;

// ============================================================================
// 3. `com.lynx.tasm.base.TraceEvent` 10 JNI Methods (`.data.rel.ro 0x008108..0x0081f7`)
//    10 Phương thức JNI của `com.lynx.tasm.base.TraceEvent`
// ============================================================================

// [0] 0x008108: nativeBeginSection (Ljava/lang/String;Ljava/lang/String;)V -> 0x0040f8
void TraceEvent_nativeBeginSection(JNIEnv* env, jclass clazz, jstring category, jstring name);

// [1] 0x008120: nativeBeginSectionWithProps (Ljava/lang/String;Ljava/lang/String;Ljava/util/Map;)V -> 0x0040f8
void TraceEvent_nativeBeginSectionWithProps(
    JNIEnv* env,
    jclass clazz,
    jstring category,
    jstring name,
    jobject props);

// [2] 0x008138: nativeEndSection (Ljava/lang/String;Ljava/lang/String;)V -> 0x0040f8
void TraceEvent_nativeEndSection(JNIEnv* env, jclass clazz, jstring category, jstring name);

// [3] 0x008150: nativeEndSectionWithProps (Ljava/lang/String;Ljava/lang/String;Ljava/util/Map;)V -> 0x0040f8
void TraceEvent_nativeEndSectionWithProps(
    JNIEnv* env,
    jclass clazz,
    jstring category,
    jstring name,
    jobject props);

// [4] 0x008168: nativeInstant (Ljava/lang/String;Ljava/lang/String;JLjava/lang/String;)V -> 0x0040f8
void TraceEvent_nativeInstant(
    JNIEnv* env,
    jclass clazz,
    jstring category,
    jstring name,
    jlong timestamp,
    jstring color);

// [5] 0x008180: nativeInstantWithProps (Ljava/lang/String;Ljava/lang/String;JLjava/util/Map;)V -> 0x0040f8
void TraceEvent_nativeInstantWithProps(
    JNIEnv* env,
    jclass clazz,
    jstring category,
    jstring name,
    jlong timestamp,
    jobject props);

// [6] 0x008198: nativeCounter (Ljava/lang/String;Ljava/lang/String;J)V -> 0x0040f8
void TraceEvent_nativeCounter(
    JNIEnv* env,
    jclass clazz,
    jstring category,
    jstring name,
    jlong counter_value);

// [7] 0x0081b0: nativeCategoryEnabled (Ljava/lang/String;)Z -> 0x0041a4 -> 0x0041e4
jboolean TraceEvent_nativeCategoryEnabled(JNIEnv* env, jclass clazz, jstring category) noexcept;

// [8] 0x0081c8: nativeSystemTraceEnabled ()Z -> 0x0041a4 -> 0x0041e4
jboolean TraceEvent_nativeSystemTraceEnabled(JNIEnv* env, jclass clazz) noexcept;

// [9] 0x0081e0: nativePerfettoTraceEnabled ()Z -> 0x0041a4 -> 0x0041e4
jboolean TraceEvent_nativePerfettoTraceEnabled(JNIEnv* env, jclass clazz) noexcept;

LynxTraceBssSegment& GetLynxTraceBssState() noexcept;
void ResetLynxTraceBssState() noexcept;

} // namespace lynxtrace
} // namespace opencut
} // namespace nextai

#endif // NEXTAI_OPENCUT_LYNXTRACE_CONTROLLER_JNI_H_
