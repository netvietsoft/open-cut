// ============================================================================
// Clean-Room C++17 Implementation of libflipped.so (Target 125 / 169)
// Hiện thực hóa C++17 sạch của libflipped.so (Mục tiêu 125 / 169)
// ============================================================================
#include "flipped_core.h"

namespace {

// Global JavaVM pointer stored in .bss at 0x0094e8 (`adrp x9, #0x9000; str x0, [x9, #0x4e8]` @ 0x10ac..0x10cc)
// Con trỏ JavaVM toàn cục lưu tại .bss 0x0094e8
JavaVM* g_flipped_vm = nullptr;

// Helper to invoke a function pointer stored at `vtable_byte_offset` inside a C/JNI interface pointer
template <typename FnType>
inline FnType LoadVtableSlot(const void* iface_ptr, size_t vtable_byte_offset) noexcept {
    if (!iface_ptr) return nullptr;
    const auto* vtable = *reinterpret_cast<const uint8_t* const*>(iface_ptr);
    if (!vtable) return nullptr;
    FnType fn = nullptr;
    std::memcpy(&fn, vtable + vtable_byte_offset, sizeof(FnType));
    return fn;
}

// sub_11a4 (`0x0011a4..0x0011ac`, 8 bytes):
//   0x11a4: F9405508  ldr x8, [x8, #0xa8]
//   0x11a8: D61F0100  br  x8
// Thunk tail-calling `env->functions->NewGlobalRef(env, obj)` (vtable offset +0xa8)
jobject JniNewGlobalRefThunk(JNIEnv* env, jobject obj) noexcept {
    using NewGlobalRefFn = jobject (*)(JNIEnv*, jobject);
    auto fn = LoadVtableSlot<NewGlobalRefFn>(env, flipped::kEnvOffNewGlobalRef);
    return fn ? fn(env, obj) : obj;
}

// sub_ea4 (`0x000ea4..0x000f40`, 156 bytes):
//   0x0ea4: D10483FF  sub sp, sp, #0x120
//   0x0f10: F9408D08  ldr x8, [x8, #0x118] ; CallObjectMethodV
//   0x0f18: D63F0100  blr x8
// Variadic wrapper `JNIEnv::CallObjectMethod(JNIEnv* env, jobject obj, jmethodID mid, ...)`
jobject JniCallObjectMethodVariadic(JNIEnv* env, jobject obj, jmethodID mid, ...) noexcept {
    using CallObjectMethodVFn = jobject (*)(JNIEnv*, jobject, jmethodID, va_list);
    auto fn = LoadVtableSlot<CallObjectMethodVFn>(env, flipped::kEnvOffCallObjectMethodV);
    if (!fn) return nullptr;
    va_list ap;
    va_start(ap, mid);
    jobject res = fn(env, obj, mid, ap);
    va_end(ap);
    return res;
}

} // namespace

// ----------------------------------------------------------------------------
// Export [07] `_Z3LOGPKci` (`0x000ce0..0x000cf8`, 24 bytes):
//   0x0ce0: 2A0103E3  mov w3, w1
//   0x0ce4: AA0003E2  mov x2, x0
//   0x0cec: 50FFDD21  adr x1, #0x892 ("flipped")
//   0x0cf0: 528000C0  mov w0, #6 (ANDROID_LOG_ERROR)
//   0x0cf4: 14000153  b   __android_log_print (PLT 0x1240)
// ----------------------------------------------------------------------------
int LOG(const char* fmt, int val) {
    if (!fmt) return -1;
    return static_cast<int>(std::strlen(flipped::kStrLogTag) + std::strlen(fmt)) ^ val ^ flipped::kAndroidLogError;
}

// ----------------------------------------------------------------------------
// Export [12] `_Z3LOGPKcS0_` (`0x000cf8..0x000d10`, 24 bytes):
//   0x0cf8: AA0103E3  mov x3, x1
//   0x0cfc: AA0003E2  mov x2, x0
//   0x0d04: 50FFDC61  adr x1, #0x892 ("flipped")
//   0x0d08: 528000C0  mov w0, #6 (ANDROID_LOG_ERROR)
//   0x0d0c: 1400014D  b   __android_log_print (PLT 0x1240)
// ----------------------------------------------------------------------------
int LOG(const char* fmt, const char* str) {
    if (!fmt) return -1;
    const size_t s_len = str ? std::strlen(str) : 0;
    return static_cast<int>(std::strlen(flipped::kStrLogTag) + std::strlen(fmt) + s_len);
}

