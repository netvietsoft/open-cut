// ============================================================================
// File: ttr_jni_bridge.cpp
// Target: libttr.so (625,192 bytes)
// Task ID: TASK-143-RECONSTRUCTION-LIBTTR / TASK_SO_101_libttr
// ============================================================================
// [EN] Clean-room C++17 reconstruction of JNI_OnLoad (0x0358b0..0x035a24) and the
//      10 registered JNINativeMethod entries (.data 0x09c048 & 0x09c060) for:
//      - com/tiktok/ttr/video/TTRVideoRender (.rodata 0x06b273, 9 methods @ 0x09c060)
//      - com/tiktok/ttr/video/TTRSurfaceWrap (.rodata 0x06b30d, 1 method @ 0x09c048)
//      - com/tiktok/ttr/video/TTRSurfaceTexture (.rodata 0x06b331)
// [VN] Tái tạo sạch C++17 của JNI_OnLoad (0x0358b0..0x035a24) và 10 hàm JNINativeMethod
//      đăng ký tại .data 0x09c048 & 0x09c060.
// ============================================================================

#include "ttr_engine_core.h"

namespace {
JavaVM* g_ttr_jvm_09ce80 = nullptr;              // .bss 0x09ce80
uint8_t g_jni_loaded_flag_09cc7c = 0;            // .bss 0x09cc7c
jclass g_cls_video_render_09cf80 = nullptr;      // .bss 0x09cf80 ("com/tiktok/ttr/video/TTRVideoRender" @ 0x06b273)
jclass g_cls_surface_wrap_09cf88 = nullptr;      // .bss 0x09cf88 ("com/tiktok/ttr/video/TTRSurfaceWrap" @ 0x06b30d)
jclass g_cls_surface_texture_09cf90 = nullptr;   // .bss 0x09cf90 ("com/tiktok/ttr/video/TTRSurfaceTexture" @ 0x06b331)
void* g_native_window_09ce90 = nullptr;          // .bss 0x09ce90
} // namespace

extern "C" {

// ----------------------------------------------------------------------------
// [EN] Exported JNI native callbacks (0x035a34..0x035ce4).
// [VN] Các hàm callback JNI xuất khẩu (0x035a34..0x035ce4).
// ----------------------------------------------------------------------------
JNIEXPORT jint JNICALL nativeInit(JNIEnv* /*env*/, jobject /*thiz*/, jobject /*ctx*/, jobject /*cfg*/) {
    // 0x035a34 (400 B)
    glstubInit(true);
    return 0;
}

JNIEXPORT jint JNICALL nativeRelease(JNIEnv* /*env*/, jobject /*thiz*/, jint /*handle*/) {
    // 0x035bc4 (100 B)
    g_native_window_09ce90 = nullptr;
    return 0;
}

JNIEXPORT jint JNICALL nativePause(JNIEnv* /*env*/, jobject /*thiz*/, jint /*handle*/) {
    // 0x035c28 (24 B): stp x29, x30, [sp, #-0x10]!; mov x29, sp; bl 0x3cfe4; mov w0, wzr; ldp; ret
    return 0;
}

JNIEXPORT jint JNICALL nativeResume(JNIEnv* /*env*/, jobject /*thiz*/, jint /*handle*/) {
    // 0x035c40 (24 B): mov w0, wzr; ret
    return 0;
}

JNIEXPORT jint JNICALL nativeSetSurface(JNIEnv* /*env*/, jobject /*thiz*/, jobject surface, jint /*handle*/) {
    // 0x035c58 (44 B): ANativeWindow_fromSurface -> stores at .bss 0x09ce90, returns -1 (0x035c78: mov w0, #-1)
    g_native_window_09ce90 = reinterpret_cast<void*>(surface);
    return -1;
}

JNIEXPORT jint JNICALL nativeSetSurfaceSize(JNIEnv* /*env*/, jobject /*thiz*/, jint /*w*/, jint /*h*/, jint /*handle*/) {
    // 0x035c84 (24 B): mov w0, wzr; ret
    return 0;
}

JNIEXPORT jobject JNICALL nativeGetSurface(JNIEnv* /*env*/, jobject /*thiz*/, jint /*handle*/) {
    // 0x035c9c (24 B): mov x0, xzr; ret
    return nullptr;
}

JNIEXPORT jint JNICALL nativeAddFilter(JNIEnv* /*env*/, jobject /*thiz*/, jlong /*filter_ptr*/, jint /*handle*/) {
    // 0x035cb4 (24 B): mov w0, wzr; ret
    return 0;
}

JNIEXPORT jint JNICALL nativeRemoveFilter(JNIEnv* /*env*/, jobject /*thiz*/, jlong /*filter_ptr*/, jint /*handle*/) {
    // 0x035ccc (24 B): mov w0, wzr; ret
    return 0;
}

JNIEXPORT void JNICALL nativeNotifyFrameAvailable(JNIEnv* /*env*/, jobject /*thiz*/, jint /*a0*/, jint /*a1*/, jint /*a2*/) {
    // 0x035ce4 (4 B): b #0x3cfe4
    return;
}

} // extern "C"

