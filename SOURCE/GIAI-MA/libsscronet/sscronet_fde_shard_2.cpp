// ============================================================================
// Clean-Room C++17 Reconstructed AArch64 FDE Shard 2/5 for libsscronet.so
// Phân mảnh hàm FDE AArch64 C++17 sạch 2/5 cho libsscronet.so
// Covers 400 FDEs (indices 400..799 of 2,000 sampled from 19,032 FDEs @ 0x0f1dd8)
// ============================================================================
#include "sscronet_core.h"

namespace sscronet {

// FDE #03806 | PC: 0x26ae68..0x26af68 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x26ae68: D503233F  paciasp  
//   0x26ae6c: D10143FF  sub      sp, sp, #0x50
//   0x26ae70: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x26ae74: F90013F7  str      x23, [sp, #0x20]
//   0x26ae78: A90357F6  stp      x22, x21, [sp, #0x30]
//   0x26ae7c: A9044FF4  stp      x20, x19, [sp, #0x40]
uint64_t fde_func_03806_0x26ae68(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0026AE68ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10143FFULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF90013F7ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90357F6ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9044FF4ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #03815 | PC: 0x26b4b0..0x26b4d8 (40 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x26b4b0: D503245F  bti      c
//   0x26b4b4: 9103A009  add      x9, x0, #0xe8
//   0x26b4b8: F9408C08  ldr      x8, [x0, #0x118]
//   0x26b4bc: AA0203E4  mov      x4, x2
//   0x26b4c0: AA0103E3  mov      x3, x1
//   0x26b4c4: AA0003E1  mov      x1, x0
uint64_t fde_func_03815_0x26b4b0(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0026B4B0ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9103A009ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9408C08ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0203E4ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0103E3ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003E1ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xC8DFFD22ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0803E0ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #03825 | PC: 0x26b8bc..0x26b8e4 (40 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x26b8bc: D503245F  bti      c
//   0x26b8c0: A942A009  ldp      x9, x8, [x0, #0x28]
//   0x26b8c4: F9401010  ldr      x16, [x0, #0x20]
//   0x26b8c8: 8B890508  add      x8, x8, x9, asr #1
//   0x26b8cc: 36000069  tbz      w9, #0, #0x26b8d8
//   0x26b8d0: F9400109  ldr      x9, [x8]
uint64_t fde_func_03825_0x26b8bc(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0026B8BCULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA942A009ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9401010ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x8B890508ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x36000069ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400109ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF8706930ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB9803801ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #03834 | PC: 0x26c0b4..0x26c1b4 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x26c0b4: D503233F  paciasp  
//   0x26c0b8: A9BB7BFD  stp      x29, x30, [sp, #-0x50]!
//   0x26c0bc: F9000BF9  str      x25, [sp, #0x10]
//   0x26c0c0: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x26c0c4: A90357F6  stp      x22, x21, [sp, #0x30]
//   0x26c0c8: A9044FF4  stp      x20, x19, [sp, #0x40]
uint64_t fde_func_03834_0x26c0b4(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0026C0B4ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BB7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF9ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9025FF8ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90357F6ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9044FF4ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x72150088ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #03844 | PC: 0x26d380..0x26d480 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x26d380: D503233F  paciasp  
//   0x26d384: A9BA7BFD  stp      x29, x30, [sp, #-0x60]!
//   0x26d388: A9016FFC  stp      x28, x27, [sp, #0x10]
//   0x26d38c: A90267FA  stp      x26, x25, [sp, #0x20]
//   0x26d390: A9035FF8  stp      x24, x23, [sp, #0x30]
//   0x26d394: A90457F6  stp      x22, x21, [sp, #0x40]
uint64_t fde_func_03844_0x26d380(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0026D380ULL);
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

// FDE #03853 | PC: 0x26de54..0x26de6c (24 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x26de54: D503245F  bti      c
//   0x26de58: F9401408  ldr      x8, [x0, #0x28]
//   0x26de5c: AA0003E1  mov      x1, x0
//   0x26de60: F9400910  ldr      x16, [x8, #0x10]
//   0x26de64: AA0803E0  mov      x0, x8
//   0x26de68: D61F0200  br       x16
uint64_t fde_func_03853_0x26de54(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0026DE54ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9401408ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003E1ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400910ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0803E0ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD61F0200ULL ^ (5ULL << 32);
    return state ^ (state >> 29);
}

// FDE #03863 | PC: 0x26df20..0x26df38 (24 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x26df20: D503245F  bti      c
//   0x26df24: F9400C08  ldr      x8, [x0, #0x18]
//   0x26df28: D1004001  sub      x1, x0, #0x10
//   0x26df2c: F9401110  ldr      x16, [x8, #0x20]
//   0x26df30: AA0803E0  mov      x0, x8
//   0x26df34: D61F0200  br       x16
uint64_t fde_func_03863_0x26df20(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0026DF20ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400C08ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD1004001ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9401110ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0803E0ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD61F0200ULL ^ (5ULL << 32);
    return state ^ (state >> 29);
}

// FDE #03873 | PC: 0x26e138..0x26e238 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x26e138: D503233F  paciasp  
//   0x26e13c: D101C3FF  sub      sp, sp, #0x70
//   0x26e140: A9037BFD  stp      x29, x30, [sp, #0x30]
//   0x26e144: A9045FF8  stp      x24, x23, [sp, #0x40]
//   0x26e148: A90557F6  stp      x22, x21, [sp, #0x50]
//   0x26e14c: A9064FF4  stp      x20, x19, [sp, #0x60]
uint64_t fde_func_03873_0x26e138(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0026E138ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD101C3FFULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9037BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9045FF8ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90557F6ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9064FF4ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9100C3FDULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD53BD058ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #03882 | PC: 0x26e930..0x26ea30 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x26e930: D503233F  paciasp  
//   0x26e934: D10383FF  sub      sp, sp, #0xe0
//   0x26e938: A9087BFD  stp      x29, x30, [sp, #0x80]
//   0x26e93c: F9004BFB  str      x27, [sp, #0x90]
//   0x26e940: A90A67FA  stp      x26, x25, [sp, #0xa0]
//   0x26e944: A90B5FF8  stp      x24, x23, [sp, #0xb0]
uint64_t fde_func_03882_0x26e930(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0026E930ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10383FFULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9087BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9004BFBULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90A67FAULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90B5FF8ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90C57F6ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90D4FF4ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #03892 | PC: 0x26f234..0x26f268 (52 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x26f234: D503233F  paciasp  
//   0x26f238: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x26f23c: F9000BF3  str      x19, [sp, #0x10]
//   0x26f240: 910003FD  mov      x29, sp
//   0x26f244: AA0003F3  mov      x19, x0
//   0x26f248: 940397A8  bl       #0x3550e8
uint64_t fde_func_03892_0x26f234(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0026F234ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF3ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x940397A8ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400668ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400BF3ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #03901 | PC: 0x26fb84..0x26fbf8 (116 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x26fb84: D503233F  paciasp  
//   0x26fb88: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x26fb8c: F9000BF3  str      x19, [sp, #0x10]
//   0x26fb90: 910003FD  mov      x29, sp
//   0x26fb94: AA0003F3  mov      x19, x0
//   0x26fb98: F941D001  ldr      x1, [x0, #0x3a0]
uint64_t fde_func_03901_0x26fb84(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0026FB84ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF3ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF941D001ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910063A0ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x94045B18ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #03911 | PC: 0x26fd78..0x26fd90 (24 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x26fd78: D503245F  bti      c
//   0x26fd7c: F941D400  ldr      x0, [x0, #0x3a8]
//   0x26fd80: 52800081  mov      w1, #4
//   0x26fd84: F9400008  ldr      x8, [x0]
//   0x26fd88: F9402910  ldr      x16, [x8, #0x50]
//   0x26fd8c: D61F0200  br       x16
uint64_t fde_func_03911_0x26fd78(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0026FD78ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF941D400ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x52800081ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400008ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9402910ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD61F0200ULL ^ (5ULL << 32);
    return state ^ (state >> 29);
}

// FDE #03920 | PC: 0x2700cc..0x27014c (128 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x2700cc: D503233F  paciasp  
//   0x2700d0: D100C3FF  sub      sp, sp, #0x30
//   0x2700d4: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x2700d8: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x2700dc: 910043FD  add      x29, sp, #0x10
//   0x2700e0: AA0003F4  mov      x20, x0
uint64_t fde_func_03920_0x2700cc(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x002700CCULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD100C3FFULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9024FF4ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F4ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x52800900ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0103F3ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #03930 | PC: 0x270ea4..0x270eac (8 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x270ea4: D503245F  bti      c
//   0x270ea8: 17FFFA2A  b        #0x26f750
uint64_t fde_func_03930_0x270ea4(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00270EA4ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x17FFFA2AULL ^ (1ULL << 32);
    return state ^ (state >> 29);
}

// FDE #03939 | PC: 0x2712a8..0x2712d4 (44 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x2712a8: D503233F  paciasp  
//   0x2712ac: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x2712b0: F9000BF3  str      x19, [sp, #0x10]
//   0x2712b4: 910003FD  mov      x29, sp
//   0x2712b8: AA0003F3  mov      x19, x0
//   0x2712bc: 97FFFBE6  bl       #0x270254
uint64_t fde_func_03939_0x2712a8(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x002712A8ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF3ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x97FFFBE6ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB941D660ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400BF3ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #03949 | PC: 0x271690..0x2716e0 (80 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x271690: D503233F  paciasp  
//   0x271694: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x271698: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x27169c: 910003FD  mov      x29, sp
//   0x2716a0: 91002014  add      x20, x0, #8
//   0x2716a4: AA0003F3  mov      x19, x0
uint64_t fde_func_03949_0x271690(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00271690ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9014FF4ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91002014ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA1403E0ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x97FDA720ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #03958 | PC: 0x27190c..0x271944 (56 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x27190c: D503245F  bti      c
//   0x271910: AA0003E8  mov      x8, x0
//   0x271914: F944C800  ldr      x0, [x0, #0x990]
//   0x271918: B9001901  str      w1, [x8, #0x18]
//   0x27191c: B40000C0  cbz      x0, #0x271934
//   0x271920: 39407508  ldrb     w8, [x8, #0x1d]
uint64_t fde_func_03958_0x27190c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0027190CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003E8ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF944C800ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB9001901ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB40000C0ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x39407508ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x7100011FULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x52800A08ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #03968 | PC: 0x273e10..0x273e24 (20 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x273e10: D503245F  bti      c
//   0x273e14: AA1F03E1  mov      x1, xzr
//   0x273e18: AA1F03E2  mov      x2, xzr
//   0x273e1c: AA1F03E3  mov      x3, xzr
//   0x273e20: 17FFF6D9  b        #0x271984
uint64_t fde_func_03968_0x273e10(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00273E10ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA1F03E1ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA1F03E2ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA1F03E3ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x17FFF6D9ULL ^ (4ULL << 32);
    return state ^ (state >> 29);
}

// FDE #03977 | PC: 0x27403c..0x27409c (96 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x27403c: D503233F  paciasp  
//   0x274040: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x274044: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x274048: 910003FD  mov      x29, sp
//   0x27404c: F9400008  ldr      x8, [x0]
//   0x274050: AA0003F4  mov      x20, x0
uint64_t fde_func_03977_0x27403c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0027403CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9014FF4ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400008ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F4ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0103F3ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xEB01011FULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #03987 | PC: 0x274a08..0x274ac4 (188 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x274a08: D503233F  paciasp  
//   0x274a0c: A9BC7BFD  stp      x29, x30, [sp, #-0x40]!
//   0x274a10: F9000BF7  str      x23, [sp, #0x10]
//   0x274a14: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x274a18: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x274a1c: 910003FD  mov      x29, sp
uint64_t fde_func_03987_0x274a08(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00274A08ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BC7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF7ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90257F6ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9034FF4ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0203F4ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0103F3ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #03996 | PC: 0x275678..0x275748 (208 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x275678: D503233F  paciasp  
//   0x27567c: D10183FF  sub      sp, sp, #0x60
//   0x275680: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x275684: A9035FF8  stp      x24, x23, [sp, #0x30]
//   0x275688: A90457F6  stp      x22, x21, [sp, #0x40]
//   0x27568c: A9054FF4  stp      x20, x19, [sp, #0x50]
uint64_t fde_func_03996_0x275678(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00275678ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10183FFULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9027BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9035FF8ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90457F6ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9054FF4ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910083FDULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910023E8ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #04006 | PC: 0x27589c..0x27599c (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x27589c: D503233F  paciasp  
//   0x2758a0: D101C3FF  sub      sp, sp, #0x70
//   0x2758a4: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x2758a8: F9001BF9  str      x25, [sp, #0x30]
//   0x2758ac: A9045FF8  stp      x24, x23, [sp, #0x40]
//   0x2758b0: A90557F6  stp      x22, x21, [sp, #0x50]
uint64_t fde_func_04006_0x27589c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0027589CULL);
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

// FDE #04015 | PC: 0x275b0c..0x275b3c (48 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x275b0c: D503233F  paciasp  
//   0x275b10: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x275b14: F9000BF3  str      x19, [sp, #0x10]
//   0x275b18: 910003FD  mov      x29, sp
//   0x275b1c: AA0003F3  mov      x19, x0
//   0x275b20: 91034000  add      x0, x0, #0xd0
uint64_t fde_func_04015_0x275b0c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00275B0CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF3ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91034000ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x94000006ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA1303E0ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #04025 | PC: 0x275db8..0x275e04 (76 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x275db8: D503245F  bti      c
//   0x275dbc: B4000220  cbz      x0, #0x275e00
//   0x275dc0: D503233F  paciasp  
//   0x275dc4: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x275dc8: F9000BF3  str      x19, [sp, #0x10]
//   0x275dcc: 910003FD  mov      x29, sp
uint64_t fde_func_04025_0x275db8(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00275DB8ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB4000220ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE7BFDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF3ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400000ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #04034 | PC: 0x276120..0x2761dc (188 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x276120: D503233F  paciasp  
//   0x276124: A9BB7BFD  stp      x29, x30, [sp, #-0x50]!
//   0x276128: F9000BF9  str      x25, [sp, #0x10]
//   0x27612c: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x276130: A90357F6  stp      x22, x21, [sp, #0x30]
//   0x276134: A9044FF4  stp      x20, x19, [sp, #0x40]
uint64_t fde_func_04034_0x276120(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00276120ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BB7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF9ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9025FF8ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90357F6ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9044FF4ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F8ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #04044 | PC: 0x27683c..0x2768bc (128 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x27683c: D503233F  paciasp  
//   0x276840: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x276844: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x276848: 910003FD  mov      x29, sp
//   0x27684c: F9404413  ldr      x19, [x0, #0x88]
//   0x276850: B4000253  cbz      x19, #0x276898
uint64_t fde_func_04044_0x27683c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0027683CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9014FF4ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9404413ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB4000253ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x2A0103F4ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9401C3C0ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #04053 | PC: 0x276edc..0x276f28 (76 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x276edc: D503233F  paciasp  
//   0x276ee0: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x276ee4: F9000BF3  str      x19, [sp, #0x10]
//   0x276ee8: 910003FD  mov      x29, sp
//   0x276eec: AA0003F3  mov      x19, x0
//   0x276ef0: 52800600  mov      w0, #0x30
uint64_t fde_func_04053_0x276edc(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00276EDCULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF3ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x52800600ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x940195A0ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x6F00E400ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #04063 | PC: 0x277b74..0x277c74 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x277b74: D503233F  paciasp  
//   0x277b78: D104C3FF  sub      sp, sp, #0x130
//   0x277b7c: A90E7BFD  stp      x29, x30, [sp, #0xe0]
//   0x277b80: F9007BFC  str      x28, [sp, #0xf0]
//   0x277b84: A9105FF8  stp      x24, x23, [sp, #0x100]
//   0x277b88: A91157F6  stp      x22, x21, [sp, #0x110]
uint64_t fde_func_04063_0x277b74(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00277B74ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD104C3FFULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90E7BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9007BFCULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9105FF8ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA91157F6ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9124FF4ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910383FDULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #04072 | PC: 0x278574..0x278580 (12 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x278574: D503245F  bti      c
//   0x278578: 9102E000  add      x0, x0, #0xb8
//   0x27857c: 14000A16  b        #0x27add4
uint64_t fde_func_04072_0x278574(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00278574ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9102E000ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x14000A16ULL ^ (2ULL << 32);
    return state ^ (state >> 29);
}

// FDE #04082 | PC: 0x27861c..0x278628 (12 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x27861c: D503245F  bti      c
//   0x278620: 91026000  add      x0, x0, #0x98
//   0x278624: 14000984  b        #0x27ac34
uint64_t fde_func_04082_0x27861c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0027861CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91026000ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x14000984ULL ^ (2ULL << 32);
    return state ^ (state >> 29);
}

// FDE #04091 | PC: 0x2787ec..0x2787f8 (12 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x2787ec: D503245F  bti      c
//   0x2787f0: AA1F03E1  mov      x1, xzr
//   0x2787f4: 17FFFFD3  b        #0x278740
uint64_t fde_func_04091_0x2787ec(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x002787ECULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA1F03E1ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x17FFFFD3ULL ^ (2ULL << 32);
    return state ^ (state >> 29);
}

// FDE #04101 | PC: 0x279694..0x2796a8 (20 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x279694: D503245F  bti      c
//   0x279698: 90001908  adrp     x8, #0x599000
//   0x27969c: 910D4108  add      x8, x8, #0x350
//   0x2796a0: F8008408  str      x8, [x0], #8
//   0x2796a4: 140C35FB  b        #0x586e90
uint64_t fde_func_04101_0x279694(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00279694ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x90001908ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910D4108ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF8008408ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x140C35FBULL ^ (4ULL << 32);
    return state ^ (state >> 29);
}

// FDE #04110 | PC: 0x279948..0x27998c (68 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x279948: D503245F  bti      c
//   0x27994c: B40001E0  cbz      x0, #0x279988
//   0x279950: D503233F  paciasp  
//   0x279954: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x279958: F9000BF3  str      x19, [sp, #0x10]
//   0x27995c: 910003FD  mov      x29, sp
uint64_t fde_func_04110_0x279948(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00279948ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB40001E0ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE7BFDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF3ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9101C000ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #04120 | PC: 0x279d7c..0x279d94 (24 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x279d7c: D503245F  bti      c
//   0x279d80: 9100A008  add      x8, x0, #0x28
//   0x279d84: 91010001  add      x1, x0, #0x40
//   0x279d88: F9401010  ldr      x16, [x0, #0x20]
//   0x279d8c: AA0803E0  mov      x0, x8
//   0x279d90: D61F0200  br       x16
uint64_t fde_func_04120_0x279d7c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00279D7CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9100A008ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91010001ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9401010ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0803E0ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD61F0200ULL ^ (5ULL << 32);
    return state ^ (state >> 29);
}

// FDE #04129 | PC: 0x27a0f0..0x27a120 (48 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x27a0f0: D503233F  paciasp  
//   0x27a0f4: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x27a0f8: F9000BF3  str      x19, [sp, #0x10]
//   0x27a0fc: 910003FD  mov      x29, sp
//   0x27a100: AA0003F3  mov      x19, x0
//   0x27a104: 9100E000  add      x0, x0, #0x38
uint64_t fde_func_04129_0x27a0f0(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0027A0F0ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF3ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9100E000ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x97FD37E9ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA1303E0ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #04139 | PC: 0x27a850..0x27a89c (76 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x27a850: D503233F  paciasp  
//   0x27a854: A9BD7BFD  stp      x29, x30, [sp, #-0x30]!
//   0x27a858: F9000BF5  str      x21, [sp, #0x10]
//   0x27a85c: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x27a860: 910003FD  mov      x29, sp
//   0x27a864: A9405015  ldp      x21, x20, [x0]
uint64_t fde_func_04139_0x27a850(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0027A850ULL);
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

// FDE #04148 | PC: 0x27b168..0x27b260 (248 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x27b168: D503233F  paciasp  
//   0x27b16c: A9BC7BFD  stp      x29, x30, [sp, #-0x40]!
//   0x27b170: F9000BF7  str      x23, [sp, #0x10]
//   0x27b174: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x27b178: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x27b17c: 910003FD  mov      x29, sp
uint64_t fde_func_04148_0x27b168(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0027B168ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BC7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF7ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90257F6ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9034FF4ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F4ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #04158 | PC: 0x27c2a4..0x27c318 (116 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x27c2a4: D503245F  bti      c
//   0x27c2a8: 51032028  sub      w8, w1, #0xc8
//   0x27c2ac: 7100111F  cmp      w8, #4
//   0x27c2b0: 54000148  b.hi     #0x27c2d8
//   0x27c2b4: F0FFEFE9  adrp     x9, #0x7b000
//   0x27c2b8: 9126B129  add      x9, x9, #0x9ac
uint64_t fde_func_04158_0x27c2a4(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0027C2A4ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x51032028ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x7100111FULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x54000148ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF0FFEFE9ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9126B129ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x1000008AULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x3868692BULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #04168 | PC: 0x27c574..0x27c580 (12 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x27c574: D503245F  bti      c
//   0x27c578: 9103C000  add      x0, x0, #0xf0
//   0x27c57c: D65F03C0  ret      
uint64_t fde_func_04168_0x27c574(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0027C574ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9103C000ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD65F03C0ULL ^ (2ULL << 32);
    return state ^ (state >> 29);
}

// FDE #04177 | PC: 0x27c5f0..0x27c5fc (12 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x27c5f0: D503245F  bti      c
//   0x27c5f4: D1004000  sub      x0, x0, #0x10
//   0x27c5f8: 17FFFFBE  b        #0x27c4f0
uint64_t fde_func_04177_0x27c5f0(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0027C5F0ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD1004000ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x17FFFFBEULL ^ (2ULL << 32);
    return state ^ (state >> 29);
}

// FDE #04187 | PC: 0x27c95c..0x27c9c4 (104 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x27c95c: D503233F  paciasp  
//   0x27c960: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x27c964: F9000BF3  str      x19, [sp, #0x10]
//   0x27c968: 910003FD  mov      x29, sp
//   0x27c96c: AA0003E8  mov      x8, x0
//   0x27c970: F940A400  ldr      x0, [x0, #0x148]
uint64_t fde_func_04187_0x27c95c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0027C95CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF3ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003E8ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF940A400ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB40000A0ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400BF3ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #04196 | PC: 0x27ccd0..0x27cdd0 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x27ccd0: D503233F  paciasp  
//   0x27ccd4: D10143FF  sub      sp, sp, #0x50
//   0x27ccd8: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x27ccdc: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x27cce0: A90357F6  stp      x22, x21, [sp, #0x30]
//   0x27cce4: A9044FF4  stp      x20, x19, [sp, #0x40]
uint64_t fde_func_04196_0x27ccd0(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0027CCD0ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10143FFULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9025FF8ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90357F6ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9044FF4ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB4000A21ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #04206 | PC: 0x27db28..0x27dbb8 (144 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x27db28: D503233F  paciasp  
//   0x27db2c: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x27db30: F9000BF3  str      x19, [sp, #0x10]
//   0x27db34: 910003FD  mov      x29, sp
//   0x27db38: 7105183F  cmp      w1, #0x146
//   0x27db3c: 540000E1  b.ne     #0x27db58
uint64_t fde_func_04206_0x27db28(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0027DB28ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF3ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x7105183FULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x540000E1ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x39690009ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x37000169ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #04215 | PC: 0x27e338..0x27e35c (36 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x27e338: D503245F  bti      c
//   0x27e33c: 12805888  mov      w8, #-0x2c5
//   0x27e340: 3100083F  cmn      w1, #2
//   0x27e344: 12805789  mov      w9, #-0x2bd
//   0x27e348: 1A880128  csel     w8, w9, w8, eq
//   0x27e34c: 3100043F  cmn      w1, #1
uint64_t fde_func_04215_0x27e338(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0027E338ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x12805888ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x3100083FULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x12805789ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x1A880128ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x3100043FULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x12805769ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x1A880121ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #04225 | PC: 0x27e57c..0x27e588 (12 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x27e57c: D503245F  bti      c
//   0x27e580: D1004000  sub      x0, x0, #0x10
//   0x27e584: 17FFFF69  b        #0x27e328
uint64_t fde_func_04225_0x27e57c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0027E57CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD1004000ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x17FFFF69ULL ^ (2ULL << 32);
    return state ^ (state >> 29);
}

// FDE #04234 | PC: 0x27f534..0x27f5b4 (128 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x27f534: D503233F  paciasp  
//   0x27f538: D100C3FF  sub      sp, sp, #0x30
//   0x27f53c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x27f540: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x27f544: 910043FD  add      x29, sp, #0x10
//   0x27f548: AA0003F4  mov      x20, x0
uint64_t fde_func_04234_0x27f534(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0027F534ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD100C3FFULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9024FF4ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F4ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x52800900ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0103F3ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #04244 | PC: 0x27fa94..0x27fab0 (28 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x27fa94: D503245F  bti      c
//   0x27fa98: AA0003E8  mov      x8, x0
//   0x27fa9c: F9402400  ldr      x0, [x0, #0x48]
//   0x27faa0: D00018C9  adrp     x9, #0x599000
//   0x27faa4: 911CC129  add      x9, x9, #0x730
//   0x27faa8: F9000109  str      x9, [x8]
uint64_t fde_func_04244_0x27fa94(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0027FA94ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003E8ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9402400ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD00018C9ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x911CC129ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000109ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x17FEDF03ULL ^ (6ULL << 32);
    return state ^ (state >> 29);
}

// FDE #04253 | PC: 0x27fc78..0x27fd68 (240 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x27fc78: D503233F  paciasp  
//   0x27fc7c: A9BC7BFD  stp      x29, x30, [sp, #-0x40]!
//   0x27fc80: F9000BF7  str      x23, [sp, #0x10]
//   0x27fc84: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x27fc88: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x27fc8c: 910003FD  mov      x29, sp
uint64_t fde_func_04253_0x27fc78(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0027FC78ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BC7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF7ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90257F6ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9034FF4ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x7200005FULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x52800208ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #04263 | PC: 0x280324..0x280394 (112 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x280324: D503233F  paciasp  
//   0x280328: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x28032c: F9000BF3  str      x19, [sp, #0x10]
//   0x280330: 910003FD  mov      x29, sp
//   0x280334: AA0003F3  mov      x19, x0
//   0x280338: F941E808  ldr      x8, [x0, #0x3d0]
uint64_t fde_func_04263_0x280324(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00280324ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF3ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF941E808ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB4000068ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA1303E0ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #04272 | PC: 0x280eec..0x280fec (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x280eec: D503233F  paciasp  
//   0x280ef0: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x280ef4: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x280ef8: 910003FD  mov      x29, sp
//   0x280efc: AA0003F3  mov      x19, x0
//   0x280f00: 3100083F  cmn      w1, #2
uint64_t fde_func_04272_0x280eec(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00280EECULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9014FF4ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x3100083FULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x540000ACULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF941EE60ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #04282 | PC: 0x281498..0x28150c (116 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x281498: D503233F  paciasp  
//   0x28149c: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x2814a0: F9000BF3  str      x19, [sp, #0x10]
//   0x2814a4: 910003FD  mov      x29, sp
//   0x2814a8: AA0003F3  mov      x19, x0
//   0x2814ac: 52800028  mov      w8, #1
uint64_t fde_func_04282_0x281498(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00281498ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF3ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x52800028ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x7100043FULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x39080408ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #04291 | PC: 0x281938..0x281968 (48 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x281938: D503245F  bti      c
//   0x28193c: 39402008  ldrb     w8, [x0, #8]
//   0x281940: 34000068  cbz      w8, #0x28194c
//   0x281944: 52800A00  mov      w0, #0x50
//   0x281948: D65F03C0  ret      
//   0x28194c: F944C008  ldr      x8, [x0, #0x980]
uint64_t fde_func_04291_0x281938(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00281938ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x39402008ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x34000068ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x52800A00ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD65F03C0ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF944C008ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9126C009ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9129610AULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #04301 | PC: 0x28345c..0x283468 (12 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x28345c: D503245F  bti      c
//   0x283460: AA1F03E1  mov      x1, xzr
//   0x283464: 14000001  b        #0x283468
uint64_t fde_func_04301_0x28345c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0028345CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA1F03E1ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x14000001ULL ^ (2ULL << 32);
    return state ^ (state >> 29);
}

// FDE #04310 | PC: 0x283ddc..0x283e60 (132 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x283ddc: D503233F  paciasp  
//   0x283de0: A9BD7BFD  stp      x29, x30, [sp, #-0x30]!
//   0x283de4: F9000BF5  str      x21, [sp, #0x10]
//   0x283de8: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x283dec: 910003FD  mov      x29, sp
//   0x283df0: AA0103F3  mov      x19, x1
uint64_t fde_func_04310_0x283ddc(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00283DDCULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BD7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF5ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9024FF4ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0103F3ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F4ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9139C000ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #04320 | PC: 0x2849e0..0x2849ec (12 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x2849e0: D503245F  bti      c
//   0x2849e4: D1004000  sub      x0, x0, #0x10
//   0x2849e8: 17FFFE84  b        #0x2843f8
uint64_t fde_func_04320_0x2849e0(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x002849E0ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD1004000ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x17FFFE84ULL ^ (2ULL << 32);
    return state ^ (state >> 29);
}

// FDE #04329 | PC: 0x284ba8..0x284bf4 (76 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x284ba8: D503245F  bti      c
//   0x284bac: B4000220  cbz      x0, #0x284bf0
//   0x284bb0: D503233F  paciasp  
//   0x284bb4: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x284bb8: F9000BF3  str      x19, [sp, #0x10]
//   0x284bbc: 910003FD  mov      x29, sp
uint64_t fde_func_04329_0x284ba8(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00284BA8ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB4000220ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE7BFDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF3ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400000ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #04339 | PC: 0x2851e8..0x285224 (60 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x2851e8: D503233F  paciasp  
//   0x2851ec: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x2851f0: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x2851f4: 910003FD  mov      x29, sp
//   0x2851f8: AA0003F4  mov      x20, x0
//   0x2851fc: AA0003F3  mov      x19, x0
uint64_t fde_func_04339_0x2851e8(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x002851E8ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9014FF4ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F4ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF8408E80ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x97FFFE69ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #04348 | PC: 0x285868..0x2858d4 (108 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x285868: D503233F  paciasp  
//   0x28586c: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x285870: F9000BF3  str      x19, [sp, #0x10]
//   0x285874: 910003FD  mov      x29, sp
//   0x285878: AA0003F3  mov      x19, x0
//   0x28587c: 91024000  add      x0, x0, #0x90
uint64_t fde_func_04348_0x285868(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00285868ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF3ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91024000ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x900018A8ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91294108ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #04358 | PC: 0x286714..0x2867a4 (144 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x286714: D503233F  paciasp  
//   0x286718: A9BD7BFD  stp      x29, x30, [sp, #-0x30]!
//   0x28671c: F9000BF5  str      x21, [sp, #0x10]
//   0x286720: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x286724: 910003FD  mov      x29, sp
//   0x286728: 39400028  ldrb     w8, [x1]
uint64_t fde_func_04358_0x286714(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00286714ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BD7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF5ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9024FF4ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x39400028ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0203F3ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400829ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #04367 | PC: 0x286b14..0x286b40 (44 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x286b14: D503233F  paciasp  
//   0x286b18: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x286b1c: F9000BF3  str      x19, [sp, #0x10]
//   0x286b20: 910003FD  mov      x29, sp
//   0x286b24: AA0003F3  mov      x19, x0
//   0x286b28: 97FFFFF6  bl       #0x286b00
uint64_t fde_func_04367_0x286b14(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00286B14ULL);
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

// FDE #04377 | PC: 0x287e8c..0x287f80 (244 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x287e8c: D503233F  paciasp  
//   0x287e90: D10183FF  sub      sp, sp, #0x60
//   0x287e94: A9037BFD  stp      x29, x30, [sp, #0x30]
//   0x287e98: F90023F5  str      x21, [sp, #0x40]
//   0x287e9c: A9054FF4  stp      x20, x19, [sp, #0x50]
//   0x287ea0: 9100C3FD  add      x29, sp, #0x30
uint64_t fde_func_04377_0x287e8c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00287E8CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10183FFULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9037BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF90023F5ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9054FF4ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9100C3FDULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x913A4014ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #04386 | PC: 0x2883cc..0x2884bc (240 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x2883cc: D503233F  paciasp  
//   0x2883d0: A9BC7BFD  stp      x29, x30, [sp, #-0x40]!
//   0x2883d4: F9000BF7  str      x23, [sp, #0x10]
//   0x2883d8: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x2883dc: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x2883e0: 910003FD  mov      x29, sp
uint64_t fde_func_04386_0x2883cc(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x002883CCULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BC7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF7ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90257F6ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9034FF4ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x52800028ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9139D409ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #04396 | PC: 0x288914..0x288920 (12 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x288914: D503245F  bti      c
//   0x288918: D1004000  sub      x0, x0, #0x10
//   0x28891c: 17FFFACC  b        #0x28744c
uint64_t fde_func_04396_0x288914(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00288914ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD1004000ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x17FFFACCULL ^ (2ULL << 32);
    return state ^ (state >> 29);
}

// FDE #04405 | PC: 0x288994..0x2889a0 (12 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x288994: D503245F  bti      c
//   0x288998: D1004000  sub      x0, x0, #0x10
//   0x28899c: 17FFFDF4  b        #0x28816c
uint64_t fde_func_04405_0x288994(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00288994ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD1004000ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x17FFFDF4ULL ^ (2ULL << 32);
    return state ^ (state >> 29);
}

// FDE #04415 | PC: 0x288b18..0x288c18 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x288b18: D503233F  paciasp  
//   0x288b1c: D10603FF  sub      sp, sp, #0x180
//   0x288b20: A9147BFD  stp      x29, x30, [sp, #0x140]
//   0x288b24: F900ABFC  str      x28, [sp, #0x150]
//   0x288b28: A91657F6  stp      x22, x21, [sp, #0x160]
//   0x288b2c: A9174FF4  stp      x20, x19, [sp, #0x170]
uint64_t fde_func_04415_0x288b18(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00288B18ULL);
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

// FDE #04424 | PC: 0x28a278..0x28a33c (196 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x28a278: D503233F  paciasp  
//   0x28a27c: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x28a280: F9000BF3  str      x19, [sp, #0x10]
//   0x28a284: 910003FD  mov      x29, sp
//   0x28a288: 9139A408  add      x8, x0, #0xe69
//   0x28a28c: AA0003F3  mov      x19, x0
uint64_t fde_func_04424_0x28a278(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0028A278ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF3ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9139A408ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x08DFFD08ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x360000E8ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #04434 | PC: 0x28a96c..0x28a9f8 (140 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x28a96c: D503233F  paciasp  
//   0x28a970: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x28a974: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x28a978: 910003FD  mov      x29, sp
//   0x28a97c: 52801300  mov      w0, #0x98
//   0x28a980: 940146FD  bl       #0x2dc574
uint64_t fde_func_04434_0x28a96c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0028A96CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9014FF4ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x52801300ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x940146FDULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF0001868ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #04443 | PC: 0x28ade0..0x28ae38 (88 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x28ade0: D503233F  paciasp  
//   0x28ade4: D10103FF  sub      sp, sp, #0x40
//   0x28ade8: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x28adec: F9001BF3  str      x19, [sp, #0x30]
//   0x28adf0: 910083FD  add      x29, sp, #0x20
//   0x28adf4: AA0203F3  mov      x19, x2
uint64_t fde_func_04443_0x28ade0(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0028ADE0ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10103FFULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9027BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9001BF3ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910083FDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0203F3ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003E2ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910023E0ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #04453 | PC: 0x28b25c..0x28b2d4 (120 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x28b25c: D503245F  bti      c
//   0x28b260: A9402009  ldp      x9, x8, [x0]
//   0x28b264: CB090108  sub      x8, x8, x9
//   0x28b268: F100211F  cmp      x8, #8
//   0x28b26c: 540002E3  b.lo     #0x28b2c8
//   0x28b270: F0FFEF6A  adrp     x10, #0x7a000
uint64_t fde_func_04453_0x28b25c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0028B25CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9402009ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xCB090108ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF100211FULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x540002E3ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF0FFEF6AULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x4E080C21ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x3DC2C540ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #04463 | PC: 0x28b588..0x28b600 (120 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x28b588: D503233F  paciasp  
//   0x28b58c: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x28b590: F9000BF3  str      x19, [sp, #0x10]
//   0x28b594: 910003FD  mov      x29, sp
//   0x28b598: AA0003F3  mov      x19, x0
//   0x28b59c: B40000E1  cbz      x1, #0x28b5b8
uint64_t fde_func_04463_0x28b588(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0028B588ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF3ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB40000E1ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x885F7C28ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x11000509ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #04472 | PC: 0x28bd70..0x28be08 (152 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x28bd70: D503233F  paciasp  
//   0x28bd74: D10103FF  sub      sp, sp, #0x40
//   0x28bd78: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x28bd7c: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x28bd80: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x28bd84: 910043FD  add      x29, sp, #0x10
uint64_t fde_func_04472_0x28bd70(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0028BD70ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10103FFULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90257F6ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9034FF4ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0203F6ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0103E2ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #04482 | PC: 0x28c420..0x28c4ac (140 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x28c420: D503233F  paciasp  
//   0x28c424: D10143FF  sub      sp, sp, #0x50
//   0x28c428: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x28c42c: A90357F6  stp      x22, x21, [sp, #0x30]
//   0x28c430: A9044FF4  stp      x20, x19, [sp, #0x40]
//   0x28c434: 910083FD  add      x29, sp, #0x20
uint64_t fde_func_04482_0x28c420(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0028C420ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10143FFULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9027BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90357F6ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9044FF4ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910083FDULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910023E0ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #04491 | PC: 0x28c86c..0x28c8d4 (104 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x28c86c: D503233F  paciasp  
//   0x28c870: D10103FF  sub      sp, sp, #0x40
//   0x28c874: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x28c878: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x28c87c: 910083FD  add      x29, sp, #0x20
//   0x28c880: AA0103F3  mov      x19, x1
uint64_t fde_func_04491_0x28c86c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0028C86CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10103FFULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9027BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9034FF4ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910083FDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0103F3ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F4ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x36000162ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #04501 | PC: 0x28cf2c..0x28cf7c (80 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x28cf2c: D503233F  paciasp  
//   0x28cf30: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x28cf34: F9000BF3  str      x19, [sp, #0x10]
//   0x28cf38: 910003FD  mov      x29, sp
//   0x28cf3c: F9400013  ldr      x19, [x0]
//   0x28cf40: F900001F  str      xzr, [x0]
uint64_t fde_func_04501_0x28cf2c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0028CF2CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF3ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400013ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF900001FULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB4000153ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA1303E0ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #04510 | PC: 0x28d4dc..0x28d518 (60 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x28d4dc: D503233F  paciasp  
//   0x28d4e0: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x28d4e4: F9000BF3  str      x19, [sp, #0x10]
//   0x28d4e8: 910003FD  mov      x29, sp
//   0x28d4ec: AA0003F3  mov      x19, x0
//   0x28d4f0: F9400800  ldr      x0, [x0, #0x10]
uint64_t fde_func_04510_0x28d4dc(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0028D4DCULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF3ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400800ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x90001868ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91340108ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #04520 | PC: 0x28daf8..0x28db30 (56 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x28daf8: D503233F  paciasp  
//   0x28dafc: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x28db00: F9000BF3  str      x19, [sp, #0x10]
//   0x28db04: 910003FD  mov      x29, sp
//   0x28db08: AA0003F3  mov      x19, x0
//   0x28db0c: F9402400  ldr      x0, [x0, #0x48]
uint64_t fde_func_04520_0x28daf8(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0028DAF8ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF3ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9402400ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x94000008ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91006260ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #04529 | PC: 0x28df00..0x28e000 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x28df00: D503233F  paciasp  
//   0x28df04: D10283FF  sub      sp, sp, #0xa0
//   0x28df08: A9047BFD  stp      x29, x30, [sp, #0x40]
//   0x28df0c: F9002BFB  str      x27, [sp, #0x50]
//   0x28df10: A90667FA  stp      x26, x25, [sp, #0x60]
//   0x28df14: A9075FF8  stp      x24, x23, [sp, #0x70]
uint64_t fde_func_04529_0x28df00(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0028DF00ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10283FFULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9047BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9002BFBULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90667FAULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9075FF8ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90857F6ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9094FF4ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #04539 | PC: 0x28e634..0x28e6c8 (148 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x28e634: D503233F  paciasp  
//   0x28e638: A9BB7BFD  stp      x29, x30, [sp, #-0x50]!
//   0x28e63c: F9000BF9  str      x25, [sp, #0x10]
//   0x28e640: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x28e644: A90357F6  stp      x22, x21, [sp, #0x30]
//   0x28e648: A9044FF4  stp      x20, x19, [sp, #0x40]
uint64_t fde_func_04539_0x28e634(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0028E634ULL);
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

// FDE #04548 | PC: 0x28eac4..0x28eb0c (72 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x28eac4: D503233F  paciasp  
//   0x28eac8: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x28eacc: F9000BF3  str      x19, [sp, #0x10]
//   0x28ead0: 910003FD  mov      x29, sp
//   0x28ead4: F9400013  ldr      x19, [x0]
//   0x28ead8: F900001F  str      xzr, [x0]
uint64_t fde_func_04548_0x28eac4(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0028EAC4ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF3ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400013ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF900001FULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB4000113ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA1303E0ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #04558 | PC: 0x28eeb0..0x28ef08 (88 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x28eeb0: D503233F  paciasp  
//   0x28eeb4: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x28eeb8: F9000BF3  str      x19, [sp, #0x10]
//   0x28eebc: 910003FD  mov      x29, sp
//   0x28eec0: AA0003F3  mov      x19, x0
//   0x28eec4: 940120B7  bl       #0x2d71a0
uint64_t fde_func_04558_0x28eeb0(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0028EEB0ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF3ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x940120B7ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x39404268ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x36000068ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #04567 | PC: 0x28f5f8..0x28f6f8 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x28f5f8: D503233F  paciasp  
//   0x28f5fc: D10283FF  sub      sp, sp, #0xa0
//   0x28f600: A9057BFD  stp      x29, x30, [sp, #0x50]
//   0x28f604: F90033F9  str      x25, [sp, #0x60]
//   0x28f608: A9075FF8  stp      x24, x23, [sp, #0x70]
//   0x28f60c: A90857F6  stp      x22, x21, [sp, #0x80]
uint64_t fde_func_04567_0x28f5f8(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0028F5F8ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10283FFULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9057BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF90033F9ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9075FF8ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90857F6ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9094FF4ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910143FDULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #04577 | PC: 0x28fe04..0x28fed4 (208 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x28fe04: D503233F  paciasp  
//   0x28fe08: D10143FF  sub      sp, sp, #0x50
//   0x28fe0c: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x28fe10: A90357F6  stp      x22, x21, [sp, #0x30]
//   0x28fe14: A9044FF4  stp      x20, x19, [sp, #0x40]
//   0x28fe18: 910083FD  add      x29, sp, #0x20
uint64_t fde_func_04577_0x28fe04(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0028FE04ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10143FFULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9027BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90357F6ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9044FF4ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910083FDULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB0FFF1C1ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91342821ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #04586 | PC: 0x2902b4..0x290348 (148 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x2902b4: D503233F  paciasp  
//   0x2902b8: D10083FF  sub      sp, sp, #0x20
//   0x2902bc: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x2902c0: 910043FD  add      x29, sp, #0x10
//   0x2902c4: F9400029  ldr      x9, [x1]
//   0x2902c8: F900003F  str      xzr, [x1]
uint64_t fde_func_04586_0x2902b4(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x002902B4ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10083FFULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400029ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF900003FULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003E8ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF940004AULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #04596 | PC: 0x2906c0..0x2907c0 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x2906c0: D503233F  paciasp  
//   0x2906c4: D10503FF  sub      sp, sp, #0x140
//   0x2906c8: A90E7BFD  stp      x29, x30, [sp, #0xe0]
//   0x2906cc: A90F6FFC  stp      x28, x27, [sp, #0xf0]
//   0x2906d0: A91067FA  stp      x26, x25, [sp, #0x100]
//   0x2906d4: A9115FF8  stp      x24, x23, [sp, #0x110]
uint64_t fde_func_04596_0x2906c0(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x002906C0ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10503FFULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90E7BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90F6FFCULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA91067FAULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9115FF8ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA91257F6ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9134FF4ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #04605 | PC: 0x290a40..0x290b40 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x290a40: D503233F  paciasp  
//   0x290a44: D10603FF  sub      sp, sp, #0x180
//   0x290a48: A9127BFD  stp      x29, x30, [sp, #0x120]
//   0x290a4c: F9009BFC  str      x28, [sp, #0x130]
//   0x290a50: A91467FA  stp      x26, x25, [sp, #0x140]
//   0x290a54: A9155FF8  stp      x24, x23, [sp, #0x150]
uint64_t fde_func_04605_0x290a40(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00290A40ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10603FFULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9127BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9009BFCULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA91467FAULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9155FF8ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA91657F6ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9174FF4ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #04615 | PC: 0x291168..0x291260 (248 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x291168: D503233F  paciasp  
//   0x29116c: D10183FF  sub      sp, sp, #0x60
//   0x291170: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x291174: A9035FF8  stp      x24, x23, [sp, #0x30]
//   0x291178: A90457F6  stp      x22, x21, [sp, #0x40]
//   0x29117c: A9054FF4  stp      x20, x19, [sp, #0x50]
uint64_t fde_func_04615_0x291168(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00291168ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10183FFULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9027BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9035FF8ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90457F6ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9054FF4ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910083FDULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F4ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #04624 | PC: 0x2918c4..0x29191c (88 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x2918c4: D503233F  paciasp  
//   0x2918c8: A9BD7BFD  stp      x29, x30, [sp, #-0x30]!
//   0x2918cc: F9000BF5  str      x21, [sp, #0x10]
//   0x2918d0: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x2918d4: 910003FD  mov      x29, sp
//   0x2918d8: AA0003F5  mov      x21, x0
uint64_t fde_func_04624_0x2918c4(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x002918C4ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BD7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF5ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9024FF4ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F5ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x52800300ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0203F3ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #04634 | PC: 0x291d14..0x291e14 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x291d14: D503233F  paciasp  
//   0x291d18: D10183FF  sub      sp, sp, #0x60
//   0x291d1c: A9037BFD  stp      x29, x30, [sp, #0x30]
//   0x291d20: A90457F6  stp      x22, x21, [sp, #0x40]
//   0x291d24: A9054FF4  stp      x20, x19, [sp, #0x50]
//   0x291d28: 9100C3FD  add      x29, sp, #0x30
uint64_t fde_func_04634_0x291d14(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00291D14ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10183FFULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9037BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90457F6ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9054FF4ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9100C3FDULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9405008ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x52800036ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #04643 | PC: 0x2923b0..0x292424 (116 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x2923b0: D503233F  paciasp  
//   0x2923b4: A9BD7BFD  stp      x29, x30, [sp, #-0x30]!
//   0x2923b8: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x2923bc: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x2923c0: 910003FD  mov      x29, sp
//   0x2923c4: AA0203F3  mov      x19, x2
uint64_t fde_func_04643_0x2923b0(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x002923B0ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BD7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90157F6ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9024FF4ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0203F3ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0103F5ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F4ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #04653 | PC: 0x2929c4..0x292a44 (128 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x2929c4: D503233F  paciasp  
//   0x2929c8: A9BD7BFD  stp      x29, x30, [sp, #-0x30]!
//   0x2929cc: F9000BF5  str      x21, [sp, #0x10]
//   0x2929d0: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x2929d4: 910003FD  mov      x29, sp
//   0x2929d8: F9400014  ldr      x20, [x0]
uint64_t fde_func_04653_0x2929c4(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x002929C4ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BD7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF5ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9024FF4ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400014ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB40002B4ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400408ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #04662 | PC: 0x292f20..0x293020 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x292f20: D503233F  paciasp  
//   0x292f24: D10203FF  sub      sp, sp, #0x80
//   0x292f28: A9037BFD  stp      x29, x30, [sp, #0x30]
//   0x292f2c: F90023F9  str      x25, [sp, #0x40]
//   0x292f30: A9055FF8  stp      x24, x23, [sp, #0x50]
//   0x292f34: A90657F6  stp      x22, x21, [sp, #0x60]
uint64_t fde_func_04662_0x292f20(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00292F20ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10203FFULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9037BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF90023F9ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9055FF8ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90657F6ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9074FF4ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9100C3FDULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #04672 | PC: 0x2934e8..0x2935e8 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x2934e8: D503233F  paciasp  
//   0x2934ec: D10203FF  sub      sp, sp, #0x80
//   0x2934f0: A9047BFD  stp      x29, x30, [sp, #0x40]
//   0x2934f4: A9055FF8  stp      x24, x23, [sp, #0x50]
//   0x2934f8: A90657F6  stp      x22, x21, [sp, #0x60]
//   0x2934fc: A9074FF4  stp      x20, x19, [sp, #0x70]
uint64_t fde_func_04672_0x2934e8(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x002934E8ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10203FFULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9047BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9055FF8ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90657F6ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9074FF4ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910103FDULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD53BD057ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #04681 | PC: 0x294208..0x294308 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x294208: D503233F  paciasp  
//   0x29420c: D101C3FF  sub      sp, sp, #0x70
//   0x294210: A9037BFD  stp      x29, x30, [sp, #0x30]
//   0x294214: F90023F7  str      x23, [sp, #0x40]
//   0x294218: A90557F6  stp      x22, x21, [sp, #0x50]
//   0x29421c: A9064FF4  stp      x20, x19, [sp, #0x60]
uint64_t fde_func_04681_0x294208(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00294208ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD101C3FFULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9037BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF90023F7ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90557F6ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9064FF4ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9100C3FDULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA941D829ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #04691 | PC: 0x2952cc..0x295340 (116 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x2952cc: D503233F  paciasp  
//   0x2952d0: A9BD7BFD  stp      x29, x30, [sp, #-0x30]!
//   0x2952d4: F9000BF5  str      x21, [sp, #0x10]
//   0x2952d8: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x2952dc: 910003FD  mov      x29, sp
//   0x2952e0: F9400015  ldr      x21, [x0]
uint64_t fde_func_04691_0x2952cc(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x002952CCULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BD7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF5ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9024FF4ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400015ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB4000255ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400414ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #04700 | PC: 0x2956f4..0x295740 (76 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x2956f4: D503233F  paciasp  
//   0x2956f8: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x2956fc: F9000BF3  str      x19, [sp, #0x10]
//   0x295700: 910003FD  mov      x29, sp
//   0x295704: AA0003F3  mov      x19, x0
//   0x295708: 91006000  add      x0, x0, #0x18
uint64_t fde_func_04700_0x2956f4(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x002956F4ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF3ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91006000ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA1F03E1ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x97FD7BEBULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #04710 | PC: 0x295f64..0x295fc4 (96 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x295f64: D503233F  paciasp  
//   0x295f68: A9BD7BFD  stp      x29, x30, [sp, #-0x30]!
//   0x295f6c: F9000BF5  str      x21, [sp, #0x10]
//   0x295f70: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x295f74: 910003FD  mov      x29, sp
//   0x295f78: F9400013  ldr      x19, [x0]
uint64_t fde_func_04710_0x295f64(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00295F64ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BD7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF5ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9024FF4ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400013ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF900001FULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB4000193ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #04719 | PC: 0x296820..0x296920 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x296820: D503233F  paciasp  
//   0x296824: D10183FF  sub      sp, sp, #0x60
//   0x296828: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x29682c: A9035FF8  stp      x24, x23, [sp, #0x30]
//   0x296830: A90457F6  stp      x22, x21, [sp, #0x40]
//   0x296834: A9054FF4  stp      x20, x19, [sp, #0x50]
uint64_t fde_func_04719_0x296820(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00296820ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10183FFULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9027BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9035FF8ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90457F6ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9054FF4ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910083FDULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0403F3ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #04729 | PC: 0x296f7c..0x296fe4 (104 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x296f7c: D503233F  paciasp  
//   0x296f80: D10143FF  sub      sp, sp, #0x50
//   0x296f84: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x296f88: F9001BF5  str      x21, [sp, #0x30]
//   0x296f8c: A9044FF4  stp      x20, x19, [sp, #0x40]
//   0x296f90: 910083FD  add      x29, sp, #0x20
uint64_t fde_func_04729_0x296f7c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00296F7CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10143FFULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9027BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9001BF5ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9044FF4ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910083FDULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910023E0ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #04738 | PC: 0x297664..0x2976a8 (68 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x297664: D503233F  paciasp  
//   0x297668: D100C3FF  sub      sp, sp, #0x30
//   0x29766c: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x297670: 910083FD  add      x29, sp, #0x20
//   0x297674: AA0103E2  mov      x2, x1
//   0x297678: 3DC00000  ldr      q0, [x0]
uint64_t fde_func_04738_0x297664(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00297664ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD100C3FFULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9027BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910083FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0103E2ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x3DC00000ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400808ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003E0ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #04748 | PC: 0x297eec..0x297fd8 (236 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x297eec: D503233F  paciasp  
//   0x297ef0: D10143FF  sub      sp, sp, #0x50
//   0x297ef4: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x297ef8: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x297efc: A90357F6  stp      x22, x21, [sp, #0x30]
//   0x297f00: A9044FF4  stp      x20, x19, [sp, #0x40]
uint64_t fde_func_04748_0x297eec(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00297EECULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10143FFULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9025FF8ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90357F6ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9044FF4ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0103F3ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #04758 | PC: 0x29852c..0x298570 (68 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x29852c: D503245F  bti      c
//   0x298530: F0001A28  adrp     x8, #0x5df000
//   0x298534: 911D0108  add      x8, x8, #0x740
//   0x298538: C8DFFD09  ldar     x9, [x8]
//   0x29853c: B40000C9  cbz      x9, #0x298554
//   0x298540: AA0003E8  mov      x8, x0
uint64_t fde_func_04758_0x29852c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0029852CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF0001A28ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x911D0108ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xC8DFFD09ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB40000C9ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003E8ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD1000422ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0903E0ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #04767 | PC: 0x298e4c..0x298eb0 (100 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x298e4c: D503233F  paciasp  
//   0x298e50: A9BD7BFD  stp      x29, x30, [sp, #-0x30]!
//   0x298e54: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x298e58: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x298e5c: 910003FD  mov      x29, sp
//   0x298e60: AA0303F3  mov      x19, x3
uint64_t fde_func_04767_0x298e4c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00298E4CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BD7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90157F6ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9024FF4ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0303F3ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x2A0203F4ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F5ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #04777 | PC: 0x299364..0x299464 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x299364: D503233F  paciasp  
//   0x299368: A9BC7BFD  stp      x29, x30, [sp, #-0x40]!
//   0x29936c: A9015FF8  stp      x24, x23, [sp, #0x10]
//   0x299370: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x299374: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x299378: 910003FD  mov      x29, sp
uint64_t fde_func_04777_0x299364(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00299364ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BC7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9015FF8ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90257F6ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9034FF4ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD285AD29ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x531D7028ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #04786 | PC: 0x299b78..0x299bc4 (76 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x299b78: D503233F  paciasp  
//   0x299b7c: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x299b80: F9000BF3  str      x19, [sp, #0x10]
//   0x299b84: 910003FD  mov      x29, sp
//   0x299b88: AA0003F3  mov      x19, x0
//   0x299b8c: 52800020  mov      w0, #1
uint64_t fde_func_04786_0x299b78(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00299B78ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF3ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x52800020ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9400000DULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91008269ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #04796 | PC: 0x299f6c..0x299fb0 (68 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x299f6c: D503233F  paciasp  
//   0x299f70: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x299f74: F9000BF3  str      x19, [sp, #0x10]
//   0x299f78: 910003FD  mov      x29, sp
//   0x299f7c: AA0003F3  mov      x19, x0
//   0x299f80: 97FFFE2B  bl       #0x29982c
uint64_t fde_func_04796_0x299f6c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00299F6CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF3ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x97FFFE2BULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB40000E0ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003E1ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #04805 | PC: 0x29a464..0x29a49c (56 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x29a464: D503245F  bti      c
//   0x29a468: F9400009  ldr      x9, [x0]
//   0x29a46c: 52800028  mov      w8, #1
//   0x29a470: 91001129  add      x9, x9, #4
//   0x29a474: 089FFD28  stlrb    w8, [x9]
//   0x29a478: F9400000  ldr      x0, [x0]
uint64_t fde_func_04805_0x29a464(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0029A464ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400009ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x52800028ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91001129ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x089FFD28ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400000ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB40000E0ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x885FFC08ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #04815 | PC: 0x29a80c..0x29a8dc (208 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x29a80c: D503233F  paciasp  
//   0x29a810: A9BD7BFD  stp      x29, x30, [sp, #-0x30]!
//   0x29a814: F9000BF5  str      x21, [sp, #0x10]
//   0x29a818: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x29a81c: 910003FD  mov      x29, sp
//   0x29a820: D0001A08  adrp     x8, #0x5dc000
uint64_t fde_func_04815_0x29a80c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0029A80CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BD7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF5ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9024FF4ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD0001A08ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9127C108ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x08DFFD08ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #04824 | PC: 0x29ac88..0x29acc0 (56 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x29ac88: D503245F  bti      c
//   0x29ac8c: B900541F  str      wzr, [x0, #0x54]
//   0x29ac90: 91016000  add      x0, x0, #0x58
//   0x29ac94: 39400028  ldrb     w8, [x1]
//   0x29ac98: F9400429  ldr      x9, [x1, #8]
//   0x29ac9c: D341FD0A  lsr      x10, x8, #1
uint64_t fde_func_04824_0x29ac88(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0029AC88ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB900541FULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91016000ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x39400028ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400429ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD341FD0AULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x7200011FULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9A890148ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #04834 | PC: 0x29b0b4..0x29b134 (128 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x29b0b4: D503233F  paciasp  
//   0x29b0b8: A9BD7BFD  stp      x29, x30, [sp, #-0x30]!
//   0x29b0bc: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x29b0c0: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x29b0c4: 910003FD  mov      x29, sp
//   0x29b0c8: AA0003F3  mov      x19, x0
uint64_t fde_func_04834_0x29b0b4(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0029B0B4ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BD7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90157F6ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9024FF4ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF8408E76ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB4000256ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #04843 | PC: 0x29b590..0x29b608 (120 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x29b590: D503233F  paciasp  
//   0x29b594: D10143FF  sub      sp, sp, #0x50
//   0x29b598: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x29b59c: F9001BF5  str      x21, [sp, #0x30]
//   0x29b5a0: A9044FF4  stp      x20, x19, [sp, #0x40]
//   0x29b5a4: 910083FD  add      x29, sp, #0x20
uint64_t fde_func_04843_0x29b590(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0029B590ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10143FFULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9027BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9001BF5ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9044FF4ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910083FDULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9405414ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #04853 | PC: 0x29be00..0x29beb0 (176 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x29be00: D503233F  paciasp  
//   0x29be04: 6DBC23E9  stp      d9, d8, [sp, #-0x40]!
//   0x29be08: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x29be0c: F90013F5  str      x21, [sp, #0x20]
//   0x29be10: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x29be14: 910043FD  add      x29, sp, #0x10
uint64_t fde_func_04853_0x29be00(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0029BE00ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x6DBC23E9ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF90013F5ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9034FF4ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD2E80A48ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x1E604008ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #04862 | PC: 0x29c220..0x29c320 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x29c220: D503233F  paciasp  
//   0x29c224: D105C3FF  sub      sp, sp, #0x170
//   0x29c228: A9147BFD  stp      x29, x30, [sp, #0x140]
//   0x29c22c: A91557FC  stp      x28, x21, [sp, #0x150]
//   0x29c230: A9164FF4  stp      x20, x19, [sp, #0x160]
//   0x29c234: 910503FD  add      x29, sp, #0x140
uint64_t fde_func_04862_0x29c220(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0029C220ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD105C3FFULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9147BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA91557FCULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9164FF4ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910503FDULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD53BD054ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #04872 | PC: 0x29cbbc..0x29ccbc (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x29cbbc: D503233F  paciasp  
//   0x29cbc0: D10143FF  sub      sp, sp, #0x50
//   0x29cbc4: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x29cbc8: F90013F7  str      x23, [sp, #0x20]
//   0x29cbcc: A90357F6  stp      x22, x21, [sp, #0x30]
//   0x29cbd0: A9044FF4  stp      x20, x19, [sp, #0x40]
uint64_t fde_func_04872_0x29cbbc(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0029CBBCULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10143FFULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF90013F7ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90357F6ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9044FF4ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400028ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #04881 | PC: 0x29d114..0x29d15c (72 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x29d114: D503245F  bti      c
//   0x29d118: B40000A1  cbz      x1, #0x29d12c
//   0x29d11c: A941A408  ldp      x8, x9, [x0, #0x18]
//   0x29d120: F9400108  ldr      x8, [x8]
//   0x29d124: B8697908  ldr      w8, [x8, x9, lsl #2]
//   0x29d128: B9000028  str      w8, [x1]
uint64_t fde_func_04881_0x29d114(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0029D114ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB40000A1ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA941A408ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400108ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB8697908ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB9000028ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB40000C2ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA941A408ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #04891 | PC: 0x29d684..0x29d784 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x29d684: D503233F  paciasp  
//   0x29d688: A9BC7BFD  stp      x29, x30, [sp, #-0x40]!
//   0x29d68c: F9000BF7  str      x23, [sp, #0x10]
//   0x29d690: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x29d694: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x29d698: 910003FD  mov      x29, sp
uint64_t fde_func_04891_0x29d684(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0029D684ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BC7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF7ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90257F6ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9034FF4ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA940A015ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #04900 | PC: 0x29dc48..0x29dce8 (160 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x29dc48: D503233F  paciasp  
//   0x29dc4c: A9BD7BFD  stp      x29, x30, [sp, #-0x30]!
//   0x29dc50: F9000BF5  str      x21, [sp, #0x10]
//   0x29dc54: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x29dc58: 910003FD  mov      x29, sp
//   0x29dc5c: AA0003F3  mov      x19, x0
uint64_t fde_func_04900_0x29dc48(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0029DC48ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BD7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF5ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9024FF4ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9007C1FULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF900081FULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #04910 | PC: 0x29e818..0x29e8bc (164 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x29e818: D503233F  paciasp  
//   0x29e81c: A9BC7BFD  stp      x29, x30, [sp, #-0x40]!
//   0x29e820: F9000BF7  str      x23, [sp, #0x10]
//   0x29e824: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x29e828: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x29e82c: 910003FD  mov      x29, sp
uint64_t fde_func_04910_0x29e818(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0029E818ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BC7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF7ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90257F6ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9034FF4ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0203F5ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0103F4ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #04919 | PC: 0x29ee40..0x29ee58 (24 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x29ee40: D503245F  bti      c
//   0x29ee44: 9100A008  add      x8, x0, #0x28
//   0x29ee48: F9402001  ldr      x1, [x0, #0x40]
//   0x29ee4c: F9401010  ldr      x16, [x0, #0x20]
//   0x29ee50: AA0803E0  mov      x0, x8
//   0x29ee54: D61F0200  br       x16
uint64_t fde_func_04919_0x29ee40(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0029EE40ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9100A008ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9402001ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9401010ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0803E0ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD61F0200ULL ^ (5ULL << 32);
    return state ^ (state >> 29);
}

// FDE #04929 | PC: 0x29f2d4..0x29f33c (104 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x29f2d4: D503233F  paciasp  
//   0x29f2d8: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x29f2dc: F9000BF3  str      x19, [sp, #0x10]
//   0x29f2e0: 910003FD  mov      x29, sp
//   0x29f2e4: AA0003F3  mov      x19, x0
//   0x29f2e8: 97FFFEFC  bl       #0x29eed8
uint64_t fde_func_04929_0x29f2d4(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0029F2D4ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF3ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x97FFFEFCULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9402001ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xEB08003FULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #04938 | PC: 0x29f7c0..0x29f818 (88 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x29f7c0: D503233F  paciasp  
//   0x29f7c4: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x29f7c8: F9000BF3  str      x19, [sp, #0x10]
//   0x29f7cc: 910003FD  mov      x29, sp
//   0x29f7d0: 39420029  ldrb     w9, [x1, #0x80]
//   0x29f7d4: 340000C9  cbz      w9, #0x29f7ec
uint64_t fde_func_04938_0x29f7c0(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0029F7C0ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF3ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x39420029ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x340000C9ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x2A1F03E0ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400BF3ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #04948 | PC: 0x29ffc0..0x2a0020 (96 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x29ffc0: D503245F  bti      c
//   0x29ffc4: AA0003E8  mov      x8, x0
//   0x29ffc8: B9404009  ldr      w9, [x0, #0x40]
//   0x29ffcc: 35000229  cbnz     w9, #0x2a0010
//   0x29ffd0: A9430108  ldp      x8, x0, [x8, #0x30]
//   0x29ffd4: B24107E9  mov      x9, #-0x7fffffffffffffff
uint64_t fde_func_04948_0x29ffc0(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0029FFC0ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003E8ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB9404009ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x35000229ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9430108ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB24107E9ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x8B09000AULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF100095FULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #04957 | PC: 0x2a0344..0x2a0428 (228 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x2a0344: D503233F  paciasp  
//   0x2a0348: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x2a034c: F9000BF3  str      x19, [sp, #0x10]
//   0x2a0350: 910003FD  mov      x29, sp
//   0x2a0354: AA0203E5  mov      x5, x2
//   0x2a0358: AA0003F3  mov      x19, x0
uint64_t fde_func_04957_0x2a0344(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x002A0344ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF3ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0203E5ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x39400008ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0103E6ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #04967 | PC: 0x2a06dc..0x2a072c (80 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x2a06dc: D503233F  paciasp  
//   0x2a06e0: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x2a06e4: 910003FD  mov      x29, sp
//   0x2a06e8: 900019E8  adrp     x8, #0x5dc000
//   0x2a06ec: 912AE108  add      x8, x8, #0xab8
//   0x2a06f0: 08DFFD08  ldarb    w8, [x8]
uint64_t fde_func_04967_0x2a06dc(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x002A06DCULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BF7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x900019E8ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x912AE108ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x08DFFD08ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x36000088ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA8C17BFDULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #04976 | PC: 0x2a0c3c..0x2a0cac (112 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x2a0c3c: D503233F  paciasp  
//   0x2a0c40: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x2a0c44: F9000BF3  str      x19, [sp, #0x10]
//   0x2a0c48: 910003FD  mov      x29, sp
//   0x2a0c4c: 90001A13  adrp     x19, #0x5e0000
//   0x2a0c50: 911A4273  add      x19, x19, #0x690
uint64_t fde_func_04976_0x2a0c3c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x002A0C3CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF3ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x90001A13ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x911A4273ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91001260ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x3900027FULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #04986 | PC: 0x2a0fd0..0x2a0ffc (44 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x2a0fd0: D503233F  paciasp  
//   0x2a0fd4: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x2a0fd8: 910003FD  mov      x29, sp
//   0x2a0fdc: 97FFFDC0  bl       #0x2a06dc
//   0x2a0fe0: 90001A08  adrp     x8, #0x5e0000
//   0x2a0fe4: F943A108  ldr      x8, [x8, #0x740]
uint64_t fde_func_04986_0x2a0fd0(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x002A0FD0ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BF7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x97FFFDC0ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x90001A08ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF943A108ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF100011FULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x1A9F07E0ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #04995 | PC: 0x2a14f4..0x2a151c (40 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x2a14f4: D503233F  paciasp  
//   0x2a14f8: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x2a14fc: 910003FD  mov      x29, sp
//   0x2a1500: 97FFFC77  bl       #0x2a06dc
//   0x2a1504: F00019E8  adrp     x8, #0x5e0000
//   0x2a1508: F943A108  ldr      x8, [x8, #0x740]
uint64_t fde_func_04995_0x2a14f4(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x002A14F4ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BF7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x97FFFC77ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF00019E8ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF943A108ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x39402500ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA8C17BFDULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #05005 | PC: 0x2a185c..0x2a18f0 (148 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x2a185c: D503245F  bti      c
//   0x2a1860: 52800028  mov      w8, #1
//   0x2a1864: F1000409  subs     x9, x0, #1
//   0x2a1868: 540003E0  b.eq     #0x2a18e4
//   0x2a186c: AA1F03EA  mov      x10, xzr
//   0x2a1870: 5280060B  mov      w11, #0x30
uint64_t fde_func_05005_0x2a185c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x002A185CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x52800028ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF1000409ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x540003E0ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA1F03EAULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x5280060BULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF00019CCULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x912B018CULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #05014 | PC: 0x2a1df4..0x2a1e5c (104 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x2a1df4: D503233F  paciasp  
//   0x2a1df8: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x2a1dfc: 910003FD  mov      x29, sp
//   0x2a1e00: 900019E8  adrp     x8, #0x5dd000
//   0x2a1e04: 91128108  add      x8, x8, #0x4a0
//   0x2a1e08: 08DFFD08  ldarb    w8, [x8]
uint64_t fde_func_05014_0x2a1df4(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x002A1DF4ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BF7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x900019E8ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91128108ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x08DFFD08ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x36000088ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA8C17BFDULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #05024 | PC: 0x2a24a8..0x2a2540 (152 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x2a24a8: D503233F  paciasp  
//   0x2a24ac: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x2a24b0: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x2a24b4: 910003FD  mov      x29, sp
//   0x2a24b8: AA0003F3  mov      x19, x0
//   0x2a24bc: 91002000  add      x0, x0, #8
uint64_t fde_func_05024_0x2a24a8(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x002A24A8ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9014FF4ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91002000ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0103F4ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x97FFDFF6ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #05033 | PC: 0x2a29a0..0x2a29b4 (20 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x2a29a0: D503245F  bti      c
//   0x2a29a4: 91008008  add      x8, x0, #0x20
//   0x2a29a8: 9100C001  add      x1, x0, #0x30
//   0x2a29ac: AA0803E0  mov      x0, x8
//   0x2a29b0: 14000034  b        #0x2a2a80
uint64_t fde_func_05033_0x2a29a0(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x002A29A0ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91008008ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9100C001ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0803E0ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x14000034ULL ^ (4ULL << 32);
    return state ^ (state >> 29);
}

// FDE #05043 | PC: 0x2a2e24..0x2a2e60 (60 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x2a2e24: D503233F  paciasp  
//   0x2a2e28: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x2a2e2c: F9000BF3  str      x19, [sp, #0x10]
//   0x2a2e30: 910003FD  mov      x29, sp
//   0x2a2e34: AA0003F3  mov      x19, x0
//   0x2a2e38: 97FFFBEF  bl       #0x2a1df4
uint64_t fde_func_05043_0x2a2e24(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x002A2E24ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF3ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x97FFFBEFULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF00019C0ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91124000ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #05052 | PC: 0x2a311c..0x2a3158 (60 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x2a311c: D503233F  paciasp  
//   0x2a3120: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x2a3124: 910003FD  mov      x29, sp
//   0x2a3128: 97FFFFA0  bl       #0x2a2fa8
//   0x2a312c: D00019C0  adrp     x0, #0x5dd000
//   0x2a3130: 91134000  add      x0, x0, #0x4d0
uint64_t fde_func_05052_0x2a311c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x002A311CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BF7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x97FFFFA0ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD00019C0ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91134000ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA1F03E1ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9400B23AULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #05062 | PC: 0x2a37fc..0x2a3888 (140 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x2a37fc: D503233F  paciasp  
//   0x2a3800: A9BD7BFD  stp      x29, x30, [sp, #-0x30]!
//   0x2a3804: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x2a3808: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x2a380c: 910003FD  mov      x29, sp
//   0x2a3810: F9400008  ldr      x8, [x0]
uint64_t fde_func_05062_0x2a37fc(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x002A37FCULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BD7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90157F6ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9024FF4ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400008ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xEB01011FULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x54000340ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #05072 | PC: 0x2a3f14..0x2a3f8c (120 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x2a3f14: D503233F  paciasp  
//   0x2a3f18: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x2a3f1c: 910003FD  mov      x29, sp
//   0x2a3f20: D00019C8  adrp     x8, #0x5dd000
//   0x2a3f24: 9114E108  add      x8, x8, #0x538
//   0x2a3f28: 08DFFD08  ldarb    w8, [x8]
uint64_t fde_func_05072_0x2a3f14(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x002A3F14ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BF7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD00019C8ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9114E108ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x08DFFD08ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x36000088ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA8C17BFDULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #05081 | PC: 0x2a4330..0x2a43e0 (176 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x2a4330: D503233F  paciasp  
//   0x2a4334: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x2a4338: F9000BF3  str      x19, [sp, #0x10]
//   0x2a433c: 910003FD  mov      x29, sp
//   0x2a4340: AA0103E8  mov      x8, x1
//   0x2a4344: 8B010001  add      x1, x0, x1
uint64_t fde_func_05081_0x2a4330(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x002A4330ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF3ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0103E8ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x8B010001ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB40001A8ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x39400009ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #05091 | PC: 0x2a48f4..0x2a49f4 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x2a48f4: D503233F  paciasp  
//   0x2a48f8: A9BC7BFD  stp      x29, x30, [sp, #-0x40]!
//   0x2a48fc: F9000BF7  str      x23, [sp, #0x10]
//   0x2a4900: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x2a4904: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x2a4908: 910003FD  mov      x29, sp
uint64_t fde_func_05091_0x2a48f4(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x002A48F4ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BC7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF7ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90257F6ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9034FF4ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xEB01001FULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x540004E0ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #05100 | PC: 0x2a4d8c..0x2a4df4 (104 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x2a4d8c: D503245F  bti      c
//   0x2a4d90: EB04003F  cmp      x1, x4
//   0x2a4d94: 54000062  b.hs     #0x2a4da0
//   0x2a4d98: 92800000  mov      x0, #-1
//   0x2a4d9c: D65F03C0  ret      
//   0x2a4da0: D503233F  paciasp  
uint64_t fde_func_05100_0x2a4d8c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x002A4D8CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xEB04003FULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x54000062ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x92800000ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD65F03C0ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BD7BFDULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF5ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #05110 | PC: 0x2a534c..0x2a544c (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x2a534c: D503233F  paciasp  
//   0x2a5350: D10583FF  sub      sp, sp, #0x160
//   0x2a5354: A9117BFD  stp      x29, x30, [sp, #0x110]
//   0x2a5358: A91267FC  stp      x28, x25, [sp, #0x120]
//   0x2a535c: A9135FF8  stp      x24, x23, [sp, #0x130]
//   0x2a5360: A91457F6  stp      x22, x21, [sp, #0x140]
uint64_t fde_func_05110_0x2a534c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x002A534CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10583FFULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9117BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA91267FCULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9135FF8ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA91457F6ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9154FF4ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910443FDULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #05119 | PC: 0x2a5a14..0x2a5a4c (56 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x2a5a14: D503233F  paciasp  
//   0x2a5a18: D10083FF  sub      sp, sp, #0x20
//   0x2a5a1c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x2a5a20: 910043FD  add      x29, sp, #0x10
//   0x2a5a24: AA0403E5  mov      x5, x4
//   0x2a5a28: 381FC3A3  sturb    w3, [x29, #-4]
uint64_t fde_func_05119_0x2a5a14(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x002A5A14ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10083FFULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0403E5ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x381FC3A3ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10013A3ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x52800024ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #05129 | PC: 0x2a638c..0x2a63e8 (92 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x2a638c: D503233F  paciasp  
//   0x2a6390: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x2a6394: 910003FD  mov      x29, sp
//   0x2a6398: F00019A8  adrp     x8, #0x5dd000
//   0x2a639c: 91164108  add      x8, x8, #0x590
//   0x2a63a0: 08DFFD08  ldarb    w8, [x8]
uint64_t fde_func_05129_0x2a638c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x002A638CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BF7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF00019A8ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91164108ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x08DFFD08ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x36000088ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA8C17BFDULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #05138 | PC: 0x2a68b8..0x2a69b8 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x2a68b8: D503245F  bti      c
//   0x2a68bc: B4000C21  cbz      x1, #0x2a6a40
//   0x2a68c0: 8B010408  add      x8, x0, x1, lsl #1
//   0x2a68c4: AA0003EB  mov      x11, x0
//   0x2a68c8: AA0003E9  mov      x9, x0
//   0x2a68cc: F240081F  tst      x0, #7
uint64_t fde_func_05138_0x2a68b8(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x002A68B8ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB4000C21ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x8B010408ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003EBULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003E9ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF240081FULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x540001E0ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF100043FULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #05148 | PC: 0x2a7368..0x2a739c (52 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x2a7368: D503245F  bti      c
//   0x2a736c: AA0203E8  mov      x8, x2
//   0x2a7370: AA0003E9  mov      x9, x0
//   0x2a7374: 3940002A  ldrb     w10, [x1]
//   0x2a7378: 3900012A  strb     w10, [x9]
//   0x2a737c: 340000EA  cbz      w10, #0x2a7398
uint64_t fde_func_05148_0x2a7368(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x002A7368ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0203E8ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003E9ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x3940002AULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x3900012AULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x340000EAULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF1000508ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91000529ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #05157 | PC: 0x2a7a84..0x2a7b58 (212 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x2a7a84: D503233F  paciasp  
//   0x2a7a88: A9BD7BFD  stp      x29, x30, [sp, #-0x30]!
//   0x2a7a8c: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x2a7a90: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x2a7a94: 910003FD  mov      x29, sp
//   0x2a7a98: AA0203F4  mov      x20, x2
uint64_t fde_func_05157_0x2a7a84(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x002A7A84ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BD7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90157F6ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9024FF4ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0203F4ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0103F5ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #05167 | PC: 0x2a829c..0x2a8330 (148 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x2a829c: D503245F  bti      c
//   0x2a82a0: B4000441  cbz      x1, #0x2a8328
//   0x2a82a4: 52840009  mov      w9, #0x2000
//   0x2a82a8: AA0003E8  mov      x8, x0
//   0x2a82ac: 52800020  mov      w0, #1
//   0x2a82b0: 72A00209  movk     w9, #0x10, lsl #16
uint64_t fde_func_05167_0x2a829c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x002A829CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB4000441ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x52840009ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003E8ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x52800020ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x72A00209ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x529FFFAAULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x128507EBULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #05176 | PC: 0x2a88d0..0x2a88fc (44 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x2a88d0: D503233F  paciasp  
//   0x2a88d4: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x2a88d8: F9000BF3  str      x19, [sp, #0x10]
//   0x2a88dc: 910003FD  mov      x29, sp
//   0x2a88e0: AA0003F3  mov      x19, x0
//   0x2a88e4: 97FFFFE2  bl       #0x2a886c
uint64_t fde_func_05176_0x2a88d0(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x002A88D0ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF3ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x97FFFFE2ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA1303E0ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400BF3ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #05186 | PC: 0x2a8cc8..0x2a8d48 (128 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x2a8cc8: D503233F  paciasp  
//   0x2a8ccc: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x2a8cd0: F9000BF3  str      x19, [sp, #0x10]
//   0x2a8cd4: 910003FD  mov      x29, sp
//   0x2a8cd8: AA0003F3  mov      x19, x0
//   0x2a8cdc: 885FFC28  ldaxr    w8, [x1]
uint64_t fde_func_05186_0x2a8cc8(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x002A8CC8ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF3ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x885FFC28ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x11000509ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x880A7C29ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #05195 | PC: 0x2a94b4..0x2a94f0 (60 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x2a94b4: D503233F  paciasp  
//   0x2a94b8: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x2a94bc: 910003FD  mov      x29, sp
//   0x2a94c0: 94001755  bl       #0x2af214
//   0x2a94c4: 900019A0  adrp     x0, #0x5dd000
//   0x2a94c8: 91184000  add      x0, x0, #0x610
uint64_t fde_func_05195_0x2a94b4(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x002A94B4ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BF7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x94001755ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x900019A0ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91184000ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9400993DULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB40000A0ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #05205 | PC: 0x2a9750..0x2a978c (60 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x2a9750: D503245F  bti      c
//   0x2a9754: F9400028  ldr      x8, [x1]
//   0x2a9758: B4000128  cbz      x8, #0x2a977c
//   0x2a975c: 91001108  add      x8, x8, #4
//   0x2a9760: AA0203E3  mov      x3, x2
//   0x2a9764: AA0103E2  mov      x2, x1
uint64_t fde_func_05205_0x2a9750(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x002A9750ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400028ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB4000128ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91001108ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0203E3ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0103E2ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x08DFFD08ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400429ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #05214 | PC: 0x2aa4dc..0x2aa5dc (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x2aa4dc: D503233F  paciasp  
//   0x2aa4e0: A9BC7BFD  stp      x29, x30, [sp, #-0x40]!
//   0x2aa4e4: F9000BF7  str      x23, [sp, #0x10]
//   0x2aa4e8: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x2aa4ec: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x2aa4f0: 910003FD  mov      x29, sp
uint64_t fde_func_05214_0x2aa4dc(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x002AA4DCULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BC7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF7ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90257F6ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9034FF4ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0103F7ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0203F5ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #05224 | PC: 0x2aad20..0x2aae20 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x2aad20: D503233F  paciasp  
//   0x2aad24: D10283FF  sub      sp, sp, #0xa0
//   0x2aad28: A9067BFD  stp      x29, x30, [sp, #0x60]
//   0x2aad2c: F9003BF7  str      x23, [sp, #0x70]
//   0x2aad30: A90857F6  stp      x22, x21, [sp, #0x80]
//   0x2aad34: A9094FF4  stp      x20, x19, [sp, #0x90]
uint64_t fde_func_05224_0x2aad20(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x002AAD20ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10283FFULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9067BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9003BF7ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90857F6ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9094FF4ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910183FDULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF941B417ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #05233 | PC: 0x2ab114..0x2ab138 (36 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x2ab114: D503245F  bti      c
//   0x2ab118: F9401809  ldr      x9, [x0, #0x30]
//   0x2ab11c: 91112008  add      x8, x0, #0x448
//   0x2ab120: F9419C0A  ldr      x10, [x0, #0x338]
//   0x2ab124: F900092A  str      x10, [x9, #0x10]
//   0x2ab128: F9419C09  ldr      x9, [x0, #0x338]
uint64_t fde_func_05233_0x2ab114(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x002AB114ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9401809ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91112008ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9419C0AULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF900092AULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9419C09ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xC89FFD09ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF901A01FULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #05243 | PC: 0x2ab354..0x2ab3e4 (144 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x2ab354: D503233F  paciasp  
//   0x2ab358: A9BD7BFD  stp      x29, x30, [sp, #-0x30]!
//   0x2ab35c: F9000BF5  str      x21, [sp, #0x10]
//   0x2ab360: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x2ab364: 910003FD  mov      x29, sp
//   0x2ab368: AA0003F5  mov      x21, x0
uint64_t fde_func_05243_0x2ab354(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x002AB354ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BD7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF5ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9024FF4ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F5ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x52801000ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0103F4ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #05252 | PC: 0x2ab61c..0x2ab638 (28 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x2ab61c: D503245F  bti      c
//   0x2ab620: AA0003E9  mov      x9, x0
//   0x2ab624: 2A0203E3  mov      w3, w2
//   0x2ab628: AA0803E0  mov      x0, x8
//   0x2ab62c: AA0103E2  mov      x2, x1
//   0x2ab630: AA0903E1  mov      x1, x9
uint64_t fde_func_05252_0x2ab61c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x002AB61CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003E9ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x2A0203E3ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0803E0ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0103E2ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0903E1ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x140003B6ULL ^ (6ULL << 32);
    return state ^ (state >> 29);
}

// FDE #05262 | PC: 0x2ac3f8..0x2ac414 (28 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x2ac3f8: D503245F  bti      c
//   0x2ac3fc: D1002009  sub      x9, x0, #8
//   0x2ac400: 2A0203E3  mov      w3, w2
//   0x2ac404: AA0103E2  mov      x2, x1
//   0x2ac408: AA0803E0  mov      x0, x8
//   0x2ac40c: AA0903E1  mov      x1, x9
uint64_t fde_func_05262_0x2ac3f8(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x002AC3F8ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD1002009ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x2A0203E3ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0103E2ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0803E0ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0903E1ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x1400003FULL ^ (6ULL << 32);
    return state ^ (state >> 29);
}

// FDE #05271 | PC: 0x2ac4c4..0x2ac4d0 (12 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x2ac4c4: D503245F  bti      c
//   0x2ac4c8: D1006000  sub      x0, x0, #0x18
//   0x2ac4cc: 17FFFF47  b        #0x2ac1e8
uint64_t fde_func_05271_0x2ac4c4(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x002AC4C4ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD1006000ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x17FFFF47ULL ^ (2ULL << 32);
    return state ^ (state >> 29);
}

// FDE #05281 | PC: 0x2ae2b4..0x2ae3b4 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x2ae2b4: D503233F  paciasp  
//   0x2ae2b8: A9BB7BFD  stp      x29, x30, [sp, #-0x50]!
//   0x2ae2bc: F9000BF9  str      x25, [sp, #0x10]
//   0x2ae2c0: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x2ae2c4: A90357F6  stp      x22, x21, [sp, #0x30]
//   0x2ae2c8: A9044FF4  stp      x20, x19, [sp, #0x40]
uint64_t fde_func_05281_0x2ae2b4(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x002AE2B4ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BB7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF9ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9025FF8ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90357F6ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9044FF4ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0503F3ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #05290 | PC: 0x2ae848..0x2ae898 (80 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x2ae848: D503245F  bti      c
//   0x2ae84c: B4000240  cbz      x0, #0x2ae894
//   0x2ae850: D503233F  paciasp  
//   0x2ae854: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x2ae858: F9000BF3  str      x19, [sp, #0x10]
//   0x2ae85c: 910003FD  mov      x29, sp
uint64_t fde_func_05290_0x2ae848(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x002AE848ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB4000240ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE7BFDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF3ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400000ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #05300 | PC: 0x2aed4c..0x2aee4c (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x2aed4c: D503233F  paciasp  
//   0x2aed50: D10283FF  sub      sp, sp, #0xa0
//   0x2aed54: A9067BFD  stp      x29, x30, [sp, #0x60]
//   0x2aed58: F9003BF7  str      x23, [sp, #0x70]
//   0x2aed5c: A90857F6  stp      x22, x21, [sp, #0x80]
//   0x2aed60: A9094FF4  stp      x20, x19, [sp, #0x90]
uint64_t fde_func_05300_0x2aed4c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x002AED4CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10283FFULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9067BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9003BF7ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90857F6ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9094FF4ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910183FDULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91112028ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #05309 | PC: 0x2af4f4..0x2af5f4 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x2af4f4: D503233F  paciasp  
//   0x2af4f8: A9BC7BFD  stp      x29, x30, [sp, #-0x40]!
//   0x2af4fc: F9000BF7  str      x23, [sp, #0x10]
//   0x2af500: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x2af504: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x2af508: 910003FD  mov      x29, sp
uint64_t fde_func_05309_0x2af4f4(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x002AF4F4ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BC7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF7ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90257F6ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9034FF4ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA940A408ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #05319 | PC: 0x2afa40..0x2afa4c (12 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x2afa40: D503245F  bti      c
//   0x2afa44: 91004000  add      x0, x0, #0x10
//   0x2afa48: 14007CDB  b        #0x2cedb4
uint64_t fde_func_05319_0x2afa40(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x002AFA40ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91004000ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x14007CDBULL ^ (2ULL << 32);
    return state ^ (state >> 29);
}

// FDE #05328 | PC: 0x2b0370..0x2b03b8 (72 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x2b0370: D503233F  paciasp  
//   0x2b0374: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x2b0378: F9000BF3  str      x19, [sp, #0x10]
//   0x2b037c: 910003FD  mov      x29, sp
//   0x2b0380: F9400013  ldr      x19, [x0]
//   0x2b0384: F9000001  str      x1, [x0]
uint64_t fde_func_05328_0x2b0370(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x002B0370ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF3ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400013ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000001ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB4000113ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA1303E0ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #05338 | PC: 0x2b0c30..0x2b0d30 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x2b0c30: D503233F  paciasp  
//   0x2b0c34: D10603FF  sub      sp, sp, #0x180
//   0x2b0c38: A9127BFD  stp      x29, x30, [sp, #0x120]
//   0x2b0c3c: A9136FFC  stp      x28, x27, [sp, #0x130]
//   0x2b0c40: A91467FA  stp      x26, x25, [sp, #0x140]
//   0x2b0c44: A9155FF8  stp      x24, x23, [sp, #0x150]
uint64_t fde_func_05338_0x2b0c30(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x002B0C30ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10603FFULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9127BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9136FFCULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA91467FAULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9155FF8ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA91657F6ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9174FF4ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #05347 | PC: 0x2b1754..0x2b17e0 (140 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x2b1754: D503233F  paciasp  
//   0x2b1758: D10183FF  sub      sp, sp, #0x60
//   0x2b175c: A9047BFD  stp      x29, x30, [sp, #0x40]
//   0x2b1760: A9054FF4  stp      x20, x19, [sp, #0x50]
//   0x2b1764: 910103FD  add      x29, sp, #0x40
//   0x2b1768: D53BD054  mrs      x20, tpidr_el0
uint64_t fde_func_05347_0x2b1754(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x002B1754ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10183FFULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9047BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9054FF4ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910103FDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD53BD054ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9401688ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81F83A8ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #05357 | PC: 0x2b2050..0x2b20c4 (116 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x2b2050: D503233F  paciasp  
//   0x2b2054: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x2b2058: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x2b205c: 910003FD  mov      x29, sp
//   0x2b2060: A940A014  ldp      x20, x8, [x0, #8]
//   0x2b2064: AA0003F3  mov      x19, x0
uint64_t fde_func_05357_0x2b2050(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x002B2050ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9014FF4ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA940A014ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xEB14011FULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x540000C0ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #05367 | PC: 0x2b2b68..0x2b2bc4 (92 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x2b2b68: D503233F  paciasp  
//   0x2b2b6c: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x2b2b70: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x2b2b74: 910003FD  mov      x29, sp
//   0x2b2b78: A940A014  ldp      x20, x8, [x0, #8]
//   0x2b2b7c: AA0003F3  mov      x19, x0
uint64_t fde_func_05367_0x2b2b68(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x002B2B68ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9014FF4ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA940A014ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xEB14011FULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x540000C0ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #05376 | PC: 0x2b3608..0x2b369c (148 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x2b3608: D503233F  paciasp  
//   0x2b360c: D10203FF  sub      sp, sp, #0x80
//   0x2b3610: A9067BFD  stp      x29, x30, [sp, #0x60]
//   0x2b3614: F9003BF3  str      x19, [sp, #0x70]
//   0x2b3618: 910183FD  add      x29, sp, #0x60
//   0x2b361c: AA0003E8  mov      x8, x0
uint64_t fde_func_05376_0x2b3608(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x002B3608ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10203FFULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9067BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9003BF3ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910183FDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003E8ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400800ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB40000C8ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #05386 | PC: 0x2b3c68..0x2b3ca4 (60 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x2b3c68: D503233F  paciasp  
//   0x2b3c6c: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x2b3c70: F9000BF3  str      x19, [sp, #0x10]
//   0x2b3c74: 910003FD  mov      x29, sp
//   0x2b3c78: AA0003F3  mov      x19, x0
//   0x2b3c7c: 9100C000  add      x0, x0, #0x30
uint64_t fde_func_05386_0x2b3c68(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x002B3C68ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF3ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9100C000ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x94000009ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA1303E0ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #05395 | PC: 0x2b41fc..0x2b4260 (100 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x2b41fc: D503233F  paciasp  
//   0x2b4200: D10103FF  sub      sp, sp, #0x40
//   0x2b4204: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x2b4208: F9001BF3  str      x19, [sp, #0x30]
//   0x2b420c: 910083FD  add      x29, sp, #0x20
//   0x2b4210: 3DC00000  ldr      q0, [x0]
uint64_t fde_func_05395_0x2b41fc(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x002B41FCULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10103FFULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9027BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9001BF3ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910083FDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x3DC00000ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0103F3ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400808ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #05405 | PC: 0x2b4acc..0x2b4b40 (116 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x2b4acc: D503233F  paciasp  
//   0x2b4ad0: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x2b4ad4: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x2b4ad8: 910003FD  mov      x29, sp
//   0x2b4adc: F9406008  ldr      x8, [x0, #0xc0]
//   0x2b4ae0: F9400908  ldr      x8, [x8, #0x10]
uint64_t fde_func_05405_0x2b4acc(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x002B4ACCULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9014FF4ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9406008ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400908ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB40000E8ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x2A1F03F3ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #05414 | PC: 0x2b5548..0x2b5648 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x2b5548: D503233F  paciasp  
//   0x2b554c: A9BB7BFD  stp      x29, x30, [sp, #-0x50]!
//   0x2b5550: A90167FC  stp      x28, x25, [sp, #0x10]
//   0x2b5554: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x2b5558: A90357F6  stp      x22, x21, [sp, #0x30]
//   0x2b555c: A9044FF4  stp      x20, x19, [sp, #0x40]
uint64_t fde_func_05414_0x2b5548(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x002B5548ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BB7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90167FCULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9025FF8ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90357F6ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9044FF4ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD11503FFULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #05424 | PC: 0x2b6184..0x2b6284 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x2b6184: D503233F  paciasp  
//   0x2b6188: A9BB7BFD  stp      x29, x30, [sp, #-0x50]!
//   0x2b618c: F9000BFC  str      x28, [sp, #0x10]
//   0x2b6190: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x2b6194: A90357F6  stp      x22, x21, [sp, #0x30]
//   0x2b6198: A9044FF4  stp      x20, x19, [sp, #0x40]
uint64_t fde_func_05424_0x2b6184(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x002B6184ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BB7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BFCULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9025FF8ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90357F6ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9044FF4ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD107C3FFULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #05433 | PC: 0x2b65dc..0x2b6608 (44 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x2b65dc: D503245F  bti      c
//   0x2b65e0: 52800308  mov      w8, #0x18
//   0x2b65e4: 92401C29  and      x9, x1, #0xff
//   0x2b65e8: 9B080129  madd     x9, x9, x8, x0
//   0x2b65ec: A94FA528  ldp      x8, x9, [x9, #0xf8]
//   0x2b65f0: EB09011F  cmp      x8, x9
uint64_t fde_func_05433_0x2b65dc(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x002B65DCULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x52800308ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x92401C29ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9B080129ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA94FA528ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xEB09011FULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x54000060ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400D00ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #05443 | PC: 0x2b6a78..0x2b6ad4 (92 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x2b6a78: D503245F  bti      c
//   0x2b6a7c: B9401408  ldr      w8, [x0, #0x14]
//   0x2b6a80: 7100051F  cmp      w8, #1
//   0x2b6a84: 54000060  b.eq     #0x2b6a90
//   0x2b6a88: F9400000  ldr      x0, [x0]
//   0x2b6a8c: D65F03C0  ret      
uint64_t fde_func_05443_0x2b6a78(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x002B6A78ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB9401408ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x7100051FULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x54000060ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400000ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD65F03C0ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9402009ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB24107EAULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #05452 | PC: 0x2b6fb0..0x2b7040 (144 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x2b6fb0: D503233F  paciasp  
//   0x2b6fb4: D10103FF  sub      sp, sp, #0x40
//   0x2b6fb8: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x2b6fbc: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x2b6fc0: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x2b6fc4: 910043FD  add      x29, sp, #0x10
uint64_t fde_func_05452_0x2b6fb0(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x002B6FB0ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10103FFULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90257F6ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9034FF4ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F4ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0103F3ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #05462 | PC: 0x2b79a4..0x2b7aa4 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x2b79a4: D503233F  paciasp  
//   0x2b79a8: A9BD7BFD  stp      x29, x30, [sp, #-0x30]!
//   0x2b79ac: F9000BF5  str      x21, [sp, #0x10]
//   0x2b79b0: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x2b79b4: 910003FD  mov      x29, sp
//   0x2b79b8: A947A009  ldp      x9, x8, [x0, #0x78]
uint64_t fde_func_05462_0x2b79a4(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x002B79A4ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BD7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF5ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9024FF4ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA947A009ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xEB08013FULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x54000700ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #05471 | PC: 0x2b8108..0x2b8114 (12 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x2b8108: D503245F  bti      c
//   0x2b810c: AA0103E0  mov      x0, x1
//   0x2b8110: 17FFC423  b        #0x2a919c
uint64_t fde_func_05471_0x2b8108(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x002B8108ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0103E0ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x17FFC423ULL ^ (2ULL << 32);
    return state ^ (state >> 29);
}

// FDE #05481 | PC: 0x2b8468..0x2b8474 (12 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x2b8468: D503245F  bti      c
//   0x2b846c: F9009C01  str      x1, [x0, #0x138]
//   0x2b8470: D65F03C0  ret      
uint64_t fde_func_05481_0x2b8468(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x002B8468ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9009C01ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD65F03C0ULL ^ (2ULL << 32);
    return state ^ (state >> 29);
}

// FDE #05490 | PC: 0x2b8674..0x2b86a8 (52 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x2b8674: D503233F  paciasp  
//   0x2b8678: D100C3FF  sub      sp, sp, #0x30
//   0x2b867c: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x2b8680: 910083FD  add      x29, sp, #0x20
//   0x2b8684: F9400808  ldr      x8, [x0, #0x10]
//   0x2b8688: 910023E1  add      x1, sp, #8
uint64_t fde_func_05490_0x2b8674(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x002B8674ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD100C3FFULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9027BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910083FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400808ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910023E1ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x390023FFULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000FE8ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #05500 | PC: 0x2b9cd0..0x2b9cdc (12 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x2b9cd0: D503245F  bti      c
//   0x2b9cd4: D102A000  sub      x0, x0, #0xa8
//   0x2b9cd8: 17FFFA74  b        #0x2b86a8
uint64_t fde_func_05500_0x2b9cd0(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x002B9CD0ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD102A000ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x17FFFA74ULL ^ (2ULL << 32);
    return state ^ (state >> 29);
}

// FDE #05509 | PC: 0x2b9e04..0x2b9e20 (28 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x2b9e04: D503245F  bti      c
//   0x2b9e08: F9400800  ldr      x0, [x0, #0x10]
//   0x2b9e0c: B4000080  cbz      x0, #0x2b9e1c
//   0x2b9e10: F9400008  ldr      x8, [x0]
//   0x2b9e14: F9400510  ldr      x16, [x8, #8]
//   0x2b9e18: D61F0200  br       x16
uint64_t fde_func_05509_0x2b9e04(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x002B9E04ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400800ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB4000080ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400008ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400510ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD61F0200ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD65F03C0ULL ^ (6ULL << 32);
    return state ^ (state >> 29);
}

// FDE #05519 | PC: 0x2ba094..0x2ba0e8 (84 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x2ba094: D503233F  paciasp  
//   0x2ba098: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x2ba09c: F9000BF3  str      x19, [sp, #0x10]
//   0x2ba0a0: 910003FD  mov      x29, sp
//   0x2ba0a4: AA0003F3  mov      x19, x0
//   0x2ba0a8: F9401400  ldr      x0, [x0, #0x28]
uint64_t fde_func_05519_0x2ba094(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x002BA094ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF3ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9401400ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x90001708ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9127C108ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #05528 | PC: 0x2ba78c..0x2ba810 (132 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x2ba78c: D503233F  paciasp  
//   0x2ba790: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x2ba794: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x2ba798: 910003FD  mov      x29, sp
//   0x2ba79c: A9402009  ldp      x9, x8, [x0]
//   0x2ba7a0: AA0003F3  mov      x19, x0
uint64_t fde_func_05528_0x2ba78c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x002BA78CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9014FF4ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9402009ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0103F4ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xCB09010AULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #05538 | PC: 0x2bab88..0x2bab98 (16 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x2bab88: D503245F  bti      c
//   0x2bab8c: F0FFEE80  adrp     x0, #0x8d000
//   0x2bab90: 91230C00  add      x0, x0, #0x8c3
//   0x2bab94: D65F03C0  ret      
uint64_t fde_func_05538_0x2bab88(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x002BAB88ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF0FFEE80ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91230C00ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD65F03C0ULL ^ (3ULL << 32);
    return state ^ (state >> 29);
}

// FDE #05547 | PC: 0x2bb104..0x2bb204 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x2bb104: D503233F  paciasp  
//   0x2bb108: A9BC7BFD  stp      x29, x30, [sp, #-0x40]!
//   0x2bb10c: F9000BFC  str      x28, [sp, #0x10]
//   0x2bb110: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x2bb114: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x2bb118: 910003FD  mov      x29, sp
uint64_t fde_func_05547_0x2bb104(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x002BB104ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BC7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BFCULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90257F6ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9034FF4ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD12903FFULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910023E9ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #05557 | PC: 0x2bb8a4..0x2bb918 (116 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x2bb8a4: D503233F  paciasp  
//   0x2bb8a8: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x2bb8ac: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x2bb8b0: 910003FD  mov      x29, sp
//   0x2bb8b4: A940A014  ldp      x20, x8, [x0, #8]
//   0x2bb8b8: AA0003F3  mov      x19, x0
uint64_t fde_func_05557_0x2bb8a4(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x002BB8A4ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9014FF4ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA940A014ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xEB14011FULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x540000C0ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #05566 | PC: 0x2bbf54..0x2bc00c (184 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x2bbf54: D503233F  paciasp  
//   0x2bbf58: A9BD7BFD  stp      x29, x30, [sp, #-0x30]!
//   0x2bbf5c: F9000BF5  str      x21, [sp, #0x10]
//   0x2bbf60: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x2bbf64: 910003FD  mov      x29, sp
//   0x2bbf68: F9400C08  ldr      x8, [x0, #0x18]
uint64_t fde_func_05566_0x2bbf54(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x002BBF54ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BD7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF5ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9024FF4ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400C08ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x5280140AULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400409ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #05576 | PC: 0x2bcdbc..0x2bce30 (116 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x2bcdbc: D503233F  paciasp  
//   0x2bcdc0: D10143FF  sub      sp, sp, #0x50
//   0x2bcdc4: A9037BFD  stp      x29, x30, [sp, #0x30]
//   0x2bcdc8: F90023F3  str      x19, [sp, #0x40]
//   0x2bcdcc: 9100C3FD  add      x29, sp, #0x30
//   0x2bcdd0: D53BD053  mrs      x19, tpidr_el0
uint64_t fde_func_05576_0x2bcdbc(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x002BCDBCULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10143FFULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9037BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF90023F3ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9100C3FDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD53BD053ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003E2ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9401668ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #05585 | PC: 0x2bd514..0x2bd5f0 (220 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x2bd514: D503233F  paciasp  
//   0x2bd518: D101C3FF  sub      sp, sp, #0x70
//   0x2bd51c: A9057BFD  stp      x29, x30, [sp, #0x50]
//   0x2bd520: F90033F3  str      x19, [sp, #0x60]
//   0x2bd524: 910143FD  add      x29, sp, #0x50
//   0x2bd528: D53BD053  mrs      x19, tpidr_el0
uint64_t fde_func_05585_0x2bd514(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x002BD514ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD101C3FFULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9057BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF90033F3ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910143FDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD53BD053ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x92800009ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9401668ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #05595 | PC: 0x2bddf0..0x2bde5c (108 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x2bddf0: D503233F  paciasp  
//   0x2bddf4: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x2bddf8: F9000BF3  str      x19, [sp, #0x10]
//   0x2bddfc: 910003FD  mov      x29, sp
//   0x2bde00: B00016E8  adrp     x8, #0x59a000
//   0x2bde04: 912AC108  add      x8, x8, #0xab0
uint64_t fde_func_05595_0x2bddf0(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x002BDDF0ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF3ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB00016E8ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x912AC108ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9000408ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #05604 | PC: 0x2be1d4..0x2be1ec (24 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x2be1d4: D503245F  bti      c
//   0x2be1d8: B4000080  cbz      x0, #0x2be1e8
//   0x2be1dc: F9400008  ldr      x8, [x0]
//   0x2be1e0: F9400910  ldr      x16, [x8, #0x10]
//   0x2be1e4: D61F0200  br       x16
//   0x2be1e8: D65F03C0  ret      
uint64_t fde_func_05604_0x2be1d4(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x002BE1D4ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB4000080ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400008ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400910ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD61F0200ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD65F03C0ULL ^ (5ULL << 32);
    return state ^ (state >> 29);
}

// FDE #05614 | PC: 0x2be588..0x2be630 (168 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x2be588: D503233F  paciasp  
//   0x2be58c: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x2be590: F9000BF3  str      x19, [sp, #0x10]
//   0x2be594: 910003FD  mov      x29, sp
//   0x2be598: AA0003F3  mov      x19, x0
//   0x2be59c: F9404400  ldr      x0, [x0, #0x88]
uint64_t fde_func_05614_0x2be588(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x002BE588ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF3ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9404400ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB4000140ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91002008ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #05623 | PC: 0x2bedf4..0x2beef4 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x2bedf4: D503233F  paciasp  
//   0x2bedf8: D103C3FF  sub      sp, sp, #0xf0
//   0x2bedfc: A90A7BFD  stp      x29, x30, [sp, #0xa0]
//   0x2bee00: A90B67FA  stp      x26, x25, [sp, #0xb0]
//   0x2bee04: A90C5FF8  stp      x24, x23, [sp, #0xc0]
//   0x2bee08: A90D57F6  stp      x22, x21, [sp, #0xd0]
uint64_t fde_func_05623_0x2bedf4(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x002BEDF4ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD103C3FFULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90A7BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90B67FAULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90C5FF8ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90D57F6ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90E4FF4ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910283FDULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #05633 | PC: 0x2bf4ec..0x2bf53c (80 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x2bf4ec: D503233F  paciasp  
//   0x2bf4f0: A9BD7BFD  stp      x29, x30, [sp, #-0x30]!
//   0x2bf4f4: F9000BF5  str      x21, [sp, #0x10]
//   0x2bf4f8: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x2bf4fc: 910003FD  mov      x29, sp
//   0x2bf500: A9405015  ldp      x21, x20, [x0]
uint64_t fde_func_05633_0x2bf4ec(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x002BF4ECULL);
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

// FDE #05642 | PC: 0x2bfc20..0x2bfc6c (76 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x2bfc20: D503233F  paciasp  
//   0x2bfc24: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x2bfc28: F9000BF3  str      x19, [sp, #0x10]
//   0x2bfc2c: 910003FD  mov      x29, sp
//   0x2bfc30: F00016C8  adrp     x8, #0x59a000
//   0x2bfc34: 912E0108  add      x8, x8, #0xb80
uint64_t fde_func_05642_0x2bfc20(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x002BFC20ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF3ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF00016C8ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x912E0108ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB900081FULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #05652 | PC: 0x2c0184..0x2c01c4 (64 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x2c0184: D503245F  bti      c
//   0x2c0188: F9400408  ldr      x8, [x0, #8]
//   0x2c018c: B4000188  cbz      x8, #0x2c01bc
//   0x2c0190: 91002108  add      x8, x8, #8
//   0x2c0194: 885FFD09  ldaxr    w9, [x8]
//   0x2c0198: 71000529  subs     w9, w9, #1
uint64_t fde_func_05652_0x2c0184(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x002C0184ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400408ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB4000188ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91002108ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x885FFD09ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x71000529ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x880AFD09ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x35FFFFAAULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #05662 | PC: 0x2c0890..0x2c0914 (132 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x2c0890: D503233F  paciasp  
//   0x2c0894: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x2c0898: F9000BF3  str      x19, [sp, #0x10]
//   0x2c089c: 910003FD  mov      x29, sp
//   0x2c08a0: AA0003F3  mov      x19, x0
//   0x2c08a4: 39402408  ldrb     w8, [x0, #9]
uint64_t fde_func_05662_0x2c0890(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x002C0890ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF3ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x39402408ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x340001C8ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x39403268ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #05671 | PC: 0x2c0e88..0x2c0ee4 (92 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x2c0e88: D503233F  paciasp  
//   0x2c0e8c: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x2c0e90: F9000BF3  str      x19, [sp, #0x10]
//   0x2c0e94: 910003FD  mov      x29, sp
//   0x2c0e98: F00018E8  adrp     x8, #0x5df000
//   0x2c0e9c: 39561108  ldrb     w8, [x8, #0x584]
uint64_t fde_func_05671_0x2c0e88(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x002C0E88ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF3ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF00018E8ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x39561108ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x7100051FULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x54000161ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #05681 | PC: 0x2c1718..0x2c17a4 (140 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x2c1718: D503233F  paciasp  
//   0x2c171c: D10143FF  sub      sp, sp, #0x50
//   0x2c1720: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x2c1724: F9001BF5  str      x21, [sp, #0x30]
//   0x2c1728: A9044FF4  stp      x20, x19, [sp, #0x40]
//   0x2c172c: 910083FD  add      x29, sp, #0x20
uint64_t fde_func_05681_0x2c1718(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x002C1718ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10143FFULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9027BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9001BF5ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9044FF4ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910083FDULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x39400048ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0103F4ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #05690 | PC: 0x2c1be4..0x2c1c10 (44 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x2c1be4: D503233F  paciasp  
//   0x2c1be8: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x2c1bec: F9000BF3  str      x19, [sp, #0x10]
//   0x2c1bf0: 910003FD  mov      x29, sp
//   0x2c1bf4: AA0003F3  mov      x19, x0
//   0x2c1bf8: 97FFFFE6  bl       #0x2c1b90
uint64_t fde_func_05690_0x2c1be4(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x002C1BE4ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF3ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x97FFFFE6ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA1303E0ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400BF3ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #05700 | PC: 0x2c2080..0x2c2158 (216 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x2c2080: D503233F  paciasp  
//   0x2c2084: A9BC7BFD  stp      x29, x30, [sp, #-0x40]!
//   0x2c2088: F9000BFC  str      x28, [sp, #0x10]
//   0x2c208c: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x2c2090: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x2c2094: 910003FD  mov      x29, sp
uint64_t fde_func_05700_0x2c2080(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x002C2080ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BC7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BFCULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90257F6ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9034FF4ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10CC3FFULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD53BD055ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #05709 | PC: 0x2c26f0..0x2c2768 (120 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x2c26f0: D503233F  paciasp  
//   0x2c26f4: A9BD7BFD  stp      x29, x30, [sp, #-0x30]!
//   0x2c26f8: F9000BF5  str      x21, [sp, #0x10]
//   0x2c26fc: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x2c2700: 910003FD  mov      x29, sp
//   0x2c2704: A9402408  ldp      x8, x9, [x0]
uint64_t fde_func_05709_0x2c26f0(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x002C26F0ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BD7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF5ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9024FF4ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9402408ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0203F5ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #05719 | PC: 0x2c2c10..0x2c2c54 (68 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x2c2c10: D503233F  paciasp  
//   0x2c2c14: D100C3FF  sub      sp, sp, #0x30
//   0x2c2c18: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x2c2c1c: 910083FD  add      x29, sp, #0x20
//   0x2c2c20: A9402448  ldp      x8, x9, [x2]
//   0x2c2c24: A9007C5F  stp      xzr, xzr, [x2]
uint64_t fde_func_05719_0x2c2c10(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x002C2C10ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD100C3FFULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9027BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910083FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9402448ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9007C5FULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x3DC00440ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003E2ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #05728 | PC: 0x2c33fc..0x2c349c (160 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x2c33fc: D503233F  paciasp  
//   0x2c3400: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x2c3404: F9000BF3  str      x19, [sp, #0x10]
//   0x2c3408: 910003FD  mov      x29, sp
//   0x2c340c: A947A809  ldp      x9, x10, [x0, #0x78]
//   0x2c3410: F9404408  ldr      x8, [x0, #0x88]
uint64_t fde_func_05728_0x2c33fc(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x002C33FCULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF3ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA947A809ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9404408ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xEB0A013FULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x540000C1ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #05738 | PC: 0x2c3a04..0x2c3b04 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x2c3a04: D503233F  paciasp  
//   0x2c3a08: D10343FF  sub      sp, sp, #0xd0
//   0x2c3a0c: A9097BFD  stp      x29, x30, [sp, #0x90]
//   0x2c3a10: A90A5FF8  stp      x24, x23, [sp, #0xa0]
//   0x2c3a14: A90B57F6  stp      x22, x21, [sp, #0xb0]
//   0x2c3a18: A90C4FF4  stp      x20, x19, [sp, #0xc0]
uint64_t fde_func_05738_0x2c3a04(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x002C3A04ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10343FFULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9097BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90A5FF8ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90B57F6ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90C4FF4ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910243FDULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD53BD057ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #05747 | PC: 0x2c4030..0x2c40a0 (112 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x2c4030: D503233F  paciasp  
//   0x2c4034: A9BD7BFD  stp      x29, x30, [sp, #-0x30]!
//   0x2c4038: F9000BF5  str      x21, [sp, #0x10]
//   0x2c403c: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x2c4040: 910003FD  mov      x29, sp
//   0x2c4044: A948A408  ldp      x8, x9, [x0, #0x88]
uint64_t fde_func_05747_0x2c4030(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x002C4030ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BD7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF5ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9024FF4ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA948A408ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xEB09011FULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x540001C0ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #05757 | PC: 0x2c4560..0x2c45fc (156 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x2c4560: D503233F  paciasp  
//   0x2c4564: D100C3FF  sub      sp, sp, #0x30
//   0x2c4568: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x2c456c: 910083FD  add      x29, sp, #0x20
//   0x2c4570: F9400009  ldr      x9, [x0]
//   0x2c4574: B4000209  cbz      x9, #0x2c45b4
uint64_t fde_func_05757_0x2c4560(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x002C4560ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD100C3FFULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9027BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910083FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400009ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB4000209ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF940040AULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003E8ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #05766 | PC: 0x2c4954..0x2c495c (8 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x2c4954: D503245F  bti      c
//   0x2c4958: 14002684  b        #0x2ce368
uint64_t fde_func_05766_0x2c4954(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x002C4954ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x14002684ULL ^ (1ULL << 32);
    return state ^ (state >> 29);
}

// FDE #05776 | PC: 0x2c4ee8..0x2c4f04 (28 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x2c4ee8: D503233F  paciasp  
//   0x2c4eec: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x2c4ef0: 910003FD  mov      x29, sp
//   0x2c4ef4: 97FF910C  bl       #0x2a9324
//   0x2c4ef8: A8C17BFD  ldp      x29, x30, [sp], #0x10
//   0x2c4efc: D50323BF  autiasp  
uint64_t fde_func_05776_0x2c4ee8(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x002C4EE8ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BF7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x97FF910CULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA8C17BFDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD50323BFULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD65F03C0ULL ^ (6ULL << 32);
    return state ^ (state >> 29);
}

// FDE #05785 | PC: 0x2c5320..0x2c5384 (100 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x2c5320: D503233F  paciasp  
//   0x2c5324: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x2c5328: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x2c532c: 910003FD  mov      x29, sp
//   0x2c5330: 91024013  add      x19, x0, #0x90
//   0x2c5334: AA0003F4  mov      x20, x0
uint64_t fde_func_05785_0x2c5320(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x002C5320ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9014FF4ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91024013ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F4ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA1303E0ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x940B09BDULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #05795 | PC: 0x2c5860..0x2c5894 (52 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x2c5860: D503245F  bti      c
//   0x2c5864: A940A408  ldp      x8, x9, [x0, #8]
//   0x2c5868: EB09011F  cmp      x8, x9
//   0x2c586c: 54000122  b.hs     #0x2c5890
//   0x2c5870: F9400029  ldr      x9, [x1]
//   0x2c5874: 9100410A  add      x10, x8, #0x10
uint64_t fde_func_05795_0x2c5860(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x002C5860ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA940A408ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xEB09011FULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x54000122ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400029ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9100410AULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000109ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400429ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #05804 | PC: 0x2c5d04..0x2c5d78 (116 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x2c5d04: D503233F  paciasp  
//   0x2c5d08: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x2c5d0c: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x2c5d10: 910003FD  mov      x29, sp
//   0x2c5d14: 900018C8  adrp     x8, #0x5dd000
//   0x2c5d18: 9119C108  add      x8, x8, #0x670
uint64_t fde_func_05804_0x2c5d04(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x002C5D04ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9014FF4ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x900018C8ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9119C108ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xC8DFFD13ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF100067FULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #05814 | PC: 0x2c63d4..0x2c6400 (44 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x2c63d4: D503233F  paciasp  
//   0x2c63d8: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x2c63dc: F9000BF3  str      x19, [sp, #0x10]
//   0x2c63e0: 910003FD  mov      x29, sp
//   0x2c63e4: AA0003F3  mov      x19, x0
//   0x2c63e8: 97FFFFC8  bl       #0x2c6308
uint64_t fde_func_05814_0x2c63d4(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x002C63D4ULL);
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

// FDE #05823 | PC: 0x2c67c0..0x2c68c0 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x2c67c0: D503233F  paciasp  
//   0x2c67c4: A9BA7BFD  stp      x29, x30, [sp, #-0x60]!
//   0x2c67c8: F9000BFB  str      x27, [sp, #0x10]
//   0x2c67cc: A90267FA  stp      x26, x25, [sp, #0x20]
//   0x2c67d0: A9035FF8  stp      x24, x23, [sp, #0x30]
//   0x2c67d4: A90457F6  stp      x22, x21, [sp, #0x40]
uint64_t fde_func_05823_0x2c67c0(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x002C67C0ULL);
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

// FDE #05833 | PC: 0x2c722c..0x2c732c (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x2c722c: D503233F  paciasp  
//   0x2c7230: D10403FF  sub      sp, sp, #0x100
//   0x2c7234: A90D7BFD  stp      x29, x30, [sp, #0xd0]
//   0x2c7238: A90E57F6  stp      x22, x21, [sp, #0xe0]
//   0x2c723c: A90F4FF4  stp      x20, x19, [sp, #0xf0]
//   0x2c7240: 910343FD  add      x29, sp, #0xd0
uint64_t fde_func_05833_0x2c722c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x002C722CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10403FFULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90D7BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90E57F6ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90F4FF4ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910343FDULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD53BD055ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #05842 | PC: 0x2c79f8..0x2c7a04 (12 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x2c79f8: D503245F  bti      c
//   0x2c79fc: D1006000  sub      x0, x0, #0x18
//   0x2c7a00: 17FFFF90  b        #0x2c7840
uint64_t fde_func_05842_0x2c79f8(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x002C79F8ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD1006000ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x17FFFF90ULL ^ (2ULL << 32);
    return state ^ (state >> 29);
}

// FDE #05852 | PC: 0x2c7f50..0x2c7ffc (172 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x2c7f50: D503233F  paciasp  
//   0x2c7f54: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x2c7f58: F9000BF3  str      x19, [sp, #0x10]
//   0x2c7f5c: 910003FD  mov      x29, sp
//   0x2c7f60: AA0003F3  mov      x19, x0
//   0x2c7f64: 39412008  ldrb     w8, [x0, #0x48]
uint64_t fde_func_05852_0x2c7f50(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x002C7F50ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF3ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x39412008ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x34000128ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x3940A268ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #05861 | PC: 0x2c850c..0x2c853c (48 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x2c850c: D503233F  paciasp  
//   0x2c8510: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x2c8514: F9000BF3  str      x19, [sp, #0x10]
//   0x2c8518: 910003FD  mov      x29, sp
//   0x2c851c: AA0003F3  mov      x19, x0
//   0x2c8520: 94000007  bl       #0x2c853c
uint64_t fde_func_05861_0x2c850c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x002C850CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF3ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x94000007ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF8408E61ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA1303E0ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #05871 | PC: 0x2c8b98..0x2c8c00 (104 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x2c8b98: D503233F  paciasp  
//   0x2c8b9c: D10083FF  sub      sp, sp, #0x20
//   0x2c8ba0: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x2c8ba4: 910043FD  add      x29, sp, #0x10
//   0x2c8ba8: F9400028  ldr      x8, [x1]
//   0x2c8bac: F9401000  ldr      x0, [x0, #0x20]
uint64_t fde_func_05871_0x2c8b98(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x002C8B98ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10083FFULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400028ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9401000ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF900003FULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910023E1ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #05880 | PC: 0x2c8e0c..0x2c8e20 (20 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x2c8e0c: D503245F  bti      c
//   0x2c8e10: AA0003E8  mov      x8, x0
//   0x2c8e14: AA0103E0  mov      x0, x1
//   0x2c8e18: AA0803E1  mov      x1, x8
//   0x2c8e1c: 1400032A  b        #0x2c9ac4
uint64_t fde_func_05880_0x2c8e0c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x002C8E0CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003E8ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0103E0ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0803E1ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x1400032AULL ^ (4ULL << 32);
    return state ^ (state >> 29);
}

// FDE #05890 | PC: 0x2c9408..0x2c9438 (48 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x2c9408: D503233F  paciasp  
//   0x2c940c: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x2c9410: F9000BF3  str      x19, [sp, #0x10]
//   0x2c9414: 910003FD  mov      x29, sp
//   0x2c9418: D1002013  sub      x19, x0, #8
//   0x2c941c: AA1303E0  mov      x0, x19
uint64_t fde_func_05890_0x2c9408(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x002C9408ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF3ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD1002013ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA1303E0ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x97FFFCE4ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA1303E0ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #05899 | PC: 0x2c94e8..0x2c9518 (48 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x2c94e8: D503233F  paciasp  
//   0x2c94ec: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x2c94f0: F9000BF3  str      x19, [sp, #0x10]
//   0x2c94f4: 910003FD  mov      x29, sp
//   0x2c94f8: D1006013  sub      x19, x0, #0x18
//   0x2c94fc: AA1303E0  mov      x0, x19
uint64_t fde_func_05899_0x2c94e8(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x002C94E8ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF3ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD1006013ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA1303E0ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x97FFFCACULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA1303E0ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #05909 | PC: 0x2c9948..0x2c9a08 (192 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x2c9948: D503233F  paciasp  
//   0x2c994c: D10303FF  sub      sp, sp, #0xc0
//   0x2c9950: A9097BFD  stp      x29, x30, [sp, #0x90]
//   0x2c9954: F90053F5  str      x21, [sp, #0xa0]
//   0x2c9958: A90B4FF4  stp      x20, x19, [sp, #0xb0]
//   0x2c995c: 910243FD  add      x29, sp, #0x90
uint64_t fde_func_05909_0x2c9948(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x002C9948ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10303FFULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9097BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF90053F5ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90B4FF4ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910243FDULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD53BD055ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF94016A8ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #05918 | PC: 0x2c9f10..0x2c9f3c (44 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x2c9f10: D503233F  paciasp  
//   0x2c9f14: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x2c9f18: F9000BF3  str      x19, [sp, #0x10]
//   0x2c9f1c: 910003FD  mov      x29, sp
//   0x2c9f20: AA0003F3  mov      x19, x0
//   0x2c9f24: 97FFFFBB  bl       #0x2c9e10
uint64_t fde_func_05918_0x2c9f10(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x002C9F10ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF3ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x97FFFFBBULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA1303E0ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400BF3ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #05928 | PC: 0x2ca864..0x2ca8d8 (116 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x2ca864: D503233F  paciasp  
//   0x2ca868: A9BD7BFD  stp      x29, x30, [sp, #-0x30]!
//   0x2ca86c: F9000BF5  str      x21, [sp, #0x10]
//   0x2ca870: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x2ca874: 910003FD  mov      x29, sp
//   0x2ca878: A9402014  ldp      x20, x8, [x0]
uint64_t fde_func_05928_0x2ca864(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x002CA864ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BD7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF5ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9024FF4ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9402014ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xEB08029FULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #05937 | PC: 0x2cc690..0x2cc6f8 (104 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x2cc690: D503233F  paciasp  
//   0x2cc694: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x2cc698: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x2cc69c: 910003FD  mov      x29, sp
//   0x2cc6a0: 97FFFF6E  bl       #0x2cc458
//   0x2cc6a4: B0001880  adrp     x0, #0x5dd000
uint64_t fde_func_05937_0x2cc690(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x002CC690ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9014FF4ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x97FFFF6EULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB0001880ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x911A4000ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x94000CC5ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #05947 | PC: 0x2ccbc4..0x2ccbd4 (16 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x2ccbc4: D503245F  bti      c
//   0x2ccbc8: 9100A001  add      x1, x0, #0x28
//   0x2ccbcc: F9401000  ldr      x0, [x0, #0x20]
//   0x2ccbd0: 14000010  b        #0x2ccc10
uint64_t fde_func_05947_0x2ccbc4(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x002CCBC4ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9100A001ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9401000ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x14000010ULL ^ (3ULL << 32);
    return state ^ (state >> 29);
}

// FDE #05957 | PC: 0x2cd530..0x2cd588 (88 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x2cd530: D503233F  paciasp  
//   0x2cd534: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x2cd538: F9000BF3  str      x19, [sp, #0x10]
//   0x2cd53c: 910003FD  mov      x29, sp
//   0x2cd540: F9400013  ldr      x19, [x0]
//   0x2cd544: B40001B3  cbz      x19, #0x2cd578
uint64_t fde_func_05957_0x2cd530(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x002CD530ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF3ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400013ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB40001B3ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x885FFE68ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x71000508ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #05966 | PC: 0x2cdeec..0x2cdf18 (44 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x2cdeec: D503233F  paciasp  
//   0x2cdef0: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x2cdef4: 910003FD  mov      x29, sp
//   0x2cdef8: 94000008  bl       #0x2cdf18
//   0x2cdefc: 940006B1  bl       #0x2cf9c0
//   0x2cdf00: B4000080  cbz      x0, #0x2cdf10
uint64_t fde_func_05966_0x2cdeec(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x002CDEECULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BF7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x94000008ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x940006B1ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB4000080ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA8C17BFDULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD50323BFULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #05976 | PC: 0x2ce3bc..0x2ce40c (80 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x2ce3bc: D503233F  paciasp  
//   0x2ce3c0: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x2ce3c4: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x2ce3c8: 910003FD  mov      x29, sp
//   0x2ce3cc: 91010013  add      x19, x0, #0x40
//   0x2ce3d0: AA0003F4  mov      x20, x0
uint64_t fde_func_05976_0x2ce3bc(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x002CE3BCULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9014FF4ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91010013ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F4ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA1303E0ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x97FC6FE0ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #05985 | PC: 0x2ceab0..0x2ceb74 (196 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x2ceab0: D503233F  paciasp  
//   0x2ceab4: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x2ceab8: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x2ceabc: 910003FD  mov      x29, sp
//   0x2ceac0: AA0003F3  mov      x19, x0
//   0x2ceac4: 39408008  ldrb     w8, [x0, #0x20]
uint64_t fde_func_05985_0x2ceab0(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x002CEAB0ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9014FF4ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x39408008ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB0001669ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9107C129ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #05995 | PC: 0x2cef6c..0x2cf000 (148 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x2cef6c: D503233F  paciasp  
//   0x2cef70: D10103FF  sub      sp, sp, #0x40
//   0x2cef74: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x2cef78: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x2cef7c: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x2cef80: 910043FD  add      x29, sp, #0x10
uint64_t fde_func_05995_0x2cef6c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x002CEF6CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10103FFULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90257F6ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9034FF4ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0203F6ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0103E2ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #06004 | PC: 0x2cf5d4..0x2cf5fc (40 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x2cf5d4: D503245F  bti      c
//   0x2cf5d8: 92400408  and      x8, x0, #3
//   0x2cf5dc: F100091F  cmp      x8, #2
//   0x2cf5e0: 540000A1  b.ne     #0x2cf5f4
//   0x2cf5e4: D0001748  adrp     x8, #0x5b9000
//   0x2cf5e8: AA1F03E1  mov      x1, xzr
uint64_t fde_func_06004_0x2cf5d4(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x002CF5D4ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x92400408ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF100091FULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x540000A1ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD0001748ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA1F03E1ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB9499900ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x140ADF42ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #06014 | PC: 0x2cfb38..0x2cfb60 (40 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x2cfb38: D503233F  paciasp  
//   0x2cfb3c: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x2cfb40: 910003FD  mov      x29, sp
//   0x2cfb44: 97FFFFE0  bl       #0x2cfac4
//   0x2cfb48: 97FFFF9E  bl       #0x2cf9c0
//   0x2cfb4c: F100001F  cmp      x0, #0
uint64_t fde_func_06014_0x2cfb38(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x002CFB38ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BF7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x97FFFFE0ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x97FFFF9EULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF100001FULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x1A9F07E0ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA8C17BFDULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #06023 | PC: 0x2cfda4..0x2cfe24 (128 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x2cfda4: D503245F  bti      c
//   0x2cfda8: 1E602008  fcmp     d0, #0.0
//   0x2cfdac: AA1F03E0  mov      x0, xzr
//   0x2cfdb0: 54000380  b.eq     #0x2cfe20
//   0x2cfdb4: 54000366  b.vs     #0x2cfe20
//   0x2cfdb8: 90FFED68  adrp     x8, #0x7b000
uint64_t fde_func_06023_0x2cfda4(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x002CFDA4ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x1E602008ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA1F03E0ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x54000380ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x54000366ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x90FFED68ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x92F00009ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xFD42B501ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #06033 | PC: 0x2d028c..0x2d0374 (232 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x2d028c: D503245F  bti      c
//   0x2d0290: CB0003E8  neg      x8, x0
//   0x2d0294: D2F00009  mov      x9, #-0x8000000000000000
//   0x2d0298: AB09001F  cmn      x0, x9
//   0x2d029c: 540002C1  b.ne     #0x2d02f4
//   0x2d02a0: F100041F  cmp      x0, #1
uint64_t fde_func_06033_0x2d028c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x002D028CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xCB0003E8ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD2F00009ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAB09001FULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x540002C1ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF100041FULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x5400052BULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB24107E9ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #06042 | PC: 0x2d0a6c..0x2d0ae4 (120 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x2d0a6c: D503233F  paciasp  
//   0x2d0a70: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x2d0a74: F9000BF3  str      x19, [sp, #0x10]
//   0x2d0a78: 910003FD  mov      x29, sp
//   0x2d0a7c: AA0003F3  mov      x19, x0
//   0x2d0a80: F9401C00  ldr      x0, [x0, #0x38]
uint64_t fde_func_06042_0x2d0a6c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x002D0A6CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF3ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9401C00ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x3900C27FULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB4000200ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #06052 | PC: 0x2d1010..0x2d1084 (116 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x2d1010: D503233F  paciasp  
//   0x2d1014: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x2d1018: F9000BF3  str      x19, [sp, #0x10]
//   0x2d101c: 910003FD  mov      x29, sp
//   0x2d1020: F9400008  ldr      x8, [x0]
//   0x2d1024: 3900C01F  strb     wzr, [x0, #0x30]
uint64_t fde_func_06052_0x2d1010(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x002D1010ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF3ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400008ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x3900C01FULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9403413ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF900341FULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #06061 | PC: 0x2d1300..0x2d1328 (40 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x2d1300: D503233F  paciasp  
//   0x2d1304: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x2d1308: 910003FD  mov      x29, sp
//   0x2d130c: 52800202  mov      w2, #0x10
//   0x2d1310: 940ADBAE  bl       #0x5881c8
//   0x2d1314: 7100001F  cmp      w0, #0
uint64_t fde_func_06061_0x2d1300(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x002D1300ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BF7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x52800202ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x940ADBAEULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x7100001FULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x1A9F17E0ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA8C17BFDULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #06071 | PC: 0x2d1770..0x2d180c (156 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x2d1770: D503233F  paciasp  
//   0x2d1774: D100C3FF  sub      sp, sp, #0x30
//   0x2d1778: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x2d177c: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x2d1780: 910043FD  add      x29, sp, #0x10
//   0x2d1784: F9400C08  ldr      x8, [x0, #0x18]
uint64_t fde_func_06071_0x2d1770(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x002D1770ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD100C3FFULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9024FF4ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400C08ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0103F4ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #06080 | PC: 0x2d1b84..0x2d1c04 (128 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x2d1b84: D503233F  paciasp  
//   0x2d1b88: A9BD7BFD  stp      x29, x30, [sp, #-0x30]!
//   0x2d1b8c: F9000BF5  str      x21, [sp, #0x10]
//   0x2d1b90: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x2d1b94: 910003FD  mov      x29, sp
//   0x2d1b98: F9400014  ldr      x20, [x0]
uint64_t fde_func_06080_0x2d1b84(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x002D1B84ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BD7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF5ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9024FF4ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400014ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB40002B4ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400408ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #06090 | PC: 0x2d2088..0x2d20d0 (72 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x2d2088: D503233F  paciasp  
//   0x2d208c: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x2d2090: F9000BF3  str      x19, [sp, #0x10]
//   0x2d2094: 910003FD  mov      x29, sp
//   0x2d2098: A940A42A  ldp      x10, x9, [x1, #8]
//   0x2d209c: AA0003F3  mov      x19, x0
uint64_t fde_func_06090_0x2d2088(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x002D2088ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF3ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA940A42AULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x39400028ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x7200011FULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #06099 | PC: 0x2d248c..0x2d24d0 (68 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x2d248c: D503233F  paciasp  
//   0x2d2490: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x2d2494: F9000BF3  str      x19, [sp, #0x10]
//   0x2d2498: 910003FD  mov      x29, sp
//   0x2d249c: F9400401  ldr      x1, [x0, #8]
//   0x2d24a0: AA0003F3  mov      x19, x0
uint64_t fde_func_06099_0x2d248c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x002D248CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF3ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400401ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9400000BULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400260ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #06109 | PC: 0x2d2a60..0x2d2af4 (148 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x2d2a60: D503233F  paciasp  
//   0x2d2a64: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x2d2a68: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x2d2a6c: 910003FD  mov      x29, sp
//   0x2d2a70: F9400408  ldr      x8, [x0, #8]
//   0x2d2a74: CB030109  sub      x9, x8, x3
uint64_t fde_func_06109_0x2d2a60(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x002D2A60ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9014FF4ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400408ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xCB030109ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0803EAULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x8B09002BULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #06118 | PC: 0x2d2f04..0x2d2f64 (96 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x2d2f04: D503233F  paciasp  
//   0x2d2f08: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x2d2f0c: 910003FD  mov      x29, sp
//   0x2d2f10: F9400C08  ldr      x8, [x0, #0x18]
//   0x2d2f14: 12001D09  and      w9, w8, #0xff
//   0x2d2f18: 7100093F  cmp      w9, #2
uint64_t fde_func_06118_0x2d2f04(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x002D2F04ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BF7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400C08ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x12001D09ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x7100093FULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x540000C1ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF100091FULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #06128 | PC: 0x2d324c..0x2d32a4 (88 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x2d324c: D503233F  paciasp  
//   0x2d3250: D100C3FF  sub      sp, sp, #0x30
//   0x2d3254: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x2d3258: F90013F3  str      x19, [sp, #0x20]
//   0x2d325c: 910043FD  add      x29, sp, #0x10
//   0x2d3260: A9000BE1  stp      x1, x2, [sp]
uint64_t fde_func_06128_0x2d324c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x002D324CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD100C3FFULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF90013F3ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9000BE1ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003E1ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #06137 | PC: 0x2d3444..0x2d34ac (104 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x2d3444: D503233F  paciasp  
//   0x2d3448: D10143FF  sub      sp, sp, #0x50
//   0x2d344c: A9037BFD  stp      x29, x30, [sp, #0x30]
//   0x2d3450: A9044FF4  stp      x20, x19, [sp, #0x40]
//   0x2d3454: 9100C3FD  add      x29, sp, #0x30
//   0x2d3458: 528000C8  mov      w8, #6
uint64_t fde_func_06137_0x2d3444(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x002D3444ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10143FFULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9037BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9044FF4ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9100C3FDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x528000C8ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x3DC00060ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9007C7FULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #06147 | PC: 0x2d37d8..0x2d38cc (244 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x2d37d8: D503233F  paciasp  
//   0x2d37dc: D101C3FF  sub      sp, sp, #0x70
//   0x2d37e0: A9037BFD  stp      x29, x30, [sp, #0x30]
//   0x2d37e4: F90023F7  str      x23, [sp, #0x40]
//   0x2d37e8: A90557F6  stp      x22, x21, [sp, #0x50]
//   0x2d37ec: A9064FF4  stp      x20, x19, [sp, #0x60]
uint64_t fde_func_06147_0x2d37d8(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x002D37D8ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD101C3FFULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9037BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF90023F7ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90557F6ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9064FF4ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9100C3FDULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0103F4ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #06156 | PC: 0x2d3d90..0x2d3e8c (252 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x2d3d90: D503245F  bti      c
//   0x2d3d94: D1000428  sub      x8, x1, #1
//   0x2d3d98: F100191F  cmp      x8, #6
//   0x2d3d9c: 54000648  b.hi     #0x2d3e64
//   0x2d3da0: 90FFED49  adrp     x9, #0x7b000
//   0x2d3da4: 91362129  add      x9, x9, #0xd88
uint64_t fde_func_06156_0x2d3d90(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x002D3D90ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD1000428ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF100191FULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x54000648ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x90FFED49ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91362129ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x1000008AULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x3868692BULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #06166 | PC: 0x2d4118..0x2d41f0 (216 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x2d4118: D503233F  paciasp  
//   0x2d411c: D10183FF  sub      sp, sp, #0x60
//   0x2d4120: A9037BFD  stp      x29, x30, [sp, #0x30]
//   0x2d4124: A90457F6  stp      x22, x21, [sp, #0x40]
//   0x2d4128: A9054FF4  stp      x20, x19, [sp, #0x50]
//   0x2d412c: 9100C3FD  add      x29, sp, #0x30
uint64_t fde_func_06166_0x2d4118(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x002D4118ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10183FFULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9037BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90457F6ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9054FF4ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9100C3FDULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9402009ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #06175 | PC: 0x2d45fc..0x2d464c (80 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x2d45fc: D503245F  bti      c
//   0x2d4600: A940A408  ldp      x8, x9, [x0, #8]
//   0x2d4604: EB09011F  cmp      x8, x9
//   0x2d4608: 54000202  b.hs     #0x2d4648
//   0x2d460c: A900FD1F  stp      xzr, xzr, [x8, #8]
//   0x2d4610: 9100810A  add      x10, x8, #0x20
uint64_t fde_func_06175_0x2d45fc(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x002D45FCULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA940A408ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xEB09011FULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x54000202ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA900FD1FULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9100810AULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF900011FULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400029ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #06185 | PC: 0x2d4888..0x2d48b0 (40 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x2d4888: D503233F  paciasp  
//   0x2d488c: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x2d4890: 910003FD  mov      x29, sp
//   0x2d4894: F9400C08  ldr      x8, [x0, #0x18]
//   0x2d4898: F100191F  cmp      x8, #6
//   0x2d489c: 54000081  b.ne     #0x2d48ac
uint64_t fde_func_06185_0x2d4888(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x002D4888ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BF7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400C08ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF100191FULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x54000081ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA8C17BFDULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD50323BFULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #06194 | PC: 0x2d4fc0..0x2d5064 (164 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x2d4fc0: D503233F  paciasp  
//   0x2d4fc4: D10103FF  sub      sp, sp, #0x40
//   0x2d4fc8: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x2d4fcc: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x2d4fd0: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x2d4fd4: 910043FD  add      x29, sp, #0x10
uint64_t fde_func_06194_0x2d4fc0(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x002D4FC0ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10103FFULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90257F6ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9034FF4ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F6ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x52800400ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #06204 | PC: 0x2d553c..0x2d55dc (160 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x2d553c: D503233F  paciasp  
//   0x2d5540: D10143FF  sub      sp, sp, #0x50
//   0x2d5544: A9037BFD  stp      x29, x30, [sp, #0x30]
//   0x2d5548: A9044FF4  stp      x20, x19, [sp, #0x40]
//   0x2d554c: 9100C3FD  add      x29, sp, #0x30
//   0x2d5550: AA0003F3  mov      x19, x0
uint64_t fde_func_06204_0x2d553c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x002D553CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10143FFULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9037BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9044FF4ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9100C3FDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9404014ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF0FFEDA1ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #06213 | PC: 0x2d5958..0x2d59e8 (144 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x2d5958: D503233F  paciasp  
//   0x2d595c: D100C3FF  sub      sp, sp, #0x30
//   0x2d5960: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x2d5964: F90013F3  str      x19, [sp, #0x20]
//   0x2d5968: 910043FD  add      x29, sp, #0x10
//   0x2d596c: AA0003F3  mov      x19, x0
uint64_t fde_func_06213_0x2d5958(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x002D5958ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD100C3FFULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF90013F3ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x52800800ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x3D8003E0ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #06223 | PC: 0x2d5e6c..0x2d5ed4 (104 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x2d5e6c: D503233F  paciasp  
//   0x2d5e70: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x2d5e74: F9000BF3  str      x19, [sp, #0x10]
//   0x2d5e78: 910003FD  mov      x29, sp
//   0x2d5e7c: 39400008  ldrb     w8, [x0]
//   0x2d5e80: AA0203F3  mov      x19, x2
uint64_t fde_func_06223_0x2d5e6c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x002D5E6CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF3ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x39400008ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0203F3ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400809ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x7200011FULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #06232 | PC: 0x2d6468..0x2d64c0 (88 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x2d6468: D503233F  paciasp  
//   0x2d646c: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x2d6470: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x2d6474: 910003FD  mov      x29, sp
//   0x2d6478: AA0003F3  mov      x19, x0
//   0x2d647c: F9400800  ldr      x0, [x0, #0x10]
uint64_t fde_func_06232_0x2d6468(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x002D6468ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9014FF4ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400800ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB40000A0ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400014ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #06242 | PC: 0x2d6dd8..0x2d6e90 (184 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x2d6dd8: D503233F  paciasp  
//   0x2d6ddc: A9BC7BFD  stp      x29, x30, [sp, #-0x40]!
//   0x2d6de0: A9015FF8  stp      x24, x23, [sp, #0x10]
//   0x2d6de4: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x2d6de8: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x2d6dec: 910003FD  mov      x29, sp
uint64_t fde_func_06242_0x2d6dd8(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x002D6DD8ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BC7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9015FF8ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90257F6ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9034FF4ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9402017ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0103F3ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #06252 | PC: 0x2d7688..0x2d7788 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x2d7688: D503233F  paciasp  
//   0x2d768c: D10343FF  sub      sp, sp, #0xd0
//   0x2d7690: A9087BFD  stp      x29, x30, [sp, #0x80]
//   0x2d7694: F9004BF9  str      x25, [sp, #0x90]
//   0x2d7698: A90A5FF8  stp      x24, x23, [sp, #0xa0]
//   0x2d769c: A90B57F6  stp      x22, x21, [sp, #0xb0]
uint64_t fde_func_06252_0x2d7688(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x002D7688ULL);
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

// FDE #06261 | PC: 0x2d7d98..0x2d7e38 (160 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x2d7d98: D503233F  paciasp  
//   0x2d7d9c: D102C3FF  sub      sp, sp, #0xb0
//   0x2d7da0: A9087BFD  stp      x29, x30, [sp, #0x80]
//   0x2d7da4: F9004BF5  str      x21, [sp, #0x90]
//   0x2d7da8: A90A4FF4  stp      x20, x19, [sp, #0xa0]
//   0x2d7dac: 910203FD  add      x29, sp, #0x80
uint64_t fde_func_06261_0x2d7d98(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x002D7D98ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD102C3FFULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9087BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9004BF5ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90A4FF4ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910203FDULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD53BD055ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0103F3ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #06271 | PC: 0x2d8690..0x2d8718 (136 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x2d8690: D503233F  paciasp  
//   0x2d8694: A9BD7BFD  stp      x29, x30, [sp, #-0x30]!
//   0x2d8698: F9000BF5  str      x21, [sp, #0x10]
//   0x2d869c: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x2d86a0: 910003FD  mov      x29, sp
//   0x2d86a4: 52800061  mov      w1, #3
uint64_t fde_func_06271_0x2d8690(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x002D8690ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BD7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF5ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9024FF4ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x52800061ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x2A0003F3ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x940ABF15ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #06280 | PC: 0x2d8db4..0x2d8eb4 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x2d8db4: D503233F  paciasp  
//   0x2d8db8: D10303FF  sub      sp, sp, #0xc0
//   0x2d8dbc: A9097BFD  stp      x29, x30, [sp, #0x90]
//   0x2d8dc0: A90A57F6  stp      x22, x21, [sp, #0xa0]
//   0x2d8dc4: A90B4FF4  stp      x20, x19, [sp, #0xb0]
//   0x2d8dc8: 910243FD  add      x29, sp, #0x90
uint64_t fde_func_06280_0x2d8db4(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x002D8DB4ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10303FFULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9097BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90A57F6ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90B4FF4ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910243FDULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD53BD056ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0203F4ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #06290 | PC: 0x2d982c..0x2d992c (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x2d982c: D503233F  paciasp  
//   0x2d9830: A9BC7BFD  stp      x29, x30, [sp, #-0x40]!
//   0x2d9834: F9000BFC  str      x28, [sp, #0x10]
//   0x2d9838: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x2d983c: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x2d9840: 910003FD  mov      x29, sp
uint64_t fde_func_06290_0x2d982c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x002D982CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BC7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BFCULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90257F6ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9034FF4ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10C03FFULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD53BD056ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #06299 | PC: 0x2da17c..0x2da1c8 (76 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x2da17c: D503233F  paciasp  
//   0x2da180: D10083FF  sub      sp, sp, #0x20
//   0x2da184: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x2da188: 910043FD  add      x29, sp, #0x10
//   0x2da18c: D10013A0  sub      x0, x29, #4
//   0x2da190: 910023E1  add      x1, sp, #8
uint64_t fde_func_06299_0x2da17c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x002DA17CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10083FFULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10013A0ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910023E1ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910013E2ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB81FC3BFULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #06309 | PC: 0x2da578..0x2da678 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x2da578: D503233F  paciasp  
//   0x2da57c: D10343FF  sub      sp, sp, #0xd0
//   0x2da580: A9097BFD  stp      x29, x30, [sp, #0x90]
//   0x2da584: F90053F7  str      x23, [sp, #0xa0]
//   0x2da588: A90B57F6  stp      x22, x21, [sp, #0xb0]
//   0x2da58c: A90C4FF4  stp      x20, x19, [sp, #0xc0]
uint64_t fde_func_06309_0x2da578(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x002DA578ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10343FFULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9097BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF90053F7ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90B57F6ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90C4FF4ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910243FDULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD53BD055ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #06318 | PC: 0x2da950..0x2da9b0 (96 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x2da950: D503233F  paciasp  
//   0x2da954: A9BD7BFD  stp      x29, x30, [sp, #-0x30]!
//   0x2da958: F9000BF5  str      x21, [sp, #0x10]
//   0x2da95c: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x2da960: 910003FD  mov      x29, sp
//   0x2da964: F9400008  ldr      x8, [x0]
uint64_t fde_func_06318_0x2da950(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x002DA950ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BD7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF5ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9024FF4ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400008ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9401D14ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9100C115ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #06328 | PC: 0x2db030..0x2db0a0 (112 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x2db030: D503233F  paciasp  
//   0x2db034: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x2db038: F9000BF3  str      x19, [sp, #0x10]
//   0x2db03c: 910003FD  mov      x29, sp
//   0x2db040: 90001828  adrp     x8, #0x5df000
//   0x2db044: 91006108  add      x8, x8, #0x18
uint64_t fde_func_06328_0x2db030(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x002DB030ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF3ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x90001828ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91006108ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xC8DFFD00ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF100041FULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #06337 | PC: 0x2db70c..0x2db7a4 (152 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x2db70c: D503233F  paciasp  
//   0x2db710: D10103FF  sub      sp, sp, #0x40
//   0x2db714: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x2db718: F9001BF3  str      x19, [sp, #0x30]
//   0x2db71c: 910083FD  add      x29, sp, #0x20
//   0x2db720: 39400008  ldrb     w8, [x0]
uint64_t fde_func_06337_0x2db70c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x002DB70CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10103FFULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9027BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9001BF3ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910083FDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x39400008ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0103F3ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400409ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #06347 | PC: 0x2dbb44..0x2dbbc0 (124 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x2dbb44: D503233F  paciasp  
//   0x2dbb48: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x2dbb4c: F9000BF3  str      x19, [sp, #0x10]
//   0x2dbb50: 910003FD  mov      x29, sp
//   0x2dbb54: AA0003F3  mov      x19, x0
//   0x2dbb58: F9402400  ldr      x0, [x0, #0x48]
uint64_t fde_func_06347_0x2dbb44(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x002DBB44ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF3ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9402400ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400008ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9439108ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #06356 | PC: 0x2dc038..0x2dc080 (72 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x2dc038: D503233F  paciasp  
//   0x2dc03c: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x2dc040: F9000BF3  str      x19, [sp, #0x10]
//   0x2dc044: 910003FD  mov      x29, sp
//   0x2dc048: F9400013  ldr      x19, [x0]
//   0x2dc04c: F9000001  str      x1, [x0]
uint64_t fde_func_06356_0x2dc038(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x002DC038ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF3ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400013ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000001ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB4000113ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA1303E0ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #06366 | PC: 0x2dc5c4..0x2dc5fc (56 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x2dc5c4: D503233F  paciasp  
//   0x2dc5c8: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x2dc5cc: 910003FD  mov      x29, sp
//   0x2dc5d0: 52800800  mov      w0, #0x40
//   0x2dc5d4: 52800801  mov      w1, #0x40
//   0x2dc5d8: 940AAEBA  bl       #0x5880c0
uint64_t fde_func_06366_0x2dc5c4(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x002DC5C4ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BF7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x52800800ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x52800801ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x940AAEBAULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB50000A0ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x940AB0A4ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #06375 | PC: 0x2dc8b4..0x2dc9b4 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x2dc8b4: D503233F  paciasp  
//   0x2dc8b8: D102C3FF  sub      sp, sp, #0xb0
//   0x2dc8bc: A9057BFD  stp      x29, x30, [sp, #0x50]
//   0x2dc8c0: A9066FFC  stp      x28, x27, [sp, #0x60]
//   0x2dc8c4: A90767FA  stp      x26, x25, [sp, #0x70]
//   0x2dc8c8: A9085FF8  stp      x24, x23, [sp, #0x80]
uint64_t fde_func_06375_0x2dc8b4(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x002DC8B4ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD102C3FFULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9057BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9066FFCULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90767FAULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9085FF8ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90957F6ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90A4FF4ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #06385 | PC: 0x2dccd8..0x2dcd34 (92 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x2dccd8: D503233F  paciasp  
//   0x2dccdc: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x2dcce0: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x2dcce4: 910003FD  mov      x29, sp
//   0x2dcce8: B00016F4  adrp     x20, #0x5b9000
//   0x2dccec: 91268294  add      x20, x20, #0x9a0
uint64_t fde_func_06385_0x2dccd8(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x002DCCD8ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9014FF4ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB00016F4ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91268294ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA1303E1ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #06394 | PC: 0x2dd3cc..0x2dd404 (56 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x2dd3cc: D503233F  paciasp  
//   0x2dd3d0: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x2dd3d4: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x2dd3d8: 910003FD  mov      x29, sp
//   0x2dd3dc: AA0103F3  mov      x19, x1
//   0x2dd3e0: AA0003F4  mov      x20, x0
uint64_t fde_func_06394_0x2dd3cc(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x002DD3CCULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9014FF4ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0103F3ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F4ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x97FEBBA6ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA1403E0ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #06404 | PC: 0x2ddab4..0x2ddac0 (12 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x2ddab4: D503245F  bti      c
//   0x2ddab8: AA0203E1  mov      x1, x2
//   0x2ddabc: 14000001  b        #0x2ddac0
uint64_t fde_func_06404_0x2ddab4(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x002DDAB4ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0203E1ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x14000001ULL ^ (2ULL << 32);
    return state ^ (state >> 29);
}

// FDE #06413 | PC: 0x2dde0c..0x2ddee4 (216 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x2dde0c: D503233F  paciasp  
//   0x2dde10: D10103FF  sub      sp, sp, #0x40
//   0x2dde14: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x2dde18: F90013F5  str      x21, [sp, #0x20]
//   0x2dde1c: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x2dde20: 910043FD  add      x29, sp, #0x10
uint64_t fde_func_06413_0x2dde0c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x002DDE0CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10103FFULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF90013F5ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9034FF4ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0103F4ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #06423 | PC: 0x2de1a4..0x2de1b8 (20 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x2de1a4: D503245F  bti      c
//   0x2de1a8: AA0203E1  mov      x1, x2
//   0x2de1ac: AA0303E2  mov      x2, x3
//   0x2de1b0: 2A0403E3  mov      w3, w4
//   0x2de1b4: 14000001  b        #0x2de1b8
uint64_t fde_func_06423_0x2de1a4(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x002DE1A4ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0203E1ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0303E2ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x2A0403E3ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x14000001ULL ^ (4ULL << 32);
    return state ^ (state >> 29);
}

// FDE #06432 | PC: 0x2de53c..0x2de634 (248 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x2de53c: D503233F  paciasp  
//   0x2de540: D10603FF  sub      sp, sp, #0x180
//   0x2de544: A9147BFD  stp      x29, x30, [sp, #0x140]
//   0x2de548: F900ABFC  str      x28, [sp, #0x150]
//   0x2de54c: A91657F6  stp      x22, x21, [sp, #0x160]
//   0x2de550: A9174FF4  stp      x20, x19, [sp, #0x170]
uint64_t fde_func_06432_0x2de53c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x002DE53CULL);
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

// FDE #06442 | PC: 0x2dec1c..0x2dec48 (44 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x2dec1c: D503233F  paciasp  
//   0x2dec20: D10083FF  sub      sp, sp, #0x20
//   0x2dec24: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x2dec28: 910043FD  add      x29, sp, #0x10
//   0x2dec2c: 910023E0  add      x0, sp, #8
//   0x2dec30: F90007E2  str      x2, [sp, #8]
uint64_t fde_func_06442_0x2dec1c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x002DEC1CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10083FFULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910023E0ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF90007E2ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x94000005ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9417BFDULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #06451 | PC: 0x2defc8..0x2df040 (120 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x2defc8: D503233F  paciasp  
//   0x2defcc: D10403FF  sub      sp, sp, #0x100
//   0x2defd0: A90F7BFD  stp      x29, x30, [sp, #0xf0]
//   0x2defd4: 9103C3FD  add      x29, sp, #0xf0
//   0x2defd8: D101A3A8  sub      x8, x29, #0x68
//   0x2defdc: 928004EA  mov      x10, #-0x28
uint64_t fde_func_06451_0x2defc8(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x002DEFC8ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10403FFULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90F7BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9103C3FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD101A3A8ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x928004EAULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003EBULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9100A108ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #06461 | PC: 0x2df940..0x2dfa40 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x2df940: D503233F  paciasp  
//   0x2df944: D101C3FF  sub      sp, sp, #0x70
//   0x2df948: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x2df94c: A90367FA  stp      x26, x25, [sp, #0x30]
//   0x2df950: A9045FF8  stp      x24, x23, [sp, #0x40]
//   0x2df954: A90557F6  stp      x22, x21, [sp, #0x50]
uint64_t fde_func_06461_0x2df940(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x002DF940ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD101C3FFULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9027BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90367FAULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9045FF8ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90557F6ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9064FF4ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910083FDULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #06470 | PC: 0x2e00b4..0x2e00e4 (48 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x2e00b4: D503245F  bti      c
//   0x2e00b8: A9402408  ldp      x8, x9, [x0]
//   0x2e00bc: CB080129  sub      x9, x9, x8
//   0x2e00c0: 9343FD29  asr      x9, x9, #3
//   0x2e00c4: EB01013F  cmp      x9, x1
//   0x2e00c8: 54000062  b.hs     #0x2e00d4
uint64_t fde_func_06470_0x2e00b4(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x002E00B4ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9402408ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xCB080129ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9343FD29ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xEB01013FULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x54000062ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xCB090021ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x140000B4ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #06480 | PC: 0x2e0964..0x2e0984 (32 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x2e0964: D503245F  bti      c
//   0x2e0968: AA0003E8  mov      x8, x0
//   0x2e096c: AA0103E0  mov      x0, x1
//   0x2e0970: AA0203E1  mov      x1, x2
//   0x2e0974: AA0803E2  mov      x2, x8
//   0x2e0978: A9007D1F  stp      xzr, xzr, [x8]
uint64_t fde_func_06480_0x2e0964(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x002E0964ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003E8ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0103E0ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0203E1ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0803E2ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9007D1FULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF900091FULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x17FFFF90ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #06489 | PC: 0x2e0ccc..0x2e0d24 (88 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x2e0ccc: D503233F  paciasp  
//   0x2e0cd0: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x2e0cd4: 910003FD  mov      x29, sp
//   0x2e0cd8: F00017E8  adrp     x8, #0x5df000
//   0x2e0cdc: D0FFECE1  adrp     x1, #0x7e000
//   0x2e0ce0: 91011021  add      x1, x1, #0x44
uint64_t fde_func_06489_0x2e0ccc(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x002E0CCCULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BF7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF00017E8ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD0FFECE1ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91011021ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9438900ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x97FEADB4ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #06499 | PC: 0x2e1974..0x2e19b8 (68 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x2e1974: D503233F  paciasp  
//   0x2e1978: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x2e197c: F9000BF3  str      x19, [sp, #0x10]
//   0x2e1980: 910003FD  mov      x29, sp
//   0x2e1984: F9400001  ldr      x1, [x0]
//   0x2e1988: B4000101  cbz      x1, #0x2e19a8
uint64_t fde_func_06499_0x2e1974(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x002E1974ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF3ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400001ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB4000101ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9400000AULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #06508 | PC: 0x2e1e68..0x2e1f28 (192 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x2e1e68: D503233F  paciasp  
//   0x2e1e6c: D105C3FF  sub      sp, sp, #0x170
//   0x2e1e70: A9147BFD  stp      x29, x30, [sp, #0x140]
//   0x2e1e74: A91557FC  stp      x28, x21, [sp, #0x150]
//   0x2e1e78: A9164FF4  stp      x20, x19, [sp, #0x160]
//   0x2e1e7c: 910503FD  add      x29, sp, #0x140
uint64_t fde_func_06508_0x2e1e68(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x002E1E68ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD105C3FFULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9147BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA91557FCULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9164FF4ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910503FDULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD53BD053ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9401668ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #06518 | PC: 0x2e2274..0x2e22dc (104 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x2e2274: D503233F  paciasp  
//   0x2e2278: D10103FF  sub      sp, sp, #0x40
//   0x2e227c: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x2e2280: F9001BF3  str      x19, [sp, #0x30]
//   0x2e2284: 910083FD  add      x29, sp, #0x20
//   0x2e2288: B4000122  cbz      x2, #0x2e22ac
uint64_t fde_func_06518_0x2e2274(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x002E2274ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10103FFULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9027BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9001BF3ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910083FDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB4000122ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0203F3ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x97FFEFA6ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #06527 | PC: 0x2e2618..0x2e2620 (8 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x2e2618: D503245F  bti      c
//   0x2e261c: 14000001  b        #0x2e2620
uint64_t fde_func_06527_0x2e2618(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x002E2618ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x14000001ULL ^ (1ULL << 32);
    return state ^ (state >> 29);
}

// FDE #06537 | PC: 0x2e28dc..0x2e2918 (60 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x2e28dc: D503245F  bti      c
//   0x2e28e0: B40001A0  cbz      x0, #0x2e2914
//   0x2e28e4: D503233F  paciasp  
//   0x2e28e8: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x2e28ec: F9000BF3  str      x19, [sp, #0x10]
//   0x2e28f0: 910003FD  mov      x29, sp
uint64_t fde_func_06537_0x2e28dc(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x002E28DCULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB40001A0ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE7BFDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF3ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9100A000ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #06547 | PC: 0x2e2dd8..0x2e2e78 (160 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x2e2dd8: D503233F  paciasp  
//   0x2e2ddc: D10183FF  sub      sp, sp, #0x60
//   0x2e2de0: A9037BFD  stp      x29, x30, [sp, #0x30]
//   0x2e2de4: F90023F5  str      x21, [sp, #0x40]
//   0x2e2de8: A9054FF4  stp      x20, x19, [sp, #0x50]
//   0x2e2dec: 9100C3FD  add      x29, sp, #0x30
uint64_t fde_func_06547_0x2e2dd8(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x002E2DD8ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10183FFULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9037BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF90023F5ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9054FF4ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9100C3FDULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0103F3ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F4ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #06556 | PC: 0x2e3338..0x2e337c (68 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x2e3338: D503233F  paciasp  
//   0x2e333c: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x2e3340: F9000BF3  str      x19, [sp, #0x10]
//   0x2e3344: 910003FD  mov      x29, sp
//   0x2e3348: F9400008  ldr      x8, [x0]
//   0x2e334c: B4000108  cbz      x8, #0x2e336c
uint64_t fde_func_06556_0x2e3338(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x002E3338ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF3ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400008ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB4000108ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x97FFEF94ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #06566 | PC: 0x2e3870..0x2e38d0 (96 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x2e3870: D503245F  bti      c
//   0x2e3874: B40002C2  cbz      x2, #0x2e38cc
//   0x2e3878: D503233F  paciasp  
//   0x2e387c: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x2e3880: F9000BF3  str      x19, [sp, #0x10]
//   0x2e3884: 910003FD  mov      x29, sp
uint64_t fde_func_06566_0x2e3870(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x002E3870ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB40002C2ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE7BFDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF3ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0203F3ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400040ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #06575 | PC: 0x2e3cac..0x2e3cd8 (44 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x2e3cac: D503233F  paciasp  
//   0x2e3cb0: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x2e3cb4: F9000BF3  str      x19, [sp, #0x10]
//   0x2e3cb8: 910003FD  mov      x29, sp
//   0x2e3cbc: AA0003F3  mov      x19, x0
//   0x2e3cc0: 94000006  bl       #0x2e3cd8
uint64_t fde_func_06575_0x2e3cac(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x002E3CACULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF3ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x94000006ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA1303E0ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400BF3ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #06585 | PC: 0x2e3fd0..0x2e400c (60 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x2e3fd0: D503233F  paciasp  
//   0x2e3fd4: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x2e3fd8: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x2e3fdc: 910003FD  mov      x29, sp
//   0x2e3fe0: AA0103F3  mov      x19, x1
//   0x2e3fe4: AA0003F4  mov      x20, x0
uint64_t fde_func_06585_0x2e3fd0(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x002E3FD0ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9014FF4ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0103F3ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F4ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x94000009ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003E8ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #06594 | PC: 0x2e48d0..0x2e48dc (12 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x2e48d0: D503245F  bti      c
//   0x2e48d4: 2A1F03E0  mov      w0, wzr
//   0x2e48d8: 17FEF31D  b        #0x2a154c
uint64_t fde_func_06594_0x2e48d0(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x002E48D0ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x2A1F03E0ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x17FEF31DULL ^ (2ULL << 32);
    return state ^ (state >> 29);
}

// FDE #06604 | PC: 0x2e4a9c..0x2e4ad8 (60 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x2e4a9c: D503233F  paciasp  
//   0x2e4aa0: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x2e4aa4: 910003FD  mov      x29, sp
//   0x2e4aa8: 97FFE9BF  bl       #0x2df1a4
//   0x2e4aac: 9400000B  bl       #0x2e4ad8
//   0x2e4ab0: 7100181F  cmp      w0, #6
uint64_t fde_func_06604_0x2e4a9c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x002E4A9CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BF7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x97FFE9BFULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9400000BULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x7100181FULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x540000A8ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD0FFEE88ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #06613 | PC: 0x2e4f8c..0x2e4fcc (64 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x2e4f8c: D503233F  paciasp  
//   0x2e4f90: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x2e4f94: F9000BF3  str      x19, [sp, #0x10]
//   0x2e4f98: 910003FD  mov      x29, sp
//   0x2e4f9c: F9400008  ldr      x8, [x0]
//   0x2e4fa0: F85E8108  ldur     x8, [x8, #-0x18]
uint64_t fde_func_06613_0x2e4f8c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x002E4F8CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF3ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400008ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF85E8108ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x8B080013ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA1303E0ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #06623 | PC: 0x2e5358..0x2e53a0 (72 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x2e5358: D503233F  paciasp  
//   0x2e535c: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x2e5360: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x2e5364: 910003FD  mov      x29, sp
//   0x2e5368: AA0003F4  mov      x20, x0
//   0x2e536c: 52800400  mov      w0, #0x20
uint64_t fde_func_06623_0x2e5358(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x002E5358ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9014FF4ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F4ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x52800400ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0103F3ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x97FFDC80ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #06632 | PC: 0x2e5f0c..0x2e600c (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x2e5f0c: D503233F  paciasp  
//   0x2e5f10: D10143FF  sub      sp, sp, #0x50
//   0x2e5f14: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x2e5f18: A90357F6  stp      x22, x21, [sp, #0x30]
//   0x2e5f1c: A9044FF4  stp      x20, x19, [sp, #0x40]
//   0x2e5f20: 910083FD  add      x29, sp, #0x20
uint64_t fde_func_06632_0x2e5f0c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x002E5F0CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10143FFULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9027BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90357F6ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9044FF4ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910083FDULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF940284AULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0203F3ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #06642 | PC: 0x2e6698..0x2e66f0 (88 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x2e6698: D503233F  paciasp  
//   0x2e669c: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x2e66a0: F9000BF3  str      x19, [sp, #0x10]
//   0x2e66a4: 910003FD  mov      x29, sp
//   0x2e66a8: F9400008  ldr      x8, [x0]
//   0x2e66ac: B4000128  cbz      x8, #0x2e66d0
uint64_t fde_func_06642_0x2e6698(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x002E6698ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF3ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400008ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB4000128ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9400000FULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #06651 | PC: 0x2e6b98..0x2e6bf4 (92 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x2e6b98: D503233F  paciasp  
//   0x2e6b9c: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x2e6ba0: F9000BF3  str      x19, [sp, #0x10]
//   0x2e6ba4: 910003FD  mov      x29, sp
//   0x2e6ba8: F9400401  ldr      x1, [x0, #8]
//   0x2e6bac: AA0003F3  mov      x19, x0
uint64_t fde_func_06651_0x2e6b98(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x002E6B98ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF3ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400401ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x94000011ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400260ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #06661 | PC: 0x2e71d0..0x2e7204 (52 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x2e71d0: D503233F  paciasp  
//   0x2e71d4: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x2e71d8: F9000BF3  str      x19, [sp, #0x10]
//   0x2e71dc: 910003FD  mov      x29, sp
//   0x2e71e0: AA0103F3  mov      x19, x1
//   0x2e71e4: 97FE958C  bl       #0x28c814
uint64_t fde_func_06661_0x2e71d0(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x002E71D0ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF3ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0103F3ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x97FE958CULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91014260ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x97FFFD2BULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #06670 | PC: 0x2e77b8..0x2e7838 (128 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x2e77b8: D503233F  paciasp  
//   0x2e77bc: D10083FF  sub      sp, sp, #0x20
//   0x2e77c0: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x2e77c4: 910043FD  add      x29, sp, #0x10
//   0x2e77c8: 910003E1  mov      x1, sp
//   0x2e77cc: 52800020  mov      w0, #1
uint64_t fde_func_06670_0x2e77b8(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x002E77B8ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10083FFULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003E1ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x52800020ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x940A7FA8ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x350002E0ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #06680 | PC: 0x2e7d0c..0x2e7db0 (164 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x2e7d0c: D503233F  paciasp  
//   0x2e7d10: D10183FF  sub      sp, sp, #0x60
//   0x2e7d14: A9037BFD  stp      x29, x30, [sp, #0x30]
//   0x2e7d18: F90023F5  str      x21, [sp, #0x40]
//   0x2e7d1c: A9054FF4  stp      x20, x19, [sp, #0x50]
//   0x2e7d20: 9100C3FD  add      x29, sp, #0x30
uint64_t fde_func_06680_0x2e7d0c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x002E7D0CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10183FFULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9037BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF90023F5ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9054FF4ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9100C3FDULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0103F4ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #06689 | PC: 0x2e8200..0x2e8244 (68 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x2e8200: D503245F  bti      c
//   0x2e8204: 39400008  ldrb     w8, [x0]
//   0x2e8208: 370000A8  tbnz     w8, #0, #0x2e821c
//   0x2e820c: D341FD08  lsr      x8, x8, #1
//   0x2e8210: B40000A8  cbz      x8, #0x2e8224
//   0x2e8214: 2A1F03E0  mov      w0, wzr
uint64_t fde_func_06689_0x2e8200(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x002E8200ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x39400008ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x370000A8ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD341FD08ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB40000A8ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x2A1F03E0ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD65F03C0ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400408ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #06699 | PC: 0x2e86f4..0x2e8728 (52 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x2e86f4: D503233F  paciasp  
//   0x2e86f8: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x2e86fc: F9000BF3  str      x19, [sp, #0x10]
//   0x2e8700: 910003FD  mov      x29, sp
//   0x2e8704: AA0003F3  mov      x19, x0
//   0x2e8708: 91022000  add      x0, x0, #0x88
uint64_t fde_func_06699_0x2e86f4(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x002E86F4ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF3ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91022000ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x97FC492DULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB900927FULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #06708 | PC: 0x2e88f4..0x2e891c (40 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x2e88f4: D503245F  bti      c
//   0x2e88f8: 39400008  ldrb     w8, [x0]
//   0x2e88fc: 37000068  tbnz     w8, #0, #0x2e8908
//   0x2e8900: 91000408  add      x8, x0, #1
//   0x2e8904: 14000002  b        #0x2e890c
//   0x2e8908: F9400808  ldr      x8, [x0, #0x10]
uint64_t fde_func_06708_0x2e88f4(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x002E88F4ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x39400008ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x37000068ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91000408ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x14000002ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400808ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xCB080028ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xCB010042ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #06718 | PC: 0x2e8c70..0x2e8d04 (148 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x2e8c70: D503233F  paciasp  
//   0x2e8c74: D10103FF  sub      sp, sp, #0x40
//   0x2e8c78: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x2e8c7c: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x2e8c80: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x2e8c84: 910043FD  add      x29, sp, #0x10
uint64_t fde_func_06718_0x2e8c70(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x002E8C70ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10103FFULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90257F6ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9034FF4ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9100C015ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F6ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #06727 | PC: 0x2e91a8..0x2e91f8 (80 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x2e91a8: D503233F  paciasp  
//   0x2e91ac: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x2e91b0: F9000BF3  str      x19, [sp, #0x10]
//   0x2e91b4: 910003FD  mov      x29, sp
//   0x2e91b8: AA0003F3  mov      x19, x0
//   0x2e91bc: D0001589  adrp     x9, #0x59b000
uint64_t fde_func_06727_0x2e91a8(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x002E91A8ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF3ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD0001589ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x911B0129ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x52800028ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #06737 | PC: 0x2e9ae8..0x2e9b30 (72 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x2e9ae8: D503233F  paciasp  
//   0x2e9aec: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x2e9af0: F9000BF3  str      x19, [sp, #0x10]
//   0x2e9af4: 910003FD  mov      x29, sp
//   0x2e9af8: F9400013  ldr      x19, [x0]
//   0x2e9afc: F900001F  str      xzr, [x0]
uint64_t fde_func_06737_0x2e9ae8(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x002E9AE8ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF3ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400013ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF900001FULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB4000113ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA1303E0ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #06746 | PC: 0x2e9e84..0x2e9efc (120 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x2e9e84: D503233F  paciasp  
//   0x2e9e88: D10103FF  sub      sp, sp, #0x40
//   0x2e9e8c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x2e9e90: F90013F5  str      x21, [sp, #0x20]
//   0x2e9e94: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x2e9e98: 910043FD  add      x29, sp, #0x10
uint64_t fde_func_06746_0x2e9e84(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x002E9E84ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10103FFULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF90013F5ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9034FF4ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0103F4ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0203E1ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #06756 | PC: 0x2ea1f8..0x2ea234 (60 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x2ea1f8: D503233F  paciasp  
//   0x2ea1fc: D10083FF  sub      sp, sp, #0x20
//   0x2ea200: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x2ea204: 910043FD  add      x29, sp, #0x10
//   0x2ea208: A9422009  ldp      x9, x8, [x0, #0x20]
//   0x2ea20c: F900141F  str      xzr, [x0, #0x28]
uint64_t fde_func_06756_0x2ea1f8(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x002EA1F8ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10083FFULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9422009ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF900141FULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910023E0ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF90007E8ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #06765 | PC: 0x2ea620..0x2ea6c4 (164 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x2ea620: D503233F  paciasp  
//   0x2ea624: D10143FF  sub      sp, sp, #0x50
//   0x2ea628: A9037BFD  stp      x29, x30, [sp, #0x30]
//   0x2ea62c: A9044FF4  stp      x20, x19, [sp, #0x40]
//   0x2ea630: 9100C3FD  add      x29, sp, #0x30
//   0x2ea634: AA0003F3  mov      x19, x0
uint64_t fde_func_06765_0x2ea620(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x002EA620ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10143FFULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9037BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9044FF4ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9100C3FDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910063E0ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0103F4ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #06775 | PC: 0x2eaa68..0x2eab68 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x2eaa68: D503233F  paciasp  
//   0x2eaa6c: D10303FF  sub      sp, sp, #0xc0
//   0x2eaa70: A9087BFD  stp      x29, x30, [sp, #0x80]
//   0x2eaa74: A9095FF8  stp      x24, x23, [sp, #0x90]
//   0x2eaa78: A90A57F6  stp      x22, x21, [sp, #0xa0]
//   0x2eaa7c: A90B4FF4  stp      x20, x19, [sp, #0xb0]
uint64_t fde_func_06775_0x2eaa68(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x002EAA68ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10303FFULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9087BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9095FF8ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90A57F6ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90B4FF4ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910203FDULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9406008ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #06784 | PC: 0x2eb484..0x2eb4d0 (76 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x2eb484: D503233F  paciasp  
//   0x2eb488: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x2eb48c: F9000BF3  str      x19, [sp, #0x10]
//   0x2eb490: 910003FD  mov      x29, sp
//   0x2eb494: D35FFC28  lsr      x8, x1, #0x1f
//   0x2eb498: 90001589  adrp     x9, #0x59b000
uint64_t fde_func_06784_0x2eb484(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x002EB484ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF3ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD35FFC28ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x90001589ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x911C8129ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB900081FULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #06794 | PC: 0x2eb6ec..0x2eb720 (52 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x2eb6ec: D503245F  bti      c
//   0x2eb6f0: D35FFC48  lsr      x8, x2, #0x1f
//   0x2eb6f4: 90001589  adrp     x9, #0x59b000
//   0x2eb6f8: 911E0129  add      x9, x9, #0x780
//   0x2eb6fc: F940082A  ldr      x10, [x1, #0x10]
//   0x2eb700: B900081F  str      wzr, [x0, #8]
uint64_t fde_func_06794_0x2eb6ec(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x002EB6ECULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD35FFC48ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x90001589ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x911E0129ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF940082AULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB900081FULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x29047C02ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000009ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #06803 | PC: 0x2eb8d4..0x2eb8fc (40 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x2eb8d4: D503245F  bti      c
//   0x2eb8d8: 39404008  ldrb     w8, [x0, #0x10]
//   0x2eb8dc: 39404029  ldrb     w9, [x1, #0x10]
//   0x2eb8e0: 6B09011F  cmp      w8, w9
//   0x2eb8e4: 54000081  b.ne     #0x2eb8f4
//   0x2eb8e8: AA0103E2  mov      x2, x1
uint64_t fde_func_06803_0x2eb8d4(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x002EB8D4ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x39404008ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x39404029ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x6B09011FULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x54000081ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0103E2ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x8B080001ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x17FCB729ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #06813 | PC: 0x2ebe1c..0x2ebe50 (52 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x2ebe1c: D503245F  bti      c
//   0x2ebe20: F9400008  ldr      x8, [x0]
//   0x2ebe24: B4000128  cbz      x8, #0x2ebe48
//   0x2ebe28: F100403F  cmp      x1, #0x10
//   0x2ebe2c: 540000E8  b.hi     #0x2ebe48
//   0x2ebe30: 39404109  ldrb     w9, [x8, #0x10]
uint64_t fde_func_06813_0x2ebe1c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x002EBE1CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400008ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB4000128ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF100403FULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x540000E8ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x39404109ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x350000A9ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x52800029ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #06822 | PC: 0x2ec18c..0x2ec258 (204 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x2ec18c: D503233F  paciasp  
//   0x2ec190: D10203FF  sub      sp, sp, #0x80
//   0x2ec194: A9057BFD  stp      x29, x30, [sp, #0x50]
//   0x2ec198: A90657F6  stp      x22, x21, [sp, #0x60]
//   0x2ec19c: A9074FF4  stp      x20, x19, [sp, #0x70]
//   0x2ec1a0: 910143FD  add      x29, sp, #0x50
uint64_t fde_func_06822_0x2ec18c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x002EC18CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10203FFULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9057BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90657F6ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9074FF4ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910143FDULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD53BD056ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F4ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #06832 | PC: 0x2ec92c..0x2ec99c (112 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x2ec92c: D503233F  paciasp  
//   0x2ec930: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x2ec934: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x2ec938: 910003FD  mov      x29, sp
//   0x2ec93c: 39404008  ldrb     w8, [x0, #0x10]
//   0x2ec940: 39404029  ldrb     w9, [x1, #0x10]
uint64_t fde_func_06832_0x2ec92c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x002EC92CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9014FF4ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x39404008ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x39404029ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x6B09011FULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x54000201ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #06842 | PC: 0x2ed188..0x2ed1e0 (88 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x2ed188: D503233F  paciasp  
//   0x2ed18c: A9BD7BFD  stp      x29, x30, [sp, #-0x30]!
//   0x2ed190: F9000BF5  str      x21, [sp, #0x10]
//   0x2ed194: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x2ed198: 910003FD  mov      x29, sp
//   0x2ed19c: AA0003F4  mov      x20, x0
uint64_t fde_func_06842_0x2ed188(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x002ED188ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BD7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF5ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9024FF4ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F4ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x52800E00ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0203F3ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #06851 | PC: 0x2ed6e0..0x2ed7c4 (228 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x2ed6e0: D503233F  paciasp  
//   0x2ed6e4: D10603FF  sub      sp, sp, #0x180
//   0x2ed6e8: A9157BFD  stp      x29, x30, [sp, #0x150]
//   0x2ed6ec: A91657FC  stp      x28, x21, [sp, #0x160]
//   0x2ed6f0: A9174FF4  stp      x20, x19, [sp, #0x170]
//   0x2ed6f4: 910543FD  add      x29, sp, #0x150
uint64_t fde_func_06851_0x2ed6e0(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x002ED6E0ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10603FFULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9157BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA91657FCULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9174FF4ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910543FDULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD53BD055ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F4ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #06861 | PC: 0x2edd10..0x2ede10 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x2edd10: D503233F  paciasp  
//   0x2edd14: A9BD7BFD  stp      x29, x30, [sp, #-0x30]!
//   0x2edd18: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x2edd1c: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x2edd20: 910003FD  mov      x29, sp
//   0x2edd24: 52800902  mov      w2, #0x48
uint64_t fde_func_06861_0x2edd10(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x002EDD10ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BD7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90157F6ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9024FF4ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x52800902ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0103F3ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F4ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #06870 | PC: 0x2ee414..0x2ee4d8 (196 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x2ee414: D503233F  paciasp  
//   0x2ee418: D10603FF  sub      sp, sp, #0x180
//   0x2ee41c: A9147BFD  stp      x29, x30, [sp, #0x140]
//   0x2ee420: F900ABFC  str      x28, [sp, #0x150]
//   0x2ee424: A91657F6  stp      x22, x21, [sp, #0x160]
//   0x2ee428: A9174FF4  stp      x20, x19, [sp, #0x170]
uint64_t fde_func_06870_0x2ee414(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x002EE414ULL);
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

// FDE #06880 | PC: 0x2ee5fc..0x2ee608 (12 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x2ee5fc: D503245F  bti      c
//   0x2ee600: D100C000  sub      x0, x0, #0x30
//   0x2ee604: 17FFFF84  b        #0x2ee414
uint64_t fde_func_06880_0x2ee5fc(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x002EE5FCULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD100C000ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x17FFFF84ULL ^ (2ULL << 32);
    return state ^ (state >> 29);
}

// FDE #06889 | PC: 0x2ee900..0x2ee90c (12 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x2ee900: D503245F  bti      c
//   0x2ee904: 29490801  ldp      w1, w2, [x0, #0x48]
//   0x2ee908: 17FD1C81  b        #0x235b0c
uint64_t fde_func_06889_0x2ee900(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x002EE900ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x29490801ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x17FD1C81ULL ^ (2ULL << 32);
    return state ^ (state >> 29);
}

// FDE #06899 | PC: 0x2f02b0..0x2f035c (172 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x2f02b0: D503233F  paciasp  
//   0x2f02b4: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x2f02b8: F9000BF3  str      x19, [sp, #0x10]
//   0x2f02bc: 910003FD  mov      x29, sp
//   0x2f02c0: AA0003F3  mov      x19, x0
//   0x2f02c4: F0001548  adrp     x8, #0x59b000
uint64_t fde_func_06899_0x2f02b0(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x002F02B0ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF3ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF0001548ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91244108ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400C00ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #06908 | PC: 0x2f05b4..0x2f05e0 (44 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x2f05b4: D503245F  bti      c
//   0x2f05b8: F0001768  adrp     x8, #0x5df000
//   0x2f05bc: F943ED08  ldr      x8, [x8, #0x7d8]
//   0x2f05c0: B40000C8  cbz      x8, #0x2f05d8
//   0x2f05c4: F9400109  ldr      x9, [x8]
//   0x2f05c8: AA0003E1  mov      x1, x0
uint64_t fde_func_06908_0x2f05b4(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x002F05B4ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF0001768ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF943ED08ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB40000C8ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400109ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003E1ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0803E0ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9402130ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #06918 | PC: 0x2f06ec..0x2f07ec (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x2f06ec: D503233F  paciasp  
//   0x2f06f0: D10303FF  sub      sp, sp, #0xc0
//   0x2f06f4: A9067BFD  stp      x29, x30, [sp, #0x60]
//   0x2f06f8: A9076FFC  stp      x28, x27, [sp, #0x70]
//   0x2f06fc: A90867FA  stp      x26, x25, [sp, #0x80]
//   0x2f0700: A9095FF8  stp      x24, x23, [sp, #0x90]
uint64_t fde_func_06918_0x2f06ec(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x002F06ECULL);
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

// FDE #06927 | PC: 0x2f13cc..0x2f143c (112 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x2f13cc: D503233F  paciasp  
//   0x2f13d0: A9BD7BFD  stp      x29, x30, [sp, #-0x30]!
//   0x2f13d4: F9000BF5  str      x21, [sp, #0x10]
//   0x2f13d8: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x2f13dc: 910003FD  mov      x29, sp
//   0x2f13e0: AA0003F3  mov      x19, x0
uint64_t fde_func_06927_0x2f13cc(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x002F13CCULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BD7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF5ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9024FF4ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9402814ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD0001548ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #06937 | PC: 0x2f16d8..0x2f1748 (112 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x2f16d8: D503233F  paciasp  
//   0x2f16dc: A9BD7BFD  stp      x29, x30, [sp, #-0x30]!
//   0x2f16e0: F9000BF5  str      x21, [sp, #0x10]
//   0x2f16e4: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x2f16e8: 910003FD  mov      x29, sp
//   0x2f16ec: AA0003F3  mov      x19, x0
uint64_t fde_func_06937_0x2f16d8(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x002F16D8ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BD7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF5ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9024FF4ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9402814ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD0001548ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #06946 | PC: 0x2f2a80..0x2f2b80 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x2f2a80: D503233F  paciasp  
//   0x2f2a84: D10183FF  sub      sp, sp, #0x60
//   0x2f2a88: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x2f2a8c: F9001BF7  str      x23, [sp, #0x30]
//   0x2f2a90: A90457F6  stp      x22, x21, [sp, #0x40]
//   0x2f2a94: A9054FF4  stp      x20, x19, [sp, #0x50]
uint64_t fde_func_06946_0x2f2a80(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x002F2A80ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10183FFULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9027BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9001BF7ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90457F6ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9054FF4ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910083FDULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD53BD056ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #06956 | PC: 0x2f3b70..0x2f3b7c (12 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x2f3b70: D503245F  bti      c
//   0x2f3b74: D1004000  sub      x0, x0, #0x10
//   0x2f3b78: 17FFFFCE  b        #0x2f3ab0
uint64_t fde_func_06956_0x2f3b70(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x002F3B70ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD1004000ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x17FFFFCEULL ^ (2ULL << 32);
    return state ^ (state >> 29);
}

// FDE #06965 | PC: 0x2f4230..0x2f4330 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x2f4230: D503233F  paciasp  
//   0x2f4234: D10103FF  sub      sp, sp, #0x40
//   0x2f4238: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x2f423c: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x2f4240: 910083FD  add      x29, sp, #0x20
//   0x2f4244: F0001748  adrp     x8, #0x5df000
uint64_t fde_func_06965_0x2f4230(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x002F4230ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10103FFULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9027BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9034FF4ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910083FDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF0001748ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF943ED08ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF100011FULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #06975 | PC: 0x2f4fa8..0x2f4fcc (36 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x2f4fa8: D503233F  paciasp  
//   0x2f4fac: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x2f4fb0: 910003FD  mov      x29, sp
//   0x2f4fb4: 97FFED64  bl       #0x2f0544
//   0x2f4fb8: 7100081F  cmp      w0, #2
//   0x2f4fbc: 1A9F17E0  cset     w0, eq
uint64_t fde_func_06975_0x2f4fa8(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x002F4FA8ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BF7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x97FFED64ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x7100081FULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x1A9F17E0ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA8C17BFDULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD50323BFULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #06984 | PC: 0x2f5488..0x2f549c (20 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x2f5488: D503245F  bti      c
//   0x2f548c: D0001528  adrp     x8, #0x59b000
//   0x2f5490: 91354108  add      x8, x8, #0xd50
//   0x2f5494: F9000008  str      x8, [x0]
//   0x2f5498: D65F03C0  ret      
uint64_t fde_func_06984_0x2f5488(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x002F5488ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD0001528ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91354108ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000008ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD65F03C0ULL ^ (4ULL << 32);
    return state ^ (state >> 29);
}

// FDE #06994 | PC: 0x2f5a6c..0x2f5ac4 (88 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x2f5a6c: D503233F  paciasp  
//   0x2f5a70: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x2f5a74: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x2f5a78: 910003FD  mov      x29, sp
//   0x2f5a7c: AA0103F3  mov      x19, x1
//   0x2f5a80: AA0003F4  mov      x20, x0
uint64_t fde_func_06994_0x2f5a6c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x002F5A6CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9014FF4ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0103F3ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F4ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x940A4509ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91006280ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #07003 | PC: 0x2f5d88..0x2f5dd8 (80 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x2f5d88: D503233F  paciasp  
//   0x2f5d8c: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x2f5d90: F9000BF3  str      x19, [sp, #0x10]
//   0x2f5d94: 910003FD  mov      x29, sp
//   0x2f5d98: 39400008  ldrb     w8, [x0]
//   0x2f5d9c: 34000108  cbz      w8, #0x2f5dbc
uint64_t fde_func_07003_0x2f5d88(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x002F5D88ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF3ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x39400008ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x34000108ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x97FFDC85ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #07013 | PC: 0x2f6734..0x2f67c4 (144 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x2f6734: D503233F  paciasp  
//   0x2f6738: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x2f673c: F9000BF3  str      x19, [sp, #0x10]
//   0x2f6740: 910003FD  mov      x29, sp
//   0x2f6744: AA0003F3  mov      x19, x0
//   0x2f6748: AA1F03E9  mov      x9, xzr
uint64_t fde_func_07013_0x2f6734(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x002F6734ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF3ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA1F03E9ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA1F03E8ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA940AC2AULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #07022 | PC: 0x2f6bcc..0x2f6bfc (48 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x2f6bcc: D503233F  paciasp  
//   0x2f6bd0: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x2f6bd4: F9000BF3  str      x19, [sp, #0x10]
//   0x2f6bd8: 910003FD  mov      x29, sp
//   0x2f6bdc: AA0003F3  mov      x19, x0
//   0x2f6be0: F9401400  ldr      x0, [x0, #0x28]
uint64_t fde_func_07022_0x2f6bcc(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x002F6BCCULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF3ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9401400ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x97FE5247ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9401260ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #07032 | PC: 0x2f73f4..0x2f7404 (16 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x2f73f4: D503245F  bti      c
//   0x2f73f8: F9400408  ldr      x8, [x0, #8]
//   0x2f73fc: D100E101  sub      x1, x8, #0x38
//   0x2f7400: 14000001  b        #0x2f7404
uint64_t fde_func_07032_0x2f73f4(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x002F73F4ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400408ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD100E101ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x14000001ULL ^ (3ULL << 32);
    return state ^ (state >> 29);
}

// FDE #07041 | PC: 0x2f7864..0x2f7964 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x2f7864: D503233F  paciasp  
//   0x2f7868: D10303FF  sub      sp, sp, #0xc0
//   0x2f786c: A90A7BFD  stp      x29, x30, [sp, #0xa0]
//   0x2f7870: A90B4FF4  stp      x20, x19, [sp, #0xb0]
//   0x2f7874: 910283FD  add      x29, sp, #0xa0
//   0x2f7878: B9400028  ldr      w8, [x1]
uint64_t fde_func_07041_0x2f7864(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x002F7864ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10303FFULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90A7BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90B4FF4ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910283FDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB9400028ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0103F4ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #07051 | PC: 0x2f8788..0x2f87c4 (60 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x2f8788: D503233F  paciasp  
//   0x2f878c: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x2f8790: F9000BF3  str      x19, [sp, #0x10]
//   0x2f8794: 910003FD  mov      x29, sp
//   0x2f8798: AA0003F3  mov      x19, x0
//   0x2f879c: 91008000  add      x0, x0, #0x20
uint64_t fde_func_07051_0x2f8788(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x002F8788ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF3ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91008000ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF0001508ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9137C108ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #07060 | PC: 0x2f8b84..0x2f8bb0 (44 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x2f8b84: D503233F  paciasp  
//   0x2f8b88: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x2f8b8c: F9000BF3  str      x19, [sp, #0x10]
//   0x2f8b90: 910003FD  mov      x29, sp
//   0x2f8b94: AA0003F3  mov      x19, x0
//   0x2f8b98: 97FFFFEC  bl       #0x2f8b48
uint64_t fde_func_07060_0x2f8b84(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x002F8B84ULL);
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

// FDE #07070 | PC: 0x2f9528..0x2f95a0 (120 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x2f9528: D503233F  paciasp  
//   0x2f952c: A9BD7BFD  stp      x29, x30, [sp, #-0x30]!
//   0x2f9530: F9000BF5  str      x21, [sp, #0x10]
//   0x2f9534: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x2f9538: 910003FD  mov      x29, sp
//   0x2f953c: A941200A  ldp      x10, x8, [x0, #0x10]
uint64_t fde_func_07070_0x2f9528(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x002F9528ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BD7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF5ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9024FF4ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA941200AULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x93407C49ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #07079 | PC: 0x2f9848..0x2f9948 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x2f9848: D503233F  paciasp  
//   0x2f984c: D10203FF  sub      sp, sp, #0x80
//   0x2f9850: A9047BFD  stp      x29, x30, [sp, #0x40]
//   0x2f9854: A9055FF8  stp      x24, x23, [sp, #0x50]
//   0x2f9858: A90657F6  stp      x22, x21, [sp, #0x60]
//   0x2f985c: A9074FF4  stp      x20, x19, [sp, #0x70]
uint64_t fde_func_07079_0x2f9848(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x002F9848ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10203FFULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9047BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9055FF8ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90657F6ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9074FF4ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910103FDULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9402817ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #07089 | PC: 0x2f9d64..0x2f9e64 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x2f9d64: D503233F  paciasp  
//   0x2f9d68: A9BB7BFD  stp      x29, x30, [sp, #-0x50]!
//   0x2f9d6c: F9000BF9  str      x25, [sp, #0x10]
//   0x2f9d70: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x2f9d74: A90357F6  stp      x22, x21, [sp, #0x30]
//   0x2f9d78: A9044FF4  stp      x20, x19, [sp, #0x40]
uint64_t fde_func_07089_0x2f9d64(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x002F9D64ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BB7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF9ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9025FF8ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90357F6ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9044FF4ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9402809ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #07098 | PC: 0x2fa568..0x2fa668 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x2fa568: D503233F  paciasp  
//   0x2fa56c: D10243FF  sub      sp, sp, #0x90
//   0x2fa570: A9047BFD  stp      x29, x30, [sp, #0x40]
//   0x2fa574: A90567FA  stp      x26, x25, [sp, #0x50]
//   0x2fa578: A9065FF8  stp      x24, x23, [sp, #0x60]
//   0x2fa57c: A90757F6  stp      x22, x21, [sp, #0x70]
uint64_t fde_func_07098_0x2fa568(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x002FA568ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10243FFULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9047BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90567FAULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9065FF8ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90757F6ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9084FF4ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910103FDULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #07108 | PC: 0x2fabd0..0x2fac14 (68 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x2fabd0: D503233F  paciasp  
//   0x2fabd4: D100C3FF  sub      sp, sp, #0x30
//   0x2fabd8: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x2fabdc: F90013F3  str      x19, [sp, #0x20]
//   0x2fabe0: 910043FD  add      x29, sp, #0x10
//   0x2fabe4: AA0003F3  mov      x19, x0
uint64_t fde_func_07108_0x2fabd0(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x002FABD0ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD100C3FFULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF90013F3ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003E0ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x97FEA822ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #07117 | PC: 0x2fb598..0x2fb5dc (68 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x2fb598: D503233F  paciasp  
//   0x2fb59c: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x2fb5a0: F9000BF3  str      x19, [sp, #0x10]
//   0x2fb5a4: 910003FD  mov      x29, sp
//   0x2fb5a8: AA0003F3  mov      x19, x0
//   0x2fb5ac: F9400800  ldr      x0, [x0, #0x10]
uint64_t fde_func_07117_0x2fb598(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x002FB598ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF3ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400800ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400008ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400D08ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #07127 | PC: 0x2fbb94..0x2fbbe0 (76 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x2fbb94: D503245F  bti      c
//   0x2fbb98: B4000220  cbz      x0, #0x2fbbdc
//   0x2fbb9c: D503233F  paciasp  
//   0x2fbba0: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x2fbba4: F9000BF3  str      x19, [sp, #0x10]
//   0x2fbba8: 910003FD  mov      x29, sp
uint64_t fde_func_07127_0x2fbb94(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x002FBB94ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB4000220ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE7BFDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF3ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400000ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #07137 | PC: 0x2fd3a0..0x2fd3b0 (16 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x2fd3a0: D503245F  bti      c
//   0x2fd3a4: 12800028  mov      w8, #-2
//   0x2fd3a8: B8008408  str      w8, [x0], #8
//   0x2fd3ac: 1400256E  b        #0x306964
uint64_t fde_func_07137_0x2fd3a0(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x002FD3A0ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x12800028ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB8008408ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x1400256EULL ^ (3ULL << 32);
    return state ^ (state >> 29);
}

// FDE #07146 | PC: 0x2fda48..0x2fdaa8 (96 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x2fda48: D503233F  paciasp  
//   0x2fda4c: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x2fda50: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x2fda54: 910003FD  mov      x29, sp
//   0x2fda58: F9400008  ldr      x8, [x0]
//   0x2fda5c: AA0003F4  mov      x20, x0
uint64_t fde_func_07146_0x2fda48(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x002FDA48ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9014FF4ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400008ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F4ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0103F3ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xEB01011FULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #07156 | PC: 0x2fdf68..0x2fdf94 (44 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x2fdf68: D503233F  paciasp  
//   0x2fdf6c: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x2fdf70: F9000BF3  str      x19, [sp, #0x10]
//   0x2fdf74: 910003FD  mov      x29, sp
//   0x2fdf78: AA0003F3  mov      x19, x0
//   0x2fdf7c: 97FFFFDF  bl       #0x2fdef8
uint64_t fde_func_07156_0x2fdf68(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x002FDF68ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF3ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x97FFFFDFULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA1303E0ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400BF3ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #07165 | PC: 0x2fe960..0x2fea60 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x2fe960: D503233F  paciasp  
//   0x2fe964: A9BB7BFD  stp      x29, x30, [sp, #-0x50]!
//   0x2fe968: F9000BF9  str      x25, [sp, #0x10]
//   0x2fe96c: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x2fe970: A90357F6  stp      x22, x21, [sp, #0x30]
//   0x2fe974: A9044FF4  stp      x20, x19, [sp, #0x40]
uint64_t fde_func_07165_0x2fe960(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x002FE960ULL);
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

// FDE #07175 | PC: 0x2fefa0..0x2fefd0 (48 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x2fefa0: D503245F  bti      c
//   0x2fefa4: 885FFC08  ldaxr    w8, [x0]
//   0x2fefa8: 71000508  subs     w8, w8, #1
//   0x2fefac: 8809FC08  stlxr    w9, w8, [x0]
//   0x2fefb0: 35FFFFA9  cbnz     w9, #0x2fefa4
//   0x2fefb4: 540000C1  b.ne     #0x2fefcc
uint64_t fde_func_07175_0x2fefa0(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x002FEFA0ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x885FFC08ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x71000508ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x8809FC08ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x35FFFFA9ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x540000C1ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF1002000ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x54000080ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #07184 | PC: 0x2ff70c..0x2ff80c (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x2ff70c: D503233F  paciasp  
//   0x2ff710: D10183FF  sub      sp, sp, #0x60
//   0x2ff714: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x2ff718: A90267FA  stp      x26, x25, [sp, #0x20]
//   0x2ff71c: A9035FF8  stp      x24, x23, [sp, #0x30]
//   0x2ff720: A90457F6  stp      x22, x21, [sp, #0x40]
uint64_t fde_func_07184_0x2ff70c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x002FF70CULL);
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

// FDE #07194 | PC: 0x300688..0x3006b4 (44 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x300688: D503233F  paciasp  
//   0x30068c: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x300690: F9000BF3  str      x19, [sp, #0x10]
//   0x300694: 910003FD  mov      x29, sp
//   0x300698: AA0003F3  mov      x19, x0
//   0x30069c: 97FFFFE8  bl       #0x30063c
uint64_t fde_func_07194_0x300688(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00300688ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF3ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x97FFFFE8ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA1303E0ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400BF3ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #07203 | PC: 0x3048f8..0x304960 (104 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x3048f8: D503233F  paciasp  
//   0x3048fc: A9BD7BFD  stp      x29, x30, [sp, #-0x30]!
//   0x304900: F9000BF5  str      x21, [sp, #0x10]
//   0x304904: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x304908: 910003FD  mov      x29, sp
//   0x30490c: AA0203F5  mov      x21, x2
uint64_t fde_func_07203_0x3048f8(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x003048F8ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BD7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF5ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9024FF4ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0203F5ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0103F4ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #07213 | PC: 0x3067e4..0x3068a8 (196 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x3067e4: D503233F  paciasp  
//   0x3067e8: D101C3FF  sub      sp, sp, #0x70
//   0x3067ec: A9037BFD  stp      x29, x30, [sp, #0x30]
//   0x3067f0: F90023F7  str      x23, [sp, #0x40]
//   0x3067f4: A90557F6  stp      x22, x21, [sp, #0x50]
//   0x3067f8: A9064FF4  stp      x20, x19, [sp, #0x60]
uint64_t fde_func_07213_0x3067e4(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x003067E4ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD101C3FFULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9037BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF90023F7ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90557F6ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9064FF4ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9100C3FDULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD53BD056ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #07222 | PC: 0x306af4..0x306b20 (44 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x306af4: D503233F  paciasp  
//   0x306af8: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x306afc: F9000BF3  str      x19, [sp, #0x10]
//   0x306b00: 910003FD  mov      x29, sp
//   0x306b04: AA0003F3  mov      x19, x0
//   0x306b08: 97FFFFE6  bl       #0x306aa0
uint64_t fde_func_07222_0x306af4(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00306AF4ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF3ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x97FFFFE6ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA1303E0ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400BF3ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #07232 | PC: 0x307490..0x30749c (12 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x307490: D503245F  bti      c
//   0x307494: AA1F03E1  mov      x1, xzr
//   0x307498: 14000001  b        #0x30749c
uint64_t fde_func_07232_0x307490(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00307490ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA1F03E1ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x14000001ULL ^ (2ULL << 32);
    return state ^ (state >> 29);
}

// FDE #07241 | PC: 0x307de4..0x307ee4 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x307de4: D503233F  paciasp  
//   0x307de8: A9BB7BFD  stp      x29, x30, [sp, #-0x50]!
//   0x307dec: A90167FA  stp      x26, x25, [sp, #0x10]
//   0x307df0: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x307df4: A90357F6  stp      x22, x21, [sp, #0x30]
//   0x307df8: A9044FF4  stp      x20, x19, [sp, #0x40]
uint64_t fde_func_07241_0x307de4(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00307DE4ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BB7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90167FAULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9025FF8ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90357F6ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9044FF4ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB9404008ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #07251 | PC: 0x30883c..0x30893c (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x30883c: D503233F  paciasp  
//   0x308840: D10343FF  sub      sp, sp, #0xd0
//   0x308844: A90A7BFD  stp      x29, x30, [sp, #0xa0]
//   0x308848: A90B57F6  stp      x22, x21, [sp, #0xb0]
//   0x30884c: A90C4FF4  stp      x20, x19, [sp, #0xc0]
//   0x308850: 910283FD  add      x29, sp, #0xa0
uint64_t fde_func_07251_0x30883c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0030883CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10343FFULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90A7BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90B57F6ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90C4FF4ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910283FDULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F5ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0103F3ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #07260 | PC: 0x3096f4..0x309710 (28 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x3096f4: D503245F  bti      c
//   0x3096f8: AA0003E8  mov      x8, x0
//   0x3096fc: F9400000  ldr      x0, [x0]
//   0x309700: F900011F  str      xzr, [x8]
//   0x309704: B4000040  cbz      x0, #0x30970c
//   0x309708: 1409FCF6  b        #0x588ae0
uint64_t fde_func_07260_0x3096f4(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x003096F4ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003E8ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400000ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF900011FULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB4000040ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x1409FCF6ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD65F03C0ULL ^ (6ULL << 32);
    return state ^ (state >> 29);
}

// FDE #07270 | PC: 0x309d24..0x309d40 (28 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x309d24: D503245F  bti      c
//   0x309d28: AA0003E8  mov      x8, x0
//   0x309d2c: F9400000  ldr      x0, [x0]
//   0x309d30: F900011F  str      xzr, [x8]
//   0x309d34: B4000040  cbz      x0, #0x309d3c
//   0x309d38: 140041E9  b        #0x31a4dc
uint64_t fde_func_07270_0x309d24(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00309D24ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003E8ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400000ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF900011FULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB4000040ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x140041E9ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD65F03C0ULL ^ (6ULL << 32);
    return state ^ (state >> 29);
}

// FDE #07279 | PC: 0x30a81c..0x30a848 (44 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x30a81c: D503233F  paciasp  
//   0x30a820: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x30a824: F9000BF3  str      x19, [sp, #0x10]
//   0x30a828: 910003FD  mov      x29, sp
//   0x30a82c: AA0003F3  mov      x19, x0
//   0x30a830: 97FFFFF6  bl       #0x30a808
uint64_t fde_func_07279_0x30a81c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0030A81CULL);
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

// FDE #07289 | PC: 0x30bc54..0x30bd3c (232 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x30bc54: D503233F  paciasp  
//   0x30bc58: A9BD7BFD  stp      x29, x30, [sp, #-0x30]!
//   0x30bc5c: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x30bc60: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x30bc64: 910003FD  mov      x29, sp
//   0x30bc68: F9400048  ldr      x8, [x2]
uint64_t fde_func_07289_0x30bc54(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0030BC54ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BD7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90157F6ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9024FF4ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400048ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0103F5ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #07298 | PC: 0x30bfb4..0x30c0b4 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x30bfb4: D503233F  paciasp  
//   0x30bfb8: D10303FF  sub      sp, sp, #0xc0
//   0x30bfbc: A9067BFD  stp      x29, x30, [sp, #0x60]
//   0x30bfc0: A9076FFC  stp      x28, x27, [sp, #0x70]
//   0x30bfc4: A90867FA  stp      x26, x25, [sp, #0x80]
//   0x30bfc8: A9095FF8  stp      x24, x23, [sp, #0x90]
uint64_t fde_func_07298_0x30bfb4(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0030BFB4ULL);
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

// FDE #07308 | PC: 0x30c7fc..0x30c828 (44 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x30c7fc: D503233F  paciasp  
//   0x30c800: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x30c804: F9000BF3  str      x19, [sp, #0x10]
//   0x30c808: 910003FD  mov      x29, sp
//   0x30c80c: AA0003F3  mov      x19, x0
//   0x30c810: 97FFFFEC  bl       #0x30c7c0
uint64_t fde_func_07308_0x30c7fc(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0030C7FCULL);
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

// FDE #07317 | PC: 0x30cd88..0x30cdec (100 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x30cd88: D503233F  paciasp  
//   0x30cd8c: D10083FF  sub      sp, sp, #0x20
//   0x30cd90: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x30cd94: 910043FD  add      x29, sp, #0x10
//   0x30cd98: AA0103E8  mov      x8, x1
//   0x30cd9c: F9400049  ldr      x9, [x2]
uint64_t fde_func_07317_0x30cd88(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0030CD88ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10083FFULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0103E8ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400049ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF900005FULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910023E3ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #07327 | PC: 0x30d4d0..0x30d54c (124 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x30d4d0: D503233F  paciasp  
//   0x30d4d4: A9BD7BFD  stp      x29, x30, [sp, #-0x30]!
//   0x30d4d8: F9000BF5  str      x21, [sp, #0x10]
//   0x30d4dc: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x30d4e0: 910003FD  mov      x29, sp
//   0x30d4e4: AA0003F3  mov      x19, x0
uint64_t fde_func_07327_0x30d4d0(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0030D4D0ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BD7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF5ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9024FF4ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400C14ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF0001468ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #07336 | PC: 0x30d8a0..0x30d9a0 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x30d8a0: D503233F  paciasp  
//   0x30d8a4: D10483FF  sub      sp, sp, #0x120
//   0x30d8a8: A90C7BFD  stp      x29, x30, [sp, #0xc0]
//   0x30d8ac: A90D6FFC  stp      x28, x27, [sp, #0xd0]
//   0x30d8b0: A90E67FA  stp      x26, x25, [sp, #0xe0]
//   0x30d8b4: A90F5FF8  stp      x24, x23, [sp, #0xf0]
uint64_t fde_func_07336_0x30d8a0(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0030D8A0ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10483FFULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90C7BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90D6FFCULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90E67FAULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90F5FF8ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA91057F6ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9114FF4ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #07346 | PC: 0x30e580..0x30e588 (8 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x30e580: D503245F  bti      c
//   0x30e584: 17FC7C46  b        #0x22d69c
uint64_t fde_func_07346_0x30e580(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0030E580ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x17FC7C46ULL ^ (1ULL << 32);
    return state ^ (state >> 29);
}

// FDE #07355 | PC: 0x30f03c..0x30f134 (248 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x30f03c: D503233F  paciasp  
//   0x30f040: D101C3FF  sub      sp, sp, #0x70
//   0x30f044: A9037BFD  stp      x29, x30, [sp, #0x30]
//   0x30f048: F90023F7  str      x23, [sp, #0x40]
//   0x30f04c: A90557F6  stp      x22, x21, [sp, #0x50]
//   0x30f050: A9064FF4  stp      x20, x19, [sp, #0x60]
uint64_t fde_func_07355_0x30f03c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0030F03CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD101C3FFULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9037BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF90023F7ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90557F6ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9064FF4ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9100C3FDULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #07365 | PC: 0x30fb18..0x30fc18 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x30fb18: D503233F  paciasp  
//   0x30fb1c: A9BA7BFD  stp      x29, x30, [sp, #-0x60]!
//   0x30fb20: A9016FFC  stp      x28, x27, [sp, #0x10]
//   0x30fb24: A90267FA  stp      x26, x25, [sp, #0x20]
//   0x30fb28: A9035FF8  stp      x24, x23, [sp, #0x30]
//   0x30fb2c: A90457F6  stp      x22, x21, [sp, #0x40]
uint64_t fde_func_07365_0x30fb18(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0030FB18ULL);
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

// FDE #07374 | PC: 0x310c4c..0x310d4c (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x310c4c: D503233F  paciasp  
//   0x310c50: D10183FF  sub      sp, sp, #0x60
//   0x310c54: A9047BFD  stp      x29, x30, [sp, #0x40]
//   0x310c58: A9054FF4  stp      x20, x19, [sp, #0x50]
//   0x310c5c: 910103FD  add      x29, sp, #0x40
//   0x310c60: AA0103F3  mov      x19, x1
uint64_t fde_func_07374_0x310c4c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00310C4CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10183FFULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9047BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9054FF4ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910103FDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0103F3ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910033E1ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043E2ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #07384 | PC: 0x311a5c..0x311b5c (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x311a5c: D503233F  paciasp  
//   0x311a60: D10343FF  sub      sp, sp, #0xd0
//   0x311a64: A9077BFD  stp      x29, x30, [sp, #0x70]
//   0x311a68: A9086FFC  stp      x28, x27, [sp, #0x80]
//   0x311a6c: A90967FA  stp      x26, x25, [sp, #0x90]
//   0x311a70: A90A5FF8  stp      x24, x23, [sp, #0xa0]
uint64_t fde_func_07384_0x311a5c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00311A5CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10343FFULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9077BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9086FFCULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90967FAULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90A5FF8ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90B57F6ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90C4FF4ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #07393 | PC: 0x312ffc..0x31302c (48 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x312ffc: D503245F  bti      c
//   0x313000: A9402009  ldp      x9, x8, [x0]
//   0x313004: EB08013F  cmp      x9, x8
//   0x313008: 540000E0  b.eq     #0x313024
//   0x31300c: B9401809  ldr      w9, [x0, #0x18]
//   0x313010: 51000929  sub      w9, w9, #2
uint64_t fde_func_07393_0x312ffc(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00312FFCULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9402009ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xEB08013FULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x540000E0ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB9401809ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x51000929ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x7100093FULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x54000068ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #07403 | PC: 0x313cd4..0x313cf0 (28 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x313cd4: D503245F  bti      c
//   0x313cd8: AA0003E8  mov      x8, x0
//   0x313cdc: F9400000  ldr      x0, [x0]
//   0x313ce0: F900011F  str      xzr, [x8]
//   0x313ce4: B4000040  cbz      x0, #0x313cec
//   0x313ce8: 17FFD834  b        #0x309db8
uint64_t fde_func_07403_0x313cd4(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00313CD4ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003E8ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400000ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF900011FULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB4000040ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x17FFD834ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD65F03C0ULL ^ (6ULL << 32);
    return state ^ (state >> 29);
}

// FDE #07412 | PC: 0x3147ac..0x3147fc (80 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x3147ac: D503233F  paciasp  
//   0x3147b0: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x3147b4: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x3147b8: 910003FD  mov      x29, sp
//   0x3147bc: AA0003F4  mov      x20, x0
//   0x3147c0: AA0003F3  mov      x19, x0
uint64_t fde_func_07412_0x3147ac(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x003147ACULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9014FF4ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F4ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x90001449ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9112C129ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #07422 | PC: 0x314e9c..0x314f48 (172 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x314e9c: D503233F  paciasp  
//   0x314ea0: D10143FF  sub      sp, sp, #0x50
//   0x314ea4: A9037BFD  stp      x29, x30, [sp, #0x30]
//   0x314ea8: A9044FF4  stp      x20, x19, [sp, #0x40]
//   0x314eac: 9100C3FD  add      x29, sp, #0x30
//   0x314eb0: AA0103F4  mov      x20, x1
uint64_t fde_func_07422_0x314e9c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00314E9CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10143FFULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9037BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9044FF4ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9100C3FDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0103F4ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003E1ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910063E0ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #07431 | PC: 0x315748..0x3157cc (132 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x315748: D503233F  paciasp  
//   0x31574c: A9BC7BFD  stp      x29, x30, [sp, #-0x40]!
//   0x315750: F9000BF7  str      x23, [sp, #0x10]
//   0x315754: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x315758: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x31575c: 910003FD  mov      x29, sp
uint64_t fde_func_07431_0x315748(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00315748ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BC7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF7ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90257F6ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9034FF4ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA940DC15ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0203F3ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #07441 | PC: 0x315e0c..0x315e90 (132 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x315e0c: D503233F  paciasp  
//   0x315e10: A9BD7BFD  stp      x29, x30, [sp, #-0x30]!
//   0x315e14: F9000BF5  str      x21, [sp, #0x10]
//   0x315e18: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x315e1c: 910003FD  mov      x29, sp
//   0x315e20: AA0103F4  mov      x20, x1
uint64_t fde_func_07441_0x315e0c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00315E0CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BD7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF5ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9024FF4ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0103F4ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F5ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91024001ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #07451 | PC: 0x316550..0x3165f0 (160 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x316550: D503233F  paciasp  
//   0x316554: D101C3FF  sub      sp, sp, #0x70
//   0x316558: A9037BFD  stp      x29, x30, [sp, #0x30]
//   0x31655c: A9045FF8  stp      x24, x23, [sp, #0x40]
//   0x316560: A90557F6  stp      x22, x21, [sp, #0x50]
//   0x316564: A9064FF4  stp      x20, x19, [sp, #0x60]
uint64_t fde_func_07451_0x316550(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00316550ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD101C3FFULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9037BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9045FF8ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90557F6ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9064FF4ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9100C3FDULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910063E8ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #07460 | PC: 0x316a08..0x316b08 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x316a08: D503233F  paciasp  
//   0x316a0c: D10643FF  sub      sp, sp, #0x190
//   0x316a10: A9137BFD  stp      x29, x30, [sp, #0x130]
//   0x316a14: A9146FFC  stp      x28, x27, [sp, #0x140]
//   0x316a18: A91567FA  stp      x26, x25, [sp, #0x150]
//   0x316a1c: A9165FF8  stp      x24, x23, [sp, #0x160]
uint64_t fde_func_07460_0x316a08(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00316A08ULL);
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

// FDE #07470 | PC: 0x317698..0x3176f8 (96 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x317698: D503233F  paciasp  
//   0x31769c: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x3176a0: F9000BF3  str      x19, [sp, #0x10]
//   0x3176a4: 910003FD  mov      x29, sp
//   0x3176a8: AA0003F3  mov      x19, x0
//   0x3176ac: 9102A000  add      x0, x0, #0xa8
uint64_t fde_func_07470_0x317698(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00317698ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF3ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9102A000ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x97FAC3AEULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91024260ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #07479 | PC: 0x317fcc..0x318050 (132 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x317fcc: D503233F  paciasp  
//   0x317fd0: D10103FF  sub      sp, sp, #0x40
//   0x317fd4: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x317fd8: F9001BF3  str      x19, [sp, #0x30]
//   0x317fdc: 910083FD  add      x29, sp, #0x20
//   0x317fe0: AA0103E2  mov      x2, x1
uint64_t fde_func_07479_0x317fcc(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00317FCCULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10103FFULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9027BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9001BF3ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910083FDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0103E2ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003E1ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910063A0ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #07489 | PC: 0x318a8c..0x318b60 (212 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x318a8c: D503233F  paciasp  
//   0x318a90: D10303FF  sub      sp, sp, #0xc0
//   0x318a94: A9087BFD  stp      x29, x30, [sp, #0x80]
//   0x318a98: F9004BF7  str      x23, [sp, #0x90]
//   0x318a9c: A90A57F6  stp      x22, x21, [sp, #0xa0]
//   0x318aa0: A90B4FF4  stp      x20, x19, [sp, #0xb0]
uint64_t fde_func_07489_0x318a8c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00318A8CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10303FFULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9087BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9004BF7ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90A57F6ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90B4FF4ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910203FDULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD53BD056ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #07498 | PC: 0x318efc..0x318f8c (144 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x318efc: D503233F  paciasp  
//   0x318f00: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x318f04: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x318f08: 910003FD  mov      x29, sp
//   0x318f0c: AA0103F4  mov      x20, x1
//   0x318f10: AA0003F3  mov      x19, x0
uint64_t fde_func_07498_0x318efc(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00318EFCULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9014FF4ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0103F4ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x97FADD5AULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x360000C0ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #07508 | PC: 0x31934c..0x319388 (60 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x31934c: D503233F  paciasp  
//   0x319350: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x319354: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x319358: 910003FD  mov      x29, sp
//   0x31935c: AA0003F4  mov      x20, x0
//   0x319360: AA0003F3  mov      x19, x0
uint64_t fde_func_07508_0x31934c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0031934CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9014FF4ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F4ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF8408E80ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x94000008ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #07517 | PC: 0x3196c0..0x3196cc (12 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x3196c0: D503245F  bti      c
//   0x3196c4: F9400001  ldr      x1, [x0]
//   0x3196c8: 17FFFEE5  b        #0x31925c
uint64_t fde_func_07517_0x3196c0(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x003196C0ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400001ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x17FFFEE5ULL ^ (2ULL << 32);
    return state ^ (state >> 29);
}

// FDE #07527 | PC: 0x319bac..0x319c54 (168 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x319bac: D503233F  paciasp  
//   0x319bb0: D10143FF  sub      sp, sp, #0x50
//   0x319bb4: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x319bb8: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x319bbc: A90357F6  stp      x22, x21, [sp, #0x30]
//   0x319bc0: A9044FF4  stp      x20, x19, [sp, #0x40]
uint64_t fde_func_07527_0x319bac(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00319BACULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10143FFULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9025FF8ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90357F6ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9044FF4ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F6ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #07536 | PC: 0x319fc4..0x31a0c4 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x319fc4: D503233F  paciasp  
//   0x319fc8: A9BA7BFD  stp      x29, x30, [sp, #-0x60]!
//   0x319fcc: A9016FFC  stp      x28, x27, [sp, #0x10]
//   0x319fd0: A90267FA  stp      x26, x25, [sp, #0x20]
//   0x319fd4: A9035FF8  stp      x24, x23, [sp, #0x30]
//   0x319fd8: A90457F6  stp      x22, x21, [sp, #0x40]
uint64_t fde_func_07536_0x319fc4(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00319FC4ULL);
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

// FDE #07546 | PC: 0x31a6e0..0x31a710 (48 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x31a6e0: D503233F  paciasp  
//   0x31a6e4: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x31a6e8: F9000BF3  str      x19, [sp, #0x10]
//   0x31a6ec: 910003FD  mov      x29, sp
//   0x31a6f0: AA0003F3  mov      x19, x0
//   0x31a6f4: 9101C000  add      x0, x0, #0x70
uint64_t fde_func_07546_0x31a6e0(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0031A6E0ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF3ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9101C000ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x97FCB89FULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91002260ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #07555 | PC: 0x31a9b0..0x31aa84 (212 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x31a9b0: D503233F  paciasp  
//   0x31a9b4: D10103FF  sub      sp, sp, #0x40
//   0x31a9b8: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x31a9bc: F90013F5  str      x21, [sp, #0x20]
//   0x31a9c0: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x31a9c4: 910043FD  add      x29, sp, #0x10
uint64_t fde_func_07555_0x31a9b0(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0031A9B0ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10103FFULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF90013F5ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9034FF4ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F4ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0103F3ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #07565 | PC: 0x31b144..0x31b18c (72 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x31b144: D503233F  paciasp  
//   0x31b148: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x31b14c: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x31b150: 910003FD  mov      x29, sp
//   0x31b154: AA0003F3  mov      x19, x0
//   0x31b158: B7F80161  tbnz     x1, #0x3f, #0x31b184
uint64_t fde_func_07565_0x31b144(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0031B144ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9014FF4ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB7F80161ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0103E0ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0103F4ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #07574 | PC: 0x31b42c..0x31b49c (112 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x31b42c: D503233F  paciasp  
//   0x31b430: D10103FF  sub      sp, sp, #0x40
//   0x31b434: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x31b438: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x31b43c: 910083FD  add      x29, sp, #0x20
//   0x31b440: AA0203F3  mov      x19, x2
uint64_t fde_func_07574_0x31b42c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0031B42CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10103FFULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9027BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9034FF4ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910083FDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0203F3ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910023E2ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0303F4ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #07584 | PC: 0x31b77c..0x31b800 (132 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x31b77c: D503233F  paciasp  
//   0x31b780: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x31b784: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x31b788: 910003FD  mov      x29, sp
//   0x31b78c: 90001628  adrp     x8, #0x5df000
//   0x31b790: 91088108  add      x8, x8, #0x220
uint64_t fde_func_07584_0x31b77c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0031B77CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9014FF4ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x90001628ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91088108ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xC8DFFD13ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF100067FULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #07593 | PC: 0x31bd90..0x31be90 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x31bd90: D503233F  paciasp  
//   0x31bd94: A9BD7BFD  stp      x29, x30, [sp, #-0x30]!
//   0x31bd98: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x31bd9c: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x31bda0: 910003FD  mov      x29, sp
//   0x31bda4: A940A408  ldp      x8, x9, [x0, #8]
uint64_t fde_func_07593_0x31bd90(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0031BD90ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BD7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90157F6ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9024FF4ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA940A408ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0103F4ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #07603 | PC: 0x31c71c..0x31c764 (72 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x31c71c: D503233F  paciasp  
//   0x31c720: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x31c724: F9000BF3  str      x19, [sp, #0x10]
//   0x31c728: 910003FD  mov      x29, sp
//   0x31c72c: F9400013  ldr      x19, [x0]
//   0x31c730: F900001F  str      xzr, [x0]
uint64_t fde_func_07603_0x31c71c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0031C71CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF3ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400013ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF900001FULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB4000113ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA1303E0ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

uint64_t execute_fde_shard_2(uint32_t fde_idx, uint64_t a0, uint64_t a1) {
    switch (fde_idx) {
        case 3806: return fde_func_03806_0x26ae68(a0, a1);
        case 3815: return fde_func_03815_0x26b4b0(a0, a1);
        case 3825: return fde_func_03825_0x26b8bc(a0, a1);
        case 3834: return fde_func_03834_0x26c0b4(a0, a1);
        case 3844: return fde_func_03844_0x26d380(a0, a1);
        case 3853: return fde_func_03853_0x26de54(a0, a1);
        case 3863: return fde_func_03863_0x26df20(a0, a1);
        case 3873: return fde_func_03873_0x26e138(a0, a1);
        case 3882: return fde_func_03882_0x26e930(a0, a1);
        case 3892: return fde_func_03892_0x26f234(a0, a1);
        case 3901: return fde_func_03901_0x26fb84(a0, a1);
        case 3911: return fde_func_03911_0x26fd78(a0, a1);
        case 3920: return fde_func_03920_0x2700cc(a0, a1);
        case 3930: return fde_func_03930_0x270ea4(a0, a1);
        case 3939: return fde_func_03939_0x2712a8(a0, a1);
        case 3949: return fde_func_03949_0x271690(a0, a1);
        case 3958: return fde_func_03958_0x27190c(a0, a1);
        case 3968: return fde_func_03968_0x273e10(a0, a1);
        case 3977: return fde_func_03977_0x27403c(a0, a1);
        case 3987: return fde_func_03987_0x274a08(a0, a1);
        case 3996: return fde_func_03996_0x275678(a0, a1);
        case 4006: return fde_func_04006_0x27589c(a0, a1);
        case 4015: return fde_func_04015_0x275b0c(a0, a1);
        case 4025: return fde_func_04025_0x275db8(a0, a1);
        case 4034: return fde_func_04034_0x276120(a0, a1);
        case 4044: return fde_func_04044_0x27683c(a0, a1);
        case 4053: return fde_func_04053_0x276edc(a0, a1);
        case 4063: return fde_func_04063_0x277b74(a0, a1);
        case 4072: return fde_func_04072_0x278574(a0, a1);
        case 4082: return fde_func_04082_0x27861c(a0, a1);
        case 4091: return fde_func_04091_0x2787ec(a0, a1);
        case 4101: return fde_func_04101_0x279694(a0, a1);
        case 4110: return fde_func_04110_0x279948(a0, a1);
        case 4120: return fde_func_04120_0x279d7c(a0, a1);
        case 4129: return fde_func_04129_0x27a0f0(a0, a1);
        case 4139: return fde_func_04139_0x27a850(a0, a1);
        case 4148: return fde_func_04148_0x27b168(a0, a1);
        case 4158: return fde_func_04158_0x27c2a4(a0, a1);
        case 4168: return fde_func_04168_0x27c574(a0, a1);
        case 4177: return fde_func_04177_0x27c5f0(a0, a1);
        case 4187: return fde_func_04187_0x27c95c(a0, a1);
        case 4196: return fde_func_04196_0x27ccd0(a0, a1);
        case 4206: return fde_func_04206_0x27db28(a0, a1);
        case 4215: return fde_func_04215_0x27e338(a0, a1);
        case 4225: return fde_func_04225_0x27e57c(a0, a1);
        case 4234: return fde_func_04234_0x27f534(a0, a1);
        case 4244: return fde_func_04244_0x27fa94(a0, a1);
        case 4253: return fde_func_04253_0x27fc78(a0, a1);
        case 4263: return fde_func_04263_0x280324(a0, a1);
        case 4272: return fde_func_04272_0x280eec(a0, a1);
        case 4282: return fde_func_04282_0x281498(a0, a1);
        case 4291: return fde_func_04291_0x281938(a0, a1);
        case 4301: return fde_func_04301_0x28345c(a0, a1);
        case 4310: return fde_func_04310_0x283ddc(a0, a1);
        case 4320: return fde_func_04320_0x2849e0(a0, a1);
        case 4329: return fde_func_04329_0x284ba8(a0, a1);
        case 4339: return fde_func_04339_0x2851e8(a0, a1);
        case 4348: return fde_func_04348_0x285868(a0, a1);
        case 4358: return fde_func_04358_0x286714(a0, a1);
        case 4367: return fde_func_04367_0x286b14(a0, a1);
        case 4377: return fde_func_04377_0x287e8c(a0, a1);
        case 4386: return fde_func_04386_0x2883cc(a0, a1);
        case 4396: return fde_func_04396_0x288914(a0, a1);
        case 4405: return fde_func_04405_0x288994(a0, a1);
        case 4415: return fde_func_04415_0x288b18(a0, a1);
        case 4424: return fde_func_04424_0x28a278(a0, a1);
        case 4434: return fde_func_04434_0x28a96c(a0, a1);
        case 4443: return fde_func_04443_0x28ade0(a0, a1);
        case 4453: return fde_func_04453_0x28b25c(a0, a1);
        case 4463: return fde_func_04463_0x28b588(a0, a1);
        case 4472: return fde_func_04472_0x28bd70(a0, a1);
        case 4482: return fde_func_04482_0x28c420(a0, a1);
        case 4491: return fde_func_04491_0x28c86c(a0, a1);
        case 4501: return fde_func_04501_0x28cf2c(a0, a1);
        case 4510: return fde_func_04510_0x28d4dc(a0, a1);
        case 4520: return fde_func_04520_0x28daf8(a0, a1);
        case 4529: return fde_func_04529_0x28df00(a0, a1);
        case 4539: return fde_func_04539_0x28e634(a0, a1);
        case 4548: return fde_func_04548_0x28eac4(a0, a1);
        case 4558: return fde_func_04558_0x28eeb0(a0, a1);
        case 4567: return fde_func_04567_0x28f5f8(a0, a1);
        case 4577: return fde_func_04577_0x28fe04(a0, a1);
        case 4586: return fde_func_04586_0x2902b4(a0, a1);
        case 4596: return fde_func_04596_0x2906c0(a0, a1);
        case 4605: return fde_func_04605_0x290a40(a0, a1);
        case 4615: return fde_func_04615_0x291168(a0, a1);
        case 4624: return fde_func_04624_0x2918c4(a0, a1);
        case 4634: return fde_func_04634_0x291d14(a0, a1);
        case 4643: return fde_func_04643_0x2923b0(a0, a1);
        case 4653: return fde_func_04653_0x2929c4(a0, a1);
        case 4662: return fde_func_04662_0x292f20(a0, a1);
        case 4672: return fde_func_04672_0x2934e8(a0, a1);
        case 4681: return fde_func_04681_0x294208(a0, a1);
        case 4691: return fde_func_04691_0x2952cc(a0, a1);
        case 4700: return fde_func_04700_0x2956f4(a0, a1);
        case 4710: return fde_func_04710_0x295f64(a0, a1);
        case 4719: return fde_func_04719_0x296820(a0, a1);
        case 4729: return fde_func_04729_0x296f7c(a0, a1);
        case 4738: return fde_func_04738_0x297664(a0, a1);
        case 4748: return fde_func_04748_0x297eec(a0, a1);
        case 4758: return fde_func_04758_0x29852c(a0, a1);
        case 4767: return fde_func_04767_0x298e4c(a0, a1);
        case 4777: return fde_func_04777_0x299364(a0, a1);
        case 4786: return fde_func_04786_0x299b78(a0, a1);
        case 4796: return fde_func_04796_0x299f6c(a0, a1);
        case 4805: return fde_func_04805_0x29a464(a0, a1);
        case 4815: return fde_func_04815_0x29a80c(a0, a1);
        case 4824: return fde_func_04824_0x29ac88(a0, a1);
        case 4834: return fde_func_04834_0x29b0b4(a0, a1);
        case 4843: return fde_func_04843_0x29b590(a0, a1);
        case 4853: return fde_func_04853_0x29be00(a0, a1);
        case 4862: return fde_func_04862_0x29c220(a0, a1);
        case 4872: return fde_func_04872_0x29cbbc(a0, a1);
        case 4881: return fde_func_04881_0x29d114(a0, a1);
        case 4891: return fde_func_04891_0x29d684(a0, a1);
        case 4900: return fde_func_04900_0x29dc48(a0, a1);
        case 4910: return fde_func_04910_0x29e818(a0, a1);
        case 4919: return fde_func_04919_0x29ee40(a0, a1);
        case 4929: return fde_func_04929_0x29f2d4(a0, a1);
        case 4938: return fde_func_04938_0x29f7c0(a0, a1);
        case 4948: return fde_func_04948_0x29ffc0(a0, a1);
        case 4957: return fde_func_04957_0x2a0344(a0, a1);
        case 4967: return fde_func_04967_0x2a06dc(a0, a1);
        case 4976: return fde_func_04976_0x2a0c3c(a0, a1);
        case 4986: return fde_func_04986_0x2a0fd0(a0, a1);
        case 4995: return fde_func_04995_0x2a14f4(a0, a1);
        case 5005: return fde_func_05005_0x2a185c(a0, a1);
        case 5014: return fde_func_05014_0x2a1df4(a0, a1);
        case 5024: return fde_func_05024_0x2a24a8(a0, a1);
        case 5033: return fde_func_05033_0x2a29a0(a0, a1);
        case 5043: return fde_func_05043_0x2a2e24(a0, a1);
        case 5052: return fde_func_05052_0x2a311c(a0, a1);
        case 5062: return fde_func_05062_0x2a37fc(a0, a1);
        case 5072: return fde_func_05072_0x2a3f14(a0, a1);
        case 5081: return fde_func_05081_0x2a4330(a0, a1);
        case 5091: return fde_func_05091_0x2a48f4(a0, a1);
        case 5100: return fde_func_05100_0x2a4d8c(a0, a1);
        case 5110: return fde_func_05110_0x2a534c(a0, a1);
        case 5119: return fde_func_05119_0x2a5a14(a0, a1);
        case 5129: return fde_func_05129_0x2a638c(a0, a1);
        case 5138: return fde_func_05138_0x2a68b8(a0, a1);
        case 5148: return fde_func_05148_0x2a7368(a0, a1);
        case 5157: return fde_func_05157_0x2a7a84(a0, a1);
        case 5167: return fde_func_05167_0x2a829c(a0, a1);
        case 5176: return fde_func_05176_0x2a88d0(a0, a1);
        case 5186: return fde_func_05186_0x2a8cc8(a0, a1);
        case 5195: return fde_func_05195_0x2a94b4(a0, a1);
        case 5205: return fde_func_05205_0x2a9750(a0, a1);
        case 5214: return fde_func_05214_0x2aa4dc(a0, a1);
        case 5224: return fde_func_05224_0x2aad20(a0, a1);
        case 5233: return fde_func_05233_0x2ab114(a0, a1);
        case 5243: return fde_func_05243_0x2ab354(a0, a1);
        case 5252: return fde_func_05252_0x2ab61c(a0, a1);
        case 5262: return fde_func_05262_0x2ac3f8(a0, a1);
        case 5271: return fde_func_05271_0x2ac4c4(a0, a1);
        case 5281: return fde_func_05281_0x2ae2b4(a0, a1);
        case 5290: return fde_func_05290_0x2ae848(a0, a1);
        case 5300: return fde_func_05300_0x2aed4c(a0, a1);
        case 5309: return fde_func_05309_0x2af4f4(a0, a1);
        case 5319: return fde_func_05319_0x2afa40(a0, a1);
        case 5328: return fde_func_05328_0x2b0370(a0, a1);
        case 5338: return fde_func_05338_0x2b0c30(a0, a1);
        case 5347: return fde_func_05347_0x2b1754(a0, a1);
        case 5357: return fde_func_05357_0x2b2050(a0, a1);
        case 5367: return fde_func_05367_0x2b2b68(a0, a1);
        case 5376: return fde_func_05376_0x2b3608(a0, a1);
        case 5386: return fde_func_05386_0x2b3c68(a0, a1);
        case 5395: return fde_func_05395_0x2b41fc(a0, a1);
        case 5405: return fde_func_05405_0x2b4acc(a0, a1);
        case 5414: return fde_func_05414_0x2b5548(a0, a1);
        case 5424: return fde_func_05424_0x2b6184(a0, a1);
        case 5433: return fde_func_05433_0x2b65dc(a0, a1);
        case 5443: return fde_func_05443_0x2b6a78(a0, a1);
        case 5452: return fde_func_05452_0x2b6fb0(a0, a1);
        case 5462: return fde_func_05462_0x2b79a4(a0, a1);
        case 5471: return fde_func_05471_0x2b8108(a0, a1);
        case 5481: return fde_func_05481_0x2b8468(a0, a1);
        case 5490: return fde_func_05490_0x2b8674(a0, a1);
        case 5500: return fde_func_05500_0x2b9cd0(a0, a1);
        case 5509: return fde_func_05509_0x2b9e04(a0, a1);
        case 5519: return fde_func_05519_0x2ba094(a0, a1);
        case 5528: return fde_func_05528_0x2ba78c(a0, a1);
        case 5538: return fde_func_05538_0x2bab88(a0, a1);
        case 5547: return fde_func_05547_0x2bb104(a0, a1);
        case 5557: return fde_func_05557_0x2bb8a4(a0, a1);
        case 5566: return fde_func_05566_0x2bbf54(a0, a1);
        case 5576: return fde_func_05576_0x2bcdbc(a0, a1);
        case 5585: return fde_func_05585_0x2bd514(a0, a1);
        case 5595: return fde_func_05595_0x2bddf0(a0, a1);
        case 5604: return fde_func_05604_0x2be1d4(a0, a1);
        case 5614: return fde_func_05614_0x2be588(a0, a1);
        case 5623: return fde_func_05623_0x2bedf4(a0, a1);
        case 5633: return fde_func_05633_0x2bf4ec(a0, a1);
        case 5642: return fde_func_05642_0x2bfc20(a0, a1);
        case 5652: return fde_func_05652_0x2c0184(a0, a1);
        case 5662: return fde_func_05662_0x2c0890(a0, a1);
        case 5671: return fde_func_05671_0x2c0e88(a0, a1);
        case 5681: return fde_func_05681_0x2c1718(a0, a1);
        case 5690: return fde_func_05690_0x2c1be4(a0, a1);
        case 5700: return fde_func_05700_0x2c2080(a0, a1);
        case 5709: return fde_func_05709_0x2c26f0(a0, a1);
        case 5719: return fde_func_05719_0x2c2c10(a0, a1);
        case 5728: return fde_func_05728_0x2c33fc(a0, a1);
        case 5738: return fde_func_05738_0x2c3a04(a0, a1);
        case 5747: return fde_func_05747_0x2c4030(a0, a1);
        case 5757: return fde_func_05757_0x2c4560(a0, a1);
        case 5766: return fde_func_05766_0x2c4954(a0, a1);
        case 5776: return fde_func_05776_0x2c4ee8(a0, a1);
        case 5785: return fde_func_05785_0x2c5320(a0, a1);
        case 5795: return fde_func_05795_0x2c5860(a0, a1);
        case 5804: return fde_func_05804_0x2c5d04(a0, a1);
        case 5814: return fde_func_05814_0x2c63d4(a0, a1);
        case 5823: return fde_func_05823_0x2c67c0(a0, a1);
        case 5833: return fde_func_05833_0x2c722c(a0, a1);
        case 5842: return fde_func_05842_0x2c79f8(a0, a1);
        case 5852: return fde_func_05852_0x2c7f50(a0, a1);
        case 5861: return fde_func_05861_0x2c850c(a0, a1);
        case 5871: return fde_func_05871_0x2c8b98(a0, a1);
        case 5880: return fde_func_05880_0x2c8e0c(a0, a1);
        case 5890: return fde_func_05890_0x2c9408(a0, a1);
        case 5899: return fde_func_05899_0x2c94e8(a0, a1);
        case 5909: return fde_func_05909_0x2c9948(a0, a1);
        case 5918: return fde_func_05918_0x2c9f10(a0, a1);
        case 5928: return fde_func_05928_0x2ca864(a0, a1);
        case 5937: return fde_func_05937_0x2cc690(a0, a1);
        case 5947: return fde_func_05947_0x2ccbc4(a0, a1);
        case 5957: return fde_func_05957_0x2cd530(a0, a1);
        case 5966: return fde_func_05966_0x2cdeec(a0, a1);
        case 5976: return fde_func_05976_0x2ce3bc(a0, a1);
        case 5985: return fde_func_05985_0x2ceab0(a0, a1);
        case 5995: return fde_func_05995_0x2cef6c(a0, a1);
        case 6004: return fde_func_06004_0x2cf5d4(a0, a1);
        case 6014: return fde_func_06014_0x2cfb38(a0, a1);
        case 6023: return fde_func_06023_0x2cfda4(a0, a1);
        case 6033: return fde_func_06033_0x2d028c(a0, a1);
        case 6042: return fde_func_06042_0x2d0a6c(a0, a1);
        case 6052: return fde_func_06052_0x2d1010(a0, a1);
        case 6061: return fde_func_06061_0x2d1300(a0, a1);
        case 6071: return fde_func_06071_0x2d1770(a0, a1);
        case 6080: return fde_func_06080_0x2d1b84(a0, a1);
        case 6090: return fde_func_06090_0x2d2088(a0, a1);
        case 6099: return fde_func_06099_0x2d248c(a0, a1);
        case 6109: return fde_func_06109_0x2d2a60(a0, a1);
        case 6118: return fde_func_06118_0x2d2f04(a0, a1);
        case 6128: return fde_func_06128_0x2d324c(a0, a1);
        case 6137: return fde_func_06137_0x2d3444(a0, a1);
        case 6147: return fde_func_06147_0x2d37d8(a0, a1);
        case 6156: return fde_func_06156_0x2d3d90(a0, a1);
        case 6166: return fde_func_06166_0x2d4118(a0, a1);
        case 6175: return fde_func_06175_0x2d45fc(a0, a1);
        case 6185: return fde_func_06185_0x2d4888(a0, a1);
        case 6194: return fde_func_06194_0x2d4fc0(a0, a1);
        case 6204: return fde_func_06204_0x2d553c(a0, a1);
        case 6213: return fde_func_06213_0x2d5958(a0, a1);
        case 6223: return fde_func_06223_0x2d5e6c(a0, a1);
        case 6232: return fde_func_06232_0x2d6468(a0, a1);
        case 6242: return fde_func_06242_0x2d6dd8(a0, a1);
        case 6252: return fde_func_06252_0x2d7688(a0, a1);
        case 6261: return fde_func_06261_0x2d7d98(a0, a1);
        case 6271: return fde_func_06271_0x2d8690(a0, a1);
        case 6280: return fde_func_06280_0x2d8db4(a0, a1);
        case 6290: return fde_func_06290_0x2d982c(a0, a1);
        case 6299: return fde_func_06299_0x2da17c(a0, a1);
        case 6309: return fde_func_06309_0x2da578(a0, a1);
        case 6318: return fde_func_06318_0x2da950(a0, a1);
        case 6328: return fde_func_06328_0x2db030(a0, a1);
        case 6337: return fde_func_06337_0x2db70c(a0, a1);
        case 6347: return fde_func_06347_0x2dbb44(a0, a1);
        case 6356: return fde_func_06356_0x2dc038(a0, a1);
        case 6366: return fde_func_06366_0x2dc5c4(a0, a1);
        case 6375: return fde_func_06375_0x2dc8b4(a0, a1);
        case 6385: return fde_func_06385_0x2dccd8(a0, a1);
        case 6394: return fde_func_06394_0x2dd3cc(a0, a1);
        case 6404: return fde_func_06404_0x2ddab4(a0, a1);
        case 6413: return fde_func_06413_0x2dde0c(a0, a1);
        case 6423: return fde_func_06423_0x2de1a4(a0, a1);
        case 6432: return fde_func_06432_0x2de53c(a0, a1);
        case 6442: return fde_func_06442_0x2dec1c(a0, a1);
        case 6451: return fde_func_06451_0x2defc8(a0, a1);
        case 6461: return fde_func_06461_0x2df940(a0, a1);
        case 6470: return fde_func_06470_0x2e00b4(a0, a1);
        case 6480: return fde_func_06480_0x2e0964(a0, a1);
        case 6489: return fde_func_06489_0x2e0ccc(a0, a1);
        case 6499: return fde_func_06499_0x2e1974(a0, a1);
        case 6508: return fde_func_06508_0x2e1e68(a0, a1);
        case 6518: return fde_func_06518_0x2e2274(a0, a1);
        case 6527: return fde_func_06527_0x2e2618(a0, a1);
        case 6537: return fde_func_06537_0x2e28dc(a0, a1);
        case 6547: return fde_func_06547_0x2e2dd8(a0, a1);
        case 6556: return fde_func_06556_0x2e3338(a0, a1);
        case 6566: return fde_func_06566_0x2e3870(a0, a1);
        case 6575: return fde_func_06575_0x2e3cac(a0, a1);
        case 6585: return fde_func_06585_0x2e3fd0(a0, a1);
        case 6594: return fde_func_06594_0x2e48d0(a0, a1);
        case 6604: return fde_func_06604_0x2e4a9c(a0, a1);
        case 6613: return fde_func_06613_0x2e4f8c(a0, a1);
        case 6623: return fde_func_06623_0x2e5358(a0, a1);
        case 6632: return fde_func_06632_0x2e5f0c(a0, a1);
        case 6642: return fde_func_06642_0x2e6698(a0, a1);
        case 6651: return fde_func_06651_0x2e6b98(a0, a1);
        case 6661: return fde_func_06661_0x2e71d0(a0, a1);
        case 6670: return fde_func_06670_0x2e77b8(a0, a1);
        case 6680: return fde_func_06680_0x2e7d0c(a0, a1);
        case 6689: return fde_func_06689_0x2e8200(a0, a1);
        case 6699: return fde_func_06699_0x2e86f4(a0, a1);
        case 6708: return fde_func_06708_0x2e88f4(a0, a1);
        case 6718: return fde_func_06718_0x2e8c70(a0, a1);
        case 6727: return fde_func_06727_0x2e91a8(a0, a1);
        case 6737: return fde_func_06737_0x2e9ae8(a0, a1);
        case 6746: return fde_func_06746_0x2e9e84(a0, a1);
        case 6756: return fde_func_06756_0x2ea1f8(a0, a1);
        case 6765: return fde_func_06765_0x2ea620(a0, a1);
        case 6775: return fde_func_06775_0x2eaa68(a0, a1);
        case 6784: return fde_func_06784_0x2eb484(a0, a1);
        case 6794: return fde_func_06794_0x2eb6ec(a0, a1);
        case 6803: return fde_func_06803_0x2eb8d4(a0, a1);
        case 6813: return fde_func_06813_0x2ebe1c(a0, a1);
        case 6822: return fde_func_06822_0x2ec18c(a0, a1);
        case 6832: return fde_func_06832_0x2ec92c(a0, a1);
        case 6842: return fde_func_06842_0x2ed188(a0, a1);
        case 6851: return fde_func_06851_0x2ed6e0(a0, a1);
        case 6861: return fde_func_06861_0x2edd10(a0, a1);
        case 6870: return fde_func_06870_0x2ee414(a0, a1);
        case 6880: return fde_func_06880_0x2ee5fc(a0, a1);
        case 6889: return fde_func_06889_0x2ee900(a0, a1);
        case 6899: return fde_func_06899_0x2f02b0(a0, a1);
        case 6908: return fde_func_06908_0x2f05b4(a0, a1);
        case 6918: return fde_func_06918_0x2f06ec(a0, a1);
        case 6927: return fde_func_06927_0x2f13cc(a0, a1);
        case 6937: return fde_func_06937_0x2f16d8(a0, a1);
        case 6946: return fde_func_06946_0x2f2a80(a0, a1);
        case 6956: return fde_func_06956_0x2f3b70(a0, a1);
        case 6965: return fde_func_06965_0x2f4230(a0, a1);
        case 6975: return fde_func_06975_0x2f4fa8(a0, a1);
        case 6984: return fde_func_06984_0x2f5488(a0, a1);
        case 6994: return fde_func_06994_0x2f5a6c(a0, a1);
        case 7003: return fde_func_07003_0x2f5d88(a0, a1);
        case 7013: return fde_func_07013_0x2f6734(a0, a1);
        case 7022: return fde_func_07022_0x2f6bcc(a0, a1);
        case 7032: return fde_func_07032_0x2f73f4(a0, a1);
        case 7041: return fde_func_07041_0x2f7864(a0, a1);
        case 7051: return fde_func_07051_0x2f8788(a0, a1);
        case 7060: return fde_func_07060_0x2f8b84(a0, a1);
        case 7070: return fde_func_07070_0x2f9528(a0, a1);
        case 7079: return fde_func_07079_0x2f9848(a0, a1);
        case 7089: return fde_func_07089_0x2f9d64(a0, a1);
        case 7098: return fde_func_07098_0x2fa568(a0, a1);
        case 7108: return fde_func_07108_0x2fabd0(a0, a1);
        case 7117: return fde_func_07117_0x2fb598(a0, a1);
        case 7127: return fde_func_07127_0x2fbb94(a0, a1);
        case 7137: return fde_func_07137_0x2fd3a0(a0, a1);
        case 7146: return fde_func_07146_0x2fda48(a0, a1);
        case 7156: return fde_func_07156_0x2fdf68(a0, a1);
        case 7165: return fde_func_07165_0x2fe960(a0, a1);
        case 7175: return fde_func_07175_0x2fefa0(a0, a1);
        case 7184: return fde_func_07184_0x2ff70c(a0, a1);
        case 7194: return fde_func_07194_0x300688(a0, a1);
        case 7203: return fde_func_07203_0x3048f8(a0, a1);
        case 7213: return fde_func_07213_0x3067e4(a0, a1);
        case 7222: return fde_func_07222_0x306af4(a0, a1);
        case 7232: return fde_func_07232_0x307490(a0, a1);
        case 7241: return fde_func_07241_0x307de4(a0, a1);
        case 7251: return fde_func_07251_0x30883c(a0, a1);
        case 7260: return fde_func_07260_0x3096f4(a0, a1);
        case 7270: return fde_func_07270_0x309d24(a0, a1);
        case 7279: return fde_func_07279_0x30a81c(a0, a1);
        case 7289: return fde_func_07289_0x30bc54(a0, a1);
        case 7298: return fde_func_07298_0x30bfb4(a0, a1);
        case 7308: return fde_func_07308_0x30c7fc(a0, a1);
        case 7317: return fde_func_07317_0x30cd88(a0, a1);
        case 7327: return fde_func_07327_0x30d4d0(a0, a1);
        case 7336: return fde_func_07336_0x30d8a0(a0, a1);
        case 7346: return fde_func_07346_0x30e580(a0, a1);
        case 7355: return fde_func_07355_0x30f03c(a0, a1);
        case 7365: return fde_func_07365_0x30fb18(a0, a1);
        case 7374: return fde_func_07374_0x310c4c(a0, a1);
        case 7384: return fde_func_07384_0x311a5c(a0, a1);
        case 7393: return fde_func_07393_0x312ffc(a0, a1);
        case 7403: return fde_func_07403_0x313cd4(a0, a1);
        case 7412: return fde_func_07412_0x3147ac(a0, a1);
        case 7422: return fde_func_07422_0x314e9c(a0, a1);
        case 7431: return fde_func_07431_0x315748(a0, a1);
        case 7441: return fde_func_07441_0x315e0c(a0, a1);
        case 7451: return fde_func_07451_0x316550(a0, a1);
        case 7460: return fde_func_07460_0x316a08(a0, a1);
        case 7470: return fde_func_07470_0x317698(a0, a1);
        case 7479: return fde_func_07479_0x317fcc(a0, a1);
        case 7489: return fde_func_07489_0x318a8c(a0, a1);
        case 7498: return fde_func_07498_0x318efc(a0, a1);
        case 7508: return fde_func_07508_0x31934c(a0, a1);
        case 7517: return fde_func_07517_0x3196c0(a0, a1);
        case 7527: return fde_func_07527_0x319bac(a0, a1);
        case 7536: return fde_func_07536_0x319fc4(a0, a1);
        case 7546: return fde_func_07546_0x31a6e0(a0, a1);
        case 7555: return fde_func_07555_0x31a9b0(a0, a1);
        case 7565: return fde_func_07565_0x31b144(a0, a1);
        case 7574: return fde_func_07574_0x31b42c(a0, a1);
        case 7584: return fde_func_07584_0x31b77c(a0, a1);
        case 7593: return fde_func_07593_0x31bd90(a0, a1);
        case 7603: return fde_func_07603_0x31c71c(a0, a1);
        default: return 0ULL;
    }
}

} // namespace sscronet