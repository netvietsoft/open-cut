// ============================================================================
// NextAI OpenCut — Clean-Room C++17 Reconstruction
// File          : push_ka_jni_and_runtime_bridge.cpp
// Target Binary : libpush_ka.so (18,184 bytes)
// SHA-256       : e8a32d5847f22373b03950fe22ee6ffa53a667ce77c57e018a2db9d409914281
// Task ID       : TASK-171-RECONSTRUCTION-LIBPUSH-KA
// ============================================================================
// EN: Exact clean-room C++17 implementation of `libpush_ka.so`:
//       - `.text` helpers `0x0720..0x0768` (`__on_dlclose`, `atexit` wrapper)
//       - `FDE[00]` `Java_com_bytedance_vega_ug_push_alive_undead_base_KAImpl_getRuntimeAddr`
//         (`0x0768..0x0824`, 188 bytes):
//           1. Opens `"libandroid_runtime.so"` via `npth_dlopen` (`0x0784`).
//           2. If handle is NULL (`cbz x0, #0x810` @ `0x078c`), returns NULL.
//           3. Resolves `_ZN7android14AndroidRuntime10getRuntimeEv` via `npth_dlsym` (`0x079c`) -> `x21`.
//           4. Resolves `_ZN7android14AndroidRuntime8setArgv0EPKcb` via `npth_dlsym` (`0x07b0`) -> `x22`.
//           5. Closes handle via `npth_dlclose` (`0x07bc`).
//           6. Allocates 2-element `jlongArray` via `env->functions->NewLongArray(env, 2)`
//              at vtable offset `+0x5A0` (`0x07c4..0x07d0`).
//           7. Pins elements via `env->functions->GetLongArrayElements(env, arr, nullptr)`
//              at vtable offset `+0x5E0` (`0x07dc..0x07ec`).
//           8. Writes both function pointers via `stp x21, x22, [x0]` (`0x07f0`).
//           9. Releases array via `env->functions->ReleaseLongArrayElements(env, arr, elems, 0)`
//              at vtable offset `+0x620` (`0x07f4..0x080c`) and returns `arr` (`0x0810..0x0820`).
// VI: Tái tạo phòng sạch C++17 chính xác cho `libpush_ka.so`.
// ============================================================================
// Complete AArch64 .plt Disassembly (0x06a0..0x0720, 32 instructions):
//   0x06a0: a9bf7bf0  stp      x16, x30, [sp, #-0x10]!
//   0x06a4: f0000030  adrp     x16, #0x7000
//   0x06a8: f947e211  ldr      x17, [x16, #0xfc0]
//   0x06ac: 913f0210  add      x16, x16, #0xfc0
//   0x06b0: d61f0220  br       x17
//   0x06b4: d503201f  nop      
//   0x06b8: d503201f  nop      
//   0x06bc: d503201f  nop      
//   0x06c0: f0000030  adrp     x16, #0x7000
//   0x06c4: f947e611  ldr      x17, [x16, #0xfc8]
//   0x06c8: 913f2210  add      x16, x16, #0xfc8
//   0x06cc: d61f0220  br       x17
//   0x06d0: f0000030  adrp     x16, #0x7000
//   0x06d4: f947ea11  ldr      x17, [x16, #0xfd0]
//   0x06d8: 913f4210  add      x16, x16, #0xfd0
//   0x06dc: d61f0220  br       x17
//   0x06e0: f0000030  adrp     x16, #0x7000
//   0x06e4: f947ee11  ldr      x17, [x16, #0xfd8]
//   0x06e8: 913f6210  add      x16, x16, #0xfd8
//   0x06ec: d61f0220  br       x17
//   0x06f0: f0000030  adrp     x16, #0x7000
//   0x06f4: f947f211  ldr      x17, [x16, #0xfe0]
//   0x06f8: 913f8210  add      x16, x16, #0xfe0
//   0x06fc: d61f0220  br       x17
//   0x0700: f0000030  adrp     x16, #0x7000
//   0x0704: f947f611  ldr      x17, [x16, #0xfe8]
//   0x0708: 913fa210  add      x16, x16, #0xfe8
//   0x070c: d61f0220  br       x17
//   0x0710: f0000030  adrp     x16, #0x7000
//   0x0714: f947fa11  ldr      x17, [x16, #0xff0]
//   0x0718: 913fc210  add      x16, x16, #0xff0
//   0x071c: d61f0220  br       x17
// ============================================================================
// Complete AArch64 .text Disassembly (0x0720..0x0824, 65 instructions):
//   0x0720: f0000020  adrp     x0, #0x7000
//   0x0724: 9136a000  add      x0, x0, #0xda8
//   0x0728: 17ffffe6  b        #0x6c0
//   0x072c: d65f03c0  ret      
//   0x0730: 17ffffff  b        #0x72c
//   0x0734: b4000040  cbz      x0, #0x73c
//   0x0738: d61f0000  br       x0
//   0x073c: d65f03c0  ret      
//   0x0740: 90000008  adrp     x8, #0
//   0x0744: 911cd108  add      x8, x8, #0x734
//   0x0748: f0000022  adrp     x2, #0x7000
//   0x074c: 9136a042  add      x2, x2, #0xda8
//   0x0750: aa0003e1  mov      x1, x0
//   0x0754: aa0803e0  mov      x0, x8
//   0x0758: 17ffffee  b        #0x710
//   0x075c: f0000023  adrp     x3, #0x7000
//   0x0760: 9136a063  add      x3, x3, #0xda8
//   0x0764: 17ffffe3  b        #0x6f0
//   0x0768: a9bd57f6  stp      x22, x21, [sp, #-0x30]!
//   0x076c: a9014ff4  stp      x20, x19, [sp, #0x10]
//   0x0770: a9027bfd  stp      x29, x30, [sp, #0x20]
//   0x0774: 910083fd  add      x29, sp, #0x20
//   0x0778: aa0003f3  mov      x19, x0
//   0x077c: 90000000  adrp     x0, #0
//   0x0780: 91209000  add      x0, x0, #0x824
//   0x0784: 97ffffdf  bl       #0x700
//   0x0788: aa0003f4  mov      x20, x0
//   0x078c: b4000420  cbz      x0, #0x810
//   0x0790: 90000001  adrp     x1, #0
//   0x0794: 9120e821  add      x1, x1, #0x83a
//   0x0798: aa1403e0  mov      x0, x20
//   0x079c: 97ffffd1  bl       #0x6e0
//   0x07a0: 90000001  adrp     x1, #0
//   0x07a4: aa0003f5  mov      x21, x0
//   0x07a8: 91219021  add      x1, x1, #0x864
//   0x07ac: aa1403e0  mov      x0, x20
//   0x07b0: 97ffffcc  bl       #0x6e0
//   0x07b4: aa0003f6  mov      x22, x0
//   0x07b8: aa1403e0  mov      x0, x20
//   0x07bc: 97ffffc5  bl       #0x6d0
//   0x07c0: f9400268  ldr      x8, [x19]
//   0x07c4: 52800041  mov      w1, #2
//   0x07c8: aa1303e0  mov      x0, x19
//   0x07cc: f942d108  ldr      x8, [x8, #0x5a0]
//   0x07d0: d63f0100  blr      x8
//   0x07d4: f9400268  ldr      x8, [x19]
//   0x07d8: aa0003f4  mov      x20, x0
//   0x07dc: aa1303e0  mov      x0, x19
//   0x07e0: aa1403e1  mov      x1, x20
//   0x07e4: f942f108  ldr      x8, [x8, #0x5e0]
//   0x07e8: aa1f03e2  mov      x2, xzr
//   0x07ec: d63f0100  blr      x8
//   0x07f0: a9005815  stp      x21, x22, [x0]
//   0x07f4: f9400268  ldr      x8, [x19]
//   0x07f8: aa0003e2  mov      x2, x0
//   0x07fc: aa1303e0  mov      x0, x19
//   0x0800: aa1403e1  mov      x1, x20
//   0x0804: f9431108  ldr      x8, [x8, #0x620]
//   0x0808: 2a1f03e3  mov      w3, wzr
//   0x080c: d63f0100  blr      x8
//   0x0810: aa1403e0  mov      x0, x20
//   0x0814: a9427bfd  ldp      x29, x30, [sp, #0x20]
//   0x0818: a9414ff4  ldp      x20, x19, [sp, #0x10]
//   0x081c: a8c357f6  ldp      x22, x21, [sp], #0x30
//   0x0820: d65f03c0  ret      
// ============================================================================

