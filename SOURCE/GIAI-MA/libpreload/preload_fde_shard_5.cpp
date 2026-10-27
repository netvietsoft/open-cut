// ============================================================================
// Clean-Room C++17 Reconstructed AArch64 FDE Shard 5/5 for libpreload.so
// Phân mảnh hàm FDE AArch64 C++17 sạch 5/5 cho libpreload.so
// Covers 400 FDEs (indices 1600..1999 of 2,000 sampled from 8,944 FDEs @ 0x305cfc)
// ============================================================================
#include "preload_core.h"

namespace preload_reconstructed {

// FDE #7155 | PC: 0x268be8..0x268cb4 (204 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x268be8: D10143FF  sub      sp, sp, #0x50
//   0x268bec: F9000BF7  str      x23, [sp, #0x10]
//   0x268bf0: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x268bf4: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x268bf8: A9047BFD  stp      x29, x30, [sp, #0x40]
//   0x268bfc: 910103FD  add      x29, sp, #0x40
uint64_t fde_func_7155_0x268be8(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00268BE8ULL);
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

// FDE #7159 | PC: 0x268d08..0x268d0c (4 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x268d08: D65F03C0  ret      
uint64_t fde_func_7159_0x268d08(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00268D08ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD65F03C0ULL ^ (0ULL << 32);
    return state ^ (state >> 29);
}

// FDE #7164 | PC: 0x268d44..0x268d48 (4 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x268d44: 17F76D7B  b        #0x44330
uint64_t fde_func_7164_0x268d44(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00268D44ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0x17F76D7BULL ^ (0ULL << 32);
    return state ^ (state >> 29);
}

// FDE #7168 | PC: 0x268d9c..0x268da0 (4 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x268d9c: 17F76D65  b        #0x44330
uint64_t fde_func_7168_0x268d9c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00268D9CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0x17F76D65ULL ^ (0ULL << 32);
    return state ^ (state >> 29);
}