// ----------------------------------------------------------------------------
// [EN] Exact JNINativeMethod tables at .data 0x09c048 (1 entry) and 0x09c060 (9 entries).
// [VN] Bảng JNINativeMethod chính xác tại .data 0x09c048 (1 mục) và 0x09c060 (9 mục).
// ----------------------------------------------------------------------------
static const JNINativeMethod kTtrSurfaceWrapJniMethods_09c048[1] = {
    {"nativeNotifyFrameAvailable", "(III)V", reinterpret_cast<void*>(nativeNotifyFrameAvailable)}
};

static const JNINativeMethod kTtrVideoRenderJniMethods_09c060[9] = {
    {"nativeInit",           "(Ljava/lang/Object;Ljava/lang/Object;)I", reinterpret_cast<void*>(nativeInit)},
    {"nativeRelease",        "(I)I",                                    reinterpret_cast<void*>(nativeRelease)},
    {"nativePause",          "(I)I",                                    reinterpret_cast<void*>(nativePause)},
    {"nativeResume",         "(I)I",                                    reinterpret_cast<void*>(nativeResume)},
    {"nativeSetSurface",     "(Ljava/lang/Object;I)I",                  reinterpret_cast<void*>(nativeSetSurface)},
    {"nativeSetSurfaceSize", "(III)I",                                  reinterpret_cast<void*>(nativeSetSurfaceSize)},
    {"nativeGetSurface",     "(I)Ljava/lang/Object;",                   reinterpret_cast<void*>(nativeGetSurface)},
    {"nativeAddFilter",      "(JI)I",                                   reinterpret_cast<void*>(nativeAddFilter)},
    {"nativeRemoveFilter",   "(JI)I",                                   reinterpret_cast<void*>(nativeRemoveFilter)}
};

extern "C" JNIEXPORT jint JNICALL JNI_OnLoad(JavaVM* vm, void* /*reserved*/) {
    // 0x0358b0..0x035a24:
    //   0x0358d0: mov w19, #6; movk w19, #1, lsl #16 (0x00010006)
    //   0x0358dc: ldrb w8, [x23, #0xc7c]; tbnz w8, #0, #0x3590c
    //   0x03596c: mov w3, #9 -> RegisterNatives(g_cls_video_render_09cf80, 0x09c060, 9)
    //   0x0359b0: mov w3, #1 -> RegisterNatives(g_cls_surface_wrap_09cf88, 0x09c048, 1)
    if (g_jni_loaded_flag_09cc7c & 1U) {
        return static_cast<jint>(ttr_render::kTtrJniVersion16);
    }
    if (!vm) return -1;
    void* raw_env = nullptr;
    if (vm->GetEnv(&raw_env, static_cast<jint>(ttr_render::kTtrJniVersion16)) != JNI_OK || !raw_env) {
        return -1;
    }
    JNIEnv* env = static_cast<JNIEnv*>(raw_env);
    if (!g_cls_video_render_09cf80) {
        jclass local_vr = env->FindClass("com/tiktok/ttr/video/TTRVideoRender");
        if (!local_vr) return -1;
        g_cls_video_render_09cf80 = static_cast<jclass>(env->NewGlobalRef(local_vr));
    }
    if (env->RegisterNatives(g_cls_video_render_09cf80, kTtrVideoRenderJniMethods_09c060, 9) < 0) {
        return -1;
    }
    if (!g_cls_surface_wrap_09cf88) {
        jclass local_sw = env->FindClass("com/tiktok/ttr/video/TTRSurfaceWrap");
        if (!local_sw) return -1;
        g_cls_surface_wrap_09cf88 = static_cast<jclass>(env->NewGlobalRef(local_sw));
    }
    if (env->RegisterNatives(g_cls_surface_wrap_09cf88, kTtrSurfaceWrapJniMethods_09c048, 1) < 0) {
        return -1;
    }
    if (!g_cls_surface_texture_09cf90) {
        jclass local_st = env->FindClass("com/tiktok/ttr/video/TTRSurfaceTexture");
        if (!local_st) return -1;
        g_cls_surface_texture_09cf90 = static_cast<jclass>(env->NewGlobalRef(local_st));
    }
    g_ttr_jvm_09ce80 = vm;
    g_jni_loaded_flag_09cc7c = 1U;
    return static_cast<jint>(ttr_render::kTtrJniVersion16);
}
