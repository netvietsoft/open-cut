/**
 * @file lynx_krypton_surface_vsync.h
 * @brief Declarations for `LynxCanvasDownStreamManager`, `LynxKryptonFrameService`,
 *        and `UICanvasSurfaceView` native bridges in `liblynx_krypton.so` (`0x004328..0x004ff0`).
 *        Khai báo các cầu nối native `LynxCanvasDownStreamManager`, `LynxKryptonFrameService`,
 *        và `UICanvasSurfaceView` trong `liblynx_krypton.so` (`0x004328..0x004ff0`).
 */

#ifndef NEXTAI_OPENCUT_LYNX_KRYPTON_SURFACE_VSYNC_H_
#define NEXTAI_OPENCUT_LYNX_KRYPTON_SURFACE_VSYNC_H_

#include "lynx_krypton_types.h"

#include <atomic>
#include <functional>
#include <memory>
#include <string>
#include <vector>

namespace nextai {
namespace opencut {
namespace lynx_krypton {

// ============================================================================
// 1. `SurfaceWithAndroidNativeWindow` (`32 bytes` / `0x20`, `0x0043ac` & `0x004fac`)
//    Lớp `SurfaceWithAndroidNativeWindow` (`32 byte` / `0x20`, `0x0043ac` & `0x004fac`)
// ============================================================================

/**
 * @brief Exact 32-byte (`0x20`) reconstruction of `lynx::canvas::SurfaceWithAndroidNativeWindow`
 *        allocated via `mov w0, #0x20; bl operator new` (`0x0043ac` & `0x004fac`) and constructed
 *        via `bl 0x0051c0` (`SurfaceWithAndroidNativeWindow(ANativeWindow*, int, int)`).
 *        Tái dựng chính xác 32-byte (`0x20`) của `lynx::canvas::SurfaceWithAndroidNativeWindow`.
 */
class SurfaceWithAndroidNativeWindow {
public:
    SurfaceWithAndroidNativeWindow(ANativeWindowMock* native_window, int32_t default_w, int32_t default_h) noexcept;
    virtual ~SurfaceWithAndroidNativeWindow() noexcept;

    ANativeWindowMock* native_window() const noexcept { return native_window_; }
    int32_t default_width() const noexcept { return default_width_; }
    int32_t default_height() const noexcept { return default_height_; }

private:
    ANativeWindowMock* native_window_;  // +0x08
    int32_t            default_width_;  // +0x10
    int32_t            default_height_; // +0x14
    uint64_t           reserved_18_;    // +0x18
};
static_assert(sizeof(SurfaceWithAndroidNativeWindow) == 32, "SurfaceWithAndroidNativeWindow must be 32 bytes (0x20)");

// ============================================================================
// 2. `PlatformViewObserver`, `TaskRunner`, & `CanvasAppAndroid` Models
//    Mô hình `PlatformViewObserver`, `TaskRunner`, & `CanvasAppAndroid`
// ============================================================================

struct DownstreamSurfaceEvent {
    bool        is_created;        // true = OnSurfaceCreated, false = OnSurfaceDestroyed
    std::string view_id;           // canvasId string
    int32_t     width;
    int32_t     height;
    int32_t     max_fps;
    uint32_t    packed_flags;      // 0x00010100 on creation
    bool        posted_to_runner;  // true if executed via TaskRunner::PostTask
    ANativeWindowMock* window_ptr;
};

class PlatformViewObserver {
public:
    virtual ~PlatformViewObserver() = default;

    /**
     * @brief Models `lynx::canvas::PlatformViewObserver::OnSurfaceCreated` (`0x005420` PLT).
     *        Mô phỏng `lynx::canvas::PlatformViewObserver::OnSurfaceCreated` (`0x005420` PLT).
     */
    virtual void OnSurfaceCreated(const SurfaceConfig& config, const std::string& view_id, bool via_post);

    /**
     * @brief Models `lynx::canvas::PlatformViewObserver::OnSurfaceDestroyed` (`0x005400` PLT).
     *        Mô phỏng `lynx::canvas::PlatformViewObserver::OnSurfaceDestroyed` (`0x005400` PLT).
     */
    virtual void OnSurfaceDestroyed(const std::string& view_id, ANativeWindowMock* window_ptr, bool via_post);

    const std::vector<DownstreamSurfaceEvent>& events() const noexcept { return events_; }

private:
    std::vector<DownstreamSurfaceEvent> events_;
};

class KryptonTaskRunner {
public:
    explicit KryptonTaskRunner(bool runs_in_current_sequence = true) noexcept
        : runs_in_current_sequence_(runs_in_current_sequence) {}
    virtual ~KryptonTaskRunner() = default;

    /**
     * @brief Models `vtable + 0x08` call at `0x005158`: `RunsTasksInCurrentSequence()`.
     *        Mô phỏng lệnh gọi `vtable + 0x08` tại `0x005158`: `RunsTasksInCurrentSequence()`.
     */
    virtual bool RunsTasksInCurrentSequence() const noexcept { return runs_in_current_sequence_; }

    void set_runs_in_current_sequence(bool val) noexcept { runs_in_current_sequence_ = val; }

    /**
     * @brief Models `lynx::base::TaskRunner::PostTask(std::function<void()>)` (`0x0053e0` PLT).
     *        Mô phỏng `lynx::base::TaskRunner::PostTask(std::function<void()>)` (`0x0053e0` PLT).
     */
    void PostTask(std::function<void()> task);

    uint32_t posted_task_count() const noexcept { return posted_task_count_; }

private:
    bool     runs_in_current_sequence_;
    uint32_t posted_task_count_ = 0;
};

class CanvasAppCore {
public:
    CanvasAppCore()
        : observer_(std::make_shared<PlatformViewObserver>()) {}
    virtual ~CanvasAppCore() = default;

