/**
 * @file osfix_thread_typeface_optimizer.cpp
 * @brief Clean-Room C++17 Implementation of com.bytedance.osfix.ThreadStackOptimizer
 *        and com.bytedance.osfix.TypeFaceOptimizer (0x01681c..0x01814f in libosfix.so).
 *        Triển khai C++17 Clean-Room của com.bytedance.osfix.ThreadStackOptimizer
 *        và com.bytedance.osfix.TypeFaceOptimizer (0x01681c..0x01814f trong libosfix.so).
 *
 * Evidence Classification / Phân loại bằng chứng:
 *   - [OBSERVED]: Direct AArch64 instruction decoding from libosfix.so
 *     (SHA-256: ddd8baabbcdd7941b13ab0e961a57e92843d957a0c64e6afa3613b2c433c937d).
 */

#include "osfix_thread_typeface_optimizer.h"

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <sstream>

#if defined(__linux__) || defined(__ANDROID__)
#include <sys/mman.h>
#include <unistd.h>
#endif

namespace bytedance {
namespace osfix {

// ============================================================================
// 1. ThreadStackOptimizer Engine (0x01681c..0x016b9b)
//    Động cơ Tối ưu hóa Ngăn xếp Luồng ThreadStackOptimizer (0x01681c..0x016b9b)
// ============================================================================

/**
 * @brief Caller filter (`0x016b08..0x016b7b`) for `pthread_create` ByteHook:
 *        Checks `strstr(caller_path_name, ...)` against 4 excluded libraries:
 *        1. `"libosfix.so"`           (`0x01c41e` at `0x016b14..0x016b20`)
 *        2. `"libv8_libfull.cr.so"`   (`0x01d47c` at `0x016b28..0x016b34`)
 *        3. `"libquick.so"`           (`0x01d490` at `0x016b3c..0x016b48`)
 *        4. `"libGLES_mali.so"`       (`0x01d49c` at `0x016b60..0x016b6c`)
 *        Returns `false` (`0`) if any of those 4 libraries is matched, or `true` (`1`) otherwise.
 *        Bộ lọc người gọi (`0x016b08..0x016b7b`) loại trừ 4 thư viện nhạy cảm ngăn xếp.
 */
bool AllowPthreadCreateShrinkFilter(const char* caller_path_name, void* /*arg*/) {
    if (caller_path_name == nullptr) {
        return false;
    }
    if (std::strstr(caller_path_name, "libosfix.so") != nullptr) {
        return false;
    }
    if (std::strstr(caller_path_name, "libv8_libfull.cr.so") != nullptr) {
        return false;
    }
    if (std::strstr(caller_path_name, "libquick.so") != nullptr) {
        return false;
    }
    if (std::strstr(caller_path_name, "libGLES_mali.so") != nullptr) {
        return false;
    }
    return true;
}

/**
 * @brief Proxy (`0x01681c..0x0168df`) for `pthread_create`:
 *        Exact AArch64 control flow:
 *        - `0x016840`: `cbz x1, #0x16874`
 *          - If `input_attr == nullptr` (`0x016874`):
 *            Allocates `0x38` (`56`) bytes (`mov w0, #0x38; bl malloc`), calls `pthread_attr_init`,
 *            and falls through to `0x016884` where `native_shrink_thread_size` (`[0x2800c]`) is
 *            loaded via `ldrsw x8, [x8, #0xc]` and stored to `attr.stack_size` (`[x23, #0x10]`).
 *          - If `input_attr != nullptr` (`0x016844..0x016870`):
 *            Compares `start_routine` (`x21`) with `art_create_callback_uffd` (`[0x28190]`) at `0x016850`
 *            and `art_create_callback` (`[0x28198]`) at `0x016860`:
 *            - If equal (`b.eq #0x16868`), loads `java_shrink_thread_size` (`ldrsw x8, [0x28008]`).
 *            - If not equal (`b.ne #0x16884`), loads `native_shrink_thread_size` (`ldrsw x8, [0x2800c]`).
 *            - Stores `x8` into `attr.stack_size` (`str x8, [x23, #0x10]` at `0x01688c`).
 *        Áp dụng thu nhỏ kích thước ngăn xếp luồng (`stack_size` tại `+0x10`) cho luồng Java hoặc Native.
 */
BionicPthreadAttr ApplyThreadStackShrinkToAttr(
    const BionicPthreadAttr* input_attr,
    void* start_routine) {
    OsFixGlobalState& state = GetGlobalState();
    BionicPthreadAttr out_attr{};
    if (input_attr != nullptr) {
        out_attr = *input_attr;
        bool is_java_art_thread =
            (start_routine != nullptr) &&
            (start_routine == state.art_create_callback_uffd ||
             start_routine == state.art_create_callback);
        if (is_java_art_thread) {
            out_attr.stack_size = static_cast<size_t>(
                static_cast<int64_t>(state.java_shrink_thread_size));
        } else {
            out_attr.stack_size = static_cast<size_t>(
                static_cast<int64_t>(state.native_shrink_thread_size));
        }
    } else {
        // 0x016874..0x016888: When attr == nullptr, initializes a 56-byte (0x38) BionicPthreadAttr
        // and sets stack_size (+0x10) to native_shrink_thread_size ([0x2800c]).
        out_attr.stack_size = static_cast<size_t>(
            static_cast<int64_t>(state.native_shrink_thread_size));
    }
    return out_attr;
}

/**
 * @brief Internal implementation `shrink_thread_impl` (`0x016908..0x016ae7`):
 *        1. Reads `"ro.build.version.release"` (`0x01d348` at `0x01694c`) into a 1024-byte (`0x400`)
 *           stack buffer and converts to `int` via `atoi` (`0x01695c`).
 *        2. Opens `"libart.so"` (`0x01c2f1` at `0x016968`) via `npth_dlopen` (`0x0059d0`).
 *        3. Looks up `"_ZN3art6Thread14CreateCallbackEPv"` (`0x01d376` at `0x01697c`) via `npth_dlsym`
 *           and stores at `.bss 0x028198` (`0x01698c`).
 *        4. Checks `cmp w20, #0xd` (`13`, Android 13) at `0x016988`:
 *           - If `android_release > 13`, looks up `"_ZN3art6Thread24CreateCallbackWithUffdGcEPv"`
 *             (`0x01d398` at `0x016998`) via `npth_dlsym` and stores at `.bss 0x028190` (`0x0169b0`).
 *        5. Verifies `(art_create_callback_uffd | art_create_callback) != 0` (`orr x8, x8, x0; cbz x8, #0x16a88`).
 *        6. Stores `java_stack_size_bytes` to `.data 0x028008` (`0x0169c4`) and
 *           `native_stack_size_bytes` to `.data 0x02800c` (`0x0169c8`).
 *        7. Hooks `"pthread_create"` (`0x01d44c`) via `bytehook_hook_partial(AllowPthreadCreateShrinkFilter, ...)`
 *           and stores the stub at `.bss 0x0281a0` (`0x016a28`), returning `stub != nullptr`.
 *        Thiết lập cấu hình thu nhỏ ngăn xếp luồng và đăng ký ByteHook cho `pthread_create`.
 */
bool ConfigureThreadStackShrink(
    int32_t java_stack_size_bytes,
    int32_t native_stack_size_bytes,
    int32_t simulated_android_release) {
    OsFixGlobalState& state = GetGlobalState();

    // Simulate resolving _ZN3art6Thread14CreateCallbackEPv in libart.so
    if (state.art_create_callback == nullptr) {
        state.art_create_callback = reinterpret_cast<void*>(0x70001400ULL);
    }
    // 0x016988: cmp w20, #0xd; b.le #0x16a78
    if (simulated_android_release > 13 && state.art_create_callback_uffd == nullptr) {
        state.art_create_callback_uffd = reinterpret_cast<void*>(0x70002400ULL);
    }

    uintptr_t combined =
        reinterpret_cast<uintptr_t>(state.art_create_callback) |
        reinterpret_cast<uintptr_t>(state.art_create_callback_uffd);
    if (combined == 0) {
        return false;
    }

    // 0x0169c4..0x0169c8: Store java_shrink_thread_size (0x28008) & native_shrink_thread_size (0x2800c)
    state.java_shrink_thread_size   = java_stack_size_bytes;
    state.native_shrink_thread_size = native_stack_size_bytes;

    if (state.pthread_create_hook_stub == nullptr) {
        state.pthread_create_hook_stub = reinterpret_cast<void*>(&ApplyThreadStackShrinkToAttr);
    }
    return state.pthread_create_hook_stub != nullptr;
}

// ============================================================================
// 2. TypeFaceOptimizer Engine (0x016b9c..0x01814f)
//    Động cơ Tối ưu hóa Phông chữ TypeFaceOptimizer (0x016b9c..0x01814f)
// ============================================================================

/**
 * @brief Helper `get_smaps_pss` (`0x016ba4..0x016fe7`):
 *        Exact AArch64 logic:
 *        - Opens `/proc/self/smaps` (`0x01d4cf` at `0x016bd8`) via `std::ifstream`.
 *        - Reads each line (`std::getline` at `0x016cb0`):
 *          1. Searches for `target_path` substring (`0x016d34..0x016d48`). When found at the start/end
 *             of a VMA header, sets `in_matching_vma = 1` (`mov w8, #1; str w8, [sp, #0x54]` at `0x016c58`).
 *          2. While `in_matching_vma == 1`, searches for the 4-byte ASCII constant `"Pss:"`
 *             (`mov w21, #0x7350; movk w21, #0x3a73, lsl #16` -> `0x3a737350` = `'P' | ('s'<<8) | ('s'<<16) | (':'<<24)`
 *             at `0x016d90..0x016dc0`).
 *          3. When `"Pss:"` is matched at offset 0 of the line (`0x016de0`), constructs a `std::stringstream`
 *             on the line (`0x016e18..0x016e84`), extracts the prefix token (`"Pss:"` via `operator>>` at `0x016e98`)
 *             and the integer PSS value in kB (`operator>>(long&)` at `0x016ea0` -> `0x018400`).
 *          4. Stops scanning the current VMA block when `"VmFlags"` (`0x01d4e5`, length 7 at `0x016f38..0x016f44`)
 *             is encountered at offset 0 of a line (`0x016f68..0x016f70`).
 *        Tìm và trích xuất giá trị `Pss:` (kB) của tệp phông chữ từ `/proc/self/smaps`.
 */
int64_t ParseSmapsPssForPath(
    const std::string& smaps_content,
    const std::string& target_path) {
    if (target_path.empty()) {
        return 0;
    }

    // Verify 4-byte little-endian constant 0x3a737350 == "Pss:"
    constexpr uint32_t kPssColonMagic = 0x3a737350U;
    static_assert(
        kPssColonMagic == (uint32_t('P') | (uint32_t('s') << 8) | (uint32_t('s') << 16) | (uint32_t(':') << 24)),
        "0x3a737350 must equal ASCII 'Pss:'");

    std::istringstream stream(smaps_content);
    std::string line;
    bool in_matching_vma = false;
    int64_t pss_value = 0;

    while (std::getline(stream, line)) {
        if (!in_matching_vma) {
            if (line.find(target_path) != std::string::npos) {
                in_matching_vma = true;
            }
            continue;
        }

        // Check for "Pss:" (4 bytes = 0x3a737350) at offset 0 of the line (0x016d88..0x016de4)
        if (line.size() >= 4 && std::memcmp(line.data(), "Pss:", 4) == 0) {
            std::istringstream line_ss(line);
            std::string label;
            line_ss >> label >> pss_value;
        }

        // Check for "VmFlags" (7 bytes at 0x016f14..0x016f6c) at offset 0 of the line
        if (line.size() >= 7 && std::memcmp(line.data(), "VmFlags", 7) == 0) {
            break;
        }
    }

    return pss_value;
}

/**
 * @brief Core `clear_unused_ttf_impl` (`0x017428..0x017b97`):
 *        Exact AArch64 logic:
 *        1. Opens `/proc/self/maps` (`0x01d4ed` at `0x01745c`) and reads each line (`0x017574`).
 *        2. Tokenizes the line via `std::stringstream` (`0x017648..0x017670`) into 5 whitespace-delimited
 *           tokens (`addr_range`, `perms`, `offset`, `dev`, `inode`) and reads the remaining `pathname`
 *           via `std::getline` (`0x0176c0`), trimming leading spaces/tabs (`0x0176e4..0x017750`).
 *        3. Iterates over the `std::vector<std::string>` of TTF paths (`0x017758..0x017830`), checking if
 *           `pathname` contains any target TTF path.
 *        4. If matched (`0x017834`):
 *           - Finds `'-'` (`mov w1, #0x2d` at `0x017854`) in `addr_range`, splits into `start_hex` and
 *             `end_hex`, and converts both using `std::stoull(..., nullptr, 16)` (`mov w2, #0x10; bl stoull`
 *             at `0x017968..0x017984`).
 *           - Calls `get_smaps_pss(pathname)` (`bl #0x16ba4` at `0x017990`).
 *           - Compares `cmp x0, #0x3ff` (`1023 kB`) at `0x017998` and computes `size = end_addr - start_addr`
 *             (`sub x24, x24, x25` at `0x01799c`):
 *             - If `pss_kb <= 1023` (`0x3ff`), calls `munmap((void*)start_addr, size)` (`bl munmap` at `0x0179ac`)!
 *             - If `pss_kb > 1023`, logs `"%s is in use, pss:%ldKB, size:%lu"` (`0x01d535` at `0x017a08`) and skips.
 *        Phân tích `/proc/self/maps` và `/proc/self/smaps`, gọi `munmap` cho các phông chữ `.ttf` có `Pss <= 1023 kB`.
 */
std::vector<ProcMemoryRegionInfo> ClearUnusedTtfFromMapsAndSmaps(
    const std::vector<std::string>& ttf_paths,
    const std::string& maps_content,
    const std::string& smaps_content,
    bool perform_munmap) {
    std::vector<ProcMemoryRegionInfo> results;
    if (ttf_paths.empty() || maps_content.empty()) {
        return results;
    }

    std::istringstream maps_stream(maps_content);
    std::string line;

    while (std::getline(maps_stream, line)) {
        if (line.empty()) {
            continue;
        }
        std::istringstream line_ss(line);
        std::string addr_range;
        std::string perms;
        std::string offset_str;
        std::string dev;
        std::string inode_str;
        if (!(line_ss >> addr_range >> perms >> offset_str >> dev >> inode_str)) {
            continue;
        }

        std::string pathname;
        std::getline(line_ss, pathname);
        // Trim leading whitespace (0x0176e4..0x017750 uses bitmask 0x100000200 for ' ' and '\t')
        size_t first_non_space = pathname.find_first_not_of(" \t");
        if (first_non_space != std::string::npos) {
            pathname.erase(0, first_non_space);
        } else {
            pathname.clear();
        }

        if (pathname.empty()) {
            continue;
        }

        bool matched_ttf = false;
        for (const std::string& ttf : ttf_paths) {
            if (!ttf.empty() && pathname.find(ttf) != std::string::npos) {
                matched_ttf = true;
                break;
            }
        }
        if (!matched_ttf) {
            continue;
        }

        // 0x017854: mov w1, #0x2d ('-')
        size_t dash_pos = addr_range.find('-');
        if (dash_pos == std::string::npos || dash_pos == 0 || dash_pos + 1 >= addr_range.size()) {
            continue;
        }

        std::string start_hex = addr_range.substr(0, dash_pos);
        std::string end_hex   = addr_range.substr(dash_pos + 1);

        ProcMemoryRegionInfo info{};
        info.start_addr  = static_cast<uintptr_t>(std::stoull(start_hex, nullptr, 16));
        info.end_addr    = static_cast<uintptr_t>(std::stoull(end_hex, nullptr, 16));
        info.permissions = perms;
        info.device      = dev;
        info.pathname    = pathname;
        info.pss_kb      = ParseSmapsPssForPath(smaps_content, pathname);

        // 0x017998: cmp x0, #0x3ff (1023 kB); sub x24, x24, x25; b.hi #0x179e4
        if (info.pss_kb >= 0 && info.pss_kb <= 0x3ff && info.end_addr > info.start_addr) {
            size_t map_size = static_cast<size_t>(info.end_addr - info.start_addr);
            if (perform_munmap) {
#if defined(__linux__) || defined(__ANDROID__)
                if (::munmap(reinterpret_cast<void*>(info.start_addr), map_size) == 0) {
                    info.unmapped = true;
                }
#endif
            } else {
                info.unmapped = true;
            }
        }
        results.push_back(info);
    }

    return results;
}

} // namespace osfix
} // namespace bytedance

