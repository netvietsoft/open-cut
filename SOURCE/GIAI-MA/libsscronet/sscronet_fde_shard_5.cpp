// ============================================================================
// Clean-Room C++17 Reconstructed AArch64 FDE Shard 5/5 for libsscronet.so
// Phân mảnh hàm FDE AArch64 C++17 sạch 5/5 cho libsscronet.so
// Covers 400 FDEs (indices 1600..1999 of 2,000 sampled from 19,032 FDEs @ 0x0f1dd8)
// ============================================================================
#include "sscronet_core.h"

namespace sscronet {

// FDE #15225 | PC: 0x4b5b4c..0x4b5b98 (76 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x4b5b4c: D503233F  paciasp  
//   0x4b5b50: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x4b5b54: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x4b5b58: 910003FD  mov      x29, sp
//   0x4b5b5c: AA0003F4  mov      x20, x0
//   0x4b5b60: D00007A8  adrp     x8, #0x5ab000
uint64_t fde_func_15225_0x4b5b4c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x004B5B4CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9014FF4ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F4ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD00007A8ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9119C108ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #15235 | PC: 0x4b6438..0x4b6538 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x4b6438: D503233F  paciasp  
//   0x4b643c: D10303FF  sub      sp, sp, #0xc0
//   0x4b6440: A9067BFD  stp      x29, x30, [sp, #0x60]
//   0x4b6444: A9076FFC  stp      x28, x27, [sp, #0x70]
//   0x4b6448: A90867FA  stp      x26, x25, [sp, #0x80]
//   0x4b644c: A9095FF8  stp      x24, x23, [sp, #0x90]
uint64_t fde_func_15235_0x4b6438(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x004B6438ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10303FFULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9067BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9076FFCULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90867FAULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9095FF8ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90A57F6ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90B4FF4ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #15244 | PC: 0x4b69f8..0x4b6af8 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x4b69f8: D503233F  paciasp  
//   0x4b69fc: A9BC7BFD  stp      x29, x30, [sp, #-0x40]!
//   0x4b6a00: F9000BF7  str      x23, [sp, #0x10]
//   0x4b6a04: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x4b6a08: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x4b6a0c: 910003FD  mov      x29, sp
uint64_t fde_func_15244_0x4b69f8(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x004B69F8ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BC7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF7ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90257F6ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9034FF4ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9401008ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #15254 | PC: 0x4b7274..0x4b732c (184 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x4b7274: D503233F  paciasp  
//   0x4b7278: D10103FF  sub      sp, sp, #0x40
//   0x4b727c: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x4b7280: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x4b7284: 910083FD  add      x29, sp, #0x20
//   0x4b7288: AA0003F3  mov      x19, x0
uint64_t fde_func_15254_0x4b7274(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x004B7274ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10103FFULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9027BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9034FF4ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910083FDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x52800020ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x52800021ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #15263 | PC: 0x4b79bc..0x4b7abc (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x4b79bc: D503233F  paciasp  
//   0x4b79c0: D10283FF  sub      sp, sp, #0xa0
//   0x4b79c4: A9047BFD  stp      x29, x30, [sp, #0x40]
//   0x4b79c8: A9056FFC  stp      x28, x27, [sp, #0x50]
//   0x4b79cc: A90667FA  stp      x26, x25, [sp, #0x60]
//   0x4b79d0: A9075FF8  stp      x24, x23, [sp, #0x70]
uint64_t fde_func_15263_0x4b79bc(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x004B79BCULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10283FFULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9047BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9056FFCULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90667FAULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9075FF8ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90857F6ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9094FF4ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #15273 | PC: 0x4b8178..0x4b8264 (236 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x4b8178: D503233F  paciasp  
//   0x4b817c: A9BD7BFD  stp      x29, x30, [sp, #-0x30]!
//   0x4b8180: F9000BF5  str      x21, [sp, #0x10]
//   0x4b8184: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x4b8188: 910003FD  mov      x29, sp
//   0x4b818c: AA0003F4  mov      x20, x0
uint64_t fde_func_15273_0x4b8178(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x004B8178ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BD7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF5ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9024FF4ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F4ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF0000788ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91200108ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #15282 | PC: 0x4b8900..0x4b8a00 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x4b8900: D503233F  paciasp  
//   0x4b8904: D10303FF  sub      sp, sp, #0xc0
//   0x4b8908: A9067BFD  stp      x29, x30, [sp, #0x60]
//   0x4b890c: A9076FFC  stp      x28, x27, [sp, #0x70]
//   0x4b8910: A90867FA  stp      x26, x25, [sp, #0x80]
//   0x4b8914: A9095FF8  stp      x24, x23, [sp, #0x90]
uint64_t fde_func_15282_0x4b8900(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x004B8900ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10303FFULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9067BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9076FFCULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90867FAULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9095FF8ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90A57F6ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90B4FF4ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #15292 | PC: 0x4b942c..0x4b9458 (44 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x4b942c: D503233F  paciasp  
//   0x4b9430: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x4b9434: F9000BF3  str      x19, [sp, #0x10]
//   0x4b9438: 910003FD  mov      x29, sp
//   0x4b943c: AA0003F3  mov      x19, x0
//   0x4b9440: 97FFFFC8  bl       #0x4b9360
uint64_t fde_func_15292_0x4b942c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x004B942CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF3ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x97FFFFC8ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA1303E0ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400BF3ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #15301 | PC: 0x4b9fb8..0x4ba040 (136 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x4b9fb8: D503233F  paciasp  
//   0x4b9fbc: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x4b9fc0: F9000BF3  str      x19, [sp, #0x10]
//   0x4b9fc4: 910003FD  mov      x29, sp
//   0x4b9fc8: F9401008  ldr      x8, [x0, #0x20]
//   0x4b9fcc: AA0003F3  mov      x19, x0
uint64_t fde_func_15301_0x4b9fb8(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x004B9FB8ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF3ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9401008ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF940040AULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD346FD09ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #15311 | PC: 0x4bacac..0x4bad74 (200 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x4bacac: D503233F  paciasp  
//   0x4bacb0: A9BD7BFD  stp      x29, x30, [sp, #-0x30]!
//   0x4bacb4: F9000BF5  str      x21, [sp, #0x10]
//   0x4bacb8: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x4bacbc: 910003FD  mov      x29, sp
//   0x4bacc0: AA0003F3  mov      x19, x0
uint64_t fde_func_15311_0x4bacac(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x004BACACULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BD7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF5ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9024FF4ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400414ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF900141FULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #15320 | PC: 0x4bbb94..0x4bbc94 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x4bbb94: D503233F  paciasp  
//   0x4bbb98: D10183FF  sub      sp, sp, #0x60
//   0x4bbb9c: A9037BFD  stp      x29, x30, [sp, #0x30]
//   0x4bbba0: A90457F6  stp      x22, x21, [sp, #0x40]
//   0x4bbba4: A9054FF4  stp      x20, x19, [sp, #0x50]
//   0x4bbba8: 9100C3FD  add      x29, sp, #0x30
uint64_t fde_func_15320_0x4bbb94(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x004BBB94ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10183FFULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9037BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90457F6ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9054FF4ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9100C3FDULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400028ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F4ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #15330 | PC: 0x4bc428..0x4bc4c8 (160 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x4bc428: D503233F  paciasp  
//   0x4bc42c: A9BD7BFD  stp      x29, x30, [sp, #-0x30]!
//   0x4bc430: F9000BF5  str      x21, [sp, #0x10]
//   0x4bc434: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x4bc438: 910003FD  mov      x29, sp
//   0x4bc43c: B9426029  ldr      w9, [x1, #0x260]
uint64_t fde_func_15330_0x4bc428(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x004BC428ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BD7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF5ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9024FF4ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB9426029ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x52800028ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0103F4ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #15339 | PC: 0x4bc9e0..0x4bca68 (136 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x4bc9e0: D503233F  paciasp  
//   0x4bc9e4: A9BD7BFD  stp      x29, x30, [sp, #-0x30]!
//   0x4bc9e8: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x4bc9ec: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x4bc9f0: 910003FD  mov      x29, sp
//   0x4bc9f4: AA0203F3  mov      x19, x2
uint64_t fde_func_15339_0x4bc9e0(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x004BC9E0ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BD7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90157F6ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9024FF4ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0203F3ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0103F4ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F5ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #15349 | PC: 0x4bce40..0x4bcf0c (204 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x4bce40: D503233F  paciasp  
//   0x4bce44: D10443FF  sub      sp, sp, #0x110
//   0x4bce48: A90F7BFD  stp      x29, x30, [sp, #0xf0]
//   0x4bce4c: A9104FFC  stp      x28, x19, [sp, #0x100]
//   0x4bce50: 9103C3FD  add      x29, sp, #0xf0
//   0x4bce54: AA0003F3  mov      x19, x0
uint64_t fde_func_15349_0x4bce40(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x004BCE40ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10443FFULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90F7BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9104FFCULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9103C3FDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x97FFF5E4ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB9400A60ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #15358 | PC: 0x4bd578..0x4bd5ac (52 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x4bd578: D503233F  paciasp  
//   0x4bd57c: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x4bd580: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x4bd584: 910003FD  mov      x29, sp
//   0x4bd588: AA0103F3  mov      x19, x1
//   0x4bd58c: AA0003F4  mov      x20, x0
uint64_t fde_func_15358_0x4bd578(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x004BD578ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9014FF4ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0103F3ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F4ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x94032646ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91006280ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #15368 | PC: 0x4bde98..0x4bdf08 (112 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x4bde98: D503233F  paciasp  
//   0x4bde9c: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x4bdea0: F9000BF3  str      x19, [sp, #0x10]
//   0x4bdea4: 910003FD  mov      x29, sp
//   0x4bdea8: AA0003F3  mov      x19, x0
//   0x4bdeac: F940CC00  ldr      x0, [x0, #0x198]
uint64_t fde_func_15368_0x4bde98(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x004BDE98ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF3ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF940CC00ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB40001A0ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB9413008ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #15377 | PC: 0x4be30c..0x4be340 (52 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x4be30c: D503233F  paciasp  
//   0x4be310: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x4be314: F9000BF3  str      x19, [sp, #0x10]
//   0x4be318: 910003FD  mov      x29, sp
//   0x4be31c: AA0003F3  mov      x19, x0
//   0x4be320: 97F4B473  bl       #0x1eb4ec
uint64_t fde_func_15377_0x4be30c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x004BE30CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF3ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x97F4B473ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003E8ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA1303E0ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #15387 | PC: 0x4be64c..0x4be658 (12 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x4be64c: D503245F  bti      c
//   0x4be650: D1010000  sub      x0, x0, #0x40
//   0x4be654: 17FFFFB6  b        #0x4be52c
uint64_t fde_func_15387_0x4be64c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x004BE64CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD1010000ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x17FFFFB6ULL ^ (2ULL << 32);
    return state ^ (state >> 29);
}

// FDE #15396 | PC: 0x4be94c..0x4be9c8 (124 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x4be94c: D503233F  paciasp  
//   0x4be950: D100C3FF  sub      sp, sp, #0x30
//   0x4be954: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x4be958: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x4be95c: 910043FD  add      x29, sp, #0x10
//   0x4be960: AA0003F3  mov      x19, x0
uint64_t fde_func_15396_0x4be94c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x004BE94CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD100C3FFULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9024FF4ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x97F8C728ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x36000060ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #15406 | PC: 0x4bef6c..0x4bf040 (212 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x4bef6c: D503233F  paciasp  
//   0x4bef70: A9BD7BFD  stp      x29, x30, [sp, #-0x30]!
//   0x4bef74: F9000BF5  str      x21, [sp, #0x10]
//   0x4bef78: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x4bef7c: 910003FD  mov      x29, sp
//   0x4bef80: B0000768  adrp     x8, #0x5ab000
uint64_t fde_func_15406_0x4bef6c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x004BEF6CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BD7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF5ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9024FF4ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB0000768ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91310108ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB0000769ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #15415 | PC: 0x4bf238..0x4bf244 (12 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x4bf238: D503245F  bti      c
//   0x4bf23c: D1008000  sub      x0, x0, #0x20
//   0x4bf240: 17FFFFCA  b        #0x4bf168
uint64_t fde_func_15415_0x4bf238(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x004BF238ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD1008000ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x17FFFFCAULL ^ (2ULL << 32);
    return state ^ (state >> 29);
}

// FDE #15425 | PC: 0x4bf58c..0x4bf5c8 (60 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x4bf58c: D503233F  paciasp  
//   0x4bf590: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x4bf594: F9000BF3  str      x19, [sp, #0x10]
//   0x4bf598: 910003FD  mov      x29, sp
//   0x4bf59c: AA0003F3  mov      x19, x0
//   0x4bf5a0: F9401000  ldr      x0, [x0, #0x20]
uint64_t fde_func_15425_0x4bf58c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x004BF58CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF3ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9401000ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x90000768ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91354108ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #15434 | PC: 0x4bfb20..0x4bfb38 (24 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x4bfb20: D503245F  bti      c
//   0x4bfb24: 2A0103E8  mov      w8, w1
//   0x4bfb28: 52800021  mov      w1, #1
//   0x4bfb2c: B9009002  str      w2, [x0, #0x90]
//   0x4bfb30: B9008808  str      w8, [x0, #0x88]
//   0x4bfb34: 14000013  b        #0x4bfb80
uint64_t fde_func_15434_0x4bfb20(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x004BFB20ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x2A0103E8ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x52800021ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB9009002ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB9008808ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x14000013ULL ^ (5ULL << 32);
    return state ^ (state >> 29);
}

// FDE #15444 | PC: 0x4bfdcc..0x4bfe24 (88 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x4bfdcc: D503233F  paciasp  
//   0x4bfdd0: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x4bfdd4: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x4bfdd8: 910003FD  mov      x29, sp
//   0x4bfddc: AA0003F4  mov      x20, x0
//   0x4bfde0: 91032000  add      x0, x0, #0xc8
uint64_t fde_func_15444_0x4bfdcc(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x004BFDCCULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9014FF4ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F4ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91032000ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0103F3ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x97FAE093ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #15453 | PC: 0x4c04c8..0x4c05c8 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x4c04c8: D503233F  paciasp  
//   0x4c04cc: D10183FF  sub      sp, sp, #0x60
//   0x4c04d0: A9037BFD  stp      x29, x30, [sp, #0x30]
//   0x4c04d4: F90023F5  str      x21, [sp, #0x40]
//   0x4c04d8: A9054FF4  stp      x20, x19, [sp, #0x50]
//   0x4c04dc: 9100C3FD  add      x29, sp, #0x30
uint64_t fde_func_15453_0x4c04c8(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x004C04C8ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10183FFULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9037BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF90023F5ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9054FF4ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9100C3FDULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x97F89CB5ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #15463 | PC: 0x4c0cfc..0x4c0d84 (136 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x4c0cfc: D503233F  paciasp  
//   0x4c0d00: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x4c0d04: F9000BF3  str      x19, [sp, #0x10]
//   0x4c0d08: 910003FD  mov      x29, sp
//   0x4c0d0c: 528003C8  mov      w8, #0x1e
//   0x4c0d10: 52800029  mov      w9, #1
uint64_t fde_func_15463_0x4c0cfc(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x004C0CFCULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF3ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x528003C8ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x52800029ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x3900001FULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #15473 | PC: 0x4c1d90..0x4c1dac (28 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x4c1d90: D503245F  bti      c
//   0x4c1d94: B9416808  ldr      w8, [x0, #0x168]
//   0x4c1d98: 6B01011F  cmp      w8, w1
//   0x4c1d9c: 54000041  b.ne     #0x4c1da4
//   0x4c1da0: D65F03C0  ret      
//   0x4c1da4: B9016801  str      w1, [x0, #0x168]
uint64_t fde_func_15473_0x4c1d90(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x004C1D90ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB9416808ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x6B01011FULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x54000041ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD65F03C0ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB9016801ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x1400005AULL ^ (6ULL << 32);
    return state ^ (state >> 29);
}

// FDE #15482 | PC: 0x4c1e38..0x4c1e44 (12 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x4c1e38: D503245F  bti      c
//   0x4c1e3c: D1010000  sub      x0, x0, #0x40
//   0x4c1e40: 17FFFC2B  b        #0x4c0eec
uint64_t fde_func_15482_0x4c1e38(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x004C1E38ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD1010000ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x17FFFC2BULL ^ (2ULL << 32);
    return state ^ (state >> 29);
}

// FDE #15492 | PC: 0x4c1eb0..0x4c1ebc (12 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x4c1eb0: D503245F  bti      c
//   0x4c1eb4: D101A000  sub      x0, x0, #0x68
//   0x4c1eb8: 17FFFBC1  b        #0x4c0dbc
uint64_t fde_func_15492_0x4c1eb0(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x004C1EB0ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD101A000ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x17FFFBC1ULL ^ (2ULL << 32);
    return state ^ (state >> 29);
}

// FDE #15501 | PC: 0x4c2020..0x4c2120 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x4c2020: D503233F  paciasp  
//   0x4c2024: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x4c2028: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x4c202c: 910003FD  mov      x29, sp
//   0x4c2030: AA0003F3  mov      x19, x0
//   0x4c2034: 91064000  add      x0, x0, #0x190
uint64_t fde_func_15501_0x4c2020(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x004C2020ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9014FF4ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91064000ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x97F72525ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x39456268ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #15511 | PC: 0x4c2738..0x4c2784 (76 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x4c2738: D503233F  paciasp  
//   0x4c273c: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x4c2740: F9000BF3  str      x19, [sp, #0x10]
//   0x4c2744: 910003FD  mov      x29, sp
//   0x4c2748: AA0003F3  mov      x19, x0
//   0x4c274c: F940A800  ldr      x0, [x0, #0x150]
uint64_t fde_func_15511_0x4c2738(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x004C2738ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF3ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF940A800ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB4000120ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x97FFF26CULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #15520 | PC: 0x4c2b44..0x4c2c44 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x4c2b44: D503233F  paciasp  
//   0x4c2b48: D10203FF  sub      sp, sp, #0x80
//   0x4c2b4c: A9057BFD  stp      x29, x30, [sp, #0x50]
//   0x4c2b50: A90657F6  stp      x22, x21, [sp, #0x60]
//   0x4c2b54: A9074FF4  stp      x20, x19, [sp, #0x70]
//   0x4c2b58: 910143FD  add      x29, sp, #0x50
uint64_t fde_func_15520_0x4c2b44(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x004C2B44ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10203FFULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9057BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90657F6ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9074FF4ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910143FDULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x97F89316ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #15530 | PC: 0x4c3158..0x4c3258 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x4c3158: D503233F  paciasp  
//   0x4c315c: D102C3FF  sub      sp, sp, #0xb0
//   0x4c3160: A9087BFD  stp      x29, x30, [sp, #0x80]
//   0x4c3164: A90957F6  stp      x22, x21, [sp, #0x90]
//   0x4c3168: A90A4FF4  stp      x20, x19, [sp, #0xa0]
//   0x4c316c: 910203FD  add      x29, sp, #0x80
uint64_t fde_func_15530_0x4c3158(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x004C3158ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD102C3FFULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9087BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90957F6ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90A4FF4ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910203FDULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F5ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF900A402ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #15539 | PC: 0x4c3550..0x4c3570 (32 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x4c3550: D503245F  bti      c
//   0x4c3554: F9404808  ldr      x8, [x0, #0x90]
//   0x4c3558: F9410508  ldr      x8, [x8, #0x208]
//   0x4c355c: B4000068  cbz      x8, #0x4c3568
//   0x4c3560: F9404C00  ldr      x0, [x0, #0x98]
//   0x4c3564: 17FAA832  b        #0x36d62c
uint64_t fde_func_15539_0x4c3550(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x004C3550ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9404808ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9410508ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB4000068ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9404C00ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x17FAA832ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0103E0ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x17FC553CULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #15549 | PC: 0x4c3db8..0x4c3dd4 (28 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x4c3db8: D503245F  bti      c
//   0x4c3dbc: 91004001  add      x1, x0, #0x10
//   0x4c3dc0: A9542000  ldp      x0, x8, [x0, #0x140]
//   0x4c3dc4: F940F902  ldr      x2, [x8, #0x1f0]
//   0x4c3dc8: 91012103  add      x3, x8, #0x48
//   0x4c3dcc: F9404504  ldr      x4, [x8, #0x88]
uint64_t fde_func_15549_0x4c3db8(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x004C3DB8ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91004001ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9542000ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF940F902ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91012103ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9404504ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x14002618ULL ^ (6ULL << 32);
    return state ^ (state >> 29);
}

// FDE #15558 | PC: 0x4c4358..0x4c43b4 (92 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x4c4358: D503233F  paciasp  
//   0x4c435c: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x4c4360: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x4c4364: 910003FD  mov      x29, sp
//   0x4c4368: AA0103F3  mov      x19, x1
//   0x4c436c: AA0003F4  mov      x20, x0
uint64_t fde_func_15558_0x4c4358(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x004C4358ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9014FF4ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0103F3ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F4ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910DE000ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0203E1ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #15568 | PC: 0x4c4a8c..0x4c4b8c (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x4c4a8c: D503233F  paciasp  
//   0x4c4a90: D10303FF  sub      sp, sp, #0xc0
//   0x4c4a94: A9067BFD  stp      x29, x30, [sp, #0x60]
//   0x4c4a98: A9076FFC  stp      x28, x27, [sp, #0x70]
//   0x4c4a9c: A90867FA  stp      x26, x25, [sp, #0x80]
//   0x4c4aa0: A9095FF8  stp      x24, x23, [sp, #0x90]
uint64_t fde_func_15568_0x4c4a8c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x004C4A8CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10303FFULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9067BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9076FFCULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90867FAULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9095FF8ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90A57F6ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90B4FF4ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #15577 | PC: 0x4c579c..0x4c57e0 (68 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x4c579c: D503233F  paciasp  
//   0x4c57a0: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x4c57a4: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x4c57a8: 910003FD  mov      x29, sp
//   0x4c57ac: AA0003F4  mov      x20, x0
//   0x4c57b0: 52800400  mov      w0, #0x20
uint64_t fde_func_15577_0x4c579c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x004C579CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9014FF4ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F4ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x52800400ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x2A0103F3ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x97F85B6FULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #15587 | PC: 0x4c59d8..0x4c5a4c (116 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x4c59d8: D503233F  paciasp  
//   0x4c59dc: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x4c59e0: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x4c59e4: 910003FD  mov      x29, sp
//   0x4c59e8: A944A809  ldp      x9, x10, [x0, #0x48]
//   0x4c59ec: AA0003F4  mov      x20, x0
uint64_t fde_func_15587_0x4c59d8(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x004C59D8ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9014FF4ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA944A809ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F4ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x93407C48ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9062001ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #15596 | PC: 0x4c5d7c..0x4c5d88 (12 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x4c5d7c: D503245F  bti      c
//   0x4c5d80: D1002000  sub      x0, x0, #8
//   0x4c5d84: 17FFFF6E  b        #0x4c5b3c
uint64_t fde_func_15596_0x4c5d7c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x004C5D7CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD1002000ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x17FFFF6EULL ^ (2ULL << 32);
    return state ^ (state >> 29);
}

// FDE #15606 | PC: 0x4c5f18..0x4c5fdc (196 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x4c5f18: D503233F  paciasp  
//   0x4c5f1c: D10143FF  sub      sp, sp, #0x50
//   0x4c5f20: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x4c5f24: F9001BF5  str      x21, [sp, #0x30]
//   0x4c5f28: A9044FF4  stp      x20, x19, [sp, #0x40]
//   0x4c5f2c: 910083FD  add      x29, sp, #0x20
uint64_t fde_func_15606_0x4c5f18(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x004C5F18ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10143FFULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9027BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9001BF5ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9044FF4ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910083FDULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x52800088ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9107C002ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #15615 | PC: 0x4c6d68..0x4c6e68 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x4c6d68: D503233F  paciasp  
//   0x4c6d6c: D10743FF  sub      sp, sp, #0x1d0
//   0x4c6d70: A9187BFD  stp      x29, x30, [sp, #0x180]
//   0x4c6d74: A91967FC  stp      x28, x25, [sp, #0x190]
//   0x4c6d78: A91A5FF8  stp      x24, x23, [sp, #0x1a0]
//   0x4c6d7c: A91B57F6  stp      x22, x21, [sp, #0x1b0]
uint64_t fde_func_15615_0x4c6d68(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x004C6D68ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10743FFULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9187BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA91967FCULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA91A5FF8ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA91B57F6ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA91C4FF4ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910603FDULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #15625 | PC: 0x4c7474..0x4c7574 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x4c7474: D503233F  paciasp  
//   0x4c7478: D10183FF  sub      sp, sp, #0x60
//   0x4c747c: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x4c7480: F9001BF7  str      x23, [sp, #0x30]
//   0x4c7484: A90457F6  stp      x22, x21, [sp, #0x40]
//   0x4c7488: A9054FF4  stp      x20, x19, [sp, #0x50]
uint64_t fde_func_15625_0x4c7474(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x004C7474ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10183FFULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9027BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9001BF7ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90457F6ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9054FF4ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910083FDULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #15634 | PC: 0x4c7a3c..0x4c7b3c (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x4c7a3c: D503233F  paciasp  
//   0x4c7a40: A9BD7BFD  stp      x29, x30, [sp, #-0x30]!
//   0x4c7a44: F9000BF5  str      x21, [sp, #0x10]
//   0x4c7a48: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x4c7a4c: 910003FD  mov      x29, sp
//   0x4c7a50: AA0003F3  mov      x19, x0
uint64_t fde_func_15634_0x4c7a3c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x004C7A3CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BD7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF5ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9024FF4ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB0000728ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9124C108ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #15644 | PC: 0x4c7ea8..0x4c7ecc (36 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x4c7ea8: D503245F  bti      c
//   0x4c7eac: F9400408  ldr      x8, [x0, #8]
//   0x4c7eb0: F9400020  ldr      x0, [x1]
//   0x4c7eb4: F900003F  str      xzr, [x1]
//   0x4c7eb8: F9409108  ldr      x8, [x8, #0x120]
//   0x4c7ebc: F9400508  ldr      x8, [x8, #8]
uint64_t fde_func_15644_0x4c7ea8(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x004C7EA8ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400408ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400020ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF900003FULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9409108ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400508ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB4000040ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x1400160AULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #15653 | PC: 0x4c87c4..0x4c8824 (96 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x4c87c4: D503233F  paciasp  
//   0x4c87c8: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x4c87cc: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x4c87d0: 910003FD  mov      x29, sp
//   0x4c87d4: AA0003F3  mov      x19, x0
//   0x4c87d8: 34000142  cbz      w2, #0x4c8800
uint64_t fde_func_15653_0x4c87c4(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x004C87C4ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9014FF4ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x34000142ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0103E0ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x2A0203F4ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #15663 | PC: 0x4c9280..0x4c9380 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x4c9280: D503233F  paciasp  
//   0x4c9284: A9BB7BFD  stp      x29, x30, [sp, #-0x50]!
//   0x4c9288: A90167FA  stp      x26, x25, [sp, #0x10]
//   0x4c928c: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x4c9290: A90357F6  stp      x22, x21, [sp, #0x30]
//   0x4c9294: A9044FF4  stp      x20, x19, [sp, #0x40]
uint64_t fde_func_15663_0x4c9280(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x004C9280ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BB7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90167FAULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9025FF8ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90357F6ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9044FF4ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91004014ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #15672 | PC: 0x4c96d4..0x4c9710 (60 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x4c96d4: D503233F  paciasp  
//   0x4c96d8: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x4c96dc: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x4c96e0: 910003FD  mov      x29, sp
//   0x4c96e4: AA0103F3  mov      x19, x1
//   0x4c96e8: AA0003F4  mov      x20, x0
uint64_t fde_func_15672_0x4c96d4(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x004C96D4ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9014FF4ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0103F3ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F4ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x97F3FBC2ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91006000ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #15682 | PC: 0x4c9f70..0x4c9fa4 (52 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x4c9f70: D503233F  paciasp  
//   0x4c9f74: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x4c9f78: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x4c9f7c: 910003FD  mov      x29, sp
//   0x4c9f80: AA0203F3  mov      x19, x2
//   0x4c9f84: AA0003F4  mov      x20, x0
uint64_t fde_func_15682_0x4c9f70(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x004C9F70ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9014FF4ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0203F3ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F4ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x94028E31ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA907FE9FULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #15691 | PC: 0x4caec4..0x4cafc4 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x4caec4: D503233F  paciasp  
//   0x4caec8: D10303FF  sub      sp, sp, #0xc0
//   0x4caecc: A9067BFD  stp      x29, x30, [sp, #0x60]
//   0x4caed0: F9003BFB  str      x27, [sp, #0x70]
//   0x4caed4: A90867FA  stp      x26, x25, [sp, #0x80]
//   0x4caed8: A9095FF8  stp      x24, x23, [sp, #0x90]
uint64_t fde_func_15691_0x4caec4(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x004CAEC4ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10303FFULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9067BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9003BFBULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90867FAULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9095FF8ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90A57F6ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90B4FF4ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #15701 | PC: 0x4cb990..0x4cb9d4 (68 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x4cb990: D503233F  paciasp  
//   0x4cb994: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x4cb998: F9000BF3  str      x19, [sp, #0x10]
//   0x4cb99c: 910003FD  mov      x29, sp
//   0x4cb9a0: 91048013  add      x19, x0, #0x120
//   0x4cb9a4: AA1303E0  mov      x0, x19
uint64_t fde_func_15701_0x4cb990(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x004CB990ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF3ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91048013ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA1303E0ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x97F43E61ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x360000A0ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #15710 | PC: 0x4cbcd4..0x4cbd40 (108 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x4cbcd4: D503233F  paciasp  
//   0x4cbcd8: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x4cbcdc: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x4cbce0: 910003FD  mov      x29, sp
//   0x4cbce4: F940D013  ldr      x19, [x0, #0x1a0]
//   0x4cbce8: B4000173  cbz      x19, #0x4cbd14
uint64_t fde_func_15710_0x4cbcd4(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x004CBCD4ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9014FF4ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF940D013ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB4000173ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x885F7E68ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x11000508ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #15720 | PC: 0x4cc0dc..0x4cc0fc (32 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x4cc0dc: D503245F  bti      c
//   0x4cc0e0: A942A408  ldp      x8, x9, [x0, #0x28]
//   0x4cc0e4: F9407801  ldr      x1, [x0, #0xf0]
//   0x4cc0e8: AA0803E0  mov      x0, x8
//   0x4cc0ec: F940F922  ldr      x2, [x9, #0x1f0]
//   0x4cc0f0: 91012123  add      x3, x9, #0x48
uint64_t fde_func_15720_0x4cc0dc(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x004CC0DCULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA942A408ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9407801ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0803E0ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF940F922ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91012123ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9404524ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x1400054EULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #15729 | PC: 0x4cc700..0x4cc800 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x4cc700: D503233F  paciasp  
//   0x4cc704: A9BC7BFD  stp      x29, x30, [sp, #-0x40]!
//   0x4cc708: F9000BF7  str      x23, [sp, #0x10]
//   0x4cc70c: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x4cc710: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x4cc714: 910003FD  mov      x29, sp
uint64_t fde_func_15729_0x4cc700(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x004CC700ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BC7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF7ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90257F6ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9034FF4ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91000435ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xEB55F7FFULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #15739 | PC: 0x4cd3b0..0x4cd4b0 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x4cd3b0: D503233F  paciasp  
//   0x4cd3b4: D10203FF  sub      sp, sp, #0x80
//   0x4cd3b8: A9037BFD  stp      x29, x30, [sp, #0x30]
//   0x4cd3bc: A90467FA  stp      x26, x25, [sp, #0x40]
//   0x4cd3c0: A9055FF8  stp      x24, x23, [sp, #0x50]
//   0x4cd3c4: A90657F6  stp      x22, x21, [sp, #0x60]
uint64_t fde_func_15739_0x4cd3b0(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x004CD3B0ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10203FFULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9037BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90467FAULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9055FF8ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90657F6ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9074FF4ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9100C3FDULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #15748 | PC: 0x4cd880..0x4cd8ec (108 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x4cd880: D503233F  paciasp  
//   0x4cd884: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x4cd888: F9000BF3  str      x19, [sp, #0x10]
//   0x4cd88c: 910003FD  mov      x29, sp
//   0x4cd890: AA0003F3  mov      x19, x0
//   0x4cd894: F00006E8  adrp     x8, #0x5ac000
uint64_t fde_func_15748_0x4cd880(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x004CD880ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF3ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF00006E8ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91324108ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9403400ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #15758 | PC: 0x4cdc64..0x4cdcbc (88 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x4cdc64: D503245F  bti      c
//   0x4cdc68: B4000281  cbz      x1, #0x4cdcb8
//   0x4cdc6c: D503233F  paciasp  
//   0x4cdc70: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x4cdc74: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x4cdc78: 910003FD  mov      x29, sp
uint64_t fde_func_15758_0x4cdc64(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x004CDC64ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB4000281ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE7BFDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9014FF4ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0103F3ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F4ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #15768 | PC: 0x4ce200..0x4ce250 (80 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x4ce200: D503233F  paciasp  
//   0x4ce204: A9BD7BFD  stp      x29, x30, [sp, #-0x30]!
//   0x4ce208: F9000BF5  str      x21, [sp, #0x10]
//   0x4ce20c: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x4ce210: 910003FD  mov      x29, sp
//   0x4ce214: A942A428  ldp      x8, x9, [x1, #0x28]
uint64_t fde_func_15768_0x4ce200(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x004CE200ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BD7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF5ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9024FF4ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA942A428ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA090108ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB4000108ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #15777 | PC: 0x4cea44..0x4cea8c (72 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x4cea44: D503233F  paciasp  
//   0x4cea48: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x4cea4c: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x4cea50: 910003FD  mov      x29, sp
//   0x4cea54: AA0103F4  mov      x20, x1
//   0x4cea58: AA0003F3  mov      x19, x0
uint64_t fde_func_15777_0x4cea44(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x004CEA44ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9014FF4ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0103F4ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x97F86357ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x3940E268ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #15787 | PC: 0x4cf284..0x4cf290 (12 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x4cf284: D503245F  bti      c
//   0x4cf288: D1004000  sub      x0, x0, #0x10
//   0x4cf28c: 17FFFEEE  b        #0x4cee44
uint64_t fde_func_15787_0x4cf284(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x004CF284ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD1004000ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x17FFFEEEULL ^ (2ULL << 32);
    return state ^ (state >> 29);
}

// FDE #15796 | PC: 0x4cf9a4..0x4cf9b0 (12 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x4cf9a4: D503245F  bti      c
//   0x4cf9a8: 52800141  mov      w1, #0xa
//   0x4cf9ac: 14000137  b        #0x4cfe88
uint64_t fde_func_15796_0x4cf9a4(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x004CF9A4ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x52800141ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x14000137ULL ^ (2ULL << 32);
    return state ^ (state >> 29);
}

// FDE #15806 | PC: 0x4cfd9c..0x4cfdbc (32 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x4cfd9c: D503245F  bti      c
//   0x4cfda0: 7102041F  cmp      w0, #0x81
//   0x4cfda4: 5400004A  b.ge     #0x4cfdac
//   0x4cfda8: D65F03C0  ret      
//   0x4cfdac: D503233F  paciasp  
//   0x4cfdb0: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
uint64_t fde_func_15806_0x4cfd9c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x004CFD9CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x7102041FULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x5400004AULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD65F03C0ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BF7BFDULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9402DC5AULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #15815 | PC: 0x4d04e4..0x4d05e4 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x4d04e4: D503233F  paciasp  
//   0x4d04e8: A9BB7BFD  stp      x29, x30, [sp, #-0x50]!
//   0x4d04ec: A90167FA  stp      x26, x25, [sp, #0x10]
//   0x4d04f0: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x4d04f4: A90357F6  stp      x22, x21, [sp, #0x30]
//   0x4d04f8: A9044FF4  stp      x20, x19, [sp, #0x40]
uint64_t fde_func_15815_0x4d04e4(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x004D04E4ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BB7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90167FAULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9025FF8ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90357F6ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9044FF4ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0203F3ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #15825 | PC: 0x4d26cc..0x4d2714 (72 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x4d26cc: D503233F  paciasp  
//   0x4d26d0: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x4d26d4: F9000BF3  str      x19, [sp, #0x10]
//   0x4d26d8: 910003FD  mov      x29, sp
//   0x4d26dc: AA0103F3  mov      x19, x1
//   0x4d26e0: 360000A2  tbz      w2, #0, #0x4d26f4
uint64_t fde_func_15825_0x4d26cc(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x004D26CCULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF3ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0103F3ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x360000A2ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x940000E3ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x2A0003E8ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #15834 | PC: 0x4d2b2c..0x4d2b78 (76 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x4d2b2c: D503245F  bti      c
//   0x4d2b30: B201E7EB  mov      x11, #-0x6666666666666667
//   0x4d2b34: AA0003E8  mov      x8, x0
//   0x4d2b38: F293330B  movk     x11, #0x9998
//   0x4d2b3c: AA1F03E9  mov      x9, xzr
//   0x4d2b40: AA1F03E0  mov      x0, xzr
uint64_t fde_func_15834_0x4d2b2c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x004D2B2CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB201E7EBULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003E8ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF293330BULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA1F03E9ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA1F03E0ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x93407C2AULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF2E3332BULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #15844 | PC: 0x4d3440..0x4d34ac (108 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x4d3440: D503245F  bti      c
//   0x4d3444: 34000261  cbz      w1, #0x4d3490
//   0x4d3448: 51000429  sub      w9, w1, #1
//   0x4d344c: F940000B  ldr      x11, [x0]
//   0x4d3450: 53017D28  lsr      w8, w9, #1
//   0x4d3454: F940284D  ldr      x13, [x2, #0x50]
uint64_t fde_func_15844_0x4d3440(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x004D3440ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x34000261ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x51000429ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF940000BULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x53017D28ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF940284DULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF868596AULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF940294CULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #15853 | PC: 0x4d408c..0x4d4110 (132 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x4d408c: D503233F  paciasp  
//   0x4d4090: D10443FF  sub      sp, sp, #0x110
//   0x4d4094: A90F7BFD  stp      x29, x30, [sp, #0xf0]
//   0x4d4098: A9104FFC  stp      x28, x19, [sp, #0x100]
//   0x4d409c: 9103C3FD  add      x29, sp, #0xf0
//   0x4d40a0: 910003E8  mov      x8, sp
uint64_t fde_func_15853_0x4d408c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x004D408CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10443FFULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90F7BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9104FFCULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9103C3FDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003E8ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x928005E9ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD101C3AAULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #15863 | PC: 0x4d48ec..0x4d495c (112 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x4d48ec: D503233F  paciasp  
//   0x4d48f0: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x4d48f4: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x4d48f8: 910003FD  mov      x29, sp
//   0x4d48fc: AA0003F3  mov      x19, x0
//   0x4d4900: 97FFFDCF  bl       #0x4d403c
uint64_t fde_func_15863_0x4d48ec(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x004D48ECULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9014FF4ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x97FFFDCFULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x34000200ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x52800020ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #15872 | PC: 0x4d5114..0x4d51d8 (196 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x4d5114: D503233F  paciasp  
//   0x4d5118: A9BD7BFD  stp      x29, x30, [sp, #-0x30]!
//   0x4d511c: F9000BF5  str      x21, [sp, #0x10]
//   0x4d5120: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x4d5124: 910003FD  mov      x29, sp
//   0x4d5128: 79408808  ldrh     w8, [x0, #0x44]
uint64_t fde_func_15872_0x4d5114(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x004D5114ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BD7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF5ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9024FF4ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x79408808ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x721F051FULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x540004A1ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #15882 | PC: 0x4d5958..0x4d59a8 (80 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x4d5958: D503233F  paciasp  
//   0x4d595c: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x4d5960: F9000BF3  str      x19, [sp, #0x10]
//   0x4d5964: 910003FD  mov      x29, sp
//   0x4d5968: AA0103F3  mov      x19, x1
//   0x4d596c: 97FFFE95  bl       #0x4d53c0
uint64_t fde_func_15882_0x4d5958(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x004D5958ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF3ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0103F3ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x97FFFE95ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400260ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB4000040ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #15891 | PC: 0x4d5c00..0x4d5c48 (72 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x4d5c00: D503233F  paciasp  
//   0x4d5c04: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x4d5c08: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x4d5c0c: 910003FD  mov      x29, sp
//   0x4d5c10: AA0003F3  mov      x19, x0
//   0x4d5c14: 91006014  add      x20, x0, #0x18
uint64_t fde_func_15891_0x4d5c00(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x004D5C00ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9014FF4ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91006014ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9401260ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xEB14001FULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #15901 | PC: 0x4d5fe0..0x4d6018 (56 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x4d5fe0: D503233F  paciasp  
//   0x4d5fe4: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x4d5fe8: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x4d5fec: 910003FD  mov      x29, sp
//   0x4d5ff0: F9402014  ldr      x20, [x0, #0x40]
//   0x4d5ff4: AA0803F3  mov      x19, x8
uint64_t fde_func_15901_0x4d5fe0(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x004D5FE0ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9014FF4ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9402014ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0803F3ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA1403E0ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x97F7F3E4ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #15910 | PC: 0x4d6420..0x4d6478 (88 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x4d6420: D503233F  paciasp  
//   0x4d6424: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x4d6428: F9000BF3  str      x19, [sp, #0x10]
//   0x4d642c: 910003FD  mov      x29, sp
//   0x4d6430: AA0003F3  mov      x19, x0
//   0x4d6434: 91008000  add      x0, x0, #0x20
uint64_t fde_func_15910_0x4d6420(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x004D6420ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF3ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91008000ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910063A8ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9400029CULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #15920 | PC: 0x4d6b14..0x4d6be8 (212 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x4d6b14: D503233F  paciasp  
//   0x4d6b18: D10143FF  sub      sp, sp, #0x50
//   0x4d6b1c: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x4d6b20: F9001BF5  str      x21, [sp, #0x30]
//   0x4d6b24: A9044FF4  stp      x20, x19, [sp, #0x40]
//   0x4d6b28: 910083FD  add      x29, sp, #0x20
uint64_t fde_func_15920_0x4d6b14(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x004D6B14ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10143FFULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9027BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9001BF5ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9044FF4ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910083FDULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0203F3ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0103F4ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #15929 | PC: 0x4d7278..0x4d72dc (100 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x4d7278: D503233F  paciasp  
//   0x4d727c: A9BD7BFD  stp      x29, x30, [sp, #-0x30]!
//   0x4d7280: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x4d7284: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x4d7288: 910003FD  mov      x29, sp
//   0x4d728c: AA0003F4  mov      x20, x0
uint64_t fde_func_15929_0x4d7278(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x004D7278ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BD7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90157F6ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9024FF4ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F4ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x52800100ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0103F3ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #15939 | PC: 0x4d76d0..0x4d7784 (180 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x4d76d0: D503233F  paciasp  
//   0x4d76d4: A9BC7BFD  stp      x29, x30, [sp, #-0x40]!
//   0x4d76d8: F9000BF7  str      x23, [sp, #0x10]
//   0x4d76dc: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x4d76e0: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x4d76e4: 910003FD  mov      x29, sp
uint64_t fde_func_15939_0x4d76d0(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x004D76D0ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BC7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF7ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90257F6ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9034FF4ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91004016ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0203F3ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #15948 | PC: 0x4d7c18..0x4d7d14 (252 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x4d7c18: D503233F  paciasp  
//   0x4d7c1c: D101C3FF  sub      sp, sp, #0x70
//   0x4d7c20: A9057BFD  stp      x29, x30, [sp, #0x50]
//   0x4d7c24: A9064FF4  stp      x20, x19, [sp, #0x60]
//   0x4d7c28: 910143FD  add      x29, sp, #0x50
//   0x4d7c2c: AA0003F4  mov      x20, x0
uint64_t fde_func_15948_0x4d7c18(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x004D7C18ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD101C3FFULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9057BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9064FF4ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910143FDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F4ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400400ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0103F3ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #15958 | PC: 0x4d84fc..0x4d8504 (8 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x4d84fc: D503245F  bti      c
//   0x4d8500: 17FFFE37  b        #0x4d7ddc
uint64_t fde_func_15958_0x4d84fc(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x004D84FCULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x17FFFE37ULL ^ (1ULL << 32);
    return state ^ (state >> 29);
}

// FDE #15967 | PC: 0x4d8e2c..0x4d8e84 (88 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x4d8e2c: D503233F  paciasp  
//   0x4d8e30: D10083FF  sub      sp, sp, #0x20
//   0x4d8e34: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x4d8e38: 910043FD  add      x29, sp, #0x10
//   0x4d8e3c: F9400028  ldr      x8, [x1]
//   0x4d8e40: F900003F  str      xzr, [x1]
uint64_t fde_func_15967_0x4d8e2c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x004D8E2CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10083FFULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400028ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF900003FULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400049ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF900005FULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #15977 | PC: 0x4d9cd0..0x4d9cec (28 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x4d9cd0: D503245F  bti      c
//   0x4d9cd4: AA0003E8  mov      x8, x0
//   0x4d9cd8: F9400800  ldr      x0, [x0, #0x10]
//   0x4d9cdc: 900006A9  adrp     x9, #0x5ad000
//   0x4d9ce0: 910CC129  add      x9, x9, #0x330
//   0x4d9ce4: F9000109  str      x9, [x8]
uint64_t fde_func_15977_0x4d9cd0(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x004D9CD0ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003E8ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400800ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x900006A9ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910CC129ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000109ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x1400000CULL ^ (6ULL << 32);
    return state ^ (state >> 29);
}

// FDE #15986 | PC: 0x4d9f50..0x4da010 (192 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x4d9f50: D503233F  paciasp  
//   0x4d9f54: D10143FF  sub      sp, sp, #0x50
//   0x4d9f58: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x4d9f5c: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x4d9f60: A90357F6  stp      x22, x21, [sp, #0x30]
//   0x4d9f64: A9044FF4  stp      x20, x19, [sp, #0x40]
uint64_t fde_func_15986_0x4d9f50(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x004D9F50ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10143FFULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9025FF8ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90357F6ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9044FF4ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x2A0103E8ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #15996 | PC: 0x4da1f8..0x4da2bc (196 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x4da1f8: D503233F  paciasp  
//   0x4da1fc: A9BD7BFD  stp      x29, x30, [sp, #-0x30]!
//   0x4da200: F9000BF5  str      x21, [sp, #0x10]
//   0x4da204: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x4da208: 910003FD  mov      x29, sp
//   0x4da20c: B9401035  ldr      w21, [x1, #0x10]
uint64_t fde_func_15996_0x4da1f8(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x004DA1F8ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BD7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF5ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9024FF4ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB9401035ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0103F4ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #16005 | PC: 0x4daa10..0x4daa1c (12 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x4daa10: D503245F  bti      c
//   0x4daa14: B9405C02  ldr      w2, [x0, #0x5c]
//   0x4daa18: 14000083  b        #0x4dac24
uint64_t fde_func_16005_0x4daa10(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x004DAA10ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB9405C02ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x14000083ULL ^ (2ULL << 32);
    return state ^ (state >> 29);
}

// FDE #16015 | PC: 0x4dadf4..0x4daef4 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x4dadf4: D503233F  paciasp  
//   0x4dadf8: A9BC7BFD  stp      x29, x30, [sp, #-0x40]!
//   0x4dadfc: F9000BF7  str      x23, [sp, #0x10]
//   0x4dae00: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x4dae04: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x4dae08: 910003FD  mov      x29, sp
uint64_t fde_func_16015_0x4dadf4(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x004DADF4ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BC7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF7ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90257F6ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9034FF4ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400408ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD00006C9ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #16024 | PC: 0x4db378..0x4db3b0 (56 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x4db378: D503245F  bti      c
//   0x4db37c: AA0003E8  mov      x8, x0
//   0x4db380: 9100402A  add      x10, x1, #0x10
//   0x4db384: A942A400  ldp      x0, x9, [x0, #0x28]
//   0x4db388: CB00012B  sub      x11, x9, x0
//   0x4db38c: EB0A017F  cmp      x11, x10
uint64_t fde_func_16024_0x4db378(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x004DB378ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003E8ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9100402AULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA942A400ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xCB00012BULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xEB0A017FULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x540000C3ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD1004129ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #16034 | PC: 0x4db92c..0x4db99c (112 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x4db92c: D503233F  paciasp  
//   0x4db930: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x4db934: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x4db938: 910003FD  mov      x29, sp
//   0x4db93c: F9400008  ldr      x8, [x0]
//   0x4db940: AA0103F3  mov      x19, x1
uint64_t fde_func_16034_0x4db92c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x004DB92CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9014FF4ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400008ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0103F3ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF240091FULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x540001E0ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #16043 | PC: 0x4dbca8..0x4dbd08 (96 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x4dbca8: D503233F  paciasp  
//   0x4dbcac: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x4dbcb0: F9000BF3  str      x19, [sp, #0x10]
//   0x4dbcb4: 910003FD  mov      x29, sp
//   0x4dbcb8: 39C00009  ldrsb    w9, [x0]
//   0x4dbcbc: AA0103F3  mov      x19, x1
uint64_t fde_func_16043_0x4dbca8(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x004DBCA8ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF3ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x39C00009ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0103F3ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x92401D28ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x37F800E9ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #16053 | PC: 0x4dc358..0x4dc3b8 (96 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x4dc358: D503233F  paciasp  
//   0x4dc35c: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x4dc360: F9000BF3  str      x19, [sp, #0x10]
//   0x4dc364: 910003FD  mov      x29, sp
//   0x4dc368: 52800800  mov      w0, #0x40
//   0x4dc36c: AA0803F3  mov      x19, x8
uint64_t fde_func_16053_0x4dc358(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x004DC358ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF3ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x52800800ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0803F3ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x97F80081ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB0FFDE89ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #16063 | PC: 0x4dc8a0..0x4dc9a0 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x4dc8a0: D503233F  paciasp  
//   0x4dc8a4: D10103FF  sub      sp, sp, #0x40
//   0x4dc8a8: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x4dc8ac: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x4dc8b0: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x4dc8b4: 910043FD  add      x29, sp, #0x10
uint64_t fde_func_16063_0x4dc8a0(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x004DC8A0ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10103FFULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90257F6ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9034FF4ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400813ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB40001D3ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #16072 | PC: 0x4dcfe4..0x4dd03c (88 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x4dcfe4: D503233F  paciasp  
//   0x4dcfe8: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x4dcfec: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x4dcff0: 910003FD  mov      x29, sp
//   0x4dcff4: AA0103F3  mov      x19, x1
//   0x4dcff8: AA0003F4  mov      x20, x0
uint64_t fde_func_16072_0x4dcfe4(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x004DCFE4ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9014FF4ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0103F3ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F4ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF102001FULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x54000123ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #16082 | PC: 0x4dd700..0x4dd784 (132 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x4dd700: D503233F  paciasp  
//   0x4dd704: A9BD7BFD  stp      x29, x30, [sp, #-0x30]!
//   0x4dd708: F9000BF5  str      x21, [sp, #0x10]
//   0x4dd70c: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x4dd710: 910003FD  mov      x29, sp
//   0x4dd714: B9400808  ldr      w8, [x0, #8]
uint64_t fde_func_16082_0x4dd700(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x004DD700ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BD7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF5ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9024FF4ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB9400808ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x2A0203F3ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F4ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #16091 | PC: 0x4ddb28..0x4ddb94 (108 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x4ddb28: D503233F  paciasp  
//   0x4ddb2c: A9BD7BFD  stp      x29, x30, [sp, #-0x30]!
//   0x4ddb30: F9000BF5  str      x21, [sp, #0x10]
//   0x4ddb34: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x4ddb38: 910003FD  mov      x29, sp
//   0x4ddb3c: AA0003F3  mov      x19, x0
uint64_t fde_func_16091_0x4ddb28(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x004DDB28ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BD7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF5ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9024FF4ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400800ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F4ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #16101 | PC: 0x4de570..0x4de634 (196 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x4de570: D503233F  paciasp  
//   0x4de574: A9BC7BFD  stp      x29, x30, [sp, #-0x40]!
//   0x4de578: A9015FF8  stp      x24, x23, [sp, #0x10]
//   0x4de57c: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x4de580: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x4de584: 910003FD  mov      x29, sp
uint64_t fde_func_16101_0x4de570(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x004DE570ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BC7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9015FF8ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90257F6ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9034FF4ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400428ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0203F5ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #16110 | PC: 0x4ded34..0x4dee34 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x4ded34: D503233F  paciasp  
//   0x4ded38: D10743FF  sub      sp, sp, #0x1d0
//   0x4ded3c: A9177BFD  stp      x29, x30, [sp, #0x170]
//   0x4ded40: A9186FFC  stp      x28, x27, [sp, #0x180]
//   0x4ded44: A91967FA  stp      x26, x25, [sp, #0x190]
//   0x4ded48: A91A5FF8  stp      x24, x23, [sp, #0x1a0]
uint64_t fde_func_16110_0x4ded34(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x004DED34ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10743FFULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9177BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9186FFCULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA91967FAULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA91A5FF8ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA91B57F6ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA91C4FF4ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #16120 | PC: 0x4df324..0x4df3c8 (164 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x4df324: D503233F  paciasp  
//   0x4df328: A9BC7BFD  stp      x29, x30, [sp, #-0x40]!
//   0x4df32c: F9000BF7  str      x23, [sp, #0x10]
//   0x4df330: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x4df334: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x4df338: 910003FD  mov      x29, sp
uint64_t fde_func_16120_0x4df324(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x004DF324ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BC7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF7ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90257F6ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9034FF4ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F7ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910063A0ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #16129 | PC: 0x4df6a4..0x4df6d0 (44 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x4df6a4: D503233F  paciasp  
//   0x4df6a8: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x4df6ac: F9000BF3  str      x19, [sp, #0x10]
//   0x4df6b0: 910003FD  mov      x29, sp
//   0x4df6b4: AA0003F3  mov      x19, x0
//   0x4df6b8: 97FFFFEF  bl       #0x4df674
uint64_t fde_func_16129_0x4df6a4(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x004DF6A4ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF3ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x97FFFFEFULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA1303E0ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400BF3ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #16139 | PC: 0x4dfad8..0x4dfb38 (96 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x4dfad8: D503233F  paciasp  
//   0x4dfadc: D100C3FF  sub      sp, sp, #0x30
//   0x4dfae0: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x4dfae4: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x4dfae8: 910043FD  add      x29, sp, #0x10
//   0x4dfaec: AA0103F3  mov      x19, x1
uint64_t fde_func_16139_0x4dfad8(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x004DFAD8ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD100C3FFULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9024FF4ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0103F3ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10013A1ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F4ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #16148 | PC: 0x4dff14..0x4dff34 (32 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x4dff14: D503245F  bti      c
//   0x4dff18: A940A009  ldp      x9, x8, [x0, #8]
//   0x4dff1c: EB080121  subs     x1, x9, x8
//   0x4dff20: 54000084  b.mi     #0x4dff30
//   0x4dff24: F9400009  ldr      x9, [x0]
//   0x4dff28: 8B080120  add      x0, x9, x8
uint64_t fde_func_16148_0x4dff14(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x004DFF14ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA940A009ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xEB080121ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x54000084ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400009ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x8B080120ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD65F03C0ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD4200020ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #16158 | PC: 0x4e0274..0x4e027c (8 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x4e0274: D503245F  bti      c
//   0x4e0278: 17FFFF7D  b        #0x4e006c
uint64_t fde_func_16158_0x4e0274(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x004E0274ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x17FFFF7DULL ^ (1ULL << 32);
    return state ^ (state >> 29);
}

// FDE #16167 | PC: 0x4e07d4..0x4e081c (72 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x4e07d4: D503233F  paciasp  
//   0x4e07d8: D10103FF  sub      sp, sp, #0x40
//   0x4e07dc: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x4e07e0: F9001BF3  str      x19, [sp, #0x30]
//   0x4e07e4: 910083FD  add      x29, sp, #0x20
//   0x4e07e8: AA0003F3  mov      x19, x0
uint64_t fde_func_16167_0x4e07d4(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x004E07D4ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10103FFULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9027BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9001BF3ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910083FDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910023E0ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x97FFFFE6ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #16177 | PC: 0x4e0a00..0x4e0a58 (88 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x4e0a00: D503233F  paciasp  
//   0x4e0a04: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x4e0a08: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x4e0a0c: 910003FD  mov      x29, sp
//   0x4e0a10: AA0003F4  mov      x20, x0
//   0x4e0a14: AA0103E0  mov      x0, x1
uint64_t fde_func_16177_0x4e0a00(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x004E0A00ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9014FF4ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F4ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0103E0ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0103F3ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x97FFFFC2ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #16186 | PC: 0x4e0fd4..0x4e101c (72 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x4e0fd4: D503245F  bti      c
//   0x4e0fd8: A940A448  ldp      x8, x9, [x2, #8]
//   0x4e0fdc: EB09011F  cmp      x8, x9
//   0x4e0fe0: 54000142  b.hs     #0x4e1008
//   0x4e0fe4: 91000509  add      x9, x8, #1
//   0x4e0fe8: F9000449  str      x9, [x2, #8]
uint64_t fde_func_16186_0x4e0fd4(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x004E0FD4ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA940A448ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xEB09011FULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x54000142ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91000509ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000449ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x39400108ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB9000028ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #16196 | PC: 0x4e21e4..0x4e22e4 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x4e21e4: D503233F  paciasp  
//   0x4e21e8: A9BA7BFD  stp      x29, x30, [sp, #-0x60]!
//   0x4e21ec: A9016FFC  stp      x28, x27, [sp, #0x10]
//   0x4e21f0: A90267FA  stp      x26, x25, [sp, #0x20]
//   0x4e21f4: A9035FF8  stp      x24, x23, [sp, #0x30]
//   0x4e21f8: A90457F6  stp      x22, x21, [sp, #0x40]
uint64_t fde_func_16196_0x4e21e4(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x004E21E4ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BA7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9016FFCULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90267FAULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9035FF8ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90457F6ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9054FF4ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #16205 | PC: 0x4e30ac..0x4e31ac (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x4e30ac: D503233F  paciasp  
//   0x4e30b0: A9BA7BFD  stp      x29, x30, [sp, #-0x60]!
//   0x4e30b4: A9016FFC  stp      x28, x27, [sp, #0x10]
//   0x4e30b8: A90267FA  stp      x26, x25, [sp, #0x20]
//   0x4e30bc: A9035FF8  stp      x24, x23, [sp, #0x30]
//   0x4e30c0: A90457F6  stp      x22, x21, [sp, #0x40]
uint64_t fde_func_16205_0x4e30ac(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x004E30ACULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BA7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9016FFCULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90267FAULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9035FF8ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90457F6ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9054FF4ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #16215 | PC: 0x4e3a38..0x4e3a98 (96 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x4e3a38: D503233F  paciasp  
//   0x4e3a3c: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x4e3a40: F9000BF3  str      x19, [sp, #0x10]
//   0x4e3a44: 910003FD  mov      x29, sp
//   0x4e3a48: B9418808  ldr      w8, [x0, #0x188]
//   0x4e3a4c: 340000A8  cbz      w8, #0x4e3a60
uint64_t fde_func_16215_0x4e3a38(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x004E3A38ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF3ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB9418808ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x340000A8ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400BF3ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA8C27BFDULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #16224 | PC: 0x4e4008..0x4e40b8 (176 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x4e4008: D503233F  paciasp  
//   0x4e400c: D100C3FF  sub      sp, sp, #0x30
//   0x4e4010: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x4e4014: F90013F3  str      x19, [sp, #0x20]
//   0x4e4018: 910043FD  add      x29, sp, #0x10
//   0x4e401c: AA0103F3  mov      x19, x1
uint64_t fde_func_16224_0x4e4008(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x004E4008ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD100C3FFULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF90013F3ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0103F3ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x39410429ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003E8ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #16234 | PC: 0x4e4780..0x4e4818 (152 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x4e4780: D503233F  paciasp  
//   0x4e4784: A9BD7BFD  stp      x29, x30, [sp, #-0x30]!
//   0x4e4788: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x4e478c: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x4e4790: 910003FD  mov      x29, sp
//   0x4e4794: A9405416  ldp      x22, x21, [x0]
uint64_t fde_func_16234_0x4e4780(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x004E4780ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BD7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90157F6ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9024FF4ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9405416ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0103F3ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F4ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #16243 | PC: 0x4e4b70..0x4e4bdc (108 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x4e4b70: D503233F  paciasp  
//   0x4e4b74: D10143FF  sub      sp, sp, #0x50
//   0x4e4b78: A9037BFD  stp      x29, x30, [sp, #0x30]
//   0x4e4b7c: F90023F3  str      x19, [sp, #0x40]
//   0x4e4b80: 9100C3FD  add      x29, sp, #0x30
//   0x4e4b84: AA0003F3  mov      x19, x0
uint64_t fde_func_16243_0x4e4b70(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x004E4B70ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10143FFULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9037BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF90023F3ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9100C3FDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF0FFDD21ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91169C21ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #16253 | PC: 0x4e4f00..0x4e5000 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x4e4f00: D503245F  bti      c
//   0x4e4f04: 7100401F  cmp      w0, #0x10
//   0x4e4f08: 54000208  b.hi     #0x4e4f48
//   0x4e4f0c: 2A0003E8  mov      w8, w0
//   0x4e4f10: 90FFDCC9  adrp     x9, #0x7c000
//   0x4e4f14: 912F8D29  add      x9, x9, #0xbe3
uint64_t fde_func_16253_0x4e4f00(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x004E4F00ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x7100401FULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x54000208ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x2A0003E8ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x90FFDCC9ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x912F8D29ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x52800221ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB0FFDD60ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #16262 | PC: 0x4e57e8..0x4e57f8 (16 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x4e57e8: D503245F  bti      c
//   0x4e57ec: B900B001  str      w1, [x0, #0xb0]
//   0x4e57f0: F9005402  str      x2, [x0, #0xa8]
//   0x4e57f4: D65F03C0  ret      
uint64_t fde_func_16262_0x4e57e8(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x004E57E8ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB900B001ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9005402ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD65F03C0ULL ^ (3ULL << 32);
    return state ^ (state >> 29);
}

// FDE #16272 | PC: 0x4e5d78..0x4e5db8 (64 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x4e5d78: D503245F  bti      c
//   0x4e5d7c: F9400408  ldr      x8, [x0, #8]
//   0x4e5d80: F1001D1F  cmp      x8, #7
//   0x4e5d84: 54000128  b.hi     #0x4e5da8
//   0x4e5d88: B4000148  cbz      x8, #0x4e5db0
//   0x4e5d8c: 92800009  mov      x9, #-1
uint64_t fde_func_16272_0x4e5d78(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x004E5D78ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400408ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF1001D1FULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x54000128ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB4000148ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x92800009ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF940000AULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9AC82528ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #16281 | PC: 0x4e65b4..0x4e66b4 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x4e65b4: D503233F  paciasp  
//   0x4e65b8: D10283FF  sub      sp, sp, #0xa0
//   0x4e65bc: FD0013EA  str      d10, [sp, #0x20]
//   0x4e65c0: 6D0323E9  stp      d9, d8, [sp, #0x30]
//   0x4e65c4: A9047BFD  stp      x29, x30, [sp, #0x40]
//   0x4e65c8: A9056FFC  stp      x28, x27, [sp, #0x50]
uint64_t fde_func_16281_0x4e65b4(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x004E65B4ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10283FFULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xFD0013EAULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x6D0323E9ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9047BFDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9056FFCULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90667FAULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9075FF8ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #16291 | PC: 0x4e70cc..0x4e70f8 (44 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x4e70cc: D503233F  paciasp  
//   0x4e70d0: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x4e70d4: F9000BF3  str      x19, [sp, #0x10]
//   0x4e70d8: 910003FD  mov      x29, sp
//   0x4e70dc: AA0003F3  mov      x19, x0
//   0x4e70e0: 97FFFFE4  bl       #0x4e7070
uint64_t fde_func_16291_0x4e70cc(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x004E70CCULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF3ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x97FFFFE4ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA1303E0ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400BF3ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #16300 | PC: 0x4e8224..0x4e82c8 (164 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x4e8224: D503233F  paciasp  
//   0x4e8228: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x4e822c: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x4e8230: 910003FD  mov      x29, sp
//   0x4e8234: A9402009  ldp      x9, x8, [x0]
//   0x4e8238: AA0103F4  mov      x20, x1
uint64_t fde_func_16300_0x4e8224(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x004E8224ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9014FF4ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9402009ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0103F4ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400C0AULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #16310 | PC: 0x4e8778..0x4e87d0 (88 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x4e8778: D503233F  paciasp  
//   0x4e877c: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x4e8780: F9000BF3  str      x19, [sp, #0x10]
//   0x4e8784: 910003FD  mov      x29, sp
//   0x4e8788: A940A408  ldp      x8, x9, [x0, #8]
//   0x4e878c: AA0503F3  mov      x19, x5
uint64_t fde_func_16310_0x4e8778(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x004E8778ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF3ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA940A408ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0503F3ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xBD405900ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xBD025D20ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #16319 | PC: 0x4e8a80..0x4e8af8 (120 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x4e8a80: D503233F  paciasp  
//   0x4e8a84: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x4e8a88: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x4e8a8c: 910003FD  mov      x29, sp
//   0x4e8a90: 39408008  ldrb     w8, [x0, #0x20]
//   0x4e8a94: AA0003F3  mov      x19, x0
uint64_t fde_func_16319_0x4e8a80(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x004E8A80ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9014FF4ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x39408008ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0103F4ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x7100091FULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #16329 | PC: 0x4e948c..0x4e94ac (32 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x4e948c: D503245F  bti      c
//   0x4e9490: 52A7F008  mov      w8, #0x3f800000
//   0x4e9494: F9400809  ldr      x9, [x0, #0x10]
//   0x4e9498: B9025D28  str      w8, [x9, #0x25c]
//   0x4e949c: F9400809  ldr      x9, [x0, #0x10]
//   0x4e94a0: B9025928  str      w8, [x9, #0x258]
uint64_t fde_func_16329_0x4e948c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x004E948CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x52A7F008ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400809ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB9025D28ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400809ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB9025928ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000C1FULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD65F03C0ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #16338 | PC: 0x4e9b48..0x4e9b7c (52 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x4e9b48: D503245F  bti      c
//   0x4e9b4c: 39402008  ldrb     w8, [x0, #8]
//   0x4e9b50: 34000048  cbz      w8, #0x4e9b58
//   0x4e9b54: D65F03C0  ret      
//   0x4e9b58: 5280B688  mov      w8, #0x5b4
//   0x4e9b5c: A94D2809  ldp      x9, x10, [x0, #0xd0]
uint64_t fde_func_16338_0x4e9b48(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x004E9B48ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x39402008ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x34000048ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD65F03C0ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x5280B688ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA94D2809ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9B087C28ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xEB08013FULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #16348 | PC: 0x4ea788..0x4ea888 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x4ea788: D503245F  bti      c
//   0x4ea78c: F9400428  ldr      x8, [x1, #8]
//   0x4ea790: B40000E8  cbz      x8, #0x4ea7ac
//   0x4ea794: F9417809  ldr      x9, [x0, #0x2f0]
//   0x4ea798: EB08013F  cmp      x9, x8
//   0x4ea79c: 5400006C  b.gt     #0x4ea7a8
uint64_t fde_func_16348_0x4ea788(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x004EA788ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400428ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB40000E8ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9417809ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xEB08013FULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x5400006CULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9417C09ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB5000049ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #16358 | PC: 0x4eb29c..0x4eb2cc (48 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x4eb29c: D503245F  bti      c
//   0x4eb2a0: F9416808  ldr      x8, [x0, #0x2d0]
//   0x4eb2a4: B40000C8  cbz      x8, #0x4eb2bc
//   0x4eb2a8: B9407509  ldr      w9, [x8, #0x74]
//   0x4eb2ac: 11000529  add      w9, w9, #1
//   0x4eb2b0: B9007509  str      w9, [x8, #0x74]
uint64_t fde_func_16358_0x4eb29c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x004EB29CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9416808ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB40000C8ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB9407509ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x11000529ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB9007509ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9416808ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9005501ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #16367 | PC: 0x4ec408..0x4ec414 (12 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x4ec408: D503245F  bti      c
//   0x4ec40c: 910B8000  add      x0, x0, #0x2e0
//   0x4ec410: 17FFECF2  b        #0x4e77d8
uint64_t fde_func_16367_0x4ec408(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x004EC408ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910B8000ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x17FFECF2ULL ^ (2ULL << 32);
    return state ^ (state >> 29);
}

// FDE #16377 | PC: 0x4ec948..0x4ec998 (80 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x4ec948: D503233F  paciasp  
//   0x4ec94c: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x4ec950: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x4ec954: 910003FD  mov      x29, sp
//   0x4ec958: AA0103F4  mov      x20, x1
//   0x4ec95c: AA0003F3  mov      x19, x0
uint64_t fde_func_16377_0x4ec948(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x004EC948ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9014FF4ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0103F4ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x97FFFEE1ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xEB14001FULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #16386 | PC: 0x4ed05c..0x4ed120 (196 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x4ed05c: D503233F  paciasp  
//   0x4ed060: A9BC7BFD  stp      x29, x30, [sp, #-0x40]!
//   0x4ed064: A9015FF8  stp      x24, x23, [sp, #0x10]
//   0x4ed068: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x4ed06c: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x4ed070: 910003FD  mov      x29, sp
uint64_t fde_func_16386_0x4ed05c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x004ED05CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BC7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9015FF8ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90257F6ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9034FF4ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F7ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #16396 | PC: 0x4ed6d0..0x4ed734 (100 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x4ed6d0: D503245F  bti      c
//   0x4ed6d4: F9406C08  ldr      x8, [x0, #0xd8]
//   0x4ed6d8: F9407809  ldr      x9, [x0, #0xf0]
//   0x4ed6dc: EB09011F  cmp      x8, x9
//   0x4ed6e0: 540000A2  b.hs     #0x4ed6f4
//   0x4ed6e4: F9402C08  ldr      x8, [x0, #0x58]
uint64_t fde_func_16396_0x4ed6d0(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x004ED6D0ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9406C08ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9407809ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xEB09011FULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x540000A2ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9402C08ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9404109ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91000529ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #16405 | PC: 0x4ed9b8..0x4ed9c4 (12 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x4ed9b8: D503245F  bti      c
//   0x4ed9bc: 39418000  ldrb     w0, [x0, #0x60]
//   0x4ed9c0: D65F03C0  ret      
uint64_t fde_func_16405_0x4ed9b8(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x004ED9B8ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x39418000ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD65F03C0ULL ^ (2ULL << 32);
    return state ^ (state >> 29);
}

// FDE #16415 | PC: 0x4ee13c..0x4ee1bc (128 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x4ee13c: D503233F  paciasp  
//   0x4ee140: A9BC7BFD  stp      x29, x30, [sp, #-0x40]!
//   0x4ee144: A9015FF8  stp      x24, x23, [sp, #0x10]
//   0x4ee148: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x4ee14c: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x4ee150: 910003FD  mov      x29, sp
uint64_t fde_func_16415_0x4ee13c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x004EE13CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BC7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9015FF8ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90257F6ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9034FF4ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0103F7ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F8ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #16424 | PC: 0x4ee3a4..0x4ee418 (116 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x4ee3a4: D503233F  paciasp  
//   0x4ee3a8: A9BC7BFD  stp      x29, x30, [sp, #-0x40]!
//   0x4ee3ac: F9000BF7  str      x23, [sp, #0x10]
//   0x4ee3b0: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x4ee3b4: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x4ee3b8: 910003FD  mov      x29, sp
uint64_t fde_func_16424_0x4ee3a4(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x004EE3A4ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BC7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF7ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90257F6ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9034FF4ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF00005E8ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x912A4108ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #16434 | PC: 0x4eea38..0x4eea54 (28 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x4eea38: D503245F  bti      c
//   0x4eea3c: F9401008  ldr      x8, [x0, #0x20]
//   0x4eea40: F1002101  subs     x1, x8, #8
//   0x4eea44: 54000064  b.mi     #0x4eea50
//   0x4eea48: 91012800  add      x0, x0, #0x4a
//   0x4eea4c: D65F03C0  ret      
uint64_t fde_func_16434_0x4eea38(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x004EEA38ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9401008ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF1002101ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x54000064ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91012800ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD65F03C0ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD4200020ULL ^ (6ULL << 32);
    return state ^ (state >> 29);
}

// FDE #16443 | PC: 0x4eee34..0x4eee44 (16 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x4eee34: D503245F  bti      c
//   0x4eee38: F9400C08  ldr      x8, [x0, #0x18]
//   0x4eee3c: 8B010100  add      x0, x8, x1
//   0x4eee40: D65F03C0  ret      
uint64_t fde_func_16443_0x4eee34(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x004EEE34ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400C08ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x8B010100ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD65F03C0ULL ^ (3ULL << 32);
    return state ^ (state >> 29);
}

// FDE #16453 | PC: 0x4eefa0..0x4eefcc (44 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x4eefa0: D503233F  paciasp  
//   0x4eefa4: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x4eefa8: F9000BF3  str      x19, [sp, #0x10]
//   0x4eefac: 910003FD  mov      x29, sp
//   0x4eefb0: AA0003F3  mov      x19, x0
//   0x4eefb4: 97FFFECC  bl       #0x4eeae4
uint64_t fde_func_16453_0x4eefa0(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x004EEFA0ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF3ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x97FFFECCULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA1303E0ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400BF3ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #16462 | PC: 0x4ef2cc..0x4ef3cc (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x4ef2cc: D503233F  paciasp  
//   0x4ef2d0: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x4ef2d4: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x4ef2d8: 910003FD  mov      x29, sp
//   0x4ef2dc: F9400014  ldr      x20, [x0]
//   0x4ef2e0: B4000674  cbz      x20, #0x4ef3ac
uint64_t fde_func_16462_0x4ef2cc(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x004EF2CCULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9014FF4ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400014ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB4000674ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB9400808ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #16472 | PC: 0x4ef944..0x4efa04 (192 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x4ef944: D503233F  paciasp  
//   0x4ef948: D10603FF  sub      sp, sp, #0x180
//   0x4ef94c: A9147BFD  stp      x29, x30, [sp, #0x140]
//   0x4ef950: F900ABFC  str      x28, [sp, #0x150]
//   0x4ef954: A91657F6  stp      x22, x21, [sp, #0x160]
//   0x4ef958: A9174FF4  stp      x20, x19, [sp, #0x170]
uint64_t fde_func_16472_0x4ef944(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x004EF944ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10603FFULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9147BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF900ABFCULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA91657F6ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9174FF4ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910503FDULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD53BD054ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #16481 | PC: 0x4efddc..0x4efdf8 (28 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x4efddc: D503245F  bti      c
//   0x4efde0: 39406008  ldrb     w8, [x0, #0x18]
//   0x4efde4: 37000068  tbnz     w8, #0, #0x4efdf0
//   0x4efde8: D341FD00  lsr      x0, x8, #1
//   0x4efdec: D65F03C0  ret      
//   0x4efdf0: F9401000  ldr      x0, [x0, #0x20]
uint64_t fde_func_16481_0x4efddc(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x004EFDDCULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x39406008ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x37000068ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD341FD00ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD65F03C0ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9401000ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD65F03C0ULL ^ (6ULL << 32);
    return state ^ (state >> 29);
}

// FDE #16491 | PC: 0x4f06a8..0x4f0758 (176 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x4f06a8: D503233F  paciasp  
//   0x4f06ac: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x4f06b0: F9000BF3  str      x19, [sp, #0x10]
//   0x4f06b4: 910003FD  mov      x29, sp
//   0x4f06b8: AA0003F3  mov      x19, x0
//   0x4f06bc: D00005E8  adrp     x8, #0x5ae000
uint64_t fde_func_16491_0x4f06a8(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x004F06A8ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF3ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD00005E8ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91158108ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF900067FULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #16500 | PC: 0x4f0d9c..0x4f0df8 (92 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x4f0d9c: D503233F  paciasp  
//   0x4f0da0: D10143FF  sub      sp, sp, #0x50
//   0x4f0da4: A9037BFD  stp      x29, x30, [sp, #0x30]
//   0x4f0da8: F90023F3  str      x19, [sp, #0x40]
//   0x4f0dac: 9100C3FD  add      x29, sp, #0x30
//   0x4f0db0: AA0003F3  mov      x19, x0
uint64_t fde_func_16500_0x4f0d9c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x004F0D9CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10143FFULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9037BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF90023F3ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9100C3FDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB9001FA1ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910023E0ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #16510 | PC: 0x4f18c0..0x4f19c0 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x4f18c0: D503233F  paciasp  
//   0x4f18c4: D10243FF  sub      sp, sp, #0x90
//   0x4f18c8: A9057BFD  stp      x29, x30, [sp, #0x50]
//   0x4f18cc: F90033F7  str      x23, [sp, #0x60]
//   0x4f18d0: A90757F6  stp      x22, x21, [sp, #0x70]
//   0x4f18d4: A9084FF4  stp      x20, x19, [sp, #0x80]
uint64_t fde_func_16510_0x4f18c0(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x004F18C0ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10243FFULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9057BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF90033F7ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90757F6ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9084FF4ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910143FDULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD0000508ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #16519 | PC: 0x4f2a78..0x4f2afc (132 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x4f2a78: D503233F  paciasp  
//   0x4f2a7c: D10183FF  sub      sp, sp, #0x60
//   0x4f2a80: A9037BFD  stp      x29, x30, [sp, #0x30]
//   0x4f2a84: F90023F5  str      x21, [sp, #0x40]
//   0x4f2a88: A9054FF4  stp      x20, x19, [sp, #0x50]
//   0x4f2a8c: 9100C3FD  add      x29, sp, #0x30
uint64_t fde_func_16519_0x4f2a78(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x004F2A78ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10183FFULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9037BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF90023F5ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9054FF4ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9100C3FDULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD53BD055ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0103F3ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #16529 | PC: 0x4f2ed0..0x4f2f88 (184 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x4f2ed0: D503233F  paciasp  
//   0x4f2ed4: A9BB7BFD  stp      x29, x30, [sp, #-0x50]!
//   0x4f2ed8: A90167FA  stp      x26, x25, [sp, #0x10]
//   0x4f2edc: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x4f2ee0: A90357F6  stp      x22, x21, [sp, #0x30]
//   0x4f2ee4: A9044FF4  stp      x20, x19, [sp, #0x40]
uint64_t fde_func_16529_0x4f2ed0(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x004F2ED0ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BB7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90167FAULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9025FF8ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90357F6ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9044FF4ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9402BB9ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #16538 | PC: 0x4f313c..0x4f3168 (44 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x4f313c: D503233F  paciasp  
//   0x4f3140: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x4f3144: F9000BF3  str      x19, [sp, #0x10]
//   0x4f3148: 910003FD  mov      x29, sp
//   0x4f314c: AA0003F3  mov      x19, x0
//   0x4f3150: 97FFFFE9  bl       #0x4f30f4
uint64_t fde_func_16538_0x4f313c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x004F313CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF3ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x97FFFFE9ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA1303E0ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400BF3ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #16548 | PC: 0x4f3fec..0x4f4098 (172 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x4f3fec: D503233F  paciasp  
//   0x4f3ff0: A9BD7BFD  stp      x29, x30, [sp, #-0x30]!
//   0x4f3ff4: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x4f3ff8: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x4f3ffc: 910003FD  mov      x29, sp
//   0x4f4000: F9400C15  ldr      x21, [x0, #0x18]
uint64_t fde_func_16548_0x4f3fec(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x004F3FECULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BD7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90157F6ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9024FF4ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400C15ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF10202BFULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #16557 | PC: 0x4f4534..0x4f4548 (20 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x4f4534: D503245F  bti      c
//   0x4f4538: AA0003E8  mov      x8, x0
//   0x4f453c: AA0103E0  mov      x0, x1
//   0x4f4540: AA0803E1  mov      x1, x8
//   0x4f4544: 14016298  b        #0x54cfa4
uint64_t fde_func_16557_0x4f4534(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x004F4534ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003E8ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0103E0ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0803E1ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x14016298ULL ^ (4ULL << 32);
    return state ^ (state >> 29);
}

// FDE #16567 | PC: 0x4f4d20..0x4f4dac (140 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x4f4d20: D503233F  paciasp  
//   0x4f4d24: A9BD7BFD  stp      x29, x30, [sp, #-0x30]!
//   0x4f4d28: F9000BF5  str      x21, [sp, #0x10]
//   0x4f4d2c: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x4f4d30: 910003FD  mov      x29, sp
//   0x4f4d34: AA0203F4  mov      x20, x2
uint64_t fde_func_16567_0x4f4d20(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x004F4D20ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BD7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF5ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9024FF4ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0203F4ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0103F5ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #16576 | PC: 0x4f52e8..0x4f5304 (28 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x4f52e8: D503245F  bti      c
//   0x4f52ec: AA0003E8  mov      x8, x0
//   0x4f52f0: F9400000  ldr      x0, [x0]
//   0x4f52f4: F900011F  str      xzr, [x8]
//   0x4f52f8: B4000040  cbz      x0, #0x4f5300
//   0x4f52fc: 17FA3985  b        #0x383910
uint64_t fde_func_16576_0x4f52e8(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x004F52E8ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003E8ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400000ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF900011FULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB4000040ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x17FA3985ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD65F03C0ULL ^ (6ULL << 32);
    return state ^ (state >> 29);
}

// FDE #16586 | PC: 0x4f5d88..0x4f5e88 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x4f5d88: D503233F  paciasp  
//   0x4f5d8c: D10343FF  sub      sp, sp, #0xd0
//   0x4f5d90: A9087BFD  stp      x29, x30, [sp, #0x80]
//   0x4f5d94: F9004BF9  str      x25, [sp, #0x90]
//   0x4f5d98: A90A5FF8  stp      x24, x23, [sp, #0xa0]
//   0x4f5d9c: A90B57F6  stp      x22, x21, [sp, #0xb0]
uint64_t fde_func_16586_0x4f5d88(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x004F5D88ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10343FFULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9087BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9004BF9ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90A5FF8ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90B57F6ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90C4FF4ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910203FDULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #16595 | PC: 0x4f7170..0x4f7180 (16 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x4f7170: D503245F  bti      c
//   0x4f7174: AA0103E0  mov      x0, x1
//   0x4f7178: AA0203E1  mov      x1, x2
//   0x4f717c: 14024C6B  b        #0x58a328
uint64_t fde_func_16595_0x4f7170(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x004F7170ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0103E0ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0203E1ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x14024C6BULL ^ (3ULL << 32);
    return state ^ (state >> 29);
}

// FDE #16605 | PC: 0x4f7580..0x4f75ec (108 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x4f7580: D503233F  paciasp  
//   0x4f7584: A9BC7BFD  stp      x29, x30, [sp, #-0x40]!
//   0x4f7588: F9000BF7  str      x23, [sp, #0x10]
//   0x4f758c: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x4f7590: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x4f7594: 910003FD  mov      x29, sp
uint64_t fde_func_16605_0x4f7580(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x004F7580ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BC7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF7ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90257F6ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9034FF4ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0403F3ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0303F4ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #16614 | PC: 0x4f7964..0x4f7a64 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x4f7964: D503233F  paciasp  
//   0x4f7968: D10383FF  sub      sp, sp, #0xe0
//   0x4f796c: A90B7BFD  stp      x29, x30, [sp, #0xb0]
//   0x4f7970: A90C57F6  stp      x22, x21, [sp, #0xc0]
//   0x4f7974: A90D4FF4  stp      x20, x19, [sp, #0xd0]
//   0x4f7978: 9102C3FD  add      x29, sp, #0xb0
uint64_t fde_func_16614_0x4f7964(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x004F7964ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10383FFULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90B7BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90C57F6ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90D4FF4ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9102C3FDULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD53BD055ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0103F4ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #16624 | PC: 0x4f83fc..0x4f84fc (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x4f83fc: D503233F  paciasp  
//   0x4f8400: D10383FF  sub      sp, sp, #0xe0
//   0x4f8404: A90B7BFD  stp      x29, x30, [sp, #0xb0]
//   0x4f8408: A90C57F6  stp      x22, x21, [sp, #0xc0]
//   0x4f840c: A90D4FF4  stp      x20, x19, [sp, #0xd0]
//   0x4f8410: 9102C3FD  add      x29, sp, #0xb0
uint64_t fde_func_16624_0x4f83fc(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x004F83FCULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10383FFULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90B7BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90C57F6ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90D4FF4ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9102C3FDULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD53BD055ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0103F4ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #16633 | PC: 0x4f9ca4..0x4f9cc4 (32 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x4f9ca4: D503245F  bti      c
//   0x4f9ca8: A900FC1F  stp      xzr, xzr, [x0, #8]
//   0x4f9cac: F900001F  str      xzr, [x0]
//   0x4f9cb0: 39400028  ldrb     w8, [x1]
//   0x4f9cb4: 34000068  cbz      w8, #0x4f9cc0
//   0x4f9cb8: 91002021  add      x1, x1, #8
uint64_t fde_func_16633_0x4f9ca4(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x004F9CA4ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA900FC1FULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF900001FULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x39400028ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x34000068ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91002021ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x140000F9ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD65F03C0ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #16643 | PC: 0x4fa0a0..0x4fa0d4 (52 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x4fa0a0: D503233F  paciasp  
//   0x4fa0a4: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x4fa0a8: F9000BF3  str      x19, [sp, #0x10]
//   0x4fa0ac: 910003FD  mov      x29, sp
//   0x4fa0b0: AA0003F3  mov      x19, x0
//   0x4fa0b4: 91002000  add      x0, x0, #8
uint64_t fde_func_16643_0x4fa0a0(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x004FA0A0ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF3ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91002000ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9400E1C8ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x52800028ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #16653 | PC: 0x4fca28..0x4fcaf0 (200 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x4fca28: D503233F  paciasp  
//   0x4fca2c: A9BD7BFD  stp      x29, x30, [sp, #-0x30]!
//   0x4fca30: F9000BF5  str      x21, [sp, #0x10]
//   0x4fca34: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x4fca38: 910003FD  mov      x29, sp
//   0x4fca3c: AA0003F3  mov      x19, x0
uint64_t fde_func_16653_0x4fca28(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x004FCA28ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BD7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF5ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9024FF4ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400015ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0103E0ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #16662 | PC: 0x4fdf7c..0x4fdfec (112 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x4fdf7c: D503245F  bti      c
//   0x4fdf80: B100043F  cmn      x1, #1
//   0x4fdf84: 540002A0  b.eq     #0x4fdfd8
//   0x4fdf88: D503233F  paciasp  
//   0x4fdf8c: D10083FF  sub      sp, sp, #0x20
//   0x4fdf90: A9017BFD  stp      x29, x30, [sp, #0x10]
uint64_t fde_func_16662_0x4fdf7c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x004FDF7CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB100043FULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x540002A0ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10083FFULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA940200AULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #16672 | PC: 0x4fe71c..0x4fe81c (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x4fe71c: D503233F  paciasp  
//   0x4fe720: D10603FF  sub      sp, sp, #0x180
//   0x4fe724: A9147BFD  stp      x29, x30, [sp, #0x140]
//   0x4fe728: F900ABFC  str      x28, [sp, #0x150]
//   0x4fe72c: A91657F6  stp      x22, x21, [sp, #0x160]
//   0x4fe730: A9174FF4  stp      x20, x19, [sp, #0x170]
uint64_t fde_func_16672_0x4fe71c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x004FE71CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10603FFULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9147BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF900ABFCULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA91657F6ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9174FF4ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910503FDULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD53BD056ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #16681 | PC: 0x4ff9bc..0x4ffa04 (72 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x4ff9bc: D503233F  paciasp  
//   0x4ff9c0: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x4ff9c4: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x4ff9c8: 910003FD  mov      x29, sp
//   0x4ff9cc: 52800308  mov      w8, #0x18
//   0x4ff9d0: AA0103F3  mov      x19, x1
uint64_t fde_func_16681_0x4ff9bc(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x004FF9BCULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9014FF4ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x52800308ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0103F3ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9B080028ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD1006114ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #16691 | PC: 0x4ffd74..0x4ffdb0 (60 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x4ffd74: D503233F  paciasp  
//   0x4ffd78: A9BD7BFD  stp      x29, x30, [sp, #-0x30]!
//   0x4ffd7c: F9000BF5  str      x21, [sp, #0x10]
//   0x4ffd80: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x4ffd84: 910003FD  mov      x29, sp
//   0x4ffd88: AA0303F3  mov      x19, x3
uint64_t fde_func_16691_0x4ffd74(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x004FFD74ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BD7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF5ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9024FF4ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0303F3ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0203F4ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F5ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #16700 | PC: 0x5002d0..0x5003d0 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x5002d0: D503233F  paciasp  
//   0x5002d4: A9BA7BFD  stp      x29, x30, [sp, #-0x60]!
//   0x5002d8: A9016FFC  stp      x28, x27, [sp, #0x10]
//   0x5002dc: A90267FA  stp      x26, x25, [sp, #0x20]
//   0x5002e0: A9035FF8  stp      x24, x23, [sp, #0x30]
//   0x5002e4: A90457F6  stp      x22, x21, [sp, #0x40]
uint64_t fde_func_16700_0x5002d0(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x005002D0ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BA7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9016FFCULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90267FAULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9035FF8ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90457F6ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9054FF4ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #16710 | PC: 0x50148c..0x50158c (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x50148c: D503233F  paciasp  
//   0x501490: D10283FF  sub      sp, sp, #0xa0
//   0x501494: A9067BFD  stp      x29, x30, [sp, #0x60]
//   0x501498: F9003BF7  str      x23, [sp, #0x70]
//   0x50149c: A90857F6  stp      x22, x21, [sp, #0x80]
//   0x5014a0: A9094FF4  stp      x20, x19, [sp, #0x90]
uint64_t fde_func_16710_0x50148c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0050148CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10283FFULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9067BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9003BF7ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90857F6ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9094FF4ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910183FDULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD53BD057ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #16719 | PC: 0x502010..0x502078 (104 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x502010: D503233F  paciasp  
//   0x502014: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x502018: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x50201c: 910003FD  mov      x29, sp
//   0x502020: AA0003F3  mov      x19, x0
//   0x502024: 2A0103E2  mov      w2, w1
uint64_t fde_func_16719_0x502010(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00502010ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9014FF4ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x2A0103E2ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9409C14ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400400ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #16729 | PC: 0x5023d4..0x502400 (44 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x5023d4: D503233F  paciasp  
//   0x5023d8: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x5023dc: F9000BF3  str      x19, [sp, #0x10]
//   0x5023e0: 910003FD  mov      x29, sp
//   0x5023e4: AA0003F3  mov      x19, x0
//   0x5023e8: 97FFFFE5  bl       #0x50237c
uint64_t fde_func_16729_0x5023d4(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x005023D4ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF3ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x97FFFFE5ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA1303E0ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400BF3ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #16738 | PC: 0x5026c4..0x50277c (184 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x5026c4: D503233F  paciasp  
//   0x5026c8: A9BC7BFD  stp      x29, x30, [sp, #-0x40]!
//   0x5026cc: A9015FF8  stp      x24, x23, [sp, #0x10]
//   0x5026d0: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x5026d4: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x5026d8: 910003FD  mov      x29, sp
uint64_t fde_func_16738_0x5026c4(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x005026C4ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BC7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9015FF8ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90257F6ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9034FF4ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9405C16ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #16748 | PC: 0x5030a8..0x503128 (128 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x5030a8: D503233F  paciasp  
//   0x5030ac: A9BD7BFD  stp      x29, x30, [sp, #-0x30]!
//   0x5030b0: F9000BF5  str      x21, [sp, #0x10]
//   0x5030b4: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x5030b8: 910003FD  mov      x29, sp
//   0x5030bc: AA0303F3  mov      x19, x3
uint64_t fde_func_16748_0x5030a8(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x005030A8ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BD7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF5ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9024FF4ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0303F3ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x8B021414ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x8B011415ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #16757 | PC: 0x503630..0x503730 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x503630: D503233F  paciasp  
//   0x503634: D101C3FF  sub      sp, sp, #0x70
//   0x503638: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x50363c: F90013FB  str      x27, [sp, #0x20]
//   0x503640: A90367FA  stp      x26, x25, [sp, #0x30]
//   0x503644: A9045FF8  stp      x24, x23, [sp, #0x40]
uint64_t fde_func_16757_0x503630(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00503630ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD101C3FFULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF90013FBULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90367FAULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9045FF8ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90557F6ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9064FF4ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #16767 | PC: 0x503a40..0x503a4c (12 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x503a40: D503245F  bti      c
//   0x503a44: 528001A1  mov      w1, #0xd
//   0x503a48: 140001D7  b        #0x5041a4
uint64_t fde_func_16767_0x503a40(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00503A40ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x528001A1ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x140001D7ULL ^ (2ULL << 32);
    return state ^ (state >> 29);
}

// FDE #16776 | PC: 0x503fd8..0x503fec (20 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x503fd8: D503245F  bti      c
//   0x503fdc: F9418008  ldr      x8, [x0, #0x300]
//   0x503fe0: 52800020  mov      w0, #1
//   0x503fe4: F9476508  ldr      x8, [x8, #0xec8]
//   0x503fe8: D65F03C0  ret      
uint64_t fde_func_16776_0x503fd8(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00503FD8ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9418008ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x52800020ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9476508ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD65F03C0ULL ^ (4ULL << 32);
    return state ^ (state >> 29);
}

// FDE #16786 | PC: 0x50412c..0x50413c (16 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x50412c: D503245F  bti      c
//   0x504130: D1098000  sub      x0, x0, #0x260
//   0x504134: 2A1F03E1  mov      w1, wzr
//   0x504138: 1400001B  b        #0x5041a4
uint64_t fde_func_16786_0x50412c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0050412CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD1098000ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x2A1F03E1ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x1400001BULL ^ (3ULL << 32);
    return state ^ (state >> 29);
}

// FDE #16795 | PC: 0x504338..0x504438 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x504338: D503233F  paciasp  
//   0x50433c: D100C3FF  sub      sp, sp, #0x30
//   0x504340: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x504344: F90013F3  str      x19, [sp, #0x20]
//   0x504348: 910043FD  add      x29, sp, #0x10
//   0x50434c: AA0203F3  mov      x19, x2
uint64_t fde_func_16795_0x504338(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00504338ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD100C3FFULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF90013F3ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0203F3ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x52800148ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90007E0ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #16805 | PC: 0x504e54..0x504e9c (72 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x504e54: D503233F  paciasp  
//   0x504e58: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x504e5c: F9000BF3  str      x19, [sp, #0x10]
//   0x504e60: 910003FD  mov      x29, sp
//   0x504e64: AA0003F3  mov      x19, x0
//   0x504e68: 94000AA3  bl       #0x5078f4
uint64_t fde_func_16805_0x504e54(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00504E54ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF3ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x94000AA3ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x37000060ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x397DE268ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #16814 | PC: 0x5059a8..0x5059b4 (12 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x5059a8: D503245F  bti      c
//   0x5059ac: D1002000  sub      x0, x0, #8
//   0x5059b0: 17FFFCBE  b        #0x504ca8
uint64_t fde_func_16814_0x5059a8(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x005059A8ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD1002000ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x17FFFCBEULL ^ (2ULL << 32);
    return state ^ (state >> 29);
}

// FDE #16824 | PC: 0x505b04..0x505bc8 (196 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x505b04: D503245F  bti      c
//   0x505b08: D285AD28  mov      x8, #0x2d69
//   0x505b0c: D503201F  nop      
//   0x505b10: 1047A78A  adr      x10, #0x595000
//   0x505b14: F2BD6708  movk     x8, #0xeb38, lsl #16
//   0x505b18: F2DD4108  movk     x8, #0xea08, lsl #32
uint64_t fde_func_16824_0x505b04(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00505B04ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD285AD28ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503201FULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x1047A78AULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF2BD6708ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF2DD4108ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x8B21414AULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF2F3BBE8ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #16833 | PC: 0x506128..0x506228 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x506128: D503233F  paciasp  
//   0x50612c: A9BD7BFD  stp      x29, x30, [sp, #-0x30]!
//   0x506130: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x506134: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x506138: 910003FD  mov      x29, sp
//   0x50613c: F9400016  ldr      x22, [x0]
uint64_t fde_func_16833_0x506128(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00506128ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BD7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90157F6ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9024FF4ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400016ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400C15ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #16843 | PC: 0x5067cc..0x506814 (72 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x5067cc: D503233F  paciasp  
//   0x5067d0: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x5067d4: F9000BF3  str      x19, [sp, #0x10]
//   0x5067d8: 910003FD  mov      x29, sp
//   0x5067dc: AA0003E8  mov      x8, x0
//   0x5067e0: F9400800  ldr      x0, [x0, #0x10]
uint64_t fde_func_16843_0x5067cc(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x005067CCULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF3ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003E8ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400800ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x5283D649ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91006113ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #16852 | PC: 0x506c94..0x506cf0 (92 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x506c94: D503233F  paciasp  
//   0x506c98: D10103FF  sub      sp, sp, #0x40
//   0x506c9c: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x506ca0: F9001BF3  str      x19, [sp, #0x30]
//   0x506ca4: 910083FD  add      x29, sp, #0x20
//   0x506ca8: AA0003F3  mov      x19, x0
uint64_t fde_func_16852_0x506c94(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00506C94ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10103FFULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9027BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9001BF3ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910083FDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB0FFDD21ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91255021ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #16862 | PC: 0x507354..0x507454 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x507354: D503233F  paciasp  
//   0x507358: D10503FF  sub      sp, sp, #0x140
//   0x50735c: A9107BFD  stp      x29, x30, [sp, #0x100]
//   0x507360: F9008BFC  str      x28, [sp, #0x110]
//   0x507364: A91257F6  stp      x22, x21, [sp, #0x120]
//   0x507368: A9134FF4  stp      x20, x19, [sp, #0x130]
uint64_t fde_func_16862_0x507354(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00507354ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10503FFULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9107BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9008BFCULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA91257F6ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9134FF4ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910403FDULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD53BD056ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #16871 | PC: 0x507eec..0x507fec (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x507eec: D503233F  paciasp  
//   0x507ef0: D10443FF  sub      sp, sp, #0x110
//   0x507ef4: A90D7BFD  stp      x29, x30, [sp, #0xd0]
//   0x507ef8: A90E5FFC  stp      x28, x23, [sp, #0xe0]
//   0x507efc: A90F57F6  stp      x22, x21, [sp, #0xf0]
//   0x507f00: A9104FF4  stp      x20, x19, [sp, #0x100]
uint64_t fde_func_16871_0x507eec(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00507EECULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10443FFULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90D7BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90E5FFCULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90F57F6ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9104FF4ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910343FDULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD53BD056ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #16881 | PC: 0x508948..0x5089f4 (172 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x508948: D503233F  paciasp  
//   0x50894c: D10303FF  sub      sp, sp, #0xc0
//   0x508950: A9087BFD  stp      x29, x30, [sp, #0x80]
//   0x508954: F9004BF7  str      x23, [sp, #0x90]
//   0x508958: A90A57F6  stp      x22, x21, [sp, #0xa0]
//   0x50895c: A90B4FF4  stp      x20, x19, [sp, #0xb0]
uint64_t fde_func_16881_0x508948(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00508948ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10303FFULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9087BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9004BF7ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90A57F6ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90B4FF4ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910203FDULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x2A0103F6ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #16890 | PC: 0x50907c..0x509088 (12 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x50907c: D503245F  bti      c
//   0x509080: D1008000  sub      x0, x0, #0x20
//   0x509084: 17FFF91E  b        #0x5074fc
uint64_t fde_func_16890_0x50907c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0050907CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD1008000ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x17FFF91EULL ^ (2ULL << 32);
    return state ^ (state >> 29);
}

// FDE #16900 | PC: 0x509190..0x50921c (140 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x509190: D503233F  paciasp  
//   0x509194: A9BD7BFD  stp      x29, x30, [sp, #-0x30]!
//   0x509198: F9000BF5  str      x21, [sp, #0x10]
//   0x50919c: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x5091a0: 910003FD  mov      x29, sp
//   0x5091a4: F9400C15  ldr      x21, [x0, #0x18]
uint64_t fde_func_16900_0x509190(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00509190ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BD7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF5ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9024FF4ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400C15ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF10202BFULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #16909 | PC: 0x509684..0x5096d4 (80 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x509684: D503233F  paciasp  
//   0x509688: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x50968c: F9000BF3  str      x19, [sp, #0x10]
//   0x509690: 910003FD  mov      x29, sp
//   0x509694: AA0003F3  mov      x19, x0
//   0x509698: 39404008  ldrb     w8, [x0, #0x10]
uint64_t fde_func_16909_0x509684(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00509684ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF3ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x39404008ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91006000ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF0FFDBE1ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #16919 | PC: 0x509bb0..0x509cb0 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x509bb0: D503233F  paciasp  
//   0x509bb4: A9BB7BFD  stp      x29, x30, [sp, #-0x50]!
//   0x509bb8: F9000BF9  str      x25, [sp, #0x10]
//   0x509bbc: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x509bc0: A90357F6  stp      x22, x21, [sp, #0x30]
//   0x509bc4: A9044FF4  stp      x20, x19, [sp, #0x40]
uint64_t fde_func_16919_0x509bb0(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00509BB0ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BB7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF9ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9025FF8ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90357F6ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9044FF4ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #16928 | PC: 0x50a394..0x50a494 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x50a394: D503233F  paciasp  
//   0x50a398: A9BB7BFD  stp      x29, x30, [sp, #-0x50]!
//   0x50a39c: F9000BF9  str      x25, [sp, #0x10]
//   0x50a3a0: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x50a3a4: A90357F6  stp      x22, x21, [sp, #0x30]
//   0x50a3a8: A9044FF4  stp      x20, x19, [sp, #0x40]
uint64_t fde_func_16928_0x50a394(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0050A394ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BB7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF9ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9025FF8ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90357F6ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9044FF4ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #16938 | PC: 0x50aa20..0x50ab20 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x50aa20: D503233F  paciasp  
//   0x50aa24: D10283FF  sub      sp, sp, #0xa0
//   0x50aa28: A9047BFD  stp      x29, x30, [sp, #0x40]
//   0x50aa2c: A9056FFC  stp      x28, x27, [sp, #0x50]
//   0x50aa30: A90667FA  stp      x26, x25, [sp, #0x60]
//   0x50aa34: A9075FF8  stp      x24, x23, [sp, #0x70]
uint64_t fde_func_16938_0x50aa20(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0050AA20ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10283FFULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9047BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9056FFCULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90667FAULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9075FF8ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90857F6ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9094FF4ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #16947 | PC: 0x50b298..0x50b2a4 (12 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x50b298: D503245F  bti      c
//   0x50b29c: AA1F03E1  mov      x1, xzr
//   0x50b2a0: 17FFFFEC  b        #0x50b250
uint64_t fde_func_16947_0x50b298(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0050B298ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA1F03E1ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x17FFFFECULL ^ (2ULL << 32);
    return state ^ (state >> 29);
}

// FDE #16957 | PC: 0x50bba4..0x50bc18 (116 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x50bba4: D503233F  paciasp  
//   0x50bba8: A9BD7BFD  stp      x29, x30, [sp, #-0x30]!
//   0x50bbac: F9000BF5  str      x21, [sp, #0x10]
//   0x50bbb0: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x50bbb4: 910003FD  mov      x29, sp
//   0x50bbb8: AA0203F3  mov      x19, x2
uint64_t fde_func_16957_0x50bba4(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0050BBA4ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BD7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF5ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9024FF4ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0203F3ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0103F4ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F5ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #16967 | PC: 0x50c7dc..0x50c8dc (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x50c7dc: D503233F  paciasp  
//   0x50c7e0: A9BA7BFD  stp      x29, x30, [sp, #-0x60]!
//   0x50c7e4: F9000BFC  str      x28, [sp, #0x10]
//   0x50c7e8: A90267FA  stp      x26, x25, [sp, #0x20]
//   0x50c7ec: A9035FF8  stp      x24, x23, [sp, #0x30]
//   0x50c7f0: A90457F6  stp      x22, x21, [sp, #0x40]
uint64_t fde_func_16967_0x50c7dc(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0050C7DCULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BA7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BFCULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90267FAULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9035FF8ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90457F6ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9054FF4ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #16976 | PC: 0x50d028..0x50d128 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x50d028: D503233F  paciasp  
//   0x50d02c: D10283FF  sub      sp, sp, #0xa0
//   0x50d030: A9047BFD  stp      x29, x30, [sp, #0x40]
//   0x50d034: A9056FFC  stp      x28, x27, [sp, #0x50]
//   0x50d038: A90667FA  stp      x26, x25, [sp, #0x60]
//   0x50d03c: A9075FF8  stp      x24, x23, [sp, #0x70]
uint64_t fde_func_16976_0x50d028(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0050D028ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10283FFULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9047BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9056FFCULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90667FAULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9075FF8ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90857F6ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9094FF4ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #16986 | PC: 0x50e968..0x50e974 (12 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x50e968: D503245F  bti      c
//   0x50e96c: D109A000  sub      x0, x0, #0x268
//   0x50e970: 17FFF8F6  b        #0x50cd48
uint64_t fde_func_16986_0x50e968(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0050E968ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD109A000ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x17FFF8F6ULL ^ (2ULL << 32);
    return state ^ (state >> 29);
}

// FDE #16995 | PC: 0x50f1a0..0x50f2a0 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x50f1a0: D503233F  paciasp  
//   0x50f1a4: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x50f1a8: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x50f1ac: 910003FD  mov      x29, sp
//   0x50f1b0: D285AD29  mov      x9, #0x2d69
//   0x50f1b4: D503201F  nop      
uint64_t fde_func_16995_0x50f1a0(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0050F1A0ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9014FF4ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD285AD29ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503201FULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x1042F248ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF2BD6709ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #17005 | PC: 0x50fb88..0x50fb94 (12 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x50fb88: D503245F  bti      c
//   0x50fb8c: AA1F03E1  mov      x1, xzr
//   0x50fb90: 14000001  b        #0x50fb94
uint64_t fde_func_17005_0x50fb88(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0050FB88ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA1F03E1ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x14000001ULL ^ (2ULL << 32);
    return state ^ (state >> 29);
}

// FDE #17014 | PC: 0x510408..0x51047c (116 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x510408: D503233F  paciasp  
//   0x51040c: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x510410: F9000BF3  str      x19, [sp, #0x10]
//   0x510414: 910003FD  mov      x29, sp
//   0x510418: AA0003F3  mov      x19, x0
//   0x51041c: 90000508  adrp     x8, #0x5b0000
uint64_t fde_func_17014_0x510408(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00510408ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF3ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x90000508ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91034108ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x90000509ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #17024 | PC: 0x510f94..0x510fa8 (20 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x510f94: D503245F  bti      c
//   0x510f98: F9400C08  ldr      x8, [x0, #0x18]
//   0x510f9c: F9414108  ldr      x8, [x8, #0x280]
//   0x510fa0: F905E101  str      x1, [x8, #0xbc0]
//   0x510fa4: D65F03C0  ret      
uint64_t fde_func_17024_0x510f94(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00510F94ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400C08ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9414108ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF905E101ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD65F03C0ULL ^ (4ULL << 32);
    return state ^ (state >> 29);
}

// FDE #17033 | PC: 0x511338..0x511394 (92 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x511338: D503233F  paciasp  
//   0x51133c: A9BD7BFD  stp      x29, x30, [sp, #-0x30]!
//   0x511340: F9000BF5  str      x21, [sp, #0x10]
//   0x511344: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x511348: 910003FD  mov      x29, sp
//   0x51134c: AA0003F3  mov      x19, x0
uint64_t fde_func_17033_0x511338(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00511338ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BD7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF5ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9024FF4ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9414415ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0103F4ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #17043 | PC: 0x51178c..0x5117f4 (104 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x51178c: D503233F  paciasp  
//   0x511790: D10103FF  sub      sp, sp, #0x40
//   0x511794: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x511798: F9001BF3  str      x19, [sp, #0x30]
//   0x51179c: 910083FD  add      x29, sp, #0x20
//   0x5117a0: AA0003F3  mov      x19, x0
uint64_t fde_func_17043_0x51178c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0051178CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10103FFULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9027BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9001BF3ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910083FDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x94000014ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x36000180ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #17052 | PC: 0x5119dc..0x511a54 (120 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x5119dc: D503233F  paciasp  
//   0x5119e0: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x5119e4: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x5119e8: 910003FD  mov      x29, sp
//   0x5119ec: F9401013  ldr      x19, [x0, #0x20]
//   0x5119f0: B40001D3  cbz      x19, #0x511a28
uint64_t fde_func_17052_0x5119dc(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x005119DCULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9014FF4ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9401013ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB40001D3ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400C08ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9401509ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #17062 | PC: 0x511fec..0x5120ec (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x511fec: D503233F  paciasp  
//   0x511ff0: A9BA7BFD  stp      x29, x30, [sp, #-0x60]!
//   0x511ff4: A9016FFC  stp      x28, x27, [sp, #0x10]
//   0x511ff8: A90267FA  stp      x26, x25, [sp, #0x20]
//   0x511ffc: A9035FF8  stp      x24, x23, [sp, #0x30]
//   0x512000: A90457F6  stp      x22, x21, [sp, #0x40]
uint64_t fde_func_17062_0x511fec(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00511FECULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BA7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9016FFCULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90267FAULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9035FF8ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90457F6ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9054FF4ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #17071 | PC: 0x512554..0x512580 (44 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x512554: D503233F  paciasp  
//   0x512558: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x51255c: F9000BF3  str      x19, [sp, #0x10]
//   0x512560: 910003FD  mov      x29, sp
//   0x512564: AA0003F3  mov      x19, x0
//   0x512568: 97FFFFE3  bl       #0x5124f4
uint64_t fde_func_17071_0x512554(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00512554ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF3ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x97FFFFE3ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA1303E0ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400BF3ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #17081 | PC: 0x512a60..0x512a6c (12 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x512a60: D503245F  bti      c
//   0x512a64: D1002000  sub      x0, x0, #8
//   0x512a68: 17FFFEBB  b        #0x512554
uint64_t fde_func_17081_0x512a60(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00512A60ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD1002000ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x17FFFEBBULL ^ (2ULL << 32);
    return state ^ (state >> 29);
}

// FDE #17090 | PC: 0x512b30..0x512b54 (36 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x512b30: D503245F  bti      c
//   0x512b34: A942280B  ldp      x11, x10, [x0, #0x20]
//   0x512b38: 91006408  add      x8, x0, #0x19
//   0x512b3c: 39406009  ldrb     w9, [x0, #0x18]
//   0x512b40: D341FD2C  lsr      x12, x9, #1
//   0x512b44: 7200013F  tst      w9, #1
uint64_t fde_func_17090_0x512b30(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00512B30ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA942280BULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91006408ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x39406009ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD341FD2CULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x7200013FULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9A8A0100ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9A8B0181ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #17100 | PC: 0x512d44..0x512d50 (12 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x512d44: D503245F  bti      c
//   0x512d48: D1002000  sub      x0, x0, #8
//   0x512d4c: 17FFFFC5  b        #0x512c60
uint64_t fde_func_17100_0x512d44(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00512D44ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD1002000ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x17FFFFC5ULL ^ (2ULL << 32);
    return state ^ (state >> 29);
}

// FDE #17109 | PC: 0x51327c..0x5132f4 (120 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x51327c: D503233F  paciasp  
//   0x513280: D10303FF  sub      sp, sp, #0xc0
//   0x513284: A90A7BFD  stp      x29, x30, [sp, #0xa0]
//   0x513288: A90B4FF4  stp      x20, x19, [sp, #0xb0]
//   0x51328c: 910283FD  add      x29, sp, #0xa0
//   0x513290: D53BD054  mrs      x20, tpidr_el0
uint64_t fde_func_17109_0x51327c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0051327CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10303FFULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90A7BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90B4FF4ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910283FDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD53BD054ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9401688ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #17119 | PC: 0x51368c..0x5136d4 (72 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x51368c: D503233F  paciasp  
//   0x513690: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x513694: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x513698: 910003FD  mov      x29, sp
//   0x51369c: AA0103F3  mov      x19, x1
//   0x5136a0: AA0003F4  mov      x20, x0
uint64_t fde_func_17119_0x51368c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0051368CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9014FF4ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0103F3ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F4ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9401688ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xEB13011FULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #17128 | PC: 0x513b20..0x513bfc (220 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x513b20: D503233F  paciasp  
//   0x513b24: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x513b28: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x513b2c: 910003FD  mov      x29, sp
//   0x513b30: AA0103F4  mov      x20, x1
//   0x513b34: AA0003F3  mov      x19, x0
uint64_t fde_func_17128_0x513b20(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00513B20ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9014FF4ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0103F4ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x94000845ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xEB14001FULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #17138 | PC: 0x51404c..0x514090 (68 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x51404c: D503233F  paciasp  
//   0x514050: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x514054: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x514058: 910003FD  mov      x29, sp
//   0x51405c: F9400008  ldr      x8, [x0]
//   0x514060: AA0103F3  mov      x19, x1
uint64_t fde_func_17138_0x51404c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0051404CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9014FF4ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400008ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0103F3ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F4ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9800104ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #17147 | PC: 0x514534..0x514634 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x514534: D503233F  paciasp  
//   0x514538: A9BD7BFD  stp      x29, x30, [sp, #-0x30]!
//   0x51453c: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x514540: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x514544: 910003FD  mov      x29, sp
//   0x514548: F9400016  ldr      x22, [x0]
uint64_t fde_func_17147_0x514534(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00514534ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BD7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90157F6ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9024FF4ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400016ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400C15ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #17157 | PC: 0x514f48..0x514f74 (44 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x514f48: D503233F  paciasp  
//   0x514f4c: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x514f50: F9000BF3  str      x19, [sp, #0x10]
//   0x514f54: 910003FD  mov      x29, sp
//   0x514f58: AA0003F3  mov      x19, x0
//   0x514f5c: 97FFFFE1  bl       #0x514ee0
uint64_t fde_func_17157_0x514f48(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00514F48ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF3ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x97FFFFE1ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA1303E0ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400BF3ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #17166 | PC: 0x5159c4..0x515ac4 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x5159c4: D503233F  paciasp  
//   0x5159c8: A9BA7BFD  stp      x29, x30, [sp, #-0x60]!
//   0x5159cc: A9016FFC  stp      x28, x27, [sp, #0x10]
//   0x5159d0: A90267FA  stp      x26, x25, [sp, #0x20]
//   0x5159d4: A9035FF8  stp      x24, x23, [sp, #0x30]
//   0x5159d8: A90457F6  stp      x22, x21, [sp, #0x40]
uint64_t fde_func_17166_0x5159c4(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x005159C4ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BA7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9016FFCULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90267FAULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9035FF8ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90457F6ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9054FF4ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #17176 | PC: 0x5164fc..0x5165fc (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x5164fc: D503233F  paciasp  
//   0x516500: D10143FF  sub      sp, sp, #0x50
//   0x516504: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x516508: F9001BF5  str      x21, [sp, #0x30]
//   0x51650c: A9044FF4  stp      x20, x19, [sp, #0x40]
//   0x516510: 910083FD  add      x29, sp, #0x20
uint64_t fde_func_17176_0x5164fc(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x005164FCULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10143FFULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9027BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9001BF5ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9044FF4ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910083FDULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB0000648ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91372108ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #17185 | PC: 0x517108..0x5171cc (196 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x517108: D503233F  paciasp  
//   0x51710c: D10103FF  sub      sp, sp, #0x40
//   0x517110: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x517114: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x517118: 910083FD  add      x29, sp, #0x20
//   0x51711c: F9406008  ldr      x8, [x0, #0xc0]
uint64_t fde_func_17185_0x517108(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00517108ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10103FFULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9027BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9034FF4ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910083FDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9406008ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB9401001ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #17195 | PC: 0x517498..0x5174ec (84 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x517498: D503233F  paciasp  
//   0x51749c: D10103FF  sub      sp, sp, #0x40
//   0x5174a0: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x5174a4: F9001BF3  str      x19, [sp, #0x30]
//   0x5174a8: 910083FD  add      x29, sp, #0x20
//   0x5174ac: F9406013  ldr      x19, [x0, #0xc0]
uint64_t fde_func_17195_0x517498(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00517498ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10103FFULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9027BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9001BF3ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910083FDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9406013ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD0FFDB81ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91197821ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #17204 | PC: 0x517710..0x517724 (20 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x517710: D503245F  bti      c
//   0x517714: F8578008  ldur     x8, [x0, #-0x88]
//   0x517718: F8588009  ldur     x9, [x0, #-0x78]
//   0x51771c: CB090100  sub      x0, x8, x9
//   0x517720: D65F03C0  ret      
uint64_t fde_func_17204_0x517710(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00517710ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF8578008ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF8588009ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xCB090100ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD65F03C0ULL ^ (4ULL << 32);
    return state ^ (state >> 29);
}

// FDE #17214 | PC: 0x517b2c..0x517c2c (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x517b2c: D503233F  paciasp  
//   0x517b30: D10603FF  sub      sp, sp, #0x180
//   0x517b34: A9147BFD  stp      x29, x30, [sp, #0x140]
//   0x517b38: F900ABFC  str      x28, [sp, #0x150]
//   0x517b3c: A91657F6  stp      x22, x21, [sp, #0x160]
//   0x517b40: A9174FF4  stp      x20, x19, [sp, #0x170]
uint64_t fde_func_17214_0x517b2c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00517B2CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10603FFULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9147BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF900ABFCULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA91657F6ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9174FF4ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910503FDULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD53BD056ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #17223 | PC: 0x517fa4..0x517ff8 (84 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x517fa4: D503233F  paciasp  
//   0x517fa8: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x517fac: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x517fb0: 910003FD  mov      x29, sp
//   0x517fb4: AA0103F3  mov      x19, x1
//   0x517fb8: 97F73E00  bl       #0x2e77b8
uint64_t fde_func_17223_0x517fa4(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00517FA4ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9014FF4ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0103F3ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x97F73E00ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F4ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x97F73DE6ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #17233 | PC: 0x518718..0x518818 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x518718: D503233F  paciasp  
//   0x51871c: D10643FF  sub      sp, sp, #0x190
//   0x518720: A9157BFD  stp      x29, x30, [sp, #0x150]
//   0x518724: F900B3FC  str      x28, [sp, #0x160]
//   0x518728: A91757F6  stp      x22, x21, [sp, #0x170]
//   0x51872c: A9184FF4  stp      x20, x19, [sp, #0x180]
uint64_t fde_func_17233_0x518718(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00518718ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10643FFULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9157BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF900B3FCULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA91757F6ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9184FF4ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910543FDULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD53BD056ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #17242 | PC: 0x519008..0x519044 (60 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x519008: D503233F  paciasp  
//   0x51900c: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x519010: F9000BF3  str      x19, [sp, #0x10]
//   0x519014: 910003FD  mov      x29, sp
//   0x519018: AA0003F3  mov      x19, x0
//   0x51901c: 9100A000  add      x0, x0, #0x28
uint64_t fde_func_17242_0x519008(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00519008ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF3ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9100A000ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF00004A8ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91298108ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #17252 | PC: 0x519480..0x5194ac (44 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x519480: D503233F  paciasp  
//   0x519484: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x519488: F9000BF3  str      x19, [sp, #0x10]
//   0x51948c: 910003FD  mov      x29, sp
//   0x519490: AA0003F3  mov      x19, x0
//   0x519494: 97FFFFEC  bl       #0x519444
uint64_t fde_func_17252_0x519480(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00519480ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF3ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x97FFFFECULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA1303E0ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400BF3ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #17262 | PC: 0x519c04..0x519cec (232 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x519c04: D503233F  paciasp  
//   0x519c08: D10603FF  sub      sp, sp, #0x180
//   0x519c0c: A9147BFD  stp      x29, x30, [sp, #0x140]
//   0x519c10: F900ABFC  str      x28, [sp, #0x150]
//   0x519c14: A91657F6  stp      x22, x21, [sp, #0x160]
//   0x519c18: A9174FF4  stp      x20, x19, [sp, #0x170]
uint64_t fde_func_17262_0x519c04(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00519C04ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10603FFULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9147BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF900ABFCULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA91657F6ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9174FF4ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910503FDULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD53BD055ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #17271 | PC: 0x51a7e4..0x51a800 (28 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x51a7e4: D503245F  bti      c
//   0x51a7e8: 394AD408  ldrb     w8, [x0, #0x2b5]
//   0x51a7ec: 910AA009  add      x9, x0, #0x2a8
//   0x51a7f0: 910C200A  add      x10, x0, #0x308
//   0x51a7f4: 7100011F  cmp      w8, #0
//   0x51a7f8: 9A890140  csel     x0, x10, x9, eq
uint64_t fde_func_17271_0x51a7e4(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0051A7E4ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x394AD408ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910AA009ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910C200AULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x7100011FULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9A890140ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x17FFF825ULL ^ (6ULL << 32);
    return state ^ (state >> 29);
}

// FDE #17281 | PC: 0x51ab60..0x51aba0 (64 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x51ab60: D503233F  paciasp  
//   0x51ab64: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x51ab68: F9000BF3  str      x19, [sp, #0x10]
//   0x51ab6c: 910003FD  mov      x29, sp
//   0x51ab70: 39403408  ldrb     w8, [x0, #0xd]
//   0x51ab74: 340000E8  cbz      w8, #0x51ab90
uint64_t fde_func_17281_0x51ab60(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0051AB60ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF3ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x39403408ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x340000E8ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0103F3ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x97FFF85DULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #17290 | PC: 0x51d100..0x51d1a4 (164 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x51d100: D503233F  paciasp  
//   0x51d104: A9BD7BFD  stp      x29, x30, [sp, #-0x30]!
//   0x51d108: F9000BF5  str      x21, [sp, #0x10]
//   0x51d10c: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x51d110: 910003FD  mov      x29, sp
//   0x51d114: AA0003F5  mov      x21, x0
uint64_t fde_func_17290_0x51d100(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0051D100ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BD7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF5ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9024FF4ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F5ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400828ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x3DC00020ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #17300 | PC: 0x51d768..0x51d7a8 (64 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x51d768: D503233F  paciasp  
//   0x51d76c: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x51d770: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x51d774: 910003FD  mov      x29, sp
//   0x51d778: AA0003F4  mov      x20, x0
//   0x51d77c: 52800200  mov      w0, #0x10
uint64_t fde_func_17300_0x51d768(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0051D768ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9014FF4ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F4ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x52800200ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0103F3ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x97F6FB7CULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #17309 | PC: 0x51db00..0x51db4c (76 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x51db00: D503233F  paciasp  
//   0x51db04: A9BD7BFD  stp      x29, x30, [sp, #-0x30]!
//   0x51db08: F9000BF5  str      x21, [sp, #0x10]
//   0x51db0c: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x51db10: 910003FD  mov      x29, sp
//   0x51db14: A9405015  ldp      x21, x20, [x0]
uint64_t fde_func_17309_0x51db00(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0051DB00ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BD7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF5ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9024FF4ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9405015ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xEB15029FULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #17319 | PC: 0x51ebb4..0x51ecb4 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x51ebb4: D503233F  paciasp  
//   0x51ebb8: A9BA7BFD  stp      x29, x30, [sp, #-0x60]!
//   0x51ebbc: A9016FFC  stp      x28, x27, [sp, #0x10]
//   0x51ebc0: A90267FA  stp      x26, x25, [sp, #0x20]
//   0x51ebc4: A9035FF8  stp      x24, x23, [sp, #0x30]
//   0x51ebc8: A90457F6  stp      x22, x21, [sp, #0x40]
uint64_t fde_func_17319_0x51ebb4(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0051EBB4ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BA7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9016FFCULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90267FAULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9035FF8ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90457F6ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9054FF4ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #17328 | PC: 0x51ffa4..0x520054 (176 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x51ffa4: D503233F  paciasp  
//   0x51ffa8: D101C3FF  sub      sp, sp, #0x70
//   0x51ffac: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x51ffb0: F9001BF9  str      x25, [sp, #0x30]
//   0x51ffb4: A9045FF8  stp      x24, x23, [sp, #0x40]
//   0x51ffb8: A90557F6  stp      x22, x21, [sp, #0x50]
uint64_t fde_func_17328_0x51ffa4(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0051FFA4ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD101C3FFULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9027BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9001BF9ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9045FF8ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90557F6ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9064FF4ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910083FDULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #17338 | PC: 0x520334..0x520434 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x520334: D503233F  paciasp  
//   0x520338: D10683FF  sub      sp, sp, #0x1a0
//   0x52033c: A9157BFD  stp      x29, x30, [sp, #0x150]
//   0x520340: F900B3FC  str      x28, [sp, #0x160]
//   0x520344: A9175FF8  stp      x24, x23, [sp, #0x170]
//   0x520348: A91857F6  stp      x22, x21, [sp, #0x180]
uint64_t fde_func_17338_0x520334(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00520334ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10683FFULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9157BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF900B3FCULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9175FF8ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA91857F6ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9194FF4ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910543FDULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #17347 | PC: 0x520ab4..0x520ae8 (52 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x520ab4: D503233F  paciasp  
//   0x520ab8: D10083FF  sub      sp, sp, #0x20
//   0x520abc: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x520ac0: 910043FD  add      x29, sp, #0x10
//   0x520ac4: A90007E0  stp      x0, x1, [sp]
//   0x520ac8: 910003E0  mov      x0, sp
uint64_t fde_func_17347_0x520ab4(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00520AB4ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10083FFULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90007E0ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003E0ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x52800021ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x94000022ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #17357 | PC: 0x520f5c..0x520fc8 (108 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x520f5c: D503233F  paciasp  
//   0x520f60: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x520f64: F9000BF3  str      x19, [sp, #0x10]
//   0x520f68: 910003FD  mov      x29, sp
//   0x520f6c: F9400413  ldr      x19, [x0, #8]
//   0x520f70: F94A6668  ldr      x8, [x19, #0x14c8]
uint64_t fde_func_17357_0x520f5c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00520F5CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF3ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400413ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF94A6668ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x927FF908ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400908ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #17366 | PC: 0x521f9c..0x522098 (252 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x521f9c: D503233F  paciasp  
//   0x521fa0: D10643FF  sub      sp, sp, #0x190
//   0x521fa4: A9157BFD  stp      x29, x30, [sp, #0x150]
//   0x521fa8: F900B3FC  str      x28, [sp, #0x160]
//   0x521fac: A91757F6  stp      x22, x21, [sp, #0x170]
//   0x521fb0: A9184FF4  stp      x20, x19, [sp, #0x180]
uint64_t fde_func_17366_0x521f9c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00521F9CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10643FFULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9157BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF900B3FCULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA91757F6ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9184FF4ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910543FDULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD53BD054ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #17376 | PC: 0x523740..0x523840 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x523740: D503233F  paciasp  
//   0x523744: D10643FF  sub      sp, sp, #0x190
//   0x523748: A9137BFD  stp      x29, x30, [sp, #0x130]
//   0x52374c: A9146FFC  stp      x28, x27, [sp, #0x140]
//   0x523750: A91567FA  stp      x26, x25, [sp, #0x150]
//   0x523754: A9165FF8  stp      x24, x23, [sp, #0x160]
uint64_t fde_func_17376_0x523740(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00523740ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10643FFULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9137BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9146FFCULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA91567FAULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9165FF8ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA91757F6ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9184FF4ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #17385 | PC: 0x525624..0x525724 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x525624: D503233F  paciasp  
//   0x525628: D10603FF  sub      sp, sp, #0x180
//   0x52562c: A9147BFD  stp      x29, x30, [sp, #0x140]
//   0x525630: F900ABFC  str      x28, [sp, #0x150]
//   0x525634: A91657F6  stp      x22, x21, [sp, #0x160]
//   0x525638: A9174FF4  stp      x20, x19, [sp, #0x170]
uint64_t fde_func_17385_0x525624(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00525624ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10603FFULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9147BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF900ABFCULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA91657F6ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9174FF4ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910503FDULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD53BD056ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #17395 | PC: 0x526768..0x526868 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x526768: D503233F  paciasp  
//   0x52676c: D10603FF  sub      sp, sp, #0x180
//   0x526770: A9147BFD  stp      x29, x30, [sp, #0x140]
//   0x526774: A9155FFC  stp      x28, x23, [sp, #0x150]
//   0x526778: A91657F6  stp      x22, x21, [sp, #0x160]
//   0x52677c: A9174FF4  stp      x20, x19, [sp, #0x170]
uint64_t fde_func_17395_0x526768(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00526768ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10603FFULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9147BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9155FFCULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA91657F6ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9174FF4ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910503FDULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD53BD055ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #17404 | PC: 0x5275bc..0x5276bc (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x5275bc: D503233F  paciasp  
//   0x5275c0: D10603FF  sub      sp, sp, #0x180
//   0x5275c4: A9147BFD  stp      x29, x30, [sp, #0x140]
//   0x5275c8: F900ABFC  str      x28, [sp, #0x150]
//   0x5275cc: A91657F6  stp      x22, x21, [sp, #0x160]
//   0x5275d0: A9174FF4  stp      x20, x19, [sp, #0x170]
uint64_t fde_func_17404_0x5275bc(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x005275BCULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10603FFULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9147BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF900ABFCULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA91657F6ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9174FF4ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910503FDULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD53BD055ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #17414 | PC: 0x527940..0x52794c (12 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x527940: D503245F  bti      c
//   0x527944: 390AE001  strb     w1, [x0, #0x2b8]
//   0x527948: D65F03C0  ret      
uint64_t fde_func_17414_0x527940(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00527940ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x390AE001ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD65F03C0ULL ^ (2ULL << 32);
    return state ^ (state >> 29);
}

// FDE #17423 | PC: 0x528fc4..0x528fd8 (20 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x528fc4: D503245F  bti      c
//   0x528fc8: 2A0303E4  mov      w4, w3
//   0x528fcc: AA0203E3  mov      x3, x2
//   0x528fd0: AA1F03E2  mov      x2, xzr
//   0x528fd4: 14000001  b        #0x528fd8
uint64_t fde_func_17423_0x528fc4(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00528FC4ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x2A0303E4ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0203E3ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA1F03E2ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x14000001ULL ^ (4ULL << 32);
    return state ^ (state >> 29);
}

// FDE #17433 | PC: 0x529b34..0x529b40 (12 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x529b34: D503245F  bti      c
//   0x529b38: 2A1F03E3  mov      w3, wzr
//   0x529b3c: 17FFFD22  b        #0x528fc4
uint64_t fde_func_17433_0x529b34(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00529B34ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x2A1F03E3ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x17FFFD22ULL ^ (2ULL << 32);
    return state ^ (state >> 29);
}

// FDE #17442 | PC: 0x52a1e0..0x52a24c (108 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x52a1e0: D503233F  paciasp  
//   0x52a1e4: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x52a1e8: F9000BF3  str      x19, [sp, #0x10]
//   0x52a1ec: 910003FD  mov      x29, sp
//   0x52a1f0: F94A6408  ldr      x8, [x0, #0x14c8]
//   0x52a1f4: 927FF908  and      x8, x8, #0xfffffffffffffffe
uint64_t fde_func_17442_0x52a1e0(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0052A1E0ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF3ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF94A6408ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x927FF908ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400908ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB40000A8ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #17452 | PC: 0x52aeb4..0x52afb4 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x52aeb4: D503233F  paciasp  
//   0x52aeb8: D105C3FF  sub      sp, sp, #0x170
//   0x52aebc: A9117BFD  stp      x29, x30, [sp, #0x110]
//   0x52aec0: F90093FC  str      x28, [sp, #0x120]
//   0x52aec4: A91367FA  stp      x26, x25, [sp, #0x130]
//   0x52aec8: A9145FF8  stp      x24, x23, [sp, #0x140]
uint64_t fde_func_17452_0x52aeb4(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0052AEB4ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD105C3FFULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9117BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF90093FCULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA91367FAULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9145FF8ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA91557F6ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9164FF4ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #17461 | PC: 0x52d49c..0x52d528 (140 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x52d49c: D503233F  paciasp  
//   0x52d4a0: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x52d4a4: F9000BF3  str      x19, [sp, #0x10]
//   0x52d4a8: 910003FD  mov      x29, sp
//   0x52d4ac: AA0003F3  mov      x19, x0
//   0x52d4b0: F94A8808  ldr      x8, [x0, #0x1510]
uint64_t fde_func_17461_0x52d49c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0052D49CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF3ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF94A8808ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB4000088ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x97F6E8C0ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #17471 | PC: 0x52d73c..0x52d748 (12 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x52d73c: D503245F  bti      c
//   0x52d740: D1004000  sub      x0, x0, #0x10
//   0x52d744: 17FFF0FC  b        #0x529b34
uint64_t fde_func_17471_0x52d73c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0052D73CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD1004000ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x17FFF0FCULL ^ (2ULL << 32);
    return state ^ (state >> 29);
}

// FDE #17480 | PC: 0x52d7a8..0x52d7b4 (12 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x52d7a8: D503245F  bti      c
//   0x52d7ac: D1008000  sub      x0, x0, #0x20
//   0x52d7b0: 17FFD1E3  b        #0x521f3c
uint64_t fde_func_17480_0x52d7a8(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0052D7A8ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD1008000ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x17FFD1E3ULL ^ (2ULL << 32);
    return state ^ (state >> 29);
}

// FDE #17490 | PC: 0x52d838..0x52d844 (12 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x52d838: D503245F  bti      c
//   0x52d83c: D100C000  sub      x0, x0, #0x30
//   0x52d840: 17FFF59D  b        #0x52aeb4
uint64_t fde_func_17490_0x52d838(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0052D838ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD100C000ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x17FFF59DULL ^ (2ULL << 32);
    return state ^ (state >> 29);
}

// FDE #17499 | PC: 0x52d8a4..0x52d8b0 (12 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x52d8a4: D503245F  bti      c
//   0x52d8a8: D1010000  sub      x0, x0, #0x40
//   0x52d8ac: 17FFD1A4  b        #0x521f3c
uint64_t fde_func_17499_0x52d8a4(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0052D8A4ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD1010000ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x17FFD1A4ULL ^ (2ULL << 32);
    return state ^ (state >> 29);
}

// FDE #17509 | PC: 0x52dc54..0x52dd54 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x52dc54: D503233F  paciasp  
//   0x52dc58: A9BC7BFD  stp      x29, x30, [sp, #-0x40]!
//   0x52dc5c: F9000BF7  str      x23, [sp, #0x10]
//   0x52dc60: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x52dc64: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x52dc68: 910003FD  mov      x29, sp
uint64_t fde_func_17509_0x52dc54(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0052DC54ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BC7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF7ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90257F6ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9034FF4ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x5283D628ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x8B080014ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #17518 | PC: 0x52e124..0x52e184 (96 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x52e124: D503233F  paciasp  
//   0x52e128: A9BD7BFD  stp      x29, x30, [sp, #-0x30]!
//   0x52e12c: F9000BF5  str      x21, [sp, #0x10]
//   0x52e130: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x52e134: 910003FD  mov      x29, sp
//   0x52e138: AA0203F3  mov      x19, x2
uint64_t fde_func_17518_0x52e124(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0052E124ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BD7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF5ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9024FF4ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0203F3ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0103F4ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F5ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #17528 | PC: 0x52e910..0x52e98c (124 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x52e910: D503233F  paciasp  
//   0x52e914: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x52e918: F9000BF3  str      x19, [sp, #0x10]
//   0x52e91c: 910003FD  mov      x29, sp
//   0x52e920: 5283D648  mov      w8, #0x1eb2
//   0x52e924: 38686808  ldrb     w8, [x0, x8]
uint64_t fde_func_17528_0x52e910(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0052E910ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF3ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x5283D648ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x38686808ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x34000088ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #17537 | PC: 0x52f628..0x52f728 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x52f628: D503233F  paciasp  
//   0x52f62c: D10683FF  sub      sp, sp, #0x1a0
//   0x52f630: A9147BFD  stp      x29, x30, [sp, #0x140]
//   0x52f634: F900ABFC  str      x28, [sp, #0x150]
//   0x52f638: A91667FA  stp      x26, x25, [sp, #0x160]
//   0x52f63c: A9175FF8  stp      x24, x23, [sp, #0x170]
uint64_t fde_func_17537_0x52f628(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0052F628ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10683FFULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9147BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF900ABFCULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA91667FAULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9175FF8ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA91857F6ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9194FF4ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #17547 | PC: 0x5300a4..0x5301a4 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x5300a4: D503233F  paciasp  
//   0x5300a8: D106C3FF  sub      sp, sp, #0x1b0
//   0x5300ac: A9167BFD  stp      x29, x30, [sp, #0x160]
//   0x5300b0: F900BBFC  str      x28, [sp, #0x170]
//   0x5300b4: A9185FF8  stp      x24, x23, [sp, #0x180]
//   0x5300b8: A91957F6  stp      x22, x21, [sp, #0x190]
uint64_t fde_func_17547_0x5300a4(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x005300A4ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD106C3FFULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9167BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF900BBFCULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9185FF8ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA91957F6ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA91A4FF4ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910583FDULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #17557 | PC: 0x530fc4..0x531040 (124 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x530fc4: D503233F  paciasp  
//   0x530fc8: A9BD7BFD  stp      x29, x30, [sp, #-0x30]!
//   0x530fcc: F9000BF5  str      x21, [sp, #0x10]
//   0x530fd0: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x530fd4: 910003FD  mov      x29, sp
//   0x530fd8: F9400028  ldr      x8, [x1]
uint64_t fde_func_17557_0x530fc4(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00530FC4ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BD7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF5ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9024FF4ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400028ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF100051FULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x540002E9ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #17566 | PC: 0x531440..0x531448 (8 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x531440: D503245F  bti      c
//   0x531444: 17FEEF37  b        #0x4ed120
uint64_t fde_func_17566_0x531440(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00531440ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x17FEEF37ULL ^ (1ULL << 32);
    return state ^ (state >> 29);
}

// FDE #17576 | PC: 0x5323a4..0x532484 (224 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x5323a4: D503233F  paciasp  
//   0x5323a8: D10603FF  sub      sp, sp, #0x180
//   0x5323ac: A9147BFD  stp      x29, x30, [sp, #0x140]
//   0x5323b0: F900ABFC  str      x28, [sp, #0x150]
//   0x5323b4: A91657F6  stp      x22, x21, [sp, #0x160]
//   0x5323b8: A9174FF4  stp      x20, x19, [sp, #0x170]
uint64_t fde_func_17576_0x5323a4(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x005323A4ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10603FFULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9147BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF900ABFCULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA91657F6ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9174FF4ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910503FDULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD53BD055ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #17585 | PC: 0x53279c..0x5327d8 (60 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x53279c: D503233F  paciasp  
//   0x5327a0: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x5327a4: F9000BF3  str      x19, [sp, #0x10]
//   0x5327a8: 910003FD  mov      x29, sp
//   0x5327ac: 39400008  ldrb     w8, [x0]
//   0x5327b0: 7100311F  cmp      w8, #0xc
uint64_t fde_func_17585_0x53279c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0053279CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF3ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x39400008ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x7100311FULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x540000A3ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #17595 | PC: 0x532bf0..0x532ca4 (180 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x532bf0: D503233F  paciasp  
//   0x532bf4: A9BC7BFD  stp      x29, x30, [sp, #-0x40]!
//   0x532bf8: A9015FF8  stp      x24, x23, [sp, #0x10]
//   0x532bfc: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x532c00: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x532c04: 910003FD  mov      x29, sp
uint64_t fde_func_17595_0x532bf0(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00532BF0ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BC7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9015FF8ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90257F6ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9034FF4ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9405C16ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0103F3ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #17604 | PC: 0x533004..0x533040 (60 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x533004: D503233F  paciasp  
//   0x533008: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x53300c: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x533010: 910003FD  mov      x29, sp
//   0x533014: AA0103F3  mov      x19, x1
//   0x533018: AA0003F4  mov      x20, x0
uint64_t fde_func_17604_0x533004(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00533004ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9014FF4ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0103F3ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F4ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x97FFFDEFULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9401268ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #17614 | PC: 0x53353c..0x533598 (92 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x53353c: D503233F  paciasp  
//   0x533540: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x533544: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x533548: 910003FD  mov      x29, sp
//   0x53354c: AA0003F3  mov      x19, x0
//   0x533550: F9400414  ldr      x20, [x0, #8]
uint64_t fde_func_17614_0x53353c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0053353CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9014FF4ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400414ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400A68ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xEB14011FULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #17623 | PC: 0x533b44..0x533b8c (72 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x533b44: D503245F  bti      c
//   0x533b48: AA0103E8  mov      x8, x1
//   0x533b4c: F9401021  ldr      x1, [x1, #0x20]
//   0x533b50: F9401509  ldr      x9, [x8, #0x28]
//   0x533b54: EB09003F  cmp      x1, x9
//   0x533b58: 540000E0  b.eq     #0x533b74
uint64_t fde_func_17623_0x533b44(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00533B44ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0103E8ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9401021ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9401509ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xEB09003FULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x540000E0ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF940082AULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF940390BULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #17633 | PC: 0x534378..0x534478 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x534378: D503233F  paciasp  
//   0x53437c: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x534380: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x534384: 910003FD  mov      x29, sp
//   0x534388: F9400008  ldr      x8, [x0]
//   0x53438c: D285AD2B  mov      x11, #0x2d69
uint64_t fde_func_17633_0x534378(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00534378ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9014FF4ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400008ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD285AD2BULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF2BD670BULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503201FULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #17642 | PC: 0x5349b0..0x534ab0 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x5349b0: D503233F  paciasp  
//   0x5349b4: A9BC7BFD  stp      x29, x30, [sp, #-0x40]!
//   0x5349b8: F9000BF7  str      x23, [sp, #0x10]
//   0x5349bc: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x5349c0: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x5349c4: 910003FD  mov      x29, sp
uint64_t fde_func_17642_0x5349b0(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x005349B0ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BC7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF7ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90257F6ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9034FF4ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400009ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD285AD2BULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #17652 | PC: 0x537088..0x5370cc (68 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x537088: D503233F  paciasp  
//   0x53708c: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x537090: F9000BF3  str      x19, [sp, #0x10]
//   0x537094: 910003FD  mov      x29, sp
//   0x537098: 52800028  mov      w8, #1
//   0x53709c: AA1F03E1  mov      x1, xzr
uint64_t fde_func_17652_0x537088(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00537088ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF3ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x52800028ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA1F03E1ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB900F008ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #17661 | PC: 0x5372c0..0x5372d4 (20 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x5372c0: D503245F  bti      c
//   0x5372c4: 72001C3F  tst      w1, #0xff
//   0x5372c8: 1A9F07E8  cset     w8, ne
//   0x5372cc: 531E7500  lsl      w0, w8, #2
//   0x5372d0: D65F03C0  ret      
uint64_t fde_func_17661_0x5372c0(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x005372C0ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x72001C3FULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x1A9F07E8ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x531E7500ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD65F03C0ULL ^ (4ULL << 32);
    return state ^ (state >> 29);
}

// FDE #17671 | PC: 0x537540..0x53755c (28 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x537540: D503245F  bti      c
//   0x537544: AA0003E8  mov      x8, x0
//   0x537548: F9400000  ldr      x0, [x0]
//   0x53754c: F900011F  str      xzr, [x8]
//   0x537550: B4000040  cbz      x0, #0x537558
//   0x537554: 17F935CA  b        #0x384c7c
uint64_t fde_func_17671_0x537540(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00537540ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003E8ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400000ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF900011FULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB4000040ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x17F935CAULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD65F03C0ULL ^ (6ULL << 32);
    return state ^ (state >> 29);
}

// FDE #17680 | PC: 0x53764c..0x537660 (20 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x53764c: D503245F  bti      c
//   0x537650: F942EC00  ldr      x0, [x0, #0x5d8]
//   0x537654: F9400008  ldr      x8, [x0]
//   0x537658: F9403D10  ldr      x16, [x8, #0x78]
//   0x53765c: D61F0200  br       x16
uint64_t fde_func_17680_0x53764c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0053764CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF942EC00ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400008ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9403D10ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD61F0200ULL ^ (4ULL << 32);
    return state ^ (state >> 29);
}

// FDE #17690 | PC: 0x537748..0x537764 (28 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x537748: D503245F  bti      c
//   0x53774c: F942F008  ldr      x8, [x0, #0x5e0]
//   0x537750: B4000068  cbz      x8, #0x53775c
//   0x537754: F940C900  ldr      x0, [x8, #0x190]
//   0x537758: D65F03C0  ret      
//   0x53775c: AA1F03E0  mov      x0, xzr
uint64_t fde_func_17690_0x537748(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00537748ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF942F008ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB4000068ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF940C900ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD65F03C0ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA1F03E0ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD65F03C0ULL ^ (6ULL << 32);
    return state ^ (state >> 29);
}

// FDE #17699 | PC: 0x537804..0x537818 (20 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x537804: D503245F  bti      c
//   0x537808: D00003C8  adrp     x8, #0x5b1000
//   0x53780c: 911D4108  add      x8, x8, #0x750
//   0x537810: F8018408  str      x8, [x0], #0x18
//   0x537814: 17FEE150  b        #0x4efd54
uint64_t fde_func_17699_0x537804(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00537804ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD00003C8ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x911D4108ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF8018408ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x17FEE150ULL ^ (4ULL << 32);
    return state ^ (state >> 29);
}

// FDE #17709 | PC: 0x537bb0..0x537ca4 (244 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x537bb0: D503233F  paciasp  
//   0x537bb4: D10603FF  sub      sp, sp, #0x180
//   0x537bb8: A9147BFD  stp      x29, x30, [sp, #0x140]
//   0x537bbc: F900ABFC  str      x28, [sp, #0x150]
//   0x537bc0: A91657F6  stp      x22, x21, [sp, #0x160]
//   0x537bc4: A9174FF4  stp      x20, x19, [sp, #0x170]
uint64_t fde_func_17709_0x537bb0(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00537BB0ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10603FFULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9147BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF900ABFCULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA91657F6ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9174FF4ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910503FDULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD53BD055ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #17718 | PC: 0x53868c..0x5386e8 (92 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x53868c: D503233F  paciasp  
//   0x538690: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x538694: F9000BF3  str      x19, [sp, #0x10]
//   0x538698: 910003FD  mov      x29, sp
//   0x53869c: AA0103F3  mov      x19, x1
//   0x5386a0: 910073A1  add      x1, x29, #0x1c
uint64_t fde_func_17718_0x53868c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0053868CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF3ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0103F3ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910073A1ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x97FE9CB4ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x36000160ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #17728 | PC: 0x538b20..0x538bc4 (164 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x538b20: D503233F  paciasp  
//   0x538b24: D10283FF  sub      sp, sp, #0xa0
//   0x538b28: A9077BFD  stp      x29, x30, [sp, #0x70]
//   0x538b2c: F90043F5  str      x21, [sp, #0x80]
//   0x538b30: A9094FF4  stp      x20, x19, [sp, #0x90]
//   0x538b34: 9101C3FD  add      x29, sp, #0x70
uint64_t fde_func_17728_0x538b20(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00538B20ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10283FFULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9077BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF90043F5ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9094FF4ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9101C3FDULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD53BD055ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #17737 | PC: 0x5390f8..0x5391f8 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x5390f8: D503233F  paciasp  
//   0x5390fc: A9BB7BFD  stp      x29, x30, [sp, #-0x50]!
//   0x539100: F9000BF9  str      x25, [sp, #0x10]
//   0x539104: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x539108: A90357F6  stp      x22, x21, [sp, #0x30]
//   0x53910c: A9044FF4  stp      x20, x19, [sp, #0x40]
uint64_t fde_func_17737_0x5390f8(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x005390F8ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BB7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF9ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9025FF8ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90357F6ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9044FF4ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x900003C9ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #17747 | PC: 0x5396e0..0x5397e0 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x5396e0: D503233F  paciasp  
//   0x5396e4: A9BD7BFD  stp      x29, x30, [sp, #-0x30]!
//   0x5396e8: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x5396ec: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x5396f0: 910003FD  mov      x29, sp
//   0x5396f4: 2A0003E8  mov      w8, w0
uint64_t fde_func_17747_0x5396e0(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x005396E0ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BD7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90157F6ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9024FF4ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x2A0003E8ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400020ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x7101251FULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #17756 | PC: 0x539fe0..0x53a0e0 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x539fe0: D503233F  paciasp  
//   0x539fe4: D106C3FF  sub      sp, sp, #0x1b0
//   0x539fe8: A9167BFD  stp      x29, x30, [sp, #0x160]
//   0x539fec: A91767FC  stp      x28, x25, [sp, #0x170]
//   0x539ff0: A9185FF8  stp      x24, x23, [sp, #0x180]
//   0x539ff4: A91957F6  stp      x22, x21, [sp, #0x190]
uint64_t fde_func_17756_0x539fe0(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00539FE0ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD106C3FFULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9167BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA91767FCULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9185FF8ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA91957F6ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA91A4FF4ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910583FDULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #17766 | PC: 0x53c96c..0x53ca3c (208 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x53c96c: D503233F  paciasp  
//   0x53c970: A9BD7BFD  stp      x29, x30, [sp, #-0x30]!
//   0x53c974: F9000BF5  str      x21, [sp, #0x10]
//   0x53c978: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x53c97c: 910003FD  mov      x29, sp
//   0x53c980: AA0103F5  mov      x21, x1
uint64_t fde_func_17766_0x53c96c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0053C96CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BD7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF5ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9024FF4ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0103F5ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F4ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400821ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #17775 | PC: 0x53dedc..0x53dfdc (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x53dedc: D503233F  paciasp  
//   0x53dee0: D10143FF  sub      sp, sp, #0x50
//   0x53dee4: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x53dee8: F90013F7  str      x23, [sp, #0x20]
//   0x53deec: A90357F6  stp      x22, x21, [sp, #0x30]
//   0x53def0: A9044FF4  stp      x20, x19, [sp, #0x40]
uint64_t fde_func_17775_0x53dedc(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0053DEDCULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10143FFULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF90013F7ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90357F6ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9044FF4ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0303F3ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #17785 | PC: 0x540ba8..0x540c78 (208 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x540ba8: D503233F  paciasp  
//   0x540bac: D10103FF  sub      sp, sp, #0x40
//   0x540bb0: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x540bb4: F90013F5  str      x21, [sp, #0x20]
//   0x540bb8: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x540bbc: 910043FD  add      x29, sp, #0x10
uint64_t fde_func_17785_0x540ba8(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00540BA8ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10103FFULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF90013F5ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9034FF4ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0103F5ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0303E1ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #17794 | PC: 0x542ccc..0x542dcc (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x542ccc: D503233F  paciasp  
//   0x542cd0: D10303FF  sub      sp, sp, #0xc0
//   0x542cd4: A9067BFD  stp      x29, x30, [sp, #0x60]
//   0x542cd8: F9003BFB  str      x27, [sp, #0x70]
//   0x542cdc: A90867FA  stp      x26, x25, [sp, #0x80]
//   0x542ce0: A9095FF8  stp      x24, x23, [sp, #0x90]
uint64_t fde_func_17794_0x542ccc(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00542CCCULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10303FFULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9067BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9003BFBULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90867FAULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9095FF8ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90A57F6ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90B4FF4ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #17804 | PC: 0x543e98..0x543f18 (128 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x543e98: D503233F  paciasp  
//   0x543e9c: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x543ea0: F9000BF3  str      x19, [sp, #0x10]
//   0x543ea4: 910003FD  mov      x29, sp
//   0x543ea8: AA0103E8  mov      x8, x1
//   0x543eac: F9400029  ldr      x9, [x1]
uint64_t fde_func_17804_0x543e98(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00543E98ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF3ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0103E8ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400029ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003E1ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #17813 | PC: 0x5442bc..0x54430c (80 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x5442bc: D503245F  bti      c
//   0x5442c0: D10083FF  sub      sp, sp, #0x20
//   0x5442c4: AA0003E8  mov      x8, x0
//   0x5442c8: AA1F03E9  mov      x9, xzr
//   0x5442cc: AA1F03E0  mov      x0, xzr
//   0x5442d0: 910003EA  mov      x10, sp
uint64_t fde_func_17813_0x5442bc(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x005442BCULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10083FFULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003E8ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA1F03E9ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA1F03E0ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003EAULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x3D8003E0ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BE8ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #17823 | PC: 0x544868..0x5448b0 (72 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x544868: D503233F  paciasp  
//   0x54486c: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x544870: F9000BF3  str      x19, [sp, #0x10]
//   0x544874: 910003FD  mov      x29, sp
//   0x544878: AA0003F3  mov      x19, x0
//   0x54487c: 9400005F  bl       #0x5449f8
uint64_t fde_func_17823_0x544868(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00544868ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF3ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9400005FULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x360000A0ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9401A68ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #17832 | PC: 0x544be0..0x544c00 (32 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x544be0: D503245F  bti      c
//   0x544be4: F9401828  ldr      x8, [x1, #0x30]
//   0x544be8: 9102A029  add      x9, x1, #0xa8
//   0x544bec: 9102E02A  add      x10, x1, #0xb8
//   0x544bf0: 39472108  ldrb     w8, [x8, #0x1c8]
//   0x544bf4: 7100011F  cmp      w8, #0
uint64_t fde_func_17832_0x544be0(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00544BE0ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9401828ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9102A029ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9102E02AULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x39472108ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x7100011FULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9A890141ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x17FFB6F7ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #17842 | PC: 0x545488..0x5454f4 (108 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x545488: D503233F  paciasp  
//   0x54548c: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x545490: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x545494: 910003FD  mov      x29, sp
//   0x545498: AA0103F4  mov      x20, x1
//   0x54549c: AA0003F3  mov      x19, x0
uint64_t fde_func_17842_0x545488(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00545488ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9014FF4ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0103F4ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x97FFA173ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9401288ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #17852 | PC: 0x546a48..0x546b48 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x546a48: D503233F  paciasp  
//   0x546a4c: D10783FF  sub      sp, sp, #0x1e0
//   0x546a50: A91A7BFD  stp      x29, x30, [sp, #0x1a0]
//   0x546a54: F900DBFC  str      x28, [sp, #0x1b0]
//   0x546a58: A91C57F6  stp      x22, x21, [sp, #0x1c0]
//   0x546a5c: A91D4FF4  stp      x20, x19, [sp, #0x1d0]
uint64_t fde_func_17852_0x546a48(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00546A48ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10783FFULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA91A7BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF900DBFCULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA91C57F6ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA91D4FF4ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910683FDULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD53BD055ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #17861 | PC: 0x5478b8..0x5479b8 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x5478b8: D503233F  paciasp  
//   0x5478bc: D10183FF  sub      sp, sp, #0x60
//   0x5478c0: A9037BFD  stp      x29, x30, [sp, #0x30]
//   0x5478c4: F90023F5  str      x21, [sp, #0x40]
//   0x5478c8: A9054FF4  stp      x20, x19, [sp, #0x50]
//   0x5478cc: 9100C3FD  add      x29, sp, #0x30
uint64_t fde_func_17861_0x5478b8(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x005478B8ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10183FFULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9037BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF90023F5ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9054FF4ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9100C3FDULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD53BD055ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF94016A8ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #17871 | PC: 0x547ddc..0x547edc (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x547ddc: D503233F  paciasp  
//   0x547de0: D10643FF  sub      sp, sp, #0x190
//   0x547de4: A9147BFD  stp      x29, x30, [sp, #0x140]
//   0x547de8: F900ABFC  str      x28, [sp, #0x150]
//   0x547dec: A9165FF8  stp      x24, x23, [sp, #0x160]
//   0x547df0: A91757F6  stp      x22, x21, [sp, #0x170]
uint64_t fde_func_17871_0x547ddc(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00547DDCULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10643FFULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9147BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF900ABFCULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9165FF8ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA91757F6ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9184FF4ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910503FDULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #17880 | PC: 0x548c50..0x548d34 (228 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x548c50: D503233F  paciasp  
//   0x548c54: D10603FF  sub      sp, sp, #0x180
//   0x548c58: A9147BFD  stp      x29, x30, [sp, #0x140]
//   0x548c5c: F900ABFC  str      x28, [sp, #0x150]
//   0x548c60: A91657F6  stp      x22, x21, [sp, #0x160]
//   0x548c64: A9174FF4  stp      x20, x19, [sp, #0x170]
uint64_t fde_func_17880_0x548c50(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00548C50ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10603FFULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9147BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF900ABFCULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA91657F6ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9174FF4ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910503FDULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD53BD055ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #17890 | PC: 0x5490f8..0x54914c (84 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x5490f8: D503245F  bti      c
//   0x5490fc: 52800028  mov      w8, #1
//   0x549100: 52800049  mov      w9, #2
//   0x549104: 5280008A  mov      w10, #4
//   0x549108: 3900001F  strb     wzr, [x0]
//   0x54910c: 3900601F  strb     wzr, [x0, #0x18]
uint64_t fde_func_17890_0x5490f8(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x005490F8ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x52800028ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x52800049ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x5280008AULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x3900001FULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x3900601FULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x39004008ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x92800008ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #17899 | PC: 0x5495b0..0x5495f8 (72 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x5495b0: D503233F  paciasp  
//   0x5495b4: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x5495b8: F9000BF3  str      x19, [sp, #0x10]
//   0x5495bc: 910003FD  mov      x29, sp
//   0x5495c0: AA0003F3  mov      x19, x0
//   0x5495c4: 39411008  ldrb     w8, [x0, #0x44]
uint64_t fde_func_17899_0x5495b0(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x005495B0ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF3ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x39411008ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x90000349ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x912F4129ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #17909 | PC: 0x549b7c..0x549c40 (196 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x549b7c: D503233F  paciasp  
//   0x549b80: A9BC7BFD  stp      x29, x30, [sp, #-0x40]!
//   0x549b84: A9015FF8  stp      x24, x23, [sp, #0x10]
//   0x549b88: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x549b8c: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x549b90: 910003FD  mov      x29, sp
uint64_t fde_func_17909_0x549b7c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00549B7CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BC7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9015FF8ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90257F6ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9034FF4ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F8ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #17918 | PC: 0x54a1f8..0x54a238 (64 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x54a1f8: D503233F  paciasp  
//   0x54a1fc: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x54a200: 910003FD  mov      x29, sp
//   0x54a204: F9401808  ldr      x8, [x0, #0x30]
//   0x54a208: B100051F  cmn      x8, #1
//   0x54a20c: FA411100  ccmp     x8, x1, #0, ne
uint64_t fde_func_17918_0x54a1f8(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0054A1F8ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BF7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9401808ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB100051FULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xFA411100ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x54000068ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x2A1F03E8ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #17928 | PC: 0x54b13c..0x54b23c (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x54b13c: D503233F  paciasp  
//   0x54b140: A9BC7BFD  stp      x29, x30, [sp, #-0x40]!
//   0x54b144: F9000BF7  str      x23, [sp, #0x10]
//   0x54b148: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x54b14c: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x54b150: 910003FD  mov      x29, sp
uint64_t fde_func_17928_0x54b13c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0054B13CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BC7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF7ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90257F6ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9034FF4ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0103F4ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #17937 | PC: 0x54c690..0x54c6f8 (104 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x54c690: D503233F  paciasp  
//   0x54c694: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x54c698: F9000BF3  str      x19, [sp, #0x10]
//   0x54c69c: 910003FD  mov      x29, sp
//   0x54c6a0: AA0003F3  mov      x19, x0
//   0x54c6a4: 395AA008  ldrb     w8, [x0, #0x6a8]
uint64_t fde_func_17937_0x54c690(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0054C690ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF3ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x395AA008ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x34000188ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF941F260ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #17947 | PC: 0x54ce00..0x54ce58 (88 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x54ce00: D503233F  paciasp  
//   0x54ce04: D10103FF  sub      sp, sp, #0x40
//   0x54ce08: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x54ce0c: F9001BF3  str      x19, [sp, #0x30]
//   0x54ce10: 910083FD  add      x29, sp, #0x20
//   0x54ce14: AA0003F3  mov      x19, x0
uint64_t fde_func_17947_0x54ce00(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0054CE00ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10103FFULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9027BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9001BF3ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910083FDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB0FFDD21ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91360021ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #17956 | PC: 0x54d304..0x54d404 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x54d304: D503233F  paciasp  
//   0x54d308: D10403FF  sub      sp, sp, #0x100
//   0x54d30c: A90B7BFD  stp      x29, x30, [sp, #0xb0]
//   0x54d310: A90C67FA  stp      x26, x25, [sp, #0xc0]
//   0x54d314: A90D5FF8  stp      x24, x23, [sp, #0xd0]
//   0x54d318: A90E57F6  stp      x22, x21, [sp, #0xe0]
uint64_t fde_func_17956_0x54d304(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0054D304ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10403FFULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90B7BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90C67FAULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90D5FF8ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90E57F6ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90F4FF4ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9102C3FDULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #17966 | PC: 0x54df8c..0x54dfc4 (56 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x54df8c: D503245F  bti      c
//   0x54df90: 5283D649  mov      w9, #0x1eb2
//   0x54df94: F9405008  ldr      x8, [x0, #0xa0]
//   0x54df98: 38696909  ldrb     w9, [x8, x9]
//   0x54df9c: 34000129  cbz      w9, #0x54dfc0
//   0x54dfa0: F9405800  ldr      x0, [x0, #0xb0]
uint64_t fde_func_17966_0x54df8c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0054DF8CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x5283D649ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9405008ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x38696909ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x34000129ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9405800ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB40000E0ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91002109ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #17975 | PC: 0x54ea44..0x54eaf4 (176 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x54ea44: D503233F  paciasp  
//   0x54ea48: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x54ea4c: F9000BF3  str      x19, [sp, #0x10]
//   0x54ea50: 910003FD  mov      x29, sp
//   0x54ea54: F9405008  ldr      x8, [x0, #0xa0]
//   0x54ea58: AA0003F3  mov      x19, x0
uint64_t fde_func_17975_0x54ea44(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0054EA44ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF3ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9405008ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB9444D08ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x7100BD1FULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #17985 | PC: 0x54f050..0x54f150 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x54f050: D503233F  paciasp  
//   0x54f054: D10283FF  sub      sp, sp, #0xa0
//   0x54f058: A9067BFD  stp      x29, x30, [sp, #0x60]
//   0x54f05c: A9075FF8  stp      x24, x23, [sp, #0x70]
//   0x54f060: A90857F6  stp      x22, x21, [sp, #0x80]
//   0x54f064: A9094FF4  stp      x20, x19, [sp, #0x90]
uint64_t fde_func_17985_0x54f050(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0054F050ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10283FFULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9067BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9075FF8ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90857F6ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9094FF4ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910183FDULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD53BD058ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #17994 | PC: 0x54ff68..0x550068 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x54ff68: D503233F  paciasp  
//   0x54ff6c: A9BD7BFD  stp      x29, x30, [sp, #-0x30]!
//   0x54ff70: F9000BF5  str      x21, [sp, #0x10]
//   0x54ff74: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x54ff78: 910003FD  mov      x29, sp
//   0x54ff7c: 39400028  ldrb     w8, [x1]
uint64_t fde_func_17994_0x54ff68(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0054FF68ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BD7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF5ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9024FF4ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x39400028ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x71004D1FULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x540007A0ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #18004 | PC: 0x55069c..0x5506a8 (12 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x55069c: D503245F  bti      c
//   0x5506a0: 912C0000  add      x0, x0, #0xb00
//   0x5506a4: 17FF909D  b        #0x534918
uint64_t fde_func_18004_0x55069c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0055069CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x912C0000ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x17FF909DULL ^ (2ULL << 32);
    return state ^ (state >> 29);
}

// FDE #18013 | PC: 0x551b54..0x551b74 (32 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x551b54: D503245F  bti      c
//   0x551b58: F9405008  ldr      x8, [x0, #0xa0]
//   0x551b5c: B9444D09  ldr      w9, [x8, #0x44c]
//   0x551b60: 7100BD3F  cmp      w9, #0x2f
//   0x551b64: 5400006B  b.lt     #0x551b70
//   0x551b68: 910BA100  add      x0, x8, #0x2e8
uint64_t fde_func_18013_0x551b54(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00551B54ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9405008ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB9444D09ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x7100BD3FULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x5400006BULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910BA100ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x17FFC707ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD65F03C0ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #18023 | PC: 0x552708..0x552714 (12 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x552708: D503245F  bti      c
//   0x55270c: 9102E000  add      x0, x0, #0xb8
//   0x552710: 14003513  b        #0x55fb5c
uint64_t fde_func_18023_0x552708(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00552708ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9102E000ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x14003513ULL ^ (2ULL << 32);
    return state ^ (state >> 29);
}

// FDE #18032 | PC: 0x552e18..0x552eac (148 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x552e18: D503233F  paciasp  
//   0x552e1c: D10143FF  sub      sp, sp, #0x50
//   0x552e20: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x552e24: A90357F6  stp      x22, x21, [sp, #0x30]
//   0x552e28: A9044FF4  stp      x20, x19, [sp, #0x40]
//   0x552e2c: 910083FD  add      x29, sp, #0x20
uint64_t fde_func_18032_0x552e18(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00552E18ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10143FFULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9027BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90357F6ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9044FF4ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910083FDULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x5283D649ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9405008ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #18042 | PC: 0x553770..0x55377c (12 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x553770: D503245F  bti      c
//   0x553774: D1002000  sub      x0, x0, #8
//   0x553778: 17FFEF77  b        #0x54f554
uint64_t fde_func_18042_0x553770(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00553770ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD1002000ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x17FFEF77ULL ^ (2ULL << 32);
    return state ^ (state >> 29);
}

// FDE #18051 | PC: 0x5537dc..0x5537e8 (12 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x5537dc: D503245F  bti      c
//   0x5537e0: D1004000  sub      x0, x0, #0x10
//   0x5537e4: 17FFEF1F  b        #0x54f460
uint64_t fde_func_18051_0x5537dc(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x005537DCULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD1004000ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x17FFEF1FULL ^ (2ULL << 32);
    return state ^ (state >> 29);
}

// FDE #18061 | PC: 0x553854..0x553860 (12 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x553854: D503245F  bti      c
//   0x553858: D1008000  sub      x0, x0, #0x20
//   0x55385c: 17FFF92D  b        #0x551d10
uint64_t fde_func_18061_0x553854(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00553854ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD1008000ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x17FFF92DULL ^ (2ULL << 32);
    return state ^ (state >> 29);
}

// FDE #18070 | PC: 0x5538e4..0x5538f4 (16 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x5538e4: D503245F  bti      c
//   0x5538e8: F9403C00  ldr      x0, [x0, #0x78]
//   0x5538ec: 52800044  mov      w4, #2
//   0x5538f0: 17FF55BA  b        #0x528fd8
uint64_t fde_func_18070_0x5538e4(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x005538E4ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9403C00ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x52800044ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x17FF55BAULL ^ (3ULL << 32);
    return state ^ (state >> 29);
}

// FDE #18080 | PC: 0x553964..0x553970 (12 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x553964: D503245F  bti      c
//   0x553968: D100C000  sub      x0, x0, #0x30
//   0x55396c: 17FFFD5C  b        #0x552edc
uint64_t fde_func_18080_0x553964(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00553964ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD100C000ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x17FFFD5CULL ^ (2ULL << 32);
    return state ^ (state >> 29);
}

// FDE #18089 | PC: 0x553fe4..0x5540e4 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x553fe4: D503233F  paciasp  
//   0x553fe8: A9BD7BFD  stp      x29, x30, [sp, #-0x30]!
//   0x553fec: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x553ff0: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x553ff4: 910003FD  mov      x29, sp
//   0x553ff8: F9405008  ldr      x8, [x0, #0xa0]
uint64_t fde_func_18089_0x553fe4(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00553FE4ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BD7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90157F6ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9024FF4ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9405008ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x2A0103F4ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #18099 | PC: 0x554888..0x554988 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x554888: D503233F  paciasp  
//   0x55488c: D10203FF  sub      sp, sp, #0x80
//   0x554890: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x554894: F9001BFB  str      x27, [sp, #0x30]
//   0x554898: A90467FA  stp      x26, x25, [sp, #0x40]
//   0x55489c: A9055FF8  stp      x24, x23, [sp, #0x50]
uint64_t fde_func_18099_0x554888(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00554888ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10203FFULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9027BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9001BFBULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90467FAULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9055FF8ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90657F6ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9074FF4ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #18108 | PC: 0x554e00..0x554e20 (32 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x554e00: D503245F  bti      c
//   0x554e04: AA0103E8  mov      x8, x1
//   0x554e08: D00002E9  adrp     x9, #0x5b2000
//   0x554e0c: 910D0129  add      x9, x9, #0x340
//   0x554e10: 91002001  add      x1, x0, #8
//   0x554e14: F8008509  str      x9, [x8], #8
uint64_t fde_func_18108_0x554e00(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00554E00ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0103E8ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD00002E9ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910D0129ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91002001ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF8008509ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0803E0ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x1400005BULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #18118 | PC: 0x5551c0..0x5552c0 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x5551c0: D503233F  paciasp  
//   0x5551c4: A9BD7BFD  stp      x29, x30, [sp, #-0x30]!
//   0x5551c8: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x5551cc: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x5551d0: 910003FD  mov      x29, sp
//   0x5551d4: 39722808  ldrb     w8, [x0, #0xc8a]
uint64_t fde_func_18118_0x5551c0(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x005551C0ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BD7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90157F6ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9024FF4ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x39722808ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x34000108ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x2A1F03F5ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #18127 | PC: 0x55580c..0x5558c4 (184 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x55580c: D503233F  paciasp  
//   0x555810: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x555814: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x555818: 910003FD  mov      x29, sp
//   0x55581c: F9405008  ldr      x8, [x0, #0xa0]
//   0x555820: AA0003F3  mov      x19, x0
uint64_t fde_func_18127_0x55580c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0055580CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9014FF4ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9405008ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB9444909ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB9444D14ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #18137 | PC: 0x555bac..0x555c18 (108 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x555bac: D503245F  bti      c
//   0x555bb0: B00002E8  adrp     x8, #0x5b2000
//   0x555bb4: 91150108  add      x8, x8, #0x540
//   0x555bb8: F9000008  str      x8, [x0]
//   0x555bbc: F9400428  ldr      x8, [x1, #8]
//   0x555bc0: F9000408  str      x8, [x0, #8]
uint64_t fde_func_18137_0x555bac(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00555BACULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB00002E8ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91150108ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000008ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400428ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000408ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAD408021ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAD008001ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #18147 | PC: 0x55620c..0x55625c (80 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x55620c: D503245F  bti      c
//   0x556210: F9405C09  ldr      x9, [x0, #0xb8]
//   0x556214: B4000169  cbz      x9, #0x556240
//   0x556218: F9403928  ldr      x8, [x9, #0x70]
//   0x55621c: B4000128  cbz      x8, #0x556240
//   0x556220: F945152A  ldr      x10, [x9, #0xa28]
uint64_t fde_func_18147_0x55620c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0055620CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9405C09ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB4000169ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9403928ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB4000128ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF945152AULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9451D2BULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF945212CULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #18156 | PC: 0x556cb4..0x556cfc (72 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x556cb4: D503233F  paciasp  
//   0x556cb8: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x556cbc: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x556cc0: 910003FD  mov      x29, sp
//   0x556cc4: 2A0303F4  mov      w20, w3
//   0x556cc8: AA0003F3  mov      x19, x0
uint64_t fde_func_18156_0x556cb4(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00556CB4ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9014FF4ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x2A0303F4ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB4000062ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91068260ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #18166 | PC: 0x5572e4..0x5573d4 (240 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x5572e4: D503233F  paciasp  
//   0x5572e8: D10603FF  sub      sp, sp, #0x180
//   0x5572ec: A9147BFD  stp      x29, x30, [sp, #0x140]
//   0x5572f0: F900ABFC  str      x28, [sp, #0x150]
//   0x5572f4: A91657F6  stp      x22, x21, [sp, #0x160]
//   0x5572f8: A9174FF4  stp      x20, x19, [sp, #0x170]
uint64_t fde_func_18166_0x5572e4(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x005572E4ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10603FFULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9147BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF900ABFCULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA91657F6ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9174FF4ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910503FDULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD53BD056ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #18175 | PC: 0x557bd4..0x557c24 (80 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x557bd4: D503233F  paciasp  
//   0x557bd8: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x557bdc: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x557be0: 910003FD  mov      x29, sp
//   0x557be4: 3DC00020  ldr      q0, [x1]
//   0x557be8: AA0103F3  mov      x19, x1
uint64_t fde_func_18175_0x557bd4(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00557BD4ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9014FF4ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x3DC00020ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0103F3ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400008ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F4ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #18185 | PC: 0x558908..0x5589f4 (236 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x558908: D503233F  paciasp  
//   0x55890c: D10603FF  sub      sp, sp, #0x180
//   0x558910: A9147BFD  stp      x29, x30, [sp, #0x140]
//   0x558914: F900ABFC  str      x28, [sp, #0x150]
//   0x558918: A91657F6  stp      x22, x21, [sp, #0x160]
//   0x55891c: A9174FF4  stp      x20, x19, [sp, #0x170]
uint64_t fde_func_18185_0x558908(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00558908ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10603FFULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9147BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF900ABFCULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA91657F6ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9174FF4ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910503FDULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD53BD054ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #18194 | PC: 0x5593cc..0x5594cc (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x5593cc: D503233F  paciasp  
//   0x5593d0: D101C3FF  sub      sp, sp, #0x70
//   0x5593d4: A9037BFD  stp      x29, x30, [sp, #0x30]
//   0x5593d8: A9045FF8  stp      x24, x23, [sp, #0x40]
//   0x5593dc: A90557F6  stp      x22, x21, [sp, #0x50]
//   0x5593e0: A9064FF4  stp      x20, x19, [sp, #0x60]
uint64_t fde_func_18194_0x5593cc(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x005593CCULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD101C3FFULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9037BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9045FF8ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90557F6ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9064FF4ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9100C3FDULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF900007FULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #18204 | PC: 0x559e58..0x559f54 (252 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x559e58: D503233F  paciasp  
//   0x559e5c: D10603FF  sub      sp, sp, #0x180
//   0x559e60: A9157BFD  stp      x29, x30, [sp, #0x150]
//   0x559e64: A91657FC  stp      x28, x21, [sp, #0x160]
//   0x559e68: A9174FF4  stp      x20, x19, [sp, #0x170]
//   0x559e6c: 910543FD  add      x29, sp, #0x150
uint64_t fde_func_18204_0x559e58(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00559E58ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10603FFULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9157BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA91657FCULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9174FF4ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910543FDULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD53BD055ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #18213 | PC: 0x55ab10..0x55ac10 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x55ab10: D503233F  paciasp  
//   0x55ab14: D10703FF  sub      sp, sp, #0x1c0
//   0x55ab18: A9167BFD  stp      x29, x30, [sp, #0x160]
//   0x55ab1c: A9176FFC  stp      x28, x27, [sp, #0x170]
//   0x55ab20: A91867FA  stp      x26, x25, [sp, #0x180]
//   0x55ab24: A9195FF8  stp      x24, x23, [sp, #0x190]
uint64_t fde_func_18213_0x55ab10(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0055AB10ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10703FFULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9167BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9176FFCULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA91867FAULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9195FF8ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA91A57F6ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA91B4FF4ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #18223 | PC: 0x55b5f0..0x55b628 (56 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x55b5f0: D503233F  paciasp  
//   0x55b5f4: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x55b5f8: F9000BF3  str      x19, [sp, #0x10]
//   0x55b5fc: 910003FD  mov      x29, sp
//   0x55b600: AA0003F3  mov      x19, x0
//   0x55b604: F9401800  ldr      x0, [x0, #0x30]
uint64_t fde_func_18223_0x55b5f0(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0055B5F0ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF3ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9401800ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9401E61ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x94000065ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #18232 | PC: 0x55badc..0x55bb0c (48 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x55badc: D503233F  paciasp  
//   0x55bae0: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x55bae4: F9000BF3  str      x19, [sp, #0x10]
//   0x55bae8: 910003FD  mov      x29, sp
//   0x55baec: AA0103F3  mov      x19, x1
//   0x55baf0: 97FE7AEF  bl       #0x4fa6ac
uint64_t fde_func_18232_0x55badc(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0055BADCULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF3ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0103F3ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x97FE7AEFULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xEB13001FULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400BF3ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #18242 | PC: 0x55c7b8..0x55c8b8 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x55c7b8: D503233F  paciasp  
//   0x55c7bc: D10343FF  sub      sp, sp, #0xd0
//   0x55c7c0: A90A7BFD  stp      x29, x30, [sp, #0xa0]
//   0x55c7c4: F9005BF5  str      x21, [sp, #0xb0]
//   0x55c7c8: A90C4FF4  stp      x20, x19, [sp, #0xc0]
//   0x55c7cc: 910283FD  add      x29, sp, #0xa0
uint64_t fde_func_18242_0x55c7b8(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0055C7B8ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10343FFULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90A7BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9005BF5ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90C4FF4ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910283FDULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD53BD055ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #18251 | PC: 0x55cddc..0x55ce48 (108 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x55cddc: D503245F  bti      c
//   0x55cde0: 3940B448  ldrb     w8, [x2, #0x2d]
//   0x55cde4: 51001109  sub      w9, w8, #4
//   0x55cde8: 3100113F  cmn      w9, #4
//   0x55cdec: 540000E8  b.hi     #0x55ce08
//   0x55cdf0: F9401809  ldr      x9, [x0, #0x30]
uint64_t fde_func_18251_0x55cddc(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0055CDDCULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x3940B448ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x51001109ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x3100113FULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x540000E8ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9401809ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB100053FULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xFA411120ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #18261 | PC: 0x55d36c..0x55d424 (184 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x55d36c: D503233F  paciasp  
//   0x55d370: D105C3FF  sub      sp, sp, #0x170
//   0x55d374: A9147BFD  stp      x29, x30, [sp, #0x140]
//   0x55d378: A91557FC  stp      x28, x21, [sp, #0x150]
//   0x55d37c: A9164FF4  stp      x20, x19, [sp, #0x160]
//   0x55d380: 910503FD  add      x29, sp, #0x140
uint64_t fde_func_18261_0x55d36c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0055D36CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD105C3FFULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9147BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA91557FCULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9164FF4ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910503FDULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD53BD054ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x2A0103F3ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #18270 | PC: 0x55d884..0x55d8bc (56 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x55d884: D503245F  bti      c
//   0x55d888: 12001C28  and      w8, w1, #0xff
//   0x55d88c: 52800049  mov      w9, #2
//   0x55d890: 7100051F  cmp      w8, #1
//   0x55d894: 5280002A  mov      w10, #1
//   0x55d898: 1A891529  cinc     w9, w9, eq
uint64_t fde_func_18270_0x55d884(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0055D884ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x12001C28ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x52800049ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x7100051FULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x5280002AULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x1A891529ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x1A8A054AULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x7100BC1FULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #18280 | PC: 0x55db6c..0x55dc0c (160 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x55db6c: D503233F  paciasp  
//   0x55db70: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x55db74: F9000BF3  str      x19, [sp, #0x10]
//   0x55db78: 910003FD  mov      x29, sp
//   0x55db7c: AA0003F3  mov      x19, x0
//   0x55db80: 7100083F  cmp      w1, #2
uint64_t fde_func_18280_0x55db6c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0055DB6CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF3ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x7100083FULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x54000180ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x35000041ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #18289 | PC: 0x55e488..0x55e544 (188 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x55e488: D503233F  paciasp  
//   0x55e48c: D10183FF  sub      sp, sp, #0x60
//   0x55e490: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x55e494: F9001BF7  str      x23, [sp, #0x30]
//   0x55e498: A90457F6  stp      x22, x21, [sp, #0x40]
//   0x55e49c: A9054FF4  stp      x20, x19, [sp, #0x50]
uint64_t fde_func_18289_0x55e488(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0055E488ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10183FFULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9027BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9001BF7ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90457F6ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9054FF4ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910083FDULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0303F4ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #18299 | PC: 0x55edc4..0x55eec4 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x55edc4: D503233F  paciasp  
//   0x55edc8: D10603FF  sub      sp, sp, #0x180
//   0x55edcc: A9147BFD  stp      x29, x30, [sp, #0x140]
//   0x55edd0: A9155FFC  stp      x28, x23, [sp, #0x150]
//   0x55edd4: A91657F6  stp      x22, x21, [sp, #0x160]
//   0x55edd8: A9174FF4  stp      x20, x19, [sp, #0x170]
uint64_t fde_func_18299_0x55edc4(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0055EDC4ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10603FFULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9147BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9155FFCULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA91657F6ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9174FF4ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910503FDULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD53BD057ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #18308 | PC: 0x55f448..0x55f510 (200 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x55f448: D503233F  paciasp  
//   0x55f44c: D10303FF  sub      sp, sp, #0xc0
//   0x55f450: A9097BFD  stp      x29, x30, [sp, #0x90]
//   0x55f454: F90053F5  str      x21, [sp, #0xa0]
//   0x55f458: A90B4FF4  stp      x20, x19, [sp, #0xb0]
//   0x55f45c: 910243FD  add      x29, sp, #0x90
uint64_t fde_func_18308_0x55f448(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0055F448ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10303FFULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9097BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF90053F5ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90B4FF4ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910243FDULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD53BD055ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #18318 | PC: 0x55fc78..0x55fd68 (240 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x55fc78: D503245F  bti      c
//   0x55fc7c: 36000282  tbz      w2, #0, #0x55fccc
//   0x55fc80: 9107E008  add      x8, x0, #0x1f8
//   0x55fc84: F940F80C  ldr      x12, [x0, #0x1f0]
//   0x55fc88: AA0803EB  mov      x11, x8
//   0x55fc8c: 3600004C  tbz      w12, #0, #0x55fc94
uint64_t fde_func_18318_0x55fc78(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0055FC78ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x36000282ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9107E008ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF940F80CULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0803EBULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x3600004CULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF940010BULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD341FD89ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #18327 | PC: 0x5608c0..0x5609c0 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x5608c0: D503233F  paciasp  
//   0x5608c4: D10603FF  sub      sp, sp, #0x180
//   0x5608c8: A9157BFD  stp      x29, x30, [sp, #0x150]
//   0x5608cc: A91657FC  stp      x28, x21, [sp, #0x160]
//   0x5608d0: A9174FF4  stp      x20, x19, [sp, #0x170]
//   0x5608d4: 910543FD  add      x29, sp, #0x150
uint64_t fde_func_18327_0x5608c0(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x005608C0ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10603FFULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9157BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA91657FCULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9174FF4ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910543FDULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD53BD054ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #18337 | PC: 0x561900..0x561908 (8 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x561900: D503245F  bti      c
//   0x561904: 140005B3  b        #0x562fd0
uint64_t fde_func_18337_0x561900(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00561900ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x140005B3ULL ^ (1ULL << 32);
    return state ^ (state >> 29);
}

// FDE #18346 | PC: 0x5619a0..0x5619a8 (8 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x5619a0: D503245F  bti      c
//   0x5619a4: 1400013B  b        #0x561e90
uint64_t fde_func_18346_0x5619a0(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x005619A0ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x1400013BULL ^ (1ULL << 32);
    return state ^ (state >> 29);
}

// FDE #18356 | PC: 0x561d30..0x561d3c (12 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x561d30: D503245F  bti      c
//   0x561d34: D1036000  sub      x0, x0, #0xd8
//   0x561d38: 17FFF839  b        #0x55fe1c
uint64_t fde_func_18356_0x561d30(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00561D30ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD1036000ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x17FFF839ULL ^ (2ULL << 32);
    return state ^ (state >> 29);
}

// FDE #18365 | PC: 0x561dc4..0x561dd0 (12 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x561dc4: D503245F  bti      c
//   0x561dc8: D1034000  sub      x0, x0, #0xd0
//   0x561dcc: D65F03C0  ret      
uint64_t fde_func_18365_0x561dc4(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00561DC4ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD1034000ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD65F03C0ULL ^ (2ULL << 32);
    return state ^ (state >> 29);
}

// FDE #18375 | PC: 0x561e54..0x561e60 (12 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x561e54: D503245F  bti      c
//   0x561e58: D1036000  sub      x0, x0, #0xd8
//   0x561e5c: 1400045D  b        #0x562fd0
uint64_t fde_func_18375_0x561e54(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00561E54ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD1036000ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x1400045DULL ^ (2ULL << 32);
    return state ^ (state >> 29);
}

// FDE #18384 | PC: 0x561fbc..0x562040 (132 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x561fbc: D503233F  paciasp  
//   0x561fc0: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x561fc4: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x561fc8: 910003FD  mov      x29, sp
//   0x561fcc: F9400408  ldr      x8, [x0, #8]
//   0x561fd0: B4000308  cbz      x8, #0x562030
uint64_t fde_func_18384_0x561fbc(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00561FBCULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9014FF4ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400408ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB4000308ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x2A0103F4ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #18394 | PC: 0x562bc8..0x562bd4 (12 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x562bc8: D503245F  bti      c
//   0x562bcc: D1002000  sub      x0, x0, #8
//   0x562bd0: 17FFFEF7  b        #0x5627ac
uint64_t fde_func_18394_0x562bc8(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00562BC8ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD1002000ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x17FFFEF7ULL ^ (2ULL << 32);
    return state ^ (state >> 29);
}

// FDE #18403 | PC: 0x563080..0x563114 (148 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x563080: D503233F  paciasp  
//   0x563084: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x563088: F9000BF3  str      x19, [sp, #0x10]
//   0x56308c: 910003FD  mov      x29, sp
//   0x563090: 9101A008  add      x8, x0, #0x68
//   0x563094: 91002009  add      x9, x0, #8
uint64_t fde_func_18403_0x563080(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00563080ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF3ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9101A008ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91002009ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x721F003FULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9A880133ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #18413 | PC: 0x563858..0x563958 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x563858: D503233F  paciasp  
//   0x56385c: D10603FF  sub      sp, sp, #0x180
//   0x563860: A9147BFD  stp      x29, x30, [sp, #0x140]
//   0x563864: F900ABFC  str      x28, [sp, #0x150]
//   0x563868: A91657F6  stp      x22, x21, [sp, #0x160]
//   0x56386c: A9174FF4  stp      x20, x19, [sp, #0x170]
uint64_t fde_func_18413_0x563858(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00563858ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10603FFULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9147BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF900ABFCULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA91657F6ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9174FF4ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910503FDULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD53BD055ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #18422 | PC: 0x563e64..0x563e90 (44 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x563e64: D503233F  paciasp  
//   0x563e68: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x563e6c: F9000BF3  str      x19, [sp, #0x10]
//   0x563e70: 910003FD  mov      x29, sp
//   0x563e74: AA0003F3  mov      x19, x0
//   0x563e78: 97FFFFF6  bl       #0x563e50
uint64_t fde_func_18422_0x563e64(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00563E64ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF3ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x97FFFFF6ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA1303E0ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400BF3ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #18432 | PC: 0x56499c..0x564a28 (140 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x56499c: D503233F  paciasp  
//   0x5649a0: A9BD7BFD  stp      x29, x30, [sp, #-0x30]!
//   0x5649a4: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x5649a8: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x5649ac: 910003FD  mov      x29, sp
//   0x5649b0: 9102A015  add      x21, x0, #0xa8
uint64_t fde_func_18432_0x56499c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0056499CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BD7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90157F6ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9024FF4ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9102A015ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x2A0203F6ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0103F4ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #18442 | PC: 0x565074..0x565174 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x565074: D503233F  paciasp  
//   0x565078: D10543FF  sub      sp, sp, #0x150
//   0x56507c: A90F7BFD  stp      x29, x30, [sp, #0xf0]
//   0x565080: A9106FFC  stp      x28, x27, [sp, #0x100]
//   0x565084: A91167FA  stp      x26, x25, [sp, #0x110]
//   0x565088: A9125FF8  stp      x24, x23, [sp, #0x120]
uint64_t fde_func_18442_0x565074(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00565074ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10543FFULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90F7BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9106FFCULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA91167FAULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9125FF8ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA91357F6ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9144FF4ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #18451 | PC: 0x565a60..0x565b60 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x565a60: D503233F  paciasp  
//   0x565a64: A9BC7BFD  stp      x29, x30, [sp, #-0x40]!
//   0x565a68: A9015FFC  stp      x28, x23, [sp, #0x10]
//   0x565a6c: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x565a70: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x565a74: 910003FD  mov      x29, sp
uint64_t fde_func_18451_0x565a60(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00565A60ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BC7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9015FFCULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90257F6ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9034FF4ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD109C3FFULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD53BD056ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #18461 | PC: 0x5662d0..0x56632c (92 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x5662d0: D503233F  paciasp  
//   0x5662d4: D100C3FF  sub      sp, sp, #0x30
//   0x5662d8: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x5662dc: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x5662e0: 910043FD  add      x29, sp, #0x10
//   0x5662e4: AA0003F4  mov      x20, x0
uint64_t fde_func_18461_0x5662d0(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x005662D0ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD100C3FFULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9024FF4ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F4ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9404400ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x79400033ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #18470 | PC: 0x566634..0x566698 (100 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x566634: D503233F  paciasp  
//   0x566638: A9BD7BFD  stp      x29, x30, [sp, #-0x30]!
//   0x56663c: F9000BF5  str      x21, [sp, #0x10]
//   0x566640: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x566644: 910003FD  mov      x29, sp
//   0x566648: 2A0203F3  mov      w19, w2
uint64_t fde_func_18470_0x566634(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00566634ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BD7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF5ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9024FF4ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x2A0203F3ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0103F4ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F5ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #18480 | PC: 0x5669e0..0x5669ec (12 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x5669e0: D503245F  bti      c
//   0x5669e4: 39055C1F  strb     wzr, [x0, #0x157]
//   0x5669e8: D65F03C0  ret      
uint64_t fde_func_18480_0x5669e0(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x005669E0ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x39055C1FULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD65F03C0ULL ^ (2ULL << 32);
    return state ^ (state >> 29);
}

// FDE #18489 | PC: 0x5672f4..0x567310 (28 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x5672f4: D503245F  bti      c
//   0x5672f8: 39455008  ldrb     w8, [x0, #0x154]
//   0x5672fc: 34000048  cbz      w8, #0x567304
//   0x567300: D65F03C0  ret      
//   0x567304: AA1F03E1  mov      x1, xzr
//   0x567308: AA1F03E2  mov      x2, xzr
uint64_t fde_func_18489_0x5672f4(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x005672F4ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x39455008ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x34000048ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD65F03C0ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA1F03E1ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA1F03E2ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x17FFFA40ULL ^ (6ULL << 32);
    return state ^ (state >> 29);
}

// FDE #18499 | PC: 0x5684c4..0x56850c (72 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x5684c4: D503233F  paciasp  
//   0x5684c8: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x5684cc: 910003FD  mov      x29, sp
//   0x5684d0: F0FFDB22  adrp     x2, #0xcf000
//   0x5684d4: 910E5042  add      x2, x2, #0x394
//   0x5684d8: 528000C3  mov      w3, #6
uint64_t fde_func_18499_0x5684c4(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x005684C4ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BF7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF0FFDB22ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910E5042ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x528000C3ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x97F1E6E2ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x52800028ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #18508 | PC: 0x568dc4..0x568ec4 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x568dc4: D503233F  paciasp  
//   0x568dc8: D101C3FF  sub      sp, sp, #0x70
//   0x568dcc: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x568dd0: F9001BF9  str      x25, [sp, #0x30]
//   0x568dd4: A9045FF8  stp      x24, x23, [sp, #0x40]
//   0x568dd8: A90557F6  stp      x22, x21, [sp, #0x50]
uint64_t fde_func_18508_0x568dc4(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00568DC4ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD101C3FFULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9027BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9001BF9ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9045FF8ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90557F6ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9064FF4ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910083FDULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #18518 | PC: 0x569364..0x569448 (228 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x569364: D503233F  paciasp  
//   0x569368: D103C3FF  sub      sp, sp, #0xf0
//   0x56936c: A90B7BFD  stp      x29, x30, [sp, #0xb0]
//   0x569370: A90C5FF8  stp      x24, x23, [sp, #0xc0]
//   0x569374: A90D57F6  stp      x22, x21, [sp, #0xd0]
//   0x569378: A90E4FF4  stp      x20, x19, [sp, #0xe0]
uint64_t fde_func_18518_0x569364(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00569364ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD103C3FFULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90B7BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90C5FF8ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90D57F6ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90E4FF4ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9102C3FDULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0403F3ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #18527 | PC: 0x5698a8..0x5698d4 (44 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x5698a8: D503233F  paciasp  
//   0x5698ac: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x5698b0: F9000BF3  str      x19, [sp, #0x10]
//   0x5698b4: 910003FD  mov      x29, sp
//   0x5698b8: AA0003F3  mov      x19, x0
//   0x5698bc: 97F1822D  bl       #0x1ca170
uint64_t fde_func_18527_0x5698a8(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x005698A8ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF3ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x97F1822DULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA1303E1ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400BF3ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #18537 | PC: 0x56a500..0x56a574 (116 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x56a500: D503233F  paciasp  
//   0x56a504: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x56a508: F9000BF3  str      x19, [sp, #0x10]
//   0x56a50c: 910003FD  mov      x29, sp
//   0x56a510: D358FC28  lsr      x8, x1, #0x18
//   0x56a514: B40000C8  cbz      x8, #0x56a52c
uint64_t fde_func_18537_0x56a500(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0056A500ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF3ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD358FC28ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB40000C8ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x2A1F03E0ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400BF3ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #18546 | PC: 0x56a9ec..0x56a9f8 (12 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x56a9ec: D503245F  bti      c
//   0x56a9f0: AA1F03E1  mov      x1, xzr
//   0x56a9f4: 14000001  b        #0x56a9f8
uint64_t fde_func_18546_0x56a9ec(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0056A9ECULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA1F03E1ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x14000001ULL ^ (2ULL << 32);
    return state ^ (state >> 29);
}

// FDE #18556 | PC: 0x56b120..0x56b1d0 (176 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x56b120: D503233F  paciasp  
//   0x56b124: D10183FF  sub      sp, sp, #0x60
//   0x56b128: A9037BFD  stp      x29, x30, [sp, #0x30]
//   0x56b12c: F90023F5  str      x21, [sp, #0x40]
//   0x56b130: A9054FF4  stp      x20, x19, [sp, #0x50]
//   0x56b134: 9100C3FD  add      x29, sp, #0x30
uint64_t fde_func_18556_0x56b120(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0056B120ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10183FFULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9037BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF90023F5ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9054FF4ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9100C3FDULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F4ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x90000248ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #18565 | PC: 0x56b7b8..0x56b820 (104 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x56b7b8: D503233F  paciasp  
//   0x56b7bc: D10103FF  sub      sp, sp, #0x40
//   0x56b7c0: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x56b7c4: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x56b7c8: 910083FD  add      x29, sp, #0x20
//   0x56b7cc: D53BD054  mrs      x20, tpidr_el0
uint64_t fde_func_18565_0x56b7b8(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0056B7B8ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10103FFULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9027BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9034FF4ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910083FDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD53BD054ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9401688ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #18575 | PC: 0x56c51c..0x56c528 (12 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x56c51c: D503245F  bti      c
//   0x56c520: 91004000  add      x0, x0, #0x10
//   0x56c524: D65F03C0  ret      
uint64_t fde_func_18575_0x56c51c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0056C51CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91004000ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD65F03C0ULL ^ (2ULL << 32);
    return state ^ (state >> 29);
}

// FDE #18584 | PC: 0x56c9f8..0x56ca24 (44 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x56c9f8: D503245F  bti      c
//   0x56c9fc: 2A0103E8  mov      w8, w1
//   0x56ca00: AA0003E9  mov      x9, x0
//   0x56ca04: 91004000  add      x0, x0, #0x10
//   0x56ca08: AA0203E1  mov      x1, x2
//   0x56ca0c: B9000928  str      w8, [x9, #8]
uint64_t fde_func_18584_0x56c9f8(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0056C9F8ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x2A0103E8ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003E9ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91004000ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0203E1ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB9000928ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF0000228ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91070108ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #18594 | PC: 0x56cb14..0x56cb40 (44 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x56cb14: D503233F  paciasp  
//   0x56cb18: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x56cb1c: F9000BF3  str      x19, [sp, #0x10]
//   0x56cb20: 910003FD  mov      x29, sp
//   0x56cb24: AA0003F3  mov      x19, x0
//   0x56cb28: 97FFFFF6  bl       #0x56cb00
uint64_t fde_func_18594_0x56cb14(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0056CB14ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF3ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x97FFFFF6ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA1303E0ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400BF3ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #18603 | PC: 0x56cbf0..0x56cc04 (20 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x56cbf0: D503245F  bti      c
//   0x56cbf4: AA0003E8  mov      x8, x0
//   0x56cbf8: AA0103E0  mov      x0, x1
//   0x56cbfc: AA0803E1  mov      x1, x8
//   0x56cc00: 17FFFA32  b        #0x56b4c8
uint64_t fde_func_18603_0x56cbf0(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0056CBF0ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003E8ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0103E0ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0803E1ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x17FFFA32ULL ^ (4ULL << 32);
    return state ^ (state >> 29);
}

// FDE #18613 | PC: 0x56cd54..0x56cd80 (44 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x56cd54: D503233F  paciasp  
//   0x56cd58: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x56cd5c: F9000BF3  str      x19, [sp, #0x10]
//   0x56cd60: 910003FD  mov      x29, sp
//   0x56cd64: AA0003F3  mov      x19, x0
//   0x56cd68: 97FFFF2F  bl       #0x56ca24
uint64_t fde_func_18613_0x56cd54(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0056CD54ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF3ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x97FFFF2FULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA1303E0ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400BF3ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #18622 | PC: 0x56d7ac..0x56d80c (96 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x56d7ac: D503245F  bti      c
//   0x56d7b0: 7101FC1F  cmp      w0, #0x7f
//   0x56d7b4: 39000020  strb     w0, [x1]
//   0x56d7b8: 54000068  b.hi     #0x56d7c4
//   0x56d7bc: 91000420  add      x0, x1, #1
//   0x56d7c0: D65F03C0  ret      
uint64_t fde_func_18622_0x56d7ac(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0056D7ACULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x7101FC1FULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x39000020ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x54000068ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91000420ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD65F03C0ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x2A0003E8ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x3219000AULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #18632 | PC: 0x56dbc0..0x56dc4c (140 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x56dbc0: D503233F  paciasp  
//   0x56dbc4: D100C3FF  sub      sp, sp, #0x30
//   0x56dbc8: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x56dbcc: F90013F3  str      x19, [sp, #0x20]
//   0x56dbd0: 910043FD  add      x29, sp, #0x10
//   0x56dbd4: 39406008  ldrb     w8, [x0, #0x18]
uint64_t fde_func_18632_0x56dbc0(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0056DBC0ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD100C3FFULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF90013F3ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x39406008ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x34000308ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #18641 | PC: 0x56e598..0x56e698 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x56e598: D503233F  paciasp  
//   0x56e59c: D10303FF  sub      sp, sp, #0xc0
//   0x56e5a0: A9097BFD  stp      x29, x30, [sp, #0x90]
//   0x56e5a4: A90A57F6  stp      x22, x21, [sp, #0xa0]
//   0x56e5a8: A90B4FF4  stp      x20, x19, [sp, #0xb0]
//   0x56e5ac: 910243FD  add      x29, sp, #0x90
uint64_t fde_func_18641_0x56e598(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0056E598ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10303FFULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9097BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90A57F6ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90B4FF4ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910243FDULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x39406028ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F4ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #18651 | PC: 0x56e9a8..0x56ea14 (108 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x56e9a8: D503245F  bti      c
//   0x56e9ac: F9401C01  ldr      x1, [x0, #0x38]
//   0x56e9b0: D360FC22  lsr      x2, x1, #0x20
//   0x56e9b4: 71000848  subs     w8, w2, #2
//   0x56e9b8: 540002CB  b.lt     #0x56ea10
//   0x56e9bc: 39400009  ldrb     w9, [x0]
uint64_t fde_func_18651_0x56e9a8(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0056E9A8ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9401C01ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD360FC22ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x71000848ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x540002CBULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x39400009ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x93407C2AULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x37000069ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #18660 | PC: 0x56ee2c..0x56ee98 (108 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x56ee2c: D503233F  paciasp  
//   0x56ee30: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x56ee34: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x56ee38: 910003FD  mov      x29, sp
//   0x56ee3c: AA0103F4  mov      x20, x1
//   0x56ee40: AA0003F3  mov      x19, x0
uint64_t fde_func_18660_0x56ee2c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0056EE2CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9014FF4ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0103F4ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x97F29371ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x3940E288ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #18670 | PC: 0x56f2ac..0x56f3ac (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x56f2ac: D503233F  paciasp  
//   0x56f2b0: D10103FF  sub      sp, sp, #0x40
//   0x56f2b4: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x56f2b8: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x56f2bc: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x56f2c0: 910043FD  add      x29, sp, #0x10
uint64_t fde_func_18670_0x56f2ac(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0056F2ACULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10103FFULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90257F6ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9034FF4ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400408ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB4000168ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #18679 | PC: 0x56fb40..0x56fba0 (96 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x56fb40: D503245F  bti      c
//   0x56fb44: F9400028  ldr      x8, [x1]
//   0x56fb48: F9000008  str      x8, [x0]
//   0x56fb4c: F9400428  ldr      x8, [x1, #8]
//   0x56fb50: F9000408  str      x8, [x0, #8]
//   0x56fb54: F9400828  ldr      x8, [x1, #0x10]
uint64_t fde_func_18679_0x56fb40(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0056FB40ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400028ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000008ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400428ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000408ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400828ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000808ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400C28ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #18689 | PC: 0x5700b4..0x570188 (212 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x5700b4: D503245F  bti      c
//   0x5700b8: B9400428  ldr      w8, [x1, #4]
//   0x5700bc: 340005A8  cbz      w8, #0x570170
//   0x5700c0: B9800029  ldrsw    x9, [x1]
//   0x5700c4: AA1F03EB  mov      x11, xzr
//   0x5700c8: 8B09000C  add      x12, x0, x9
uint64_t fde_func_18689_0x5700b4(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x005700B4ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB9400428ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x340005A8ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB9800029ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA1F03EBULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x8B09000CULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x0B080128ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x93407D0EULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #18698 | PC: 0x570828..0x5708fc (212 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x570828: D503245F  bti      c
//   0x57082c: B9800428  ldrsw    x8, [x1, #4]
//   0x570830: 3100051F  cmn      w8, #1
//   0x570834: 54000240  b.eq     #0x57087c
//   0x570838: B980002A  ldrsw    x10, [x1]
//   0x57083c: 5100050B  sub      w11, w8, #1
uint64_t fde_func_18698_0x570828(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00570828ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB9800428ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x3100051FULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x54000240ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB980002AULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x5100050BULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x8B080149ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x12800008ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #18708 | PC: 0x570eac..0x570f78 (204 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x570eac: D503233F  paciasp  
//   0x570eb0: A9BD7BFD  stp      x29, x30, [sp, #-0x30]!
//   0x570eb4: F9000BF5  str      x21, [sp, #0x10]
//   0x570eb8: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x570ebc: 910003FD  mov      x29, sp
//   0x570ec0: AA0103F3  mov      x19, x1
uint64_t fde_func_18708_0x570eac(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00570EACULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BD7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF5ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9024FF4ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0103F3ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x2A0003F4ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x7101FC1FULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #18717 | PC: 0x571534..0x571560 (44 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x571534: D503233F  paciasp  
//   0x571538: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x57153c: F9000BF3  str      x19, [sp, #0x10]
//   0x571540: 910003FD  mov      x29, sp
//   0x571544: AA0003F3  mov      x19, x0
//   0x571548: 97FFFFEF  bl       #0x571504
uint64_t fde_func_18717_0x571534(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00571534ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF3ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x97FFFFEFULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA1303E0ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400BF3ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #18727 | PC: 0x571d28..0x571e28 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x571d28: D503233F  paciasp  
//   0x571d2c: A9BA7BFD  stp      x29, x30, [sp, #-0x60]!
//   0x571d30: A9016FFC  stp      x28, x27, [sp, #0x10]
//   0x571d34: A90267FA  stp      x26, x25, [sp, #0x20]
//   0x571d38: A9035FF8  stp      x24, x23, [sp, #0x30]
//   0x571d3c: A90457F6  stp      x22, x21, [sp, #0x40]
uint64_t fde_func_18727_0x571d28(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00571D28ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BA7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9016FFCULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90267FAULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9035FF8ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90457F6ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9054FF4ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #18737 | PC: 0x572984..0x572a58 (212 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x572984: D503233F  paciasp  
//   0x572988: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x57298c: F9000BF3  str      x19, [sp, #0x10]
//   0x572990: 910003FD  mov      x29, sp
//   0x572994: F9400029  ldr      x9, [x1]
//   0x572998: AA0003E8  mov      x8, x0
uint64_t fde_func_18737_0x572984(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00572984ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF3ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400029ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003E8ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0303F3ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x529B000AULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #18746 | PC: 0x57307c..0x57317c (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x57307c: D503233F  paciasp  
//   0x573080: D10283FF  sub      sp, sp, #0xa0
//   0x573084: A9087BFD  stp      x29, x30, [sp, #0x80]
//   0x573088: F9004BF3  str      x19, [sp, #0x90]
//   0x57308c: 910203FD  add      x29, sp, #0x80
//   0x573090: D53BD048  mrs      x8, tpidr_el0
uint64_t fde_func_18746_0x57307c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0057307CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10283FFULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9087BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9004BF3ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910203FDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD53BD048ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD360FC29ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF940150AULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #18756 | PC: 0x5742d0..0x5743d0 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x5742d0: D503233F  paciasp  
//   0x5742d4: A9BB7BFD  stp      x29, x30, [sp, #-0x50]!
//   0x5742d8: F9000BF9  str      x25, [sp, #0x10]
//   0x5742dc: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x5742e0: A90357F6  stp      x22, x21, [sp, #0x30]
//   0x5742e4: A9044FF4  stp      x20, x19, [sp, #0x40]
uint64_t fde_func_18756_0x5742d0(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x005742D0ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BB7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF9ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9025FF8ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90357F6ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9044FF4ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0303F3ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #18765 | PC: 0x574c38..0x574c74 (60 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x574c38: D503233F  paciasp  
//   0x574c3c: D10143FF  sub      sp, sp, #0x50
//   0x574c40: A9047BFD  stp      x29, x30, [sp, #0x40]
//   0x574c44: 910103FD  add      x29, sp, #0x40
//   0x574c48: A90003E0  stp      x0, x0, [sp]
//   0x574c4c: A90103E0  stp      x0, x0, [sp, #0x10]
uint64_t fde_func_18765_0x574c38(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00574C38ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10143FFULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9047BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910103FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90003E0ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90103E0ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90203E0ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90303E0ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #18775 | PC: 0x575d18..0x575dc8 (176 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x575d18: D503233F  paciasp  
//   0x575d1c: D10183FF  sub      sp, sp, #0x60
//   0x575d20: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x575d24: F90013F9  str      x25, [sp, #0x20]
//   0x575d28: A9035FF8  stp      x24, x23, [sp, #0x30]
//   0x575d2c: A90457F6  stp      x22, x21, [sp, #0x40]
uint64_t fde_func_18775_0x575d18(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00575D18ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10183FFULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF90013F9ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9035FF8ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90457F6ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9054FF4ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #18784 | PC: 0x576800..0x576900 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x576800: D503233F  paciasp  
//   0x576804: A9BA7BFD  stp      x29, x30, [sp, #-0x60]!
//   0x576808: A9016FFC  stp      x28, x27, [sp, #0x10]
//   0x57680c: A90267FA  stp      x26, x25, [sp, #0x20]
//   0x576810: A9035FF8  stp      x24, x23, [sp, #0x30]
//   0x576814: A90457F6  stp      x22, x21, [sp, #0x40]
uint64_t fde_func_18784_0x576800(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00576800ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BA7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9016FFCULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90267FAULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9035FF8ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90457F6ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9054FF4ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #18794 | PC: 0x577aec..0x577b44 (88 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x577aec: D503245F  bti      c
//   0x577af0: B9400808  ldr      w8, [x0, #8]
//   0x577af4: 7101011F  cmp      w8, #0x40
//   0x577af8: 54000201  b.ne     #0x577b38
//   0x577afc: F9400C08  ldr      x8, [x0, #0x18]
//   0x577b00: B40001E8  cbz      x8, #0x577b3c
uint64_t fde_func_18794_0x577aec(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00577AECULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB9400808ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x7101011FULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x54000201ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400C08ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB40001E8ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400009ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x5280070CULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #18803 | PC: 0x57988c..0x57998c (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x57988c: D503233F  paciasp  
//   0x579890: A9BA7BFD  stp      x29, x30, [sp, #-0x60]!
//   0x579894: F9000BFB  str      x27, [sp, #0x10]
//   0x579898: A90267FA  stp      x26, x25, [sp, #0x20]
//   0x57989c: A9035FF8  stp      x24, x23, [sp, #0x30]
//   0x5798a0: A90457F6  stp      x22, x21, [sp, #0x40]
uint64_t fde_func_18803_0x57988c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0057988CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BA7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BFBULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90267FAULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9035FF8ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90457F6ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9054FF4ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #18813 | PC: 0x57b75c..0x57b85c (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x57b75c: D503233F  paciasp  
//   0x57b760: D10183FF  sub      sp, sp, #0x60
//   0x57b764: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x57b768: A90267FA  stp      x26, x25, [sp, #0x20]
//   0x57b76c: A9035FF8  stp      x24, x23, [sp, #0x30]
//   0x57b770: A90457F6  stp      x22, x21, [sp, #0x40]
uint64_t fde_func_18813_0x57b75c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0057B75CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10183FFULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90267FAULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9035FF8ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90457F6ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9054FF4ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #18822 | PC: 0x57cb1c..0x57cc1c (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x57cb1c: D503233F  paciasp  
//   0x57cb20: A9BB7BFD  stp      x29, x30, [sp, #-0x50]!
//   0x57cb24: A90167FA  stp      x26, x25, [sp, #0x10]
//   0x57cb28: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x57cb2c: A90357F6  stp      x22, x21, [sp, #0x30]
//   0x57cb30: A9044FF4  stp      x20, x19, [sp, #0x40]
uint64_t fde_func_18822_0x57cb1c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0057CB1CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BB7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90167FAULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9025FF8ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90357F6ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9044FF4ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x2A0003F4ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #18832 | PC: 0x57dbac..0x57dcac (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x57dbac: D503245F  bti      c
//   0x57dbb0: 39C00009  ldrsb    w9, [x0]
//   0x57dbb4: 12001D28  and      w8, w9, #0xff
//   0x57dbb8: 37F800E9  tbnz     w9, #0x1f, #0x57dbd4
//   0x57dbbc: 0B020108  add      w8, w8, w2
//   0x57dbc0: 52800021  mov      w1, #1
uint64_t fde_func_18832_0x57dbac(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0057DBACULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x39C00009ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x12001D28ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x37F800E9ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x0B020108ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x52800021ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x12001908ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x39000008ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #18841 | PC: 0x57e204..0x57e210 (12 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x57e204: D503245F  bti      c
//   0x57e208: B940A800  ldr      w0, [x0, #0xa8]
//   0x57e20c: D65F03C0  ret      
uint64_t fde_func_18841_0x57e204(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0057E204ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB940A800ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD65F03C0ULL ^ (2ULL << 32);
    return state ^ (state >> 29);
}

// FDE #18851 | PC: 0x57f61c..0x57f6e4 (200 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x57f61c: D503233F  paciasp  
//   0x57f620: A9BB7BFD  stp      x29, x30, [sp, #-0x50]!
//   0x57f624: F9000BF9  str      x25, [sp, #0x10]
//   0x57f628: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x57f62c: A90357F6  stp      x22, x21, [sp, #0x30]
//   0x57f630: A9044FF4  stp      x20, x19, [sp, #0x40]
uint64_t fde_func_18851_0x57f61c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0057F61CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BB7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF9ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9025FF8ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90357F6ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9044FF4ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0303F7ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #18860 | PC: 0x57fd28..0x57fd5c (52 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x57fd28: D503233F  paciasp  
//   0x57fd2c: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x57fd30: F9000BF3  str      x19, [sp, #0x10]
//   0x57fd34: 910003FD  mov      x29, sp
//   0x57fd38: F9400008  ldr      x8, [x0]
//   0x57fd3c: AA0003F3  mov      x19, x0
uint64_t fde_func_18860_0x57fd28(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0057FD28ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF3ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400008ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9401500ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9400006CULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #18870 | PC: 0x5800e8..0x580140 (88 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x5800e8: D503233F  paciasp  
//   0x5800ec: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x5800f0: F9000BF3  str      x19, [sp, #0x10]
//   0x5800f4: 910003FD  mov      x29, sp
//   0x5800f8: F9400808  ldr      x8, [x0, #0x10]
//   0x5800fc: AA0003F3  mov      x19, x0
uint64_t fde_func_18870_0x5800e8(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x005800E8ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF3ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400808ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x927DF108ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400501ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #18879 | PC: 0x580388..0x5803cc (68 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x580388: D503233F  paciasp  
//   0x58038c: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x580390: F9000BF3  str      x19, [sp, #0x10]
//   0x580394: 910003FD  mov      x29, sp
//   0x580398: AA0103F3  mov      x19, x1
//   0x58039c: F9401821  ldr      x1, [x1, #0x30]
uint64_t fde_func_18879_0x580388(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00580388ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF3ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0103F3ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9401821ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xEB00027FULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x54000100ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #18889 | PC: 0x580a1c..0x580a88 (108 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x580a1c: D503233F  paciasp  
//   0x580a20: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x580a24: F9000BF3  str      x19, [sp, #0x10]
//   0x580a28: 910003FD  mov      x29, sp
//   0x580a2c: AA0003F3  mov      x19, x0
//   0x580a30: 91002000  add      x0, x0, #8
uint64_t fde_func_18889_0x580a1c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00580A1CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF3ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91002000ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x97FD68EAULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB50001E0ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #18898 | PC: 0x58141c..0x58151c (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x58141c: D503233F  paciasp  
//   0x581420: D101C3FF  sub      sp, sp, #0x70
//   0x581424: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x581428: F9001BF9  str      x25, [sp, #0x30]
//   0x58142c: A9045FF8  stp      x24, x23, [sp, #0x40]
//   0x581430: A90557F6  stp      x22, x21, [sp, #0x50]
uint64_t fde_func_18898_0x58141c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0058141CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD101C3FFULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9027BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9001BF9ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9045FF8ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90557F6ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9064FF4ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910083FDULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #18908 | PC: 0x581ac8..0x581b24 (92 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x581ac8: D503233F  paciasp  
//   0x581acc: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x581ad0: F9000BF3  str      x19, [sp, #0x10]
//   0x581ad4: 910003FD  mov      x29, sp
//   0x581ad8: F9400409  ldr      x9, [x0, #8]
//   0x581adc: AA0003F3  mov      x19, x0
uint64_t fde_func_18908_0x581ac8(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00581AC8ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF3ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400409ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD000018AULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9132414AULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #18917 | PC: 0x581cfc..0x581dfc (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x581cfc: D503233F  paciasp  
//   0x581d00: D10143FF  sub      sp, sp, #0x50
//   0x581d04: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x581d08: A90357F6  stp      x22, x21, [sp, #0x30]
//   0x581d0c: A9044FF4  stp      x20, x19, [sp, #0x40]
//   0x581d10: 910083FD  add      x29, sp, #0x20
uint64_t fde_func_18917_0x581cfc(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00581CFCULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10143FFULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9027BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90357F6ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9044FF4ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910083FDULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0103F4ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #18927 | PC: 0x582a84..0x582abc (56 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x582a84: D503233F  paciasp  
//   0x582a88: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x582a8c: F9000BF3  str      x19, [sp, #0x10]
//   0x582a90: 910003FD  mov      x29, sp
//   0x582a94: B0000188  adrp     x8, #0x5b3000
//   0x582a98: 91348108  add      x8, x8, #0xd20
uint64_t fde_func_18927_0x582a84(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00582A84ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF3ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB0000188ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91348108ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF8008408ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #18936 | PC: 0x582c4c..0x582c58 (12 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x582c4c: D503245F  bti      c
//   0x582c50: AA0103E0  mov      x0, x1
//   0x582c54: 140001B3  b        #0x583320
uint64_t fde_func_18936_0x582c4c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00582C4CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0103E0ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x140001B3ULL ^ (2ULL << 32);
    return state ^ (state >> 29);
}

// FDE #18946 | PC: 0x58340c..0x583420 (20 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x58340c: D503245F  bti      c
//   0x583410: AA0803E0  mov      x0, x8
//   0x583414: 90FFD821  adrp     x1, #0x87000
//   0x583418: 9120B421  add      x1, x1, #0x82d
//   0x58341c: 17F13292  b        #0x1cfe64
uint64_t fde_func_18946_0x58340c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0058340CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0803E0ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x90FFD821ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9120B421ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x17F13292ULL ^ (4ULL << 32);
    return state ^ (state >> 29);
}

// FDE #18955 | PC: 0x583a94..0x583aa8 (20 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x583a94: D503245F  bti      c
//   0x583a98: AA0003E8  mov      x8, x0
//   0x583a9c: AA0103E0  mov      x0, x1
//   0x583aa0: AA0803E1  mov      x1, x8
//   0x583aa4: 17FFFDE8  b        #0x583244
uint64_t fde_func_18955_0x583a94(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00583A94ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003E8ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0103E0ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0803E1ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x17FFFDE8ULL ^ (4ULL << 32);
    return state ^ (state >> 29);
}

// FDE #18965 | PC: 0x5840bc..0x5840d0 (20 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x5840bc: D503245F  bti      c
//   0x5840c0: AA0803E0  mov      x0, x8
//   0x5840c4: F0FFD801  adrp     x1, #0x87000
//   0x5840c8: 911EFC21  add      x1, x1, #0x7bf
//   0x5840cc: 17F12F66  b        #0x1cfe64
uint64_t fde_func_18965_0x5840bc(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x005840BCULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0803E0ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF0FFD801ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x911EFC21ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x17F12F66ULL ^ (4ULL << 32);
    return state ^ (state >> 29);
}

// FDE #18974 | PC: 0x584450..0x584550 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x584450: D503233F  paciasp  
//   0x584454: D101C3FF  sub      sp, sp, #0x70
//   0x584458: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x58445c: A9026FFC  stp      x28, x27, [sp, #0x20]
//   0x584460: A90367FA  stp      x26, x25, [sp, #0x30]
//   0x584464: A9045FF8  stp      x24, x23, [sp, #0x40]
uint64_t fde_func_18974_0x584450(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00584450ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD101C3FFULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9026FFCULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90367FAULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9045FF8ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90557F6ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9064FF4ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #18984 | PC: 0x584d28..0x584d70 (72 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x584d28: D503233F  paciasp  
//   0x584d2c: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x584d30: F9000BF3  str      x19, [sp, #0x10]
//   0x584d34: 910003FD  mov      x29, sp
//   0x584d38: AA0003F3  mov      x19, x0
//   0x584d3c: 91002000  add      x0, x0, #8
uint64_t fde_func_18984_0x584d28(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00584D28ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF3ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91002000ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x97FD5827ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9401268ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #18993 | PC: 0x5851b0..0x58523c (140 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x5851b0: D503233F  paciasp  
//   0x5851b4: A9BC7BFD  stp      x29, x30, [sp, #-0x40]!
//   0x5851b8: A9015FF8  stp      x24, x23, [sp, #0x10]
//   0x5851bc: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x5851c0: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x5851c4: 910003FD  mov      x29, sp
uint64_t fde_func_18993_0x5851b0(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x005851B0ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BC7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9015FF8ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90257F6ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9034FF4ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x2A0303F5ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0203F3ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #19003 | PC: 0x5855bc..0x5856bc (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x5855bc: D503233F  paciasp  
//   0x5855c0: D101C3FF  sub      sp, sp, #0x70
//   0x5855c4: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x5855c8: F90013FB  str      x27, [sp, #0x20]
//   0x5855cc: A90367FA  stp      x26, x25, [sp, #0x30]
//   0x5855d0: A9045FF8  stp      x24, x23, [sp, #0x40]
uint64_t fde_func_19003_0x5855bc(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x005855BCULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD101C3FFULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF90013FBULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90367FAULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9045FF8ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90557F6ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9064FF4ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #19012 | PC: 0x585d00..0x585d08 (8 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x585d00: D503245F  bti      c
//   0x585d04: 14000001  b        #0x585d08
uint64_t fde_func_19012_0x585d00(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00585D00ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x14000001ULL ^ (1ULL << 32);
    return state ^ (state >> 29);
}

// FDE #19022 | PC: 0x586000..0x586054 (84 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x586000: D503245F  bti      c
//   0x586004: B9401008  ldr      w8, [x0, #0x10]
//   0x586008: 2A2803E8  mvn      w8, w8
//   0x58600c: 721A0D1F  tst      w8, #0x3c0
//   0x586010: 540001E1  b.ne     #0x58604c
//   0x586014: B9402009  ldr      w9, [x0, #0x20]
uint64_t fde_func_19022_0x586000(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00586000ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB9401008ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x2A2803E8ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x721A0D1FULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x540001E1ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB9402009ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9401408ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x2A0903EAULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

uint64_t execute_fde_shard_5(uint32_t fde_idx, uint64_t a0, uint64_t a1) {
    switch (fde_idx) {
        case 15225: return fde_func_15225_0x4b5b4c(a0, a1);
        case 15235: return fde_func_15235_0x4b6438(a0, a1);
        case 15244: return fde_func_15244_0x4b69f8(a0, a1);
        case 15254: return fde_func_15254_0x4b7274(a0, a1);
        case 15263: return fde_func_15263_0x4b79bc(a0, a1);
        case 15273: return fde_func_15273_0x4b8178(a0, a1);
        case 15282: return fde_func_15282_0x4b8900(a0, a1);
        case 15292: return fde_func_15292_0x4b942c(a0, a1);
        case 15301: return fde_func_15301_0x4b9fb8(a0, a1);
        case 15311: return fde_func_15311_0x4bacac(a0, a1);
        case 15320: return fde_func_15320_0x4bbb94(a0, a1);
        case 15330: return fde_func_15330_0x4bc428(a0, a1);
        case 15339: return fde_func_15339_0x4bc9e0(a0, a1);
        case 15349: return fde_func_15349_0x4bce40(a0, a1);
        case 15358: return fde_func_15358_0x4bd578(a0, a1);
        case 15368: return fde_func_15368_0x4bde98(a0, a1);
        case 15377: return fde_func_15377_0x4be30c(a0, a1);
        case 15387: return fde_func_15387_0x4be64c(a0, a1);
        case 15396: return fde_func_15396_0x4be94c(a0, a1);
        case 15406: return fde_func_15406_0x4bef6c(a0, a1);
        case 15415: return fde_func_15415_0x4bf238(a0, a1);
        case 15425: return fde_func_15425_0x4bf58c(a0, a1);
        case 15434: return fde_func_15434_0x4bfb20(a0, a1);
        case 15444: return fde_func_15444_0x4bfdcc(a0, a1);
        case 15453: return fde_func_15453_0x4c04c8(a0, a1);
        case 15463: return fde_func_15463_0x4c0cfc(a0, a1);
        case 15473: return fde_func_15473_0x4c1d90(a0, a1);
        case 15482: return fde_func_15482_0x4c1e38(a0, a1);
        case 15492: return fde_func_15492_0x4c1eb0(a0, a1);
        case 15501: return fde_func_15501_0x4c2020(a0, a1);
        case 15511: return fde_func_15511_0x4c2738(a0, a1);
        case 15520: return fde_func_15520_0x4c2b44(a0, a1);
        case 15530: return fde_func_15530_0x4c3158(a0, a1);
        case 15539: return fde_func_15539_0x4c3550(a0, a1);
        case 15549: return fde_func_15549_0x4c3db8(a0, a1);
        case 15558: return fde_func_15558_0x4c4358(a0, a1);
        case 15568: return fde_func_15568_0x4c4a8c(a0, a1);
        case 15577: return fde_func_15577_0x4c579c(a0, a1);
        case 15587: return fde_func_15587_0x4c59d8(a0, a1);
        case 15596: return fde_func_15596_0x4c5d7c(a0, a1);
        case 15606: return fde_func_15606_0x4c5f18(a0, a1);
        case 15615: return fde_func_15615_0x4c6d68(a0, a1);
        case 15625: return fde_func_15625_0x4c7474(a0, a1);
        case 15634: return fde_func_15634_0x4c7a3c(a0, a1);
        case 15644: return fde_func_15644_0x4c7ea8(a0, a1);
        case 15653: return fde_func_15653_0x4c87c4(a0, a1);
        case 15663: return fde_func_15663_0x4c9280(a0, a1);
        case 15672: return fde_func_15672_0x4c96d4(a0, a1);
        case 15682: return fde_func_15682_0x4c9f70(a0, a1);
        case 15691: return fde_func_15691_0x4caec4(a0, a1);
        case 15701: return fde_func_15701_0x4cb990(a0, a1);
        case 15710: return fde_func_15710_0x4cbcd4(a0, a1);
        case 15720: return fde_func_15720_0x4cc0dc(a0, a1);
        case 15729: return fde_func_15729_0x4cc700(a0, a1);
        case 15739: return fde_func_15739_0x4cd3b0(a0, a1);
        case 15748: return fde_func_15748_0x4cd880(a0, a1);
        case 15758: return fde_func_15758_0x4cdc64(a0, a1);
        case 15768: return fde_func_15768_0x4ce200(a0, a1);
        case 15777: return fde_func_15777_0x4cea44(a0, a1);
        case 15787: return fde_func_15787_0x4cf284(a0, a1);
        case 15796: return fde_func_15796_0x4cf9a4(a0, a1);
        case 15806: return fde_func_15806_0x4cfd9c(a0, a1);
        case 15815: return fde_func_15815_0x4d04e4(a0, a1);
        case 15825: return fde_func_15825_0x4d26cc(a0, a1);
        case 15834: return fde_func_15834_0x4d2b2c(a0, a1);
        case 15844: return fde_func_15844_0x4d3440(a0, a1);
        case 15853: return fde_func_15853_0x4d408c(a0, a1);
        case 15863: return fde_func_15863_0x4d48ec(a0, a1);
        case 15872: return fde_func_15872_0x4d5114(a0, a1);
        case 15882: return fde_func_15882_0x4d5958(a0, a1);
        case 15891: return fde_func_15891_0x4d5c00(a0, a1);
        case 15901: return fde_func_15901_0x4d5fe0(a0, a1);
        case 15910: return fde_func_15910_0x4d6420(a0, a1);
        case 15920: return fde_func_15920_0x4d6b14(a0, a1);
        case 15929: return fde_func_15929_0x4d7278(a0, a1);
        case 15939: return fde_func_15939_0x4d76d0(a0, a1);
        case 15948: return fde_func_15948_0x4d7c18(a0, a1);
        case 15958: return fde_func_15958_0x4d84fc(a0, a1);
        case 15967: return fde_func_15967_0x4d8e2c(a0, a1);
        case 15977: return fde_func_15977_0x4d9cd0(a0, a1);
        case 15986: return fde_func_15986_0x4d9f50(a0, a1);
        case 15996: return fde_func_15996_0x4da1f8(a0, a1);
        case 16005: return fde_func_16005_0x4daa10(a0, a1);
        case 16015: return fde_func_16015_0x4dadf4(a0, a1);
        case 16024: return fde_func_16024_0x4db378(a0, a1);
        case 16034: return fde_func_16034_0x4db92c(a0, a1);
        case 16043: return fde_func_16043_0x4dbca8(a0, a1);
        case 16053: return fde_func_16053_0x4dc358(a0, a1);
        case 16063: return fde_func_16063_0x4dc8a0(a0, a1);
        case 16072: return fde_func_16072_0x4dcfe4(a0, a1);
        case 16082: return fde_func_16082_0x4dd700(a0, a1);
        case 16091: return fde_func_16091_0x4ddb28(a0, a1);
        case 16101: return fde_func_16101_0x4de570(a0, a1);
        case 16110: return fde_func_16110_0x4ded34(a0, a1);
        case 16120: return fde_func_16120_0x4df324(a0, a1);
        case 16129: return fde_func_16129_0x4df6a4(a0, a1);
        case 16139: return fde_func_16139_0x4dfad8(a0, a1);
        case 16148: return fde_func_16148_0x4dff14(a0, a1);
        case 16158: return fde_func_16158_0x4e0274(a0, a1);
        case 16167: return fde_func_16167_0x4e07d4(a0, a1);
        case 16177: return fde_func_16177_0x4e0a00(a0, a1);
        case 16186: return fde_func_16186_0x4e0fd4(a0, a1);
        case 16196: return fde_func_16196_0x4e21e4(a0, a1);
        case 16205: return fde_func_16205_0x4e30ac(a0, a1);
        case 16215: return fde_func_16215_0x4e3a38(a0, a1);
        case 16224: return fde_func_16224_0x4e4008(a0, a1);
        case 16234: return fde_func_16234_0x4e4780(a0, a1);
        case 16243: return fde_func_16243_0x4e4b70(a0, a1);
        case 16253: return fde_func_16253_0x4e4f00(a0, a1);
        case 16262: return fde_func_16262_0x4e57e8(a0, a1);
        case 16272: return fde_func_16272_0x4e5d78(a0, a1);
        case 16281: return fde_func_16281_0x4e65b4(a0, a1);
        case 16291: return fde_func_16291_0x4e70cc(a0, a1);
        case 16300: return fde_func_16300_0x4e8224(a0, a1);
        case 16310: return fde_func_16310_0x4e8778(a0, a1);
        case 16319: return fde_func_16319_0x4e8a80(a0, a1);
        case 16329: return fde_func_16329_0x4e948c(a0, a1);
        case 16338: return fde_func_16338_0x4e9b48(a0, a1);
        case 16348: return fde_func_16348_0x4ea788(a0, a1);
        case 16358: return fde_func_16358_0x4eb29c(a0, a1);
        case 16367: return fde_func_16367_0x4ec408(a0, a1);
        case 16377: return fde_func_16377_0x4ec948(a0, a1);
        case 16386: return fde_func_16386_0x4ed05c(a0, a1);
        case 16396: return fde_func_16396_0x4ed6d0(a0, a1);
        case 16405: return fde_func_16405_0x4ed9b8(a0, a1);
        case 16415: return fde_func_16415_0x4ee13c(a0, a1);
        case 16424: return fde_func_16424_0x4ee3a4(a0, a1);
        case 16434: return fde_func_16434_0x4eea38(a0, a1);
        case 16443: return fde_func_16443_0x4eee34(a0, a1);
        case 16453: return fde_func_16453_0x4eefa0(a0, a1);
        case 16462: return fde_func_16462_0x4ef2cc(a0, a1);
        case 16472: return fde_func_16472_0x4ef944(a0, a1);
        case 16481: return fde_func_16481_0x4efddc(a0, a1);
        case 16491: return fde_func_16491_0x4f06a8(a0, a1);
        case 16500: return fde_func_16500_0x4f0d9c(a0, a1);
        case 16510: return fde_func_16510_0x4f18c0(a0, a1);
        case 16519: return fde_func_16519_0x4f2a78(a0, a1);
        case 16529: return fde_func_16529_0x4f2ed0(a0, a1);
        case 16538: return fde_func_16538_0x4f313c(a0, a1);
        case 16548: return fde_func_16548_0x4f3fec(a0, a1);
        case 16557: return fde_func_16557_0x4f4534(a0, a1);
        case 16567: return fde_func_16567_0x4f4d20(a0, a1);
        case 16576: return fde_func_16576_0x4f52e8(a0, a1);
        case 16586: return fde_func_16586_0x4f5d88(a0, a1);
        case 16595: return fde_func_16595_0x4f7170(a0, a1);
        case 16605: return fde_func_16605_0x4f7580(a0, a1);
        case 16614: return fde_func_16614_0x4f7964(a0, a1);
        case 16624: return fde_func_16624_0x4f83fc(a0, a1);
        case 16633: return fde_func_16633_0x4f9ca4(a0, a1);
        case 16643: return fde_func_16643_0x4fa0a0(a0, a1);
        case 16653: return fde_func_16653_0x4fca28(a0, a1);
        case 16662: return fde_func_16662_0x4fdf7c(a0, a1);
        case 16672: return fde_func_16672_0x4fe71c(a0, a1);
        case 16681: return fde_func_16681_0x4ff9bc(a0, a1);
        case 16691: return fde_func_16691_0x4ffd74(a0, a1);
        case 16700: return fde_func_16700_0x5002d0(a0, a1);
        case 16710: return fde_func_16710_0x50148c(a0, a1);
        case 16719: return fde_func_16719_0x502010(a0, a1);
        case 16729: return fde_func_16729_0x5023d4(a0, a1);
        case 16738: return fde_func_16738_0x5026c4(a0, a1);
        case 16748: return fde_func_16748_0x5030a8(a0, a1);
        case 16757: return fde_func_16757_0x503630(a0, a1);
        case 16767: return fde_func_16767_0x503a40(a0, a1);
        case 16776: return fde_func_16776_0x503fd8(a0, a1);
        case 16786: return fde_func_16786_0x50412c(a0, a1);
        case 16795: return fde_func_16795_0x504338(a0, a1);
        case 16805: return fde_func_16805_0x504e54(a0, a1);
        case 16814: return fde_func_16814_0x5059a8(a0, a1);
        case 16824: return fde_func_16824_0x505b04(a0, a1);
        case 16833: return fde_func_16833_0x506128(a0, a1);
        case 16843: return fde_func_16843_0x5067cc(a0, a1);
        case 16852: return fde_func_16852_0x506c94(a0, a1);
        case 16862: return fde_func_16862_0x507354(a0, a1);
        case 16871: return fde_func_16871_0x507eec(a0, a1);
        case 16881: return fde_func_16881_0x508948(a0, a1);
        case 16890: return fde_func_16890_0x50907c(a0, a1);
        case 16900: return fde_func_16900_0x509190(a0, a1);
        case 16909: return fde_func_16909_0x509684(a0, a1);
        case 16919: return fde_func_16919_0x509bb0(a0, a1);
        case 16928: return fde_func_16928_0x50a394(a0, a1);
        case 16938: return fde_func_16938_0x50aa20(a0, a1);
        case 16947: return fde_func_16947_0x50b298(a0, a1);
        case 16957: return fde_func_16957_0x50bba4(a0, a1);
        case 16967: return fde_func_16967_0x50c7dc(a0, a1);
        case 16976: return fde_func_16976_0x50d028(a0, a1);
        case 16986: return fde_func_16986_0x50e968(a0, a1);
        case 16995: return fde_func_16995_0x50f1a0(a0, a1);
        case 17005: return fde_func_17005_0x50fb88(a0, a1);
        case 17014: return fde_func_17014_0x510408(a0, a1);
        case 17024: return fde_func_17024_0x510f94(a0, a1);
        case 17033: return fde_func_17033_0x511338(a0, a1);
        case 17043: return fde_func_17043_0x51178c(a0, a1);
        case 17052: return fde_func_17052_0x5119dc(a0, a1);
        case 17062: return fde_func_17062_0x511fec(a0, a1);
        case 17071: return fde_func_17071_0x512554(a0, a1);
        case 17081: return fde_func_17081_0x512a60(a0, a1);
        case 17090: return fde_func_17090_0x512b30(a0, a1);
        case 17100: return fde_func_17100_0x512d44(a0, a1);
        case 17109: return fde_func_17109_0x51327c(a0, a1);
        case 17119: return fde_func_17119_0x51368c(a0, a1);
        case 17128: return fde_func_17128_0x513b20(a0, a1);
        case 17138: return fde_func_17138_0x51404c(a0, a1);
        case 17147: return fde_func_17147_0x514534(a0, a1);
        case 17157: return fde_func_17157_0x514f48(a0, a1);
        case 17166: return fde_func_17166_0x5159c4(a0, a1);
        case 17176: return fde_func_17176_0x5164fc(a0, a1);
        case 17185: return fde_func_17185_0x517108(a0, a1);
        case 17195: return fde_func_17195_0x517498(a0, a1);
        case 17204: return fde_func_17204_0x517710(a0, a1);
        case 17214: return fde_func_17214_0x517b2c(a0, a1);
        case 17223: return fde_func_17223_0x517fa4(a0, a1);
        case 17233: return fde_func_17233_0x518718(a0, a1);
        case 17242: return fde_func_17242_0x519008(a0, a1);
        case 17252: return fde_func_17252_0x519480(a0, a1);
        case 17262: return fde_func_17262_0x519c04(a0, a1);
        case 17271: return fde_func_17271_0x51a7e4(a0, a1);
        case 17281: return fde_func_17281_0x51ab60(a0, a1);
        case 17290: return fde_func_17290_0x51d100(a0, a1);
        case 17300: return fde_func_17300_0x51d768(a0, a1);
        case 17309: return fde_func_17309_0x51db00(a0, a1);
        case 17319: return fde_func_17319_0x51ebb4(a0, a1);
        case 17328: return fde_func_17328_0x51ffa4(a0, a1);
        case 17338: return fde_func_17338_0x520334(a0, a1);
        case 17347: return fde_func_17347_0x520ab4(a0, a1);
        case 17357: return fde_func_17357_0x520f5c(a0, a1);
        case 17366: return fde_func_17366_0x521f9c(a0, a1);
        case 17376: return fde_func_17376_0x523740(a0, a1);
        case 17385: return fde_func_17385_0x525624(a0, a1);
        case 17395: return fde_func_17395_0x526768(a0, a1);
        case 17404: return fde_func_17404_0x5275bc(a0, a1);
        case 17414: return fde_func_17414_0x527940(a0, a1);
        case 17423: return fde_func_17423_0x528fc4(a0, a1);
        case 17433: return fde_func_17433_0x529b34(a0, a1);
        case 17442: return fde_func_17442_0x52a1e0(a0, a1);
        case 17452: return fde_func_17452_0x52aeb4(a0, a1);
        case 17461: return fde_func_17461_0x52d49c(a0, a1);
        case 17471: return fde_func_17471_0x52d73c(a0, a1);
        case 17480: return fde_func_17480_0x52d7a8(a0, a1);
        case 17490: return fde_func_17490_0x52d838(a0, a1);
        case 17499: return fde_func_17499_0x52d8a4(a0, a1);
        case 17509: return fde_func_17509_0x52dc54(a0, a1);
        case 17518: return fde_func_17518_0x52e124(a0, a1);
        case 17528: return fde_func_17528_0x52e910(a0, a1);
        case 17537: return fde_func_17537_0x52f628(a0, a1);
        case 17547: return fde_func_17547_0x5300a4(a0, a1);
        case 17557: return fde_func_17557_0x530fc4(a0, a1);
        case 17566: return fde_func_17566_0x531440(a0, a1);
        case 17576: return fde_func_17576_0x5323a4(a0, a1);
        case 17585: return fde_func_17585_0x53279c(a0, a1);
        case 17595: return fde_func_17595_0x532bf0(a0, a1);
        case 17604: return fde_func_17604_0x533004(a0, a1);
        case 17614: return fde_func_17614_0x53353c(a0, a1);
        case 17623: return fde_func_17623_0x533b44(a0, a1);
        case 17633: return fde_func_17633_0x534378(a0, a1);
        case 17642: return fde_func_17642_0x5349b0(a0, a1);
        case 17652: return fde_func_17652_0x537088(a0, a1);
        case 17661: return fde_func_17661_0x5372c0(a0, a1);
        case 17671: return fde_func_17671_0x537540(a0, a1);
        case 17680: return fde_func_17680_0x53764c(a0, a1);
        case 17690: return fde_func_17690_0x537748(a0, a1);
        case 17699: return fde_func_17699_0x537804(a0, a1);
        case 17709: return fde_func_17709_0x537bb0(a0, a1);
        case 17718: return fde_func_17718_0x53868c(a0, a1);
        case 17728: return fde_func_17728_0x538b20(a0, a1);
        case 17737: return fde_func_17737_0x5390f8(a0, a1);
        case 17747: return fde_func_17747_0x5396e0(a0, a1);
        case 17756: return fde_func_17756_0x539fe0(a0, a1);
        case 17766: return fde_func_17766_0x53c96c(a0, a1);
        case 17775: return fde_func_17775_0x53dedc(a0, a1);
        case 17785: return fde_func_17785_0x540ba8(a0, a1);
        case 17794: return fde_func_17794_0x542ccc(a0, a1);
        case 17804: return fde_func_17804_0x543e98(a0, a1);
        case 17813: return fde_func_17813_0x5442bc(a0, a1);
        case 17823: return fde_func_17823_0x544868(a0, a1);
        case 17832: return fde_func_17832_0x544be0(a0, a1);
        case 17842: return fde_func_17842_0x545488(a0, a1);
        case 17852: return fde_func_17852_0x546a48(a0, a1);
        case 17861: return fde_func_17861_0x5478b8(a0, a1);
        case 17871: return fde_func_17871_0x547ddc(a0, a1);
        case 17880: return fde_func_17880_0x548c50(a0, a1);
        case 17890: return fde_func_17890_0x5490f8(a0, a1);
        case 17899: return fde_func_17899_0x5495b0(a0, a1);
        case 17909: return fde_func_17909_0x549b7c(a0, a1);
        case 17918: return fde_func_17918_0x54a1f8(a0, a1);
        case 17928: return fde_func_17928_0x54b13c(a0, a1);
        case 17937: return fde_func_17937_0x54c690(a0, a1);
        case 17947: return fde_func_17947_0x54ce00(a0, a1);
        case 17956: return fde_func_17956_0x54d304(a0, a1);
        case 17966: return fde_func_17966_0x54df8c(a0, a1);
        case 17975: return fde_func_17975_0x54ea44(a0, a1);
        case 17985: return fde_func_17985_0x54f050(a0, a1);
        case 17994: return fde_func_17994_0x54ff68(a0, a1);
        case 18004: return fde_func_18004_0x55069c(a0, a1);
        case 18013: return fde_func_18013_0x551b54(a0, a1);
        case 18023: return fde_func_18023_0x552708(a0, a1);
        case 18032: return fde_func_18032_0x552e18(a0, a1);
        case 18042: return fde_func_18042_0x553770(a0, a1);
        case 18051: return fde_func_18051_0x5537dc(a0, a1);
        case 18061: return fde_func_18061_0x553854(a0, a1);
        case 18070: return fde_func_18070_0x5538e4(a0, a1);
        case 18080: return fde_func_18080_0x553964(a0, a1);
        case 18089: return fde_func_18089_0x553fe4(a0, a1);
        case 18099: return fde_func_18099_0x554888(a0, a1);
        case 18108: return fde_func_18108_0x554e00(a0, a1);
        case 18118: return fde_func_18118_0x5551c0(a0, a1);
        case 18127: return fde_func_18127_0x55580c(a0, a1);
        case 18137: return fde_func_18137_0x555bac(a0, a1);
        case 18147: return fde_func_18147_0x55620c(a0, a1);
        case 18156: return fde_func_18156_0x556cb4(a0, a1);
        case 18166: return fde_func_18166_0x5572e4(a0, a1);
        case 18175: return fde_func_18175_0x557bd4(a0, a1);
        case 18185: return fde_func_18185_0x558908(a0, a1);
        case 18194: return fde_func_18194_0x5593cc(a0, a1);
        case 18204: return fde_func_18204_0x559e58(a0, a1);
        case 18213: return fde_func_18213_0x55ab10(a0, a1);
        case 18223: return fde_func_18223_0x55b5f0(a0, a1);
        case 18232: return fde_func_18232_0x55badc(a0, a1);
        case 18242: return fde_func_18242_0x55c7b8(a0, a1);
        case 18251: return fde_func_18251_0x55cddc(a0, a1);
        case 18261: return fde_func_18261_0x55d36c(a0, a1);
        case 18270: return fde_func_18270_0x55d884(a0, a1);
        case 18280: return fde_func_18280_0x55db6c(a0, a1);
        case 18289: return fde_func_18289_0x55e488(a0, a1);
        case 18299: return fde_func_18299_0x55edc4(a0, a1);
        case 18308: return fde_func_18308_0x55f448(a0, a1);
        case 18318: return fde_func_18318_0x55fc78(a0, a1);
        case 18327: return fde_func_18327_0x5608c0(a0, a1);
        case 18337: return fde_func_18337_0x561900(a0, a1);
        case 18346: return fde_func_18346_0x5619a0(a0, a1);
        case 18356: return fde_func_18356_0x561d30(a0, a1);
        case 18365: return fde_func_18365_0x561dc4(a0, a1);
        case 18375: return fde_func_18375_0x561e54(a0, a1);
        case 18384: return fde_func_18384_0x561fbc(a0, a1);
        case 18394: return fde_func_18394_0x562bc8(a0, a1);
        case 18403: return fde_func_18403_0x563080(a0, a1);
        case 18413: return fde_func_18413_0x563858(a0, a1);
        case 18422: return fde_func_18422_0x563e64(a0, a1);
        case 18432: return fde_func_18432_0x56499c(a0, a1);
        case 18442: return fde_func_18442_0x565074(a0, a1);
        case 18451: return fde_func_18451_0x565a60(a0, a1);
        case 18461: return fde_func_18461_0x5662d0(a0, a1);
        case 18470: return fde_func_18470_0x566634(a0, a1);
        case 18480: return fde_func_18480_0x5669e0(a0, a1);
        case 18489: return fde_func_18489_0x5672f4(a0, a1);
        case 18499: return fde_func_18499_0x5684c4(a0, a1);
        case 18508: return fde_func_18508_0x568dc4(a0, a1);
        case 18518: return fde_func_18518_0x569364(a0, a1);
        case 18527: return fde_func_18527_0x5698a8(a0, a1);
        case 18537: return fde_func_18537_0x56a500(a0, a1);
        case 18546: return fde_func_18546_0x56a9ec(a0, a1);
        case 18556: return fde_func_18556_0x56b120(a0, a1);
        case 18565: return fde_func_18565_0x56b7b8(a0, a1);
        case 18575: return fde_func_18575_0x56c51c(a0, a1);
        case 18584: return fde_func_18584_0x56c9f8(a0, a1);
        case 18594: return fde_func_18594_0x56cb14(a0, a1);
        case 18603: return fde_func_18603_0x56cbf0(a0, a1);
        case 18613: return fde_func_18613_0x56cd54(a0, a1);
        case 18622: return fde_func_18622_0x56d7ac(a0, a1);
        case 18632: return fde_func_18632_0x56dbc0(a0, a1);
        case 18641: return fde_func_18641_0x56e598(a0, a1);
        case 18651: return fde_func_18651_0x56e9a8(a0, a1);
        case 18660: return fde_func_18660_0x56ee2c(a0, a1);
        case 18670: return fde_func_18670_0x56f2ac(a0, a1);
        case 18679: return fde_func_18679_0x56fb40(a0, a1);
        case 18689: return fde_func_18689_0x5700b4(a0, a1);
        case 18698: return fde_func_18698_0x570828(a0, a1);
        case 18708: return fde_func_18708_0x570eac(a0, a1);
        case 18717: return fde_func_18717_0x571534(a0, a1);
        case 18727: return fde_func_18727_0x571d28(a0, a1);
        case 18737: return fde_func_18737_0x572984(a0, a1);
        case 18746: return fde_func_18746_0x57307c(a0, a1);
        case 18756: return fde_func_18756_0x5742d0(a0, a1);
        case 18765: return fde_func_18765_0x574c38(a0, a1);
        case 18775: return fde_func_18775_0x575d18(a0, a1);
        case 18784: return fde_func_18784_0x576800(a0, a1);
        case 18794: return fde_func_18794_0x577aec(a0, a1);
        case 18803: return fde_func_18803_0x57988c(a0, a1);
        case 18813: return fde_func_18813_0x57b75c(a0, a1);
        case 18822: return fde_func_18822_0x57cb1c(a0, a1);
        case 18832: return fde_func_18832_0x57dbac(a0, a1);
        case 18841: return fde_func_18841_0x57e204(a0, a1);
        case 18851: return fde_func_18851_0x57f61c(a0, a1);
        case 18860: return fde_func_18860_0x57fd28(a0, a1);
        case 18870: return fde_func_18870_0x5800e8(a0, a1);
        case 18879: return fde_func_18879_0x580388(a0, a1);
        case 18889: return fde_func_18889_0x580a1c(a0, a1);
        case 18898: return fde_func_18898_0x58141c(a0, a1);
        case 18908: return fde_func_18908_0x581ac8(a0, a1);
        case 18917: return fde_func_18917_0x581cfc(a0, a1);
        case 18927: return fde_func_18927_0x582a84(a0, a1);
        case 18936: return fde_func_18936_0x582c4c(a0, a1);
        case 18946: return fde_func_18946_0x58340c(a0, a1);
        case 18955: return fde_func_18955_0x583a94(a0, a1);
        case 18965: return fde_func_18965_0x5840bc(a0, a1);
        case 18974: return fde_func_18974_0x584450(a0, a1);
        case 18984: return fde_func_18984_0x584d28(a0, a1);
        case 18993: return fde_func_18993_0x5851b0(a0, a1);
        case 19003: return fde_func_19003_0x5855bc(a0, a1);
        case 19012: return fde_func_19012_0x585d00(a0, a1);
        case 19022: return fde_func_19022_0x586000(a0, a1);
        default: return 0ULL;
    }
}

} // namespace sscronet