    /**
     * @brief Models `vtable + 0x10` call at `0x004810`: `GetPlatformViewObserver(const std::string&)`.
     *        Mô phỏng lệnh gọi `vtable + 0x10` tại `0x004810`: `GetPlatformViewObserver(const std::string&)`.
     */
    virtual std::shared_ptr<PlatformViewObserver> GetPlatformViewObserver(const std::string& view_id) {
        (void)view_id;
        return observer_;
    }

private:
    std::shared_ptr<PlatformViewObserver> observer_;
};

class CanvasAppAndroid {
public:
    explicit CanvasAppAndroid(bool runs_on_current_thread = true)
        : app_core_(std::make_shared<CanvasAppCore>()),
          task_runner_(std::make_shared<KryptonTaskRunner>(runs_on_current_thread)) {}

    std::shared_ptr<CanvasAppCore> GetApp() const noexcept { return app_core_; }
    std::shared_ptr<KryptonTaskRunner> GetTaskRunner() const noexcept { return task_runner_; }

private:
    std::shared_ptr<CanvasAppCore>     app_core_;
    std::shared_ptr<KryptonTaskRunner> task_runner_;
};

// ============================================================================
// 3. `LynxKryptonFrameService` (`16 bytes` / `0x10`, `0x004bb4..0x004f68`)
//    Dịch vụ Khung hình `LynxKryptonFrameService` (`16 byte` / `0x10`, `0x004bb4..0x004f68`)
// ============================================================================

class KryptonFrameServiceCore {
public:
    virtual ~KryptonFrameServiceCore() = default;

    /**
     * @brief Models `vtable + 0x10` call at `0x004c78`: `RequestVSync(std::function<void(int64_t)>)`.
     *        Mô phỏng lệnh gọi `vtable + 0x10` tại `0x004c78`: `RequestVSync(std::function<void(int64_t)>)`.
     */
    virtual void RequestVSync(std::function<void(int64_t)> callback) {
        vsync_callbacks_.push_back(std::move(callback));
    }

    /**
     * @brief Models `vtable + 0x20` call at `0x004d20`: `RegisterBeforeVSyncEndListener(std::function<void(int64_t)>)`.
     *        Mô phỏng lệnh gọi `vtable + 0x20` tại `0x004d20`: `RegisterBeforeVSyncEndListener(std::function<void(int64_t)>)`.
     */
    virtual void RegisterBeforeVSyncEndListener(std::function<void(int64_t)> listener) {
        before_vsync_end_listeners_.push_back(std::move(listener));
    }

    void TriggerVSync(int64_t frame_time_nanos);
    void TriggerBeforeVSyncEnd(int64_t frame_time_nanos);

private:
    std::vector<std::function<void(int64_t)>> vsync_callbacks_;
    std::vector<std::function<void(int64_t)>> before_vsync_end_listeners_;
};

/**
 * @brief Exact 16-byte (`0x10`) native wrapper allocated in `nativeCreateFrameService` (`0x004bb4`):
 *        `mov w0, #0x10; bl operator new; ldp x8, x9, [x19]; stp xzr, xzr, [x19]; stp x8, x9, [x0]`.
 *        Wrapper native 16-byte (`0x10`) chính xác được cấp phát trong `nativeCreateFrameService` (`0x004bb4`).
 */
struct LynxKryptonFrameServiceWrapper {
    std::shared_ptr<KryptonFrameServiceCore> service; // 16 bytes on AArch64 (ptr + control block)
};
static_assert(sizeof(LynxKryptonFrameServiceWrapper) == 16, "LynxKryptonFrameServiceWrapper must be 16 bytes (0x10)");

struct JavaVSyncInvocationRecord {
    std::string method_name;
    std::string method_sig;
    int64_t     frame_time_nanos;
};

// ============================================================================
// 4. JNI Native Method Declarations (`0x004328..0x004ff0`)
//    Khai báo Phương thức Native JNI (`0x004328..0x004ff0`)
// ============================================================================

jlong LynxCanvasDownStreamManager_nativeAddSurface(
    JNIEnv* env,
    jobject jcaller,
    jlong canvas_app_weak_ptr,
    jstring jcanvas_id,
    jobject jsurface,
    jint width,
    jint height,
    jint max_fps);

void LynxCanvasDownStreamManager_nativeRemoveSurface(
    JNIEnv* env,
    jobject jcaller,
    jlong canvas_app_weak_ptr,
    jstring jcanvas_id,
    jlong surface_window_ptr);

jlong LynxKryptonFrameService_nativeCreateFrameService(
    JNIEnv* env,
    jobject jcaller,
    jlong native_shared_ptr_addr);

void LynxKryptonFrameService_nativeDestroyFrameService(
    JNIEnv* env,
    jobject jcaller,
    jlong wrapper_ptr);

void LynxKryptonFrameService_nativeDoRequestVSync(
    JNIEnv* env,
    jobject jcaller,
    jlong wrapper_ptr);

void LynxKryptonFrameService_nativeDoRegisterBeforeVSyncEndListener(
    JNIEnv* env,
    jobject jcaller,
    jlong wrapper_ptr);

jlong UICanvasSurfaceView_nativeCreateSurface(
    JNIEnv* env,
    jclass clazz,
    jobject jsurface);

std::vector<JavaVSyncInvocationRecord> GetCapturedJavaVSyncInvocations();
void ClearCapturedJavaVSyncInvocations();

} // namespace lynx_krypton
} // namespace opencut
} // namespace nextai

#endif // NEXTAI_OPENCUT_LYNX_KRYPTON_SURFACE_VSYNC_H_
