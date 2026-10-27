/**
 * @file maps_hook_scanner.h
 * @brief Clean-Room Header for /proc/self/maps Hook Framework & >39-Bit VMA Detector.
 *        Header tái tạo sạch cho Bộ quét Hook Framework trên /proc/self/maps và Phát hiện VMA >39-Bit.
 *
 * Binary Target / Mục tiêu nhị phân:
 *   SOURCE/apktool-res/lib/arm64-v8a/libgodzilla-sysopt.so
 *   Addresses covered / Phạm vi địa chỉ:
 *     - 0x0180f4..0x01828c : Java_com_bytedance_platform_godzilla_sysopt_ApkSha256_checkHookFrameworks
 *     - 0x019fb4..0x02207c : scanMapsForHookFrameworks() (.data 0x02f940)
 *     - 0x022108..0x022684 : Encrypted Hook Keyword Initializers (12 MBA rolling-XOR blobs)
 *     - 0x022688..0x0227b4 : std::vector<std::string> initializer for .bss 0x02fc40
 *     - 0x0227b8..0x022878 : endsWith(const std::string& str, const std::string& suffix)
 */

#ifndef NEXTAI_OPENCUT_GODZILLA_SYSOPT_MAPS_HOOK_SCANNER_H_
#define NEXTAI_OPENCUT_GODZILLA_SYSOPT_MAPS_HOOK_SCANNER_H_

#include "godzilla_sysopt_types.h"

#include <array>
#include <cstddef>
#include <cstdint>
#include <string>
#include <vector>

namespace nextai {
namespace opencut {
namespace godzilla_sysopt {

/**
 * @brief Encrypted Hook Keyword Descriptor [OBSERVED at 0x01b18c..0x022684]
 *        Mô tả từ khóa Hook Framework được mã hóa XOR trượt [QUAN SÁT ĐƯỢC tại 0x01b18c..0x022684]
 */
struct EncryptedKeywordBlob {
    uint8_t        base_key;
    uint8_t        byte_len;
    const uint8_t* enc_bytes;
    const char*    expected_plaintext;
};

/**
 * @brief Returns the 12 encrypted hook framework blobs embedded in `scanMapsForHookFrameworks`.
 *        Trả về 12 khối byte từ khóa hook framework được nhúng trong `scanMapsForHookFrameworks`.
 */
const std::array<EncryptedKeywordBlob, 12>& GetEncryptedHookKeywordBlobs() noexcept;

/**
 * @brief Decrypts a single rolling-XOR hook keyword blob using the exact MBA identity
 *        (`(a + b) - ((a & b) << 1)`) and opaque predicate scale from `0x01b210..0x01b248`.
 *        Giải mã một từ khóa hook bằng đồng nhất thức MBA (`(a + b) - ((a & b) << 1)`) tại `0x01b210..0x01b248`.
 */
std::string DecryptHookKeywordBlob(const EncryptedKeywordBlob& blob,
                                   const OpaquePredicateBlock& pred = kDefaultOpaquePredicateBlock);

/**
 * @brief Builds the 12-element `std::vector<std::string>` corresponding to `.bss 0x02fc40`
 *        (guarded by `__cxa_guard_acquire` at `.bss 0x02fc38`, `0x01b184`).
 *        Khởi tạo danh sách 12 từ khóa hook tương ứng với `.bss 0x02fc40`.
 */
std::vector<std::string> GetDecryptedHookKeywords();

/**
 * @brief Reconstructs `endsWith` (`0x0227b8..0x022878`):
 *        Checks whether `full_str` ends with `suffix` (used for `.so`, `.jar`, `.apk`, `.odex`, `.vdex`).
 *        Tái tạo hàm kiểm tra hậu tố chuỗi `endsWith` (`0x0227b8..0x022878`).
 */
bool StringEndsWith(const std::string& full_str, const std::string& suffix) noexcept;

/**
 * @brief Reconstructs the >39-bit VMA address check at `0x01a438..0x01a458`:
 *        `and x9, x9, #0xffffff8000000000; bfxil x9, x8, #0x27, #0x19; cmp x9, #0`
 *        Checks whether bits `[63:39]` of either `start_addr` (`x8`) or `end_addr` (`x9`) are non-zero.
 *        Kiểm tra địa chỉ vùng nhớ ảo VMA có vượt quá không gian 39-bit của Android ARM64 hay không.
 */
constexpr bool HasMoreThan39BitsInVma(uint64_t start_addr, uint64_t end_addr) noexcept {
    // Equivalent to: ((end_addr & 0xffffff8000000000ULL) | ((start_addr >> 39) & 0x1ffffffULL)) != 0
    const uint64_t high_end = end_addr & kVmaAbove39BitsMask;
    const uint64_t high_start_25 = (start_addr >> 39U) & 0x01FFFFFFULL;
    return (high_end | high_start_25) != 0ULL;
}

/**
 * @brief Reconstructs `scanMapsForHookFrameworks` (`0x019fb4..0x02207c`, `.data 0x02f940`):
 *        1. Parses each line of `/proc/self/maps` via `sscanf(line, "%lx-%lx r", &start, &end)` (`0x004207`).
 *        2. If `HasMoreThan39BitsInVma(start, end)` is true, logs `"More than 39 bits in maps"` (`0x00448d`)
 *           and returns `"use_more_than_39_bits"` (`0x003fb9`).
 *        3. Iterates the 12 decrypted hook keywords in `.bss 0x02fc40`: if a line contains `keyword` AND
 *           ends with `".so"`, `".jar"`, `".apk"`, `".odex"`, or `".vdex"`, logs
 *           `"Found hook framework keyword '%s' in maps: %s"` (`0x004a61`) and returns the line.
 *        4. Otherwise logs `"No hook frameworks found in maps"` (`0x004a8f`) and returns `""`.
 *        Tái tạo hàm `scanMapsForHookFrameworks` (`0x019fb4..0x02207c`, `.data 0x02f940`).
 */
std::string ScanMapsTextForHookFrameworks(const std::string& maps_content,
                                          std::string* out_log = nullptr);

}  // namespace godzilla_sysopt
}  // namespace opencut
}  // namespace nextai

#endif  // NEXTAI_OPENCUT_GODZILLA_SYSOPT_MAPS_HOOK_SCANNER_H_
