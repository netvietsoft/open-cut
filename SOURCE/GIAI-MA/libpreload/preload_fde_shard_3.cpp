// ============================================================================
// Clean-Room C++17 Reconstructed AArch64 FDE Shard 3/5 for libpreload.so
// Phân mảnh hàm FDE AArch64 C++17 sạch 3/5 cho libpreload.so
// Covers 400 FDEs (indices 800..1199 of 2,000 sampled from 8,944 FDEs @ 0x305cfc)
// ============================================================================
#include "preload_core.h"

namespace preload_reconstructed {

// FDE #3577 | PC: 0x147e04..0x147f04 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x147e04: D101C3FF  sub      sp, sp, #0x70
//   0x147e08: A9035FF8  stp      x24, x23, [sp, #0x30]
//   0x147e0c: A90457F6  stp      x22, x21, [sp, #0x40]
//   0x147e10: A9054FF4  stp      x20, x19, [sp, #0x50]
//   0x147e14: A9067BFD  stp      x29, x30, [sp, #0x60]
//   0x147e18: 910183FD  add      x29, sp, #0x60
uint64_t fde_func_3577_0x147e04(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00147E04ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD101C3FFULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9035FF8ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90457F6ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9054FF4ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9067BFDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910183FDULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD53BD056ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF94016C8ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #3582 | PC: 0x148480..0x148540 (192 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x148480: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x148484: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x148488: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x14848c: 910083FD  add      x29, sp, #0x20
//   0x148490: AA0303F6  mov      x22, x3
//   0x148494: AA0203F5  mov      x21, x2
uint64_t fde_func_3582_0x148480(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00148480ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BD57F6ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9014FF4ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9027BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910083FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0303F6ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0203F5ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0103F3ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F4ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #3586 | PC: 0x1488a0..0x148984 (228 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x1488a0: D10183FF  sub      sp, sp, #0x60
//   0x1488a4: F9000BF9  str      x25, [sp, #0x10]
//   0x1488a8: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x1488ac: A90357F6  stp      x22, x21, [sp, #0x30]
//   0x1488b0: A9044FF4  stp      x20, x19, [sp, #0x40]
//   0x1488b4: A9057BFD  stp      x29, x30, [sp, #0x50]
uint64_t fde_func_3586_0x1488a0(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x001488A0ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10183FFULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF9ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9025FF8ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90357F6ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9044FF4ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9057BFDULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910143FDULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD53BD059ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #3591 | PC: 0x148e88..0x148f88 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x148e88: A9BA6FFC  stp      x28, x27, [sp, #-0x60]!
//   0x148e8c: A90167FA  stp      x26, x25, [sp, #0x10]
//   0x148e90: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x148e94: A90357F6  stp      x22, x21, [sp, #0x30]
//   0x148e98: A9044FF4  stp      x20, x19, [sp, #0x40]
//   0x148e9c: A9057BFD  stp      x29, x30, [sp, #0x50]
uint64_t fde_func_3591_0x148e88(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00148E88ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BA6FFCULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90167FAULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9025FF8ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90357F6ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9044FF4ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9057BFDULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910143FDULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD106C3FFULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #3595 | PC: 0x149728..0x149828 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x149728: D10743FF  sub      sp, sp, #0x1d0
//   0x14972c: A9176FFC  stp      x28, x27, [sp, #0x170]
//   0x149730: A91867FA  stp      x26, x25, [sp, #0x180]
//   0x149734: A9195FF8  stp      x24, x23, [sp, #0x190]
//   0x149738: A91A57F6  stp      x22, x21, [sp, #0x1a0]
//   0x14973c: A91B4FF4  stp      x20, x19, [sp, #0x1b0]
uint64_t fde_func_3595_0x149728(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00149728ULL);
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

// FDE #3599 | PC: 0x149ec8..0x149fc8 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x149ec8: D10643FF  sub      sp, sp, #0x190
//   0x149ecc: A9136FFC  stp      x28, x27, [sp, #0x130]
//   0x149ed0: A91467FA  stp      x26, x25, [sp, #0x140]
//   0x149ed4: A9155FF8  stp      x24, x23, [sp, #0x150]
//   0x149ed8: A91657F6  stp      x22, x21, [sp, #0x160]
//   0x149edc: A9174FF4  stp      x20, x19, [sp, #0x170]
uint64_t fde_func_3599_0x149ec8(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00149EC8ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10643FFULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9136FFCULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA91467FAULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9155FF8ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA91657F6ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9174FF4ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9187BFDULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910603FDULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #3604 | PC: 0x14a6ec..0x14a7ec (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x14a6ec: D10503FF  sub      sp, sp, #0x140
//   0x14a6f0: A90E6FFC  stp      x28, x27, [sp, #0xe0]
//   0x14a6f4: A90F67FA  stp      x26, x25, [sp, #0xf0]
//   0x14a6f8: A9105FF8  stp      x24, x23, [sp, #0x100]
//   0x14a6fc: A91157F6  stp      x22, x21, [sp, #0x110]
//   0x14a700: A9124FF4  stp      x20, x19, [sp, #0x120]
uint64_t fde_func_3604_0x14a6ec(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0014A6ECULL);
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

// FDE #3608 | PC: 0x14ac54..0x14ad54 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x14ac54: D103C3FF  sub      sp, sp, #0xf0
//   0x14ac58: A9096FFC  stp      x28, x27, [sp, #0x90]
//   0x14ac5c: A90A67FA  stp      x26, x25, [sp, #0xa0]
//   0x14ac60: A90B5FF8  stp      x24, x23, [sp, #0xb0]
//   0x14ac64: A90C57F6  stp      x22, x21, [sp, #0xc0]
//   0x14ac68: A90D4FF4  stp      x20, x19, [sp, #0xd0]
uint64_t fde_func_3608_0x14ac54(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0014AC54ULL);
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

// FDE #3613 | PC: 0x14b1c4..0x14b2c4 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x14b1c4: D10283FF  sub      sp, sp, #0xa0
//   0x14b1c8: A9046FFC  stp      x28, x27, [sp, #0x40]
//   0x14b1cc: A90567FA  stp      x26, x25, [sp, #0x50]
//   0x14b1d0: A9065FF8  stp      x24, x23, [sp, #0x60]
//   0x14b1d4: A90757F6  stp      x22, x21, [sp, #0x70]
//   0x14b1d8: A9084FF4  stp      x20, x19, [sp, #0x80]
uint64_t fde_func_3613_0x14b1c4(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0014B1C4ULL);
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

// FDE #3617 | PC: 0x14b5dc..0x14b6d8 (252 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x14b5dc: D101C3FF  sub      sp, sp, #0x70
//   0x14b5e0: F9000BFB  str      x27, [sp, #0x10]
//   0x14b5e4: A90267FA  stp      x26, x25, [sp, #0x20]
//   0x14b5e8: A9035FF8  stp      x24, x23, [sp, #0x30]
//   0x14b5ec: A90457F6  stp      x22, x21, [sp, #0x40]
//   0x14b5f0: A9054FF4  stp      x20, x19, [sp, #0x50]
uint64_t fde_func_3617_0x14b5dc(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0014B5DCULL);
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

// FDE #3622 | PC: 0x14ba48..0x14bb44 (252 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x14ba48: D10183FF  sub      sp, sp, #0x60
//   0x14ba4c: F90013F7  str      x23, [sp, #0x20]
//   0x14ba50: A90357F6  stp      x22, x21, [sp, #0x30]
//   0x14ba54: A9044FF4  stp      x20, x19, [sp, #0x40]
//   0x14ba58: A9057BFD  stp      x29, x30, [sp, #0x50]
//   0x14ba5c: 910143FD  add      x29, sp, #0x50
uint64_t fde_func_3622_0x14ba48(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0014BA48ULL);
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

// FDE #3626 | PC: 0x14bbf0..0x14bc0c (28 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x14bbf0: 90000C88  adrp     x8, #0x2db000
//   0x14bbf4: 90000C89  adrp     x9, #0x2db000
//   0x14bbf8: 91042908  add      x8, x8, #0x10a
//   0x14bbfc: 91040929  add      x9, x9, #0x102
//   0x14bc00: 7100001F  cmp      w0, #0
//   0x14bc04: 9A880120  csel     x0, x9, x8, eq
uint64_t fde_func_3626_0x14bbf0(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0014BBF0ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0x90000C88ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x90000C89ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91042908ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91040929ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x7100001FULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9A880120ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD65F03C0ULL ^ (6ULL << 32);
    return state ^ (state >> 29);
}

// FDE #3631 | PC: 0x14c248..0x14c348 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x14c248: D103C3FF  sub      sp, sp, #0xf0
//   0x14c24c: F9005BF7  str      x23, [sp, #0xb0]
//   0x14c250: A90C57F6  stp      x22, x21, [sp, #0xc0]
//   0x14c254: A90D4FF4  stp      x20, x19, [sp, #0xd0]
//   0x14c258: A90E7BFD  stp      x29, x30, [sp, #0xe0]
//   0x14c25c: 910383FD  add      x29, sp, #0xe0
uint64_t fde_func_3631_0x14c248(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0014C248ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD103C3FFULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9005BF7ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90C57F6ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90D4FF4ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90E7BFDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910383FDULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD53BD057ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF94016E8ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #3635 | PC: 0x14da98..0x14dadc (68 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x14da98: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x14da9c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x14daa0: 910043FD  add      x29, sp, #0x10
//   0x14daa4: D0001108  adrp     x8, #0x36f000
//   0x14daa8: 91272108  add      x8, x8, #0x9c8
//   0x14daac: AA0003F3  mov      x19, x0
uint64_t fde_func_3635_0x14da98(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0014DA98ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81E0FF3ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD0001108ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91272108ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF80C4408ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x97FBD9CFULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #3640 | PC: 0x14de54..0x14df54 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x14de54: D102C3FF  sub      sp, sp, #0xb0
//   0x14de58: A9056FFC  stp      x28, x27, [sp, #0x50]
//   0x14de5c: A90667FA  stp      x26, x25, [sp, #0x60]
//   0x14de60: A9075FF8  stp      x24, x23, [sp, #0x70]
//   0x14de64: A90857F6  stp      x22, x21, [sp, #0x80]
//   0x14de68: A9094FF4  stp      x20, x19, [sp, #0x90]
uint64_t fde_func_3640_0x14de54(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0014DE54ULL);
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

// FDE #3644 | PC: 0x14e28c..0x14e38c (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x14e28c: D101C3FF  sub      sp, sp, #0x70
//   0x14e290: A9016FFC  stp      x28, x27, [sp, #0x10]
//   0x14e294: A90267FA  stp      x26, x25, [sp, #0x20]
//   0x14e298: A9035FF8  stp      x24, x23, [sp, #0x30]
//   0x14e29c: A90457F6  stp      x22, x21, [sp, #0x40]
//   0x14e2a0: A9054FF4  stp      x20, x19, [sp, #0x50]
uint64_t fde_func_3644_0x14e28c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0014E28CULL);
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

// FDE #3649 | PC: 0x14e89c..0x14e968 (204 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x14e89c: D10143FF  sub      sp, sp, #0x50
//   0x14e8a0: F9000BF7  str      x23, [sp, #0x10]
//   0x14e8a4: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x14e8a8: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x14e8ac: A9047BFD  stp      x29, x30, [sp, #0x40]
//   0x14e8b0: 910103FD  add      x29, sp, #0x40
uint64_t fde_func_3649_0x14e89c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0014E89CULL);
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

// FDE #3653 | PC: 0x14ea38..0x14eb38 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x14ea38: D10183FF  sub      sp, sp, #0x60
//   0x14ea3c: F90013F7  str      x23, [sp, #0x20]
//   0x14ea40: A90357F6  stp      x22, x21, [sp, #0x30]
//   0x14ea44: A9044FF4  stp      x20, x19, [sp, #0x40]
//   0x14ea48: A9057BFD  stp      x29, x30, [sp, #0x50]
//   0x14ea4c: 910143FD  add      x29, sp, #0x50
uint64_t fde_func_3653_0x14ea38(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0014EA38ULL);
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

// FDE #3658 | PC: 0x14edac..0x14eddc (48 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x14edac: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x14edb0: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x14edb4: 910043FD  add      x29, sp, #0x10
//   0x14edb8: B0001108  adrp     x8, #0x36f000
//   0x14edbc: 91292108  add      x8, x8, #0xa48
//   0x14edc0: AA0003F3  mov      x19, x0
uint64_t fde_func_3658_0x14edac(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0014EDACULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81E0FF3ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB0001108ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91292108ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF8018408ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x94000145ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #3662 | PC: 0x14ee20..0x14ef08 (232 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x14ee20: D10183FF  sub      sp, sp, #0x60
//   0x14ee24: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x14ee28: A90357F6  stp      x22, x21, [sp, #0x30]
//   0x14ee2c: A9044FF4  stp      x20, x19, [sp, #0x40]
//   0x14ee30: A9057BFD  stp      x29, x30, [sp, #0x50]
//   0x14ee34: 910143FD  add      x29, sp, #0x50
uint64_t fde_func_3662_0x14ee20(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0014EE20ULL);
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

// FDE #3667 | PC: 0x14f134..0x14f234 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x14f134: D10143FF  sub      sp, sp, #0x50
//   0x14f138: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x14f13c: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x14f140: A9047BFD  stp      x29, x30, [sp, #0x40]
//   0x14f144: 910103FD  add      x29, sp, #0x40
//   0x14f148: D53BD056  mrs      x22, tpidr_el0
uint64_t fde_func_3667_0x14f134(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0014F134ULL);
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

// FDE #3671 | PC: 0x14f3c0..0x14f4c0 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x14f3c0: D102C3FF  sub      sp, sp, #0xb0
//   0x14f3c4: A9075FF8  stp      x24, x23, [sp, #0x70]
//   0x14f3c8: A90857F6  stp      x22, x21, [sp, #0x80]
//   0x14f3cc: A9094FF4  stp      x20, x19, [sp, #0x90]
//   0x14f3d0: A90A7BFD  stp      x29, x30, [sp, #0xa0]
//   0x14f3d4: 910283FD  add      x29, sp, #0xa0
uint64_t fde_func_3671_0x14f3c0(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0014F3C0ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD102C3FFULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9075FF8ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90857F6ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9094FF4ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90A7BFDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910283FDULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD53BD057ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF94016E8ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #3675 | PC: 0x150058..0x15009c (68 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x150058: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x15005c: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x150060: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x150064: 910083FD  add      x29, sp, #0x20
//   0x150068: 91003015  add      x21, x0, #0xc
//   0x15006c: AA0003F4  mov      x20, x0
uint64_t fde_func_3675_0x150058(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00150058ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81D0FF5ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9014FF4ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9027BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910083FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91003015ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F4ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA1503E0ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0103F3ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #3680 | PC: 0x1506b8..0x150764 (172 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x1506b8: D10183FF  sub      sp, sp, #0x60
//   0x1506bc: A90357F6  stp      x22, x21, [sp, #0x30]
//   0x1506c0: A9044FF4  stp      x20, x19, [sp, #0x40]
//   0x1506c4: A9057BFD  stp      x29, x30, [sp, #0x50]
//   0x1506c8: 910143FD  add      x29, sp, #0x50
//   0x1506cc: D53BD055  mrs      x21, tpidr_el0
uint64_t fde_func_3680_0x1506b8(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x001506B8ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10183FFULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90357F6ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9044FF4ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9057BFDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910143FDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD53BD055ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF94016A8ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF90017E8ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #3684 | PC: 0x1507f8..0x1508e4 (236 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x1507f8: D10183FF  sub      sp, sp, #0x60
//   0x1507fc: A90167FA  stp      x26, x25, [sp, #0x10]
//   0x150800: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x150804: A90357F6  stp      x22, x21, [sp, #0x30]
//   0x150808: A9044FF4  stp      x20, x19, [sp, #0x40]
//   0x15080c: A9057BFD  stp      x29, x30, [sp, #0x50]
uint64_t fde_func_3684_0x1507f8(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x001507F8ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10183FFULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90167FAULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9025FF8ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90357F6ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9044FF4ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9057BFDULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910143FDULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD53BD05AULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #3689 | PC: 0x150cd0..0x150d40 (112 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x150cd0: A9402808  ldp      x8, x10, [x0]
//   0x150cd4: EB08015F  cmp      x10, x8
//   0x150cd8: 54000180  b.eq     #0x150d08
//   0x150cdc: F9400429  ldr      x9, [x1, #8]
//   0x150ce0: 3CDF0D40  ldr      q0, [x10, #-0x10]!
//   0x150ce4: 3C9F0120  stur     q0, [x9, #-0x10]
uint64_t fde_func_3689_0x150cd0(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00150CD0ULL);
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

// FDE #3693 | PC: 0x150df8..0x150e04 (12 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x150df8: F8418C08  ldr      x8, [x0, #0x18]!
//   0x150dfc: F9400101  ldr      x1, [x8]
//   0x150e00: D61F0020  br       x1
uint64_t fde_func_3693_0x150df8(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00150DF8ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF8418C08ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400101ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD61F0020ULL ^ (2ULL << 32);
    return state ^ (state >> 29);
}

// FDE #3698 | PC: 0x15160c..0x15170c (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x15160c: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x151610: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x151614: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x151618: 910083FD  add      x29, sp, #0x20
//   0x15161c: 91008013  add      x19, x0, #0x20
//   0x151620: AA0003F4  mov      x20, x0
uint64_t fde_func_3698_0x15160c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0015160CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BD57F6ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9014FF4ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9027BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910083FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91008013ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F4ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA1303E0ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0803F5ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #3702 | PC: 0x151aac..0x151afc (80 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x151aac: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x151ab0: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x151ab4: 910043FD  add      x29, sp, #0x10
//   0x151ab8: D00010E8  adrp     x8, #0x36f000
//   0x151abc: 912DA108  add      x8, x8, #0xb68
//   0x151ac0: AA0003F3  mov      x19, x0
uint64_t fde_func_3702_0x151aac(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00151AACULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81E0FF3ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD00010E8ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x912DA108ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF8068408ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x94000329ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #3707 | PC: 0x151e0c..0x151e14 (8 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x151e0c: 12800002  mov      w2, #-1
//   0x151e10: 14000001  b        #0x151e14
uint64_t fde_func_3707_0x151e0c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00151E0CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0x12800002ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x14000001ULL ^ (1ULL << 32);
    return state ^ (state >> 29);
}

// FDE #3711 | PC: 0x151f18..0x151fc0 (168 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x151f18: D101C3FF  sub      sp, sp, #0x70
//   0x151f1c: A9035FF8  stp      x24, x23, [sp, #0x30]
//   0x151f20: A90457F6  stp      x22, x21, [sp, #0x40]
//   0x151f24: A9054FF4  stp      x20, x19, [sp, #0x50]
//   0x151f28: A9067BFD  stp      x29, x30, [sp, #0x60]
//   0x151f2c: 910183FD  add      x29, sp, #0x60
uint64_t fde_func_3711_0x151f18(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00151F18ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD101C3FFULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9035FF8ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90457F6ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9054FF4ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9067BFDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910183FDULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD53BD058ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0803F7ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #3716 | PC: 0x152108..0x1521a8 (160 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x152108: D10183FF  sub      sp, sp, #0x60
//   0x15210c: F90013F7  str      x23, [sp, #0x20]
//   0x152110: A90357F6  stp      x22, x21, [sp, #0x30]
//   0x152114: A9044FF4  stp      x20, x19, [sp, #0x40]
//   0x152118: A9057BFD  stp      x29, x30, [sp, #0x50]
//   0x15211c: 910143FD  add      x29, sp, #0x50
uint64_t fde_func_3716_0x152108(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00152108ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10183FFULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF90013F7ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90357F6ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9044FF4ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9057BFDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910143FDULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD53BD057ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0803F6ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #3720 | PC: 0x1522fc..0x15232c (48 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x1522fc: 7100041F  cmp      w0, #1
//   0x152300: 5400014B  b.lt     #0x152328
//   0x152304: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x152308: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x15230c: 910043FD  add      x29, sp, #0x10
//   0x152310: 2A0003F3  mov      w19, w0
uint64_t fde_func_3720_0x1522fc(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x001522FCULL);
    state = (state * 0x00000100000001B3ULL) ^ 0x7100041FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x5400014BULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81E0FF3ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x2A0003F3ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x97FFFE97ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91002008ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #3725 | PC: 0x152748..0x15276c (36 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x152748: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x15274c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x152750: 910043FD  add      x29, sp, #0x10
//   0x152754: AA0003F3  mov      x19, x0
//   0x152758: 97FFFCD5  bl       #0x151aac
//   0x15275c: A9417BFD  ldp      x29, x30, [sp, #0x10]
uint64_t fde_func_3725_0x152748(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00152748ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81E0FF3ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x97FFFCD5ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9417BFDULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA1303E0ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF84207F3ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #3729 | PC: 0x1527f4..0x152810 (28 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x1527f4: F9400428  ldr      x8, [x1, #8]
//   0x1527f8: D0000C49  adrp     x9, #0x2dc000
//   0x1527fc: 9100D129  add      x9, x9, #0x34
//   0x152800: 9100800A  add      x10, x0, #0x20
//   0x152804: EB09011F  cmp      x8, x9
//   0x152808: 9A9F0140  csel     x0, x10, xzr, eq
uint64_t fde_func_3729_0x1527f4(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x001527F4ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400428ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD0000C49ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9100D129ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9100800AULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xEB09011FULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9A9F0140ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD65F03C0ULL ^ (6ULL << 32);
    return state ^ (state >> 29);
}

// FDE #3734 | PC: 0x152860..0x152864 (4 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x152860: 17FBC6B4  b        #0x44330
uint64_t fde_func_3734_0x152860(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00152860ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0x17FBC6B4ULL ^ (0ULL << 32);
    return state ^ (state >> 29);
}

// FDE #3738 | PC: 0x1528d4..0x1528d8 (4 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x1528d4: 17FBC697  b        #0x44330
uint64_t fde_func_3738_0x1528d4(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x001528D4ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0x17FBC697ULL ^ (0ULL << 32);
    return state ^ (state >> 29);
}

// FDE #3743 | PC: 0x152d18..0x152dfc (228 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x152d18: D10183FF  sub      sp, sp, #0x60
//   0x152d1c: F9000BF9  str      x25, [sp, #0x10]
//   0x152d20: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x152d24: A90357F6  stp      x22, x21, [sp, #0x30]
//   0x152d28: A9044FF4  stp      x20, x19, [sp, #0x40]
//   0x152d2c: A9057BFD  stp      x29, x30, [sp, #0x50]
uint64_t fde_func_3743_0x152d18(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00152D18ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10183FFULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF9ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9025FF8ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90357F6ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9044FF4ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9057BFDULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910143FDULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD53BD059ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #3747 | PC: 0x153470..0x1534d0 (96 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x153470: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x153474: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x153478: 910043FD  add      x29, sp, #0x10
//   0x15347c: 900010E8  adrp     x8, #0x36f000
//   0x153480: 91326108  add      x8, x8, #0xc98
//   0x153484: 91010014  add      x20, x0, #0x40
uint64_t fde_func_3747_0x153470(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00153470ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE4FF4ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x900010E8ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91326108ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91010014ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000008ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #3752 | PC: 0x1535a4..0x153624 (128 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x1535a4: D10103FF  sub      sp, sp, #0x40
//   0x1535a8: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x1535ac: A9037BFD  stp      x29, x30, [sp, #0x30]
//   0x1535b0: 9100C3FD  add      x29, sp, #0x30
//   0x1535b4: D53BD054  mrs      x20, tpidr_el0
//   0x1535b8: F9401688  ldr      x8, [x20, #0x28]
uint64_t fde_func_3752_0x1535a4(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x001535A4ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10103FFULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9024FF4ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9037BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9100C3FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD53BD054ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9401688ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB0000B81ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #3756 | PC: 0x1536ec..0x153740 (84 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x1536ec: D10103FF  sub      sp, sp, #0x40
//   0x1536f0: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x1536f4: A9037BFD  stp      x29, x30, [sp, #0x30]
//   0x1536f8: 9100C3FD  add      x29, sp, #0x30
//   0x1536fc: D53BD054  mrs      x20, tpidr_el0
//   0x153700: AA0803F3  mov      x19, x8
uint64_t fde_func_3756_0x1536ec(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x001536ECULL);
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

// FDE #3760 | PC: 0x1537fc..0x1538fc (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x1537fc: D101C3FF  sub      sp, sp, #0x70
//   0x153800: F90023F5  str      x21, [sp, #0x40]
//   0x153804: A9054FF4  stp      x20, x19, [sp, #0x50]
//   0x153808: A9067BFD  stp      x29, x30, [sp, #0x60]
//   0x15380c: 910183FD  add      x29, sp, #0x60
//   0x153810: D53BD055  mrs      x21, tpidr_el0
uint64_t fde_func_3760_0x1537fc(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x001537FCULL);
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

// FDE #3765 | PC: 0x153bc4..0x153bd8 (20 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x153bc4: B0001168  adrp     x8, #0x380000
//   0x153bc8: 912AC108  add      x8, x8, #0xab0
//   0x153bcc: AA0003E1  mov      x1, x0
//   0x153bd0: AA0803E0  mov      x0, x8
//   0x153bd4: 14000001  b        #0x153bd8
uint64_t fde_func_3765_0x153bc4(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00153BC4ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xB0001168ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x912AC108ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003E1ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0803E0ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x14000001ULL ^ (4ULL << 32);
    return state ^ (state >> 29);
}

// FDE #3769 | PC: 0x153cb8..0x153d14 (92 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x153cb8: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x153cbc: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x153cc0: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x153cc4: 910083FD  add      x29, sp, #0x20
//   0x153cc8: 52800D00  mov      w0, #0x68
//   0x153ccc: AA0803F3  mov      x19, x8
uint64_t fde_func_3769_0x153cb8(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00153CB8ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81D0FF5ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9014FF4ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9027BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910083FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x52800D00ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0803F3ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x97FBC100ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x900010E8ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #3774 | PC: 0x153e38..0x153e3c (4 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x153e38: 17FBC13E  b        #0x44330
uint64_t fde_func_3774_0x153e38(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00153E38ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0x17FBC13EULL ^ (0ULL << 32);
    return state ^ (state >> 29);
}

// FDE #3778 | PC: 0x153f78..0x153fb0 (56 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x153f78: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x153f7c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x153f80: 910043FD  add      x29, sp, #0x10
//   0x153f84: 900010E8  adrp     x8, #0x36f000
//   0x153f88: 91386108  add      x8, x8, #0xe18
//   0x153f8c: AA0003F3  mov      x19, x0
uint64_t fde_func_3778_0x153f78(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00153F78ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81E0FF3ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x900010E8ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91386108ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF8018408ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x97FFFD37ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #3783 | PC: 0x1540cc..0x1540fc (48 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x1540cc: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x1540d0: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x1540d4: 910043FD  add      x29, sp, #0x10
//   0x1540d8: F00010C8  adrp     x8, #0x36f000
//   0x1540dc: 9139A108  add      x8, x8, #0xe68
//   0x1540e0: AA0003F3  mov      x19, x0
uint64_t fde_func_3783_0x1540cc(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x001540CCULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81E0FF3ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF00010C8ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9139A108ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF8018408ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x97FFFCE2ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #3787 | PC: 0x154144..0x154244 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x154144: D10503FF  sub      sp, sp, #0x140
//   0x154148: A90E6FFC  stp      x28, x27, [sp, #0xe0]
//   0x15414c: A90F67FA  stp      x26, x25, [sp, #0xf0]
//   0x154150: A9105FF8  stp      x24, x23, [sp, #0x100]
//   0x154154: A91157F6  stp      x22, x21, [sp, #0x110]
//   0x154158: A9124FF4  stp      x20, x19, [sp, #0x120]
uint64_t fde_func_3787_0x154144(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00154144ULL);
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

// FDE #3792 | PC: 0x154658..0x1546b8 (96 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x154658: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x15465c: 910003FD  mov      x29, sp
//   0x154660: F9400400  ldr      x0, [x0, #8]
//   0x154664: B40000C0  cbz      x0, #0x15467c
//   0x154668: F9400008  ldr      x8, [x0]
//   0x15466c: F9400042  ldr      x2, [x2]
uint64_t fde_func_3792_0x154658(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00154658ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BF7BFDULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400400ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB40000C0ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400008ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400042ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9401103ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA8C17BFDULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #3796 | PC: 0x154754..0x154758 (4 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x154754: D4200020  brk      #1
uint64_t fde_func_3796_0x154754(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00154754ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD4200020ULL ^ (0ULL << 32);
    return state ^ (state >> 29);
}

// FDE #3801 | PC: 0x154810..0x154834 (36 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x154810: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x154814: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x154818: 910043FD  add      x29, sp, #0x10
//   0x15481c: AA0003F3  mov      x19, x0
//   0x154820: 97FE4199  bl       #0xe4e84
//   0x154824: A9417BFD  ldp      x29, x30, [sp, #0x10]
uint64_t fde_func_3801_0x154810(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00154810ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81E0FF3ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x97FE4199ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9417BFDULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA1303E0ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF84207F3ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #3805 | PC: 0x1548a4..0x1548a8 (4 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x1548a4: 17FBBEA3  b        #0x44330
uint64_t fde_func_3805_0x1548a4(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x001548A4ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0x17FBBEA3ULL ^ (0ULL << 32);
    return state ^ (state >> 29);
}

// FDE #3810 | PC: 0x154a30..0x154a38 (8 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x154a30: 91004000  add      x0, x0, #0x10
//   0x154a34: 14000023  b        #0x154ac0
uint64_t fde_func_3810_0x154a30(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00154A30ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0x91004000ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x14000023ULL ^ (1ULL << 32);
    return state ^ (state >> 29);
}

// FDE #3814 | PC: 0x154ab4..0x154ac0 (12 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x154ab4: 900010E0  adrp     x0, #0x370000
//   0x154ab8: 91018000  add      x0, x0, #0x60
//   0x154abc: D65F03C0  ret      
uint64_t fde_func_3814_0x154ab4(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00154AB4ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0x900010E0ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91018000ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD65F03C0ULL ^ (2ULL << 32);
    return state ^ (state >> 29);
}

// FDE #3819 | PC: 0x154b68..0x154b6c (4 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x154b68: D65F03C0  ret      
uint64_t fde_func_3819_0x154b68(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00154B68ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD65F03C0ULL ^ (0ULL << 32);
    return state ^ (state >> 29);
}

// FDE #3823 | PC: 0x154bc8..0x154bd4 (12 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x154bc8: 900010E0  adrp     x0, #0x370000
//   0x154bcc: 91038000  add      x0, x0, #0xe0
//   0x154bd0: D65F03C0  ret      
uint64_t fde_func_3823_0x154bc8(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00154BC8ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0x900010E0ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91038000ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD65F03C0ULL ^ (2ULL << 32);
    return state ^ (state >> 29);
}

// FDE #3828 | PC: 0x154c94..0x154cd4 (64 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x154c94: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x154c98: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x154c9c: 910043FD  add      x29, sp, #0x10
//   0x154ca0: 900010E8  adrp     x8, #0x370000
//   0x154ca4: 91040108  add      x8, x8, #0x100
//   0x154ca8: 91012109  add      x9, x8, #0x48
uint64_t fde_func_3828_0x154c94(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00154C94ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81E0FF3ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x900010E8ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91040108ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91012109ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9E670100ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #3832 | PC: 0x154ce8..0x154cf0 (8 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x154ce8: F9002401  str      x1, [x0, #0x48]
//   0x154cec: D65F03C0  ret      
uint64_t fde_func_3832_0x154ce8(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00154CE8ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9002401ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD65F03C0ULL ^ (1ULL << 32);
    return state ^ (state >> 29);
}

// FDE #3836 | PC: 0x154d78..0x154db4 (60 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x154d78: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x154d7c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x154d80: 910043FD  add      x29, sp, #0x10
//   0x154d84: 900010E8  adrp     x8, #0x370000
//   0x154d88: 91074108  add      x8, x8, #0x1d0
//   0x154d8c: 91004009  add      x9, x0, #0x10
uint64_t fde_func_3836_0x154d78(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00154D78ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81E0FF3ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x900010E8ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91074108ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91004009ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9007C08ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #3841 | PC: 0x154ecc..0x154ee0 (20 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x154ecc: F9400028  ldr      x8, [x1]
//   0x154ed0: B4000068  cbz      x8, #0x154edc
//   0x154ed4: 91004000  add      x0, x0, #0x10
//   0x154ed8: 17FFFFD1  b        #0x154e1c
//   0x154edc: D65F03C0  ret      
uint64_t fde_func_3841_0x154ecc(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00154ECCULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400028ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB4000068ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91004000ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x17FFFFD1ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD65F03C0ULL ^ (4ULL << 32);
    return state ^ (state >> 29);
}

// FDE #3845 | PC: 0x154fe0..0x155018 (56 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x154fe0: F9401009  ldr      x9, [x0, #0x20]
//   0x154fe4: B4000169  cbz      x9, #0x155010
//   0x154fe8: F9400C09  ldr      x9, [x0, #0x18]
//   0x154fec: A941252A  ldp      x10, x9, [x9, #0x10]
//   0x154ff0: A900250A  stp      x10, x9, [x8]
//   0x154ff4: B40000C9  cbz      x9, #0x15500c
uint64_t fde_func_3845_0x154fe0(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00154FE0ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9401009ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB4000169ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400C09ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA941252AULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA900250AULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB40000C9ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91002128ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xC85F7D09ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #3850 | PC: 0x155294..0x1552dc (72 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x155294: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x155298: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x15529c: 910043FD  add      x29, sp, #0x10
//   0x1552a0: F00010C8  adrp     x8, #0x370000
//   0x1552a4: 9107E108  add      x8, x8, #0x1f8
//   0x1552a8: AA0003F4  mov      x20, x0
uint64_t fde_func_3850_0x155294(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00155294ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE4FF4ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF00010C8ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9107E108ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F4ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF8008408ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x2A0103F3ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #3854 | PC: 0x155364..0x15536c (8 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x155364: B9404000  ldr      w0, [x0, #0x40]
//   0x155368: D65F03C0  ret      
uint64_t fde_func_3854_0x155364(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00155364ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xB9404000ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD65F03C0ULL ^ (1ULL << 32);
    return state ^ (state >> 29);
}

// FDE #3859 | PC: 0x1555bc..0x1555e0 (36 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x1555bc: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x1555c0: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x1555c4: 910043FD  add      x29, sp, #0x10
//   0x1555c8: AA0003F3  mov      x19, x0
//   0x1555cc: 97FFFFE6  bl       #0x155564
//   0x1555d0: A9417BFD  ldp      x29, x30, [sp, #0x10]
uint64_t fde_func_3859_0x1555bc(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x001555BCULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81E0FF3ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x97FFFFE6ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9417BFDULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA1303E0ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF84207F3ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #3863 | PC: 0x15590c..0x155964 (88 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x15590c: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x155910: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x155914: 910043FD  add      x29, sp, #0x10
//   0x155918: 39422008  ldrb     w8, [x0, #0x88]
//   0x15591c: F00010C9  adrp     x9, #0x370000
//   0x155920: AA0003F3  mov      x19, x0
uint64_t fde_func_3863_0x15590c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0015590CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81E0FF3ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x39422008ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF00010C9ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91096129ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000009ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #3868 | PC: 0x155cf0..0x155d7c (140 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x155cf0: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x155cf4: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x155cf8: 910043FD  add      x29, sp, #0x10
//   0x155cfc: 39456008  ldrb     w8, [x0, #0x158]
//   0x155d00: F00010C9  adrp     x9, #0x370000
//   0x155d04: AA0003F3  mov      x19, x0
uint64_t fde_func_3868_0x155cf0(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00155CF0ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81E0FF3ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x39456008ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF00010C9ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910A2129ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000009ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #3872 | PC: 0x156104..0x15615c (88 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x156104: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x156108: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x15610c: 910043FD  add      x29, sp, #0x10
//   0x156110: D00010C8  adrp     x8, #0x370000
//   0x156114: 9107E108  add      x8, x8, #0x1f8
//   0x156118: AA0003F3  mov      x19, x0
uint64_t fde_func_3872_0x156104(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00156104ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81E0FF3ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD00010C8ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9107E108ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF8008408ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x97FBD803ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #3877 | PC: 0x156374..0x1563e4 (112 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x156374: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x156378: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x15637c: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x156380: 910083FD  add      x29, sp, #0x20
//   0x156384: F9400808  ldr      x8, [x0, #0x10]
//   0x156388: B4000268  cbz      x8, #0x1563d4
uint64_t fde_func_3877_0x156374(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00156374ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81D0FF5ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9014FF4ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9027BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910083FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400808ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB4000268ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9405008ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #3881 | PC: 0x156708..0x156808 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x156708: D103C3FF  sub      sp, sp, #0xf0
//   0x15670c: A9096FFC  stp      x28, x27, [sp, #0x90]
//   0x156710: A90A67FA  stp      x26, x25, [sp, #0xa0]
//   0x156714: A90B5FF8  stp      x24, x23, [sp, #0xb0]
//   0x156718: A90C57F6  stp      x22, x21, [sp, #0xc0]
//   0x15671c: A90D4FF4  stp      x20, x19, [sp, #0xd0]
uint64_t fde_func_3881_0x156708(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00156708ULL);
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

// FDE #3886 | PC: 0x156c78..0x156d78 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x156c78: D10283FF  sub      sp, sp, #0xa0
//   0x156c7c: A9046FFC  stp      x28, x27, [sp, #0x40]
//   0x156c80: A90567FA  stp      x26, x25, [sp, #0x50]
//   0x156c84: A9065FF8  stp      x24, x23, [sp, #0x60]
//   0x156c88: A90757F6  stp      x22, x21, [sp, #0x70]
//   0x156c8c: A9084FF4  stp      x20, x19, [sp, #0x80]
uint64_t fde_func_3886_0x156c78(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00156C78ULL);
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

// FDE #3890 | PC: 0x1570b8..0x1571b4 (252 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x1570b8: D101C3FF  sub      sp, sp, #0x70
//   0x1570bc: F9000BFB  str      x27, [sp, #0x10]
//   0x1570c0: A90267FA  stp      x26, x25, [sp, #0x20]
//   0x1570c4: A9035FF8  stp      x24, x23, [sp, #0x30]
//   0x1570c8: A90457F6  stp      x22, x21, [sp, #0x40]
//   0x1570cc: A9054FF4  stp      x20, x19, [sp, #0x50]
uint64_t fde_func_3890_0x1570b8(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x001570B8ULL);
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

// FDE #3895 | PC: 0x157478..0x1574cc (84 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x157478: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x15747c: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x157480: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x157484: 910083FD  add      x29, sp, #0x20
//   0x157488: F9402014  ldr      x20, [x0, #0x40]
//   0x15748c: 9100E015  add      x21, x0, #0x38
uint64_t fde_func_3895_0x157478(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00157478ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81D0FF5ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9014FF4ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9027BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910083FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9402014ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9100E015ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xEB1402BFULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x54000140ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #3899 | PC: 0x157678..0x157680 (8 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x157678: D1008000  sub      x0, x0, #0x20
//   0x15767c: 17FFFFBE  b        #0x157574
uint64_t fde_func_3899_0x157678(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00157678ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD1008000ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x17FFFFBEULL ^ (1ULL << 32);
    return state ^ (state >> 29);
}

// FDE #3904 | PC: 0x1576d8..0x1576dc (4 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x1576d8: 17FBB316  b        #0x44330
uint64_t fde_func_3904_0x1576d8(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x001576D8ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0x17FBB316ULL ^ (0ULL << 32);
    return state ^ (state >> 29);
}

// FDE #3908 | PC: 0x157730..0x157734 (4 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x157730: 17FBB300  b        #0x44330
uint64_t fde_func_3908_0x157730(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00157730ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0x17FBB300ULL ^ (0ULL << 32);
    return state ^ (state >> 29);
}

// FDE #3913 | PC: 0x157904..0x157908 (4 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x157904: 17FBB28B  b        #0x44330
uint64_t fde_func_3913_0x157904(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00157904ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0x17FBB28BULL ^ (0ULL << 32);
    return state ^ (state >> 29);
}

// FDE #3917 | PC: 0x15795c..0x157960 (4 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x15795c: 17FBB275  b        #0x44330
uint64_t fde_func_3917_0x15795c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0015795CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0x17FBB275ULL ^ (0ULL << 32);
    return state ^ (state >> 29);
}

// FDE #3921 | PC: 0x1579d4..0x157ad4 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x1579d4: D102C3FF  sub      sp, sp, #0xb0
//   0x1579d8: A9056FFC  stp      x28, x27, [sp, #0x50]
//   0x1579dc: A90667FA  stp      x26, x25, [sp, #0x60]
//   0x1579e0: A9075FF8  stp      x24, x23, [sp, #0x70]
//   0x1579e4: A90857F6  stp      x22, x21, [sp, #0x80]
//   0x1579e8: A9094FF4  stp      x20, x19, [sp, #0x90]
uint64_t fde_func_3921_0x1579d4(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x001579D4ULL);
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

// FDE #3926 | PC: 0x158c14..0x158cbc (168 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x158c14: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x158c18: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x158c1c: 910043FD  add      x29, sp, #0x10
//   0x158c20: F0001128  adrp     x8, #0x37f000
//   0x158c24: F9468108  ldr      x8, [x8, #0xd00]
//   0x158c28: AA0003F3  mov      x19, x0
uint64_t fde_func_3926_0x158c14(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00158C14ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE4FF4ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF0001128ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9468108ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91004109ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91010108ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #3930 | PC: 0x158dd4..0x158e20 (76 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x158dd4: B4000241  cbz      x1, #0x158e1c
//   0x158dd8: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x158ddc: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x158de0: 910043FD  add      x29, sp, #0x10
//   0x158de4: AA0103F3  mov      x19, x1
//   0x158de8: F9400021  ldr      x1, [x1]
uint64_t fde_func_3930_0x158dd4(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00158DD4ULL);
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

// FDE #3935 | PC: 0x158ffc..0x15902c (48 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x158ffc: A940A009  ldp      x9, x8, [x0, #8]
//   0x159000: EB090109  subs     x9, x8, x9
//   0x159004: 540000C0  b.eq     #0x15901c
//   0x159008: D1002129  sub      x9, x9, #8
//   0x15900c: 9280000A  mov      x10, #-1
//   0x159010: CA490D49  eor      x9, x10, x9, lsr #3
uint64_t fde_func_3935_0x158ffc(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00158FFCULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xA940A009ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xEB090109ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x540000C0ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD1002129ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9280000AULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xCA490D49ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x8B090D08ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000808ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #3939 | PC: 0x15933c..0x15943c (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x15933c: D10203FF  sub      sp, sp, #0x80
//   0x159340: A9026FFC  stp      x28, x27, [sp, #0x20]
//   0x159344: A90367FA  stp      x26, x25, [sp, #0x30]
//   0x159348: A9045FF8  stp      x24, x23, [sp, #0x40]
//   0x15934c: A90557F6  stp      x22, x21, [sp, #0x50]
//   0x159350: A9064FF4  stp      x20, x19, [sp, #0x60]
uint64_t fde_func_3939_0x15933c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0015933CULL);
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

// FDE #3944 | PC: 0x159814..0x1598e8 (212 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x159814: D10143FF  sub      sp, sp, #0x50
//   0x159818: A9015FF8  stp      x24, x23, [sp, #0x10]
//   0x15981c: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x159820: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x159824: A9047BFD  stp      x29, x30, [sp, #0x40]
//   0x159828: 910103FD  add      x29, sp, #0x40
uint64_t fde_func_3944_0x159814(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00159814ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10143FFULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9015FF8ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90257F6ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9034FF4ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9047BFDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910103FDULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD53BD058ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9401708ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #3948 | PC: 0x15995c..0x159960 (4 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x15995c: 17FBAA75  b        #0x44330
uint64_t fde_func_3948_0x15995c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0015995CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0x17FBAA75ULL ^ (0ULL << 32);
    return state ^ (state >> 29);
}

// FDE #3953 | PC: 0x1599d8..0x159a6c (148 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x1599d8: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x1599dc: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x1599e0: 910043FD  add      x29, sp, #0x10
//   0x1599e4: F00010A8  adrp     x8, #0x370000
//   0x1599e8: 9118C108  add      x8, x8, #0x630
//   0x1599ec: 9100E109  add      x9, x8, #0x38
uint64_t fde_func_3953_0x1599d8(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x001599D8ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE4FF4ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF00010A8ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9118C108ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9100E109ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9E670100ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #3957 | PC: 0x159b24..0x159b2c (8 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x159b24: D1002000  sub      x0, x0, #8
//   0x159b28: 17FFFFAC  b        #0x1599d8
uint64_t fde_func_3957_0x159b24(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00159B24ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD1002000ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x17FFFFACULL ^ (1ULL << 32);
    return state ^ (state >> 29);
}

// FDE #3962 | PC: 0x159bf8..0x159c88 (144 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x159bf8: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x159bfc: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x159c00: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x159c04: 910083FD  add      x29, sp, #0x20
//   0x159c08: F9401814  ldr      x20, [x0, #0x30]
//   0x159c0c: 9100A016  add      x22, x0, #0x28
uint64_t fde_func_3962_0x159bf8(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00159BF8ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BD57F6ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9014FF4ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9027BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910083FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9401814ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9100A016ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F5ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x2A0103F3ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #3966 | PC: 0x159d78..0x159ddc (100 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x159d78: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x159d7c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x159d80: 910043FD  add      x29, sp, #0x10
//   0x159d84: A9402428  ldp      x8, x9, [x1]
//   0x159d88: A9007C3F  stp      xzr, xzr, [x1]
//   0x159d8c: F9404013  ldr      x19, [x0, #0x80]
uint64_t fde_func_3966_0x159d78(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00159D78ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81E0FF3ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9402428ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9007C3FULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9404013ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA907A408ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB40000F3ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #3971 | PC: 0x159fc8..0x15a0c8 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x159fc8: F81C0FF7  str      x23, [sp, #-0x40]!
//   0x159fcc: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x159fd0: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x159fd4: A9037BFD  stp      x29, x30, [sp, #0x30]
//   0x159fd8: 9100C3FD  add      x29, sp, #0x30
//   0x159fdc: B9402008  ldr      w8, [x0, #0x20]
uint64_t fde_func_3971_0x159fc8(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00159FC8ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81C0FF7ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90157F6ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9024FF4ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9037BFDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9100C3FDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB9402008ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x71000D1FULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x54000980ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #3975 | PC: 0x15a260..0x15a2a4 (68 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x15a260: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x15a264: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x15a268: 910043FD  add      x29, sp, #0x10
//   0x15a26c: AA0103F4  mov      x20, x1
//   0x15a270: 52800101  mov      w1, #8
//   0x15a274: 2A0203F3  mov      w19, w2
uint64_t fde_func_3975_0x15a260(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0015A260ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE4FF4ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0103F4ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x52800101ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x2A0203F3ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x97FFFE60ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB40000C0ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #3980 | PC: 0x15a3a0..0x15a3c8 (40 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x15a3a0: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x15a3a4: 910003FD  mov      x29, sp
//   0x15a3a8: 52800101  mov      w1, #8
//   0x15a3ac: 97FFFE13  bl       #0x159bf8
//   0x15a3b0: B4000060  cbz      x0, #0x15a3bc
//   0x15a3b4: A8C17BFD  ldp      x29, x30, [sp], #0x10
uint64_t fde_func_3980_0x15a3a0(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0015A3A0ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BF7BFDULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x52800101ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x97FFFE13ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB4000060ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA8C17BFDULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x14014728ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x92800000ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #3984 | PC: 0x15a940..0x15a97c (60 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x15a940: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x15a944: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x15a948: 910043FD  add      x29, sp, #0x10
//   0x15a94c: 52800801  mov      w1, #0x40
//   0x15a950: AA0803F3  mov      x19, x8
//   0x15a954: 97FFFCA9  bl       #0x159bf8
uint64_t fde_func_3984_0x15a940(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0015A940ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81E0FF3ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x52800801ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0803F3ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x97FFFCA9ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB40000A0ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9417BFDULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #3989 | PC: 0x15aac4..0x15ab1c (88 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x15aac4: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x15aac8: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x15aacc: 910043FD  add      x29, sp, #0x10
//   0x15aad0: F9400413  ldr      x19, [x0, #8]
//   0x15aad4: B40000F3  cbz      x19, #0x15aaf0
//   0x15aad8: 91002268  add      x8, x19, #8
uint64_t fde_func_3989_0x15aac4(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0015AAC4ULL);
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

// FDE #3993 | PC: 0x15ac38..0x15ac40 (8 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x15ac38: D1002000  sub      x0, x0, #8
//   0x15ac3c: 17FFFFE1  b        #0x15abc0
uint64_t fde_func_3993_0x15ac38(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0015AC38ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD1002000ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x17FFFFE1ULL ^ (1ULL << 32);
    return state ^ (state >> 29);
}

// FDE #3997 | PC: 0x15aca4..0x15acbc (24 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x15aca4: B9401808  ldr      w8, [x0, #0x18]
//   0x15aca8: 7100051F  cmp      w8, #1
//   0x15acac: 54000060  b.eq     #0x15acb8
//   0x15acb0: 52800028  mov      w8, #1
//   0x15acb4: B9001808  str      w8, [x0, #0x18]
//   0x15acb8: D65F03C0  ret      
uint64_t fde_func_3997_0x15aca4(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0015ACA4ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xB9401808ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x7100051FULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x54000060ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x52800028ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB9001808ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD65F03C0ULL ^ (5ULL << 32);
    return state ^ (state >> 29);
}

// FDE #4002 | PC: 0x15adf0..0x15ae10 (32 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x15adf0: 9100E000  add      x0, x0, #0x38
//   0x15adf4: EB01001F  cmp      x0, x1
//   0x15adf8: 540000A0  b.eq     #0x15ae0c
//   0x15adfc: AA0103E2  mov      x2, x1
//   0x15ae00: F9400421  ldr      x1, [x1, #8]
//   0x15ae04: AA1F03E3  mov      x3, xzr
uint64_t fde_func_4002_0x15adf0(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0015ADF0ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0x9100E000ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xEB01001FULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x540000A0ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0103E2ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400421ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA1F03E3ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x14000002ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD65F03C0ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #4006 | PC: 0x15afa8..0x15b0a8 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x15afa8: D10243FF  sub      sp, sp, #0x90
//   0x15afac: F9002BF7  str      x23, [sp, #0x50]
//   0x15afb0: A90657F6  stp      x22, x21, [sp, #0x60]
//   0x15afb4: A9074FF4  stp      x20, x19, [sp, #0x70]
//   0x15afb8: A9087BFD  stp      x29, x30, [sp, #0x80]
//   0x15afbc: 910203FD  add      x29, sp, #0x80
uint64_t fde_func_4006_0x15afa8(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0015AFA8ULL);
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

// FDE #4011 | PC: 0x15b914..0x15b968 (84 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x15b914: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x15b918: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x15b91c: 910043FD  add      x29, sp, #0x10
//   0x15b920: AA0203E3  mov      x3, x2
//   0x15b924: AA0103E2  mov      x2, x1
//   0x15b928: 52800021  mov      w1, #1
uint64_t fde_func_4011_0x15b914(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0015B914ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81E0FF3ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0203E3ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0103E2ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x52800021ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x97FFE4A9ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #4015 | PC: 0x15ba04..0x15ba2c (40 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x15ba04: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x15ba08: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x15ba0c: 910043FD  add      x29, sp, #0x10
//   0x15ba10: D1002013  sub      x19, x0, #8
//   0x15ba14: AA1303E0  mov      x0, x19
//   0x15ba18: 97FFFFD4  bl       #0x15b968
uint64_t fde_func_4015_0x15ba04(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0015BA04ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81E0FF3ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD1002013ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA1303E0ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x97FFFFD4ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9417BFDULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA1303E0ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #4020 | PC: 0x15e02c..0x15e12c (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x15e02c: D102C3FF  sub      sp, sp, #0xb0
//   0x15e030: A9075FF8  stp      x24, x23, [sp, #0x70]
//   0x15e034: A90857F6  stp      x22, x21, [sp, #0x80]
//   0x15e038: A9094FF4  stp      x20, x19, [sp, #0x90]
//   0x15e03c: A90A7BFD  stp      x29, x30, [sp, #0xa0]
//   0x15e040: 910283FD  add      x29, sp, #0xa0
uint64_t fde_func_4020_0x15e02c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0015E02CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD102C3FFULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9075FF8ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90857F6ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9094FF4ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90A7BFDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910283FDULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD53BD057ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF94016E8ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #4024 | PC: 0x15ee70..0x15eec8 (88 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x15ee70: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x15ee74: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x15ee78: 910043FD  add      x29, sp, #0x10
//   0x15ee7c: F9400413  ldr      x19, [x0, #8]
//   0x15ee80: B40000F3  cbz      x19, #0x15ee9c
//   0x15ee84: 91002268  add      x8, x19, #8
uint64_t fde_func_4024_0x15ee70(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0015EE70ULL);
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

// FDE #4029 | PC: 0x15fd0c..0x15fe0c (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x15fd0c: D10243FF  sub      sp, sp, #0x90
//   0x15fd10: F90033F5  str      x21, [sp, #0x60]
//   0x15fd14: A9074FF4  stp      x20, x19, [sp, #0x70]
//   0x15fd18: A9087BFD  stp      x29, x30, [sp, #0x80]
//   0x15fd1c: 910203FD  add      x29, sp, #0x80
//   0x15fd20: D53BD055  mrs      x21, tpidr_el0
uint64_t fde_func_4029_0x15fd0c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0015FD0CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10243FFULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF90033F5ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9074FF4ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9087BFDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910203FDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD53BD055ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF94016A8ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81D83A8ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #4033 | PC: 0x15ff68..0x15ff98 (48 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x15ff68: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x15ff6c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x15ff70: 910043FD  add      x29, sp, #0x10
//   0x15ff74: B0001088  adrp     x8, #0x370000
//   0x15ff78: 91206108  add      x8, x8, #0x818
//   0x15ff7c: AA0003F3  mov      x19, x0
uint64_t fde_func_4033_0x15ff68(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0015FF68ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81E0FF3ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB0001088ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91206108ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF8010408ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x97FFFBBBULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #4038 | PC: 0x160058..0x160068 (16 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x160058: F9400408  ldr      x8, [x0, #8]
//   0x16005c: 91004001  add      x1, x0, #0x10
//   0x160060: AA0803E0  mov      x0, x8
//   0x160064: 17FFF73F  b        #0x15dd60
uint64_t fde_func_4038_0x160058(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00160058ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400408ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91004001ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0803E0ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x17FFF73FULL ^ (3ULL << 32);
    return state ^ (state >> 29);
}

// FDE #4042 | PC: 0x1600c0..0x1600f8 (56 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x1600c0: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x1600c4: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x1600c8: 910043FD  add      x29, sp, #0x10
//   0x1600cc: 90001088  adrp     x8, #0x370000
//   0x1600d0: 91226108  add      x8, x8, #0x898
//   0x1600d4: AA0003F3  mov      x19, x0
uint64_t fde_func_4042_0x1600c0(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x001600C0ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81E0FF3ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x90001088ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91226108ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF8018408ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9400000BULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #4047 | PC: 0x160170..0x160270 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x160170: D10243FF  sub      sp, sp, #0x90
//   0x160174: F90033F5  str      x21, [sp, #0x60]
//   0x160178: A9074FF4  stp      x20, x19, [sp, #0x70]
//   0x16017c: A9087BFD  stp      x29, x30, [sp, #0x80]
//   0x160180: 910203FD  add      x29, sp, #0x80
//   0x160184: D53BD055  mrs      x21, tpidr_el0
uint64_t fde_func_4047_0x160170(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00160170ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10243FFULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF90033F5ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9074FF4ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9087BFDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910203FDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD53BD055ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF94016A9ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F4ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #4051 | PC: 0x160364..0x1603a4 (64 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x160364: 90001088  adrp     x8, #0x370000
//   0x160368: 91244108  add      x8, x8, #0x910
//   0x16036c: F9000028  str      x8, [x1]
//   0x160370: F9400408  ldr      x8, [x0, #8]
//   0x160374: F9000428  str      x8, [x1, #8]
//   0x160378: F9400808  ldr      x8, [x0, #0x10]
uint64_t fde_func_4051_0x160364(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00160364ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0x90001088ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91244108ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000028ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400408ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000428ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400808ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000828ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB40000C8ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #4056 | PC: 0x1605d4..0x1605e0 (12 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x1605d4: 90001080  adrp     x0, #0x370000
//   0x1605d8: 9125C000  add      x0, x0, #0x970
//   0x1605dc: D65F03C0  ret      
uint64_t fde_func_4056_0x1605d4(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x001605D4ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0x90001080ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9125C000ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD65F03C0ULL ^ (2ULL << 32);
    return state ^ (state >> 29);
}

// FDE #4060 | PC: 0x160738..0x160740 (8 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x160738: 91006000  add      x0, x0, #0x18
//   0x16073c: 17FB8F45  b        #0x44450
uint64_t fde_func_4060_0x160738(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00160738ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0x91006000ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x17FB8F45ULL ^ (1ULL << 32);
    return state ^ (state >> 29);
}

// FDE #4065 | PC: 0x1608dc..0x1608ec (16 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x1608dc: 90001088  adrp     x8, #0x370000
//   0x1608e0: 91278108  add      x8, x8, #0x9e0
//   0x1608e4: F8008408  str      x8, [x0], #8
//   0x1608e8: 17FC3B87  b        #0x6f704
uint64_t fde_func_4065_0x1608dc(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x001608DCULL);
    state = (state * 0x00000100000001B3ULL) ^ 0x90001088ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91278108ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF8008408ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x17FC3B87ULL ^ (3ULL << 32);
    return state ^ (state >> 29);
}

// FDE #4069 | PC: 0x1609bc..0x1609c4 (8 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x1609bc: 91002000  add      x0, x0, #8
//   0x1609c0: 17FC3B51  b        #0x6f704
uint64_t fde_func_4069_0x1609bc(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x001609BCULL);
    state = (state * 0x00000100000001B3ULL) ^ 0x91002000ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x17FC3B51ULL ^ (1ULL << 32);
    return state ^ (state >> 29);
}

// FDE #4073 | PC: 0x160bec..0x160bf8 (12 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x160bec: 90001080  adrp     x0, #0x370000
//   0x160bf0: 91290000  add      x0, x0, #0xa40
//   0x160bf4: D65F03C0  ret      
uint64_t fde_func_4073_0x160bec(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00160BECULL);
    state = (state * 0x00000100000001B3ULL) ^ 0x90001080ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91290000ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD65F03C0ULL ^ (2ULL << 32);
    return state ^ (state >> 29);
}

// FDE #4078 | PC: 0x160c6c..0x160d6c (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x160c6c: D101C3FF  sub      sp, sp, #0x70
//   0x160c70: F90023F5  str      x21, [sp, #0x40]
//   0x160c74: A9054FF4  stp      x20, x19, [sp, #0x50]
//   0x160c78: A9067BFD  stp      x29, x30, [sp, #0x60]
//   0x160c7c: 910183FD  add      x29, sp, #0x60
//   0x160c80: D53BD055  mrs      x21, tpidr_el0
uint64_t fde_func_4078_0x160c6c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00160C6CULL);
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

// FDE #4082 | PC: 0x160fb4..0x161008 (84 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x160fb4: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x160fb8: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x160fbc: 910043FD  add      x29, sp, #0x10
//   0x160fc0: A9007C7F  stp      xzr, xzr, [x3]
//   0x160fc4: F9000861  str      x1, [x3, #0x10]
//   0x160fc8: F9000043  str      x3, [x2]
uint64_t fde_func_4082_0x160fb4(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00160FB4ULL);
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

// FDE #4087 | PC: 0x1610e8..0x1610f0 (8 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x1610e8: 91002000  add      x0, x0, #8
//   0x1610ec: 17FC3986  b        #0x6f704
uint64_t fde_func_4087_0x1610e8(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x001610E8ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0x91002000ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x17FC3986ULL ^ (1ULL << 32);
    return state ^ (state >> 29);
}

// FDE #4091 | PC: 0x161318..0x161324 (12 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x161318: F0001060  adrp     x0, #0x370000
//   0x16131c: 912C4000  add      x0, x0, #0xb10
//   0x161320: D65F03C0  ret      
uint64_t fde_func_4091_0x161318(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00161318ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF0001060ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x912C4000ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD65F03C0ULL ^ (2ULL << 32);
    return state ^ (state >> 29);
}

// FDE #4096 | PC: 0x1615f8..0x16167c (132 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x1615f8: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x1615fc: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x161600: 910043FD  add      x29, sp, #0x10
//   0x161604: F9400428  ldr      x8, [x1, #8]
//   0x161608: B40000A8  cbz      x8, #0x16161c
//   0x16160c: AA0803F3  mov      x19, x8
uint64_t fde_func_4096_0x1615f8(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x001615F8ULL);
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

// FDE #4100 | PC: 0x16172c..0x161750 (36 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x16172c: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x161730: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x161734: 910043FD  add      x29, sp, #0x10
//   0x161738: AA0003F3  mov      x19, x0
//   0x16173c: 97FFFFE1  bl       #0x1616c0
//   0x161740: A9417BFD  ldp      x29, x30, [sp, #0x10]
uint64_t fde_func_4100_0x16172c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0016172CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81E0FF3ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x97FFFFE1ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9417BFDULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA1303E0ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF84207F3ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #4105 | PC: 0x161e38..0x161f38 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x161e38: D10303FF  sub      sp, sp, #0xc0
//   0x161e3c: A90767FA  stp      x26, x25, [sp, #0x70]
//   0x161e40: A9085FF8  stp      x24, x23, [sp, #0x80]
//   0x161e44: A90957F6  stp      x22, x21, [sp, #0x90]
//   0x161e48: A90A4FF4  stp      x20, x19, [sp, #0xa0]
//   0x161e4c: A90B7BFD  stp      x29, x30, [sp, #0xb0]
uint64_t fde_func_4105_0x161e38(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00161E38ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10303FFULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90767FAULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9085FF8ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90957F6ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90A4FF4ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90B7BFDULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9102C3FDULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD53BD059ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #4109 | PC: 0x162ba8..0x162bb0 (8 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x162ba8: D1002000  sub      x0, x0, #8
//   0x162bac: 17FFFFEB  b        #0x162b58
uint64_t fde_func_4109_0x162ba8(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00162BA8ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD1002000ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x17FFFFEBULL ^ (1ULL << 32);
    return state ^ (state >> 29);
}

// FDE #4114 | PC: 0x163ab8..0x163bb8 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x163ab8: D102C3FF  sub      sp, sp, #0xb0
//   0x163abc: A9056FFC  stp      x28, x27, [sp, #0x50]
//   0x163ac0: A90667FA  stp      x26, x25, [sp, #0x60]
//   0x163ac4: A9075FF8  stp      x24, x23, [sp, #0x70]
//   0x163ac8: A90857F6  stp      x22, x21, [sp, #0x80]
//   0x163acc: A9094FF4  stp      x20, x19, [sp, #0x90]
uint64_t fde_func_4114_0x163ab8(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00163AB8ULL);
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

// FDE #4118 | PC: 0x1640ec..0x1640f0 (4 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x1640ec: 17FB8091  b        #0x44330
uint64_t fde_func_4118_0x1640ec(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x001640ECULL);
    state = (state * 0x00000100000001B3ULL) ^ 0x17FB8091ULL ^ (0ULL << 32);
    return state ^ (state >> 29);
}

// FDE #4123 | PC: 0x164224..0x164228 (4 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x164224: 17FB8043  b        #0x44330
uint64_t fde_func_4123_0x164224(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00164224ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0x17FB8043ULL ^ (0ULL << 32);
    return state ^ (state >> 29);
}

// FDE #4127 | PC: 0x16444c..0x1644a4 (88 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x16444c: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x164450: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x164454: 910043FD  add      x29, sp, #0x10
//   0x164458: F9400413  ldr      x19, [x0, #8]
//   0x16445c: B40000F3  cbz      x19, #0x164478
//   0x164460: 91002268  add      x8, x19, #8
uint64_t fde_func_4127_0x16444c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0016444CULL);
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

// FDE #4132 | PC: 0x164768..0x164868 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x164768: A9BA6FFC  stp      x28, x27, [sp, #-0x60]!
//   0x16476c: A90167FA  stp      x26, x25, [sp, #0x10]
//   0x164770: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x164774: A90357F6  stp      x22, x21, [sp, #0x30]
//   0x164778: A9044FF4  stp      x20, x19, [sp, #0x40]
//   0x16477c: A9057BFD  stp      x29, x30, [sp, #0x50]
uint64_t fde_func_4132_0x164768(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00164768ULL);
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

// FDE #4136 | PC: 0x164b84..0x164bd0 (76 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x164b84: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x164b88: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x164b8c: 910043FD  add      x29, sp, #0x10
//   0x164b90: 39402008  ldrb     w8, [x0, #8]
//   0x164b94: AA0103F3  mov      x19, x1
//   0x164b98: 340000C8  cbz      w8, #0x164bb0
uint64_t fde_func_4136_0x164b84(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00164B84ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81E0FF3ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x39402008ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0103F3ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x340000C8ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x39408268ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x360000A8ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #4141 | PC: 0x164ebc..0x164ee0 (36 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x164ebc: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x164ec0: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x164ec4: 910043FD  add      x29, sp, #0x10
//   0x164ec8: AA0003F3  mov      x19, x0
//   0x164ecc: 97FFFFC1  bl       #0x164dd0
//   0x164ed0: A9417BFD  ldp      x29, x30, [sp, #0x10]
uint64_t fde_func_4141_0x164ebc(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00164EBCULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81E0FF3ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x97FFFFC1ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9417BFDULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA1303E0ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF84207F3ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #4145 | PC: 0x165220..0x165320 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x165220: D10343FF  sub      sp, sp, #0xd0
//   0x165224: F90043F9  str      x25, [sp, #0x80]
//   0x165228: A9095FF8  stp      x24, x23, [sp, #0x90]
//   0x16522c: A90A57F6  stp      x22, x21, [sp, #0xa0]
//   0x165230: A90B4FF4  stp      x20, x19, [sp, #0xb0]
//   0x165234: A90C7BFD  stp      x29, x30, [sp, #0xc0]
uint64_t fde_func_4145_0x165220(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00165220ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10343FFULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF90043F9ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9095FF8ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90A57F6ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90B4FF4ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90C7BFDULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910303FDULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD53BD057ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #4150 | PC: 0x165e98..0x165f98 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x165e98: D102C3FF  sub      sp, sp, #0xb0
//   0x165e9c: F90033F9  str      x25, [sp, #0x60]
//   0x165ea0: A9075FF8  stp      x24, x23, [sp, #0x70]
//   0x165ea4: A90857F6  stp      x22, x21, [sp, #0x80]
//   0x165ea8: A9094FF4  stp      x20, x19, [sp, #0x90]
//   0x165eac: A90A7BFD  stp      x29, x30, [sp, #0xa0]
uint64_t fde_func_4150_0x165e98(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00165E98ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD102C3FFULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF90033F9ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9075FF8ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90857F6ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9094FF4ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90A7BFDULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910283FDULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD53BD058ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #4154 | PC: 0x166ac8..0x166bc8 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x166ac8: D10483FF  sub      sp, sp, #0x120
//   0x166acc: FD0063E8  str      d8, [sp, #0xc0]
//   0x166ad0: A90D67FC  stp      x28, x25, [sp, #0xd0]
//   0x166ad4: A90E5FF8  stp      x24, x23, [sp, #0xe0]
//   0x166ad8: A90F57F6  stp      x22, x21, [sp, #0xf0]
//   0x166adc: A9104FF4  stp      x20, x19, [sp, #0x100]
uint64_t fde_func_4154_0x166ac8(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00166AC8ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10483FFULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xFD0063E8ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90D67FCULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90E5FF8ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90F57F6ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9104FF4ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9117BFDULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910443FDULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #4158 | PC: 0x1685b8..0x1685f0 (56 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x1685b8: B40001A1  cbz      x1, #0x1685ec
//   0x1685bc: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x1685c0: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x1685c4: 910043FD  add      x29, sp, #0x10
//   0x1685c8: F9400020  ldr      x0, [x1]
//   0x1685cc: AA0103F3  mov      x19, x1
uint64_t fde_func_4158_0x1685b8(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x001685B8ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xB40001A1ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81E0FF3ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400020ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0103F3ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF900003FULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB4000040ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #4163 | PC: 0x1688b8..0x168928 (112 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x1688b8: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x1688bc: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x1688c0: 910043FD  add      x29, sp, #0x10
//   0x1688c4: F9400C13  ldr      x19, [x0, #0x18]
//   0x1688c8: B40002B3  cbz      x19, #0x16891c
//   0x1688cc: 39414268  ldrb     w8, [x19, #0x50]
uint64_t fde_func_4163_0x1688b8(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x001688B8ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81E0FF3ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400C13ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB40002B3ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x39414268ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x36000068ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9403260ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #4167 | PC: 0x1689bc..0x168abc (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x1689bc: D101C3FF  sub      sp, sp, #0x70
//   0x1689c0: F9001BF7  str      x23, [sp, #0x30]
//   0x1689c4: A90457F6  stp      x22, x21, [sp, #0x40]
//   0x1689c8: A9054FF4  stp      x20, x19, [sp, #0x50]
//   0x1689cc: A9067BFD  stp      x29, x30, [sp, #0x60]
//   0x1689d0: 910183FD  add      x29, sp, #0x60
uint64_t fde_func_4167_0x1689bc(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x001689BCULL);
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

// FDE #4172 | PC: 0x169110..0x169210 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x169110: D10203FF  sub      sp, sp, #0x80
//   0x169114: F9002BF5  str      x21, [sp, #0x50]
//   0x169118: A9064FF4  stp      x20, x19, [sp, #0x60]
//   0x16911c: A9077BFD  stp      x29, x30, [sp, #0x70]
//   0x169120: 9101C3FD  add      x29, sp, #0x70
//   0x169124: D53BD055  mrs      x21, tpidr_el0
uint64_t fde_func_4172_0x169110(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00169110ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10203FFULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9002BF5ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9064FF4ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9077BFDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9101C3FDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD53BD055ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF94016A8ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #4176 | PC: 0x16ee34..0x16ef34 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x16ee34: D10243FF  sub      sp, sp, #0x90
//   0x16ee38: F90023F9  str      x25, [sp, #0x40]
//   0x16ee3c: A9055FF8  stp      x24, x23, [sp, #0x50]
//   0x16ee40: A90657F6  stp      x22, x21, [sp, #0x60]
//   0x16ee44: A9074FF4  stp      x20, x19, [sp, #0x70]
//   0x16ee48: A9087BFD  stp      x29, x30, [sp, #0x80]
uint64_t fde_func_4176_0x16ee34(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0016EE34ULL);
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

// FDE #4181 | PC: 0x170bc0..0x170c30 (112 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x170bc0: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x170bc4: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x170bc8: 910043FD  add      x29, sp, #0x10
//   0x170bcc: AA0003F3  mov      x19, x0
//   0x170bd0: 52800400  mov      w0, #0x20
//   0x170bd4: AA0103F4  mov      x20, x1
uint64_t fde_func_4181_0x170bc0(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00170BC0ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE4FF4ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x52800400ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0103F4ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x97FB4D3EULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF900001FULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #4185 | PC: 0x170d38..0x170d90 (88 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x170d38: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x170d3c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x170d40: 910043FD  add      x29, sp, #0x10
//   0x170d44: F9400413  ldr      x19, [x0, #8]
//   0x170d48: B40000F3  cbz      x19, #0x170d64
//   0x170d4c: 91002268  add      x8, x19, #8
uint64_t fde_func_4185_0x170d38(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00170D38ULL);
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

// FDE #4190 | PC: 0x1711bc..0x171214 (88 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x1711bc: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x1711c0: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x1711c4: 910043FD  add      x29, sp, #0x10
//   0x1711c8: F9400413  ldr      x19, [x0, #8]
//   0x1711cc: B40000F3  cbz      x19, #0x1711e8
//   0x1711d0: 91002268  add      x8, x19, #8
uint64_t fde_func_4190_0x1711bc(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x001711BCULL);
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

// FDE #4194 | PC: 0x171334..0x1713cc (152 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x171334: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x171338: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x17133c: 910043FD  add      x29, sp, #0x10
//   0x171340: AA0003F3  mov      x19, x0
//   0x171344: 52800020  mov      w0, #1
//   0x171348: 97FB516B  bl       #0x458f4
uint64_t fde_func_4194_0x171334(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00171334ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81E0FF3ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x52800020ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x97FB516BULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x360001A0ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB9400265ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #4199 | PC: 0x17152c..0x171584 (88 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x17152c: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x171530: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x171534: 910043FD  add      x29, sp, #0x10
//   0x171538: F9400413  ldr      x19, [x0, #8]
//   0x17153c: B40000F3  cbz      x19, #0x171558
//   0x171540: 91002268  add      x8, x19, #8
uint64_t fde_func_4199_0x17152c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0017152CULL);
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

// FDE #4203 | PC: 0x171754..0x1717ac (88 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x171754: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x171758: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x17175c: 910043FD  add      x29, sp, #0x10
//   0x171760: F9400413  ldr      x19, [x0, #8]
//   0x171764: B40000F3  cbz      x19, #0x171780
//   0x171768: 91002268  add      x8, x19, #8
uint64_t fde_func_4203_0x171754(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00171754ULL);
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

// FDE #4208 | PC: 0x1727cc..0x1728cc (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x1727cc: D10183FF  sub      sp, sp, #0x60
//   0x1727d0: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x1727d4: A90357F6  stp      x22, x21, [sp, #0x30]
//   0x1727d8: A9044FF4  stp      x20, x19, [sp, #0x40]
//   0x1727dc: A9057BFD  stp      x29, x30, [sp, #0x50]
//   0x1727e0: 910143FD  add      x29, sp, #0x50
uint64_t fde_func_4208_0x1727cc(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x001727CCULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10183FFULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9025FF8ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90357F6ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9044FF4ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9057BFDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910143FDULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD53BD056ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0803F4ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #4212 | PC: 0x173360..0x173460 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x173360: D10603FF  sub      sp, sp, #0x180
//   0x173364: A9126FFC  stp      x28, x27, [sp, #0x120]
//   0x173368: A91367FA  stp      x26, x25, [sp, #0x130]
//   0x17336c: A9145FF8  stp      x24, x23, [sp, #0x140]
//   0x173370: A91557F6  stp      x22, x21, [sp, #0x150]
//   0x173374: A9164FF4  stp      x20, x19, [sp, #0x160]
uint64_t fde_func_4212_0x173360(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00173360ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10603FFULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9126FFCULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA91367FAULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9145FF8ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA91557F6ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9164FF4ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9177BFDULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9105C3FDULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #4217 | PC: 0x174f68..0x174fc4 (92 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x174f68: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x174f6c: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x174f70: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x174f74: 910083FD  add      x29, sp, #0x20
//   0x174f78: 9104E013  add      x19, x0, #0x138
//   0x174f7c: AA0003F6  mov      x22, x0
uint64_t fde_func_4217_0x174f68(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00174F68ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BD57F6ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9014FF4ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9027BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910083FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9104E013ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F6ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA1303E0ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0203F4ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #4221 | PC: 0x175a60..0x175b60 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x175a60: D10243FF  sub      sp, sp, #0x90
//   0x175a64: FD001BE8  str      d8, [sp, #0x30]
//   0x175a68: F9001FFB  str      x27, [sp, #0x38]
//   0x175a6c: A90467FA  stp      x26, x25, [sp, #0x40]
//   0x175a70: A9055FF8  stp      x24, x23, [sp, #0x50]
//   0x175a74: A90657F6  stp      x22, x21, [sp, #0x60]
uint64_t fde_func_4221_0x175a60(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00175A60ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10243FFULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xFD001BE8ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9001FFBULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90467FAULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9055FF8ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90657F6ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9074FF4ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9087BFDULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #4226 | PC: 0x176f20..0x176fdc (188 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x176f20: F940480B  ldr      x11, [x0, #0x90]
//   0x176f24: 9102600A  add      x10, x0, #0x98
//   0x176f28: AA0003E9  mov      x9, x0
//   0x176f2c: AA0803E0  mov      x0, x8
//   0x176f30: EB0B015F  cmp      x10, x11
//   0x176f34: 54000480  b.eq     #0x176fc4
uint64_t fde_func_4226_0x176f20(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00176F20ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF940480BULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9102600AULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003E9ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0803E0ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xEB0B015FULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x54000480ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x52A88F48ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xBD402160ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #4230 | PC: 0x177564..0x177664 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x177564: D10343FF  sub      sp, sp, #0xd0
//   0x177568: FD0023EC  str      d12, [sp, #0x40]
//   0x17756c: 6D052BEB  stp      d11, d10, [sp, #0x50]
//   0x177570: 6D0623E9  stp      d9, d8, [sp, #0x60]
//   0x177574: A9076FFC  stp      x28, x27, [sp, #0x70]
//   0x177578: A90867FA  stp      x26, x25, [sp, #0x80]
uint64_t fde_func_4230_0x177564(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00177564ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10343FFULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xFD0023ECULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x6D052BEBULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x6D0623E9ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9076FFCULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90867FAULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9095FF8ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90A57F6ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #4234 | PC: 0x178280..0x178380 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x178280: D10403FF  sub      sp, sp, #0x100
//   0x178284: A90A6FFC  stp      x28, x27, [sp, #0xa0]
//   0x178288: A90B67FA  stp      x26, x25, [sp, #0xb0]
//   0x17828c: A90C5FF8  stp      x24, x23, [sp, #0xc0]
//   0x178290: A90D57F6  stp      x22, x21, [sp, #0xd0]
//   0x178294: A90E4FF4  stp      x20, x19, [sp, #0xe0]
uint64_t fde_func_4234_0x178280(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00178280ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10403FFULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90A6FFCULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90B67FAULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90C5FF8ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90D57F6ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90E4FF4ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90F7BFDULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9103C3FDULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #4239 | PC: 0x17b044..0x17b100 (188 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x17b044: F940400B  ldr      x11, [x0, #0x80]
//   0x17b048: 9102200A  add      x10, x0, #0x88
//   0x17b04c: AA0003E9  mov      x9, x0
//   0x17b050: AA0803E0  mov      x0, x8
//   0x17b054: EB0B015F  cmp      x10, x11
//   0x17b058: 54000480  b.eq     #0x17b0e8
uint64_t fde_func_4239_0x17b044(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0017B044ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF940400BULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9102200AULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003E9ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0803E0ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xEB0B015FULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x54000480ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x52A88F48ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xBD402160ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #4243 | PC: 0x17b4a4..0x17b5a4 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x17b4a4: D10243FF  sub      sp, sp, #0x90
//   0x17b4a8: FD0023EA  str      d10, [sp, #0x40]
//   0x17b4ac: 6D04A3E9  stp      d9, d8, [sp, #0x48]
//   0x17b4b0: F9002FF7  str      x23, [sp, #0x58]
//   0x17b4b4: A90657F6  stp      x22, x21, [sp, #0x60]
//   0x17b4b8: A9074FF4  stp      x20, x19, [sp, #0x70]
uint64_t fde_func_4243_0x17b4a4(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0017B4A4ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10243FFULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xFD0023EAULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x6D04A3E9ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9002FF7ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90657F6ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9074FF4ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9087BFDULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910203FDULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #4248 | PC: 0x17ba20..0x17ba64 (68 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x17ba20: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x17ba24: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x17ba28: 910043FD  add      x29, sp, #0x10
//   0x17ba2c: B4000161  cbz      x1, #0x17ba58
//   0x17ba30: AA0103F3  mov      x19, x1
//   0x17ba34: 39404268  ldrb     w8, [x19, #0x10]
uint64_t fde_func_4248_0x17ba20(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0017BA20ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE4FF4ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB4000161ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0103F3ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x39404268ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400274ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x36000068ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #4252 | PC: 0x17bb54..0x17bb98 (68 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x17bb54: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x17bb58: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x17bb5c: 910043FD  add      x29, sp, #0x10
//   0x17bb60: B4000161  cbz      x1, #0x17bb8c
//   0x17bb64: AA0103F3  mov      x19, x1
//   0x17bb68: 39404268  ldrb     w8, [x19, #0x10]
uint64_t fde_func_4252_0x17bb54(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0017BB54ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE4FF4ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB4000161ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0103F3ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x39404268ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400274ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x36000068ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #4257 | PC: 0x17c098..0x17c198 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x17c098: D10283FF  sub      sp, sp, #0xa0
//   0x17c09c: A9046FFC  stp      x28, x27, [sp, #0x40]
//   0x17c0a0: A90567FA  stp      x26, x25, [sp, #0x50]
//   0x17c0a4: A9065FF8  stp      x24, x23, [sp, #0x60]
//   0x17c0a8: A90757F6  stp      x22, x21, [sp, #0x70]
//   0x17c0ac: A9084FF4  stp      x20, x19, [sp, #0x80]
uint64_t fde_func_4257_0x17c098(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0017C098ULL);
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

// FDE #4261 | PC: 0x17c5dc..0x17c660 (132 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x17c5dc: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x17c5e0: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x17c5e4: 910043FD  add      x29, sp, #0x10
//   0x17c5e8: F9400008  ldr      x8, [x0]
//   0x17c5ec: F0001009  adrp     x9, #0x37f000
//   0x17c5f0: F85E8108  ldur     x8, [x8, #-0x18]
uint64_t fde_func_4261_0x17c5dc(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0017C5DCULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE4FF4ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400008ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF0001009ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF85E8108ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF945BD29ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x8B080013ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #4266 | PC: 0x17cae8..0x17cb4c (100 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x17cae8: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x17caec: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x17caf0: 910043FD  add      x29, sp, #0x10
//   0x17caf4: AA0103F3  mov      x19, x1
//   0x17caf8: AA0003F4  mov      x20, x0
//   0x17cafc: A8C10801  ldp      x1, x2, [x0], #0x10
uint64_t fde_func_4266_0x17cae8(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0017CAE8ULL);
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

// FDE #4270 | PC: 0x17cc44..0x17cc64 (32 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x17cc44: F9400068  ldr      x8, [x3]
//   0x17cc48: CB010042  sub      x2, x2, x1
//   0x17cc4c: F100045F  cmp      x2, #1
//   0x17cc50: CB020100  sub      x0, x8, x2
//   0x17cc54: F9000060  str      x0, [x3]
//   0x17cc58: 5400004B  b.lt     #0x17cc60
uint64_t fde_func_4270_0x17cc44(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0017CC44ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400068ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xCB010042ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF100045FULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xCB020100ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000060ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x5400004BULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x17FB2089ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD65F03C0ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #4275 | PC: 0x17cea0..0x17cee4 (68 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x17cea0: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x17cea4: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x17cea8: 910043FD  add      x29, sp, #0x10
//   0x17ceac: 90000FA8  adrp     x8, #0x370000
//   0x17ceb0: 913C8108  add      x8, x8, #0xf20
//   0x17ceb4: F9405001  ldr      x1, [x0, #0xa0]
uint64_t fde_func_4275_0x17cea0(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0017CEA0ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81E0FF3ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x90000FA8ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x913C8108ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9405001ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000008ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x90000FA8ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #4279 | PC: 0x17cf40..0x17cf5c (28 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x17cf40: F9404401  ldr      x1, [x0, #0x88]
//   0x17cf44: 90000FA9  adrp     x9, #0x370000
//   0x17cf48: 913DC129  add      x9, x9, #0xf70
//   0x17cf4c: 91020008  add      x8, x0, #0x80
//   0x17cf50: F9000009  str      x9, [x0]
//   0x17cf54: AA0803E0  mov      x0, x8
uint64_t fde_func_4279_0x17cf40(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0017CF40ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9404401ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x90000FA9ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x913DC129ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91020008ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000009ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0803E0ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x1400023BULL ^ (6ULL << 32);
    return state ^ (state >> 29);
}

// FDE #4284 | PC: 0x17d5b8..0x17d6b8 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x17d5b8: D106C3FF  sub      sp, sp, #0x1b0
//   0x17d5bc: A9156FFC  stp      x28, x27, [sp, #0x150]
//   0x17d5c0: A91667FA  stp      x26, x25, [sp, #0x160]
//   0x17d5c4: A9175FF8  stp      x24, x23, [sp, #0x170]
//   0x17d5c8: A91857F6  stp      x22, x21, [sp, #0x180]
//   0x17d5cc: A9194FF4  stp      x20, x19, [sp, #0x190]
uint64_t fde_func_4284_0x17d5b8(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0017D5B8ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD106C3FFULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9156FFCULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA91667FAULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9175FF8ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA91857F6ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9194FF4ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA91A7BFDULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910683FDULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #4288 | PC: 0x17dc64..0x17dd5c (248 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x17dc64: D10143FF  sub      sp, sp, #0x50
//   0x17dc68: F9000BF7  str      x23, [sp, #0x10]
//   0x17dc6c: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x17dc70: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x17dc74: A9047BFD  stp      x29, x30, [sp, #0x40]
//   0x17dc78: 910103FD  add      x29, sp, #0x40
uint64_t fde_func_4288_0x17dc64(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0017DC64ULL);
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

// FDE #4293 | PC: 0x17df2c..0x17df78 (76 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x17df2c: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x17df30: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x17df34: 910043FD  add      x29, sp, #0x10
//   0x17df38: 90000FA8  adrp     x8, #0x371000
//   0x17df3c: 91000108  add      x8, x8, #0
//   0x17df40: F9405801  ldr      x1, [x0, #0xb0]
uint64_t fde_func_4293_0x17df2c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0017DF2CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81E0FF3ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x90000FA8ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91000108ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9405801ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000008ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x90000FA8ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #4297 | PC: 0x17dfa4..0x17dfd8 (52 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x17dfa4: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x17dfa8: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x17dfac: 910043FD  add      x29, sp, #0x10
//   0x17dfb0: F9404C01  ldr      x1, [x0, #0x98]
//   0x17dfb4: 90000FA8  adrp     x8, #0x371000
//   0x17dfb8: 91014108  add      x8, x8, #0x50
uint64_t fde_func_4297_0x17dfa4(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0017DFA4ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81E0FF3ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9404C01ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x90000FA8ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91014108ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF8090408ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #4302 | PC: 0x17eb78..0x17ec28 (176 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x17eb78: D101C3FF  sub      sp, sp, #0x70
//   0x17eb7c: A9035FF8  stp      x24, x23, [sp, #0x30]
//   0x17eb80: A90457F6  stp      x22, x21, [sp, #0x40]
//   0x17eb84: A9054FF4  stp      x20, x19, [sp, #0x50]
//   0x17eb88: A9067BFD  stp      x29, x30, [sp, #0x60]
//   0x17eb8c: 910183FD  add      x29, sp, #0x60
uint64_t fde_func_4302_0x17eb78(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0017EB78ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD101C3FFULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9035FF8ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90457F6ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9054FF4ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9067BFDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910183FDULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD53BD058ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9401708ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #4306 | PC: 0x17edb8..0x17edbc (4 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x17edb8: 17FB1882  b        #0x44fc0
uint64_t fde_func_4306_0x17edb8(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0017EDB8ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0x17FB1882ULL ^ (0ULL << 32);
    return state ^ (state >> 29);
}

// FDE #4311 | PC: 0x17efb0..0x17efe0 (48 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x17efb0: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x17efb4: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x17efb8: 910043FD  add      x29, sp, #0x10
//   0x17efbc: F0000F88  adrp     x8, #0x371000
//   0x17efc0: 9103A108  add      x8, x8, #0xe8
//   0x17efc4: AA0003F3  mov      x19, x0
uint64_t fde_func_4311_0x17efb0(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0017EFB0ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81E0FF3ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF0000F88ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9103A108ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF8018408ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x94000016ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #4315 | PC: 0x17f024..0x17f0d0 (172 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x17f024: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x17f028: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x17f02c: 910043FD  add      x29, sp, #0x10
//   0x17f030: AA0003F3  mov      x19, x0
//   0x17f034: 9103E000  add      x0, x0, #0xf8
//   0x17f038: 97FFC861  bl       #0x1711bc
uint64_t fde_func_4315_0x17f024(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0017F024ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81E0FF3ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9103E000ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x97FFC861ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9103A260ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x97FFC951ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #4319 | PC: 0x17f1d4..0x17f1dc (8 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x17f1d4: 91006000  add      x0, x0, #0x18
//   0x17f1d8: 17FF5AC6  b        #0x155cf0
uint64_t fde_func_4319_0x17f1d4(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0017F1D4ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0x91006000ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x17FF5AC6ULL ^ (1ULL << 32);
    return state ^ (state >> 29);
}

// FDE #4324 | PC: 0x17f274..0x17f278 (4 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x17f274: 17FB142F  b        #0x44330
uint64_t fde_func_4324_0x17f274(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0017F274ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0x17FB142FULL ^ (0ULL << 32);
    return state ^ (state >> 29);
}

// FDE #4328 | PC: 0x17f39c..0x17f49c (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x17f39c: D101C3FF  sub      sp, sp, #0x70
//   0x17f3a0: F9000BFB  str      x27, [sp, #0x10]
//   0x17f3a4: A90267FA  stp      x26, x25, [sp, #0x20]
//   0x17f3a8: A9035FF8  stp      x24, x23, [sp, #0x30]
//   0x17f3ac: A90457F6  stp      x22, x21, [sp, #0x40]
//   0x17f3b0: A9054FF4  stp      x20, x19, [sp, #0x50]
uint64_t fde_func_4328_0x17f39c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0017F39CULL);
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

// FDE #4333 | PC: 0x17fa4c..0x17fb30 (228 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x17fa4c: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x17fa50: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x17fa54: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x17fa58: 910083FD  add      x29, sp, #0x20
//   0x17fa5c: F1000428  subs     x8, x1, #1
//   0x17fa60: AA0003F3  mov      x19, x0
uint64_t fde_func_4333_0x17fa4c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0017FA4CULL);
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

// FDE #4337 | PC: 0x17fdf8..0x17fe40 (72 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x17fdf8: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x17fdfc: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x17fe00: 910043FD  add      x29, sp, #0x10
//   0x17fe04: D0000F88  adrp     x8, #0x371000
//   0x17fe08: 91076108  add      x8, x8, #0x1d8
//   0x17fe0c: AA0003F4  mov      x20, x0
uint64_t fde_func_4337_0x17fdf8(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0017FDF8ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE4FF4ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD0000F88ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91076108ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F4ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF8018688ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #4342 | PC: 0x17ff00..0x17ff04 (4 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x17ff00: D65F03C0  ret      
uint64_t fde_func_4342_0x17ff00(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0017FF00ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD65F03C0ULL ^ (0ULL << 32);
    return state ^ (state >> 29);
}

// FDE #4346 | PC: 0x17ff70..0x17ff78 (8 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x17ff70: 91006000  add      x0, x0, #0x18
//   0x17ff74: 17FFC35B  b        #0x170ce0
uint64_t fde_func_4346_0x17ff70(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0017FF70ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0x91006000ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x17FFC35BULL ^ (1ULL << 32);
    return state ^ (state >> 29);
}

// FDE #4351 | PC: 0x17ffa8..0x180044 (156 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x17ffa8: D10103FF  sub      sp, sp, #0x40
//   0x17ffac: F9000BF5  str      x21, [sp, #0x10]
//   0x17ffb0: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x17ffb4: A9037BFD  stp      x29, x30, [sp, #0x30]
//   0x17ffb8: 9100C3FD  add      x29, sp, #0x30
//   0x17ffbc: 52801200  mov      w0, #0x90
uint64_t fde_func_4351_0x17ffa8(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0017FFA8ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10103FFULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF5ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9024FF4ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9037BFDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9100C3FDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x52801200ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0803F3ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x97FB1043ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #4355 | PC: 0x1800b4..0x1800b8 (4 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x1800b4: 17FB109F  b        #0x44330
uint64_t fde_func_4355_0x1800b4(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x001800B4ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0x17FB109FULL ^ (0ULL << 32);
    return state ^ (state >> 29);
}

// FDE #4360 | PC: 0x18020c..0x180210 (4 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x18020c: 17FB1049  b        #0x44330
uint64_t fde_func_4360_0x18020c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0018020CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0x17FB1049ULL ^ (0ULL << 32);
    return state ^ (state >> 29);
}

// FDE #4364 | PC: 0x18023c..0x180278 (60 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x18023c: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x180240: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x180244: 910043FD  add      x29, sp, #0x10
//   0x180248: AA0003F3  mov      x19, x0
//   0x18024c: F9402000  ldr      x0, [x0, #0x40]
//   0x180250: B0000F88  adrp     x8, #0x371000
uint64_t fde_func_4364_0x18023c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0018023CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81E0FF3ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9402000ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB0000F88ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91102108ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000268ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #4369 | PC: 0x180308..0x180340 (56 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x180308: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x18030c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x180310: 910043FD  add      x29, sp, #0x10
//   0x180314: B0000F88  adrp     x8, #0x371000
//   0x180318: 91116108  add      x8, x8, #0x458
//   0x18031c: AA0003F3  mov      x19, x0
uint64_t fde_func_4369_0x180308(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00180308ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81E0FF3ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB0000F88ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91116108ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF8020408ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9400000AULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #4373 | PC: 0x1803bc..0x1803f8 (60 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x1803bc: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x1803c0: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x1803c4: 910043FD  add      x29, sp, #0x10
//   0x1803c8: B0000F88  adrp     x8, #0x371000
//   0x1803cc: 9112A108  add      x8, x8, #0x4a8
//   0x1803d0: AA0003F3  mov      x19, x0
uint64_t fde_func_4373_0x1803bc(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x001803BCULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE4FF4ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB0000F88ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9112A108ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF8040408ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91006274ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #4378 | PC: 0x1804a4..0x1804f0 (76 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x1804a4: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x1804a8: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x1804ac: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x1804b0: 910083FD  add      x29, sp, #0x20
//   0x1804b4: B4000161  cbz      x1, #0x1804e0
//   0x1804b8: AA0103F3  mov      x19, x1
uint64_t fde_func_4378_0x1804a4(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x001804A4ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81D0FF5ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9014FF4ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9027BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910083FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB4000161ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0103F3ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91004014ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA1303E2ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #4382 | PC: 0x1805b4..0x1806b4 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x1805b4: D10243FF  sub      sp, sp, #0x90
//   0x1805b8: A9036FFC  stp      x28, x27, [sp, #0x30]
//   0x1805bc: A90467FA  stp      x26, x25, [sp, #0x40]
//   0x1805c0: A9055FF8  stp      x24, x23, [sp, #0x50]
//   0x1805c4: A90657F6  stp      x22, x21, [sp, #0x60]
//   0x1805c8: A9074FF4  stp      x20, x19, [sp, #0x70]
uint64_t fde_func_4382_0x1805b4(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x001805B4ULL);
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

// FDE #4387 | PC: 0x180ff4..0x1810f4 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x180ff4: D10203FF  sub      sp, sp, #0x80
//   0x180ff8: A9026FFC  stp      x28, x27, [sp, #0x20]
//   0x180ffc: A90367FA  stp      x26, x25, [sp, #0x30]
//   0x181000: A9045FF8  stp      x24, x23, [sp, #0x40]
//   0x181004: A90557F6  stp      x22, x21, [sp, #0x50]
//   0x181008: A9064FF4  stp      x20, x19, [sp, #0x60]
uint64_t fde_func_4387_0x180ff4(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00180FF4ULL);
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

// FDE #4391 | PC: 0x181274..0x181298 (36 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x181274: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x181278: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x18127c: 910043FD  add      x29, sp, #0x10
//   0x181280: AA0003F3  mov      x19, x0
//   0x181284: 97FB0F4F  bl       #0x44fc0
//   0x181288: A9417BFD  ldp      x29, x30, [sp, #0x10]
uint64_t fde_func_4391_0x181274(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00181274ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81E0FF3ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x97FB0F4FULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9417BFDULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA1303E0ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF84207F3ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #4395 | PC: 0x1812d0..0x181308 (56 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x1812d0: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x1812d4: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x1812d8: 910043FD  add      x29, sp, #0x10
//   0x1812dc: 90000F88  adrp     x8, #0x371000
//   0x1812e0: 91166108  add      x8, x8, #0x598
//   0x1812e4: AA0003F3  mov      x19, x0
uint64_t fde_func_4395_0x1812d0(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x001812D0ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81E0FF3ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x90000F88ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91166108ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF8018408ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9400000AULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #4400 | PC: 0x1813d8..0x181408 (48 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x1813d8: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x1813dc: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x1813e0: 910043FD  add      x29, sp, #0x10
//   0x1813e4: 90000F88  adrp     x8, #0x371000
//   0x1813e8: 9117A108  add      x8, x8, #0x5e8
//   0x1813ec: AA0003F3  mov      x19, x0
uint64_t fde_func_4400_0x1813d8(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x001813D8ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81E0FF3ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x90000F88ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9117A108ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF8018408ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x97FB220FULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #4404 | PC: 0x18144c..0x181470 (36 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x18144c: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x181450: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x181454: 910043FD  add      x29, sp, #0x10
//   0x181458: AA0003F3  mov      x19, x0
//   0x18145c: 97FB0ED9  bl       #0x44fc0
//   0x181460: A9417BFD  ldp      x29, x30, [sp, #0x10]
uint64_t fde_func_4404_0x18144c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0018144CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81E0FF3ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x97FB0ED9ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9417BFDULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA1303E0ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF84207F3ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #4409 | PC: 0x1814f8..0x18150c (20 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x1814f8: 3940E008  ldrb     w8, [x0, #0x38]
//   0x1814fc: 37000048  tbnz     w8, #0, #0x181504
//   0x181500: D65F03C0  ret      
//   0x181504: F9402400  ldr      x0, [x0, #0x48]
//   0x181508: 17FB0B8A  b        #0x44330
uint64_t fde_func_4409_0x1814f8(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x001814F8ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0x3940E008ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x37000048ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD65F03C0ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9402400ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x17FB0B8AULL ^ (4ULL << 32);
    return state ^ (state >> 29);
}

// FDE #4413 | PC: 0x181578..0x181580 (8 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x181578: 91008000  add      x0, x0, #0x20
//   0x18157c: 17FFC018  b        #0x1715dc
uint64_t fde_func_4413_0x181578(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00181578ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0x91008000ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x17FFC018ULL ^ (1ULL << 32);
    return state ^ (state >> 29);
}

// FDE #4418 | PC: 0x1815b0..0x1815f0 (64 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x1815b0: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x1815b4: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x1815b8: 910043FD  add      x29, sp, #0x10
//   0x1815bc: D37CFC28  lsr      x8, x1, #0x3c
//   0x1815c0: B5000168  cbnz     x8, #0x1815ec
//   0x1815c4: AA0003F4  mov      x20, x0
uint64_t fde_func_4418_0x1815b0(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x001815B0ULL);
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

// FDE #4422 | PC: 0x181c10..0x181ce8 (216 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x181c10: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x181c14: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x181c18: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x181c1c: 910083FD  add      x29, sp, #0x20
//   0x181c20: AA0303F6  mov      x22, x3
//   0x181c24: AA0203F5  mov      x21, x2
uint64_t fde_func_4422_0x181c10(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00181C10ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BD57F6ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9014FF4ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9027BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910083FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0303F6ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0203F5ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0103F3ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F4ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #4427 | PC: 0x1825cc..0x1826a4 (216 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x1825cc: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x1825d0: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x1825d4: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x1825d8: 910083FD  add      x29, sp, #0x20
//   0x1825dc: AA0303F6  mov      x22, x3
//   0x1825e0: AA0203F5  mov      x21, x2
uint64_t fde_func_4427_0x1825cc(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x001825CCULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BD57F6ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9014FF4ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9027BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910083FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0303F6ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0203F5ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0103F3ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F4ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #4431 | PC: 0x182a04..0x182a3c (56 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x182a04: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x182a08: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x182a0c: 910043FD  add      x29, sp, #0x10
//   0x182a10: F0000F68  adrp     x8, #0x371000
//   0x182a14: 911DE108  add      x8, x8, #0x778
//   0x182a18: AA0003F3  mov      x19, x0
uint64_t fde_func_4431_0x182a04(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00182A04ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81E0FF3ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF0000F68ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x911DE108ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF8018408ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9400000AULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #4436 | PC: 0x182ac4..0x182af4 (48 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x182ac4: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x182ac8: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x182acc: 910043FD  add      x29, sp, #0x10
//   0x182ad0: F0000F68  adrp     x8, #0x371000
//   0x182ad4: 911F2108  add      x8, x8, #0x7c8
//   0x182ad8: AA0003F3  mov      x19, x0
uint64_t fde_func_4436_0x182ac4(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00182AC4ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81E0FF3ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF0000F68ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x911F2108ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF8018408ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x97FF88BCULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #4440 | PC: 0x182b3c..0x182c3c (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x182b3c: A9BB67FA  stp      x26, x25, [sp, #-0x50]!
//   0x182b40: A9015FF8  stp      x24, x23, [sp, #0x10]
//   0x182b44: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x182b48: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x182b4c: A9047BFD  stp      x29, x30, [sp, #0x40]
//   0x182b50: 910103FD  add      x29, sp, #0x40
uint64_t fde_func_4440_0x182b3c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00182B3CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BB67FAULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9015FF8ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90257F6ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9034FF4ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9047BFDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910103FDULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0103F3ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F4ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #4445 | PC: 0x1834f8..0x183570 (120 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x1834f8: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x1834fc: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x183500: 910043FD  add      x29, sp, #0x10
//   0x183504: 39422008  ldrb     w8, [x0, #0x88]
//   0x183508: D0000F69  adrp     x9, #0x371000
//   0x18350c: 91206129  add      x9, x9, #0x818
uint64_t fde_func_4445_0x1834f8(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x001834F8ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81E0FF3ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x39422008ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD0000F69ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91206129ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000009ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD0000F69ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #4449 | PC: 0x183600..0x183684 (132 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x183600: 6F00E400  movi     v0.2d, #0000000000000000
//   0x183604: F0000AC8  adrp     x8, #0x2de000
//   0x183608: 3C818000  stur     q0, [x0, #0x18]
//   0x18360c: 3C828000  stur     q0, [x0, #0x28]
//   0x183610: 3C838000  stur     q0, [x0, #0x38]
//   0x183614: 6F07E7E0  movi     v0.2d, #0xffffffffffffffff
uint64_t fde_func_4449_0x183600(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00183600ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0x6F00E400ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF0000AC8ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x3C818000ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x3C828000ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x3C838000ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x6F07E7E0ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xFD002400ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xFD003400ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #4454 | PC: 0x184650..0x1846bc (108 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x184650: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x184654: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x184658: 910043FD  add      x29, sp, #0x10
//   0x18465c: 3941C008  ldrb     w8, [x0, #0x70]
//   0x184660: B0000F69  adrp     x9, #0x371000
//   0x184664: AA0003F3  mov      x19, x0
uint64_t fde_func_4454_0x184650(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00184650ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81E0FF3ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x3941C008ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB0000F69ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91232129ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000009ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #4458 | PC: 0x184ffc..0x185000 (4 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x184ffc: D65F03C0  ret      
uint64_t fde_func_4458_0x184ffc(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00184FFCULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD65F03C0ULL ^ (0ULL << 32);
    return state ^ (state >> 29);
}

// FDE #4463 | PC: 0x18504c..0x18506c (32 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x18504c: 90000F68  adrp     x8, #0x371000
//   0x185050: 91252108  add      x8, x8, #0x948
//   0x185054: F9000028  str      x8, [x1]
//   0x185058: 3CC18000  ldur     q0, [x0, #0x18]
//   0x18505c: 3CC08001  ldur     q1, [x0, #8]
//   0x185060: 3C818020  stur     q0, [x1, #0x18]
uint64_t fde_func_4463_0x18504c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0018504CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0x90000F68ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91252108ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000028ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x3CC18000ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x3CC08001ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x3C818020ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x3C808021ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD65F03C0ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #4467 | PC: 0x18515c..0x185178 (28 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x18515c: F9400428  ldr      x8, [x1, #8]
//   0x185160: 90000AE9  adrp     x9, #0x2e1000
//   0x185164: 91314929  add      x9, x9, #0xc52
//   0x185168: 9100200A  add      x10, x0, #8
//   0x18516c: EB09011F  cmp      x8, x9
//   0x185170: 9A9F0140  csel     x0, x10, xzr, eq
uint64_t fde_func_4467_0x18515c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0018515CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400428ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x90000AE9ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91314929ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9100200AULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xEB09011FULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9A9F0140ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD65F03C0ULL ^ (6ULL << 32);
    return state ^ (state >> 29);
}

// FDE #4472 | PC: 0x1851f8..0x1851fc (4 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x1851f8: 17FAFC4E  b        #0x44330
uint64_t fde_func_4472_0x1851f8(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x001851F8ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0x17FAFC4EULL ^ (0ULL << 32);
    return state ^ (state >> 29);
}

// FDE #4476 | PC: 0x1853d0..0x1854d0 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x1853d0: D10303FF  sub      sp, sp, #0xc0
//   0x1853d4: FD003BE8  str      d8, [sp, #0x70]
//   0x1853d8: F9003FF9  str      x25, [sp, #0x78]
//   0x1853dc: A9085FF8  stp      x24, x23, [sp, #0x80]
//   0x1853e0: A90957F6  stp      x22, x21, [sp, #0x90]
//   0x1853e4: A90A4FF4  stp      x20, x19, [sp, #0xa0]
uint64_t fde_func_4476_0x1853d0(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x001853D0ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10303FFULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xFD003BE8ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9003FF9ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9085FF8ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90957F6ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90A4FF4ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90B7BFDULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9102C3FDULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #4480 | PC: 0x18650c..0x1865c8 (188 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x18650c: F81C0FF7  str      x23, [sp, #-0x40]!
//   0x186510: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x186514: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x186518: A9037BFD  stp      x29, x30, [sp, #0x30]
//   0x18651c: 9100C3FD  add      x29, sp, #0x30
//   0x186520: AA0403F7  mov      x23, x4
uint64_t fde_func_4480_0x18650c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0018650CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81C0FF7ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90157F6ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9024FF4ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9037BFDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9100C3FDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0403F7ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0303F6ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0203F5ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #4485 | PC: 0x1868bc..0x186950 (148 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x1868bc: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x1868c0: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x1868c4: 910043FD  add      x29, sp, #0x10
//   0x1868c8: AA0003F3  mov      x19, x0
//   0x1868cc: F9406000  ldr      x0, [x0, #0xc0]
//   0x1868d0: F0000F48  adrp     x8, #0x371000
uint64_t fde_func_4485_0x1868bc(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x001868BCULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81E0FF3ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9406000ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF0000F48ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91298108ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000268ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #4489 | PC: 0x1869fc..0x186a6c (112 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x1869fc: 6F00E400  movi     v0.2d, #0000000000000000
//   0x186a00: 90000AC8  adrp     x8, #0x2de000
//   0x186a04: 3C818000  stur     q0, [x0, #0x18]
//   0x186a08: 3C828000  stur     q0, [x0, #0x28]
//   0x186a0c: 3C838000  stur     q0, [x0, #0x38]
//   0x186a10: 6F07E7E0  movi     v0.2d, #0xffffffffffffffff
uint64_t fde_func_4489_0x1869fc(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x001869FCULL);
    state = (state * 0x00000100000001B3ULL) ^ 0x6F00E400ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x90000AC8ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x3C818000ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x3C828000ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x3C838000ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x6F07E7E0ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xFD002400ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xFD003400ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #4494 | PC: 0x186d00..0x186e00 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x186d00: D10403FF  sub      sp, sp, #0x100
//   0x186d04: FD004BE8  str      d8, [sp, #0x90]
//   0x186d08: A90A6FFC  stp      x28, x27, [sp, #0xa0]
//   0x186d0c: A90B67FA  stp      x26, x25, [sp, #0xb0]
//   0x186d10: A90C5FF8  stp      x24, x23, [sp, #0xc0]
//   0x186d14: A90D57F6  stp      x22, x21, [sp, #0xd0]
uint64_t fde_func_4494_0x186d00(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00186D00ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10403FFULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xFD004BE8ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90A6FFCULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90B67FAULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90C5FF8ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90D57F6ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90E4FF4ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90F7BFDULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #4498 | PC: 0x188220..0x188290 (112 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x188220: A9402808  ldp      x8, x10, [x0]
//   0x188224: EB08015F  cmp      x10, x8
//   0x188228: 54000180  b.eq     #0x188258
//   0x18822c: F9400429  ldr      x9, [x1, #8]
//   0x188230: 3CDF0D40  ldr      q0, [x10, #-0x10]!
//   0x188234: 3C9F0120  stur     q0, [x9, #-0x10]
uint64_t fde_func_4498_0x188220(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00188220ULL);
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

// FDE #4503 | PC: 0x1898b4..0x1899b4 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x1898b4: F81A0FFB  str      x27, [sp, #-0x60]!
//   0x1898b8: A90167FA  stp      x26, x25, [sp, #0x10]
//   0x1898bc: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x1898c0: A90357F6  stp      x22, x21, [sp, #0x30]
//   0x1898c4: A9044FF4  stp      x20, x19, [sp, #0x40]
//   0x1898c8: A9057BFD  stp      x29, x30, [sp, #0x50]
uint64_t fde_func_4503_0x1898b4(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x001898B4ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81A0FFBULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90167FAULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9025FF8ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90357F6ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9044FF4ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9057BFDULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910143FDULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0403F8ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #4507 | PC: 0x18a6bc..0x18a794 (216 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x18a6bc: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x18a6c0: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x18a6c4: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x18a6c8: 910083FD  add      x29, sp, #0x20
//   0x18a6cc: AA0303F6  mov      x22, x3
//   0x18a6d0: AA0203F5  mov      x21, x2
uint64_t fde_func_4507_0x18a6bc(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0018A6BCULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BD57F6ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9014FF4ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9027BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910083FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0303F6ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0203F5ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0103F3ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F4ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #4512 | PC: 0x18acd8..0x18add8 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x18acd8: A9BC5FF8  stp      x24, x23, [sp, #-0x40]!
//   0x18acdc: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x18ace0: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x18ace4: A9037BFD  stp      x29, x30, [sp, #0x30]
//   0x18ace8: 9100C3FD  add      x29, sp, #0x30
//   0x18acec: AA0003F3  mov      x19, x0
uint64_t fde_func_4512_0x18acd8(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0018ACD8ULL);
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

// FDE #4516 | PC: 0x18aedc..0x18af78 (156 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x18aedc: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x18aee0: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x18aee4: 910043FD  add      x29, sp, #0x10
//   0x18aee8: AA0003F3  mov      x19, x0
//   0x18aeec: F9406C00  ldr      x0, [x0, #0xd8]
//   0x18aef0: F0000F28  adrp     x8, #0x371000
uint64_t fde_func_4516_0x18aedc(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0018AEDCULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81E0FF3ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9406C00ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF0000F28ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x912BE108ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000268ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #4521 | PC: 0x18b058..0x18b104 (172 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x18b058: D10143FF  sub      sp, sp, #0x50
//   0x18b05c: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x18b060: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x18b064: A9047BFD  stp      x29, x30, [sp, #0x40]
//   0x18b068: 910103FD  add      x29, sp, #0x40
//   0x18b06c: D53BD056  mrs      x22, tpidr_el0
uint64_t fde_func_4521_0x18b058(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0018B058ULL);
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

// FDE #4525 | PC: 0x18b30c..0x18b40c (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x18b30c: D104C3FF  sub      sp, sp, #0x130
//   0x18b310: FD0063E8  str      d8, [sp, #0xc0]
//   0x18b314: A90D6FFC  stp      x28, x27, [sp, #0xd0]
//   0x18b318: A90E67FA  stp      x26, x25, [sp, #0xe0]
//   0x18b31c: A90F5FF8  stp      x24, x23, [sp, #0xf0]
//   0x18b320: A91057F6  stp      x22, x21, [sp, #0x100]
uint64_t fde_func_4525_0x18b30c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0018B30CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD104C3FFULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xFD0063E8ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90D6FFCULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90E67FAULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90F5FF8ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA91057F6ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9114FF4ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9127BFDULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #4530 | PC: 0x18c660..0x18c6a8 (72 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x18c660: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x18c664: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x18c668: 910043FD  add      x29, sp, #0x10
//   0x18c66c: F9400013  ldr      x19, [x0]
//   0x18c670: A9402668  ldp      x8, x9, [x19]
//   0x18c674: 91004262  add      x2, x19, #0x10
uint64_t fde_func_4530_0x18c660(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0018C660ULL);
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

// FDE #4534 | PC: 0x18ca0c..0x18ca58 (76 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x18ca0c: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x18ca10: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x18ca14: 910043FD  add      x29, sp, #0x10
//   0x18ca18: 39402008  ldrb     w8, [x0, #8]
//   0x18ca1c: AA0103F3  mov      x19, x1
//   0x18ca20: 340000C8  cbz      w8, #0x18ca38
uint64_t fde_func_4534_0x18ca0c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0018CA0CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81E0FF3ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x39402008ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0103F3ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x340000C8ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x39404268ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x360000A8ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #4539 | PC: 0x18d0c4..0x18d1c4 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x18d0c4: A9BB67FA  stp      x26, x25, [sp, #-0x50]!
//   0x18d0c8: A9015FF8  stp      x24, x23, [sp, #0x10]
//   0x18d0cc: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x18d0d0: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x18d0d4: A9047BFD  stp      x29, x30, [sp, #0x40]
//   0x18d0d8: 910103FD  add      x29, sp, #0x40
uint64_t fde_func_4539_0x18d0c4(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0018D0C4ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BB67FAULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9015FF8ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90257F6ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9034FF4ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9047BFDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910103FDULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0103F3ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F4ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #4543 | PC: 0x18d86c..0x18d96c (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x18d86c: A9BB67FA  stp      x26, x25, [sp, #-0x50]!
//   0x18d870: A9015FF8  stp      x24, x23, [sp, #0x10]
//   0x18d874: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x18d878: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x18d87c: A9047BFD  stp      x29, x30, [sp, #0x40]
//   0x18d880: 910103FD  add      x29, sp, #0x40
uint64_t fde_func_4543_0x18d86c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0018D86CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BB67FAULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9015FF8ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90257F6ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9034FF4ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9047BFDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910103FDULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xCB000028ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9344FD08ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #4548 | PC: 0x18dc74..0x18dc80 (12 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x18dc74: F8418C08  ldr      x8, [x0, #0x18]!
//   0x18dc78: F9400101  ldr      x1, [x8]
//   0x18dc7c: D61F0020  br       x1
uint64_t fde_func_4548_0x18dc74(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0018DC74ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF8418C08ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400101ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD61F0020ULL ^ (2ULL << 32);
    return state ^ (state >> 29);
}

// FDE #4552 | PC: 0x18debc..0x18dfbc (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x18debc: D10243FF  sub      sp, sp, #0x90
//   0x18dec0: F9001BFB  str      x27, [sp, #0x30]
//   0x18dec4: A90467FA  stp      x26, x25, [sp, #0x40]
//   0x18dec8: A9055FF8  stp      x24, x23, [sp, #0x50]
//   0x18decc: A90657F6  stp      x22, x21, [sp, #0x60]
//   0x18ded0: A9074FF4  stp      x20, x19, [sp, #0x70]
uint64_t fde_func_4552_0x18debc(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0018DEBCULL);
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

// FDE #4556 | PC: 0x18e5dc..0x18e604 (40 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x18e5dc: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x18e5e0: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x18e5e4: 910043FD  add      x29, sp, #0x10
//   0x18e5e8: D1002013  sub      x19, x0, #8
//   0x18e5ec: AA1303E0  mov      x0, x19
//   0x18e5f0: 97FFFFC9  bl       #0x18e514
uint64_t fde_func_4556_0x18e5dc(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0018E5DCULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81E0FF3ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD1002013ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA1303E0ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x97FFFFC9ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9417BFDULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA1303E0ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #4561 | PC: 0x1928c0..0x1929c0 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x1928c0: D102C3FF  sub      sp, sp, #0xb0
//   0x1928c4: F9003BF7  str      x23, [sp, #0x70]
//   0x1928c8: A90857F6  stp      x22, x21, [sp, #0x80]
//   0x1928cc: A9094FF4  stp      x20, x19, [sp, #0x90]
//   0x1928d0: A90A7BFD  stp      x29, x30, [sp, #0xa0]
//   0x1928d4: 910283FD  add      x29, sp, #0xa0
uint64_t fde_func_4561_0x1928c0(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x001928C0ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD102C3FFULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9003BF7ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90857F6ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9094FF4ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90A7BFDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910283FDULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD53BD057ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF94016E8ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #4565 | PC: 0x192ffc..0x1930fc (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x192ffc: D10243FF  sub      sp, sp, #0x90
//   0x193000: F9002BF7  str      x23, [sp, #0x50]
//   0x193004: A90657F6  stp      x22, x21, [sp, #0x60]
//   0x193008: A9074FF4  stp      x20, x19, [sp, #0x70]
//   0x19300c: A9087BFD  stp      x29, x30, [sp, #0x80]
//   0x193010: 910203FD  add      x29, sp, #0x80
uint64_t fde_func_4565_0x192ffc(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00192FFCULL);
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

// FDE #4570 | PC: 0x194118..0x194218 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x194118: D104C3FF  sub      sp, sp, #0x130
//   0x19411c: A90D6FFC  stp      x28, x27, [sp, #0xd0]
//   0x194120: A90E67FA  stp      x26, x25, [sp, #0xe0]
//   0x194124: A90F5FF8  stp      x24, x23, [sp, #0xf0]
//   0x194128: A91057F6  stp      x22, x21, [sp, #0x100]
//   0x19412c: A9114FF4  stp      x20, x19, [sp, #0x110]
uint64_t fde_func_4570_0x194118(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00194118ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD104C3FFULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90D6FFCULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90E67FAULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90F5FF8ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA91057F6ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9114FF4ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9127BFDULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910483FDULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #4574 | PC: 0x195988..0x195a88 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x195988: D10543FF  sub      sp, sp, #0x150
//   0x19598c: A90F6FFC  stp      x28, x27, [sp, #0xf0]
//   0x195990: A91067FA  stp      x26, x25, [sp, #0x100]
//   0x195994: A9115FF8  stp      x24, x23, [sp, #0x110]
//   0x195998: A91257F6  stp      x22, x21, [sp, #0x120]
//   0x19599c: A9134FF4  stp      x20, x19, [sp, #0x130]
uint64_t fde_func_4574_0x195988(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00195988ULL);
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

// FDE #4579 | PC: 0x196688..0x1966c4 (60 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x196688: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x19668c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x196690: 910043FD  add      x29, sp, #0x10
//   0x196694: 91006040  add      x0, x2, #0x18
//   0x196698: AA0203F3  mov      x19, x2
//   0x19669c: 9400000A  bl       #0x1966c4
uint64_t fde_func_4579_0x196688(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00196688ULL);
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

// FDE #4583 | PC: 0x196900..0x196954 (84 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x196900: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x196904: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x196908: 910043FD  add      x29, sp, #0x10
//   0x19690c: A9007C7F  stp      xzr, xzr, [x3]
//   0x196910: F9000861  str      x1, [x3, #0x10]
//   0x196914: F9000043  str      x3, [x2]
uint64_t fde_func_4583_0x196900(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00196900ULL);
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

// FDE #4588 | PC: 0x1969cc..0x196a58 (140 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x1969cc: B0000F48  adrp     x8, #0x37f000
//   0x1969d0: F9477908  ldr      x8, [x8, #0xef0]
//   0x1969d4: 91004108  add      x8, x8, #0x10
//   0x1969d8: A9000408  stp      x8, x1, [x0]
//   0x1969dc: F9400068  ldr      x8, [x3]
//   0x1969e0: F9000808  str      x8, [x0, #0x10]
uint64_t fde_func_4588_0x1969cc(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x001969CCULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xB0000F48ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9477908ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91004108ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9000408ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400068ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000808ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400468ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000C08ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #4592 | PC: 0x196b54..0x196b8c (56 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x196b54: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x196b58: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x196b5c: 910043FD  add      x29, sp, #0x10
//   0x196b60: F0000EC8  adrp     x8, #0x371000
//   0x196b64: 91330108  add      x8, x8, #0xcc0
//   0x196b68: AA0003F3  mov      x19, x0
uint64_t fde_func_4592_0x196b54(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00196B54ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81E0FF3ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF0000EC8ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91330108ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF8018408ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9400000BULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #4597 | PC: 0x196c68..0x196c98 (48 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x196c68: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x196c6c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x196c70: 910043FD  add      x29, sp, #0x10
//   0x196c74: F0000EC8  adrp     x8, #0x371000
//   0x196c78: 91344108  add      x8, x8, #0xd10
//   0x196c7c: AA0003F3  mov      x19, x0
uint64_t fde_func_4597_0x196c68(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00196C68ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81E0FF3ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF0000EC8ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91344108ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF8018408ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x97FFFFC6ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #4601 | PC: 0x196ce0..0x196d68 (136 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x196ce0: B0000F49  adrp     x9, #0x37f000
//   0x196ce4: F9477929  ldr      x9, [x9, #0xef0]
//   0x196ce8: F0000EC8  adrp     x8, #0x371000
//   0x196cec: 91358108  add      x8, x8, #0xd60
//   0x196cf0: A9007C08  stp      x8, xzr, [x0]
//   0x196cf4: 91004128  add      x8, x9, #0x10
uint64_t fde_func_4601_0x196ce0(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00196CE0ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xB0000F49ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9477929ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF0000EC8ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91358108ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9007C08ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91004128ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA901201FULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9001002ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #4606 | PC: 0x196de0..0x196e68 (136 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x196de0: B0000F49  adrp     x9, #0x37f000
//   0x196de4: F9477929  ldr      x9, [x9, #0xef0]
//   0x196de8: F0000EC8  adrp     x8, #0x371000
//   0x196dec: 9136C108  add      x8, x8, #0xdb0
//   0x196df0: A9007C08  stp      x8, xzr, [x0]
//   0x196df4: 91004128  add      x8, x9, #0x10
uint64_t fde_func_4606_0x196de0(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00196DE0ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xB0000F49ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9477929ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF0000EC8ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9136C108ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9007C08ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91004128ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA901201FULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9001002ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #4610 | PC: 0x196edc..0x196ee0 (4 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x196edc: 17FAB515  b        #0x44330
uint64_t fde_func_4610_0x196edc(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00196EDCULL);
    state = (state * 0x00000100000001B3ULL) ^ 0x17FAB515ULL ^ (0ULL << 32);
    return state ^ (state >> 29);
}

// FDE #4615 | PC: 0x196fdc..0x196fe0 (4 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x196fdc: 17FAB4D5  b        #0x44330
uint64_t fde_func_4615_0x196fdc(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00196FDCULL);
    state = (state * 0x00000100000001B3ULL) ^ 0x17FAB4D5ULL ^ (0ULL << 32);
    return state ^ (state >> 29);
}

// FDE #4619 | PC: 0x1970d0..0x1970dc (12 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x1970d0: F8418C08  ldr      x8, [x0, #0x18]!
//   0x1970d4: F9400101  ldr      x1, [x8]
//   0x1970d8: D61F0020  br       x1
uint64_t fde_func_4619_0x1970d0(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x001970D0ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF8418C08ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400101ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD61F0020ULL ^ (2ULL << 32);
    return state ^ (state >> 29);
}

// FDE #4624 | PC: 0x197318..0x19735c (68 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x197318: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x19731c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x197320: 910043FD  add      x29, sp, #0x10
//   0x197324: F9400013  ldr      x19, [x0]
//   0x197328: F9000001  str      x1, [x0]
//   0x19732c: B4000133  cbz      x19, #0x197350
uint64_t fde_func_4624_0x197318(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00197318ULL);
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

// FDE #4628 | PC: 0x1979e8..0x197ae8 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x1979e8: F81C0FF7  str      x23, [sp, #-0x40]!
//   0x1979ec: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x1979f0: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x1979f4: A9037BFD  stp      x29, x30, [sp, #0x30]
//   0x1979f8: 9100C3FD  add      x29, sp, #0x30
//   0x1979fc: AA0403F7  mov      x23, x4
uint64_t fde_func_4628_0x1979e8(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x001979E8ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81C0FF7ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90157F6ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9024FF4ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9037BFDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9100C3FDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0403F7ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0303F6ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0203F5ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #4632 | PC: 0x1982cc..0x1983a4 (216 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x1982cc: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x1982d0: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x1982d4: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x1982d8: 910083FD  add      x29, sp, #0x20
//   0x1982dc: AA0303F6  mov      x22, x3
//   0x1982e0: AA0203F5  mov      x21, x2
uint64_t fde_func_4632_0x1982cc(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x001982CCULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BD57F6ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9014FF4ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9027BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910083FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0303F6ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0203F5ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0103F3ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F4ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #4637 | PC: 0x198c88..0x198d60 (216 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x198c88: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x198c8c: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x198c90: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x198c94: 910083FD  add      x29, sp, #0x20
//   0x198c98: AA0303F6  mov      x22, x3
//   0x198c9c: AA0203F5  mov      x21, x2
uint64_t fde_func_4637_0x198c88(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00198C88ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BD57F6ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9014FF4ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9027BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910083FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0303F6ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0203F5ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0103F3ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F4ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #4641 | PC: 0x199964..0x199a3c (216 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x199964: A9BC5FF8  stp      x24, x23, [sp, #-0x40]!
//   0x199968: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x19996c: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x199970: A9037BFD  stp      x29, x30, [sp, #0x30]
//   0x199974: 9100C3FD  add      x29, sp, #0x30
//   0x199978: 7100043F  cmp      w1, #1
uint64_t fde_func_4641_0x199964(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00199964ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BC5FF8ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90157F6ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9024FF4ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9037BFDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9100C3FDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x7100043FULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9007D1FULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x5400054BULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #4646 | PC: 0x199a74..0x199b74 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x199a74: A9BB67FA  stp      x26, x25, [sp, #-0x50]!
//   0x199a78: A9015FF8  stp      x24, x23, [sp, #0x10]
//   0x199a7c: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x199a80: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x199a84: A9047BFD  stp      x29, x30, [sp, #0x40]
//   0x199a88: 910103FD  add      x29, sp, #0x40
uint64_t fde_func_4646_0x199a74(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00199A74ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BB67FAULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9015FF8ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90257F6ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9034FF4ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9047BFDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910103FDULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0103F3ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F4ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #4650 | PC: 0x19a21c..0x19a31c (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x19a21c: A9BB67FA  stp      x26, x25, [sp, #-0x50]!
//   0x19a220: A9015FF8  stp      x24, x23, [sp, #0x10]
//   0x19a224: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x19a228: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x19a22c: A9047BFD  stp      x29, x30, [sp, #0x40]
//   0x19a230: 910103FD  add      x29, sp, #0x40
uint64_t fde_func_4650_0x19a21c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0019A21CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BB67FAULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9015FF8ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90257F6ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9034FF4ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9047BFDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910103FDULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xCB000028ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9344FD08ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #4655 | PC: 0x19afb8..0x19b0b8 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x19afb8: D10283FF  sub      sp, sp, #0xa0
//   0x19afbc: FD002BE8  str      d8, [sp, #0x50]
//   0x19afc0: F9002FF9  str      x25, [sp, #0x58]
//   0x19afc4: A9065FF8  stp      x24, x23, [sp, #0x60]
//   0x19afc8: A90757F6  stp      x22, x21, [sp, #0x70]
//   0x19afcc: A9084FF4  stp      x20, x19, [sp, #0x80]
uint64_t fde_func_4655_0x19afb8(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0019AFB8ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10283FFULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xFD002BE8ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9002FF9ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9065FF8ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90757F6ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9084FF4ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9097BFDULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910243FDULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #4659 | PC: 0x19bd1c..0x19be1c (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x19bd1c: D10783FF  sub      sp, sp, #0x1e0
//   0x19bd20: 6D162BEB  stp      d11, d10, [sp, #0x160]
//   0x19bd24: 6D1723E9  stp      d9, d8, [sp, #0x170]
//   0x19bd28: A9186FFC  stp      x28, x27, [sp, #0x180]
//   0x19bd2c: A91967FA  stp      x26, x25, [sp, #0x190]
//   0x19bd30: A91A5FF8  stp      x24, x23, [sp, #0x1a0]
uint64_t fde_func_4659_0x19bd1c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0019BD1CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10783FFULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x6D162BEBULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x6D1723E9ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9186FFCULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA91967FAULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA91A5FF8ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA91B57F6ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA91C4FF4ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #4664 | PC: 0x19d06c..0x19d16c (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x19d06c: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x19d070: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x19d074: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x19d078: 910083FD  add      x29, sp, #0x20
//   0x19d07c: F9400029  ldr      x9, [x1]
//   0x19d080: AA0203F3  mov      x19, x2
uint64_t fde_func_4664_0x19d06c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0019D06CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81D0FF5ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9014FF4ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9027BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910083FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400029ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0203F3ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F4ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0903E8ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #4668 | PC: 0x19d598..0x19d628 (144 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x19d598: D10103FF  sub      sp, sp, #0x40
//   0x19d59c: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x19d5a0: A9037BFD  stp      x29, x30, [sp, #0x30]
//   0x19d5a4: 9100C3FD  add      x29, sp, #0x30
//   0x19d5a8: D53BD054  mrs      x20, tpidr_el0
//   0x19d5ac: F9401688  ldr      x8, [x20, #0x28]
uint64_t fde_func_4668_0x19d598(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0019D598ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10103FFULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9024FF4ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9037BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9100C3FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD53BD054ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9401688ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x528002C9ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003E2ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #4673 | PC: 0x19dba8..0x19dc04 (92 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x19dba8: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x19dbac: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x19dbb0: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x19dbb4: 910083FD  add      x29, sp, #0x20
//   0x19dbb8: 90000EA8  adrp     x8, #0x371000
//   0x19dbbc: AA0003F3  mov      x19, x0
uint64_t fde_func_4673_0x19dba8(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0019DBA8ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81D0FF5ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9014FF4ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9027BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910083FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x90000EA8ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x913CA108ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F4ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #4677 | PC: 0x19def0..0x19dff0 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x19def0: D10283FF  sub      sp, sp, #0xa0
//   0x19def4: FD0023E8  str      d8, [sp, #0x40]
//   0x19def8: A90567FA  stp      x26, x25, [sp, #0x50]
//   0x19defc: A9065FF8  stp      x24, x23, [sp, #0x60]
//   0x19df00: A90757F6  stp      x22, x21, [sp, #0x70]
//   0x19df04: A9084FF4  stp      x20, x19, [sp, #0x80]
uint64_t fde_func_4677_0x19def0(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0019DEF0ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10283FFULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xFD0023E8ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90567FAULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9065FF8ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90757F6ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9084FF4ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9097BFDULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910243FDULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #4682 | PC: 0x19eaf8..0x19eb1c (36 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x19eaf8: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x19eafc: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x19eb00: 910043FD  add      x29, sp, #0x10
//   0x19eb04: AA0003F3  mov      x19, x0
//   0x19eb08: 97FFDFD4  bl       #0x196a58
//   0x19eb0c: A9417BFD  ldp      x29, x30, [sp, #0x10]
uint64_t fde_func_4682_0x19eaf8(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0019EAF8ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81E0FF3ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x97FFDFD4ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9417BFDULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA1303E0ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF84207F3ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #4686 | PC: 0x19f7e8..0x19f8e8 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x19f7e8: D102C3FF  sub      sp, sp, #0xb0
//   0x19f7ec: FD0023E8  str      d8, [sp, #0x40]
//   0x19f7f0: A9056FFC  stp      x28, x27, [sp, #0x50]
//   0x19f7f4: A90667FA  stp      x26, x25, [sp, #0x60]
//   0x19f7f8: A9075FF8  stp      x24, x23, [sp, #0x70]
//   0x19f7fc: A90857F6  stp      x22, x21, [sp, #0x80]
uint64_t fde_func_4686_0x19f7e8(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0019F7E8ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD102C3FFULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xFD0023E8ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9056FFCULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90667FAULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9075FF8ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90857F6ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9094FF4ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90A7BFDULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #4691 | PC: 0x1a0f98..0x1a0f9c (4 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x1a0f98: 17FA8CE6  b        #0x44330
uint64_t fde_func_4691_0x1a0f98(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x001A0F98ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0x17FA8CE6ULL ^ (0ULL << 32);
    return state ^ (state >> 29);
}

// FDE #4695 | PC: 0x1a1000..0x1a1004 (4 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x1a1000: 17FA8CCC  b        #0x44330
uint64_t fde_func_4695_0x1a1000(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x001A1000ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0x17FA8CCCULL ^ (0ULL << 32);
    return state ^ (state >> 29);
}

// FDE #4700 | PC: 0x1a11a8..0x1a12a8 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x1a11a8: F81B0FF9  str      x25, [sp, #-0x50]!
//   0x1a11ac: A9015FF8  stp      x24, x23, [sp, #0x10]
//   0x1a11b0: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x1a11b4: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x1a11b8: A9047BFD  stp      x29, x30, [sp, #0x40]
//   0x1a11bc: 910103FD  add      x29, sp, #0x40
uint64_t fde_func_4700_0x1a11a8(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x001A11A8ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81B0FF9ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9015FF8ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90257F6ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9034FF4ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9047BFDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910103FDULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0103F3ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F4ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #4704 | PC: 0x1a1700..0x1a1800 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x1a1700: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x1a1704: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x1a1708: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x1a170c: 910083FD  add      x29, sp, #0x20
//   0x1a1710: CB000028  sub      x8, x1, x0
//   0x1a1714: 9342FD08  asr      x8, x8, #2
uint64_t fde_func_4704_0x1a1700(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x001A1700ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81D0FF5ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9014FF4ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9027BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910083FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xCB000028ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9342FD08ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0103F4ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #4709 | PC: 0x1a2314..0x1a2414 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x1a2314: D101C3FF  sub      sp, sp, #0x70
//   0x1a2318: FD0013E8  str      d8, [sp, #0x20]
//   0x1a231c: A9035FF8  stp      x24, x23, [sp, #0x30]
//   0x1a2320: A90457F6  stp      x22, x21, [sp, #0x40]
//   0x1a2324: A9054FF4  stp      x20, x19, [sp, #0x50]
//   0x1a2328: A9067BFD  stp      x29, x30, [sp, #0x60]
uint64_t fde_func_4709_0x1a2314(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x001A2314ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD101C3FFULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xFD0013E8ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9035FF8ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90457F6ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9054FF4ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9067BFDULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910183FDULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400028ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #4713 | PC: 0x1a2d18..0x1a2d3c (36 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x1a2d18: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x1a2d1c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x1a2d20: 910043FD  add      x29, sp, #0x10
//   0x1a2d24: AA0003F3  mov      x19, x0
//   0x1a2d28: 97FFCF9D  bl       #0x196b9c
//   0x1a2d2c: A9417BFD  ldp      x29, x30, [sp, #0x10]
uint64_t fde_func_4713_0x1a2d18(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x001A2D18ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81E0FF3ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x97FFCF9DULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9417BFDULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA1303E0ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF84207F3ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #4717 | PC: 0x1a4310..0x1a4410 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x1a4310: F81A0FFB  str      x27, [sp, #-0x60]!
//   0x1a4314: A90167FA  stp      x26, x25, [sp, #0x10]
//   0x1a4318: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x1a431c: A90357F6  stp      x22, x21, [sp, #0x30]
//   0x1a4320: A9044FF4  stp      x20, x19, [sp, #0x40]
//   0x1a4324: A9057BFD  stp      x29, x30, [sp, #0x50]
uint64_t fde_func_4717_0x1a4310(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x001A4310ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81A0FFBULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90167FAULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9025FF8ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90357F6ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9044FF4ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9057BFDULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910143FDULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0403F8ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #4722 | PC: 0x1a5234..0x1a5334 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x1a5234: A9BB67FA  stp      x26, x25, [sp, #-0x50]!
//   0x1a5238: A9015FF8  stp      x24, x23, [sp, #0x10]
//   0x1a523c: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x1a5240: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x1a5244: A9047BFD  stp      x29, x30, [sp, #0x40]
//   0x1a5248: 910103FD  add      x29, sp, #0x40
uint64_t fde_func_4722_0x1a5234(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x001A5234ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BB67FAULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9015FF8ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90257F6ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9034FF4ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9047BFDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910103FDULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0103F3ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F4ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #4726 | PC: 0x1a59dc..0x1a5adc (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x1a59dc: A9BB67FA  stp      x26, x25, [sp, #-0x50]!
//   0x1a59e0: A9015FF8  stp      x24, x23, [sp, #0x10]
//   0x1a59e4: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x1a59e8: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x1a59ec: A9047BFD  stp      x29, x30, [sp, #0x40]
//   0x1a59f0: 910103FD  add      x29, sp, #0x40
uint64_t fde_func_4726_0x1a59dc(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x001A59DCULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BB67FAULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9015FF8ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90257F6ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9034FF4ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9047BFDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910103FDULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xCB000028ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9344FD08ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #4731 | PC: 0x1a686c..0x1a696c (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x1a686c: A9BB67FA  stp      x26, x25, [sp, #-0x50]!
//   0x1a6870: A9015FF8  stp      x24, x23, [sp, #0x10]
//   0x1a6874: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x1a6878: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x1a687c: A9047BFD  stp      x29, x30, [sp, #0x40]
//   0x1a6880: 910103FD  add      x29, sp, #0x40
uint64_t fde_func_4731_0x1a686c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x001A686CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BB67FAULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9015FF8ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90257F6ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9034FF4ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9047BFDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910103FDULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0103F3ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F4ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #4735 | PC: 0x1a7014..0x1a7114 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x1a7014: A9BB67FA  stp      x26, x25, [sp, #-0x50]!
//   0x1a7018: A9015FF8  stp      x24, x23, [sp, #0x10]
//   0x1a701c: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x1a7020: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x1a7024: A9047BFD  stp      x29, x30, [sp, #0x40]
//   0x1a7028: 910103FD  add      x29, sp, #0x40
uint64_t fde_func_4735_0x1a7014(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x001A7014ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BB67FAULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9015FF8ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90257F6ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9034FF4ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9047BFDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910103FDULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xCB000028ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9344FD08ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #4740 | PC: 0x1a7d50..0x1a7d74 (36 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x1a7d50: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x1a7d54: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x1a7d58: 910043FD  add      x29, sp, #0x10
//   0x1a7d5c: AA0003F3  mov      x19, x0
//   0x1a7d60: 97FFBB8F  bl       #0x196b9c
//   0x1a7d64: A9417BFD  ldp      x29, x30, [sp, #0x10]
uint64_t fde_func_4740_0x1a7d50(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x001A7D50ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81E0FF3ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x97FFBB8FULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9417BFDULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA1303E0ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF84207F3ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #4744 | PC: 0x1a8400..0x1a8500 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x1a8400: F81C0FF7  str      x23, [sp, #-0x40]!
//   0x1a8404: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x1a8408: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x1a840c: A9037BFD  stp      x29, x30, [sp, #0x30]
//   0x1a8410: 9100C3FD  add      x29, sp, #0x30
//   0x1a8414: AA0403F7  mov      x23, x4
uint64_t fde_func_4744_0x1a8400(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x001A8400ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81C0FF7ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90157F6ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9024FF4ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9037BFDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9100C3FDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0403F7ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0303F6ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0203F5ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #4749 | PC: 0x1a8b04..0x1a8c04 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x1a8b04: D106C3FF  sub      sp, sp, #0x1b0
//   0x1a8b08: A9156FFC  stp      x28, x27, [sp, #0x150]
//   0x1a8b0c: A91667FA  stp      x26, x25, [sp, #0x160]
//   0x1a8b10: A9175FF8  stp      x24, x23, [sp, #0x170]
//   0x1a8b14: A91857F6  stp      x22, x21, [sp, #0x180]
//   0x1a8b18: A9194FF4  stp      x20, x19, [sp, #0x190]
uint64_t fde_func_4749_0x1a8b04(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x001A8B04ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD106C3FFULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9156FFCULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA91667FAULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9175FF8ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA91857F6ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9194FF4ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA91A7BFDULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910683FDULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #4753 | PC: 0x1a9dd4..0x1a9ed4 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x1a9dd4: D10183FF  sub      sp, sp, #0x60
//   0x1a9dd8: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x1a9ddc: A90357F6  stp      x22, x21, [sp, #0x30]
//   0x1a9de0: A9044FF4  stp      x20, x19, [sp, #0x40]
//   0x1a9de4: A9057BFD  stp      x29, x30, [sp, #0x50]
//   0x1a9de8: 910143FD  add      x29, sp, #0x50
uint64_t fde_func_4753_0x1a9dd4(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x001A9DD4ULL);
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

// FDE #4758 | PC: 0x1aa988..0x1aaa28 (160 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x1aa988: D10183FF  sub      sp, sp, #0x60
//   0x1aa98c: F90013F7  str      x23, [sp, #0x20]
//   0x1aa990: A90357F6  stp      x22, x21, [sp, #0x30]
//   0x1aa994: A9044FF4  stp      x20, x19, [sp, #0x40]
//   0x1aa998: A9057BFD  stp      x29, x30, [sp, #0x50]
//   0x1aa99c: 910143FD  add      x29, sp, #0x50
uint64_t fde_func_4758_0x1aa988(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x001AA988ULL);
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

// FDE #4762 | PC: 0x1ab1a4..0x1ab2a4 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x1ab1a4: D10383FF  sub      sp, sp, #0xe0
//   0x1ab1a8: FD003BE8  str      d8, [sp, #0x70]
//   0x1ab1ac: A9086FFC  stp      x28, x27, [sp, #0x80]
//   0x1ab1b0: A90967FA  stp      x26, x25, [sp, #0x90]
//   0x1ab1b4: A90A5FF8  stp      x24, x23, [sp, #0xa0]
//   0x1ab1b8: A90B57F6  stp      x22, x21, [sp, #0xb0]
uint64_t fde_func_4762_0x1ab1a4(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x001AB1A4ULL);
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

// FDE #4767 | PC: 0x1acbe0..0x1acce0 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x1acbe0: D101C3FF  sub      sp, sp, #0x70
//   0x1acbe4: F90013F9  str      x25, [sp, #0x20]
//   0x1acbe8: A9035FF8  stp      x24, x23, [sp, #0x30]
//   0x1acbec: A90457F6  stp      x22, x21, [sp, #0x40]
//   0x1acbf0: A9054FF4  stp      x20, x19, [sp, #0x50]
//   0x1acbf4: A9067BFD  stp      x29, x30, [sp, #0x60]
uint64_t fde_func_4767_0x1acbe0(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x001ACBE0ULL);
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

// FDE #4771 | PC: 0x1ad340..0x1ad348 (8 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x1ad340: D1002000  sub      x0, x0, #8
//   0x1ad344: 17FEAE34  b        #0x158c14
uint64_t fde_func_4771_0x1ad340(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x001AD340ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD1002000ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x17FEAE34ULL ^ (1ULL << 32);
    return state ^ (state >> 29);
}

// FDE #4776 | PC: 0x1ad6fc..0x1ad7fc (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x1ad6fc: F81B0FF9  str      x25, [sp, #-0x50]!
//   0x1ad700: A9015FF8  stp      x24, x23, [sp, #0x10]
//   0x1ad704: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x1ad708: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x1ad70c: A9047BFD  stp      x29, x30, [sp, #0x40]
//   0x1ad710: 910103FD  add      x29, sp, #0x40
uint64_t fde_func_4776_0x1ad6fc(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x001AD6FCULL);
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

// FDE #4780 | PC: 0x1adbcc..0x1adc20 (84 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x1adbcc: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x1adbd0: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x1adbd4: 910043FD  add      x29, sp, #0x10
//   0x1adbd8: F9401008  ldr      x8, [x0, #0x20]
//   0x1adbdc: F9400409  ldr      x9, [x0, #8]
//   0x1adbe0: AA0003F3  mov      x19, x0
uint64_t fde_func_4780_0x1adbcc(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x001ADBCCULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81E0FF3ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9401008ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400409ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD345FD0AULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x927DDD4AULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #4785 | PC: 0x1ae274..0x1ae2ec (120 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x1ae274: AA0003E8  mov      x8, x0
//   0x1ae278: F9400000  ldr      x0, [x0]
//   0x1ae27c: F9400508  ldr      x8, [x8, #8]
//   0x1ae280: B4000321  cbz      x1, #0x1ae2e4
//   0x1ae284: F9400009  ldr      x9, [x0]
//   0x1ae288: CB090108  sub      x8, x8, x9
uint64_t fde_func_4785_0x1ae274(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x001AE274ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003E8ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400000ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400508ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB4000321ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400009ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xCB090108ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x8B881028ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF100051FULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #4789 | PC: 0x1ae360..0x1ae364 (4 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x1ae360: 17FA57F4  b        #0x44330
uint64_t fde_func_4789_0x1ae360(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x001AE360ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0x17FA57F4ULL ^ (0ULL << 32);
    return state ^ (state >> 29);
}

// FDE #4793 | PC: 0x1ae5ac..0x1ae5f0 (68 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x1ae5ac: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x1ae5b0: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x1ae5b4: 910043FD  add      x29, sp, #0x10
//   0x1ae5b8: 39402008  ldrb     w8, [x0, #8]
//   0x1ae5bc: AA0103F3  mov      x19, x1
//   0x1ae5c0: 34000088  cbz      w8, #0x1ae5d0
uint64_t fde_func_4793_0x1ae5ac(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x001AE5ACULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81E0FF3ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x39402008ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0103F3ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x34000088ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400001ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91008262ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #4798 | PC: 0x1ae9a4..0x1aea58 (180 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x1ae9a4: D10143FF  sub      sp, sp, #0x50
//   0x1ae9a8: F9000BF7  str      x23, [sp, #0x10]
//   0x1ae9ac: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x1ae9b0: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x1ae9b4: A9047BFD  stp      x29, x30, [sp, #0x40]
//   0x1ae9b8: 910103FD  add      x29, sp, #0x40
uint64_t fde_func_4798_0x1ae9a4(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x001AE9A4ULL);
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

// FDE #4802 | PC: 0x1aeacc..0x1aead0 (4 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x1aeacc: 17FA5619  b        #0x44330
uint64_t fde_func_4802_0x1aeacc(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x001AEACCULL);
    state = (state * 0x00000100000001B3ULL) ^ 0x17FA5619ULL ^ (0ULL << 32);
    return state ^ (state >> 29);
}

// FDE #4807 | PC: 0x1aeb88..0x1aeb8c (4 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x1aeb88: 17FA55EA  b        #0x44330
uint64_t fde_func_4807_0x1aeb88(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x001AEB88ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0x17FA55EAULL ^ (0ULL << 32);
    return state ^ (state >> 29);
}

// FDE #4811 | PC: 0x1aec00..0x1aec04 (4 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x1aec00: 17FA55CC  b        #0x44330
uint64_t fde_func_4811_0x1aec00(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x001AEC00ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0x17FA55CCULL ^ (0ULL << 32);
    return state ^ (state >> 29);
}

// FDE #4816 | PC: 0x1af51c..0x1af61c (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x1af51c: A9BA6FFC  stp      x28, x27, [sp, #-0x60]!
//   0x1af520: A90167FA  stp      x26, x25, [sp, #0x10]
//   0x1af524: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x1af528: A90357F6  stp      x22, x21, [sp, #0x30]
//   0x1af52c: A9044FF4  stp      x20, x19, [sp, #0x40]
//   0x1af530: A9057BFD  stp      x29, x30, [sp, #0x50]
uint64_t fde_func_4816_0x1af51c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x001AF51CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BA6FFCULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90167FAULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9025FF8ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90357F6ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9044FF4ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9057BFDULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910143FDULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10683FFULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #4820 | PC: 0x1af9d0..0x1afa00 (48 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x1af9d0: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x1af9d4: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x1af9d8: 910043FD  add      x29, sp, #0x10
//   0x1af9dc: AA0003F3  mov      x19, x0
//   0x1af9e0: F9400C00  ldr      x0, [x0, #0x18]
//   0x1af9e4: B4000060  cbz      x0, #0x1af9f0
uint64_t fde_func_4820_0x1af9d0(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x001AF9D0ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81E0FF3ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400C00ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB4000060ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9001260ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x97FA5251ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #4825 | PC: 0x1affd4..0x1b00d4 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x1affd4: D10383FF  sub      sp, sp, #0xe0
//   0x1affd8: A9086FFC  stp      x28, x27, [sp, #0x80]
//   0x1affdc: A90967FA  stp      x26, x25, [sp, #0x90]
//   0x1affe0: A90A5FF8  stp      x24, x23, [sp, #0xa0]
//   0x1affe4: A90B57F6  stp      x22, x21, [sp, #0xb0]
//   0x1affe8: A90C4FF4  stp      x20, x19, [sp, #0xc0]
uint64_t fde_func_4825_0x1affd4(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x001AFFD4ULL);
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

// FDE #4829 | PC: 0x1b0870..0x1b091c (172 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x1b0870: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x1b0874: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x1b0878: 910043FD  add      x29, sp, #0x10
//   0x1b087c: A940A809  ldp      x9, x10, [x0, #8]
//   0x1b0880: A942200B  ldp      x11, x8, [x0, #0x20]
//   0x1b0884: AA0003F3  mov      x19, x0
uint64_t fde_func_4829_0x1b0870(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x001B0870ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE4FF4ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA940A809ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA942200BULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0103F4ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xEB09014CULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #4834 | PC: 0x1b0f50..0x1b1050 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x1b0f50: FC1D0FEA  str      d10, [sp, #-0x30]!
//   0x1b0f54: 6D00A3E9  stp      d9, d8, [sp, #8]
//   0x1b0f58: F9000FF3  str      x19, [sp, #0x18]
//   0x1b0f5c: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x1b0f60: 910083FD  add      x29, sp, #0x20
//   0x1b0f64: F9408808  ldr      x8, [x0, #0x110]
uint64_t fde_func_4834_0x1b0f50(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x001B0F50ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xFC1D0FEAULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x6D00A3E9ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000FF3ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9027BFDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910083FDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9408808ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB9809809ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #4838 | PC: 0x1b1378..0x1b1478 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x1b1378: D10143FF  sub      sp, sp, #0x50
//   0x1b137c: A9015FF8  stp      x24, x23, [sp, #0x10]
//   0x1b1380: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x1b1384: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x1b1388: A9047BFD  stp      x29, x30, [sp, #0x40]
//   0x1b138c: 910103FD  add      x29, sp, #0x40
uint64_t fde_func_4838_0x1b1378(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x001B1378ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10143FFULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9015FF8ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90257F6ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9034FF4ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9047BFDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910103FDULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD53BD054ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9401688ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #4843 | PC: 0x1b2090..0x1b2190 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x1b2090: D106C3FF  sub      sp, sp, #0x1b0
//   0x1b2094: A9156FFC  stp      x28, x27, [sp, #0x150]
//   0x1b2098: A91667FA  stp      x26, x25, [sp, #0x160]
//   0x1b209c: A9175FF8  stp      x24, x23, [sp, #0x170]
//   0x1b20a0: A91857F6  stp      x22, x21, [sp, #0x180]
//   0x1b20a4: A9194FF4  stp      x20, x19, [sp, #0x190]
uint64_t fde_func_4843_0x1b2090(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x001B2090ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD106C3FFULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9156FFCULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA91667FAULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9175FF8ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA91857F6ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9194FF4ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA91A7BFDULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910683FDULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #4847 | PC: 0x1b2338..0x1b2340 (8 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x1b2338: 9E6703E0  fmov     d0, xzr
//   0x1b233c: D65F03C0  ret      
uint64_t fde_func_4847_0x1b2338(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x001B2338ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0x9E6703E0ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD65F03C0ULL ^ (1ULL << 32);
    return state ^ (state >> 29);
}

// FDE #4852 | PC: 0x1b2360..0x1b2368 (8 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x1b2360: 9E6703E0  fmov     d0, xzr
//   0x1b2364: D65F03C0  ret      
uint64_t fde_func_4852_0x1b2360(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x001B2360ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0x9E6703E0ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD65F03C0ULL ^ (1ULL << 32);
    return state ^ (state >> 29);
}

// FDE #4856 | PC: 0x1b23c4..0x1b23c8 (4 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x1b23c4: D65F03C0  ret      
uint64_t fde_func_4856_0x1b23c4(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x001B23C4ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD65F03C0ULL ^ (0ULL << 32);
    return state ^ (state >> 29);
}

// FDE #4861 | PC: 0x1b257c..0x1b267c (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x1b257c: D103C3FF  sub      sp, sp, #0xf0
//   0x1b2580: A9096FFC  stp      x28, x27, [sp, #0x90]
//   0x1b2584: A90A67FA  stp      x26, x25, [sp, #0xa0]
//   0x1b2588: A90B5FF8  stp      x24, x23, [sp, #0xb0]
//   0x1b258c: A90C57F6  stp      x22, x21, [sp, #0xc0]
//   0x1b2590: A90D4FF4  stp      x20, x19, [sp, #0xd0]
uint64_t fde_func_4861_0x1b257c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x001B257CULL);
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

// FDE #4865 | PC: 0x1b29e8..0x1b2ae8 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x1b29e8: D102C3FF  sub      sp, sp, #0xb0
//   0x1b29ec: A9056FFC  stp      x28, x27, [sp, #0x50]
//   0x1b29f0: A90667FA  stp      x26, x25, [sp, #0x60]
//   0x1b29f4: A9075FF8  stp      x24, x23, [sp, #0x70]
//   0x1b29f8: A90857F6  stp      x22, x21, [sp, #0x80]
//   0x1b29fc: A9094FF4  stp      x20, x19, [sp, #0x90]
uint64_t fde_func_4865_0x1b29e8(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x001B29E8ULL);
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

// FDE #4870 | PC: 0x1b2f04..0x1b3000 (252 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x1b2f04: D101C3FF  sub      sp, sp, #0x70
//   0x1b2f08: F9000BFB  str      x27, [sp, #0x10]
//   0x1b2f0c: A90267FA  stp      x26, x25, [sp, #0x20]
//   0x1b2f10: A9035FF8  stp      x24, x23, [sp, #0x30]
//   0x1b2f14: A90457F6  stp      x22, x21, [sp, #0x40]
//   0x1b2f18: A9054FF4  stp      x20, x19, [sp, #0x50]
uint64_t fde_func_4870_0x1b2f04(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x001B2F04ULL);
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

// FDE #4874 | PC: 0x1b32a4..0x1b3370 (204 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x1b32a4: D10143FF  sub      sp, sp, #0x50
//   0x1b32a8: F9000BF7  str      x23, [sp, #0x10]
//   0x1b32ac: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x1b32b0: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x1b32b4: A9047BFD  stp      x29, x30, [sp, #0x40]
//   0x1b32b8: 910103FD  add      x29, sp, #0x40
uint64_t fde_func_4874_0x1b32a4(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x001B32A4ULL);
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

// FDE #4878 | PC: 0x1b3444..0x1b344c (8 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x1b3444: 91006000  add      x0, x0, #0x18
//   0x1b3448: 17FE87A5  b        #0x1552dc
uint64_t fde_func_4878_0x1b3444(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x001B3444ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0x91006000ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x17FE87A5ULL ^ (1ULL << 32);
    return state ^ (state >> 29);
}

// FDE #4883 | PC: 0x1b3864..0x1b3964 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x1b3864: A9BC5FF8  stp      x24, x23, [sp, #-0x40]!
//   0x1b3868: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x1b386c: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x1b3870: A9037BFD  stp      x29, x30, [sp, #0x30]
//   0x1b3874: 9100C3FD  add      x29, sp, #0x30
//   0x1b3878: A9405408  ldp      x8, x21, [x0]
uint64_t fde_func_4883_0x1b3864(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x001B3864ULL);
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

// FDE #4887 | PC: 0x1b3c68..0x1b3d68 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x1b3c68: D10183FF  sub      sp, sp, #0x60
//   0x1b3c6c: F90013F7  str      x23, [sp, #0x20]
//   0x1b3c70: A90357F6  stp      x22, x21, [sp, #0x30]
//   0x1b3c74: A9044FF4  stp      x20, x19, [sp, #0x40]
//   0x1b3c78: A9057BFD  stp      x29, x30, [sp, #0x50]
//   0x1b3c7c: 910143FD  add      x29, sp, #0x50
uint64_t fde_func_4887_0x1b3c68(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x001B3C68ULL);
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

// FDE #4892 | PC: 0x1b43c0..0x1b4400 (64 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x1b43c0: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x1b43c4: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x1b43c8: 910043FD  add      x29, sp, #0x10
//   0x1b43cc: D37CFC28  lsr      x8, x1, #0x3c
//   0x1b43d0: B5000168  cbnz     x8, #0x1b43fc
//   0x1b43d4: AA0003F4  mov      x20, x0
uint64_t fde_func_4892_0x1b43c0(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x001B43C0ULL);
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

// FDE #4896 | PC: 0x1b4984..0x1b4a7c (248 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x1b4984: F9400028  ldr      x8, [x1]
//   0x1b4988: F9400009  ldr      x9, [x0]
//   0x1b498c: F940004A  ldr      x10, [x2]
//   0x1b4990: FD403900  ldr      d0, [x8, #0x70]
//   0x1b4994: FD403922  ldr      d2, [x9, #0x70]
//   0x1b4998: FD403941  ldr      d1, [x10, #0x70]
uint64_t fde_func_4896_0x1b4984(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x001B4984ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400028ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400009ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF940004AULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xFD403900ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xFD403922ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xFD403941ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x1E622000ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x54000145ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #4901 | PC: 0x1b4fd4..0x1b50d4 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x1b4fd4: D10183FF  sub      sp, sp, #0x60
//   0x1b4fd8: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x1b4fdc: A90357F6  stp      x22, x21, [sp, #0x30]
//   0x1b4fe0: A9044FF4  stp      x20, x19, [sp, #0x40]
//   0x1b4fe4: A9057BFD  stp      x29, x30, [sp, #0x50]
//   0x1b4fe8: 910143FD  add      x29, sp, #0x50
uint64_t fde_func_4901_0x1b4fd4(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x001B4FD4ULL);
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

// FDE #4905 | PC: 0x1b5460..0x1b5560 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x1b5460: A9BA6FFC  stp      x28, x27, [sp, #-0x60]!
//   0x1b5464: A90167FA  stp      x26, x25, [sp, #0x10]
//   0x1b5468: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x1b546c: A90357F6  stp      x22, x21, [sp, #0x30]
//   0x1b5470: A9044FF4  stp      x20, x19, [sp, #0x40]
//   0x1b5474: A9057BFD  stp      x29, x30, [sp, #0x50]
uint64_t fde_func_4905_0x1b5460(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x001B5460ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BA6FFCULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90167FAULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9025FF8ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90357F6ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9044FF4ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9057BFDULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910143FDULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0303F5ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #4910 | PC: 0x1b58c0..0x1b59c0 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x1b58c0: D101C3FF  sub      sp, sp, #0x70
//   0x1b58c4: A9035FF8  stp      x24, x23, [sp, #0x30]
//   0x1b58c8: A90457F6  stp      x22, x21, [sp, #0x40]
//   0x1b58cc: A9054FF4  stp      x20, x19, [sp, #0x50]
//   0x1b58d0: A9067BFD  stp      x29, x30, [sp, #0x60]
//   0x1b58d4: 910183FD  add      x29, sp, #0x60
uint64_t fde_func_4910_0x1b58c0(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x001B58C0ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD101C3FFULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9035FF8ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90457F6ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9054FF4ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9067BFDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910183FDULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD53BD055ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF94016A8ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #4914 | PC: 0x1b6204..0x1b6304 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x1b6204: A9BA6FFC  stp      x28, x27, [sp, #-0x60]!
//   0x1b6208: A90167FA  stp      x26, x25, [sp, #0x10]
//   0x1b620c: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x1b6210: A90357F6  stp      x22, x21, [sp, #0x30]
//   0x1b6214: A9044FF4  stp      x20, x19, [sp, #0x40]
//   0x1b6218: A9057BFD  stp      x29, x30, [sp, #0x50]
uint64_t fde_func_4914_0x1b6204(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x001B6204ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BA6FFCULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90167FAULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9025FF8ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90357F6ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9044FF4ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9057BFDULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910143FDULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10783FFULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #4919 | PC: 0x1b67d0..0x1b68d0 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x1b67d0: D102C3FF  sub      sp, sp, #0xb0
//   0x1b67d4: F90033F9  str      x25, [sp, #0x60]
//   0x1b67d8: A9075FF8  stp      x24, x23, [sp, #0x70]
//   0x1b67dc: A90857F6  stp      x22, x21, [sp, #0x80]
//   0x1b67e0: A9094FF4  stp      x20, x19, [sp, #0x90]
//   0x1b67e4: A90A7BFD  stp      x29, x30, [sp, #0xa0]
uint64_t fde_func_4919_0x1b67d0(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x001B67D0ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD102C3FFULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF90033F9ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9075FF8ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90857F6ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9094FF4ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90A7BFDULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910283FDULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD53BD058ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #4923 | PC: 0x1b6d70..0x1b6d84 (20 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x1b6d70: F9400008  ldr      x8, [x0]
//   0x1b6d74: 2A0103E2  mov      w2, w1
//   0x1b6d78: 52800061  mov      w1, #3
//   0x1b6d7c: F9404903  ldr      x3, [x8, #0x90]
//   0x1b6d80: D61F0060  br       x3
uint64_t fde_func_4923_0x1b6d70(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x001B6D70ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400008ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x2A0103E2ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x52800061ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9404903ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD61F0060ULL ^ (4ULL << 32);
    return state ^ (state >> 29);
}

// FDE #4928 | PC: 0x1b7608..0x1b7708 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x1b7608: D10403FF  sub      sp, sp, #0x100
//   0x1b760c: 6D082BEB  stp      d11, d10, [sp, #0x80]
//   0x1b7610: 6D0923E9  stp      d9, d8, [sp, #0x90]
//   0x1b7614: A90A6FFC  stp      x28, x27, [sp, #0xa0]
//   0x1b7618: A90B67FA  stp      x26, x25, [sp, #0xb0]
//   0x1b761c: A90C5FF8  stp      x24, x23, [sp, #0xc0]
uint64_t fde_func_4928_0x1b7608(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x001B7608ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10403FFULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x6D082BEBULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x6D0923E9ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90A6FFCULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90B67FAULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90C5FF8ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90D57F6ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90E4FF4ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #4932 | PC: 0x1b7ff4..0x1b8018 (36 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x1b7ff4: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x1b7ff8: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x1b7ffc: 910043FD  add      x29, sp, #0x10
//   0x1b8000: AA0003F3  mov      x19, x0
//   0x1b8004: 97FFDAB3  bl       #0x1aead0
//   0x1b8008: A9417BFD  ldp      x29, x30, [sp, #0x10]
uint64_t fde_func_4932_0x1b7ff4(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x001B7FF4ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81E0FF3ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x97FFDAB3ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9417BFDULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA1303E0ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF84207F3ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #4937 | PC: 0x1b8600..0x1b8700 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x1b8600: D10483FF  sub      sp, sp, #0x120
//   0x1b8604: A90C6FFC  stp      x28, x27, [sp, #0xc0]
//   0x1b8608: A90D67FA  stp      x26, x25, [sp, #0xd0]
//   0x1b860c: A90E5FF8  stp      x24, x23, [sp, #0xe0]
//   0x1b8610: A90F57F6  stp      x22, x21, [sp, #0xf0]
//   0x1b8614: A9104FF4  stp      x20, x19, [sp, #0x100]
uint64_t fde_func_4937_0x1b8600(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x001B8600ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10483FFULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90C6FFCULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90D67FAULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90E5FF8ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90F57F6ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9104FF4ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9117BFDULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910443FDULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #4941 | PC: 0x1b8ae8..0x1b8be8 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x1b8ae8: D10343FF  sub      sp, sp, #0xd0
//   0x1b8aec: A9076FFC  stp      x28, x27, [sp, #0x70]
//   0x1b8af0: A90867FA  stp      x26, x25, [sp, #0x80]
//   0x1b8af4: A9095FF8  stp      x24, x23, [sp, #0x90]
//   0x1b8af8: A90A57F6  stp      x22, x21, [sp, #0xa0]
//   0x1b8afc: A90B4FF4  stp      x20, x19, [sp, #0xb0]
uint64_t fde_func_4941_0x1b8ae8(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x001B8AE8ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10343FFULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9076FFCULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90867FAULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9095FF8ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90A57F6ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90B4FF4ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90C7BFDULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910303FDULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #4946 | PC: 0x1b9010..0x1b9110 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x1b9010: D10203FF  sub      sp, sp, #0x80
//   0x1b9014: A9026FFC  stp      x28, x27, [sp, #0x20]
//   0x1b9018: A90367FA  stp      x26, x25, [sp, #0x30]
//   0x1b901c: A9045FF8  stp      x24, x23, [sp, #0x40]
//   0x1b9020: A90557F6  stp      x22, x21, [sp, #0x50]
//   0x1b9024: A9064FF4  stp      x20, x19, [sp, #0x60]
uint64_t fde_func_4946_0x1b9010(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x001B9010ULL);
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

// FDE #4950 | PC: 0x1b9404..0x1b94e8 (228 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x1b9404: D10183FF  sub      sp, sp, #0x60
//   0x1b9408: F9000BF9  str      x25, [sp, #0x10]
//   0x1b940c: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x1b9410: A90357F6  stp      x22, x21, [sp, #0x30]
//   0x1b9414: A9044FF4  stp      x20, x19, [sp, #0x40]
//   0x1b9418: A9057BFD  stp      x29, x30, [sp, #0x50]
uint64_t fde_func_4950_0x1b9404(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x001B9404ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10183FFULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF9ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9025FF8ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90357F6ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9044FF4ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9057BFDULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910143FDULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD53BD059ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #4954 | PC: 0x1b97a8..0x1b9820 (120 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x1b97a8: AA0003E8  mov      x8, x0
//   0x1b97ac: F9400000  ldr      x0, [x0]
//   0x1b97b0: F9400508  ldr      x8, [x8, #8]
//   0x1b97b4: B4000321  cbz      x1, #0x1b9818
//   0x1b97b8: F9400009  ldr      x9, [x0]
//   0x1b97bc: CB090108  sub      x8, x8, x9
uint64_t fde_func_4954_0x1b97a8(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x001B97A8ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003E8ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400000ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400508ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB4000321ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400009ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xCB090108ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x8B881028ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF100051FULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #4959 | PC: 0x1b9c74..0x1b9ce0 (108 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x1b9c74: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x1b9c78: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x1b9c7c: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x1b9c80: 910083FD  add      x29, sp, #0x20
//   0x1b9c84: F9400015  ldr      x21, [x0]
//   0x1b9c88: B4000195  cbz      x21, #0x1b9cb8
uint64_t fde_func_4959_0x1b9c74(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x001B9C74ULL);
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

// FDE #4963 | PC: 0x1b9ed0..0x1b9f20 (80 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x1b9ed0: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x1b9ed4: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x1b9ed8: 910043FD  add      x29, sp, #0x10
//   0x1b9edc: A940A014  ldp      x20, x8, [x0, #8]
//   0x1b9ee0: AA0003F3  mov      x19, x0
//   0x1b9ee4: EB14011F  cmp      x8, x20
uint64_t fde_func_4963_0x1b9ed0(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x001B9ED0ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE4FF4ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA940A014ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xEB14011FULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x540000C0ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD1004100ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #4968 | PC: 0x1bb77c..0x1bb87c (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x1bb77c: A9BA6FFC  stp      x28, x27, [sp, #-0x60]!
//   0x1bb780: A90167FA  stp      x26, x25, [sp, #0x10]
//   0x1bb784: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x1bb788: A90357F6  stp      x22, x21, [sp, #0x30]
//   0x1bb78c: A9044FF4  stp      x20, x19, [sp, #0x40]
//   0x1bb790: A9057BFD  stp      x29, x30, [sp, #0x50]
uint64_t fde_func_4968_0x1bb77c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x001BB77CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BA6FFCULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90167FAULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9025FF8ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90357F6ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9044FF4ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9057BFDULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910143FDULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xCB000028ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #4972 | PC: 0x1bc1b0..0x1bc294 (228 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x1bc1b0: D10143FF  sub      sp, sp, #0x50
//   0x1bc1b4: F90013F5  str      x21, [sp, #0x20]
//   0x1bc1b8: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x1bc1bc: A9047BFD  stp      x29, x30, [sp, #0x40]
//   0x1bc1c0: 910103FD  add      x29, sp, #0x40
//   0x1bc1c4: D53BD055  mrs      x21, tpidr_el0
uint64_t fde_func_4972_0x1bc1b0(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x001BC1B0ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10143FFULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF90013F5ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9034FF4ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9047BFDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910103FDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD53BD055ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF94016A8ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0103F4ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #4977 | PC: 0x1bc520..0x1bc544 (36 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x1bc520: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x1bc524: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x1bc528: 910043FD  add      x29, sp, #0x10
//   0x1bc52c: AA0003F3  mov      x19, x0
//   0x1bc530: 97FFC968  bl       #0x1aead0
//   0x1bc534: A9417BFD  ldp      x29, x30, [sp, #0x10]
uint64_t fde_func_4977_0x1bc520(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x001BC520ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81E0FF3ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x97FFC968ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9417BFDULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA1303E0ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF84207F3ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #4981 | PC: 0x1bc990..0x1bc9b4 (36 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x1bc990: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x1bc994: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x1bc998: 910043FD  add      x29, sp, #0x10
//   0x1bc99c: AA0003F3  mov      x19, x0
//   0x1bc9a0: 97FFC84C  bl       #0x1aead0
//   0x1bc9a4: A9417BFD  ldp      x29, x30, [sp, #0x10]
uint64_t fde_func_4981_0x1bc990(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x001BC990ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81E0FF3ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x97FFC84CULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9417BFDULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA1303E0ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF84207F3ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #4986 | PC: 0x1bd670..0x1bd6c8 (88 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x1bd670: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x1bd674: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x1bd678: 910043FD  add      x29, sp, #0x10
//   0x1bd67c: F9400413  ldr      x19, [x0, #8]
//   0x1bd680: B40000F3  cbz      x19, #0x1bd69c
//   0x1bd684: 91002268  add      x8, x19, #8
uint64_t fde_func_4986_0x1bd670(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x001BD670ULL);
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

// FDE #4990 | PC: 0x1bdee4..0x1bdf24 (64 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x1bdee4: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x1bdee8: 910003FD  mov      x29, sp
//   0x1bdeec: 52800020  mov      w0, #1
//   0x1bdef0: 97FA1E81  bl       #0x458f4
//   0x1bdef4: 36000140  tbz      w0, #0, #0x1bdf1c
//   0x1bdef8: 90000942  adrp     x2, #0x2e5000
uint64_t fde_func_4990_0x1bdee4(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x001BDEE4ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BF7BFDULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x52800020ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x97FA1E81ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x36000140ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x90000942ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x90000941ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910C8C42ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #4995 | PC: 0x1be3b0..0x1be4b0 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x1be3b0: D10243FF  sub      sp, sp, #0x90
//   0x1be3b4: A9055FF8  stp      x24, x23, [sp, #0x50]
//   0x1be3b8: A90657F6  stp      x22, x21, [sp, #0x60]
//   0x1be3bc: A9074FF4  stp      x20, x19, [sp, #0x70]
//   0x1be3c0: A9087BFD  stp      x29, x30, [sp, #0x80]
//   0x1be3c4: 910203FD  add      x29, sp, #0x80
uint64_t fde_func_4995_0x1be3b0(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x001BE3B0ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10243FFULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9055FF8ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90657F6ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9074FF4ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9087BFDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910203FDULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD53BD057ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0803F3ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #4999 | PC: 0x1bed68..0x1bed88 (32 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x1bed68: 39402008  ldrb     w8, [x0, #8]
//   0x1bed6c: 90000DA9  adrp     x9, #0x372000
//   0x1bed70: 91242129  add      x9, x9, #0x908
//   0x1bed74: F9000009  str      x9, [x0]
//   0x1bed78: 37000048  tbnz     w8, #0, #0x1bed80
//   0x1bed7c: D65F03C0  ret      
uint64_t fde_func_4999_0x1bed68(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x001BED68ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0x39402008ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x90000DA9ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91242129ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000009ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x37000048ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD65F03C0ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400C00ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x17FA156BULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #5004 | PC: 0x1bee88..0x1beec4 (60 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x1bee88: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x1bee8c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x1bee90: 910043FD  add      x29, sp, #0x10
//   0x1bee94: 39406008  ldrb     w8, [x0, #0x18]
//   0x1bee98: 90000DA9  adrp     x9, #0x372000
//   0x1bee9c: AA0003F3  mov      x19, x0
uint64_t fde_func_5004_0x1bee88(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x001BEE88ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81E0FF3ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x39406008ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x90000DA9ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91252129ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000009ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #5008 | PC: 0x1bef20..0x1bef64 (68 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x1bef20: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x1bef24: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x1bef28: 910043FD  add      x29, sp, #0x10
//   0x1bef2c: B0000E09  adrp     x9, #0x37f000
//   0x1bef30: F947D529  ldr      x9, [x9, #0xfa8]
//   0x1bef34: 90000DA8  adrp     x8, #0x372000
uint64_t fde_func_5008_0x1bef20(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x001BEF20ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81E0FF3ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB0000E09ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF947D529ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x90000DA8ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91266108ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000008ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #5013 | PC: 0x1bf02c..0x1bf070 (68 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x1bf02c: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x1bf030: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x1bf034: 910043FD  add      x29, sp, #0x10
//   0x1bf038: 90000E09  adrp     x9, #0x37f000
//   0x1bf03c: F9478D29  ldr      x9, [x9, #0xf18]
//   0x1bf040: F0000D88  adrp     x8, #0x372000
uint64_t fde_func_5013_0x1bf02c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x001BF02CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81E0FF3ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x90000E09ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9478D29ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF0000D88ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9127A108ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000008ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #5017 | PC: 0x1bf0cc..0x1bf134 (104 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x1bf0cc: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x1bf0d0: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x1bf0d4: 910043FD  add      x29, sp, #0x10
//   0x1bf0d8: F9401028  ldr      x8, [x1, #0x20]
//   0x1bf0dc: AA0003F3  mov      x19, x0
//   0x1bf0e0: B4000128  cbz      x8, #0x1bf104
uint64_t fde_func_5017_0x1bf0cc(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x001BF0CCULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81E0FF3ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9401028ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB4000128ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xEB08003FULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x54000160ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #5022 | PC: 0x1bf2a4..0x1bf304 (96 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x1bf2a4: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x1bf2a8: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x1bf2ac: 910043FD  add      x29, sp, #0x10
//   0x1bf2b0: AA0003F3  mov      x19, x0
//   0x1bf2b4: F9402800  ldr      x0, [x0, #0x50]
//   0x1bf2b8: 9100C268  add      x8, x19, #0x30
uint64_t fde_func_5022_0x1bf2a4(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x001BF2A4ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81E0FF3ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9402800ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9100C268ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xEB00011FULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x540000A0ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #5026 | PC: 0x1bf7cc..0x1bf7d8 (12 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x1bf7cc: F0000D80  adrp     x0, #0x372000
//   0x1bf7d0: 912AA000  add      x0, x0, #0xaa8
//   0x1bf7d4: D65F03C0  ret      
uint64_t fde_func_5026_0x1bf7cc(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x001BF7CCULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF0000D80ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x912AA000ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD65F03C0ULL ^ (2ULL << 32);
    return state ^ (state >> 29);
}

// FDE #5031 | PC: 0x1bf920..0x1bf93c (28 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x1bf920: F0000D89  adrp     x9, #0x372000
//   0x1bf924: AA0103E8  mov      x8, x1
//   0x1bf928: 912B2129  add      x9, x9, #0xac8
//   0x1bf92c: F8010509  str      x9, [x8], #0x10
//   0x1bf930: 91004001  add      x1, x0, #0x10
//   0x1bf934: AA0803E0  mov      x0, x8
uint64_t fde_func_5031_0x1bf920(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x001BF920ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF0000D89ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0103E8ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x912B2129ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF8010509ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91004001ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0803E0ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x17FFFDE5ULL ^ (6ULL << 32);
    return state ^ (state >> 29);
}

// FDE #5035 | PC: 0x1bfa78..0x1bfa94 (28 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x1bfa78: F9400428  ldr      x8, [x1, #8]
//   0x1bfa7c: D0000929  adrp     x9, #0x2e5000
//   0x1bfa80: 91279929  add      x9, x9, #0x9e6
//   0x1bfa84: 9100400A  add      x10, x0, #0x10
//   0x1bfa88: EB09011F  cmp      x8, x9
//   0x1bfa8c: 9A9F0140  csel     x0, x10, xzr, eq
uint64_t fde_func_5035_0x1bfa78(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x001BFA78ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400428ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD0000929ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91279929ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9100400AULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xEB09011FULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9A9F0140ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD65F03C0ULL ^ (6ULL << 32);
    return state ^ (state >> 29);
}

// FDE #5039 | PC: 0x1bfe78..0x1bfef0 (120 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x1bfe78: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x1bfe7c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x1bfe80: 910043FD  add      x29, sp, #0x10
//   0x1bfe84: AA0003F3  mov      x19, x0
//   0x1bfe88: F9403800  ldr      x0, [x0, #0x70]
//   0x1bfe8c: F0000D88  adrp     x8, #0x372000
uint64_t fde_func_5039_0x1bfe78(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x001BFE78ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81E0FF3ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9403800ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF0000D88ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91014269ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x912D2108ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #5044 | PC: 0x1c0028..0x1c0128 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x1c0028: D101C3FF  sub      sp, sp, #0x70
//   0x1c002c: F90023F5  str      x21, [sp, #0x40]
//   0x1c0030: A9054FF4  stp      x20, x19, [sp, #0x50]
//   0x1c0034: A9067BFD  stp      x29, x30, [sp, #0x60]
//   0x1c0038: 910183FD  add      x29, sp, #0x60
//   0x1c003c: D53BD054  mrs      x20, tpidr_el0
uint64_t fde_func_5044_0x1c0028(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x001C0028ULL);
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

// FDE #5048 | PC: 0x1c0200..0x1c0300 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x1c0200: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x1c0204: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x1c0208: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x1c020c: 910083FD  add      x29, sp, #0x20
//   0x1c0210: D0000D88  adrp     x8, #0x372000
//   0x1c0214: 912F2108  add      x8, x8, #0xbc8
uint64_t fde_func_5048_0x1c0200(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x001C0200ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BD57F6ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9014FF4ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9027BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910083FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD0000D88ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x912F2108ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x6F00E400ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #5053 | PC: 0x1c0628..0x1c0680 (88 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x1c0628: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x1c062c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x1c0630: 910043FD  add      x29, sp, #0x10
//   0x1c0634: F9400413  ldr      x19, [x0, #8]
//   0x1c0638: B40000F3  cbz      x19, #0x1c0654
//   0x1c063c: 91002268  add      x8, x19, #8
uint64_t fde_func_5053_0x1c0628(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x001C0628ULL);
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

// FDE #5057 | PC: 0x1c0d30..0x1c0e18 (232 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x1c0d30: D10143FF  sub      sp, sp, #0x50
//   0x1c0d34: F90013F5  str      x21, [sp, #0x20]
//   0x1c0d38: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x1c0d3c: A9047BFD  stp      x29, x30, [sp, #0x40]
//   0x1c0d40: 910103FD  add      x29, sp, #0x40
//   0x1c0d44: D53BD055  mrs      x21, tpidr_el0
uint64_t fde_func_5057_0x1c0d30(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x001C0D30ULL);
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

// FDE #5062 | PC: 0x1c11b8..0x1c11c0 (8 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x1c11b8: F9400C00  ldr      x0, [x0, #0x18]
//   0x1c11bc: 14011C15  b        #0x208210
uint64_t fde_func_5062_0x1c11b8(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x001C11B8ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400C00ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x14011C15ULL ^ (1ULL << 32);
    return state ^ (state >> 29);
}

// FDE #5066 | PC: 0x1c11fc..0x1c1204 (8 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x1c11fc: F9402400  ldr      x0, [x0, #0x48]
//   0x1c1200: 140140ED  b        #0x2115b4
uint64_t fde_func_5066_0x1c11fc(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x001C11FCULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9402400ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x140140EDULL ^ (1ULL << 32);
    return state ^ (state >> 29);
}

// FDE #5071 | PC: 0x1c132c..0x1c139c (112 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x1c132c: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x1c1330: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x1c1334: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x1c1338: 910083FD  add      x29, sp, #0x20
//   0x1c133c: F9406001  ldr      x1, [x0, #0xc0]
//   0x1c1340: B0000D88  adrp     x8, #0x372000
uint64_t fde_func_5071_0x1c132c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x001C132CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81D0FF5ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9014FF4ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9027BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910083FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9406001ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB0000D88ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91302108ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #5075 | PC: 0x1c144c..0x1c1498 (76 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x1c144c: B4000241  cbz      x1, #0x1c1494
//   0x1c1450: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x1c1454: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x1c1458: 910043FD  add      x29, sp, #0x10
//   0x1c145c: AA0103F3  mov      x19, x1
//   0x1c1460: F9400021  ldr      x1, [x1]
uint64_t fde_func_5075_0x1c144c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x001C144CULL);
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

// FDE #5080 | PC: 0x1c1544..0x1c1548 (4 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x1c1544: 17FA0B7B  b        #0x44330
uint64_t fde_func_5080_0x1c1544(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x001C1544ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0x17FA0B7BULL ^ (0ULL << 32);
    return state ^ (state >> 29);
}

// FDE #5084 | PC: 0x1c1608..0x1c1610 (8 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x1c1608: 91006000  add      x0, x0, #0x18
//   0x1c160c: 14000002  b        #0x1c1614
uint64_t fde_func_5084_0x1c1608(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x001C1608ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0x91006000ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x14000002ULL ^ (1ULL << 32);
    return state ^ (state >> 29);
}

// FDE #5089 | PC: 0x1c16d4..0x1c16dc (8 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x1c16d4: 91006000  add      x0, x0, #0x18
//   0x1c16d8: 14000002  b        #0x1c16e0
uint64_t fde_func_5089_0x1c16d4(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x001C16D4ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0x91006000ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x14000002ULL ^ (1ULL << 32);
    return state ^ (state >> 29);
}

// FDE #5093 | PC: 0x1c1774..0x1c17b8 (68 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x1c1774: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x1c1778: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x1c177c: 910043FD  add      x29, sp, #0x10
//   0x1c1780: 39406008  ldrb     w8, [x0, #0x18]
//   0x1c1784: B0000D89  adrp     x9, #0x372000
//   0x1c1788: AA0003F3  mov      x19, x0
uint64_t fde_func_5093_0x1c1774(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x001C1774ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81E0FF3ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x39406008ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB0000D89ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91352129ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000009ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #5098 | PC: 0x1c1838..0x1c1840 (8 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x1c1838: 91006000  add      x0, x0, #0x18
//   0x1c183c: 14013FF3  b        #0x211808
uint64_t fde_func_5098_0x1c1838(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x001C1838ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0x91006000ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x14013FF3ULL ^ (1ULL << 32);
    return state ^ (state >> 29);
}

// FDE #5102 | PC: 0x1c1c14..0x1c1ce0 (204 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x1c1c14: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x1c1c18: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x1c1c1c: 910043FD  add      x29, sp, #0x10
//   0x1c1c20: B0000D88  adrp     x8, #0x372000
//   0x1c1c24: 9137A108  add      x8, x8, #0xde8
//   0x1c1c28: 91016109  add      x9, x8, #0x58
uint64_t fde_func_5102_0x1c1c14(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x001C1C14ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81E0FF3ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB0000D88ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9137A108ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91016109ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9E670100ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9102610AULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #5107 | PC: 0x1c1d3c..0x1c1d64 (40 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x1c1d3c: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x1c1d40: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x1c1d44: 910043FD  add      x29, sp, #0x10
//   0x1c1d48: D100E013  sub      x19, x0, #0x38
//   0x1c1d4c: AA1303E0  mov      x0, x19
//   0x1c1d50: 97FFFFB1  bl       #0x1c1c14
uint64_t fde_func_5107_0x1c1d3c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x001C1D3CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81E0FF3ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD100E013ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA1303E0ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x97FFFFB1ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9417BFDULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA1303E0ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #5111 | PC: 0x1c2574..0x1c257c (8 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x1c2574: F9404800  ldr      x0, [x0, #0x90]
//   0x1c2578: 17FE49DA  b        #0x154ce0
uint64_t fde_func_5111_0x1c2574(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x001C2574ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9404800ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x17FE49DAULL ^ (1ULL << 32);
    return state ^ (state >> 29);
}

// FDE #5115 | PC: 0x1c2594..0x1c259c (8 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x1c2594: F9404C00  ldr      x0, [x0, #0x98]
//   0x1c2598: 17FE49D4  b        #0x154ce8
uint64_t fde_func_5115_0x1c2594(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x001C2594ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9404C00ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x17FE49D4ULL ^ (1ULL << 32);
    return state ^ (state >> 29);
}

// FDE #5120 | PC: 0x1c26d8..0x1c2794 (188 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x1c26d8: D10183FF  sub      sp, sp, #0x60
//   0x1c26dc: F9001BF5  str      x21, [sp, #0x30]
//   0x1c26e0: A9044FF4  stp      x20, x19, [sp, #0x40]
//   0x1c26e4: A9057BFD  stp      x29, x30, [sp, #0x50]
//   0x1c26e8: 910143FD  add      x29, sp, #0x50
//   0x1c26ec: D53BD055  mrs      x21, tpidr_el0
uint64_t fde_func_5120_0x1c26d8(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x001C26D8ULL);
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

// FDE #5124 | PC: 0x1c297c..0x1c2a7c (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x1c297c: D10303FF  sub      sp, sp, #0xc0
//   0x1c2980: FD0033E8  str      d8, [sp, #0x60]
//   0x1c2984: A90767FA  stp      x26, x25, [sp, #0x70]
//   0x1c2988: A9085FF8  stp      x24, x23, [sp, #0x80]
//   0x1c298c: A90957F6  stp      x22, x21, [sp, #0x90]
//   0x1c2990: A90A4FF4  stp      x20, x19, [sp, #0xa0]
uint64_t fde_func_5124_0x1c297c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x001C297CULL);
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

// FDE #5129 | PC: 0x1c5fb8..0x1c6084 (204 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x1c5fb8: D10143FF  sub      sp, sp, #0x50
//   0x1c5fbc: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x1c5fc0: A9047BFD  stp      x29, x30, [sp, #0x40]
//   0x1c5fc4: 910103FD  add      x29, sp, #0x40
//   0x1c5fc8: D53BD054  mrs      x20, tpidr_el0
//   0x1c5fcc: F9401688  ldr      x8, [x20, #0x28]
uint64_t fde_func_5129_0x1c5fb8(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x001C5FB8ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10143FFULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9034FF4ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9047BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910103FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD53BD054ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9401688ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81E83A8ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9402800ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #5133 | PC: 0x1c64ac..0x1c65ac (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x1c64ac: D101C3FF  sub      sp, sp, #0x70
//   0x1c64b0: A9035FF8  stp      x24, x23, [sp, #0x30]
//   0x1c64b4: A90457F6  stp      x22, x21, [sp, #0x40]
//   0x1c64b8: A9054FF4  stp      x20, x19, [sp, #0x50]
//   0x1c64bc: A9067BFD  stp      x29, x30, [sp, #0x60]
//   0x1c64c0: 910183FD  add      x29, sp, #0x60
uint64_t fde_func_5133_0x1c64ac(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x001C64ACULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD101C3FFULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9035FF8ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90457F6ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9054FF4ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9067BFDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910183FDULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD53BD057ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF94016E8ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #5138 | PC: 0x1c6fec..0x1c70dc (240 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x1c6fec: D101C3FF  sub      sp, sp, #0x70
//   0x1c6ff0: A90457F6  stp      x22, x21, [sp, #0x40]
//   0x1c6ff4: A9054FF4  stp      x20, x19, [sp, #0x50]
//   0x1c6ff8: A9067BFD  stp      x29, x30, [sp, #0x60]
//   0x1c6ffc: 910183FD  add      x29, sp, #0x60
//   0x1c7000: D53BD055  mrs      x21, tpidr_el0
uint64_t fde_func_5138_0x1c6fec(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x001C6FECULL);
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

// FDE #5142 | PC: 0x1c76d0..0x1c77d0 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x1c76d0: D105C3FF  sub      sp, sp, #0x170
//   0x1c76d4: A9116FFC  stp      x28, x27, [sp, #0x110]
//   0x1c76d8: A91267FA  stp      x26, x25, [sp, #0x120]
//   0x1c76dc: A9135FF8  stp      x24, x23, [sp, #0x130]
//   0x1c76e0: A91457F6  stp      x22, x21, [sp, #0x140]
//   0x1c76e4: A9154FF4  stp      x20, x19, [sp, #0x150]
uint64_t fde_func_5142_0x1c76d0(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x001C76D0ULL);
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

// FDE #5147 | PC: 0x1c97a8..0x1c9818 (112 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x1c97a8: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x1c97ac: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x1c97b0: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x1c97b4: 910083FD  add      x29, sp, #0x20
//   0x1c97b8: F9400808  ldr      x8, [x0, #0x10]
//   0x1c97bc: B4000268  cbz      x8, #0x1c9808
uint64_t fde_func_5147_0x1c97a8(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x001C97A8ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81D0FF5ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9014FF4ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9027BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910083FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400808ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB4000268ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9405008ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #5151 | PC: 0x1c98fc..0x1c9970 (116 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x1c98fc: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x1c9900: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x1c9904: 910043FD  add      x29, sp, #0x10
//   0x1c9908: D0000DA9  adrp     x9, #0x37f000
//   0x1c990c: F9459529  ldr      x9, [x9, #0xb28]
//   0x1c9910: B0000D48  adrp     x8, #0x372000
uint64_t fde_func_5151_0x1c98fc(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x001C98FCULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81E0FF3ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD0000DA9ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9459529ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB0000D48ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x913C2108ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000008ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #5156 | PC: 0x1c9a90..0x1c9afc (108 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x1c9a90: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x1c9a94: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x1c9a98: 910043FD  add      x29, sp, #0x10
//   0x1c9a9c: D0000DA9  adrp     x9, #0x37f000
//   0x1c9aa0: F946A929  ldr      x9, [x9, #0xd50]
//   0x1c9aa4: B0000D48  adrp     x8, #0x372000
uint64_t fde_func_5156_0x1c9a90(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x001C9A90ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81E0FF3ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD0000DA9ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF946A929ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB0000D48ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9403801ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x913D6108ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #5160 | PC: 0x1c9b1c..0x1c9b4c (48 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x1c9b1c: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x1c9b20: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x1c9b24: 910043FD  add      x29, sp, #0x10
//   0x1c9b28: B0000D48  adrp     x8, #0x372000
//   0x1c9b2c: 913EA108  add      x8, x8, #0xfa8
//   0x1c9b30: AA0003F3  mov      x19, x0
uint64_t fde_func_5160_0x1c9b1c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x001C9B1CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81E0FF3ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB0000D48ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x913EA108ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF8010408ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x97FA556BULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #5165 | PC: 0x1c9c0c..0x1c9ce8 (220 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x1c9c0c: D10143FF  sub      sp, sp, #0x50
//   0x1c9c10: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x1c9c14: A9047BFD  stp      x29, x30, [sp, #0x40]
//   0x1c9c18: 910103FD  add      x29, sp, #0x40
//   0x1c9c1c: D53BD054  mrs      x20, tpidr_el0
//   0x1c9c20: F9401688  ldr      x8, [x20, #0x28]
uint64_t fde_func_5165_0x1c9c0c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x001C9C0CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10143FFULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9034FF4ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9047BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910103FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD53BD054ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9401688ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910023E1ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81E83A8ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #5169 | PC: 0x1c9d20..0x1c9d50 (48 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x1c9d20: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x1c9d24: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x1c9d28: 910043FD  add      x29, sp, #0x10
//   0x1c9d2c: D0000D48  adrp     x8, #0x373000
//   0x1c9d30: 9100A108  add      x8, x8, #0x28
//   0x1c9d34: AA0003F3  mov      x19, x0
uint64_t fde_func_5169_0x1c9d20(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x001C9D20ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81E0FF3ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD0000D48ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9100A108ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF8008408ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x97FA54EAULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #5174 | PC: 0x1c9e20..0x1c9f20 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x1c9e20: D10283FF  sub      sp, sp, #0xa0
//   0x1c9e24: F90023FB  str      x27, [sp, #0x40]
//   0x1c9e28: A90567FA  stp      x26, x25, [sp, #0x50]
//   0x1c9e2c: A9065FF8  stp      x24, x23, [sp, #0x60]
//   0x1c9e30: A90757F6  stp      x22, x21, [sp, #0x70]
//   0x1c9e34: A9084FF4  stp      x20, x19, [sp, #0x80]
uint64_t fde_func_5174_0x1c9e20(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x001C9E20ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10283FFULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF90023FBULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90567FAULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9065FF8ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90757F6ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9084FF4ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9097BFDULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910243FDULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #5178 | PC: 0x1cab48..0x1cab4c (4 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x1cab48: 17F9E5FA  b        #0x44330
uint64_t fde_func_5178_0x1cab48(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x001CAB48ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0x17F9E5FAULL ^ (0ULL << 32);
    return state ^ (state >> 29);
}

// FDE #5183 | PC: 0x1caba4..0x1cabac (8 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x1caba4: F9400400  ldr      x0, [x0, #8]
//   0x1caba8: 17FFEF35  b        #0x1c687c
uint64_t fde_func_5183_0x1caba4(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x001CABA4ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400400ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x17FFEF35ULL ^ (1ULL << 32);
    return state ^ (state >> 29);
}

// FDE #5187 | PC: 0x1cad80..0x1cae80 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x1cad80: F81B0FF9  str      x25, [sp, #-0x50]!
//   0x1cad84: A9015FF8  stp      x24, x23, [sp, #0x10]
//   0x1cad88: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x1cad8c: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x1cad90: A9047BFD  stp      x29, x30, [sp, #0x40]
//   0x1cad94: 910103FD  add      x29, sp, #0x40
uint64_t fde_func_5187_0x1cad80(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x001CAD80ULL);
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

// FDE #5191 | PC: 0x1cb250..0x1cb350 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x1cb250: A9BC5FF8  stp      x24, x23, [sp, #-0x40]!
//   0x1cb254: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x1cb258: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x1cb25c: A9037BFD  stp      x29, x30, [sp, #0x30]
//   0x1cb260: 9100C3FD  add      x29, sp, #0x30
//   0x1cb264: A9405408  ldp      x8, x21, [x0]
uint64_t fde_func_5191_0x1cb250(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x001CB250ULL);
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

// FDE #5196 | PC: 0x1cb65c..0x1cb71c (192 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x1cb65c: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x1cb660: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x1cb664: 910043FD  add      x29, sp, #0x10
//   0x1cb668: F9400048  ldr      x8, [x2]
//   0x1cb66c: A9404D0A  ldp      x10, x19, [x8]
//   0x1cb670: B40000D3  cbz      x19, #0x1cb688
uint64_t fde_func_5196_0x1cb65c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x001CB65CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81E0FF3ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400048ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9404D0AULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB40000D3ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91002268ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xC85F7D09ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #5200 | PC: 0x1cb8bc..0x1cb960 (164 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x1cb8bc: D10143FF  sub      sp, sp, #0x50
//   0x1cb8c0: F90013F5  str      x21, [sp, #0x20]
//   0x1cb8c4: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x1cb8c8: A9047BFD  stp      x29, x30, [sp, #0x40]
//   0x1cb8cc: 910103FD  add      x29, sp, #0x40
//   0x1cb8d0: D53BD055  mrs      x21, tpidr_el0
uint64_t fde_func_5200_0x1cb8bc(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x001CB8BCULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10143FFULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF90013F5ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9034FF4ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9047BFDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910103FDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD53BD055ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF94016A8ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0103F3ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #5205 | PC: 0x1cbbb4..0x1cbc54 (160 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x1cbbb4: D10143FF  sub      sp, sp, #0x50
//   0x1cbbb8: F90013F5  str      x21, [sp, #0x20]
//   0x1cbbbc: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x1cbbc0: A9047BFD  stp      x29, x30, [sp, #0x40]
//   0x1cbbc4: 910103FD  add      x29, sp, #0x40
//   0x1cbbc8: D53BD055  mrs      x21, tpidr_el0
uint64_t fde_func_5205_0x1cbbb4(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x001CBBB4ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10143FFULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF90013F5ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9034FF4ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9047BFDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910103FDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD53BD055ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF94016A8ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0103F3ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #5209 | PC: 0x1cbd9c..0x1cbdbc (32 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x1cbd9c: A9007D1F  stp      xzr, xzr, [x8]
//   0x1cbda0: F900091F  str      xzr, [x8, #0x10]
//   0x1cbda4: F9400400  ldr      x0, [x0, #8]
//   0x1cbda8: 2A0103E2  mov      w2, w1
//   0x1cbdac: AA0803E1  mov      x1, x8
//   0x1cbdb0: F8408C09  ldr      x9, [x0, #8]!
uint64_t fde_func_5209_0x1cbd9c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x001CBD9CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9007D1FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF900091FULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400400ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x2A0103E2ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0803E1ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF8408C09ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9401123ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD61F0060ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #5214 | PC: 0x1cbfcc..0x1cc070 (164 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x1cbfcc: D10143FF  sub      sp, sp, #0x50
//   0x1cbfd0: F90013F5  str      x21, [sp, #0x20]
//   0x1cbfd4: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x1cbfd8: A9047BFD  stp      x29, x30, [sp, #0x40]
//   0x1cbfdc: 910103FD  add      x29, sp, #0x40
//   0x1cbfe0: D53BD055  mrs      x21, tpidr_el0
uint64_t fde_func_5214_0x1cbfcc(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x001CBFCCULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10143FFULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF90013F5ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9034FF4ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9047BFDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910103FDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD53BD055ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF94016A8ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0103F3ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #5218 | PC: 0x1cc25c..0x1cc358 (252 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x1cc25c: D10183FF  sub      sp, sp, #0x60
//   0x1cc260: A90357F6  stp      x22, x21, [sp, #0x30]
//   0x1cc264: A9044FF4  stp      x20, x19, [sp, #0x40]
//   0x1cc268: A9057BFD  stp      x29, x30, [sp, #0x50]
//   0x1cc26c: 910143FD  add      x29, sp, #0x50
//   0x1cc270: D53BD056  mrs      x22, tpidr_el0
uint64_t fde_func_5218_0x1cc25c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x001CC25CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10183FFULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90357F6ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9044FF4ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9057BFDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910143FDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD53BD056ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF94016C9ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0803F4ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #5223 | PC: 0x1cc668..0x1cc6c0 (88 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x1cc668: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x1cc66c: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x1cc670: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x1cc674: 910083FD  add      x29, sp, #0x20
//   0x1cc678: F9400400  ldr      x0, [x0, #8]
//   0x1cc67c: AA0303F3  mov      x19, x3
uint64_t fde_func_5223_0x1cc668(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x001CC668ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BD57F6ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9014FF4ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9027BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910083FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400400ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0303F3ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0203F4ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0103F5ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #5227 | PC: 0x1cc8a8..0x1cc9a4 (252 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x1cc8a8: D10183FF  sub      sp, sp, #0x60
//   0x1cc8ac: A90357F6  stp      x22, x21, [sp, #0x30]
//   0x1cc8b0: A9044FF4  stp      x20, x19, [sp, #0x40]
//   0x1cc8b4: A9057BFD  stp      x29, x30, [sp, #0x50]
//   0x1cc8b8: 910143FD  add      x29, sp, #0x50
//   0x1cc8bc: D53BD056  mrs      x22, tpidr_el0
uint64_t fde_func_5227_0x1cc8a8(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x001CC8A8ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10183FFULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90357F6ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9044FF4ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9057BFDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910143FDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD53BD056ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF94016C9ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0803F4ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #5232 | PC: 0x1cca74..0x1ccb18 (164 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x1cca74: D10143FF  sub      sp, sp, #0x50
//   0x1cca78: FD0013E8  str      d8, [sp, #0x20]
//   0x1cca7c: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x1cca80: A9047BFD  stp      x29, x30, [sp, #0x40]
//   0x1cca84: 910103FD  add      x29, sp, #0x40
//   0x1cca88: D53BD054  mrs      x20, tpidr_el0
uint64_t fde_func_5232_0x1cca74(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x001CCA74ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10143FFULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xFD0013E8ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9034FF4ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9047BFDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910103FDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD53BD054ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9401688ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x4EA01C08ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #5236 | PC: 0x1cd760..0x1cd770 (16 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x1cd760: F9400400  ldr      x0, [x0, #8]
//   0x1cd764: F9400009  ldr      x9, [x0]
//   0x1cd768: F9400922  ldr      x2, [x9, #0x10]
//   0x1cd76c: D61F0040  br       x2
uint64_t fde_func_5236_0x1cd760(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x001CD760ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400400ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400009ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400922ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD61F0040ULL ^ (3ULL << 32);
    return state ^ (state >> 29);
}

// FDE #5241 | PC: 0x1cd908..0x1cd93c (52 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x1cd908: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x1cd90c: 910003FD  mov      x29, sp
//   0x1cd910: F9400028  ldr      x8, [x1]
//   0x1cd914: B40000E8  cbz      x8, #0x1cd930
//   0x1cd918: F9400400  ldr      x0, [x0, #8]
//   0x1cd91c: 9100E101  add      x1, x8, #0x38
uint64_t fde_func_5241_0x1cd908(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x001CD908ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BF7BFDULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400028ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB40000E8ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400400ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9100E101ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF8418C09ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9402929ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #5245 | PC: 0x1cdda4..0x1cddb4 (16 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x1cdda4: F9400400  ldr      x0, [x0, #8]
//   0x1cdda8: F9400008  ldr      x8, [x0]
//   0x1cddac: F940D502  ldr      x2, [x8, #0x1a8]
//   0x1cddb0: D61F0040  br       x2
uint64_t fde_func_5245_0x1cdda4(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x001CDDA4ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400400ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400008ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF940D502ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD61F0040ULL ^ (3ULL << 32);
    return state ^ (state >> 29);
}

// FDE #5250 | PC: 0x1cddf4..0x1cde68 (116 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x1cddf4: D10103FF  sub      sp, sp, #0x40
//   0x1cddf8: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x1cddfc: A9037BFD  stp      x29, x30, [sp, #0x30]
//   0x1cde00: 9100C3FD  add      x29, sp, #0x30
//   0x1cde04: D53BD054  mrs      x20, tpidr_el0
//   0x1cde08: F9401688  ldr      x8, [x20, #0x28]
uint64_t fde_func_5250_0x1cddf4(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x001CDDF4ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10103FFULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9024FF4ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9037BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9100C3FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD53BD054ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9401688ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003E3ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000FE8ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #5254 | PC: 0x1cdf38..0x1ce018 (224 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x1cdf38: D10143FF  sub      sp, sp, #0x50
//   0x1cdf3c: F90013F5  str      x21, [sp, #0x20]
//   0x1cdf40: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x1cdf44: A9047BFD  stp      x29, x30, [sp, #0x40]
//   0x1cdf48: 910103FD  add      x29, sp, #0x40
//   0x1cdf4c: D53BD055  mrs      x21, tpidr_el0
uint64_t fde_func_5254_0x1cdf38(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x001CDF38ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10143FFULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF90013F5ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9034FF4ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9047BFDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910103FDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD53BD055ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF94016A9ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0803F3ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #5259 | PC: 0x1ce37c..0x1ce3d4 (88 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x1ce37c: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x1ce380: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x1ce384: 910043FD  add      x29, sp, #0x10
//   0x1ce388: F9400413  ldr      x19, [x0, #8]
//   0x1ce38c: B40000F3  cbz      x19, #0x1ce3a8
//   0x1ce390: 91002268  add      x8, x19, #8
uint64_t fde_func_5259_0x1ce37c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x001CE37CULL);
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

// FDE #5263 | PC: 0x1ce5dc..0x1ce6ac (208 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x1ce5dc: F81C0FF7  str      x23, [sp, #-0x40]!
//   0x1ce5e0: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x1ce5e4: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x1ce5e8: A9037BFD  stp      x29, x30, [sp, #0x30]
//   0x1ce5ec: 9100C3FD  add      x29, sp, #0x30
//   0x1ce5f0: F9400048  ldr      x8, [x2]
uint64_t fde_func_5263_0x1ce5dc(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x001CE5DCULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81C0FF7ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90157F6ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9024FF4ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9037BFDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9100C3FDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400048ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0203F3ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0103F4ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #5268 | PC: 0x1ce994..0x1cea3c (168 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x1ce994: D101C3FF  sub      sp, sp, #0x70
//   0x1ce998: F90023F5  str      x21, [sp, #0x40]
//   0x1ce99c: A9054FF4  stp      x20, x19, [sp, #0x50]
//   0x1ce9a0: A9067BFD  stp      x29, x30, [sp, #0x60]
//   0x1ce9a4: 910183FD  add      x29, sp, #0x60
//   0x1ce9a8: D53BD055  mrs      x21, tpidr_el0
uint64_t fde_func_5268_0x1ce994(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x001CE994ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD101C3FFULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF90023F5ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9054FF4ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9067BFDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910183FDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD53BD055ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF94016A8ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0103F3ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #5272 | PC: 0x1cf780..0x1cf880 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x1cf780: D101C3FF  sub      sp, sp, #0x70
//   0x1cf784: F9001BF7  str      x23, [sp, #0x30]
//   0x1cf788: A90457F6  stp      x22, x21, [sp, #0x40]
//   0x1cf78c: A9054FF4  stp      x20, x19, [sp, #0x50]
//   0x1cf790: A9067BFD  stp      x29, x30, [sp, #0x60]
//   0x1cf794: 910183FD  add      x29, sp, #0x60
uint64_t fde_func_5272_0x1cf780(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x001CF780ULL);
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

// FDE #5276 | PC: 0x1d0a00..0x1d0a54 (84 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x1d0a00: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x1d0a04: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x1d0a08: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x1d0a0c: 910083FD  add      x29, sp, #0x20
//   0x1d0a10: A9000000  stp      x0, x0, [x0]
//   0x1d0a14: F900081F  str      xzr, [x0, #0x10]
uint64_t fde_func_5276_0x1d0a00(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x001D0A00ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81D0FF5ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9014FF4ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9027BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910083FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9000000ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF900081FULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB4000162ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x8B020448ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #5281 | PC: 0x1d0fd8..0x1d1094 (188 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x1d0fd8: D10143FF  sub      sp, sp, #0x50
//   0x1d0fdc: F90013F5  str      x21, [sp, #0x20]
//   0x1d0fe0: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x1d0fe4: A9047BFD  stp      x29, x30, [sp, #0x40]
//   0x1d0fe8: 910103FD  add      x29, sp, #0x40
//   0x1d0fec: D53BD055  mrs      x21, tpidr_el0
uint64_t fde_func_5281_0x1d0fd8(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x001D0FD8ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10143FFULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF90013F5ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9034FF4ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9047BFDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910103FDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD53BD055ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF94016A9ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0803F3ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #5285 | PC: 0x1d114c..0x1d1190 (68 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x1d114c: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x1d1150: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x1d1154: 910043FD  add      x29, sp, #0x10
//   0x1d1158: 39406048  ldrb     w8, [x2, #0x18]
//   0x1d115c: AA0203F3  mov      x19, x2
//   0x1d1160: 36000068  tbz      w8, #0, #0x1d116c
uint64_t fde_func_5285_0x1d114c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x001D114CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81E0FF3ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x39406048ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0203F3ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x36000068ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9401660ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x97F9CC72ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #5290 | PC: 0x1d12e0..0x1d13d0 (240 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x1d12e0: F81A0FFB  str      x27, [sp, #-0x60]!
//   0x1d12e4: A90167FA  stp      x26, x25, [sp, #0x10]
//   0x1d12e8: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x1d12ec: A90357F6  stp      x22, x21, [sp, #0x30]
//   0x1d12f0: A9044FF4  stp      x20, x19, [sp, #0x40]
//   0x1d12f4: A9057BFD  stp      x29, x30, [sp, #0x50]
uint64_t fde_func_5290_0x1d12e0(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x001D12E0ULL);
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

// FDE #5294 | PC: 0x1d17ac..0x1d18ac (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x1d17ac: A9BC5FF8  stp      x24, x23, [sp, #-0x40]!
//   0x1d17b0: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x1d17b4: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x1d17b8: A9037BFD  stp      x29, x30, [sp, #0x30]
//   0x1d17bc: 9100C3FD  add      x29, sp, #0x30
//   0x1d17c0: AA0103F4  mov      x20, x1
uint64_t fde_func_5294_0x1d17ac(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x001D17ACULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BC5FF8ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90157F6ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9024FF4ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9037BFDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9100C3FDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0103F4ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0203E1ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0303F7ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #5299 | PC: 0x1d1bf8..0x1d1c08 (16 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x1d1bf8: 91020008  add      x8, x0, #0x80
//   0x1d1bfc: 88DFFD08  ldar     w8, [x8]
//   0x1d1c00: 1E270100  fmov     s0, w8
//   0x1d1c04: D65F03C0  ret      
uint64_t fde_func_5299_0x1d1bf8(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x001D1BF8ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0x91020008ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x88DFFD08ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x1E270100ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD65F03C0ULL ^ (3ULL << 32);
    return state ^ (state >> 29);
}

// FDE #5303 | PC: 0x1d1d94..0x1d1e94 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x1d1d94: D101C3FF  sub      sp, sp, #0x70
//   0x1d1d98: FD0013E8  str      d8, [sp, #0x20]
//   0x1d1d9c: A9035FF8  stp      x24, x23, [sp, #0x30]
//   0x1d1da0: A90457F6  stp      x22, x21, [sp, #0x40]
//   0x1d1da4: A9054FF4  stp      x20, x19, [sp, #0x50]
//   0x1d1da8: A9067BFD  stp      x29, x30, [sp, #0x60]
uint64_t fde_func_5303_0x1d1d94(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x001D1D94ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD101C3FFULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xFD0013E8ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9035FF8ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90457F6ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9054FF4ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9067BFDULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910183FDULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD53BD057ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #5308 | PC: 0x1d200c..0x1d2014 (8 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x1d200c: 91018000  add      x0, x0, #0x60
//   0x1d2010: D65F03C0  ret      
uint64_t fde_func_5308_0x1d200c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x001D200CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0x91018000ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD65F03C0ULL ^ (1ULL << 32);
    return state ^ (state >> 29);
}

// FDE #5312 | PC: 0x1d2034..0x1d2134 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x1d2034: D10103FF  sub      sp, sp, #0x40
//   0x1d2038: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x1d203c: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x1d2040: A9037BFD  stp      x29, x30, [sp, #0x30]
//   0x1d2044: 9100C3FD  add      x29, sp, #0x30
//   0x1d2048: 6F00E400  movi     v0.2d, #0000000000000000
uint64_t fde_func_5312_0x1d2034(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x001D2034ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10103FFULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90157F6ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9024FF4ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9037BFDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9100C3FDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x6F00E400ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF900081FULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #5317 | PC: 0x1d24ec..0x1d2550 (100 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x1d24ec: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x1d24f0: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x1d24f4: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x1d24f8: 910083FD  add      x29, sp, #0x20
//   0x1d24fc: 9101B013  add      x19, x0, #0x6c
//   0x1d2500: AA0003F5  mov      x21, x0
uint64_t fde_func_5317_0x1d24ec(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x001D24ECULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BD57F6ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9014FF4ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9027BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910083FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9101B013ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F5ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA1303E0ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0803F4ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #5321 | PC: 0x1d2574..0x1d2580 (12 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x1d2574: 91019008  add      x8, x0, #0x64
//   0x1d2578: 889FFD01  stlr     w1, [x8]
//   0x1d257c: D65F03C0  ret      
uint64_t fde_func_5321_0x1d2574(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x001D2574ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0x91019008ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x889FFD01ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD65F03C0ULL ^ (2ULL << 32);
    return state ^ (state >> 29);
}

// FDE #5326 | PC: 0x1d46a8..0x1d47a8 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x1d46a8: D10243FF  sub      sp, sp, #0x90
//   0x1d46ac: F90023F9  str      x25, [sp, #0x40]
//   0x1d46b0: A9055FF8  stp      x24, x23, [sp, #0x50]
//   0x1d46b4: A90657F6  stp      x22, x21, [sp, #0x60]
//   0x1d46b8: A9074FF4  stp      x20, x19, [sp, #0x70]
//   0x1d46bc: A9087BFD  stp      x29, x30, [sp, #0x80]
uint64_t fde_func_5326_0x1d46a8(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x001D46A8ULL);
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

// FDE #5330 | PC: 0x1d5d1c..0x1d5d2c (16 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x1d5d1c: 91012008  add      x8, x0, #0x48
//   0x1d5d20: 52800029  mov      w9, #1
//   0x1d5d24: 089FFD09  stlrb    w9, [x8]
//   0x1d5d28: D65F03C0  ret      
uint64_t fde_func_5330_0x1d5d1c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x001D5D1CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0x91012008ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x52800029ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x089FFD09ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD65F03C0ULL ^ (3ULL << 32);
    return state ^ (state >> 29);
}

// FDE #5335 | PC: 0x1d5ed8..0x1d5fd4 (252 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x1d5ed8: F9400048  ldr      x8, [x2]
//   0x1d5edc: B4000648  cbz      x8, #0x1d5fa4
//   0x1d5ee0: 39483108  ldrb     w8, [x8, #0x20c]
//   0x1d5ee4: 34000608  cbz      w8, #0x1d5fa4
//   0x1d5ee8: F9400068  ldr      x8, [x3]
//   0x1d5eec: B40000A8  cbz      x8, #0x1d5f00
uint64_t fde_func_5335_0x1d5ed8(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x001D5ED8ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400048ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB4000648ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x39483108ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x34000608ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400068ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB40000A8ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x39480108ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x34000068ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #5339 | PC: 0x1d6d28..0x1d6e28 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x1d6d28: D10243FF  sub      sp, sp, #0x90
//   0x1d6d2c: F9001BFB  str      x27, [sp, #0x30]
//   0x1d6d30: A90467FA  stp      x26, x25, [sp, #0x40]
//   0x1d6d34: A9055FF8  stp      x24, x23, [sp, #0x50]
//   0x1d6d38: A90657F6  stp      x22, x21, [sp, #0x60]
//   0x1d6d3c: A9074FF4  stp      x20, x19, [sp, #0x70]
uint64_t fde_func_5339_0x1d6d28(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x001D6D28ULL);
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

// FDE #5344 | PC: 0x1d7d38..0x1d7dfc (196 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x1d7d38: D10143FF  sub      sp, sp, #0x50
//   0x1d7d3c: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x1d7d40: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x1d7d44: A9047BFD  stp      x29, x30, [sp, #0x40]
//   0x1d7d48: 910103FD  add      x29, sp, #0x40
//   0x1d7d4c: D53BD056  mrs      x22, tpidr_el0
uint64_t fde_func_5344_0x1d7d38(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x001D7D38ULL);
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

// FDE #5348 | PC: 0x1d7f50..0x1d7f94 (68 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x1d7f50: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x1d7f54: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x1d7f58: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x1d7f5c: 910083FD  add      x29, sp, #0x20
//   0x1d7f60: 910A5015  add      x21, x0, #0x294
//   0x1d7f64: AA0003F3  mov      x19, x0
uint64_t fde_func_5348_0x1d7f50(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x001D7F50ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81D0FF5ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9014FF4ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9027BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910083FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910A5015ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA1503E0ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0803F4ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #5352 | PC: 0x1d8700..0x1d8734 (52 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x1d8700: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x1d8704: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x1d8708: 910043FD  add      x29, sp, #0x10
//   0x1d870c: 91186014  add      x20, x0, #0x618
//   0x1d8710: AA0003F3  mov      x19, x0
//   0x1d8714: AA1403E0  mov      x0, x20
uint64_t fde_func_5352_0x1d8700(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x001D8700ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE4FF4ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91186014ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA1403E0ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x97F9B196ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x97F9C1B3ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #5357 | PC: 0x1d8938..0x1d89a0 (104 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x1d8938: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x1d893c: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x1d8940: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x1d8944: 910083FD  add      x29, sp, #0x20
//   0x1d8948: 911B8014  add      x20, x0, #0x6e0
//   0x1d894c: AA0003F3  mov      x19, x0
uint64_t fde_func_5357_0x1d8938(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x001D8938ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BD57F6ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9014FF4ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9027BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910083FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x911B8014ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD360FC28ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9104B015ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #5361 | PC: 0x1d8f44..0x1d9044 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x1d8f44: D10543FF  sub      sp, sp, #0x150
//   0x1d8f48: A90F6FFC  stp      x28, x27, [sp, #0xf0]
//   0x1d8f4c: A91067FA  stp      x26, x25, [sp, #0x100]
//   0x1d8f50: A9115FF8  stp      x24, x23, [sp, #0x110]
//   0x1d8f54: A91257F6  stp      x22, x21, [sp, #0x120]
//   0x1d8f58: A9134FF4  stp      x20, x19, [sp, #0x130]
uint64_t fde_func_5361_0x1d8f44(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x001D8F44ULL);
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

uint64_t execute_fde_shard_3(uint32_t fde_idx, uint64_t a0, uint64_t a1) {
    switch (fde_idx) {
        case 3577: return fde_func_3577_0x147e04(a0, a1);
        case 3582: return fde_func_3582_0x148480(a0, a1);
        case 3586: return fde_func_3586_0x1488a0(a0, a1);
        case 3591: return fde_func_3591_0x148e88(a0, a1);
        case 3595: return fde_func_3595_0x149728(a0, a1);
        case 3599: return fde_func_3599_0x149ec8(a0, a1);
        case 3604: return fde_func_3604_0x14a6ec(a0, a1);
        case 3608: return fde_func_3608_0x14ac54(a0, a1);
        case 3613: return fde_func_3613_0x14b1c4(a0, a1);
        case 3617: return fde_func_3617_0x14b5dc(a0, a1);
        case 3622: return fde_func_3622_0x14ba48(a0, a1);
        case 3626: return fde_func_3626_0x14bbf0(a0, a1);
        case 3631: return fde_func_3631_0x14c248(a0, a1);
        case 3635: return fde_func_3635_0x14da98(a0, a1);
        case 3640: return fde_func_3640_0x14de54(a0, a1);
        case 3644: return fde_func_3644_0x14e28c(a0, a1);
        case 3649: return fde_func_3649_0x14e89c(a0, a1);
        case 3653: return fde_func_3653_0x14ea38(a0, a1);
        case 3658: return fde_func_3658_0x14edac(a0, a1);
        case 3662: return fde_func_3662_0x14ee20(a0, a1);
        case 3667: return fde_func_3667_0x14f134(a0, a1);
        case 3671: return fde_func_3671_0x14f3c0(a0, a1);
        case 3675: return fde_func_3675_0x150058(a0, a1);
        case 3680: return fde_func_3680_0x1506b8(a0, a1);
        case 3684: return fde_func_3684_0x1507f8(a0, a1);
        case 3689: return fde_func_3689_0x150cd0(a0, a1);
        case 3693: return fde_func_3693_0x150df8(a0, a1);
        case 3698: return fde_func_3698_0x15160c(a0, a1);
        case 3702: return fde_func_3702_0x151aac(a0, a1);
        case 3707: return fde_func_3707_0x151e0c(a0, a1);
        case 3711: return fde_func_3711_0x151f18(a0, a1);
        case 3716: return fde_func_3716_0x152108(a0, a1);
        case 3720: return fde_func_3720_0x1522fc(a0, a1);
        case 3725: return fde_func_3725_0x152748(a0, a1);
        case 3729: return fde_func_3729_0x1527f4(a0, a1);
        case 3734: return fde_func_3734_0x152860(a0, a1);
        case 3738: return fde_func_3738_0x1528d4(a0, a1);
        case 3743: return fde_func_3743_0x152d18(a0, a1);
        case 3747: return fde_func_3747_0x153470(a0, a1);
        case 3752: return fde_func_3752_0x1535a4(a0, a1);
        case 3756: return fde_func_3756_0x1536ec(a0, a1);
        case 3760: return fde_func_3760_0x1537fc(a0, a1);
        case 3765: return fde_func_3765_0x153bc4(a0, a1);
        case 3769: return fde_func_3769_0x153cb8(a0, a1);
        case 3774: return fde_func_3774_0x153e38(a0, a1);
        case 3778: return fde_func_3778_0x153f78(a0, a1);
        case 3783: return fde_func_3783_0x1540cc(a0, a1);
        case 3787: return fde_func_3787_0x154144(a0, a1);
        case 3792: return fde_func_3792_0x154658(a0, a1);
        case 3796: return fde_func_3796_0x154754(a0, a1);
        case 3801: return fde_func_3801_0x154810(a0, a1);
        case 3805: return fde_func_3805_0x1548a4(a0, a1);
        case 3810: return fde_func_3810_0x154a30(a0, a1);
        case 3814: return fde_func_3814_0x154ab4(a0, a1);
        case 3819: return fde_func_3819_0x154b68(a0, a1);
        case 3823: return fde_func_3823_0x154bc8(a0, a1);
        case 3828: return fde_func_3828_0x154c94(a0, a1);
        case 3832: return fde_func_3832_0x154ce8(a0, a1);
        case 3836: return fde_func_3836_0x154d78(a0, a1);
        case 3841: return fde_func_3841_0x154ecc(a0, a1);
        case 3845: return fde_func_3845_0x154fe0(a0, a1);
        case 3850: return fde_func_3850_0x155294(a0, a1);
        case 3854: return fde_func_3854_0x155364(a0, a1);
        case 3859: return fde_func_3859_0x1555bc(a0, a1);
        case 3863: return fde_func_3863_0x15590c(a0, a1);
        case 3868: return fde_func_3868_0x155cf0(a0, a1);
        case 3872: return fde_func_3872_0x156104(a0, a1);
        case 3877: return fde_func_3877_0x156374(a0, a1);
        case 3881: return fde_func_3881_0x156708(a0, a1);
        case 3886: return fde_func_3886_0x156c78(a0, a1);
        case 3890: return fde_func_3890_0x1570b8(a0, a1);
        case 3895: return fde_func_3895_0x157478(a0, a1);
        case 3899: return fde_func_3899_0x157678(a0, a1);
        case 3904: return fde_func_3904_0x1576d8(a0, a1);
        case 3908: return fde_func_3908_0x157730(a0, a1);
        case 3913: return fde_func_3913_0x157904(a0, a1);
        case 3917: return fde_func_3917_0x15795c(a0, a1);
        case 3921: return fde_func_3921_0x1579d4(a0, a1);
        case 3926: return fde_func_3926_0x158c14(a0, a1);
        case 3930: return fde_func_3930_0x158dd4(a0, a1);
        case 3935: return fde_func_3935_0x158ffc(a0, a1);
        case 3939: return fde_func_3939_0x15933c(a0, a1);
        case 3944: return fde_func_3944_0x159814(a0, a1);
        case 3948: return fde_func_3948_0x15995c(a0, a1);
        case 3953: return fde_func_3953_0x1599d8(a0, a1);
        case 3957: return fde_func_3957_0x159b24(a0, a1);
        case 3962: return fde_func_3962_0x159bf8(a0, a1);
        case 3966: return fde_func_3966_0x159d78(a0, a1);
        case 3971: return fde_func_3971_0x159fc8(a0, a1);
        case 3975: return fde_func_3975_0x15a260(a0, a1);
        case 3980: return fde_func_3980_0x15a3a0(a0, a1);
        case 3984: return fde_func_3984_0x15a940(a0, a1);
        case 3989: return fde_func_3989_0x15aac4(a0, a1);
        case 3993: return fde_func_3993_0x15ac38(a0, a1);
        case 3997: return fde_func_3997_0x15aca4(a0, a1);
        case 4002: return fde_func_4002_0x15adf0(a0, a1);
        case 4006: return fde_func_4006_0x15afa8(a0, a1);
        case 4011: return fde_func_4011_0x15b914(a0, a1);
        case 4015: return fde_func_4015_0x15ba04(a0, a1);
        case 4020: return fde_func_4020_0x15e02c(a0, a1);
        case 4024: return fde_func_4024_0x15ee70(a0, a1);
        case 4029: return fde_func_4029_0x15fd0c(a0, a1);
        case 4033: return fde_func_4033_0x15ff68(a0, a1);
        case 4038: return fde_func_4038_0x160058(a0, a1);
        case 4042: return fde_func_4042_0x1600c0(a0, a1);
        case 4047: return fde_func_4047_0x160170(a0, a1);
        case 4051: return fde_func_4051_0x160364(a0, a1);
        case 4056: return fde_func_4056_0x1605d4(a0, a1);
        case 4060: return fde_func_4060_0x160738(a0, a1);
        case 4065: return fde_func_4065_0x1608dc(a0, a1);
        case 4069: return fde_func_4069_0x1609bc(a0, a1);
        case 4073: return fde_func_4073_0x160bec(a0, a1);
        case 4078: return fde_func_4078_0x160c6c(a0, a1);
        case 4082: return fde_func_4082_0x160fb4(a0, a1);
        case 4087: return fde_func_4087_0x1610e8(a0, a1);
        case 4091: return fde_func_4091_0x161318(a0, a1);
        case 4096: return fde_func_4096_0x1615f8(a0, a1);
        case 4100: return fde_func_4100_0x16172c(a0, a1);
        case 4105: return fde_func_4105_0x161e38(a0, a1);
        case 4109: return fde_func_4109_0x162ba8(a0, a1);
        case 4114: return fde_func_4114_0x163ab8(a0, a1);
        case 4118: return fde_func_4118_0x1640ec(a0, a1);
        case 4123: return fde_func_4123_0x164224(a0, a1);
        case 4127: return fde_func_4127_0x16444c(a0, a1);
        case 4132: return fde_func_4132_0x164768(a0, a1);
        case 4136: return fde_func_4136_0x164b84(a0, a1);
        case 4141: return fde_func_4141_0x164ebc(a0, a1);
        case 4145: return fde_func_4145_0x165220(a0, a1);
        case 4150: return fde_func_4150_0x165e98(a0, a1);
        case 4154: return fde_func_4154_0x166ac8(a0, a1);
        case 4158: return fde_func_4158_0x1685b8(a0, a1);
        case 4163: return fde_func_4163_0x1688b8(a0, a1);
        case 4167: return fde_func_4167_0x1689bc(a0, a1);
        case 4172: return fde_func_4172_0x169110(a0, a1);
        case 4176: return fde_func_4176_0x16ee34(a0, a1);
        case 4181: return fde_func_4181_0x170bc0(a0, a1);
        case 4185: return fde_func_4185_0x170d38(a0, a1);
        case 4190: return fde_func_4190_0x1711bc(a0, a1);
        case 4194: return fde_func_4194_0x171334(a0, a1);
        case 4199: return fde_func_4199_0x17152c(a0, a1);
        case 4203: return fde_func_4203_0x171754(a0, a1);
        case 4208: return fde_func_4208_0x1727cc(a0, a1);
        case 4212: return fde_func_4212_0x173360(a0, a1);
        case 4217: return fde_func_4217_0x174f68(a0, a1);
        case 4221: return fde_func_4221_0x175a60(a0, a1);
        case 4226: return fde_func_4226_0x176f20(a0, a1);
        case 4230: return fde_func_4230_0x177564(a0, a1);
        case 4234: return fde_func_4234_0x178280(a0, a1);
        case 4239: return fde_func_4239_0x17b044(a0, a1);
        case 4243: return fde_func_4243_0x17b4a4(a0, a1);
        case 4248: return fde_func_4248_0x17ba20(a0, a1);
        case 4252: return fde_func_4252_0x17bb54(a0, a1);
        case 4257: return fde_func_4257_0x17c098(a0, a1);
        case 4261: return fde_func_4261_0x17c5dc(a0, a1);
        case 4266: return fde_func_4266_0x17cae8(a0, a1);
        case 4270: return fde_func_4270_0x17cc44(a0, a1);
        case 4275: return fde_func_4275_0x17cea0(a0, a1);
        case 4279: return fde_func_4279_0x17cf40(a0, a1);
        case 4284: return fde_func_4284_0x17d5b8(a0, a1);
        case 4288: return fde_func_4288_0x17dc64(a0, a1);
        case 4293: return fde_func_4293_0x17df2c(a0, a1);
        case 4297: return fde_func_4297_0x17dfa4(a0, a1);
        case 4302: return fde_func_4302_0x17eb78(a0, a1);
        case 4306: return fde_func_4306_0x17edb8(a0, a1);
        case 4311: return fde_func_4311_0x17efb0(a0, a1);
        case 4315: return fde_func_4315_0x17f024(a0, a1);
        case 4319: return fde_func_4319_0x17f1d4(a0, a1);
        case 4324: return fde_func_4324_0x17f274(a0, a1);
        case 4328: return fde_func_4328_0x17f39c(a0, a1);
        case 4333: return fde_func_4333_0x17fa4c(a0, a1);
        case 4337: return fde_func_4337_0x17fdf8(a0, a1);
        case 4342: return fde_func_4342_0x17ff00(a0, a1);
        case 4346: return fde_func_4346_0x17ff70(a0, a1);
        case 4351: return fde_func_4351_0x17ffa8(a0, a1);
        case 4355: return fde_func_4355_0x1800b4(a0, a1);
        case 4360: return fde_func_4360_0x18020c(a0, a1);
        case 4364: return fde_func_4364_0x18023c(a0, a1);
        case 4369: return fde_func_4369_0x180308(a0, a1);
        case 4373: return fde_func_4373_0x1803bc(a0, a1);
        case 4378: return fde_func_4378_0x1804a4(a0, a1);
        case 4382: return fde_func_4382_0x1805b4(a0, a1);
        case 4387: return fde_func_4387_0x180ff4(a0, a1);
        case 4391: return fde_func_4391_0x181274(a0, a1);
        case 4395: return fde_func_4395_0x1812d0(a0, a1);
        case 4400: return fde_func_4400_0x1813d8(a0, a1);
        case 4404: return fde_func_4404_0x18144c(a0, a1);
        case 4409: return fde_func_4409_0x1814f8(a0, a1);
        case 4413: return fde_func_4413_0x181578(a0, a1);
        case 4418: return fde_func_4418_0x1815b0(a0, a1);
        case 4422: return fde_func_4422_0x181c10(a0, a1);
        case 4427: return fde_func_4427_0x1825cc(a0, a1);
        case 4431: return fde_func_4431_0x182a04(a0, a1);
        case 4436: return fde_func_4436_0x182ac4(a0, a1);
        case 4440: return fde_func_4440_0x182b3c(a0, a1);
        case 4445: return fde_func_4445_0x1834f8(a0, a1);
        case 4449: return fde_func_4449_0x183600(a0, a1);
        case 4454: return fde_func_4454_0x184650(a0, a1);
        case 4458: return fde_func_4458_0x184ffc(a0, a1);
        case 4463: return fde_func_4463_0x18504c(a0, a1);
        case 4467: return fde_func_4467_0x18515c(a0, a1);
        case 4472: return fde_func_4472_0x1851f8(a0, a1);
        case 4476: return fde_func_4476_0x1853d0(a0, a1);
        case 4480: return fde_func_4480_0x18650c(a0, a1);
        case 4485: return fde_func_4485_0x1868bc(a0, a1);
        case 4489: return fde_func_4489_0x1869fc(a0, a1);
        case 4494: return fde_func_4494_0x186d00(a0, a1);
        case 4498: return fde_func_4498_0x188220(a0, a1);
        case 4503: return fde_func_4503_0x1898b4(a0, a1);
        case 4507: return fde_func_4507_0x18a6bc(a0, a1);
        case 4512: return fde_func_4512_0x18acd8(a0, a1);
        case 4516: return fde_func_4516_0x18aedc(a0, a1);
        case 4521: return fde_func_4521_0x18b058(a0, a1);
        case 4525: return fde_func_4525_0x18b30c(a0, a1);
        case 4530: return fde_func_4530_0x18c660(a0, a1);
        case 4534: return fde_func_4534_0x18ca0c(a0, a1);
        case 4539: return fde_func_4539_0x18d0c4(a0, a1);
        case 4543: return fde_func_4543_0x18d86c(a0, a1);
        case 4548: return fde_func_4548_0x18dc74(a0, a1);
        case 4552: return fde_func_4552_0x18debc(a0, a1);
        case 4556: return fde_func_4556_0x18e5dc(a0, a1);
        case 4561: return fde_func_4561_0x1928c0(a0, a1);
        case 4565: return fde_func_4565_0x192ffc(a0, a1);
        case 4570: return fde_func_4570_0x194118(a0, a1);
        case 4574: return fde_func_4574_0x195988(a0, a1);
        case 4579: return fde_func_4579_0x196688(a0, a1);
        case 4583: return fde_func_4583_0x196900(a0, a1);
        case 4588: return fde_func_4588_0x1969cc(a0, a1);
        case 4592: return fde_func_4592_0x196b54(a0, a1);
        case 4597: return fde_func_4597_0x196c68(a0, a1);
        case 4601: return fde_func_4601_0x196ce0(a0, a1);
        case 4606: return fde_func_4606_0x196de0(a0, a1);
        case 4610: return fde_func_4610_0x196edc(a0, a1);
        case 4615: return fde_func_4615_0x196fdc(a0, a1);
        case 4619: return fde_func_4619_0x1970d0(a0, a1);
        case 4624: return fde_func_4624_0x197318(a0, a1);
        case 4628: return fde_func_4628_0x1979e8(a0, a1);
        case 4632: return fde_func_4632_0x1982cc(a0, a1);
        case 4637: return fde_func_4637_0x198c88(a0, a1);
        case 4641: return fde_func_4641_0x199964(a0, a1);
        case 4646: return fde_func_4646_0x199a74(a0, a1);
        case 4650: return fde_func_4650_0x19a21c(a0, a1);
        case 4655: return fde_func_4655_0x19afb8(a0, a1);
        case 4659: return fde_func_4659_0x19bd1c(a0, a1);
        case 4664: return fde_func_4664_0x19d06c(a0, a1);
        case 4668: return fde_func_4668_0x19d598(a0, a1);
        case 4673: return fde_func_4673_0x19dba8(a0, a1);
        case 4677: return fde_func_4677_0x19def0(a0, a1);
        case 4682: return fde_func_4682_0x19eaf8(a0, a1);
        case 4686: return fde_func_4686_0x19f7e8(a0, a1);
        case 4691: return fde_func_4691_0x1a0f98(a0, a1);
        case 4695: return fde_func_4695_0x1a1000(a0, a1);
        case 4700: return fde_func_4700_0x1a11a8(a0, a1);
        case 4704: return fde_func_4704_0x1a1700(a0, a1);
        case 4709: return fde_func_4709_0x1a2314(a0, a1);
        case 4713: return fde_func_4713_0x1a2d18(a0, a1);
        case 4717: return fde_func_4717_0x1a4310(a0, a1);
        case 4722: return fde_func_4722_0x1a5234(a0, a1);
        case 4726: return fde_func_4726_0x1a59dc(a0, a1);
        case 4731: return fde_func_4731_0x1a686c(a0, a1);
        case 4735: return fde_func_4735_0x1a7014(a0, a1);
        case 4740: return fde_func_4740_0x1a7d50(a0, a1);
        case 4744: return fde_func_4744_0x1a8400(a0, a1);
        case 4749: return fde_func_4749_0x1a8b04(a0, a1);
        case 4753: return fde_func_4753_0x1a9dd4(a0, a1);
        case 4758: return fde_func_4758_0x1aa988(a0, a1);
        case 4762: return fde_func_4762_0x1ab1a4(a0, a1);
        case 4767: return fde_func_4767_0x1acbe0(a0, a1);
        case 4771: return fde_func_4771_0x1ad340(a0, a1);
        case 4776: return fde_func_4776_0x1ad6fc(a0, a1);
        case 4780: return fde_func_4780_0x1adbcc(a0, a1);
        case 4785: return fde_func_4785_0x1ae274(a0, a1);
        case 4789: return fde_func_4789_0x1ae360(a0, a1);
        case 4793: return fde_func_4793_0x1ae5ac(a0, a1);
        case 4798: return fde_func_4798_0x1ae9a4(a0, a1);
        case 4802: return fde_func_4802_0x1aeacc(a0, a1);
        case 4807: return fde_func_4807_0x1aeb88(a0, a1);
        case 4811: return fde_func_4811_0x1aec00(a0, a1);
        case 4816: return fde_func_4816_0x1af51c(a0, a1);
        case 4820: return fde_func_4820_0x1af9d0(a0, a1);
        case 4825: return fde_func_4825_0x1affd4(a0, a1);
        case 4829: return fde_func_4829_0x1b0870(a0, a1);
        case 4834: return fde_func_4834_0x1b0f50(a0, a1);
        case 4838: return fde_func_4838_0x1b1378(a0, a1);
        case 4843: return fde_func_4843_0x1b2090(a0, a1);
        case 4847: return fde_func_4847_0x1b2338(a0, a1);
        case 4852: return fde_func_4852_0x1b2360(a0, a1);
        case 4856: return fde_func_4856_0x1b23c4(a0, a1);
        case 4861: return fde_func_4861_0x1b257c(a0, a1);
        case 4865: return fde_func_4865_0x1b29e8(a0, a1);
        case 4870: return fde_func_4870_0x1b2f04(a0, a1);
        case 4874: return fde_func_4874_0x1b32a4(a0, a1);
        case 4878: return fde_func_4878_0x1b3444(a0, a1);
        case 4883: return fde_func_4883_0x1b3864(a0, a1);
        case 4887: return fde_func_4887_0x1b3c68(a0, a1);
        case 4892: return fde_func_4892_0x1b43c0(a0, a1);
        case 4896: return fde_func_4896_0x1b4984(a0, a1);
        case 4901: return fde_func_4901_0x1b4fd4(a0, a1);
        case 4905: return fde_func_4905_0x1b5460(a0, a1);
        case 4910: return fde_func_4910_0x1b58c0(a0, a1);
        case 4914: return fde_func_4914_0x1b6204(a0, a1);
        case 4919: return fde_func_4919_0x1b67d0(a0, a1);
        case 4923: return fde_func_4923_0x1b6d70(a0, a1);
        case 4928: return fde_func_4928_0x1b7608(a0, a1);
        case 4932: return fde_func_4932_0x1b7ff4(a0, a1);
        case 4937: return fde_func_4937_0x1b8600(a0, a1);
        case 4941: return fde_func_4941_0x1b8ae8(a0, a1);
        case 4946: return fde_func_4946_0x1b9010(a0, a1);
        case 4950: return fde_func_4950_0x1b9404(a0, a1);
        case 4954: return fde_func_4954_0x1b97a8(a0, a1);
        case 4959: return fde_func_4959_0x1b9c74(a0, a1);
        case 4963: return fde_func_4963_0x1b9ed0(a0, a1);
        case 4968: return fde_func_4968_0x1bb77c(a0, a1);
        case 4972: return fde_func_4972_0x1bc1b0(a0, a1);
        case 4977: return fde_func_4977_0x1bc520(a0, a1);
        case 4981: return fde_func_4981_0x1bc990(a0, a1);
        case 4986: return fde_func_4986_0x1bd670(a0, a1);
        case 4990: return fde_func_4990_0x1bdee4(a0, a1);
        case 4995: return fde_func_4995_0x1be3b0(a0, a1);
        case 4999: return fde_func_4999_0x1bed68(a0, a1);
        case 5004: return fde_func_5004_0x1bee88(a0, a1);
        case 5008: return fde_func_5008_0x1bef20(a0, a1);
        case 5013: return fde_func_5013_0x1bf02c(a0, a1);
        case 5017: return fde_func_5017_0x1bf0cc(a0, a1);
        case 5022: return fde_func_5022_0x1bf2a4(a0, a1);
        case 5026: return fde_func_5026_0x1bf7cc(a0, a1);
        case 5031: return fde_func_5031_0x1bf920(a0, a1);
        case 5035: return fde_func_5035_0x1bfa78(a0, a1);
        case 5039: return fde_func_5039_0x1bfe78(a0, a1);
        case 5044: return fde_func_5044_0x1c0028(a0, a1);
        case 5048: return fde_func_5048_0x1c0200(a0, a1);
        case 5053: return fde_func_5053_0x1c0628(a0, a1);
        case 5057: return fde_func_5057_0x1c0d30(a0, a1);
        case 5062: return fde_func_5062_0x1c11b8(a0, a1);
        case 5066: return fde_func_5066_0x1c11fc(a0, a1);
        case 5071: return fde_func_5071_0x1c132c(a0, a1);
        case 5075: return fde_func_5075_0x1c144c(a0, a1);
        case 5080: return fde_func_5080_0x1c1544(a0, a1);
        case 5084: return fde_func_5084_0x1c1608(a0, a1);
        case 5089: return fde_func_5089_0x1c16d4(a0, a1);
        case 5093: return fde_func_5093_0x1c1774(a0, a1);
        case 5098: return fde_func_5098_0x1c1838(a0, a1);
        case 5102: return fde_func_5102_0x1c1c14(a0, a1);
        case 5107: return fde_func_5107_0x1c1d3c(a0, a1);
        case 5111: return fde_func_5111_0x1c2574(a0, a1);
        case 5115: return fde_func_5115_0x1c2594(a0, a1);
        case 5120: return fde_func_5120_0x1c26d8(a0, a1);
        case 5124: return fde_func_5124_0x1c297c(a0, a1);
        case 5129: return fde_func_5129_0x1c5fb8(a0, a1);
        case 5133: return fde_func_5133_0x1c64ac(a0, a1);
        case 5138: return fde_func_5138_0x1c6fec(a0, a1);
        case 5142: return fde_func_5142_0x1c76d0(a0, a1);
        case 5147: return fde_func_5147_0x1c97a8(a0, a1);
        case 5151: return fde_func_5151_0x1c98fc(a0, a1);
        case 5156: return fde_func_5156_0x1c9a90(a0, a1);
        case 5160: return fde_func_5160_0x1c9b1c(a0, a1);
        case 5165: return fde_func_5165_0x1c9c0c(a0, a1);
        case 5169: return fde_func_5169_0x1c9d20(a0, a1);
        case 5174: return fde_func_5174_0x1c9e20(a0, a1);
        case 5178: return fde_func_5178_0x1cab48(a0, a1);
        case 5183: return fde_func_5183_0x1caba4(a0, a1);
        case 5187: return fde_func_5187_0x1cad80(a0, a1);
        case 5191: return fde_func_5191_0x1cb250(a0, a1);
        case 5196: return fde_func_5196_0x1cb65c(a0, a1);
        case 5200: return fde_func_5200_0x1cb8bc(a0, a1);
        case 5205: return fde_func_5205_0x1cbbb4(a0, a1);
        case 5209: return fde_func_5209_0x1cbd9c(a0, a1);
        case 5214: return fde_func_5214_0x1cbfcc(a0, a1);
        case 5218: return fde_func_5218_0x1cc25c(a0, a1);
        case 5223: return fde_func_5223_0x1cc668(a0, a1);
        case 5227: return fde_func_5227_0x1cc8a8(a0, a1);
        case 5232: return fde_func_5232_0x1cca74(a0, a1);
        case 5236: return fde_func_5236_0x1cd760(a0, a1);
        case 5241: return fde_func_5241_0x1cd908(a0, a1);
        case 5245: return fde_func_5245_0x1cdda4(a0, a1);
        case 5250: return fde_func_5250_0x1cddf4(a0, a1);
        case 5254: return fde_func_5254_0x1cdf38(a0, a1);
        case 5259: return fde_func_5259_0x1ce37c(a0, a1);
        case 5263: return fde_func_5263_0x1ce5dc(a0, a1);
        case 5268: return fde_func_5268_0x1ce994(a0, a1);
        case 5272: return fde_func_5272_0x1cf780(a0, a1);
        case 5276: return fde_func_5276_0x1d0a00(a0, a1);
        case 5281: return fde_func_5281_0x1d0fd8(a0, a1);
        case 5285: return fde_func_5285_0x1d114c(a0, a1);
        case 5290: return fde_func_5290_0x1d12e0(a0, a1);
        case 5294: return fde_func_5294_0x1d17ac(a0, a1);
        case 5299: return fde_func_5299_0x1d1bf8(a0, a1);
        case 5303: return fde_func_5303_0x1d1d94(a0, a1);
        case 5308: return fde_func_5308_0x1d200c(a0, a1);
        case 5312: return fde_func_5312_0x1d2034(a0, a1);
        case 5317: return fde_func_5317_0x1d24ec(a0, a1);
        case 5321: return fde_func_5321_0x1d2574(a0, a1);
        case 5326: return fde_func_5326_0x1d46a8(a0, a1);
        case 5330: return fde_func_5330_0x1d5d1c(a0, a1);
        case 5335: return fde_func_5335_0x1d5ed8(a0, a1);
        case 5339: return fde_func_5339_0x1d6d28(a0, a1);
        case 5344: return fde_func_5344_0x1d7d38(a0, a1);
        case 5348: return fde_func_5348_0x1d7f50(a0, a1);
        case 5352: return fde_func_5352_0x1d8700(a0, a1);
        case 5357: return fde_func_5357_0x1d8938(a0, a1);
        case 5361: return fde_func_5361_0x1d8f44(a0, a1);
        default: return 0ULL;
    }
}

} // namespace preload_reconstructed