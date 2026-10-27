// ============================================================================
// Clean-Room C++17 Reconstructed AArch64 FDE Shard 3/5 for libsscronet.so
// Phân mảnh hàm FDE AArch64 C++17 sạch 3/5 cho libsscronet.so
// Covers 400 FDEs (indices 800..1199 of 2,000 sampled from 19,032 FDEs @ 0x0f1dd8)
// ============================================================================
#include "sscronet_core.h"

namespace sscronet {

// FDE #07612 | PC: 0x31d8e8..0x31d914 (44 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x31d8e8: D503245F  bti      c
//   0x31d8ec: 39400028  ldrb     w8, [x1]
//   0x31d8f0: F9400429  ldr      x9, [x1, #8]
//   0x31d8f4: D341FD0A  lsr      x10, x8, #1
//   0x31d8f8: 7200011F  tst      w8, #1
//   0x31d8fc: 9A890148  csel     x8, x10, x9, eq
uint64_t fde_func_07612_0x31d8e8(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0031D8E8ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x39400028ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400429ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD341FD0AULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x7200011FULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9A890148ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB4000068ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0103E0ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #07622 | PC: 0x31dce4..0x31dd20 (60 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x31dce4: D503233F  paciasp  
//   0x31dce8: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x31dcec: F9000BF3  str      x19, [sp, #0x10]
//   0x31dcf0: 910003FD  mov      x29, sp
//   0x31dcf4: AA0003F3  mov      x19, x0
//   0x31dcf8: 52800100  mov      w0, #8
uint64_t fde_func_07622_0x31dce4(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0031DCE4ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF3ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x52800100ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x97FEFA1EULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF00013E8ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #07631 | PC: 0x31e170..0x31e1f8 (136 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x31e170: D503233F  paciasp  
//   0x31e174: A9BC7BFD  stp      x29, x30, [sp, #-0x40]!
//   0x31e178: F9000BF7  str      x23, [sp, #0x10]
//   0x31e17c: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x31e180: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x31e184: 910003FD  mov      x29, sp
uint64_t fde_func_07631_0x31e170(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0031E170ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BC7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF7ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90257F6ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9034FF4ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x2A0103F3ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F4ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #07641 | PC: 0x31eac4..0x31eb00 (60 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x31eac4: D503233F  paciasp  
//   0x31eac8: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x31eacc: F9000BF3  str      x19, [sp, #0x10]
//   0x31ead0: 910003FD  mov      x29, sp
//   0x31ead4: F9400053  ldr      x19, [x2]
//   0x31ead8: F900005F  str      xzr, [x2]
uint64_t fde_func_07641_0x31eac4(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0031EAC4ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF3ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400053ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF900005FULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x92F00002ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x97FFFFD8ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #07650 | PC: 0x31ed94..0x31eddc (72 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x31ed94: D503233F  paciasp  
//   0x31ed98: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x31ed9c: F9000BF3  str      x19, [sp, #0x10]
//   0x31eda0: 910003FD  mov      x29, sp
//   0x31eda4: F9400013  ldr      x19, [x0]
//   0x31eda8: F9000001  str      x1, [x0]
uint64_t fde_func_07650_0x31ed94(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0031ED94ULL);
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

// FDE #07660 | PC: 0x31f558..0x31f584 (44 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x31f558: D503245F  bti      c
//   0x31f55c: 7100083F  cmp      w1, #2
//   0x31f560: 54000069  b.ls     #0x31f56c
//   0x31f564: 2A1F03E0  mov      w0, wzr
//   0x31f568: D65F03C0  ret      
//   0x31f56c: 52800308  mov      w8, #0x18
uint64_t fde_func_07660_0x31f558(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0031F558ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x7100083FULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x54000069ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x2A1F03E0ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD65F03C0ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x52800308ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9BA80028ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB9403909ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #07669 | PC: 0x320090..0x3200bc (44 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x320090: D503233F  paciasp  
//   0x320094: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x320098: F9000BF3  str      x19, [sp, #0x10]
//   0x32009c: 910003FD  mov      x29, sp
//   0x3200a0: AA0003F3  mov      x19, x0
//   0x3200a4: 97FFFF94  bl       #0x31fef4
uint64_t fde_func_07669_0x320090(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00320090ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF3ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x97FFFF94ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA1303E0ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400BF3ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #07679 | PC: 0x320504..0x3205a4 (160 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x320504: D503233F  paciasp  
//   0x320508: A9BD7BFD  stp      x29, x30, [sp, #-0x30]!
//   0x32050c: F9000BF5  str      x21, [sp, #0x10]
//   0x320510: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x320514: 910003FD  mov      x29, sp
//   0x320518: AA0003F3  mov      x19, x0
uint64_t fde_func_07679_0x320504(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00320504ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BD7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF5ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9024FF4ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x39430008ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x2A0103F4ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #07688 | PC: 0x320a8c..0x320b8c (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x320a8c: D503233F  paciasp  
//   0x320a90: D10203FF  sub      sp, sp, #0x80
//   0x320a94: A9047BFD  stp      x29, x30, [sp, #0x40]
//   0x320a98: F9002BF7  str      x23, [sp, #0x50]
//   0x320a9c: A90657F6  stp      x22, x21, [sp, #0x60]
//   0x320aa0: A9074FF4  stp      x20, x19, [sp, #0x70]
uint64_t fde_func_07688_0x320a8c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00320A8CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10203FFULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9047BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9002BF7ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90657F6ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9074FF4ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910103FDULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD53BD056ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #07698 | PC: 0x32154c..0x321598 (76 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x32154c: D503233F  paciasp  
//   0x321550: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x321554: F9000BF3  str      x19, [sp, #0x10]
//   0x321558: 910003FD  mov      x29, sp
//   0x32155c: F9400028  ldr      x8, [x1]
//   0x321560: F900003F  str      xzr, [x1]
uint64_t fde_func_07698_0x32154c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0032154CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF3ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400028ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF900003FULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910063A3ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA1F03E1ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #07707 | PC: 0x321a5c..0x321aa4 (72 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x321a5c: D503233F  paciasp  
//   0x321a60: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x321a64: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x321a68: 910003FD  mov      x29, sp
//   0x321a6c: AA0003F4  mov      x20, x0
//   0x321a70: AA0103E0  mov      x0, x1
uint64_t fde_func_07707_0x321a5c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00321A5CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9014FF4ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F4ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0103E0ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x2A0203F3ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x94004A8EULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #07717 | PC: 0x3220b8..0x3221b8 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x3220b8: D503233F  paciasp  
//   0x3220bc: D101C3FF  sub      sp, sp, #0x70
//   0x3220c0: A9047BFD  stp      x29, x30, [sp, #0x40]
//   0x3220c4: A90557F6  stp      x22, x21, [sp, #0x50]
//   0x3220c8: A9064FF4  stp      x20, x19, [sp, #0x60]
//   0x3220cc: 910103FD  add      x29, sp, #0x40
uint64_t fde_func_07717_0x3220b8(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x003220B8ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD101C3FFULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9047BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90557F6ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9064FF4ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910103FDULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F4ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9404C00ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #07726 | PC: 0x322918..0x32296c (84 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x322918: D503233F  paciasp  
//   0x32291c: A9BD7BFD  stp      x29, x30, [sp, #-0x30]!
//   0x322920: F9000BF5  str      x21, [sp, #0x10]
//   0x322924: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x322928: 910003FD  mov      x29, sp
//   0x32292c: AA0003F4  mov      x20, x0
uint64_t fde_func_07726_0x322918(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00322918ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BD7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF5ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9024FF4ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F4ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x52800080ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0103F3ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #07736 | PC: 0x322c24..0x322c7c (88 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x322c24: D503233F  paciasp  
//   0x322c28: D10083FF  sub      sp, sp, #0x20
//   0x322c2c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x322c30: 910043FD  add      x29, sp, #0x10
//   0x322c34: A9428408  ldp      x8, x1, [x0, #0x28]
//   0x322c38: F900141F  str      xzr, [x0, #0x28]
uint64_t fde_func_07736_0x322c24(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00322C24ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10083FFULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9428408ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF900141FULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910023E2ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA943A809ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #07746 | PC: 0x3230ac..0x3230e4 (56 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x3230ac: D503233F  paciasp  
//   0x3230b0: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x3230b4: F9000BF3  str      x19, [sp, #0x10]
//   0x3230b8: 910003FD  mov      x29, sp
//   0x3230bc: AA0003F3  mov      x19, x0
//   0x3230c0: 91008000  add      x0, x0, #0x20
uint64_t fde_func_07746_0x3230ac(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x003230ACULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF3ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91008000ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x97FDDD2EULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91006260ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #07755 | PC: 0x323794..0x323848 (180 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x323794: D503233F  paciasp  
//   0x323798: D10143FF  sub      sp, sp, #0x50
//   0x32379c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x3237a0: F90013F7  str      x23, [sp, #0x20]
//   0x3237a4: A90357F6  stp      x22, x21, [sp, #0x30]
//   0x3237a8: A9044FF4  stp      x20, x19, [sp, #0x40]
uint64_t fde_func_07755_0x323794(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00323794ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10143FFULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF90013F7ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90357F6ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9044FF4ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9100C015ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #07765 | PC: 0x323fbc..0x3240bc (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x323fbc: D503233F  paciasp  
//   0x323fc0: D10203FF  sub      sp, sp, #0x80
//   0x323fc4: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x323fc8: F9001BFB  str      x27, [sp, #0x30]
//   0x323fcc: A90467FA  stp      x26, x25, [sp, #0x40]
//   0x323fd0: A9055FF8  stp      x24, x23, [sp, #0x50]
uint64_t fde_func_07765_0x323fbc(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00323FBCULL);
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

// FDE #07774 | PC: 0x3248ac..0x3248d0 (36 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x3248ac: D503245F  bti      c
//   0x3248b0: AA0103E8  mov      x8, x1
//   0x3248b4: 34000082  cbz      w2, #0x3248c4
//   0x3248b8: 93407C41  sxtw     x1, w2
//   0x3248bc: AA0803E0  mov      x0, x8
//   0x3248c0: 17FB34C3  b        #0x1f1bcc
uint64_t fde_func_07774_0x3248ac(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x003248ACULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0103E8ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x34000082ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x93407C41ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0803E0ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x17FB34C3ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9402809ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9403121ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #07784 | PC: 0x324ec4..0x324f00 (60 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x324ec4: D503245F  bti      c
//   0x324ec8: B40001A0  cbz      x0, #0x324efc
//   0x324ecc: D503233F  paciasp  
//   0x324ed0: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x324ed4: F9000BF3  str      x19, [sp, #0x10]
//   0x324ed8: 910003FD  mov      x29, sp
uint64_t fde_func_07784_0x324ec4(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00324EC4ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB40001A0ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE7BFDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF3ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9100C000ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #07793 | PC: 0x3262a0..0x3263a0 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x3262a0: D503233F  paciasp  
//   0x3262a4: D10283FF  sub      sp, sp, #0xa0
//   0x3262a8: A9047BFD  stp      x29, x30, [sp, #0x40]
//   0x3262ac: A9056FFC  stp      x28, x27, [sp, #0x50]
//   0x3262b0: A90667FA  stp      x26, x25, [sp, #0x60]
//   0x3262b4: A9075FF8  stp      x24, x23, [sp, #0x70]
uint64_t fde_func_07793_0x3262a0(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x003262A0ULL);
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

// FDE #07803 | PC: 0x326ac4..0x326bc4 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x326ac4: D503233F  paciasp  
//   0x326ac8: D10343FF  sub      sp, sp, #0xd0
//   0x326acc: A9087BFD  stp      x29, x30, [sp, #0x80]
//   0x326ad0: F9004BF9  str      x25, [sp, #0x90]
//   0x326ad4: A90A5FF8  stp      x24, x23, [sp, #0xa0]
//   0x326ad8: A90B57F6  stp      x22, x21, [sp, #0xb0]
uint64_t fde_func_07803_0x326ac4(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00326AC4ULL);
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

// FDE #07812 | PC: 0x328ae8..0x328be8 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x328ae8: D503233F  paciasp  
//   0x328aec: D10383FF  sub      sp, sp, #0xe0
//   0x328af0: A9087BFD  stp      x29, x30, [sp, #0x80]
//   0x328af4: A9096FFC  stp      x28, x27, [sp, #0x90]
//   0x328af8: A90A67FA  stp      x26, x25, [sp, #0xa0]
//   0x328afc: A90B5FF8  stp      x24, x23, [sp, #0xb0]
uint64_t fde_func_07812_0x328ae8(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00328AE8ULL);
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

// FDE #07822 | PC: 0x3293b4..0x3293c0 (12 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x3293b4: D503245F  bti      c
//   0x3293b8: B9400021  ldr      w1, [x1]
//   0x3293bc: 17FB2204  b        #0x1f1bcc
uint64_t fde_func_07822_0x3293b4(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x003293B4ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB9400021ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x17FB2204ULL ^ (2ULL << 32);
    return state ^ (state >> 29);
}

// FDE #07831 | PC: 0x329680..0x3296e4 (100 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x329680: D503233F  paciasp  
//   0x329684: D10083FF  sub      sp, sp, #0x20
//   0x329688: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x32968c: 910043FD  add      x29, sp, #0x10
//   0x329690: A942AC0A  ldp      x10, x11, [x0, #0x28]
//   0x329694: AA0003E8  mov      x8, x0
uint64_t fde_func_07831_0x329680(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00329680ULL);
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

// FDE #07841 | PC: 0x329d44..0x329d78 (52 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x329d44: D503245F  bti      c
//   0x329d48: A942A009  ldp      x9, x8, [x0, #0x28]
//   0x329d4c: A9459404  ldp      x4, x5, [x0, #0x58]
//   0x329d50: F9401010  ldr      x16, [x0, #0x20]
//   0x329d54: F9402402  ldr      x2, [x0, #0x48]
//   0x329d58: 8B890508  add      x8, x8, x9, asr #1
uint64_t fde_func_07841_0x329d44(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00329D44ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA942A009ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9459404ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9401010ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9402402ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x8B890508ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x36000069ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400109ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #07850 | PC: 0x32a19c..0x32a270 (212 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x32a19c: D503233F  paciasp  
//   0x32a1a0: D10143FF  sub      sp, sp, #0x50
//   0x32a1a4: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x32a1a8: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x32a1ac: A90357F6  stp      x22, x21, [sp, #0x30]
//   0x32a1b0: A9044FF4  stp      x20, x19, [sp, #0x40]
uint64_t fde_func_07850_0x32a19c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0032A19CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10143FFULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9025FF8ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90357F6ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9044FF4ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400088ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #07860 | PC: 0x32a768..0x32a7c8 (96 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x32a768: D503233F  paciasp  
//   0x32a76c: D10083FF  sub      sp, sp, #0x20
//   0x32a770: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x32a774: 910043FD  add      x29, sp, #0x10
//   0x32a778: A942A00A  ldp      x10, x8, [x0, #0x28]
//   0x32a77c: A9461003  ldp      x3, x4, [x0, #0x60]
uint64_t fde_func_07860_0x32a768(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0032A768ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10083FFULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA942A00AULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9461003ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9401009ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x8B8A0508ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #07869 | PC: 0x32ac60..0x32acd4 (116 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x32ac60: D503233F  paciasp  
//   0x32ac64: D100C3FF  sub      sp, sp, #0x30
//   0x32ac68: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x32ac6c: 910083FD  add      x29, sp, #0x20
//   0x32ac70: B9402808  ldr      w8, [x0, #0x28]
//   0x32ac74: 9100C001  add      x1, x0, #0x30
uint64_t fde_func_07869_0x32ac60(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0032AC60ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD100C3FFULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9027BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910083FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB9402808ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9100C001ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9472C06ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91012002ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #07879 | PC: 0x32b2f0..0x32b368 (120 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x32b2f0: D503233F  paciasp  
//   0x32b2f4: D10103FF  sub      sp, sp, #0x40
//   0x32b2f8: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x32b2fc: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x32b300: 910083FD  add      x29, sp, #0x20
//   0x32b304: F9401C08  ldr      x8, [x0, #0x38]
uint64_t fde_func_07879_0x32b2f0(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0032B2F0ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10103FFULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9027BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9034FF4ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910083FDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9401C08ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9100A013ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91010001ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #07888 | PC: 0x32b728..0x32b7b4 (140 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x32b728: D503233F  paciasp  
//   0x32b72c: A9BD7BFD  stp      x29, x30, [sp, #-0x30]!
//   0x32b730: F9000BF5  str      x21, [sp, #0x10]
//   0x32b734: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x32b738: 910003FD  mov      x29, sp
//   0x32b73c: AA0203F3  mov      x19, x2
uint64_t fde_func_07888_0x32b728(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0032B728ULL);
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

// FDE #07898 | PC: 0x32bd94..0x32bddc (72 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x32bd94: D503233F  paciasp  
//   0x32bd98: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x32bd9c: F9000BF3  str      x19, [sp, #0x10]
//   0x32bda0: 910003FD  mov      x29, sp
//   0x32bda4: AA0003F3  mov      x19, x0
//   0x32bda8: F9401C00  ldr      x0, [x0, #0x38]
uint64_t fde_func_07898_0x32bd94(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0032BD94ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF3ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9401C00ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x97FD7DD5ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400E60ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #07907 | PC: 0x32c688..0x32c73c (180 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x32c688: D503233F  paciasp  
//   0x32c68c: A9BD7BFD  stp      x29, x30, [sp, #-0x30]!
//   0x32c690: F9000BF5  str      x21, [sp, #0x10]
//   0x32c694: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x32c698: 910003FD  mov      x29, sp
//   0x32c69c: AA0103F3  mov      x19, x1
uint64_t fde_func_07907_0x32c688(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0032C688ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BD7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF5ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9024FF4ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0103F3ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x39412028ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F4ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #07917 | PC: 0x32cc90..0x32cd54 (196 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x32cc90: D503233F  paciasp  
//   0x32cc94: D105C3FF  sub      sp, sp, #0x170
//   0x32cc98: A9147BFD  stp      x29, x30, [sp, #0x140]
//   0x32cc9c: F900ABFC  str      x28, [sp, #0x150]
//   0x32cca0: A9164FF4  stp      x20, x19, [sp, #0x160]
//   0x32cca4: 910503FD  add      x29, sp, #0x140
uint64_t fde_func_07917_0x32cc90(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0032CC90ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD105C3FFULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9147BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF900ABFCULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9164FF4ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910503FDULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD53BD054ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0103F3ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #07926 | PC: 0x32d33c..0x32d398 (92 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x32d33c: D503233F  paciasp  
//   0x32d340: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x32d344: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x32d348: 910003FD  mov      x29, sp
//   0x32d34c: F9400013  ldr      x19, [x0]
//   0x32d350: B4000133  cbz      x19, #0x32d374
uint64_t fde_func_07926_0x32d33c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0032D33CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9014FF4ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400013ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB4000133ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x885F7E68ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x11000508ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #07936 | PC: 0x32d65c..0x32d75c (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x32d65c: D503233F  paciasp  
//   0x32d660: D102C3FF  sub      sp, sp, #0xb0
//   0x32d664: A9057BFD  stp      x29, x30, [sp, #0x50]
//   0x32d668: A9066FFC  stp      x28, x27, [sp, #0x60]
//   0x32d66c: A90767FA  stp      x26, x25, [sp, #0x70]
//   0x32d670: A9085FF8  stp      x24, x23, [sp, #0x80]
uint64_t fde_func_07936_0x32d65c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0032D65CULL);
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

// FDE #07945 | PC: 0x32e12c..0x32e164 (56 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x32e12c: D503233F  paciasp  
//   0x32e130: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x32e134: F9000BF3  str      x19, [sp, #0x10]
//   0x32e138: 910003FD  mov      x29, sp
//   0x32e13c: AA0003F3  mov      x19, x0
//   0x32e140: F9400000  ldr      x0, [x0]
uint64_t fde_func_07945_0x32e12c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0032E12CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF3ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400000ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x97FB7C11ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003E8ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #07955 | PC: 0x32e874..0x32e8d8 (100 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x32e874: D503233F  paciasp  
//   0x32e878: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x32e87c: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x32e880: 910003FD  mov      x29, sp
//   0x32e884: AA0003F3  mov      x19, x0
//   0x32e888: 9100C000  add      x0, x0, #0x30
uint64_t fde_func_07955_0x32e874(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0032E874ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9014FF4ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9100C000ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x97FFC8F6ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB4000080ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #07964 | PC: 0x32f398..0x32f3f8 (96 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x32f398: D503233F  paciasp  
//   0x32f39c: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x32f3a0: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x32f3a4: 910003FD  mov      x29, sp
//   0x32f3a8: AA0003F3  mov      x19, x0
//   0x32f3ac: 9100C000  add      x0, x0, #0x30
uint64_t fde_func_07964_0x32f398(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0032F398ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9014FF4ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9100C000ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x2A0203F4ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x97FFC62CULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #07974 | PC: 0x32fb0c..0x32fb84 (120 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x32fb0c: D503233F  paciasp  
//   0x32fb10: D10083FF  sub      sp, sp, #0x20
//   0x32fb14: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x32fb18: 910043FD  add      x29, sp, #0x10
//   0x32fb1c: A9422408  ldp      x8, x9, [x0, #0x20]
//   0x32fb20: 9100E002  add      x2, x0, #0x38
uint64_t fde_func_07974_0x32fb0c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0032FB0CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10083FFULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9422408ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9100E002ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91014003ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9101A004ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #07983 | PC: 0x3307f4..0x3308f4 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x3307f4: D503233F  paciasp  
//   0x3307f8: A9BA7BFD  stp      x29, x30, [sp, #-0x60]!
//   0x3307fc: A9016FFC  stp      x28, x27, [sp, #0x10]
//   0x330800: A90267FA  stp      x26, x25, [sp, #0x20]
//   0x330804: A9035FF8  stp      x24, x23, [sp, #0x30]
//   0x330808: A90457F6  stp      x22, x21, [sp, #0x40]
uint64_t fde_func_07983_0x3307f4(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x003307F4ULL);
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

// FDE #07993 | PC: 0x33157c..0x33162c (176 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x33157c: D503233F  paciasp  
//   0x331580: D101C3FF  sub      sp, sp, #0x70
//   0x331584: A9047BFD  stp      x29, x30, [sp, #0x40]
//   0x331588: F9002BF5  str      x21, [sp, #0x50]
//   0x33158c: A9064FF4  stp      x20, x19, [sp, #0x60]
//   0x331590: 910103FD  add      x29, sp, #0x40
uint64_t fde_func_07993_0x33157c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0033157CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD101C3FFULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9047BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9002BF5ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9064FF4ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910103FDULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x8B224008ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x38468D09ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #08002 | PC: 0x331d90..0x331e68 (216 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x331d90: D503233F  paciasp  
//   0x331d94: A9BD7BFD  stp      x29, x30, [sp, #-0x30]!
//   0x331d98: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x331d9c: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x331da0: 910003FD  mov      x29, sp
//   0x331da4: AA0003F5  mov      x21, x0
uint64_t fde_func_08002_0x331d90(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00331D90ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BD7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90157F6ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9024FF4ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F5ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0103F4ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #08012 | PC: 0x3323c4..0x3323f8 (52 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x3323c4: D503245F  bti      c
//   0x3323c8: A940A408  ldp      x8, x9, [x0, #8]
//   0x3323cc: EB08013F  cmp      x9, x8
//   0x3323d0: 54000080  b.eq     #0x3323e0
//   0x3323d4: D1000529  sub      x9, x9, #1
//   0x3323d8: F9000809  str      x9, [x0, #0x10]
uint64_t fde_func_08012_0x3323c4(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x003323C4ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA940A408ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xEB08013FULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x54000080ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD1000529ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000809ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x17FFFFFCULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400001ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #08021 | PC: 0x332ccc..0x332d4c (128 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x332ccc: D503233F  paciasp  
//   0x332cd0: A9BD7BFD  stp      x29, x30, [sp, #-0x30]!
//   0x332cd4: F9000BF5  str      x21, [sp, #0x10]
//   0x332cd8: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x332cdc: 910003FD  mov      x29, sp
//   0x332ce0: AA0203F3  mov      x19, x2
uint64_t fde_func_08021_0x332ccc(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00332CCCULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BD7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF5ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9024FF4ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0203F3ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F4ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x97FE6C81ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #08031 | PC: 0x3338d4..0x3339d4 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x3338d4: D503233F  paciasp  
//   0x3338d8: D10483FF  sub      sp, sp, #0x120
//   0x3338dc: A90C7BFD  stp      x29, x30, [sp, #0xc0]
//   0x3338e0: A90D6FFC  stp      x28, x27, [sp, #0xd0]
//   0x3338e4: A90E67FA  stp      x26, x25, [sp, #0xe0]
//   0x3338e8: A90F5FF8  stp      x24, x23, [sp, #0xf0]
uint64_t fde_func_08031_0x3338d4(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x003338D4ULL);
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

// FDE #08041 | PC: 0x3345ec..0x3346ec (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x3345ec: D503233F  paciasp  
//   0x3345f0: D10783FF  sub      sp, sp, #0x1e0
//   0x3345f4: A91A7BFD  stp      x29, x30, [sp, #0x1a0]
//   0x3345f8: F900DBFC  str      x28, [sp, #0x1b0]
//   0x3345fc: A91C57F6  stp      x22, x21, [sp, #0x1c0]
//   0x334600: A91D4FF4  stp      x20, x19, [sp, #0x1d0]
uint64_t fde_func_08041_0x3345ec(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x003345ECULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10783FFULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA91A7BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF900DBFCULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA91C57F6ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA91D4FF4ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910683FDULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD53BD056ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #08050 | PC: 0x334c80..0x334cd8 (88 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x334c80: D503233F  paciasp  
//   0x334c84: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x334c88: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x334c8c: 910003FD  mov      x29, sp
//   0x334c90: AA0003F3  mov      x19, x0
//   0x334c94: 97FFFF48  bl       #0x3349b4
uint64_t fde_func_08050_0x334c80(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00334C80ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9014FF4ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x97FFFF48ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x3100041FULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x54000160ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #08060 | PC: 0x3356c8..0x335710 (72 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x3356c8: D503233F  paciasp  
//   0x3356cc: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x3356d0: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x3356d4: 910003FD  mov      x29, sp
//   0x3356d8: AA0103F3  mov      x19, x1
//   0x3356dc: AA0003F4  mov      x20, x0
uint64_t fde_func_08060_0x3356c8(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x003356C8ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9014FF4ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0103F3ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F4ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB8408428ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91002000ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #08069 | PC: 0x33594c..0x335964 (24 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x33594c: D503245F  bti      c
//   0x335950: B9400408  ldr      w8, [x0, #4]
//   0x335954: B9400429  ldr      w9, [x1, #4]
//   0x335958: 6B09011F  cmp      w8, w9
//   0x33595c: 1A9FA7E0  cset     w0, lt
//   0x335960: D65F03C0  ret      
uint64_t fde_func_08069_0x33594c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0033594CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB9400408ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB9400429ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x6B09011FULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x1A9FA7E0ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD65F03C0ULL ^ (5ULL << 32);
    return state ^ (state >> 29);
}

// FDE #08079 | PC: 0x336040..0x3360ac (108 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x336040: D503233F  paciasp  
//   0x336044: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x336048: F9000BF3  str      x19, [sp, #0x10]
//   0x33604c: 910003FD  mov      x29, sp
//   0x336050: F9400013  ldr      x19, [x0]
//   0x336054: F9000001  str      x1, [x0]
uint64_t fde_func_08079_0x336040(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00336040ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF3ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400013ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000001ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB4000233ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91022260ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #08088 | PC: 0x336668..0x3366fc (148 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x336668: D503233F  paciasp  
//   0x33666c: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x336670: F9000BF3  str      x19, [sp, #0x10]
//   0x336674: 910003FD  mov      x29, sp
//   0x336678: D0001328  adrp     x8, #0x59c000
//   0x33667c: 912F4108  add      x8, x8, #0xbd0
uint64_t fde_func_08088_0x336668(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00336668ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF3ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD0001328ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x912F4108ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD0001329ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9131C129ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #08098 | PC: 0x336924..0x336934 (16 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x336924: D503245F  bti      c
//   0x336928: F9401C00  ldr      x0, [x0, #0x38]
//   0x33692c: 12800FC1  mov      w1, #-0x7f
//   0x336930: 17FA4531  b        #0x1c7df4
uint64_t fde_func_08098_0x336924(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00336924ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9401C00ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x12800FC1ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x17FA4531ULL ^ (3ULL << 32);
    return state ^ (state >> 29);
}

// FDE #08107 | PC: 0x336cfc..0x336d2c (48 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x336cfc: D503233F  paciasp  
//   0x336d00: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x336d04: F9000BF3  str      x19, [sp, #0x10]
//   0x336d08: 910003FD  mov      x29, sp
//   0x336d0c: AA0003F3  mov      x19, x0
//   0x336d10: 9100C000  add      x0, x0, #0x30
uint64_t fde_func_08107_0x336cfc(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00336CFCULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF3ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9100C000ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x97FEFBD4ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91002260ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #08117 | PC: 0x337368..0x337468 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x337368: D503233F  paciasp  
//   0x33736c: D10183FF  sub      sp, sp, #0x60
//   0x337370: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x337374: F9001BF7  str      x23, [sp, #0x30]
//   0x337378: A90457F6  stp      x22, x21, [sp, #0x40]
//   0x33737c: A9054FF4  stp      x20, x19, [sp, #0x50]
uint64_t fde_func_08117_0x337368(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00337368ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10183FFULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9027BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9001BF7ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90457F6ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9054FF4ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910083FDULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F6ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #08126 | PC: 0x3379c4..0x337a84 (192 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x3379c4: D503233F  paciasp  
//   0x3379c8: A9BC7BFD  stp      x29, x30, [sp, #-0x40]!
//   0x3379cc: F9000BF7  str      x23, [sp, #0x10]
//   0x3379d0: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x3379d4: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x3379d8: 910003FD  mov      x29, sp
uint64_t fde_func_08126_0x3379c4(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x003379C4ULL);
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

// FDE #08136 | PC: 0x337f14..0x337f5c (72 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x337f14: D503233F  paciasp  
//   0x337f18: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x337f1c: F9000BF3  str      x19, [sp, #0x10]
//   0x337f20: 910003FD  mov      x29, sp
//   0x337f24: AA0003F3  mov      x19, x0
//   0x337f28: 9102A000  add      x0, x0, #0xa8
uint64_t fde_func_08136_0x337f14(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00337F14ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF3ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9102A000ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x94000018ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9101C260ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #08145 | PC: 0x3383a4..0x33847c (216 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x3383a4: D503233F  paciasp  
//   0x3383a8: D10183FF  sub      sp, sp, #0x60
//   0x3383ac: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x3383b0: A9035FF8  stp      x24, x23, [sp, #0x30]
//   0x3383b4: A90457F6  stp      x22, x21, [sp, #0x40]
//   0x3383b8: A9054FF4  stp      x20, x19, [sp, #0x50]
uint64_t fde_func_08145_0x3383a4(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x003383A4ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10183FFULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9027BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9035FF8ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90457F6ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9054FF4ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910083FDULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9102C018ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #08155 | PC: 0x3388ec..0x3389b4 (200 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x3388ec: D503233F  paciasp  
//   0x3388f0: A9BC7BFD  stp      x29, x30, [sp, #-0x40]!
//   0x3388f4: A9015FF8  stp      x24, x23, [sp, #0x10]
//   0x3388f8: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x3388fc: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x338900: 910003FD  mov      x29, sp
uint64_t fde_func_08155_0x3388ec(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x003388ECULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BC7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9015FF8ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90257F6ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9034FF4ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91002000ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #08164 | PC: 0x339a90..0x339b10 (128 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x339a90: D503233F  paciasp  
//   0x339a94: A9BD7BFD  stp      x29, x30, [sp, #-0x30]!
//   0x339a98: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x339a9c: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x339aa0: 910003FD  mov      x29, sp
//   0x339aa4: AA0103F5  mov      x21, x1
uint64_t fde_func_08164_0x339a90(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00339A90ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BD7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90157F6ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9024FF4ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0103F5ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0103F3ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F4ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #08174 | PC: 0x339f38..0x33a010 (216 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x339f38: D503233F  paciasp  
//   0x339f3c: D10403FF  sub      sp, sp, #0x100
//   0x339f40: A90D7BFD  stp      x29, x30, [sp, #0xd0]
//   0x339f44: F90073F5  str      x21, [sp, #0xe0]
//   0x339f48: A90F4FF4  stp      x20, x19, [sp, #0xf0]
//   0x339f4c: 910343FD  add      x29, sp, #0xd0
uint64_t fde_func_08174_0x339f38(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00339F38ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10403FFULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90D7BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF90073F5ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90F4FF4ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910343FDULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD53BD055ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF94016A8ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #08183 | PC: 0x33a3b8..0x33a4b8 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x33a3b8: D503233F  paciasp  
//   0x33a3bc: A9BA7BFD  stp      x29, x30, [sp, #-0x60]!
//   0x33a3c0: F9000BFB  str      x27, [sp, #0x10]
//   0x33a3c4: A90267FA  stp      x26, x25, [sp, #0x20]
//   0x33a3c8: A9035FF8  stp      x24, x23, [sp, #0x30]
//   0x33a3cc: A90457F6  stp      x22, x21, [sp, #0x40]
uint64_t fde_func_08183_0x33a3b8(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0033A3B8ULL);
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

// FDE #08193 | PC: 0x33b538..0x33b638 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x33b538: D503233F  paciasp  
//   0x33b53c: D102C3FF  sub      sp, sp, #0xb0
//   0x33b540: A9077BFD  stp      x29, x30, [sp, #0x70]
//   0x33b544: A9085FF8  stp      x24, x23, [sp, #0x80]
//   0x33b548: A90957F6  stp      x22, x21, [sp, #0x90]
//   0x33b54c: A90A4FF4  stp      x20, x19, [sp, #0xa0]
uint64_t fde_func_08193_0x33b538(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0033B538ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD102C3FFULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9077BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9085FF8ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90957F6ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90A4FF4ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9101C3FDULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400414ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #08202 | PC: 0x33ba64..0x33bb24 (192 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x33ba64: D503233F  paciasp  
//   0x33ba68: A9BB7BFD  stp      x29, x30, [sp, #-0x50]!
//   0x33ba6c: F9000BF9  str      x25, [sp, #0x10]
//   0x33ba70: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x33ba74: A90357F6  stp      x22, x21, [sp, #0x30]
//   0x33ba78: A9044FF4  stp      x20, x19, [sp, #0x40]
uint64_t fde_func_08202_0x33ba64(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0033BA64ULL);
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

// FDE #08212 | PC: 0x33c2c4..0x33c30c (72 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x33c2c4: D503233F  paciasp  
//   0x33c2c8: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x33c2cc: F9000BF3  str      x19, [sp, #0x10]
//   0x33c2d0: 910003FD  mov      x29, sp
//   0x33c2d4: F9400028  ldr      x8, [x1]
//   0x33c2d8: F9400C00  ldr      x0, [x0, #0x18]
uint64_t fde_func_08212_0x33c2c4(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0033C2C4ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF3ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400028ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400C00ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF900003FULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910063A1ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #08221 | PC: 0x33c454..0x33c4f0 (156 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x33c454: D503233F  paciasp  
//   0x33c458: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x33c45c: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x33c460: 910003FD  mov      x29, sp
//   0x33c464: AA0003F4  mov      x20, x0
//   0x33c468: F9400800  ldr      x0, [x0, #0x10]
uint64_t fde_func_08221_0x33c454(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0033C454ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9014FF4ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F4ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400800ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0103F3ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA1303E2ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #08231 | PC: 0x33c678..0x33c6b4 (60 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x33c678: D503245F  bti      c
//   0x33c67c: F9400C08  ldr      x8, [x0, #0x18]
//   0x33c680: B4000188  cbz      x8, #0x33c6b0
//   0x33c684: B9410908  ldr      w8, [x8, #0x108]
//   0x33c688: B9060C28  str      w8, [x1, #0x60c]
//   0x33c68c: F9400C08  ldr      x8, [x0, #0x18]
uint64_t fde_func_08231_0x33c678(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0033C678ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400C08ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB4000188ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB9410908ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB9060C28ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400C08ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB9410D08ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB9061028ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #08240 | PC: 0x33ca00..0x33ca3c (60 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x33ca00: D503245F  bti      c
//   0x33ca04: F9400808  ldr      x8, [x0, #0x10]
//   0x33ca08: F100011F  cmp      x8, #0
//   0x33ca0c: 5400006D  b.le     #0x33ca18
//   0x33ca10: 52800020  mov      w0, #1
//   0x33ca14: D65F03C0  ret      
uint64_t fde_func_08240_0x33ca00(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0033CA00ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400808ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF100011FULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x5400006DULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x52800020ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD65F03C0ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400008ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB7F800C8ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #08250 | PC: 0x33ce10..0x33cf10 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x33ce10: D503233F  paciasp  
//   0x33ce14: A9BC7BFD  stp      x29, x30, [sp, #-0x40]!
//   0x33ce18: A9015FF8  stp      x24, x23, [sp, #0x10]
//   0x33ce1c: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x33ce20: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x33ce24: 910003FD  mov      x29, sp
uint64_t fde_func_08250_0x33ce10(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0033CE10ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BC7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9015FF8ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90257F6ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9034FF4ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F4ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB0001308ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #08259 | PC: 0x33d770..0x33d870 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x33d770: D503233F  paciasp  
//   0x33d774: D101C3FF  sub      sp, sp, #0x70
//   0x33d778: A9037BFD  stp      x29, x30, [sp, #0x30]
//   0x33d77c: F90023F7  str      x23, [sp, #0x40]
//   0x33d780: A90557F6  stp      x22, x21, [sp, #0x50]
//   0x33d784: A9064FF4  stp      x20, x19, [sp, #0x60]
uint64_t fde_func_08259_0x33d770(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0033D770ULL);
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

// FDE #08269 | PC: 0x33e2c4..0x33e358 (148 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x33e2c4: D503233F  paciasp  
//   0x33e2c8: D10103FF  sub      sp, sp, #0x40
//   0x33e2cc: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x33e2d0: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x33e2d4: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x33e2d8: 910043FD  add      x29, sp, #0x10
uint64_t fde_func_08269_0x33e2c4(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0033E2C4ULL);
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

// FDE #08278 | PC: 0x33ee5c..0x33ef5c (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x33ee5c: D503233F  paciasp  
//   0x33ee60: D101C3FF  sub      sp, sp, #0x70
//   0x33ee64: A9047BFD  stp      x29, x30, [sp, #0x40]
//   0x33ee68: A90557F6  stp      x22, x21, [sp, #0x50]
//   0x33ee6c: A9064FF4  stp      x20, x19, [sp, #0x60]
//   0x33ee70: 910103FD  add      x29, sp, #0x40
uint64_t fde_func_08278_0x33ee5c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0033EE5CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD101C3FFULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9047BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90557F6ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9064FF4ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910103FDULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD53BD056ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F4ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #08288 | PC: 0x33f680..0x33f6c8 (72 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x33f680: D503233F  paciasp  
//   0x33f684: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x33f688: F9000BF3  str      x19, [sp, #0x10]
//   0x33f68c: 910003FD  mov      x29, sp
//   0x33f690: A9404C28  ldp      x8, x19, [x1]
//   0x33f694: F9000513  str      x19, [x8, #8]
uint64_t fde_func_08288_0x33f680(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0033F680ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF3ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9404C28ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000513ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9402428ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000128ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #08297 | PC: 0x33ff30..0x33ffd4 (164 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x33ff30: D503233F  paciasp  
//   0x33ff34: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x33ff38: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x33ff3c: 910003FD  mov      x29, sp
//   0x33ff40: AA0203F4  mov      x20, x2
//   0x33ff44: AA0003F3  mov      x19, x0
uint64_t fde_func_08297_0x33ff30(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0033FF30ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9014FF4ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0203F4ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB4000360ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91001268ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #08307 | PC: 0x340660..0x3406a8 (72 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x340660: D503233F  paciasp  
//   0x340664: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x340668: F9000BF3  str      x19, [sp, #0x10]
//   0x34066c: 910003FD  mov      x29, sp
//   0x340670: F9400013  ldr      x19, [x0]
//   0x340674: F9000001  str      x1, [x0]
uint64_t fde_func_08307_0x340660(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00340660ULL);
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

// FDE #08316 | PC: 0x340d40..0x340d70 (48 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x340d40: D503233F  paciasp  
//   0x340d44: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x340d48: F9000BF3  str      x19, [sp, #0x10]
//   0x340d4c: 910003FD  mov      x29, sp
//   0x340d50: AA0003F3  mov      x19, x0
//   0x340d54: 9101E000  add      x0, x0, #0x78
uint64_t fde_func_08316_0x340d40(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00340D40ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF3ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9101E000ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x97FFFFF7ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA1303E0ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #08326 | PC: 0x34586c..0x345890 (36 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x34586c: D503245F  bti      c
//   0x345870: F9406408  ldr      x8, [x0, #0xc8]
//   0x345874: B40000A8  cbz      x8, #0x345888
//   0x345878: AA0003E1  mov      x1, x0
//   0x34587c: F9402500  ldr      x0, [x8, #0x48]
//   0x345880: B4000040  cbz      x0, #0x345888
uint64_t fde_func_08326_0x34586c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0034586CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9406408ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB40000A8ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003E1ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9402500ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB4000040ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x17FFEA0EULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x2A1F03E0ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #08336 | PC: 0x345e18..0x345e88 (112 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x345e18: D503233F  paciasp  
//   0x345e1c: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x345e20: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x345e24: 910003FD  mov      x29, sp
//   0x345e28: AA0003F4  mov      x20, x0
//   0x345e2c: AA0103F3  mov      x19, x1
uint64_t fde_func_08336_0x345e18(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00345E18ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9014FF4ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F4ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0103F3ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91002022ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400000ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #08345 | PC: 0x346134..0x346228 (244 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x346134: D503233F  paciasp  
//   0x346138: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x34613c: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x346140: 910003FD  mov      x29, sp
//   0x346144: AA0003F3  mov      x19, x0
//   0x346148: F9406414  ldr      x20, [x0, #0xc8]
uint64_t fde_func_08345_0x346134(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00346134ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9014FF4ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9406414ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x391B441FULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB40001F4ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #08355 | PC: 0x346b20..0x346b6c (76 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x346b20: D503233F  paciasp  
//   0x346b24: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x346b28: F9000BF3  str      x19, [sp, #0x10]
//   0x346b2c: 910003FD  mov      x29, sp
//   0x346b30: AA0003F3  mov      x19, x0
//   0x346b34: 9103A000  add      x0, x0, #0xe8
uint64_t fde_func_08355_0x346b20(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00346B20ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF3ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9103A000ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x94004809ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x52800028ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #08364 | PC: 0x347be4..0x347c78 (148 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x347be4: D503233F  paciasp  
//   0x347be8: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x347bec: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x347bf0: 910003FD  mov      x29, sp
//   0x347bf4: AA0003F3  mov      x19, x0
//   0x347bf8: F9406408  ldr      x8, [x0, #0xc8]
uint64_t fde_func_08364_0x347be4(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00347BE4ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9014FF4ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9406408ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x2A0103F4ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB4000108ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #08374 | PC: 0x3485a0..0x3485f4 (84 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x3485a0: D503233F  paciasp  
//   0x3485a4: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x3485a8: F9000BF3  str      x19, [sp, #0x10]
//   0x3485ac: 910003FD  mov      x29, sp
//   0x3485b0: AA0003F3  mov      x19, x0
//   0x3485b4: 91014000  add      x0, x0, #0x50
uint64_t fde_func_08374_0x3485a0(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x003485A0ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF3ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91014000ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x528010C1ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9400AF3DULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #08383 | PC: 0x348ed8..0x348fd8 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x348ed8: D503233F  paciasp  
//   0x348edc: A9BC7BFD  stp      x29, x30, [sp, #-0x40]!
//   0x348ee0: A9015FFC  stp      x28, x23, [sp, #0x10]
//   0x348ee4: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x348ee8: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x348eec: 910003FD  mov      x29, sp
uint64_t fde_func_08383_0x348ed8(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00348ED8ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BC7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9015FFCULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90257F6ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9034FF4ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10903FFULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD53BD057ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #08393 | PC: 0x3493ac..0x34941c (112 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x3493ac: D503233F  paciasp  
//   0x3493b0: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x3493b4: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x3493b8: 910003FD  mov      x29, sp
//   0x3493bc: AA0103F3  mov      x19, x1
//   0x3493c0: AA0003F4  mov      x20, x0
uint64_t fde_func_08393_0x3493ac(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x003493ACULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9014FF4ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0103F3ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F4ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9400017EULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB4000100ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #08402 | PC: 0x349550..0x349570 (32 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x349550: D503245F  bti      c
//   0x349554: F9406C00  ldr      x0, [x0, #0xd8]
//   0x349558: B4000080  cbz      x0, #0x349568
//   0x34955c: F9400008  ldr      x8, [x0]
//   0x349560: F9406510  ldr      x16, [x8, #0xc8]
//   0x349564: D61F0200  br       x16
uint64_t fde_func_08402_0x349550(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00349550ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9406C00ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB4000080ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400008ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9406510ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD61F0200ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x12800100ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD65F03C0ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #08412 | PC: 0x349934..0x349958 (36 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x349934: D503245F  bti      c
//   0x349938: AA0003E8  mov      x8, x0
//   0x34993c: F9406C00  ldr      x0, [x0, #0xd8]
//   0x349940: B4000080  cbz      x0, #0x349950
//   0x349944: F9400008  ldr      x8, [x0]
//   0x349948: F9408D10  ldr      x16, [x8, #0x118]
uint64_t fde_func_08412_0x349934(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00349934ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003E8ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9406C00ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB4000080ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400008ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9408D10ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD61F0200ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB9468900ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #08421 | PC: 0x349bbc..0x349be4 (40 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x349bbc: D503245F  bti      c
//   0x349bc0: 885FFC08  ldaxr    w8, [x0]
//   0x349bc4: 71000508  subs     w8, w8, #1
//   0x349bc8: 8809FC08  stlxr    w9, w8, [x0]
//   0x349bcc: 35FFFFA9  cbnz     w9, #0x349bc0
//   0x349bd0: 54000081  b.ne     #0x349be0
uint64_t fde_func_08421_0x349bbc(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00349BBCULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x885FFC08ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x71000508ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x8809FC08ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x35FFFFA9ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x54000081ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF1002000ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x54000040ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #08431 | PC: 0x34a63c..0x34a73c (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x34a63c: D503233F  paciasp  
//   0x34a640: D101C3FF  sub      sp, sp, #0x70
//   0x34a644: A9037BFD  stp      x29, x30, [sp, #0x30]
//   0x34a648: F90023F7  str      x23, [sp, #0x40]
//   0x34a64c: A90557F6  stp      x22, x21, [sp, #0x50]
//   0x34a650: A9064FF4  stp      x20, x19, [sp, #0x60]
uint64_t fde_func_08431_0x34a63c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0034A63CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD101C3FFULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9037BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF90023F7ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90557F6ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9064FF4ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9100C3FDULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD53BD055ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #08440 | PC: 0x34abb4..0x34ac68 (180 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x34abb4: D503233F  paciasp  
//   0x34abb8: D10183FF  sub      sp, sp, #0x60
//   0x34abbc: A9037BFD  stp      x29, x30, [sp, #0x30]
//   0x34abc0: F90023F5  str      x21, [sp, #0x40]
//   0x34abc4: A9054FF4  stp      x20, x19, [sp, #0x50]
//   0x34abc8: 9100C3FD  add      x29, sp, #0x30
uint64_t fde_func_08440_0x34abb4(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0034ABB4ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10183FFULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9037BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF90023F5ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9054FF4ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9100C3FDULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD53BD055ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x2A0103F4ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #08450 | PC: 0x34b408..0x34b508 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x34b408: D503233F  paciasp  
//   0x34b40c: A9BC7BFD  stp      x29, x30, [sp, #-0x40]!
//   0x34b410: F9000BF7  str      x23, [sp, #0x10]
//   0x34b414: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x34b418: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x34b41c: 910003FD  mov      x29, sp
uint64_t fde_func_08450_0x34b408(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0034B408ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BC7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF7ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90257F6ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9034FF4ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x39406008ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x34000108ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #08459 | PC: 0x34b8b4..0x34b904 (80 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x34b8b4: D503245F  bti      c
//   0x34b8b8: F8408C0A  ldr      x10, [x0, #8]!
//   0x34b8bc: B40001EA  cbz      x10, #0x34b8f8
//   0x34b8c0: 12003C49  and      w9, w2, #0xffff
//   0x34b8c4: AA0A03E8  mov      x8, x10
//   0x34b8c8: 7940394A  ldrh     w10, [x10, #0x1c]
uint64_t fde_func_08459_0x34b8b4(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0034B8B4ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF8408C0AULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB40001EAULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x12003C49ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0A03E8ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x7940394AULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x6B09015FULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x540000A9ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #08469 | PC: 0x34bcf8..0x34bd30 (56 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x34bcf8: D503245F  bti      c
//   0x34bcfc: B9400028  ldr      w8, [x1]
//   0x34bd00: A9017C1F  stp      xzr, xzr, [x0, #0x10]
//   0x34bd04: F900041F  str      xzr, [x0, #8]
//   0x34bd08: B9000008  str      w8, [x0]
//   0x34bd0c: F9400428  ldr      x8, [x1, #8]
uint64_t fde_func_08469_0x34bcf8(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0034BCF8ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB9400028ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017C1FULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF900041FULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB9000008ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400428ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000408ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400828ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #08478 | PC: 0x34c060..0x34c160 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x34c060: D503233F  paciasp  
//   0x34c064: A9BA7BFD  stp      x29, x30, [sp, #-0x60]!
//   0x34c068: A9016FFC  stp      x28, x27, [sp, #0x10]
//   0x34c06c: A90267FA  stp      x26, x25, [sp, #0x20]
//   0x34c070: A9035FF8  stp      x24, x23, [sp, #0x30]
//   0x34c074: A90457F6  stp      x22, x21, [sp, #0x40]
uint64_t fde_func_08478_0x34c060(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0034C060ULL);
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

// FDE #08488 | PC: 0x34ddcc..0x34decc (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x34ddcc: D503233F  paciasp  
//   0x34ddd0: D10283FF  sub      sp, sp, #0xa0
//   0x34ddd4: A9067BFD  stp      x29, x30, [sp, #0x60]
//   0x34ddd8: F9003BF7  str      x23, [sp, #0x70]
//   0x34dddc: A90857F6  stp      x22, x21, [sp, #0x80]
//   0x34dde0: A9094FF4  stp      x20, x19, [sp, #0x90]
uint64_t fde_func_08488_0x34ddcc(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0034DDCCULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10283FFULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9067BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9003BF7ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90857F6ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9094FF4ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910183FDULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #08497 | PC: 0x34eea4..0x34ef0c (104 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x34eea4: D503233F  paciasp  
//   0x34eea8: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x34eeac: F9000BF3  str      x19, [sp, #0x10]
//   0x34eeb0: 910003FD  mov      x29, sp
//   0x34eeb4: B40000C0  cbz      x0, #0x34eecc
//   0x34eeb8: F947BC00  ldr      x0, [x0, #0xf78]
uint64_t fde_func_08497_0x34eea4(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0034EEA4ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF3ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB40000C0ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF947BC00ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB4000080ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9400A125ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #08507 | PC: 0x34fc3c..0x34fca4 (104 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x34fc3c: D503233F  paciasp  
//   0x34fc40: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x34fc44: F9000BF3  str      x19, [sp, #0x10]
//   0x34fc48: 910003FD  mov      x29, sp
//   0x34fc4c: AA0003F3  mov      x19, x0
//   0x34fc50: F941F000  ldr      x0, [x0, #0x3e0]
uint64_t fde_func_08507_0x34fc3c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0034FC3CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF3ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF941F000ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF941F661ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x94000013ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #08516 | PC: 0x350068..0x350070 (8 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x350068: D503245F  bti      c
//   0x35006c: 17FFEFEB  b        #0x34c018
uint64_t fde_func_08516_0x350068(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00350068ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x17FFEFEBULL ^ (1ULL << 32);
    return state ^ (state >> 29);
}

// FDE #08526 | PC: 0x350c6c..0x350cb0 (68 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x350c6c: D503233F  paciasp  
//   0x350c70: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x350c74: F9000BF3  str      x19, [sp, #0x10]
//   0x350c78: 910003FD  mov      x29, sp
//   0x350c7c: AA0003E8  mov      x8, x0
//   0x350c80: F9421800  ldr      x0, [x0, #0x430]
uint64_t fde_func_08526_0x350c6c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00350C6CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF3ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003E8ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9421800ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF943BD13ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB40000A0ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #08535 | PC: 0x350f64..0x350f70 (12 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x350f64: D503245F  bti      c
//   0x350f68: 911F6000  add      x0, x0, #0x7d8
//   0x350f6c: 17FCE929  b        #0x28b410
uint64_t fde_func_08535_0x350f64(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00350F64ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x911F6000ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x17FCE929ULL ^ (2ULL << 32);
    return state ^ (state >> 29);
}

// FDE #08545 | PC: 0x35112c..0x351148 (28 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x35112c: D503245F  bti      c
//   0x351130: F9421800  ldr      x0, [x0, #0x430]
//   0x351134: B4000080  cbz      x0, #0x351144
//   0x351138: F9400008  ldr      x8, [x0]
//   0x35113c: F9407110  ldr      x16, [x8, #0xe0]
//   0x351140: D61F0200  br       x16
uint64_t fde_func_08545_0x35112c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0035112CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9421800ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB4000080ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400008ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9407110ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD61F0200ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD65F03C0ULL ^ (6ULL << 32);
    return state ^ (state >> 29);
}

// FDE #08554 | PC: 0x3515d0..0x351624 (84 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x3515d0: D503233F  paciasp  
//   0x3515d4: A9BD7BFD  stp      x29, x30, [sp, #-0x30]!
//   0x3515d8: F9000BF5  str      x21, [sp, #0x10]
//   0x3515dc: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x3515e0: 910003FD  mov      x29, sp
//   0x3515e4: AA0003F4  mov      x20, x0
uint64_t fde_func_08554_0x3515d0(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x003515D0ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BD7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF5ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9024FF4ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F4ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x2A0103F5ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91094000ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #08564 | PC: 0x3517e4..0x351800 (28 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x3517e4: D503245F  bti      c
//   0x3517e8: 39772009  ldrb     w9, [x0, #0xdc8]
//   0x3517ec: 12000028  and      w8, w1, #1
//   0x3517f0: 6B08013F  cmp      w9, w8
//   0x3517f4: 54000040  b.eq     #0x3517fc
//   0x3517f8: 39372008  strb     w8, [x0, #0xdc8]
uint64_t fde_func_08564_0x3517e4(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x003517E4ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x39772009ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x12000028ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x6B08013FULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x54000040ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x39372008ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD65F03C0ULL ^ (6ULL << 32);
    return state ^ (state >> 29);
}

// FDE #08573 | PC: 0x35188c..0x351898 (12 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x35188c: D503245F  bti      c
//   0x351890: D1004000  sub      x0, x0, #0x10
//   0x351894: 17FFFA11  b        #0x3500d8
uint64_t fde_func_08573_0x35188c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0035188CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD1004000ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x17FFFA11ULL ^ (2ULL << 32);
    return state ^ (state >> 29);
}

// FDE #08583 | PC: 0x351910..0x35191c (12 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x351910: D503245F  bti      c
//   0x351914: 913D0000  add      x0, x0, #0xf40
//   0x351918: 17FAB05D  b        #0x1fda8c
uint64_t fde_func_08583_0x351910(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00351910ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x913D0000ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x17FAB05DULL ^ (2ULL << 32);
    return state ^ (state >> 29);
}

// FDE #08592 | PC: 0x351fa4..0x351fe8 (68 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x351fa4: D503245F  bti      c
//   0x351fa8: F9400408  ldr      x8, [x0, #8]
//   0x351fac: EB02003F  cmp      x1, x2
//   0x351fb0: 54000180  b.eq     #0x351fe0
//   0x351fb4: 39404029  ldrb     w9, [x1, #0x10]
//   0x351fb8: 3DC00020  ldr      q0, [x1]
uint64_t fde_func_08592_0x351fa4(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00351FA4ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400408ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xEB02003FULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x54000180ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x39404029ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x3DC00020ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x39004109ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x3D800100ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #08602 | PC: 0x352818..0x35287c (100 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x352818: D503233F  paciasp  
//   0x35281c: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x352820: F9000BF3  str      x19, [sp, #0x10]
//   0x352824: 910003FD  mov      x29, sp
//   0x352828: B941B008  ldr      w8, [x0, #0x1b0]
//   0x35282c: 7100251F  cmp      w8, #9
uint64_t fde_func_08602_0x352818(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00352818ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF3ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB941B008ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x7100251FULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x540001A1ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400068ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #08611 | PC: 0x3529fc..0x352a10 (20 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x3529fc: D503245F  bti      c
//   0x352a00: F9437800  ldr      x0, [x0, #0x6f0]
//   0x352a04: F9400008  ldr      x8, [x0]
//   0x352a08: F9404110  ldr      x16, [x8, #0x80]
//   0x352a0c: D61F0200  br       x16
uint64_t fde_func_08611_0x3529fc(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x003529FCULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9437800ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400008ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9404110ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD61F0200ULL ^ (4ULL << 32);
    return state ^ (state >> 29);
}

// FDE #08621 | PC: 0x352b98..0x352c10 (120 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x352b98: D503233F  paciasp  
//   0x352b9c: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x352ba0: F9000BF3  str      x19, [sp, #0x10]
//   0x352ba4: 910003FD  mov      x29, sp
//   0x352ba8: F9400013  ldr      x19, [x0]
//   0x352bac: B40002B3  cbz      x19, #0x352c00
uint64_t fde_func_08621_0x352b98(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00352B98ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF3ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400013ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB40002B3ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA1303E0ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x97FA97D5ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #08631 | PC: 0x3530a0..0x3530cc (44 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x3530a0: D503245F  bti      c
//   0x3530a4: 394A9408  ldrb     w8, [x0, #0x2a5]
//   0x3530a8: 34000068  cbz      w8, #0x3530b4
//   0x3530ac: 52800020  mov      w0, #1
//   0x3530b0: D65F03C0  ret      
//   0x3530b4: F9416400  ldr      x0, [x0, #0x2c8]
uint64_t fde_func_08631_0x3530a0(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x003530A0ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x394A9408ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x34000068ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x52800020ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD65F03C0ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9416400ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB4000080ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400008ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #08640 | PC: 0x3531b4..0x3531c0 (12 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x3531b4: D503245F  bti      c
//   0x3531b8: D10A2000  sub      x0, x0, #0x288
//   0x3531bc: 17FFFF9F  b        #0x353038
uint64_t fde_func_08640_0x3531b4(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x003531B4ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10A2000ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x17FFFF9FULL ^ (2ULL << 32);
    return state ^ (state >> 29);
}

// FDE #08650 | PC: 0x3547fc..0x354808 (12 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x3547fc: D503245F  bti      c
//   0x354800: AA1F03E1  mov      x1, xzr
//   0x354804: 17FFFFAA  b        #0x3546ac
uint64_t fde_func_08650_0x3547fc(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x003547FCULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA1F03E1ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x17FFFFAAULL ^ (2ULL << 32);
    return state ^ (state >> 29);
}

// FDE #08659 | PC: 0x354c1c..0x354d18 (252 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x354c1c: D503233F  paciasp  
//   0x354c20: D10243FF  sub      sp, sp, #0x90
//   0x354c24: A9067BFD  stp      x29, x30, [sp, #0x60]
//   0x354c28: F9003BF5  str      x21, [sp, #0x70]
//   0x354c2c: A9084FF4  stp      x20, x19, [sp, #0x80]
//   0x354c30: 910183FD  add      x29, sp, #0x60
uint64_t fde_func_08659_0x354c1c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00354C1CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10243FFULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9067BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9003BF5ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9084FF4ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910183FDULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910083E0ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #08669 | PC: 0x355090..0x3550e8 (88 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x355090: D503233F  paciasp  
//   0x355094: A9BD7BFD  stp      x29, x30, [sp, #-0x30]!
//   0x355098: F9000BF5  str      x21, [sp, #0x10]
//   0x35509c: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x3550a0: 910003FD  mov      x29, sp
//   0x3550a4: AA0203F3  mov      x19, x2
uint64_t fde_func_08669_0x355090(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00355090ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BD7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF5ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9024FF4ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0203F3ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F4ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9400000FULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #08678 | PC: 0x355748..0x3557dc (148 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x355748: D503233F  paciasp  
//   0x35574c: A9BD7BFD  stp      x29, x30, [sp, #-0x30]!
//   0x355750: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x355754: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x355758: 910003FD  mov      x29, sp
//   0x35575c: AA0103F4  mov      x20, x1
uint64_t fde_func_08678_0x355748(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00355748ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BD7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90157F6ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9024FF4ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0103F4ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x97F9CB99ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #08688 | PC: 0x355e18..0x355e90 (120 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x355e18: D503233F  paciasp  
//   0x355e1c: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x355e20: F9000BF3  str      x19, [sp, #0x10]
//   0x355e24: 910003FD  mov      x29, sp
//   0x355e28: AA0003F3  mov      x19, x0
//   0x355e2c: 910B6000  add      x0, x0, #0x2d8
uint64_t fde_func_08688_0x355e18(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00355E18ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF3ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910B6000ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9408C418ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9109E260ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #08697 | PC: 0x356874..0x356974 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x356874: D503233F  paciasp  
//   0x356878: D10183FF  sub      sp, sp, #0x60
//   0x35687c: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x356880: F9001BF7  str      x23, [sp, #0x30]
//   0x356884: A90457F6  stp      x22, x21, [sp, #0x40]
//   0x356888: A9054FF4  stp      x20, x19, [sp, #0x50]
uint64_t fde_func_08697_0x356874(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00356874ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10183FFULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9027BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9001BF7ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90457F6ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9054FF4ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910083FDULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0203F4ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #08707 | PC: 0x356ea0..0x356f70 (208 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x356ea0: D503233F  paciasp  
//   0x356ea4: A9BC7BFD  stp      x29, x30, [sp, #-0x40]!
//   0x356ea8: F9000BF7  str      x23, [sp, #0x10]
//   0x356eac: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x356eb0: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x356eb4: 910003FD  mov      x29, sp
uint64_t fde_func_08707_0x356ea0(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00356EA0ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BC7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF7ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90257F6ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9034FF4ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA940A408ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400036ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #08716 | PC: 0x357780..0x357824 (164 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x357780: D503233F  paciasp  
//   0x357784: D101C3FF  sub      sp, sp, #0x70
//   0x357788: A9037BFD  stp      x29, x30, [sp, #0x30]
//   0x35778c: A9045FF8  stp      x24, x23, [sp, #0x40]
//   0x357790: A90557F6  stp      x22, x21, [sp, #0x50]
//   0x357794: A9064FF4  stp      x20, x19, [sp, #0x60]
uint64_t fde_func_08716_0x357780(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00357780ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD101C3FFULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9037BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9045FF8ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90557F6ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9064FF4ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9100C3FDULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F7ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #08726 | PC: 0x3584c4..0x3585c4 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x3584c4: D503233F  paciasp  
//   0x3584c8: D10283FF  sub      sp, sp, #0xa0
//   0x3584cc: A9057BFD  stp      x29, x30, [sp, #0x50]
//   0x3584d0: A90667FA  stp      x26, x25, [sp, #0x60]
//   0x3584d4: A9075FF8  stp      x24, x23, [sp, #0x70]
//   0x3584d8: A90857F6  stp      x22, x21, [sp, #0x80]
uint64_t fde_func_08726_0x3584c4(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x003584C4ULL);
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

// FDE #08735 | PC: 0x35936c..0x359394 (40 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x35936c: D503245F  bti      c
//   0x359370: 7100A43F  cmp      w1, #0x29
//   0x359374: 540000A8  b.hi     #0x359388
//   0x359378: F00011A8  adrp     x8, #0x590000
//   0x35937c: 911FA108  add      x8, x8, #0x7e8
//   0x359380: F8615901  ldr      x1, [x8, w1, uxtw #3]
uint64_t fde_func_08735_0x35936c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0035936CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x7100A43FULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x540000A8ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF00011A8ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x911FA108ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF8615901ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x17F9DAB8ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x90FFECC1ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #08745 | PC: 0x3596d4..0x359748 (116 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x3596d4: D503233F  paciasp  
//   0x3596d8: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x3596dc: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x3596e0: 910003FD  mov      x29, sp
//   0x3596e4: AA0103F3  mov      x19, x1
//   0x3596e8: AA0003F4  mov      x20, x0
uint64_t fde_func_08745_0x3596d4(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x003596D4ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9014FF4ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0103F3ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F4ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9407CE0AULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x360000C0ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #08754 | PC: 0x359c7c..0x359d7c (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x359c7c: D503233F  paciasp  
//   0x359c80: D10303FF  sub      sp, sp, #0xc0
//   0x359c84: A9087BFD  stp      x29, x30, [sp, #0x80]
//   0x359c88: F9004BF7  str      x23, [sp, #0x90]
//   0x359c8c: A90A57F6  stp      x22, x21, [sp, #0xa0]
//   0x359c90: A90B4FF4  stp      x20, x19, [sp, #0xb0]
uint64_t fde_func_08754_0x359c7c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00359C7CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10303FFULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9087BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9004BF7ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90A57F6ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90B4FF4ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910203FDULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0403F6ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #08764 | PC: 0x35ab70..0x35abf0 (128 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x35ab70: D503233F  paciasp  
//   0x35ab74: A9BD7BFD  stp      x29, x30, [sp, #-0x30]!
//   0x35ab78: F9000BF5  str      x21, [sp, #0x10]
//   0x35ab7c: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x35ab80: 910003FD  mov      x29, sp
//   0x35ab84: AA0003F3  mov      x19, x0
uint64_t fde_func_08764_0x35ab70(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0035AB70ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BD7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF5ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9024FF4ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9401000ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x94000019ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #08773 | PC: 0x35ae90..0x35aed8 (72 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x35ae90: D503233F  paciasp  
//   0x35ae94: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x35ae98: F9000BF3  str      x19, [sp, #0x10]
//   0x35ae9c: 910003FD  mov      x29, sp
//   0x35aea0: F9400013  ldr      x19, [x0]
//   0x35aea4: F9000001  str      x1, [x0]
uint64_t fde_func_08773_0x35ae90(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0035AE90ULL);
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

// FDE #08783 | PC: 0x35ca38..0x35ca6c (52 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x35ca38: D503233F  paciasp  
//   0x35ca3c: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x35ca40: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x35ca44: 910003FD  mov      x29, sp
//   0x35ca48: AA0203F3  mov      x19, x2
//   0x35ca4c: AA0003F4  mov      x20, x0
uint64_t fde_func_08783_0x35ca38(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0035CA38ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9014FF4ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0203F3ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F4ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9400006AULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9103E280ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #08792 | PC: 0x35cd2c..0x35cd5c (48 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x35cd2c: D503233F  paciasp  
//   0x35cd30: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x35cd34: F9000BF3  str      x19, [sp, #0x10]
//   0x35cd38: 910003FD  mov      x29, sp
//   0x35cd3c: AA0003F3  mov      x19, x0
//   0x35cd40: 91008000  add      x0, x0, #0x20
uint64_t fde_func_08792_0x35cd2c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0035CD2CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF3ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91008000ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9408A853ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA1303E0ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #08802 | PC: 0x35d268..0x35d29c (52 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x35d268: D503233F  paciasp  
//   0x35d26c: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x35d270: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x35d274: 910003FD  mov      x29, sp
//   0x35d278: AA0203F3  mov      x19, x2
//   0x35d27c: AA0003F4  mov      x20, x0
uint64_t fde_func_08802_0x35d268(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0035D268ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9014FF4ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0203F3ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F4ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x97FFF20EULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91042280ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #08811 | PC: 0x35d604..0x35d65c (88 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x35d604: D503233F  paciasp  
//   0x35d608: A9BD7BFD  stp      x29, x30, [sp, #-0x30]!
//   0x35d60c: F9000BF5  str      x21, [sp, #0x10]
//   0x35d610: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x35d614: 910003FD  mov      x29, sp
//   0x35d618: AA0203F3  mov      x19, x2
uint64_t fde_func_08811_0x35d604(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0035D604ULL);
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

// FDE #08821 | PC: 0x35e3dc..0x35e4dc (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x35e3dc: D503233F  paciasp  
//   0x35e3e0: D100C3FF  sub      sp, sp, #0x30
//   0x35e3e4: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x35e3e8: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x35e3ec: 910043FD  add      x29, sp, #0x10
//   0x35e3f0: AA0003F3  mov      x19, x0
uint64_t fde_func_08821_0x35e3dc(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0035E3DCULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD100C3FFULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9024FF4ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x394A4008ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x90001249ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #08830 | PC: 0x35e958..0x35ea58 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x35e958: D503233F  paciasp  
//   0x35e95c: A9BA7BFD  stp      x29, x30, [sp, #-0x60]!
//   0x35e960: A9016FFC  stp      x28, x27, [sp, #0x10]
//   0x35e964: A90267FA  stp      x26, x25, [sp, #0x20]
//   0x35e968: A9035FF8  stp      x24, x23, [sp, #0x30]
//   0x35e96c: A90457F6  stp      x22, x21, [sp, #0x40]
uint64_t fde_func_08830_0x35e958(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0035E958ULL);
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

// FDE #08840 | PC: 0x35f8d0..0x35f9ac (220 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x35f8d0: D503233F  paciasp  
//   0x35f8d4: D102C3FF  sub      sp, sp, #0xb0
//   0x35f8d8: A9077BFD  stp      x29, x30, [sp, #0x70]
//   0x35f8dc: A9085FF8  stp      x24, x23, [sp, #0x80]
//   0x35f8e0: A90957F6  stp      x22, x21, [sp, #0x90]
//   0x35f8e4: A90A4FF4  stp      x20, x19, [sp, #0xa0]
uint64_t fde_func_08840_0x35f8d0(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0035F8D0ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD102C3FFULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9077BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9085FF8ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90957F6ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90A4FF4ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9101C3FDULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD53BD056ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #08849 | PC: 0x35ff20..0x35ffac (140 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x35ff20: D503233F  paciasp  
//   0x35ff24: D10683FF  sub      sp, sp, #0x1a0
//   0x35ff28: A9167BFD  stp      x29, x30, [sp, #0x160]
//   0x35ff2c: F900BBFC  str      x28, [sp, #0x170]
//   0x35ff30: A91857F6  stp      x22, x21, [sp, #0x180]
//   0x35ff34: A9194FF4  stp      x20, x19, [sp, #0x190]
uint64_t fde_func_08849_0x35ff20(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0035FF20ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10683FFULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9167BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF900BBFCULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA91857F6ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9194FF4ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910583FDULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD53BD055ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #08859 | PC: 0x361cb0..0x361d24 (116 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x361cb0: D503233F  paciasp  
//   0x361cb4: D100C3FF  sub      sp, sp, #0x30
//   0x361cb8: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x361cbc: F90013F3  str      x19, [sp, #0x20]
//   0x361cc0: 910043FD  add      x29, sp, #0x10
//   0x361cc4: AA0003F3  mov      x19, x0
uint64_t fde_func_08859_0x361cb0(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00361CB0ULL);
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

// FDE #08868 | PC: 0x362270..0x362370 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x362270: D503233F  paciasp  
//   0x362274: D10503FF  sub      sp, sp, #0x140
//   0x362278: A90E7BFD  stp      x29, x30, [sp, #0xe0]
//   0x36227c: A90F6FFC  stp      x28, x27, [sp, #0xf0]
//   0x362280: A91067FA  stp      x26, x25, [sp, #0x100]
//   0x362284: A9115FF8  stp      x24, x23, [sp, #0x110]
uint64_t fde_func_08868_0x362270(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00362270ULL);
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

// FDE #08878 | PC: 0x366480..0x366490 (16 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x366480: D503245F  bti      c
//   0x366484: F943A400  ldr      x0, [x0, #0x748]
//   0x366488: 2A0103E2  mov      w2, w1
//   0x36648c: 140009FD  b        #0x368c80
uint64_t fde_func_08878_0x366480(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00366480ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF943A400ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x2A0103E2ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x140009FDULL ^ (3ULL << 32);
    return state ^ (state >> 29);
}

// FDE #08887 | PC: 0x3666f0..0x366734 (68 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x3666f0: D503245F  bti      c
//   0x3666f4: B40001E0  cbz      x0, #0x366730
//   0x3666f8: D503233F  paciasp  
//   0x3666fc: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x366700: F9000BF3  str      x19, [sp, #0x10]
//   0x366704: 910003FD  mov      x29, sp
uint64_t fde_func_08887_0x3666f0(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x003666F0ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB40001E0ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE7BFDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF3ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91012000ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #08897 | PC: 0x36706c..0x367094 (40 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x36706c: D503245F  bti      c
//   0x367070: B9475009  ldr      w9, [x0, #0x750]
//   0x367074: 52801808  mov      w8, #0xc0
//   0x367078: 5280002A  mov      w10, #1
//   0x36707c: 7100053F  cmp      w9, #1
//   0x367080: 52801709  mov      w9, #0xb8
uint64_t fde_func_08897_0x36706c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0036706CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB9475009ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x52801808ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x5280002AULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x7100053FULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x52801709ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9A880128ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF943A409ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #08906 | PC: 0x3673e0..0x367404 (36 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x3673e0: D503245F  bti      c
//   0x3673e4: B9468808  ldr      w8, [x0, #0x688]
//   0x3673e8: 7100251F  cmp      w8, #9
//   0x3673ec: 54000081  b.ne     #0x3673fc
//   0x3673f0: 2A1F03E1  mov      w1, wzr
//   0x3673f4: B906881F  str      wzr, [x0, #0x688]
uint64_t fde_func_08906_0x3673e0(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x003673E0ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB9468808ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x7100251FULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x54000081ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x2A1F03E1ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB906881FULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x17FFED25ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD4200000ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #08916 | PC: 0x3682e0..0x36830c (44 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x3682e0: D503233F  paciasp  
//   0x3682e4: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x3682e8: F9000BF3  str      x19, [sp, #0x10]
//   0x3682ec: 910003FD  mov      x29, sp
//   0x3682f0: AA0003F3  mov      x19, x0
//   0x3682f4: 97FFFFB2  bl       #0x3681bc
uint64_t fde_func_08916_0x3682e0(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x003682E0ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF3ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x97FFFFB2ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA1303E0ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400BF3ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #08926 | PC: 0x368e28..0x368e98 (112 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x368e28: D503233F  paciasp  
//   0x368e2c: A9BD7BFD  stp      x29, x30, [sp, #-0x30]!
//   0x368e30: F9000BF5  str      x21, [sp, #0x10]
//   0x368e34: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x368e38: 910003FD  mov      x29, sp
//   0x368e3c: 3940E008  ldrb     w8, [x0, #0x38]
uint64_t fde_func_08926_0x368e28(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00368E28ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BD7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF5ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9024FF4ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x3940E008ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x340000C8ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9424FF4ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #08935 | PC: 0x368fb4..0x368ff8 (68 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x368fb4: D503245F  bti      c
//   0x368fb8: B940F808  ldr      w8, [x0, #0xf8]
//   0x368fbc: 7100051F  cmp      w8, #1
//   0x368fc0: 54000061  b.ne     #0x368fcc
//   0x368fc4: F9408000  ldr      x0, [x0, #0x100]
//   0x368fc8: 14004CC4  b        #0x37c2d8
uint64_t fde_func_08935_0x368fb4(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00368FB4ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB940F808ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x7100051FULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x54000061ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9408000ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x14004CC4ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9407808ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB4000068ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #08945 | PC: 0x369284..0x369290 (12 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x369284: D503245F  bti      c
//   0x369288: D1002000  sub      x0, x0, #8
//   0x36928c: 17FFFF4A  b        #0x368fb4
uint64_t fde_func_08945_0x369284(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00369284ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD1002000ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x17FFFF4AULL ^ (2ULL << 32);
    return state ^ (state >> 29);
}

// FDE #08954 | PC: 0x369498..0x369598 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x369498: D503233F  paciasp  
//   0x36949c: D10643FF  sub      sp, sp, #0x190
//   0x3694a0: A9147BFD  stp      x29, x30, [sp, #0x140]
//   0x3694a4: A91567FC  stp      x28, x25, [sp, #0x150]
//   0x3694a8: A9165FF8  stp      x24, x23, [sp, #0x160]
//   0x3694ac: A91757F6  stp      x22, x21, [sp, #0x170]
uint64_t fde_func_08954_0x369498(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00369498ULL);
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

// FDE #08964 | PC: 0x369c7c..0x369ce0 (100 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x369c7c: D503233F  paciasp  
//   0x369c80: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x369c84: F9000BF3  str      x19, [sp, #0x10]
//   0x369c88: 910003FD  mov      x29, sp
//   0x369c8c: AA0003F3  mov      x19, x0
//   0x369c90: 7100043F  cmp      w1, #1
uint64_t fde_func_08964_0x369c7c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00369C7CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF3ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x7100043FULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x540000C0ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x350001C1ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #08973 | PC: 0x36b564..0x36b580 (28 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x36b564: D503245F  bti      c
//   0x36b568: AA0003E8  mov      x8, x0
//   0x36b56c: F9400000  ldr      x0, [x0]
//   0x36b570: F900011F  str      xzr, [x8]
//   0x36b574: B4000040  cbz      x0, #0x36b57c
//   0x36b578: 17FFEF62  b        #0x367300
uint64_t fde_func_08973_0x36b564(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0036B564ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003E8ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400000ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF900011FULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB4000040ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x17FFEF62ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD65F03C0ULL ^ (6ULL << 32);
    return state ^ (state >> 29);
}

// FDE #08983 | PC: 0x36ce00..0x36ce1c (28 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x36ce00: D503245F  bti      c
//   0x36ce04: B0001188  adrp     x8, #0x59d000
//   0x36ce08: 91290108  add      x8, x8, #0xa40
//   0x36ce0c: F9400C09  ldr      x9, [x0, #0x18]
//   0x36ce10: F9000008  str      x8, [x0]
//   0x36ce14: F9000809  str      x9, [x0, #0x10]
uint64_t fde_func_08983_0x36ce00(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0036CE00ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB0001188ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91290108ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400C09ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000008ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000809ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x17FDF9AEULL ^ (6ULL << 32);
    return state ^ (state >> 29);
}

// FDE #08992 | PC: 0x36d51c..0x36d5b0 (148 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x36d51c: D503245F  bti      c
//   0x36d520: B4000441  cbz      x1, #0x36d5a8
//   0x36d524: D503233F  paciasp  
//   0x36d528: A9BD7BFD  stp      x29, x30, [sp, #-0x30]!
//   0x36d52c: F9000BF5  str      x21, [sp, #0x10]
//   0x36d530: A9024FF4  stp      x20, x19, [sp, #0x20]
uint64_t fde_func_08992_0x36d51c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0036D51CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB4000441ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BD7BFDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF5ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9024FF4ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB9400808ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #09002 | PC: 0x36d980..0x36da1c (156 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x36d980: D503233F  paciasp  
//   0x36d984: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x36d988: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x36d98c: 910003FD  mov      x29, sp
//   0x36d990: D0FFEB02  adrp     x2, #0xcf000
//   0x36d994: 910C8042  add      x2, x2, #0x320
uint64_t fde_func_09002_0x36d980(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0036D980ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9014FF4ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD0FFEB02ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910C8042ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x52800063ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0103F3ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #09011 | PC: 0x36e2d8..0x36e2ec (20 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x36e2d8: D503245F  bti      c
//   0x36e2dc: AA0103E8  mov      x8, x1
//   0x36e2e0: AA0203E1  mov      x1, x2
//   0x36e2e4: AA0803E2  mov      x2, x8
//   0x36e2e8: 17FCD612  b        #0x2a3b30
uint64_t fde_func_09011_0x36e2d8(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0036E2D8ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0103E8ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0203E1ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0803E2ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x17FCD612ULL ^ (4ULL << 32);
    return state ^ (state >> 29);
}

// FDE #09021 | PC: 0x36ec34..0x36ed34 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x36ec34: D503233F  paciasp  
//   0x36ec38: D10243FF  sub      sp, sp, #0x90
//   0x36ec3c: A9067BFD  stp      x29, x30, [sp, #0x60]
//   0x36ec40: A90757F6  stp      x22, x21, [sp, #0x70]
//   0x36ec44: A9084FF4  stp      x20, x19, [sp, #0x80]
//   0x36ec48: 910183FD  add      x29, sp, #0x60
uint64_t fde_func_09021_0x36ec34(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0036EC34ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10243FFULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9067BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90757F6ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9084FF4ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910183FDULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD53BD055ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x52800609ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #09030 | PC: 0x36f708..0x36f784 (124 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x36f708: D503233F  paciasp  
//   0x36f70c: D10103FF  sub      sp, sp, #0x40
//   0x36f710: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x36f714: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x36f718: 910083FD  add      x29, sp, #0x20
//   0x36f71c: AA0003F4  mov      x20, x0
uint64_t fde_func_09030_0x36f708(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0036F708ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10103FFULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9027BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9034FF4ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910083FDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F4ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910023E0ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0803F3ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #09040 | PC: 0x3700f0..0x3701f0 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x3700f0: D503233F  paciasp  
//   0x3700f4: D10183FF  sub      sp, sp, #0x60
//   0x3700f8: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x3700fc: A9035FF8  stp      x24, x23, [sp, #0x30]
//   0x370100: A90457F6  stp      x22, x21, [sp, #0x40]
//   0x370104: A9054FF4  stp      x20, x19, [sp, #0x50]
uint64_t fde_func_09040_0x3700f0(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x003700F0ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10183FFULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9027BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9035FF8ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90457F6ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9054FF4ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910083FDULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #09049 | PC: 0x370740..0x3707bc (124 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x370740: D503233F  paciasp  
//   0x370744: D10103FF  sub      sp, sp, #0x40
//   0x370748: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x37074c: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x370750: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x370754: 910043FD  add      x29, sp, #0x10
uint64_t fde_func_09049_0x370740(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00370740ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10103FFULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90257F6ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9034FF4ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9100C014ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #09059 | PC: 0x370f58..0x370fb8 (96 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x370f58: D503233F  paciasp  
//   0x370f5c: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x370f60: F9000BF3  str      x19, [sp, #0x10]
//   0x370f64: 910003FD  mov      x29, sp
//   0x370f68: B4000200  cbz      x0, #0x370fa8
//   0x370f6c: AA0003F3  mov      x19, x0
uint64_t fde_func_09059_0x370f58(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00370F58ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF3ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB4000200ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x885FFE68ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x71000508ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #09068 | PC: 0x3712d4..0x37138c (184 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x3712d4: D503233F  paciasp  
//   0x3712d8: A9BC7BFD  stp      x29, x30, [sp, #-0x40]!
//   0x3712dc: A9015FF8  stp      x24, x23, [sp, #0x10]
//   0x3712e0: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x3712e4: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x3712e8: 910003FD  mov      x29, sp
uint64_t fde_func_09068_0x3712d4(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x003712D4ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BC7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9015FF8ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90257F6ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9034FF4ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB9400808ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x3100051FULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #09078 | PC: 0x371ce4..0x371d68 (132 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x371ce4: D503233F  paciasp  
//   0x371ce8: A9BD7BFD  stp      x29, x30, [sp, #-0x30]!
//   0x371cec: F9000BF5  str      x21, [sp, #0x10]
//   0x371cf0: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x371cf4: 910003FD  mov      x29, sp
//   0x371cf8: AA0203F3  mov      x19, x2
uint64_t fde_func_09078_0x371ce4(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00371CE4ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BD7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF5ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9024FF4ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0203F3ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0103F4ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xEB01005FULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #09087 | PC: 0x372188..0x372278 (240 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x372188: D503233F  paciasp  
//   0x37218c: D10183FF  sub      sp, sp, #0x60
//   0x372190: A9047BFD  stp      x29, x30, [sp, #0x40]
//   0x372194: A9054FF4  stp      x20, x19, [sp, #0x50]
//   0x372198: 910103FD  add      x29, sp, #0x40
//   0x37219c: AA0103F3  mov      x19, x1
uint64_t fde_func_09087_0x372188(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00372188ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10183FFULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9047BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9054FF4ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910103FDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0103F3ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F4ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF0FFE921ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #09097 | PC: 0x3725c4..0x372630 (108 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x3725c4: D503233F  paciasp  
//   0x3725c8: D10103FF  sub      sp, sp, #0x40
//   0x3725cc: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x3725d0: F90013F5  str      x21, [sp, #0x20]
//   0x3725d4: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x3725d8: 910043FD  add      x29, sp, #0x10
uint64_t fde_func_09097_0x3725c4(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x003725C4ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10103FFULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF90013F5ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9034FF4ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x2A0103F3ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F4ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #09106 | PC: 0x372b04..0x372b8c (136 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x372b04: D503233F  paciasp  
//   0x372b08: D10103FF  sub      sp, sp, #0x40
//   0x372b0c: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x372b10: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x372b14: 910083FD  add      x29, sp, #0x20
//   0x372b18: AA0103F3  mov      x19, x1
uint64_t fde_func_09106_0x372b04(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00372B04ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10103FFULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9027BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9034FF4ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910083FDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0103F3ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F4ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB9400003ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #09116 | PC: 0x373d00..0x373e00 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x373d00: D503233F  paciasp  
//   0x373d04: A9BB7BFD  stp      x29, x30, [sp, #-0x50]!
//   0x373d08: A90167FA  stp      x26, x25, [sp, #0x10]
//   0x373d0c: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x373d10: A90357F6  stp      x22, x21, [sp, #0x30]
//   0x373d14: A9044FF4  stp      x20, x19, [sp, #0x40]
uint64_t fde_func_09116_0x373d00(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00373D00ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BB7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90167FAULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9025FF8ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90357F6ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9044FF4ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xCB000028ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #09125 | PC: 0x374298..0x3742b0 (24 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x374298: D503245F  bti      c
//   0x37429c: AA0003E8  mov      x8, x0
//   0x3742a0: F9400800  ldr      x0, [x0, #0x10]
//   0x3742a4: 2A0203E3  mov      w3, w2
//   0x3742a8: AA0803E2  mov      x2, x8
//   0x3742ac: 17FFF867  b        #0x372448
uint64_t fde_func_09125_0x374298(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00374298ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003E8ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400800ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x2A0203E3ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0803E2ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x17FFF867ULL ^ (5ULL << 32);
    return state ^ (state >> 29);
}

// FDE #09135 | PC: 0x374674..0x374680 (12 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x374674: D503245F  bti      c
//   0x374678: 52800042  mov      w2, #2
//   0x37467c: 17FFFF07  b        #0x374298
uint64_t fde_func_09135_0x374674(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00374674ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x52800042ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x17FFFF07ULL ^ (2ULL << 32);
    return state ^ (state >> 29);
}

// FDE #09144 | PC: 0x374aa0..0x374ba0 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x374aa0: D503233F  paciasp  
//   0x374aa4: D10243FF  sub      sp, sp, #0x90
//   0x374aa8: A9077BFD  stp      x29, x30, [sp, #0x70]
//   0x374aac: A9084FF4  stp      x20, x19, [sp, #0x80]
//   0x374ab0: 9101C3FD  add      x29, sp, #0x70
//   0x374ab4: AA0003F3  mov      x19, x0
uint64_t fde_func_09144_0x374aa0(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00374AA0ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10243FFULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9077BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9084FF4ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9101C3FDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10063A0ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0103F4ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #09154 | PC: 0x375124..0x375194 (112 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x375124: D503233F  paciasp  
//   0x375128: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x37512c: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x375130: 910003FD  mov      x29, sp
//   0x375134: F9400013  ldr      x19, [x0]
//   0x375138: F9000001  str      x1, [x0]
uint64_t fde_func_09154_0x375124(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00375124ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9014FF4ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400013ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000001ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB4000253ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91014260ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #09163 | PC: 0x375a44..0x375b44 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x375a44: D503233F  paciasp  
//   0x375a48: D10503FF  sub      sp, sp, #0x140
//   0x375a4c: A90E7BFD  stp      x29, x30, [sp, #0xe0]
//   0x375a50: A90F6FFC  stp      x28, x27, [sp, #0xf0]
//   0x375a54: A91067FA  stp      x26, x25, [sp, #0x100]
//   0x375a58: A9115FF8  stp      x24, x23, [sp, #0x110]
uint64_t fde_func_09163_0x375a44(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00375A44ULL);
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

// FDE #09173 | PC: 0x37665c..0x376694 (56 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x37665c: D503245F  bti      c
//   0x376660: F9400808  ldr      x8, [x0, #0x10]
//   0x376664: B4000148  cbz      x8, #0x37668c
//   0x376668: A9402508  ldp      x8, x9, [x8]
//   0x37666c: CB080128  sub      x8, x9, x8
//   0x376670: A941A809  ldp      x9, x10, [x0, #0x18]
uint64_t fde_func_09173_0x37665c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0037665CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400808ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB4000148ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9402508ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xCB080128ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA941A809ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9343FD08ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xEB0A011FULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #09182 | PC: 0x376fe4..0x3770e4 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x376fe4: D503233F  paciasp  
//   0x376fe8: D10183FF  sub      sp, sp, #0x60
//   0x376fec: A9037BFD  stp      x29, x30, [sp, #0x30]
//   0x376ff0: A90457F6  stp      x22, x21, [sp, #0x40]
//   0x376ff4: A9054FF4  stp      x20, x19, [sp, #0x50]
//   0x376ff8: 9100C3FD  add      x29, sp, #0x30
uint64_t fde_func_09182_0x376fe4(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00376FE4ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10183FFULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9037BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90457F6ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9054FF4ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9100C3FDULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF940042AULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #09192 | PC: 0x377d7c..0x377e7c (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x377d7c: D503233F  paciasp  
//   0x377d80: D10203FF  sub      sp, sp, #0x80
//   0x377d84: A9067BFD  stp      x29, x30, [sp, #0x60]
//   0x377d88: A9074FF4  stp      x20, x19, [sp, #0x70]
//   0x377d8c: 910183FD  add      x29, sp, #0x60
//   0x377d90: AA0003F3  mov      x19, x0
uint64_t fde_func_09192_0x377d7c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00377D7CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10203FFULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9067BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9074FF4ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910183FDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x394F8400ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x97FFF990ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #09201 | PC: 0x378074..0x3780c0 (76 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x378074: D503233F  paciasp  
//   0x378078: D100C3FF  sub      sp, sp, #0x30
//   0x37807c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x378080: F90013F3  str      x19, [sp, #0x20]
//   0x378084: 910043FD  add      x29, sp, #0x10
//   0x378088: A9410801  ldp      x1, x2, [x0, #0x10]
uint64_t fde_func_09201_0x378074(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00378074ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD100C3FFULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF90013F3ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9410801ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9400000CULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #09211 | PC: 0x378538..0x3785a8 (112 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x378538: D503233F  paciasp  
//   0x37853c: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x378540: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x378544: 910003FD  mov      x29, sp
//   0x378548: AA0003F4  mov      x20, x0
//   0x37854c: 91020000  add      x0, x0, #0x80
uint64_t fde_func_09211_0x378538(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00378538ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9014FF4ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F4ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91020000ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0103F3ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x97FFFEB8ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #09221 | PC: 0x3792dc..0x379320 (68 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x3792dc: D503233F  paciasp  
//   0x3792e0: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x3792e4: F9000BF3  str      x19, [sp, #0x10]
//   0x3792e8: 910003FD  mov      x29, sp
//   0x3792ec: AA0003F3  mov      x19, x0
//   0x3792f0: 97F9E557  bl       #0x1f284c
uint64_t fde_func_09221_0x3792dc(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x003792DCULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF3ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x97F9E557ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x3951D008ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x340000C8ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #09230 | PC: 0x379a7c..0x379ab0 (52 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x379a7c: D503245F  bti      c
//   0x379a80: 6F00E400  movi     v0.2d, #0000000000000000
//   0x379a84: F9400028  ldr      x8, [x1]
//   0x379a88: F9000008  str      x8, [x0]
//   0x379a8c: 3C808000  stur     q0, [x0, #8]
//   0x379a90: 3C818000  stur     q0, [x0, #0x18]
uint64_t fde_func_09230_0x379a7c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00379A7CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x6F00E400ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400028ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000008ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x3C808000ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x3C818000ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xFD401420ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xFD001400ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #09240 | PC: 0x37a788..0x37a888 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x37a788: D503233F  paciasp  
//   0x37a78c: A9BD7BFD  stp      x29, x30, [sp, #-0x30]!
//   0x37a790: F9000BF5  str      x21, [sp, #0x10]
//   0x37a794: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x37a798: 910003FD  mov      x29, sp
//   0x37a79c: CB000028  sub      x8, x1, x0
uint64_t fde_func_09240_0x37a788(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0037A788ULL);
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

// FDE #09249 | PC: 0x37ac3c..0x37ac80 (68 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x37ac3c: D503245F  bti      c
//   0x37ac40: B40001E0  cbz      x0, #0x37ac7c
//   0x37ac44: D503233F  paciasp  
//   0x37ac48: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x37ac4c: F9000BF3  str      x19, [sp, #0x10]
//   0x37ac50: 910003FD  mov      x29, sp
uint64_t fde_func_09249_0x37ac3c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0037AC3CULL);
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

// FDE #09259 | PC: 0x37b168..0x37b268 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x37b168: D503233F  paciasp  
//   0x37b16c: D101C3FF  sub      sp, sp, #0x70
//   0x37b170: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x37b174: A90367FA  stp      x26, x25, [sp, #0x30]
//   0x37b178: A9045FF8  stp      x24, x23, [sp, #0x40]
//   0x37b17c: A90557F6  stp      x22, x21, [sp, #0x50]
uint64_t fde_func_09259_0x37b168(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0037B168ULL);
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

// FDE #09268 | PC: 0x37c2ac..0x37c2d8 (44 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x37c2ac: D503233F  paciasp  
//   0x37c2b0: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x37c2b4: F9000BF3  str      x19, [sp, #0x10]
//   0x37c2b8: 910003FD  mov      x29, sp
//   0x37c2bc: AA0003F3  mov      x19, x0
//   0x37c2c0: 97FFFFD6  bl       #0x37c218
uint64_t fde_func_09268_0x37c2ac(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0037C2ACULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF3ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x97FFFFD6ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA1303E0ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400BF3ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #09278 | PC: 0x37ccf4..0x37cd00 (12 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x37ccf4: D503245F  bti      c
//   0x37ccf8: F9022801  str      x1, [x0, #0x450]
//   0x37ccfc: D65F03C0  ret      
uint64_t fde_func_09278_0x37ccf4(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0037CCF4ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9022801ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD65F03C0ULL ^ (2ULL << 32);
    return state ^ (state >> 29);
}

// FDE #09287 | PC: 0x37d02c..0x37d040 (20 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x37d02c: D503245F  bti      c
//   0x37d030: F9421000  ldr      x0, [x0, #0x420]
//   0x37d034: B4000040  cbz      x0, #0x37d03c
//   0x37d038: 14000598  b        #0x37e698
//   0x37d03c: D65F03C0  ret      
uint64_t fde_func_09287_0x37d02c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0037D02CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9421000ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB4000040ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x14000598ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD65F03C0ULL ^ (4ULL << 32);
    return state ^ (state >> 29);
}

// FDE #09297 | PC: 0x37d260..0x37d26c (12 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x37d260: D503245F  bti      c
//   0x37d264: D100A000  sub      x0, x0, #0x28
//   0x37d268: 17FFFF76  b        #0x37d040
uint64_t fde_func_09297_0x37d260(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0037D260ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD100A000ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x17FFFF76ULL ^ (2ULL << 32);
    return state ^ (state >> 29);
}

// FDE #09306 | PC: 0x37d8bc..0x37d9bc (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x37d8bc: D503233F  paciasp  
//   0x37d8c0: A9BA7BFD  stp      x29, x30, [sp, #-0x60]!
//   0x37d8c4: A9016FFC  stp      x28, x27, [sp, #0x10]
//   0x37d8c8: A90267FA  stp      x26, x25, [sp, #0x20]
//   0x37d8cc: A9035FF8  stp      x24, x23, [sp, #0x30]
//   0x37d8d0: A90457F6  stp      x22, x21, [sp, #0x40]
uint64_t fde_func_09306_0x37d8bc(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0037D8BCULL);
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

// FDE #09316 | PC: 0x37e03c..0x37e070 (52 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x37e03c: D503233F  paciasp  
//   0x37e040: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x37e044: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x37e048: 910003FD  mov      x29, sp
//   0x37e04c: AA0103F3  mov      x19, x1
//   0x37e050: AA0003F4  mov      x20, x0
uint64_t fde_func_09316_0x37e03c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0037E03CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9014FF4ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0103F3ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F4ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x94000DE7ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB9412268ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #09325 | PC: 0x37e660..0x37e698 (56 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x37e660: D503233F  paciasp  
//   0x37e664: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x37e668: F9000BF3  str      x19, [sp, #0x10]
//   0x37e66c: 910003FD  mov      x29, sp
//   0x37e670: 39400008  ldrb     w8, [x0]
//   0x37e674: 340000A8  cbz      w8, #0x37e688
uint64_t fde_func_09325_0x37e660(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0037E660ULL);
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

// FDE #09335 | PC: 0x37f824..0x37f874 (80 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x37f824: D503233F  paciasp  
//   0x37f828: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x37f82c: F9000BF3  str      x19, [sp, #0x10]
//   0x37f830: 910003FD  mov      x29, sp
//   0x37f834: 52800100  mov      w0, #8
//   0x37f838: AA0203F3  mov      x19, x2
uint64_t fde_func_09335_0x37f824(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0037F824ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF3ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x52800100ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0203F3ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x97FD734EULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003E8ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #09344 | PC: 0x37f9f0..0x37fa24 (52 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x37f9f0: D503233F  paciasp  
//   0x37f9f4: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x37f9f8: F9000BF3  str      x19, [sp, #0x10]
//   0x37f9fc: 910003FD  mov      x29, sp
//   0x37fa00: AA0003F3  mov      x19, x0
//   0x37fa04: F9400000  ldr      x0, [x0]
uint64_t fde_func_09344_0x37f9f0(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0037F9F0ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF3ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400000ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000261ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x97FFFFAFULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #09354 | PC: 0x380910..0x380964 (84 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x380910: D503233F  paciasp  
//   0x380914: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x380918: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x38091c: 910003FD  mov      x29, sp
//   0x380920: AA0003F3  mov      x19, x0
//   0x380924: 97FFFD33  bl       #0x37fdf0
uint64_t fde_func_09354_0x380910(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00380910ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9014FF4ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x97FFFD33ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x3100041FULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x54000140ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #09363 | PC: 0x381338..0x381390 (88 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x381338: D503233F  paciasp  
//   0x38133c: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x381340: F9000BF3  str      x19, [sp, #0x10]
//   0x381344: 910003FD  mov      x29, sp
//   0x381348: AA0103E0  mov      x0, x1
//   0x38134c: AA0103F3  mov      x19, x1
uint64_t fde_func_09363_0x381338(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00381338ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF3ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0103E0ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0103F3ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x97FAD101ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x528005C2ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #09373 | PC: 0x381ba8..0x381c50 (168 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x381ba8: D503233F  paciasp  
//   0x381bac: D10203FF  sub      sp, sp, #0x80
//   0x381bb0: A9057BFD  stp      x29, x30, [sp, #0x50]
//   0x381bb4: F90033F5  str      x21, [sp, #0x60]
//   0x381bb8: A9074FF4  stp      x20, x19, [sp, #0x70]
//   0x381bbc: 910143FD  add      x29, sp, #0x50
uint64_t fde_func_09373_0x381ba8(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00381BA8ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10203FFULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9057BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF90033F5ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9074FF4ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910143FDULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9402428ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xEB09011FULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #09382 | PC: 0x381e00..0x381e34 (52 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x381e00: D503233F  paciasp  
//   0x381e04: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x381e08: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x381e0c: 910003FD  mov      x29, sp
//   0x381e10: AA0103F3  mov      x19, x1
//   0x381e14: AA0003F4  mov      x20, x0
uint64_t fde_func_09382_0x381e00(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00381E00ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9014FF4ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0103F3ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F4ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x97FFFFE0ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA1403E0ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #09392 | PC: 0x3821d4..0x382224 (80 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x3821d4: D503233F  paciasp  
//   0x3821d8: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x3821dc: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x3821e0: 910003FD  mov      x29, sp
//   0x3821e4: AA0103F3  mov      x19, x1
//   0x3821e8: AA0003F4  mov      x20, x0
uint64_t fde_func_09392_0x3821d4(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x003821D4ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9014FF4ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0103F3ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F4ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x97FFFFD0ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400268ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #09401 | PC: 0x3824d4..0x382544 (112 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x3824d4: D503233F  paciasp  
//   0x3824d8: A9BD7BFD  stp      x29, x30, [sp, #-0x30]!
//   0x3824dc: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x3824e0: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x3824e4: 910003FD  mov      x29, sp
//   0x3824e8: A9405809  ldp      x9, x22, [x0]
uint64_t fde_func_09401_0x3824d4(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x003824D4ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BD7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90157F6ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9024FF4ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9405809ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x52800508ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #09411 | PC: 0x382f1c..0x382f90 (116 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x382f1c: D503233F  paciasp  
//   0x382f20: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x382f24: F9000BF3  str      x19, [sp, #0x10]
//   0x382f28: 910003FD  mov      x29, sp
//   0x382f2c: AA0003F3  mov      x19, x0
//   0x382f30: F9400401  ldr      x1, [x0, #8]
uint64_t fde_func_09411_0x382f1c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00382F1CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF3ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400401ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910063A0ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x94000E32ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #09420 | PC: 0x383544..0x3835e0 (156 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x383544: D503233F  paciasp  
//   0x383548: D10103FF  sub      sp, sp, #0x40
//   0x38354c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x383550: F90013F5  str      x21, [sp, #0x20]
//   0x383554: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x383558: 910043FD  add      x29, sp, #0x10
uint64_t fde_func_09420_0x383544(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00383544ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10103FFULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF90013F5ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9034FF4ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9106A014ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #09430 | PC: 0x3839b8..0x383ab8 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x3839b8: D503233F  paciasp  
//   0x3839bc: D101C3FF  sub      sp, sp, #0x70
//   0x3839c0: A9037BFD  stp      x29, x30, [sp, #0x30]
//   0x3839c4: A9045FF8  stp      x24, x23, [sp, #0x40]
//   0x3839c8: A90557F6  stp      x22, x21, [sp, #0x50]
//   0x3839cc: A9064FF4  stp      x20, x19, [sp, #0x60]
uint64_t fde_func_09430_0x3839b8(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x003839B8ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD101C3FFULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9037BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9045FF8ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90557F6ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9064FF4ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9100C3FDULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9402428ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #09439 | PC: 0x3843e8..0x38442c (68 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x3843e8: D503233F  paciasp  
//   0x3843ec: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x3843f0: F9000BF3  str      x19, [sp, #0x10]
//   0x3843f4: 910003FD  mov      x29, sp
//   0x3843f8: AA0003F3  mov      x19, x0
//   0x3843fc: 91016000  add      x0, x0, #0x58
uint64_t fde_func_09439_0x3843e8(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x003843E8ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF3ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91016000ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD00010C8ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9102C108ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #09449 | PC: 0x384e14..0x384e30 (28 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x384e14: D503245F  bti      c
//   0x384e18: AA0003E8  mov      x8, x0
//   0x384e1c: F9400000  ldr      x0, [x0]
//   0x384e20: F900011F  str      xzr, [x8]
//   0x384e24: B4000040  cbz      x0, #0x384e2c
//   0x384e28: 14003859  b        #0x392f8c
uint64_t fde_func_09449_0x384e14(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00384E14ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003E8ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400000ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF900011FULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB4000040ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x14003859ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD65F03C0ULL ^ (6ULL << 32);
    return state ^ (state >> 29);
}

// FDE #09458 | PC: 0x385104..0x385124 (32 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x385104: D503245F  bti      c
//   0x385108: 6F00E400  movi     v0.2d, #0000000000000000
//   0x38510c: 3900011F  strb     wzr, [x8]
//   0x385110: 3C808100  stur     q0, [x8, #8]
//   0x385114: 3C818100  stur     q0, [x8, #0x18]
//   0x385118: 3C828100  stur     q0, [x8, #0x28]
uint64_t fde_func_09458_0x385104(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00385104ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x6F00E400ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x3900011FULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x3C808100ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x3C818100ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x3C828100ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x3C838100ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD65F03C0ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #09468 | PC: 0x3852a0..0x3852d0 (48 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x3852a0: D503233F  paciasp  
//   0x3852a4: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x3852a8: 910003FD  mov      x29, sp
//   0x3852ac: 97FD892B  bl       #0x2e7758
//   0x3852b0: D2980008  mov      x8, #0xc000
//   0x3852b4: F2B6EF28  movk     x8, #0xb779, lsl #16
uint64_t fde_func_09468_0x3852a0(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x003852A0ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BF7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x97FD892BULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD2980008ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF2B6EF28ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF2D42D28ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF2FFFAC8ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #09477 | PC: 0x385d20..0x385e20 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x385d20: D503233F  paciasp  
//   0x385d24: D10103FF  sub      sp, sp, #0x40
//   0x385d28: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x385d2c: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x385d30: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x385d34: 910043FD  add      x29, sp, #0x10
uint64_t fde_func_09477_0x385d20(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00385D20ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10103FFULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90257F6ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9034FF4ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF0001148ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9124C108ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #09487 | PC: 0x38605c..0x386068 (12 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x38605c: D503245F  bti      c
//   0x386060: D1006000  sub      x0, x0, #0x18
//   0x386064: 17FFFFBC  b        #0x385f54
uint64_t fde_func_09487_0x38605c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0038605CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD1006000ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x17FFFFBCULL ^ (2ULL << 32);
    return state ^ (state >> 29);
}

// FDE #09496 | PC: 0x386524..0x386598 (116 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x386524: D503233F  paciasp  
//   0x386528: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x38652c: F9000BF3  str      x19, [sp, #0x10]
//   0x386530: 910003FD  mov      x29, sp
//   0x386534: AA0003F3  mov      x19, x0
//   0x386538: B4000241  cbz      x1, #0x386580
uint64_t fde_func_09496_0x386524(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00386524ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF3ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB4000241ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910063A0ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x94003116ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #09506 | PC: 0x386800..0x38686c (108 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x386800: D503233F  paciasp  
//   0x386804: A9BD7BFD  stp      x29, x30, [sp, #-0x30]!
//   0x386808: F9000BF5  str      x21, [sp, #0x10]
//   0x38680c: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x386810: 910003FD  mov      x29, sp
//   0x386814: 9102C035  add      x21, x1, #0xb0
uint64_t fde_func_09506_0x386800(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00386800ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BD7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF5ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9024FF4ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9102C035ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA1503E0ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #09516 | PC: 0x386fd8..0x387024 (76 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x386fd8: D503233F  paciasp  
//   0x386fdc: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x386fe0: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x386fe4: 910003FD  mov      x29, sp
//   0x386fe8: 9102C013  add      x19, x0, #0xb0
//   0x386fec: AA0003F4  mov      x20, x0
uint64_t fde_func_09516_0x386fd8(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00386FD8ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9014FF4ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9102C013ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F4ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA1303E0ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x97F950CEULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #09525 | PC: 0x3875e8..0x387654 (108 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x3875e8: D503233F  paciasp  
//   0x3875ec: D10183FF  sub      sp, sp, #0x60
//   0x3875f0: A9047BFD  stp      x29, x30, [sp, #0x40]
//   0x3875f4: F9002BF3  str      x19, [sp, #0x50]
//   0x3875f8: 910103FD  add      x29, sp, #0x40
//   0x3875fc: D53BD053  mrs      x19, tpidr_el0
uint64_t fde_func_09525_0x3875e8(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x003875E8ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10183FFULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9047BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9002BF3ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910103FDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD53BD053ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF00010A9ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9134C129ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #09535 | PC: 0x388160..0x388260 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x388160: D503233F  paciasp  
//   0x388164: D10283FF  sub      sp, sp, #0xa0
//   0x388168: A9067BFD  stp      x29, x30, [sp, #0x60]
//   0x38816c: A9075FF8  stp      x24, x23, [sp, #0x70]
//   0x388170: A90857F6  stp      x22, x21, [sp, #0x80]
//   0x388174: A9094FF4  stp      x20, x19, [sp, #0x90]
uint64_t fde_func_09535_0x388160(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00388160ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10283FFULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9067BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9075FF8ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90857F6ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9094FF4ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910183FDULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9494414ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #09544 | PC: 0x388a70..0x388b70 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x388a70: D503233F  paciasp  
//   0x388a74: A9BD7BFD  stp      x29, x30, [sp, #-0x30]!
//   0x388a78: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x388a7c: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x388a80: 910003FD  mov      x29, sp
//   0x388a84: A940A408  ldp      x8, x9, [x0, #8]
uint64_t fde_func_09544_0x388a70(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00388A70ULL);
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

// FDE #09554 | PC: 0x389104..0x389130 (44 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x389104: D503233F  paciasp  
//   0x389108: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x38910c: 910003FD  mov      x29, sp
//   0x389110: 52800200  mov      w0, #0x10
//   0x389114: 97FD4D18  bl       #0x2dc574
//   0x389118: B00010A8  adrp     x8, #0x59e000
uint64_t fde_func_09554_0x389104(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00389104ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BF7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x52800200ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x97FD4D18ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB00010A8ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9134C108ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000008ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #09563 | PC: 0x38a498..0x38a598 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x38a498: D503233F  paciasp  
//   0x38a49c: A9BB7BFD  stp      x29, x30, [sp, #-0x50]!
//   0x38a4a0: A90167FC  stp      x28, x25, [sp, #0x10]
//   0x38a4a4: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x38a4a8: A90357F6  stp      x22, x21, [sp, #0x30]
//   0x38a4ac: A9044FF4  stp      x20, x19, [sp, #0x40]
uint64_t fde_func_09563_0x38a498(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0038A498ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BB7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90167FCULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9025FF8ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90357F6ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9044FF4ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD116C3FFULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #09573 | PC: 0x38b728..0x38b734 (12 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x38b728: D503245F  bti      c
//   0x38b72c: F948BC00  ldr      x0, [x0, #0x1178]
//   0x38b730: D65F03C0  ret      
uint64_t fde_func_09573_0x38b728(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0038B728ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF948BC00ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD65F03C0ULL ^ (2ULL << 32);
    return state ^ (state >> 29);
}

// FDE #09582 | PC: 0x38be88..0x38bef0 (104 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x38be88: D503233F  paciasp  
//   0x38be8c: D10103FF  sub      sp, sp, #0x40
//   0x38be90: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x38be94: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x38be98: 910083FD  add      x29, sp, #0x20
//   0x38be9c: F94A1008  ldr      x8, [x0, #0x1420]
uint64_t fde_func_09582_0x38be88(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0038BE88ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10103FFULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9027BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9034FF4ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910083FDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF94A1008ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF940AD13ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB9402E69ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #09592 | PC: 0x38cad4..0x38cb14 (64 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x38cad4: D503233F  paciasp  
//   0x38cad8: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x38cadc: F9000BF3  str      x19, [sp, #0x10]
//   0x38cae0: 910003FD  mov      x29, sp
//   0x38cae4: 913F6002  add      x2, x0, #0xfd8
//   0x38cae8: AA0003F3  mov      x19, x0
uint64_t fde_func_09592_0x38cad4(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0038CAD4ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF3ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x913F6002ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x940006A1ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x36000080ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #09601 | PC: 0x38d1ec..0x38d2d4 (232 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x38d1ec: D503233F  paciasp  
//   0x38d1f0: A9BC7BFD  stp      x29, x30, [sp, #-0x40]!
//   0x38d1f4: F9000BF7  str      x23, [sp, #0x10]
//   0x38d1f8: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x38d1fc: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x38d200: 910003FD  mov      x29, sp
uint64_t fde_func_09601_0x38d1ec(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0038D1ECULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BC7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF7ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90257F6ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9034FF4ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0303F4ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0203F6ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #09611 | PC: 0x38d690..0x38d69c (12 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x38d690: D503245F  bti      c
//   0x38d694: D1002000  sub      x0, x0, #8
//   0x38d698: 17FFF545  b        #0x38abac
uint64_t fde_func_09611_0x38d690(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0038D690ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD1002000ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x17FFF545ULL ^ (2ULL << 32);
    return state ^ (state >> 29);
}

// FDE #09620 | PC: 0x38d6fc..0x38d708 (12 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x38d6fc: D503245F  bti      c
//   0x38d700: D1008000  sub      x0, x0, #0x20
//   0x38d704: 17FFF97E  b        #0x38bcfc
uint64_t fde_func_09620_0x38d6fc(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0038D6FCULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD1008000ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x17FFF97EULL ^ (2ULL << 32);
    return state ^ (state >> 29);
}

// FDE #09630 | PC: 0x38d774..0x38d780 (12 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x38d774: D503245F  bti      c
//   0x38d778: D1326000  sub      x0, x0, #0xc98
//   0x38d77c: 17FFF50C  b        #0x38abac
uint64_t fde_func_09630_0x38d774(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0038D774ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD1326000ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x17FFF50CULL ^ (2ULL << 32);
    return state ^ (state >> 29);
}

// FDE #09639 | PC: 0x38d7f8..0x38d804 (12 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x38d7f8: D503245F  bti      c
//   0x38d7fc: D13EE000  sub      x0, x0, #0xfb8
//   0x38d800: 17FFFF5D  b        #0x38d574
uint64_t fde_func_09639_0x38d7f8(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0038D7F8ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD13EE000ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x17FFFF5DULL ^ (2ULL << 32);
    return state ^ (state >> 29);
}

// FDE #09649 | PC: 0x38d904..0x38d910 (12 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x38d904: D503245F  bti      c
//   0x38d908: D13F2000  sub      x0, x0, #0xfc8
//   0x38d90c: 17FFFCA3  b        #0x38cb98
uint64_t fde_func_09649_0x38d904(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0038D904ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD13F2000ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x17FFFCA3ULL ^ (2ULL << 32);
    return state ^ (state >> 29);
}

// FDE #09658 | PC: 0x38dc00..0x38dd00 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x38dc00: D503233F  paciasp  
//   0x38dc04: D10303FF  sub      sp, sp, #0xc0
//   0x38dc08: A9087BFD  stp      x29, x30, [sp, #0x80]
//   0x38dc0c: A9095FF8  stp      x24, x23, [sp, #0x90]
//   0x38dc10: A90A57F6  stp      x22, x21, [sp, #0xa0]
//   0x38dc14: A90B4FF4  stp      x20, x19, [sp, #0xb0]
uint64_t fde_func_09658_0x38dc00(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0038DC00ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10303FFULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9087BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9095FF8ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90A57F6ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90B4FF4ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910203FDULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD53BD057ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #09668 | PC: 0x38e7bc..0x38e878 (188 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x38e7bc: D503233F  paciasp  
//   0x38e7c0: A9BD7BFD  stp      x29, x30, [sp, #-0x30]!
//   0x38e7c4: F9000BF5  str      x21, [sp, #0x10]
//   0x38e7c8: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x38e7cc: 910003FD  mov      x29, sp
//   0x38e7d0: 91002013  add      x19, x0, #8
uint64_t fde_func_09668_0x38e7bc(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0038E7BCULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BD7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF5ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9024FF4ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91002013ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F4ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA1303E0ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #09677 | PC: 0x38edb8..0x38ee14 (92 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x38edb8: D503233F  paciasp  
//   0x38edbc: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x38edc0: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x38edc4: 910003FD  mov      x29, sp
//   0x38edc8: AA0003F3  mov      x19, x0
//   0x38edcc: F9400414  ldr      x20, [x0, #8]
uint64_t fde_func_09677_0x38edb8(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0038EDB8ULL);
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

// FDE #09687 | PC: 0x38f5b8..0x38f66c (180 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x38f5b8: D503233F  paciasp  
//   0x38f5bc: D10143FF  sub      sp, sp, #0x50
//   0x38f5c0: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x38f5c4: F9001BF5  str      x21, [sp, #0x30]
//   0x38f5c8: A9044FF4  stp      x20, x19, [sp, #0x40]
//   0x38f5cc: 910083FD  add      x29, sp, #0x20
uint64_t fde_func_09687_0x38f5b8(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0038F5B8ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10143FFULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9027BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9001BF5ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9044FF4ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910083FDULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x2A0203F4ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x2A0103F5ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #09696 | PC: 0x38f938..0x38f9a4 (108 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x38f938: D503233F  paciasp  
//   0x38f93c: A9BD7BFD  stp      x29, x30, [sp, #-0x30]!
//   0x38f940: F9000BF5  str      x21, [sp, #0x10]
//   0x38f944: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x38f948: 910003FD  mov      x29, sp
//   0x38f94c: F9400015  ldr      x21, [x0]
uint64_t fde_func_09696_0x38f938(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0038F938ULL);
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

// FDE #09706 | PC: 0x390204..0x390220 (28 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x390204: D503245F  bti      c
//   0x390208: D0001068  adrp     x8, #0x59e000
//   0x39020c: 91360108  add      x8, x8, #0xd80
//   0x390210: F9000028  str      x8, [x1]
//   0x390214: F9400408  ldr      x8, [x0, #8]
//   0x390218: F9000428  str      x8, [x1, #8]
uint64_t fde_func_09706_0x390204(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00390204ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD0001068ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91360108ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000028ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400408ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000428ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD65F03C0ULL ^ (6ULL << 32);
    return state ^ (state >> 29);
}

// FDE #09715 | PC: 0x390760..0x3907f0 (144 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x390760: D503233F  paciasp  
//   0x390764: D10243FF  sub      sp, sp, #0x90
//   0x390768: A9077BFD  stp      x29, x30, [sp, #0x70]
//   0x39076c: F90043F3  str      x19, [sp, #0x80]
//   0x390770: 9101C3FD  add      x29, sp, #0x70
//   0x390774: D53BD053  mrs      x19, tpidr_el0
uint64_t fde_func_09715_0x390760(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00390760ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10243FFULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9077BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF90043F3ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9101C3FDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD53BD053ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD0001109ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91380129ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #09725 | PC: 0x390ccc..0x390d1c (80 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x390ccc: D503233F  paciasp  
//   0x390cd0: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x390cd4: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x390cd8: 910003FD  mov      x29, sp
//   0x390cdc: 9102C014  add      x20, x0, #0xb0
//   0x390ce0: AA0103F3  mov      x19, x1
uint64_t fde_func_09725_0x390ccc(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00390CCCULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9014FF4ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9102C014ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0103F3ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA1403E0ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x97F92991ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #09734 | PC: 0x39118c..0x391220 (148 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x39118c: D503233F  paciasp  
//   0x391190: A9BD7BFD  stp      x29, x30, [sp, #-0x30]!
//   0x391194: F9000BF5  str      x21, [sp, #0x10]
//   0x391198: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x39119c: 910003FD  mov      x29, sp
//   0x3911a0: AA0203F3  mov      x19, x2
uint64_t fde_func_09734_0x39118c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0039118CULL);
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

// FDE #09744 | PC: 0x391684..0x39176c (232 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x391684: D503233F  paciasp  
//   0x391688: D101C3FF  sub      sp, sp, #0x70
//   0x39168c: A9037BFD  stp      x29, x30, [sp, #0x30]
//   0x391690: A9045FF8  stp      x24, x23, [sp, #0x40]
//   0x391694: A90557F6  stp      x22, x21, [sp, #0x50]
//   0x391698: A9064FF4  stp      x20, x19, [sp, #0x60]
uint64_t fde_func_09744_0x391684(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00391684ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD101C3FFULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9037BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9045FF8ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90557F6ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9064FF4ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9100C3FDULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F5ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #09753 | PC: 0x391b54..0x391b98 (68 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x391b54: D503233F  paciasp  
//   0x391b58: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x391b5c: F9000BF3  str      x19, [sp, #0x10]
//   0x391b60: 910003FD  mov      x29, sp
//   0x391b64: AA0003F3  mov      x19, x0
//   0x391b68: 91010000  add      x0, x0, #0x40
uint64_t fde_func_09753_0x391b54(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00391B54ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF3ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91010000ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x97FBE658ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9401A60ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #09763 | PC: 0x391fd8..0x392010 (56 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x391fd8: D503233F  paciasp  
//   0x391fdc: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x391fe0: F9000BF3  str      x19, [sp, #0x10]
//   0x391fe4: 910003FD  mov      x29, sp
//   0x391fe8: AA0003F3  mov      x19, x0
//   0x391fec: F9425C00  ldr      x0, [x0, #0x4b8]
uint64_t fde_func_09763_0x391fd8(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00391FD8ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF3ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9425C00ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB4000060ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x97FFFD3EULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #09772 | PC: 0x3926d4..0x3926e0 (12 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x3926d4: D503245F  bti      c
//   0x3926d8: D109A000  sub      x0, x0, #0x268
//   0x3926dc: 17FFFE19  b        #0x391f40
uint64_t fde_func_09772_0x3926d4(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x003926D4ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD109A000ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x17FFFE19ULL ^ (2ULL << 32);
    return state ^ (state >> 29);
}

// FDE #09782 | PC: 0x392df0..0x392e50 (96 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x392df0: D503233F  paciasp  
//   0x392df4: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x392df8: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x392dfc: 910003FD  mov      x29, sp
//   0x392e00: 94027B19  bl       #0x431a64
//   0x392e04: B0001273  adrp     x19, #0x5df000
uint64_t fde_func_09782_0x392df0(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00392DF0ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9014FF4ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x94027B19ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB0001273ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF947BA74ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9409280ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #09791 | PC: 0x393354..0x393454 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x393354: D503233F  paciasp  
//   0x393358: A9BD7BFD  stp      x29, x30, [sp, #-0x30]!
//   0x39335c: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x393360: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x393364: 910003FD  mov      x29, sp
//   0x393368: AA0003F3  mov      x19, x0
uint64_t fde_func_09791_0x393354(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00393354ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BD7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90157F6ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9024FF4ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x2A0103F4ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x7100003FULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #09801 | PC: 0x393b88..0x393bd4 (76 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x393b88: D503233F  paciasp  
//   0x393b8c: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x393b90: F9000BF3  str      x19, [sp, #0x10]
//   0x393b94: 910003FD  mov      x29, sp
//   0x393b98: AA0003F3  mov      x19, x0
//   0x393b9c: 9102A000  add      x0, x0, #0xa8
uint64_t fde_func_09801_0x393b88(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00393B88ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF3ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9102A000ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x90001068ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91088108ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #09810 | PC: 0x393dfc..0x393e14 (24 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x393dfc: D503245F  bti      c
//   0x393e00: B9417C28  ldr      w8, [x1, #0x17c]
//   0x393e04: 7100051F  cmp      w8, #1
//   0x393e08: 5400004B  b.lt     #0x393e10
//   0x393e0c: B9000808  str      w8, [x0, #8]
//   0x393e10: D65F03C0  ret      
uint64_t fde_func_09810_0x393dfc(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00393DFCULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB9417C28ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x7100051FULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x5400004BULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB9000808ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD65F03C0ULL ^ (5ULL << 32);
    return state ^ (state >> 29);
}

// FDE #09820 | PC: 0x394108..0x3941d0 (200 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x394108: D503233F  paciasp  
//   0x39410c: D10203FF  sub      sp, sp, #0x80
//   0x394110: A9047BFD  stp      x29, x30, [sp, #0x40]
//   0x394114: F9002BF7  str      x23, [sp, #0x50]
//   0x394118: A90657F6  stp      x22, x21, [sp, #0x60]
//   0x39411c: A9074FF4  stp      x20, x19, [sp, #0x70]
uint64_t fde_func_09820_0x394108(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00394108ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10203FFULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9047BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9002BF7ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90657F6ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9074FF4ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910103FDULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD53BD057ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #09830 | PC: 0x3943ac..0x3943b8 (12 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x3943ac: D503245F  bti      c
//   0x3943b0: 9104C000  add      x0, x0, #0x130
//   0x3943b4: 14000B5D  b        #0x397128
uint64_t fde_func_09830_0x3943ac(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x003943ACULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9104C000ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x14000B5DULL ^ (2ULL << 32);
    return state ^ (state >> 29);
}

// FDE #09839 | PC: 0x39442c..0x394438 (12 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x39442c: D503245F  bti      c
//   0x394430: 9104C000  add      x0, x0, #0x130
//   0x394434: 14000BFA  b        #0x39741c
uint64_t fde_func_09839_0x39442c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0039442CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9104C000ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x14000BFAULL ^ (2ULL << 32);
    return state ^ (state >> 29);
}

// FDE #09849 | PC: 0x39457c..0x394588 (12 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x39457c: D503245F  bti      c
//   0x394580: 9104C000  add      x0, x0, #0x130
//   0x394584: 14000CD6  b        #0x3978dc
uint64_t fde_func_09849_0x39457c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0039457CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9104C000ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x14000CD6ULL ^ (2ULL << 32);
    return state ^ (state >> 29);
}

// FDE #09858 | PC: 0x3945e8..0x3945f4 (12 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x3945e8: D503245F  bti      c
//   0x3945ec: 9104C000  add      x0, x0, #0x130
//   0x3945f0: 14000DD4  b        #0x397d40
uint64_t fde_func_09858_0x3945e8(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x003945E8ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9104C000ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x14000DD4ULL ^ (2ULL << 32);
    return state ^ (state >> 29);
}

// FDE #09868 | PC: 0x394770..0x39477c (12 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x394770: D503245F  bti      c
//   0x394774: D1002000  sub      x0, x0, #8
//   0x394778: 17FFFFD8  b        #0x3946d8
uint64_t fde_func_09868_0x394770(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00394770ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD1002000ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x17FFFFD8ULL ^ (2ULL << 32);
    return state ^ (state >> 29);
}

// FDE #09877 | PC: 0x3947dc..0x3947e8 (12 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x3947dc: D503245F  bti      c
//   0x3947e0: 91048000  add      x0, x0, #0x120
//   0x3947e4: 14000EA0  b        #0x398264
uint64_t fde_func_09877_0x3947dc(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x003947DCULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91048000ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x14000EA0ULL ^ (2ULL << 32);
    return state ^ (state >> 29);
}

// FDE #09887 | PC: 0x394cb4..0x394d3c (136 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x394cb4: D503233F  paciasp  
//   0x394cb8: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x394cbc: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x394cc0: 910003FD  mov      x29, sp
//   0x394cc4: F9400C08  ldr      x8, [x0, #0x18]
//   0x394cc8: EB02011F  cmp      x8, x2
uint64_t fde_func_09887_0x394cb4(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00394CB4ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9014FF4ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400C08ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xEB02011FULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x54000301ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #09896 | PC: 0x395530..0x395614 (228 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x395530: D503233F  paciasp  
//   0x395534: A9BD7BFD  stp      x29, x30, [sp, #-0x30]!
//   0x395538: F9000BF5  str      x21, [sp, #0x10]
//   0x39553c: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x395540: 910003FD  mov      x29, sp
//   0x395544: 52823108  mov      w8, #0x1188
uint64_t fde_func_09896_0x395530(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00395530ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BD7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF5ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9024FF4ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x52823108ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0103F4ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x8B080033ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #09906 | PC: 0x3966d4..0x3967d4 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x3966d4: D503233F  paciasp  
//   0x3966d8: D104C3FF  sub      sp, sp, #0x130
//   0x3966dc: A90D7BFD  stp      x29, x30, [sp, #0xd0]
//   0x3966e0: F90073FC  str      x28, [sp, #0xe0]
//   0x3966e4: A90F67FA  stp      x26, x25, [sp, #0xf0]
//   0x3966e8: A9105FF8  stp      x24, x23, [sp, #0x100]
uint64_t fde_func_09906_0x3966d4(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x003966D4ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD104C3FFULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90D7BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF90073FCULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90F67FAULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9105FF8ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA91157F6ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9124FF4ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #09915 | PC: 0x3970c0..0x397128 (104 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x3970c0: D503233F  paciasp  
//   0x3970c4: D10103FF  sub      sp, sp, #0x40
//   0x3970c8: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x3970cc: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x3970d0: 910083FD  add      x29, sp, #0x20
//   0x3970d4: F9401413  ldr      x19, [x0, #0x28]
uint64_t fde_func_09915_0x3970c0(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x003970C0ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10103FFULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9027BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9034FF4ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910083FDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9401413ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB9402E68ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x350000C8ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #09925 | PC: 0x39741c..0x397480 (100 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x39741c: D503233F  paciasp  
//   0x397420: D10103FF  sub      sp, sp, #0x40
//   0x397424: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x397428: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x39742c: 910083FD  add      x29, sp, #0x20
//   0x397430: F9401413  ldr      x19, [x0, #0x28]
uint64_t fde_func_09925_0x39741c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0039741CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10103FFULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9027BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9034FF4ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910083FDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9401413ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB9402E68ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x350000C8ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #09934 | PC: 0x3978dc..0x397944 (104 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x3978dc: D503233F  paciasp  
//   0x3978e0: D10103FF  sub      sp, sp, #0x40
//   0x3978e4: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x3978e8: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x3978ec: 910083FD  add      x29, sp, #0x20
//   0x3978f0: F9401413  ldr      x19, [x0, #0x28]
uint64_t fde_func_09934_0x3978dc(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x003978DCULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10103FFULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9027BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9034FF4ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910083FDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9401413ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB9402E68ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x350000C8ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #09944 | PC: 0x397da4..0x397e08 (100 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x397da4: D503233F  paciasp  
//   0x397da8: D10103FF  sub      sp, sp, #0x40
//   0x397dac: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x397db0: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x397db4: 910083FD  add      x29, sp, #0x20
//   0x397db8: F9401413  ldr      x19, [x0, #0x28]
uint64_t fde_func_09944_0x397da4(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00397DA4ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10103FFULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9027BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9034FF4ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910083FDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9401413ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB9402E68ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x350000C8ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #09953 | PC: 0x398308..0x398314 (12 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x398308: D503245F  bti      c
//   0x39830c: D1002000  sub      x0, x0, #8
//   0x398310: 17FFFFBC  b        #0x398200
uint64_t fde_func_09953_0x398308(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00398308ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD1002000ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x17FFFFBCULL ^ (2ULL << 32);
    return state ^ (state >> 29);
}

// FDE #09963 | PC: 0x398a48..0x398ac8 (128 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x398a48: D503233F  paciasp  
//   0x398a4c: D10183FF  sub      sp, sp, #0x60
//   0x398a50: A9047BFD  stp      x29, x30, [sp, #0x40]
//   0x398a54: F9002BF3  str      x19, [sp, #0x50]
//   0x398a58: 910103FD  add      x29, sp, #0x40
//   0x398a5c: AA0003F3  mov      x19, x0
uint64_t fde_func_09963_0x398a48(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00398A48ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10183FFULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9047BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9002BF3ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910103FDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910023E0ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA93EFFBFULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #09972 | PC: 0x398ff0..0x399074 (132 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x398ff0: D503233F  paciasp  
//   0x398ff4: D10143FF  sub      sp, sp, #0x50
//   0x398ff8: A9037BFD  stp      x29, x30, [sp, #0x30]
//   0x398ffc: F90023F3  str      x19, [sp, #0x40]
//   0x399000: 9100C3FD  add      x29, sp, #0x30
//   0x399004: AA0003F3  mov      x19, x0
uint64_t fde_func_09972_0x398ff0(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00398FF0ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10143FFULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9037BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF90023F3ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9100C3FDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003E0ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA1F03E2ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #09982 | PC: 0x399294..0x399300 (108 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x399294: D503233F  paciasp  
//   0x399298: D10103FF  sub      sp, sp, #0x40
//   0x39929c: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x3992a0: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x3992a4: 910083FD  add      x29, sp, #0x20
//   0x3992a8: F9400C13  ldr      x19, [x0, #0x18]
uint64_t fde_func_09982_0x399294(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00399294ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10103FFULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9027BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9034FF4ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910083FDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400C13ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB9402E68ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x34000068ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #09991 | PC: 0x39971c..0x399784 (104 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x39971c: D503233F  paciasp  
//   0x399720: D100C3FF  sub      sp, sp, #0x30
//   0x399724: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x399728: 910083FD  add      x29, sp, #0x20
//   0x39972c: AA0003E8  mov      x8, x0
//   0x399730: F9400C00  ldr      x0, [x0, #0x18]
uint64_t fde_func_09991_0x39971c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0039971CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD100C3FFULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9027BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910083FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003E8ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400C00ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB9402C09ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x340000A9ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #10001 | PC: 0x399c1c..0x399d1c (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x399c1c: D503233F  paciasp  
//   0x399c20: D10603FF  sub      sp, sp, #0x180
//   0x399c24: A9127BFD  stp      x29, x30, [sp, #0x120]
//   0x399c28: A9136FFC  stp      x28, x27, [sp, #0x130]
//   0x399c2c: A91467FA  stp      x26, x25, [sp, #0x140]
//   0x399c30: A9155FF8  stp      x24, x23, [sp, #0x150]
uint64_t fde_func_10001_0x399c1c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00399C1CULL);
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

// FDE #10010 | PC: 0x39a6a8..0x39a6e0 (56 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x39a6a8: D503245F  bti      c
//   0x39a6ac: F9401008  ldr      x8, [x0, #0x20]
//   0x39a6b0: B4000148  cbz      x8, #0x39a6d8
//   0x39a6b4: F9401909  ldr      x9, [x8, #0x30]
//   0x39a6b8: 9101C108  add      x8, x8, #0x70
//   0x39a6bc: 9102C12A  add      x10, x9, #0xb0
uint64_t fde_func_10010_0x39a6a8(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0039A6A8ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9401008ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB4000148ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9401909ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9101C108ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9102C12AULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF100013FULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9A881148ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #10020 | PC: 0x39ace0..0x39ad90 (176 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x39ace0: D503233F  paciasp  
//   0x39ace4: A9BD7BFD  stp      x29, x30, [sp, #-0x30]!
//   0x39ace8: F9000BF5  str      x21, [sp, #0x10]
//   0x39acec: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x39acf0: 910003FD  mov      x29, sp
//   0x39acf4: 39502828  ldrb     w8, [x1, #0x40a]
uint64_t fde_func_10020_0x39ace0(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0039ACE0ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BD7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF5ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9024FF4ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x39502828ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x340000C8ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9424FF4ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #10029 | PC: 0x39b06c..0x39b0c4 (88 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x39b06c: D503233F  paciasp  
//   0x39b070: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x39b074: F9000BF3  str      x19, [sp, #0x10]
//   0x39b078: 910003FD  mov      x29, sp
//   0x39b07c: AA0003F3  mov      x19, x0
//   0x39b080: F9401000  ldr      x0, [x0, #0x20]
uint64_t fde_func_10029_0x39b06c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0039B06CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF3ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9401000ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x97FFDA1EULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x36000160ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #10039 | PC: 0x39bdbc..0x39bdf8 (60 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x39bdbc: D503245F  bti      c
//   0x39bdc0: F9400409  ldr      x9, [x0, #8]
//   0x39bdc4: 2A0103E4  mov      w4, w1
//   0x39bdc8: AA0803E0  mov      x0, x8
//   0x39bdcc: F9400129  ldr      x9, [x9]
//   0x39bdd0: F940112A  ldr      x10, [x9, #0x20]
uint64_t fde_func_10039_0x39bdbc(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0039BDBCULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400409ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x2A0103E4ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0803E0ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400129ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF940112AULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91018122ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB9404923ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #10048 | PC: 0x39c32c..0x39c390 (100 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x39c32c: D503233F  paciasp  
//   0x39c330: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x39c334: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x39c338: 910003FD  mov      x29, sp
//   0x39c33c: F940D808  ldr      x8, [x0, #0x1b0]
//   0x39c340: F9401908  ldr      x8, [x8, #0x30]
uint64_t fde_func_10048_0x39c32c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0039C32CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9014FF4ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF940D808ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9401908ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB40001C8ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0103F3ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #10058 | PC: 0x39c570..0x39c588 (24 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x39c570: D503245F  bti      c
//   0x39c574: F9436409  ldr      x9, [x0, #0x6c8]
//   0x39c578: 91136008  add      x8, x0, #0x4d8
//   0x39c57c: F100013F  cmp      x9, #0
//   0x39c580: 9A8803E0  csel     x0, xzr, x8, eq
//   0x39c584: D65F03C0  ret      
uint64_t fde_func_10058_0x39c570(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0039C570ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9436409ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91136008ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF100013FULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9A8803E0ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD65F03C0ULL ^ (5ULL << 32);
    return state ^ (state >> 29);
}

// FDE #10067 | PC: 0x39cafc..0x39cb78 (124 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x39cafc: D503233F  paciasp  
//   0x39cb00: D10103FF  sub      sp, sp, #0x40
//   0x39cb04: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x39cb08: F9001BF3  str      x19, [sp, #0x30]
//   0x39cb0c: 910083FD  add      x29, sp, #0x20
//   0x39cb10: AA0003F3  mov      x19, x0
uint64_t fde_func_10067_0x39cafc(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0039CAFCULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10103FFULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9027BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9001BF3ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910083FDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x94000019ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91006260ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #10077 | PC: 0x39d164..0x39d1f4 (144 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x39d164: D503233F  paciasp  
//   0x39d168: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x39d16c: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x39d170: 910003FD  mov      x29, sp
//   0x39d174: 39408808  ldrb     w8, [x0, #0x22]
//   0x39d178: 39408829  ldrb     w9, [x1, #0x22]
uint64_t fde_func_10077_0x39d164(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0039D164ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9014FF4ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x39408808ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x39408829ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x7100011FULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x1A9F07E8ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #10086 | PC: 0x39fcd4..0x39fdc4 (240 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x39fcd4: D503233F  paciasp  
//   0x39fcd8: D10183FF  sub      sp, sp, #0x60
//   0x39fcdc: A9037BFD  stp      x29, x30, [sp, #0x30]
//   0x39fce0: A90457F6  stp      x22, x21, [sp, #0x40]
//   0x39fce4: A9054FF4  stp      x20, x19, [sp, #0x50]
//   0x39fce8: 9100C3FD  add      x29, sp, #0x30
uint64_t fde_func_10086_0x39fcd4(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0039FCD4ULL);
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

// FDE #10096 | PC: 0x3a0678..0x3a06a8 (48 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x3a0678: D503233F  paciasp  
//   0x3a067c: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x3a0680: F9000BF3  str      x19, [sp, #0x10]
//   0x3a0684: 910003FD  mov      x29, sp
//   0x3a0688: AA0003F3  mov      x19, x0
//   0x3a068c: 9104A000  add      x0, x0, #0x128
uint64_t fde_func_10096_0x3a0678(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x003A0678ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF3ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9104A000ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x97F8DFD1ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA1303E0ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #10105 | PC: 0x3a0a38..0x3a0b38 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x3a0a38: D503233F  paciasp  
//   0x3a0a3c: A9BC7BFD  stp      x29, x30, [sp, #-0x40]!
//   0x3a0a40: A9015FF8  stp      x24, x23, [sp, #0x10]
//   0x3a0a44: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x3a0a48: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x3a0a4c: 910003FD  mov      x29, sp
uint64_t fde_func_10105_0x3a0a38(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x003A0A38ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BC7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9015FF8ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90257F6ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9034FF4ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0503F6ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0403F8ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #10115 | PC: 0x3a18e8..0x3a196c (132 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x3a18e8: D503233F  paciasp  
//   0x3a18ec: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x3a18f0: F9000BF3  str      x19, [sp, #0x10]
//   0x3a18f4: 910003FD  mov      x29, sp
//   0x3a18f8: AA0003F3  mov      x19, x0
//   0x3a18fc: 91002000  add      x0, x0, #8
uint64_t fde_func_10115_0x3a18e8(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x003A18E8ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF3ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91002000ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000261ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x97FFECD0ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #10125 | PC: 0x3a2e4c..0x3a2e7c (48 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x3a2e4c: D503233F  paciasp  
//   0x3a2e50: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x3a2e54: F9000BF3  str      x19, [sp, #0x10]
//   0x3a2e58: 910003FD  mov      x29, sp
//   0x3a2e5c: AA0003F3  mov      x19, x0
//   0x3a2e60: 9104A000  add      x0, x0, #0x128
uint64_t fde_func_10125_0x3a2e4c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x003A2E4CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF3ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9104A000ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x97FFFFF7ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA1303E0ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #10134 | PC: 0x3a3b94..0x3a3c44 (176 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x3a3b94: D503233F  paciasp  
//   0x3a3b98: D10143FF  sub      sp, sp, #0x50
//   0x3a3b9c: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x3a3ba0: A90357F6  stp      x22, x21, [sp, #0x30]
//   0x3a3ba4: A9044FF4  stp      x20, x19, [sp, #0x40]
//   0x3a3ba8: 910083FD  add      x29, sp, #0x20
uint64_t fde_func_10134_0x3a3b94(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x003A3B94ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10143FFULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9027BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90357F6ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9044FF4ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910083FDULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0103F3ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x2A1F03E1ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #10144 | PC: 0x3a4184..0x3a4190 (12 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x3a4184: D503245F  bti      c
//   0x3a4188: D1004000  sub      x0, x0, #0x10
//   0x3a418c: 17FFFEAE  b        #0x3a3c44
uint64_t fde_func_10144_0x3a4184(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x003A4184ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD1004000ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x17FFFEAEULL ^ (2ULL << 32);
    return state ^ (state >> 29);
}

// FDE #10153 | PC: 0x3a41f0..0x3a41fc (12 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x3a41f0: D503245F  bti      c
//   0x3a41f4: D100A000  sub      x0, x0, #0x28
//   0x3a41f8: 17FFFDC9  b        #0x3a391c
uint64_t fde_func_10153_0x3a41f0(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x003A41F0ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD100A000ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x17FFFDC9ULL ^ (2ULL << 32);
    return state ^ (state >> 29);
}

// FDE #10163 | PC: 0x3a4268..0x3a4274 (12 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x3a4268: D503245F  bti      c
//   0x3a426c: D1012000  sub      x0, x0, #0x48
//   0x3a4270: 17FFFEF1  b        #0x3a3e34
uint64_t fde_func_10163_0x3a4268(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x003A4268ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD1012000ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x17FFFEF1ULL ^ (2ULL << 32);
    return state ^ (state >> 29);
}

// FDE #10172 | PC: 0x3a4674..0x3a46c0 (76 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x3a4674: D503245F  bti      c
//   0x3a4678: B4000220  cbz      x0, #0x3a46bc
//   0x3a467c: D503233F  paciasp  
//   0x3a4680: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x3a4684: F9000BF3  str      x19, [sp, #0x10]
//   0x3a4688: 910003FD  mov      x29, sp
uint64_t fde_func_10172_0x3a4674(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x003A4674ULL);
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

// FDE #10182 | PC: 0x3a4ab4..0x3a4b00 (76 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x3a4ab4: D503233F  paciasp  
//   0x3a4ab8: D100C3FF  sub      sp, sp, #0x30
//   0x3a4abc: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x3a4ac0: F90013F3  str      x19, [sp, #0x20]
//   0x3a4ac4: 910043FD  add      x29, sp, #0x10
//   0x3a4ac8: AA0003F3  mov      x19, x0
uint64_t fde_func_10182_0x3a4ab4(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x003A4AB4ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD100C3FFULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF90013F3ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003E0ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x97FC007AULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #10191 | PC: 0x3a5298..0x3a5398 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x3a5298: D503233F  paciasp  
//   0x3a529c: A9BB7BFD  stp      x29, x30, [sp, #-0x50]!
//   0x3a52a0: F9000BF9  str      x25, [sp, #0x10]
//   0x3a52a4: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x3a52a8: A90357F6  stp      x22, x21, [sp, #0x30]
//   0x3a52ac: A9044FF4  stp      x20, x19, [sp, #0x40]
uint64_t fde_func_10191_0x3a5298(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x003A5298ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BB7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF9ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9025FF8ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90357F6ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9044FF4ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x5280A300ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #10201 | PC: 0x3a58d8..0x3a593c (100 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x3a58d8: D503233F  paciasp  
//   0x3a58dc: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x3a58e0: F9000BF3  str      x19, [sp, #0x10]
//   0x3a58e4: 910003FD  mov      x29, sp
//   0x3a58e8: B4000220  cbz      x0, #0x3a592c
//   0x3a58ec: AA0003F3  mov      x19, x0
uint64_t fde_func_10201_0x3a58d8(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x003A58D8ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF3ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB4000220ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x97F94C86ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x360001C0ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #10210 | PC: 0x3a5d68..0x3a5e68 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x3a5d68: D503233F  paciasp  
//   0x3a5d6c: A9BD7BFD  stp      x29, x30, [sp, #-0x30]!
//   0x3a5d70: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x3a5d74: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x3a5d78: 910003FD  mov      x29, sp
//   0x3a5d7c: 2A0403F5  mov      w21, w4
uint64_t fde_func_10210_0x3a5d68(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x003A5D68ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BD7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90157F6ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9024FF4ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x2A0403F5ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0303F3ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x2A0203F6ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #10220 | PC: 0x3a64cc..0x3a65cc (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x3a64cc: D503233F  paciasp  
//   0x3a64d0: A9BA7BFD  stp      x29, x30, [sp, #-0x60]!
//   0x3a64d4: A9016FFC  stp      x28, x27, [sp, #0x10]
//   0x3a64d8: A90267FA  stp      x26, x25, [sp, #0x20]
//   0x3a64dc: A9035FF8  stp      x24, x23, [sp, #0x30]
//   0x3a64e0: A90457F6  stp      x22, x21, [sp, #0x40]
uint64_t fde_func_10220_0x3a64cc(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x003A64CCULL);
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

// FDE #10229 | PC: 0x3a7540..0x3a75a8 (104 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x3a7540: D503233F  paciasp  
//   0x3a7544: A9BD7BFD  stp      x29, x30, [sp, #-0x30]!
//   0x3a7548: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x3a754c: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x3a7550: 910003FD  mov      x29, sp
//   0x3a7554: AA0203F3  mov      x19, x2
uint64_t fde_func_10229_0x3a7540(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x003A7540ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BD7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90157F6ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9024FF4ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0203F3ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x2A0103F4ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9103E016ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #10239 | PC: 0x3a7ec8..0x3a7ed8 (16 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x3a7ec8: D503245F  bti      c
//   0x3a7ecc: 39093001  strb     w1, [x0, #0x24c]
//   0x3a7ed0: 39051001  strb     w1, [x0, #0x144]
//   0x3a7ed4: D65F03C0  ret      
uint64_t fde_func_10239_0x3a7ec8(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x003A7EC8ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x39093001ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x39051001ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD65F03C0ULL ^ (3ULL << 32);
    return state ^ (state >> 29);
}

// FDE #10248 | PC: 0x3a8134..0x3a81d8 (164 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x3a8134: D503233F  paciasp  
//   0x3a8138: D10103FF  sub      sp, sp, #0x40
//   0x3a813c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x3a8140: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x3a8144: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x3a8148: 910043FD  add      x29, sp, #0x10
uint64_t fde_func_10248_0x3a8134(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x003A8134ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10103FFULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90257F6ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9034FF4ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F6ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x52800700ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #10258 | PC: 0x3a8c3c..0x3a8ccc (144 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x3a8c3c: D503233F  paciasp  
//   0x3a8c40: D10183FF  sub      sp, sp, #0x60
//   0x3a8c44: A9047BFD  stp      x29, x30, [sp, #0x40]
//   0x3a8c48: F9002BF3  str      x19, [sp, #0x50]
//   0x3a8c4c: 910103FD  add      x29, sp, #0x40
//   0x3a8c50: AA0003F3  mov      x19, x0
uint64_t fde_func_10258_0x3a8c3c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x003A8C3CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10183FFULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9047BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9002BF3ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910103FDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9401C08ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB4000188ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #10267 | PC: 0x3a9010..0x3a901c (12 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x3a9010: D503245F  bti      c
//   0x3a9014: 128015A0  mov      w0, #-0xae
//   0x3a9018: D65F03C0  ret      
uint64_t fde_func_10267_0x3a9010(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x003A9010ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x128015A0ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD65F03C0ULL ^ (2ULL << 32);
    return state ^ (state >> 29);
}

// FDE #10277 | PC: 0x3a9888..0x3a9898 (16 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x3a9888: D503245F  bti      c
//   0x3a988c: 71002C3F  cmp      w1, #0xb
//   0x3a9890: 1A9F17E0  cset     w0, eq
//   0x3a9894: D65F03C0  ret      
uint64_t fde_func_10277_0x3a9888(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x003A9888ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x71002C3FULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x1A9F17E0ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD65F03C0ULL ^ (3ULL << 32);
    return state ^ (state >> 29);
}

// FDE #10286 | PC: 0x3a9ae4..0x3a9b14 (48 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x3a9ae4: D503245F  bti      c
//   0x3a9ae8: B9400008  ldr      w8, [x0]
//   0x3a9aec: B9400029  ldr      w9, [x1]
//   0x3a9af0: 6B09011F  cmp      w8, w9
//   0x3a9af4: 540000C1  b.ne     #0x3a9b0c
//   0x3a9af8: B9400408  ldr      w8, [x0, #4]
uint64_t fde_func_10286_0x3a9ae4(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x003A9AE4ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB9400008ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB9400029ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x6B09011FULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x540000C1ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB9400408ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB9400429ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x6B09011FULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #10296 | PC: 0x3aa5d8..0x3aa670 (152 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x3aa5d8: D503233F  paciasp  
//   0x3aa5dc: A9BD7BFD  stp      x29, x30, [sp, #-0x30]!
//   0x3aa5e0: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x3aa5e4: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x3aa5e8: 910003FD  mov      x29, sp
//   0x3aa5ec: 3947A008  ldrb     w8, [x0, #0x1e8]
uint64_t fde_func_10296_0x3aa5d8(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x003AA5D8ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BD7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90157F6ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9024FF4ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x3947A008ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x34000108ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x2A1F03F6ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #10305 | PC: 0x3aa758..0x3aa774 (28 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x3aa758: D503245F  bti      c
//   0x3aa75c: F940D800  ldr      x0, [x0, #0x1b0]
//   0x3aa760: B4000080  cbz      x0, #0x3aa770
//   0x3aa764: F9400008  ldr      x8, [x0]
//   0x3aa768: F9405510  ldr      x16, [x8, #0xa8]
//   0x3aa76c: D61F0200  br       x16
uint64_t fde_func_10305_0x3aa758(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x003AA758ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF940D800ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB4000080ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400008ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9405510ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD61F0200ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD65F03C0ULL ^ (6ULL << 32);
    return state ^ (state >> 29);
}

// FDE #10315 | PC: 0x3aa9a8..0x3aaa14 (108 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x3aa9a8: D503233F  paciasp  
//   0x3aa9ac: D100C3FF  sub      sp, sp, #0x30
//   0x3aa9b0: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x3aa9b4: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x3aa9b8: 910043FD  add      x29, sp, #0x10
//   0x3aa9bc: F9400068  ldr      x8, [x3]
uint64_t fde_func_10315_0x3aa9a8(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x003AA9A8ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD100C3FFULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9024FF4ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400068ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF940D400ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #10324 | PC: 0x3aac24..0x3aac38 (20 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x3aac24: D503245F  bti      c
//   0x3aac28: F940D400  ldr      x0, [x0, #0x1a8]
//   0x3aac2c: F9400008  ldr      x8, [x0]
//   0x3aac30: F9404110  ldr      x16, [x8, #0x80]
//   0x3aac34: D61F0200  br       x16
uint64_t fde_func_10324_0x3aac24(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x003AAC24ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF940D400ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400008ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9404110ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD61F0200ULL ^ (4ULL << 32);
    return state ^ (state >> 29);
}

// FDE #10334 | PC: 0x3aacfc..0x3aadfc (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x3aacfc: D503233F  paciasp  
//   0x3aad00: A9BA7BFD  stp      x29, x30, [sp, #-0x60]!
//   0x3aad04: A9016FFC  stp      x28, x27, [sp, #0x10]
//   0x3aad08: A90267FA  stp      x26, x25, [sp, #0x20]
//   0x3aad0c: A9035FF8  stp      x24, x23, [sp, #0x30]
//   0x3aad10: A90457F6  stp      x22, x21, [sp, #0x40]
uint64_t fde_func_10334_0x3aacfc(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x003AACFCULL);
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

// FDE #10343 | PC: 0x3ab4ac..0x3ab4bc (16 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x3ab4ac: D503245F  bti      c
//   0x3ab4b0: 910AE001  add      x1, x0, #0x2b8
//   0x3ab4b4: AA0803E0  mov      x0, x8
//   0x3ab4b8: 17FA2330  b        #0x234178
uint64_t fde_func_10343_0x3ab4ac(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x003AB4ACULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910AE001ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0803E0ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x17FA2330ULL ^ (3ULL << 32);
    return state ^ (state >> 29);
}

// FDE #10353 | PC: 0x3abad4..0x3abaf4 (32 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x3abad4: D503245F  bti      c
//   0x3abad8: A940A408  ldp      x8, x9, [x0, #8]
//   0x3abadc: EB09011F  cmp      x8, x9
//   0x3abae0: 54000082  b.hs     #0x3abaf0
//   0x3abae4: 38001501  strb     w1, [x8], #1
//   0x3abae8: F9000408  str      x8, [x0, #8]
uint64_t fde_func_10353_0x3abad4(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x003ABAD4ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA940A408ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xEB09011FULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x54000082ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x38001501ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000408ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD65F03C0ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x17FBE401ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #10362 | PC: 0x3abd94..0x3abdb4 (32 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x3abd94: D503245F  bti      c
//   0x3abd98: 72001C1F  tst      w0, #0xff
//   0x3abd9c: 54000080  b.eq     #0x3abdac
//   0x3abda0: D0001060  adrp     x0, #0x5b9000
//   0x3abda4: 912BA000  add      x0, x0, #0xae8
//   0x3abda8: 17FB8A75  b        #0x28e77c
uint64_t fde_func_10362_0x3abd94(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x003ABD94ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x72001C1FULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x54000080ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD0001060ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x912BA000ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x17FB8A75ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x2A1F03E0ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD65F03C0ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #10372 | PC: 0x3ac654..0x3ac6e4 (144 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x3ac654: D503233F  paciasp  
//   0x3ac658: D10103FF  sub      sp, sp, #0x40
//   0x3ac65c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x3ac660: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x3ac664: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x3ac668: 910043FD  add      x29, sp, #0x10
uint64_t fde_func_10372_0x3ac654(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x003AC654ULL);
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

// FDE #10381 | PC: 0x3ad070..0x3ad170 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x3ad070: D503233F  paciasp  
//   0x3ad074: A9BA7BFD  stp      x29, x30, [sp, #-0x60]!
//   0x3ad078: A9016FFC  stp      x28, x27, [sp, #0x10]
//   0x3ad07c: A90267FA  stp      x26, x25, [sp, #0x20]
//   0x3ad080: A9035FF8  stp      x24, x23, [sp, #0x30]
//   0x3ad084: A90457F6  stp      x22, x21, [sp, #0x40]
uint64_t fde_func_10381_0x3ad070(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x003AD070ULL);
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

// FDE #10391 | PC: 0x3ae71c..0x3ae768 (76 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x3ae71c: D503245F  bti      c
//   0x3ae720: B4000221  cbz      x1, #0x3ae764
//   0x3ae724: D503233F  paciasp  
//   0x3ae728: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x3ae72c: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x3ae730: 910003FD  mov      x29, sp
uint64_t fde_func_10391_0x3ae71c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x003AE71CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB4000221ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE7BFDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9014FF4ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0103F3ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F4ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #10400 | PC: 0x3aec18..0x3aecec (212 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x3aec18: D503233F  paciasp  
//   0x3aec1c: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x3aec20: F9000BF3  str      x19, [sp, #0x10]
//   0x3aec24: 910003FD  mov      x29, sp
//   0x3aec28: D0000F88  adrp     x8, #0x5a0000
//   0x3aec2c: 91144108  add      x8, x8, #0x510
uint64_t fde_func_10400_0x3aec18(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x003AEC18ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF3ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD0000F88ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91144108ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD0000F89ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91194129ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #10410 | PC: 0x3afc7c..0x3afd10 (148 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x3afc7c: D503233F  paciasp  
//   0x3afc80: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x3afc84: F9000BF3  str      x19, [sp, #0x10]
//   0x3afc88: 910003FD  mov      x29, sp
//   0x3afc8c: AA0003F3  mov      x19, x0
//   0x3afc90: 52800028  mov      w8, #1
uint64_t fde_func_10410_0x3afc7c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x003AFC7CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF3ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x52800028ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9415C00ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x39125A68ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #10420 | PC: 0x3afe64..0x3aff64 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x3afe64: D503233F  paciasp  
//   0x3afe68: A9BD7BFD  stp      x29, x30, [sp, #-0x30]!
//   0x3afe6c: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x3afe70: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x3afe74: 910003FD  mov      x29, sp
//   0x3afe78: AA0003F4  mov      x20, x0
uint64_t fde_func_10420_0x3afe64(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x003AFE64ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BD7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90157F6ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9024FF4ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F4ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0103E0ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0103F3ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #10429 | PC: 0x3b02a8..0x3b03a8 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x3b02a8: D503233F  paciasp  
//   0x3b02ac: D10643FF  sub      sp, sp, #0x190
//   0x3b02b0: A9147BFD  stp      x29, x30, [sp, #0x140]
//   0x3b02b4: A91567FC  stp      x28, x25, [sp, #0x150]
//   0x3b02b8: A9165FF8  stp      x24, x23, [sp, #0x160]
//   0x3b02bc: A91757F6  stp      x22, x21, [sp, #0x170]
uint64_t fde_func_10429_0x3b02a8(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x003B02A8ULL);
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

// FDE #10439 | PC: 0x3b0524..0x3b0530 (12 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x3b0524: D503245F  bti      c
//   0x3b0528: AA1F03E1  mov      x1, xzr
//   0x3b052c: 17FFFFD9  b        #0x3b0490
uint64_t fde_func_10439_0x3b0524(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x003B0524ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA1F03E1ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x17FFFFD9ULL ^ (2ULL << 32);
    return state ^ (state >> 29);
}

// FDE #10448 | PC: 0x3b1620..0x3b16e4 (196 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x3b1620: D503233F  paciasp  
//   0x3b1624: D10103FF  sub      sp, sp, #0x40
//   0x3b1628: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x3b162c: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x3b1630: 910083FD  add      x29, sp, #0x20
//   0x3b1634: AA0003F3  mov      x19, x0
uint64_t fde_func_10448_0x3b1620(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x003B1620ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10103FFULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9027BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9034FF4ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910083FDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91068000ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF940D268ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #10458 | PC: 0x3b1a94..0x3b1ab4 (32 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x3b1a94: D503245F  bti      c
//   0x3b1a98: F9416400  ldr      x0, [x0, #0x2c8]
//   0x3b1a9c: B40000A0  cbz      x0, #0x3b1ab0
//   0x3b1aa0: 885F7C08  ldxr     w8, [x0]
//   0x3b1aa4: 11000508  add      w8, w8, #1
//   0x3b1aa8: 88097C08  stxr     w9, w8, [x0]
uint64_t fde_func_10458_0x3b1a94(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x003B1A94ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9416400ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB40000A0ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x885F7C08ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x11000508ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x88097C08ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x35FFFFA9ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD65F03C0ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #10467 | PC: 0x3b1c18..0x3b1c50 (56 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x3b1c18: D503233F  paciasp  
//   0x3b1c1c: D10083FF  sub      sp, sp, #0x20
//   0x3b1c20: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x3b1c24: 910043FD  add      x29, sp, #0x10
//   0x3b1c28: F9400068  ldr      x8, [x3]
//   0x3b1c2c: F900007F  str      xzr, [x3]
uint64_t fde_func_10467_0x3b1c18(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x003B1C18ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10083FFULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400068ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF900007FULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910023E3ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF90007E8ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #10477 | PC: 0x3b1d38..0x3b1d84 (76 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x3b1d38: D503233F  paciasp  
//   0x3b1d3c: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x3b1d40: F9000BF3  str      x19, [sp, #0x10]
//   0x3b1d44: 910003FD  mov      x29, sp
//   0x3b1d48: AA0003F3  mov      x19, x0
//   0x3b1d4c: F940D000  ldr      x0, [x0, #0x1a0]
uint64_t fde_func_10477_0x3b1d38(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x003B1D38ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF3ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF940D000ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF0000F68ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91200108ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #10486 | PC: 0x3b2190..0x3b2290 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x3b2190: D503233F  paciasp  
//   0x3b2194: D10243FF  sub      sp, sp, #0x90
//   0x3b2198: A9047BFD  stp      x29, x30, [sp, #0x40]
//   0x3b219c: F9002BF9  str      x25, [sp, #0x50]
//   0x3b21a0: A9065FF8  stp      x24, x23, [sp, #0x60]
//   0x3b21a4: A90757F6  stp      x22, x21, [sp, #0x70]
uint64_t fde_func_10486_0x3b2190(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x003B2190ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10243FFULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9047BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9002BF9ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9065FF8ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90757F6ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9084FF4ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910103FDULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #10496 | PC: 0x3b2730..0x3b2740 (16 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x3b2730: D503245F  bti      c
//   0x3b2734: F940D808  ldr      x8, [x0, #0x1b0]
//   0x3b2738: 91008100  add      x0, x8, #0x20
//   0x3b273c: D65F03C0  ret      
uint64_t fde_func_10496_0x3b2730(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x003B2730ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF940D808ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91008100ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD65F03C0ULL ^ (3ULL << 32);
    return state ^ (state >> 29);
}

// FDE #10505 | PC: 0x3b2a84..0x3b2aac (40 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x3b2a84: D503245F  bti      c
//   0x3b2a88: F940D808  ldr      x8, [x0, #0x1b0]
//   0x3b2a8c: B40000C8  cbz      x8, #0x3b2aa4
//   0x3b2a90: F9403108  ldr      x8, [x8, #0x60]
//   0x3b2a94: B4000088  cbz      x8, #0x3b2aa4
//   0x3b2a98: F9400508  ldr      x8, [x8, #8]
uint64_t fde_func_10505_0x3b2a84(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x003B2A84ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF940D808ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB40000C8ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9403108ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB4000088ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400508ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB9400900ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD65F03C0ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #10515 | PC: 0x3b30a0..0x3b31a0 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x3b30a0: D503233F  paciasp  
//   0x3b30a4: D104C3FF  sub      sp, sp, #0x130
//   0x3b30a8: 6D0C23E9  stp      d9, d8, [sp, #0xc0]
//   0x3b30ac: A90D7BFD  stp      x29, x30, [sp, #0xd0]
//   0x3b30b0: A90E6FFC  stp      x28, x27, [sp, #0xe0]
//   0x3b30b4: A90F67FA  stp      x26, x25, [sp, #0xf0]
uint64_t fde_func_10515_0x3b30a0(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x003B30A0ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD104C3FFULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x6D0C23E9ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90D7BFDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90E6FFCULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90F67FAULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9105FF8ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA91157F6ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #10524 | PC: 0x3b3b74..0x3b3c74 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x3b3b74: D503233F  paciasp  
//   0x3b3b78: D10283FF  sub      sp, sp, #0xa0
//   0x3b3b7c: A9057BFD  stp      x29, x30, [sp, #0x50]
//   0x3b3b80: F90033F9  str      x25, [sp, #0x60]
//   0x3b3b84: A9075FF8  stp      x24, x23, [sp, #0x70]
//   0x3b3b88: A90857F6  stp      x22, x21, [sp, #0x80]
uint64_t fde_func_10524_0x3b3b74(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x003B3B74ULL);
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

// FDE #10534 | PC: 0x3b42e8..0x3b4314 (44 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x3b42e8: D503233F  paciasp  
//   0x3b42ec: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x3b42f0: F9000BF3  str      x19, [sp, #0x10]
//   0x3b42f4: 910003FD  mov      x29, sp
//   0x3b42f8: AA0003F3  mov      x19, x0
//   0x3b42fc: 97FFFFAF  bl       #0x3b41b8
uint64_t fde_func_10534_0x3b42e8(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x003B42E8ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF3ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x97FFFFAFULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA1303E0ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400BF3ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #10543 | PC: 0x3b5214..0x3b5314 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x3b5214: D503233F  paciasp  
//   0x3b5218: D10183FF  sub      sp, sp, #0x60
//   0x3b521c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x3b5220: A90267FA  stp      x26, x25, [sp, #0x20]
//   0x3b5224: A9035FF8  stp      x24, x23, [sp, #0x30]
//   0x3b5228: A90457F6  stp      x22, x21, [sp, #0x40]
uint64_t fde_func_10543_0x3b5214(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x003B5214ULL);
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

// FDE #10553 | PC: 0x3b5bb0..0x3b5c0c (92 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x3b5bb0: D503233F  paciasp  
//   0x3b5bb4: A9BD7BFD  stp      x29, x30, [sp, #-0x30]!
//   0x3b5bb8: F9000BF5  str      x21, [sp, #0x10]
//   0x3b5bbc: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x3b5bc0: 910003FD  mov      x29, sp
//   0x3b5bc4: AA0003F5  mov      x21, x0
uint64_t fde_func_10553_0x3b5bb0(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x003B5BB0ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BD7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF5ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9024FF4ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F5ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91042000ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0303F3ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #10562 | PC: 0x3b5ea0..0x3b5eac (12 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x3b5ea0: D503245F  bti      c
//   0x3b5ea4: D100C000  sub      x0, x0, #0x30
//   0x3b5ea8: 17FFF8C4  b        #0x3b41b8
uint64_t fde_func_10562_0x3b5ea0(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x003B5EA0ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD100C000ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x17FFF8C4ULL ^ (2ULL << 32);
    return state ^ (state >> 29);
}

// FDE #10572 | PC: 0x3b6074..0x3b6174 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x3b6074: D503233F  paciasp  
//   0x3b6078: D10143FF  sub      sp, sp, #0x50
//   0x3b607c: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x3b6080: A90357F6  stp      x22, x21, [sp, #0x30]
//   0x3b6084: A9044FF4  stp      x20, x19, [sp, #0x40]
//   0x3b6088: 910083FD  add      x29, sp, #0x20
uint64_t fde_func_10572_0x3b6074(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x003B6074ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10143FFULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9027BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90357F6ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9044FF4ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910083FDULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0203E0ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #10581 | PC: 0x3b71a0..0x3b71e8 (72 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x3b71a0: D503233F  paciasp  
//   0x3b71a4: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x3b71a8: F9000BF3  str      x19, [sp, #0x10]
//   0x3b71ac: 910003FD  mov      x29, sp
//   0x3b71b0: F9400013  ldr      x19, [x0]
//   0x3b71b4: F9000001  str      x1, [x0]
uint64_t fde_func_10581_0x3b71a0(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x003B71A0ULL);
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

// FDE #10591 | PC: 0x3b77f8..0x3b7850 (88 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x3b77f8: D503245F  bti      c
//   0x3b77fc: 52800308  mov      w8, #0x18
//   0x3b7800: F9400469  ldr      x9, [x3, #8]
//   0x3b7804: D503201F  nop      
//   0x3b7808: 9BA8044A  umaddl   x10, w2, w8, x1
//   0x3b780c: EB0A013F  cmp      x9, x10
uint64_t fde_func_10591_0x3b77f8(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x003B77F8ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x52800308ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400469ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503201FULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9BA8044AULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xEB0A013FULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x540000A1ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x34000122ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #10600 | PC: 0x3b7e94..0x3b7eac (24 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x3b7e94: D503245F  bti      c
//   0x3b7e98: 9100E028  add      x8, x1, #0x38
//   0x3b7e9c: AA0003E2  mov      x2, x0
//   0x3b7ea0: AA0803E0  mov      x0, x8
//   0x3b7ea4: 52800CC1  mov      w1, #0x66
//   0x3b7ea8: 17FEF1B6  b        #0x374580
uint64_t fde_func_10600_0x3b7e94(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x003B7E94ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9100E028ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003E2ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0803E0ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x52800CC1ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x17FEF1B6ULL ^ (5ULL << 32);
    return state ^ (state >> 29);
}

// FDE #10610 | PC: 0x3b8b70..0x3b8bac (60 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x3b8b70: D503245F  bti      c
//   0x3b8b74: B40001A0  cbz      x0, #0x3b8ba8
//   0x3b8b78: D503233F  paciasp  
//   0x3b8b7c: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x3b8b80: F9000BF3  str      x19, [sp, #0x10]
//   0x3b8b84: 910003FD  mov      x29, sp
uint64_t fde_func_10610_0x3b8b70(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x003B8B70ULL);
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

// FDE #10619 | PC: 0x3b95b0..0x3b96b0 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x3b95b0: D503233F  paciasp  
//   0x3b95b4: A9BD7BFD  stp      x29, x30, [sp, #-0x30]!
//   0x3b95b8: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x3b95bc: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x3b95c0: 910003FD  mov      x29, sp
//   0x3b95c4: AA0003F3  mov      x19, x0
uint64_t fde_func_10619_0x3b95b0(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x003B95B0ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BD7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90157F6ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9024FF4ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9413800ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF0000F28ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #10629 | PC: 0x3ba090..0x3ba158 (200 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x3ba090: D503233F  paciasp  
//   0x3ba094: D101C3FF  sub      sp, sp, #0x70
//   0x3ba098: A9037BFD  stp      x29, x30, [sp, #0x30]
//   0x3ba09c: A9045FF8  stp      x24, x23, [sp, #0x40]
//   0x3ba0a0: A90557F6  stp      x22, x21, [sp, #0x50]
//   0x3ba0a4: A9064FF4  stp      x20, x19, [sp, #0x60]
uint64_t fde_func_10629_0x3ba090(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x003BA090ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD101C3FFULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9037BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9045FF8ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90557F6ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9064FF4ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9100C3FDULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0103F5ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #10638 | PC: 0x3ba4b4..0x3ba50c (88 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x3ba4b4: D503233F  paciasp  
//   0x3ba4b8: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x3ba4bc: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x3ba4c0: 910003FD  mov      x29, sp
//   0x3ba4c4: A9405028  ldp      x8, x20, [x1]
//   0x3ba4c8: AA0103F3  mov      x19, x1
uint64_t fde_func_10638_0x3ba4b4(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x003BA4B4ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9014FF4ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9405028ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0103F3ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000514ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9402428ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #10648 | PC: 0x3bacb4..0x3bad00 (76 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x3bacb4: D503245F  bti      c
//   0x3bacb8: B4000220  cbz      x0, #0x3bacfc
//   0x3bacbc: D503233F  paciasp  
//   0x3bacc0: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x3bacc4: F9000BF3  str      x19, [sp, #0x10]
//   0x3bacc8: 910003FD  mov      x29, sp
uint64_t fde_func_10648_0x3bacb4(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x003BACB4ULL);
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

// FDE #10657 | PC: 0x3bb2d8..0x3bb2e8 (16 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x3bb2d8: D503245F  bti      c
//   0x3bb2dc: 910DE001  add      x1, x0, #0x378
//   0x3bb2e0: AA0803E0  mov      x0, x8
//   0x3bb2e4: 17FE5AFA  b        #0x351ecc
uint64_t fde_func_10657_0x3bb2d8(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x003BB2D8ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910DE001ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0803E0ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x17FE5AFAULL ^ (3ULL << 32);
    return state ^ (state >> 29);
}

// FDE #10667 | PC: 0x3bc708..0x3bc808 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x3bc708: D503233F  paciasp  
//   0x3bc70c: D10183FF  sub      sp, sp, #0x60
//   0x3bc710: A9037BFD  stp      x29, x30, [sp, #0x30]
//   0x3bc714: A90457F6  stp      x22, x21, [sp, #0x40]
//   0x3bc718: A9054FF4  stp      x20, x19, [sp, #0x50]
//   0x3bc71c: 9100C3FD  add      x29, sp, #0x30
uint64_t fde_func_10667_0x3bc708(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x003BC708ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10183FFULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9037BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90457F6ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9054FF4ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9100C3FDULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0203F5ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x2A0103F4ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #10676 | PC: 0x3bcb24..0x3bcb30 (12 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x3bcb24: D503245F  bti      c
//   0x3bcb28: 2A1F03E1  mov      w1, wzr
//   0x3bcb2c: 14000001  b        #0x3bcb30
uint64_t fde_func_10676_0x3bcb24(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x003BCB24ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x2A1F03E1ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x14000001ULL ^ (2ULL << 32);
    return state ^ (state >> 29);
}

// FDE #10686 | PC: 0x3bd570..0x3bd584 (20 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x3bd570: D503245F  bti      c
//   0x3bd574: F940D400  ldr      x0, [x0, #0x1a8]
//   0x3bd578: F9400008  ldr      x8, [x0]
//   0x3bd57c: F9402510  ldr      x16, [x8, #0x48]
//   0x3bd580: D61F0200  br       x16
uint64_t fde_func_10686_0x3bd570(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x003BD570ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF940D400ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400008ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9402510ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD61F0200ULL ^ (4ULL << 32);
    return state ^ (state >> 29);
}

// FDE #10695 | PC: 0x3bd660..0x3bd674 (20 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x3bd660: D503245F  bti      c
//   0x3bd664: F940D400  ldr      x0, [x0, #0x1a8]
//   0x3bd668: F9400008  ldr      x8, [x0]
//   0x3bd66c: F9405D10  ldr      x16, [x8, #0xb8]
//   0x3bd670: D61F0200  br       x16
uint64_t fde_func_10695_0x3bd660(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x003BD660ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF940D400ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400008ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9405D10ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD61F0200ULL ^ (4ULL << 32);
    return state ^ (state >> 29);
}

// FDE #10705 | PC: 0x3bdca0..0x3bdcc4 (36 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x3bdca0: D503245F  bti      c
//   0x3bdca4: B9404408  ldr      w8, [x0, #0x44]
//   0x3bdca8: 7200003F  tst      w1, #1
//   0x3bdcac: 52810009  mov      w9, #0x800
//   0x3bdcb0: 1A9F1129  csel     w9, w9, wzr, ne
//   0x3bdcb4: 12147908  and      w8, w8, #0xfffff7ff
uint64_t fde_func_10705_0x3bdca0(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x003BDCA0ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB9404408ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x7200003FULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x52810009ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x1A9F1129ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x12147908ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x2A090108ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB9004408ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #10715 | PC: 0x3bdf9c..0x3be09c (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x3bdf9c: D503233F  paciasp  
//   0x3bdfa0: D10683FF  sub      sp, sp, #0x1a0
//   0x3bdfa4: A9157BFD  stp      x29, x30, [sp, #0x150]
//   0x3bdfa8: A91667FC  stp      x28, x25, [sp, #0x160]
//   0x3bdfac: A9175FF8  stp      x24, x23, [sp, #0x170]
//   0x3bdfb0: A91857F6  stp      x22, x21, [sp, #0x180]
uint64_t fde_func_10715_0x3bdf9c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x003BDF9CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10683FFULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9157BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA91667FCULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9175FF8ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA91857F6ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9194FF4ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910543FDULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #10724 | PC: 0x3be434..0x3be440 (12 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x3be434: D503245F  bti      c
//   0x3be438: D1002000  sub      x0, x0, #8
//   0x3be43c: 17FFFD42  b        #0x3bd944
uint64_t fde_func_10724_0x3be434(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x003BE434ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD1002000ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x17FFFD42ULL ^ (2ULL << 32);
    return state ^ (state >> 29);
}

// FDE #10734 | PC: 0x3be71c..0x3be7c0 (164 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x3be71c: D503233F  paciasp  
//   0x3be720: D10143FF  sub      sp, sp, #0x50
//   0x3be724: A9037BFD  stp      x29, x30, [sp, #0x30]
//   0x3be728: A9044FF4  stp      x20, x19, [sp, #0x40]
//   0x3be72c: 9100C3FD  add      x29, sp, #0x30
//   0x3be730: AA0003F3  mov      x19, x0
uint64_t fde_func_10734_0x3be71c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x003BE71CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10143FFULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9037BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9044FF4ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9100C3FDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003E0ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0203F4ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #10743 | PC: 0x3bebe8..0x3bec5c (116 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x3bebe8: D503233F  paciasp  
//   0x3bebec: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x3bebf0: F9000BF3  str      x19, [sp, #0x10]
//   0x3bebf4: 910003FD  mov      x29, sp
//   0x3bebf8: F0000F08  adrp     x8, #0x5a1000
//   0x3bebfc: 91070108  add      x8, x8, #0x1c0
uint64_t fde_func_10743_0x3bebe8(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x003BEBE8ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF3ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF0000F08ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91070108ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF0FFE982ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91360042ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #10753 | PC: 0x3bf618..0x3bf67c (100 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x3bf618: D503245F  bti      c
//   0x3bf61c: B40002E2  cbz      x2, #0x3bf678
//   0x3bf620: D503233F  paciasp  
//   0x3bf624: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x3bf628: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x3bf62c: 910003FD  mov      x29, sp
uint64_t fde_func_10753_0x3bf618(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x003BF618ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB40002E2ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE7BFDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9014FF4ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0103F3ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F4ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #10762 | PC: 0x3bfb74..0x3bfbc0 (76 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x3bfb74: D503245F  bti      c
//   0x3bfb78: B4000220  cbz      x0, #0x3bfbbc
//   0x3bfb7c: D503233F  paciasp  
//   0x3bfb80: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x3bfb84: F9000BF3  str      x19, [sp, #0x10]
//   0x3bfb88: 910003FD  mov      x29, sp
uint64_t fde_func_10762_0x3bfb74(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x003BFB74ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB4000220ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE7BFDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF3ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9402800ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #10772 | PC: 0x3c0244..0x3c0344 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x3c0244: D503233F  paciasp  
//   0x3c0248: A9BD7BFD  stp      x29, x30, [sp, #-0x30]!
//   0x3c024c: F9000BF5  str      x21, [sp, #0x10]
//   0x3c0250: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x3c0254: 910003FD  mov      x29, sp
//   0x3c0258: 2A0103F4  mov      w20, w1
uint64_t fde_func_10772_0x3c0244(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x003C0244ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BD7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF5ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9024FF4ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x2A0103F4ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB40003E2ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #10781 | PC: 0x3c07ac..0x3c0850 (164 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x3c07ac: D503233F  paciasp  
//   0x3c07b0: A9BD7BFD  stp      x29, x30, [sp, #-0x30]!
//   0x3c07b4: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x3c07b8: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x3c07bc: 910003FD  mov      x29, sp
//   0x3c07c0: B9402008  ldr      w8, [x0, #0x20]
uint64_t fde_func_10781_0x3c07ac(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x003C07ACULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BD7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90157F6ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9024FF4ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB9402008ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x340000E8ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x2A1F03E0ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #10791 | PC: 0x3c0c2c..0x3c0c3c (16 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x3c0c2c: D503245F  bti      c
//   0x3c0c30: 52800028  mov      w8, #1
//   0x3c0c34: 39006408  strb     w8, [x0, #0x19]
//   0x3c0c38: D65F03C0  ret      
uint64_t fde_func_10791_0x3c0c2c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x003C0C2CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x52800028ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x39006408ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD65F03C0ULL ^ (3ULL << 32);
    return state ^ (state >> 29);
}

// FDE #10800 | PC: 0x3c0f7c..0x3c107c (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x3c0f7c: D503233F  paciasp  
//   0x3c0f80: D10743FF  sub      sp, sp, #0x1d0
//   0x3c0f84: A9177BFD  stp      x29, x30, [sp, #0x170]
//   0x3c0f88: A9186FFC  stp      x28, x27, [sp, #0x180]
//   0x3c0f8c: A91967FA  stp      x26, x25, [sp, #0x190]
//   0x3c0f90: A91A5FF8  stp      x24, x23, [sp, #0x1a0]
uint64_t fde_func_10800_0x3c0f7c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x003C0F7CULL);
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

// FDE #10810 | PC: 0x3c151c..0x3c1610 (244 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x3c151c: D503233F  paciasp  
//   0x3c1520: A9BD7BFD  stp      x29, x30, [sp, #-0x30]!
//   0x3c1524: F9000BF5  str      x21, [sp, #0x10]
//   0x3c1528: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x3c152c: 910003FD  mov      x29, sp
//   0x3c1530: 52800028  mov      w8, #1
uint64_t fde_func_10810_0x3c151c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x003C151CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BD7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF5ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9024FF4ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x52800028ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9104E015ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #10819 | PC: 0x3c1698..0x3c16a4 (12 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x3c1698: D503245F  bti      c
//   0x3c169c: D1002000  sub      x0, x0, #8
//   0x3c16a0: 17FFFD73  b        #0x3c0c6c
uint64_t fde_func_10819_0x3c1698(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x003C1698ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD1002000ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x17FFFD73ULL ^ (2ULL << 32);
    return state ^ (state >> 29);
}

// FDE #10829 | PC: 0x3c1b28..0x3c1b84 (92 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x3c1b28: D503233F  paciasp  
//   0x3c1b2c: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x3c1b30: F9000BF3  str      x19, [sp, #0x10]
//   0x3c1b34: 910003FD  mov      x29, sp
//   0x3c1b38: AA0003F3  mov      x19, x0
//   0x3c1b3c: 90000F08  adrp     x8, #0x5a1000
uint64_t fde_func_10829_0x3c1b28(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x003C1B28ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF3ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x90000F08ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9116C108ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF940D000ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #10838 | PC: 0x3c1c9c..0x3c1d9c (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x3c1c9c: D503233F  paciasp  
//   0x3c1ca0: D105C3FF  sub      sp, sp, #0x170
//   0x3c1ca4: A9127BFD  stp      x29, x30, [sp, #0x120]
//   0x3c1ca8: F9009BFC  str      x28, [sp, #0x130]
//   0x3c1cac: A9145FF8  stp      x24, x23, [sp, #0x140]
//   0x3c1cb0: A91557F6  stp      x22, x21, [sp, #0x150]
uint64_t fde_func_10838_0x3c1c9c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x003C1C9CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD105C3FFULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9127BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9009BFCULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9145FF8ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA91557F6ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9164FF4ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910483FDULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #10848 | PC: 0x3c1f90..0x3c2040 (176 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x3c1f90: D503233F  paciasp  
//   0x3c1f94: D10103FF  sub      sp, sp, #0x40
//   0x3c1f98: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x3c1f9c: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x3c1fa0: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x3c1fa4: 910043FD  add      x29, sp, #0x10
uint64_t fde_func_10848_0x3c1f90(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x003C1F90ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10103FFULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90257F6ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9034FF4ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB4000242ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF940CC08ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #10857 | PC: 0x3c2314..0x3c2328 (20 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x3c2314: D503245F  bti      c
//   0x3c2318: F0000EE8  adrp     x8, #0x5a1000
//   0x3c231c: 911AC108  add      x8, x8, #0x6b0
//   0x3c2320: F8008408  str      x8, [x0], #8
//   0x3c2324: 14069BC3  b        #0x569230
uint64_t fde_func_10857_0x3c2314(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x003C2314ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF0000EE8ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x911AC108ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF8008408ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x14069BC3ULL ^ (4ULL << 32);
    return state ^ (state >> 29);
}

// FDE #10867 | PC: 0x3c2924..0x3c2960 (60 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x3c2924: D503245F  bti      c
//   0x3c2928: 12001C2B  and      w11, w1, #0xff
//   0x3c292c: 52800309  mov      w9, #0x18
//   0x3c2930: 2A0B03E8  mov      w8, w11
//   0x3c2934: 37F8010B  tbnz     w11, #0x1f, #0x3c2954
//   0x3c2938: 9BA9010A  umaddl   x10, w8, w9, x0
uint64_t fde_func_10867_0x3c2924(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x003C2924ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x12001C2BULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x52800309ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x2A0B03E8ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x37F8010BULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9BA9010AULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x5100050BULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF940094CULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #10876 | PC: 0x3c2f80..0x3c2fe0 (96 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x3c2f80: D503233F  paciasp  
//   0x3c2f84: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x3c2f88: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x3c2f8c: 910003FD  mov      x29, sp
//   0x3c2f90: F9400008  ldr      x8, [x0]
//   0x3c2f94: AA0003F4  mov      x20, x0
uint64_t fde_func_10876_0x3c2f80(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x003C2F80ULL);
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

// FDE #10886 | PC: 0x3c3404..0x3c34ac (168 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x3c3404: D503233F  paciasp  
//   0x3c3408: D10243FF  sub      sp, sp, #0x90
//   0x3c340c: A9067BFD  stp      x29, x30, [sp, #0x60]
//   0x3c3410: F9003BF5  str      x21, [sp, #0x70]
//   0x3c3414: A9084FF4  stp      x20, x19, [sp, #0x80]
//   0x3c3418: 910183FD  add      x29, sp, #0x60
uint64_t fde_func_10886_0x3c3404(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x003C3404ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10243FFULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9067BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9003BF5ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9084FF4ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910183FDULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400808ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB40003A8ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #10895 | PC: 0x3c36d0..0x3c3728 (88 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x3c36d0: D503233F  paciasp  
//   0x3c36d4: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x3c36d8: F9000BF3  str      x19, [sp, #0x10]
//   0x3c36dc: 910003FD  mov      x29, sp
//   0x3c36e0: B40001C0  cbz      x0, #0x3c3718
//   0x3c36e4: AA0003F3  mov      x19, x0
uint64_t fde_func_10895_0x3c36d0(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x003C36D0ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF3ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB40001C0ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x885FFE68ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x71000508ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #10905 | PC: 0x3c3a5c..0x3c3b5c (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x3c3a5c: D503233F  paciasp  
//   0x3c3a60: A9BB7BFD  stp      x29, x30, [sp, #-0x50]!
//   0x3c3a64: A90167FC  stp      x28, x25, [sp, #0x10]
//   0x3c3a68: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x3c3a6c: A90357F6  stp      x22, x21, [sp, #0x30]
//   0x3c3a70: A9044FF4  stp      x20, x19, [sp, #0x40]
uint64_t fde_func_10905_0x3c3a5c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x003C3A5CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BB7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90167FCULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9025FF8ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90357F6ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9044FF4ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10C83FFULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #10914 | PC: 0x3c413c..0x3c423c (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x3c413c: D503233F  paciasp  
//   0x3c4140: D10383FF  sub      sp, sp, #0xe0
//   0x3c4144: A9087BFD  stp      x29, x30, [sp, #0x80]
//   0x3c4148: A9096FFC  stp      x28, x27, [sp, #0x90]
//   0x3c414c: A90A67FA  stp      x26, x25, [sp, #0xa0]
//   0x3c4150: A90B5FF8  stp      x24, x23, [sp, #0xb0]
uint64_t fde_func_10914_0x3c413c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x003C413CULL);
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

// FDE #10924 | PC: 0x3c4a84..0x3c4aa4 (32 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x3c4a84: D503245F  bti      c
//   0x3c4a88: 52800088  mov      w8, #4
//   0x3c4a8c: B9000828  str      w8, [x1, #8]
//   0x3c4a90: B9436008  ldr      w8, [x0, #0x360]
//   0x3c4a94: B9001828  str      w8, [x1, #0x18]
//   0x3c4a98: B9436408  ldr      w8, [x0, #0x364]
uint64_t fde_func_10924_0x3c4a84(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x003C4A84ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x52800088ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB9000828ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB9436008ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB9001828ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB9436408ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB9001C28ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD65F03C0ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #10933 | PC: 0x3c4ca4..0x3c4d00 (92 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x3c4ca4: D503233F  paciasp  
//   0x3c4ca8: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x3c4cac: F9000BF3  str      x19, [sp, #0x10]
//   0x3c4cb0: 910003FD  mov      x29, sp
//   0x3c4cb4: 91008013  add      x19, x0, #0x20
//   0x3c4cb8: AA1303E0  mov      x0, x19
uint64_t fde_func_10933_0x3c4ca4(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x003C4CA4ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF3ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91008013ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA1303E0ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x97F8599CULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x36000160ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #10943 | PC: 0x3c4d88..0x3c4d94 (12 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x3c4d88: D503245F  bti      c
//   0x3c4d8c: 39452000  ldrb     w0, [x0, #0x148]
//   0x3c4d90: D65F03C0  ret      
uint64_t fde_func_10943_0x3c4d88(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x003C4D88ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x39452000ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD65F03C0ULL ^ (2ULL << 32);
    return state ^ (state >> 29);
}

// FDE #10952 | PC: 0x3c4e50..0x3c4e5c (12 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x3c4e50: D503245F  bti      c
//   0x3c4e54: D1002000  sub      x0, x0, #8
//   0x3c4e58: 17FFFF1B  b        #0x3c4ac4
uint64_t fde_func_10952_0x3c4e50(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x003C4E50ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD1002000ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x17FFFF1BULL ^ (2ULL << 32);
    return state ^ (state >> 29);
}

// FDE #10962 | PC: 0x3c4f78..0x3c4fe8 (112 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x3c4f78: D503233F  paciasp  
//   0x3c4f7c: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x3c4f80: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x3c4f84: 910003FD  mov      x29, sp
//   0x3c4f88: AA0103F3  mov      x19, x1
//   0x3c4f8c: 340000E2  cbz      w2, #0x3c4fa8
uint64_t fde_func_10962_0x3c4f78(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x003C4F78ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9014FF4ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0103F3ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x340000E2ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA1303E0ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x2A0203E1ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #10971 | PC: 0x3c55d4..0x3c56d4 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x3c55d4: D503233F  paciasp  
//   0x3c55d8: D10343FF  sub      sp, sp, #0xd0
//   0x3c55dc: A9077BFD  stp      x29, x30, [sp, #0x70]
//   0x3c55e0: A9086FFC  stp      x28, x27, [sp, #0x80]
//   0x3c55e4: A90967FA  stp      x26, x25, [sp, #0x90]
//   0x3c55e8: A90A5FF8  stp      x24, x23, [sp, #0xa0]
uint64_t fde_func_10971_0x3c55d4(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x003C55D4ULL);
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

// FDE #10981 | PC: 0x3c631c..0x3c6340 (36 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x3c631c: D503233F  paciasp  
//   0x3c6320: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x3c6324: 910003FD  mov      x29, sp
//   0x3c6328: 91072000  add      x0, x0, #0x1c8
//   0x3c632c: 97FB1468  bl       #0x28b4cc
//   0x3c6330: 2A1F03E0  mov      w0, wzr
uint64_t fde_func_10981_0x3c631c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x003C631CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BF7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91072000ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x97FB1468ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x2A1F03E0ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA8C17BFDULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD50323BFULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #10990 | PC: 0x3c664c..0x3c6664 (24 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x3c664c: D503245F  bti      c
//   0x3c6650: F9435C09  ldr      x9, [x0, #0x6b8]
//   0x3c6654: 91132008  add      x8, x0, #0x4c8
//   0x3c6658: F100013F  cmp      x9, #0
//   0x3c665c: 9A8803E0  csel     x0, xzr, x8, eq
//   0x3c6660: D65F03C0  ret      
uint64_t fde_func_10990_0x3c664c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x003C664CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9435C09ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91132008ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF100013FULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9A8803E0ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD65F03C0ULL ^ (5ULL << 32);
    return state ^ (state >> 29);
}

// FDE #11000 | PC: 0x3c6a80..0x3c6a8c (12 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x3c6a80: D503245F  bti      c
//   0x3c6a84: D106A000  sub      x0, x0, #0x1a8
//   0x3c6a88: 17FFFF02  b        #0x3c6690
uint64_t fde_func_11000_0x3c6a80(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x003C6A80ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD106A000ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x17FFFF02ULL ^ (2ULL << 32);
    return state ^ (state >> 29);
}

// FDE #11010 | PC: 0x3c6ca0..0x3c6ce8 (72 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x3c6ca0: D503233F  paciasp  
//   0x3c6ca4: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x3c6ca8: F9000BF3  str      x19, [sp, #0x10]
//   0x3c6cac: 910003FD  mov      x29, sp
//   0x3c6cb0: AA0003F3  mov      x19, x0
//   0x3c6cb4: 9400000D  bl       #0x3c6ce8
uint64_t fde_func_11010_0x3c6ca0(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x003C6CA0ULL);
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

// FDE #11019 | PC: 0x3c747c..0x3c757c (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x3c747c: D503233F  paciasp  
//   0x3c7480: A9BB7BFD  stp      x29, x30, [sp, #-0x50]!
//   0x3c7484: F9000BF9  str      x25, [sp, #0x10]
//   0x3c7488: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x3c748c: A90357F6  stp      x22, x21, [sp, #0x30]
//   0x3c7490: A9044FF4  stp      x20, x19, [sp, #0x40]
uint64_t fde_func_11019_0x3c747c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x003C747CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BB7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF9ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9025FF8ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90357F6ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9044FF4ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0203F5ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #11029 | PC: 0x3c8aec..0x3c8bec (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x3c8aec: D503233F  paciasp  
//   0x3c8af0: A9BC7BFD  stp      x29, x30, [sp, #-0x40]!
//   0x3c8af4: F9000BF7  str      x23, [sp, #0x10]
//   0x3c8af8: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x3c8afc: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x3c8b00: 910003FD  mov      x29, sp
uint64_t fde_func_11029_0x3c8aec(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x003C8AECULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BC7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF7ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90257F6ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9034FF4ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91000435ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xEB55F3FFULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #11038 | PC: 0x3c94d8..0x3c95d8 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x3c94d8: D503233F  paciasp  
//   0x3c94dc: D10703FF  sub      sp, sp, #0x1c0
//   0x3c94e0: A9167BFD  stp      x29, x30, [sp, #0x160]
//   0x3c94e4: F900BBFC  str      x28, [sp, #0x170]
//   0x3c94e8: A91867FA  stp      x26, x25, [sp, #0x180]
//   0x3c94ec: A9195FF8  stp      x24, x23, [sp, #0x190]
uint64_t fde_func_11038_0x3c94d8(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x003C94D8ULL);
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

// FDE #11048 | PC: 0x3c9e64..0x3c9e90 (44 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x3c9e64: D503233F  paciasp  
//   0x3c9e68: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x3c9e6c: F9000BF3  str      x19, [sp, #0x10]
//   0x3c9e70: 910003FD  mov      x29, sp
//   0x3c9e74: AA0003F3  mov      x19, x0
//   0x3c9e78: 97FFFFF4  bl       #0x3c9e48
uint64_t fde_func_11048_0x3c9e64(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x003C9E64ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF3ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x97FFFFF4ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA1303E0ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400BF3ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #11057 | PC: 0x3cb038..0x3cb0fc (196 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x3cb038: D503233F  paciasp  
//   0x3cb03c: D10203FF  sub      sp, sp, #0x80
//   0x3cb040: A9037BFD  stp      x29, x30, [sp, #0x30]
//   0x3cb044: F90023F9  str      x25, [sp, #0x40]
//   0x3cb048: A9055FF8  stp      x24, x23, [sp, #0x50]
//   0x3cb04c: A90657F6  stp      x22, x21, [sp, #0x60]
uint64_t fde_func_11057_0x3cb038(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x003CB038ULL);
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

// FDE #11067 | PC: 0x3cbc60..0x3cbcec (140 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x3cbc60: D503233F  paciasp  
//   0x3cbc64: D100C3FF  sub      sp, sp, #0x30
//   0x3cbc68: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x3cbc6c: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x3cbc70: 910043FD  add      x29, sp, #0x10
//   0x3cbc74: AA0003F4  mov      x20, x0
uint64_t fde_func_11067_0x3cbc60(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x003CBC60ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD100C3FFULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9024FF4ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F4ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0103E0ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0103F3ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #11076 | PC: 0x3cc02c..0x3cc120 (244 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x3cc02c: D503233F  paciasp  
//   0x3cc030: D10143FF  sub      sp, sp, #0x50
//   0x3cc034: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x3cc038: F9001BF5  str      x21, [sp, #0x30]
//   0x3cc03c: A9044FF4  stp      x20, x19, [sp, #0x40]
//   0x3cc040: 910083FD  add      x29, sp, #0x20
uint64_t fde_func_11076_0x3cc02c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x003CC02CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10143FFULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9027BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9001BF5ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9044FF4ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910083FDULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F4ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400028ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #11086 | PC: 0x3ccf14..0x3ccfac (152 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x3ccf14: D503233F  paciasp  
//   0x3ccf18: D10143FF  sub      sp, sp, #0x50
//   0x3ccf1c: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x3ccf20: A90357F6  stp      x22, x21, [sp, #0x30]
//   0x3ccf24: A9044FF4  stp      x20, x19, [sp, #0x40]
//   0x3ccf28: 910083FD  add      x29, sp, #0x20
uint64_t fde_func_11086_0x3ccf14(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x003CCF14ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10143FFULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9027BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90357F6ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9044FF4ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910083FDULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x39410008ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x340003A8ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #11095 | PC: 0x3ce2b8..0x3ce2e4 (44 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x3ce2b8: D503245F  bti      c
//   0x3ce2bc: 37000061  tbnz     w1, #0, #0x3ce2c8
//   0x3ce2c0: B941FC08  ldr      w8, [x0, #0x1fc]
//   0x3ce2c4: 14000002  b        #0x3ce2cc
//   0x3ce2c8: B941F808  ldr      w8, [x0, #0x1f8]
//   0x3ce2cc: 6B01011F  cmp      w8, w1
uint64_t fde_func_11095_0x3ce2b8(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x003CE2B8ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x37000061ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB941FC08ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x14000002ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB941F808ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x6B01011FULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x54000062ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x2A1F03E0ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #11105 | PC: 0x3ce91c..0x3ce934 (24 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x3ce91c: D503245F  bti      c
//   0x3ce920: 3954E008  ldrb     w8, [x0, #0x538]
//   0x3ce924: 34000068  cbz      w8, #0x3ce930
//   0x3ce928: 3914E01F  strb     wzr, [x0, #0x538]
//   0x3ce92c: 17FFE9FD  b        #0x3c9120
//   0x3ce930: D65F03C0  ret      
uint64_t fde_func_11105_0x3ce91c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x003CE91CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x3954E008ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x34000068ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x3914E01FULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x17FFE9FDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD65F03C0ULL ^ (5ULL << 32);
    return state ^ (state >> 29);
}

// FDE #11114 | PC: 0x3ceb64..0x3ceb78 (20 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x3ceb64: D503245F  bti      c
//   0x3ceb68: F940EC00  ldr      x0, [x0, #0x1d8]
//   0x3ceb6c: F9400008  ldr      x8, [x0]
//   0x3ceb70: F9405D10  ldr      x16, [x8, #0xb8]
//   0x3ceb74: D61F0200  br       x16
uint64_t fde_func_11114_0x3ceb64(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x003CEB64ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF940EC00ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400008ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9405D10ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD61F0200ULL ^ (4ULL << 32);
    return state ^ (state >> 29);
}

// FDE #11124 | PC: 0x3cec20..0x3cec2c (12 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x3cec20: D503245F  bti      c
//   0x3cec24: D100C000  sub      x0, x0, #0x30
//   0x3cec28: 17FFFF43  b        #0x3ce934
uint64_t fde_func_11124_0x3cec20(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x003CEC20ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD100C000ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x17FFFF43ULL ^ (2ULL << 32);
    return state ^ (state >> 29);
}

// FDE #11133 | PC: 0x3ced3c..0x3ced48 (12 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x3ced3c: D503245F  bti      c
//   0x3ced40: AA1F03E1  mov      x1, xzr
//   0x3ced44: 14000014  b        #0x3ced94
uint64_t fde_func_11133_0x3ced3c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x003CED3CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA1F03E1ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x14000014ULL ^ (2ULL << 32);
    return state ^ (state >> 29);
}

// FDE #11143 | PC: 0x3cf360..0x3cf3f0 (144 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x3cf360: D503233F  paciasp  
//   0x3cf364: D10103FF  sub      sp, sp, #0x40
//   0x3cf368: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x3cf36c: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x3cf370: 910083FD  add      x29, sp, #0x20
//   0x3cf374: 91002013  add      x19, x0, #8
uint64_t fde_func_11143_0x3cf360(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x003CF360ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10103FFULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9027BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9034FF4ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910083FDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91002013ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F4ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA1303E0ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #11152 | PC: 0x3cfb78..0x3cfc78 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x3cfb78: D503233F  paciasp  
//   0x3cfb7c: A9BC7BFD  stp      x29, x30, [sp, #-0x40]!
//   0x3cfb80: F9000BF7  str      x23, [sp, #0x10]
//   0x3cfb84: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x3cfb88: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x3cfb8c: 910003FD  mov      x29, sp
uint64_t fde_func_11152_0x3cfb78(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x003CFB78ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BC7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF7ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90257F6ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9034FF4ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91000435ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xEB55FBFFULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #11162 | PC: 0x3d0704..0x3d0804 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x3d0704: D503233F  paciasp  
//   0x3d0708: D101C3FF  sub      sp, sp, #0x70
//   0x3d070c: A9037BFD  stp      x29, x30, [sp, #0x30]
//   0x3d0710: F90023F7  str      x23, [sp, #0x40]
//   0x3d0714: A90557F6  stp      x22, x21, [sp, #0x50]
//   0x3d0718: A9064FF4  stp      x20, x19, [sp, #0x60]
uint64_t fde_func_11162_0x3d0704(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x003D0704ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD101C3FFULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9037BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF90023F7ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90557F6ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9064FF4ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9100C3FDULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0803F3ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #11171 | PC: 0x3d172c..0x3d1780 (84 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x3d172c: D503233F  paciasp  
//   0x3d1730: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x3d1734: F9000BF3  str      x19, [sp, #0x10]
//   0x3d1738: 910003FD  mov      x29, sp
//   0x3d173c: AA0003F3  mov      x19, x0
//   0x3d1740: 910B0000  add      x0, x0, #0x2c0
uint64_t fde_func_11171_0x3d172c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x003D172CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF3ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910B0000ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x97FFF5A6ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910B2268ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #11181 | PC: 0x3d1f58..0x3d1f7c (36 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x3d1f58: D503233F  paciasp  
//   0x3d1f5c: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x3d1f60: 910003FD  mov      x29, sp
//   0x3d1f64: 97FFFFCE  bl       #0x3d1e9c
//   0x3d1f68: 2A2003E8  mvn      w8, w0
//   0x3d1f6c: 12000100  and      w0, w8, #1
uint64_t fde_func_11181_0x3d1f58(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x003D1F58ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BF7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x97FFFFCEULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x2A2003E8ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x12000100ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA8C17BFDULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD50323BFULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #11190 | PC: 0x3d2254..0x3d2354 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x3d2254: D503233F  paciasp  
//   0x3d2258: D10203FF  sub      sp, sp, #0x80
//   0x3d225c: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x3d2260: F9001BFB  str      x27, [sp, #0x30]
//   0x3d2264: A90467FA  stp      x26, x25, [sp, #0x40]
//   0x3d2268: A9055FF8  stp      x24, x23, [sp, #0x50]
uint64_t fde_func_11190_0x3d2254(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x003D2254ULL);
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

// FDE #11200 | PC: 0x3d2ab0..0x3d2b18 (104 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x3d2ab0: D503233F  paciasp  
//   0x3d2ab4: D10103FF  sub      sp, sp, #0x40
//   0x3d2ab8: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x3d2abc: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x3d2ac0: 910083FD  add      x29, sp, #0x20
//   0x3d2ac4: AA0003F3  mov      x19, x0
uint64_t fde_func_11200_0x3d2ab0(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x003D2AB0ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10103FFULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9027BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9034FF4ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910083FDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x7200003FULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF0FFE6A1ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #11209 | PC: 0x3d2e40..0x3d2e4c (12 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x3d2e40: D503245F  bti      c
//   0x3d2e44: D1008000  sub      x0, x0, #0x20
//   0x3d2e48: 17FFFEAB  b        #0x3d28f4
uint64_t fde_func_11209_0x3d2e40(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x003D2E40ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD1008000ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x17FFFEABULL ^ (2ULL << 32);
    return state ^ (state >> 29);
}

// FDE #11219 | PC: 0x3d3010..0x3d3078 (104 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x3d3010: D503233F  paciasp  
//   0x3d3014: A9BD7BFD  stp      x29, x30, [sp, #-0x30]!
//   0x3d3018: F9000BF5  str      x21, [sp, #0x10]
//   0x3d301c: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x3d3020: 910003FD  mov      x29, sp
//   0x3d3024: F9400014  ldr      x20, [x0]
uint64_t fde_func_11219_0x3d3010(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x003D3010ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BD7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF5ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9024FF4ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400014ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB40001F4ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #11228 | PC: 0x3d3404..0x3d3450 (76 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x3d3404: D503245F  bti      c
//   0x3d3408: B4000220  cbz      x0, #0x3d344c
//   0x3d340c: D503233F  paciasp  
//   0x3d3410: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x3d3414: F9000BF3  str      x19, [sp, #0x10]
//   0x3d3418: 910003FD  mov      x29, sp
uint64_t fde_func_11228_0x3d3404(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x003D3404ULL);
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

// FDE #11238 | PC: 0x3d46d4..0x3d476c (152 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x3d46d4: D503233F  paciasp  
//   0x3d46d8: A9BC7BFD  stp      x29, x30, [sp, #-0x40]!
//   0x3d46dc: F9000BF7  str      x23, [sp, #0x10]
//   0x3d46e0: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x3d46e4: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x3d46e8: 910003FD  mov      x29, sp
uint64_t fde_func_11238_0x3d46d4(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x003D46D4ULL);
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

// FDE #11247 | PC: 0x3d4de0..0x3d4ee0 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x3d4de0: D503233F  paciasp  
//   0x3d4de4: D10203FF  sub      sp, sp, #0x80
//   0x3d4de8: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x3d4dec: F9001BFB  str      x27, [sp, #0x30]
//   0x3d4df0: A90467FA  stp      x26, x25, [sp, #0x40]
//   0x3d4df4: A9055FF8  stp      x24, x23, [sp, #0x50]
uint64_t fde_func_11247_0x3d4de0(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x003D4DE0ULL);
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

// FDE #11257 | PC: 0x3d5ca8..0x3d5cfc (84 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x3d5ca8: D503233F  paciasp  
//   0x3d5cac: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x3d5cb0: F9000BF3  str      x19, [sp, #0x10]
//   0x3d5cb4: 910003FD  mov      x29, sp
//   0x3d5cb8: 91032000  add      x0, x0, #0xc8
//   0x3d5cbc: AA0103F3  mov      x19, x1
uint64_t fde_func_11257_0x3d5ca8(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x003D5CA8ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF3ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91032000ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0103F3ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x97F815A7ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF940F400ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #11266 | PC: 0x3d66d0..0x3d6774 (164 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x3d66d0: D503233F  paciasp  
//   0x3d66d4: A9BD7BFD  stp      x29, x30, [sp, #-0x30]!
//   0x3d66d8: F9000BF5  str      x21, [sp, #0x10]
//   0x3d66dc: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x3d66e0: 910003FD  mov      x29, sp
//   0x3d66e4: B9402808  ldr      w8, [x0, #0x28]
uint64_t fde_func_11266_0x3d66d0(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x003D66D0ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BD7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF5ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9024FF4ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB9402808ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB9001FA2ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x7100091FULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #11276 | PC: 0x3d6ecc..0x3d6f58 (140 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x3d6ecc: D503233F  paciasp  
//   0x3d6ed0: A9BD7BFD  stp      x29, x30, [sp, #-0x30]!
//   0x3d6ed4: F9000BF5  str      x21, [sp, #0x10]
//   0x3d6ed8: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x3d6edc: 910003FD  mov      x29, sp
//   0x3d6ee0: AA0203F3  mov      x19, x2
uint64_t fde_func_11276_0x3d6ecc(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x003D6ECCULL);
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

// FDE #11285 | PC: 0x3d7838..0x3d78c0 (136 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x3d7838: D503233F  paciasp  
//   0x3d783c: D10183FF  sub      sp, sp, #0x60
//   0x3d7840: A9037BFD  stp      x29, x30, [sp, #0x30]
//   0x3d7844: F90023F5  str      x21, [sp, #0x40]
//   0x3d7848: A9054FF4  stp      x20, x19, [sp, #0x50]
//   0x3d784c: 9100C3FD  add      x29, sp, #0x30
uint64_t fde_func_11285_0x3d7838(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x003D7838ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10183FFULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9037BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF90023F5ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9054FF4ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9100C3FDULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003E8ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400009ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #11295 | PC: 0x3d7ba4..0x3d7c14 (112 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x3d7ba4: D503233F  paciasp  
//   0x3d7ba8: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x3d7bac: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x3d7bb0: 910003FD  mov      x29, sp
//   0x3d7bb4: AA0103F4  mov      x20, x1
//   0x3d7bb8: AA0003F3  mov      x19, x0
uint64_t fde_func_11295_0x3d7ba4(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x003D7BA4ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9014FF4ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0103F4ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x97F8986FULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x7900627FULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #11305 | PC: 0x3d7f40..0x3d7f7c (60 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x3d7f40: D503233F  paciasp  
//   0x3d7f44: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x3d7f48: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x3d7f4c: 910003FD  mov      x29, sp
//   0x3d7f50: AA0003F3  mov      x19, x0
//   0x3d7f54: 52800114  mov      w20, #8
uint64_t fde_func_11305_0x3d7f40(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x003D7F40ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9014FF4ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x52800114ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x8B140260ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x97FF5A03ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #11314 | PC: 0x3d843c..0x3d84a4 (104 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x3d843c: D503233F  paciasp  
//   0x3d8440: A9BD7BFD  stp      x29, x30, [sp, #-0x30]!
//   0x3d8444: F9000BF5  str      x21, [sp, #0x10]
//   0x3d8448: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x3d844c: 910003FD  mov      x29, sp
//   0x3d8450: AA0103F3  mov      x19, x1
uint64_t fde_func_11314_0x3d843c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x003D843CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BD7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF5ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9024FF4ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0103F3ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91006014ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9401015ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #11324 | PC: 0x3d8854..0x3d8954 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x3d8854: D503233F  paciasp  
//   0x3d8858: A9BD7BFD  stp      x29, x30, [sp, #-0x30]!
//   0x3d885c: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x3d8860: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x3d8864: 910003FD  mov      x29, sp
//   0x3d8868: AA0103F4  mov      x20, x1
uint64_t fde_func_11324_0x3d8854(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x003D8854ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BD7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90157F6ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9024FF4ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0103F4ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400028ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #11333 | PC: 0x3d8c60..0x3d8c7c (28 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x3d8c60: D503245F  bti      c
//   0x3d8c64: AA0003E8  mov      x8, x0
//   0x3d8c68: F9400400  ldr      x0, [x0, #8]
//   0x3d8c6c: D0000E49  adrp     x9, #0x5a2000
//   0x3d8c70: 91150129  add      x9, x9, #0x540
//   0x3d8c74: F9000109  str      x9, [x8]
uint64_t fde_func_11333_0x3d8c60(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x003D8C60ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003E8ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400400ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD0000E49ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91150129ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000109ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x17FFFFDEULL ^ (6ULL << 32);
    return state ^ (state >> 29);
}

// FDE #11343 | PC: 0x3d924c..0x3d9278 (44 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x3d924c: D503233F  paciasp  
//   0x3d9250: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x3d9254: F9000BF3  str      x19, [sp, #0x10]
//   0x3d9258: 910003FD  mov      x29, sp
//   0x3d925c: AA0003F3  mov      x19, x0
//   0x3d9260: 97FFFFEA  bl       #0x3d9208
uint64_t fde_func_11343_0x3d924c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x003D924CULL);
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

// FDE #11352 | PC: 0x3d95b4..0x3d95fc (72 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x3d95b4: D503233F  paciasp  
//   0x3d95b8: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x3d95bc: F9000BF3  str      x19, [sp, #0x10]
//   0x3d95c0: 910003FD  mov      x29, sp
//   0x3d95c4: F9400013  ldr      x19, [x0]
//   0x3d95c8: F9000001  str      x1, [x0]
uint64_t fde_func_11352_0x3d95b4(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x003D95B4ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF3ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400013ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000001ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB4000113ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91002260ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #11362 | PC: 0x3d98f0..0x3d9900 (16 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x3d98f0: D503245F  bti      c
//   0x3d98f4: AA0103E0  mov      x0, x1
//   0x3d98f8: 12800DA1  mov      w1, #-0x6e
//   0x3d98fc: 14000001  b        #0x3d9900
uint64_t fde_func_11362_0x3d98f0(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x003D98F0ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0103E0ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x12800DA1ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x14000001ULL ^ (3ULL << 32);
    return state ^ (state >> 29);
}

// FDE #11371 | PC: 0x3dba2c..0x3dba74 (72 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x3dba2c: D503233F  paciasp  
//   0x3dba30: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x3dba34: F9000BF3  str      x19, [sp, #0x10]
//   0x3dba38: 910003FD  mov      x29, sp
//   0x3dba3c: F9400013  ldr      x19, [x0]
//   0x3dba40: F900001F  str      xzr, [x0]
uint64_t fde_func_11371_0x3dba2c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x003DBA2CULL);
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

// FDE #11381 | PC: 0x3dc474..0x3dc574 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x3dc474: D503233F  paciasp  
//   0x3dc478: A9BB7BFD  stp      x29, x30, [sp, #-0x50]!
//   0x3dc47c: F9000BFC  str      x28, [sp, #0x10]
//   0x3dc480: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x3dc484: A90357F6  stp      x22, x21, [sp, #0x30]
//   0x3dc488: A9044FF4  stp      x20, x19, [sp, #0x40]
uint64_t fde_func_11381_0x3dc474(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x003DC474ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BB7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BFCULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9025FF8ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90357F6ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9044FF4ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD12803FFULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #11390 | PC: 0x3dd140..0x3dd204 (196 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x3dd140: D503233F  paciasp  
//   0x3dd144: D10143FF  sub      sp, sp, #0x50
//   0x3dd148: A9037BFD  stp      x29, x30, [sp, #0x30]
//   0x3dd14c: A9044FF4  stp      x20, x19, [sp, #0x40]
//   0x3dd150: 9100C3FD  add      x29, sp, #0x30
//   0x3dd154: 395E2028  ldrb     w8, [x1, #0x788]
uint64_t fde_func_11390_0x3dd140(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x003DD140ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10143FFULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9037BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9044FF4ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9100C3FDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x395E2028ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x340002A8ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #11400 | PC: 0x3df17c..0x3df184 (8 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x3df17c: D503245F  bti      c
//   0x3df180: 17FFE9E0  b        #0x3d9900
uint64_t fde_func_11400_0x3df17c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x003DF17CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503245FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x17FFE9E0ULL ^ (1ULL << 32);
    return state ^ (state >> 29);
}

// FDE #11409 | PC: 0x3dfad0..0x3dfb44 (116 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x3dfad0: D503233F  paciasp  
//   0x3dfad4: A9BD7BFD  stp      x29, x30, [sp, #-0x30]!
//   0x3dfad8: F9000BF5  str      x21, [sp, #0x10]
//   0x3dfadc: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x3dfae0: 910003FD  mov      x29, sp
//   0x3dfae4: AA0003F5  mov      x21, x0
uint64_t fde_func_11409_0x3dfad0(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x003DFAD0ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD503233FULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BD7BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF5ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9024FF4ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F5ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0103E0ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0103F3ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

uint64_t execute_fde_shard_3(uint32_t fde_idx, uint64_t a0, uint64_t a1) {
    switch (fde_idx) {
        case 7612: return fde_func_07612_0x31d8e8(a0, a1);
        case 7622: return fde_func_07622_0x31dce4(a0, a1);
        case 7631: return fde_func_07631_0x31e170(a0, a1);
        case 7641: return fde_func_07641_0x31eac4(a0, a1);
        case 7650: return fde_func_07650_0x31ed94(a0, a1);
        case 7660: return fde_func_07660_0x31f558(a0, a1);
        case 7669: return fde_func_07669_0x320090(a0, a1);
        case 7679: return fde_func_07679_0x320504(a0, a1);
        case 7688: return fde_func_07688_0x320a8c(a0, a1);
        case 7698: return fde_func_07698_0x32154c(a0, a1);
        case 7707: return fde_func_07707_0x321a5c(a0, a1);
        case 7717: return fde_func_07717_0x3220b8(a0, a1);
        case 7726: return fde_func_07726_0x322918(a0, a1);
        case 7736: return fde_func_07736_0x322c24(a0, a1);
        case 7746: return fde_func_07746_0x3230ac(a0, a1);
        case 7755: return fde_func_07755_0x323794(a0, a1);
        case 7765: return fde_func_07765_0x323fbc(a0, a1);
        case 7774: return fde_func_07774_0x3248ac(a0, a1);
        case 7784: return fde_func_07784_0x324ec4(a0, a1);
        case 7793: return fde_func_07793_0x3262a0(a0, a1);
        case 7803: return fde_func_07803_0x326ac4(a0, a1);
        case 7812: return fde_func_07812_0x328ae8(a0, a1);
        case 7822: return fde_func_07822_0x3293b4(a0, a1);
        case 7831: return fde_func_07831_0x329680(a0, a1);
        case 7841: return fde_func_07841_0x329d44(a0, a1);
        case 7850: return fde_func_07850_0x32a19c(a0, a1);
        case 7860: return fde_func_07860_0x32a768(a0, a1);
        case 7869: return fde_func_07869_0x32ac60(a0, a1);
        case 7879: return fde_func_07879_0x32b2f0(a0, a1);
        case 7888: return fde_func_07888_0x32b728(a0, a1);
        case 7898: return fde_func_07898_0x32bd94(a0, a1);
        case 7907: return fde_func_07907_0x32c688(a0, a1);
        case 7917: return fde_func_07917_0x32cc90(a0, a1);
        case 7926: return fde_func_07926_0x32d33c(a0, a1);
        case 7936: return fde_func_07936_0x32d65c(a0, a1);
        case 7945: return fde_func_07945_0x32e12c(a0, a1);
        case 7955: return fde_func_07955_0x32e874(a0, a1);
        case 7964: return fde_func_07964_0x32f398(a0, a1);
        case 7974: return fde_func_07974_0x32fb0c(a0, a1);
        case 7983: return fde_func_07983_0x3307f4(a0, a1);
        case 7993: return fde_func_07993_0x33157c(a0, a1);
        case 8002: return fde_func_08002_0x331d90(a0, a1);
        case 8012: return fde_func_08012_0x3323c4(a0, a1);
        case 8021: return fde_func_08021_0x332ccc(a0, a1);
        case 8031: return fde_func_08031_0x3338d4(a0, a1);
        case 8041: return fde_func_08041_0x3345ec(a0, a1);
        case 8050: return fde_func_08050_0x334c80(a0, a1);
        case 8060: return fde_func_08060_0x3356c8(a0, a1);
        case 8069: return fde_func_08069_0x33594c(a0, a1);
        case 8079: return fde_func_08079_0x336040(a0, a1);
        case 8088: return fde_func_08088_0x336668(a0, a1);
        case 8098: return fde_func_08098_0x336924(a0, a1);
        case 8107: return fde_func_08107_0x336cfc(a0, a1);
        case 8117: return fde_func_08117_0x337368(a0, a1);
        case 8126: return fde_func_08126_0x3379c4(a0, a1);
        case 8136: return fde_func_08136_0x337f14(a0, a1);
        case 8145: return fde_func_08145_0x3383a4(a0, a1);
        case 8155: return fde_func_08155_0x3388ec(a0, a1);
        case 8164: return fde_func_08164_0x339a90(a0, a1);
        case 8174: return fde_func_08174_0x339f38(a0, a1);
        case 8183: return fde_func_08183_0x33a3b8(a0, a1);
        case 8193: return fde_func_08193_0x33b538(a0, a1);
        case 8202: return fde_func_08202_0x33ba64(a0, a1);
        case 8212: return fde_func_08212_0x33c2c4(a0, a1);
        case 8221: return fde_func_08221_0x33c454(a0, a1);
        case 8231: return fde_func_08231_0x33c678(a0, a1);
        case 8240: return fde_func_08240_0x33ca00(a0, a1);
        case 8250: return fde_func_08250_0x33ce10(a0, a1);
        case 8259: return fde_func_08259_0x33d770(a0, a1);
        case 8269: return fde_func_08269_0x33e2c4(a0, a1);
        case 8278: return fde_func_08278_0x33ee5c(a0, a1);
        case 8288: return fde_func_08288_0x33f680(a0, a1);
        case 8297: return fde_func_08297_0x33ff30(a0, a1);
        case 8307: return fde_func_08307_0x340660(a0, a1);
        case 8316: return fde_func_08316_0x340d40(a0, a1);
        case 8326: return fde_func_08326_0x34586c(a0, a1);
        case 8336: return fde_func_08336_0x345e18(a0, a1);
        case 8345: return fde_func_08345_0x346134(a0, a1);
        case 8355: return fde_func_08355_0x346b20(a0, a1);
        case 8364: return fde_func_08364_0x347be4(a0, a1);
        case 8374: return fde_func_08374_0x3485a0(a0, a1);
        case 8383: return fde_func_08383_0x348ed8(a0, a1);
        case 8393: return fde_func_08393_0x3493ac(a0, a1);
        case 8402: return fde_func_08402_0x349550(a0, a1);
        case 8412: return fde_func_08412_0x349934(a0, a1);
        case 8421: return fde_func_08421_0x349bbc(a0, a1);
        case 8431: return fde_func_08431_0x34a63c(a0, a1);
        case 8440: return fde_func_08440_0x34abb4(a0, a1);
        case 8450: return fde_func_08450_0x34b408(a0, a1);
        case 8459: return fde_func_08459_0x34b8b4(a0, a1);
        case 8469: return fde_func_08469_0x34bcf8(a0, a1);
        case 8478: return fde_func_08478_0x34c060(a0, a1);
        case 8488: return fde_func_08488_0x34ddcc(a0, a1);
        case 8497: return fde_func_08497_0x34eea4(a0, a1);
        case 8507: return fde_func_08507_0x34fc3c(a0, a1);
        case 8516: return fde_func_08516_0x350068(a0, a1);
        case 8526: return fde_func_08526_0x350c6c(a0, a1);
        case 8535: return fde_func_08535_0x350f64(a0, a1);
        case 8545: return fde_func_08545_0x35112c(a0, a1);
        case 8554: return fde_func_08554_0x3515d0(a0, a1);
        case 8564: return fde_func_08564_0x3517e4(a0, a1);
        case 8573: return fde_func_08573_0x35188c(a0, a1);
        case 8583: return fde_func_08583_0x351910(a0, a1);
        case 8592: return fde_func_08592_0x351fa4(a0, a1);
        case 8602: return fde_func_08602_0x352818(a0, a1);
        case 8611: return fde_func_08611_0x3529fc(a0, a1);
        case 8621: return fde_func_08621_0x352b98(a0, a1);
        case 8631: return fde_func_08631_0x3530a0(a0, a1);
        case 8640: return fde_func_08640_0x3531b4(a0, a1);
        case 8650: return fde_func_08650_0x3547fc(a0, a1);
        case 8659: return fde_func_08659_0x354c1c(a0, a1);
        case 8669: return fde_func_08669_0x355090(a0, a1);
        case 8678: return fde_func_08678_0x355748(a0, a1);
        case 8688: return fde_func_08688_0x355e18(a0, a1);
        case 8697: return fde_func_08697_0x356874(a0, a1);
        case 8707: return fde_func_08707_0x356ea0(a0, a1);
        case 8716: return fde_func_08716_0x357780(a0, a1);
        case 8726: return fde_func_08726_0x3584c4(a0, a1);
        case 8735: return fde_func_08735_0x35936c(a0, a1);
        case 8745: return fde_func_08745_0x3596d4(a0, a1);
        case 8754: return fde_func_08754_0x359c7c(a0, a1);
        case 8764: return fde_func_08764_0x35ab70(a0, a1);
        case 8773: return fde_func_08773_0x35ae90(a0, a1);
        case 8783: return fde_func_08783_0x35ca38(a0, a1);
        case 8792: return fde_func_08792_0x35cd2c(a0, a1);
        case 8802: return fde_func_08802_0x35d268(a0, a1);
        case 8811: return fde_func_08811_0x35d604(a0, a1);
        case 8821: return fde_func_08821_0x35e3dc(a0, a1);
        case 8830: return fde_func_08830_0x35e958(a0, a1);
        case 8840: return fde_func_08840_0x35f8d0(a0, a1);
        case 8849: return fde_func_08849_0x35ff20(a0, a1);
        case 8859: return fde_func_08859_0x361cb0(a0, a1);
        case 8868: return fde_func_08868_0x362270(a0, a1);
        case 8878: return fde_func_08878_0x366480(a0, a1);
        case 8887: return fde_func_08887_0x3666f0(a0, a1);
        case 8897: return fde_func_08897_0x36706c(a0, a1);
        case 8906: return fde_func_08906_0x3673e0(a0, a1);
        case 8916: return fde_func_08916_0x3682e0(a0, a1);
        case 8926: return fde_func_08926_0x368e28(a0, a1);
        case 8935: return fde_func_08935_0x368fb4(a0, a1);
        case 8945: return fde_func_08945_0x369284(a0, a1);
        case 8954: return fde_func_08954_0x369498(a0, a1);
        case 8964: return fde_func_08964_0x369c7c(a0, a1);
        case 8973: return fde_func_08973_0x36b564(a0, a1);
        case 8983: return fde_func_08983_0x36ce00(a0, a1);
        case 8992: return fde_func_08992_0x36d51c(a0, a1);
        case 9002: return fde_func_09002_0x36d980(a0, a1);
        case 9011: return fde_func_09011_0x36e2d8(a0, a1);
        case 9021: return fde_func_09021_0x36ec34(a0, a1);
        case 9030: return fde_func_09030_0x36f708(a0, a1);
        case 9040: return fde_func_09040_0x3700f0(a0, a1);
        case 9049: return fde_func_09049_0x370740(a0, a1);
        case 9059: return fde_func_09059_0x370f58(a0, a1);
        case 9068: return fde_func_09068_0x3712d4(a0, a1);
        case 9078: return fde_func_09078_0x371ce4(a0, a1);
        case 9087: return fde_func_09087_0x372188(a0, a1);
        case 9097: return fde_func_09097_0x3725c4(a0, a1);
        case 9106: return fde_func_09106_0x372b04(a0, a1);
        case 9116: return fde_func_09116_0x373d00(a0, a1);
        case 9125: return fde_func_09125_0x374298(a0, a1);
        case 9135: return fde_func_09135_0x374674(a0, a1);
        case 9144: return fde_func_09144_0x374aa0(a0, a1);
        case 9154: return fde_func_09154_0x375124(a0, a1);
        case 9163: return fde_func_09163_0x375a44(a0, a1);
        case 9173: return fde_func_09173_0x37665c(a0, a1);
        case 9182: return fde_func_09182_0x376fe4(a0, a1);
        case 9192: return fde_func_09192_0x377d7c(a0, a1);
        case 9201: return fde_func_09201_0x378074(a0, a1);
        case 9211: return fde_func_09211_0x378538(a0, a1);
        case 9221: return fde_func_09221_0x3792dc(a0, a1);
        case 9230: return fde_func_09230_0x379a7c(a0, a1);
        case 9240: return fde_func_09240_0x37a788(a0, a1);
        case 9249: return fde_func_09249_0x37ac3c(a0, a1);
        case 9259: return fde_func_09259_0x37b168(a0, a1);
        case 9268: return fde_func_09268_0x37c2ac(a0, a1);
        case 9278: return fde_func_09278_0x37ccf4(a0, a1);
        case 9287: return fde_func_09287_0x37d02c(a0, a1);
        case 9297: return fde_func_09297_0x37d260(a0, a1);
        case 9306: return fde_func_09306_0x37d8bc(a0, a1);
        case 9316: return fde_func_09316_0x37e03c(a0, a1);
        case 9325: return fde_func_09325_0x37e660(a0, a1);
        case 9335: return fde_func_09335_0x37f824(a0, a1);
        case 9344: return fde_func_09344_0x37f9f0(a0, a1);
        case 9354: return fde_func_09354_0x380910(a0, a1);
        case 9363: return fde_func_09363_0x381338(a0, a1);
        case 9373: return fde_func_09373_0x381ba8(a0, a1);
        case 9382: return fde_func_09382_0x381e00(a0, a1);
        case 9392: return fde_func_09392_0x3821d4(a0, a1);
        case 9401: return fde_func_09401_0x3824d4(a0, a1);
        case 9411: return fde_func_09411_0x382f1c(a0, a1);
        case 9420: return fde_func_09420_0x383544(a0, a1);
        case 9430: return fde_func_09430_0x3839b8(a0, a1);
        case 9439: return fde_func_09439_0x3843e8(a0, a1);
        case 9449: return fde_func_09449_0x384e14(a0, a1);
        case 9458: return fde_func_09458_0x385104(a0, a1);
        case 9468: return fde_func_09468_0x3852a0(a0, a1);
        case 9477: return fde_func_09477_0x385d20(a0, a1);
        case 9487: return fde_func_09487_0x38605c(a0, a1);
        case 9496: return fde_func_09496_0x386524(a0, a1);
        case 9506: return fde_func_09506_0x386800(a0, a1);
        case 9516: return fde_func_09516_0x386fd8(a0, a1);
        case 9525: return fde_func_09525_0x3875e8(a0, a1);
        case 9535: return fde_func_09535_0x388160(a0, a1);
        case 9544: return fde_func_09544_0x388a70(a0, a1);
        case 9554: return fde_func_09554_0x389104(a0, a1);
        case 9563: return fde_func_09563_0x38a498(a0, a1);
        case 9573: return fde_func_09573_0x38b728(a0, a1);
        case 9582: return fde_func_09582_0x38be88(a0, a1);
        case 9592: return fde_func_09592_0x38cad4(a0, a1);
        case 9601: return fde_func_09601_0x38d1ec(a0, a1);
        case 9611: return fde_func_09611_0x38d690(a0, a1);
        case 9620: return fde_func_09620_0x38d6fc(a0, a1);
        case 9630: return fde_func_09630_0x38d774(a0, a1);
        case 9639: return fde_func_09639_0x38d7f8(a0, a1);
        case 9649: return fde_func_09649_0x38d904(a0, a1);
        case 9658: return fde_func_09658_0x38dc00(a0, a1);
        case 9668: return fde_func_09668_0x38e7bc(a0, a1);
        case 9677: return fde_func_09677_0x38edb8(a0, a1);
        case 9687: return fde_func_09687_0x38f5b8(a0, a1);
        case 9696: return fde_func_09696_0x38f938(a0, a1);
        case 9706: return fde_func_09706_0x390204(a0, a1);
        case 9715: return fde_func_09715_0x390760(a0, a1);
        case 9725: return fde_func_09725_0x390ccc(a0, a1);
        case 9734: return fde_func_09734_0x39118c(a0, a1);
        case 9744: return fde_func_09744_0x391684(a0, a1);
        case 9753: return fde_func_09753_0x391b54(a0, a1);
        case 9763: return fde_func_09763_0x391fd8(a0, a1);
        case 9772: return fde_func_09772_0x3926d4(a0, a1);
        case 9782: return fde_func_09782_0x392df0(a0, a1);
        case 9791: return fde_func_09791_0x393354(a0, a1);
        case 9801: return fde_func_09801_0x393b88(a0, a1);
        case 9810: return fde_func_09810_0x393dfc(a0, a1);
        case 9820: return fde_func_09820_0x394108(a0, a1);
        case 9830: return fde_func_09830_0x3943ac(a0, a1);
        case 9839: return fde_func_09839_0x39442c(a0, a1);
        case 9849: return fde_func_09849_0x39457c(a0, a1);
        case 9858: return fde_func_09858_0x3945e8(a0, a1);
        case 9868: return fde_func_09868_0x394770(a0, a1);
        case 9877: return fde_func_09877_0x3947dc(a0, a1);
        case 9887: return fde_func_09887_0x394cb4(a0, a1);
        case 9896: return fde_func_09896_0x395530(a0, a1);
        case 9906: return fde_func_09906_0x3966d4(a0, a1);
        case 9915: return fde_func_09915_0x3970c0(a0, a1);
        case 9925: return fde_func_09925_0x39741c(a0, a1);
        case 9934: return fde_func_09934_0x3978dc(a0, a1);
        case 9944: return fde_func_09944_0x397da4(a0, a1);
        case 9953: return fde_func_09953_0x398308(a0, a1);
        case 9963: return fde_func_09963_0x398a48(a0, a1);
        case 9972: return fde_func_09972_0x398ff0(a0, a1);
        case 9982: return fde_func_09982_0x399294(a0, a1);
        case 9991: return fde_func_09991_0x39971c(a0, a1);
        case 10001: return fde_func_10001_0x399c1c(a0, a1);
        case 10010: return fde_func_10010_0x39a6a8(a0, a1);
        case 10020: return fde_func_10020_0x39ace0(a0, a1);
        case 10029: return fde_func_10029_0x39b06c(a0, a1);
        case 10039: return fde_func_10039_0x39bdbc(a0, a1);
        case 10048: return fde_func_10048_0x39c32c(a0, a1);
        case 10058: return fde_func_10058_0x39c570(a0, a1);
        case 10067: return fde_func_10067_0x39cafc(a0, a1);
        case 10077: return fde_func_10077_0x39d164(a0, a1);
        case 10086: return fde_func_10086_0x39fcd4(a0, a1);
        case 10096: return fde_func_10096_0x3a0678(a0, a1);
        case 10105: return fde_func_10105_0x3a0a38(a0, a1);
        case 10115: return fde_func_10115_0x3a18e8(a0, a1);
        case 10125: return fde_func_10125_0x3a2e4c(a0, a1);
        case 10134: return fde_func_10134_0x3a3b94(a0, a1);
        case 10144: return fde_func_10144_0x3a4184(a0, a1);
        case 10153: return fde_func_10153_0x3a41f0(a0, a1);
        case 10163: return fde_func_10163_0x3a4268(a0, a1);
        case 10172: return fde_func_10172_0x3a4674(a0, a1);
        case 10182: return fde_func_10182_0x3a4ab4(a0, a1);
        case 10191: return fde_func_10191_0x3a5298(a0, a1);
        case 10201: return fde_func_10201_0x3a58d8(a0, a1);
        case 10210: return fde_func_10210_0x3a5d68(a0, a1);
        case 10220: return fde_func_10220_0x3a64cc(a0, a1);
        case 10229: return fde_func_10229_0x3a7540(a0, a1);
        case 10239: return fde_func_10239_0x3a7ec8(a0, a1);
        case 10248: return fde_func_10248_0x3a8134(a0, a1);
        case 10258: return fde_func_10258_0x3a8c3c(a0, a1);
        case 10267: return fde_func_10267_0x3a9010(a0, a1);
        case 10277: return fde_func_10277_0x3a9888(a0, a1);
        case 10286: return fde_func_10286_0x3a9ae4(a0, a1);
        case 10296: return fde_func_10296_0x3aa5d8(a0, a1);
        case 10305: return fde_func_10305_0x3aa758(a0, a1);
        case 10315: return fde_func_10315_0x3aa9a8(a0, a1);
        case 10324: return fde_func_10324_0x3aac24(a0, a1);
        case 10334: return fde_func_10334_0x3aacfc(a0, a1);
        case 10343: return fde_func_10343_0x3ab4ac(a0, a1);
        case 10353: return fde_func_10353_0x3abad4(a0, a1);
        case 10362: return fde_func_10362_0x3abd94(a0, a1);
        case 10372: return fde_func_10372_0x3ac654(a0, a1);
        case 10381: return fde_func_10381_0x3ad070(a0, a1);
        case 10391: return fde_func_10391_0x3ae71c(a0, a1);
        case 10400: return fde_func_10400_0x3aec18(a0, a1);
        case 10410: return fde_func_10410_0x3afc7c(a0, a1);
        case 10420: return fde_func_10420_0x3afe64(a0, a1);
        case 10429: return fde_func_10429_0x3b02a8(a0, a1);
        case 10439: return fde_func_10439_0x3b0524(a0, a1);
        case 10448: return fde_func_10448_0x3b1620(a0, a1);
        case 10458: return fde_func_10458_0x3b1a94(a0, a1);
        case 10467: return fde_func_10467_0x3b1c18(a0, a1);
        case 10477: return fde_func_10477_0x3b1d38(a0, a1);
        case 10486: return fde_func_10486_0x3b2190(a0, a1);
        case 10496: return fde_func_10496_0x3b2730(a0, a1);
        case 10505: return fde_func_10505_0x3b2a84(a0, a1);
        case 10515: return fde_func_10515_0x3b30a0(a0, a1);
        case 10524: return fde_func_10524_0x3b3b74(a0, a1);
        case 10534: return fde_func_10534_0x3b42e8(a0, a1);
        case 10543: return fde_func_10543_0x3b5214(a0, a1);
        case 10553: return fde_func_10553_0x3b5bb0(a0, a1);
        case 10562: return fde_func_10562_0x3b5ea0(a0, a1);
        case 10572: return fde_func_10572_0x3b6074(a0, a1);
        case 10581: return fde_func_10581_0x3b71a0(a0, a1);
        case 10591: return fde_func_10591_0x3b77f8(a0, a1);
        case 10600: return fde_func_10600_0x3b7e94(a0, a1);
        case 10610: return fde_func_10610_0x3b8b70(a0, a1);
        case 10619: return fde_func_10619_0x3b95b0(a0, a1);
        case 10629: return fde_func_10629_0x3ba090(a0, a1);
        case 10638: return fde_func_10638_0x3ba4b4(a0, a1);
        case 10648: return fde_func_10648_0x3bacb4(a0, a1);
        case 10657: return fde_func_10657_0x3bb2d8(a0, a1);
        case 10667: return fde_func_10667_0x3bc708(a0, a1);
        case 10676: return fde_func_10676_0x3bcb24(a0, a1);
        case 10686: return fde_func_10686_0x3bd570(a0, a1);
        case 10695: return fde_func_10695_0x3bd660(a0, a1);
        case 10705: return fde_func_10705_0x3bdca0(a0, a1);
        case 10715: return fde_func_10715_0x3bdf9c(a0, a1);
        case 10724: return fde_func_10724_0x3be434(a0, a1);
        case 10734: return fde_func_10734_0x3be71c(a0, a1);
        case 10743: return fde_func_10743_0x3bebe8(a0, a1);
        case 10753: return fde_func_10753_0x3bf618(a0, a1);
        case 10762: return fde_func_10762_0x3bfb74(a0, a1);
        case 10772: return fde_func_10772_0x3c0244(a0, a1);
        case 10781: return fde_func_10781_0x3c07ac(a0, a1);
        case 10791: return fde_func_10791_0x3c0c2c(a0, a1);
        case 10800: return fde_func_10800_0x3c0f7c(a0, a1);
        case 10810: return fde_func_10810_0x3c151c(a0, a1);
        case 10819: return fde_func_10819_0x3c1698(a0, a1);
        case 10829: return fde_func_10829_0x3c1b28(a0, a1);
        case 10838: return fde_func_10838_0x3c1c9c(a0, a1);
        case 10848: return fde_func_10848_0x3c1f90(a0, a1);
        case 10857: return fde_func_10857_0x3c2314(a0, a1);
        case 10867: return fde_func_10867_0x3c2924(a0, a1);
        case 10876: return fde_func_10876_0x3c2f80(a0, a1);
        case 10886: return fde_func_10886_0x3c3404(a0, a1);
        case 10895: return fde_func_10895_0x3c36d0(a0, a1);
        case 10905: return fde_func_10905_0x3c3a5c(a0, a1);
        case 10914: return fde_func_10914_0x3c413c(a0, a1);
        case 10924: return fde_func_10924_0x3c4a84(a0, a1);
        case 10933: return fde_func_10933_0x3c4ca4(a0, a1);
        case 10943: return fde_func_10943_0x3c4d88(a0, a1);
        case 10952: return fde_func_10952_0x3c4e50(a0, a1);
        case 10962: return fde_func_10962_0x3c4f78(a0, a1);
        case 10971: return fde_func_10971_0x3c55d4(a0, a1);
        case 10981: return fde_func_10981_0x3c631c(a0, a1);
        case 10990: return fde_func_10990_0x3c664c(a0, a1);
        case 11000: return fde_func_11000_0x3c6a80(a0, a1);
        case 11010: return fde_func_11010_0x3c6ca0(a0, a1);
        case 11019: return fde_func_11019_0x3c747c(a0, a1);
        case 11029: return fde_func_11029_0x3c8aec(a0, a1);
        case 11038: return fde_func_11038_0x3c94d8(a0, a1);
        case 11048: return fde_func_11048_0x3c9e64(a0, a1);
        case 11057: return fde_func_11057_0x3cb038(a0, a1);
        case 11067: return fde_func_11067_0x3cbc60(a0, a1);
        case 11076: return fde_func_11076_0x3cc02c(a0, a1);
        case 11086: return fde_func_11086_0x3ccf14(a0, a1);
        case 11095: return fde_func_11095_0x3ce2b8(a0, a1);
        case 11105: return fde_func_11105_0x3ce91c(a0, a1);
        case 11114: return fde_func_11114_0x3ceb64(a0, a1);
        case 11124: return fde_func_11124_0x3cec20(a0, a1);
        case 11133: return fde_func_11133_0x3ced3c(a0, a1);
        case 11143: return fde_func_11143_0x3cf360(a0, a1);
        case 11152: return fde_func_11152_0x3cfb78(a0, a1);
        case 11162: return fde_func_11162_0x3d0704(a0, a1);
        case 11171: return fde_func_11171_0x3d172c(a0, a1);
        case 11181: return fde_func_11181_0x3d1f58(a0, a1);
        case 11190: return fde_func_11190_0x3d2254(a0, a1);
        case 11200: return fde_func_11200_0x3d2ab0(a0, a1);
        case 11209: return fde_func_11209_0x3d2e40(a0, a1);
        case 11219: return fde_func_11219_0x3d3010(a0, a1);
        case 11228: return fde_func_11228_0x3d3404(a0, a1);
        case 11238: return fde_func_11238_0x3d46d4(a0, a1);
        case 11247: return fde_func_11247_0x3d4de0(a0, a1);
        case 11257: return fde_func_11257_0x3d5ca8(a0, a1);
        case 11266: return fde_func_11266_0x3d66d0(a0, a1);
        case 11276: return fde_func_11276_0x3d6ecc(a0, a1);
        case 11285: return fde_func_11285_0x3d7838(a0, a1);
        case 11295: return fde_func_11295_0x3d7ba4(a0, a1);
        case 11305: return fde_func_11305_0x3d7f40(a0, a1);
        case 11314: return fde_func_11314_0x3d843c(a0, a1);
        case 11324: return fde_func_11324_0x3d8854(a0, a1);
        case 11333: return fde_func_11333_0x3d8c60(a0, a1);
        case 11343: return fde_func_11343_0x3d924c(a0, a1);
        case 11352: return fde_func_11352_0x3d95b4(a0, a1);
        case 11362: return fde_func_11362_0x3d98f0(a0, a1);
        case 11371: return fde_func_11371_0x3dba2c(a0, a1);
        case 11381: return fde_func_11381_0x3dc474(a0, a1);
        case 11390: return fde_func_11390_0x3dd140(a0, a1);
        case 11400: return fde_func_11400_0x3df17c(a0, a1);
        case 11409: return fde_func_11409_0x3dfad0(a0, a1);
        default: return 0ULL;
    }
}

} // namespace sscronet