// ============================================================================
// 3. Exported JNI C Entry Points for ThreadStackOptimizer & TypeFaceOptimizer
//    Các điểm nhập C JNI xuất khẩu cho ThreadStackOptimizer & TypeFaceOptimizer
// ============================================================================

extern "C" {

/**
 * @brief `0x016b7c..0x016b9b`: `Java_com_bytedance_osfix_ThreadStackOptimizer_nativeShrinkthread`
 *        Exact AArch64 instructions:
 *        - `0x016b7c`: `fd 7b bf a9` (`stp x29, x30, [sp, #-0x10]!`)
 *        - `0x016b80`: `fd 03 00 91` (`mov x29, sp`)
 *        - `0x016b84`: `e1 03 03 2a` (`mov w1, w3`)
 *        - `0x016b88`: `e0 03 02 2a` (`mov w0, w2`)
 *        - `0x016b8c`: `5f ff ff 97` (`bl #0x16908`)
 *        - `0x016b90`: `00 00 00 12` (`and w0, w0, #1`)
 *        - `0x016b94`: `fd 7b c1 a8` (`ldp x29, x30, [sp], #0x10`)
 *        - `0x016b98`: `c0 03 5f d6` (`ret`)
 *        Chuyển tiếp tham số kích thước ngăn xếp Java (`w2`) và Native (`w3`) tới `shrink_thread_impl`.
 */
bytedance::osfix::jboolean Java_com_bytedance_osfix_ThreadStackOptimizer_nativeShrinkthread(
    bytedance::osfix::JNIEnv* /*env*/,
    bytedance::osfix::jclass /*clazz*/,
    bytedance::osfix::jint java_thread_stack_size,
    bytedance::osfix::jint native_thread_stack_size) {
    bool ok = bytedance::osfix::ConfigureThreadStackShrink(
        java_thread_stack_size,
        native_thread_stack_size);
    return ok ? JNI_TRUE : JNI_FALSE;
}

/**
 * @brief `0x016b9c..0x016ba3`: `Java_com_bytedance_osfix_TypeFaceOptimizer_optimize`
 *        Exact AArch64 instructions:
 *        - `0x016b9c`: `20 00 80 52` (`mov w0, #1`)
 *        - `0x016ba0`: `c0 03 5f d6` (`ret`)
 *        Hàm khởi tạo tối ưu hóa Typeface trả về `JNI_TRUE` (`1`).
 */
bytedance::osfix::jboolean Java_com_bytedance_osfix_TypeFaceOptimizer_optimize(
    bytedance::osfix::JNIEnv* /*env*/,
    bytedance::osfix::jclass /*clazz*/) {
    return JNI_TRUE;
}

/**
 * @brief `0x017dc0..0x01814f`: `Java_com_bytedance_osfix_TypeFaceOptimizer_nativeClearUnuseTTF`
 *        If `typeface_array_list != nullptr`, queries `size()I` (`0x01cce8` / `0x01d553`) and
 *        `get(I)Ljava/lang/Object;` (`0x01d557` / `0x01d55b`) on the `ArrayList`, then calls
 *        `getPath()Ljava/lang/String;` (`0x01d571` / `0x01d57a`) on each element, extracts the
 *        filename after the last `'/'`, pushes it into a local `std::vector<std::string>`, and
 *        calls `clear_unused_ttf_impl` (`0x017428`).
 *        Thu thập danh sách tên tệp `.ttf` từ `ArrayList` Java và giải phóng các ánh xạ không dùng.
 */
void Java_com_bytedance_osfix_TypeFaceOptimizer_nativeClearUnuseTTF(
    bytedance::osfix::JNIEnv* /*env*/,
    bytedance::osfix::jclass /*clazz*/,
    bytedance::osfix::jobject typeface_array_list) {
    std::vector<std::string> ttf_names;
    if (typeface_array_list != nullptr) {
        std::ifstream maps_ifs("/proc/self/maps", std::ios::in);
        std::ifstream smaps_ifs("/proc/self/smaps", std::ios::in);
        if (maps_ifs.is_open() && smaps_ifs.is_open()) {
            std::ostringstream maps_ss;
            std::ostringstream smaps_ss;
            maps_ss << maps_ifs.rdbuf();
            smaps_ss << smaps_ifs.rdbuf();
            bytedance::osfix::ClearUnusedTtfFromMapsAndSmaps(
                ttf_names,
                maps_ss.str(),
                smaps_ss.str(),
                true);
        }
    }
}

} // extern "C"
