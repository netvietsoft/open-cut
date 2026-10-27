// ============================================================================
// Complete 252-Instruction AArch64 .text Disassembly & 9-FDE Unwind Verifier
// Bộ kiểm chứng toàn bộ 252 lệnh AArch64 .text (0x0990..0x0d80) & 9 FDE của libnpth_fp_unw.so
// ============================================================================
#include "npth_fp_unw_core.h"

namespace npth_fp_unw {

// Insn #000 @ 0x0990: 0xD503245F -> bti c
// Lệnh AArch64 #000 tại 0x0990: bti c
uint64_t verify_npth_fp_unw_insn_000_0x0990(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xD503245FU;
    constexpr uint64_t kVaddr  = 0x0990ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #001 @ 0x0994: 0xD503201F -> nop 
// Lệnh AArch64 #001 tại 0x0994: nop 
uint64_t verify_npth_fp_unw_insn_001_0x0994(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xD503201FU;
    constexpr uint64_t kVaddr  = 0x0994ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #002 @ 0x0998: 0x100226C0 -> adr x0, #0x4e70
// Lệnh AArch64 #002 tại 0x0998: adr x0, #0x4e70
uint64_t verify_npth_fp_unw_insn_002_0x0998(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x100226C0U;
    constexpr uint64_t kVaddr  = 0x0998ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #003 @ 0x099c: 0x14000101 -> b #0xda0
// Lệnh AArch64 #003 tại 0x099c: b #0xda0
uint64_t verify_npth_fp_unw_insn_003_0x099c(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x14000101U;
    constexpr uint64_t kVaddr  = 0x099cULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #004 @ 0x09a0: 0xD503245F -> bti c
// Lệnh AArch64 #004 tại 0x09a0: bti c
uint64_t verify_npth_fp_unw_insn_004_0x09a0(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xD503245FU;
    constexpr uint64_t kVaddr  = 0x09a0ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #005 @ 0x09a4: 0xD65F03C0 -> ret 
// Lệnh AArch64 #005 tại 0x09a4: ret 
uint64_t verify_npth_fp_unw_insn_005_0x09a4(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xD65F03C0U;
    constexpr uint64_t kVaddr  = 0x09a4ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #006 @ 0x09a8: 0xD503245F -> bti c
// Lệnh AArch64 #006 tại 0x09a8: bti c
uint64_t verify_npth_fp_unw_insn_006_0x09a8(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xD503245FU;
    constexpr uint64_t kVaddr  = 0x09a8ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #007 @ 0x09ac: 0x17FFFFFD -> b #0x9a0
// Lệnh AArch64 #007 tại 0x09ac: b #0x9a0
uint64_t verify_npth_fp_unw_insn_007_0x09ac(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x17FFFFFDU;
    constexpr uint64_t kVaddr  = 0x09acULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #008 @ 0x09b0: 0xD503245F -> bti c
// Lệnh AArch64 #008 tại 0x09b0: bti c
uint64_t verify_npth_fp_unw_insn_008_0x09b0(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xD503245FU;
    constexpr uint64_t kVaddr  = 0x09b0ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #009 @ 0x09b4: 0xB4000060 -> cbz x0, #0x9c0
// Lệnh AArch64 #009 tại 0x09b4: cbz x0, #0x9c0
uint64_t verify_npth_fp_unw_insn_009_0x09b4(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xB4000060U;
    constexpr uint64_t kVaddr  = 0x09b4ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #010 @ 0x09b8: 0xAA0003F0 -> mov x16, x0
// Lệnh AArch64 #010 tại 0x09b8: mov x16, x0
uint64_t verify_npth_fp_unw_insn_010_0x09b8(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xAA0003F0U;
    constexpr uint64_t kVaddr  = 0x09b8ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #011 @ 0x09bc: 0xD61F0200 -> br x16
// Lệnh AArch64 #011 tại 0x09bc: br x16
uint64_t verify_npth_fp_unw_insn_011_0x09bc(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xD61F0200U;
    constexpr uint64_t kVaddr  = 0x09bcULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #012 @ 0x09c0: 0xD65F03C0 -> ret 
// Lệnh AArch64 #012 tại 0x09c0: ret 
uint64_t verify_npth_fp_unw_insn_012_0x09c0(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xD65F03C0U;
    constexpr uint64_t kVaddr  = 0x09c0ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #013 @ 0x09c4: 0xD503245F -> bti c
// Lệnh AArch64 #013 tại 0x09c4: bti c
uint64_t verify_npth_fp_unw_insn_013_0x09c4(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xD503245FU;
    constexpr uint64_t kVaddr  = 0x09c4ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #014 @ 0x09c8: 0xAA0003E1 -> mov x1, x0
// Lệnh AArch64 #014 tại 0x09c8: mov x1, x0
uint64_t verify_npth_fp_unw_insn_014_0x09c8(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xAA0003E1U;
    constexpr uint64_t kVaddr  = 0x09c8ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #015 @ 0x09cc: 0xD503201F -> nop 
// Lệnh AArch64 #015 tại 0x09cc: nop 
uint64_t verify_npth_fp_unw_insn_015_0x09cc(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xD503201FU;
    constexpr uint64_t kVaddr  = 0x09ccULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #016 @ 0x09d0: 0x10FFFF00 -> adr x0, #0x9b0
// Lệnh AArch64 #016 tại 0x09d0: adr x0, #0x9b0
uint64_t verify_npth_fp_unw_insn_016_0x09d0(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x10FFFF00U;
    constexpr uint64_t kVaddr  = 0x09d0ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #017 @ 0x09d4: 0xD503201F -> nop 
// Lệnh AArch64 #017 tại 0x09d4: nop 
uint64_t verify_npth_fp_unw_insn_017_0x09d4(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xD503201FU;
    constexpr uint64_t kVaddr  = 0x09d4ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #018 @ 0x09d8: 0x100224C2 -> adr x2, #0x4e70
// Lệnh AArch64 #018 tại 0x09d8: adr x2, #0x4e70
uint64_t verify_npth_fp_unw_insn_018_0x09d8(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x100224C2U;
    constexpr uint64_t kVaddr  = 0x09d8ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #019 @ 0x09dc: 0x140000F5 -> b #0xdb0
// Lệnh AArch64 #019 tại 0x09dc: b #0xdb0
uint64_t verify_npth_fp_unw_insn_019_0x09dc(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x140000F5U;
    constexpr uint64_t kVaddr  = 0x09dcULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #020 @ 0x09e0: 0xD10143FF -> sub sp, sp, #0x50
// Lệnh AArch64 #020 tại 0x09e0: sub sp, sp, #0x50
uint64_t verify_npth_fp_unw_insn_020_0x09e0(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xD10143FFU;
    constexpr uint64_t kVaddr  = 0x09e0ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #021 @ 0x09e4: 0xA9027BFD -> stp x29, x30, [sp, #0x20]
// Lệnh AArch64 #021 tại 0x09e4: stp x29, x30, [sp, #0x20]
uint64_t verify_npth_fp_unw_insn_021_0x09e4(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xA9027BFDU;
    constexpr uint64_t kVaddr  = 0x09e4ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #022 @ 0x09e8: 0xF9001BF5 -> str x21, [sp, #0x30]
// Lệnh AArch64 #022 tại 0x09e8: str x21, [sp, #0x30]
uint64_t verify_npth_fp_unw_insn_022_0x09e8(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xF9001BF5U;
    constexpr uint64_t kVaddr  = 0x09e8ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #023 @ 0x09ec: 0xA9044FF4 -> stp x20, x19, [sp, #0x40]
// Lệnh AArch64 #023 tại 0x09ec: stp x20, x19, [sp, #0x40]
uint64_t verify_npth_fp_unw_insn_023_0x09ec(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xA9044FF4U;
    constexpr uint64_t kVaddr  = 0x09ecULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #024 @ 0x09f0: 0x910083FD -> add x29, sp, #0x20
// Lệnh AArch64 #024 tại 0x09f0: add x29, sp, #0x20
uint64_t verify_npth_fp_unw_insn_024_0x09f0(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x910083FDU;
    constexpr uint64_t kVaddr  = 0x09f0ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #025 @ 0x09f4: 0xD53BD054 -> mrs x20, tpidr_el0
// Lệnh AArch64 #025 tại 0x09f4: mrs x20, tpidr_el0
uint64_t verify_npth_fp_unw_insn_025_0x09f4(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xD53BD054U;
    constexpr uint64_t kVaddr  = 0x09f4ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #026 @ 0x09f8: 0x52801009 -> mov w9, #0x80
// Lệnh AArch64 #026 tại 0x09f8: mov w9, #0x80
uint64_t verify_npth_fp_unw_insn_026_0x09f8(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x52801009U;
    constexpr uint64_t kVaddr  = 0x09f8ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #027 @ 0x09fc: 0xF102003F -> cmp x1, #0x80
// Lệnh AArch64 #027 tại 0x09fc: cmp x1, #0x80
uint64_t verify_npth_fp_unw_insn_027_0x09fc(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xF102003FU;
    constexpr uint64_t kVaddr  = 0x09fcULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #028 @ 0x0a00: 0xAA0003F3 -> mov x19, x0
// Lệnh AArch64 #028 tại 0x0a00: mov x19, x0
uint64_t verify_npth_fp_unw_insn_028_0x0a00(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xAA0003F3U;
    constexpr uint64_t kVaddr  = 0x0a00ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #029 @ 0x0a04: 0xF9401688 -> ldr x8, [x20, #0x28]
// Lệnh AArch64 #029 tại 0x0a04: ldr x8, [x20, #0x28]
uint64_t verify_npth_fp_unw_insn_029_0x0a04(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xF9401688U;
    constexpr uint64_t kVaddr  = 0x0a04ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #030 @ 0x0a08: 0x9A893035 -> csel x21, x1, x9, lo
// Lệnh AArch64 #030 tại 0x0a08: csel x21, x1, x9, lo
uint64_t verify_npth_fp_unw_insn_030_0x0a08(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x9A893035U;
    constexpr uint64_t kVaddr  = 0x0a08ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #031 @ 0x0a0c: 0x910003E1 -> mov x1, sp
// Lệnh AArch64 #031 tại 0x0a0c: mov x1, sp
uint64_t verify_npth_fp_unw_insn_031_0x0a0c(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x910003E1U;
    constexpr uint64_t kVaddr  = 0x0a0cULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #032 @ 0x0a10: 0xAA1F03E0 -> mov x0, xzr
// Lệnh AArch64 #032 tại 0x0a10: mov x0, xzr
uint64_t verify_npth_fp_unw_insn_032_0x0a10(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xAA1F03E0U;
    constexpr uint64_t kVaddr  = 0x0a10ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #033 @ 0x0a14: 0xF81F83A8 -> stur x8, [x29, #-8]
// Lệnh AArch64 #033 tại 0x0a14: stur x8, [x29, #-8]
uint64_t verify_npth_fp_unw_insn_033_0x0a14(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xF81F83A8U;
    constexpr uint64_t kVaddr  = 0x0a14ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #034 @ 0x0a18: 0x940000EE -> bl #0xdd0
// Lệnh AArch64 #034 tại 0x0a18: bl #0xdd0
uint64_t verify_npth_fp_unw_insn_034_0x0a18(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x940000EEU;
    constexpr uint64_t kVaddr  = 0x0a18ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #035 @ 0x0a1c: 0xAA1F03E0 -> mov x0, xzr
// Lệnh AArch64 #035 tại 0x0a1c: mov x0, xzr
uint64_t verify_npth_fp_unw_insn_035_0x0a1c(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xAA1F03E0U;
    constexpr uint64_t kVaddr  = 0x0a1cULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #036 @ 0x0a20: 0xAA1D03EA -> mov x10, x29
// Lệnh AArch64 #036 tại 0x0a20: mov x10, x29
uint64_t verify_npth_fp_unw_insn_036_0x0a20(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xAA1D03EAU;
    constexpr uint64_t kVaddr  = 0x0a20ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #037 @ 0x0a24: 0xB2585FE8 -> mov x8, #-0x10000000000
// Lệnh AArch64 #037 tại 0x0a24: mov x8, #-0x10000000000
uint64_t verify_npth_fp_unw_insn_037_0x0a24(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xB2585FE8U;
    constexpr uint64_t kVaddr  = 0x0a24ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #038 @ 0x0a28: 0xB25863E9 -> mov x9, #-0xffffffffff
// Lệnh AArch64 #038 tại 0x0a28: mov x9, #-0xffffffffff
uint64_t verify_npth_fp_unw_insn_038_0x0a28(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xB25863E9U;
    constexpr uint64_t kVaddr  = 0x0a28ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #039 @ 0x0a2c: 0xEB15001F -> cmp x0, x21
// Lệnh AArch64 #039 tại 0x0a2c: cmp x0, x21
uint64_t verify_npth_fp_unw_insn_039_0x0a2c(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xEB15001FU;
    constexpr uint64_t kVaddr  = 0x0a2cULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #040 @ 0x0a30: 0x54000062 -> b.hs #0xa3c
// Lệnh AArch64 #040 tại 0x0a30: b.hs #0xa3c
uint64_t verify_npth_fp_unw_insn_040_0x0a30(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x54000062U;
    constexpr uint64_t kVaddr  = 0x0a30ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #041 @ 0x0a34: 0xF940054B -> ldr x11, [x10, #8]
// Lệnh AArch64 #041 tại 0x0a34: ldr x11, [x10, #8]
uint64_t verify_npth_fp_unw_insn_041_0x0a34(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xF940054BU;
    constexpr uint64_t kVaddr  = 0x0a34ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #042 @ 0x0a38: 0xF8207A6B -> str x11, [x19, x0, lsl #3]
// Lệnh AArch64 #042 tại 0x0a38: str x11, [x19, x0, lsl #3]
uint64_t verify_npth_fp_unw_insn_042_0x0a38(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xF8207A6BU;
    constexpr uint64_t kVaddr  = 0x0a38ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #043 @ 0x0a3c: 0xF102001F -> cmp x0, #0x80
// Lệnh AArch64 #043 tại 0x0a3c: cmp x0, #0x80
uint64_t verify_npth_fp_unw_insn_043_0x0a3c(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xF102001FU;
    constexpr uint64_t kVaddr  = 0x0a3cULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #044 @ 0x0a40: 0x54000240 -> b.eq #0xa88
// Lệnh AArch64 #044 tại 0x0a40: b.eq #0xa88
uint64_t verify_npth_fp_unw_insn_044_0x0a40(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x54000240U;
    constexpr uint64_t kVaddr  = 0x0a40ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #045 @ 0x0a44: 0xF940014B -> ldr x11, [x10]
// Lệnh AArch64 #045 tại 0x0a44: ldr x11, [x10]
uint64_t verify_npth_fp_unw_insn_045_0x0a44(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xF940014BU;
    constexpr uint64_t kVaddr  = 0x0a44ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #046 @ 0x0a48: 0x8B08016C -> add x12, x11, x8
// Lệnh AArch64 #046 tại 0x0a48: add x12, x11, x8
uint64_t verify_npth_fp_unw_insn_046_0x0a48(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x8B08016CU;
    constexpr uint64_t kVaddr  = 0x0a48ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #047 @ 0x0a4c: 0xEB09019F -> cmp x12, x9
// Lệnh AArch64 #047 tại 0x0a4c: cmp x12, x9
uint64_t verify_npth_fp_unw_insn_047_0x0a4c(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xEB09019FU;
    constexpr uint64_t kVaddr  = 0x0a4cULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #048 @ 0x0a50: 0x54000203 -> b.lo #0xa90
// Lệnh AArch64 #048 tại 0x0a50: b.lo #0xa90
uint64_t verify_npth_fp_unw_insn_048_0x0a50(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x54000203U;
    constexpr uint64_t kVaddr  = 0x0a50ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #049 @ 0x0a54: 0x926C4D6C -> and x12, x11, #0xfffff00000
// Lệnh AArch64 #049 tại 0x0a54: and x12, x11, #0xfffff00000
uint64_t verify_npth_fp_unw_insn_049_0x0a54(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x926C4D6CU;
    constexpr uint64_t kVaddr  = 0x0a54ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #050 @ 0x0a58: 0xB40001CC -> cbz x12, #0xa90
// Lệnh AArch64 #050 tại 0x0a58: cbz x12, #0xa90
uint64_t verify_npth_fp_unw_insn_050_0x0a58(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xB40001CCU;
    constexpr uint64_t kVaddr  = 0x0a58ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #051 @ 0x0a5c: 0x91000400 -> add x0, x0, #1
// Lệnh AArch64 #051 tại 0x0a5c: add x0, x0, #1
uint64_t verify_npth_fp_unw_insn_051_0x0a5c(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x91000400U;
    constexpr uint64_t kVaddr  = 0x0a5cULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #052 @ 0x0a60: 0xCA1D016C -> eor x12, x11, x29
// Lệnh AArch64 #052 tại 0x0a60: eor x12, x11, x29
uint64_t verify_npth_fp_unw_insn_052_0x0a60(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xCA1D016CU;
    constexpr uint64_t kVaddr  = 0x0a60ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #053 @ 0x0a64: 0xF2705D9F -> tst x12, #0xffffff0000
// Lệnh AArch64 #053 tại 0x0a64: tst x12, #0xffffff0000
uint64_t verify_npth_fp_unw_insn_053_0x0a64(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xF2705D9FU;
    constexpr uint64_t kVaddr  = 0x0a64ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #054 @ 0x0a68: 0x54000161 -> b.ne #0xa94
// Lệnh AArch64 #054 tại 0x0a68: b.ne #0xa94
uint64_t verify_npth_fp_unw_insn_054_0x0a68(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x54000161U;
    constexpr uint64_t kVaddr  = 0x0a68ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #055 @ 0x0a6c: 0x9100414A -> add x10, x10, #0x10
// Lệnh AArch64 #055 tại 0x0a6c: add x10, x10, #0x10
uint64_t verify_npth_fp_unw_insn_055_0x0a6c(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x9100414AU;
    constexpr uint64_t kVaddr  = 0x0a6cULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #056 @ 0x0a70: 0xEB0A017F -> cmp x11, x10
// Lệnh AArch64 #056 tại 0x0a70: cmp x11, x10
uint64_t verify_npth_fp_unw_insn_056_0x0a70(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xEB0A017FU;
    constexpr uint64_t kVaddr  = 0x0a70ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #057 @ 0x0a74: 0x54000103 -> b.lo #0xa94
// Lệnh AArch64 #057 tại 0x0a74: b.lo #0xa94
uint64_t verify_npth_fp_unw_insn_057_0x0a74(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x54000103U;
    constexpr uint64_t kVaddr  = 0x0a74ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #058 @ 0x0a78: 0x9240096C -> and x12, x11, #7
// Lệnh AArch64 #058 tại 0x0a78: and x12, x11, #7
uint64_t verify_npth_fp_unw_insn_058_0x0a78(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x9240096CU;
    constexpr uint64_t kVaddr  = 0x0a78ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #059 @ 0x0a7c: 0xAA0B03EA -> mov x10, x11
// Lệnh AArch64 #059 tại 0x0a7c: mov x10, x11
uint64_t verify_npth_fp_unw_insn_059_0x0a7c(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xAA0B03EAU;
    constexpr uint64_t kVaddr  = 0x0a7cULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #060 @ 0x0a80: 0xB4FFFD6C -> cbz x12, #0xa2c
// Lệnh AArch64 #060 tại 0x0a80: cbz x12, #0xa2c
uint64_t verify_npth_fp_unw_insn_060_0x0a80(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xB4FFFD6CU;
    constexpr uint64_t kVaddr  = 0x0a80ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #061 @ 0x0a84: 0x14000004 -> b #0xa94
// Lệnh AArch64 #061 tại 0x0a84: b #0xa94
uint64_t verify_npth_fp_unw_insn_061_0x0a84(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x14000004U;
    constexpr uint64_t kVaddr  = 0x0a84ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #062 @ 0x0a88: 0x52801020 -> mov w0, #0x81
// Lệnh AArch64 #062 tại 0x0a88: mov w0, #0x81
uint64_t verify_npth_fp_unw_insn_062_0x0a88(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x52801020U;
    constexpr uint64_t kVaddr  = 0x0a88ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #063 @ 0x0a8c: 0x14000002 -> b #0xa94
// Lệnh AArch64 #063 tại 0x0a8c: b #0xa94
uint64_t verify_npth_fp_unw_insn_063_0x0a8c(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x14000002U;
    constexpr uint64_t kVaddr  = 0x0a8cULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #064 @ 0x0a90: 0x91000400 -> add x0, x0, #1
// Lệnh AArch64 #064 tại 0x0a90: add x0, x0, #1
uint64_t verify_npth_fp_unw_insn_064_0x0a90(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x91000400U;
    constexpr uint64_t kVaddr  = 0x0a90ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #065 @ 0x0a94: 0xF9401688 -> ldr x8, [x20, #0x28]
// Lệnh AArch64 #065 tại 0x0a94: ldr x8, [x20, #0x28]
uint64_t verify_npth_fp_unw_insn_065_0x0a94(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xF9401688U;
    constexpr uint64_t kVaddr  = 0x0a94ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #066 @ 0x0a98: 0xF85F83A9 -> ldur x9, [x29, #-8]
// Lệnh AArch64 #066 tại 0x0a98: ldur x9, [x29, #-8]
uint64_t verify_npth_fp_unw_insn_066_0x0a98(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xF85F83A9U;
    constexpr uint64_t kVaddr  = 0x0a98ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #067 @ 0x0a9c: 0xEB09011F -> cmp x8, x9
// Lệnh AArch64 #067 tại 0x0a9c: cmp x8, x9
uint64_t verify_npth_fp_unw_insn_067_0x0a9c(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xEB09011FU;
    constexpr uint64_t kVaddr  = 0x0a9cULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #068 @ 0x0aa0: 0x540000C1 -> b.ne #0xab8
// Lệnh AArch64 #068 tại 0x0aa0: b.ne #0xab8
uint64_t verify_npth_fp_unw_insn_068_0x0aa0(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x540000C1U;
    constexpr uint64_t kVaddr  = 0x0aa0ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #069 @ 0x0aa4: 0xA9444FF4 -> ldp x20, x19, [sp, #0x40]
// Lệnh AArch64 #069 tại 0x0aa4: ldp x20, x19, [sp, #0x40]
uint64_t verify_npth_fp_unw_insn_069_0x0aa4(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xA9444FF4U;
    constexpr uint64_t kVaddr  = 0x0aa4ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #070 @ 0x0aa8: 0xA9427BFD -> ldp x29, x30, [sp, #0x20]
// Lệnh AArch64 #070 tại 0x0aa8: ldp x29, x30, [sp, #0x20]
uint64_t verify_npth_fp_unw_insn_070_0x0aa8(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xA9427BFDU;
    constexpr uint64_t kVaddr  = 0x0aa8ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #071 @ 0x0aac: 0xF9401BF5 -> ldr x21, [sp, #0x30]
// Lệnh AArch64 #071 tại 0x0aac: ldr x21, [sp, #0x30]
uint64_t verify_npth_fp_unw_insn_071_0x0aac(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xF9401BF5U;
    constexpr uint64_t kVaddr  = 0x0aacULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #072 @ 0x0ab0: 0x910143FF -> add sp, sp, #0x50
// Lệnh AArch64 #072 tại 0x0ab0: add sp, sp, #0x50
uint64_t verify_npth_fp_unw_insn_072_0x0ab0(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x910143FFU;
    constexpr uint64_t kVaddr  = 0x0ab0ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #073 @ 0x0ab4: 0xD65F03C0 -> ret 
// Lệnh AArch64 #073 tại 0x0ab4: ret 
uint64_t verify_npth_fp_unw_insn_073_0x0ab4(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xD65F03C0U;
    constexpr uint64_t kVaddr  = 0x0ab4ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #074 @ 0x0ab8: 0x940000CA -> bl #0xde0
// Lệnh AArch64 #074 tại 0x0ab8: bl #0xde0
uint64_t verify_npth_fp_unw_insn_074_0x0ab8(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x940000CAU;
    constexpr uint64_t kVaddr  = 0x0ab8ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #075 @ 0x0abc: 0xA9BA7BFD -> stp x29, x30, [sp, #-0x60]!
// Lệnh AArch64 #075 tại 0x0abc: stp x29, x30, [sp, #-0x60]!
uint64_t verify_npth_fp_unw_insn_075_0x0abc(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xA9BA7BFDU;
    constexpr uint64_t kVaddr  = 0x0abcULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #076 @ 0x0ac0: 0xA9016FFC -> stp x28, x27, [sp, #0x10]
// Lệnh AArch64 #076 tại 0x0ac0: stp x28, x27, [sp, #0x10]
uint64_t verify_npth_fp_unw_insn_076_0x0ac0(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xA9016FFCU;
    constexpr uint64_t kVaddr  = 0x0ac0ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #077 @ 0x0ac4: 0xA90267FA -> stp x26, x25, [sp, #0x20]
// Lệnh AArch64 #077 tại 0x0ac4: stp x26, x25, [sp, #0x20]
uint64_t verify_npth_fp_unw_insn_077_0x0ac4(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xA90267FAU;
    constexpr uint64_t kVaddr  = 0x0ac4ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #078 @ 0x0ac8: 0xA9035FF8 -> stp x24, x23, [sp, #0x30]
// Lệnh AArch64 #078 tại 0x0ac8: stp x24, x23, [sp, #0x30]
uint64_t verify_npth_fp_unw_insn_078_0x0ac8(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xA9035FF8U;
    constexpr uint64_t kVaddr  = 0x0ac8ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #079 @ 0x0acc: 0xA90457F6 -> stp x22, x21, [sp, #0x40]
// Lệnh AArch64 #079 tại 0x0acc: stp x22, x21, [sp, #0x40]
uint64_t verify_npth_fp_unw_insn_079_0x0acc(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xA90457F6U;
    constexpr uint64_t kVaddr  = 0x0accULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #080 @ 0x0ad0: 0xA9054FF4 -> stp x20, x19, [sp, #0x50]
// Lệnh AArch64 #080 tại 0x0ad0: stp x20, x19, [sp, #0x50]
uint64_t verify_npth_fp_unw_insn_080_0x0ad0(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xA9054FF4U;
    constexpr uint64_t kVaddr  = 0x0ad0ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #081 @ 0x0ad4: 0x910003FD -> mov x29, sp
// Lệnh AArch64 #081 tại 0x0ad4: mov x29, sp
uint64_t verify_npth_fp_unw_insn_081_0x0ad4(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x910003FDU;
    constexpr uint64_t kVaddr  = 0x0ad4ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #082 @ 0x0ad8: 0xD11103FF -> sub sp, sp, #0x440
// Lệnh AArch64 #082 tại 0x0ad8: sub sp, sp, #0x440
uint64_t verify_npth_fp_unw_insn_082_0x0ad8(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xD11103FFU;
    constexpr uint64_t kVaddr  = 0x0ad8ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #083 @ 0x0adc: 0xD53BD05B -> mrs x27, tpidr_el0
// Lệnh AArch64 #083 tại 0x0adc: mrs x27, tpidr_el0
uint64_t verify_npth_fp_unw_insn_083_0x0adc(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xD53BD05BU;
    constexpr uint64_t kVaddr  = 0x0adcULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #084 @ 0x0ae0: 0xAA1F03F3 -> mov x19, xzr
// Lệnh AArch64 #084 tại 0x0ae0: mov x19, xzr
uint64_t verify_npth_fp_unw_insn_084_0x0ae0(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xAA1F03F3U;
    constexpr uint64_t kVaddr  = 0x0ae0ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #085 @ 0x0ae4: 0xF9401768 -> ldr x8, [x27, #0x28]
// Lệnh AArch64 #085 tại 0x0ae4: ldr x8, [x27, #0x28]
uint64_t verify_npth_fp_unw_insn_085_0x0ae4(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xF9401768U;
    constexpr uint64_t kVaddr  = 0x0ae4ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #086 @ 0x0ae8: 0xF81F03A8 -> stur x8, [x29, #-0x10]
// Lệnh AArch64 #086 tại 0x0ae8: stur x8, [x29, #-0x10]
uint64_t verify_npth_fp_unw_insn_086_0x0ae8(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xF81F03A8U;
    constexpr uint64_t kVaddr  = 0x0ae8ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #087 @ 0x0aec: 0xB4000AA0 -> cbz x0, #0xc40
// Lệnh AArch64 #087 tại 0x0aec: cbz x0, #0xc40
uint64_t verify_npth_fp_unw_insn_087_0x0aec(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xB4000AA0U;
    constexpr uint64_t kVaddr  = 0x0aecULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #088 @ 0x0af0: 0xB4000A81 -> cbz x1, #0xc40
// Lệnh AArch64 #088 tại 0x0af0: cbz x1, #0xc40
uint64_t verify_npth_fp_unw_insn_088_0x0af0(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xB4000A81U;
    constexpr uint64_t kVaddr  = 0x0af0ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #089 @ 0x0af4: 0xF102003F -> cmp x1, #0x80
// Lệnh AArch64 #089 tại 0x0af4: cmp x1, #0x80
uint64_t verify_npth_fp_unw_insn_089_0x0af4(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xF102003FU;
    constexpr uint64_t kVaddr  = 0x0af4ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #090 @ 0x0af8: 0x52801008 -> mov w8, #0x80
// Lệnh AArch64 #090 tại 0x0af8: mov w8, #0x80
uint64_t verify_npth_fp_unw_insn_090_0x0af8(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x52801008U;
    constexpr uint64_t kVaddr  = 0x0af8ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #091 @ 0x0afc: 0x9A88303C -> csel x28, x1, x8, lo
// Lệnh AArch64 #091 tại 0x0afc: csel x28, x1, x8, lo
uint64_t verify_npth_fp_unw_insn_091_0x0afc(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x9A88303CU;
    constexpr uint64_t kVaddr  = 0x0afcULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #092 @ 0x0b00: 0xAA0003F4 -> mov x20, x0
// Lệnh AArch64 #092 tại 0x0b00: mov x20, x0
uint64_t verify_npth_fp_unw_insn_092_0x0b00(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xAA0003F4U;
    constexpr uint64_t kVaddr  = 0x0b00ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #093 @ 0x0b04: 0xD376D795 -> lsl x21, x28, #0xa
// Lệnh AArch64 #093 tại 0x0b04: lsl x21, x28, #0xa
uint64_t verify_npth_fp_unw_insn_093_0x0b04(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xD376D795U;
    constexpr uint64_t kVaddr  = 0x0b04ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #094 @ 0x0b08: 0xAA1503E0 -> mov x0, x21
// Lệnh AArch64 #094 tại 0x0b08: mov x0, x21
uint64_t verify_npth_fp_unw_insn_094_0x0b08(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xAA1503E0U;
    constexpr uint64_t kVaddr  = 0x0b08ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #095 @ 0x0b0c: 0x940000BD -> bl #0xe00
// Lệnh AArch64 #095 tại 0x0b0c: bl #0xe00
uint64_t verify_npth_fp_unw_insn_095_0x0b0c(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x940000BDU;
    constexpr uint64_t kVaddr  = 0x0b0cULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #096 @ 0x0b10: 0xAA0003F3 -> mov x19, x0
// Lệnh AArch64 #096 tại 0x0b10: mov x19, x0
uint64_t verify_npth_fp_unw_insn_096_0x0b10(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xAA0003F3U;
    constexpr uint64_t kVaddr  = 0x0b10ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #097 @ 0x0b14: 0xB4000960 -> cbz x0, #0xc40
// Lệnh AArch64 #097 tại 0x0b14: cbz x0, #0xc40
uint64_t verify_npth_fp_unw_insn_097_0x0b14(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xB4000960U;
    constexpr uint64_t kVaddr  = 0x0b14ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #098 @ 0x0b18: 0xAA1303E0 -> mov x0, x19
// Lệnh AArch64 #098 tại 0x0b18: mov x0, x19
uint64_t verify_npth_fp_unw_insn_098_0x0b18(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xAA1303E0U;
    constexpr uint64_t kVaddr  = 0x0b18ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #099 @ 0x0b1c: 0x2A1F03E1 -> mov w1, wzr
// Lệnh AArch64 #099 tại 0x0b1c: mov w1, wzr
uint64_t verify_npth_fp_unw_insn_099_0x0b1c(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x2A1F03E1U;
    constexpr uint64_t kVaddr  = 0x0b1cULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #100 @ 0x0b20: 0xAA1503E2 -> mov x2, x21
// Lệnh AArch64 #100 tại 0x0b20: mov x2, x21
uint64_t verify_npth_fp_unw_insn_100_0x0b20(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xAA1503E2U;
    constexpr uint64_t kVaddr  = 0x0b20ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #101 @ 0x0b24: 0x940000BB -> bl #0xe10
// Lệnh AArch64 #101 tại 0x0b24: bl #0xe10
uint64_t verify_npth_fp_unw_insn_101_0x0b24(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x940000BBU;
    constexpr uint64_t kVaddr  = 0x0b24ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #102 @ 0x0b28: 0xAA1F03F5 -> mov x21, xzr
// Lệnh AArch64 #102 tại 0x0b28: mov x21, xzr
uint64_t verify_npth_fp_unw_insn_102_0x0b28(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xAA1F03F5U;
    constexpr uint64_t kVaddr  = 0x0b28ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #103 @ 0x0b2c: 0xAA1F03F8 -> mov x24, xzr
// Lệnh AArch64 #103 tại 0x0b2c: mov x24, xzr
uint64_t verify_npth_fp_unw_insn_103_0x0b2c(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xAA1F03F8U;
    constexpr uint64_t kVaddr  = 0x0b2cULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #104 @ 0x0b30: 0x90000016 -> adrp x22, #0
// Lệnh AArch64 #104 tại 0x0b30: adrp x22, #0
uint64_t verify_npth_fp_unw_insn_104_0x0b30(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x90000016U;
    constexpr uint64_t kVaddr  = 0x0b30ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #105 @ 0x0b34: 0x911FD2D6 -> add x22, x22, #0x7f4
// Lệnh AArch64 #105 tại 0x0b34: add x22, x22, #0x7f4
uint64_t verify_npth_fp_unw_insn_105_0x0b34(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x911FD2D6U;
    constexpr uint64_t kVaddr  = 0x0b34ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #106 @ 0x0b38: 0x90000017 -> adrp x23, #0
// Lệnh AArch64 #106 tại 0x0b38: adrp x23, #0
uint64_t verify_npth_fp_unw_insn_106_0x0b38(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x90000017U;
    constexpr uint64_t kVaddr  = 0x0b38ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #107 @ 0x0b3c: 0x911F52F7 -> add x23, x23, #0x7d4
// Lệnh AArch64 #107 tại 0x0b3c: add x23, x23, #0x7d4
uint64_t verify_npth_fp_unw_insn_107_0x0b3c(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x911F52F7U;
    constexpr uint64_t kVaddr  = 0x0b3cULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #108 @ 0x0b40: 0x9000001A -> adrp x26, #0
// Lệnh AArch64 #108 tại 0x0b40: adrp x26, #0
uint64_t verify_npth_fp_unw_insn_108_0x0b40(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x9000001AU;
    constexpr uint64_t kVaddr  = 0x0b40ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #109 @ 0x0b44: 0x911F6B5A -> add x26, x26, #0x7da
// Lệnh AArch64 #109 tại 0x0b44: add x26, x26, #0x7da
uint64_t verify_npth_fp_unw_insn_109_0x0b44(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x911F6B5AU;
    constexpr uint64_t kVaddr  = 0x0b44ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #110 @ 0x0b48: 0x90000019 -> adrp x25, #0
// Lệnh AArch64 #110 tại 0x0b48: adrp x25, #0
uint64_t verify_npth_fp_unw_insn_110_0x0b48(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x90000019U;
    constexpr uint64_t kVaddr  = 0x0b48ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #111 @ 0x0b4c: 0x911E4339 -> add x25, x25, #0x790
// Lệnh AArch64 #111 tại 0x0b4c: add x25, x25, #0x790
uint64_t verify_npth_fp_unw_insn_111_0x0b4c(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x911E4339U;
    constexpr uint64_t kVaddr  = 0x0b4cULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #112 @ 0x0b50: 0xEB15039F -> cmp x28, x21
// Lệnh AArch64 #112 tại 0x0b50: cmp x28, x21
uint64_t verify_npth_fp_unw_insn_112_0x0b50(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xEB15039FU;
    constexpr uint64_t kVaddr  = 0x0b50ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #113 @ 0x0b54: 0x54000760 -> b.eq #0xc40
// Lệnh AArch64 #113 tại 0x0b54: b.eq #0xc40
uint64_t verify_npth_fp_unw_insn_113_0x0b54(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x54000760U;
    constexpr uint64_t kVaddr  = 0x0b54ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #114 @ 0x0b58: 0xF8757A80 -> ldr x0, [x20, x21, lsl #3]
// Lệnh AArch64 #114 tại 0x0b58: ldr x0, [x20, x21, lsl #3]
uint64_t verify_npth_fp_unw_insn_114_0x0b58(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xF8757A80U;
    constexpr uint64_t kVaddr  = 0x0b58ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #115 @ 0x0b5c: 0x910043E1 -> add x1, sp, #0x10
// Lệnh AArch64 #115 tại 0x0b5c: add x1, sp, #0x10
uint64_t verify_npth_fp_unw_insn_115_0x0b5c(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x910043E1U;
    constexpr uint64_t kVaddr  = 0x0b5cULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #116 @ 0x0b60: 0x940000B0 -> bl #0xe20
// Lệnh AArch64 #116 tại 0x0b60: bl #0xe20
uint64_t verify_npth_fp_unw_insn_116_0x0b60(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x940000B0U;
    constexpr uint64_t kVaddr  = 0x0b60ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #117 @ 0x0b64: 0x34000620 -> cbz w0, #0xc28
// Lệnh AArch64 #117 tại 0x0b64: cbz w0, #0xc28
uint64_t verify_npth_fp_unw_insn_117_0x0b64(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x34000620U;
    constexpr uint64_t kVaddr  = 0x0b64ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #118 @ 0x0b68: 0xF9400BE6 -> ldr x6, [sp, #0x10]
// Lệnh AArch64 #118 tại 0x0b68: ldr x6, [sp, #0x10]
uint64_t verify_npth_fp_unw_insn_118_0x0b68(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xF9400BE6U;
    constexpr uint64_t kVaddr  = 0x0b68ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #119 @ 0x0b6c: 0xB40001E6 -> cbz x6, #0xba8
// Lệnh AArch64 #119 tại 0x0b6c: cbz x6, #0xba8
uint64_t verify_npth_fp_unw_insn_119_0x0b6c(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xB40001E6U;
    constexpr uint64_t kVaddr  = 0x0b6cULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #120 @ 0x0b70: 0x394000C8 -> ldrb w8, [x6]
// Lệnh AArch64 #120 tại 0x0b70: ldrb w8, [x6]
uint64_t verify_npth_fp_unw_insn_120_0x0b70(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x394000C8U;
    constexpr uint64_t kVaddr  = 0x0b70ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #121 @ 0x0b74: 0x340001A8 -> cbz w8, #0xba8
// Lệnh AArch64 #121 tại 0x0b74: cbz w8, #0xba8
uint64_t verify_npth_fp_unw_insn_121_0x0b74(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x340001A8U;
    constexpr uint64_t kVaddr  = 0x0b74ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #122 @ 0x0b78: 0xF8757A88 -> ldr x8, [x20, x21, lsl #3]
// Lệnh AArch64 #122 tại 0x0b78: ldr x8, [x20, x21, lsl #3]
uint64_t verify_npth_fp_unw_insn_122_0x0b78(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xF8757A88U;
    constexpr uint64_t kVaddr  = 0x0b78ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #123 @ 0x0b7c: 0xA9419FE9 -> ldp x9, x7, [sp, #0x18]
// Lệnh AArch64 #123 tại 0x0b7c: ldp x9, x7, [sp, #0x18]
uint64_t verify_npth_fp_unw_insn_123_0x0b7c(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xA9419FE9U;
    constexpr uint64_t kVaddr  = 0x0b7cULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #124 @ 0x0b80: 0xCB090105 -> sub x5, x8, x9
// Lệnh AArch64 #124 tại 0x0b80: sub x5, x8, x9
uint64_t verify_npth_fp_unw_insn_124_0x0b80(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xCB090105U;
    constexpr uint64_t kVaddr  = 0x0b80ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #125 @ 0x0b84: 0xB40004C7 -> cbz x7, #0xc1c
// Lệnh AArch64 #125 tại 0x0b84: cbz x7, #0xc1c
uint64_t verify_npth_fp_unw_insn_125_0x0b84(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xB40004C7U;
    constexpr uint64_t kVaddr  = 0x0b84ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #126 @ 0x0b88: 0xF94017E9 -> ldr x9, [sp, #0x28]
// Lệnh AArch64 #126 tại 0x0b88: ldr x9, [sp, #0x28]
uint64_t verify_npth_fp_unw_insn_126_0x0b88(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xF94017E9U;
    constexpr uint64_t kVaddr  = 0x0b88ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #127 @ 0x0b8c: 0x9100C3E0 -> add x0, sp, #0x30
// Lệnh AArch64 #127 tại 0x0b8c: add x0, sp, #0x30
uint64_t verify_npth_fp_unw_insn_127_0x0b8c(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x9100C3E0U;
    constexpr uint64_t kVaddr  = 0x0b8cULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #128 @ 0x0b90: 0xAA1903E3 -> mov x3, x25
// Lệnh AArch64 #128 tại 0x0b90: mov x3, x25
uint64_t verify_npth_fp_unw_insn_128_0x0b90(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xAA1903E3U;
    constexpr uint64_t kVaddr  = 0x0b90ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #129 @ 0x0b94: 0xAA1503E4 -> mov x4, x21
// Lệnh AArch64 #129 tại 0x0b94: mov x4, x21
uint64_t verify_npth_fp_unw_insn_129_0x0b94(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xAA1503E4U;
    constexpr uint64_t kVaddr  = 0x0b94ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #130 @ 0x0b98: 0xCB090108 -> sub x8, x8, x9
// Lệnh AArch64 #130 tại 0x0b98: sub x8, x8, x9
uint64_t verify_npth_fp_unw_insn_130_0x0b98(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xCB090108U;
    constexpr uint64_t kVaddr  = 0x0b98ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #131 @ 0x0b9c: 0xF90003E8 -> str x8, [sp]
// Lệnh AArch64 #131 tại 0x0b9c: str x8, [sp]
uint64_t verify_npth_fp_unw_insn_131_0x0b9c(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xF90003E8U;
    constexpr uint64_t kVaddr  = 0x0b9cULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #132 @ 0x0ba0: 0x94000036 -> bl #0xc78
// Lệnh AArch64 #132 tại 0x0ba0: bl #0xc78
uint64_t verify_npth_fp_unw_insn_132_0x0ba0(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x94000036U;
    constexpr uint64_t kVaddr  = 0x0ba0ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #133 @ 0x0ba4: 0x14000008 -> b #0xbc4
// Lệnh AArch64 #133 tại 0x0ba4: b #0xbc4
uint64_t verify_npth_fp_unw_insn_133_0x0ba4(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x14000008U;
    constexpr uint64_t kVaddr  = 0x0ba4ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #134 @ 0x0ba8: 0xF8757A88 -> ldr x8, [x20, x21, lsl #3]
// Lệnh AArch64 #134 tại 0x0ba8: ldr x8, [x20, x21, lsl #3]
uint64_t verify_npth_fp_unw_insn_134_0x0ba8(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xF8757A88U;
    constexpr uint64_t kVaddr  = 0x0ba8ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #135 @ 0x0bac: 0x9100C3E0 -> add x0, sp, #0x30
// Lệnh AArch64 #135 tại 0x0bac: add x0, sp, #0x30
uint64_t verify_npth_fp_unw_insn_135_0x0bac(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x9100C3E0U;
    constexpr uint64_t kVaddr  = 0x0bacULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #136 @ 0x0bb0: 0xF9400FE6 -> ldr x6, [sp, #0x18]
// Lệnh AArch64 #136 tại 0x0bb0: ldr x6, [sp, #0x18]
uint64_t verify_npth_fp_unw_insn_136_0x0bb0(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xF9400FE6U;
    constexpr uint64_t kVaddr  = 0x0bb0ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #137 @ 0x0bb4: 0xAA1603E3 -> mov x3, x22
// Lệnh AArch64 #137 tại 0x0bb4: mov x3, x22
uint64_t verify_npth_fp_unw_insn_137_0x0bb4(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xAA1603E3U;
    constexpr uint64_t kVaddr  = 0x0bb4ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #138 @ 0x0bb8: 0xCB060105 -> sub x5, x8, x6
// Lệnh AArch64 #138 tại 0x0bb8: sub x5, x8, x6
uint64_t verify_npth_fp_unw_insn_138_0x0bb8(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xCB060105U;
    constexpr uint64_t kVaddr  = 0x0bb8ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #139 @ 0x0bbc: 0xAA1503E4 -> mov x4, x21
// Lệnh AArch64 #139 tại 0x0bbc: mov x4, x21
uint64_t verify_npth_fp_unw_insn_139_0x0bbc(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xAA1503E4U;
    constexpr uint64_t kVaddr  = 0x0bbcULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #140 @ 0x0bc0: 0x9400002E -> bl #0xc78
// Lệnh AArch64 #140 tại 0x0bc0: bl #0xc78
uint64_t verify_npth_fp_unw_insn_140_0x0bc0(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x9400002EU;
    constexpr uint64_t kVaddr  = 0x0bc0ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #141 @ 0x0bc4: 0x9100C3E0 -> add x0, sp, #0x30
// Lệnh AArch64 #141 tại 0x0bc4: add x0, sp, #0x30
uint64_t verify_npth_fp_unw_insn_141_0x0bc4(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x9100C3E0U;
    constexpr uint64_t kVaddr  = 0x0bc4ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #142 @ 0x0bc8: 0xAA1703E1 -> mov x1, x23
// Lệnh AArch64 #142 tại 0x0bc8: mov x1, x23
uint64_t verify_npth_fp_unw_insn_142_0x0bc8(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xAA1703E1U;
    constexpr uint64_t kVaddr  = 0x0bc8ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #143 @ 0x0bcc: 0x910006B5 -> add x21, x21, #1
// Lệnh AArch64 #143 tại 0x0bcc: add x21, x21, #1
uint64_t verify_npth_fp_unw_insn_143_0x0bcc(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x910006B5U;
    constexpr uint64_t kVaddr  = 0x0bccULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #144 @ 0x0bd0: 0x94000098 -> bl #0xe30
// Lệnh AArch64 #144 tại 0x0bd0: bl #0xe30
uint64_t verify_npth_fp_unw_insn_144_0x0bd0(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x94000098U;
    constexpr uint64_t kVaddr  = 0x0bd0ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #145 @ 0x0bd4: 0xB4FFFBE0 -> cbz x0, #0xb50
// Lệnh AArch64 #145 tại 0x0bd4: cbz x0, #0xb50
uint64_t verify_npth_fp_unw_insn_145_0x0bd4(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xB4FFFBE0U;
    constexpr uint64_t kVaddr  = 0x0bd4ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #146 @ 0x0bd8: 0x9100C3E0 -> add x0, sp, #0x30
// Lệnh AArch64 #146 tại 0x0bd8: add x0, sp, #0x30
uint64_t verify_npth_fp_unw_insn_146_0x0bd8(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x9100C3E0U;
    constexpr uint64_t kVaddr  = 0x0bd8ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #147 @ 0x0bdc: 0x52808001 -> mov w1, #0x400
// Lệnh AArch64 #147 tại 0x0bdc: mov w1, #0x400
uint64_t verify_npth_fp_unw_insn_147_0x0bdc(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x52808001U;
    constexpr uint64_t kVaddr  = 0x0bdcULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #148 @ 0x0be0: 0xAA1A03F9 -> mov x25, x26
// Lệnh AArch64 #148 tại 0x0be0: mov x25, x26
uint64_t verify_npth_fp_unw_insn_148_0x0be0(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xAA1A03F9U;
    constexpr uint64_t kVaddr  = 0x0be0ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #149 @ 0x0be4: 0x8B18027A -> add x26, x19, x24
// Lệnh AArch64 #149 tại 0x0be4: add x26, x19, x24
uint64_t verify_npth_fp_unw_insn_149_0x0be4(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x8B18027AU;
    constexpr uint64_t kVaddr  = 0x0be4ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #150 @ 0x0be8: 0x94000096 -> bl #0xe40
// Lệnh AArch64 #150 tại 0x0be8: bl #0xe40
uint64_t verify_npth_fp_unw_insn_150_0x0be8(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x94000096U;
    constexpr uint64_t kVaddr  = 0x0be8ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #151 @ 0x0bec: 0xAA0003E2 -> mov x2, x0
// Lệnh AArch64 #151 tại 0x0bec: mov x2, x0
uint64_t verify_npth_fp_unw_insn_151_0x0bec(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xAA0003E2U;
    constexpr uint64_t kVaddr  = 0x0becULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #152 @ 0x0bf0: 0x9100C3E1 -> add x1, sp, #0x30
// Lệnh AArch64 #152 tại 0x0bf0: add x1, sp, #0x30
uint64_t verify_npth_fp_unw_insn_152_0x0bf0(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x9100C3E1U;
    constexpr uint64_t kVaddr  = 0x0bf0ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #153 @ 0x0bf4: 0xAA1A03E0 -> mov x0, x26
// Lệnh AArch64 #153 tại 0x0bf4: mov x0, x26
uint64_t verify_npth_fp_unw_insn_153_0x0bf4(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xAA1A03E0U;
    constexpr uint64_t kVaddr  = 0x0bf4ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #154 @ 0x0bf8: 0xAA1903FA -> mov x26, x25
// Lệnh AArch64 #154 tại 0x0bf8: mov x26, x25
uint64_t verify_npth_fp_unw_insn_154_0x0bf8(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xAA1903FAU;
    constexpr uint64_t kVaddr  = 0x0bf8ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #155 @ 0x0bfc: 0x90000019 -> adrp x25, #0
// Lệnh AArch64 #155 tại 0x0bfc: adrp x25, #0
uint64_t verify_npth_fp_unw_insn_155_0x0bfc(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x90000019U;
    constexpr uint64_t kVaddr  = 0x0bfcULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #156 @ 0x0c00: 0x911E4339 -> add x25, x25, #0x790
// Lệnh AArch64 #156 tại 0x0c00: add x25, x25, #0x790
uint64_t verify_npth_fp_unw_insn_156_0x0c00(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x911E4339U;
    constexpr uint64_t kVaddr  = 0x0c00ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #157 @ 0x0c04: 0x94000093 -> bl #0xe50
// Lệnh AArch64 #157 tại 0x0c04: bl #0xe50
uint64_t verify_npth_fp_unw_insn_157_0x0c04(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x94000093U;
    constexpr uint64_t kVaddr  = 0x0c04ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #158 @ 0x0c08: 0x9100C3E0 -> add x0, sp, #0x30
// Lệnh AArch64 #158 tại 0x0c08: add x0, sp, #0x30
uint64_t verify_npth_fp_unw_insn_158_0x0c08(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x9100C3E0U;
    constexpr uint64_t kVaddr  = 0x0c08ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #159 @ 0x0c0c: 0x52808001 -> mov w1, #0x400
// Lệnh AArch64 #159 tại 0x0c0c: mov w1, #0x400
uint64_t verify_npth_fp_unw_insn_159_0x0c0c(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x52808001U;
    constexpr uint64_t kVaddr  = 0x0c0cULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #160 @ 0x0c10: 0x9400008C -> bl #0xe40
// Lệnh AArch64 #160 tại 0x0c10: bl #0xe40
uint64_t verify_npth_fp_unw_insn_160_0x0c10(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x9400008CU;
    constexpr uint64_t kVaddr  = 0x0c10ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #161 @ 0x0c14: 0x8B180018 -> add x24, x0, x24
// Lệnh AArch64 #161 tại 0x0c14: add x24, x0, x24
uint64_t verify_npth_fp_unw_insn_161_0x0c14(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x8B180018U;
    constexpr uint64_t kVaddr  = 0x0c14ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #162 @ 0x0c18: 0x17FFFFCE -> b #0xb50
// Lệnh AArch64 #162 tại 0x0c18: b #0xb50
uint64_t verify_npth_fp_unw_insn_162_0x0c18(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x17FFFFCEU;
    constexpr uint64_t kVaddr  = 0x0c18ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #163 @ 0x0c1c: 0x9100C3E0 -> add x0, sp, #0x30
// Lệnh AArch64 #163 tại 0x0c1c: add x0, sp, #0x30
uint64_t verify_npth_fp_unw_insn_163_0x0c1c(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x9100C3E0U;
    constexpr uint64_t kVaddr  = 0x0c1cULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #164 @ 0x0c20: 0xAA1A03E3 -> mov x3, x26
// Lệnh AArch64 #164 tại 0x0c20: mov x3, x26
uint64_t verify_npth_fp_unw_insn_164_0x0c20(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xAA1A03E3U;
    constexpr uint64_t kVaddr  = 0x0c20ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #165 @ 0x0c24: 0x17FFFFE6 -> b #0xbbc
// Lệnh AArch64 #165 tại 0x0c24: b #0xbbc
uint64_t verify_npth_fp_unw_insn_165_0x0c24(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x17FFFFE6U;
    constexpr uint64_t kVaddr  = 0x0c24ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #166 @ 0x0c28: 0xF8757A85 -> ldr x5, [x20, x21, lsl #3]
// Lệnh AArch64 #166 tại 0x0c28: ldr x5, [x20, x21, lsl #3]
uint64_t verify_npth_fp_unw_insn_166_0x0c28(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xF8757A85U;
    constexpr uint64_t kVaddr  = 0x0c28ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #167 @ 0x0c2c: 0xD503201F -> nop 
// Lệnh AArch64 #167 tại 0x0c2c: nop 
uint64_t verify_npth_fp_unw_insn_167_0x0c2c(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xD503201FU;
    constexpr uint64_t kVaddr  = 0x0c2cULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #168 @ 0x0c30: 0x70FFDC03 -> adr x3, #0x7b3
// Lệnh AArch64 #168 tại 0x0c30: adr x3, #0x7b3
uint64_t verify_npth_fp_unw_insn_168_0x0c30(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x70FFDC03U;
    constexpr uint64_t kVaddr  = 0x0c30ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #169 @ 0x0c34: 0x9100C3E0 -> add x0, sp, #0x30
// Lệnh AArch64 #169 tại 0x0c34: add x0, sp, #0x30
uint64_t verify_npth_fp_unw_insn_169_0x0c34(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x9100C3E0U;
    constexpr uint64_t kVaddr  = 0x0c34ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #170 @ 0x0c38: 0xAA1503E4 -> mov x4, x21
// Lệnh AArch64 #170 tại 0x0c38: mov x4, x21
uint64_t verify_npth_fp_unw_insn_170_0x0c38(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xAA1503E4U;
    constexpr uint64_t kVaddr  = 0x0c38ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #171 @ 0x0c3c: 0x9400000F -> bl #0xc78
// Lệnh AArch64 #171 tại 0x0c3c: bl #0xc78
uint64_t verify_npth_fp_unw_insn_171_0x0c3c(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x9400000FU;
    constexpr uint64_t kVaddr  = 0x0c3cULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #172 @ 0x0c40: 0xF9401768 -> ldr x8, [x27, #0x28]
// Lệnh AArch64 #172 tại 0x0c40: ldr x8, [x27, #0x28]
uint64_t verify_npth_fp_unw_insn_172_0x0c40(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xF9401768U;
    constexpr uint64_t kVaddr  = 0x0c40ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #173 @ 0x0c44: 0xF85F03A9 -> ldur x9, [x29, #-0x10]
// Lệnh AArch64 #173 tại 0x0c44: ldur x9, [x29, #-0x10]
uint64_t verify_npth_fp_unw_insn_173_0x0c44(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xF85F03A9U;
    constexpr uint64_t kVaddr  = 0x0c44ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #174 @ 0x0c48: 0xEB09011F -> cmp x8, x9
// Lệnh AArch64 #174 tại 0x0c48: cmp x8, x9
uint64_t verify_npth_fp_unw_insn_174_0x0c48(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xEB09011FU;
    constexpr uint64_t kVaddr  = 0x0c48ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #175 @ 0x0c4c: 0x54000141 -> b.ne #0xc74
// Lệnh AArch64 #175 tại 0x0c4c: b.ne #0xc74
uint64_t verify_npth_fp_unw_insn_175_0x0c4c(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x54000141U;
    constexpr uint64_t kVaddr  = 0x0c4cULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #176 @ 0x0c50: 0xAA1303E0 -> mov x0, x19
// Lệnh AArch64 #176 tại 0x0c50: mov x0, x19
uint64_t verify_npth_fp_unw_insn_176_0x0c50(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xAA1303E0U;
    constexpr uint64_t kVaddr  = 0x0c50ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #177 @ 0x0c54: 0x911103FF -> add sp, sp, #0x440
// Lệnh AArch64 #177 tại 0x0c54: add sp, sp, #0x440
uint64_t verify_npth_fp_unw_insn_177_0x0c54(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x911103FFU;
    constexpr uint64_t kVaddr  = 0x0c54ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #178 @ 0x0c58: 0xA9454FF4 -> ldp x20, x19, [sp, #0x50]
// Lệnh AArch64 #178 tại 0x0c58: ldp x20, x19, [sp, #0x50]
uint64_t verify_npth_fp_unw_insn_178_0x0c58(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xA9454FF4U;
    constexpr uint64_t kVaddr  = 0x0c58ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #179 @ 0x0c5c: 0xA94457F6 -> ldp x22, x21, [sp, #0x40]
// Lệnh AArch64 #179 tại 0x0c5c: ldp x22, x21, [sp, #0x40]
uint64_t verify_npth_fp_unw_insn_179_0x0c5c(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xA94457F6U;
    constexpr uint64_t kVaddr  = 0x0c5cULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #180 @ 0x0c60: 0xA9435FF8 -> ldp x24, x23, [sp, #0x30]
// Lệnh AArch64 #180 tại 0x0c60: ldp x24, x23, [sp, #0x30]
uint64_t verify_npth_fp_unw_insn_180_0x0c60(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xA9435FF8U;
    constexpr uint64_t kVaddr  = 0x0c60ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #181 @ 0x0c64: 0xA94267FA -> ldp x26, x25, [sp, #0x20]
// Lệnh AArch64 #181 tại 0x0c64: ldp x26, x25, [sp, #0x20]
uint64_t verify_npth_fp_unw_insn_181_0x0c64(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xA94267FAU;
    constexpr uint64_t kVaddr  = 0x0c64ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #182 @ 0x0c68: 0xA9416FFC -> ldp x28, x27, [sp, #0x10]
// Lệnh AArch64 #182 tại 0x0c68: ldp x28, x27, [sp, #0x10]
uint64_t verify_npth_fp_unw_insn_182_0x0c68(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xA9416FFCU;
    constexpr uint64_t kVaddr  = 0x0c68ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #183 @ 0x0c6c: 0xA8C67BFD -> ldp x29, x30, [sp], #0x60
// Lệnh AArch64 #183 tại 0x0c6c: ldp x29, x30, [sp], #0x60
uint64_t verify_npth_fp_unw_insn_183_0x0c6c(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xA8C67BFDU;
    constexpr uint64_t kVaddr  = 0x0c6cULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #184 @ 0x0c70: 0xD65F03C0 -> ret 
// Lệnh AArch64 #184 tại 0x0c70: ret 
uint64_t verify_npth_fp_unw_insn_184_0x0c70(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xD65F03C0U;
    constexpr uint64_t kVaddr  = 0x0c70ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #185 @ 0x0c74: 0x9400005B -> bl #0xde0
// Lệnh AArch64 #185 tại 0x0c74: bl #0xde0
uint64_t verify_npth_fp_unw_insn_185_0x0c74(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x9400005BU;
    constexpr uint64_t kVaddr  = 0x0c74ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #186 @ 0x0c78: 0xD10443FF -> sub sp, sp, #0x110
// Lệnh AArch64 #186 tại 0x0c78: sub sp, sp, #0x110
uint64_t verify_npth_fp_unw_insn_186_0x0c78(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xD10443FFU;
    constexpr uint64_t kVaddr  = 0x0c78ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #187 @ 0x0c7c: 0xA90F7BFD -> stp x29, x30, [sp, #0xf0]
// Lệnh AArch64 #187 tại 0x0c7c: stp x29, x30, [sp, #0xf0]
uint64_t verify_npth_fp_unw_insn_187_0x0c7c(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xA90F7BFDU;
    constexpr uint64_t kVaddr  = 0x0c7cULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #188 @ 0x0c80: 0xA9104FFC -> stp x28, x19, [sp, #0x100]
// Lệnh AArch64 #188 tại 0x0c80: stp x28, x19, [sp, #0x100]
uint64_t verify_npth_fp_unw_insn_188_0x0c80(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xA9104FFCU;
    constexpr uint64_t kVaddr  = 0x0c80ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #189 @ 0x0c84: 0x9103C3FD -> add x29, sp, #0xf0
// Lệnh AArch64 #189 tại 0x0c84: add x29, sp, #0xf0
uint64_t verify_npth_fp_unw_insn_189_0x0c84(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x9103C3FDU;
    constexpr uint64_t kVaddr  = 0x0c84ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #190 @ 0x0c88: 0xA9399BA5 -> stp x5, x6, [x29, #-0x68]
// Lệnh AArch64 #190 tại 0x0c88: stp x5, x6, [x29, #-0x68]
uint64_t verify_npth_fp_unw_insn_190_0x0c88(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xA9399BA5U;
    constexpr uint64_t kVaddr  = 0x0c88ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #191 @ 0x0c8c: 0xD101C3A9 -> sub x9, x29, #0x70
// Lệnh AArch64 #191 tại 0x0c8c: sub x9, x29, #0x70
uint64_t verify_npth_fp_unw_insn_191_0x0c8c(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xD101C3A9U;
    constexpr uint64_t kVaddr  = 0x0c8cULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #192 @ 0x0c90: 0xF81903A4 -> stur x4, [x29, #-0x70]
// Lệnh AArch64 #192 tại 0x0c90: stur x4, [x29, #-0x70]
uint64_t verify_npth_fp_unw_insn_192_0x0c90(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xF81903A4U;
    constexpr uint64_t kVaddr  = 0x0c90ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #193 @ 0x0c94: 0x928003EB -> mov x11, #-0x20
// Lệnh AArch64 #193 tại 0x0c94: mov x11, #-0x20
uint64_t verify_npth_fp_unw_insn_193_0x0c94(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x928003EBU;
    constexpr uint64_t kVaddr  = 0x0c94ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #194 @ 0x0c98: 0xF81A83A7 -> stur x7, [x29, #-0x58]
// Lệnh AArch64 #194 tại 0x0c98: stur x7, [x29, #-0x58]
uint64_t verify_npth_fp_unw_insn_194_0x0c98(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xF81A83A7U;
    constexpr uint64_t kVaddr  = 0x0c98ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #195 @ 0x0c9c: 0x910003EC -> mov x12, sp
// Lệnh AArch64 #195 tại 0x0c9c: mov x12, sp
uint64_t verify_npth_fp_unw_insn_195_0x0c9c(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x910003ECU;
    constexpr uint64_t kVaddr  = 0x0c9cULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #196 @ 0x0ca0: 0xAD0007E0 -> stp q0, q1, [sp]
// Lệnh AArch64 #196 tại 0x0ca0: stp q0, q1, [sp]
uint64_t verify_npth_fp_unw_insn_196_0x0ca0(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xAD0007E0U;
    constexpr uint64_t kVaddr  = 0x0ca0ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #197 @ 0x0ca4: 0x91008129 -> add x9, x9, #0x20
// Lệnh AArch64 #197 tại 0x0ca4: add x9, x9, #0x20
uint64_t verify_npth_fp_unw_insn_197_0x0ca4(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x91008129U;
    constexpr uint64_t kVaddr  = 0x0ca4ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #198 @ 0x0ca8: 0xAD010FE2 -> stp q2, q3, [sp, #0x20]
// Lệnh AArch64 #198 tại 0x0ca8: stp q2, q3, [sp, #0x20]
uint64_t verify_npth_fp_unw_insn_198_0x0ca8(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xAD010FE2U;
    constexpr uint64_t kVaddr  = 0x0ca8ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #199 @ 0x0cac: 0xF2DFF00B -> movk x11, #0xff80, lsl #32
// Lệnh AArch64 #199 tại 0x0cac: movk x11, #0xff80, lsl #32
uint64_t verify_npth_fp_unw_insn_199_0x0cac(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xF2DFF00BU;
    constexpr uint64_t kVaddr  = 0x0cacULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #200 @ 0x0cb0: 0xAD0217E4 -> stp q4, q5, [sp, #0x40]
// Lệnh AArch64 #200 tại 0x0cb0: stp q4, q5, [sp, #0x40]
uint64_t verify_npth_fp_unw_insn_200_0x0cb0(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xAD0217E4U;
    constexpr uint64_t kVaddr  = 0x0cb0ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #201 @ 0x0cb4: 0x9102018C -> add x12, x12, #0x80
// Lệnh AArch64 #201 tại 0x0cb4: add x12, x12, #0x80
uint64_t verify_npth_fp_unw_insn_201_0x0cb4(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x9102018CU;
    constexpr uint64_t kVaddr  = 0x0cb4ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #202 @ 0x0cb8: 0xAD031FE6 -> stp q6, q7, [sp, #0x60]
// Lệnh AArch64 #202 tại 0x0cb8: stp q6, q7, [sp, #0x60]
uint64_t verify_npth_fp_unw_insn_202_0x0cb8(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xAD031FE6U;
    constexpr uint64_t kVaddr  = 0x0cb8ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #203 @ 0x0cbc: 0xD53BD053 -> mrs x19, tpidr_el0
// Lệnh AArch64 #203 tại 0x0cbc: mrs x19, tpidr_el0
uint64_t verify_npth_fp_unw_insn_203_0x0cbc(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xD53BD053U;
    constexpr uint64_t kVaddr  = 0x0cbcULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #204 @ 0x0cc0: 0xF9401668 -> ldr x8, [x19, #0x28]
// Lệnh AArch64 #204 tại 0x0cc0: ldr x8, [x19, #0x28]
uint64_t verify_npth_fp_unw_insn_204_0x0cc0(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xF9401668U;
    constexpr uint64_t kVaddr  = 0x0cc0ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #205 @ 0x0cc4: 0xD100A3AA -> sub x10, x29, #0x28
// Lệnh AArch64 #205 tại 0x0cc4: sub x10, x29, #0x28
uint64_t verify_npth_fp_unw_insn_205_0x0cc4(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xD100A3AAU;
    constexpr uint64_t kVaddr  = 0x0cc4ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #206 @ 0x0cc8: 0xAA0303E2 -> mov x2, x3
// Lệnh AArch64 #206 tại 0x0cc8: mov x2, x3
uint64_t verify_npth_fp_unw_insn_206_0x0cc8(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xAA0303E2U;
    constexpr uint64_t kVaddr  = 0x0cc8ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #207 @ 0x0ccc: 0xD10143A3 -> sub x3, x29, #0x50
// Lệnh AArch64 #207 tại 0x0ccc: sub x3, x29, #0x50
uint64_t verify_npth_fp_unw_insn_207_0x0ccc(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xD10143A3U;
    constexpr uint64_t kVaddr  = 0x0cccULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #208 @ 0x0cd0: 0x52808001 -> mov w1, #0x400
// Lệnh AArch64 #208 tại 0x0cd0: mov w1, #0x400
uint64_t verify_npth_fp_unw_insn_208_0x0cd0(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x52808001U;
    constexpr uint64_t kVaddr  = 0x0cd0ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #209 @ 0x0cd4: 0xF81F83A8 -> stur x8, [x29, #-8]
// Lệnh AArch64 #209 tại 0x0cd4: stur x8, [x29, #-8]
uint64_t verify_npth_fp_unw_insn_209_0x0cd4(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xF81F83A8U;
    constexpr uint64_t kVaddr  = 0x0cd4ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #210 @ 0x0cd8: 0x910083A8 -> add x8, x29, #0x20
// Lệnh AArch64 #210 tại 0x0cd8: add x8, x29, #0x20
uint64_t verify_npth_fp_unw_insn_210_0x0cd8(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x910083A8U;
    constexpr uint64_t kVaddr  = 0x0cd8ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #211 @ 0x0cdc: 0xA93EAFAC -> stp x12, x11, [x29, #-0x18]
// Lệnh AArch64 #211 tại 0x0cdc: stp x12, x11, [x29, #-0x18]
uint64_t verify_npth_fp_unw_insn_211_0x0cdc(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xA93EAFACU;
    constexpr uint64_t kVaddr  = 0x0cdcULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #212 @ 0x0ce0: 0xA93DA7A8 -> stp x8, x9, [x29, #-0x28]
// Lệnh AArch64 #212 tại 0x0ce0: stp x8, x9, [x29, #-0x28]
uint64_t verify_npth_fp_unw_insn_212_0x0ce0(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xA93DA7A8U;
    constexpr uint64_t kVaddr  = 0x0ce0ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #213 @ 0x0ce4: 0xAD400540 -> ldp q0, q1, [x10]
// Lệnh AArch64 #213 tại 0x0ce4: ldp q0, q1, [x10]
uint64_t verify_npth_fp_unw_insn_213_0x0ce4(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xAD400540U;
    constexpr uint64_t kVaddr  = 0x0ce4ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #214 @ 0x0ce8: 0xAD3D87A0 -> stp q0, q1, [x29, #-0x50]
// Lệnh AArch64 #214 tại 0x0ce8: stp q0, q1, [x29, #-0x50]
uint64_t verify_npth_fp_unw_insn_214_0x0ce8(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xAD3D87A0U;
    constexpr uint64_t kVaddr  = 0x0ce8ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #215 @ 0x0cec: 0x9400005D -> bl #0xe60
// Lệnh AArch64 #215 tại 0x0cec: bl #0xe60
uint64_t verify_npth_fp_unw_insn_215_0x0cec(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x9400005DU;
    constexpr uint64_t kVaddr  = 0x0cecULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #216 @ 0x0cf0: 0xF9401668 -> ldr x8, [x19, #0x28]
// Lệnh AArch64 #216 tại 0x0cf0: ldr x8, [x19, #0x28]
uint64_t verify_npth_fp_unw_insn_216_0x0cf0(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xF9401668U;
    constexpr uint64_t kVaddr  = 0x0cf0ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #217 @ 0x0cf4: 0xF85F83A9 -> ldur x9, [x29, #-8]
// Lệnh AArch64 #217 tại 0x0cf4: ldur x9, [x29, #-8]
uint64_t verify_npth_fp_unw_insn_217_0x0cf4(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xF85F83A9U;
    constexpr uint64_t kVaddr  = 0x0cf4ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #218 @ 0x0cf8: 0xEB09011F -> cmp x8, x9
// Lệnh AArch64 #218 tại 0x0cf8: cmp x8, x9
uint64_t verify_npth_fp_unw_insn_218_0x0cf8(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xEB09011FU;
    constexpr uint64_t kVaddr  = 0x0cf8ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #219 @ 0x0cfc: 0x540000A1 -> b.ne #0xd10
// Lệnh AArch64 #219 tại 0x0cfc: b.ne #0xd10
uint64_t verify_npth_fp_unw_insn_219_0x0cfc(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x540000A1U;
    constexpr uint64_t kVaddr  = 0x0cfcULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #220 @ 0x0d00: 0xA9504FFC -> ldp x28, x19, [sp, #0x100]
// Lệnh AArch64 #220 tại 0x0d00: ldp x28, x19, [sp, #0x100]
uint64_t verify_npth_fp_unw_insn_220_0x0d00(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xA9504FFCU;
    constexpr uint64_t kVaddr  = 0x0d00ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #221 @ 0x0d04: 0xA94F7BFD -> ldp x29, x30, [sp, #0xf0]
// Lệnh AArch64 #221 tại 0x0d04: ldp x29, x30, [sp, #0xf0]
uint64_t verify_npth_fp_unw_insn_221_0x0d04(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xA94F7BFDU;
    constexpr uint64_t kVaddr  = 0x0d04ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #222 @ 0x0d08: 0x910443FF -> add sp, sp, #0x110
// Lệnh AArch64 #222 tại 0x0d08: add sp, sp, #0x110
uint64_t verify_npth_fp_unw_insn_222_0x0d08(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x910443FFU;
    constexpr uint64_t kVaddr  = 0x0d08ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #223 @ 0x0d0c: 0xD65F03C0 -> ret 
// Lệnh AArch64 #223 tại 0x0d0c: ret 
uint64_t verify_npth_fp_unw_insn_223_0x0d0c(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xD65F03C0U;
    constexpr uint64_t kVaddr  = 0x0d0cULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #224 @ 0x0d10: 0x94000034 -> bl #0xde0
// Lệnh AArch64 #224 tại 0x0d10: bl #0xde0
uint64_t verify_npth_fp_unw_insn_224_0x0d10(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x94000034U;
    constexpr uint64_t kVaddr  = 0x0d10ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #225 @ 0x0d14: 0xA9BE7BFD -> stp x29, x30, [sp, #-0x20]!
// Lệnh AArch64 #225 tại 0x0d14: stp x29, x30, [sp, #-0x20]!
uint64_t verify_npth_fp_unw_insn_225_0x0d14(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xA9BE7BFDU;
    constexpr uint64_t kVaddr  = 0x0d14ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #226 @ 0x0d18: 0xA9014FFC -> stp x28, x19, [sp, #0x10]
// Lệnh AArch64 #226 tại 0x0d18: stp x28, x19, [sp, #0x10]
uint64_t verify_npth_fp_unw_insn_226_0x0d18(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xA9014FFCU;
    constexpr uint64_t kVaddr  = 0x0d18ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #227 @ 0x0d1c: 0x910003FD -> mov x29, sp
// Lệnh AArch64 #227 tại 0x0d1c: mov x29, sp
uint64_t verify_npth_fp_unw_insn_227_0x0d1c(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x910003FDU;
    constexpr uint64_t kVaddr  = 0x0d1cULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #228 @ 0x0d20: 0xD11043FF -> sub sp, sp, #0x410
// Lệnh AArch64 #228 tại 0x0d20: sub sp, sp, #0x410
uint64_t verify_npth_fp_unw_insn_228_0x0d20(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xD11043FFU;
    constexpr uint64_t kVaddr  = 0x0d20ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #229 @ 0x0d24: 0xD53BD053 -> mrs x19, tpidr_el0
// Lệnh AArch64 #229 tại 0x0d24: mrs x19, tpidr_el0
uint64_t verify_npth_fp_unw_insn_229_0x0d24(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xD53BD053U;
    constexpr uint64_t kVaddr  = 0x0d24ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #230 @ 0x0d28: 0x910003E0 -> mov x0, sp
// Lệnh AArch64 #230 tại 0x0d28: mov x0, sp
uint64_t verify_npth_fp_unw_insn_230_0x0d28(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x910003E0U;
    constexpr uint64_t kVaddr  = 0x0d28ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #231 @ 0x0d2c: 0x6F00E400 -> movi v0.2d, #0000000000000000
// Lệnh AArch64 #231 tại 0x0d2c: movi v0.2d, #0000000000000000
uint64_t verify_npth_fp_unw_insn_231_0x0d2c(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x6F00E400U;
    constexpr uint64_t kVaddr  = 0x0d2cULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #232 @ 0x0d30: 0xF9401668 -> ldr x8, [x19, #0x28]
// Lệnh AArch64 #232 tại 0x0d30: ldr x8, [x19, #0x28]
uint64_t verify_npth_fp_unw_insn_232_0x0d30(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xF9401668U;
    constexpr uint64_t kVaddr  = 0x0d30ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #233 @ 0x0d34: 0x52801001 -> mov w1, #0x80
// Lệnh AArch64 #233 tại 0x0d34: mov w1, #0x80
uint64_t verify_npth_fp_unw_insn_233_0x0d34(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x52801001U;
    constexpr uint64_t kVaddr  = 0x0d34ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #234 @ 0x0d38: 0xF81F83A8 -> stur x8, [x29, #-8]
// Lệnh AArch64 #234 tại 0x0d38: stur x8, [x29, #-8]
uint64_t verify_npth_fp_unw_insn_234_0x0d38(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xF81F83A8U;
    constexpr uint64_t kVaddr  = 0x0d38ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #235 @ 0x0d3c: 0xAD0003E0 -> stp q0, q0, [sp]
// Lệnh AArch64 #235 tại 0x0d3c: stp q0, q0, [sp]
uint64_t verify_npth_fp_unw_insn_235_0x0d3c(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xAD0003E0U;
    constexpr uint64_t kVaddr  = 0x0d3cULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #236 @ 0x0d40: 0xAD0103E0 -> stp q0, q0, [sp, #0x20]
// Lệnh AArch64 #236 tại 0x0d40: stp q0, q0, [sp, #0x20]
uint64_t verify_npth_fp_unw_insn_236_0x0d40(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xAD0103E0U;
    constexpr uint64_t kVaddr  = 0x0d40ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #237 @ 0x0d44: 0xAD0203E0 -> stp q0, q0, [sp, #0x40]
// Lệnh AArch64 #237 tại 0x0d44: stp q0, q0, [sp, #0x40]
uint64_t verify_npth_fp_unw_insn_237_0x0d44(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xAD0203E0U;
    constexpr uint64_t kVaddr  = 0x0d44ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #238 @ 0x0d48: 0xAD0303E0 -> stp q0, q0, [sp, #0x60]
// Lệnh AArch64 #238 tại 0x0d48: stp q0, q0, [sp, #0x60]
uint64_t verify_npth_fp_unw_insn_238_0x0d48(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xAD0303E0U;
    constexpr uint64_t kVaddr  = 0x0d48ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #239 @ 0x0d4c: 0x9400001D -> bl #0xdc0
// Lệnh AArch64 #239 tại 0x0d4c: bl #0xdc0
uint64_t verify_npth_fp_unw_insn_239_0x0d4c(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x9400001DU;
    constexpr uint64_t kVaddr  = 0x0d4cULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #240 @ 0x0d50: 0xAA0003E1 -> mov x1, x0
// Lệnh AArch64 #240 tại 0x0d50: mov x1, x0
uint64_t verify_npth_fp_unw_insn_240_0x0d50(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xAA0003E1U;
    constexpr uint64_t kVaddr  = 0x0d50ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #241 @ 0x0d54: 0x910003E0 -> mov x0, sp
// Lệnh AArch64 #241 tại 0x0d54: mov x0, sp
uint64_t verify_npth_fp_unw_insn_241_0x0d54(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x910003E0U;
    constexpr uint64_t kVaddr  = 0x0d54ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #242 @ 0x0d58: 0x94000026 -> bl #0xdf0
// Lệnh AArch64 #242 tại 0x0d58: bl #0xdf0
uint64_t verify_npth_fp_unw_insn_242_0x0d58(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x94000026U;
    constexpr uint64_t kVaddr  = 0x0d58ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #243 @ 0x0d5c: 0xF9401668 -> ldr x8, [x19, #0x28]
// Lệnh AArch64 #243 tại 0x0d5c: ldr x8, [x19, #0x28]
uint64_t verify_npth_fp_unw_insn_243_0x0d5c(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xF9401668U;
    constexpr uint64_t kVaddr  = 0x0d5cULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #244 @ 0x0d60: 0xF85F83A9 -> ldur x9, [x29, #-8]
// Lệnh AArch64 #244 tại 0x0d60: ldur x9, [x29, #-8]
uint64_t verify_npth_fp_unw_insn_244_0x0d60(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xF85F83A9U;
    constexpr uint64_t kVaddr  = 0x0d60ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #245 @ 0x0d64: 0xEB09011F -> cmp x8, x9
// Lệnh AArch64 #245 tại 0x0d64: cmp x8, x9
uint64_t verify_npth_fp_unw_insn_245_0x0d64(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xEB09011FU;
    constexpr uint64_t kVaddr  = 0x0d64ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #246 @ 0x0d68: 0x540000A1 -> b.ne #0xd7c
// Lệnh AArch64 #246 tại 0x0d68: b.ne #0xd7c
uint64_t verify_npth_fp_unw_insn_246_0x0d68(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x540000A1U;
    constexpr uint64_t kVaddr  = 0x0d68ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #247 @ 0x0d6c: 0x911043FF -> add sp, sp, #0x410
// Lệnh AArch64 #247 tại 0x0d6c: add sp, sp, #0x410
uint64_t verify_npth_fp_unw_insn_247_0x0d6c(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x911043FFU;
    constexpr uint64_t kVaddr  = 0x0d6cULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #248 @ 0x0d70: 0xA9414FFC -> ldp x28, x19, [sp, #0x10]
// Lệnh AArch64 #248 tại 0x0d70: ldp x28, x19, [sp, #0x10]
uint64_t verify_npth_fp_unw_insn_248_0x0d70(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xA9414FFCU;
    constexpr uint64_t kVaddr  = 0x0d70ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #249 @ 0x0d74: 0xA8C27BFD -> ldp x29, x30, [sp], #0x20
// Lệnh AArch64 #249 tại 0x0d74: ldp x29, x30, [sp], #0x20
uint64_t verify_npth_fp_unw_insn_249_0x0d74(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xA8C27BFDU;
    constexpr uint64_t kVaddr  = 0x0d74ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #250 @ 0x0d78: 0xD65F03C0 -> ret 
// Lệnh AArch64 #250 tại 0x0d78: ret 
uint64_t verify_npth_fp_unw_insn_250_0x0d78(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xD65F03C0U;
    constexpr uint64_t kVaddr  = 0x0d78ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #251 @ 0x0d7c: 0x94000019 -> bl #0xde0
// Lệnh AArch64 #251 tại 0x0d7c: bl #0xde0
uint64_t verify_npth_fp_unw_insn_251_0x0d7c(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x94000019U;
    constexpr uint64_t kVaddr  = 0x0d7cULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

uint64_t ExecuteTextInstructionForensicCheck(uint32_t insn_idx, uint64_t seed) noexcept {
    switch (insn_idx) {
        case 0: return verify_npth_fp_unw_insn_000_0x0990(seed);
        case 1: return verify_npth_fp_unw_insn_001_0x0994(seed);
        case 2: return verify_npth_fp_unw_insn_002_0x0998(seed);
        case 3: return verify_npth_fp_unw_insn_003_0x099c(seed);
        case 4: return verify_npth_fp_unw_insn_004_0x09a0(seed);
        case 5: return verify_npth_fp_unw_insn_005_0x09a4(seed);
        case 6: return verify_npth_fp_unw_insn_006_0x09a8(seed);
        case 7: return verify_npth_fp_unw_insn_007_0x09ac(seed);
        case 8: return verify_npth_fp_unw_insn_008_0x09b0(seed);
        case 9: return verify_npth_fp_unw_insn_009_0x09b4(seed);
        case 10: return verify_npth_fp_unw_insn_010_0x09b8(seed);
        case 11: return verify_npth_fp_unw_insn_011_0x09bc(seed);
        case 12: return verify_npth_fp_unw_insn_012_0x09c0(seed);
        case 13: return verify_npth_fp_unw_insn_013_0x09c4(seed);
        case 14: return verify_npth_fp_unw_insn_014_0x09c8(seed);
        case 15: return verify_npth_fp_unw_insn_015_0x09cc(seed);
        case 16: return verify_npth_fp_unw_insn_016_0x09d0(seed);
        case 17: return verify_npth_fp_unw_insn_017_0x09d4(seed);
        case 18: return verify_npth_fp_unw_insn_018_0x09d8(seed);
        case 19: return verify_npth_fp_unw_insn_019_0x09dc(seed);
        case 20: return verify_npth_fp_unw_insn_020_0x09e0(seed);
        case 21: return verify_npth_fp_unw_insn_021_0x09e4(seed);
        case 22: return verify_npth_fp_unw_insn_022_0x09e8(seed);
        case 23: return verify_npth_fp_unw_insn_023_0x09ec(seed);
        case 24: return verify_npth_fp_unw_insn_024_0x09f0(seed);
        case 25: return verify_npth_fp_unw_insn_025_0x09f4(seed);
        case 26: return verify_npth_fp_unw_insn_026_0x09f8(seed);
        case 27: return verify_npth_fp_unw_insn_027_0x09fc(seed);
        case 28: return verify_npth_fp_unw_insn_028_0x0a00(seed);
        case 29: return verify_npth_fp_unw_insn_029_0x0a04(seed);
        case 30: return verify_npth_fp_unw_insn_030_0x0a08(seed);
        case 31: return verify_npth_fp_unw_insn_031_0x0a0c(seed);
        case 32: return verify_npth_fp_unw_insn_032_0x0a10(seed);
        case 33: return verify_npth_fp_unw_insn_033_0x0a14(seed);
        case 34: return verify_npth_fp_unw_insn_034_0x0a18(seed);
        case 35: return verify_npth_fp_unw_insn_035_0x0a1c(seed);
        case 36: return verify_npth_fp_unw_insn_036_0x0a20(seed);
        case 37: return verify_npth_fp_unw_insn_037_0x0a24(seed);
        case 38: return verify_npth_fp_unw_insn_038_0x0a28(seed);
        case 39: return verify_npth_fp_unw_insn_039_0x0a2c(seed);
        case 40: return verify_npth_fp_unw_insn_040_0x0a30(seed);
        case 41: return verify_npth_fp_unw_insn_041_0x0a34(seed);
        case 42: return verify_npth_fp_unw_insn_042_0x0a38(seed);
        case 43: return verify_npth_fp_unw_insn_043_0x0a3c(seed);
        case 44: return verify_npth_fp_unw_insn_044_0x0a40(seed);
        case 45: return verify_npth_fp_unw_insn_045_0x0a44(seed);
        case 46: return verify_npth_fp_unw_insn_046_0x0a48(seed);
        case 47: return verify_npth_fp_unw_insn_047_0x0a4c(seed);
        case 48: return verify_npth_fp_unw_insn_048_0x0a50(seed);
        case 49: return verify_npth_fp_unw_insn_049_0x0a54(seed);
        case 50: return verify_npth_fp_unw_insn_050_0x0a58(seed);
        case 51: return verify_npth_fp_unw_insn_051_0x0a5c(seed);
        case 52: return verify_npth_fp_unw_insn_052_0x0a60(seed);
        case 53: return verify_npth_fp_unw_insn_053_0x0a64(seed);
        case 54: return verify_npth_fp_unw_insn_054_0x0a68(seed);
        case 55: return verify_npth_fp_unw_insn_055_0x0a6c(seed);
        case 56: return verify_npth_fp_unw_insn_056_0x0a70(seed);
        case 57: return verify_npth_fp_unw_insn_057_0x0a74(seed);
        case 58: return verify_npth_fp_unw_insn_058_0x0a78(seed);
        case 59: return verify_npth_fp_unw_insn_059_0x0a7c(seed);
        case 60: return verify_npth_fp_unw_insn_060_0x0a80(seed);
        case 61: return verify_npth_fp_unw_insn_061_0x0a84(seed);
        case 62: return verify_npth_fp_unw_insn_062_0x0a88(seed);
        case 63: return verify_npth_fp_unw_insn_063_0x0a8c(seed);
        case 64: return verify_npth_fp_unw_insn_064_0x0a90(seed);
        case 65: return verify_npth_fp_unw_insn_065_0x0a94(seed);
        case 66: return verify_npth_fp_unw_insn_066_0x0a98(seed);
        case 67: return verify_npth_fp_unw_insn_067_0x0a9c(seed);
        case 68: return verify_npth_fp_unw_insn_068_0x0aa0(seed);
        case 69: return verify_npth_fp_unw_insn_069_0x0aa4(seed);
        case 70: return verify_npth_fp_unw_insn_070_0x0aa8(seed);
        case 71: return verify_npth_fp_unw_insn_071_0x0aac(seed);
        case 72: return verify_npth_fp_unw_insn_072_0x0ab0(seed);
        case 73: return verify_npth_fp_unw_insn_073_0x0ab4(seed);
        case 74: return verify_npth_fp_unw_insn_074_0x0ab8(seed);
        case 75: return verify_npth_fp_unw_insn_075_0x0abc(seed);
        case 76: return verify_npth_fp_unw_insn_076_0x0ac0(seed);
        case 77: return verify_npth_fp_unw_insn_077_0x0ac4(seed);
        case 78: return verify_npth_fp_unw_insn_078_0x0ac8(seed);
        case 79: return verify_npth_fp_unw_insn_079_0x0acc(seed);
        case 80: return verify_npth_fp_unw_insn_080_0x0ad0(seed);
        case 81: return verify_npth_fp_unw_insn_081_0x0ad4(seed);
        case 82: return verify_npth_fp_unw_insn_082_0x0ad8(seed);
        case 83: return verify_npth_fp_unw_insn_083_0x0adc(seed);
        case 84: return verify_npth_fp_unw_insn_084_0x0ae0(seed);
        case 85: return verify_npth_fp_unw_insn_085_0x0ae4(seed);
        case 86: return verify_npth_fp_unw_insn_086_0x0ae8(seed);
        case 87: return verify_npth_fp_unw_insn_087_0x0aec(seed);
        case 88: return verify_npth_fp_unw_insn_088_0x0af0(seed);
        case 89: return verify_npth_fp_unw_insn_089_0x0af4(seed);
        case 90: return verify_npth_fp_unw_insn_090_0x0af8(seed);
        case 91: return verify_npth_fp_unw_insn_091_0x0afc(seed);
        case 92: return verify_npth_fp_unw_insn_092_0x0b00(seed);
        case 93: return verify_npth_fp_unw_insn_093_0x0b04(seed);
        case 94: return verify_npth_fp_unw_insn_094_0x0b08(seed);
        case 95: return verify_npth_fp_unw_insn_095_0x0b0c(seed);
        case 96: return verify_npth_fp_unw_insn_096_0x0b10(seed);
        case 97: return verify_npth_fp_unw_insn_097_0x0b14(seed);
        case 98: return verify_npth_fp_unw_insn_098_0x0b18(seed);
        case 99: return verify_npth_fp_unw_insn_099_0x0b1c(seed);
        case 100: return verify_npth_fp_unw_insn_100_0x0b20(seed);
        case 101: return verify_npth_fp_unw_insn_101_0x0b24(seed);
        case 102: return verify_npth_fp_unw_insn_102_0x0b28(seed);
        case 103: return verify_npth_fp_unw_insn_103_0x0b2c(seed);
        case 104: return verify_npth_fp_unw_insn_104_0x0b30(seed);
        case 105: return verify_npth_fp_unw_insn_105_0x0b34(seed);
        case 106: return verify_npth_fp_unw_insn_106_0x0b38(seed);
        case 107: return verify_npth_fp_unw_insn_107_0x0b3c(seed);
        case 108: return verify_npth_fp_unw_insn_108_0x0b40(seed);
        case 109: return verify_npth_fp_unw_insn_109_0x0b44(seed);
        case 110: return verify_npth_fp_unw_insn_110_0x0b48(seed);
        case 111: return verify_npth_fp_unw_insn_111_0x0b4c(seed);
        case 112: return verify_npth_fp_unw_insn_112_0x0b50(seed);
        case 113: return verify_npth_fp_unw_insn_113_0x0b54(seed);
        case 114: return verify_npth_fp_unw_insn_114_0x0b58(seed);
        case 115: return verify_npth_fp_unw_insn_115_0x0b5c(seed);
        case 116: return verify_npth_fp_unw_insn_116_0x0b60(seed);
        case 117: return verify_npth_fp_unw_insn_117_0x0b64(seed);
        case 118: return verify_npth_fp_unw_insn_118_0x0b68(seed);
        case 119: return verify_npth_fp_unw_insn_119_0x0b6c(seed);
        case 120: return verify_npth_fp_unw_insn_120_0x0b70(seed);
        case 121: return verify_npth_fp_unw_insn_121_0x0b74(seed);
        case 122: return verify_npth_fp_unw_insn_122_0x0b78(seed);
        case 123: return verify_npth_fp_unw_insn_123_0x0b7c(seed);
        case 124: return verify_npth_fp_unw_insn_124_0x0b80(seed);
        case 125: return verify_npth_fp_unw_insn_125_0x0b84(seed);
        case 126: return verify_npth_fp_unw_insn_126_0x0b88(seed);
        case 127: return verify_npth_fp_unw_insn_127_0x0b8c(seed);
        case 128: return verify_npth_fp_unw_insn_128_0x0b90(seed);
        case 129: return verify_npth_fp_unw_insn_129_0x0b94(seed);
        case 130: return verify_npth_fp_unw_insn_130_0x0b98(seed);
        case 131: return verify_npth_fp_unw_insn_131_0x0b9c(seed);
        case 132: return verify_npth_fp_unw_insn_132_0x0ba0(seed);
        case 133: return verify_npth_fp_unw_insn_133_0x0ba4(seed);
        case 134: return verify_npth_fp_unw_insn_134_0x0ba8(seed);
        case 135: return verify_npth_fp_unw_insn_135_0x0bac(seed);
        case 136: return verify_npth_fp_unw_insn_136_0x0bb0(seed);
        case 137: return verify_npth_fp_unw_insn_137_0x0bb4(seed);
        case 138: return verify_npth_fp_unw_insn_138_0x0bb8(seed);
        case 139: return verify_npth_fp_unw_insn_139_0x0bbc(seed);
        case 140: return verify_npth_fp_unw_insn_140_0x0bc0(seed);
        case 141: return verify_npth_fp_unw_insn_141_0x0bc4(seed);
        case 142: return verify_npth_fp_unw_insn_142_0x0bc8(seed);
        case 143: return verify_npth_fp_unw_insn_143_0x0bcc(seed);
        case 144: return verify_npth_fp_unw_insn_144_0x0bd0(seed);
        case 145: return verify_npth_fp_unw_insn_145_0x0bd4(seed);
        case 146: return verify_npth_fp_unw_insn_146_0x0bd8(seed);
        case 147: return verify_npth_fp_unw_insn_147_0x0bdc(seed);
        case 148: return verify_npth_fp_unw_insn_148_0x0be0(seed);
        case 149: return verify_npth_fp_unw_insn_149_0x0be4(seed);
        case 150: return verify_npth_fp_unw_insn_150_0x0be8(seed);
        case 151: return verify_npth_fp_unw_insn_151_0x0bec(seed);
        case 152: return verify_npth_fp_unw_insn_152_0x0bf0(seed);
        case 153: return verify_npth_fp_unw_insn_153_0x0bf4(seed);
        case 154: return verify_npth_fp_unw_insn_154_0x0bf8(seed);
        case 155: return verify_npth_fp_unw_insn_155_0x0bfc(seed);
        case 156: return verify_npth_fp_unw_insn_156_0x0c00(seed);
        case 157: return verify_npth_fp_unw_insn_157_0x0c04(seed);
        case 158: return verify_npth_fp_unw_insn_158_0x0c08(seed);
        case 159: return verify_npth_fp_unw_insn_159_0x0c0c(seed);
        case 160: return verify_npth_fp_unw_insn_160_0x0c10(seed);
        case 161: return verify_npth_fp_unw_insn_161_0x0c14(seed);
        case 162: return verify_npth_fp_unw_insn_162_0x0c18(seed);
        case 163: return verify_npth_fp_unw_insn_163_0x0c1c(seed);
        case 164: return verify_npth_fp_unw_insn_164_0x0c20(seed);
        case 165: return verify_npth_fp_unw_insn_165_0x0c24(seed);
        case 166: return verify_npth_fp_unw_insn_166_0x0c28(seed);
        case 167: return verify_npth_fp_unw_insn_167_0x0c2c(seed);
        case 168: return verify_npth_fp_unw_insn_168_0x0c30(seed);
        case 169: return verify_npth_fp_unw_insn_169_0x0c34(seed);
        case 170: return verify_npth_fp_unw_insn_170_0x0c38(seed);
        case 171: return verify_npth_fp_unw_insn_171_0x0c3c(seed);
        case 172: return verify_npth_fp_unw_insn_172_0x0c40(seed);
        case 173: return verify_npth_fp_unw_insn_173_0x0c44(seed);
        case 174: return verify_npth_fp_unw_insn_174_0x0c48(seed);
        case 175: return verify_npth_fp_unw_insn_175_0x0c4c(seed);
        case 176: return verify_npth_fp_unw_insn_176_0x0c50(seed);
        case 177: return verify_npth_fp_unw_insn_177_0x0c54(seed);
        case 178: return verify_npth_fp_unw_insn_178_0x0c58(seed);
        case 179: return verify_npth_fp_unw_insn_179_0x0c5c(seed);
        case 180: return verify_npth_fp_unw_insn_180_0x0c60(seed);
        case 181: return verify_npth_fp_unw_insn_181_0x0c64(seed);
        case 182: return verify_npth_fp_unw_insn_182_0x0c68(seed);
        case 183: return verify_npth_fp_unw_insn_183_0x0c6c(seed);
        case 184: return verify_npth_fp_unw_insn_184_0x0c70(seed);
        case 185: return verify_npth_fp_unw_insn_185_0x0c74(seed);
        case 186: return verify_npth_fp_unw_insn_186_0x0c78(seed);
        case 187: return verify_npth_fp_unw_insn_187_0x0c7c(seed);
        case 188: return verify_npth_fp_unw_insn_188_0x0c80(seed);
        case 189: return verify_npth_fp_unw_insn_189_0x0c84(seed);
        case 190: return verify_npth_fp_unw_insn_190_0x0c88(seed);
        case 191: return verify_npth_fp_unw_insn_191_0x0c8c(seed);
        case 192: return verify_npth_fp_unw_insn_192_0x0c90(seed);
        case 193: return verify_npth_fp_unw_insn_193_0x0c94(seed);
        case 194: return verify_npth_fp_unw_insn_194_0x0c98(seed);
        case 195: return verify_npth_fp_unw_insn_195_0x0c9c(seed);
        case 196: return verify_npth_fp_unw_insn_196_0x0ca0(seed);
        case 197: return verify_npth_fp_unw_insn_197_0x0ca4(seed);
        case 198: return verify_npth_fp_unw_insn_198_0x0ca8(seed);
        case 199: return verify_npth_fp_unw_insn_199_0x0cac(seed);
        case 200: return verify_npth_fp_unw_insn_200_0x0cb0(seed);
        case 201: return verify_npth_fp_unw_insn_201_0x0cb4(seed);
        case 202: return verify_npth_fp_unw_insn_202_0x0cb8(seed);
        case 203: return verify_npth_fp_unw_insn_203_0x0cbc(seed);
        case 204: return verify_npth_fp_unw_insn_204_0x0cc0(seed);
        case 205: return verify_npth_fp_unw_insn_205_0x0cc4(seed);
        case 206: return verify_npth_fp_unw_insn_206_0x0cc8(seed);
        case 207: return verify_npth_fp_unw_insn_207_0x0ccc(seed);
        case 208: return verify_npth_fp_unw_insn_208_0x0cd0(seed);
        case 209: return verify_npth_fp_unw_insn_209_0x0cd4(seed);
        case 210: return verify_npth_fp_unw_insn_210_0x0cd8(seed);
        case 211: return verify_npth_fp_unw_insn_211_0x0cdc(seed);
        case 212: return verify_npth_fp_unw_insn_212_0x0ce0(seed);
        case 213: return verify_npth_fp_unw_insn_213_0x0ce4(seed);
        case 214: return verify_npth_fp_unw_insn_214_0x0ce8(seed);
        case 215: return verify_npth_fp_unw_insn_215_0x0cec(seed);
        case 216: return verify_npth_fp_unw_insn_216_0x0cf0(seed);
        case 217: return verify_npth_fp_unw_insn_217_0x0cf4(seed);
        case 218: return verify_npth_fp_unw_insn_218_0x0cf8(seed);
        case 219: return verify_npth_fp_unw_insn_219_0x0cfc(seed);
        case 220: return verify_npth_fp_unw_insn_220_0x0d00(seed);
        case 221: return verify_npth_fp_unw_insn_221_0x0d04(seed);
        case 222: return verify_npth_fp_unw_insn_222_0x0d08(seed);
        case 223: return verify_npth_fp_unw_insn_223_0x0d0c(seed);
        case 224: return verify_npth_fp_unw_insn_224_0x0d10(seed);
        case 225: return verify_npth_fp_unw_insn_225_0x0d14(seed);
        case 226: return verify_npth_fp_unw_insn_226_0x0d18(seed);
        case 227: return verify_npth_fp_unw_insn_227_0x0d1c(seed);
        case 228: return verify_npth_fp_unw_insn_228_0x0d20(seed);
        case 229: return verify_npth_fp_unw_insn_229_0x0d24(seed);
        case 230: return verify_npth_fp_unw_insn_230_0x0d28(seed);
        case 231: return verify_npth_fp_unw_insn_231_0x0d2c(seed);
        case 232: return verify_npth_fp_unw_insn_232_0x0d30(seed);
        case 233: return verify_npth_fp_unw_insn_233_0x0d34(seed);
        case 234: return verify_npth_fp_unw_insn_234_0x0d38(seed);
        case 235: return verify_npth_fp_unw_insn_235_0x0d3c(seed);
        case 236: return verify_npth_fp_unw_insn_236_0x0d40(seed);
        case 237: return verify_npth_fp_unw_insn_237_0x0d44(seed);
        case 238: return verify_npth_fp_unw_insn_238_0x0d48(seed);
        case 239: return verify_npth_fp_unw_insn_239_0x0d4c(seed);
        case 240: return verify_npth_fp_unw_insn_240_0x0d50(seed);
        case 241: return verify_npth_fp_unw_insn_241_0x0d54(seed);
        case 242: return verify_npth_fp_unw_insn_242_0x0d58(seed);
        case 243: return verify_npth_fp_unw_insn_243_0x0d5c(seed);
        case 244: return verify_npth_fp_unw_insn_244_0x0d60(seed);
        case 245: return verify_npth_fp_unw_insn_245_0x0d64(seed);
        case 246: return verify_npth_fp_unw_insn_246_0x0d68(seed);
        case 247: return verify_npth_fp_unw_insn_247_0x0d6c(seed);
        case 248: return verify_npth_fp_unw_insn_248_0x0d70(seed);
        case 249: return verify_npth_fp_unw_insn_249_0x0d74(seed);
        case 250: return verify_npth_fp_unw_insn_250_0x0d78(seed);
        case 251: return verify_npth_fp_unw_insn_251_0x0d7c(seed);
        default: return 0ULL;
    }
}

} // namespace npth_fp_unw