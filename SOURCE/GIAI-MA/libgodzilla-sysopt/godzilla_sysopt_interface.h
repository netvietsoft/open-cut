/**
 * @file godzilla_sysopt_interface.h
 * @brief Clean-Room JNI Exports & Public C/C++ Interface for libgodzilla-sysopt.so.
 *        Giao diện C/C++ công khai và 10 hàm xuất JNI tái tạo sạch cho libgodzilla-sysopt.so.
 *
 * Binary Target / Mục tiêu nhị phân:
 *   SOURCE/apktool-res/lib/arm64-v8a/libgodzilla-sysopt.so
 *   10 Exported JNI Functions in .dynsym / 10 hàm JNI xuất trong .dynsym:
 *     1. 0x00819c : Java_com_bytedance_platform_godzilla_sysopt_IvimageOpt_start
 *     2. 0x0081f0 : Java_com_bytedance_platform_godzilla_sysopt_IvimageOpt_end
 *     3. 0x0081f0 : Java_com_bytedance_platform_godzilla_sysopt_PthreadCreateHook_end
 *     4. 0x0081f0 : Java_com_bytedance_platform_godzilla_sysopt_UbsanOpt_end
 *     5. 0x0081f4 : Java_com_bytedance_platform_godzilla_sysopt_UbsanOpt_start
 *     6. 0x008254 : Java_com_bytedance_platform_godzilla_sysopt_PthreadCreateHook_start
 *     7. 0x00aa3c : Java_com_bytedance_platform_godzilla_sysopt_ThreadHook_start
 *     8. 0x00aadc : Java_com_bytedance_platform_godzilla_sysopt_ThreadHook_end
 *     9. 0x017978 : Java_com_bytedance_platform_godzilla_sysopt_ApkSha256_checkMyShit
 *    10. 0x0180f4 : Java_com_bytedance_platform_godzilla_sysopt_ApkSha256_checkHookFrameworks
 */

#ifndef NEXTAI_OPENCUT_GODZILLA_SYSOPT_INTERFACE_H_
#define NEXTAI_OPENCUT_GODZILLA_SYSOPT_INTERFACE_H_

#include "apk_cert_sha256_engine.h"
#include "elf_build_id_xhook.h"
#include "godzilla_sysopt_types.h"
#include "maps_hook_scanner.h"

#include <cstdint>
#include <string>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Minimal JNI types for clean-room cross-platform compilation.
 *        Các kiểu JNI tối giản phục vụ biên dịch đa nền tảng sạch.
 */
typedef void*   GodzillaJniEnvPtr;
typedef void*   GodzillaJClass;
typedef void*   GodzillaJString;
typedef int32_t GodzillaJInt;

/**
 * @brief 1. `Java_com_bytedance_platform_godzilla_sysopt_IvimageOpt_start` (`0x00819c`, `84 B`)
 *        Logs `"register ivimage optimize"` (`0x003f35`) and inspects `/system/lib/libIVImageSR.so` Build-ID.
 */
void Java_com_bytedance_platform_godzilla_sysopt_IvimageOpt_start(
    GodzillaJniEnvPtr env,
    GodzillaJClass clazz);

/**
 * @brief 2. `Java_com_bytedance_platform_godzilla_sysopt_IvimageOpt_end` (`0x0081f0`, `4 B` `ret`)
 *        Shared 4-byte `ret` stub (`c0035fd6`) with `UbsanOpt_end` and `PthreadCreateHook_end`.
 */
void Java_com_bytedance_platform_godzilla_sysopt_IvimageOpt_end(
    GodzillaJniEnvPtr env,
    GodzillaJClass clazz);

/**
 * @brief 3. `Java_com_bytedance_platform_godzilla_sysopt_UbsanOpt_start` (`0x0081f4`, `84 B`)
 *        Logs `"register ubsan optimize"` (`0x0046b3`) and inspects `/system/lib/libbinder.so` Build-ID.
 */
void Java_com_bytedance_platform_godzilla_sysopt_UbsanOpt_start(
    GodzillaJniEnvPtr env,
    GodzillaJClass clazz);

/**
 * @brief 4. `Java_com_bytedance_platform_godzilla_sysopt_UbsanOpt_end` (`0x0081f0`, `4 B` `ret`)
 */
void Java_com_bytedance_platform_godzilla_sysopt_UbsanOpt_end(
    GodzillaJniEnvPtr env,
    GodzillaJClass clazz);

/**
 * @brief 5. `Java_com_bytedance_platform_godzilla_sysopt_PthreadCreateHook_start` (`0x008254`, `152 B`)
 *        Sets target pthread stack size (`0x00083000` default at `.data 0x02f7c8`) and hooks
 *        `pthread_attr_setstacksize` in `libart.so` via xHook.
 */
void Java_com_bytedance_platform_godzilla_sysopt_PthreadCreateHook_start(
    GodzillaJniEnvPtr env,
    GodzillaJClass clazz,
    GodzillaJInt stack_size_bytes);

/**
 * @brief 6. `Java_com_bytedance_platform_godzilla_sysopt_PthreadCreateHook_end` (`0x0081f0`, `4 B` `ret`)
 */
void Java_com_bytedance_platform_godzilla_sysopt_PthreadCreateHook_end(
    GodzillaJniEnvPtr env,
    GodzillaJClass clazz);

/**
 * @brief 7. `Java_com_bytedance_platform_godzilla_sysopt_ThreadHook_start` (`0x00aa3c`, `160 B`)
 *        Installs `SIGBUS` (`7`) handler with `sa_flags = 0x18000004` (`SA_SIGINFO | SA_ONSTACK | SA_RESTART`).
 */
void Java_com_bytedance_platform_godzilla_sysopt_ThreadHook_start(
    GodzillaJniEnvPtr env,
    GodzillaJClass clazz);

/**
 * @brief 8. `Java_com_bytedance_platform_godzilla_sysopt_ThreadHook_end` (`0x00aadc`, `24 B`)
 *        Logs `"thread end"` (`0x004fb2`) under tag `"pyt123"` (`0x0046ea`).
 */
void Java_com_bytedance_platform_godzilla_sysopt_ThreadHook_end(
    GodzillaJniEnvPtr env,
    GodzillaJClass clazz);

/**
 * @brief 9. `Java_com_bytedance_platform_godzilla_sysopt_ApkSha256_checkMyShit` (`0x017978`, `1,916 B`)
 *        Resolves the app's APK path from `/proc/self/maps` via `.data 0x02f8a0` (`findApkPathFromMaps`),
 *        extracts the X.509 signing certificate from `META-INF/*.RSA|DSA|EC`, and returns its 64-char SHA-256.
 */
GodzillaJString Java_com_bytedance_platform_godzilla_sysopt_ApkSha256_checkMyShit(
    GodzillaJniEnvPtr env,
    GodzillaJClass clazz,
    GodzillaJString package_hint);

/**
 * @brief 10. `Java_com_bytedance_platform_godzilla_sysopt_ApkSha256_checkHookFrameworks` (`0x0180f4`, `408 B`)
 *        Invokes `.data 0x02f940` (`scanMapsForHookFrameworks` @ `0x019fb4`) and returns the matching
 *        `/proc/self/maps` line, `"use_more_than_39_bits"`, or `""`.
 */
GodzillaJString Java_com_bytedance_platform_godzilla_sysopt_ApkSha256_checkHookFrameworks(
    GodzillaJniEnvPtr env,
    GodzillaJClass clazz);

#ifdef __cplusplus
}  // extern "C"
#endif

#endif  // NEXTAI_OPENCUT_GODZILLA_SYSOPT_INTERFACE_H_
