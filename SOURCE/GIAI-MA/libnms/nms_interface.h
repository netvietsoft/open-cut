/**
 * @file nms_interface.h
 * @brief Public C/JNI and C++17 clean-room interface for libnms.so (com.pgl.ssdk.ces.a).
 *        Giao diện C/JNI và C++17 clean-room công khai cho libnms.so (com.pgl.ssdk.ces.a).
 *
 * Binary target / Mục tiêu nhị phân:
 *   SOURCE/apktool-res/lib/arm64-v8a/libnms.so (293,272 bytes)
 *   SHA-256: c448eb3aac806f9a69df7ccebcdf3fac2f77a643716bbba2e0aa5ddc40e50890
 *   Exported symbol: JNI_OnLoad (0x015074, size 296 bytes)
 *   Registered JNI method: com.pgl.ssdk.ces.a.meta(ILandroid/content/Context;Ljava/lang/Object;)Ljava/lang/Object; (0x038a58)
 */

#ifndef NEXTAI_OPENCUT_NMS_INTERFACE_H_
#define NEXTAI_OPENCUT_NMS_INTERFACE_H_

#include "nms_ces_meta_engine.h"
#include "nms_crypto_and_syscalls.h"
#include "nms_rodata_tables.h"
#include "nms_types.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Clean-room C entrypoint corresponding to exported JNI_OnLoad at 0x015074.
 *        Điểm vào C clean-room tương ứng với hàm xuất khẩu JNI_OnLoad tại 0x015074.
 */
int32_t opencut_nms_jni_onload(void* java_vm, void* reserved);

/**
 * @brief Clean-room C entrypoint corresponding to com.pgl.ssdk.ces.a.meta at 0x038a58.
 *        Điểm vào C clean-room tương ứng với com.pgl.ssdk.ces.a.meta tại 0x038a58.
 */
int32_t opencut_nms_ces_meta(int32_t command_code,
                             const char* input_arg,
                             char* out_buf,
                             size_t out_buf_capacity);

/**
 * @brief Self-test harness verifying all 30 XOR strings, 19 RC4 strings, 49 MBA relocations,
 *        opaque predicates, +0xE9 shifted syscalls, and 23 meta() command codes.
 *        Bộ tự kiểm thử xác minh toàn bộ 30 chuỗi XOR, 19 chuỗi RC4, 49 định vị lại MBA,
 *        vị từ mờ, syscall dịch chuyển +0xE9 và 23 mã lệnh meta().
 */
int32_t opencut_nms_run_full_self_test(void);

#ifdef __cplusplus
}
#endif

#endif // NEXTAI_OPENCUT_NMS_INTERFACE_H_
