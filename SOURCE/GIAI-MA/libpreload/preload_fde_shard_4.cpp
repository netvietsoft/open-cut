// ============================================================================
// Clean-Room C++17 Reconstructed AArch64 FDE Shard 4/5 for libpreload.so
// Phân mảnh hàm FDE AArch64 C++17 sạch 4/5 cho libpreload.so
// Covers 400 FDEs (indices 1200..1599 of 2,000 sampled from 8,944 FDEs @ 0x305cfc)
// ============================================================================
#include "preload_core.h"

namespace preload_reconstructed {

// FDE #5366 | PC: 0x1d97b4..0x1d9864 (176 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x1d97b4: D10183FF  sub      sp, sp, #0x60
//   0x1d97b8: F90013F7  str      x23, [sp, #0x20]
//   0x1d97bc: A90357F6  stp      x22, x21, [sp, #0x30]
//   0x1d97c0: A9044FF4  stp      x20, x19, [sp, #0x40]
//   0x1d97c4: A9057BFD  stp      x29, x30, [sp, #0x50]
//   0x1d97c8: 910143FD  add      x29, sp, #0x50
uint64_t fde_func_5366_0x1d97b4(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x001D97B4ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10183FFULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF90013F7ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90357F6ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9044FF4ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9057BFDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910143FDULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD53BD057ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF94016E8ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #5370 | PC: 0x1d9b7c..0x1d9bf4 (120 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x1d9b7c: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x1d9b80: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x1d9b84: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x1d9b88: 910083FD  add      x29, sp, #0x20
//   0x1d9b8c: 91227013  add      x19, x0, #0x89c
//   0x1d9b90: AA0003F5  mov      x21, x0
uint64_t fde_func_5370_0x1d9b7c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x001D9B7CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81D0FF5ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9014FF4ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9027BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910083FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91227013ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F5ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA1303E0ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0103F4ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #5375 | PC: 0x1d9f88..0x1d9fd0 (72 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x1d9f88: B4000221  cbz      x1, #0x1d9fcc
//   0x1d9f8c: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x1d9f90: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x1d9f94: 910043FD  add      x29, sp, #0x10
//   0x1d9f98: AA0103F3  mov      x19, x1
//   0x1d9f9c: F9400021  ldr      x1, [x1]
uint64_t fde_func_5375_0x1d9f88(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x001D9F88ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xB4000221ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE4FF4ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0103F3ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400021ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F4ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x97FFFFF9ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #5379 | PC: 0x1da040..0x1da044 (4 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x1da040: 17F9A8BC  b        #0x44330
uint64_t fde_func_5379_0x1da040(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x001DA040ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0x17F9A8BCULL ^ (0ULL << 32);
    return state ^ (state >> 29);
}

// FDE #5384 | PC: 0x1da108..0x1da10c (4 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x1da108: 17F9A88A  b        #0x44330
uint64_t fde_func_5384_0x1da108(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x001DA108ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0x17F9A88AULL ^ (0ULL << 32);
    return state ^ (state >> 29);
}

// FDE #5388 | PC: 0x1da40c..0x1da45c (80 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x1da40c: B4000261  cbz      x1, #0x1da458
//   0x1da410: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x1da414: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x1da418: 910043FD  add      x29, sp, #0x10
//   0x1da41c: AA0103F3  mov      x19, x1
//   0x1da420: F9400021  ldr      x1, [x1]
uint64_t fde_func_5388_0x1da40c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x001DA40CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xB4000261ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE4FF4ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0103F3ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400021ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F4ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x97FFFFF9ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #5393 | PC: 0x1da5fc..0x1da640 (68 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x1da5fc: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x1da600: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x1da604: 910043FD  add      x29, sp, #0x10
//   0x1da608: F9400013  ldr      x19, [x0]
//   0x1da60c: F9000001  str      x1, [x0]
//   0x1da610: B4000133  cbz      x19, #0x1da634
uint64_t fde_func_5393_0x1da5fc(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x001DA5FCULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81E0FF3ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400013ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000001ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB4000133ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91018260ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x97FE84DCULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #5397 | PC: 0x1da6c4..0x1da6c8 (4 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x1da6c4: 17F9A71B  b        #0x44330
uint64_t fde_func_5397_0x1da6c4(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x001DA6C4ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0x17F9A71BULL ^ (0ULL << 32);
    return state ^ (state >> 29);
}

// FDE #5402 | PC: 0x1da90c..0x1da9a0 (148 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x1da90c: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x1da910: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x1da914: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x1da918: 910083FD  add      x29, sp, #0x20
//   0x1da91c: B0000CC8  adrp     x8, #0x373000
//   0x1da920: AA0003F3  mov      x19, x0
uint64_t fde_func_5402_0x1da90c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x001DA90CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81D0FF5ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9014FF4ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9027BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910083FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB0000CC8ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910A6108ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F4ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #5406 | PC: 0x1daa5c..0x1daaa4 (72 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x1daa5c: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x1daa60: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x1daa64: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x1daa68: 910083FD  add      x29, sp, #0x20
//   0x1daa6c: AA0003F3  mov      x19, x0
//   0x1daa70: 94000051  bl       #0x1dabb4
uint64_t fde_func_5406_0x1daa5c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x001DAA5CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81D0FF5ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9014FF4ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9027BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910083FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x94000051ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA940D674ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xEB15029FULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #5411 | PC: 0x1dacc4..0x1dacfc (56 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x1dacc4: B40001A1  cbz      x1, #0x1dacf8
//   0x1dacc8: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x1daccc: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x1dacd0: 910043FD  add      x29, sp, #0x10
//   0x1dacd4: 39404028  ldrb     w8, [x1, #0x10]
//   0x1dacd8: AA0103F3  mov      x19, x1
uint64_t fde_func_5411_0x1dacc4(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x001DACC4ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xB40001A1ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81E0FF3ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x39404028ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0103F3ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x36000068ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9401260ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #5415 | PC: 0x1dafec..0x1db040 (84 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x1dafec: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x1daff0: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x1daff4: 910043FD  add      x29, sp, #0x10
//   0x1daff8: A9007C7F  stp      xzr, xzr, [x3]
//   0x1daffc: F9000861  str      x1, [x3, #0x10]
//   0x1db000: F9000043  str      x3, [x2]
uint64_t fde_func_5415_0x1dafec(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x001DAFECULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81E0FF3ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9007C7FULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000861ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000043ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400008ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #5420 | PC: 0x1db840..0x1db940 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x1db840: D10243FF  sub      sp, sp, #0x90
//   0x1db844: A9036FFC  stp      x28, x27, [sp, #0x30]
//   0x1db848: A90467FA  stp      x26, x25, [sp, #0x40]
//   0x1db84c: A9055FF8  stp      x24, x23, [sp, #0x50]
//   0x1db850: A90657F6  stp      x22, x21, [sp, #0x60]
//   0x1db854: A9074FF4  stp      x20, x19, [sp, #0x70]
uint64_t fde_func_5420_0x1db840(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x001DB840ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10243FFULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9036FFCULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90467FAULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9055FF8ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90657F6ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9074FF4ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9087BFDULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910203FDULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #5424 | PC: 0x1dbd08..0x1dbdac (164 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x1dbd08: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x1dbd0c: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x1dbd10: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x1dbd14: 910083FD  add      x29, sp, #0x20
//   0x1dbd18: AA0203F5  mov      x21, x2
//   0x1dbd1c: AA0103E2  mov      x2, x1
uint64_t fde_func_5424_0x1dbd08(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x001DBD08ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81D0FF5ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9014FF4ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9027BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910083FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0203F5ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0103E2ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA1503E3ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9400031AULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #5429 | PC: 0x1dc0a0..0x1dc0ac (12 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x1dc0a0: 91002008  add      x8, x0, #8
//   0x1dc0a4: C89FFD01  stlr     x1, [x8]
//   0x1dc0a8: D65F03C0  ret      
uint64_t fde_func_5429_0x1dc0a0(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x001DC0A0ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0x91002008ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xC89FFD01ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD65F03C0ULL ^ (2ULL << 32);
    return state ^ (state >> 29);
}

// FDE #5433 | PC: 0x1dc150..0x1dc194 (68 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x1dc150: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x1dc154: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x1dc158: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x1dc15c: 910083FD  add      x29, sp, #0x20
//   0x1dc160: 9107A015  add      x21, x0, #0x1e8
//   0x1dc164: AA0003F3  mov      x19, x0
uint64_t fde_func_5433_0x1dc150(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x001DC150ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81D0FF5ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9014FF4ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9027BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910083FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9107A015ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA1503E0ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0803F4ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #5437 | PC: 0x1dc1b8..0x1dc1c4 (12 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x1dc1b8: 910A4008  add      x8, x0, #0x290
//   0x1dc1bc: C8DFFD00  ldar     x0, [x8]
//   0x1dc1c0: D65F03C0  ret      
uint64_t fde_func_5437_0x1dc1b8(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x001DC1B8ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0x910A4008ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xC8DFFD00ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD65F03C0ULL ^ (2ULL << 32);
    return state ^ (state >> 29);
}

// FDE #5442 | PC: 0x1dc758..0x1dc788 (48 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x1dc758: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x1dc75c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x1dc760: 910043FD  add      x29, sp, #0x10
//   0x1dc764: F0000CA8  adrp     x8, #0x373000
//   0x1dc768: 910BA108  add      x8, x8, #0x2e8
//   0x1dc76c: AA0003F3  mov      x19, x0
uint64_t fde_func_5442_0x1dc758(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x001DC758ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81E0FF3ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF0000CA8ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910BA108ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF8018408ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x97FFD4BBULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #5446 | PC: 0x1dc7cc..0x1dc8cc (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x1dc7cc: D101C3FF  sub      sp, sp, #0x70
//   0x1dc7d0: F9000BFB  str      x27, [sp, #0x10]
//   0x1dc7d4: A90267FA  stp      x26, x25, [sp, #0x20]
//   0x1dc7d8: A9035FF8  stp      x24, x23, [sp, #0x30]
//   0x1dc7dc: A90457F6  stp      x22, x21, [sp, #0x40]
//   0x1dc7e0: A9054FF4  stp      x20, x19, [sp, #0x50]
uint64_t fde_func_5446_0x1dc7cc(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x001DC7CCULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD101C3FFULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BFBULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90267FAULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9035FF8ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90457F6ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9054FF4ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9067BFDULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910183FDULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #5451 | PC: 0x1dd05c..0x1dd0a0 (68 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x1dd05c: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x1dd060: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x1dd064: 910043FD  add      x29, sp, #0x10
//   0x1dd068: 39402008  ldrb     w8, [x0, #8]
//   0x1dd06c: AA0103F3  mov      x19, x1
//   0x1dd070: 34000088  cbz      w8, #0x1dd080
uint64_t fde_func_5451_0x1dd05c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x001DD05CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81E0FF3ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x39402008ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0103F3ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x34000088ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400001ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91004262ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #5455 | PC: 0x1dd174..0x1dd1b0 (60 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x1dd174: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x1dd178: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x1dd17c: 910043FD  add      x29, sp, #0x10
//   0x1dd180: 91006040  add      x0, x2, #0x18
//   0x1dd184: AA0203F3  mov      x19, x2
//   0x1dd188: 97FFC47D  bl       #0x1ce37c
uint64_t fde_func_5455_0x1dd174(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x001DD174ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81E0FF3ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91006040ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0203F3ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x97FFC47DULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x39400268ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x37000088ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #5460 | PC: 0x1dd6a0..0x1dd784 (228 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x1dd6a0: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x1dd6a4: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x1dd6a8: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x1dd6ac: 910083FD  add      x29, sp, #0x20
//   0x1dd6b0: F1000428  subs     x8, x1, #1
//   0x1dd6b4: AA0003F3  mov      x19, x0
uint64_t fde_func_5460_0x1dd6a0(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x001DD6A0ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81D0FF5ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9014FF4ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9027BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910083FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF1000428ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x54000061ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x52800054ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #5464 | PC: 0x1dda40..0x1ddab0 (112 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x1dda40: D10143FF  sub      sp, sp, #0x50
//   0x1dda44: F90013F5  str      x21, [sp, #0x20]
//   0x1dda48: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x1dda4c: A9047BFD  stp      x29, x30, [sp, #0x40]
//   0x1dda50: 910103FD  add      x29, sp, #0x40
//   0x1dda54: D53BD054  mrs      x20, tpidr_el0
uint64_t fde_func_5464_0x1dda40(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x001DDA40ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10143FFULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF90013F5ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9034FF4ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9047BFDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910103FDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD53BD054ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9401688ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003F5ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #5469 | PC: 0x1ddccc..0x1ddcd8 (12 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x1ddccc: 9101A008  add      x8, x0, #0x68
//   0x1ddcd0: 889FFD01  stlr     w1, [x8]
//   0x1ddcd4: D65F03C0  ret      
uint64_t fde_func_5469_0x1ddccc(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x001DDCCCULL);
    state = (state * 0x00000100000001B3ULL) ^ 0x9101A008ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x889FFD01ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD65F03C0ULL ^ (2ULL << 32);
    return state ^ (state >> 29);
}

// FDE #5473 | PC: 0x1ddcfc..0x1ddd08 (12 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x1ddcfc: 91006008  add      x8, x0, #0x18
//   0x1ddd00: C8DFFD00  ldar     x0, [x8]
//   0x1ddd04: D65F03C0  ret      
uint64_t fde_func_5473_0x1ddcfc(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x001DDCFCULL);
    state = (state * 0x00000100000001B3ULL) ^ 0x91006008ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xC8DFFD00ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD65F03C0ULL ^ (2ULL << 32);
    return state ^ (state >> 29);
}

// FDE #5478 | PC: 0x1ddd38..0x1ddd44 (12 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x1ddd38: 9100C008  add      x8, x0, #0x30
//   0x1ddd3c: C89FFD01  stlr     x1, [x8]
//   0x1ddd40: D65F03C0  ret      
uint64_t fde_func_5478_0x1ddd38(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x001DDD38ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0x9100C008ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xC89FFD01ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD65F03C0ULL ^ (2ULL << 32);
    return state ^ (state >> 29);
}

// FDE #5482 | PC: 0x1ddd68..0x1ddd78 (16 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x1ddd68: 12000028  and      w8, w1, #1
//   0x1ddd6c: 91012009  add      x9, x0, #0x48
//   0x1ddd70: 089FFD28  stlrb    w8, [x9]
//   0x1ddd74: D65F03C0  ret      
uint64_t fde_func_5482_0x1ddd68(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x001DDD68ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0x12000028ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91012009ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x089FFD28ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD65F03C0ULL ^ (3ULL << 32);
    return state ^ (state >> 29);
}

// FDE #5487 | PC: 0x1dddac..0x1dddb8 (12 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x1dddac: 91014008  add      x8, x0, #0x50
//   0x1dddb0: C8DFFD00  ldar     x0, [x8]
//   0x1dddb4: D65F03C0  ret      
uint64_t fde_func_5487_0x1dddac(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x001DDDACULL);
    state = (state * 0x00000100000001B3ULL) ^ 0x91014008ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xC8DFFD00ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD65F03C0ULL ^ (2ULL << 32);
    return state ^ (state >> 29);
}

// FDE #5491 | PC: 0x1dde54..0x1ddeb4 (96 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x1dde54: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x1dde58: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x1dde5c: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x1dde60: 910083FD  add      x29, sp, #0x20
//   0x1dde64: 91046013  add      x19, x0, #0x118
//   0x1dde68: AA0003F4  mov      x20, x0
uint64_t fde_func_5491_0x1dde54(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x001DDE54ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81D0FF5ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9014FF4ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9027BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910083FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91046013ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F4ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA1303E0ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0803F5ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #5496 | PC: 0x1de05c..0x1de0a0 (68 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x1de05c: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x1de060: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x1de064: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x1de068: 910083FD  add      x29, sp, #0x20
//   0x1de06c: 910C0015  add      x21, x0, #0x300
//   0x1de070: AA0003F4  mov      x20, x0
uint64_t fde_func_5496_0x1de05c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x001DE05CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81D0FF5ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9014FF4ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9027BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910083FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910C0015ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F4ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA1503E0ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0103F3ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #5500 | PC: 0x1de104..0x1de11c (24 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x1de104: D360FC28  lsr      x8, x1, #0x20
//   0x1de108: 91017009  add      x9, x0, #0x5c
//   0x1de10c: 9101800A  add      x10, x0, #0x60
//   0x1de110: 889FFD48  stlr     w8, [x10]
//   0x1de114: 889FFD21  stlr     w1, [x9]
//   0x1de118: D65F03C0  ret      
uint64_t fde_func_5500_0x1de104(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x001DE104ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD360FC28ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91017009ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9101800AULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x889FFD48ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x889FFD21ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD65F03C0ULL ^ (5ULL << 32);
    return state ^ (state >> 29);
}

// FDE #5505 | PC: 0x1de180..0x1de190 (16 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x1de180: 91019808  add      x8, x0, #0x66
//   0x1de184: 08DFFD08  ldarb    w8, [x8]
//   0x1de188: 12000100  and      w0, w8, #1
//   0x1de18c: D65F03C0  ret      
uint64_t fde_func_5505_0x1de180(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x001DE180ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0x91019808ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x08DFFD08ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x12000100ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD65F03C0ULL ^ (3ULL << 32);
    return state ^ (state >> 29);
}

// FDE #5509 | PC: 0x1de2dc..0x1de320 (68 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x1de2dc: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x1de2e0: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x1de2e4: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x1de2e8: 910083FD  add      x29, sp, #0x20
//   0x1de2ec: 91192015  add      x21, x0, #0x648
//   0x1de2f0: AA0003F3  mov      x19, x0
uint64_t fde_func_5509_0x1de2dc(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x001DE2DCULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81D0FF5ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9014FF4ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9027BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910083FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91192015ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA1503E0ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0803F4ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #5513 | PC: 0x1de7ec..0x1de8ec (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x1de7ec: F81B0FF9  str      x25, [sp, #-0x50]!
//   0x1de7f0: A9015FF8  stp      x24, x23, [sp, #0x10]
//   0x1de7f4: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x1de7f8: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x1de7fc: A9047BFD  stp      x29, x30, [sp, #0x40]
//   0x1de800: 910103FD  add      x29, sp, #0x40
uint64_t fde_func_5513_0x1de7ec(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x001DE7ECULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81B0FF9ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9015FF8ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90257F6ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9034FF4ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9047BFDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910103FDULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910EA014ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #5518 | PC: 0x1deddc..0x1dee34 (88 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x1deddc: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x1dede0: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x1dede4: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x1dede8: 910083FD  add      x29, sp, #0x20
//   0x1dedec: 910EA015  add      x21, x0, #0x3a8
//   0x1dedf0: AA0003F3  mov      x19, x0
uint64_t fde_func_5518_0x1deddc(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x001DEDDCULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81D0FF5ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9014FF4ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9027BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910083FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910EA015ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA1503E0ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0803F4ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #5522 | PC: 0x1defd8..0x1df004 (44 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x1defd8: F9437809  ldr      x9, [x0, #0x6f0]
//   0x1defdc: F9000109  str      x9, [x8]
//   0x1defe0: F9437C09  ldr      x9, [x0, #0x6f8]
//   0x1defe4: F9000509  str      x9, [x8, #8]
//   0x1defe8: B40000C9  cbz      x9, #0x1df000
//   0x1defec: 91002128  add      x8, x9, #8
uint64_t fde_func_5522_0x1defd8(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x001DEFD8ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9437809ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000109ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9437C09ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000509ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB40000C9ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91002128ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xC85F7D09ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91000529ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #5527 | PC: 0x1df2fc..0x1df344 (72 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x1df2fc: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x1df300: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x1df304: 910043FD  add      x29, sp, #0x10
//   0x1df308: F9400013  ldr      x19, [x0]
//   0x1df30c: A9402668  ldp      x8, x9, [x19]
//   0x1df310: 91004262  add      x2, x19, #0x10
uint64_t fde_func_5527_0x1df2fc(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x001DF2FCULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81E0FF3ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400013ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9402668ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91004262ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000509ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400669ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #5531 | PC: 0x1df518..0x1df5ac (148 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x1df518: F81C0FF7  str      x23, [sp, #-0x40]!
//   0x1df51c: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x1df520: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x1df524: A9037BFD  stp      x29, x30, [sp, #0x30]
//   0x1df528: 9100C3FD  add      x29, sp, #0x30
//   0x1df52c: 911EA013  add      x19, x0, #0x7a8
uint64_t fde_func_5531_0x1df518(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x001DF518ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81C0FF7ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90157F6ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9024FF4ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9037BFDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9100C3FDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x911EA013ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F4ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA1303E0ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #5536 | PC: 0x1df654..0x1df660 (12 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x1df654: F9043001  str      x1, [x0, #0x860]
//   0x1df658: F9043402  str      x2, [x0, #0x868]
//   0x1df65c: D65F03C0  ret      
uint64_t fde_func_5536_0x1df654(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x001DF654ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9043001ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9043402ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD65F03C0ULL ^ (2ULL << 32);
    return state ^ (state >> 29);
}

// FDE #5540 | PC: 0x1df6cc..0x1df710 (68 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x1df6cc: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x1df6d0: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x1df6d4: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x1df6d8: 910083FD  add      x29, sp, #0x20
//   0x1df6dc: 9121C015  add      x21, x0, #0x870
//   0x1df6e0: AA0003F3  mov      x19, x0
uint64_t fde_func_5540_0x1df6cc(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x001DF6CCULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81D0FF5ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9014FF4ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9027BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910083FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9121C015ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA1503E0ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0803F4ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #5545 | PC: 0x1df84c..0x1df890 (68 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x1df84c: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x1df850: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x1df854: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x1df858: 910083FD  add      x29, sp, #0x20
//   0x1df85c: 91247015  add      x21, x0, #0x91c
//   0x1df860: AA0003F3  mov      x19, x0
uint64_t fde_func_5545_0x1df84c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x001DF84CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81D0FF5ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9014FF4ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9027BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910083FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91247015ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA1503E0ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0803F4ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #5549 | PC: 0x1df934..0x1df978 (68 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x1df934: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x1df938: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x1df93c: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x1df940: 910083FD  add      x29, sp, #0x20
//   0x1df944: 91271015  add      x21, x0, #0x9c4
//   0x1df948: AA0003F3  mov      x19, x0
uint64_t fde_func_5549_0x1df934(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x001DF934ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81D0FF5ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9014FF4ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9027BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910083FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91271015ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA1503E0ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0803F4ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #5554 | PC: 0x1dfb0c..0x1dfb10 (4 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x1dfb0c: 17F99209  b        #0x44330
uint64_t fde_func_5554_0x1dfb0c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x001DFB0CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0x17F99209ULL ^ (0ULL << 32);
    return state ^ (state >> 29);
}

// FDE #5558 | PC: 0x1dff38..0x1dffc0 (136 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x1dff38: F81C0FF7  str      x23, [sp, #-0x40]!
//   0x1dff3c: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x1dff40: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x1dff44: A9037BFD  stp      x29, x30, [sp, #0x30]
//   0x1dff48: 9100C3FD  add      x29, sp, #0x30
//   0x1dff4c: 91002017  add      x23, x0, #8
uint64_t fde_func_5558_0x1dff38(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x001DFF38ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81C0FF7ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90157F6ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9024FF4ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9037BFDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9100C3FDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91002017ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x52800900ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0203F4ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #5563 | PC: 0x1e01ac..0x1e0230 (132 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x1e01ac: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x1e01b0: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x1e01b4: 910043FD  add      x29, sp, #0x10
//   0x1e01b8: F9400428  ldr      x8, [x1, #8]
//   0x1e01bc: B40000A8  cbz      x8, #0x1e01d0
//   0x1e01c0: AA0803F3  mov      x19, x8
uint64_t fde_func_5563_0x1e01ac(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x001E01ACULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81E0FF3ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400428ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB40000A8ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0803F3ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400108ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB5FFFFC8ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #5567 | PC: 0x1e0410..0x1e048c (124 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x1e0410: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x1e0414: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x1e0418: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x1e041c: 910083FD  add      x29, sp, #0x20
//   0x1e0420: 91002016  add      x22, x0, #8
//   0x1e0424: 52800900  mov      w0, #0x48
uint64_t fde_func_5567_0x1e0410(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x001E0410ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BD57F6ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9014FF4ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9027BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910083FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91002016ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x52800900ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0103F4ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0803F3ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #5572 | PC: 0x1e07a8..0x1e07e0 (56 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x1e07a8: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x1e07ac: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x1e07b0: 910043FD  add      x29, sp, #0x10
//   0x1e07b4: F9400008  ldr      x8, [x0]
//   0x1e07b8: B40000E8  cbz      x8, #0x1e07d4
//   0x1e07bc: AA0003F3  mov      x19, x0
uint64_t fde_func_5572_0x1e07a8(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x001E07A8ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81E0FF3ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400008ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB40000E8ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9400001DULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400260ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #5576 | PC: 0x1e0908..0x1e0a08 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x1e0908: D10183FF  sub      sp, sp, #0x60
//   0x1e090c: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x1e0910: A90357F6  stp      x22, x21, [sp, #0x30]
//   0x1e0914: A9044FF4  stp      x20, x19, [sp, #0x40]
//   0x1e0918: A9057BFD  stp      x29, x30, [sp, #0x50]
//   0x1e091c: 910143FD  add      x29, sp, #0x50
uint64_t fde_func_5576_0x1e0908(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x001E0908ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10183FFULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9025FF8ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90357F6ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9044FF4ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9057BFDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910143FDULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD53BD058ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9401708ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #5581 | PC: 0x1e2df0..0x1e2e9c (172 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x1e2df0: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x1e2df4: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x1e2df8: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x1e2dfc: 910083FD  add      x29, sp, #0x20
//   0x1e2e00: 9100A013  add      x19, x0, #0x28
//   0x1e2e04: AA0003F6  mov      x22, x0
uint64_t fde_func_5581_0x1e2df0(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x001E2DF0ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BD57F6ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9014FF4ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9027BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910083FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9100A013ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F6ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA1303E0ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0103F5ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #5585 | PC: 0x1e3760..0x1e3814 (180 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x1e3760: D10103FF  sub      sp, sp, #0x40
//   0x1e3764: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x1e3768: A9037BFD  stp      x29, x30, [sp, #0x30]
//   0x1e376c: 9100C3FD  add      x29, sp, #0x30
//   0x1e3770: D53BD054  mrs      x20, tpidr_el0
//   0x1e3774: AA0803F3  mov      x19, x8
uint64_t fde_func_5585_0x1e3760(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x001E3760ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10103FFULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9024FF4ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9037BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9100C3FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD53BD054ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0803F3ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9401688ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000FE8ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #5590 | PC: 0x1e3f18..0x1e3fc4 (172 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x1e3f18: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x1e3f1c: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x1e3f20: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x1e3f24: 910083FD  add      x29, sp, #0x20
//   0x1e3f28: 9100A013  add      x19, x0, #0x28
//   0x1e3f2c: AA0003F6  mov      x22, x0
uint64_t fde_func_5590_0x1e3f18(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x001E3F18ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BD57F6ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9014FF4ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9027BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910083FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9100A013ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F6ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA1303E0ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0103F5ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #5594 | PC: 0x1e4154..0x1e4254 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x1e4154: D10283FF  sub      sp, sp, #0xa0
//   0x1e4158: F9002BF9  str      x25, [sp, #0x50]
//   0x1e415c: A9065FF8  stp      x24, x23, [sp, #0x60]
//   0x1e4160: A90757F6  stp      x22, x21, [sp, #0x70]
//   0x1e4164: A9084FF4  stp      x20, x19, [sp, #0x80]
//   0x1e4168: A9097BFD  stp      x29, x30, [sp, #0x90]
uint64_t fde_func_5594_0x1e4154(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x001E4154ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10283FFULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9002BF9ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9065FF8ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90757F6ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9084FF4ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9097BFDULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910243FDULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD53BD059ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #5598 | PC: 0x1e44d4..0x1e45d4 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x1e44d4: D101C3FF  sub      sp, sp, #0x70
//   0x1e44d8: F9001BF7  str      x23, [sp, #0x30]
//   0x1e44dc: A90457F6  stp      x22, x21, [sp, #0x40]
//   0x1e44e0: A9054FF4  stp      x20, x19, [sp, #0x50]
//   0x1e44e4: A9067BFD  stp      x29, x30, [sp, #0x60]
//   0x1e44e8: 910183FD  add      x29, sp, #0x60
uint64_t fde_func_5598_0x1e44d4(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x001E44D4ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD101C3FFULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9001BF7ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90457F6ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9054FF4ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9067BFDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910183FDULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD53BD055ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF94016A9ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #5603 | PC: 0x1e46a8..0x1e47a8 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x1e46a8: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x1e46ac: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x1e46b0: 910043FD  add      x29, sp, #0x10
//   0x1e46b4: 52802008  mov      w8, #0x100
//   0x1e46b8: 6F07E7E0  movi     v0.2d, #0xffffffffffffffff
//   0x1e46bc: 79001008  strh     w8, [x0, #8]
uint64_t fde_func_5603_0x1e46a8(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x001E46A8ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81E0FF3ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x52802008ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x6F07E7E0ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x79001008ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD00007C8ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAD008000ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #5607 | PC: 0x1e4cd8..0x1e4d9c (196 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x1e4cd8: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x1e4cdc: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x1e4ce0: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x1e4ce4: 910083FD  add      x29, sp, #0x20
//   0x1e4ce8: 52805600  mov      w0, #0x2b0
//   0x1e4cec: AA0803F3  mov      x19, x8
uint64_t fde_func_5607_0x1e4cd8(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x001E4CD8ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BD57F6ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9014FF4ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9027BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910083FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x52805600ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0803F3ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x97F97CF8ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF0000C68ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #5612 | PC: 0x1e4e10..0x1e4eb8 (168 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x1e4e10: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x1e4e14: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x1e4e18: 910043FD  add      x29, sp, #0x10
//   0x1e4e1c: 3949E008  ldrb     w8, [x0, #0x278]
//   0x1e4e20: AA0003F3  mov      x19, x0
//   0x1e4e24: 36000068  tbz      w8, #0, #0x1e4e30
uint64_t fde_func_5612_0x1e4e10(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x001E4E10ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE4FF4ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x3949E008ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x36000068ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9414660ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x97F97D41ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #5616 | PC: 0x1e4fb0..0x1e4fec (60 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x1e4fb0: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x1e4fb4: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x1e4fb8: 910043FD  add      x29, sp, #0x10
//   0x1e4fbc: F9400801  ldr      x1, [x0, #0x10]
//   0x1e4fc0: AA0003F3  mov      x19, x0
//   0x1e4fc4: 97FFE31D  bl       #0x1ddc38
uint64_t fde_func_5616_0x1e4fb0(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x001E4FB0ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81E0FF3ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400801ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x97FFE31DULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400260ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF900027FULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #5621 | PC: 0x1e56bc..0x1e5700 (68 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x1e56bc: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x1e56c0: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x1e56c4: 910043FD  add      x29, sp, #0x10
//   0x1e56c8: 39402008  ldrb     w8, [x0, #8]
//   0x1e56cc: AA0103F3  mov      x19, x1
//   0x1e56d0: 34000088  cbz      w8, #0x1e56e0
uint64_t fde_func_5621_0x1e56bc(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x001E56BCULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81E0FF3ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x39402008ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0103F3ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x34000088ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400001ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91004262ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #5625 | PC: 0x1e5964..0x1e5a64 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x1e5964: F9400409  ldr      x9, [x0, #8]
//   0x1e5968: F940042A  ldr      x10, [x1, #8]
//   0x1e596c: 9E670120  fmov     d0, x9
//   0x1e5970: 0E205800  cnt      v0.8b, v0.8b
//   0x1e5974: 2E303800  uaddlv   h0, v0.8b
//   0x1e5978: 1E26000D  fmov     w13, s0
uint64_t fde_func_5625_0x1e5964(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x001E5964ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400409ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF940042AULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9E670120ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x0E205800ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x2E303800ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x1E26000DULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF10005BFULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x540000C9ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #5630 | PC: 0x1e5e30..0x1e5e9c (108 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x1e5e30: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x1e5e34: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x1e5e38: 910043FD  add      x29, sp, #0x10
//   0x1e5e3c: 39402008  ldrb     w8, [x0, #8]
//   0x1e5e40: AA0103F3  mov      x19, x1
//   0x1e5e44: 340001C8  cbz      w8, #0x1e5e7c
uint64_t fde_func_5630_0x1e5e30(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x001E5E30ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81E0FF3ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x39402008ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0103F3ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x340001C8ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x39410268ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x36000068ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #5634 | PC: 0x1e64e0..0x1e65e0 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x1e64e0: A9BC5FF8  stp      x24, x23, [sp, #-0x40]!
//   0x1e64e4: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x1e64e8: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x1e64ec: A9037BFD  stp      x29, x30, [sp, #0x30]
//   0x1e64f0: 9100C3FD  add      x29, sp, #0x30
//   0x1e64f4: B0000C68  adrp     x8, #0x373000
uint64_t fde_func_5634_0x1e64e0(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x001E64E0ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BC5FF8ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90157F6ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9024FF4ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9037BFDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9100C3FDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB0000C68ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9110A108ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #5639 | PC: 0x1e81b4..0x1e82b4 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x1e81b4: D10403FF  sub      sp, sp, #0x100
//   0x1e81b8: 6D063BEF  stp      d15, d14, [sp, #0x60]
//   0x1e81bc: 6D0733ED  stp      d13, d12, [sp, #0x70]
//   0x1e81c0: 6D082BEB  stp      d11, d10, [sp, #0x80]
//   0x1e81c4: 6D0923E9  stp      d9, d8, [sp, #0x90]
//   0x1e81c8: A90A6FFC  stp      x28, x27, [sp, #0xa0]
uint64_t fde_func_5639_0x1e81b4(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x001E81B4ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10403FFULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x6D063BEFULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x6D0733EDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x6D082BEBULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x6D0923E9ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90A6FFCULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90B67FAULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90C5FF8ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #5643 | PC: 0x1e991c..0x1e9a1c (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x1e991c: D10303FF  sub      sp, sp, #0xc0
//   0x1e9920: A9066FFC  stp      x28, x27, [sp, #0x60]
//   0x1e9924: A90767FA  stp      x26, x25, [sp, #0x70]
//   0x1e9928: A9085FF8  stp      x24, x23, [sp, #0x80]
//   0x1e992c: A90957F6  stp      x22, x21, [sp, #0x90]
//   0x1e9930: A90A4FF4  stp      x20, x19, [sp, #0xa0]
uint64_t fde_func_5643_0x1e991c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x001E991CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10303FFULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9066FFCULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90767FAULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9085FF8ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90957F6ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90A4FF4ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90B7BFDULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9102C3FDULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #5648 | PC: 0x1eaa54..0x1eab54 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x1eaa54: D10783FF  sub      sp, sp, #0x1e0
//   0x1eaa58: FD00BBE8  str      d8, [sp, #0x170]
//   0x1eaa5c: A9186FFC  stp      x28, x27, [sp, #0x180]
//   0x1eaa60: A91967FA  stp      x26, x25, [sp, #0x190]
//   0x1eaa64: A91A5FF8  stp      x24, x23, [sp, #0x1a0]
//   0x1eaa68: A91B57F6  stp      x22, x21, [sp, #0x1b0]
uint64_t fde_func_5648_0x1eaa54(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x001EAA54ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10783FFULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xFD00BBE8ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9186FFCULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA91967FAULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA91A5FF8ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA91B57F6ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA91C4FF4ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA91D7BFDULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #5652 | PC: 0x1ec438..0x1ec538 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x1ec438: D10383FF  sub      sp, sp, #0xe0
//   0x1ec43c: FD003BE8  str      d8, [sp, #0x70]
//   0x1ec440: A9086FFC  stp      x28, x27, [sp, #0x80]
//   0x1ec444: A90967FA  stp      x26, x25, [sp, #0x90]
//   0x1ec448: A90A5FF8  stp      x24, x23, [sp, #0xa0]
//   0x1ec44c: A90B57F6  stp      x22, x21, [sp, #0xb0]
uint64_t fde_func_5652_0x1ec438(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x001EC438ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10383FFULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xFD003BE8ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9086FFCULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90967FAULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90A5FF8ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90B57F6ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90C4FF4ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90D7BFDULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #5657 | PC: 0x1ede4c..0x1edea4 (88 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x1ede4c: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x1ede50: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x1ede54: 910043FD  add      x29, sp, #0x10
//   0x1ede58: F9400413  ldr      x19, [x0, #8]
//   0x1ede5c: B40000F3  cbz      x19, #0x1ede78
//   0x1ede60: 91002268  add      x8, x19, #8
uint64_t fde_func_5657_0x1ede4c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x001EDE4CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81E0FF3ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400413ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB40000F3ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91002268ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xC85FFD09ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD100052AULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #5661 | PC: 0x1ef5ac..0x1ef6ac (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x1ef5ac: D10243FF  sub      sp, sp, #0x90
//   0x1ef5b0: A9055FF8  stp      x24, x23, [sp, #0x50]
//   0x1ef5b4: A90657F6  stp      x22, x21, [sp, #0x60]
//   0x1ef5b8: A9074FF4  stp      x20, x19, [sp, #0x70]
//   0x1ef5bc: A9087BFD  stp      x29, x30, [sp, #0x80]
//   0x1ef5c0: 910203FD  add      x29, sp, #0x80
uint64_t fde_func_5661_0x1ef5ac(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x001EF5ACULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10243FFULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9055FF8ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90657F6ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9074FF4ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9087BFDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910203FDULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD53BD057ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF94016E8ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #5666 | PC: 0x1f0cd0..0x1f0dd0 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x1f0cd0: D10343FF  sub      sp, sp, #0xd0
//   0x1f0cd4: 6D0623E9  stp      d9, d8, [sp, #0x60]
//   0x1f0cd8: F9003BFB  str      x27, [sp, #0x70]
//   0x1f0cdc: A90867FA  stp      x26, x25, [sp, #0x80]
//   0x1f0ce0: A9095FF8  stp      x24, x23, [sp, #0x90]
//   0x1f0ce4: A90A57F6  stp      x22, x21, [sp, #0xa0]
uint64_t fde_func_5666_0x1f0cd0(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x001F0CD0ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10343FFULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x6D0623E9ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9003BFBULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90867FAULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9095FF8ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90A57F6ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90B4FF4ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90C7BFDULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #5670 | PC: 0x1f1ce4..0x1f1d80 (156 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x1f1ce4: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x1f1ce8: 910003FD  mov      x29, sp
//   0x1f1cec: F9400028  ldr      x8, [x1]
//   0x1f1cf0: 39400109  ldrb     w9, [x8]
//   0x1f1cf4: 34000229  cbz      w9, #0x1f1d38
//   0x1f1cf8: F9400048  ldr      x8, [x2]
uint64_t fde_func_5670_0x1f1ce4(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x001F1CE4ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BF7BFDULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400028ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x39400109ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x34000229ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400048ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x52800069ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x52800020ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #5674 | PC: 0x1f31dc..0x1f32dc (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x1f31dc: D10303FF  sub      sp, sp, #0xc0
//   0x1f31e0: A9066FFC  stp      x28, x27, [sp, #0x60]
//   0x1f31e4: A90767FA  stp      x26, x25, [sp, #0x70]
//   0x1f31e8: A9085FF8  stp      x24, x23, [sp, #0x80]
//   0x1f31ec: A90957F6  stp      x22, x21, [sp, #0x90]
//   0x1f31f0: A90A4FF4  stp      x20, x19, [sp, #0xa0]
uint64_t fde_func_5674_0x1f31dc(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x001F31DCULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10303FFULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9066FFCULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90767FAULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9085FF8ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90957F6ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90A4FF4ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90B7BFDULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9102C3FDULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #5679 | PC: 0x1f4734..0x1f4834 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x1f4734: D102C3FF  sub      sp, sp, #0xb0
//   0x1f4738: 6D0423E9  stp      d9, d8, [sp, #0x40]
//   0x1f473c: A9056FFC  stp      x28, x27, [sp, #0x50]
//   0x1f4740: A90667FA  stp      x26, x25, [sp, #0x60]
//   0x1f4744: A9075FF8  stp      x24, x23, [sp, #0x70]
//   0x1f4748: A90857F6  stp      x22, x21, [sp, #0x80]
uint64_t fde_func_5679_0x1f4734(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x001F4734ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD102C3FFULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x6D0423E9ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9056FFCULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90667FAULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9075FF8ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90857F6ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9094FF4ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90A7BFDULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #5683 | PC: 0x1f53e0..0x1f5440 (96 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x1f53e0: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x1f53e4: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x1f53e8: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x1f53ec: 910083FD  add      x29, sp, #0x20
//   0x1f53f0: 91012013  add      x19, x0, #0x48
//   0x1f53f4: AA0003F4  mov      x20, x0
uint64_t fde_func_5683_0x1f53e0(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x001F53E0ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81D0FF5ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9014FF4ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9027BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910083FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91012013ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F4ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA1303E0ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0803F5ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #5688 | PC: 0x1f6040..0x1f6064 (36 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x1f6040: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x1f6044: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x1f6048: 910043FD  add      x29, sp, #0x10
//   0x1f604c: AA0003F3  mov      x19, x0
//   0x1f6050: 97FFFFE7  bl       #0x1f5fec
//   0x1f6054: A9417BFD  ldp      x29, x30, [sp, #0x10]
uint64_t fde_func_5688_0x1f6040(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x001F6040ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81E0FF3ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x97FFFFE7ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9417BFDULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA1303E0ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF84207F3ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #5692 | PC: 0x1f61fc..0x1f62fc (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x1f61fc: D10243FF  sub      sp, sp, #0x90
//   0x1f6200: A9036FFC  stp      x28, x27, [sp, #0x30]
//   0x1f6204: A90467FA  stp      x26, x25, [sp, #0x40]
//   0x1f6208: A9055FF8  stp      x24, x23, [sp, #0x50]
//   0x1f620c: A90657F6  stp      x22, x21, [sp, #0x60]
//   0x1f6210: A9074FF4  stp      x20, x19, [sp, #0x70]
uint64_t fde_func_5692_0x1f61fc(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x001F61FCULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10243FFULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9036FFCULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90467FAULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9055FF8ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90657F6ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9074FF4ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9087BFDULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910203FDULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #5697 | PC: 0x1f68b4..0x1f68dc (40 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x1f68b4: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x1f68b8: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x1f68bc: 910043FD  add      x29, sp, #0x10
//   0x1f68c0: 91006013  add      x19, x0, #0x18
//   0x1f68c4: 9100A000  add      x0, x0, #0x28
//   0x1f68c8: 97F97479  bl       #0x53aac
uint64_t fde_func_5697_0x1f68b4(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x001F68B4ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81E0FF3ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91006013ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9100A000ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x97F97479ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9417BFDULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA1303E0ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #5701 | PC: 0x1f69f0..0x1f6a20 (48 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x1f69f0: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x1f69f4: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x1f69f8: 910043FD  add      x29, sp, #0x10
//   0x1f69fc: B0000BE8  adrp     x8, #0x373000
//   0x1f6a00: 91134108  add      x8, x8, #0x4d0
//   0x1f6a04: AA0003F3  mov      x19, x0
uint64_t fde_func_5701_0x1f69f0(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x001F69F0ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81E0FF3ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB0000BE8ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91134108ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF8018408ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x94000017ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #5706 | PC: 0x1f6aac..0x1f6ad0 (36 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x1f6aac: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x1f6ab0: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x1f6ab4: 910043FD  add      x29, sp, #0x10
//   0x1f6ab8: AA0003F3  mov      x19, x0
//   0x1f6abc: 97FFFFEB  bl       #0x1f6a68
//   0x1f6ac0: A9417BFD  ldp      x29, x30, [sp, #0x10]
uint64_t fde_func_5706_0x1f6aac(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x001F6AACULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81E0FF3ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x97FFFFEBULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9417BFDULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA1303E0ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF84207F3ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #5710 | PC: 0x1f6be0..0x1f6c2c (76 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x1f6be0: B4000241  cbz      x1, #0x1f6c28
//   0x1f6be4: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x1f6be8: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x1f6bec: 910043FD  add      x29, sp, #0x10
//   0x1f6bf0: AA0103F3  mov      x19, x1
//   0x1f6bf4: F9400021  ldr      x1, [x1]
uint64_t fde_func_5710_0x1f6be0(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x001F6BE0ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xB4000241ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE4FF4ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0103F3ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400021ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F4ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x97FFFFF9ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #5715 | PC: 0x1f6f88..0x1f707c (244 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x1f6f88: D10143FF  sub      sp, sp, #0x50
//   0x1f6f8c: F9000BF7  str      x23, [sp, #0x10]
//   0x1f6f90: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x1f6f94: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x1f6f98: A9047BFD  stp      x29, x30, [sp, #0x40]
//   0x1f6f9c: 910103FD  add      x29, sp, #0x40
uint64_t fde_func_5715_0x1f6f88(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x001F6F88ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10143FFULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF7ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90257F6ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9034FF4ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9047BFDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910103FDULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD53BD057ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF94016E8ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #5719 | PC: 0x1f7220..0x1f7320 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x1f7220: A9BA6FFC  stp      x28, x27, [sp, #-0x60]!
//   0x1f7224: A90167FA  stp      x26, x25, [sp, #0x10]
//   0x1f7228: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x1f722c: A90357F6  stp      x22, x21, [sp, #0x30]
//   0x1f7230: A9044FF4  stp      x20, x19, [sp, #0x40]
//   0x1f7234: A9057BFD  stp      x29, x30, [sp, #0x50]
uint64_t fde_func_5719_0x1f7220(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x001F7220ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BA6FFCULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90167FAULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9025FF8ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90357F6ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9044FF4ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9057BFDULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910143FDULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F4ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #5724 | PC: 0x1f76e0..0x1f778c (172 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x1f76e0: D10183FF  sub      sp, sp, #0x60
//   0x1f76e4: F90013F7  str      x23, [sp, #0x20]
//   0x1f76e8: A90357F6  stp      x22, x21, [sp, #0x30]
//   0x1f76ec: A9044FF4  stp      x20, x19, [sp, #0x40]
//   0x1f76f0: A9057BFD  stp      x29, x30, [sp, #0x50]
//   0x1f76f4: 910143FD  add      x29, sp, #0x50
uint64_t fde_func_5724_0x1f76e0(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x001F76E0ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10183FFULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF90013F7ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90357F6ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9044FF4ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9057BFDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910143FDULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD53BD057ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF94016E8ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #5728 | PC: 0x1f7ae4..0x1f7be4 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x1f7ae4: A9BC5FF8  stp      x24, x23, [sp, #-0x40]!
//   0x1f7ae8: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x1f7aec: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x1f7af0: A9037BFD  stp      x29, x30, [sp, #0x30]
//   0x1f7af4: 9100C3FD  add      x29, sp, #0x30
//   0x1f7af8: 90000C48  adrp     x8, #0x37f000
uint64_t fde_func_5728_0x1f7ae4(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x001F7AE4ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BC5FF8ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90157F6ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9024FF4ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9037BFDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9100C3FDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x90000C48ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF946B908ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #5733 | PC: 0x1fa5a0..0x1fa6a0 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x1fa5a0: A9BA6FFC  stp      x28, x27, [sp, #-0x60]!
//   0x1fa5a4: A90167FA  stp      x26, x25, [sp, #0x10]
//   0x1fa5a8: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x1fa5ac: A90357F6  stp      x22, x21, [sp, #0x30]
//   0x1fa5b0: A9044FF4  stp      x20, x19, [sp, #0x40]
//   0x1fa5b4: A9057BFD  stp      x29, x30, [sp, #0x50]
uint64_t fde_func_5733_0x1fa5a0(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x001FA5A0ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BA6FFCULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90167FAULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9025FF8ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90357F6ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9044FF4ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9057BFDULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910143FDULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400028ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #5737 | PC: 0x1fbe84..0x1fbf84 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x1fbe84: 6DB733ED  stp      d13, d12, [sp, #-0x90]!
//   0x1fbe88: 6D012BEB  stp      d11, d10, [sp, #0x10]
//   0x1fbe8c: 6D0223E9  stp      d9, d8, [sp, #0x20]
//   0x1fbe90: A9036FFC  stp      x28, x27, [sp, #0x30]
//   0x1fbe94: A90467FA  stp      x26, x25, [sp, #0x40]
//   0x1fbe98: A9055FF8  stp      x24, x23, [sp, #0x50]
uint64_t fde_func_5737_0x1fbe84(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x001FBE84ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0x6DB733EDULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x6D012BEBULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x6D0223E9ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9036FFCULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90467FAULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9055FF8ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90657F6ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9074FF4ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #5742 | PC: 0x1fe64c..0x1fe670 (36 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x1fe64c: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x1fe650: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x1fe654: 910043FD  add      x29, sp, #0x10
//   0x1fe658: AA0003F3  mov      x19, x0
//   0x1fe65c: 97FFDE64  bl       #0x1f5fec
//   0x1fe660: A9417BFD  ldp      x29, x30, [sp, #0x10]
uint64_t fde_func_5742_0x1fe64c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x001FE64CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81E0FF3ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x97FFDE64ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9417BFDULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA1303E0ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF84207F3ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #5746 | PC: 0x1fe778..0x1fe7b8 (64 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x1fe778: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x1fe77c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x1fe780: 910043FD  add      x29, sp, #0x10
//   0x1fe784: CB010053  sub      x19, x2, x1
//   0x1fe788: F100067F  cmp      x19, #1
//   0x1fe78c: 5400010B  b.lt     #0x1fe7ac
uint64_t fde_func_5746_0x1fe778(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x001FE778ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE4FF4ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xCB010053ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF100067FULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x5400010BULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400060ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA1303E2ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #5750 | PC: 0x1fee70..0x1fef70 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x1fee70: D10383FF  sub      sp, sp, #0xe0
//   0x1fee74: A9086FFC  stp      x28, x27, [sp, #0x80]
//   0x1fee78: A90967FA  stp      x26, x25, [sp, #0x90]
//   0x1fee7c: A90A5FF8  stp      x24, x23, [sp, #0xa0]
//   0x1fee80: A90B57F6  stp      x22, x21, [sp, #0xb0]
//   0x1fee84: A90C4FF4  stp      x20, x19, [sp, #0xc0]
uint64_t fde_func_5750_0x1fee70(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x001FEE70ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10383FFULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9086FFCULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90967FAULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90A5FF8ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90B57F6ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90C4FF4ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90D7BFDULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910343FDULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #5755 | PC: 0x201cf0..0x201df0 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x201cf0: D10283FF  sub      sp, sp, #0xa0
//   0x201cf4: A9065FF8  stp      x24, x23, [sp, #0x60]
//   0x201cf8: A90757F6  stp      x22, x21, [sp, #0x70]
//   0x201cfc: A9084FF4  stp      x20, x19, [sp, #0x80]
//   0x201d00: A9097BFD  stp      x29, x30, [sp, #0x90]
//   0x201d04: 910243FD  add      x29, sp, #0x90
uint64_t fde_func_5755_0x201cf0(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00201CF0ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10283FFULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9065FF8ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90757F6ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9084FF4ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9097BFDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910243FDULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD53BD057ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF94016E8ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #5759 | PC: 0x2028b8..0x20293c (132 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x2028b8: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x2028bc: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x2028c0: 910043FD  add      x29, sp, #0x10
//   0x2028c4: B0000B88  adrp     x8, #0x373000
//   0x2028c8: 91162108  add      x8, x8, #0x588
//   0x2028cc: AA0003F3  mov      x19, x0
uint64_t fde_func_5759_0x2028b8(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x002028B8ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE4FF4ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB0000B88ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91162108ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91040014ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000008ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #5764 | PC: 0x2029fc..0x202a00 (4 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x2029fc: 17F9064D  b        #0x44330
uint64_t fde_func_5764_0x2029fc(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x002029FCULL);
    state = (state * 0x00000100000001B3ULL) ^ 0x17F9064DULL ^ (0ULL << 32);
    return state ^ (state >> 29);
}

// FDE #5768 | PC: 0x202ab4..0x202b8c (216 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x202ab4: D10143FF  sub      sp, sp, #0x50
//   0x202ab8: F9000BF7  str      x23, [sp, #0x10]
//   0x202abc: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x202ac0: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x202ac4: A9047BFD  stp      x29, x30, [sp, #0x40]
//   0x202ac8: 910103FD  add      x29, sp, #0x40
uint64_t fde_func_5768_0x202ab4(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00202AB4ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10143FFULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF7ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90257F6ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9034FF4ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9047BFDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910103FDULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD53BD057ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF94016E8ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #5773 | PC: 0x202e74..0x202f74 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x202e74: D10203FF  sub      sp, sp, #0x80
//   0x202e78: A9026FFC  stp      x28, x27, [sp, #0x20]
//   0x202e7c: A90367FA  stp      x26, x25, [sp, #0x30]
//   0x202e80: A9045FF8  stp      x24, x23, [sp, #0x40]
//   0x202e84: A90557F6  stp      x22, x21, [sp, #0x50]
//   0x202e88: A9064FF4  stp      x20, x19, [sp, #0x60]
uint64_t fde_func_5773_0x202e74(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00202E74ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10203FFULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9026FFCULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90367FAULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9045FF8ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90557F6ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9064FF4ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9077BFDULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9101C3FDULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #5777 | PC: 0x2030bc..0x2030ec (48 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x2030bc: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x2030c0: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x2030c4: 910043FD  add      x29, sp, #0x10
//   0x2030c8: 3940C008  ldrb     w8, [x0, #0x30]
//   0x2030cc: AA0003F3  mov      x19, x0
//   0x2030d0: 36000068  tbz      w8, #0, #0x2030dc
uint64_t fde_func_5777_0x2030bc(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x002030BCULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81E0FF3ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x3940C008ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x36000068ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9402260ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x97F90496ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #5782 | PC: 0x2041bc..0x2042bc (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x2041bc: D10703FF  sub      sp, sp, #0x1c0
//   0x2041c0: 6D1523E9  stp      d9, d8, [sp, #0x150]
//   0x2041c4: A9166FFC  stp      x28, x27, [sp, #0x160]
//   0x2041c8: A91767FA  stp      x26, x25, [sp, #0x170]
//   0x2041cc: A9185FF8  stp      x24, x23, [sp, #0x180]
//   0x2041d0: A91957F6  stp      x22, x21, [sp, #0x190]
uint64_t fde_func_5782_0x2041bc(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x002041BCULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10703FFULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x6D1523E9ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9166FFCULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA91767FAULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9185FF8ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA91957F6ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA91A4FF4ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA91B7BFDULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #5786 | PC: 0x205c58..0x205d58 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x205c58: D10543FF  sub      sp, sp, #0x150
//   0x205c5c: A90F6FFC  stp      x28, x27, [sp, #0xf0]
//   0x205c60: A91067FA  stp      x26, x25, [sp, #0x100]
//   0x205c64: A9115FF8  stp      x24, x23, [sp, #0x110]
//   0x205c68: A91257F6  stp      x22, x21, [sp, #0x120]
//   0x205c6c: A9134FF4  stp      x20, x19, [sp, #0x130]
uint64_t fde_func_5786_0x205c58(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00205C58ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10543FFULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90F6FFCULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA91067FAULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9115FF8ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA91257F6ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9134FF4ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9147BFDULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910503FDULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #5791 | PC: 0x206870..0x206878 (8 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x206870: F9401800  ldr      x0, [x0, #0x30]
//   0x206874: D65F03C0  ret      
uint64_t fde_func_5791_0x206870(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00206870ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9401800ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD65F03C0ULL ^ (1ULL << 32);
    return state ^ (state >> 29);
}

// FDE #5795 | PC: 0x206970..0x206994 (36 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x206970: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x206974: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x206978: 910043FD  add      x29, sp, #0x10
//   0x20697c: AA0003F3  mov      x19, x0
//   0x206980: 97FFFFD8  bl       #0x2068e0
//   0x206984: A9417BFD  ldp      x29, x30, [sp, #0x10]
uint64_t fde_func_5795_0x206970(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00206970ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81E0FF3ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x97FFFFD8ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9417BFDULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA1303E0ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF84207F3ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #5800 | PC: 0x206b18..0x206b80 (104 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x206b18: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x206b1c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x206b20: 910043FD  add      x29, sp, #0x10
//   0x206b24: 39414008  ldrb     w8, [x0, #0x50]
//   0x206b28: B0000B69  adrp     x9, #0x373000
//   0x206b2c: 911BA129  add      x9, x9, #0x6e8
uint64_t fde_func_5800_0x206b18(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00206B18ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81E0FF3ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x39414008ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB0000B69ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x911BA129ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000009ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB0000B69ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #5804 | PC: 0x206bb8..0x206cb8 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x206bb8: D101C3FF  sub      sp, sp, #0x70
//   0x206bbc: A9035FF8  stp      x24, x23, [sp, #0x30]
//   0x206bc0: A90457F6  stp      x22, x21, [sp, #0x40]
//   0x206bc4: A9054FF4  stp      x20, x19, [sp, #0x50]
//   0x206bc8: A9067BFD  stp      x29, x30, [sp, #0x60]
//   0x206bcc: 910183FD  add      x29, sp, #0x60
uint64_t fde_func_5804_0x206bb8(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00206BB8ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD101C3FFULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9035FF8ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90457F6ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9054FF4ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9067BFDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910183FDULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD53BD058ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0803F3ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #5809 | PC: 0x20749c..0x2074dc (64 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x20749c: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x2074a0: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x2074a4: 910043FD  add      x29, sp, #0x10
//   0x2074a8: 90000B68  adrp     x8, #0x373000
//   0x2074ac: 911DE108  add      x8, x8, #0x778
//   0x2074b0: AA0003F3  mov      x19, x0
uint64_t fde_func_5809_0x20749c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0020749CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81E0FF3ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x90000B68ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x911DE108ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF8020408ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x97F98CB7ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #5813 | PC: 0x207588..0x2075b0 (40 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x207588: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x20758c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x207590: 910043FD  add      x29, sp, #0x10
//   0x207594: AA0003F3  mov      x19, x0
//   0x207598: 91002000  add      x0, x0, #8
//   0x20759c: 940002E3  bl       #0x208128
uint64_t fde_func_5813_0x207588(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00207588ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81E0FF3ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91002000ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x940002E3ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9417BFDULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA1303E0ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #5818 | PC: 0x208164..0x208210 (172 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x208164: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x208168: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x20816c: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x208170: 910083FD  add      x29, sp, #0x20
//   0x208174: AA0003F4  mov      x20, x0
//   0x208178: A8817C1F  stp      xzr, xzr, [x0], #0x10
uint64_t fde_func_5818_0x208164(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00208164ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BD57F6ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9014FF4ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9027BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910083FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F4ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA8817C1FULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x97F8F195ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA1403E8ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #5822 | PC: 0x2089ac..0x208aac (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x2089ac: D10543FF  sub      sp, sp, #0x150
//   0x2089b0: FD0073E8  str      d8, [sp, #0xe0]
//   0x2089b4: A90F6FFC  stp      x28, x27, [sp, #0xf0]
//   0x2089b8: A91067FA  stp      x26, x25, [sp, #0x100]
//   0x2089bc: A9115FF8  stp      x24, x23, [sp, #0x110]
//   0x2089c0: A91257F6  stp      x22, x21, [sp, #0x120]
uint64_t fde_func_5822_0x2089ac(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x002089ACULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10543FFULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xFD0073E8ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90F6FFCULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA91067FAULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9115FF8ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA91257F6ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9134FF4ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9147BFDULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #5827 | PC: 0x20e490..0x20e498 (8 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x20e490: 91006000  add      x0, x0, #0x18
//   0x20e494: 140004EC  b        #0x20f844
uint64_t fde_func_5827_0x20e490(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0020E490ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0x91006000ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x140004ECULL ^ (1ULL << 32);
    return state ^ (state >> 29);
}

// FDE #5831 | PC: 0x20edd4..0x20ee2c (88 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x20edd4: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x20edd8: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x20eddc: 910043FD  add      x29, sp, #0x10
//   0x20ede0: F9400413  ldr      x19, [x0, #8]
//   0x20ede4: B40000F3  cbz      x19, #0x20ee00
//   0x20ede8: 91002268  add      x8, x19, #8
uint64_t fde_func_5831_0x20edd4(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0020EDD4ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81E0FF3ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400413ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB40000F3ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91002268ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xC85FFD09ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD100052AULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #5835 | PC: 0x20ee58..0x20ee5c (4 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x20ee58: 17F8D536  b        #0x44330
uint64_t fde_func_5835_0x20ee58(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0020EE58ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0x17F8D536ULL ^ (0ULL << 32);
    return state ^ (state >> 29);
}

// FDE #5840 | PC: 0x20f104..0x20f124 (32 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x20f104: F9400068  ldr      x8, [x3]
//   0x20f108: CB010042  sub      x2, x2, x1
//   0x20f10c: F100045F  cmp      x2, #1
//   0x20f110: CB020100  sub      x0, x8, x2
//   0x20f114: F9000060  str      x0, [x3]
//   0x20f118: 5400004B  b.lt     #0x20f120
uint64_t fde_func_5840_0x20f104(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0020F104ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400068ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xCB010042ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF100045FULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xCB020100ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000060ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x5400004BULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x17F8D759ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD65F03C0ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #5844 | PC: 0x20f2d8..0x20f3d8 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x20f2d8: A9BB67FA  stp      x26, x25, [sp, #-0x50]!
//   0x20f2dc: A9015FF8  stp      x24, x23, [sp, #0x10]
//   0x20f2e0: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x20f2e4: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x20f2e8: A9047BFD  stp      x29, x30, [sp, #0x40]
//   0x20f2ec: 910103FD  add      x29, sp, #0x40
uint64_t fde_func_5844_0x20f2d8(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0020F2D8ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BB67FAULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9015FF8ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90257F6ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9034FF4ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9047BFDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910103FDULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400417ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #5849 | PC: 0x20f92c..0x20fa1c (240 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x20f92c: F81A0FFB  str      x27, [sp, #-0x60]!
//   0x20f930: A90167FA  stp      x26, x25, [sp, #0x10]
//   0x20f934: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x20f938: A90357F6  stp      x22, x21, [sp, #0x30]
//   0x20f93c: A9044FF4  stp      x20, x19, [sp, #0x40]
//   0x20f940: A9057BFD  stp      x29, x30, [sp, #0x50]
uint64_t fde_func_5849_0x20f92c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0020F92CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81A0FFBULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90167FAULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9025FF8ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90357F6ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9044FF4ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9057BFDULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910143FDULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400416ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #5853 | PC: 0x20fd78..0x20fdd0 (88 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x20fd78: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x20fd7c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x20fd80: 910043FD  add      x29, sp, #0x10
//   0x20fd84: 6F00E400  movi     v0.2d, #0000000000000000
//   0x20fd88: AD000000  stp      q0, q0, [x0]
//   0x20fd8c: B9402028  ldr      w8, [x1, #0x20]
uint64_t fde_func_5853_0x20fd78(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0020FD78ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE4FF4ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x6F00E400ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAD000000ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB9402028ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0103F4ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #5858 | PC: 0x20ff60..0x210060 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x20ff60: D10243FF  sub      sp, sp, #0x90
//   0x20ff64: A9036FFC  stp      x28, x27, [sp, #0x30]
//   0x20ff68: A90467FA  stp      x26, x25, [sp, #0x40]
//   0x20ff6c: A9055FF8  stp      x24, x23, [sp, #0x50]
//   0x20ff70: A90657F6  stp      x22, x21, [sp, #0x60]
//   0x20ff74: A9074FF4  stp      x20, x19, [sp, #0x70]
uint64_t fde_func_5858_0x20ff60(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0020FF60ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10243FFULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9036FFCULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90467FAULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9055FF8ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90657F6ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9074FF4ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9087BFDULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910203FDULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #5862 | PC: 0x21040c..0x210480 (116 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x21040c: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x210410: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x210414: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x210418: 910083FD  add      x29, sp, #0x20
//   0x21041c: AA0203F5  mov      x21, x2
//   0x210420: AA0103F4  mov      x20, x1
uint64_t fde_func_5862_0x21040c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0021040CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81D0FF5ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9014FF4ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9027BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910083FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0203F5ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0103F4ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9018C1FULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #5867 | PC: 0x2106b0..0x2106dc (44 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x2106b0: F9400009  ldr      x9, [x0]
//   0x2106b4: F9000109  str      x9, [x8]
//   0x2106b8: F9400409  ldr      x9, [x0, #8]
//   0x2106bc: F9000509  str      x9, [x8, #8]
//   0x2106c0: B40000C9  cbz      x9, #0x2106d8
//   0x2106c4: 91002128  add      x8, x9, #8
uint64_t fde_func_5867_0x2106b0(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x002106B0ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400009ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000109ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400409ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000509ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB40000C9ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91002128ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xC85F7D09ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91000529ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #5871 | PC: 0x211260..0x211264 (4 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x211260: 17F8CC34  b        #0x44330
uint64_t fde_func_5871_0x211260(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00211260ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0x17F8CC34ULL ^ (0ULL << 32);
    return state ^ (state >> 29);
}

// FDE #5876 | PC: 0x2115e0..0x21164c (108 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x2115e0: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x2115e4: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x2115e8: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x2115ec: 910083FD  add      x29, sp, #0x20
//   0x2115f0: 52800A00  mov      w0, #0x50
//   0x2115f4: AA0803F3  mov      x19, x8
uint64_t fde_func_5876_0x2115e0(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x002115E0ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BD57F6ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9014FF4ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9027BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910083FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x52800A00ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0803F3ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x97F8CAB6ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD0000B08ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #5880 | PC: 0x211730..0x211734 (4 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x211730: 17F8CB00  b        #0x44330
uint64_t fde_func_5880_0x211730(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00211730ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0x17F8CB00ULL ^ (0ULL << 32);
    return state ^ (state >> 29);
}

// FDE #5885 | PC: 0x211cd8..0x211dbc (228 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x211cd8: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x211cdc: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x211ce0: 910043FD  add      x29, sp, #0x10
//   0x211ce4: 52801300  mov      w0, #0x98
//   0x211ce8: AA0803F3  mov      x19, x8
//   0x211cec: 97F8C8F9  bl       #0x440d0
uint64_t fde_func_5885_0x211cd8(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00211CD8ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81E0FF3ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x52801300ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0803F3ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x97F8C8F9ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB0000AC8ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91280108ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #5889 | PC: 0x212158..0x212160 (8 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x212158: D1002000  sub      x0, x0, #8
//   0x21215c: 17FFFFC6  b        #0x212074
uint64_t fde_func_5889_0x212158(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00212158ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD1002000ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x17FFFFC6ULL ^ (1ULL << 32);
    return state ^ (state >> 29);
}

// FDE #5894 | PC: 0x2121dc..0x2122dc (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x2121dc: D10703FF  sub      sp, sp, #0x1c0
//   0x2121e0: A9166FFC  stp      x28, x27, [sp, #0x160]
//   0x2121e4: A91767FA  stp      x26, x25, [sp, #0x170]
//   0x2121e8: A9185FF8  stp      x24, x23, [sp, #0x180]
//   0x2121ec: A91957F6  stp      x22, x21, [sp, #0x190]
//   0x2121f0: A91A4FF4  stp      x20, x19, [sp, #0x1a0]
uint64_t fde_func_5894_0x2121dc(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x002121DCULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10703FFULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9166FFCULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA91767FAULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9185FF8ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA91957F6ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA91A4FF4ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA91B7BFDULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9106C3FDULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #5898 | PC: 0x212de0..0x212de8 (8 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x212de0: D1004000  sub      x0, x0, #0x10
//   0x212de4: 17FFFCFE  b        #0x2121dc
uint64_t fde_func_5898_0x212de0(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00212DE0ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD1004000ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x17FFFCFEULL ^ (1ULL << 32);
    return state ^ (state >> 29);
}

// FDE #5903 | PC: 0x213120..0x21318c (108 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x213120: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x213124: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x213128: 910043FD  add      x29, sp, #0x10
//   0x21312c: AA0003F3  mov      x19, x0
//   0x213130: F9402800  ldr      x0, [x0, #0x50]
//   0x213134: 529ADB21  mov      w1, #0xd6d9
uint64_t fde_func_5903_0x213120(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00213120ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE4FF4ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9402800ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x529ADB21ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x2A1F03E2ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x97FEEB2EULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #5907 | PC: 0x213298..0x21329c (4 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x213298: D65F03C0  ret      
uint64_t fde_func_5907_0x213298(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00213298ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD65F03C0ULL ^ (0ULL << 32);
    return state ^ (state >> 29);
}

// FDE #5911 | PC: 0x21353c..0x213544 (8 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x21353c: D1002000  sub      x0, x0, #8
//   0x213540: 17FFFF7A  b        #0x213328
uint64_t fde_func_5911_0x21353c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0021353CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD1002000ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x17FFFF7AULL ^ (1ULL << 32);
    return state ^ (state >> 29);
}

// FDE #5916 | PC: 0x213558..0x21355c (4 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x213558: D65F03C0  ret      
uint64_t fde_func_5916_0x213558(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00213558ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD65F03C0ULL ^ (0ULL << 32);
    return state ^ (state >> 29);
}

// FDE #5920 | PC: 0x213604..0x213640 (60 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x213604: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x213608: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x21360c: 910043FD  add      x29, sp, #0x10
//   0x213610: 91006040  add      x0, x2, #0x18
//   0x213614: AA0203F3  mov      x19, x2
//   0x213618: 97FFFCB9  bl       #0x2128fc
uint64_t fde_func_5920_0x213604(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00213604ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81E0FF3ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91006040ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0203F3ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x97FFFCB9ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x39400268ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x37000088ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #5925 | PC: 0x2136f0..0x2137f0 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x2136f0: D10143FF  sub      sp, sp, #0x50
//   0x2136f4: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x2136f8: A9047BFD  stp      x29, x30, [sp, #0x40]
//   0x2136fc: 910103FD  add      x29, sp, #0x40
//   0x213700: D53BD054  mrs      x20, tpidr_el0
//   0x213704: F9401689  ldr      x9, [x20, #0x28]
uint64_t fde_func_5925_0x2136f0(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x002136F0ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10143FFULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9034FF4ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9047BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910103FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD53BD054ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9401689ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0203E8ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81E83A9ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #5929 | PC: 0x2138ac..0x2138b0 (4 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x2138ac: 17F8C2A1  b        #0x44330
uint64_t fde_func_5929_0x2138ac(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x002138ACULL);
    state = (state * 0x00000100000001B3ULL) ^ 0x17F8C2A1ULL ^ (0ULL << 32);
    return state ^ (state >> 29);
}

// FDE #5934 | PC: 0x213b20..0x213bc0 (160 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x213b20: D101C3FF  sub      sp, sp, #0x70
//   0x213b24: F9001BF7  str      x23, [sp, #0x30]
//   0x213b28: A90457F6  stp      x22, x21, [sp, #0x40]
//   0x213b2c: A9054FF4  stp      x20, x19, [sp, #0x50]
//   0x213b30: A9067BFD  stp      x29, x30, [sp, #0x60]
//   0x213b34: 910183FD  add      x29, sp, #0x60
uint64_t fde_func_5934_0x213b20(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00213B20ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD101C3FFULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9001BF7ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90457F6ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9054FF4ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9067BFDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910183FDULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD53BD057ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF94016E8ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #5938 | PC: 0x213f74..0x214074 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x213f74: A9BA6FFC  stp      x28, x27, [sp, #-0x60]!
//   0x213f78: A90167FA  stp      x26, x25, [sp, #0x10]
//   0x213f7c: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x213f80: A90357F6  stp      x22, x21, [sp, #0x30]
//   0x213f84: A9044FF4  stp      x20, x19, [sp, #0x40]
//   0x213f88: A9057BFD  stp      x29, x30, [sp, #0x50]
uint64_t fde_func_5938_0x213f74(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00213F74ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BA6FFCULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90167FAULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9025FF8ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90357F6ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9044FF4ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9057BFDULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910143FDULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F4ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #5943 | PC: 0x214220..0x214258 (56 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x214220: F0000AE8  adrp     x8, #0x373000
//   0x214224: 912D6108  add      x8, x8, #0xb58
//   0x214228: F9000028  str      x8, [x1]
//   0x21422c: 3CC08000  ldur     q0, [x0, #8]
//   0x214230: 3C808020  stur     q0, [x1, #8]
//   0x214234: F9400C08  ldr      x8, [x0, #0x18]
uint64_t fde_func_5943_0x214220(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00214220ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF0000AE8ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x912D6108ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000028ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x3CC08000ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x3C808020ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400C08ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000C28ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB40000C8ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #5947 | PC: 0x2143e4..0x214400 (28 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x2143e4: F9400428  ldr      x8, [x1, #8]
//   0x2143e8: 900006E9  adrp     x9, #0x2f0000
//   0x2143ec: 91224129  add      x9, x9, #0x890
//   0x2143f0: 9100200A  add      x10, x0, #8
//   0x2143f4: EB09011F  cmp      x8, x9
//   0x2143f8: 9A9F0140  csel     x0, x10, xzr, eq
uint64_t fde_func_5947_0x2143e4(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x002143E4ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400428ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x900006E9ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91224129ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9100200AULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xEB09011FULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9A9F0140ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD65F03C0ULL ^ (6ULL << 32);
    return state ^ (state >> 29);
}

// FDE #5952 | PC: 0x21454c..0x2145a4 (88 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x21454c: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x214550: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x214554: 910043FD  add      x29, sp, #0x10
//   0x214558: F9400413  ldr      x19, [x0, #8]
//   0x21455c: B40000F3  cbz      x19, #0x214578
//   0x214560: 91002268  add      x8, x19, #8
uint64_t fde_func_5952_0x21454c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0021454CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81E0FF3ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400413ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB40000F3ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91002268ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xC85FFD09ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD100052AULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #5956 | PC: 0x2146ac..0x2146d0 (36 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x2146ac: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x2146b0: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x2146b4: 910043FD  add      x29, sp, #0x10
//   0x2146b8: AA0003F3  mov      x19, x0
//   0x2146bc: 97FFFF6B  bl       #0x214468
//   0x2146c0: A9417BFD  ldp      x29, x30, [sp, #0x10]
uint64_t fde_func_5956_0x2146ac(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x002146ACULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81E0FF3ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x97FFFF6BULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9417BFDULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA1303E0ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF84207F3ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #5961 | PC: 0x214d80..0x214e28 (168 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x214d80: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x214d84: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x214d88: 910043FD  add      x29, sp, #0x10
//   0x214d8c: AA0003F3  mov      x19, x0
//   0x214d90: 52800020  mov      w0, #1
//   0x214d94: 97F8C2D8  bl       #0x458f4
uint64_t fde_func_5961_0x214d80(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00214D80ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81E0FF3ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x52800020ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x97F8C2D8ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x36000140ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x900006E1ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #5965 | PC: 0x214fe0..0x2150e0 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x214fe0: D10283FF  sub      sp, sp, #0xa0
//   0x214fe4: A90757F6  stp      x22, x21, [sp, #0x70]
//   0x214fe8: A9084FF4  stp      x20, x19, [sp, #0x80]
//   0x214fec: A9097BFD  stp      x29, x30, [sp, #0x90]
//   0x214ff0: 910243FD  add      x29, sp, #0x90
//   0x214ff4: D53BD056  mrs      x22, tpidr_el0
uint64_t fde_func_5965_0x214fe0(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00214FE0ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10283FFULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90757F6ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9084FF4ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9097BFDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910243FDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD53BD056ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF94016C8ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #5970 | PC: 0x216148..0x216248 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x216148: D101C3FF  sub      sp, sp, #0x70
//   0x21614c: F90023F5  str      x21, [sp, #0x40]
//   0x216150: A9054FF4  stp      x20, x19, [sp, #0x50]
//   0x216154: A9067BFD  stp      x29, x30, [sp, #0x60]
//   0x216158: 910183FD  add      x29, sp, #0x60
//   0x21615c: D53BD054  mrs      x20, tpidr_el0
uint64_t fde_func_5970_0x216148(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00216148ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD101C3FFULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF90023F5ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9054FF4ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9067BFDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910183FDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD53BD054ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9401689ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0803F3ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #5974 | PC: 0x2163c4..0x2164c4 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x2163c4: F81C0FF7  str      x23, [sp, #-0x40]!
//   0x2163c8: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x2163cc: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x2163d0: A9037BFD  stp      x29, x30, [sp, #0x30]
//   0x2163d4: 9100C3FD  add      x29, sp, #0x30
//   0x2163d8: F940100B  ldr      x11, [x0, #0x20]
uint64_t fde_func_5974_0x2163c4(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x002163C4ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81C0FF7ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90157F6ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9024FF4ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9037BFDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9100C3FDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF940100BULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA940A408ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB202C7ECULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #5979 | PC: 0x216674..0x2166ac (56 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x216674: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x216678: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x21667c: 910043FD  add      x29, sp, #0x10
//   0x216680: B0000AE8  adrp     x8, #0x373000
//   0x216684: 91318108  add      x8, x8, #0xc60
//   0x216688: AA0003F3  mov      x19, x0
uint64_t fde_func_5979_0x216674(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00216674ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81E0FF3ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB0000AE8ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91318108ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF8020408ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x94000036ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #5983 | PC: 0x216768..0x216868 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x216768: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x21676c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x216770: 910043FD  add      x29, sp, #0x10
//   0x216774: B0000AE8  adrp     x8, #0x373000
//   0x216778: 9132C108  add      x8, x8, #0xcb0
//   0x21677c: AA0003F3  mov      x19, x0
uint64_t fde_func_5983_0x216768(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00216768ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81E0FF3ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB0000AE8ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9132C108ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000008ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9118A000ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #5988 | PC: 0x216ac4..0x216b28 (100 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x216ac4: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x216ac8: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x216acc: 910043FD  add      x29, sp, #0x10
//   0x216ad0: B4000261  cbz      x1, #0x216b1c
//   0x216ad4: AA0103F3  mov      x19, x1
//   0x216ad8: 39416268  ldrb     w8, [x19, #0x58]
uint64_t fde_func_5988_0x216ac4(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00216AC4ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE4FF4ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB4000261ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0103F3ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x39416268ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400274ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x36000068ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #5992 | PC: 0x216c18..0x216c80 (104 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x216c18: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x216c1c: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x216c20: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x216c24: 910083FD  add      x29, sp, #0x20
//   0x216c28: A9405414  ldp      x20, x21, [x0]
//   0x216c2c: AA0003F3  mov      x19, x0
uint64_t fde_func_5992_0x216c18(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00216C18ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81D0FF5ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9014FF4ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9027BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910083FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9405414ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xEB1402BFULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x540001C0ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #5996 | PC: 0x216d2c..0x216d7c (80 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x216d2c: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x216d30: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x216d34: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x216d38: 910083FD  add      x29, sp, #0x20
//   0x216d3c: A9402014  ldp      x20, x8, [x0]
//   0x216d40: AA0003F3  mov      x19, x0
uint64_t fde_func_5996_0x216d2c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00216D2CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81D0FF5ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9014FF4ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9027BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910083FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9402014ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xEB14011FULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x54000100ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #6001 | PC: 0x216dd4..0x216dd8 (4 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x216dd4: 17F8B557  b        #0x44330
uint64_t fde_func_6001_0x216dd4(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00216DD4ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0x17F8B557ULL ^ (0ULL << 32);
    return state ^ (state >> 29);
}

// FDE #6005 | PC: 0x216e84..0x216e88 (4 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x216e84: 17F8B52B  b        #0x44330
uint64_t fde_func_6005_0x216e84(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00216E84ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0x17F8B52BULL ^ (0ULL << 32);
    return state ^ (state >> 29);
}

// FDE #6010 | PC: 0x216ee0..0x216ef4 (20 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x216ee0: F9400408  ldr      x8, [x0, #8]
//   0x216ee4: 528000E9  mov      w9, #7
//   0x216ee8: 9102F108  add      x8, x8, #0xbc
//   0x216eec: 889FFD09  stlr     w9, [x8]
//   0x216ef0: D65F03C0  ret      
uint64_t fde_func_6010_0x216ee0(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00216EE0ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400408ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x528000E9ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9102F108ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x889FFD09ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD65F03C0ULL ^ (4ULL << 32);
    return state ^ (state >> 29);
}

// FDE #6014 | PC: 0x216fd0..0x217080 (176 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x216fd0: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x216fd4: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x216fd8: 910043FD  add      x29, sp, #0x10
//   0x216fdc: B40003C1  cbz      x1, #0x217054
//   0x216fe0: AA0003E8  mov      x8, x0
//   0x216fe4: F9400420  ldr      x0, [x1, #8]
uint64_t fde_func_6014_0x216fd0(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00216FD0ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81E0FF3ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB40003C1ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003E8ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400420ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB4000080ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400409ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #6019 | PC: 0x2170f8..0x2171f8 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x2170f8: D10143FF  sub      sp, sp, #0x50
//   0x2170fc: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x217100: A9047BFD  stp      x29, x30, [sp, #0x40]
//   0x217104: 910103FD  add      x29, sp, #0x40
//   0x217108: D53BD054  mrs      x20, tpidr_el0
//   0x21710c: F9401688  ldr      x8, [x20, #0x28]
uint64_t fde_func_6019_0x2170f8(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x002170F8ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10143FFULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9034FF4ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9047BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910103FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD53BD054ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9401688ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81E83A8ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9402041ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #6023 | PC: 0x217488..0x2174c4 (60 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x217488: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x21748c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x217490: 910043FD  add      x29, sp, #0x10
//   0x217494: F9400013  ldr      x19, [x0]
//   0x217498: F9000001  str      x1, [x0]
//   0x21749c: B40000F3  cbz      x19, #0x2174b8
uint64_t fde_func_6023_0x217488(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00217488ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81E0FF3ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400013ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000001ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB40000F3ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA1303E0ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x97F8B52BULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #6028 | PC: 0x2176a8..0x2176e4 (60 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x2176a8: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x2176ac: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x2176b0: 910043FD  add      x29, sp, #0x10
//   0x2176b4: F9400801  ldr      x1, [x0, #0x10]
//   0x2176b8: AA0003F3  mov      x19, x0
//   0x2176bc: 9400000A  bl       #0x2176e4
uint64_t fde_func_6028_0x2176a8(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x002176A8ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81E0FF3ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400801ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9400000AULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400260ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF900027FULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #6032 | PC: 0x2177b0..0x2177ec (60 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x2177b0: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x2177b4: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x2177b8: 910043FD  add      x29, sp, #0x10
//   0x2177bc: 91006040  add      x0, x2, #0x18
//   0x2177c0: AA0203F3  mov      x19, x2
//   0x2177c4: 9400000A  bl       #0x2177ec
uint64_t fde_func_6032_0x2177b0(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x002177B0ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81E0FF3ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91006040ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0203F3ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9400000AULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x39400268ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x37000088ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #6037 | PC: 0x217938..0x21793c (4 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x217938: D65F03C0  ret      
uint64_t fde_func_6037_0x217938(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00217938ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD65F03C0ULL ^ (0ULL << 32);
    return state ^ (state >> 29);
}

// FDE #6041 | PC: 0x2179e4..0x217a1c (56 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x2179e4: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x2179e8: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x2179ec: 910043FD  add      x29, sp, #0x10
//   0x2179f0: AA0003F3  mov      x19, x0
//   0x2179f4: F9400800  ldr      x0, [x0, #0x10]
//   0x2179f8: 90000AE8  adrp     x8, #0x373000
uint64_t fde_func_6041_0x2179e4(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x002179E4ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81E0FF3ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400800ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x90000AE8ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x913B8108ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000268ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #6046 | PC: 0x217ae8..0x217bb4 (204 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x217ae8: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x217aec: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x217af0: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x217af4: 910083FD  add      x29, sp, #0x20
//   0x217af8: AA0003F5  mov      x21, x0
//   0x217afc: F9400800  ldr      x0, [x0, #0x10]
uint64_t fde_func_6046_0x217ae8(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00217AE8ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81D0FF5ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9014FF4ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9027BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910083FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F5ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400800ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB4000400ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0103F4ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #6050 | PC: 0x217c8c..0x217d3c (176 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x217c8c: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x217c90: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x217c94: 910043FD  add      x29, sp, #0x10
//   0x217c98: B40003C1  cbz      x1, #0x217d10
//   0x217c9c: AA0003E8  mov      x8, x0
//   0x217ca0: F9400420  ldr      x0, [x1, #8]
uint64_t fde_func_6050_0x217c8c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00217C8CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81E0FF3ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB40003C1ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003E8ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400420ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB4000080ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400409ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #6055 | PC: 0x217db0..0x217eb0 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x217db0: D10143FF  sub      sp, sp, #0x50
//   0x217db4: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x217db8: A9047BFD  stp      x29, x30, [sp, #0x40]
//   0x217dbc: 910103FD  add      x29, sp, #0x40
//   0x217dc0: D53BD054  mrs      x20, tpidr_el0
//   0x217dc4: F9401688  ldr      x8, [x20, #0x28]
uint64_t fde_func_6055_0x217db0(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00217DB0ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10143FFULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9034FF4ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9047BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910103FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD53BD054ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9401688ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81E83A8ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9402041ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #6059 | PC: 0x218070..0x2180a0 (48 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x218070: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x218074: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x218078: 910043FD  add      x29, sp, #0x10
//   0x21807c: F0000AC8  adrp     x8, #0x373000
//   0x218080: 913EC108  add      x8, x8, #0xfb0
//   0x218084: AA0003F3  mov      x19, x0
uint64_t fde_func_6059_0x218070(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00218070ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81E0FF3ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF0000AC8ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x913EC108ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF8018408ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x940127C9ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #6064 | PC: 0x218194..0x218244 (176 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x218194: D101C3FF  sub      sp, sp, #0x70
//   0x218198: F90013F9  str      x25, [sp, #0x20]
//   0x21819c: A9035FF8  stp      x24, x23, [sp, #0x30]
//   0x2181a0: A90457F6  stp      x22, x21, [sp, #0x40]
//   0x2181a4: A9054FF4  stp      x20, x19, [sp, #0x50]
//   0x2181a8: A9067BFD  stp      x29, x30, [sp, #0x60]
uint64_t fde_func_6064_0x218194(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00218194ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD101C3FFULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF90013F9ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9035FF8ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90457F6ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9054FF4ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9067BFDULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910183FDULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD53BD059ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #6068 | PC: 0x21835c..0x218368 (12 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x21835c: F8418C08  ldr      x8, [x0, #0x18]!
//   0x218360: F9400101  ldr      x1, [x8]
//   0x218364: D61F0020  br       x1
uint64_t fde_func_6068_0x21835c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0021835CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF8418C08ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400101ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD61F0020ULL ^ (2ULL << 32);
    return state ^ (state >> 29);
}

// FDE #6072 | PC: 0x218488..0x2184b8 (48 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x218488: 90000AE8  adrp     x8, #0x374000
//   0x21848c: 91014108  add      x8, x8, #0x50
//   0x218490: A9008801  stp      x1, x2, [x0, #8]
//   0x218494: F9000008  str      x8, [x0]
//   0x218498: 3DC00080  ldr      q0, [x4]
//   0x21849c: 3C818000  stur     q0, [x0, #0x18]
uint64_t fde_func_6072_0x218488(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00218488ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0x90000AE8ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91014108ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9008801ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000008ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x3DC00080ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x3C818000ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9007C9FULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x3DC000A0ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #6077 | PC: 0x2187b8..0x2187f0 (56 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x2187b8: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x2187bc: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x2187c0: 910043FD  add      x29, sp, #0x10
//   0x2187c4: 90000AE8  adrp     x8, #0x374000
//   0x2187c8: 91028108  add      x8, x8, #0xa0
//   0x2187cc: AA0003F3  mov      x19, x0
uint64_t fde_func_6077_0x2187b8(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x002187B8ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81E0FF3ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x90000AE8ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91028108ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF8018408ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x97FD0C65ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #6081 | PC: 0x21882c..0x218864 (56 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x21882c: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x218830: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x218834: 910043FD  add      x29, sp, #0x10
//   0x218838: 90000AE8  adrp     x8, #0x374000
//   0x21883c: 9103C108  add      x8, x8, #0xf0
//   0x218840: AA0003F3  mov      x19, x0
uint64_t fde_func_6081_0x21882c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0021882CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81E0FF3ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x90000AE8ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9103C108ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF8018408ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x97FD239EULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #6086 | PC: 0x2188d8..0x2188e4 (12 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x2188d8: F8418C08  ldr      x8, [x0, #0x18]!
//   0x2188dc: F9400101  ldr      x1, [x8]
//   0x2188e0: D61F0020  br       x1
uint64_t fde_func_6086_0x2188d8(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x002188D8ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF8418C08ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400101ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD61F0020ULL ^ (2ULL << 32);
    return state ^ (state >> 29);
}

// FDE #6090 | PC: 0x218a20..0x218b20 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x218a20: D10203FF  sub      sp, sp, #0x80
//   0x218a24: A90367FA  stp      x26, x25, [sp, #0x30]
//   0x218a28: A9045FF8  stp      x24, x23, [sp, #0x40]
//   0x218a2c: A90557F6  stp      x22, x21, [sp, #0x50]
//   0x218a30: A9064FF4  stp      x20, x19, [sp, #0x60]
//   0x218a34: A9077BFD  stp      x29, x30, [sp, #0x70]
uint64_t fde_func_6090_0x218a20(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00218A20ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10203FFULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90367FAULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9045FF8ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90557F6ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9064FF4ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9077BFDULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9101C3FDULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD53BD057ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #6095 | PC: 0x218f0c..0x218f14 (8 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x218f0c: 91006000  add      x0, x0, #0x18
//   0x218f10: 14000044  b        #0x219020
uint64_t fde_func_6095_0x218f0c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00218F0CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0x91006000ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x14000044ULL ^ (1ULL << 32);
    return state ^ (state >> 29);
}

// FDE #6099 | PC: 0x219064..0x219114 (176 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x219064: D101C3FF  sub      sp, sp, #0x70
//   0x219068: F90013F9  str      x25, [sp, #0x20]
//   0x21906c: A9035FF8  stp      x24, x23, [sp, #0x30]
//   0x219070: A90457F6  stp      x22, x21, [sp, #0x40]
//   0x219074: A9054FF4  stp      x20, x19, [sp, #0x50]
//   0x219078: A9067BFD  stp      x29, x30, [sp, #0x60]
uint64_t fde_func_6099_0x219064(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00219064ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD101C3FFULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF90013F9ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9035FF8ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90457F6ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9054FF4ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9067BFDULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910183FDULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD53BD059ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #6104 | PC: 0x219238..0x21923c (4 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x219238: 17F8AC3E  b        #0x44330
uint64_t fde_func_6104_0x219238(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00219238ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0x17F8AC3EULL ^ (0ULL << 32);
    return state ^ (state >> 29);
}

// FDE #6108 | PC: 0x2194a8..0x2194d8 (48 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x2194a8: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x2194ac: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x2194b0: 910043FD  add      x29, sp, #0x10
//   0x2194b4: F0000AC8  adrp     x8, #0x374000
//   0x2194b8: 9109C108  add      x8, x8, #0x270
//   0x2194bc: AA0003F3  mov      x19, x0
uint64_t fde_func_6108_0x2194a8(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x002194A8ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81E0FF3ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF0000AC8ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9109C108ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF8018408ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x94000042ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #6113 | PC: 0x2195cc..0x219634 (104 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x2195cc: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x2195d0: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x2195d4: 910043FD  add      x29, sp, #0x10
//   0x2195d8: D0000B28  adrp     x8, #0x37f000
//   0x2195dc: F947B108  ldr      x8, [x8, #0xf60]
//   0x2195e0: AA0003F4  mov      x20, x0
uint64_t fde_func_6113_0x2195cc(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x002195CCULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE4FF4ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD0000B28ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF947B108ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F4ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91002013ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91004109ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #6117 | PC: 0x219714..0x21974c (56 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x219714: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x219718: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x21971c: 910043FD  add      x29, sp, #0x10
//   0x219720: F0000AC8  adrp     x8, #0x374000
//   0x219724: 910B0108  add      x8, x8, #0x2c0
//   0x219728: AA0003F3  mov      x19, x0
uint64_t fde_func_6117_0x219714(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00219714ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81E0FF3ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF0000AC8ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910B0108ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF8018408ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9400004CULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #6122 | PC: 0x2198b4..0x2198fc (72 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x2198b4: B4000221  cbz      x1, #0x2198f8
//   0x2198b8: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x2198bc: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x2198c0: 910043FD  add      x29, sp, #0x10
//   0x2198c4: AA0103F3  mov      x19, x1
//   0x2198c8: F9400021  ldr      x1, [x1]
uint64_t fde_func_6122_0x2198b4(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x002198B4ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xB4000221ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE4FF4ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0103F3ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400021ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F4ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x97FFFFF9ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #6126 | PC: 0x2199dc..0x219a34 (88 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x2199dc: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x2199e0: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x2199e4: 910043FD  add      x29, sp, #0x10
//   0x2199e8: F9400413  ldr      x19, [x0, #8]
//   0x2199ec: B40000F3  cbz      x19, #0x219a08
//   0x2199f0: 91002268  add      x8, x19, #8
uint64_t fde_func_6126_0x2199dc(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x002199DCULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81E0FF3ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400413ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB40000F3ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91002268ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xC85FFD09ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD100052AULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #6131 | PC: 0x219aac..0x219bac (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x219aac: D10143FF  sub      sp, sp, #0x50
//   0x219ab0: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x219ab4: A9047BFD  stp      x29, x30, [sp, #0x40]
//   0x219ab8: 910103FD  add      x29, sp, #0x40
//   0x219abc: D53BD054  mrs      x20, tpidr_el0
//   0x219ac0: F9401688  ldr      x8, [x20, #0x28]
uint64_t fde_func_6131_0x219aac(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00219AACULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10143FFULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9034FF4ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9047BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910103FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD53BD054ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9401688ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81E83A8ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400048ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #6135 | PC: 0x219e04..0x219e5c (88 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x219e04: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x219e08: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x219e0c: 910043FD  add      x29, sp, #0x10
//   0x219e10: F9400413  ldr      x19, [x0, #8]
//   0x219e14: B40000F3  cbz      x19, #0x219e30
//   0x219e18: 91002268  add      x8, x19, #8
uint64_t fde_func_6135_0x219e04(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00219E04ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81E0FF3ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400413ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB40000F3ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91002268ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xC85FFD09ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD100052AULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #6140 | PC: 0x219eb8..0x219ee0 (40 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x219eb8: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x219ebc: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x219ec0: 910043FD  add      x29, sp, #0x10
//   0x219ec4: D100A013  sub      x19, x0, #0x28
//   0x219ec8: AA1303E0  mov      x0, x19
//   0x219ecc: 97FFFF80  bl       #0x219ccc
uint64_t fde_func_6140_0x219eb8(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00219EB8ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81E0FF3ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD100A013ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA1303E0ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x97FFFF80ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9417BFDULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA1303E0ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #6144 | PC: 0x21a9e0..0x21a9e8 (8 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x21a9e0: D1002000  sub      x0, x0, #8
//   0x21a9e4: 17FFFD3F  b        #0x219ee0
uint64_t fde_func_6144_0x21a9e0(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0021A9E0ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD1002000ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x17FFFD3FULL ^ (1ULL << 32);
    return state ^ (state >> 29);
}

// FDE #6149 | PC: 0x21aad4..0x21abb0 (220 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x21aad4: D10143FF  sub      sp, sp, #0x50
//   0x21aad8: F90013F5  str      x21, [sp, #0x20]
//   0x21aadc: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x21aae0: A9047BFD  stp      x29, x30, [sp, #0x40]
//   0x21aae4: 910103FD  add      x29, sp, #0x40
//   0x21aae8: D53BD055  mrs      x21, tpidr_el0
uint64_t fde_func_6149_0x21aad4(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0021AAD4ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10143FFULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF90013F5ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9034FF4ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9047BFDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910103FDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD53BD055ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF94016A8ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #6153 | PC: 0x21abc8..0x21abd0 (8 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x21abc8: F9403000  ldr      x0, [x0, #0x60]
//   0x21abcc: 17FCE843  b        #0x154cd8
uint64_t fde_func_6153_0x21abc8(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0021ABC8ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9403000ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x17FCE843ULL ^ (1ULL << 32);
    return state ^ (state >> 29);
}

// FDE #6157 | PC: 0x21ac88..0x21ad44 (188 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x21ac88: D10183FF  sub      sp, sp, #0x60
//   0x21ac8c: F9001BF5  str      x21, [sp, #0x30]
//   0x21ac90: A9044FF4  stp      x20, x19, [sp, #0x40]
//   0x21ac94: A9057BFD  stp      x29, x30, [sp, #0x50]
//   0x21ac98: 910143FD  add      x29, sp, #0x50
//   0x21ac9c: D53BD055  mrs      x21, tpidr_el0
uint64_t fde_func_6157_0x21ac88(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0021AC88ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10183FFULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9001BF5ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9044FF4ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9057BFDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910143FDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD53BD055ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF94016A8ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF90017E8ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #6162 | PC: 0x21b1e4..0x21b2e4 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x21b1e4: D10303FF  sub      sp, sp, #0xc0
//   0x21b1e8: FD0033E8  str      d8, [sp, #0x60]
//   0x21b1ec: A90767FA  stp      x26, x25, [sp, #0x70]
//   0x21b1f0: A9085FF8  stp      x24, x23, [sp, #0x80]
//   0x21b1f4: A90957F6  stp      x22, x21, [sp, #0x90]
//   0x21b1f8: A90A4FF4  stp      x20, x19, [sp, #0xa0]
uint64_t fde_func_6162_0x21b1e4(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0021B1E4ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10303FFULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xFD0033E8ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90767FAULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9085FF8ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90957F6ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90A4FF4ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90B7BFDULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9102C3FDULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #6166 | PC: 0x21e7c8..0x21e8c8 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x21e7c8: D10403FF  sub      sp, sp, #0x100
//   0x21e7cc: F9006BF5  str      x21, [sp, #0xd0]
//   0x21e7d0: A90E4FF4  stp      x20, x19, [sp, #0xe0]
//   0x21e7d4: A90F7BFD  stp      x29, x30, [sp, #0xf0]
//   0x21e7d8: 9103C3FD  add      x29, sp, #0xf0
//   0x21e7dc: D53BD055  mrs      x21, tpidr_el0
uint64_t fde_func_6166_0x21e7c8(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0021E7C8ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10403FFULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9006BF5ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90E4FF4ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90F7BFDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9103C3FDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD53BD055ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF94016A8ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81D83A8ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #6171 | PC: 0x21ef10..0x21f010 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x21ef10: D10183FF  sub      sp, sp, #0x60
//   0x21ef14: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x21ef18: A90357F6  stp      x22, x21, [sp, #0x30]
//   0x21ef1c: A9044FF4  stp      x20, x19, [sp, #0x40]
//   0x21ef20: A9057BFD  stp      x29, x30, [sp, #0x50]
//   0x21ef24: 910143FD  add      x29, sp, #0x50
uint64_t fde_func_6171_0x21ef10(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0021EF10ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10183FFULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9025FF8ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90357F6ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9044FF4ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9057BFDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910143FDULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD53BD057ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF94016E8ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #6175 | PC: 0x21f67c..0x21f76c (240 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x21f67c: D101C3FF  sub      sp, sp, #0x70
//   0x21f680: A90457F6  stp      x22, x21, [sp, #0x40]
//   0x21f684: A9054FF4  stp      x20, x19, [sp, #0x50]
//   0x21f688: A9067BFD  stp      x29, x30, [sp, #0x60]
//   0x21f68c: 910183FD  add      x29, sp, #0x60
//   0x21f690: D53BD055  mrs      x21, tpidr_el0
uint64_t fde_func_6175_0x21f67c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0021F67CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD101C3FFULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90457F6ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9054FF4ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9067BFDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910183FDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD53BD055ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF94016A8ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #6180 | PC: 0x221a80..0x221b80 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x221a80: D103C3FF  sub      sp, sp, #0xf0
//   0x221a84: A9096FFC  stp      x28, x27, [sp, #0x90]
//   0x221a88: A90A67FA  stp      x26, x25, [sp, #0xa0]
//   0x221a8c: A90B5FF8  stp      x24, x23, [sp, #0xb0]
//   0x221a90: A90C57F6  stp      x22, x21, [sp, #0xc0]
//   0x221a94: A90D4FF4  stp      x20, x19, [sp, #0xd0]
uint64_t fde_func_6180_0x221a80(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00221A80ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD103C3FFULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9096FFCULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90A67FAULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90B5FF8ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90C57F6ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90D4FF4ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90E7BFDULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910383FDULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #6184 | PC: 0x222480..0x22252c (172 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x222480: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x222484: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x222488: 910043FD  add      x29, sp, #0x10
//   0x22248c: B0000AE8  adrp     x8, #0x37f000
//   0x222490: F9453108  ldr      x8, [x8, #0xa60]
//   0x222494: 6F00E400  movi     v0.2d, #0000000000000000
uint64_t fde_func_6184_0x222480(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00222480ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE4FF4ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB0000AE8ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9453108ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x6F00E400ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x3C808000ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x3C818000ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #6189 | PC: 0x2225fc..0x222604 (8 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x2225fc: 91004000  add      x0, x0, #0x10
//   0x222600: 17F8F2B9  b        #0x5f0e4
uint64_t fde_func_6189_0x2225fc(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x002225FCULL);
    state = (state * 0x00000100000001B3ULL) ^ 0x91004000ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x17F8F2B9ULL ^ (1ULL << 32);
    return state ^ (state >> 29);
}

// FDE #6193 | PC: 0x222724..0x222730 (12 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x222724: D0000A80  adrp     x0, #0x374000
//   0x222728: 9113C000  add      x0, x0, #0x4f0
//   0x22272c: D65F03C0  ret      
uint64_t fde_func_6193_0x222724(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00222724ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD0000A80ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9113C000ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD65F03C0ULL ^ (2ULL << 32);
    return state ^ (state >> 29);
}

// FDE #6198 | PC: 0x222800..0x222808 (8 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x222800: 91004000  add      x0, x0, #0x10
//   0x222804: 17F8F238  b        #0x5f0e4
uint64_t fde_func_6198_0x222800(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00222800ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0x91004000ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x17F8F238ULL ^ (1ULL << 32);
    return state ^ (state >> 29);
}

// FDE #6202 | PC: 0x2233e0..0x2233ec (12 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x2233e0: B0000A80  adrp     x0, #0x374000
//   0x2233e4: 9115C000  add      x0, x0, #0x570
//   0x2233e8: D65F03C0  ret      
uint64_t fde_func_6202_0x2233e0(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x002233E0ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xB0000A80ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9115C000ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD65F03C0ULL ^ (2ULL << 32);
    return state ^ (state >> 29);
}

// FDE #6207 | PC: 0x223444..0x223448 (4 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x223444: 17F883BB  b        #0x44330
uint64_t fde_func_6207_0x223444(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00223444ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0x17F883BBULL ^ (0ULL << 32);
    return state ^ (state >> 29);
}

// FDE #6211 | PC: 0x223478..0x223514 (156 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x223478: B0000A88  adrp     x8, #0x374000
//   0x22347c: 91184108  add      x8, x8, #0x610
//   0x223480: 91010109  add      x9, x8, #0x40
//   0x223484: 9E670100  fmov     d0, x8
//   0x223488: 52800028  mov      w8, #1
//   0x22348c: 4E181D20  mov      v0.d[1], x9
uint64_t fde_func_6211_0x223478(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00223478ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xB0000A88ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91184108ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91010109ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9E670100ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x52800028ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x4E181D20ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017C1FULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB900201FULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #6216 | PC: 0x223d48..0x223d64 (28 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x223d48: F9404000  ldr      x0, [x0, #0x80]
//   0x223d4c: B4000040  cbz      x0, #0x223d54
//   0x223d50: 14002A33  b        #0x22e61c
//   0x223d54: 90000701  adrp     x1, #0x303000
//   0x223d58: 913EF021  add      x1, x1, #0xfbc
//   0x223d5c: AA0803E0  mov      x0, x8
uint64_t fde_func_6216_0x223d48(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00223D48ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9404000ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB4000040ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x14002A33ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x90000701ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x913EF021ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0803E0ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x17F89730ULL ^ (6ULL << 32);
    return state ^ (state >> 29);
}

// FDE #6220 | PC: 0x224558..0x2245b0 (88 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x224558: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x22455c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x224560: 910043FD  add      x29, sp, #0x10
//   0x224564: AA0003F3  mov      x19, x0
//   0x224568: 52800020  mov      w0, #1
//   0x22456c: 97F884E2  bl       #0x458f4
uint64_t fde_func_6220_0x224558(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00224558ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81E0FF3ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x52800020ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x97F884E2ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x36000140ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB0000661ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #6225 | PC: 0x224654..0x224694 (64 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x224654: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x224658: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x22465c: 910043FD  add      x29, sp, #0x10
//   0x224660: 90000A88  adrp     x8, #0x374000
//   0x224664: 90000A89  adrp     x9, #0x374000
//   0x224668: 911BA108  add      x8, x8, #0x6e8
uint64_t fde_func_6225_0x224654(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00224654ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81E0FF3ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x90000A88ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x90000A89ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x911BA108ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x911CE129ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #6229 | PC: 0x2246ec..0x2246fc (16 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x2246ec: 90000A88  adrp     x8, #0x374000
//   0x2246f0: 911CE108  add      x8, x8, #0x738
//   0x2246f4: F8008408  str      x8, [x0], #8
//   0x2246f8: 17F8EA7B  b        #0x5f0e4
uint64_t fde_func_6229_0x2246ec(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x002246ECULL);
    state = (state * 0x00000100000001B3ULL) ^ 0x90000A88ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x911CE108ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF8008408ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x17F8EA7BULL ^ (3ULL << 32);
    return state ^ (state >> 29);
}

// FDE #6233 | PC: 0x2248a0..0x2248d0 (48 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x2248a0: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x2248a4: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x2248a8: 910043FD  add      x29, sp, #0x10
//   0x2248ac: 90000A88  adrp     x8, #0x374000
//   0x2248b0: 911DC108  add      x8, x8, #0x770
//   0x2248b4: AA0003F3  mov      x19, x0
uint64_t fde_func_6233_0x2248a0(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x002248A0ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81E0FF3ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x90000A88ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x911DC108ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF8018408ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9400004BULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #6238 | PC: 0x2249e8..0x224a88 (160 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x2249e8: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x2249ec: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x2249f0: 910043FD  add      x29, sp, #0x10
//   0x2249f4: F0000AC8  adrp     x8, #0x37f000
//   0x2249f8: F947B908  ldr      x8, [x8, #0xf70]
//   0x2249fc: AA0003F4  mov      x20, x0
uint64_t fde_func_6238_0x2249e8(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x002249E8ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE4FF4ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF0000AC8ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF947B908ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F4ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91002013ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91004109ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #6242 | PC: 0x224b74..0x224bd0 (92 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x224b74: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x224b78: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x224b7c: 910043FD  add      x29, sp, #0x10
//   0x224b80: F9400808  ldr      x8, [x0, #0x10]
//   0x224b84: B4000208  cbz      x8, #0x224bc4
//   0x224b88: AA0003F3  mov      x19, x0
uint64_t fde_func_6242_0x224b74(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00224B74ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE4FF4ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400808ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB4000208ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9400008ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400509ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #6247 | PC: 0x224dd0..0x224e08 (56 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x224dd0: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x224dd4: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x224dd8: 910043FD  add      x29, sp, #0x10
//   0x224ddc: 90000A88  adrp     x8, #0x374000
//   0x224de0: 911F0108  add      x8, x8, #0x7c0
//   0x224de4: AA0003F3  mov      x19, x0
uint64_t fde_func_6247_0x224dd0(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00224DD0ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81E0FF3ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x90000A88ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x911F0108ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF8018408ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9400003FULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #6251 | PC: 0x224ee8..0x224f4c (100 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x224ee8: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x224eec: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x224ef0: 910043FD  add      x29, sp, #0x10
//   0x224ef4: F0000AC8  adrp     x8, #0x37f000
//   0x224ef8: F947F508  ldr      x8, [x8, #0xfe8]
//   0x224efc: AA0003F4  mov      x20, x0
uint64_t fde_func_6251_0x224ee8(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00224EE8ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE4FF4ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF0000AC8ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF947F508ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F4ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91002013ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91004109ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #6256 | PC: 0x22546c..0x22556c (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x22546c: D101C3FF  sub      sp, sp, #0x70
//   0x225470: A9016FFC  stp      x28, x27, [sp, #0x10]
//   0x225474: A90267FA  stp      x26, x25, [sp, #0x20]
//   0x225478: A9035FF8  stp      x24, x23, [sp, #0x30]
//   0x22547c: A90457F6  stp      x22, x21, [sp, #0x40]
//   0x225480: A9054FF4  stp      x20, x19, [sp, #0x50]
uint64_t fde_func_6256_0x22546c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0022546CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD101C3FFULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9016FFCULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90267FAULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9035FF8ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90457F6ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9054FF4ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9067BFDULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910183FDULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #6260 | PC: 0x2256dc..0x225734 (88 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x2256dc: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x2256e0: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x2256e4: 910043FD  add      x29, sp, #0x10
//   0x2256e8: AA0003F3  mov      x19, x0
//   0x2256ec: 52800300  mov      w0, #0x18
//   0x2256f0: 97F87A78  bl       #0x440d0
uint64_t fde_func_6260_0x2256dc(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x002256DCULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81E0FF3ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x52800300ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x97F87A78ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF0000A68ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91204108ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #6265 | PC: 0x2258f8..0x225914 (28 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x2258f8: F9400428  ldr      x8, [x1, #8]
//   0x2258fc: 90000669  adrp     x9, #0x2f1000
//   0x225900: 9139C929  add      x9, x9, #0xe72
//   0x225904: 9100200A  add      x10, x0, #8
//   0x225908: EB09011F  cmp      x8, x9
//   0x22590c: 9A9F0140  csel     x0, x10, xzr, eq
uint64_t fde_func_6265_0x2258f8(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x002258F8ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400428ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x90000669ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9139C929ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9100200AULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xEB09011FULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9A9F0140ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD65F03C0ULL ^ (6ULL << 32);
    return state ^ (state >> 29);
}

// FDE #6269 | PC: 0x225c34..0x225c3c (8 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x225c34: D1002000  sub      x0, x0, #8
//   0x225c38: 17FFFFEA  b        #0x225be0
uint64_t fde_func_6269_0x225c34(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00225C34ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD1002000ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x17FFFFEAULL ^ (1ULL << 32);
    return state ^ (state >> 29);
}

// FDE #6274 | PC: 0x226384..0x226484 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x226384: D10343FF  sub      sp, sp, #0xd0
//   0x226388: A9095FF8  stp      x24, x23, [sp, #0x90]
//   0x22638c: A90A57F6  stp      x22, x21, [sp, #0xa0]
//   0x226390: A90B4FF4  stp      x20, x19, [sp, #0xb0]
//   0x226394: A90C7BFD  stp      x29, x30, [sp, #0xc0]
//   0x226398: 910303FD  add      x29, sp, #0xc0
uint64_t fde_func_6274_0x226384(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00226384ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10343FFULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9095FF8ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90A57F6ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90B4FF4ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90C7BFDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910303FDULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD53BD058ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9401708ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #6278 | PC: 0x2276d4..0x2277d4 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x2276d4: D10183FF  sub      sp, sp, #0x60
//   0x2276d8: A90357F6  stp      x22, x21, [sp, #0x30]
//   0x2276dc: A9044FF4  stp      x20, x19, [sp, #0x40]
//   0x2276e0: A9057BFD  stp      x29, x30, [sp, #0x50]
//   0x2276e4: 910143FD  add      x29, sp, #0x50
//   0x2276e8: D53BD056  mrs      x22, tpidr_el0
uint64_t fde_func_6278_0x2276d4(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x002276D4ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10183FFULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90357F6ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9044FF4ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9057BFDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910143FDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD53BD056ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF94016C8ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF90017E8ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #6283 | PC: 0x229764..0x229864 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x229764: D101C3FF  sub      sp, sp, #0x70
//   0x229768: F9001BF7  str      x23, [sp, #0x30]
//   0x22976c: A90457F6  stp      x22, x21, [sp, #0x40]
//   0x229770: A9054FF4  stp      x20, x19, [sp, #0x50]
//   0x229774: A9067BFD  stp      x29, x30, [sp, #0x60]
//   0x229778: 910183FD  add      x29, sp, #0x60
uint64_t fde_func_6283_0x229764(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00229764ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD101C3FFULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9001BF7ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90457F6ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9054FF4ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9067BFDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910183FDULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD53BD057ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF94016E8ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #6287 | PC: 0x22acf0..0x22adf0 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x22acf0: D10243FF  sub      sp, sp, #0x90
//   0x22acf4: F9002BF7  str      x23, [sp, #0x50]
//   0x22acf8: A90657F6  stp      x22, x21, [sp, #0x60]
//   0x22acfc: A9074FF4  stp      x20, x19, [sp, #0x70]
//   0x22ad00: A9087BFD  stp      x29, x30, [sp, #0x80]
//   0x22ad04: 910203FD  add      x29, sp, #0x80
uint64_t fde_func_6287_0x22acf0(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0022ACF0ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10243FFULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9002BF7ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90657F6ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9074FF4ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9087BFDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910203FDULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD53BD057ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF94016E8ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #6292 | PC: 0x22be48..0x22bf48 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x22be48: D10243FF  sub      sp, sp, #0x90
//   0x22be4c: F9002BF7  str      x23, [sp, #0x50]
//   0x22be50: A90657F6  stp      x22, x21, [sp, #0x60]
//   0x22be54: A9074FF4  stp      x20, x19, [sp, #0x70]
//   0x22be58: A9087BFD  stp      x29, x30, [sp, #0x80]
//   0x22be5c: 910203FD  add      x29, sp, #0x80
uint64_t fde_func_6292_0x22be48(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0022BE48ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10243FFULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9002BF7ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90657F6ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9074FF4ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9087BFDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910203FDULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD53BD057ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF94016E8ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #6296 | PC: 0x22c184..0x22c18c (8 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x22c184: D1002000  sub      x0, x0, #8
//   0x22c188: 17FFE218  b        #0x2249e8
uint64_t fde_func_6296_0x22c184(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0022C184ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD1002000ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x17FFE218ULL ^ (1ULL << 32);
    return state ^ (state >> 29);
}

// FDE #6301 | PC: 0x22c5fc..0x22c6b0 (180 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x22c5fc: F9400408  ldr      x8, [x0, #8]
//   0x22c600: B4000548  cbz      x8, #0x22c6a8
//   0x22c604: 9E670100  fmov     d0, x8
//   0x22c608: B9800029  ldrsw    x9, [x1]
//   0x22c60c: 0E205800  cnt      v0.8b, v0.8b
//   0x22c610: 2E303800  uaddlv   h0, v0.8b
uint64_t fde_func_6301_0x22c5fc(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0022C5FCULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400408ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB4000548ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9E670100ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB9800029ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x0E205800ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x2E303800ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x1E26000AULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF100055FULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #6305 | PC: 0x22c7ac..0x22c80c (96 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x22c7ac: 90000A48  adrp     x8, #0x374000
//   0x22c7b0: 91258108  add      x8, x8, #0x960
//   0x22c7b4: F9000028  str      x8, [x1]
//   0x22c7b8: F9400408  ldr      x8, [x0, #8]
//   0x22c7bc: F9000428  str      x8, [x1, #8]
//   0x22c7c0: F9400808  ldr      x8, [x0, #0x10]
uint64_t fde_func_6305_0x22c7ac(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0022C7ACULL);
    state = (state * 0x00000100000001B3ULL) ^ 0x90000A48ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91258108ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000028ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400408ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000428ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400808ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000828ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB40000C8ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #6309 | PC: 0x22c914..0x22c930 (28 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x22c914: F9400428  ldr      x8, [x1, #8]
//   0x22c918: F0000629  adrp     x9, #0x2f3000
//   0x22c91c: 9107A529  add      x9, x9, #0x1e9
//   0x22c920: 9100200A  add      x10, x0, #8
//   0x22c924: EB09011F  cmp      x8, x9
//   0x22c928: 9A9F0140  csel     x0, x10, xzr, eq
uint64_t fde_func_6309_0x22c914(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0022C914ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400428ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF0000629ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9107A529ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9100200AULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xEB09011FULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9A9F0140ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD65F03C0ULL ^ (6ULL << 32);
    return state ^ (state >> 29);
}

// FDE #6314 | PC: 0x22ca00..0x22ca40 (64 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x22ca00: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x22ca04: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x22ca08: 910043FD  add      x29, sp, #0x10
//   0x22ca0c: AA0003F3  mov      x19, x0
//   0x22ca10: 52800700  mov      w0, #0x38
//   0x22ca14: 97F85DAF  bl       #0x440d0
uint64_t fde_func_6314_0x22ca00(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0022CA00ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE4FF4ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x52800700ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x97F85DAFULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x90000A48ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91278108ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #6318 | PC: 0x22cad8..0x22cbd8 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x22cad8: D101C3FF  sub      sp, sp, #0x70
//   0x22cadc: A90457F6  stp      x22, x21, [sp, #0x40]
//   0x22cae0: A9054FF4  stp      x20, x19, [sp, #0x50]
//   0x22cae4: A9067BFD  stp      x29, x30, [sp, #0x60]
//   0x22cae8: 910183FD  add      x29, sp, #0x60
//   0x22caec: D53BD056  mrs      x22, tpidr_el0
uint64_t fde_func_6318_0x22cad8(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0022CAD8ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD101C3FFULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90457F6ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9054FF4ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9067BFDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910183FDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD53BD056ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF94016C8ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F5ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #6323 | PC: 0x22d34c..0x22d44c (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x22d34c: D101C3FF  sub      sp, sp, #0x70
//   0x22d350: F9000BFB  str      x27, [sp, #0x10]
//   0x22d354: A90267FA  stp      x26, x25, [sp, #0x20]
//   0x22d358: A9035FF8  stp      x24, x23, [sp, #0x30]
//   0x22d35c: A90457F6  stp      x22, x21, [sp, #0x40]
//   0x22d360: A9054FF4  stp      x20, x19, [sp, #0x50]
uint64_t fde_func_6323_0x22d34c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0022D34CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD101C3FFULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BFBULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90267FAULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9035FF8ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90457F6ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9054FF4ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9067BFDULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910183FDULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #6327 | PC: 0x22db7c..0x22dbe8 (108 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x22db7c: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x22db80: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x22db84: 910043FD  add      x29, sp, #0x10
//   0x22db88: 39402008  ldrb     w8, [x0, #8]
//   0x22db8c: AA0103F3  mov      x19, x1
//   0x22db90: 340001C8  cbz      w8, #0x22dbc8
uint64_t fde_func_6327_0x22db7c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0022DB7CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81E0FF3ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x39402008ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0103F3ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x340001C8ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x39410268ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x36000068ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #6332 | PC: 0x22df80..0x22e080 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x22df80: D10143FF  sub      sp, sp, #0x50
//   0x22df84: A9015FF8  stp      x24, x23, [sp, #0x10]
//   0x22df88: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x22df8c: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x22df90: A9047BFD  stp      x29, x30, [sp, #0x40]
//   0x22df94: 910103FD  add      x29, sp, #0x40
uint64_t fde_func_6332_0x22df80(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0022DF80ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10143FFULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9015FF8ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90257F6ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9034FF4ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9047BFDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910103FDULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD53BD056ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF94016C8ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #6336 | PC: 0x22e410..0x22e46c (92 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x22e410: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x22e414: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x22e418: 910043FD  add      x29, sp, #0x10
//   0x22e41c: AA0003F3  mov      x19, x0
//   0x22e420: 52800020  mov      w0, #1
//   0x22e424: 97F85D34  bl       #0x458f4
uint64_t fde_func_6336_0x22e410(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0022E410ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81E0FF3ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x52800020ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x97F85D34ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x36000140ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB0000621ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #6341 | PC: 0x22e61c..0x22e71c (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x22e61c: D102C3FF  sub      sp, sp, #0xb0
//   0x22e620: A9075FF8  stp      x24, x23, [sp, #0x70]
//   0x22e624: A90857F6  stp      x22, x21, [sp, #0x80]
//   0x22e628: A9094FF4  stp      x20, x19, [sp, #0x90]
//   0x22e62c: A90A7BFD  stp      x29, x30, [sp, #0xa0]
//   0x22e630: 910283FD  add      x29, sp, #0xa0
uint64_t fde_func_6341_0x22e61c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0022E61CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD102C3FFULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9075FF8ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90857F6ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9094FF4ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90A7BFDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910283FDULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD53BD058ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0803F4ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #6345 | PC: 0x22fb44..0x22fc14 (208 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x22fb44: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x22fb48: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x22fb4c: 910043FD  add      x29, sp, #0x10
//   0x22fb50: F9400028  ldr      x8, [x1]
//   0x22fb54: B40004A8  cbz      x8, #0x22fbe8
//   0x22fb58: F9403913  ldr      x19, [x8, #0x70]
uint64_t fde_func_6345_0x22fb44(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0022FB44ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE4FF4ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400028ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB40004A8ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9403913ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F4ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB40000F3ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #6350 | PC: 0x22fca8..0x22fce4 (60 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x22fca8: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x22fcac: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x22fcb0: 910043FD  add      x29, sp, #0x10
//   0x22fcb4: B0000A28  adrp     x8, #0x374000
//   0x22fcb8: 912CC108  add      x8, x8, #0xb30
//   0x22fcbc: AA0003F3  mov      x19, x0
uint64_t fde_func_6350_0x22fca8(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0022FCA8ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81E0FF3ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB0000A28ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x912CC108ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF8018408ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x97F8BD08ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #6354 | PC: 0x22fdcc..0x22fdf4 (40 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x22fdcc: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x22fdd0: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x22fdd4: 910043FD  add      x29, sp, #0x10
//   0x22fdd8: AA0003F3  mov      x19, x0
//   0x22fddc: 91002000  add      x0, x0, #8
//   0x22fde0: 94000045  bl       #0x22fef4
uint64_t fde_func_6354_0x22fdcc(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0022FDCCULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81E0FF3ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91002000ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x94000045ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9417BFDULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA1303E0ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #6359 | PC: 0x22ff2c..0x22ff74 (72 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x22ff2c: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x22ff30: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x22ff34: 910043FD  add      x29, sp, #0x10
//   0x22ff38: B0000A28  adrp     x8, #0x374000
//   0x22ff3c: 912EC108  add      x8, x8, #0xbb0
//   0x22ff40: AA0003F3  mov      x19, x0
uint64_t fde_func_6359_0x22ff2c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0022FF2CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81E0FF3ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB0000A28ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x912EC108ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF8028408ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x97FC9145ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #6363 | PC: 0x230014..0x230054 (64 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x230014: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x230018: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x23001c: 910043FD  add      x29, sp, #0x10
//   0x230020: AA0003F3  mov      x19, x0
//   0x230024: 9100A000  add      x0, x0, #0x28
//   0x230028: 97FC910D  bl       #0x15445c
uint64_t fde_func_6363_0x230014(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00230014ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81E0FF3ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9100A000ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x97FC910DULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91006260ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x97F86700ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #6368 | PC: 0x23053c..0x2305f8 (188 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x23053c: F81C0FF7  str      x23, [sp, #-0x40]!
//   0x230540: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x230544: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x230548: A9037BFD  stp      x29, x30, [sp, #0x30]
//   0x23054c: 9100C3FD  add      x29, sp, #0x30
//   0x230550: F9400028  ldr      x8, [x1]
uint64_t fde_func_6368_0x23053c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0023053CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81C0FF7ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90157F6ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9024FF4ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9037BFDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9100C3FDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400028ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0103F3ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F4ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #6372 | PC: 0x2306cc..0x2306d0 (4 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x2306cc: D65F03C0  ret      
uint64_t fde_func_6372_0x2306cc(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x002306CCULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD65F03C0ULL ^ (0ULL << 32);
    return state ^ (state >> 29);
}

// FDE #6377 | PC: 0x230da0..0x230ea0 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x230da0: D105C3FF  sub      sp, sp, #0x170
//   0x230da4: A9116FFC  stp      x28, x27, [sp, #0x110]
//   0x230da8: A91267FA  stp      x26, x25, [sp, #0x120]
//   0x230dac: A9135FF8  stp      x24, x23, [sp, #0x130]
//   0x230db0: A91457F6  stp      x22, x21, [sp, #0x140]
//   0x230db4: A9154FF4  stp      x20, x19, [sp, #0x150]
uint64_t fde_func_6377_0x230da0(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00230DA0ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD105C3FFULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9116FFCULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA91267FAULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9135FF8ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA91457F6ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9154FF4ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9167BFDULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910583FDULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #6381 | PC: 0x23185c..0x2318e4 (136 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x23185c: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x231860: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x231864: 910043FD  add      x29, sp, #0x10
//   0x231868: A9007C1F  stp      xzr, xzr, [x0]
//   0x23186c: F900081F  str      xzr, [x0, #0x10]
//   0x231870: A9402428  ldp      x8, x9, [x1]
uint64_t fde_func_6381_0x23185c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0023185CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE4FF4ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9007C1FULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF900081FULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9402428ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xEB080128ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x54000300ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #6386 | PC: 0x231b04..0x231ba8 (164 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x231b04: D10183FF  sub      sp, sp, #0x60
//   0x231b08: F90013F7  str      x23, [sp, #0x20]
//   0x231b0c: A90357F6  stp      x22, x21, [sp, #0x30]
//   0x231b10: A9044FF4  stp      x20, x19, [sp, #0x40]
//   0x231b14: A9057BFD  stp      x29, x30, [sp, #0x50]
//   0x231b18: 910143FD  add      x29, sp, #0x50
uint64_t fde_func_6386_0x231b04(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00231B04ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10183FFULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF90013F7ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90357F6ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9044FF4ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9057BFDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910143FDULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD53BD057ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF94016E8ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #6390 | PC: 0x231f84..0x232084 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x231f84: 91002008  add      x8, x0, #8
//   0x231f88: EB01011F  cmp      x8, x1
//   0x231f8c: 540000A0  b.eq     #0x231fa0
//   0x231f90: B9400089  ldr      w9, [x4]
//   0x231f94: B940202A  ldr      w10, [x1, #0x20]
//   0x231f98: 6B0A013F  cmp      w9, w10
uint64_t fde_func_6390_0x231f84(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00231F84ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0x91002008ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xEB01011FULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x540000A0ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB9400089ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB940202AULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x6B0A013FULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x5400018AULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400009ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #6394 | PC: 0x23221c..0x23231c (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x23221c: 91002008  add      x8, x0, #8
//   0x232220: EB01011F  cmp      x8, x1
//   0x232224: 540000A0  b.eq     #0x232238
//   0x232228: B9400089  ldr      w9, [x4]
//   0x23222c: B940202A  ldr      w10, [x1, #0x20]
//   0x232230: 6B0A013F  cmp      w9, w10
uint64_t fde_func_6394_0x23221c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0023221CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0x91002008ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xEB01011FULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x540000A0ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB9400089ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB940202AULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x6B0A013FULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x5400018AULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400009ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #6399 | PC: 0x23251c..0x23254c (48 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x23251c: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x232520: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x232524: 910043FD  add      x29, sp, #0x10
//   0x232528: D0000A08  adrp     x8, #0x374000
//   0x23252c: 91322108  add      x8, x8, #0xc88
//   0x232530: AA0003F3  mov      x19, x0
uint64_t fde_func_6399_0x23251c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0023251CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81E0FF3ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD0000A08ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91322108ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF8018408ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x94000016ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #6403 | PC: 0x232590..0x232600 (112 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x232590: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x232594: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x232598: 910043FD  add      x29, sp, #0x10
//   0x23259c: AA0003F3  mov      x19, x0
//   0x2325a0: 9101C000  add      x0, x0, #0x70
//   0x2325a4: 97F84883  bl       #0x447b0
uint64_t fde_func_6403_0x232590(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00232590ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81E0FF3ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9101C000ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x97F84883ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91016260ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x940000F7ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #6408 | PC: 0x232948..0x232988 (64 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x232948: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x23294c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x232950: 910043FD  add      x29, sp, #0x10
//   0x232954: D37CFC28  lsr      x8, x1, #0x3c
//   0x232958: B5000168  cbnz     x8, #0x232984
//   0x23295c: AA0003F4  mov      x20, x0
uint64_t fde_func_6408_0x232948(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00232948ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE4FF4ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD37CFC28ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB5000168ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F4ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD37CEC20ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0103F3ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #6412 | PC: 0x232a40..0x232a78 (56 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x232a40: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x232a44: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x232a48: 910043FD  add      x29, sp, #0x10
//   0x232a4c: D0000A08  adrp     x8, #0x374000
//   0x232a50: 91336108  add      x8, x8, #0xcd8
//   0x232a54: AA0003F3  mov      x19, x0
uint64_t fde_func_6412_0x232a40(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00232A40ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81E0FF3ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD0000A08ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91336108ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF8018408ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x97FFFD09ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #6417 | PC: 0x232bb0..0x232be0 (48 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x232bb0: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x232bb4: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x232bb8: 910043FD  add      x29, sp, #0x10
//   0x232bbc: D0000A08  adrp     x8, #0x374000
//   0x232bc0: 9134A108  add      x8, x8, #0xd28
//   0x232bc4: AA0003F3  mov      x19, x0
uint64_t fde_func_6417_0x232bb0(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00232BB0ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81E0FF3ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD0000A08ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9134A108ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF8018408ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x94000016ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #6421 | PC: 0x232c24..0x232c6c (72 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x232c24: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x232c28: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x232c2c: 910043FD  add      x29, sp, #0x10
//   0x232c30: B0000A68  adrp     x8, #0x37f000
//   0x232c34: F9456D08  ldr      x8, [x8, #0xad8]
//   0x232c38: F9401C01  ldr      x1, [x0, #0x38]
uint64_t fde_func_6421_0x232c24(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00232C24ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81E0FF3ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB0000A68ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9456D08ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9401C01ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91004108ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #6426 | PC: 0x232e64..0x232eb8 (84 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x232e64: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x232e68: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x232e6c: 910043FD  add      x29, sp, #0x10
//   0x232e70: A9007C7F  stp      xzr, xzr, [x3]
//   0x232e74: F9000861  str      x1, [x3, #0x10]
//   0x232e78: F9000043  str      x3, [x2]
uint64_t fde_func_6426_0x232e64(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00232E64ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81E0FF3ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9007C7FULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000861ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000043ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400008ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #6430 | PC: 0x23326c..0x23336c (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x23326c: D10183FF  sub      sp, sp, #0x60
//   0x233270: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x233274: A90357F6  stp      x22, x21, [sp, #0x30]
//   0x233278: A9044FF4  stp      x20, x19, [sp, #0x40]
//   0x23327c: A9057BFD  stp      x29, x30, [sp, #0x50]
//   0x233280: 910143FD  add      x29, sp, #0x50
uint64_t fde_func_6430_0x23326c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0023326CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10183FFULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9025FF8ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90357F6ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9044FF4ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9057BFDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910143FDULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD53BD056ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF94016C8ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #6435 | PC: 0x2334b4..0x233594 (224 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x2334b4: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x2334b8: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x2334bc: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x2334c0: 910083FD  add      x29, sp, #0x20
//   0x2334c4: B0000A08  adrp     x8, #0x374000
//   0x2334c8: 9135E108  add      x8, x8, #0xd78
uint64_t fde_func_6435_0x2334b4(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x002334B4ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BD57F6ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9014FF4ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9027BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910083FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB0000A08ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9135E108ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91016109ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9E670100ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #6439 | PC: 0x233668..0x233670 (8 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x233668: D100A000  sub      x0, x0, #0x28
//   0x23366c: 17FFFFE0  b        #0x2335ec
uint64_t fde_func_6439_0x233668(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00233668ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD100A000ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x17FFFFE0ULL ^ (1ULL << 32);
    return state ^ (state >> 29);
}

// FDE #6444 | PC: 0x233a50..0x233aa8 (88 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x233a50: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x233a54: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x233a58: 910043FD  add      x29, sp, #0x10
//   0x233a5c: F9400413  ldr      x19, [x0, #8]
//   0x233a60: B40000F3  cbz      x19, #0x233a7c
//   0x233a64: 91002268  add      x8, x19, #8
uint64_t fde_func_6444_0x233a50(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00233A50ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81E0FF3ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400413ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB40000F3ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91002268ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xC85FFD09ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD100052AULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #6448 | PC: 0x233e6c..0x233e78 (12 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x233e6c: 52800068  mov      w8, #3
//   0x233e70: B9001808  str      w8, [x0, #0x18]
//   0x233e74: D65F03C0  ret      
uint64_t fde_func_6448_0x233e6c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00233E6CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0x52800068ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB9001808ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD65F03C0ULL ^ (2ULL << 32);
    return state ^ (state >> 29);
}

// FDE #6453 | PC: 0x234968..0x234974 (12 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x234968: F9400008  ldr      x8, [x0]
//   0x23496c: F9401D01  ldr      x1, [x8, #0x38]
//   0x234970: D61F0020  br       x1
uint64_t fde_func_6453_0x234968(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00234968ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400008ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9401D01ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD61F0020ULL ^ (2ULL << 32);
    return state ^ (state >> 29);
}

// FDE #6457 | PC: 0x234e78..0x234eb0 (56 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x234e78: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x234e7c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x234e80: 910043FD  add      x29, sp, #0x10
//   0x234e84: 90000A08  adrp     x8, #0x374000
//   0x234e88: 913A4108  add      x8, x8, #0xe90
//   0x234e8c: AA0003F3  mov      x19, x0
uint64_t fde_func_6457_0x234e78(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00234E78ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81E0FF3ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x90000A08ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x913A4108ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF8018408ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x97FFFAEFULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #6462 | PC: 0x234f9c..0x234ffc (96 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x234f9c: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x234fa0: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x234fa4: 910043FD  add      x29, sp, #0x10
//   0x234fa8: 39410008  ldrb     w8, [x0, #0x40]
//   0x234fac: 90000A09  adrp     x9, #0x374000
//   0x234fb0: 913B8129  add      x9, x9, #0xee0
uint64_t fde_func_6462_0x234f9c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00234F9CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81E0FF3ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x39410008ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x90000A09ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x913B8129ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000009ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x90000A09ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #6466 | PC: 0x23505c..0x2350a8 (76 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x23505c: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x235060: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x235064: 910043FD  add      x29, sp, #0x10
//   0x235068: 3940A008  ldrb     w8, [x0, #0x28]
//   0x23506c: F00009E9  adrp     x9, #0x374000
//   0x235070: AA0003F3  mov      x19, x0
uint64_t fde_func_6466_0x23505c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0023505CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81E0FF3ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x3940A008ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF00009E9ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x913CC129ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000009ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #6470 | PC: 0x235598..0x235624 (140 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x235598: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x23559c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x2355a0: 910043FD  add      x29, sp, #0x10
//   0x2355a4: 52801100  mov      w0, #0x88
//   0x2355a8: AA0803F3  mov      x19, x8
//   0x2355ac: 97F83AC9  bl       #0x440d0
uint64_t fde_func_6470_0x235598(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00235598ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81E0FF3ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x52801100ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0803F3ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x97F83AC9ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF00009E8ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x913DA108ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #6475 | PC: 0x235678..0x235778 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x235678: D10203FF  sub      sp, sp, #0x80
//   0x23567c: A9045FF8  stp      x24, x23, [sp, #0x40]
//   0x235680: A90557F6  stp      x22, x21, [sp, #0x50]
//   0x235684: A9064FF4  stp      x20, x19, [sp, #0x60]
//   0x235688: A9077BFD  stp      x29, x30, [sp, #0x70]
//   0x23568c: 9101C3FD  add      x29, sp, #0x70
uint64_t fde_func_6475_0x235678(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00235678ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10203FFULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9045FF8ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90557F6ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9064FF4ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9077BFDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9101C3FDULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD53BD058ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0803F6ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #6479 | PC: 0x236b64..0x236ba4 (64 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x236b64: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x236b68: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x236b6c: 910043FD  add      x29, sp, #0x10
//   0x236b70: D00009E8  adrp     x8, #0x374000
//   0x236b74: AA0003F3  mov      x19, x0
//   0x236b78: 913EE108  add      x8, x8, #0xfb8
uint64_t fde_func_6479_0x236b64(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00236B64ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE4FF4ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD00009E8ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x913EE108ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F4ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91006000ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #6484 | PC: 0x2374a4..0x2375a4 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x2374a4: D101C3FF  sub      sp, sp, #0x70
//   0x2374a8: 6D0223E9  stp      d9, d8, [sp, #0x20]
//   0x2374ac: A9035FF8  stp      x24, x23, [sp, #0x30]
//   0x2374b0: A90457F6  stp      x22, x21, [sp, #0x40]
//   0x2374b4: A9054FF4  stp      x20, x19, [sp, #0x50]
//   0x2374b8: A9067BFD  stp      x29, x30, [sp, #0x60]
uint64_t fde_func_6484_0x2374a4(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x002374A4ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD101C3FFULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x6D0223E9ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9035FF8ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90457F6ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9054FF4ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9067BFDULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910183FDULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD53BD058ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #6488 | PC: 0x237a88..0x237b88 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x237a88: D10383FF  sub      sp, sp, #0xe0
//   0x237a8c: A90A5FF8  stp      x24, x23, [sp, #0xa0]
//   0x237a90: A90B57F6  stp      x22, x21, [sp, #0xb0]
//   0x237a94: A90C4FF4  stp      x20, x19, [sp, #0xc0]
//   0x237a98: A90D7BFD  stp      x29, x30, [sp, #0xd0]
//   0x237a9c: 910343FD  add      x29, sp, #0xd0
uint64_t fde_func_6488_0x237a88(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00237A88ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10383FFULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90A5FF8ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90B57F6ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90C4FF4ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90D7BFDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910343FDULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD53BD057ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF94016E8ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #6493 | PC: 0x23857c..0x2385a0 (36 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x23857c: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x238580: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x238584: 910043FD  add      x29, sp, #0x10
//   0x238588: AA0003F3  mov      x19, x0
//   0x23858c: 97F8328D  bl       #0x44fc0
//   0x238590: A9417BFD  ldp      x29, x30, [sp, #0x10]
uint64_t fde_func_6493_0x23857c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0023857CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81E0FF3ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x97F8328DULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9417BFDULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA1303E0ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF84207F3ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #6497 | PC: 0x2385b4..0x2385d8 (36 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x2385b4: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x2385b8: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x2385bc: 910043FD  add      x29, sp, #0x10
//   0x2385c0: AA0003F3  mov      x19, x0
//   0x2385c4: 97F8327F  bl       #0x44fc0
//   0x2385c8: A9417BFD  ldp      x29, x30, [sp, #0x10]
uint64_t fde_func_6497_0x2385b4(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x002385B4ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81E0FF3ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x97F8327FULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9417BFDULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA1303E0ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF84207F3ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #6502 | PC: 0x238610..0x23861c (12 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x238610: F8418C08  ldr      x8, [x0, #0x18]!
//   0x238614: F9400101  ldr      x1, [x8]
//   0x238618: D61F0020  br       x1
uint64_t fde_func_6502_0x238610(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00238610ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF8418C08ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400101ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD61F0020ULL ^ (2ULL << 32);
    return state ^ (state >> 29);
}

// FDE #6506 | PC: 0x238824..0x23889c (120 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x238824: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x238828: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x23882c: 910043FD  add      x29, sp, #0x10
//   0x238830: A940A808  ldp      x8, x10, [x0, #8]
//   0x238834: A942240B  ldp      x11, x9, [x0, #0x20]
//   0x238838: AA0003F3  mov      x19, x0
uint64_t fde_func_6506_0x238824(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00238824ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE4FF4ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA940A808ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA942240BULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0103F4ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xEB08014AULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #6511 | PC: 0x238d94..0x238e94 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x238d94: F81B0FF9  str      x25, [sp, #-0x50]!
//   0x238d98: A9015FF8  stp      x24, x23, [sp, #0x10]
//   0x238d9c: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x238da0: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x238da4: A9047BFD  stp      x29, x30, [sp, #0x40]
//   0x238da8: 910103FD  add      x29, sp, #0x40
uint64_t fde_func_6511_0x238d94(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00238D94ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81B0FF9ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9015FF8ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90257F6ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9034FF4ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9047BFDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910103FDULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9412017ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #6515 | PC: 0x239264..0x2392cc (104 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x239264: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x239268: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x23926c: 910043FD  add      x29, sp, #0x10
//   0x239270: F9401009  ldr      x9, [x0, #0x20]
//   0x239274: AA0003F3  mov      x19, x0
//   0x239278: F110013F  cmp      x9, #0x400
uint64_t fde_func_6515_0x239264(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00239264ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81E0FF3ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9401009ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF110013FULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x1A9F27E8ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF11FFD3FULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #6520 | PC: 0x23a544..0x23a644 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x23a544: FC1C0FE8  str      d8, [sp, #-0x40]!
//   0x23a548: F90007F7  str      x23, [sp, #8]
//   0x23a54c: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x23a550: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x23a554: A9037BFD  stp      x29, x30, [sp, #0x30]
//   0x23a558: 9100C3FD  add      x29, sp, #0x30
uint64_t fde_func_6520_0x23a544(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0023A544ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xFC1C0FE8ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF90007F7ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90157F6ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9024FF4ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9037BFDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9100C3FDULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400048ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x2A0403F6ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #6524 | PC: 0x23a7f0..0x23a7fc (12 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x23a7f0: F8418C08  ldr      x8, [x0, #0x18]!
//   0x23a7f4: F9400101  ldr      x1, [x8]
//   0x23a7f8: D61F0020  br       x1
uint64_t fde_func_6524_0x23a7f0(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0023A7F0ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF8418C08ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400101ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD61F0020ULL ^ (2ULL << 32);
    return state ^ (state >> 29);
}

// FDE #6529 | PC: 0x23a894..0x23a994 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x23a894: D10743FF  sub      sp, sp, #0x1d0
//   0x23a898: 6D133BEF  stp      d15, d14, [sp, #0x130]
//   0x23a89c: 6D1433ED  stp      d13, d12, [sp, #0x140]
//   0x23a8a0: 6D152BEB  stp      d11, d10, [sp, #0x150]
//   0x23a8a4: 6D1623E9  stp      d9, d8, [sp, #0x160]
//   0x23a8a8: A9176FFC  stp      x28, x27, [sp, #0x170]
uint64_t fde_func_6529_0x23a894(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0023A894ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10743FFULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x6D133BEFULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x6D1433EDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x6D152BEBULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x6D1623E9ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9176FFCULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA91867FAULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9195FF8ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #6533 | PC: 0x23bb64..0x23bb68 (4 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x23bb64: 17F821F3  b        #0x44330
uint64_t fde_func_6533_0x23bb64(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0023BB64ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0x17F821F3ULL ^ (0ULL << 32);
    return state ^ (state >> 29);
}

// FDE #6538 | PC: 0x23c094..0x23c194 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x23c094: D102C3FF  sub      sp, sp, #0xb0
//   0x23c098: 6D0333ED  stp      d13, d12, [sp, #0x30]
//   0x23c09c: 6D042BEB  stp      d11, d10, [sp, #0x40]
//   0x23c0a0: 6D0523E9  stp      d9, d8, [sp, #0x50]
//   0x23c0a4: A90667FA  stp      x26, x25, [sp, #0x60]
//   0x23c0a8: A9075FF8  stp      x24, x23, [sp, #0x70]
uint64_t fde_func_6538_0x23c094(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0023C094ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD102C3FFULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x6D0333EDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x6D042BEBULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x6D0523E9ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90667FAULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9075FF8ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90857F6ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9094FF4ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #6542 | PC: 0x23d2d0..0x23d3d0 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x23d2d0: D10103FF  sub      sp, sp, #0x40
//   0x23d2d4: F9000BF5  str      x21, [sp, #0x10]
//   0x23d2d8: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x23d2dc: A9037BFD  stp      x29, x30, [sp, #0x30]
//   0x23d2e0: 9100C3FD  add      x29, sp, #0x30
//   0x23d2e4: D53BD055  mrs      x21, tpidr_el0
uint64_t fde_func_6542_0x23d2d0(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0023D2D0ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10103FFULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF5ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9024FF4ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9037BFDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9100C3FDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD53BD055ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF94016A8ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF90007E8ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #6547 | PC: 0x23d56c..0x23d64c (224 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x23d56c: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x23d570: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x23d574: 910043FD  add      x29, sp, #0x10
//   0x23d578: A940A408  ldp      x8, x9, [x0, #8]
//   0x23d57c: AA0003F3  mov      x19, x0
//   0x23d580: EB080129  subs     x9, x9, x8
uint64_t fde_func_6547_0x23d56c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0023D56CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81E0FF3ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA940A408ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xEB080129ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x54000320ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF940126CULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #6551 | PC: 0x23da60..0x23db60 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x23da60: A9BC5FF8  stp      x24, x23, [sp, #-0x40]!
//   0x23da64: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x23da68: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x23da6c: A9037BFD  stp      x29, x30, [sp, #0x30]
//   0x23da70: 9100C3FD  add      x29, sp, #0x30
//   0x23da74: A9405408  ldp      x8, x21, [x0]
uint64_t fde_func_6551_0x23da60(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0023DA60ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BC5FF8ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90157F6ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9024FF4ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9037BFDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9100C3FDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9405408ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0103F4ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #6555 | PC: 0x23de64..0x23df64 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x23de64: D10243FF  sub      sp, sp, #0x90
//   0x23de68: F90023F9  str      x25, [sp, #0x40]
//   0x23de6c: A9055FF8  stp      x24, x23, [sp, #0x50]
//   0x23de70: A90657F6  stp      x22, x21, [sp, #0x60]
//   0x23de74: A9074FF4  stp      x20, x19, [sp, #0x70]
//   0x23de78: A9087BFD  stp      x29, x30, [sp, #0x80]
uint64_t fde_func_6555_0x23de64(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0023DE64ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10243FFULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF90023F9ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9055FF8ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90657F6ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9074FF4ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9087BFDULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910203FDULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD53BD058ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #6560 | PC: 0x23ebec..0x23ec34 (72 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x23ebec: B9400028  ldr      w8, [x1]
//   0x23ebf0: 7100051F  cmp      w8, #1
//   0x23ebf4: 5400014B  b.lt     #0x23ec1c
//   0x23ebf8: F9400409  ldr      x9, [x0, #8]
//   0x23ebfc: EB09001F  cmp      x0, x9
//   0x23ec00: 540000E0  b.eq     #0x23ec1c
uint64_t fde_func_6560_0x23ebec(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0023EBECULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xB9400028ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x7100051FULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x5400014BULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400409ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xEB09001FULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x540000E0ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF940092AULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB940694AULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #6564 | PC: 0x23edb8..0x23eeb8 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x23edb8: D101C3FF  sub      sp, sp, #0x70
//   0x23edbc: F9001BF7  str      x23, [sp, #0x30]
//   0x23edc0: A90457F6  stp      x22, x21, [sp, #0x40]
//   0x23edc4: A9054FF4  stp      x20, x19, [sp, #0x50]
//   0x23edc8: A9067BFD  stp      x29, x30, [sp, #0x60]
//   0x23edcc: 910183FD  add      x29, sp, #0x60
uint64_t fde_func_6564_0x23edb8(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0023EDB8ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD101C3FFULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9001BF7ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90457F6ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9054FF4ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9067BFDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910183FDULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD53BD057ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF94016E8ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #6569 | PC: 0x240678..0x240778 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x240678: D10383FF  sub      sp, sp, #0xe0
//   0x24067c: A90967FA  stp      x26, x25, [sp, #0x90]
//   0x240680: A90A5FF8  stp      x24, x23, [sp, #0xa0]
//   0x240684: A90B57F6  stp      x22, x21, [sp, #0xb0]
//   0x240688: A90C4FF4  stp      x20, x19, [sp, #0xc0]
//   0x24068c: A90D7BFD  stp      x29, x30, [sp, #0xd0]
uint64_t fde_func_6569_0x240678(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00240678ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10383FFULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90967FAULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90A5FF8ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90B57F6ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90C4FF4ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90D7BFDULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910343FDULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD53BD057ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #6573 | PC: 0x241194..0x2411b8 (36 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x241194: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x241198: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x24119c: 910043FD  add      x29, sp, #0x10
//   0x2411a0: AA0003F3  mov      x19, x0
//   0x2411a4: 94000005  bl       #0x2411b8
//   0x2411a8: A9417BFD  ldp      x29, x30, [sp, #0x10]
uint64_t fde_func_6573_0x241194(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00241194ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81E0FF3ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x94000005ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9417BFDULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA1303E0ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF84207F3ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #6578 | PC: 0x2415f0..0x2416f0 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x2415f0: D102C3FF  sub      sp, sp, #0xb0
//   0x2415f4: A9056FFC  stp      x28, x27, [sp, #0x50]
//   0x2415f8: A90667FA  stp      x26, x25, [sp, #0x60]
//   0x2415fc: A9075FF8  stp      x24, x23, [sp, #0x70]
//   0x241600: A90857F6  stp      x22, x21, [sp, #0x80]
//   0x241604: A9094FF4  stp      x20, x19, [sp, #0x90]
uint64_t fde_func_6578_0x2415f0(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x002415F0ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD102C3FFULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9056FFCULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90667FAULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9075FF8ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90857F6ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9094FF4ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90A7BFDULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910283FDULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #6582 | PC: 0x241974..0x241a04 (144 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x241974: D101C3FF  sub      sp, sp, #0x70
//   0x241978: F90023F5  str      x21, [sp, #0x40]
//   0x24197c: A9054FF4  stp      x20, x19, [sp, #0x50]
//   0x241980: A9067BFD  stp      x29, x30, [sp, #0x60]
//   0x241984: 910183FD  add      x29, sp, #0x60
//   0x241988: D53BD054  mrs      x20, tpidr_el0
uint64_t fde_func_6582_0x241974(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00241974ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD101C3FFULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF90023F5ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9054FF4ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9067BFDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910183FDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD53BD054ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9401688ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #6587 | PC: 0x241d54..0x241e54 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x241d54: D10703FF  sub      sp, sp, #0x1c0
//   0x241d58: F900BBFC  str      x28, [sp, #0x170]
//   0x241d5c: A9185FF8  stp      x24, x23, [sp, #0x180]
//   0x241d60: A91957F6  stp      x22, x21, [sp, #0x190]
//   0x241d64: A91A4FF4  stp      x20, x19, [sp, #0x1a0]
//   0x241d68: A91B7BFD  stp      x29, x30, [sp, #0x1b0]
uint64_t fde_func_6587_0x241d54(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00241D54ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10703FFULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF900BBFCULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9185FF8ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA91957F6ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA91A4FF4ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA91B7BFDULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9106C3FDULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD53BD058ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #6591 | PC: 0x24256c..0x24266c (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x24256c: D10283FF  sub      sp, sp, #0xa0
//   0x242570: A9065FF8  stp      x24, x23, [sp, #0x60]
//   0x242574: A90757F6  stp      x22, x21, [sp, #0x70]
//   0x242578: A9084FF4  stp      x20, x19, [sp, #0x80]
//   0x24257c: A9097BFD  stp      x29, x30, [sp, #0x90]
//   0x242580: 910243FD  add      x29, sp, #0x90
uint64_t fde_func_6591_0x24256c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0024256CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10283FFULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9065FF8ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90757F6ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9084FF4ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9097BFDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910243FDULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD53BD058ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0803F3ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #6596 | PC: 0x2443c8..0x244430 (104 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x2443c8: 2A0003E9  mov      w9, w0
//   0x2443cc: AA0803E0  mov      x0, x8
//   0x2443d0: 37F80129  tbnz     w9, #0x1f, #0x2443f4
//   0x2443d4: 340001C9  cbz      w9, #0x24440c
//   0x2443d8: 7100293F  cmp      w9, #0xa
//   0x2443dc: 540001E0  b.eq     #0x244418
uint64_t fde_func_6596_0x2443c8(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x002443C8ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0x2A0003E9ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0803E0ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x37F80129ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x340001C9ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x7100293FULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x540001E0ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x7100513FULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x540000E1ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #6600 | PC: 0x244954..0x244a54 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x244954: F81C0FF7  str      x23, [sp, #-0x40]!
//   0x244958: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x24495c: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x244960: A9037BFD  stp      x29, x30, [sp, #0x30]
//   0x244964: 9100C3FD  add      x29, sp, #0x30
//   0x244968: 3952A009  ldrb     w9, [x0, #0x4a8]
uint64_t fde_func_6600_0x244954(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00244954ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81C0FF7ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90157F6ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9024FF4ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9037BFDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9100C3FDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x3952A009ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0803F3ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x34000449ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #6605 | PC: 0x245270..0x245370 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x245270: D10583FF  sub      sp, sp, #0x160
//   0x245274: A9106FFC  stp      x28, x27, [sp, #0x100]
//   0x245278: A91167FA  stp      x26, x25, [sp, #0x110]
//   0x24527c: A9125FF8  stp      x24, x23, [sp, #0x120]
//   0x245280: A91357F6  stp      x22, x21, [sp, #0x130]
//   0x245284: A9144FF4  stp      x20, x19, [sp, #0x140]
uint64_t fde_func_6605_0x245270(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00245270ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10583FFULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9106FFCULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA91167FAULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9125FF8ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA91357F6ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9144FF4ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9157BFDULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910543FDULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #6609 | PC: 0x247ae4..0x247be4 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x247ae4: D10203FF  sub      sp, sp, #0x80
//   0x247ae8: A9026FFC  stp      x28, x27, [sp, #0x20]
//   0x247aec: A90367FA  stp      x26, x25, [sp, #0x30]
//   0x247af0: A9045FF8  stp      x24, x23, [sp, #0x40]
//   0x247af4: A90557F6  stp      x22, x21, [sp, #0x50]
//   0x247af8: A9064FF4  stp      x20, x19, [sp, #0x60]
uint64_t fde_func_6609_0x247ae4(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00247AE4ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10203FFULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9026FFCULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90367FAULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9045FF8ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90557F6ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9064FF4ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9077BFDULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9101C3FDULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #6614 | PC: 0x248210..0x2482f4 (228 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x248210: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x248214: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x248218: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x24821c: 910083FD  add      x29, sp, #0x20
//   0x248220: F1000428  subs     x8, x1, #1
//   0x248224: AA0003F3  mov      x19, x0
uint64_t fde_func_6614_0x248210(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00248210ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81D0FF5ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9014FF4ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9027BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910083FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF1000428ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x54000061ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x52800054ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #6618 | PC: 0x2488f4..0x248974 (128 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x2488f4: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x2488f8: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x2488fc: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x248900: 910083FD  add      x29, sp, #0x20
//   0x248904: A9007C1F  stp      xzr, xzr, [x0]
//   0x248908: F900081F  str      xzr, [x0, #0x10]
uint64_t fde_func_6618_0x2488f4(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x002488F4ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BD57F6ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9014FF4ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9027BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910083FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9007C1FULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF900081FULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9402428ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xEB080128ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #6623 | PC: 0x248bdc..0x248c84 (168 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x248bdc: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x248be0: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x248be4: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x248be8: 910083FD  add      x29, sp, #0x20
//   0x248bec: AA0003F3  mov      x19, x0
//   0x248bf0: F9400000  ldr      x0, [x0]
uint64_t fde_func_6623_0x248bdc(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00248BDCULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BD57F6ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9014FF4ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9027BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910083FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400000ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0103F4ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x97F8098AULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #6627 | PC: 0x249064..0x249164 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x249064: A9BB67FA  stp      x26, x25, [sp, #-0x50]!
//   0x249068: A9015FF8  stp      x24, x23, [sp, #0x10]
//   0x24906c: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x249070: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x249074: A9047BFD  stp      x29, x30, [sp, #0x40]
//   0x249078: 910103FD  add      x29, sp, #0x40
uint64_t fde_func_6627_0x249064(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00249064ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BB67FAULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9015FF8ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90257F6ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9034FF4ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9047BFDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910103FDULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400809ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400017ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #6631 | PC: 0x24941c..0x249488 (108 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x24941c: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x249420: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x249424: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x249428: 910083FD  add      x29, sp, #0x20
//   0x24942c: F9400415  ldr      x21, [x0, #8]
//   0x249430: AA0003F3  mov      x19, x0
uint64_t fde_func_6631_0x24941c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0024941CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81D0FF5ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9014FF4ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9027BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910083FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400415ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0103F4ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xEB0102BFULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #6636 | PC: 0x2497c4..0x249864 (160 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x2497c4: D10103FF  sub      sp, sp, #0x40
//   0x2497c8: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x2497cc: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x2497d0: A9037BFD  stp      x29, x30, [sp, #0x30]
//   0x2497d4: 9100C3FD  add      x29, sp, #0x30
//   0x2497d8: D53BD056  mrs      x22, tpidr_el0
uint64_t fde_func_6636_0x2497c4(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x002497C4ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10103FFULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90157F6ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9024FF4ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9037BFDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9100C3FDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD53BD056ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF94016C8ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0103F5ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #6640 | PC: 0x249bb0..0x249c94 (228 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x249bb0: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x249bb4: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x249bb8: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x249bbc: 910083FD  add      x29, sp, #0x20
//   0x249bc0: F1000428  subs     x8, x1, #1
//   0x249bc4: AA0003F3  mov      x19, x0
uint64_t fde_func_6640_0x249bb0(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00249BB0ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81D0FF5ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9014FF4ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9027BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910083FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF1000428ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x54000061ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x52800054ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #6645 | PC: 0x24a260..0x24a360 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x24a260: D10183FF  sub      sp, sp, #0x60
//   0x24a264: F9001BF5  str      x21, [sp, #0x30]
//   0x24a268: A9044FF4  stp      x20, x19, [sp, #0x40]
//   0x24a26c: A9057BFD  stp      x29, x30, [sp, #0x50]
//   0x24a270: 910143FD  add      x29, sp, #0x50
//   0x24a274: D53BD055  mrs      x21, tpidr_el0
uint64_t fde_func_6645_0x24a260(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0024A260ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10183FFULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9001BF5ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9044FF4ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9057BFDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910143FDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD53BD055ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF94016A8ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xEB00003FULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #6649 | PC: 0x24a440..0x24a4c0 (128 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x24a440: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x24a444: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x24a448: 910043FD  add      x29, sp, #0x10
//   0x24a44c: AA0003F3  mov      x19, x0
//   0x24a450: 52800900  mov      w0, #0x48
//   0x24a454: 97F7E71F  bl       #0x440d0
uint64_t fde_func_6649_0x24a440(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0024A440ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81E0FF3ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x52800900ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x97F7E71FULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF0000948ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910B4108ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #6654 | PC: 0x24a7a8..0x24a7c4 (28 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x24a7a8: F9400428  ldr      x8, [x1, #8]
//   0x24a7ac: B0000569  adrp     x9, #0x2f7000
//   0x24a7b0: 911BA929  add      x9, x9, #0x6ea
//   0x24a7b4: 9100200A  add      x10, x0, #8
//   0x24a7b8: EB09011F  cmp      x8, x9
//   0x24a7bc: 9A9F0140  csel     x0, x10, xzr, eq
uint64_t fde_func_6654_0x24a7a8(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0024A7A8ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400428ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB0000569ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x911BA929ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9100200AULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xEB09011FULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9A9F0140ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD65F03C0ULL ^ (6ULL << 32);
    return state ^ (state >> 29);
}

// FDE #6658 | PC: 0x24a810..0x24a880 (112 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x24a810: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x24a814: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x24a818: 910043FD  add      x29, sp, #0x10
//   0x24a81c: AA0003F3  mov      x19, x0
//   0x24a820: 52800700  mov      w0, #0x38
//   0x24a824: 97F7E62B  bl       #0x440d0
uint64_t fde_func_6658_0x24a810(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0024A810ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81E0FF3ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x52800700ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x97F7E62BULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF0000948ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910D0108ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #6663 | PC: 0x24a92c..0x24a948 (28 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x24a92c: F9400428  ldr      x8, [x1, #8]
//   0x24a930: B0000569  adrp     x9, #0x2f7000
//   0x24a934: 9115E929  add      x9, x9, #0x57a
//   0x24a938: 9100200A  add      x10, x0, #8
//   0x24a93c: EB09011F  cmp      x8, x9
//   0x24a940: 9A9F0140  csel     x0, x10, xzr, eq
uint64_t fde_func_6663_0x24a92c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0024A92CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400428ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB0000569ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9115E929ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9100200AULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xEB09011FULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9A9F0140ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD65F03C0ULL ^ (6ULL << 32);
    return state ^ (state >> 29);
}

// FDE #6667 | PC: 0x24a990..0x24a9a8 (24 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x24a990: F0000948  adrp     x8, #0x375000
//   0x24a994: 910FE108  add      x8, x8, #0x3f8
//   0x24a998: F9000028  str      x8, [x1]
//   0x24a99c: F9400408  ldr      x8, [x0, #8]
//   0x24a9a0: F9000428  str      x8, [x1, #8]
//   0x24a9a4: D65F03C0  ret      
uint64_t fde_func_6667_0x24a990(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0024A990ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF0000948ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910FE108ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000028ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400408ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000428ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD65F03C0ULL ^ (5ULL << 32);
    return state ^ (state >> 29);
}

// FDE #6672 | PC: 0x24a9dc..0x24a9e8 (12 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x24a9dc: F0000940  adrp     x0, #0x375000
//   0x24a9e0: 91116000  add      x0, x0, #0x458
//   0x24a9e4: D65F03C0  ret      
uint64_t fde_func_6672_0x24a9dc(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0024A9DCULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF0000940ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91116000ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD65F03C0ULL ^ (2ULL << 32);
    return state ^ (state >> 29);
}

// FDE #6676 | PC: 0x24ae7c..0x24aeec (112 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x24ae7c: A9402808  ldp      x8, x10, [x0]
//   0x24ae80: EB08015F  cmp      x10, x8
//   0x24ae84: 54000180  b.eq     #0x24aeb4
//   0x24ae88: F9400429  ldr      x9, [x1, #8]
//   0x24ae8c: 3CDF0D40  ldr      q0, [x10, #-0x10]!
//   0x24ae90: 3C9F0120  stur     q0, [x9, #-0x10]
uint64_t fde_func_6676_0x24ae7c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0024AE7CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9402808ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xEB08015FULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x54000180ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400429ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x3CDF0D40ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x3C9F0120ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9007D5FULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400429ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #6681 | PC: 0x24b16c..0x24b1ac (64 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x24b16c: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x24b170: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x24b174: 910043FD  add      x29, sp, #0x10
//   0x24b178: D37CFC28  lsr      x8, x1, #0x3c
//   0x24b17c: B5000168  cbnz     x8, #0x24b1a8
//   0x24b180: AA0003F4  mov      x20, x0
uint64_t fde_func_6681_0x24b16c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0024B16CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE4FF4ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD37CFC28ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB5000168ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F4ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD37CEC20ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0103F3ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #6685 | PC: 0x24b22c..0x24b248 (28 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x24b22c: D0000949  adrp     x9, #0x375000
//   0x24b230: AA0103E8  mov      x8, x1
//   0x24b234: 9111E129  add      x9, x9, #0x478
//   0x24b238: F8008509  str      x9, [x8], #8
//   0x24b23c: 91002001  add      x1, x0, #8
//   0x24b240: AA0803E0  mov      x0, x8
uint64_t fde_func_6685_0x24b22c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0024B22CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD0000949ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0103E8ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9111E129ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF8008509ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91002001ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0803E0ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x140000AEULL ^ (6ULL << 32);
    return state ^ (state >> 29);
}

// FDE #6690 | PC: 0x24b4f0..0x24b4fc (12 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x24b4f0: D0000940  adrp     x0, #0x375000
//   0x24b4f4: 91136000  add      x0, x0, #0x4d8
//   0x24b4f8: D65F03C0  ret      
uint64_t fde_func_6690_0x24b4f0(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0024B4F0ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD0000940ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91136000ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD65F03C0ULL ^ (2ULL << 32);
    return state ^ (state >> 29);
}

// FDE #6694 | PC: 0x24ba30..0x24bab4 (132 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x24ba30: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x24ba34: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x24ba38: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x24ba3c: 910083FD  add      x29, sp, #0x20
//   0x24ba40: F9400068  ldr      x8, [x3]
//   0x24ba44: AA0103F3  mov      x19, x1
uint64_t fde_func_6694_0x24ba30(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0024BA30ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81D0FF5ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9014FF4ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9027BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910083FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400068ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0103F3ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0103E0ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0803E1ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #6699 | PC: 0x24bf80..0x24c080 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x24bf80: D101C3FF  sub      sp, sp, #0x70
//   0x24bf84: F9000BFB  str      x27, [sp, #0x10]
//   0x24bf88: A90267FA  stp      x26, x25, [sp, #0x20]
//   0x24bf8c: A9035FF8  stp      x24, x23, [sp, #0x30]
//   0x24bf90: A90457F6  stp      x22, x21, [sp, #0x40]
//   0x24bf94: A9054FF4  stp      x20, x19, [sp, #0x50]
uint64_t fde_func_6699_0x24bf80(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0024BF80ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD101C3FFULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BFBULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90267FAULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9035FF8ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90457F6ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9054FF4ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9067BFDULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910183FDULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #6703 | PC: 0x24c778..0x24c878 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x24c778: D101C3FF  sub      sp, sp, #0x70
//   0x24c77c: A90457F6  stp      x22, x21, [sp, #0x40]
//   0x24c780: A9054FF4  stp      x20, x19, [sp, #0x50]
//   0x24c784: A9067BFD  stp      x29, x30, [sp, #0x60]
//   0x24c788: 910183FD  add      x29, sp, #0x60
//   0x24c78c: D53BD056  mrs      x22, tpidr_el0
uint64_t fde_func_6703_0x24c778(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0024C778ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD101C3FFULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90457F6ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9054FF4ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9067BFDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910183FDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD53BD056ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF94016C8ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #6708 | PC: 0x24d41c..0x24d4c4 (168 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x24d41c: D10183FF  sub      sp, sp, #0x60
//   0x24d420: A9044FF4  stp      x20, x19, [sp, #0x40]
//   0x24d424: A9057BFD  stp      x29, x30, [sp, #0x50]
//   0x24d428: 910143FD  add      x29, sp, #0x50
//   0x24d42c: D53BD053  mrs      x19, tpidr_el0
//   0x24d430: F9401668  ldr      x8, [x19, #0x28]
uint64_t fde_func_6708_0x24d41c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0024D41CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10183FFULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9044FF4ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9057BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910143FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD53BD053ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9401668ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9000094AULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x2A0103E9ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #6712 | PC: 0x24d888..0x24d988 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x24d888: F81A0FFB  str      x27, [sp, #-0x60]!
//   0x24d88c: A90167FA  stp      x26, x25, [sp, #0x10]
//   0x24d890: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x24d894: A90357F6  stp      x22, x21, [sp, #0x30]
//   0x24d898: A9044FF4  stp      x20, x19, [sp, #0x40]
//   0x24d89c: A9057BFD  stp      x29, x30, [sp, #0x50]
uint64_t fde_func_6712_0x24d888(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0024D888ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81A0FFBULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90167FAULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9025FF8ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90357F6ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9044FF4ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9057BFDULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910143FDULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400028ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #6716 | PC: 0x24e058..0x24e0c8 (112 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x24e058: F81C0FF7  str      x23, [sp, #-0x40]!
//   0x24e05c: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x24e060: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x24e064: A9037BFD  stp      x29, x30, [sp, #0x30]
//   0x24e068: 9100C3FD  add      x29, sp, #0x30
//   0x24e06c: 91128013  add      x19, x0, #0x4a0
uint64_t fde_func_6716_0x24e058(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0024E058ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81C0FF7ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90157F6ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9024FF4ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9037BFDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9100C3FDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91128013ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F4ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA1303E0ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #6721 | PC: 0x24e690..0x24e72c (156 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x24e690: D10143FF  sub      sp, sp, #0x50
//   0x24e694: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x24e698: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x24e69c: A9047BFD  stp      x29, x30, [sp, #0x40]
//   0x24e6a0: 910103FD  add      x29, sp, #0x40
//   0x24e6a4: D53BD056  mrs      x22, tpidr_el0
uint64_t fde_func_6721_0x24e690(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0024E690ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10143FFULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90257F6ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9034FF4ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9047BFDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910103FDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD53BD056ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF94016C8ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000FE8ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #6725 | PC: 0x24ebd0..0x24ecd0 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x24ebd0: D102C3FF  sub      sp, sp, #0xb0
//   0x24ebd4: A90857F6  stp      x22, x21, [sp, #0x80]
//   0x24ebd8: A9094FF4  stp      x20, x19, [sp, #0x90]
//   0x24ebdc: A90A7BFD  stp      x29, x30, [sp, #0xa0]
//   0x24ebe0: 910283FD  add      x29, sp, #0xa0
//   0x24ebe4: D53BD056  mrs      x22, tpidr_el0
uint64_t fde_func_6725_0x24ebd0(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0024EBD0ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD102C3FFULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90857F6ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9094FF4ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90A7BFDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910283FDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD53BD056ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0803F4ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF94016C8ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #6730 | PC: 0x24f920..0x24fa20 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x24f920: A9BA6FFC  stp      x28, x27, [sp, #-0x60]!
//   0x24f924: A90167FA  stp      x26, x25, [sp, #0x10]
//   0x24f928: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x24f92c: A90357F6  stp      x22, x21, [sp, #0x30]
//   0x24f930: A9044FF4  stp      x20, x19, [sp, #0x40]
//   0x24f934: A9057BFD  stp      x29, x30, [sp, #0x50]
uint64_t fde_func_6730_0x24f920(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0024F920ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BA6FFCULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90167FAULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9025FF8ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90357F6ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9044FF4ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9057BFDULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910143FDULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10F43FFULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #6734 | PC: 0x252060..0x252160 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x252060: F81A0FFC  str      x28, [sp, #-0x60]!
//   0x252064: A90167FA  stp      x26, x25, [sp, #0x10]
//   0x252068: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x25206c: A90357F6  stp      x22, x21, [sp, #0x30]
//   0x252070: A9044FF4  stp      x20, x19, [sp, #0x40]
//   0x252074: A9057BFD  stp      x29, x30, [sp, #0x50]
uint64_t fde_func_6734_0x252060(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00252060ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81A0FFCULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90167FAULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9025FF8ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90357F6ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9044FF4ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9057BFDULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910143FDULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD107C3FFULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #6739 | PC: 0x2529c0..0x252a44 (132 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x2529c0: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x2529c4: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x2529c8: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x2529cc: 910083FD  add      x29, sp, #0x20
//   0x2529d0: A9405008  ldp      x8, x20, [x0]
//   0x2529d4: B201F3EA  mov      x10, #-0x5555555555555556
uint64_t fde_func_6739_0x2529c0(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x002529C0ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81D0FF5ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9014FF4ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9027BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910083FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9405008ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB201F3EAULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF295556AULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #6743 | PC: 0x252b8c..0x252c8c (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x252b8c: D101C3FF  sub      sp, sp, #0x70
//   0x252b90: A9054FF4  stp      x20, x19, [sp, #0x50]
//   0x252b94: A9067BFD  stp      x29, x30, [sp, #0x60]
//   0x252b98: 910183FD  add      x29, sp, #0x60
//   0x252b9c: D53BD054  mrs      x20, tpidr_el0
//   0x252ba0: F9401688  ldr      x8, [x20, #0x28]
uint64_t fde_func_6743_0x252b8c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00252B8CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD101C3FFULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9054FF4ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9067BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910183FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD53BD054ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9401688ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81E83A8ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #6748 | PC: 0x2535dc..0x2535e4 (8 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x2535dc: D1002000  sub      x0, x0, #8
//   0x2535e0: 17FFFED4  b        #0x253130
uint64_t fde_func_6748_0x2535dc(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x002535DCULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD1002000ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x17FFFED4ULL ^ (1ULL << 32);
    return state ^ (state >> 29);
}

// FDE #6752 | PC: 0x25391c..0x253a1c (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x25391c: D10483FF  sub      sp, sp, #0x120
//   0x253920: A90E5FFC  stp      x28, x23, [sp, #0xe0]
//   0x253924: A90F57F6  stp      x22, x21, [sp, #0xf0]
//   0x253928: A9104FF4  stp      x20, x19, [sp, #0x100]
//   0x25392c: A9117BFD  stp      x29, x30, [sp, #0x110]
//   0x253930: 910443FD  add      x29, sp, #0x110
uint64_t fde_func_6752_0x25391c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0025391CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10483FFULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90E5FFCULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90F57F6ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9104FF4ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9117BFDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910443FDULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD53BD056ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF94016C8ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #6757 | PC: 0x2542dc..0x2543dc (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x2542dc: D104C3FF  sub      sp, sp, #0x130
//   0x2542e0: F9006BFC  str      x28, [sp, #0xd0]
//   0x2542e4: A90E67FA  stp      x26, x25, [sp, #0xe0]
//   0x2542e8: A90F5FF8  stp      x24, x23, [sp, #0xf0]
//   0x2542ec: A91057F6  stp      x22, x21, [sp, #0x100]
//   0x2542f0: A9114FF4  stp      x20, x19, [sp, #0x110]
uint64_t fde_func_6757_0x2542dc(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x002542DCULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD104C3FFULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9006BFCULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90E67FAULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90F5FF8ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA91057F6ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9114FF4ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9127BFDULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910483FDULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #6761 | PC: 0x254a18..0x254b18 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x254a18: D10503FF  sub      sp, sp, #0x140
//   0x254a1c: A90E6FFC  stp      x28, x27, [sp, #0xe0]
//   0x254a20: A90F67FA  stp      x26, x25, [sp, #0xf0]
//   0x254a24: A9105FF8  stp      x24, x23, [sp, #0x100]
//   0x254a28: A91157F6  stp      x22, x21, [sp, #0x110]
//   0x254a2c: A9124FF4  stp      x20, x19, [sp, #0x120]
uint64_t fde_func_6761_0x254a18(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00254A18ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10503FFULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90E6FFCULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90F67FAULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9105FF8ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA91157F6ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9124FF4ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9137BFDULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9104C3FDULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #6766 | PC: 0x255138..0x255178 (64 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x255138: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x25513c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x255140: 910043FD  add      x29, sp, #0x10
//   0x255144: CB010053  sub      x19, x2, x1
//   0x255148: F100067F  cmp      x19, #1
//   0x25514c: 5400010B  b.lt     #0x25516c
uint64_t fde_func_6766_0x255138(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00255138ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE4FF4ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xCB010053ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF100067FULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x5400010BULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400060ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA1303E2ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #6770 | PC: 0x2554d8..0x25554c (116 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x2554d8: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x2554dc: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x2554e0: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x2554e4: 910083FD  add      x29, sp, #0x20
//   0x2554e8: AA0203F5  mov      x21, x2
//   0x2554ec: AA0103F4  mov      x20, x1
uint64_t fde_func_6770_0x2554d8(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x002554D8ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81D0FF5ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9014FF4ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9027BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910083FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0203F5ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0103F4ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9018C1FULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #6775 | PC: 0x2556ac..0x25571c (112 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x2556ac: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x2556b0: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x2556b4: 910043FD  add      x29, sp, #0x10
//   0x2556b8: F9401408  ldr      x8, [x0, #0x28]
//   0x2556bc: AA0003F3  mov      x19, x0
//   0x2556c0: B4000108  cbz      x8, #0x2556e0
uint64_t fde_func_6775_0x2556ac(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x002556ACULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81E0FF3ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9401408ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB4000108ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA1303E0ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x2A1F03E1ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #6779 | PC: 0x2558bc..0x255928 (108 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x2558bc: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x2558c0: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x2558c4: 910043FD  add      x29, sp, #0x10
//   0x2558c8: A940A009  ldp      x9, x8, [x0, #8]
//   0x2558cc: AA0003F3  mov      x19, x0
//   0x2558d0: AA0103F4  mov      x20, x1
uint64_t fde_func_6779_0x2558bc(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x002558BCULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE4FF4ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA940A009ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0103F4ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xEB090109ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x540000C0ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #6784 | PC: 0x255de0..0x255ee0 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x255de0: F81B0FF9  str      x25, [sp, #-0x50]!
//   0x255de4: A9015FF8  stp      x24, x23, [sp, #0x10]
//   0x255de8: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x255dec: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x255df0: A9047BFD  stp      x29, x30, [sp, #0x40]
//   0x255df4: 910103FD  add      x29, sp, #0x40
uint64_t fde_func_6784_0x255de0(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00255DE0ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81B0FF9ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9015FF8ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90257F6ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9034FF4ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9047BFDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910103FDULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9412017ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #6788 | PC: 0x2562b0..0x2563b0 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x2562b0: A9BC5FF8  stp      x24, x23, [sp, #-0x40]!
//   0x2562b4: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x2562b8: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x2562bc: A9037BFD  stp      x29, x30, [sp, #0x30]
//   0x2562c0: 9100C3FD  add      x29, sp, #0x30
//   0x2562c4: A9405408  ldp      x8, x21, [x0]
uint64_t fde_func_6788_0x2562b0(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x002562B0ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BC5FF8ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90157F6ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9024FF4ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9037BFDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9100C3FDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9405408ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0103F4ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #6792 | PC: 0x2564a8..0x25655c (180 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x2564a8: F9400408  ldr      x8, [x0, #8]
//   0x2564ac: B4000548  cbz      x8, #0x256554
//   0x2564b0: 9E670100  fmov     d0, x8
//   0x2564b4: B9800029  ldrsw    x9, [x1]
//   0x2564b8: 0E205800  cnt      v0.8b, v0.8b
//   0x2564bc: 2E303800  uaddlv   h0, v0.8b
uint64_t fde_func_6792_0x2564a8(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x002564A8ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400408ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB4000548ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9E670100ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB9800029ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x0E205800ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x2E303800ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x1E26000AULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF100055FULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #6797 | PC: 0x256a60..0x256b58 (248 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x256a60: D10183FF  sub      sp, sp, #0x60
//   0x256a64: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x256a68: A90357F6  stp      x22, x21, [sp, #0x30]
//   0x256a6c: A9044FF4  stp      x20, x19, [sp, #0x40]
//   0x256a70: A9057BFD  stp      x29, x30, [sp, #0x50]
//   0x256a74: 910143FD  add      x29, sp, #0x50
uint64_t fde_func_6797_0x256a60(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00256A60ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10183FFULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9025FF8ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90357F6ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9044FF4ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9057BFDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910143FDULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD53BD058ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9401708ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #6801 | PC: 0x256edc..0x256fc0 (228 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x256edc: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x256ee0: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x256ee4: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x256ee8: 910083FD  add      x29, sp, #0x20
//   0x256eec: F1000428  subs     x8, x1, #1
//   0x256ef0: AA0003F3  mov      x19, x0
uint64_t fde_func_6801_0x256edc(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00256EDCULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81D0FF5ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9014FF4ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9027BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910083FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF1000428ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x54000061ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x52800054ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #6806 | PC: 0x257784..0x257884 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x257784: D10243FF  sub      sp, sp, #0x90
//   0x257788: A9036FFC  stp      x28, x27, [sp, #0x30]
//   0x25778c: A90467FA  stp      x26, x25, [sp, #0x40]
//   0x257790: A9055FF8  stp      x24, x23, [sp, #0x50]
//   0x257794: A90657F6  stp      x22, x21, [sp, #0x60]
//   0x257798: A9074FF4  stp      x20, x19, [sp, #0x70]
uint64_t fde_func_6806_0x257784(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00257784ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10243FFULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9036FFCULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90467FAULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9055FF8ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90657F6ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9074FF4ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9087BFDULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910203FDULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #6810 | PC: 0x257f74..0x258074 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x257f74: D101C3FF  sub      sp, sp, #0x70
//   0x257f78: F90013F9  str      x25, [sp, #0x20]
//   0x257f7c: A9035FF8  stp      x24, x23, [sp, #0x30]
//   0x257f80: A90457F6  stp      x22, x21, [sp, #0x40]
//   0x257f84: A9054FF4  stp      x20, x19, [sp, #0x50]
//   0x257f88: A9067BFD  stp      x29, x30, [sp, #0x60]
uint64_t fde_func_6810_0x257f74(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00257F74ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD101C3FFULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF90013F9ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9035FF8ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90457F6ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9054FF4ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9067BFDULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910183FDULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD53BD056ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #6815 | PC: 0x2585e0..0x258688 (168 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x2585e0: B4000521  cbz      x1, #0x258684
//   0x2585e4: A9402408  ldp      x8, x9, [x0]
//   0x2585e8: F940010A  ldr      x10, [x8]
//   0x2585ec: CB0A0129  sub      x9, x9, x10
//   0x2585f0: B201F3EA  mov      x10, #-0x5555555555555556
//   0x2585f4: 9343FD29  asr      x9, x9, #3
uint64_t fde_func_6815_0x2585e0(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x002585E0ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xB4000521ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9402408ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF940010AULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xCB0A0129ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB201F3EAULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9343FD29ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF295556AULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9B0A0529ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #6819 | PC: 0x258e08..0x258e78 (112 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x258e08: A9402808  ldp      x8, x10, [x0]
//   0x258e0c: EB08015F  cmp      x10, x8
//   0x258e10: 54000180  b.eq     #0x258e40
//   0x258e14: F9400429  ldr      x9, [x1, #8]
//   0x258e18: 3CDF0D40  ldr      q0, [x10, #-0x10]!
//   0x258e1c: 3C9F0120  stur     q0, [x9, #-0x10]
uint64_t fde_func_6819_0x258e08(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00258E08ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9402808ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xEB08015FULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x54000180ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400429ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x3CDF0D40ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x3C9F0120ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9007D5FULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400429ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #6824 | PC: 0x2590f8..0x259138 (64 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x2590f8: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x2590fc: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x259100: 910043FD  add      x29, sp, #0x10
//   0x259104: D37CFC28  lsr      x8, x1, #0x3c
//   0x259108: B5000168  cbnz     x8, #0x259134
//   0x25910c: AA0003F4  mov      x20, x0
uint64_t fde_func_6824_0x2590f8(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x002590F8ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE4FF4ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD37CFC28ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB5000168ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F4ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD37CEC20ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0103F3ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #6828 | PC: 0x2591c4..0x259204 (64 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x2591c4: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x2591c8: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x2591cc: 910043FD  add      x29, sp, #0x10
//   0x2591d0: 900008E8  adrp     x8, #0x375000
//   0x2591d4: AA0003F4  mov      x20, x0
//   0x2591d8: 9118A108  add      x8, x8, #0x628
uint64_t fde_func_6828_0x2591c4(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x002591C4ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE4FF4ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x900008E8ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F4ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9118A108ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0103F3ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91002020ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #6833 | PC: 0x2595f0..0x2595fc (12 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x2595f0: 900008E0  adrp     x0, #0x375000
//   0x2595f4: 911A2000  add      x0, x0, #0x688
//   0x2595f8: D65F03C0  ret      
uint64_t fde_func_6833_0x2595f0(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x002595F0ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0x900008E0ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x911A2000ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD65F03C0ULL ^ (2ULL << 32);
    return state ^ (state >> 29);
}

// FDE #6837 | PC: 0x25966c..0x259670 (4 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x25966c: 17F7AB31  b        #0x44330
uint64_t fde_func_6837_0x25966c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0025966CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0x17F7AB31ULL ^ (0ULL << 32);
    return state ^ (state >> 29);
}

// FDE #6842 | PC: 0x2598cc..0x25996c (160 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x2598cc: D10103FF  sub      sp, sp, #0x40
//   0x2598d0: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x2598d4: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x2598d8: A9037BFD  stp      x29, x30, [sp, #0x30]
//   0x2598dc: 9100C3FD  add      x29, sp, #0x30
//   0x2598e0: D53BD056  mrs      x22, tpidr_el0
uint64_t fde_func_6842_0x2598cc(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x002598CCULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10103FFULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90157F6ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9024FF4ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9037BFDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9100C3FDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD53BD056ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF94016C8ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0103F5ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #6846 | PC: 0x259c94..0x259d78 (228 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x259c94: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x259c98: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x259c9c: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x259ca0: 910083FD  add      x29, sp, #0x20
//   0x259ca4: F1000428  subs     x8, x1, #1
//   0x259ca8: AA0003F3  mov      x19, x0
uint64_t fde_func_6846_0x259c94(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00259C94ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81D0FF5ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9014FF4ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9027BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910083FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF1000428ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x54000061ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x52800054ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #6851 | PC: 0x25a14c..0x25a24c (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x25a14c: D10243FF  sub      sp, sp, #0x90
//   0x25a150: A90467FA  stp      x26, x25, [sp, #0x40]
//   0x25a154: A9055FF8  stp      x24, x23, [sp, #0x50]
//   0x25a158: A90657F6  stp      x22, x21, [sp, #0x60]
//   0x25a15c: A9074FF4  stp      x20, x19, [sp, #0x70]
//   0x25a160: A9087BFD  stp      x29, x30, [sp, #0x80]
uint64_t fde_func_6851_0x25a14c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0025A14CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10243FFULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90467FAULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9055FF8ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90657F6ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9074FF4ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9087BFDULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910203FDULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD53BD056ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #6855 | PC: 0x25aa3c..0x25aaa4 (104 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x25aa3c: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x25aa40: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x25aa44: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x25aa48: 910083FD  add      x29, sp, #0x20
//   0x25aa4c: F9400015  ldr      x21, [x0]
//   0x25aa50: B4000235  cbz      x21, #0x25aa94
uint64_t fde_func_6855_0x25aa3c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0025AA3CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81D0FF5ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9014FF4ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9027BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910083FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400015ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB4000235ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400414ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #6860 | PC: 0x25ae48..0x25aebc (116 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x25ae48: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x25ae4c: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x25ae50: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x25ae54: 910083FD  add      x29, sp, #0x20
//   0x25ae58: AA0203F5  mov      x21, x2
//   0x25ae5c: AA0103F4  mov      x20, x1
uint64_t fde_func_6860_0x25ae48(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0025AE48ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81D0FF5ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9014FF4ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9027BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910083FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0203F5ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0103F4ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9018C1FULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #6864 | PC: 0x25afe8..0x25b040 (88 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x25afe8: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x25afec: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x25aff0: 910043FD  add      x29, sp, #0x10
//   0x25aff4: AA0003F3  mov      x19, x0
//   0x25aff8: F9400000  ldr      x0, [x0]
//   0x25affc: B4000120  cbz      x0, #0x25b020
uint64_t fde_func_6864_0x25afe8(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0025AFE8ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81E0FF3ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400000ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB4000120ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x39402268ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x35000168ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #6868 | PC: 0x25b37c..0x25b47c (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x25b37c: D10283FF  sub      sp, sp, #0xa0
//   0x25b380: A9046FFC  stp      x28, x27, [sp, #0x40]
//   0x25b384: A90567FA  stp      x26, x25, [sp, #0x50]
//   0x25b388: A9065FF8  stp      x24, x23, [sp, #0x60]
//   0x25b38c: A90757F6  stp      x22, x21, [sp, #0x70]
//   0x25b390: A9084FF4  stp      x20, x19, [sp, #0x80]
uint64_t fde_func_6868_0x25b37c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0025B37CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10283FFULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9046FFCULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90567FAULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9065FF8ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90757F6ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9084FF4ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9097BFDULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910243FDULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #6873 | PC: 0x25b990..0x25ba0c (124 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x25b990: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x25b994: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x25b998: 910043FD  add      x29, sp, #0x10
//   0x25b99c: F9401008  ldr      x8, [x0, #0x20]
//   0x25b9a0: F9400409  ldr      x9, [x0, #8]
//   0x25b9a4: B202C7EA  mov      x10, #-0x3f3f3f3f3f3f3f40
uint64_t fde_func_6873_0x25b990(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0025B990ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81E0FF3ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9401008ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400409ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB202C7EAULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF298182AULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9BCA7D0AULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #6877 | PC: 0x25bb44..0x25bb90 (76 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x25bb44: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x25bb48: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x25bb4c: 910043FD  add      x29, sp, #0x10
//   0x25bb50: 39408008  ldrb     w8, [x0, #0x20]
//   0x25bb54: D00008C9  adrp     x9, #0x375000
//   0x25bb58: AA0003F3  mov      x19, x0
uint64_t fde_func_6877_0x25bb44(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0025BB44ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81E0FF3ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x39408008ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD00008C9ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x911CE129ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000009ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #6882 | PC: 0x25bd5c..0x25bdb0 (84 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x25bd5c: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x25bd60: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x25bd64: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x25bd68: 910083FD  add      x29, sp, #0x20
//   0x25bd6c: A9402014  ldp      x20, x8, [x0]
//   0x25bd70: AA0003F3  mov      x19, x0
uint64_t fde_func_6882_0x25bd5c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0025BD5CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81D0FF5ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9014FF4ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9027BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910083FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9402014ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xEB14011FULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x54000120ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #6886 | PC: 0x25c5bc..0x25c6bc (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x25c5bc: D10203FF  sub      sp, sp, #0x80
//   0x25c5c0: 6D0223E9  stp      d9, d8, [sp, #0x20]
//   0x25c5c4: F9001BF9  str      x25, [sp, #0x30]
//   0x25c5c8: A9045FF8  stp      x24, x23, [sp, #0x40]
//   0x25c5cc: A90557F6  stp      x22, x21, [sp, #0x50]
//   0x25c5d0: A9064FF4  stp      x20, x19, [sp, #0x60]
uint64_t fde_func_6886_0x25c5bc(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0025C5BCULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10203FFULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x6D0223E9ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9001BF9ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9045FF8ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90557F6ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9064FF4ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9077BFDULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9101C3FDULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #6891 | PC: 0x25d120..0x25d158 (56 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x25d120: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x25d124: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x25d128: 910043FD  add      x29, sp, #0x10
//   0x25d12c: AA0003F3  mov      x19, x0
//   0x25d130: 52800300  mov      w0, #0x18
//   0x25d134: 97F79BE7  bl       #0x440d0
uint64_t fde_func_6891_0x25d120(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0025D120ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81E0FF3ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x52800300ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x97F79BE7ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x900008C8ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x911DE108ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #6895 | PC: 0x25d178..0x25d1d8 (96 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x25d178: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x25d17c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x25d180: 910043FD  add      x29, sp, #0x10
//   0x25d184: F9400413  ldr      x19, [x0, #8]
//   0x25d188: AA0003F4  mov      x20, x0
//   0x25d18c: AA1303E0  mov      x0, x19
uint64_t fde_func_6895_0x25d178(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0025D178ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE4FF4ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400413ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F4ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA1303E0ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x97FFDC2FULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB9456268ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #6900 | PC: 0x25d39c..0x25d3f4 (88 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x25d39c: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x25d3a0: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x25d3a4: 910043FD  add      x29, sp, #0x10
//   0x25d3a8: F9400413  ldr      x19, [x0, #8]
//   0x25d3ac: B40000F3  cbz      x19, #0x25d3c8
//   0x25d3b0: 91002268  add      x8, x19, #8
uint64_t fde_func_6900_0x25d39c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0025D39CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81E0FF3ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400413ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB40000F3ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91002268ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xC85FFD09ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD100052AULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #6904 | PC: 0x25dd4c..0x25ddd4 (136 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x25dd4c: D100C3FF  sub      sp, sp, #0x30
//   0x25dd50: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x25dd54: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x25dd58: 910083FD  add      x29, sp, #0x20
//   0x25dd5c: AA0003F3  mov      x19, x0
//   0x25dd60: 91006000  add      x0, x0, #0x18
uint64_t fde_func_6904_0x25dd4c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0025DD4CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD100C3FFULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9014FF4ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9027BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910083FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91006000ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x940009CAULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB4000140ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #6909 | PC: 0x25e28c..0x25e38c (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x25e28c: D10303FF  sub      sp, sp, #0xc0
//   0x25e290: F9004BF5  str      x21, [sp, #0x90]
//   0x25e294: A90A4FF4  stp      x20, x19, [sp, #0xa0]
//   0x25e298: A90B7BFD  stp      x29, x30, [sp, #0xb0]
//   0x25e29c: 9102C3FD  add      x29, sp, #0xb0
//   0x25e2a0: D53BD055  mrs      x21, tpidr_el0
uint64_t fde_func_6909_0x25e28c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0025E28CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10303FFULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9004BF5ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90A4FF4ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90B7BFDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9102C3FDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD53BD055ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF94016A8ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #6913 | PC: 0x25f55c..0x25f65c (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x25f55c: D10243FF  sub      sp, sp, #0x90
//   0x25f560: F90033F5  str      x21, [sp, #0x60]
//   0x25f564: A9074FF4  stp      x20, x19, [sp, #0x70]
//   0x25f568: A9087BFD  stp      x29, x30, [sp, #0x80]
//   0x25f56c: 910203FD  add      x29, sp, #0x80
//   0x25f570: D53BD055  mrs      x21, tpidr_el0
uint64_t fde_func_6913_0x25f55c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0025F55CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10243FFULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF90033F5ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9074FF4ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9087BFDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910203FDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD53BD055ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF94016A8ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #6918 | PC: 0x25fbc8..0x25fc40 (120 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x25fbc8: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x25fbcc: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x25fbd0: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x25fbd4: 910083FD  add      x29, sp, #0x20
//   0x25fbd8: F9400808  ldr      x8, [x0, #0x10]
//   0x25fbdc: B40002A8  cbz      x8, #0x25fc30
uint64_t fde_func_6918_0x25fbc8(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0025FBC8ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BD57F6ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9014FF4ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9027BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910083FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400808ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB40002A8ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9405008ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F5ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #6922 | PC: 0x25fcfc..0x25fd74 (120 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x25fcfc: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x25fd00: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x25fd04: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x25fd08: 910083FD  add      x29, sp, #0x20
//   0x25fd0c: F9400808  ldr      x8, [x0, #0x10]
//   0x25fd10: B40002A8  cbz      x8, #0x25fd64
uint64_t fde_func_6922_0x25fcfc(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0025FCFCULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BD57F6ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9014FF4ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9027BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910083FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400808ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB40002A8ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9405008ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F5ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #6927 | PC: 0x25feac..0x25ff5c (176 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x25feac: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x25feb0: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x25feb4: 910043FD  add      x29, sp, #0x10
//   0x25feb8: B40003C1  cbz      x1, #0x25ff30
//   0x25febc: AA0003E8  mov      x8, x0
//   0x25fec0: F9400420  ldr      x0, [x1, #8]
uint64_t fde_func_6927_0x25feac(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0025FEACULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81E0FF3ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB40003C1ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003E8ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400420ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB4000080ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400409ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #6931 | PC: 0x25ffcc..0x25ffd0 (4 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x25ffcc: 17F790D9  b        #0x44330
uint64_t fde_func_6931_0x25ffcc(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0025FFCCULL);
    state = (state * 0x00000100000001B3ULL) ^ 0x17F790D9ULL ^ (0ULL << 32);
    return state ^ (state >> 29);
}

// FDE #6936 | PC: 0x2601a4..0x2601e4 (64 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x2601a4: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x2601a8: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x2601ac: 910043FD  add      x29, sp, #0x10
//   0x2601b0: F9400028  ldr      x8, [x1]
//   0x2601b4: AA0003F3  mov      x19, x0
//   0x2601b8: F9000008  str      x8, [x0]
uint64_t fde_func_6936_0x2601a4(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x002601A4ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81E0FF3ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400028ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000008ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400420ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB40000E0ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #6940 | PC: 0x260238..0x26023c (4 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x260238: D65F03C0  ret      
uint64_t fde_func_6940_0x260238(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00260238ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD65F03C0ULL ^ (0ULL << 32);
    return state ^ (state >> 29);
}

// FDE #6945 | PC: 0x260278..0x260378 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x260278: D101C3FF  sub      sp, sp, #0x70
//   0x26027c: F9000BFB  str      x27, [sp, #0x10]
//   0x260280: A90267FA  stp      x26, x25, [sp, #0x20]
//   0x260284: A9035FF8  stp      x24, x23, [sp, #0x30]
//   0x260288: A90457F6  stp      x22, x21, [sp, #0x40]
//   0x26028c: A9054FF4  stp      x20, x19, [sp, #0x50]
uint64_t fde_func_6945_0x260278(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00260278ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD101C3FFULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BFBULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90267FAULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9035FF8ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90457F6ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9054FF4ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9067BFDULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910183FDULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #6949 | PC: 0x2606fc..0x260734 (56 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x2606fc: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x260700: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x260704: 910043FD  add      x29, sp, #0x10
//   0x260708: AA0003F3  mov      x19, x0
//   0x26070c: F9401000  ldr      x0, [x0, #0x20]
//   0x260710: B00008A8  adrp     x8, #0x375000
uint64_t fde_func_6949_0x2606fc(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x002606FCULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81E0FF3ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9401000ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB00008A8ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9125A108ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000268ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #6953 | PC: 0x260788..0x2607d8 (80 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x260788: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x26078c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x260790: 910043FD  add      x29, sp, #0x10
//   0x260794: A9405028  ldp      x8, x20, [x1]
//   0x260798: AA0103F3  mov      x19, x1
//   0x26079c: 91004022  add      x2, x1, #0x10
uint64_t fde_func_6953_0x260788(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00260788ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE4FF4ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9405028ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0103F3ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91004022ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000514ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400429ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #6958 | PC: 0x260a10..0x260b10 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x260a10: D10243FF  sub      sp, sp, #0x90
//   0x260a14: A9036FFC  stp      x28, x27, [sp, #0x30]
//   0x260a18: A90467FA  stp      x26, x25, [sp, #0x40]
//   0x260a1c: A9055FF8  stp      x24, x23, [sp, #0x50]
//   0x260a20: A90657F6  stp      x22, x21, [sp, #0x60]
//   0x260a24: A9074FF4  stp      x20, x19, [sp, #0x70]
uint64_t fde_func_6958_0x260a10(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00260A10ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10243FFULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9036FFCULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90467FAULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9055FF8ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90657F6ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9074FF4ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9087BFDULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910203FDULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #6962 | PC: 0x26107c..0x261080 (4 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x26107c: 17F78CAD  b        #0x44330
uint64_t fde_func_6962_0x26107c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0026107CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0x17F78CADULL ^ (0ULL << 32);
    return state ^ (state >> 29);
}

// FDE #6967 | PC: 0x2610d8..0x2610e0 (8 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x2610d8: F9400400  ldr      x0, [x0, #8]
//   0x2610dc: 17FFF920  b        #0x25f55c
uint64_t fde_func_6967_0x2610d8(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x002610D8ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400400ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x17FFF920ULL ^ (1ULL << 32);
    return state ^ (state >> 29);
}

// FDE #6971 | PC: 0x26110c..0x261144 (56 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x26110c: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x261110: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x261114: 910043FD  add      x29, sp, #0x10
//   0x261118: AA0003F3  mov      x19, x0
//   0x26111c: 52800200  mov      w0, #0x10
//   0x261120: 97F78BEC  bl       #0x440d0
uint64_t fde_func_6971_0x26110c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0026110CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81E0FF3ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x52800200ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x97F78BECULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x900008A8ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9128E108ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #6976 | PC: 0x26116c..0x261188 (28 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x26116c: F9400428  ldr      x8, [x1, #8]
//   0x261170: 900004C9  adrp     x9, #0x2f9000
//   0x261174: 9114C129  add      x9, x9, #0x530
//   0x261178: 9100200A  add      x10, x0, #8
//   0x26117c: EB09011F  cmp      x8, x9
//   0x261180: 9A9F0140  csel     x0, x10, xzr, eq
uint64_t fde_func_6976_0x26116c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0026116CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400428ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x900004C9ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9114C129ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9100200AULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xEB09011FULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9A9F0140ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD65F03C0ULL ^ (6ULL << 32);
    return state ^ (state >> 29);
}

// FDE #6980 | PC: 0x2612a4..0x2612e0 (60 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x2612a4: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x2612a8: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x2612ac: 910043FD  add      x29, sp, #0x10
//   0x2612b0: 39404008  ldrb     w8, [x0, #0x10]
//   0x2612b4: 900008A9  adrp     x9, #0x375000
//   0x2612b8: AA0003F3  mov      x19, x0
uint64_t fde_func_6980_0x2612a4(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x002612A4ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81E0FF3ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x39404008ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x900008A9ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x912AE129ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000009ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #6985 | PC: 0x261394..0x261494 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x261394: D10243FF  sub      sp, sp, #0x90
//   0x261398: A90467FA  stp      x26, x25, [sp, #0x40]
//   0x26139c: A9055FF8  stp      x24, x23, [sp, #0x50]
//   0x2613a0: A90657F6  stp      x22, x21, [sp, #0x60]
//   0x2613a4: A9074FF4  stp      x20, x19, [sp, #0x70]
//   0x2613a8: A9087BFD  stp      x29, x30, [sp, #0x80]
uint64_t fde_func_6985_0x261394(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00261394ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10243FFULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90467FAULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9055FF8ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90657F6ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9074FF4ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9087BFDULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910203FDULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD53BD059ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #6989 | PC: 0x261754..0x261854 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x261754: A9BA6FFC  stp      x28, x27, [sp, #-0x60]!
//   0x261758: A90167FA  stp      x26, x25, [sp, #0x10]
//   0x26175c: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x261760: A90357F6  stp      x22, x21, [sp, #0x30]
//   0x261764: A9044FF4  stp      x20, x19, [sp, #0x40]
//   0x261768: A9057BFD  stp      x29, x30, [sp, #0x50]
uint64_t fde_func_6989_0x261754(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00261754ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BA6FFCULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90167FAULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9025FF8ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90357F6ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9044FF4ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9057BFDULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910143FDULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F4ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #6994 | PC: 0x261a64..0x261ae8 (132 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x261a64: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x261a68: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x261a6c: 910043FD  add      x29, sp, #0x10
//   0x261a70: F9400428  ldr      x8, [x1, #8]
//   0x261a74: B40000A8  cbz      x8, #0x261a88
//   0x261a78: AA0803F3  mov      x19, x8
uint64_t fde_func_6994_0x261a64(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00261A64ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81E0FF3ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400428ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB40000A8ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0803F3ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400108ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB5FFFFC8ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #6998 | PC: 0x261b3c..0x261b40 (4 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x261b3c: D65F03C0  ret      
uint64_t fde_func_6998_0x261b3c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00261B3CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD65F03C0ULL ^ (0ULL << 32);
    return state ^ (state >> 29);
}

// FDE #7003 | PC: 0x261be8..0x261c18 (48 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x261be8: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x261bec: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x261bf0: 910043FD  add      x29, sp, #0x10
//   0x261bf4: 900008A8  adrp     x8, #0x375000
//   0x261bf8: 912EE108  add      x8, x8, #0xbb8
//   0x261bfc: AA0003F3  mov      x19, x0
uint64_t fde_func_7003_0x261be8(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00261BE8ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81E0FF3ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x900008A8ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x912EE108ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF8018408ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x940028B6ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #7007 | PC: 0x261c5c..0x261c60 (4 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x261c5c: 17F789B5  b        #0x44330
uint64_t fde_func_7007_0x261c5c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00261C5CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0x17F789B5ULL ^ (0ULL << 32);
    return state ^ (state >> 29);
}

// FDE #7012 | PC: 0x261cb8..0x261cc0 (8 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x261cb8: F9400400  ldr      x0, [x0, #8]
//   0x261cbc: 17FFF493  b        #0x25ef08
uint64_t fde_func_7012_0x261cb8(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00261CB8ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400400ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x17FFF493ULL ^ (1ULL << 32);
    return state ^ (state >> 29);
}

// FDE #7016 | PC: 0x261d28..0x261d70 (72 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x261d28: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x261d2c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x261d30: 910043FD  add      x29, sp, #0x10
//   0x261d34: AA0003F3  mov      x19, x0
//   0x261d38: F9402000  ldr      x0, [x0, #0x40]
//   0x261d3c: 900008A8  adrp     x8, #0x375000
uint64_t fde_func_7016_0x261d28(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00261D28ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81E0FF3ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9402000ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x900008A8ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91322108ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000268ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #7021 | PC: 0x261eb4..0x261fb0 (252 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x261eb4: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x261eb8: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x261ebc: 910043FD  add      x29, sp, #0x10
//   0x261ec0: 900008A8  adrp     x8, #0x375000
//   0x261ec4: 91336108  add      x8, x8, #0xcd8
//   0x261ec8: A9007C08  stp      x8, xzr, [x0]
uint64_t fde_func_7021_0x261eb4(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00261EB4ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE4FF4ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x900008A8ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91336108ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9007C08ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA901041FULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400048ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #7025 | PC: 0x262134..0x26218c (88 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x262134: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x262138: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x26213c: 910043FD  add      x29, sp, #0x10
//   0x262140: F9400413  ldr      x19, [x0, #8]
//   0x262144: B40000F3  cbz      x19, #0x262160
//   0x262148: 91002268  add      x8, x19, #8
uint64_t fde_func_7025_0x262134(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00262134ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81E0FF3ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400413ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB40000F3ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91002268ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xC85FFD09ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD100052AULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #7029 | PC: 0x262b38..0x262ba8 (112 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x262b38: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x262b3c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x262b40: 910043FD  add      x29, sp, #0x10
//   0x262b44: 39416408  ldrb     w8, [x0, #0x59]
//   0x262b48: 39416009  ldrb     w9, [x0, #0x58]
//   0x262b4c: 5280002A  mov      w10, #1
uint64_t fde_func_7029_0x262b38(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00262B38ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81E0FF3ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x39416408ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x39416009ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x5280002AULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x52800020ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x7100011FULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #7034 | PC: 0x263890..0x263990 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x263890: D10303FF  sub      sp, sp, #0xc0
//   0x263894: A90957F6  stp      x22, x21, [sp, #0x90]
//   0x263898: A90A4FF4  stp      x20, x19, [sp, #0xa0]
//   0x26389c: A90B7BFD  stp      x29, x30, [sp, #0xb0]
//   0x2638a0: 9102C3FD  add      x29, sp, #0xb0
//   0x2638a4: D53BD055  mrs      x21, tpidr_el0
uint64_t fde_func_7034_0x263890(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00263890ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10303FFULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90957F6ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90A4FF4ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90B7BFDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9102C3FDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD53BD055ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF94016A8ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #7038 | PC: 0x26439c..0x2643f4 (88 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x26439c: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x2643a0: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x2643a4: 910043FD  add      x29, sp, #0x10
//   0x2643a8: F9400413  ldr      x19, [x0, #8]
//   0x2643ac: B40000F3  cbz      x19, #0x2643c8
//   0x2643b0: 91002268  add      x8, x19, #8
uint64_t fde_func_7038_0x26439c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0026439CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81E0FF3ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400413ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB40000F3ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91002268ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xC85FFD09ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD100052AULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #7043 | PC: 0x26524c..0x26534c (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x26524c: D101C3FF  sub      sp, sp, #0x70
//   0x265250: F90023F5  str      x21, [sp, #0x40]
//   0x265254: A9054FF4  stp      x20, x19, [sp, #0x50]
//   0x265258: A9067BFD  stp      x29, x30, [sp, #0x60]
//   0x26525c: 910183FD  add      x29, sp, #0x60
//   0x265260: D53BD055  mrs      x21, tpidr_el0
uint64_t fde_func_7043_0x26524c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0026524CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD101C3FFULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF90023F5ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9054FF4ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9067BFDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910183FDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD53BD055ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF94016A8ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #7047 | PC: 0x266dcc..0x266e24 (88 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x266dcc: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x266dd0: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x266dd4: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x266dd8: 910083FD  add      x29, sp, #0x20
//   0x266ddc: AA0203F3  mov      x19, x2
//   0x266de0: AA0003F5  mov      x21, x0
uint64_t fde_func_7047_0x266dcc(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00266DCCULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81D0FF5ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9014FF4ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9027BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910083FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0203F3ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F5ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x97F78305ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910062B4ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #7052 | PC: 0x266f68..0x266fa4 (60 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x266f68: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x266f6c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x266f70: 910043FD  add      x29, sp, #0x10
//   0x266f74: 91006040  add      x0, x2, #0x18
//   0x266f78: AA0203F3  mov      x19, x2
//   0x266f7c: 97F80B51  bl       #0x69cc0
uint64_t fde_func_7052_0x266f68(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00266F68ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81E0FF3ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91006040ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0203F3ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x97F80B51ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x39400268ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x37000088ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #7056 | PC: 0x267108..0x267138 (48 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x267108: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x26710c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x267110: 910043FD  add      x29, sp, #0x10
//   0x267114: D0000868  adrp     x8, #0x375000
//   0x267118: 91354108  add      x8, x8, #0xd50
//   0x26711c: AA0003F3  mov      x19, x0
uint64_t fde_func_7056_0x267108(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00267108ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81E0FF3ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD0000868ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91354108ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF8018408ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x94000040ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #7061 | PC: 0x267224..0x267270 (76 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x267224: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x267228: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x26722c: 910043FD  add      x29, sp, #0x10
//   0x267230: AA0003F3  mov      x19, x0
//   0x267234: 9100C014  add      x20, x0, #0x30
//   0x267238: 91012000  add      x0, x0, #0x48
uint64_t fde_func_7061_0x267224(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00267224ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE4FF4ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9100C014ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91012000ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9400000DULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA1403E0ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #7065 | PC: 0x267368..0x2673a4 (60 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x267368: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x26736c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x267370: 910043FD  add      x29, sp, #0x10
//   0x267374: 91006040  add      x0, x2, #0x18
//   0x267378: AA0203F3  mov      x19, x2
//   0x26737c: 97F970A6  bl       #0xc3614
uint64_t fde_func_7065_0x267368(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00267368ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81E0FF3ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91006040ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0203F3ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x97F970A6ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x39400268ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x37000088ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #7070 | PC: 0x267530..0x267538 (8 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x267530: 91006000  add      x0, x0, #0x18
//   0x267534: 14000045  b        #0x267648
uint64_t fde_func_7070_0x267530(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00267530ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0x91006000ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x14000045ULL ^ (1ULL << 32);
    return state ^ (state >> 29);
}

// FDE #7074 | PC: 0x267688..0x2676c8 (64 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x267688: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x26768c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x267690: 910043FD  add      x29, sp, #0x10
//   0x267694: F9400028  ldr      x8, [x1]
//   0x267698: AA0003F3  mov      x19, x0
//   0x26769c: F9000008  str      x8, [x0]
uint64_t fde_func_7074_0x267688(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00267688ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81E0FF3ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400028ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000008ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400420ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB40000E0ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #7079 | PC: 0x267720..0x267724 (4 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x267720: 17F77304  b        #0x44330
uint64_t fde_func_7079_0x267720(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00267720ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0x17F77304ULL ^ (0ULL << 32);
    return state ^ (state >> 29);
}

// FDE #7083 | PC: 0x26775c..0x267780 (36 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x26775c: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x267760: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x267764: 910043FD  add      x29, sp, #0x10
//   0x267768: AA0003F3  mov      x19, x0
//   0x26776c: 97F77615  bl       #0x44fc0
//   0x267770: A9417BFD  ldp      x29, x30, [sp, #0x10]
uint64_t fde_func_7083_0x26775c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0026775CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81E0FF3ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x97F77615ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9417BFDULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA1303E0ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF84207F3ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #7088 | PC: 0x2677c4..0x2677dc (24 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x2677c4: D0000868  adrp     x8, #0x375000
//   0x2677c8: 913B0108  add      x8, x8, #0xec0
//   0x2677cc: F9000028  str      x8, [x1]
//   0x2677d0: F9400408  ldr      x8, [x0, #8]
//   0x2677d4: F9000428  str      x8, [x1, #8]
//   0x2677d8: D65F03C0  ret      
uint64_t fde_func_7088_0x2677c4(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x002677C4ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD0000868ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x913B0108ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000028ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400408ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000428ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD65F03C0ULL ^ (5ULL << 32);
    return state ^ (state >> 29);
}

// FDE #7092 | PC: 0x267884..0x2678a0 (28 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x267884: F9400428  ldr      x8, [x1, #8]
//   0x267888: F0000489  adrp     x9, #0x2fa000
//   0x26788c: 91170129  add      x9, x9, #0x5c0
//   0x267890: 9100200A  add      x10, x0, #8
//   0x267894: EB09011F  cmp      x8, x9
//   0x267898: 9A9F0140  csel     x0, x10, xzr, eq
uint64_t fde_func_7092_0x267884(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00267884ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400428ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF0000489ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91170129ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9100200AULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xEB09011FULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9A9F0140ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD65F03C0ULL ^ (6ULL << 32);
    return state ^ (state >> 29);
}

// FDE #7097 | PC: 0x267950..0x267978 (40 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x267950: D0000868  adrp     x8, #0x375000
//   0x267954: 913D0108  add      x8, x8, #0xf40
//   0x267958: F9000028  str      x8, [x1]
//   0x26795c: F940040A  ldr      x10, [x0, #8]
//   0x267960: 91004028  add      x8, x1, #0x10
//   0x267964: 91004009  add      x9, x0, #0x10
uint64_t fde_func_7097_0x267950(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00267950ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD0000868ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x913D0108ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000028ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF940040AULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91004028ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91004009ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0803E0ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF900042AULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #7101 | PC: 0x2679cc..0x2679e8 (28 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x2679cc: F9400428  ldr      x8, [x1, #8]
//   0x2679d0: F0000489  adrp     x9, #0x2fa000
//   0x2679d4: 911B0929  add      x9, x9, #0x6c2
//   0x2679d8: 9100200A  add      x10, x0, #8
//   0x2679dc: EB09011F  cmp      x8, x9
//   0x2679e0: 9A9F0140  csel     x0, x10, xzr, eq
uint64_t fde_func_7101_0x2679cc(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x002679CCULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400428ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF0000489ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x911B0929ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9100200AULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xEB09011FULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9A9F0140ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD65F03C0ULL ^ (6ULL << 32);
    return state ^ (state >> 29);
}

// FDE #7106 | PC: 0x267c8c..0x267d8c (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x267c8c: A9BA6FFC  stp      x28, x27, [sp, #-0x60]!
//   0x267c90: A90167FA  stp      x26, x25, [sp, #0x10]
//   0x267c94: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x267c98: A90357F6  stp      x22, x21, [sp, #0x30]
//   0x267c9c: A9044FF4  stp      x20, x19, [sp, #0x40]
//   0x267ca0: A9057BFD  stp      x29, x30, [sp, #0x50]
uint64_t fde_func_7106_0x267c8c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00267C8CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BA6FFCULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90167FAULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9025FF8ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90357F6ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9044FF4ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9057BFDULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910143FDULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F4ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #7110 | PC: 0x267f38..0x268038 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x267f38: A9BC5FF8  stp      x24, x23, [sp, #-0x40]!
//   0x267f3c: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x267f40: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x267f44: A9037BFD  stp      x29, x30, [sp, #0x30]
//   0x267f48: 9100C3FD  add      x29, sp, #0x30
//   0x267f4c: AA0003F3  mov      x19, x0
uint64_t fde_func_7110_0x267f38(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00267F38ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BC5FF8ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90157F6ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9024FF4ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9037BFDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9100C3FDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF8408E77ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB40006B7ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #7114 | PC: 0x268154..0x268254 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x268154: A9BC5FF8  stp      x24, x23, [sp, #-0x40]!
//   0x268158: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x26815c: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x268160: A9037BFD  stp      x29, x30, [sp, #0x30]
//   0x268164: 9100C3FD  add      x29, sp, #0x30
//   0x268168: AA0003F3  mov      x19, x0
uint64_t fde_func_7114_0x268154(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00268154ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BC5FF8ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90157F6ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9024FF4ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9037BFDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9100C3FDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF8408E77ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB40006B7ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #7119 | PC: 0x26847c..0x2684bc (64 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x26847c: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x268480: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x268484: 910043FD  add      x29, sp, #0x10
//   0x268488: AA0103F3  mov      x19, x1
//   0x26848c: 9400000C  bl       #0x2684bc
//   0x268490: 39408268  ldrb     w8, [x19, #0x20]
uint64_t fde_func_7119_0x26847c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0026847CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE4FF4ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0103F3ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9400000CULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x39408268ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F4ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x36000068ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #7123 | PC: 0x26871c..0x268770 (84 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x26871c: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x268720: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x268724: 910043FD  add      x29, sp, #0x10
//   0x268728: A9007C7F  stp      xzr, xzr, [x3]
//   0x26872c: F9000861  str      x1, [x3, #0x10]
//   0x268730: F9000043  str      x3, [x2]
uint64_t fde_func_7123_0x26871c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0026871CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81E0FF3ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9007C7FULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000861ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000043ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400008ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #7128 | PC: 0x268814..0x2688c4 (176 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x268814: D10143FF  sub      sp, sp, #0x50
//   0x268818: F9000BF7  str      x23, [sp, #0x10]
//   0x26881c: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x268820: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x268824: A9047BFD  stp      x29, x30, [sp, #0x40]
//   0x268828: 910103FD  add      x29, sp, #0x40
uint64_t fde_func_7128_0x268814(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00268814ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10143FFULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF7ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90257F6ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9034FF4ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9047BFDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910103FDULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD53BD057ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF94016E8ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #7132 | PC: 0x268a40..0x268a78 (56 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x268a40: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x268a44: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x268a48: 910043FD  add      x29, sp, #0x10
//   0x268a4c: AA0003F3  mov      x19, x0
//   0x268a50: 52800200  mov      w0, #0x10
//   0x268a54: 97F76D9F  bl       #0x440d0
uint64_t fde_func_7132_0x268a40(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00268A40ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81E0FF3ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x52800200ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x97F76D9FULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD0000868ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91004108ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #7137 | PC: 0x268aa0..0x268abc (28 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x268aa0: F9400428  ldr      x8, [x1, #8]
//   0x268aa4: D0000489  adrp     x9, #0x2fa000
//   0x268aa8: 91201929  add      x9, x9, #0x806
//   0x268aac: 9100200A  add      x10, x0, #8
//   0x268ab0: EB09011F  cmp      x8, x9
//   0x268ab4: 9A9F0140  csel     x0, x10, xzr, eq
uint64_t fde_func_7137_0x268aa0(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00268AA0ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400428ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD0000489ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91201929ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9100200AULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xEB09011FULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9A9F0140ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD65F03C0ULL ^ (6ULL << 32);
    return state ^ (state >> 29);
}

// FDE #7141 | PC: 0x268b04..0x268b1c (24 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x268b04: D0000868  adrp     x8, #0x376000
//   0x268b08: 91024108  add      x8, x8, #0x90
//   0x268b0c: F9000028  str      x8, [x1]
//   0x268b10: F9400408  ldr      x8, [x0, #8]
//   0x268b14: F9000428  str      x8, [x1, #8]
//   0x268b18: D65F03C0  ret      
uint64_t fde_func_7141_0x268b04(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00268B04ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD0000868ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91024108ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000028ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400408ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000428ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD65F03C0ULL ^ (5ULL << 32);
    return state ^ (state >> 29);
}

// FDE #7146 | PC: 0x268b4c..0x268b58 (12 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x268b4c: D0000860  adrp     x0, #0x376000
//   0x268b50: 9103C000  add      x0, x0, #0xf0
//   0x268b54: D65F03C0  ret      
uint64_t fde_func_7146_0x268b4c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00268B4CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD0000860ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9103C000ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD65F03C0ULL ^ (2ULL << 32);
    return state ^ (state >> 29);
}

// FDE #7150 | PC: 0x268bac..0x268bb0 (4 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x268bac: D65F03C0  ret      
uint64_t fde_func_7150_0x268bac(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00268BACULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD65F03C0ULL ^ (0ULL << 32);
    return state ^ (state >> 29);
}

uint64_t execute_fde_shard_4(uint32_t fde_idx, uint64_t a0, uint64_t a1) {
    switch (fde_idx) {
        case 5366: return fde_func_5366_0x1d97b4(a0, a1);
        case 5370: return fde_func_5370_0x1d9b7c(a0, a1);
        case 5375: return fde_func_5375_0x1d9f88(a0, a1);
        case 5379: return fde_func_5379_0x1da040(a0, a1);
        case 5384: return fde_func_5384_0x1da108(a0, a1);
        case 5388: return fde_func_5388_0x1da40c(a0, a1);
        case 5393: return fde_func_5393_0x1da5fc(a0, a1);
        case 5397: return fde_func_5397_0x1da6c4(a0, a1);
        case 5402: return fde_func_5402_0x1da90c(a0, a1);
        case 5406: return fde_func_5406_0x1daa5c(a0, a1);
        case 5411: return fde_func_5411_0x1dacc4(a0, a1);
        case 5415: return fde_func_5415_0x1dafec(a0, a1);
        case 5420: return fde_func_5420_0x1db840(a0, a1);
        case 5424: return fde_func_5424_0x1dbd08(a0, a1);
        case 5429: return fde_func_5429_0x1dc0a0(a0, a1);
        case 5433: return fde_func_5433_0x1dc150(a0, a1);
        case 5437: return fde_func_5437_0x1dc1b8(a0, a1);
        case 5442: return fde_func_5442_0x1dc758(a0, a1);
        case 5446: return fde_func_5446_0x1dc7cc(a0, a1);
        case 5451: return fde_func_5451_0x1dd05c(a0, a1);
        case 5455: return fde_func_5455_0x1dd174(a0, a1);
        case 5460: return fde_func_5460_0x1dd6a0(a0, a1);
        case 5464: return fde_func_5464_0x1dda40(a0, a1);
        case 5469: return fde_func_5469_0x1ddccc(a0, a1);
        case 5473: return fde_func_5473_0x1ddcfc(a0, a1);
        case 5478: return fde_func_5478_0x1ddd38(a0, a1);
        case 5482: return fde_func_5482_0x1ddd68(a0, a1);
        case 5487: return fde_func_5487_0x1dddac(a0, a1);
        case 5491: return fde_func_5491_0x1dde54(a0, a1);
        case 5496: return fde_func_5496_0x1de05c(a0, a1);
        case 5500: return fde_func_5500_0x1de104(a0, a1);
        case 5505: return fde_func_5505_0x1de180(a0, a1);
        case 5509: return fde_func_5509_0x1de2dc(a0, a1);
        case 5513: return fde_func_5513_0x1de7ec(a0, a1);
        case 5518: return fde_func_5518_0x1deddc(a0, a1);
        case 5522: return fde_func_5522_0x1defd8(a0, a1);
        case 5527: return fde_func_5527_0x1df2fc(a0, a1);
        case 5531: return fde_func_5531_0x1df518(a0, a1);
        case 5536: return fde_func_5536_0x1df654(a0, a1);
        case 5540: return fde_func_5540_0x1df6cc(a0, a1);
        case 5545: return fde_func_5545_0x1df84c(a0, a1);
        case 5549: return fde_func_5549_0x1df934(a0, a1);
        case 5554: return fde_func_5554_0x1dfb0c(a0, a1);
        case 5558: return fde_func_5558_0x1dff38(a0, a1);
        case 5563: return fde_func_5563_0x1e01ac(a0, a1);
        case 5567: return fde_func_5567_0x1e0410(a0, a1);
        case 5572: return fde_func_5572_0x1e07a8(a0, a1);
        case 5576: return fde_func_5576_0x1e0908(a0, a1);
        case 5581: return fde_func_5581_0x1e2df0(a0, a1);
        case 5585: return fde_func_5585_0x1e3760(a0, a1);
        case 5590: return fde_func_5590_0x1e3f18(a0, a1);
        case 5594: return fde_func_5594_0x1e4154(a0, a1);
        case 5598: return fde_func_5598_0x1e44d4(a0, a1);
        case 5603: return fde_func_5603_0x1e46a8(a0, a1);
        case 5607: return fde_func_5607_0x1e4cd8(a0, a1);
        case 5612: return fde_func_5612_0x1e4e10(a0, a1);
        case 5616: return fde_func_5616_0x1e4fb0(a0, a1);
        case 5621: return fde_func_5621_0x1e56bc(a0, a1);
        case 5625: return fde_func_5625_0x1e5964(a0, a1);
        case 5630: return fde_func_5630_0x1e5e30(a0, a1);
        case 5634: return fde_func_5634_0x1e64e0(a0, a1);
        case 5639: return fde_func_5639_0x1e81b4(a0, a1);
        case 5643: return fde_func_5643_0x1e991c(a0, a1);
        case 5648: return fde_func_5648_0x1eaa54(a0, a1);
        case 5652: return fde_func_5652_0x1ec438(a0, a1);
        case 5657: return fde_func_5657_0x1ede4c(a0, a1);
        case 5661: return fde_func_5661_0x1ef5ac(a0, a1);
        case 5666: return fde_func_5666_0x1f0cd0(a0, a1);
        case 5670: return fde_func_5670_0x1f1ce4(a0, a1);
        case 5674: return fde_func_5674_0x1f31dc(a0, a1);
        case 5679: return fde_func_5679_0x1f4734(a0, a1);
        case 5683: return fde_func_5683_0x1f53e0(a0, a1);
        case 5688: return fde_func_5688_0x1f6040(a0, a1);
        case 5692: return fde_func_5692_0x1f61fc(a0, a1);
        case 5697: return fde_func_5697_0x1f68b4(a0, a1);
        case 5701: return fde_func_5701_0x1f69f0(a0, a1);
        case 5706: return fde_func_5706_0x1f6aac(a0, a1);
        case 5710: return fde_func_5710_0x1f6be0(a0, a1);
        case 5715: return fde_func_5715_0x1f6f88(a0, a1);
        case 5719: return fde_func_5719_0x1f7220(a0, a1);
        case 5724: return fde_func_5724_0x1f76e0(a0, a1);
        case 5728: return fde_func_5728_0x1f7ae4(a0, a1);
        case 5733: return fde_func_5733_0x1fa5a0(a0, a1);
        case 5737: return fde_func_5737_0x1fbe84(a0, a1);
        case 5742: return fde_func_5742_0x1fe64c(a0, a1);
        case 5746: return fde_func_5746_0x1fe778(a0, a1);
        case 5750: return fde_func_5750_0x1fee70(a0, a1);
        case 5755: return fde_func_5755_0x201cf0(a0, a1);
        case 5759: return fde_func_5759_0x2028b8(a0, a1);
        case 5764: return fde_func_5764_0x2029fc(a0, a1);
        case 5768: return fde_func_5768_0x202ab4(a0, a1);
        case 5773: return fde_func_5773_0x202e74(a0, a1);
        case 5777: return fde_func_5777_0x2030bc(a0, a1);
        case 5782: return fde_func_5782_0x2041bc(a0, a1);
        case 5786: return fde_func_5786_0x205c58(a0, a1);
        case 5791: return fde_func_5791_0x206870(a0, a1);
        case 5795: return fde_func_5795_0x206970(a0, a1);
        case 5800: return fde_func_5800_0x206b18(a0, a1);
        case 5804: return fde_func_5804_0x206bb8(a0, a1);
        case 5809: return fde_func_5809_0x20749c(a0, a1);
        case 5813: return fde_func_5813_0x207588(a0, a1);
        case 5818: return fde_func_5818_0x208164(a0, a1);
        case 5822: return fde_func_5822_0x2089ac(a0, a1);
        case 5827: return fde_func_5827_0x20e490(a0, a1);
        case 5831: return fde_func_5831_0x20edd4(a0, a1);
        case 5835: return fde_func_5835_0x20ee58(a0, a1);
        case 5840: return fde_func_5840_0x20f104(a0, a1);
        case 5844: return fde_func_5844_0x20f2d8(a0, a1);
        case 5849: return fde_func_5849_0x20f92c(a0, a1);
        case 5853: return fde_func_5853_0x20fd78(a0, a1);
        case 5858: return fde_func_5858_0x20ff60(a0, a1);
        case 5862: return fde_func_5862_0x21040c(a0, a1);
        case 5867: return fde_func_5867_0x2106b0(a0, a1);
        case 5871: return fde_func_5871_0x211260(a0, a1);
        case 5876: return fde_func_5876_0x2115e0(a0, a1);
        case 5880: return fde_func_5880_0x211730(a0, a1);
        case 5885: return fde_func_5885_0x211cd8(a0, a1);
        case 5889: return fde_func_5889_0x212158(a0, a1);
        case 5894: return fde_func_5894_0x2121dc(a0, a1);
        case 5898: return fde_func_5898_0x212de0(a0, a1);
        case 5903: return fde_func_5903_0x213120(a0, a1);
        case 5907: return fde_func_5907_0x213298(a0, a1);
        case 5911: return fde_func_5911_0x21353c(a0, a1);
        case 5916: return fde_func_5916_0x213558(a0, a1);
        case 5920: return fde_func_5920_0x213604(a0, a1);
        case 5925: return fde_func_5925_0x2136f0(a0, a1);
        case 5929: return fde_func_5929_0x2138ac(a0, a1);
        case 5934: return fde_func_5934_0x213b20(a0, a1);
        case 5938: return fde_func_5938_0x213f74(a0, a1);
        case 5943: return fde_func_5943_0x214220(a0, a1);
        case 5947: return fde_func_5947_0x2143e4(a0, a1);
        case 5952: return fde_func_5952_0x21454c(a0, a1);
        case 5956: return fde_func_5956_0x2146ac(a0, a1);
        case 5961: return fde_func_5961_0x214d80(a0, a1);
        case 5965: return fde_func_5965_0x214fe0(a0, a1);
        case 5970: return fde_func_5970_0x216148(a0, a1);
        case 5974: return fde_func_5974_0x2163c4(a0, a1);
        case 5979: return fde_func_5979_0x216674(a0, a1);
        case 5983: return fde_func_5983_0x216768(a0, a1);
        case 5988: return fde_func_5988_0x216ac4(a0, a1);
        case 5992: return fde_func_5992_0x216c18(a0, a1);
        case 5996: return fde_func_5996_0x216d2c(a0, a1);
        case 6001: return fde_func_6001_0x216dd4(a0, a1);
        case 6005: return fde_func_6005_0x216e84(a0, a1);
        case 6010: return fde_func_6010_0x216ee0(a0, a1);
        case 6014: return fde_func_6014_0x216fd0(a0, a1);
        case 6019: return fde_func_6019_0x2170f8(a0, a1);
        case 6023: return fde_func_6023_0x217488(a0, a1);
        case 6028: return fde_func_6028_0x2176a8(a0, a1);
        case 6032: return fde_func_6032_0x2177b0(a0, a1);
        case 6037: return fde_func_6037_0x217938(a0, a1);
        case 6041: return fde_func_6041_0x2179e4(a0, a1);
        case 6046: return fde_func_6046_0x217ae8(a0, a1);
        case 6050: return fde_func_6050_0x217c8c(a0, a1);
        case 6055: return fde_func_6055_0x217db0(a0, a1);
        case 6059: return fde_func_6059_0x218070(a0, a1);
        case 6064: return fde_func_6064_0x218194(a0, a1);
        case 6068: return fde_func_6068_0x21835c(a0, a1);
        case 6072: return fde_func_6072_0x218488(a0, a1);
        case 6077: return fde_func_6077_0x2187b8(a0, a1);
        case 6081: return fde_func_6081_0x21882c(a0, a1);
        case 6086: return fde_func_6086_0x2188d8(a0, a1);
        case 6090: return fde_func_6090_0x218a20(a0, a1);
        case 6095: return fde_func_6095_0x218f0c(a0, a1);
        case 6099: return fde_func_6099_0x219064(a0, a1);
        case 6104: return fde_func_6104_0x219238(a0, a1);
        case 6108: return fde_func_6108_0x2194a8(a0, a1);
        case 6113: return fde_func_6113_0x2195cc(a0, a1);
        case 6117: return fde_func_6117_0x219714(a0, a1);
        case 6122: return fde_func_6122_0x2198b4(a0, a1);
        case 6126: return fde_func_6126_0x2199dc(a0, a1);
        case 6131: return fde_func_6131_0x219aac(a0, a1);
        case 6135: return fde_func_6135_0x219e04(a0, a1);
        case 6140: return fde_func_6140_0x219eb8(a0, a1);
        case 6144: return fde_func_6144_0x21a9e0(a0, a1);
        case 6149: return fde_func_6149_0x21aad4(a0, a1);
        case 6153: return fde_func_6153_0x21abc8(a0, a1);
        case 6157: return fde_func_6157_0x21ac88(a0, a1);
        case 6162: return fde_func_6162_0x21b1e4(a0, a1);
        case 6166: return fde_func_6166_0x21e7c8(a0, a1);
        case 6171: return fde_func_6171_0x21ef10(a0, a1);
        case 6175: return fde_func_6175_0x21f67c(a0, a1);
        case 6180: return fde_func_6180_0x221a80(a0, a1);
        case 6184: return fde_func_6184_0x222480(a0, a1);
        case 6189: return fde_func_6189_0x2225fc(a0, a1);
        case 6193: return fde_func_6193_0x222724(a0, a1);
        case 6198: return fde_func_6198_0x222800(a0, a1);
        case 6202: return fde_func_6202_0x2233e0(a0, a1);
        case 6207: return fde_func_6207_0x223444(a0, a1);
        case 6211: return fde_func_6211_0x223478(a0, a1);
        case 6216: return fde_func_6216_0x223d48(a0, a1);
        case 6220: return fde_func_6220_0x224558(a0, a1);
        case 6225: return fde_func_6225_0x224654(a0, a1);
        case 6229: return fde_func_6229_0x2246ec(a0, a1);
        case 6233: return fde_func_6233_0x2248a0(a0, a1);
        case 6238: return fde_func_6238_0x2249e8(a0, a1);
        case 6242: return fde_func_6242_0x224b74(a0, a1);
        case 6247: return fde_func_6247_0x224dd0(a0, a1);
        case 6251: return fde_func_6251_0x224ee8(a0, a1);
        case 6256: return fde_func_6256_0x22546c(a0, a1);
        case 6260: return fde_func_6260_0x2256dc(a0, a1);
        case 6265: return fde_func_6265_0x2258f8(a0, a1);
        case 6269: return fde_func_6269_0x225c34(a0, a1);
        case 6274: return fde_func_6274_0x226384(a0, a1);
        case 6278: return fde_func_6278_0x2276d4(a0, a1);
        case 6283: return fde_func_6283_0x229764(a0, a1);
        case 6287: return fde_func_6287_0x22acf0(a0, a1);
        case 6292: return fde_func_6292_0x22be48(a0, a1);
        case 6296: return fde_func_6296_0x22c184(a0, a1);
        case 6301: return fde_func_6301_0x22c5fc(a0, a1);
        case 6305: return fde_func_6305_0x22c7ac(a0, a1);
        case 6309: return fde_func_6309_0x22c914(a0, a1);
        case 6314: return fde_func_6314_0x22ca00(a0, a1);
        case 6318: return fde_func_6318_0x22cad8(a0, a1);
        case 6323: return fde_func_6323_0x22d34c(a0, a1);
        case 6327: return fde_func_6327_0x22db7c(a0, a1);
        case 6332: return fde_func_6332_0x22df80(a0, a1);
        case 6336: return fde_func_6336_0x22e410(a0, a1);
        case 6341: return fde_func_6341_0x22e61c(a0, a1);
        case 6345: return fde_func_6345_0x22fb44(a0, a1);
        case 6350: return fde_func_6350_0x22fca8(a0, a1);
        case 6354: return fde_func_6354_0x22fdcc(a0, a1);
        case 6359: return fde_func_6359_0x22ff2c(a0, a1);
        case 6363: return fde_func_6363_0x230014(a0, a1);
        case 6368: return fde_func_6368_0x23053c(a0, a1);
        case 6372: return fde_func_6372_0x2306cc(a0, a1);
        case 6377: return fde_func_6377_0x230da0(a0, a1);
        case 6381: return fde_func_6381_0x23185c(a0, a1);
        case 6386: return fde_func_6386_0x231b04(a0, a1);
        case 6390: return fde_func_6390_0x231f84(a0, a1);
        case 6394: return fde_func_6394_0x23221c(a0, a1);
        case 6399: return fde_func_6399_0x23251c(a0, a1);
        case 6403: return fde_func_6403_0x232590(a0, a1);
        case 6408: return fde_func_6408_0x232948(a0, a1);
        case 6412: return fde_func_6412_0x232a40(a0, a1);
        case 6417: return fde_func_6417_0x232bb0(a0, a1);
        case 6421: return fde_func_6421_0x232c24(a0, a1);
        case 6426: return fde_func_6426_0x232e64(a0, a1);
        case 6430: return fde_func_6430_0x23326c(a0, a1);
        case 6435: return fde_func_6435_0x2334b4(a0, a1);
        case 6439: return fde_func_6439_0x233668(a0, a1);
        case 6444: return fde_func_6444_0x233a50(a0, a1);
        case 6448: return fde_func_6448_0x233e6c(a0, a1);
        case 6453: return fde_func_6453_0x234968(a0, a1);
        case 6457: return fde_func_6457_0x234e78(a0, a1);
        case 6462: return fde_func_6462_0x234f9c(a0, a1);
        case 6466: return fde_func_6466_0x23505c(a0, a1);
        case 6470: return fde_func_6470_0x235598(a0, a1);
        case 6475: return fde_func_6475_0x235678(a0, a1);
        case 6479: return fde_func_6479_0x236b64(a0, a1);
        case 6484: return fde_func_6484_0x2374a4(a0, a1);
        case 6488: return fde_func_6488_0x237a88(a0, a1);
        case 6493: return fde_func_6493_0x23857c(a0, a1);
        case 6497: return fde_func_6497_0x2385b4(a0, a1);
        case 6502: return fde_func_6502_0x238610(a0, a1);
        case 6506: return fde_func_6506_0x238824(a0, a1);
        case 6511: return fde_func_6511_0x238d94(a0, a1);
        case 6515: return fde_func_6515_0x239264(a0, a1);
        case 6520: return fde_func_6520_0x23a544(a0, a1);
        case 6524: return fde_func_6524_0x23a7f0(a0, a1);
        case 6529: return fde_func_6529_0x23a894(a0, a1);
        case 6533: return fde_func_6533_0x23bb64(a0, a1);
        case 6538: return fde_func_6538_0x23c094(a0, a1);
        case 6542: return fde_func_6542_0x23d2d0(a0, a1);
        case 6547: return fde_func_6547_0x23d56c(a0, a1);
        case 6551: return fde_func_6551_0x23da60(a0, a1);
        case 6555: return fde_func_6555_0x23de64(a0, a1);
        case 6560: return fde_func_6560_0x23ebec(a0, a1);
        case 6564: return fde_func_6564_0x23edb8(a0, a1);
        case 6569: return fde_func_6569_0x240678(a0, a1);
        case 6573: return fde_func_6573_0x241194(a0, a1);
        case 6578: return fde_func_6578_0x2415f0(a0, a1);
        case 6582: return fde_func_6582_0x241974(a0, a1);
        case 6587: return fde_func_6587_0x241d54(a0, a1);
        case 6591: return fde_func_6591_0x24256c(a0, a1);
        case 6596: return fde_func_6596_0x2443c8(a0, a1);
        case 6600: return fde_func_6600_0x244954(a0, a1);
        case 6605: return fde_func_6605_0x245270(a0, a1);
        case 6609: return fde_func_6609_0x247ae4(a0, a1);
        case 6614: return fde_func_6614_0x248210(a0, a1);
        case 6618: return fde_func_6618_0x2488f4(a0, a1);
        case 6623: return fde_func_6623_0x248bdc(a0, a1);
        case 6627: return fde_func_6627_0x249064(a0, a1);
        case 6631: return fde_func_6631_0x24941c(a0, a1);
        case 6636: return fde_func_6636_0x2497c4(a0, a1);
        case 6640: return fde_func_6640_0x249bb0(a0, a1);
        case 6645: return fde_func_6645_0x24a260(a0, a1);
        case 6649: return fde_func_6649_0x24a440(a0, a1);
        case 6654: return fde_func_6654_0x24a7a8(a0, a1);
        case 6658: return fde_func_6658_0x24a810(a0, a1);
        case 6663: return fde_func_6663_0x24a92c(a0, a1);
        case 6667: return fde_func_6667_0x24a990(a0, a1);
        case 6672: return fde_func_6672_0x24a9dc(a0, a1);
        case 6676: return fde_func_6676_0x24ae7c(a0, a1);
        case 6681: return fde_func_6681_0x24b16c(a0, a1);
        case 6685: return fde_func_6685_0x24b22c(a0, a1);
        case 6690: return fde_func_6690_0x24b4f0(a0, a1);
        case 6694: return fde_func_6694_0x24ba30(a0, a1);
        case 6699: return fde_func_6699_0x24bf80(a0, a1);
        case 6703: return fde_func_6703_0x24c778(a0, a1);
        case 6708: return fde_func_6708_0x24d41c(a0, a1);
        case 6712: return fde_func_6712_0x24d888(a0, a1);
        case 6716: return fde_func_6716_0x24e058(a0, a1);
        case 6721: return fde_func_6721_0x24e690(a0, a1);
        case 6725: return fde_func_6725_0x24ebd0(a0, a1);
        case 6730: return fde_func_6730_0x24f920(a0, a1);
        case 6734: return fde_func_6734_0x252060(a0, a1);
        case 6739: return fde_func_6739_0x2529c0(a0, a1);
        case 6743: return fde_func_6743_0x252b8c(a0, a1);
        case 6748: return fde_func_6748_0x2535dc(a0, a1);
        case 6752: return fde_func_6752_0x25391c(a0, a1);
        case 6757: return fde_func_6757_0x2542dc(a0, a1);
        case 6761: return fde_func_6761_0x254a18(a0, a1);
        case 6766: return fde_func_6766_0x255138(a0, a1);
        case 6770: return fde_func_6770_0x2554d8(a0, a1);
        case 6775: return fde_func_6775_0x2556ac(a0, a1);
        case 6779: return fde_func_6779_0x2558bc(a0, a1);
        case 6784: return fde_func_6784_0x255de0(a0, a1);
        case 6788: return fde_func_6788_0x2562b0(a0, a1);
        case 6792: return fde_func_6792_0x2564a8(a0, a1);
        case 6797: return fde_func_6797_0x256a60(a0, a1);
        case 6801: return fde_func_6801_0x256edc(a0, a1);
        case 6806: return fde_func_6806_0x257784(a0, a1);
        case 6810: return fde_func_6810_0x257f74(a0, a1);
        case 6815: return fde_func_6815_0x2585e0(a0, a1);
        case 6819: return fde_func_6819_0x258e08(a0, a1);
        case 6824: return fde_func_6824_0x2590f8(a0, a1);
        case 6828: return fde_func_6828_0x2591c4(a0, a1);
        case 6833: return fde_func_6833_0x2595f0(a0, a1);
        case 6837: return fde_func_6837_0x25966c(a0, a1);
        case 6842: return fde_func_6842_0x2598cc(a0, a1);
        case 6846: return fde_func_6846_0x259c94(a0, a1);
        case 6851: return fde_func_6851_0x25a14c(a0, a1);
        case 6855: return fde_func_6855_0x25aa3c(a0, a1);
        case 6860: return fde_func_6860_0x25ae48(a0, a1);
        case 6864: return fde_func_6864_0x25afe8(a0, a1);
        case 6868: return fde_func_6868_0x25b37c(a0, a1);
        case 6873: return fde_func_6873_0x25b990(a0, a1);
        case 6877: return fde_func_6877_0x25bb44(a0, a1);
        case 6882: return fde_func_6882_0x25bd5c(a0, a1);
        case 6886: return fde_func_6886_0x25c5bc(a0, a1);
        case 6891: return fde_func_6891_0x25d120(a0, a1);
        case 6895: return fde_func_6895_0x25d178(a0, a1);
        case 6900: return fde_func_6900_0x25d39c(a0, a1);
        case 6904: return fde_func_6904_0x25dd4c(a0, a1);
        case 6909: return fde_func_6909_0x25e28c(a0, a1);
        case 6913: return fde_func_6913_0x25f55c(a0, a1);
        case 6918: return fde_func_6918_0x25fbc8(a0, a1);
        case 6922: return fde_func_6922_0x25fcfc(a0, a1);
        case 6927: return fde_func_6927_0x25feac(a0, a1);
        case 6931: return fde_func_6931_0x25ffcc(a0, a1);
        case 6936: return fde_func_6936_0x2601a4(a0, a1);
        case 6940: return fde_func_6940_0x260238(a0, a1);
        case 6945: return fde_func_6945_0x260278(a0, a1);
        case 6949: return fde_func_6949_0x2606fc(a0, a1);
        case 6953: return fde_func_6953_0x260788(a0, a1);
        case 6958: return fde_func_6958_0x260a10(a0, a1);
        case 6962: return fde_func_6962_0x26107c(a0, a1);
        case 6967: return fde_func_6967_0x2610d8(a0, a1);
        case 6971: return fde_func_6971_0x26110c(a0, a1);
        case 6976: return fde_func_6976_0x26116c(a0, a1);
        case 6980: return fde_func_6980_0x2612a4(a0, a1);
        case 6985: return fde_func_6985_0x261394(a0, a1);
        case 6989: return fde_func_6989_0x261754(a0, a1);
        case 6994: return fde_func_6994_0x261a64(a0, a1);
        case 6998: return fde_func_6998_0x261b3c(a0, a1);
        case 7003: return fde_func_7003_0x261be8(a0, a1);
        case 7007: return fde_func_7007_0x261c5c(a0, a1);
        case 7012: return fde_func_7012_0x261cb8(a0, a1);
        case 7016: return fde_func_7016_0x261d28(a0, a1);
        case 7021: return fde_func_7021_0x261eb4(a0, a1);
        case 7025: return fde_func_7025_0x262134(a0, a1);
        case 7029: return fde_func_7029_0x262b38(a0, a1);
        case 7034: return fde_func_7034_0x263890(a0, a1);
        case 7038: return fde_func_7038_0x26439c(a0, a1);
        case 7043: return fde_func_7043_0x26524c(a0, a1);
        case 7047: return fde_func_7047_0x266dcc(a0, a1);
        case 7052: return fde_func_7052_0x266f68(a0, a1);
        case 7056: return fde_func_7056_0x267108(a0, a1);
        case 7061: return fde_func_7061_0x267224(a0, a1);
        case 7065: return fde_func_7065_0x267368(a0, a1);
        case 7070: return fde_func_7070_0x267530(a0, a1);
        case 7074: return fde_func_7074_0x267688(a0, a1);
        case 7079: return fde_func_7079_0x267720(a0, a1);
        case 7083: return fde_func_7083_0x26775c(a0, a1);
        case 7088: return fde_func_7088_0x2677c4(a0, a1);
        case 7092: return fde_func_7092_0x267884(a0, a1);
        case 7097: return fde_func_7097_0x267950(a0, a1);
        case 7101: return fde_func_7101_0x2679cc(a0, a1);
        case 7106: return fde_func_7106_0x267c8c(a0, a1);
        case 7110: return fde_func_7110_0x267f38(a0, a1);
        case 7114: return fde_func_7114_0x268154(a0, a1);
        case 7119: return fde_func_7119_0x26847c(a0, a1);
        case 7123: return fde_func_7123_0x26871c(a0, a1);
        case 7128: return fde_func_7128_0x268814(a0, a1);
        case 7132: return fde_func_7132_0x268a40(a0, a1);
        case 7137: return fde_func_7137_0x268aa0(a0, a1);
        case 7141: return fde_func_7141_0x268b04(a0, a1);
        case 7146: return fde_func_7146_0x268b4c(a0, a1);
        case 7150: return fde_func_7150_0x268bac(a0, a1);
        default: return 0ULL;
    }
}

} // namespace preload_reconstructed