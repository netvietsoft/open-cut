/**
 * @file lynx_krypton_surface_vsync.cpp
 * @brief Exact AArch64 opcode-verified implementation of `LynxCanvasDownStreamManager`
 *        (`0x004328..0x004b44`), `LynxKryptonFrameService` (`0x004bb4..0x004f68`),
 *        and `UICanvasSurfaceView` (`0x004f6c..0x004ff0`) for `liblynx_krypton.so`.
 *        Triển khai đối soát opcode AArch64 chính xác của `LynxCanvasDownStreamManager`,
 *        `LynxKryptonFrameService`, và `UICanvasSurfaceView` cho `liblynx_krypton.so`.
 */

#include "lynx_krypton_surface_vsync.h"
#include "lynx_krypton_trace_log.h"

#include <mutex>
#include <utility>

namespace nextai {
namespace opencut {
namespace lynx_krypton {

namespace {

std::mutex g_vsync_mutex;
std::vector<JavaVSyncInvocationRecord> g_vsync_invocations;

/**
 * @brief Converts a `jstring` (modeled as `const char*` on host) to `std::string`
 *        matching `lynx::base::android::JNIConvertHelper::ConvertToString` (`0x005360` PLT).
 *        Chuyển đổi `jstring` sang `std::string` khớp với `JNIConvertHelper::ConvertToString` (`0x005360`).
 */
std::string ConvertJStringToStdString(JNIEnv* env, jstring jstr) {
    (void)env;
    if (jstr == nullptr) {
        return std::string();
    }
    return std::string(reinterpret_cast<const char*>(jstr));
}

/**
 * @brief Models `ANativeWindow_fromSurface(env, jsurface)` (`0x005340` PLT).
 *        Mô phỏng `ANativeWindow_fromSurface(env, jsurface)` (`0x005340` PLT).
 */
ANativeWindowMock* AcquireNativeWindowFromSurface(JNIEnv* env, jobject jsurface) {
    (void)env;
    if (jsurface == nullptr) {
        return nullptr;
    }
    auto* window = reinterpret_cast<ANativeWindowMock*>(jsurface);
    window->ref_count.fetch_add(1, std::memory_order_relaxed);
    return window;
}

/**
 * @brief Models `ANativeWindow_release(window)` (`0x0053d0` PLT).
 *        Mô phỏng `ANativeWindow_release(window)` (`0x0053d0` PLT).
 */
void ReleaseNativeWindow(ANativeWindowMock* window) noexcept {
    if (window != nullptr) {
        window->ref_count.fetch_sub(1, std::memory_order_acq_rel);
    }
}

/**
 * @brief Models `sub_0047b4` (`0x0047b4..0x00483c`):
 *        Locks `std::weak_ptr<CanvasAppAndroid>`, fetches `CanvasAppAndroid::GetApp()` (`0x0053f0`),
 *        and invokes `App::GetPlatformViewObserver(view_id)` (`vtable + 0x10` @ `0x004810`).
 *        Mô phỏng `sub_0047b4`: khóa `weak_ptr<CanvasAppAndroid>`, lấy `GetApp()`, và
 *        gọi `GetPlatformViewObserver(view_id)`.
 */
std::shared_ptr<PlatformViewObserver> ResolvePlatformViewObserver(
    const std::weak_ptr<CanvasAppAndroid>& weak_app,
    const std::string& view_id) {
    std::shared_ptr<CanvasAppAndroid> locked_app = weak_app.lock();
    if (!locked_app) {
        return nullptr;
    }
    std::shared_ptr<CanvasAppCore> app_core = locked_app->GetApp();
    if (!app_core) {
        return nullptr;
    }
    return app_core->GetPlatformViewObserver(view_id);
}

/**
 * @brief Models `sub_004a2c` (`0x004a2c..0x004b44`):
 *        Constructs the 72-byte `SurfaceConfig` on the stack with `packed_flags = 0x00010100`
 *        (`mov w8, #0x10100` @ `0x004a7c`) and calls `PlatformViewObserver::OnSurfaceCreated` (`0x005420`).
 *        Mô phỏng `sub_004a2c`: khởi tạo `SurfaceConfig` 72-byte trên stack với `packed_flags = 0x00010100`
 *        và gọi `PlatformViewObserver::OnSurfaceCreated`.
 */
void ExecuteAddSurfaceOnRunner(
    const std::weak_ptr<CanvasAppAndroid>& weak_app,
    const std::string& view_id,
    const std::shared_ptr<SurfaceWithAndroidNativeWindow>& surface,
    int32_t width,
    int32_t height,
    int32_t max_fps,
    bool via_post) {
    std::shared_ptr<PlatformViewObserver> observer = ResolvePlatformViewObserver(weak_app, view_id);
    if (!observer) {
        return;
    }

    // Exact stack initialization at 0x004a60..0x004a98:
    //   stp x22, x21, [sp, #8]     ; surface shared_ptr
    //   stp w9, w10, [sp, #0x18]   ; width, height
    //   mov w8, #0x10100
    //   str w11, [sp, #0x20]       ; max_fps
    //   str w8, [sp, #0x24]        ; packed_flags = 0x00010100
    //   stp xzr, xzr, [sp, #0x38]
    //   stp xzr, xzr, [sp, #0x28]
    //   str wzr, [sp, #0x48]
    SurfaceConfig config{};
    config.surface      = surface;
    config.width        = width;
    config.height       = height;
    config.max_fps      = max_fps;
    config.packed_flags = 0x00010100u;
    config.reserved_0   = 0u;
    config.reserved_1   = 0u;
    config.reserved_2   = 0u;
    config.reserved_3   = 0u;
    config.extra_flags  = 0u;
    config.padding      = 0u;

    observer->OnSurfaceCreated(config, view_id, via_post);
}

/**
 * @brief Models `sub_0048a4` (`0x0048a4..0x004964`):
 *        Resolves `PlatformViewObserver`, calls `OnSurfaceDestroyed(observer, view_id)` (`0x005400`),
 *        and calls `ANativeWindow_release(reinterpret_cast<ANativeWindow*>(surface_ptr))` (`0x0053d0`).
 *        Mô phỏng `sub_0048a4`: gọi `OnSurfaceDestroyed` và `ANativeWindow_release`.
 */
void ExecuteRemoveSurfaceOnRunner(
    const std::weak_ptr<CanvasAppAndroid>& weak_app,
    const std::string& view_id,
    ANativeWindowMock* window_ptr,
    bool via_post) {
    std::shared_ptr<PlatformViewObserver> observer = ResolvePlatformViewObserver(weak_app, view_id);
    if (!observer) {
        return;
    }
    observer->OnSurfaceDestroyed(view_id, window_ptr, via_post);
    ReleaseNativeWindow(window_ptr);
}

} // namespace

// ============================================================================
// 1. `SurfaceWithAndroidNativeWindow` Implementation (`0x0051c0..0x00522c`)
//    Triển khai `SurfaceWithAndroidNativeWindow` (`0x0051c0..0x00522c`)
// ============================================================================

SurfaceWithAndroidNativeWindow::SurfaceWithAndroidNativeWindow(
    ANativeWindowMock* native_window,
    int32_t default_w,
    int32_t default_h) noexcept
    : native_window_(native_window),
      default_width_(default_w),
      default_height_(default_h),
      reserved_18_(0u) {}

SurfaceWithAndroidNativeWindow::~SurfaceWithAndroidNativeWindow() noexcept {
    // When destroyed, releases the underlying ANativeWindow reference if held
    ReleaseNativeWindow(native_window_);
    native_window_ = nullptr;
}

void PlatformViewObserver::OnSurfaceCreated(
    const SurfaceConfig& config,
    const std::string& view_id,
    bool via_post) {
    events_.push_back(DownstreamSurfaceEvent{
        true,
        view_id,
        config.width,
        config.height,
        config.max_fps,
        config.packed_flags,
        via_post,
        config.surface ? config.surface->native_window() : nullptr,
    });
}

void PlatformViewObserver::OnSurfaceDestroyed(
    const std::string& view_id,
    ANativeWindowMock* window_ptr,
    bool via_post) {
    events_.push_back(DownstreamSurfaceEvent{
        false,
        view_id,
        0,
        0,
        0,
        0u,
        via_post,
        window_ptr,
    });
}

void KryptonTaskRunner::PostTask(std::function<void()> task) {
    ++posted_task_count_;
    if (task) {
        task();
    }
}

void KryptonFrameServiceCore::TriggerVSync(int64_t frame_time_nanos) {
    for (auto& cb : vsync_callbacks_) {
        if (cb) {
            cb(frame_time_nanos);
        }
    }
}

void KryptonFrameServiceCore::TriggerBeforeVSyncEnd(int64_t frame_time_nanos) {
    for (auto& listener : before_vsync_end_listeners_) {
        if (listener) {
            listener(frame_time_nanos);
        }
    }
}

// ============================================================================
// 2. `LynxCanvasDownStreamManager` JNI Methods (`0x004328..0x0047b0`)
//    Các phương thức JNI của `LynxCanvasDownStreamManager` (`0x004328..0x0047b0`)
// ============================================================================

jlong LynxCanvasDownStreamManager_nativeAddSurface(
    JNIEnv* env,
    jobject jcaller,
    jlong canvas_app_weak_ptr,
    jstring jcanvas_id,
    jobject jsurface,
    jint width,
    jint height,
    jint max_fps) {
    (void)jcaller;

    // 0x004364..0x004388:
    //   UnwrapWeak<CanvasAppAndroid>(canvas_app_weak_ptr) -> std::shared_ptr::lock()
    if (canvas_app_weak_ptr == 0 || jsurface == nullptr) {
        return 0;
    }

    auto* weak_app_ptr = reinterpret_cast<std::weak_ptr<CanvasAppAndroid>*>(canvas_app_weak_ptr);
    std::shared_ptr<CanvasAppAndroid> locked_app = weak_app_ptr->lock();
    if (!locked_app) {
        return 0;
    }

    // 0x00439c..0x0043e0:
    //   x22 = ANativeWindow_fromSurface(env, jsurface)
    //   x20 = operator new(0x20)
    //   SurfaceWithAndroidNativeWindow(x20, x22, 0, 0)
    ANativeWindowMock* native_window = AcquireNativeWindowFromSurface(env, jsurface);
    if (native_window == nullptr) {
        return 0;
    }
    auto surface_obj = std::make_shared<SurfaceWithAndroidNativeWindow>(native_window, 0, 0);

    // 0x0043e4..0x0043f0:
    //   std::string view_id = JNIConvertHelper::ConvertToString(env, jcanvas_id)
    const std::string view_id = ConvertJStringToStdString(env, jcanvas_id);

    // 0x0043f4..0x004448:
    //   if (GetMinLogLevel() <= 0)
    //     LogMessage("down_stream_surface_manager.cc", 0x20 (32), 0)
    //       << "Krypton AddDownStreamSurface for canvas app: " << locked_app.get();
    if (LynxLogMessage::GetMinLogLevel() <= 0) {
        LynxLogMessage log_msg(RodataConstants::kFileDownStreamSurfaceManagerCc, 32, 0);
        log_msg.stream().write(RodataConstants::kLogAddDownStreamSurface, 45); // mov w2, #0x2d @ 0x00442c
        log_msg.stream() << static_cast<const void*>(locked_app.get());
    }

    // 0x00444c..0x0044b0 & 0x005128..0x005174:
    //   Check CanvasAppAndroid::GetTaskRunner()->RunsTasksInCurrentSequence() (vtable + 0x08)
    //   If true -> invoke sub_004a2c directly
    //   If false -> allocate 0x60-byte closure (vtable 0x0080c8 @ 0x004538) and call TaskRunner::PostTask
    std::shared_ptr<KryptonTaskRunner> runner = locked_app->GetTaskRunner();
    std::weak_ptr<CanvasAppAndroid> weak_copy = *weak_app_ptr;

    if (runner && !runner->RunsTasksInCurrentSequence()) {
        runner->PostTask([weak_copy, view_id, surface_obj, width, height, max_fps]() {
            ExecuteAddSurfaceOnRunner(weak_copy, view_id, surface_obj, width, height, max_fps, true);
        });
    } else {
        ExecuteAddSurfaceOnRunner(weak_copy, view_id, surface_obj, width, height, max_fps, false);
    }

    // 0x004508: mov x0, x22 (returns ANativeWindow* cast to jlong)
    return reinterpret_cast<jlong>(native_window);
}

void LynxCanvasDownStreamManager_nativeRemoveSurface(
    JNIEnv* env,
    jobject jcaller,
    jlong canvas_app_weak_ptr,
    jstring jcanvas_id,
    jlong surface_window_ptr) {
    (void)jcaller;

    // 0x0045ec..0x004610:
    //   UnwrapWeak<CanvasAppAndroid>(canvas_app_weak_ptr) -> std::shared_ptr::lock()
    if (canvas_app_weak_ptr == 0 || surface_window_ptr == 0) {
        return;
    }

    auto* weak_app_ptr = reinterpret_cast<std::weak_ptr<CanvasAppAndroid>*>(canvas_app_weak_ptr);
    std::shared_ptr<CanvasAppAndroid> locked_app = weak_app_ptr->lock();
    if (!locked_app) {
        return;
    }

    // 0x00461c..0x004628:
    //   std::string view_id = JNIConvertHelper::ConvertToString(env, jcanvas_id)
    const std::string view_id = ConvertJStringToStdString(env, jcanvas_id);

    // 0x00462c..0x004680:
    //   if (GetMinLogLevel() <= 0)
    //     LogMessage("down_stream_surface_manager.cc", 0x3b (59), 0)
    //       << "Krypton RemoveDownStreamSurface for canvas app: " << locked_app.get();
    if (LynxLogMessage::GetMinLogLevel() <= 0) {
        LynxLogMessage log_msg(RodataConstants::kFileDownStreamSurfaceManagerCc, 59, 0);
        log_msg.stream().write(RodataConstants::kLogRemoveDownStreamSurface, 48); // mov w2, #0x30 @ 0x004664
        log_msg.stream() << static_cast<const void*>(locked_app.get());
    }

    // 0x004684..0x00476c & 0x005128..0x005174:
    //   If RunsTasksInCurrentSequence() -> call sub_0048a4 directly
    //   Else -> allocate 0x48-byte closure (vtable 0x0080a0 @ 0x004740) and call TaskRunner::PostTask
    auto* window_ptr = reinterpret_cast<ANativeWindowMock*>(surface_window_ptr);
    std::shared_ptr<KryptonTaskRunner> runner = locked_app->GetTaskRunner();
    std::weak_ptr<CanvasAppAndroid> weak_copy = *weak_app_ptr;

    if (runner && !runner->RunsTasksInCurrentSequence()) {
        runner->PostTask([weak_copy, view_id, window_ptr]() {
            ExecuteRemoveSurfaceOnRunner(weak_copy, view_id, window_ptr, true);
        });
    } else {
        ExecuteRemoveSurfaceOnRunner(weak_copy, view_id, window_ptr, false);
    }
}

// ============================================================================
// 3. `LynxKryptonFrameService` JNI Methods (`0x004bb4..0x004f68`)
//    Các phương thức JNI của `LynxKryptonFrameService` (`0x004bb4..0x004f68`)
// ============================================================================

jlong LynxKryptonFrameService_nativeCreateFrameService(
    JNIEnv* env,
    jobject jcaller,
    jlong native_shared_ptr_addr) {
    (void)env;
    (void)jcaller;

    // 0x004bb4..0x004bec:
    //   mov  w0, #0x10
    //   bl   operator new(0x10)
    //   ldp  x8, x9, [x19]
    //   stp  xzr, xzr, [x19]
    //   stp  x8, x9, [x0]
    if (native_shared_ptr_addr == 0) {
        return 0;
    }
    auto* incoming_shared =
        reinterpret_cast<std::shared_ptr<KryptonFrameServiceCore>*>(native_shared_ptr_addr);
    auto* wrapper = new LynxKryptonFrameServiceWrapper{std::move(*incoming_shared)};
    return reinterpret_cast<jlong>(wrapper);
}

void LynxKryptonFrameService_nativeDestroyFrameService(
    JNIEnv* env,
    jobject jcaller,
    jlong wrapper_ptr) {
    (void)env;
    (void)jcaller;

    // 0x004bf0..0x004c10:
    //   cbz x19, #0x4c08
    //   ldr x0, [x19, #8] ; control block release (bl #0x4968)
    //   mov x0, x19       ; bl operator delete (0x005410)
    if (wrapper_ptr == 0) {
        return;
    }
    auto* wrapper = reinterpret_cast<LynxKryptonFrameServiceWrapper*>(wrapper_ptr);
    delete wrapper;
}

void LynxKryptonFrameService_nativeDoRequestVSync(
    JNIEnv* env,
    jobject jcaller,
    jlong wrapper_ptr) {
    (void)env;
    if (wrapper_ptr == 0) {
        return;
    }
    auto* wrapper = reinterpret_cast<LynxKryptonFrameServiceWrapper*>(wrapper_ptr);
    if (!wrapper->service) {
        return;
    }

    // 0x004c30..0x004c84:
    //   ScopedGlobalJavaRef<jobject>(env, jcaller)
    //   Allocates 0x18-byte functor with vtable 0x0081a0 (operator() @ 0x004f34 -> "OnVSync" "(J)V")
    //   Calls FrameService->RequestVSync (vtable + 0x10 @ 0x004c78)
    jobject global_ref = jcaller;
    wrapper->service->RequestVSync([global_ref](int64_t frame_time_nanos) {
        (void)global_ref;
        // 0x004f34..0x004f68:
        //   Caches jmethodID at .bss 0x00c038 ("OnVSync", "(J)V")
        //   Invokes CallVoidMethodV(env, obj, method_id, frame_time_nanos) @ 0x004e74
        KryptonBssSegment& bss = GetKryptonBssState();
        if (bss.on_vsync_method == nullptr) {
            bss.on_vsync_method = reinterpret_cast<jmethodID>(0x1002);
        }
        std::lock_guard<std::mutex> lock(g_vsync_mutex);
        g_vsync_invocations.push_back(JavaVSyncInvocationRecord{
            RodataConstants::kMethodOnVSync,
            RodataConstants::kSigLongVoid,
            frame_time_nanos,
        });
    });
}

void LynxKryptonFrameService_nativeDoRegisterBeforeVSyncEndListener(
    JNIEnv* env,
    jobject jcaller,
    jlong wrapper_ptr) {
    (void)env;
    if (wrapper_ptr == 0) {
        return;
    }
    auto* wrapper = reinterpret_cast<LynxKryptonFrameServiceWrapper*>(wrapper_ptr);
    if (!wrapper->service) {
        return;
    }

    // 0x004cdc..0x004d2c:
    //   ScopedGlobalJavaRef<jobject>(env, jcaller)
    //   Allocates 0x18-byte functor with vtable 0x008150 (operator() @ 0x004e3c -> "OnBeforeVSyncEnd" "(J)V")
    //   Calls FrameService->RegisterBeforeVSyncEndListener (vtable + 0x20 @ 0x004d20)
    jobject global_ref = jcaller;
    wrapper->service->RegisterBeforeVSyncEndListener([global_ref](int64_t frame_time_nanos) {
        (void)global_ref;
        // 0x004e3c..0x004eb0:
        //   Caches jmethodID at .bss 0x00c030 ("OnBeforeVSyncEnd", "(J)V")
        //   Invokes CallVoidMethodV(env, obj, method_id, frame_time_nanos) @ 0x004e74
        KryptonBssSegment& bss = GetKryptonBssState();
        if (bss.on_before_vsync_end_method == nullptr) {
            bss.on_before_vsync_end_method = reinterpret_cast<jmethodID>(0x1001);
        }
        std::lock_guard<std::mutex> lock(g_vsync_mutex);
        g_vsync_invocations.push_back(JavaVSyncInvocationRecord{
            RodataConstants::kMethodOnBeforeVSyncEnd,
            RodataConstants::kSigLongVoid,
            frame_time_nanos,
        });
    });
}

// ============================================================================
// 4. `UICanvasSurfaceView_nativeCreateSurface` (`0x004f6c..0x004ff0`, 132 bytes)
//    Phương thức JNI `UICanvasSurfaceView_nativeCreateSurface` (`0x004f6c..0x004ff0`, 132 byte)
// ============================================================================

jlong UICanvasSurfaceView_nativeCreateSurface(
    JNIEnv* env,
    jclass clazz,
    jobject jsurface) {
    (void)clazz;

    // 0x004f6c..0x004fc4:
    //   ScopedJavaLocalFrame frame(env)
    //   if (jsurface == nullptr) return 0;
    //   x19 = ANativeWindow_fromSurface(env, jsurface) (0x005340)
    //   if (x19 == nullptr) return 0;
    //   x20 = operator new(0x20) (0x004fac)
    //   SurfaceWithAndroidNativeWindow(x20, x19, 0, 0) (0x005490)
    //   return reinterpret_cast<jlong>(x20);
    if (jsurface == nullptr) {
        return 0;
    }
    ANativeWindowMock* window = AcquireNativeWindowFromSurface(env, jsurface);
    if (window == nullptr) {
        return 0;
    }
    auto* surface = new SurfaceWithAndroidNativeWindow(window, 0, 0);
    return reinterpret_cast<jlong>(surface);
}

std::vector<JavaVSyncInvocationRecord> GetCapturedJavaVSyncInvocations() {
    std::lock_guard<std::mutex> lock(g_vsync_mutex);
    return g_vsync_invocations;
}

void ClearCapturedJavaVSyncInvocations() {
    std::lock_guard<std::mutex> lock(g_vsync_mutex);
    g_vsync_invocations.clear();
}

} // namespace lynx_krypton
} // namespace opencut
} // namespace nextai
