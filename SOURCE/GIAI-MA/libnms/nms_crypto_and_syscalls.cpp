/**
 * @file nms_crypto_and_syscalls.cpp
 * @brief Clean-room C++17 implementation of libnms.so cryptography, MBA pointer deobfuscation,
 *        OLLVM number-theoretic opaque predicates, custom setjmp/longjmp, and +0xE9 shifted syscalls.
 *        Triển khai C++17 clean-room cho giải mã mật mã, khử làm rối con trỏ MBA, vị từ mờ lý thuyết số
 *        OLLVM, setjmp/longjmp tùy chỉnh và cầu nối syscall dịch chuyển +0xE9 của libnms.so.
 */

#include "nms_crypto_and_syscalls.h"
#include "nms_rodata_tables.h"
#include <cstdlib>
#include <cstring>
#include <vector>

namespace nextai {
namespace opencut {
namespace nms {

/**
 * @brief Reconstructs sub_14bd4 (0x014bd4 .. 0x014c00): Null-terminated key XOR stream decryptor.
 *        Tái tạo hàm sub_14bd4 (0x014bd4 .. 0x014c00): Bộ giải mã dòng XOR với khóa kết thúc bằng byte 0x00.
 */
size_t nms_xor_decrypt_14bd4(const uint8_t* ciphertext,
                             uint8_t* out_buffer,
                             const uint8_t* key) noexcept {
    if (ciphertext == nullptr || out_buffer == nullptr || key == nullptr) {
        return 0U;
    }
    // 0x014bd4: ldrb w8, [x2]; cbz w8, #0x14bf8
    uint8_t w8 = key[0];
    if (w8 == 0U) {
        out_buffer[0] = 0U;
        return 0U;
    }
    // 0x014bdc: mov x9, #1
    size_t x9 = 1U;
    while (true) {
        // 0x014be0: ldrb w10, [x0], #1
        const uint8_t w10 = *ciphertext++;
        // 0x014be4: eor w8, w10, w8
        // 0x014be8: strb w8, [x1], #1
        *out_buffer++ = static_cast<uint8_t>(w10 ^ w8);
        // 0x014bec: ldrb w8, [x2, x9]
        w8 = key[x9];
        // 0x014bf0: add x9, x9, #1
        ++x9;
        // 0x014bf4: cbnz w8, #0x14be0
        if (w8 == 0U) {
            break;
        }
    }
    // 0x014bf8: strb wzr, [x1]
    *out_buffer = 0U;
    return x9 - 1U;
}

std::string nms_xor_decrypt_to_string(const uint8_t* ciphertext,
                                      const uint8_t* key) {
    if (ciphertext == nullptr || key == nullptr) {
        return {};
    }
    size_t klen = 0U;
    while (key[klen] != 0U) {
        ++klen;
    }
    std::vector<uint8_t> buf(klen + 1U, 0U);
    nms_xor_decrypt_14bd4(ciphertext, buf.data(), key);
    return std::string(reinterpret_cast<const char*>(buf.data()), klen);
}

/**
 * @brief Reconstructs sub_1ba38 (0x01ba38 .. 0x01bde4): OLLVM-flattened RC4 (ARC4) 256-byte S-Box
 *        Key-Scheduling Algorithm (KSA) + Pseudo-Random Generation Algorithm (PRGA).
 *        Tái tạo hàm sub_1ba38 (0x01ba38 .. 0x01bde4): Thuật toán RC4 (ARC4) KSA + PRGA bị làm phẳng
 *        luồng điều khiển bởi OLLVM.
 *
 * Exact state transitions verified at 0x01bab0 .. 0x01bda4:
 *   - State 0xBA527277 -> 0x75993646 (KSA loop header: w14 < 0x100)
 *   - State 0x504D3009 (KSA body: S[w14] = w14; K[w14] = key[w14 % key_len]) -> 0x472F5CB8 (w14++)
 *   - State 0x22514940 (Init S-Box permutation: w14=0, w15=0) -> 0x6F53FDB6 (w15 < 0x100)
 *   - State 0xFFAFB94C (w14 = (w14 + S[w15] + K[w15]) & 0xFF; swap(S[w15], S[w14])) -> 0xE7258560 (w15++)
 *   - State 0x523F91AA (Init PRGA: w13=0, w14=0, w15=0) -> 0x73EAF80B (w13 < w19)
 *   - State 0xB46D15B3 (PRGA step: w14=(w14+1)&0xFF; w15=(w15+S[w14])&0xFF; swap(S[w14], S[w15]);
 *                       out[w13] = ct[w13] ^ S[(S[w14]+S[w15])&0xFF]; w13++) -> 0x73EAF80B
 *   - State 0xC53E7034 (Opaque predicate 0x01bc20..0x01bc64) -> 0x5BF71CFC (out[ct_len]=0; return ct_len)
 */
uint32_t nms_rc4_crypt_1ba38(const NmsRc4Packet* pkt) noexcept {
    if (pkt == nullptr || pkt->ciphertext == nullptr || pkt->key == nullptr ||
        pkt->output_buffer == nullptr || pkt->key_len == 0U) {
        return 0U;
    }

    // Stack buffers at sp+0x120 (x20: S-Box, zeroed with size 0x200) and sp+0x20 (x21: K-Box, size 0x100)
    uint8_t s_box[512];
    uint8_t k_box[256];
    std::memset(s_box, 0, sizeof(s_box));
    std::memset(k_box, 0, sizeof(k_box));

    const uint8_t* x22_ct      = pkt->ciphertext;
    const uint32_t w19_ct_len  = static_cast<uint32_t>(pkt->ciphertext_len & 0xFFFFFFFFULL);
    const uint8_t* x25_key     = pkt->key;
    const uint32_t w27_key_len = pkt->key_len;
    uint8_t*       x28_out     = pkt->output_buffer;

    uint32_t w24_state = NmsRc4OllvmStates::kStateEntry;
    uint32_t w13_k     = 0U;
    uint32_t w14_i     = 0U;
    uint32_t w15_j     = 0U;

    while (true) {
        const uint32_t w16 = w24_state;
        if (w16 == NmsRc4OllvmStates::kStateEntry) {
            // 0x01bc04..0x01bc10: cmp w16, w8 (0xBA527277) -> w24 = 0x75993646
            w24_state = NmsRc4OllvmStates::kStateKsaCheck;
        } else if (w16 == NmsRc4OllvmStates::kStateKsaCheck) {
            // 0x01bbbc..0x01bbc4: cmp w14, #0x100; csel w24, w6, w3, lo
            w24_state = (w14_i < 0x100U)
                ? NmsRc4OllvmStates::kStateKsaBody
                : NmsRc4OllvmStates::kStatePermInit;
        } else if (w16 == NmsRc4OllvmStates::kStateKsaBody) {
            // 0x01bcb4..0x01bcd0:
            // udiv w16, w14, w27; strb w14, [x20, w14]; msub w16, w16, w27, w14; ldrb/strb K[w14]
            s_box[w14_i] = static_cast<uint8_t>(w14_i & 0xFFU);
            const uint32_t rem = w14_i % w27_key_len;
            k_box[w14_i] = x25_key[rem];
            w24_state = NmsRc4OllvmStates::kStateKsaNext;
        } else if (w16 == NmsRc4OllvmStates::kStateKsaNext) {
            // 0x01bc7c..0x01bc88: add w14, w14, #1; w24 = 0x75993646
            ++w14_i;
            w24_state = NmsRc4OllvmStates::kStateKsaCheck;
        } else if (w16 == NmsRc4OllvmStates::kStatePermInit) {
            // 0x01bce4..0x01bcf4: mov w14, wzr; mov w15, wzr; w24 = 0x6F53FDB6
            w14_i = 0U;
            w15_j = 0U;
            w24_state = NmsRc4OllvmStates::kStatePermCheck;
        } else if (w16 == NmsRc4OllvmStates::kStatePermCheck) {
            // 0x01bc9c..0x01bca4: cmp w15, #0x100; csel w24, w2, w7, lo
            w24_state = (w15_j < 0x100U)
                ? NmsRc4OllvmStates::kStatePermSwap
                : NmsRc4OllvmStates::kStatePrgaInit;
        } else if (w16 == NmsRc4OllvmStates::kStatePermSwap) {
            // 0x01bb64..0x01bb8c:
            // w16 = S[w15]; w24 = K[w15]; w14 = (w14 + w16 + w24) & 0xFF; swap(S[w15], S[w14])
            const uint8_t s_i = s_box[w15_j];
            const uint8_t k_i = k_box[w15_j];
            w14_i = (w14_i + static_cast<uint32_t>(s_i) + static_cast<uint32_t>(k_i)) & 0xFFU;
            const uint8_t s_j = s_box[w14_i];
            s_box[w15_j] = s_j;
            s_box[w14_i] = s_i;
            w24_state = NmsRc4OllvmStates::kStatePermNext;
        } else if (w16 == NmsRc4OllvmStates::kStatePermNext) {
            // 0x01bcd4..0x01bce0: add w15, w15, #1; w24 = 0x6F53FDB6
            ++w15_j;
            w24_state = NmsRc4OllvmStates::kStatePermCheck;
        } else if (w16 == NmsRc4OllvmStates::kStatePrgaInit) {
            // 0x01bbe4..0x01bbf8: mov w13, wzr; mov w14, wzr; mov w15, wzr; w24 = 0x73EAF80B
            w13_k = 0U;
            w14_i = 0U;
            w15_j = 0U;
            w24_state = NmsRc4OllvmStates::kStatePrgaCheck;
        } else if (w16 == NmsRc4OllvmStates::kStatePrgaCheck) {
            // 0x01bca8..0x01bcb0: cmp w13, w19; csel w24, w11, w12, lo
            w24_state = (w13_k < w19_ct_len)
                ? NmsRc4OllvmStates::kStatePrgaStep
                : NmsRc4OllvmStates::kStatePrgaDone;
        } else if (w16 == NmsRc4OllvmStates::kStatePrgaStep) {
            // 0x01bd40..0x01bd88:
            // w14 = (w14 + 1) & 0xFF; w16 = S[w14]; w15 = (w15 + w16) & 0xFF;
            // swap(S[w14], S[w15]); t = (S[w14] + S[w15]) & 0xFF; out[w13] = ct[w13] ^ S[t]; w13++
            w14_i = (w14_i + 1U) & 0xFFU;
            const uint8_t s_i = s_box[w14_i];
            w15_j = (w15_j + static_cast<uint32_t>(s_i)) & 0xFFU;
            const uint8_t s_j = s_box[w15_j];
            s_box[w14_i] = s_j;
            s_box[w15_j] = s_i;
            const uint32_t t = (static_cast<uint32_t>(s_box[w14_i]) + static_cast<uint32_t>(s_i)) & 0xFFU;
            x28_out[w13_k] = static_cast<uint8_t>(x22_ct[w13_k] ^ s_box[t]);
            ++w13_k;
            w24_state = NmsRc4OllvmStates::kStatePrgaCheck;
        } else if (w16 == NmsRc4OllvmStates::kStatePrgaDone) {
            // 0x01bc20..0x01bc64: Opaque predicate -> transitions to 0x5BF71CFC (kStateExit)
            w24_state = nms_eval_madd_predicate_1bc40(0x1D8U, 0xB9U);
        } else if (w16 == NmsRc4OllvmStates::kStateExit) {
            // 0x01bda0..0x01bdbc: strb wzr, [x28, x8]; mov w0, w19; ret
            x28_out[w19_ct_len] = 0U;
            return w19_ct_len;
        } else {
            break;
        }
    }
    return 0U;
}

/**
 * @brief Reconstructs sub_1bde4 (0x01bde4 .. 0x01be54): Stack-frame builder & wrapper for sub_1ba38.
 *        Tái tạo hàm sub_1bde4 (0x01bde4 .. 0x01be54): Hàm dựng khung stack và bọc quanh sub_1ba38.
 */
uint32_t nms_rc4_decrypt_1bde4(const uint8_t* ciphertext,
                               uint32_t ciphertext_len,
                               const uint8_t* key,
                               uint32_t key_len,
                               uint8_t* out_buffer) noexcept {
    NmsRc4Packet pkt{};
    pkt.ciphertext     = ciphertext;
    pkt.ciphertext_len = static_cast<uint64_t>(ciphertext_len);
    pkt.key            = key;
    pkt.key_len        = key_len;
    pkt.reserved_pad   = 0U;
    pkt.output_buffer  = out_buffer;
    return nms_rc4_crypt_1ba38(&pkt);
}

std::string nms_rc4_decrypt_to_string(const uint8_t* ciphertext,
                                      uint32_t ciphertext_len,
                                      const uint8_t* key,
                                      uint32_t key_len) {
    if (ciphertext == nullptr || key == nullptr || ciphertext_len == 0U || key_len == 0U) {
        return {};
    }
    std::vector<uint8_t> buf(static_cast<size_t>(ciphertext_len) + 1U, 0U);
    nms_rc4_decrypt_1bde4(ciphertext, ciphertext_len, key, key_len, buf.data());
    return std::string(reinterpret_cast<const char*>(buf.data()), static_cast<size_t>(ciphertext_len));
}

/**
 * @brief Reconstructs the 64-bit Mixed Boolean-Arithmetic (MBA) offset computation at
 *        0x038b04..0x038b70 (sub_38a58) and 0x03c690..0x03c700 (sub_3c670).
 *        Tái tạo phép tính độ lệch 64-bit Mixed Boolean-Arithmetic (MBA) tại
 *        0x038b04..0x038b70 (sub_38a58) và 0x03c690..0x03c700 (sub_3c670).
 */
uint64_t nms_mba_compute_offset(uint64_t anchor_vaddr, uint64_t xor_key) noexcept {
    // orn x11, kMask1, anchor_vaddr
    const uint64_t orn_val = NmsMbaConstants::kMask1 | (~anchor_vaddr);
    // and x10, orn_val, kMask2; and x9, anchor_vaddr, kMask3; add mba_sum, x10, x9
    const uint64_t mba_sum = (orn_val & NmsMbaConstants::kMask2) +
                             (anchor_vaddr & NmsMbaConstants::kMask3);
    // orr x8, mba_sum, kOrConst; eor offset, x8, xor_key
    return (mba_sum | NmsMbaConstants::kOrConst) ^ xor_key;
}

uint64_t nms_mba_resolve_pointer(uint64_t rela_addend,
                                 uint64_t anchor_vaddr,
                                 uint64_t xor_key) noexcept {
    const uint64_t mba_offset = nms_mba_compute_offset(anchor_vaddr, xor_key);
    return rela_addend + mba_offset;
}

/**
 * @brief Reconstructs the OLLVM Pell-like quadratic non-residue mod 7 opaque predicate
 *        at 0x014610..0x014644, 0x014a7c..0x014aac, and 0x038a88..0x038ac4.
 *        Tái tạo vị từ mờ bất khả quy bậc hai Pell mod 7 của OLLVM.
 *
 * Binary disassembly at 0x014610..0x014644:
 *   mul w8, w8, w8         // x^2
 *   add w8, w8, #1         // x^2 + 1
 *   mul w9, w9, w9         // y^2
 *   sub w9, w9, w9, lsl #3 // -7 * y^2
 *   cmp w8, w9             // compares x^2 + 1 == -7 * y^2 (or at 0x038a9c: (x^2 + 1) mod 7 != 0)
 */
bool nms_eval_pell_mod7_predicate(uint32_t x, uint32_t y) noexcept {
    const uint32_t lhs = x * x + 1U;
    const uint32_t y_sq = y * y;
    const uint32_t rhs = y_sq - (y_sq << 3U); // -7 * y^2 (mod 2^32)

    // Also evaluate the magic reciprocal mod-7 check at 0x038a9c..0x038ac4:
    // w9 = 0x24924925; umull x9, w8, w9; lsr x9, x9, #32; sub w10, w8, w9;
    // add w9, w9, w10, lsr #1; lsr w9, w9, #2; sub w9, w9, w9, lsl #3; add w8, w8, w9
    const uint64_t prod = static_cast<uint64_t>(lhs) * 0x24924925ULL;
    uint32_t q = static_cast<uint32_t>(prod >> 32U);
    const uint32_t diff = lhs - q;
    q = (q + (diff >> 1U)) >> 2U; // floor(lhs / 7)
    const uint32_t rem7 = lhs - (q * 7U);

    return (lhs != rhs) && (rem7 != 0U);
}

/**
 * @brief Reconstructs the OLLVM quadratic non-residue mod 19 opaque predicate at
 *        0x014d14..0x014d64 (x=318, y=155) and 0x034974..0x0349c4 (x=294, y=352).
 *        Tái tạo vị từ mờ bất khả quy bậc hai mod 19 của OLLVM.
 *
 * Binary disassembly at 0x014d28..0x014d58:
 *   mul   w8, w8, w8          // x^2
 *   mov   w9, #0xAF286BCB     // magic multiplier for unsigned division by 19
 *   lsl   w8, w8, #2          // 4 * x^2
 *   add   w8, w8, #4          // 4 * x^2 + 4 = 4 * (x^2 + 1)
 *   umull x9, w8, w9
 *   lsr   x9, x9, #32
 *   sub   w10, w8, w9
 *   add   w9, w9, w10, lsr #1
 *   mov   w10, #19
 *   lsr   w9, w9, #4          // floor(w8 / 19)
 *   msub  w8, w9, w10, w8     // w8 mod 19
 *   cbnz  w8, <true_target>
 */
bool nms_eval_mod19_predicate(uint32_t x, uint32_t y) noexcept {
    (void)y;
    const uint32_t w8 = ((x * x) << 2U) + 4U;
    const uint64_t prod = static_cast<uint64_t>(w8) * 0xAF286BCBULL;
    uint32_t w9 = static_cast<uint32_t>(prod >> 32U);
    const uint32_t w10 = w8 - w9;
    w9 = (w9 + (w10 >> 1U)) >> 4U;
    const uint32_t rem19 = w8 - (w9 * 19U);
    return rem19 != 0U;
}

/**
 * @brief Reconstructs the OLLVM multiplicative opaque predicate inside sub_1ba38 at 0x01bc20..0x01bc64.
 *        Tái tạo vị từ mờ nhân tính của OLLVM bên trong sub_1ba38 tại 0x01bc20..0x01bc64.
 */
uint32_t nms_eval_madd_predicate_1bc40(uint32_t x_val, uint32_t y_val) noexcept {
    // 0x01bc40: mul w16, w16, w16
    // 0x01bc44: madd w16, w16, w26, w26  (where w26 = 0xB6DB6DB7)
    const uint32_t w26 = 0xB6DB6DB7U;
    const uint32_t w16 = (x_val * x_val) * w26 + w26;
    // 0x01bc50: cmp w16, #0x24924924; ccmp w24, #0x13, #0, ls; csel w24, 0x5BF71CFC, 0x51AC33A6, gt
    const bool cond_ls = (w16 <= 0x24924924U);
    const bool cond_gt = cond_ls ? (static_cast<int32_t>(y_val) > 0x13) : true;
    return cond_gt ? NmsRc4OllvmStates::kStateExit : 0x51AC33A6U;
}

/**
 * @brief Reconstructs sub_153f4 (0x0153f4 .. 0x015404): Returns the right-shift constant 2.
 *        Tái tạo hàm sub_153f4 (0x0153f4 .. 0x015404): Trả về hằng số dịch phải 2.
 */
uint32_t nms_shift_const_153f4(const char* numeric_str) noexcept {
    (void)numeric_str;
    return 2U;
}

/**
 * @brief Reconstructs sub_159f4 (0x0159f4 .. 0x015a64): OLLVM-wrapped strtoll parser.
 *        Tái tạo hàm sub_159f4 (0x0159f4 .. 0x015a64): Bộ phân tích số nguyên strtoll bọc OLLVM.
 */
int64_t nms_parse_int64_159f4(const char* str, char** endptr, int32_t base) noexcept {
    if (str == nullptr) {
        return 0;
    }
    return static_cast<int64_t>(std::strtoll(str, endptr, base));
}

/**
 * @brief Reconstructs the obfuscated target address computation used in JNI_OnLoad (0x015130..0x015158)
 *        and sub_38a58 (0x038bc8..0x038bf0) before invoking sub_3c108 (0x03c108).
 *        Tái tạo phép tính địa chỉ đích làm rối trước khi gọi sub_3c108 (0x03c108).
 */
uint64_t nms_compute_indirect_target(uint64_t base_anchor_va,
                                     const char* decrypted_num_str,
                                     uint64_t addend_offset) noexcept {
    const int64_t  parsed_val = nms_parse_int64_159f4(decrypted_num_str, nullptr, 10);
    const uint32_t shift_bits = nms_shift_const_153f4(decrypted_num_str);
    const int64_t  shifted    = parsed_val >> shift_bits;
    // sub x8, base_anchor_va, shifted; add x0, x8, addend_offset
    return (base_anchor_va - static_cast<uint64_t>(shifted)) + addend_offset;
}

/**
 * @brief Reconstructs sub_3c0bc (0x03c0bc .. 0x03c0ec): Shifted AArch64 direct syscall dispatcher.
 *        Tái tạo hàm sub_3c0bc (0x03c0bc .. 0x03c0ec): Bộ điều phối syscall trực tiếp AArch64 dịch chuyển (+0xE9).
 *
 * AArch64 Disassembly (0x03c0bc .. 0x03c0ec):
 *   0x03c0bc: d103a400  sub  x0, x0, #0xe9
 *   0x03c0c0: aa0003e8  mov  x8, x0
 *   0x03c0c4: aa0103e0  mov  x0, x1
 *   0x03c0c8: aa0203e1  mov  x1, x2
 *   0x03c0cc: aa0303e2  mov  x2, x3
 *   0x03c0d0: aa0403e3  mov  x3, x4
 *   0x03c0d4: aa0503e4  mov  x4, x5
 *   0x03c0d8: aa0603e5  mov  x5, x6
 *   0x03c0dc: d4000001  svc  #0
 */
int64_t nms_syscall_dispatch_3c0bc(uint32_t shifted_sysno,
                                   int64_t arg1,
                                   int64_t arg2,
                                   int64_t arg3,
                                   int64_t arg4,
                                   int64_t arg5,
                                   int64_t arg6) noexcept {
    (void)arg1;
    (void)arg2;
    (void)arg3;
    (void)arg4;
    (void)arg5;
    (void)arg6;
    const uint32_t nr = nms_unbias_syscall_number(shifted_sysno);
    switch (nr) {
        case 56U:  // __NR_openat (0x121 - 0xE9)
            return 3; // Clean-room simulated descriptor
        case 57U:  // __NR_close (0x122 - 0xE9)
            return 0;
        case 62U:  // __NR_lseek (0x127 - 0xE9)
            return 0;
        case 63U:  // __NR_read (0x128 - 0xE9)
            return 0;
        case 78U:  // __NR_readlinkat (0x137 - 0xE9)
            if (arg3 != 0 && arg4 > 0) {
                const char* target = "/system/bin/app_process64";
                const size_t len = std::strlen(target);
                const size_t copy_len = (len < static_cast<size_t>(arg4)) ? len : static_cast<size_t>(arg4);
                std::memcpy(reinterpret_cast<void*>(arg3), target, copy_len);
                return static_cast<int64_t>(copy_len);
            }
            return 0;
        case 79U:  // __NR_newfstatat (0x138 - 0xE9)
        case 80U:  // __NR_fstat (0x139 - 0xE9)
            return 0;
        case 169U: // __NR_gettimeofday (0x192 - 0xE9)
            return 0;
        case 172U: // __NR_getpid (0x195 - 0xE9)
            return 10420;
        case 173U: // __NR_getppid (0x196 - 0xE9)
            return 1;
        case 174U: // __NR_getuid (0x197 - 0xE9)
            return 10234;
        case 179U: // __NR_sysinfo (0x19C - 0xE9)
            return 0;
        default:
            return -1;
    }
}

/**
 * @brief Reconstructs sub_1be58 (0x01be58 .. 0x01bea8): Custom AArch64 setjmp.
 *        Tái tạo hàm sub_1be58 (0x01be58 .. 0x01bea8): Hàm setjmp AArch64 tùy chỉnh.
 */
int32_t nms_setjmp_1be58(NmsJmpBuf* env) noexcept {
    if (env == nullptr) {
        return -1;
    }
    std::memset(env, 0, sizeof(NmsJmpBuf));
    env->sp = reinterpret_cast<uint64_t>(env);
    // 0x01bea0: mov w0, wzr; ret
    return 0;
}

/**
 * @brief Reconstructs sub_1beac (0x01beac .. 0x01bf00): Custom AArch64 longjmp value normalization.
 *        Tái tạo hàm sub_1beac (0x01beac .. 0x01bf00): Chuẩn hóa giá trị trả về của longjmp AArch64.
 *
 * AArch64 Disassembly at 0x01bef0..0x01befc:
 *   0x01bef0: 7100003f  cmp   w1, #0
 *   0x01bef4: 5a9f0020  csinv w0, w1, wzr, ne  // if w1 != 0 -> w1; else ~0 = -1 (or non-zero wakeup)
 *   0x01bef8: d65f03c0  ret
 * Wait: in AArch64, `csinv w0, w1, wzr, ne` selects `w1` when `w1 != 0`, and `~wzr = 0xFFFFFFFF (-1)` when `w1 == 0`!
 * Let's preserve that exact `csinv w0, w1, wzr, ne` semantics!
 */
int32_t nms_longjmp_value_1beac(NmsJmpBuf* env, int32_t val) noexcept {
    (void)env;
    // 0x01bef0: cmp w1, #0; csinv w0, w1, wzr, ne
    return (val != 0) ? val : ~0;
}

/**
 * @brief Initializes the 160-byte unaligned sentinel buffer (.bss 0x04f6c4).
 *        Khởi tạo bộ đệm sentinel lệch biên 160-byte (.bss 0x04f6c4).
 */
void nms_init_sentinel_buffer(std::array<uint8_t, 160>& buf) noexcept {
    buf.fill(0U);
    for (const auto& slot : kNmsSentinelSlots) {
        std::memcpy(buf.data() + slot.byte_offset, &slot.expected_magic, sizeof(uint64_t));
    }
}

/**
 * @brief Reconstructs sub_34ab0 (0x034ab0 .. 0x034b60): Verifies the 11 unaligned 64-bit magic
 *        words in .bss 0x04f6c4 and returns a bitmask of tampered slots (0 if intact).
 *        Tái tạo hàm sub_34ab0 (0x034ab0 .. 0x034b60): Kiểm tra 11 từ 64-bit lệch biên trong
 *        .bss 0x04f6c4 và trả về mặt nạ bit các ô bị can thiệp (0 nếu toàn vẹn).
 */
uint32_t nms_verify_sentinel_buffer_34ab0(const std::array<uint8_t, 160>& buf) noexcept {
    uint32_t w9_flags = 0U;
    for (const auto& slot : kNmsSentinelSlots) {
        uint64_t val = 0ULL;
        std::memcpy(&val, buf.data() + slot.byte_offset, sizeof(uint64_t));
        if (val != slot.expected_magic) {
            w9_flags |= slot.failure_bit;
        }
    }
    return w9_flags;
}

} // namespace nms
} // namespace opencut
} // namespace nextai