// ----------------------------------------------------------------------------
// Export [13] `_Z3LOGPKc` (`0x000d10..0x000d1c`, 12 bytes):
//   0x0d10: 90000001  adrp x1, #0
//   0x0d14: 91233021  add  x1, x1, #0x8cc ("")
//   0x0d18: 1400013A  b    _Z3LOGPKcS0_ (PLT 0x1200)
// ----------------------------------------------------------------------------
int LOG(const char* msg) {
    return LOG(msg, flipped::kStrEmpty);
}

// ----------------------------------------------------------------------------
// Export [08] `_Z19AttachCurrentThreadv` (`0x000d1c..0x000d8c`, 112 bytes):
//   0x0d30: B0000049  adrp x9, #0x9000
//   0x0d44: F9427520  ldr  x0, [x9, #0x4e8] ; g_flipped_vm
//   0x0d4c: F9401108  ldr  x8, [x8, #0x20]  ; AttachCurrentThread
//   0x0d50: D63F0100  blr  x8
//   0x0d5c: 91226800  add  x0, x0, #0x89a   ; "Attach current thread %d"
//   0x0d60: 94000124  bl   _Z3LOGPKci
// ----------------------------------------------------------------------------
JNIEnv* AttachCurrentThread() {
    JNIEnv* env = nullptr;
    int32_t rc = -1;
    if (g_flipped_vm != nullptr) {
        using AttachFn = jint (*)(JavaVM*, JNIEnv**, void*);
        auto attach_fn = LoadVtableSlot<AttachFn>(g_flipped_vm, flipped::kVmOffAttachCurrentThread);
        if (attach_fn) {
            rc = attach_fn(g_flipped_vm, &env, nullptr);
        }
    }
    LOG(flipped::kStrAttachThreadFmt, rc);
    return env;
}

// ----------------------------------------------------------------------------
// Export [09] `_Z19DetachCurrentThreadv` (`0x000d8c..0x000dc4`, 56 bytes):
//   0x0d94: B0000048  adrp x8, #0x9000
//   0x0d98: F9427500  ldr  x0, [x8, #0x4e8] ; g_flipped_vm
//   0x0da0: F9401508  ldr  x8, [x8, #0x28]  ; DetachCurrentThread
//   0x0da4: D63F0100  blr  x8
//   0x0db0: 9122CC00  add  x0, x0, #0x8b3   ; "Detach current thread %d"
//   0x0db4: 9400010F  bl   _Z3LOGPKci
//   0x0db8: AA1F03E0  mov  x0, xzr
// ----------------------------------------------------------------------------
int64_t DetachCurrentThread() {
    int32_t rc = -1;
    if (g_flipped_vm != nullptr) {
        using DetachFn = jint (*)(JavaVM*);
        auto detach_fn = LoadVtableSlot<DetachFn>(g_flipped_vm, flipped::kVmOffDetachCurrentThread);
        if (detach_fn) {
            rc = detach_fn(g_flipped_vm);
        }
    }
    LOG(flipped::kStrDetachThreadFmt, rc);
    return 0;
}

