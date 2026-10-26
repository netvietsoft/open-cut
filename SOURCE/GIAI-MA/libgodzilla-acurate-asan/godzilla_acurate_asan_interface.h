// ============================================================================
// File: godzilla_acurate_asan_interface.h
// Target: libgodzilla-acurate-asan.so (160,168 bytes, SHA-256: 0c89ab013365273e...)
// Task ID: TASK-114-RECONSTRUCTION-LIBGODZILLA_ACURATE_ASAN (TASK_SO_128)
// Architecture: AArch64 (ARM64-v8a)
// Description (EN): Public C/C++ and JNI exported symbol interface of
//                   libgodzilla-acurate-asan.so matching all 10 .dynsym exports.
// Mô tả (VN): Giao diện biểu tượng xuất công khai C/C++ và JNI của
//             libgodzilla-acurate-asan.so khớp toàn bộ 10 hàm xuất trong .dynsym.
// ============================================================================

#pragma once

#include "godzilla_acurate_asan_types.h"
#include "guarded_pool_allocator.h"
#include "acurate_asan_signal_hook.h"
#include "godzilla_ref_debug.h"

#include <jni.h>

extern "C" {

// ============================================================================
// [EN] 1. Exported @ 0x00dcc0 (size 1572 B):
//      Java_com_bytedance_platform_godzilla_gwpasan_GodzillaAcurateAsan_initAcurateAsan
//      Signature: (Ljava/lang/String;Ljava/lang/String;I)Z
// [VN] 1. Hàm xuất JNI tại 0x00dcc0 (kích thước 1572 B): Khởi tạo GodzillaAcurateAsan
// ============================================================================
JNIEXPORT jboolean JNICALL
Java_com_bytedance_platform_godzilla_gwpasan_GodzillaAcurateAsan_initAcurateAsan(
    JNIEnv* env,
    jclass clazz,
    jstring config_json,
    jstring dump_dir,
    jint api_level);

// ============================================================================
// [EN] 2. Exported @ 0x01ed68 (size 784 B):
//      Java_com_bytedance_platform_godzilla_gwpasan_GodzillaAcurateAsan_initProxyFaultHandler
//      Signature: (Ljava/lang/String;)Z
// [VN] 2. Hàm xuất JNI tại 0x01ed68 (kích thước 784 B): Khởi tạo Proxy Fault Handler
// ============================================================================
JNIEXPORT jboolean JNICALL
Java_com_bytedance_platform_godzilla_gwpasan_GodzillaAcurateAsan_initProxyFaultHandler(
    JNIEnv* env,
    jclass clazz,
    jstring config_json);

// ============================================================================
// [EN] 3. Exported @ 0x01ff1c (size 4 B):
//      Java_com_bytedance_platform_godzilla_gwpasan_GodzillaRefDebug_nativeRefrecordInit
//      Signature: ()V
// [VN] 3. Hàm xuất JNI tại 0x01ff1c (kích thước 4 B): Khởi tạo GodzillaRefDebug
// ============================================================================
JNIEXPORT void JNICALL
Java_com_bytedance_platform_godzilla_gwpasan_GodzillaRefDebug_nativeRefrecordInit(
    JNIEnv* env,
    jclass clazz);

// ============================================================================
// [EN] 4. Exported @ 0x01ff20 (size 12 B):
//      Java_com_bytedance_platform_godzilla_gwpasan_GodzillaRefDebug_nativeRefrecordDumpLatest
//      Signature: (II)V
// [VN] 4. Hàm xuất JNI tại 0x01ff20 (kích thước 12 B): Kết xuất các bản ghi GlobalRef mới nhất
// ============================================================================
JNIEXPORT void JNICALL
Java_com_bytedance_platform_godzilla_gwpasan_GodzillaRefDebug_nativeRefrecordDumpLatest(
    JNIEnv* env,
    jclass clazz,
    jint max_count,
    jint ref_value);

// ============================================================================
// [EN] 5. Exported @ 0x01ff2c (size 16 B):
//      Java_com_bytedance_platform_godzilla_gwpasan_GodzillaRefDebug_nativeRefrecordConfig
//      Signature: (III)V
// [VN] 5. Hàm xuất JNI tại 0x01ff2c (kích thước 16 B): Cấu hình tham số GodzillaRefDebug
// ============================================================================
JNIEXPORT void JNICALL
Java_com_bytedance_platform_godzilla_gwpasan_GodzillaRefDebug_nativeRefrecordConfig(
    JNIEnv* env,
    jclass clazz,
    jint bundle_size,
    jint local_size,
    jint hook_add_global_ref);

// ============================================================================
// [EN] 6. Exported @ 0x01ff3c (size 28 B):
//      Java_com_bytedance_platform_godzilla_gwpasan_GodzillaRefDebug_nativeSetRefdebugDebuglog
//      Signature: (Z)V
// [VN] 6. Hàm xuất JNI tại 0x01ff3c (kích thước 28 B): Bật/tắt nhật ký gỡ lỗi RefDebug
// ============================================================================
JNIEXPORT void JNICALL
Java_com_bytedance_platform_godzilla_gwpasan_GodzillaRefDebug_nativeSetRefdebugDebuglog(
    JNIEnv* env,
    jclass clazz,
    jboolean enable_debug_log);

// ============================================================================
// [EN] 7. Exported @ 0x01ff58 (size 124 B):
//      Java_com_bytedance_platform_godzilla_gwpasan_GodzillaRefDebug_testcase1
//      Signature: (Ljava/lang/Object;)V
// [VN] 7. Hàm xuất JNI tại 0x01ff58 (kích thước 124 B): Kịch bản kiểm thử 1 (NewGlobalRef + DeleteGlobalRef)
// ============================================================================
JNIEXPORT void JNICALL
Java_com_bytedance_platform_godzilla_gwpasan_GodzillaRefDebug_testcase1(
    JNIEnv* env,
    jclass clazz,
    jobject obj);

// ============================================================================
// [EN] 8. Exported @ 0x01ffd4 (size 308 B):
//      Java_com_bytedance_platform_godzilla_gwpasan_GodzillaRefDebug_testcase2_11
//      Signature: (Ljava/lang/Object;I)J
// [VN] 8. Hàm xuất JNI tại 0x01ffd4 (kích thước 308 B): Kịch bản kiểm thử 2.1 (Cấp phát mảng GlobalRef)
// ============================================================================
JNIEXPORT jlong JNICALL
Java_com_bytedance_platform_godzilla_gwpasan_GodzillaRefDebug_testcase2_11(
    JNIEnv* env,
    jclass clazz,
    jobject obj,
    jint count);

// ============================================================================
// [EN] 9. Exported @ 0x020108 (size 124 B):
//      Java_com_bytedance_platform_godzilla_gwpasan_GodzillaRefDebug_testcase2_12
//      Signature: (J)V
// [VN] 9. Hàm xuất JNI tại 0x020108 (kích thước 124 B): Kịch bản kiểm thử 2.2 (Giải phóng mảng GlobalRef)
// ============================================================================
JNIEXPORT void JNICALL
Java_com_bytedance_platform_godzilla_gwpasan_GodzillaRefDebug_testcase2_12(
    JNIEnv* env,
    jclass clazz,
    jlong array_handle);

} // extern "C"
