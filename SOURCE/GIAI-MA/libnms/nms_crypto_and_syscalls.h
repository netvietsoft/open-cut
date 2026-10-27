/**
 * @file nms_crypto_and_syscalls.h
 * @brief Clean-room C++17 declarations for libnms.so cryptography, MBA deobfuscation, opaque predicates,
 *        custom setjmp/longjmp, and +0xE9 shifted syscall bridge.
 *        Khai báo C++17 clean-room cho giải mã mật mã, khử làm rối MBA, vị từ mờ lý thuyết số,
 *        setjmp/longjmp tùy chỉnh và cầu nối syscall dịch chuyển +0xE9 của libnms.so.
 */

#ifndef NEXTAI_OPENCUT_NMS_CRYPTO_AND_SYSCALLS_H_
#define NEXTAI_OPENCUT_NMS_CRYPTO_AND_SYSCALLS_H_

#include "nms_types.h"
#include <cstddef>
#include <cstdint>
#include <string>

namespace nextai {
namespace opencut {
namespace nms {

/**
 * @brief Reconstructs sub_14bd4 (0x014bd4 .. 0x014c00): Null-terminated key XOR stream decryptor.
 *        Tái tạo hàm sub_14bd4 (0x014bd4 .. 0x014c00): Bộ giải mã dòng XOR với khóa kết thúc bằng byte 0x00.
 *
 * AArch64 Disassembly (0x014bd4 .. 0x014c00):
 *   0x014bd4: 39400048  ldrb w8, [x2]
 *   0x014bd8: 34000108  cbz  w8, #0x14bf8
 *   0x014bdc: d2800029  mov  x9, #1
 *   0x014be0: 3840140a  ldrb w10, [x0], #1
 *   0x014be4: 4a080148  eor  w8, w10, w8
 *   0x014be8: 38001428  strb w8, [x1], #1
 *   0x014bec: 38696848  ldrb w8, [x2, x9]
 *   0x014bf0: 91000529  add  x9, x9, #1
 *   0x014bf4: 35ffff68  cbnz w8, #0x14be0
 *   0x014bf8: 3900003f  strb wzr, [x1]
 *   0x014bfc: d65f03c0  ret
 *
 * @param ciphertext Pointer to ciphertext bytes (x0). / Con trỏ mảng ciphertext (x0).
 * @param out_buffer Pointer to output buffer (x1). / Con trỏ bộ đệm đầu ra (x1).
 * @param key        Pointer to null-terminated key bytes (x2). / Con trỏ khóa kết thúc bằng null (x2).
 * @return Number of bytes decrypted (excluding null terminator). / Số byte đã giải mã (không tính byte 0 cuối).
 */
size_t nms_xor_decrypt_14bd4(const uint8_t* ciphertext,
                             uint8_t* out_buffer,
                             const uint8_t* key) noexcept;

/**
 * @brief Convenience wrapper around nms_xor_decrypt_14bd4 returning std::string.
 *        Hàm bọc tiện ích quanh nms_xor_decrypt_14bd4 trả về std::string.
 */
std::string nms_xor_decrypt_to_string(const uint8_t* ciphertext,
                                      const uint8_t* key);

/**
 * @brief Reconstructs sub_1ba38 (0x01ba38 .. 0x01bde4): OLLVM-flattened RC4 (ARC4) 256-byte S-Box
 *        Key-Scheduling Algorithm (KSA) + Pseudo-Random Generation Algorithm (PRGA).
 *        Tái tạo hàm sub_1ba38 (0x01ba38 .. 0x01bde4): Thuật toán lập lịch khóa (KSA) + sinh dòng giả ngẫu nhiên (PRGA)
 *        RC4 (ARC4) S-Box 256-byte bị làm phẳng luồng điều khiển bởi OLLVM.
 *
 * @param pkt Pointer to NmsRc4Packet on stack (x0). / Con trỏ tới NmsRc4Packet trên stack (x0).
 * @return Decrypted byte count (w19). / Số lượng byte đã giải mã (w19).
 */
uint32_t nms_rc4_crypt_1ba38(const NmsRc4Packet* pkt) noexcept;

/**
 * @brief Reconstructs sub_1bde4 (0x01bde4 .. 0x01be54): Stack-frame builder & wrapper for sub_1ba38.
 *        Tái tạo hàm sub_1bde4 (0x01bde4 .. 0x01be54): Hàm dựng khung stack và bọc quanh sub_1ba38.
 *
 * AArch64 Disassembly (0x01bde4 .. 0x01be54):
 *   Packs {x0=ct, x1=ct_len, x2=key, w3=key_len, x4=out_buf} into NmsRc4Packet at sp+0x00
 *   and calls bl #0x1ba38.
 */
uint32_t nms_rc4_decrypt_1bde4(const uint8_t* ciphertext,
                               uint32_t ciphertext_len,
                               const uint8_t* key,
                               uint32_t key_len,
                               uint8_t* out_buffer) noexcept;

/**
 * @brief Convenience wrapper around nms_rc4_decrypt_1bde4 returning std::string.
 *        Hàm bọc tiện ích quanh nms_rc4_decrypt_1bde4 trả về std::string.
 */
std::string nms_rc4_decrypt_to_string(const uint8_t* ciphertext,
                                      uint32_t ciphertext_len,
                                      const uint8_t* key,
                                      uint32_t key_len = 4U);

/**
 * @brief Reconstructs the 64-bit Mixed Boolean-Arithmetic (MBA) offset computation at
 *        0x038b04..0x038b70 (sub_38a58) and 0x03c690..0x03c700 (sub_3c670).
 *        Tái tạo phép tính độ lệch 64-bit Mixed Boolean-Arithmetic (MBA) tại
 *        0x038b04..0x038b70 (sub_38a58) và 0x03c690..0x03c700 (sub_3c670).
 *
 * Formula verified directly from AArch64 instructions:
 *   orn_val = kMask1 | (~anchor_vaddr)
 *   mba_sum = (orn_val & kMask2) + (anchor_vaddr & kMask3)
 *   offset  = (mba_sum | kOrConst) ^ xor_key
 */
uint64_t nms_mba_compute_offset(uint64_t anchor_vaddr, uint64_t xor_key) noexcept;

/**
 * @brief Resolves an R_AARCH64_RELATIVE addend from .data using the MBA offset.
 *        Phân giải giá trị bù R_AARCH64_RELATIVE từ .data bằng độ lệch MBA.
 */
uint64_t nms_mba_resolve_pointer(uint64_t rela_addend,
                                 uint64_t anchor_vaddr,
                                 uint64_t xor_key) noexcept;

/**
 * @brief Reconstructs the OLLVM Pell-like quadratic non-residue mod 7 opaque predicate
 *        at 0x014610..0x014644 (x=340, y=509), 0x014a7c..0x014aac (x=127, y=336),
 *        and 0x038a88..0x038ac4 (x=207, y=140).
 *        Tái tạo vị từ mờ bất khả quy bậc hai Pell mod 7 của OLLVM tại
 *        0x014610..0x014644, 0x014a7c..0x014aac và 0x038a88..0x038ac4.
 *
 * Since -1 is a quadratic non-residue modulo 7 (x^2 mod 7 in {0, 1, 2, 4}),
 * x^2 + 1 is NEVER divisible by 7 for any integer x, so (x^2 + 1 - 7*y^2) != 0 holds 100%!
 *
 * @return Always true (opaque invariant). / Luôn trả về true (bất biến mờ).
 */
bool nms_eval_pell_mod7_predicate(uint32_t x, uint32_t y) noexcept;

/**
 * @brief Reconstructs the OLLVM quadratic non-residue mod 19 opaque predicate at
 *        0x014d14..0x014d64 (x=318, y=155) and 0x034974..0x0349c4 (x=294, y=352).
 *        Tái tạo vị từ mờ bất khả quy bậc hai mod 19 của OLLVM tại
 *        0x014d14..0x014d64 (x=318, y=155) và 0x034974..0x0349c4 (x=294, y=352).
 *
 * Uses magic reciprocal 0xAF286BCB to compute u = (4*x^2 + 4) mod 19.
 * Since 19 == 3 (mod 4), -1 is a quadratic non-residue mod 19, so 4*(x^2 + 1) mod 19 != 0
 * for every integer x!
 *
 * @return Always true (opaque invariant). / Luôn trả về true (bất biến mờ).
 */
bool nms_eval_mod19_predicate(uint32_t x, uint32_t y) noexcept;

/**
 * @brief Reconstructs the OLLVM multiplicative opaque predicate inside sub_1ba38 at 0x01bc20..0x01bc64.
 *        Tái tạo vị từ mờ nhân tính của OLLVM bên trong sub_1ba38 tại 0x01bc20..0x01bc64.
 *
 * At 0x01bc20..0x01bc60:
 *   w16 = 0x1d8 (472), w24 = 0xb9 (185), w26 = 0xB6DB6DB7
 *   w16 = (w16 * w16) * w26 + w26 = (w16^2 + 1) * 0xB6DB6DB7 (mod 2^32)
 *   Compares w16 against 0x24924924 and ccmp w24, #0x13, #0, ls -> always selects 0x5BF71CFC!
 */
uint32_t nms_eval_madd_predicate_1bc40(uint32_t x_val = 0x1D8U,
                                       uint32_t y_val = 0xB9U) noexcept;

/**
 * @brief Reconstructs sub_153f4 (0x0153f4 .. 0x015404): Returns the right-shift constant 2
 *        used by JNI_OnLoad (0x015074) and sub_38a58 (0x038a58) to decode jump offsets.
 *        Tái tạo hàm sub_153f4 (0x0153f4 .. 0x015404): Trả về hằng số dịch phải 2
 *        dùng bởi JNI_OnLoad (0x015074) và sub_38a58 (0x038a58) để giải mã độ lệch nhảy.
 */
uint32_t nms_shift_const_153f4(const char* numeric_str) noexcept;

/**
 * @brief Reconstructs sub_159f4 (0x0159f4 .. 0x015a64): OLLVM-wrapped strtoll parser.
 *        Tái tạo hàm sub_159f4 (0x0159f4 .. 0x015a64): Bộ phân tích số nguyên strtoll bọc OLLVM.
 */
int64_t nms_parse_int64_159f4(const char* str, char** endptr, int32_t base) noexcept;

/**
 * @brief Reconstructs the obfuscated target address computation used in JNI_OnLoad (0x015130..0x015158)
 *        and sub_38a58 (0x038bc8..0x038bf0) before invoking sub_3c108 (0x03c108).
 *        Tái tạo phép tính địa chỉ đích làm rối dùng trong JNI_OnLoad (0x015130..0x015158)
 *        và sub_38a58 (0x038bc8..0x038bf0) trước khi gọi sub_3c108 (0x03c108).
 *
 * Formula:
 *   parsed_val = nms_parse_int64_159f4(dec_str, nullptr, 10)
 *   shift_bits = nms_shift_const_153f4(dec_str)  // == 2
 *   target_va  = (base_anchor_va - (parsed_val >> shift_bits)) + addend_offset
 *
 * Verified instances:
 *   1) JNI_OnLoad (0x015074): base=0x014ddc, dec_str="5256" (5256>>2 = 0x522), addend=0x522 -> target=0x014ddc
 *   2) sub_38a58  (0x038a58): base=0x038c20, dec_str="38816" (38816>>2 = 0x25e8), addend=0x25e8 -> target=0x038c20
 */
uint64_t nms_compute_indirect_target(uint64_t base_anchor_va,
                                     const char* decrypted_num_str,
                                     uint64_t addend_offset) noexcept;

/**
 * @brief Reconstructs sub_3c0bc (0x03c0bc .. 0x03c0ec): Shifted AArch64 direct syscall dispatcher.
 *        Tái tạo hàm sub_3c0bc (0x03c0bc .. 0x03c0ec): Bộ điều phối syscall trực tiếp AArch64 dịch chuyển (+0xE9).
 *
 * Subtracts 0xE9 (233) from shifted_sysno to recover the true AArch64 Linux __NR_* syscall number,
 * and executes the corresponding clean-room host operation.
 */
int64_t nms_syscall_dispatch_3c0bc(uint32_t shifted_sysno,
                                   int64_t arg1 = 0,
                                   int64_t arg2 = 0,
                                   int64_t arg3 = 0,
                                   int64_t arg4 = 0,
                                   int64_t arg5 = 0,
                                   int64_t arg6 = 0) noexcept;

/**
 * @brief Pure mathematical translator from shifted_sysno (w0) to Linux AArch64 __NR_* number (x8).
 *        Hàm ánh xạ toán học thuần túy từ mã syscall dịch chuyển (w0) sang mã __NR_* Linux AArch64 (x8).
 */
constexpr uint32_t nms_unbias_syscall_number(uint32_t shifted_sysno) noexcept {
    return shifted_sysno - static_cast<uint32_t>(NmsShiftedSyscall::kSyscallBias);
}

/**
 * @brief Reconstructs sub_1be58 (0x01be58 .. 0x01bea8): Custom AArch64 setjmp saving x19..x30, sp, d8..d15.
 *        Tái tạo hàm sub_1be58 (0x01be58 .. 0x01bea8): Hàm setjmp AArch64 tùy chỉnh lưu x19..x30, sp, d8..d15.
 */
int32_t nms_setjmp_1be58(NmsJmpBuf* env) noexcept;

/**
 * @brief Reconstructs sub_1beac (0x01beac .. 0x01bf00): Custom AArch64 longjmp restoring x19..x30, sp, d8..d15.
 *        Tái tạo hàm sub_1beac (0x01beac .. 0x01bf00): Hàm longjmp AArch64 tùy chỉnh khôi phục x19..x30, sp, d8..d15.
 *
 * Note: At 0x01bef4: `cmp w1, #0; csinv w0, w1, wzr, ne` -> if val == 0, returns 1; else returns val!
 */
int32_t nms_longjmp_value_1beac(NmsJmpBuf* env, int32_t val) noexcept;

/**
 * @brief Initializes the 160-byte unaligned sentinel buffer (.bss 0x04f6c4) with the expected
 *        magic constants (0x100, 0x2f0, 0x3e0, ..., 0xb60).
 *        Khởi tạo bộ đệm sentinel lệch biên 160-byte (.bss 0x04f6c4) với các hằng số magic chuẩn.
 */
void nms_init_sentinel_buffer(std::array<uint8_t, 160>& buf) noexcept;

/**
 * @brief Reconstructs sub_34ab0 (0x034ab0 .. 0x034b60): Verifies the 11 unaligned 64-bit magic
 *        words in .bss 0x04f6c4 and returns a bitmask of tampered slots (0 if intact).
 *        Tái tạo hàm sub_34ab0 (0x034ab0 .. 0x034b60): Kiểm tra 11 từ 64-bit lệch biên trong
 *        .bss 0x04f6c4 và trả về mặt nạ bit các ô bị can thiệp (0 nếu toàn vẹn).
 */
uint32_t nms_verify_sentinel_buffer_34ab0(const std::array<uint8_t, 160>& buf) noexcept;

} // namespace nms
} // namespace opencut
} // namespace nextai

#endif // NEXTAI_OPENCUT_NMS_CRYPTO_AND_SYSCALLS_H_
