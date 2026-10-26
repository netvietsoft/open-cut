/**
 * @file godzilla_touphic_interface.h
 * @brief Public C/JNI Exports & ART/WebView Subsystem Declarations for libgodzilla-touphic.so
 *        Khai báo Xuất C/JNI Công khai & Các phân hệ ART/WebView cho libgodzilla-touphic.so
 *
 * Binary Target / Đích nhị phân:
 *   apktool-res/lib/arm64-v8a/libgodzilla-touphic.so (65,304 bytes, 27 exported functions [085..111])
 */

#ifndef OPENCUT_GODZILLA_TOUPHIC_INTERFACE_H_
#define OPENCUT_GODZILLA_TOUPHIC_INTERFACE_H_

#include "godzilla_touphic_types.h"

extern "C" {

// 1. VisitLocksOpt (.dynsym [093])
JNIEXPORT jint JNICALL
Java_com_bytedance_platform_godzilla_touphic_VisitLocksOpt_start(JNIEnv* env, jclass clazz, jint sdk_int);

// 2. DirectBufferOpt (.dynsym [085], [098], [109])
JNIEXPORT jint JNICALL
Java_com_bytedance_platform_godzilla_touphic_DirectBufferOpt_start(JNIEnv* env, jclass clazz, jint sdk_int);
JNIEXPORT void JNICALL
Java_com_bytedance_platform_godzilla_touphic_DirectBufferOpt_nativeEnableSEGV(JNIEnv* env, jclass clazz);
JNIEXPORT void JNICALL
Java_com_bytedance_platform_godzilla_touphic_DirectBufferOpt_nativeEnableSIGBUS(JNIEnv* env, jclass clazz);

// 3. MaxTextureOpt (.dynsym [086], [110])
JNIEXPORT jint JNICALL
Java_com_bytedance_platform_godzilla_touphic_MaxTextureOpt_nStart(JNIEnv* env, jclass clazz, jint sdk_int);
JNIEXPORT jint JNICALL
Java_com_bytedance_platform_godzilla_touphic_MaxTextureOpt_nSafeMaxTextureSize(JNIEnv* env, jclass clazz);

// 4. MakeFromTextureOptS (.dynsym [087], [088])
JNIEXPORT jboolean JNICALL
Java_com_bytedance_platform_godzilla_touphic_impl_MakeFromTextureOptS_startHook(JNIEnv* env, jobject thiz);
JNIEXPORT void JNICALL
Java_com_bytedance_platform_godzilla_touphic_impl_MakeFromTextureOptS_createCrash(JNIEnv* env, jobject thiz);

// 5. SurfaceUpdateOpt (.dynsym [094], [103], [111])
JNIEXPORT jint JNICALL
Java_com_bytedance_platform_godzilla_touphic_impl_SurfaceUpdateOpt_start(JNIEnv* env, jobject thiz, jint sdk_int);
int _Z23updateTexImageByteProxyPv(void* surface_texture);
int _Z19updateTexImageProxyPv(void* surface_texture);

// 6. ChromeSupportOpt (.dynsym [089], [099], [100])
JNIEXPORT jint JNICALL
Java_com_bytedance_platform_godzilla_touphic_impl_ChromeSupportOpt_start(
    JNIEnv* env, jobject thiz, jboolean need_gc, jboolean need_listen,
    jint sdk_version, jint skip_error_count, jint notify_times);
JNIEXPORT jint JNICALL
Java_com_bytedance_platform_godzilla_touphic_impl_ChromeSupportOpt_doWait(JNIEnv* env, jobject thiz);
JNIEXPORT void JNICALL
Java_com_bytedance_platform_godzilla_touphic_impl_ChromeSupportOpt_setDamageWebview(
    JNIEnv* env, jobject thiz, jboolean damage);

// 7. JitCompileOpt (.dynsym [101], [104])
JNIEXPORT jint JNICALL
Java_com_bytedance_platform_godzilla_touphic_impl_JitCompileOpt_start(JNIEnv* env, jobject thiz, jint sdk_int);
JNIEXPORT void JNICALL
Java_com_bytedance_platform_godzilla_touphic_impl_JitCompileOpt_setDamage(
    JNIEnv* env, jobject thiz, jboolean damage);

// 8. TouphicInitUtil & AvLockRegisterHelper (.dynsym [090], [105])
JNIEXPORT jboolean JNICALL
Java_com_bytedance_platform_godzilla_touphic_util_TouphicInitUtil_initNativeAlog(JNIEnv* env, jclass clazz);
JNIEXPORT jboolean JNICALL
Java_com_bytedance_platform_godzilla_touphic_AvLockRegisterHelper_nativeIgnoreAVLockMgrRegister(
    JNIEnv* env, jclass clazz);

// 9. CreateLayerOpt (.dynsym [091])
JNIEXPORT jint JNICALL
Java_com_bytedance_platform_godzilla_touphic_CreateLayerOpt_nativeInit(
    JNIEnv* env, jclass clazz, jint sdk_int, jint max_texture_size, jboolean is_debug);

// 10. GLESMaliOpt (.dynsym [095])
JNIEXPORT jint JNICALL
Java_com_bytedance_platform_godzilla_touphic_GLESMaliOpt_nativeInit(
    JNIEnv* env, jclass clazz, jstring build_id, jstring target_sym, jlong offset, jboolean is_debug);

// 11. SafeUffdGCOpt (.dynsym [102], [106], [107])
JNIEXPORT jint JNICALL
Java_com_bytedance_platform_godzilla_touphic_SafeUffdGCOpt_start(JNIEnv* env, jclass clazz, jint sdk_int);
JNIEXPORT void JNICALL
Java_com_bytedance_platform_godzilla_touphic_SafeUffdGCOpt_setParamNative(
    JNIEnv* env, jclass clazz, jint back_off_time, jint back_off_max_count);
JNIEXPORT void JNICALL
Java_com_bytedance_platform_godzilla_touphic_SafeUffdGCOpt_setMode(JNIEnv* env, jclass clazz, jint mode);

// 12. EglNotInitOpt (.dynsym [096])
JNIEXPORT jboolean JNICALL
Java_com_bytedance_platform_godzilla_touphic_EglNotInitOpt_nativeWaitEglInit(
    JNIEnv* env, jclass clazz, jint delay_ms);

// 13. GLESAdrenoOpt (.dynsym [092], [097])
JNIEXPORT jint JNICALL
Java_com_bytedance_platform_godzilla_touphic_GLESAdrenoOpt_nativeInitDoubleFreeOpt(
    JNIEnv* env, jclass clazz, jint size, jint slot_size, jboolean need_timing, jboolean is_debug);
JNIEXPORT jint JNICALL
Java_com_bytedance_platform_godzilla_touphic_GLESAdrenoOpt_nativeInitUafOpt(
    JNIEnv* env, jclass clazz, jint mode, jobject config_obj);

// 14. WebviewChromiumOpt (.dynsym [108])
JNIEXPORT jint JNICALL
Java_com_bytedance_platform_godzilla_touphic_WebviewChromiumOpt_nativeInit(
    JNIEnv* env, jclass clazz, jstring so_name, jboolean clear_exp);

}  // extern "C"

#endif  // OPENCUT_GODZILLA_TOUPHIC_INTERFACE_H_
