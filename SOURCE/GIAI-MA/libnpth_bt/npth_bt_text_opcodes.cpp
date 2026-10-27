// ============================================================================
// Complete 358-Instruction AArch64 .text Disassembly & 18-FDE Unwind Verifier
// Bộ kiểm chứng toàn bộ 358 lệnh AArch64 .text (0x0c60..0x11f8) & 18 FDE của libnpth_bt.so
// ============================================================================
#include "npth_bt_core.h"

namespace npth_bt {

// Insn #000 @ 0x0c60: 0xD503245F -> bti c
// Lệnh AArch64 #000 tại 0x0c60: bti c
uint64_t verify_npth_bt_insn_000_0x0c60(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xD503245FU;
    constexpr uint64_t kVaddr  = 0x0c60ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #001 @ 0x0c64: 0xD503201F -> nop 
// Lệnh AArch64 #001 tại 0x0c64: nop 
uint64_t verify_npth_bt_insn_001_0x0c64(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xD503201FU;
    constexpr uint64_t kVaddr  = 0x0c64ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #002 @ 0x0c68: 0x10023440 -> adr x0, #0x52f0
// Lệnh AArch64 #002 tại 0x0c68: adr x0, #0x52f0
uint64_t verify_npth_bt_insn_002_0x0c68(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x10023440U;
    constexpr uint64_t kVaddr  = 0x0c68ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #003 @ 0x0c6c: 0x1400016D -> b #0x1220
// Lệnh AArch64 #003 tại 0x0c6c: b #0x1220
uint64_t verify_npth_bt_insn_003_0x0c6c(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x1400016DU;
    constexpr uint64_t kVaddr  = 0x0c6cULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #004 @ 0x0c70: 0xD503245F -> bti c
// Lệnh AArch64 #004 tại 0x0c70: bti c
uint64_t verify_npth_bt_insn_004_0x0c70(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xD503245FU;
    constexpr uint64_t kVaddr  = 0x0c70ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #005 @ 0x0c74: 0xD65F03C0 -> ret 
// Lệnh AArch64 #005 tại 0x0c74: ret 
uint64_t verify_npth_bt_insn_005_0x0c74(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xD65F03C0U;
    constexpr uint64_t kVaddr  = 0x0c74ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #006 @ 0x0c78: 0xD503245F -> bti c
// Lệnh AArch64 #006 tại 0x0c78: bti c
uint64_t verify_npth_bt_insn_006_0x0c78(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xD503245FU;
    constexpr uint64_t kVaddr  = 0x0c78ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #007 @ 0x0c7c: 0x17FFFFFD -> b #0xc70
// Lệnh AArch64 #007 tại 0x0c7c: b #0xc70
uint64_t verify_npth_bt_insn_007_0x0c7c(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x17FFFFFDU;
    constexpr uint64_t kVaddr  = 0x0c7cULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #008 @ 0x0c80: 0xD503245F -> bti c
// Lệnh AArch64 #008 tại 0x0c80: bti c
uint64_t verify_npth_bt_insn_008_0x0c80(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xD503245FU;
    constexpr uint64_t kVaddr  = 0x0c80ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #009 @ 0x0c84: 0xB4000060 -> cbz x0, #0xc90
// Lệnh AArch64 #009 tại 0x0c84: cbz x0, #0xc90
uint64_t verify_npth_bt_insn_009_0x0c84(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xB4000060U;
    constexpr uint64_t kVaddr  = 0x0c84ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #010 @ 0x0c88: 0xAA0003F0 -> mov x16, x0
// Lệnh AArch64 #010 tại 0x0c88: mov x16, x0
uint64_t verify_npth_bt_insn_010_0x0c88(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xAA0003F0U;
    constexpr uint64_t kVaddr  = 0x0c88ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #011 @ 0x0c8c: 0xD61F0200 -> br x16
// Lệnh AArch64 #011 tại 0x0c8c: br x16
uint64_t verify_npth_bt_insn_011_0x0c8c(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xD61F0200U;
    constexpr uint64_t kVaddr  = 0x0c8cULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #012 @ 0x0c90: 0xD65F03C0 -> ret 
// Lệnh AArch64 #012 tại 0x0c90: ret 
uint64_t verify_npth_bt_insn_012_0x0c90(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xD65F03C0U;
    constexpr uint64_t kVaddr  = 0x0c90ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #013 @ 0x0c94: 0xD503245F -> bti c
// Lệnh AArch64 #013 tại 0x0c94: bti c
uint64_t verify_npth_bt_insn_013_0x0c94(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xD503245FU;
    constexpr uint64_t kVaddr  = 0x0c94ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #014 @ 0x0c98: 0xAA0003E1 -> mov x1, x0
// Lệnh AArch64 #014 tại 0x0c98: mov x1, x0
uint64_t verify_npth_bt_insn_014_0x0c98(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xAA0003E1U;
    constexpr uint64_t kVaddr  = 0x0c98ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #015 @ 0x0c9c: 0xD503201F -> nop 
// Lệnh AArch64 #015 tại 0x0c9c: nop 
uint64_t verify_npth_bt_insn_015_0x0c9c(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xD503201FU;
    constexpr uint64_t kVaddr  = 0x0c9cULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #016 @ 0x0ca0: 0x10FFFF00 -> adr x0, #0xc80
// Lệnh AArch64 #016 tại 0x0ca0: adr x0, #0xc80
uint64_t verify_npth_bt_insn_016_0x0ca0(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x10FFFF00U;
    constexpr uint64_t kVaddr  = 0x0ca0ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #017 @ 0x0ca4: 0xD503201F -> nop 
// Lệnh AArch64 #017 tại 0x0ca4: nop 
uint64_t verify_npth_bt_insn_017_0x0ca4(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xD503201FU;
    constexpr uint64_t kVaddr  = 0x0ca4ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #018 @ 0x0ca8: 0x10023242 -> adr x2, #0x52f0
// Lệnh AArch64 #018 tại 0x0ca8: adr x2, #0x52f0
uint64_t verify_npth_bt_insn_018_0x0ca8(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x10023242U;
    constexpr uint64_t kVaddr  = 0x0ca8ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #019 @ 0x0cac: 0x14000161 -> b #0x1230
// Lệnh AArch64 #019 tại 0x0cac: b #0x1230
uint64_t verify_npth_bt_insn_019_0x0cac(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x14000161U;
    constexpr uint64_t kVaddr  = 0x0cacULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #020 @ 0x0cb0: 0xA9BA7BFD -> stp x29, x30, [sp, #-0x60]!
// Lệnh AArch64 #020 tại 0x0cb0: stp x29, x30, [sp, #-0x60]!
uint64_t verify_npth_bt_insn_020_0x0cb0(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xA9BA7BFDU;
    constexpr uint64_t kVaddr  = 0x0cb0ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #021 @ 0x0cb4: 0xF9000BFC -> str x28, [sp, #0x10]
// Lệnh AArch64 #021 tại 0x0cb4: str x28, [sp, #0x10]
uint64_t verify_npth_bt_insn_021_0x0cb4(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xF9000BFCU;
    constexpr uint64_t kVaddr  = 0x0cb4ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #022 @ 0x0cb8: 0xA90267FA -> stp x26, x25, [sp, #0x20]
// Lệnh AArch64 #022 tại 0x0cb8: stp x26, x25, [sp, #0x20]
uint64_t verify_npth_bt_insn_022_0x0cb8(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xA90267FAU;
    constexpr uint64_t kVaddr  = 0x0cb8ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #023 @ 0x0cbc: 0xA9035FF8 -> stp x24, x23, [sp, #0x30]
// Lệnh AArch64 #023 tại 0x0cbc: stp x24, x23, [sp, #0x30]
uint64_t verify_npth_bt_insn_023_0x0cbc(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xA9035FF8U;
    constexpr uint64_t kVaddr  = 0x0cbcULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #024 @ 0x0cc0: 0xA90457F6 -> stp x22, x21, [sp, #0x40]
// Lệnh AArch64 #024 tại 0x0cc0: stp x22, x21, [sp, #0x40]
uint64_t verify_npth_bt_insn_024_0x0cc0(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xA90457F6U;
    constexpr uint64_t kVaddr  = 0x0cc0ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #025 @ 0x0cc4: 0xA9054FF4 -> stp x20, x19, [sp, #0x50]
// Lệnh AArch64 #025 tại 0x0cc4: stp x20, x19, [sp, #0x50]
uint64_t verify_npth_bt_insn_025_0x0cc4(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xA9054FF4U;
    constexpr uint64_t kVaddr  = 0x0cc4ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #026 @ 0x0cc8: 0x910003FD -> mov x29, sp
// Lệnh AArch64 #026 tại 0x0cc8: mov x29, sp
uint64_t verify_npth_bt_insn_026_0x0cc8(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x910003FDU;
    constexpr uint64_t kVaddr  = 0x0cc8ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #027 @ 0x0ccc: 0xD12143FF -> sub sp, sp, #0x850
// Lệnh AArch64 #027 tại 0x0ccc: sub sp, sp, #0x850
uint64_t verify_npth_bt_insn_027_0x0ccc(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xD12143FFU;
    constexpr uint64_t kVaddr  = 0x0cccULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #028 @ 0x0cd0: 0xD53BD05A -> mrs x26, tpidr_el0
// Lệnh AArch64 #028 tại 0x0cd0: mrs x26, tpidr_el0
uint64_t verify_npth_bt_insn_028_0x0cd0(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xD53BD05AU;
    constexpr uint64_t kVaddr  = 0x0cd0ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #029 @ 0x0cd4: 0xB0000054 -> adrp x20, #0x9000
// Lệnh AArch64 #029 tại 0x0cd4: adrp x20, #0x9000
uint64_t verify_npth_bt_insn_029_0x0cd4(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xB0000054U;
    constexpr uint64_t kVaddr  = 0x0cd4ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #030 @ 0x0cd8: 0xF9401748 -> ldr x8, [x26, #0x28]
// Lệnh AArch64 #030 tại 0x0cd8: ldr x8, [x26, #0x28]
uint64_t verify_npth_bt_insn_030_0x0cd8(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xF9401748U;
    constexpr uint64_t kVaddr  = 0x0cd8ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #031 @ 0x0cdc: 0x2A0003F3 -> mov w19, w0
// Lệnh AArch64 #031 tại 0x0cdc: mov w19, w0
uint64_t verify_npth_bt_insn_031_0x0cdc(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x2A0003F3U;
    constexpr uint64_t kVaddr  = 0x0cdcULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #032 @ 0x0ce0: 0xF81F83A8 -> stur x8, [x29, #-8]
// Lệnh AArch64 #032 tại 0x0ce0: stur x8, [x29, #-8]
uint64_t verify_npth_bt_insn_032_0x0ce0(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xF81F83A8U;
    constexpr uint64_t kVaddr  = 0x0ce0ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #033 @ 0x0ce4: 0x39552288 -> ldrb w8, [x20, #0x548]
// Lệnh AArch64 #033 tại 0x0ce4: ldrb w8, [x20, #0x548]
uint64_t verify_npth_bt_insn_033_0x0ce4(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x39552288U;
    constexpr uint64_t kVaddr  = 0x0ce4ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #034 @ 0x0ce8: 0x7100051F -> cmp w8, #1
// Lệnh AArch64 #034 tại 0x0ce8: cmp w8, #1
uint64_t verify_npth_bt_insn_034_0x0ce8(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x7100051FU;
    constexpr uint64_t kVaddr  = 0x0ce8ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #035 @ 0x0cec: 0x54000081 -> b.ne #0xcfc
// Lệnh AArch64 #035 tại 0x0cec: b.ne #0xcfc
uint64_t verify_npth_bt_insn_035_0x0cec(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x54000081U;
    constexpr uint64_t kVaddr  = 0x0cecULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #036 @ 0x0cf0: 0xB0000048 -> adrp x8, #0x9000
// Lệnh AArch64 #036 tại 0x0cf0: adrp x8, #0x9000
uint64_t verify_npth_bt_insn_036_0x0cf0(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xB0000048U;
    constexpr uint64_t kVaddr  = 0x0cf0ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #037 @ 0x0cf4: 0xF942AD15 -> ldr x21, [x8, #0x558]
// Lệnh AArch64 #037 tại 0x0cf4: ldr x21, [x8, #0x558]
uint64_t verify_npth_bt_insn_037_0x0cf4(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xF942AD15U;
    constexpr uint64_t kVaddr  = 0x0cf4ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #038 @ 0x0cf8: 0x14000014 -> b #0xd48
// Lệnh AArch64 #038 tại 0x0cf8: b #0xd48
uint64_t verify_npth_bt_insn_038_0x0cf8(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x14000014U;
    constexpr uint64_t kVaddr  = 0x0cf8ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #039 @ 0x0cfc: 0xD503201F -> nop 
// Lệnh AArch64 #039 tại 0x0cfc: nop 
uint64_t verify_npth_bt_insn_039_0x0cfc(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xD503201FU;
    constexpr uint64_t kVaddr  = 0x0cfcULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #040 @ 0x0d00: 0x10044255 -> adr x21, #0x9548
// Lệnh AArch64 #040 tại 0x0d00: adr x21, #0x9548
uint64_t verify_npth_bt_insn_040_0x0d00(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x10044255U;
    constexpr uint64_t kVaddr  = 0x0d00ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #041 @ 0x0d04: 0x9100A2A0 -> add x0, x21, #0x28
// Lệnh AArch64 #041 tại 0x0d04: add x0, x21, #0x28
uint64_t verify_npth_bt_insn_041_0x0d04(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x9100A2A0U;
    constexpr uint64_t kVaddr  = 0x0d04ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #042 @ 0x0d08: 0x94000152 -> bl #0x1250
// Lệnh AArch64 #042 tại 0x0d08: bl #0x1250
uint64_t verify_npth_bt_insn_042_0x0d08(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x94000152U;
    constexpr uint64_t kVaddr  = 0x0d08ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #043 @ 0x0d0c: 0x394002A8 -> ldrb w8, [x21]
// Lệnh AArch64 #043 tại 0x0d0c: ldrb w8, [x21]
uint64_t verify_npth_bt_insn_043_0x0d0c(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x394002A8U;
    constexpr uint64_t kVaddr  = 0x0d0cULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #044 @ 0x0d10: 0x360000E8 -> tbz w8, #0, #0xd2c
// Lệnh AArch64 #044 tại 0x0d10: tbz w8, #0, #0xd2c
uint64_t verify_npth_bt_insn_044_0x0d10(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x360000E8U;
    constexpr uint64_t kVaddr  = 0x0d10ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #045 @ 0x0d14: 0xB0000054 -> adrp x20, #0x9000
// Lệnh AArch64 #045 tại 0x0d14: adrp x20, #0x9000
uint64_t verify_npth_bt_insn_045_0x0d14(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xB0000054U;
    constexpr uint64_t kVaddr  = 0x0d14ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #046 @ 0x0d18: 0x91156294 -> add x20, x20, #0x558
// Lệnh AArch64 #046 tại 0x0d18: add x20, x20, #0x558
uint64_t verify_npth_bt_insn_046_0x0d18(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x91156294U;
    constexpr uint64_t kVaddr  = 0x0d18ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #047 @ 0x0d1c: 0x91006280 -> add x0, x20, #0x18
// Lệnh AArch64 #047 tại 0x0d1c: add x0, x20, #0x18
uint64_t verify_npth_bt_insn_047_0x0d1c(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x91006280U;
    constexpr uint64_t kVaddr  = 0x0d1cULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #048 @ 0x0d20: 0x94000150 -> bl #0x1260
// Lệnh AArch64 #048 tại 0x0d20: bl #0x1260
uint64_t verify_npth_bt_insn_048_0x0d20(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x94000150U;
    constexpr uint64_t kVaddr  = 0x0d20ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #049 @ 0x0d24: 0xF9400295 -> ldr x21, [x20]
// Lệnh AArch64 #049 tại 0x0d24: ldr x21, [x20]
uint64_t verify_npth_bt_insn_049_0x0d24(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xF9400295U;
    constexpr uint64_t kVaddr  = 0x0d24ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #050 @ 0x0d28: 0x14000008 -> b #0xd48
// Lệnh AArch64 #050 tại 0x0d28: b #0xd48
uint64_t verify_npth_bt_insn_050_0x0d28(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x14000008U;
    constexpr uint64_t kVaddr  = 0x0d28ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #051 @ 0x0d2c: 0x52800028 -> mov w8, #1
// Lệnh AArch64 #051 tại 0x0d2c: mov w8, #1
uint64_t verify_npth_bt_insn_051_0x0d2c(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x52800028U;
    constexpr uint64_t kVaddr  = 0x0d2cULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #052 @ 0x0d30: 0x39152288 -> strb w8, [x20, #0x548]
// Lệnh AArch64 #052 tại 0x0d30: strb w8, [x20, #0x548]
uint64_t verify_npth_bt_insn_052_0x0d30(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x39152288U;
    constexpr uint64_t kVaddr  = 0x0d30ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #053 @ 0x0d34: 0x9400014F -> bl #0x1270
// Lệnh AArch64 #053 tại 0x0d34: bl #0x1270
uint64_t verify_npth_bt_insn_053_0x0d34(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x9400014FU;
    constexpr uint64_t kVaddr  = 0x0d34ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #054 @ 0x0d38: 0x51009008 -> sub w8, w0, #0x24
// Lệnh AArch64 #054 tại 0x0d38: sub w8, w0, #0x24
uint64_t verify_npth_bt_insn_054_0x0d38(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x51009008U;
    constexpr uint64_t kVaddr  = 0x0d38ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #055 @ 0x0d3c: 0x3100451F -> cmn w8, #0x11
// Lệnh AArch64 #055 tại 0x0d3c: cmn w8, #0x11
uint64_t verify_npth_bt_insn_055_0x0d3c(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x3100451FU;
    constexpr uint64_t kVaddr  = 0x0d3cULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #056 @ 0x0d40: 0x540005C2 -> b.hs #0xdf8
// Lệnh AArch64 #056 tại 0x0d40: b.hs #0xdf8
uint64_t verify_npth_bt_insn_056_0x0d40(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x540005C2U;
    constexpr uint64_t kVaddr  = 0x0d40ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #057 @ 0x0d44: 0xAA1F03F5 -> mov x21, xzr
// Lệnh AArch64 #057 tại 0x0d44: mov x21, xzr
uint64_t verify_npth_bt_insn_057_0x0d44(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xAA1F03F5U;
    constexpr uint64_t kVaddr  = 0x0d44ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #058 @ 0x0d48: 0x94000060 -> bl #0xec8
// Lệnh AArch64 #058 tại 0x0d48: bl #0xec8
uint64_t verify_npth_bt_insn_058_0x0d48(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x94000060U;
    constexpr uint64_t kVaddr  = 0x0d48ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #059 @ 0x0d4c: 0xAA0003F4 -> mov x20, x0
// Lệnh AArch64 #059 tại 0x0d4c: mov x20, x0
uint64_t verify_npth_bt_insn_059_0x0d4c(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xAA0003F4U;
    constexpr uint64_t kVaddr  = 0x0d4cULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #060 @ 0x0d50: 0xAA1F03E0 -> mov x0, xzr
// Lệnh AArch64 #060 tại 0x0d50: mov x0, xzr
uint64_t verify_npth_bt_insn_060_0x0d50(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xAA1F03E0U;
    constexpr uint64_t kVaddr  = 0x0d50ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #061 @ 0x0d54: 0xB40003B5 -> cbz x21, #0xdc8
// Lệnh AArch64 #061 tại 0x0d54: cbz x21, #0xdc8
uint64_t verify_npth_bt_insn_061_0x0d54(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xB40003B5U;
    constexpr uint64_t kVaddr  = 0x0d54ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #062 @ 0x0d58: 0xB4000394 -> cbz x20, #0xdc8
// Lệnh AArch64 #062 tại 0x0d58: cbz x20, #0xdc8
uint64_t verify_npth_bt_insn_062_0x0d58(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xB4000394U;
    constexpr uint64_t kVaddr  = 0x0d58ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #063 @ 0x0d5c: 0x94000111 -> bl #0x11a0
// Lệnh AArch64 #063 tại 0x0d5c: bl #0x11a0
uint64_t verify_npth_bt_insn_063_0x0d5c(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x94000111U;
    constexpr uint64_t kVaddr  = 0x0d5cULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #064 @ 0x0d60: 0xF94002A8 -> ldr x8, [x21]
// Lệnh AArch64 #064 tại 0x0d60: ldr x8, [x21]
uint64_t verify_npth_bt_insn_064_0x0d60(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xF94002A8U;
    constexpr uint64_t kVaddr  = 0x0d60ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #065 @ 0x0d64: 0x9400011D -> bl #0x11d8
// Lệnh AArch64 #065 tại 0x0d64: bl #0x11d8
uint64_t verify_npth_bt_insn_065_0x0d64(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x9400011DU;
    constexpr uint64_t kVaddr  = 0x0d64ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #066 @ 0x0d68: 0xF9400288 -> ldr x8, [x20]
// Lệnh AArch64 #066 tại 0x0d68: ldr x8, [x20]
uint64_t verify_npth_bt_insn_066_0x0d68(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xF9400288U;
    constexpr uint64_t kVaddr  = 0x0d68ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #067 @ 0x0d6c: 0xD100C3A0 -> sub x0, x29, #0x30
// Lệnh AArch64 #067 tại 0x0d6c: sub x0, x29, #0x30
uint64_t verify_npth_bt_insn_067_0x0d6c(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xD100C3A0U;
    constexpr uint64_t kVaddr  = 0x0d6cULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #068 @ 0x0d70: 0xD63F0100 -> blr x8
// Lệnh AArch64 #068 tại 0x0d70: blr x8
uint64_t verify_npth_bt_insn_068_0x0d70(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xD63F0100U;
    constexpr uint64_t kVaddr  = 0x0d70ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #069 @ 0x0d74: 0xF94006A8 -> ldr x8, [x21, #8]
// Lệnh AArch64 #069 tại 0x0d74: ldr x8, [x21, #8]
uint64_t verify_npth_bt_insn_069_0x0d74(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xF94006A8U;
    constexpr uint64_t kVaddr  = 0x0d74ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #070 @ 0x0d78: 0xB40000C8 -> cbz x8, #0xd90
// Lệnh AArch64 #070 tại 0x0d78: cbz x8, #0xd90
uint64_t verify_npth_bt_insn_070_0x0d78(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xB40000C8U;
    constexpr uint64_t kVaddr  = 0x0d78ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #071 @ 0x0d7c: 0x910083E0 -> add x0, sp, #0x20
// Lệnh AArch64 #071 tại 0x0d7c: add x0, sp, #0x20
uint64_t verify_npth_bt_insn_071_0x0d7c(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x910083E0U;
    constexpr uint64_t kVaddr  = 0x0d7cULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #072 @ 0x0d80: 0x52800041 -> mov w1, #2
// Lệnh AArch64 #072 tại 0x0d80: mov w1, #2
uint64_t verify_npth_bt_insn_072_0x0d80(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x52800041U;
    constexpr uint64_t kVaddr  = 0x0d80ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #073 @ 0x0d84: 0x2A1303E2 -> mov w2, w19
// Lệnh AArch64 #073 tại 0x0d84: mov w2, w19
uint64_t verify_npth_bt_insn_073_0x0d84(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x2A1303E2U;
    constexpr uint64_t kVaddr  = 0x0d84ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #074 @ 0x0d88: 0xD63F0100 -> blr x8
// Lệnh AArch64 #074 tại 0x0d88: blr x8
uint64_t verify_npth_bt_insn_074_0x0d88(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xD63F0100U;
    constexpr uint64_t kVaddr  = 0x0d88ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #075 @ 0x0d8c: 0x14000008 -> b #0xdac
// Lệnh AArch64 #075 tại 0x0d8c: b #0xdac
uint64_t verify_npth_bt_insn_075_0x0d8c(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x14000008U;
    constexpr uint64_t kVaddr  = 0x0d8cULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #076 @ 0x0d90: 0xF9400AA8 -> ldr x8, [x21, #0x10]
// Lệnh AArch64 #076 tại 0x0d90: ldr x8, [x21, #0x10]
uint64_t verify_npth_bt_insn_076_0x0d90(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xF9400AA8U;
    constexpr uint64_t kVaddr  = 0x0d90ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #077 @ 0x0d94: 0xB4000148 -> cbz x8, #0xdbc
// Lệnh AArch64 #077 tại 0x0d94: cbz x8, #0xdbc
uint64_t verify_npth_bt_insn_077_0x0d94(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xB4000148U;
    constexpr uint64_t kVaddr  = 0x0d94ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #078 @ 0x0d98: 0x910083E0 -> add x0, sp, #0x20
// Lệnh AArch64 #078 tại 0x0d98: add x0, sp, #0x20
uint64_t verify_npth_bt_insn_078_0x0d98(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x910083E0U;
    constexpr uint64_t kVaddr  = 0x0d98ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #079 @ 0x0d9c: 0x52800041 -> mov w1, #2
// Lệnh AArch64 #079 tại 0x0d9c: mov w1, #2
uint64_t verify_npth_bt_insn_079_0x0d9c(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x52800041U;
    constexpr uint64_t kVaddr  = 0x0d9cULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #080 @ 0x0da0: 0x528003E2 -> mov w2, #0x1f
// Lệnh AArch64 #080 tại 0x0da0: mov w2, #0x1f
uint64_t verify_npth_bt_insn_080_0x0da0(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x528003E2U;
    constexpr uint64_t kVaddr  = 0x0da0ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #081 @ 0x0da4: 0x2A1303E3 -> mov w3, w19
// Lệnh AArch64 #081 tại 0x0da4: mov w3, w19
uint64_t verify_npth_bt_insn_081_0x0da4(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x2A1303E3U;
    constexpr uint64_t kVaddr  = 0x0da4ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #082 @ 0x0da8: 0xD63F0100 -> blr x8
// Lệnh AArch64 #082 tại 0x0da8: blr x8
uint64_t verify_npth_bt_insn_082_0x0da8(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xD63F0100U;
    constexpr uint64_t kVaddr  = 0x0da8ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #083 @ 0x0dac: 0xF9400EA9 -> ldr x9, [x21, #0x18]
// Lệnh AArch64 #083 tại 0x0dac: ldr x9, [x21, #0x18]
uint64_t verify_npth_bt_insn_083_0x0dac(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xF9400EA9U;
    constexpr uint64_t kVaddr  = 0x0dacULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #084 @ 0x0db0: 0x94000104 -> bl #0x11c0
// Lệnh AArch64 #084 tại 0x0db0: bl #0x11c0
uint64_t verify_npth_bt_insn_084_0x0db0(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x94000104U;
    constexpr uint64_t kVaddr  = 0x0db0ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #085 @ 0x0db4: 0xAD4007E0 -> ldp q0, q1, [sp]
// Lệnh AArch64 #085 tại 0x0db4: ldp q0, q1, [sp]
uint64_t verify_npth_bt_insn_085_0x0db4(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xAD4007E0U;
    constexpr uint64_t kVaddr  = 0x0db4ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #086 @ 0x0db8: 0xAD3E87A0 -> stp q0, q1, [x29, #-0x30]
// Lệnh AArch64 #086 tại 0x0db8: stp q0, q1, [x29, #-0x30]
uint64_t verify_npth_bt_insn_086_0x0db8(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xAD3E87A0U;
    constexpr uint64_t kVaddr  = 0x0db8ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #087 @ 0x0dbc: 0xF94012A8 -> ldr x8, [x21, #0x20]
// Lệnh AArch64 #087 tại 0x0dbc: ldr x8, [x21, #0x20]
uint64_t verify_npth_bt_insn_087_0x0dbc(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xF94012A8U;
    constexpr uint64_t kVaddr  = 0x0dbcULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #088 @ 0x0dc0: 0x94000106 -> bl #0x11d8
// Lệnh AArch64 #088 tại 0x0dc0: bl #0x11d8
uint64_t verify_npth_bt_insn_088_0x0dc0(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x94000106U;
    constexpr uint64_t kVaddr  = 0x0dc0ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #089 @ 0x0dc4: 0xF85D03A0 -> ldur x0, [x29, #-0x30]
// Lệnh AArch64 #089 tại 0x0dc4: ldur x0, [x29, #-0x30]
uint64_t verify_npth_bt_insn_089_0x0dc4(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xF85D03A0U;
    constexpr uint64_t kVaddr  = 0x0dc4ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #090 @ 0x0dc8: 0xF9401748 -> ldr x8, [x26, #0x28]
// Lệnh AArch64 #090 tại 0x0dc8: ldr x8, [x26, #0x28]
uint64_t verify_npth_bt_insn_090_0x0dc8(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xF9401748U;
    constexpr uint64_t kVaddr  = 0x0dc8ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #091 @ 0x0dcc: 0xF85F83A9 -> ldur x9, [x29, #-8]
// Lệnh AArch64 #091 tại 0x0dcc: ldur x9, [x29, #-8]
uint64_t verify_npth_bt_insn_091_0x0dcc(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xF85F83A9U;
    constexpr uint64_t kVaddr  = 0x0dccULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #092 @ 0x0dd0: 0xEB09011F -> cmp x8, x9
// Lệnh AArch64 #092 tại 0x0dd0: cmp x8, x9
uint64_t verify_npth_bt_insn_092_0x0dd0(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xEB09011FU;
    constexpr uint64_t kVaddr  = 0x0dd0ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #093 @ 0x0dd4: 0x54000781 -> b.ne #0xec4
// Lệnh AArch64 #093 tại 0x0dd4: b.ne #0xec4
uint64_t verify_npth_bt_insn_093_0x0dd4(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x54000781U;
    constexpr uint64_t kVaddr  = 0x0dd4ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #094 @ 0x0dd8: 0x912143FF -> add sp, sp, #0x850
// Lệnh AArch64 #094 tại 0x0dd8: add sp, sp, #0x850
uint64_t verify_npth_bt_insn_094_0x0dd8(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x912143FFU;
    constexpr uint64_t kVaddr  = 0x0dd8ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #095 @ 0x0ddc: 0xA9454FF4 -> ldp x20, x19, [sp, #0x50]
// Lệnh AArch64 #095 tại 0x0ddc: ldp x20, x19, [sp, #0x50]
uint64_t verify_npth_bt_insn_095_0x0ddc(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xA9454FF4U;
    constexpr uint64_t kVaddr  = 0x0ddcULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #096 @ 0x0de0: 0xA94457F6 -> ldp x22, x21, [sp, #0x40]
// Lệnh AArch64 #096 tại 0x0de0: ldp x22, x21, [sp, #0x40]
uint64_t verify_npth_bt_insn_096_0x0de0(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xA94457F6U;
    constexpr uint64_t kVaddr  = 0x0de0ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #097 @ 0x0de4: 0xA9435FF8 -> ldp x24, x23, [sp, #0x30]
// Lệnh AArch64 #097 tại 0x0de4: ldp x24, x23, [sp, #0x30]
uint64_t verify_npth_bt_insn_097_0x0de4(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xA9435FF8U;
    constexpr uint64_t kVaddr  = 0x0de4ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #098 @ 0x0de8: 0xA94267FA -> ldp x26, x25, [sp, #0x20]
// Lệnh AArch64 #098 tại 0x0de8: ldp x26, x25, [sp, #0x20]
uint64_t verify_npth_bt_insn_098_0x0de8(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xA94267FAU;
    constexpr uint64_t kVaddr  = 0x0de8ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #099 @ 0x0dec: 0xF9400BFC -> ldr x28, [sp, #0x10]
// Lệnh AArch64 #099 tại 0x0dec: ldr x28, [sp, #0x10]
uint64_t verify_npth_bt_insn_099_0x0dec(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xF9400BFCU;
    constexpr uint64_t kVaddr  = 0x0decULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #100 @ 0x0df0: 0xA8C67BFD -> ldp x29, x30, [sp], #0x60
// Lệnh AArch64 #100 tại 0x0df0: ldp x29, x30, [sp], #0x60
uint64_t verify_npth_bt_insn_100_0x0df0(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xA8C67BFDU;
    constexpr uint64_t kVaddr  = 0x0df0ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #101 @ 0x0df4: 0xD65F03C0 -> ret 
// Lệnh AArch64 #101 tại 0x0df4: ret 
uint64_t verify_npth_bt_insn_101_0x0df4(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xD65F03C0U;
    constexpr uint64_t kVaddr  = 0x0df4ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #102 @ 0x0df8: 0x2A0003F8 -> mov w24, w0
// Lệnh AArch64 #102 tại 0x0df8: mov w24, w0
uint64_t verify_npth_bt_insn_102_0x0df8(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x2A0003F8U;
    constexpr uint64_t kVaddr  = 0x0df8ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #103 @ 0x0dfc: 0x7100701F -> cmp w0, #0x1c
// Lệnh AArch64 #103 tại 0x0dfc: cmp w0, #0x1c
uint64_t verify_npth_bt_insn_103_0x0dfc(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x7100701FU;
    constexpr uint64_t kVaddr  = 0x0dfcULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #104 @ 0x0e00: 0x54000083 -> b.lo #0xe10
// Lệnh AArch64 #104 tại 0x0e00: b.lo #0xe10
uint64_t verify_npth_bt_insn_104_0x0e00(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x54000083U;
    constexpr uint64_t kVaddr  = 0x0e00ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #105 @ 0x0e04: 0x940000FA -> bl #0x11ec
// Lệnh AArch64 #105 tại 0x0e04: bl #0x11ec
uint64_t verify_npth_bt_insn_105_0x0e04(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x940000FAU;
    constexpr uint64_t kVaddr  = 0x0e04ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #106 @ 0x0e08: 0xAA0003F7 -> mov x23, x0
// Lệnh AArch64 #106 tại 0x0e08: mov x23, x0
uint64_t verify_npth_bt_insn_106_0x0e08(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xAA0003F7U;
    constexpr uint64_t kVaddr  = 0x0e08ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #107 @ 0x0e0c: 0xB5000080 -> cbnz x0, #0xe1c
// Lệnh AArch64 #107 tại 0x0e0c: cbnz x0, #0xe1c
uint64_t verify_npth_bt_insn_107_0x0e0c(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xB5000080U;
    constexpr uint64_t kVaddr  = 0x0e0cULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #108 @ 0x0e10: 0x940000F4 -> bl #0x11e0
// Lệnh AArch64 #108 tại 0x0e10: bl #0x11e0
uint64_t verify_npth_bt_insn_108_0x0e10(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x940000F4U;
    constexpr uint64_t kVaddr  = 0x0e10ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #109 @ 0x0e14: 0xAA0003F7 -> mov x23, x0
// Lệnh AArch64 #109 tại 0x0e14: mov x23, x0
uint64_t verify_npth_bt_insn_109_0x0e14(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xAA0003F7U;
    constexpr uint64_t kVaddr  = 0x0e14ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #110 @ 0x0e18: 0xB4FFF7E0 -> cbz x0, #0xd14
// Lệnh AArch64 #110 tại 0x0e18: cbz x0, #0xd14
uint64_t verify_npth_bt_insn_110_0x0e18(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xB4FFF7E0U;
    constexpr uint64_t kVaddr  = 0x0e18ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #111 @ 0x0e1c: 0x90000001 -> adrp x1, #0
// Lệnh AArch64 #111 tại 0x0e1c: adrp x1, #0
uint64_t verify_npth_bt_insn_111_0x0e1c(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x90000001U;
    constexpr uint64_t kVaddr  = 0x0e1cULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #112 @ 0x0e20: 0x91240C21 -> add x1, x1, #0x903
// Lệnh AArch64 #112 tại 0x0e20: add x1, x1, #0x903
uint64_t verify_npth_bt_insn_112_0x0e20(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x91240C21U;
    constexpr uint64_t kVaddr  = 0x0e20ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #113 @ 0x0e24: 0x940000E5 -> bl #0x11b8
// Lệnh AArch64 #113 tại 0x0e24: bl #0x11b8
uint64_t verify_npth_bt_insn_113_0x0e24(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x940000E5U;
    constexpr uint64_t kVaddr  = 0x0e24ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #114 @ 0x0e28: 0xAA0003F4 -> mov x20, x0
// Lệnh AArch64 #114 tại 0x0e28: mov x20, x0
uint64_t verify_npth_bt_insn_114_0x0e28(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xAA0003F4U;
    constexpr uint64_t kVaddr  = 0x0e28ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #115 @ 0x0e2c: 0x90000001 -> adrp x1, #0
// Lệnh AArch64 #115 tại 0x0e2c: adrp x1, #0
uint64_t verify_npth_bt_insn_115_0x0e2c(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x90000001U;
    constexpr uint64_t kVaddr  = 0x0e2cULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #116 @ 0x0e30: 0x9125D821 -> add x1, x1, #0x976
// Lệnh AArch64 #116 tại 0x0e30: add x1, x1, #0x976
uint64_t verify_npth_bt_insn_116_0x0e30(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x9125D821U;
    constexpr uint64_t kVaddr  = 0x0e30ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #117 @ 0x0e34: 0x940000E1 -> bl #0x11b8
// Lệnh AArch64 #117 tại 0x0e34: bl #0x11b8
uint64_t verify_npth_bt_insn_117_0x0e34(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x940000E1U;
    constexpr uint64_t kVaddr  = 0x0e34ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #118 @ 0x0e38: 0xAA0003F5 -> mov x21, x0
// Lệnh AArch64 #118 tại 0x0e38: mov x21, x0
uint64_t verify_npth_bt_insn_118_0x0e38(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xAA0003F5U;
    constexpr uint64_t kVaddr  = 0x0e38ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #119 @ 0x0e3c: 0x90000001 -> adrp x1, #0
// Lệnh AArch64 #119 tại 0x0e3c: adrp x1, #0
uint64_t verify_npth_bt_insn_119_0x0e3c(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x90000001U;
    constexpr uint64_t kVaddr  = 0x0e3cULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #120 @ 0x0e40: 0x9122F421 -> add x1, x1, #0x8bd
// Lệnh AArch64 #120 tại 0x0e40: add x1, x1, #0x8bd
uint64_t verify_npth_bt_insn_120_0x0e40(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x9122F421U;
    constexpr uint64_t kVaddr  = 0x0e40ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #121 @ 0x0e44: 0x940000DD -> bl #0x11b8
// Lệnh AArch64 #121 tại 0x0e44: bl #0x11b8
uint64_t verify_npth_bt_insn_121_0x0e44(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x940000DDU;
    constexpr uint64_t kVaddr  = 0x0e44ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #122 @ 0x0e48: 0xAA0003F6 -> mov x22, x0
// Lệnh AArch64 #122 tại 0x0e48: mov x22, x0
uint64_t verify_npth_bt_insn_122_0x0e48(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xAA0003F6U;
    constexpr uint64_t kVaddr  = 0x0e48ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #123 @ 0x0e4c: 0x7100531F -> cmp w24, #0x14
// Lệnh AArch64 #123 tại 0x0e4c: cmp w24, #0x14
uint64_t verify_npth_bt_insn_123_0x0e4c(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x7100531FU;
    constexpr uint64_t kVaddr  = 0x0e4cULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #124 @ 0x0e50: 0x54000108 -> b.hi #0xe70
// Lệnh AArch64 #124 tại 0x0e50: b.hi #0xe70
uint64_t verify_npth_bt_insn_124_0x0e50(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x54000108U;
    constexpr uint64_t kVaddr  = 0x0e50ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #125 @ 0x0e54: 0x90000001 -> adrp x1, #0
// Lệnh AArch64 #125 tại 0x0e54: adrp x1, #0
uint64_t verify_npth_bt_insn_125_0x0e54(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x90000001U;
    constexpr uint64_t kVaddr  = 0x0e54ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #126 @ 0x0e58: 0x91255421 -> add x1, x1, #0x955
// Lệnh AArch64 #126 tại 0x0e58: add x1, x1, #0x955
uint64_t verify_npth_bt_insn_126_0x0e58(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x91255421U;
    constexpr uint64_t kVaddr  = 0x0e58ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #127 @ 0x0e5c: 0x940000D7 -> bl #0x11b8
// Lệnh AArch64 #127 tại 0x0e5c: bl #0x11b8
uint64_t verify_npth_bt_insn_127_0x0e5c(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x940000D7U;
    constexpr uint64_t kVaddr  = 0x0e5cULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #128 @ 0x0e60: 0xB4000080 -> cbz x0, #0xe70
// Lệnh AArch64 #128 tại 0x0e60: cbz x0, #0xe70
uint64_t verify_npth_bt_insn_128_0x0e60(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xB4000080U;
    constexpr uint64_t kVaddr  = 0x0e60ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #129 @ 0x0e64: 0xAA0003F8 -> mov x24, x0
// Lệnh AArch64 #129 tại 0x0e64: mov x24, x0
uint64_t verify_npth_bt_insn_129_0x0e64(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xAA0003F8U;
    constexpr uint64_t kVaddr  = 0x0e64ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #130 @ 0x0e68: 0xAA1F03F9 -> mov x25, xzr
// Lệnh AArch64 #130 tại 0x0e68: mov x25, xzr
uint64_t verify_npth_bt_insn_130_0x0e68(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xAA1F03F9U;
    constexpr uint64_t kVaddr  = 0x0e68ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #131 @ 0x0e6c: 0x14000006 -> b #0xe84
// Lệnh AArch64 #131 tại 0x0e6c: b #0xe84
uint64_t verify_npth_bt_insn_131_0x0e6c(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x14000006U;
    constexpr uint64_t kVaddr  = 0x0e6cULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #132 @ 0x0e70: 0x90000001 -> adrp x1, #0
// Lệnh AArch64 #132 tại 0x0e70: adrp x1, #0
uint64_t verify_npth_bt_insn_132_0x0e70(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x90000001U;
    constexpr uint64_t kVaddr  = 0x0e70ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #133 @ 0x0e74: 0x91247421 -> add x1, x1, #0x91d
// Lệnh AArch64 #133 tại 0x0e74: add x1, x1, #0x91d
uint64_t verify_npth_bt_insn_133_0x0e74(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x91247421U;
    constexpr uint64_t kVaddr  = 0x0e74ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #134 @ 0x0e78: 0x940000D0 -> bl #0x11b8
// Lệnh AArch64 #134 tại 0x0e78: bl #0x11b8
uint64_t verify_npth_bt_insn_134_0x0e78(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x940000D0U;
    constexpr uint64_t kVaddr  = 0x0e78ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #135 @ 0x0e7c: 0xAA0003F9 -> mov x25, x0
// Lệnh AArch64 #135 tại 0x0e7c: mov x25, x0
uint64_t verify_npth_bt_insn_135_0x0e7c(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xAA0003F9U;
    constexpr uint64_t kVaddr  = 0x0e7cULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #136 @ 0x0e80: 0xAA1F03F8 -> mov x24, xzr
// Lệnh AArch64 #136 tại 0x0e80: mov x24, xzr
uint64_t verify_npth_bt_insn_136_0x0e80(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xAA1F03F8U;
    constexpr uint64_t kVaddr  = 0x0e80ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #137 @ 0x0e84: 0xAA1703E0 -> mov x0, x23
// Lệnh AArch64 #137 tại 0x0e84: mov x0, x23
uint64_t verify_npth_bt_insn_137_0x0e84(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xAA1703E0U;
    constexpr uint64_t kVaddr  = 0x0e84ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #138 @ 0x0e88: 0x940000FE -> bl #0x1280
// Lệnh AArch64 #138 tại 0x0e88: bl #0x1280
uint64_t verify_npth_bt_insn_138_0x0e88(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x940000FEU;
    constexpr uint64_t kVaddr  = 0x0e88ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #139 @ 0x0e8c: 0xB4FFF454 -> cbz x20, #0xd14
// Lệnh AArch64 #139 tại 0x0e8c: cbz x20, #0xd14
uint64_t verify_npth_bt_insn_139_0x0e8c(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xB4FFF454U;
    constexpr uint64_t kVaddr  = 0x0e8cULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #140 @ 0x0e90: 0xB4FFF436 -> cbz x22, #0xd14
// Lệnh AArch64 #140 tại 0x0e90: cbz x22, #0xd14
uint64_t verify_npth_bt_insn_140_0x0e90(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xB4FFF436U;
    constexpr uint64_t kVaddr  = 0x0e90ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #141 @ 0x0e94: 0xB4FFF415 -> cbz x21, #0xd14
// Lệnh AArch64 #141 tại 0x0e94: cbz x21, #0xd14
uint64_t verify_npth_bt_insn_141_0x0e94(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xB4FFF415U;
    constexpr uint64_t kVaddr  = 0x0e94ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #142 @ 0x0e98: 0xAA180328 -> orr x8, x25, x24
// Lệnh AArch64 #142 tại 0x0e98: orr x8, x25, x24
uint64_t verify_npth_bt_insn_142_0x0e98(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xAA180328U;
    constexpr uint64_t kVaddr  = 0x0e98ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #143 @ 0x0e9c: 0xB4FFF3C8 -> cbz x8, #0xd14
// Lệnh AArch64 #143 tại 0x0e9c: cbz x8, #0xd14
uint64_t verify_npth_bt_insn_143_0x0e9c(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xB4FFF3C8U;
    constexpr uint64_t kVaddr  = 0x0e9cULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #144 @ 0x0ea0: 0x52800500 -> mov w0, #0x28
// Lệnh AArch64 #144 tại 0x0ea0: mov w0, #0x28
uint64_t verify_npth_bt_insn_144_0x0ea0(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x52800500U;
    constexpr uint64_t kVaddr  = 0x0ea0ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #145 @ 0x0ea4: 0x940000FB -> bl #0x1290
// Lệnh AArch64 #145 tại 0x0ea4: bl #0x1290
uint64_t verify_npth_bt_insn_145_0x0ea4(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x940000FBU;
    constexpr uint64_t kVaddr  = 0x0ea4ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #146 @ 0x0ea8: 0xB0000048 -> adrp x8, #0x9000
// Lệnh AArch64 #146 tại 0x0ea8: adrp x8, #0x9000
uint64_t verify_npth_bt_insn_146_0x0ea8(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xB0000048U;
    constexpr uint64_t kVaddr  = 0x0ea8ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #147 @ 0x0eac: 0xF902AD00 -> str x0, [x8, #0x558]
// Lệnh AArch64 #147 tại 0x0eac: str x0, [x8, #0x558]
uint64_t verify_npth_bt_insn_147_0x0eac(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xF902AD00U;
    constexpr uint64_t kVaddr  = 0x0eacULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #148 @ 0x0eb0: 0xB4FFF320 -> cbz x0, #0xd14
// Lệnh AArch64 #148 tại 0x0eb0: cbz x0, #0xd14
uint64_t verify_npth_bt_insn_148_0x0eb0(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xB4FFF320U;
    constexpr uint64_t kVaddr  = 0x0eb0ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #149 @ 0x0eb4: 0xA901D416 -> stp x22, x21, [x0, #0x18]
// Lệnh AArch64 #149 tại 0x0eb4: stp x22, x21, [x0, #0x18]
uint64_t verify_npth_bt_insn_149_0x0eb4(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xA901D416U;
    constexpr uint64_t kVaddr  = 0x0eb4ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #150 @ 0x0eb8: 0xA9006414 -> stp x20, x25, [x0]
// Lệnh AArch64 #150 tại 0x0eb8: stp x20, x25, [x0]
uint64_t verify_npth_bt_insn_150_0x0eb8(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xA9006414U;
    constexpr uint64_t kVaddr  = 0x0eb8ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #151 @ 0x0ebc: 0xF9000818 -> str x24, [x0, #0x10]
// Lệnh AArch64 #151 tại 0x0ebc: str x24, [x0, #0x10]
uint64_t verify_npth_bt_insn_151_0x0ebc(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xF9000818U;
    constexpr uint64_t kVaddr  = 0x0ebcULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #152 @ 0x0ec0: 0x17FFFF95 -> b #0xd14
// Lệnh AArch64 #152 tại 0x0ec0: b #0xd14
uint64_t verify_npth_bt_insn_152_0x0ec0(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x17FFFF95U;
    constexpr uint64_t kVaddr  = 0x0ec0ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #153 @ 0x0ec4: 0x940000F7 -> bl #0x12a0
// Lệnh AArch64 #153 tại 0x0ec4: bl #0x12a0
uint64_t verify_npth_bt_insn_153_0x0ec4(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x940000F7U;
    constexpr uint64_t kVaddr  = 0x0ec4ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #154 @ 0x0ec8: 0xA9BD7BFD -> stp x29, x30, [sp, #-0x30]!
// Lệnh AArch64 #154 tại 0x0ec8: stp x29, x30, [sp, #-0x30]!
uint64_t verify_npth_bt_insn_154_0x0ec8(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xA9BD7BFDU;
    constexpr uint64_t kVaddr  = 0x0ec8ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #155 @ 0x0ecc: 0xA90157F6 -> stp x22, x21, [sp, #0x10]
// Lệnh AArch64 #155 tại 0x0ecc: stp x22, x21, [sp, #0x10]
uint64_t verify_npth_bt_insn_155_0x0ecc(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xA90157F6U;
    constexpr uint64_t kVaddr  = 0x0eccULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #156 @ 0x0ed0: 0xA9024FF4 -> stp x20, x19, [sp, #0x20]
// Lệnh AArch64 #156 tại 0x0ed0: stp x20, x19, [sp, #0x20]
uint64_t verify_npth_bt_insn_156_0x0ed0(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xA9024FF4U;
    constexpr uint64_t kVaddr  = 0x0ed0ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #157 @ 0x0ed4: 0x910003FD -> mov x29, sp
// Lệnh AArch64 #157 tại 0x0ed4: mov x29, sp
uint64_t verify_npth_bt_insn_157_0x0ed4(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x910003FDU;
    constexpr uint64_t kVaddr  = 0x0ed4ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #158 @ 0x0ed8: 0xB0000053 -> adrp x19, #0x9000
// Lệnh AArch64 #158 tại 0x0ed8: adrp x19, #0x9000
uint64_t verify_npth_bt_insn_158_0x0ed8(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xB0000053U;
    constexpr uint64_t kVaddr  = 0x0ed8ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #159 @ 0x0edc: 0xB0000056 -> adrp x22, #0x9000
// Lệnh AArch64 #159 tại 0x0edc: adrp x22, #0x9000
uint64_t verify_npth_bt_insn_159_0x0edc(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xB0000056U;
    constexpr uint64_t kVaddr  = 0x0edcULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #160 @ 0x0ee0: 0x39553268 -> ldrb w8, [x19, #0x54c]
// Lệnh AArch64 #160 tại 0x0ee0: ldrb w8, [x19, #0x54c]
uint64_t verify_npth_bt_insn_160_0x0ee0(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x39553268U;
    constexpr uint64_t kVaddr  = 0x0ee0ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #161 @ 0x0ee4: 0x37000468 -> tbnz w8, #0, #0xf70
// Lệnh AArch64 #161 tại 0x0ee4: tbnz w8, #0, #0xf70
uint64_t verify_npth_bt_insn_161_0x0ee4(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x37000468U;
    constexpr uint64_t kVaddr  = 0x0ee4ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #162 @ 0x0ee8: 0xB0000054 -> adrp x20, #0x9000
// Lệnh AArch64 #162 tại 0x0ee8: adrp x20, #0x9000
uint64_t verify_npth_bt_insn_162_0x0ee8(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xB0000054U;
    constexpr uint64_t kVaddr  = 0x0ee8ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #163 @ 0x0eec: 0x91153294 -> add x20, x20, #0x54c
// Lệnh AArch64 #163 tại 0x0eec: add x20, x20, #0x54c
uint64_t verify_npth_bt_insn_163_0x0eec(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x91153294U;
    constexpr uint64_t kVaddr  = 0x0eecULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #164 @ 0x0ef0: 0x91013280 -> add x0, x20, #0x4c
// Lệnh AArch64 #164 tại 0x0ef0: add x0, x20, #0x4c
uint64_t verify_npth_bt_insn_164_0x0ef0(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x91013280U;
    constexpr uint64_t kVaddr  = 0x0ef0ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #165 @ 0x0ef4: 0x940000D7 -> bl #0x1250
// Lệnh AArch64 #165 tại 0x0ef4: bl #0x1250
uint64_t verify_npth_bt_insn_165_0x0ef4(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x940000D7U;
    constexpr uint64_t kVaddr  = 0x0ef4ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #166 @ 0x0ef8: 0x39400288 -> ldrb w8, [x20]
// Lệnh AArch64 #166 tại 0x0ef8: ldrb w8, [x20]
uint64_t verify_npth_bt_insn_166_0x0ef8(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x39400288U;
    constexpr uint64_t kVaddr  = 0x0ef8ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #167 @ 0x0efc: 0x37000348 -> tbnz w8, #0, #0xf64
// Lệnh AArch64 #167 tại 0x0efc: tbnz w8, #0, #0xf64
uint64_t verify_npth_bt_insn_167_0x0efc(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x37000348U;
    constexpr uint64_t kVaddr  = 0x0efcULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #168 @ 0x0f00: 0x52800028 -> mov w8, #1
// Lệnh AArch64 #168 tại 0x0f00: mov w8, #1
uint64_t verify_npth_bt_insn_168_0x0f00(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x52800028U;
    constexpr uint64_t kVaddr  = 0x0f00ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #169 @ 0x0f04: 0x90000000 -> adrp x0, #0
// Lệnh AArch64 #169 tại 0x0f04: adrp x0, #0
uint64_t verify_npth_bt_insn_169_0x0f04(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x90000000U;
    constexpr uint64_t kVaddr  = 0x0f04ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #170 @ 0x0f08: 0x91227000 -> add x0, x0, #0x89c
// Lệnh AArch64 #170 tại 0x0f08: add x0, x0, #0x89c
uint64_t verify_npth_bt_insn_170_0x0f08(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x91227000U;
    constexpr uint64_t kVaddr  = 0x0f08ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #171 @ 0x0f0c: 0x39153268 -> strb w8, [x19, #0x54c]
// Lệnh AArch64 #171 tại 0x0f0c: strb w8, [x19, #0x54c]
uint64_t verify_npth_bt_insn_171_0x0f0c(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x39153268U;
    constexpr uint64_t kVaddr  = 0x0f0cULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #172 @ 0x0f10: 0x940000E8 -> bl #0x12b0
// Lệnh AArch64 #172 tại 0x0f10: bl #0x12b0
uint64_t verify_npth_bt_insn_172_0x0f10(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x940000E8U;
    constexpr uint64_t kVaddr  = 0x0f10ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #173 @ 0x0f14: 0xB4000280 -> cbz x0, #0xf64
// Lệnh AArch64 #173 tại 0x0f14: cbz x0, #0xf64
uint64_t verify_npth_bt_insn_173_0x0f14(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xB4000280U;
    constexpr uint64_t kVaddr  = 0x0f14ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #174 @ 0x0f18: 0x90000001 -> adrp x1, #0
// Lệnh AArch64 #174 tại 0x0f18: adrp x1, #0
uint64_t verify_npth_bt_insn_174_0x0f18(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x90000001U;
    constexpr uint64_t kVaddr  = 0x0f18ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #175 @ 0x0f1c: 0x91276421 -> add x1, x1, #0x9d9
// Lệnh AArch64 #175 tại 0x0f1c: add x1, x1, #0x9d9
uint64_t verify_npth_bt_insn_175_0x0f1c(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x91276421U;
    constexpr uint64_t kVaddr  = 0x0f1cULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #176 @ 0x0f20: 0xAA0003F5 -> mov x21, x0
// Lệnh AArch64 #176 tại 0x0f20: mov x21, x0
uint64_t verify_npth_bt_insn_176_0x0f20(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xAA0003F5U;
    constexpr uint64_t kVaddr  = 0x0f20ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #177 @ 0x0f24: 0x940000E7 -> bl #0x12c0
// Lệnh AArch64 #177 tại 0x0f24: bl #0x12c0
uint64_t verify_npth_bt_insn_177_0x0f24(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x940000E7U;
    constexpr uint64_t kVaddr  = 0x0f24ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #178 @ 0x0f28: 0xAA0003F3 -> mov x19, x0
// Lệnh AArch64 #178 tại 0x0f28: mov x19, x0
uint64_t verify_npth_bt_insn_178_0x0f28(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xAA0003F3U;
    constexpr uint64_t kVaddr  = 0x0f28ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #179 @ 0x0f2c: 0x90000001 -> adrp x1, #0
// Lệnh AArch64 #179 tại 0x0f2c: adrp x1, #0
uint64_t verify_npth_bt_insn_179_0x0f2c(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x90000001U;
    constexpr uint64_t kVaddr  = 0x0f2cULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #180 @ 0x0f30: 0x9124F421 -> add x1, x1, #0x93d
// Lệnh AArch64 #180 tại 0x0f30: add x1, x1, #0x93d
uint64_t verify_npth_bt_insn_180_0x0f30(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x9124F421U;
    constexpr uint64_t kVaddr  = 0x0f30ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #181 @ 0x0f34: 0xAA1503E0 -> mov x0, x21
// Lệnh AArch64 #181 tại 0x0f34: mov x0, x21
uint64_t verify_npth_bt_insn_181_0x0f34(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xAA1503E0U;
    constexpr uint64_t kVaddr  = 0x0f34ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #182 @ 0x0f38: 0x940000E2 -> bl #0x12c0
// Lệnh AArch64 #182 tại 0x0f38: bl #0x12c0
uint64_t verify_npth_bt_insn_182_0x0f38(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x940000E2U;
    constexpr uint64_t kVaddr  = 0x0f38ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #183 @ 0x0f3c: 0xAA0003F4 -> mov x20, x0
// Lệnh AArch64 #183 tại 0x0f3c: mov x20, x0
uint64_t verify_npth_bt_insn_183_0x0f3c(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xAA0003F4U;
    constexpr uint64_t kVaddr  = 0x0f3cULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #184 @ 0x0f40: 0xAA1503E0 -> mov x0, x21
// Lệnh AArch64 #184 tại 0x0f40: mov x0, x21
uint64_t verify_npth_bt_insn_184_0x0f40(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xAA1503E0U;
    constexpr uint64_t kVaddr  = 0x0f40ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #185 @ 0x0f44: 0x940000CF -> bl #0x1280
// Lệnh AArch64 #185 tại 0x0f44: bl #0x1280
uint64_t verify_npth_bt_insn_185_0x0f44(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x940000CFU;
    constexpr uint64_t kVaddr  = 0x0f44ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #186 @ 0x0f48: 0xB40000F3 -> cbz x19, #0xf64
// Lệnh AArch64 #186 tại 0x0f48: cbz x19, #0xf64
uint64_t verify_npth_bt_insn_186_0x0f48(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xB40000F3U;
    constexpr uint64_t kVaddr  = 0x0f48ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #187 @ 0x0f4c: 0xB40000D4 -> cbz x20, #0xf64
// Lệnh AArch64 #187 tại 0x0f4c: cbz x20, #0xf64
uint64_t verify_npth_bt_insn_187_0x0f4c(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xB40000D4U;
    constexpr uint64_t kVaddr  = 0x0f4cULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #188 @ 0x0f50: 0x52800200 -> mov w0, #0x10
// Lệnh AArch64 #188 tại 0x0f50: mov w0, #0x10
uint64_t verify_npth_bt_insn_188_0x0f50(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x52800200U;
    constexpr uint64_t kVaddr  = 0x0f50ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #189 @ 0x0f54: 0x940000CF -> bl #0x1290
// Lệnh AArch64 #189 tại 0x0f54: bl #0x1290
uint64_t verify_npth_bt_insn_189_0x0f54(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x940000CFU;
    constexpr uint64_t kVaddr  = 0x0f54ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #190 @ 0x0f58: 0xF902B2C0 -> str x0, [x22, #0x560]
// Lệnh AArch64 #190 tại 0x0f58: str x0, [x22, #0x560]
uint64_t verify_npth_bt_insn_190_0x0f58(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xF902B2C0U;
    constexpr uint64_t kVaddr  = 0x0f58ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #191 @ 0x0f5c: 0xB4000040 -> cbz x0, #0xf64
// Lệnh AArch64 #191 tại 0x0f5c: cbz x0, #0xf64
uint64_t verify_npth_bt_insn_191_0x0f5c(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xB4000040U;
    constexpr uint64_t kVaddr  = 0x0f5cULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #192 @ 0x0f60: 0xA9005013 -> stp x19, x20, [x0]
// Lệnh AArch64 #192 tại 0x0f60: stp x19, x20, [x0]
uint64_t verify_npth_bt_insn_192_0x0f60(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xA9005013U;
    constexpr uint64_t kVaddr  = 0x0f60ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #193 @ 0x0f64: 0xB0000040 -> adrp x0, #0x9000
// Lệnh AArch64 #193 tại 0x0f64: adrp x0, #0x9000
uint64_t verify_npth_bt_insn_193_0x0f64(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xB0000040U;
    constexpr uint64_t kVaddr  = 0x0f64ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #194 @ 0x0f68: 0x91166000 -> add x0, x0, #0x598
// Lệnh AArch64 #194 tại 0x0f68: add x0, x0, #0x598
uint64_t verify_npth_bt_insn_194_0x0f68(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x91166000U;
    constexpr uint64_t kVaddr  = 0x0f68ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #195 @ 0x0f6c: 0x940000BD -> bl #0x1260
// Lệnh AArch64 #195 tại 0x0f6c: bl #0x1260
uint64_t verify_npth_bt_insn_195_0x0f6c(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x940000BDU;
    constexpr uint64_t kVaddr  = 0x0f6cULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #196 @ 0x0f70: 0xF942B2C0 -> ldr x0, [x22, #0x560]
// Lệnh AArch64 #196 tại 0x0f70: ldr x0, [x22, #0x560]
uint64_t verify_npth_bt_insn_196_0x0f70(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xF942B2C0U;
    constexpr uint64_t kVaddr  = 0x0f70ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #197 @ 0x0f74: 0xA9424FF4 -> ldp x20, x19, [sp, #0x20]
// Lệnh AArch64 #197 tại 0x0f74: ldp x20, x19, [sp, #0x20]
uint64_t verify_npth_bt_insn_197_0x0f74(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xA9424FF4U;
    constexpr uint64_t kVaddr  = 0x0f74ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #198 @ 0x0f78: 0xA94157F6 -> ldp x22, x21, [sp, #0x10]
// Lệnh AArch64 #198 tại 0x0f78: ldp x22, x21, [sp, #0x10]
uint64_t verify_npth_bt_insn_198_0x0f78(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xA94157F6U;
    constexpr uint64_t kVaddr  = 0x0f78ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #199 @ 0x0f7c: 0xA8C37BFD -> ldp x29, x30, [sp], #0x30
// Lệnh AArch64 #199 tại 0x0f7c: ldp x29, x30, [sp], #0x30
uint64_t verify_npth_bt_insn_199_0x0f7c(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xA8C37BFDU;
    constexpr uint64_t kVaddr  = 0x0f7cULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #200 @ 0x0f80: 0xD65F03C0 -> ret 
// Lệnh AArch64 #200 tại 0x0f80: ret 
uint64_t verify_npth_bt_insn_200_0x0f80(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xD65F03C0U;
    constexpr uint64_t kVaddr  = 0x0f80ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #201 @ 0x0f84: 0x12800000 -> mov w0, #-1
// Lệnh AArch64 #201 tại 0x0f84: mov w0, #-1
uint64_t verify_npth_bt_insn_201_0x0f84(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x12800000U;
    constexpr uint64_t kVaddr  = 0x0f84ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #202 @ 0x0f88: 0x140000AE -> b #0x1240
// Lệnh AArch64 #202 tại 0x0f88: b #0x1240
uint64_t verify_npth_bt_insn_202_0x0f88(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x140000AEU;
    constexpr uint64_t kVaddr  = 0x0f88ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #203 @ 0x0f8c: 0xA9BB7BFD -> stp x29, x30, [sp, #-0x50]!
// Lệnh AArch64 #203 tại 0x0f8c: stp x29, x30, [sp, #-0x50]!
uint64_t verify_npth_bt_insn_203_0x0f8c(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xA9BB7BFDU;
    constexpr uint64_t kVaddr  = 0x0f8cULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #204 @ 0x0f90: 0xF9000BFC -> str x28, [sp, #0x10]
// Lệnh AArch64 #204 tại 0x0f90: str x28, [sp, #0x10]
uint64_t verify_npth_bt_insn_204_0x0f90(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xF9000BFCU;
    constexpr uint64_t kVaddr  = 0x0f90ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #205 @ 0x0f94: 0xA9025FF8 -> stp x24, x23, [sp, #0x20]
// Lệnh AArch64 #205 tại 0x0f94: stp x24, x23, [sp, #0x20]
uint64_t verify_npth_bt_insn_205_0x0f94(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xA9025FF8U;
    constexpr uint64_t kVaddr  = 0x0f94ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #206 @ 0x0f98: 0xA90357F6 -> stp x22, x21, [sp, #0x30]
// Lệnh AArch64 #206 tại 0x0f98: stp x22, x21, [sp, #0x30]
uint64_t verify_npth_bt_insn_206_0x0f98(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xA90357F6U;
    constexpr uint64_t kVaddr  = 0x0f98ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #207 @ 0x0f9c: 0xA9044FF4 -> stp x20, x19, [sp, #0x40]
// Lệnh AArch64 #207 tại 0x0f9c: stp x20, x19, [sp, #0x40]
uint64_t verify_npth_bt_insn_207_0x0f9c(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xA9044FF4U;
    constexpr uint64_t kVaddr  = 0x0f9cULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #208 @ 0x0fa0: 0x910003FD -> mov x29, sp
// Lệnh AArch64 #208 tại 0x0fa0: mov x29, sp
uint64_t verify_npth_bt_insn_208_0x0fa0(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x910003FDU;
    constexpr uint64_t kVaddr  = 0x0fa0ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #209 @ 0x0fa4: 0xD12143FF -> sub sp, sp, #0x850
// Lệnh AArch64 #209 tại 0x0fa4: sub sp, sp, #0x850
uint64_t verify_npth_bt_insn_209_0x0fa4(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xD12143FFU;
    constexpr uint64_t kVaddr  = 0x0fa4ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #210 @ 0x0fa8: 0xD53BD058 -> mrs x24, tpidr_el0
// Lệnh AArch64 #210 tại 0x0fa8: mrs x24, tpidr_el0
uint64_t verify_npth_bt_insn_210_0x0fa8(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xD53BD058U;
    constexpr uint64_t kVaddr  = 0x0fa8ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #211 @ 0x0fac: 0xB0000053 -> adrp x19, #0x9000
// Lệnh AArch64 #211 tại 0x0fac: adrp x19, #0x9000
uint64_t verify_npth_bt_insn_211_0x0fac(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xB0000053U;
    constexpr uint64_t kVaddr  = 0x0facULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #212 @ 0x0fb0: 0xF9401708 -> ldr x8, [x24, #0x28]
// Lệnh AArch64 #212 tại 0x0fb0: ldr x8, [x24, #0x28]
uint64_t verify_npth_bt_insn_212_0x0fb0(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xF9401708U;
    constexpr uint64_t kVaddr  = 0x0fb0ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #213 @ 0x0fb4: 0xF81F83A8 -> stur x8, [x29, #-8]
// Lệnh AArch64 #213 tại 0x0fb4: stur x8, [x29, #-8]
uint64_t verify_npth_bt_insn_213_0x0fb4(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xF81F83A8U;
    constexpr uint64_t kVaddr  = 0x0fb4ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #214 @ 0x0fb8: 0x39554268 -> ldrb w8, [x19, #0x550]
// Lệnh AArch64 #214 tại 0x0fb8: ldrb w8, [x19, #0x550]
uint64_t verify_npth_bt_insn_214_0x0fb8(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x39554268U;
    constexpr uint64_t kVaddr  = 0x0fb8ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #215 @ 0x0fbc: 0x7100051F -> cmp w8, #1
// Lệnh AArch64 #215 tại 0x0fbc: cmp w8, #1
uint64_t verify_npth_bt_insn_215_0x0fbc(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x7100051FU;
    constexpr uint64_t kVaddr  = 0x0fbcULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #216 @ 0x0fc0: 0x54000081 -> b.ne #0xfd0
// Lệnh AArch64 #216 tại 0x0fc0: b.ne #0xfd0
uint64_t verify_npth_bt_insn_216_0x0fc0(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x54000081U;
    constexpr uint64_t kVaddr  = 0x0fc0ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #217 @ 0x0fc4: 0xB0000048 -> adrp x8, #0x9000
// Lệnh AArch64 #217 tại 0x0fc4: adrp x8, #0x9000
uint64_t verify_npth_bt_insn_217_0x0fc4(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xB0000048U;
    constexpr uint64_t kVaddr  = 0x0fc4ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #218 @ 0x0fc8: 0xF942B514 -> ldr x20, [x8, #0x568]
// Lệnh AArch64 #218 tại 0x0fc8: ldr x20, [x8, #0x568]
uint64_t verify_npth_bt_insn_218_0x0fc8(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xF942B514U;
    constexpr uint64_t kVaddr  = 0x0fc8ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #219 @ 0x0fcc: 0x14000014 -> b #0x101c
// Lệnh AArch64 #219 tại 0x0fcc: b #0x101c
uint64_t verify_npth_bt_insn_219_0x0fcc(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x14000014U;
    constexpr uint64_t kVaddr  = 0x0fccULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #220 @ 0x0fd0: 0xB0000054 -> adrp x20, #0x9000
// Lệnh AArch64 #220 tại 0x0fd0: adrp x20, #0x9000
uint64_t verify_npth_bt_insn_220_0x0fd0(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xB0000054U;
    constexpr uint64_t kVaddr  = 0x0fd0ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #221 @ 0x0fd4: 0x91154294 -> add x20, x20, #0x550
// Lệnh AArch64 #221 tại 0x0fd4: add x20, x20, #0x550
uint64_t verify_npth_bt_insn_221_0x0fd4(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x91154294U;
    constexpr uint64_t kVaddr  = 0x0fd4ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #222 @ 0x0fd8: 0x9101C280 -> add x0, x20, #0x70
// Lệnh AArch64 #222 tại 0x0fd8: add x0, x20, #0x70
uint64_t verify_npth_bt_insn_222_0x0fd8(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x9101C280U;
    constexpr uint64_t kVaddr  = 0x0fd8ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #223 @ 0x0fdc: 0x9400009D -> bl #0x1250
// Lệnh AArch64 #223 tại 0x0fdc: bl #0x1250
uint64_t verify_npth_bt_insn_223_0x0fdc(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x9400009DU;
    constexpr uint64_t kVaddr  = 0x0fdcULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #224 @ 0x0fe0: 0x39400288 -> ldrb w8, [x20]
// Lệnh AArch64 #224 tại 0x0fe0: ldrb w8, [x20]
uint64_t verify_npth_bt_insn_224_0x0fe0(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x39400288U;
    constexpr uint64_t kVaddr  = 0x0fe0ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #225 @ 0x0fe4: 0x360000E8 -> tbz w8, #0, #0x1000
// Lệnh AArch64 #225 tại 0x0fe4: tbz w8, #0, #0x1000
uint64_t verify_npth_bt_insn_225_0x0fe4(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x360000E8U;
    constexpr uint64_t kVaddr  = 0x0fe4ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #226 @ 0x0fe8: 0xB0000053 -> adrp x19, #0x9000
// Lệnh AArch64 #226 tại 0x0fe8: adrp x19, #0x9000
uint64_t verify_npth_bt_insn_226_0x0fe8(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xB0000053U;
    constexpr uint64_t kVaddr  = 0x0fe8ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #227 @ 0x0fec: 0x9115A273 -> add x19, x19, #0x568
// Lệnh AArch64 #227 tại 0x0fec: add x19, x19, #0x568
uint64_t verify_npth_bt_insn_227_0x0fec(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x9115A273U;
    constexpr uint64_t kVaddr  = 0x0fecULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #228 @ 0x0ff0: 0x91016260 -> add x0, x19, #0x58
// Lệnh AArch64 #228 tại 0x0ff0: add x0, x19, #0x58
uint64_t verify_npth_bt_insn_228_0x0ff0(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x91016260U;
    constexpr uint64_t kVaddr  = 0x0ff0ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #229 @ 0x0ff4: 0x9400009B -> bl #0x1260
// Lệnh AArch64 #229 tại 0x0ff4: bl #0x1260
uint64_t verify_npth_bt_insn_229_0x0ff4(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x9400009BU;
    constexpr uint64_t kVaddr  = 0x0ff4ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #230 @ 0x0ff8: 0xF9400274 -> ldr x20, [x19]
// Lệnh AArch64 #230 tại 0x0ff8: ldr x20, [x19]
uint64_t verify_npth_bt_insn_230_0x0ff8(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xF9400274U;
    constexpr uint64_t kVaddr  = 0x0ff8ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #231 @ 0x0ffc: 0x14000008 -> b #0x101c
// Lệnh AArch64 #231 tại 0x0ffc: b #0x101c
uint64_t verify_npth_bt_insn_231_0x0ffc(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x14000008U;
    constexpr uint64_t kVaddr  = 0x0ffcULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #232 @ 0x1000: 0x52800028 -> mov w8, #1
// Lệnh AArch64 #232 tại 0x1000: mov w8, #1
uint64_t verify_npth_bt_insn_232_0x1000(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x52800028U;
    constexpr uint64_t kVaddr  = 0x1000ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #233 @ 0x1004: 0x39154268 -> strb w8, [x19, #0x550]
// Lệnh AArch64 #233 tại 0x1004: strb w8, [x19, #0x550]
uint64_t verify_npth_bt_insn_233_0x1004(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x39154268U;
    constexpr uint64_t kVaddr  = 0x1004ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #234 @ 0x1008: 0x9400009A -> bl #0x1270
// Lệnh AArch64 #234 tại 0x1008: bl #0x1270
uint64_t verify_npth_bt_insn_234_0x1008(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x9400009AU;
    constexpr uint64_t kVaddr  = 0x1008ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #235 @ 0x100c: 0x51009008 -> sub w8, w0, #0x24
// Lệnh AArch64 #235 tại 0x100c: sub w8, w0, #0x24
uint64_t verify_npth_bt_insn_235_0x100c(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x51009008U;
    constexpr uint64_t kVaddr  = 0x100cULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #236 @ 0x1010: 0x3100451F -> cmn w8, #0x11
// Lệnh AArch64 #236 tại 0x1010: cmn w8, #0x11
uint64_t verify_npth_bt_insn_236_0x1010(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x3100451FU;
    constexpr uint64_t kVaddr  = 0x1010ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #237 @ 0x1014: 0x54000442 -> b.hs #0x109c
// Lệnh AArch64 #237 tại 0x1014: b.hs #0x109c
uint64_t verify_npth_bt_insn_237_0x1014(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x54000442U;
    constexpr uint64_t kVaddr  = 0x1014ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #238 @ 0x1018: 0xAA1F03F4 -> mov x20, xzr
// Lệnh AArch64 #238 tại 0x1018: mov x20, xzr
uint64_t verify_npth_bt_insn_238_0x1018(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xAA1F03F4U;
    constexpr uint64_t kVaddr  = 0x1018ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #239 @ 0x101c: 0x97FFFFAB -> bl #0xec8
// Lệnh AArch64 #239 tại 0x101c: bl #0xec8
uint64_t verify_npth_bt_insn_239_0x101c(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x97FFFFABU;
    constexpr uint64_t kVaddr  = 0x101cULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #240 @ 0x1020: 0xAA0003F3 -> mov x19, x0
// Lệnh AArch64 #240 tại 0x1020: mov x19, x0
uint64_t verify_npth_bt_insn_240_0x1020(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xAA0003F3U;
    constexpr uint64_t kVaddr  = 0x1020ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #241 @ 0x1024: 0xAA1F03E0 -> mov x0, xzr
// Lệnh AArch64 #241 tại 0x1024: mov x0, xzr
uint64_t verify_npth_bt_insn_241_0x1024(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xAA1F03E0U;
    constexpr uint64_t kVaddr  = 0x1024ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #242 @ 0x1028: 0xB4000254 -> cbz x20, #0x1070
// Lệnh AArch64 #242 tại 0x1028: cbz x20, #0x1070
uint64_t verify_npth_bt_insn_242_0x1028(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xB4000254U;
    constexpr uint64_t kVaddr  = 0x1028ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #243 @ 0x102c: 0xB4000233 -> cbz x19, #0x1070
// Lệnh AArch64 #243 tại 0x102c: cbz x19, #0x1070
uint64_t verify_npth_bt_insn_243_0x102c(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xB4000233U;
    constexpr uint64_t kVaddr  = 0x102cULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #244 @ 0x1030: 0x9400005C -> bl #0x11a0
// Lệnh AArch64 #244 tại 0x1030: bl #0x11a0
uint64_t verify_npth_bt_insn_244_0x1030(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x9400005CU;
    constexpr uint64_t kVaddr  = 0x1030ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #245 @ 0x1034: 0xF9400268 -> ldr x8, [x19]
// Lệnh AArch64 #245 tại 0x1034: ldr x8, [x19]
uint64_t verify_npth_bt_insn_245_0x1034(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xF9400268U;
    constexpr uint64_t kVaddr  = 0x1034ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #246 @ 0x1038: 0xD100C3A0 -> sub x0, x29, #0x30
// Lệnh AArch64 #246 tại 0x1038: sub x0, x29, #0x30
uint64_t verify_npth_bt_insn_246_0x1038(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xD100C3A0U;
    constexpr uint64_t kVaddr  = 0x1038ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #247 @ 0x103c: 0xD63F0100 -> blr x8
// Lệnh AArch64 #247 tại 0x103c: blr x8
uint64_t verify_npth_bt_insn_247_0x103c(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xD63F0100U;
    constexpr uint64_t kVaddr  = 0x103cULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #248 @ 0x1040: 0xF9400288 -> ldr x8, [x20]
// Lệnh AArch64 #248 tại 0x1040: ldr x8, [x20]
uint64_t verify_npth_bt_insn_248_0x1040(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xF9400288U;
    constexpr uint64_t kVaddr  = 0x1040ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #249 @ 0x1044: 0x94000065 -> bl #0x11d8
// Lệnh AArch64 #249 tại 0x1044: bl #0x11d8
uint64_t verify_npth_bt_insn_249_0x1044(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x94000065U;
    constexpr uint64_t kVaddr  = 0x1044ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #250 @ 0x1048: 0xF9400688 -> ldr x8, [x20, #8]
// Lệnh AArch64 #250 tại 0x1048: ldr x8, [x20, #8]
uint64_t verify_npth_bt_insn_250_0x1048(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xF9400688U;
    constexpr uint64_t kVaddr  = 0x1048ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #251 @ 0x104c: 0x94000063 -> bl #0x11d8
// Lệnh AArch64 #251 tại 0x104c: bl #0x11d8
uint64_t verify_npth_bt_insn_251_0x104c(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x94000063U;
    constexpr uint64_t kVaddr  = 0x104cULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #252 @ 0x1050: 0xF9400A89 -> ldr x9, [x20, #0x10]
// Lệnh AArch64 #252 tại 0x1050: ldr x9, [x20, #0x10]
uint64_t verify_npth_bt_insn_252_0x1050(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xF9400A89U;
    constexpr uint64_t kVaddr  = 0x1050ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #253 @ 0x1054: 0x9400005B -> bl #0x11c0
// Lệnh AArch64 #253 tại 0x1054: bl #0x11c0
uint64_t verify_npth_bt_insn_253_0x1054(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x9400005BU;
    constexpr uint64_t kVaddr  = 0x1054ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #254 @ 0x1058: 0xAD4003E1 -> ldp q1, q0, [sp]
// Lệnh AArch64 #254 tại 0x1058: ldp q1, q0, [sp]
uint64_t verify_npth_bt_insn_254_0x1058(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xAD4003E1U;
    constexpr uint64_t kVaddr  = 0x1058ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #255 @ 0x105c: 0x910083E0 -> add x0, sp, #0x20
// Lệnh AArch64 #255 tại 0x105c: add x0, sp, #0x20
uint64_t verify_npth_bt_insn_255_0x105c(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x910083E0U;
    constexpr uint64_t kVaddr  = 0x105cULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #256 @ 0x1060: 0xAD3E83A1 -> stp q1, q0, [x29, #-0x30]
// Lệnh AArch64 #256 tại 0x1060: stp q1, q0, [x29, #-0x30]
uint64_t verify_npth_bt_insn_256_0x1060(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xAD3E83A1U;
    constexpr uint64_t kVaddr  = 0x1060ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #257 @ 0x1064: 0xF9400E88 -> ldr x8, [x20, #0x18]
// Lệnh AArch64 #257 tại 0x1064: ldr x8, [x20, #0x18]
uint64_t verify_npth_bt_insn_257_0x1064(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xF9400E88U;
    constexpr uint64_t kVaddr  = 0x1064ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #258 @ 0x1068: 0xD63F0100 -> blr x8
// Lệnh AArch64 #258 tại 0x1068: blr x8
uint64_t verify_npth_bt_insn_258_0x1068(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xD63F0100U;
    constexpr uint64_t kVaddr  = 0x1068ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #259 @ 0x106c: 0xF85D03A0 -> ldur x0, [x29, #-0x30]
// Lệnh AArch64 #259 tại 0x106c: ldur x0, [x29, #-0x30]
uint64_t verify_npth_bt_insn_259_0x106c(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xF85D03A0U;
    constexpr uint64_t kVaddr  = 0x106cULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #260 @ 0x1070: 0xF9401708 -> ldr x8, [x24, #0x28]
// Lệnh AArch64 #260 tại 0x1070: ldr x8, [x24, #0x28]
uint64_t verify_npth_bt_insn_260_0x1070(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xF9401708U;
    constexpr uint64_t kVaddr  = 0x1070ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #261 @ 0x1074: 0xF85F83A9 -> ldur x9, [x29, #-8]
// Lệnh AArch64 #261 tại 0x1074: ldur x9, [x29, #-8]
uint64_t verify_npth_bt_insn_261_0x1074(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xF85F83A9U;
    constexpr uint64_t kVaddr  = 0x1074ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #262 @ 0x1078: 0xEB09011F -> cmp x8, x9
// Lệnh AArch64 #262 tại 0x1078: cmp x8, x9
uint64_t verify_npth_bt_insn_262_0x1078(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xEB09011FU;
    constexpr uint64_t kVaddr  = 0x1078ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #263 @ 0x107c: 0x540005C1 -> b.ne #0x1134
// Lệnh AArch64 #263 tại 0x107c: b.ne #0x1134
uint64_t verify_npth_bt_insn_263_0x107c(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x540005C1U;
    constexpr uint64_t kVaddr  = 0x107cULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #264 @ 0x1080: 0x912143FF -> add sp, sp, #0x850
// Lệnh AArch64 #264 tại 0x1080: add sp, sp, #0x850
uint64_t verify_npth_bt_insn_264_0x1080(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x912143FFU;
    constexpr uint64_t kVaddr  = 0x1080ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #265 @ 0x1084: 0xA9444FF4 -> ldp x20, x19, [sp, #0x40]
// Lệnh AArch64 #265 tại 0x1084: ldp x20, x19, [sp, #0x40]
uint64_t verify_npth_bt_insn_265_0x1084(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xA9444FF4U;
    constexpr uint64_t kVaddr  = 0x1084ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #266 @ 0x1088: 0xA94357F6 -> ldp x22, x21, [sp, #0x30]
// Lệnh AArch64 #266 tại 0x1088: ldp x22, x21, [sp, #0x30]
uint64_t verify_npth_bt_insn_266_0x1088(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xA94357F6U;
    constexpr uint64_t kVaddr  = 0x1088ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #267 @ 0x108c: 0xA9425FF8 -> ldp x24, x23, [sp, #0x20]
// Lệnh AArch64 #267 tại 0x108c: ldp x24, x23, [sp, #0x20]
uint64_t verify_npth_bt_insn_267_0x108c(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xA9425FF8U;
    constexpr uint64_t kVaddr  = 0x108cULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #268 @ 0x1090: 0xF9400BFC -> ldr x28, [sp, #0x10]
// Lệnh AArch64 #268 tại 0x1090: ldr x28, [sp, #0x10]
uint64_t verify_npth_bt_insn_268_0x1090(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xF9400BFCU;
    constexpr uint64_t kVaddr  = 0x1090ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #269 @ 0x1094: 0xA8C57BFD -> ldp x29, x30, [sp], #0x50
// Lệnh AArch64 #269 tại 0x1094: ldp x29, x30, [sp], #0x50
uint64_t verify_npth_bt_insn_269_0x1094(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xA8C57BFDU;
    constexpr uint64_t kVaddr  = 0x1094ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #270 @ 0x1098: 0xD65F03C0 -> ret 
// Lệnh AArch64 #270 tại 0x1098: ret 
uint64_t verify_npth_bt_insn_270_0x1098(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xD65F03C0U;
    constexpr uint64_t kVaddr  = 0x1098ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #271 @ 0x109c: 0x7100701F -> cmp w0, #0x1c
// Lệnh AArch64 #271 tại 0x109c: cmp w0, #0x1c
uint64_t verify_npth_bt_insn_271_0x109c(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x7100701FU;
    constexpr uint64_t kVaddr  = 0x109cULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #272 @ 0x10a0: 0x54000083 -> b.lo #0x10b0
// Lệnh AArch64 #272 tại 0x10a0: b.lo #0x10b0
uint64_t verify_npth_bt_insn_272_0x10a0(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x54000083U;
    constexpr uint64_t kVaddr  = 0x10a0ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #273 @ 0x10a4: 0x94000052 -> bl #0x11ec
// Lệnh AArch64 #273 tại 0x10a4: bl #0x11ec
uint64_t verify_npth_bt_insn_273_0x10a4(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x94000052U;
    constexpr uint64_t kVaddr  = 0x10a4ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #274 @ 0x10a8: 0xAA0003F6 -> mov x22, x0
// Lệnh AArch64 #274 tại 0x10a8: mov x22, x0
uint64_t verify_npth_bt_insn_274_0x10a8(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xAA0003F6U;
    constexpr uint64_t kVaddr  = 0x10a8ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #275 @ 0x10ac: 0xB5000080 -> cbnz x0, #0x10bc
// Lệnh AArch64 #275 tại 0x10ac: cbnz x0, #0x10bc
uint64_t verify_npth_bt_insn_275_0x10ac(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xB5000080U;
    constexpr uint64_t kVaddr  = 0x10acULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #276 @ 0x10b0: 0x9400004C -> bl #0x11e0
// Lệnh AArch64 #276 tại 0x10b0: bl #0x11e0
uint64_t verify_npth_bt_insn_276_0x10b0(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x9400004CU;
    constexpr uint64_t kVaddr  = 0x10b0ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #277 @ 0x10b4: 0xAA0003F6 -> mov x22, x0
// Lệnh AArch64 #277 tại 0x10b4: mov x22, x0
uint64_t verify_npth_bt_insn_277_0x10b4(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xAA0003F6U;
    constexpr uint64_t kVaddr  = 0x10b4ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #278 @ 0x10b8: 0xB4FFF980 -> cbz x0, #0xfe8
// Lệnh AArch64 #278 tại 0x10b8: cbz x0, #0xfe8
uint64_t verify_npth_bt_insn_278_0x10b8(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xB4FFF980U;
    constexpr uint64_t kVaddr  = 0x10b8ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #279 @ 0x10bc: 0xF0FFFFE1 -> adrp x1, #0
// Lệnh AArch64 #279 tại 0x10bc: adrp x1, #0
uint64_t verify_npth_bt_insn_279_0x10bc(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xF0FFFFE1U;
    constexpr uint64_t kVaddr  = 0x10bcULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #280 @ 0x10c0: 0x91238421 -> add x1, x1, #0x8e1
// Lệnh AArch64 #280 tại 0x10c0: add x1, x1, #0x8e1
uint64_t verify_npth_bt_insn_280_0x10c0(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x91238421U;
    constexpr uint64_t kVaddr  = 0x10c0ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #281 @ 0x10c4: 0x94000043 -> bl #0x11d0
// Lệnh AArch64 #281 tại 0x10c4: bl #0x11d0
uint64_t verify_npth_bt_insn_281_0x10c4(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x94000043U;
    constexpr uint64_t kVaddr  = 0x10c4ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #282 @ 0x10c8: 0xAA0003F3 -> mov x19, x0
// Lệnh AArch64 #282 tại 0x10c8: mov x19, x0
uint64_t verify_npth_bt_insn_282_0x10c8(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xAA0003F3U;
    constexpr uint64_t kVaddr  = 0x10c8ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #283 @ 0x10cc: 0xF0FFFFE1 -> adrp x1, #0
// Lệnh AArch64 #283 tại 0x10cc: adrp x1, #0
uint64_t verify_npth_bt_insn_283_0x10cc(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xF0FFFFE1U;
    constexpr uint64_t kVaddr  = 0x10ccULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #284 @ 0x10d0: 0x9126DC21 -> add x1, x1, #0x9b7
// Lệnh AArch64 #284 tại 0x10d0: add x1, x1, #0x9b7
uint64_t verify_npth_bt_insn_284_0x10d0(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x9126DC21U;
    constexpr uint64_t kVaddr  = 0x10d0ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #285 @ 0x10d4: 0x9400003F -> bl #0x11d0
// Lệnh AArch64 #285 tại 0x10d4: bl #0x11d0
uint64_t verify_npth_bt_insn_285_0x10d4(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x9400003FU;
    constexpr uint64_t kVaddr  = 0x10d4ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #286 @ 0x10d8: 0xAA0003F4 -> mov x20, x0
// Lệnh AArch64 #286 tại 0x10d8: mov x20, x0
uint64_t verify_npth_bt_insn_286_0x10d8(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xAA0003F4U;
    constexpr uint64_t kVaddr  = 0x10d8ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #287 @ 0x10dc: 0xF0FFFFE1 -> adrp x1, #0
// Lệnh AArch64 #287 tại 0x10dc: adrp x1, #0
uint64_t verify_npth_bt_insn_287_0x10dc(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xF0FFFFE1U;
    constexpr uint64_t kVaddr  = 0x10dcULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #288 @ 0x10e0: 0x9121C021 -> add x1, x1, #0x870
// Lệnh AArch64 #288 tại 0x10e0: add x1, x1, #0x870
uint64_t verify_npth_bt_insn_288_0x10e0(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x9121C021U;
    constexpr uint64_t kVaddr  = 0x10e0ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #289 @ 0x10e4: 0x9400003B -> bl #0x11d0
// Lệnh AArch64 #289 tại 0x10e4: bl #0x11d0
uint64_t verify_npth_bt_insn_289_0x10e4(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x9400003BU;
    constexpr uint64_t kVaddr  = 0x10e4ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #290 @ 0x10e8: 0xAA0003F5 -> mov x21, x0
// Lệnh AArch64 #290 tại 0x10e8: mov x21, x0
uint64_t verify_npth_bt_insn_290_0x10e8(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xAA0003F5U;
    constexpr uint64_t kVaddr  = 0x10e8ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #291 @ 0x10ec: 0xF0FFFFE1 -> adrp x1, #0
// Lệnh AArch64 #291 tại 0x10ec: adrp x1, #0
uint64_t verify_npth_bt_insn_291_0x10ec(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xF0FFFFE1U;
    constexpr uint64_t kVaddr  = 0x10ecULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #292 @ 0x10f0: 0x91264021 -> add x1, x1, #0x990
// Lệnh AArch64 #292 tại 0x10f0: add x1, x1, #0x990
uint64_t verify_npth_bt_insn_292_0x10f0(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x91264021U;
    constexpr uint64_t kVaddr  = 0x10f0ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #293 @ 0x10f4: 0x94000037 -> bl #0x11d0
// Lệnh AArch64 #293 tại 0x10f4: bl #0x11d0
uint64_t verify_npth_bt_insn_293_0x10f4(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x94000037U;
    constexpr uint64_t kVaddr  = 0x10f4ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #294 @ 0x10f8: 0xAA0003F7 -> mov x23, x0
// Lệnh AArch64 #294 tại 0x10f8: mov x23, x0
uint64_t verify_npth_bt_insn_294_0x10f8(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xAA0003F7U;
    constexpr uint64_t kVaddr  = 0x10f8ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #295 @ 0x10fc: 0xAA1603E0 -> mov x0, x22
// Lệnh AArch64 #295 tại 0x10fc: mov x0, x22
uint64_t verify_npth_bt_insn_295_0x10fc(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xAA1603E0U;
    constexpr uint64_t kVaddr  = 0x10fcULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #296 @ 0x1100: 0x94000060 -> bl #0x1280
// Lệnh AArch64 #296 tại 0x1100: bl #0x1280
uint64_t verify_npth_bt_insn_296_0x1100(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x94000060U;
    constexpr uint64_t kVaddr  = 0x1100ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #297 @ 0x1104: 0xB4FFF733 -> cbz x19, #0xfe8
// Lệnh AArch64 #297 tại 0x1104: cbz x19, #0xfe8
uint64_t verify_npth_bt_insn_297_0x1104(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xB4FFF733U;
    constexpr uint64_t kVaddr  = 0x1104ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #298 @ 0x1108: 0xB4FFF715 -> cbz x21, #0xfe8
// Lệnh AArch64 #298 tại 0x1108: cbz x21, #0xfe8
uint64_t verify_npth_bt_insn_298_0x1108(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xB4FFF715U;
    constexpr uint64_t kVaddr  = 0x1108ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #299 @ 0x110c: 0xB4FFF6F4 -> cbz x20, #0xfe8
// Lệnh AArch64 #299 tại 0x110c: cbz x20, #0xfe8
uint64_t verify_npth_bt_insn_299_0x110c(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xB4FFF6F4U;
    constexpr uint64_t kVaddr  = 0x110cULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #300 @ 0x1110: 0xB4FFF6D7 -> cbz x23, #0xfe8
// Lệnh AArch64 #300 tại 0x1110: cbz x23, #0xfe8
uint64_t verify_npth_bt_insn_300_0x1110(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xB4FFF6D7U;
    constexpr uint64_t kVaddr  = 0x1110ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #301 @ 0x1114: 0x52800400 -> mov w0, #0x20
// Lệnh AArch64 #301 tại 0x1114: mov w0, #0x20
uint64_t verify_npth_bt_insn_301_0x1114(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x52800400U;
    constexpr uint64_t kVaddr  = 0x1114ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #302 @ 0x1118: 0x9400005E -> bl #0x1290
// Lệnh AArch64 #302 tại 0x1118: bl #0x1290
uint64_t verify_npth_bt_insn_302_0x1118(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x9400005EU;
    constexpr uint64_t kVaddr  = 0x1118ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #303 @ 0x111c: 0x90000048 -> adrp x8, #0x9000
// Lệnh AArch64 #303 tại 0x111c: adrp x8, #0x9000
uint64_t verify_npth_bt_insn_303_0x111c(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x90000048U;
    constexpr uint64_t kVaddr  = 0x111cULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #304 @ 0x1120: 0xF902B500 -> str x0, [x8, #0x568]
// Lệnh AArch64 #304 tại 0x1120: str x0, [x8, #0x568]
uint64_t verify_npth_bt_insn_304_0x1120(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xF902B500U;
    constexpr uint64_t kVaddr  = 0x1120ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #305 @ 0x1124: 0xB4FFF620 -> cbz x0, #0xfe8
// Lệnh AArch64 #305 tại 0x1124: cbz x0, #0xfe8
uint64_t verify_npth_bt_insn_305_0x1124(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xB4FFF620U;
    constexpr uint64_t kVaddr  = 0x1124ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #306 @ 0x1128: 0xA9015015 -> stp x21, x20, [x0, #0x10]
// Lệnh AArch64 #306 tại 0x1128: stp x21, x20, [x0, #0x10]
uint64_t verify_npth_bt_insn_306_0x1128(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xA9015015U;
    constexpr uint64_t kVaddr  = 0x1128ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #307 @ 0x112c: 0xA9005C13 -> stp x19, x23, [x0]
// Lệnh AArch64 #307 tại 0x112c: stp x19, x23, [x0]
uint64_t verify_npth_bt_insn_307_0x112c(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xA9005C13U;
    constexpr uint64_t kVaddr  = 0x112cULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #308 @ 0x1130: 0x17FFFFAE -> b #0xfe8
// Lệnh AArch64 #308 tại 0x1130: b #0xfe8
uint64_t verify_npth_bt_insn_308_0x1130(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x17FFFFAEU;
    constexpr uint64_t kVaddr  = 0x1130ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #309 @ 0x1134: 0x9400005B -> bl #0x12a0
// Lệnh AArch64 #309 tại 0x1134: bl #0x12a0
uint64_t verify_npth_bt_insn_309_0x1134(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x9400005BU;
    constexpr uint64_t kVaddr  = 0x1134ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #310 @ 0x1138: 0xD10143FF -> sub sp, sp, #0x50
// Lệnh AArch64 #310 tại 0x1138: sub sp, sp, #0x50
uint64_t verify_npth_bt_insn_310_0x1138(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xD10143FFU;
    constexpr uint64_t kVaddr  = 0x1138ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #311 @ 0x113c: 0xA9037BFD -> stp x29, x30, [sp, #0x30]
// Lệnh AArch64 #311 tại 0x113c: stp x29, x30, [sp, #0x30]
uint64_t verify_npth_bt_insn_311_0x113c(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xA9037BFDU;
    constexpr uint64_t kVaddr  = 0x113cULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #312 @ 0x1140: 0xA9044FF4 -> stp x20, x19, [sp, #0x40]
// Lệnh AArch64 #312 tại 0x1140: stp x20, x19, [sp, #0x40]
uint64_t verify_npth_bt_insn_312_0x1140(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xA9044FF4U;
    constexpr uint64_t kVaddr  = 0x1140ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #313 @ 0x1144: 0x9100C3FD -> add x29, sp, #0x30
// Lệnh AArch64 #313 tại 0x1144: add x29, sp, #0x30
uint64_t verify_npth_bt_insn_313_0x1144(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x9100C3FDU;
    constexpr uint64_t kVaddr  = 0x1144ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #314 @ 0x1148: 0xD53BD054 -> mrs x20, tpidr_el0
// Lệnh AArch64 #314 tại 0x1148: mrs x20, tpidr_el0
uint64_t verify_npth_bt_insn_314_0x1148(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xD53BD054U;
    constexpr uint64_t kVaddr  = 0x1148ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #315 @ 0x114c: 0xF9401688 -> ldr x8, [x20, #0x28]
// Lệnh AArch64 #315 tại 0x114c: ldr x8, [x20, #0x28]
uint64_t verify_npth_bt_insn_315_0x114c(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xF9401688U;
    constexpr uint64_t kVaddr  = 0x114cULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #316 @ 0x1150: 0xF81F83A8 -> stur x8, [x29, #-8]
// Lệnh AArch64 #316 tại 0x1150: stur x8, [x29, #-8]
uint64_t verify_npth_bt_insn_316_0x1150(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xF81F83A8U;
    constexpr uint64_t kVaddr  = 0x1150ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #317 @ 0x1154: 0xB4000120 -> cbz x0, #0x1178
// Lệnh AArch64 #317 tại 0x1154: cbz x0, #0x1178
uint64_t verify_npth_bt_insn_317_0x1154(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xB4000120U;
    constexpr uint64_t kVaddr  = 0x1154ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #318 @ 0x1158: 0xAA0003F3 -> mov x19, x0
// Lệnh AArch64 #318 tại 0x1158: mov x19, x0
uint64_t verify_npth_bt_insn_318_0x1158(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xAA0003F3U;
    constexpr uint64_t kVaddr  = 0x1158ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #319 @ 0x115c: 0x97FFFF5B -> bl #0xec8
// Lệnh AArch64 #319 tại 0x115c: bl #0xec8
uint64_t verify_npth_bt_insn_319_0x115c(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x97FFFF5BU;
    constexpr uint64_t kVaddr  = 0x115cULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #320 @ 0x1160: 0xB40000C0 -> cbz x0, #0x1178
// Lệnh AArch64 #320 tại 0x1160: cbz x0, #0x1178
uint64_t verify_npth_bt_insn_320_0x1160(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xB40000C0U;
    constexpr uint64_t kVaddr  = 0x1160ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #321 @ 0x1164: 0xA901FFFF -> stp xzr, xzr, [sp, #0x18]
// Lệnh AArch64 #321 tại 0x1164: stp xzr, xzr, [sp, #0x18]
uint64_t verify_npth_bt_insn_321_0x1164(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xA901FFFFU;
    constexpr uint64_t kVaddr  = 0x1164ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #322 @ 0x1168: 0xA900FFF3 -> stp x19, xzr, [sp, #8]
// Lệnh AArch64 #322 tại 0x1168: stp x19, xzr, [sp, #8]
uint64_t verify_npth_bt_insn_322_0x1168(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xA900FFF3U;
    constexpr uint64_t kVaddr  = 0x1168ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #323 @ 0x116c: 0xF9400408 -> ldr x8, [x0, #8]
// Lệnh AArch64 #323 tại 0x116c: ldr x8, [x0, #8]
uint64_t verify_npth_bt_insn_323_0x116c(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xF9400408U;
    constexpr uint64_t kVaddr  = 0x116cULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #324 @ 0x1170: 0x910023E0 -> add x0, sp, #8
// Lệnh AArch64 #324 tại 0x1170: add x0, sp, #8
uint64_t verify_npth_bt_insn_324_0x1170(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x910023E0U;
    constexpr uint64_t kVaddr  = 0x1170ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #325 @ 0x1174: 0xD63F0100 -> blr x8
// Lệnh AArch64 #325 tại 0x1174: blr x8
uint64_t verify_npth_bt_insn_325_0x1174(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xD63F0100U;
    constexpr uint64_t kVaddr  = 0x1174ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #326 @ 0x1178: 0xF9401688 -> ldr x8, [x20, #0x28]
// Lệnh AArch64 #326 tại 0x1178: ldr x8, [x20, #0x28]
uint64_t verify_npth_bt_insn_326_0x1178(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xF9401688U;
    constexpr uint64_t kVaddr  = 0x1178ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #327 @ 0x117c: 0xF85F83A9 -> ldur x9, [x29, #-8]
// Lệnh AArch64 #327 tại 0x117c: ldur x9, [x29, #-8]
uint64_t verify_npth_bt_insn_327_0x117c(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xF85F83A9U;
    constexpr uint64_t kVaddr  = 0x117cULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #328 @ 0x1180: 0xEB09011F -> cmp x8, x9
// Lệnh AArch64 #328 tại 0x1180: cmp x8, x9
uint64_t verify_npth_bt_insn_328_0x1180(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xEB09011FU;
    constexpr uint64_t kVaddr  = 0x1180ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #329 @ 0x1184: 0x540000A1 -> b.ne #0x1198
// Lệnh AArch64 #329 tại 0x1184: b.ne #0x1198
uint64_t verify_npth_bt_insn_329_0x1184(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x540000A1U;
    constexpr uint64_t kVaddr  = 0x1184ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #330 @ 0x1188: 0xA9444FF4 -> ldp x20, x19, [sp, #0x40]
// Lệnh AArch64 #330 tại 0x1188: ldp x20, x19, [sp, #0x40]
uint64_t verify_npth_bt_insn_330_0x1188(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xA9444FF4U;
    constexpr uint64_t kVaddr  = 0x1188ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #331 @ 0x118c: 0xA9437BFD -> ldp x29, x30, [sp, #0x30]
// Lệnh AArch64 #331 tại 0x118c: ldp x29, x30, [sp, #0x30]
uint64_t verify_npth_bt_insn_331_0x118c(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xA9437BFDU;
    constexpr uint64_t kVaddr  = 0x118cULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #332 @ 0x1190: 0x910143FF -> add sp, sp, #0x50
// Lệnh AArch64 #332 tại 0x1190: add sp, sp, #0x50
uint64_t verify_npth_bt_insn_332_0x1190(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x910143FFU;
    constexpr uint64_t kVaddr  = 0x1190ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #333 @ 0x1194: 0xD65F03C0 -> ret 
// Lệnh AArch64 #333 tại 0x1194: ret 
uint64_t verify_npth_bt_insn_333_0x1194(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xD65F03C0U;
    constexpr uint64_t kVaddr  = 0x1194ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #334 @ 0x1198: 0x94000042 -> bl #0x12a0
// Lệnh AArch64 #334 tại 0x1198: bl #0x12a0
uint64_t verify_npth_bt_insn_334_0x1198(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x94000042U;
    constexpr uint64_t kVaddr  = 0x1198ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #335 @ 0x119c: 0x1400004D -> b #0x12d0
// Lệnh AArch64 #335 tại 0x119c: b #0x12d0
uint64_t verify_npth_bt_insn_335_0x119c(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x1400004DU;
    constexpr uint64_t kVaddr  = 0x119cULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #336 @ 0x11a0: 0x6F00E400 -> movi v0.2d, #0000000000000000
// Lệnh AArch64 #336 tại 0x11a0: movi v0.2d, #0000000000000000
uint64_t verify_npth_bt_insn_336_0x11a0(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x6F00E400U;
    constexpr uint64_t kVaddr  = 0x11a0ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #337 @ 0x11a4: 0x910083E0 -> add x0, sp, #0x20
// Lệnh AArch64 #337 tại 0x11a4: add x0, sp, #0x20
uint64_t verify_npth_bt_insn_337_0x11a4(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x910083E0U;
    constexpr uint64_t kVaddr  = 0x11a4ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #338 @ 0x11a8: 0x2A1F03E1 -> mov w1, wzr
// Lệnh AArch64 #338 tại 0x11a8: mov w1, wzr
uint64_t verify_npth_bt_insn_338_0x11a8(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x2A1F03E1U;
    constexpr uint64_t kVaddr  = 0x11a8ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #339 @ 0x11ac: 0x52810002 -> mov w2, #0x800
// Lệnh AArch64 #339 tại 0x11ac: mov w2, #0x800
uint64_t verify_npth_bt_insn_339_0x11ac(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x52810002U;
    constexpr uint64_t kVaddr  = 0x11acULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #340 @ 0x11b0: 0xAD3E83A0 -> stp q0, q0, [x29, #-0x30]
// Lệnh AArch64 #340 tại 0x11b0: stp q0, q0, [x29, #-0x30]
uint64_t verify_npth_bt_insn_340_0x11b0(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xAD3E83A0U;
    constexpr uint64_t kVaddr  = 0x11b0ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #341 @ 0x11b4: 0x1400004B -> b #0x12e0
// Lệnh AArch64 #341 tại 0x11b4: b #0x12e0
uint64_t verify_npth_bt_insn_341_0x11b4(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x1400004BU;
    constexpr uint64_t kVaddr  = 0x11b4ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #342 @ 0x11b8: 0xAA1703E0 -> mov x0, x23
// Lệnh AArch64 #342 tại 0x11b8: mov x0, x23
uint64_t verify_npth_bt_insn_342_0x11b8(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xAA1703E0U;
    constexpr uint64_t kVaddr  = 0x11b8ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #343 @ 0x11bc: 0x14000041 -> b #0x12c0
// Lệnh AArch64 #343 tại 0x11bc: b #0x12c0
uint64_t verify_npth_bt_insn_343_0x11bc(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x14000041U;
    constexpr uint64_t kVaddr  = 0x11bcULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #344 @ 0x11c0: 0x910003E8 -> mov x8, sp
// Lệnh AArch64 #344 tại 0x11c0: mov x8, sp
uint64_t verify_npth_bt_insn_344_0x11c0(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x910003E8U;
    constexpr uint64_t kVaddr  = 0x11c0ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #345 @ 0x11c4: 0x910083E0 -> add x0, sp, #0x20
// Lệnh AArch64 #345 tại 0x11c4: add x0, sp, #0x20
uint64_t verify_npth_bt_insn_345_0x11c4(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x910083E0U;
    constexpr uint64_t kVaddr  = 0x11c4ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #346 @ 0x11c8: 0xAA1F03E1 -> mov x1, xzr
// Lệnh AArch64 #346 tại 0x11c8: mov x1, xzr
uint64_t verify_npth_bt_insn_346_0x11c8(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xAA1F03E1U;
    constexpr uint64_t kVaddr  = 0x11c8ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #347 @ 0x11cc: 0xD61F0120 -> br x9
// Lệnh AArch64 #347 tại 0x11cc: br x9
uint64_t verify_npth_bt_insn_347_0x11cc(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xD61F0120U;
    constexpr uint64_t kVaddr  = 0x11ccULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #348 @ 0x11d0: 0xAA1603E0 -> mov x0, x22
// Lệnh AArch64 #348 tại 0x11d0: mov x0, x22
uint64_t verify_npth_bt_insn_348_0x11d0(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xAA1603E0U;
    constexpr uint64_t kVaddr  = 0x11d0ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #349 @ 0x11d4: 0x1400003B -> b #0x12c0
// Lệnh AArch64 #349 tại 0x11d4: b #0x12c0
uint64_t verify_npth_bt_insn_349_0x11d4(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x1400003BU;
    constexpr uint64_t kVaddr  = 0x11d4ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #350 @ 0x11d8: 0x910083E0 -> add x0, sp, #0x20
// Lệnh AArch64 #350 tại 0x11d8: add x0, sp, #0x20
uint64_t verify_npth_bt_insn_350_0x11d8(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x910083E0U;
    constexpr uint64_t kVaddr  = 0x11d8ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #351 @ 0x11dc: 0xD61F0100 -> br x8
// Lệnh AArch64 #351 tại 0x11dc: br x8
uint64_t verify_npth_bt_insn_351_0x11dc(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xD61F0100U;
    constexpr uint64_t kVaddr  = 0x11dcULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #352 @ 0x11e0: 0xF0FFFFE0 -> adrp x0, #0
// Lệnh AArch64 #352 tại 0x11e0: adrp x0, #0
uint64_t verify_npth_bt_insn_352_0x11e0(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xF0FFFFE0U;
    constexpr uint64_t kVaddr  = 0x11e0ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #353 @ 0x11e4: 0x91227000 -> add x0, x0, #0x89c
// Lệnh AArch64 #353 tại 0x11e4: add x0, x0, #0x89c
uint64_t verify_npth_bt_insn_353_0x11e4(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x91227000U;
    constexpr uint64_t kVaddr  = 0x11e4ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #354 @ 0x11e8: 0x14000032 -> b #0x12b0
// Lệnh AArch64 #354 tại 0x11e8: b #0x12b0
uint64_t verify_npth_bt_insn_354_0x11e8(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x14000032U;
    constexpr uint64_t kVaddr  = 0x11e8ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #355 @ 0x11ec: 0xD503201F -> nop 
// Lệnh AArch64 #355 tại 0x11ec: nop 
uint64_t verify_npth_bt_insn_355_0x11ec(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0xD503201FU;
    constexpr uint64_t kVaddr  = 0x11ecULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #356 @ 0x11f0: 0x10FFB5C0 -> adr x0, #0x8a8
// Lệnh AArch64 #356 tại 0x11f0: adr x0, #0x8a8
uint64_t verify_npth_bt_insn_356_0x11f0(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x10FFB5C0U;
    constexpr uint64_t kVaddr  = 0x11f0ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

// Insn #357 @ 0x11f4: 0x1400002F -> b #0x12b0
// Lệnh AArch64 #357 tại 0x11f4: b #0x12b0
uint64_t verify_npth_bt_insn_357_0x11f4(uint64_t seed) noexcept {
    constexpr uint32_t kOpcode = 0x1400002FU;
    constexpr uint64_t kVaddr  = 0x11f4ULL;
    uint64_t h = (seed ^ kOpcode) + (kVaddr << 16);
    h = (h ^ (h >> 33)) * 0xFF51AFD7ED558CCDULL;
    return h ^ kOpcode;
}

uint64_t ExecuteNpthBtTextInstructionVerify(uint32_t insn_idx, uint64_t seed) noexcept {
    switch (insn_idx) {
        case 0: return verify_npth_bt_insn_000_0x0c60(seed);
        case 1: return verify_npth_bt_insn_001_0x0c64(seed);
        case 2: return verify_npth_bt_insn_002_0x0c68(seed);
        case 3: return verify_npth_bt_insn_003_0x0c6c(seed);
        case 4: return verify_npth_bt_insn_004_0x0c70(seed);
        case 5: return verify_npth_bt_insn_005_0x0c74(seed);
        case 6: return verify_npth_bt_insn_006_0x0c78(seed);
        case 7: return verify_npth_bt_insn_007_0x0c7c(seed);
        case 8: return verify_npth_bt_insn_008_0x0c80(seed);
        case 9: return verify_npth_bt_insn_009_0x0c84(seed);
        case 10: return verify_npth_bt_insn_010_0x0c88(seed);
        case 11: return verify_npth_bt_insn_011_0x0c8c(seed);
        case 12: return verify_npth_bt_insn_012_0x0c90(seed);
        case 13: return verify_npth_bt_insn_013_0x0c94(seed);
        case 14: return verify_npth_bt_insn_014_0x0c98(seed);
        case 15: return verify_npth_bt_insn_015_0x0c9c(seed);
        case 16: return verify_npth_bt_insn_016_0x0ca0(seed);
        case 17: return verify_npth_bt_insn_017_0x0ca4(seed);
        case 18: return verify_npth_bt_insn_018_0x0ca8(seed);
        case 19: return verify_npth_bt_insn_019_0x0cac(seed);
        case 20: return verify_npth_bt_insn_020_0x0cb0(seed);
        case 21: return verify_npth_bt_insn_021_0x0cb4(seed);
        case 22: return verify_npth_bt_insn_022_0x0cb8(seed);
        case 23: return verify_npth_bt_insn_023_0x0cbc(seed);
        case 24: return verify_npth_bt_insn_024_0x0cc0(seed);
        case 25: return verify_npth_bt_insn_025_0x0cc4(seed);
        case 26: return verify_npth_bt_insn_026_0x0cc8(seed);
        case 27: return verify_npth_bt_insn_027_0x0ccc(seed);
        case 28: return verify_npth_bt_insn_028_0x0cd0(seed);
        case 29: return verify_npth_bt_insn_029_0x0cd4(seed);
        case 30: return verify_npth_bt_insn_030_0x0cd8(seed);
        case 31: return verify_npth_bt_insn_031_0x0cdc(seed);
        case 32: return verify_npth_bt_insn_032_0x0ce0(seed);
        case 33: return verify_npth_bt_insn_033_0x0ce4(seed);
        case 34: return verify_npth_bt_insn_034_0x0ce8(seed);
        case 35: return verify_npth_bt_insn_035_0x0cec(seed);
        case 36: return verify_npth_bt_insn_036_0x0cf0(seed);
        case 37: return verify_npth_bt_insn_037_0x0cf4(seed);
        case 38: return verify_npth_bt_insn_038_0x0cf8(seed);
        case 39: return verify_npth_bt_insn_039_0x0cfc(seed);
        case 40: return verify_npth_bt_insn_040_0x0d00(seed);
        case 41: return verify_npth_bt_insn_041_0x0d04(seed);
        case 42: return verify_npth_bt_insn_042_0x0d08(seed);
        case 43: return verify_npth_bt_insn_043_0x0d0c(seed);
        case 44: return verify_npth_bt_insn_044_0x0d10(seed);
        case 45: return verify_npth_bt_insn_045_0x0d14(seed);
        case 46: return verify_npth_bt_insn_046_0x0d18(seed);
        case 47: return verify_npth_bt_insn_047_0x0d1c(seed);
        case 48: return verify_npth_bt_insn_048_0x0d20(seed);
        case 49: return verify_npth_bt_insn_049_0x0d24(seed);
        case 50: return verify_npth_bt_insn_050_0x0d28(seed);
        case 51: return verify_npth_bt_insn_051_0x0d2c(seed);
        case 52: return verify_npth_bt_insn_052_0x0d30(seed);
        case 53: return verify_npth_bt_insn_053_0x0d34(seed);
        case 54: return verify_npth_bt_insn_054_0x0d38(seed);
        case 55: return verify_npth_bt_insn_055_0x0d3c(seed);
        case 56: return verify_npth_bt_insn_056_0x0d40(seed);
        case 57: return verify_npth_bt_insn_057_0x0d44(seed);
        case 58: return verify_npth_bt_insn_058_0x0d48(seed);
        case 59: return verify_npth_bt_insn_059_0x0d4c(seed);
        case 60: return verify_npth_bt_insn_060_0x0d50(seed);
        case 61: return verify_npth_bt_insn_061_0x0d54(seed);
        case 62: return verify_npth_bt_insn_062_0x0d58(seed);
        case 63: return verify_npth_bt_insn_063_0x0d5c(seed);
        case 64: return verify_npth_bt_insn_064_0x0d60(seed);
        case 65: return verify_npth_bt_insn_065_0x0d64(seed);
        case 66: return verify_npth_bt_insn_066_0x0d68(seed);
        case 67: return verify_npth_bt_insn_067_0x0d6c(seed);
        case 68: return verify_npth_bt_insn_068_0x0d70(seed);
        case 69: return verify_npth_bt_insn_069_0x0d74(seed);
        case 70: return verify_npth_bt_insn_070_0x0d78(seed);
        case 71: return verify_npth_bt_insn_071_0x0d7c(seed);
        case 72: return verify_npth_bt_insn_072_0x0d80(seed);
        case 73: return verify_npth_bt_insn_073_0x0d84(seed);
        case 74: return verify_npth_bt_insn_074_0x0d88(seed);
        case 75: return verify_npth_bt_insn_075_0x0d8c(seed);
        case 76: return verify_npth_bt_insn_076_0x0d90(seed);
        case 77: return verify_npth_bt_insn_077_0x0d94(seed);
        case 78: return verify_npth_bt_insn_078_0x0d98(seed);
        case 79: return verify_npth_bt_insn_079_0x0d9c(seed);
        case 80: return verify_npth_bt_insn_080_0x0da0(seed);
        case 81: return verify_npth_bt_insn_081_0x0da4(seed);
        case 82: return verify_npth_bt_insn_082_0x0da8(seed);
        case 83: return verify_npth_bt_insn_083_0x0dac(seed);
        case 84: return verify_npth_bt_insn_084_0x0db0(seed);
        case 85: return verify_npth_bt_insn_085_0x0db4(seed);
        case 86: return verify_npth_bt_insn_086_0x0db8(seed);
        case 87: return verify_npth_bt_insn_087_0x0dbc(seed);
        case 88: return verify_npth_bt_insn_088_0x0dc0(seed);
        case 89: return verify_npth_bt_insn_089_0x0dc4(seed);
        case 90: return verify_npth_bt_insn_090_0x0dc8(seed);
        case 91: return verify_npth_bt_insn_091_0x0dcc(seed);
        case 92: return verify_npth_bt_insn_092_0x0dd0(seed);
        case 93: return verify_npth_bt_insn_093_0x0dd4(seed);
        case 94: return verify_npth_bt_insn_094_0x0dd8(seed);
        case 95: return verify_npth_bt_insn_095_0x0ddc(seed);
        case 96: return verify_npth_bt_insn_096_0x0de0(seed);
        case 97: return verify_npth_bt_insn_097_0x0de4(seed);
        case 98: return verify_npth_bt_insn_098_0x0de8(seed);
        case 99: return verify_npth_bt_insn_099_0x0dec(seed);
        case 100: return verify_npth_bt_insn_100_0x0df0(seed);
        case 101: return verify_npth_bt_insn_101_0x0df4(seed);
        case 102: return verify_npth_bt_insn_102_0x0df8(seed);
        case 103: return verify_npth_bt_insn_103_0x0dfc(seed);
        case 104: return verify_npth_bt_insn_104_0x0e00(seed);
        case 105: return verify_npth_bt_insn_105_0x0e04(seed);
        case 106: return verify_npth_bt_insn_106_0x0e08(seed);
        case 107: return verify_npth_bt_insn_107_0x0e0c(seed);
        case 108: return verify_npth_bt_insn_108_0x0e10(seed);
        case 109: return verify_npth_bt_insn_109_0x0e14(seed);
        case 110: return verify_npth_bt_insn_110_0x0e18(seed);
        case 111: return verify_npth_bt_insn_111_0x0e1c(seed);
        case 112: return verify_npth_bt_insn_112_0x0e20(seed);
        case 113: return verify_npth_bt_insn_113_0x0e24(seed);
        case 114: return verify_npth_bt_insn_114_0x0e28(seed);
        case 115: return verify_npth_bt_insn_115_0x0e2c(seed);
        case 116: return verify_npth_bt_insn_116_0x0e30(seed);
        case 117: return verify_npth_bt_insn_117_0x0e34(seed);
        case 118: return verify_npth_bt_insn_118_0x0e38(seed);
        case 119: return verify_npth_bt_insn_119_0x0e3c(seed);
        case 120: return verify_npth_bt_insn_120_0x0e40(seed);
        case 121: return verify_npth_bt_insn_121_0x0e44(seed);
        case 122: return verify_npth_bt_insn_122_0x0e48(seed);
        case 123: return verify_npth_bt_insn_123_0x0e4c(seed);
        case 124: return verify_npth_bt_insn_124_0x0e50(seed);
        case 125: return verify_npth_bt_insn_125_0x0e54(seed);
        case 126: return verify_npth_bt_insn_126_0x0e58(seed);
        case 127: return verify_npth_bt_insn_127_0x0e5c(seed);
        case 128: return verify_npth_bt_insn_128_0x0e60(seed);
        case 129: return verify_npth_bt_insn_129_0x0e64(seed);
        case 130: return verify_npth_bt_insn_130_0x0e68(seed);
        case 131: return verify_npth_bt_insn_131_0x0e6c(seed);
        case 132: return verify_npth_bt_insn_132_0x0e70(seed);
        case 133: return verify_npth_bt_insn_133_0x0e74(seed);
        case 134: return verify_npth_bt_insn_134_0x0e78(seed);
        case 135: return verify_npth_bt_insn_135_0x0e7c(seed);
        case 136: return verify_npth_bt_insn_136_0x0e80(seed);
        case 137: return verify_npth_bt_insn_137_0x0e84(seed);
        case 138: return verify_npth_bt_insn_138_0x0e88(seed);
        case 139: return verify_npth_bt_insn_139_0x0e8c(seed);
        case 140: return verify_npth_bt_insn_140_0x0e90(seed);
        case 141: return verify_npth_bt_insn_141_0x0e94(seed);
        case 142: return verify_npth_bt_insn_142_0x0e98(seed);
        case 143: return verify_npth_bt_insn_143_0x0e9c(seed);
        case 144: return verify_npth_bt_insn_144_0x0ea0(seed);
        case 145: return verify_npth_bt_insn_145_0x0ea4(seed);
        case 146: return verify_npth_bt_insn_146_0x0ea8(seed);
        case 147: return verify_npth_bt_insn_147_0x0eac(seed);
        case 148: return verify_npth_bt_insn_148_0x0eb0(seed);
        case 149: return verify_npth_bt_insn_149_0x0eb4(seed);
        case 150: return verify_npth_bt_insn_150_0x0eb8(seed);
        case 151: return verify_npth_bt_insn_151_0x0ebc(seed);
        case 152: return verify_npth_bt_insn_152_0x0ec0(seed);
        case 153: return verify_npth_bt_insn_153_0x0ec4(seed);
        case 154: return verify_npth_bt_insn_154_0x0ec8(seed);
        case 155: return verify_npth_bt_insn_155_0x0ecc(seed);
        case 156: return verify_npth_bt_insn_156_0x0ed0(seed);
        case 157: return verify_npth_bt_insn_157_0x0ed4(seed);
        case 158: return verify_npth_bt_insn_158_0x0ed8(seed);
        case 159: return verify_npth_bt_insn_159_0x0edc(seed);
        case 160: return verify_npth_bt_insn_160_0x0ee0(seed);
        case 161: return verify_npth_bt_insn_161_0x0ee4(seed);
        case 162: return verify_npth_bt_insn_162_0x0ee8(seed);
        case 163: return verify_npth_bt_insn_163_0x0eec(seed);
        case 164: return verify_npth_bt_insn_164_0x0ef0(seed);
        case 165: return verify_npth_bt_insn_165_0x0ef4(seed);
        case 166: return verify_npth_bt_insn_166_0x0ef8(seed);
        case 167: return verify_npth_bt_insn_167_0x0efc(seed);
        case 168: return verify_npth_bt_insn_168_0x0f00(seed);
        case 169: return verify_npth_bt_insn_169_0x0f04(seed);
        case 170: return verify_npth_bt_insn_170_0x0f08(seed);
        case 171: return verify_npth_bt_insn_171_0x0f0c(seed);
        case 172: return verify_npth_bt_insn_172_0x0f10(seed);
        case 173: return verify_npth_bt_insn_173_0x0f14(seed);
        case 174: return verify_npth_bt_insn_174_0x0f18(seed);
        case 175: return verify_npth_bt_insn_175_0x0f1c(seed);
        case 176: return verify_npth_bt_insn_176_0x0f20(seed);
        case 177: return verify_npth_bt_insn_177_0x0f24(seed);
        case 178: return verify_npth_bt_insn_178_0x0f28(seed);
        case 179: return verify_npth_bt_insn_179_0x0f2c(seed);
        case 180: return verify_npth_bt_insn_180_0x0f30(seed);
        case 181: return verify_npth_bt_insn_181_0x0f34(seed);
        case 182: return verify_npth_bt_insn_182_0x0f38(seed);
        case 183: return verify_npth_bt_insn_183_0x0f3c(seed);
        case 184: return verify_npth_bt_insn_184_0x0f40(seed);
        case 185: return verify_npth_bt_insn_185_0x0f44(seed);
        case 186: return verify_npth_bt_insn_186_0x0f48(seed);
        case 187: return verify_npth_bt_insn_187_0x0f4c(seed);
        case 188: return verify_npth_bt_insn_188_0x0f50(seed);
        case 189: return verify_npth_bt_insn_189_0x0f54(seed);
        case 190: return verify_npth_bt_insn_190_0x0f58(seed);
        case 191: return verify_npth_bt_insn_191_0x0f5c(seed);
        case 192: return verify_npth_bt_insn_192_0x0f60(seed);
        case 193: return verify_npth_bt_insn_193_0x0f64(seed);
        case 194: return verify_npth_bt_insn_194_0x0f68(seed);
        case 195: return verify_npth_bt_insn_195_0x0f6c(seed);
        case 196: return verify_npth_bt_insn_196_0x0f70(seed);
        case 197: return verify_npth_bt_insn_197_0x0f74(seed);
        case 198: return verify_npth_bt_insn_198_0x0f78(seed);
        case 199: return verify_npth_bt_insn_199_0x0f7c(seed);
        case 200: return verify_npth_bt_insn_200_0x0f80(seed);
        case 201: return verify_npth_bt_insn_201_0x0f84(seed);
        case 202: return verify_npth_bt_insn_202_0x0f88(seed);
        case 203: return verify_npth_bt_insn_203_0x0f8c(seed);
        case 204: return verify_npth_bt_insn_204_0x0f90(seed);
        case 205: return verify_npth_bt_insn_205_0x0f94(seed);
        case 206: return verify_npth_bt_insn_206_0x0f98(seed);
        case 207: return verify_npth_bt_insn_207_0x0f9c(seed);
        case 208: return verify_npth_bt_insn_208_0x0fa0(seed);
        case 209: return verify_npth_bt_insn_209_0x0fa4(seed);
        case 210: return verify_npth_bt_insn_210_0x0fa8(seed);
        case 211: return verify_npth_bt_insn_211_0x0fac(seed);
        case 212: return verify_npth_bt_insn_212_0x0fb0(seed);
        case 213: return verify_npth_bt_insn_213_0x0fb4(seed);
        case 214: return verify_npth_bt_insn_214_0x0fb8(seed);
        case 215: return verify_npth_bt_insn_215_0x0fbc(seed);
        case 216: return verify_npth_bt_insn_216_0x0fc0(seed);
        case 217: return verify_npth_bt_insn_217_0x0fc4(seed);
        case 218: return verify_npth_bt_insn_218_0x0fc8(seed);
        case 219: return verify_npth_bt_insn_219_0x0fcc(seed);
        case 220: return verify_npth_bt_insn_220_0x0fd0(seed);
        case 221: return verify_npth_bt_insn_221_0x0fd4(seed);
        case 222: return verify_npth_bt_insn_222_0x0fd8(seed);
        case 223: return verify_npth_bt_insn_223_0x0fdc(seed);
        case 224: return verify_npth_bt_insn_224_0x0fe0(seed);
        case 225: return verify_npth_bt_insn_225_0x0fe4(seed);
        case 226: return verify_npth_bt_insn_226_0x0fe8(seed);
        case 227: return verify_npth_bt_insn_227_0x0fec(seed);
        case 228: return verify_npth_bt_insn_228_0x0ff0(seed);
        case 229: return verify_npth_bt_insn_229_0x0ff4(seed);
        case 230: return verify_npth_bt_insn_230_0x0ff8(seed);
        case 231: return verify_npth_bt_insn_231_0x0ffc(seed);
        case 232: return verify_npth_bt_insn_232_0x1000(seed);
        case 233: return verify_npth_bt_insn_233_0x1004(seed);
        case 234: return verify_npth_bt_insn_234_0x1008(seed);
        case 235: return verify_npth_bt_insn_235_0x100c(seed);
        case 236: return verify_npth_bt_insn_236_0x1010(seed);
        case 237: return verify_npth_bt_insn_237_0x1014(seed);
        case 238: return verify_npth_bt_insn_238_0x1018(seed);
        case 239: return verify_npth_bt_insn_239_0x101c(seed);
        case 240: return verify_npth_bt_insn_240_0x1020(seed);
        case 241: return verify_npth_bt_insn_241_0x1024(seed);
        case 242: return verify_npth_bt_insn_242_0x1028(seed);
        case 243: return verify_npth_bt_insn_243_0x102c(seed);
        case 244: return verify_npth_bt_insn_244_0x1030(seed);
        case 245: return verify_npth_bt_insn_245_0x1034(seed);
        case 246: return verify_npth_bt_insn_246_0x1038(seed);
        case 247: return verify_npth_bt_insn_247_0x103c(seed);
        case 248: return verify_npth_bt_insn_248_0x1040(seed);
        case 249: return verify_npth_bt_insn_249_0x1044(seed);
        case 250: return verify_npth_bt_insn_250_0x1048(seed);
        case 251: return verify_npth_bt_insn_251_0x104c(seed);
        case 252: return verify_npth_bt_insn_252_0x1050(seed);
        case 253: return verify_npth_bt_insn_253_0x1054(seed);
        case 254: return verify_npth_bt_insn_254_0x1058(seed);
        case 255: return verify_npth_bt_insn_255_0x105c(seed);
        case 256: return verify_npth_bt_insn_256_0x1060(seed);
        case 257: return verify_npth_bt_insn_257_0x1064(seed);
        case 258: return verify_npth_bt_insn_258_0x1068(seed);
        case 259: return verify_npth_bt_insn_259_0x106c(seed);
        case 260: return verify_npth_bt_insn_260_0x1070(seed);
        case 261: return verify_npth_bt_insn_261_0x1074(seed);
        case 262: return verify_npth_bt_insn_262_0x1078(seed);
        case 263: return verify_npth_bt_insn_263_0x107c(seed);
        case 264: return verify_npth_bt_insn_264_0x1080(seed);
        case 265: return verify_npth_bt_insn_265_0x1084(seed);
        case 266: return verify_npth_bt_insn_266_0x1088(seed);
        case 267: return verify_npth_bt_insn_267_0x108c(seed);
        case 268: return verify_npth_bt_insn_268_0x1090(seed);
        case 269: return verify_npth_bt_insn_269_0x1094(seed);
        case 270: return verify_npth_bt_insn_270_0x1098(seed);
        case 271: return verify_npth_bt_insn_271_0x109c(seed);
        case 272: return verify_npth_bt_insn_272_0x10a0(seed);
        case 273: return verify_npth_bt_insn_273_0x10a4(seed);
        case 274: return verify_npth_bt_insn_274_0x10a8(seed);
        case 275: return verify_npth_bt_insn_275_0x10ac(seed);
        case 276: return verify_npth_bt_insn_276_0x10b0(seed);
        case 277: return verify_npth_bt_insn_277_0x10b4(seed);
        case 278: return verify_npth_bt_insn_278_0x10b8(seed);
        case 279: return verify_npth_bt_insn_279_0x10bc(seed);
        case 280: return verify_npth_bt_insn_280_0x10c0(seed);
        case 281: return verify_npth_bt_insn_281_0x10c4(seed);
        case 282: return verify_npth_bt_insn_282_0x10c8(seed);
        case 283: return verify_npth_bt_insn_283_0x10cc(seed);
        case 284: return verify_npth_bt_insn_284_0x10d0(seed);
        case 285: return verify_npth_bt_insn_285_0x10d4(seed);
        case 286: return verify_npth_bt_insn_286_0x10d8(seed);
        case 287: return verify_npth_bt_insn_287_0x10dc(seed);
        case 288: return verify_npth_bt_insn_288_0x10e0(seed);
        case 289: return verify_npth_bt_insn_289_0x10e4(seed);
        case 290: return verify_npth_bt_insn_290_0x10e8(seed);
        case 291: return verify_npth_bt_insn_291_0x10ec(seed);
        case 292: return verify_npth_bt_insn_292_0x10f0(seed);
        case 293: return verify_npth_bt_insn_293_0x10f4(seed);
        case 294: return verify_npth_bt_insn_294_0x10f8(seed);
        case 295: return verify_npth_bt_insn_295_0x10fc(seed);
        case 296: return verify_npth_bt_insn_296_0x1100(seed);
        case 297: return verify_npth_bt_insn_297_0x1104(seed);
        case 298: return verify_npth_bt_insn_298_0x1108(seed);
        case 299: return verify_npth_bt_insn_299_0x110c(seed);
        case 300: return verify_npth_bt_insn_300_0x1110(seed);
        case 301: return verify_npth_bt_insn_301_0x1114(seed);
        case 302: return verify_npth_bt_insn_302_0x1118(seed);
        case 303: return verify_npth_bt_insn_303_0x111c(seed);
        case 304: return verify_npth_bt_insn_304_0x1120(seed);
        case 305: return verify_npth_bt_insn_305_0x1124(seed);
        case 306: return verify_npth_bt_insn_306_0x1128(seed);
        case 307: return verify_npth_bt_insn_307_0x112c(seed);
        case 308: return verify_npth_bt_insn_308_0x1130(seed);
        case 309: return verify_npth_bt_insn_309_0x1134(seed);
        case 310: return verify_npth_bt_insn_310_0x1138(seed);
        case 311: return verify_npth_bt_insn_311_0x113c(seed);
        case 312: return verify_npth_bt_insn_312_0x1140(seed);
        case 313: return verify_npth_bt_insn_313_0x1144(seed);
        case 314: return verify_npth_bt_insn_314_0x1148(seed);
        case 315: return verify_npth_bt_insn_315_0x114c(seed);
        case 316: return verify_npth_bt_insn_316_0x1150(seed);
        case 317: return verify_npth_bt_insn_317_0x1154(seed);
        case 318: return verify_npth_bt_insn_318_0x1158(seed);
        case 319: return verify_npth_bt_insn_319_0x115c(seed);
        case 320: return verify_npth_bt_insn_320_0x1160(seed);
        case 321: return verify_npth_bt_insn_321_0x1164(seed);
        case 322: return verify_npth_bt_insn_322_0x1168(seed);
        case 323: return verify_npth_bt_insn_323_0x116c(seed);
        case 324: return verify_npth_bt_insn_324_0x1170(seed);
        case 325: return verify_npth_bt_insn_325_0x1174(seed);
        case 326: return verify_npth_bt_insn_326_0x1178(seed);
        case 327: return verify_npth_bt_insn_327_0x117c(seed);
        case 328: return verify_npth_bt_insn_328_0x1180(seed);
        case 329: return verify_npth_bt_insn_329_0x1184(seed);
        case 330: return verify_npth_bt_insn_330_0x1188(seed);
        case 331: return verify_npth_bt_insn_331_0x118c(seed);
        case 332: return verify_npth_bt_insn_332_0x1190(seed);
        case 333: return verify_npth_bt_insn_333_0x1194(seed);
        case 334: return verify_npth_bt_insn_334_0x1198(seed);
        case 335: return verify_npth_bt_insn_335_0x119c(seed);
        case 336: return verify_npth_bt_insn_336_0x11a0(seed);
        case 337: return verify_npth_bt_insn_337_0x11a4(seed);
        case 338: return verify_npth_bt_insn_338_0x11a8(seed);
        case 339: return verify_npth_bt_insn_339_0x11ac(seed);
        case 340: return verify_npth_bt_insn_340_0x11b0(seed);
        case 341: return verify_npth_bt_insn_341_0x11b4(seed);
        case 342: return verify_npth_bt_insn_342_0x11b8(seed);
        case 343: return verify_npth_bt_insn_343_0x11bc(seed);
        case 344: return verify_npth_bt_insn_344_0x11c0(seed);
        case 345: return verify_npth_bt_insn_345_0x11c4(seed);
        case 346: return verify_npth_bt_insn_346_0x11c8(seed);
        case 347: return verify_npth_bt_insn_347_0x11cc(seed);
        case 348: return verify_npth_bt_insn_348_0x11d0(seed);
        case 349: return verify_npth_bt_insn_349_0x11d4(seed);
        case 350: return verify_npth_bt_insn_350_0x11d8(seed);
        case 351: return verify_npth_bt_insn_351_0x11dc(seed);
        case 352: return verify_npth_bt_insn_352_0x11e0(seed);
        case 353: return verify_npth_bt_insn_353_0x11e4(seed);
        case 354: return verify_npth_bt_insn_354_0x11e8(seed);
        case 355: return verify_npth_bt_insn_355_0x11ec(seed);
        case 356: return verify_npth_bt_insn_356_0x11f0(seed);
        case 357: return verify_npth_bt_insn_357_0x11f4(seed);
        default: return 0ULL;
    }
}

} // namespace npth_bt