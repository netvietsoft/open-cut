/**
 * @file osfix_thread_typeface_optimizer.h
 * @brief Clean-Room C++17 Reconstruction of com.bytedance.osfix.ThreadStackOptimizer
 *        and com.bytedance.osfix.TypeFaceOptimizer (0x01681c..0x01814f in libosfix.so).
 *        Tái cấu trúc C++17 Clean-Room của com.bytedance.osfix.ThreadStackOptimizer
 *        và com.bytedance.osfix.TypeFaceOptimizer (0x01681c..0x01814f trong libosfix.so).
 *
 * Exported JNI Symbols Covered / Các biểu tượng JNI xuất khẩu được bao phủ:
 *   10. Java_com_bytedance_osfix_ThreadStackOptimizer_nativeShrinkthread (0x016b7c, size 0x0020)
 *   11. Java_com_bytedance_osfix_TypeFaceOptimizer_optimize              (0x016b9c, size 0x0008)
 *   12. Java_com_bytedance_osfix_TypeFaceOptimizer_nativeClearUnuseTTF   (0x017dc0, size 0x0390)
 */

#ifndef NEXTAI_OPENCUT_OSFIX_THREAD_TYPEFACE_OPTIMIZER_H_
#define NEXTAI_OPENCUT_OSFIX_THREAD_TYPEFACE_OPTIMIZER_H_

#include "osfix_types.h"

namespace bytedance {
namespace osfix {

// ============================================================================
// 1. ThreadStackOptimizer Engine (0x01681c..0x016b9b)
//    Động cơ Tối ưu hóa Ngăn xếp Luồng ThreadStackOptimizer (0x01681c..0x016b9b)
// ============================================================================

/**
 * @brief Caller filter (`0x016b08..0x016b7b`) for `pthread_create` ByteHook:
 *        Excludes `"libosfix.so"` (`0x01c41e`), `"libv8_libfull.cr.so"` (`0x01d47c`),
 *        `"libquick.so"` (`0x01d490`), and `"libGLES_mali.so"` (`0x01d49c`).
 *        Returns `false` (`0`) if any of those libraries is the caller, or `true` (`1`)
 *        to allow stack shrinking.
 *        Bộ lọc người gọi (`0x016b08..0x016b7b`) cho `pthread_create` loại trừ V8, QuickJS và GPU Mali.
 */
bool AllowPthreadCreateShrinkFilter(const char* caller_path_name, void* arg);

/**
 * @brief Proxy (`0x01681c..0x0168df`) for `pthread_create`:
 *        - Checks if `attr == nullptr` (`cbz x1, #0x16874`):
 *          - If `attr == nullptr`, allocates `0x38` (`56`) bytes via `malloc(0x38)` (`0x016874..0x016878`),
 *            initializes it via `pthread_attr_init(attr)` (`0x016880`), and sets `attr->stack_size` (`+0x10`)
 *            to `native_shrink_thread_size` (`.data 0x02800c`, default `0x00080000` = 512 KB).
 *          - If `attr != nullptr`:
 *            - Compares `start_routine` (`x2`) against `_ZN3art6Thread24CreateCallbackWithUffdGcEPv`
 *              (`.bss 0x028190`) and `_ZN3art6Thread14CreateCallbackEPv` (`.bss 0x028198`).
 *            - If `start_routine` matches either ART Java thread entry point (`0x016850..0x016864`),
 *              loads `java_shrink_thread_size` (`ldrsw x8, [0x28008]`, default `0x00030000` = 192 KB);
 *              otherwise loads `native_shrink_thread_size` (`ldrsw x8, [0x2800c]`, default `0x00080000` = 512 KB).
 *            - Writes `x8` into `attr->stack_size` (`str x8, [x23, #0x10]` at `0x01688c`).
 *        Hàm ủy nhiệm (`0x01681c..0x0168df`) cho `pthread_create` thu nhỏ `stack_size` tại `+0x10`.
 */
BionicPthreadAttr ApplyThreadStackShrinkToAttr(
    const BionicPthreadAttr* input_attr,
    void* start_routine);

/**
 * @brief Internal implementation `shrink_thread_impl` (`0x016908..0x016ae7`) invoked by
 *        `Java_com_bytedance_osfix_ThreadStackOptimizer_nativeShrinkthread`:
 *        1. Queries `"ro.build.version.release"` (`0x01d348`) via `__system_property_get` and `atoi`.
 *        2. Opens `"libart.so"` (`0x01c2f1`) via `npth_dlopen` (`0x0059d0`).
 *        3. Resolves `"_ZN3art6Thread14CreateCallbackEPv"` (`0x01d376`) into `.bss 0x028198` via `npth_dlsym`.
 *        4. If `android_release_version > 13` (`cmp w20, #0xd; b.le #0x16a78`), also resolves
 *           `"_ZN3art6Thread24CreateCallbackWithUffdGcEPv"` (`0x01d398`) into `.bss 0x028190`.
 *        5. Updates `java_shrink_thread_size` (`.data 0x028008`) and `native_shrink_thread_size`
 *           (`.data 0x02800c`), and hooks `"pthread_create"` (`0x01d44c`) via `bytehook_hook_partial`.
 *        Hàm thực thi nội bộ `shrink_thread_impl` (`0x016908..0x016ae7`) thu nhỏ ngăn xếp luồng Java và Native.
 */
bool ConfigureThreadStackShrink(
    int32_t java_stack_size_bytes,
    int32_t native_stack_size_bytes,
    int32_t simulated_android_release = 14);

// ============================================================================
// 2. TypeFaceOptimizer Engine (0x016b9c..0x01814f)
//    Động cơ Tối ưu hóa Phông chữ TypeFaceOptimizer (0x016b9c..0x01814f)
// ============================================================================

/**
 * @brief Helper `get_smaps_pss` (`0x016ba4..0x016fe7`):
 *        Scans `/proc/self/smaps` (`0x01d4cf`) for a specific mapped file path, then reads
 *        subsequent lines looking for the 4-byte prefix `"Pss:"` (`0x3a737350` at `0x016d90..0x016da0`:
 *        `mov w21, #0x7350; movk w21, #0x3a73, lsl #16`) until `"VmFlags"` (`0x01d4e5` at `0x016f3c`)
 *        is reached, returning the PSS in kB!
 *        Hàm phụ trợ `get_smaps_pss` (`0x016ba4..0x016fe7`) tìm giá trị `"Pss:"` (`0x3a737350`)
 *        trong `/proc/self/smaps` cho đến khi gặp `"VmFlags"`.
 */
int64_t ParseSmapsPssForPath(
    const std::string& smaps_content,
    const std::string& target_path);

/**
 * @brief Core `clear_unused_ttf_impl` (`0x017428..0x017b97`):
 *        Reads `/proc/self/maps` (`0x01d4ed`) line by line, extracts the 6 fields
 *        (`addr_range`, `perms`, `offset`, `dev`, `inode`, `pathname`), checks if `pathname`
 *        contains any TTF path from `ttf_paths`, splits `addr_range` on `'-'` (`0x2d` at `0x017854`),
 *        parses `start_addr` and `end_addr` in base 16 (`stoull(..., nullptr, 16)` at `0x017970` & `0x017984`),
 *        queries `get_smaps_pss` (`0x017990`), and if `pss_kb <= 1023` (`cmp x0, #0x3ff; b.hi #0x179e4`
 *        at `0x017998`), calls `munmap((void*)start_addr, end_addr - start_addr)` (`0x0179ac`)!
 *        Hàm thực thi `clear_unused_ttf_impl` (`0x017428..0x017b97`) giải phóng các tệp phông chữ `.ttf`
 *        có `Pss <= 1023 kB` (`0x3ff`).
 */
std::vector<ProcMemoryRegionInfo> ClearUnusedTtfFromMapsAndSmaps(
    const std::vector<std::string>& ttf_paths,
    const std::string& maps_content,
    const std::string& smaps_content,
    bool perform_munmap = false);

} // namespace osfix
} // namespace bytedance

