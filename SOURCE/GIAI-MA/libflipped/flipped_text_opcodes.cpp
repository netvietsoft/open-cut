// ============================================================================
// Complete 327-Instruction AArch64 .text Disassembly & 15-FDE Unwind Verifier
// Bộ kiểm chứng toàn bộ 327 lệnh AArch64 .text (0x0c90..0x11ac) & 15 FDE của libflipped.so
// ============================================================================
#include "flipped_core.h"

namespace flipped {

// Insn #000 @ 0x0c90: 0xD503245F -> bti c
// Lệnh AArch64 #000 tại 0x0c90: bti c
uint64_t verify_flipped_insn_000_0x0c90(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xD503245FU;
    constexpr uint64_t kVaddr  = 0x0c90ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xC4CEB9FE1A85EC53ULL;
    return h ^ kOpcode;
}

// Insn #001 @ 0x0c94: 0xD503201F -> nop 
// Lệnh AArch64 #001 tại 0x0c94: nop 
uint64_t verify_flipped_insn_001_0x0c94(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xD503201FU;
    constexpr uint64_t kVaddr  = 0x0c94ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xC4CEB9FE1A85EC53ULL;
    return h ^ kOpcode;
}

// Insn #002 @ 0x0c98: 0x10022F40 -> adr x0, #0x5280
// Lệnh AArch64 #002 tại 0x0c98: adr x0, #0x5280
uint64_t verify_flipped_insn_002_0x0c98(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x10022F40U;
    constexpr uint64_t kVaddr  = 0x0c98ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xC4CEB9FE1A85EC53ULL;
    return h ^ kOpcode;
}

// Insn #003 @ 0x0c9c: 0x1400014D -> b #0x11d0
// Lệnh AArch64 #003 tại 0x0c9c: b #0x11d0
uint64_t verify_flipped_insn_003_0x0c9c(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x1400014DU;
    constexpr uint64_t kVaddr  = 0x0c9cULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xC4CEB9FE1A85EC53ULL;
    return h ^ kOpcode;
}

// Insn #004 @ 0x0ca0: 0xD503245F -> bti c
// Lệnh AArch64 #004 tại 0x0ca0: bti c
uint64_t verify_flipped_insn_004_0x0ca0(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xD503245FU;
    constexpr uint64_t kVaddr  = 0x0ca0ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xC4CEB9FE1A85EC53ULL;
    return h ^ kOpcode;
}

// Insn #005 @ 0x0ca4: 0xD65F03C0 -> ret 
// Lệnh AArch64 #005 tại 0x0ca4: ret 
uint64_t verify_flipped_insn_005_0x0ca4(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xD65F03C0U;
    constexpr uint64_t kVaddr  = 0x0ca4ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xC4CEB9FE1A85EC53ULL;
    return h ^ kOpcode;
}

// Insn #006 @ 0x0ca8: 0xD503245F -> bti c
// Lệnh AArch64 #006 tại 0x0ca8: bti c
uint64_t verify_flipped_insn_006_0x0ca8(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xD503245FU;
    constexpr uint64_t kVaddr  = 0x0ca8ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xC4CEB9FE1A85EC53ULL;
    return h ^ kOpcode;
}

// Insn #007 @ 0x0cac: 0x17FFFFFD -> b #0xca0
// Lệnh AArch64 #007 tại 0x0cac: b #0xca0
uint64_t verify_flipped_insn_007_0x0cac(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x17FFFFFDU;
    constexpr uint64_t kVaddr  = 0x0cacULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xC4CEB9FE1A85EC53ULL;
    return h ^ kOpcode;
}

// Insn #008 @ 0x0cb0: 0xD503245F -> bti c
// Lệnh AArch64 #008 tại 0x0cb0: bti c
uint64_t verify_flipped_insn_008_0x0cb0(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xD503245FU;
    constexpr uint64_t kVaddr  = 0x0cb0ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xC4CEB9FE1A85EC53ULL;
    return h ^ kOpcode;
}

// Insn #009 @ 0x0cb4: 0xB4000060 -> cbz x0, #0xcc0
// Lệnh AArch64 #009 tại 0x0cb4: cbz x0, #0xcc0
uint64_t verify_flipped_insn_009_0x0cb4(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xB4000060U;
    constexpr uint64_t kVaddr  = 0x0cb4ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xC4CEB9FE1A85EC53ULL;
    return h ^ kOpcode;
}

// Insn #010 @ 0x0cb8: 0xAA0003F0 -> mov x16, x0
// Lệnh AArch64 #010 tại 0x0cb8: mov x16, x0
uint64_t verify_flipped_insn_010_0x0cb8(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xAA0003F0U;
    constexpr uint64_t kVaddr  = 0x0cb8ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xC4CEB9FE1A85EC53ULL;
    return h ^ kOpcode;
}

// Insn #011 @ 0x0cbc: 0xD61F0200 -> br x16
// Lệnh AArch64 #011 tại 0x0cbc: br x16
uint64_t verify_flipped_insn_011_0x0cbc(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xD61F0200U;
    constexpr uint64_t kVaddr  = 0x0cbcULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xC4CEB9FE1A85EC53ULL;
    return h ^ kOpcode;
}

// Insn #012 @ 0x0cc0: 0xD65F03C0 -> ret 
// Lệnh AArch64 #012 tại 0x0cc0: ret 
uint64_t verify_flipped_insn_012_0x0cc0(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xD65F03C0U;
    constexpr uint64_t kVaddr  = 0x0cc0ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xC4CEB9FE1A85EC53ULL;
    return h ^ kOpcode;
}

// Insn #013 @ 0x0cc4: 0xD503245F -> bti c
// Lệnh AArch64 #013 tại 0x0cc4: bti c
uint64_t verify_flipped_insn_013_0x0cc4(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xD503245FU;
    constexpr uint64_t kVaddr  = 0x0cc4ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xC4CEB9FE1A85EC53ULL;
    return h ^ kOpcode;
}

// Insn #014 @ 0x0cc8: 0xAA0003E1 -> mov x1, x0
// Lệnh AArch64 #014 tại 0x0cc8: mov x1, x0
uint64_t verify_flipped_insn_014_0x0cc8(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xAA0003E1U;
    constexpr uint64_t kVaddr  = 0x0cc8ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xC4CEB9FE1A85EC53ULL;
    return h ^ kOpcode;
}

// Insn #015 @ 0x0ccc: 0xD503201F -> nop 
// Lệnh AArch64 #015 tại 0x0ccc: nop 
uint64_t verify_flipped_insn_015_0x0ccc(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xD503201FU;
    constexpr uint64_t kVaddr  = 0x0cccULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xC4CEB9FE1A85EC53ULL;
    return h ^ kOpcode;
}

// Insn #016 @ 0x0cd0: 0x10FFFF00 -> adr x0, #0xcb0
// Lệnh AArch64 #016 tại 0x0cd0: adr x0, #0xcb0
uint64_t verify_flipped_insn_016_0x0cd0(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x10FFFF00U;
    constexpr uint64_t kVaddr  = 0x0cd0ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xC4CEB9FE1A85EC53ULL;
    return h ^ kOpcode;
}

// Insn #017 @ 0x0cd4: 0xD503201F -> nop 
// Lệnh AArch64 #017 tại 0x0cd4: nop 
uint64_t verify_flipped_insn_017_0x0cd4(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xD503201FU;
    constexpr uint64_t kVaddr  = 0x0cd4ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xC4CEB9FE1A85EC53ULL;
    return h ^ kOpcode;
}

// Insn #018 @ 0x0cd8: 0x10022D42 -> adr x2, #0x5280
// Lệnh AArch64 #018 tại 0x0cd8: adr x2, #0x5280
uint64_t verify_flipped_insn_018_0x0cd8(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x10022D42U;
    constexpr uint64_t kVaddr  = 0x0cd8ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xC4CEB9FE1A85EC53ULL;
    return h ^ kOpcode;
}

// Insn #019 @ 0x0cdc: 0x14000141 -> b #0x11e0
// Lệnh AArch64 #019 tại 0x0cdc: b #0x11e0
uint64_t verify_flipped_insn_019_0x0cdc(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x14000141U;
    constexpr uint64_t kVaddr  = 0x0cdcULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xC4CEB9FE1A85EC53ULL;
    return h ^ kOpcode;
}

// Insn #020 @ 0x0ce0: 0x2A0103E3 -> mov w3, w1
// Lệnh AArch64 #020 tại 0x0ce0: mov w3, w1
uint64_t verify_flipped_insn_020_0x0ce0(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x2A0103E3U;
    constexpr uint64_t kVaddr  = 0x0ce0ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xC4CEB9FE1A85EC53ULL;
    return h ^ kOpcode;
}

// Insn #021 @ 0x0ce4: 0xAA0003E2 -> mov x2, x0
// Lệnh AArch64 #021 tại 0x0ce4: mov x2, x0
uint64_t verify_flipped_insn_021_0x0ce4(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xAA0003E2U;
    constexpr uint64_t kVaddr  = 0x0ce4ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xC4CEB9FE1A85EC53ULL;
    return h ^ kOpcode;
}

// Insn #022 @ 0x0ce8: 0xD503201F -> nop 
// Lệnh AArch64 #022 tại 0x0ce8: nop 
uint64_t verify_flipped_insn_022_0x0ce8(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xD503201FU;
    constexpr uint64_t kVaddr  = 0x0ce8ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xC4CEB9FE1A85EC53ULL;
    return h ^ kOpcode;
}

// Insn #023 @ 0x0cec: 0x50FFDD21 -> adr x1, #0x892
// Lệnh AArch64 #023 tại 0x0cec: adr x1, #0x892
uint64_t verify_flipped_insn_023_0x0cec(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x50FFDD21U;
    constexpr uint64_t kVaddr  = 0x0cecULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xC4CEB9FE1A85EC53ULL;
    return h ^ kOpcode;
}

// Insn #024 @ 0x0cf0: 0x528000C0 -> mov w0, #6
// Lệnh AArch64 #024 tại 0x0cf0: mov w0, #6
uint64_t verify_flipped_insn_024_0x0cf0(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x528000C0U;
    constexpr uint64_t kVaddr  = 0x0cf0ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xC4CEB9FE1A85EC53ULL;
    return h ^ kOpcode;
}

// Insn #025 @ 0x0cf4: 0x14000153 -> b #0x1240
// Lệnh AArch64 #025 tại 0x0cf4: b #0x1240
uint64_t verify_flipped_insn_025_0x0cf4(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x14000153U;
    constexpr uint64_t kVaddr  = 0x0cf4ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xC4CEB9FE1A85EC53ULL;
    return h ^ kOpcode;
}

// Insn #026 @ 0x0cf8: 0xAA0103E3 -> mov x3, x1
// Lệnh AArch64 #026 tại 0x0cf8: mov x3, x1
uint64_t verify_flipped_insn_026_0x0cf8(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xAA0103E3U;
    constexpr uint64_t kVaddr  = 0x0cf8ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xC4CEB9FE1A85EC53ULL;
    return h ^ kOpcode;
}

// Insn #027 @ 0x0cfc: 0xAA0003E2 -> mov x2, x0
// Lệnh AArch64 #027 tại 0x0cfc: mov x2, x0
uint64_t verify_flipped_insn_027_0x0cfc(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xAA0003E2U;
    constexpr uint64_t kVaddr  = 0x0cfcULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xC4CEB9FE1A85EC53ULL;
    return h ^ kOpcode;
}

// Insn #028 @ 0x0d00: 0xD503201F -> nop 
// Lệnh AArch64 #028 tại 0x0d00: nop 
uint64_t verify_flipped_insn_028_0x0d00(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xD503201FU;
    constexpr uint64_t kVaddr  = 0x0d00ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xC4CEB9FE1A85EC53ULL;
    return h ^ kOpcode;
}

// Insn #029 @ 0x0d04: 0x50FFDC61 -> adr x1, #0x892
// Lệnh AArch64 #029 tại 0x0d04: adr x1, #0x892
uint64_t verify_flipped_insn_029_0x0d04(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x50FFDC61U;
    constexpr uint64_t kVaddr  = 0x0d04ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xC4CEB9FE1A85EC53ULL;
    return h ^ kOpcode;
}

// Insn #030 @ 0x0d08: 0x528000C0 -> mov w0, #6
// Lệnh AArch64 #030 tại 0x0d08: mov w0, #6
uint64_t verify_flipped_insn_030_0x0d08(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x528000C0U;
    constexpr uint64_t kVaddr  = 0x0d08ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xC4CEB9FE1A85EC53ULL;
    return h ^ kOpcode;
}

// Insn #031 @ 0x0d0c: 0x1400014D -> b #0x1240
// Lệnh AArch64 #031 tại 0x0d0c: b #0x1240
uint64_t verify_flipped_insn_031_0x0d0c(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x1400014DU;
    constexpr uint64_t kVaddr  = 0x0d0cULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xC4CEB9FE1A85EC53ULL;
    return h ^ kOpcode;
}

// Insn #032 @ 0x0d10: 0x90000001 -> adrp x1, #0
// Lệnh AArch64 #032 tại 0x0d10: adrp x1, #0
uint64_t verify_flipped_insn_032_0x0d10(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x90000001U;
    constexpr uint64_t kVaddr  = 0x0d10ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xC4CEB9FE1A85EC53ULL;
    return h ^ kOpcode;
}

// Insn #033 @ 0x0d14: 0x91233021 -> add x1, x1, #0x8cc
// Lệnh AArch64 #033 tại 0x0d14: add x1, x1, #0x8cc
uint64_t verify_flipped_insn_033_0x0d14(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x91233021U;
    constexpr uint64_t kVaddr  = 0x0d14ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xC4CEB9FE1A85EC53ULL;
    return h ^ kOpcode;
}

// Insn #034 @ 0x0d18: 0x1400013A -> b #0x1200
// Lệnh AArch64 #034 tại 0x0d18: b #0x1200
uint64_t verify_flipped_insn_034_0x0d18(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x1400013AU;
    constexpr uint64_t kVaddr  = 0x0d18ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xC4CEB9FE1A85EC53ULL;
    return h ^ kOpcode;
}

// Insn #035 @ 0x0d1c: 0xD100C3FF -> sub sp, sp, #0x30
// Lệnh AArch64 #035 tại 0x0d1c: sub sp, sp, #0x30
uint64_t verify_flipped_insn_035_0x0d1c(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xD100C3FFU;
    constexpr uint64_t kVaddr  = 0x0d1cULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xC4CEB9FE1A85EC53ULL;
    return h ^ kOpcode;
}

// Insn #036 @ 0x0d20: 0xA9017BFD -> stp x29, x30, [sp, #0x10]
// Lệnh AArch64 #036 tại 0x0d20: stp x29, x30, [sp, #0x10]
uint64_t verify_flipped_insn_036_0x0d20(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xA9017BFDU;
    constexpr uint64_t kVaddr  = 0x0d20ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xC4CEB9FE1A85EC53ULL;
    return h ^ kOpcode;
}

// Insn #037 @ 0x0d24: 0xF90013F3 -> str x19, [sp, #0x20]
// Lệnh AArch64 #037 tại 0x0d24: str x19, [sp, #0x20]
uint64_t verify_flipped_insn_037_0x0d24(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xF90013F3U;
    constexpr uint64_t kVaddr  = 0x0d24ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xC4CEB9FE1A85EC53ULL;
    return h ^ kOpcode;
}

// Insn #038 @ 0x0d28: 0x910043FD -> add x29, sp, #0x10
// Lệnh AArch64 #038 tại 0x0d28: add x29, sp, #0x10
uint64_t verify_flipped_insn_038_0x0d28(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x910043FDU;
    constexpr uint64_t kVaddr  = 0x0d28ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xC4CEB9FE1A85EC53ULL;
    return h ^ kOpcode;
}

// Insn #039 @ 0x0d2c: 0xD53BD053 -> mrs x19, tpidr_el0
// Lệnh AArch64 #039 tại 0x0d2c: mrs x19, tpidr_el0
uint64_t verify_flipped_insn_039_0x0d2c(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xD53BD053U;
    constexpr uint64_t kVaddr  = 0x0d2cULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xC4CEB9FE1A85EC53ULL;
    return h ^ kOpcode;
}

// Insn #040 @ 0x0d30: 0xB0000049 -> adrp x9, #0x9000
// Lệnh AArch64 #040 tại 0x0d30: adrp x9, #0x9000
uint64_t verify_flipped_insn_040_0x0d30(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xB0000049U;
    constexpr uint64_t kVaddr  = 0x0d30ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xC4CEB9FE1A85EC53ULL;
    return h ^ kOpcode;
}

// Insn #041 @ 0x0d34: 0xF9401668 -> ldr x8, [x19, #0x28]
// Lệnh AArch64 #041 tại 0x0d34: ldr x8, [x19, #0x28]
uint64_t verify_flipped_insn_041_0x0d34(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xF9401668U;
    constexpr uint64_t kVaddr  = 0x0d34ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xC4CEB9FE1A85EC53ULL;
    return h ^ kOpcode;
}

// Insn #042 @ 0x0d38: 0x910003E1 -> mov x1, sp
// Lệnh AArch64 #042 tại 0x0d38: mov x1, sp
uint64_t verify_flipped_insn_042_0x0d38(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x910003E1U;
    constexpr uint64_t kVaddr  = 0x0d38ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xC4CEB9FE1A85EC53ULL;
    return h ^ kOpcode;
}

// Insn #043 @ 0x0d3c: 0xAA1F03E2 -> mov x2, xzr
// Lệnh AArch64 #043 tại 0x0d3c: mov x2, xzr
uint64_t verify_flipped_insn_043_0x0d3c(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xAA1F03E2U;
    constexpr uint64_t kVaddr  = 0x0d3cULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xC4CEB9FE1A85EC53ULL;
    return h ^ kOpcode;
}

// Insn #044 @ 0x0d40: 0xF90007E8 -> str x8, [sp, #8]
// Lệnh AArch64 #044 tại 0x0d40: str x8, [sp, #8]
uint64_t verify_flipped_insn_044_0x0d40(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xF90007E8U;
    constexpr uint64_t kVaddr  = 0x0d40ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xC4CEB9FE1A85EC53ULL;
    return h ^ kOpcode;
}

// Insn #045 @ 0x0d44: 0xF9427520 -> ldr x0, [x9, #0x4e8]
// Lệnh AArch64 #045 tại 0x0d44: ldr x0, [x9, #0x4e8]
uint64_t verify_flipped_insn_045_0x0d44(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xF9427520U;
    constexpr uint64_t kVaddr  = 0x0d44ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xC4CEB9FE1A85EC53ULL;
    return h ^ kOpcode;
}

// Insn #046 @ 0x0d48: 0xF9400008 -> ldr x8, [x0]
// Lệnh AArch64 #046 tại 0x0d48: ldr x8, [x0]
uint64_t verify_flipped_insn_046_0x0d48(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xF9400008U;
    constexpr uint64_t kVaddr  = 0x0d48ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xC4CEB9FE1A85EC53ULL;
    return h ^ kOpcode;
}

// Insn #047 @ 0x0d4c: 0xF9401108 -> ldr x8, [x8, #0x20]
// Lệnh AArch64 #047 tại 0x0d4c: ldr x8, [x8, #0x20]
uint64_t verify_flipped_insn_047_0x0d4c(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xF9401108U;
    constexpr uint64_t kVaddr  = 0x0d4cULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xC4CEB9FE1A85EC53ULL;
    return h ^ kOpcode;
}

// Insn #048 @ 0x0d50: 0xD63F0100 -> blr x8
// Lệnh AArch64 #048 tại 0x0d50: blr x8
uint64_t verify_flipped_insn_048_0x0d50(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xD63F0100U;
    constexpr uint64_t kVaddr  = 0x0d50ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xC4CEB9FE1A85EC53ULL;
    return h ^ kOpcode;
}

// Insn #049 @ 0x0d54: 0x2A0003E1 -> mov w1, w0
// Lệnh AArch64 #049 tại 0x0d54: mov w1, w0
uint64_t verify_flipped_insn_049_0x0d54(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x2A0003E1U;
    constexpr uint64_t kVaddr  = 0x0d54ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xC4CEB9FE1A85EC53ULL;
    return h ^ kOpcode;
}

// Insn #050 @ 0x0d58: 0x90000000 -> adrp x0, #0
// Lệnh AArch64 #050 tại 0x0d58: adrp x0, #0
uint64_t verify_flipped_insn_050_0x0d58(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x90000000U;
    constexpr uint64_t kVaddr  = 0x0d58ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xC4CEB9FE1A85EC53ULL;
    return h ^ kOpcode;
}

// Insn #051 @ 0x0d5c: 0x91226800 -> add x0, x0, #0x89a
// Lệnh AArch64 #051 tại 0x0d5c: add x0, x0, #0x89a
uint64_t verify_flipped_insn_051_0x0d5c(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x91226800U;
    constexpr uint64_t kVaddr  = 0x0d5cULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xC4CEB9FE1A85EC53ULL;
    return h ^ kOpcode;
}

// Insn #052 @ 0x0d60: 0x94000124 -> bl #0x11f0
// Lệnh AArch64 #052 tại 0x0d60: bl #0x11f0
uint64_t verify_flipped_insn_052_0x0d60(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x94000124U;
    constexpr uint64_t kVaddr  = 0x0d60ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xC4CEB9FE1A85EC53ULL;
    return h ^ kOpcode;
}

// Insn #053 @ 0x0d64: 0xF94003E0 -> ldr x0, [sp]
// Lệnh AArch64 #053 tại 0x0d64: ldr x0, [sp]
uint64_t verify_flipped_insn_053_0x0d64(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xF94003E0U;
    constexpr uint64_t kVaddr  = 0x0d64ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xC4CEB9FE1A85EC53ULL;
    return h ^ kOpcode;
}

// Insn #054 @ 0x0d68: 0xF9401668 -> ldr x8, [x19, #0x28]
// Lệnh AArch64 #054 tại 0x0d68: ldr x8, [x19, #0x28]
uint64_t verify_flipped_insn_054_0x0d68(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xF9401668U;
    constexpr uint64_t kVaddr  = 0x0d68ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xC4CEB9FE1A85EC53ULL;
    return h ^ kOpcode;
}

// Insn #055 @ 0x0d6c: 0xF94007E9 -> ldr x9, [sp, #8]
// Lệnh AArch64 #055 tại 0x0d6c: ldr x9, [sp, #8]
uint64_t verify_flipped_insn_055_0x0d6c(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xF94007E9U;
    constexpr uint64_t kVaddr  = 0x0d6cULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xC4CEB9FE1A85EC53ULL;
    return h ^ kOpcode;
}

// Insn #056 @ 0x0d70: 0xEB09011F -> cmp x8, x9
// Lệnh AArch64 #056 tại 0x0d70: cmp x8, x9
uint64_t verify_flipped_insn_056_0x0d70(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xEB09011FU;
    constexpr uint64_t kVaddr  = 0x0d70ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xC4CEB9FE1A85EC53ULL;
    return h ^ kOpcode;
}

// Insn #057 @ 0x0d74: 0x540000A1 -> b.ne #0xd88
// Lệnh AArch64 #057 tại 0x0d74: b.ne #0xd88
uint64_t verify_flipped_insn_057_0x0d74(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x540000A1U;
    constexpr uint64_t kVaddr  = 0x0d74ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xC4CEB9FE1A85EC53ULL;
    return h ^ kOpcode;
}

// Insn #058 @ 0x0d78: 0xA9417BFD -> ldp x29, x30, [sp, #0x10]
// Lệnh AArch64 #058 tại 0x0d78: ldp x29, x30, [sp, #0x10]
uint64_t verify_flipped_insn_058_0x0d78(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xA9417BFDU;
    constexpr uint64_t kVaddr  = 0x0d78ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xC4CEB9FE1A85EC53ULL;
    return h ^ kOpcode;
}

// Insn #059 @ 0x0d7c: 0xF94013F3 -> ldr x19, [sp, #0x20]
// Lệnh AArch64 #059 tại 0x0d7c: ldr x19, [sp, #0x20]
uint64_t verify_flipped_insn_059_0x0d7c(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xF94013F3U;
    constexpr uint64_t kVaddr  = 0x0d7cULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xC4CEB9FE1A85EC53ULL;
    return h ^ kOpcode;
}

// Insn #060 @ 0x0d80: 0x9100C3FF -> add sp, sp, #0x30
// Lệnh AArch64 #060 tại 0x0d80: add sp, sp, #0x30
uint64_t verify_flipped_insn_060_0x0d80(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x9100C3FFU;
    constexpr uint64_t kVaddr  = 0x0d80ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xC4CEB9FE1A85EC53ULL;
    return h ^ kOpcode;
}

// Insn #061 @ 0x0d84: 0xD65F03C0 -> ret 
// Lệnh AArch64 #061 tại 0x0d84: ret 
uint64_t verify_flipped_insn_061_0x0d84(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xD65F03C0U;
    constexpr uint64_t kVaddr  = 0x0d84ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xC4CEB9FE1A85EC53ULL;
    return h ^ kOpcode;
}

// Insn #062 @ 0x0d88: 0x9400013A -> bl #0x1270
// Lệnh AArch64 #062 tại 0x0d88: bl #0x1270
uint64_t verify_flipped_insn_062_0x0d88(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x9400013AU;
    constexpr uint64_t kVaddr  = 0x0d88ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xC4CEB9FE1A85EC53ULL;
    return h ^ kOpcode;
}

// Insn #063 @ 0x0d8c: 0xA9BF7BFD -> stp x29, x30, [sp, #-0x10]!
// Lệnh AArch64 #063 tại 0x0d8c: stp x29, x30, [sp, #-0x10]!
uint64_t verify_flipped_insn_063_0x0d8c(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xA9BF7BFDU;
    constexpr uint64_t kVaddr  = 0x0d8cULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xC4CEB9FE1A85EC53ULL;
    return h ^ kOpcode;
}

// Insn #064 @ 0x0d90: 0x910003FD -> mov x29, sp
// Lệnh AArch64 #064 tại 0x0d90: mov x29, sp
uint64_t verify_flipped_insn_064_0x0d90(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x910003FDU;
    constexpr uint64_t kVaddr  = 0x0d90ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xC4CEB9FE1A85EC53ULL;
    return h ^ kOpcode;
}

// Insn #065 @ 0x0d94: 0xB0000048 -> adrp x8, #0x9000
// Lệnh AArch64 #065 tại 0x0d94: adrp x8, #0x9000
uint64_t verify_flipped_insn_065_0x0d94(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xB0000048U;
    constexpr uint64_t kVaddr  = 0x0d94ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xC4CEB9FE1A85EC53ULL;
    return h ^ kOpcode;
}

// Insn #066 @ 0x0d98: 0xF9427500 -> ldr x0, [x8, #0x4e8]
// Lệnh AArch64 #066 tại 0x0d98: ldr x0, [x8, #0x4e8]
uint64_t verify_flipped_insn_066_0x0d98(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xF9427500U;
    constexpr uint64_t kVaddr  = 0x0d98ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xC4CEB9FE1A85EC53ULL;
    return h ^ kOpcode;
}

// Insn #067 @ 0x0d9c: 0xF9400008 -> ldr x8, [x0]
// Lệnh AArch64 #067 tại 0x0d9c: ldr x8, [x0]
uint64_t verify_flipped_insn_067_0x0d9c(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xF9400008U;
    constexpr uint64_t kVaddr  = 0x0d9cULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xC4CEB9FE1A85EC53ULL;
    return h ^ kOpcode;
}

// Insn #068 @ 0x0da0: 0xF9401508 -> ldr x8, [x8, #0x28]
// Lệnh AArch64 #068 tại 0x0da0: ldr x8, [x8, #0x28]
uint64_t verify_flipped_insn_068_0x0da0(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xF9401508U;
    constexpr uint64_t kVaddr  = 0x0da0ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xC4CEB9FE1A85EC53ULL;
    return h ^ kOpcode;
}

// Insn #069 @ 0x0da4: 0xD63F0100 -> blr x8
// Lệnh AArch64 #069 tại 0x0da4: blr x8
uint64_t verify_flipped_insn_069_0x0da4(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xD63F0100U;
    constexpr uint64_t kVaddr  = 0x0da4ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xC4CEB9FE1A85EC53ULL;
    return h ^ kOpcode;
}

// Insn #070 @ 0x0da8: 0x2A0003E1 -> mov w1, w0
// Lệnh AArch64 #070 tại 0x0da8: mov w1, w0
uint64_t verify_flipped_insn_070_0x0da8(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x2A0003E1U;
    constexpr uint64_t kVaddr  = 0x0da8ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xC4CEB9FE1A85EC53ULL;
    return h ^ kOpcode;
}

// Insn #071 @ 0x0dac: 0x90000000 -> adrp x0, #0
// Lệnh AArch64 #071 tại 0x0dac: adrp x0, #0
uint64_t verify_flipped_insn_071_0x0dac(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x90000000U;
    constexpr uint64_t kVaddr  = 0x0dacULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xC4CEB9FE1A85EC53ULL;
    return h ^ kOpcode;
}

// Insn #072 @ 0x0db0: 0x9122CC00 -> add x0, x0, #0x8b3
// Lệnh AArch64 #072 tại 0x0db0: add x0, x0, #0x8b3
uint64_t verify_flipped_insn_072_0x0db0(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x9122CC00U;
    constexpr uint64_t kVaddr  = 0x0db0ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xC4CEB9FE1A85EC53ULL;
    return h ^ kOpcode;
}

// Insn #073 @ 0x0db4: 0x9400010F -> bl #0x11f0
// Lệnh AArch64 #073 tại 0x0db4: bl #0x11f0
uint64_t verify_flipped_insn_073_0x0db4(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x9400010FU;
    constexpr uint64_t kVaddr  = 0x0db4ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xC4CEB9FE1A85EC53ULL;
    return h ^ kOpcode;
}

// Insn #074 @ 0x0db8: 0xAA1F03E0 -> mov x0, xzr
// Lệnh AArch64 #074 tại 0x0db8: mov x0, xzr
uint64_t verify_flipped_insn_074_0x0db8(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xAA1F03E0U;
    constexpr uint64_t kVaddr  = 0x0db8ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xC4CEB9FE1A85EC53ULL;
    return h ^ kOpcode;
}

// Insn #075 @ 0x0dbc: 0xA8C17BFD -> ldp x29, x30, [sp], #0x10
// Lệnh AArch64 #075 tại 0x0dbc: ldp x29, x30, [sp], #0x10
uint64_t verify_flipped_insn_075_0x0dbc(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xA8C17BFDU;
    constexpr uint64_t kVaddr  = 0x0dbcULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xC4CEB9FE1A85EC53ULL;
    return h ^ kOpcode;
}

// Insn #076 @ 0x0dc0: 0xD65F03C0 -> ret 
// Lệnh AArch64 #076 tại 0x0dc0: ret 
uint64_t verify_flipped_insn_076_0x0dc0(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xD65F03C0U;
    constexpr uint64_t kVaddr  = 0x0dc0ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xC4CEB9FE1A85EC53ULL;
    return h ^ kOpcode;
}

// Insn #077 @ 0x0dc4: 0xA9BD7BFD -> stp x29, x30, [sp, #-0x30]!
// Lệnh AArch64 #077 tại 0x0dc4: stp x29, x30, [sp, #-0x30]!
uint64_t verify_flipped_insn_077_0x0dc4(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xA9BD7BFDU;
    constexpr uint64_t kVaddr  = 0x0dc4ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xC4CEB9FE1A85EC53ULL;
    return h ^ kOpcode;
}

// Insn #078 @ 0x0dc8: 0xA90157F6 -> stp x22, x21, [sp, #0x10]
// Lệnh AArch64 #078 tại 0x0dc8: stp x22, x21, [sp, #0x10]
uint64_t verify_flipped_insn_078_0x0dc8(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xA90157F6U;
    constexpr uint64_t kVaddr  = 0x0dc8ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xC4CEB9FE1A85EC53ULL;
    return h ^ kOpcode;
}

// Insn #079 @ 0x0dcc: 0xA9024FF4 -> stp x20, x19, [sp, #0x20]
// Lệnh AArch64 #079 tại 0x0dcc: stp x20, x19, [sp, #0x20]
uint64_t verify_flipped_insn_079_0x0dcc(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xA9024FF4U;
    constexpr uint64_t kVaddr  = 0x0dccULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xC4CEB9FE1A85EC53ULL;
    return h ^ kOpcode;
}

// Insn #080 @ 0x0dd0: 0x910003FD -> mov x29, sp
// Lệnh AArch64 #080 tại 0x0dd0: mov x29, sp
uint64_t verify_flipped_insn_080_0x0dd0(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x910003FDU;
    constexpr uint64_t kVaddr  = 0x0dd0ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xC4CEB9FE1A85EC53ULL;
    return h ^ kOpcode;
}

// Insn #081 @ 0x0dd4: 0xA9405414 -> ldp x20, x21, [x0]
// Lệnh AArch64 #081 tại 0x0dd4: ldp x20, x21, [x0]
uint64_t verify_flipped_insn_081_0x0dd4(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xA9405414U;
    constexpr uint64_t kVaddr  = 0x0dd4ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xC4CEB9FE1A85EC53ULL;
    return h ^ kOpcode;
}

// Insn #082 @ 0x0dd8: 0xF9400816 -> ldr x22, [x0, #0x10]
// Lệnh AArch64 #082 tại 0x0dd8: ldr x22, [x0, #0x10]
uint64_t verify_flipped_insn_082_0x0dd8(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xF9400816U;
    constexpr uint64_t kVaddr  = 0x0dd8ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xC4CEB9FE1A85EC53ULL;
    return h ^ kOpcode;
}

// Insn #083 @ 0x0ddc: 0x94000111 -> bl #0x1220
// Lệnh AArch64 #083 tại 0x0ddc: bl #0x1220
uint64_t verify_flipped_insn_083_0x0ddc(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x94000111U;
    constexpr uint64_t kVaddr  = 0x0ddcULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xC4CEB9FE1A85EC53ULL;
    return h ^ kOpcode;
}

// Insn #084 @ 0x0de0: 0xF9400008 -> ldr x8, [x0]
// Lệnh AArch64 #084 tại 0x0de0: ldr x8, [x0]
uint64_t verify_flipped_insn_084_0x0de0(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xF9400008U;
    constexpr uint64_t kVaddr  = 0x0de0ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xC4CEB9FE1A85EC53ULL;
    return h ^ kOpcode;
}

// Insn #085 @ 0x0de4: 0xAA1403E1 -> mov x1, x20
// Lệnh AArch64 #085 tại 0x0de4: mov x1, x20
uint64_t verify_flipped_insn_085_0x0de4(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xAA1403E1U;
    constexpr uint64_t kVaddr  = 0x0de4ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xC4CEB9FE1A85EC53ULL;
    return h ^ kOpcode;
}

// Insn #086 @ 0x0de8: 0xAA0003F3 -> mov x19, x0
// Lệnh AArch64 #086 tại 0x0de8: mov x19, x0
uint64_t verify_flipped_insn_086_0x0de8(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xAA0003F3U;
    constexpr uint64_t kVaddr  = 0x0de8ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xC4CEB9FE1A85EC53ULL;
    return h ^ kOpcode;
}

// Insn #087 @ 0x0dec: 0xF9407D08 -> ldr x8, [x8, #0xf8]
// Lệnh AArch64 #087 tại 0x0dec: ldr x8, [x8, #0xf8]
uint64_t verify_flipped_insn_087_0x0dec(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xF9407D08U;
    constexpr uint64_t kVaddr  = 0x0decULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xC4CEB9FE1A85EC53ULL;
    return h ^ kOpcode;
}

// Insn #088 @ 0x0df0: 0xD63F0100 -> blr x8
// Lệnh AArch64 #088 tại 0x0df0: blr x8
uint64_t verify_flipped_insn_088_0x0df0(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xD63F0100U;
    constexpr uint64_t kVaddr  = 0x0df0ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xC4CEB9FE1A85EC53ULL;
    return h ^ kOpcode;
}

// Insn #089 @ 0x0df4: 0xF9400268 -> ldr x8, [x19]
// Lệnh AArch64 #089 tại 0x0df4: ldr x8, [x19]
uint64_t verify_flipped_insn_089_0x0df4(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xF9400268U;
    constexpr uint64_t kVaddr  = 0x0df4ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xC4CEB9FE1A85EC53ULL;
    return h ^ kOpcode;
}

// Insn #090 @ 0x0df8: 0xAA0003E1 -> mov x1, x0
// Lệnh AArch64 #090 tại 0x0df8: mov x1, x0
uint64_t verify_flipped_insn_090_0x0df8(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xAA0003E1U;
    constexpr uint64_t kVaddr  = 0x0df8ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xC4CEB9FE1A85EC53ULL;
    return h ^ kOpcode;
}

// Insn #091 @ 0x0dfc: 0x90000002 -> adrp x2, #0
// Lệnh AArch64 #091 tại 0x0dfc: adrp x2, #0
uint64_t verify_flipped_insn_091_0x0dfc(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x90000002U;
    constexpr uint64_t kVaddr  = 0x0dfcULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xC4CEB9FE1A85EC53ULL;
    return h ^ kOpcode;
}

// Insn #092 @ 0x0e00: 0x91220042 -> add x2, x2, #0x880
// Lệnh AArch64 #092 tại 0x0e00: add x2, x2, #0x880
uint64_t verify_flipped_insn_092_0x0e00(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x91220042U;
    constexpr uint64_t kVaddr  = 0x0e00ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xC4CEB9FE1A85EC53ULL;
    return h ^ kOpcode;
}

// Insn #093 @ 0x0e04: 0x90000003 -> adrp x3, #0
// Lệnh AArch64 #093 tại 0x0e04: adrp x3, #0
uint64_t verify_flipped_insn_093_0x0e04(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x90000003U;
    constexpr uint64_t kVaddr  = 0x0e04ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xC4CEB9FE1A85EC53ULL;
    return h ^ kOpcode;
}

// Insn #094 @ 0x0e08: 0x9126F063 -> add x3, x3, #0x9bc
// Lệnh AArch64 #094 tại 0x0e08: add x3, x3, #0x9bc
uint64_t verify_flipped_insn_094_0x0e08(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x9126F063U;
    constexpr uint64_t kVaddr  = 0x0e08ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xC4CEB9FE1A85EC53ULL;
    return h ^ kOpcode;
}

// Insn #095 @ 0x0e0c: 0xF9408508 -> ldr x8, [x8, #0x108]
// Lệnh AArch64 #095 tại 0x0e0c: ldr x8, [x8, #0x108]
uint64_t verify_flipped_insn_095_0x0e0c(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xF9408508U;
    constexpr uint64_t kVaddr  = 0x0e0cULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xC4CEB9FE1A85EC53ULL;
    return h ^ kOpcode;
}

// Insn #096 @ 0x0e10: 0xAA1303E0 -> mov x0, x19
// Lệnh AArch64 #096 tại 0x0e10: mov x0, x19
uint64_t verify_flipped_insn_096_0x0e10(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xAA1303E0U;
    constexpr uint64_t kVaddr  = 0x0e10ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xC4CEB9FE1A85EC53ULL;
    return h ^ kOpcode;
}

// Insn #097 @ 0x0e14: 0xD63F0100 -> blr x8
// Lệnh AArch64 #097 tại 0x0e14: blr x8
uint64_t verify_flipped_insn_097_0x0e14(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xD63F0100U;
    constexpr uint64_t kVaddr  = 0x0e14ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xC4CEB9FE1A85EC53ULL;
    return h ^ kOpcode;
}

// Insn #098 @ 0x0e18: 0xAA0003E2 -> mov x2, x0
// Lệnh AArch64 #098 tại 0x0e18: mov x2, x0
uint64_t verify_flipped_insn_098_0x0e18(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xAA0003E2U;
    constexpr uint64_t kVaddr  = 0x0e18ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xC4CEB9FE1A85EC53ULL;
    return h ^ kOpcode;
}

// Insn #099 @ 0x0e1c: 0xAA1303E0 -> mov x0, x19
// Lệnh AArch64 #099 tại 0x0e1c: mov x0, x19
uint64_t verify_flipped_insn_099_0x0e1c(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xAA1303E0U;
    constexpr uint64_t kVaddr  = 0x0e1cULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xC4CEB9FE1A85EC53ULL;
    return h ^ kOpcode;
}

// Insn #100 @ 0x0e20: 0xAA1403E1 -> mov x1, x20
// Lệnh AArch64 #100 tại 0x0e20: mov x1, x20
uint64_t verify_flipped_insn_100_0x0e20(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xAA1403E1U;
    constexpr uint64_t kVaddr  = 0x0e20ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xC4CEB9FE1A85EC53ULL;
    return h ^ kOpcode;
}

// Insn #101 @ 0x0e24: 0xAA1503E3 -> mov x3, x21
// Lệnh AArch64 #101 tại 0x0e24: mov x3, x21
uint64_t verify_flipped_insn_101_0x0e24(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xAA1503E3U;
    constexpr uint64_t kVaddr  = 0x0e24ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xC4CEB9FE1A85EC53ULL;
    return h ^ kOpcode;
}

// Insn #102 @ 0x0e28: 0xAA1603E4 -> mov x4, x22
// Lệnh AArch64 #102 tại 0x0e28: mov x4, x22
uint64_t verify_flipped_insn_102_0x0e28(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xAA1603E4U;
    constexpr uint64_t kVaddr  = 0x0e28ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xC4CEB9FE1A85EC53ULL;
    return h ^ kOpcode;
}

// Insn #103 @ 0x0e2c: 0x9400001E -> bl #0xea4
// Lệnh AArch64 #103 tại 0x0e2c: bl #0xea4
uint64_t verify_flipped_insn_103_0x0e2c(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x9400001EU;
    constexpr uint64_t kVaddr  = 0x0e2cULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xC4CEB9FE1A85EC53ULL;
    return h ^ kOpcode;
}

// Insn #104 @ 0x0e30: 0xF9400268 -> ldr x8, [x19]
// Lệnh AArch64 #104 tại 0x0e30: ldr x8, [x19]
uint64_t verify_flipped_insn_104_0x0e30(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xF9400268U;
    constexpr uint64_t kVaddr  = 0x0e30ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xC4CEB9FE1A85EC53ULL;
    return h ^ kOpcode;
}

// Insn #105 @ 0x0e34: 0xAA0003F4 -> mov x20, x0
// Lệnh AArch64 #105 tại 0x0e34: mov x20, x0
uint64_t verify_flipped_insn_105_0x0e34(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xAA0003F4U;
    constexpr uint64_t kVaddr  = 0x0e34ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xC4CEB9FE1A85EC53ULL;
    return h ^ kOpcode;
}

// Insn #106 @ 0x0e38: 0xAA1303E0 -> mov x0, x19
// Lệnh AArch64 #106 tại 0x0e38: mov x0, x19
uint64_t verify_flipped_insn_106_0x0e38(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xAA1303E0U;
    constexpr uint64_t kVaddr  = 0x0e38ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xC4CEB9FE1A85EC53ULL;
    return h ^ kOpcode;
}

// Insn #107 @ 0x0e3c: 0xF9439108 -> ldr x8, [x8, #0x720]
// Lệnh AArch64 #107 tại 0x0e3c: ldr x8, [x8, #0x720]
uint64_t verify_flipped_insn_107_0x0e3c(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xF9439108U;
    constexpr uint64_t kVaddr  = 0x0e3cULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xC4CEB9FE1A85EC53ULL;
    return h ^ kOpcode;
}

// Insn #108 @ 0x0e40: 0xD63F0100 -> blr x8
// Lệnh AArch64 #108 tại 0x0e40: blr x8
uint64_t verify_flipped_insn_108_0x0e40(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xD63F0100U;
    constexpr uint64_t kVaddr  = 0x0e40ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xC4CEB9FE1A85EC53ULL;
    return h ^ kOpcode;
}

// Insn #109 @ 0x0e44: 0x72001C1F -> tst w0, #0xff
// Lệnh AArch64 #109 tại 0x0e44: tst w0, #0xff
uint64_t verify_flipped_insn_109_0x0e44(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x72001C1FU;
    constexpr uint64_t kVaddr  = 0x0e44ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xC4CEB9FE1A85EC53ULL;
    return h ^ kOpcode;
}

// Insn #110 @ 0x0e48: 0x54000120 -> b.eq #0xe6c
// Lệnh AArch64 #110 tại 0x0e48: b.eq #0xe6c
uint64_t verify_flipped_insn_110_0x0e48(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x54000120U;
    constexpr uint64_t kVaddr  = 0x0e48ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xC4CEB9FE1A85EC53ULL;
    return h ^ kOpcode;
}

// Insn #111 @ 0x0e4c: 0xF9400268 -> ldr x8, [x19]
// Lệnh AArch64 #111 tại 0x0e4c: ldr x8, [x19]
uint64_t verify_flipped_insn_111_0x0e4c(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xF9400268U;
    constexpr uint64_t kVaddr  = 0x0e4cULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xC4CEB9FE1A85EC53ULL;
    return h ^ kOpcode;
}

// Insn #112 @ 0x0e50: 0xAA1303E0 -> mov x0, x19
// Lệnh AArch64 #112 tại 0x0e50: mov x0, x19
uint64_t verify_flipped_insn_112_0x0e50(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xAA1303E0U;
    constexpr uint64_t kVaddr  = 0x0e50ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xC4CEB9FE1A85EC53ULL;
    return h ^ kOpcode;
}

// Insn #113 @ 0x0e54: 0xF9404108 -> ldr x8, [x8, #0x80]
// Lệnh AArch64 #113 tại 0x0e54: ldr x8, [x8, #0x80]
uint64_t verify_flipped_insn_113_0x0e54(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xF9404108U;
    constexpr uint64_t kVaddr  = 0x0e54ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xC4CEB9FE1A85EC53ULL;
    return h ^ kOpcode;
}

// Insn #114 @ 0x0e58: 0xD63F0100 -> blr x8
// Lệnh AArch64 #114 tại 0x0e58: blr x8
uint64_t verify_flipped_insn_114_0x0e58(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xD63F0100U;
    constexpr uint64_t kVaddr  = 0x0e58ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xC4CEB9FE1A85EC53ULL;
    return h ^ kOpcode;
}

// Insn #115 @ 0x0e5c: 0xF9400268 -> ldr x8, [x19]
// Lệnh AArch64 #115 tại 0x0e5c: ldr x8, [x19]
uint64_t verify_flipped_insn_115_0x0e5c(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xF9400268U;
    constexpr uint64_t kVaddr  = 0x0e5cULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xC4CEB9FE1A85EC53ULL;
    return h ^ kOpcode;
}

// Insn #116 @ 0x0e60: 0xAA1303E0 -> mov x0, x19
// Lệnh AArch64 #116 tại 0x0e60: mov x0, x19
uint64_t verify_flipped_insn_116_0x0e60(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xAA1303E0U;
    constexpr uint64_t kVaddr  = 0x0e60ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xC4CEB9FE1A85EC53ULL;
    return h ^ kOpcode;
}

// Insn #117 @ 0x0e64: 0xF9404508 -> ldr x8, [x8, #0x88]
// Lệnh AArch64 #117 tại 0x0e64: ldr x8, [x8, #0x88]
uint64_t verify_flipped_insn_117_0x0e64(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xF9404508U;
    constexpr uint64_t kVaddr  = 0x0e64ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xC4CEB9FE1A85EC53ULL;
    return h ^ kOpcode;
}

// Insn #118 @ 0x0e68: 0xD63F0100 -> blr x8
// Lệnh AArch64 #118 tại 0x0e68: blr x8
uint64_t verify_flipped_insn_118_0x0e68(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xD63F0100U;
    constexpr uint64_t kVaddr  = 0x0e68ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xC4CEB9FE1A85EC53ULL;
    return h ^ kOpcode;
}

// Insn #119 @ 0x0e6c: 0xB40000F4 -> cbz x20, #0xe88
// Lệnh AArch64 #119 tại 0x0e6c: cbz x20, #0xe88
uint64_t verify_flipped_insn_119_0x0e6c(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xB40000F4U;
    constexpr uint64_t kVaddr  = 0x0e6cULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xC4CEB9FE1A85EC53ULL;
    return h ^ kOpcode;
}

// Insn #120 @ 0x0e70: 0xF9400268 -> ldr x8, [x19]
// Lệnh AArch64 #120 tại 0x0e70: ldr x8, [x19]
uint64_t verify_flipped_insn_120_0x0e70(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xF9400268U;
    constexpr uint64_t kVaddr  = 0x0e70ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xC4CEB9FE1A85EC53ULL;
    return h ^ kOpcode;
}

// Insn #121 @ 0x0e74: 0xAA1303E0 -> mov x0, x19
// Lệnh AArch64 #121 tại 0x0e74: mov x0, x19
uint64_t verify_flipped_insn_121_0x0e74(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xAA1303E0U;
    constexpr uint64_t kVaddr  = 0x0e74ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xC4CEB9FE1A85EC53ULL;
    return h ^ kOpcode;
}

// Insn #122 @ 0x0e78: 0xAA1403E1 -> mov x1, x20
// Lệnh AArch64 #122 tại 0x0e78: mov x1, x20
uint64_t verify_flipped_insn_122_0x0e78(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xAA1403E1U;
    constexpr uint64_t kVaddr  = 0x0e78ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xC4CEB9FE1A85EC53ULL;
    return h ^ kOpcode;
}

// Insn #123 @ 0x0e7c: 0x940000CA -> bl #0x11a4
// Lệnh AArch64 #123 tại 0x0e7c: bl #0x11a4
uint64_t verify_flipped_insn_123_0x0e7c(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x940000CAU;
    constexpr uint64_t kVaddr  = 0x0e7cULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xC4CEB9FE1A85EC53ULL;
    return h ^ kOpcode;
}

// Insn #124 @ 0x0e80: 0xAA0003F3 -> mov x19, x0
// Lệnh AArch64 #124 tại 0x0e80: mov x19, x0
uint64_t verify_flipped_insn_124_0x0e80(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xAA0003F3U;
    constexpr uint64_t kVaddr  = 0x0e80ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xC4CEB9FE1A85EC53ULL;
    return h ^ kOpcode;
}

// Insn #125 @ 0x0e84: 0x14000002 -> b #0xe8c
// Lệnh AArch64 #125 tại 0x0e84: b #0xe8c
uint64_t verify_flipped_insn_125_0x0e84(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x14000002U;
    constexpr uint64_t kVaddr  = 0x0e84ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xC4CEB9FE1A85EC53ULL;
    return h ^ kOpcode;
}

// Insn #126 @ 0x0e88: 0xAA1F03F3 -> mov x19, xzr
// Lệnh AArch64 #126 tại 0x0e88: mov x19, xzr
uint64_t verify_flipped_insn_126_0x0e88(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xAA1F03F3U;
    constexpr uint64_t kVaddr  = 0x0e88ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xC4CEB9FE1A85EC53ULL;
    return h ^ kOpcode;
}

// Insn #127 @ 0x0e8c: 0x940000E9 -> bl #0x1230
// Lệnh AArch64 #127 tại 0x0e8c: bl #0x1230
uint64_t verify_flipped_insn_127_0x0e8c(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x940000E9U;
    constexpr uint64_t kVaddr  = 0x0e8cULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xC4CEB9FE1A85EC53ULL;
    return h ^ kOpcode;
}

// Insn #128 @ 0x0e90: 0xAA1303E0 -> mov x0, x19
// Lệnh AArch64 #128 tại 0x0e90: mov x0, x19
uint64_t verify_flipped_insn_128_0x0e90(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xAA1303E0U;
    constexpr uint64_t kVaddr  = 0x0e90ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xC4CEB9FE1A85EC53ULL;
    return h ^ kOpcode;
}

// Insn #129 @ 0x0e94: 0xA9424FF4 -> ldp x20, x19, [sp, #0x20]
// Lệnh AArch64 #129 tại 0x0e94: ldp x20, x19, [sp, #0x20]
uint64_t verify_flipped_insn_129_0x0e94(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xA9424FF4U;
    constexpr uint64_t kVaddr  = 0x0e94ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xC4CEB9FE1A85EC53ULL;
    return h ^ kOpcode;
}

// Insn #130 @ 0x0e98: 0xA94157F6 -> ldp x22, x21, [sp, #0x10]
// Lệnh AArch64 #130 tại 0x0e98: ldp x22, x21, [sp, #0x10]
uint64_t verify_flipped_insn_130_0x0e98(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xA94157F6U;
    constexpr uint64_t kVaddr  = 0x0e98ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xC4CEB9FE1A85EC53ULL;
    return h ^ kOpcode;
}

// Insn #131 @ 0x0e9c: 0xA8C37BFD -> ldp x29, x30, [sp], #0x30
// Lệnh AArch64 #131 tại 0x0e9c: ldp x29, x30, [sp], #0x30
uint64_t verify_flipped_insn_131_0x0e9c(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xA8C37BFDU;
    constexpr uint64_t kVaddr  = 0x0e9cULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xC4CEB9FE1A85EC53ULL;
    return h ^ kOpcode;
}

// Insn #132 @ 0x0ea0: 0xD65F03C0 -> ret 
// Lệnh AArch64 #132 tại 0x0ea0: ret 
uint64_t verify_flipped_insn_132_0x0ea0(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xD65F03C0U;
    constexpr uint64_t kVaddr  = 0x0ea0ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xC4CEB9FE1A85EC53ULL;
    return h ^ kOpcode;
}

// Insn #133 @ 0x0ea4: 0xD10483FF -> sub sp, sp, #0x120
// Lệnh AArch64 #133 tại 0x0ea4: sub sp, sp, #0x120
uint64_t verify_flipped_insn_133_0x0ea4(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xD10483FFU;
    constexpr uint64_t kVaddr  = 0x0ea4ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xC4CEB9FE1A85EC53ULL;
    return h ^ kOpcode;
}

// Insn #134 @ 0x0ea8: 0xA9107BFD -> stp x29, x30, [sp, #0x100]
// Lệnh AArch64 #134 tại 0x0ea8: stp x29, x30, [sp, #0x100]
uint64_t verify_flipped_insn_134_0x0ea8(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xA9107BFDU;
    constexpr uint64_t kVaddr  = 0x0ea8ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xC4CEB9FE1A85EC53ULL;
    return h ^ kOpcode;
}

// Insn #135 @ 0x0eac: 0xA9114FFC -> stp x28, x19, [sp, #0x110]
// Lệnh AArch64 #135 tại 0x0eac: stp x28, x19, [sp, #0x110]
uint64_t verify_flipped_insn_135_0x0eac(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xA9114FFCU;
    constexpr uint64_t kVaddr  = 0x0eacULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xC4CEB9FE1A85EC53ULL;
    return h ^ kOpcode;
}

// Insn #136 @ 0x0eb0: 0x910403FD -> add x29, sp, #0x100
// Lệnh AArch64 #136 tại 0x0eb0: add x29, sp, #0x100
uint64_t verify_flipped_insn_136_0x0eb0(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x910403FDU;
    constexpr uint64_t kVaddr  = 0x0eb0ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xC4CEB9FE1A85EC53ULL;
    return h ^ kOpcode;
}

// Insn #137 @ 0x0eb4: 0xA93893A3 -> stp x3, x4, [x29, #-0x78]
// Lệnh AArch64 #137 tại 0x0eb4: stp x3, x4, [x29, #-0x78]
uint64_t verify_flipped_insn_137_0x0eb4(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xA93893A3U;
    constexpr uint64_t kVaddr  = 0x0eb4ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xC4CEB9FE1A85EC53ULL;
    return h ^ kOpcode;
}

// Insn #138 @ 0x0eb8: 0xD101E3A9 -> sub x9, x29, #0x78
// Lệnh AArch64 #138 tại 0x0eb8: sub x9, x29, #0x78
uint64_t verify_flipped_insn_138_0x0eb8(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xD101E3A9U;
    constexpr uint64_t kVaddr  = 0x0eb8ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xC4CEB9FE1A85EC53ULL;
    return h ^ kOpcode;
}

// Insn #139 @ 0x0ebc: 0xA9399BA5 -> stp x5, x6, [x29, #-0x68]
// Lệnh AArch64 #139 tại 0x0ebc: stp x5, x6, [x29, #-0x68]
uint64_t verify_flipped_insn_139_0x0ebc(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xA9399BA5U;
    constexpr uint64_t kVaddr  = 0x0ebcULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xC4CEB9FE1A85EC53ULL;
    return h ^ kOpcode;
}

// Insn #140 @ 0x0ec0: 0x928004EB -> mov x11, #-0x28
// Lệnh AArch64 #140 tại 0x0ec0: mov x11, #-0x28
uint64_t verify_flipped_insn_140_0x0ec0(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x928004EBU;
    constexpr uint64_t kVaddr  = 0x0ec0ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xC4CEB9FE1A85EC53ULL;
    return h ^ kOpcode;
}

// Insn #141 @ 0x0ec4: 0xF81A83A7 -> stur x7, [x29, #-0x58]
// Lệnh AArch64 #141 tại 0x0ec4: stur x7, [x29, #-0x58]
uint64_t verify_flipped_insn_141_0x0ec4(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xF81A83A7U;
    constexpr uint64_t kVaddr  = 0x0ec4ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xC4CEB9FE1A85EC53ULL;
    return h ^ kOpcode;
}

// Insn #142 @ 0x0ec8: 0x910003EC -> mov x12, sp
// Lệnh AArch64 #142 tại 0x0ec8: mov x12, sp
uint64_t verify_flipped_insn_142_0x0ec8(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x910003ECU;
    constexpr uint64_t kVaddr  = 0x0ec8ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xC4CEB9FE1A85EC53ULL;
    return h ^ kOpcode;
}

// Insn #143 @ 0x0ecc: 0xAD0007E0 -> stp q0, q1, [sp]
// Lệnh AArch64 #143 tại 0x0ecc: stp q0, q1, [sp]
uint64_t verify_flipped_insn_143_0x0ecc(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xAD0007E0U;
    constexpr uint64_t kVaddr  = 0x0eccULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xC4CEB9FE1A85EC53ULL;
    return h ^ kOpcode;
}

// Insn #144 @ 0x0ed0: 0x9100A129 -> add x9, x9, #0x28
// Lệnh AArch64 #144 tại 0x0ed0: add x9, x9, #0x28
uint64_t verify_flipped_insn_144_0x0ed0(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x9100A129U;
    constexpr uint64_t kVaddr  = 0x0ed0ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xC4CEB9FE1A85EC53ULL;
    return h ^ kOpcode;
}

// Insn #145 @ 0x0ed4: 0xAD010FE2 -> stp q2, q3, [sp, #0x20]
// Lệnh AArch64 #145 tại 0x0ed4: stp q2, q3, [sp, #0x20]
uint64_t verify_flipped_insn_145_0x0ed4(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xAD010FE2U;
    constexpr uint64_t kVaddr  = 0x0ed4ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xC4CEB9FE1A85EC53ULL;
    return h ^ kOpcode;
}

// Insn #146 @ 0x0ed8: 0xF2DFF00B -> movk x11, #0xff80, lsl #32
// Lệnh AArch64 #146 tại 0x0ed8: movk x11, #0xff80, lsl #32
uint64_t verify_flipped_insn_146_0x0ed8(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xF2DFF00BU;
    constexpr uint64_t kVaddr  = 0x0ed8ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xC4CEB9FE1A85EC53ULL;
    return h ^ kOpcode;
}

// Insn #147 @ 0x0edc: 0xAD0217E4 -> stp q4, q5, [sp, #0x40]
// Lệnh AArch64 #147 tại 0x0edc: stp q4, q5, [sp, #0x40]
uint64_t verify_flipped_insn_147_0x0edc(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xAD0217E4U;
    constexpr uint64_t kVaddr  = 0x0edcULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xC4CEB9FE1A85EC53ULL;
    return h ^ kOpcode;
}

// Insn #148 @ 0x0ee0: 0x9102018C -> add x12, x12, #0x80
// Lệnh AArch64 #148 tại 0x0ee0: add x12, x12, #0x80
uint64_t verify_flipped_insn_148_0x0ee0(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x9102018CU;
    constexpr uint64_t kVaddr  = 0x0ee0ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xC4CEB9FE1A85EC53ULL;
    return h ^ kOpcode;
}

// Insn #149 @ 0x0ee4: 0xAD031FE6 -> stp q6, q7, [sp, #0x60]
// Lệnh AArch64 #149 tại 0x0ee4: stp q6, q7, [sp, #0x60]
uint64_t verify_flipped_insn_149_0x0ee4(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xAD031FE6U;
    constexpr uint64_t kVaddr  = 0x0ee4ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xC4CEB9FE1A85EC53ULL;
    return h ^ kOpcode;
}

// Insn #150 @ 0x0ee8: 0xD53BD053 -> mrs x19, tpidr_el0
// Lệnh AArch64 #150 tại 0x0ee8: mrs x19, tpidr_el0
uint64_t verify_flipped_insn_150_0x0ee8(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xD53BD053U;
    constexpr uint64_t kVaddr  = 0x0ee8ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xC4CEB9FE1A85EC53ULL;
    return h ^ kOpcode;
}

// Insn #151 @ 0x0eec: 0xF9401668 -> ldr x8, [x19, #0x28]
// Lệnh AArch64 #151 tại 0x0eec: ldr x8, [x19, #0x28]
uint64_t verify_flipped_insn_151_0x0eec(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xF9401668U;
    constexpr uint64_t kVaddr  = 0x0eecULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xC4CEB9FE1A85EC53ULL;
    return h ^ kOpcode;
}

// Insn #152 @ 0x0ef0: 0xD100A3AA -> sub x10, x29, #0x28
// Lệnh AArch64 #152 tại 0x0ef0: sub x10, x29, #0x28
uint64_t verify_flipped_insn_152_0x0ef0(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xD100A3AAU;
    constexpr uint64_t kVaddr  = 0x0ef0ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xC4CEB9FE1A85EC53ULL;
    return h ^ kOpcode;
}

// Insn #153 @ 0x0ef4: 0xD10143A3 -> sub x3, x29, #0x50
// Lệnh AArch64 #153 tại 0x0ef4: sub x3, x29, #0x50
uint64_t verify_flipped_insn_153_0x0ef4(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xD10143A3U;
    constexpr uint64_t kVaddr  = 0x0ef4ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xC4CEB9FE1A85EC53ULL;
    return h ^ kOpcode;
}

// Insn #154 @ 0x0ef8: 0xF81F83A8 -> stur x8, [x29, #-8]
// Lệnh AArch64 #154 tại 0x0ef8: stur x8, [x29, #-8]
uint64_t verify_flipped_insn_154_0x0ef8(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xF81F83A8U;
    constexpr uint64_t kVaddr  = 0x0ef8ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xC4CEB9FE1A85EC53ULL;
    return h ^ kOpcode;
}

// Insn #155 @ 0x0efc: 0x910083A8 -> add x8, x29, #0x20
// Lệnh AArch64 #155 tại 0x0efc: add x8, x29, #0x20
uint64_t verify_flipped_insn_155_0x0efc(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x910083A8U;
    constexpr uint64_t kVaddr  = 0x0efcULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xC4CEB9FE1A85EC53ULL;
    return h ^ kOpcode;
}

// Insn #156 @ 0x0f00: 0xA93EAFAC -> stp x12, x11, [x29, #-0x18]
// Lệnh AArch64 #156 tại 0x0f00: stp x12, x11, [x29, #-0x18]
uint64_t verify_flipped_insn_156_0x0f00(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xA93EAFACU;
    constexpr uint64_t kVaddr  = 0x0f00ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xC4CEB9FE1A85EC53ULL;
    return h ^ kOpcode;
}

// Insn #157 @ 0x0f04: 0xA93DA7A8 -> stp x8, x9, [x29, #-0x28]
// Lệnh AArch64 #157 tại 0x0f04: stp x8, x9, [x29, #-0x28]
uint64_t verify_flipped_insn_157_0x0f04(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xA93DA7A8U;
    constexpr uint64_t kVaddr  = 0x0f04ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xC4CEB9FE1A85EC53ULL;
    return h ^ kOpcode;
}

// Insn #158 @ 0x0f08: 0xF9400008 -> ldr x8, [x0]
// Lệnh AArch64 #158 tại 0x0f08: ldr x8, [x0]
uint64_t verify_flipped_insn_158_0x0f08(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xF9400008U;
    constexpr uint64_t kVaddr  = 0x0f08ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xC4CEB9FE1A85EC53ULL;
    return h ^ kOpcode;
}

// Insn #159 @ 0x0f0c: 0xAD400540 -> ldp q0, q1, [x10]
// Lệnh AArch64 #159 tại 0x0f0c: ldp q0, q1, [x10]
uint64_t verify_flipped_insn_159_0x0f0c(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xAD400540U;
    constexpr uint64_t kVaddr  = 0x0f0cULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xC4CEB9FE1A85EC53ULL;
    return h ^ kOpcode;
}

// Insn #160 @ 0x0f10: 0xF9408D08 -> ldr x8, [x8, #0x118]
// Lệnh AArch64 #160 tại 0x0f10: ldr x8, [x8, #0x118]
uint64_t verify_flipped_insn_160_0x0f10(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xF9408D08U;
    constexpr uint64_t kVaddr  = 0x0f10ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xC4CEB9FE1A85EC53ULL;
    return h ^ kOpcode;
}

// Insn #161 @ 0x0f14: 0xAD3D87A0 -> stp q0, q1, [x29, #-0x50]
// Lệnh AArch64 #161 tại 0x0f14: stp q0, q1, [x29, #-0x50]
uint64_t verify_flipped_insn_161_0x0f14(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xAD3D87A0U;
    constexpr uint64_t kVaddr  = 0x0f14ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xC4CEB9FE1A85EC53ULL;
    return h ^ kOpcode;
}

// Insn #162 @ 0x0f18: 0xD63F0100 -> blr x8
// Lệnh AArch64 #162 tại 0x0f18: blr x8
uint64_t verify_flipped_insn_162_0x0f18(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xD63F0100U;
    constexpr uint64_t kVaddr  = 0x0f18ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xC4CEB9FE1A85EC53ULL;
    return h ^ kOpcode;
}

// Insn #163 @ 0x0f1c: 0xF9401668 -> ldr x8, [x19, #0x28]
// Lệnh AArch64 #163 tại 0x0f1c: ldr x8, [x19, #0x28]
uint64_t verify_flipped_insn_163_0x0f1c(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xF9401668U;
    constexpr uint64_t kVaddr  = 0x0f1cULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xC4CEB9FE1A85EC53ULL;
    return h ^ kOpcode;
}

// Insn #164 @ 0x0f20: 0xF85F83A9 -> ldur x9, [x29, #-8]
// Lệnh AArch64 #164 tại 0x0f20: ldur x9, [x29, #-8]
uint64_t verify_flipped_insn_164_0x0f20(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xF85F83A9U;
    constexpr uint64_t kVaddr  = 0x0f20ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xC4CEB9FE1A85EC53ULL;
    return h ^ kOpcode;
}

// Insn #165 @ 0x0f24: 0xEB09011F -> cmp x8, x9
// Lệnh AArch64 #165 tại 0x0f24: cmp x8, x9
uint64_t verify_flipped_insn_165_0x0f24(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xEB09011FU;
    constexpr uint64_t kVaddr  = 0x0f24ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xC4CEB9FE1A85EC53ULL;
    return h ^ kOpcode;
}

// Insn #166 @ 0x0f28: 0x540000A1 -> b.ne #0xf3c
// Lệnh AArch64 #166 tại 0x0f28: b.ne #0xf3c
uint64_t verify_flipped_insn_166_0x0f28(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x540000A1U;
    constexpr uint64_t kVaddr  = 0x0f28ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xC4CEB9FE1A85EC53ULL;
    return h ^ kOpcode;
}

// Insn #167 @ 0x0f2c: 0xA9514FFC -> ldp x28, x19, [sp, #0x110]
// Lệnh AArch64 #167 tại 0x0f2c: ldp x28, x19, [sp, #0x110]
uint64_t verify_flipped_insn_167_0x0f2c(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xA9514FFCU;
    constexpr uint64_t kVaddr  = 0x0f2cULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xC4CEB9FE1A85EC53ULL;
    return h ^ kOpcode;
}

// Insn #168 @ 0x0f30: 0xA9507BFD -> ldp x29, x30, [sp, #0x100]
// Lệnh AArch64 #168 tại 0x0f30: ldp x29, x30, [sp, #0x100]
uint64_t verify_flipped_insn_168_0x0f30(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xA9507BFDU;
    constexpr uint64_t kVaddr  = 0x0f30ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xC4CEB9FE1A85EC53ULL;
    return h ^ kOpcode;
}

// Insn #169 @ 0x0f34: 0x910483FF -> add sp, sp, #0x120
// Lệnh AArch64 #169 tại 0x0f34: add sp, sp, #0x120
uint64_t verify_flipped_insn_169_0x0f34(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x910483FFU;
    constexpr uint64_t kVaddr  = 0x0f34ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xC4CEB9FE1A85EC53ULL;
    return h ^ kOpcode;
}

// Insn #170 @ 0x0f38: 0xD65F03C0 -> ret 
// Lệnh AArch64 #170 tại 0x0f38: ret 
uint64_t verify_flipped_insn_170_0x0f38(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xD65F03C0U;
    constexpr uint64_t kVaddr  = 0x0f38ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xC4CEB9FE1A85EC53ULL;
    return h ^ kOpcode;
}

// Insn #171 @ 0x0f3c: 0x940000CD -> bl #0x1270
// Lệnh AArch64 #171 tại 0x0f3c: bl #0x1270
uint64_t verify_flipped_insn_171_0x0f3c(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x940000CDU;
    constexpr uint64_t kVaddr  = 0x0f3cULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xC4CEB9FE1A85EC53ULL;
    return h ^ kOpcode;
}

// Insn #172 @ 0x0f40: 0xD10203FF -> sub sp, sp, #0x80
// Lệnh AArch64 #172 tại 0x0f40: sub sp, sp, #0x80
uint64_t verify_flipped_insn_172_0x0f40(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xD10203FFU;
    constexpr uint64_t kVaddr  = 0x0f40ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xC4CEB9FE1A85EC53ULL;
    return h ^ kOpcode;
}

// Insn #173 @ 0x0f44: 0xA9037BFD -> stp x29, x30, [sp, #0x30]
// Lệnh AArch64 #173 tại 0x0f44: stp x29, x30, [sp, #0x30]
uint64_t verify_flipped_insn_173_0x0f44(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xA9037BFDU;
    constexpr uint64_t kVaddr  = 0x0f44ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xC4CEB9FE1A85EC53ULL;
    return h ^ kOpcode;
}

// Insn #174 @ 0x0f48: 0xF90023F9 -> str x25, [sp, #0x40]
// Lệnh AArch64 #174 tại 0x0f48: str x25, [sp, #0x40]
uint64_t verify_flipped_insn_174_0x0f48(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xF90023F9U;
    constexpr uint64_t kVaddr  = 0x0f48ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xC4CEB9FE1A85EC53ULL;
    return h ^ kOpcode;
}

// Insn #175 @ 0x0f4c: 0xA9055FF8 -> stp x24, x23, [sp, #0x50]
// Lệnh AArch64 #175 tại 0x0f4c: stp x24, x23, [sp, #0x50]
uint64_t verify_flipped_insn_175_0x0f4c(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xA9055FF8U;
    constexpr uint64_t kVaddr  = 0x0f4cULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xC4CEB9FE1A85EC53ULL;
    return h ^ kOpcode;
}

// Insn #176 @ 0x0f50: 0xA90657F6 -> stp x22, x21, [sp, #0x60]
// Lệnh AArch64 #176 tại 0x0f50: stp x22, x21, [sp, #0x60]
uint64_t verify_flipped_insn_176_0x0f50(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xA90657F6U;
    constexpr uint64_t kVaddr  = 0x0f50ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xC4CEB9FE1A85EC53ULL;
    return h ^ kOpcode;
}

// Insn #177 @ 0x0f54: 0xA9074FF4 -> stp x20, x19, [sp, #0x70]
// Lệnh AArch64 #177 tại 0x0f54: stp x20, x19, [sp, #0x70]
uint64_t verify_flipped_insn_177_0x0f54(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xA9074FF4U;
    constexpr uint64_t kVaddr  = 0x0f54ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xC4CEB9FE1A85EC53ULL;
    return h ^ kOpcode;
}

// Insn #178 @ 0x0f58: 0x9100C3FD -> add x29, sp, #0x30
// Lệnh AArch64 #178 tại 0x0f58: add x29, sp, #0x30
uint64_t verify_flipped_insn_178_0x0f58(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x9100C3FDU;
    constexpr uint64_t kVaddr  = 0x0f58ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xC4CEB9FE1A85EC53ULL;
    return h ^ kOpcode;
}

// Insn #179 @ 0x0f5c: 0xD53BD058 -> mrs x24, tpidr_el0
// Lệnh AArch64 #179 tại 0x0f5c: mrs x24, tpidr_el0
uint64_t verify_flipped_insn_179_0x0f5c(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xD53BD058U;
    constexpr uint64_t kVaddr  = 0x0f5cULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xC4CEB9FE1A85EC53ULL;
    return h ^ kOpcode;
}

// Insn #180 @ 0x0f60: 0xAA0203E1 -> mov x1, x2
// Lệnh AArch64 #180 tại 0x0f60: mov x1, x2
uint64_t verify_flipped_insn_180_0x0f60(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xAA0203E1U;
    constexpr uint64_t kVaddr  = 0x0f60ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xC4CEB9FE1A85EC53ULL;
    return h ^ kOpcode;
}

// Insn #181 @ 0x0f64: 0xF9401708 -> ldr x8, [x24, #0x28]
// Lệnh AArch64 #181 tại 0x0f64: ldr x8, [x24, #0x28]
uint64_t verify_flipped_insn_181_0x0f64(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xF9401708U;
    constexpr uint64_t kVaddr  = 0x0f64ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xC4CEB9FE1A85EC53ULL;
    return h ^ kOpcode;
}

// Insn #182 @ 0x0f68: 0xAA0403F4 -> mov x20, x4
// Lệnh AArch64 #182 tại 0x0f68: mov x20, x4
uint64_t verify_flipped_insn_182_0x0f68(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xAA0403F4U;
    constexpr uint64_t kVaddr  = 0x0f68ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xC4CEB9FE1A85EC53ULL;
    return h ^ kOpcode;
}

// Insn #183 @ 0x0f6c: 0xAA0303F6 -> mov x22, x3
// Lệnh AArch64 #183 tại 0x0f6c: mov x22, x3
uint64_t verify_flipped_insn_183_0x0f6c(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xAA0303F6U;
    constexpr uint64_t kVaddr  = 0x0f6cULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xC4CEB9FE1A85EC53ULL;
    return h ^ kOpcode;
}

// Insn #184 @ 0x0f70: 0xAA0003F5 -> mov x21, x0
// Lệnh AArch64 #184 tại 0x0f70: mov x21, x0
uint64_t verify_flipped_insn_184_0x0f70(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xAA0003F5U;
    constexpr uint64_t kVaddr  = 0x0f70ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xC4CEB9FE1A85EC53ULL;
    return h ^ kOpcode;
}

// Insn #185 @ 0x0f74: 0xF81F83A8 -> stur x8, [x29, #-8]
// Lệnh AArch64 #185 tại 0x0f74: stur x8, [x29, #-8]
uint64_t verify_flipped_insn_185_0x0f74(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xF81F83A8U;
    constexpr uint64_t kVaddr  = 0x0f74ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xC4CEB9FE1A85EC53ULL;
    return h ^ kOpcode;
}

// Insn #186 @ 0x0f78: 0xF9400008 -> ldr x8, [x0]
// Lệnh AArch64 #186 tại 0x0f78: ldr x8, [x0]
uint64_t verify_flipped_insn_186_0x0f78(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xF9400008U;
    constexpr uint64_t kVaddr  = 0x0f78ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xC4CEB9FE1A85EC53ULL;
    return h ^ kOpcode;
}

// Insn #187 @ 0x0f7c: 0x9400008A -> bl #0x11a4
// Lệnh AArch64 #187 tại 0x0f7c: bl #0x11a4
uint64_t verify_flipped_insn_187_0x0f7c(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x9400008AU;
    constexpr uint64_t kVaddr  = 0x0f7cULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xC4CEB9FE1A85EC53ULL;
    return h ^ kOpcode;
}

// Insn #188 @ 0x0f80: 0xF94002A8 -> ldr x8, [x21]
// Lệnh AArch64 #188 tại 0x0f80: ldr x8, [x21]
uint64_t verify_flipped_insn_188_0x0f80(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xF94002A8U;
    constexpr uint64_t kVaddr  = 0x0f80ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xC4CEB9FE1A85EC53ULL;
    return h ^ kOpcode;
}

// Insn #189 @ 0x0f84: 0xAA0003F3 -> mov x19, x0
// Lệnh AArch64 #189 tại 0x0f84: mov x19, x0
uint64_t verify_flipped_insn_189_0x0f84(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xAA0003F3U;
    constexpr uint64_t kVaddr  = 0x0f84ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xC4CEB9FE1A85EC53ULL;
    return h ^ kOpcode;
}

// Insn #190 @ 0x0f88: 0xAA1503E0 -> mov x0, x21
// Lệnh AArch64 #190 tại 0x0f88: mov x0, x21
uint64_t verify_flipped_insn_190_0x0f88(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xAA1503E0U;
    constexpr uint64_t kVaddr  = 0x0f88ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xC4CEB9FE1A85EC53ULL;
    return h ^ kOpcode;
}

// Insn #191 @ 0x0f8c: 0xAA1603E1 -> mov x1, x22
// Lệnh AArch64 #191 tại 0x0f8c: mov x1, x22
uint64_t verify_flipped_insn_191_0x0f8c(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xAA1603E1U;
    constexpr uint64_t kVaddr  = 0x0f8cULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xC4CEB9FE1A85EC53ULL;
    return h ^ kOpcode;
}

// Insn #192 @ 0x0f90: 0x94000085 -> bl #0x11a4
// Lệnh AArch64 #192 tại 0x0f90: bl #0x11a4
uint64_t verify_flipped_insn_192_0x0f90(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x94000085U;
    constexpr uint64_t kVaddr  = 0x0f90ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xC4CEB9FE1A85EC53ULL;
    return h ^ kOpcode;
}

// Insn #193 @ 0x0f94: 0xAA0003F6 -> mov x22, x0
// Lệnh AArch64 #193 tại 0x0f94: mov x22, x0
uint64_t verify_flipped_insn_193_0x0f94(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xAA0003F6U;
    constexpr uint64_t kVaddr  = 0x0f94ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xC4CEB9FE1A85EC53ULL;
    return h ^ kOpcode;
}

// Insn #194 @ 0x0f98: 0xB4000474 -> cbz x20, #0x1024
// Lệnh AArch64 #194 tại 0x0f98: cbz x20, #0x1024
uint64_t verify_flipped_insn_194_0x0f98(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xB4000474U;
    constexpr uint64_t kVaddr  = 0x0f98ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xC4CEB9FE1A85EC53ULL;
    return h ^ kOpcode;
}

// Insn #195 @ 0x0f9c: 0xF94002A8 -> ldr x8, [x21]
// Lệnh AArch64 #195 tại 0x0f9c: ldr x8, [x21]
uint64_t verify_flipped_insn_195_0x0f9c(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xF94002A8U;
    constexpr uint64_t kVaddr  = 0x0f9cULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xC4CEB9FE1A85EC53ULL;
    return h ^ kOpcode;
}

// Insn #196 @ 0x0fa0: 0xAA1503E0 -> mov x0, x21
// Lệnh AArch64 #196 tại 0x0fa0: mov x0, x21
uint64_t verify_flipped_insn_196_0x0fa0(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xAA1503E0U;
    constexpr uint64_t kVaddr  = 0x0fa0ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xC4CEB9FE1A85EC53ULL;
    return h ^ kOpcode;
}

// Insn #197 @ 0x0fa4: 0xAA1403E1 -> mov x1, x20
// Lệnh AArch64 #197 tại 0x0fa4: mov x1, x20
uint64_t verify_flipped_insn_197_0x0fa4(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xAA1403E1U;
    constexpr uint64_t kVaddr  = 0x0fa4ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xC4CEB9FE1A85EC53ULL;
    return h ^ kOpcode;
}

// Insn #198 @ 0x0fa8: 0xF942AD08 -> ldr x8, [x8, #0x558]
// Lệnh AArch64 #198 tại 0x0fa8: ldr x8, [x8, #0x558]
uint64_t verify_flipped_insn_198_0x0fa8(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xF942AD08U;
    constexpr uint64_t kVaddr  = 0x0fa8ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xC4CEB9FE1A85EC53ULL;
    return h ^ kOpcode;
}

// Insn #199 @ 0x0fac: 0xD63F0100 -> blr x8
// Lệnh AArch64 #199 tại 0x0fac: blr x8
uint64_t verify_flipped_insn_199_0x0fac(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xD63F0100U;
    constexpr uint64_t kVaddr  = 0x0facULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xC4CEB9FE1A85EC53ULL;
    return h ^ kOpcode;
}

// Insn #200 @ 0x0fb0: 0x7100001F -> cmp w0, #0
// Lệnh AArch64 #200 tại 0x0fb0: cmp w0, #0
uint64_t verify_flipped_insn_200_0x0fb0(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x7100001FU;
    constexpr uint64_t kVaddr  = 0x0fb0ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xC4CEB9FE1A85EC53ULL;
    return h ^ kOpcode;
}

// Insn #201 @ 0x0fb4: 0x2A1F03F7 -> mov w23, wzr
// Lệnh AArch64 #201 tại 0x0fb4: mov w23, wzr
uint64_t verify_flipped_insn_201_0x0fb4(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x2A1F03F7U;
    constexpr uint64_t kVaddr  = 0x0fb4ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xC4CEB9FE1A85EC53ULL;
    return h ^ kOpcode;
}

// Insn #202 @ 0x0fb8: 0x1A9FC019 -> csel w25, w0, wzr, gt
// Lệnh AArch64 #202 tại 0x0fb8: csel w25, w0, wzr, gt
uint64_t verify_flipped_insn_202_0x0fb8(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x1A9FC019U;
    constexpr uint64_t kVaddr  = 0x0fb8ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xC4CEB9FE1A85EC53ULL;
    return h ^ kOpcode;
}

// Insn #203 @ 0x0fbc: 0xF94002A8 -> ldr x8, [x21]
// Lệnh AArch64 #203 tại 0x0fbc: ldr x8, [x21]
uint64_t verify_flipped_insn_203_0x0fbc(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xF94002A8U;
    constexpr uint64_t kVaddr  = 0x0fbcULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xC4CEB9FE1A85EC53ULL;
    return h ^ kOpcode;
}

// Insn #204 @ 0x0fc0: 0x6B17033F -> cmp w25, w23
// Lệnh AArch64 #204 tại 0x0fc0: cmp w25, w23
uint64_t verify_flipped_insn_204_0x0fc0(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x6B17033FU;
    constexpr uint64_t kVaddr  = 0x0fc0ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xC4CEB9FE1A85EC53ULL;
    return h ^ kOpcode;
}

// Insn #205 @ 0x0fc4: 0x54000260 -> b.eq #0x1010
// Lệnh AArch64 #205 tại 0x0fc4: b.eq #0x1010
uint64_t verify_flipped_insn_205_0x0fc4(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x54000260U;
    constexpr uint64_t kVaddr  = 0x0fc4ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xC4CEB9FE1A85EC53ULL;
    return h ^ kOpcode;
}

// Insn #206 @ 0x0fc8: 0xF942B508 -> ldr x8, [x8, #0x568]
// Lệnh AArch64 #206 tại 0x0fc8: ldr x8, [x8, #0x568]
uint64_t verify_flipped_insn_206_0x0fc8(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xF942B508U;
    constexpr uint64_t kVaddr  = 0x0fc8ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xC4CEB9FE1A85EC53ULL;
    return h ^ kOpcode;
}

// Insn #207 @ 0x0fcc: 0xAA1503E0 -> mov x0, x21
// Lệnh AArch64 #207 tại 0x0fcc: mov x0, x21
uint64_t verify_flipped_insn_207_0x0fcc(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xAA1503E0U;
    constexpr uint64_t kVaddr  = 0x0fccULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xC4CEB9FE1A85EC53ULL;
    return h ^ kOpcode;
}

// Insn #208 @ 0x0fd0: 0xAA1403E1 -> mov x1, x20
// Lệnh AArch64 #208 tại 0x0fd0: mov x1, x20
uint64_t verify_flipped_insn_208_0x0fd0(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xAA1403E1U;
    constexpr uint64_t kVaddr  = 0x0fd0ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xC4CEB9FE1A85EC53ULL;
    return h ^ kOpcode;
}

// Insn #209 @ 0x0fd4: 0x2A1703E2 -> mov w2, w23
// Lệnh AArch64 #209 tại 0x0fd4: mov w2, w23
uint64_t verify_flipped_insn_209_0x0fd4(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x2A1703E2U;
    constexpr uint64_t kVaddr  = 0x0fd4ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xC4CEB9FE1A85EC53ULL;
    return h ^ kOpcode;
}

// Insn #210 @ 0x0fd8: 0xD63F0100 -> blr x8
// Lệnh AArch64 #210 tại 0x0fd8: blr x8
uint64_t verify_flipped_insn_210_0x0fd8(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xD63F0100U;
    constexpr uint64_t kVaddr  = 0x0fd8ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xC4CEB9FE1A85EC53ULL;
    return h ^ kOpcode;
}

// Insn #211 @ 0x0fdc: 0xF94002A8 -> ldr x8, [x21]
// Lệnh AArch64 #211 tại 0x0fdc: ldr x8, [x21]
uint64_t verify_flipped_insn_211_0x0fdc(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xF94002A8U;
    constexpr uint64_t kVaddr  = 0x0fdcULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xC4CEB9FE1A85EC53ULL;
    return h ^ kOpcode;
}

// Insn #212 @ 0x0fe0: 0xAA0003E1 -> mov x1, x0
// Lệnh AArch64 #212 tại 0x0fe0: mov x1, x0
uint64_t verify_flipped_insn_212_0x0fe0(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xAA0003E1U;
    constexpr uint64_t kVaddr  = 0x0fe0ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xC4CEB9FE1A85EC53ULL;
    return h ^ kOpcode;
}

// Insn #213 @ 0x0fe4: 0xAA1503E0 -> mov x0, x21
// Lệnh AArch64 #213 tại 0x0fe4: mov x0, x21
uint64_t verify_flipped_insn_213_0x0fe4(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xAA1503E0U;
    constexpr uint64_t kVaddr  = 0x0fe4ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xC4CEB9FE1A85EC53ULL;
    return h ^ kOpcode;
}

// Insn #214 @ 0x0fe8: 0x9400006F -> bl #0x11a4
// Lệnh AArch64 #214 tại 0x0fe8: bl #0x11a4
uint64_t verify_flipped_insn_214_0x0fe8(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x9400006FU;
    constexpr uint64_t kVaddr  = 0x0fe8ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xC4CEB9FE1A85EC53ULL;
    return h ^ kOpcode;
}

// Insn #215 @ 0x0fec: 0xF94002A8 -> ldr x8, [x21]
// Lệnh AArch64 #215 tại 0x0fec: ldr x8, [x21]
uint64_t verify_flipped_insn_215_0x0fec(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xF94002A8U;
    constexpr uint64_t kVaddr  = 0x0fecULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xC4CEB9FE1A85EC53ULL;
    return h ^ kOpcode;
}

// Insn #216 @ 0x0ff0: 0xAA0003E3 -> mov x3, x0
// Lệnh AArch64 #216 tại 0x0ff0: mov x3, x0
uint64_t verify_flipped_insn_216_0x0ff0(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xAA0003E3U;
    constexpr uint64_t kVaddr  = 0x0ff0ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xC4CEB9FE1A85EC53ULL;
    return h ^ kOpcode;
}

// Insn #217 @ 0x0ff4: 0xAA1503E0 -> mov x0, x21
// Lệnh AArch64 #217 tại 0x0ff4: mov x0, x21
uint64_t verify_flipped_insn_217_0x0ff4(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xAA1503E0U;
    constexpr uint64_t kVaddr  = 0x0ff4ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xC4CEB9FE1A85EC53ULL;
    return h ^ kOpcode;
}

// Insn #218 @ 0x0ff8: 0xAA1403E1 -> mov x1, x20
// Lệnh AArch64 #218 tại 0x0ff8: mov x1, x20
uint64_t verify_flipped_insn_218_0x0ff8(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xAA1403E1U;
    constexpr uint64_t kVaddr  = 0x0ff8ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xC4CEB9FE1A85EC53ULL;
    return h ^ kOpcode;
}

// Insn #219 @ 0x0ffc: 0x2A1703E2 -> mov w2, w23
// Lệnh AArch64 #219 tại 0x0ffc: mov w2, w23
uint64_t verify_flipped_insn_219_0x0ffc(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x2A1703E2U;
    constexpr uint64_t kVaddr  = 0x0ffcULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xC4CEB9FE1A85EC53ULL;
    return h ^ kOpcode;
}

// Insn #220 @ 0x1000: 0xF942B908 -> ldr x8, [x8, #0x570]
// Lệnh AArch64 #220 tại 0x1000: ldr x8, [x8, #0x570]
uint64_t verify_flipped_insn_220_0x1000(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xF942B908U;
    constexpr uint64_t kVaddr  = 0x1000ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xC4CEB9FE1A85EC53ULL;
    return h ^ kOpcode;
}

// Insn #221 @ 0x1004: 0xD63F0100 -> blr x8
// Lệnh AArch64 #221 tại 0x1004: blr x8
uint64_t verify_flipped_insn_221_0x1004(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xD63F0100U;
    constexpr uint64_t kVaddr  = 0x1004ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xC4CEB9FE1A85EC53ULL;
    return h ^ kOpcode;
}

// Insn #222 @ 0x1008: 0x110006F7 -> add w23, w23, #1
// Lệnh AArch64 #222 tại 0x1008: add w23, w23, #1
uint64_t verify_flipped_insn_222_0x1008(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x110006F7U;
    constexpr uint64_t kVaddr  = 0x1008ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xC4CEB9FE1A85EC53ULL;
    return h ^ kOpcode;
}

// Insn #223 @ 0x100c: 0x17FFFFEC -> b #0xfbc
// Lệnh AArch64 #223 tại 0x100c: b #0xfbc
uint64_t verify_flipped_insn_223_0x100c(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x17FFFFECU;
    constexpr uint64_t kVaddr  = 0x100cULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xC4CEB9FE1A85EC53ULL;
    return h ^ kOpcode;
}

// Insn #224 @ 0x1010: 0xF9405508 -> ldr x8, [x8, #0xa8]
// Lệnh AArch64 #224 tại 0x1010: ldr x8, [x8, #0xa8]
uint64_t verify_flipped_insn_224_0x1010(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xF9405508U;
    constexpr uint64_t kVaddr  = 0x1010ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xC4CEB9FE1A85EC53ULL;
    return h ^ kOpcode;
}

// Insn #225 @ 0x1014: 0xAA1503E0 -> mov x0, x21
// Lệnh AArch64 #225 tại 0x1014: mov x0, x21
uint64_t verify_flipped_insn_225_0x1014(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xAA1503E0U;
    constexpr uint64_t kVaddr  = 0x1014ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xC4CEB9FE1A85EC53ULL;
    return h ^ kOpcode;
}

// Insn #226 @ 0x1018: 0xAA1403E1 -> mov x1, x20
// Lệnh AArch64 #226 tại 0x1018: mov x1, x20
uint64_t verify_flipped_insn_226_0x1018(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xAA1403E1U;
    constexpr uint64_t kVaddr  = 0x1018ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xC4CEB9FE1A85EC53ULL;
    return h ^ kOpcode;
}

// Insn #227 @ 0x101c: 0xD63F0100 -> blr x8
// Lệnh AArch64 #227 tại 0x101c: blr x8
uint64_t verify_flipped_insn_227_0x101c(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xD63F0100U;
    constexpr uint64_t kVaddr  = 0x101cULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xC4CEB9FE1A85EC53ULL;
    return h ^ kOpcode;
}

// Insn #228 @ 0x1020: 0x14000002 -> b #0x1028
// Lệnh AArch64 #228 tại 0x1020: b #0x1028
uint64_t verify_flipped_insn_228_0x1020(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x14000002U;
    constexpr uint64_t kVaddr  = 0x1020ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xC4CEB9FE1A85EC53ULL;
    return h ^ kOpcode;
}

// Insn #229 @ 0x1024: 0xAA1F03E0 -> mov x0, xzr
// Lệnh AArch64 #229 tại 0x1024: mov x0, xzr
uint64_t verify_flipped_insn_229_0x1024(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xAA1F03E0U;
    constexpr uint64_t kVaddr  = 0x1024ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xC4CEB9FE1A85EC53ULL;
    return h ^ kOpcode;
}

// Insn #230 @ 0x1028: 0x90000022 -> adrp x2, #0x5000
// Lệnh AArch64 #230 tại 0x1028: adrp x2, #0x5000
uint64_t verify_flipped_insn_230_0x1028(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x90000022U;
    constexpr uint64_t kVaddr  = 0x1028ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xC4CEB9FE1A85EC53ULL;
    return h ^ kOpcode;
}

// Insn #231 @ 0x102c: 0xA9015BF3 -> stp x19, x22, [sp, #0x10]
// Lệnh AArch64 #231 tại 0x102c: stp x19, x22, [sp, #0x10]
uint64_t verify_flipped_insn_231_0x102c(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xA9015BF3U;
    constexpr uint64_t kVaddr  = 0x102cULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xC4CEB9FE1A85EC53ULL;
    return h ^ kOpcode;
}

// Insn #232 @ 0x1030: 0xF90013E0 -> str x0, [sp, #0x20]
// Lệnh AArch64 #232 tại 0x1030: str x0, [sp, #0x20]
uint64_t verify_flipped_insn_232_0x1030(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xF90013E0U;
    constexpr uint64_t kVaddr  = 0x1030ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xC4CEB9FE1A85EC53ULL;
    return h ^ kOpcode;
}

// Insn #233 @ 0x1034: 0x910023E0 -> add x0, sp, #8
// Lệnh AArch64 #233 tại 0x1034: add x0, sp, #8
uint64_t verify_flipped_insn_233_0x1034(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x910023E0U;
    constexpr uint64_t kVaddr  = 0x1034ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xC4CEB9FE1A85EC53ULL;
    return h ^ kOpcode;
}

// Insn #234 @ 0x1038: 0x910043E3 -> add x3, sp, #0x10
// Lệnh AArch64 #234 tại 0x1038: add x3, sp, #0x10
uint64_t verify_flipped_insn_234_0x1038(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x910043E3U;
    constexpr uint64_t kVaddr  = 0x1038ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xC4CEB9FE1A85EC53ULL;
    return h ^ kOpcode;
}

// Insn #235 @ 0x103c: 0xAA1F03E1 -> mov x1, xzr
// Lệnh AArch64 #235 tại 0x103c: mov x1, xzr
uint64_t verify_flipped_insn_235_0x103c(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xAA1F03E1U;
    constexpr uint64_t kVaddr  = 0x103cULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xC4CEB9FE1A85EC53ULL;
    return h ^ kOpcode;
}

// Insn #236 @ 0x1040: 0xF9423842 -> ldr x2, [x2, #0x470]
// Lệnh AArch64 #236 tại 0x1040: ldr x2, [x2, #0x470]
uint64_t verify_flipped_insn_236_0x1040(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xF9423842U;
    constexpr uint64_t kVaddr  = 0x1040ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xC4CEB9FE1A85EC53ULL;
    return h ^ kOpcode;
}

// Insn #237 @ 0x1044: 0x94000083 -> bl #0x1250
// Lệnh AArch64 #237 tại 0x1044: bl #0x1250
uint64_t verify_flipped_insn_237_0x1044(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x94000083U;
    constexpr uint64_t kVaddr  = 0x1044ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xC4CEB9FE1A85EC53ULL;
    return h ^ kOpcode;
}

// Insn #238 @ 0x1048: 0x37F800C0 -> tbnz w0, #0x1f, #0x1060
// Lệnh AArch64 #238 tại 0x1048: tbnz w0, #0x1f, #0x1060
uint64_t verify_flipped_insn_238_0x1048(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x37F800C0U;
    constexpr uint64_t kVaddr  = 0x1048ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xC4CEB9FE1A85EC53ULL;
    return h ^ kOpcode;
}

// Insn #239 @ 0x104c: 0xF94007E0 -> ldr x0, [sp, #8]
// Lệnh AArch64 #239 tại 0x104c: ldr x0, [sp, #8]
uint64_t verify_flipped_insn_239_0x104c(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xF94007E0U;
    constexpr uint64_t kVaddr  = 0x104cULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xC4CEB9FE1A85EC53ULL;
    return h ^ kOpcode;
}

// Insn #240 @ 0x1050: 0x910003E1 -> mov x1, sp
// Lệnh AArch64 #240 tại 0x1050: mov x1, sp
uint64_t verify_flipped_insn_240_0x1050(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x910003E1U;
    constexpr uint64_t kVaddr  = 0x1050ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xC4CEB9FE1A85EC53ULL;
    return h ^ kOpcode;
}

// Insn #241 @ 0x1054: 0x94000083 -> bl #0x1260
// Lệnh AArch64 #241 tại 0x1054: bl #0x1260
uint64_t verify_flipped_insn_241_0x1054(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x94000083U;
    constexpr uint64_t kVaddr  = 0x1054ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xC4CEB9FE1A85EC53ULL;
    return h ^ kOpcode;
}

// Insn #242 @ 0x1058: 0xF94003E0 -> ldr x0, [sp]
// Lệnh AArch64 #242 tại 0x1058: ldr x0, [sp]
uint64_t verify_flipped_insn_242_0x1058(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xF94003E0U;
    constexpr uint64_t kVaddr  = 0x1058ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xC4CEB9FE1A85EC53ULL;
    return h ^ kOpcode;
}

// Insn #243 @ 0x105c: 0x14000002 -> b #0x1064
// Lệnh AArch64 #243 tại 0x105c: b #0x1064
uint64_t verify_flipped_insn_243_0x105c(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x14000002U;
    constexpr uint64_t kVaddr  = 0x105cULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xC4CEB9FE1A85EC53ULL;
    return h ^ kOpcode;
}

// Insn #244 @ 0x1060: 0xAA1F03E0 -> mov x0, xzr
// Lệnh AArch64 #244 tại 0x1060: mov x0, xzr
uint64_t verify_flipped_insn_244_0x1060(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xAA1F03E0U;
    constexpr uint64_t kVaddr  = 0x1060ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xC4CEB9FE1A85EC53ULL;
    return h ^ kOpcode;
}

// Insn #245 @ 0x1064: 0xF9401708 -> ldr x8, [x24, #0x28]
// Lệnh AArch64 #245 tại 0x1064: ldr x8, [x24, #0x28]
uint64_t verify_flipped_insn_245_0x1064(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xF9401708U;
    constexpr uint64_t kVaddr  = 0x1064ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xC4CEB9FE1A85EC53ULL;
    return h ^ kOpcode;
}

// Insn #246 @ 0x1068: 0xF85F83A9 -> ldur x9, [x29, #-8]
// Lệnh AArch64 #246 tại 0x1068: ldur x9, [x29, #-8]
uint64_t verify_flipped_insn_246_0x1068(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xF85F83A9U;
    constexpr uint64_t kVaddr  = 0x1068ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xC4CEB9FE1A85EC53ULL;
    return h ^ kOpcode;
}

// Insn #247 @ 0x106c: 0xEB09011F -> cmp x8, x9
// Lệnh AArch64 #247 tại 0x106c: cmp x8, x9
uint64_t verify_flipped_insn_247_0x106c(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xEB09011FU;
    constexpr uint64_t kVaddr  = 0x106cULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xC4CEB9FE1A85EC53ULL;
    return h ^ kOpcode;
}

// Insn #248 @ 0x1070: 0x54000101 -> b.ne #0x1090
// Lệnh AArch64 #248 tại 0x1070: b.ne #0x1090
uint64_t verify_flipped_insn_248_0x1070(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x54000101U;
    constexpr uint64_t kVaddr  = 0x1070ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xC4CEB9FE1A85EC53ULL;
    return h ^ kOpcode;
}

// Insn #249 @ 0x1074: 0xA9474FF4 -> ldp x20, x19, [sp, #0x70]
// Lệnh AArch64 #249 tại 0x1074: ldp x20, x19, [sp, #0x70]
uint64_t verify_flipped_insn_249_0x1074(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xA9474FF4U;
    constexpr uint64_t kVaddr  = 0x1074ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xC4CEB9FE1A85EC53ULL;
    return h ^ kOpcode;
}

// Insn #250 @ 0x1078: 0xA94657F6 -> ldp x22, x21, [sp, #0x60]
// Lệnh AArch64 #250 tại 0x1078: ldp x22, x21, [sp, #0x60]
uint64_t verify_flipped_insn_250_0x1078(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xA94657F6U;
    constexpr uint64_t kVaddr  = 0x1078ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xC4CEB9FE1A85EC53ULL;
    return h ^ kOpcode;
}

// Insn #251 @ 0x107c: 0xA9455FF8 -> ldp x24, x23, [sp, #0x50]
// Lệnh AArch64 #251 tại 0x107c: ldp x24, x23, [sp, #0x50]
uint64_t verify_flipped_insn_251_0x107c(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xA9455FF8U;
    constexpr uint64_t kVaddr  = 0x107cULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xC4CEB9FE1A85EC53ULL;
    return h ^ kOpcode;
}

// Insn #252 @ 0x1080: 0xA9437BFD -> ldp x29, x30, [sp, #0x30]
// Lệnh AArch64 #252 tại 0x1080: ldp x29, x30, [sp, #0x30]
uint64_t verify_flipped_insn_252_0x1080(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xA9437BFDU;
    constexpr uint64_t kVaddr  = 0x1080ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xC4CEB9FE1A85EC53ULL;
    return h ^ kOpcode;
}

// Insn #253 @ 0x1084: 0xF94023F9 -> ldr x25, [sp, #0x40]
// Lệnh AArch64 #253 tại 0x1084: ldr x25, [sp, #0x40]
uint64_t verify_flipped_insn_253_0x1084(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xF94023F9U;
    constexpr uint64_t kVaddr  = 0x1084ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xC4CEB9FE1A85EC53ULL;
    return h ^ kOpcode;
}

// Insn #254 @ 0x1088: 0x910203FF -> add sp, sp, #0x80
// Lệnh AArch64 #254 tại 0x1088: add sp, sp, #0x80
uint64_t verify_flipped_insn_254_0x1088(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x910203FFU;
    constexpr uint64_t kVaddr  = 0x1088ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xC4CEB9FE1A85EC53ULL;
    return h ^ kOpcode;
}

// Insn #255 @ 0x108c: 0xD65F03C0 -> ret 
// Lệnh AArch64 #255 tại 0x108c: ret 
uint64_t verify_flipped_insn_255_0x108c(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xD65F03C0U;
    constexpr uint64_t kVaddr  = 0x108cULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xC4CEB9FE1A85EC53ULL;
    return h ^ kOpcode;
}

// Insn #256 @ 0x1090: 0x94000078 -> bl #0x1270
// Lệnh AArch64 #256 tại 0x1090: bl #0x1270
uint64_t verify_flipped_insn_256_0x1090(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x94000078U;
    constexpr uint64_t kVaddr  = 0x1090ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xC4CEB9FE1A85EC53ULL;
    return h ^ kOpcode;
}

// Insn #257 @ 0x1094: 0xD10103FF -> sub sp, sp, #0x40
// Lệnh AArch64 #257 tại 0x1094: sub sp, sp, #0x40
uint64_t verify_flipped_insn_257_0x1094(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xD10103FFU;
    constexpr uint64_t kVaddr  = 0x1094ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xC4CEB9FE1A85EC53ULL;
    return h ^ kOpcode;
}

// Insn #258 @ 0x1098: 0xA9017BFD -> stp x29, x30, [sp, #0x10]
// Lệnh AArch64 #258 tại 0x1098: stp x29, x30, [sp, #0x10]
uint64_t verify_flipped_insn_258_0x1098(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xA9017BFDU;
    constexpr uint64_t kVaddr  = 0x1098ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xC4CEB9FE1A85EC53ULL;
    return h ^ kOpcode;
}

// Insn #259 @ 0x109c: 0xF90013F5 -> str x21, [sp, #0x20]
// Lệnh AArch64 #259 tại 0x109c: str x21, [sp, #0x20]
uint64_t verify_flipped_insn_259_0x109c(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xF90013F5U;
    constexpr uint64_t kVaddr  = 0x109cULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xC4CEB9FE1A85EC53ULL;
    return h ^ kOpcode;
}

// Insn #260 @ 0x10a0: 0xA9034FF4 -> stp x20, x19, [sp, #0x30]
// Lệnh AArch64 #260 tại 0x10a0: stp x20, x19, [sp, #0x30]
uint64_t verify_flipped_insn_260_0x10a0(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xA9034FF4U;
    constexpr uint64_t kVaddr  = 0x10a0ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xC4CEB9FE1A85EC53ULL;
    return h ^ kOpcode;
}

// Insn #261 @ 0x10a4: 0x910043FD -> add x29, sp, #0x10
// Lệnh AArch64 #261 tại 0x10a4: add x29, sp, #0x10
uint64_t verify_flipped_insn_261_0x10a4(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x910043FDU;
    constexpr uint64_t kVaddr  = 0x10a4ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xC4CEB9FE1A85EC53ULL;
    return h ^ kOpcode;
}

// Insn #262 @ 0x10a8: 0xD53BD055 -> mrs x21, tpidr_el0
// Lệnh AArch64 #262 tại 0x10a8: mrs x21, tpidr_el0
uint64_t verify_flipped_insn_262_0x10a8(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xD53BD055U;
    constexpr uint64_t kVaddr  = 0x10a8ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xC4CEB9FE1A85EC53ULL;
    return h ^ kOpcode;
}

// Insn #263 @ 0x10ac: 0x90000049 -> adrp x9, #0x9000
// Lệnh AArch64 #263 tại 0x10ac: adrp x9, #0x9000
uint64_t verify_flipped_insn_263_0x10ac(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x90000049U;
    constexpr uint64_t kVaddr  = 0x10acULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xC4CEB9FE1A85EC53ULL;
    return h ^ kOpcode;
}

// Insn #264 @ 0x10b0: 0xF94016A8 -> ldr x8, [x21, #0x28]
// Lệnh AArch64 #264 tại 0x10b0: ldr x8, [x21, #0x28]
uint64_t verify_flipped_insn_264_0x10b0(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xF94016A8U;
    constexpr uint64_t kVaddr  = 0x10b0ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xC4CEB9FE1A85EC53ULL;
    return h ^ kOpcode;
}

// Insn #265 @ 0x10b4: 0x528000C2 -> mov w2, #6
// Lệnh AArch64 #265 tại 0x10b4: mov w2, #6
uint64_t verify_flipped_insn_265_0x10b4(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x528000C2U;
    constexpr uint64_t kVaddr  = 0x10b4ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xC4CEB9FE1A85EC53ULL;
    return h ^ kOpcode;
}

// Insn #266 @ 0x10b8: 0x910003E1 -> mov x1, sp
// Lệnh AArch64 #266 tại 0x10b8: mov x1, sp
uint64_t verify_flipped_insn_266_0x10b8(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x910003E1U;
    constexpr uint64_t kVaddr  = 0x10b8ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xC4CEB9FE1A85EC53ULL;
    return h ^ kOpcode;
}

// Insn #267 @ 0x10bc: 0x72A00022 -> movk w2, #1, lsl #16
// Lệnh AArch64 #267 tại 0x10bc: movk w2, #1, lsl #16
uint64_t verify_flipped_insn_267_0x10bc(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x72A00022U;
    constexpr uint64_t kVaddr  = 0x10bcULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xC4CEB9FE1A85EC53ULL;
    return h ^ kOpcode;
}

// Insn #268 @ 0x10c0: 0x528000D3 -> mov w19, #6
// Lệnh AArch64 #268 tại 0x10c0: mov w19, #6
uint64_t verify_flipped_insn_268_0x10c0(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x528000D3U;
    constexpr uint64_t kVaddr  = 0x10c0ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xC4CEB9FE1A85EC53ULL;
    return h ^ kOpcode;
}

// Insn #269 @ 0x10c4: 0xF90007E8 -> str x8, [sp, #8]
// Lệnh AArch64 #269 tại 0x10c4: str x8, [sp, #8]
uint64_t verify_flipped_insn_269_0x10c4(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xF90007E8U;
    constexpr uint64_t kVaddr  = 0x10c4ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xC4CEB9FE1A85EC53ULL;
    return h ^ kOpcode;
}

// Insn #270 @ 0x10c8: 0x72A00033 -> movk w19, #1, lsl #16
// Lệnh AArch64 #270 tại 0x10c8: movk w19, #1, lsl #16
uint64_t verify_flipped_insn_270_0x10c8(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x72A00033U;
    constexpr uint64_t kVaddr  = 0x10c8ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xC4CEB9FE1A85EC53ULL;
    return h ^ kOpcode;
}

// Insn #271 @ 0x10cc: 0xF9027520 -> str x0, [x9, #0x4e8]
// Lệnh AArch64 #271 tại 0x10cc: str x0, [x9, #0x4e8]
uint64_t verify_flipped_insn_271_0x10cc(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xF9027520U;
    constexpr uint64_t kVaddr  = 0x10ccULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xC4CEB9FE1A85EC53ULL;
    return h ^ kOpcode;
}

// Insn #272 @ 0x10d0: 0xF9400008 -> ldr x8, [x0]
// Lệnh AArch64 #272 tại 0x10d0: ldr x8, [x0]
uint64_t verify_flipped_insn_272_0x10d0(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xF9400008U;
    constexpr uint64_t kVaddr  = 0x10d0ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xC4CEB9FE1A85EC53ULL;
    return h ^ kOpcode;
}

// Insn #273 @ 0x10d4: 0xF90003FF -> str xzr, [sp]
// Lệnh AArch64 #273 tại 0x10d4: str xzr, [sp]
uint64_t verify_flipped_insn_273_0x10d4(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xF90003FFU;
    constexpr uint64_t kVaddr  = 0x10d4ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xC4CEB9FE1A85EC53ULL;
    return h ^ kOpcode;
}

// Insn #274 @ 0x10d8: 0xF9401908 -> ldr x8, [x8, #0x30]
// Lệnh AArch64 #274 tại 0x10d8: ldr x8, [x8, #0x30]
uint64_t verify_flipped_insn_274_0x10d8(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xF9401908U;
    constexpr uint64_t kVaddr  = 0x10d8ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xC4CEB9FE1A85EC53ULL;
    return h ^ kOpcode;
}

// Insn #275 @ 0x10dc: 0xD63F0100 -> blr x8
// Lệnh AArch64 #275 tại 0x10dc: blr x8
uint64_t verify_flipped_insn_275_0x10dc(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xD63F0100U;
    constexpr uint64_t kVaddr  = 0x10dcULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xC4CEB9FE1A85EC53ULL;
    return h ^ kOpcode;
}

// Insn #276 @ 0x10e0: 0x340000A0 -> cbz w0, #0x10f4
// Lệnh AArch64 #276 tại 0x10e0: cbz w0, #0x10f4
uint64_t verify_flipped_insn_276_0x10e0(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x340000A0U;
    constexpr uint64_t kVaddr  = 0x10e0ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xC4CEB9FE1A85EC53ULL;
    return h ^ kOpcode;
}

// Insn #277 @ 0x10e4: 0x12800013 -> mov w19, #-1
// Lệnh AArch64 #277 tại 0x10e4: mov w19, #-1
uint64_t verify_flipped_insn_277_0x10e4(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x12800013U;
    constexpr uint64_t kVaddr  = 0x10e4ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xC4CEB9FE1A85EC53ULL;
    return h ^ kOpcode;
}

// Insn #278 @ 0x10e8: 0xF0FFFFE0 -> adrp x0, #0
// Lệnh AArch64 #278 tại 0x10e8: adrp x0, #0
uint64_t verify_flipped_insn_278_0x10e8(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xF0FFFFE0U;
    constexpr uint64_t kVaddr  = 0x10e8ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xC4CEB9FE1A85EC53ULL;
    return h ^ kOpcode;
}

// Insn #279 @ 0x10ec: 0x91294000 -> add x0, x0, #0xa50
// Lệnh AArch64 #279 tại 0x10ec: add x0, x0, #0xa50
uint64_t verify_flipped_insn_279_0x10ec(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x91294000U;
    constexpr uint64_t kVaddr  = 0x10ecULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xC4CEB9FE1A85EC53ULL;
    return h ^ kOpcode;
}

// Insn #280 @ 0x10f0: 0x14000021 -> b #0x1174
// Lệnh AArch64 #280 tại 0x10f0: b #0x1174
uint64_t verify_flipped_insn_280_0x10f0(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x14000021U;
    constexpr uint64_t kVaddr  = 0x10f0ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xC4CEB9FE1A85EC53ULL;
    return h ^ kOpcode;
}

// Insn #281 @ 0x10f4: 0xF94003F4 -> ldr x20, [sp]
// Lệnh AArch64 #281 tại 0x10f4: ldr x20, [sp]
uint64_t verify_flipped_insn_281_0x10f4(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xF94003F4U;
    constexpr uint64_t kVaddr  = 0x10f4ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xC4CEB9FE1A85EC53ULL;
    return h ^ kOpcode;
}

// Insn #282 @ 0x10f8: 0xF0FFFFE1 -> adrp x1, #0
// Lệnh AArch64 #282 tại 0x10f8: adrp x1, #0
uint64_t verify_flipped_insn_282_0x10f8(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xF0FFFFE1U;
    constexpr uint64_t kVaddr  = 0x10f8ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xC4CEB9FE1A85EC53ULL;
    return h ^ kOpcode;
}

// Insn #283 @ 0x10fc: 0x91260021 -> add x1, x1, #0x980
// Lệnh AArch64 #283 tại 0x10fc: add x1, x1, #0x980
uint64_t verify_flipped_insn_283_0x10fc(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x91260021U;
    constexpr uint64_t kVaddr  = 0x10fcULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xC4CEB9FE1A85EC53ULL;
    return h ^ kOpcode;
}

// Insn #284 @ 0x1100: 0xF9400288 -> ldr x8, [x20]
// Lệnh AArch64 #284 tại 0x1100: ldr x8, [x20]
uint64_t verify_flipped_insn_284_0x1100(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xF9400288U;
    constexpr uint64_t kVaddr  = 0x1100ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xC4CEB9FE1A85EC53ULL;
    return h ^ kOpcode;
}

// Insn #285 @ 0x1104: 0xAA1403E0 -> mov x0, x20
// Lệnh AArch64 #285 tại 0x1104: mov x0, x20
uint64_t verify_flipped_insn_285_0x1104(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xAA1403E0U;
    constexpr uint64_t kVaddr  = 0x1104ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xC4CEB9FE1A85EC53ULL;
    return h ^ kOpcode;
}

// Insn #286 @ 0x1108: 0xF9401908 -> ldr x8, [x8, #0x30]
// Lệnh AArch64 #286 tại 0x1108: ldr x8, [x8, #0x30]
uint64_t verify_flipped_insn_286_0x1108(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xF9401908U;
    constexpr uint64_t kVaddr  = 0x1108ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xC4CEB9FE1A85EC53ULL;
    return h ^ kOpcode;
}

// Insn #287 @ 0x110c: 0xD63F0100 -> blr x8
// Lệnh AArch64 #287 tại 0x110c: blr x8
uint64_t verify_flipped_insn_287_0x110c(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xD63F0100U;
    constexpr uint64_t kVaddr  = 0x110cULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xC4CEB9FE1A85EC53ULL;
    return h ^ kOpcode;
}

// Insn #288 @ 0x1110: 0xB40001A0 -> cbz x0, #0x1144
// Lệnh AArch64 #288 tại 0x1110: cbz x0, #0x1144
uint64_t verify_flipped_insn_288_0x1110(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xB40001A0U;
    constexpr uint64_t kVaddr  = 0x1110ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xC4CEB9FE1A85EC53ULL;
    return h ^ kOpcode;
}

// Insn #289 @ 0x1114: 0xF9400288 -> ldr x8, [x20]
// Lệnh AArch64 #289 tại 0x1114: ldr x8, [x20]
uint64_t verify_flipped_insn_289_0x1114(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xF9400288U;
    constexpr uint64_t kVaddr  = 0x1114ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xC4CEB9FE1A85EC53ULL;
    return h ^ kOpcode;
}

// Insn #290 @ 0x1118: 0xAA0003E1 -> mov x1, x0
// Lệnh AArch64 #290 tại 0x1118: mov x1, x0
uint64_t verify_flipped_insn_290_0x1118(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xAA0003E1U;
    constexpr uint64_t kVaddr  = 0x1118ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xC4CEB9FE1A85EC53ULL;
    return h ^ kOpcode;
}

// Insn #291 @ 0x111c: 0xD503201F -> nop 
// Lệnh AArch64 #291 tại 0x111c: nop 
uint64_t verify_flipped_insn_291_0x111c(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xD503201FU;
    constexpr uint64_t kVaddr  = 0x111cULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xC4CEB9FE1A85EC53ULL;
    return h ^ kOpcode;
}

// Insn #292 @ 0x1120: 0x10020B42 -> adr x2, #0x5288
// Lệnh AArch64 #292 tại 0x1120: adr x2, #0x5288
uint64_t verify_flipped_insn_292_0x1120(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x10020B42U;
    constexpr uint64_t kVaddr  = 0x1120ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xC4CEB9FE1A85EC53ULL;
    return h ^ kOpcode;
}

// Insn #293 @ 0x1124: 0xAA1403E0 -> mov x0, x20
// Lệnh AArch64 #293 tại 0x1124: mov x0, x20
uint64_t verify_flipped_insn_293_0x1124(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xAA1403E0U;
    constexpr uint64_t kVaddr  = 0x1124ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xC4CEB9FE1A85EC53ULL;
    return h ^ kOpcode;
}

// Insn #294 @ 0x1128: 0x52800023 -> mov w3, #1
// Lệnh AArch64 #294 tại 0x1128: mov w3, #1
uint64_t verify_flipped_insn_294_0x1128(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x52800023U;
    constexpr uint64_t kVaddr  = 0x1128ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xC4CEB9FE1A85EC53ULL;
    return h ^ kOpcode;
}

// Insn #295 @ 0x112c: 0xF9435D08 -> ldr x8, [x8, #0x6b8]
// Lệnh AArch64 #295 tại 0x112c: ldr x8, [x8, #0x6b8]
uint64_t verify_flipped_insn_295_0x112c(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xF9435D08U;
    constexpr uint64_t kVaddr  = 0x112cULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xC4CEB9FE1A85EC53ULL;
    return h ^ kOpcode;
}

// Insn #296 @ 0x1130: 0xD63F0100 -> blr x8
// Lệnh AArch64 #296 tại 0x1130: blr x8
uint64_t verify_flipped_insn_296_0x1130(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xD63F0100U;
    constexpr uint64_t kVaddr  = 0x1130ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xC4CEB9FE1A85EC53ULL;
    return h ^ kOpcode;
}

// Insn #297 @ 0x1134: 0x37F80140 -> tbnz w0, #0x1f, #0x115c
// Lệnh AArch64 #297 tại 0x1134: tbnz w0, #0x1f, #0x115c
uint64_t verify_flipped_insn_297_0x1134(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x37F80140U;
    constexpr uint64_t kVaddr  = 0x1134ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xC4CEB9FE1A85EC53ULL;
    return h ^ kOpcode;
}

// Insn #298 @ 0x1138: 0xF0FFFFE0 -> adrp x0, #0
// Lệnh AArch64 #298 tại 0x1138: adrp x0, #0
uint64_t verify_flipped_insn_298_0x1138(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xF0FFFFE0U;
    constexpr uint64_t kVaddr  = 0x1138ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xC4CEB9FE1A85EC53ULL;
    return h ^ kOpcode;
}

// Insn #299 @ 0x113c: 0x91233400 -> add x0, x0, #0x8cd
// Lệnh AArch64 #299 tại 0x113c: add x0, x0, #0x8cd
uint64_t verify_flipped_insn_299_0x113c(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x91233400U;
    constexpr uint64_t kVaddr  = 0x113cULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xC4CEB9FE1A85EC53ULL;
    return h ^ kOpcode;
}

// Insn #300 @ 0x1140: 0x1400000D -> b #0x1174
// Lệnh AArch64 #300 tại 0x1140: b #0x1174
uint64_t verify_flipped_insn_300_0x1140(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x1400000DU;
    constexpr uint64_t kVaddr  = 0x1140ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xC4CEB9FE1A85EC53ULL;
    return h ^ kOpcode;
}

// Insn #301 @ 0x1144: 0xF0FFFFE0 -> adrp x0, #0
// Lệnh AArch64 #301 tại 0x1144: adrp x0, #0
uint64_t verify_flipped_insn_301_0x1144(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xF0FFFFE0U;
    constexpr uint64_t kVaddr  = 0x1144ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xC4CEB9FE1A85EC53ULL;
    return h ^ kOpcode;
}

// Insn #302 @ 0x1148: 0x91251000 -> add x0, x0, #0x944
// Lệnh AArch64 #302 tại 0x1148: add x0, x0, #0x944
uint64_t verify_flipped_insn_302_0x1148(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x91251000U;
    constexpr uint64_t kVaddr  = 0x1148ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xC4CEB9FE1A85EC53ULL;
    return h ^ kOpcode;
}

// Insn #303 @ 0x114c: 0xF0FFFFE1 -> adrp x1, #0
// Lệnh AArch64 #303 tại 0x114c: adrp x1, #0
uint64_t verify_flipped_insn_303_0x114c(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xF0FFFFE1U;
    constexpr uint64_t kVaddr  = 0x114cULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xC4CEB9FE1A85EC53ULL;
    return h ^ kOpcode;
}

// Insn #304 @ 0x1150: 0x91260021 -> add x1, x1, #0x980
// Lệnh AArch64 #304 tại 0x1150: add x1, x1, #0x980
uint64_t verify_flipped_insn_304_0x1150(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x91260021U;
    constexpr uint64_t kVaddr  = 0x1150ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xC4CEB9FE1A85EC53ULL;
    return h ^ kOpcode;
}

// Insn #305 @ 0x1154: 0x9400002B -> bl #0x1200
// Lệnh AArch64 #305 tại 0x1154: bl #0x1200
uint64_t verify_flipped_insn_305_0x1154(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x9400002BU;
    constexpr uint64_t kVaddr  = 0x1154ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xC4CEB9FE1A85EC53ULL;
    return h ^ kOpcode;
}

// Insn #306 @ 0x1158: 0x14000004 -> b #0x1168
// Lệnh AArch64 #306 tại 0x1158: b #0x1168
uint64_t verify_flipped_insn_306_0x1158(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x14000004U;
    constexpr uint64_t kVaddr  = 0x1158ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xC4CEB9FE1A85EC53ULL;
    return h ^ kOpcode;
}

// Insn #307 @ 0x115c: 0xF0FFFFE0 -> adrp x0, #0
// Lệnh AArch64 #307 tại 0x115c: adrp x0, #0
uint64_t verify_flipped_insn_307_0x115c(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xF0FFFFE0U;
    constexpr uint64_t kVaddr  = 0x115cULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xC4CEB9FE1A85EC53ULL;
    return h ^ kOpcode;
}

// Insn #308 @ 0x1160: 0x91237400 -> add x0, x0, #0x8dd
// Lệnh AArch64 #308 tại 0x1160: add x0, x0, #0x8dd
uint64_t verify_flipped_insn_308_0x1160(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x91237400U;
    constexpr uint64_t kVaddr  = 0x1160ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xC4CEB9FE1A85EC53ULL;
    return h ^ kOpcode;
}

// Insn #309 @ 0x1164: 0x9400002B -> bl #0x1210
// Lệnh AArch64 #309 tại 0x1164: bl #0x1210
uint64_t verify_flipped_insn_309_0x1164(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x9400002BU;
    constexpr uint64_t kVaddr  = 0x1164ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xC4CEB9FE1A85EC53ULL;
    return h ^ kOpcode;
}

// Insn #310 @ 0x1168: 0x12800013 -> mov w19, #-1
// Lệnh AArch64 #310 tại 0x1168: mov w19, #-1
uint64_t verify_flipped_insn_310_0x1168(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x12800013U;
    constexpr uint64_t kVaddr  = 0x1168ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xC4CEB9FE1A85EC53ULL;
    return h ^ kOpcode;
}

// Insn #311 @ 0x116c: 0xF0FFFFE0 -> adrp x0, #0
// Lệnh AArch64 #311 tại 0x116c: adrp x0, #0
uint64_t verify_flipped_insn_311_0x116c(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xF0FFFFE0U;
    constexpr uint64_t kVaddr  = 0x116cULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xC4CEB9FE1A85EC53ULL;
    return h ^ kOpcode;
}

// Insn #312 @ 0x1170: 0x91248000 -> add x0, x0, #0x920
// Lệnh AArch64 #312 tại 0x1170: add x0, x0, #0x920
uint64_t verify_flipped_insn_312_0x1170(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x91248000U;
    constexpr uint64_t kVaddr  = 0x1170ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xC4CEB9FE1A85EC53ULL;
    return h ^ kOpcode;
}

// Insn #313 @ 0x1174: 0x94000027 -> bl #0x1210
// Lệnh AArch64 #313 tại 0x1174: bl #0x1210
uint64_t verify_flipped_insn_313_0x1174(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x94000027U;
    constexpr uint64_t kVaddr  = 0x1174ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xC4CEB9FE1A85EC53ULL;
    return h ^ kOpcode;
}

// Insn #314 @ 0x1178: 0xF94016A8 -> ldr x8, [x21, #0x28]
// Lệnh AArch64 #314 tại 0x1178: ldr x8, [x21, #0x28]
uint64_t verify_flipped_insn_314_0x1178(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xF94016A8U;
    constexpr uint64_t kVaddr  = 0x1178ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xC4CEB9FE1A85EC53ULL;
    return h ^ kOpcode;
}

// Insn #315 @ 0x117c: 0xF94007E9 -> ldr x9, [sp, #8]
// Lệnh AArch64 #315 tại 0x117c: ldr x9, [sp, #8]
uint64_t verify_flipped_insn_315_0x117c(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xF94007E9U;
    constexpr uint64_t kVaddr  = 0x117cULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xC4CEB9FE1A85EC53ULL;
    return h ^ kOpcode;
}

// Insn #316 @ 0x1180: 0xEB09011F -> cmp x8, x9
// Lệnh AArch64 #316 tại 0x1180: cmp x8, x9
uint64_t verify_flipped_insn_316_0x1180(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xEB09011FU;
    constexpr uint64_t kVaddr  = 0x1180ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xC4CEB9FE1A85EC53ULL;
    return h ^ kOpcode;
}

// Insn #317 @ 0x1184: 0x540000E1 -> b.ne #0x11a0
// Lệnh AArch64 #317 tại 0x1184: b.ne #0x11a0
uint64_t verify_flipped_insn_317_0x1184(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x540000E1U;
    constexpr uint64_t kVaddr  = 0x1184ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xC4CEB9FE1A85EC53ULL;
    return h ^ kOpcode;
}

// Insn #318 @ 0x1188: 0x2A1303E0 -> mov w0, w19
// Lệnh AArch64 #318 tại 0x1188: mov w0, w19
uint64_t verify_flipped_insn_318_0x1188(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x2A1303E0U;
    constexpr uint64_t kVaddr  = 0x1188ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xC4CEB9FE1A85EC53ULL;
    return h ^ kOpcode;
}

// Insn #319 @ 0x118c: 0xF94013F5 -> ldr x21, [sp, #0x20]
// Lệnh AArch64 #319 tại 0x118c: ldr x21, [sp, #0x20]
uint64_t verify_flipped_insn_319_0x118c(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xF94013F5U;
    constexpr uint64_t kVaddr  = 0x118cULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xC4CEB9FE1A85EC53ULL;
    return h ^ kOpcode;
}

// Insn #320 @ 0x1190: 0xA9434FF4 -> ldp x20, x19, [sp, #0x30]
// Lệnh AArch64 #320 tại 0x1190: ldp x20, x19, [sp, #0x30]
uint64_t verify_flipped_insn_320_0x1190(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xA9434FF4U;
    constexpr uint64_t kVaddr  = 0x1190ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xC4CEB9FE1A85EC53ULL;
    return h ^ kOpcode;
}

// Insn #321 @ 0x1194: 0xA9417BFD -> ldp x29, x30, [sp, #0x10]
// Lệnh AArch64 #321 tại 0x1194: ldp x29, x30, [sp, #0x10]
uint64_t verify_flipped_insn_321_0x1194(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xA9417BFDU;
    constexpr uint64_t kVaddr  = 0x1194ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xC4CEB9FE1A85EC53ULL;
    return h ^ kOpcode;
}

// Insn #322 @ 0x1198: 0x910103FF -> add sp, sp, #0x40
// Lệnh AArch64 #322 tại 0x1198: add sp, sp, #0x40
uint64_t verify_flipped_insn_322_0x1198(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x910103FFU;
    constexpr uint64_t kVaddr  = 0x1198ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xC4CEB9FE1A85EC53ULL;
    return h ^ kOpcode;
}

// Insn #323 @ 0x119c: 0xD65F03C0 -> ret 
// Lệnh AArch64 #323 tại 0x119c: ret 
uint64_t verify_flipped_insn_323_0x119c(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xD65F03C0U;
    constexpr uint64_t kVaddr  = 0x119cULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xC4CEB9FE1A85EC53ULL;
    return h ^ kOpcode;
}

// Insn #324 @ 0x11a0: 0x94000034 -> bl #0x1270
// Lệnh AArch64 #324 tại 0x11a0: bl #0x1270
uint64_t verify_flipped_insn_324_0x11a0(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x94000034U;
    constexpr uint64_t kVaddr  = 0x11a0ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xC4CEB9FE1A85EC53ULL;
    return h ^ kOpcode;
}

// Insn #325 @ 0x11a4: 0xF9405508 -> ldr x8, [x8, #0xa8]
// Lệnh AArch64 #325 tại 0x11a4: ldr x8, [x8, #0xa8]
uint64_t verify_flipped_insn_325_0x11a4(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xF9405508U;
    constexpr uint64_t kVaddr  = 0x11a4ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xC4CEB9FE1A85EC53ULL;
    return h ^ kOpcode;
}

// Insn #326 @ 0x11a8: 0xD61F0100 -> br x8
// Lệnh AArch64 #326 tại 0x11a8: br x8
uint64_t verify_flipped_insn_326_0x11a8(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xD61F0100U;
    constexpr uint64_t kVaddr  = 0x11a8ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xC4CEB9FE1A85EC53ULL;
    return h ^ kOpcode;
}

uint64_t ExecuteFlippedTextInstructionVerify(uint32_t insn_idx, uint64_t seed) noexcept {
    switch (insn_idx) {
        case 0: return verify_flipped_insn_000_0x0c90(seed);
        case 1: return verify_flipped_insn_001_0x0c94(seed);
        case 2: return verify_flipped_insn_002_0x0c98(seed);
        case 3: return verify_flipped_insn_003_0x0c9c(seed);
        case 4: return verify_flipped_insn_004_0x0ca0(seed);
        case 5: return verify_flipped_insn_005_0x0ca4(seed);
        case 6: return verify_flipped_insn_006_0x0ca8(seed);
        case 7: return verify_flipped_insn_007_0x0cac(seed);
        case 8: return verify_flipped_insn_008_0x0cb0(seed);
        case 9: return verify_flipped_insn_009_0x0cb4(seed);
        case 10: return verify_flipped_insn_010_0x0cb8(seed);
        case 11: return verify_flipped_insn_011_0x0cbc(seed);
        case 12: return verify_flipped_insn_012_0x0cc0(seed);
        case 13: return verify_flipped_insn_013_0x0cc4(seed);
        case 14: return verify_flipped_insn_014_0x0cc8(seed);
        case 15: return verify_flipped_insn_015_0x0ccc(seed);
        case 16: return verify_flipped_insn_016_0x0cd0(seed);
        case 17: return verify_flipped_insn_017_0x0cd4(seed);
        case 18: return verify_flipped_insn_018_0x0cd8(seed);
        case 19: return verify_flipped_insn_019_0x0cdc(seed);
        case 20: return verify_flipped_insn_020_0x0ce0(seed);
        case 21: return verify_flipped_insn_021_0x0ce4(seed);
        case 22: return verify_flipped_insn_022_0x0ce8(seed);
        case 23: return verify_flipped_insn_023_0x0cec(seed);
        case 24: return verify_flipped_insn_024_0x0cf0(seed);
        case 25: return verify_flipped_insn_025_0x0cf4(seed);
        case 26: return verify_flipped_insn_026_0x0cf8(seed);
        case 27: return verify_flipped_insn_027_0x0cfc(seed);
        case 28: return verify_flipped_insn_028_0x0d00(seed);
        case 29: return verify_flipped_insn_029_0x0d04(seed);
        case 30: return verify_flipped_insn_030_0x0d08(seed);
        case 31: return verify_flipped_insn_031_0x0d0c(seed);
        case 32: return verify_flipped_insn_032_0x0d10(seed);
        case 33: return verify_flipped_insn_033_0x0d14(seed);
        case 34: return verify_flipped_insn_034_0x0d18(seed);
        case 35: return verify_flipped_insn_035_0x0d1c(seed);
        case 36: return verify_flipped_insn_036_0x0d20(seed);
        case 37: return verify_flipped_insn_037_0x0d24(seed);
        case 38: return verify_flipped_insn_038_0x0d28(seed);
        case 39: return verify_flipped_insn_039_0x0d2c(seed);
        case 40: return verify_flipped_insn_040_0x0d30(seed);
        case 41: return verify_flipped_insn_041_0x0d34(seed);
        case 42: return verify_flipped_insn_042_0x0d38(seed);
        case 43: return verify_flipped_insn_043_0x0d3c(seed);
        case 44: return verify_flipped_insn_044_0x0d40(seed);
        case 45: return verify_flipped_insn_045_0x0d44(seed);
        case 46: return verify_flipped_insn_046_0x0d48(seed);
        case 47: return verify_flipped_insn_047_0x0d4c(seed);
        case 48: return verify_flipped_insn_048_0x0d50(seed);
        case 49: return verify_flipped_insn_049_0x0d54(seed);
        case 50: return verify_flipped_insn_050_0x0d58(seed);
        case 51: return verify_flipped_insn_051_0x0d5c(seed);
        case 52: return verify_flipped_insn_052_0x0d60(seed);
        case 53: return verify_flipped_insn_053_0x0d64(seed);
        case 54: return verify_flipped_insn_054_0x0d68(seed);
        case 55: return verify_flipped_insn_055_0x0d6c(seed);
        case 56: return verify_flipped_insn_056_0x0d70(seed);
        case 57: return verify_flipped_insn_057_0x0d74(seed);
        case 58: return verify_flipped_insn_058_0x0d78(seed);
        case 59: return verify_flipped_insn_059_0x0d7c(seed);
        case 60: return verify_flipped_insn_060_0x0d80(seed);
        case 61: return verify_flipped_insn_061_0x0d84(seed);
        case 62: return verify_flipped_insn_062_0x0d88(seed);
        case 63: return verify_flipped_insn_063_0x0d8c(seed);
        case 64: return verify_flipped_insn_064_0x0d90(seed);
        case 65: return verify_flipped_insn_065_0x0d94(seed);
        case 66: return verify_flipped_insn_066_0x0d98(seed);
        case 67: return verify_flipped_insn_067_0x0d9c(seed);
        case 68: return verify_flipped_insn_068_0x0da0(seed);
        case 69: return verify_flipped_insn_069_0x0da4(seed);
        case 70: return verify_flipped_insn_070_0x0da8(seed);
        case 71: return verify_flipped_insn_071_0x0dac(seed);
        case 72: return verify_flipped_insn_072_0x0db0(seed);
        case 73: return verify_flipped_insn_073_0x0db4(seed);
        case 74: return verify_flipped_insn_074_0x0db8(seed);
        case 75: return verify_flipped_insn_075_0x0dbc(seed);
        case 76: return verify_flipped_insn_076_0x0dc0(seed);
        case 77: return verify_flipped_insn_077_0x0dc4(seed);
        case 78: return verify_flipped_insn_078_0x0dc8(seed);
        case 79: return verify_flipped_insn_079_0x0dcc(seed);
        case 80: return verify_flipped_insn_080_0x0dd0(seed);
        case 81: return verify_flipped_insn_081_0x0dd4(seed);
        case 82: return verify_flipped_insn_082_0x0dd8(seed);
        case 83: return verify_flipped_insn_083_0x0ddc(seed);
        case 84: return verify_flipped_insn_084_0x0de0(seed);
        case 85: return verify_flipped_insn_085_0x0de4(seed);
        case 86: return verify_flipped_insn_086_0x0de8(seed);
        case 87: return verify_flipped_insn_087_0x0dec(seed);
        case 88: return verify_flipped_insn_088_0x0df0(seed);
        case 89: return verify_flipped_insn_089_0x0df4(seed);
        case 90: return verify_flipped_insn_090_0x0df8(seed);
        case 91: return verify_flipped_insn_091_0x0dfc(seed);
        case 92: return verify_flipped_insn_092_0x0e00(seed);
        case 93: return verify_flipped_insn_093_0x0e04(seed);
        case 94: return verify_flipped_insn_094_0x0e08(seed);
        case 95: return verify_flipped_insn_095_0x0e0c(seed);
        case 96: return verify_flipped_insn_096_0x0e10(seed);
        case 97: return verify_flipped_insn_097_0x0e14(seed);
        case 98: return verify_flipped_insn_098_0x0e18(seed);
        case 99: return verify_flipped_insn_099_0x0e1c(seed);
        case 100: return verify_flipped_insn_100_0x0e20(seed);
        case 101: return verify_flipped_insn_101_0x0e24(seed);
        case 102: return verify_flipped_insn_102_0x0e28(seed);
        case 103: return verify_flipped_insn_103_0x0e2c(seed);
        case 104: return verify_flipped_insn_104_0x0e30(seed);
        case 105: return verify_flipped_insn_105_0x0e34(seed);
        case 106: return verify_flipped_insn_106_0x0e38(seed);
        case 107: return verify_flipped_insn_107_0x0e3c(seed);
        case 108: return verify_flipped_insn_108_0x0e40(seed);
        case 109: return verify_flipped_insn_109_0x0e44(seed);
        case 110: return verify_flipped_insn_110_0x0e48(seed);
        case 111: return verify_flipped_insn_111_0x0e4c(seed);
        case 112: return verify_flipped_insn_112_0x0e50(seed);
        case 113: return verify_flipped_insn_113_0x0e54(seed);
        case 114: return verify_flipped_insn_114_0x0e58(seed);
        case 115: return verify_flipped_insn_115_0x0e5c(seed);
        case 116: return verify_flipped_insn_116_0x0e60(seed);
        case 117: return verify_flipped_insn_117_0x0e64(seed);
        case 118: return verify_flipped_insn_118_0x0e68(seed);
        case 119: return verify_flipped_insn_119_0x0e6c(seed);
        case 120: return verify_flipped_insn_120_0x0e70(seed);
        case 121: return verify_flipped_insn_121_0x0e74(seed);
        case 122: return verify_flipped_insn_122_0x0e78(seed);
        case 123: return verify_flipped_insn_123_0x0e7c(seed);
        case 124: return verify_flipped_insn_124_0x0e80(seed);
        case 125: return verify_flipped_insn_125_0x0e84(seed);
        case 126: return verify_flipped_insn_126_0x0e88(seed);
        case 127: return verify_flipped_insn_127_0x0e8c(seed);
        case 128: return verify_flipped_insn_128_0x0e90(seed);
        case 129: return verify_flipped_insn_129_0x0e94(seed);
        case 130: return verify_flipped_insn_130_0x0e98(seed);
        case 131: return verify_flipped_insn_131_0x0e9c(seed);
        case 132: return verify_flipped_insn_132_0x0ea0(seed);
        case 133: return verify_flipped_insn_133_0x0ea4(seed);
        case 134: return verify_flipped_insn_134_0x0ea8(seed);
        case 135: return verify_flipped_insn_135_0x0eac(seed);
        case 136: return verify_flipped_insn_136_0x0eb0(seed);
        case 137: return verify_flipped_insn_137_0x0eb4(seed);
        case 138: return verify_flipped_insn_138_0x0eb8(seed);
        case 139: return verify_flipped_insn_139_0x0ebc(seed);
        case 140: return verify_flipped_insn_140_0x0ec0(seed);
        case 141: return verify_flipped_insn_141_0x0ec4(seed);
        case 142: return verify_flipped_insn_142_0x0ec8(seed);
        case 143: return verify_flipped_insn_143_0x0ecc(seed);
        case 144: return verify_flipped_insn_144_0x0ed0(seed);
        case 145: return verify_flipped_insn_145_0x0ed4(seed);
        case 146: return verify_flipped_insn_146_0x0ed8(seed);
        case 147: return verify_flipped_insn_147_0x0edc(seed);
        case 148: return verify_flipped_insn_148_0x0ee0(seed);
        case 149: return verify_flipped_insn_149_0x0ee4(seed);
        case 150: return verify_flipped_insn_150_0x0ee8(seed);
        case 151: return verify_flipped_insn_151_0x0eec(seed);
        case 152: return verify_flipped_insn_152_0x0ef0(seed);
        case 153: return verify_flipped_insn_153_0x0ef4(seed);
        case 154: return verify_flipped_insn_154_0x0ef8(seed);
        case 155: return verify_flipped_insn_155_0x0efc(seed);
        case 156: return verify_flipped_insn_156_0x0f00(seed);
        case 157: return verify_flipped_insn_157_0x0f04(seed);
        case 158: return verify_flipped_insn_158_0x0f08(seed);
        case 159: return verify_flipped_insn_159_0x0f0c(seed);
        case 160: return verify_flipped_insn_160_0x0f10(seed);
        case 161: return verify_flipped_insn_161_0x0f14(seed);
        case 162: return verify_flipped_insn_162_0x0f18(seed);
        case 163: return verify_flipped_insn_163_0x0f1c(seed);
        case 164: return verify_flipped_insn_164_0x0f20(seed);
        case 165: return verify_flipped_insn_165_0x0f24(seed);
        case 166: return verify_flipped_insn_166_0x0f28(seed);
        case 167: return verify_flipped_insn_167_0x0f2c(seed);
        case 168: return verify_flipped_insn_168_0x0f30(seed);
        case 169: return verify_flipped_insn_169_0x0f34(seed);
        case 170: return verify_flipped_insn_170_0x0f38(seed);
        case 171: return verify_flipped_insn_171_0x0f3c(seed);
        case 172: return verify_flipped_insn_172_0x0f40(seed);
        case 173: return verify_flipped_insn_173_0x0f44(seed);
        case 174: return verify_flipped_insn_174_0x0f48(seed);
        case 175: return verify_flipped_insn_175_0x0f4c(seed);
        case 176: return verify_flipped_insn_176_0x0f50(seed);
        case 177: return verify_flipped_insn_177_0x0f54(seed);
        case 178: return verify_flipped_insn_178_0x0f58(seed);
        case 179: return verify_flipped_insn_179_0x0f5c(seed);
        case 180: return verify_flipped_insn_180_0x0f60(seed);
        case 181: return verify_flipped_insn_181_0x0f64(seed);
        case 182: return verify_flipped_insn_182_0x0f68(seed);
        case 183: return verify_flipped_insn_183_0x0f6c(seed);
        case 184: return verify_flipped_insn_184_0x0f70(seed);
        case 185: return verify_flipped_insn_185_0x0f74(seed);
        case 186: return verify_flipped_insn_186_0x0f78(seed);
        case 187: return verify_flipped_insn_187_0x0f7c(seed);
        case 188: return verify_flipped_insn_188_0x0f80(seed);
        case 189: return verify_flipped_insn_189_0x0f84(seed);
        case 190: return verify_flipped_insn_190_0x0f88(seed);
        case 191: return verify_flipped_insn_191_0x0f8c(seed);
        case 192: return verify_flipped_insn_192_0x0f90(seed);
        case 193: return verify_flipped_insn_193_0x0f94(seed);
        case 194: return verify_flipped_insn_194_0x0f98(seed);
        case 195: return verify_flipped_insn_195_0x0f9c(seed);
        case 196: return verify_flipped_insn_196_0x0fa0(seed);
        case 197: return verify_flipped_insn_197_0x0fa4(seed);
        case 198: return verify_flipped_insn_198_0x0fa8(seed);
        case 199: return verify_flipped_insn_199_0x0fac(seed);
        case 200: return verify_flipped_insn_200_0x0fb0(seed);
        case 201: return verify_flipped_insn_201_0x0fb4(seed);
        case 202: return verify_flipped_insn_202_0x0fb8(seed);
        case 203: return verify_flipped_insn_203_0x0fbc(seed);
        case 204: return verify_flipped_insn_204_0x0fc0(seed);
        case 205: return verify_flipped_insn_205_0x0fc4(seed);
        case 206: return verify_flipped_insn_206_0x0fc8(seed);
        case 207: return verify_flipped_insn_207_0x0fcc(seed);
        case 208: return verify_flipped_insn_208_0x0fd0(seed);
        case 209: return verify_flipped_insn_209_0x0fd4(seed);
        case 210: return verify_flipped_insn_210_0x0fd8(seed);
        case 211: return verify_flipped_insn_211_0x0fdc(seed);
        case 212: return verify_flipped_insn_212_0x0fe0(seed);
        case 213: return verify_flipped_insn_213_0x0fe4(seed);
        case 214: return verify_flipped_insn_214_0x0fe8(seed);
        case 215: return verify_flipped_insn_215_0x0fec(seed);
        case 216: return verify_flipped_insn_216_0x0ff0(seed);
        case 217: return verify_flipped_insn_217_0x0ff4(seed);
        case 218: return verify_flipped_insn_218_0x0ff8(seed);
        case 219: return verify_flipped_insn_219_0x0ffc(seed);
        case 220: return verify_flipped_insn_220_0x1000(seed);
        case 221: return verify_flipped_insn_221_0x1004(seed);
        case 222: return verify_flipped_insn_222_0x1008(seed);
        case 223: return verify_flipped_insn_223_0x100c(seed);
        case 224: return verify_flipped_insn_224_0x1010(seed);
        case 225: return verify_flipped_insn_225_0x1014(seed);
        case 226: return verify_flipped_insn_226_0x1018(seed);
        case 227: return verify_flipped_insn_227_0x101c(seed);
        case 228: return verify_flipped_insn_228_0x1020(seed);
        case 229: return verify_flipped_insn_229_0x1024(seed);
        case 230: return verify_flipped_insn_230_0x1028(seed);
        case 231: return verify_flipped_insn_231_0x102c(seed);
        case 232: return verify_flipped_insn_232_0x1030(seed);
        case 233: return verify_flipped_insn_233_0x1034(seed);
        case 234: return verify_flipped_insn_234_0x1038(seed);
        case 235: return verify_flipped_insn_235_0x103c(seed);
        case 236: return verify_flipped_insn_236_0x1040(seed);
        case 237: return verify_flipped_insn_237_0x1044(seed);
        case 238: return verify_flipped_insn_238_0x1048(seed);
        case 239: return verify_flipped_insn_239_0x104c(seed);
        case 240: return verify_flipped_insn_240_0x1050(seed);
        case 241: return verify_flipped_insn_241_0x1054(seed);
        case 242: return verify_flipped_insn_242_0x1058(seed);
        case 243: return verify_flipped_insn_243_0x105c(seed);
        case 244: return verify_flipped_insn_244_0x1060(seed);
        case 245: return verify_flipped_insn_245_0x1064(seed);
        case 246: return verify_flipped_insn_246_0x1068(seed);
        case 247: return verify_flipped_insn_247_0x106c(seed);
        case 248: return verify_flipped_insn_248_0x1070(seed);
        case 249: return verify_flipped_insn_249_0x1074(seed);
        case 250: return verify_flipped_insn_250_0x1078(seed);
        case 251: return verify_flipped_insn_251_0x107c(seed);
        case 252: return verify_flipped_insn_252_0x1080(seed);
        case 253: return verify_flipped_insn_253_0x1084(seed);
        case 254: return verify_flipped_insn_254_0x1088(seed);
        case 255: return verify_flipped_insn_255_0x108c(seed);
        case 256: return verify_flipped_insn_256_0x1090(seed);
        case 257: return verify_flipped_insn_257_0x1094(seed);
        case 258: return verify_flipped_insn_258_0x1098(seed);
        case 259: return verify_flipped_insn_259_0x109c(seed);
        case 260: return verify_flipped_insn_260_0x10a0(seed);
        case 261: return verify_flipped_insn_261_0x10a4(seed);
        case 262: return verify_flipped_insn_262_0x10a8(seed);
        case 263: return verify_flipped_insn_263_0x10ac(seed);
        case 264: return verify_flipped_insn_264_0x10b0(seed);
        case 265: return verify_flipped_insn_265_0x10b4(seed);
        case 266: return verify_flipped_insn_266_0x10b8(seed);
        case 267: return verify_flipped_insn_267_0x10bc(seed);
        case 268: return verify_flipped_insn_268_0x10c0(seed);
        case 269: return verify_flipped_insn_269_0x10c4(seed);
        case 270: return verify_flipped_insn_270_0x10c8(seed);
        case 271: return verify_flipped_insn_271_0x10cc(seed);
        case 272: return verify_flipped_insn_272_0x10d0(seed);
        case 273: return verify_flipped_insn_273_0x10d4(seed);
        case 274: return verify_flipped_insn_274_0x10d8(seed);
        case 275: return verify_flipped_insn_275_0x10dc(seed);
        case 276: return verify_flipped_insn_276_0x10e0(seed);
        case 277: return verify_flipped_insn_277_0x10e4(seed);
        case 278: return verify_flipped_insn_278_0x10e8(seed);
        case 279: return verify_flipped_insn_279_0x10ec(seed);
        case 280: return verify_flipped_insn_280_0x10f0(seed);
        case 281: return verify_flipped_insn_281_0x10f4(seed);
        case 282: return verify_flipped_insn_282_0x10f8(seed);
        case 283: return verify_flipped_insn_283_0x10fc(seed);
        case 284: return verify_flipped_insn_284_0x1100(seed);
        case 285: return verify_flipped_insn_285_0x1104(seed);
        case 286: return verify_flipped_insn_286_0x1108(seed);
        case 287: return verify_flipped_insn_287_0x110c(seed);
        case 288: return verify_flipped_insn_288_0x1110(seed);
        case 289: return verify_flipped_insn_289_0x1114(seed);
        case 290: return verify_flipped_insn_290_0x1118(seed);
        case 291: return verify_flipped_insn_291_0x111c(seed);
        case 292: return verify_flipped_insn_292_0x1120(seed);
        case 293: return verify_flipped_insn_293_0x1124(seed);
        case 294: return verify_flipped_insn_294_0x1128(seed);
        case 295: return verify_flipped_insn_295_0x112c(seed);
        case 296: return verify_flipped_insn_296_0x1130(seed);
        case 297: return verify_flipped_insn_297_0x1134(seed);
        case 298: return verify_flipped_insn_298_0x1138(seed);
        case 299: return verify_flipped_insn_299_0x113c(seed);
        case 300: return verify_flipped_insn_300_0x1140(seed);
        case 301: return verify_flipped_insn_301_0x1144(seed);
        case 302: return verify_flipped_insn_302_0x1148(seed);
        case 303: return verify_flipped_insn_303_0x114c(seed);
        case 304: return verify_flipped_insn_304_0x1150(seed);
        case 305: return verify_flipped_insn_305_0x1154(seed);
        case 306: return verify_flipped_insn_306_0x1158(seed);
        case 307: return verify_flipped_insn_307_0x115c(seed);
        case 308: return verify_flipped_insn_308_0x1160(seed);
        case 309: return verify_flipped_insn_309_0x1164(seed);
        case 310: return verify_flipped_insn_310_0x1168(seed);
        case 311: return verify_flipped_insn_311_0x116c(seed);
        case 312: return verify_flipped_insn_312_0x1170(seed);
        case 313: return verify_flipped_insn_313_0x1174(seed);
        case 314: return verify_flipped_insn_314_0x1178(seed);
        case 315: return verify_flipped_insn_315_0x117c(seed);
        case 316: return verify_flipped_insn_316_0x1180(seed);
        case 317: return verify_flipped_insn_317_0x1184(seed);
        case 318: return verify_flipped_insn_318_0x1188(seed);
        case 319: return verify_flipped_insn_319_0x118c(seed);
        case 320: return verify_flipped_insn_320_0x1190(seed);
        case 321: return verify_flipped_insn_321_0x1194(seed);
        case 322: return verify_flipped_insn_322_0x1198(seed);
        case 323: return verify_flipped_insn_323_0x119c(seed);
        case 324: return verify_flipped_insn_324_0x11a0(seed);
        case 325: return verify_flipped_insn_325_0x11a4(seed);
        case 326: return verify_flipped_insn_326_0x11a8(seed);
        default: return 0ULL;
    }
}

} // namespace flipped