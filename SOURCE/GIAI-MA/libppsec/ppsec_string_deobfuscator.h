/**
 * @file ppsec_string_deobfuscator.h
 * @brief Clean-Room Header for Pairwise-XOR String Deobfuscator (`0x004714`) & OLLVM Opaque Predicates.
 *        Header tái tạo sạch bộ giải mã chuỗi XOR (`0x004714`) và các vị từ mờ OLLVM/Tigress của libppsec.so.
 *
 * Binary Target / Mục tiêu nhị phân:
 *   SOURCE/apktool-res/lib/arm64-v8a/libppsec.so
 *   Addresses covered / Phạm vi địa chỉ:
 *     - 0x002b38..0x00327c : OLLVM Indirect Branch & Quadratic / Consecutive-Product Opaque Predicates
 *     - 0x004714..0x004740 : Pairwise Byte-Array XOR String Decryptor (`dst[i] = src[i] ^ key[i]`)
 *     - 0x018968..0x01898c : Mixed Boolean-Arithmetic (MBA) Increment & XOR Identities
 *     - .rodata 0x01c920..0x024dc0 : Encrypted string pool & key pool (180+ entries)
 */

#ifndef NEXTAI_OPENCUT_PPSEC_STRING_DEOBFUSCATOR_H_
#define NEXTAI_OPENCUT_PPSEC_STRING_DEOBFUSCATOR_H_

#include "ppsec_types.h"

#include <cstddef>
#include <cstdint>
#include <string>
#include <vector>

namespace nextai {
namespace opencut {
namespace ppsec {

/**
 * @brief Reconstructs `sub_4714` (`0x004714..0x004740`):
 *        Decrypts `src` into `dst` using null-terminated `key` (`dst[i] = src[i] ^ key[i]` while `key[i] != 0`).
 *        Tái tạo hàm giải mã chuỗi XOR từng cặp byte `sub_4714` (`0x004714..0x004740`).
 *
 * Disassembly (`0x004714..0x004740`):
 *   - `0x004714: ldrb w8, [x2]`
 *   - `0x004718: cbz  w8, #0x4740`
 *   - `0x00471c: mov  x9, xzr`
 *   - `0x004720: mov  w10, #1`
 *   - `0x004724: ldrb w11, [x0, x9]`
 *   - `0x004728: eor  w8, w11, w8`
 *   - `0x00472c: strb w8, [x1, x9]`
 *   - `0x004730: sxtw x9, w10`
 *   - `0x004734: ldrb w8, [x2, x9]`
 *   - `0x004738: add  w10, w10, #1`
 *   - `0x00473c: cbnz w8, #0x4724`
 *   - `0x004740: ret`
 */
size_t XorDeobfuscateNullTerminated(const uint8_t* src,
                                    uint8_t* dst,
                                    const uint8_t* key,
                                    size_t max_len) noexcept;

std::string XorDeobfuscateToString(const uint8_t* src,
                                   const uint8_t* key,
                                   size_t max_len) noexcept;

/**
 * @brief Reconstructs OLLVM Quadratic Modular Inverse Predicate (`0x002b40..0x002b70`, `0x002dd4..0x002e08`):
 *        Evaluates whether `((x * x + 1) * 0xA1AF286CU) == 0x0D79435EU` (mod 2^32).
 *        Tái tạo vị từ mờ bậc hai nghịch đảo modulo (`0x002b40..0x002b70`, `0x002dd4..0x002e08`).
 */
bool EvaluateQuadraticModInversePredicate(uint32_t x) noexcept;

/**
 * @brief Reconstructs OLLVM Bitwise-Transformed Quadratic Predicate (`0x0031ac..0x00320c`):
 *        Evaluates `(((8 * x^2 | 8) - (4 * x^2 ^ 4)) * 0x286BCA1BU) == 0x0D79435EU` (mod 2^32).
 *        Note that `(8*x^2 | 8) - (4*x^2 ^ 4) == 4 * (x^2 + 1)` and `4 * 0x286BCA1B == 0xA1AF286C`!
 *        Tái tạo vị từ mờ bậc hai biến đổi bit (`0x0031ac..0x00320c`).
 */
bool EvaluateBitwiseQuadraticPredicate(uint32_t x) noexcept;

/**
 * @brief Reconstructs OLLVM 3-Consecutive-Integers Divisibility-by-6 Offset (`0x002ee0..0x002f14`, `0x003218..0x00325c`):
 *        Computes `p = n * (n + 1) * (n + 2)` and `q = umulh(p, 0xAAAAAAAAAAAAAAABULL) >> 1` (`p / 3`),
 *        returning `p - 3 * (q & ~1ULL)` which is identically `0` for all `n` because `6 | n(n+1)(n+2)`.
 *        Tái tạo hằng đẳng thức chia hết cho 6 của tích 3 số nguyên liên tiếp (`0x002ee0..0x002f14`).
 */
uint64_t EvaluateConsecutiveTripleMod6Offset(uint64_t n) noexcept;

/**
 * @brief Reconstructs OLLVM 2-Consecutive-Integers Parity Offset (`0x002fe4..0x002ff4`, `0x003210..0x003238`):
 *        Computes `(n * (n + 1)) & 1U`, which is identically `0` for all `n`.
 *        Tái tạo hằng đẳng thức tính chẵn lẻ của tích 2 số nguyên liên tiếp (`0x002fe4..0x002ff4`).
 */
uint32_t EvaluateConsecutivePairParityOffset(uint32_t n) noexcept;

/**
 * @brief Reconstructs OLLVM Pell's Equation Predicate (`0x003048..0x0030b4`):
 *        Evaluates whether `x * x + 1 == 7 * y * y` (mod 2^32), which is false for `(x=0xCD, y=0x141)`.
 *        Tái tạo vị từ mờ phương trình Pell `x^2 + 1 == 7*y^2` (`0x003048..0x0030b4`).
 */
bool EvaluatePell7Equation(uint32_t x, uint32_t y) noexcept;

/**
 * @brief Reconstructs Mixed Boolean-Arithmetic (MBA) XOR & Increment Identities (`0x018968..0x01898c`):
 *        - `MbaXorOrSubAnd(a, b) = (a | b) - (a & b) == a ^ b` (`0x018984..0x01898c`)
 *        - `MbaIncrementBy1(i)   = ((i << 1) | 2) - (i ^ 1) == i + 1` (`0x018968..0x01897c`)
 *        Tái tạo đồng nhất thức MBA XOR và tăng 1 tại `0x018968..0x01898c`.
 */
uint32_t MbaXorOrSubAnd(uint32_t a, uint32_t b) noexcept;
uint32_t MbaIncrementBy1(uint32_t i) noexcept;

/**
 * @brief Returns the catalog of decrypted `.rodata` string entries observed in `libppsec.so`.
 *        Trả về danh mục các chuỗi `.rodata` đã giải mã từ `libppsec.so`.
 */
const std::vector<PpsecXorStringEntry>& GetPpsecDecryptedStringCatalog() noexcept;

}  // namespace ppsec
}  // namespace opencut
}  // namespace nextai

#endif  // NEXTAI_OPENCUT_PPSEC_STRING_DEOBFUSCATOR_H_