// ============================================================================
// 3. Exported JNI C Entry Points for ThreadStackOptimizer & TypeFaceOptimizer
//    Các điểm nhập C JNI xuất khẩu cho ThreadStackOptimizer & TypeFaceOptimizer
// ============================================================================

extern "C" {

/**
 * @brief `0x016b7c..0x016b9b`: `Java_com_bytedance_osfix_ThreadStackOptimizer_nativeShrinkthread`
 *        Forwards `(jint java_size, jint native_size)` (`w2`, `w3`) to `shrink_thread_impl` (`0x016908`).
 */
bytedance::osfix::jboolean Java_com_bytedance_osfix_ThreadStackOptimizer_nativeShrinkthread(
    bytedance::osfix::JNIEnv* env,
    bytedance::osfix::jclass clazz,
    bytedance::osfix::jint java_thread_stack_size,
    bytedance::osfix::jint native_thread_stack_size);

/**
 * @brief `0x016b9c..0x016ba3`: `Java_com_bytedance_osfix_TypeFaceOptimizer_optimize`
 *        Returns `JNI_TRUE` (`1`) (`mov w0, #1; ret`).
 */
bytedance::osfix::jboolean Java_com_bytedance_osfix_TypeFaceOptimizer_optimize(
    bytedance::osfix::JNIEnv* env,
    bytedance::osfix::jclass clazz);

/**
 * @brief `0x017dc0..0x01814f`: `Java_com_bytedance_osfix_TypeFaceOptimizer_nativeClearUnuseTTF`
 *        Iterates `ArrayList` of typeface objects via JNI (`size()I`, `get(I)Ljava/lang/Object;`,
 *        `getPath()Ljava/lang/String;`) and unmaps unused TTF mappings (`Pss <= 1023 kB`).
 */
void Java_com_bytedance_osfix_TypeFaceOptimizer_nativeClearUnuseTTF(
    bytedance::osfix::JNIEnv* env,
    bytedance::osfix::jclass clazz,
    bytedance::osfix::jobject typeface_array_list);

} // extern "C"

#endif // NEXTAI_OPENCUT_OSFIX_THREAD_TYPEFACE_OPTIMIZER_H_