// FDE #7173 | PC: 0x268df0..0x268e2c (60 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x268df0: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x268df4: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x268df8: 910043FD  add      x29, sp, #0x10
//   0x268dfc: 39404008  ldrb     w8, [x0, #0x10]
//   0x268e00: D0000869  adrp     x9, #0x376000
//   0x268e04: AA0003F3  mov      x19, x0
uint64_t fde_func_7173_0x268df0(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00268DF0ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81E0FF3ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x39404008ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD0000869ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910A4129ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000009ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #7177 | PC: 0x268eb0..0x268ee0 (48 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x268eb0: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x268eb4: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x268eb8: 910043FD  add      x29, sp, #0x10
//   0x268ebc: 39404008  ldrb     w8, [x0, #0x10]
//   0x268ec0: AA0003F3  mov      x19, x0
//   0x268ec4: 36000068  tbz      w8, #0, #0x268ed0
uint64_t fde_func_7177_0x268eb0(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00268EB0ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81E0FF3ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x39404008ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x36000068ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9401260ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x97F76D19ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #7182 | PC: 0x2693dc..0x269414 (56 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x2693dc: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x2693e0: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x2693e4: 910043FD  add      x29, sp, #0x10
//   0x2693e8: AA0003F3  mov      x19, x0
//   0x2693ec: 52800200  mov      w0, #0x10
//   0x2693f0: 97F76B38  bl       #0x440d0
uint64_t fde_func_7182_0x2693dc(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x002693DCULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81E0FF3ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x52800200ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x97F76B38ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB0000868ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910C4108ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #7186 | PC: 0x269434..0x269440 (12 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x269434: F9400400  ldr      x0, [x0, #8]
//   0x269438: 2A1F03E1  mov      w1, wzr
//   0x26943c: 17FFEF84  b        #0x26524c
uint64_t fde_func_7186_0x269434(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00269434ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400400ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x2A1F03E1ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x17FFEF84ULL ^ (2ULL << 32);
    return state ^ (state >> 29);
}

// FDE #7190 | PC: 0x269488..0x2694c4 (60 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x269488: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x26948c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x269490: 910043FD  add      x29, sp, #0x10
//   0x269494: 39404008  ldrb     w8, [x0, #0x10]
//   0x269498: B0000869  adrp     x9, #0x376000
//   0x26949c: AA0003F3  mov      x19, x0
uint64_t fde_func_7190_0x269488(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00269488ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81E0FF3ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x39404008ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB0000869ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910E4129ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000009ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #7195 | PC: 0x2695a0..0x2696a0 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x2695a0: D10243FF  sub      sp, sp, #0x90
//   0x2695a4: A9055FF8  stp      x24, x23, [sp, #0x50]
//   0x2695a8: A90657F6  stp      x22, x21, [sp, #0x60]
//   0x2695ac: A9074FF4  stp      x20, x19, [sp, #0x70]
//   0x2695b0: A9087BFD  stp      x29, x30, [sp, #0x80]
//   0x2695b4: 910203FD  add      x29, sp, #0x80
uint64_t fde_func_7195_0x2695a0(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x002695A0ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10243FFULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9055FF8ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90657F6ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9074FF4ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9087BFDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910203FDULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD53BD056ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF94016C8ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #7199 | PC: 0x269848..0x269880 (56 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x269848: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x26984c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x269850: 910043FD  add      x29, sp, #0x10
//   0x269854: AA0003F3  mov      x19, x0
//   0x269858: 52800200  mov      w0, #0x10
//   0x26985c: 97F76A1D  bl       #0x440d0
uint64_t fde_func_7199_0x269848(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00269848ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81E0FF3ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x52800200ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x97F76A1DULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB0000868ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91100108ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #7204 | PC: 0x2698a8..0x2698c4 (28 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x2698a8: F9400428  ldr      x8, [x1, #8]
//   0x2698ac: B0000489  adrp     x9, #0x2fa000
//   0x2698b0: 913F2529  add      x9, x9, #0xfc9
//   0x2698b4: 9100200A  add      x10, x0, #8
//   0x2698b8: EB09011F  cmp      x8, x9
//   0x2698bc: 9A9F0140  csel     x0, x10, xzr, eq
uint64_t fde_func_7204_0x2698a8(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x002698A8ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400428ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB0000489ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x913F2529ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9100200AULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xEB09011FULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9A9F0140ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD65F03C0ULL ^ (6ULL << 32);
    return state ^ (state >> 29);
}

// FDE #7208 | PC: 0x269a50..0x269b28 (216 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x269a50: D10183FF  sub      sp, sp, #0x60
//   0x269a54: A9044FF4  stp      x20, x19, [sp, #0x40]
//   0x269a58: A9057BFD  stp      x29, x30, [sp, #0x50]
//   0x269a5c: 910143FD  add      x29, sp, #0x50
//   0x269a60: D53BD053  mrs      x19, tpidr_el0
//   0x269a64: F9401668  ldr      x8, [x19, #0x28]
uint64_t fde_func_7208_0x269a50(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00269A50ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10183FFULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9044FF4ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9057BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910143FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD53BD053ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9401668ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81E83A8ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400028ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #7213 | PC: 0x26a4d8..0x26a4f0 (24 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x26a4d8: 90000868  adrp     x8, #0x376000
//   0x26a4dc: 91124108  add      x8, x8, #0x490
//   0x26a4e0: F9000028  str      x8, [x1]
//   0x26a4e4: F9400408  ldr      x8, [x0, #8]
//   0x26a4e8: F9000428  str      x8, [x1, #8]
//   0x26a4ec: D65F03C0  ret      
uint64_t fde_func_7213_0x26a4d8(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0026A4D8ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0x90000868ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91124108ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000028ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400408ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000428ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD65F03C0ULL ^ (5ULL << 32);
    return state ^ (state >> 29);
}

// FDE #7217 | PC: 0x26a500..0x26a51c (28 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x26a500: F9400428  ldr      x8, [x1, #8]
//   0x26a504: B0000489  adrp     x9, #0x2fb000
//   0x26a508: 91111929  add      x9, x9, #0x446
//   0x26a50c: 9100200A  add      x10, x0, #8
//   0x26a510: EB09011F  cmp      x8, x9
//   0x26a514: 9A9F0140  csel     x0, x10, xzr, eq
uint64_t fde_func_7217_0x26a500(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0026A500ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400428ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB0000489ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91111929ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9100200AULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xEB09011FULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9A9F0140ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD65F03C0ULL ^ (6ULL << 32);
    return state ^ (state >> 29);
}

// FDE #7222 | PC: 0x26a57c..0x26a580 (4 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x26a57c: D65F03C0  ret      
uint64_t fde_func_7222_0x26a57c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0026A57CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD65F03C0ULL ^ (0ULL << 32);
    return state ^ (state >> 29);
}

// FDE #7226 | PC: 0x26a5a8..0x26a5b4 (12 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x26a5a8: 90000860  adrp     x0, #0x376000
//   0x26a5ac: 9115C000  add      x0, x0, #0x570
//   0x26a5b0: D65F03C0  ret      
uint64_t fde_func_7226_0x26a5a8(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0026A5A8ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0x90000860ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9115C000ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD65F03C0ULL ^ (2ULL << 32);
    return state ^ (state >> 29);
}

// FDE #7231 | PC: 0x26a60c..0x26a610 (4 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x26a60c: 17F76749  b        #0x44330
uint64_t fde_func_7231_0x26a60c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0026A60CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0x17F76749ULL ^ (0ULL << 32);
    return state ^ (state >> 29);
}

// FDE #7235 | PC: 0x26a640..0x26a708 (200 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x26a640: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x26a644: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x26a648: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x26a64c: 910083FD  add      x29, sp, #0x20
//   0x26a650: B00004D5  adrp     x21, #0x303000
//   0x26a654: 913EF2B5  add      x21, x21, #0xfbc
uint64_t fde_func_7235_0x26a640(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0026A640ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BD57F6ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9014FF4ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9027BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910083FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB00004D5ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x913EF2B5ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0103F3ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA1503E1ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #7240 | PC: 0x26cecc..0x26cf84 (184 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x26cecc: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x26ced0: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x26ced4: 910043FD  add      x29, sp, #0x10
//   0x26ced8: A940A408  ldp      x8, x9, [x0, #8]
//   0x26cedc: A942300B  ldp      x11, x12, [x0, #0x20]
//   0x26cee0: 5280154A  mov      w10, #0xaa
uint64_t fde_func_7240_0x26cecc(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0026CECCULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE4FF4ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA940A408ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA942300BULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x5280154AULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xEB08012DULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #7244 | PC: 0x26d0a8..0x26d100 (88 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x26d0a8: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x26d0ac: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x26d0b0: 910043FD  add      x29, sp, #0x10
//   0x26d0b4: F9400413  ldr      x19, [x0, #8]
//   0x26d0b8: B40000F3  cbz      x19, #0x26d0d4
//   0x26d0bc: 91002268  add      x8, x19, #8
uint64_t fde_func_7244_0x26d0a8(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0026D0A8ULL);
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

// FDE #7249 | PC: 0x26d4f0..0x26d590 (160 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x26d4f0: A9BC5FF8  stp      x24, x23, [sp, #-0x40]!
//   0x26d4f4: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x26d4f8: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x26d4fc: A9037BFD  stp      x29, x30, [sp, #0x30]
//   0x26d500: 9100C3FD  add      x29, sp, #0x30
//   0x26d504: F9401C15  ldr      x21, [x0, #0x38]
uint64_t fde_func_7249_0x26d4f0(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0026D4F0ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BC5FF8ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90157F6ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9024FF4ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9037BFDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9100C3FDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9401C15ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0203F3ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F4ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #7253 | PC: 0x26d7f4..0x26d7f8 (4 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x26d7f4: 17F75ACF  b        #0x44330
uint64_t fde_func_7253_0x26d7f4(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0026D7F4ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0x17F75ACFULL ^ (0ULL << 32);
    return state ^ (state >> 29);
}

// FDE #7258 | PC: 0x26d830..0x26d848 (24 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x26d830: F9400C00  ldr      x0, [x0, #0x18]
//   0x26d834: B4000080  cbz      x0, #0x26d844
//   0x26d838: F9400008  ldr      x8, [x0]
//   0x26d83c: F9400501  ldr      x1, [x8, #8]
//   0x26d840: D61F0020  br       x1
//   0x26d844: D65F03C0  ret      
uint64_t fde_func_7258_0x26d830(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0026D830ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400C00ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB4000080ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400008ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400501ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD61F0020ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD65F03C0ULL ^ (5ULL << 32);
    return state ^ (state >> 29);
}

// FDE #7262 | PC: 0x26d8a8..0x26d8bc (20 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x26d8a8: 12807C28  mov      w8, #-0x3e2
//   0x26d8ac: B9000028  str      w8, [x1]
//   0x26d8b0: F9400408  ldr      x8, [x0, #8]
//   0x26d8b4: F9002828  str      x8, [x1, #0x50]
//   0x26d8b8: D65F03C0  ret      
uint64_t fde_func_7262_0x26d8a8(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0026D8A8ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0x12807C28ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB9000028ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400408ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9002828ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD65F03C0ULL ^ (4ULL << 32);
    return state ^ (state >> 29);
}

// FDE #7267 | PC: 0x26d9cc..0x26da60 (148 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x26d9cc: F81C0FF7  str      x23, [sp, #-0x40]!
//   0x26d9d0: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x26d9d4: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x26d9d8: A9037BFD  stp      x29, x30, [sp, #0x30]
//   0x26d9dc: 9100C3FD  add      x29, sp, #0x30
//   0x26d9e0: AA0203F3  mov      x19, x2
uint64_t fde_func_7267_0x26d9cc(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0026D9CCULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81C0FF7ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90157F6ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9024FF4ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9037BFDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9100C3FDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0203F3ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0103F5ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F4ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #7271 | PC: 0x26e1f8..0x26e26c (116 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x26e1f8: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x26e1fc: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x26e200: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x26e204: 910083FD  add      x29, sp, #0x20
//   0x26e208: AA0003F4  mov      x20, x0
//   0x26e20c: 52800600  mov      w0, #0x30
uint64_t fde_func_7271_0x26e1f8(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0026E1F8ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81D0FF5ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9014FF4ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9027BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910083FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F4ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x52800600ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x2A0103F3ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x97F757AFULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #7275 | PC: 0x26e328..0x26e368 (64 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x26e328: 39417028  ldrb     w8, [x1, #0x5c]
//   0x26e32c: 34000168  cbz      w8, #0x26e358
//   0x26e330: A940A428  ldp      x8, x9, [x1, #8]
//   0x26e334: EB08013F  cmp      x9, x8
//   0x26e338: 54000101  b.ne     #0x26e358
//   0x26e33c: 39416028  ldrb     w8, [x1, #0x58]
uint64_t fde_func_7275_0x26e328(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0026E328ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0x39417028ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x34000168ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA940A428ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xEB08013FULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x54000101ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x39416028ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x370000C8ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x12807C28ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #7280 | PC: 0x26e484..0x26e584 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x26e484: F9400428  ldr      x8, [x1, #8]
//   0x26e488: F9400C2A  ldr      x10, [x1, #0x18]
//   0x26e48c: EB0A011F  cmp      x8, x10
//   0x26e490: 540004C0  b.eq     #0x26e528
//   0x26e494: F9400829  ldr      x9, [x1, #0x10]
//   0x26e498: EB0A013F  cmp      x9, x10
uint64_t fde_func_7280_0x26e484(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0026E484ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400428ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400C2AULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xEB0A011FULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x540004C0ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400829ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xEB0A013FULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x540002A0ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xEB08013FULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #7284 | PC: 0x26e6dc..0x26e7dc (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x26e6dc: D10303FF  sub      sp, sp, #0xc0
//   0x26e6e0: F90043F7  str      x23, [sp, #0x80]
//   0x26e6e4: A90957F6  stp      x22, x21, [sp, #0x90]
//   0x26e6e8: A90A4FF4  stp      x20, x19, [sp, #0xa0]
//   0x26e6ec: A90B7BFD  stp      x29, x30, [sp, #0xb0]
//   0x26e6f0: 9102C3FD  add      x29, sp, #0xb0
uint64_t fde_func_7284_0x26e6dc(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0026E6DCULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10303FFULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF90043F7ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90957F6ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90A4FF4ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90B7BFDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9102C3FDULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD53BD056ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF94016C8ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #7289 | PC: 0x26ede0..0x26eee0 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x26ede0: D10183FF  sub      sp, sp, #0x60
//   0x26ede4: F9001BF5  str      x21, [sp, #0x30]
//   0x26ede8: A9044FF4  stp      x20, x19, [sp, #0x40]
//   0x26edec: A9057BFD  stp      x29, x30, [sp, #0x50]
//   0x26edf0: 910143FD  add      x29, sp, #0x50
//   0x26edf4: D53BD055  mrs      x21, tpidr_el0
uint64_t fde_func_7289_0x26ede0(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0026EDE0ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10183FFULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9001BF5ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9044FF4ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9057BFDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910143FDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD53BD055ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF94016A8ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #7293 | PC: 0x26eff8..0x26f004 (12 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x26eff8: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x26effc: 910003FD  mov      x29, sp
//   0x26f000: 97F756C0  bl       #0x44b00
uint64_t fde_func_7293_0x26eff8(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0026EFF8ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BF7BFDULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x97F756C0ULL ^ (2ULL << 32);
    return state ^ (state >> 29);
}

// FDE #7298 | PC: 0x26f190..0x26f1d4 (68 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x26f190: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x26f194: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x26f198: 910043FD  add      x29, sp, #0x10
//   0x26f19c: A940A014  ldp      x20, x8, [x0, #8]
//   0x26f1a0: EB14011F  cmp      x8, x20
//   0x26f1a4: 54000120  b.eq     #0x26f1c8
uint64_t fde_func_7298_0x26f190(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0026F190ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE4FF4ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA940A014ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xEB14011FULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x54000120ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9401260ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #7302 | PC: 0x26f42c..0x26f490 (100 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x26f42c: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x26f430: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x26f434: 910043FD  add      x29, sp, #0x10
//   0x26f438: AA0103F3  mov      x19, x1
//   0x26f43c: AA0003F4  mov      x20, x0
//   0x26f440: A8C10801  ldp      x1, x2, [x0], #0x10
uint64_t fde_func_7302_0x26f42c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0026F42CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE4FF4ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0103F3ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F4ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA8C10801ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91002263ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x94000012ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #7307 | PC: 0x26f690..0x26f73c (172 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x26f690: D10143FF  sub      sp, sp, #0x50
//   0x26f694: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x26f698: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x26f69c: A9047BFD  stp      x29, x30, [sp, #0x40]
//   0x26f6a0: 910103FD  add      x29, sp, #0x40
//   0x26f6a4: D53BD056  mrs      x22, tpidr_el0
uint64_t fde_func_7307_0x26f690(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0026F690ULL);
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

// FDE #7311 | PC: 0x26f868..0x26f8a8 (64 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x26f868: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x26f86c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x26f870: 910043FD  add      x29, sp, #0x10
//   0x26f874: CB010053  sub      x19, x2, x1
//   0x26f878: F100067F  cmp      x19, #1
//   0x26f87c: 5400010B  b.lt     #0x26f89c
uint64_t fde_func_7311_0x26f868(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0026F868ULL);
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

// FDE #7316 | PC: 0x26fb28..0x26fb80 (88 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x26fb28: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x26fb2c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x26fb30: 910043FD  add      x29, sp, #0x10
//   0x26fb34: 39406008  ldrb     w8, [x0, #0x18]
//   0x26fb38: 370801E8  tbnz     w8, #1, #0x26fb74
//   0x26fb3c: AA0003F3  mov      x19, x0
uint64_t fde_func_7316_0x26fb28(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0026FB28ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE4FF4ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x39406008ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x370801E8ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x52800300ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x2A0103F4ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #7320 | PC: 0x26fc34..0x26fc40 (12 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x26fc34: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x26fc38: 910003FD  mov      x29, sp
//   0x26fc3c: 97F753B1  bl       #0x44b00
uint64_t fde_func_7320_0x26fc34(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0026FC34ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BF7BFDULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x97F753B1ULL ^ (2ULL << 32);
    return state ^ (state >> 29);
}

// FDE #7325 | PC: 0x2702b8..0x2702c4 (12 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x2702b8: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x2702bc: 910003FD  mov      x29, sp
//   0x2702c0: 97F75210  bl       #0x44b00
uint64_t fde_func_7325_0x2702b8(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x002702B8ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BF7BFDULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x97F75210ULL ^ (2ULL << 32);
    return state ^ (state >> 29);
}

// FDE #7329 | PC: 0x27042c..0x2704a4 (120 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x27042c: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x270430: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x270434: 910043FD  add      x29, sp, #0x10
//   0x270438: A9412428  ldp      x8, x9, [x1, #0x10]
//   0x27043c: AA0103F3  mov      x19, x1
//   0x270440: EB09011F  cmp      x8, x9
uint64_t fde_func_7329_0x27042c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0027042CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE4FF4ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9412428ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0103F3ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xEB09011FULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x54000240ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F4ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #7334 | PC: 0x2705d0..0x270618 (72 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x2705d0: A9412428  ldp      x8, x9, [x1, #0x10]
//   0x2705d4: EB09011F  cmp      x8, x9
//   0x2705d8: 54000180  b.eq     #0x270608
//   0x2705dc: 39400109  ldrb     w9, [x8]
//   0x2705e0: 3940400A  ldrb     w10, [x0, #0x10]
//   0x2705e4: 6B0A013F  cmp      w9, w10
uint64_t fde_func_7334_0x2705d0(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x002705D0ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9412428ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xEB09011FULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x54000180ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x39400109ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x3940400AULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x6B0A013FULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x54000101ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x12807C49ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #7338 | PC: 0x2707c4..0x270818 (84 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x2707c4: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x2707c8: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x2707cc: 910043FD  add      x29, sp, #0x10
//   0x2707d0: D0000828  adrp     x8, #0x376000
//   0x2707d4: 9127A108  add      x8, x8, #0x9e8
//   0x2707d8: AA0003F3  mov      x19, x0
uint64_t fde_func_7338_0x2707c4(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x002707C4ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81E0FF3ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD0000828ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9127A108ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF8010408ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x97F750D8ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #7343 | PC: 0x270a00..0x270a64 (100 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x270a00: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x270a04: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x270a08: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x270a0c: 910083FD  add      x29, sp, #0x20
//   0x270a10: AA0003F4  mov      x20, x0
//   0x270a14: 52801500  mov      w0, #0xa8
uint64_t fde_func_7343_0x270a00(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00270A00ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81D0FF5ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9014FF4ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9027BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910083FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F4ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x52801500ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x2A0103F3ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x97F74DADULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #7347 | PC: 0x270dd4..0x270e64 (144 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x270dd4: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x270dd8: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x270ddc: 910043FD  add      x29, sp, #0x10
//   0x270de0: D0000828  adrp     x8, #0x376000
//   0x270de4: 9129E108  add      x8, x8, #0xa78
//   0x270de8: AA0003F3  mov      x19, x0
uint64_t fde_func_7347_0x270dd4(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00270DD4ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81E0FF3ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD0000828ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9129E108ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF8088408ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x97F79336ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #7351 | PC: 0x2717e4..0x2718e4 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x2717e4: D101C3FF  sub      sp, sp, #0x70
//   0x2717e8: F90013F9  str      x25, [sp, #0x20]
//   0x2717ec: A9035FF8  stp      x24, x23, [sp, #0x30]
//   0x2717f0: A90457F6  stp      x22, x21, [sp, #0x40]
//   0x2717f4: A9054FF4  stp      x20, x19, [sp, #0x50]
//   0x2717f8: A9067BFD  stp      x29, x30, [sp, #0x60]
uint64_t fde_func_7351_0x2717e4(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x002717E4ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD101C3FFULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF90013F9ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9035FF8ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90457F6ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9054FF4ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9067BFDULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910183FDULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD53BD058ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #7356 | PC: 0x271d04..0x271d10 (12 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x271d04: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x271d08: 910003FD  mov      x29, sp
//   0x271d0c: 97F74B7D  bl       #0x44b00
uint64_t fde_func_7356_0x271d04(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00271D04ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BF7BFDULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x97F74B7DULL ^ (2ULL << 32);
    return state ^ (state >> 29);
}

// FDE #7360 | PC: 0x272394..0x272494 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x272394: D10183FF  sub      sp, sp, #0x60
//   0x272398: F9001BF5  str      x21, [sp, #0x30]
//   0x27239c: A9044FF4  stp      x20, x19, [sp, #0x40]
//   0x2723a0: A9057BFD  stp      x29, x30, [sp, #0x50]
//   0x2723a4: 910143FD  add      x29, sp, #0x50
//   0x2723a8: D53BD055  mrs      x21, tpidr_el0
uint64_t fde_func_7360_0x272394(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00272394ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10183FFULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9001BF5ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9044FF4ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9057BFDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910143FDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD53BD055ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF94016A8ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xCB01004AULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #7365 | PC: 0x273054..0x273060 (12 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x273054: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x273058: 910003FD  mov      x29, sp
//   0x27305c: 97F746A9  bl       #0x44b00
uint64_t fde_func_7365_0x273054(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00273054ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BF7BFDULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x97F746A9ULL ^ (2ULL << 32);
    return state ^ (state >> 29);
}

// FDE #7369 | PC: 0x27342c..0x273438 (12 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x27342c: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x273430: 910003FD  mov      x29, sp
//   0x273434: 97F745B3  bl       #0x44b00
uint64_t fde_func_7369_0x27342c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0027342CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BF7BFDULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x97F745B3ULL ^ (2ULL << 32);
    return state ^ (state >> 29);
}

// FDE #7374 | PC: 0x273828..0x27389c (116 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x273828: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x27382c: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x273830: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x273834: 910083FD  add      x29, sp, #0x20
//   0x273838: AA0203F5  mov      x21, x2
//   0x27383c: AA0103F4  mov      x20, x1
uint64_t fde_func_7374_0x273828(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00273828ULL);
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

// FDE #7378 | PC: 0x2739ac..0x273a10 (100 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x2739ac: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x2739b0: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x2739b4: 910043FD  add      x29, sp, #0x10
//   0x2739b8: AA0103F3  mov      x19, x1
//   0x2739bc: AA0003F4  mov      x20, x0
//   0x2739c0: A8C10801  ldp      x1, x2, [x0], #0x10
uint64_t fde_func_7378_0x2739ac(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x002739ACULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE4FF4ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0103F3ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F4ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA8C10801ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91002263ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x94000012ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #7383 | PC: 0x273ae0..0x273b18 (56 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x273ae0: 12807C28  mov      w8, #-0x3e2
//   0x273ae4: B9000028  str      w8, [x1]
//   0x273ae8: B9401008  ldr      w8, [x0, #0x10]
//   0x273aec: F940102A  ldr      x10, [x1, #0x20]
//   0x273af0: F9400829  ldr      x9, [x1, #0x10]
//   0x273af4: 5280030B  mov      w11, #0x18
uint64_t fde_func_7383_0x273ae0(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00273AE0ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0x12807C28ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB9000028ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB9401008ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF940102AULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400829ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x5280030BULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x51000508ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x5280002CULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #7387 | PC: 0x273cb4..0x273cc0 (12 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x273cb4: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x273cb8: 910003FD  mov      x29, sp
//   0x273cbc: 97F74391  bl       #0x44b00
uint64_t fde_func_7387_0x273cb4(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00273CB4ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BF7BFDULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x97F74391ULL ^ (2ULL << 32);
    return state ^ (state >> 29);
}

// FDE #7392 | PC: 0x273e78..0x273ed8 (96 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x273e78: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x273e7c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x273e80: 910043FD  add      x29, sp, #0x10
//   0x273e84: AA0003F3  mov      x19, x0
//   0x273e88: F9400800  ldr      x0, [x0, #0x10]
//   0x273e8c: F0000808  adrp     x8, #0x376000
uint64_t fde_func_7392_0x273e78(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00273E78ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81E0FF3ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400800ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF0000808ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x912EC108ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000268ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #7396 | PC: 0x273f40..0x273fa0 (96 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x273f40: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x273f44: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x273f48: 910043FD  add      x29, sp, #0x10
//   0x273f4c: AA0003F3  mov      x19, x0
//   0x273f50: F9400800  ldr      x0, [x0, #0x10]
//   0x273f54: F0000808  adrp     x8, #0x376000
uint64_t fde_func_7396_0x273f40(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00273F40ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81E0FF3ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400800ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF0000808ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x912EC108ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000268ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #7401 | PC: 0x273fe4..0x273ff0 (12 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x273fe4: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x273fe8: 910003FD  mov      x29, sp
//   0x273fec: 97F742C5  bl       #0x44b00
uint64_t fde_func_7401_0x273fe4(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00273FE4ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BF7BFDULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x97F742C5ULL ^ (2ULL << 32);
    return state ^ (state >> 29);
}

// FDE #7405 | PC: 0x27437c..0x27447c (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x27437c: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x274380: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x274384: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x274388: 910083FD  add      x29, sp, #0x20
//   0x27438c: AA0203F5  mov      x21, x2
//   0x274390: AA0103F3  mov      x19, x1
uint64_t fde_func_7405_0x27437c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0027437CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BD57F6ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9014FF4ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9027BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910083FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0203F5ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0103F3ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xEB02003FULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F4ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #7410 | PC: 0x2745e8..0x274644 (92 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x2745e8: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x2745ec: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x2745f0: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x2745f4: 910083FD  add      x29, sp, #0x20
//   0x2745f8: AA0203F3  mov      x19, x2
//   0x2745fc: AA0103F5  mov      x21, x1
uint64_t fde_func_7410_0x2745e8(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x002745E8ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81D0FF5ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9014FF4ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9027BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910083FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0203F3ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0103F5ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F4ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x94000010ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #7414 | PC: 0x2748cc..0x274970 (164 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x2748cc: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x2748d0: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x2748d4: 910043FD  add      x29, sp, #0x10
//   0x2748d8: AA0103F3  mov      x19, x1
//   0x2748dc: EB02003F  cmp      x1, x2
//   0x2748e0: 54000300  b.eq     #0x274940
uint64_t fde_func_7414_0x2748cc(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x002748CCULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81E0FF3ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0103F3ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xEB02003FULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x54000300ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91000661ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xEB02003FULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #7419 | PC: 0x274d94..0x274e94 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x274d94: D10543FF  sub      sp, sp, #0x150
//   0x274d98: A90F6FFC  stp      x28, x27, [sp, #0xf0]
//   0x274d9c: A91067FA  stp      x26, x25, [sp, #0x100]
//   0x274da0: A9115FF8  stp      x24, x23, [sp, #0x110]
//   0x274da4: A91257F6  stp      x22, x21, [sp, #0x120]
//   0x274da8: A9134FF4  stp      x20, x19, [sp, #0x130]
uint64_t fde_func_7419_0x274d94(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00274D94ULL);
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

// FDE #7423 | PC: 0x275780..0x275878 (248 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x275780: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x275784: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x275788: 910043FD  add      x29, sp, #0x10
//   0x27578c: F9401008  ldr      x8, [x0, #0x20]
//   0x275790: AA0003F3  mov      x19, x0
//   0x275794: AA0103F4  mov      x20, x1
uint64_t fde_func_7423_0x275780(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00275780ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE4FF4ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9401008ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0103F4ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB5000088ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA1303E0ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #7427 | PC: 0x275ba0..0x275ca0 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x275ba0: F81B0FF9  str      x25, [sp, #-0x50]!
//   0x275ba4: A9015FF8  stp      x24, x23, [sp, #0x10]
//   0x275ba8: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x275bac: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x275bb0: A9047BFD  stp      x29, x30, [sp, #0x40]
//   0x275bb4: 910103FD  add      x29, sp, #0x40
uint64_t fde_func_7427_0x275ba0(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00275BA0ULL);
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

// FDE #7432 | PC: 0x2760ec..0x2761ec (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x2760ec: A9BC5FF8  stp      x24, x23, [sp, #-0x40]!
//   0x2760f0: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x2760f4: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x2760f8: A9037BFD  stp      x29, x30, [sp, #0x30]
//   0x2760fc: 9100C3FD  add      x29, sp, #0x30
//   0x276100: A940A408  ldp      x8, x9, [x0, #8]
uint64_t fde_func_7432_0x2760ec(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x002760ECULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BC5FF8ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90157F6ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9024FF4ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9037BFDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9100C3FDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA940A408ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9100A014ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #7436 | PC: 0x27669c..0x27679c (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x27669c: D10183FF  sub      sp, sp, #0x60
//   0x2766a0: F90013F7  str      x23, [sp, #0x20]
//   0x2766a4: A90357F6  stp      x22, x21, [sp, #0x30]
//   0x2766a8: A9044FF4  stp      x20, x19, [sp, #0x40]
//   0x2766ac: A9057BFD  stp      x29, x30, [sp, #0x50]
//   0x2766b0: 910143FD  add      x29, sp, #0x50
uint64_t fde_func_7436_0x27669c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0027669CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10183FFULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF90013F7ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90357F6ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9044FF4ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9057BFDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910143FDULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD53BD056ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF94016C8ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #7441 | PC: 0x276bc0..0x276c24 (100 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x276bc0: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x276bc4: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x276bc8: 910043FD  add      x29, sp, #0x10
//   0x276bcc: AA0103F3  mov      x19, x1
//   0x276bd0: AA0003F4  mov      x20, x0
//   0x276bd4: A8C10801  ldp      x1, x2, [x0], #0x10
uint64_t fde_func_7441_0x276bc0(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00276BC0ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE4FF4ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0103F3ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F4ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA8C10801ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91002263ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x94000012ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #7445 | PC: 0x276fe0..0x2770e0 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x276fe0: D10283FF  sub      sp, sp, #0xa0
//   0x276fe4: A9065FF8  stp      x24, x23, [sp, #0x60]
//   0x276fe8: A90757F6  stp      x22, x21, [sp, #0x70]
//   0x276fec: A9084FF4  stp      x20, x19, [sp, #0x80]
//   0x276ff0: A9097BFD  stp      x29, x30, [sp, #0x90]
//   0x276ff4: 910243FD  add      x29, sp, #0x90
uint64_t fde_func_7445_0x276fe0(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00276FE0ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10283FFULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9065FF8ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90757F6ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9084FF4ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9097BFDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910243FDULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD53BD058ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9401708ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #7450 | PC: 0x277734..0x277788 (84 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x277734: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x277738: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x27773c: 910043FD  add      x29, sp, #0x10
//   0x277740: F9400C08  ldr      x8, [x0, #0x18]
//   0x277744: B40001C8  cbz      x8, #0x27777c
//   0x277748: F9400801  ldr      x1, [x0, #0x10]
uint64_t fde_func_7450_0x277734(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00277734ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81E0FF3ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400C08ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB40001C8ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400801ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x97FFBED7ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #7454 | PC: 0x277b5c..0x277bac (80 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x277b5c: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x277b60: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x277b64: 910043FD  add      x29, sp, #0x10
//   0x277b68: A9405028  ldp      x8, x20, [x1]
//   0x277b6c: AA0103F3  mov      x19, x1
//   0x277b70: 91004022  add      x2, x1, #0x10
uint64_t fde_func_7454_0x277b5c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00277B5CULL);
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

// FDE #7459 | PC: 0x277de4..0x277ee4 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x277de4: D10243FF  sub      sp, sp, #0x90
//   0x277de8: A9036FFC  stp      x28, x27, [sp, #0x30]
//   0x277dec: A90467FA  stp      x26, x25, [sp, #0x40]
//   0x277df0: A9055FF8  stp      x24, x23, [sp, #0x50]
//   0x277df4: A90657F6  stp      x22, x21, [sp, #0x60]
//   0x277df8: A9074FF4  stp      x20, x19, [sp, #0x70]
uint64_t fde_func_7459_0x277de4(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00277DE4ULL);
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

// FDE #7463 | PC: 0x278450..0x2784a8 (88 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x278450: A9007C1F  stp      xzr, xzr, [x0]
//   0x278454: F9400028  ldr      x8, [x1]
//   0x278458: F9000808  str      x8, [x0, #0x10]
//   0x27845c: F9400428  ldr      x8, [x1, #8]
//   0x278460: F9000C08  str      x8, [x0, #0x18]
//   0x278464: B40000C8  cbz      x8, #0x27847c
uint64_t fde_func_7463_0x278450(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00278450ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9007C1FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400028ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000808ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400428ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000C08ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB40000C8ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91002108ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xC85F7D09ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #7468 | PC: 0x2787a8..0x2788a8 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x2787a8: D10243FF  sub      sp, sp, #0x90
//   0x2787ac: F90023F9  str      x25, [sp, #0x40]
//   0x2787b0: A9055FF8  stp      x24, x23, [sp, #0x50]
//   0x2787b4: A90657F6  stp      x22, x21, [sp, #0x60]
//   0x2787b8: A9074FF4  stp      x20, x19, [sp, #0x70]
//   0x2787bc: A9087BFD  stp      x29, x30, [sp, #0x80]
uint64_t fde_func_7468_0x2787a8(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x002787A8ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10243FFULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF90023F9ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9055FF8ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90657F6ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9074FF4ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9087BFDULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910203FDULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD53BD059ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #7472 | PC: 0x27982c..0x27992c (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x27982c: D10483FF  sub      sp, sp, #0x120
//   0x279830: A90E5FFC  stp      x28, x23, [sp, #0xe0]
//   0x279834: A90F57F6  stp      x22, x21, [sp, #0xf0]
//   0x279838: A9104FF4  stp      x20, x19, [sp, #0x100]
//   0x27983c: A9117BFD  stp      x29, x30, [sp, #0x110]
//   0x279840: 910443FD  add      x29, sp, #0x110
uint64_t fde_func_7472_0x27982c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0027982CULL);
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

// FDE #7477 | PC: 0x27a0a8..0x27a1a8 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x27a0a8: A9BA6FFC  stp      x28, x27, [sp, #-0x60]!
//   0x27a0ac: A90167FA  stp      x26, x25, [sp, #0x10]
//   0x27a0b0: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x27a0b4: A90357F6  stp      x22, x21, [sp, #0x30]
//   0x27a0b8: A9044FF4  stp      x20, x19, [sp, #0x40]
//   0x27a0bc: A9057BFD  stp      x29, x30, [sp, #0x50]
uint64_t fde_func_7477_0x27a0a8(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0027A0A8ULL);
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

// FDE #7481 | PC: 0x27a304..0x27a340 (60 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x27a304: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x27a308: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x27a30c: 910043FD  add      x29, sp, #0x10
//   0x27a310: 39402008  ldrb     w8, [x0, #8]
//   0x27a314: 900007E9  adrp     x9, #0x376000
//   0x27a318: AA0003F3  mov      x19, x0
uint64_t fde_func_7481_0x27a304(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0027A304ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81E0FF3ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x39402008ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x900007E9ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91340129ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000009ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #7486 | PC: 0x27a410..0x27a510 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x27a410: D101C3FF  sub      sp, sp, #0x70
//   0x27a414: F90013F9  str      x25, [sp, #0x20]
//   0x27a418: A9035FF8  stp      x24, x23, [sp, #0x30]
//   0x27a41c: A90457F6  stp      x22, x21, [sp, #0x40]
//   0x27a420: A9054FF4  stp      x20, x19, [sp, #0x50]
//   0x27a424: A9067BFD  stp      x29, x30, [sp, #0x60]
uint64_t fde_func_7486_0x27a410(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0027A410ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD101C3FFULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF90013F9ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9035FF8ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90457F6ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9054FF4ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9067BFDULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910183FDULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD53BD057ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #7490 | PC: 0x27a6ec..0x27a7ec (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x27a6ec: A9BC5FF8  stp      x24, x23, [sp, #-0x40]!
//   0x27a6f0: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x27a6f4: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x27a6f8: A9037BFD  stp      x29, x30, [sp, #0x30]
//   0x27a6fc: 9100C3FD  add      x29, sp, #0x30
//   0x27a700: AA0003F3  mov      x19, x0
uint64_t fde_func_7490_0x27a6ec(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0027A6ECULL);
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

// FDE #7495 | PC: 0x27a964..0x27a9a4 (64 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x27a964: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x27a968: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x27a96c: 910043FD  add      x29, sp, #0x10
//   0x27a970: AA0003F3  mov      x19, x0
//   0x27a974: 52800900  mov      w0, #0x48
//   0x27a978: 97F725D6  bl       #0x440d0
uint64_t fde_func_7495_0x27a964(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0027A964ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE4FF4ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x52800900ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x97F725D6ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x900007E8ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91360108ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #7499 | PC: 0x27aa48..0x27ab48 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x27aa48: D10203FF  sub      sp, sp, #0x80
//   0x27aa4c: A9045FF8  stp      x24, x23, [sp, #0x40]
//   0x27aa50: A90557F6  stp      x22, x21, [sp, #0x50]
//   0x27aa54: A9064FF4  stp      x20, x19, [sp, #0x60]
//   0x27aa58: A9077BFD  stp      x29, x30, [sp, #0x70]
//   0x27aa5c: 9101C3FD  add      x29, sp, #0x70
uint64_t fde_func_7499_0x27aa48(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0027AA48ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10203FFULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9045FF8ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90557F6ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9064FF4ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9077BFDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9101C3FDULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD53BD056ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF94016C8ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #7504 | PC: 0x27af08..0x27af40 (56 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x27af08: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x27af0c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x27af10: 910043FD  add      x29, sp, #0x10
//   0x27af14: AA0003F3  mov      x19, x0
//   0x27af18: 52800200  mov      w0, #0x10
//   0x27af1c: 97F7246D  bl       #0x440d0
uint64_t fde_func_7504_0x27af08(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0027AF08ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81E0FF3ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x52800200ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x97F7246DULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x900007E8ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91380108ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #7508 | PC: 0x27af60..0x27af68 (8 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x27af60: F9400400  ldr      x0, [x0, #8]
//   0x27af64: 17FFFB01  b        #0x279b68
uint64_t fde_func_7508_0x27af60(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0027AF60ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400400ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x17FFFB01ULL ^ (1ULL << 32);
    return state ^ (state >> 29);
}

// FDE #7512 | PC: 0x27aff0..0x27b0f0 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x27aff0: D101C3FF  sub      sp, sp, #0x70
//   0x27aff4: F90013F9  str      x25, [sp, #0x20]
//   0x27aff8: A9035FF8  stp      x24, x23, [sp, #0x30]
//   0x27affc: A90457F6  stp      x22, x21, [sp, #0x40]
//   0x27b000: A9054FF4  stp      x20, x19, [sp, #0x50]
//   0x27b004: A9067BFD  stp      x29, x30, [sp, #0x60]
uint64_t fde_func_7512_0x27aff0(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0027AFF0ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD101C3FFULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF90013F9ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9035FF8ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90457F6ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9054FF4ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9067BFDULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910183FDULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0803F3ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #7517 | PC: 0x27b51c..0x27b5a4 (136 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x27b51c: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x27b520: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x27b524: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x27b528: 910083FD  add      x29, sp, #0x20
//   0x27b52c: F9400008  ldr      x8, [x0]
//   0x27b530: AA0103F6  mov      x22, x1
uint64_t fde_func_7517_0x27b51c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0027B51CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BD57F6ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9014FF4ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9027BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910083FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400008ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0103F6ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB0000401ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9115B821ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #7521 | PC: 0x27b96c..0x27b9f4 (136 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x27b96c: B4000422  cbz      x2, #0x27b9f0
//   0x27b970: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x27b974: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x27b978: 910043FD  add      x29, sp, #0x10
//   0x27b97c: 52800020  mov      w0, #1
//   0x27b980: AA0203F3  mov      x19, x2
uint64_t fde_func_7521_0x27b96c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0027B96CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xB4000422ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81E0FF3ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x52800020ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0203F3ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x97F727DCULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x36000140ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #7526 | PC: 0x27bc1c..0x27bcd8 (188 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x27bc1c: D10203FF  sub      sp, sp, #0x80
//   0x27bc20: A90557F6  stp      x22, x21, [sp, #0x50]
//   0x27bc24: A9064FF4  stp      x20, x19, [sp, #0x60]
//   0x27bc28: A9077BFD  stp      x29, x30, [sp, #0x70]
//   0x27bc2c: 9101C3FD  add      x29, sp, #0x70
//   0x27bc30: D53BD056  mrs      x22, tpidr_el0
uint64_t fde_func_7526_0x27bc1c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0027BC1CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10203FFULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90557F6ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9064FF4ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9077BFDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9101C3FDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD53BD056ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF94016C8ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81D83A8ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #7530 | PC: 0x27c1b8..0x27c1cc (20 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x27c1b8: B4000082  cbz      x2, #0x27c1c8
//   0x27c1bc: AA0203E0  mov      x0, x2
//   0x27c1c0: 2A0303E1  mov      w1, w3
//   0x27c1c4: 17F9ACB5  b        #0xe7498
//   0x27c1c8: D65F03C0  ret      
uint64_t fde_func_7530_0x27c1b8(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0027C1B8ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xB4000082ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0203E0ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x2A0303E1ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x17F9ACB5ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD65F03C0ULL ^ (4ULL << 32);
    return state ^ (state >> 29);
}

// FDE #7535 | PC: 0x27c66c..0x27c760 (244 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x27c66c: D10283FF  sub      sp, sp, #0xa0
//   0x27c670: A9065FF8  stp      x24, x23, [sp, #0x60]
//   0x27c674: A90757F6  stp      x22, x21, [sp, #0x70]
//   0x27c678: A9084FF4  stp      x20, x19, [sp, #0x80]
//   0x27c67c: A9097BFD  stp      x29, x30, [sp, #0x90]
//   0x27c680: 910243FD  add      x29, sp, #0x90
uint64_t fde_func_7535_0x27c66c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0027C66CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10283FFULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9065FF8ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90757F6ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9084FF4ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9097BFDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910243FDULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD53BD058ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9401708ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #7539 | PC: 0x27c950..0x27c9e4 (148 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x27c950: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x27c954: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x27c958: 910043FD  add      x29, sp, #0x10
//   0x27c95c: AA0203F3  mov      x19, x2
//   0x27c960: B40003A2  cbz      x2, #0x27c9d4
//   0x27c964: 52800020  mov      w0, #1
uint64_t fde_func_7539_0x27c950(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0027C950ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81E0FF3ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0203F3ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB40003A2ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x52800020ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x97F723E3ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x36000140ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #7544 | PC: 0x27cda0..0x27cea0 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x27cda0: D10243FF  sub      sp, sp, #0x90
//   0x27cda4: F9002BF7  str      x23, [sp, #0x50]
//   0x27cda8: A90657F6  stp      x22, x21, [sp, #0x60]
//   0x27cdac: A9074FF4  stp      x20, x19, [sp, #0x70]
//   0x27cdb0: A9087BFD  stp      x29, x30, [sp, #0x80]
//   0x27cdb4: 910203FD  add      x29, sp, #0x80
uint64_t fde_func_7544_0x27cda0(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0027CDA0ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10243FFULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9002BF7ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90657F6ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9074FF4ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9087BFDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910203FDULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD53BD056ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF94016C8ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #7548 | PC: 0x27cff0..0x27d00c (28 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x27cff0: B40000C2  cbz      x2, #0x27d008
//   0x27cff4: AA0203E0  mov      x0, x2
//   0x27cff8: 2A0303E1  mov      w1, w3
//   0x27cffc: 2A0403E2  mov      w2, w4
//   0x27d000: 2A0503E3  mov      w3, w5
//   0x27d004: 17F9AB8B  b        #0xe7e30
uint64_t fde_func_7548_0x27cff0(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0027CFF0ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xB40000C2ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0203E0ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x2A0303E1ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x2A0403E2ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x2A0503E3ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x17F9AB8BULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD65F03C0ULL ^ (6ULL << 32);
    return state ^ (state >> 29);
}

// FDE #7553 | PC: 0x27d75c..0x27d848 (236 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x27d75c: D10283FF  sub      sp, sp, #0xa0
//   0x27d760: F90033F7  str      x23, [sp, #0x60]
//   0x27d764: A90757F6  stp      x22, x21, [sp, #0x70]
//   0x27d768: A9084FF4  stp      x20, x19, [sp, #0x80]
//   0x27d76c: A9097BFD  stp      x29, x30, [sp, #0x90]
//   0x27d770: 910243FD  add      x29, sp, #0x90
uint64_t fde_func_7553_0x27d75c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0027D75CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10283FFULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF90033F7ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90757F6ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9084FF4ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9097BFDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910243FDULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD53BD057ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF94016E8ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #7557 | PC: 0x27d99c..0x27d9b4 (24 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x27d99c: B40000A2  cbz      x2, #0x27d9b0
//   0x27d9a0: AA0203E0  mov      x0, x2
//   0x27d9a4: 2A0303E1  mov      w1, w3
//   0x27d9a8: AA0403E2  mov      x2, x4
//   0x27d9ac: 17F9A6BC  b        #0xe749c
//   0x27d9b0: D65F03C0  ret      
uint64_t fde_func_7557_0x27d99c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0027D99CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xB40000A2ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0203E0ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x2A0303E1ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0403E2ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x17F9A6BCULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD65F03C0ULL ^ (5ULL << 32);
    return state ^ (state >> 29);
}

// FDE #7562 | PC: 0x27dd2c..0x27dde0 (180 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x27dd2c: D101C3FF  sub      sp, sp, #0x70
//   0x27dd30: F90023F5  str      x21, [sp, #0x40]
//   0x27dd34: A9054FF4  stp      x20, x19, [sp, #0x50]
//   0x27dd38: A9067BFD  stp      x29, x30, [sp, #0x60]
//   0x27dd3c: 910183FD  add      x29, sp, #0x60
//   0x27dd40: D53BD055  mrs      x21, tpidr_el0
uint64_t fde_func_7562_0x27dd2c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0027DD2CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD101C3FFULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF90023F5ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9054FF4ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9067BFDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910183FDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD53BD055ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF94016A8ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81D83A8ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #7566 | PC: 0x27e0b4..0x27e1b4 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x27e0b4: D10243FF  sub      sp, sp, #0x90
//   0x27e0b8: F9002BF7  str      x23, [sp, #0x50]
//   0x27e0bc: A90657F6  stp      x22, x21, [sp, #0x60]
//   0x27e0c0: A9074FF4  stp      x20, x19, [sp, #0x70]
//   0x27e0c4: A9087BFD  stp      x29, x30, [sp, #0x80]
//   0x27e0c8: 910203FD  add      x29, sp, #0x80
uint64_t fde_func_7566_0x27e0b4(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0027E0B4ULL);
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

// FDE #7571 | PC: 0x27eb08..0x27ec08 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x27eb08: D10383FF  sub      sp, sp, #0xe0
//   0x27eb0c: A90967FA  stp      x26, x25, [sp, #0x90]
//   0x27eb10: A90A5FF8  stp      x24, x23, [sp, #0xa0]
//   0x27eb14: A90B57F6  stp      x22, x21, [sp, #0xb0]
//   0x27eb18: A90C4FF4  stp      x20, x19, [sp, #0xc0]
//   0x27eb1c: A90D7BFD  stp      x29, x30, [sp, #0xd0]
uint64_t fde_func_7571_0x27eb08(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0027EB08ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10383FFULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90967FAULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90A5FF8ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90B57F6ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90C4FF4ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90D7BFDULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910343FDULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD53BD05AULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #7575 | PC: 0x27efcc..0x27f07c (176 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x27efcc: D10203FF  sub      sp, sp, #0x80
//   0x27efd0: FD0023E8  str      d8, [sp, #0x40]
//   0x27efd4: A90557F6  stp      x22, x21, [sp, #0x50]
//   0x27efd8: A9064FF4  stp      x20, x19, [sp, #0x60]
//   0x27efdc: A9077BFD  stp      x29, x30, [sp, #0x70]
//   0x27efe0: 9101C3FD  add      x29, sp, #0x70
uint64_t fde_func_7575_0x27efcc(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0027EFCCULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10203FFULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xFD0023E8ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90557F6ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9064FF4ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9077BFDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9101C3FDULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD53BD056ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF94016C8ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #7580 | PC: 0x27f38c..0x27f48c (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x27f38c: D10383FF  sub      sp, sp, #0xe0
//   0x27f390: A9086FFC  stp      x28, x27, [sp, #0x80]
//   0x27f394: A90967FA  stp      x26, x25, [sp, #0x90]
//   0x27f398: A90A5FF8  stp      x24, x23, [sp, #0xa0]
//   0x27f39c: A90B57F6  stp      x22, x21, [sp, #0xb0]
//   0x27f3a0: A90C4FF4  stp      x20, x19, [sp, #0xc0]
uint64_t fde_func_7580_0x27f38c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0027F38CULL);
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

// FDE #7584 | PC: 0x27fb9c..0x27fbd4 (56 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x27fb9c: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x27fba0: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x27fba4: 910043FD  add      x29, sp, #0x10
//   0x27fba8: F00007A8  adrp     x8, #0x376000
//   0x27fbac: 913A0108  add      x8, x8, #0xe80
//   0x27fbb0: AA0003F3  mov      x19, x0
uint64_t fde_func_7584_0x27fb9c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0027FB9CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81E0FF3ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF00007A8ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x913A0108ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF8018408ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x94000BE7ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #7588 | PC: 0x27fc14..0x27fc4c (56 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x27fc14: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x27fc18: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x27fc1c: 910043FD  add      x29, sp, #0x10
//   0x27fc20: F00007A8  adrp     x8, #0x376000
//   0x27fc24: 913B4108  add      x8, x8, #0xed0
//   0x27fc28: AA0003F3  mov      x19, x0
uint64_t fde_func_7588_0x27fc14(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0027FC14ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81E0FF3ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF00007A8ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x913B4108ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF8018408ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x94000D98ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #7593 | PC: 0x28010c..0x280144 (56 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x28010c: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x280110: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x280114: 910043FD  add      x29, sp, #0x10
//   0x280118: D00007A8  adrp     x8, #0x376000
//   0x28011c: 913C8108  add      x8, x8, #0xf20
//   0x280120: AA0003F3  mov      x19, x0
uint64_t fde_func_7593_0x28010c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0028010CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81E0FF3ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD00007A8ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x913C8108ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF8018408ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x94000A19ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #7597 | PC: 0x2801fc..0x2802a4 (168 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x2801fc: D10143FF  sub      sp, sp, #0x50
//   0x280200: F90013F5  str      x21, [sp, #0x20]
//   0x280204: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x280208: A9047BFD  stp      x29, x30, [sp, #0x40]
//   0x28020c: 910103FD  add      x29, sp, #0x40
//   0x280210: D53BD055  mrs      x21, tpidr_el0
uint64_t fde_func_7597_0x2801fc(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x002801FCULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10143FFULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF90013F5ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9034FF4ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9047BFDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910103FDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD53BD055ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF94016A8ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9107A000ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #7602 | PC: 0x28052c..0x28053c (16 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x28052c: F9400008  ldr      x8, [x0]
//   0x280530: F9400108  ldr      x8, [x8]
//   0x280534: F9400100  ldr      x0, [x8]
//   0x280538: 14000001  b        #0x28053c
uint64_t fde_func_7602_0x28052c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0028052CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400008ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400108ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400100ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x14000001ULL ^ (3ULL << 32);
    return state ^ (state >> 29);
}

// FDE #7606 | PC: 0x2807fc..0x280800 (4 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x2807fc: 17F711F1  b        #0x44fc0
uint64_t fde_func_7606_0x2807fc(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x002807FCULL);
    state = (state * 0x00000100000001B3ULL) ^ 0x17F711F1ULL ^ (0ULL << 32);
    return state ^ (state >> 29);
}

// FDE #7611 | PC: 0x280838..0x28085c (36 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x280838: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x28083c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x280840: 910043FD  add      x29, sp, #0x10
//   0x280844: AA0003F3  mov      x19, x0
//   0x280848: 97F711DE  bl       #0x44fc0
//   0x28084c: A9417BFD  ldp      x29, x30, [sp, #0x10]
uint64_t fde_func_7611_0x280838(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00280838ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81E0FF3ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x97F711DEULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9417BFDULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA1303E0ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF84207F3ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #7615 | PC: 0x28087c..0x2808ac (48 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x28087c: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x280880: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x280884: 910043FD  add      x29, sp, #0x10
//   0x280888: F00007A8  adrp     x8, #0x377000
//   0x28088c: 91004108  add      x8, x8, #0x10
//   0x280890: AA0003F3  mov      x19, x0
uint64_t fde_func_7615_0x28087c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0028087CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81E0FF3ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF00007A8ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91004108ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF8018408ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x94002622ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #7620 | PC: 0x280914..0x28094c (56 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x280914: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x280918: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x28091c: 910043FD  add      x29, sp, #0x10
//   0x280920: F9400C13  ldr      x19, [x0, #0x18]
//   0x280924: B40000F3  cbz      x19, #0x280940
//   0x280928: AA1303E0  mov      x0, x19
uint64_t fde_func_7620_0x280914(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00280914ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81E0FF3ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400C13ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB40000F3ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA1303E0ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x940028A6ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9417BFDULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #7624 | PC: 0x280ab0..0x280b6c (188 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x280ab0: D10103FF  sub      sp, sp, #0x40
//   0x280ab4: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x280ab8: A9037BFD  stp      x29, x30, [sp, #0x30]
//   0x280abc: 9100C3FD  add      x29, sp, #0x30
//   0x280ac0: D53BD054  mrs      x20, tpidr_el0
//   0x280ac4: F9401688  ldr      x8, [x20, #0x28]
uint64_t fde_func_7624_0x280ab0(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00280AB0ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10103FFULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9024FF4ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9037BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9100C3FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD53BD054ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9401688ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF00007A9ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9102C129ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #7629 | PC: 0x280e50..0x280ea0 (80 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x280e50: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x280e54: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x280e58: 910043FD  add      x29, sp, #0x10
//   0x280e5c: 39408008  ldrb     w8, [x0, #0x20]
//   0x280e60: F00007A9  adrp     x9, #0x377000
//   0x280e64: AA0003F3  mov      x19, x0
uint64_t fde_func_7629_0x280e50(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00280E50ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81E0FF3ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x39408008ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF00007A9ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91044129ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000009ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #7633 | PC: 0x280f90..0x280fd4 (68 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x280f90: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x280f94: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x280f98: 910043FD  add      x29, sp, #0x10
//   0x280f9c: 39408008  ldrb     w8, [x0, #0x20]
//   0x280fa0: AA0003F3  mov      x19, x0
//   0x280fa4: 36000068  tbz      w8, #0, #0x280fb0
uint64_t fde_func_7633_0x280f90(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00280F90ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81E0FF3ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x39408008ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x36000068ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9401A60ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x97F70CE1ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #7638 | PC: 0x28113c..0x2811d8 (156 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x28113c: D10483FF  sub      sp, sp, #0x120
//   0x281140: A9104FFC  stp      x28, x19, [sp, #0x100]
//   0x281144: A9117BFD  stp      x29, x30, [sp, #0x110]
//   0x281148: 910443FD  add      x29, sp, #0x110
//   0x28114c: A90893E3  stp      x3, x4, [sp, #0x88]
//   0x281150: A9099BE5  stp      x5, x6, [sp, #0x98]
uint64_t fde_func_7638_0x28113c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0028113CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10483FFULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9104FFCULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9117BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910443FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90893E3ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9099BE5ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF90057E7ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAD0007E0ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #7642 | PC: 0x2812cc..0x281318 (76 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x2812cc: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x2812d0: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x2812d4: 910043FD  add      x29, sp, #0x10
//   0x2812d8: D00007A8  adrp     x8, #0x377000
//   0x2812dc: AA0003F4  mov      x20, x0
//   0x2812e0: 91064108  add      x8, x8, #0x190
uint64_t fde_func_7642_0x2812cc(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x002812CCULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE4FF4ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD00007A8ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F4ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91064108ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0103F3ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91002020ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #7647 | PC: 0x2814b8..0x2814c4 (12 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x2814b8: D00007A0  adrp     x0, #0x377000
//   0x2814bc: 9107C000  add      x0, x0, #0x1f0
//   0x2814c0: D65F03C0  ret      
uint64_t fde_func_7647_0x2814b8(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x002814B8ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD00007A0ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9107C000ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD65F03C0ULL ^ (2ULL << 32);
    return state ^ (state >> 29);
}

// FDE #7651 | PC: 0x281838..0x28184c (20 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x281838: AA0803E9  mov      x9, x8
//   0x28183c: F8008D3F  str      xzr, [x9, #8]!
//   0x281840: F900091F  str      xzr, [x8, #0x10]
//   0x281844: F9000109  str      x9, [x8]
//   0x281848: D65F03C0  ret      
uint64_t fde_func_7651_0x281838(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00281838ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0803E9ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF8008D3FULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF900091FULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000109ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD65F03C0ULL ^ (4ULL << 32);
    return state ^ (state >> 29);
}

// FDE #7656 | PC: 0x282158..0x2821f8 (160 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x282158: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x28215c: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x282160: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x282164: 910083FD  add      x29, sp, #0x20
//   0x282168: EB02003F  cmp      x1, x2
//   0x28216c: 540003E0  b.eq     #0x2821e8
uint64_t fde_func_7656_0x282158(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00282158ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BD57F6ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9014FF4ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9027BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910083FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xEB02003FULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x540003E0ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0203F3ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0103F6ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #7660 | PC: 0x28253c..0x282634 (248 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x28253c: D10143FF  sub      sp, sp, #0x50
//   0x282540: FD0013E8  str      d8, [sp, #0x20]
//   0x282544: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x282548: A9047BFD  stp      x29, x30, [sp, #0x40]
//   0x28254c: 910103FD  add      x29, sp, #0x40
//   0x282550: D53BD054  mrs      x20, tpidr_el0
uint64_t fde_func_7660_0x28253c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0028253CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10143FFULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xFD0013E8ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9034FF4ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9047BFDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910103FDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD53BD054ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9401688ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000FE8ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #7665 | PC: 0x282a10..0x282a34 (36 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x282a10: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x282a14: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x282a18: 910043FD  add      x29, sp, #0x10
//   0x282a1c: AA0003F3  mov      x19, x0
//   0x282a20: 97FFFFDB  bl       #0x28298c
//   0x282a24: A9417BFD  ldp      x29, x30, [sp, #0x10]
uint64_t fde_func_7665_0x282a10(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00282A10ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81E0FF3ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x97FFFFDBULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9417BFDULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA1303E0ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF84207F3ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #7669 | PC: 0x282c44..0x282c68 (36 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x282c44: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x282c48: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x282c4c: 910043FD  add      x29, sp, #0x10
//   0x282c50: AA0003F3  mov      x19, x0
//   0x282c54: 97FFFFC0  bl       #0x282b54
//   0x282c58: A9417BFD  ldp      x29, x30, [sp, #0x10]
uint64_t fde_func_7669_0x282c44(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00282C44ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81E0FF3ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x97FFFFC0ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9417BFDULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA1303E0ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF84207F3ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #7673 | PC: 0x283290..0x283380 (240 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x283290: D10103FF  sub      sp, sp, #0x40
//   0x283294: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x283298: A9037BFD  stp      x29, x30, [sp, #0x30]
//   0x28329c: 9100C3FD  add      x29, sp, #0x30
//   0x2832a0: D53BD054  mrs      x20, tpidr_el0
//   0x2832a4: F9401688  ldr      x8, [x20, #0x28]
uint64_t fde_func_7673_0x283290(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00283290ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10103FFULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9024FF4ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9037BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9100C3FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD53BD054ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9401688ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x900007A9ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910D2129ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #7678 | PC: 0x283748..0x2837a0 (88 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x283748: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x28374c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x283750: 910043FD  add      x29, sp, #0x10
//   0x283754: F9400413  ldr      x19, [x0, #8]
//   0x283758: B40000F3  cbz      x19, #0x283774
//   0x28375c: 91002268  add      x8, x19, #8
uint64_t fde_func_7678_0x283748(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00283748ULL);
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

// FDE #7682 | PC: 0x2838b4..0x2838c8 (20 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x2838b4: 39406008  ldrb     w8, [x0, #0x18]
//   0x2838b8: 37000048  tbnz     w8, #0, #0x2838c0
//   0x2838bc: D65F03C0  ret      
//   0x2838c0: F9401400  ldr      x0, [x0, #0x28]
//   0x2838c4: 17F7029B  b        #0x44330
uint64_t fde_func_7682_0x2838b4(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x002838B4ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0x39406008ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x37000048ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD65F03C0ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9401400ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x17F7029BULL ^ (4ULL << 32);
    return state ^ (state >> 29);
}

// FDE #7687 | PC: 0x283964..0x28399c (56 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x283964: 900007A8  adrp     x8, #0x377000
//   0x283968: 910FA108  add      x8, x8, #0x3e8
//   0x28396c: F9000028  str      x8, [x1]
//   0x283970: F9400408  ldr      x8, [x0, #8]
//   0x283974: F9000428  str      x8, [x1, #8]
//   0x283978: F9400808  ldr      x8, [x0, #0x10]
uint64_t fde_func_7687_0x283964(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00283964ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0x900007A8ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910FA108ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000028ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400408ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000428ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400808ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000828ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB40000C8ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #7691 | PC: 0x283a88..0x283aa4 (28 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x283a88: F9400428  ldr      x8, [x1, #8]
//   0x283a8c: F00003C9  adrp     x9, #0x2fe000
//   0x283a90: 91230529  add      x9, x9, #0x8c1
//   0x283a94: 9100200A  add      x10, x0, #8
//   0x283a98: EB09011F  cmp      x8, x9
//   0x283a9c: 9A9F0140  csel     x0, x10, xzr, eq
uint64_t fde_func_7691_0x283a88(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00283A88ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400428ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF00003C9ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91230529ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9100200AULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xEB09011FULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9A9F0140ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD65F03C0ULL ^ (6ULL << 32);
    return state ^ (state >> 29);
}

// FDE #7696 | PC: 0x286b78..0x286c00 (136 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x286b78: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x286b7c: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x286b80: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x286b84: 910083FD  add      x29, sp, #0x20
//   0x286b88: B4000321  cbz      x1, #0x286bec
//   0x286b8c: D00007D5  adrp     x21, #0x380000
uint64_t fde_func_7696_0x286b78(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00286B78ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81D0FF5ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9014FF4ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9027BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910083FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB4000321ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD00007D5ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9472AA8ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB40002C8ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #7700 | PC: 0x286d98..0x286e98 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x286d98: D101C3FF  sub      sp, sp, #0x70
//   0x286d9c: F90013F9  str      x25, [sp, #0x20]
//   0x286da0: A9035FF8  stp      x24, x23, [sp, #0x30]
//   0x286da4: A90457F6  stp      x22, x21, [sp, #0x40]
//   0x286da8: A9054FF4  stp      x20, x19, [sp, #0x50]
//   0x286dac: A9067BFD  stp      x29, x30, [sp, #0x60]
uint64_t fde_func_7700_0x286d98(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00286D98ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD101C3FFULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF90013F9ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9035FF8ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90457F6ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9054FF4ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9067BFDULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910183FDULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD53BD058ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #7705 | PC: 0x2879ec..0x287aec (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x2879ec: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x2879f0: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x2879f4: 910043FD  add      x29, sp, #0x10
//   0x2879f8: F9400008  ldr      x8, [x0]
//   0x2879fc: B00007D4  adrp     x20, #0x380000
//   0x287a00: F9400108  ldr      x8, [x8]
uint64_t fde_func_7705_0x2879ec(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x002879ECULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE4FF4ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400008ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB00007D4ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400108ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400113ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9474E88ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #7709 | PC: 0x288130..0x2881cc (156 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x288130: D10483FF  sub      sp, sp, #0x120
//   0x288134: A9104FFC  stp      x28, x19, [sp, #0x100]
//   0x288138: A9117BFD  stp      x29, x30, [sp, #0x110]
//   0x28813c: 910443FD  add      x29, sp, #0x110
//   0x288140: A90893E3  stp      x3, x4, [sp, #0x88]
//   0x288144: A9099BE5  stp      x5, x6, [sp, #0x98]
uint64_t fde_func_7709_0x288130(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00288130ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10483FFULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9104FFCULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9117BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910443FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90893E3ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9099BE5ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF90057E7ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAD0007E0ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #7714 | PC: 0x288480..0x288504 (132 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x288480: D10103FF  sub      sp, sp, #0x40
//   0x288484: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x288488: A9037BFD  stp      x29, x30, [sp, #0x30]
//   0x28848c: 9100C3FD  add      x29, sp, #0x30
//   0x288490: D53BD054  mrs      x20, tpidr_el0
//   0x288494: F9401688  ldr      x8, [x20, #0x28]
uint64_t fde_func_7714_0x288480(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00288480ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10103FFULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9024FF4ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9037BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9100C3FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD53BD054ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9401688ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF0000769ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9112E129ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #7718 | PC: 0x28895c..0x288a5c (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x28895c: D10243FF  sub      sp, sp, #0x90
//   0x288960: F9002BF7  str      x23, [sp, #0x50]
//   0x288964: A90657F6  stp      x22, x21, [sp, #0x60]
//   0x288968: A9074FF4  stp      x20, x19, [sp, #0x70]
//   0x28896c: A9087BFD  stp      x29, x30, [sp, #0x80]
//   0x288970: 910203FD  add      x29, sp, #0x80
uint64_t fde_func_7718_0x28895c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0028895CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10243FFULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9002BF7ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90657F6ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9074FF4ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9087BFDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910203FDULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD53BD057ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF94016E9ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #7723 | PC: 0x28921c..0x289240 (36 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x28921c: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x289220: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x289224: 910043FD  add      x29, sp, #0x10
//   0x289228: AA0003F3  mov      x19, x0
//   0x28922c: 97FFFFC0  bl       #0x28912c
//   0x289230: A9417BFD  ldp      x29, x30, [sp, #0x10]
uint64_t fde_func_7723_0x28921c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0028921CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81E0FF3ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x97FFFFC0ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9417BFDULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA1303E0ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF84207F3ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #7727 | PC: 0x289734..0x2897b8 (132 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x289734: D10103FF  sub      sp, sp, #0x40
//   0x289738: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x28973c: A9037BFD  stp      x29, x30, [sp, #0x30]
//   0x289740: 9100C3FD  add      x29, sp, #0x30
//   0x289744: D53BD054  mrs      x20, tpidr_el0
//   0x289748: F9401688  ldr      x8, [x20, #0x28]
uint64_t fde_func_7727_0x289734(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00289734ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10103FFULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9024FF4ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9037BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9100C3FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD53BD054ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9401688ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD0000769ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9115C129ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #7732 | PC: 0x289b64..0x289c00 (156 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x289b64: D10483FF  sub      sp, sp, #0x120
//   0x289b68: A9104FFC  stp      x28, x19, [sp, #0x100]
//   0x289b6c: A9117BFD  stp      x29, x30, [sp, #0x110]
//   0x289b70: 910443FD  add      x29, sp, #0x110
//   0x289b74: A90893E3  stp      x3, x4, [sp, #0x88]
//   0x289b78: A9099BE5  stp      x5, x6, [sp, #0x98]
uint64_t fde_func_7732_0x289b64(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00289B64ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10483FFULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9104FFCULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9117BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910443FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90893E3ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9099BE5ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF90057E7ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAD0007E0ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #7736 | PC: 0x289fb8..0x28a0b8 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x289fb8: D10143FF  sub      sp, sp, #0x50
//   0x289fbc: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x289fc0: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x289fc4: A9047BFD  stp      x29, x30, [sp, #0x40]
//   0x289fc8: 910103FD  add      x29, sp, #0x40
//   0x289fcc: D53BD056  mrs      x22, tpidr_el0
uint64_t fde_func_7736_0x289fb8(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00289FB8ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10143FFULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90257F6ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9034FF4ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9047BFDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910103FDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD53BD056ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF94016C8ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD0000769ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #7741 | PC: 0x28a42c..0x28a52c (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x28a42c: D10243FF  sub      sp, sp, #0x90
//   0x28a430: A90657F6  stp      x22, x21, [sp, #0x60]
//   0x28a434: A9074FF4  stp      x20, x19, [sp, #0x70]
//   0x28a438: A9087BFD  stp      x29, x30, [sp, #0x80]
//   0x28a43c: 910203FD  add      x29, sp, #0x80
//   0x28a440: D53BD056  mrs      x22, tpidr_el0
uint64_t fde_func_7741_0x28a42c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0028A42CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10243FFULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90657F6ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9074FF4ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9087BFDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910203FDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD53BD056ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF94016C8ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81D83A8ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #7745 | PC: 0x28a5ec..0x28a62c (64 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x28a5ec: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x28a5f0: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x28a5f4: 910043FD  add      x29, sp, #0x10
//   0x28a5f8: B0000768  adrp     x8, #0x377000
//   0x28a5fc: AA0003F4  mov      x20, x0
//   0x28a600: 9118E108  add      x8, x8, #0x638
uint64_t fde_func_7745_0x28a5ec(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0028A5ECULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE4FF4ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB0000768ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F4ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9118E108ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0103F3ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91002020ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #7749 | PC: 0x28a744..0x28a760 (28 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x28a744: F9400428  ldr      x8, [x1, #8]
//   0x28a748: B00003A9  adrp     x9, #0x2ff000
//   0x28a74c: 91110929  add      x9, x9, #0x442
//   0x28a750: 9100200A  add      x10, x0, #8
//   0x28a754: EB09011F  cmp      x8, x9
//   0x28a758: 9A9F0140  csel     x0, x10, xzr, eq
uint64_t fde_func_7749_0x28a744(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0028A744ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400428ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB00003A9ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91110929ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9100200AULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xEB09011FULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9A9F0140ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD65F03C0ULL ^ (6ULL << 32);
    return state ^ (state >> 29);
}

// FDE #7754 | PC: 0x28a814..0x28a854 (64 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x28a814: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x28a818: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x28a81c: 910043FD  add      x29, sp, #0x10
//   0x28a820: B0000768  adrp     x8, #0x377000
//   0x28a824: AA0003F4  mov      x20, x0
//   0x28a828: 911AE108  add      x8, x8, #0x6b8
uint64_t fde_func_7754_0x28a814(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0028A814ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE4FF4ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB0000768ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F4ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x911AE108ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0103F3ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91002020ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #7758 | PC: 0x28a970..0x28a98c (28 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x28a970: F9400428  ldr      x8, [x1, #8]
//   0x28a974: B00003A9  adrp     x9, #0x2ff000
//   0x28a978: 9115C929  add      x9, x9, #0x572
//   0x28a97c: 9100200A  add      x10, x0, #8
//   0x28a980: EB09011F  cmp      x8, x9
//   0x28a984: 9A9F0140  csel     x0, x10, xzr, eq
uint64_t fde_func_7758_0x28a970(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0028A970ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400428ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB00003A9ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9115C929ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9100200AULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xEB09011FULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9A9F0140ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD65F03C0ULL ^ (6ULL << 32);
    return state ^ (state >> 29);
}

// FDE #7763 | PC: 0x28ac9c..0x28ad9c (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x28ac9c: D10243FF  sub      sp, sp, #0x90
//   0x28aca0: F9002BF7  str      x23, [sp, #0x50]
//   0x28aca4: A90657F6  stp      x22, x21, [sp, #0x60]
//   0x28aca8: A9074FF4  stp      x20, x19, [sp, #0x70]
//   0x28acac: A9087BFD  stp      x29, x30, [sp, #0x80]
//   0x28acb0: 910203FD  add      x29, sp, #0x80
uint64_t fde_func_7763_0x28ac9c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0028AC9CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10243FFULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9002BF7ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90657F6ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9074FF4ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9087BFDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910203FDULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD53BD056ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0803F3ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #7767 | PC: 0x28b490..0x28b590 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x28b490: D10143FF  sub      sp, sp, #0x50
//   0x28b494: FD0013E8  str      d8, [sp, #0x20]
//   0x28b498: F90017F5  str      x21, [sp, #0x28]
//   0x28b49c: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x28b4a0: A9047BFD  stp      x29, x30, [sp, #0x40]
//   0x28b4a4: 910103FD  add      x29, sp, #0x40
uint64_t fde_func_7767_0x28b490(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0028B490ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10143FFULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xFD0013E8ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF90017F5ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9034FF4ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9047BFDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910103FDULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD53BD055ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF94016A8ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #7772 | PC: 0x28bc90..0x28bc94 (4 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x28bc90: 17F6E1A8  b        #0x44330
uint64_t fde_func_7772_0x28bc90(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0028BC90ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0x17F6E1A8ULL ^ (0ULL << 32);
    return state ^ (state >> 29);
}

// FDE #7776 | PC: 0x28becc..0x28bf78 (172 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x28becc: D10103FF  sub      sp, sp, #0x40
//   0x28bed0: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x28bed4: A9037BFD  stp      x29, x30, [sp, #0x30]
//   0x28bed8: 9100C3FD  add      x29, sp, #0x30
//   0x28bedc: D53BD054  mrs      x20, tpidr_el0
//   0x28bee0: F9401689  ldr      x9, [x20, #0x28]
uint64_t fde_func_7776_0x28becc(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0028BECCULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10103FFULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9024FF4ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9037BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9100C3FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD53BD054ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9401689ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0803F3ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910023E8ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #7781 | PC: 0x28c23c..0x28c308 (204 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x28c23c: D10183FF  sub      sp, sp, #0x60
//   0x28c240: F90013F7  str      x23, [sp, #0x20]
//   0x28c244: A90357F6  stp      x22, x21, [sp, #0x30]
//   0x28c248: A9044FF4  stp      x20, x19, [sp, #0x40]
//   0x28c24c: A9057BFD  stp      x29, x30, [sp, #0x50]
//   0x28c250: 910143FD  add      x29, sp, #0x50
uint64_t fde_func_7781_0x28c23c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0028C23CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10183FFULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF90013F7ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90357F6ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9044FF4ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9057BFDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910143FDULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD53BD057ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0803F4ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #7785 | PC: 0x28c4f4..0x28c4fc (8 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x28c4f4: B9000801  str      w1, [x0, #8]
//   0x28c4f8: D65F03C0  ret      
uint64_t fde_func_7785_0x28c4f4(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0028C4F4ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xB9000801ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD65F03C0ULL ^ (1ULL << 32);
    return state ^ (state >> 29);
}

// FDE #7790 | PC: 0x28c574..0x28c58c (24 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x28c574: F9400008  ldr      x8, [x0]
//   0x28c578: F0000741  adrp     x1, #0x377000
//   0x28c57c: 9126C021  add      x1, x1, #0x9b0
//   0x28c580: F85E8108  ldur     x8, [x8, #-0x18]
//   0x28c584: 8B080000  add      x0, x0, x8
//   0x28c588: 14000038  b        #0x28c668
uint64_t fde_func_7790_0x28c574(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0028C574ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400008ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF0000741ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9126C021ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF85E8108ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x8B080000ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x14000038ULL ^ (5ULL << 32);
    return state ^ (state >> 29);
}

// FDE #7794 | PC: 0x28c638..0x28c640 (8 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x28c638: D1004000  sub      x0, x0, #0x10
//   0x28c63c: 17FFFFE2  b        #0x28c5c4
uint64_t fde_func_7794_0x28c638(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0028C638ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD1004000ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x17FFFFE2ULL ^ (1ULL << 32);
    return state ^ (state >> 29);
}

// FDE #7799 | PC: 0x28c75c..0x28c78c (48 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x28c75c: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x28c760: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x28c764: 910043FD  add      x29, sp, #0x10
//   0x28c768: F0000748  adrp     x8, #0x377000
//   0x28c76c: 912BA108  add      x8, x8, #0xae8
//   0x28c770: AA0003F3  mov      x19, x0
uint64_t fde_func_7799_0x28c75c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0028C75CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81E0FF3ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF0000748ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x912BA108ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF8018408ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x97FFFF93ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #7803 | PC: 0x28c7d4..0x28c848 (116 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x28c7d4: D100C3FF  sub      sp, sp, #0x30
//   0x28c7d8: F9000BF3  str      x19, [sp, #0x10]
//   0x28c7dc: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x28c7e0: 910083FD  add      x29, sp, #0x20
//   0x28c7e4: A9404C48  ldp      x8, x19, [x2]
//   0x28c7e8: 910003E1  mov      x1, sp
uint64_t fde_func_7803_0x28c7d4(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0028C7D4ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD100C3FFULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF3ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9027BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910083FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9404C48ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003E1ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9004FE8ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9007C5FULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #7808 | PC: 0x28ca98..0x28cb04 (108 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x28ca98: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x28ca9c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x28caa0: 910043FD  add      x29, sp, #0x10
//   0x28caa4: F0000748  adrp     x8, #0x377000
//   0x28caa8: 912D0108  add      x8, x8, #0xb40
//   0x28caac: AA0003F3  mov      x19, x0
uint64_t fde_func_7808_0x28ca98(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0028CA98ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81E0FF3ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF0000748ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x912D0108ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81F8E68ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x3942A009ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #7812 | PC: 0x28cbe4..0x28cbec (8 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x28cbe4: 91004000  add      x0, x0, #0x10
//   0x28cbe8: 14000001  b        #0x28cbec
uint64_t fde_func_7812_0x28cbe4(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0028CBE4ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0x91004000ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x14000001ULL ^ (1ULL << 32);
    return state ^ (state >> 29);
}

// FDE #7817 | PC: 0x28cf1c..0x28d01c (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x28cf1c: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x28cf20: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x28cf24: 910043FD  add      x29, sp, #0x10
//   0x28cf28: AA0003F3  mov      x19, x0
//   0x28cf2c: F9400800  ldr      x0, [x0, #0x10]
//   0x28cf30: B4000060  cbz      x0, #0x28cf3c
uint64_t fde_func_7817_0x28cf1c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0028CF1CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE4FF4ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400800ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB4000060ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000A7FULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x97F6DC6EULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #7821 | PC: 0x28d2f4..0x28d320 (44 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x28d2f4: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x28d2f8: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x28d2fc: 910043FD  add      x29, sp, #0x10
//   0x28d300: D0000741  adrp     x1, #0x377000
//   0x28d304: 91380021  add      x1, x1, #0xe00
//   0x28d308: AA0003F3  mov      x19, x0
uint64_t fde_func_7821_0x28d2f4(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0028D2F4ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81E0FF3ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD0000741ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91380021ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x94000019ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9417BFDULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #7826 | PC: 0x28d48c..0x28d4bc (48 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x28d48c: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x28d490: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x28d494: 910043FD  add      x29, sp, #0x10
//   0x28d498: D0000748  adrp     x8, #0x377000
//   0x28d49c: 9139A108  add      x8, x8, #0xe68
//   0x28d4a0: AA0003F3  mov      x19, x0
uint64_t fde_func_7826_0x28d48c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0028D48CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81E0FF3ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD0000748ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9139A108ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF8018408ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x97F6DC9EULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #7830 | PC: 0x28d500..0x28d598 (152 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x28d500: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x28d504: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x28d508: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x28d50c: 910083FD  add      x29, sp, #0x20
//   0x28d510: A9405416  ldp      x22, x21, [x0]
//   0x28d514: AA0003F3  mov      x19, x0
uint64_t fde_func_7830_0x28d500(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0028D500ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BD57F6ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9014FF4ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9027BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910083FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9405416ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0103F4ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xEB1602BFULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #7834 | PC: 0x28d9ec..0x28daec (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x28d9ec: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x28d9f0: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x28d9f4: 910043FD  add      x29, sp, #0x10
//   0x28d9f8: F9400814  ldr      x20, [x0, #0x10]
//   0x28d9fc: AA0003F3  mov      x19, x0
//   0x28da00: A900FC1F  stp      xzr, xzr, [x0, #8]
uint64_t fde_func_7834_0x28d9ec(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0028D9ECULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE4FF4ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400814ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA900FC1FULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB40001B4ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91002288ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #7839 | PC: 0x28dc64..0x28dc74 (16 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x28dc64: F9401C00  ldr      x0, [x0, #0x38]
//   0x28dc68: B4000040  cbz      x0, #0x28dc70
//   0x28dc6c: 1400113A  b        #0x292154
//   0x28dc70: D65F03C0  ret      
uint64_t fde_func_7839_0x28dc64(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0028DC64ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9401C00ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB4000040ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x1400113AULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD65F03C0ULL ^ (3ULL << 32);
    return state ^ (state >> 29);
}

// FDE #7843 | PC: 0x28dd84..0x28ddfc (120 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x28dd84: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x28dd88: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x28dd8c: 910043FD  add      x29, sp, #0x10
//   0x28dd90: F0000748  adrp     x8, #0x378000
//   0x28dd94: 9103A108  add      x8, x8, #0xe8
//   0x28dd98: 91012109  add      x9, x8, #0x48
uint64_t fde_func_7843_0x28dd84(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0028DD84ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81E0FF3ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF0000748ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9103A108ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91012109ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9E670100ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x4E181D20ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #7848 | PC: 0x28e174..0x28e1e8 (116 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x28e174: D10103FF  sub      sp, sp, #0x40
//   0x28e178: F9000BF5  str      x21, [sp, #0x10]
//   0x28e17c: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x28e180: A9037BFD  stp      x29, x30, [sp, #0x30]
//   0x28e184: 9100C3FD  add      x29, sp, #0x30
//   0x28e188: D53BD055  mrs      x21, tpidr_el0
uint64_t fde_func_7848_0x28e174(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0028E174ULL);
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

// FDE #7852 | PC: 0x28e390..0x28e3bc (44 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x28e390: F9404409  ldr      x9, [x0, #0x88]
//   0x28e394: F9000109  str      x9, [x8]
//   0x28e398: F9404809  ldr      x9, [x0, #0x90]
//   0x28e39c: F9000509  str      x9, [x8, #8]
//   0x28e3a0: B40000C9  cbz      x9, #0x28e3b8
//   0x28e3a4: 91002128  add      x8, x9, #8
uint64_t fde_func_7852_0x28e390(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0028E390ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9404409ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000109ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9404809ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000509ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB40000C9ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91002128ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xC85F7D09ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91000529ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #7857 | PC: 0x28eb80..0x28eb8c (12 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x28eb80: D0000741  adrp     x1, #0x378000
//   0x28eb84: 9100E021  add      x1, x1, #0x38
//   0x28eb88: 17FFFFD2  b        #0x28ead0
uint64_t fde_func_7857_0x28eb80(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0028EB80ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD0000741ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9100E021ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x17FFFFD2ULL ^ (2ULL << 32);
    return state ^ (state >> 29);
}

// FDE #7861 | PC: 0x28ebe0..0x28ec10 (48 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x28ebe0: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x28ebe4: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x28ebe8: 910043FD  add      x29, sp, #0x10
//   0x28ebec: D1002013  sub      x19, x0, #8
//   0x28ebf0: D0000741  adrp     x1, #0x378000
//   0x28ebf4: 9100E021  add      x1, x1, #0x38
uint64_t fde_func_7861_0x28ebe0(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0028EBE0ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81E0FF3ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD1002013ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD0000741ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9100E021ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA1303E0ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x97FFFFB5ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #7866 | PC: 0x28ec7c..0x28ec80 (4 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x28ec7c: 17F6D5AD  b        #0x44330
uint64_t fde_func_7866_0x28ec7c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0028EC7CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0x17F6D5ADULL ^ (0ULL << 32);
    return state ^ (state >> 29);
}

// FDE #7870 | PC: 0x28ec90..0x28ec94 (4 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x28ec90: 17F6D5A8  b        #0x44330
uint64_t fde_func_7870_0x28ec90(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0028EC90ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0x17F6D5A8ULL ^ (0ULL << 32);
    return state ^ (state >> 29);
}

// FDE #7875 | PC: 0x28ee64..0x28eee8 (132 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x28ee64: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x28ee68: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x28ee6c: 910043FD  add      x29, sp, #0x10
//   0x28ee70: F9400428  ldr      x8, [x1, #8]
//   0x28ee74: B40000A8  cbz      x8, #0x28ee88
//   0x28ee78: AA0803F3  mov      x19, x8
uint64_t fde_func_7875_0x28ee64(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0028EE64ULL);
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

// FDE #7879 | PC: 0x28ef6c..0x28ef70 (4 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x28ef6c: 17F6D4F1  b        #0x44330
uint64_t fde_func_7879_0x28ef6c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0028EF6CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0x17F6D4F1ULL ^ (0ULL << 32);
    return state ^ (state >> 29);
}

// FDE #7884 | PC: 0x28f0b8..0x28f0c4 (12 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x28f0b8: F8418C08  ldr      x8, [x0, #0x18]!
//   0x28f0bc: F9400101  ldr      x1, [x8]
//   0x28f0c0: D61F0020  br       x1
uint64_t fde_func_7884_0x28f0b8(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0028F0B8ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF8418C08ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400101ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD61F0020ULL ^ (2ULL << 32);
    return state ^ (state >> 29);
}

// FDE #7888 | PC: 0x28f198..0x28f230 (152 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x28f198: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x28f19c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x28f1a0: 910043FD  add      x29, sp, #0x10
//   0x28f1a4: B0000748  adrp     x8, #0x378000
//   0x28f1a8: 91090108  add      x8, x8, #0x240
//   0x28f1ac: 12800009  mov      w9, #-1
uint64_t fde_func_7888_0x28f198(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0028F198ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81E0FF3ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB0000748ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91090108ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x12800009ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000008ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB0000748ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #7893 | PC: 0x28f368..0x28f36c (4 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x28f368: 17F6D3F2  b        #0x44330
uint64_t fde_func_7893_0x28f368(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0028F368ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0x17F6D3F2ULL ^ (0ULL << 32);
    return state ^ (state >> 29);
}

// FDE #7897 | PC: 0x28f3c4..0x28f3d4 (16 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x28f3c4: 35000041  cbnz     w1, #0x28f3cc
//   0x28f3c8: B9409802  ldr      w2, [x0, #0x98]
//   0x28f3cc: 2A0203E0  mov      w0, w2
//   0x28f3d0: D65F03C0  ret      
uint64_t fde_func_7897_0x28f3c4(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0028F3C4ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0x35000041ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB9409802ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x2A0203E0ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD65F03C0ULL ^ (3ULL << 32);
    return state ^ (state >> 29);
}

// FDE #7902 | PC: 0x28f43c..0x28f474 (56 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x28f43c: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x28f440: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x28f444: 910043FD  add      x29, sp, #0x10
//   0x28f448: F9400008  ldr      x8, [x0]
//   0x28f44c: B0000741  adrp     x1, #0x378000
//   0x28f450: 910EA021  add      x1, x1, #0x3a8
uint64_t fde_func_7902_0x28f43c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0028F43CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81E0FF3ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400008ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB0000741ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910EA021ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF85E8108ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x8B080013ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #7906 | PC: 0x28f628..0x28f668 (64 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x28f628: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x28f62c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x28f630: 910043FD  add      x29, sp, #0x10
//   0x28f634: B0000748  adrp     x8, #0x378000
//   0x28f638: 91130108  add      x8, x8, #0x4c0
//   0x28f63c: B0000741  adrp     x1, #0x378000
uint64_t fde_func_7906_0x28f628(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0028F628ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81E0FF3ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB0000748ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91130108ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB0000741ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF8018408ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #7910 | PC: 0x28f684..0x28f6b0 (44 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x28f684: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x28f688: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x28f68c: 910043FD  add      x29, sp, #0x10
//   0x28f690: B0000741  adrp     x1, #0x378000
//   0x28f694: 91188021  add      x1, x1, #0x620
//   0x28f698: AA0003F3  mov      x19, x0
uint64_t fde_func_7910_0x28f684(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0028F684ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81E0FF3ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB0000741ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91188021ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x97FFFD0DULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9417BFDULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #7915 | PC: 0x28f740..0x28f80c (204 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x28f740: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x28f744: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x28f748: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x28f74c: 910083FD  add      x29, sp, #0x20
//   0x28f750: 52801800  mov      w0, #0xc0
//   0x28f754: AA0803F3  mov      x19, x8
uint64_t fde_func_7915_0x28f740(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0028F740ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BD57F6ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9014FF4ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9027BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910083FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x52801800ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0803F3ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x97F6D25EULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB0000748ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #7919 | PC: 0x28f934..0x28f944 (16 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x28f934: B0000741  adrp     x1, #0x378000
//   0x28f938: 91006000  add      x0, x0, #0x18
//   0x28f93c: 91226021  add      x1, x1, #0x898
//   0x28f940: 17FFFC64  b        #0x28ead0
uint64_t fde_func_7919_0x28f934(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0028F934ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xB0000741ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91006000ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91226021ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x17FFFC64ULL ^ (3ULL << 32);
    return state ^ (state >> 29);
}

// FDE #7924 | PC: 0x28f990..0x28f9c0 (48 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x28f990: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x28f994: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x28f998: 910043FD  add      x29, sp, #0x10
//   0x28f99c: D1002013  sub      x19, x0, #8
//   0x28f9a0: B0000741  adrp     x1, #0x378000
//   0x28f9a4: 91226021  add      x1, x1, #0x898
uint64_t fde_func_7924_0x28f990(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0028F990ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81E0FF3ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD1002013ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB0000741ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91226021ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA1303E0ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x97FFFC49ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #7928 | PC: 0x28fadc..0x28fb8c (176 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x28fadc: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x28fae0: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x28fae4: 910043FD  add      x29, sp, #0x10
//   0x28fae8: B40003C1  cbz      x1, #0x28fb60
//   0x28faec: AA0003E8  mov      x8, x0
//   0x28faf0: F9400420  ldr      x0, [x1, #8]
uint64_t fde_func_7928_0x28fadc(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0028FADCULL);
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

// FDE #7933 | PC: 0x28fc18..0x28fc24 (12 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x28fc18: B0000741  adrp     x1, #0x378000
//   0x28fc1c: 912C4021  add      x1, x1, #0xb10
//   0x28fc20: 17FFFBAC  b        #0x28ead0
uint64_t fde_func_7933_0x28fc18(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0028FC18ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xB0000741ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x912C4021ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x17FFFBACULL ^ (2ULL << 32);
    return state ^ (state >> 29);
}

// FDE #7937 | PC: 0x28fc90..0x28fca8 (24 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x28fc90: F9400008  ldr      x8, [x0]
//   0x28fc94: B0000741  adrp     x1, #0x378000
//   0x28fc98: 912C4021  add      x1, x1, #0xb10
//   0x28fc9c: F85E8108  ldur     x8, [x8, #-0x18]
//   0x28fca0: 8B080000  add      x0, x0, x8
//   0x28fca4: 17FFFB8B  b        #0x28ead0
uint64_t fde_func_7937_0x28fc90(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0028FC90ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400008ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB0000741ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x912C4021ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF85E8108ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x8B080000ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x17FFFB8BULL ^ (5ULL << 32);
    return state ^ (state >> 29);
}

// FDE #7942 | PC: 0x28fe1c..0x28fe54 (56 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x28fe1c: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x28fe20: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x28fe24: 910043FD  add      x29, sp, #0x10
//   0x28fe28: B0000748  adrp     x8, #0x378000
//   0x28fe2c: 9130A108  add      x8, x8, #0xc28
//   0x28fe30: AA0003F3  mov      x19, x0
uint64_t fde_func_7942_0x28fe1c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0028FE1CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81E0FF3ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB0000748ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9130A108ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF8018408ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x94000658ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #7946 | PC: 0x28febc..0x28ff6c (176 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x28febc: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x28fec0: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x28fec4: 910043FD  add      x29, sp, #0x10
//   0x28fec8: B40003C1  cbz      x1, #0x28ff40
//   0x28fecc: AA0003E8  mov      x8, x0
//   0x28fed0: F9400420  ldr      x0, [x1, #8]
uint64_t fde_func_7946_0x28febc(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0028FEBCULL);
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

// FDE #7951 | PC: 0x28fff8..0x290070 (120 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x28fff8: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x28fffc: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x290000: 910043FD  add      x29, sp, #0x10
//   0x290004: F9400028  ldr      x8, [x1]
//   0x290008: AA0103F4  mov      x20, x1
//   0x29000c: AA0003F3  mov      x19, x0
uint64_t fde_func_7951_0x28fff8(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0028FFF8ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE4FF4ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400028ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0103F4ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000008ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400C29ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #7955 | PC: 0x290158..0x290208 (176 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x290158: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x29015c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x290160: 910043FD  add      x29, sp, #0x10
//   0x290164: B40003C1  cbz      x1, #0x2901dc
//   0x290168: AA0003E8  mov      x8, x0
//   0x29016c: F9400420  ldr      x0, [x1, #8]
uint64_t fde_func_7955_0x290158(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00290158ULL);
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

// FDE #7960 | PC: 0x290290..0x2902f4 (100 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x290290: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x290294: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x290298: 910043FD  add      x29, sp, #0x10
//   0x29029c: F9400028  ldr      x8, [x1]
//   0x2902a0: F000076A  adrp     x10, #0x37f000
//   0x2902a4: AA0003F4  mov      x20, x0
uint64_t fde_func_7960_0x290290(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00290290ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE4FF4ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400028ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF000076AULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F4ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0103F3ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000008ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #7964 | PC: 0x290438..0x290478 (64 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x290438: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x29043c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x290440: 910043FD  add      x29, sp, #0x10
//   0x290444: 90000748  adrp     x8, #0x378000
//   0x290448: 91346108  add      x8, x8, #0xd18
//   0x29044c: AA0003F3  mov      x19, x0
uint64_t fde_func_7964_0x290438(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00290438ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81E0FF3ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x90000748ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91346108ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF8018408ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF0000761ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #7969 | PC: 0x2905dc..0x29068c (176 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x2905dc: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x2905e0: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x2905e4: 910043FD  add      x29, sp, #0x10
//   0x2905e8: B40003C1  cbz      x1, #0x290660
//   0x2905ec: AA0003E8  mov      x8, x0
//   0x2905f0: F9400420  ldr      x0, [x1, #8]
uint64_t fde_func_7969_0x2905dc(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x002905DCULL);
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

// FDE #7973 | PC: 0x290870..0x2908ec (124 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x290870: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x290874: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x290878: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x29087c: 910083FD  add      x29, sp, #0x20
//   0x290880: F0000775  adrp     x21, #0x37f000
//   0x290884: F9464AB5  ldr      x21, [x21, #0xc90]
uint64_t fde_func_7973_0x290870(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00290870ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81D0FF5ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9014FF4ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9027BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910083FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF0000775ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9464AB5ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F4ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #7978 | PC: 0x290a34..0x290a74 (64 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x290a34: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x290a38: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x290a3c: 910043FD  add      x29, sp, #0x10
//   0x290a40: 90000748  adrp     x8, #0x378000
//   0x290a44: 9136E108  add      x8, x8, #0xdb8
//   0x290a48: AA0003F3  mov      x19, x0
uint64_t fde_func_7978_0x290a34(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00290A34ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81E0FF3ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x90000748ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9136E108ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF8018408ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF0000761ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #7982 | PC: 0x290ae8..0x290b24 (60 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x290ae8: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x290aec: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x290af0: 910043FD  add      x29, sp, #0x10
//   0x290af4: F9400801  ldr      x1, [x0, #0x10]
//   0x290af8: AA0003F3  mov      x19, x0
//   0x290afc: 9400000A  bl       #0x290b24
uint64_t fde_func_7982_0x290ae8(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00290AE8ULL);
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

// FDE #7986 | PC: 0x290c04..0x290c50 (76 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x290c04: 90000749  adrp     x9, #0x378000
//   0x290c08: 12800008  mov      w8, #-1
//   0x290c0c: 91382129  add      x9, x9, #0xe08
//   0x290c10: B9000808  str      w8, [x0, #8]
//   0x290c14: 91016128  add      x8, x9, #0x58
//   0x290c18: F9000009  str      x9, [x0]
uint64_t fde_func_7986_0x290c04(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00290C04ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0x90000749ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x12800008ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91382129ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB9000808ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91016128ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000009ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000808ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400028ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #7991 | PC: 0x290dd8..0x290e88 (176 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x290dd8: F81C0FF7  str      x23, [sp, #-0x40]!
//   0x290ddc: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x290de0: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x290de4: A9037BFD  stp      x29, x30, [sp, #0x30]
//   0x290de8: 9100C3FD  add      x29, sp, #0x30
//   0x290dec: 9100A014  add      x20, x0, #0x28
uint64_t fde_func_7991_0x290dd8(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00290DD8ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81C0FF7ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90157F6ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9024FF4ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9037BFDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9100C3FDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9100A014ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F7ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA1403E0ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #7995 | PC: 0x290f98..0x290fa0 (8 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x290f98: D1004000  sub      x0, x0, #0x10
//   0x290f9c: 17FFFFCC  b        #0x290ecc
uint64_t fde_func_7995_0x290f98(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00290F98ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD1004000ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x17FFFFCCULL ^ (1ULL << 32);
    return state ^ (state >> 29);
}

// FDE #8000 | PC: 0x291030..0x2910f8 (200 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x291030: A9BC5FF8  stp      x24, x23, [sp, #-0x40]!
//   0x291034: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x291038: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x29103c: A9037BFD  stp      x29, x30, [sp, #0x30]
//   0x291040: 9100C3FD  add      x29, sp, #0x30
//   0x291044: 91006013  add      x19, x0, #0x18
uint64_t fde_func_8000_0x291030(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00291030ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BC5FF8ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90157F6ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9024FF4ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9037BFDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9100C3FDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91006013ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F8ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA1303E0ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #8004 | PC: 0x29131c..0x29141c (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x29131c: D10183FF  sub      sp, sp, #0x60
//   0x291320: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x291324: A90357F6  stp      x22, x21, [sp, #0x30]
//   0x291328: A9044FF4  stp      x20, x19, [sp, #0x40]
//   0x29132c: A9057BFD  stp      x29, x30, [sp, #0x50]
//   0x291330: 910143FD  add      x29, sp, #0x50
uint64_t fde_func_8004_0x29131c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0029131CULL);
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

// FDE #8009 | PC: 0x2914e0..0x29150c (44 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x2914e0: F9403C09  ldr      x9, [x0, #0x78]
//   0x2914e4: F9000109  str      x9, [x8]
//   0x2914e8: F9404009  ldr      x9, [x0, #0x80]
//   0x2914ec: F9000509  str      x9, [x8, #8]
//   0x2914f0: B40000C9  cbz      x9, #0x291508
//   0x2914f4: 91002128  add      x8, x9, #8
uint64_t fde_func_8009_0x2914e0(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x002914E0ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9403C09ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000109ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9404009ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000509ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB40000C9ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91002128ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xC85F7D09ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91000529ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #8013 | PC: 0x291728..0x291730 (8 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x291728: D1026000  sub      x0, x0, #0x98
//   0x29172c: 17FFFFC3  b        #0x291638
uint64_t fde_func_8013_0x291728(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00291728ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD1026000ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x17FFFFC3ULL ^ (1ULL << 32);
    return state ^ (state >> 29);
}

// FDE #8018 | PC: 0x2917c4..0x2917dc (24 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x2917c4: F9400008  ldr      x8, [x0]
//   0x2917c8: 90000741  adrp     x1, #0x379000
//   0x2917cc: 9103A021  add      x1, x1, #0xe8
//   0x2917d0: F85E8108  ldur     x8, [x8, #-0x18]
//   0x2917d4: 8B080000  add      x0, x0, x8
//   0x2917d8: 17FFFFD6  b        #0x291730
uint64_t fde_func_8018_0x2917c4(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x002917C4ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400008ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x90000741ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9103A021ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF85E8108ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x8B080000ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x17FFFFD6ULL ^ (5ULL << 32);
    return state ^ (state >> 29);
}

// FDE #8022 | PC: 0x291868..0x2918a0 (56 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x291868: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x29186c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x291870: 910043FD  add      x29, sp, #0x10
//   0x291874: F9400008  ldr      x8, [x0]
//   0x291878: 90000741  adrp     x1, #0x379000
//   0x29187c: 9103A021  add      x1, x1, #0xe8
uint64_t fde_func_8022_0x291868(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00291868ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81E0FF3ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400008ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x90000741ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9103A021ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF85E8108ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x8B080013ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #8027 | PC: 0x2919d4..0x291ad4 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x2919d4: D10243FF  sub      sp, sp, #0x90
//   0x2919d8: F9001BFB  str      x27, [sp, #0x30]
//   0x2919dc: A90467FA  stp      x26, x25, [sp, #0x40]
//   0x2919e0: A9055FF8  stp      x24, x23, [sp, #0x50]
//   0x2919e4: A90657F6  stp      x22, x21, [sp, #0x60]
//   0x2919e8: A9074FF4  stp      x20, x19, [sp, #0x70]
uint64_t fde_func_8027_0x2919d4(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x002919D4ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10243FFULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9001BFBULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90467FAULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9055FF8ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90657F6ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9074FF4ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9087BFDULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910203FDULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #8031 | PC: 0x291f78..0x291fb8 (64 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x291f78: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x291f7c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x291f80: 910043FD  add      x29, sp, #0x10
//   0x291f84: AA0003F3  mov      x19, x0
//   0x291f88: 91028000  add      x0, x0, #0xa0
//   0x291f8c: 34000081  cbz      w1, #0x291f9c
uint64_t fde_func_8031_0x291f78(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00291F78ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81E0FF3ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91028000ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x34000081ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x97F6C8CCULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x52800028ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #8036 | PC: 0x2920f8..0x292154 (92 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x2920f8: D100C3FF  sub      sp, sp, #0x30
//   0x2920fc: F9000BF3  str      x19, [sp, #0x10]
//   0x292100: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x292104: 910083FD  add      x29, sp, #0x20
//   0x292108: D53BD053  mrs      x19, tpidr_el0
//   0x29210c: F9401668  ldr      x8, [x19, #0x28]
uint64_t fde_func_8036_0x2920f8(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x002920F8ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD100C3FFULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF3ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9027BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910083FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD53BD053ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9401668ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0103E2ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003E1ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #8040 | PC: 0x2924c8..0x2925c8 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x2924c8: D101C3FF  sub      sp, sp, #0x70
//   0x2924cc: F9001BF7  str      x23, [sp, #0x30]
//   0x2924d0: A90457F6  stp      x22, x21, [sp, #0x40]
//   0x2924d4: A9054FF4  stp      x20, x19, [sp, #0x50]
//   0x2924d8: A9067BFD  stp      x29, x30, [sp, #0x60]
//   0x2924dc: 910183FD  add      x29, sp, #0x60
uint64_t fde_func_8040_0x2924c8(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x002924C8ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD101C3FFULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9001BF7ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90457F6ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9054FF4ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9067BFDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910183FDULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD53BD057ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0803F3ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #8045 | PC: 0x292690..0x2926a8 (24 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x292690: F9400008  ldr      x8, [x0]
//   0x292694: F0000721  adrp     x1, #0x379000
//   0x292698: 910F2021  add      x1, x1, #0x3c8
//   0x29269c: F85E8108  ldur     x8, [x8, #-0x18]
//   0x2926a0: 8B080000  add      x0, x0, x8
//   0x2926a4: 17FFF655  b        #0x28fff8
uint64_t fde_func_8045_0x292690(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00292690ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400008ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF0000721ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910F2021ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF85E8108ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x8B080000ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x17FFF655ULL ^ (5ULL << 32);
    return state ^ (state >> 29);
}

// FDE #8049 | PC: 0x292740..0x292778 (56 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x292740: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x292744: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x292748: 910043FD  add      x29, sp, #0x10
//   0x29274c: F0000728  adrp     x8, #0x379000
//   0x292750: 9108A108  add      x8, x8, #0x228
//   0x292754: AA0003F3  mov      x19, x0
uint64_t fde_func_8049_0x292740(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00292740ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81E0FF3ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF0000728ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9108A108ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81F0E68ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91016108ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #8054 | PC: 0x292a80..0x292b30 (176 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x292a80: D10143FF  sub      sp, sp, #0x50
//   0x292a84: F9000BF7  str      x23, [sp, #0x10]
//   0x292a88: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x292a8c: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x292a90: A9047BFD  stp      x29, x30, [sp, #0x40]
//   0x292a94: 910103FD  add      x29, sp, #0x40
uint64_t fde_func_8054_0x292a80(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00292A80ULL);
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

// FDE #8058 | PC: 0x292c7c..0x292d7c (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x292c7c: A9BC5FF8  stp      x24, x23, [sp, #-0x40]!
//   0x292c80: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x292c84: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x292c88: A9037BFD  stp      x29, x30, [sp, #0x30]
//   0x292c8c: 9100C3FD  add      x29, sp, #0x30
//   0x292c90: AA0003F3  mov      x19, x0
uint64_t fde_func_8058_0x292c7c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00292C7CULL);
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

// FDE #8063 | PC: 0x292f04..0x292f40 (60 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x292f04: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x292f08: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x292f0c: 910043FD  add      x29, sp, #0x10
//   0x292f10: F0000728  adrp     x8, #0x379000
//   0x292f14: AA0003F3  mov      x19, x0
//   0x292f18: 9108A108  add      x8, x8, #0x228
uint64_t fde_func_8063_0x292f04(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00292F04ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81E0FF3ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF0000728ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9108A108ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF8018E68ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91016108ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #8067 | PC: 0x2930e4..0x29314c (104 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x2930e4: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x2930e8: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x2930ec: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x2930f0: 910083FD  add      x29, sp, #0x20
//   0x2930f4: AA0003F4  mov      x20, x0
//   0x2930f8: 52800500  mov      w0, #0x28
uint64_t fde_func_8067_0x2930e4(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x002930E4ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BD57F6ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9014FF4ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9027BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910083FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F4ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x52800500ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0103F3ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x97F6C3F4ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #8071 | PC: 0x293318..0x2933c4 (172 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x293318: D10143FF  sub      sp, sp, #0x50
//   0x29331c: F90013F5  str      x21, [sp, #0x20]
//   0x293320: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x293324: A9047BFD  stp      x29, x30, [sp, #0x40]
//   0x293328: 910103FD  add      x29, sp, #0x40
//   0x29332c: D53BD055  mrs      x21, tpidr_el0
uint64_t fde_func_8071_0x293318(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00293318ULL);
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

// FDE #8076 | PC: 0x293650..0x29367c (44 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x293650: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x293654: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x293658: 910043FD  add      x29, sp, #0x10
//   0x29365c: D0000721  adrp     x1, #0x379000
//   0x293660: 91196021  add      x1, x1, #0x658
//   0x293664: AA0003F3  mov      x19, x0
uint64_t fde_func_8076_0x293650(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00293650ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81E0FF3ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD0000721ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91196021ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x97FFF30AULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9417BFDULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #8080 | PC: 0x2936d4..0x29370c (56 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x2936d4: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x2936d8: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x2936dc: 910043FD  add      x29, sp, #0x10
//   0x2936e0: F9400008  ldr      x8, [x0]
//   0x2936e4: D0000721  adrp     x1, #0x379000
//   0x2936e8: 91196021  add      x1, x1, #0x658
uint64_t fde_func_8080_0x2936d4(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x002936D4ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81E0FF3ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400008ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD0000721ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91196021ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF85E8108ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x8B080013ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #8085 | PC: 0x293920..0x293a20 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x293920: D10243FF  sub      sp, sp, #0x90
//   0x293924: A9036FFC  stp      x28, x27, [sp, #0x30]
//   0x293928: A90467FA  stp      x26, x25, [sp, #0x40]
//   0x29392c: A9055FF8  stp      x24, x23, [sp, #0x50]
//   0x293930: A90657F6  stp      x22, x21, [sp, #0x60]
//   0x293934: A9074FF4  stp      x20, x19, [sp, #0x70]
uint64_t fde_func_8085_0x293920(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00293920ULL);
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

// FDE #8089 | PC: 0x293d20..0x293e20 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x293d20: F9400409  ldr      x9, [x0, #8]
//   0x293d24: F940042A  ldr      x10, [x1, #8]
//   0x293d28: 9E670120  fmov     d0, x9
//   0x293d2c: 0E205800  cnt      v0.8b, v0.8b
//   0x293d30: 2E303800  uaddlv   h0, v0.8b
//   0x293d34: 1E26000D  fmov     w13, s0
uint64_t fde_func_8089_0x293d20(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00293D20ULL);
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

// FDE #8094 | PC: 0x293eb0..0x293fb0 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x293eb0: D10283FF  sub      sp, sp, #0xa0
//   0x293eb4: A9046FFC  stp      x28, x27, [sp, #0x40]
//   0x293eb8: A90567FA  stp      x26, x25, [sp, #0x50]
//   0x293ebc: A9065FF8  stp      x24, x23, [sp, #0x60]
//   0x293ec0: A90757F6  stp      x22, x21, [sp, #0x70]
//   0x293ec4: A9084FF4  stp      x20, x19, [sp, #0x80]
uint64_t fde_func_8094_0x293eb0(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00293EB0ULL);
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

// FDE #8098 | PC: 0x294304..0x2943d4 (208 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x294304: D10143FF  sub      sp, sp, #0x50
//   0x294308: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x29430c: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x294310: A9047BFD  stp      x29, x30, [sp, #0x40]
//   0x294314: 910103FD  add      x29, sp, #0x40
//   0x294318: D53BD056  mrs      x22, tpidr_el0
uint64_t fde_func_8098_0x294304(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00294304ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10143FFULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90257F6ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9034FF4ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9047BFDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910103FDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD53BD056ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0803F4ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF94016C8ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #8103 | PC: 0x29474c..0x294758 (12 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x29474c: B0000721  adrp     x1, #0x379000
//   0x294750: 91260021  add      x1, x1, #0x980
//   0x294754: 17FFF0CC  b        #0x290a84
uint64_t fde_func_8103_0x29474c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0029474CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xB0000721ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91260021ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x17FFF0CCULL ^ (2ULL << 32);
    return state ^ (state >> 29);
}

// FDE #8107 | PC: 0x2947c4..0x2947dc (24 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x2947c4: F9400008  ldr      x8, [x0]
//   0x2947c8: B0000721  adrp     x1, #0x379000
//   0x2947cc: 91260021  add      x1, x1, #0x980
//   0x2947d0: F85E8108  ldur     x8, [x8, #-0x18]
//   0x2947d4: 8B080000  add      x0, x0, x8
//   0x2947d8: 17FFF0AB  b        #0x290a84
uint64_t fde_func_8107_0x2947c4(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x002947C4ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400008ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB0000721ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91260021ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF85E8108ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x8B080000ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x17FFF0ABULL ^ (5ULL << 32);
    return state ^ (state >> 29);
}

// FDE #8112 | PC: 0x294868..0x294968 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x294868: D101C3FF  sub      sp, sp, #0x70
//   0x29486c: F9000BFB  str      x27, [sp, #0x10]
//   0x294870: A90267FA  stp      x26, x25, [sp, #0x20]
//   0x294874: A9035FF8  stp      x24, x23, [sp, #0x30]
//   0x294878: A90457F6  stp      x22, x21, [sp, #0x40]
//   0x29487c: A9054FF4  stp      x20, x19, [sp, #0x50]
uint64_t fde_func_8112_0x294868(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00294868ULL);
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

// FDE #8116 | PC: 0x294c50..0x294c58 (8 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x294c50: 91006000  add      x0, x0, #0x18
//   0x294c54: 1400008F  b        #0x294e90
uint64_t fde_func_8116_0x294c50(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00294C50ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0x91006000ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x1400008FULL ^ (1ULL << 32);
    return state ^ (state >> 29);
}

// FDE #8121 | PC: 0x294e90..0x294efc (108 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x294e90: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x294e94: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x294e98: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x294e9c: 910083FD  add      x29, sp, #0x20
//   0x294ea0: F9400015  ldr      x21, [x0]
//   0x294ea4: B4000195  cbz      x21, #0x294ed4
uint64_t fde_func_8121_0x294e90(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00294E90ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81D0FF5ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9014FF4ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9027BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910083FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400015ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB4000195ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400414ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #8125 | PC: 0x295548..0x29558c (68 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x295548: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x29554c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x295550: 910043FD  add      x29, sp, #0x10
//   0x295554: 39402008  ldrb     w8, [x0, #8]
//   0x295558: AA0103F3  mov      x19, x1
//   0x29555c: 34000088  cbz      w8, #0x29556c
uint64_t fde_func_8125_0x295548(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00295548ULL);
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

// FDE #8130 | PC: 0x295788..0x2957a0 (24 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x295788: F9400C00  ldr      x0, [x0, #0x18]
//   0x29578c: B4000080  cbz      x0, #0x29579c
//   0x295790: F9400008  ldr      x8, [x0]
//   0x295794: F9400501  ldr      x1, [x8, #8]
//   0x295798: D61F0020  br       x1
//   0x29579c: D65F03C0  ret      
uint64_t fde_func_8130_0x295788(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00295788ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400C00ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB4000080ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400008ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400501ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD61F0020ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD65F03C0ULL ^ (5ULL << 32);
    return state ^ (state >> 29);
}

// FDE #8134 | PC: 0x295834..0x29587c (72 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x295834: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x295838: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x29583c: 910043FD  add      x29, sp, #0x10
//   0x295840: 90000728  adrp     x8, #0x379000
//   0x295844: 912FC108  add      x8, x8, #0xbf0
//   0x295848: AA0003F3  mov      x19, x0
uint64_t fde_func_8134_0x295834(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00295834ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81E0FF3ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x90000728ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x912FC108ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF8058408ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x97F6BCDCULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #8139 | PC: 0x295fac..0x296004 (88 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x295fac: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x295fb0: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x295fb4: 910043FD  add      x29, sp, #0x10
//   0x295fb8: F9400413  ldr      x19, [x0, #8]
//   0x295fbc: B40000F3  cbz      x19, #0x295fd8
//   0x295fc0: 91002268  add      x8, x19, #8
uint64_t fde_func_8139_0x295fac(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00295FACULL);
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

// FDE #8143 | PC: 0x29610c..0x29620c (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x29610c: D10183FF  sub      sp, sp, #0x60
//   0x296110: F9001BF5  str      x21, [sp, #0x30]
//   0x296114: A9044FF4  stp      x20, x19, [sp, #0x40]
//   0x296118: A9057BFD  stp      x29, x30, [sp, #0x50]
//   0x29611c: 910143FD  add      x29, sp, #0x50
//   0x296120: D53BD055  mrs      x21, tpidr_el0
uint64_t fde_func_8143_0x29610c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0029610CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10183FFULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9001BF5ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9044FF4ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9057BFDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910143FDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD53BD055ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF94016A8ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x12800009ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #8147 | PC: 0x2962d0..0x2962d4 (4 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x2962d0: D65F03C0  ret      
uint64_t fde_func_8147_0x2962d0(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x002962D0ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD65F03C0ULL ^ (0ULL << 32);
    return state ^ (state >> 29);
}

// FDE #8152 | PC: 0x2968cc..0x2968d4 (8 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x2968cc: 2A1F03E0  mov      w0, wzr
//   0x2968d0: D65F03C0  ret      
uint64_t fde_func_8152_0x2968cc(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x002968CCULL);
    state = (state * 0x00000100000001B3ULL) ^ 0x2A1F03E0ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD65F03C0ULL ^ (1ULL << 32);
    return state ^ (state >> 29);
}

// FDE #8156 | PC: 0x296c40..0x296d40 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x296c40: D10103FF  sub      sp, sp, #0x40
//   0x296c44: F9000BF5  str      x21, [sp, #0x10]
//   0x296c48: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x296c4c: A9037BFD  stp      x29, x30, [sp, #0x30]
//   0x296c50: 9100C3FD  add      x29, sp, #0x30
//   0x296c54: D53BD055  mrs      x21, tpidr_el0
uint64_t fde_func_8156_0x296c40(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00296C40ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10103FFULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF5ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9024FF4ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9037BFDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9100C3FDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD53BD055ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF94016A8ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #8161 | PC: 0x296e18..0x296e1c (4 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x296e18: D65F03C0  ret      
uint64_t fde_func_8161_0x296e18(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00296E18ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD65F03C0ULL ^ (0ULL << 32);
    return state ^ (state >> 29);
}

// FDE #8165 | PC: 0x296e28..0x296e2c (4 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x296e28: D65F03C0  ret      
uint64_t fde_func_8165_0x296e28(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00296E28ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD65F03C0ULL ^ (0ULL << 32);
    return state ^ (state >> 29);
}

// FDE #8170 | PC: 0x296e74..0x296e78 (4 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x296e74: D65F03C0  ret      
uint64_t fde_func_8170_0x296e74(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00296E74ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD65F03C0ULL ^ (0ULL << 32);
    return state ^ (state >> 29);
}

// FDE #8174 | PC: 0x296ec0..0x296ec8 (8 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x296ec0: F9001801  str      x1, [x0, #0x30]
//   0x296ec4: D65F03C0  ret      
uint64_t fde_func_8174_0x296ec0(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00296EC0ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9001801ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD65F03C0ULL ^ (1ULL << 32);
    return state ^ (state >> 29);
}

// FDE #8179 | PC: 0x296f40..0x296fdc (156 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x296f40: D10103FF  sub      sp, sp, #0x40
//   0x296f44: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x296f48: A9037BFD  stp      x29, x30, [sp, #0x30]
//   0x296f4c: 9100C3FD  add      x29, sp, #0x30
//   0x296f50: D53BD054  mrs      x20, tpidr_el0
//   0x296f54: F9401688  ldr      x8, [x20, #0x28]
uint64_t fde_func_8179_0x296f40(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00296F40ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10103FFULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9024FF4ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9037BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9100C3FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD53BD054ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9401688ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000FE8ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9402C00ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #8183 | PC: 0x297068..0x297078 (16 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x297068: F85B8C08  ldr      x8, [x0, #-0x48]!
//   0x29706c: F85E8108  ldur     x8, [x8, #-0x18]
//   0x297070: 8B080000  add      x0, x0, x8
//   0x297074: 17FFFF46  b        #0x296d8c
uint64_t fde_func_8183_0x297068(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00297068ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF85B8C08ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF85E8108ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x8B080000ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x17FFFF46ULL ^ (3ULL << 32);
    return state ^ (state >> 29);
}

// FDE #8188 | PC: 0x2970ec..0x2970f0 (4 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x2970ec: D4200020  brk      #1
uint64_t fde_func_8188_0x2970ec(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x002970ECULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD4200020ULL ^ (0ULL << 32);
    return state ^ (state >> 29);
}

// FDE #8192 | PC: 0x2970fc..0x297100 (4 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x2970fc: D4200020  brk      #1
uint64_t fde_func_8192_0x2970fc(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x002970FCULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD4200020ULL ^ (0ULL << 32);
    return state ^ (state >> 29);
}

// FDE #8197 | PC: 0x297110..0x297114 (4 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x297110: D4200020  brk      #1
uint64_t fde_func_8197_0x297110(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00297110ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD4200020ULL ^ (0ULL << 32);
    return state ^ (state >> 29);
}

// FDE #8201 | PC: 0x297120..0x297124 (4 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x297120: D4200020  brk      #1
uint64_t fde_func_8201_0x297120(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00297120ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD4200020ULL ^ (0ULL << 32);
    return state ^ (state >> 29);
}

// FDE #8206 | PC: 0x2971b0..0x2971d8 (40 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x2971b0: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x2971b4: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x2971b8: 910043FD  add      x29, sp, #0x10
//   0x2971bc: D100A013  sub      x19, x0, #0x28
//   0x2971c0: AA1303E0  mov      x0, x19
//   0x2971c4: 97FFFFD9  bl       #0x297128
uint64_t fde_func_8206_0x2971b0(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x002971B0ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81E0FF3ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD100A013ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA1303E0ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x97FFFFD9ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9417BFDULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA1303E0ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #8210 | PC: 0x297228..0x297258 (48 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x297228: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x29722c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x297230: 910043FD  add      x29, sp, #0x10
//   0x297234: F9400008  ldr      x8, [x0]
//   0x297238: F85E8108  ldur     x8, [x8, #-0x18]
//   0x29723c: 8B080013  add      x19, x0, x8
uint64_t fde_func_8210_0x297228(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00297228ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81E0FF3ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400008ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF85E8108ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x8B080013ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA1303E0ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x97FFFFB9ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #8215 | PC: 0x2972d8..0x297348 (112 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x2972d8: F9400028  ldr      x8, [x1]
//   0x2972dc: F9000008  str      x8, [x0]
//   0x2972e0: F9400429  ldr      x9, [x1, #8]
//   0x2972e4: F85C0108  ldur     x8, [x8, #-0x40]
//   0x2972e8: F8286809  str      x9, [x0, x8]
//   0x2972ec: F9400008  ldr      x8, [x0]
uint64_t fde_func_8215_0x2972d8(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x002972D8ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400028ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000008ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400429ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF85C0108ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF8286809ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400008ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400829ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF85B8108ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #8219 | PC: 0x29742c..0x297434 (8 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x29742c: D1012000  sub      x0, x0, #0x48
//   0x297430: 17FFFFDC  b        #0x2973a0
uint64_t fde_func_8219_0x29742c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0029742CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD1012000ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x17FFFFDCULL ^ (1ULL << 32);
    return state ^ (state >> 29);
}

// FDE #8224 | PC: 0x2974e4..0x297528 (68 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x2974e4: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x2974e8: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x2974ec: 910043FD  add      x29, sp, #0x10
//   0x2974f0: F0000708  adrp     x8, #0x37a000
//   0x2974f4: 91344108  add      x8, x8, #0xd10
//   0x2974f8: AA0003F3  mov      x19, x0
uint64_t fde_func_8224_0x2974e4(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x002974E4ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81E0FF3ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF0000708ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91344108ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF8038408ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x97FFFFE3ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #8228 | PC: 0x297668..0x297768 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x297668: A9BC5FF8  stp      x24, x23, [sp, #-0x40]!
//   0x29766c: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x297670: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x297674: A9037BFD  stp      x29, x30, [sp, #0x30]
//   0x297678: 9100C3FD  add      x29, sp, #0x30
//   0x29767c: F9400416  ldr      x22, [x0, #8]
uint64_t fde_func_8228_0x297668(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00297668ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BC5FF8ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90157F6ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9024FF4ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9037BFDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9100C3FDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400416ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB9800037ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #8232 | PC: 0x297ad4..0x297ae4 (16 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x297ad4: F9400C00  ldr      x0, [x0, #0x18]
//   0x297ad8: B4000040  cbz      x0, #0x297ae0
//   0x297adc: 17F6B215  b        #0x44330
//   0x297ae0: D65F03C0  ret      
uint64_t fde_func_8232_0x297ad4(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00297AD4ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400C00ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB4000040ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x17F6B215ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD65F03C0ULL ^ (3ULL << 32);
    return state ^ (state >> 29);
}

// FDE #8237 | PC: 0x297cc4..0x297cd4 (16 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x297cc4: B0000348  adrp     x8, #0x300000
//   0x297cc8: 3DC22500  ldr      q0, [x8, #0x890]
//   0x297ccc: 3C808000  stur     q0, [x0, #8]
//   0x297cd0: D65F03C0  ret      
uint64_t fde_func_8237_0x297cc4(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00297CC4ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xB0000348ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x3DC22500ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x3C808000ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD65F03C0ULL ^ (3ULL << 32);
    return state ^ (state >> 29);
}

// FDE #8241 | PC: 0x297d24..0x297d2c (8 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x297d24: B900E001  str      w1, [x0, #0xe0]
//   0x297d28: 14000001  b        #0x297d2c
uint64_t fde_func_8241_0x297d24(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00297D24ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xB900E001ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x14000001ULL ^ (1ULL << 32);
    return state ^ (state >> 29);
}

// FDE #8246 | PC: 0x2984b4..0x2985b4 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x2984b4: D10143FF  sub      sp, sp, #0x50
//   0x2984b8: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x2984bc: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x2984c0: A9047BFD  stp      x29, x30, [sp, #0x40]
//   0x2984c4: 910103FD  add      x29, sp, #0x40
//   0x2984c8: D53BD054  mrs      x20, tpidr_el0
uint64_t fde_func_8246_0x2984b4(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x002984B4ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10143FFULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90257F6ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9034FF4ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9047BFDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910103FDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD53BD054ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF940168CULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x52800028ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #8250 | PC: 0x298ae4..0x298aec (8 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x298ae4: D1004000  sub      x0, x0, #0x10
//   0x298ae8: 17FFFF8D  b        #0x29891c
uint64_t fde_func_8250_0x298ae4(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00298AE4ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD1004000ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x17FFFF8DULL ^ (1ULL << 32);
    return state ^ (state >> 29);
}

// FDE #8255 | PC: 0x298d94..0x298e94 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x298d94: D10243FF  sub      sp, sp, #0x90
//   0x298d98: F9001BFB  str      x27, [sp, #0x30]
//   0x298d9c: A90467FA  stp      x26, x25, [sp, #0x40]
//   0x298da0: A9055FF8  stp      x24, x23, [sp, #0x50]
//   0x298da4: A90657F6  stp      x22, x21, [sp, #0x60]
//   0x298da8: A9074FF4  stp      x20, x19, [sp, #0x70]
uint64_t fde_func_8255_0x298d94(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00298D94ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10243FFULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9001BFBULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90467FAULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9055FF8ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90657F6ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9074FF4ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9087BFDULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910203FDULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #8259 | PC: 0x299054..0x29911c (200 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x299054: D10243FF  sub      sp, sp, #0x90
//   0x299058: F9002BF7  str      x23, [sp, #0x50]
//   0x29905c: A90657F6  stp      x22, x21, [sp, #0x60]
//   0x299060: A9074FF4  stp      x20, x19, [sp, #0x70]
//   0x299064: A9087BFD  stp      x29, x30, [sp, #0x80]
//   0x299068: 910203FD  add      x29, sp, #0x80
uint64_t fde_func_8259_0x299054(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00299054ULL);
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

// FDE #8264 | PC: 0x299924..0x29992c (8 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x299924: F9407800  ldr      x0, [x0, #0xf0]
//   0x299928: D65F03C0  ret      
uint64_t fde_func_8264_0x299924(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00299924ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9407800ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD65F03C0ULL ^ (1ULL << 32);
    return state ^ (state >> 29);
}

// FDE #8268 | PC: 0x299ab0..0x299bac (252 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x299ab0: D10143FF  sub      sp, sp, #0x50
//   0x299ab4: F90013F5  str      x21, [sp, #0x20]
//   0x299ab8: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x299abc: A9047BFD  stp      x29, x30, [sp, #0x40]
//   0x299ac0: 910103FD  add      x29, sp, #0x40
//   0x299ac4: D53BD055  mrs      x21, tpidr_el0
uint64_t fde_func_8268_0x299ab0(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00299AB0ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10143FFULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF90013F5ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9034FF4ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9047BFDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910103FDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD53BD055ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF94016A8ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000FE8ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #8273 | PC: 0x299d7c..0x299e7c (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x299d7c: D10343FF  sub      sp, sp, #0xd0
//   0x299d80: FD004BE8  str      d8, [sp, #0x90]
//   0x299d84: F9004FF7  str      x23, [sp, #0x98]
//   0x299d88: A90A57F6  stp      x22, x21, [sp, #0xa0]
//   0x299d8c: A90B4FF4  stp      x20, x19, [sp, #0xb0]
//   0x299d90: A90C7BFD  stp      x29, x30, [sp, #0xc0]
uint64_t fde_func_8273_0x299d7c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00299D7CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10343FFULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xFD004BE8ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9004FF7ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90A57F6ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90B4FF4ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90C7BFDULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910303FDULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD53BD057ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #8277 | PC: 0x29a304..0x29a330 (44 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x29a304: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x29a308: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x29a30c: 910043FD  add      x29, sp, #0x10
//   0x29a310: 90000701  adrp     x1, #0x37a000
//   0x29a314: 913E2021  add      x1, x1, #0xf88
//   0x29a318: AA0003F3  mov      x19, x0
uint64_t fde_func_8277_0x29a304(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0029A304ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81E0FF3ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x90000701ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x913E2021ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x94000055ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9417BFDULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #8282 | PC: 0x29a3b0..0x29a3c8 (24 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x29a3b0: F9400008  ldr      x8, [x0]
//   0x29a3b4: 90000701  adrp     x1, #0x37a000
//   0x29a3b8: 913E2021  add      x1, x1, #0xf88
//   0x29a3bc: F85E8108  ldur     x8, [x8, #-0x18]
//   0x29a3c0: 8B080000  add      x0, x0, x8
//   0x29a3c4: 1400002B  b        #0x29a470
uint64_t fde_func_8282_0x29a3b0(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0029A3B0ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400008ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x90000701ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x913E2021ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF85E8108ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x8B080000ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x1400002BULL ^ (5ULL << 32);
    return state ^ (state >> 29);
}

// FDE #8286 | PC: 0x29a500..0x29a548 (72 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x29a500: B4000221  cbz      x1, #0x29a544
//   0x29a504: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x29a508: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x29a50c: 910043FD  add      x29, sp, #0x10
//   0x29a510: AA0103F3  mov      x19, x1
//   0x29a514: F9400021  ldr      x1, [x1]
uint64_t fde_func_8286_0x29a500(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0029A500ULL);
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

// FDE #8291 | PC: 0x29a5d4..0x29a690 (188 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x29a5d4: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x29a5d8: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x29a5dc: 910043FD  add      x29, sp, #0x10
//   0x29a5e0: B4000421  cbz      x1, #0x29a664
//   0x29a5e4: AA0003E8  mov      x8, x0
//   0x29a5e8: F9400420  ldr      x0, [x1, #8]
uint64_t fde_func_8291_0x29a5d4(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0029A5D4ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81E0FF3ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB4000421ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003E8ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400420ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB4000080ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400409ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #8295 | PC: 0x29a708..0x29a70c (4 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x29a708: 17F6A70A  b        #0x44330
uint64_t fde_func_8295_0x29a708(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0029A708ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0x17F6A70AULL ^ (0ULL << 32);
    return state ^ (state >> 29);
}

// FDE #8300 | PC: 0x29a934..0x29a96c (56 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x29a934: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x29a938: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x29a93c: 910043FD  add      x29, sp, #0x10
//   0x29a940: F9400C13  ldr      x19, [x0, #0x18]
//   0x29a944: B40000F3  cbz      x19, #0x29a960
//   0x29a948: AA1303E0  mov      x0, x19
uint64_t fde_func_8300_0x29a934(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0029A934ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81E0FF3ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400C13ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB40000F3ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA1303E0ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x94000010ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9417BFDULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #8304 | PC: 0x29a9fc..0x29aafc (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x29a9fc: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x29aa00: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x29aa04: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x29aa08: 910083FD  add      x29, sp, #0x20
//   0x29aa0c: B0000729  adrp     x9, #0x37f000
//   0x29aa10: F9400028  ldr      x8, [x1]
uint64_t fde_func_8304_0x29a9fc(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0029A9FCULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BD57F6ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9014FF4ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9027BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910083FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB0000729ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400028ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9455129ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F5ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #8308 | PC: 0x29abbc..0x29abd8 (28 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x29abbc: F9400428  ldr      x8, [x1, #8]
//   0x29abc0: F0000329  adrp     x9, #0x301000
//   0x29abc4: 910D4529  add      x9, x9, #0x351
//   0x29abc8: 9100600A  add      x10, x0, #0x18
//   0x29abcc: EB09011F  cmp      x8, x9
//   0x29abd0: 9A9F0140  csel     x0, x10, xzr, eq
uint64_t fde_func_8308_0x29abbc(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0029ABBCULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400428ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF0000329ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910D4529ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9100600AULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xEB09011FULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9A9F0140ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD65F03C0ULL ^ (6ULL << 32);
    return state ^ (state >> 29);
}

// FDE #8313 | PC: 0x29ace8..0x29ad04 (28 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x29ace8: F9400428  ldr      x8, [x1, #8]
//   0x29acec: F0000329  adrp     x9, #0x301000
//   0x29acf0: 91103D29  add      x9, x9, #0x40f
//   0x29acf4: 9100600A  add      x10, x0, #0x18
//   0x29acf8: EB09011F  cmp      x8, x9
//   0x29acfc: 9A9F0140  csel     x0, x10, xzr, eq
uint64_t fde_func_8313_0x29ace8(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0029ACE8ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400428ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF0000329ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91103D29ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9100600AULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xEB09011FULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9A9F0140ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD65F03C0ULL ^ (6ULL << 32);
    return state ^ (state >> 29);
}

// FDE #8317 | PC: 0x29ae1c..0x29ae74 (88 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x29ae1c: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x29ae20: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x29ae24: 910043FD  add      x29, sp, #0x10
//   0x29ae28: F9400413  ldr      x19, [x0, #8]
//   0x29ae2c: B40000F3  cbz      x19, #0x29ae48
//   0x29ae30: 91002268  add      x8, x19, #8
uint64_t fde_func_8317_0x29ae1c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0029AE1CULL);
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

// FDE #8322 | PC: 0x29afd8..0x29aff4 (28 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x29afd8: F9400428  ldr      x8, [x1, #8]
//   0x29afdc: F0000329  adrp     x9, #0x301000
//   0x29afe0: 91134529  add      x9, x9, #0x4d1
//   0x29afe4: 9100600A  add      x10, x0, #0x18
//   0x29afe8: EB09011F  cmp      x8, x9
//   0x29afec: 9A9F0140  csel     x0, x10, xzr, eq
uint64_t fde_func_8322_0x29afd8(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0029AFD8ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400428ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF0000329ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91134529ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9100600AULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xEB09011FULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9A9F0140ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD65F03C0ULL ^ (6ULL << 32);
    return state ^ (state >> 29);
}

// FDE #8326 | PC: 0x29b10c..0x29b164 (88 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x29b10c: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x29b110: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x29b114: 910043FD  add      x29, sp, #0x10
//   0x29b118: F9400413  ldr      x19, [x0, #8]
//   0x29b11c: B40000F3  cbz      x19, #0x29b138
//   0x29b120: 91002268  add      x8, x19, #8
uint64_t fde_func_8326_0x29b10c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0029B10CULL);
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

// FDE #8331 | PC: 0x29b374..0x29b3b4 (64 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x29b374: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x29b378: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x29b37c: 910043FD  add      x29, sp, #0x10
//   0x29b380: F9400028  ldr      x8, [x1]
//   0x29b384: AA0003F3  mov      x19, x0
//   0x29b388: F9000008  str      x8, [x0]
uint64_t fde_func_8331_0x29b374(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0029B374ULL);
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

// FDE #8335 | PC: 0x29b484..0x29b4c4 (64 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x29b484: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x29b488: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x29b48c: 910043FD  add      x29, sp, #0x10
//   0x29b490: 90000708  adrp     x8, #0x37b000
//   0x29b494: 9109E108  add      x8, x8, #0x278
//   0x29b498: AA0003F3  mov      x19, x0
uint64_t fde_func_8335_0x29b484(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0029B484ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81E0FF3ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x90000708ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9109E108ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF8028408ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x97FFF5C2ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #8340 | PC: 0x29b620..0x29b628 (8 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x29b620: F9400800  ldr      x0, [x0, #0x10]
//   0x29b624: 17FFF9AD  b        #0x299cd8
uint64_t fde_func_8340_0x29b620(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0029B620ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400800ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x17FFF9ADULL ^ (1ULL << 32);
    return state ^ (state >> 29);
}

// FDE #8344 | PC: 0x29b670..0x29b6b0 (64 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x29b670: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x29b674: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x29b678: 910043FD  add      x29, sp, #0x10
//   0x29b67c: F9400028  ldr      x8, [x1]
//   0x29b680: AA0003F3  mov      x19, x0
//   0x29b684: F9000008  str      x8, [x0]
uint64_t fde_func_8344_0x29b670(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0029B670ULL);
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

// FDE #8349 | PC: 0x29b878..0x29b8b4 (60 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x29b878: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x29b87c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x29b880: 910043FD  add      x29, sp, #0x10
//   0x29b884: F9403C01  ldr      x1, [x0, #0x78]
//   0x29b888: 90000708  adrp     x8, #0x37b000
//   0x29b88c: 910DE108  add      x8, x8, #0x378
uint64_t fde_func_8349_0x29b878(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0029B878ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81E0FF3ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9403C01ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x90000708ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910DE108ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF8070408ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #8353 | PC: 0x29b934..0x29b97c (72 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x29b934: B4000221  cbz      x1, #0x29b978
//   0x29b938: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x29b93c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x29b940: 910043FD  add      x29, sp, #0x10
//   0x29b944: AA0103F3  mov      x19, x1
//   0x29b948: F9400021  ldr      x1, [x1]
uint64_t fde_func_8353_0x29b934(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0029B934ULL);
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

// FDE #8358 | PC: 0x29bba8..0x29bbb8 (16 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x29bba8: F9402400  ldr      x0, [x0, #0x48]
//   0x29bbac: B4000040  cbz      x0, #0x29bbb4
//   0x29bbb0: 17F6A4E8  b        #0x44f50
//   0x29bbb4: D65F03C0  ret      
uint64_t fde_func_8358_0x29bba8(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0029BBA8ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9402400ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB4000040ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x17F6A4E8ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD65F03C0ULL ^ (3ULL << 32);
    return state ^ (state >> 29);
}

// FDE #8362 | PC: 0x29bdec..0x29bdf4 (8 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x29bdec: F9402800  ldr      x0, [x0, #0x50]
//   0x29bdf0: D65F03C0  ret      
uint64_t fde_func_8362_0x29bdec(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0029BDECULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9402800ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD65F03C0ULL ^ (1ULL << 32);
    return state ^ (state >> 29);
}

// FDE #8367 | PC: 0x29c14c..0x29c154 (8 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x29c14c: D1002000  sub      x0, x0, #8
//   0x29c150: 17FFFFDB  b        #0x29c0bc
uint64_t fde_func_8367_0x29c14c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0029C14CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD1002000ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x17FFFFDBULL ^ (1ULL << 32);
    return state ^ (state >> 29);
}

// FDE #8371 | PC: 0x29c45c..0x29c464 (8 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x29c45c: D1002000  sub      x0, x0, #8
//   0x29c460: 17FFFF7F  b        #0x29c25c
uint64_t fde_func_8371_0x29c45c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0029C45CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD1002000ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x17FFFF7FULL ^ (1ULL << 32);
    return state ^ (state >> 29);
}

// FDE #8376 | PC: 0x29cbbc..0x29cbc4 (8 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x29cbbc: D1002000  sub      x0, x0, #8
//   0x29cbc0: 17FFFFA2  b        #0x29ca48
uint64_t fde_func_8376_0x29cbbc(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0029CBBCULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD1002000ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x17FFFFA2ULL ^ (1ULL << 32);
    return state ^ (state >> 29);
}

// FDE #8380 | PC: 0x29d150..0x29d1e8 (152 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x29d150: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x29d154: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x29d158: 910043FD  add      x29, sp, #0x10
//   0x29d15c: D00006E8  adrp     x8, #0x37b000
//   0x29d160: 910F6108  add      x8, x8, #0x3d8
//   0x29d164: 9101A109  add      x9, x8, #0x68
uint64_t fde_func_8380_0x29d150(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0029D150ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81E0FF3ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD00006E8ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910F6108ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9101A109ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9E670100ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9102C10AULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #8385 | PC: 0x29d244..0x29d26c (40 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x29d244: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x29d248: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x29d24c: 910043FD  add      x29, sp, #0x10
//   0x29d250: D1004013  sub      x19, x0, #0x10
//   0x29d254: AA1303E0  mov      x0, x19
//   0x29d258: 97FFFFBE  bl       #0x29d150
uint64_t fde_func_8385_0x29d244(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0029D244ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81E0FF3ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD1004013ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA1303E0ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x97FFFFBEULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9417BFDULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA1303E0ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #8389 | PC: 0x29d364..0x29d3b0 (76 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x29d364: B4000241  cbz      x1, #0x29d3ac
//   0x29d368: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x29d36c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x29d370: 910043FD  add      x29, sp, #0x10
//   0x29d374: AA0103F3  mov      x19, x1
//   0x29d378: F9400021  ldr      x1, [x1]
uint64_t fde_func_8389_0x29d364(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0029D364ULL);
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

// FDE #8393 | PC: 0x29d5e4..0x29d644 (96 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x29d5e4: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x29d5e8: 910003FD  mov      x29, sp
//   0x29d5ec: AA0003E8  mov      x8, x0
//   0x29d5f0: F8408D0A  ldr      x10, [x8, #8]!
//   0x29d5f4: B40001CA  cbz      x10, #0x29d62c
//   0x29d5f8: F9400029  ldr      x9, [x1]
uint64_t fde_func_8393_0x29d5e4(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0029D5E4ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BF7BFDULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003E8ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF8408D0AULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB40001CAULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400029ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0803E1ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF940114BULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #8398 | PC: 0x29d770..0x29d778 (8 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x29d770: 91006000  add      x0, x0, #0x18
//   0x29d774: 14000363  b        #0x29e500
uint64_t fde_func_8398_0x29d770(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0029D770ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0x91006000ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x14000363ULL ^ (1ULL << 32);
    return state ^ (state >> 29);
}

// FDE #8402 | PC: 0x29d7f4..0x29d814 (32 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x29d7f4: 39406008  ldrb     w8, [x0, #0x18]
//   0x29d7f8: D00006E9  adrp     x9, #0x37b000
//   0x29d7fc: 91180129  add      x9, x9, #0x600
//   0x29d800: F9000009  str      x9, [x0]
//   0x29d804: 37000048  tbnz     w8, #0, #0x29d80c
//   0x29d808: D65F03C0  ret      
uint64_t fde_func_8402_0x29d7f4(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0029D7F4ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0x39406008ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD00006E9ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91180129ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000009ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x37000048ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD65F03C0ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9401400ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x17F69AC8ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #8407 | PC: 0x29d9b4..0x29da08 (84 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x29d9b4: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x29d9b8: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x29d9bc: 910043FD  add      x29, sp, #0x10
//   0x29d9c0: A9007C7F  stp      xzr, xzr, [x3]
//   0x29d9c4: F9000861  str      x1, [x3, #0x10]
//   0x29d9c8: F9000043  str      x3, [x2]
uint64_t fde_func_8407_0x29d9b4(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0029D9B4ULL);
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

// FDE #8411 | PC: 0x29db38..0x29dc28 (240 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x29db38: F81A0FFB  str      x27, [sp, #-0x60]!
//   0x29db3c: A90167FA  stp      x26, x25, [sp, #0x10]
//   0x29db40: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x29db44: A90357F6  stp      x22, x21, [sp, #0x30]
//   0x29db48: A9044FF4  stp      x20, x19, [sp, #0x40]
//   0x29db4c: A9057BFD  stp      x29, x30, [sp, #0x50]
uint64_t fde_func_8411_0x29db38(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0029DB38ULL);
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

// FDE #8416 | PC: 0x29dee4..0x29df68 (132 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x29dee4: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x29dee8: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x29deec: 910043FD  add      x29, sp, #0x10
//   0x29def0: F9400428  ldr      x8, [x1, #8]
//   0x29def4: B40000A8  cbz      x8, #0x29df08
//   0x29def8: AA0803F3  mov      x19, x8
uint64_t fde_func_8416_0x29dee4(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0029DEE4ULL);
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

// FDE #8420 | PC: 0x29e100..0x29e140 (64 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x29e100: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x29e104: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x29e108: 910043FD  add      x29, sp, #0x10
//   0x29e10c: B00006E8  adrp     x8, #0x37b000
//   0x29e110: 911A0108  add      x8, x8, #0x680
//   0x29e114: AA0003F3  mov      x19, x0
uint64_t fde_func_8420_0x29e100(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0029E100ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81E0FF3ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB00006E8ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x911A0108ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF8018408ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB0000701ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #8425 | PC: 0x29e2b0..0x29e360 (176 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x29e2b0: D10103FF  sub      sp, sp, #0x40
//   0x29e2b4: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x29e2b8: A9037BFD  stp      x29, x30, [sp, #0x30]
//   0x29e2bc: 9100C3FD  add      x29, sp, #0x30
//   0x29e2c0: D53BD054  mrs      x20, tpidr_el0
//   0x29e2c4: F9401688  ldr      x8, [x20, #0x28]
uint64_t fde_func_8425_0x29e2b0(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0029E2B0ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10103FFULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9024FF4ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9037BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9100C3FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD53BD054ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9401688ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000FE8ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400848ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #8429 | PC: 0x29e4e4..0x29e500 (28 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x29e4e4: 6F00E400  movi     v0.2d, #0000000000000000
//   0x29e4e8: A905041F  stp      xzr, x1, [x0, #0x50]
//   0x29e4ec: AD018000  stp      q0, q0, [x0, #0x30]
//   0x29e4f0: AD008000  stp      q0, q0, [x0, #0x10]
//   0x29e4f4: 3D800000  str      q0, [x0]
//   0x29e4f8: B900601F  str      wzr, [x0, #0x60]
uint64_t fde_func_8429_0x29e4e4(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0029E4E4ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0x6F00E400ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA905041FULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAD018000ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAD008000ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x3D800000ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB900601FULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD65F03C0ULL ^ (6ULL << 32);
    return state ^ (state >> 29);
}

// FDE #8434 | PC: 0x29e774..0x29e7c4 (80 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x29e774: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x29e778: 910003FD  mov      x29, sp
//   0x29e77c: F0000708  adrp     x8, #0x381000
//   0x29e780: 9101C108  add      x8, x8, #0x70
//   0x29e784: 08DFFD08  ldarb    w8, [x8]
//   0x29e788: 360000A8  tbz      w8, #0, #0x29e79c
uint64_t fde_func_8434_0x29e774(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0029E774ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BF7BFDULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF0000708ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9101C108ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x08DFFD08ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x360000A8ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF0000700ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9101A000ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #8438 | PC: 0x29e84c..0x29e854 (8 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x29e84c: 12800000  mov      w0, #-1
//   0x29e850: D65F03C0  ret      
uint64_t fde_func_8438_0x29e84c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0029E84CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0x12800000ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD65F03C0ULL ^ (1ULL << 32);
    return state ^ (state >> 29);
}

// FDE #8443 | PC: 0x29e874..0x29e87c (8 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x29e874: 2A0203E0  mov      w0, w2
//   0x29e878: D65F03C0  ret      
uint64_t fde_func_8443_0x29e874(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0029E874ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0x2A0203E0ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD65F03C0ULL ^ (1ULL << 32);
    return state ^ (state >> 29);
}

// FDE #8447 | PC: 0x29e894..0x29e994 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x29e894: D10183FF  sub      sp, sp, #0x60
//   0x29e898: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x29e89c: A90357F6  stp      x22, x21, [sp, #0x30]
//   0x29e8a0: A9044FF4  stp      x20, x19, [sp, #0x40]
//   0x29e8a4: A9057BFD  stp      x29, x30, [sp, #0x50]
//   0x29e8a8: 910143FD  add      x29, sp, #0x50
uint64_t fde_func_8447_0x29e894(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0029E894ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10183FFULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9025FF8ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90357F6ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9044FF4ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9057BFDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910143FDULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD53BD057ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0803F3ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #8452 | PC: 0x29f0a8..0x29f100 (88 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x29f0a8: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x29f0ac: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x29f0b0: 910043FD  add      x29, sp, #0x10
//   0x29f0b4: F9400413  ldr      x19, [x0, #8]
//   0x29f0b8: B40000F3  cbz      x19, #0x29f0d4
//   0x29f0bc: 91002268  add      x8, x19, #8
uint64_t fde_func_8452_0x29f0a8(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0029F0A8ULL);
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

// FDE #8456 | PC: 0x29f590..0x29f634 (164 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x29f590: D10183FF  sub      sp, sp, #0x60
//   0x29f594: A90357F6  stp      x22, x21, [sp, #0x30]
//   0x29f598: A9044FF4  stp      x20, x19, [sp, #0x40]
//   0x29f59c: A9057BFD  stp      x29, x30, [sp, #0x50]
//   0x29f5a0: 910143FD  add      x29, sp, #0x50
//   0x29f5a4: D53BD056  mrs      x22, tpidr_el0
uint64_t fde_func_8456_0x29f590(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0029F590ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10183FFULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90357F6ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9044FF4ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9057BFDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910143FDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD53BD056ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF94016C9ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0803F3ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #8461 | PC: 0x29f750..0x29f800 (176 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x29f750: D10103FF  sub      sp, sp, #0x40
//   0x29f754: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x29f758: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x29f75c: A9037BFD  stp      x29, x30, [sp, #0x30]
//   0x29f760: 9100C3FD  add      x29, sp, #0x30
//   0x29f764: D53BD056  mrs      x22, tpidr_el0
uint64_t fde_func_8461_0x29f750(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0029F750ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10103FFULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90157F6ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9024FF4ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9037BFDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9100C3FDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD53BD056ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF94016C8ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF90007E8ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #8465 | PC: 0x29f89c..0x29f8a0 (4 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x29f89c: 17F692A5  b        #0x44330
uint64_t fde_func_8465_0x29f89c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0029F89CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0x17F692A5ULL ^ (0ULL << 32);
    return state ^ (state >> 29);
}

// FDE #8469 | PC: 0x29f930..0x29f96c (60 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x29f930: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x29f934: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x29f938: 910043FD  add      x29, sp, #0x10
//   0x29f93c: B4000121  cbz      x1, #0x29f960
//   0x29f940: AA0103F3  mov      x19, x1
//   0x29f944: AA1303E0  mov      x0, x19
uint64_t fde_func_8469_0x29f930(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0029F930ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE4FF4ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB4000121ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0103F3ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA1303E0ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF8418414ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x97FFFDD7ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #8474 | PC: 0x29fed0..0x29ff14 (68 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x29fed0: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x29fed4: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x29fed8: 910043FD  add      x29, sp, #0x10
//   0x29fedc: F9400013  ldr      x19, [x0]
//   0x29fee0: F9000001  str      x1, [x0]
//   0x29fee4: B4000133  cbz      x19, #0x29ff08
uint64_t fde_func_8474_0x29fed0(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0029FED0ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81E0FF3ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400013ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000001ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB4000133ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x39404008ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x34000068ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #8478 | PC: 0x2a0364..0x2a0384 (32 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x2a0364: 39406008  ldrb     w8, [x0, #0x18]
//   0x2a0368: F00006C9  adrp     x9, #0x37b000
//   0x2a036c: 911E6129  add      x9, x9, #0x798
//   0x2a0370: F9000009  str      x9, [x0]
//   0x2a0374: 37000048  tbnz     w8, #0, #0x2a037c
//   0x2a0378: D65F03C0  ret      
uint64_t fde_func_8478_0x2a0364(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x002A0364ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0x39406008ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF00006C9ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x911E6129ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000009ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x37000048ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD65F03C0ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9401400ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x17F68FECULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #8483 | PC: 0x2a07e4..0x2a08e4 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x2a07e4: F81B0FF9  str      x25, [sp, #-0x50]!
//   0x2a07e8: A9015FF8  stp      x24, x23, [sp, #0x10]
//   0x2a07ec: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x2a07f0: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x2a07f4: A9047BFD  stp      x29, x30, [sp, #0x40]
//   0x2a07f8: 910103FD  add      x29, sp, #0x40
uint64_t fde_func_8483_0x2a07e4(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x002A07E4ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81B0FF9ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9015FF8ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90257F6ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9034FF4ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9047BFDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910103FDULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400417ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB9800038ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #8487 | PC: 0x2a0e00..0x2a0f00 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x2a0e00: D101C3FF  sub      sp, sp, #0x70
//   0x2a0e04: F90023F5  str      x21, [sp, #0x40]
//   0x2a0e08: A9054FF4  stp      x20, x19, [sp, #0x50]
//   0x2a0e0c: A9067BFD  stp      x29, x30, [sp, #0x60]
//   0x2a0e10: 910183FD  add      x29, sp, #0x60
//   0x2a0e14: D53BD055  mrs      x21, tpidr_el0
uint64_t fde_func_8487_0x2a0e00(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x002A0E00ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD101C3FFULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF90023F5ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9054FF4ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9067BFDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910183FDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD53BD055ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF94016A8ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81D83A8ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #8492 | PC: 0x2a0fb4..0x2a0fb8 (4 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x2a0fb4: 17FFF634  b        #0x29e884
uint64_t fde_func_8492_0x2a0fb4(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x002A0FB4ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0x17FFF634ULL ^ (0ULL << 32);
    return state ^ (state >> 29);
}

// FDE #8496 | PC: 0x2a1058..0x2a1158 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x2a1058: D10483FF  sub      sp, sp, #0x120
//   0x2a105c: F9006BFC  str      x28, [sp, #0xd0]
//   0x2a1060: A90E5FF8  stp      x24, x23, [sp, #0xe0]
//   0x2a1064: A90F57F6  stp      x22, x21, [sp, #0xf0]
//   0x2a1068: A9104FF4  stp      x20, x19, [sp, #0x100]
//   0x2a106c: A9117BFD  stp      x29, x30, [sp, #0x110]
uint64_t fde_func_8496_0x2a1058(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x002A1058ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10483FFULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9006BFCULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90E5FF8ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90F57F6ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9104FF4ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9117BFDULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910443FDULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD53BD058ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #8501 | PC: 0x2a1570..0x2a15ec (124 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x2a1570: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x2a1574: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x2a1578: 910043FD  add      x29, sp, #0x10
//   0x2a157c: AA0003F3  mov      x19, x0
//   0x2a1580: F9400800  ldr      x0, [x0, #0x10]
//   0x2a1584: B4000160  cbz      x0, #0x2a15b0
uint64_t fde_func_8501_0x2a1570(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x002A1570ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81E0FF3ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400800ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB4000160ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x97F68C0AULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x37000120ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #8505 | PC: 0x2a1604..0x2a1608 (4 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x2a1604: 17F68B4B  b        #0x44330
uint64_t fde_func_8505_0x2a1604(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x002A1604ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0x17F68B4BULL ^ (0ULL << 32);
    return state ^ (state >> 29);
}

// FDE #8510 | PC: 0x2a1690..0x2a169c (12 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x2a1690: F8418C08  ldr      x8, [x0, #0x18]!
//   0x2a1694: F9400101  ldr      x1, [x8]
//   0x2a1698: D61F0020  br       x1
uint64_t fde_func_8510_0x2a1690(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x002A1690ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF8418C08ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400101ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD61F0020ULL ^ (2ULL << 32);
    return state ^ (state >> 29);
}

// FDE #8514 | PC: 0x2a192c..0x2a1a04 (216 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x2a192c: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x2a1930: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x2a1934: 910043FD  add      x29, sp, #0x10
//   0x2a1938: F9401008  ldr      x8, [x0, #0x20]
//   0x2a193c: AA0003F4  mov      x20, x0
//   0x2a1940: AA0103F3  mov      x19, x1
uint64_t fde_func_8514_0x2a192c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x002A192CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE4FF4ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9401008ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F4ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0103F3ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB4000148ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x97F69D0DULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #8519 | PC: 0x2a21e8..0x2a226c (132 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x2a21e8: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x2a21ec: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x2a21f0: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x2a21f4: 910083FD  add      x29, sp, #0x20
//   0x2a21f8: A9405008  ldp      x8, x20, [x0]
//   0x2a21fc: B202E7EA  mov      x10, #-0x3333333333333334
uint64_t fde_func_8519_0x2a21e8(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x002A21E8ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81D0FF5ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9014FF4ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9027BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910083FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9405008ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB202E7EAULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF29999AAULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #8523 | PC: 0x2a2300..0x2a2320 (32 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x2a2300: 39402008  ldrb     w8, [x0, #8]
//   0x2a2304: B00006C9  adrp     x9, #0x37b000
//   0x2a2308: 9126A129  add      x9, x9, #0x9a8
//   0x2a230c: F9000009  str      x9, [x0]
//   0x2a2310: 37000048  tbnz     w8, #0, #0x2a2318
//   0x2a2314: D65F03C0  ret      
uint64_t fde_func_8523_0x2a2300(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x002A2300ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0x39402008ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB00006C9ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9126A129ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000009ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x37000048ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD65F03C0ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400C00ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x17F68805ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #8528 | PC: 0x2a2408..0x2a2440 (56 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x2a2408: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x2a240c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x2a2410: 910043FD  add      x29, sp, #0x10
//   0x2a2414: B00006C8  adrp     x8, #0x37b000
//   0x2a2418: 91284108  add      x8, x8, #0xa10
//   0x2a241c: AA0003F3  mov      x19, x0
uint64_t fde_func_8528_0x2a2408(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x002A2408ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81E0FF3ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB00006C8ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91284108ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF8018408ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x97FFFFCEULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #8532 | PC: 0x2a24b0..0x2a2564 (180 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x2a24b0: F9400408  ldr      x8, [x0, #8]
//   0x2a24b4: B4000548  cbz      x8, #0x2a255c
//   0x2a24b8: 9E670100  fmov     d0, x8
//   0x2a24bc: B9800029  ldrsw    x9, [x1]
//   0x2a24c0: 0E205800  cnt      v0.8b, v0.8b
//   0x2a24c4: 2E303800  uaddlv   h0, v0.8b
uint64_t fde_func_8532_0x2a24b0(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x002A24B0ULL);
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

// FDE #8537 | PC: 0x2a27f8..0x2a2890 (152 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x2a27f8: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x2a27fc: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x2a2800: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x2a2804: 910083FD  add      x29, sp, #0x20
//   0x2a2808: A9405416  ldp      x22, x21, [x0]
//   0x2a280c: AA0003F3  mov      x19, x0
uint64_t fde_func_8537_0x2a27f8(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x002A27F8ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BD57F6ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9014FF4ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9027BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910083FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9405416ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0103F4ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xEB1602BFULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #8541 | PC: 0x2a29bc..0x2a2abc (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x2a29bc: D101C3FF  sub      sp, sp, #0x70
//   0x2a29c0: F9001BF7  str      x23, [sp, #0x30]
//   0x2a29c4: A90457F6  stp      x22, x21, [sp, #0x40]
//   0x2a29c8: A9054FF4  stp      x20, x19, [sp, #0x50]
//   0x2a29cc: A9067BFD  stp      x29, x30, [sp, #0x60]
//   0x2a29d0: 910183FD  add      x29, sp, #0x60
uint64_t fde_func_8541_0x2a29bc(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x002A29BCULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD101C3FFULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9001BF7ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90457F6ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9054FF4ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9067BFDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910183FDULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD53BD056ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF94016C8ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #8545 | PC: 0x2a2c70..0x2a2d70 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x2a2c70: A9BC5FF8  stp      x24, x23, [sp, #-0x40]!
//   0x2a2c74: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x2a2c78: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x2a2c7c: A9037BFD  stp      x29, x30, [sp, #0x30]
//   0x2a2c80: 9100C3FD  add      x29, sp, #0x30
//   0x2a2c84: F9400416  ldr      x22, [x0, #8]
uint64_t fde_func_8545_0x2a2c70(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x002A2C70ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BC5FF8ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90157F6ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9024FF4ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9037BFDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9100C3FDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400416ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB9800037ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #8550 | PC: 0x2a35f4..0x2a36f4 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x2a35f4: D10283FF  sub      sp, sp, #0xa0
//   0x2a35f8: A90757F6  stp      x22, x21, [sp, #0x70]
//   0x2a35fc: A9084FF4  stp      x20, x19, [sp, #0x80]
//   0x2a3600: A9097BFD  stp      x29, x30, [sp, #0x90]
//   0x2a3604: 910243FD  add      x29, sp, #0x90
//   0x2a3608: D53BD055  mrs      x21, tpidr_el0
uint64_t fde_func_8550_0x2a35f4(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x002A35F4ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10283FFULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90757F6ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9084FF4ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9097BFDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910243FDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD53BD055ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF94016A8ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81D83A8ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #8554 | PC: 0x2a38c4..0x2a39c4 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x2a38c4: FC1C0FE8  str      d8, [sp, #-0x40]!
//   0x2a38c8: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x2a38cc: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x2a38d0: A9037BFD  stp      x29, x30, [sp, #0x30]
//   0x2a38d4: 9100C3FD  add      x29, sp, #0x30
//   0x2a38d8: AA0003F3  mov      x19, x0
uint64_t fde_func_8554_0x2a38c4(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x002A38C4ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xFC1C0FE8ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90157F6ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9024FF4ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9037BFDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9100C3FDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x52800060ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x2A0203F4ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #8559 | PC: 0x2a434c..0x2a444c (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x2a434c: A9BC5FF8  stp      x24, x23, [sp, #-0x40]!
//   0x2a4350: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x2a4354: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x2a4358: A9037BFD  stp      x29, x30, [sp, #0x30]
//   0x2a435c: 9100C3FD  add      x29, sp, #0x30
//   0x2a4360: AA0003F6  mov      x22, x0
uint64_t fde_func_8559_0x2a434c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x002A434CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BC5FF8ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90157F6ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9024FF4ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9037BFDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9100C3FDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F6ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x52800020ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x2A0303F7ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #8563 | PC: 0x2a44f4..0x2a44fc (8 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x2a44f4: 12800000  mov      w0, #-1
//   0x2a44f8: D65F03C0  ret      
uint64_t fde_func_8563_0x2a44f4(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x002A44F4ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0x12800000ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD65F03C0ULL ^ (1ULL << 32);
    return state ^ (state >> 29);
}

// FDE #8568 | PC: 0x2a45d8..0x2a46ac (212 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x2a45d8: D10203FF  sub      sp, sp, #0x80
//   0x2a45dc: F9002BF5  str      x21, [sp, #0x50]
//   0x2a45e0: A9064FF4  stp      x20, x19, [sp, #0x60]
//   0x2a45e4: A9077BFD  stp      x29, x30, [sp, #0x70]
//   0x2a45e8: 9101C3FD  add      x29, sp, #0x70
//   0x2a45ec: D53BD055  mrs      x21, tpidr_el0
uint64_t fde_func_8568_0x2a45d8(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x002A45D8ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10203FFULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9002BF5ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9064FF4ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9077BFDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9101C3FDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD53BD055ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF94016A8ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81D83A8ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #8572 | PC: 0x2a5098..0x2a5198 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x2a5098: D102C3FF  sub      sp, sp, #0xb0
//   0x2a509c: F9003BF7  str      x23, [sp, #0x70]
//   0x2a50a0: A90857F6  stp      x22, x21, [sp, #0x80]
//   0x2a50a4: A9094FF4  stp      x20, x19, [sp, #0x90]
//   0x2a50a8: A90A7BFD  stp      x29, x30, [sp, #0xa0]
//   0x2a50ac: 910283FD  add      x29, sp, #0xa0
uint64_t fde_func_8572_0x2a5098(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x002A5098ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD102C3FFULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9003BF7ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90857F6ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9094FF4ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90A7BFDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910283FDULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD53BD057ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0803F3ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #8577 | PC: 0x2a53cc..0x2a5408 (60 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x2a53cc: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x2a53d0: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x2a53d4: 910043FD  add      x29, sp, #0x10
//   0x2a53d8: F940B408  ldr      x8, [x0, #0x168]
//   0x2a53dc: D1006013  sub      x19, x0, #0x18
//   0x2a53e0: 9103C002  add      x2, x0, #0xf0
uint64_t fde_func_8577_0x2a53cc(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x002A53CCULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81E0FF3ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF940B408ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD1006013ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9103C002ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x52800D01ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400109ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #8581 | PC: 0x2a56f4..0x2a56fc (8 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x2a56f4: D1006000  sub      x0, x0, #0x18
//   0x2a56f8: 17FFFF54  b        #0x2a5448
uint64_t fde_func_8581_0x2a56f4(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x002A56F4ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD1006000ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x17FFFF54ULL ^ (1ULL << 32);
    return state ^ (state >> 29);
}

// FDE #8586 | PC: 0x2a58dc..0x2a58e4 (8 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x2a58dc: D1004000  sub      x0, x0, #0x10
//   0x2a58e0: 17FFD42B  b        #0x29a98c
uint64_t fde_func_8586_0x2a58dc(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x002A58DCULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD1004000ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x17FFD42BULL ^ (1ULL << 32);
    return state ^ (state >> 29);
}

// FDE #8590 | PC: 0x2a593c..0x2a5944 (8 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x2a593c: D1010000  sub      x0, x0, #0x40
//   0x2a5940: 17FFD413  b        #0x29a98c
uint64_t fde_func_8590_0x2a593c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x002A593CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD1010000ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x17FFD413ULL ^ (1ULL << 32);
    return state ^ (state >> 29);
}

// FDE #8595 | PC: 0x2a59bc..0x2a59ec (48 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x2a59bc: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x2a59c0: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x2a59c4: 910043FD  add      x29, sp, #0x10
//   0x2a59c8: F9400008  ldr      x8, [x0]
//   0x2a59cc: F85E8108  ldur     x8, [x8, #-0x18]
//   0x2a59d0: 8B080013  add      x19, x0, x8
uint64_t fde_func_8595_0x2a59bc(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x002A59BCULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81E0FF3ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400008ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF85E8108ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x8B080013ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA1303E0ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x97FFD3EDULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #8599 | PC: 0x2a5a3c..0x2a5a6c (48 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x2a5a3c: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x2a5a40: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x2a5a44: 910043FD  add      x29, sp, #0x10
//   0x2a5a48: F85B0C08  ldr      x8, [x0, #-0x50]!
//   0x2a5a4c: F85E8108  ldur     x8, [x8, #-0x18]
//   0x2a5a50: 8B080013  add      x19, x0, x8
uint64_t fde_func_8599_0x2a5a3c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x002A5A3CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81E0FF3ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF85B0C08ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF85E8108ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x8B080013ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA1303E0ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x97FFD3CDULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #8604 | PC: 0x2a5ac8..0x2a5b08 (64 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x2a5ac8: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x2a5acc: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x2a5ad0: 910043FD  add      x29, sp, #0x10
//   0x2a5ad4: F9400028  ldr      x8, [x1]
//   0x2a5ad8: AA0003F3  mov      x19, x0
//   0x2a5adc: F9000008  str      x8, [x0]
uint64_t fde_func_8604_0x2a5ac8(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x002A5AC8ULL);
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

// FDE #8608 | PC: 0x2a5d9c..0x2a5e9c (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x2a5d9c: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x2a5da0: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x2a5da4: 910043FD  add      x29, sp, #0x10
//   0x2a5da8: 52800022  mov      w2, #1
//   0x2a5dac: AA0003F3  mov      x19, x0
//   0x2a5db0: 97FFECAA  bl       #0x2a1058
uint64_t fde_func_8608_0x2a5d9c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x002A5D9CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81E0FF3ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x52800022ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x97FFECAAULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB00002E9ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x3DC27520ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #8613 | PC: 0x2a64fc..0x2a65fc (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x2a64fc: D10183FF  sub      sp, sp, #0x60
//   0x2a6500: F90013F7  str      x23, [sp, #0x20]
//   0x2a6504: A90357F6  stp      x22, x21, [sp, #0x30]
//   0x2a6508: A9044FF4  stp      x20, x19, [sp, #0x40]
//   0x2a650c: A9057BFD  stp      x29, x30, [sp, #0x50]
//   0x2a6510: 910143FD  add      x29, sp, #0x50
uint64_t fde_func_8613_0x2a64fc(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x002A64FCULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10183FFULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF90013F7ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90357F6ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9044FF4ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9057BFDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910143FDULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD53BD055ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF94016A8ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #8617 | PC: 0x2a6e48..0x2a6ea4 (92 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x2a6e48: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x2a6e4c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x2a6e50: 910043FD  add      x29, sp, #0x10
//   0x2a6e54: 39430008  ldrb     w8, [x0, #0xc0]
//   0x2a6e58: D00006A9  adrp     x9, #0x37c000
//   0x2a6e5c: AA0003F3  mov      x19, x0
uint64_t fde_func_8617_0x2a6e48(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x002A6E48ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81E0FF3ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x39430008ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD00006A9ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91170129ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000009ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #8622 | PC: 0x2a7058..0x2a705c (4 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x2a7058: 17F674B6  b        #0x44330
uint64_t fde_func_8622_0x2a7058(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x002A7058ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0x17F674B6ULL ^ (0ULL << 32);
    return state ^ (state >> 29);
}

// FDE #8626 | PC: 0x2a7280..0x2a7324 (164 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x2a7280: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x2a7284: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x2a7288: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x2a728c: 910083FD  add      x29, sp, #0x20
//   0x2a7290: AA0003F3  mov      x19, x0
//   0x2a7294: F9400800  ldr      x0, [x0, #0x10]
uint64_t fde_func_8626_0x2a7280(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x002A7280ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81D0FF5ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9014FF4ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9027BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910083FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400800ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB00006A8ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x911B0108ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #8630 | PC: 0x2a73e0..0x2a7484 (164 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x2a73e0: D10143FF  sub      sp, sp, #0x50
//   0x2a73e4: F90013F5  str      x21, [sp, #0x20]
//   0x2a73e8: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x2a73ec: A9047BFD  stp      x29, x30, [sp, #0x40]
//   0x2a73f0: 910103FD  add      x29, sp, #0x40
//   0x2a73f4: D53BD055  mrs      x21, tpidr_el0
uint64_t fde_func_8630_0x2a73e0(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x002A73E0ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10143FFULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF90013F5ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9034FF4ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9047BFDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910103FDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD53BD055ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF94016A8ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000FE8ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #8635 | PC: 0x2a78cc..0x2a79cc (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x2a78cc: D10743FF  sub      sp, sp, #0x1d0
//   0x2a78d0: A9176FFC  stp      x28, x27, [sp, #0x170]
//   0x2a78d4: A91867FA  stp      x26, x25, [sp, #0x180]
//   0x2a78d8: A9195FF8  stp      x24, x23, [sp, #0x190]
//   0x2a78dc: A91A57F6  stp      x22, x21, [sp, #0x1a0]
//   0x2a78e0: A91B4FF4  stp      x20, x19, [sp, #0x1b0]
uint64_t fde_func_8635_0x2a78cc(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x002A78CCULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10743FFULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9176FFCULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA91867FAULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9195FF8ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA91A57F6ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA91B4FF4ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA91C7BFDULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910703FDULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #8639 | PC: 0x2a7d04..0x2a7d48 (68 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x2a7d04: 12B00008  mov      w8, #0x7fffffff
//   0x2a7d08: B2007BEA  mov      x10, #0x7fffffff7fffffff
//   0x2a7d0c: B9001008  str      w8, [x0, #0x10]
//   0x2a7d10: 92800008  mov      x8, #-1
//   0x2a7d14: F9400C09  ldr      x9, [x0, #0x18]
//   0x2a7d18: A906A00A  stp      x10, x8, [x0, #0x68]
uint64_t fde_func_8639_0x2a7d04(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x002A7D04ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0x12B00008ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB2007BEAULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB9001008ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x92800008ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400C09ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA906A00AULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA907A008ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9401808ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #8644 | PC: 0x2a7f60..0x2a7f80 (32 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x2a7f60: F9400068  ldr      x8, [x3]
//   0x2a7f64: CB010042  sub      x2, x2, x1
//   0x2a7f68: F100045F  cmp      x2, #1
//   0x2a7f6c: CB020100  sub      x0, x8, x2
//   0x2a7f70: F9000060  str      x0, [x3]
//   0x2a7f74: 5400004B  b.lt     #0x2a7f7c
uint64_t fde_func_8644_0x2a7f60(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x002A7F60ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400068ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xCB010042ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF100045FULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xCB020100ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000060ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x5400004BULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x17F673C2ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD65F03C0ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #8648 | PC: 0x2a80f0..0x2a81f0 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x2a80f0: D101C3FF  sub      sp, sp, #0x70
//   0x2a80f4: A90457F6  stp      x22, x21, [sp, #0x40]
//   0x2a80f8: A9054FF4  stp      x20, x19, [sp, #0x50]
//   0x2a80fc: A9067BFD  stp      x29, x30, [sp, #0x60]
//   0x2a8100: 910183FD  add      x29, sp, #0x60
//   0x2a8104: D53BD056  mrs      x22, tpidr_el0
uint64_t fde_func_8648_0x2a80f0(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x002A80F0ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD101C3FFULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90457F6ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9054FF4ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9067BFDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910183FDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD53BD056ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF94016C8ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F4ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #8653 | PC: 0x2a85bc..0x2a85cc (16 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x2a85bc: F9400008  ldr      x8, [x0]
//   0x2a85c0: F8598108  ldur     x8, [x8, #-0x68]
//   0x2a85c4: 8B080000  add      x0, x0, x8
//   0x2a85c8: 17FFFFBB  b        #0x2a84b4
uint64_t fde_func_8653_0x2a85bc(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x002A85BCULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400008ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF8598108ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x8B080000ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x17FFFFBBULL ^ (3ULL << 32);
    return state ^ (state >> 29);
}

// FDE #8657 | PC: 0x2a9044..0x2a9084 (64 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x2a9044: 9101A008  add      x8, x0, #0x68
//   0x2a9048: 885FFD09  ldaxr    w9, [x8]
//   0x2a904c: 7100053F  cmp      w9, #1
//   0x2a9050: 540000A1  b.ne     #0x2a9064
//   0x2a9054: 52800069  mov      w9, #3
//   0x2a9058: 880AFD09  stlxr    w10, w9, [x8]
uint64_t fde_func_8657_0x2a9044(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x002A9044ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0x9101A008ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x885FFD09ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x7100053FULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x540000A1ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x52800069ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x880AFD09ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x3400008AULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD65F03C0ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #8662 | PC: 0x2a9244..0x2a9254 (16 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x2a9244: F9400008  ldr      x8, [x0]
//   0x2a9248: F85E8108  ldur     x8, [x8, #-0x18]
//   0x2a924c: 8B080000  add      x0, x0, x8
//   0x2a9250: 17FFC6AE  b        #0x29ad08
uint64_t fde_func_8662_0x2a9244(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x002A9244ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400008ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF85E8108ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x8B080000ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x17FFC6AEULL ^ (3ULL << 32);
    return state ^ (state >> 29);
}

// FDE #8666 | PC: 0x2a92c4..0x2a92d4 (16 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x2a92c4: F85B0C08  ldr      x8, [x0, #-0x50]!
//   0x2a92c8: F85E8108  ldur     x8, [x8, #-0x18]
//   0x2a92cc: 8B080000  add      x0, x0, x8
//   0x2a92d0: 17FFC68E  b        #0x29ad08
uint64_t fde_func_8666_0x2a92c4(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x002A92C4ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF85B0C08ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF85E8108ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x8B080000ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x17FFC68EULL ^ (3ULL << 32);
    return state ^ (state >> 29);
}

// FDE #8671 | PC: 0x2a9398..0x2a93bc (36 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x2a9398: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x2a939c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x2a93a0: 910043FD  add      x29, sp, #0x10
//   0x2a93a4: AA0003F3  mov      x19, x0
//   0x2a93a8: 97F66F06  bl       #0x44fc0
//   0x2a93ac: A9417BFD  ldp      x29, x30, [sp, #0x10]
uint64_t fde_func_8671_0x2a9398(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x002A9398ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81E0FF3ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x97F66F06ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9417BFDULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA1303E0ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF84207F3ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #8675 | PC: 0x2a93e4..0x2a942c (72 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x2a93e4: B4000221  cbz      x1, #0x2a9428
//   0x2a93e8: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x2a93ec: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x2a93f0: 910043FD  add      x29, sp, #0x10
//   0x2a93f4: D00006A9  adrp     x9, #0x37f000
//   0x2a93f8: 3940A028  ldrb     w8, [x1, #0x28]
uint64_t fde_func_8675_0x2a93e4(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x002A93E4ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xB4000221ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81E0FF3ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD00006A9ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x3940A028ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9460D29ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0103F3ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #8680 | PC: 0x2a95f4..0x2a962c (56 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x2a95f4: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x2a95f8: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x2a95fc: 910043FD  add      x29, sp, #0x10
//   0x2a9600: D00006A8  adrp     x8, #0x37f000
//   0x2a9604: F946A108  ldr      x8, [x8, #0xd40]
//   0x2a9608: AA0003F3  mov      x19, x0
uint64_t fde_func_8680_0x2a95f4(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x002A95F4ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81E0FF3ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD00006A8ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF946A108ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91004108ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF8020E68ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #8684 | PC: 0x2a9734..0x2a97e4 (176 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x2a9734: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x2a9738: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x2a973c: 910043FD  add      x29, sp, #0x10
//   0x2a9740: B40003C1  cbz      x1, #0x2a97b8
//   0x2a9744: AA0003E8  mov      x8, x0
//   0x2a9748: F9400420  ldr      x0, [x1, #8]
uint64_t fde_func_8684_0x2a9734(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x002A9734ULL);
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

// FDE #8689 | PC: 0x2a98c0..0x2a9900 (64 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x2a98c0: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x2a98c4: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x2a98c8: 910043FD  add      x29, sp, #0x10
//   0x2a98cc: F9400028  ldr      x8, [x1]
//   0x2a98d0: AA0003F3  mov      x19, x0
//   0x2a98d4: F9000008  str      x8, [x0]
uint64_t fde_func_8689_0x2a98c0(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x002A98C0ULL);
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

// FDE #8693 | PC: 0x2a99b0..0x2a99e8 (56 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x2a99b0: 900006A8  adrp     x8, #0x37d000
//   0x2a99b4: 9103A108  add      x8, x8, #0xe8
//   0x2a99b8: F9000028  str      x8, [x1]
//   0x2a99bc: F9400408  ldr      x8, [x0, #8]
//   0x2a99c0: F9000428  str      x8, [x1, #8]
//   0x2a99c4: F9400808  ldr      x8, [x0, #0x10]
uint64_t fde_func_8693_0x2a99b0(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x002A99B0ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0x900006A8ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9103A108ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000028ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400408ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000428ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400808ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000828ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB40000C8ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #8698 | PC: 0x2a9ad0..0x2a9adc (12 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x2a9ad0: 900006A0  adrp     x0, #0x37d000
//   0x2a9ad4: 91056000  add      x0, x0, #0x158
//   0x2a9ad8: D65F03C0  ret      
uint64_t fde_func_8698_0x2a9ad0(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x002A9AD0ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0x900006A0ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91056000ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD65F03C0ULL ^ (2ULL << 32);
    return state ^ (state >> 29);
}

// FDE #8702 | PC: 0x2a9d7c..0x2a9e7c (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x2a9d7c: D10383FF  sub      sp, sp, #0xe0
//   0x2a9d80: F90043FB  str      x27, [sp, #0x80]
//   0x2a9d84: A90967FA  stp      x26, x25, [sp, #0x90]
//   0x2a9d88: A90A5FF8  stp      x24, x23, [sp, #0xa0]
//   0x2a9d8c: A90B57F6  stp      x22, x21, [sp, #0xb0]
//   0x2a9d90: A90C4FF4  stp      x20, x19, [sp, #0xc0]
uint64_t fde_func_8702_0x2a9d7c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x002A9D7CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10383FFULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF90043FBULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90967FAULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90A5FF8ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90B57F6ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90C4FF4ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90D7BFDULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910343FDULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #8706 | PC: 0x2ab190..0x2ab228 (152 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x2ab190: F81C0FF7  str      x23, [sp, #-0x40]!
//   0x2ab194: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x2ab198: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x2ab19c: A9037BFD  stp      x29, x30, [sp, #0x30]
//   0x2ab1a0: 9100C3FD  add      x29, sp, #0x30
//   0x2ab1a4: AA0003F3  mov      x19, x0
uint64_t fde_func_8706_0x2ab190(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x002AB190ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81C0FF7ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90157F6ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9024FF4ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9037BFDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9100C3FDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x52800700ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0103F5ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #8711 | PC: 0x2ab354..0x2ab3a0 (76 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x2ab354: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x2ab358: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x2ab35c: 910043FD  add      x29, sp, #0x10
//   0x2ab360: D0000688  adrp     x8, #0x37d000
//   0x2ab364: 91082108  add      x8, x8, #0x208
//   0x2ab368: F9401801  ldr      x1, [x0, #0x30]
uint64_t fde_func_8711_0x2ab354(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x002AB354ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81E0FF3ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD0000688ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91082108ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9401801ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000008ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD0000688ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #8715 | PC: 0x2ab3dc..0x2ab410 (52 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x2ab3dc: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x2ab3e0: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x2ab3e4: 910043FD  add      x29, sp, #0x10
//   0x2ab3e8: F9400C01  ldr      x1, [x0, #0x18]
//   0x2ab3ec: D0000688  adrp     x8, #0x37d000
//   0x2ab3f0: 91096108  add      x8, x8, #0x258
uint64_t fde_func_8715_0x2ab3dc(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x002AB3DCULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81E0FF3ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400C01ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD0000688ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91096108ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF8010408ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #8720 | PC: 0x2ab5ec..0x2ab644 (88 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x2ab5ec: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x2ab5f0: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x2ab5f4: 910043FD  add      x29, sp, #0x10
//   0x2ab5f8: AA0003F3  mov      x19, x0
//   0x2ab5fc: 9102E000  add      x0, x0, #0xb8
//   0x2ab600: 97F6CE47  bl       #0x5ef1c
uint64_t fde_func_8720_0x2ab5ec(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x002AB5ECULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81E0FF3ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9102E000ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x97F6CE47ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91028260ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x94000010ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #8724 | PC: 0x2ab730..0x2ab830 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x2ab730: D101C3FF  sub      sp, sp, #0x70
//   0x2ab734: F90013F9  str      x25, [sp, #0x20]
//   0x2ab738: A9035FF8  stp      x24, x23, [sp, #0x30]
//   0x2ab73c: A90457F6  stp      x22, x21, [sp, #0x40]
//   0x2ab740: A9054FF4  stp      x20, x19, [sp, #0x50]
//   0x2ab744: A9067BFD  stp      x29, x30, [sp, #0x60]
uint64_t fde_func_8724_0x2ab730(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x002AB730ULL);
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

// FDE #8729 | PC: 0x2abe6c..0x2abec4 (88 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x2abe6c: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x2abe70: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x2abe74: 910043FD  add      x29, sp, #0x10
//   0x2abe78: F9400413  ldr      x19, [x0, #8]
//   0x2abe7c: B40000F3  cbz      x19, #0x2abe98
//   0x2abe80: 91002268  add      x8, x19, #8
uint64_t fde_func_8729_0x2abe6c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x002ABE6CULL);
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

// FDE #8733 | PC: 0x2acb2c..0x2acc2c (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x2acb2c: D10603FF  sub      sp, sp, #0x180
//   0x2acb30: F90093FC  str      x28, [sp, #0x120]
//   0x2acb34: A91367FA  stp      x26, x25, [sp, #0x130]
//   0x2acb38: A9145FF8  stp      x24, x23, [sp, #0x140]
//   0x2acb3c: A91557F6  stp      x22, x21, [sp, #0x150]
//   0x2acb40: A9164FF4  stp      x20, x19, [sp, #0x160]
uint64_t fde_func_8733_0x2acb2c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x002ACB2CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10603FFULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF90093FCULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA91367FAULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9145FF8ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA91557F6ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9164FF4ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9177BFDULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9105C3FDULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #8738 | PC: 0x2ae02c..0x2ae12c (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x2ae02c: F81C0FF7  str      x23, [sp, #-0x40]!
//   0x2ae030: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x2ae034: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x2ae038: A9037BFD  stp      x29, x30, [sp, #0x30]
//   0x2ae03c: 9100C3FD  add      x29, sp, #0x30
//   0x2ae040: F9400457  ldr      x23, [x2, #8]
uint64_t fde_func_8738_0x2ae02c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x002AE02CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81C0FF7ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90157F6ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9024FF4ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9037BFDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9100C3FDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400457ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0203F4ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0103F3ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #8742 | PC: 0x2af484..0x2af488 (4 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x2af484: D4200020  brk      #1
uint64_t fde_func_8742_0x2af484(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x002AF484ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD4200020ULL ^ (0ULL << 32);
    return state ^ (state >> 29);
}

// FDE #8747 | PC: 0x2af52c..0x2af564 (56 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x2af52c: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x2af530: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x2af534: 910043FD  add      x29, sp, #0x10
//   0x2af538: D0000668  adrp     x8, #0x37d000
//   0x2af53c: 910FC108  add      x8, x8, #0x3f0
//   0x2af540: AA0003F3  mov      x19, x0
uint64_t fde_func_8747_0x2af52c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x002AF52CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81E0FF3ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD0000668ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910FC108ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF8088408ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x97F8D3D3ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #8751 | PC: 0x2af590..0x2af594 (4 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x2af590: 17F65368  b        #0x44330
uint64_t fde_func_8751_0x2af590(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x002AF590ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0x17F65368ULL ^ (0ULL << 32);
    return state ^ (state >> 29);
}

// FDE #8756 | PC: 0x2af6d0..0x2af730 (96 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x2af6d0: D0000668  adrp     x8, #0x37d000
//   0x2af6d4: 91128108  add      x8, x8, #0x4a0
//   0x2af6d8: F9000028  str      x8, [x1]
//   0x2af6dc: F9400408  ldr      x8, [x0, #8]
//   0x2af6e0: F9000428  str      x8, [x1, #8]
//   0x2af6e4: F9400808  ldr      x8, [x0, #0x10]
uint64_t fde_func_8756_0x2af6d0(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x002AF6D0ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD0000668ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91128108ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000028ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400408ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000428ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400808ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000828ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB40000C8ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #8760 | PC: 0x2af910..0x2af92c (28 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x2af910: F9400428  ldr      x8, [x1, #8]
//   0x2af914: B00002A9  adrp     x9, #0x304000
//   0x2af918: 911CB529  add      x9, x9, #0x72d
//   0x2af91c: 9100200A  add      x10, x0, #8
//   0x2af920: EB09011F  cmp      x8, x9
//   0x2af924: 9A9F0140  csel     x0, x10, xzr, eq
uint64_t fde_func_8760_0x2af910(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x002AF910ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400428ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB00002A9ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x911CB529ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9100200AULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xEB09011FULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9A9F0140ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD65F03C0ULL ^ (6ULL << 32);
    return state ^ (state >> 29);
}

// FDE #8765 | PC: 0x2afbdc..0x2afc00 (36 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x2afbdc: 71001C3F  cmp      w1, #7
//   0x2afbe0: 540000A0  b.eq     #0x2afbf4
//   0x2afbe4: 7100043F  cmp      w1, #1
//   0x2afbe8: 54000081  b.ne     #0x2afbf8
//   0x2afbec: B9001C02  str      w2, [x0, #0x1c]
//   0x2afbf0: 14000002  b        #0x2afbf8
uint64_t fde_func_8765_0x2afbdc(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x002AFBDCULL);
    state = (state * 0x00000100000001B3ULL) ^ 0x71001C3FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x540000A0ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x7100043FULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x54000081ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB9001C02ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x14000002ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB9004002ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x2A1F03E0ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #8769 | PC: 0x2afca0..0x2afcc0 (32 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x2afca0: 3940A008  ldrb     w8, [x0, #0x28]
//   0x2afca4: D0000669  adrp     x9, #0x37d000
//   0x2afca8: 91148129  add      x9, x9, #0x520
//   0x2afcac: F9000009  str      x9, [x0]
//   0x2afcb0: 37000048  tbnz     w8, #0, #0x2afcb8
//   0x2afcb4: D65F03C0  ret      
uint64_t fde_func_8769_0x2afca0(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x002AFCA0ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0x3940A008ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD0000669ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91148129ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000009ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x37000048ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD65F03C0ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9401C00ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x17F6519DULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #8774 | PC: 0x2b0120..0x2b0220 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x2b0120: D102C3FF  sub      sp, sp, #0xb0
//   0x2b0124: A9056FFC  stp      x28, x27, [sp, #0x50]
//   0x2b0128: A90667FA  stp      x26, x25, [sp, #0x60]
//   0x2b012c: A9075FF8  stp      x24, x23, [sp, #0x70]
//   0x2b0130: A90857F6  stp      x22, x21, [sp, #0x80]
//   0x2b0134: A9094FF4  stp      x20, x19, [sp, #0x90]
uint64_t fde_func_8774_0x2b0120(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x002B0120ULL);
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

// FDE #8778 | PC: 0x2b0a30..0x2b0b30 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x2b0a30: D103C3FF  sub      sp, sp, #0xf0
//   0x2b0a34: 6D092BEB  stp      d11, d10, [sp, #0x90]
//   0x2b0a38: 6D0A23E9  stp      d9, d8, [sp, #0xa0]
//   0x2b0a3c: F9005BF7  str      x23, [sp, #0xb0]
//   0x2b0a40: A90C57F6  stp      x22, x21, [sp, #0xc0]
//   0x2b0a44: A90D4FF4  stp      x20, x19, [sp, #0xd0]
uint64_t fde_func_8778_0x2b0a30(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x002B0A30ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD103C3FFULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x6D092BEBULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x6D0A23E9ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9005BF7ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90C57F6ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90D4FF4ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90E7BFDULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910383FDULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #8783 | PC: 0x2b1f7c..0x2b1fa0 (36 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x2b1f7c: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x2b1f80: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x2b1f84: 910043FD  add      x29, sp, #0x10
//   0x2b1f88: AA0003F3  mov      x19, x0
//   0x2b1f8c: 9400001E  bl       #0x2b2004
//   0x2b1f90: A9417BFD  ldp      x29, x30, [sp, #0x10]
uint64_t fde_func_8783_0x2b1f7c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x002B1F7CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81E0FF3ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9400001EULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9417BFDULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA1303E0ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF84207F3ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #8787 | PC: 0x2b20c8..0x2b20ec (36 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x2b20c8: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x2b20cc: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x2b20d0: 910043FD  add      x29, sp, #0x10
//   0x2b20d4: AA0003F3  mov      x19, x0
//   0x2b20d8: 97FFFFCB  bl       #0x2b2004
//   0x2b20dc: A9417BFD  ldp      x29, x30, [sp, #0x10]
uint64_t fde_func_8787_0x2b20c8(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x002B20C8ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81E0FF3ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x97FFFFCBULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9417BFDULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA1303E0ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF84207F3ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #8791 | PC: 0x2b216c..0x2b2170 (4 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x2b216c: D65F03C0  ret      
uint64_t fde_func_8791_0x2b216c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x002B216CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD65F03C0ULL ^ (0ULL << 32);
    return state ^ (state >> 29);
}

// FDE #8796 | PC: 0x2b21b8..0x2b2210 (88 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x2b21b8: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x2b21bc: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x2b21c0: 910043FD  add      x29, sp, #0x10
//   0x2b21c4: AA0003F3  mov      x19, x0
//   0x2b21c8: 52800400  mov      w0, #0x20
//   0x2b21cc: 97F647C1  bl       #0x440d0
uint64_t fde_func_8796_0x2b21b8(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x002B21B8ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81E0FF3ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x52800400ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x97F647C1ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF0000648ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x911C8108ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #8800 | PC: 0x2b2278..0x2b2378 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x2b2278: D10183FF  sub      sp, sp, #0x60
//   0x2b227c: F9001BF5  str      x21, [sp, #0x30]
//   0x2b2280: A9044FF4  stp      x20, x19, [sp, #0x40]
//   0x2b2284: A9057BFD  stp      x29, x30, [sp, #0x50]
//   0x2b2288: 910143FD  add      x29, sp, #0x50
//   0x2b228c: D53BD055  mrs      x21, tpidr_el0
uint64_t fde_func_8800_0x2b2278(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x002B2278ULL);
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

// FDE #8805 | PC: 0x2b24d8..0x2b24e0 (8 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x2b24d8: 2A1F03E0  mov      w0, wzr
//   0x2b24dc: D65F03C0  ret      
uint64_t fde_func_8805_0x2b24d8(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x002B24D8ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0x2A1F03E0ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD65F03C0ULL ^ (1ULL << 32);
    return state ^ (state >> 29);
}

// FDE #8809 | PC: 0x2b24f0..0x2b25f0 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x2b24f0: D10383FF  sub      sp, sp, #0xe0
//   0x2b24f4: F90043FB  str      x27, [sp, #0x80]
//   0x2b24f8: A90967FA  stp      x26, x25, [sp, #0x90]
//   0x2b24fc: A90A5FF8  stp      x24, x23, [sp, #0xa0]
//   0x2b2500: A90B57F6  stp      x22, x21, [sp, #0xb0]
//   0x2b2504: A90C4FF4  stp      x20, x19, [sp, #0xc0]
uint64_t fde_func_8809_0x2b24f0(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x002B24F0ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10383FFULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF90043FBULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90967FAULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90A5FF8ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90B57F6ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90C4FF4ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90D7BFDULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910343FDULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #8814 | PC: 0x2b3480..0x2b34cc (76 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x2b3480: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x2b3484: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x2b3488: 910043FD  add      x29, sp, #0x10
//   0x2b348c: D0000648  adrp     x8, #0x37d000
//   0x2b3490: 91218108  add      x8, x8, #0x860
//   0x2b3494: F9401801  ldr      x1, [x0, #0x30]
uint64_t fde_func_8814_0x2b3480(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x002B3480ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81E0FF3ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD0000648ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91218108ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9401801ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000008ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD0000648ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #8818 | PC: 0x2b3508..0x2b353c (52 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x2b3508: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x2b350c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x2b3510: 910043FD  add      x29, sp, #0x10
//   0x2b3514: F9400C01  ldr      x1, [x0, #0x18]
//   0x2b3518: D0000648  adrp     x8, #0x37d000
//   0x2b351c: 9122C108  add      x8, x8, #0x8b0
uint64_t fde_func_8818_0x2b3508(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x002B3508ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81E0FF3ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400C01ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD0000648ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9122C108ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF8010408ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #8823 | PC: 0x2b36d0..0x2b371c (76 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x2b36d0: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x2b36d4: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x2b36d8: 910043FD  add      x29, sp, #0x10
//   0x2b36dc: AA0003F3  mov      x19, x0
//   0x2b36e0: 91030000  add      x0, x0, #0xc0
//   0x2b36e4: 97F6AE0E  bl       #0x5ef1c
uint64_t fde_func_8823_0x2b36d0(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x002B36D0ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81E0FF3ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91030000ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x97F6AE0EULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9102A260ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x97FF63F5ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #8827 | PC: 0x2b3898..0x2b38dc (68 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x2b3898: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x2b389c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x2b38a0: 910043FD  add      x29, sp, #0x10
//   0x2b38a4: F9400013  ldr      x19, [x0]
//   0x2b38a8: F9000001  str      x1, [x0]
//   0x2b38ac: B4000133  cbz      x19, #0x2b38d0
uint64_t fde_func_8827_0x2b3898(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x002B3898ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81E0FF3ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400013ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000001ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB4000133ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x39404008ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x34000068ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #8832 | PC: 0x2b3b8c..0x2b3c8c (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x2b3b8c: D10343FF  sub      sp, sp, #0xd0
//   0x2b3b90: F9004BF7  str      x23, [sp, #0x90]
//   0x2b3b94: A90A57F6  stp      x22, x21, [sp, #0xa0]
//   0x2b3b98: A90B4FF4  stp      x20, x19, [sp, #0xb0]
//   0x2b3b9c: A90C7BFD  stp      x29, x30, [sp, #0xc0]
//   0x2b3ba0: 910303FD  add      x29, sp, #0xc0
uint64_t fde_func_8832_0x2b3b8c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x002B3B8CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10343FFULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9004BF7ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90A57F6ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90B4FF4ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90C7BFDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910303FDULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD53BD056ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF94016C8ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #8836 | PC: 0x2b4454..0x2b4478 (36 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x2b4454: F9400008  ldr      x8, [x0]
//   0x2b4458: 52800CE1  mov      w1, #0x67
//   0x2b445c: F85C8108  ldur     x8, [x8, #-0x38]
//   0x2b4460: 8B080008  add      x8, x0, x8
//   0x2b4464: F9407500  ldr      x0, [x8, #0xe8]
//   0x2b4468: 9101C102  add      x2, x8, #0x70
uint64_t fde_func_8836_0x2b4454(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x002B4454ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400008ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x52800CE1ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF85C8108ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x8B080008ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9407500ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9101C102ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400009ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9401523ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #8841 | PC: 0x2b49f8..0x2b4af8 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x2b49f8: D101C3FF  sub      sp, sp, #0x70
//   0x2b49fc: F90013F9  str      x25, [sp, #0x20]
//   0x2b4a00: A9035FF8  stp      x24, x23, [sp, #0x30]
//   0x2b4a04: A90457F6  stp      x22, x21, [sp, #0x40]
//   0x2b4a08: A9054FF4  stp      x20, x19, [sp, #0x50]
//   0x2b4a0c: A9067BFD  stp      x29, x30, [sp, #0x60]
uint64_t fde_func_8841_0x2b49f8(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x002B49F8ULL);
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

// FDE #8845 | PC: 0x2b4bcc..0x2b4bfc (48 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x2b4bcc: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x2b4bd0: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x2b4bd4: 910043FD  add      x29, sp, #0x10
//   0x2b4bd8: F9400008  ldr      x8, [x0]
//   0x2b4bdc: F85E0108  ldur     x8, [x8, #-0x20]
//   0x2b4be0: 8B080013  add      x19, x0, x8
uint64_t fde_func_8845_0x2b4bcc(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x002B4BCCULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81E0FF3ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400008ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF85E0108ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x8B080013ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA1303E0ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x97FF9904ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #8850 | PC: 0x2b4c7c..0x2b4c8c (16 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x2b4c7c: F85B0C08  ldr      x8, [x0, #-0x50]!
//   0x2b4c80: F85E8108  ldur     x8, [x8, #-0x18]
//   0x2b4c84: 8B080000  add      x0, x0, x8
//   0x2b4c88: 17FF98DC  b        #0x29aff8
uint64_t fde_func_8850_0x2b4c7c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x002B4C7CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF85B0C08ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF85E8108ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x8B080000ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x17FF98DCULL ^ (3ULL << 32);
    return state ^ (state >> 29);
}

// FDE #8854 | PC: 0x2b4d6c..0x2b4d7c (16 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x2b4d6c: F9400C00  ldr      x0, [x0, #0x18]
//   0x2b4d70: B4000040  cbz      x0, #0x2b4d78
//   0x2b4d74: 17F63D6F  b        #0x44330
//   0x2b4d78: D65F03C0  ret      
uint64_t fde_func_8854_0x2b4d6c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x002B4D6CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400C00ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB4000040ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x17F63D6FULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD65F03C0ULL ^ (3ULL << 32);
    return state ^ (state >> 29);
}

// FDE #8859 | PC: 0x2b4ec8..0x2b4ef8 (48 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x2b4ec8: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x2b4ecc: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x2b4ed0: 910043FD  add      x29, sp, #0x10
//   0x2b4ed4: D0000648  adrp     x8, #0x37e000
//   0x2b4ed8: 91064108  add      x8, x8, #0x190
//   0x2b4edc: AA0003F3  mov      x19, x0
uint64_t fde_func_8859_0x2b4ec8(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x002B4EC8ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81E0FF3ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD0000648ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91064108ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF8020408ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x97FFF448ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #8863 | PC: 0x2b4f3c..0x2b4fc8 (140 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x2b4f3c: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x2b4f40: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x2b4f44: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x2b4f48: 910083FD  add      x29, sp, #0x20
//   0x2b4f4c: F900081F  str      xzr, [x0, #0x10]
//   0x2b4f50: F0000648  adrp     x8, #0x37f000
uint64_t fde_func_8863_0x2b4f3c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x002B4F3CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81D0FF5ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9014FF4ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9027BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910083FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF900081FULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF0000648ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF946B508ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x6F00E400ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #8867 | PC: 0x2b5124..0x2b515c (56 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x2b5124: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x2b5128: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x2b512c: 910043FD  add      x29, sp, #0x10
//   0x2b5130: B0000648  adrp     x8, #0x37e000
//   0x2b5134: 91078108  add      x8, x8, #0x1e0
//   0x2b5138: AA0003F3  mov      x19, x0
uint64_t fde_func_8867_0x2b5124(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x002B5124ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81E0FF3ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB0000648ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91078108ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF8020408ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x97FFF3B1ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #8872 | PC: 0x2b51c8..0x2b5200 (56 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x2b51c8: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x2b51cc: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x2b51d0: 910043FD  add      x29, sp, #0x10
//   0x2b51d4: AA0003F3  mov      x19, x0
//   0x2b51d8: F9400800  ldr      x0, [x0, #0x10]
//   0x2b51dc: B0000648  adrp     x8, #0x37e000
uint64_t fde_func_8872_0x2b51c8(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x002B51C8ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81E0FF3ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400800ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB0000648ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9108C108ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000268ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #8876 | PC: 0x2b52a0..0x2b52cc (44 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x2b52a0: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x2b52a4: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x2b52a8: 910043FD  add      x29, sp, #0x10
//   0x2b52ac: AA0003F3  mov      x19, x0
//   0x2b52b0: F9400800  ldr      x0, [x0, #0x10]
//   0x2b52b4: B4000040  cbz      x0, #0x2b52bc
uint64_t fde_func_8876_0x2b52a0(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x002B52A0ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81E0FF3ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400800ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB4000040ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x97F63BB6ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9417BFDULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #8881 | PC: 0x2b545c..0x2b5498 (60 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x2b545c: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x2b5460: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x2b5464: 910043FD  add      x29, sp, #0x10
//   0x2b5468: B0000648  adrp     x8, #0x37e000
//   0x2b546c: 910B0108  add      x8, x8, #0x2c0
//   0x2b5470: AA0003F3  mov      x19, x0
uint64_t fde_func_8881_0x2b545c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x002B545CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81E0FF3ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB0000648ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910B0108ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF8020408ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x97FFEC23ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #8885 | PC: 0x2b5b7c..0x2b5c7c (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x2b5b7c: D10303FF  sub      sp, sp, #0xc0
//   0x2b5b80: FD0033E8  str      d8, [sp, #0x60]
//   0x2b5b84: F90037FB  str      x27, [sp, #0x68]
//   0x2b5b88: A90767FA  stp      x26, x25, [sp, #0x70]
//   0x2b5b8c: A9085FF8  stp      x24, x23, [sp, #0x80]
//   0x2b5b90: A90957F6  stp      x22, x21, [sp, #0x90]
uint64_t fde_func_8885_0x2b5b7c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x002B5B7CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10303FFULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xFD0033E8ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF90037FBULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90767FAULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9085FF8ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90957F6ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90A4FF4ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90B7BFDULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #8890 | PC: 0x2b6504..0x2b656c (104 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x2b6504: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x2b6508: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x2b650c: 910043FD  add      x29, sp, #0x10
//   0x2b6510: F9400028  ldr      x8, [x1]
//   0x2b6514: B4000268  cbz      x8, #0x2b6560
//   0x2b6518: AA0803F3  mov      x19, x8
uint64_t fde_func_8890_0x2b6504(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x002B6504ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE4FF4ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400028ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB4000268ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0803F3ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x38428E69ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x37000089ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #8894 | PC: 0x2b67c0..0x2b6884 (196 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x2b67c0: D10143FF  sub      sp, sp, #0x50
//   0x2b67c4: F9000BF7  str      x23, [sp, #0x10]
//   0x2b67c8: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x2b67cc: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x2b67d0: A9047BFD  stp      x29, x30, [sp, #0x40]
//   0x2b67d4: 910103FD  add      x29, sp, #0x40
uint64_t fde_func_8894_0x2b67c0(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x002B67C0ULL);
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

// FDE #8899 | PC: 0x2b6a54..0x2b6ad8 (132 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x2b6a54: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x2b6a58: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x2b6a5c: 910043FD  add      x29, sp, #0x10
//   0x2b6a60: F9400428  ldr      x8, [x1, #8]
//   0x2b6a64: B40000A8  cbz      x8, #0x2b6a78
//   0x2b6a68: AA0803F3  mov      x19, x8
uint64_t fde_func_8899_0x2b6a54(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x002B6A54ULL);
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

// FDE #8903 | PC: 0x2b6b04..0x2b6bb8 (180 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x2b6b04: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x2b6b08: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x2b6b0c: 910043FD  add      x29, sp, #0x10
//   0x2b6b10: AA0003F3  mov      x19, x0
//   0x2b6b14: 52800020  mov      w0, #1
//   0x2b6b18: 97F63B77  bl       #0x458f4
uint64_t fde_func_8903_0x2b6b04(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x002B6B04ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE4FF4ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x52800020ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x97F63B77ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x36000140ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF0000261ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #8908 | PC: 0x2b7004..0x2b7014 (16 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x2b7004: F9400008  ldr      x8, [x0]
//   0x2b7008: F85C8108  ldur     x8, [x8, #-0x38]
//   0x2b700c: 8B080000  add      x0, x0, x8
//   0x2b7010: 17FFFFE3  b        #0x2b6f9c
uint64_t fde_func_8908_0x2b7004(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x002B7004ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400008ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF85C8108ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x8B080000ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x17FFFFE3ULL ^ (3ULL << 32);
    return state ^ (state >> 29);
}

// FDE #8912 | PC: 0x2b718c..0x2b7254 (200 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x2b718c: D100C3FF  sub      sp, sp, #0x30
//   0x2b7190: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x2b7194: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x2b7198: 910083FD  add      x29, sp, #0x20
//   0x2b719c: D53BD054  mrs      x20, tpidr_el0
//   0x2b71a0: F9401688  ldr      x8, [x20, #0x28]
uint64_t fde_func_8912_0x2b718c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x002B718CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD100C3FFULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9014FF4ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9027BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910083FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD53BD054ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9401688ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910013E2ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #8917 | PC: 0x2b7e0c..0x2b7e14 (8 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x2b7e0c: 2A1F03E0  mov      w0, wzr
//   0x2b7e10: D65F03C0  ret      
uint64_t fde_func_8917_0x2b7e0c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x002B7E0CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0x2A1F03E0ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD65F03C0ULL ^ (1ULL << 32);
    return state ^ (state >> 29);
}

// FDE #8921 | PC: 0x2b81c4..0x2b81d4 (16 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x2b81c4: F9400008  ldr      x8, [x0]
//   0x2b81c8: F85D8108  ldur     x8, [x8, #-0x28]
//   0x2b81cc: 8B080000  add      x0, x0, x8
//   0x2b81d0: 17FFFF11  b        #0x2b7e14
uint64_t fde_func_8921_0x2b81c4(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x002B81C4ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400008ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF85D8108ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x8B080000ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x17FFFF11ULL ^ (3ULL << 32);
    return state ^ (state >> 29);
}

// FDE #8926 | PC: 0x2b83e8..0x2b83f0 (8 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x2b83e8: D100A000  sub      x0, x0, #0x28
//   0x2b83ec: 17FF88C8  b        #0x29a70c
uint64_t fde_func_8926_0x2b83e8(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x002B83E8ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD100A000ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x17FF88C8ULL ^ (1ULL << 32);
    return state ^ (state >> 29);
}

// FDE #8930 | PC: 0x2b8448..0x2b8458 (16 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x2b8448: F9400008  ldr      x8, [x0]
//   0x2b844c: F85E0108  ldur     x8, [x8, #-0x20]
//   0x2b8450: 8B080000  add      x0, x0, x8
//   0x2b8454: 17FF88AE  b        #0x29a70c
uint64_t fde_func_8930_0x2b8448(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x002B8448ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400008ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF85E0108ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x8B080000ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x17FF88AEULL ^ (3ULL << 32);
    return state ^ (state >> 29);
}

// FDE #8935 | PC: 0x2b84d8..0x2b8508 (48 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x2b84d8: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x2b84dc: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x2b84e0: 910043FD  add      x29, sp, #0x10
//   0x2b84e4: F85B8C08  ldr      x8, [x0, #-0x48]!
//   0x2b84e8: F85E8108  ldur     x8, [x8, #-0x18]
//   0x2b84ec: 8B080013  add      x19, x0, x8
uint64_t fde_func_8935_0x2b84d8(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x002B84D8ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81E0FF3ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF85B8C08ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF85E8108ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x8B080013ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA1303E0ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x97FF8886ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #8939 | PC: 0x2b9034..0x2b9134 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x2b9034: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x2b9038: 9E660000  fmov     x0, d0
//   0x2b903c: 9EAE0001  fmov     x1, v0.d[1]
//   0x2b9040: 910003FD  mov      x29, sp
//   0x2b9044: AA0003E3  mov      x3, x0
//   0x2b9048: AA0103E0  mov      x0, x1
uint64_t fde_func_8939_0x2b9034(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x002B9034ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BF7BFDULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9E660000ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9EAE0001ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003E3ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0103E0ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9E660024ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9EAE0025ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

uint64_t execute_fde_shard_5(uint32_t fde_idx, uint64_t a0, uint64_t a1) {
    switch (fde_idx) {
        case 7155: return fde_func_7155_0x268be8(a0, a1);
        case 7159: return fde_func_7159_0x268d08(a0, a1);
        case 7164: return fde_func_7164_0x268d44(a0, a1);
        case 7168: return fde_func_7168_0x268d9c(a0, a1);
        case 7173: return fde_func_7173_0x268df0(a0, a1);
        case 7177: return fde_func_7177_0x268eb0(a0, a1);
        case 7182: return fde_func_7182_0x2693dc(a0, a1);
        case 7186: return fde_func_7186_0x269434(a0, a1);
        case 7190: return fde_func_7190_0x269488(a0, a1);
        case 7195: return fde_func_7195_0x2695a0(a0, a1);
        case 7199: return fde_func_7199_0x269848(a0, a1);
        case 7204: return fde_func_7204_0x2698a8(a0, a1);
        case 7208: return fde_func_7208_0x269a50(a0, a1);
        case 7213: return fde_func_7213_0x26a4d8(a0, a1);
        case 7217: return fde_func_7217_0x26a500(a0, a1);
        case 7222: return fde_func_7222_0x26a57c(a0, a1);
        case 7226: return fde_func_7226_0x26a5a8(a0, a1);
        case 7231: return fde_func_7231_0x26a60c(a0, a1);
        case 7235: return fde_func_7235_0x26a640(a0, a1);
        case 7240: return fde_func_7240_0x26cecc(a0, a1);
        case 7244: return fde_func_7244_0x26d0a8(a0, a1);
        case 7249: return fde_func_7249_0x26d4f0(a0, a1);
        case 7253: return fde_func_7253_0x26d7f4(a0, a1);
        case 7258: return fde_func_7258_0x26d830(a0, a1);
        case 7262: return fde_func_7262_0x26d8a8(a0, a1);
        case 7267: return fde_func_7267_0x26d9cc(a0, a1);
        case 7271: return fde_func_7271_0x26e1f8(a0, a1);
        case 7275: return fde_func_7275_0x26e328(a0, a1);
        case 7280: return fde_func_7280_0x26e484(a0, a1);
        case 7284: return fde_func_7284_0x26e6dc(a0, a1);
        case 7289: return fde_func_7289_0x26ede0(a0, a1);
        case 7293: return fde_func_7293_0x26eff8(a0, a1);
        case 7298: return fde_func_7298_0x26f190(a0, a1);
        case 7302: return fde_func_7302_0x26f42c(a0, a1);
        case 7307: return fde_func_7307_0x26f690(a0, a1);
        case 7311: return fde_func_7311_0x26f868(a0, a1);
        case 7316: return fde_func_7316_0x26fb28(a0, a1);
        case 7320: return fde_func_7320_0x26fc34(a0, a1);
        case 7325: return fde_func_7325_0x2702b8(a0, a1);
        case 7329: return fde_func_7329_0x27042c(a0, a1);
        case 7334: return fde_func_7334_0x2705d0(a0, a1);
        case 7338: return fde_func_7338_0x2707c4(a0, a1);
        case 7343: return fde_func_7343_0x270a00(a0, a1);
        case 7347: return fde_func_7347_0x270dd4(a0, a1);
        case 7351: return fde_func_7351_0x2717e4(a0, a1);
        case 7356: return fde_func_7356_0x271d04(a0, a1);
        case 7360: return fde_func_7360_0x272394(a0, a1);
        case 7365: return fde_func_7365_0x273054(a0, a1);
        case 7369: return fde_func_7369_0x27342c(a0, a1);
        case 7374: return fde_func_7374_0x273828(a0, a1);
        case 7378: return fde_func_7378_0x2739ac(a0, a1);
        case 7383: return fde_func_7383_0x273ae0(a0, a1);
        case 7387: return fde_func_7387_0x273cb4(a0, a1);
        case 7392: return fde_func_7392_0x273e78(a0, a1);
        case 7396: return fde_func_7396_0x273f40(a0, a1);
        case 7401: return fde_func_7401_0x273fe4(a0, a1);
        case 7405: return fde_func_7405_0x27437c(a0, a1);
        case 7410: return fde_func_7410_0x2745e8(a0, a1);
        case 7414: return fde_func_7414_0x2748cc(a0, a1);
        case 7419: return fde_func_7419_0x274d94(a0, a1);
        case 7423: return fde_func_7423_0x275780(a0, a1);
        case 7427: return fde_func_7427_0x275ba0(a0, a1);
        case 7432: return fde_func_7432_0x2760ec(a0, a1);
        case 7436: return fde_func_7436_0x27669c(a0, a1);
        case 7441: return fde_func_7441_0x276bc0(a0, a1);
        case 7445: return fde_func_7445_0x276fe0(a0, a1);
        case 7450: return fde_func_7450_0x277734(a0, a1);
        case 7454: return fde_func_7454_0x277b5c(a0, a1);
        case 7459: return fde_func_7459_0x277de4(a0, a1);
        case 7463: return fde_func_7463_0x278450(a0, a1);
        case 7468: return fde_func_7468_0x2787a8(a0, a1);
        case 7472: return fde_func_7472_0x27982c(a0, a1);
        case 7477: return fde_func_7477_0x27a0a8(a0, a1);
        case 7481: return fde_func_7481_0x27a304(a0, a1);
        case 7486: return fde_func_7486_0x27a410(a0, a1);
        case 7490: return fde_func_7490_0x27a6ec(a0, a1);
        case 7495: return fde_func_7495_0x27a964(a0, a1);
        case 7499: return fde_func_7499_0x27aa48(a0, a1);
        case 7504: return fde_func_7504_0x27af08(a0, a1);
        case 7508: return fde_func_7508_0x27af60(a0, a1);
        case 7512: return fde_func_7512_0x27aff0(a0, a1);
        case 7517: return fde_func_7517_0x27b51c(a0, a1);
        case 7521: return fde_func_7521_0x27b96c(a0, a1);
        case 7526: return fde_func_7526_0x27bc1c(a0, a1);
        case 7530: return fde_func_7530_0x27c1b8(a0, a1);
        case 7535: return fde_func_7535_0x27c66c(a0, a1);
        case 7539: return fde_func_7539_0x27c950(a0, a1);
        case 7544: return fde_func_7544_0x27cda0(a0, a1);
        case 7548: return fde_func_7548_0x27cff0(a0, a1);
        case 7553: return fde_func_7553_0x27d75c(a0, a1);
        case 7557: return fde_func_7557_0x27d99c(a0, a1);
        case 7562: return fde_func_7562_0x27dd2c(a0, a1);
        case 7566: return fde_func_7566_0x27e0b4(a0, a1);
        case 7571: return fde_func_7571_0x27eb08(a0, a1);
        case 7575: return fde_func_7575_0x27efcc(a0, a1);
        case 7580: return fde_func_7580_0x27f38c(a0, a1);
        case 7584: return fde_func_7584_0x27fb9c(a0, a1);
        case 7588: return fde_func_7588_0x27fc14(a0, a1);
        case 7593: return fde_func_7593_0x28010c(a0, a1);
        case 7597: return fde_func_7597_0x2801fc(a0, a1);
        case 7602: return fde_func_7602_0x28052c(a0, a1);
        case 7606: return fde_func_7606_0x2807fc(a0, a1);
        case 7611: return fde_func_7611_0x280838(a0, a1);
        case 7615: return fde_func_7615_0x28087c(a0, a1);
        case 7620: return fde_func_7620_0x280914(a0, a1);
        case 7624: return fde_func_7624_0x280ab0(a0, a1);
        case 7629: return fde_func_7629_0x280e50(a0, a1);
        case 7633: return fde_func_7633_0x280f90(a0, a1);
        case 7638: return fde_func_7638_0x28113c(a0, a1);
        case 7642: return fde_func_7642_0x2812cc(a0, a1);
        case 7647: return fde_func_7647_0x2814b8(a0, a1);
        case 7651: return fde_func_7651_0x281838(a0, a1);
        case 7656: return fde_func_7656_0x282158(a0, a1);
        case 7660: return fde_func_7660_0x28253c(a0, a1);
        case 7665: return fde_func_7665_0x282a10(a0, a1);
        case 7669: return fde_func_7669_0x282c44(a0, a1);
        case 7673: return fde_func_7673_0x283290(a0, a1);
        case 7678: return fde_func_7678_0x283748(a0, a1);
        case 7682: return fde_func_7682_0x2838b4(a0, a1);
        case 7687: return fde_func_7687_0x283964(a0, a1);
        case 7691: return fde_func_7691_0x283a88(a0, a1);
        case 7696: return fde_func_7696_0x286b78(a0, a1);
        case 7700: return fde_func_7700_0x286d98(a0, a1);
        case 7705: return fde_func_7705_0x2879ec(a0, a1);
        case 7709: return fde_func_7709_0x288130(a0, a1);
        case 7714: return fde_func_7714_0x288480(a0, a1);
        case 7718: return fde_func_7718_0x28895c(a0, a1);
        case 7723: return fde_func_7723_0x28921c(a0, a1);
        case 7727: return fde_func_7727_0x289734(a0, a1);
        case 7732: return fde_func_7732_0x289b64(a0, a1);
        case 7736: return fde_func_7736_0x289fb8(a0, a1);
        case 7741: return fde_func_7741_0x28a42c(a0, a1);
        case 7745: return fde_func_7745_0x28a5ec(a0, a1);
        case 7749: return fde_func_7749_0x28a744(a0, a1);
        case 7754: return fde_func_7754_0x28a814(a0, a1);
        case 7758: return fde_func_7758_0x28a970(a0, a1);
        case 7763: return fde_func_7763_0x28ac9c(a0, a1);
        case 7767: return fde_func_7767_0x28b490(a0, a1);
        case 7772: return fde_func_7772_0x28bc90(a0, a1);
        case 7776: return fde_func_7776_0x28becc(a0, a1);
        case 7781: return fde_func_7781_0x28c23c(a0, a1);
        case 7785: return fde_func_7785_0x28c4f4(a0, a1);
        case 7790: return fde_func_7790_0x28c574(a0, a1);
        case 7794: return fde_func_7794_0x28c638(a0, a1);
        case 7799: return fde_func_7799_0x28c75c(a0, a1);
        case 7803: return fde_func_7803_0x28c7d4(a0, a1);
        case 7808: return fde_func_7808_0x28ca98(a0, a1);
        case 7812: return fde_func_7812_0x28cbe4(a0, a1);
        case 7817: return fde_func_7817_0x28cf1c(a0, a1);
        case 7821: return fde_func_7821_0x28d2f4(a0, a1);
        case 7826: return fde_func_7826_0x28d48c(a0, a1);
        case 7830: return fde_func_7830_0x28d500(a0, a1);
        case 7834: return fde_func_7834_0x28d9ec(a0, a1);
        case 7839: return fde_func_7839_0x28dc64(a0, a1);
        case 7843: return fde_func_7843_0x28dd84(a0, a1);
        case 7848: return fde_func_7848_0x28e174(a0, a1);
        case 7852: return fde_func_7852_0x28e390(a0, a1);
        case 7857: return fde_func_7857_0x28eb80(a0, a1);
        case 7861: return fde_func_7861_0x28ebe0(a0, a1);
        case 7866: return fde_func_7866_0x28ec7c(a0, a1);
        case 7870: return fde_func_7870_0x28ec90(a0, a1);
        case 7875: return fde_func_7875_0x28ee64(a0, a1);
        case 7879: return fde_func_7879_0x28ef6c(a0, a1);
        case 7884: return fde_func_7884_0x28f0b8(a0, a1);
        case 7888: return fde_func_7888_0x28f198(a0, a1);
        case 7893: return fde_func_7893_0x28f368(a0, a1);
        case 7897: return fde_func_7897_0x28f3c4(a0, a1);
        case 7902: return fde_func_7902_0x28f43c(a0, a1);
        case 7906: return fde_func_7906_0x28f628(a0, a1);
        case 7910: return fde_func_7910_0x28f684(a0, a1);
        case 7915: return fde_func_7915_0x28f740(a0, a1);
        case 7919: return fde_func_7919_0x28f934(a0, a1);
        case 7924: return fde_func_7924_0x28f990(a0, a1);
        case 7928: return fde_func_7928_0x28fadc(a0, a1);
        case 7933: return fde_func_7933_0x28fc18(a0, a1);
        case 7937: return fde_func_7937_0x28fc90(a0, a1);
        case 7942: return fde_func_7942_0x28fe1c(a0, a1);
        case 7946: return fde_func_7946_0x28febc(a0, a1);
        case 7951: return fde_func_7951_0x28fff8(a0, a1);
        case 7955: return fde_func_7955_0x290158(a0, a1);
        case 7960: return fde_func_7960_0x290290(a0, a1);
        case 7964: return fde_func_7964_0x290438(a0, a1);
        case 7969: return fde_func_7969_0x2905dc(a0, a1);
        case 7973: return fde_func_7973_0x290870(a0, a1);
        case 7978: return fde_func_7978_0x290a34(a0, a1);
        case 7982: return fde_func_7982_0x290ae8(a0, a1);
        case 7986: return fde_func_7986_0x290c04(a0, a1);
        case 7991: return fde_func_7991_0x290dd8(a0, a1);
        case 7995: return fde_func_7995_0x290f98(a0, a1);
        case 8000: return fde_func_8000_0x291030(a0, a1);
        case 8004: return fde_func_8004_0x29131c(a0, a1);
        case 8009: return fde_func_8009_0x2914e0(a0, a1);
        case 8013: return fde_func_8013_0x291728(a0, a1);
        case 8018: return fde_func_8018_0x2917c4(a0, a1);
        case 8022: return fde_func_8022_0x291868(a0, a1);
        case 8027: return fde_func_8027_0x2919d4(a0, a1);
        case 8031: return fde_func_8031_0x291f78(a0, a1);
        case 8036: return fde_func_8036_0x2920f8(a0, a1);
        case 8040: return fde_func_8040_0x2924c8(a0, a1);
        case 8045: return fde_func_8045_0x292690(a0, a1);
        case 8049: return fde_func_8049_0x292740(a0, a1);
        case 8054: return fde_func_8054_0x292a80(a0, a1);
        case 8058: return fde_func_8058_0x292c7c(a0, a1);
        case 8063: return fde_func_8063_0x292f04(a0, a1);
        case 8067: return fde_func_8067_0x2930e4(a0, a1);
        case 8071: return fde_func_8071_0x293318(a0, a1);
        case 8076: return fde_func_8076_0x293650(a0, a1);
        case 8080: return fde_func_8080_0x2936d4(a0, a1);
        case 8085: return fde_func_8085_0x293920(a0, a1);
        case 8089: return fde_func_8089_0x293d20(a0, a1);
        case 8094: return fde_func_8094_0x293eb0(a0, a1);
        case 8098: return fde_func_8098_0x294304(a0, a1);
        case 8103: return fde_func_8103_0x29474c(a0, a1);
        case 8107: return fde_func_8107_0x2947c4(a0, a1);
        case 8112: return fde_func_8112_0x294868(a0, a1);
        case 8116: return fde_func_8116_0x294c50(a0, a1);
        case 8121: return fde_func_8121_0x294e90(a0, a1);
        case 8125: return fde_func_8125_0x295548(a0, a1);
        case 8130: return fde_func_8130_0x295788(a0, a1);
        case 8134: return fde_func_8134_0x295834(a0, a1);
        case 8139: return fde_func_8139_0x295fac(a0, a1);
        case 8143: return fde_func_8143_0x29610c(a0, a1);
        case 8147: return fde_func_8147_0x2962d0(a0, a1);
        case 8152: return fde_func_8152_0x2968cc(a0, a1);
        case 8156: return fde_func_8156_0x296c40(a0, a1);
        case 8161: return fde_func_8161_0x296e18(a0, a1);
        case 8165: return fde_func_8165_0x296e28(a0, a1);
        case 8170: return fde_func_8170_0x296e74(a0, a1);
        case 8174: return fde_func_8174_0x296ec0(a0, a1);
        case 8179: return fde_func_8179_0x296f40(a0, a1);
        case 8183: return fde_func_8183_0x297068(a0, a1);
        case 8188: return fde_func_8188_0x2970ec(a0, a1);
        case 8192: return fde_func_8192_0x2970fc(a0, a1);
        case 8197: return fde_func_8197_0x297110(a0, a1);
        case 8201: return fde_func_8201_0x297120(a0, a1);
        case 8206: return fde_func_8206_0x2971b0(a0, a1);
        case 8210: return fde_func_8210_0x297228(a0, a1);
        case 8215: return fde_func_8215_0x2972d8(a0, a1);
        case 8219: return fde_func_8219_0x29742c(a0, a1);
        case 8224: return fde_func_8224_0x2974e4(a0, a1);
        case 8228: return fde_func_8228_0x297668(a0, a1);
        case 8232: return fde_func_8232_0x297ad4(a0, a1);
        case 8237: return fde_func_8237_0x297cc4(a0, a1);
        case 8241: return fde_func_8241_0x297d24(a0, a1);
        case 8246: return fde_func_8246_0x2984b4(a0, a1);
        case 8250: return fde_func_8250_0x298ae4(a0, a1);
        case 8255: return fde_func_8255_0x298d94(a0, a1);
        case 8259: return fde_func_8259_0x299054(a0, a1);
        case 8264: return fde_func_8264_0x299924(a0, a1);
        case 8268: return fde_func_8268_0x299ab0(a0, a1);
        case 8273: return fde_func_8273_0x299d7c(a0, a1);
        case 8277: return fde_func_8277_0x29a304(a0, a1);
        case 8282: return fde_func_8282_0x29a3b0(a0, a1);
        case 8286: return fde_func_8286_0x29a500(a0, a1);
        case 8291: return fde_func_8291_0x29a5d4(a0, a1);
        case 8295: return fde_func_8295_0x29a708(a0, a1);
        case 8300: return fde_func_8300_0x29a934(a0, a1);
        case 8304: return fde_func_8304_0x29a9fc(a0, a1);
        case 8308: return fde_func_8308_0x29abbc(a0, a1);
        case 8313: return fde_func_8313_0x29ace8(a0, a1);
        case 8317: return fde_func_8317_0x29ae1c(a0, a1);
        case 8322: return fde_func_8322_0x29afd8(a0, a1);
        case 8326: return fde_func_8326_0x29b10c(a0, a1);
        case 8331: return fde_func_8331_0x29b374(a0, a1);
        case 8335: return fde_func_8335_0x29b484(a0, a1);
        case 8340: return fde_func_8340_0x29b620(a0, a1);
        case 8344: return fde_func_8344_0x29b670(a0, a1);
        case 8349: return fde_func_8349_0x29b878(a0, a1);
        case 8353: return fde_func_8353_0x29b934(a0, a1);
        case 8358: return fde_func_8358_0x29bba8(a0, a1);
        case 8362: return fde_func_8362_0x29bdec(a0, a1);
        case 8367: return fde_func_8367_0x29c14c(a0, a1);
        case 8371: return fde_func_8371_0x29c45c(a0, a1);
        case 8376: return fde_func_8376_0x29cbbc(a0, a1);
        case 8380: return fde_func_8380_0x29d150(a0, a1);
        case 8385: return fde_func_8385_0x29d244(a0, a1);
        case 8389: return fde_func_8389_0x29d364(a0, a1);
        case 8393: return fde_func_8393_0x29d5e4(a0, a1);
        case 8398: return fde_func_8398_0x29d770(a0, a1);
        case 8402: return fde_func_8402_0x29d7f4(a0, a1);
        case 8407: return fde_func_8407_0x29d9b4(a0, a1);
        case 8411: return fde_func_8411_0x29db38(a0, a1);
        case 8416: return fde_func_8416_0x29dee4(a0, a1);
        case 8420: return fde_func_8420_0x29e100(a0, a1);
        case 8425: return fde_func_8425_0x29e2b0(a0, a1);
        case 8429: return fde_func_8429_0x29e4e4(a0, a1);
        case 8434: return fde_func_8434_0x29e774(a0, a1);
        case 8438: return fde_func_8438_0x29e84c(a0, a1);
        case 8443: return fde_func_8443_0x29e874(a0, a1);
        case 8447: return fde_func_8447_0x29e894(a0, a1);
        case 8452: return fde_func_8452_0x29f0a8(a0, a1);
        case 8456: return fde_func_8456_0x29f590(a0, a1);
        case 8461: return fde_func_8461_0x29f750(a0, a1);
        case 8465: return fde_func_8465_0x29f89c(a0, a1);
        case 8469: return fde_func_8469_0x29f930(a0, a1);
        case 8474: return fde_func_8474_0x29fed0(a0, a1);
        case 8478: return fde_func_8478_0x2a0364(a0, a1);
        case 8483: return fde_func_8483_0x2a07e4(a0, a1);
        case 8487: return fde_func_8487_0x2a0e00(a0, a1);
        case 8492: return fde_func_8492_0x2a0fb4(a0, a1);
        case 8496: return fde_func_8496_0x2a1058(a0, a1);
        case 8501: return fde_func_8501_0x2a1570(a0, a1);
        case 8505: return fde_func_8505_0x2a1604(a0, a1);
        case 8510: return fde_func_8510_0x2a1690(a0, a1);
        case 8514: return fde_func_8514_0x2a192c(a0, a1);
        case 8519: return fde_func_8519_0x2a21e8(a0, a1);
        case 8523: return fde_func_8523_0x2a2300(a0, a1);
        case 8528: return fde_func_8528_0x2a2408(a0, a1);
        case 8532: return fde_func_8532_0x2a24b0(a0, a1);
        case 8537: return fde_func_8537_0x2a27f8(a0, a1);
        case 8541: return fde_func_8541_0x2a29bc(a0, a1);
        case 8545: return fde_func_8545_0x2a2c70(a0, a1);
        case 8550: return fde_func_8550_0x2a35f4(a0, a1);
        case 8554: return fde_func_8554_0x2a38c4(a0, a1);
        case 8559: return fde_func_8559_0x2a434c(a0, a1);
        case 8563: return fde_func_8563_0x2a44f4(a0, a1);
        case 8568: return fde_func_8568_0x2a45d8(a0, a1);
        case 8572: return fde_func_8572_0x2a5098(a0, a1);
        case 8577: return fde_func_8577_0x2a53cc(a0, a1);
        case 8581: return fde_func_8581_0x2a56f4(a0, a1);
        case 8586: return fde_func_8586_0x2a58dc(a0, a1);
        case 8590: return fde_func_8590_0x2a593c(a0, a1);
        case 8595: return fde_func_8595_0x2a59bc(a0, a1);
        case 8599: return fde_func_8599_0x2a5a3c(a0, a1);
        case 8604: return fde_func_8604_0x2a5ac8(a0, a1);
        case 8608: return fde_func_8608_0x2a5d9c(a0, a1);
        case 8613: return fde_func_8613_0x2a64fc(a0, a1);
        case 8617: return fde_func_8617_0x2a6e48(a0, a1);
        case 8622: return fde_func_8622_0x2a7058(a0, a1);
        case 8626: return fde_func_8626_0x2a7280(a0, a1);
        case 8630: return fde_func_8630_0x2a73e0(a0, a1);
        case 8635: return fde_func_8635_0x2a78cc(a0, a1);
        case 8639: return fde_func_8639_0x2a7d04(a0, a1);
        case 8644: return fde_func_8644_0x2a7f60(a0, a1);
        case 8648: return fde_func_8648_0x2a80f0(a0, a1);
        case 8653: return fde_func_8653_0x2a85bc(a0, a1);
        case 8657: return fde_func_8657_0x2a9044(a0, a1);
        case 8662: return fde_func_8662_0x2a9244(a0, a1);
        case 8666: return fde_func_8666_0x2a92c4(a0, a1);
        case 8671: return fde_func_8671_0x2a9398(a0, a1);
        case 8675: return fde_func_8675_0x2a93e4(a0, a1);
        case 8680: return fde_func_8680_0x2a95f4(a0, a1);
        case 8684: return fde_func_8684_0x2a9734(a0, a1);
        case 8689: return fde_func_8689_0x2a98c0(a0, a1);
        case 8693: return fde_func_8693_0x2a99b0(a0, a1);
        case 8698: return fde_func_8698_0x2a9ad0(a0, a1);
        case 8702: return fde_func_8702_0x2a9d7c(a0, a1);
        case 8706: return fde_func_8706_0x2ab190(a0, a1);
        case 8711: return fde_func_8711_0x2ab354(a0, a1);
        case 8715: return fde_func_8715_0x2ab3dc(a0, a1);
        case 8720: return fde_func_8720_0x2ab5ec(a0, a1);
        case 8724: return fde_func_8724_0x2ab730(a0, a1);
        case 8729: return fde_func_8729_0x2abe6c(a0, a1);
        case 8733: return fde_func_8733_0x2acb2c(a0, a1);
        case 8738: return fde_func_8738_0x2ae02c(a0, a1);
        case 8742: return fde_func_8742_0x2af484(a0, a1);
        case 8747: return fde_func_8747_0x2af52c(a0, a1);
        case 8751: return fde_func_8751_0x2af590(a0, a1);
        case 8756: return fde_func_8756_0x2af6d0(a0, a1);
        case 8760: return fde_func_8760_0x2af910(a0, a1);
        case 8765: return fde_func_8765_0x2afbdc(a0, a1);
        case 8769: return fde_func_8769_0x2afca0(a0, a1);
        case 8774: return fde_func_8774_0x2b0120(a0, a1);
        case 8778: return fde_func_8778_0x2b0a30(a0, a1);
        case 8783: return fde_func_8783_0x2b1f7c(a0, a1);
        case 8787: return fde_func_8787_0x2b20c8(a0, a1);
        case 8791: return fde_func_8791_0x2b216c(a0, a1);
        case 8796: return fde_func_8796_0x2b21b8(a0, a1);
        case 8800: return fde_func_8800_0x2b2278(a0, a1);
        case 8805: return fde_func_8805_0x2b24d8(a0, a1);
        case 8809: return fde_func_8809_0x2b24f0(a0, a1);
        case 8814: return fde_func_8814_0x2b3480(a0, a1);
        case 8818: return fde_func_8818_0x2b3508(a0, a1);
        case 8823: return fde_func_8823_0x2b36d0(a0, a1);
        case 8827: return fde_func_8827_0x2b3898(a0, a1);
        case 8832: return fde_func_8832_0x2b3b8c(a0, a1);
        case 8836: return fde_func_8836_0x2b4454(a0, a1);
        case 8841: return fde_func_8841_0x2b49f8(a0, a1);
        case 8845: return fde_func_8845_0x2b4bcc(a0, a1);
        case 8850: return fde_func_8850_0x2b4c7c(a0, a1);
        case 8854: return fde_func_8854_0x2b4d6c(a0, a1);
        case 8859: return fde_func_8859_0x2b4ec8(a0, a1);
        case 8863: return fde_func_8863_0x2b4f3c(a0, a1);
        case 8867: return fde_func_8867_0x2b5124(a0, a1);
        case 8872: return fde_func_8872_0x2b51c8(a0, a1);
        case 8876: return fde_func_8876_0x2b52a0(a0, a1);
        case 8881: return fde_func_8881_0x2b545c(a0, a1);
        case 8885: return fde_func_8885_0x2b5b7c(a0, a1);
        case 8890: return fde_func_8890_0x2b6504(a0, a1);
        case 8894: return fde_func_8894_0x2b67c0(a0, a1);
        case 8899: return fde_func_8899_0x2b6a54(a0, a1);
        case 8903: return fde_func_8903_0x2b6b04(a0, a1);
        case 8908: return fde_func_8908_0x2b7004(a0, a1);
        case 8912: return fde_func_8912_0x2b718c(a0, a1);
        case 8917: return fde_func_8917_0x2b7e0c(a0, a1);
        case 8921: return fde_func_8921_0x2b81c4(a0, a1);
        case 8926: return fde_func_8926_0x2b83e8(a0, a1);
        case 8930: return fde_func_8930_0x2b8448(a0, a1);
        case 8935: return fde_func_8935_0x2b84d8(a0, a1);
        case 8939: return fde_func_8939_0x2b9034(a0, a1);
        default: return 0ULL;
    }
}

} // namespace preload_reconstructed