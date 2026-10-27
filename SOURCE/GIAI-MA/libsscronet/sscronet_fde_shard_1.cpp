// ============================================================================
// Clean-Room C++17 Reconstructed AArch64 FDE Shard 1/5 for libsscronet.so
// Phân mảnh hàm FDE AArch64 C++17 sạch 1/5 cho libsscronet.so
// Covers 400 FDEs (indices 0..399 of 2,000 sampled from 19,032 FDEs @ 0x0f1dd8)
// ============================================================================
#include "sscronet_core.h"

namespace sscronet {

// FDE #00000 | PC: 0x1c6edc..0x1c6eec (16 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x1c6edc: D503245F  bti      c
//   0x1c6ee0: 90001E40  adrp     x0, #0x58e000
//   0x1c6ee4: 911B4000  add      x0, x0, #0x6d0
//   0x1c6ee8: 140EFF90  b        #0x586d28
uint64_t fde_func_00000_0x1c6edc(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x001C6EDCULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x90001E40ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x911B4000ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x140EFF90ULL ^ (3ULL << 32);
    return state ^ (state >> 29);
}

// FDE #00009 | PC: 0x1c71f4..0x1c72f4 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x1c71f4: D503233F  paciasp  
//   0x1c71f8: F81C0FFE  str      x30, [sp, #-0x40]!
//   0x1c71fc: A9015FF8  stp      x24, x23, [sp, #0x10]
//   0x1c7200: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x1c7204: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x1c7208: 91004008  add      x8, x0, #0x10
uint64_t fde_func_00009_0x1c71f4(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x001C71F4ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81C0FFEULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9015FF8ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90257F6ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9034FF4ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91004008ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xC8DFFD16ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #00019 | PC: 0x1c7ca4..0x1c7d48 (164 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x1c7ca4: D503233F  paciasp  
//   0x1c7ca8: D10183FF  sub      sp, sp, #0x60
//   0x1c7cac: A9037BFD  stp      x29, x30, [sp, #0x30]
//   0x1c7cb0: A90457F6  stp      x22, x21, [sp, #0x40]
//   0x1c7cb4: A9054FF4  stp      x20, x19, [sp, #0x50]
//   0x1c7cb8: 9100C3FD  add      x29, sp, #0x30
uint64_t fde_func_00019_0x1c7ca4(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x001C7CA4ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10183FFULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9037BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90457F6ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9054FF4ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9100C3FDULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x94045D39ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #00028 | PC: 0x1c80ac..0x1c80c8 (28 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x1c80ac: D503245F  bti      c
//   0x1c80b0: AA0003E8  mov      x8, x0
//   0x1c80b4: F9400000  ldr      x0, [x0]
//   0x1c80b8: B4000060  cbz      x0, #0x1c80c4
//   0x1c80bc: F9000500  str      x0, [x8, #8]
//   0x1c80c0: 1404513D  b        #0x2dc5b4
uint64_t fde_func_00028_0x1c80ac(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x001C80ACULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003E8ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400000ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB4000060ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000500ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x1404513DULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD65F03C0ULL ^ (6ULL << 32);
    return state ^ (state >> 29);
}

// FDE #00038 | PC: 0x1c8414..0x1c8514 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x1c8414: D503233F  paciasp  
//   0x1c8418: D102C3FF  sub      sp, sp, #0xb0
//   0x1c841c: A9067BFD  stp      x29, x30, [sp, #0x60]
//   0x1c8420: F9003BF9  str      x25, [sp, #0x70]
//   0x1c8424: A9085FF8  stp      x24, x23, [sp, #0x80]
//   0x1c8428: A90957F6  stp      x22, x21, [sp, #0x90]
uint64_t fde_func_00038_0x1c8414(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x001C8414ULL);
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

// FDE #00047 | PC: 0x1c8764..0x1c87c0 (92 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x1c8764: D503233F  paciasp  
//   0x1c8768: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x1c876c: 910003FD  mov      x29, sp
//   0x1c8770: B201F3E8  mov      x8, #-0x5555555555555556
//   0x1c8774: F2E15548  movk     x8, #0xaaa, lsl #48
//   0x1c8778: EB08003F  cmp      x1, x8
uint64_t fde_func_00047_0x1c8764(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x001C8764ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BF7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB201F3E8ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF2E15548ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xEB08003FULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x54000208ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400809ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #00057 | PC: 0x1c8ae0..0x1c8b74 (148 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x1c8ae0: D503233F  paciasp  
//   0x1c8ae4: D10103FF  sub      sp, sp, #0x40
//   0x1c8ae8: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x1c8aec: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x1c8af0: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x1c8af4: 910043FD  add      x29, sp, #0x10
uint64_t fde_func_00057_0x1c8ae0(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x001C8AE0ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10103FFULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90257F6ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9034FF4ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0103F5ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0103F4ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #00066 | PC: 0x1c8dc8..0x1c8dfc (52 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x1c8dc8: D503233F  paciasp  
//   0x1c8dcc: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x1c8dd0: F9000BF3  str      x19, [sp, #0x10]
//   0x1c8dd4: 910003FD  mov      x29, sp
//   0x1c8dd8: AA0203F3  mov      x19, x2
//   0x1c8ddc: 94000008  bl       #0x1c8dfc
uint64_t fde_func_00066_0x1c8dc8(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x001C8DC8ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF3ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0203F3ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x94000008ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910063A1ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000FB3ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #00076 | PC: 0x1c96f4..0x1c9718 (36 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x1c96f4: D503245F  bti      c
//   0x1c96f8: 39412008  ldrb     w8, [x0, #0x48]
//   0x1c96fc: 34000048  cbz      w8, #0x1c9704
//   0x1c9700: D65F03C0  ret      
//   0x1c9704: F9402008  ldr      x8, [x0, #0x40]
//   0x1c9708: F9402D00  ldr      x0, [x8, #0x58]
uint64_t fde_func_00076_0x1c96f4(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x001C96F4ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x39412008ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x34000048ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD65F03C0ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9402008ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9402D00ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400008ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400D10ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #00085 | PC: 0x1c9d40..0x1c9e0c (204 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x1c9d40: D503233F  paciasp  
//   0x1c9d44: D101C3FF  sub      sp, sp, #0x70
//   0x1c9d48: A9037BFD  stp      x29, x30, [sp, #0x30]
//   0x1c9d4c: A9045FF8  stp      x24, x23, [sp, #0x40]
//   0x1c9d50: A90557F6  stp      x22, x21, [sp, #0x50]
//   0x1c9d54: A9064FF4  stp      x20, x19, [sp, #0x60]
uint64_t fde_func_00085_0x1c9d40(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x001C9D40ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD101C3FFULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9037BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9045FF8ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90557F6ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9064FF4ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9100C3FDULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F6ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #00095 | PC: 0x1ca28c..0x1ca2b0 (36 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x1ca28c: D503245F  bti      c
//   0x1ca290: D37DFC08  lsr      x8, x0, #0x3d
//   0x1ca294: B5000068  cbnz     x8, #0x1ca2a0
//   0x1ca298: D37DF000  lsl      x0, x0, #3
//   0x1ca29c: 140448B6  b        #0x2dc574
//   0x1ca2a0: D503233F  paciasp  
uint64_t fde_func_00095_0x1ca28c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x001CA28CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD37DFC08ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB5000068ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD37DF000ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x140448B6ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BF7BFDULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #00104 | PC: 0x1ca978..0x1caa78 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x1ca978: D503233F  paciasp  
//   0x1ca97c: A9BD7BFD  stp      x29, x30, [sp, #-0x30]!
//   0x1ca980: F9000BF5  str      x21, [sp, #0x10]
//   0x1ca984: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x1ca988: 910003FD  mov      x29, sp
//   0x1ca98c: F9400013  ldr      x19, [x0]
uint64_t fde_func_00104_0x1ca978(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x001CA978ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BD7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF5ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9024FF4ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400013ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF900001FULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB4000253ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #00114 | PC: 0x1cb1ac..0x1cb1fc (80 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x1cb1ac: D503233F  paciasp  
//   0x1cb1b0: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x1cb1b4: F9000BF3  str      x19, [sp, #0x10]
//   0x1cb1b8: 910003FD  mov      x29, sp
//   0x1cb1bc: F9400013  ldr      x19, [x0]
//   0x1cb1c0: F900001F  str      xzr, [x0]
uint64_t fde_func_00114_0x1cb1ac(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x001CB1ACULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF3ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400013ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF900001FULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB4000153ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91006260ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #00123 | PC: 0x1cb550..0x1cb598 (72 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x1cb550: D503245F  bti      c
//   0x1cb554: B24107E8  mov      x8, #-0x7fffffffffffffff
//   0x1cb558: 8B080029  add      x9, x1, x8
//   0x1cb55c: F100093F  cmp      x9, #2
//   0x1cb560: 540000E2  b.hs     #0x1cb57c
//   0x1cb564: 8B080008  add      x8, x0, x8
uint64_t fde_func_00123_0x1cb550(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x001CB550ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB24107E8ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x8B080029ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF100093FULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x540000E2ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x8B080008ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF100051FULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xFA419004ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #00133 | PC: 0x1cb9a4..0x1cba24 (128 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x1cb9a4: D503233F  paciasp  
//   0x1cb9a8: D10143FF  sub      sp, sp, #0x50
//   0x1cb9ac: A9037BFD  stp      x29, x30, [sp, #0x30]
//   0x1cb9b0: A9044FF4  stp      x20, x19, [sp, #0x40]
//   0x1cb9b4: 9100C3FD  add      x29, sp, #0x30
//   0x1cb9b8: AA0003F3  mov      x19, x0
uint64_t fde_func_00133_0x1cb9a4(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x001CB9A4ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10143FFULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9037BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9044FF4ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9100C3FDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x94044DFAULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F4ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #00142 | PC: 0x1ce1b0..0x1ce294 (228 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x1ce1b0: D503233F  paciasp  
//   0x1ce1b4: D10283FF  sub      sp, sp, #0xa0
//   0x1ce1b8: A9077BFD  stp      x29, x30, [sp, #0x70]
//   0x1ce1bc: A90857F6  stp      x22, x21, [sp, #0x80]
//   0x1ce1c0: A9094FF4  stp      x20, x19, [sp, #0x90]
//   0x1ce1c4: 9101C3FD  add      x29, sp, #0x70
uint64_t fde_func_00142_0x1ce1b0(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x001CE1B0ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10283FFULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9077BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90857F6ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9094FF4ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9101C3FDULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0203F3ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0103F4ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #00152 | PC: 0x1cee18..0x1ceed8 (192 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x1cee18: D503233F  paciasp  
//   0x1cee1c: D10203FF  sub      sp, sp, #0x80
//   0x1cee20: 6D032BEB  stp      d11, d10, [sp, #0x30]
//   0x1cee24: 6D0423E9  stp      d9, d8, [sp, #0x40]
//   0x1cee28: A9057BFD  stp      x29, x30, [sp, #0x50]
//   0x1cee2c: F90033F5  str      x21, [sp, #0x60]
uint64_t fde_func_00152_0x1cee18(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x001CEE18ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10203FFULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x6D032BEBULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x6D0423E9ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9057BFDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF90033F5ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9074FF4ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910143FDULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #00161 | PC: 0x1cf5e4..0x1cf6e4 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x1cf5e4: D503233F  paciasp  
//   0x1cf5e8: D10383FF  sub      sp, sp, #0xe0
//   0x1cf5ec: A90A7BFD  stp      x29, x30, [sp, #0xa0]
//   0x1cf5f0: A90B5FF8  stp      x24, x23, [sp, #0xb0]
//   0x1cf5f4: A90C57F6  stp      x22, x21, [sp, #0xc0]
//   0x1cf5f8: A90D4FF4  stp      x20, x19, [sp, #0xd0]
uint64_t fde_func_00161_0x1cf5e4(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x001CF5E4ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10383FFULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90A7BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90B5FF8ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90C57F6ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90D4FF4ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910283FDULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0503F3ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #00171 | PC: 0x1cfe64..0x1cfea0 (60 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x1cfe64: D503233F  paciasp  
//   0x1cfe68: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x1cfe6c: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x1cfe70: 910003FD  mov      x29, sp
//   0x1cfe74: AA0003F4  mov      x20, x0
//   0x1cfe78: AA0103E0  mov      x0, x1
uint64_t fde_func_00171_0x1cfe64(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x001CFE64ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9014FF4ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F4ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0103E0ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0103F3ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x940EDC16ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #00180 | PC: 0x1d015c..0x1d018c (48 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x1d015c: D503233F  paciasp  
//   0x1d0160: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x1d0164: F9000BF3  str      x19, [sp, #0x10]
//   0x1d0168: 910003FD  mov      x29, sp
//   0x1d016c: AA0003F3  mov      x19, x0
//   0x1d0170: 91006000  add      x0, x0, #0x18
uint64_t fde_func_00180_0x1d015c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x001D015CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF3ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91006000ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x940EDB47ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA1303E0ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #00190 | PC: 0x1d0514..0x1d0538 (36 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x1d0514: D503245F  bti      c
//   0x1d0518: AA0003E8  mov      x8, x0
//   0x1d051c: 39400009  ldrb     w9, [x0]
//   0x1d0520: 37000089  tbnz     w9, #0, #0x1d0530
//   0x1d0524: 91000500  add      x0, x8, #1
//   0x1d0528: D341FD21  lsr      x1, x9, #1
uint64_t fde_func_00190_0x1d0514(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x001D0514ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003E8ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x39400009ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x37000089ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91000500ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD341FD21ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD65F03C0ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9408101ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #00199 | PC: 0x1d075c..0x1d084c (240 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x1d075c: D503233F  paciasp  
//   0x1d0760: D10183FF  sub      sp, sp, #0x60
//   0x1d0764: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x1d0768: F9001BF7  str      x23, [sp, #0x30]
//   0x1d076c: A90457F6  stp      x22, x21, [sp, #0x40]
//   0x1d0770: A9054FF4  stp      x20, x19, [sp, #0x50]
uint64_t fde_func_00199_0x1d075c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x001D075CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10183FFULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9027BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9001BF7ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90457F6ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9054FF4ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910083FDULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x12001C89ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #00209 | PC: 0x1d1bec..0x1d1c3c (80 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x1d1bec: D503233F  paciasp  
//   0x1d1bf0: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x1d1bf4: F9000BF3  str      x19, [sp, #0x10]
//   0x1d1bf8: 910003FD  mov      x29, sp
//   0x1d1bfc: F9400013  ldr      x19, [x0]
//   0x1d1c00: F900001F  str      xzr, [x0]
uint64_t fde_func_00209_0x1d1bec(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x001D1BECULL);
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

// FDE #00218 | PC: 0x1d1ef4..0x1d1fc4 (208 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x1d1ef4: D503233F  paciasp  
//   0x1d1ef8: A9BC7BFD  stp      x29, x30, [sp, #-0x40]!
//   0x1d1efc: A9015FF8  stp      x24, x23, [sp, #0x10]
//   0x1d1f00: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x1d1f04: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x1d1f08: 910003FD  mov      x29, sp
uint64_t fde_func_00218_0x1d1ef4(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x001D1EF4ULL);
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

// FDE #00228 | PC: 0x1d2550..0x1d257c (44 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x1d2550: D503245F  bti      c
//   0x1d2554: EB01001F  cmp      x0, x1
//   0x1d2558: 540000E0  b.eq     #0x1d2574
//   0x1d255c: 39400008  ldrb     w8, [x0]
//   0x1d2560: 6B22011F  cmp      w8, w2, uxtb
//   0x1d2564: 54000060  b.eq     #0x1d2570
uint64_t fde_func_00228_0x1d2550(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x001D2550ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xEB01001FULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x540000E0ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x39400008ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x6B22011FULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x54000060ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91000400ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x17FFFFFAULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #00237 | PC: 0x1d2768..0x1d2794 (44 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x1d2768: D503233F  paciasp  
//   0x1d276c: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x1d2770: F9000BF3  str      x19, [sp, #0x10]
//   0x1d2774: 910003FD  mov      x29, sp
//   0x1d2778: AA0003F3  mov      x19, x0
//   0x1d277c: 97FFFFF0  bl       #0x1d273c
uint64_t fde_func_00237_0x1d2768(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x001D2768ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF3ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x97FFFFF0ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA1303E0ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400BF3ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #00247 | PC: 0x1d2eec..0x1d2fd8 (236 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x1d2eec: D503233F  paciasp  
//   0x1d2ef0: A9BA7BFD  stp      x29, x30, [sp, #-0x60]!
//   0x1d2ef4: F9000BFB  str      x27, [sp, #0x10]
//   0x1d2ef8: A90267FA  stp      x26, x25, [sp, #0x20]
//   0x1d2efc: A9035FF8  stp      x24, x23, [sp, #0x30]
//   0x1d2f00: A90457F6  stp      x22, x21, [sp, #0x40]
uint64_t fde_func_00247_0x1d2eec(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x001D2EECULL);
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

// FDE #00256 | PC: 0x1d32d4..0x1d3310 (60 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x1d32d4: D503245F  bti      c
//   0x1d32d8: A9412428  ldp      x8, x9, [x1, #0x10]
//   0x1d32dc: EB09011F  cmp      x8, x9
//   0x1d32e0: 540000C0  b.eq     #0x1d32f8
//   0x1d32e4: 12807C09  mov      w9, #-0x3e1
//   0x1d32e8: AA1F03E8  mov      x8, xzr
uint64_t fde_func_00256_0x1d32d4(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x001D32D4ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9412428ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xEB09011FULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x540000C0ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x12807C09ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA1F03E8ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB9000029ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9002828ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #00266 | PC: 0x1d4278..0x1d4368 (240 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x1d4278: D503233F  paciasp  
//   0x1d427c: A9BD7BFD  stp      x29, x30, [sp, #-0x30]!
//   0x1d4280: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x1d4284: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x1d4288: 910003FD  mov      x29, sp
//   0x1d428c: A940A009  ldp      x9, x8, [x0, #8]
uint64_t fde_func_00266_0x1d4278(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x001D4278ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BD7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90157F6ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9024FF4ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA940A009ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x2A0103F4ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #00275 | PC: 0x1d4714..0x1d4748 (52 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x1d4714: D503245F  bti      c
//   0x1d4718: B200F3E8  mov      x8, #0x5555555555555555
//   0x1d471c: F28AAAC8  movk     x8, #0x5556
//   0x1d4720: F2E0AAA8  movk     x8, #0x555, lsl #48
//   0x1d4724: EB08001F  cmp      x0, x8
//   0x1d4728: 54000082  b.hs     #0x1d4738
uint64_t fde_func_00275_0x1d4714(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x001D4714ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB200F3E8ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF28AAAC8ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF2E0AAA8ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xEB08001FULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x54000082ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x8B000408ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD37CED00ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #00285 | PC: 0x1d4ab4..0x1d4bb4 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x1d4ab4: D503233F  paciasp  
//   0x1d4ab8: A9BC7BFD  stp      x29, x30, [sp, #-0x40]!
//   0x1d4abc: F9000BF7  str      x23, [sp, #0x10]
//   0x1d4ac0: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x1d4ac4: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x1d4ac8: 910003FD  mov      x29, sp
uint64_t fde_func_00285_0x1d4ab4(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x001D4AB4ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BC7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF7ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90257F6ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9034FF4ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0103F3ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xEB02003FULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #00294 | PC: 0x1d5114..0x1d5138 (36 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x1d5114: D503233F  paciasp  
//   0x1d5118: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x1d511c: 910003FD  mov      x29, sp
//   0x1d5120: 97FFEBCE  bl       #0x1d0058
//   0x1d5124: 2A2003E8  mvn      w8, w0
//   0x1d5128: 12000100  and      w0, w8, #1
uint64_t fde_func_00294_0x1d5114(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x001D5114ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BF7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x97FFEBCEULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x2A2003E8ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x12000100ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA8C17BFDULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD50323BFULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #00304 | PC: 0x1d59fc..0x1d5ac0 (196 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x1d59fc: D503233F  paciasp  
//   0x1d5a00: A9BD7BFD  stp      x29, x30, [sp, #-0x30]!
//   0x1d5a04: F9000BF5  str      x21, [sp, #0x10]
//   0x1d5a08: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x1d5a0c: 910003FD  mov      x29, sp
//   0x1d5a10: AA0003F3  mov      x19, x0
uint64_t fde_func_00304_0x1d59fc(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x001D59FCULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BD7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF5ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9024FF4ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB9401808ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x2A0103F4ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #00314 | PC: 0x1d6188..0x1d6288 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x1d6188: D503233F  paciasp  
//   0x1d618c: D10283FF  sub      sp, sp, #0xa0
//   0x1d6190: A9047BFD  stp      x29, x30, [sp, #0x40]
//   0x1d6194: A9056FFC  stp      x28, x27, [sp, #0x50]
//   0x1d6198: A90667FA  stp      x26, x25, [sp, #0x60]
//   0x1d619c: A9075FF8  stp      x24, x23, [sp, #0x70]
uint64_t fde_func_00314_0x1d6188(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x001D6188ULL);
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

// FDE #00323 | PC: 0x1d6ce8..0x1d6de8 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x1d6ce8: D503233F  paciasp  
//   0x1d6cec: A9BB7BFD  stp      x29, x30, [sp, #-0x50]!
//   0x1d6cf0: F9000BF9  str      x25, [sp, #0x10]
//   0x1d6cf4: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x1d6cf8: A90357F6  stp      x22, x21, [sp, #0x30]
//   0x1d6cfc: A9044FF4  stp      x20, x19, [sp, #0x40]
uint64_t fde_func_00323_0x1d6ce8(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x001D6CE8ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BB7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF9ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9025FF8ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90357F6ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9044FF4ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA940A415ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #00333 | PC: 0x1d72d8..0x1d7328 (80 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x1d72d8: D503233F  paciasp  
//   0x1d72dc: A9BD7BFD  stp      x29, x30, [sp, #-0x30]!
//   0x1d72e0: F9000BF5  str      x21, [sp, #0x10]
//   0x1d72e4: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x1d72e8: 910003FD  mov      x29, sp
//   0x1d72ec: AA0003F3  mov      x19, x0
uint64_t fde_func_00333_0x1d72d8(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x001D72D8ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BD7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF5ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9024FF4ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xCB010055ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400414ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #00342 | PC: 0x1d7624..0x1d765c (56 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x1d7624: D503233F  paciasp  
//   0x1d7628: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x1d762c: F9000BF3  str      x19, [sp, #0x10]
//   0x1d7630: 910003FD  mov      x29, sp
//   0x1d7634: B0001EA8  adrp     x8, #0x5ac000
//   0x1d7638: 910A0108  add      x8, x8, #0x280
uint64_t fde_func_00342_0x1d7624(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x001D7624ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF3ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB0001EA8ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910A0108ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF8010408ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #00352 | PC: 0x1d78ec..0x1d7954 (104 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x1d78ec: D503233F  paciasp  
//   0x1d78f0: D10283FF  sub      sp, sp, #0xa0
//   0x1d78f4: A9087BFD  stp      x29, x30, [sp, #0x80]
//   0x1d78f8: F9004BF3  str      x19, [sp, #0x90]
//   0x1d78fc: 910203FD  add      x29, sp, #0x80
//   0x1d7900: AA0203F3  mov      x19, x2
uint64_t fde_func_00352_0x1d78ec(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x001D78ECULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10283FFULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9087BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9004BF3ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910203FDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0203F3ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003E1ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90013E5ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #00361 | PC: 0x1d8108..0x1d811c (20 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x1d8108: D503245F  bti      c
//   0x1d810c: 72001C9F  tst      w4, #0xff
//   0x1d8110: F9400440  ldr      x0, [x2, #8]
//   0x1d8114: 1A9F07E1  cset     w1, ne
//   0x1d8118: 14007877  b        #0x1f62f4
uint64_t fde_func_00361_0x1d8108(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x001D8108ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x72001C9FULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400440ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x1A9F07E1ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x14007877ULL ^ (4ULL << 32);
    return state ^ (state >> 29);
}

// FDE #00371 | PC: 0x1d85d4..0x1d85e0 (12 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x1d85d4: D503245F  bti      c
//   0x1d85d8: F9400400  ldr      x0, [x0, #8]
//   0x1d85dc: 14000001  b        #0x1d85e0
uint64_t fde_func_00371_0x1d85d4(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x001D85D4ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400400ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x14000001ULL ^ (2ULL << 32);
    return state ^ (state >> 29);
}

// FDE #00380 | PC: 0x1d8c88..0x1d8d80 (248 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x1d8c88: D503233F  paciasp  
//   0x1d8c8c: D10243FF  sub      sp, sp, #0x90
//   0x1d8c90: A9047BFD  stp      x29, x30, [sp, #0x40]
//   0x1d8c94: A90567FA  stp      x26, x25, [sp, #0x50]
//   0x1d8c98: A9065FF8  stp      x24, x23, [sp, #0x60]
//   0x1d8c9c: A90757F6  stp      x22, x21, [sp, #0x70]
uint64_t fde_func_00380_0x1d8c88(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x001D8C88ULL);
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

// FDE #00390 | PC: 0x1d9318..0x1d9350 (56 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x1d9318: D503233F  paciasp  
//   0x1d931c: D10083FF  sub      sp, sp, #0x20
//   0x1d9320: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x1d9324: 910043FD  add      x29, sp, #0x10
//   0x1d9328: F9400048  ldr      x8, [x2]
//   0x1d932c: F900005F  str      xzr, [x2]
uint64_t fde_func_00390_0x1d9318(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x001D9318ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10083FFULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400048ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF900005FULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910023E2ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF90007E8ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #00399 | PC: 0x1d96c0..0x1d97c0 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x1d96c0: D503233F  paciasp  
//   0x1d96c4: D10403FF  sub      sp, sp, #0x100
//   0x1d96c8: A90A7BFD  stp      x29, x30, [sp, #0xa0]
//   0x1d96cc: A90B6FFC  stp      x28, x27, [sp, #0xb0]
//   0x1d96d0: A90C67FA  stp      x26, x25, [sp, #0xc0]
//   0x1d96d4: A90D5FF8  stp      x24, x23, [sp, #0xd0]
uint64_t fde_func_00399_0x1d96c0(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x001D96C0ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10403FFULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90A7BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90B6FFCULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90C67FAULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90D5FF8ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90E57F6ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90F4FF4ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #00409 | PC: 0x1daa28..0x1daa90 (104 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x1daa28: D503233F  paciasp  
//   0x1daa2c: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x1daa30: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x1daa34: 910003FD  mov      x29, sp
//   0x1daa38: D29BC368  mov      x8, #0xde1b
//   0x1daa3c: AA0003F4  mov      x20, x0
uint64_t fde_func_00409_0x1daa28(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x001DAA28ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9014FF4ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD29BC368ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F4ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF2BD7948ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF2DDE368ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #00418 | PC: 0x1dae9c..0x1daee8 (76 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x1dae9c: D503233F  paciasp  
//   0x1daea0: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x1daea4: F9000BF3  str      x19, [sp, #0x10]
//   0x1daea8: 910003FD  mov      x29, sp
//   0x1daeac: AA0003F3  mov      x19, x0
//   0x1daeb0: 9100A000  add      x0, x0, #0x28
uint64_t fde_func_00418_0x1dae9c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x001DAE9CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF3ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9100A000ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF0001DC8ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910CC108ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #00428 | PC: 0x1db090..0x1db0dc (76 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x1db090: D503233F  paciasp  
//   0x1db094: A9BD7BFD  stp      x29, x30, [sp, #-0x30]!
//   0x1db098: F9000BF5  str      x21, [sp, #0x10]
//   0x1db09c: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x1db0a0: 910003FD  mov      x29, sp
//   0x1db0a4: AA0003F4  mov      x20, x0
uint64_t fde_func_00428_0x1db090(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x001DB090ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BD7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF5ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9024FF4ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F4ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x52800600ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0203F3ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #00437 | PC: 0x1db404..0x1db478 (116 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x1db404: D503233F  paciasp  
//   0x1db408: D100C3FF  sub      sp, sp, #0x30
//   0x1db40c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x1db410: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x1db414: 910043FD  add      x29, sp, #0x10
//   0x1db418: 9100C013  add      x19, x0, #0x30
uint64_t fde_func_00437_0x1db404(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x001DB404ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD100C3FFULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9024FF4ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9100C013ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F4ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA1303E0ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #00447 | PC: 0x1dbd40..0x1dbdd0 (144 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x1dbd40: D503233F  paciasp  
//   0x1dbd44: D10183FF  sub      sp, sp, #0x60
//   0x1dbd48: A9037BFD  stp      x29, x30, [sp, #0x30]
//   0x1dbd4c: F90023F5  str      x21, [sp, #0x40]
//   0x1dbd50: A9054FF4  stp      x20, x19, [sp, #0x50]
//   0x1dbd54: 9100C3FD  add      x29, sp, #0x30
uint64_t fde_func_00447_0x1dbd40(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x001DBD40ULL);
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

// FDE #00456 | PC: 0x1dc550..0x1dc58c (60 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x1dc550: D503233F  paciasp  
//   0x1dc554: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x1dc558: F9000BF3  str      x19, [sp, #0x10]
//   0x1dc55c: 910003FD  mov      x29, sp
//   0x1dc560: F9400441  ldr      x1, [x2, #8]
//   0x1dc564: AA0203F3  mov      x19, x2
uint64_t fde_func_00456_0x1dc550(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x001DC550ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF3ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400441ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0203F3ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF100043FULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x5400006BULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #00466 | PC: 0x1dc994..0x1dc9b0 (28 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x1dc994: D503245F  bti      c
//   0x1dc998: F9400840  ldr      x0, [x2, #0x10]
//   0x1dc99c: F9000444  str      x4, [x2, #8]
//   0x1dc9a0: B4000060  cbz      x0, #0x1dc9ac
//   0x1dc9a4: AA0403E1  mov      x1, x4
//   0x1dc9a8: 14007F15  b        #0x1fc5fc
uint64_t fde_func_00466_0x1dc994(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x001DC994ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400840ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000444ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB4000060ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0403E1ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x14007F15ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD65F03C0ULL ^ (6ULL << 32);
    return state ^ (state >> 29);
}

// FDE #00475 | PC: 0x1dcc50..0x1dcca8 (88 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x1dcc50: D503233F  paciasp  
//   0x1dcc54: A9BD7BFD  stp      x29, x30, [sp, #-0x30]!
//   0x1dcc58: F9000BF5  str      x21, [sp, #0x10]
//   0x1dcc5c: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x1dcc60: 910003FD  mov      x29, sp
//   0x1dcc64: 8B24C068  add      x8, x3, w4, sxtw
uint64_t fde_func_00475_0x1dcc50(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x001DCC50ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BD7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF5ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9024FF4ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x8B24C068ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB0001DC9ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910FC129ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #00485 | PC: 0x1dd61c..0x1dd71c (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x1dd61c: D503233F  paciasp  
//   0x1dd620: D106C3FF  sub      sp, sp, #0x1b0
//   0x1dd624: A9167BFD  stp      x29, x30, [sp, #0x160]
//   0x1dd628: A91767FC  stp      x28, x25, [sp, #0x170]
//   0x1dd62c: A9185FF8  stp      x24, x23, [sp, #0x180]
//   0x1dd630: A91957F6  stp      x22, x21, [sp, #0x190]
uint64_t fde_func_00485_0x1dd61c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x001DD61CULL);
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

// FDE #00494 | PC: 0x1ddcd0..0x1ddcdc (12 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x1ddcd0: D503245F  bti      c
//   0x1ddcd4: D1002000  sub      x0, x0, #8
//   0x1ddcd8: 17FFFEA8  b        #0x1dd778
uint64_t fde_func_00494_0x1ddcd0(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x001DDCD0ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD1002000ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x17FFFEA8ULL ^ (2ULL << 32);
    return state ^ (state >> 29);
}

// FDE #00504 | PC: 0x1dde6c..0x1ddf6c (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x1dde6c: D503233F  paciasp  
//   0x1dde70: A9BA7BFD  stp      x29, x30, [sp, #-0x60]!
//   0x1dde74: A9016FFC  stp      x28, x27, [sp, #0x10]
//   0x1dde78: A90267FA  stp      x26, x25, [sp, #0x20]
//   0x1dde7c: A9035FF8  stp      x24, x23, [sp, #0x30]
//   0x1dde80: A90457F6  stp      x22, x21, [sp, #0x40]
uint64_t fde_func_00504_0x1dde6c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x001DDE6CULL);
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

// FDE #00513 | PC: 0x1dede8..0x1deee8 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x1dede8: D503233F  paciasp  
//   0x1dedec: D10603FF  sub      sp, sp, #0x180
//   0x1dedf0: A9147BFD  stp      x29, x30, [sp, #0x140]
//   0x1dedf4: F900ABFC  str      x28, [sp, #0x150]
//   0x1dedf8: A91657F6  stp      x22, x21, [sp, #0x160]
//   0x1dedfc: A9174FF4  stp      x20, x19, [sp, #0x170]
uint64_t fde_func_00513_0x1dede8(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x001DEDE8ULL);
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

// FDE #00523 | PC: 0x1df5a0..0x1df5ac (12 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x1df5a0: D503245F  bti      c
//   0x1df5a4: AA1F03E1  mov      x1, xzr
//   0x1df5a8: 14000001  b        #0x1df5ac
uint64_t fde_func_00523_0x1df5a0(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x001DF5A0ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA1F03E1ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x14000001ULL ^ (2ULL << 32);
    return state ^ (state >> 29);
}

// FDE #00532 | PC: 0x1dfa2c..0x1dfad8 (172 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x1dfa2c: D503233F  paciasp  
//   0x1dfa30: D10143FF  sub      sp, sp, #0x50
//   0x1dfa34: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x1dfa38: F9001BF5  str      x21, [sp, #0x30]
//   0x1dfa3c: A9044FF4  stp      x20, x19, [sp, #0x40]
//   0x1dfa40: 910083FD  add      x29, sp, #0x20
uint64_t fde_func_00532_0x1dfa2c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x001DFA2CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10143FFULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9027BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9001BF5ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9044FF4ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910083FDULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x12001C88ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x52800029ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #00542 | PC: 0x1dff3c..0x1dffa0 (100 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x1dff3c: D503233F  paciasp  
//   0x1dff40: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x1dff44: F9000BF3  str      x19, [sp, #0x10]
//   0x1dff48: 910003FD  mov      x29, sp
//   0x1dff4c: AA0003F3  mov      x19, x0
//   0x1dff50: F9400800  ldr      x0, [x0, #0x10]
uint64_t fde_func_00542_0x1dff3c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x001DFF3CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF3ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400800ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB4000060ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA1303E1ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #00551 | PC: 0x1e0490..0x1e04bc (44 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x1e0490: D503233F  paciasp  
//   0x1e0494: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x1e0498: F9000BF3  str      x19, [sp, #0x10]
//   0x1e049c: 910003FD  mov      x29, sp
//   0x1e04a0: AA0003F3  mov      x19, x0
//   0x1e04a4: 97FFFFE1  bl       #0x1e0428
uint64_t fde_func_00551_0x1e0490(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x001E0490ULL);
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

// FDE #00561 | PC: 0x1e0a60..0x1e0a94 (52 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x1e0a60: D503245F  bti      c
//   0x1e0a64: EB020028  subs     x8, x1, x2
//   0x1e0a68: 540000C3  b.lo     #0x1e0a80
//   0x1e0a6c: EB08007F  cmp      x3, x8
//   0x1e0a70: 9A883061  csel     x1, x3, x8, lo
//   0x1e0a74: B7F800E1  tbnz     x1, #0x3f, #0x1e0a90
uint64_t fde_func_00561_0x1e0a60(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x001E0A60ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xEB020028ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x540000C3ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xEB08007FULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9A883061ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB7F800E1ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x8B020000ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD65F03C0ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #00570 | PC: 0x1e0e80..0x1e0f80 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x1e0e80: D503245F  bti      c
//   0x1e0e84: D360FC08  lsr      x8, x0, #0x20
//   0x1e0e88: B5000048  cbnz     x8, #0x1e0e90
//   0x1e0e8c: 17FFFF94  b        #0x1e0cdc
//   0x1e0e90: D503233F  paciasp  
//   0x1e0e94: A9BD7BFD  stp      x29, x30, [sp, #-0x30]!
uint64_t fde_func_00570_0x1e0e80(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x001E0E80ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD360FC08ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB5000048ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x17FFFF94ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BD7BFDULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF5ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9024FF4ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #00580 | PC: 0x1e15d0..0x1e15d8 (8 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x1e15d0: D503245F  bti      c
//   0x1e15d4: 140E9785  b        #0x5873e8
uint64_t fde_func_00580_0x1e15d0(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x001E15D0ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x140E9785ULL ^ (1ULL << 32);
    return state ^ (state >> 29);
}

// FDE #00589 | PC: 0x1e19d0..0x1e1a48 (120 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x1e19d0: D503233F  paciasp  
//   0x1e19d4: A9BD7BFD  stp      x29, x30, [sp, #-0x30]!
//   0x1e19d8: F9000BF5  str      x21, [sp, #0x10]
//   0x1e19dc: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x1e19e0: 910003FD  mov      x29, sp
//   0x1e19e4: B0001E88  adrp     x8, #0x5b2000
uint64_t fde_func_00589_0x1e19d0(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x001E19D0ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BD7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF5ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9024FF4ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB0001E88ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91172108ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F4ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #00599 | PC: 0x1e1e3c..0x1e1e70 (52 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x1e1e3c: D503233F  paciasp  
//   0x1e1e40: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x1e1e44: F9000BF3  str      x19, [sp, #0x10]
//   0x1e1e48: 910003FD  mov      x29, sp
//   0x1e1e4c: AA0003F3  mov      x19, x0
//   0x1e1e50: 940E95B4  bl       #0x587520
uint64_t fde_func_00599_0x1e1e3c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x001E1E3CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF3ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x940E95B4ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x12800008ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF900467FULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #00609 | PC: 0x1e201c..0x1e2064 (72 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x1e201c: D503233F  paciasp  
//   0x1e2020: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x1e2024: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x1e2028: 910003FD  mov      x29, sp
//   0x1e202c: 91004014  add      x20, x0, #0x10
//   0x1e2030: AA0003F3  mov      x19, x0
uint64_t fde_func_00609_0x1e201c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x001E201CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9014FF4ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91004014ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0103E0ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA1403E1ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #00618 | PC: 0x1e21e8..0x1e21fc (20 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x1e21e8: D503245F  bti      c
//   0x1e21ec: F9400008  ldr      x8, [x0]
//   0x1e21f0: F85E8108  ldur     x8, [x8, #-0x18]
//   0x1e21f4: 8B080000  add      x0, x0, x8
//   0x1e21f8: 17FFFFE6  b        #0x1e2190
uint64_t fde_func_00618_0x1e21e8(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x001E21E8ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400008ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF85E8108ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x8B080000ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x17FFFFE6ULL ^ (4ULL << 32);
    return state ^ (state >> 29);
}

// FDE #00628 | PC: 0x1e2784..0x1e27f4 (112 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x1e2784: D503233F  paciasp  
//   0x1e2788: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x1e278c: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x1e2790: 910003FD  mov      x29, sp
//   0x1e2794: AA0103F4  mov      x20, x1
//   0x1e2798: AA0003F3  mov      x19, x0
uint64_t fde_func_00628_0x1e2784(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x001E2784ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9014FF4ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0103F4ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x940E91CFULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x39400288ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #00637 | PC: 0x1e2c40..0x1e2d40 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x1e2c40: D503233F  paciasp  
//   0x1e2c44: D10203FF  sub      sp, sp, #0x80
//   0x1e2c48: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x1e2c4c: A9036FFC  stp      x28, x27, [sp, #0x30]
//   0x1e2c50: A90467FA  stp      x26, x25, [sp, #0x40]
//   0x1e2c54: A9055FF8  stp      x24, x23, [sp, #0x50]
uint64_t fde_func_00637_0x1e2c40(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x001E2C40ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10203FFULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9027BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9036FFCULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90467FAULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9055FF8ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90657F6ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9074FF4ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #00647 | PC: 0x1e35c8..0x1e3608 (64 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x1e35c8: D503233F  paciasp  
//   0x1e35cc: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x1e35d0: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x1e35d4: 910003FD  mov      x29, sp
//   0x1e35d8: 91004014  add      x20, x0, #0x10
//   0x1e35dc: AA0003F3  mov      x19, x0
uint64_t fde_func_00647_0x1e35c8(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x001E35C8ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9014FF4ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91004014ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0103E0ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA1403E1ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #00656 | PC: 0x1e49c8..0x1e4a04 (60 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x1e49c8: D503245F  bti      c
//   0x1e49cc: 52800148  mov      w8, #0xa
//   0x1e49d0: 52801EC9  mov      w9, #0xf6
//   0x1e49d4: 9AC8080A  udiv     x10, x0, x8
//   0x1e49d8: F100241F  cmp      x0, #9
//   0x1e49dc: 1B09014B  madd     w11, w10, w9, w0
uint64_t fde_func_00656_0x1e49c8(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x001E49C8ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x52800148ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x52801EC9ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9AC8080AULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF100241FULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x1B09014BULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0A03E0ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x12001D6CULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #00666 | PC: 0x1e53d0..0x1e541c (76 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x1e53d0: D503245F  bti      c
//   0x1e53d4: B9400448  ldr      w8, [x2, #4]
//   0x1e53d8: 37F80128  tbnz     w8, #0x1f, #0x1e53fc
//   0x1e53dc: EB010108  subs     x8, x8, x1
//   0x1e53e0: 540000E9  b.ls     #0x1e53fc
//   0x1e53e4: 39400449  ldrb     w9, [x2, #1]
uint64_t fde_func_00666_0x1e53d0(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x001E53D0ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB9400448ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x37F80128ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xEB010108ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x540000E9ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x39400449ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x37000109ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x37200149ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #00675 | PC: 0x1e5898..0x1e5920 (136 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x1e5898: D503245F  bti      c
//   0x1e589c: F9400409  ldr      x9, [x0, #8]
//   0x1e58a0: B4000369  cbz      x9, #0x1e590c
//   0x1e58a4: AA0003E8  mov      x8, x0
//   0x1e58a8: AA1F03E0  mov      x0, xzr
//   0x1e58ac: D1000529  sub      x9, x9, #1
uint64_t fde_func_00675_0x1e5898(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x001E5898ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400409ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB4000369ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003E8ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA1F03E0ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD1000529ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x5280014AULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB100053FULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #00685 | PC: 0x1e6704..0x1e6728 (36 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x1e6704: D503233F  paciasp  
//   0x1e6708: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x1e670c: 910003FD  mov      x29, sp
//   0x1e6710: D0FFF561  adrp     x1, #0x94000
//   0x1e6714: 91245021  add      x1, x1, #0x914
//   0x1e6718: 90FFF4E3  adrp     x3, #0x82000
uint64_t fde_func_00685_0x1e6704(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x001E6704ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BF7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD0FFF561ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91245021ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x90FFF4E3ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9129B863ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x52800582ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #00694 | PC: 0x1e6a2c..0x1e6a44 (24 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x1e6a2c: D503245F  bti      c
//   0x1e6a30: 39400008  ldrb     w8, [x0]
//   0x1e6a34: 34000068  cbz      w8, #0x1e6a40
//   0x1e6a38: 91002000  add      x0, x0, #8
//   0x1e6a3c: 17FF86EE  b        #0x1c85f4
//   0x1e6a40: 1400000F  b        #0x1e6a7c
uint64_t fde_func_00694_0x1e6a2c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x001E6A2CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x39400008ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x34000068ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91002000ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x17FF86EEULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x1400000FULL ^ (5ULL << 32);
    return state ^ (state >> 29);
}

// FDE #00704 | PC: 0x1e78b4..0x1e7978 (196 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x1e78b4: D503233F  paciasp  
//   0x1e78b8: D101C3FF  sub      sp, sp, #0x70
//   0x1e78bc: A9037BFD  stp      x29, x30, [sp, #0x30]
//   0x1e78c0: A9045FF8  stp      x24, x23, [sp, #0x40]
//   0x1e78c4: A90557F6  stp      x22, x21, [sp, #0x50]
//   0x1e78c8: A9064FF4  stp      x20, x19, [sp, #0x60]
uint64_t fde_func_00704_0x1e78b4(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x001E78B4ULL);
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

// FDE #00713 | PC: 0x1e8364..0x1e83dc (120 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x1e8364: D503233F  paciasp  
//   0x1e8368: D100C3FF  sub      sp, sp, #0x30
//   0x1e836c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x1e8370: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x1e8374: 910043FD  add      x29, sp, #0x10
//   0x1e8378: 91030014  add      x20, x0, #0xc0
uint64_t fde_func_00713_0x1e8364(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x001E8364ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD100C3FFULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9024FF4ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91030014ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0103F3ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA1403E0ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #00723 | PC: 0x1e8cd0..0x1e8dd0 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x1e8cd0: D503233F  paciasp  
//   0x1e8cd4: D10183FF  sub      sp, sp, #0x60
//   0x1e8cd8: A9037BFD  stp      x29, x30, [sp, #0x30]
//   0x1e8cdc: A90457F6  stp      x22, x21, [sp, #0x40]
//   0x1e8ce0: A9054FF4  stp      x20, x19, [sp, #0x50]
//   0x1e8ce4: 9100C3FD  add      x29, sp, #0x30
uint64_t fde_func_00723_0x1e8cd0(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x001E8CD0ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10183FFULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9037BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90457F6ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9054FF4ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9100C3FDULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9407408ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F4ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #00732 | PC: 0x1e9878..0x1e9978 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x1e9878: D503233F  paciasp  
//   0x1e987c: D10203FF  sub      sp, sp, #0x80
//   0x1e9880: A9037BFD  stp      x29, x30, [sp, #0x30]
//   0x1e9884: A90467FA  stp      x26, x25, [sp, #0x40]
//   0x1e9888: A9055FF8  stp      x24, x23, [sp, #0x50]
//   0x1e988c: A90657F6  stp      x22, x21, [sp, #0x60]
uint64_t fde_func_00732_0x1e9878(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x001E9878ULL);
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

// FDE #00742 | PC: 0x1e9f0c..0x1e9f18 (12 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x1e9f0c: D503245F  bti      c
//   0x1e9f10: D1004000  sub      x0, x0, #0x10
//   0x1e9f14: 17FFF6FC  b        #0x1e7b04
uint64_t fde_func_00742_0x1e9f0c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x001E9F0CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD1004000ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x17FFF6FCULL ^ (2ULL << 32);
    return state ^ (state >> 29);
}

// FDE #00751 | PC: 0x1e9f78..0x1e9f84 (12 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x1e9f78: D503245F  bti      c
//   0x1e9f7c: D100A000  sub      x0, x0, #0x28
//   0x1e9f80: 17FFF6E1  b        #0x1e7b04
uint64_t fde_func_00751_0x1e9f78(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x001E9F78ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD100A000ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x17FFF6E1ULL ^ (2ULL << 32);
    return state ^ (state >> 29);
}

// FDE #00761 | PC: 0x1e9ff8..0x1ea004 (12 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x1e9ff8: D503245F  bti      c
//   0x1e9ffc: D1010000  sub      x0, x0, #0x40
//   0x1ea000: 17FFFAA3  b        #0x1e8a8c
uint64_t fde_func_00761_0x1e9ff8(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x001E9FF8ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD1010000ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x17FFFAA3ULL ^ (2ULL << 32);
    return state ^ (state >> 29);
}

// FDE #00770 | PC: 0x1ea07c..0x1ea088 (12 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x1ea07c: D503245F  bti      c
//   0x1ea080: D1014000  sub      x0, x0, #0x50
//   0x1ea084: 17FFFC8F  b        #0x1e92c0
uint64_t fde_func_00770_0x1ea07c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x001EA07CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD1014000ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x17FFFC8FULL ^ (2ULL << 32);
    return state ^ (state >> 29);
}

// FDE #00780 | PC: 0x1ea0f4..0x1ea100 (12 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x1ea0f4: D503245F  bti      c
//   0x1ea0f8: D1018000  sub      x0, x0, #0x60
//   0x1ea0fc: 17FFF682  b        #0x1e7b04
uint64_t fde_func_00780_0x1ea0f4(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x001EA0F4ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD1018000ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x17FFF682ULL ^ (2ULL << 32);
    return state ^ (state >> 29);
}

// FDE #00789 | PC: 0x1ea160..0x1ea16c (12 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x1ea160: D503245F  bti      c
//   0x1ea164: D101E000  sub      x0, x0, #0x78
//   0x1ea168: 17FFF667  b        #0x1e7b04
uint64_t fde_func_00789_0x1ea160(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x001EA160ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD101E000ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x17FFF667ULL ^ (2ULL << 32);
    return state ^ (state >> 29);
}

// FDE #00799 | PC: 0x1ea1d8..0x1ea1e4 (12 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x1ea1d8: D503245F  bti      c
//   0x1ea1dc: D1024000  sub      x0, x0, #0x90
//   0x1ea1e0: 17FFF649  b        #0x1e7b04
uint64_t fde_func_00799_0x1ea1d8(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x001EA1D8ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD1024000ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x17FFF649ULL ^ (2ULL << 32);
    return state ^ (state >> 29);
}

// FDE #00808 | PC: 0x1ea358..0x1ea398 (64 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x1ea358: D503233F  paciasp  
//   0x1ea35c: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x1ea360: F9000BF3  str      x19, [sp, #0x10]
//   0x1ea364: 910003FD  mov      x29, sp
//   0x1ea368: AA0003F3  mov      x19, x0
//   0x1ea36c: 940E75B1  bl       #0x587a30
uint64_t fde_func_00808_0x1ea358(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x001EA358ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF3ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x940E75B1ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x350000A0ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400BF3ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #00818 | PC: 0x1ea64c..0x1ea674 (40 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x1ea64c: D503245F  bti      c
//   0x1ea650: A942A009  ldp      x9, x8, [x0, #0x28]
//   0x1ea654: F9401010  ldr      x16, [x0, #0x20]
//   0x1ea658: 8B890508  add      x8, x8, x9, asr #1
//   0x1ea65c: 36000069  tbz      w9, #0, #0x1ea668
//   0x1ea660: F9400109  ldr      x9, [x8]
uint64_t fde_func_00818_0x1ea64c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x001EA64CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA942A009ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9401010ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x8B890508ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x36000069ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400109ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF8706930ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9401C01ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #00827 | PC: 0x1ea878..0x1ea8a4 (44 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x1ea878: D503245F  bti      c
//   0x1ea87c: A942A009  ldp      x9, x8, [x0, #0x28]
//   0x1ea880: F9401010  ldr      x16, [x0, #0x20]
//   0x1ea884: 8B890508  add      x8, x8, x9, asr #1
//   0x1ea888: 36000069  tbz      w9, #0, #0x1ea894
//   0x1ea88c: F9400109  ldr      x9, [x8]
uint64_t fde_func_00827_0x1ea878(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x001EA878ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA942A009ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9401010ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x8B890508ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x36000069ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400109ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF8706930ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91010002ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #00837 | PC: 0x1eaf50..0x1eafa8 (88 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x1eaf50: D503233F  paciasp  
//   0x1eaf54: A9BD7BFD  stp      x29, x30, [sp, #-0x30]!
//   0x1eaf58: F9000BF5  str      x21, [sp, #0x10]
//   0x1eaf5c: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x1eaf60: 910003FD  mov      x29, sp
//   0x1eaf64: AA0203F3  mov      x19, x2
uint64_t fde_func_00837_0x1eaf50(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x001EAF50ULL);
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

// FDE #00846 | PC: 0x1eb38c..0x1eb3b8 (44 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x1eb38c: D503245F  bti      c
//   0x1eb390: A942A009  ldp      x9, x8, [x0, #0x28]
//   0x1eb394: F9401010  ldr      x16, [x0, #0x20]
//   0x1eb398: 8B890508  add      x8, x8, x9, asr #1
//   0x1eb39c: 36000069  tbz      w9, #0, #0x1eb3a8
//   0x1eb3a0: F9400109  ldr      x9, [x8]
uint64_t fde_func_00846_0x1eb38c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x001EB38CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA942A009ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9401010ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x8B890508ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x36000069ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400109ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF8706930ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x29470801ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #00856 | PC: 0x1ebc10..0x1ebd10 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x1ebc10: D503233F  paciasp  
//   0x1ebc14: A9BD7BFD  stp      x29, x30, [sp, #-0x30]!
//   0x1ebc18: F9000BF5  str      x21, [sp, #0x10]
//   0x1ebc1c: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x1ebc20: 910003FD  mov      x29, sp
//   0x1ebc24: 94091790  bl       #0x431a64
uint64_t fde_func_00856_0x1ebc10(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x001EBC10ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BD7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF5ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9024FF4ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x94091790ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x90001FB4ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF947BA88ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #00865 | PC: 0x1ec124..0x1ec134 (16 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x1ec124: D503245F  bti      c
//   0x1ec128: B4000040  cbz      x0, #0x1ec130
//   0x1ec12c: 17FFEF7C  b        #0x1e7f1c
//   0x1ec130: D65F03C0  ret      
uint64_t fde_func_00865_0x1ec124(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x001EC124ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB4000040ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x17FFEF7CULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD65F03C0ULL ^ (3ULL << 32);
    return state ^ (state >> 29);
}

// FDE #00875 | PC: 0x1f08fc..0x1f09bc (192 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x1f08fc: D503233F  paciasp  
//   0x1f0900: A9BD7BFD  stp      x29, x30, [sp, #-0x30]!
//   0x1f0904: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x1f0908: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x1f090c: 910003FD  mov      x29, sp
//   0x1f0910: 94090455  bl       #0x431a64
uint64_t fde_func_00875_0x1f08fc(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x001F08FCULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BD7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90157F6ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9024FF4ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x94090455ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF0001F75ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF947BAB6ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #00884 | PC: 0x1f0fe4..0x1f10cc (232 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x1f0fe4: D503233F  paciasp  
//   0x1f0fe8: A9BD7BFD  stp      x29, x30, [sp, #-0x30]!
//   0x1f0fec: F9000BF5  str      x21, [sp, #0x10]
//   0x1f0ff0: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x1f0ff4: 910003FD  mov      x29, sp
//   0x1f0ff8: 9409029B  bl       #0x431a64
uint64_t fde_func_00884_0x1f0fe4(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x001F0FE4ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BD7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF5ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9024FF4ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9409029BULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF0001F74ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF947BA95ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #00894 | PC: 0x1f1cdc..0x1f1ddc (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x1f1cdc: D503233F  paciasp  
//   0x1f1ce0: A9BC7BFD  stp      x29, x30, [sp, #-0x40]!
//   0x1f1ce4: F9000BF7  str      x23, [sp, #0x10]
//   0x1f1ce8: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x1f1cec: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x1f1cf0: 910003FD  mov      x29, sp
uint64_t fde_func_00894_0x1f1cdc(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x001F1CDCULL);
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

// FDE #00904 | PC: 0x1f27d8..0x1f2818 (64 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x1f27d8: D503233F  paciasp  
//   0x1f27dc: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x1f27e0: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x1f27e4: 910003FD  mov      x29, sp
//   0x1f27e8: AA0003F4  mov      x20, x0
//   0x1f27ec: 91002000  add      x0, x0, #8
uint64_t fde_func_00904_0x1f27d8(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x001F27D8ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9014FF4ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F4ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91002000ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x2A0303F3ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB9000281ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #00913 | PC: 0x1f2b7c..0x1f2c7c (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x1f2b7c: D503233F  paciasp  
//   0x1f2b80: A9BD7BFD  stp      x29, x30, [sp, #-0x30]!
//   0x1f2b84: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x1f2b88: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x1f2b8c: 910003FD  mov      x29, sp
//   0x1f2b90: 9408FBB5  bl       #0x431a64
uint64_t fde_func_00913_0x1f2b7c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x001F2B7CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BD7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90157F6ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9024FF4ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9408FBB5ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB0001F75ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF947BAB6ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #00923 | PC: 0x1f3198..0x1f3288 (240 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x1f3198: D503233F  paciasp  
//   0x1f319c: A9BD7BFD  stp      x29, x30, [sp, #-0x30]!
//   0x1f31a0: F9000BF5  str      x21, [sp, #0x10]
//   0x1f31a4: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x1f31a8: 910003FD  mov      x29, sp
//   0x1f31ac: 9408FA2E  bl       #0x431a64
uint64_t fde_func_00923_0x1f3198(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x001F3198ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BD7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF5ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9024FF4ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9408FA2EULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x90001F74ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF947BA95ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #00932 | PC: 0x1f37d8..0x1f3860 (136 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x1f37d8: D503233F  paciasp  
//   0x1f37dc: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x1f37e0: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x1f37e4: 910003FD  mov      x29, sp
//   0x1f37e8: 9408F89F  bl       #0x431a64
//   0x1f37ec: 90001F73  adrp     x19, #0x5df000
uint64_t fde_func_00932_0x1f37d8(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x001F37D8ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9014FF4ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9408F89FULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x90001F73ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF947BA74ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9407E80ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #00942 | PC: 0x1f3d8c..0x1f3dcc (64 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x1f3d8c: D503233F  paciasp  
//   0x1f3d90: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x1f3d94: F9000BF3  str      x19, [sp, #0x10]
//   0x1f3d98: 910003FD  mov      x29, sp
//   0x1f3d9c: F9400008  ldr      x8, [x0]
//   0x1f3da0: B40000E8  cbz      x8, #0x1f3dbc
uint64_t fde_func_00942_0x1f3d8c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x001F3D8CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF3ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400008ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB40000E8ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x97FFFFC5ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #00951 | PC: 0x1f4058..0x1f4094 (60 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x1f4058: D503245F  bti      c
//   0x1f405c: B40001A0  cbz      x0, #0x1f4090
//   0x1f4060: D503233F  paciasp  
//   0x1f4064: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x1f4068: F9000BF3  str      x19, [sp, #0x10]
//   0x1f406c: 910003FD  mov      x29, sp
uint64_t fde_func_00951_0x1f4058(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x001F4058ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB40001A0ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE7BFDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF3ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9401C00ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #00961 | PC: 0x1f45ac..0x1f45b8 (12 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x1f45ac: D503245F  bti      c
//   0x1f45b0: AA1F03E1  mov      x1, xzr
//   0x1f45b4: 14000042  b        #0x1f46bc
uint64_t fde_func_00961_0x1f45ac(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x001F45ACULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA1F03E1ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x14000042ULL ^ (2ULL << 32);
    return state ^ (state >> 29);
}

// FDE #00970 | PC: 0x1f6148..0x1f61f4 (172 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x1f6148: D503233F  paciasp  
//   0x1f614c: D10203FF  sub      sp, sp, #0x80
//   0x1f6150: A9037BFD  stp      x29, x30, [sp, #0x30]
//   0x1f6154: F90023F9  str      x25, [sp, #0x40]
//   0x1f6158: A9055FF8  stp      x24, x23, [sp, #0x50]
//   0x1f615c: A90657F6  stp      x22, x21, [sp, #0x60]
uint64_t fde_func_00970_0x1f6148(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x001F6148ULL);
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

// FDE #00980 | PC: 0x1f6840..0x1f687c (60 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x1f6840: D503245F  bti      c
//   0x1f6844: B40001A0  cbz      x0, #0x1f6878
//   0x1f6848: D503233F  paciasp  
//   0x1f684c: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x1f6850: F9000BF3  str      x19, [sp, #0x10]
//   0x1f6854: 910003FD  mov      x29, sp
uint64_t fde_func_00980_0x1f6840(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x001F6840ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB40001A0ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE7BFDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF3ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9100E000ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #00989 | PC: 0x1f6df4..0x1f6e14 (32 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x1f6df4: D503245F  bti      c
//   0x1f6df8: AA0003E8  mov      x8, x0
//   0x1f6dfc: AA0103E2  mov      x2, x1
//   0x1f6e00: F900081F  str      xzr, [x0, #0x10]
//   0x1f6e04: F8008D1F  str      xzr, [x8, #8]!
//   0x1f6e08: F9000008  str      x8, [x0]
uint64_t fde_func_00989_0x1f6df4(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x001F6DF4ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003E8ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0103E2ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF900081FULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF8008D1FULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000008ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF8408441ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x1400009EULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #00999 | PC: 0x1f73cc..0x1f74cc (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x1f73cc: D503233F  paciasp  
//   0x1f73d0: A9BD7BFD  stp      x29, x30, [sp, #-0x30]!
//   0x1f73d4: F9000BF5  str      x21, [sp, #0x10]
//   0x1f73d8: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x1f73dc: 910003FD  mov      x29, sp
//   0x1f73e0: AA0103F5  mov      x21, x1
uint64_t fde_func_00999_0x1f73cc(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x001F73CCULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BD7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF5ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9024FF4ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0103F5ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400028ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #01008 | PC: 0x1f7ba4..0x1f7bdc (56 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x1f7ba4: D503245F  bti      c
//   0x1f7ba8: A942A009  ldp      x9, x8, [x0, #0x28]
//   0x1f7bac: F9401010  ldr      x16, [x0, #0x20]
//   0x1f7bb0: 8B890508  add      x8, x8, x9, asr #1
//   0x1f7bb4: 36000069  tbz      w9, #0, #0x1f7bc0
//   0x1f7bb8: F9400109  ldr      x9, [x8]
uint64_t fde_func_01008_0x1f7ba4(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x001F7BA4ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA942A009ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9401010ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x8B890508ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x36000069ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400109ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF8706930ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9100E001ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #01018 | PC: 0x1f7e60..0x1f7e9c (60 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x1f7e60: D503245F  bti      c
//   0x1f7e64: B40001A0  cbz      x0, #0x1f7e98
//   0x1f7e68: D503233F  paciasp  
//   0x1f7e6c: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x1f7e70: F9000BF3  str      x19, [sp, #0x10]
//   0x1f7e74: 910003FD  mov      x29, sp
uint64_t fde_func_01018_0x1f7e60(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x001F7E60ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB40001A0ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE7BFDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF3ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9100E000ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #01027 | PC: 0x1f854c..0x1f857c (48 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x1f854c: D503233F  paciasp  
//   0x1f8550: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x1f8554: F9000BF3  str      x19, [sp, #0x10]
//   0x1f8558: 910003FD  mov      x29, sp
//   0x1f855c: AA0103F3  mov      x19, x1
//   0x1f8560: 97FFE33F  bl       #0x1f125c
uint64_t fde_func_01027_0x1f854c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x001F854CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF3ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0103F3ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x97FFE33FULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x39408000ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA1303E1ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #01037 | PC: 0x1f8b6c..0x1f8b98 (44 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x1f8b6c: D503233F  paciasp  
//   0x1f8b70: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x1f8b74: F9000BF3  str      x19, [sp, #0x10]
//   0x1f8b78: 910003FD  mov      x29, sp
//   0x1f8b7c: AA0003F3  mov      x19, x0
//   0x1f8b80: 97FFFFEC  bl       #0x1f8b30
uint64_t fde_func_01037_0x1f8b6c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x001F8B6CULL);
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

// FDE #01046 | PC: 0x1f8e38..0x1f8e54 (28 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x1f8e38: D503245F  bti      c
//   0x1f8e3c: AA0003E8  mov      x8, x0
//   0x1f8e40: F9400000  ldr      x0, [x0]
//   0x1f8e44: F900011F  str      xzr, [x8]
//   0x1f8e48: B4000040  cbz      x0, #0x1f8e50
//   0x1f8e4c: 140B7E70  b        #0x4d880c
uint64_t fde_func_01046_0x1f8e38(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x001F8E38ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003E8ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400000ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF900011FULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB4000040ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x140B7E70ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD65F03C0ULL ^ (6ULL << 32);
    return state ^ (state >> 29);
}

// FDE #01056 | PC: 0x1f91ec..0x1f9218 (44 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x1f91ec: D503233F  paciasp  
//   0x1f91f0: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x1f91f4: F9000BF3  str      x19, [sp, #0x10]
//   0x1f91f8: 910003FD  mov      x29, sp
//   0x1f91fc: AA0003F3  mov      x19, x0
//   0x1f9200: 97FFFFE8  bl       #0x1f91a0
uint64_t fde_func_01056_0x1f91ec(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x001F91ECULL);
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

// FDE #01065 | PC: 0x1f96cc..0x1f976c (160 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x1f96cc: D503233F  paciasp  
//   0x1f96d0: D10203FF  sub      sp, sp, #0x80
//   0x1f96d4: A9067BFD  stp      x29, x30, [sp, #0x60]
//   0x1f96d8: A9074FF4  stp      x20, x19, [sp, #0x70]
//   0x1f96dc: 910183FD  add      x29, sp, #0x60
//   0x1f96e0: 91034014  add      x20, x0, #0xd0
uint64_t fde_func_01065_0x1f96cc(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x001F96CCULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10203FFULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9067BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9074FF4ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910183FDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91034014ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0103F3ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA1403E0ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #01075 | PC: 0x1fa824..0x1fa924 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x1fa824: D503233F  paciasp  
//   0x1fa828: A9BA7BFD  stp      x29, x30, [sp, #-0x60]!
//   0x1fa82c: A9016FFC  stp      x28, x27, [sp, #0x10]
//   0x1fa830: A90267FA  stp      x26, x25, [sp, #0x20]
//   0x1fa834: A9035FF8  stp      x24, x23, [sp, #0x30]
//   0x1fa838: A90457F6  stp      x22, x21, [sp, #0x40]
uint64_t fde_func_01075_0x1fa824(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x001FA824ULL);
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

// FDE #01084 | PC: 0x1fad74..0x1fadb0 (60 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x1fad74: D503233F  paciasp  
//   0x1fad78: D10083FF  sub      sp, sp, #0x20
//   0x1fad7c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x1fad80: 910043FD  add      x29, sp, #0x10
//   0x1fad84: AA0103E2  mov      x2, x1
//   0x1fad88: 910023E1  add      x1, sp, #8
uint64_t fde_func_01084_0x1fad74(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x001FAD74ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10083FFULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0103E2ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910023E1ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x97FF5500ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400008ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #01094 | PC: 0x1fb1c0..0x1fb260 (160 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x1fb1c0: D503233F  paciasp  
//   0x1fb1c4: D101C3FF  sub      sp, sp, #0x70
//   0x1fb1c8: A9047BFD  stp      x29, x30, [sp, #0x40]
//   0x1fb1cc: F9002BF5  str      x21, [sp, #0x50]
//   0x1fb1d0: A9064FF4  stp      x20, x19, [sp, #0x60]
//   0x1fb1d4: 910103FD  add      x29, sp, #0x40
uint64_t fde_func_01094_0x1fb1c0(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x001FB1C0ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD101C3FFULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9047BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9002BF5ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9064FF4ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910103FDULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F5ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10043A0ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #01103 | PC: 0x1fb9cc..0x1fba88 (188 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x1fb9cc: D503233F  paciasp  
//   0x1fb9d0: D101C3FF  sub      sp, sp, #0x70
//   0x1fb9d4: A9047BFD  stp      x29, x30, [sp, #0x40]
//   0x1fb9d8: F9002BF5  str      x21, [sp, #0x50]
//   0x1fb9dc: A9064FF4  stp      x20, x19, [sp, #0x60]
//   0x1fb9e0: 910103FD  add      x29, sp, #0x40
uint64_t fde_func_01103_0x1fb9cc(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x001FB9CCULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD101C3FFULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9047BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9002BF5ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9064FF4ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910103FDULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9406015ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0103F4ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #01113 | PC: 0x1fbf74..0x1fbfa0 (44 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x1fbf74: D503245F  bti      c
//   0x1fbf78: A942A009  ldp      x9, x8, [x0, #0x28]
//   0x1fbf7c: F9401010  ldr      x16, [x0, #0x20]
//   0x1fbf80: F9401C01  ldr      x1, [x0, #0x38]
//   0x1fbf84: 8B890508  add      x8, x8, x9, asr #1
//   0x1fbf88: 36000069  tbz      w9, #0, #0x1fbf94
uint64_t fde_func_01113_0x1fbf74(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x001FBF74ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA942A009ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9401010ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9401C01ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x8B890508ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x36000069ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400109ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF8706930ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #01122 | PC: 0x1fc218..0x1fc318 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x1fc218: D503233F  paciasp  
//   0x1fc21c: D10343FF  sub      sp, sp, #0xd0
//   0x1fc220: A9097BFD  stp      x29, x30, [sp, #0x90]
//   0x1fc224: A90A5FF8  stp      x24, x23, [sp, #0xa0]
//   0x1fc228: A90B57F6  stp      x22, x21, [sp, #0xb0]
//   0x1fc22c: A90C4FF4  stp      x20, x19, [sp, #0xc0]
uint64_t fde_func_01122_0x1fc218(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x001FC218ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10343FFULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9097BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90A5FF8ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90B57F6ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90C4FF4ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910243FDULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0103F4ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #01132 | PC: 0x1fdaf0..0x1fdb60 (112 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x1fdaf0: D503233F  paciasp  
//   0x1fdaf4: D100C3FF  sub      sp, sp, #0x30
//   0x1fdaf8: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x1fdafc: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x1fdb00: 910043FD  add      x29, sp, #0x10
//   0x1fdb04: AA0003F4  mov      x20, x0
uint64_t fde_func_01132_0x1fdaf0(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x001FDAF0ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD100C3FFULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9024FF4ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F4ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x52800800ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0103F3ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #01141 | PC: 0x1fe2d0..0x1fe2f0 (32 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x1fe2d0: D503245F  bti      c
//   0x1fe2d4: AA0003E8  mov      x8, x0
//   0x1fe2d8: F9412000  ldr      x0, [x0, #0x240]
//   0x1fe2dc: B5000040  cbnz     x0, #0x1fe2e4
//   0x1fe2e0: F940E500  ldr      x0, [x8, #0x1c8]
//   0x1fe2e4: F9400008  ldr      x8, [x0]
uint64_t fde_func_01141_0x1fe2d0(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x001FE2D0ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003E8ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9412000ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB5000040ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF940E500ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400008ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400D10ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD61F0200ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #01151 | PC: 0x1fe418..0x1fe518 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x1fe418: D503233F  paciasp  
//   0x1fe41c: D10203FF  sub      sp, sp, #0x80
//   0x1fe420: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x1fe424: A9036FFC  stp      x28, x27, [sp, #0x30]
//   0x1fe428: A90467FA  stp      x26, x25, [sp, #0x40]
//   0x1fe42c: A9055FF8  stp      x24, x23, [sp, #0x50]
uint64_t fde_func_01151_0x1fe418(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x001FE418ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10203FFULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9027BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9036FFCULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90467FAULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9055FF8ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90657F6ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9074FF4ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #01160 | PC: 0x1fedcc..0x1fedd8 (12 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x1fedcc: D503245F  bti      c
//   0x1fedd0: F9400400  ldr      x0, [x0, #8]
//   0x1fedd4: 14001F54  b        #0x206b24
uint64_t fde_func_01160_0x1fedcc(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x001FEDCCULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400400ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x14001F54ULL ^ (2ULL << 32);
    return state ^ (state >> 29);
}

// FDE #01170 | PC: 0x1ff114..0x1ff214 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x1ff114: D503233F  paciasp  
//   0x1ff118: A9BA7BFD  stp      x29, x30, [sp, #-0x60]!
//   0x1ff11c: A9016FFC  stp      x28, x27, [sp, #0x10]
//   0x1ff120: A90267FA  stp      x26, x25, [sp, #0x20]
//   0x1ff124: A9035FF8  stp      x24, x23, [sp, #0x30]
//   0x1ff128: A90457F6  stp      x22, x21, [sp, #0x40]
uint64_t fde_func_01170_0x1ff114(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x001FF114ULL);
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

// FDE #01179 | PC: 0x202388..0x2023d8 (80 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x202388: D503233F  paciasp  
//   0x20238c: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x202390: F9000BF3  str      x19, [sp, #0x10]
//   0x202394: 910003FD  mov      x29, sp
//   0x202398: F2401C1F  tst      x0, #0xff
//   0x20239c: F9000FA0  str      x0, [x29, #0x18]
uint64_t fde_func_01179_0x202388(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00202388ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF3ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF2401C1FULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000FA0ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x54000180ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910063A0ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #01189 | PC: 0x202a30..0x202ab8 (136 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x202a30: D503233F  paciasp  
//   0x202a34: A9BB7BFD  stp      x29, x30, [sp, #-0x50]!
//   0x202a38: F9000BF9  str      x25, [sp, #0x10]
//   0x202a3c: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x202a40: A90357F6  stp      x22, x21, [sp, #0x30]
//   0x202a44: A9044FF4  stp      x20, x19, [sp, #0x40]
uint64_t fde_func_01189_0x202a30(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00202A30ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BB7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF9ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9025FF8ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90357F6ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9044FF4ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9402014ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #01199 | PC: 0x203348..0x203384 (60 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x203348: D503233F  paciasp  
//   0x20334c: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x203350: F9000BF3  str      x19, [sp, #0x10]
//   0x203354: 910003FD  mov      x29, sp
//   0x203358: AA0003F3  mov      x19, x0
//   0x20335c: 91004000  add      x0, x0, #0x10
uint64_t fde_func_01199_0x203348(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00203348ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF3ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91004000ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x78408428ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x79001268ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #01208 | PC: 0x203834..0x203880 (76 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x203834: D503233F  paciasp  
//   0x203838: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x20383c: 910003FD  mov      x29, sp
//   0x203840: D37BFC28  lsr      x8, x1, #0x3b
//   0x203844: B50001C8  cbnz     x8, #0x20387c
//   0x203848: F9400808  ldr      x8, [x0, #0x10]
uint64_t fde_func_01208_0x203834(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00203834ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BF7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD37BFC28ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB50001C8ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400808ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB27BE7EAULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400009ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #01218 | PC: 0x2060b8..0x2061b8 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x2060b8: D503233F  paciasp  
//   0x2060bc: A9BC7BFD  stp      x29, x30, [sp, #-0x40]!
//   0x2060c0: F9000BF7  str      x23, [sp, #0x10]
//   0x2060c4: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x2060c8: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x2060cc: 910003FD  mov      x29, sp
uint64_t fde_func_01218_0x2060b8(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x002060B8ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BC7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF7ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90257F6ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9034FF4ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9401C17ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x2A0203F4ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #01227 | PC: 0x206638..0x206660 (40 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x206638: D503245F  bti      c
//   0x20663c: AA0003E8  mov      x8, x0
//   0x206640: 52800029  mov      w9, #1
//   0x206644: AA0103E0  mov      x0, x1
//   0x206648: 39000109  strb     w9, [x8]
//   0x20664c: F9400829  ldr      x9, [x1, #0x10]
uint64_t fde_func_01227_0x206638(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00206638ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003E8ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x52800029ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0103E0ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x39000109ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400829ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x3DC00020ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000D09ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #01237 | PC: 0x206a84..0x206af8 (116 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x206a84: D503233F  paciasp  
//   0x206a88: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x206a8c: F9000BF3  str      x19, [sp, #0x10]
//   0x206a90: 910003FD  mov      x29, sp
//   0x206a94: AA0003F3  mov      x19, x0
//   0x206a98: F9400C01  ldr      x1, [x0, #0x18]
uint64_t fde_func_01237_0x206a84(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00206A84ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF3ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400C01ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF0001C68ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91388108ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #01246 | PC: 0x206f5c..0x206f6c (16 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x206f5c: D503245F  bti      c
//   0x206f60: F9400C08  ldr      x8, [x0, #0x18]
//   0x206f64: F9000D01  str      x1, [x8, #0x18]
//   0x206f68: D65F03C0  ret      
uint64_t fde_func_01246_0x206f5c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00206F5CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400C08ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000D01ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD65F03C0ULL ^ (3ULL << 32);
    return state ^ (state >> 29);
}

// FDE #01256 | PC: 0x2074a0..0x2074d0 (48 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x2074a0: D503233F  paciasp  
//   0x2074a4: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x2074a8: F9000BF3  str      x19, [sp, #0x10]
//   0x2074ac: 910003FD  mov      x29, sp
//   0x2074b0: AA0003F3  mov      x19, x0
//   0x2074b4: 97FFDA31  bl       #0x1fdd78
uint64_t fde_func_01256_0x2074a0(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x002074A0ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF3ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x97FFDA31ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x52800028ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9001E68ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #01265 | PC: 0x207804..0x2078a8 (164 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x207804: D503233F  paciasp  
//   0x207808: D10103FF  sub      sp, sp, #0x40
//   0x20780c: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x207810: F9001BF3  str      x19, [sp, #0x30]
//   0x207814: 910083FD  add      x29, sp, #0x20
//   0x207818: AA0003F3  mov      x19, x0
uint64_t fde_func_01265_0x207804(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00207804ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10103FFULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9027BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9001BF3ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910083FDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9007C1FULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF900081FULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #01275 | PC: 0x207fe0..0x20801c (60 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x207fe0: D503245F  bti      c
//   0x207fe4: F9400408  ldr      x8, [x0, #8]
//   0x207fe8: EB02003F  cmp      x1, x2
//   0x207fec: 54000140  b.eq     #0x208014
//   0x207ff0: 39404029  ldrb     w9, [x1, #0x10]
//   0x207ff4: 3DC00020  ldr      q0, [x1]
uint64_t fde_func_01275_0x207fe0(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00207FE0ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400408ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xEB02003FULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x54000140ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x39404029ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x3DC00020ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x39004109ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x3D800100ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #01284 | PC: 0x208780..0x2087c0 (64 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x208780: D503233F  paciasp  
//   0x208784: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x208788: F9000BF3  str      x19, [sp, #0x10]
//   0x20878c: 910003FD  mov      x29, sp
//   0x208790: F9400008  ldr      x8, [x0]
//   0x208794: B40000E8  cbz      x8, #0x2087b0
uint64_t fde_func_01284_0x208780(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00208780ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF3ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400008ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB40000E8ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x97FFC932ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #01294 | PC: 0x208d80..0x208df4 (116 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x208d80: D503233F  paciasp  
//   0x208d84: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x208d88: F9000BF3  str      x19, [sp, #0x10]
//   0x208d8c: 910003FD  mov      x29, sp
//   0x208d90: AA0003F3  mov      x19, x0
//   0x208d94: F9407C08  ldr      x8, [x0, #0xf8]
uint64_t fde_func_01294_0x208d80(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00208D80ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF3ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9407C08ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB0001C69ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x913B4129ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #01303 | PC: 0x2091bc..0x209264 (168 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x2091bc: D503233F  paciasp  
//   0x2091c0: D101C3FF  sub      sp, sp, #0x70
//   0x2091c4: A9047BFD  stp      x29, x30, [sp, #0x40]
//   0x2091c8: A90557F6  stp      x22, x21, [sp, #0x50]
//   0x2091cc: A9064FF4  stp      x20, x19, [sp, #0x60]
//   0x2091d0: 910103FD  add      x29, sp, #0x40
uint64_t fde_func_01303_0x2091bc(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x002091BCULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD101C3FFULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9047BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90557F6ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9064FF4ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910103FDULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD53BD055ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F4ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #01313 | PC: 0x209688..0x2096ac (36 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x209688: D503233F  paciasp  
//   0x20968c: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x209690: 910003FD  mov      x29, sp
//   0x209694: 94000006  bl       #0x2096ac
//   0x209698: 2A2003E8  mvn      w8, w0
//   0x20969c: 12000100  and      w0, w8, #1
uint64_t fde_func_01313_0x209688(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00209688ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BF7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x94000006ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x2A2003E8ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x12000100ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA8C17BFDULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD50323BFULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #01322 | PC: 0x209d7c..0x209e7c (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x209d7c: D503233F  paciasp  
//   0x209d80: D106C3FF  sub      sp, sp, #0x1b0
//   0x209d84: A9157BFD  stp      x29, x30, [sp, #0x150]
//   0x209d88: A9166FFC  stp      x28, x27, [sp, #0x160]
//   0x209d8c: A91767FA  stp      x26, x25, [sp, #0x170]
//   0x209d90: A9185FF8  stp      x24, x23, [sp, #0x180]
uint64_t fde_func_01322_0x209d7c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00209D7CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD106C3FFULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9157BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9166FFCULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA91767FAULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9185FF8ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA91957F6ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA91A4FF4ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #01332 | PC: 0x20a650..0x20a6bc (108 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x20a650: D503233F  paciasp  
//   0x20a654: A9BD7BFD  stp      x29, x30, [sp, #-0x30]!
//   0x20a658: F9000BF5  str      x21, [sp, #0x10]
//   0x20a65c: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x20a660: 910003FD  mov      x29, sp
//   0x20a664: F9400015  ldr      x21, [x0]
uint64_t fde_func_01332_0x20a650(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0020A650ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BD7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF5ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9024FF4ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400015ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB4000215ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #01341 | PC: 0x20b000..0x20b038 (56 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x20b000: D503233F  paciasp  
//   0x20b004: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x20b008: F9000BF3  str      x19, [sp, #0x10]
//   0x20b00c: 910003FD  mov      x29, sp
//   0x20b010: 39400008  ldrb     w8, [x0]
//   0x20b014: 340000A8  cbz      w8, #0x20b028
uint64_t fde_func_01341_0x20b000(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0020B000ULL);
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

// FDE #01351 | PC: 0x20b678..0x20b6e0 (104 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x20b678: D503233F  paciasp  
//   0x20b67c: A9BD7BFD  stp      x29, x30, [sp, #-0x30]!
//   0x20b680: F9000BF5  str      x21, [sp, #0x10]
//   0x20b684: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x20b688: 910003FD  mov      x29, sp
//   0x20b68c: AA0103F4  mov      x20, x1
uint64_t fde_func_01351_0x20b678(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0020B678ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BD7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF5ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9024FF4ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0103F4ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xEB010041ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9007C1FULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #01360 | PC: 0x20b8f8..0x20b98c (148 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x20b8f8: D503233F  paciasp  
//   0x20b8fc: A9BD7BFD  stp      x29, x30, [sp, #-0x30]!
//   0x20b900: F9000BF5  str      x21, [sp, #0x10]
//   0x20b904: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x20b908: 910003FD  mov      x29, sp
//   0x20b90c: AA0003F4  mov      x20, x0
uint64_t fde_func_01360_0x20b8f8(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0020B8F8ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BD7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF5ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9024FF4ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F4ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x39400008ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0103F3ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #01370 | PC: 0x20bda8..0x20bdec (68 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x20bda8: D503233F  paciasp  
//   0x20bdac: D100C3FF  sub      sp, sp, #0x30
//   0x20bdb0: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x20bdb4: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x20bdb8: 910043FD  add      x29, sp, #0x10
//   0x20bdbc: AA0003F4  mov      x20, x0
uint64_t fde_func_01370_0x20bda8(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0020BDA8ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD100C3FFULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9024FF4ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F4ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003E0ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0203F3ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #01379 | PC: 0x20c070..0x20c0a8 (56 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x20c070: D503245F  bti      c
//   0x20c074: A9017C1F  stp      xzr, xzr, [x0, #0x10]
//   0x20c078: 52800028  mov      w8, #1
//   0x20c07c: F900041F  str      xzr, [x0, #8]
//   0x20c080: F9400029  ldr      x9, [x1]
//   0x20c084: F9000409  str      x9, [x0, #8]
uint64_t fde_func_01379_0x20c070(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0020C070ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017C1FULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x52800028ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF900041FULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400029ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000409ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400429ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000809ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #01389 | PC: 0x20c3f0..0x20c470 (128 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x20c3f0: D503233F  paciasp  
//   0x20c3f4: A9BD7BFD  stp      x29, x30, [sp, #-0x30]!
//   0x20c3f8: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x20c3fc: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x20c400: 910003FD  mov      x29, sp
//   0x20c404: 91002015  add      x21, x0, #8
uint64_t fde_func_01389_0x20c3f0(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0020C3F0ULL);
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

// FDE #01398 | PC: 0x20c760..0x20c7a4 (68 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x20c760: D503233F  paciasp  
//   0x20c764: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x20c768: F9000BF3  str      x19, [sp, #0x10]
//   0x20c76c: 910003FD  mov      x29, sp
//   0x20c770: F9400008  ldr      x8, [x0]
//   0x20c774: B4000108  cbz      x8, #0x20c794
uint64_t fde_func_01398_0x20c760(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0020C760ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF3ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400008ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB4000108ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9400000AULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #01408 | PC: 0x20ce24..0x20cea4 (128 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x20ce24: D503233F  paciasp  
//   0x20ce28: A9BD7BFD  stp      x29, x30, [sp, #-0x30]!
//   0x20ce2c: F9000BF5  str      x21, [sp, #0x10]
//   0x20ce30: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x20ce34: 910003FD  mov      x29, sp
//   0x20ce38: AA0003F4  mov      x20, x0
uint64_t fde_func_01408_0x20ce24(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0020CE24ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BD7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF5ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9024FF4ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F4ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x52800500ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0103F5ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #01417 | PC: 0x20d190..0x20d250 (192 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x20d190: D503233F  paciasp  
//   0x20d194: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x20d198: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x20d19c: 910003FD  mov      x29, sp
//   0x20d1a0: AA0103F4  mov      x20, x1
//   0x20d1a4: AA0003F3  mov      x19, x0
uint64_t fde_func_01417_0x20d190(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0020D190ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9014FF4ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0103F4ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x97FF92C5ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400668ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #01427 | PC: 0x20d718..0x20d780 (104 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x20d718: D503233F  paciasp  
//   0x20d71c: A9BC7BFD  stp      x29, x30, [sp, #-0x40]!
//   0x20d720: F9000BF7  str      x23, [sp, #0x10]
//   0x20d724: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x20d728: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x20d72c: 910003FD  mov      x29, sp
uint64_t fde_func_01427_0x20d718(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0020D718ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BC7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF7ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90257F6ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9034FF4ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0503F3ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x2A0403F4ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #01436 | PC: 0x20dae8..0x20db3c (84 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x20dae8: D503233F  paciasp  
//   0x20daec: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x20daf0: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x20daf4: 910003FD  mov      x29, sp
//   0x20daf8: AA0103F4  mov      x20, x1
//   0x20dafc: 2A1F03E1  mov      w1, wzr
uint64_t fde_func_01436_0x20dae8(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0020DAE8ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9014FF4ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0103F4ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x2A1F03E1ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x52801702ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #01446 | PC: 0x20dff8..0x20e068 (112 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x20dff8: D503233F  paciasp  
//   0x20dffc: A9BD7BFD  stp      x29, x30, [sp, #-0x30]!
//   0x20e000: F9000BF5  str      x21, [sp, #0x10]
//   0x20e004: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x20e008: 910003FD  mov      x29, sp
//   0x20e00c: A900FC1F  stp      xzr, xzr, [x0, #8]
uint64_t fde_func_01446_0x20dff8(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0020DFF8ULL);
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

// FDE #01455 | PC: 0x20e340..0x20e3a0 (96 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x20e340: D503233F  paciasp  
//   0x20e344: A9BD7BFD  stp      x29, x30, [sp, #-0x30]!
//   0x20e348: F9000BF5  str      x21, [sp, #0x10]
//   0x20e34c: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x20e350: 910003FD  mov      x29, sp
//   0x20e354: AA0003F4  mov      x20, x0
uint64_t fde_func_01455_0x20e340(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0020E340ULL);
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

// FDE #01465 | PC: 0x20e620..0x20e658 (56 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x20e620: D503233F  paciasp  
//   0x20e624: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x20e628: F9000BF3  str      x19, [sp, #0x10]
//   0x20e62c: 910003FD  mov      x29, sp
//   0x20e630: 39400008  ldrb     w8, [x0]
//   0x20e634: 340000A8  cbz      w8, #0x20e648
uint64_t fde_func_01465_0x20e620(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0020E620ULL);
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

// FDE #01474 | PC: 0x20eb90..0x20ebe0 (80 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x20eb90: D503233F  paciasp  
//   0x20eb94: A9BD7BFD  stp      x29, x30, [sp, #-0x30]!
//   0x20eb98: F9000BF5  str      x21, [sp, #0x10]
//   0x20eb9c: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x20eba0: 910003FD  mov      x29, sp
//   0x20eba4: AA0103F3  mov      x19, x1
uint64_t fde_func_01474_0x20eb90(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0020EB90ULL);
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

// FDE #01484 | PC: 0x20f6d4..0x20f7d4 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x20f6d4: D503233F  paciasp  
//   0x20f6d8: D101C3FF  sub      sp, sp, #0x70
//   0x20f6dc: A9037BFD  stp      x29, x30, [sp, #0x30]
//   0x20f6e0: A9045FF8  stp      x24, x23, [sp, #0x40]
//   0x20f6e4: A90557F6  stp      x22, x21, [sp, #0x50]
//   0x20f6e8: A9064FF4  stp      x20, x19, [sp, #0x60]
uint64_t fde_func_01484_0x20f6d4(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0020F6D4ULL);
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

// FDE #01494 | PC: 0x20fe8c..0x20ff8c (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x20fe8c: D503233F  paciasp  
//   0x20fe90: D101C3FF  sub      sp, sp, #0x70
//   0x20fe94: A9037BFD  stp      x29, x30, [sp, #0x30]
//   0x20fe98: A9045FF8  stp      x24, x23, [sp, #0x40]
//   0x20fe9c: A90557F6  stp      x22, x21, [sp, #0x50]
//   0x20fea0: A9064FF4  stp      x20, x19, [sp, #0x60]
uint64_t fde_func_01494_0x20fe8c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0020FE8CULL);
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

// FDE #01503 | PC: 0x210394..0x210494 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x210394: D503233F  paciasp  
//   0x210398: D10783FF  sub      sp, sp, #0x1e0
//   0x21039c: A9187BFD  stp      x29, x30, [sp, #0x180]
//   0x2103a0: F900CBFC  str      x28, [sp, #0x190]
//   0x2103a4: A91A67FA  stp      x26, x25, [sp, #0x1a0]
//   0x2103a8: A91B5FF8  stp      x24, x23, [sp, #0x1b0]
uint64_t fde_func_01503_0x210394(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00210394ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10783FFULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9187BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF900CBFCULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA91A67FAULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA91B5FF8ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA91C57F6ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA91D4FF4ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #01513 | PC: 0x210aac..0x210ad4 (40 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x210aac: D503245F  bti      c
//   0x210ab0: B941C008  ldr      w8, [x0, #0x1c0]
//   0x210ab4: 6B02011F  cmp      w8, w2
//   0x210ab8: 5400006A  b.ge     #0x210ac4
//   0x210abc: 52800020  mov      w0, #1
//   0x210ac0: D65F03C0  ret      
uint64_t fde_func_01513_0x210aac(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00210AACULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB941C008ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x6B02011FULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x5400006AULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x52800020ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD65F03C0ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF940DC08ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xEB01011FULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #01522 | PC: 0x2112f8..0x2113f8 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x2112f8: D503233F  paciasp  
//   0x2112fc: A9BD7BFD  stp      x29, x30, [sp, #-0x30]!
//   0x211300: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x211304: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x211308: 910003FD  mov      x29, sp
//   0x21130c: 39410008  ldrb     w8, [x0, #0x40]
uint64_t fde_func_01522_0x2112f8(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x002112F8ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BD7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90157F6ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9024FF4ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x39410008ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x39410029ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x6B09011FULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #01532 | PC: 0x211dec..0x211e84 (152 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x211dec: D503233F  paciasp  
//   0x211df0: A9BC7BFD  stp      x29, x30, [sp, #-0x40]!
//   0x211df4: F9000BF7  str      x23, [sp, #0x10]
//   0x211df8: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x211dfc: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x211e00: 910003FD  mov      x29, sp
uint64_t fde_func_01532_0x211dec(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00211DECULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BC7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF7ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90257F6ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9034FF4ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F4ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0103F3ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #01541 | PC: 0x2122c8..0x2123a8 (224 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x2122c8: D503233F  paciasp  
//   0x2122cc: D10183FF  sub      sp, sp, #0x60
//   0x2122d0: A9037BFD  stp      x29, x30, [sp, #0x30]
//   0x2122d4: A90457F6  stp      x22, x21, [sp, #0x40]
//   0x2122d8: A9054FF4  stp      x20, x19, [sp, #0x50]
//   0x2122dc: 9100C3FD  add      x29, sp, #0x30
uint64_t fde_func_01541_0x2122c8(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x002122C8ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10183FFULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9037BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90457F6ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9054FF4ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9100C3FDULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F5ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #01551 | PC: 0x2127d8..0x2128bc (228 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x2127d8: D503233F  paciasp  
//   0x2127dc: D10103FF  sub      sp, sp, #0x40
//   0x2127e0: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x2127e4: F9001BF3  str      x19, [sp, #0x30]
//   0x2127e8: 910083FD  add      x29, sp, #0x20
//   0x2127ec: AA0003F3  mov      x19, x0
uint64_t fde_func_01551_0x2127d8(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x002127D8ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10103FFULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9027BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9001BF3ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910083FDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9100C002ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB9406003ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #01560 | PC: 0x2131f0..0x213214 (36 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x2131f0: D503233F  paciasp  
//   0x2131f4: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x2131f8: 910003FD  mov      x29, sp
//   0x2131fc: F9401C08  ldr      x8, [x0, #0x38]
//   0x213200: B5000088  cbnz     x8, #0x213210
//   0x213204: A8C17BFD  ldp      x29, x30, [sp], #0x10
uint64_t fde_func_01560_0x2131f0(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x002131F0ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BF7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9401C08ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB5000088ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA8C17BFDULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD50323BFULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD65F03C0ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #01570 | PC: 0x213ffc..0x214008 (12 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x213ffc: D503245F  bti      c
//   0x214000: AA1F03E0  mov      x0, xzr
//   0x214004: D65F03C0  ret      
uint64_t fde_func_01570_0x213ffc(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00213FFCULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA1F03E0ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD65F03C0ULL ^ (2ULL << 32);
    return state ^ (state >> 29);
}

// FDE #01579 | PC: 0x214574..0x214580 (12 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x214574: D503245F  bti      c
//   0x214578: F900011F  str      xzr, [x8]
//   0x21457c: D65F03C0  ret      
uint64_t fde_func_01579_0x214574(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00214574ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF900011FULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD65F03C0ULL ^ (2ULL << 32);
    return state ^ (state >> 29);
}

// FDE #01589 | PC: 0x214774..0x2147cc (88 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x214774: D503233F  paciasp  
//   0x214778: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x21477c: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x214780: 910003FD  mov      x29, sp
//   0x214784: AA0003F3  mov      x19, x0
//   0x214788: A9405020  ldp      x0, x20, [x1]
uint64_t fde_func_01589_0x214774(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00214774ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9014FF4ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9405020ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA1403E1ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x97FFFFCDULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #01598 | PC: 0x214968..0x21497c (20 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x214968: D503245F  bti      c
//   0x21496c: AA0803E0  mov      x0, x8
//   0x214970: B0FFF6E1  adrp     x1, #0xf1000
//   0x214974: 91360021  add      x1, x1, #0xd80
//   0x214978: 17FEED3B  b        #0x1cfe64
uint64_t fde_func_01598_0x214968(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00214968ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0803E0ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB0FFF6E1ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91360021ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x17FEED3BULL ^ (4ULL << 32);
    return state ^ (state >> 29);
}

// FDE #01608 | PC: 0x214f70..0x214f7c (12 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x214f70: D503245F  bti      c
//   0x214f74: AA1F03E1  mov      x1, xzr
//   0x214f78: 17FFFFDD  b        #0x214eec
uint64_t fde_func_01608_0x214f70(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00214F70ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA1F03E1ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x17FFFFDDULL ^ (2ULL << 32);
    return state ^ (state >> 29);
}

// FDE #01617 | PC: 0x215304..0x215358 (84 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x215304: D503245F  bti      c
//   0x215308: F9400408  ldr      x8, [x0, #8]
//   0x21530c: B40000C8  cbz      x8, #0x215324
//   0x215310: F9400008  ldr      x8, [x0]
//   0x215314: B40001E8  cbz      x8, #0x215350
//   0x215318: 91001108  add      x8, x8, #4
uint64_t fde_func_01617_0x215304(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00215304ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400408ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB40000C8ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400008ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB40001E8ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91001108ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x08DFFD08ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x35000188ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #01627 | PC: 0x215884..0x215924 (160 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x215884: D503245F  bti      c
//   0x215888: 71000C3F  cmp      w1, #3
//   0x21588c: 7A420840  ccmp     w2, #2, #0, eq
//   0x215890: 54000080  b.eq     #0x2158a0
//   0x215894: 7100083F  cmp      w1, #2
//   0x215898: 7A430840  ccmp     w2, #3, #0, eq
uint64_t fde_func_01627_0x215884(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00215884ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x71000C3FULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x7A420840ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x54000080ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x7100083FULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x7A430840ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x54000421ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #01636 | PC: 0x215f58..0x215f64 (12 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x215f58: D503245F  bti      c
//   0x215f5c: D1006000  sub      x0, x0, #0x18
//   0x215f60: 17FFFC07  b        #0x214f7c
uint64_t fde_func_01636_0x215f58(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00215F58ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD1006000ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x17FFFC07ULL ^ (2ULL << 32);
    return state ^ (state >> 29);
}

// FDE #01646 | PC: 0x216e5c..0x216e94 (56 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x216e5c: D503233F  paciasp  
//   0x216e60: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x216e64: F9000BF3  str      x19, [sp, #0x10]
//   0x216e68: 910003FD  mov      x29, sp
//   0x216e6c: 39400008  ldrb     w8, [x0]
//   0x216e70: 340000A8  cbz      w8, #0x216e84
uint64_t fde_func_01646_0x216e5c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00216E5CULL);
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

// FDE #01655 | PC: 0x2175cc..0x217604 (56 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x2175cc: D503233F  paciasp  
//   0x2175d0: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x2175d4: 910003FD  mov      x29, sp
//   0x2175d8: F9401C08  ldr      x8, [x0, #0x38]
//   0x2175dc: B40000E8  cbz      x8, #0x2175f8
//   0x2175e0: 97FFEB22  bl       #0x212268
uint64_t fde_func_01655_0x2175cc(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x002175CCULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BF7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9401C08ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB40000E8ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x97FFEB22ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91006008ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x79400100ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #01665 | PC: 0x217eec..0x217fa4 (184 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x217eec: D503233F  paciasp  
//   0x217ef0: D101C3FF  sub      sp, sp, #0x70
//   0x217ef4: A9037BFD  stp      x29, x30, [sp, #0x30]
//   0x217ef8: F90023F7  str      x23, [sp, #0x40]
//   0x217efc: A90557F6  stp      x22, x21, [sp, #0x50]
//   0x217f00: A9064FF4  stp      x20, x19, [sp, #0x60]
uint64_t fde_func_01665_0x217eec(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00217EECULL);
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

// FDE #01674 | PC: 0x2185c4..0x21860c (72 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x2185c4: D503233F  paciasp  
//   0x2185c8: D10103FF  sub      sp, sp, #0x40
//   0x2185cc: A9037BFD  stp      x29, x30, [sp, #0x30]
//   0x2185d0: 9100C3FD  add      x29, sp, #0x30
//   0x2185d4: 910023E8  add      x8, sp, #8
//   0x2185d8: 12800009  mov      w9, #-1
uint64_t fde_func_01674_0x2185c4(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x002185C4ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10103FFULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9037BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9100C3FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910023E8ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x12800009ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91004108ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB9000009ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #01684 | PC: 0x218c20..0x218c3c (28 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x218c20: D503245F  bti      c
//   0x218c24: AA0003E8  mov      x8, x0
//   0x218c28: F9400000  ldr      x0, [x0]
//   0x218c2c: F900011F  str      xzr, [x8]
//   0x218c30: B4000040  cbz      x0, #0x218c38
//   0x218c34: 14004179  b        #0x229218
uint64_t fde_func_01684_0x218c20(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00218C20ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003E8ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400000ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF900011FULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB4000040ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x14004179ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD65F03C0ULL ^ (6ULL << 32);
    return state ^ (state >> 29);
}

// FDE #01693 | PC: 0x218f08..0x218f18 (16 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x218f08: D503245F  bti      c
//   0x218f0c: 52800028  mov      w8, #1
//   0x218f10: 38008408  strb     w8, [x0], #8
//   0x218f14: 17FFD53D  b        #0x20e408
uint64_t fde_func_01693_0x218f08(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00218F08ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x52800028ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x38008408ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x17FFD53DULL ^ (3ULL << 32);
    return state ^ (state >> 29);
}

// FDE #01703 | PC: 0x219360..0x2193a0 (64 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x219360: D503233F  paciasp  
//   0x219364: D10083FF  sub      sp, sp, #0x20
//   0x219368: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x21936c: 910043FD  add      x29, sp, #0x10
//   0x219370: A9422009  ldp      x9, x8, [x0, #0x20]
//   0x219374: F900141F  str      xzr, [x0, #0x28]
uint64_t fde_func_01703_0x219360(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00219360ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10083FFULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9422009ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF900141FULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9401801ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910023E0ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #01712 | PC: 0x2195c8..0x2196c8 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x2195c8: D503233F  paciasp  
//   0x2195cc: D10383FF  sub      sp, sp, #0xe0
//   0x2195d0: A9087BFD  stp      x29, x30, [sp, #0x80]
//   0x2195d4: A9096FFC  stp      x28, x27, [sp, #0x90]
//   0x2195d8: A90A67FA  stp      x26, x25, [sp, #0xa0]
//   0x2195dc: A90B5FF8  stp      x24, x23, [sp, #0xb0]
uint64_t fde_func_01712_0x2195c8(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x002195C8ULL);
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

// FDE #01722 | PC: 0x21b04c..0x21b14c (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x21b04c: D503233F  paciasp  
//   0x21b050: D103C3FF  sub      sp, sp, #0xf0
//   0x21b054: A9097BFD  stp      x29, x30, [sp, #0x90]
//   0x21b058: A90A6FFC  stp      x28, x27, [sp, #0xa0]
//   0x21b05c: A90B67FA  stp      x26, x25, [sp, #0xb0]
//   0x21b060: A90C5FF8  stp      x24, x23, [sp, #0xc0]
uint64_t fde_func_01722_0x21b04c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0021B04CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD103C3FFULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9097BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90A6FFCULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90B67FAULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90C5FF8ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90D57F6ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90E4FF4ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #01731 | PC: 0x21be04..0x21bf04 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x21be04: D503233F  paciasp  
//   0x21be08: A9BA7BFD  stp      x29, x30, [sp, #-0x60]!
//   0x21be0c: A9016FFC  stp      x28, x27, [sp, #0x10]
//   0x21be10: A90267FA  stp      x26, x25, [sp, #0x20]
//   0x21be14: A9035FF8  stp      x24, x23, [sp, #0x30]
//   0x21be18: A90457F6  stp      x22, x21, [sp, #0x40]
uint64_t fde_func_01731_0x21be04(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0021BE04ULL);
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

// FDE #01741 | PC: 0x21caf0..0x21cbb4 (196 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x21caf0: D503233F  paciasp  
//   0x21caf4: D10143FF  sub      sp, sp, #0x50
//   0x21caf8: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x21cafc: A90357F6  stp      x22, x21, [sp, #0x30]
//   0x21cb00: A9044FF4  stp      x20, x19, [sp, #0x40]
//   0x21cb04: 910083FD  add      x29, sp, #0x20
uint64_t fde_func_01741_0x21caf0(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0021CAF0ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10143FFULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9027BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90357F6ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9044FF4ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910083FDULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F4ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x97FF5750ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #01750 | PC: 0x21cfec..0x21d044 (88 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x21cfec: D503233F  paciasp  
//   0x21cff0: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x21cff4: F9000BF3  str      x19, [sp, #0x10]
//   0x21cff8: 910003FD  mov      x29, sp
//   0x21cffc: F9400013  ldr      x19, [x0]
//   0x21d000: F9000001  str      x1, [x0]
uint64_t fde_func_01750_0x21cfec(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0021CFECULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF3ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400013ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000001ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB4000193ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400260ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #01760 | PC: 0x21d6b0..0x21d6bc (12 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x21d6b0: D503245F  bti      c
//   0x21d6b4: AA1F03E1  mov      x1, xzr
//   0x21d6b8: 17FFEC17  b        #0x218714
uint64_t fde_func_01760_0x21d6b0(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0021D6B0ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA1F03E1ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x17FFEC17ULL ^ (2ULL << 32);
    return state ^ (state >> 29);
}

// FDE #01769 | PC: 0x221408..0x2214e8 (224 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x221408: D503233F  paciasp  
//   0x22140c: A9BC7BFD  stp      x29, x30, [sp, #-0x40]!
//   0x221410: F9000BF7  str      x23, [sp, #0x10]
//   0x221414: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x221418: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x22141c: 910003FD  mov      x29, sp
uint64_t fde_func_01769_0x221408(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00221408ULL);
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

// FDE #01779 | PC: 0x2220c0..0x222108 (72 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x2220c0: D503233F  paciasp  
//   0x2220c4: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x2220c8: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x2220cc: 910003FD  mov      x29, sp
//   0x2220d0: AA0003F4  mov      x20, x0
//   0x2220d4: F9400000  ldr      x0, [x0]
uint64_t fde_func_01779_0x2220c0(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x002220C0ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9014FF4ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F4ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400000ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0103F3ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9402E936ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #01789 | PC: 0x22289c..0x2228d4 (56 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x22289c: D503245F  bti      c
//   0x2228a0: A942A009  ldp      x9, x8, [x0, #0x28]
//   0x2228a4: AA0303E4  mov      x4, x3
//   0x2228a8: 2A0203E3  mov      w3, w2
//   0x2228ac: F9401010  ldr      x16, [x0, #0x20]
//   0x2228b0: 8B890508  add      x8, x8, x9, asr #1
uint64_t fde_func_01789_0x22289c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0022289CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA942A009ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0303E4ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x2A0203E3ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9401010ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x8B890508ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x36000069ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400109ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #01798 | PC: 0x2235fc..0x223678 (124 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x2235fc: D503233F  paciasp  
//   0x223600: D10143FF  sub      sp, sp, #0x50
//   0x223604: A9037BFD  stp      x29, x30, [sp, #0x30]
//   0x223608: A9044FF4  stp      x20, x19, [sp, #0x40]
//   0x22360c: 9100C3FD  add      x29, sp, #0x30
//   0x223610: AA0003F3  mov      x19, x0
uint64_t fde_func_01798_0x2235fc(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x002235FCULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10143FFULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9037BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9044FF4ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9100C3FDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9100A000ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x3CC28260ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #01808 | PC: 0x223a04..0x223b04 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x223a04: D503233F  paciasp  
//   0x223a08: D10203FF  sub      sp, sp, #0x80
//   0x223a0c: A9047BFD  stp      x29, x30, [sp, #0x40]
//   0x223a10: A9055FF8  stp      x24, x23, [sp, #0x50]
//   0x223a14: A90657F6  stp      x22, x21, [sp, #0x60]
//   0x223a18: A9074FF4  stp      x20, x19, [sp, #0x70]
uint64_t fde_func_01808_0x223a04(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00223A04ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10203FFULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9047BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9055FF8ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90657F6ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9074FF4ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910103FDULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #01817 | PC: 0x223fac..0x2240ac (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x223fac: D503233F  paciasp  
//   0x223fb0: D10183FF  sub      sp, sp, #0x60
//   0x223fb4: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x223fb8: F9001BF7  str      x23, [sp, #0x30]
//   0x223fbc: A90457F6  stp      x22, x21, [sp, #0x40]
//   0x223fc0: A9054FF4  stp      x20, x19, [sp, #0x50]
uint64_t fde_func_01817_0x223fac(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00223FACULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10183FFULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9027BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9001BF7ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90457F6ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9054FF4ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910083FDULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0103E8ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #01827 | PC: 0x22422c..0x22427c (80 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x22422c: D503233F  paciasp  
//   0x224230: A9BD7BFD  stp      x29, x30, [sp, #-0x30]!
//   0x224234: F9000BF5  str      x21, [sp, #0x10]
//   0x224238: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x22423c: 910003FD  mov      x29, sp
//   0x224240: AA0103F3  mov      x19, x1
uint64_t fde_func_01827_0x22422c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0022422CULL);
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

// FDE #01836 | PC: 0x2248a0..0x2249a0 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x2248a0: D503233F  paciasp  
//   0x2248a4: D10243FF  sub      sp, sp, #0x90
//   0x2248a8: A9057BFD  stp      x29, x30, [sp, #0x50]
//   0x2248ac: F90033F7  str      x23, [sp, #0x60]
//   0x2248b0: A90757F6  stp      x22, x21, [sp, #0x70]
//   0x2248b4: A9084FF4  stp      x20, x19, [sp, #0x80]
uint64_t fde_func_01836_0x2248a0(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x002248A0ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10243FFULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9057BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF90033F7ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90757F6ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9084FF4ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910143FDULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x394CE008ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #01846 | PC: 0x224d38..0x224d48 (16 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x224d38: D503245F  bti      c
//   0x224d3c: 91006001  add      x1, x0, #0x18
//   0x224d40: AA0803E0  mov      x0, x8
//   0x224d44: 140D8859  b        #0x586ea8
uint64_t fde_func_01846_0x224d38(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00224D38ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91006001ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0803E0ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x140D8859ULL ^ (3ULL << 32);
    return state ^ (state >> 29);
}

// FDE #01855 | PC: 0x22517c..0x225274 (248 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x22517c: D503233F  paciasp  
//   0x225180: D101C3FF  sub      sp, sp, #0x70
//   0x225184: A9037BFD  stp      x29, x30, [sp, #0x30]
//   0x225188: F90023F7  str      x23, [sp, #0x40]
//   0x22518c: A90557F6  stp      x22, x21, [sp, #0x50]
//   0x225190: A9064FF4  stp      x20, x19, [sp, #0x60]
uint64_t fde_func_01855_0x22517c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0022517CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD101C3FFULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9037BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF90023F7ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90557F6ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9064FF4ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9100C3FDULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB949B008ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #01865 | PC: 0x227bb4..0x227c4c (152 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x227bb4: D503233F  paciasp  
//   0x227bb8: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x227bbc: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x227bc0: 910003FD  mov      x29, sp
//   0x227bc4: AA0103F4  mov      x20, x1
//   0x227bc8: AA0003F3  mov      x19, x0
uint64_t fde_func_01865_0x227bb4(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00227BB4ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9014FF4ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0103F4ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x78408428ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91002000ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #01874 | PC: 0x228d28..0x228e28 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x228d28: D503233F  paciasp  
//   0x228d2c: D101C3FF  sub      sp, sp, #0x70
//   0x228d30: A9037BFD  stp      x29, x30, [sp, #0x30]
//   0x228d34: F90023F7  str      x23, [sp, #0x40]
//   0x228d38: A90557F6  stp      x22, x21, [sp, #0x50]
//   0x228d3c: A9064FF4  stp      x20, x19, [sp, #0x60]
uint64_t fde_func_01874_0x228d28(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00228D28ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD101C3FFULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9037BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF90023F7ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90557F6ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9064FF4ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9100C3FDULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9412408ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #01884 | PC: 0x229a3c..0x229ab8 (124 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x229a3c: D503233F  paciasp  
//   0x229a40: D10183FF  sub      sp, sp, #0x60
//   0x229a44: A9037BFD  stp      x29, x30, [sp, #0x30]
//   0x229a48: A90457F6  stp      x22, x21, [sp, #0x40]
//   0x229a4c: A9054FF4  stp      x20, x19, [sp, #0x50]
//   0x229a50: 9100C3FD  add      x29, sp, #0x30
uint64_t fde_func_01884_0x229a3c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00229A3CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10183FFULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9037BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90457F6ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9054FF4ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9100C3FDULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910023E8ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F5ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #01893 | PC: 0x229df8..0x229e04 (12 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x229df8: D503245F  bti      c
//   0x229dfc: D1004000  sub      x0, x0, #0x10
//   0x229e00: 17FFFF2E  b        #0x229ab8
uint64_t fde_func_01893_0x229df8(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00229DF8ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD1004000ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x17FFFF2EULL ^ (2ULL << 32);
    return state ^ (state >> 29);
}

// FDE #01903 | PC: 0x22a63c..0x22a678 (60 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x22a63c: D503245F  bti      c
//   0x22a640: B40001A0  cbz      x0, #0x22a674
//   0x22a644: D503233F  paciasp  
//   0x22a648: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x22a64c: F9000BF3  str      x19, [sp, #0x10]
//   0x22a650: 910003FD  mov      x29, sp
uint64_t fde_func_01903_0x22a63c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0022A63CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB40001A0ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE7BFDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF3ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91012000ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #01912 | PC: 0x22ae60..0x22af60 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x22ae60: D503233F  paciasp  
//   0x22ae64: D10183FF  sub      sp, sp, #0x60
//   0x22ae68: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x22ae6c: A90267FA  stp      x26, x25, [sp, #0x20]
//   0x22ae70: A9035FF8  stp      x24, x23, [sp, #0x30]
//   0x22ae74: A90457F6  stp      x22, x21, [sp, #0x40]
uint64_t fde_func_01912_0x22ae60(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0022AE60ULL);
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

// FDE #01922 | PC: 0x22b79c..0x22b7a8 (12 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x22b79c: D503245F  bti      c
//   0x22b7a0: D1002000  sub      x0, x0, #8
//   0x22b7a4: 17FFFF72  b        #0x22b56c
uint64_t fde_func_01922_0x22b79c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0022B79CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD1002000ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x17FFFF72ULL ^ (2ULL << 32);
    return state ^ (state >> 29);
}

// FDE #01931 | PC: 0x22bbe0..0x22bc7c (156 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x22bbe0: D503233F  paciasp  
//   0x22bbe4: A9BD7BFD  stp      x29, x30, [sp, #-0x30]!
//   0x22bbe8: F9000BF5  str      x21, [sp, #0x10]
//   0x22bbec: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x22bbf0: 910003FD  mov      x29, sp
//   0x22bbf4: F9400013  ldr      x19, [x0]
uint64_t fde_func_01931_0x22bbe0(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0022BBE0ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BD7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF5ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9024FF4ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400013ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA1F03E8ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9C75269ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #01941 | PC: 0x22c244..0x22c290 (76 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x22c244: D503233F  paciasp  
//   0x22c248: A9BD7BFD  stp      x29, x30, [sp, #-0x30]!
//   0x22c24c: F9000BF5  str      x21, [sp, #0x10]
//   0x22c250: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x22c254: 910003FD  mov      x29, sp
//   0x22c258: A9405015  ldp      x21, x20, [x0]
uint64_t fde_func_01941_0x22c244(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0022C244ULL);
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

// FDE #01950 | PC: 0x22c85c..0x22c874 (24 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x22c85c: D503245F  bti      c
//   0x22c860: AA0003E8  mov      x8, x0
//   0x22c864: 91006000  add      x0, x0, #0x18
//   0x22c868: A9007D1F  stp      xzr, xzr, [x8]
//   0x22c86c: F900091F  str      xzr, [x8, #0x10]
//   0x22c870: 1402EFB6  b        #0x2e8748
uint64_t fde_func_01950_0x22c85c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0022C85CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003E8ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91006000ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9007D1FULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF900091FULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x1402EFB6ULL ^ (5ULL << 32);
    return state ^ (state >> 29);
}

// FDE #01960 | PC: 0x22cd5c..0x22cd88 (44 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x22cd5c: D503233F  paciasp  
//   0x22cd60: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x22cd64: F9000BF3  str      x19, [sp, #0x10]
//   0x22cd68: 910003FD  mov      x29, sp
//   0x22cd6c: AA0003F3  mov      x19, x0
//   0x22cd70: 97FFFFE1  bl       #0x22ccf4
uint64_t fde_func_01960_0x22cd5c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0022CD5CULL);
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

// FDE #01969 | PC: 0x22d0f0..0x22d11c (44 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x22d0f0: D503245F  bti      c
//   0x22d0f4: B200CFE8  mov      x8, #0xf0f0f0f0f0f0f0f
//   0x22d0f8: F281E208  movk     x8, #0xf10
//   0x22d0fc: EB08001F  cmp      x0, x8
//   0x22d100: 54000062  b.hs     #0x22d10c
//   0x22d104: 8B001000  add      x0, x0, x0, lsl #4
uint64_t fde_func_01969_0x22d0f0(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0022D0F0ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB200CFE8ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF281E208ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xEB08001FULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x54000062ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x8B001000ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x1402BD1BULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #01979 | PC: 0x22d654..0x22d69c (72 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x22d654: D503233F  paciasp  
//   0x22d658: D100C3FF  sub      sp, sp, #0x30
//   0x22d65c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x22d660: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x22d664: 910043FD  add      x29, sp, #0x10
//   0x22d668: AA0103F3  mov      x19, x1
uint64_t fde_func_01979_0x22d654(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0022D654ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD100C3FFULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9024FF4ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0103F3ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F4ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003E0ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #01988 | PC: 0x22e424..0x22e4ac (136 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x22e424: D503233F  paciasp  
//   0x22e428: D10143FF  sub      sp, sp, #0x50
//   0x22e42c: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x22e430: F9001BF5  str      x21, [sp, #0x30]
//   0x22e434: A9044FF4  stp      x20, x19, [sp, #0x40]
//   0x22e438: 910083FD  add      x29, sp, #0x20
uint64_t fde_func_01988_0x22e424(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0022E424ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10143FFULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9027BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9001BF5ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9044FF4ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910083FDULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F4ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF0001C40ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #01998 | PC: 0x22e970..0x22ea40 (208 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x22e970: D503233F  paciasp  
//   0x22e974: D101C3FF  sub      sp, sp, #0x70
//   0x22e978: A9037BFD  stp      x29, x30, [sp, #0x30]
//   0x22e97c: A9045FF8  stp      x24, x23, [sp, #0x40]
//   0x22e980: A90557F6  stp      x22, x21, [sp, #0x50]
//   0x22e984: A9064FF4  stp      x20, x19, [sp, #0x60]
uint64_t fde_func_01998_0x22e970(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0022E970ULL);
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

// FDE #02007 | PC: 0x22eae0..0x22eaf4 (20 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x22eae0: D503245F  bti      c
//   0x22eae4: F9400400  ldr      x0, [x0, #8]
//   0x22eae8: F9400008  ldr      x8, [x0]
//   0x22eaec: F9404110  ldr      x16, [x8, #0x80]
//   0x22eaf0: D61F0200  br       x16
uint64_t fde_func_02007_0x22eae0(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0022EAE0ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400400ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400008ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9404110ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD61F0200ULL ^ (4ULL << 32);
    return state ^ (state >> 29);
}

// FDE #02017 | PC: 0x22ec1c..0x22ec28 (12 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x22ec1c: D503245F  bti      c
//   0x22ec20: 528001E0  mov      w0, #0xf
//   0x22ec24: D65F03C0  ret      
uint64_t fde_func_02017_0x22ec1c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0022EC1CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x528001E0ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD65F03C0ULL ^ (2ULL << 32);
    return state ^ (state >> 29);
}

// FDE #02026 | PC: 0x22ed2c..0x22ee2c (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x22ed2c: D503233F  paciasp  
//   0x22ed30: D101C3FF  sub      sp, sp, #0x70
//   0x22ed34: A9037BFD  stp      x29, x30, [sp, #0x30]
//   0x22ed38: F90023F7  str      x23, [sp, #0x40]
//   0x22ed3c: A90557F6  stp      x22, x21, [sp, #0x50]
//   0x22ed40: A9064FF4  stp      x20, x19, [sp, #0x60]
uint64_t fde_func_02026_0x22ed2c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0022ED2CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD101C3FFULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9037BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF90023F7ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90557F6ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9064FF4ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9100C3FDULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9402408ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #02036 | PC: 0x23070c..0x230734 (40 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x23070c: D503245F  bti      c
//   0x230710: F9400028  ldr      x8, [x1]
//   0x230714: 785EE108  ldurh    w8, [x8, #-0x12]
//   0x230718: 7100051F  cmp      w8, #1
//   0x23071c: 54000081  b.ne     #0x23072c
//   0x230720: 91002000  add      x0, x0, #8
uint64_t fde_func_02036_0x23070c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0023070CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400028ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x785EE108ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x7100051FULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x54000081ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91002000ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91002021ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x1402EC6BULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #02045 | PC: 0x230804..0x230830 (44 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x230804: D503233F  paciasp  
//   0x230808: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x23080c: F9000BF3  str      x19, [sp, #0x10]
//   0x230810: 910003FD  mov      x29, sp
//   0x230814: AA0003F3  mov      x19, x0
//   0x230818: 97FFFFF6  bl       #0x2307f0
uint64_t fde_func_02045_0x230804(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00230804ULL);
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

// FDE #02055 | PC: 0x230950..0x2309a0 (80 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x230950: D503245F  bti      c
//   0x230954: F9400409  ldr      x9, [x0, #8]
//   0x230958: AA0203E8  mov      x8, x2
//   0x23095c: AA1F03EA  mov      x10, xzr
//   0x230960: CB030122  sub      x2, x9, x3
//   0x230964: 8B02002B  add      x11, x1, x2
uint64_t fde_func_02055_0x230950(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00230950ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400409ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0203E8ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA1F03EAULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xCB030122ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x8B02002BULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x8B0A016CULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xEB08019FULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #02064 | PC: 0x230bf4..0x230c10 (28 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x230bf4: D503245F  bti      c
//   0x230bf8: AA0003E8  mov      x8, x0
//   0x230bfc: F9400000  ldr      x0, [x0]
//   0x230c00: F900011F  str      xzr, [x8]
//   0x230c04: B4000040  cbz      x0, #0x230c0c
//   0x230c08: 1401B18B  b        #0x29d234
uint64_t fde_func_02064_0x230bf4(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00230BF4ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003E8ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400000ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF900011FULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB4000040ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x1401B18BULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD65F03C0ULL ^ (6ULL << 32);
    return state ^ (state >> 29);
}

// FDE #02074 | PC: 0x230f60..0x231060 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x230f60: D503233F  paciasp  
//   0x230f64: D10283FF  sub      sp, sp, #0xa0
//   0x230f68: A9057BFD  stp      x29, x30, [sp, #0x50]
//   0x230f6c: A90667FA  stp      x26, x25, [sp, #0x60]
//   0x230f70: A9075FF8  stp      x24, x23, [sp, #0x70]
//   0x230f74: A90857F6  stp      x22, x21, [sp, #0x80]
uint64_t fde_func_02074_0x230f60(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00230F60ULL);
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

// FDE #02084 | PC: 0x231778..0x2317c4 (76 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x231778: D503233F  paciasp  
//   0x23177c: D10083FF  sub      sp, sp, #0x20
//   0x231780: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x231784: 910043FD  add      x29, sp, #0x10
//   0x231788: A942240A  ldp      x10, x9, [x0, #0x20]
//   0x23178c: F900141F  str      xzr, [x0, #0x28]
uint64_t fde_func_02084_0x231778(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00231778ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10083FFULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA942240AULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF900141FULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910023E0ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF90007E9ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #02093 | PC: 0x231bf4..0x231c3c (72 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x231bf4: D503233F  paciasp  
//   0x231bf8: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x231bfc: F9000BF3  str      x19, [sp, #0x10]
//   0x231c00: 910003FD  mov      x29, sp
//   0x231c04: F9400013  ldr      x19, [x0]
//   0x231c08: F9000001  str      x1, [x0]
uint64_t fde_func_02093_0x231bf4(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00231BF4ULL);
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

// FDE #02103 | PC: 0x2320a4..0x2320f0 (76 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x2320a4: D503245F  bti      c
//   0x2320a8: B4000220  cbz      x0, #0x2320ec
//   0x2320ac: D503233F  paciasp  
//   0x2320b0: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x2320b4: F9000BF3  str      x19, [sp, #0x10]
//   0x2320b8: 910003FD  mov      x29, sp
uint64_t fde_func_02103_0x2320a4(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x002320A4ULL);
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

// FDE #02112 | PC: 0x2325bc..0x2326bc (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x2325bc: D503233F  paciasp  
//   0x2325c0: D10503FF  sub      sp, sp, #0x140
//   0x2325c4: A90F7BFD  stp      x29, x30, [sp, #0xf0]
//   0x2325c8: F90083FC  str      x28, [sp, #0x100]
//   0x2325cc: A9115FF8  stp      x24, x23, [sp, #0x110]
//   0x2325d0: A91257F6  stp      x22, x21, [sp, #0x120]
uint64_t fde_func_02112_0x2325bc(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x002325BCULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10503FFULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90F7BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF90083FCULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9115FF8ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA91257F6ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9134FF4ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9103C3FDULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #02122 | PC: 0x232c04..0x232c84 (128 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x232c04: D503233F  paciasp  
//   0x232c08: A9BD7BFD  stp      x29, x30, [sp, #-0x30]!
//   0x232c0c: F9000BF5  str      x21, [sp, #0x10]
//   0x232c10: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x232c14: 910003FD  mov      x29, sp
//   0x232c18: F940C414  ldr      x20, [x0, #0x188]
uint64_t fde_func_02122_0x232c04(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00232C04ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BD7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF5ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9024FF4ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF940C414ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB40000F4ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA1403E0ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #02131 | PC: 0x232efc..0x232f38 (60 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x232efc: D503233F  paciasp  
//   0x232f00: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x232f04: F9000BF3  str      x19, [sp, #0x10]
//   0x232f08: 910003FD  mov      x29, sp
//   0x232f0c: AA0003F3  mov      x19, x0
//   0x232f10: F9405C00  ldr      x0, [x0, #0xb8]
uint64_t fde_func_02131_0x232efc(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00232EFCULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF3ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9405C00ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x90001B28ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91274108ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #02141 | PC: 0x2334e8..0x23355c (116 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x2334e8: D503233F  paciasp  
//   0x2334ec: A9BD7BFD  stp      x29, x30, [sp, #-0x30]!
//   0x2334f0: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x2334f4: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x2334f8: 910003FD  mov      x29, sp
//   0x2334fc: F9400408  ldr      x8, [x0, #8]
uint64_t fde_func_02141_0x2334e8(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x002334E8ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BD7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90157F6ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9024FF4ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400408ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0103F3ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F4ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #02150 | PC: 0x233764..0x23377c (24 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x233764: D503245F  bti      c
//   0x233768: 39400008  ldrb     w8, [x0]
//   0x23376c: 34000068  cbz      w8, #0x233778
//   0x233770: 91002000  add      x0, x0, #8
//   0x233774: 140D4E03  b        #0x586f80
//   0x233778: 17FFFFBE  b        #0x233670
uint64_t fde_func_02150_0x233764(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00233764ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x39400008ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x34000068ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91002000ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x140D4E03ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x17FFFFBEULL ^ (5ULL << 32);
    return state ^ (state >> 29);
}

// FDE #02160 | PC: 0x233d08..0x233d54 (76 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x233d08: D503233F  paciasp  
//   0x233d0c: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x233d10: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x233d14: 910003FD  mov      x29, sp
//   0x233d18: AA0103F3  mov      x19, x1
//   0x233d1c: AA0003F4  mov      x20, x0
uint64_t fde_func_02160_0x233d08(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00233D08ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9014FF4ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0103F3ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F4ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400000ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400A81ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #02169 | PC: 0x234070..0x2340b4 (68 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x234070: D503245F  bti      c
//   0x234074: AA0003E8  mov      x8, x0
//   0x234078: 39400009  ldrb     w9, [x0]
//   0x23407c: 37000089  tbnz     w9, #0, #0x23408c
//   0x234080: 91000500  add      x0, x8, #1
//   0x234084: D341FD28  lsr      x8, x9, #1
uint64_t fde_func_02169_0x234070(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00234070ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003E8ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x39400009ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x37000089ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91000500ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD341FD28ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x14000002ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9408108ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #02179 | PC: 0x234490..0x2344d4 (68 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x234490: D503233F  paciasp  
//   0x234494: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x234498: F9000BF3  str      x19, [sp, #0x10]
//   0x23449c: 910003FD  mov      x29, sp
//   0x2344a0: 6F00E400  movi     v0.2d, #0000000000000000
//   0x2344a4: AA0003F3  mov      x19, x0
uint64_t fde_func_02179_0x234490(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00234490ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF3ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x6F00E400ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x3901001FULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x3D800C00ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #02188 | PC: 0x234c90..0x234cf8 (104 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x234c90: D503233F  paciasp  
//   0x234c94: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x234c98: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x234c9c: 910003FD  mov      x29, sp
//   0x234ca0: AA0103F3  mov      x19, x1
//   0x234ca4: AA0003F4  mov      x20, x0
uint64_t fde_func_02188_0x234c90(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00234C90ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9014FF4ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0103F3ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F4ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x3CC10420ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91004000ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #02198 | PC: 0x235830..0x23589c (108 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x235830: D503233F  paciasp  
//   0x235834: A9BD7BFD  stp      x29, x30, [sp, #-0x30]!
//   0x235838: F9000BF5  str      x21, [sp, #0x10]
//   0x23583c: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x235840: 910003FD  mov      x29, sp
//   0x235844: 91002013  add      x19, x0, #8
uint64_t fde_func_02198_0x235830(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00235830ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BD7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF5ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9024FF4ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91002013ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F5ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA1303E0ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #02207 | PC: 0x235fc4..0x2360c4 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x235fc4: D503233F  paciasp  
//   0x235fc8: D10603FF  sub      sp, sp, #0x180
//   0x235fcc: A9137BFD  stp      x29, x30, [sp, #0x130]
//   0x235fd0: F900A3FC  str      x28, [sp, #0x140]
//   0x235fd4: A9155FF8  stp      x24, x23, [sp, #0x150]
//   0x235fd8: A91657F6  stp      x22, x21, [sp, #0x160]
uint64_t fde_func_02207_0x235fc4(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00235FC4ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10603FFULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9137BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF900A3FCULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9155FF8ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA91657F6ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9174FF4ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9104C3FDULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #02217 | PC: 0x2364c8..0x2364f8 (48 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x2364c8: D503245F  bti      c
//   0x2364cc: D28C0008  mov      x8, #0x6000
//   0x2364d0: 93407C09  sxtw     x9, w0
//   0x2364d4: F2A3BAE8  movk     x8, #0x1dd7, lsl #16
//   0x2364d8: F2C00288  movk     x8, #0x14, lsl #32
//   0x2364dc: 9B087D2A  mul      x10, x9, x8
uint64_t fde_func_02217_0x2364c8(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x002364C8ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD28C0008ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x93407C09ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF2A3BAE8ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF2C00288ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9B087D2AULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9B487D28ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x935F7C09ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #02226 | PC: 0x236a30..0x236a7c (76 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x236a30: D503245F  bti      c
//   0x236a34: B4000220  cbz      x0, #0x236a78
//   0x236a38: D503233F  paciasp  
//   0x236a3c: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x236a40: F9000BF3  str      x19, [sp, #0x10]
//   0x236a44: 910003FD  mov      x29, sp
uint64_t fde_func_02226_0x236a30(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00236A30ULL);
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

// FDE #02236 | PC: 0x2373e0..0x237418 (56 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x2373e0: D503245F  bti      c
//   0x2373e4: B4000160  cbz      x0, #0x237410
//   0x2373e8: B4000141  cbz      x1, #0x237410
//   0x2373ec: D503233F  paciasp  
//   0x2373f0: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x2373f4: 910003FD  mov      x29, sp
uint64_t fde_func_02236_0x2373e0(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x002373E0ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB4000160ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB4000141ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BF7BFDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xCB010001ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0203E0ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #02245 | PC: 0x2375d0..0x237618 (72 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x2375d0: D503233F  paciasp  
//   0x2375d4: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x2375d8: 910003FD  mov      x29, sp
//   0x2375dc: 52800600  mov      w0, #0x30
//   0x2375e0: 940293E5  bl       #0x2dc574
//   0x2375e4: 6F07F600  fmov     v0.2d, #-1.00000000
uint64_t fde_func_02245_0x2375d0(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x002375D0ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BF7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x52800600ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x940293E5ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x6F07F600ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x12800008ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB900001FULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #02255 | PC: 0x237b24..0x237b6c (72 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x237b24: D503233F  paciasp  
//   0x237b28: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x237b2c: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x237b30: 910003FD  mov      x29, sp
//   0x237b34: 9112F013  add      x19, x0, #0x4bc
//   0x237b38: AA0003F4  mov      x20, x0
uint64_t fde_func_02255_0x237b24(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00237B24ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9014FF4ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9112F013ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F4ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA1303E0ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x97FECA06ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #02264 | PC: 0x239068..0x239168 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x239068: D503233F  paciasp  
//   0x23906c: D10603FF  sub      sp, sp, #0x180
//   0x239070: A9147BFD  stp      x29, x30, [sp, #0x140]
//   0x239074: A9155FFC  stp      x28, x23, [sp, #0x150]
//   0x239078: A91657F6  stp      x22, x21, [sp, #0x160]
//   0x23907c: A9174FF4  stp      x20, x19, [sp, #0x170]
uint64_t fde_func_02264_0x239068(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00239068ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10603FFULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9147BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9155FFCULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA91657F6ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9174FF4ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910503FDULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD53BD056ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #02274 | PC: 0x239bb4..0x239c60 (172 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x239bb4: D503233F  paciasp  
//   0x239bb8: D10183FF  sub      sp, sp, #0x60
//   0x239bbc: A9047BFD  stp      x29, x30, [sp, #0x40]
//   0x239bc0: A9054FF4  stp      x20, x19, [sp, #0x50]
//   0x239bc4: 910103FD  add      x29, sp, #0x40
//   0x239bc8: AA0003F4  mov      x20, x0
uint64_t fde_func_02274_0x239bb4(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00239BB4ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10183FFULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9047BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9054FF4ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910103FDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F4ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9113A000ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0103F3ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #02283 | PC: 0x239f04..0x239f8c (136 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x239f04: D503245F  bti      c
//   0x239f08: B4000401  cbz      x1, #0x239f88
//   0x239f0c: D503233F  paciasp  
//   0x239f10: A9BD7BFD  stp      x29, x30, [sp, #-0x30]!
//   0x239f14: F9000BF5  str      x21, [sp, #0x10]
//   0x239f18: A9024FF4  stp      x20, x19, [sp, #0x20]
uint64_t fde_func_02283_0x239f04(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00239F04ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB4000401ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BD7BFDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF5ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9024FF4ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91102015ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #02293 | PC: 0x23ac78..0x23ad78 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x23ac78: D503233F  paciasp  
//   0x23ac7c: D10343FF  sub      sp, sp, #0xd0
//   0x23ac80: A9077BFD  stp      x29, x30, [sp, #0x70]
//   0x23ac84: A9086FFC  stp      x28, x27, [sp, #0x80]
//   0x23ac88: A90967FA  stp      x26, x25, [sp, #0x90]
//   0x23ac8c: A90A5FF8  stp      x24, x23, [sp, #0xa0]
uint64_t fde_func_02293_0x23ac78(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0023AC78ULL);
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

// FDE #02302 | PC: 0x23ba14..0x23ba50 (60 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x23ba14: D503245F  bti      c
//   0x23ba18: B40001A0  cbz      x0, #0x23ba4c
//   0x23ba1c: D503233F  paciasp  
//   0x23ba20: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x23ba24: F9000BF3  str      x19, [sp, #0x10]
//   0x23ba28: 910003FD  mov      x29, sp
uint64_t fde_func_02302_0x23ba14(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0023BA14ULL);
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

// FDE #02312 | PC: 0x23bf44..0x23bf68 (36 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x23bf44: D503245F  bti      c
//   0x23bf48: A942A408  ldp      x8, x9, [x0, #0x28]
//   0x23bf4c: F9401010  ldr      x16, [x0, #0x20]
//   0x23bf50: F9401C01  ldr      x1, [x0, #0x38]
//   0x23bf54: 8B880520  add      x0, x9, x8, asr #1
//   0x23bf58: 36000068  tbz      w8, #0, #0x23bf64
uint64_t fde_func_02312_0x23bf44(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0023BF44ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA942A408ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9401010ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9401C01ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x8B880520ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x36000068ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400008ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF8706910ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #02321 | PC: 0x23c130..0x23c20c (220 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x23c130: D503233F  paciasp  
//   0x23c134: A9BC7BFD  stp      x29, x30, [sp, #-0x40]!
//   0x23c138: A9015FF8  stp      x24, x23, [sp, #0x10]
//   0x23c13c: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x23c140: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x23c144: 910003FD  mov      x29, sp
uint64_t fde_func_02321_0x23c130(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0023C130ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BC7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9015FF8ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90257F6ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9034FF4ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400434ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0203F6ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #02331 | PC: 0x23c774..0x23c848 (212 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x23c774: D503233F  paciasp  
//   0x23c778: A9BD7BFD  stp      x29, x30, [sp, #-0x30]!
//   0x23c77c: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x23c780: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x23c784: 910003FD  mov      x29, sp
//   0x23c788: AA0203F4  mov      x20, x2
uint64_t fde_func_02331_0x23c774(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0023C774ULL);
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

// FDE #02340 | PC: 0x23cbb8..0x23cc04 (76 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x23cbb8: D503233F  paciasp  
//   0x23cbbc: D10083FF  sub      sp, sp, #0x20
//   0x23cbc0: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x23cbc4: 910043FD  add      x29, sp, #0x10
//   0x23cbc8: F9400008  ldr      x8, [x0]
//   0x23cbcc: F9000001  str      x1, [x0]
uint64_t fde_func_02340_0x23cbb8(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0023CBB8ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10083FFULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400008ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000001ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB4000108ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9401800ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #02350 | PC: 0x23ddc0..0x23de40 (128 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x23ddc0: D503233F  paciasp  
//   0x23ddc4: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x23ddc8: F9000BF3  str      x19, [sp, #0x10]
//   0x23ddcc: 910003FD  mov      x29, sp
//   0x23ddd0: 9402A67A  bl       #0x2e77b8
//   0x23ddd4: AA0003F3  mov      x19, x0
uint64_t fde_func_02350_0x23ddc0(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0023DDC0ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF3ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9402A67AULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x97FF16D6ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF0001D08ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #02359 | PC: 0x23e388..0x23e488 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x23e388: D503233F  paciasp  
//   0x23e38c: D101C3FF  sub      sp, sp, #0x70
//   0x23e390: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x23e394: A9026FFC  stp      x28, x27, [sp, #0x20]
//   0x23e398: A90367FA  stp      x26, x25, [sp, #0x30]
//   0x23e39c: A9045FF8  stp      x24, x23, [sp, #0x40]
uint64_t fde_func_02359_0x23e388(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0023E388ULL);
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

// FDE #02369 | PC: 0x23f134..0x23f234 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x23f134: D503233F  paciasp  
//   0x23f138: D101C3FF  sub      sp, sp, #0x70
//   0x23f13c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x23f140: A9026FFC  stp      x28, x27, [sp, #0x20]
//   0x23f144: A90367FA  stp      x26, x25, [sp, #0x30]
//   0x23f148: A9045FF8  stp      x24, x23, [sp, #0x40]
uint64_t fde_func_02369_0x23f134(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0023F134ULL);
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

// FDE #02379 | PC: 0x23f974..0x23fa10 (156 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x23f974: D503233F  paciasp  
//   0x23f978: A9BD7BFD  stp      x29, x30, [sp, #-0x30]!
//   0x23f97c: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x23f980: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x23f984: 910003FD  mov      x29, sp
//   0x23f988: A942D416  ldp      x22, x21, [x0, #0x28]
uint64_t fde_func_02379_0x23f974(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0023F974ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BD7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90157F6ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9024FF4ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA942D416ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9401C13ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9001C1FULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #02388 | PC: 0x23fd2c..0x23fd58 (44 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x23fd2c: D503233F  paciasp  
//   0x23fd30: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x23fd34: 910003FD  mov      x29, sp
//   0x23fd38: 52800200  mov      w0, #0x10
//   0x23fd3c: 9402720E  bl       #0x2dc574
//   0x23fd40: F0001AA8  adrp     x8, #0x596000
uint64_t fde_func_02388_0x23fd2c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0023FD2CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BF7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x52800200ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9402720EULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF0001AA8ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91388108ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000008ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #02398 | PC: 0x2401fc..0x2402fc (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x2401fc: D503233F  paciasp  
//   0x240200: A9BD7BFD  stp      x29, x30, [sp, #-0x30]!
//   0x240204: F9000BF5  str      x21, [sp, #0x10]
//   0x240208: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x24020c: 910003FD  mov      x29, sp
//   0x240210: 5280AA00  mov      w0, #0x550
uint64_t fde_func_02398_0x2401fc(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x002401FCULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BD7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF5ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9024FF4ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x5280AA00ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x940270D8ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #02407 | PC: 0x240544..0x240644 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x240544: D503233F  paciasp  
//   0x240548: D10683FF  sub      sp, sp, #0x1a0
//   0x24054c: A9147BFD  stp      x29, x30, [sp, #0x140]
//   0x240550: F900ABFC  str      x28, [sp, #0x150]
//   0x240554: A91667FA  stp      x26, x25, [sp, #0x160]
//   0x240558: A9175FF8  stp      x24, x23, [sp, #0x170]
uint64_t fde_func_02407_0x240544(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00240544ULL);
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

// FDE #02417 | PC: 0x240fc8..0x240ff4 (44 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x240fc8: D503233F  paciasp  
//   0x240fcc: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x240fd0: F9000BF3  str      x19, [sp, #0x10]
//   0x240fd4: 910003FD  mov      x29, sp
//   0x240fd8: AA0003F3  mov      x19, x0
//   0x240fdc: 97FFFFE8  bl       #0x240f7c
uint64_t fde_func_02417_0x240fc8(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00240FC8ULL);
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

// FDE #02426 | PC: 0x24160c..0x24165c (80 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x24160c: D503233F  paciasp  
//   0x241610: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x241614: F9000BF3  str      x19, [sp, #0x10]
//   0x241618: 910003FD  mov      x29, sp
//   0x24161c: F9400013  ldr      x19, [x0]
//   0x241620: F9000001  str      x1, [x0]
uint64_t fde_func_02426_0x24160c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0024160CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF3ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400013ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000001ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB4000153ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91004260ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #02436 | PC: 0x241c64..0x241ca8 (68 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x241c64: D503245F  bti      c
//   0x241c68: B40001E0  cbz      x0, #0x241ca4
//   0x241c6c: D503233F  paciasp  
//   0x241c70: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x241c74: F9000BF3  str      x19, [sp, #0x10]
//   0x241c78: 910003FD  mov      x29, sp
uint64_t fde_func_02436_0x241c64(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00241C64ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB40001E0ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE7BFDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF3ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9402400ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #02445 | PC: 0x242800..0x242858 (88 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x242800: D503233F  paciasp  
//   0x242804: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x242808: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x24280c: 910003FD  mov      x29, sp
//   0x242810: 91033013  add      x19, x0, #0xcc
//   0x242814: AA0003F4  mov      x20, x0
uint64_t fde_func_02445_0x242800(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00242800ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9014FF4ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91033013ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F4ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA1303E0ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x97FE9ECFULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #02455 | PC: 0x243254..0x2432d8 (132 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x243254: D503233F  paciasp  
//   0x243258: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x24325c: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x243260: 910003FD  mov      x29, sp
//   0x243264: 2A1F03E1  mov      w1, wzr
//   0x243268: AA0003F3  mov      x19, x0
uint64_t fde_func_02455_0x243254(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00243254ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9014FF4ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x2A1F03E1ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9400001BULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x360000A0ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #02464 | PC: 0x2437ac..0x2437d8 (44 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x2437ac: D503233F  paciasp  
//   0x2437b0: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x2437b4: F9000BF3  str      x19, [sp, #0x10]
//   0x2437b8: 910003FD  mov      x29, sp
//   0x2437bc: AA0003F3  mov      x19, x0
//   0x2437c0: 97FFFFF6  bl       #0x243798
uint64_t fde_func_02464_0x2437ac(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x002437ACULL);
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

// FDE #02474 | PC: 0x2442d4..0x24430c (56 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x2442d4: D503233F  paciasp  
//   0x2442d8: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x2442dc: F9000BF3  str      x19, [sp, #0x10]
//   0x2442e0: 910003FD  mov      x29, sp
//   0x2442e4: 39400008  ldrb     w8, [x0]
//   0x2442e8: 340000A8  cbz      w8, #0x2442fc
uint64_t fde_func_02474_0x2442d4(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x002442D4ULL);
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

// FDE #02483 | PC: 0x244c8c..0x244d04 (120 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x244c8c: D503233F  paciasp  
//   0x244c90: D10083FF  sub      sp, sp, #0x20
//   0x244c94: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x244c98: 910043FD  add      x29, sp, #0x10
//   0x244c9c: A942A00A  ldp      x10, x8, [x0, #0x28]
//   0x244ca0: 91012003  add      x3, x0, #0x48
uint64_t fde_func_02483_0x244c8c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00244C8CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10083FFULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA942A00AULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91012003ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91014004ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9401009ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #02493 | PC: 0x245454..0x245510 (188 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x245454: D503233F  paciasp  
//   0x245458: D10103FF  sub      sp, sp, #0x40
//   0x24545c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x245460: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x245464: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x245468: 910043FD  add      x29, sp, #0x10
uint64_t fde_func_02493_0x245454(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00245454ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10103FFULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90257F6ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9034FF4ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x52800C00ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x94025C41ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #02502 | PC: 0x2455d0..0x2455dc (12 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x2455d0: D503245F  bti      c
//   0x2455d4: F9401410  ldr      x16, [x0, #0x28]
//   0x2455d8: D61F0200  br       x16
uint64_t fde_func_02502_0x2455d0(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x002455D0ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9401410ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD61F0200ULL ^ (2ULL << 32);
    return state ^ (state >> 29);
}

// FDE #02512 | PC: 0x2456f0..0x245700 (16 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x2456f0: D503245F  bti      c
//   0x2456f4: F9400008  ldr      x8, [x0]
//   0x2456f8: F9403110  ldr      x16, [x8, #0x60]
//   0x2456fc: D61F0200  br       x16
uint64_t fde_func_02512_0x2456f0(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x002456F0ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400008ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9403110ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD61F0200ULL ^ (3ULL << 32);
    return state ^ (state >> 29);
}

// FDE #02521 | PC: 0x245780..0x245790 (16 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x245780: D503245F  bti      c
//   0x245784: F9400008  ldr      x8, [x0]
//   0x245788: F9405510  ldr      x16, [x8, #0xa8]
//   0x24578c: D61F0200  br       x16
uint64_t fde_func_02521_0x245780(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00245780ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400008ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9405510ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD61F0200ULL ^ (3ULL << 32);
    return state ^ (state >> 29);
}

// FDE #02531 | PC: 0x245820..0x245830 (16 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x245820: D503245F  bti      c
//   0x245824: F9400008  ldr      x8, [x0]
//   0x245828: F9407D10  ldr      x16, [x8, #0xf8]
//   0x24582c: D61F0200  br       x16
uint64_t fde_func_02531_0x245820(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00245820ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400008ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9407D10ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD61F0200ULL ^ (3ULL << 32);
    return state ^ (state >> 29);
}

// FDE #02540 | PC: 0x2458b0..0x2458c0 (16 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x2458b0: D503245F  bti      c
//   0x2458b4: F9400008  ldr      x8, [x0]
//   0x2458b8: F940A110  ldr      x16, [x8, #0x140]
//   0x2458bc: D61F0200  br       x16
uint64_t fde_func_02540_0x2458b0(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x002458B0ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400008ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF940A110ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD61F0200ULL ^ (3ULL << 32);
    return state ^ (state >> 29);
}

// FDE #02550 | PC: 0x245950..0x245960 (16 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x245950: D503245F  bti      c
//   0x245954: F9400008  ldr      x8, [x0]
//   0x245958: F940C910  ldr      x16, [x8, #0x190]
//   0x24595c: D61F0200  br       x16
uint64_t fde_func_02550_0x245950(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00245950ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400008ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF940C910ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD61F0200ULL ^ (3ULL << 32);
    return state ^ (state >> 29);
}

// FDE #02559 | PC: 0x245b64..0x245b70 (12 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x245b64: D503245F  bti      c
//   0x245b68: F9402C10  ldr      x16, [x0, #0x58]
//   0x245b6c: D61F0200  br       x16
uint64_t fde_func_02559_0x245b64(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00245B64ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9402C10ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD61F0200ULL ^ (2ULL << 32);
    return state ^ (state >> 29);
}

// FDE #02569 | PC: 0x245bdc..0x245be8 (12 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x245bdc: D503245F  bti      c
//   0x245be0: F9405410  ldr      x16, [x0, #0xa8]
//   0x245be4: D61F0200  br       x16
uint64_t fde_func_02569_0x245bdc(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00245BDCULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9405410ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD61F0200ULL ^ (2ULL << 32);
    return state ^ (state >> 29);
}

// FDE #02578 | PC: 0x245c48..0x245c54 (12 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x245c48: D503245F  bti      c
//   0x245c4c: F9407810  ldr      x16, [x0, #0xf0]
//   0x245c50: D61F0200  br       x16
uint64_t fde_func_02578_0x245c48(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00245C48ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9407810ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD61F0200ULL ^ (2ULL << 32);
    return state ^ (state >> 29);
}

// FDE #02588 | PC: 0x245cc0..0x245ccc (12 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x245cc0: D503245F  bti      c
//   0x245cc4: F940A010  ldr      x16, [x0, #0x140]
//   0x245cc8: D61F0200  br       x16
uint64_t fde_func_02588_0x245cc0(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00245CC0ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF940A010ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD61F0200ULL ^ (2ULL << 32);
    return state ^ (state >> 29);
}

// FDE #02597 | PC: 0x245d2c..0x245d38 (12 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x245d2c: D503245F  bti      c
//   0x245d30: F940C410  ldr      x16, [x0, #0x188]
//   0x245d34: D61F0200  br       x16
uint64_t fde_func_02597_0x245d2c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00245D2CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF940C410ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD61F0200ULL ^ (2ULL << 32);
    return state ^ (state >> 29);
}

// FDE #02607 | PC: 0x245f70..0x245fac (60 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x245f70: D503233F  paciasp  
//   0x245f74: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x245f78: F9000BF3  str      x19, [sp, #0x10]
//   0x245f7c: 910003FD  mov      x29, sp
//   0x245f80: AA0003F3  mov      x19, x0
//   0x245f84: 52800300  mov      w0, #0x18
uint64_t fde_func_02607_0x245f70(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00245F70ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF3ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x52800300ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9402597BULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD0001A88ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #02616 | PC: 0x2461a4..0x2461d8 (52 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x2461a4: D503233F  paciasp  
//   0x2461a8: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x2461ac: F9000BF3  str      x19, [sp, #0x10]
//   0x2461b0: 910003FD  mov      x29, sp
//   0x2461b4: 52800600  mov      w0, #0x30
//   0x2461b8: 940258EF  bl       #0x2dc574
uint64_t fde_func_02616_0x2461a4(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x002461A4ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF3ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x52800600ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x940258EFULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x97FFFFEAULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #02626 | PC: 0x246284..0x246290 (12 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x246284: D503245F  bti      c
//   0x246288: 39409000  ldrb     w0, [x0, #0x24]
//   0x24628c: D65F03C0  ret      
uint64_t fde_func_02626_0x246284(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00246284ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x39409000ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD65F03C0ULL ^ (2ULL << 32);
    return state ^ (state >> 29);
}

// FDE #02635 | PC: 0x246400..0x24640c (12 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x246400: D503245F  bti      c
//   0x246404: B9004C01  str      w1, [x0, #0x4c]
//   0x246408: D65F03C0  ret      
uint64_t fde_func_02635_0x246400(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00246400ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB9004C01ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD65F03C0ULL ^ (2ULL << 32);
    return state ^ (state >> 29);
}

// FDE #02645 | PC: 0x2464b8..0x2464c8 (16 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x2464b8: D503245F  bti      c
//   0x2464bc: F9401808  ldr      x8, [x0, #0x30]
//   0x2464c0: F9001C08  str      x8, [x0, #0x38]
//   0x2464c4: D65F03C0  ret      
uint64_t fde_func_02645_0x2464b8(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x002464B8ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9401808ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9001C08ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD65F03C0ULL ^ (3ULL << 32);
    return state ^ (state >> 29);
}

// FDE #02654 | PC: 0x246550..0x24655c (12 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x246550: D503245F  bti      c
//   0x246554: FD400400  ldr      d0, [x0, #8]
//   0x246558: D65F03C0  ret      
uint64_t fde_func_02654_0x246550(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00246550ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xFD400400ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD65F03C0ULL ^ (2ULL << 32);
    return state ^ (state >> 29);
}

// FDE #02664 | PC: 0x2466b0..0x2466bc (12 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x2466b0: D503245F  bti      c
//   0x2466b4: 91006000  add      x0, x0, #0x18
//   0x2466b8: 140D0226  b        #0x586f50
uint64_t fde_func_02664_0x2466b0(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x002466B0ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91006000ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x140D0226ULL ^ (2ULL << 32);
    return state ^ (state >> 29);
}

// FDE #02673 | PC: 0x24674c..0x246778 (44 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x24674c: D503233F  paciasp  
//   0x246750: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x246754: 910003FD  mov      x29, sp
//   0x246758: 52800400  mov      w0, #0x20
//   0x24675c: 94025786  bl       #0x2dc574
//   0x246760: A900FC1F  stp      xzr, xzr, [x0, #8]
uint64_t fde_func_02673_0x24674c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0024674CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BF7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x52800400ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x94025786ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA900FC1FULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF900001FULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x7900301FULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #02683 | PC: 0x24681c..0x24686c (80 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x24681c: D503233F  paciasp  
//   0x246820: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x246824: F9000BF3  str      x19, [sp, #0x10]
//   0x246828: 910003FD  mov      x29, sp
//   0x24682c: 52800800  mov      w0, #0x40
//   0x246830: 94025751  bl       #0x2dc574
uint64_t fde_func_02683_0x24681c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0024681CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF3ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x52800800ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x94025751ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x12800008ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #02693 | PC: 0x246974..0x246990 (28 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x246974: D503245F  bti      c
//   0x246978: 3940A008  ldrb     w8, [x0, #0x28]
//   0x24697c: 37000068  tbnz     w8, #0, #0x246988
//   0x246980: 9100A400  add      x0, x0, #0x29
//   0x246984: D65F03C0  ret      
//   0x246988: F9401C00  ldr      x0, [x0, #0x38]
uint64_t fde_func_02693_0x246974(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00246974ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x3940A008ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x37000068ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9100A400ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD65F03C0ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9401C00ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD65F03C0ULL ^ (6ULL << 32);
    return state ^ (state >> 29);
}

// FDE #02702 | PC: 0x246b68..0x246bac (68 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x246b68: D503233F  paciasp  
//   0x246b6c: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x246b70: F9000BF3  str      x19, [sp, #0x10]
//   0x246b74: 910003FD  mov      x29, sp
//   0x246b78: F9400008  ldr      x8, [x0]
//   0x246b7c: B4000108  cbz      x8, #0x246b9c
uint64_t fde_func_02702_0x246b68(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00246B68ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF3ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400008ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB4000108ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9400000AULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #02712 | PC: 0x246e40..0x246e54 (20 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x246e40: D503245F  bti      c
//   0x246e44: B9402008  ldr      w8, [x0, #0x20]
//   0x246e48: B9401809  ldr      w9, [x0, #0x18]
//   0x246e4c: 4B090100  sub      w0, w8, w9
//   0x246e50: D65F03C0  ret      
uint64_t fde_func_02712_0x246e40(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00246E40ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB9402008ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB9401809ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x4B090100ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD65F03C0ULL ^ (4ULL << 32);
    return state ^ (state >> 29);
}

// FDE #02721 | PC: 0x246ed8..0x246f0c (52 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x246ed8: D503233F  paciasp  
//   0x246edc: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x246ee0: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x246ee4: 910003FD  mov      x29, sp
//   0x246ee8: AA0103F3  mov      x19, x1
//   0x246eec: AA0003F4  mov      x20, x0
uint64_t fde_func_02721_0x246ed8(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00246ED8ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9014FF4ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0103F3ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F4ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x940CFFEEULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400E68ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #02731 | PC: 0x247060..0x247098 (56 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x247060: D503245F  bti      c
//   0x247064: B4000180  cbz      x0, #0x247094
//   0x247068: D503233F  paciasp  
//   0x24706c: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x247070: F9000BF3  str      x19, [sp, #0x10]
//   0x247074: 910003FD  mov      x29, sp
uint64_t fde_func_02731_0x247060(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00247060ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB4000180ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE7BFDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF3ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x97FFFFDCULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #02740 | PC: 0x24715c..0x24725c (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x24715c: D503233F  paciasp  
//   0x247160: A9BC7BFD  stp      x29, x30, [sp, #-0x40]!
//   0x247164: F9000BF7  str      x23, [sp, #0x10]
//   0x247168: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x24716c: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x247170: 910003FD  mov      x29, sp
uint64_t fde_func_02740_0x24715c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0024715CULL);
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

// FDE #02750 | PC: 0x2475e8..0x2475f4 (12 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x2475e8: D503245F  bti      c
//   0x2475ec: 91024000  add      x0, x0, #0x90
//   0x2475f0: 140CFE58  b        #0x586f50
uint64_t fde_func_02750_0x2475e8(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x002475E8ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91024000ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x140CFE58ULL ^ (2ULL << 32);
    return state ^ (state >> 29);
}

// FDE #02759 | PC: 0x247654..0x247660 (12 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x247654: D503245F  bti      c
//   0x247658: 9105A000  add      x0, x0, #0x168
//   0x24765c: 140CFE3D  b        #0x586f50
uint64_t fde_func_02759_0x247654(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00247654ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9105A000ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x140CFE3DULL ^ (2ULL << 32);
    return state ^ (state >> 29);
}

// FDE #02769 | PC: 0x247914..0x247930 (28 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x247914: D503245F  bti      c
//   0x247918: 39412008  ldrb     w8, [x0, #0x48]
//   0x24791c: 37000068  tbnz     w8, #0, #0x247928
//   0x247920: 91012400  add      x0, x0, #0x49
//   0x247924: D65F03C0  ret      
//   0x247928: F9402C00  ldr      x0, [x0, #0x58]
uint64_t fde_func_02769_0x247914(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00247914ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x39412008ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x37000068ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91012400ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD65F03C0ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9402C00ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD65F03C0ULL ^ (6ULL << 32);
    return state ^ (state >> 29);
}

// FDE #02778 | PC: 0x247a10..0x247a2c (28 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x247a10: D503245F  bti      c
//   0x247a14: 39448008  ldrb     w8, [x0, #0x120]
//   0x247a18: 37000068  tbnz     w8, #0, #0x247a24
//   0x247a1c: 91048400  add      x0, x0, #0x121
//   0x247a20: D65F03C0  ret      
//   0x247a24: F9409800  ldr      x0, [x0, #0x130]
uint64_t fde_func_02778_0x247a10(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00247A10ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x39448008ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x37000068ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91048400ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD65F03C0ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9409800ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD65F03C0ULL ^ (6ULL << 32);
    return state ^ (state >> 29);
}

// FDE #02788 | PC: 0x247b08..0x247b1c (20 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x247b08: D503245F  bti      c
//   0x247b0c: F940E408  ldr      x8, [x0, #0x1c8]
//   0x247b10: 52800609  mov      w9, #0x30
//   0x247b14: 9BA92020  umaddl   x0, w1, w9, x8
//   0x247b18: D65F03C0  ret      
uint64_t fde_func_02788_0x247b08(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00247B08ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF940E408ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x52800609ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9BA92020ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD65F03C0ULL ^ (4ULL << 32);
    return state ^ (state >> 29);
}

// FDE #02797 | PC: 0x247c58..0x247ca4 (76 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x247c58: D503233F  paciasp  
//   0x247c5c: A9BD7BFD  stp      x29, x30, [sp, #-0x30]!
//   0x247c60: F9000BF5  str      x21, [sp, #0x10]
//   0x247c64: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x247c68: 910003FD  mov      x29, sp
//   0x247c6c: A9405015  ldp      x21, x20, [x0]
uint64_t fde_func_02797_0x247c58(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00247C58ULL);
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

// FDE #02807 | PC: 0x247ea8..0x247eb4 (12 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x247ea8: D503245F  bti      c
//   0x247eac: F9003801  str      x1, [x0, #0x70]
//   0x247eb0: D65F03C0  ret      
uint64_t fde_func_02807_0x247ea8(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00247EA8ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9003801ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD65F03C0ULL ^ (2ULL << 32);
    return state ^ (state >> 29);
}

// FDE #02816 | PC: 0x248204..0x248304 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x248204: D503233F  paciasp  
//   0x248208: A9BC7BFD  stp      x29, x30, [sp, #-0x40]!
//   0x24820c: F9000BF7  str      x23, [sp, #0x10]
//   0x248210: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x248214: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x248218: 910003FD  mov      x29, sp
uint64_t fde_func_02816_0x248204(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00248204ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BC7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF7ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90257F6ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9034FF4ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA951A014ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #02826 | PC: 0x2484c8..0x2484d4 (12 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x2484c8: D503245F  bti      c
//   0x2484cc: 3941A000  ldrb     w0, [x0, #0x68]
//   0x2484d0: D65F03C0  ret      
uint64_t fde_func_02826_0x2484c8(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x002484C8ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x3941A000ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD65F03C0ULL ^ (2ULL << 32);
    return state ^ (state >> 29);
}

// FDE #02835 | PC: 0x24854c..0x248560 (20 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x24854c: D503245F  bti      c
//   0x248550: F9404808  ldr      x8, [x0, #0x90]
//   0x248554: 2A0103E9  mov      w9, w1
//   0x248558: 8B091900  add      x0, x8, x9, lsl #6
//   0x24855c: D65F03C0  ret      
uint64_t fde_func_02835_0x24854c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0024854CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9404808ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x2A0103E9ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x8B091900ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD65F03C0ULL ^ (4ULL << 32);
    return state ^ (state >> 29);
}

// FDE #02845 | PC: 0x2485f0..0x248608 (24 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x2485f0: D503245F  bti      c
//   0x2485f4: A951240A  ldp      x10, x9, [x0, #0x110]
//   0x2485f8: 52800E08  mov      w8, #0x70
//   0x2485fc: CB0A0129  sub      x9, x9, x10
//   0x248600: 9AC80D20  sdiv     x0, x9, x8
//   0x248604: D65F03C0  ret      
uint64_t fde_func_02845_0x2485f0(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x002485F0ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA951240AULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x52800E08ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xCB0A0129ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9AC80D20ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD65F03C0ULL ^ (5ULL << 32);
    return state ^ (state >> 29);
}

// FDE #02854 | PC: 0x2486a0..0x2486cc (44 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x2486a0: D503233F  paciasp  
//   0x2486a4: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x2486a8: F9000BF3  str      x19, [sp, #0x10]
//   0x2486ac: 910003FD  mov      x29, sp
//   0x2486b0: AA0003F3  mov      x19, x0
//   0x2486b4: 97FDFFC5  bl       #0x1c85c8
uint64_t fde_func_02854_0x2486a0(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x002486A0ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF3ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x97FDFFC5ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91006260ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400BF3ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #02864 | PC: 0x248848..0x248860 (24 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x248848: D503245F  bti      c
//   0x24884c: A945240A  ldp      x10, x9, [x0, #0x50]
//   0x248850: 52800608  mov      w8, #0x30
//   0x248854: CB0A0129  sub      x9, x9, x10
//   0x248858: 9AC80D20  sdiv     x0, x9, x8
//   0x24885c: D65F03C0  ret      
uint64_t fde_func_02864_0x248848(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00248848ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA945240AULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x52800608ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xCB0A0129ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9AC80D20ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD65F03C0ULL ^ (5ULL << 32);
    return state ^ (state >> 29);
}

// FDE #02873 | PC: 0x2489ac..0x248a18 (108 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x2489ac: D503233F  paciasp  
//   0x2489b0: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x2489b4: F9000BF3  str      x19, [sp, #0x10]
//   0x2489b8: 910003FD  mov      x29, sp
//   0x2489bc: 52801900  mov      w0, #0xc8
//   0x2489c0: 94024EED  bl       #0x2dc574
uint64_t fde_func_02873_0x2489ac(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x002489ACULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF3ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x52801900ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x94024EEDULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x97FDFF00ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #02883 | PC: 0x248ba4..0x248bb0 (12 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x248ba4: D503245F  bti      c
//   0x248ba8: B9008801  str      w1, [x0, #0x88]
//   0x248bac: D65F03C0  ret      
uint64_t fde_func_02883_0x248ba4(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00248BA4ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB9008801ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD65F03C0ULL ^ (2ULL << 32);
    return state ^ (state >> 29);
}

// FDE #02892 | PC: 0x248c7c..0x248c8c (16 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x248c7c: D503245F  bti      c
//   0x248c80: F9402808  ldr      x8, [x0, #0x50]
//   0x248c84: F8615900  ldr      x0, [x8, w1, uxtw #3]
//   0x248c88: D65F03C0  ret      
uint64_t fde_func_02892_0x248c7c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00248C7CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9402808ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF8615900ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD65F03C0ULL ^ (3ULL << 32);
    return state ^ (state >> 29);
}

// FDE #02902 | PC: 0x248d20..0x248d2c (12 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x248d20: D503245F  bti      c
//   0x248d24: F9000001  str      x1, [x0]
//   0x248d28: D65F03C0  ret      
uint64_t fde_func_02902_0x248d20(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00248D20ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000001ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD65F03C0ULL ^ (2ULL << 32);
    return state ^ (state >> 29);
}

// FDE #02911 | PC: 0x2490e8..0x249110 (40 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x2490e8: D503245F  bti      c
//   0x2490ec: 39408008  ldrb     w8, [x0, #0x20]
//   0x2490f0: 34000048  cbz      w8, #0x2490f8
//   0x2490f4: 3900801F  strb     wzr, [x0, #0x20]
//   0x2490f8: B40000A1  cbz      x1, #0x24910c
//   0x2490fc: F9400028  ldr      x8, [x1]
uint64_t fde_func_02911_0x2490e8(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x002490E8ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x39408008ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x34000048ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x3900801FULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB40000A1ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400028ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x52800029ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9001408ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #02921 | PC: 0x249278..0x2492a0 (40 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x249278: D503245F  bti      c
//   0x24927c: 39430008  ldrb     w8, [x0, #0xc0]
//   0x249280: 34000048  cbz      w8, #0x249288
//   0x249284: 3903001F  strb     wzr, [x0, #0xc0]
//   0x249288: B40000A1  cbz      x1, #0x24929c
//   0x24928c: F9400028  ldr      x8, [x1]
uint64_t fde_func_02921_0x249278(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00249278ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x39430008ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x34000048ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x3903001FULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB40000A1ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400028ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x52800029ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9006408ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #02930 | PC: 0x249324..0x24933c (24 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x249324: D503245F  bti      c
//   0x249328: 38440C08  ldrb     w8, [x0, #0x40]!
//   0x24932c: 34000048  cbz      w8, #0x249334
//   0x249330: 17FE528B  b        #0x1ddd5c
//   0x249334: AA1F03E0  mov      x0, xzr
//   0x249338: D65F03C0  ret      
uint64_t fde_func_02930_0x249324(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00249324ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x38440C08ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x34000048ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x17FE528BULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA1F03E0ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD65F03C0ULL ^ (5ULL << 32);
    return state ^ (state >> 29);
}

// FDE #02940 | PC: 0x249408..0x249414 (12 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x249408: D503245F  bti      c
//   0x24940c: F9407000  ldr      x0, [x0, #0xe0]
//   0x249410: D65F03C0  ret      
uint64_t fde_func_02940_0x249408(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00249408ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9407000ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD65F03C0ULL ^ (2ULL << 32);
    return state ^ (state >> 29);
}

// FDE #02949 | PC: 0x249570..0x2495a0 (48 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x249570: D503233F  paciasp  
//   0x249574: D10083FF  sub      sp, sp, #0x20
//   0x249578: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x24957c: 910043FD  add      x29, sp, #0x10
//   0x249580: 91044000  add      x0, x0, #0x110
//   0x249584: F90007E1  str      x1, [sp, #8]
uint64_t fde_func_02949_0x249570(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00249570ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10083FFULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91044000ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF90007E1ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910023E1ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x97FFFD46ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #02959 | PC: 0x24967c..0x249688 (12 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x24967c: D503245F  bti      c
//   0x249680: 79000401  strh     w1, [x0, #2]
//   0x249684: D65F03C0  ret      
uint64_t fde_func_02959_0x24967c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0024967CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x79000401ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD65F03C0ULL ^ (2ULL << 32);
    return state ^ (state >> 29);
}

// FDE #02968 | PC: 0x2496e8..0x2496f4 (12 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x2496e8: D503245F  bti      c
//   0x2496ec: B9004001  str      w1, [x0, #0x40]
//   0x2496f0: D65F03C0  ret      
uint64_t fde_func_02968_0x2496e8(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x002496E8ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB9004001ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD65F03C0ULL ^ (2ULL << 32);
    return state ^ (state >> 29);
}

// FDE #02978 | PC: 0x249760..0x24976c (12 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x249760: D503245F  bti      c
//   0x249764: 79400C00  ldrh     w0, [x0, #6]
//   0x249768: D65F03C0  ret      
uint64_t fde_func_02978_0x249760(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00249760ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x79400C00ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD65F03C0ULL ^ (2ULL << 32);
    return state ^ (state >> 29);
}

// FDE #02988 | PC: 0x2497d8..0x2497e4 (12 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x2497d8: D503245F  bti      c
//   0x2497dc: B9406400  ldr      w0, [x0, #0x64]
//   0x2497e0: D65F03C0  ret      
uint64_t fde_func_02988_0x2497d8(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x002497D8ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB9406400ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD65F03C0ULL ^ (2ULL << 32);
    return state ^ (state >> 29);
}

// FDE #02997 | PC: 0x249928..0x249960 (56 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x249928: D503245F  bti      c
//   0x24992c: B4000180  cbz      x0, #0x24995c
//   0x249930: D503233F  paciasp  
//   0x249934: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x249938: F9000BF3  str      x19, [sp, #0x10]
//   0x24993c: 910003FD  mov      x29, sp
uint64_t fde_func_02997_0x249928(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00249928ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB4000180ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE7BFDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF3ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x97FFFFE0ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #03007 | PC: 0x249a70..0x249aa4 (52 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x249a70: D503233F  paciasp  
//   0x249a74: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x249a78: F9000BF3  str      x19, [sp, #0x10]
//   0x249a7c: 910003FD  mov      x29, sp
//   0x249a80: 52800D00  mov      w0, #0x68
//   0x249a84: 94024ABC  bl       #0x2dc574
uint64_t fde_func_03007_0x249a70(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00249A70ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF3ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x52800D00ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x94024ABCULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x97FFFFD8ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #03016 | PC: 0x249f04..0x249f6c (104 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x249f04: D503233F  paciasp  
//   0x249f08: A9BD7BFD  stp      x29, x30, [sp, #-0x30]!
//   0x249f0c: F9000BF5  str      x21, [sp, #0x10]
//   0x249f10: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x249f14: 910003FD  mov      x29, sp
//   0x249f18: AA0003F4  mov      x20, x0
uint64_t fde_func_03016_0x249f04(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00249F04ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BD7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF5ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9024FF4ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F4ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x52800300ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0103F3ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #03026 | PC: 0x24a4d4..0x24a558 (132 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x24a4d4: D503233F  paciasp  
//   0x24a4d8: A9BC7BFD  stp      x29, x30, [sp, #-0x40]!
//   0x24a4dc: F9000BF7  str      x23, [sp, #0x10]
//   0x24a4e0: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x24a4e4: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x24a4e8: 910003FD  mov      x29, sp
uint64_t fde_func_03026_0x24a4d4(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0024A4D4ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BC7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF7ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90257F6ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9034FF4ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9100A013ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F7ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #03035 | PC: 0x24a87c..0x24a888 (12 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x24a87c: D503245F  bti      c
//   0x24a880: D1004000  sub      x0, x0, #0x10
//   0x24a884: 17FFFF70  b        #0x24a644
uint64_t fde_func_03035_0x24a87c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0024A87CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD1004000ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x17FFFF70ULL ^ (2ULL << 32);
    return state ^ (state >> 29);
}

// FDE #03045 | PC: 0x24acf8..0x24adf8 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x24acf8: D503233F  paciasp  
//   0x24acfc: D101C3FF  sub      sp, sp, #0x70
//   0x24ad00: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x24ad04: F9001BF9  str      x25, [sp, #0x30]
//   0x24ad08: A9045FF8  stp      x24, x23, [sp, #0x40]
//   0x24ad0c: A90557F6  stp      x22, x21, [sp, #0x50]
uint64_t fde_func_03045_0x24acf8(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0024ACF8ULL);
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

// FDE #03054 | PC: 0x24b3c0..0x24b410 (80 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x24b3c0: D503233F  paciasp  
//   0x24b3c4: A9BD7BFD  stp      x29, x30, [sp, #-0x30]!
//   0x24b3c8: F9000BF5  str      x21, [sp, #0x10]
//   0x24b3cc: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x24b3d0: 910003FD  mov      x29, sp
//   0x24b3d4: 9100A013  add      x19, x0, #0x28
uint64_t fde_func_03054_0x24b3c0(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0024B3C0ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BD7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF5ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9024FF4ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9100A013ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F4ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA1303E0ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #03064 | PC: 0x24b5d4..0x24b698 (196 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x24b5d4: D503233F  paciasp  
//   0x24b5d8: D101C3FF  sub      sp, sp, #0x70
//   0x24b5dc: A9037BFD  stp      x29, x30, [sp, #0x30]
//   0x24b5e0: A9045FF8  stp      x24, x23, [sp, #0x40]
//   0x24b5e4: A90557F6  stp      x22, x21, [sp, #0x50]
//   0x24b5e8: A9064FF4  stp      x20, x19, [sp, #0x60]
uint64_t fde_func_03064_0x24b5d4(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0024B5D4ULL);
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

// FDE #03073 | PC: 0x24b8a0..0x24b8bc (28 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x24b8a0: D503245F  bti      c
//   0x24b8a4: 39404008  ldrb     w8, [x0, #0x10]
//   0x24b8a8: 37000068  tbnz     w8, #0, #0x24b8b4
//   0x24b8ac: D341FD00  lsr      x0, x8, #1
//   0x24b8b0: D65F03C0  ret      
//   0x24b8b4: F9400C00  ldr      x0, [x0, #0x18]
uint64_t fde_func_03073_0x24b8a0(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0024B8A0ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x39404008ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x37000068ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD341FD00ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD65F03C0ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400C00ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD65F03C0ULL ^ (6ULL << 32);
    return state ^ (state >> 29);
}

// FDE #03083 | PC: 0x24bfe0..0x24c02c (76 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x24bfe0: D503233F  paciasp  
//   0x24bfe4: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x24bfe8: F9000BF3  str      x19, [sp, #0x10]
//   0x24bfec: 910003FD  mov      x29, sp
//   0x24bff0: AA0003F3  mov      x19, x0
//   0x24bff4: 91006000  add      x0, x0, #0x18
uint64_t fde_func_03083_0x24bfe0(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0024BFE0ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF3ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91006000ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9007E7FULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000A7FULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #03092 | PC: 0x24c124..0x24c130 (12 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x24c124: D503245F  bti      c
//   0x24c128: 9101A000  add      x0, x0, #0x68
//   0x24c12c: 17FE0FF9  b        #0x1d0110
uint64_t fde_func_03092_0x24c124(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0024C124ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9101A000ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x17FE0FF9ULL ^ (2ULL << 32);
    return state ^ (state >> 29);
}

// FDE #03102 | PC: 0x24c2fc..0x24c308 (12 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x24c2fc: D503245F  bti      c
//   0x24c300: B900D801  str      w1, [x0, #0xd8]
//   0x24c304: D65F03C0  ret      
uint64_t fde_func_03102_0x24c2fc(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0024C2FCULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB900D801ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD65F03C0ULL ^ (2ULL << 32);
    return state ^ (state >> 29);
}

// FDE #03111 | PC: 0x24c388..0x24c394 (12 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x24c388: D503245F  bti      c
//   0x24c38c: 39426000  ldrb     w0, [x0, #0x98]
//   0x24c390: D65F03C0  ret      
uint64_t fde_func_03111_0x24c388(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0024C388ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x39426000ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD65F03C0ULL ^ (2ULL << 32);
    return state ^ (state >> 29);
}

// FDE #03121 | PC: 0x24c450..0x24c45c (12 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x24c450: D503245F  bti      c
//   0x24c454: 39437400  ldrb     w0, [x0, #0xdd]
//   0x24c458: D65F03C0  ret      
uint64_t fde_func_03121_0x24c450(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0024C450ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x39437400ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD65F03C0ULL ^ (2ULL << 32);
    return state ^ (state >> 29);
}

// FDE #03130 | PC: 0x24c6ac..0x24c6d8 (44 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x24c6ac: D503245F  bti      c
//   0x24c6b0: A942A009  ldp      x9, x8, [x0, #0x28]
//   0x24c6b4: F9401010  ldr      x16, [x0, #0x20]
//   0x24c6b8: 8B890508  add      x8, x8, x9, asr #1
//   0x24c6bc: 36000069  tbz      w9, #0, #0x24c6c8
//   0x24c6c0: F9400109  ldr      x9, [x8]
uint64_t fde_func_03130_0x24c6ac(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0024C6ACULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA942A009ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9401010ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x8B890508ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x36000069ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400109ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF8706930ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91010002ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #03140 | PC: 0x24ca20..0x24ca2c (12 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x24ca20: D503245F  bti      c
//   0x24ca24: D1004000  sub      x0, x0, #0x10
//   0x24ca28: 17FFFF99  b        #0x24c88c
uint64_t fde_func_03140_0x24ca20(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0024CA20ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD1004000ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x17FFFF99ULL ^ (2ULL << 32);
    return state ^ (state >> 29);
}

// FDE #03149 | PC: 0x24cf58..0x24cfe4 (140 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x24cf58: D503233F  paciasp  
//   0x24cf5c: D100C3FF  sub      sp, sp, #0x30
//   0x24cf60: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x24cf64: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x24cf68: 910043FD  add      x29, sp, #0x10
//   0x24cf6c: AA0003F3  mov      x19, x0
uint64_t fde_func_03149_0x24cf58(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0024CF58ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD100C3FFULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9024FF4ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91006014ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x52800700ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #03159 | PC: 0x24d110..0x24d140 (48 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x24d110: D503245F  bti      c
//   0x24d114: A942A40A  ldp      x10, x9, [x0, #0x28]
//   0x24d118: AA0003E8  mov      x8, x0
//   0x24d11c: F9401010  ldr      x16, [x0, #0x20]
//   0x24d120: 8B8A0520  add      x0, x9, x10, asr #1
//   0x24d124: 3600006A  tbz      w10, #0, #0x24d130
uint64_t fde_func_03159_0x24d110(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0024D110ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA942A40AULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003E8ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9401010ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x8B8A0520ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x3600006AULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400009ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF8706930ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #03168 | PC: 0x24d440..0x24d494 (84 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x24d440: D503233F  paciasp  
//   0x24d444: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x24d448: F9000BF3  str      x19, [sp, #0x10]
//   0x24d44c: 910003FD  mov      x29, sp
//   0x24d450: 52800600  mov      w0, #0x30
//   0x24d454: 94023C48  bl       #0x2dc574
uint64_t fde_func_03168_0x24d440(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0024D440ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF3ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x52800600ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x94023C48ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x97FDEC5BULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #03178 | PC: 0x24d868..0x24d924 (188 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x24d868: D503233F  paciasp  
//   0x24d86c: D10103FF  sub      sp, sp, #0x40
//   0x24d870: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x24d874: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x24d878: 910083FD  add      x29, sp, #0x20
//   0x24d87c: D0001C88  adrp     x8, #0x5df000
uint64_t fde_func_03178_0x24d868(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0024D868ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10103FFULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9027BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9034FF4ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910083FDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD0001C88ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9438108ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #03187 | PC: 0x24ded4..0x24dfd4 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x24ded4: D503233F  paciasp  
//   0x24ded8: A9BD7BFD  stp      x29, x30, [sp, #-0x30]!
//   0x24dedc: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x24dee0: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x24dee4: 910003FD  mov      x29, sp
//   0x24dee8: A940A408  ldp      x8, x9, [x0, #8]
uint64_t fde_func_03187_0x24ded4(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0024DED4ULL);
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

// FDE #03197 | PC: 0x24e408..0x24e438 (48 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x24e408: D503233F  paciasp  
//   0x24e40c: D10083FF  sub      sp, sp, #0x20
//   0x24e410: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x24e414: 910043FD  add      x29, sp, #0x10
//   0x24e418: 9100E000  add      x0, x0, #0x38
//   0x24e41c: 381FC3A1  sturb    w1, [x29, #-4]
uint64_t fde_func_03197_0x24e408(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0024E408ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10083FFULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9100E000ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x381FC3A1ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10013A1ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x97FE1A4FULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #03206 | PC: 0x24e4e8..0x24e4f8 (16 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x24e4e8: D503245F  bti      c
//   0x24e4ec: F9402808  ldr      x8, [x0, #0x50]
//   0x24e4f0: 38614900  ldrb     w0, [x8, w1, uxtw]
//   0x24e4f4: D65F03C0  ret      
uint64_t fde_func_03206_0x24e4e8(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0024E4E8ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9402808ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x38614900ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD65F03C0ULL ^ (3ULL << 32);
    return state ^ (state >> 29);
}

// FDE #03216 | PC: 0x24eaf0..0x24eb2c (60 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x24eaf0: D503233F  paciasp  
//   0x24eaf4: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x24eaf8: F9000BF3  str      x19, [sp, #0x10]
//   0x24eafc: 910003FD  mov      x29, sp
//   0x24eb00: AA0003F3  mov      x19, x0
//   0x24eb04: 91002000  add      x0, x0, #8
uint64_t fde_func_03216_0x24eaf0(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0024EAF0ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF3ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91002000ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF900027FULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x97FDE6AFULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #03225 | PC: 0x24f23c..0x24f250 (20 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x24f23c: D503245F  bti      c
//   0x24f240: 9100A008  add      x8, x0, #0x28
//   0x24f244: F9401010  ldr      x16, [x0, #0x20]
//   0x24f248: AA0803E0  mov      x0, x8
//   0x24f24c: D61F0200  br       x16
uint64_t fde_func_03225_0x24f23c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0024F23CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9100A008ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9401010ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0803E0ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD61F0200ULL ^ (4ULL << 32);
    return state ^ (state >> 29);
}

// FDE #03235 | PC: 0x24fe08..0x24fe60 (88 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x24fe08: D503233F  paciasp  
//   0x24fe0c: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x24fe10: F9000BF3  str      x19, [sp, #0x10]
//   0x24fe14: 910003FD  mov      x29, sp
//   0x24fe18: 6F00E400  movi     v0.2d, #0000000000000000
//   0x24fe1c: D503201F  nop      
uint64_t fde_func_03235_0x24fe08(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0024FE08ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF3ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x6F00E400ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503201FULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x100443E8ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x2A0203E3ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #03244 | PC: 0x250b08..0x250c08 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x250b08: D503233F  paciasp  
//   0x250b0c: A9BA7BFD  stp      x29, x30, [sp, #-0x60]!
//   0x250b10: A9016FFC  stp      x28, x27, [sp, #0x10]
//   0x250b14: A90267FA  stp      x26, x25, [sp, #0x20]
//   0x250b18: A9035FF8  stp      x24, x23, [sp, #0x30]
//   0x250b1c: A90457F6  stp      x22, x21, [sp, #0x40]
uint64_t fde_func_03244_0x250b08(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00250B08ULL);
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

// FDE #03254 | PC: 0x252394..0x2523a0 (12 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x252394: D503245F  bti      c
//   0x252398: D1004000  sub      x0, x0, #0x10
//   0x25239c: 17FFFF09  b        #0x251fc0
uint64_t fde_func_03254_0x252394(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00252394ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD1004000ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x17FFFF09ULL ^ (2ULL << 32);
    return state ^ (state >> 29);
}

// FDE #03263 | PC: 0x252400..0x25240c (12 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x252400: D503245F  bti      c
//   0x252404: D1020000  sub      x0, x0, #0x80
//   0x252408: 17FFFF4A  b        #0x252130
uint64_t fde_func_03263_0x252400(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00252400ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD1020000ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x17FFFF4AULL ^ (2ULL << 32);
    return state ^ (state >> 29);
}

// FDE #03273 | PC: 0x252988..0x2529d4 (76 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x252988: D503245F  bti      c
//   0x25298c: F0001AA9  adrp     x9, #0x5a9000
//   0x252990: 913C0129  add      x9, x9, #0xf00
//   0x252994: AA0003E8  mov      x8, x0
//   0x252998: F0001AAA  adrp     x10, #0x5a9000
//   0x25299c: 913B414A  add      x10, x10, #0xed0
uint64_t fde_func_03273_0x252988(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00252988ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF0001AA9ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x913C0129ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003E8ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF0001AAAULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x913B414AULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000009ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91010029ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #03283 | PC: 0x253380..0x253438 (184 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x253380: D503245F  bti      c
//   0x253384: F9400408  ldr      x8, [x0, #8]
//   0x253388: B4000448  cbz      x8, #0x253410
//   0x25338c: 9E670100  fmov     d0, x8
//   0x253390: 2A0103EA  mov      w10, w1
//   0x253394: 0E205800  cnt      v0.8b, v0.8b
uint64_t fde_func_03283_0x253380(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00253380ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400408ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB4000448ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9E670100ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x2A0103EAULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x0E205800ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x2E303800ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x1E260009ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #03292 | PC: 0x253da0..0x253e90 (240 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x253da0: D503233F  paciasp  
//   0x253da4: D10243FF  sub      sp, sp, #0x90
//   0x253da8: A9047BFD  stp      x29, x30, [sp, #0x40]
//   0x253dac: A90567FA  stp      x26, x25, [sp, #0x50]
//   0x253db0: A9065FF8  stp      x24, x23, [sp, #0x60]
//   0x253db4: A90757F6  stp      x22, x21, [sp, #0x70]
uint64_t fde_func_03292_0x253da0(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00253DA0ULL);
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

// FDE #03302 | PC: 0x254384..0x25439c (24 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x254384: D503245F  bti      c
//   0x254388: B4000060  cbz      x0, #0x254394
//   0x25438c: 52800701  mov      w1, #0x38
//   0x254390: 140A1CDC  b        #0x4db700
//   0x254394: 52800700  mov      w0, #0x38
//   0x254398: 14022077  b        #0x2dc574
uint64_t fde_func_03302_0x254384(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00254384ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB4000060ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x52800701ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x140A1CDCULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x52800700ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x14022077ULL ^ (5ULL << 32);
    return state ^ (state >> 29);
}

// FDE #03311 | PC: 0x254778..0x2547d4 (92 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x254778: D503233F  paciasp  
//   0x25477c: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x254780: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x254784: 910003FD  mov      x29, sp
//   0x254788: AA0203E8  mov      x8, x2
//   0x25478c: EB01007F  cmp      x3, x1
uint64_t fde_func_03311_0x254778(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00254778ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9014FF4ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0203E8ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xEB01007FULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0103F4ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9A813062ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #03321 | PC: 0x254a14..0x254b14 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x254a14: D503233F  paciasp  
//   0x254a18: A9BA7BFD  stp      x29, x30, [sp, #-0x60]!
//   0x254a1c: A9016FFC  stp      x28, x27, [sp, #0x10]
//   0x254a20: A90267FA  stp      x26, x25, [sp, #0x20]
//   0x254a24: A9035FF8  stp      x24, x23, [sp, #0x30]
//   0x254a28: A90457F6  stp      x22, x21, [sp, #0x40]
uint64_t fde_func_03321_0x254a14(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00254A14ULL);
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

// FDE #03330 | PC: 0x254f9c..0x255034 (152 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x254f9c: D503233F  paciasp  
//   0x254fa0: A9BD7BFD  stp      x29, x30, [sp, #-0x30]!
//   0x254fa4: F9000BF5  str      x21, [sp, #0x10]
//   0x254fa8: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x254fac: 910003FD  mov      x29, sp
//   0x254fb0: F9400013  ldr      x19, [x0]
uint64_t fde_func_03330_0x254f9c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00254F9CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BD7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF5ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9024FF4ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400013ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000001ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB4000353ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #03340 | PC: 0x255b34..0x255bb0 (124 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x255b34: D503233F  paciasp  
//   0x255b38: A9BD7BFD  stp      x29, x30, [sp, #-0x30]!
//   0x255b3c: F9000BF5  str      x21, [sp, #0x10]
//   0x255b40: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x255b44: 910003FD  mov      x29, sp
//   0x255b48: 9100C014  add      x20, x0, #0x30
uint64_t fde_func_03340_0x255b34(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00255B34ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BD7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF5ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9024FF4ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9100C014ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F5ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA1403E0ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #03349 | PC: 0x255df8..0x255e04 (12 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x255df8: D503245F  bti      c
//   0x255dfc: AA1F03E1  mov      x1, xzr
//   0x255e00: 140CAAF6  b        #0x5809d8
uint64_t fde_func_03349_0x255df8(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00255DF8ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA1F03E1ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x140CAAF6ULL ^ (2ULL << 32);
    return state ^ (state >> 29);
}

// FDE #03359 | PC: 0x256b28..0x256bf8 (208 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x256b28: D503233F  paciasp  
//   0x256b2c: D10103FF  sub      sp, sp, #0x40
//   0x256b30: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x256b34: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x256b38: 910083FD  add      x29, sp, #0x20
//   0x256b3c: AA0103F3  mov      x19, x1
uint64_t fde_func_03359_0x256b28(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00256B28ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10103FFULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9027BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9034FF4ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910083FDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0103F3ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x97FFEF87ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x90FFF3A1ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #03368 | PC: 0x257f0c..0x257f64 (88 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x257f0c: D503233F  paciasp  
//   0x257f10: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x257f14: F9000BF3  str      x19, [sp, #0x10]
//   0x257f18: 910003FD  mov      x29, sp
//   0x257f1c: 39400028  ldrb     w8, [x1]
//   0x257f20: AA0003F3  mov      x19, x0
uint64_t fde_func_03368_0x257f0c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00257F0CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF3ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x39400028ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x340000C8ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x38408408ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #03378 | PC: 0x258568..0x258668 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x258568: D503233F  paciasp  
//   0x25856c: D10603FF  sub      sp, sp, #0x180
//   0x258570: A9147BFD  stp      x29, x30, [sp, #0x140]
//   0x258574: A9155FFC  stp      x28, x23, [sp, #0x150]
//   0x258578: A91657F6  stp      x22, x21, [sp, #0x160]
//   0x25857c: A9174FF4  stp      x20, x19, [sp, #0x170]
uint64_t fde_func_03378_0x258568(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00258568ULL);
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

// FDE #03387 | PC: 0x259538..0x259570 (56 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x259538: D503245F  bti      c
//   0x25953c: A942A009  ldp      x9, x8, [x0, #0x28]
//   0x259540: F9401010  ldr      x16, [x0, #0x20]
//   0x259544: F9402002  ldr      x2, [x0, #0x40]
//   0x259548: 8B890508  add      x8, x8, x9, asr #1
//   0x25954c: 36000069  tbz      w9, #0, #0x259558
uint64_t fde_func_03387_0x259538(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00259538ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA942A009ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9401010ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9402002ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x8B890508ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x36000069ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400109ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF8706930ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #03397 | PC: 0x25a5b8..0x25a628 (112 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x25a5b8: D503233F  paciasp  
//   0x25a5bc: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x25a5c0: F9000BF3  str      x19, [sp, #0x10]
//   0x25a5c4: 910003FD  mov      x29, sp
//   0x25a5c8: AA0003F3  mov      x19, x0
//   0x25a5cc: 91042000  add      x0, x0, #0x108
uint64_t fde_func_03397_0x25a5b8(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0025A5B8ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF3ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91042000ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x940CB230ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9103C260ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #03406 | PC: 0x25aa94..0x25ab94 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x25aa94: D503233F  paciasp  
//   0x25aa98: A9BC7BFD  stp      x29, x30, [sp, #-0x40]!
//   0x25aa9c: A9015FFC  stp      x28, x23, [sp, #0x10]
//   0x25aaa0: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x25aaa4: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x25aaa8: 910003FD  mov      x29, sp
uint64_t fde_func_03406_0x25aa94(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0025AA94ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BC7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9015FFCULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90257F6ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9034FF4ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10703FFULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD53BD055ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #03416 | PC: 0x25b39c..0x25b3e8 (76 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x25b39c: D503245F  bti      c
//   0x25b3a0: B4000220  cbz      x0, #0x25b3e4
//   0x25b3a4: D503233F  paciasp  
//   0x25b3a8: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x25b3ac: F9000BF3  str      x19, [sp, #0x10]
//   0x25b3b0: 910003FD  mov      x29, sp
uint64_t fde_func_03416_0x25b39c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0025B39CULL);
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

// FDE #03425 | PC: 0x25b7a0..0x25b7bc (28 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x25b7a0: D503245F  bti      c
//   0x25b7a4: AA0003E8  mov      x8, x0
//   0x25b7a8: F9400000  ldr      x0, [x0]
//   0x25b7ac: F900011F  str      xzr, [x8]
//   0x25b7b0: B4000040  cbz      x0, #0x25b7b8
//   0x25b7b4: 1401D5F1  b        #0x2d0f78
uint64_t fde_func_03425_0x25b7a0(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0025B7A0ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003E8ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400000ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF900011FULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB4000040ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x1401D5F1ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD65F03C0ULL ^ (6ULL << 32);
    return state ^ (state >> 29);
}

// FDE #03435 | PC: 0x25ce24..0x25cef4 (208 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x25ce24: D503233F  paciasp  
//   0x25ce28: A9BC7BFD  stp      x29, x30, [sp, #-0x40]!
//   0x25ce2c: A9015FF8  stp      x24, x23, [sp, #0x10]
//   0x25ce30: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x25ce34: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x25ce38: 910003FD  mov      x29, sp
uint64_t fde_func_03435_0x25ce24(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0025CE24ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BC7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9015FF8ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90257F6ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9034FF4ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F5ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x2A0203F3ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #03444 | PC: 0x25de6c..0x25df6c (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x25de6c: D503233F  paciasp  
//   0x25de70: A9BC7BFD  stp      x29, x30, [sp, #-0x40]!
//   0x25de74: A9015FFC  stp      x28, x23, [sp, #0x10]
//   0x25de78: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x25de7c: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x25de80: 910003FD  mov      x29, sp
uint64_t fde_func_03444_0x25de6c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0025DE6CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BC7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9015FFCULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90257F6ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9034FF4ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10943FFULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD53BD057ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #03454 | PC: 0x25eb10..0x25eb1c (12 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x25eb10: D503245F  bti      c
//   0x25eb14: AA1F03E1  mov      x1, xzr
//   0x25eb18: 14000001  b        #0x25eb1c
uint64_t fde_func_03454_0x25eb10(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0025EB10ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA1F03E1ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x14000001ULL ^ (2ULL << 32);
    return state ^ (state >> 29);
}

// FDE #03463 | PC: 0x25f018..0x25f050 (56 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x25f018: D503245F  bti      c
//   0x25f01c: B4000180  cbz      x0, #0x25f04c
//   0x25f020: D503233F  paciasp  
//   0x25f024: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x25f028: F9000BF3  str      x19, [sp, #0x10]
//   0x25f02c: 910003FD  mov      x29, sp
uint64_t fde_func_03463_0x25f018(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0025F018ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB4000180ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE7BFDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF3ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9409276FULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #03473 | PC: 0x25f59c..0x25f5a8 (12 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x25f59c: D503245F  bti      c
//   0x25f5a0: D100C000  sub      x0, x0, #0x30
//   0x25f5a4: 17FFFF78  b        #0x25f384
uint64_t fde_func_03473_0x25f59c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0025F59CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD100C000ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x17FFFF78ULL ^ (2ULL << 32);
    return state ^ (state >> 29);
}

// FDE #03482 | PC: 0x25ff48..0x260048 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x25ff48: D503233F  paciasp  
//   0x25ff4c: D106C3FF  sub      sp, sp, #0x1b0
//   0x25ff50: A9157BFD  stp      x29, x30, [sp, #0x150]
//   0x25ff54: A9166FFC  stp      x28, x27, [sp, #0x160]
//   0x25ff58: A91767FA  stp      x26, x25, [sp, #0x170]
//   0x25ff5c: A9185FF8  stp      x24, x23, [sp, #0x180]
uint64_t fde_func_03482_0x25ff48(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0025FF48ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD106C3FFULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9157BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9166FFCULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA91767FAULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9185FF8ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA91957F6ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA91A4FF4ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #03492 | PC: 0x260b14..0x260c14 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x260b14: D503233F  paciasp  
//   0x260b18: D10243FF  sub      sp, sp, #0x90
//   0x260b1c: A9047BFD  stp      x29, x30, [sp, #0x40]
//   0x260b20: A90567FA  stp      x26, x25, [sp, #0x50]
//   0x260b24: A9065FF8  stp      x24, x23, [sp, #0x60]
//   0x260b28: A90757F6  stp      x22, x21, [sp, #0x70]
uint64_t fde_func_03492_0x260b14(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00260B14ULL);
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

// FDE #03501 | PC: 0x2615ac..0x2616ac (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x2615ac: D503233F  paciasp  
//   0x2615b0: D10683FF  sub      sp, sp, #0x1a0
//   0x2615b4: A9167BFD  stp      x29, x30, [sp, #0x160]
//   0x2615b8: A9175FFC  stp      x28, x23, [sp, #0x170]
//   0x2615bc: A91857F6  stp      x22, x21, [sp, #0x180]
//   0x2615c0: A9194FF4  stp      x20, x19, [sp, #0x190]
uint64_t fde_func_03501_0x2615ac(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x002615ACULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10683FFULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9167BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9175FFCULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA91857F6ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9194FF4ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910583FDULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD53BD057ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #03511 | PC: 0x262234..0x2622d8 (164 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x262234: D503233F  paciasp  
//   0x262238: D10103FF  sub      sp, sp, #0x40
//   0x26223c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x262240: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x262244: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x262248: 910043FD  add      x29, sp, #0x10
uint64_t fde_func_03511_0x262234(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00262234ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10103FFULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90257F6ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9034FF4ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0303F4ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x2A0103F3ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #03520 | PC: 0x262574..0x262674 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x262574: D503233F  paciasp  
//   0x262578: A9BB7BFD  stp      x29, x30, [sp, #-0x50]!
//   0x26257c: F9000BFC  str      x28, [sp, #0x10]
//   0x262580: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x262584: A90357F6  stp      x22, x21, [sp, #0x30]
//   0x262588: A9044FF4  stp      x20, x19, [sp, #0x40]
uint64_t fde_func_03520_0x262574(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00262574ULL);
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

// FDE #03530 | PC: 0x26325c..0x26335c (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x26325c: D503233F  paciasp  
//   0x263260: D10603FF  sub      sp, sp, #0x180
//   0x263264: A9147BFD  stp      x29, x30, [sp, #0x140]
//   0x263268: A9155FFC  stp      x28, x23, [sp, #0x150]
//   0x26326c: A91657F6  stp      x22, x21, [sp, #0x160]
//   0x263270: A9174FF4  stp      x20, x19, [sp, #0x170]
uint64_t fde_func_03530_0x26325c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0026325CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10603FFULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9147BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9155FFCULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA91657F6ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9174FF4ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910503FDULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD53BD056ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #03539 | PC: 0x263af0..0x263bc4 (212 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x263af0: D503233F  paciasp  
//   0x263af4: A9BB7BFD  stp      x29, x30, [sp, #-0x50]!
//   0x263af8: F9000BF9  str      x25, [sp, #0x10]
//   0x263afc: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x263b00: A90357F6  stp      x22, x21, [sp, #0x30]
//   0x263b04: A9044FF4  stp      x20, x19, [sp, #0x40]
uint64_t fde_func_03539_0x263af0(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00263AF0ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BB7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF9ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9025FF8ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90357F6ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9044FF4ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F5ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #03549 | PC: 0x263f14..0x264014 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x263f14: D503233F  paciasp  
//   0x263f18: D105C3FF  sub      sp, sp, #0x170
//   0x263f1c: A9147BFD  stp      x29, x30, [sp, #0x140]
//   0x263f20: A91557FC  stp      x28, x21, [sp, #0x150]
//   0x263f24: A9164FF4  stp      x20, x19, [sp, #0x160]
//   0x263f28: 910503FD  add      x29, sp, #0x140
uint64_t fde_func_03549_0x263f14(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00263F14ULL);
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

// FDE #03558 | PC: 0x2640a4..0x2640b0 (12 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x2640a4: D503245F  bti      c
//   0x2640a8: D100C000  sub      x0, x0, #0x30
//   0x2640ac: 17FFFCB4  b        #0x26337c
uint64_t fde_func_03558_0x2640a4(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x002640A4ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD100C000ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x17FFFCB4ULL ^ (2ULL << 32);
    return state ^ (state >> 29);
}

// FDE #03568 | PC: 0x264500..0x264600 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x264500: D503233F  paciasp  
//   0x264504: D106C3FF  sub      sp, sp, #0x1b0
//   0x264508: A9177BFD  stp      x29, x30, [sp, #0x170]
//   0x26450c: A9185FFC  stp      x28, x23, [sp, #0x180]
//   0x264510: A91957F6  stp      x22, x21, [sp, #0x190]
//   0x264514: A91A4FF4  stp      x20, x19, [sp, #0x1a0]
uint64_t fde_func_03568_0x264500(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00264500ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD106C3FFULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9177BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9185FFCULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA91957F6ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA91A4FF4ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9105C3FDULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD53BD056ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #03578 | PC: 0x264ef0..0x264f28 (56 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x264ef0: D503233F  paciasp  
//   0x264ef4: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x264ef8: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x264efc: 910003FD  mov      x29, sp
//   0x264f00: AA0003F3  mov      x19, x0
//   0x264f04: 52800E00  mov      w0, #0x70
uint64_t fde_func_03578_0x264ef0(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00264EF0ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9014FF4ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x52800E00ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9401DD9BULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F4ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #03587 | PC: 0x265908..0x26593c (52 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x265908: D503245F  bti      c
//   0x26590c: A942A40A  ldp      x10, x9, [x0, #0x28]
//   0x265910: AA0003E8  mov      x8, x0
//   0x265914: F9401010  ldr      x16, [x0, #0x20]
//   0x265918: 8B8A0520  add      x0, x9, x10, asr #1
//   0x26591c: 3600006A  tbz      w10, #0, #0x265928
uint64_t fde_func_03587_0x265908(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00265908ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA942A40AULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003E8ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9401010ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x8B8A0520ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x3600006AULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400009ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF8706930ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #03597 | PC: 0x265d98..0x265e00 (104 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x265d98: D503233F  paciasp  
//   0x265d9c: A9BC7BFD  stp      x29, x30, [sp, #-0x40]!
//   0x265da0: A9015FF8  stp      x24, x23, [sp, #0x10]
//   0x265da4: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x265da8: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x265dac: 910003FD  mov      x29, sp
uint64_t fde_func_03597_0x265d98(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00265D98ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BC7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9015FF8ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90257F6ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9034FF4ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F8ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x52800800ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #03606 | PC: 0x266028..0x2660cc (164 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x266028: D503233F  paciasp  
//   0x26602c: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x266030: F9000BF3  str      x19, [sp, #0x10]
//   0x266034: 910003FD  mov      x29, sp
//   0x266038: 52802300  mov      w0, #0x118
//   0x26603c: 9401D94E  bl       #0x2dc574
uint64_t fde_func_03606_0x266028(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00266028ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF3ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x52802300ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9401D94EULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91002000ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #03616 | PC: 0x266234..0x266240 (12 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x266234: D503245F  bti      c
//   0x266238: 39038001  strb     w1, [x0, #0xe0]
//   0x26623c: D65F03C0  ret      
uint64_t fde_func_03616_0x266234(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00266234ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x39038001ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD65F03C0ULL ^ (2ULL << 32);
    return state ^ (state >> 29);
}

// FDE #03625 | PC: 0x2662ac..0x2662bc (16 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x2662ac: D503245F  bti      c
//   0x2662b0: F9406408  ldr      x8, [x0, #0xc8]
//   0x2662b4: F9006808  str      x8, [x0, #0xd0]
//   0x2662b8: D65F03C0  ret      
uint64_t fde_func_03625_0x2662ac(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x002662ACULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9406408ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9006808ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD65F03C0ULL ^ (3ULL << 32);
    return state ^ (state >> 29);
}

// FDE #03635 | PC: 0x2663e8..0x266450 (104 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x2663e8: D503233F  paciasp  
//   0x2663ec: A9BD7BFD  stp      x29, x30, [sp, #-0x30]!
//   0x2663f0: F9000BF5  str      x21, [sp, #0x10]
//   0x2663f4: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x2663f8: 910003FD  mov      x29, sp
//   0x2663fc: AA0003F3  mov      x19, x0
uint64_t fde_func_03635_0x2663e8(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x002663E8ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BD7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF5ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9024FF4ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0103F4ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x38408E68ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #03644 | PC: 0x26669c..0x26673c (160 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x26669c: D503233F  paciasp  
//   0x2666a0: D10103FF  sub      sp, sp, #0x40
//   0x2666a4: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x2666a8: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x2666ac: 910083FD  add      x29, sp, #0x20
//   0x2666b0: B0001BC8  adrp     x8, #0x5df000
uint64_t fde_func_03644_0x26669c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0026669CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10103FFULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9027BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9034FF4ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910083FDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB0001BC8ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9438108ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #03654 | PC: 0x266ba4..0x266bb0 (12 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x266ba4: D503245F  bti      c
//   0x266ba8: D1004000  sub      x0, x0, #0x10
//   0x266bac: 17FFFF0C  b        #0x2667dc
uint64_t fde_func_03654_0x266ba4(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00266BA4ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD1004000ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x17FFFF0CULL ^ (2ULL << 32);
    return state ^ (state >> 29);
}

// FDE #03663 | PC: 0x267190..0x2671cc (60 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x267190: D503233F  paciasp  
//   0x267194: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x267198: F9000BF3  str      x19, [sp, #0x10]
//   0x26719c: 910003FD  mov      x29, sp
//   0x2671a0: AA0003F3  mov      x19, x0
//   0x2671a4: 52800300  mov      w0, #0x18
uint64_t fde_func_03663_0x267190(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00267190ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF3ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x52800300ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9401D4F3ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB0001988ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #03673 | PC: 0x2673b4..0x2673e4 (48 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x2673b4: D503233F  paciasp  
//   0x2673b8: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x2673bc: F9000BF3  str      x19, [sp, #0x10]
//   0x2673c0: 910003FD  mov      x29, sp
//   0x2673c4: AA0003F3  mov      x19, x0
//   0x2673c8: 91006000  add      x0, x0, #0x18
uint64_t fde_func_03673_0x2673b4(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x002673B4ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF3ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91006000ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x97FF8A0DULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA1303E0ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #03682 | PC: 0x2678c4..0x2678d0 (12 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x2678c4: D503245F  bti      c
//   0x2678c8: 91002000  add      x0, x0, #8
//   0x2678cc: 17FF88CD  b        #0x249c00
uint64_t fde_func_03682_0x2678c4(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x002678C4ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91002000ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x17FF88CDULL ^ (2ULL << 32);
    return state ^ (state >> 29);
}

// FDE #03692 | PC: 0x267b18..0x267bcc (180 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x267b18: D503233F  paciasp  
//   0x267b1c: D10183FF  sub      sp, sp, #0x60
//   0x267b20: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x267b24: F9001BF7  str      x23, [sp, #0x30]
//   0x267b28: A90457F6  stp      x22, x21, [sp, #0x40]
//   0x267b2c: A9054FF4  stp      x20, x19, [sp, #0x50]
uint64_t fde_func_03692_0x267b18(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00267B18ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10183FFULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9027BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9001BF7ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90457F6ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9054FF4ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910083FDULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0103F4ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #03701 | PC: 0x268094..0x2680dc (72 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x268094: D503245F  bti      c
//   0x268098: B4000200  cbz      x0, #0x2680d8
//   0x26809c: D503233F  paciasp  
//   0x2680a0: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x2680a4: F9000BF3  str      x19, [sp, #0x10]
//   0x2680a8: 910003FD  mov      x29, sp
uint64_t fde_func_03701_0x268094(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00268094ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB4000200ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE7BFDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF3ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x39406008ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #03711 | PC: 0x2683ac..0x2683d4 (40 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x2683ac: D503245F  bti      c
//   0x2683b0: F9401008  ldr      x8, [x0, #0x20]
//   0x2683b4: 52800309  mov      w9, #0x18
//   0x2683b8: 9BA92028  umaddl   x8, w1, w9, x8
//   0x2683bc: 39400109  ldrb     w9, [x8]
//   0x2683c0: 37000069  tbnz     w9, #0, #0x2683cc
uint64_t fde_func_03711_0x2683ac(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x002683ACULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9401008ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x52800309ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9BA92028ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x39400109ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x37000069ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91000500ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD65F03C0ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #03720 | PC: 0x26854c..0x2685c8 (124 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x26854c: D503233F  paciasp  
//   0x268550: A9BB7BFD  stp      x29, x30, [sp, #-0x50]!
//   0x268554: A90167FA  stp      x26, x25, [sp, #0x10]
//   0x268558: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x26855c: A90357F6  stp      x22, x21, [sp, #0x30]
//   0x268560: A9044FF4  stp      x20, x19, [sp, #0x40]
uint64_t fde_func_03720_0x26854c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0026854CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BB7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90167FAULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9025FF8ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90357F6ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9044FF4ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003FAULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #03730 | PC: 0x268954..0x2689a8 (84 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x268954: D503233F  paciasp  
//   0x268958: A9BD7BFD  stp      x29, x30, [sp, #-0x30]!
//   0x26895c: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x268960: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x268964: 910003FD  mov      x29, sp
//   0x268968: AA0003F6  mov      x22, x0
uint64_t fde_func_03730_0x268954(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00268954ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BD7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90157F6ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9024FF4ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F6ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x52800600ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0303F3ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #03739 | PC: 0x268c28..0x268c98 (112 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x268c28: D503233F  paciasp  
//   0x268c2c: A9BD7BFD  stp      x29, x30, [sp, #-0x30]!
//   0x268c30: F9000BF5  str      x21, [sp, #0x10]
//   0x268c34: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x268c38: 910003FD  mov      x29, sp
//   0x268c3c: A900FC1F  stp      xzr, xzr, [x0, #8]
uint64_t fde_func_03739_0x268c28(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00268C28ULL);
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

// FDE #03749 | PC: 0x268f40..0x268f88 (72 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x268f40: D503233F  paciasp  
//   0x268f44: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x268f48: F9000BF3  str      x19, [sp, #0x10]
//   0x268f4c: 910003FD  mov      x29, sp
//   0x268f50: B4000120  cbz      x0, #0x268f74
//   0x268f54: AA0303F3  mov      x19, x3
uint64_t fde_func_03749_0x268f40(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00268F40ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF3ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB4000120ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0303F3ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9401AA7DULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB40000C0ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #03758 | PC: 0x26947c..0x269578 (252 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x26947c: D503233F  paciasp  
//   0x269480: D10243FF  sub      sp, sp, #0x90
//   0x269484: A9057BFD  stp      x29, x30, [sp, #0x50]
//   0x269488: F90033F7  str      x23, [sp, #0x60]
//   0x26948c: A90757F6  stp      x22, x21, [sp, #0x70]
//   0x269490: A9084FF4  stp      x20, x19, [sp, #0x80]
uint64_t fde_func_03758_0x26947c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0026947CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10243FFULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9057BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF90033F7ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90757F6ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9084FF4ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910143FDULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x39406008ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #03768 | PC: 0x269840..0x269888 (72 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x269840: D503233F  paciasp  
//   0x269844: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x269848: F9000BF3  str      x19, [sp, #0x10]
//   0x26984c: 910003FD  mov      x29, sp
//   0x269850: F9400013  ldr      x19, [x0]
//   0x269854: F9000001  str      x1, [x0]
uint64_t fde_func_03768_0x269840(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00269840ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF3ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400013ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000001ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB4000113ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400260ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #03777 | PC: 0x269c3c..0x269cf8 (188 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x269c3c: D503233F  paciasp  
//   0x269c40: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x269c44: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x269c48: 910003FD  mov      x29, sp
//   0x269c4c: F0001968  adrp     x8, #0x598000
//   0x269c50: 91334108  add      x8, x8, #0xcd0
uint64_t fde_func_03777_0x269c3c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00269C3CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9014FF4ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF0001968ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91334108ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF0001969ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9135C129ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #03787 | PC: 0x26a228..0x26a328 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x26a228: D503233F  paciasp  
//   0x26a22c: D10143FF  sub      sp, sp, #0x50
//   0x26a230: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x26a234: A90357F6  stp      x22, x21, [sp, #0x30]
//   0x26a238: A9044FF4  stp      x20, x19, [sp, #0x40]
//   0x26a23c: 910083FD  add      x29, sp, #0x20
uint64_t fde_func_03787_0x26a228(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0026A228ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10143FFULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9027BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90357F6ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9044FF4ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910083FDULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB9403048ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0203F5ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #03796 | PC: 0x26a6ec..0x26a6f8 (12 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x26a6ec: D503245F  bti      c
//   0x26a6f0: D1004000  sub      x0, x0, #0x10
//   0x26a6f4: 17FFFF25  b        #0x26a388
uint64_t fde_func_03796_0x26a6ec(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0026A6ECULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD1004000ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x17FFFF25ULL ^ (2ULL << 32);
    return state ^ (state >> 29);
}

uint64_t execute_fde_shard_1(uint32_t fde_idx, uint64_t a0, uint64_t a1) {
    switch (fde_idx) {
        case 0: return fde_func_00000_0x1c6edc(a0, a1);
        case 9: return fde_func_00009_0x1c71f4(a0, a1);
        case 19: return fde_func_00019_0x1c7ca4(a0, a1);
        case 28: return fde_func_00028_0x1c80ac(a0, a1);
        case 38: return fde_func_00038_0x1c8414(a0, a1);
        case 47: return fde_func_00047_0x1c8764(a0, a1);
        case 57: return fde_func_00057_0x1c8ae0(a0, a1);
        case 66: return fde_func_00066_0x1c8dc8(a0, a1);
        case 76: return fde_func_00076_0x1c96f4(a0, a1);
        case 85: return fde_func_00085_0x1c9d40(a0, a1);
        case 95: return fde_func_00095_0x1ca28c(a0, a1);
        case 104: return fde_func_00104_0x1ca978(a0, a1);
        case 114: return fde_func_00114_0x1cb1ac(a0, a1);
        case 123: return fde_func_00123_0x1cb550(a0, a1);
        case 133: return fde_func_00133_0x1cb9a4(a0, a1);
        case 142: return fde_func_00142_0x1ce1b0(a0, a1);
        case 152: return fde_func_00152_0x1cee18(a0, a1);
        case 161: return fde_func_00161_0x1cf5e4(a0, a1);
        case 171: return fde_func_00171_0x1cfe64(a0, a1);
        case 180: return fde_func_00180_0x1d015c(a0, a1);
        case 190: return fde_func_00190_0x1d0514(a0, a1);
        case 199: return fde_func_00199_0x1d075c(a0, a1);
        case 209: return fde_func_00209_0x1d1bec(a0, a1);
        case 218: return fde_func_00218_0x1d1ef4(a0, a1);
        case 228: return fde_func_00228_0x1d2550(a0, a1);
        case 237: return fde_func_00237_0x1d2768(a0, a1);
        case 247: return fde_func_00247_0x1d2eec(a0, a1);
        case 256: return fde_func_00256_0x1d32d4(a0, a1);
        case 266: return fde_func_00266_0x1d4278(a0, a1);
        case 275: return fde_func_00275_0x1d4714(a0, a1);
        case 285: return fde_func_00285_0x1d4ab4(a0, a1);
        case 294: return fde_func_00294_0x1d5114(a0, a1);
        case 304: return fde_func_00304_0x1d59fc(a0, a1);
        case 314: return fde_func_00314_0x1d6188(a0, a1);
        case 323: return fde_func_00323_0x1d6ce8(a0, a1);
        case 333: return fde_func_00333_0x1d72d8(a0, a1);
        case 342: return fde_func_00342_0x1d7624(a0, a1);
        case 352: return fde_func_00352_0x1d78ec(a0, a1);
        case 361: return fde_func_00361_0x1d8108(a0, a1);
        case 371: return fde_func_00371_0x1d85d4(a0, a1);
        case 380: return fde_func_00380_0x1d8c88(a0, a1);
        case 390: return fde_func_00390_0x1d9318(a0, a1);
        case 399: return fde_func_00399_0x1d96c0(a0, a1);
        case 409: return fde_func_00409_0x1daa28(a0, a1);
        case 418: return fde_func_00418_0x1dae9c(a0, a1);
        case 428: return fde_func_00428_0x1db090(a0, a1);
        case 437: return fde_func_00437_0x1db404(a0, a1);
        case 447: return fde_func_00447_0x1dbd40(a0, a1);
        case 456: return fde_func_00456_0x1dc550(a0, a1);
        case 466: return fde_func_00466_0x1dc994(a0, a1);
        case 475: return fde_func_00475_0x1dcc50(a0, a1);
        case 485: return fde_func_00485_0x1dd61c(a0, a1);
        case 494: return fde_func_00494_0x1ddcd0(a0, a1);
        case 504: return fde_func_00504_0x1dde6c(a0, a1);
        case 513: return fde_func_00513_0x1dede8(a0, a1);
        case 523: return fde_func_00523_0x1df5a0(a0, a1);
        case 532: return fde_func_00532_0x1dfa2c(a0, a1);
        case 542: return fde_func_00542_0x1dff3c(a0, a1);
        case 551: return fde_func_00551_0x1e0490(a0, a1);
        case 561: return fde_func_00561_0x1e0a60(a0, a1);
        case 570: return fde_func_00570_0x1e0e80(a0, a1);
        case 580: return fde_func_00580_0x1e15d0(a0, a1);
        case 589: return fde_func_00589_0x1e19d0(a0, a1);
        case 599: return fde_func_00599_0x1e1e3c(a0, a1);
        case 609: return fde_func_00609_0x1e201c(a0, a1);
        case 618: return fde_func_00618_0x1e21e8(a0, a1);
        case 628: return fde_func_00628_0x1e2784(a0, a1);
        case 637: return fde_func_00637_0x1e2c40(a0, a1);
        case 647: return fde_func_00647_0x1e35c8(a0, a1);
        case 656: return fde_func_00656_0x1e49c8(a0, a1);
        case 666: return fde_func_00666_0x1e53d0(a0, a1);
        case 675: return fde_func_00675_0x1e5898(a0, a1);
        case 685: return fde_func_00685_0x1e6704(a0, a1);
        case 694: return fde_func_00694_0x1e6a2c(a0, a1);
        case 704: return fde_func_00704_0x1e78b4(a0, a1);
        case 713: return fde_func_00713_0x1e8364(a0, a1);
        case 723: return fde_func_00723_0x1e8cd0(a0, a1);
        case 732: return fde_func_00732_0x1e9878(a0, a1);
        case 742: return fde_func_00742_0x1e9f0c(a0, a1);
        case 751: return fde_func_00751_0x1e9f78(a0, a1);
        case 761: return fde_func_00761_0x1e9ff8(a0, a1);
        case 770: return fde_func_00770_0x1ea07c(a0, a1);
        case 780: return fde_func_00780_0x1ea0f4(a0, a1);
        case 789: return fde_func_00789_0x1ea160(a0, a1);
        case 799: return fde_func_00799_0x1ea1d8(a0, a1);
        case 808: return fde_func_00808_0x1ea358(a0, a1);
        case 818: return fde_func_00818_0x1ea64c(a0, a1);
        case 827: return fde_func_00827_0x1ea878(a0, a1);
        case 837: return fde_func_00837_0x1eaf50(a0, a1);
        case 846: return fde_func_00846_0x1eb38c(a0, a1);
        case 856: return fde_func_00856_0x1ebc10(a0, a1);
        case 865: return fde_func_00865_0x1ec124(a0, a1);
        case 875: return fde_func_00875_0x1f08fc(a0, a1);
        case 884: return fde_func_00884_0x1f0fe4(a0, a1);
        case 894: return fde_func_00894_0x1f1cdc(a0, a1);
        case 904: return fde_func_00904_0x1f27d8(a0, a1);
        case 913: return fde_func_00913_0x1f2b7c(a0, a1);
        case 923: return fde_func_00923_0x1f3198(a0, a1);
        case 932: return fde_func_00932_0x1f37d8(a0, a1);
        case 942: return fde_func_00942_0x1f3d8c(a0, a1);
        case 951: return fde_func_00951_0x1f4058(a0, a1);
        case 961: return fde_func_00961_0x1f45ac(a0, a1);
        case 970: return fde_func_00970_0x1f6148(a0, a1);
        case 980: return fde_func_00980_0x1f6840(a0, a1);
        case 989: return fde_func_00989_0x1f6df4(a0, a1);
        case 999: return fde_func_00999_0x1f73cc(a0, a1);
        case 1008: return fde_func_01008_0x1f7ba4(a0, a1);
        case 1018: return fde_func_01018_0x1f7e60(a0, a1);
        case 1027: return fde_func_01027_0x1f854c(a0, a1);
        case 1037: return fde_func_01037_0x1f8b6c(a0, a1);
        case 1046: return fde_func_01046_0x1f8e38(a0, a1);
        case 1056: return fde_func_01056_0x1f91ec(a0, a1);
        case 1065: return fde_func_01065_0x1f96cc(a0, a1);
        case 1075: return fde_func_01075_0x1fa824(a0, a1);
        case 1084: return fde_func_01084_0x1fad74(a0, a1);
        case 1094: return fde_func_01094_0x1fb1c0(a0, a1);
        case 1103: return fde_func_01103_0x1fb9cc(a0, a1);
        case 1113: return fde_func_01113_0x1fbf74(a0, a1);
        case 1122: return fde_func_01122_0x1fc218(a0, a1);
        case 1132: return fde_func_01132_0x1fdaf0(a0, a1);
        case 1141: return fde_func_01141_0x1fe2d0(a0, a1);
        case 1151: return fde_func_01151_0x1fe418(a0, a1);
        case 1160: return fde_func_01160_0x1fedcc(a0, a1);
        case 1170: return fde_func_01170_0x1ff114(a0, a1);
        case 1179: return fde_func_01179_0x202388(a0, a1);
        case 1189: return fde_func_01189_0x202a30(a0, a1);
        case 1199: return fde_func_01199_0x203348(a0, a1);
        case 1208: return fde_func_01208_0x203834(a0, a1);
        case 1218: return fde_func_01218_0x2060b8(a0, a1);
        case 1227: return fde_func_01227_0x206638(a0, a1);
        case 1237: return fde_func_01237_0x206a84(a0, a1);
        case 1246: return fde_func_01246_0x206f5c(a0, a1);
        case 1256: return fde_func_01256_0x2074a0(a0, a1);
        case 1265: return fde_func_01265_0x207804(a0, a1);
        case 1275: return fde_func_01275_0x207fe0(a0, a1);
        case 1284: return fde_func_01284_0x208780(a0, a1);
        case 1294: return fde_func_01294_0x208d80(a0, a1);
        case 1303: return fde_func_01303_0x2091bc(a0, a1);
        case 1313: return fde_func_01313_0x209688(a0, a1);
        case 1322: return fde_func_01322_0x209d7c(a0, a1);
        case 1332: return fde_func_01332_0x20a650(a0, a1);
        case 1341: return fde_func_01341_0x20b000(a0, a1);
        case 1351: return fde_func_01351_0x20b678(a0, a1);
        case 1360: return fde_func_01360_0x20b8f8(a0, a1);
        case 1370: return fde_func_01370_0x20bda8(a0, a1);
        case 1379: return fde_func_01379_0x20c070(a0, a1);
        case 1389: return fde_func_01389_0x20c3f0(a0, a1);
        case 1398: return fde_func_01398_0x20c760(a0, a1);
        case 1408: return fde_func_01408_0x20ce24(a0, a1);
        case 1417: return fde_func_01417_0x20d190(a0, a1);
        case 1427: return fde_func_01427_0x20d718(a0, a1);
        case 1436: return fde_func_01436_0x20dae8(a0, a1);
        case 1446: return fde_func_01446_0x20dff8(a0, a1);
        case 1455: return fde_func_01455_0x20e340(a0, a1);
        case 1465: return fde_func_01465_0x20e620(a0, a1);
        case 1474: return fde_func_01474_0x20eb90(a0, a1);
        case 1484: return fde_func_01484_0x20f6d4(a0, a1);
        case 1494: return fde_func_01494_0x20fe8c(a0, a1);
        case 1503: return fde_func_01503_0x210394(a0, a1);
        case 1513: return fde_func_01513_0x210aac(a0, a1);
        case 1522: return fde_func_01522_0x2112f8(a0, a1);
        case 1532: return fde_func_01532_0x211dec(a0, a1);
        case 1541: return fde_func_01541_0x2122c8(a0, a1);
        case 1551: return fde_func_01551_0x2127d8(a0, a1);
        case 1560: return fde_func_01560_0x2131f0(a0, a1);
        case 1570: return fde_func_01570_0x213ffc(a0, a1);
        case 1579: return fde_func_01579_0x214574(a0, a1);
        case 1589: return fde_func_01589_0x214774(a0, a1);
        case 1598: return fde_func_01598_0x214968(a0, a1);
        case 1608: return fde_func_01608_0x214f70(a0, a1);
        case 1617: return fde_func_01617_0x215304(a0, a1);
        case 1627: return fde_func_01627_0x215884(a0, a1);
        case 1636: return fde_func_01636_0x215f58(a0, a1);
        case 1646: return fde_func_01646_0x216e5c(a0, a1);
        case 1655: return fde_func_01655_0x2175cc(a0, a1);
        case 1665: return fde_func_01665_0x217eec(a0, a1);
        case 1674: return fde_func_01674_0x2185c4(a0, a1);
        case 1684: return fde_func_01684_0x218c20(a0, a1);
        case 1693: return fde_func_01693_0x218f08(a0, a1);
        case 1703: return fde_func_01703_0x219360(a0, a1);
        case 1712: return fde_func_01712_0x2195c8(a0, a1);
        case 1722: return fde_func_01722_0x21b04c(a0, a1);
        case 1731: return fde_func_01731_0x21be04(a0, a1);
        case 1741: return fde_func_01741_0x21caf0(a0, a1);
        case 1750: return fde_func_01750_0x21cfec(a0, a1);
        case 1760: return fde_func_01760_0x21d6b0(a0, a1);
        case 1769: return fde_func_01769_0x221408(a0, a1);
        case 1779: return fde_func_01779_0x2220c0(a0, a1);
        case 1789: return fde_func_01789_0x22289c(a0, a1);
        case 1798: return fde_func_01798_0x2235fc(a0, a1);
        case 1808: return fde_func_01808_0x223a04(a0, a1);
        case 1817: return fde_func_01817_0x223fac(a0, a1);
        case 1827: return fde_func_01827_0x22422c(a0, a1);
        case 1836: return fde_func_01836_0x2248a0(a0, a1);
        case 1846: return fde_func_01846_0x224d38(a0, a1);
        case 1855: return fde_func_01855_0x22517c(a0, a1);
        case 1865: return fde_func_01865_0x227bb4(a0, a1);
        case 1874: return fde_func_01874_0x228d28(a0, a1);
        case 1884: return fde_func_01884_0x229a3c(a0, a1);
        case 1893: return fde_func_01893_0x229df8(a0, a1);
        case 1903: return fde_func_01903_0x22a63c(a0, a1);
        case 1912: return fde_func_01912_0x22ae60(a0, a1);
        case 1922: return fde_func_01922_0x22b79c(a0, a1);
        case 1931: return fde_func_01931_0x22bbe0(a0, a1);
        case 1941: return fde_func_01941_0x22c244(a0, a1);
        case 1950: return fde_func_01950_0x22c85c(a0, a1);
        case 1960: return fde_func_01960_0x22cd5c(a0, a1);
        case 1969: return fde_func_01969_0x22d0f0(a0, a1);
        case 1979: return fde_func_01979_0x22d654(a0, a1);
        case 1988: return fde_func_01988_0x22e424(a0, a1);
        case 1998: return fde_func_01998_0x22e970(a0, a1);
        case 2007: return fde_func_02007_0x22eae0(a0, a1);
        case 2017: return fde_func_02017_0x22ec1c(a0, a1);
        case 2026: return fde_func_02026_0x22ed2c(a0, a1);
        case 2036: return fde_func_02036_0x23070c(a0, a1);
        case 2045: return fde_func_02045_0x230804(a0, a1);
        case 2055: return fde_func_02055_0x230950(a0, a1);
        case 2064: return fde_func_02064_0x230bf4(a0, a1);
        case 2074: return fde_func_02074_0x230f60(a0, a1);
        case 2084: return fde_func_02084_0x231778(a0, a1);
        case 2093: return fde_func_02093_0x231bf4(a0, a1);
        case 2103: return fde_func_02103_0x2320a4(a0, a1);
        case 2112: return fde_func_02112_0x2325bc(a0, a1);
        case 2122: return fde_func_02122_0x232c04(a0, a1);
        case 2131: return fde_func_02131_0x232efc(a0, a1);
        case 2141: return fde_func_02141_0x2334e8(a0, a1);
        case 2150: return fde_func_02150_0x233764(a0, a1);
        case 2160: return fde_func_02160_0x233d08(a0, a1);
        case 2169: return fde_func_02169_0x234070(a0, a1);
        case 2179: return fde_func_02179_0x234490(a0, a1);
        case 2188: return fde_func_02188_0x234c90(a0, a1);
        case 2198: return fde_func_02198_0x235830(a0, a1);
        case 2207: return fde_func_02207_0x235fc4(a0, a1);
        case 2217: return fde_func_02217_0x2364c8(a0, a1);
        case 2226: return fde_func_02226_0x236a30(a0, a1);
        case 2236: return fde_func_02236_0x2373e0(a0, a1);
        case 2245: return fde_func_02245_0x2375d0(a0, a1);
        case 2255: return fde_func_02255_0x237b24(a0, a1);
        case 2264: return fde_func_02264_0x239068(a0, a1);
        case 2274: return fde_func_02274_0x239bb4(a0, a1);
        case 2283: return fde_func_02283_0x239f04(a0, a1);
        case 2293: return fde_func_02293_0x23ac78(a0, a1);
        case 2302: return fde_func_02302_0x23ba14(a0, a1);
        case 2312: return fde_func_02312_0x23bf44(a0, a1);
        case 2321: return fde_func_02321_0x23c130(a0, a1);
        case 2331: return fde_func_02331_0x23c774(a0, a1);
        case 2340: return fde_func_02340_0x23cbb8(a0, a1);
        case 2350: return fde_func_02350_0x23ddc0(a0, a1);
        case 2359: return fde_func_02359_0x23e388(a0, a1);
        case 2369: return fde_func_02369_0x23f134(a0, a1);
        case 2379: return fde_func_02379_0x23f974(a0, a1);
        case 2388: return fde_func_02388_0x23fd2c(a0, a1);
        case 2398: return fde_func_02398_0x2401fc(a0, a1);
        case 2407: return fde_func_02407_0x240544(a0, a1);
        case 2417: return fde_func_02417_0x240fc8(a0, a1);
        case 2426: return fde_func_02426_0x24160c(a0, a1);
        case 2436: return fde_func_02436_0x241c64(a0, a1);
        case 2445: return fde_func_02445_0x242800(a0, a1);
        case 2455: return fde_func_02455_0x243254(a0, a1);
        case 2464: return fde_func_02464_0x2437ac(a0, a1);
        case 2474: return fde_func_02474_0x2442d4(a0, a1);
        case 2483: return fde_func_02483_0x244c8c(a0, a1);
        case 2493: return fde_func_02493_0x245454(a0, a1);
        case 2502: return fde_func_02502_0x2455d0(a0, a1);
        case 2512: return fde_func_02512_0x2456f0(a0, a1);
        case 2521: return fde_func_02521_0x245780(a0, a1);
        case 2531: return fde_func_02531_0x245820(a0, a1);
        case 2540: return fde_func_02540_0x2458b0(a0, a1);
        case 2550: return fde_func_02550_0x245950(a0, a1);
        case 2559: return fde_func_02559_0x245b64(a0, a1);
        case 2569: return fde_func_02569_0x245bdc(a0, a1);
        case 2578: return fde_func_02578_0x245c48(a0, a1);
        case 2588: return fde_func_02588_0x245cc0(a0, a1);
        case 2597: return fde_func_02597_0x245d2c(a0, a1);
        case 2607: return fde_func_02607_0x245f70(a0, a1);
        case 2616: return fde_func_02616_0x2461a4(a0, a1);
        case 2626: return fde_func_02626_0x246284(a0, a1);
        case 2635: return fde_func_02635_0x246400(a0, a1);
        case 2645: return fde_func_02645_0x2464b8(a0, a1);
        case 2654: return fde_func_02654_0x246550(a0, a1);
        case 2664: return fde_func_02664_0x2466b0(a0, a1);
        case 2673: return fde_func_02673_0x24674c(a0, a1);
        case 2683: return fde_func_02683_0x24681c(a0, a1);
        case 2693: return fde_func_02693_0x246974(a0, a1);
        case 2702: return fde_func_02702_0x246b68(a0, a1);
        case 2712: return fde_func_02712_0x246e40(a0, a1);
        case 2721: return fde_func_02721_0x246ed8(a0, a1);
        case 2731: return fde_func_02731_0x247060(a0, a1);
        case 2740: return fde_func_02740_0x24715c(a0, a1);
        case 2750: return fde_func_02750_0x2475e8(a0, a1);
        case 2759: return fde_func_02759_0x247654(a0, a1);
        case 2769: return fde_func_02769_0x247914(a0, a1);
        case 2778: return fde_func_02778_0x247a10(a0, a1);
        case 2788: return fde_func_02788_0x247b08(a0, a1);
        case 2797: return fde_func_02797_0x247c58(a0, a1);
        case 2807: return fde_func_02807_0x247ea8(a0, a1);
        case 2816: return fde_func_02816_0x248204(a0, a1);
        case 2826: return fde_func_02826_0x2484c8(a0, a1);
        case 2835: return fde_func_02835_0x24854c(a0, a1);
        case 2845: return fde_func_02845_0x2485f0(a0, a1);
        case 2854: return fde_func_02854_0x2486a0(a0, a1);
        case 2864: return fde_func_02864_0x248848(a0, a1);
        case 2873: return fde_func_02873_0x2489ac(a0, a1);
        case 2883: return fde_func_02883_0x248ba4(a0, a1);
        case 2892: return fde_func_02892_0x248c7c(a0, a1);
        case 2902: return fde_func_02902_0x248d20(a0, a1);
        case 2911: return fde_func_02911_0x2490e8(a0, a1);
        case 2921: return fde_func_02921_0x249278(a0, a1);
        case 2930: return fde_func_02930_0x249324(a0, a1);
        case 2940: return fde_func_02940_0x249408(a0, a1);
        case 2949: return fde_func_02949_0x249570(a0, a1);
        case 2959: return fde_func_02959_0x24967c(a0, a1);
        case 2968: return fde_func_02968_0x2496e8(a0, a1);
        case 2978: return fde_func_02978_0x249760(a0, a1);
        case 2988: return fde_func_02988_0x2497d8(a0, a1);
        case 2997: return fde_func_02997_0x249928(a0, a1);
        case 3007: return fde_func_03007_0x249a70(a0, a1);
        case 3016: return fde_func_03016_0x249f04(a0, a1);
        case 3026: return fde_func_03026_0x24a4d4(a0, a1);
        case 3035: return fde_func_03035_0x24a87c(a0, a1);
        case 3045: return fde_func_03045_0x24acf8(a0, a1);
        case 3054: return fde_func_03054_0x24b3c0(a0, a1);
        case 3064: return fde_func_03064_0x24b5d4(a0, a1);
        case 3073: return fde_func_03073_0x24b8a0(a0, a1);
        case 3083: return fde_func_03083_0x24bfe0(a0, a1);
        case 3092: return fde_func_03092_0x24c124(a0, a1);
        case 3102: return fde_func_03102_0x24c2fc(a0, a1);
        case 3111: return fde_func_03111_0x24c388(a0, a1);
        case 3121: return fde_func_03121_0x24c450(a0, a1);
        case 3130: return fde_func_03130_0x24c6ac(a0, a1);
        case 3140: return fde_func_03140_0x24ca20(a0, a1);
        case 3149: return fde_func_03149_0x24cf58(a0, a1);
        case 3159: return fde_func_03159_0x24d110(a0, a1);
        case 3168: return fde_func_03168_0x24d440(a0, a1);
        case 3178: return fde_func_03178_0x24d868(a0, a1);
        case 3187: return fde_func_03187_0x24ded4(a0, a1);
        case 3197: return fde_func_03197_0x24e408(a0, a1);
        case 3206: return fde_func_03206_0x24e4e8(a0, a1);
        case 3216: return fde_func_03216_0x24eaf0(a0, a1);
        case 3225: return fde_func_03225_0x24f23c(a0, a1);
        case 3235: return fde_func_03235_0x24fe08(a0, a1);
        case 3244: return fde_func_03244_0x250b08(a0, a1);
        case 3254: return fde_func_03254_0x252394(a0, a1);
        case 3263: return fde_func_03263_0x252400(a0, a1);
        case 3273: return fde_func_03273_0x252988(a0, a1);
        case 3283: return fde_func_03283_0x253380(a0, a1);
        case 3292: return fde_func_03292_0x253da0(a0, a1);
        case 3302: return fde_func_03302_0x254384(a0, a1);
        case 3311: return fde_func_03311_0x254778(a0, a1);
        case 3321: return fde_func_03321_0x254a14(a0, a1);
        case 3330: return fde_func_03330_0x254f9c(a0, a1);
        case 3340: return fde_func_03340_0x255b34(a0, a1);
        case 3349: return fde_func_03349_0x255df8(a0, a1);
        case 3359: return fde_func_03359_0x256b28(a0, a1);
        case 3368: return fde_func_03368_0x257f0c(a0, a1);
        case 3378: return fde_func_03378_0x258568(a0, a1);
        case 3387: return fde_func_03387_0x259538(a0, a1);
        case 3397: return fde_func_03397_0x25a5b8(a0, a1);
        case 3406: return fde_func_03406_0x25aa94(a0, a1);
        case 3416: return fde_func_03416_0x25b39c(a0, a1);
        case 3425: return fde_func_03425_0x25b7a0(a0, a1);
        case 3435: return fde_func_03435_0x25ce24(a0, a1);
        case 3444: return fde_func_03444_0x25de6c(a0, a1);
        case 3454: return fde_func_03454_0x25eb10(a0, a1);
        case 3463: return fde_func_03463_0x25f018(a0, a1);
        case 3473: return fde_func_03473_0x25f59c(a0, a1);
        case 3482: return fde_func_03482_0x25ff48(a0, a1);
        case 3492: return fde_func_03492_0x260b14(a0, a1);
        case 3501: return fde_func_03501_0x2615ac(a0, a1);
        case 3511: return fde_func_03511_0x262234(a0, a1);
        case 3520: return fde_func_03520_0x262574(a0, a1);
        case 3530: return fde_func_03530_0x26325c(a0, a1);
        case 3539: return fde_func_03539_0x263af0(a0, a1);
        case 3549: return fde_func_03549_0x263f14(a0, a1);
        case 3558: return fde_func_03558_0x2640a4(a0, a1);
        case 3568: return fde_func_03568_0x264500(a0, a1);
        case 3578: return fde_func_03578_0x264ef0(a0, a1);
        case 3587: return fde_func_03587_0x265908(a0, a1);
        case 3597: return fde_func_03597_0x265d98(a0, a1);
        case 3606: return fde_func_03606_0x266028(a0, a1);
        case 3616: return fde_func_03616_0x266234(a0, a1);
        case 3625: return fde_func_03625_0x2662ac(a0, a1);
        case 3635: return fde_func_03635_0x2663e8(a0, a1);
        case 3644: return fde_func_03644_0x26669c(a0, a1);
        case 3654: return fde_func_03654_0x266ba4(a0, a1);
        case 3663: return fde_func_03663_0x267190(a0, a1);
        case 3673: return fde_func_03673_0x2673b4(a0, a1);
        case 3682: return fde_func_03682_0x2678c4(a0, a1);
        case 3692: return fde_func_03692_0x267b18(a0, a1);
        case 3701: return fde_func_03701_0x268094(a0, a1);
        case 3711: return fde_func_03711_0x2683ac(a0, a1);
        case 3720: return fde_func_03720_0x26854c(a0, a1);
        case 3730: return fde_func_03730_0x268954(a0, a1);
        case 3739: return fde_func_03739_0x268c28(a0, a1);
        case 3749: return fde_func_03749_0x268f40(a0, a1);
        case 3758: return fde_func_03758_0x26947c(a0, a1);
        case 3768: return fde_func_03768_0x269840(a0, a1);
        case 3777: return fde_func_03777_0x269c3c(a0, a1);
        case 3787: return fde_func_03787_0x26a228(a0, a1);
        case 3796: return fde_func_03796_0x26a6ec(a0, a1);
        default: return 0ULL;
    }
}

} // namespace sscronet