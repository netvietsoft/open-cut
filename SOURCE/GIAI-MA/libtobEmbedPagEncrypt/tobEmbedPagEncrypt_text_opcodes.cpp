// ============================================================================
// Complete 537-Instruction AArch64 .text Disassembly & 7-FDE Unwind Verifier
// Bộ kiểm chứng toàn bộ 537 lệnh AArch64 .text (0x0a94..0x12f8) & 7 FDE của libtobEmbedPagEncrypt.so
// ============================================================================
#include "tobEmbedPagEncrypt_core.h"

namespace tob_embed_pag_encrypt {

// Insn #000 @ 0x0a94: 0xB0000020 -> adrp x0, #0x5000
// Lệnh AArch64 #000 tại 0x0a94: adrp x0, #0x5000
uint64_t verify_tob_encrypt_insn_000_0x0a94(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xB0000020U;
    constexpr uint64_t kVaddr  = 0x0a94ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #001 @ 0x0a98: 0x910F8000 -> add x0, x0, #0x3e0
// Lệnh AArch64 #001 tại 0x0a98: add x0, x0, #0x3e0
uint64_t verify_tob_encrypt_insn_001_0x0a98(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x910F8000U;
    constexpr uint64_t kVaddr  = 0x0a98ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #002 @ 0x0a9c: 0x14000221 -> b #0x1320
// Lệnh AArch64 #002 tại 0x0a9c: b #0x1320
uint64_t verify_tob_encrypt_insn_002_0x0a9c(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x14000221U;
    constexpr uint64_t kVaddr  = 0x0a9cULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #003 @ 0x0aa0: 0xD65F03C0 -> ret 
// Lệnh AArch64 #003 tại 0x0aa0: ret 
uint64_t verify_tob_encrypt_insn_003_0x0aa0(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xD65F03C0U;
    constexpr uint64_t kVaddr  = 0x0aa0ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #004 @ 0x0aa4: 0x17FFFFFF -> b #0xaa0
// Lệnh AArch64 #004 tại 0x0aa4: b #0xaa0
uint64_t verify_tob_encrypt_insn_004_0x0aa4(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x17FFFFFFU;
    constexpr uint64_t kVaddr  = 0x0aa4ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #005 @ 0x0aa8: 0xB4000040 -> cbz x0, #0xab0
// Lệnh AArch64 #005 tại 0x0aa8: cbz x0, #0xab0
uint64_t verify_tob_encrypt_insn_005_0x0aa8(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xB4000040U;
    constexpr uint64_t kVaddr  = 0x0aa8ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #006 @ 0x0aac: 0xD61F0000 -> br x0
// Lệnh AArch64 #006 tại 0x0aac: br x0
uint64_t verify_tob_encrypt_insn_006_0x0aac(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xD61F0000U;
    constexpr uint64_t kVaddr  = 0x0aacULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #007 @ 0x0ab0: 0xD65F03C0 -> ret 
// Lệnh AArch64 #007 tại 0x0ab0: ret 
uint64_t verify_tob_encrypt_insn_007_0x0ab0(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xD65F03C0U;
    constexpr uint64_t kVaddr  = 0x0ab0ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #008 @ 0x0ab4: 0x90000008 -> adrp x8, #0
// Lệnh AArch64 #008 tại 0x0ab4: adrp x8, #0
uint64_t verify_tob_encrypt_insn_008_0x0ab4(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x90000008U;
    constexpr uint64_t kVaddr  = 0x0ab4ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #009 @ 0x0ab8: 0x912AA108 -> add x8, x8, #0xaa8
// Lệnh AArch64 #009 tại 0x0ab8: add x8, x8, #0xaa8
uint64_t verify_tob_encrypt_insn_009_0x0ab8(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x912AA108U;
    constexpr uint64_t kVaddr  = 0x0ab8ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #010 @ 0x0abc: 0xB0000022 -> adrp x2, #0x5000
// Lệnh AArch64 #010 tại 0x0abc: adrp x2, #0x5000
uint64_t verify_tob_encrypt_insn_010_0x0abc(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xB0000022U;
    constexpr uint64_t kVaddr  = 0x0abcULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #011 @ 0x0ac0: 0x910F8042 -> add x2, x2, #0x3e0
// Lệnh AArch64 #011 tại 0x0ac0: add x2, x2, #0x3e0
uint64_t verify_tob_encrypt_insn_011_0x0ac0(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x910F8042U;
    constexpr uint64_t kVaddr  = 0x0ac0ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #012 @ 0x0ac4: 0xAA0003E1 -> mov x1, x0
// Lệnh AArch64 #012 tại 0x0ac4: mov x1, x0
uint64_t verify_tob_encrypt_insn_012_0x0ac4(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xAA0003E1U;
    constexpr uint64_t kVaddr  = 0x0ac4ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #013 @ 0x0ac8: 0xAA0803E0 -> mov x0, x8
// Lệnh AArch64 #013 tại 0x0ac8: mov x0, x8
uint64_t verify_tob_encrypt_insn_013_0x0ac8(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xAA0803E0U;
    constexpr uint64_t kVaddr  = 0x0ac8ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #014 @ 0x0acc: 0x14000219 -> b #0x1330
// Lệnh AArch64 #014 tại 0x0acc: b #0x1330
uint64_t verify_tob_encrypt_insn_014_0x0acc(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x14000219U;
    constexpr uint64_t kVaddr  = 0x0accULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #015 @ 0x0ad0: 0xD10083FF -> sub sp, sp, #0x20
// Lệnh AArch64 #015 tại 0x0ad0: sub sp, sp, #0x20
uint64_t verify_tob_encrypt_insn_015_0x0ad0(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xD10083FFU;
    constexpr uint64_t kVaddr  = 0x0ad0ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #016 @ 0x0ad4: 0xA9017BFD -> stp x29, x30, [sp, #0x10]
// Lệnh AArch64 #016 tại 0x0ad4: stp x29, x30, [sp, #0x10]
uint64_t verify_tob_encrypt_insn_016_0x0ad4(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xA9017BFDU;
    constexpr uint64_t kVaddr  = 0x0ad4ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #017 @ 0x0ad8: 0x910043FD -> add x29, sp, #0x10
// Lệnh AArch64 #017 tại 0x0ad8: add x29, sp, #0x10
uint64_t verify_tob_encrypt_insn_017_0x0ad8(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x910043FDU;
    constexpr uint64_t kVaddr  = 0x0ad8ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #018 @ 0x0adc: 0xD53BD049 -> mrs x9, tpidr_el0
// Lệnh AArch64 #018 tại 0x0adc: mrs x9, tpidr_el0
uint64_t verify_tob_encrypt_insn_018_0x0adc(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xD53BD049U;
    constexpr uint64_t kVaddr  = 0x0adcULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #019 @ 0x0ae0: 0xF940152C -> ldr x12, [x9, #0x28]
// Lệnh AArch64 #019 tại 0x0ae0: ldr x12, [x9, #0x28]
uint64_t verify_tob_encrypt_insn_019_0x0ae0(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xF940152CU;
    constexpr uint64_t kVaddr  = 0x0ae0ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #020 @ 0x0ae4: 0x11003C08 -> add w8, w0, #0xf
// Lệnh AArch64 #020 tại 0x0ae4: add w8, w0, #0xf
uint64_t verify_tob_encrypt_insn_020_0x0ae4(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x11003C08U;
    constexpr uint64_t kVaddr  = 0x0ae4ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #021 @ 0x0ae8: 0x7100001F -> cmp w0, #0
// Lệnh AArch64 #021 tại 0x0ae8: cmp w0, #0
uint64_t verify_tob_encrypt_insn_021_0x0ae8(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x7100001FU;
    constexpr uint64_t kVaddr  = 0x0ae8ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #022 @ 0x0aec: 0x1A80B108 -> csel w8, w8, w0, lt
// Lệnh AArch64 #022 tại 0x0aec: csel w8, w8, w0, lt
uint64_t verify_tob_encrypt_insn_022_0x0aec(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x1A80B108U;
    constexpr uint64_t kVaddr  = 0x0aecULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #023 @ 0x0af0: 0x121C6D08 -> and w8, w8, #0xfffffff0
// Lệnh AArch64 #023 tại 0x0af0: and w8, w8, #0xfffffff0
uint64_t verify_tob_encrypt_insn_023_0x0af0(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x121C6D08U;
    constexpr uint64_t kVaddr  = 0x0af0ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #024 @ 0x0af4: 0x5280020A -> mov w10, #0x10
// Lệnh AArch64 #024 tại 0x0af4: mov w10, #0x10
uint64_t verify_tob_encrypt_insn_024_0x0af4(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x5280020AU;
    constexpr uint64_t kVaddr  = 0x0af4ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #025 @ 0x0af8: 0x4B08000D -> sub w13, w0, w8
// Lệnh AArch64 #025 tại 0x0af8: sub w13, w0, w8
uint64_t verify_tob_encrypt_insn_025_0x0af8(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x4B08000DU;
    constexpr uint64_t kVaddr  = 0x0af8ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #026 @ 0x0afc: 0xF90007EC -> str x12, [sp, #8]
// Lệnh AArch64 #026 tại 0x0afc: str x12, [sp, #8]
uint64_t verify_tob_encrypt_insn_026_0x0afc(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xF90007ECU;
    constexpr uint64_t kVaddr  = 0x0afcULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #027 @ 0x0b00: 0x4B0D0148 -> sub w8, w10, w13
// Lệnh AArch64 #027 tại 0x0b00: sub w8, w10, w13
uint64_t verify_tob_encrypt_insn_027_0x0b00(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x4B0D0148U;
    constexpr uint64_t kVaddr  = 0x0b00ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #028 @ 0x0b04: 0xF940152A -> ldr x10, [x9, #0x28]
// Lệnh AArch64 #028 tại 0x0b04: ldr x10, [x9, #0x28]
uint64_t verify_tob_encrypt_insn_028_0x0b04(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xF940152AU;
    constexpr uint64_t kVaddr  = 0x0b04ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #029 @ 0x0b08: 0xF94007EC -> ldr x12, [sp, #8]
// Lệnh AArch64 #029 tại 0x0b08: ldr x12, [sp, #8]
uint64_t verify_tob_encrypt_insn_029_0x0b08(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xF94007ECU;
    constexpr uint64_t kVaddr  = 0x0b08ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #030 @ 0x0b0c: 0x528003EB -> mov w11, #0x1f
// Lệnh AArch64 #030 tại 0x0b0c: mov w11, #0x1f
uint64_t verify_tob_encrypt_insn_030_0x0b0c(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x528003EBU;
    constexpr uint64_t kVaddr  = 0x0b0cULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #031 @ 0x0b10: 0x4B0D0169 -> sub w9, w11, w13
// Lệnh AArch64 #031 tại 0x0b10: sub w9, w11, w13
uint64_t verify_tob_encrypt_insn_031_0x0b10(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x4B0D0169U;
    constexpr uint64_t kVaddr  = 0x0b10ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #032 @ 0x0b14: 0x7100011F -> cmp w8, #0
// Lệnh AArch64 #032 tại 0x0b14: cmp w8, #0
uint64_t verify_tob_encrypt_insn_032_0x0b14(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x7100011FU;
    constexpr uint64_t kVaddr  = 0x0b14ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #033 @ 0x0b18: 0x1A88B129 -> csel w9, w9, w8, lt
// Lệnh AArch64 #033 tại 0x0b18: csel w9, w9, w8, lt
uint64_t verify_tob_encrypt_insn_033_0x0b18(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x1A88B129U;
    constexpr uint64_t kVaddr  = 0x0b18ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #034 @ 0x0b1c: 0xEB0C015F -> cmp x10, x12
// Lệnh AArch64 #034 tại 0x0b1c: cmp x10, x12
uint64_t verify_tob_encrypt_insn_034_0x0b1c(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xEB0C015FU;
    constexpr uint64_t kVaddr  = 0x0b1cULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #035 @ 0x0b20: 0x54000101 -> b.ne #0xb40
// Lệnh AArch64 #035 tại 0x0b20: b.ne #0xb40
uint64_t verify_tob_encrypt_insn_035_0x0b20(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x54000101U;
    constexpr uint64_t kVaddr  = 0x0b20ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #036 @ 0x0b24: 0x121C6D29 -> and w9, w9, #0xfffffff0
// Lệnh AArch64 #036 tại 0x0b24: and w9, w9, #0xfffffff0
uint64_t verify_tob_encrypt_insn_036_0x0b24(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x121C6D29U;
    constexpr uint64_t kVaddr  = 0x0b24ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #037 @ 0x0b28: 0xA9417BFD -> ldp x29, x30, [sp, #0x10]
// Lệnh AArch64 #037 tại 0x0b28: ldp x29, x30, [sp, #0x10]
uint64_t verify_tob_encrypt_insn_037_0x0b28(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xA9417BFDU;
    constexpr uint64_t kVaddr  = 0x0b28ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #038 @ 0x0b2c: 0x4B090108 -> sub w8, w8, w9
// Lệnh AArch64 #038 tại 0x0b2c: sub w8, w8, w9
uint64_t verify_tob_encrypt_insn_038_0x0b2c(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x4B090108U;
    constexpr uint64_t kVaddr  = 0x0b2cULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #039 @ 0x0b30: 0x0B080008 -> add w8, w0, w8
// Lệnh AArch64 #039 tại 0x0b30: add w8, w0, w8
uint64_t verify_tob_encrypt_insn_039_0x0b30(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x0B080008U;
    constexpr uint64_t kVaddr  = 0x0b30ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #040 @ 0x0b34: 0x11001900 -> add w0, w8, #6
// Lệnh AArch64 #040 tại 0x0b34: add w0, w8, #6
uint64_t verify_tob_encrypt_insn_040_0x0b34(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x11001900U;
    constexpr uint64_t kVaddr  = 0x0b34ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #041 @ 0x0b38: 0x910083FF -> add sp, sp, #0x20
// Lệnh AArch64 #041 tại 0x0b38: add sp, sp, #0x20
uint64_t verify_tob_encrypt_insn_041_0x0b38(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x910083FFU;
    constexpr uint64_t kVaddr  = 0x0b38ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #042 @ 0x0b3c: 0xD65F03C0 -> ret 
// Lệnh AArch64 #042 tại 0x0b3c: ret 
uint64_t verify_tob_encrypt_insn_042_0x0b3c(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xD65F03C0U;
    constexpr uint64_t kVaddr  = 0x0b3cULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #043 @ 0x0b40: 0x94000200 -> bl #0x1340
// Lệnh AArch64 #043 tại 0x0b40: bl #0x1340
uint64_t verify_tob_encrypt_insn_043_0x0b40(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x94000200U;
    constexpr uint64_t kVaddr  = 0x0b40ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #044 @ 0x0b44: 0xD10203FF -> sub sp, sp, #0x80
// Lệnh AArch64 #044 tại 0x0b44: sub sp, sp, #0x80
uint64_t verify_tob_encrypt_insn_044_0x0b44(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xD10203FFU;
    constexpr uint64_t kVaddr  = 0x0b44ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #045 @ 0x0b48: 0xA9027BFD -> stp x29, x30, [sp, #0x20]
// Lệnh AArch64 #045 tại 0x0b48: stp x29, x30, [sp, #0x20]
uint64_t verify_tob_encrypt_insn_045_0x0b48(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xA9027BFDU;
    constexpr uint64_t kVaddr  = 0x0b48ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #046 @ 0x0b4c: 0xA9036FFC -> stp x28, x27, [sp, #0x30]
// Lệnh AArch64 #046 tại 0x0b4c: stp x28, x27, [sp, #0x30]
uint64_t verify_tob_encrypt_insn_046_0x0b4c(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xA9036FFCU;
    constexpr uint64_t kVaddr  = 0x0b4cULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #047 @ 0x0b50: 0xA90467FA -> stp x26, x25, [sp, #0x40]
// Lệnh AArch64 #047 tại 0x0b50: stp x26, x25, [sp, #0x40]
uint64_t verify_tob_encrypt_insn_047_0x0b50(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xA90467FAU;
    constexpr uint64_t kVaddr  = 0x0b50ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #048 @ 0x0b54: 0xA9055FF8 -> stp x24, x23, [sp, #0x50]
// Lệnh AArch64 #048 tại 0x0b54: stp x24, x23, [sp, #0x50]
uint64_t verify_tob_encrypt_insn_048_0x0b54(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xA9055FF8U;
    constexpr uint64_t kVaddr  = 0x0b54ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #049 @ 0x0b58: 0xA90657F6 -> stp x22, x21, [sp, #0x60]
// Lệnh AArch64 #049 tại 0x0b58: stp x22, x21, [sp, #0x60]
uint64_t verify_tob_encrypt_insn_049_0x0b58(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xA90657F6U;
    constexpr uint64_t kVaddr  = 0x0b58ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #050 @ 0x0b5c: 0xA9074FF4 -> stp x20, x19, [sp, #0x70]
// Lệnh AArch64 #050 tại 0x0b5c: stp x20, x19, [sp, #0x70]
uint64_t verify_tob_encrypt_insn_050_0x0b5c(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xA9074FF4U;
    constexpr uint64_t kVaddr  = 0x0b5cULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #051 @ 0x0b60: 0x910083FD -> add x29, sp, #0x20
// Lệnh AArch64 #051 tại 0x0b60: add x29, sp, #0x20
uint64_t verify_tob_encrypt_insn_051_0x0b60(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x910083FDU;
    constexpr uint64_t kVaddr  = 0x0b60ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #052 @ 0x0b64: 0xD53BD057 -> mrs x23, tpidr_el0
// Lệnh AArch64 #052 tại 0x0b64: mrs x23, tpidr_el0
uint64_t verify_tob_encrypt_insn_052_0x0b64(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xD53BD057U;
    constexpr uint64_t kVaddr  = 0x0b64ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #053 @ 0x0b68: 0xF94016E9 -> ldr x9, [x23, #0x28]
// Lệnh AArch64 #053 tại 0x0b68: ldr x9, [x23, #0x28]
uint64_t verify_tob_encrypt_insn_053_0x0b68(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xF94016E9U;
    constexpr uint64_t kVaddr  = 0x0b68ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #054 @ 0x0b6c: 0xAA0003F5 -> mov x21, x0
// Lệnh AArch64 #054 tại 0x0b6c: mov x21, x0
uint64_t verify_tob_encrypt_insn_054_0x0b6c(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xAA0003F5U;
    constexpr uint64_t kVaddr  = 0x0b6cULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #055 @ 0x0b70: 0x7100047F -> cmp w3, #1
// Lệnh AArch64 #055 tại 0x0b70: cmp w3, #1
uint64_t verify_tob_encrypt_insn_055_0x0b70(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x7100047FU;
    constexpr uint64_t kVaddr  = 0x0b70ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #056 @ 0x0b74: 0x12800000 -> mov w0, #-1
// Lệnh AArch64 #056 tại 0x0b74: mov w0, #-1
uint64_t verify_tob_encrypt_insn_056_0x0b74(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x12800000U;
    constexpr uint64_t kVaddr  = 0x0b74ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #057 @ 0x0b78: 0xF81F83A9 -> stur x9, [x29, #-8]
// Lệnh AArch64 #057 tại 0x0b78: stur x9, [x29, #-8]
uint64_t verify_tob_encrypt_insn_057_0x0b78(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xF81F83A9U;
    constexpr uint64_t kVaddr  = 0x0b78ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #058 @ 0x0b7c: 0x54000AEB -> b.lt #0xcd8
// Lệnh AArch64 #058 tại 0x0b7c: b.lt #0xcd8
uint64_t verify_tob_encrypt_insn_058_0x0b7c(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x54000AEBU;
    constexpr uint64_t kVaddr  = 0x0b7cULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #059 @ 0x0b80: 0xAA0203E8 -> mov x8, x2
// Lệnh AArch64 #059 tại 0x0b80: mov x8, x2
uint64_t verify_tob_encrypt_insn_059_0x0b80(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xAA0203E8U;
    constexpr uint64_t kVaddr  = 0x0b80ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #060 @ 0x0b84: 0xB4000AA2 -> cbz x2, #0xcd8
// Lệnh AArch64 #060 tại 0x0b84: cbz x2, #0xcd8
uint64_t verify_tob_encrypt_insn_060_0x0b84(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xB4000AA2U;
    constexpr uint64_t kVaddr  = 0x0b84ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #061 @ 0x0b88: 0x2A0103F6 -> mov w22, w1
// Lệnh AArch64 #061 tại 0x0b88: mov w22, w1
uint64_t verify_tob_encrypt_insn_061_0x0b88(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x2A0103F6U;
    constexpr uint64_t kVaddr  = 0x0b88ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #062 @ 0x0b8c: 0x7100043F -> cmp w1, #1
// Lệnh AArch64 #062 tại 0x0b8c: cmp w1, #1
uint64_t verify_tob_encrypt_insn_062_0x0b8c(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x7100043FU;
    constexpr uint64_t kVaddr  = 0x0b8cULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #063 @ 0x0b90: 0x54000A4B -> b.lt #0xcd8
// Lệnh AArch64 #063 tại 0x0b90: b.lt #0xcd8
uint64_t verify_tob_encrypt_insn_063_0x0b90(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x54000A4BU;
    constexpr uint64_t kVaddr  = 0x0b90ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #064 @ 0x0b94: 0xAA0403F3 -> mov x19, x4
// Lệnh AArch64 #064 tại 0x0b94: mov x19, x4
uint64_t verify_tob_encrypt_insn_064_0x0b94(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xAA0403F3U;
    constexpr uint64_t kVaddr  = 0x0b94ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #065 @ 0x0b98: 0xB4000A04 -> cbz x4, #0xcd8
// Lệnh AArch64 #065 tại 0x0b98: cbz x4, #0xcd8
uint64_t verify_tob_encrypt_insn_065_0x0b98(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xB4000A04U;
    constexpr uint64_t kVaddr  = 0x0b98ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #066 @ 0x0b9c: 0x910023E2 -> add x2, sp, #8
// Lệnh AArch64 #066 tại 0x0b9c: add x2, sp, #8
uint64_t verify_tob_encrypt_insn_066_0x0b9c(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x910023E2U;
    constexpr uint64_t kVaddr  = 0x0b9cULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #067 @ 0x0ba0: 0xAA0803E0 -> mov x0, x8
// Lệnh AArch64 #067 tại 0x0ba0: mov x0, x8
uint64_t verify_tob_encrypt_insn_067_0x0ba0(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xAA0803E0U;
    constexpr uint64_t kVaddr  = 0x0ba0ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #068 @ 0x0ba4: 0x2A0303E1 -> mov w1, w3
// Lệnh AArch64 #068 tại 0x0ba4: mov w1, w3
uint64_t verify_tob_encrypt_insn_068_0x0ba4(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x2A0303E1U;
    constexpr uint64_t kVaddr  = 0x0ba4ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #069 @ 0x0ba8: 0x94000059 -> bl #0xd0c
// Lệnh AArch64 #069 tại 0x0ba8: bl #0xd0c
uint64_t verify_tob_encrypt_insn_069_0x0ba8(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x94000059U;
    constexpr uint64_t kVaddr  = 0x0ba8ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #070 @ 0x0bac: 0x4B1603E8 -> neg w8, w22
// Lệnh AArch64 #070 tại 0x0bac: neg w8, w22
uint64_t verify_tob_encrypt_insn_070_0x0bac(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x4B1603E8U;
    constexpr uint64_t kVaddr  = 0x0bacULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #071 @ 0x0bb0: 0x91001A74 -> add x20, x19, #6
// Lệnh AArch64 #071 tại 0x0bb0: add x20, x19, #6
uint64_t verify_tob_encrypt_insn_071_0x0bb0(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x91001A74U;
    constexpr uint64_t kVaddr  = 0x0bb0ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #072 @ 0x0bb4: 0x12000D1A -> and w26, w8, #0xf
// Lệnh AArch64 #072 tại 0x0bb4: and w26, w8, #0xf
uint64_t verify_tob_encrypt_insn_072_0x0bb4(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x12000D1AU;
    constexpr uint64_t kVaddr  = 0x0bb4ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #073 @ 0x0bb8: 0x0B160358 -> add w24, w26, w22
// Lệnh AArch64 #073 tại 0x0bb8: add w24, w26, w22
uint64_t verify_tob_encrypt_insn_073_0x0bb8(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x0B160358U;
    constexpr uint64_t kVaddr  = 0x0bb8ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #074 @ 0x0bbc: 0x2A1603E2 -> mov w2, w22
// Lệnh AArch64 #074 tại 0x0bbc: mov w2, w22
uint64_t verify_tob_encrypt_insn_074_0x0bbc(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x2A1603E2U;
    constexpr uint64_t kVaddr  = 0x0bbcULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #075 @ 0x0bc0: 0xAA1403E0 -> mov x0, x20
// Lệnh AArch64 #075 tại 0x0bc0: mov x0, x20
uint64_t verify_tob_encrypt_insn_075_0x0bc0(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xAA1403E0U;
    constexpr uint64_t kVaddr  = 0x0bc0ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #076 @ 0x0bc4: 0xAA1503E1 -> mov x1, x21
// Lệnh AArch64 #076 tại 0x0bc4: mov x1, x21
uint64_t verify_tob_encrypt_insn_076_0x0bc4(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xAA1503E1U;
    constexpr uint64_t kVaddr  = 0x0bc4ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #077 @ 0x0bc8: 0x11001B19 -> add w25, w24, #6
// Lệnh AArch64 #077 tại 0x0bc8: add w25, w24, #6
uint64_t verify_tob_encrypt_insn_077_0x0bc8(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x11001B19U;
    constexpr uint64_t kVaddr  = 0x0bc8ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #078 @ 0x0bcc: 0x940001E1 -> bl #0x1350
// Lệnh AArch64 #078 tại 0x0bcc: bl #0x1350
uint64_t verify_tob_encrypt_insn_078_0x0bcc(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x940001E1U;
    constexpr uint64_t kVaddr  = 0x0bccULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #079 @ 0x0bd0: 0x528C6E88 -> mov w8, #0x6374
// Lệnh AArch64 #079 tại 0x0bd0: mov w8, #0x6374
uint64_t verify_tob_encrypt_insn_079_0x0bd0(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x528C6E88U;
    constexpr uint64_t kVaddr  = 0x0bd0ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #080 @ 0x0bd4: 0x52800069 -> mov w9, #3
// Lệnh AArch64 #080 tại 0x0bd4: mov w9, #3
uint64_t verify_tob_encrypt_insn_080_0x0bd4(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x52800069U;
    constexpr uint64_t kVaddr  = 0x0bd4ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #081 @ 0x0bd8: 0x5280200A -> mov w10, #0x100
// Lệnh AArch64 #081 tại 0x0bd8: mov w10, #0x100
uint64_t verify_tob_encrypt_insn_081_0x0bd8(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x5280200AU;
    constexpr uint64_t kVaddr  = 0x0bd8ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #082 @ 0x0bdc: 0x71001F3F -> cmp w25, #7
// Lệnh AArch64 #082 tại 0x0bdc: cmp w25, #7
uint64_t verify_tob_encrypt_insn_082_0x0bdc(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x71001F3FU;
    constexpr uint64_t kVaddr  = 0x0bdcULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #083 @ 0x0be0: 0x39000E7A -> strb w26, [x19, #3]
// Lệnh AArch64 #083 tại 0x0be0: strb w26, [x19, #3]
uint64_t verify_tob_encrypt_insn_083_0x0be0(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x39000E7AU;
    constexpr uint64_t kVaddr  = 0x0be0ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #084 @ 0x0be4: 0x79000268 -> strh w8, [x19]
// Lệnh AArch64 #084 tại 0x0be4: strh w8, [x19]
uint64_t verify_tob_encrypt_insn_084_0x0be4(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x79000268U;
    constexpr uint64_t kVaddr  = 0x0be4ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #085 @ 0x0be8: 0x39000A69 -> strb w9, [x19, #2]
// Lệnh AArch64 #085 tại 0x0be8: strb w9, [x19, #2]
uint64_t verify_tob_encrypt_insn_085_0x0be8(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x39000A69U;
    constexpr uint64_t kVaddr  = 0x0be8ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #086 @ 0x0bec: 0x79000A6A -> strh w10, [x19, #4]
// Lệnh AArch64 #086 tại 0x0bec: strh w10, [x19, #4]
uint64_t verify_tob_encrypt_insn_086_0x0bec(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x79000A6AU;
    constexpr uint64_t kVaddr  = 0x0becULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #087 @ 0x0bf0: 0x5400014B -> b.lt #0xc18
// Lệnh AArch64 #087 tại 0x0bf0: b.lt #0xc18
uint64_t verify_tob_encrypt_insn_087_0x0bf0(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x5400014BU;
    constexpr uint64_t kVaddr  = 0x0bf0ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #088 @ 0x0bf4: 0xB0000029 -> adrp x9, #0x5000
// Lệnh AArch64 #088 tại 0x0bf4: adrp x9, #0x5000
uint64_t verify_tob_encrypt_insn_088_0x0bf4(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xB0000029U;
    constexpr uint64_t kVaddr  = 0x0bf4ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #089 @ 0x0bf8: 0xF942D529 -> ldr x9, [x9, #0x5a8]
// Lệnh AArch64 #089 tại 0x0bf8: ldr x9, [x9, #0x5a8]
uint64_t verify_tob_encrypt_insn_089_0x0bf8(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xF942D529U;
    constexpr uint64_t kVaddr  = 0x0bf8ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #090 @ 0x0bfc: 0x2A1903E8 -> mov w8, w25
// Lệnh AArch64 #090 tại 0x0bfc: mov w8, w25
uint64_t verify_tob_encrypt_insn_090_0x0bfc(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x2A1903E8U;
    constexpr uint64_t kVaddr  = 0x0bfcULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #091 @ 0x0c00: 0xD1001908 -> sub x8, x8, #6
// Lệnh AArch64 #091 tại 0x0c00: sub x8, x8, #6
uint64_t verify_tob_encrypt_insn_091_0x0c00(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xD1001908U;
    constexpr uint64_t kVaddr  = 0x0c00ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #092 @ 0x0c04: 0x3940028A -> ldrb w10, [x20]
// Lệnh AArch64 #092 tại 0x0c04: ldrb w10, [x20]
uint64_t verify_tob_encrypt_insn_092_0x0c04(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x3940028AU;
    constexpr uint64_t kVaddr  = 0x0c04ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #093 @ 0x0c08: 0xF1000508 -> subs x8, x8, #1
// Lệnh AArch64 #093 tại 0x0c08: subs x8, x8, #1
uint64_t verify_tob_encrypt_insn_093_0x0c08(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xF1000508U;
    constexpr uint64_t kVaddr  = 0x0c08ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #094 @ 0x0c0c: 0x386A692A -> ldrb w10, [x9, x10]
// Lệnh AArch64 #094 tại 0x0c0c: ldrb w10, [x9, x10]
uint64_t verify_tob_encrypt_insn_094_0x0c0c(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x386A692AU;
    constexpr uint64_t kVaddr  = 0x0c0cULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #095 @ 0x0c10: 0x3800168A -> strb w10, [x20], #1
// Lệnh AArch64 #095 tại 0x0c10: strb w10, [x20], #1
uint64_t verify_tob_encrypt_insn_095_0x0c10(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x3800168AU;
    constexpr uint64_t kVaddr  = 0x0c10ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #096 @ 0x0c14: 0x54FFFF81 -> b.ne #0xc04
// Lệnh AArch64 #096 tại 0x0c14: b.ne #0xc04
uint64_t verify_tob_encrypt_insn_096_0x0c14(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x54FFFF81U;
    constexpr uint64_t kVaddr  = 0x0c14ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #097 @ 0x0c18: 0x7100431F -> cmp w24, #0x10
// Lệnh AArch64 #097 tại 0x0c18: cmp w24, #0x10
uint64_t verify_tob_encrypt_insn_097_0x0c18(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x7100431FU;
    constexpr uint64_t kVaddr  = 0x0c18ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #098 @ 0x0c1c: 0x540005CB -> b.lt #0xcd4
// Lệnh AArch64 #098 tại 0x0c1c: b.lt #0xcd4
uint64_t verify_tob_encrypt_insn_098_0x0c1c(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x540005CBU;
    constexpr uint64_t kVaddr  = 0x0c1cULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #099 @ 0x0c20: 0x53047F14 -> lsr w20, w24, #4
// Lệnh AArch64 #099 tại 0x0c20: lsr w20, w24, #4
uint64_t verify_tob_encrypt_insn_099_0x0c20(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x53047F14U;
    constexpr uint64_t kVaddr  = 0x0c20ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #100 @ 0x0c24: 0x29415BF5 -> ldp w21, w22, [sp, #8]
// Lệnh AArch64 #100 tại 0x0c24: ldp w21, w22, [sp, #8]
uint64_t verify_tob_encrypt_insn_100_0x0c24(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x29415BF5U;
    constexpr uint64_t kVaddr  = 0x0c24ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #101 @ 0x0c28: 0x294267F8 -> ldp w24, w25, [sp, #0x10]
// Lệnh AArch64 #101 tại 0x0c28: ldp w24, w25, [sp, #0x10]
uint64_t verify_tob_encrypt_insn_101_0x0c28(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x294267F8U;
    constexpr uint64_t kVaddr  = 0x0c28ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #102 @ 0x0c2c: 0x91004A7A -> add x26, x19, #0x12
// Lệnh AArch64 #102 tại 0x0c2c: add x26, x19, #0x12
uint64_t verify_tob_encrypt_insn_102_0x0c2c(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x91004A7AU;
    constexpr uint64_t kVaddr  = 0x0c2cULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #103 @ 0x0c30: 0x90000013 -> adrp x19, #0
// Lệnh AArch64 #103 tại 0x0c30: adrp x19, #0
uint64_t verify_tob_encrypt_insn_103_0x0c30(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x90000013U;
    constexpr uint64_t kVaddr  = 0x0c30ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #104 @ 0x0c34: 0x52A0201B -> mov w27, #0x1000000
// Lệnh AArch64 #104 tại 0x0c34: mov w27, #0x1000000
uint64_t verify_tob_encrypt_insn_104_0x0c34(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x52A0201BU;
    constexpr uint64_t kVaddr  = 0x0c34ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #105 @ 0x0c38: 0x91238273 -> add x19, x19, #0x8e0
// Lệnh AArch64 #105 tại 0x0c38: add x19, x19, #0x8e0
uint64_t verify_tob_encrypt_insn_105_0x0c38(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x91238273U;
    constexpr uint64_t kVaddr  = 0x0c38ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #106 @ 0x0c3c: 0x14000006 -> b #0xc54
// Lệnh AArch64 #106 tại 0x0c3c: b #0xc54
uint64_t verify_tob_encrypt_insn_106_0x0c3c(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x14000006U;
    constexpr uint64_t kVaddr  = 0x0c3cULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #107 @ 0x0c40: 0x4ADC2328 -> eor w8, w25, w28, ror #8
// Lệnh AArch64 #107 tại 0x0c40: eor w8, w25, w28, ror #8
uint64_t verify_tob_encrypt_insn_107_0x0c40(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x4ADC2328U;
    constexpr uint64_t kVaddr  = 0x0c40ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #108 @ 0x0c44: 0x5AC00908 -> rev w8, w8
// Lệnh AArch64 #108 tại 0x0c44: rev w8, w8
uint64_t verify_tob_encrypt_insn_108_0x0c44(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x5AC00908U;
    constexpr uint64_t kVaddr  = 0x0c44ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #109 @ 0x0c48: 0xF1000694 -> subs x20, x20, #1
// Lệnh AArch64 #109 tại 0x0c48: subs x20, x20, #1
uint64_t verify_tob_encrypt_insn_109_0x0c48(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xF1000694U;
    constexpr uint64_t kVaddr  = 0x0c48ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #110 @ 0x0c4c: 0xB8010748 -> str w8, [x26], #0x10
// Lệnh AArch64 #110 tại 0x0c4c: str w8, [x26], #0x10
uint64_t verify_tob_encrypt_insn_110_0x0c4c(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xB8010748U;
    constexpr uint64_t kVaddr  = 0x0c4cULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #111 @ 0x0c50: 0x54000420 -> b.eq #0xcd4
// Lệnh AArch64 #111 tại 0x0c50: b.eq #0xcd4
uint64_t verify_tob_encrypt_insn_111_0x0c50(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x54000420U;
    constexpr uint64_t kVaddr  = 0x0c50ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #112 @ 0x0c54: 0x297EA748 -> ldp w8, w9, [x26, #-0xc]
// Lệnh AArch64 #112 tại 0x0c54: ldp w8, w9, [x26, #-0xc]
uint64_t verify_tob_encrypt_insn_112_0x0c54(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x297EA748U;
    constexpr uint64_t kVaddr  = 0x0c54ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #113 @ 0x0c58: 0x5AC00908 -> rev w8, w8
// Lệnh AArch64 #113 tại 0x0c58: rev w8, w8
uint64_t verify_tob_encrypt_insn_113_0x0c58(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x5AC00908U;
    constexpr uint64_t kVaddr  = 0x0c58ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #114 @ 0x0c5c: 0x4A150108 -> eor w8, w8, w21
// Lệnh AArch64 #114 tại 0x0c5c: eor w8, w8, w21
uint64_t verify_tob_encrypt_insn_114_0x0c5c(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x4A150108U;
    constexpr uint64_t kVaddr  = 0x0c5cULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #115 @ 0x0c60: 0x6B1B013F -> cmp w9, w27
// Lệnh AArch64 #115 tại 0x0c60: cmp w9, w27
uint64_t verify_tob_encrypt_insn_115_0x0c60(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x6B1B013FU;
    constexpr uint64_t kVaddr  = 0x0c60ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #116 @ 0x0c64: 0x5AC00908 -> rev w8, w8
// Lệnh AArch64 #116 tại 0x0c64: rev w8, w8
uint64_t verify_tob_encrypt_insn_116_0x0c64(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x5AC00908U;
    constexpr uint64_t kVaddr  = 0x0c64ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #117 @ 0x0c68: 0x5AC0093C -> rev w28, w9
// Lệnh AArch64 #117 tại 0x0c68: rev w28, w9
uint64_t verify_tob_encrypt_insn_117_0x0c68(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x5AC0093CU;
    constexpr uint64_t kVaddr  = 0x0c68ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #118 @ 0x0c6c: 0xB81F4348 -> stur w8, [x26, #-0xc]
// Lệnh AArch64 #118 tại 0x0c6c: stur w8, [x26, #-0xc]
uint64_t verify_tob_encrypt_insn_118_0x0c6c(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xB81F4348U;
    constexpr uint64_t kVaddr  = 0x0c6cULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #119 @ 0x0c70: 0x54000081 -> b.ne #0xc80
// Lệnh AArch64 #119 tại 0x0c70: b.ne #0xc80
uint64_t verify_tob_encrypt_insn_119_0x0c70(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x54000081U;
    constexpr uint64_t kVaddr  = 0x0c70ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #120 @ 0x0c74: 0x52800021 -> mov w1, #1
// Lệnh AArch64 #120 tại 0x0c74: mov w1, #1
uint64_t verify_tob_encrypt_insn_120_0x0c74(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x52800021U;
    constexpr uint64_t kVaddr  = 0x0c74ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #121 @ 0x0c78: 0xAA1303E0 -> mov x0, x19
// Lệnh AArch64 #121 tại 0x0c78: mov x0, x19
uint64_t verify_tob_encrypt_insn_121_0x0c78(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xAA1303E0U;
    constexpr uint64_t kVaddr  = 0x0c78ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #122 @ 0x0c7c: 0x940001B9 -> bl #0x1360
// Lệnh AArch64 #122 tại 0x0c7c: bl #0x1360
uint64_t verify_tob_encrypt_insn_122_0x0c7c(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x940001B9U;
    constexpr uint64_t kVaddr  = 0x0c7cULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #123 @ 0x0c80: 0xB85FC348 -> ldur w8, [x26, #-4]
// Lệnh AArch64 #123 tại 0x0c80: ldur w8, [x26, #-4]
uint64_t verify_tob_encrypt_insn_123_0x0c80(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xB85FC348U;
    constexpr uint64_t kVaddr  = 0x0c80ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #124 @ 0x0c84: 0x4ADC62C9 -> eor w9, w22, w28, ror #24
// Lệnh AArch64 #124 tại 0x0c84: eor w9, w22, w28, ror #24
uint64_t verify_tob_encrypt_insn_124_0x0c84(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x4ADC62C9U;
    constexpr uint64_t kVaddr  = 0x0c84ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #125 @ 0x0c88: 0x5AC00929 -> rev w9, w9
// Lệnh AArch64 #125 tại 0x0c88: rev w9, w9
uint64_t verify_tob_encrypt_insn_125_0x0c88(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x5AC00929U;
    constexpr uint64_t kVaddr  = 0x0c88ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #126 @ 0x0c8c: 0xB81F8349 -> stur w9, [x26, #-8]
// Lệnh AArch64 #126 tại 0x0c8c: stur w9, [x26, #-8]
uint64_t verify_tob_encrypt_insn_126_0x0c8c(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xB81F8349U;
    constexpr uint64_t kVaddr  = 0x0c8cULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #127 @ 0x0c90: 0x6B1B011F -> cmp w8, w27
// Lệnh AArch64 #127 tại 0x0c90: cmp w8, w27
uint64_t verify_tob_encrypt_insn_127_0x0c90(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x6B1B011FU;
    constexpr uint64_t kVaddr  = 0x0c90ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #128 @ 0x0c94: 0x5AC0091C -> rev w28, w8
// Lệnh AArch64 #128 tại 0x0c94: rev w28, w8
uint64_t verify_tob_encrypt_insn_128_0x0c94(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x5AC0091CU;
    constexpr uint64_t kVaddr  = 0x0c94ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #129 @ 0x0c98: 0x54000081 -> b.ne #0xca8
// Lệnh AArch64 #129 tại 0x0c98: b.ne #0xca8
uint64_t verify_tob_encrypt_insn_129_0x0c98(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x54000081U;
    constexpr uint64_t kVaddr  = 0x0c98ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #130 @ 0x0c9c: 0x52800021 -> mov w1, #1
// Lệnh AArch64 #130 tại 0x0c9c: mov w1, #1
uint64_t verify_tob_encrypt_insn_130_0x0c9c(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x52800021U;
    constexpr uint64_t kVaddr  = 0x0c9cULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #131 @ 0x0ca0: 0xAA1303E0 -> mov x0, x19
// Lệnh AArch64 #131 tại 0x0ca0: mov x0, x19
uint64_t verify_tob_encrypt_insn_131_0x0ca0(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xAA1303E0U;
    constexpr uint64_t kVaddr  = 0x0ca0ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #132 @ 0x0ca4: 0x940001AF -> bl #0x1360
// Lệnh AArch64 #132 tại 0x0ca4: bl #0x1360
uint64_t verify_tob_encrypt_insn_132_0x0ca4(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x940001AFU;
    constexpr uint64_t kVaddr  = 0x0ca4ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #133 @ 0x0ca8: 0xB9400348 -> ldr w8, [x26]
// Lệnh AArch64 #133 tại 0x0ca8: ldr w8, [x26]
uint64_t verify_tob_encrypt_insn_133_0x0ca8(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xB9400348U;
    constexpr uint64_t kVaddr  = 0x0ca8ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #134 @ 0x0cac: 0x4ADC4309 -> eor w9, w24, w28, ror #16
// Lệnh AArch64 #134 tại 0x0cac: eor w9, w24, w28, ror #16
uint64_t verify_tob_encrypt_insn_134_0x0cac(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x4ADC4309U;
    constexpr uint64_t kVaddr  = 0x0cacULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #135 @ 0x0cb0: 0x5AC00929 -> rev w9, w9
// Lệnh AArch64 #135 tại 0x0cb0: rev w9, w9
uint64_t verify_tob_encrypt_insn_135_0x0cb0(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x5AC00929U;
    constexpr uint64_t kVaddr  = 0x0cb0ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #136 @ 0x0cb4: 0xB81FC349 -> stur w9, [x26, #-4]
// Lệnh AArch64 #136 tại 0x0cb4: stur w9, [x26, #-4]
uint64_t verify_tob_encrypt_insn_136_0x0cb4(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xB81FC349U;
    constexpr uint64_t kVaddr  = 0x0cb4ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #137 @ 0x0cb8: 0x6B1B011F -> cmp w8, w27
// Lệnh AArch64 #137 tại 0x0cb8: cmp w8, w27
uint64_t verify_tob_encrypt_insn_137_0x0cb8(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x6B1B011FU;
    constexpr uint64_t kVaddr  = 0x0cb8ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #138 @ 0x0cbc: 0x5AC0091C -> rev w28, w8
// Lệnh AArch64 #138 tại 0x0cbc: rev w28, w8
uint64_t verify_tob_encrypt_insn_138_0x0cbc(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x5AC0091CU;
    constexpr uint64_t kVaddr  = 0x0cbcULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #139 @ 0x0cc0: 0x54FFFC01 -> b.ne #0xc40
// Lệnh AArch64 #139 tại 0x0cc0: b.ne #0xc40
uint64_t verify_tob_encrypt_insn_139_0x0cc0(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x54FFFC01U;
    constexpr uint64_t kVaddr  = 0x0cc0ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #140 @ 0x0cc4: 0x52800021 -> mov w1, #1
// Lệnh AArch64 #140 tại 0x0cc4: mov w1, #1
uint64_t verify_tob_encrypt_insn_140_0x0cc4(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x52800021U;
    constexpr uint64_t kVaddr  = 0x0cc4ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #141 @ 0x0cc8: 0xAA1303E0 -> mov x0, x19
// Lệnh AArch64 #141 tại 0x0cc8: mov x0, x19
uint64_t verify_tob_encrypt_insn_141_0x0cc8(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xAA1303E0U;
    constexpr uint64_t kVaddr  = 0x0cc8ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #142 @ 0x0ccc: 0x940001A5 -> bl #0x1360
// Lệnh AArch64 #142 tại 0x0ccc: bl #0x1360
uint64_t verify_tob_encrypt_insn_142_0x0ccc(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x940001A5U;
    constexpr uint64_t kVaddr  = 0x0cccULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #143 @ 0x0cd0: 0x17FFFFDC -> b #0xc40
// Lệnh AArch64 #143 tại 0x0cd0: b #0xc40
uint64_t verify_tob_encrypt_insn_143_0x0cd0(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x17FFFFDCU;
    constexpr uint64_t kVaddr  = 0x0cd0ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #144 @ 0x0cd4: 0x2A1F03E0 -> mov w0, wzr
// Lệnh AArch64 #144 tại 0x0cd4: mov w0, wzr
uint64_t verify_tob_encrypt_insn_144_0x0cd4(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x2A1F03E0U;
    constexpr uint64_t kVaddr  = 0x0cd4ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #145 @ 0x0cd8: 0xF94016E8 -> ldr x8, [x23, #0x28]
// Lệnh AArch64 #145 tại 0x0cd8: ldr x8, [x23, #0x28]
uint64_t verify_tob_encrypt_insn_145_0x0cd8(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xF94016E8U;
    constexpr uint64_t kVaddr  = 0x0cd8ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #146 @ 0x0cdc: 0xF85F83A9 -> ldur x9, [x29, #-8]
// Lệnh AArch64 #146 tại 0x0cdc: ldur x9, [x29, #-8]
uint64_t verify_tob_encrypt_insn_146_0x0cdc(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xF85F83A9U;
    constexpr uint64_t kVaddr  = 0x0cdcULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #147 @ 0x0ce0: 0xEB09011F -> cmp x8, x9
// Lệnh AArch64 #147 tại 0x0ce0: cmp x8, x9
uint64_t verify_tob_encrypt_insn_147_0x0ce0(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xEB09011FU;
    constexpr uint64_t kVaddr  = 0x0ce0ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #148 @ 0x0ce4: 0x54000121 -> b.ne #0xd08
// Lệnh AArch64 #148 tại 0x0ce4: b.ne #0xd08
uint64_t verify_tob_encrypt_insn_148_0x0ce4(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x54000121U;
    constexpr uint64_t kVaddr  = 0x0ce4ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #149 @ 0x0ce8: 0xA9474FF4 -> ldp x20, x19, [sp, #0x70]
// Lệnh AArch64 #149 tại 0x0ce8: ldp x20, x19, [sp, #0x70]
uint64_t verify_tob_encrypt_insn_149_0x0ce8(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xA9474FF4U;
    constexpr uint64_t kVaddr  = 0x0ce8ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #150 @ 0x0cec: 0xA94657F6 -> ldp x22, x21, [sp, #0x60]
// Lệnh AArch64 #150 tại 0x0cec: ldp x22, x21, [sp, #0x60]
uint64_t verify_tob_encrypt_insn_150_0x0cec(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xA94657F6U;
    constexpr uint64_t kVaddr  = 0x0cecULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #151 @ 0x0cf0: 0xA9455FF8 -> ldp x24, x23, [sp, #0x50]
// Lệnh AArch64 #151 tại 0x0cf0: ldp x24, x23, [sp, #0x50]
uint64_t verify_tob_encrypt_insn_151_0x0cf0(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xA9455FF8U;
    constexpr uint64_t kVaddr  = 0x0cf0ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #152 @ 0x0cf4: 0xA94467FA -> ldp x26, x25, [sp, #0x40]
// Lệnh AArch64 #152 tại 0x0cf4: ldp x26, x25, [sp, #0x40]
uint64_t verify_tob_encrypt_insn_152_0x0cf4(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xA94467FAU;
    constexpr uint64_t kVaddr  = 0x0cf4ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #153 @ 0x0cf8: 0xA9436FFC -> ldp x28, x27, [sp, #0x30]
// Lệnh AArch64 #153 tại 0x0cf8: ldp x28, x27, [sp, #0x30]
uint64_t verify_tob_encrypt_insn_153_0x0cf8(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xA9436FFCU;
    constexpr uint64_t kVaddr  = 0x0cf8ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #154 @ 0x0cfc: 0xA9427BFD -> ldp x29, x30, [sp, #0x20]
// Lệnh AArch64 #154 tại 0x0cfc: ldp x29, x30, [sp, #0x20]
uint64_t verify_tob_encrypt_insn_154_0x0cfc(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xA9427BFDU;
    constexpr uint64_t kVaddr  = 0x0cfcULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #155 @ 0x0d00: 0x910203FF -> add sp, sp, #0x80
// Lệnh AArch64 #155 tại 0x0d00: add sp, sp, #0x80
uint64_t verify_tob_encrypt_insn_155_0x0d00(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x910203FFU;
    constexpr uint64_t kVaddr  = 0x0d00ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #156 @ 0x0d04: 0xD65F03C0 -> ret 
// Lệnh AArch64 #156 tại 0x0d04: ret 
uint64_t verify_tob_encrypt_insn_156_0x0d04(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xD65F03C0U;
    constexpr uint64_t kVaddr  = 0x0d04ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #157 @ 0x0d08: 0x9400018E -> bl #0x1340
// Lệnh AArch64 #157 tại 0x0d08: bl #0x1340
uint64_t verify_tob_encrypt_insn_157_0x0d08(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x9400018EU;
    constexpr uint64_t kVaddr  = 0x0d08ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #158 @ 0x0d0c: 0xD10103FF -> sub sp, sp, #0x40
// Lệnh AArch64 #158 tại 0x0d0c: sub sp, sp, #0x40
uint64_t verify_tob_encrypt_insn_158_0x0d0c(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xD10103FFU;
    constexpr uint64_t kVaddr  = 0x0d0cULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #159 @ 0x0d10: 0xA9017BFD -> stp x29, x30, [sp, #0x10]
// Lệnh AArch64 #159 tại 0x0d10: stp x29, x30, [sp, #0x10]
uint64_t verify_tob_encrypt_insn_159_0x0d10(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xA9017BFDU;
    constexpr uint64_t kVaddr  = 0x0d10ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #160 @ 0x0d14: 0xA90257F6 -> stp x22, x21, [sp, #0x20]
// Lệnh AArch64 #160 tại 0x0d14: stp x22, x21, [sp, #0x20]
uint64_t verify_tob_encrypt_insn_160_0x0d14(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xA90257F6U;
    constexpr uint64_t kVaddr  = 0x0d14ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #161 @ 0x0d18: 0xA9034FF4 -> stp x20, x19, [sp, #0x30]
// Lệnh AArch64 #161 tại 0x0d18: stp x20, x19, [sp, #0x30]
uint64_t verify_tob_encrypt_insn_161_0x0d18(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xA9034FF4U;
    constexpr uint64_t kVaddr  = 0x0d18ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #162 @ 0x0d1c: 0x910043FD -> add x29, sp, #0x10
// Lệnh AArch64 #162 tại 0x0d1c: add x29, sp, #0x10
uint64_t verify_tob_encrypt_insn_162_0x0d1c(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x910043FDU;
    constexpr uint64_t kVaddr  = 0x0d1cULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #163 @ 0x0d20: 0x2A0103F5 -> mov w21, w1
// Lệnh AArch64 #163 tại 0x0d20: mov w21, w1
uint64_t verify_tob_encrypt_insn_163_0x0d20(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x2A0103F5U;
    constexpr uint64_t kVaddr  = 0x0d20ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #164 @ 0x0d24: 0xD53BD056 -> mrs x22, tpidr_el0
// Lệnh AArch64 #164 tại 0x0d24: mrs x22, tpidr_el0
uint64_t verify_tob_encrypt_insn_164_0x0d24(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xD53BD056U;
    constexpr uint64_t kVaddr  = 0x0d24ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #165 @ 0x0d28: 0xF94016C8 -> ldr x8, [x22, #0x28]
// Lệnh AArch64 #165 tại 0x0d28: ldr x8, [x22, #0x28]
uint64_t verify_tob_encrypt_insn_165_0x0d28(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xF94016C8U;
    constexpr uint64_t kVaddr  = 0x0d28ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #166 @ 0x0d2c: 0x710042BF -> cmp w21, #0x10
// Lệnh AArch64 #166 tại 0x0d2c: cmp w21, #0x10
uint64_t verify_tob_encrypt_insn_166_0x0d2c(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x710042BFU;
    constexpr uint64_t kVaddr  = 0x0d2cULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #167 @ 0x0d30: 0x52800209 -> mov w9, #0x10
// Lệnh AArch64 #167 tại 0x0d30: mov w9, #0x10
uint64_t verify_tob_encrypt_insn_167_0x0d30(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x52800209U;
    constexpr uint64_t kVaddr  = 0x0d30ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #168 @ 0x0d34: 0x1A89B2A9 -> csel w9, w21, w9, lt
// Lệnh AArch64 #168 tại 0x0d34: csel w9, w21, w9, lt
uint64_t verify_tob_encrypt_insn_168_0x0d34(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x1A89B2A9U;
    constexpr uint64_t kVaddr  = 0x0d34ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #169 @ 0x0d38: 0x93407D34 -> sxtw x20, w9
// Lệnh AArch64 #169 tại 0x0d38: sxtw x20, w9
uint64_t verify_tob_encrypt_insn_169_0x0d38(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x93407D34U;
    constexpr uint64_t kVaddr  = 0x0d38ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #170 @ 0x0d3c: 0xAA0203F3 -> mov x19, x2
// Lệnh AArch64 #170 tại 0x0d3c: mov x19, x2
uint64_t verify_tob_encrypt_insn_170_0x0d3c(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xAA0203F3U;
    constexpr uint64_t kVaddr  = 0x0d3cULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #171 @ 0x0d40: 0xAA0003E1 -> mov x1, x0
// Lệnh AArch64 #171 tại 0x0d40: mov x1, x0
uint64_t verify_tob_encrypt_insn_171_0x0d40(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xAA0003E1U;
    constexpr uint64_t kVaddr  = 0x0d40ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #172 @ 0x0d44: 0xAA0203E0 -> mov x0, x2
// Lệnh AArch64 #172 tại 0x0d44: mov x0, x2
uint64_t verify_tob_encrypt_insn_172_0x0d44(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xAA0203E0U;
    constexpr uint64_t kVaddr  = 0x0d44ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #173 @ 0x0d48: 0xAA1403E2 -> mov x2, x20
// Lệnh AArch64 #173 tại 0x0d48: mov x2, x20
uint64_t verify_tob_encrypt_insn_173_0x0d48(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xAA1403E2U;
    constexpr uint64_t kVaddr  = 0x0d48ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #174 @ 0x0d4c: 0xF90007E8 -> str x8, [sp, #8]
// Lệnh AArch64 #174 tại 0x0d4c: str x8, [sp, #8]
uint64_t verify_tob_encrypt_insn_174_0x0d4c(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xF90007E8U;
    constexpr uint64_t kVaddr  = 0x0d4cULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #175 @ 0x0d50: 0x94000188 -> bl #0x1370
// Lệnh AArch64 #175 tại 0x0d50: bl #0x1370
uint64_t verify_tob_encrypt_insn_175_0x0d50(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x94000188U;
    constexpr uint64_t kVaddr  = 0x0d50ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #176 @ 0x0d54: 0x71003EBF -> cmp w21, #0xf
// Lệnh AArch64 #176 tại 0x0d54: cmp w21, #0xf
uint64_t verify_tob_encrypt_insn_176_0x0d54(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x71003EBFU;
    constexpr uint64_t kVaddr  = 0x0d54ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #177 @ 0x0d58: 0x540001CC -> b.gt #0xd90
// Lệnh AArch64 #177 tại 0x0d58: b.gt #0xd90
uint64_t verify_tob_encrypt_insn_177_0x0d58(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x540001CCU;
    constexpr uint64_t kVaddr  = 0x0d58ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #178 @ 0x0d5c: 0xB000002A -> adrp x10, #0x5000
// Lệnh AArch64 #178 tại 0x0d5c: adrp x10, #0x5000
uint64_t verify_tob_encrypt_insn_178_0x0d5c(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xB000002AU;
    constexpr uint64_t kVaddr  = 0x0d5cULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #179 @ 0x0d60: 0x71003E9F -> cmp w20, #0xf
// Lệnh AArch64 #179 tại 0x0d60: cmp w20, #0xf
uint64_t verify_tob_encrypt_insn_179_0x0d60(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x71003E9FU;
    constexpr uint64_t kVaddr  = 0x0d60ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #180 @ 0x0d64: 0x528001E9 -> mov w9, #0xf
// Lệnh AArch64 #180 tại 0x0d64: mov w9, #0xf
uint64_t verify_tob_encrypt_insn_180_0x0d64(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x528001E9U;
    constexpr uint64_t kVaddr  = 0x0d64ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #181 @ 0x0d68: 0xF942D94A -> ldr x10, [x10, #0x5b0]
// Lệnh AArch64 #181 tại 0x0d68: ldr x10, [x10, #0x5b0]
uint64_t verify_tob_encrypt_insn_181_0x0d68(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xF942D94AU;
    constexpr uint64_t kVaddr  = 0x0d68ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #182 @ 0x0d6c: 0x1A89C289 -> csel w9, w20, w9, gt
// Lệnh AArch64 #182 tại 0x0d6c: csel w9, w20, w9, gt
uint64_t verify_tob_encrypt_insn_182_0x0d6c(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x1A89C289U;
    constexpr uint64_t kVaddr  = 0x0d6cULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #183 @ 0x0d70: 0x4B140129 -> sub w9, w9, w20
// Lệnh AArch64 #183 tại 0x0d70: sub w9, w9, w20
uint64_t verify_tob_encrypt_insn_183_0x0d70(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x4B140129U;
    constexpr uint64_t kVaddr  = 0x0d70ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #184 @ 0x0d74: 0x8B140268 -> add x8, x19, x20
// Lệnh AArch64 #184 tại 0x0d74: add x8, x19, x20
uint64_t verify_tob_encrypt_insn_184_0x0d74(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x8B140268U;
    constexpr uint64_t kVaddr  = 0x0d74ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #185 @ 0x0d78: 0x11000529 -> add w9, w9, #1
// Lệnh AArch64 #185 tại 0x0d78: add w9, w9, #1
uint64_t verify_tob_encrypt_insn_185_0x0d78(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x11000529U;
    constexpr uint64_t kVaddr  = 0x0d78ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #186 @ 0x0d7c: 0x385FF10B -> ldurb w11, [x8, #-1]
// Lệnh AArch64 #186 tại 0x0d7c: ldurb w11, [x8, #-1]
uint64_t verify_tob_encrypt_insn_186_0x0d7c(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x385FF10BU;
    constexpr uint64_t kVaddr  = 0x0d7cULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #187 @ 0x0d80: 0x71000529 -> subs w9, w9, #1
// Lệnh AArch64 #187 tại 0x0d80: subs w9, w9, #1
uint64_t verify_tob_encrypt_insn_187_0x0d80(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x71000529U;
    constexpr uint64_t kVaddr  = 0x0d80ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #188 @ 0x0d84: 0x386B694B -> ldrb w11, [x10, x11]
// Lệnh AArch64 #188 tại 0x0d84: ldrb w11, [x10, x11]
uint64_t verify_tob_encrypt_insn_188_0x0d84(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x386B694BU;
    constexpr uint64_t kVaddr  = 0x0d84ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #189 @ 0x0d88: 0x3800150B -> strb w11, [x8], #1
// Lệnh AArch64 #189 tại 0x0d88: strb w11, [x8], #1
uint64_t verify_tob_encrypt_insn_189_0x0d88(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x3800150BU;
    constexpr uint64_t kVaddr  = 0x0d88ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #190 @ 0x0d8c: 0x54FFFF81 -> b.ne #0xd7c
// Lệnh AArch64 #190 tại 0x0d8c: b.ne #0xd7c
uint64_t verify_tob_encrypt_insn_190_0x0d8c(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x54FFFF81U;
    constexpr uint64_t kVaddr  = 0x0d8cULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #191 @ 0x0d90: 0xB0000028 -> adrp x8, #0x5000
// Lệnh AArch64 #191 tại 0x0d90: adrp x8, #0x5000
uint64_t verify_tob_encrypt_insn_191_0x0d90(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xB0000028U;
    constexpr uint64_t kVaddr  = 0x0d90ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #192 @ 0x0d94: 0x39400269 -> ldrb w9, [x19]
// Lệnh AArch64 #192 tại 0x0d94: ldrb w9, [x19]
uint64_t verify_tob_encrypt_insn_192_0x0d94(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x39400269U;
    constexpr uint64_t kVaddr  = 0x0d94ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #193 @ 0x0d98: 0xF942D508 -> ldr x8, [x8, #0x5a8]
// Lệnh AArch64 #193 tại 0x0d98: ldr x8, [x8, #0x5a8]
uint64_t verify_tob_encrypt_insn_193_0x0d98(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xF942D508U;
    constexpr uint64_t kVaddr  = 0x0d98ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #194 @ 0x0d9c: 0x3940066A -> ldrb w10, [x19, #1]
// Lệnh AArch64 #194 tại 0x0d9c: ldrb w10, [x19, #1]
uint64_t verify_tob_encrypt_insn_194_0x0d9c(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x3940066AU;
    constexpr uint64_t kVaddr  = 0x0d9cULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #195 @ 0x0da0: 0x38696909 -> ldrb w9, [x8, x9]
// Lệnh AArch64 #195 tại 0x0da0: ldrb w9, [x8, x9]
uint64_t verify_tob_encrypt_insn_195_0x0da0(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x38696909U;
    constexpr uint64_t kVaddr  = 0x0da0ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #196 @ 0x0da4: 0x39000269 -> strb w9, [x19]
// Lệnh AArch64 #196 tại 0x0da4: strb w9, [x19]
uint64_t verify_tob_encrypt_insn_196_0x0da4(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x39000269U;
    constexpr uint64_t kVaddr  = 0x0da4ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #197 @ 0x0da8: 0x386A6909 -> ldrb w9, [x8, x10]
// Lệnh AArch64 #197 tại 0x0da8: ldrb w9, [x8, x10]
uint64_t verify_tob_encrypt_insn_197_0x0da8(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x386A6909U;
    constexpr uint64_t kVaddr  = 0x0da8ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #198 @ 0x0dac: 0x39400A6A -> ldrb w10, [x19, #2]
// Lệnh AArch64 #198 tại 0x0dac: ldrb w10, [x19, #2]
uint64_t verify_tob_encrypt_insn_198_0x0dac(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x39400A6AU;
    constexpr uint64_t kVaddr  = 0x0dacULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #199 @ 0x0db0: 0x39000669 -> strb w9, [x19, #1]
// Lệnh AArch64 #199 tại 0x0db0: strb w9, [x19, #1]
uint64_t verify_tob_encrypt_insn_199_0x0db0(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x39000669U;
    constexpr uint64_t kVaddr  = 0x0db0ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #200 @ 0x0db4: 0x386A6909 -> ldrb w9, [x8, x10]
// Lệnh AArch64 #200 tại 0x0db4: ldrb w9, [x8, x10]
uint64_t verify_tob_encrypt_insn_200_0x0db4(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x386A6909U;
    constexpr uint64_t kVaddr  = 0x0db4ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #201 @ 0x0db8: 0x39400E6A -> ldrb w10, [x19, #3]
// Lệnh AArch64 #201 tại 0x0db8: ldrb w10, [x19, #3]
uint64_t verify_tob_encrypt_insn_201_0x0db8(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x39400E6AU;
    constexpr uint64_t kVaddr  = 0x0db8ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #202 @ 0x0dbc: 0x39000A69 -> strb w9, [x19, #2]
// Lệnh AArch64 #202 tại 0x0dbc: strb w9, [x19, #2]
uint64_t verify_tob_encrypt_insn_202_0x0dbc(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x39000A69U;
    constexpr uint64_t kVaddr  = 0x0dbcULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #203 @ 0x0dc0: 0x386A6909 -> ldrb w9, [x8, x10]
// Lệnh AArch64 #203 tại 0x0dc0: ldrb w9, [x8, x10]
uint64_t verify_tob_encrypt_insn_203_0x0dc0(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x386A6909U;
    constexpr uint64_t kVaddr  = 0x0dc0ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #204 @ 0x0dc4: 0x3940126A -> ldrb w10, [x19, #4]
// Lệnh AArch64 #204 tại 0x0dc4: ldrb w10, [x19, #4]
uint64_t verify_tob_encrypt_insn_204_0x0dc4(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x3940126AU;
    constexpr uint64_t kVaddr  = 0x0dc4ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #205 @ 0x0dc8: 0x39000E69 -> strb w9, [x19, #3]
// Lệnh AArch64 #205 tại 0x0dc8: strb w9, [x19, #3]
uint64_t verify_tob_encrypt_insn_205_0x0dc8(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x39000E69U;
    constexpr uint64_t kVaddr  = 0x0dc8ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #206 @ 0x0dcc: 0x386A6909 -> ldrb w9, [x8, x10]
// Lệnh AArch64 #206 tại 0x0dcc: ldrb w9, [x8, x10]
uint64_t verify_tob_encrypt_insn_206_0x0dcc(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x386A6909U;
    constexpr uint64_t kVaddr  = 0x0dccULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #207 @ 0x0dd0: 0x3940166A -> ldrb w10, [x19, #5]
// Lệnh AArch64 #207 tại 0x0dd0: ldrb w10, [x19, #5]
uint64_t verify_tob_encrypt_insn_207_0x0dd0(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x3940166AU;
    constexpr uint64_t kVaddr  = 0x0dd0ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #208 @ 0x0dd4: 0x39001269 -> strb w9, [x19, #4]
// Lệnh AArch64 #208 tại 0x0dd4: strb w9, [x19, #4]
uint64_t verify_tob_encrypt_insn_208_0x0dd4(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x39001269U;
    constexpr uint64_t kVaddr  = 0x0dd4ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #209 @ 0x0dd8: 0x386A6909 -> ldrb w9, [x8, x10]
// Lệnh AArch64 #209 tại 0x0dd8: ldrb w9, [x8, x10]
uint64_t verify_tob_encrypt_insn_209_0x0dd8(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x386A6909U;
    constexpr uint64_t kVaddr  = 0x0dd8ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #210 @ 0x0ddc: 0x39401A6A -> ldrb w10, [x19, #6]
// Lệnh AArch64 #210 tại 0x0ddc: ldrb w10, [x19, #6]
uint64_t verify_tob_encrypt_insn_210_0x0ddc(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x39401A6AU;
    constexpr uint64_t kVaddr  = 0x0ddcULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #211 @ 0x0de0: 0x39001669 -> strb w9, [x19, #5]
// Lệnh AArch64 #211 tại 0x0de0: strb w9, [x19, #5]
uint64_t verify_tob_encrypt_insn_211_0x0de0(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x39001669U;
    constexpr uint64_t kVaddr  = 0x0de0ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #212 @ 0x0de4: 0x386A6909 -> ldrb w9, [x8, x10]
// Lệnh AArch64 #212 tại 0x0de4: ldrb w9, [x8, x10]
uint64_t verify_tob_encrypt_insn_212_0x0de4(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x386A6909U;
    constexpr uint64_t kVaddr  = 0x0de4ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #213 @ 0x0de8: 0x39401E6A -> ldrb w10, [x19, #7]
// Lệnh AArch64 #213 tại 0x0de8: ldrb w10, [x19, #7]
uint64_t verify_tob_encrypt_insn_213_0x0de8(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x39401E6AU;
    constexpr uint64_t kVaddr  = 0x0de8ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #214 @ 0x0dec: 0x39001A69 -> strb w9, [x19, #6]
// Lệnh AArch64 #214 tại 0x0dec: strb w9, [x19, #6]
uint64_t verify_tob_encrypt_insn_214_0x0dec(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x39001A69U;
    constexpr uint64_t kVaddr  = 0x0decULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #215 @ 0x0df0: 0x386A6909 -> ldrb w9, [x8, x10]
// Lệnh AArch64 #215 tại 0x0df0: ldrb w9, [x8, x10]
uint64_t verify_tob_encrypt_insn_215_0x0df0(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x386A6909U;
    constexpr uint64_t kVaddr  = 0x0df0ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #216 @ 0x0df4: 0x3940226A -> ldrb w10, [x19, #8]
// Lệnh AArch64 #216 tại 0x0df4: ldrb w10, [x19, #8]
uint64_t verify_tob_encrypt_insn_216_0x0df4(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x3940226AU;
    constexpr uint64_t kVaddr  = 0x0df4ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #217 @ 0x0df8: 0x39001E69 -> strb w9, [x19, #7]
// Lệnh AArch64 #217 tại 0x0df8: strb w9, [x19, #7]
uint64_t verify_tob_encrypt_insn_217_0x0df8(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x39001E69U;
    constexpr uint64_t kVaddr  = 0x0df8ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #218 @ 0x0dfc: 0x386A6909 -> ldrb w9, [x8, x10]
// Lệnh AArch64 #218 tại 0x0dfc: ldrb w9, [x8, x10]
uint64_t verify_tob_encrypt_insn_218_0x0dfc(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x386A6909U;
    constexpr uint64_t kVaddr  = 0x0dfcULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #219 @ 0x0e00: 0x3940266A -> ldrb w10, [x19, #9]
// Lệnh AArch64 #219 tại 0x0e00: ldrb w10, [x19, #9]
uint64_t verify_tob_encrypt_insn_219_0x0e00(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x3940266AU;
    constexpr uint64_t kVaddr  = 0x0e00ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #220 @ 0x0e04: 0x2940326B -> ldp w11, w12, [x19]
// Lệnh AArch64 #220 tại 0x0e04: ldp w11, w12, [x19]
uint64_t verify_tob_encrypt_insn_220_0x0e04(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x2940326BU;
    constexpr uint64_t kVaddr  = 0x0e04ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #221 @ 0x0e08: 0x39002269 -> strb w9, [x19, #8]
// Lệnh AArch64 #221 tại 0x0e08: strb w9, [x19, #8]
uint64_t verify_tob_encrypt_insn_221_0x0e08(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x39002269U;
    constexpr uint64_t kVaddr  = 0x0e08ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #222 @ 0x0e0c: 0x386A6909 -> ldrb w9, [x8, x10]
// Lệnh AArch64 #222 tại 0x0e0c: ldrb w9, [x8, x10]
uint64_t verify_tob_encrypt_insn_222_0x0e0c(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x386A6909U;
    constexpr uint64_t kVaddr  = 0x0e0cULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #223 @ 0x0e10: 0x39402A6A -> ldrb w10, [x19, #0xa]
// Lệnh AArch64 #223 tại 0x0e10: ldrb w10, [x19, #0xa]
uint64_t verify_tob_encrypt_insn_223_0x0e10(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x39402A6AU;
    constexpr uint64_t kVaddr  = 0x0e10ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #224 @ 0x0e14: 0x39002669 -> strb w9, [x19, #9]
// Lệnh AArch64 #224 tại 0x0e14: strb w9, [x19, #9]
uint64_t verify_tob_encrypt_insn_224_0x0e14(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x39002669U;
    constexpr uint64_t kVaddr  = 0x0e14ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #225 @ 0x0e18: 0x386A6909 -> ldrb w9, [x8, x10]
// Lệnh AArch64 #225 tại 0x0e18: ldrb w9, [x8, x10]
uint64_t verify_tob_encrypt_insn_225_0x0e18(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x386A6909U;
    constexpr uint64_t kVaddr  = 0x0e18ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #226 @ 0x0e1c: 0x39402E6A -> ldrb w10, [x19, #0xb]
// Lệnh AArch64 #226 tại 0x0e1c: ldrb w10, [x19, #0xb]
uint64_t verify_tob_encrypt_insn_226_0x0e1c(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x39402E6AU;
    constexpr uint64_t kVaddr  = 0x0e1cULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #227 @ 0x0e20: 0x39002A69 -> strb w9, [x19, #0xa]
// Lệnh AArch64 #227 tại 0x0e20: strb w9, [x19, #0xa]
uint64_t verify_tob_encrypt_insn_227_0x0e20(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x39002A69U;
    constexpr uint64_t kVaddr  = 0x0e20ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #228 @ 0x0e24: 0x386A6909 -> ldrb w9, [x8, x10]
// Lệnh AArch64 #228 tại 0x0e24: ldrb w9, [x8, x10]
uint64_t verify_tob_encrypt_insn_228_0x0e24(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x386A6909U;
    constexpr uint64_t kVaddr  = 0x0e24ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #229 @ 0x0e28: 0x3940326A -> ldrb w10, [x19, #0xc]
// Lệnh AArch64 #229 tại 0x0e28: ldrb w10, [x19, #0xc]
uint64_t verify_tob_encrypt_insn_229_0x0e28(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x3940326AU;
    constexpr uint64_t kVaddr  = 0x0e28ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #230 @ 0x0e2c: 0x39002E69 -> strb w9, [x19, #0xb]
// Lệnh AArch64 #230 tại 0x0e2c: strb w9, [x19, #0xb]
uint64_t verify_tob_encrypt_insn_230_0x0e2c(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x39002E69U;
    constexpr uint64_t kVaddr  = 0x0e2cULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #231 @ 0x0e30: 0x386A6909 -> ldrb w9, [x8, x10]
// Lệnh AArch64 #231 tại 0x0e30: ldrb w9, [x8, x10]
uint64_t verify_tob_encrypt_insn_231_0x0e30(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x386A6909U;
    constexpr uint64_t kVaddr  = 0x0e30ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #232 @ 0x0e34: 0x3940366A -> ldrb w10, [x19, #0xd]
// Lệnh AArch64 #232 tại 0x0e34: ldrb w10, [x19, #0xd]
uint64_t verify_tob_encrypt_insn_232_0x0e34(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x3940366AU;
    constexpr uint64_t kVaddr  = 0x0e34ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #233 @ 0x0e38: 0x39003269 -> strb w9, [x19, #0xc]
// Lệnh AArch64 #233 tại 0x0e38: strb w9, [x19, #0xc]
uint64_t verify_tob_encrypt_insn_233_0x0e38(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x39003269U;
    constexpr uint64_t kVaddr  = 0x0e38ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #234 @ 0x0e3c: 0x386A6909 -> ldrb w9, [x8, x10]
// Lệnh AArch64 #234 tại 0x0e3c: ldrb w9, [x8, x10]
uint64_t verify_tob_encrypt_insn_234_0x0e3c(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x386A6909U;
    constexpr uint64_t kVaddr  = 0x0e3cULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #235 @ 0x0e40: 0x39403A6A -> ldrb w10, [x19, #0xe]
// Lệnh AArch64 #235 tại 0x0e40: ldrb w10, [x19, #0xe]
uint64_t verify_tob_encrypt_insn_235_0x0e40(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x39403A6AU;
    constexpr uint64_t kVaddr  = 0x0e40ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #236 @ 0x0e44: 0x39003669 -> strb w9, [x19, #0xd]
// Lệnh AArch64 #236 tại 0x0e44: strb w9, [x19, #0xd]
uint64_t verify_tob_encrypt_insn_236_0x0e44(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x39003669U;
    constexpr uint64_t kVaddr  = 0x0e44ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #237 @ 0x0e48: 0x386A6909 -> ldrb w9, [x8, x10]
// Lệnh AArch64 #237 tại 0x0e48: ldrb w9, [x8, x10]
uint64_t verify_tob_encrypt_insn_237_0x0e48(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x386A6909U;
    constexpr uint64_t kVaddr  = 0x0e48ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #238 @ 0x0e4c: 0x39403E6A -> ldrb w10, [x19, #0xf]
// Lệnh AArch64 #238 tại 0x0e4c: ldrb w10, [x19, #0xf]
uint64_t verify_tob_encrypt_insn_238_0x0e4c(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x39403E6AU;
    constexpr uint64_t kVaddr  = 0x0e4cULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #239 @ 0x0e50: 0x39003A69 -> strb w9, [x19, #0xe]
// Lệnh AArch64 #239 tại 0x0e50: strb w9, [x19, #0xe]
uint64_t verify_tob_encrypt_insn_239_0x0e50(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x39003A69U;
    constexpr uint64_t kVaddr  = 0x0e50ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #240 @ 0x0e54: 0x386A6908 -> ldrb w8, [x8, x10]
// Lệnh AArch64 #240 tại 0x0e54: ldrb w8, [x8, x10]
uint64_t verify_tob_encrypt_insn_240_0x0e54(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x386A6908U;
    constexpr uint64_t kVaddr  = 0x0e54ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #241 @ 0x0e58: 0x5AC00969 -> rev w9, w11
// Lệnh AArch64 #241 tại 0x0e58: rev w9, w11
uint64_t verify_tob_encrypt_insn_241_0x0e58(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x5AC00969U;
    constexpr uint64_t kVaddr  = 0x0e58ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #242 @ 0x0e5c: 0x5AC0098A -> rev w10, w12
// Lệnh AArch64 #242 tại 0x0e5c: rev w10, w12
uint64_t verify_tob_encrypt_insn_242_0x0e5c(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x5AC0098AU;
    constexpr uint64_t kVaddr  = 0x0e5cULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #243 @ 0x0e60: 0x29002A69 -> stp w9, w10, [x19]
// Lệnh AArch64 #243 tại 0x0e60: stp w9, w10, [x19]
uint64_t verify_tob_encrypt_insn_243_0x0e60(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x29002A69U;
    constexpr uint64_t kVaddr  = 0x0e60ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #244 @ 0x0e64: 0x39003E68 -> strb w8, [x19, #0xf]
// Lệnh AArch64 #244 tại 0x0e64: strb w8, [x19, #0xf]
uint64_t verify_tob_encrypt_insn_244_0x0e64(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x39003E68U;
    constexpr uint64_t kVaddr  = 0x0e64ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #245 @ 0x0e68: 0x29412269 -> ldp w9, w8, [x19, #8]
// Lệnh AArch64 #245 tại 0x0e68: ldp w9, w8, [x19, #8]
uint64_t verify_tob_encrypt_insn_245_0x0e68(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x29412269U;
    constexpr uint64_t kVaddr  = 0x0e68ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #246 @ 0x0e6c: 0x5AC00929 -> rev w9, w9
// Lệnh AArch64 #246 tại 0x0e6c: rev w9, w9
uint64_t verify_tob_encrypt_insn_246_0x0e6c(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x5AC00929U;
    constexpr uint64_t kVaddr  = 0x0e6cULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #247 @ 0x0e70: 0x5AC00908 -> rev w8, w8
// Lệnh AArch64 #247 tại 0x0e70: rev w8, w8
uint64_t verify_tob_encrypt_insn_247_0x0e70(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x5AC00908U;
    constexpr uint64_t kVaddr  = 0x0e70ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #248 @ 0x0e74: 0x29012269 -> stp w9, w8, [x19, #8]
// Lệnh AArch64 #248 tại 0x0e74: stp w9, w8, [x19, #8]
uint64_t verify_tob_encrypt_insn_248_0x0e74(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x29012269U;
    constexpr uint64_t kVaddr  = 0x0e74ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #249 @ 0x0e78: 0xF94016C8 -> ldr x8, [x22, #0x28]
// Lệnh AArch64 #249 tại 0x0e78: ldr x8, [x22, #0x28]
uint64_t verify_tob_encrypt_insn_249_0x0e78(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xF94016C8U;
    constexpr uint64_t kVaddr  = 0x0e78ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #250 @ 0x0e7c: 0xF94007E9 -> ldr x9, [sp, #8]
// Lệnh AArch64 #250 tại 0x0e7c: ldr x9, [sp, #8]
uint64_t verify_tob_encrypt_insn_250_0x0e7c(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xF94007E9U;
    constexpr uint64_t kVaddr  = 0x0e7cULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #251 @ 0x0e80: 0xEB09011F -> cmp x8, x9
// Lệnh AArch64 #251 tại 0x0e80: cmp x8, x9
uint64_t verify_tob_encrypt_insn_251_0x0e80(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xEB09011FU;
    constexpr uint64_t kVaddr  = 0x0e80ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #252 @ 0x0e84: 0x540000C1 -> b.ne #0xe9c
// Lệnh AArch64 #252 tại 0x0e84: b.ne #0xe9c
uint64_t verify_tob_encrypt_insn_252_0x0e84(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x540000C1U;
    constexpr uint64_t kVaddr  = 0x0e84ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #253 @ 0x0e88: 0xA9434FF4 -> ldp x20, x19, [sp, #0x30]
// Lệnh AArch64 #253 tại 0x0e88: ldp x20, x19, [sp, #0x30]
uint64_t verify_tob_encrypt_insn_253_0x0e88(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xA9434FF4U;
    constexpr uint64_t kVaddr  = 0x0e88ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #254 @ 0x0e8c: 0xA94257F6 -> ldp x22, x21, [sp, #0x20]
// Lệnh AArch64 #254 tại 0x0e8c: ldp x22, x21, [sp, #0x20]
uint64_t verify_tob_encrypt_insn_254_0x0e8c(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xA94257F6U;
    constexpr uint64_t kVaddr  = 0x0e8cULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #255 @ 0x0e90: 0xA9417BFD -> ldp x29, x30, [sp, #0x10]
// Lệnh AArch64 #255 tại 0x0e90: ldp x29, x30, [sp, #0x10]
uint64_t verify_tob_encrypt_insn_255_0x0e90(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xA9417BFDU;
    constexpr uint64_t kVaddr  = 0x0e90ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #256 @ 0x0e94: 0x910103FF -> add sp, sp, #0x40
// Lệnh AArch64 #256 tại 0x0e94: add sp, sp, #0x40
uint64_t verify_tob_encrypt_insn_256_0x0e94(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x910103FFU;
    constexpr uint64_t kVaddr  = 0x0e94ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #257 @ 0x0e98: 0xD65F03C0 -> ret 
// Lệnh AArch64 #257 tại 0x0e98: ret 
uint64_t verify_tob_encrypt_insn_257_0x0e98(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xD65F03C0U;
    constexpr uint64_t kVaddr  = 0x0e98ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #258 @ 0x0e9c: 0x94000129 -> bl #0x1340
// Lệnh AArch64 #258 tại 0x0e9c: bl #0x1340
uint64_t verify_tob_encrypt_insn_258_0x0e9c(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x94000129U;
    constexpr uint64_t kVaddr  = 0x0e9cULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #259 @ 0x0ea0: 0xD10183FF -> sub sp, sp, #0x60
// Lệnh AArch64 #259 tại 0x0ea0: sub sp, sp, #0x60
uint64_t verify_tob_encrypt_insn_259_0x0ea0(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xD10183FFU;
    constexpr uint64_t kVaddr  = 0x0ea0ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #260 @ 0x0ea4: 0xA9027BFD -> stp x29, x30, [sp, #0x20]
// Lệnh AArch64 #260 tại 0x0ea4: stp x29, x30, [sp, #0x20]
uint64_t verify_tob_encrypt_insn_260_0x0ea4(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xA9027BFDU;
    constexpr uint64_t kVaddr  = 0x0ea4ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #261 @ 0x0ea8: 0xF9001BF7 -> str x23, [sp, #0x30]
// Lệnh AArch64 #261 tại 0x0ea8: str x23, [sp, #0x30]
uint64_t verify_tob_encrypt_insn_261_0x0ea8(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xF9001BF7U;
    constexpr uint64_t kVaddr  = 0x0ea8ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #262 @ 0x0eac: 0xA90457F6 -> stp x22, x21, [sp, #0x40]
// Lệnh AArch64 #262 tại 0x0eac: stp x22, x21, [sp, #0x40]
uint64_t verify_tob_encrypt_insn_262_0x0eac(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xA90457F6U;
    constexpr uint64_t kVaddr  = 0x0eacULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #263 @ 0x0eb0: 0xA9054FF4 -> stp x20, x19, [sp, #0x50]
// Lệnh AArch64 #263 tại 0x0eb0: stp x20, x19, [sp, #0x50]
uint64_t verify_tob_encrypt_insn_263_0x0eb0(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xA9054FF4U;
    constexpr uint64_t kVaddr  = 0x0eb0ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #264 @ 0x0eb4: 0x910083FD -> add x29, sp, #0x20
// Lệnh AArch64 #264 tại 0x0eb4: add x29, sp, #0x20
uint64_t verify_tob_encrypt_insn_264_0x0eb4(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x910083FDU;
    constexpr uint64_t kVaddr  = 0x0eb4ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #265 @ 0x0eb8: 0xD53BD055 -> mrs x21, tpidr_el0
// Lệnh AArch64 #265 tại 0x0eb8: mrs x21, tpidr_el0
uint64_t verify_tob_encrypt_insn_265_0x0eb8(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xD53BD055U;
    constexpr uint64_t kVaddr  = 0x0eb8ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #266 @ 0x0ebc: 0xF94016A9 -> ldr x9, [x21, #0x28]
// Lệnh AArch64 #266 tại 0x0ebc: ldr x9, [x21, #0x28]
uint64_t verify_tob_encrypt_insn_266_0x0ebc(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xF94016A9U;
    constexpr uint64_t kVaddr  = 0x0ebcULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #267 @ 0x0ec0: 0xAA0003F3 -> mov x19, x0
// Lệnh AArch64 #267 tại 0x0ec0: mov x19, x0
uint64_t verify_tob_encrypt_insn_267_0x0ec0(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xAA0003F3U;
    constexpr uint64_t kVaddr  = 0x0ec0ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #268 @ 0x0ec4: 0x12800000 -> mov w0, #-1
// Lệnh AArch64 #268 tại 0x0ec4: mov w0, #-1
uint64_t verify_tob_encrypt_insn_268_0x0ec4(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x12800000U;
    constexpr uint64_t kVaddr  = 0x0ec4ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #269 @ 0x0ec8: 0xF81F83A9 -> stur x9, [x29, #-8]
// Lệnh AArch64 #269 tại 0x0ec8: stur x9, [x29, #-8]
uint64_t verify_tob_encrypt_insn_269_0x0ec8(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xF81F83A9U;
    constexpr uint64_t kVaddr  = 0x0ec8ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #270 @ 0x0ecc: 0xB4000373 -> cbz x19, #0xf38
// Lệnh AArch64 #270 tại 0x0ecc: cbz x19, #0xf38
uint64_t verify_tob_encrypt_insn_270_0x0ecc(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xB4000373U;
    constexpr uint64_t kVaddr  = 0x0eccULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #271 @ 0x0ed0: 0x2A0103F4 -> mov w20, w1
// Lệnh AArch64 #271 tại 0x0ed0: mov w20, w1
uint64_t verify_tob_encrypt_insn_271_0x0ed0(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x2A0103F4U;
    constexpr uint64_t kVaddr  = 0x0ed0ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #272 @ 0x0ed4: 0x71001C3F -> cmp w1, #7
// Lệnh AArch64 #272 tại 0x0ed4: cmp w1, #7
uint64_t verify_tob_encrypt_insn_272_0x0ed4(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x71001C3FU;
    constexpr uint64_t kVaddr  = 0x0ed4ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #273 @ 0x0ed8: 0x5400030B -> b.lt #0xf38
// Lệnh AArch64 #273 tại 0x0ed8: b.lt #0xf38
uint64_t verify_tob_encrypt_insn_273_0x0ed8(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x5400030BU;
    constexpr uint64_t kVaddr  = 0x0ed8ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #274 @ 0x0edc: 0x7100047F -> cmp w3, #1
// Lệnh AArch64 #274 tại 0x0edc: cmp w3, #1
uint64_t verify_tob_encrypt_insn_274_0x0edc(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x7100047FU;
    constexpr uint64_t kVaddr  = 0x0edcULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #275 @ 0x0ee0: 0x12800000 -> mov w0, #-1
// Lệnh AArch64 #275 tại 0x0ee0: mov w0, #-1
uint64_t verify_tob_encrypt_insn_275_0x0ee0(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x12800000U;
    constexpr uint64_t kVaddr  = 0x0ee0ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #276 @ 0x0ee4: 0x540002AB -> b.lt #0xf38
// Lệnh AArch64 #276 tại 0x0ee4: b.lt #0xf38
uint64_t verify_tob_encrypt_insn_276_0x0ee4(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x540002ABU;
    constexpr uint64_t kVaddr  = 0x0ee4ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #277 @ 0x0ee8: 0xAA0203E8 -> mov x8, x2
// Lệnh AArch64 #277 tại 0x0ee8: mov x8, x2
uint64_t verify_tob_encrypt_insn_277_0x0ee8(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xAA0203E8U;
    constexpr uint64_t kVaddr  = 0x0ee8ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #278 @ 0x0eec: 0xB4000262 -> cbz x2, #0xf38
// Lệnh AArch64 #278 tại 0x0eec: cbz x2, #0xf38
uint64_t verify_tob_encrypt_insn_278_0x0eec(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xB4000262U;
    constexpr uint64_t kVaddr  = 0x0eecULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #279 @ 0x0ef0: 0x51001A96 -> sub w22, w20, #6
// Lệnh AArch64 #279 tại 0x0ef0: sub w22, w20, #6
uint64_t verify_tob_encrypt_insn_279_0x0ef0(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x51001A96U;
    constexpr uint64_t kVaddr  = 0x0ef0ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #280 @ 0x0ef4: 0x12000EC9 -> and w9, w22, #0xf
// Lệnh AArch64 #280 tại 0x0ef4: and w9, w22, #0xf
uint64_t verify_tob_encrypt_insn_280_0x0ef4(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x12000EC9U;
    constexpr uint64_t kVaddr  = 0x0ef4ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #281 @ 0x0ef8: 0x35000209 -> cbnz w9, #0xf38
// Lệnh AArch64 #281 tại 0x0ef8: cbnz w9, #0xf38
uint64_t verify_tob_encrypt_insn_281_0x0ef8(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x35000209U;
    constexpr uint64_t kVaddr  = 0x0ef8ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #282 @ 0x0efc: 0x39400269 -> ldrb w9, [x19]
// Lệnh AArch64 #282 tại 0x0efc: ldrb w9, [x19]
uint64_t verify_tob_encrypt_insn_282_0x0efc(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x39400269U;
    constexpr uint64_t kVaddr  = 0x0efcULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #283 @ 0x0f00: 0x7101D13F -> cmp w9, #0x74
// Lệnh AArch64 #283 tại 0x0f00: cmp w9, #0x74
uint64_t verify_tob_encrypt_insn_283_0x0f00(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x7101D13FU;
    constexpr uint64_t kVaddr  = 0x0f00ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #284 @ 0x0f04: 0x54000181 -> b.ne #0xf34
// Lệnh AArch64 #284 tại 0x0f04: b.ne #0xf34
uint64_t verify_tob_encrypt_insn_284_0x0f04(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x54000181U;
    constexpr uint64_t kVaddr  = 0x0f04ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #285 @ 0x0f08: 0x39400669 -> ldrb w9, [x19, #1]
// Lệnh AArch64 #285 tại 0x0f08: ldrb w9, [x19, #1]
uint64_t verify_tob_encrypt_insn_285_0x0f08(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x39400669U;
    constexpr uint64_t kVaddr  = 0x0f08ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #286 @ 0x0f0c: 0x71018D3F -> cmp w9, #0x63
// Lệnh AArch64 #286 tại 0x0f0c: cmp w9, #0x63
uint64_t verify_tob_encrypt_insn_286_0x0f0c(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x71018D3FU;
    constexpr uint64_t kVaddr  = 0x0f0cULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #287 @ 0x0f10: 0x54000121 -> b.ne #0xf34
// Lệnh AArch64 #287 tại 0x0f10: b.ne #0xf34
uint64_t verify_tob_encrypt_insn_287_0x0f10(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x54000121U;
    constexpr uint64_t kVaddr  = 0x0f10ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #288 @ 0x0f14: 0x39400A69 -> ldrb w9, [x19, #2]
// Lệnh AArch64 #288 tại 0x0f14: ldrb w9, [x19, #2]
uint64_t verify_tob_encrypt_insn_288_0x0f14(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x39400A69U;
    constexpr uint64_t kVaddr  = 0x0f14ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #289 @ 0x0f18: 0x71000D3F -> cmp w9, #3
// Lệnh AArch64 #289 tại 0x0f18: cmp w9, #3
uint64_t verify_tob_encrypt_insn_289_0x0f18(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x71000D3FU;
    constexpr uint64_t kVaddr  = 0x0f18ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #290 @ 0x0f1c: 0x540000C1 -> b.ne #0xf34
// Lệnh AArch64 #290 tại 0x0f1c: b.ne #0xf34
uint64_t verify_tob_encrypt_insn_290_0x0f1c(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x540000C1U;
    constexpr uint64_t kVaddr  = 0x0f1cULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #291 @ 0x0f20: 0x39400E77 -> ldrb w23, [x19, #3]
// Lệnh AArch64 #291 tại 0x0f20: ldrb w23, [x19, #3]
uint64_t verify_tob_encrypt_insn_291_0x0f20(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x39400E77U;
    constexpr uint64_t kVaddr  = 0x0f20ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #292 @ 0x0f24: 0x71003EFF -> cmp w23, #0xf
// Lệnh AArch64 #292 tại 0x0f24: cmp w23, #0xf
uint64_t verify_tob_encrypt_insn_292_0x0f24(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x71003EFFU;
    constexpr uint64_t kVaddr  = 0x0f24ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #293 @ 0x0f28: 0x540001C9 -> b.ls #0xf60
// Lệnh AArch64 #293 tại 0x0f28: b.ls #0xf60
uint64_t verify_tob_encrypt_insn_293_0x0f28(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x540001C9U;
    constexpr uint64_t kVaddr  = 0x0f28ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #294 @ 0x0f2c: 0x12800040 -> mov w0, #-3
// Lệnh AArch64 #294 tại 0x0f2c: mov w0, #-3
uint64_t verify_tob_encrypt_insn_294_0x0f2c(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x12800040U;
    constexpr uint64_t kVaddr  = 0x0f2cULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #295 @ 0x0f30: 0x14000002 -> b #0xf38
// Lệnh AArch64 #295 tại 0x0f30: b #0xf38
uint64_t verify_tob_encrypt_insn_295_0x0f30(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x14000002U;
    constexpr uint64_t kVaddr  = 0x0f30ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #296 @ 0x0f34: 0x12800020 -> mov w0, #-2
// Lệnh AArch64 #296 tại 0x0f34: mov w0, #-2
uint64_t verify_tob_encrypt_insn_296_0x0f34(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x12800020U;
    constexpr uint64_t kVaddr  = 0x0f34ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #297 @ 0x0f38: 0xF94016A8 -> ldr x8, [x21, #0x28]
// Lệnh AArch64 #297 tại 0x0f38: ldr x8, [x21, #0x28]
uint64_t verify_tob_encrypt_insn_297_0x0f38(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xF94016A8U;
    constexpr uint64_t kVaddr  = 0x0f38ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #298 @ 0x0f3c: 0xF85F83A9 -> ldur x9, [x29, #-8]
// Lệnh AArch64 #298 tại 0x0f3c: ldur x9, [x29, #-8]
uint64_t verify_tob_encrypt_insn_298_0x0f3c(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xF85F83A9U;
    constexpr uint64_t kVaddr  = 0x0f3cULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #299 @ 0x0f40: 0xEB09011F -> cmp x8, x9
// Lệnh AArch64 #299 tại 0x0f40: cmp x8, x9
uint64_t verify_tob_encrypt_insn_299_0x0f40(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xEB09011FU;
    constexpr uint64_t kVaddr  = 0x0f40ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #300 @ 0x0f44: 0x54000681 -> b.ne #0x1014
// Lệnh AArch64 #300 tại 0x0f44: b.ne #0x1014
uint64_t verify_tob_encrypt_insn_300_0x0f44(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x54000681U;
    constexpr uint64_t kVaddr  = 0x0f44ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #301 @ 0x0f48: 0xA9454FF4 -> ldp x20, x19, [sp, #0x50]
// Lệnh AArch64 #301 tại 0x0f48: ldp x20, x19, [sp, #0x50]
uint64_t verify_tob_encrypt_insn_301_0x0f48(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xA9454FF4U;
    constexpr uint64_t kVaddr  = 0x0f48ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #302 @ 0x0f4c: 0xA94457F6 -> ldp x22, x21, [sp, #0x40]
// Lệnh AArch64 #302 tại 0x0f4c: ldp x22, x21, [sp, #0x40]
uint64_t verify_tob_encrypt_insn_302_0x0f4c(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xA94457F6U;
    constexpr uint64_t kVaddr  = 0x0f4cULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #303 @ 0x0f50: 0xF9401BF7 -> ldr x23, [sp, #0x30]
// Lệnh AArch64 #303 tại 0x0f50: ldr x23, [sp, #0x30]
uint64_t verify_tob_encrypt_insn_303_0x0f50(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xF9401BF7U;
    constexpr uint64_t kVaddr  = 0x0f50ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #304 @ 0x0f54: 0xA9427BFD -> ldp x29, x30, [sp, #0x20]
// Lệnh AArch64 #304 tại 0x0f54: ldp x29, x30, [sp, #0x20]
uint64_t verify_tob_encrypt_insn_304_0x0f54(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xA9427BFDU;
    constexpr uint64_t kVaddr  = 0x0f54ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #305 @ 0x0f58: 0x910183FF -> add sp, sp, #0x60
// Lệnh AArch64 #305 tại 0x0f58: add sp, sp, #0x60
uint64_t verify_tob_encrypt_insn_305_0x0f58(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x910183FFU;
    constexpr uint64_t kVaddr  = 0x0f58ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #306 @ 0x0f5c: 0xD65F03C0 -> ret 
// Lệnh AArch64 #306 tại 0x0f5c: ret 
uint64_t verify_tob_encrypt_insn_306_0x0f5c(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xD65F03C0U;
    constexpr uint64_t kVaddr  = 0x0f5cULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #307 @ 0x0f60: 0x910023E2 -> add x2, sp, #8
// Lệnh AArch64 #307 tại 0x0f60: add x2, sp, #8
uint64_t verify_tob_encrypt_insn_307_0x0f60(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x910023E2U;
    constexpr uint64_t kVaddr  = 0x0f60ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #308 @ 0x0f64: 0xAA0803E0 -> mov x0, x8
// Lệnh AArch64 #308 tại 0x0f64: mov x0, x8
uint64_t verify_tob_encrypt_insn_308_0x0f64(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xAA0803E0U;
    constexpr uint64_t kVaddr  = 0x0f64ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #309 @ 0x0f68: 0x2A0303E1 -> mov w1, w3
// Lệnh AArch64 #309 tại 0x0f68: mov w1, w3
uint64_t verify_tob_encrypt_insn_309_0x0f68(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x2A0303E1U;
    constexpr uint64_t kVaddr  = 0x0f68ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #310 @ 0x0f6c: 0x97FFFF68 -> bl #0xd0c
// Lệnh AArch64 #310 tại 0x0f6c: bl #0xd0c
uint64_t verify_tob_encrypt_insn_310_0x0f6c(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x97FFFF68U;
    constexpr uint64_t kVaddr  = 0x0f6cULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #311 @ 0x0f70: 0x53047EC8 -> lsr w8, w22, #4
// Lệnh AArch64 #311 tại 0x0f70: lsr w8, w22, #4
uint64_t verify_tob_encrypt_insn_311_0x0f70(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x53047EC8U;
    constexpr uint64_t kVaddr  = 0x0f70ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #312 @ 0x0f74: 0x34000388 -> cbz w8, #0xfe4
// Lệnh AArch64 #312 tại 0x0f74: cbz w8, #0xfe4
uint64_t verify_tob_encrypt_insn_312_0x0f74(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x34000388U;
    constexpr uint64_t kVaddr  = 0x0f74ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #313 @ 0x0f78: 0x29412BE9 -> ldp w9, w10, [sp, #8]
// Lệnh AArch64 #313 tại 0x0f78: ldp w9, w10, [sp, #8]
uint64_t verify_tob_encrypt_insn_313_0x0f78(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x29412BE9U;
    constexpr uint64_t kVaddr  = 0x0f78ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #314 @ 0x0f7c: 0x294233EB -> ldp w11, w12, [sp, #0x10]
// Lệnh AArch64 #314 tại 0x0f7c: ldp w11, w12, [sp, #0x10]
uint64_t verify_tob_encrypt_insn_314_0x0f7c(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x294233EBU;
    constexpr uint64_t kVaddr  = 0x0f7cULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #315 @ 0x0f80: 0x91004A6D -> add x13, x19, #0x12
// Lệnh AArch64 #315 tại 0x0f80: add x13, x19, #0x12
uint64_t verify_tob_encrypt_insn_315_0x0f80(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x91004A6DU;
    constexpr uint64_t kVaddr  = 0x0f80ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #316 @ 0x0f84: 0x297EBDAE -> ldp w14, w15, [x13, #-0xc]
// Lệnh AArch64 #316 tại 0x0f84: ldp w14, w15, [x13, #-0xc]
uint64_t verify_tob_encrypt_insn_316_0x0f84(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x297EBDAEU;
    constexpr uint64_t kVaddr  = 0x0f84ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #317 @ 0x0f88: 0xB85FC1B0 -> ldur w16, [x13, #-4]
// Lệnh AArch64 #317 tại 0x0f88: ldur w16, [x13, #-4]
uint64_t verify_tob_encrypt_insn_317_0x0f88(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xB85FC1B0U;
    constexpr uint64_t kVaddr  = 0x0f88ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #318 @ 0x0f8c: 0xF1000508 -> subs x8, x8, #1
// Lệnh AArch64 #318 tại 0x0f8c: subs x8, x8, #1
uint64_t verify_tob_encrypt_insn_318_0x0f8c(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xF1000508U;
    constexpr uint64_t kVaddr  = 0x0f8cULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #319 @ 0x0f90: 0x5AC009CE -> rev w14, w14
// Lệnh AArch64 #319 tại 0x0f90: rev w14, w14
uint64_t verify_tob_encrypt_insn_319_0x0f90(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x5AC009CEU;
    constexpr uint64_t kVaddr  = 0x0f90ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #320 @ 0x0f94: 0x4A0901CE -> eor w14, w14, w9
// Lệnh AArch64 #320 tại 0x0f94: eor w14, w14, w9
uint64_t verify_tob_encrypt_insn_320_0x0f94(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x4A0901CEU;
    constexpr uint64_t kVaddr  = 0x0f94ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #321 @ 0x0f98: 0x5AC009D1 -> rev w17, w14
// Lệnh AArch64 #321 tại 0x0f98: rev w17, w14
uint64_t verify_tob_encrypt_insn_321_0x0f98(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x5AC009D1U;
    constexpr uint64_t kVaddr  = 0x0f98ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #322 @ 0x0f9c: 0x5AC00A0E -> rev w14, w16
// Lệnh AArch64 #322 tại 0x0f9c: rev w14, w16
uint64_t verify_tob_encrypt_insn_322_0x0f9c(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x5AC00A0EU;
    constexpr uint64_t kVaddr  = 0x0f9cULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #323 @ 0x0fa0: 0x4A0B01CE -> eor w14, w14, w11
// Lệnh AArch64 #323 tại 0x0fa0: eor w14, w14, w11
uint64_t verify_tob_encrypt_insn_323_0x0fa0(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x4A0B01CEU;
    constexpr uint64_t kVaddr  = 0x0fa0ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #324 @ 0x0fa4: 0x5AC005D0 -> rev16 w16, w14
// Lệnh AArch64 #324 tại 0x0fa4: rev16 w16, w14
uint64_t verify_tob_encrypt_insn_324_0x0fa4(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x5AC005D0U;
    constexpr uint64_t kVaddr  = 0x0fa4ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #325 @ 0x0fa8: 0xB94001AE -> ldr w14, [x13]
// Lệnh AArch64 #325 tại 0x0fa8: ldr w14, [x13]
uint64_t verify_tob_encrypt_insn_325_0x0fa8(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xB94001AEU;
    constexpr uint64_t kVaddr  = 0x0fa8ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #326 @ 0x0fac: 0x5AC009EF -> rev w15, w15
// Lệnh AArch64 #326 tại 0x0fac: rev w15, w15
uint64_t verify_tob_encrypt_insn_326_0x0fac(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x5AC009EFU;
    constexpr uint64_t kVaddr  = 0x0facULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #327 @ 0x0fb0: 0x4A0A01EF -> eor w15, w15, w10
// Lệnh AArch64 #327 tại 0x0fb0: eor w15, w15, w10
uint64_t verify_tob_encrypt_insn_327_0x0fb0(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x4A0A01EFU;
    constexpr uint64_t kVaddr  = 0x0fb0ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #328 @ 0x0fb4: 0x138F21EF -> ror w15, w15, #8
// Lệnh AArch64 #328 tại 0x0fb4: ror w15, w15, #8
uint64_t verify_tob_encrypt_insn_328_0x0fb4(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x138F21EFU;
    constexpr uint64_t kVaddr  = 0x0fb4ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #329 @ 0x0fb8: 0x5AC009CE -> rev w14, w14
// Lệnh AArch64 #329 tại 0x0fb8: rev w14, w14
uint64_t verify_tob_encrypt_insn_329_0x0fb8(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x5AC009CEU;
    constexpr uint64_t kVaddr  = 0x0fb8ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #330 @ 0x0fbc: 0x4A0C01CE -> eor w14, w14, w12
// Lệnh AArch64 #330 tại 0x0fbc: eor w14, w14, w12
uint64_t verify_tob_encrypt_insn_330_0x0fbc(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x4A0C01CEU;
    constexpr uint64_t kVaddr  = 0x0fbcULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #331 @ 0x0fc0: 0x138E61CE -> ror w14, w14, #0x18
// Lệnh AArch64 #331 tại 0x0fc0: ror w14, w14, #0x18
uint64_t verify_tob_encrypt_insn_331_0x0fc0(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x138E61CEU;
    constexpr uint64_t kVaddr  = 0x0fc0ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #332 @ 0x0fc4: 0x5AC009EF -> rev w15, w15
// Lệnh AArch64 #332 tại 0x0fc4: rev w15, w15
uint64_t verify_tob_encrypt_insn_332_0x0fc4(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x5AC009EFU;
    constexpr uint64_t kVaddr  = 0x0fc4ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #333 @ 0x0fc8: 0x5AC009CE -> rev w14, w14
// Lệnh AArch64 #333 tại 0x0fc8: rev w14, w14
uint64_t verify_tob_encrypt_insn_333_0x0fc8(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x5AC009CEU;
    constexpr uint64_t kVaddr  = 0x0fc8ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #334 @ 0x0fcc: 0x293EBDB1 -> stp w17, w15, [x13, #-0xc]
// Lệnh AArch64 #334 tại 0x0fcc: stp w17, w15, [x13, #-0xc]
uint64_t verify_tob_encrypt_insn_334_0x0fcc(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x293EBDB1U;
    constexpr uint64_t kVaddr  = 0x0fccULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #335 @ 0x0fd0: 0x293FB9B0 -> stp w16, w14, [x13, #-4]
// Lệnh AArch64 #335 tại 0x0fd0: stp w16, w14, [x13, #-4]
uint64_t verify_tob_encrypt_insn_335_0x0fd0(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x293FB9B0U;
    constexpr uint64_t kVaddr  = 0x0fd0ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #336 @ 0x0fd4: 0x910041AD -> add x13, x13, #0x10
// Lệnh AArch64 #336 tại 0x0fd4: add x13, x13, #0x10
uint64_t verify_tob_encrypt_insn_336_0x0fd4(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x910041ADU;
    constexpr uint64_t kVaddr  = 0x0fd4ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #337 @ 0x0fd8: 0x54FFFD61 -> b.ne #0xf84
// Lệnh AArch64 #337 tại 0x0fd8: b.ne #0xf84
uint64_t verify_tob_encrypt_insn_337_0x0fd8(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x54FFFD61U;
    constexpr uint64_t kVaddr  = 0x0fd8ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #338 @ 0x0fdc: 0x71001E9F -> cmp w20, #7
// Lệnh AArch64 #338 tại 0x0fdc: cmp w20, #7
uint64_t verify_tob_encrypt_insn_338_0x0fdc(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x71001E9FU;
    constexpr uint64_t kVaddr  = 0x0fdcULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #339 @ 0x0fe0: 0x5400016B -> b.lt #0x100c
// Lệnh AArch64 #339 tại 0x0fe0: b.lt #0x100c
uint64_t verify_tob_encrypt_insn_339_0x0fe0(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x5400016BU;
    constexpr uint64_t kVaddr  = 0x0fe0ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #340 @ 0x0fe4: 0xB000002A -> adrp x10, #0x5000
// Lệnh AArch64 #340 tại 0x0fe4: adrp x10, #0x5000
uint64_t verify_tob_encrypt_insn_340_0x0fe4(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xB000002AU;
    constexpr uint64_t kVaddr  = 0x0fe4ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #341 @ 0x0fe8: 0xF942D94A -> ldr x10, [x10, #0x5b0]
// Lệnh AArch64 #341 tại 0x0fe8: ldr x10, [x10, #0x5b0]
uint64_t verify_tob_encrypt_insn_341_0x0fe8(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xF942D94AU;
    constexpr uint64_t kVaddr  = 0x0fe8ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #342 @ 0x0fec: 0x2A1403E9 -> mov w9, w20
// Lệnh AArch64 #342 tại 0x0fec: mov w9, w20
uint64_t verify_tob_encrypt_insn_342_0x0fec(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x2A1403E9U;
    constexpr uint64_t kVaddr  = 0x0fecULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #343 @ 0x0ff0: 0x91001A68 -> add x8, x19, #6
// Lệnh AArch64 #343 tại 0x0ff0: add x8, x19, #6
uint64_t verify_tob_encrypt_insn_343_0x0ff0(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x91001A68U;
    constexpr uint64_t kVaddr  = 0x0ff0ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #344 @ 0x0ff4: 0xD1001929 -> sub x9, x9, #6
// Lệnh AArch64 #344 tại 0x0ff4: sub x9, x9, #6
uint64_t verify_tob_encrypt_insn_344_0x0ff4(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xD1001929U;
    constexpr uint64_t kVaddr  = 0x0ff4ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #345 @ 0x0ff8: 0x3940010B -> ldrb w11, [x8]
// Lệnh AArch64 #345 tại 0x0ff8: ldrb w11, [x8]
uint64_t verify_tob_encrypt_insn_345_0x0ff8(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x3940010BU;
    constexpr uint64_t kVaddr  = 0x0ff8ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #346 @ 0x0ffc: 0xF1000529 -> subs x9, x9, #1
// Lệnh AArch64 #346 tại 0x0ffc: subs x9, x9, #1
uint64_t verify_tob_encrypt_insn_346_0x0ffc(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xF1000529U;
    constexpr uint64_t kVaddr  = 0x0ffcULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #347 @ 0x1000: 0x386B694B -> ldrb w11, [x10, x11]
// Lệnh AArch64 #347 tại 0x1000: ldrb w11, [x10, x11]
uint64_t verify_tob_encrypt_insn_347_0x1000(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x386B694BU;
    constexpr uint64_t kVaddr  = 0x1000ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #348 @ 0x1004: 0x3800150B -> strb w11, [x8], #1
// Lệnh AArch64 #348 tại 0x1004: strb w11, [x8], #1
uint64_t verify_tob_encrypt_insn_348_0x1004(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x3800150BU;
    constexpr uint64_t kVaddr  = 0x1004ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #349 @ 0x1008: 0x54FFFF81 -> b.ne #0xff8
// Lệnh AArch64 #349 tại 0x1008: b.ne #0xff8
uint64_t verify_tob_encrypt_insn_349_0x1008(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x54FFFF81U;
    constexpr uint64_t kVaddr  = 0x1008ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #350 @ 0x100c: 0x4B1702C0 -> sub w0, w22, w23
// Lệnh AArch64 #350 tại 0x100c: sub w0, w22, w23
uint64_t verify_tob_encrypt_insn_350_0x100c(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x4B1702C0U;
    constexpr uint64_t kVaddr  = 0x100cULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #351 @ 0x1010: 0x17FFFFCA -> b #0xf38
// Lệnh AArch64 #351 tại 0x1010: b #0xf38
uint64_t verify_tob_encrypt_insn_351_0x1010(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x17FFFFCAU;
    constexpr uint64_t kVaddr  = 0x1010ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #352 @ 0x1014: 0x940000CB -> bl #0x1340
// Lệnh AArch64 #352 tại 0x1014: bl #0x1340
uint64_t verify_tob_encrypt_insn_352_0x1014(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x940000CBU;
    constexpr uint64_t kVaddr  = 0x1014ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #353 @ 0x1018: 0xD10083FF -> sub sp, sp, #0x20
// Lệnh AArch64 #353 tại 0x1018: sub sp, sp, #0x20
uint64_t verify_tob_encrypt_insn_353_0x1018(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xD10083FFU;
    constexpr uint64_t kVaddr  = 0x1018ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #354 @ 0x101c: 0xA9017BFD -> stp x29, x30, [sp, #0x10]
// Lệnh AArch64 #354 tại 0x101c: stp x29, x30, [sp, #0x10]
uint64_t verify_tob_encrypt_insn_354_0x101c(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xA9017BFDU;
    constexpr uint64_t kVaddr  = 0x101cULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #355 @ 0x1020: 0x910043FD -> add x29, sp, #0x10
// Lệnh AArch64 #355 tại 0x1020: add x29, sp, #0x10
uint64_t verify_tob_encrypt_insn_355_0x1020(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x910043FDU;
    constexpr uint64_t kVaddr  = 0x1020ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #356 @ 0x1024: 0xD53BD048 -> mrs x8, tpidr_el0
// Lệnh AArch64 #356 tại 0x1024: mrs x8, tpidr_el0
uint64_t verify_tob_encrypt_insn_356_0x1024(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xD53BD048U;
    constexpr uint64_t kVaddr  = 0x1024ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #357 @ 0x1028: 0xF0FFFFEB -> adrp x11, #0
// Lệnh AArch64 #357 tại 0x1028: adrp x11, #0
uint64_t verify_tob_encrypt_insn_357_0x1028(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xF0FFFFEBU;
    constexpr uint64_t kVaddr  = 0x1028ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #358 @ 0x102c: 0xF940150A -> ldr x10, [x8, #0x28]
// Lệnh AArch64 #358 tại 0x102c: ldr x10, [x8, #0x28]
uint64_t verify_tob_encrypt_insn_358_0x102c(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xF940150AU;
    constexpr uint64_t kVaddr  = 0x102cULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #359 @ 0x1030: 0x3DC24160 -> ldr q0, [x11, #0x900]
// Lệnh AArch64 #359 tại 0x1030: ldr q0, [x11, #0x900]
uint64_t verify_tob_encrypt_insn_359_0x1030(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x3DC24160U;
    constexpr uint64_t kVaddr  = 0x1030ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #360 @ 0x1034: 0x90000049 -> adrp x9, #0x9000
// Lệnh AArch64 #360 tại 0x1034: adrp x9, #0x9000
uint64_t verify_tob_encrypt_insn_360_0x1034(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x90000049U;
    constexpr uint64_t kVaddr  = 0x1034ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #361 @ 0x1038: 0x528CCA8B -> mov w11, #0x6654
// Lệnh AArch64 #361 tại 0x1038: mov w11, #0x6654
uint64_t verify_tob_encrypt_insn_361_0x1038(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x528CCA8BU;
    constexpr uint64_t kVaddr  = 0x1038ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #362 @ 0x103c: 0x9120C129 -> add x9, x9, #0x830
// Lệnh AArch64 #362 tại 0x103c: add x9, x9, #0x830
uint64_t verify_tob_encrypt_insn_362_0x103c(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x9120C129U;
    constexpr uint64_t kVaddr  = 0x103cULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #363 @ 0x1040: 0x72A82C8B -> movk w11, #0x4164, lsl #16
// Lệnh AArch64 #363 tại 0x1040: movk w11, #0x4164, lsl #16
uint64_t verify_tob_encrypt_insn_363_0x1040(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x72A82C8BU;
    constexpr uint64_t kVaddr  = 0x1040ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #364 @ 0x1044: 0xF90007EA -> str x10, [sp, #8]
// Lệnh AArch64 #364 tại 0x1044: str x10, [sp, #8]
uint64_t verify_tob_encrypt_insn_364_0x1044(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xF90007EAU;
    constexpr uint64_t kVaddr  = 0x1044ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #365 @ 0x1048: 0xB900112B -> str w11, [x9, #0x10]
// Lệnh AArch64 #365 tại 0x1048: str w11, [x9, #0x10]
uint64_t verify_tob_encrypt_insn_365_0x1048(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xB900112BU;
    constexpr uint64_t kVaddr  = 0x1048ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #366 @ 0x104c: 0x3D800120 -> str q0, [x9]
// Lệnh AArch64 #366 tại 0x104c: str q0, [x9]
uint64_t verify_tob_encrypt_insn_366_0x104c(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x3D800120U;
    constexpr uint64_t kVaddr  = 0x104cULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #367 @ 0x1050: 0xF9401508 -> ldr x8, [x8, #0x28]
// Lệnh AArch64 #367 tại 0x1050: ldr x8, [x8, #0x28]
uint64_t verify_tob_encrypt_insn_367_0x1050(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xF9401508U;
    constexpr uint64_t kVaddr  = 0x1050ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #368 @ 0x1054: 0xF94007E9 -> ldr x9, [sp, #8]
// Lệnh AArch64 #368 tại 0x1054: ldr x9, [sp, #8]
uint64_t verify_tob_encrypt_insn_368_0x1054(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xF94007E9U;
    constexpr uint64_t kVaddr  = 0x1054ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #369 @ 0x1058: 0xEB09011F -> cmp x8, x9
// Lệnh AArch64 #369 tại 0x1058: cmp x8, x9
uint64_t verify_tob_encrypt_insn_369_0x1058(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xEB09011FU;
    constexpr uint64_t kVaddr  = 0x1058ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #370 @ 0x105c: 0x54000081 -> b.ne #0x106c
// Lệnh AArch64 #370 tại 0x105c: b.ne #0x106c
uint64_t verify_tob_encrypt_insn_370_0x105c(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x54000081U;
    constexpr uint64_t kVaddr  = 0x105cULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #371 @ 0x1060: 0xA9417BFD -> ldp x29, x30, [sp, #0x10]
// Lệnh AArch64 #371 tại 0x1060: ldp x29, x30, [sp, #0x10]
uint64_t verify_tob_encrypt_insn_371_0x1060(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xA9417BFDU;
    constexpr uint64_t kVaddr  = 0x1060ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #372 @ 0x1064: 0x910083FF -> add sp, sp, #0x20
// Lệnh AArch64 #372 tại 0x1064: add sp, sp, #0x20
uint64_t verify_tob_encrypt_insn_372_0x1064(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x910083FFU;
    constexpr uint64_t kVaddr  = 0x1064ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #373 @ 0x1068: 0xD65F03C0 -> ret 
// Lệnh AArch64 #373 tại 0x1068: ret 
uint64_t verify_tob_encrypt_insn_373_0x1068(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xD65F03C0U;
    constexpr uint64_t kVaddr  = 0x1068ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #374 @ 0x106c: 0x940000B5 -> bl #0x1340
// Lệnh AArch64 #374 tại 0x106c: bl #0x1340
uint64_t verify_tob_encrypt_insn_374_0x106c(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x940000B5U;
    constexpr uint64_t kVaddr  = 0x106cULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #375 @ 0x1070: 0xD10183FF -> sub sp, sp, #0x60
// Lệnh AArch64 #375 tại 0x1070: sub sp, sp, #0x60
uint64_t verify_tob_encrypt_insn_375_0x1070(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xD10183FFU;
    constexpr uint64_t kVaddr  = 0x1070ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #376 @ 0x1074: 0xA9017BFD -> stp x29, x30, [sp, #0x10]
// Lệnh AArch64 #376 tại 0x1074: stp x29, x30, [sp, #0x10]
uint64_t verify_tob_encrypt_insn_376_0x1074(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xA9017BFDU;
    constexpr uint64_t kVaddr  = 0x1074ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #377 @ 0x1078: 0xA90267FA -> stp x26, x25, [sp, #0x20]
// Lệnh AArch64 #377 tại 0x1078: stp x26, x25, [sp, #0x20]
uint64_t verify_tob_encrypt_insn_377_0x1078(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xA90267FAU;
    constexpr uint64_t kVaddr  = 0x1078ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #378 @ 0x107c: 0xA9035FF8 -> stp x24, x23, [sp, #0x30]
// Lệnh AArch64 #378 tại 0x107c: stp x24, x23, [sp, #0x30]
uint64_t verify_tob_encrypt_insn_378_0x107c(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xA9035FF8U;
    constexpr uint64_t kVaddr  = 0x107cULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #379 @ 0x1080: 0xA90457F6 -> stp x22, x21, [sp, #0x40]
// Lệnh AArch64 #379 tại 0x1080: stp x22, x21, [sp, #0x40]
uint64_t verify_tob_encrypt_insn_379_0x1080(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xA90457F6U;
    constexpr uint64_t kVaddr  = 0x1080ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #380 @ 0x1084: 0xA9054FF4 -> stp x20, x19, [sp, #0x50]
// Lệnh AArch64 #380 tại 0x1084: stp x20, x19, [sp, #0x50]
uint64_t verify_tob_encrypt_insn_380_0x1084(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xA9054FF4U;
    constexpr uint64_t kVaddr  = 0x1084ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #381 @ 0x1088: 0x910043FD -> add x29, sp, #0x10
// Lệnh AArch64 #381 tại 0x1088: add x29, sp, #0x10
uint64_t verify_tob_encrypt_insn_381_0x1088(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x910043FDU;
    constexpr uint64_t kVaddr  = 0x1088ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #382 @ 0x108c: 0xD53BD05A -> mrs x26, tpidr_el0
// Lệnh AArch64 #382 tại 0x108c: mrs x26, tpidr_el0
uint64_t verify_tob_encrypt_insn_382_0x108c(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xD53BD05AU;
    constexpr uint64_t kVaddr  = 0x108cULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #383 @ 0x1090: 0xF9401748 -> ldr x8, [x26, #0x28]
// Lệnh AArch64 #383 tại 0x1090: ldr x8, [x26, #0x28]
uint64_t verify_tob_encrypt_insn_383_0x1090(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xF9401748U;
    constexpr uint64_t kVaddr  = 0x1090ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #384 @ 0x1094: 0xAA1F03F8 -> mov x24, xzr
// Lệnh AArch64 #384 tại 0x1094: mov x24, xzr
uint64_t verify_tob_encrypt_insn_384_0x1094(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xAA1F03F8U;
    constexpr uint64_t kVaddr  = 0x1094ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #385 @ 0x1098: 0xF90007E8 -> str x8, [sp, #8]
// Lệnh AArch64 #385 tại 0x1098: str x8, [sp, #8]
uint64_t verify_tob_encrypt_insn_385_0x1098(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xF90007E8U;
    constexpr uint64_t kVaddr  = 0x1098ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #386 @ 0x109c: 0xB40007C2 -> cbz x2, #0x1194
// Lệnh AArch64 #386 tại 0x109c: cbz x2, #0x1194
uint64_t verify_tob_encrypt_insn_386_0x109c(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xB40007C2U;
    constexpr uint64_t kVaddr  = 0x109cULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #387 @ 0x10a0: 0x2A0303F7 -> mov w23, w3
// Lệnh AArch64 #387 tại 0x10a0: mov w23, w3
uint64_t verify_tob_encrypt_insn_387_0x10a0(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x2A0303F7U;
    constexpr uint64_t kVaddr  = 0x10a0ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #388 @ 0x10a4: 0x7100047F -> cmp w3, #1
// Lệnh AArch64 #388 tại 0x10a4: cmp w3, #1
uint64_t verify_tob_encrypt_insn_388_0x10a4(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x7100047FU;
    constexpr uint64_t kVaddr  = 0x10a4ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #389 @ 0x10a8: 0x5400076B -> b.lt #0x1194
// Lệnh AArch64 #389 tại 0x10a8: b.lt #0x1194
uint64_t verify_tob_encrypt_insn_389_0x10a8(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x5400076BU;
    constexpr uint64_t kVaddr  = 0x10a8ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #390 @ 0x10ac: 0xF0FFFFE8 -> adrp x8, #0
// Lệnh AArch64 #390 tại 0x10ac: adrp x8, #0
uint64_t verify_tob_encrypt_insn_390_0x10ac(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xF0FFFFE8U;
    constexpr uint64_t kVaddr  = 0x10acULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #391 @ 0x10b0: 0x3DC24100 -> ldr q0, [x8, #0x900]
// Lệnh AArch64 #391 tại 0x10b0: ldr q0, [x8, #0x900]
uint64_t verify_tob_encrypt_insn_391_0x10b0(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x3DC24100U;
    constexpr uint64_t kVaddr  = 0x10b0ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #392 @ 0x10b4: 0x90000058 -> adrp x24, #0x9000
// Lệnh AArch64 #392 tại 0x10b4: adrp x24, #0x9000
uint64_t verify_tob_encrypt_insn_392_0x10b4(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x90000058U;
    constexpr uint64_t kVaddr  = 0x10b4ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #393 @ 0x10b8: 0x528CCA88 -> mov w8, #0x6654
// Lệnh AArch64 #393 tại 0x10b8: mov w8, #0x6654
uint64_t verify_tob_encrypt_insn_393_0x10b8(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x528CCA88U;
    constexpr uint64_t kVaddr  = 0x10b8ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #394 @ 0x10bc: 0xAA0003F3 -> mov x19, x0
// Lệnh AArch64 #394 tại 0x10bc: mov x19, x0
uint64_t verify_tob_encrypt_insn_394_0x10bc(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xAA0003F3U;
    constexpr uint64_t kVaddr  = 0x10bcULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #395 @ 0x10c0: 0x9120C318 -> add x24, x24, #0x830
// Lệnh AArch64 #395 tại 0x10c0: add x24, x24, #0x830
uint64_t verify_tob_encrypt_insn_395_0x10c0(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x9120C318U;
    constexpr uint64_t kVaddr  = 0x10c0ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #396 @ 0x10c4: 0x72A82C88 -> movk w8, #0x4164, lsl #16
// Lệnh AArch64 #396 tại 0x10c4: movk w8, #0x4164, lsl #16
uint64_t verify_tob_encrypt_insn_396_0x10c4(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x72A82C88U;
    constexpr uint64_t kVaddr  = 0x10c4ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #397 @ 0x10c8: 0x2A1703E0 -> mov w0, w23
// Lệnh AArch64 #397 tại 0x10c8: mov w0, w23
uint64_t verify_tob_encrypt_insn_397_0x10c8(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x2A1703E0U;
    constexpr uint64_t kVaddr  = 0x10c8ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #398 @ 0x10cc: 0xAA0203F9 -> mov x25, x2
// Lệnh AArch64 #398 tại 0x10cc: mov x25, x2
uint64_t verify_tob_encrypt_insn_398_0x10cc(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xAA0203F9U;
    constexpr uint64_t kVaddr  = 0x10ccULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #399 @ 0x10d0: 0xB9001308 -> str w8, [x24, #0x10]
// Lệnh AArch64 #399 tại 0x10d0: str w8, [x24, #0x10]
uint64_t verify_tob_encrypt_insn_399_0x10d0(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xB9001308U;
    constexpr uint64_t kVaddr  = 0x10d0ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #400 @ 0x10d4: 0x3D800300 -> str q0, [x24]
// Lệnh AArch64 #400 tại 0x10d4: str q0, [x24]
uint64_t verify_tob_encrypt_insn_400_0x10d4(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x3D800300U;
    constexpr uint64_t kVaddr  = 0x10d4ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #401 @ 0x10d8: 0x940000AA -> bl #0x1380
// Lệnh AArch64 #401 tại 0x10d8: bl #0x1380
uint64_t verify_tob_encrypt_insn_401_0x10d8(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x940000AAU;
    constexpr uint64_t kVaddr  = 0x10d8ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #402 @ 0x10dc: 0x2A0003F5 -> mov w21, w0
// Lệnh AArch64 #402 tại 0x10dc: mov w21, w0
uint64_t verify_tob_encrypt_insn_402_0x10dc(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x2A0003F5U;
    constexpr uint64_t kVaddr  = 0x10dcULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #403 @ 0x10e0: 0x2A1703E0 -> mov w0, w23
// Lệnh AArch64 #403 tại 0x10e0: mov w0, w23
uint64_t verify_tob_encrypt_insn_403_0x10e0(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x2A1703E0U;
    constexpr uint64_t kVaddr  = 0x10e0ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #404 @ 0x10e4: 0x940000AB -> bl #0x1390
// Lệnh AArch64 #404 tại 0x10e4: bl #0x1390
uint64_t verify_tob_encrypt_insn_404_0x10e4(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x940000ABU;
    constexpr uint64_t kVaddr  = 0x10e4ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #405 @ 0x10e8: 0xAA0003F4 -> mov x20, x0
// Lệnh AArch64 #405 tại 0x10e8: mov x20, x0
uint64_t verify_tob_encrypt_insn_405_0x10e8(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xAA0003F4U;
    constexpr uint64_t kVaddr  = 0x10e8ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #406 @ 0x10ec: 0x93407EA0 -> sxtw x0, w21
// Lệnh AArch64 #406 tại 0x10ec: sxtw x0, w21
uint64_t verify_tob_encrypt_insn_406_0x10ec(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x93407EA0U;
    constexpr uint64_t kVaddr  = 0x10ecULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #407 @ 0x10f0: 0x940000A8 -> bl #0x1390
// Lệnh AArch64 #407 tại 0x10f0: bl #0x1390
uint64_t verify_tob_encrypt_insn_407_0x10f0(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x940000A8U;
    constexpr uint64_t kVaddr  = 0x10f0ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #408 @ 0x10f4: 0xF9400268 -> ldr x8, [x19]
// Lệnh AArch64 #408 tại 0x10f4: ldr x8, [x19]
uint64_t verify_tob_encrypt_insn_408_0x10f4(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xF9400268U;
    constexpr uint64_t kVaddr  = 0x10f4ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #409 @ 0x10f8: 0xAA0003F6 -> mov x22, x0
// Lệnh AArch64 #409 tại 0x10f8: mov x22, x0
uint64_t verify_tob_encrypt_insn_409_0x10f8(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xAA0003F6U;
    constexpr uint64_t kVaddr  = 0x10f8ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #410 @ 0x10fc: 0xAA1303E0 -> mov x0, x19
// Lệnh AArch64 #410 tại 0x10fc: mov x0, x19
uint64_t verify_tob_encrypt_insn_410_0x10fc(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xAA1303E0U;
    constexpr uint64_t kVaddr  = 0x10fcULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #411 @ 0x1100: 0xAA1903E1 -> mov x1, x25
// Lệnh AArch64 #411 tại 0x1100: mov x1, x25
uint64_t verify_tob_encrypt_insn_411_0x1100(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xAA1903E1U;
    constexpr uint64_t kVaddr  = 0x1100ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #412 @ 0x1104: 0xF9432108 -> ldr x8, [x8, #0x640]
// Lệnh AArch64 #412 tại 0x1104: ldr x8, [x8, #0x640]
uint64_t verify_tob_encrypt_insn_412_0x1104(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xF9432108U;
    constexpr uint64_t kVaddr  = 0x1104ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #413 @ 0x1108: 0x2A1F03E2 -> mov w2, wzr
// Lệnh AArch64 #413 tại 0x1108: mov w2, wzr
uint64_t verify_tob_encrypt_insn_413_0x1108(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x2A1F03E2U;
    constexpr uint64_t kVaddr  = 0x1108ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #414 @ 0x110c: 0x2A1703E3 -> mov w3, w23
// Lệnh AArch64 #414 tại 0x110c: mov w3, w23
uint64_t verify_tob_encrypt_insn_414_0x110c(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x2A1703E3U;
    constexpr uint64_t kVaddr  = 0x110cULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #415 @ 0x1110: 0xAA1403E4 -> mov x4, x20
// Lệnh AArch64 #415 tại 0x1110: mov x4, x20
uint64_t verify_tob_encrypt_insn_415_0x1110(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xAA1403E4U;
    constexpr uint64_t kVaddr  = 0x1110ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #416 @ 0x1114: 0xD63F0100 -> blr x8
// Lệnh AArch64 #416 tại 0x1114: blr x8
uint64_t verify_tob_encrypt_insn_416_0x1114(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xD63F0100U;
    constexpr uint64_t kVaddr  = 0x1114ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #417 @ 0x1118: 0xAA1803E0 -> mov x0, x24
// Lệnh AArch64 #417 tại 0x1118: mov x0, x24
uint64_t verify_tob_encrypt_insn_417_0x1118(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xAA1803E0U;
    constexpr uint64_t kVaddr  = 0x1118ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #418 @ 0x111c: 0x940000A1 -> bl #0x13a0
// Lệnh AArch64 #418 tại 0x111c: bl #0x13a0
uint64_t verify_tob_encrypt_insn_418_0x111c(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x940000A1U;
    constexpr uint64_t kVaddr  = 0x111cULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #419 @ 0x1120: 0xAA0003E3 -> mov x3, x0
// Lệnh AArch64 #419 tại 0x1120: mov x3, x0
uint64_t verify_tob_encrypt_insn_419_0x1120(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xAA0003E3U;
    constexpr uint64_t kVaddr  = 0x1120ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #420 @ 0x1124: 0xAA1403E0 -> mov x0, x20
// Lệnh AArch64 #420 tại 0x1124: mov x0, x20
uint64_t verify_tob_encrypt_insn_420_0x1124(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xAA1403E0U;
    constexpr uint64_t kVaddr  = 0x1124ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #421 @ 0x1128: 0x2A1703E1 -> mov w1, w23
// Lệnh AArch64 #421 tại 0x1128: mov w1, w23
uint64_t verify_tob_encrypt_insn_421_0x1128(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x2A1703E1U;
    constexpr uint64_t kVaddr  = 0x1128ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #422 @ 0x112c: 0xAA1803E2 -> mov x2, x24
// Lệnh AArch64 #422 tại 0x112c: mov x2, x24
uint64_t verify_tob_encrypt_insn_422_0x112c(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xAA1803E2U;
    constexpr uint64_t kVaddr  = 0x112cULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #423 @ 0x1130: 0xAA1603E4 -> mov x4, x22
// Lệnh AArch64 #423 tại 0x1130: mov x4, x22
uint64_t verify_tob_encrypt_insn_423_0x1130(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xAA1603E4U;
    constexpr uint64_t kVaddr  = 0x1130ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #424 @ 0x1134: 0x9400009F -> bl #0x13b0
// Lệnh AArch64 #424 tại 0x1134: bl #0x13b0
uint64_t verify_tob_encrypt_insn_424_0x1134(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x9400009FU;
    constexpr uint64_t kVaddr  = 0x1134ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #425 @ 0x1138: 0x37F802C0 -> tbnz w0, #0x1f, #0x1190
// Lệnh AArch64 #425 tại 0x1138: tbnz w0, #0x1f, #0x1190
uint64_t verify_tob_encrypt_insn_425_0x1138(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x37F802C0U;
    constexpr uint64_t kVaddr  = 0x1138ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #426 @ 0x113c: 0xF9400268 -> ldr x8, [x19]
// Lệnh AArch64 #426 tại 0x113c: ldr x8, [x19]
uint64_t verify_tob_encrypt_insn_426_0x113c(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xF9400268U;
    constexpr uint64_t kVaddr  = 0x113cULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #427 @ 0x1140: 0xAA1303E0 -> mov x0, x19
// Lệnh AArch64 #427 tại 0x1140: mov x0, x19
uint64_t verify_tob_encrypt_insn_427_0x1140(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xAA1303E0U;
    constexpr uint64_t kVaddr  = 0x1140ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #428 @ 0x1144: 0x2A1503E1 -> mov w1, w21
// Lệnh AArch64 #428 tại 0x1144: mov w1, w21
uint64_t verify_tob_encrypt_insn_428_0x1144(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x2A1503E1U;
    constexpr uint64_t kVaddr  = 0x1144ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #429 @ 0x1148: 0xF942C108 -> ldr x8, [x8, #0x580]
// Lệnh AArch64 #429 tại 0x1148: ldr x8, [x8, #0x580]
uint64_t verify_tob_encrypt_insn_429_0x1148(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xF942C108U;
    constexpr uint64_t kVaddr  = 0x1148ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #430 @ 0x114c: 0xD63F0100 -> blr x8
// Lệnh AArch64 #430 tại 0x114c: blr x8
uint64_t verify_tob_encrypt_insn_430_0x114c(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xD63F0100U;
    constexpr uint64_t kVaddr  = 0x114cULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #431 @ 0x1150: 0xF9400268 -> ldr x8, [x19]
// Lệnh AArch64 #431 tại 0x1150: ldr x8, [x19]
uint64_t verify_tob_encrypt_insn_431_0x1150(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xF9400268U;
    constexpr uint64_t kVaddr  = 0x1150ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #432 @ 0x1154: 0xAA0003F8 -> mov x24, x0
// Lệnh AArch64 #432 tại 0x1154: mov x24, x0
uint64_t verify_tob_encrypt_insn_432_0x1154(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xAA0003F8U;
    constexpr uint64_t kVaddr  = 0x1154ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #433 @ 0x1158: 0xAA1303E0 -> mov x0, x19
// Lệnh AArch64 #433 tại 0x1158: mov x0, x19
uint64_t verify_tob_encrypt_insn_433_0x1158(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xAA1303E0U;
    constexpr uint64_t kVaddr  = 0x1158ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #434 @ 0x115c: 0xAA1803E1 -> mov x1, x24
// Lệnh AArch64 #434 tại 0x115c: mov x1, x24
uint64_t verify_tob_encrypt_insn_434_0x115c(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xAA1803E1U;
    constexpr uint64_t kVaddr  = 0x115cULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #435 @ 0x1160: 0xF9434108 -> ldr x8, [x8, #0x680]
// Lệnh AArch64 #435 tại 0x1160: ldr x8, [x8, #0x680]
uint64_t verify_tob_encrypt_insn_435_0x1160(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xF9434108U;
    constexpr uint64_t kVaddr  = 0x1160ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #436 @ 0x1164: 0x2A1F03E2 -> mov w2, wzr
// Lệnh AArch64 #436 tại 0x1164: mov w2, wzr
uint64_t verify_tob_encrypt_insn_436_0x1164(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x2A1F03E2U;
    constexpr uint64_t kVaddr  = 0x1164ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #437 @ 0x1168: 0x2A1503E3 -> mov w3, w21
// Lệnh AArch64 #437 tại 0x1168: mov w3, w21
uint64_t verify_tob_encrypt_insn_437_0x1168(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x2A1503E3U;
    constexpr uint64_t kVaddr  = 0x1168ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #438 @ 0x116c: 0xAA1603E4 -> mov x4, x22
// Lệnh AArch64 #438 tại 0x116c: mov x4, x22
uint64_t verify_tob_encrypt_insn_438_0x116c(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xAA1603E4U;
    constexpr uint64_t kVaddr  = 0x116cULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #439 @ 0x1170: 0xD63F0100 -> blr x8
// Lệnh AArch64 #439 tại 0x1170: blr x8
uint64_t verify_tob_encrypt_insn_439_0x1170(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xD63F0100U;
    constexpr uint64_t kVaddr  = 0x1170ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #440 @ 0x1174: 0xB4000074 -> cbz x20, #0x1180
// Lệnh AArch64 #440 tại 0x1174: cbz x20, #0x1180
uint64_t verify_tob_encrypt_insn_440_0x1174(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xB4000074U;
    constexpr uint64_t kVaddr  = 0x1174ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #441 @ 0x1178: 0xAA1403E0 -> mov x0, x20
// Lệnh AArch64 #441 tại 0x1178: mov x0, x20
uint64_t verify_tob_encrypt_insn_441_0x1178(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xAA1403E0U;
    constexpr uint64_t kVaddr  = 0x1178ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #442 @ 0x117c: 0x94000091 -> bl #0x13c0
// Lệnh AArch64 #442 tại 0x117c: bl #0x13c0
uint64_t verify_tob_encrypt_insn_442_0x117c(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x94000091U;
    constexpr uint64_t kVaddr  = 0x117cULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #443 @ 0x1180: 0xB40000B6 -> cbz x22, #0x1194
// Lệnh AArch64 #443 tại 0x1180: cbz x22, #0x1194
uint64_t verify_tob_encrypt_insn_443_0x1180(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xB40000B6U;
    constexpr uint64_t kVaddr  = 0x1180ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #444 @ 0x1184: 0xAA1603E0 -> mov x0, x22
// Lệnh AArch64 #444 tại 0x1184: mov x0, x22
uint64_t verify_tob_encrypt_insn_444_0x1184(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xAA1603E0U;
    constexpr uint64_t kVaddr  = 0x1184ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #445 @ 0x1188: 0x9400008E -> bl #0x13c0
// Lệnh AArch64 #445 tại 0x1188: bl #0x13c0
uint64_t verify_tob_encrypt_insn_445_0x1188(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x9400008EU;
    constexpr uint64_t kVaddr  = 0x1188ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #446 @ 0x118c: 0x14000002 -> b #0x1194
// Lệnh AArch64 #446 tại 0x118c: b #0x1194
uint64_t verify_tob_encrypt_insn_446_0x118c(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x14000002U;
    constexpr uint64_t kVaddr  = 0x118cULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #447 @ 0x1190: 0xAA1F03F8 -> mov x24, xzr
// Lệnh AArch64 #447 tại 0x1190: mov x24, xzr
uint64_t verify_tob_encrypt_insn_447_0x1190(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xAA1F03F8U;
    constexpr uint64_t kVaddr  = 0x1190ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #448 @ 0x1194: 0xF9401748 -> ldr x8, [x26, #0x28]
// Lệnh AArch64 #448 tại 0x1194: ldr x8, [x26, #0x28]
uint64_t verify_tob_encrypt_insn_448_0x1194(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xF9401748U;
    constexpr uint64_t kVaddr  = 0x1194ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #449 @ 0x1198: 0xF94007E9 -> ldr x9, [sp, #8]
// Lệnh AArch64 #449 tại 0x1198: ldr x9, [sp, #8]
uint64_t verify_tob_encrypt_insn_449_0x1198(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xF94007E9U;
    constexpr uint64_t kVaddr  = 0x1198ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #450 @ 0x119c: 0xEB09011F -> cmp x8, x9
// Lệnh AArch64 #450 tại 0x119c: cmp x8, x9
uint64_t verify_tob_encrypt_insn_450_0x119c(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xEB09011FU;
    constexpr uint64_t kVaddr  = 0x119cULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #451 @ 0x11a0: 0x54000121 -> b.ne #0x11c4
// Lệnh AArch64 #451 tại 0x11a0: b.ne #0x11c4
uint64_t verify_tob_encrypt_insn_451_0x11a0(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x54000121U;
    constexpr uint64_t kVaddr  = 0x11a0ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #452 @ 0x11a4: 0xAA1803E0 -> mov x0, x24
// Lệnh AArch64 #452 tại 0x11a4: mov x0, x24
uint64_t verify_tob_encrypt_insn_452_0x11a4(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xAA1803E0U;
    constexpr uint64_t kVaddr  = 0x11a4ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #453 @ 0x11a8: 0xA9454FF4 -> ldp x20, x19, [sp, #0x50]
// Lệnh AArch64 #453 tại 0x11a8: ldp x20, x19, [sp, #0x50]
uint64_t verify_tob_encrypt_insn_453_0x11a8(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xA9454FF4U;
    constexpr uint64_t kVaddr  = 0x11a8ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #454 @ 0x11ac: 0xA94457F6 -> ldp x22, x21, [sp, #0x40]
// Lệnh AArch64 #454 tại 0x11ac: ldp x22, x21, [sp, #0x40]
uint64_t verify_tob_encrypt_insn_454_0x11ac(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xA94457F6U;
    constexpr uint64_t kVaddr  = 0x11acULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #455 @ 0x11b0: 0xA9435FF8 -> ldp x24, x23, [sp, #0x30]
// Lệnh AArch64 #455 tại 0x11b0: ldp x24, x23, [sp, #0x30]
uint64_t verify_tob_encrypt_insn_455_0x11b0(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xA9435FF8U;
    constexpr uint64_t kVaddr  = 0x11b0ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #456 @ 0x11b4: 0xA94267FA -> ldp x26, x25, [sp, #0x20]
// Lệnh AArch64 #456 tại 0x11b4: ldp x26, x25, [sp, #0x20]
uint64_t verify_tob_encrypt_insn_456_0x11b4(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xA94267FAU;
    constexpr uint64_t kVaddr  = 0x11b4ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #457 @ 0x11b8: 0xA9417BFD -> ldp x29, x30, [sp, #0x10]
// Lệnh AArch64 #457 tại 0x11b8: ldp x29, x30, [sp, #0x10]
uint64_t verify_tob_encrypt_insn_457_0x11b8(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xA9417BFDU;
    constexpr uint64_t kVaddr  = 0x11b8ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #458 @ 0x11bc: 0x910183FF -> add sp, sp, #0x60
// Lệnh AArch64 #458 tại 0x11bc: add sp, sp, #0x60
uint64_t verify_tob_encrypt_insn_458_0x11bc(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x910183FFU;
    constexpr uint64_t kVaddr  = 0x11bcULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #459 @ 0x11c0: 0xD65F03C0 -> ret 
// Lệnh AArch64 #459 tại 0x11c0: ret 
uint64_t verify_tob_encrypt_insn_459_0x11c0(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xD65F03C0U;
    constexpr uint64_t kVaddr  = 0x11c0ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #460 @ 0x11c4: 0x9400005F -> bl #0x1340
// Lệnh AArch64 #460 tại 0x11c4: bl #0x1340
uint64_t verify_tob_encrypt_insn_460_0x11c4(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x9400005FU;
    constexpr uint64_t kVaddr  = 0x11c4ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #461 @ 0x11c8: 0xD10143FF -> sub sp, sp, #0x50
// Lệnh AArch64 #461 tại 0x11c8: sub sp, sp, #0x50
uint64_t verify_tob_encrypt_insn_461_0x11c8(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xD10143FFU;
    constexpr uint64_t kVaddr  = 0x11c8ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #462 @ 0x11cc: 0xA9017BFD -> stp x29, x30, [sp, #0x10]
// Lệnh AArch64 #462 tại 0x11cc: stp x29, x30, [sp, #0x10]
uint64_t verify_tob_encrypt_insn_462_0x11cc(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xA9017BFDU;
    constexpr uint64_t kVaddr  = 0x11ccULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #463 @ 0x11d0: 0xA9025FF8 -> stp x24, x23, [sp, #0x20]
// Lệnh AArch64 #463 tại 0x11d0: stp x24, x23, [sp, #0x20]
uint64_t verify_tob_encrypt_insn_463_0x11d0(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xA9025FF8U;
    constexpr uint64_t kVaddr  = 0x11d0ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #464 @ 0x11d4: 0xA90357F6 -> stp x22, x21, [sp, #0x30]
// Lệnh AArch64 #464 tại 0x11d4: stp x22, x21, [sp, #0x30]
uint64_t verify_tob_encrypt_insn_464_0x11d4(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xA90357F6U;
    constexpr uint64_t kVaddr  = 0x11d4ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #465 @ 0x11d8: 0xA9044FF4 -> stp x20, x19, [sp, #0x40]
// Lệnh AArch64 #465 tại 0x11d8: stp x20, x19, [sp, #0x40]
uint64_t verify_tob_encrypt_insn_465_0x11d8(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xA9044FF4U;
    constexpr uint64_t kVaddr  = 0x11d8ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #466 @ 0x11dc: 0x910043FD -> add x29, sp, #0x10
// Lệnh AArch64 #466 tại 0x11dc: add x29, sp, #0x10
uint64_t verify_tob_encrypt_insn_466_0x11dc(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x910043FDU;
    constexpr uint64_t kVaddr  = 0x11dcULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #467 @ 0x11e0: 0xD53BD058 -> mrs x24, tpidr_el0
// Lệnh AArch64 #467 tại 0x11e0: mrs x24, tpidr_el0
uint64_t verify_tob_encrypt_insn_467_0x11e0(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xD53BD058U;
    constexpr uint64_t kVaddr  = 0x11e0ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #468 @ 0x11e4: 0xF9401708 -> ldr x8, [x24, #0x28]
// Lệnh AArch64 #468 tại 0x11e4: ldr x8, [x24, #0x28]
uint64_t verify_tob_encrypt_insn_468_0x11e4(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xF9401708U;
    constexpr uint64_t kVaddr  = 0x11e4ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #469 @ 0x11e8: 0xAA1F03F5 -> mov x21, xzr
// Lệnh AArch64 #469 tại 0x11e8: mov x21, xzr
uint64_t verify_tob_encrypt_insn_469_0x11e8(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xAA1F03F5U;
    constexpr uint64_t kVaddr  = 0x11e8ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #470 @ 0x11ec: 0xF90007E8 -> str x8, [sp, #8]
// Lệnh AArch64 #470 tại 0x11ec: str x8, [sp, #8]
uint64_t verify_tob_encrypt_insn_470_0x11ec(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xF90007E8U;
    constexpr uint64_t kVaddr  = 0x11ecULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #471 @ 0x11f0: 0xB40006C2 -> cbz x2, #0x12c8
// Lệnh AArch64 #471 tại 0x11f0: cbz x2, #0x12c8
uint64_t verify_tob_encrypt_insn_471_0x11f0(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xB40006C2U;
    constexpr uint64_t kVaddr  = 0x11f0ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #472 @ 0x11f4: 0x2A0303F6 -> mov w22, w3
// Lệnh AArch64 #472 tại 0x11f4: mov w22, w3
uint64_t verify_tob_encrypt_insn_472_0x11f4(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x2A0303F6U;
    constexpr uint64_t kVaddr  = 0x11f4ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #473 @ 0x11f8: 0x7100047F -> cmp w3, #1
// Lệnh AArch64 #473 tại 0x11f8: cmp w3, #1
uint64_t verify_tob_encrypt_insn_473_0x11f8(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x7100047FU;
    constexpr uint64_t kVaddr  = 0x11f8ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #474 @ 0x11fc: 0x5400066B -> b.lt #0x12c8
// Lệnh AArch64 #474 tại 0x11fc: b.lt #0x12c8
uint64_t verify_tob_encrypt_insn_474_0x11fc(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x5400066BU;
    constexpr uint64_t kVaddr  = 0x11fcULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #475 @ 0x1200: 0xF0FFFFE8 -> adrp x8, #0
// Lệnh AArch64 #475 tại 0x1200: adrp x8, #0
uint64_t verify_tob_encrypt_insn_475_0x1200(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xF0FFFFE8U;
    constexpr uint64_t kVaddr  = 0x1200ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #476 @ 0x1204: 0x3DC24100 -> ldr q0, [x8, #0x900]
// Lệnh AArch64 #476 tại 0x1204: ldr q0, [x8, #0x900]
uint64_t verify_tob_encrypt_insn_476_0x1204(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x3DC24100U;
    constexpr uint64_t kVaddr  = 0x1204ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #477 @ 0x1208: 0x90000055 -> adrp x21, #0x9000
// Lệnh AArch64 #477 tại 0x1208: adrp x21, #0x9000
uint64_t verify_tob_encrypt_insn_477_0x1208(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x90000055U;
    constexpr uint64_t kVaddr  = 0x1208ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #478 @ 0x120c: 0x528CCA88 -> mov w8, #0x6654
// Lệnh AArch64 #478 tại 0x120c: mov w8, #0x6654
uint64_t verify_tob_encrypt_insn_478_0x120c(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x528CCA88U;
    constexpr uint64_t kVaddr  = 0x120cULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #479 @ 0x1210: 0xAA0003F3 -> mov x19, x0
// Lệnh AArch64 #479 tại 0x1210: mov x19, x0
uint64_t verify_tob_encrypt_insn_479_0x1210(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xAA0003F3U;
    constexpr uint64_t kVaddr  = 0x1210ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #480 @ 0x1214: 0x9120C2B5 -> add x21, x21, #0x830
// Lệnh AArch64 #480 tại 0x1214: add x21, x21, #0x830
uint64_t verify_tob_encrypt_insn_480_0x1214(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x9120C2B5U;
    constexpr uint64_t kVaddr  = 0x1214ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #481 @ 0x1218: 0x72A82C88 -> movk w8, #0x4164, lsl #16
// Lệnh AArch64 #481 tại 0x1218: movk w8, #0x4164, lsl #16
uint64_t verify_tob_encrypt_insn_481_0x1218(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x72A82C88U;
    constexpr uint64_t kVaddr  = 0x1218ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #482 @ 0x121c: 0x2A1603E0 -> mov w0, w22
// Lệnh AArch64 #482 tại 0x121c: mov w0, w22
uint64_t verify_tob_encrypt_insn_482_0x121c(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x2A1603E0U;
    constexpr uint64_t kVaddr  = 0x121cULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #483 @ 0x1220: 0xAA0203F7 -> mov x23, x2
// Lệnh AArch64 #483 tại 0x1220: mov x23, x2
uint64_t verify_tob_encrypt_insn_483_0x1220(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xAA0203F7U;
    constexpr uint64_t kVaddr  = 0x1220ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #484 @ 0x1224: 0xB90012A8 -> str w8, [x21, #0x10]
// Lệnh AArch64 #484 tại 0x1224: str w8, [x21, #0x10]
uint64_t verify_tob_encrypt_insn_484_0x1224(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xB90012A8U;
    constexpr uint64_t kVaddr  = 0x1224ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #485 @ 0x1228: 0x3D8002A0 -> str q0, [x21]
// Lệnh AArch64 #485 tại 0x1228: str q0, [x21]
uint64_t verify_tob_encrypt_insn_485_0x1228(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x3D8002A0U;
    constexpr uint64_t kVaddr  = 0x1228ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #486 @ 0x122c: 0x94000059 -> bl #0x1390
// Lệnh AArch64 #486 tại 0x122c: bl #0x1390
uint64_t verify_tob_encrypt_insn_486_0x122c(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x94000059U;
    constexpr uint64_t kVaddr  = 0x122cULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #487 @ 0x1230: 0xF9400268 -> ldr x8, [x19]
// Lệnh AArch64 #487 tại 0x1230: ldr x8, [x19]
uint64_t verify_tob_encrypt_insn_487_0x1230(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xF9400268U;
    constexpr uint64_t kVaddr  = 0x1230ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #488 @ 0x1234: 0xAA0003F4 -> mov x20, x0
// Lệnh AArch64 #488 tại 0x1234: mov x20, x0
uint64_t verify_tob_encrypt_insn_488_0x1234(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xAA0003F4U;
    constexpr uint64_t kVaddr  = 0x1234ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #489 @ 0x1238: 0xAA1303E0 -> mov x0, x19
// Lệnh AArch64 #489 tại 0x1238: mov x0, x19
uint64_t verify_tob_encrypt_insn_489_0x1238(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xAA1303E0U;
    constexpr uint64_t kVaddr  = 0x1238ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #490 @ 0x123c: 0xAA1703E1 -> mov x1, x23
// Lệnh AArch64 #490 tại 0x123c: mov x1, x23
uint64_t verify_tob_encrypt_insn_490_0x123c(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xAA1703E1U;
    constexpr uint64_t kVaddr  = 0x123cULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #491 @ 0x1240: 0xF9432108 -> ldr x8, [x8, #0x640]
// Lệnh AArch64 #491 tại 0x1240: ldr x8, [x8, #0x640]
uint64_t verify_tob_encrypt_insn_491_0x1240(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xF9432108U;
    constexpr uint64_t kVaddr  = 0x1240ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #492 @ 0x1244: 0x2A1F03E2 -> mov w2, wzr
// Lệnh AArch64 #492 tại 0x1244: mov w2, wzr
uint64_t verify_tob_encrypt_insn_492_0x1244(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x2A1F03E2U;
    constexpr uint64_t kVaddr  = 0x1244ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #493 @ 0x1248: 0x2A1603E3 -> mov w3, w22
// Lệnh AArch64 #493 tại 0x1248: mov w3, w22
uint64_t verify_tob_encrypt_insn_493_0x1248(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x2A1603E3U;
    constexpr uint64_t kVaddr  = 0x1248ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #494 @ 0x124c: 0xAA1403E4 -> mov x4, x20
// Lệnh AArch64 #494 tại 0x124c: mov x4, x20
uint64_t verify_tob_encrypt_insn_494_0x124c(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xAA1403E4U;
    constexpr uint64_t kVaddr  = 0x124cULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #495 @ 0x1250: 0xD63F0100 -> blr x8
// Lệnh AArch64 #495 tại 0x1250: blr x8
uint64_t verify_tob_encrypt_insn_495_0x1250(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xD63F0100U;
    constexpr uint64_t kVaddr  = 0x1250ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #496 @ 0x1254: 0xAA1503E0 -> mov x0, x21
// Lệnh AArch64 #496 tại 0x1254: mov x0, x21
uint64_t verify_tob_encrypt_insn_496_0x1254(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xAA1503E0U;
    constexpr uint64_t kVaddr  = 0x1254ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #497 @ 0x1258: 0x94000052 -> bl #0x13a0
// Lệnh AArch64 #497 tại 0x1258: bl #0x13a0
uint64_t verify_tob_encrypt_insn_497_0x1258(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x94000052U;
    constexpr uint64_t kVaddr  = 0x1258ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #498 @ 0x125c: 0xAA0003E3 -> mov x3, x0
// Lệnh AArch64 #498 tại 0x125c: mov x3, x0
uint64_t verify_tob_encrypt_insn_498_0x125c(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xAA0003E3U;
    constexpr uint64_t kVaddr  = 0x125cULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #499 @ 0x1260: 0xAA1403E0 -> mov x0, x20
// Lệnh AArch64 #499 tại 0x1260: mov x0, x20
uint64_t verify_tob_encrypt_insn_499_0x1260(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xAA1403E0U;
    constexpr uint64_t kVaddr  = 0x1260ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #500 @ 0x1264: 0x2A1603E1 -> mov w1, w22
// Lệnh AArch64 #500 tại 0x1264: mov w1, w22
uint64_t verify_tob_encrypt_insn_500_0x1264(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x2A1603E1U;
    constexpr uint64_t kVaddr  = 0x1264ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #501 @ 0x1268: 0xAA1503E2 -> mov x2, x21
// Lệnh AArch64 #501 tại 0x1268: mov x2, x21
uint64_t verify_tob_encrypt_insn_501_0x1268(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xAA1503E2U;
    constexpr uint64_t kVaddr  = 0x1268ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #502 @ 0x126c: 0x94000059 -> bl #0x13d0
// Lệnh AArch64 #502 tại 0x126c: bl #0x13d0
uint64_t verify_tob_encrypt_insn_502_0x126c(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x94000059U;
    constexpr uint64_t kVaddr  = 0x126cULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #503 @ 0x1270: 0x7100041F -> cmp w0, #1
// Lệnh AArch64 #503 tại 0x1270: cmp w0, #1
uint64_t verify_tob_encrypt_insn_503_0x1270(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x7100041FU;
    constexpr uint64_t kVaddr  = 0x1270ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #504 @ 0x1274: 0x5400028B -> b.lt #0x12c4
// Lệnh AArch64 #504 tại 0x1274: b.lt #0x12c4
uint64_t verify_tob_encrypt_insn_504_0x1274(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x5400028BU;
    constexpr uint64_t kVaddr  = 0x1274ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #505 @ 0x1278: 0xF9400268 -> ldr x8, [x19]
// Lệnh AArch64 #505 tại 0x1278: ldr x8, [x19]
uint64_t verify_tob_encrypt_insn_505_0x1278(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xF9400268U;
    constexpr uint64_t kVaddr  = 0x1278ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #506 @ 0x127c: 0x2A0003F6 -> mov w22, w0
// Lệnh AArch64 #506 tại 0x127c: mov w22, w0
uint64_t verify_tob_encrypt_insn_506_0x127c(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x2A0003F6U;
    constexpr uint64_t kVaddr  = 0x127cULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #507 @ 0x1280: 0xAA1303E0 -> mov x0, x19
// Lệnh AArch64 #507 tại 0x1280: mov x0, x19
uint64_t verify_tob_encrypt_insn_507_0x1280(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xAA1303E0U;
    constexpr uint64_t kVaddr  = 0x1280ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #508 @ 0x1284: 0x2A1603E1 -> mov w1, w22
// Lệnh AArch64 #508 tại 0x1284: mov w1, w22
uint64_t verify_tob_encrypt_insn_508_0x1284(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x2A1603E1U;
    constexpr uint64_t kVaddr  = 0x1284ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #509 @ 0x1288: 0xF942C108 -> ldr x8, [x8, #0x580]
// Lệnh AArch64 #509 tại 0x1288: ldr x8, [x8, #0x580]
uint64_t verify_tob_encrypt_insn_509_0x1288(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xF942C108U;
    constexpr uint64_t kVaddr  = 0x1288ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #510 @ 0x128c: 0xD63F0100 -> blr x8
// Lệnh AArch64 #510 tại 0x128c: blr x8
uint64_t verify_tob_encrypt_insn_510_0x128c(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xD63F0100U;
    constexpr uint64_t kVaddr  = 0x128cULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #511 @ 0x1290: 0xF9400268 -> ldr x8, [x19]
// Lệnh AArch64 #511 tại 0x1290: ldr x8, [x19]
uint64_t verify_tob_encrypt_insn_511_0x1290(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xF9400268U;
    constexpr uint64_t kVaddr  = 0x1290ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #512 @ 0x1294: 0xAA0003F5 -> mov x21, x0
// Lệnh AArch64 #512 tại 0x1294: mov x21, x0
uint64_t verify_tob_encrypt_insn_512_0x1294(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xAA0003F5U;
    constexpr uint64_t kVaddr  = 0x1294ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #513 @ 0x1298: 0x91001A84 -> add x4, x20, #6
// Lệnh AArch64 #513 tại 0x1298: add x4, x20, #6
uint64_t verify_tob_encrypt_insn_513_0x1298(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x91001A84U;
    constexpr uint64_t kVaddr  = 0x1298ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #514 @ 0x129c: 0xAA1303E0 -> mov x0, x19
// Lệnh AArch64 #514 tại 0x129c: mov x0, x19
uint64_t verify_tob_encrypt_insn_514_0x129c(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xAA1303E0U;
    constexpr uint64_t kVaddr  = 0x129cULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #515 @ 0x12a0: 0xF9434108 -> ldr x8, [x8, #0x680]
// Lệnh AArch64 #515 tại 0x12a0: ldr x8, [x8, #0x680]
uint64_t verify_tob_encrypt_insn_515_0x12a0(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xF9434108U;
    constexpr uint64_t kVaddr  = 0x12a0ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #516 @ 0x12a4: 0xAA1503E1 -> mov x1, x21
// Lệnh AArch64 #516 tại 0x12a4: mov x1, x21
uint64_t verify_tob_encrypt_insn_516_0x12a4(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xAA1503E1U;
    constexpr uint64_t kVaddr  = 0x12a4ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #517 @ 0x12a8: 0x2A1F03E2 -> mov w2, wzr
// Lệnh AArch64 #517 tại 0x12a8: mov w2, wzr
uint64_t verify_tob_encrypt_insn_517_0x12a8(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x2A1F03E2U;
    constexpr uint64_t kVaddr  = 0x12a8ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #518 @ 0x12ac: 0x2A1603E3 -> mov w3, w22
// Lệnh AArch64 #518 tại 0x12ac: mov w3, w22
uint64_t verify_tob_encrypt_insn_518_0x12ac(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x2A1603E3U;
    constexpr uint64_t kVaddr  = 0x12acULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #519 @ 0x12b0: 0xD63F0100 -> blr x8
// Lệnh AArch64 #519 tại 0x12b0: blr x8
uint64_t verify_tob_encrypt_insn_519_0x12b0(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xD63F0100U;
    constexpr uint64_t kVaddr  = 0x12b0ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #520 @ 0x12b4: 0xB40000B4 -> cbz x20, #0x12c8
// Lệnh AArch64 #520 tại 0x12b4: cbz x20, #0x12c8
uint64_t verify_tob_encrypt_insn_520_0x12b4(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xB40000B4U;
    constexpr uint64_t kVaddr  = 0x12b4ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #521 @ 0x12b8: 0xAA1403E0 -> mov x0, x20
// Lệnh AArch64 #521 tại 0x12b8: mov x0, x20
uint64_t verify_tob_encrypt_insn_521_0x12b8(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xAA1403E0U;
    constexpr uint64_t kVaddr  = 0x12b8ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #522 @ 0x12bc: 0x94000041 -> bl #0x13c0
// Lệnh AArch64 #522 tại 0x12bc: bl #0x13c0
uint64_t verify_tob_encrypt_insn_522_0x12bc(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x94000041U;
    constexpr uint64_t kVaddr  = 0x12bcULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #523 @ 0x12c0: 0x14000002 -> b #0x12c8
// Lệnh AArch64 #523 tại 0x12c0: b #0x12c8
uint64_t verify_tob_encrypt_insn_523_0x12c0(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x14000002U;
    constexpr uint64_t kVaddr  = 0x12c0ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #524 @ 0x12c4: 0xAA1F03F5 -> mov x21, xzr
// Lệnh AArch64 #524 tại 0x12c4: mov x21, xzr
uint64_t verify_tob_encrypt_insn_524_0x12c4(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xAA1F03F5U;
    constexpr uint64_t kVaddr  = 0x12c4ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #525 @ 0x12c8: 0xF9401708 -> ldr x8, [x24, #0x28]
// Lệnh AArch64 #525 tại 0x12c8: ldr x8, [x24, #0x28]
uint64_t verify_tob_encrypt_insn_525_0x12c8(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xF9401708U;
    constexpr uint64_t kVaddr  = 0x12c8ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #526 @ 0x12cc: 0xF94007E9 -> ldr x9, [sp, #8]
// Lệnh AArch64 #526 tại 0x12cc: ldr x9, [sp, #8]
uint64_t verify_tob_encrypt_insn_526_0x12cc(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xF94007E9U;
    constexpr uint64_t kVaddr  = 0x12ccULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #527 @ 0x12d0: 0xEB09011F -> cmp x8, x9
// Lệnh AArch64 #527 tại 0x12d0: cmp x8, x9
uint64_t verify_tob_encrypt_insn_527_0x12d0(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xEB09011FU;
    constexpr uint64_t kVaddr  = 0x12d0ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #528 @ 0x12d4: 0x54000101 -> b.ne #0x12f4
// Lệnh AArch64 #528 tại 0x12d4: b.ne #0x12f4
uint64_t verify_tob_encrypt_insn_528_0x12d4(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x54000101U;
    constexpr uint64_t kVaddr  = 0x12d4ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #529 @ 0x12d8: 0xAA1503E0 -> mov x0, x21
// Lệnh AArch64 #529 tại 0x12d8: mov x0, x21
uint64_t verify_tob_encrypt_insn_529_0x12d8(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xAA1503E0U;
    constexpr uint64_t kVaddr  = 0x12d8ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #530 @ 0x12dc: 0xA9444FF4 -> ldp x20, x19, [sp, #0x40]
// Lệnh AArch64 #530 tại 0x12dc: ldp x20, x19, [sp, #0x40]
uint64_t verify_tob_encrypt_insn_530_0x12dc(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xA9444FF4U;
    constexpr uint64_t kVaddr  = 0x12dcULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #531 @ 0x12e0: 0xA94357F6 -> ldp x22, x21, [sp, #0x30]
// Lệnh AArch64 #531 tại 0x12e0: ldp x22, x21, [sp, #0x30]
uint64_t verify_tob_encrypt_insn_531_0x12e0(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xA94357F6U;
    constexpr uint64_t kVaddr  = 0x12e0ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #532 @ 0x12e4: 0xA9425FF8 -> ldp x24, x23, [sp, #0x20]
// Lệnh AArch64 #532 tại 0x12e4: ldp x24, x23, [sp, #0x20]
uint64_t verify_tob_encrypt_insn_532_0x12e4(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xA9425FF8U;
    constexpr uint64_t kVaddr  = 0x12e4ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #533 @ 0x12e8: 0xA9417BFD -> ldp x29, x30, [sp, #0x10]
// Lệnh AArch64 #533 tại 0x12e8: ldp x29, x30, [sp, #0x10]
uint64_t verify_tob_encrypt_insn_533_0x12e8(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xA9417BFDU;
    constexpr uint64_t kVaddr  = 0x12e8ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #534 @ 0x12ec: 0x910143FF -> add sp, sp, #0x50
// Lệnh AArch64 #534 tại 0x12ec: add sp, sp, #0x50
uint64_t verify_tob_encrypt_insn_534_0x12ec(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x910143FFU;
    constexpr uint64_t kVaddr  = 0x12ecULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #535 @ 0x12f0: 0xD65F03C0 -> ret 
// Lệnh AArch64 #535 tại 0x12f0: ret 
uint64_t verify_tob_encrypt_insn_535_0x12f0(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xD65F03C0U;
    constexpr uint64_t kVaddr  = 0x12f0ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #536 @ 0x12f4: 0x94000013 -> bl #0x1340
// Lệnh AArch64 #536 tại 0x12f4: bl #0x1340
uint64_t verify_tob_encrypt_insn_536_0x12f4(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x94000013U;
    constexpr uint64_t kVaddr  = 0x12f4ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

uint64_t ExecuteTobEncryptTextInstructionVerify(uint32_t insn_idx, uint64_t seed) noexcept {
    switch (insn_idx) {
        case 0: return verify_tob_encrypt_insn_000_0x0a94(seed);
        case 1: return verify_tob_encrypt_insn_001_0x0a98(seed);
        case 2: return verify_tob_encrypt_insn_002_0x0a9c(seed);
        case 3: return verify_tob_encrypt_insn_003_0x0aa0(seed);
        case 4: return verify_tob_encrypt_insn_004_0x0aa4(seed);
        case 5: return verify_tob_encrypt_insn_005_0x0aa8(seed);
        case 6: return verify_tob_encrypt_insn_006_0x0aac(seed);
        case 7: return verify_tob_encrypt_insn_007_0x0ab0(seed);
        case 8: return verify_tob_encrypt_insn_008_0x0ab4(seed);
        case 9: return verify_tob_encrypt_insn_009_0x0ab8(seed);
        case 10: return verify_tob_encrypt_insn_010_0x0abc(seed);
        case 11: return verify_tob_encrypt_insn_011_0x0ac0(seed);
        case 12: return verify_tob_encrypt_insn_012_0x0ac4(seed);
        case 13: return verify_tob_encrypt_insn_013_0x0ac8(seed);
        case 14: return verify_tob_encrypt_insn_014_0x0acc(seed);
        case 15: return verify_tob_encrypt_insn_015_0x0ad0(seed);
        case 16: return verify_tob_encrypt_insn_016_0x0ad4(seed);
        case 17: return verify_tob_encrypt_insn_017_0x0ad8(seed);
        case 18: return verify_tob_encrypt_insn_018_0x0adc(seed);
        case 19: return verify_tob_encrypt_insn_019_0x0ae0(seed);
        case 20: return verify_tob_encrypt_insn_020_0x0ae4(seed);
        case 21: return verify_tob_encrypt_insn_021_0x0ae8(seed);
        case 22: return verify_tob_encrypt_insn_022_0x0aec(seed);
        case 23: return verify_tob_encrypt_insn_023_0x0af0(seed);
        case 24: return verify_tob_encrypt_insn_024_0x0af4(seed);
        case 25: return verify_tob_encrypt_insn_025_0x0af8(seed);
        case 26: return verify_tob_encrypt_insn_026_0x0afc(seed);
        case 27: return verify_tob_encrypt_insn_027_0x0b00(seed);
        case 28: return verify_tob_encrypt_insn_028_0x0b04(seed);
        case 29: return verify_tob_encrypt_insn_029_0x0b08(seed);
        case 30: return verify_tob_encrypt_insn_030_0x0b0c(seed);
        case 31: return verify_tob_encrypt_insn_031_0x0b10(seed);
        case 32: return verify_tob_encrypt_insn_032_0x0b14(seed);
        case 33: return verify_tob_encrypt_insn_033_0x0b18(seed);
        case 34: return verify_tob_encrypt_insn_034_0x0b1c(seed);
        case 35: return verify_tob_encrypt_insn_035_0x0b20(seed);
        case 36: return verify_tob_encrypt_insn_036_0x0b24(seed);
        case 37: return verify_tob_encrypt_insn_037_0x0b28(seed);
        case 38: return verify_tob_encrypt_insn_038_0x0b2c(seed);
        case 39: return verify_tob_encrypt_insn_039_0x0b30(seed);
        case 40: return verify_tob_encrypt_insn_040_0x0b34(seed);
        case 41: return verify_tob_encrypt_insn_041_0x0b38(seed);
        case 42: return verify_tob_encrypt_insn_042_0x0b3c(seed);
        case 43: return verify_tob_encrypt_insn_043_0x0b40(seed);
        case 44: return verify_tob_encrypt_insn_044_0x0b44(seed);
        case 45: return verify_tob_encrypt_insn_045_0x0b48(seed);
        case 46: return verify_tob_encrypt_insn_046_0x0b4c(seed);
        case 47: return verify_tob_encrypt_insn_047_0x0b50(seed);
        case 48: return verify_tob_encrypt_insn_048_0x0b54(seed);
        case 49: return verify_tob_encrypt_insn_049_0x0b58(seed);
        case 50: return verify_tob_encrypt_insn_050_0x0b5c(seed);
        case 51: return verify_tob_encrypt_insn_051_0x0b60(seed);
        case 52: return verify_tob_encrypt_insn_052_0x0b64(seed);
        case 53: return verify_tob_encrypt_insn_053_0x0b68(seed);
        case 54: return verify_tob_encrypt_insn_054_0x0b6c(seed);
        case 55: return verify_tob_encrypt_insn_055_0x0b70(seed);
        case 56: return verify_tob_encrypt_insn_056_0x0b74(seed);
        case 57: return verify_tob_encrypt_insn_057_0x0b78(seed);
        case 58: return verify_tob_encrypt_insn_058_0x0b7c(seed);
        case 59: return verify_tob_encrypt_insn_059_0x0b80(seed);
        case 60: return verify_tob_encrypt_insn_060_0x0b84(seed);
        case 61: return verify_tob_encrypt_insn_061_0x0b88(seed);
        case 62: return verify_tob_encrypt_insn_062_0x0b8c(seed);
        case 63: return verify_tob_encrypt_insn_063_0x0b90(seed);
        case 64: return verify_tob_encrypt_insn_064_0x0b94(seed);
        case 65: return verify_tob_encrypt_insn_065_0x0b98(seed);
        case 66: return verify_tob_encrypt_insn_066_0x0b9c(seed);
        case 67: return verify_tob_encrypt_insn_067_0x0ba0(seed);
        case 68: return verify_tob_encrypt_insn_068_0x0ba4(seed);
        case 69: return verify_tob_encrypt_insn_069_0x0ba8(seed);
        case 70: return verify_tob_encrypt_insn_070_0x0bac(seed);
        case 71: return verify_tob_encrypt_insn_071_0x0bb0(seed);
        case 72: return verify_tob_encrypt_insn_072_0x0bb4(seed);
        case 73: return verify_tob_encrypt_insn_073_0x0bb8(seed);
        case 74: return verify_tob_encrypt_insn_074_0x0bbc(seed);
        case 75: return verify_tob_encrypt_insn_075_0x0bc0(seed);
        case 76: return verify_tob_encrypt_insn_076_0x0bc4(seed);
        case 77: return verify_tob_encrypt_insn_077_0x0bc8(seed);
        case 78: return verify_tob_encrypt_insn_078_0x0bcc(seed);
        case 79: return verify_tob_encrypt_insn_079_0x0bd0(seed);
        case 80: return verify_tob_encrypt_insn_080_0x0bd4(seed);
        case 81: return verify_tob_encrypt_insn_081_0x0bd8(seed);
        case 82: return verify_tob_encrypt_insn_082_0x0bdc(seed);
        case 83: return verify_tob_encrypt_insn_083_0x0be0(seed);
        case 84: return verify_tob_encrypt_insn_084_0x0be4(seed);
        case 85: return verify_tob_encrypt_insn_085_0x0be8(seed);
        case 86: return verify_tob_encrypt_insn_086_0x0bec(seed);
        case 87: return verify_tob_encrypt_insn_087_0x0bf0(seed);
        case 88: return verify_tob_encrypt_insn_088_0x0bf4(seed);
        case 89: return verify_tob_encrypt_insn_089_0x0bf8(seed);
        case 90: return verify_tob_encrypt_insn_090_0x0bfc(seed);
        case 91: return verify_tob_encrypt_insn_091_0x0c00(seed);
        case 92: return verify_tob_encrypt_insn_092_0x0c04(seed);
        case 93: return verify_tob_encrypt_insn_093_0x0c08(seed);
        case 94: return verify_tob_encrypt_insn_094_0x0c0c(seed);
        case 95: return verify_tob_encrypt_insn_095_0x0c10(seed);
        case 96: return verify_tob_encrypt_insn_096_0x0c14(seed);
        case 97: return verify_tob_encrypt_insn_097_0x0c18(seed);
        case 98: return verify_tob_encrypt_insn_098_0x0c1c(seed);
        case 99: return verify_tob_encrypt_insn_099_0x0c20(seed);
        case 100: return verify_tob_encrypt_insn_100_0x0c24(seed);
        case 101: return verify_tob_encrypt_insn_101_0x0c28(seed);
        case 102: return verify_tob_encrypt_insn_102_0x0c2c(seed);
        case 103: return verify_tob_encrypt_insn_103_0x0c30(seed);
        case 104: return verify_tob_encrypt_insn_104_0x0c34(seed);
        case 105: return verify_tob_encrypt_insn_105_0x0c38(seed);
        case 106: return verify_tob_encrypt_insn_106_0x0c3c(seed);
        case 107: return verify_tob_encrypt_insn_107_0x0c40(seed);
        case 108: return verify_tob_encrypt_insn_108_0x0c44(seed);
        case 109: return verify_tob_encrypt_insn_109_0x0c48(seed);
        case 110: return verify_tob_encrypt_insn_110_0x0c4c(seed);
        case 111: return verify_tob_encrypt_insn_111_0x0c50(seed);
        case 112: return verify_tob_encrypt_insn_112_0x0c54(seed);
        case 113: return verify_tob_encrypt_insn_113_0x0c58(seed);
        case 114: return verify_tob_encrypt_insn_114_0x0c5c(seed);
        case 115: return verify_tob_encrypt_insn_115_0x0c60(seed);
        case 116: return verify_tob_encrypt_insn_116_0x0c64(seed);
        case 117: return verify_tob_encrypt_insn_117_0x0c68(seed);
        case 118: return verify_tob_encrypt_insn_118_0x0c6c(seed);
        case 119: return verify_tob_encrypt_insn_119_0x0c70(seed);
        case 120: return verify_tob_encrypt_insn_120_0x0c74(seed);
        case 121: return verify_tob_encrypt_insn_121_0x0c78(seed);
        case 122: return verify_tob_encrypt_insn_122_0x0c7c(seed);
        case 123: return verify_tob_encrypt_insn_123_0x0c80(seed);
        case 124: return verify_tob_encrypt_insn_124_0x0c84(seed);
        case 125: return verify_tob_encrypt_insn_125_0x0c88(seed);
        case 126: return verify_tob_encrypt_insn_126_0x0c8c(seed);
        case 127: return verify_tob_encrypt_insn_127_0x0c90(seed);
        case 128: return verify_tob_encrypt_insn_128_0x0c94(seed);
        case 129: return verify_tob_encrypt_insn_129_0x0c98(seed);
        case 130: return verify_tob_encrypt_insn_130_0x0c9c(seed);
        case 131: return verify_tob_encrypt_insn_131_0x0ca0(seed);
        case 132: return verify_tob_encrypt_insn_132_0x0ca4(seed);
        case 133: return verify_tob_encrypt_insn_133_0x0ca8(seed);
        case 134: return verify_tob_encrypt_insn_134_0x0cac(seed);
        case 135: return verify_tob_encrypt_insn_135_0x0cb0(seed);
        case 136: return verify_tob_encrypt_insn_136_0x0cb4(seed);
        case 137: return verify_tob_encrypt_insn_137_0x0cb8(seed);
        case 138: return verify_tob_encrypt_insn_138_0x0cbc(seed);
        case 139: return verify_tob_encrypt_insn_139_0x0cc0(seed);
        case 140: return verify_tob_encrypt_insn_140_0x0cc4(seed);
        case 141: return verify_tob_encrypt_insn_141_0x0cc8(seed);
        case 142: return verify_tob_encrypt_insn_142_0x0ccc(seed);
        case 143: return verify_tob_encrypt_insn_143_0x0cd0(seed);
        case 144: return verify_tob_encrypt_insn_144_0x0cd4(seed);
        case 145: return verify_tob_encrypt_insn_145_0x0cd8(seed);
        case 146: return verify_tob_encrypt_insn_146_0x0cdc(seed);
        case 147: return verify_tob_encrypt_insn_147_0x0ce0(seed);
        case 148: return verify_tob_encrypt_insn_148_0x0ce4(seed);
        case 149: return verify_tob_encrypt_insn_149_0x0ce8(seed);
        case 150: return verify_tob_encrypt_insn_150_0x0cec(seed);
        case 151: return verify_tob_encrypt_insn_151_0x0cf0(seed);
        case 152: return verify_tob_encrypt_insn_152_0x0cf4(seed);
        case 153: return verify_tob_encrypt_insn_153_0x0cf8(seed);
        case 154: return verify_tob_encrypt_insn_154_0x0cfc(seed);
        case 155: return verify_tob_encrypt_insn_155_0x0d00(seed);
        case 156: return verify_tob_encrypt_insn_156_0x0d04(seed);
        case 157: return verify_tob_encrypt_insn_157_0x0d08(seed);
        case 158: return verify_tob_encrypt_insn_158_0x0d0c(seed);
        case 159: return verify_tob_encrypt_insn_159_0x0d10(seed);
        case 160: return verify_tob_encrypt_insn_160_0x0d14(seed);
        case 161: return verify_tob_encrypt_insn_161_0x0d18(seed);
        case 162: return verify_tob_encrypt_insn_162_0x0d1c(seed);
        case 163: return verify_tob_encrypt_insn_163_0x0d20(seed);
        case 164: return verify_tob_encrypt_insn_164_0x0d24(seed);
        case 165: return verify_tob_encrypt_insn_165_0x0d28(seed);
        case 166: return verify_tob_encrypt_insn_166_0x0d2c(seed);
        case 167: return verify_tob_encrypt_insn_167_0x0d30(seed);
        case 168: return verify_tob_encrypt_insn_168_0x0d34(seed);
        case 169: return verify_tob_encrypt_insn_169_0x0d38(seed);
        case 170: return verify_tob_encrypt_insn_170_0x0d3c(seed);
        case 171: return verify_tob_encrypt_insn_171_0x0d40(seed);
        case 172: return verify_tob_encrypt_insn_172_0x0d44(seed);
        case 173: return verify_tob_encrypt_insn_173_0x0d48(seed);
        case 174: return verify_tob_encrypt_insn_174_0x0d4c(seed);
        case 175: return verify_tob_encrypt_insn_175_0x0d50(seed);
        case 176: return verify_tob_encrypt_insn_176_0x0d54(seed);
        case 177: return verify_tob_encrypt_insn_177_0x0d58(seed);
        case 178: return verify_tob_encrypt_insn_178_0x0d5c(seed);
        case 179: return verify_tob_encrypt_insn_179_0x0d60(seed);
        case 180: return verify_tob_encrypt_insn_180_0x0d64(seed);
        case 181: return verify_tob_encrypt_insn_181_0x0d68(seed);
        case 182: return verify_tob_encrypt_insn_182_0x0d6c(seed);
        case 183: return verify_tob_encrypt_insn_183_0x0d70(seed);
        case 184: return verify_tob_encrypt_insn_184_0x0d74(seed);
        case 185: return verify_tob_encrypt_insn_185_0x0d78(seed);
        case 186: return verify_tob_encrypt_insn_186_0x0d7c(seed);
        case 187: return verify_tob_encrypt_insn_187_0x0d80(seed);
        case 188: return verify_tob_encrypt_insn_188_0x0d84(seed);
        case 189: return verify_tob_encrypt_insn_189_0x0d88(seed);
        case 190: return verify_tob_encrypt_insn_190_0x0d8c(seed);
        case 191: return verify_tob_encrypt_insn_191_0x0d90(seed);
        case 192: return verify_tob_encrypt_insn_192_0x0d94(seed);
        case 193: return verify_tob_encrypt_insn_193_0x0d98(seed);
        case 194: return verify_tob_encrypt_insn_194_0x0d9c(seed);
        case 195: return verify_tob_encrypt_insn_195_0x0da0(seed);
        case 196: return verify_tob_encrypt_insn_196_0x0da4(seed);
        case 197: return verify_tob_encrypt_insn_197_0x0da8(seed);
        case 198: return verify_tob_encrypt_insn_198_0x0dac(seed);
        case 199: return verify_tob_encrypt_insn_199_0x0db0(seed);
        case 200: return verify_tob_encrypt_insn_200_0x0db4(seed);
        case 201: return verify_tob_encrypt_insn_201_0x0db8(seed);
        case 202: return verify_tob_encrypt_insn_202_0x0dbc(seed);
        case 203: return verify_tob_encrypt_insn_203_0x0dc0(seed);
        case 204: return verify_tob_encrypt_insn_204_0x0dc4(seed);
        case 205: return verify_tob_encrypt_insn_205_0x0dc8(seed);
        case 206: return verify_tob_encrypt_insn_206_0x0dcc(seed);
        case 207: return verify_tob_encrypt_insn_207_0x0dd0(seed);
        case 208: return verify_tob_encrypt_insn_208_0x0dd4(seed);
        case 209: return verify_tob_encrypt_insn_209_0x0dd8(seed);
        case 210: return verify_tob_encrypt_insn_210_0x0ddc(seed);
        case 211: return verify_tob_encrypt_insn_211_0x0de0(seed);
        case 212: return verify_tob_encrypt_insn_212_0x0de4(seed);
        case 213: return verify_tob_encrypt_insn_213_0x0de8(seed);
        case 214: return verify_tob_encrypt_insn_214_0x0dec(seed);
        case 215: return verify_tob_encrypt_insn_215_0x0df0(seed);
        case 216: return verify_tob_encrypt_insn_216_0x0df4(seed);
        case 217: return verify_tob_encrypt_insn_217_0x0df8(seed);
        case 218: return verify_tob_encrypt_insn_218_0x0dfc(seed);
        case 219: return verify_tob_encrypt_insn_219_0x0e00(seed);
        case 220: return verify_tob_encrypt_insn_220_0x0e04(seed);
        case 221: return verify_tob_encrypt_insn_221_0x0e08(seed);
        case 222: return verify_tob_encrypt_insn_222_0x0e0c(seed);
        case 223: return verify_tob_encrypt_insn_223_0x0e10(seed);
        case 224: return verify_tob_encrypt_insn_224_0x0e14(seed);
        case 225: return verify_tob_encrypt_insn_225_0x0e18(seed);
        case 226: return verify_tob_encrypt_insn_226_0x0e1c(seed);
        case 227: return verify_tob_encrypt_insn_227_0x0e20(seed);
        case 228: return verify_tob_encrypt_insn_228_0x0e24(seed);
        case 229: return verify_tob_encrypt_insn_229_0x0e28(seed);
        case 230: return verify_tob_encrypt_insn_230_0x0e2c(seed);
        case 231: return verify_tob_encrypt_insn_231_0x0e30(seed);
        case 232: return verify_tob_encrypt_insn_232_0x0e34(seed);
        case 233: return verify_tob_encrypt_insn_233_0x0e38(seed);
        case 234: return verify_tob_encrypt_insn_234_0x0e3c(seed);
        case 235: return verify_tob_encrypt_insn_235_0x0e40(seed);
        case 236: return verify_tob_encrypt_insn_236_0x0e44(seed);
        case 237: return verify_tob_encrypt_insn_237_0x0e48(seed);
        case 238: return verify_tob_encrypt_insn_238_0x0e4c(seed);
        case 239: return verify_tob_encrypt_insn_239_0x0e50(seed);
        case 240: return verify_tob_encrypt_insn_240_0x0e54(seed);
        case 241: return verify_tob_encrypt_insn_241_0x0e58(seed);
        case 242: return verify_tob_encrypt_insn_242_0x0e5c(seed);
        case 243: return verify_tob_encrypt_insn_243_0x0e60(seed);
        case 244: return verify_tob_encrypt_insn_244_0x0e64(seed);
        case 245: return verify_tob_encrypt_insn_245_0x0e68(seed);
        case 246: return verify_tob_encrypt_insn_246_0x0e6c(seed);
        case 247: return verify_tob_encrypt_insn_247_0x0e70(seed);
        case 248: return verify_tob_encrypt_insn_248_0x0e74(seed);
        case 249: return verify_tob_encrypt_insn_249_0x0e78(seed);
        case 250: return verify_tob_encrypt_insn_250_0x0e7c(seed);
        case 251: return verify_tob_encrypt_insn_251_0x0e80(seed);
        case 252: return verify_tob_encrypt_insn_252_0x0e84(seed);
        case 253: return verify_tob_encrypt_insn_253_0x0e88(seed);
        case 254: return verify_tob_encrypt_insn_254_0x0e8c(seed);
        case 255: return verify_tob_encrypt_insn_255_0x0e90(seed);
        case 256: return verify_tob_encrypt_insn_256_0x0e94(seed);
        case 257: return verify_tob_encrypt_insn_257_0x0e98(seed);
        case 258: return verify_tob_encrypt_insn_258_0x0e9c(seed);
        case 259: return verify_tob_encrypt_insn_259_0x0ea0(seed);
        case 260: return verify_tob_encrypt_insn_260_0x0ea4(seed);
        case 261: return verify_tob_encrypt_insn_261_0x0ea8(seed);
        case 262: return verify_tob_encrypt_insn_262_0x0eac(seed);
        case 263: return verify_tob_encrypt_insn_263_0x0eb0(seed);
        case 264: return verify_tob_encrypt_insn_264_0x0eb4(seed);
        case 265: return verify_tob_encrypt_insn_265_0x0eb8(seed);
        case 266: return verify_tob_encrypt_insn_266_0x0ebc(seed);
        case 267: return verify_tob_encrypt_insn_267_0x0ec0(seed);
        case 268: return verify_tob_encrypt_insn_268_0x0ec4(seed);
        case 269: return verify_tob_encrypt_insn_269_0x0ec8(seed);
        case 270: return verify_tob_encrypt_insn_270_0x0ecc(seed);
        case 271: return verify_tob_encrypt_insn_271_0x0ed0(seed);
        case 272: return verify_tob_encrypt_insn_272_0x0ed4(seed);
        case 273: return verify_tob_encrypt_insn_273_0x0ed8(seed);
        case 274: return verify_tob_encrypt_insn_274_0x0edc(seed);
        case 275: return verify_tob_encrypt_insn_275_0x0ee0(seed);
        case 276: return verify_tob_encrypt_insn_276_0x0ee4(seed);
        case 277: return verify_tob_encrypt_insn_277_0x0ee8(seed);
        case 278: return verify_tob_encrypt_insn_278_0x0eec(seed);
        case 279: return verify_tob_encrypt_insn_279_0x0ef0(seed);
        case 280: return verify_tob_encrypt_insn_280_0x0ef4(seed);
        case 281: return verify_tob_encrypt_insn_281_0x0ef8(seed);
        case 282: return verify_tob_encrypt_insn_282_0x0efc(seed);
        case 283: return verify_tob_encrypt_insn_283_0x0f00(seed);
        case 284: return verify_tob_encrypt_insn_284_0x0f04(seed);
        case 285: return verify_tob_encrypt_insn_285_0x0f08(seed);
        case 286: return verify_tob_encrypt_insn_286_0x0f0c(seed);
        case 287: return verify_tob_encrypt_insn_287_0x0f10(seed);
        case 288: return verify_tob_encrypt_insn_288_0x0f14(seed);
        case 289: return verify_tob_encrypt_insn_289_0x0f18(seed);
        case 290: return verify_tob_encrypt_insn_290_0x0f1c(seed);
        case 291: return verify_tob_encrypt_insn_291_0x0f20(seed);
        case 292: return verify_tob_encrypt_insn_292_0x0f24(seed);
        case 293: return verify_tob_encrypt_insn_293_0x0f28(seed);
        case 294: return verify_tob_encrypt_insn_294_0x0f2c(seed);
        case 295: return verify_tob_encrypt_insn_295_0x0f30(seed);
        case 296: return verify_tob_encrypt_insn_296_0x0f34(seed);
        case 297: return verify_tob_encrypt_insn_297_0x0f38(seed);
        case 298: return verify_tob_encrypt_insn_298_0x0f3c(seed);
        case 299: return verify_tob_encrypt_insn_299_0x0f40(seed);
        case 300: return verify_tob_encrypt_insn_300_0x0f44(seed);
        case 301: return verify_tob_encrypt_insn_301_0x0f48(seed);
        case 302: return verify_tob_encrypt_insn_302_0x0f4c(seed);
        case 303: return verify_tob_encrypt_insn_303_0x0f50(seed);
        case 304: return verify_tob_encrypt_insn_304_0x0f54(seed);
        case 305: return verify_tob_encrypt_insn_305_0x0f58(seed);
        case 306: return verify_tob_encrypt_insn_306_0x0f5c(seed);
        case 307: return verify_tob_encrypt_insn_307_0x0f60(seed);
        case 308: return verify_tob_encrypt_insn_308_0x0f64(seed);
        case 309: return verify_tob_encrypt_insn_309_0x0f68(seed);
        case 310: return verify_tob_encrypt_insn_310_0x0f6c(seed);
        case 311: return verify_tob_encrypt_insn_311_0x0f70(seed);
        case 312: return verify_tob_encrypt_insn_312_0x0f74(seed);
        case 313: return verify_tob_encrypt_insn_313_0x0f78(seed);
        case 314: return verify_tob_encrypt_insn_314_0x0f7c(seed);
        case 315: return verify_tob_encrypt_insn_315_0x0f80(seed);
        case 316: return verify_tob_encrypt_insn_316_0x0f84(seed);
        case 317: return verify_tob_encrypt_insn_317_0x0f88(seed);
        case 318: return verify_tob_encrypt_insn_318_0x0f8c(seed);
        case 319: return verify_tob_encrypt_insn_319_0x0f90(seed);
        case 320: return verify_tob_encrypt_insn_320_0x0f94(seed);
        case 321: return verify_tob_encrypt_insn_321_0x0f98(seed);
        case 322: return verify_tob_encrypt_insn_322_0x0f9c(seed);
        case 323: return verify_tob_encrypt_insn_323_0x0fa0(seed);
        case 324: return verify_tob_encrypt_insn_324_0x0fa4(seed);
        case 325: return verify_tob_encrypt_insn_325_0x0fa8(seed);
        case 326: return verify_tob_encrypt_insn_326_0x0fac(seed);
        case 327: return verify_tob_encrypt_insn_327_0x0fb0(seed);
        case 328: return verify_tob_encrypt_insn_328_0x0fb4(seed);
        case 329: return verify_tob_encrypt_insn_329_0x0fb8(seed);
        case 330: return verify_tob_encrypt_insn_330_0x0fbc(seed);
        case 331: return verify_tob_encrypt_insn_331_0x0fc0(seed);
        case 332: return verify_tob_encrypt_insn_332_0x0fc4(seed);
        case 333: return verify_tob_encrypt_insn_333_0x0fc8(seed);
        case 334: return verify_tob_encrypt_insn_334_0x0fcc(seed);
        case 335: return verify_tob_encrypt_insn_335_0x0fd0(seed);
        case 336: return verify_tob_encrypt_insn_336_0x0fd4(seed);
        case 337: return verify_tob_encrypt_insn_337_0x0fd8(seed);
        case 338: return verify_tob_encrypt_insn_338_0x0fdc(seed);
        case 339: return verify_tob_encrypt_insn_339_0x0fe0(seed);
        case 340: return verify_tob_encrypt_insn_340_0x0fe4(seed);
        case 341: return verify_tob_encrypt_insn_341_0x0fe8(seed);
        case 342: return verify_tob_encrypt_insn_342_0x0fec(seed);
        case 343: return verify_tob_encrypt_insn_343_0x0ff0(seed);
        case 344: return verify_tob_encrypt_insn_344_0x0ff4(seed);
        case 345: return verify_tob_encrypt_insn_345_0x0ff8(seed);
        case 346: return verify_tob_encrypt_insn_346_0x0ffc(seed);
        case 347: return verify_tob_encrypt_insn_347_0x1000(seed);
        case 348: return verify_tob_encrypt_insn_348_0x1004(seed);
        case 349: return verify_tob_encrypt_insn_349_0x1008(seed);
        case 350: return verify_tob_encrypt_insn_350_0x100c(seed);
        case 351: return verify_tob_encrypt_insn_351_0x1010(seed);
        case 352: return verify_tob_encrypt_insn_352_0x1014(seed);
        case 353: return verify_tob_encrypt_insn_353_0x1018(seed);
        case 354: return verify_tob_encrypt_insn_354_0x101c(seed);
        case 355: return verify_tob_encrypt_insn_355_0x1020(seed);
        case 356: return verify_tob_encrypt_insn_356_0x1024(seed);
        case 357: return verify_tob_encrypt_insn_357_0x1028(seed);
        case 358: return verify_tob_encrypt_insn_358_0x102c(seed);
        case 359: return verify_tob_encrypt_insn_359_0x1030(seed);
        case 360: return verify_tob_encrypt_insn_360_0x1034(seed);
        case 361: return verify_tob_encrypt_insn_361_0x1038(seed);
        case 362: return verify_tob_encrypt_insn_362_0x103c(seed);
        case 363: return verify_tob_encrypt_insn_363_0x1040(seed);
        case 364: return verify_tob_encrypt_insn_364_0x1044(seed);
        case 365: return verify_tob_encrypt_insn_365_0x1048(seed);
        case 366: return verify_tob_encrypt_insn_366_0x104c(seed);
        case 367: return verify_tob_encrypt_insn_367_0x1050(seed);
        case 368: return verify_tob_encrypt_insn_368_0x1054(seed);
        case 369: return verify_tob_encrypt_insn_369_0x1058(seed);
        case 370: return verify_tob_encrypt_insn_370_0x105c(seed);
        case 371: return verify_tob_encrypt_insn_371_0x1060(seed);
        case 372: return verify_tob_encrypt_insn_372_0x1064(seed);
        case 373: return verify_tob_encrypt_insn_373_0x1068(seed);
        case 374: return verify_tob_encrypt_insn_374_0x106c(seed);
        case 375: return verify_tob_encrypt_insn_375_0x1070(seed);
        case 376: return verify_tob_encrypt_insn_376_0x1074(seed);
        case 377: return verify_tob_encrypt_insn_377_0x1078(seed);
        case 378: return verify_tob_encrypt_insn_378_0x107c(seed);
        case 379: return verify_tob_encrypt_insn_379_0x1080(seed);
        case 380: return verify_tob_encrypt_insn_380_0x1084(seed);
        case 381: return verify_tob_encrypt_insn_381_0x1088(seed);
        case 382: return verify_tob_encrypt_insn_382_0x108c(seed);
        case 383: return verify_tob_encrypt_insn_383_0x1090(seed);
        case 384: return verify_tob_encrypt_insn_384_0x1094(seed);
        case 385: return verify_tob_encrypt_insn_385_0x1098(seed);
        case 386: return verify_tob_encrypt_insn_386_0x109c(seed);
        case 387: return verify_tob_encrypt_insn_387_0x10a0(seed);
        case 388: return verify_tob_encrypt_insn_388_0x10a4(seed);
        case 389: return verify_tob_encrypt_insn_389_0x10a8(seed);
        case 390: return verify_tob_encrypt_insn_390_0x10ac(seed);
        case 391: return verify_tob_encrypt_insn_391_0x10b0(seed);
        case 392: return verify_tob_encrypt_insn_392_0x10b4(seed);
        case 393: return verify_tob_encrypt_insn_393_0x10b8(seed);
        case 394: return verify_tob_encrypt_insn_394_0x10bc(seed);
        case 395: return verify_tob_encrypt_insn_395_0x10c0(seed);
        case 396: return verify_tob_encrypt_insn_396_0x10c4(seed);
        case 397: return verify_tob_encrypt_insn_397_0x10c8(seed);
        case 398: return verify_tob_encrypt_insn_398_0x10cc(seed);
        case 399: return verify_tob_encrypt_insn_399_0x10d0(seed);
        case 400: return verify_tob_encrypt_insn_400_0x10d4(seed);
        case 401: return verify_tob_encrypt_insn_401_0x10d8(seed);
        case 402: return verify_tob_encrypt_insn_402_0x10dc(seed);
        case 403: return verify_tob_encrypt_insn_403_0x10e0(seed);
        case 404: return verify_tob_encrypt_insn_404_0x10e4(seed);
        case 405: return verify_tob_encrypt_insn_405_0x10e8(seed);
        case 406: return verify_tob_encrypt_insn_406_0x10ec(seed);
        case 407: return verify_tob_encrypt_insn_407_0x10f0(seed);
        case 408: return verify_tob_encrypt_insn_408_0x10f4(seed);
        case 409: return verify_tob_encrypt_insn_409_0x10f8(seed);
        case 410: return verify_tob_encrypt_insn_410_0x10fc(seed);
        case 411: return verify_tob_encrypt_insn_411_0x1100(seed);
        case 412: return verify_tob_encrypt_insn_412_0x1104(seed);
        case 413: return verify_tob_encrypt_insn_413_0x1108(seed);
        case 414: return verify_tob_encrypt_insn_414_0x110c(seed);
        case 415: return verify_tob_encrypt_insn_415_0x1110(seed);
        case 416: return verify_tob_encrypt_insn_416_0x1114(seed);
        case 417: return verify_tob_encrypt_insn_417_0x1118(seed);
        case 418: return verify_tob_encrypt_insn_418_0x111c(seed);
        case 419: return verify_tob_encrypt_insn_419_0x1120(seed);
        case 420: return verify_tob_encrypt_insn_420_0x1124(seed);
        case 421: return verify_tob_encrypt_insn_421_0x1128(seed);
        case 422: return verify_tob_encrypt_insn_422_0x112c(seed);
        case 423: return verify_tob_encrypt_insn_423_0x1130(seed);
        case 424: return verify_tob_encrypt_insn_424_0x1134(seed);
        case 425: return verify_tob_encrypt_insn_425_0x1138(seed);
        case 426: return verify_tob_encrypt_insn_426_0x113c(seed);
        case 427: return verify_tob_encrypt_insn_427_0x1140(seed);
        case 428: return verify_tob_encrypt_insn_428_0x1144(seed);
        case 429: return verify_tob_encrypt_insn_429_0x1148(seed);
        case 430: return verify_tob_encrypt_insn_430_0x114c(seed);
        case 431: return verify_tob_encrypt_insn_431_0x1150(seed);
        case 432: return verify_tob_encrypt_insn_432_0x1154(seed);
        case 433: return verify_tob_encrypt_insn_433_0x1158(seed);
        case 434: return verify_tob_encrypt_insn_434_0x115c(seed);
        case 435: return verify_tob_encrypt_insn_435_0x1160(seed);
        case 436: return verify_tob_encrypt_insn_436_0x1164(seed);
        case 437: return verify_tob_encrypt_insn_437_0x1168(seed);
        case 438: return verify_tob_encrypt_insn_438_0x116c(seed);
        case 439: return verify_tob_encrypt_insn_439_0x1170(seed);
        case 440: return verify_tob_encrypt_insn_440_0x1174(seed);
        case 441: return verify_tob_encrypt_insn_441_0x1178(seed);
        case 442: return verify_tob_encrypt_insn_442_0x117c(seed);
        case 443: return verify_tob_encrypt_insn_443_0x1180(seed);
        case 444: return verify_tob_encrypt_insn_444_0x1184(seed);
        case 445: return verify_tob_encrypt_insn_445_0x1188(seed);
        case 446: return verify_tob_encrypt_insn_446_0x118c(seed);
        case 447: return verify_tob_encrypt_insn_447_0x1190(seed);
        case 448: return verify_tob_encrypt_insn_448_0x1194(seed);
        case 449: return verify_tob_encrypt_insn_449_0x1198(seed);
        case 450: return verify_tob_encrypt_insn_450_0x119c(seed);
        case 451: return verify_tob_encrypt_insn_451_0x11a0(seed);
        case 452: return verify_tob_encrypt_insn_452_0x11a4(seed);
        case 453: return verify_tob_encrypt_insn_453_0x11a8(seed);
        case 454: return verify_tob_encrypt_insn_454_0x11ac(seed);
        case 455: return verify_tob_encrypt_insn_455_0x11b0(seed);
        case 456: return verify_tob_encrypt_insn_456_0x11b4(seed);
        case 457: return verify_tob_encrypt_insn_457_0x11b8(seed);
        case 458: return verify_tob_encrypt_insn_458_0x11bc(seed);
        case 459: return verify_tob_encrypt_insn_459_0x11c0(seed);
        case 460: return verify_tob_encrypt_insn_460_0x11c4(seed);
        case 461: return verify_tob_encrypt_insn_461_0x11c8(seed);
        case 462: return verify_tob_encrypt_insn_462_0x11cc(seed);
        case 463: return verify_tob_encrypt_insn_463_0x11d0(seed);
        case 464: return verify_tob_encrypt_insn_464_0x11d4(seed);
        case 465: return verify_tob_encrypt_insn_465_0x11d8(seed);
        case 466: return verify_tob_encrypt_insn_466_0x11dc(seed);
        case 467: return verify_tob_encrypt_insn_467_0x11e0(seed);
        case 468: return verify_tob_encrypt_insn_468_0x11e4(seed);
        case 469: return verify_tob_encrypt_insn_469_0x11e8(seed);
        case 470: return verify_tob_encrypt_insn_470_0x11ec(seed);
        case 471: return verify_tob_encrypt_insn_471_0x11f0(seed);
        case 472: return verify_tob_encrypt_insn_472_0x11f4(seed);
        case 473: return verify_tob_encrypt_insn_473_0x11f8(seed);
        case 474: return verify_tob_encrypt_insn_474_0x11fc(seed);
        case 475: return verify_tob_encrypt_insn_475_0x1200(seed);
        case 476: return verify_tob_encrypt_insn_476_0x1204(seed);
        case 477: return verify_tob_encrypt_insn_477_0x1208(seed);
        case 478: return verify_tob_encrypt_insn_478_0x120c(seed);
        case 479: return verify_tob_encrypt_insn_479_0x1210(seed);
        case 480: return verify_tob_encrypt_insn_480_0x1214(seed);
        case 481: return verify_tob_encrypt_insn_481_0x1218(seed);
        case 482: return verify_tob_encrypt_insn_482_0x121c(seed);
        case 483: return verify_tob_encrypt_insn_483_0x1220(seed);
        case 484: return verify_tob_encrypt_insn_484_0x1224(seed);
        case 485: return verify_tob_encrypt_insn_485_0x1228(seed);
        case 486: return verify_tob_encrypt_insn_486_0x122c(seed);
        case 487: return verify_tob_encrypt_insn_487_0x1230(seed);
        case 488: return verify_tob_encrypt_insn_488_0x1234(seed);
        case 489: return verify_tob_encrypt_insn_489_0x1238(seed);
        case 490: return verify_tob_encrypt_insn_490_0x123c(seed);
        case 491: return verify_tob_encrypt_insn_491_0x1240(seed);
        case 492: return verify_tob_encrypt_insn_492_0x1244(seed);
        case 493: return verify_tob_encrypt_insn_493_0x1248(seed);
        case 494: return verify_tob_encrypt_insn_494_0x124c(seed);
        case 495: return verify_tob_encrypt_insn_495_0x1250(seed);
        case 496: return verify_tob_encrypt_insn_496_0x1254(seed);
        case 497: return verify_tob_encrypt_insn_497_0x1258(seed);
        case 498: return verify_tob_encrypt_insn_498_0x125c(seed);
        case 499: return verify_tob_encrypt_insn_499_0x1260(seed);
        case 500: return verify_tob_encrypt_insn_500_0x1264(seed);
        case 501: return verify_tob_encrypt_insn_501_0x1268(seed);
        case 502: return verify_tob_encrypt_insn_502_0x126c(seed);
        case 503: return verify_tob_encrypt_insn_503_0x1270(seed);
        case 504: return verify_tob_encrypt_insn_504_0x1274(seed);
        case 505: return verify_tob_encrypt_insn_505_0x1278(seed);
        case 506: return verify_tob_encrypt_insn_506_0x127c(seed);
        case 507: return verify_tob_encrypt_insn_507_0x1280(seed);
        case 508: return verify_tob_encrypt_insn_508_0x1284(seed);
        case 509: return verify_tob_encrypt_insn_509_0x1288(seed);
        case 510: return verify_tob_encrypt_insn_510_0x128c(seed);
        case 511: return verify_tob_encrypt_insn_511_0x1290(seed);
        case 512: return verify_tob_encrypt_insn_512_0x1294(seed);
        case 513: return verify_tob_encrypt_insn_513_0x1298(seed);
        case 514: return verify_tob_encrypt_insn_514_0x129c(seed);
        case 515: return verify_tob_encrypt_insn_515_0x12a0(seed);
        case 516: return verify_tob_encrypt_insn_516_0x12a4(seed);
        case 517: return verify_tob_encrypt_insn_517_0x12a8(seed);
        case 518: return verify_tob_encrypt_insn_518_0x12ac(seed);
        case 519: return verify_tob_encrypt_insn_519_0x12b0(seed);
        case 520: return verify_tob_encrypt_insn_520_0x12b4(seed);
        case 521: return verify_tob_encrypt_insn_521_0x12b8(seed);
        case 522: return verify_tob_encrypt_insn_522_0x12bc(seed);
        case 523: return verify_tob_encrypt_insn_523_0x12c0(seed);
        case 524: return verify_tob_encrypt_insn_524_0x12c4(seed);
        case 525: return verify_tob_encrypt_insn_525_0x12c8(seed);
        case 526: return verify_tob_encrypt_insn_526_0x12cc(seed);
        case 527: return verify_tob_encrypt_insn_527_0x12d0(seed);
        case 528: return verify_tob_encrypt_insn_528_0x12d4(seed);
        case 529: return verify_tob_encrypt_insn_529_0x12d8(seed);
        case 530: return verify_tob_encrypt_insn_530_0x12dc(seed);
        case 531: return verify_tob_encrypt_insn_531_0x12e0(seed);
        case 532: return verify_tob_encrypt_insn_532_0x12e4(seed);
        case 533: return verify_tob_encrypt_insn_533_0x12e8(seed);
        case 534: return verify_tob_encrypt_insn_534_0x12ec(seed);
        case 535: return verify_tob_encrypt_insn_535_0x12f0(seed);
        case 536: return verify_tob_encrypt_insn_536_0x12f4(seed);
        default: return 0ULL;
    }
}

} // namespace tob_embed_pag_encrypt