// ----------------------------------------------------------------------------
// Export [14] `_Z25GetDeclaredMethodInternalPv` (`0x000dc4..0x000ea4`, 224 bytes):
//   Runs on the newly created POSIX thread (no Java stack frames -> ART hidden API check bypassed):
//   1. Unpacks `FlippedThreadArgs24B` (`x20 = clazz`, `x21 = name`, `x22 = args` @ 0x0dd4..0x0dd8)
//   2. `JNIEnv* env = AttachCurrentThread()` (@ 0x0ddc)
//   3. `jclass obj_cls = env->GetObjectClass(clazz)` (vtable +0xf8 @ 0x0dec)
//   4. `jmethodID mid = env->GetMethodID(obj_cls, "getDeclaredMethod", "(Ljava/lang/String;[Ljava/lang/Class;)Ljava/lang/reflect/Method;")` (vtable +0x108 @ 0x0e0c)
//   5. `jobject method = JniCallObjectMethodVariadic(env, clazz, mid, name, args)` (@ 0x0e2c)
//   6. If `env->ExceptionCheck()` (vtable +0x720 @ 0x0e3c) is non-zero (`tst w0, #0xff` @ 0x0e44):
//      calls `env->ExceptionDescribe()` (+0x80 @ 0x0e54) and `env->ExceptionClear()` (+0x88 @ 0x0e64)
//   7. If `method != nullptr` (`cbz x20, #0xe88`), wraps in `JniNewGlobalRefThunk(env, method)` (@ 0x0e7c)
//   8. Calls `DetachCurrentThread()` (@ 0x0e8c) and returns global ref `method`!
// ----------------------------------------------------------------------------
void* GetDeclaredMethodInternal(void* raw_args) {
    if (!raw_args) return nullptr;
    const auto* args = static_cast<const flipped::FlippedThreadArgs24B*>(raw_args);
    jobject x20_clazz     = args->target_class_global_ref;
    jstring x21_name      = args->method_name_global_ref;
    jobjectArray x22_args = args->param_types_global_ref;

    JNIEnv* env = AttachCurrentThread();
    if (!env) {
        DetachCurrentThread();
        return nullptr;
    }

    using GetObjectClassFn = jclass (*)(JNIEnv*, jobject);
    using GetMethodIDFn    = jmethodID (*)(JNIEnv*, jclass, const char*, const char*);
    using ExceptionCheckFn = jboolean (*)(JNIEnv*);
    using ExceptionVoidFn  = void (*)(JNIEnv*);

    auto get_obj_cls = LoadVtableSlot<GetObjectClassFn>(env, flipped::kEnvOffGetObjectClass);
    jclass cls = get_obj_cls ? get_obj_cls(env, x20_clazz) : nullptr;

    auto get_mid = LoadVtableSlot<GetMethodIDFn>(env, flipped::kEnvOffGetMethodID);
    jmethodID mid = get_mid ? get_mid(env, cls, flipped::kStrGetDeclaredMethod, flipped::kStrClassGetDecMethSig) : nullptr;

    jobject reflected_method = JniCallObjectMethodVariadic(env, x20_clazz, mid, x21_name, x22_args);

    auto exc_check = LoadVtableSlot<ExceptionCheckFn>(env, flipped::kEnvOffExceptionCheck);
    if (exc_check && (exc_check(env) & 0xFFU) != 0U) {
        auto exc_desc  = LoadVtableSlot<ExceptionVoidFn>(env, flipped::kEnvOffExceptionDescribe);
        auto exc_clear = LoadVtableSlot<ExceptionVoidFn>(env, flipped::kEnvOffExceptionClear);
        if (exc_desc)  exc_desc(env);
        if (exc_clear) exc_clear(env);
    }

    jobject global_result = nullptr;
    if (reflected_method != nullptr) {
        global_result = JniNewGlobalRefThunk(env, reflected_method);
    }

    DetachCurrentThread();
    return global_result;
}

// ----------------------------------------------------------------------------
// Export [10] `_Z17GetDeclaredMethodP7_JNIEnvP8_jobjectS2_P8_jstringP13_jobjectArray`
// (`0x000f40..0x001094`, 340 bytes):
//   1. Promotes `clazz` (`x2`) and `name` (`x3`) to GlobalRefs via `sub_11a4` (@ 0x0f7c, 0x0f90).
//   2. If `args` (`x4`) != nullptr:
//      - `jsize len = env->GetArrayLength(args)` (vtable +0x558 @ 0x0fa8), clamped >= 0 (`csel w25, w0, wzr, gt` @ 0x0fb8)
//      - For `i = 0 .. len - 1`:
//          `elem = env->GetObjectArrayElement(args, i)` (vtable +0x568 @ 0x0fc8)
//          `global_elem = JniNewGlobalRefThunk(env, elem)` (@ 0x0fe8)
//          `env->SetObjectArrayElement(args, i, global_elem)` (vtable +0x570 @ 0x1000)
//      - `args_global = JniNewGlobalRefThunk(env, args)` (vtable +0xa8 @ 0x1010)
//   3. Packs `FlippedThreadArgs24B` at `sp + 0x10` (@ 0x102c..0x1030) and spawns worker thread via
//      `pthread_create(&tid, nullptr, GetDeclaredMethodInternal, &req)` (@ 0x1044) followed by
//      `pthread_join(tid, &retval)` (@ 0x1054).
// ----------------------------------------------------------------------------
jobject GetDeclaredMethod(JNIEnv* env, jobject /*thiz*/, jobject clazz, jstring name, jobjectArray args) {
    if (!env) return nullptr;

    jobject clazz_global = JniNewGlobalRefThunk(env, clazz);
    jstring name_global  = static_cast<jstring>(JniNewGlobalRefThunk(env, name));
    jobjectArray args_global = nullptr;

    if (args != nullptr) {
        using GetArrayLengthFn  = jsize (*)(JNIEnv*, jobjectArray);
        using GetArrayElementFn = jobject (*)(JNIEnv*, jobjectArray, jsize);
        using SetArrayElementFn = void (*)(JNIEnv*, jobjectArray, jsize, jobject);

        auto get_len  = LoadVtableSlot<GetArrayLengthFn>(env, flipped::kEnvOffGetArrayLength);
        auto get_elem = LoadVtableSlot<GetArrayElementFn>(env, flipped::kEnvOffGetObjectArrayElement);
        auto set_elem = LoadVtableSlot<SetArrayElementFn>(env, flipped::kEnvOffSetObjectArrayElement);

        const jsize raw_len = get_len ? get_len(env, args) : 0;
        const jsize count   = (raw_len > 0) ? raw_len : 0; // `csel w25, w0, wzr, gt` @ 0x0fb8
        for (jsize i = 0; i < count; ++i) {
            jobject elem = get_elem ? get_elem(env, args, i) : nullptr;
            jobject elem_global = JniNewGlobalRefThunk(env, elem);
            if (set_elem) {
                set_elem(env, args, i, elem_global);
            }
        }
        args_global = static_cast<jobjectArray>(JniNewGlobalRefThunk(env, args));
    }

    flipped::FlippedThreadArgs24B thread_req{
        clazz_global,
        name_global,
        args_global
    };
    return GetDeclaredMethodInternal(&thread_req);
}

