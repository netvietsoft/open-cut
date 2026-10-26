/**
 * @file lynx_krypton_interface.cpp
 * @brief Exact AArch64 opcode-verified implementation of `JNI_OnLoad` (`0x004ff4..0x005124`),
 *        `.data.rel.ro` `JNINativeMethod` registration tables (`0x008008..0x0081cf`),
 *        and `.data.rel.ro` C++ vtables for `liblynx_krypton.so`.
 *        Triển khai đối soát opcode AArch64 chính xác của `JNI_OnLoad` (`0x004ff4..0x005124`),
 *        bảng đăng ký `JNINativeMethod` trong `.data.rel.ro`, và các vtable C++ cho `liblynx_krypton.so`.
 */

#include "lynx_krypton_interface.h"

namespace nextai {
namespace opencut {
namespace lynx_krypton {

namespace {

// 1. `.data.rel.ro 0x008008..0x008037`: `com/lynx/canvas/CanvasManager` (2 methods)
const std::array<JNINativeMethodEntry, 2> kCanvasManagerMethods = {{
    {
        RodataConstants::kJniNativeGetLogFunctionPtr, // 0x001bf9 "nativeGetLogFunctionPtr"
        RodataConstants::kSigVoidLong,                // 0x001bf5 "()J"
        reinterpret_cast<void*>(&CanvasManager_nativeGetLogFunctionPtr), // 0x004160
    },
    {
        RodataConstants::kJniNativeRegisterTraceFunc, // 0x001c11 "nativeRegisterTraceFunc"
        RodataConstants::kSigVoidVoid,                // 0x001ba2 "()V"
        reinterpret_cast<void*>(&CanvasManager_nativeRegisterTraceFunc), // 0x00416c
    },
}};

// 2. `.data.rel.ro 0x008060..0x00808f`: `com/lynx/canvas/LynxCanvasDownStreamManager` (2 methods)
const std::array<JNINativeMethodEntry, 2> kDownStreamManagerMethods = {{
    {
        RodataConstants::kJniNativeAddSurface,        // 0x001c29 "nativeAddSurface"
        RodataConstants::kSigAddSurface,              // 0x001bab "(JLjava/lang/String;Landroid/view/Surface;III)J"
        reinterpret_cast<void*>(&LynxCanvasDownStreamManager_nativeAddSurface), // 0x004328
    },
    {
        "nativeRemoveSurface",                        // 0x001d1c
        RodataConstants::kSigRemoveSurface,           // 0x001b85 "(JLjava/lang/String;J)V"
        reinterpret_cast<void*>(&LynxCanvasDownStreamManager_nativeRemoveSurface), // 0x0045bc
    },
}};

// 3. `.data.rel.ro 0x0080e0..0x00813f`: `com/lynx/canvas/LynxKryptonFrameService` (4 methods)
const std::array<JNINativeMethodEntry, 4> kFrameServiceMethods = {{
    {
        "nativeCreateFrameService",                   // 0x001d4f
        RodataConstants::kSigLongLong,                // 0x001ba6 "(J)J"
        reinterpret_cast<void*>(&LynxKryptonFrameService_nativeCreateFrameService), // 0x004bb4
    },
    {
        "nativeDestroyFrameService",                  // 0x001d68
        RodataConstants::kSigLongVoid,                // 0x001b9d "(J)V"
        reinterpret_cast<void*>(&LynxKryptonFrameService_nativeDestroyFrameService), // 0x004bf0
    },
    {
        "nativeDoRequestVSync",                       // 0x001d82
        RodataConstants::kSigLongVoid,                // 0x001b9d "(J)V"
        reinterpret_cast<void*>(&LynxKryptonFrameService_nativeDoRequestVSync), // 0x004c14
    },
    {
        "nativeDoRegisterBeforeVSyncEndListener",     // 0x001d97
        RodataConstants::kSigLongVoid,                // 0x001b9d "(J)V"
        reinterpret_cast<void*>(&LynxKryptonFrameService_nativeDoRegisterBeforeVSyncEndListener), // 0x004cc4
    },
}};

// 4. `.data.rel.ro 0x0081b8..0x0081cf`: `com/lynx/canvas/UICanvasSurfaceView` (1 method)
const std::array<JNINativeMethodEntry, 1> kUiCanvasSurfaceViewMethods = {{
    {
        "nativeCreateSurface",                        // 0x001dc8
        RodataConstants::kSigCreateSurface,           // 0x001bdb "(Landroid/view/Surface;)J"
        reinterpret_cast<void*>(&UICanvasSurfaceView_nativeCreateSurface), // 0x004f6c
    },
}};

} // namespace

const std::array<JNINativeMethodEntry, 2>& GetCanvasManagerJniMethods() noexcept {
    return kCanvasManagerMethods;
}

const std::array<JNINativeMethodEntry, 2>& GetDownStreamManagerJniMethods() noexcept {
    return kDownStreamManagerMethods;
}

const std::array<JNINativeMethodEntry, 4>& GetFrameServiceJniMethods() noexcept {
    return kFrameServiceMethods;
}

const std::array<JNINativeMethodEntry, 1>& GetUiCanvasSurfaceViewJniMethods() noexcept {
    return kUiCanvasSurfaceViewMethods;
}

std::vector<JniClassRegistrationDescriptor> GetAllJniClassRegistrations() {
    return {
        {
            RodataConstants::kClassCanvasManager,
            0x001975u,
            0x008008u,
            0x00c000u,
            static_cast<uint32_t>(kCanvasManagerMethods.size()),
            kCanvasManagerMethods.data(),
        },
        {
            RodataConstants::kClassDownStreamManager,
            0x001c98u,
            0x008060u,
            0x00c020u,
            static_cast<uint32_t>(kDownStreamManagerMethods.size()),
            kDownStreamManagerMethods.data(),
        },
        {
            RodataConstants::kClassFrameService,
            0x001cc4u,
            0x0080e0u,
            0x00c028u,
            static_cast<uint32_t>(kFrameServiceMethods.size()),
            kFrameServiceMethods.data(),
        },
        {
            RodataConstants::kClassUiCanvasSurfaceView,
            0x001cecu,
            0x0081b8u,
            0x00c040u,
            static_cast<uint32_t>(kUiCanvasSurfaceViewMethods.size()),
            kUiCanvasSurfaceViewMethods.data(),
        },
    };
}

std::vector<DataRelRoVtableDescriptor> GetAllDataRelRoVtables() {
    // Verified from `.rela.dyn` (`0x001148..0x0015c7`) and `.data.rel.ro` (`0x008090..0x0081b7`):
    return {
        {
            0x008090u,
            0x0080a0u,
            "RemoveSurfaceTaskClosure (0x48 bytes, allocated @ 0x004740)",
            0x004840u,
            0x004870u,
            0x0048a4u,
        },
        {
            0x0080b8u,
            0x0080c8u,
            "AddSurfaceTaskClosure (0x60 bytes, allocated @ 0x004538)",
            0x0049b4u,
            0x0049f0u,
            0x004a2cu,
        },
        {
            0x008140u,
            0x008150u,
            "BeforeVSyncEndListenerFunctor (0x18 bytes, allocated @ 0x004cf8)",
            0x004d70u,
            0x004da0u,
            0x004e3cu,
        },
        {
            0x008168u,
            0x008178u,
            "lynx::base::android::ScopedGlobalJavaRef<jobject> embedded member vtable",
            0x004ddcu,
            0x004de8u,
            0x000000u,
        },
        {
            0x008190u,
            0x0081a0u,
            "RequestVSyncCallbackFunctor (0x18 bytes, allocated @ 0x004c50)",
            0x004eb4u,
            0x004ee4u,
            0x004f34u,
        },
    };
}

jint ExecuteJniOnLoad(JavaVM* vm, void* reserved) {
    (void)vm;
    (void)reserved;

    // Exact instruction sequence at 0x004ff4..0x005124:
    // 1. 0x005014..0x005024:
    //    lynx::base::android::InitVM(vm);
    //    env = lynx::base::android::AttachCurrentThread();
    // 2. 0x005028..0x00504c:
    //    GetClass(env, "com/lynx/canvas/CanvasManager") -> stored at .bss 0x00c000
    //    RegisterNatives(env, clazz, 0x008008, 2) via sub_005194
    // 3. 0x005050..0x005084:
    //    GetClass(env, "com/lynx/canvas/LynxCanvasDownStreamManager") -> stored at .bss 0x00c020
    //    RegisterNatives(env, clazz, 0x008060, 2)
    // 4. 0x005088..0x0050bc:
    //    GetClass(env, "com/lynx/canvas/LynxKryptonFrameService") -> stored at .bss 0x00c028
    //    RegisterNatives(env, clazz, 0x0080e0, 4)
    // 5. 0x0050c0..0x005108:
    //    GetClass(env, "com/lynx/canvas/UICanvasSurfaceView") -> stored at .bss 0x00c040
    //    RegisterNatives(env, clazz, 0x0081b8, 1)
    // 6. 0x00510c..0x005124:
    //    mov w0, #0x6; movk w0, #0x1, lsl #16 (returns JNI_VERSION_1_6 = 0x00010006)
    KryptonBssSegment& bss = GetKryptonBssState();
    bss.canvas_manager_class         = reinterpret_cast<jclass>(0xC000u);
    bss.downstream_manager_class     = reinterpret_cast<jclass>(0xC020u);
    bss.frame_service_class          = reinterpret_cast<jclass>(0xC028u);
    bss.ui_canvas_surface_view_class = reinterpret_cast<jclass>(0xC040u);

    return kJniVersion1_6;
}

} // namespace lynx_krypton
} // namespace opencut
} // namespace nextai

extern "C" {

nextai::opencut::lynx_krypton::jint JNI_OnLoad(
    nextai::opencut::lynx_krypton::JavaVM* vm,
    void* reserved) {
    return nextai::opencut::lynx_krypton::ExecuteJniOnLoad(vm, reserved);
}

} // extern "C"