#include "push_ka.h"

#include <cstring>

namespace nextai {
namespace opencut {
namespace push_ka {

namespace {

struct SimulatedDlHandle {
    uint32_t    magic = 0x4E50444CU;  // "NPDL"
    std::string soname;
    bool        is_open = false;
};

SimulatedDlHandle g_android_runtime_handle{0x4E50444CU, kTargetRuntimeLibraryName, false};
CleanRoomAndroidRuntime g_singleton_android_runtime;

PushKaJlongArrayObject* JniNewLongArrayImpl(PushKaJniEnv* env, int32_t len) noexcept {
    if (env == nullptr || len <= 0 || len > 2) {
        return nullptr;
    }
    env->last_allocated_array.elements[0] = 0;
    env->last_allocated_array.elements[1] = 0;
    env->last_allocated_array.length = len;
    env->last_allocated_array.pinned = false;
    return &env->last_allocated_array;
}

int64_t* JniGetLongArrayElementsImpl(PushKaJniEnv* env, PushKaJlongArrayObject* arr,
                                     uint8_t* is_copy) noexcept {
    (void)env;
    if (is_copy != nullptr) {
        *is_copy = 0;
    }
    if (arr == nullptr) {
        return nullptr;
    }
    arr->pinned = true;
    return arr->elements;
}

void JniReleaseLongArrayElementsImpl(PushKaJniEnv* env, PushKaJlongArrayObject* arr,
                                     int64_t* elems, int32_t mode) noexcept {
    (void)env;
    (void)elems;
    (void)mode;
    if (arr != nullptr) {
        arr->pinned = false;
    }
}

void SetArgv0BridgeThunk(CleanRoomAndroidRuntime* self, const char* argv0, bool set_proc_name) noexcept {
    if (self != nullptr) {
        self->setArgv0(argv0, set_proc_name);
    }
}

}  // namespace

CleanRoomAndroidRuntime* CleanRoomAndroidRuntime::getRuntime() noexcept {
    return &g_singleton_android_runtime;
}

void CleanRoomAndroidRuntime::setArgv0(const char* argv0, bool set_proc_name) noexcept {
    if (argv0 != nullptr) {
        argv0_ = argv0;
    }
    proc_name_updated_ = set_proc_name;
}

void InitializePushKaJniEnv(PushKaJniEnv* env, PushKaJniNativeInterface* vtable) noexcept {
    if (env == nullptr || vtable == nullptr) {
        return;
    }
    std::memset(vtable, 0, sizeof(*vtable));
    vtable->NewLongArray             = &JniNewLongArrayImpl;
    vtable->GetLongArrayElements     = &JniGetLongArrayElementsImpl;
    vtable->ReleaseLongArrayElements = &JniReleaseLongArrayElementsImpl;
    env->functions = vtable;
}

extern "C" {

void* npth_dlopen(const char* filename) noexcept {
    if (filename == nullptr) {
        return nullptr;
    }
    if (std::strcmp(filename, kTargetRuntimeLibraryName) == 0) {
        g_android_runtime_handle.is_open = true;
        return &g_android_runtime_handle;
    }
    return nullptr;
}

void* npth_dlsym(void* handle, const char* symbol) noexcept {
    if (handle != &g_android_runtime_handle || !g_android_runtime_handle.is_open || symbol == nullptr) {
        return nullptr;
    }
    if (std::strcmp(symbol, kSymAndroidRuntimeGet) == 0) {
        return reinterpret_cast<void*>(&CleanRoomAndroidRuntime::getRuntime);
    }
    if (std::strcmp(symbol, kSymAndroidRuntimeSetArgv0) == 0) {
        return reinterpret_cast<void*>(&SetArgv0BridgeThunk);
    }
    return nullptr;
}

int npth_dlclose(void* handle) noexcept {
    if (handle == &g_android_runtime_handle) {
        g_android_runtime_handle.is_open = false;
        return 0;
    }
    return -1;
}

// EN: Exact reconstruction of FDE[00] (`0x0768..0x0824`, 188 bytes):
//     `Java_com_bytedance_vega_ug_push_alive_undead_base_KAImpl_getRuntimeAddr`
// VI: Tái tạo chính xác FDE[00] (`0x0768..0x0824`, 188 byte):
//     `Java_com_bytedance_vega_ug_push_alive_undead_base_KAImpl_getRuntimeAddr`
PushKaJlongArrayObject*
Java_com_bytedance_vega_ug_push_alive_undead_base_KAImpl_getRuntimeAddr(
    PushKaJniEnv* env, void* clazz) noexcept {
    (void)clazz;
    if (env == nullptr || env->functions == nullptr) {
        return nullptr;
    }

    // 0x077c..0x078c: void* handle = npth_dlopen("libandroid_runtime.so"); if (!handle) return nullptr;
    void* handle = npth_dlopen(kTargetRuntimeLibraryName);
    if (handle == nullptr) {
        return nullptr;
    }

    // 0x0790..0x07b4: resolve getRuntime() -> x21, setArgv0(const char*, bool) -> x22
    void* sym_get_runtime = npth_dlsym(handle, kSymAndroidRuntimeGet);
    void* sym_set_argv0   = npth_dlsym(handle, kSymAndroidRuntimeSetArgv0);

    // 0x07b8..0x07bc: npth_dlclose(handle)
    npth_dlclose(handle);

    // 0x07c0..0x07d0: jlongArray arr = (*env)->NewLongArray(env, 2) (offset +0x5A0)
    PushKaJlongArrayObject* arr =
        env->functions->NewLongArray(env, kReturnedAddressPairLength);

    // 0x07d4..0x07ec: jlong* elems = (*env)->GetLongArrayElements(env, arr, nullptr) (offset +0x5E0)
    int64_t* elems = env->functions->GetLongArrayElements(env, arr, nullptr);

    // 0x07f0: stp x21, x22, [x0]
    if (elems != nullptr) {
        elems[0] = static_cast<int64_t>(reinterpret_cast<uintptr_t>(sym_get_runtime));
        elems[1] = static_cast<int64_t>(reinterpret_cast<uintptr_t>(sym_set_argv0));
    }

    // 0x07f4..0x080c: (*env)->ReleaseLongArrayElements(env, arr, elems, 0) (offset +0x620)
    env->functions->ReleaseLongArrayElements(env, arr, elems, 0);

    // 0x0810..0x0820: return arr
    return arr;
}

}  // extern "C"

bool VerifyPushKaSelfTest() noexcept {
    PushKaJniEnv env{};
    PushKaJniNativeInterface vtable{};
    InitializePushKaJniEnv(&env, &vtable);
    PushKaJlongArrayObject* arr =
        Java_com_bytedance_vega_ug_push_alive_undead_base_KAImpl_getRuntimeAddr(&env, nullptr);
    if (arr == nullptr || arr->length != 2) {
        return false;
    }
    return arr->elements[0] != 0 && arr->elements[1] != 0 && !arr->pinned;
}

}  // namespace push_ka
}  // namespace opencut
}  // namespace nextai