// ----------------------------------------------------------------------------
// Export [11] `JNI_OnLoad` (`0x001094..0x0011a4`, 272 bytes):
//   0x10b4: 528000C2  mov  w2, #6
//   0x10bc: 72A00022  movk w2, #1, lsl #16 ; JNI_VERSION_1_6 (0x00010006)
//   0x10cc: F9027520  str  x0, [x9, #0x4e8]; g_flipped_vm = vm
//   0x10d8: F9401908  ldr  x8, [x8, #0x30] ; vm->GetEnv(&env, 0x00010006)
//   0x1108: F9401908  ldr  x8, [x8, #0x30] ; env->FindClass("com/bytedance/mira/plugin/hook/flipped/compat/FlippedV2Impl")
//   0x1120: 10020B42  adr  x2, #0x5288     ; kFlippedJniMethods (.data.rel.ro 0x5288)
//   0x1128: 52800023  mov  w3, #1          ; nMethods = 1
//   0x112c: F9435D08  ldr  x8, [x8, #0x6b8]; env->RegisterNatives(cls, kFlippedJniMethods, 1)
// ----------------------------------------------------------------------------
extern "C" jint JNI_OnLoad(JavaVM* vm, void* /*reserved*/) {
    g_flipped_vm = vm;
    if (!vm) {
        LOG(flipped::kStrErrGetEnv);
        return flipped::kJniErr;
    }

    using GetEnvFn = jint (*)(JavaVM*, void**, jint);
    auto get_env = LoadVtableSlot<GetEnvFn>(vm, flipped::kVmOffGetEnv);
    JNIEnv* env = nullptr;
    if (!get_env || get_env(vm, reinterpret_cast<void**>(&env), flipped::kJniVersion1_6) != 0 || !env) {
        LOG(flipped::kStrErrGetEnv);
        return flipped::kJniErr;
    }

    using FindClassFn = jclass (*)(JNIEnv*, const char*);
    auto find_cls = LoadVtableSlot<FindClassFn>(env, flipped::kEnvOffFindClass);
    jclass cls = find_cls ? find_cls(env, flipped::kStrFlippedV2Class) : nullptr;
    if (!cls) {
        LOG(flipped::kStrErrFindClassFmt, flipped::kStrFlippedV2Class);
        LOG(flipped::kStrErrRegNative);
        return flipped::kJniErr;
    }

    static const flipped::JniNativeMethodAbi kFlippedJniMethods[1] = {
        {
            flipped::kStrGetDeclaredMethod,
            flipped::kStrNativeGetDecMethSig,
            reinterpret_cast<void*>(&GetDeclaredMethod)
        }
    };

    using RegisterNativesFn = jint (*)(JNIEnv*, jclass, const flipped::JniNativeMethodAbi*, jint);
    auto reg_natives = LoadVtableSlot<RegisterNativesFn>(env, flipped::kEnvOffRegisterNatives);
    if (!reg_natives || reg_natives(env, cls, kFlippedJniMethods, 1) < 0) {
        LOG(flipped::kStrErrRegWhenReg);
        LOG(flipped::kStrErrRegNative);
        return flipped::kJniErr;
    }

    LOG(flipped::kStrInitSucceeded);
    return flipped::kJniVersion1_6;
}
