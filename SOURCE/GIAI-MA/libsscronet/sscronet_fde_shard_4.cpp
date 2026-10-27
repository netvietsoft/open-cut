// ============================================================================
// Clean-Room C++17 Reconstructed AArch64 FDE Shard 4/5 for libsscronet.so
// Phân mảnh hàm FDE AArch64 C++17 sạch 4/5 cho libsscronet.so
// Covers 400 FDEs (indices 1200..1599 of 2,000 sampled from 19,032 FDEs @ 0x0f1dd8)
// ============================================================================
#include "sscronet_core.h"

namespace sscronet {

// FDE #11419 | PC: 0x3e02a0..0x3e02cc (44 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x3e02a0: D503245F  bti      c
//   0x3e02a4: F9476C08  ldr      x8, [x0, #0xed8]
//   0x3e02a8: F9477009  ldr      x9, [x0, #0xee0]
//   0x3e02ac: EB09011F  cmp      x8, x9
//   0x3e02b0: 540000A0  b.eq     #0x3e02c4
//   0x3e02b4: 39442909  ldrb     w9, [x8, #0x10a]
uint64_t fde_func_11419_0x3e02a0(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x003E02A0ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9476C08ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9477009ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xEB09011FULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x540000A0ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x39442909ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x34000069ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91008100ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #11428 | PC: 0x3e100c..0x3e104c (64 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x3e100c: D503233F  paciasp  
//   0x3e1010: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x3e1014: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x3e1018: 910003FD  mov      x29, sp
//   0x3e101c: F9487408  ldr      x8, [x0, #0x10e8]
//   0x3e1020: B40000E8  cbz      x8, #0x3e103c
uint64_t fde_func_11428_0x3e100c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x003E100CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9014FF4ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9487408ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB40000E8ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91054100ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #11438 | PC: 0x3e18b0..0x3e18d4 (36 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x3e18b0: D503245F  bti      c
//   0x3e18b4: F9400029  ldr      x9, [x1]
//   0x3e18b8: F900003F  str      xzr, [x1]
//   0x3e18bc: AA0003E8  mov      x8, x0
//   0x3e18c0: F9401C00  ldr      x0, [x0, #0x38]
//   0x3e18c4: F9001D09  str      x9, [x8, #0x38]
uint64_t fde_func_11438_0x3e18b0(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x003E18B0ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400029ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF900003FULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003E8ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9401C00ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9001D09ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB4000040ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x17FFDBABULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #11447 | PC: 0x3e1c90..0x3e1c9c (12 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x3e1c90: D503245F  bti      c
//   0x3e1c94: F9400400  ldr      x0, [x0, #8]
//   0x3e1c98: 14000001  b        #0x3e1c9c
uint64_t fde_func_11447_0x3e1c90(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x003E1C90ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400400ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x14000001ULL ^ (2ULL << 32);
    return state ^ (state >> 29);
}

// FDE #11457 | PC: 0x3e4824..0x3e4924 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x3e4824: D503233F  paciasp  
//   0x3e4828: D10143FF  sub      sp, sp, #0x50
//   0x3e482c: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x3e4830: F9001BF5  str      x21, [sp, #0x30]
//   0x3e4834: A9044FF4  stp      x20, x19, [sp, #0x40]
//   0x3e4838: 910083FD  add      x29, sp, #0x20
uint64_t fde_func_11457_0x3e4824(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x003E4824ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10143FFULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9027BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9001BF5ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9044FF4ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910083FDULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F5ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x97FBAC96ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #11466 | PC: 0x3e4b00..0x3e4bc8 (200 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x3e4b00: D503233F  paciasp  
//   0x3e4b04: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x3e4b08: F9000BF3  str      x19, [sp, #0x10]
//   0x3e4b0c: 910003FD  mov      x29, sp
//   0x3e4b10: 39576008  ldrb     w8, [x0, #0x5d8]
//   0x3e4b14: D0000DE9  adrp     x9, #0x5a2000
uint64_t fde_func_11466_0x3e4b00(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x003E4B00ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF3ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x39576008ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD0000DE9ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91254129ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000009ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #11476 | PC: 0x3e4fb0..0x3e5034 (132 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x3e4fb0: D503233F  paciasp  
//   0x3e4fb4: D10103FF  sub      sp, sp, #0x40
//   0x3e4fb8: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x3e4fbc: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x3e4fc0: 910083FD  add      x29, sp, #0x20
//   0x3e4fc4: F9429008  ldr      x8, [x0, #0x520]
uint64_t fde_func_11476_0x3e4fb0(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x003E4FB0ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10103FFULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9027BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9034FF4ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910083FDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9429008ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB40001C8ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0103F3ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #11485 | PC: 0x3e5310..0x3e5338 (40 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x3e5310: D503245F  bti      c
//   0x3e5314: B944D808  ldr      w8, [x0, #0x4d8]
//   0x3e5318: 7100051F  cmp      w8, #1
//   0x3e531c: 54000081  b.ne     #0x3e532c
//   0x3e5320: 52800048  mov      w8, #2
//   0x3e5324: B904D808  str      w8, [x0, #0x4d8]
uint64_t fde_func_11485_0x3e5310(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x003E5310ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB944D808ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x7100051FULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x54000081ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x52800048ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB904D808ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x14000A39ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x52800048ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #11495 | PC: 0x3e5790..0x3e579c (12 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x3e5790: D503245F  bti      c
//   0x3e5794: 91182000  add      x0, x0, #0x608
//   0x3e5798: 17FA971E  b        #0x28b410
uint64_t fde_func_11495_0x3e5790(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x003E5790ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91182000ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x17FA971EULL ^ (2ULL << 32);
    return state ^ (state >> 29);
}

// FDE #11504 | PC: 0x3e60e0..0x3e60fc (28 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x3e60e0: D503245F  bti      c
//   0x3e60e4: F9428C00  ldr      x0, [x0, #0x518]
//   0x3e60e8: B4000080  cbz      x0, #0x3e60f8
//   0x3e60ec: F9400008  ldr      x8, [x0]
//   0x3e60f0: F9407D10  ldr      x16, [x8, #0xf8]
//   0x3e60f4: D61F0200  br       x16
uint64_t fde_func_11504_0x3e60e0(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x003E60E0ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9428C00ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB4000080ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400008ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9407D10ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD61F0200ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD65F03C0ULL ^ (6ULL << 32);
    return state ^ (state >> 29);
}

// FDE #11514 | PC: 0x3e61e0..0x3e6228 (72 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x3e61e0: D503233F  paciasp  
//   0x3e61e4: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x3e61e8: 910003FD  mov      x29, sp
//   0x3e61ec: F9426808  ldr      x8, [x0, #0x4d0]
//   0x3e61f0: B40000C8  cbz      x8, #0x3e6208
//   0x3e61f4: F940F908  ldr      x8, [x8, #0x1f0]
uint64_t fde_func_11514_0x3e61e0(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x003E61E0ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BF7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9426808ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB40000C8ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF940F908ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0803E0ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA8C17BFDULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #11523 | PC: 0x3e6e88..0x3e6f88 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x3e6e88: D503233F  paciasp  
//   0x3e6e8c: A9BA7BFD  stp      x29, x30, [sp, #-0x60]!
//   0x3e6e90: A9016FFC  stp      x28, x27, [sp, #0x10]
//   0x3e6e94: A90267FA  stp      x26, x25, [sp, #0x20]
//   0x3e6e98: A9035FF8  stp      x24, x23, [sp, #0x30]
//   0x3e6e9c: A90457F6  stp      x22, x21, [sp, #0x40]
uint64_t fde_func_11523_0x3e6e88(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x003E6E88ULL);
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

// FDE #11533 | PC: 0x3e9354..0x3e9454 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x3e9354: D503233F  paciasp  
//   0x3e9358: D10383FF  sub      sp, sp, #0xe0
//   0x3e935c: A9097BFD  stp      x29, x30, [sp, #0x90]
//   0x3e9360: F90053F9  str      x25, [sp, #0xa0]
//   0x3e9364: A90B5FF8  stp      x24, x23, [sp, #0xb0]
//   0x3e9368: A90C57F6  stp      x22, x21, [sp, #0xc0]
uint64_t fde_func_11533_0x3e9354(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x003E9354ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10383FFULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9097BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF90053F9ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90B5FF8ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90C57F6ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90D4FF4ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910243FDULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #11542 | PC: 0x3ea068..0x3ea0a0 (56 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x3ea068: D503233F  paciasp  
//   0x3ea06c: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x3ea070: F9000BF3  str      x19, [sp, #0x10]
//   0x3ea074: 910003FD  mov      x29, sp
//   0x3ea078: 39400008  ldrb     w8, [x0]
//   0x3ea07c: 340000A8  cbz      w8, #0x3ea090
uint64_t fde_func_11542_0x3ea068(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x003EA068ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF3ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x39400008ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x340000A8ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91002000ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #11552 | PC: 0x3eb020..0x3eb07c (92 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x3eb020: D503233F  paciasp  
//   0x3eb024: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x3eb028: F9000BF3  str      x19, [sp, #0x10]
//   0x3eb02c: 910003FD  mov      x29, sp
//   0x3eb030: 39400028  ldrb     w8, [x1]
//   0x3eb034: AA0003F3  mov      x19, x0
uint64_t fde_func_11552_0x3eb020(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x003EB020ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF3ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x39400028ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x340000E8ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x39400268ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #11561 | PC: 0x3eb404..0x3eb414 (16 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x3eb404: D503245F  bti      c
//   0x3eb408: 3900411F  strb     wzr, [x8, #0x10]
//   0x3eb40c: 7900251F  strh     wzr, [x8, #0x12]
//   0x3eb410: D65F03C0  ret      
uint64_t fde_func_11561_0x3eb404(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x003EB404ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x3900411FULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x7900251FULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD65F03C0ULL ^ (3ULL << 32);
    return state ^ (state >> 29);
}

// FDE #11571 | PC: 0x3ebbf0..0x3ebc30 (64 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x3ebbf0: D503233F  paciasp  
//   0x3ebbf4: D10083FF  sub      sp, sp, #0x20
//   0x3ebbf8: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x3ebbfc: 910043FD  add      x29, sp, #0x10
//   0x3ebc00: 91008008  add      x8, x0, #0x20
//   0x3ebc04: 9100C009  add      x9, x0, #0x30
uint64_t fde_func_11571_0x3ebbf0(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x003EBBF0ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10083FFULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91008008ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9100C009ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91010002ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB81FC3A1ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #11580 | PC: 0x3ec984..0x3eca84 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x3ec984: D503233F  paciasp  
//   0x3ec988: A9BA7BFD  stp      x29, x30, [sp, #-0x60]!
//   0x3ec98c: A9016FFC  stp      x28, x27, [sp, #0x10]
//   0x3ec990: A90267FA  stp      x26, x25, [sp, #0x20]
//   0x3ec994: A9035FF8  stp      x24, x23, [sp, #0x30]
//   0x3ec998: A90457F6  stp      x22, x21, [sp, #0x40]
uint64_t fde_func_11580_0x3ec984(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x003EC984ULL);
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

// FDE #11590 | PC: 0x3ed950..0x3eda50 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x3ed950: D503233F  paciasp  
//   0x3ed954: A9BB7BFD  stp      x29, x30, [sp, #-0x50]!
//   0x3ed958: A90167FA  stp      x26, x25, [sp, #0x10]
//   0x3ed95c: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x3ed960: A90357F6  stp      x22, x21, [sp, #0x30]
//   0x3ed964: A9044FF4  stp      x20, x19, [sp, #0x40]
uint64_t fde_func_11590_0x3ed950(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x003ED950ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BB7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90167FAULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9025FF8ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90357F6ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9044FF4ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0103F6ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #11600 | PC: 0x3ee324..0x3ee424 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x3ee324: D503233F  paciasp  
//   0x3ee328: D10183FF  sub      sp, sp, #0x60
//   0x3ee32c: A9037BFD  stp      x29, x30, [sp, #0x30]
//   0x3ee330: F90023F5  str      x21, [sp, #0x40]
//   0x3ee334: A9054FF4  stp      x20, x19, [sp, #0x50]
//   0x3ee338: 9100C3FD  add      x29, sp, #0x30
uint64_t fde_func_11600_0x3ee324(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x003EE324ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10183FFULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9037BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF90023F5ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9054FF4ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9100C3FDULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F5ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91092001ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #11609 | PC: 0x3ee924..0x3ee94c (40 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x3ee924: D503245F  bti      c
//   0x3ee928: 5107D028  sub      w8, w1, #0x1f4
//   0x3ee92c: 52803EC9  mov      w9, #0x1f6
//   0x3ee930: 7100251F  cmp      w8, #9
//   0x3ee934: 9101E000  add      x0, x0, #0x78
//   0x3ee938: 1A9F97EA  cset     w10, hi
uint64_t fde_func_11609_0x3ee924(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x003EE924ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x5107D028ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x52803EC9ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x7100251FULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9101E000ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x1A9F97EAULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x1AC82528ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x2A080148ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #11619 | PC: 0x3eec00..0x3eec0c (12 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x3eec00: D503245F  bti      c
//   0x3eec04: D1004000  sub      x0, x0, #0x10
//   0x3eec08: 17FFFFED  b        #0x3eebbc
uint64_t fde_func_11619_0x3eec00(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x003EEC00ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD1004000ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x17FFFFEDULL ^ (2ULL << 32);
    return state ^ (state >> 29);
}

// FDE #11628 | PC: 0x3ef460..0x3ef478 (24 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x3ef460: D503245F  bti      c
//   0x3ef464: D0FFE6C1  adrp     x1, #0xc9000
//   0x3ef468: 9134F021  add      x1, x1, #0xd3c
//   0x3ef46c: 90000F82  adrp     x2, #0x5df000
//   0x3ef470: 91104042  add      x2, x2, #0x410
//   0x3ef474: 17FBC037  b        #0x2df550
uint64_t fde_func_11628_0x3ef460(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x003EF460ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD0FFE6C1ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9134F021ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x90000F82ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91104042ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x17FBC037ULL ^ (5ULL << 32);
    return state ^ (state >> 29);
}

// FDE #11638 | PC: 0x3f05f0..0x3f05fc (12 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x3f05f0: D503245F  bti      c
//   0x3f05f4: F9402400  ldr      x0, [x0, #0x48]
//   0x3f05f8: 1400034A  b        #0x3f1320
uint64_t fde_func_11638_0x3f05f0(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x003F05F0ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9402400ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x1400034AULL ^ (2ULL << 32);
    return state ^ (state >> 29);
}

// FDE #11647 | PC: 0x3f0914..0x3f09bc (168 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x3f0914: D503233F  paciasp  
//   0x3f0918: D10143FF  sub      sp, sp, #0x50
//   0x3f091c: A9037BFD  stp      x29, x30, [sp, #0x30]
//   0x3f0920: A9044FF4  stp      x20, x19, [sp, #0x40]
//   0x3f0924: 9100C3FD  add      x29, sp, #0x30
//   0x3f0928: F9402414  ldr      x20, [x0, #0x48]
uint64_t fde_func_11647_0x3f0914(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x003F0914ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10143FFULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9037BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9044FF4ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9100C3FDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9402414ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x39412288ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x340003C8ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #11657 | PC: 0x3f0bf4..0x3f0c00 (12 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x3f0bf4: D503245F  bti      c
//   0x3f0bf8: 52800020  mov      w0, #1
//   0x3f0bfc: 17FC0D8D  b        #0x2f4230
uint64_t fde_func_11657_0x3f0bf4(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x003F0BF4ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x52800020ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x17FC0D8DULL ^ (2ULL << 32);
    return state ^ (state >> 29);
}

// FDE #11666 | PC: 0x3f10b4..0x3f10f8 (68 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x3f10b4: D503233F  paciasp  
//   0x3f10b8: A9BD7BFD  stp      x29, x30, [sp, #-0x30]!
//   0x3f10bc: F9000BF5  str      x21, [sp, #0x10]
//   0x3f10c0: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x3f10c4: 910003FD  mov      x29, sp
//   0x3f10c8: 91013015  add      x21, x0, #0x4c
uint64_t fde_func_11666_0x3f10b4(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x003F10B4ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BD7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF5ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9024FF4ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91013015ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F4ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA1503E0ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #11676 | PC: 0x3f1478..0x3f153c (196 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x3f1478: D503233F  paciasp  
//   0x3f147c: D101C3FF  sub      sp, sp, #0x70
//   0x3f1480: A9037BFD  stp      x29, x30, [sp, #0x30]
//   0x3f1484: A9045FF8  stp      x24, x23, [sp, #0x40]
//   0x3f1488: A90557F6  stp      x22, x21, [sp, #0x50]
//   0x3f148c: A9064FF4  stp      x20, x19, [sp, #0x60]
uint64_t fde_func_11676_0x3f1478(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x003F1478ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD101C3FFULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9037BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9045FF8ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90557F6ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9064FF4ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9100C3FDULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD53BD057ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #11685 | PC: 0x3f1928..0x3f19f8 (208 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x3f1928: D503233F  paciasp  
//   0x3f192c: D10183FF  sub      sp, sp, #0x60
//   0x3f1930: A9037BFD  stp      x29, x30, [sp, #0x30]
//   0x3f1934: F90023F5  str      x21, [sp, #0x40]
//   0x3f1938: A9054FF4  stp      x20, x19, [sp, #0x50]
//   0x3f193c: 9100C3FD  add      x29, sp, #0x30
uint64_t fde_func_11685_0x3f1928(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x003F1928ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10183FFULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9037BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF90023F5ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9054FF4ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9100C3FDULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD0000D88ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #11695 | PC: 0x3f27f8..0x3f2810 (24 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x3f27f8: D503245F  bti      c
//   0x3f27fc: F0FFE6A1  adrp     x1, #0xc9000
//   0x3f2800: 91384021  add      x1, x1, #0xe10
//   0x3f2804: B0000F62  adrp     x2, #0x5df000
//   0x3f2808: 91118042  add      x2, x2, #0x460
//   0x3f280c: 17FBB351  b        #0x2df550
uint64_t fde_func_11695_0x3f27f8(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x003F27F8ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF0FFE6A1ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91384021ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB0000F62ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91118042ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x17FBB351ULL ^ (5ULL << 32);
    return state ^ (state >> 29);
}

// FDE #11704 | PC: 0x3f2ef4..0x3f2f0c (24 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x3f2ef4: D503245F  bti      c
//   0x3f2ef8: F0FFE6A1  adrp     x1, #0xc9000
//   0x3f2efc: 9138D421  add      x1, x1, #0xe35
//   0x3f2f00: B0000F62  adrp     x2, #0x5df000
//   0x3f2f04: 9112C042  add      x2, x2, #0x4b0
//   0x3f2f08: 17FBB192  b        #0x2df550
uint64_t fde_func_11704_0x3f2ef4(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x003F2EF4ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF0FFE6A1ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9138D421ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB0000F62ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9112C042ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x17FBB192ULL ^ (5ULL << 32);
    return state ^ (state >> 29);
}

// FDE #11714 | PC: 0x3f3afc..0x3f3be4 (232 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x3f3afc: D503233F  paciasp  
//   0x3f3b00: D10203FF  sub      sp, sp, #0x80
//   0x3f3b04: A9057BFD  stp      x29, x30, [sp, #0x50]
//   0x3f3b08: F90033F5  str      x21, [sp, #0x60]
//   0x3f3b0c: A9074FF4  stp      x20, x19, [sp, #0x70]
//   0x3f3b10: 910143FD  add      x29, sp, #0x50
uint64_t fde_func_11714_0x3f3afc(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x003F3AFCULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10203FFULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9057BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF90033F5ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9074FF4ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910143FDULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F5ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0803F3ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #11723 | PC: 0x3f4374..0x3f4474 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x3f4374: D503233F  paciasp  
//   0x3f4378: D10503FF  sub      sp, sp, #0x140
//   0x3f437c: A9107BFD  stp      x29, x30, [sp, #0x100]
//   0x3f4380: F9008BFC  str      x28, [sp, #0x110]
//   0x3f4384: A91257F6  stp      x22, x21, [sp, #0x120]
//   0x3f4388: A9134FF4  stp      x20, x19, [sp, #0x130]
uint64_t fde_func_11723_0x3f4374(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x003F4374ULL);
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

// FDE #11733 | PC: 0x3f4bac..0x3f4c18 (108 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x3f4bac: D503245F  bti      c
//   0x3f4bb0: F9400409  ldr      x9, [x0, #8]
//   0x3f4bb4: AA0103E8  mov      x8, x1
//   0x3f4bb8: AA0903E0  mov      x0, x9
//   0x3f4bbc: F940192A  ldr      x10, [x9, #0x30]
//   0x3f4bc0: F8428C01  ldr      x1, [x0, #0x28]!
uint64_t fde_func_11733_0x3f4bac(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x003F4BACULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400409ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0103E8ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0903E0ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF940192AULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF8428C01ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xEB0A003FULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x54000240ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #11742 | PC: 0x3f5064..0x3f50c0 (92 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x3f5064: D503233F  paciasp  
//   0x3f5068: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x3f506c: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x3f5070: 910003FD  mov      x29, sp
//   0x3f5074: 6F00E400  movi     v0.2d, #0000000000000000
//   0x3f5078: AA0103F4  mov      x20, x1
uint64_t fde_func_11742_0x3f5064(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x003F5064ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9014FF4ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x6F00E400ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0103F4ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAD000000ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #11752 | PC: 0x3f6004..0x3f606c (104 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x3f6004: D503233F  paciasp  
//   0x3f6008: D10103FF  sub      sp, sp, #0x40
//   0x3f600c: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x3f6010: F9001BF3  str      x19, [sp, #0x30]
//   0x3f6014: 910083FD  add      x29, sp, #0x20
//   0x3f6018: 2A0103E8  mov      w8, w1
uint64_t fde_func_11752_0x3f6004(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x003F6004ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10103FFULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9027BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9001BF3ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910083FDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x2A0103E8ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD53BD053ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003E9ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #11761 | PC: 0x3f676c..0x3f683c (208 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x3f676c: D503233F  paciasp  
//   0x3f6770: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x3f6774: 910003FD  mov      x29, sp
//   0x3f6778: F9400409  ldr      x9, [x0, #8]
//   0x3f677c: B4000449  cbz      x9, #0x3f6804
//   0x3f6780: 9E670120  fmov     d0, x9
uint64_t fde_func_11761_0x3f676c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x003F676CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BF7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400409ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB4000449ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9E670120ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x93407C2BULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x0E205800ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #11771 | PC: 0x3f78b0..0x3f794c (156 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x3f78b0: D503233F  paciasp  
//   0x3f78b4: D10103FF  sub      sp, sp, #0x40
//   0x3f78b8: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x3f78bc: F90013F5  str      x21, [sp, #0x20]
//   0x3f78c0: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x3f78c4: 910043FD  add      x29, sp, #0x10
uint64_t fde_func_11771_0x3f78b0(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x003F78B0ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10103FFULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF90013F5ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9034FF4ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F5ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x52800900ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #11780 | PC: 0x3f7eec..0x3f7f18 (44 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x3f7eec: D503233F  paciasp  
//   0x3f7ef0: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x3f7ef4: F9000BF3  str      x19, [sp, #0x10]
//   0x3f7ef8: 910003FD  mov      x29, sp
//   0x3f7efc: AA0003F3  mov      x19, x0
//   0x3f7f00: 97FFFFDB  bl       #0x3f7e6c
uint64_t fde_func_11780_0x3f7eec(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x003F7EECULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF3ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x97FFFFDBULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA1303E0ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400BF3ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #11790 | PC: 0x3f8704..0x3f8804 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x3f8704: D503233F  paciasp  
//   0x3f8708: A9BD7BFD  stp      x29, x30, [sp, #-0x30]!
//   0x3f870c: F9000BF5  str      x21, [sp, #0x10]
//   0x3f8710: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x3f8714: 910003FD  mov      x29, sp
//   0x3f8718: AA0003F3  mov      x19, x0
uint64_t fde_func_11790_0x3f8704(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x003F8704ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BD7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF5ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9024FF4ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9403008ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF0000D49ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #11799 | PC: 0x3f8c9c..0x3f8d58 (188 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x3f8c9c: D503233F  paciasp  
//   0x3f8ca0: D10343FF  sub      sp, sp, #0xd0
//   0x3f8ca4: A90A7BFD  stp      x29, x30, [sp, #0xa0]
//   0x3f8ca8: F9005BF5  str      x21, [sp, #0xb0]
//   0x3f8cac: A90C4FF4  stp      x20, x19, [sp, #0xc0]
//   0x3f8cb0: 910283FD  add      x29, sp, #0xa0
uint64_t fde_func_11799_0x3f8c9c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x003F8C9CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10343FFULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90A7BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9005BF5ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90C4FF4ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910283FDULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD53BD055ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F4ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #11809 | PC: 0x3f9484..0x3f94bc (56 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x3f9484: D503233F  paciasp  
//   0x3f9488: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x3f948c: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x3f9490: 910003FD  mov      x29, sp
//   0x3f9494: AA0103F4  mov      x20, x1
//   0x3f9498: 2A0203E1  mov      w1, w2
uint64_t fde_func_11809_0x3f9484(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x003F9484ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9014FF4ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0103F4ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x2A0203E1ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x2A0203F3ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x97FFFFD6ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #11818 | PC: 0x3f9828..0x3f98d8 (176 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x3f9828: D503233F  paciasp  
//   0x3f982c: A9BD7BFD  stp      x29, x30, [sp, #-0x30]!
//   0x3f9830: F9000BF5  str      x21, [sp, #0x10]
//   0x3f9834: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x3f9838: 910003FD  mov      x29, sp
//   0x3f983c: F9400413  ldr      x19, [x0, #8]
uint64_t fde_func_11818_0x3f9828(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x003F9828ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BD7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF5ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9024FF4ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400413ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF940BA68ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB4000348ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #11828 | PC: 0x3fa2c4..0x3fa3b4 (240 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x3fa2c4: D503233F  paciasp  
//   0x3fa2c8: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x3fa2cc: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x3fa2d0: 910003FD  mov      x29, sp
//   0x3fa2d4: AA0003F3  mov      x19, x0
//   0x3fa2d8: 9108A400  add      x0, x0, #0x229
uint64_t fde_func_11828_0x3fa2c4(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x003FA2C4ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9014FF4ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9108A400ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x97FF1139ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB9400A68ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #11837 | PC: 0x3fa9d8..0x3faa04 (44 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x3fa9d8: D503233F  paciasp  
//   0x3fa9dc: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x3fa9e0: F9000BF3  str      x19, [sp, #0x10]
//   0x3fa9e4: 910003FD  mov      x29, sp
//   0x3fa9e8: AA0003F3  mov      x19, x0
//   0x3fa9ec: 97FFFFE6  bl       #0x3fa984
uint64_t fde_func_11837_0x3fa9d8(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x003FA9D8ULL);
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

// FDE #11847 | PC: 0x3fac28..0x3fac64 (60 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x3fac28: D503233F  paciasp  
//   0x3fac2c: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x3fac30: F9000BF3  str      x19, [sp, #0x10]
//   0x3fac34: 910003FD  mov      x29, sp
//   0x3fac38: AA0003F3  mov      x19, x0
//   0x3fac3c: 9100C000  add      x0, x0, #0x30
uint64_t fde_func_11847_0x3fac28(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x003FAC28ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF3ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9100C000ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB0000D48ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9116C108ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #11856 | PC: 0x3fae34..0x3faea8 (116 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x3fae34: D503245F  bti      c
//   0x3fae38: B4000360  cbz      x0, #0x3faea4
//   0x3fae3c: D503233F  paciasp  
//   0x3fae40: A9BD7BFD  stp      x29, x30, [sp, #-0x30]!
//   0x3fae44: F9000BF5  str      x21, [sp, #0x10]
//   0x3fae48: A9024FF4  stp      x20, x19, [sp, #0x20]
uint64_t fde_func_11856_0x3fae34(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x003FAE34ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB4000360ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BD7BFDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF5ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9024FF4ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #11866 | PC: 0x3fb174..0x3fb1a4 (48 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x3fb174: D503233F  paciasp  
//   0x3fb178: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x3fb17c: F9000BF3  str      x19, [sp, #0x10]
//   0x3fb180: 910003FD  mov      x29, sp
//   0x3fb184: AA0103F3  mov      x19, x1
//   0x3fb188: 9405CF58  bl       #0x56eee8
uint64_t fde_func_11866_0x3fb174(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x003FB174ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF3ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0103F3ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9405CF58ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAD428261ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400BF3ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #11875 | PC: 0x3fb7cc..0x3fb830 (100 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x3fb7cc: D503233F  paciasp  
//   0x3fb7d0: D10203FF  sub      sp, sp, #0x80
//   0x3fb7d4: A9067BFD  stp      x29, x30, [sp, #0x60]
//   0x3fb7d8: A9074FF4  stp      x20, x19, [sp, #0x70]
//   0x3fb7dc: 910183FD  add      x29, sp, #0x60
//   0x3fb7e0: D53BD054  mrs      x20, tpidr_el0
uint64_t fde_func_11875_0x3fb7cc(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x003FB7CCULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10203FFULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9067BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9074FF4ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910183FDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD53BD054ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9401688ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #11885 | PC: 0x3fba7c..0x3fbb04 (136 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x3fba7c: D503245F  bti      c
//   0x3fba80: 720000BF  tst      w5, #1
//   0x3fba84: 52800109  mov      w9, #8
//   0x3fba88: 12800FEA  mov      w10, #-0x80
//   0x3fba8c: 5AC0088B  rev      w11, w4
//   0x3fba90: 1A891149  csel     w9, w10, w9, ne
uint64_t fde_func_11885_0x3fba7c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x003FBA7CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x720000BFULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x52800109ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x12800FEAULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x5AC0088BULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x1A891149ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x5AC0086AULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x2A1F03E8ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #11895 | PC: 0x3fc060..0x3fc118 (184 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x3fc060: D503233F  paciasp  
//   0x3fc064: A9BD7BFD  stp      x29, x30, [sp, #-0x30]!
//   0x3fc068: F9000BF5  str      x21, [sp, #0x10]
//   0x3fc06c: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x3fc070: 910003FD  mov      x29, sp
//   0x3fc074: 39408408  ldrb     w8, [x0, #0x21]
uint64_t fde_func_11895_0x3fc060(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x003FC060ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BD7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF5ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9024FF4ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x39408408ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x34000468ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #11904 | PC: 0x3fc3a8..0x3fc3b0 (8 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x3fc3a8: D503245F  bti      c
//   0x3fc3ac: 14009CB4  b        #0x42367c
uint64_t fde_func_11904_0x3fc3a8(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x003FC3A8ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x14009CB4ULL ^ (1ULL << 32);
    return state ^ (state >> 29);
}

// FDE #11914 | PC: 0x3fc798..0x3fc7c4 (44 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x3fc798: D503245F  bti      c
//   0x3fc79c: AA0003E8  mov      x8, x0
//   0x3fc7a0: F0000D29  adrp     x9, #0x5a3000
//   0x3fc7a4: 911BC129  add      x9, x9, #0x6f0
//   0x3fc7a8: F9400400  ldr      x0, [x0, #8]
//   0x3fc7ac: A9007D09  stp      x9, xzr, [x8]
uint64_t fde_func_11914_0x3fc798(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x003FC798ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003E8ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF0000D29ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x911BC129ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400400ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9007D09ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB4000080ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400008ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #11923 | PC: 0x3fcf68..0x3fcfdc (116 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x3fcf68: D503233F  paciasp  
//   0x3fcf6c: A9BD7BFD  stp      x29, x30, [sp, #-0x30]!
//   0x3fcf70: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x3fcf74: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x3fcf78: 910003FD  mov      x29, sp
//   0x3fcf7c: AA0003F5  mov      x21, x0
uint64_t fde_func_11923_0x3fcf68(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x003FCF68ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BD7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90157F6ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9024FF4ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F5ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF0000D29ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x911D8129ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #11933 | PC: 0x3fd504..0x3fd528 (36 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x3fd504: D503245F  bti      c
//   0x3fd508: A941240A  ldp      x10, x9, [x0, #0x10]
//   0x3fd50c: 528000C8  mov      w8, #6
//   0x3fd510: CB490D2B  sub      x11, x9, x9, lsr #3
//   0x3fd514: F1001D3F  cmp      x9, #7
//   0x3fd518: 9A8B0108  csel     x8, x8, x11, eq
uint64_t fde_func_11933_0x3fd504(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x003FD504ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA941240AULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x528000C8ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xCB490D2BULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF1001D3FULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9A8B0108ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xCB0A0108ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9001008ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #11942 | PC: 0x3fdb14..0x3fdc10 (252 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x3fdb14: D503233F  paciasp  
//   0x3fdb18: FC190FEA  str      d10, [sp, #-0x70]!
//   0x3fdb1c: 6D00A3E9  stp      d9, d8, [sp, #8]
//   0x3fdb20: A901FBFD  stp      x29, x30, [sp, #0x18]
//   0x3fdb24: F90017FB  str      x27, [sp, #0x28]
//   0x3fdb28: A90367FA  stp      x26, x25, [sp, #0x30]
uint64_t fde_func_11942_0x3fdb14(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x003FDB14ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xFC190FEAULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x6D00A3E9ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA901FBFDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF90017FBULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90367FAULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9045FF8ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90557F6ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #11952 | PC: 0x3ffbb4..0x3ffcb4 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x3ffbb4: D503233F  paciasp  
//   0x3ffbb8: D10503FF  sub      sp, sp, #0x140
//   0x3ffbbc: A90E7BFD  stp      x29, x30, [sp, #0xe0]
//   0x3ffbc0: F9007BFC  str      x28, [sp, #0xf0]
//   0x3ffbc4: A91067FA  stp      x26, x25, [sp, #0x100]
//   0x3ffbc8: A9115FF8  stp      x24, x23, [sp, #0x110]
uint64_t fde_func_11952_0x3ffbb4(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x003FFBB4ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10503FFULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90E7BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9007BFCULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA91067FAULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9115FF8ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA91257F6ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9134FF4ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #11961 | PC: 0x401eec..0x401fec (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x401eec: D503233F  paciasp  
//   0x401ef0: D10143FF  sub      sp, sp, #0x50
//   0x401ef4: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x401ef8: F90013F7  str      x23, [sp, #0x20]
//   0x401efc: A90357F6  stp      x22, x21, [sp, #0x30]
//   0x401f00: A9044FF4  stp      x20, x19, [sp, #0x40]
uint64_t fde_func_11961_0x401eec(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00401EECULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10143FFULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF90013F7ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90357F6ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9044FF4ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0203F4ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #11971 | PC: 0x4043c8..0x4043f4 (44 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x4043c8: D503233F  paciasp  
//   0x4043cc: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x4043d0: 910003FD  mov      x29, sp
//   0x4043d4: 52800200  mov      w0, #0x10
//   0x4043d8: 97FB6067  bl       #0x2dc574
//   0x4043dc: 90000D08  adrp     x8, #0x5a4000
uint64_t fde_func_11971_0x4043c8(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x004043C8ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BF7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x52800200ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x97FB6067ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x90000D08ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x911B8108ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000008ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #11980 | PC: 0x4045ac..0x4045d8 (44 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x4045ac: D503233F  paciasp  
//   0x4045b0: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x4045b4: 910003FD  mov      x29, sp
//   0x4045b8: 52800200  mov      w0, #0x10
//   0x4045bc: 97FB5FEE  bl       #0x2dc574
//   0x4045c0: 90000D08  adrp     x8, #0x5a4000
uint64_t fde_func_11980_0x4045ac(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x004045ACULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BF7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x52800200ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x97FB5FEEULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x90000D08ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9117C108ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000008ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #11990 | PC: 0x404768..0x4047c4 (92 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x404768: D503233F  paciasp  
//   0x40476c: D10103FF  sub      sp, sp, #0x40
//   0x404770: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x404774: F9001BF3  str      x19, [sp, #0x30]
//   0x404778: 910083FD  add      x29, sp, #0x20
//   0x40477c: F9400801  ldr      x1, [x0, #0x10]
uint64_t fde_func_11990_0x404768(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00404768ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10103FFULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9027BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9001BF3ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910083FDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400801ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910023E0ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0803F3ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #11999 | PC: 0x40498c..0x4049c8 (60 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x40498c: D503233F  paciasp  
//   0x404990: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x404994: F9000BF3  str      x19, [sp, #0x10]
//   0x404998: 910003FD  mov      x29, sp
//   0x40499c: AA0003F3  mov      x19, x0
//   0x4049a0: 52800200  mov      w0, #0x10
uint64_t fde_func_11999_0x40498c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0040498CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF3ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x52800200ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x97FB5EF4ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400668ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #12009 | PC: 0x404be8..0x404c04 (28 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x404be8: D503245F  bti      c
//   0x404bec: 90000D08  adrp     x8, #0x5a4000
//   0x404bf0: 910B4108  add      x8, x8, #0x2d0
//   0x404bf4: F9000028  str      x8, [x1]
//   0x404bf8: F9400408  ldr      x8, [x0, #8]
//   0x404bfc: F9000428  str      x8, [x1, #8]
uint64_t fde_func_12009_0x404be8(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00404BE8ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x90000D08ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910B4108ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000028ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400408ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000428ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD65F03C0ULL ^ (6ULL << 32);
    return state ^ (state >> 29);
}

// FDE #12018 | PC: 0x404e98..0x404eb4 (28 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x404e98: D503245F  bti      c
//   0x404e9c: 90000D08  adrp     x8, #0x5a4000
//   0x404ea0: 91078108  add      x8, x8, #0x1e0
//   0x404ea4: F9000028  str      x8, [x1]
//   0x404ea8: 3CC08000  ldur     q0, [x0, #8]
//   0x404eac: 3C808020  stur     q0, [x1, #8]
uint64_t fde_func_12018_0x404e98(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00404E98ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x90000D08ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91078108ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000028ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x3CC08000ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x3C808020ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD65F03C0ULL ^ (6ULL << 32);
    return state ^ (state >> 29);
}

// FDE #12028 | PC: 0x4050d8..0x405118 (64 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x4050d8: D503233F  paciasp  
//   0x4050dc: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x4050e0: F9000BF3  str      x19, [sp, #0x10]
//   0x4050e4: 910003FD  mov      x29, sp
//   0x4050e8: AA0003F3  mov      x19, x0
//   0x4050ec: 52800300  mov      w0, #0x18
uint64_t fde_func_12028_0x4050d8(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x004050D8ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF3ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x52800300ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x97FB5D21ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x3CC08260ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #12037 | PC: 0x405304..0x405344 (64 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x405304: D503233F  paciasp  
//   0x405308: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x40530c: F9000BF3  str      x19, [sp, #0x10]
//   0x405310: 910003FD  mov      x29, sp
//   0x405314: AA0003F3  mov      x19, x0
//   0x405318: 52800300  mov      w0, #0x18
uint64_t fde_func_12037_0x405304(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00405304ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF3ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x52800300ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x97FB5C96ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x3CC08260ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #12047 | PC: 0x40556c..0x405588 (28 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x40556c: D503245F  bti      c
//   0x405570: D0000CE8  adrp     x8, #0x5a3000
//   0x405574: 913B0108  add      x8, x8, #0xec0
//   0x405578: F9000028  str      x8, [x1]
//   0x40557c: 3CC08000  ldur     q0, [x0, #8]
//   0x405580: 3C808020  stur     q0, [x1, #8]
uint64_t fde_func_12047_0x40556c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0040556CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD0000CE8ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x913B0108ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000028ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x3CC08000ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x3C808020ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD65F03C0ULL ^ (6ULL << 32);
    return state ^ (state >> 29);
}

// FDE #12056 | PC: 0x405790..0x4057ac (28 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x405790: D503245F  bti      c
//   0x405794: D0000CE8  adrp     x8, #0x5a3000
//   0x405798: 91374108  add      x8, x8, #0xdd0
//   0x40579c: F9000028  str      x8, [x1]
//   0x4057a0: F9400408  ldr      x8, [x0, #8]
//   0x4057a4: F9000428  str      x8, [x1, #8]
uint64_t fde_func_12056_0x405790(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00405790ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD0000CE8ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91374108ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000028ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400408ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000428ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD65F03C0ULL ^ (6ULL << 32);
    return state ^ (state >> 29);
}

// FDE #12066 | PC: 0x405998..0x405a98 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x405998: D503233F  paciasp  
//   0x40599c: D10343FF  sub      sp, sp, #0xd0
//   0x4059a0: A9097BFD  stp      x29, x30, [sp, #0x90]
//   0x4059a4: A90A5FF8  stp      x24, x23, [sp, #0xa0]
//   0x4059a8: A90B57F6  stp      x22, x21, [sp, #0xb0]
//   0x4059ac: A90C4FF4  stp      x20, x19, [sp, #0xc0]
uint64_t fde_func_12066_0x405998(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00405998ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10343FFULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9097BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90A5FF8ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90B57F6ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90C4FF4ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910243FDULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0803F3ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #12075 | PC: 0x405ce8..0x405d08 (32 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x405ce8: D503245F  bti      c
//   0x405cec: F940040A  ldr      x10, [x0, #8]
//   0x405cf0: 52800069  mov      w9, #3
//   0x405cf4: BD4EF940  ldr      s0, [x10, #0xef8]
//   0x405cf8: F9000D09  str      x9, [x8, #0x18]
//   0x405cfc: 7E61D800  ucvtf    d0, d0
uint64_t fde_func_12075_0x405ce8(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00405CE8ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF940040AULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x52800069ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xBD4EF940ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000D09ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x7E61D800ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xFD000100ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD65F03C0ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #12085 | PC: 0x405e64..0x405ea0 (60 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x405e64: D503233F  paciasp  
//   0x405e68: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x405e6c: F9000BF3  str      x19, [sp, #0x10]
//   0x405e70: 910003FD  mov      x29, sp
//   0x405e74: AA0003F3  mov      x19, x0
//   0x405e78: 52800200  mov      w0, #0x10
uint64_t fde_func_12085_0x405e64(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00405E64ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF3ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x52800200ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x97FB59BEULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400668ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #12094 | PC: 0x405fc8..0x406004 (60 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x405fc8: D503233F  paciasp  
//   0x405fcc: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x405fd0: F9000BF3  str      x19, [sp, #0x10]
//   0x405fd4: 910003FD  mov      x29, sp
//   0x405fd8: AA0003F3  mov      x19, x0
//   0x405fdc: 52800200  mov      w0, #0x10
uint64_t fde_func_12094_0x405fc8(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00405FC8ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF3ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x52800200ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x97FB5965ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400668ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #12104 | PC: 0x4061f4..0x406210 (28 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x4061f4: D503245F  bti      c
//   0x4061f8: B0000CE8  adrp     x8, #0x5a3000
//   0x4061fc: 91234108  add      x8, x8, #0x8d0
//   0x406200: F9000028  str      x8, [x1]
//   0x406204: F9400408  ldr      x8, [x0, #8]
//   0x406208: F9000428  str      x8, [x1, #8]
uint64_t fde_func_12104_0x4061f4(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x004061F4ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB0000CE8ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91234108ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000028ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400408ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000428ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD65F03C0ULL ^ (6ULL << 32);
    return state ^ (state >> 29);
}

// FDE #12113 | PC: 0x406350..0x40637c (44 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x406350: D503245F  bti      c
//   0x406354: F940040A  ldr      x10, [x0, #8]
//   0x406358: 52800F09  mov      w9, #0x78
//   0x40635c: A9472D4A  ldp      x10, x11, [x10, #0x70]
//   0x406360: CB0A016A  sub      x10, x11, x10
//   0x406364: 9AC90D49  sdiv     x9, x10, x9
uint64_t fde_func_12113_0x406350(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00406350ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF940040AULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x52800F09ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9472D4AULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xCB0A016AULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9AC90D49ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x5280004AULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000D0AULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #12123 | PC: 0x4066ec..0x4067ec (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x4066ec: D503233F  paciasp  
//   0x4066f0: D101C3FF  sub      sp, sp, #0x70
//   0x4066f4: A9037BFD  stp      x29, x30, [sp, #0x30]
//   0x4066f8: A9045FF8  stp      x24, x23, [sp, #0x40]
//   0x4066fc: A90557F6  stp      x22, x21, [sp, #0x50]
//   0x406700: A9064FF4  stp      x20, x19, [sp, #0x60]
uint64_t fde_func_12123_0x4066ec(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x004066ECULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD101C3FFULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9037BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9045FF8ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90557F6ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9064FF4ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9100C3FDULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0203F3ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #12132 | PC: 0x406b90..0x406bb8 (40 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x406b90: D503245F  bti      c
//   0x406b94: AA0003E8  mov      x8, x0
//   0x406b98: F940D400  ldr      x0, [x0, #0x1a8]
//   0x406b9c: B902AD01  str      w1, [x8, #0x2ac]
//   0x406ba0: B4000080  cbz      x0, #0x406bb0
//   0x406ba4: F9400008  ldr      x8, [x0]
uint64_t fde_func_12132_0x406b90(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00406B90ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003E8ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF940D400ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB902AD01ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB4000080ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400008ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9401D10ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD61F0200ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #12142 | PC: 0x406d50..0x406d6c (28 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x406d50: D503245F  bti      c
//   0x406d54: F940D400  ldr      x0, [x0, #0x1a8]
//   0x406d58: B4000080  cbz      x0, #0x406d68
//   0x406d5c: F9400008  ldr      x8, [x0]
//   0x406d60: F9406910  ldr      x16, [x8, #0xd0]
//   0x406d64: D61F0200  br       x16
uint64_t fde_func_12142_0x406d50(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00406D50ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF940D400ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB4000080ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400008ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9406910ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD61F0200ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD65F03C0ULL ^ (6ULL << 32);
    return state ^ (state >> 29);
}

// FDE #12151 | PC: 0x4074dc..0x407524 (72 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x4074dc: D503233F  paciasp  
//   0x4074e0: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x4074e4: F9000BF3  str      x19, [sp, #0x10]
//   0x4074e8: 910003FD  mov      x29, sp
//   0x4074ec: AA0003F3  mov      x19, x0
//   0x4074f0: 9400002F  bl       #0x4075ac
uint64_t fde_func_12151_0x4074dc(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x004074DCULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF3ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9400002FULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x3100041FULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x540000E0ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #12161 | PC: 0x407a94..0x407aac (24 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x407a94: D503245F  bti      c
//   0x407a98: F940E009  ldr      x9, [x0, #0x1c0]
//   0x407a9c: AA0103E8  mov      x8, x1
//   0x407aa0: AA0803E0  mov      x0, x8
//   0x407aa4: 91006121  add      x1, x9, #0x18
//   0x407aa8: 17FD442D  b        #0x358b5c
uint64_t fde_func_12161_0x407a94(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00407A94ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF940E009ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0103E8ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0803E0ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91006121ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x17FD442DULL ^ (5ULL << 32);
    return state ^ (state >> 29);
}

// FDE #12170 | PC: 0x407ff0..0x408040 (80 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x407ff0: D503233F  paciasp  
//   0x407ff4: A9BD7BFD  stp      x29, x30, [sp, #-0x30]!
//   0x407ff8: F9000BF5  str      x21, [sp, #0x10]
//   0x407ffc: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x408000: 910003FD  mov      x29, sp
//   0x408004: AA0103F3  mov      x19, x1
uint64_t fde_func_12170_0x407ff0(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00407FF0ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BD7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF5ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9024FF4ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0103F3ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F4ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400415ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #12180 | PC: 0x4085d4..0x40862c (88 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x4085d4: D503233F  paciasp  
//   0x4085d8: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x4085dc: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x4085e0: 910003FD  mov      x29, sp
//   0x4085e4: AA0103F3  mov      x19, x1
//   0x4085e8: AA0003F4  mov      x20, x0
uint64_t fde_func_12180_0x4085d4(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x004085D4ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9014FF4ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0103F3ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F4ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x97F787FBULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91006280ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #12189 | PC: 0x409064..0x4090c8 (100 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x409064: D503233F  paciasp  
//   0x409068: D10303FF  sub      sp, sp, #0xc0
//   0x40906c: A9097BFD  stp      x29, x30, [sp, #0x90]
//   0x409070: F90053F5  str      x21, [sp, #0xa0]
//   0x409074: A90B4FF4  stp      x20, x19, [sp, #0xb0]
//   0x409078: 910243FD  add      x29, sp, #0x90
uint64_t fde_func_12189_0x409064(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00409064ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10303FFULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9097BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF90053F5ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90B4FF4ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910243FDULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F4ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910023E0ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #12199 | PC: 0x409e04..0x409e6c (104 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x409e04: D503233F  paciasp  
//   0x409e08: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x409e0c: F9000BF3  str      x19, [sp, #0x10]
//   0x409e10: 910003FD  mov      x29, sp
//   0x409e14: F9400808  ldr      x8, [x0, #0x10]
//   0x409e18: B40000C8  cbz      x8, #0x409e30
uint64_t fde_func_12199_0x409e04(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00409E04ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF3ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400808ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB40000C8ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91002109ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x885F7D2AULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #12209 | PC: 0x40a6d8..0x40a6f0 (24 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x40a6d8: D503245F  bti      c
//   0x40a6dc: B4000061  cbz      x1, #0x40a6e8
//   0x40a6e0: 91002000  add      x0, x0, #8
//   0x40a6e4: 17FC2D5F  b        #0x315c60
//   0x40a6e8: 2A1F03E0  mov      w0, wzr
//   0x40a6ec: D65F03C0  ret      
uint64_t fde_func_12209_0x40a6d8(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0040A6D8ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB4000061ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91002000ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x17FC2D5FULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x2A1F03E0ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD65F03C0ULL ^ (5ULL << 32);
    return state ^ (state >> 29);
}

// FDE #12218 | PC: 0x40aa84..0x40ab84 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x40aa84: D503233F  paciasp  
//   0x40aa88: D101C3FF  sub      sp, sp, #0x70
//   0x40aa8c: A9047BFD  stp      x29, x30, [sp, #0x40]
//   0x40aa90: A90557F6  stp      x22, x21, [sp, #0x50]
//   0x40aa94: A9064FF4  stp      x20, x19, [sp, #0x60]
//   0x40aa98: 910103FD  add      x29, sp, #0x40
uint64_t fde_func_12218_0x40aa84(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0040AA84ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD101C3FFULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9047BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90557F6ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9064FF4ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910103FDULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F5ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10023A0ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #12228 | PC: 0x40b464..0x40b4f0 (140 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x40b464: D503233F  paciasp  
//   0x40b468: D100C3FF  sub      sp, sp, #0x30
//   0x40b46c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x40b470: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x40b474: 910043FD  add      x29, sp, #0x10
//   0x40b478: AA0003F3  mov      x19, x0
uint64_t fde_func_12228_0x40b464(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0040B464ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD100C3FFULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9024FF4ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x394E6008ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x340001A8ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #12237 | PC: 0x40ba58..0x40ba6c (20 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x40ba58: D503245F  bti      c
//   0x40ba5c: 9104E000  add      x0, x0, #0x138
//   0x40ba60: F0FFE601  adrp     x1, #0xce000
//   0x40ba64: 91074821  add      x1, x1, #0x1d2
//   0x40ba68: 17F7117C  b        #0x1d0058
uint64_t fde_func_12237_0x40ba58(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0040BA58ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9104E000ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF0FFE601ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91074821ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x17F7117CULL ^ (4ULL << 32);
    return state ^ (state >> 29);
}

// FDE #12247 | PC: 0x40caac..0x40cad8 (44 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x40caac: D503233F  paciasp  
//   0x40cab0: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x40cab4: 910003FD  mov      x29, sp
//   0x40cab8: 52800200  mov      w0, #0x10
//   0x40cabc: 97FB3EAE  bl       #0x2dc574
//   0x40cac0: B0000CC8  adrp     x8, #0x5a5000
uint64_t fde_func_12247_0x40caac(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0040CAACULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BF7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x52800200ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x97FB3EAEULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB0000CC8ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91024108ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000008ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #12256 | PC: 0x40cbd0..0x40cbe4 (20 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x40cbd0: D503245F  bti      c
//   0x40cbd4: 90000CC8  adrp     x8, #0x5a4000
//   0x40cbd8: 913E8108  add      x8, x8, #0xfa0
//   0x40cbdc: F9000028  str      x8, [x1]
//   0x40cbe0: D65F03C0  ret      
uint64_t fde_func_12256_0x40cbd0(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0040CBD0ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x90000CC8ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x913E8108ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000028ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD65F03C0ULL ^ (4ULL << 32);
    return state ^ (state >> 29);
}

// FDE #12266 | PC: 0x40cdcc..0x40cdf8 (44 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x40cdcc: D503233F  paciasp  
//   0x40cdd0: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x40cdd4: 910003FD  mov      x29, sp
//   0x40cdd8: 52800200  mov      w0, #0x10
//   0x40cddc: 97FB3DE6  bl       #0x2dc574
//   0x40cde0: 90000CC8  adrp     x8, #0x5a4000
uint64_t fde_func_12266_0x40cdcc(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0040CDCCULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BF7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x52800200ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x97FB3DE6ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x90000CC8ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91398108ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000008ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #12275 | PC: 0x40f078..0x40f0ec (116 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x40f078: D503233F  paciasp  
//   0x40f07c: D10103FF  sub      sp, sp, #0x40
//   0x40f080: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x40f084: F90013F5  str      x21, [sp, #0x20]
//   0x40f088: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x40f08c: 910043FD  add      x29, sp, #0x10
uint64_t fde_func_12275_0x40f078(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0040F078ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10103FFULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF90013F5ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9034FF4ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F5ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003E0ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #12285 | PC: 0x40f5cc..0x40f5e0 (20 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x40f5cc: D503245F  bti      c
//   0x40f5d0: D0000CA8  adrp     x8, #0x5a5000
//   0x40f5d4: 91394108  add      x8, x8, #0xe50
//   0x40f5d8: F9000028  str      x8, [x1]
//   0x40f5dc: D65F03C0  ret      
uint64_t fde_func_12285_0x40f5cc(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0040F5CCULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD0000CA8ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91394108ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000028ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD65F03C0ULL ^ (4ULL << 32);
    return state ^ (state >> 29);
}

// FDE #12294 | PC: 0x40f6c8..0x40f6dc (20 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x40f6c8: D503245F  bti      c
//   0x40f6cc: B9400028  ldr      w8, [x1]
//   0x40f6d0: 7100011F  cmp      w8, #0
//   0x40f6d4: 1A9FD7E0  cset     w0, gt
//   0x40f6d8: D65F03C0  ret      
uint64_t fde_func_12294_0x40f6c8(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0040F6C8ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB9400028ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x7100011FULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x1A9FD7E0ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD65F03C0ULL ^ (4ULL << 32);
    return state ^ (state >> 29);
}

// FDE #12304 | PC: 0x40f808..0x40f81c (20 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x40f808: D503245F  bti      c
//   0x40f80c: D0000CA8  adrp     x8, #0x5a5000
//   0x40f810: 912F4108  add      x8, x8, #0xbd0
//   0x40f814: F9000028  str      x8, [x1]
//   0x40f818: D65F03C0  ret      
uint64_t fde_func_12304_0x40f808(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0040F808ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD0000CA8ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x912F4108ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000028ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD65F03C0ULL ^ (4ULL << 32);
    return state ^ (state >> 29);
}

// FDE #12313 | PC: 0x40f91c..0x40f948 (44 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x40f91c: D503233F  paciasp  
//   0x40f920: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x40f924: 910003FD  mov      x29, sp
//   0x40f928: 52800200  mov      w0, #0x10
//   0x40f92c: 97FB3312  bl       #0x2dc574
//   0x40f930: D0000CA8  adrp     x8, #0x5a5000
uint64_t fde_func_12313_0x40f91c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0040F91CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BF7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x52800200ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x97FB3312ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD0000CA8ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91290108ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000008ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #12323 | PC: 0x40facc..0x40fb18 (76 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x40facc: D503245F  bti      c
//   0x40fad0: B4000220  cbz      x0, #0x40fb14
//   0x40fad4: D503233F  paciasp  
//   0x40fad8: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x40fadc: F9000BF3  str      x19, [sp, #0x10]
//   0x40fae0: 910003FD  mov      x29, sp
uint64_t fde_func_12323_0x40facc(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0040FACCULL);
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

// FDE #12332 | PC: 0x40fc18..0x40fc44 (44 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x40fc18: D503233F  paciasp  
//   0x40fc1c: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x40fc20: 910003FD  mov      x29, sp
//   0x40fc24: 52800200  mov      w0, #0x10
//   0x40fc28: 97FB3253  bl       #0x2dc574
//   0x40fc2c: D0000CA8  adrp     x8, #0x5a5000
uint64_t fde_func_12332_0x40fc18(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0040FC18ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BF7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x52800200ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x97FB3253ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD0000CA8ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x911F0108ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000008ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #12342 | PC: 0x40fd58..0x40fd84 (44 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x40fd58: D503233F  paciasp  
//   0x40fd5c: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x40fd60: 910003FD  mov      x29, sp
//   0x40fd64: 52800200  mov      w0, #0x10
//   0x40fd68: 97FB3203  bl       #0x2dc574
//   0x40fd6c: D0000CA8  adrp     x8, #0x5a5000
uint64_t fde_func_12342_0x40fd58(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0040FD58ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BF7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x52800200ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x97FB3203ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD0000CA8ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9118C108ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000008ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #12351 | PC: 0x41001c..0x410048 (44 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x41001c: D503233F  paciasp  
//   0x410020: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x410024: 910003FD  mov      x29, sp
//   0x410028: 52800200  mov      w0, #0x10
//   0x41002c: 97FB3152  bl       #0x2dc574
//   0x410030: B0000CA8  adrp     x8, #0x5a5000
uint64_t fde_func_12351_0x41001c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0041001CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BF7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x52800200ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x97FB3152ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB0000CA8ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91150108ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000008ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #12361 | PC: 0x41018c..0x4101a0 (20 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x41018c: D503245F  bti      c
//   0x410190: B0000CA8  adrp     x8, #0x5a5000
//   0x410194: 91100108  add      x8, x8, #0x400
//   0x410198: F9000028  str      x8, [x1]
//   0x41019c: D65F03C0  ret      
uint64_t fde_func_12361_0x41018c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0041018CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB0000CA8ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91100108ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000028ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD65F03C0ULL ^ (4ULL << 32);
    return state ^ (state >> 29);
}

// FDE #12370 | PC: 0x4102a0..0x4102cc (44 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x4102a0: D503233F  paciasp  
//   0x4102a4: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x4102a8: 910003FD  mov      x29, sp
//   0x4102ac: 52800200  mov      w0, #0x10
//   0x4102b0: 97FB30B1  bl       #0x2dc574
//   0x4102b4: B0000CA8  adrp     x8, #0x5a5000
uint64_t fde_func_12370_0x4102a0(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x004102A0ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BF7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x52800200ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x97FB30B1ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB0000CA8ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9109C108ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000008ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #12380 | PC: 0x4104a0..0x4104cc (44 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x4104a0: D503233F  paciasp  
//   0x4104a4: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x4104a8: 910003FD  mov      x29, sp
//   0x4104ac: 52800200  mov      w0, #0x10
//   0x4104b0: 97FB3031  bl       #0x2dc574
//   0x4104b4: B0000CA8  adrp     x8, #0x5a5000
uint64_t fde_func_12380_0x4104a0(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x004104A0ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BF7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x52800200ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x97FB3031ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB0000CA8ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9104C108ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000008ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #12389 | PC: 0x410664..0x410698 (52 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x410664: D503233F  paciasp  
//   0x410668: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x41066c: F9000BF3  str      x19, [sp, #0x10]
//   0x410670: 910003FD  mov      x29, sp
//   0x410674: AA0003F3  mov      x19, x0
//   0x410678: F9400000  ldr      x0, [x0]
uint64_t fde_func_12389_0x410664(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00410664ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF3ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400000ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000261ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x97F7A10AULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #12399 | PC: 0x410d64..0x410e30 (204 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x410d64: D503233F  paciasp  
//   0x410d68: D101C3FF  sub      sp, sp, #0x70
//   0x410d6c: A9037BFD  stp      x29, x30, [sp, #0x30]
//   0x410d70: A9045FF8  stp      x24, x23, [sp, #0x40]
//   0x410d74: A90557F6  stp      x22, x21, [sp, #0x50]
//   0x410d78: A9064FF4  stp      x20, x19, [sp, #0x60]
uint64_t fde_func_12399_0x410d64(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00410D64ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD101C3FFULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9037BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9045FF8ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90557F6ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9064FF4ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9100C3FDULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD53BD057ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #12408 | PC: 0x4112c0..0x4112e8 (40 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x4112c0: D503245F  bti      c
//   0x4112c4: 6F00E400  movi     v0.2d, #0000000000000000
//   0x4112c8: AA0003E8  mov      x8, x0
//   0x4112cc: 91010000  add      x0, x0, #0x40
//   0x4112d0: 3900011F  strb     wzr, [x8]
//   0x4112d4: A9037D1F  stp      xzr, xzr, [x8, #0x30]
uint64_t fde_func_12408_0x4112c0(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x004112C0ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x6F00E400ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003E8ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91010000ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x3900011FULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9037D1FULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF900151FULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x3C804100ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #12418 | PC: 0x411824..0x411924 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x411824: D503233F  paciasp  
//   0x411828: D10103FF  sub      sp, sp, #0x40
//   0x41182c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x411830: F90013F5  str      x21, [sp, #0x20]
//   0x411834: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x411838: 910043FD  add      x29, sp, #0x10
uint64_t fde_func_12418_0x411824(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00411824ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10103FFULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF90013F5ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9034FF4ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB4000701ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400C28ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #12427 | PC: 0x412768..0x412868 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x412768: D503233F  paciasp  
//   0x41276c: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x412770: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x412774: 910003FD  mov      x29, sp
//   0x412778: 52825D08  mov      w8, #0x12e8
//   0x41277c: 52826B09  mov      w9, #0x1358
uint64_t fde_func_12427_0x412768(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00412768ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9014FF4ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x52825D08ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x52826B09ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x8B080014ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #12437 | PC: 0x41a6c0..0x41a790 (208 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x41a6c0: D503233F  paciasp  
//   0x41a6c4: D10143FF  sub      sp, sp, #0x50
//   0x41a6c8: A9037BFD  stp      x29, x30, [sp, #0x30]
//   0x41a6cc: A9044FF4  stp      x20, x19, [sp, #0x40]
//   0x41a6d0: 9100C3FD  add      x29, sp, #0x30
//   0x41a6d4: 39406008  ldrb     w8, [x0, #0x18]
uint64_t fde_func_12437_0x41a6c0(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0041A6C0ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10143FFULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9037BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9044FF4ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9100C3FDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x39406008ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F4ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0103F3ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #12446 | PC: 0x41ac48..0x41ad48 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x41ac48: D503233F  paciasp  
//   0x41ac4c: D101C3FF  sub      sp, sp, #0x70
//   0x41ac50: A9037BFD  stp      x29, x30, [sp, #0x30]
//   0x41ac54: A9045FF8  stp      x24, x23, [sp, #0x40]
//   0x41ac58: A90557F6  stp      x22, x21, [sp, #0x50]
//   0x41ac5c: A9064FF4  stp      x20, x19, [sp, #0x60]
uint64_t fde_func_12446_0x41ac48(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0041AC48ULL);
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

// FDE #12456 | PC: 0x41b6ac..0x41b778 (204 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x41b6ac: D503233F  paciasp  
//   0x41b6b0: D101C3FF  sub      sp, sp, #0x70
//   0x41b6b4: A9037BFD  stp      x29, x30, [sp, #0x30]
//   0x41b6b8: A9045FF8  stp      x24, x23, [sp, #0x40]
//   0x41b6bc: A90557F6  stp      x22, x21, [sp, #0x50]
//   0x41b6c0: A9064FF4  stp      x20, x19, [sp, #0x60]
uint64_t fde_func_12456_0x41b6ac(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0041B6ACULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD101C3FFULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9037BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9045FF8ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90557F6ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9064FF4ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9100C3FDULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD53BD057ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #12465 | PC: 0x41bdb0..0x41be10 (96 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x41bdb0: D503233F  paciasp  
//   0x41bdb4: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x41bdb8: F9000BF3  str      x19, [sp, #0x10]
//   0x41bdbc: 910003FD  mov      x29, sp
//   0x41bdc0: AA0003F3  mov      x19, x0
//   0x41bdc4: F9404C00  ldr      x0, [x0, #0x98]
uint64_t fde_func_12465_0x41bdb0(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0041BDB0ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF3ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9404C00ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x97F77338ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9404A60ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #12475 | PC: 0x41cb28..0x41cc28 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x41cb28: D503233F  paciasp  
//   0x41cb2c: D102C3FF  sub      sp, sp, #0xb0
//   0x41cb30: A9077BFD  stp      x29, x30, [sp, #0x70]
//   0x41cb34: F90043F7  str      x23, [sp, #0x80]
//   0x41cb38: A90957F6  stp      x22, x21, [sp, #0x90]
//   0x41cb3c: A90A4FF4  stp      x20, x19, [sp, #0xa0]
uint64_t fde_func_12475_0x41cb28(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0041CB28ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD102C3FFULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9077BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF90043F7ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90957F6ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90A4FF4ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9101C3FDULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB941A028ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #12484 | PC: 0x41d1b0..0x41d230 (128 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x41d1b0: D503233F  paciasp  
//   0x41d1b4: D10103FF  sub      sp, sp, #0x40
//   0x41d1b8: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x41d1bc: F9001BF3  str      x19, [sp, #0x30]
//   0x41d1c0: 910083FD  add      x29, sp, #0x20
//   0x41d1c4: AA0103F3  mov      x19, x1
uint64_t fde_func_12484_0x41d1b0(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0041D1B0ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10103FFULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9027BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9001BF3ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910083FDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0103F3ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91384001ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910023E0ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #12494 | PC: 0x41d8a4..0x41d9a4 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x41d8a4: D503233F  paciasp  
//   0x41d8a8: A9BA7BFD  stp      x29, x30, [sp, #-0x60]!
//   0x41d8ac: A9016FFC  stp      x28, x27, [sp, #0x10]
//   0x41d8b0: A90267FA  stp      x26, x25, [sp, #0x20]
//   0x41d8b4: A9035FF8  stp      x24, x23, [sp, #0x30]
//   0x41d8b8: A90457F6  stp      x22, x21, [sp, #0x40]
uint64_t fde_func_12494_0x41d8a4(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0041D8A4ULL);
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

// FDE #12504 | PC: 0x41fc38..0x41fc4c (20 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x41fc38: D503245F  bti      c
//   0x41fc3c: B0FFE3C0  adrp     x0, #0x98000
//   0x41fc40: 911ADC00  add      x0, x0, #0x6b7
//   0x41fc44: 52800541  mov      w1, #0x2a
//   0x41fc48: 17F9E239  b        #0x29852c
uint64_t fde_func_12504_0x41fc38(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0041FC38ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB0FFE3C0ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x911ADC00ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x52800541ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x17F9E239ULL ^ (4ULL << 32);
    return state ^ (state >> 29);
}

// FDE #12513 | PC: 0x42023c..0x42033c (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x42023c: D503233F  paciasp  
//   0x420240: D10383FF  sub      sp, sp, #0xe0
//   0x420244: A9097BFD  stp      x29, x30, [sp, #0x90]
//   0x420248: A90A67FA  stp      x26, x25, [sp, #0xa0]
//   0x42024c: A90B5FF8  stp      x24, x23, [sp, #0xb0]
//   0x420250: A90C57F6  stp      x22, x21, [sp, #0xc0]
uint64_t fde_func_12513_0x42023c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0042023CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10383FFULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9097BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90A67FAULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90B5FF8ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90C57F6ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90D4FF4ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910243FDULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #12523 | PC: 0x420828..0x420834 (12 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x420828: D503245F  bti      c
//   0x42082c: D1002000  sub      x0, x0, #8
//   0x420830: 17FFFF23  b        #0x4204bc
uint64_t fde_func_12523_0x420828(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00420828ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD1002000ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x17FFFF23ULL ^ (2ULL << 32);
    return state ^ (state >> 29);
}

// FDE #12532 | PC: 0x420894..0x4208a0 (12 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x420894: D503245F  bti      c
//   0x420898: D100A000  sub      x0, x0, #0x28
//   0x42089c: 17FFFED1  b        #0x4203e0
uint64_t fde_func_12532_0x420894(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00420894ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD100A000ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x17FFFED1ULL ^ (2ULL << 32);
    return state ^ (state >> 29);
}

// FDE #12542 | PC: 0x421190..0x42123c (172 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x421190: D503233F  paciasp  
//   0x421194: D10403FF  sub      sp, sp, #0x100
//   0x421198: A90E7BFD  stp      x29, x30, [sp, #0xe0]
//   0x42119c: F9007BF3  str      x19, [sp, #0xf0]
//   0x4211a0: 910383FD  add      x29, sp, #0xe0
//   0x4211a4: D53BD053  mrs      x19, tpidr_el0
uint64_t fde_func_12542_0x421190(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00421190ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10403FFULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90E7BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9007BF3ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910383FDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD53BD053ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD0FFE2C9ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9401668ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #12551 | PC: 0x42155c..0x421584 (40 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x42155c: D503233F  paciasp  
//   0x421560: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x421564: 910003FD  mov      x29, sp
//   0x421568: F9404408  ldr      x8, [x0, #0x88]
//   0x42156c: F100051F  cmp      x8, #1
//   0x421570: 54000081  b.ne     #0x421580
uint64_t fde_func_12551_0x42155c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0042155CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BF7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9404408ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF100051FULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x54000081ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA8C17BFDULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD50323BFULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #12561 | PC: 0x421908..0x42191c (20 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x421908: D503245F  bti      c
//   0x42190c: 39400008  ldrb     w8, [x0]
//   0x421910: 34000048  cbz      w8, #0x421918
//   0x421914: D65F03C0  ret      
//   0x421918: 17F84781  b        #0x23371c
uint64_t fde_func_12561_0x421908(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00421908ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x39400008ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x34000048ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD65F03C0ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x17F84781ULL ^ (4ULL << 32);
    return state ^ (state >> 29);
}

// FDE #12570 | PC: 0x422454..0x42245c (8 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x422454: D503245F  bti      c
//   0x422458: 17FFFFEB  b        #0x422404
uint64_t fde_func_12570_0x422454(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00422454ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x17FFFFEBULL ^ (1ULL << 32);
    return state ^ (state >> 29);
}

// FDE #12580 | PC: 0x422b3c..0x422c3c (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x422b3c: D503233F  paciasp  
//   0x422b40: D10643FF  sub      sp, sp, #0x190
//   0x422b44: A9137BFD  stp      x29, x30, [sp, #0x130]
//   0x422b48: A9146FFC  stp      x28, x27, [sp, #0x140]
//   0x422b4c: A91567FA  stp      x26, x25, [sp, #0x150]
//   0x422b50: A9165FF8  stp      x24, x23, [sp, #0x160]
uint64_t fde_func_12580_0x422b3c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00422B3CULL);
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

// FDE #12589 | PC: 0x423334..0x4233f8 (196 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x423334: D503233F  paciasp  
//   0x423338: D10143FF  sub      sp, sp, #0x50
//   0x42333c: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x423340: F9001BF5  str      x21, [sp, #0x30]
//   0x423344: A9044FF4  stp      x20, x19, [sp, #0x40]
//   0x423348: 910083FD  add      x29, sp, #0x20
uint64_t fde_func_12589_0x423334(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00423334ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10143FFULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9027BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9001BF5ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9044FF4ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910083FDULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x2A0103F3ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F4ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #12599 | PC: 0x423710..0x423810 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x423710: D503233F  paciasp  
//   0x423714: D105C3FF  sub      sp, sp, #0x170
//   0x423718: A9147BFD  stp      x29, x30, [sp, #0x140]
//   0x42371c: F900ABFC  str      x28, [sp, #0x150]
//   0x423720: A9164FF4  stp      x20, x19, [sp, #0x160]
//   0x423724: 910503FD  add      x29, sp, #0x140
uint64_t fde_func_12599_0x423710(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00423710ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD105C3FFULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9147BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF900ABFCULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9164FF4ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910503FDULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD53BD054ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9401688ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #12608 | PC: 0x424164..0x42419c (56 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x424164: D503245F  bti      c
//   0x424168: 3940E008  ldrb     w8, [x0, #0x38]
//   0x42416c: 34000048  cbz      w8, #0x424174
//   0x424170: 3900E01F  strb     wzr, [x0, #0x38]
//   0x424174: 39409808  ldrb     w8, [x0, #0x26]
//   0x424178: 34000048  cbz      w8, #0x424180
uint64_t fde_func_12608_0x424164(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00424164ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x3940E008ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x34000048ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x3900E01FULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x39409808ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x34000048ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x3900981FULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x39405008ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #12618 | PC: 0x4253b8..0x4254b8 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x4253b8: D503233F  paciasp  
//   0x4253bc: D101C3FF  sub      sp, sp, #0x70
//   0x4253c0: A9037BFD  stp      x29, x30, [sp, #0x30]
//   0x4253c4: F90023F7  str      x23, [sp, #0x40]
//   0x4253c8: A90557F6  stp      x22, x21, [sp, #0x50]
//   0x4253cc: A9064FF4  stp      x20, x19, [sp, #0x60]
uint64_t fde_func_12618_0x4253b8(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x004253B8ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD101C3FFULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9037BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF90023F7ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90557F6ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9064FF4ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9100C3FDULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD53BD057ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #12627 | PC: 0x425d00..0x425e00 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x425d00: D503233F  paciasp  
//   0x425d04: D10143FF  sub      sp, sp, #0x50
//   0x425d08: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x425d0c: F9001BF5  str      x21, [sp, #0x30]
//   0x425d10: A9044FF4  stp      x20, x19, [sp, #0x40]
//   0x425d14: 910083FD  add      x29, sp, #0x20
uint64_t fde_func_12627_0x425d00(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00425D00ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10143FFULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9027BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9001BF5ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9044FF4ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910083FDULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91082000ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #12637 | PC: 0x425f54..0x425ff4 (160 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x425f54: D503233F  paciasp  
//   0x425f58: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x425f5c: F9000BF3  str      x19, [sp, #0x10]
//   0x425f60: 910003FD  mov      x29, sp
//   0x425f64: 7100043F  cmp      w1, #1
//   0x425f68: 540000C0  b.eq     #0x425f80
uint64_t fde_func_12637_0x425f54(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00425F54ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF3ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x7100043FULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x540000C0ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x35000121ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x39423408ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #12646 | PC: 0x4261e4..0x4261f0 (12 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x4261e4: D503245F  bti      c
//   0x4261e8: D100A000  sub      x0, x0, #0x28
//   0x4261ec: 17FFFF82  b        #0x425ff4
uint64_t fde_func_12646_0x4261e4(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x004261E4ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD100A000ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x17FFFF82ULL ^ (2ULL << 32);
    return state ^ (state >> 29);
}

// FDE #12656 | PC: 0x426e7c..0x426e88 (12 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x426e7c: D503245F  bti      c
//   0x426e80: D1002000  sub      x0, x0, #8
//   0x426e84: 17FFFD7C  b        #0x426474
uint64_t fde_func_12656_0x426e7c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00426E7CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD1002000ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x17FFFD7CULL ^ (2ULL << 32);
    return state ^ (state >> 29);
}

// FDE #12665 | PC: 0x4278ec..0x427908 (28 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x4278ec: D503245F  bti      c
//   0x4278f0: AA0003E8  mov      x8, x0
//   0x4278f4: F9400000  ldr      x0, [x0]
//   0x4278f8: F900011F  str      xzr, [x8]
//   0x4278fc: B4000040  cbz      x0, #0x427904
//   0x427900: 140021D5  b        #0x430054
uint64_t fde_func_12665_0x4278ec(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x004278ECULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003E8ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400000ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF900011FULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB4000040ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x140021D5ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD65F03C0ULL ^ (6ULL << 32);
    return state ^ (state >> 29);
}

// FDE #12675 | PC: 0x427c5c..0x427d5c (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x427c5c: D503233F  paciasp  
//   0x427c60: D10403FF  sub      sp, sp, #0x100
//   0x427c64: A90C7BFD  stp      x29, x30, [sp, #0xc0]
//   0x427c68: F9006BF7  str      x23, [sp, #0xd0]
//   0x427c6c: A90E57F6  stp      x22, x21, [sp, #0xe0]
//   0x427c70: A90F4FF4  stp      x20, x19, [sp, #0xf0]
uint64_t fde_func_12675_0x427c5c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00427C5CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10403FFULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90C7BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9006BF7ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90E57F6ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90F4FF4ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910303FDULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD53BD057ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #12684 | PC: 0x4285ec..0x428628 (60 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x4285ec: D503245F  bti      c
//   0x4285f0: B40001A0  cbz      x0, #0x428624
//   0x4285f4: D503233F  paciasp  
//   0x4285f8: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x4285fc: F9000BF3  str      x19, [sp, #0x10]
//   0x428600: 910003FD  mov      x29, sp
uint64_t fde_func_12684_0x4285ec(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x004285ECULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB40001A0ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE7BFDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF3ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9401800ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #12694 | PC: 0x428e64..0x428e90 (44 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x428e64: D503233F  paciasp  
//   0x428e68: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x428e6c: F9000BF3  str      x19, [sp, #0x10]
//   0x428e70: 910003FD  mov      x29, sp
//   0x428e74: AA0003F3  mov      x19, x0
//   0x428e78: 97FFFFEA  bl       #0x428e20
uint64_t fde_func_12694_0x428e64(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00428E64ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF3ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x97FFFFEAULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA1303E0ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400BF3ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #12703 | PC: 0x42a70c..0x42a794 (136 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x42a70c: D503233F  paciasp  
//   0x42a710: D10103FF  sub      sp, sp, #0x40
//   0x42a714: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x42a718: F9001BF3  str      x19, [sp, #0x30]
//   0x42a71c: 910083FD  add      x29, sp, #0x20
//   0x42a720: AA0003F3  mov      x19, x0
uint64_t fde_func_12703_0x42a70c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0042A70CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10103FFULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9027BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9001BF3ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910083FDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x97F7204AULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91066001ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #12713 | PC: 0x42af64..0x42af88 (36 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x42af64: D503233F  paciasp  
//   0x42af68: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x42af6c: 910003FD  mov      x29, sp
//   0x42af70: 9101C040  add      x0, x2, #0x70
//   0x42af74: 94057003  bl       #0x586f80
//   0x42af78: 52800020  mov      w0, #1
uint64_t fde_func_12713_0x42af64(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0042AF64ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BF7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9101C040ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x94057003ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x52800020ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA8C17BFDULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD50323BFULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #12722 | PC: 0x42b9e0..0x42ba2c (76 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x42b9e0: D503245F  bti      c
//   0x42b9e4: B4000220  cbz      x0, #0x42ba28
//   0x42b9e8: D503233F  paciasp  
//   0x42b9ec: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x42b9f0: F9000BF3  str      x19, [sp, #0x10]
//   0x42b9f4: 910003FD  mov      x29, sp
uint64_t fde_func_12722_0x42b9e0(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0042B9E0ULL);
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

// FDE #12732 | PC: 0x42c798..0x42c7c4 (44 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x42c798: D503245F  bti      c
//   0x42c79c: 39400028  ldrb     w8, [x1]
//   0x42c7a0: F9400429  ldr      x9, [x1, #8]
//   0x42c7a4: D341FD0A  lsr      x10, x8, #1
//   0x42c7a8: 7200011F  tst      w8, #1
//   0x42c7ac: 9A890148  csel     x8, x10, x9, eq
uint64_t fde_func_12732_0x42c798(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0042C798ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x39400028ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400429ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD341FD0AULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x7200011FULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9A890148ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB4000068ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x36000062ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #12741 | PC: 0x42ca28..0x42caa8 (128 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x42ca28: D503233F  paciasp  
//   0x42ca2c: D10143FF  sub      sp, sp, #0x50
//   0x42ca30: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x42ca34: F9001BF5  str      x21, [sp, #0x30]
//   0x42ca38: A9044FF4  stp      x20, x19, [sp, #0x40]
//   0x42ca3c: 910083FD  add      x29, sp, #0x20
uint64_t fde_func_12741_0x42ca28(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0042CA28ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10143FFULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9027BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9001BF5ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9044FF4ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910083FDULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x97F71782ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #12751 | PC: 0x42d258..0x42d358 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x42d258: D503233F  paciasp  
//   0x42d25c: D10143FF  sub      sp, sp, #0x50
//   0x42d260: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x42d264: A90357F6  stp      x22, x21, [sp, #0x30]
//   0x42d268: A9044FF4  stp      x20, x19, [sp, #0x40]
//   0x42d26c: 910083FD  add      x29, sp, #0x20
uint64_t fde_func_12751_0x42d258(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0042D258ULL);
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

// FDE #12760 | PC: 0x42e288..0x42e388 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x42e288: D503233F  paciasp  
//   0x42e28c: D102C3FF  sub      sp, sp, #0xb0
//   0x42e290: A9057BFD  stp      x29, x30, [sp, #0x50]
//   0x42e294: A9066FFC  stp      x28, x27, [sp, #0x60]
//   0x42e298: A90767FA  stp      x26, x25, [sp, #0x70]
//   0x42e29c: A9085FF8  stp      x24, x23, [sp, #0x80]
uint64_t fde_func_12760_0x42e288(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0042E288ULL);
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

// FDE #12770 | PC: 0x42e7c4..0x42e848 (132 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x42e7c4: D503233F  paciasp  
//   0x42e7c8: D100C3FF  sub      sp, sp, #0x30
//   0x42e7cc: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x42e7d0: F90013F3  str      x19, [sp, #0x20]
//   0x42e7d4: 910043FD  add      x29, sp, #0x10
//   0x42e7d8: AA0003F3  mov      x19, x0
uint64_t fde_func_12770_0x42e7c4(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0042E7C4ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD100C3FFULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF90013F3ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x52800700ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x3D8003E0ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #12779 | PC: 0x42ed08..0x42ed28 (32 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x42ed08: D503245F  bti      c
//   0x42ed0c: AA0003F0  mov      x16, x0
//   0x42ed10: 8B810440  add      x0, x2, x1, asr #1
//   0x42ed14: 36000061  tbz      w1, #0, #0x42ed20
//   0x42ed18: F9400008  ldr      x8, [x0]
//   0x42ed1c: F8706910  ldr      x16, [x8, x16]
uint64_t fde_func_12779_0x42ed08(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0042ED08ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F0ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x8B810440ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x36000061ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400008ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF8706910ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x2A0303E1ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD61F0200ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #12789 | PC: 0x42fa30..0x42fa60 (48 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x42fa30: D503245F  bti      c
//   0x42fa34: A942A809  ldp      x9, x10, [x0, #0x28]
//   0x42fa38: 2A0103E2  mov      w2, w1
//   0x42fa3c: AA0003E8  mov      x8, x0
//   0x42fa40: F9401010  ldr      x16, [x0, #0x20]
//   0x42fa44: 8B890540  add      x0, x10, x9, asr #1
uint64_t fde_func_12789_0x42fa30(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0042FA30ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA942A809ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x2A0103E2ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003E8ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9401010ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x8B890540ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x36000069ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400009ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #12799 | PC: 0x42fc24..0x42fd24 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x42fc24: D503233F  paciasp  
//   0x42fc28: D10143FF  sub      sp, sp, #0x50
//   0x42fc2c: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x42fc30: F9001BF5  str      x21, [sp, #0x30]
//   0x42fc34: A9044FF4  stp      x20, x19, [sp, #0x40]
//   0x42fc38: 910083FD  add      x29, sp, #0x20
uint64_t fde_func_12799_0x42fc24(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0042FC24ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10143FFULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9027BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9001BF5ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9044FF4ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910083FDULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F4ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9409400ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #12808 | PC: 0x430080..0x4300c4 (68 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x430080: D503233F  paciasp  
//   0x430084: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x430088: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x43008c: 910003FD  mov      x29, sp
//   0x430090: F9400414  ldr      x20, [x0, #8]
//   0x430094: AA0203F3  mov      x19, x2
uint64_t fde_func_12808_0x430080(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00430080ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9014FF4ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400414ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0203F3ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910A2280ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x94055BB9ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #12818 | PC: 0x430348..0x430358 (16 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x430348: D503245F  bti      c
//   0x43034c: F9400408  ldr      x8, [x0, #8]
//   0x430350: 91072100  add      x0, x8, #0x1c8
//   0x430354: 17FC92DE  b        #0x354ecc
uint64_t fde_func_12818_0x430348(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00430348ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400408ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91072100ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x17FC92DEULL ^ (3ULL << 32);
    return state ^ (state >> 29);
}

// FDE #12827 | PC: 0x430428..0x430438 (16 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x430428: D503245F  bti      c
//   0x43042c: F9400408  ldr      x8, [x0, #8]
//   0x430430: F9418100  ldr      x0, [x8, #0x300]
//   0x430434: D65F03C0  ret      
uint64_t fde_func_12827_0x430428(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00430428ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400408ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9418100ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD65F03C0ULL ^ (3ULL << 32);
    return state ^ (state >> 29);
}

// FDE #12837 | PC: 0x430644..0x430654 (16 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x430644: D503245F  bti      c
//   0x430648: F9400408  ldr      x8, [x0, #8]
//   0x43064c: F9411100  ldr      x0, [x8, #0x220]
//   0x430650: D65F03C0  ret      
uint64_t fde_func_12837_0x430644(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00430644ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400408ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9411100ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD65F03C0ULL ^ (3ULL << 32);
    return state ^ (state >> 29);
}

// FDE #12846 | PC: 0x4308b0..0x4308c0 (16 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x4308b0: D503245F  bti      c
//   0x4308b4: F9400401  ldr      x1, [x0, #8]
//   0x4308b8: AA0803E0  mov      x0, x8
//   0x4308bc: 17FFF2D4  b        #0x42d40c
uint64_t fde_func_12846_0x4308b0(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x004308B0ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400401ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0803E0ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x17FFF2D4ULL ^ (3ULL << 32);
    return state ^ (state >> 29);
}

// FDE #12856 | PC: 0x430bc0..0x430bd8 (24 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x430bc0: D503245F  bti      c
//   0x430bc4: F9400408  ldr      x8, [x0, #8]
//   0x430bc8: B941E908  ldr      w8, [x8, #0x1e8]
//   0x430bcc: 7100091F  cmp      w8, #2
//   0x430bd0: 1A9F07E0  cset     w0, ne
//   0x430bd4: D65F03C0  ret      
uint64_t fde_func_12856_0x430bc0(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00430BC0ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400408ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB941E908ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x7100091FULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x1A9F07E0ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD65F03C0ULL ^ (5ULL << 32);
    return state ^ (state >> 29);
}

// FDE #12865 | PC: 0x430d78..0x430dc0 (72 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x430d78: D503233F  paciasp  
//   0x430d7c: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x430d80: F9000BF3  str      x19, [sp, #0x10]
//   0x430d84: 910003FD  mov      x29, sp
//   0x430d88: F9400413  ldr      x19, [x0, #8]
//   0x430d8c: B4000173  cbz      x19, #0x430db8
uint64_t fde_func_12865_0x430d78(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00430D78ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF3ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400413ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB4000173ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9409E68ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB4000088ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #12875 | PC: 0x4310b8..0x4310dc (36 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x4310b8: D503233F  paciasp  
//   0x4310bc: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x4310c0: 910003FD  mov      x29, sp
//   0x4310c4: 91002000  add      x0, x0, #8
//   0x4310c8: 97F6900A  bl       #0x1d50f0
//   0x4310cc: 2A1F03E0  mov      w0, wzr
uint64_t fde_func_12875_0x4310b8(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x004310B8ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BF7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91002000ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x97F6900AULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x2A1F03E0ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA8C17BFDULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD50323BFULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #12884 | PC: 0x431790..0x4317e8 (88 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x431790: D503233F  paciasp  
//   0x431794: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x431798: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x43179c: 910003FD  mov      x29, sp
//   0x4317a0: AA0003F3  mov      x19, x0
//   0x4317a4: F9401800  ldr      x0, [x0, #0x30]
uint64_t fde_func_12884_0x431790(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00431790ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9014FF4ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9401800ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x2A0103F4ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9001A7FULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #12894 | PC: 0x431c9c..0x431d04 (104 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x431c9c: D503233F  paciasp  
//   0x431ca0: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x431ca4: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x431ca8: 910003FD  mov      x29, sp
//   0x431cac: F9400013  ldr      x19, [x0]
//   0x431cb0: F9000001  str      x1, [x0]
uint64_t fde_func_12894_0x431c9c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00431C9CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9014FF4ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400013ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000001ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB4000213ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA1303F4ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #12903 | PC: 0x432364..0x4323b4 (80 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x432364: D503233F  paciasp  
//   0x432368: A9BD7BFD  stp      x29, x30, [sp, #-0x30]!
//   0x43236c: F9000BF5  str      x21, [sp, #0x10]
//   0x432370: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x432374: 910003FD  mov      x29, sp
//   0x432378: AA0103F3  mov      x19, x1
uint64_t fde_func_12903_0x432364(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00432364ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BD7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF5ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9024FF4ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0103F3ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F4ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9401415ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #12913 | PC: 0x432bb0..0x432c70 (192 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x432bb0: D503233F  paciasp  
//   0x432bb4: A9BC7BFD  stp      x29, x30, [sp, #-0x40]!
//   0x432bb8: F9000BF7  str      x23, [sp, #0x10]
//   0x432bbc: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x432bc0: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x432bc4: 910003FD  mov      x29, sp
uint64_t fde_func_12913_0x432bb0(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00432BB0ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BC7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF7ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90257F6ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9034FF4ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91006017ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91004034ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #12922 | PC: 0x433074..0x433114 (160 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x433074: D503233F  paciasp  
//   0x433078: D10143FF  sub      sp, sp, #0x50
//   0x43307c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x433080: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x433084: A90357F6  stp      x22, x21, [sp, #0x30]
//   0x433088: A9044FF4  stp      x20, x19, [sp, #0x40]
uint64_t fde_func_12922_0x433074(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00433074ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10143FFULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9025FF8ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90357F6ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9044FF4ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0103F8ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #12932 | PC: 0x433b10..0x433b80 (112 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x433b10: D503233F  paciasp  
//   0x433b14: D10143FF  sub      sp, sp, #0x50
//   0x433b18: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x433b1c: F9001BF5  str      x21, [sp, #0x30]
//   0x433b20: A9044FF4  stp      x20, x19, [sp, #0x40]
//   0x433b24: 910083FD  add      x29, sp, #0x20
uint64_t fde_func_12932_0x433b10(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00433B10ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10143FFULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9027BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9001BF5ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9044FF4ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910083FDULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F4ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x52800B00ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #12941 | PC: 0x434ddc..0x434e18 (60 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x434ddc: D503233F  paciasp  
//   0x434de0: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x434de4: F9000BF3  str      x19, [sp, #0x10]
//   0x434de8: 910003FD  mov      x29, sp
//   0x434dec: AA0003F3  mov      x19, x0
//   0x434df0: 9100A000  add      x0, x0, #0x28
uint64_t fde_func_12941_0x434ddc(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00434DDCULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF3ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9100A000ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD0000B88ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91308108ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #12951 | PC: 0x435188..0x4351cc (68 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x435188: D503233F  paciasp  
//   0x43518c: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x435190: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x435194: 910003FD  mov      x29, sp
//   0x435198: AA0003F4  mov      x20, x0
//   0x43519c: B0000B88  adrp     x8, #0x5a6000
uint64_t fde_func_12951_0x435188(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00435188ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9014FF4ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F4ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB0000B88ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9132C108ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #12960 | PC: 0x435480..0x4354ac (44 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x435480: D503233F  paciasp  
//   0x435484: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x435488: F9000BF3  str      x19, [sp, #0x10]
//   0x43548c: 910003FD  mov      x29, sp
//   0x435490: AA0003F3  mov      x19, x0
//   0x435494: 97FFFFD4  bl       #0x4353e4
uint64_t fde_func_12960_0x435480(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00435480ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF3ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x97FFFFD4ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA1303E0ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400BF3ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #12970 | PC: 0x435ef8..0x435fa4 (172 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x435ef8: D503233F  paciasp  
//   0x435efc: A9BC7BFD  stp      x29, x30, [sp, #-0x40]!
//   0x435f00: F9000BF7  str      x23, [sp, #0x10]
//   0x435f04: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x435f08: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x435f0c: 910003FD  mov      x29, sp
uint64_t fde_func_12970_0x435ef8(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00435EF8ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BC7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF7ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90257F6ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9034FF4ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F5ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #12979 | PC: 0x43653c..0x4365ac (112 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x43653c: D503233F  paciasp  
//   0x436540: D10103FF  sub      sp, sp, #0x40
//   0x436544: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x436548: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x43654c: 910083FD  add      x29, sp, #0x20
//   0x436550: 39400028  ldrb     w8, [x1]
uint64_t fde_func_12979_0x43653c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0043653CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10103FFULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9027BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9034FF4ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910083FDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x39400028ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400429ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD341FD0AULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #12989 | PC: 0x436c2c..0x436d2c (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x436c2c: D503233F  paciasp  
//   0x436c30: D10383FF  sub      sp, sp, #0xe0
//   0x436c34: A90B7BFD  stp      x29, x30, [sp, #0xb0]
//   0x436c38: A90C57F6  stp      x22, x21, [sp, #0xc0]
//   0x436c3c: A90D4FF4  stp      x20, x19, [sp, #0xd0]
//   0x436c40: 9102C3FD  add      x29, sp, #0xb0
uint64_t fde_func_12989_0x436c2c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00436C2CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10383FFULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90B7BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90C57F6ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90D4FF4ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9102C3FDULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F4ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003E0ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #12998 | PC: 0x437490..0x4374a0 (16 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x437490: D503245F  bti      c
//   0x437494: F9400C08  ldr      x8, [x0, #0x18]
//   0x437498: D1002100  sub      x0, x8, #8
//   0x43749c: 140008FB  b        #0x439888
uint64_t fde_func_12998_0x437490(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00437490ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400C08ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD1002100ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x140008FBULL ^ (3ULL << 32);
    return state ^ (state >> 29);
}

// FDE #13008 | PC: 0x437d30..0x437d3c (12 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x437d30: D503245F  bti      c
//   0x437d34: D1036000  sub      x0, x0, #0xd8
//   0x437d38: 17FFFE33  b        #0x437604
uint64_t fde_func_13008_0x437d30(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00437D30ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD1036000ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x17FFFE33ULL ^ (2ULL << 32);
    return state ^ (state >> 29);
}

// FDE #13017 | PC: 0x4387a8..0x4387d8 (48 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x4387a8: D503233F  paciasp  
//   0x4387ac: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x4387b0: F9000BF3  str      x19, [sp, #0x10]
//   0x4387b4: 910003FD  mov      x29, sp
//   0x4387b8: AA0003F3  mov      x19, x0
//   0x4387bc: 9100E000  add      x0, x0, #0x38
uint64_t fde_func_13017_0x4387a8(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x004387A8ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF3ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9100E000ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x940539B4ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91008260ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #13027 | PC: 0x4397e0..0x43985c (124 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x4397e0: D503233F  paciasp  
//   0x4397e4: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x4397e8: F9000BF3  str      x19, [sp, #0x10]
//   0x4397ec: 910003FD  mov      x29, sp
//   0x4397f0: AA0003F3  mov      x19, x0
//   0x4397f4: B0000B68  adrp     x8, #0x5a6000
uint64_t fde_func_13027_0x4397e0(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x004397E0ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF3ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB0000B68ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x913B8108ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB0000B69ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #13036 | PC: 0x439e9c..0x439f9c (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x439e9c: D503233F  paciasp  
//   0x439ea0: D102C3FF  sub      sp, sp, #0xb0
//   0x439ea4: A9087BFD  stp      x29, x30, [sp, #0x80]
//   0x439ea8: A90957F6  stp      x22, x21, [sp, #0x90]
//   0x439eac: A90A4FF4  stp      x20, x19, [sp, #0xa0]
//   0x439eb0: 910203FD  add      x29, sp, #0x80
uint64_t fde_func_13036_0x439e9c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00439E9CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD102C3FFULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9087BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90957F6ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90A4FF4ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910203FDULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0203F4ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x39404028ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #13046 | PC: 0x43ac64..0x43ac70 (12 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x43ac64: D503245F  bti      c
//   0x43ac68: D1092000  sub      x0, x0, #0x248
//   0x43ac6c: 17FFFEC7  b        #0x43a788
uint64_t fde_func_13046_0x43ac64(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0043AC64ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD1092000ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x17FFFEC7ULL ^ (2ULL << 32);
    return state ^ (state >> 29);
}

// FDE #13055 | PC: 0x43bc5c..0x43bc68 (12 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x43bc5c: D503245F  bti      c
//   0x43bc60: D1006000  sub      x0, x0, #0x18
//   0x43bc64: 17FFFC1E  b        #0x43acdc
uint64_t fde_func_13055_0x43bc5c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0043BC5CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD1006000ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x17FFFC1EULL ^ (2ULL << 32);
    return state ^ (state >> 29);
}

// FDE #13065 | PC: 0x43c9ec..0x43c9f8 (12 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x43c9ec: D503245F  bti      c
//   0x43c9f0: D1092000  sub      x0, x0, #0x248
//   0x43c9f4: 17FFFCA7  b        #0x43bc90
uint64_t fde_func_13065_0x43c9ec(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0043C9ECULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD1092000ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x17FFFCA7ULL ^ (2ULL << 32);
    return state ^ (state >> 29);
}

// FDE #13074 | PC: 0x43d5a4..0x43d5c4 (32 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x43d5a4: D503245F  bti      c
//   0x43d5a8: F9400408  ldr      x8, [x0, #8]
//   0x43d5ac: 5141F029  sub      w9, w1, #0x7c, lsl #12
//   0x43d5b0: 51018129  sub      w9, w9, #0x60
//   0x43d5b4: 7100003F  cmp      w1, #0
//   0x43d5b8: 1A8903E1  csel     w1, wzr, w9, eq
uint64_t fde_func_13074_0x43d5a4(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0043D5A4ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400408ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x5141F029ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x51018129ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x7100003FULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x1A8903E1ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD1092100ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x17FFF566ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #13084 | PC: 0x43d6cc..0x43d6f8 (44 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x43d6cc: D503233F  paciasp  
//   0x43d6d0: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x43d6d4: F9000BF3  str      x19, [sp, #0x10]
//   0x43d6d8: 910003FD  mov      x29, sp
//   0x43d6dc: AA0003F3  mov      x19, x0
//   0x43d6e0: 97FFFFE5  bl       #0x43d674
uint64_t fde_func_13084_0x43d6cc(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0043D6CCULL);
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

// FDE #13094 | PC: 0x43e0e8..0x43e0f4 (12 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x43e0e8: D503245F  bti      c
//   0x43e0ec: 2A0203E1  mov      w1, w2
//   0x43e0f0: 17FFFD5D  b        #0x43d664
uint64_t fde_func_13094_0x43e0e8(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0043E0E8ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x2A0203E1ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x17FFFD5DULL ^ (2ULL << 32);
    return state ^ (state >> 29);
}

// FDE #13103 | PC: 0x43e3d0..0x43e4d0 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x43e3d0: D503233F  paciasp  
//   0x43e3d4: A9BB7BFD  stp      x29, x30, [sp, #-0x50]!
//   0x43e3d8: F9000BFC  str      x28, [sp, #0x10]
//   0x43e3dc: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x43e3e0: A90357F6  stp      x22, x21, [sp, #0x30]
//   0x43e3e4: A9044FF4  stp      x20, x19, [sp, #0x40]
uint64_t fde_func_13103_0x43e3d0(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0043E3D0ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BB7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BFCULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9025FF8ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90357F6ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9044FF4ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD116C3FFULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #13113 | PC: 0x43f068..0x43f138 (208 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x43f068: D503233F  paciasp  
//   0x43f06c: D101C3FF  sub      sp, sp, #0x70
//   0x43f070: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x43f074: A9026FFC  stp      x28, x27, [sp, #0x20]
//   0x43f078: A90367FA  stp      x26, x25, [sp, #0x30]
//   0x43f07c: A9045FF8  stp      x24, x23, [sp, #0x40]
uint64_t fde_func_13113_0x43f068(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0043F068ULL);
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

// FDE #13122 | PC: 0x43f978..0x43f9a0 (40 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x43f978: D503245F  bti      c
//   0x43f97c: B4000100  cbz      x0, #0x43f99c
//   0x43f980: 91002008  add      x8, x0, #8
//   0x43f984: 885FFD09  ldaxr    w9, [x8]
//   0x43f988: 71000529  subs     w9, w9, #1
//   0x43f98c: 880AFD09  stlxr    w10, w9, [x8]
uint64_t fde_func_13122_0x43f978(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0043F978ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB4000100ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91002008ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x885FFD09ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x71000529ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x880AFD09ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x35FFFFAAULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x54000041ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #13132 | PC: 0x4401e0..0x4402e0 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x4401e0: D503233F  paciasp  
//   0x4401e4: A9BB7BFD  stp      x29, x30, [sp, #-0x50]!
//   0x4401e8: F9000BFC  str      x28, [sp, #0x10]
//   0x4401ec: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x4401f0: A90357F6  stp      x22, x21, [sp, #0x30]
//   0x4401f4: A9044FF4  stp      x20, x19, [sp, #0x40]
uint64_t fde_func_13132_0x4401e0(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x004401E0ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BB7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BFCULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9025FF8ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90357F6ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9044FF4ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10783FFULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #13141 | PC: 0x440f4c..0x440f98 (76 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x440f4c: D503233F  paciasp  
//   0x440f50: D102C3FF  sub      sp, sp, #0xb0
//   0x440f54: A9097BFD  stp      x29, x30, [sp, #0x90]
//   0x440f58: F90053F3  str      x19, [sp, #0xa0]
//   0x440f5c: 910243FD  add      x29, sp, #0x90
//   0x440f60: AA0003F3  mov      x19, x0
uint64_t fde_func_13141_0x440f4c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00440F4CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD102C3FFULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9097BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF90053F3ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910243FDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003E0ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x2A1F03E2ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #13151 | PC: 0x4419c4..0x441ac4 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x4419c4: D503233F  paciasp  
//   0x4419c8: A9BA7BFD  stp      x29, x30, [sp, #-0x60]!
//   0x4419cc: A9016FFC  stp      x28, x27, [sp, #0x10]
//   0x4419d0: A90267FA  stp      x26, x25, [sp, #0x20]
//   0x4419d4: A9035FF8  stp      x24, x23, [sp, #0x30]
//   0x4419d8: A90457F6  stp      x22, x21, [sp, #0x40]
uint64_t fde_func_13151_0x4419c4(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x004419C4ULL);
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

// FDE #13160 | PC: 0x4425a0..0x4426a0 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x4425a0: D503233F  paciasp  
//   0x4425a4: D10183FF  sub      sp, sp, #0x60
//   0x4425a8: A9037BFD  stp      x29, x30, [sp, #0x30]
//   0x4425ac: F90023F5  str      x21, [sp, #0x40]
//   0x4425b0: A9054FF4  stp      x20, x19, [sp, #0x50]
//   0x4425b4: 9100C3FD  add      x29, sp, #0x30
uint64_t fde_func_13160_0x4425a0(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x004425A0ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10183FFULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9037BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF90023F5ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9054FF4ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9100C3FDULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400428ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #13170 | PC: 0x442994..0x4429b0 (28 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x442994: D503245F  bti      c
//   0x442998: B0000B28  adrp     x8, #0x5a7000
//   0x44299c: 91114108  add      x8, x8, #0x450
//   0x4429a0: F9000028  str      x8, [x1]
//   0x4429a4: F9400408  ldr      x8, [x0, #8]
//   0x4429a8: F9000428  str      x8, [x1, #8]
uint64_t fde_func_13170_0x442994(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00442994ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB0000B28ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91114108ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000028ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400408ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000428ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD65F03C0ULL ^ (6ULL << 32);
    return state ^ (state >> 29);
}

// FDE #13179 | PC: 0x443530..0x4435b4 (132 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x443530: D503233F  paciasp  
//   0x443534: D10143FF  sub      sp, sp, #0x50
//   0x443538: A9037BFD  stp      x29, x30, [sp, #0x30]
//   0x44353c: F90023F3  str      x19, [sp, #0x40]
//   0x443540: 9100C3FD  add      x29, sp, #0x30
//   0x443544: AA0103F3  mov      x19, x1
uint64_t fde_func_13179_0x443530(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00443530ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10143FFULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9037BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF90023F3ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9100C3FDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0103F3ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91042001ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910023E0ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #13189 | PC: 0x4444cc..0x444504 (56 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x4444cc: D503245F  bti      c
//   0x4444d0: A942A009  ldp      x9, x8, [x0, #0x28]
//   0x4444d4: 2A0103E5  mov      w5, w1
//   0x4444d8: F9401010  ldr      x16, [x0, #0x20]
//   0x4444dc: 8B890508  add      x8, x8, x9, asr #1
//   0x4444e0: 36000069  tbz      w9, #0, #0x4444ec
uint64_t fde_func_13189_0x4444cc(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x004444CCULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA942A009ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x2A0103E5ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9401010ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x8B890508ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x36000069ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400109ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF8706930ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #13198 | PC: 0x445190..0x4451e0 (80 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x445190: D503233F  paciasp  
//   0x445194: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x445198: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x44519c: 910003FD  mov      x29, sp
//   0x4451a0: AA0003F4  mov      x20, x0
//   0x4451a4: 52800300  mov      w0, #0x18
uint64_t fde_func_13198_0x445190(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00445190ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9014FF4ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F4ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x52800300ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0103F3ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x97FA5CF2ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #13208 | PC: 0x445994..0x4459c4 (48 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x445994: D503233F  paciasp  
//   0x445998: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x44599c: F9000BF3  str      x19, [sp, #0x10]
//   0x4459a0: 910003FD  mov      x29, sp
//   0x4459a4: AA0003F3  mov      x19, x0
//   0x4459a8: 91006000  add      x0, x0, #0x18
uint64_t fde_func_13208_0x445994(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00445994ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF3ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91006000ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x94000006ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA1303E0ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #13217 | PC: 0x446108..0x44617c (116 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x446108: D503233F  paciasp  
//   0x44610c: A9BD7BFD  stp      x29, x30, [sp, #-0x30]!
//   0x446110: F9000BF5  str      x21, [sp, #0x10]
//   0x446114: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x446118: 910003FD  mov      x29, sp
//   0x44611c: AA0003F5  mov      x21, x0
uint64_t fde_func_13217_0x446108(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00446108ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BD7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF5ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9024FF4ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F5ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0103F4ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #13227 | PC: 0x446850..0x446950 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x446850: D503233F  paciasp  
//   0x446854: D104C3FF  sub      sp, sp, #0x130
//   0x446858: A90F7BFD  stp      x29, x30, [sp, #0xf0]
//   0x44685c: F90083FC  str      x28, [sp, #0x100]
//   0x446860: A91157F6  stp      x22, x21, [sp, #0x110]
//   0x446864: A9124FF4  stp      x20, x19, [sp, #0x120]
uint64_t fde_func_13227_0x446850(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00446850ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD104C3FFULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90F7BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF90083FCULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA91157F6ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9124FF4ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9103C3FDULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F6ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #13236 | PC: 0x4489c0..0x448a1c (92 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x4489c0: D503233F  paciasp  
//   0x4489c4: D10103FF  sub      sp, sp, #0x40
//   0x4489c8: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x4489cc: F9001BF3  str      x19, [sp, #0x30]
//   0x4489d0: 910083FD  add      x29, sp, #0x20
//   0x4489d4: D101E001  sub      x1, x0, #0x78
uint64_t fde_func_13236_0x4489c0(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x004489C0ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10103FFULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9027BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9001BF3ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910083FDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD101E001ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910023E0ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x97F88CAEULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #13246 | PC: 0x44be60..0x44bf58 (248 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x44be60: D503233F  paciasp  
//   0x44be64: D10343FF  sub      sp, sp, #0xd0
//   0x44be68: A9077BFD  stp      x29, x30, [sp, #0x70]
//   0x44be6c: A9086FFC  stp      x28, x27, [sp, #0x80]
//   0x44be70: A90967FA  stp      x26, x25, [sp, #0x90]
//   0x44be74: A90A5FF8  stp      x24, x23, [sp, #0xa0]
uint64_t fde_func_13246_0x44be60(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0044BE60ULL);
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

// FDE #13255 | PC: 0x44c924..0x44c9dc (184 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x44c924: D503233F  paciasp  
//   0x44c928: A9BD7BFD  stp      x29, x30, [sp, #-0x30]!
//   0x44c92c: A90157FC  stp      x28, x21, [sp, #0x10]
//   0x44c930: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x44c934: 910003FD  mov      x29, sp
//   0x44c938: D10943FF  sub      sp, sp, #0x250
uint64_t fde_func_13255_0x44c924(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0044C924ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BD7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90157FCULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9024FF4ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10943FFULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD53BD054ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003E0ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #13265 | PC: 0x44d048..0x44d05c (20 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x44d048: D503245F  bti      c
//   0x44d04c: D0FFE169  adrp     x9, #0x7b000
//   0x44d050: FD428D20  ldr      d0, [x9, #0x518]
//   0x44d054: FD000100  str      d0, [x8]
//   0x44d058: D65F03C0  ret      
uint64_t fde_func_13265_0x44d048(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0044D048ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD0FFE169ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xFD428D20ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xFD000100ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD65F03C0ULL ^ (4ULL << 32);
    return state ^ (state >> 29);
}

// FDE #13274 | PC: 0x44d95c..0x44d970 (20 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x44d95c: D503245F  bti      c
//   0x44d960: F9409000  ldr      x0, [x0, #0x120]
//   0x44d964: F9400008  ldr      x8, [x0]
//   0x44d968: F9401D10  ldr      x16, [x8, #0x38]
//   0x44d96c: D61F0200  br       x16
uint64_t fde_func_13274_0x44d95c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0044D95CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9409000ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400008ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9401D10ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD61F0200ULL ^ (4ULL << 32);
    return state ^ (state >> 29);
}

// FDE #13284 | PC: 0x44ec24..0x44ecd8 (180 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x44ec24: D503233F  paciasp  
//   0x44ec28: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x44ec2c: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x44ec30: 910003FD  mov      x29, sp
//   0x44ec34: AA0003F3  mov      x19, x0
//   0x44ec38: F9400000  ldr      x0, [x0]
uint64_t fde_func_13284_0x44ec24(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0044EC24ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9014FF4ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400000ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0103F4ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB40000A0ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #13293 | PC: 0x44f154..0x44f1a0 (76 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x44f154: D503233F  paciasp  
//   0x44f158: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x44f15c: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x44f160: 910003FD  mov      x29, sp
//   0x44f164: F9400828  ldr      x8, [x1, #0x10]
//   0x44f168: AA0003F4  mov      x20, x0
uint64_t fde_func_13293_0x44f154(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0044F154ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9014FF4ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400828ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F4ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x3DC00020ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0103F3ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #13303 | PC: 0x44f794..0x44f894 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x44f794: D503233F  paciasp  
//   0x44f798: D10203FF  sub      sp, sp, #0x80
//   0x44f79c: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x44f7a0: F9001BFB  str      x27, [sp, #0x30]
//   0x44f7a4: A90467FA  stp      x26, x25, [sp, #0x40]
//   0x44f7a8: A9055FF8  stp      x24, x23, [sp, #0x50]
uint64_t fde_func_13303_0x44f794(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0044F794ULL);
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

// FDE #13312 | PC: 0x451d88..0x451dc0 (56 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x451d88: D503233F  paciasp  
//   0x451d8c: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x451d90: F9000BF3  str      x19, [sp, #0x10]
//   0x451d94: 910003FD  mov      x29, sp
//   0x451d98: D0000AA8  adrp     x8, #0x5a7000
//   0x451d9c: 9121E108  add      x8, x8, #0x878
uint64_t fde_func_13312_0x451d88(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00451D88ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF3ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD0000AA8ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9121E108ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF8028408ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #13322 | PC: 0x4529d4..0x452a64 (144 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x4529d4: D503233F  paciasp  
//   0x4529d8: A9BD7BFD  stp      x29, x30, [sp, #-0x30]!
//   0x4529dc: F9000BF5  str      x21, [sp, #0x10]
//   0x4529e0: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x4529e4: 910003FD  mov      x29, sp
//   0x4529e8: F9400808  ldr      x8, [x0, #0x10]
uint64_t fde_func_13322_0x4529d4(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x004529D4ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BD7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF5ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9024FF4ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400808ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB4000328ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9405008ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #13331 | PC: 0x452d04..0x452d10 (12 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x452d04: D503245F  bti      c
//   0x452d08: 528000E0  mov      w0, #7
//   0x452d0c: D65F03C0  ret      
uint64_t fde_func_13331_0x452d04(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00452D04ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x528000E0ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD65F03C0ULL ^ (2ULL << 32);
    return state ^ (state >> 29);
}

// FDE #13341 | PC: 0x453148..0x453248 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x453148: D503233F  paciasp  
//   0x45314c: D105C3FF  sub      sp, sp, #0x170
//   0x453150: A9137BFD  stp      x29, x30, [sp, #0x130]
//   0x453154: A9145FFC  stp      x28, x23, [sp, #0x140]
//   0x453158: A91557F6  stp      x22, x21, [sp, #0x150]
//   0x45315c: A9164FF4  stp      x20, x19, [sp, #0x160]
uint64_t fde_func_13341_0x453148(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00453148ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD105C3FFULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9137BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9145FFCULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA91557F6ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9164FF4ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9104C3FDULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #13350 | PC: 0x453a84..0x453acc (72 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x453a84: D503233F  paciasp  
//   0x453a88: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x453a8c: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x453a90: 910003FD  mov      x29, sp
//   0x453a94: AA0003F3  mov      x19, x0
//   0x453a98: AA0003F4  mov      x20, x0
uint64_t fde_func_13350_0x453a84(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00453A84ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9014FF4ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F4ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91010000ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x90000AA8ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #13360 | PC: 0x453e38..0x453f04 (204 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x453e38: D503233F  paciasp  
//   0x453e3c: D10343FF  sub      sp, sp, #0xd0
//   0x453e40: A90A7BFD  stp      x29, x30, [sp, #0xa0]
//   0x453e44: A90B57F6  stp      x22, x21, [sp, #0xb0]
//   0x453e48: A90C4FF4  stp      x20, x19, [sp, #0xc0]
//   0x453e4c: 910283FD  add      x29, sp, #0xa0
uint64_t fde_func_13360_0x453e38(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00453E38ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10343FFULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90A7BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90B57F6ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90C4FF4ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910283FDULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9100A015ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043E0ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #13369 | PC: 0x45425c..0x454268 (12 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x45425c: D503245F  bti      c
//   0x454260: D1002000  sub      x0, x0, #8
//   0x454264: 17FFFFE3  b        #0x4541f0
uint64_t fde_func_13369_0x45425c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0045425CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD1002000ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x17FFFFE3ULL ^ (2ULL << 32);
    return state ^ (state >> 29);
}

// FDE #13379 | PC: 0x454de0..0x454e60 (128 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x454de0: D503233F  paciasp  
//   0x454de4: A9BD7BFD  stp      x29, x30, [sp, #-0x30]!
//   0x454de8: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x454dec: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x454df0: 910003FD  mov      x29, sp
//   0x454df4: 91002015  add      x21, x0, #8
uint64_t fde_func_13379_0x454de0(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00454DE0ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BD7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90157F6ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9024FF4ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91002015ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0103F4ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA1503E8ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #13389 | PC: 0x455258..0x455358 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x455258: D503233F  paciasp  
//   0x45525c: D10183FF  sub      sp, sp, #0x60
//   0x455260: A9037BFD  stp      x29, x30, [sp, #0x30]
//   0x455264: A90457F6  stp      x22, x21, [sp, #0x40]
//   0x455268: A9054FF4  stp      x20, x19, [sp, #0x50]
//   0x45526c: 9100C3FD  add      x29, sp, #0x30
uint64_t fde_func_13389_0x455258(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00455258ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10183FFULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9037BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90457F6ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9054FF4ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9100C3FDULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x2A1F03F4ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #13398 | PC: 0x45569c..0x45579c (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x45569c: D503233F  paciasp  
//   0x4556a0: D10703FF  sub      sp, sp, #0x1c0
//   0x4556a4: A9167BFD  stp      x29, x30, [sp, #0x160]
//   0x4556a8: A9176FFC  stp      x28, x27, [sp, #0x170]
//   0x4556ac: A91867FA  stp      x26, x25, [sp, #0x180]
//   0x4556b0: A9195FF8  stp      x24, x23, [sp, #0x190]
uint64_t fde_func_13398_0x45569c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0045569CULL);
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

// FDE #13408 | PC: 0x456a7c..0x456b2c (176 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x456a7c: D503233F  paciasp  
//   0x456a80: D10143FF  sub      sp, sp, #0x50
//   0x456a84: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x456a88: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x456a8c: A90357F6  stp      x22, x21, [sp, #0x30]
//   0x456a90: A9044FF4  stp      x20, x19, [sp, #0x40]
uint64_t fde_func_13408_0x456a7c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00456A7CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10143FFULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9025FF8ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90357F6ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9044FF4ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9100C018ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #13417 | PC: 0x457378..0x4573dc (100 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x457378: D503233F  paciasp  
//   0x45737c: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x457380: F9000BF3  str      x19, [sp, #0x10]
//   0x457384: 910003FD  mov      x29, sp
//   0x457388: AA0003F3  mov      x19, x0
//   0x45738c: 97FA649E  bl       #0x2f0604
uint64_t fde_func_13417_0x457378(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00457378ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF3ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x97FA649EULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x360000A0ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400BF3ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #13427 | PC: 0x4577f8..0x457804 (12 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x4577f8: D503245F  bti      c
//   0x4577fc: D1012000  sub      x0, x0, #0x48
//   0x457800: 17FFFF3D  b        #0x4574f4
uint64_t fde_func_13427_0x4577f8(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x004577F8ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD1012000ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x17FFFF3DULL ^ (2ULL << 32);
    return state ^ (state >> 29);
}

// FDE #13436 | PC: 0x457ec0..0x457eec (44 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x457ec0: D503233F  paciasp  
//   0x457ec4: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x457ec8: F9000BF3  str      x19, [sp, #0x10]
//   0x457ecc: 910003FD  mov      x29, sp
//   0x457ed0: AA0003F3  mov      x19, x0
//   0x457ed4: 97FFFFEC  bl       #0x457e84
uint64_t fde_func_13436_0x457ec0(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00457EC0ULL);
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

// FDE #13446 | PC: 0x458d60..0x458d80 (32 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x458d60: D503245F  bti      c
//   0x458d64: F9400008  ldr      x8, [x0]
//   0x458d68: F9400029  ldr      x9, [x1]
//   0x458d6c: B940CD08  ldr      w8, [x8, #0xcc]
//   0x458d70: B940CD29  ldr      w9, [x9, #0xcc]
//   0x458d74: 6B09011F  cmp      w8, w9
uint64_t fde_func_13446_0x458d60(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00458D60ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400008ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400029ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB940CD08ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB940CD29ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x6B09011FULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x1A9F27E0ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD65F03C0ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #13455 | PC: 0x459ab4..0x459ac0 (12 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x459ab4: D503245F  bti      c
//   0x459ab8: 2A1F03E2  mov      w2, wzr
//   0x459abc: 17FFFFC3  b        #0x4599c8
uint64_t fde_func_13455_0x459ab4(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00459AB4ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x2A1F03E2ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x17FFFFC3ULL ^ (2ULL << 32);
    return state ^ (state >> 29);
}

// FDE #13465 | PC: 0x45a3b8..0x45a428 (112 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x45a3b8: D503233F  paciasp  
//   0x45a3bc: A9BD7BFD  stp      x29, x30, [sp, #-0x30]!
//   0x45a3c0: F9000BF5  str      x21, [sp, #0x10]
//   0x45a3c4: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x45a3c8: 910003FD  mov      x29, sp
//   0x45a3cc: F9400008  ldr      x8, [x0]
uint64_t fde_func_13465_0x45a3b8(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0045A3B8ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BD7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF5ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9024FF4ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400008ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB4000228ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x39400028ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #13474 | PC: 0x45a6c0..0x45a71c (92 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x45a6c0: D503233F  paciasp  
//   0x45a6c4: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x45a6c8: 910003FD  mov      x29, sp
//   0x45a6cc: 940003BB  bl       #0x45b5b8
//   0x45a6d0: 3100041F  cmn      w0, #1
//   0x45a6d4: 540001E0  b.eq     #0x45a710
uint64_t fde_func_13474_0x45a6c0(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0045A6C0ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BF7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x940003BBULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x3100041FULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x540001E0ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF0000AE8ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x912DA108ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #13484 | PC: 0x45ada8..0x45aea8 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x45ada8: D503233F  paciasp  
//   0x45adac: D10143FF  sub      sp, sp, #0x50
//   0x45adb0: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x45adb4: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x45adb8: A90357F6  stp      x22, x21, [sp, #0x30]
//   0x45adbc: A9044FF4  stp      x20, x19, [sp, #0x40]
uint64_t fde_func_13484_0x45ada8(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0045ADA8ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10143FFULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9025FF8ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90357F6ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9044FF4ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB9405028ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #13493 | PC: 0x45b56c..0x45b5b8 (76 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x45b56c: D503233F  paciasp  
//   0x45b570: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x45b574: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x45b578: 910003FD  mov      x29, sp
//   0x45b57c: AA0103F3  mov      x19, x1
//   0x45b580: 2A0203E1  mov      w1, w2
uint64_t fde_func_13493_0x45b56c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0045B56CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9014FF4ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0103F3ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x2A0203E1ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F4ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x97FFFFA9ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #13503 | PC: 0x45c078..0x45c0b0 (56 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x45c078: D503233F  paciasp  
//   0x45c07c: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x45c080: F9000BF3  str      x19, [sp, #0x10]
//   0x45c084: 910003FD  mov      x29, sp
//   0x45c088: AA0003F3  mov      x19, x0
//   0x45c08c: 91004000  add      x0, x0, #0x10
uint64_t fde_func_13503_0x45c078(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0045C078ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF3ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91004000ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x97F5F151ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF0000A48ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #13512 | PC: 0x45c614..0x45c61c (8 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x45c614: D503245F  bti      c
//   0x45c618: 17FFFEB1  b        #0x45c0dc
uint64_t fde_func_13512_0x45c614(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0045C614ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x17FFFEB1ULL ^ (1ULL << 32);
    return state ^ (state >> 29);
}

// FDE #13522 | PC: 0x45ca00..0x45cab8 (184 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x45ca00: D503233F  paciasp  
//   0x45ca04: A9BD7BFD  stp      x29, x30, [sp, #-0x30]!
//   0x45ca08: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x45ca0c: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x45ca10: 910003FD  mov      x29, sp
//   0x45ca14: F9400013  ldr      x19, [x0]
uint64_t fde_func_13522_0x45ca00(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0045CA00ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BD7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90157F6ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9024FF4ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400013ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000001ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB4000453ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #13531 | PC: 0x45ce14..0x45ce7c (104 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x45ce14: D503233F  paciasp  
//   0x45ce18: A9BD7BFD  stp      x29, x30, [sp, #-0x30]!
//   0x45ce1c: F9000BF5  str      x21, [sp, #0x10]
//   0x45ce20: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x45ce24: 910003FD  mov      x29, sp
//   0x45ce28: 97FF530F  bl       #0x431a64
uint64_t fde_func_13531_0x45ce14(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0045CE14ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BD7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF5ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9024FF4ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x97FF530FULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF0000C14ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF947BA95ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #13541 | PC: 0x45d820..0x45d84c (44 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x45d820: D503233F  paciasp  
//   0x45d824: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x45d828: F9000BF3  str      x19, [sp, #0x10]
//   0x45d82c: 910003FD  mov      x29, sp
//   0x45d830: AA0003F3  mov      x19, x0
//   0x45d834: 97FFFFEC  bl       #0x45d7e4
uint64_t fde_func_13541_0x45d820(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0045D820ULL);
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

// FDE #13550 | PC: 0x45dff0..0x45dff8 (8 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x45dff0: D503245F  bti      c
//   0x45dff4: 17F9B9FB  b        #0x2cc7e0
uint64_t fde_func_13550_0x45dff0(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0045DFF0ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x17F9B9FBULL ^ (1ULL << 32);
    return state ^ (state >> 29);
}

// FDE #13560 | PC: 0x45e500..0x45e50c (12 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x45e500: D503245F  bti      c
//   0x45e504: F9400400  ldr      x0, [x0, #8]
//   0x45e508: 14000001  b        #0x45e50c
uint64_t fde_func_13560_0x45e500(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0045E500ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400400ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x14000001ULL ^ (2ULL << 32);
    return state ^ (state >> 29);
}

// FDE #13569 | PC: 0x45e8f0..0x45e920 (48 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x45e8f0: D503233F  paciasp  
//   0x45e8f4: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x45e8f8: F9000BF3  str      x19, [sp, #0x10]
//   0x45e8fc: 910003FD  mov      x29, sp
//   0x45e900: AA0003F3  mov      x19, x0
//   0x45e904: F9400C00  ldr      x0, [x0, #0x18]
uint64_t fde_func_13569_0x45e8f0(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0045E8F0ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF3ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400C00ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x97FD7833ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA1303E0ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #13579 | PC: 0x45ee14..0x45ee84 (112 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x45ee14: D503233F  paciasp  
//   0x45ee18: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x45ee1c: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x45ee20: 910003FD  mov      x29, sp
//   0x45ee24: AA0003F3  mov      x19, x0
//   0x45ee28: F9405014  ldr      x20, [x0, #0xa0]
uint64_t fde_func_13579_0x45ee14(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0045EE14ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9014FF4ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9405014ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB4000254ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91024280ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #13588 | PC: 0x45f1e0..0x45f21c (60 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x45f1e0: D503233F  paciasp  
//   0x45f1e4: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x45f1e8: F9000BF3  str      x19, [sp, #0x10]
//   0x45f1ec: 910003FD  mov      x29, sp
//   0x45f1f0: AA0003F3  mov      x19, x0
//   0x45f1f4: F9404000  ldr      x0, [x0, #0x80]
uint64_t fde_func_13588_0x45f1e0(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0045F1E0ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF3ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9404000ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB0000A48ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91094108ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #13598 | PC: 0x45f6b8..0x45f708 (80 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x45f6b8: D503233F  paciasp  
//   0x45f6bc: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x45f6c0: F9000BF3  str      x19, [sp, #0x10]
//   0x45f6c4: 910003FD  mov      x29, sp
//   0x45f6c8: F9400013  ldr      x19, [x0]
//   0x45f6cc: F900001F  str      xzr, [x0]
uint64_t fde_func_13598_0x45f6b8(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0045F6B8ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF3ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400013ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF900001FULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB4000153ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x39404008ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #13607 | PC: 0x45fa18..0x45fa68 (80 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x45fa18: D503233F  paciasp  
//   0x45fa1c: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x45fa20: F9000BF3  str      x19, [sp, #0x10]
//   0x45fa24: 910003FD  mov      x29, sp
//   0x45fa28: F9400013  ldr      x19, [x0]
//   0x45fa2c: F900001F  str      xzr, [x0]
uint64_t fde_func_13607_0x45fa18(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0045FA18ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF3ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400013ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF900001FULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB4000153ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x39404008ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #13617 | PC: 0x460064..0x460078 (20 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x460064: D503245F  bti      c
//   0x460068: 90000A48  adrp     x8, #0x5a8000
//   0x46006c: 910A4108  add      x8, x8, #0x290
//   0x460070: F9000028  str      x8, [x1]
//   0x460074: D65F03C0  ret      
uint64_t fde_func_13617_0x460064(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00460064ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x90000A48ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910A4108ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000028ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD65F03C0ULL ^ (4ULL << 32);
    return state ^ (state >> 29);
}

// FDE #13626 | PC: 0x46012c..0x460164 (56 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x46012c: D503233F  paciasp  
//   0x460130: D10083FF  sub      sp, sp, #0x20
//   0x460134: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x460138: 910043FD  add      x29, sp, #0x10
//   0x46013c: F9407008  ldr      x8, [x0, #0xe0]
//   0x460140: 3902AC1F  strb     wzr, [x0, #0xab]
uint64_t fde_func_13626_0x46012c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0046012CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10083FFULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9407008ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x3902AC1FULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910023E1ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF90007FFULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #13636 | PC: 0x46104c..0x461084 (56 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x46104c: D503233F  paciasp  
//   0x461050: D10083FF  sub      sp, sp, #0x20
//   0x461054: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x461058: 910043FD  add      x29, sp, #0x10
//   0x46105c: F9407008  ldr      x8, [x0, #0xe0]
//   0x461060: B9018801  str      w1, [x0, #0x188]
uint64_t fde_func_13636_0x46104c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0046104CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10083FFULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9407008ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB9018801ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910023E1ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF90007FFULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #13645 | PC: 0x4610e4..0x4610f0 (12 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x4610e4: D503245F  bti      c
//   0x4610e8: D1016000  sub      x0, x0, #0x58
//   0x4610ec: 17FFFF37  b        #0x460dc8
uint64_t fde_func_13645_0x4610e4(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x004610E4ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD1016000ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x17FFFF37ULL ^ (2ULL << 32);
    return state ^ (state >> 29);
}

// FDE #13655 | PC: 0x46115c..0x461168 (12 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x46115c: D503245F  bti      c
//   0x461160: D101C000  sub      x0, x0, #0x70
//   0x461164: 17FFFFBA  b        #0x46104c
uint64_t fde_func_13655_0x46115c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0046115CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD101C000ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x17FFFFBAULL ^ (2ULL << 32);
    return state ^ (state >> 29);
}

// FDE #13664 | PC: 0x46133c..0x46143c (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x46133c: D503233F  paciasp  
//   0x461340: A9BD7BFD  stp      x29, x30, [sp, #-0x30]!
//   0x461344: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x461348: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x46134c: 910003FD  mov      x29, sp
//   0x461350: A94F5413  ldp      x19, x21, [x0, #0xf0]
uint64_t fde_func_13664_0x46133c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0046133CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BD7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90157F6ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9024FF4ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA94F5413ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F4ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xEB15027FULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #13674 | PC: 0x461f6c..0x46206c (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x461f6c: D503233F  paciasp  
//   0x461f70: A9BD7BFD  stp      x29, x30, [sp, #-0x30]!
//   0x461f74: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x461f78: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x461f7c: 910003FD  mov      x29, sp
//   0x461f80: F9400016  ldr      x22, [x0]
uint64_t fde_func_13674_0x461f6c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00461F6CULL);
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

// FDE #13684 | PC: 0x462928..0x462a28 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x462928: D503233F  paciasp  
//   0x46292c: D10143FF  sub      sp, sp, #0x50
//   0x462930: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x462934: F90013F7  str      x23, [sp, #0x20]
//   0x462938: A90357F6  stp      x22, x21, [sp, #0x30]
//   0x46293c: A9044FF4  stp      x20, x19, [sp, #0x40]
uint64_t fde_func_13684_0x462928(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00462928ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10143FFULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF90013F7ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90357F6ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9044FF4ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x52800028ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #13693 | PC: 0x462ce0..0x462d64 (132 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x462ce0: D503233F  paciasp  
//   0x462ce4: A9BD7BFD  stp      x29, x30, [sp, #-0x30]!
//   0x462ce8: F9000BF5  str      x21, [sp, #0x10]
//   0x462cec: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x462cf0: 910003FD  mov      x29, sp
//   0x462cf4: AA0003F4  mov      x20, x0
uint64_t fde_func_13693_0x462ce0(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00462CE0ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BD7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF5ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9024FF4ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F4ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x97F64128ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB940EA81ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #13703 | PC: 0x4632bc..0x4632c8 (12 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x4632bc: D503245F  bti      c
//   0x4632c0: D1002000  sub      x0, x0, #8
//   0x4632c4: 17FFFF7E  b        #0x4630bc
uint64_t fde_func_13703_0x4632bc(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x004632BCULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD1002000ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x17FFFF7EULL ^ (2ULL << 32);
    return state ^ (state >> 29);
}

// FDE #13712 | PC: 0x463c44..0x463d44 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x463c44: D503233F  paciasp  
//   0x463c48: A9BB7BFD  stp      x29, x30, [sp, #-0x50]!
//   0x463c4c: F9000BF9  str      x25, [sp, #0x10]
//   0x463c50: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x463c54: A90357F6  stp      x22, x21, [sp, #0x30]
//   0x463c58: A9044FF4  stp      x20, x19, [sp, #0x40]
uint64_t fde_func_13712_0x463c44(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00463C44ULL);
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

// FDE #13722 | PC: 0x464430..0x4644f8 (200 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x464430: D503233F  paciasp  
//   0x464434: D10143FF  sub      sp, sp, #0x50
//   0x464438: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x46443c: A90357F6  stp      x22, x21, [sp, #0x30]
//   0x464440: A9044FF4  stp      x20, x19, [sp, #0x40]
//   0x464444: 910083FD  add      x29, sp, #0x20
uint64_t fde_func_13722_0x464430(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00464430ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10143FFULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9027BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90357F6ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9044FF4ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910083FDULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F5ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91012000ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #13731 | PC: 0x464844..0x464940 (252 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x464844: D503233F  paciasp  
//   0x464848: D10203FF  sub      sp, sp, #0x80
//   0x46484c: A9057BFD  stp      x29, x30, [sp, #0x50]
//   0x464850: F90033F5  str      x21, [sp, #0x60]
//   0x464854: A9074FF4  stp      x20, x19, [sp, #0x70]
//   0x464858: 910143FD  add      x29, sp, #0x50
uint64_t fde_func_13731_0x464844(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00464844ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10203FFULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9057BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF90033F5ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9074FF4ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910143FDULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD53BD055ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #13741 | PC: 0x464d08..0x464e08 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x464d08: D503233F  paciasp  
//   0x464d0c: A9BB7BFD  stp      x29, x30, [sp, #-0x50]!
//   0x464d10: F9000BF9  str      x25, [sp, #0x10]
//   0x464d14: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x464d18: A90357F6  stp      x22, x21, [sp, #0x30]
//   0x464d1c: A9044FF4  stp      x20, x19, [sp, #0x40]
uint64_t fde_func_13741_0x464d08(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00464D08ULL);
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

// FDE #13750 | PC: 0x465238..0x4652d0 (152 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x465238: D503233F  paciasp  
//   0x46523c: D10103FF  sub      sp, sp, #0x40
//   0x465240: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x465244: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x465248: 910083FD  add      x29, sp, #0x20
//   0x46524c: 910023E0  add      x0, sp, #8
uint64_t fde_func_13750_0x465238(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00465238ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10103FFULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9027BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9034FF4ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910083FDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910023E0ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0103F4ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0803F3ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #13760 | PC: 0x465d2c..0x465d70 (68 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x465d2c: D503233F  paciasp  
//   0x465d30: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x465d34: F9000BF3  str      x19, [sp, #0x10]
//   0x465d38: 910003FD  mov      x29, sp
//   0x465d3c: AA0003F3  mov      x19, x0
//   0x465d40: 52800600  mov      w0, #0x30
uint64_t fde_func_13760_0x465d2c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00465D2CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF3ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x52800600ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x97F9DA0CULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x6F00E400ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #13769 | PC: 0x466808..0x4668fc (244 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x466808: D503233F  paciasp  
//   0x46680c: A9BD7BFD  stp      x29, x30, [sp, #-0x30]!
//   0x466810: F9000BF5  str      x21, [sp, #0x10]
//   0x466814: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x466818: 910003FD  mov      x29, sp
//   0x46681c: D0000A08  adrp     x8, #0x5a8000
uint64_t fde_func_13769_0x466808(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00466808ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BD7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF5ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9024FF4ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD0000A08ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x911B4108ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F4ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #13779 | PC: 0x467688..0x4676d8 (80 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x467688: D503233F  paciasp  
//   0x46768c: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x467690: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x467694: 910003FD  mov      x29, sp
//   0x467698: AA0103F3  mov      x19, x1
//   0x46769c: AA0003F4  mov      x20, x0
uint64_t fde_func_13779_0x467688(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00467688ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9014FF4ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0103F3ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F4ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x94047E38ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91006280ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #13788 | PC: 0x4680dc..0x468128 (76 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x4680dc: D503233F  paciasp  
//   0x4680e0: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x4680e4: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x4680e8: 910003FD  mov      x29, sp
//   0x4680ec: AA0103F3  mov      x19, x1
//   0x4680f0: AA0003F4  mov      x20, x0
uint64_t fde_func_13788_0x4680dc(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x004680DCULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9014FF4ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0103F3ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F4ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x94047B6DULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91006280ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #13798 | PC: 0x468b34..0x468b40 (12 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x468b34: D503245F  bti      c
//   0x468b38: F9400001  ldr      x1, [x0]
//   0x468b3c: 14000001  b        #0x468b40
uint64_t fde_func_13798_0x468b34(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00468B34ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400001ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x14000001ULL ^ (2ULL << 32);
    return state ^ (state >> 29);
}

// FDE #13807 | PC: 0x469120..0x46916c (76 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x469120: D503245F  bti      c
//   0x469124: B4000220  cbz      x0, #0x469168
//   0x469128: D503233F  paciasp  
//   0x46912c: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x469130: F9000BF3  str      x19, [sp, #0x10]
//   0x469134: 910003FD  mov      x29, sp
uint64_t fde_func_13807_0x469120(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00469120ULL);
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

// FDE #13817 | PC: 0x4698b4..0x4698e0 (44 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x4698b4: D503233F  paciasp  
//   0x4698b8: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x4698bc: F9000BF3  str      x19, [sp, #0x10]
//   0x4698c0: 910003FD  mov      x29, sp
//   0x4698c4: AA0003F3  mov      x19, x0
//   0x4698c8: 97FFFFE2  bl       #0x469850
uint64_t fde_func_13817_0x4698b4(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x004698B4ULL);
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

// FDE #13826 | PC: 0x46a2a0..0x46a358 (184 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x46a2a0: D503233F  paciasp  
//   0x46a2a4: A9BD7BFD  stp      x29, x30, [sp, #-0x30]!
//   0x46a2a8: F9000BF5  str      x21, [sp, #0x10]
//   0x46a2ac: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x46a2b0: 910003FD  mov      x29, sp
//   0x46a2b4: AA0003F3  mov      x19, x0
uint64_t fde_func_13826_0x46a2a0(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0046A2A0ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BD7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF5ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9024FF4ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x52803200ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0103F4ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #13836 | PC: 0x46aba0..0x46ac1c (124 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x46aba0: D503233F  paciasp  
//   0x46aba4: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x46aba8: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x46abac: 910003FD  mov      x29, sp
//   0x46abb0: AA0103F3  mov      x19, x1
//   0x46abb4: AA0003F4  mov      x20, x0
uint64_t fde_func_13836_0x46aba0(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0046ABA0ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9014FF4ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0103F3ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F4ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400268ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x29442109ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #13845 | PC: 0x46b000..0x46b020 (32 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x46b000: D503245F  bti      c
//   0x46b004: B9414008  ldr      w8, [x0, #0x140]
//   0x46b008: 7100151F  cmp      w8, #5
//   0x46b00c: 54000041  b.ne     #0x46b014
//   0x46b010: D65F03C0  ret      
//   0x46b014: 52800088  mov      w8, #4
uint64_t fde_func_13845_0x46b000(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0046B000ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB9414008ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x7100151FULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x54000041ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD65F03C0ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x52800088ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB9014008ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x14000001ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #13855 | PC: 0x46ba00..0x46ba3c (60 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x46ba00: D503233F  paciasp  
//   0x46ba04: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x46ba08: F9000BF3  str      x19, [sp, #0x10]
//   0x46ba0c: 910003FD  mov      x29, sp
//   0x46ba10: AA0003F3  mov      x19, x0
//   0x46ba14: 91060000  add      x0, x0, #0x180
uint64_t fde_func_13855_0x46ba00(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0046BA00ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF3ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91060000ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB00009E8ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91236108ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #13864 | PC: 0x46bd04..0x46bdbc (184 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x46bd04: D503233F  paciasp  
//   0x46bd08: D10143FF  sub      sp, sp, #0x50
//   0x46bd0c: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x46bd10: A90357F6  stp      x22, x21, [sp, #0x30]
//   0x46bd14: A9044FF4  stp      x20, x19, [sp, #0x40]
//   0x46bd18: 910083FD  add      x29, sp, #0x20
uint64_t fde_func_13864_0x46bd04(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0046BD04ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10143FFULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9027BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90357F6ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9044FF4ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910083FDULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF940DC13ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB40004B3ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #13874 | PC: 0x46c094..0x46c0c0 (44 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x46c094: D503233F  paciasp  
//   0x46c098: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x46c09c: F9000BF3  str      x19, [sp, #0x10]
//   0x46c0a0: 910003FD  mov      x29, sp
//   0x46c0a4: AA0003F3  mov      x19, x0
//   0x46c0a8: 97FFFFF6  bl       #0x46c080
uint64_t fde_func_13874_0x46c094(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0046C094ULL);
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

// FDE #13883 | PC: 0x46c34c..0x46c3c0 (116 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x46c34c: D503233F  paciasp  
//   0x46c350: A9BD7BFD  stp      x29, x30, [sp, #-0x30]!
//   0x46c354: F9000BF5  str      x21, [sp, #0x10]
//   0x46c358: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x46c35c: 910003FD  mov      x29, sp
//   0x46c360: AA0003F3  mov      x19, x0
uint64_t fde_func_13883_0x46c34c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0046C34CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BD7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF5ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9024FF4ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x52800E00ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0803F4ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #13893 | PC: 0x46c6f4..0x46c768 (116 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x46c6f4: D503233F  paciasp  
//   0x46c6f8: A9BD7BFD  stp      x29, x30, [sp, #-0x30]!
//   0x46c6fc: F9000BF5  str      x21, [sp, #0x10]
//   0x46c700: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x46c704: 910003FD  mov      x29, sp
//   0x46c708: AA0003F3  mov      x19, x0
uint64_t fde_func_13893_0x46c6f4(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0046C6F4ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BD7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF5ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9024FF4ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x52800E00ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0803F4ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #13902 | PC: 0x46cbe8..0x46ccc4 (220 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x46cbe8: D503233F  paciasp  
//   0x46cbec: A9BC7BFD  stp      x29, x30, [sp, #-0x40]!
//   0x46cbf0: F9000BF7  str      x23, [sp, #0x10]
//   0x46cbf4: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x46cbf8: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x46cbfc: 910003FD  mov      x29, sp
uint64_t fde_func_13902_0x46cbe8(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0046CBE8ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BC7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF7ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90257F6ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9034FF4ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x52801100ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #13912 | PC: 0x46d210..0x46d268 (88 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x46d210: D503233F  paciasp  
//   0x46d214: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x46d218: F9000BF3  str      x19, [sp, #0x10]
//   0x46d21c: 910003FD  mov      x29, sp
//   0x46d220: AA0003F3  mov      x19, x0
//   0x46d224: 97FFFB85  bl       #0x46c038
uint64_t fde_func_13912_0x46d210(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0046D210ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF3ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x97FFFB85ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF00009C8ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x912E0108ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #13921 | PC: 0x46d4c4..0x46d518 (84 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x46d4c4: D503233F  paciasp  
//   0x46d4c8: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x46d4cc: F9000BF3  str      x19, [sp, #0x10]
//   0x46d4d0: 910003FD  mov      x29, sp
//   0x46d4d4: AA0003F3  mov      x19, x0
//   0x46d4d8: F9404800  ldr      x0, [x0, #0x90]
uint64_t fde_func_13921_0x46d4c4(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0046D4C4ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF3ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9404800ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF00009C8ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91310108ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #13931 | PC: 0x46d958..0x46d984 (44 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x46d958: D503233F  paciasp  
//   0x46d95c: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x46d960: F9000BF3  str      x19, [sp, #0x10]
//   0x46d964: 910003FD  mov      x29, sp
//   0x46d968: AA0003F3  mov      x19, x0
//   0x46d96c: 97FFFFE9  bl       #0x46d910
uint64_t fde_func_13931_0x46d958(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0046D958ULL);
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

// FDE #13940 | PC: 0x46dd2c..0x46dd8c (96 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x46dd2c: D503233F  paciasp  
//   0x46dd30: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x46dd34: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x46dd38: 910003FD  mov      x29, sp
//   0x46dd3c: AA0003F4  mov      x20, x0
//   0x46dd40: AA0003F3  mov      x19, x0
uint64_t fde_func_13940_0x46dd2c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0046DD2CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9014FF4ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F4ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF00009C8ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91360108ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #13950 | PC: 0x46e1d4..0x46e248 (116 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x46e1d4: D503233F  paciasp  
//   0x46e1d8: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x46e1dc: F9000BF3  str      x19, [sp, #0x10]
//   0x46e1e0: 910003FD  mov      x29, sp
//   0x46e1e4: D00009C8  adrp     x8, #0x5a8000
//   0x46e1e8: 91390108  add      x8, x8, #0xe40
uint64_t fde_func_13950_0x46e1d4(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0046E1D4ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF3ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD00009C8ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91390108ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD00009C9ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x913A0129ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #13959 | PC: 0x46e54c..0x46e5d0 (132 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x46e54c: D503233F  paciasp  
//   0x46e550: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x46e554: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x46e558: 910003FD  mov      x29, sp
//   0x46e55c: A95E2408  ldp      x8, x9, [x0, #0x1e0]
//   0x46e560: AA0003F3  mov      x19, x0
uint64_t fde_func_13959_0x46e54c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0046E54CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9014FF4ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA95E2408ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x2A0103F4ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9403D0AULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #13969 | PC: 0x46ef6c..0x46f06c (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x46ef6c: D503233F  paciasp  
//   0x46ef70: D10143FF  sub      sp, sp, #0x50
//   0x46ef74: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x46ef78: F9001BF5  str      x21, [sp, #0x30]
//   0x46ef7c: A9044FF4  stp      x20, x19, [sp, #0x40]
//   0x46ef80: 910083FD  add      x29, sp, #0x20
uint64_t fde_func_13969_0x46ef6c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0046EF6CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10143FFULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9027BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9001BF5ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9044FF4ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910083FDULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F5ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x97F982C4ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #13979 | PC: 0x46f55c..0x46f588 (44 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x46f55c: D503233F  paciasp  
//   0x46f560: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x46f564: F9000BF3  str      x19, [sp, #0x10]
//   0x46f568: 910003FD  mov      x29, sp
//   0x46f56c: AA0003F3  mov      x19, x0
//   0x46f570: 97FFFFE7  bl       #0x46f50c
uint64_t fde_func_13979_0x46f55c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0046F55CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF3ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x97FFFFE7ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA1303E0ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400BF3ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #13988 | PC: 0x46fc00..0x46fc24 (36 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x46fc00: D503245F  bti      c
//   0x46fc04: F9408408  ldr      x8, [x0, #0x108]
//   0x46fc08: B9000D01  str      w1, [x8, #0xc]
//   0x46fc0c: F9408C08  ldr      x8, [x0, #0x118]
//   0x46fc10: B4000088  cbz      x8, #0x46fc20
//   0x46fc14: 91046000  add      x0, x0, #0x118
uint64_t fde_func_13988_0x46fc00(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0046FC00ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9408408ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB9000D01ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9408C08ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB4000088ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91046000ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA1F03E1ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x17F6B4F4ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #13998 | PC: 0x4701d4..0x4702d4 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x4701d4: D503233F  paciasp  
//   0x4701d8: D101C3FF  sub      sp, sp, #0x70
//   0x4701dc: A9047BFD  stp      x29, x30, [sp, #0x40]
//   0x4701e0: F9002BF5  str      x21, [sp, #0x50]
//   0x4701e4: A9064FF4  stp      x20, x19, [sp, #0x60]
//   0x4701e8: 910103FD  add      x29, sp, #0x40
uint64_t fde_func_13998_0x4701d4(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x004701D4ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD101C3FFULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9047BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9002BF5ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9064FF4ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910103FDULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD53BD055ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #14007 | PC: 0x470728..0x470754 (44 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x470728: D503233F  paciasp  
//   0x47072c: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x470730: F9000BF3  str      x19, [sp, #0x10]
//   0x470734: 910003FD  mov      x29, sp
//   0x470738: AA0003F3  mov      x19, x0
//   0x47073c: 97FFFFE9  bl       #0x4706e0
uint64_t fde_func_14007_0x470728(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00470728ULL);
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

// FDE #14017 | PC: 0x470db8..0x470dfc (68 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x470db8: D503245F  bti      c
//   0x470dbc: B40001E0  cbz      x0, #0x470df8
//   0x470dc0: D503233F  paciasp  
//   0x470dc4: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x470dc8: F9000BF3  str      x19, [sp, #0x10]
//   0x470dcc: 910003FD  mov      x29, sp
uint64_t fde_func_14017_0x470db8(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00470DB8ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB40001E0ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE7BFDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF3ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9100C000ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #14026 | PC: 0x4710bc..0x471138 (124 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x4710bc: D503233F  paciasp  
//   0x4710c0: D100C3FF  sub      sp, sp, #0x30
//   0x4710c4: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x4710c8: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x4710cc: 910043FD  add      x29, sp, #0x10
//   0x4710d0: 39408008  ldrb     w8, [x0, #0x20]
uint64_t fde_func_14026_0x4710bc(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x004710BCULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD100C3FFULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9024FF4ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x39408008ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x340000C8ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9424FF4ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #14036 | PC: 0x471594..0x4715d0 (60 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x471594: D503233F  paciasp  
//   0x471598: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x47159c: F9000BF3  str      x19, [sp, #0x10]
//   0x4715a0: 910003FD  mov      x29, sp
//   0x4715a4: AA0003F3  mov      x19, x0
//   0x4715a8: 97F9D884  bl       #0x2e77b8
uint64_t fde_func_14036_0x471594(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00471594ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF3ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x97F9D884ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003E8ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA1303E0ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #14045 | PC: 0x471cf4..0x471d20 (44 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x471cf4: D503233F  paciasp  
//   0x471cf8: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x471cfc: F9000BF3  str      x19, [sp, #0x10]
//   0x471d00: 910003FD  mov      x29, sp
//   0x471d04: AA0003F3  mov      x19, x0
//   0x471d08: 97FFFFE6  bl       #0x471ca0
uint64_t fde_func_14045_0x471cf4(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00471CF4ULL);
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

// FDE #14055 | PC: 0x472334..0x472360 (44 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x472334: D503233F  paciasp  
//   0x472338: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x47233c: F9000BF3  str      x19, [sp, #0x10]
//   0x472340: 910003FD  mov      x29, sp
//   0x472344: AA0003F3  mov      x19, x0
//   0x472348: 94000186  bl       #0x472960
uint64_t fde_func_14055_0x472334(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00472334ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF3ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x94000186ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA1303E0ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400BF3ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #14064 | PC: 0x472798..0x4727cc (52 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x472798: D503233F  paciasp  
//   0x47279c: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x4727a0: 910003FD  mov      x29, sp
//   0x4727a4: 39450009  ldrb     w9, [x0, #0x140]
//   0x4727a8: 52800748  mov      w8, #0x3a
//   0x4727ac: F9409C00  ldr      x0, [x0, #0x138]
uint64_t fde_func_14064_0x472798(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00472798ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BF7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x39450009ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x52800748ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9409C00ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x7100013FULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x1A9F1501ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #14074 | PC: 0x473198..0x473214 (124 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x473198: D503233F  paciasp  
//   0x47319c: A9BD7BFD  stp      x29, x30, [sp, #-0x30]!
//   0x4731a0: F9000BF5  str      x21, [sp, #0x10]
//   0x4731a4: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x4731a8: 910003FD  mov      x29, sp
//   0x4731ac: 9100C014  add      x20, x0, #0x30
uint64_t fde_func_14074_0x473198(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00473198ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BD7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF5ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9024FF4ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9100C014ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA1403E0ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #14083 | PC: 0x473a00..0x473aa0 (160 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x473a00: D503233F  paciasp  
//   0x473a04: A9BD7BFD  stp      x29, x30, [sp, #-0x30]!
//   0x473a08: F9000BF5  str      x21, [sp, #0x10]
//   0x473a0c: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x473a10: 910003FD  mov      x29, sp
//   0x473a14: D00009A8  adrp     x8, #0x5a9000
uint64_t fde_func_14083_0x473a00(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00473A00ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BD7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF5ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9024FF4ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD00009A8ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910C8108ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x12800041ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #14093 | PC: 0x4744bc..0x474570 (180 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x4744bc: D503233F  paciasp  
//   0x4744c0: A9BC7BFD  stp      x29, x30, [sp, #-0x40]!
//   0x4744c4: F9000BF7  str      x23, [sp, #0x10]
//   0x4744c8: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x4744cc: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x4744d0: 910003FD  mov      x29, sp
uint64_t fde_func_14093_0x4744bc(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x004744BCULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BC7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF7ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90257F6ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9034FF4ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0303F7ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0203F6ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #14102 | PC: 0x475038..0x4750e0 (168 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x475038: D503233F  paciasp  
//   0x47503c: A9BD7BFD  stp      x29, x30, [sp, #-0x30]!
//   0x475040: F9000BF5  str      x21, [sp, #0x10]
//   0x475044: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x475048: 910003FD  mov      x29, sp
//   0x47504c: AA0003F5  mov      x21, x0
uint64_t fde_func_14102_0x475038(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00475038ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BD7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF5ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9024FF4ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F5ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F4ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x2A0103F3ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #14112 | PC: 0x475d20..0x475e20 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x475d20: D503233F  paciasp  
//   0x475d24: D102C3FF  sub      sp, sp, #0xb0
//   0x475d28: A9067BFD  stp      x29, x30, [sp, #0x60]
//   0x475d2c: F9003BF9  str      x25, [sp, #0x70]
//   0x475d30: A9085FF8  stp      x24, x23, [sp, #0x80]
//   0x475d34: A90957F6  stp      x22, x21, [sp, #0x90]
uint64_t fde_func_14112_0x475d20(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00475D20ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD102C3FFULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9067BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9003BF9ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9085FF8ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90957F6ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90A4FF4ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910183FDULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #14121 | PC: 0x476330..0x4763b4 (132 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x476330: D503233F  paciasp  
//   0x476334: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x476338: F9000BF3  str      x19, [sp, #0x10]
//   0x47633c: 910003FD  mov      x29, sp
//   0x476340: AA0003F3  mov      x19, x0
//   0x476344: 97F9C51D  bl       #0x2e77b8
uint64_t fde_func_14121_0x476330(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00476330ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF3ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x97F9C51DULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA950A668ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9010660ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #14131 | PC: 0x477178..0x477198 (32 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x477178: D503245F  bti      c
//   0x47717c: 7100003F  cmp      w1, #0
//   0x477180: 12807D09  mov      w9, #-0x3e9
//   0x477184: 2A0103E8  mov      w8, w1
//   0x477188: 1A8903E1  csel     w1, wzr, w9, eq
//   0x47718c: F9407009  ldr      x9, [x0, #0xe0]
uint64_t fde_func_14131_0x477178(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00477178ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x7100003FULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x12807D09ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x2A0103E8ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x1A8903E1ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9407009ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB9001128ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x17FFFFE7ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #14140 | PC: 0x477f78..0x478078 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x477f78: D503233F  paciasp  
//   0x477f7c: A9BD7BFD  stp      x29, x30, [sp, #-0x30]!
//   0x477f80: F9000BF5  str      x21, [sp, #0x10]
//   0x477f84: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x477f88: 910003FD  mov      x29, sp
//   0x477f8c: 6F00E400  movi     v0.2d, #0000000000000000
uint64_t fde_func_14140_0x477f78(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00477F78ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BD7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF5ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9024FF4ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x6F00E400ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF0FFE008ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #14150 | PC: 0x47943c..0x47946c (48 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x47943c: D503233F  paciasp  
//   0x479440: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x479444: 910003FD  mov      x29, sp
//   0x479448: A9402408  ldp      x8, x9, [x0]
//   0x47944c: CB080129  sub      x9, x9, x8
//   0x479450: EB890C3F  cmp      x1, x9, asr #3
uint64_t fde_func_14150_0x47943c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0047943CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BF7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9402408ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xCB080129ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xEB890C3FULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x540000A2ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x8B010D00ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #14159 | PC: 0x47a048..0x47a060 (24 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x47a048: D503245F  bti      c
//   0x47a04c: AA0303E5  mov      x5, x3
//   0x47a050: AA0203E4  mov      x4, x2
//   0x47a054: 2A1F03E2  mov      w2, wzr
//   0x47a058: 2A1F03E3  mov      w3, wzr
//   0x47a05c: 17FFF94D  b        #0x478590
uint64_t fde_func_14159_0x47a048(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0047A048ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0303E5ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0203E4ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x2A1F03E2ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x2A1F03E3ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x17FFF94DULL ^ (5ULL << 32);
    return state ^ (state >> 29);
}

// FDE #14169 | PC: 0x47a654..0x47a660 (12 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x47a654: D503245F  bti      c
//   0x47a658: D1002000  sub      x0, x0, #8
//   0x47a65c: 17FFFFB8  b        #0x47a53c
uint64_t fde_func_14169_0x47a654(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0047A654ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD1002000ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x17FFFFB8ULL ^ (2ULL << 32);
    return state ^ (state >> 29);
}

// FDE #14178 | PC: 0x47ac78..0x47acd4 (92 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x47ac78: D503233F  paciasp  
//   0x47ac7c: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x47ac80: F9000BF3  str      x19, [sp, #0x10]
//   0x47ac84: 910003FD  mov      x29, sp
//   0x47ac88: F0000968  adrp     x8, #0x5a9000
//   0x47ac8c: 91130108  add      x8, x8, #0x4c0
uint64_t fde_func_14178_0x47ac78(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0047AC78ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF3ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF0000968ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91130108ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x2A1F03E1ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #14188 | PC: 0x47c284..0x47c384 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x47c284: D503233F  paciasp  
//   0x47c288: D10303FF  sub      sp, sp, #0xc0
//   0x47c28c: A9067BFD  stp      x29, x30, [sp, #0x60]
//   0x47c290: F9003BFB  str      x27, [sp, #0x70]
//   0x47c294: A90867FA  stp      x26, x25, [sp, #0x80]
//   0x47c298: A9095FF8  stp      x24, x23, [sp, #0x90]
uint64_t fde_func_14188_0x47c284(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0047C284ULL);
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

// FDE #14197 | PC: 0x47c7fc..0x47c870 (116 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x47c7fc: D503233F  paciasp  
//   0x47c800: A9BD7BFD  stp      x29, x30, [sp, #-0x30]!
//   0x47c804: F9000BF5  str      x21, [sp, #0x10]
//   0x47c808: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x47c80c: 910003FD  mov      x29, sp
//   0x47c810: A900FC1F  stp      xzr, xzr, [x0, #8]
uint64_t fde_func_14197_0x47c7fc(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0047C7FCULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BD7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF5ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9024FF4ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA900FC1FULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF900001FULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9402029ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #14207 | PC: 0x47d858..0x47d8a0 (72 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x47d858: D503233F  paciasp  
//   0x47d85c: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x47d860: F9000BF3  str      x19, [sp, #0x10]
//   0x47d864: 910003FD  mov      x29, sp
//   0x47d868: AA0003F3  mov      x19, x0
//   0x47d86c: 97FFFD2F  bl       #0x47cd28
uint64_t fde_func_14207_0x47d858(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0047D858ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF3ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x97FFFD2FULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x3100041FULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x540000E0ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #14216 | PC: 0x47dcd0..0x47dd68 (152 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x47dcd0: D503233F  paciasp  
//   0x47dcd4: A9BD7BFD  stp      x29, x30, [sp, #-0x30]!
//   0x47dcd8: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x47dcdc: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x47dce0: 910003FD  mov      x29, sp
//   0x47dce4: A9405416  ldp      x22, x21, [x0]
uint64_t fde_func_14216_0x47dcd0(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0047DCD0ULL);
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

// FDE #14226 | PC: 0x47e1f0..0x47e228 (56 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x47e1f0: D503233F  paciasp  
//   0x47e1f4: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x47e1f8: F9000BF3  str      x19, [sp, #0x10]
//   0x47e1fc: 910003FD  mov      x29, sp
//   0x47e200: F0000948  adrp     x8, #0x5a9000
//   0x47e204: 9117C108  add      x8, x8, #0x5f0
uint64_t fde_func_14226_0x47e1f0(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0047E1F0ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF3ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF0000948ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9117C108ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF80A8408ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #14235 | PC: 0x47e790..0x47e890 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x47e790: D503233F  paciasp  
//   0x47e794: D101C3FF  sub      sp, sp, #0x70
//   0x47e798: A9037BFD  stp      x29, x30, [sp, #0x30]
//   0x47e79c: F90023F7  str      x23, [sp, #0x40]
//   0x47e7a0: A90557F6  stp      x22, x21, [sp, #0x50]
//   0x47e7a4: A9064FF4  stp      x20, x19, [sp, #0x60]
uint64_t fde_func_14235_0x47e790(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0047E790ULL);
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

// FDE #14245 | PC: 0x47f190..0x47f1b8 (40 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x47f190: D503245F  bti      c
//   0x47f194: AA0003E8  mov      x8, x0
//   0x47f198: F9400400  ldr      x0, [x0, #8]
//   0x47f19c: B4000060  cbz      x0, #0x47f1a8
//   0x47f1a0: 3940A108  ldrb     w8, [x8, #0x28]
//   0x47f1a4: 34000048  cbz      w8, #0x47f1ac
uint64_t fde_func_14245_0x47f190(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0047F190ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003E8ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400400ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB4000060ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x3940A108ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x34000048ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD65F03C0ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400008ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #14254 | PC: 0x480dac..0x480e28 (124 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x480dac: D503233F  paciasp  
//   0x480db0: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x480db4: F9000BF3  str      x19, [sp, #0x10]
//   0x480db8: 910003FD  mov      x29, sp
//   0x480dbc: AA0003F3  mov      x19, x0
//   0x480dc0: 97F51E02  bl       #0x1c85c8
uint64_t fde_func_14254_0x480dac(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00480DACULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF3ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x97F51E02ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91006260ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x97F51E00ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #14264 | PC: 0x481208..0x481264 (92 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x481208: D503233F  paciasp  
//   0x48120c: A9BD7BFD  stp      x29, x30, [sp, #-0x30]!
//   0x481210: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x481214: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x481218: 910003FD  mov      x29, sp
//   0x48121c: AA0203F3  mov      x19, x2
uint64_t fde_func_14264_0x481208(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00481208ULL);
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

// FDE #14274 | PC: 0x481fbc..0x482048 (140 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x481fbc: D503233F  paciasp  
//   0x481fc0: A9BD7BFD  stp      x29, x30, [sp, #-0x30]!
//   0x481fc4: F9000BF5  str      x21, [sp, #0x10]
//   0x481fc8: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x481fcc: 910003FD  mov      x29, sp
//   0x481fd0: AA0003F3  mov      x19, x0
uint64_t fde_func_14274_0x481fbc(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00481FBCULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BD7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF5ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9024FF4ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x52805400ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x97F96967ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #14283 | PC: 0x482958..0x482964 (12 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x482958: D503245F  bti      c
//   0x48295c: D1124000  sub      x0, x0, #0x490
//   0x482960: 17FFFDF8  b        #0x482140
uint64_t fde_func_14283_0x482958(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00482958ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD1124000ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x17FFFDF8ULL ^ (2ULL << 32);
    return state ^ (state >> 29);
}

// FDE #14293 | PC: 0x48321c..0x483274 (88 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x48321c: D503233F  paciasp  
//   0x483220: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x483224: F9000BF3  str      x19, [sp, #0x10]
//   0x483228: 910003FD  mov      x29, sp
//   0x48322c: B944A008  ldr      w8, [x0, #0x4a0]
//   0x483230: 340001A8  cbz      w8, #0x483264
uint64_t fde_func_14293_0x48321c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0048321CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF3ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB944A008ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x340001A8ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB904A001ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x2A0203E1ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #14302 | PC: 0x483510..0x483610 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x483510: D503233F  paciasp  
//   0x483514: D101C3FF  sub      sp, sp, #0x70
//   0x483518: A9037BFD  stp      x29, x30, [sp, #0x30]
//   0x48351c: A9045FF8  stp      x24, x23, [sp, #0x40]
//   0x483520: A90557F6  stp      x22, x21, [sp, #0x50]
//   0x483524: A9064FF4  stp      x20, x19, [sp, #0x60]
uint64_t fde_func_14302_0x483510(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00483510ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD101C3FFULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9037BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9045FF8ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90557F6ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9064FF4ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9100C3FDULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #14312 | PC: 0x484424..0x484524 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x484424: D503233F  paciasp  
//   0x484428: A9BB7BFD  stp      x29, x30, [sp, #-0x50]!
//   0x48442c: F9000BF9  str      x25, [sp, #0x10]
//   0x484430: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x484434: A90357F6  stp      x22, x21, [sp, #0x30]
//   0x484438: A9044FF4  stp      x20, x19, [sp, #0x40]
uint64_t fde_func_14312_0x484424(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00484424ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BB7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF9ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9025FF8ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90357F6ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9044FF4ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA940A014ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #14321 | PC: 0x4847e4..0x48481c (56 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x4847e4: D503233F  paciasp  
//   0x4847e8: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x4847ec: F9000BF3  str      x19, [sp, #0x10]
//   0x4847f0: 910003FD  mov      x29, sp
//   0x4847f4: 94000044  bl       #0x484904
//   0x4847f8: AA0003F3  mov      x19, x0
uint64_t fde_func_14321_0x4847e4(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x004847E4ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF3ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x94000044ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF8418E60ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x94000022ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #14331 | PC: 0x48533c..0x485348 (12 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x48533c: D503245F  bti      c
//   0x485340: D1124000  sub      x0, x0, #0x490
//   0x485344: 17FFFD91  b        #0x484988
uint64_t fde_func_14331_0x48533c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0048533CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD1124000ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x17FFFD91ULL ^ (2ULL << 32);
    return state ^ (state >> 29);
}

// FDE #14340 | PC: 0x486304..0x486358 (84 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x486304: D503233F  paciasp  
//   0x486308: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x48630c: F9000BF3  str      x19, [sp, #0x10]
//   0x486310: 910003FD  mov      x29, sp
//   0x486314: AA0003F3  mov      x19, x0
//   0x486318: 97F9A88B  bl       #0x2f0544
uint64_t fde_func_14340_0x486304(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00486304ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF3ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x97F9A88BULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x7100201FULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x540000C8ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #14350 | PC: 0x48662c..0x4866f8 (204 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x48662c: D503233F  paciasp  
//   0x486630: A9BD7BFD  stp      x29, x30, [sp, #-0x30]!
//   0x486634: F9000BF5  str      x21, [sp, #0x10]
//   0x486638: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x48663c: 910003FD  mov      x29, sp
//   0x486640: AA0103F5  mov      x21, x1
uint64_t fde_func_14350_0x48662c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0048662CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BD7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF5ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9024FF4ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0103F5ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB0FFDFE1ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #14359 | PC: 0x4879c0..0x487a08 (72 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x4879c0: D503233F  paciasp  
//   0x4879c4: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x4879c8: F9000BF3  str      x19, [sp, #0x10]
//   0x4879cc: 910003FD  mov      x29, sp
//   0x4879d0: AA0003F3  mov      x19, x0
//   0x4879d4: 9400000D  bl       #0x487a08
uint64_t fde_func_14359_0x4879c0(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x004879C0ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF3ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9400000DULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x3100041FULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x540000E0ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #14369 | PC: 0x488d30..0x488d9c (108 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x488d30: D503233F  paciasp  
//   0x488d34: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x488d38: 910003FD  mov      x29, sp
//   0x488d3c: D2972C28  mov      x8, #0xb961
//   0x488d40: F2A234E8  movk     x8, #0x11a7, lsl #16
//   0x488d44: F2CF72C8  movk     x8, #0x7b96, lsl #32
uint64_t fde_func_14369_0x488d30(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00488D30ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BF7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD2972C28ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF2A234E8ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF2CF72C8ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF2E02348ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xEB08003FULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #14378 | PC: 0x489000..0x489038 (56 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x489000: D503245F  bti      c
//   0x489004: D2871C88  mov      x8, #0x38e4
//   0x489008: F2BC71C8  movk     x8, #0xe38e, lsl #16
//   0x48900c: F2D1C708  movk     x8, #0x8e38, lsl #32
//   0x489010: F2E01C68  movk     x8, #0xe3, lsl #48
//   0x489014: EB08001F  cmp      x0, x8
uint64_t fde_func_14378_0x489000(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00489000ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD2871C88ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF2BC71C8ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF2D1C708ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF2E01C68ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xEB08001FULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x54000082ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x8B000C08ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #14388 | PC: 0x4892b0..0x4892bc (12 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x4892b0: D503245F  bti      c
//   0x4892b4: F9400001  ldr      x1, [x0]
//   0x4892b8: 17FFFFE8  b        #0x489258
uint64_t fde_func_14388_0x4892b0(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x004892B0ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400001ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x17FFFFE8ULL ^ (2ULL << 32);
    return state ^ (state >> 29);
}

// FDE #14397 | PC: 0x489538..0x489638 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x489538: D503233F  paciasp  
//   0x48953c: D10643FF  sub      sp, sp, #0x190
//   0x489540: A9137BFD  stp      x29, x30, [sp, #0x130]
//   0x489544: A9146FFC  stp      x28, x27, [sp, #0x140]
//   0x489548: A91567FA  stp      x26, x25, [sp, #0x150]
//   0x48954c: A9165FF8  stp      x24, x23, [sp, #0x160]
uint64_t fde_func_14397_0x489538(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00489538ULL);
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

// FDE #14407 | PC: 0x48a18c..0x48a28c (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x48a18c: D503233F  paciasp  
//   0x48a190: D102C3FF  sub      sp, sp, #0xb0
//   0x48a194: A9057BFD  stp      x29, x30, [sp, #0x50]
//   0x48a198: A9066FFC  stp      x28, x27, [sp, #0x60]
//   0x48a19c: A90767FA  stp      x26, x25, [sp, #0x70]
//   0x48a1a0: A9085FF8  stp      x24, x23, [sp, #0x80]
uint64_t fde_func_14407_0x48a18c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0048A18CULL);
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

// FDE #14416 | PC: 0x48a5c8..0x48a6c8 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x48a5c8: D503233F  paciasp  
//   0x48a5cc: D10103FF  sub      sp, sp, #0x40
//   0x48a5d0: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x48a5d4: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x48a5d8: 910083FD  add      x29, sp, #0x20
//   0x48a5dc: AA0103F4  mov      x20, x1
uint64_t fde_func_14416_0x48a5c8(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0048A5C8ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10103FFULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9027BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9034FF4ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910083FDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0103F4ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400421ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #14426 | PC: 0x48abdc..0x48ac74 (152 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x48abdc: D503233F  paciasp  
//   0x48abe0: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x48abe4: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x48abe8: 910003FD  mov      x29, sp
//   0x48abec: F00008E8  adrp     x8, #0x5a9000
//   0x48abf0: 912DC108  add      x8, x8, #0xb70
uint64_t fde_func_14426_0x48abdc(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0048ABDCULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9014FF4ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF00008E8ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x912DC108ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF00008E9ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9127C129ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #14435 | PC: 0x48af30..0x48af70 (64 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x48af30: D503233F  paciasp  
//   0x48af34: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x48af38: F9000BF3  str      x19, [sp, #0x10]
//   0x48af3c: 910003FD  mov      x29, sp
//   0x48af40: AA0003F3  mov      x19, x0
//   0x48af44: 9101A000  add      x0, x0, #0x68
uint64_t fde_func_14435_0x48af30(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0048AF30ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF3ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9101A000ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9403EFD2ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91014260ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #14445 | PC: 0x48b52c..0x48b580 (84 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x48b52c: D503233F  paciasp  
//   0x48b530: D100C3FF  sub      sp, sp, #0x30
//   0x48b534: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x48b538: F90013F3  str      x19, [sp, #0x20]
//   0x48b53c: 910043FD  add      x29, sp, #0x10
//   0x48b540: AA0003F3  mov      x19, x0
uint64_t fde_func_14445_0x48b52c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0048B52CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD100C3FFULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF90013F3ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91004021ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9007C1FULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #14454 | PC: 0x48bcc0..0x48bdc0 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x48bcc0: D503233F  paciasp  
//   0x48bcc4: A9BD7BFD  stp      x29, x30, [sp, #-0x30]!
//   0x48bcc8: F9000BF5  str      x21, [sp, #0x10]
//   0x48bccc: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x48bcd0: 910003FD  mov      x29, sp
//   0x48bcd4: CB000028  sub      x8, x1, x0
uint64_t fde_func_14454_0x48bcc0(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0048BCC0ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BD7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF5ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9024FF4ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xCB000028ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0103F4ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #14464 | PC: 0x48c118..0x48c168 (80 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x48c118: D503245F  bti      c
//   0x48c11c: F0FFDF68  adrp     x8, #0x7b000
//   0x48c120: B00008E9  adrp     x9, #0x5a9000
//   0x48c124: 912BC129  add      x9, x9, #0xaf0
//   0x48c128: B900081F  str      wzr, [x0, #8]
//   0x48c12c: A9017C1F  stp      xzr, xzr, [x0, #0x10]
uint64_t fde_func_14464_0x48c118(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0048C118ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF0FFDF68ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB00008E9ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x912BC129ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB900081FULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017C1FULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xFD43A100ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB00008E8ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #14473 | PC: 0x48c474..0x48c480 (12 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x48c474: D503245F  bti      c
//   0x48c478: F9400400  ldr      x0, [x0, #8]
//   0x48c47c: 14000239  b        #0x48cd60
uint64_t fde_func_14473_0x48c474(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0048C474ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400400ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x14000239ULL ^ (2ULL << 32);
    return state ^ (state >> 29);
}

// FDE #14483 | PC: 0x48cddc..0x48ce20 (68 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x48cddc: D503233F  paciasp  
//   0x48cde0: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x48cde4: F9000BF3  str      x19, [sp, #0x10]
//   0x48cde8: 910003FD  mov      x29, sp
//   0x48cdec: F9400008  ldr      x8, [x0]
//   0x48cdf0: B4000108  cbz      x8, #0x48ce10
uint64_t fde_func_14483_0x48cddc(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0048CDDCULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF3ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400008ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB4000108ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x97FFDE66ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #14492 | PC: 0x48d130..0x48d178 (72 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x48d130: D503233F  paciasp  
//   0x48d134: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x48d138: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x48d13c: 910003FD  mov      x29, sp
//   0x48d140: AA0003F3  mov      x19, x0
//   0x48d144: AA0003F4  mov      x20, x0
uint64_t fde_func_14492_0x48d130(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0048D130ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9014FF4ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F4ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9102C000ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x900008E8ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #14502 | PC: 0x48d42c..0x48d440 (20 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x48d42c: D503245F  bti      c
//   0x48d430: F9401000  ldr      x0, [x0, #0x20]
//   0x48d434: B4000040  cbz      x0, #0x48d43c
//   0x48d438: 17FFC760  b        #0x47f1b8
//   0x48d43c: D65F03C0  ret      
uint64_t fde_func_14502_0x48d42c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0048D42CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9401000ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB4000040ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x17FFC760ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD65F03C0ULL ^ (4ULL << 32);
    return state ^ (state >> 29);
}

// FDE #14511 | PC: 0x48da30..0x48daec (188 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x48da30: D503233F  paciasp  
//   0x48da34: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x48da38: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x48da3c: 910003FD  mov      x29, sp
//   0x48da40: 90FFE334  adrp     x20, #0xf1000
//   0x48da44: 91360294  add      x20, x20, #0xd80
uint64_t fde_func_14511_0x48da30(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0048DA30ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9014FF4ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x90FFE334ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91360294ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91006000ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #14521 | PC: 0x48e4c4..0x48e564 (160 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x48e4c4: D503233F  paciasp  
//   0x48e4c8: D10183FF  sub      sp, sp, #0x60
//   0x48e4cc: A9047BFD  stp      x29, x30, [sp, #0x40]
//   0x48e4d0: A9054FF4  stp      x20, x19, [sp, #0x50]
//   0x48e4d4: 910103FD  add      x29, sp, #0x40
//   0x48e4d8: AA0003F3  mov      x19, x0
uint64_t fde_func_14521_0x48e4c4(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0048E4C4ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10183FFULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9047BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9054FF4ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910103FDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9404014ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x90FFE001ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #14530 | PC: 0x48e614..0x48e620 (12 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x48e614: D503245F  bti      c
//   0x48e618: D1006000  sub      x0, x0, #0x18
//   0x48e61c: 17FFFEC6  b        #0x48e134
uint64_t fde_func_14530_0x48e614(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0048E614ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD1006000ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x17FFFEC6ULL ^ (2ULL << 32);
    return state ^ (state >> 29);
}

// FDE #14540 | PC: 0x48e8d0..0x48e914 (68 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x48e8d0: D503233F  paciasp  
//   0x48e8d4: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x48e8d8: F9000BF3  str      x19, [sp, #0x10]
//   0x48e8dc: 910003FD  mov      x29, sp
//   0x48e8e0: F9401813  ldr      x19, [x0, #0x30]
//   0x48e8e4: B40000D3  cbz      x19, #0x48e8fc
uint64_t fde_func_14540_0x48e8d0(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0048E8D0ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF3ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9401813ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB40000D3ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0103E3ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA1303E0ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #14549 | PC: 0x48f0dc..0x48f0ec (16 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x48f0dc: D503245F  bti      c
//   0x48f0e0: AA0103E2  mov      x2, x1
//   0x48f0e4: 52800041  mov      w1, #2
//   0x48f0e8: 1400003F  b        #0x48f1e4
uint64_t fde_func_14549_0x48f0dc(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0048F0DCULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0103E2ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x52800041ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x1400003FULL ^ (3ULL << 32);
    return state ^ (state >> 29);
}

// FDE #14559 | PC: 0x48fce8..0x48fde8 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x48fce8: D503233F  paciasp  
//   0x48fcec: A9BA7BFD  stp      x29, x30, [sp, #-0x60]!
//   0x48fcf0: A9016FFC  stp      x28, x27, [sp, #0x10]
//   0x48fcf4: A90267FA  stp      x26, x25, [sp, #0x20]
//   0x48fcf8: A9035FF8  stp      x24, x23, [sp, #0x30]
//   0x48fcfc: A90457F6  stp      x22, x21, [sp, #0x40]
uint64_t fde_func_14559_0x48fce8(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0048FCE8ULL);
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

// FDE #14568 | PC: 0x4917e8..0x4918a8 (192 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x4917e8: D503233F  paciasp  
//   0x4917ec: D10343FF  sub      sp, sp, #0xd0
//   0x4917f0: A9097BFD  stp      x29, x30, [sp, #0x90]
//   0x4917f4: F90053F7  str      x23, [sp, #0xa0]
//   0x4917f8: A90B57F6  stp      x22, x21, [sp, #0xb0]
//   0x4917fc: A90C4FF4  stp      x20, x19, [sp, #0xc0]
uint64_t fde_func_14568_0x4917e8(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x004917E8ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10343FFULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9097BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF90053F7ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90B57F6ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90C4FF4ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910243FDULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD53BD056ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #14578 | PC: 0x492e40..0x492e58 (24 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x492e40: D503245F  bti      c
//   0x492e44: F9400400  ldr      x0, [x0, #8]
//   0x492e48: B4000060  cbz      x0, #0x492e54
//   0x492e4c: 52800021  mov      w1, #1
//   0x492e50: 17FFFA96  b        #0x4918a8
//   0x492e54: D65F03C0  ret      
uint64_t fde_func_14578_0x492e40(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00492E40ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400400ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB4000060ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x52800021ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x17FFFA96ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD65F03C0ULL ^ (5ULL << 32);
    return state ^ (state >> 29);
}

// FDE #14588 | PC: 0x4936c8..0x4937c8 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x4936c8: D503233F  paciasp  
//   0x4936cc: D10583FF  sub      sp, sp, #0x160
//   0x4936d0: A9107BFD  stp      x29, x30, [sp, #0x100]
//   0x4936d4: A9116FFC  stp      x28, x27, [sp, #0x110]
//   0x4936d8: A91267FA  stp      x26, x25, [sp, #0x120]
//   0x4936dc: A9135FF8  stp      x24, x23, [sp, #0x130]
uint64_t fde_func_14588_0x4936c8(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x004936C8ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10583FFULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9107BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9116FFCULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA91267FAULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9135FF8ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA91457F6ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9154FF4ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #14597 | PC: 0x4949a4..0x4949e4 (64 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x4949a4: D503245F  bti      c
//   0x4949a8: A940A408  ldp      x8, x9, [x0, #8]
//   0x4949ac: EB08013F  cmp      x9, x8
//   0x4949b0: 54000160  b.eq     #0x4949dc
//   0x4949b4: A9422809  ldp      x9, x10, [x0, #0x20]
//   0x4949b8: 9280090B  mov      x11, #-0x49
uint64_t fde_func_14597_0x4949a4(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x004949A4ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA940A408ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xEB08013FULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x54000160ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9422809ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9280090BULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x8B0A0129ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x5280092AULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #14607 | PC: 0x49549c..0x495540 (164 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x49549c: D503233F  paciasp  
//   0x4954a0: D10183FF  sub      sp, sp, #0x60
//   0x4954a4: A9047BFD  stp      x29, x30, [sp, #0x40]
//   0x4954a8: F9002BF3  str      x19, [sp, #0x50]
//   0x4954ac: 910103FD  add      x29, sp, #0x40
//   0x4954b0: F9427008  ldr      x8, [x0, #0x4e0]
uint64_t fde_func_14607_0x49549c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0049549CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10183FFULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9047BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9002BF3ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910103FDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9427008ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB4000428ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #14616 | PC: 0x495ae4..0x495bac (200 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x495ae4: D503233F  paciasp  
//   0x495ae8: D10143FF  sub      sp, sp, #0x50
//   0x495aec: A9037BFD  stp      x29, x30, [sp, #0x30]
//   0x495af0: A9044FF4  stp      x20, x19, [sp, #0x40]
//   0x495af4: 9100C3FD  add      x29, sp, #0x30
//   0x495af8: 52800028  mov      w8, #1
uint64_t fde_func_14616_0x495ae4(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00495AE4ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10143FFULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9037BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9044FF4ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9100C3FDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x52800028ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB9039408ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #14626 | PC: 0x496514..0x496528 (20 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x496514: D503245F  bti      c
//   0x496518: B0000A48  adrp     x8, #0x5df000
//   0x49651c: 91146108  add      x8, x8, #0x518
//   0x496520: C89FFD00  stlr     x0, [x8]
//   0x496524: D65F03C0  ret      
uint64_t fde_func_14626_0x496514(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00496514ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB0000A48ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91146108ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xC89FFD00ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD65F03C0ULL ^ (4ULL << 32);
    return state ^ (state >> 29);
}

// FDE #14635 | PC: 0x496de8..0x496ee8 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x496de8: D503233F  paciasp  
//   0x496dec: D10283FF  sub      sp, sp, #0xa0
//   0x496df0: A9067BFD  stp      x29, x30, [sp, #0x60]
//   0x496df4: A9075FF8  stp      x24, x23, [sp, #0x70]
//   0x496df8: A90857F6  stp      x22, x21, [sp, #0x80]
//   0x496dfc: A9094FF4  stp      x20, x19, [sp, #0x90]
uint64_t fde_func_14635_0x496de8(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00496DE8ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10283FFULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9067BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9075FF8ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90857F6ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9094FF4ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910183FDULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #14645 | PC: 0x4971e4..0x4971f0 (12 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x4971e4: D503245F  bti      c
//   0x4971e8: B9015801  str      w1, [x0, #0x158]
//   0x4971ec: D65F03C0  ret      
uint64_t fde_func_14645_0x4971e4(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x004971E4ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB9015801ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD65F03C0ULL ^ (2ULL << 32);
    return state ^ (state >> 29);
}

// FDE #14654 | PC: 0x497610..0x49761c (12 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x497610: D503245F  bti      c
//   0x497614: D1002000  sub      x0, x0, #8
//   0x497618: 17FFFDC0  b        #0x496d18
uint64_t fde_func_14654_0x497610(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00497610ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD1002000ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x17FFFDC0ULL ^ (2ULL << 32);
    return state ^ (state >> 29);
}

// FDE #14664 | PC: 0x497aa8..0x497afc (84 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x497aa8: D503233F  paciasp  
//   0x497aac: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x497ab0: F9000BF3  str      x19, [sp, #0x10]
//   0x497ab4: 910003FD  mov      x29, sp
//   0x497ab8: AA0003F3  mov      x19, x0
//   0x497abc: F0000888  adrp     x8, #0x5aa000
uint64_t fde_func_14664_0x497aa8(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00497AA8ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF3ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF0000888ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91050108ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF0000889ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #14673 | PC: 0x497cfc..0x497d08 (12 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x497cfc: D503245F  bti      c
//   0x497d00: F9400C08  ldr      x8, [x0, #0x18]
//   0x497d04: D65F03C0  ret      
uint64_t fde_func_14673_0x497cfc(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00497CFCULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400C08ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD65F03C0ULL ^ (2ULL << 32);
    return state ^ (state >> 29);
}

// FDE #14683 | PC: 0x497e6c..0x497ec8 (92 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x497e6c: D503245F  bti      c
//   0x497e70: F9400008  ldr      x8, [x0]
//   0x497e74: B40000A8  cbz      x8, #0x497e88
//   0x497e78: B9400809  ldr      w9, [x0, #8]
//   0x497e7c: 1100104A  add      w10, w2, #4
//   0x497e80: 6B09015F  cmp      w10, w9
uint64_t fde_func_14683_0x497e6c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00497E6CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400008ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB40000A8ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB9400809ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x1100104AULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x6B09015FULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x54000069ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x2A1F03E0ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #14692 | PC: 0x498544..0x498644 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x498544: D503233F  paciasp  
//   0x498548: D10483FF  sub      sp, sp, #0x120
//   0x49854c: A90E7BFD  stp      x29, x30, [sp, #0xe0]
//   0x498550: F9007BFC  str      x28, [sp, #0xf0]
//   0x498554: A91057F6  stp      x22, x21, [sp, #0x100]
//   0x498558: A9114FF4  stp      x20, x19, [sp, #0x110]
uint64_t fde_func_14692_0x498544(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00498544ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10483FFULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90E7BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9007BFCULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA91057F6ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9114FF4ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910383FDULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD53BD056ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #14702 | PC: 0x498e6c..0x498ea4 (56 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x498e6c: D503233F  paciasp  
//   0x498e70: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x498e74: F9000BF3  str      x19, [sp, #0x10]
//   0x498e78: 910003FD  mov      x29, sp
//   0x498e7c: 6F07E7E0  movi     v0.2d, #0xffffffffffffffff
//   0x498e80: AA0003F3  mov      x19, x0
uint64_t fde_func_14702_0x498e6c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00498E6CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF3ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x6F07E7E0ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91002000ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xFC020660ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #14711 | PC: 0x499938..0x499978 (64 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x499938: D503233F  paciasp  
//   0x49993c: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x499940: F9000BF3  str      x19, [sp, #0x10]
//   0x499944: 910003FD  mov      x29, sp
//   0x499948: AA0003F3  mov      x19, x0
//   0x49994c: 52800300  mov      w0, #0x18
uint64_t fde_func_14711_0x499938(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00499938ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF3ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x52800300ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x97F90B09ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003E8ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #14721 | PC: 0x49a160..0x49a1c4 (100 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x49a160: D503233F  paciasp  
//   0x49a164: D10083FF  sub      sp, sp, #0x20
//   0x49a168: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x49a16c: 910043FD  add      x29, sp, #0x10
//   0x49a170: A942AC0A  ldp      x10, x11, [x0, #0x28]
//   0x49a174: AA0003E8  mov      x8, x0
uint64_t fde_func_14721_0x49a160(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0049A160ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10083FFULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA942AC0AULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003E8ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9401009ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x8B8A0560ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #14730 | PC: 0x49a804..0x49a848 (68 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x49a804: D503245F  bti      c
//   0x49a808: B40001E0  cbz      x0, #0x49a844
//   0x49a80c: D503233F  paciasp  
//   0x49a810: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x49a814: F9000BF3  str      x19, [sp, #0x10]
//   0x49a818: 910003FD  mov      x29, sp
uint64_t fde_func_14730_0x49a804(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0049A804ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB40001E0ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE7BFDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF3ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9401C00ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #14740 | PC: 0x49b020..0x49b04c (44 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x49b020: D503233F  paciasp  
//   0x49b024: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x49b028: F9000BF3  str      x19, [sp, #0x10]
//   0x49b02c: 910003FD  mov      x29, sp
//   0x49b030: AA0003F3  mov      x19, x0
//   0x49b034: 97FFFFAE  bl       #0x49aeec
uint64_t fde_func_14740_0x49b020(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0049B020ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF3ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x97FFFFAEULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA1303E0ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400BF3ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #14749 | PC: 0x49bd58..0x49be58 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x49bd58: D503233F  paciasp  
//   0x49bd5c: D10643FF  sub      sp, sp, #0x190
//   0x49bd60: A9147BFD  stp      x29, x30, [sp, #0x140]
//   0x49bd64: A91567FC  stp      x28, x25, [sp, #0x150]
//   0x49bd68: A9165FF8  stp      x24, x23, [sp, #0x160]
//   0x49bd6c: A91757F6  stp      x22, x21, [sp, #0x170]
uint64_t fde_func_14749_0x49bd58(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0049BD58ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10643FFULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9147BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA91567FCULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9165FF8ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA91757F6ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9184FF4ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910503FDULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #14759 | PC: 0x49cd50..0x49cde4 (148 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x49cd50: D503233F  paciasp  
//   0x49cd54: D10103FF  sub      sp, sp, #0x40
//   0x49cd58: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x49cd5c: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x49cd60: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x49cd64: 910043FD  add      x29, sp, #0x10
uint64_t fde_func_14759_0x49cd50(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0049CD50ULL);
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

// FDE #14768 | PC: 0x49d530..0x49d618 (232 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x49d530: D503233F  paciasp  
//   0x49d534: D105C3FF  sub      sp, sp, #0x170
//   0x49d538: A9147BFD  stp      x29, x30, [sp, #0x140]
//   0x49d53c: A91557FC  stp      x28, x21, [sp, #0x150]
//   0x49d540: A9164FF4  stp      x20, x19, [sp, #0x160]
//   0x49d544: 910503FD  add      x29, sp, #0x140
uint64_t fde_func_14768_0x49d530(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0049D530ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD105C3FFULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9147BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA91557FCULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9164FF4ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910503FDULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD53BD055ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB0000869ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #14778 | PC: 0x49dcf0..0x49dd28 (56 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x49dcf0: D503233F  paciasp  
//   0x49dcf4: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x49dcf8: F9000BF3  str      x19, [sp, #0x10]
//   0x49dcfc: 910003FD  mov      x29, sp
//   0x49dd00: 39400008  ldrb     w8, [x0]
//   0x49dd04: 340000A8  cbz      w8, #0x49dd18
uint64_t fde_func_14778_0x49dcf0(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0049DCF0ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF3ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x39400008ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x340000A8ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91002000ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #14787 | PC: 0x49ee90..0x49eed8 (72 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x49ee90: D503233F  paciasp  
//   0x49ee94: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x49ee98: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x49ee9c: 910003FD  mov      x29, sp
//   0x49eea0: AA0003F3  mov      x19, x0
//   0x49eea4: AA0003F4  mov      x20, x0
uint64_t fde_func_14787_0x49ee90(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0049EE90ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9014FF4ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F4ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9103C000ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x90000868ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #14797 | PC: 0x49f78c..0x49f7d4 (72 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x49f78c: D503233F  paciasp  
//   0x49f790: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x49f794: F9000BF3  str      x19, [sp, #0x10]
//   0x49f798: 910003FD  mov      x29, sp
//   0x49f79c: 6F00E400  movi     v0.2d, #0000000000000000
//   0x49f7a0: AA0003F3  mov      x19, x0
uint64_t fde_func_14797_0x49f78c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0049F78CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF3ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x6F00E400ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x3C86D000ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAD018000ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #14806 | PC: 0x49f9f0..0x49f9fc (12 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x49f9f0: D503245F  bti      c
//   0x49f9f4: 91060000  add      x0, x0, #0x180
//   0x49f9f8: 17FCE3ED  b        #0x3d89ac
uint64_t fde_func_14806_0x49f9f0(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0049F9F0ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91060000ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x17FCE3EDULL ^ (2ULL << 32);
    return state ^ (state >> 29);
}

// FDE #14816 | PC: 0x4a0ff0..0x4a1080 (144 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x4a0ff0: D503233F  paciasp  
//   0x4a0ff4: A9BD7BFD  stp      x29, x30, [sp, #-0x30]!
//   0x4a0ff8: F9000BF5  str      x21, [sp, #0x10]
//   0x4a0ffc: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x4a1000: 910003FD  mov      x29, sp
//   0x4a1004: AA0003F5  mov      x21, x0
uint64_t fde_func_14816_0x4a0ff0(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x004A0FF0ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BD7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF5ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9024FF4ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F5ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x97FFED75ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #14825 | PC: 0x4a169c..0x4a179c (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x4a169c: D503233F  paciasp  
//   0x4a16a0: D10703FF  sub      sp, sp, #0x1c0
//   0x4a16a4: A9167BFD  stp      x29, x30, [sp, #0x160]
//   0x4a16a8: F900BBFC  str      x28, [sp, #0x170]
//   0x4a16ac: A91867FA  stp      x26, x25, [sp, #0x180]
//   0x4a16b0: A9195FF8  stp      x24, x23, [sp, #0x190]
uint64_t fde_func_14825_0x4a169c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x004A169CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10703FFULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9167BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF900BBFCULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA91867FAULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9195FF8ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA91A57F6ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA91B4FF4ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #14835 | PC: 0x4a2200..0x4a222c (44 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x4a2200: D503233F  paciasp  
//   0x4a2204: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x4a2208: F9000BF3  str      x19, [sp, #0x10]
//   0x4a220c: 910003FD  mov      x29, sp
//   0x4a2210: AA0003F3  mov      x19, x0
//   0x4a2214: 94000006  bl       #0x4a222c
uint64_t fde_func_14835_0x4a2200(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x004A2200ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF3ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x94000006ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB940E260ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400BF3ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #14844 | PC: 0x4a31e4..0x4a31f0 (12 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x4a31e4: D503245F  bti      c
//   0x4a31e8: 2A0103E0  mov      w0, w1
//   0x4a31ec: D65F03C0  ret      
uint64_t fde_func_14844_0x4a31e4(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x004A31E4ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x2A0103E0ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD65F03C0ULL ^ (2ULL << 32);
    return state ^ (state >> 29);
}

// FDE #14854 | PC: 0x4a4070..0x4a4158 (232 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x4a4070: D503233F  paciasp  
//   0x4a4074: D105C3FF  sub      sp, sp, #0x170
//   0x4a4078: A9147BFD  stp      x29, x30, [sp, #0x140]
//   0x4a407c: A91557FC  stp      x28, x21, [sp, #0x150]
//   0x4a4080: A9164FF4  stp      x20, x19, [sp, #0x160]
//   0x4a4084: 910503FD  add      x29, sp, #0x140
uint64_t fde_func_14854_0x4a4070(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x004A4070ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD105C3FFULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9147BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA91557FCULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9164FF4ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910503FDULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD53BD055ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD0000829ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #14863 | PC: 0x4a4c84..0x4a4d20 (156 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x4a4c84: D503233F  paciasp  
//   0x4a4c88: D10183FF  sub      sp, sp, #0x60
//   0x4a4c8c: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x4a4c90: F9001BF7  str      x23, [sp, #0x30]
//   0x4a4c94: A90457F6  stp      x22, x21, [sp, #0x40]
//   0x4a4c98: A9054FF4  stp      x20, x19, [sp, #0x50]
uint64_t fde_func_14863_0x4a4c84(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x004A4C84ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10183FFULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9027BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9001BF7ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90457F6ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9054FF4ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910083FDULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9100C015ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #14873 | PC: 0x4a5380..0x4a5480 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x4a5380: D503233F  paciasp  
//   0x4a5384: D10603FF  sub      sp, sp, #0x180
//   0x4a5388: A9147BFD  stp      x29, x30, [sp, #0x140]
//   0x4a538c: A9155FFC  stp      x28, x23, [sp, #0x150]
//   0x4a5390: A91657F6  stp      x22, x21, [sp, #0x160]
//   0x4a5394: A9174FF4  stp      x20, x19, [sp, #0x170]
uint64_t fde_func_14873_0x4a5380(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x004A5380ULL);
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

// FDE #14883 | PC: 0x4a6044..0x4a6140 (252 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x4a6044: D503233F  paciasp  
//   0x4a6048: D10183FF  sub      sp, sp, #0x60
//   0x4a604c: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x4a6050: A9035FF8  stp      x24, x23, [sp, #0x30]
//   0x4a6054: A90457F6  stp      x22, x21, [sp, #0x40]
//   0x4a6058: A9054FF4  stp      x20, x19, [sp, #0x50]
uint64_t fde_func_14883_0x4a6044(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x004A6044ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10183FFULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9027BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9035FF8ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90457F6ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9054FF4ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910083FDULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0203F4ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #14892 | PC: 0x4a6fd4..0x4a70d4 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x4a6fd4: D503233F  paciasp  
//   0x4a6fd8: A9BC7BFD  stp      x29, x30, [sp, #-0x40]!
//   0x4a6fdc: F9000BF7  str      x23, [sp, #0x10]
//   0x4a6fe0: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x4a6fe4: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x4a6fe8: 910003FD  mov      x29, sp
uint64_t fde_func_14892_0x4a6fd4(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x004A6FD4ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BC7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF7ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90257F6ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9034FF4ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB9400016ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #14902 | PC: 0x4a74ac..0x4a74c4 (24 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x4a74ac: D503245F  bti      c
//   0x4a74b0: 39404008  ldrb     w8, [x0, #0x10]
//   0x4a74b4: 34000048  cbz      w8, #0x4a74bc
//   0x4a74b8: D65F03C0  ret      
//   0x4a74bc: 91044000  add      x0, x0, #0x110
//   0x4a74c0: 17FFFEC5  b        #0x4a6fd4
uint64_t fde_func_14902_0x4a74ac(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x004A74ACULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x39404008ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x34000048ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD65F03C0ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91044000ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x17FFFEC5ULL ^ (5ULL << 32);
    return state ^ (state >> 29);
}

// FDE #14911 | PC: 0x4a7718..0x4a7744 (44 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x4a7718: D503233F  paciasp  
//   0x4a771c: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x4a7720: F9000BF3  str      x19, [sp, #0x10]
//   0x4a7724: 910003FD  mov      x29, sp
//   0x4a7728: AA0003F3  mov      x19, x0
//   0x4a772c: 97FFFFE5  bl       #0x4a76c0
uint64_t fde_func_14911_0x4a7718(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x004A7718ULL);
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

// FDE #14921 | PC: 0x4a836c..0x4a8378 (12 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x4a836c: D503245F  bti      c
//   0x4a8370: F9002401  str      x1, [x0, #0x48]
//   0x4a8374: D65F03C0  ret      
uint64_t fde_func_14921_0x4a836c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x004A836CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9002401ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD65F03C0ULL ^ (2ULL << 32);
    return state ^ (state >> 29);
}

// FDE #14930 | PC: 0x4a86c0..0x4a8724 (100 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x4a86c0: D503233F  paciasp  
//   0x4a86c4: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x4a86c8: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x4a86cc: 910003FD  mov      x29, sp
//   0x4a86d0: F9400408  ldr      x8, [x0, #8]
//   0x4a86d4: B9400108  ldr      w8, [x8]
uint64_t fde_func_14930_0x4a86c0(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x004A86C0ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9014FF4ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400408ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB9400108ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x340001E8ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0203F3ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #14940 | PC: 0x4a8b24..0x4a8c24 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x4a8b24: D503233F  paciasp  
//   0x4a8b28: D10603FF  sub      sp, sp, #0x180
//   0x4a8b2c: A9147BFD  stp      x29, x30, [sp, #0x140]
//   0x4a8b30: F900ABFC  str      x28, [sp, #0x150]
//   0x4a8b34: A91657F6  stp      x22, x21, [sp, #0x160]
//   0x4a8b38: A9174FF4  stp      x20, x19, [sp, #0x170]
uint64_t fde_func_14940_0x4a8b24(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x004A8B24ULL);
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

// FDE #14949 | PC: 0x4a8efc..0x4a8ffc (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x4a8efc: D503233F  paciasp  
//   0x4a8f00: D10283FF  sub      sp, sp, #0xa0
//   0x4a8f04: A9057BFD  stp      x29, x30, [sp, #0x50]
//   0x4a8f08: A90667FA  stp      x26, x25, [sp, #0x60]
//   0x4a8f0c: A9075FF8  stp      x24, x23, [sp, #0x70]
//   0x4a8f10: A90857F6  stp      x22, x21, [sp, #0x80]
uint64_t fde_func_14949_0x4a8efc(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x004A8EFCULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10283FFULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9057BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90667FAULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9075FF8ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90857F6ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9094FF4ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910143FDULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #14959 | PC: 0x4a9aa4..0x4a9ba4 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x4a9aa4: D503233F  paciasp  
//   0x4a9aa8: D10283FF  sub      sp, sp, #0xa0
//   0x4a9aac: A9057BFD  stp      x29, x30, [sp, #0x50]
//   0x4a9ab0: F90033F9  str      x25, [sp, #0x60]
//   0x4a9ab4: A9075FF8  stp      x24, x23, [sp, #0x70]
//   0x4a9ab8: A90857F6  stp      x22, x21, [sp, #0x80]
uint64_t fde_func_14959_0x4a9aa4(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x004A9AA4ULL);
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

// FDE #14968 | PC: 0x4aa104..0x4aa204 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x4aa104: D503233F  paciasp  
//   0x4aa108: D10283FF  sub      sp, sp, #0xa0
//   0x4aa10c: A9057BFD  stp      x29, x30, [sp, #0x50]
//   0x4aa110: F90033F9  str      x25, [sp, #0x60]
//   0x4aa114: A9075FF8  stp      x24, x23, [sp, #0x70]
//   0x4aa118: A90857F6  stp      x22, x21, [sp, #0x80]
uint64_t fde_func_14968_0x4aa104(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x004AA104ULL);
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

// FDE #14978 | PC: 0x4aaf10..0x4ab010 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x4aaf10: D503233F  paciasp  
//   0x4aaf14: D102C3FF  sub      sp, sp, #0xb0
//   0x4aaf18: A9077BFD  stp      x29, x30, [sp, #0x70]
//   0x4aaf1c: A9085FF8  stp      x24, x23, [sp, #0x80]
//   0x4aaf20: A90957F6  stp      x22, x21, [sp, #0x90]
//   0x4aaf24: A90A4FF4  stp      x20, x19, [sp, #0xa0]
uint64_t fde_func_14978_0x4aaf10(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x004AAF10ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD102C3FFULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9077BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9085FF8ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90957F6ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90A4FF4ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9101C3FDULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0103F4ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #14987 | PC: 0x4ab9a4..0x4abaa4 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x4ab9a4: D503233F  paciasp  
//   0x4ab9a8: D10183FF  sub      sp, sp, #0x60
//   0x4ab9ac: A9037BFD  stp      x29, x30, [sp, #0x30]
//   0x4ab9b0: F90023F5  str      x21, [sp, #0x40]
//   0x4ab9b4: A9054FF4  stp      x20, x19, [sp, #0x50]
//   0x4ab9b8: 9100C3FD  add      x29, sp, #0x30
uint64_t fde_func_14987_0x4ab9a4(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x004AB9A4ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10183FFULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9037BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF90023F5ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9054FF4ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9100C3FDULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA94CD414ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910063E8ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #14997 | PC: 0x4ac774..0x4ac874 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x4ac774: D503233F  paciasp  
//   0x4ac778: D10383FF  sub      sp, sp, #0xe0
//   0x4ac77c: A9087BFD  stp      x29, x30, [sp, #0x80]
//   0x4ac780: A9096FFC  stp      x28, x27, [sp, #0x90]
//   0x4ac784: A90A67FA  stp      x26, x25, [sp, #0xa0]
//   0x4ac788: A90B5FF8  stp      x24, x23, [sp, #0xb0]
uint64_t fde_func_14997_0x4ac774(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x004AC774ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10383FFULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9087BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9096FFCULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90A67FAULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90B5FF8ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90C57F6ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90D4FF4ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #15006 | PC: 0x4ad808..0x4ad814 (12 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x4ad808: D503245F  bti      c
//   0x4ad80c: 528000A1  mov      w1, #5
//   0x4ad810: 17FFFE23  b        #0x4ad09c
uint64_t fde_func_15006_0x4ad808(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x004AD808ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x528000A1ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x17FFFE23ULL ^ (2ULL << 32);
    return state ^ (state >> 29);
}

// FDE #15016 | PC: 0x4adbf8..0x4adcb0 (184 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x4adbf8: D503233F  paciasp  
//   0x4adbfc: D10143FF  sub      sp, sp, #0x50
//   0x4adc00: A9037BFD  stp      x29, x30, [sp, #0x30]
//   0x4adc04: A9044FF4  stp      x20, x19, [sp, #0x40]
//   0x4adc08: 9100C3FD  add      x29, sp, #0x30
//   0x4adc0c: AA0003F3  mov      x19, x0
uint64_t fde_func_15016_0x4adbf8(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x004ADBF8ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10143FFULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9037BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9044FF4ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9100C3FDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x97F887A2ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400014ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #15025 | PC: 0x4ae460..0x4ae560 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x4ae460: D503233F  paciasp  
//   0x4ae464: D10343FF  sub      sp, sp, #0xd0
//   0x4ae468: A9077BFD  stp      x29, x30, [sp, #0x70]
//   0x4ae46c: F90043FB  str      x27, [sp, #0x80]
//   0x4ae470: A90967FA  stp      x26, x25, [sp, #0x90]
//   0x4ae474: A90A5FF8  stp      x24, x23, [sp, #0xa0]
uint64_t fde_func_15025_0x4ae460(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x004AE460ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10343FFULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9077BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF90043FBULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90967FAULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90A5FF8ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90B57F6ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90C4FF4ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #15035 | PC: 0x4ae994..0x4aea74 (224 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x4ae994: D503233F  paciasp  
//   0x4ae998: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x4ae99c: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x4ae9a0: 910003FD  mov      x29, sp
//   0x4ae9a4: 39404008  ldrb     w8, [x0, #0x10]
//   0x4ae9a8: 340000A8  cbz      w8, #0x4ae9bc
uint64_t fde_func_15035_0x4ae994(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x004AE994ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9014FF4ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x39404008ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x340000A8ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9414FF4ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA8C27BFDULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #15044 | PC: 0x4aede8..0x4aee68 (128 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x4aede8: D503233F  paciasp  
//   0x4aedec: A9BD7BFD  stp      x29, x30, [sp, #-0x30]!
//   0x4aedf0: F9000BF5  str      x21, [sp, #0x10]
//   0x4aedf4: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x4aedf8: 910003FD  mov      x29, sp
//   0x4aedfc: 900007E8  adrp     x8, #0x5aa000
uint64_t fde_func_15044_0x4aede8(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x004AEDE8ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BD7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF5ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9024FF4ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x900007E8ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91358108ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x900007E9ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #15054 | PC: 0x4af40c..0x4af418 (12 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x4af40c: D503245F  bti      c
//   0x4af410: D1020000  sub      x0, x0, #0x80
//   0x4af414: 17FFFFBF  b        #0x4af310
uint64_t fde_func_15054_0x4af40c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x004AF40CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD1020000ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x17FFFFBFULL ^ (2ULL << 32);
    return state ^ (state >> 29);
}

// FDE #15063 | PC: 0x4af75c..0x4af768 (12 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x4af75c: D503245F  bti      c
//   0x4af760: D1020000  sub      x0, x0, #0x80
//   0x4af764: 17FFFFDE  b        #0x4af6dc
uint64_t fde_func_15063_0x4af75c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x004AF75CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD1020000ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x17FFFFDEULL ^ (2ULL << 32);
    return state ^ (state >> 29);
}

// FDE #15073 | PC: 0x4afc3c..0x4afc48 (12 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x4afc3c: D503245F  bti      c
//   0x4afc40: 52800021  mov      w1, #1
//   0x4afc44: 140008C3  b        #0x4b1f50
uint64_t fde_func_15073_0x4afc3c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x004AFC3CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x52800021ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x140008C3ULL ^ (2ULL << 32);
    return state ^ (state >> 29);
}

// FDE #15082 | PC: 0x4afd18..0x4afd24 (12 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x4afd18: D503245F  bti      c
//   0x4afd1c: 52800181  mov      w1, #0xc
//   0x4afd20: 1400088C  b        #0x4b1f50
uint64_t fde_func_15082_0x4afd18(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x004AFD18ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x52800181ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x1400088CULL ^ (2ULL << 32);
    return state ^ (state >> 29);
}

// FDE #15092 | PC: 0x4b0130..0x4b0230 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x4b0130: D503233F  paciasp  
//   0x4b0134: D10183FF  sub      sp, sp, #0x60
//   0x4b0138: A9037BFD  stp      x29, x30, [sp, #0x30]
//   0x4b013c: A90457F6  stp      x22, x21, [sp, #0x40]
//   0x4b0140: A9054FF4  stp      x20, x19, [sp, #0x50]
//   0x4b0144: 9100C3FD  add      x29, sp, #0x30
uint64_t fde_func_15092_0x4b0130(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x004B0130ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10183FFULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9037BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90457F6ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9054FF4ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9100C3FDULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB9419808ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x7100091FULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #15101 | PC: 0x4b09c8..0x4b0ac8 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x4b09c8: D503245F  bti      c
//   0x4b09cc: 51000428  sub      w8, w1, #1
//   0x4b09d0: 7100391F  cmp      w8, #0xe
//   0x4b09d4: 540005C8  b.hi     #0x4b0a8c
//   0x4b09d8: 90FFDE69  adrp     x9, #0x7c000
//   0x4b09dc: 912C1929  add      x9, x9, #0xb06
uint64_t fde_func_15101_0x4b09c8(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x004B09C8ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x51000428ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x7100391FULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x540005C8ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x90FFDE69ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x912C1929ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x1000008AULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x3868692BULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #15111 | PC: 0x4b16f8..0x4b17f0 (248 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x4b16f8: D503233F  paciasp  
//   0x4b16fc: D10143FF  sub      sp, sp, #0x50
//   0x4b1700: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x4b1704: F9001BF5  str      x21, [sp, #0x30]
//   0x4b1708: A9044FF4  stp      x20, x19, [sp, #0x40]
//   0x4b170c: 910083FD  add      x29, sp, #0x20
uint64_t fde_func_15111_0x4b16f8(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x004B16F8ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10143FFULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9027BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9001BF5ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9044FF4ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910083FDULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x340000E2ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9444FF4ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #15120 | PC: 0x4b1a40..0x4b1a48 (8 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x4b1a40: D503245F  bti      c
//   0x4b1a44: 17FFFD87  b        #0x4b1060
uint64_t fde_func_15120_0x4b1a40(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x004B1A40ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x17FFFD87ULL ^ (1ULL << 32);
    return state ^ (state >> 29);
}

// FDE #15130 | PC: 0x4b1ab4..0x4b1ac0 (12 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x4b1ab4: D503245F  bti      c
//   0x4b1ab8: D1054000  sub      x0, x0, #0x150
//   0x4b1abc: 17FFFFA8  b        #0x4b195c
uint64_t fde_func_15130_0x4b1ab4(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x004B1AB4ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD1054000ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x17FFFFA8ULL ^ (2ULL << 32);
    return state ^ (state >> 29);
}

// FDE #15139 | PC: 0x4b1de0..0x4b1e00 (32 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x4b1de0: D503245F  bti      c
//   0x4b1de4: 91016008  add      x8, x0, #0x58
//   0x4b1de8: 08DFFD08  ldarb    w8, [x8]
//   0x4b1dec: 37000048  tbnz     w8, #0, #0x4b1df4
//   0x4b1df0: D65F03C0  ret      
//   0x4b1df4: 91066021  add      x1, x1, #0x198
uint64_t fde_func_15139_0x4b1de0(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x004B1DE0ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91016008ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x08DFFD08ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x37000048ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD65F03C0ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91066021ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB9405000ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x14000001ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #15149 | PC: 0x4b254c..0x4b2558 (12 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x4b254c: D503245F  bti      c
//   0x4b2550: D1002000  sub      x0, x0, #8
//   0x4b2554: 17FFFFD6  b        #0x4b24ac
uint64_t fde_func_15149_0x4b254c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x004B254CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD1002000ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x17FFFFD6ULL ^ (2ULL << 32);
    return state ^ (state >> 29);
}

// FDE #15158 | PC: 0x4b2740..0x4b2758 (24 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x4b2740: D503245F  bti      c
//   0x4b2744: 7100283F  cmp      w1, #0xa
//   0x4b2748: 54000061  b.ne     #0x4b2754
//   0x4b274c: B9414401  ldr      w1, [x0, #0x144]
//   0x4b2750: 14000002  b        #0x4b2758
//   0x4b2754: D65F03C0  ret      
uint64_t fde_func_15158_0x4b2740(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x004B2740ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x7100283FULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x54000061ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB9414401ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x14000002ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD65F03C0ULL ^ (5ULL << 32);
    return state ^ (state >> 29);
}

// FDE #15168 | PC: 0x4b28a4..0x4b2918 (116 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x4b28a4: D503233F  paciasp  
//   0x4b28a8: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x4b28ac: F9000BF3  str      x19, [sp, #0x10]
//   0x4b28b0: 910003FD  mov      x29, sp
//   0x4b28b4: F0FFDF41  adrp     x1, #0x9d000
//   0x4b28b8: 912B8021  add      x1, x1, #0xae0
uint64_t fde_func_15168_0x4b28a4(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x004B28A4ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF3ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF0FFDF41ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x912B8021ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x97F475E6ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #15178 | PC: 0x4b357c..0x4b35f4 (120 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x4b357c: D503233F  paciasp  
//   0x4b3580: A9BB7BFD  stp      x29, x30, [sp, #-0x50]!
//   0x4b3584: F9000BF9  str      x25, [sp, #0x10]
//   0x4b3588: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x4b358c: A90357F6  stp      x22, x21, [sp, #0x30]
//   0x4b3590: A9044FF4  stp      x20, x19, [sp, #0x40]
uint64_t fde_func_15178_0x4b357c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x004B357CULL);
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

// FDE #15187 | PC: 0x4b444c..0x4b454c (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x4b444c: D503233F  paciasp  
//   0x4b4450: A9BB7BFD  stp      x29, x30, [sp, #-0x50]!
//   0x4b4454: A90167FA  stp      x26, x25, [sp, #0x10]
//   0x4b4458: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x4b445c: A90357F6  stp      x22, x21, [sp, #0x30]
//   0x4b4460: A9044FF4  stp      x20, x19, [sp, #0x40]
uint64_t fde_func_15187_0x4b444c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x004B444CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BB7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90167FAULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9025FF8ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90357F6ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9044FF4ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91003C37ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #15197 | PC: 0x4b4968..0x4b4994 (44 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x4b4968: D503233F  paciasp  
//   0x4b496c: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x4b4970: F9000BF3  str      x19, [sp, #0x10]
//   0x4b4974: 910003FD  mov      x29, sp
//   0x4b4978: AA0003F3  mov      x19, x0
//   0x4b497c: 97FFFF7B  bl       #0x4b4768
uint64_t fde_func_15197_0x4b4968(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x004B4968ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF3ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x97FFFF7BULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA1303E0ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400BF3ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #15206 | PC: 0x4b4f2c..0x4b4f68 (60 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x4b4f2c: D503233F  paciasp  
//   0x4b4f30: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x4b4f34: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x4b4f38: 910003FD  mov      x29, sp
//   0x4b4f3c: AA0003F3  mov      x19, x0
//   0x4b4f40: 52800500  mov      w0, #0x28
uint64_t fde_func_15206_0x4b4f2c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x004B4F2CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9014FF4ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x52800500ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x97F89D8CULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x5280B581ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #15216 | PC: 0x4b5788..0x4b579c (20 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x4b5788: D503245F  bti      c
//   0x4b578c: D00007A8  adrp     x8, #0x5ab000
//   0x4b5790: 91178108  add      x8, x8, #0x5e0
//   0x4b5794: F8008408  str      x8, [x0], #8
//   0x4b5798: 17FFFC0A  b        #0x4b47c0
uint64_t fde_func_15216_0x4b5788(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x004B5788ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD00007A8ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91178108ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF8008408ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x17FFFC0AULL ^ (4ULL << 32);
    return state ^ (state >> 29);
}

uint64_t execute_fde_shard_4(uint32_t fde_idx, uint64_t a0, uint64_t a1) {
    switch (fde_idx) {
        case 11419: return fde_func_11419_0x3e02a0(a0, a1);
        case 11428: return fde_func_11428_0x3e100c(a0, a1);
        case 11438: return fde_func_11438_0x3e18b0(a0, a1);
        case 11447: return fde_func_11447_0x3e1c90(a0, a1);
        case 11457: return fde_func_11457_0x3e4824(a0, a1);
        case 11466: return fde_func_11466_0x3e4b00(a0, a1);
        case 11476: return fde_func_11476_0x3e4fb0(a0, a1);
        case 11485: return fde_func_11485_0x3e5310(a0, a1);
        case 11495: return fde_func_11495_0x3e5790(a0, a1);
        case 11504: return fde_func_11504_0x3e60e0(a0, a1);
        case 11514: return fde_func_11514_0x3e61e0(a0, a1);
        case 11523: return fde_func_11523_0x3e6e88(a0, a1);
        case 11533: return fde_func_11533_0x3e9354(a0, a1);
        case 11542: return fde_func_11542_0x3ea068(a0, a1);
        case 11552: return fde_func_11552_0x3eb020(a0, a1);
        case 11561: return fde_func_11561_0x3eb404(a0, a1);
        case 11571: return fde_func_11571_0x3ebbf0(a0, a1);
        case 11580: return fde_func_11580_0x3ec984(a0, a1);
        case 11590: return fde_func_11590_0x3ed950(a0, a1);
        case 11600: return fde_func_11600_0x3ee324(a0, a1);
        case 11609: return fde_func_11609_0x3ee924(a0, a1);
        case 11619: return fde_func_11619_0x3eec00(a0, a1);
        case 11628: return fde_func_11628_0x3ef460(a0, a1);
        case 11638: return fde_func_11638_0x3f05f0(a0, a1);
        case 11647: return fde_func_11647_0x3f0914(a0, a1);
        case 11657: return fde_func_11657_0x3f0bf4(a0, a1);
        case 11666: return fde_func_11666_0x3f10b4(a0, a1);
        case 11676: return fde_func_11676_0x3f1478(a0, a1);
        case 11685: return fde_func_11685_0x3f1928(a0, a1);
        case 11695: return fde_func_11695_0x3f27f8(a0, a1);
        case 11704: return fde_func_11704_0x3f2ef4(a0, a1);
        case 11714: return fde_func_11714_0x3f3afc(a0, a1);
        case 11723: return fde_func_11723_0x3f4374(a0, a1);
        case 11733: return fde_func_11733_0x3f4bac(a0, a1);
        case 11742: return fde_func_11742_0x3f5064(a0, a1);
        case 11752: return fde_func_11752_0x3f6004(a0, a1);
        case 11761: return fde_func_11761_0x3f676c(a0, a1);
        case 11771: return fde_func_11771_0x3f78b0(a0, a1);
        case 11780: return fde_func_11780_0x3f7eec(a0, a1);
        case 11790: return fde_func_11790_0x3f8704(a0, a1);
        case 11799: return fde_func_11799_0x3f8c9c(a0, a1);
        case 11809: return fde_func_11809_0x3f9484(a0, a1);
        case 11818: return fde_func_11818_0x3f9828(a0, a1);
        case 11828: return fde_func_11828_0x3fa2c4(a0, a1);
        case 11837: return fde_func_11837_0x3fa9d8(a0, a1);
        case 11847: return fde_func_11847_0x3fac28(a0, a1);
        case 11856: return fde_func_11856_0x3fae34(a0, a1);
        case 11866: return fde_func_11866_0x3fb174(a0, a1);
        case 11875: return fde_func_11875_0x3fb7cc(a0, a1);
        case 11885: return fde_func_11885_0x3fba7c(a0, a1);
        case 11895: return fde_func_11895_0x3fc060(a0, a1);
        case 11904: return fde_func_11904_0x3fc3a8(a0, a1);
        case 11914: return fde_func_11914_0x3fc798(a0, a1);
        case 11923: return fde_func_11923_0x3fcf68(a0, a1);
        case 11933: return fde_func_11933_0x3fd504(a0, a1);
        case 11942: return fde_func_11942_0x3fdb14(a0, a1);
        case 11952: return fde_func_11952_0x3ffbb4(a0, a1);
        case 11961: return fde_func_11961_0x401eec(a0, a1);
        case 11971: return fde_func_11971_0x4043c8(a0, a1);
        case 11980: return fde_func_11980_0x4045ac(a0, a1);
        case 11990: return fde_func_11990_0x404768(a0, a1);
        case 11999: return fde_func_11999_0x40498c(a0, a1);
        case 12009: return fde_func_12009_0x404be8(a0, a1);
        case 12018: return fde_func_12018_0x404e98(a0, a1);
        case 12028: return fde_func_12028_0x4050d8(a0, a1);
        case 12037: return fde_func_12037_0x405304(a0, a1);
        case 12047: return fde_func_12047_0x40556c(a0, a1);
        case 12056: return fde_func_12056_0x405790(a0, a1);
        case 12066: return fde_func_12066_0x405998(a0, a1);
        case 12075: return fde_func_12075_0x405ce8(a0, a1);
        case 12085: return fde_func_12085_0x405e64(a0, a1);
        case 12094: return fde_func_12094_0x405fc8(a0, a1);
        case 12104: return fde_func_12104_0x4061f4(a0, a1);
        case 12113: return fde_func_12113_0x406350(a0, a1);
        case 12123: return fde_func_12123_0x4066ec(a0, a1);
        case 12132: return fde_func_12132_0x406b90(a0, a1);
        case 12142: return fde_func_12142_0x406d50(a0, a1);
        case 12151: return fde_func_12151_0x4074dc(a0, a1);
        case 12161: return fde_func_12161_0x407a94(a0, a1);
        case 12170: return fde_func_12170_0x407ff0(a0, a1);
        case 12180: return fde_func_12180_0x4085d4(a0, a1);
        case 12189: return fde_func_12189_0x409064(a0, a1);
        case 12199: return fde_func_12199_0x409e04(a0, a1);
        case 12209: return fde_func_12209_0x40a6d8(a0, a1);
        case 12218: return fde_func_12218_0x40aa84(a0, a1);
        case 12228: return fde_func_12228_0x40b464(a0, a1);
        case 12237: return fde_func_12237_0x40ba58(a0, a1);
        case 12247: return fde_func_12247_0x40caac(a0, a1);
        case 12256: return fde_func_12256_0x40cbd0(a0, a1);
        case 12266: return fde_func_12266_0x40cdcc(a0, a1);
        case 12275: return fde_func_12275_0x40f078(a0, a1);
        case 12285: return fde_func_12285_0x40f5cc(a0, a1);
        case 12294: return fde_func_12294_0x40f6c8(a0, a1);
        case 12304: return fde_func_12304_0x40f808(a0, a1);
        case 12313: return fde_func_12313_0x40f91c(a0, a1);
        case 12323: return fde_func_12323_0x40facc(a0, a1);
        case 12332: return fde_func_12332_0x40fc18(a0, a1);
        case 12342: return fde_func_12342_0x40fd58(a0, a1);
        case 12351: return fde_func_12351_0x41001c(a0, a1);
        case 12361: return fde_func_12361_0x41018c(a0, a1);
        case 12370: return fde_func_12370_0x4102a0(a0, a1);
        case 12380: return fde_func_12380_0x4104a0(a0, a1);
        case 12389: return fde_func_12389_0x410664(a0, a1);
        case 12399: return fde_func_12399_0x410d64(a0, a1);
        case 12408: return fde_func_12408_0x4112c0(a0, a1);
        case 12418: return fde_func_12418_0x411824(a0, a1);
        case 12427: return fde_func_12427_0x412768(a0, a1);
        case 12437: return fde_func_12437_0x41a6c0(a0, a1);
        case 12446: return fde_func_12446_0x41ac48(a0, a1);
        case 12456: return fde_func_12456_0x41b6ac(a0, a1);
        case 12465: return fde_func_12465_0x41bdb0(a0, a1);
        case 12475: return fde_func_12475_0x41cb28(a0, a1);
        case 12484: return fde_func_12484_0x41d1b0(a0, a1);
        case 12494: return fde_func_12494_0x41d8a4(a0, a1);
        case 12504: return fde_func_12504_0x41fc38(a0, a1);
        case 12513: return fde_func_12513_0x42023c(a0, a1);
        case 12523: return fde_func_12523_0x420828(a0, a1);
        case 12532: return fde_func_12532_0x420894(a0, a1);
        case 12542: return fde_func_12542_0x421190(a0, a1);
        case 12551: return fde_func_12551_0x42155c(a0, a1);
        case 12561: return fde_func_12561_0x421908(a0, a1);
        case 12570: return fde_func_12570_0x422454(a0, a1);
        case 12580: return fde_func_12580_0x422b3c(a0, a1);
        case 12589: return fde_func_12589_0x423334(a0, a1);
        case 12599: return fde_func_12599_0x423710(a0, a1);
        case 12608: return fde_func_12608_0x424164(a0, a1);
        case 12618: return fde_func_12618_0x4253b8(a0, a1);
        case 12627: return fde_func_12627_0x425d00(a0, a1);
        case 12637: return fde_func_12637_0x425f54(a0, a1);
        case 12646: return fde_func_12646_0x4261e4(a0, a1);
        case 12656: return fde_func_12656_0x426e7c(a0, a1);
        case 12665: return fde_func_12665_0x4278ec(a0, a1);
        case 12675: return fde_func_12675_0x427c5c(a0, a1);
        case 12684: return fde_func_12684_0x4285ec(a0, a1);
        case 12694: return fde_func_12694_0x428e64(a0, a1);
        case 12703: return fde_func_12703_0x42a70c(a0, a1);
        case 12713: return fde_func_12713_0x42af64(a0, a1);
        case 12722: return fde_func_12722_0x42b9e0(a0, a1);
        case 12732: return fde_func_12732_0x42c798(a0, a1);
        case 12741: return fde_func_12741_0x42ca28(a0, a1);
        case 12751: return fde_func_12751_0x42d258(a0, a1);
        case 12760: return fde_func_12760_0x42e288(a0, a1);
        case 12770: return fde_func_12770_0x42e7c4(a0, a1);
        case 12779: return fde_func_12779_0x42ed08(a0, a1);
        case 12789: return fde_func_12789_0x42fa30(a0, a1);
        case 12799: return fde_func_12799_0x42fc24(a0, a1);
        case 12808: return fde_func_12808_0x430080(a0, a1);
        case 12818: return fde_func_12818_0x430348(a0, a1);
        case 12827: return fde_func_12827_0x430428(a0, a1);
        case 12837: return fde_func_12837_0x430644(a0, a1);
        case 12846: return fde_func_12846_0x4308b0(a0, a1);
        case 12856: return fde_func_12856_0x430bc0(a0, a1);
        case 12865: return fde_func_12865_0x430d78(a0, a1);
        case 12875: return fde_func_12875_0x4310b8(a0, a1);
        case 12884: return fde_func_12884_0x431790(a0, a1);
        case 12894: return fde_func_12894_0x431c9c(a0, a1);
        case 12903: return fde_func_12903_0x432364(a0, a1);
        case 12913: return fde_func_12913_0x432bb0(a0, a1);
        case 12922: return fde_func_12922_0x433074(a0, a1);
        case 12932: return fde_func_12932_0x433b10(a0, a1);
        case 12941: return fde_func_12941_0x434ddc(a0, a1);
        case 12951: return fde_func_12951_0x435188(a0, a1);
        case 12960: return fde_func_12960_0x435480(a0, a1);
        case 12970: return fde_func_12970_0x435ef8(a0, a1);
        case 12979: return fde_func_12979_0x43653c(a0, a1);
        case 12989: return fde_func_12989_0x436c2c(a0, a1);
        case 12998: return fde_func_12998_0x437490(a0, a1);
        case 13008: return fde_func_13008_0x437d30(a0, a1);
        case 13017: return fde_func_13017_0x4387a8(a0, a1);
        case 13027: return fde_func_13027_0x4397e0(a0, a1);
        case 13036: return fde_func_13036_0x439e9c(a0, a1);
        case 13046: return fde_func_13046_0x43ac64(a0, a1);
        case 13055: return fde_func_13055_0x43bc5c(a0, a1);
        case 13065: return fde_func_13065_0x43c9ec(a0, a1);
        case 13074: return fde_func_13074_0x43d5a4(a0, a1);
        case 13084: return fde_func_13084_0x43d6cc(a0, a1);
        case 13094: return fde_func_13094_0x43e0e8(a0, a1);
        case 13103: return fde_func_13103_0x43e3d0(a0, a1);
        case 13113: return fde_func_13113_0x43f068(a0, a1);
        case 13122: return fde_func_13122_0x43f978(a0, a1);
        case 13132: return fde_func_13132_0x4401e0(a0, a1);
        case 13141: return fde_func_13141_0x440f4c(a0, a1);
        case 13151: return fde_func_13151_0x4419c4(a0, a1);
        case 13160: return fde_func_13160_0x4425a0(a0, a1);
        case 13170: return fde_func_13170_0x442994(a0, a1);
        case 13179: return fde_func_13179_0x443530(a0, a1);
        case 13189: return fde_func_13189_0x4444cc(a0, a1);
        case 13198: return fde_func_13198_0x445190(a0, a1);
        case 13208: return fde_func_13208_0x445994(a0, a1);
        case 13217: return fde_func_13217_0x446108(a0, a1);
        case 13227: return fde_func_13227_0x446850(a0, a1);
        case 13236: return fde_func_13236_0x4489c0(a0, a1);
        case 13246: return fde_func_13246_0x44be60(a0, a1);
        case 13255: return fde_func_13255_0x44c924(a0, a1);
        case 13265: return fde_func_13265_0x44d048(a0, a1);
        case 13274: return fde_func_13274_0x44d95c(a0, a1);
        case 13284: return fde_func_13284_0x44ec24(a0, a1);
        case 13293: return fde_func_13293_0x44f154(a0, a1);
        case 13303: return fde_func_13303_0x44f794(a0, a1);
        case 13312: return fde_func_13312_0x451d88(a0, a1);
        case 13322: return fde_func_13322_0x4529d4(a0, a1);
        case 13331: return fde_func_13331_0x452d04(a0, a1);
        case 13341: return fde_func_13341_0x453148(a0, a1);
        case 13350: return fde_func_13350_0x453a84(a0, a1);
        case 13360: return fde_func_13360_0x453e38(a0, a1);
        case 13369: return fde_func_13369_0x45425c(a0, a1);
        case 13379: return fde_func_13379_0x454de0(a0, a1);
        case 13389: return fde_func_13389_0x455258(a0, a1);
        case 13398: return fde_func_13398_0x45569c(a0, a1);
        case 13408: return fde_func_13408_0x456a7c(a0, a1);
        case 13417: return fde_func_13417_0x457378(a0, a1);
        case 13427: return fde_func_13427_0x4577f8(a0, a1);
        case 13436: return fde_func_13436_0x457ec0(a0, a1);
        case 13446: return fde_func_13446_0x458d60(a0, a1);
        case 13455: return fde_func_13455_0x459ab4(a0, a1);
        case 13465: return fde_func_13465_0x45a3b8(a0, a1);
        case 13474: return fde_func_13474_0x45a6c0(a0, a1);
        case 13484: return fde_func_13484_0x45ada8(a0, a1);
        case 13493: return fde_func_13493_0x45b56c(a0, a1);
        case 13503: return fde_func_13503_0x45c078(a0, a1);
        case 13512: return fde_func_13512_0x45c614(a0, a1);
        case 13522: return fde_func_13522_0x45ca00(a0, a1);
        case 13531: return fde_func_13531_0x45ce14(a0, a1);
        case 13541: return fde_func_13541_0x45d820(a0, a1);
        case 13550: return fde_func_13550_0x45dff0(a0, a1);
        case 13560: return fde_func_13560_0x45e500(a0, a1);
        case 13569: return fde_func_13569_0x45e8f0(a0, a1);
        case 13579: return fde_func_13579_0x45ee14(a0, a1);
        case 13588: return fde_func_13588_0x45f1e0(a0, a1);
        case 13598: return fde_func_13598_0x45f6b8(a0, a1);
        case 13607: return fde_func_13607_0x45fa18(a0, a1);
        case 13617: return fde_func_13617_0x460064(a0, a1);
        case 13626: return fde_func_13626_0x46012c(a0, a1);
        case 13636: return fde_func_13636_0x46104c(a0, a1);
        case 13645: return fde_func_13645_0x4610e4(a0, a1);
        case 13655: return fde_func_13655_0x46115c(a0, a1);
        case 13664: return fde_func_13664_0x46133c(a0, a1);
        case 13674: return fde_func_13674_0x461f6c(a0, a1);
        case 13684: return fde_func_13684_0x462928(a0, a1);
        case 13693: return fde_func_13693_0x462ce0(a0, a1);
        case 13703: return fde_func_13703_0x4632bc(a0, a1);
        case 13712: return fde_func_13712_0x463c44(a0, a1);
        case 13722: return fde_func_13722_0x464430(a0, a1);
        case 13731: return fde_func_13731_0x464844(a0, a1);
        case 13741: return fde_func_13741_0x464d08(a0, a1);
        case 13750: return fde_func_13750_0x465238(a0, a1);
        case 13760: return fde_func_13760_0x465d2c(a0, a1);
        case 13769: return fde_func_13769_0x466808(a0, a1);
        case 13779: return fde_func_13779_0x467688(a0, a1);
        case 13788: return fde_func_13788_0x4680dc(a0, a1);
        case 13798: return fde_func_13798_0x468b34(a0, a1);
        case 13807: return fde_func_13807_0x469120(a0, a1);
        case 13817: return fde_func_13817_0x4698b4(a0, a1);
        case 13826: return fde_func_13826_0x46a2a0(a0, a1);
        case 13836: return fde_func_13836_0x46aba0(a0, a1);
        case 13845: return fde_func_13845_0x46b000(a0, a1);
        case 13855: return fde_func_13855_0x46ba00(a0, a1);
        case 13864: return fde_func_13864_0x46bd04(a0, a1);
        case 13874: return fde_func_13874_0x46c094(a0, a1);
        case 13883: return fde_func_13883_0x46c34c(a0, a1);
        case 13893: return fde_func_13893_0x46c6f4(a0, a1);
        case 13902: return fde_func_13902_0x46cbe8(a0, a1);
        case 13912: return fde_func_13912_0x46d210(a0, a1);
        case 13921: return fde_func_13921_0x46d4c4(a0, a1);
        case 13931: return fde_func_13931_0x46d958(a0, a1);
        case 13940: return fde_func_13940_0x46dd2c(a0, a1);
        case 13950: return fde_func_13950_0x46e1d4(a0, a1);
        case 13959: return fde_func_13959_0x46e54c(a0, a1);
        case 13969: return fde_func_13969_0x46ef6c(a0, a1);
        case 13979: return fde_func_13979_0x46f55c(a0, a1);
        case 13988: return fde_func_13988_0x46fc00(a0, a1);
        case 13998: return fde_func_13998_0x4701d4(a0, a1);
        case 14007: return fde_func_14007_0x470728(a0, a1);
        case 14017: return fde_func_14017_0x470db8(a0, a1);
        case 14026: return fde_func_14026_0x4710bc(a0, a1);
        case 14036: return fde_func_14036_0x471594(a0, a1);
        case 14045: return fde_func_14045_0x471cf4(a0, a1);
        case 14055: return fde_func_14055_0x472334(a0, a1);
        case 14064: return fde_func_14064_0x472798(a0, a1);
        case 14074: return fde_func_14074_0x473198(a0, a1);
        case 14083: return fde_func_14083_0x473a00(a0, a1);
        case 14093: return fde_func_14093_0x4744bc(a0, a1);
        case 14102: return fde_func_14102_0x475038(a0, a1);
        case 14112: return fde_func_14112_0x475d20(a0, a1);
        case 14121: return fde_func_14121_0x476330(a0, a1);
        case 14131: return fde_func_14131_0x477178(a0, a1);
        case 14140: return fde_func_14140_0x477f78(a0, a1);
        case 14150: return fde_func_14150_0x47943c(a0, a1);
        case 14159: return fde_func_14159_0x47a048(a0, a1);
        case 14169: return fde_func_14169_0x47a654(a0, a1);
        case 14178: return fde_func_14178_0x47ac78(a0, a1);
        case 14188: return fde_func_14188_0x47c284(a0, a1);
        case 14197: return fde_func_14197_0x47c7fc(a0, a1);
        case 14207: return fde_func_14207_0x47d858(a0, a1);
        case 14216: return fde_func_14216_0x47dcd0(a0, a1);
        case 14226: return fde_func_14226_0x47e1f0(a0, a1);
        case 14235: return fde_func_14235_0x47e790(a0, a1);
        case 14245: return fde_func_14245_0x47f190(a0, a1);
        case 14254: return fde_func_14254_0x480dac(a0, a1);
        case 14264: return fde_func_14264_0x481208(a0, a1);
        case 14274: return fde_func_14274_0x481fbc(a0, a1);
        case 14283: return fde_func_14283_0x482958(a0, a1);
        case 14293: return fde_func_14293_0x48321c(a0, a1);
        case 14302: return fde_func_14302_0x483510(a0, a1);
        case 14312: return fde_func_14312_0x484424(a0, a1);
        case 14321: return fde_func_14321_0x4847e4(a0, a1);
        case 14331: return fde_func_14331_0x48533c(a0, a1);
        case 14340: return fde_func_14340_0x486304(a0, a1);
        case 14350: return fde_func_14350_0x48662c(a0, a1);
        case 14359: return fde_func_14359_0x4879c0(a0, a1);
        case 14369: return fde_func_14369_0x488d30(a0, a1);
        case 14378: return fde_func_14378_0x489000(a0, a1);
        case 14388: return fde_func_14388_0x4892b0(a0, a1);
        case 14397: return fde_func_14397_0x489538(a0, a1);
        case 14407: return fde_func_14407_0x48a18c(a0, a1);
        case 14416: return fde_func_14416_0x48a5c8(a0, a1);
        case 14426: return fde_func_14426_0x48abdc(a0, a1);
        case 14435: return fde_func_14435_0x48af30(a0, a1);
        case 14445: return fde_func_14445_0x48b52c(a0, a1);
        case 14454: return fde_func_14454_0x48bcc0(a0, a1);
        case 14464: return fde_func_14464_0x48c118(a0, a1);
        case 14473: return fde_func_14473_0x48c474(a0, a1);
        case 14483: return fde_func_14483_0x48cddc(a0, a1);
        case 14492: return fde_func_14492_0x48d130(a0, a1);
        case 14502: return fde_func_14502_0x48d42c(a0, a1);
        case 14511: return fde_func_14511_0x48da30(a0, a1);
        case 14521: return fde_func_14521_0x48e4c4(a0, a1);
        case 14530: return fde_func_14530_0x48e614(a0, a1);
        case 14540: return fde_func_14540_0x48e8d0(a0, a1);
        case 14549: return fde_func_14549_0x48f0dc(a0, a1);
        case 14559: return fde_func_14559_0x48fce8(a0, a1);
        case 14568: return fde_func_14568_0x4917e8(a0, a1);
        case 14578: return fde_func_14578_0x492e40(a0, a1);
        case 14588: return fde_func_14588_0x4936c8(a0, a1);
        case 14597: return fde_func_14597_0x4949a4(a0, a1);
        case 14607: return fde_func_14607_0x49549c(a0, a1);
        case 14616: return fde_func_14616_0x495ae4(a0, a1);
        case 14626: return fde_func_14626_0x496514(a0, a1);
        case 14635: return fde_func_14635_0x496de8(a0, a1);
        case 14645: return fde_func_14645_0x4971e4(a0, a1);
        case 14654: return fde_func_14654_0x497610(a0, a1);
        case 14664: return fde_func_14664_0x497aa8(a0, a1);
        case 14673: return fde_func_14673_0x497cfc(a0, a1);
        case 14683: return fde_func_14683_0x497e6c(a0, a1);
        case 14692: return fde_func_14692_0x498544(a0, a1);
        case 14702: return fde_func_14702_0x498e6c(a0, a1);
        case 14711: return fde_func_14711_0x499938(a0, a1);
        case 14721: return fde_func_14721_0x49a160(a0, a1);
        case 14730: return fde_func_14730_0x49a804(a0, a1);
        case 14740: return fde_func_14740_0x49b020(a0, a1);
        case 14749: return fde_func_14749_0x49bd58(a0, a1);
        case 14759: return fde_func_14759_0x49cd50(a0, a1);
        case 14768: return fde_func_14768_0x49d530(a0, a1);
        case 14778: return fde_func_14778_0x49dcf0(a0, a1);
        case 14787: return fde_func_14787_0x49ee90(a0, a1);
        case 14797: return fde_func_14797_0x49f78c(a0, a1);
        case 14806: return fde_func_14806_0x49f9f0(a0, a1);
        case 14816: return fde_func_14816_0x4a0ff0(a0, a1);
        case 14825: return fde_func_14825_0x4a169c(a0, a1);
        case 14835: return fde_func_14835_0x4a2200(a0, a1);
        case 14844: return fde_func_14844_0x4a31e4(a0, a1);
        case 14854: return fde_func_14854_0x4a4070(a0, a1);
        case 14863: return fde_func_14863_0x4a4c84(a0, a1);
        case 14873: return fde_func_14873_0x4a5380(a0, a1);
        case 14883: return fde_func_14883_0x4a6044(a0, a1);
        case 14892: return fde_func_14892_0x4a6fd4(a0, a1);
        case 14902: return fde_func_14902_0x4a74ac(a0, a1);
        case 14911: return fde_func_14911_0x4a7718(a0, a1);
        case 14921: return fde_func_14921_0x4a836c(a0, a1);
        case 14930: return fde_func_14930_0x4a86c0(a0, a1);
        case 14940: return fde_func_14940_0x4a8b24(a0, a1);
        case 14949: return fde_func_14949_0x4a8efc(a0, a1);
        case 14959: return fde_func_14959_0x4a9aa4(a0, a1);
        case 14968: return fde_func_14968_0x4aa104(a0, a1);
        case 14978: return fde_func_14978_0x4aaf10(a0, a1);
        case 14987: return fde_func_14987_0x4ab9a4(a0, a1);
        case 14997: return fde_func_14997_0x4ac774(a0, a1);
        case 15006: return fde_func_15006_0x4ad808(a0, a1);
        case 15016: return fde_func_15016_0x4adbf8(a0, a1);
        case 15025: return fde_func_15025_0x4ae460(a0, a1);
        case 15035: return fde_func_15035_0x4ae994(a0, a1);
        case 15044: return fde_func_15044_0x4aede8(a0, a1);
        case 15054: return fde_func_15054_0x4af40c(a0, a1);
        case 15063: return fde_func_15063_0x4af75c(a0, a1);
        case 15073: return fde_func_15073_0x4afc3c(a0, a1);
        case 15082: return fde_func_15082_0x4afd18(a0, a1);
        case 15092: return fde_func_15092_0x4b0130(a0, a1);
        case 15101: return fde_func_15101_0x4b09c8(a0, a1);
        case 15111: return fde_func_15111_0x4b16f8(a0, a1);
        case 15120: return fde_func_15120_0x4b1a40(a0, a1);
        case 15130: return fde_func_15130_0x4b1ab4(a0, a1);
        case 15139: return fde_func_15139_0x4b1de0(a0, a1);
        case 15149: return fde_func_15149_0x4b254c(a0, a1);
        case 15158: return fde_func_15158_0x4b2740(a0, a1);
        case 15168: return fde_func_15168_0x4b28a4(a0, a1);
        case 15178: return fde_func_15178_0x4b357c(a0, a1);
        case 15187: return fde_func_15187_0x4b444c(a0, a1);
        case 15197: return fde_func_15197_0x4b4968(a0, a1);
        case 15206: return fde_func_15206_0x4b4f2c(a0, a1);
        case 15216: return fde_func_15216_0x4b5788(a0, a1);
        default: return 0ULL;
    }
}

} // namespace sscronet