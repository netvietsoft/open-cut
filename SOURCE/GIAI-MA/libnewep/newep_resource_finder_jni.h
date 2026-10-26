/**
 * @file newep_resource_finder_jni.h
 * @brief Declarations for the 6 exported `.bss` global JNI pointers (`0x010010..0x010038`),
 *        the 4 core EffectPlatform / EPKN JNI & C++ entry points (`JNI_OnLoad`,
 *        `nativeCreateResourceFinder`, `findResourceUri_DownloadableModelSupport`,
 *        `nativeCheckEffectChildrenFile`), and the 2 `_JNIEnv` variadic helpers in `libnewep.so`.
 *        Khai báo 6 con trỏ toàn cục `.bss` (`0x010010..0x010038`), 4 điểm nhập JNI & C++
 *        cốt lõi của EffectPlatform / EPKN và 2 hàm biến đối số `_JNIEnv` trong `libnewep.so`.
 */

#ifndef NEXTAI_OPENCUT_NEWEP_RESOURCE_FINDER_JNI_H_
#define NEXTAI_OPENCUT_NEWEP_RESOURCE_FINDER_JNI_H_

#include "newep_types.h"

namespace nextai {
namespace opencut {
namespace newep {

// ============================================================================
// 1. Global `.bss` Segment Accessor (`0x010010..0x01027f`)
//    Bộ truy cập Phân đoạn Toàn cục `.bss` (`0x010010..0x01027f`)
// ============================================================================

NewepBssSegment& GetNewepBssSegment() noexcept;

// ============================================================================
// 2. Core EffectPlatform Resource Finder & Children Validator API (`0x001ebc..0x00326f`)
//    API Tìm kiếm Tài nguyên Mô hình & Kiểm tra Tệp Con EffectPlatform (`0x001ebc..0x00326f`)
// ============================================================================

/**
 * @brief `JNI_OnLoad` (`0x001ebc..0x00209b`, `480 bytes`, `.dynsym [058]`).
 *        Caches `g_vm` (`0x010038`), resolves `AlgorithmModelResourceFinder` (`0x00728c` -> `0x010010`),
 *        `findResourceUri` (`0x0073f3` -> `0x010018`), `modelNotFound` (`0x007306` -> `0x010020`),
 *        and optionally `DownloadableModelSupportResourceFinder` (`0x00732a` -> `0x010030`, `0x010028`)
 *        with `ExceptionCheck` / `ExceptionDescribe` / `ExceptionClear` (`0x001fec..0x002018`).
 *        Returns `0x00010006` (`JNI_VERSION_1_6`) or `-1` (`0x001f0c`).
 */
jint NewepJniOnLoad(JavaVM* vm, void* reserved) noexcept;

/**
 * @brief `Java_com_ss_ugc_effectplatform_algorithm_AlgorithmModelResourceFinder_nativeCreateResourceFinder`
 *        (`0x00209c..0x0020a7`, `12 bytes`, `.dynsym [072]`).
 *        Disassembly:
 *        - `0x00209c`: `adrp x0, #0xf000`
 *        - `0x0020a0`: `ldr  x0, [x0, #0xfb0]` (`_Z40findResourceUri_DownloadableModelSupportPvPKcS1_`)
 *        - `0x0020a4`: `ret`
 */
jlong NativeCreateResourceFinder(JNIEnv* env, jobject thiz, jlong param) noexcept;

/**
 * @brief `_Z40findResourceUri_DownloadableModelSupportPvPKcS1_` (`0x0020a8..0x002437`, `912 bytes`, `.dynsym [070]`).
 *        Resolves an algorithm model URI by calling `kn_resource_finder_class.findResourceUri(dir, name)`,
 *        falling back to `old_resource_finder_class.findResourceUri(dir, name)` if the result equals
 *        `"asset://not_found"`, and invoking `kn_resource_finder_class.modelNotFound(name)` if still
 *        `"asset://not_found"`. Returns a `malloc`-allocated C string.
 */
char* FindResourceUriDownloadableModelSupport(void* user_data,
                                              const char* dir_path,
                                              const char* model_name) noexcept;

/**
 * @brief `_ZN7_JNIEnv22CallStaticObjectMethodEP7_jclassP10_jmethodIDz` (`0x002438..0x0024d3`, `156 bytes`, `.dynsym [057]`).
 */
jobject JniEnvCallStaticObjectMethodVariadic(JNIEnv* env, jclass clazz, jmethodID method_id, ...) noexcept;

/**
 * @brief `_ZN7_JNIEnv20CallStaticVoidMethodEP7_jclassP10_jmethodIDz` (`0x0024d4..0x00256f`, `156 bytes`, `.dynsym [049]`).
 */
void JniEnvCallStaticVoidMethodVariadic(JNIEnv* env, jclass clazz, jmethodID method_id, ...) noexcept;

/**
 * @brief `Java_com_ss_ugc_effectplatform_util_EffectUtilKt_nativeCheckEffectChildrenFile`
 *        (`0x002570..0x00326f`, `3,328 bytes`, `.dynsym [048]`).
 *        Reads `<dirPath>/effect_platform_children.tag`, splits by `","`, trims leading/trailing
 *        ASCII spaces (`0x20`), and verifies every child relative path exists via `stat()`.
 */
jboolean NativeCheckEffectChildrenFile(JNIEnv* env, jclass clazz, jstring dir_path_jstr);

/**
 * @brief Pure C++ helper replicating the exact tag-file parsing, comma-splitting, space-trimming
 *        (`0x20` @ `0x002bf0`, `0x002c78`, `0x002d98`, `0x002e24`), and `stat()` check in
 *        `nativeCheckEffectChildrenFile` (`0x002570..0x00326f`).
 */
bool CheckEffectChildrenFileFromPath(const char* dir_path,
                                     std::vector<std::string>* out_parsed_children = nullptr);

} // namespace newep
} // namespace opencut
} // namespace nextai

#endif // NEXTAI_OPENCUT_NEWEP_RESOURCE_FINDER_JNI_H_
