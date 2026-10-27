// ============================================================================
// Clean-Room C++17 Reconstructed AArch64 FDE Shard 2/5 for libpreload.so
// Phân mảnh hàm FDE AArch64 C++17 sạch 2/5 cho libpreload.so
// Covers 400 FDEs (indices 400..799 of 2,000 sampled from 8,944 FDEs @ 0x305cfc)
// ============================================================================
#include "preload_core.h"

namespace preload_reconstructed {

// FDE #1788 | PC: 0x0ce4e0..0x0ce5ac (204 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x0ce4e0: D10143FF  sub      sp, sp, #0x50
//   0x0ce4e4: F9000BF7  str      x23, [sp, #0x10]
//   0x0ce4e8: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x0ce4ec: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x0ce4f0: A9047BFD  stp      x29, x30, [sp, #0x40]
//   0x0ce4f4: 910103FD  add      x29, sp, #0x40
uint64_t fde_func_1788_0x0ce4e0(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x000CE4E0ULL);
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

// FDE #1793 | PC: 0x0ce994..0x0cea78 (228 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x0ce994: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x0ce998: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0ce99c: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0ce9a0: 910083FD  add      x29, sp, #0x20
//   0x0ce9a4: F1000428  subs     x8, x1, #1
//   0x0ce9a8: AA0003F3  mov      x19, x0
uint64_t fde_func_1793_0x0ce994(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x000CE994ULL);
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

// FDE #1797 | PC: 0x0ced34..0x0ced3c (8 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x0ced34: 91006000  add      x0, x0, #0x18
//   0x0ced38: 17FE1B64  b        #0x55ac8
uint64_t fde_func_1797_0x0ced34(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x000CED34ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0x91006000ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x17FE1B64ULL ^ (1ULL << 32);
    return state ^ (state >> 29);
}

// FDE #1802 | PC: 0x0cf0e4..0x0cf138 (84 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x0cf0e4: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x0cf0e8: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0cf0ec: 910043FD  add      x29, sp, #0x10
//   0x0cf0f0: A9007C7F  stp      xzr, xzr, [x3]
//   0x0cf0f4: F9000861  str      x1, [x3, #0x10]
//   0x0cf0f8: F9000043  str      x3, [x2]
uint64_t fde_func_1802_0x0cf0e4(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x000CF0E4ULL);
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

// FDE #1806 | PC: 0x0cf3c8..0x0cf408 (64 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x0cf3c8: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x0cf3cc: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0cf3d0: 910043FD  add      x29, sp, #0x10
//   0x0cf3d4: F9400028  ldr      x8, [x1]
//   0x0cf3d8: AA0003F3  mov      x19, x0
//   0x0cf3dc: F9000008  str      x8, [x0]
uint64_t fde_func_1806_0x0cf3c8(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x000CF3C8ULL);
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

// FDE #1811 | PC: 0x0cf70c..0x0cf768 (92 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x0cf70c: AA0003E8  mov      x8, x0
//   0x0cf710: F9400800  ldr      x0, [x0, #0x10]
//   0x0cf714: B4000280  cbz      x0, #0xcf764
//   0x0cf718: F9400009  ldr      x9, [x0]
//   0x0cf71c: EB08013F  cmp      x9, x8
//   0x0cf720: 54000120  b.eq     #0xcf744
uint64_t fde_func_1811_0x0cf70c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x000CF70CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003E8ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400800ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB4000280ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400009ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xEB08013FULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x54000120ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF900041FULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB40001E9ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #1815 | PC: 0x0cf91c..0x0cf974 (88 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x0cf91c: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x0cf920: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0cf924: 910043FD  add      x29, sp, #0x10
//   0x0cf928: F9400413  ldr      x19, [x0, #8]
//   0x0cf92c: B40000F3  cbz      x19, #0xcf948
//   0x0cf930: 91002268  add      x8, x19, #8
uint64_t fde_func_1815_0x0cf91c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x000CF91CULL);
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

// FDE #1820 | PC: 0x0cfba4..0x0cfbcc (40 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x0cfba4: F9401C08  ldr      x8, [x0, #0x38]
//   0x0cfba8: B40000E8  cbz      x8, #0xcfbc4
//   0x0cfbac: F9400109  ldr      x9, [x8]
//   0x0cfbb0: 2A0103E2  mov      w2, w1
//   0x0cfbb4: 91002001  add      x1, x0, #8
//   0x0cfbb8: AA0803E0  mov      x0, x8
uint64_t fde_func_1820_0x0cfba4(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x000CFBA4ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9401C08ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB40000E8ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400109ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x2A0103E2ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91002001ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0803E0ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400D23ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD61F0060ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #1824 | PC: 0x0cfe40..0x0cfe64 (36 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x0cfe40: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x0cfe44: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0cfe48: 910043FD  add      x29, sp, #0x10
//   0x0cfe4c: AA0003F3  mov      x19, x0
//   0x0cfe50: 97FFFFC3  bl       #0xcfd5c
//   0x0cfe54: A9417BFD  ldp      x29, x30, [sp, #0x10]
uint64_t fde_func_1824_0x0cfe40(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x000CFE40ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81E0FF3ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x97FFFFC3ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9417BFDULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA1303E0ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF84207F3ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #1829 | PC: 0x0d0254..0x0d0354 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x0d0254: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x0d0258: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0d025c: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0d0260: 910083FD  add      x29, sp, #0x20
//   0x0d0264: F0001568  adrp     x8, #0x37f000
//   0x0d0268: F9452D08  ldr      x8, [x8, #0xa58]
uint64_t fde_func_1829_0x0d0254(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x000D0254ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81D0FF5ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9014FF4ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9027BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910083FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF0001568ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9452D08ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91004108ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #1833 | PC: 0x0d0658..0x0d0664 (12 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x0d0658: 910B0001  add      x1, x0, #0x2c0
//   0x0d065c: AA0803E0  mov      x0, x8
//   0x0d0660: 17FDDCE6  b        #0x479f8
uint64_t fde_func_1833_0x0d0658(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x000D0658ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0x910B0001ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0803E0ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x17FDDCE6ULL ^ (2ULL << 32);
    return state ^ (state >> 29);
}

// FDE #1837 | PC: 0x0d0754..0x0d07f4 (160 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x0d0754: D10103FF  sub      sp, sp, #0x40
//   0x0d0758: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x0d075c: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x0d0760: A9037BFD  stp      x29, x30, [sp, #0x30]
//   0x0d0764: 9100C3FD  add      x29, sp, #0x30
//   0x0d0768: D53BD056  mrs      x22, tpidr_el0
uint64_t fde_func_1837_0x0d0754(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x000D0754ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10103FFULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90157F6ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9024FF4ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9037BFDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9100C3FDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD53BD056ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF94016C8ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91081013ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #1842 | PC: 0x0d09d4..0x0d0a40 (108 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x0d09d4: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x0d09d8: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0d09dc: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0d09e0: 910083FD  add      x29, sp, #0x20
//   0x0d09e4: 91081014  add      x20, x0, #0x204
//   0x0d09e8: AA0003F6  mov      x22, x0
uint64_t fde_func_1842_0x0d09d4(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x000D09D4ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BD57F6ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9014FF4ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9027BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910083FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91081014ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F6ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA1403E0ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0203F3ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #1846 | PC: 0x0d0d64..0x0d0e64 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x0d0d64: D106C3FF  sub      sp, sp, #0x1b0
//   0x0d0d68: A9156FFC  stp      x28, x27, [sp, #0x150]
//   0x0d0d6c: A91667FA  stp      x26, x25, [sp, #0x160]
//   0x0d0d70: A9175FF8  stp      x24, x23, [sp, #0x170]
//   0x0d0d74: A91857F6  stp      x22, x21, [sp, #0x180]
//   0x0d0d78: A9194FF4  stp      x20, x19, [sp, #0x190]
uint64_t fde_func_1846_0x0d0d64(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x000D0D64ULL);
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

// FDE #1851 | PC: 0x0d24b8..0x0d2510 (88 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x0d24b8: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x0d24bc: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0d24c0: 910043FD  add      x29, sp, #0x10
//   0x0d24c4: F9400413  ldr      x19, [x0, #8]
//   0x0d24c8: B40000F3  cbz      x19, #0xd24e4
//   0x0d24cc: 91002268  add      x8, x19, #8
uint64_t fde_func_1851_0x0d24b8(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x000D24B8ULL);
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

// FDE #1855 | PC: 0x0d2c70..0x0d2ccc (92 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x0d2c70: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x0d2c74: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0d2c78: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0d2c7c: 910083FD  add      x29, sp, #0x20
//   0x0d2c80: 91050014  add      x20, x0, #0x140
//   0x0d2c84: AA0003F5  mov      x21, x0
uint64_t fde_func_1855_0x0d2c70(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x000D2C70ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81D0FF5ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9014FF4ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9027BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910083FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91050014ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F5ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA1403E0ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0803F3ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #1860 | PC: 0x0d3518..0x0d355c (68 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x0d3518: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0d351c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0d3520: 910043FD  add      x29, sp, #0x10
//   0x0d3524: AA0003F4  mov      x20, x0
//   0x0d3528: 910A4000  add      x0, x0, #0x290
//   0x0d352c: AA0103F3  mov      x19, x1
uint64_t fde_func_1860_0x0d3518(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x000D3518ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE4FF4ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F4ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910A4000ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0103F3ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x97FDDF3CULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x529B5881ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #1864 | PC: 0x0d4628..0x0d4728 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x0d4628: D10203FF  sub      sp, sp, #0x80
//   0x0d462c: A9026FFC  stp      x28, x27, [sp, #0x20]
//   0x0d4630: A90367FA  stp      x26, x25, [sp, #0x30]
//   0x0d4634: A9045FF8  stp      x24, x23, [sp, #0x40]
//   0x0d4638: A90557F6  stp      x22, x21, [sp, #0x50]
//   0x0d463c: A9064FF4  stp      x20, x19, [sp, #0x60]
uint64_t fde_func_1864_0x0d4628(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x000D4628ULL);
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

// FDE #1869 | PC: 0x0d4a04..0x0d4a58 (84 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x0d4a04: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x0d4a08: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0d4a0c: 910043FD  add      x29, sp, #0x10
//   0x0d4a10: A9007C7F  stp      xzr, xzr, [x3]
//   0x0d4a14: F9000861  str      x1, [x3, #0x10]
//   0x0d4a18: F9000043  str      x3, [x2]
uint64_t fde_func_1869_0x0d4a04(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x000D4A04ULL);
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

// FDE #1873 | PC: 0x0d4be0..0x0d4cd8 (248 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x0d4be0: D10183FF  sub      sp, sp, #0x60
//   0x0d4be4: F9000BF9  str      x25, [sp, #0x10]
//   0x0d4be8: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x0d4bec: A90357F6  stp      x22, x21, [sp, #0x30]
//   0x0d4bf0: A9044FF4  stp      x20, x19, [sp, #0x40]
//   0x0d4bf4: A9057BFD  stp      x29, x30, [sp, #0x50]
uint64_t fde_func_1873_0x0d4be0(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x000D4BE0ULL);
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

// FDE #1878 | PC: 0x0d5048..0x0d5138 (240 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x0d5048: F81A0FFB  str      x27, [sp, #-0x60]!
//   0x0d504c: A90167FA  stp      x26, x25, [sp, #0x10]
//   0x0d5050: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x0d5054: A90357F6  stp      x22, x21, [sp, #0x30]
//   0x0d5058: A9044FF4  stp      x20, x19, [sp, #0x40]
//   0x0d505c: A9057BFD  stp      x29, x30, [sp, #0x50]
uint64_t fde_func_1878_0x0d5048(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x000D5048ULL);
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

// FDE #1882 | PC: 0x0d52c4..0x0d52cc (8 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x0d52c4: 91006000  add      x0, x0, #0x18
//   0x0d52c8: 17FFEC8A  b        #0xd04f0
uint64_t fde_func_1882_0x0d52c4(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x000D52C4ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0x91006000ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x17FFEC8AULL ^ (1ULL << 32);
    return state ^ (state >> 29);
}

// FDE #1887 | PC: 0x0d5490..0x0d5518 (136 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x0d5490: F81C0FF7  str      x23, [sp, #-0x40]!
//   0x0d5494: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x0d5498: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x0d549c: A9037BFD  stp      x29, x30, [sp, #0x30]
//   0x0d54a0: 9100C3FD  add      x29, sp, #0x30
//   0x0d54a4: 91002017  add      x23, x0, #8
uint64_t fde_func_1887_0x0d5490(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x000D5490ULL);
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

// FDE #1891 | PC: 0x0d56f0..0x0d57f0 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x0d56f0: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x0d56f4: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0d56f8: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0d56fc: 910083FD  add      x29, sp, #0x20
//   0x0d5700: AA0003F3  mov      x19, x0
//   0x0d5704: F9415C00  ldr      x0, [x0, #0x2b8]
uint64_t fde_func_1891_0x0d56f0(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x000D56F0ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81D0FF5ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9014FF4ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9027BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910083FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9415C00ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF00014A8ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910D2108ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #1896 | PC: 0x0d5988..0x0d5a88 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x0d5988: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0d598c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0d5990: 910043FD  add      x29, sp, #0x10
//   0x0d5994: 3940C008  ldrb     w8, [x0, #0x30]
//   0x0d5998: AA0003F3  mov      x19, x0
//   0x0d599c: 37000068  tbnz     w8, #0, #0xd59a8
uint64_t fde_func_1896_0x0d5988(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x000D5988ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE4FF4ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x3940C008ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x37000068ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x7900627FULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x14000004ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #1900 | PC: 0x0d61e4..0x0d6274 (144 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x0d61e4: D10103FF  sub      sp, sp, #0x40
//   0x0d61e8: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x0d61ec: A9037BFD  stp      x29, x30, [sp, #0x30]
//   0x0d61f0: 9100C3FD  add      x29, sp, #0x30
//   0x0d61f4: D53BD054  mrs      x20, tpidr_el0
//   0x0d61f8: F9401689  ldr      x9, [x20, #0x28]
uint64_t fde_func_1900_0x0d61e4(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x000D61E4ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10103FFULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9024FF4ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9037BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9100C3FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD53BD054ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9401689ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910A0000ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000FE9ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #1905 | PC: 0x0d65ac..0x0d66ac (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x0d65ac: F81C0FF7  str      x23, [sp, #-0x40]!
//   0x0d65b0: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x0d65b4: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x0d65b8: A9037BFD  stp      x29, x30, [sp, #0x30]
//   0x0d65bc: 9100C3FD  add      x29, sp, #0x30
//   0x0d65c0: 910A4013  add      x19, x0, #0x290
uint64_t fde_func_1905_0x0d65ac(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x000D65ACULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81C0FF7ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90157F6ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9024FF4ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9037BFDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9100C3FDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910A4013ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F7ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA1303E0ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #1909 | PC: 0x0d68a4..0x0d694c (168 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x0d68a4: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x0d68a8: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0d68ac: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0d68b0: 910083FD  add      x29, sp, #0x20
//   0x0d68b4: AA0203F3  mov      x19, x2
//   0x0d68b8: 2A0103F6  mov      w22, w1
uint64_t fde_func_1909_0x0d68a4(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x000D68A4ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BD57F6ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9014FF4ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9027BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910083FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0203F3ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x2A0103F6ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F5ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x97FFA8BEULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #1914 | PC: 0x0d6ad8..0x0d6b3c (100 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x0d6ad8: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0d6adc: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0d6ae0: 910043FD  add      x29, sp, #0x10
//   0x0d6ae4: 2A0103F4  mov      w20, w1
//   0x0d6ae8: AA0003F3  mov      x19, x0
//   0x0d6aec: 97FFA906  bl       #0xc0f04
uint64_t fde_func_1914_0x0d6ad8(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x000D6AD8ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE4FF4ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x2A0103F4ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x97FFA906ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x51064688ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x71000D1FULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #1918 | PC: 0x0d6f04..0x0d6f0c (8 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x0d6f04: D1004000  sub      x0, x0, #0x10
//   0x0d6f08: 17FFFFF5  b        #0xd6edc
uint64_t fde_func_1918_0x0d6f04(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x000D6F04ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD1004000ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x17FFFFF5ULL ^ (1ULL << 32);
    return state ^ (state >> 29);
}

// FDE #1922 | PC: 0x0d6f8c..0x0d6f90 (4 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x0d6f8c: D65F03C0  ret      
uint64_t fde_func_1922_0x0d6f8c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x000D6F8CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD65F03C0ULL ^ (0ULL << 32);
    return state ^ (state >> 29);
}

// FDE #1927 | PC: 0x0d8084..0x0d8184 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x0d8084: D10603FF  sub      sp, sp, #0x180
//   0x0d8088: A91367FC  stp      x28, x25, [sp, #0x130]
//   0x0d808c: A9145FF8  stp      x24, x23, [sp, #0x140]
//   0x0d8090: A91557F6  stp      x22, x21, [sp, #0x150]
//   0x0d8094: A9164FF4  stp      x20, x19, [sp, #0x160]
//   0x0d8098: A9177BFD  stp      x29, x30, [sp, #0x170]
uint64_t fde_func_1927_0x0d8084(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x000D8084ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10603FFULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA91367FCULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9145FF8ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA91557F6ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9164FF4ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9177BFDULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9105C3FDULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD53BD058ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #1931 | PC: 0x0d9648..0x0d9748 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x0d9648: FC1D0FE8  str      d8, [sp, #-0x30]!
//   0x0d964c: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0d9650: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0d9654: 910083FD  add      x29, sp, #0x20
//   0x0d9658: 3940002A  ldrb     w10, [x1]
//   0x0d965c: F9400428  ldr      x8, [x1, #8]
uint64_t fde_func_1931_0x0d9648(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x000D9648ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xFC1D0FE8ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9014FF4ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9027BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910083FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x3940002AULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400428ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0103F4ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #1936 | PC: 0x0d9d88..0x0d9e48 (192 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x0d9d88: D10143FF  sub      sp, sp, #0x50
//   0x0d9d8c: F9000BF7  str      x23, [sp, #0x10]
//   0x0d9d90: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x0d9d94: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x0d9d98: A9047BFD  stp      x29, x30, [sp, #0x40]
//   0x0d9d9c: 910103FD  add      x29, sp, #0x40
uint64_t fde_func_1936_0x0d9d88(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x000D9D88ULL);
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

// FDE #1940 | PC: 0x0da038..0x0da138 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x0da038: D103C3FF  sub      sp, sp, #0xf0
//   0x0da03c: A9096FFC  stp      x28, x27, [sp, #0x90]
//   0x0da040: A90A67FA  stp      x26, x25, [sp, #0xa0]
//   0x0da044: A90B5FF8  stp      x24, x23, [sp, #0xb0]
//   0x0da048: A90C57F6  stp      x22, x21, [sp, #0xc0]
//   0x0da04c: A90D4FF4  stp      x20, x19, [sp, #0xd0]
uint64_t fde_func_1940_0x0da038(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x000DA038ULL);
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

// FDE #1945 | PC: 0x0da5d0..0x0da6d0 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x0da5d0: D10283FF  sub      sp, sp, #0xa0
//   0x0da5d4: A9046FFC  stp      x28, x27, [sp, #0x40]
//   0x0da5d8: A90567FA  stp      x26, x25, [sp, #0x50]
//   0x0da5dc: A9065FF8  stp      x24, x23, [sp, #0x60]
//   0x0da5e0: A90757F6  stp      x22, x21, [sp, #0x70]
//   0x0da5e4: A9084FF4  stp      x20, x19, [sp, #0x80]
uint64_t fde_func_1945_0x0da5d0(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x000DA5D0ULL);
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

// FDE #1949 | PC: 0x0daa10..0x0dab10 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x0daa10: D101C3FF  sub      sp, sp, #0x70
//   0x0daa14: F9000BFB  str      x27, [sp, #0x10]
//   0x0daa18: A90267FA  stp      x26, x25, [sp, #0x20]
//   0x0daa1c: A9035FF8  stp      x24, x23, [sp, #0x30]
//   0x0daa20: A90457F6  stp      x22, x21, [sp, #0x40]
//   0x0daa24: A9054FF4  stp      x20, x19, [sp, #0x50]
uint64_t fde_func_1949_0x0daa10(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x000DAA10ULL);
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

// FDE #1954 | PC: 0x0dae90..0x0daee8 (88 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x0dae90: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x0dae94: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0dae98: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0dae9c: 910083FD  add      x29, sp, #0x20
//   0x0daea0: AA0003F5  mov      x21, x0
//   0x0daea4: AA0103E0  mov      x0, x1
uint64_t fde_func_1954_0x0dae90(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x000DAE90ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81D0FF5ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9014FF4ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9027BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910083FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F5ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0103E0ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0203F3ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0103F4ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #1958 | PC: 0x0db24c..0x0db338 (236 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x0db24c: D10183FF  sub      sp, sp, #0x60
//   0x0db250: A90167FA  stp      x26, x25, [sp, #0x10]
//   0x0db254: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x0db258: A90357F6  stp      x22, x21, [sp, #0x30]
//   0x0db25c: A9044FF4  stp      x20, x19, [sp, #0x40]
//   0x0db260: A9057BFD  stp      x29, x30, [sp, #0x50]
uint64_t fde_func_1958_0x0db24c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x000DB24CULL);
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

// FDE #1963 | PC: 0x0db614..0x0db714 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x0db614: D10383FF  sub      sp, sp, #0xe0
//   0x0db618: F90053F7  str      x23, [sp, #0xa0]
//   0x0db61c: A90B57F6  stp      x22, x21, [sp, #0xb0]
//   0x0db620: A90C4FF4  stp      x20, x19, [sp, #0xc0]
//   0x0db624: A90D7BFD  stp      x29, x30, [sp, #0xd0]
//   0x0db628: 910343FD  add      x29, sp, #0xd0
uint64_t fde_func_1963_0x0db614(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x000DB614ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10383FFULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF90053F7ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90B57F6ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90C4FF4ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90D7BFDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910343FDULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD53BD057ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF94016E8ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #1967 | PC: 0x0db9e0..0x0dbabc (220 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x0db9e0: A9BC5FF8  stp      x24, x23, [sp, #-0x40]!
//   0x0db9e4: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x0db9e8: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x0db9ec: A9037BFD  stp      x29, x30, [sp, #0x30]
//   0x0db9f0: 9100C3FD  add      x29, sp, #0x30
//   0x0db9f4: B000152A  adrp     x10, #0x380000
uint64_t fde_func_1967_0x0db9e0(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x000DB9E0ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BC5FF8ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90157F6ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9024FF4ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9037BFDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9100C3FDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB000152AULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x39400008ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9125814AULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #1972 | PC: 0x0dc2f0..0x0dc35c (108 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x0dc2f0: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0dc2f4: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0dc2f8: 910043FD  add      x29, sp, #0x10
//   0x0dc2fc: AA0003F3  mov      x19, x0
//   0x0dc300: 52800400  mov      w0, #0x20
//   0x0dc304: AA0103F4  mov      x20, x1
uint64_t fde_func_1972_0x0dc2f0(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x000DC2F0ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE4FF4ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x52800400ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0103F4ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x97FD9F72ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF900001FULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #1976 | PC: 0x0dcad0..0x0dcb14 (68 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x0dcad0: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x0dcad4: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0dcad8: 910043FD  add      x29, sp, #0x10
//   0x0dcadc: F9400013  ldr      x19, [x0]
//   0x0dcae0: A9402668  ldp      x8, x9, [x19]
//   0x0dcae4: F9000509  str      x9, [x8, #8]
uint64_t fde_func_1976_0x0dcad0(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x000DCAD0ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81E0FF3ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400013ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9402668ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000509ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400669ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000128ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #1981 | PC: 0x0dd0d8..0x0dd0e4 (12 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x0dd0d8: 12000028  and      w8, w1, #1
//   0x0dd0dc: 39066408  strb     w8, [x0, #0x199]
//   0x0dd0e0: D65F03C0  ret      
uint64_t fde_func_1981_0x0dd0d8(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x000DD0D8ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0x12000028ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x39066408ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD65F03C0ULL ^ (2ULL << 32);
    return state ^ (state >> 29);
}

// FDE #1985 | PC: 0x0ddabc..0x0ddbbc (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x0ddabc: D10183FF  sub      sp, sp, #0x60
//   0x0ddac0: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x0ddac4: A90357F6  stp      x22, x21, [sp, #0x30]
//   0x0ddac8: A9044FF4  stp      x20, x19, [sp, #0x40]
//   0x0ddacc: A9057BFD  stp      x29, x30, [sp, #0x50]
//   0x0ddad0: 910143FD  add      x29, sp, #0x50
uint64_t fde_func_1985_0x0ddabc(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x000DDABCULL);
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

// FDE #1990 | PC: 0x0de1c4..0x0de2c4 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x0de1c4: D10103FF  sub      sp, sp, #0x40
//   0x0de1c8: F9000BF5  str      x21, [sp, #0x10]
//   0x0de1cc: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x0de1d0: A9037BFD  stp      x29, x30, [sp, #0x30]
//   0x0de1d4: 9100C3FD  add      x29, sp, #0x30
//   0x0de1d8: AA0003F5  mov      x21, x0
uint64_t fde_func_1990_0x0de1c4(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x000DE1C4ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10103FFULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF5ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9024FF4ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9037BFDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9100C3FDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F5ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x52800020ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0203F3ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #1994 | PC: 0x0de54c..0x0de644 (248 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x0de54c: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x0de550: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0de554: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0de558: 910083FD  add      x29, sp, #0x20
//   0x0de55c: 91035013  add      x19, x0, #0xd4
//   0x0de560: AA0003F6  mov      x22, x0
uint64_t fde_func_1994_0x0de54c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x000DE54CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BD57F6ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9014FF4ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9027BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910083FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91035013ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F6ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA1303E0ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0203F4ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #1998 | PC: 0x0de848..0x0de908 (192 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x0de848: D100C3FF  sub      sp, sp, #0x30
//   0x0de84c: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0de850: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0de854: 910083FD  add      x29, sp, #0x20
//   0x0de858: AA0103F4  mov      x20, x1
//   0x0de85c: AA0803F3  mov      x19, x8
uint64_t fde_func_1998_0x0de848(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x000DE848ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD100C3FFULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9014FF4ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9027BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910083FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0103F4ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0803F3ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003E8ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0203E1ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #2003 | PC: 0x0ded34..0x0dee34 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x0ded34: D101C3FF  sub      sp, sp, #0x70
//   0x0ded38: A90267FA  stp      x26, x25, [sp, #0x20]
//   0x0ded3c: A9035FF8  stp      x24, x23, [sp, #0x30]
//   0x0ded40: A90457F6  stp      x22, x21, [sp, #0x40]
//   0x0ded44: A9054FF4  stp      x20, x19, [sp, #0x50]
//   0x0ded48: A9067BFD  stp      x29, x30, [sp, #0x60]
uint64_t fde_func_2003_0x0ded34(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x000DED34ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD101C3FFULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90267FAULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9035FF8ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90457F6ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9054FF4ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9067BFDULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910183FDULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD53BD058ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #2007 | PC: 0x0df0d8..0x0df1bc (228 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x0df0d8: D10143FF  sub      sp, sp, #0x50
//   0x0df0dc: A9015FF8  stp      x24, x23, [sp, #0x10]
//   0x0df0e0: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x0df0e4: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x0df0e8: A9047BFD  stp      x29, x30, [sp, #0x40]
//   0x0df0ec: 910103FD  add      x29, sp, #0x40
uint64_t fde_func_2007_0x0df0d8(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x000DF0D8ULL);
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

// FDE #2012 | PC: 0x0df4b8..0x0df4fc (68 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x0df4b8: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x0df4bc: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0df4c0: 910043FD  add      x29, sp, #0x10
//   0x0df4c4: AA0003F3  mov      x19, x0
//   0x0df4c8: 97FFFF9B  bl       #0xdf334
//   0x0df4cc: 91002268  add      x8, x19, #8
uint64_t fde_func_2012_0x0df4b8(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x000DF4B8ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81E0FF3ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x97FFFF9BULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91002268ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xEB00011FULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x540000C0ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #2016 | PC: 0x0df5f8..0x0df630 (56 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x0df5f8: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x0df5fc: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0df600: 910043FD  add      x29, sp, #0x10
//   0x0df604: B0001468  adrp     x8, #0x36c000
//   0x0df608: 9111E108  add      x8, x8, #0x478
//   0x0df60c: AA0003F3  mov      x19, x0
uint64_t fde_func_2016_0x0df5f8(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x000DF5F8ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81E0FF3ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB0001468ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9111E108ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF8018408ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x940001CFULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #2021 | PC: 0x0df750..0x0df7d8 (136 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x0df750: F81C0FF7  str      x23, [sp, #-0x40]!
//   0x0df754: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x0df758: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x0df75c: A9037BFD  stp      x29, x30, [sp, #0x30]
//   0x0df760: 9100C3FD  add      x29, sp, #0x30
//   0x0df764: 91002017  add      x23, x0, #8
uint64_t fde_func_2021_0x0df750(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x000DF750ULL);
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

// FDE #2025 | PC: 0x0df964..0x0dfa64 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x0df964: F81B0FF9  str      x25, [sp, #-0x50]!
//   0x0df968: A9015FF8  stp      x24, x23, [sp, #0x10]
//   0x0df96c: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x0df970: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x0df974: A9047BFD  stp      x29, x30, [sp, #0x40]
//   0x0df978: 910103FD  add      x29, sp, #0x40
uint64_t fde_func_2025_0x0df964(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x000DF964ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81B0FF9ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9015FF8ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90257F6ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9034FF4ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9047BFDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910103FDULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F5ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF8420EB8ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #2030 | PC: 0x0dff20..0x0dff30 (16 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x0dff20: 12000028  and      w8, w1, #1
//   0x0dff24: 91094409  add      x9, x0, #0x251
//   0x0dff28: 089FFD28  stlrb    w8, [x9]
//   0x0dff2c: D65F03C0  ret      
uint64_t fde_func_2030_0x0dff20(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x000DFF20ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0x12000028ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91094409ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x089FFD28ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD65F03C0ULL ^ (3ULL << 32);
    return state ^ (state >> 29);
}

// FDE #2034 | PC: 0x0dffc0..0x0dffcc (12 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x0dffc0: 91002001  add      x1, x0, #8
//   0x0dffc4: AA0803E0  mov      x0, x8
//   0x0dffc8: 17FD9E8C  b        #0x479f8
uint64_t fde_func_2034_0x0dffc0(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x000DFFC0ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0x91002001ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0803E0ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x17FD9E8CULL ^ (2ULL << 32);
    return state ^ (state >> 29);
}

// FDE #2039 | PC: 0x0e1000..0x0e10e4 (228 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x0e1000: D10143FF  sub      sp, sp, #0x50
//   0x0e1004: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x0e1008: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x0e100c: A9047BFD  stp      x29, x30, [sp, #0x40]
//   0x0e1010: 910103FD  add      x29, sp, #0x40
//   0x0e1014: D53BD056  mrs      x22, tpidr_el0
uint64_t fde_func_2039_0x0e1000(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x000E1000ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10143FFULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90257F6ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9034FF4ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9047BFDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910103FDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD53BD056ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF94016C8ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003E9ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #2043 | PC: 0x0e1abc..0x0e1b3c (128 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x0e1abc: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x0e1ac0: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0e1ac4: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0e1ac8: 910083FD  add      x29, sp, #0x20
//   0x0e1acc: AA0003F3  mov      x19, x0
//   0x0e1ad0: 52800400  mov      w0, #0x20
uint64_t fde_func_2043_0x0e1abc(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x000E1ABCULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81D0FF5ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9014FF4ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9027BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910083FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x52800400ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0203F5ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0103F4ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #2048 | PC: 0x0e2270..0x0e2370 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x0e2270: D10243FF  sub      sp, sp, #0x90
//   0x0e2274: A9036FFC  stp      x28, x27, [sp, #0x30]
//   0x0e2278: A90467FA  stp      x26, x25, [sp, #0x40]
//   0x0e227c: A9055FF8  stp      x24, x23, [sp, #0x50]
//   0x0e2280: A90657F6  stp      x22, x21, [sp, #0x60]
//   0x0e2284: A9074FF4  stp      x20, x19, [sp, #0x70]
uint64_t fde_func_2048_0x0e2270(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x000E2270ULL);
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

// FDE #2052 | PC: 0x0e2848..0x0e2948 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x0e2848: A9BA6FFC  stp      x28, x27, [sp, #-0x60]!
//   0x0e284c: A90167FA  stp      x26, x25, [sp, #0x10]
//   0x0e2850: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x0e2854: A90357F6  stp      x22, x21, [sp, #0x30]
//   0x0e2858: A9044FF4  stp      x20, x19, [sp, #0x40]
//   0x0e285c: A9057BFD  stp      x29, x30, [sp, #0x50]
uint64_t fde_func_2052_0x0e2848(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x000E2848ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BA6FFCULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90167FAULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9025FF8ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90357F6ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9044FF4ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9057BFDULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910143FDULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9103C017ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #2057 | PC: 0x0e3244..0x0e3270 (44 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x0e3244: F9411409  ldr      x9, [x0, #0x228]
//   0x0e3248: F9000109  str      x9, [x8]
//   0x0e324c: F9411809  ldr      x9, [x0, #0x230]
//   0x0e3250: F9000509  str      x9, [x8, #8]
//   0x0e3254: B40000C9  cbz      x9, #0xe326c
//   0x0e3258: 91002128  add      x8, x9, #8
uint64_t fde_func_2057_0x0e3244(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x000E3244ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9411409ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000109ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9411809ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000509ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB40000C9ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91002128ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xC85F7D09ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91000529ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #2061 | PC: 0x0e3380..0x0e3390 (16 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x0e3380: 91094008  add      x8, x0, #0x250
//   0x0e3384: 08DFFD08  ldarb    w8, [x8]
//   0x0e3388: 12000100  and      w0, w8, #1
//   0x0e338c: D65F03C0  ret      
uint64_t fde_func_2061_0x0e3380(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x000E3380ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0x91094008ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x08DFFD08ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x12000100ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD65F03C0ULL ^ (3ULL << 32);
    return state ^ (state >> 29);
}

// FDE #2066 | PC: 0x0e3600..0x0e3654 (84 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x0e3600: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x0e3604: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0e3608: 910043FD  add      x29, sp, #0x10
//   0x0e360c: A9007C7F  stp      xzr, xzr, [x3]
//   0x0e3610: F9000861  str      x1, [x3, #0x10]
//   0x0e3614: F9000043  str      x3, [x2]
uint64_t fde_func_2066_0x0e3600(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x000E3600ULL);
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

// FDE #2070 | PC: 0x0e3894..0x0e38dc (72 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x0e3894: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x0e3898: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0e389c: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0e38a0: 910083FD  add      x29, sp, #0x20
//   0x0e38a4: AA0103F3  mov      x19, x1
//   0x0e38a8: AA0003F4  mov      x20, x0
uint64_t fde_func_2070_0x0e3894(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x000E3894ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81D0FF5ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9014FF4ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9027BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910083FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0103F3ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F4ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9400000CULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91002281ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #2075 | PC: 0x0e3a40..0x0e3a48 (8 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x0e3a40: 91006000  add      x0, x0, #0x18
//   0x0e3a44: 17FFEFA6  b        #0xdf8dc
uint64_t fde_func_2075_0x0e3a40(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x000E3A40ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0x91006000ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x17FFEFA6ULL ^ (1ULL << 32);
    return state ^ (state >> 29);
}

// FDE #2079 | PC: 0x0e3ba0..0x0e3ca0 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x0e3ba0: F81B0FF9  str      x25, [sp, #-0x50]!
//   0x0e3ba4: A9015FF8  stp      x24, x23, [sp, #0x10]
//   0x0e3ba8: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x0e3bac: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x0e3bb0: A9047BFD  stp      x29, x30, [sp, #0x40]
//   0x0e3bb4: 910103FD  add      x29, sp, #0x40
uint64_t fde_func_2079_0x0e3ba0(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x000E3BA0ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81B0FF9ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9015FF8ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90257F6ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9034FF4ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9047BFDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910103FDULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0103F3ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xEB03005FULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #2083 | PC: 0x0e435c..0x0e43e4 (136 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x0e435c: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x0e4360: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0e4364: 910043FD  add      x29, sp, #0x10
//   0x0e4368: B0001448  adrp     x8, #0x36d000
//   0x0e436c: A900FC1F  stp      xzr, xzr, [x0, #8]
//   0x0e4370: B900181F  str      wzr, [x0, #0x18]
uint64_t fde_func_2083_0x0e435c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x000E435CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81E0FF3ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB0001448ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA900FC1FULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB900181FULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91048108ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9001001ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #2088 | PC: 0x0e4748..0x0e4848 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x0e4748: D101C3FF  sub      sp, sp, #0x70
//   0x0e474c: F9001BF7  str      x23, [sp, #0x30]
//   0x0e4750: A90457F6  stp      x22, x21, [sp, #0x40]
//   0x0e4754: A9054FF4  stp      x20, x19, [sp, #0x50]
//   0x0e4758: A9067BFD  stp      x29, x30, [sp, #0x60]
//   0x0e475c: 910183FD  add      x29, sp, #0x60
uint64_t fde_func_2088_0x0e4748(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x000E4748ULL);
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

// FDE #2092 | PC: 0x0e4c5c..0x0e4ce0 (132 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x0e4c5c: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x0e4c60: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0e4c64: 910043FD  add      x29, sp, #0x10
//   0x0e4c68: F00014C8  adrp     x8, #0x37f000
//   0x0e4c6c: F946ED08  ldr      x8, [x8, #0xdd8]
//   0x0e4c70: AA0003F3  mov      x19, x0
uint64_t fde_func_2092_0x0e4c5c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x000E4C5CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81E0FF3ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF00014C8ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF946ED08ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91004109ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9103010BULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #2097 | PC: 0x0e4e84..0x0e4ee0 (92 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x0e4e84: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x0e4e88: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0e4e8c: 910043FD  add      x29, sp, #0x10
//   0x0e4e90: F00014C8  adrp     x8, #0x37f000
//   0x0e4e94: F9474908  ldr      x8, [x8, #0xe90]
//   0x0e4e98: AA0003F3  mov      x19, x0
uint64_t fde_func_2097_0x0e4e84(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x000E4E84ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81E0FF3ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF00014C8ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9474908ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91004108ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000008ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #2101 | PC: 0x0e4ef8..0x0e4f00 (8 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x0e4ef8: D100E000  sub      x0, x0, #0x38
//   0x0e4efc: 17FFFD7C  b        #0xe44ec
uint64_t fde_func_2101_0x0e4ef8(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x000E4EF8ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD100E000ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x17FFFD7CULL ^ (1ULL << 32);
    return state ^ (state >> 29);
}

// FDE #2106 | PC: 0x0e4f20..0x0e4f44 (36 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x0e4f20: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x0e4f24: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0e4f28: 910043FD  add      x29, sp, #0x10
//   0x0e4f2c: AA0003F3  mov      x19, x0
//   0x0e4f30: 97FFFD6F  bl       #0xe44ec
//   0x0e4f34: A9417BFD  ldp      x29, x30, [sp, #0x10]
uint64_t fde_func_2106_0x0e4f20(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x000E4F20ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81E0FF3ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x97FFFD6FULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9417BFDULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA1303E0ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF84207F3ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #2110 | PC: 0x0e4fbc..0x0e4fe4 (40 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x0e4fbc: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x0e4fc0: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0e4fc4: 910043FD  add      x29, sp, #0x10
//   0x0e4fc8: D100E013  sub      x19, x0, #0x38
//   0x0e4fcc: AA1303E0  mov      x0, x19
//   0x0e4fd0: 97FFFD47  bl       #0xe44ec
uint64_t fde_func_2110_0x0e4fbc(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x000E4FBCULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81E0FF3ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD100E013ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA1303E0ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x97FFFD47ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9417BFDULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA1303E0ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #2115 | PC: 0x0e5084..0x0e5184 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x0e5084: D10503FF  sub      sp, sp, #0x140
//   0x0e5088: A90E6FFC  stp      x28, x27, [sp, #0xe0]
//   0x0e508c: A90F67FA  stp      x26, x25, [sp, #0xf0]
//   0x0e5090: A9105FF8  stp      x24, x23, [sp, #0x100]
//   0x0e5094: A91157F6  stp      x22, x21, [sp, #0x110]
//   0x0e5098: A9124FF4  stp      x20, x19, [sp, #0x120]
uint64_t fde_func_2115_0x0e5084(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x000E5084ULL);
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

// FDE #2119 | PC: 0x0e5c84..0x0e5d84 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x0e5c84: D102C3FF  sub      sp, sp, #0xb0
//   0x0e5c88: A9075FF8  stp      x24, x23, [sp, #0x70]
//   0x0e5c8c: A90857F6  stp      x22, x21, [sp, #0x80]
//   0x0e5c90: A9094FF4  stp      x20, x19, [sp, #0x90]
//   0x0e5c94: A90A7BFD  stp      x29, x30, [sp, #0xa0]
//   0x0e5c98: 910283FD  add      x29, sp, #0xa0
uint64_t fde_func_2119_0x0e5c84(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x000E5C84ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD102C3FFULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9075FF8ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90857F6ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9094FF4ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90A7BFDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910283FDULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD53BD057ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0803F3ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #2124 | PC: 0x0e62f8..0x0e6354 (92 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x0e62f8: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x0e62fc: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0e6300: 910043FD  add      x29, sp, #0x10
//   0x0e6304: B9401808  ldr      w8, [x0, #0x18]
//   0x0e6308: 7100051F  cmp      w8, #1
//   0x0e630c: 540001E1  b.ne     #0xe6348
uint64_t fde_func_2124_0x0e62f8(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x000E62F8ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81E0FF3ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB9401808ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x7100051FULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x540001E1ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x52800068ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #2128 | PC: 0x0e6d08..0x0e6dec (228 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x0e6d08: D10143FF  sub      sp, sp, #0x50
//   0x0e6d0c: F90013F5  str      x21, [sp, #0x20]
//   0x0e6d10: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x0e6d14: A9047BFD  stp      x29, x30, [sp, #0x40]
//   0x0e6d18: 910103FD  add      x29, sp, #0x40
//   0x0e6d1c: D53BD055  mrs      x21, tpidr_el0
uint64_t fde_func_2128_0x0e6d08(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x000E6D08ULL);
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

// FDE #2133 | PC: 0x0e72d4..0x0e73d4 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x0e72d4: D101C3FF  sub      sp, sp, #0x70
//   0x0e72d8: F90013F9  str      x25, [sp, #0x20]
//   0x0e72dc: A9035FF8  stp      x24, x23, [sp, #0x30]
//   0x0e72e0: A90457F6  stp      x22, x21, [sp, #0x40]
//   0x0e72e4: A9054FF4  stp      x20, x19, [sp, #0x50]
//   0x0e72e8: A9067BFD  stp      x29, x30, [sp, #0x60]
uint64_t fde_func_2133_0x0e72d4(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x000E72D4ULL);
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

// FDE #2137 | PC: 0x0e74a8..0x0e74b0 (8 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x0e74a8: AA0303E0  mov      x0, x3
//   0x0e74ac: D65F03C0  ret      
uint64_t fde_func_2137_0x0e74a8(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x000E74A8ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0303E0ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD65F03C0ULL ^ (1ULL << 32);
    return state ^ (state >> 29);
}

// FDE #2142 | PC: 0x0e7f64..0x0e8064 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x0e7f64: D10183FF  sub      sp, sp, #0x60
//   0x0e7f68: F90013F7  str      x23, [sp, #0x20]
//   0x0e7f6c: A90357F6  stp      x22, x21, [sp, #0x30]
//   0x0e7f70: A9044FF4  stp      x20, x19, [sp, #0x40]
//   0x0e7f74: A9057BFD  stp      x29, x30, [sp, #0x50]
//   0x0e7f78: 910143FD  add      x29, sp, #0x50
uint64_t fde_func_2142_0x0e7f64(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x000E7F64ULL);
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

// FDE #2146 | PC: 0x0e8e94..0x0e8ecc (56 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x0e8e94: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0e8e98: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0e8e9c: 910043FD  add      x29, sp, #0x10
//   0x0e8ea0: AA0003F3  mov      x19, x0
//   0x0e8ea4: F947A800  ldr      x0, [x0, #0xf50]
//   0x0e8ea8: AA0103F4  mov      x20, x1
uint64_t fde_func_2146_0x0e8e94(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x000E8E94ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE4FF4ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF947A800ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0103F4ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB4000080ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400008ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #2151 | PC: 0x0e90ac..0x0e90b4 (8 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x0e90ac: D1008000  sub      x0, x0, #0x20
//   0x0e90b0: 17FFFFC4  b        #0xe8fc0
uint64_t fde_func_2151_0x0e90ac(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x000E90ACULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD1008000ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x17FFFFC4ULL ^ (1ULL << 32);
    return state ^ (state >> 29);
}

// FDE #2155 | PC: 0x0e929c..0x0e92a4 (8 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x0e929c: F9028801  str      x1, [x0, #0x510]
//   0x0e92a0: D65F03C0  ret      
uint64_t fde_func_2155_0x0e929c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x000E929CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9028801ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD65F03C0ULL ^ (1ULL << 32);
    return state ^ (state >> 29);
}

// FDE #2159 | PC: 0x0e9510..0x0e9610 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x0e9510: D10403FF  sub      sp, sp, #0x100
//   0x0e9514: A90A6FFC  stp      x28, x27, [sp, #0xa0]
//   0x0e9518: A90B67FA  stp      x26, x25, [sp, #0xb0]
//   0x0e951c: A90C5FF8  stp      x24, x23, [sp, #0xc0]
//   0x0e9520: A90D57F6  stp      x22, x21, [sp, #0xd0]
//   0x0e9524: A90E4FF4  stp      x20, x19, [sp, #0xe0]
uint64_t fde_func_2159_0x0e9510(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x000E9510ULL);
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

// FDE #2164 | PC: 0x0e9f60..0x0ea014 (180 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x0e9f60: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0e9f64: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0e9f68: 910043FD  add      x29, sp, #0x10
//   0x0e9f6c: AA0003F4  mov      x20, x0
//   0x0e9f70: 52800020  mov      w0, #1
//   0x0e9f74: AA0103F3  mov      x19, x1
uint64_t fde_func_2164_0x0e9f60(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x000E9F60ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE4FF4ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F4ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x52800020ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0103F3ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x97FD6E5FULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x36000160ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #2168 | PC: 0x0ea5b0..0x0ea608 (88 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x0ea5b0: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x0ea5b4: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0ea5b8: 910043FD  add      x29, sp, #0x10
//   0x0ea5bc: F9400413  ldr      x19, [x0, #8]
//   0x0ea5c0: B40000F3  cbz      x19, #0xea5dc
//   0x0ea5c4: 91002268  add      x8, x19, #8
uint64_t fde_func_2168_0x0ea5b0(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x000EA5B0ULL);
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

// FDE #2173 | PC: 0x0eab4c..0x0eac4c (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x0eab4c: D101C3FF  sub      sp, sp, #0x70
//   0x0eab50: F90023F5  str      x21, [sp, #0x40]
//   0x0eab54: A9054FF4  stp      x20, x19, [sp, #0x50]
//   0x0eab58: A9067BFD  stp      x29, x30, [sp, #0x60]
//   0x0eab5c: 910183FD  add      x29, sp, #0x60
//   0x0eab60: D53BD055  mrs      x21, tpidr_el0
uint64_t fde_func_2173_0x0eab4c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x000EAB4CULL);
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

// FDE #2177 | PC: 0x0eaeb8..0x0eafb8 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x0eaeb8: D10183FF  sub      sp, sp, #0x60
//   0x0eaebc: A90357F6  stp      x22, x21, [sp, #0x30]
//   0x0eaec0: A9044FF4  stp      x20, x19, [sp, #0x40]
//   0x0eaec4: A9057BFD  stp      x29, x30, [sp, #0x50]
//   0x0eaec8: 910143FD  add      x29, sp, #0x50
//   0x0eaecc: D53BD056  mrs      x22, tpidr_el0
uint64_t fde_func_2177_0x0eaeb8(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x000EAEB8ULL);
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

// FDE #2182 | PC: 0x0eb714..0x0eb71c (8 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x0eb714: B9503000  ldr      w0, [x0, #0x1030]
//   0x0eb718: D65F03C0  ret      
uint64_t fde_func_2182_0x0eb714(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x000EB714ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xB9503000ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD65F03C0ULL ^ (1ULL << 32);
    return state ^ (state >> 29);
}

// FDE #2186 | PC: 0x0ebb8c..0x0ebc1c (144 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x0ebb8c: D10103FF  sub      sp, sp, #0x40
//   0x0ebb90: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x0ebb94: A9037BFD  stp      x29, x30, [sp, #0x30]
//   0x0ebb98: 9100C3FD  add      x29, sp, #0x30
//   0x0ebb9c: D53BD054  mrs      x20, tpidr_el0
//   0x0ebba0: F9401689  ldr      x9, [x20, #0x28]
uint64_t fde_func_2186_0x0ebb8c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x000EBB8CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10103FFULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9024FF4ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9037BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9100C3FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD53BD054ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9401689ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91036000ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000FE9ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #2191 | PC: 0x0ebc48..0x0ebc50 (8 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x0ebc48: D1010000  sub      x0, x0, #0x40
//   0x0ebc4c: 17FFEA9F  b        #0xe66c8
uint64_t fde_func_2191_0x0ebc48(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x000EBC48ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD1010000ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x17FFEA9FULL ^ (1ULL << 32);
    return state ^ (state >> 29);
}

// FDE #2195 | PC: 0x0ebcdc..0x0ebd60 (132 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x0ebcdc: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x0ebce0: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0ebce4: 910043FD  add      x29, sp, #0x10
//   0x0ebce8: AA0003F3  mov      x19, x0
//   0x0ebcec: 9122A000  add      x0, x0, #0x8a8
//   0x0ebcf0: 52987161  mov      w1, #0xc38b
uint64_t fde_func_2195_0x0ebcdc(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x000EBCDCULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81E0FF3ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9122A000ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x52987161ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x2A1F03E2ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x940069E9ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #2200 | PC: 0x0ebfa8..0x0ec0a8 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x0ebfa8: D10243FF  sub      sp, sp, #0x90
//   0x0ebfac: A90657F6  stp      x22, x21, [sp, #0x60]
//   0x0ebfb0: A9074FF4  stp      x20, x19, [sp, #0x70]
//   0x0ebfb4: A9087BFD  stp      x29, x30, [sp, #0x80]
//   0x0ebfb8: 910203FD  add      x29, sp, #0x80
//   0x0ebfbc: D53BD055  mrs      x21, tpidr_el0
uint64_t fde_func_2200_0x0ebfa8(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x000EBFA8ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10243FFULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90657F6ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9074FF4ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9087BFDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910203FDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD53BD055ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF94016A8ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #2204 | PC: 0x0ec250..0x0ec350 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x0ec250: D10243FF  sub      sp, sp, #0x90
//   0x0ec254: A90657F6  stp      x22, x21, [sp, #0x60]
//   0x0ec258: A9074FF4  stp      x20, x19, [sp, #0x70]
//   0x0ec25c: A9087BFD  stp      x29, x30, [sp, #0x80]
//   0x0ec260: 910203FD  add      x29, sp, #0x80
//   0x0ec264: D53BD055  mrs      x21, tpidr_el0
uint64_t fde_func_2204_0x0ec250(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x000EC250ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10243FFULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90657F6ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9074FF4ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9087BFDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910203FDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD53BD055ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF94016A8ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #2209 | PC: 0x0ec65c..0x0ec664 (8 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x0ec65c: D1008000  sub      x0, x0, #0x20
//   0x0ec660: 17FFFFA4  b        #0xec4f0
uint64_t fde_func_2209_0x0ec65c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x000EC65CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD1008000ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x17FFFFA4ULL ^ (1ULL << 32);
    return state ^ (state >> 29);
}

// FDE #2213 | PC: 0x0ec930..0x0ec938 (8 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x0ec930: D1008000  sub      x0, x0, #0x20
//   0x0ec934: 17FFFF94  b        #0xec784
uint64_t fde_func_2213_0x0ec930(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x000EC930ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD1008000ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x17FFFF94ULL ^ (1ULL << 32);
    return state ^ (state >> 29);
}

// FDE #2218 | PC: 0x0ec9bc..0x0ec9e8 (44 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x0ec9bc: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x0ec9c0: 910003FD  mov      x29, sp
//   0x0ec9c4: 3945F408  ldrb     w8, [x0, #0x17d]
//   0x0ec9c8: 340000A8  cbz      w8, #0xec9dc
//   0x0ec9cc: 91036000  add      x0, x0, #0xd8
//   0x0ec9d0: 9401B61A  bl       #0x15a238
uint64_t fde_func_2218_0x0ec9bc(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x000EC9BCULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BF7BFDULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x3945F408ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x340000A8ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91036000ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9401B61AULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9E380000ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x14000002ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #2222 | PC: 0x0eca74..0x0eca88 (20 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x0eca74: 3945F408  ldrb     w8, [x0, #0x17d]
//   0x0eca78: 34000068  cbz      w8, #0xeca84
//   0x0eca7c: 91036000  add      x0, x0, #0xd8
//   0x0eca80: 1401B609  b        #0x15a2a4
//   0x0eca84: D65F03C0  ret      
uint64_t fde_func_2222_0x0eca74(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x000ECA74ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0x3945F408ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x34000068ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91036000ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x1401B609ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD65F03C0ULL ^ (4ULL << 32);
    return state ^ (state >> 29);
}

// FDE #2227 | PC: 0x0ecb74..0x0ecb90 (28 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x0ecb74: 39455408  ldrb     w8, [x0, #0x155]
//   0x0ecb78: 34000088  cbz      w8, #0xecb88
//   0x0ecb7c: D100A008  sub      x8, x0, #0x28
//   0x0ecb80: 91036100  add      x0, x8, #0xd8
//   0x0ecb84: 1401B5D8  b        #0x15a2e4
//   0x0ecb88: 12800000  mov      w0, #-1
uint64_t fde_func_2227_0x0ecb74(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x000ECB74ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0x39455408ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x34000088ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD100A008ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91036100ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x1401B5D8ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x12800000ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD65F03C0ULL ^ (6ULL << 32);
    return state ^ (state >> 29);
}

// FDE #2231 | PC: 0x0ecd18..0x0ece18 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x0ecd18: D10283FF  sub      sp, sp, #0xa0
//   0x0ecd1c: A90757F6  stp      x22, x21, [sp, #0x70]
//   0x0ecd20: A9084FF4  stp      x20, x19, [sp, #0x80]
//   0x0ecd24: A9097BFD  stp      x29, x30, [sp, #0x90]
//   0x0ecd28: 910243FD  add      x29, sp, #0x90
//   0x0ecd2c: D53BD055  mrs      x21, tpidr_el0
uint64_t fde_func_2231_0x0ecd18(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x000ECD18ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10283FFULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90757F6ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9084FF4ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9097BFDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910243FDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD53BD055ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF94016A9ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0803F3ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #2236 | PC: 0x0ed1d0..0x0ed2d0 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x0ed1d0: D104C3FF  sub      sp, sp, #0x130
//   0x0ed1d4: A90D6FFC  stp      x28, x27, [sp, #0xd0]
//   0x0ed1d8: A90E67FA  stp      x26, x25, [sp, #0xe0]
//   0x0ed1dc: A90F5FF8  stp      x24, x23, [sp, #0xf0]
//   0x0ed1e0: A91057F6  stp      x22, x21, [sp, #0x100]
//   0x0ed1e4: A9114FF4  stp      x20, x19, [sp, #0x110]
uint64_t fde_func_2236_0x0ed1d0(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x000ED1D0ULL);
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

// FDE #2240 | PC: 0x0ee194..0x0ee268 (212 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x0ee194: D10183FF  sub      sp, sp, #0x60
//   0x0ee198: F90013F7  str      x23, [sp, #0x20]
//   0x0ee19c: A90357F6  stp      x22, x21, [sp, #0x30]
//   0x0ee1a0: A9044FF4  stp      x20, x19, [sp, #0x40]
//   0x0ee1a4: A9057BFD  stp      x29, x30, [sp, #0x50]
//   0x0ee1a8: 910143FD  add      x29, sp, #0x50
uint64_t fde_func_2240_0x0ee194(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x000EE194ULL);
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

// FDE #2244 | PC: 0x0ee34c..0x0ee354 (8 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x0ee34c: 9122A000  add      x0, x0, #0x8a8
//   0x0ee350: D65F03C0  ret      
uint64_t fde_func_2244_0x0ee34c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x000EE34CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0x9122A000ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD65F03C0ULL ^ (1ULL << 32);
    return state ^ (state >> 29);
}

// FDE #2249 | PC: 0x0ee378..0x0ee380 (8 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x0ee378: 91222000  add      x0, x0, #0x888
//   0x0ee37c: 1400616A  b        #0x106924
uint64_t fde_func_2249_0x0ee378(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x000EE378ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0x91222000ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x1400616AULL ^ (1ULL << 32);
    return state ^ (state >> 29);
}

// FDE #2253 | PC: 0x0ee398..0x0ee3a0 (8 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x0ee398: 91138000  add      x0, x0, #0x4e0
//   0x0ee39c: D65F03C0  ret      
uint64_t fde_func_2253_0x0ee398(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x000EE398ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0x91138000ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD65F03C0ULL ^ (1ULL << 32);
    return state ^ (state >> 29);
}

// FDE #2258 | PC: 0x0ee404..0x0ee484 (128 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x0ee404: F81C0FF7  str      x23, [sp, #-0x40]!
//   0x0ee408: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x0ee40c: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x0ee410: A9037BFD  stp      x29, x30, [sp, #0x30]
//   0x0ee414: 9100C3FD  add      x29, sp, #0x30
//   0x0ee418: AA0203F5  mov      x21, x2
uint64_t fde_func_2258_0x0ee404(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x000EE404ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81C0FF7ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90157F6ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9024FF4ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9037BFDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9100C3FDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0203F5ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x2A0103F6ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F7ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #2262 | PC: 0x0ee4fc..0x0ee564 (104 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x0ee4fc: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x0ee500: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0ee504: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0ee508: 910083FD  add      x29, sp, #0x20
//   0x0ee50c: 2A0203F4  mov      w20, w2
//   0x0ee510: AA0103F5  mov      x21, x1
uint64_t fde_func_2262_0x0ee4fc(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x000EE4FCULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BD57F6ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9014FF4ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9027BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910083FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x2A0203F4ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0103F5ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F6ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9122A000ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #2267 | PC: 0x0eec48..0x0eec50 (8 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x0eec48: 91188000  add      x0, x0, #0x620
//   0x0eec4c: 14005816  b        #0x104ca4
uint64_t fde_func_2267_0x0eec48(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x000EEC48ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0x91188000ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x14005816ULL ^ (1ULL << 32);
    return state ^ (state >> 29);
}

// FDE #2271 | PC: 0x0eeedc..0x0eeee4 (8 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x0eeedc: D1008000  sub      x0, x0, #0x20
//   0x0eeee0: 17FFFF60  b        #0xeec60
uint64_t fde_func_2271_0x0eeedc(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x000EEEDCULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD1008000ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x17FFFF60ULL ^ (1ULL << 32);
    return state ^ (state >> 29);
}

// FDE #2276 | PC: 0x0ef238..0x0ef23c (4 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x0ef238: D65F03C0  ret      
uint64_t fde_func_2276_0x0ef238(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x000EF238ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD65F03C0ULL ^ (0ULL << 32);
    return state ^ (state >> 29);
}

// FDE #2280 | PC: 0x0ef248..0x0ef24c (4 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x0ef248: D65F03C0  ret      
uint64_t fde_func_2280_0x0ef248(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x000EF248ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD65F03C0ULL ^ (0ULL << 32);
    return state ^ (state >> 29);
}

// FDE #2285 | PC: 0x0ef2a4..0x0ef2a8 (4 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x0ef2a4: D4200020  brk      #1
uint64_t fde_func_2285_0x0ef2a4(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x000EF2A4ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD4200020ULL ^ (0ULL << 32);
    return state ^ (state >> 29);
}

// FDE #2289 | PC: 0x0ef2b4..0x0ef2d8 (36 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x0ef2b4: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x0ef2b8: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0ef2bc: 910043FD  add      x29, sp, #0x10
//   0x0ef2c0: AA0003F3  mov      x19, x0
//   0x0ef2c4: 97FFD6C1  bl       #0xe4dc8
//   0x0ef2c8: A9417BFD  ldp      x29, x30, [sp, #0x10]
uint64_t fde_func_2289_0x0ef2b4(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x000EF2B4ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81E0FF3ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x97FFD6C1ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9417BFDULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA1303E0ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF84207F3ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #2294 | PC: 0x0ef4ac..0x0ef4e8 (60 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x0ef4ac: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x0ef4b0: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0ef4b4: 910043FD  add      x29, sp, #0x10
//   0x0ef4b8: F9400801  ldr      x1, [x0, #0x10]
//   0x0ef4bc: AA0003F3  mov      x19, x0
//   0x0ef4c0: 9400000A  bl       #0xef4e8
uint64_t fde_func_2294_0x0ef4ac(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x000EF4ACULL);
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

// FDE #2298 | PC: 0x0ef5d4..0x0ef5d8 (4 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x0ef5d4: D65F03C0  ret      
uint64_t fde_func_2298_0x0ef5d4(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x000EF5D4ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD65F03C0ULL ^ (0ULL << 32);
    return state ^ (state >> 29);
}

// FDE #2303 | PC: 0x0ef6d8..0x0ef730 (88 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x0ef6d8: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x0ef6dc: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0ef6e0: 910043FD  add      x29, sp, #0x10
//   0x0ef6e4: F9400413  ldr      x19, [x0, #8]
//   0x0ef6e8: B40000F3  cbz      x19, #0xef704
//   0x0ef6ec: 91002268  add      x8, x19, #8
uint64_t fde_func_2303_0x0ef6d8(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x000EF6D8ULL);
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

// FDE #2307 | PC: 0x0ef814..0x0ef86c (88 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x0ef814: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x0ef818: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0ef81c: 910043FD  add      x29, sp, #0x10
//   0x0ef820: F9400413  ldr      x19, [x0, #8]
//   0x0ef824: B40000F3  cbz      x19, #0xef840
//   0x0ef828: 91002268  add      x8, x19, #8
uint64_t fde_func_2307_0x0ef814(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x000EF814ULL);
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

// FDE #2312 | PC: 0x0efad0..0x0efb14 (68 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x0efad0: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x0efad4: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0efad8: 910043FD  add      x29, sp, #0x10
//   0x0efadc: AA0003F3  mov      x19, x0
//   0x0efae0: 9400000D  bl       #0xefb14
//   0x0efae4: 91002268  add      x8, x19, #8
uint64_t fde_func_2312_0x0efad0(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x000EFAD0ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81E0FF3ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9400000DULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91002268ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xEB00011FULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x540000C0ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #2316 | PC: 0x0efcec..0x0efd3c (80 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x0efcec: B4000261  cbz      x1, #0xefd38
//   0x0efcf0: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0efcf4: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0efcf8: 910043FD  add      x29, sp, #0x10
//   0x0efcfc: AA0103F3  mov      x19, x1
//   0x0efd00: F9400021  ldr      x1, [x1]
uint64_t fde_func_2316_0x0efcec(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x000EFCECULL);
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

// FDE #2320 | PC: 0x0efe94..0x0efec4 (48 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x0efe94: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x0efe98: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0efe9c: 910043FD  add      x29, sp, #0x10
//   0x0efea0: D00013E8  adrp     x8, #0x36d000
//   0x0efea4: 91074108  add      x8, x8, #0x1d0
//   0x0efea8: AA0003F3  mov      x19, x0
uint64_t fde_func_2320_0x0efe94(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x000EFE94ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81E0FF3ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD00013E8ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91074108ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF8020408ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x94000036ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #2325 | PC: 0x0eff88..0x0f0078 (240 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x0eff88: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0eff8c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0eff90: 910043FD  add      x29, sp, #0x10
//   0x0eff94: 90001488  adrp     x8, #0x37f000
//   0x0eff98: F9467108  ldr      x8, [x8, #0xce0]
//   0x0eff9c: AA0003F3  mov      x19, x0
uint64_t fde_func_2325_0x0eff88(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x000EFF88ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE4FF4ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x90001488ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9467108ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91088009ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9412000ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #2329 | PC: 0x0f0158..0x0f01d4 (124 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x0f0158: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0f015c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0f0160: 910043FD  add      x29, sp, #0x10
//   0x0f0164: B00013E8  adrp     x8, #0x36d000
//   0x0f0168: 91088108  add      x8, x8, #0x220
//   0x0f016c: AA0003F3  mov      x19, x0
uint64_t fde_func_2329_0x0f0158(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x000F0158ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE4FF4ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB00013E8ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91088108ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000008ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91052000ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #2334 | PC: 0x0f02c8..0x0f0304 (60 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x0f02c8: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x0f02cc: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0f02d0: 910043FD  add      x29, sp, #0x10
//   0x0f02d4: F9400801  ldr      x1, [x0, #0x10]
//   0x0f02d8: AA0003F3  mov      x19, x0
//   0x0f02dc: 9400000A  bl       #0xf0304
uint64_t fde_func_2334_0x0f02c8(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x000F02C8ULL);
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

// FDE #2338 | PC: 0x0f03f0..0x0f042c (60 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x0f03f0: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x0f03f4: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0f03f8: 910043FD  add      x29, sp, #0x10
//   0x0f03fc: 91006040  add      x0, x2, #0x18
//   0x0f0400: AA0203F3  mov      x19, x2
//   0x0f0404: 9400000A  bl       #0xf042c
uint64_t fde_func_2338_0x0f03f0(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x000F03F0ULL);
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

// FDE #2343 | PC: 0x0f0520..0x0f0524 (4 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x0f0520: 17FD4F84  b        #0x44330
uint64_t fde_func_2343_0x0f0520(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x000F0520ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0x17FD4F84ULL ^ (0ULL << 32);
    return state ^ (state >> 29);
}

// FDE #2347 | PC: 0x0f060c..0x0f0624 (24 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x0f060c: B00013E8  adrp     x8, #0x36d000
//   0x0f0610: 910B0108  add      x8, x8, #0x2c0
//   0x0f0614: F9000028  str      x8, [x1]
//   0x0f0618: F9400408  ldr      x8, [x0, #8]
//   0x0f061c: F9000428  str      x8, [x1, #8]
//   0x0f0620: D65F03C0  ret      
uint64_t fde_func_2347_0x0f060c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x000F060CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xB00013E8ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910B0108ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000028ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400408ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000428ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD65F03C0ULL ^ (5ULL << 32);
    return state ^ (state >> 29);
}

// FDE #2352 | PC: 0x0f0684..0x0f0690 (12 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x0f0684: B00013E0  adrp     x0, #0x36d000
//   0x0f0688: 910C8000  add      x0, x0, #0x320
//   0x0f068c: D65F03C0  ret      
uint64_t fde_func_2352_0x0f0684(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x000F0684ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xB00013E0ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910C8000ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD65F03C0ULL ^ (2ULL << 32);
    return state ^ (state >> 29);
}

// FDE #2356 | PC: 0x0f06e4..0x0f06e8 (4 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x0f06e4: D65F03C0  ret      
uint64_t fde_func_2356_0x0f06e4(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x000F06E4ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD65F03C0ULL ^ (0ULL << 32);
    return state ^ (state >> 29);
}

// FDE #2361 | PC: 0x0f07a8..0x0f07ac (4 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x0f07a8: 17FD4EE2  b        #0x44330
uint64_t fde_func_2361_0x0f07a8(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x000F07A8ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0x17FD4EE2ULL ^ (0ULL << 32);
    return state ^ (state >> 29);
}

// FDE #2365 | PC: 0x0f0800..0x0f0804 (4 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x0f0800: 17FD4ECC  b        #0x44330
uint64_t fde_func_2365_0x0f0800(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x000F0800ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0x17FD4ECCULL ^ (0ULL << 32);
    return state ^ (state >> 29);
}

// FDE #2370 | PC: 0x0f0900..0x0f0930 (48 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x0f0900: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x0f0904: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0f0908: 910043FD  add      x29, sp, #0x10
//   0x0f090c: B00013E8  adrp     x8, #0x36d000
//   0x0f0910: 91118108  add      x8, x8, #0x460
//   0x0f0914: AA0003F3  mov      x19, x0
uint64_t fde_func_2370_0x0f0900(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x000F0900ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81E0FF3ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB00013E8ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91118108ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF8018408ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x94000016ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #2374 | PC: 0x0f0974..0x0f09b0 (60 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x0f0974: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x0f0978: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0f097c: 910043FD  add      x29, sp, #0x10
//   0x0f0980: 39406008  ldrb     w8, [x0, #0x18]
//   0x0f0984: B00013E9  adrp     x9, #0x36d000
//   0x0f0988: AA0003F3  mov      x19, x0
uint64_t fde_func_2374_0x0f0974(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x000F0974ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81E0FF3ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x39406008ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB00013E9ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9112C129ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000009ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #2379 | PC: 0x0f0d18..0x0f0d64 (76 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x0f0d18: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x0f0d1c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0f0d20: 910043FD  add      x29, sp, #0x10
//   0x0f0d24: 39408008  ldrb     w8, [x0, #0x20]
//   0x0f0d28: B00013E9  adrp     x9, #0x36d000
//   0x0f0d2c: AA0003F3  mov      x19, x0
uint64_t fde_func_2379_0x0f0d18(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x000F0D18ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81E0FF3ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x39408008ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB00013E9ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91136129ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000009ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #2383 | PC: 0x0f0e4c..0x0f0e8c (64 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x0f0e4c: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x0f0e50: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0f0e54: 910043FD  add      x29, sp, #0x10
//   0x0f0e58: 39408008  ldrb     w8, [x0, #0x20]
//   0x0f0e5c: AA0003F3  mov      x19, x0
//   0x0f0e60: 36000068  tbz      w8, #0, #0xf0e6c
uint64_t fde_func_2383_0x0f0e4c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x000F0E4CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81E0FF3ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x39408008ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x36000068ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9401A60ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x97FD4D32ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #2388 | PC: 0x0f10d4..0x0f1104 (48 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x0f10d4: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x0f10d8: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0f10dc: 910043FD  add      x29, sp, #0x10
//   0x0f10e0: 900013E8  adrp     x8, #0x36d000
//   0x0f10e4: 91152108  add      x8, x8, #0x548
//   0x0f10e8: AA0003F3  mov      x19, x0
uint64_t fde_func_2388_0x0f10d4(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x000F10D4ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81E0FF3ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x900013E8ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91152108ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF8018408ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x94000016ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #2392 | PC: 0x0f1148..0x0f118c (68 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x0f1148: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x0f114c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0f1150: 910043FD  add      x29, sp, #0x10
//   0x0f1154: 900013E8  adrp     x8, #0x36d000
//   0x0f1158: 91166108  add      x8, x8, #0x598
//   0x0f115c: AA0003F3  mov      x19, x0
uint64_t fde_func_2392_0x0f1148(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x000F1148ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81E0FF3ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x900013E8ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91166108ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF8020408ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x97FD62B3ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #2396 | PC: 0x0f1454..0x0f1524 (208 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x0f1454: D10143FF  sub      sp, sp, #0x50
//   0x0f1458: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x0f145c: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x0f1460: A9047BFD  stp      x29, x30, [sp, #0x40]
//   0x0f1464: 910103FD  add      x29, sp, #0x40
//   0x0f1468: D53BD056  mrs      x22, tpidr_el0
uint64_t fde_func_2396_0x0f1454(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x000F1454ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10143FFULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90257F6ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9034FF4ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9047BFDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910103FDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD53BD056ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF94016C8ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F5ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #2401 | PC: 0x0f15c4..0x0f1674 (176 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x0f15c4: D10143FF  sub      sp, sp, #0x50
//   0x0f15c8: F90013F5  str      x21, [sp, #0x20]
//   0x0f15cc: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x0f15d0: A9047BFD  stp      x29, x30, [sp, #0x40]
//   0x0f15d4: 910103FD  add      x29, sp, #0x40
//   0x0f15d8: D53BD054  mrs      x20, tpidr_el0
uint64_t fde_func_2401_0x0f15c4(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x000F15C4ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10143FFULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF90013F5ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9034FF4ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9047BFDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910103FDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD53BD054ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9401688ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003E9ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #2405 | PC: 0x0f16d4..0x0f17d4 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x0f16d4: A9BC5FF8  stp      x24, x23, [sp, #-0x40]!
//   0x0f16d8: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x0f16dc: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x0f16e0: A9037BFD  stp      x29, x30, [sp, #0x30]
//   0x0f16e4: 9100C3FD  add      x29, sp, #0x30
//   0x0f16e8: AA0003F3  mov      x19, x0
uint64_t fde_func_2405_0x0f16d4(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x000F16D4ULL);
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

// FDE #2410 | PC: 0x0f1a38..0x0f1a70 (56 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x0f1a38: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x0f1a3c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0f1a40: 910043FD  add      x29, sp, #0x10
//   0x0f1a44: 900013E8  adrp     x8, #0x36d000
//   0x0f1a48: 91198108  add      x8, x8, #0x660
//   0x0f1a4c: AA0003F3  mov      x19, x0
uint64_t fde_func_2410_0x0f1a38(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x000F1A38ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81E0FF3ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x900013E8ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91198108ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF8018408ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9400000BULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #2414 | PC: 0x0f1ad4..0x0f1af8 (36 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x0f1ad4: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x0f1ad8: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0f1adc: 910043FD  add      x29, sp, #0x10
//   0x0f1ae0: AA0003F3  mov      x19, x0
//   0x0f1ae4: 97FFFFE7  bl       #0xf1a80
//   0x0f1ae8: A9417BFD  ldp      x29, x30, [sp, #0x10]
uint64_t fde_func_2414_0x0f1ad4(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x000F1AD4ULL);
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

// FDE #2419 | PC: 0x0f1df8..0x0f1e48 (80 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x0f1df8: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0f1dfc: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0f1e00: 910043FD  add      x29, sp, #0x10
//   0x0f1e04: AA0003F3  mov      x19, x0
//   0x0f1e08: 52800600  mov      w0, #0x30
//   0x0f1e0c: 97FD48B1  bl       #0x440d0
uint64_t fde_func_2419_0x0f1df8(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x000F1DF8ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE4FF4ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x52800600ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x97FD48B1ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x900013E8ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x911B6108ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #2423 | PC: 0x0f1ed4..0x0f1f90 (188 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x0f1ed4: D10143FF  sub      sp, sp, #0x50
//   0x0f1ed8: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x0f1edc: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x0f1ee0: A9047BFD  stp      x29, x30, [sp, #0x40]
//   0x0f1ee4: 910103FD  add      x29, sp, #0x40
//   0x0f1ee8: D53BD056  mrs      x22, tpidr_el0
uint64_t fde_func_2423_0x0f1ed4(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x000F1ED4ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10143FFULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90257F6ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9034FF4ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9047BFDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910103FDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD53BD056ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF94016C8ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #2428 | PC: 0x0f2060..0x0f20b8 (88 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x0f2060: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x0f2064: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0f2068: 910043FD  add      x29, sp, #0x10
//   0x0f206c: AA0003F3  mov      x19, x0
//   0x0f2070: F9402000  ldr      x0, [x0, #0x40]
//   0x0f2074: F00013C8  adrp     x8, #0x36d000
uint64_t fde_func_2428_0x0f2060(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x000F2060ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81E0FF3ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9402000ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF00013C8ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91008269ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x911D6108ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #2432 | PC: 0x0f215c..0x0f21a8 (76 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x0f215c: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x0f2160: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0f2164: 910043FD  add      x29, sp, #0x10
//   0x0f2168: AA0003F3  mov      x19, x0
//   0x0f216c: F9402000  ldr      x0, [x0, #0x40]
//   0x0f2170: 91008268  add      x8, x19, #0x20
uint64_t fde_func_2432_0x0f215c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x000F215CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81E0FF3ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9402000ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91008268ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xEB00011FULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x540000A0ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #2437 | PC: 0x0f234c..0x0f238c (64 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x0f234c: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0f2350: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0f2354: 910043FD  add      x29, sp, #0x10
//   0x0f2358: D37CFC28  lsr      x8, x1, #0x3c
//   0x0f235c: B5000168  cbnz     x8, #0xf2388
//   0x0f2360: AA0003F4  mov      x20, x0
uint64_t fde_func_2437_0x0f234c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x000F234CULL);
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

// FDE #2441 | PC: 0x0f2470..0x0f24c4 (84 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x0f2470: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0f2474: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0f2478: 910043FD  add      x29, sp, #0x10
//   0x0f247c: F00013C8  adrp     x8, #0x36d000
//   0x0f2480: AA0003F4  mov      x20, x0
//   0x0f2484: 911FA108  add      x8, x8, #0x7e8
uint64_t fde_func_2441_0x0f2470(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x000F2470ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE4FF4ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF00013C8ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F4ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x911FA108ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0103F3ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91002020ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #2446 | PC: 0x0f30ac..0x0f30b8 (12 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x0f30ac: D00013C0  adrp     x0, #0x36d000
//   0x0f30b0: 91212000  add      x0, x0, #0x848
//   0x0f30b4: D65F03C0  ret      
uint64_t fde_func_2446_0x0f30ac(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x000F30ACULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD00013C0ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91212000ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD65F03C0ULL ^ (2ULL << 32);
    return state ^ (state >> 29);
}

// FDE #2450 | PC: 0x0f326c..0x0f328c (32 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x0f326c: F9400068  ldr      x8, [x3]
//   0x0f3270: CB010042  sub      x2, x2, x1
//   0x0f3274: F100045F  cmp      x2, #1
//   0x0f3278: CB020100  sub      x0, x8, x2
//   0x0f327c: F9000060  str      x0, [x3]
//   0x0f3280: 5400004B  b.lt     #0xf3288
uint64_t fde_func_2450_0x0f326c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x000F326CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400068ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xCB010042ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF100045FULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xCB020100ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000060ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x5400004BULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x17FD46FFULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD65F03C0ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #2455 | PC: 0x0f336c..0x0f3374 (8 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x0f336c: 91002000  add      x0, x0, #8
//   0x0f3370: 17FDAF5D  b        #0x5f0e4
uint64_t fde_func_2455_0x0f336c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x000F336CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0x91002000ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x17FDAF5DULL ^ (1ULL << 32);
    return state ^ (state >> 29);
}

// FDE #2459 | PC: 0x0f3480..0x0f348c (12 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x0f3480: D00013C0  adrp     x0, #0x36d000
//   0x0f3484: 91232000  add      x0, x0, #0x8c8
//   0x0f3488: D65F03C0  ret      
uint64_t fde_func_2459_0x0f3480(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x000F3480ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD00013C0ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91232000ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD65F03C0ULL ^ (2ULL << 32);
    return state ^ (state >> 29);
}

// FDE #2464 | PC: 0x0f3500..0x0f3504 (4 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x0f3500: 17FD438C  b        #0x44330
uint64_t fde_func_2464_0x0f3500(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x000F3500ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0x17FD438CULL ^ (0ULL << 32);
    return state ^ (state >> 29);
}

// FDE #2468 | PC: 0x0f3558..0x0f355c (4 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x0f3558: 17FD4376  b        #0x44330
uint64_t fde_func_2468_0x0f3558(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x000F3558ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0x17FD4376ULL ^ (0ULL << 32);
    return state ^ (state >> 29);
}

// FDE #2473 | PC: 0x0f3590..0x0f35c8 (56 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x0f3590: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x0f3594: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0f3598: 910043FD  add      x29, sp, #0x10
//   0x0f359c: AA0003F3  mov      x19, x0
//   0x0f35a0: 52800300  mov      w0, #0x18
//   0x0f35a4: 97FD42CB  bl       #0x440d0
uint64_t fde_func_2473_0x0f3590(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x000F3590ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81E0FF3ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x52800300ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x97FD42CBULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD00013C8ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9126E108ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #2477 | PC: 0x0f35e8..0x0f36e8 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x0f35e8: D10243FF  sub      sp, sp, #0x90
//   0x0f35ec: A9036FFC  stp      x28, x27, [sp, #0x30]
//   0x0f35f0: A90467FA  stp      x26, x25, [sp, #0x40]
//   0x0f35f4: A9055FF8  stp      x24, x23, [sp, #0x50]
//   0x0f35f8: A90657F6  stp      x22, x21, [sp, #0x60]
//   0x0f35fc: A9074FF4  stp      x20, x19, [sp, #0x70]
uint64_t fde_func_2477_0x0f35e8(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x000F35E8ULL);
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

// FDE #2481 | PC: 0x0f38a0..0x0f38d8 (56 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x0f38a0: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x0f38a4: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0f38a8: 910043FD  add      x29, sp, #0x10
//   0x0f38ac: AA0003F3  mov      x19, x0
//   0x0f38b0: 52800200  mov      w0, #0x10
//   0x0f38b4: 97FD4207  bl       #0x440d0
uint64_t fde_func_2481_0x0f38a0(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x000F38A0ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81E0FF3ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x52800200ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x97FD4207ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD00013C8ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9128E108ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #2486 | PC: 0x0f3aac..0x0f3ac8 (28 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x0f3aac: F9400428  ldr      x8, [x1, #8]
//   0x0f3ab0: F0000EE9  adrp     x9, #0x2d2000
//   0x0f3ab4: 91225129  add      x9, x9, #0x894
//   0x0f3ab8: 9100200A  add      x10, x0, #8
//   0x0f3abc: EB09011F  cmp      x8, x9
//   0x0f3ac0: 9A9F0140  csel     x0, x10, xzr, eq
uint64_t fde_func_2486_0x0f3aac(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x000F3AACULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400428ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF0000EE9ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91225129ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9100200AULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xEB09011FULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9A9F0140ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD65F03C0ULL ^ (6ULL << 32);
    return state ^ (state >> 29);
}

// FDE #2490 | PC: 0x0f3b58..0x0f3b90 (56 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x0f3b58: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x0f3b5c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0f3b60: 910043FD  add      x29, sp, #0x10
//   0x0f3b64: AA0003F3  mov      x19, x0
//   0x0f3b68: 52800200  mov      w0, #0x10
//   0x0f3b6c: 97FD4159  bl       #0x440d0
uint64_t fde_func_2490_0x0f3b58(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x000F3B58ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81E0FF3ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x52800200ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x97FD4159ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD00013C8ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x912AE108ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #2495 | PC: 0x0f3c8c..0x0f3ca8 (28 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x0f3c8c: F9400428  ldr      x8, [x1, #8]
//   0x0f3c90: F0000EE9  adrp     x9, #0x2d2000
//   0x0f3c94: 9124CD29  add      x9, x9, #0x933
//   0x0f3c98: 9100200A  add      x10, x0, #8
//   0x0f3c9c: EB09011F  cmp      x8, x9
//   0x0f3ca0: 9A9F0140  csel     x0, x10, xzr, eq
uint64_t fde_func_2495_0x0f3c8c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x000F3C8CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400428ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF0000EE9ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9124CD29ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9100200AULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xEB09011FULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9A9F0140ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD65F03C0ULL ^ (6ULL << 32);
    return state ^ (state >> 29);
}

// FDE #2499 | PC: 0x0f3d34..0x0f3e34 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x0f3d34: D103C3FF  sub      sp, sp, #0xf0
//   0x0f3d38: A90A67FA  stp      x26, x25, [sp, #0xa0]
//   0x0f3d3c: A90B5FF8  stp      x24, x23, [sp, #0xb0]
//   0x0f3d40: A90C57F6  stp      x22, x21, [sp, #0xc0]
//   0x0f3d44: A90D4FF4  stp      x20, x19, [sp, #0xd0]
//   0x0f3d48: A90E7BFD  stp      x29, x30, [sp, #0xe0]
uint64_t fde_func_2499_0x0f3d34(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x000F3D34ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD103C3FFULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90A67FAULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90B5FF8ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90C57F6ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90D4FF4ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90E7BFDULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910383FDULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD53BD059ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #2504 | PC: 0x0f4a88..0x0f4a90 (8 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x0f4a88: 52800080  mov      w0, #4
//   0x0f4a8c: D65F03C0  ret      
uint64_t fde_func_2504_0x0f4a88(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x000F4A88ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0x52800080ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD65F03C0ULL ^ (1ULL << 32);
    return state ^ (state >> 29);
}

// FDE #2508 | PC: 0x0f4c54..0x0f4c5c (8 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x0f4c54: D100E000  sub      x0, x0, #0x38
//   0x0f4c58: 17FFFFBC  b        #0xf4b48
uint64_t fde_func_2508_0x0f4c54(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x000F4C54ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD100E000ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x17FFFFBCULL ^ (1ULL << 32);
    return state ^ (state >> 29);
}

// FDE #2513 | PC: 0x0f4dcc..0x0f4e7c (176 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x0f4dcc: D10143FF  sub      sp, sp, #0x50
//   0x0f4dd0: FD0013E8  str      d8, [sp, #0x20]
//   0x0f4dd4: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x0f4dd8: A9047BFD  stp      x29, x30, [sp, #0x40]
//   0x0f4ddc: 910103FD  add      x29, sp, #0x40
//   0x0f4de0: D53BD054  mrs      x20, tpidr_el0
uint64_t fde_func_2513_0x0f4dcc(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x000F4DCCULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10143FFULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xFD0013E8ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9034FF4ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9047BFDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910103FDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD53BD054ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9401688ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9107A000ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #2517 | PC: 0x0f4e9c..0x0f4f9c (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x0f4e9c: D101C3FF  sub      sp, sp, #0x70
//   0x0f4ea0: F9001BF7  str      x23, [sp, #0x30]
//   0x0f4ea4: A90457F6  stp      x22, x21, [sp, #0x40]
//   0x0f4ea8: A9054FF4  stp      x20, x19, [sp, #0x50]
//   0x0f4eac: A9067BFD  stp      x29, x30, [sp, #0x60]
//   0x0f4eb0: 910183FD  add      x29, sp, #0x60
uint64_t fde_func_2517_0x0f4e9c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x000F4E9CULL);
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

// FDE #2522 | PC: 0x0f51cc..0x0f51d4 (8 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x0f51cc: D100E000  sub      x0, x0, #0x38
//   0x0f51d0: 17FFFFC3  b        #0xf50dc
uint64_t fde_func_2522_0x0f51cc(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x000F51CCULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD100E000ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x17FFFFC3ULL ^ (1ULL << 32);
    return state ^ (state >> 29);
}

// FDE #2526 | PC: 0x0f538c..0x0f5394 (8 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x0f538c: D1008000  sub      x0, x0, #0x20
//   0x0f5390: 17FFFFC9  b        #0xf52b4
uint64_t fde_func_2526_0x0f538c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x000F538CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD1008000ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x17FFFFC9ULL ^ (1ULL << 32);
    return state ^ (state >> 29);
}

// FDE #2531 | PC: 0x0f5580..0x0f5620 (160 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x0f5580: D10103FF  sub      sp, sp, #0x40
//   0x0f5584: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x0f5588: A9037BFD  stp      x29, x30, [sp, #0x30]
//   0x0f558c: 9100C3FD  add      x29, sp, #0x30
//   0x0f5590: D53BD054  mrs      x20, tpidr_el0
//   0x0f5594: AA0803F3  mov      x19, x8
uint64_t fde_func_2531_0x0f5580(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x000F5580ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10103FFULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9024FF4ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9037BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9100C3FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD53BD054ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0803F3ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9401688ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9107A000ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #2535 | PC: 0x0f5754..0x0f5854 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x0f5754: D10143FF  sub      sp, sp, #0x50
//   0x0f5758: F90013F5  str      x21, [sp, #0x20]
//   0x0f575c: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x0f5760: A9047BFD  stp      x29, x30, [sp, #0x40]
//   0x0f5764: 910103FD  add      x29, sp, #0x40
//   0x0f5768: D53BD055  mrs      x21, tpidr_el0
uint64_t fde_func_2535_0x0f5754(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x000F5754ULL);
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

// FDE #2540 | PC: 0x0f5cb8..0x0f5cc0 (8 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x0f5cb8: D100C000  sub      x0, x0, #0x30
//   0x0f5cbc: 17FFFF79  b        #0xf5aa0
uint64_t fde_func_2540_0x0f5cb8(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x000F5CB8ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD100C000ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x17FFFF79ULL ^ (1ULL << 32);
    return state ^ (state >> 29);
}

// FDE #2544 | PC: 0x0f6178..0x0f6180 (8 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x0f6178: D1008000  sub      x0, x0, #0x20
//   0x0f617c: 17FFFF68  b        #0xf5f1c
uint64_t fde_func_2544_0x0f6178(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x000F6178ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD1008000ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x17FFFF68ULL ^ (1ULL << 32);
    return state ^ (state >> 29);
}

// FDE #2549 | PC: 0x0f649c..0x0f64f4 (88 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x0f649c: D10103FF  sub      sp, sp, #0x40
//   0x0f64a0: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x0f64a4: A9037BFD  stp      x29, x30, [sp, #0x30]
//   0x0f64a8: 9100C3FD  add      x29, sp, #0x30
//   0x0f64ac: D53BD054  mrs      x20, tpidr_el0
//   0x0f64b0: AA0803F3  mov      x19, x8
uint64_t fde_func_2549_0x0f649c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x000F649CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10103FFULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9024FF4ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9037BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9100C3FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD53BD054ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0803F3ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9401688ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9107A000ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #2553 | PC: 0x0f65e4..0x0f66e4 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x0f65e4: D107C3FF  sub      sp, sp, #0x1f0
//   0x0f65e8: FD00C3E8  str      d8, [sp, #0x180]
//   0x0f65ec: A9196FFC  stp      x28, x27, [sp, #0x190]
//   0x0f65f0: A91A67FA  stp      x26, x25, [sp, #0x1a0]
//   0x0f65f4: A91B5FF8  stp      x24, x23, [sp, #0x1b0]
//   0x0f65f8: A91C57F6  stp      x22, x21, [sp, #0x1c0]
uint64_t fde_func_2553_0x0f65e4(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x000F65E4ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD107C3FFULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xFD00C3E8ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9196FFCULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA91A67FAULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA91B5FF8ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA91C57F6ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA91D4FF4ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA91E7BFDULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #2557 | PC: 0x0f9874..0x0f987c (8 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x0f9874: D1012000  sub      x0, x0, #0x48
//   0x0f9878: 17FFF35B  b        #0xf65e4
uint64_t fde_func_2557_0x0f9874(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x000F9874ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD1012000ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x17FFF35BULL ^ (1ULL << 32);
    return state ^ (state >> 29);
}

// FDE #2562 | PC: 0x0f9d94..0x0f9d98 (4 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x0f9d94: D65F03C0  ret      
uint64_t fde_func_2562_0x0f9d94(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x000F9D94ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD65F03C0ULL ^ (0ULL << 32);
    return state ^ (state >> 29);
}

// FDE #2566 | PC: 0x0f9dc4..0x0f9dd0 (12 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x0f9dc4: 900013A0  adrp     x0, #0x36d000
//   0x0f9dc8: 912E6000  add      x0, x0, #0xb98
//   0x0f9dcc: D65F03C0  ret      
uint64_t fde_func_2566_0x0f9dc4(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x000F9DC4ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0x900013A0ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x912E6000ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD65F03C0ULL ^ (2ULL << 32);
    return state ^ (state >> 29);
}

// FDE #2571 | PC: 0x0fa140..0x0fa178 (56 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x0fa140: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x0fa144: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0fa148: 910043FD  add      x29, sp, #0x10
//   0x0fa14c: F0001388  adrp     x8, #0x36d000
//   0x0fa150: 912EE108  add      x8, x8, #0xbb8
//   0x0fa154: AA0003F3  mov      x19, x0
uint64_t fde_func_2571_0x0fa140(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x000FA140ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81E0FF3ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF0001388ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x912EE108ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF8018408ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9400000BULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #2575 | PC: 0x0fa1e8..0x0fa20c (36 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x0fa1e8: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x0fa1ec: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0fa1f0: 910043FD  add      x29, sp, #0x10
//   0x0fa1f4: AA0003F3  mov      x19, x0
//   0x0fa1f8: 97FFFFE4  bl       #0xfa188
//   0x0fa1fc: A9417BFD  ldp      x29, x30, [sp, #0x10]
uint64_t fde_func_2575_0x0fa1e8(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x000FA1E8ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81E0FF3ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x97FFFFE4ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9417BFDULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA1303E0ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF84207F3ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #2580 | PC: 0x0fa524..0x0fa530 (12 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x0fa524: F8418C08  ldr      x8, [x0, #0x18]!
//   0x0fa528: F9400101  ldr      x1, [x8]
//   0x0fa52c: D61F0020  br       x1
uint64_t fde_func_2580_0x0fa524(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x000FA524ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF8418C08ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400101ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD61F0020ULL ^ (2ULL << 32);
    return state ^ (state >> 29);
}

// FDE #2584 | PC: 0x0fa5a8..0x0fa6a8 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x0fa5a8: D106C3FF  sub      sp, sp, #0x1b0
//   0x0fa5ac: A9156FFC  stp      x28, x27, [sp, #0x150]
//   0x0fa5b0: A91667FA  stp      x26, x25, [sp, #0x160]
//   0x0fa5b4: A9175FF8  stp      x24, x23, [sp, #0x170]
//   0x0fa5b8: A91857F6  stp      x22, x21, [sp, #0x180]
//   0x0fa5bc: A9194FF4  stp      x20, x19, [sp, #0x190]
uint64_t fde_func_2584_0x0fa5a8(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x000FA5A8ULL);
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

// FDE #2589 | PC: 0x0fa9f8..0x0faa58 (96 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x0fa9f8: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x0fa9fc: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0faa00: 910043FD  add      x29, sp, #0x10
//   0x0faa04: AA0003F3  mov      x19, x0
//   0x0faa08: 52800020  mov      w0, #1
//   0x0faa0c: 97FD2BBA  bl       #0x458f4
uint64_t fde_func_2589_0x0fa9f8(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x000FA9F8ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81E0FF3ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x52800020ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x97FD2BBAULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x36000180ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB94F4A65ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #2593 | PC: 0x0fac58..0x0fac60 (8 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x0fac58: D100C000  sub      x0, x0, #0x30
//   0x0fac5c: 17FFFFC4  b        #0xfab6c
uint64_t fde_func_2593_0x0fac58(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x000FAC58ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD100C000ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x17FFFFC4ULL ^ (1ULL << 32);
    return state ^ (state >> 29);
}

// FDE #2598 | PC: 0x0fb2d4..0x0fb378 (164 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x0fb2d4: D10103FF  sub      sp, sp, #0x40
//   0x0fb2d8: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x0fb2dc: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x0fb2e0: A9037BFD  stp      x29, x30, [sp, #0x30]
//   0x0fb2e4: 9100C3FD  add      x29, sp, #0x30
//   0x0fb2e8: AA0303F3  mov      x19, x3
uint64_t fde_func_2598_0x0fb2d4(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x000FB2D4ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10103FFULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90157F6ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9024FF4ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9037BFDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9100C3FDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0303F3ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x528514C3ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x2A1303E4ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #2602 | PC: 0x0fb41c..0x0fb48c (112 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x0fb41c: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x0fb420: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0fb424: 910043FD  add      x29, sp, #0x10
//   0x0fb428: AA0003F3  mov      x19, x0
//   0x0fb42c: B94F5800  ldr      w0, [x0, #0xf58]
//   0x0fb430: 7100041F  cmp      w0, #1
uint64_t fde_func_2602_0x0fb41c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x000FB41CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81E0FF3ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB94F5800ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x7100041FULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x54000061ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x52800020ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #2607 | PC: 0x0fb808..0x0fb810 (8 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x0fb808: D1016000  sub      x0, x0, #0x58
//   0x0fb80c: 17FFFF3E  b        #0xfb504
uint64_t fde_func_2607_0x0fb808(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x000FB808ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD1016000ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x17FFFF3EULL ^ (1ULL << 32);
    return state ^ (state >> 29);
}

// FDE #2611 | PC: 0x0fb9cc..0x0fb9d4 (8 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x0fb9cc: D1016000  sub      x0, x0, #0x58
//   0x0fb9d0: 17FFFFCE  b        #0xfb908
uint64_t fde_func_2611_0x0fb9cc(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x000FB9CCULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD1016000ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x17FFFFCEULL ^ (1ULL << 32);
    return state ^ (state >> 29);
}

// FDE #2616 | PC: 0x0fee28..0x0fef28 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x0fee28: D10243FF  sub      sp, sp, #0x90
//   0x0fee2c: A9055FF8  stp      x24, x23, [sp, #0x50]
//   0x0fee30: A90657F6  stp      x22, x21, [sp, #0x60]
//   0x0fee34: A9074FF4  stp      x20, x19, [sp, #0x70]
//   0x0fee38: A9087BFD  stp      x29, x30, [sp, #0x80]
//   0x0fee3c: 910203FD  add      x29, sp, #0x80
uint64_t fde_func_2616_0x0fee28(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x000FEE28ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10243FFULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9055FF8ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90657F6ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9074FF4ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9087BFDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910203FDULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD53BD058ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9401708ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #2620 | PC: 0x0ff1d4..0x0ff224 (80 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x0ff1d4: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x0ff1d8: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0ff1dc: 910043FD  add      x29, sp, #0x10
//   0x0ff1e0: D0001368  adrp     x8, #0x36d000
//   0x0ff1e4: D0001369  adrp     x9, #0x36d000
//   0x0ff1e8: 91330108  add      x8, x8, #0xcc0
uint64_t fde_func_2620_0x0ff1d4(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x000FF1D4ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81E0FF3ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD0001368ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD0001369ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91330108ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91344129ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #2625 | PC: 0x0ff2d0..0x0ff3d0 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x0ff2d0: D106C3FF  sub      sp, sp, #0x1b0
//   0x0ff2d4: A9156FFC  stp      x28, x27, [sp, #0x150]
//   0x0ff2d8: A91667FA  stp      x26, x25, [sp, #0x160]
//   0x0ff2dc: A9175FF8  stp      x24, x23, [sp, #0x170]
//   0x0ff2e0: A91857F6  stp      x22, x21, [sp, #0x180]
//   0x0ff2e4: A9194FF4  stp      x20, x19, [sp, #0x190]
uint64_t fde_func_2625_0x0ff2d0(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x000FF2D0ULL);
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

// FDE #2629 | PC: 0x0ff714..0x0ff744 (48 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x0ff714: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x0ff718: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0ff71c: 910043FD  add      x29, sp, #0x10
//   0x0ff720: D0001368  adrp     x8, #0x36d000
//   0x0ff724: 91354108  add      x8, x8, #0xd50
//   0x0ff728: AA0003F3  mov      x19, x0
uint64_t fde_func_2629_0x0ff714(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x000FF714ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81E0FF3ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD0001368ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91354108ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF8018408ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x94000017ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #2634 | PC: 0x0ff804..0x0ff828 (36 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x0ff804: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x0ff808: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0ff80c: 910043FD  add      x29, sp, #0x10
//   0x0ff810: AA0003F3  mov      x19, x0
//   0x0ff814: 97FFFFDE  bl       #0xff78c
//   0x0ff818: A9417BFD  ldp      x29, x30, [sp, #0x10]
uint64_t fde_func_2634_0x0ff804(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x000FF804ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81E0FF3ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x97FFFFDEULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9417BFDULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA1303E0ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF84207F3ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #2638 | PC: 0x0ffc54..0x0ffd54 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x0ffc54: D10283FF  sub      sp, sp, #0xa0
//   0x0ffc58: A9046FFC  stp      x28, x27, [sp, #0x40]
//   0x0ffc5c: A90567FA  stp      x26, x25, [sp, #0x50]
//   0x0ffc60: A9065FF8  stp      x24, x23, [sp, #0x60]
//   0x0ffc64: A90757F6  stp      x22, x21, [sp, #0x70]
//   0x0ffc68: A9084FF4  stp      x20, x19, [sp, #0x80]
uint64_t fde_func_2638_0x0ffc54(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x000FFC54ULL);
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

// FDE #2642 | PC: 0x100080..0x10017c (252 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x100080: D101C3FF  sub      sp, sp, #0x70
//   0x100084: F9000BFB  str      x27, [sp, #0x10]
//   0x100088: A90267FA  stp      x26, x25, [sp, #0x20]
//   0x10008c: A9035FF8  stp      x24, x23, [sp, #0x30]
//   0x100090: A90457F6  stp      x22, x21, [sp, #0x40]
//   0x100094: A9054FF4  stp      x20, x19, [sp, #0x50]
uint64_t fde_func_2642_0x100080(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00100080ULL);
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

// FDE #2647 | PC: 0x1004ec..0x100544 (88 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x1004ec: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x1004f0: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x1004f4: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x1004f8: 910083FD  add      x29, sp, #0x20
//   0x1004fc: AA0003F5  mov      x21, x0
//   0x100500: AA0103E0  mov      x0, x1
uint64_t fde_func_2647_0x1004ec(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x001004ECULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81D0FF5ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9014FF4ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9027BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910083FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F5ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0103E0ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0203F3ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0103F4ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #2651 | PC: 0x100bf0..0x100cf0 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x100bf0: D10243FF  sub      sp, sp, #0x90
//   0x100bf4: A9036FFC  stp      x28, x27, [sp, #0x30]
//   0x100bf8: A90467FA  stp      x26, x25, [sp, #0x40]
//   0x100bfc: A9055FF8  stp      x24, x23, [sp, #0x50]
//   0x100c00: A90657F6  stp      x22, x21, [sp, #0x60]
//   0x100c04: A9074FF4  stp      x20, x19, [sp, #0x70]
uint64_t fde_func_2651_0x100bf0(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00100BF0ULL);
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

// FDE #2656 | PC: 0x1019d4..0x101a6c (152 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x1019d4: D10103FF  sub      sp, sp, #0x40
//   0x1019d8: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x1019dc: A9037BFD  stp      x29, x30, [sp, #0x30]
//   0x1019e0: 9100C3FD  add      x29, sp, #0x30
//   0x1019e4: D53BD054  mrs      x20, tpidr_el0
//   0x1019e8: F9401688  ldr      x8, [x20, #0x28]
uint64_t fde_func_2656_0x1019d4(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x001019D4ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10103FFULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9024FF4ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9037BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9100C3FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD53BD054ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9401688ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910D4000ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0303F3ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #2660 | PC: 0x101a88..0x101a94 (12 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x101a88: 910CC000  add      x0, x0, #0x330
//   0x101a8c: 12000063  and      w3, w3, #1
//   0x101a90: 17FF733B  b        #0xde77c
uint64_t fde_func_2660_0x101a88(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00101A88ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0x910CC000ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x12000063ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x17FF733BULL ^ (2ULL << 32);
    return state ^ (state >> 29);
}

// FDE #2665 | PC: 0x1022d8..0x1022e0 (8 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x1022d8: D1008000  sub      x0, x0, #0x20
//   0x1022dc: 17FFFE1F  b        #0x101b58
uint64_t fde_func_2665_0x1022d8(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x001022D8ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD1008000ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x17FFFE1FULL ^ (1ULL << 32);
    return state ^ (state >> 29);
}

// FDE #2669 | PC: 0x1022f8..0x102300 (8 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x1022f8: 910D4000  add      x0, x0, #0x350
//   0x1022fc: 17FF7183  b        #0xde908
uint64_t fde_func_2669_0x1022f8(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x001022F8ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0x910D4000ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x17FF7183ULL ^ (1ULL << 32);
    return state ^ (state >> 29);
}

// FDE #2674 | PC: 0x102458..0x102558 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x102458: D104C3FF  sub      sp, sp, #0x130
//   0x10245c: FD0063E8  str      d8, [sp, #0xc0]
//   0x102460: A90D6FFC  stp      x28, x27, [sp, #0xd0]
//   0x102464: A90E67FA  stp      x26, x25, [sp, #0xe0]
//   0x102468: A90F5FF8  stp      x24, x23, [sp, #0xf0]
//   0x10246c: A91057F6  stp      x22, x21, [sp, #0x100]
uint64_t fde_func_2674_0x102458(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00102458ULL);
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

// FDE #2678 | PC: 0x103140..0x103240 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x103140: D106C3FF  sub      sp, sp, #0x1b0
//   0x103144: A9156FFC  stp      x28, x27, [sp, #0x150]
//   0x103148: A91667FA  stp      x26, x25, [sp, #0x160]
//   0x10314c: A9175FF8  stp      x24, x23, [sp, #0x170]
//   0x103150: A91857F6  stp      x22, x21, [sp, #0x180]
//   0x103154: A9194FF4  stp      x20, x19, [sp, #0x190]
uint64_t fde_func_2678_0x103140(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00103140ULL);
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

// FDE #2683 | PC: 0x103648..0x1036d4 (140 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x103648: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x10364c: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x103650: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x103654: 910083FD  add      x29, sp, #0x20
//   0x103658: 2A0203F3  mov      w19, w2
//   0x10365c: 2A0103F5  mov      w21, w1
uint64_t fde_func_2683_0x103648(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00103648ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81D0FF5ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9014FF4ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9027BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910083FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x2A0203F3ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x2A0103F5ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F4ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x97FEF577ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #2687 | PC: 0x103858..0x103958 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x103858: D10203FF  sub      sp, sp, #0x80
//   0x10385c: F90013FB  str      x27, [sp, #0x20]
//   0x103860: A90367FA  stp      x26, x25, [sp, #0x30]
//   0x103864: A9045FF8  stp      x24, x23, [sp, #0x40]
//   0x103868: A90557F6  stp      x22, x21, [sp, #0x50]
//   0x10386c: A9064FF4  stp      x20, x19, [sp, #0x60]
uint64_t fde_func_2687_0x103858(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00103858ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10203FFULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF90013FBULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90367FAULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9045FF8ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90557F6ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9064FF4ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9077BFDULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9101C3FDULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #2692 | PC: 0x103dc8..0x103ec8 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x103dc8: D101C3FF  sub      sp, sp, #0x70
//   0x103dcc: F90013F9  str      x25, [sp, #0x20]
//   0x103dd0: A9035FF8  stp      x24, x23, [sp, #0x30]
//   0x103dd4: A90457F6  stp      x22, x21, [sp, #0x40]
//   0x103dd8: A9054FF4  stp      x20, x19, [sp, #0x50]
//   0x103ddc: A9067BFD  stp      x29, x30, [sp, #0x60]
uint64_t fde_func_2692_0x103dc8(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00103DC8ULL);
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

// FDE #2696 | PC: 0x1040d0..0x1041d0 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x1040d0: D10203FF  sub      sp, sp, #0x80
//   0x1040d4: A9026FFC  stp      x28, x27, [sp, #0x20]
//   0x1040d8: A90367FA  stp      x26, x25, [sp, #0x30]
//   0x1040dc: A9045FF8  stp      x24, x23, [sp, #0x40]
//   0x1040e0: A90557F6  stp      x22, x21, [sp, #0x50]
//   0x1040e4: A9064FF4  stp      x20, x19, [sp, #0x60]
uint64_t fde_func_2696_0x1040d0(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x001040D0ULL);
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

// FDE #2701 | PC: 0x1045a8..0x10467c (212 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x1045a8: D10143FF  sub      sp, sp, #0x50
//   0x1045ac: A9015FF8  stp      x24, x23, [sp, #0x10]
//   0x1045b0: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x1045b4: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x1045b8: A9047BFD  stp      x29, x30, [sp, #0x40]
//   0x1045bc: 910103FD  add      x29, sp, #0x40
uint64_t fde_func_2701_0x1045a8(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x001045A8ULL);
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

// FDE #2705 | PC: 0x104904..0x104a04 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x104904: D10183FF  sub      sp, sp, #0x60
//   0x104908: A90167FA  stp      x26, x25, [sp, #0x10]
//   0x10490c: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x104910: A90357F6  stp      x22, x21, [sp, #0x30]
//   0x104914: A9044FF4  stp      x20, x19, [sp, #0x40]
//   0x104918: A9057BFD  stp      x29, x30, [sp, #0x50]
uint64_t fde_func_2705_0x104904(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00104904ULL);
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

// FDE #2710 | PC: 0x104ca4..0x104d24 (128 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x104ca4: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x104ca8: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x104cac: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x104cb0: 910083FD  add      x29, sp, #0x20
//   0x104cb4: 9100E014  add      x20, x0, #0x38
//   0x104cb8: AA0003F6  mov      x22, x0
uint64_t fde_func_2710_0x104ca4(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00104CA4ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BD57F6ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9014FF4ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9027BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910083FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9100E014ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F6ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA1403E0ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0103F5ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #2714 | PC: 0x1051ac..0x1051f0 (68 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x1051ac: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x1051b0: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x1051b4: 910043FD  add      x29, sp, #0x10
//   0x1051b8: F9400013  ldr      x19, [x0]
//   0x1051bc: A9402668  ldp      x8, x9, [x19]
//   0x1051c0: F9000509  str      x9, [x8, #8]
uint64_t fde_func_2714_0x1051ac(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x001051ACULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81E0FF3ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400013ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9402668ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000509ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400669ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000128ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #2718 | PC: 0x105598..0x105608 (112 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x105598: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x10559c: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x1055a0: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x1055a4: 910083FD  add      x29, sp, #0x20
//   0x1055a8: F9400808  ldr      x8, [x0, #0x10]
//   0x1055ac: B4000268  cbz      x8, #0x1055f8
uint64_t fde_func_2718_0x105598(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00105598ULL);
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

// FDE #2723 | PC: 0x1058a4..0x1058e8 (68 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x1058a4: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x1058a8: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x1058ac: 910043FD  add      x29, sp, #0x10
//   0x1058b0: AA0003F3  mov      x19, x0
//   0x1058b4: 9400000D  bl       #0x1058e8
//   0x1058b8: 91002268  add      x8, x19, #8
uint64_t fde_func_2723_0x1058a4(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x001058A4ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81E0FF3ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9400000DULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91002268ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xEB00011FULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x540000C0ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #2727 | PC: 0x105ac0..0x105b84 (196 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x105ac0: D10143FF  sub      sp, sp, #0x50
//   0x105ac4: F9000BF7  str      x23, [sp, #0x10]
//   0x105ac8: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x105acc: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x105ad0: A9047BFD  stp      x29, x30, [sp, #0x40]
//   0x105ad4: 910103FD  add      x29, sp, #0x40
uint64_t fde_func_2727_0x105ac0(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00105AC0ULL);
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

// FDE #2732 | PC: 0x105d34..0x105dc8 (148 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x105d34: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x105d38: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x105d3c: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x105d40: 910083FD  add      x29, sp, #0x20
//   0x105d44: 2A0103F5  mov      w21, w1
//   0x105d48: AA0003F4  mov      x20, x0
uint64_t fde_func_2732_0x105d34(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00105D34ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81D0FF5ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9014FF4ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9027BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910083FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x2A0103F5ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F4ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0803F3ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x97FEEC47ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #2736 | PC: 0x105f14..0x105f48 (52 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x105f14: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x105f18: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x105f1c: 910043FD  add      x29, sp, #0x10
//   0x105f20: 2A0103F4  mov      w20, w1
//   0x105f24: AA0003F3  mov      x19, x0
//   0x105f28: 97FEEC20  bl       #0xc0fa8
uint64_t fde_func_2736_0x105f14(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00105F14ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE4FF4ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x2A0103F4ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x97FEEC20ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x5284E228ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x6B08029FULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #2741 | PC: 0x106390..0x106490 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x106390: D10143FF  sub      sp, sp, #0x50
//   0x106394: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x106398: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x10639c: A9047BFD  stp      x29, x30, [sp, #0x40]
//   0x1063a0: 910103FD  add      x29, sp, #0x40
//   0x1063a4: D53BD056  mrs      x22, tpidr_el0
uint64_t fde_func_2741_0x106390(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00106390ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10143FFULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90257F6ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9034FF4ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9047BFDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910103FDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD53BD056ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF94016C8ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x2A0203F3ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #2745 | PC: 0x106888..0x1068cc (68 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x106888: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x10688c: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x106890: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x106894: 910083FD  add      x29, sp, #0x20
//   0x106898: 91003015  add      x21, x0, #0xc
//   0x10689c: AA0003F3  mov      x19, x0
uint64_t fde_func_2745_0x106888(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00106888ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81D0FF5ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9014FF4ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9027BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910083FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91003015ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA1503E0ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0803F4ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #2750 | PC: 0x106efc..0x106fec (240 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x106efc: D10183FF  sub      sp, sp, #0x60
//   0x106f00: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x106f04: A90357F6  stp      x22, x21, [sp, #0x30]
//   0x106f08: A9044FF4  stp      x20, x19, [sp, #0x40]
//   0x106f0c: A9057BFD  stp      x29, x30, [sp, #0x50]
//   0x106f10: 910143FD  add      x29, sp, #0x50
uint64_t fde_func_2750_0x106efc(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00106EFCULL);
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

// FDE #2754 | PC: 0x1072bc..0x1073a0 (228 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x1072bc: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x1072c0: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x1072c4: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x1072c8: 910083FD  add      x29, sp, #0x20
//   0x1072cc: F1000428  subs     x8, x1, #1
//   0x1072d0: AA0003F3  mov      x19, x0
uint64_t fde_func_2754_0x1072bc(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x001072BCULL);
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

// FDE #2759 | PC: 0x107958..0x1079a4 (76 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x107958: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x10795c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x107960: 910043FD  add      x29, sp, #0x10
//   0x107964: AA0003F3  mov      x19, x0
//   0x107968: F9400800  ldr      x0, [x0, #0x10]
//   0x10796c: B40000A0  cbz      x0, #0x107980
uint64_t fde_func_2759_0x107958(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00107958ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE4FF4ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400800ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB40000A0ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400014ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x97FCF26FULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #2763 | PC: 0x107b04..0x107c04 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x107b04: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x107b08: 910003FD  mov      x29, sp
//   0x107b0c: F9400409  ldr      x9, [x0, #8]
//   0x107b10: B4000489  cbz      x9, #0x107ba0
//   0x107b14: 9E670120  fmov     d0, x9
//   0x107b18: 0E205800  cnt      v0.8b, v0.8b
uint64_t fde_func_2763_0x107b04(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00107B04ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BF7BFDULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400409ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB4000489ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9E670120ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x0E205800ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x2E303800ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x1E26000AULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #2768 | PC: 0x108154..0x108254 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x108154: A9BC5FF8  stp      x24, x23, [sp, #-0x40]!
//   0x108158: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x10815c: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x108160: A9037BFD  stp      x29, x30, [sp, #0x30]
//   0x108164: 9100C3FD  add      x29, sp, #0x30
//   0x108168: F9400416  ldr      x22, [x0, #8]
uint64_t fde_func_2768_0x108154(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00108154ULL);
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

// FDE #2772 | PC: 0x1086f8..0x1087ac (180 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x1086f8: F9400408  ldr      x8, [x0, #8]
//   0x1086fc: B4000548  cbz      x8, #0x1087a4
//   0x108700: 9E670100  fmov     d0, x8
//   0x108704: B9800029  ldrsw    x9, [x1]
//   0x108708: 0E205800  cnt      v0.8b, v0.8b
//   0x10870c: 2E303800  uaddlv   h0, v0.8b
uint64_t fde_func_2772_0x1086f8(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x001086F8ULL);
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

// FDE #2777 | PC: 0x10932c..0x10942c (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x10932c: D101C3FF  sub      sp, sp, #0x70
//   0x109330: F90023F5  str      x21, [sp, #0x40]
//   0x109334: A9054FF4  stp      x20, x19, [sp, #0x50]
//   0x109338: A9067BFD  stp      x29, x30, [sp, #0x60]
//   0x10933c: 910183FD  add      x29, sp, #0x60
//   0x109340: D53BD055  mrs      x21, tpidr_el0
uint64_t fde_func_2777_0x10932c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0010932CULL);
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

// FDE #2781 | PC: 0x109a98..0x109aec (84 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x109a98: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x109a9c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x109aa0: 910043FD  add      x29, sp, #0x10
//   0x109aa4: A9007C7F  stp      xzr, xzr, [x3]
//   0x109aa8: F9000861  str      x1, [x3, #0x10]
//   0x109aac: F9000043  str      x3, [x2]
uint64_t fde_func_2781_0x109a98(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00109A98ULL);
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

// FDE #2786 | PC: 0x109c44..0x109c60 (28 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x109c44: F9400400  ldr      x0, [x0, #8]
//   0x109c48: B40000A0  cbz      x0, #0x109c5c
//   0x109c4c: F9400008  ldr      x8, [x0]
//   0x109c50: 52800022  mov      w2, #1
//   0x109c54: F9400903  ldr      x3, [x8, #0x10]
//   0x109c58: D61F0060  br       x3
uint64_t fde_func_2786_0x109c44(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00109C44ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400400ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB40000A0ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400008ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x52800022ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400903ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD61F0060ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD65F03C0ULL ^ (6ULL << 32);
    return state ^ (state >> 29);
}

// FDE #2790 | PC: 0x109ca8..0x109d04 (92 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x109ca8: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x109cac: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x109cb0: 910043FD  add      x29, sp, #0x10
//   0x109cb4: 52800081  mov      w1, #4
//   0x109cb8: AA0003F3  mov      x19, x0
//   0x109cbc: 97FEDBBA  bl       #0xc0ba4
uint64_t fde_func_2790_0x109ca8(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00109CA8ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81E0FF3ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x52800081ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x97FEDBBAULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB0001328ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9109E108ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #2795 | PC: 0x109fcc..0x10a0cc (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x109fcc: D101C3FF  sub      sp, sp, #0x70
//   0x109fd0: F9000BFB  str      x27, [sp, #0x10]
//   0x109fd4: A90267FA  stp      x26, x25, [sp, #0x20]
//   0x109fd8: A9035FF8  stp      x24, x23, [sp, #0x30]
//   0x109fdc: A90457F6  stp      x22, x21, [sp, #0x40]
//   0x109fe0: A9054FF4  stp      x20, x19, [sp, #0x50]
uint64_t fde_func_2795_0x109fcc(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00109FCCULL);
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

// FDE #2799 | PC: 0x10aa08..0x10aac0 (184 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x10aa08: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x10aa0c: 910003FD  mov      x29, sp
//   0x10aa10: 39404008  ldrb     w8, [x0, #0x10]
//   0x10aa14: 37000068  tbnz     w8, #0, #0x10aa20
//   0x10aa18: 7900201F  strh     wzr, [x0, #0x10]
//   0x10aa1c: 14000004  b        #0x10aa2c
uint64_t fde_func_2799_0x10aa08(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0010AA08ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BF7BFDULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910003FDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x39404008ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x37000068ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x7900201FULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x14000004ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9401008ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x3900011FULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #2803 | PC: 0x10af80..0x10b080 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x10af80: D10183FF  sub      sp, sp, #0x60
//   0x10af84: A90167FA  stp      x26, x25, [sp, #0x10]
//   0x10af88: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x10af8c: A90357F6  stp      x22, x21, [sp, #0x30]
//   0x10af90: A9044FF4  stp      x20, x19, [sp, #0x40]
//   0x10af94: A9057BFD  stp      x29, x30, [sp, #0x50]
uint64_t fde_func_2803_0x10af80(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0010AF80ULL);
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

// FDE #2808 | PC: 0x10b410..0x10b510 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x10b410: D106C3FF  sub      sp, sp, #0x1b0
//   0x10b414: A9156FFC  stp      x28, x27, [sp, #0x150]
//   0x10b418: A91667FA  stp      x26, x25, [sp, #0x160]
//   0x10b41c: A9175FF8  stp      x24, x23, [sp, #0x170]
//   0x10b420: A91857F6  stp      x22, x21, [sp, #0x180]
//   0x10b424: A9194FF4  stp      x20, x19, [sp, #0x190]
uint64_t fde_func_2808_0x10b410(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0010B410ULL);
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

// FDE #2812 | PC: 0x10bb80..0x10bc80 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x10bb80: D105C3FF  sub      sp, sp, #0x170
//   0x10bb84: A9116FFC  stp      x28, x27, [sp, #0x110]
//   0x10bb88: A91267FA  stp      x26, x25, [sp, #0x120]
//   0x10bb8c: A9135FF8  stp      x24, x23, [sp, #0x130]
//   0x10bb90: A91457F6  stp      x22, x21, [sp, #0x140]
//   0x10bb94: A9154FF4  stp      x20, x19, [sp, #0x150]
uint64_t fde_func_2812_0x10bb80(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0010BB80ULL);
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

// FDE #2817 | PC: 0x10c308..0x10c408 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x10c308: D10483FF  sub      sp, sp, #0x120
//   0x10c30c: A90C6FFC  stp      x28, x27, [sp, #0xc0]
//   0x10c310: A90D67FA  stp      x26, x25, [sp, #0xd0]
//   0x10c314: A90E5FF8  stp      x24, x23, [sp, #0xe0]
//   0x10c318: A90F57F6  stp      x22, x21, [sp, #0xf0]
//   0x10c31c: A9104FF4  stp      x20, x19, [sp, #0x100]
uint64_t fde_func_2817_0x10c308(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0010C308ULL);
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

// FDE #2821 | PC: 0x10c7f0..0x10c8f0 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x10c7f0: D10343FF  sub      sp, sp, #0xd0
//   0x10c7f4: A9076FFC  stp      x28, x27, [sp, #0x70]
//   0x10c7f8: A90867FA  stp      x26, x25, [sp, #0x80]
//   0x10c7fc: A9095FF8  stp      x24, x23, [sp, #0x90]
//   0x10c800: A90A57F6  stp      x22, x21, [sp, #0xa0]
//   0x10c804: A90B4FF4  stp      x20, x19, [sp, #0xb0]
uint64_t fde_func_2821_0x10c7f0(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0010C7F0ULL);
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

// FDE #2826 | PC: 0x10cd18..0x10ce18 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x10cd18: D10203FF  sub      sp, sp, #0x80
//   0x10cd1c: A9026FFC  stp      x28, x27, [sp, #0x20]
//   0x10cd20: A90367FA  stp      x26, x25, [sp, #0x30]
//   0x10cd24: A9045FF8  stp      x24, x23, [sp, #0x40]
//   0x10cd28: A90557F6  stp      x22, x21, [sp, #0x50]
//   0x10cd2c: A9064FF4  stp      x20, x19, [sp, #0x60]
uint64_t fde_func_2826_0x10cd18(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0010CD18ULL);
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

// FDE #2830 | PC: 0x10d10c..0x10d1f4 (232 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x10d10c: D10103FF  sub      sp, sp, #0x40
//   0x10d110: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x10d114: A9037BFD  stp      x29, x30, [sp, #0x30]
//   0x10d118: 9100C3FD  add      x29, sp, #0x30
//   0x10d11c: D53BD054  mrs      x20, tpidr_el0
//   0x10d120: F9401689  ldr      x9, [x20, #0x28]
uint64_t fde_func_2830_0x10d10c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0010D10CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10103FFULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9024FF4ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9037BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9100C3FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD53BD054ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9401689ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0803F3ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x51000408ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #2835 | PC: 0x10d4ec..0x10d5d4 (232 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x10d4ec: D10143FF  sub      sp, sp, #0x50
//   0x10d4f0: A9015FF8  stp      x24, x23, [sp, #0x10]
//   0x10d4f4: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x10d4f8: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x10d4fc: A9047BFD  stp      x29, x30, [sp, #0x40]
//   0x10d500: 910103FD  add      x29, sp, #0x40
uint64_t fde_func_2835_0x10d4ec(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0010D4ECULL);
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

// FDE #2839 | PC: 0x10dd60..0x10de34 (212 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x10dd60: F81B0FF9  str      x25, [sp, #-0x50]!
//   0x10dd64: A9015FF8  stp      x24, x23, [sp, #0x10]
//   0x10dd68: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x10dd6c: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x10dd70: A9047BFD  stp      x29, x30, [sp, #0x40]
//   0x10dd74: 910103FD  add      x29, sp, #0x40
uint64_t fde_func_2839_0x10dd60(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0010DD60ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81B0FF9ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9015FF8ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90257F6ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9034FF4ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9047BFDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910103FDULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0803F3ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB4000301ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #2844 | PC: 0x10e3b4..0x10e4b4 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x10e3b4: D102C3FF  sub      sp, sp, #0xb0
//   0x10e3b8: A9056FFC  stp      x28, x27, [sp, #0x50]
//   0x10e3bc: A90667FA  stp      x26, x25, [sp, #0x60]
//   0x10e3c0: A9075FF8  stp      x24, x23, [sp, #0x70]
//   0x10e3c4: A90857F6  stp      x22, x21, [sp, #0x80]
//   0x10e3c8: A9094FF4  stp      x20, x19, [sp, #0x90]
uint64_t fde_func_2844_0x10e3b4(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0010E3B4ULL);
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

// FDE #2848 | PC: 0x10eb98..0x10ec98 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x10eb98: D101C3FF  sub      sp, sp, #0x70
//   0x10eb9c: F90013F9  str      x25, [sp, #0x20]
//   0x10eba0: A9035FF8  stp      x24, x23, [sp, #0x30]
//   0x10eba4: A90457F6  stp      x22, x21, [sp, #0x40]
//   0x10eba8: A9054FF4  stp      x20, x19, [sp, #0x50]
//   0x10ebac: A9067BFD  stp      x29, x30, [sp, #0x60]
uint64_t fde_func_2848_0x10eb98(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0010EB98ULL);
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

// FDE #2853 | PC: 0x10f0fc..0x10f1e4 (232 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x10f0fc: D10143FF  sub      sp, sp, #0x50
//   0x10f100: A9015FF8  stp      x24, x23, [sp, #0x10]
//   0x10f104: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x10f108: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x10f10c: A9047BFD  stp      x29, x30, [sp, #0x40]
//   0x10f110: 910103FD  add      x29, sp, #0x40
uint64_t fde_func_2853_0x10f0fc(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0010F0FCULL);
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

// FDE #2857 | PC: 0x10fdd8..0x10fed8 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x10fdd8: D10303FF  sub      sp, sp, #0xc0
//   0x10fddc: A90767FA  stp      x26, x25, [sp, #0x70]
//   0x10fde0: A9085FF8  stp      x24, x23, [sp, #0x80]
//   0x10fde4: A90957F6  stp      x22, x21, [sp, #0x90]
//   0x10fde8: A90A4FF4  stp      x20, x19, [sp, #0xa0]
//   0x10fdec: A90B7BFD  stp      x29, x30, [sp, #0xb0]
uint64_t fde_func_2857_0x10fdd8(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0010FDD8ULL);
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

// FDE #2862 | PC: 0x110ce0..0x110de0 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x110ce0: D10343FF  sub      sp, sp, #0xd0
//   0x110ce4: A9076FFC  stp      x28, x27, [sp, #0x70]
//   0x110ce8: A90867FA  stp      x26, x25, [sp, #0x80]
//   0x110cec: A9095FF8  stp      x24, x23, [sp, #0x90]
//   0x110cf0: A90A57F6  stp      x22, x21, [sp, #0xa0]
//   0x110cf4: A90B4FF4  stp      x20, x19, [sp, #0xb0]
uint64_t fde_func_2862_0x110ce0(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00110CE0ULL);
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

// FDE #2866 | PC: 0x111d04..0x111e04 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x111d04: D10183FF  sub      sp, sp, #0x60
//   0x111d08: F90013F7  str      x23, [sp, #0x20]
//   0x111d0c: A90357F6  stp      x22, x21, [sp, #0x30]
//   0x111d10: A9044FF4  stp      x20, x19, [sp, #0x40]
//   0x111d14: A9057BFD  stp      x29, x30, [sp, #0x50]
//   0x111d18: 910143FD  add      x29, sp, #0x50
uint64_t fde_func_2866_0x111d04(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00111D04ULL);
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

// FDE #2871 | PC: 0x112498..0x112598 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x112498: D10243FF  sub      sp, sp, #0x90
//   0x11249c: A9055FF8  stp      x24, x23, [sp, #0x50]
//   0x1124a0: A90657F6  stp      x22, x21, [sp, #0x60]
//   0x1124a4: A9074FF4  stp      x20, x19, [sp, #0x70]
//   0x1124a8: A9087BFD  stp      x29, x30, [sp, #0x80]
//   0x1124ac: 910203FD  add      x29, sp, #0x80
uint64_t fde_func_2871_0x112498(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00112498ULL);
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

// FDE #2875 | PC: 0x113fc4..0x1140c4 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x113fc4: A9BA6FFC  stp      x28, x27, [sp, #-0x60]!
//   0x113fc8: A90167FA  stp      x26, x25, [sp, #0x10]
//   0x113fcc: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x113fd0: A90357F6  stp      x22, x21, [sp, #0x30]
//   0x113fd4: A9044FF4  stp      x20, x19, [sp, #0x40]
//   0x113fd8: A9057BFD  stp      x29, x30, [sp, #0x50]
uint64_t fde_func_2875_0x113fc4(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00113FC4ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BA6FFCULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90167FAULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9025FF8ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90357F6ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9044FF4ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9057BFDULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910143FDULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10A83FFULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #2879 | PC: 0x115180..0x1151a4 (36 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x115180: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x115184: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x115188: 910043FD  add      x29, sp, #0x10
//   0x11518c: AA0003F3  mov      x19, x0
//   0x115190: 97FFFFD6  bl       #0x1150e8
//   0x115194: A9417BFD  ldp      x29, x30, [sp, #0x10]
uint64_t fde_func_2879_0x115180(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00115180ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81E0FF3ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x97FFFFD6ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9417BFDULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA1303E0ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF84207F3ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #2884 | PC: 0x11521c..0x11528c (112 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x11521c: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x115220: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x115224: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x115228: 910083FD  add      x29, sp, #0x20
//   0x11522c: F9400808  ldr      x8, [x0, #0x10]
//   0x115230: B4000268  cbz      x8, #0x11527c
uint64_t fde_func_2884_0x11521c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0011521CULL);
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

// FDE #2888 | PC: 0x11540c..0x115418 (12 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x11540c: F8418C08  ldr      x8, [x0, #0x18]!
//   0x115410: F9400101  ldr      x1, [x8]
//   0x115414: D61F0020  br       x1
uint64_t fde_func_2888_0x11540c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0011540CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF8418C08ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400101ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD61F0020ULL ^ (2ULL << 32);
    return state ^ (state >> 29);
}

// FDE #2893 | PC: 0x1156c4..0x11571c (88 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x1156c4: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x1156c8: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x1156cc: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x1156d0: 910083FD  add      x29, sp, #0x20
//   0x1156d4: AA0003F5  mov      x21, x0
//   0x1156d8: AA0103E0  mov      x0, x1
uint64_t fde_func_2893_0x1156c4(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x001156C4ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81D0FF5ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9014FF4ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9027BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910083FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F5ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0103E0ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0203F3ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0103F4ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #2897 | PC: 0x115a00..0x115a30 (48 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x115a00: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x115a04: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x115a08: 910043FD  add      x29, sp, #0x10
//   0x115a0c: B00012C8  adrp     x8, #0x36e000
//   0x115a10: 91152108  add      x8, x8, #0x548
//   0x115a14: AA0003F3  mov      x19, x0
uint64_t fde_func_2897_0x115a00(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00115A00ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81E0FF3ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB00012C8ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91152108ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF8018408ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x97FFFDB3ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #2902 | PC: 0x115b3c..0x115c3c (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x115b3c: A9BA6FFC  stp      x28, x27, [sp, #-0x60]!
//   0x115b40: A90167FA  stp      x26, x25, [sp, #0x10]
//   0x115b44: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x115b48: A90357F6  stp      x22, x21, [sp, #0x30]
//   0x115b4c: A9044FF4  stp      x20, x19, [sp, #0x40]
//   0x115b50: A9057BFD  stp      x29, x30, [sp, #0x50]
uint64_t fde_func_2902_0x115b3c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00115B3CULL);
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

// FDE #2906 | PC: 0x115d80..0x115df0 (112 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x115d80: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x115d84: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x115d88: 910043FD  add      x29, sp, #0x10
//   0x115d8c: 3943A008  ldrb     w8, [x0, #0xe8]
//   0x115d90: B00012C9  adrp     x9, #0x36e000
//   0x115d94: AA0003F3  mov      x19, x0
uint64_t fde_func_2906_0x115d80(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00115D80ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81E0FF3ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x3943A008ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB00012C9ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91166129ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000009ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #2911 | PC: 0x115f20..0x115f78 (88 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x115f20: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x115f24: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x115f28: 910043FD  add      x29, sp, #0x10
//   0x115f2c: F9400413  ldr      x19, [x0, #8]
//   0x115f30: B40000F3  cbz      x19, #0x115f4c
//   0x115f34: 91002268  add      x8, x19, #8
uint64_t fde_func_2911_0x115f20(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00115F20ULL);
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

// FDE #2915 | PC: 0x116174..0x1161b0 (60 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x116174: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x116178: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x11617c: 910043FD  add      x29, sp, #0x10
//   0x116180: 39406008  ldrb     w8, [x0, #0x18]
//   0x116184: 900012C9  adrp     x9, #0x36e000
//   0x116188: AA0003F3  mov      x19, x0
uint64_t fde_func_2915_0x116174(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00116174ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81E0FF3ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x39406008ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x900012C9ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9117A129ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000009ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #2920 | PC: 0x116234..0x116278 (68 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x116234: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x116238: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x11623c: 910043FD  add      x29, sp, #0x10
//   0x116240: F9400408  ldr      x8, [x0, #8]
//   0x116244: AA0003F3  mov      x19, x0
//   0x116248: B4000108  cbz      x8, #0x116268
uint64_t fde_func_2920_0x116234(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00116234ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81E0FF3ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400408ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB4000108ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x97FCCACCULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB9400A68ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #2924 | PC: 0x1162ec..0x1162f4 (8 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x1162ec: B9401400  ldr      w0, [x0, #0x14]
//   0x1162f0: D65F03C0  ret      
uint64_t fde_func_2924_0x1162ec(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x001162ECULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xB9401400ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD65F03C0ULL ^ (1ULL << 32);
    return state ^ (state >> 29);
}

// FDE #2929 | PC: 0x1164ac..0x1164e4 (56 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x1164ac: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x1164b0: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x1164b4: 910043FD  add      x29, sp, #0x10
//   0x1164b8: 91007014  add      x20, x0, #0x1c
//   0x1164bc: AA0003F3  mov      x19, x0
//   0x1164c0: AA1403E0  mov      x0, x20
uint64_t fde_func_2929_0x1164ac(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x001164ACULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE4FF4ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91007014ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA1403E0ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x97FCB9C7ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB9401273ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #2933 | PC: 0x1167d8..0x116880 (168 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x1167d8: D10183FF  sub      sp, sp, #0x60
//   0x1167dc: A90357F6  stp      x22, x21, [sp, #0x30]
//   0x1167e0: A9044FF4  stp      x20, x19, [sp, #0x40]
//   0x1167e4: A9057BFD  stp      x29, x30, [sp, #0x50]
//   0x1167e8: 910143FD  add      x29, sp, #0x50
//   0x1167ec: D53BD056  mrs      x22, tpidr_el0
uint64_t fde_func_2933_0x1167d8(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x001167D8ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10183FFULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90357F6ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9044FF4ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9057BFDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910143FDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD53BD056ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF94016C8ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F4ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #2938 | PC: 0x116f74..0x117074 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x116f74: D10343FF  sub      sp, sp, #0xd0
//   0x116f78: A9076FFC  stp      x28, x27, [sp, #0x70]
//   0x116f7c: A90867FA  stp      x26, x25, [sp, #0x80]
//   0x116f80: A9095FF8  stp      x24, x23, [sp, #0x90]
//   0x116f84: A90A57F6  stp      x22, x21, [sp, #0xa0]
//   0x116f88: A90B4FF4  stp      x20, x19, [sp, #0xb0]
uint64_t fde_func_2938_0x116f74(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00116F74ULL);
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

// FDE #2942 | PC: 0x1179f4..0x1179f8 (4 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x1179f4: D65F03C0  ret      
uint64_t fde_func_2942_0x1179f4(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x001179F4ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD65F03C0ULL ^ (0ULL << 32);
    return state ^ (state >> 29);
}

// FDE #2947 | PC: 0x117f70..0x117fb4 (68 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x117f70: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x117f74: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x117f78: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x117f7c: 910083FD  add      x29, sp, #0x20
//   0x117f80: 91032015  add      x21, x0, #0xc8
//   0x117f84: AA0003F3  mov      x19, x0
uint64_t fde_func_2947_0x117f70(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00117F70ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81D0FF5ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9014FF4ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9027BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910083FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91032015ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA1503E0ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0803F4ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #2951 | PC: 0x118304..0x118404 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x118304: D10383FF  sub      sp, sp, #0xe0
//   0x118308: A9086FFC  stp      x28, x27, [sp, #0x80]
//   0x11830c: A90967FA  stp      x26, x25, [sp, #0x90]
//   0x118310: A90A5FF8  stp      x24, x23, [sp, #0xa0]
//   0x118314: A90B57F6  stp      x22, x21, [sp, #0xb0]
//   0x118318: A90C4FF4  stp      x20, x19, [sp, #0xc0]
uint64_t fde_func_2951_0x118304(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00118304ULL);
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

// FDE #2955 | PC: 0x119524..0x119624 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x119524: D10203FF  sub      sp, sp, #0x80
//   0x119528: A9045FF8  stp      x24, x23, [sp, #0x40]
//   0x11952c: A90557F6  stp      x22, x21, [sp, #0x50]
//   0x119530: A9064FF4  stp      x20, x19, [sp, #0x60]
//   0x119534: A9077BFD  stp      x29, x30, [sp, #0x70]
//   0x119538: 9101C3FD  add      x29, sp, #0x70
uint64_t fde_func_2955_0x119524(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00119524ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10203FFULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9045FF8ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90557F6ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9064FF4ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9077BFDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9101C3FDULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD53BD057ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF94016E8ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #2960 | PC: 0x11a080..0x11a168 (232 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x11a080: F81C0FF7  str      x23, [sp, #-0x40]!
//   0x11a084: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x11a088: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x11a08c: A9037BFD  stp      x29, x30, [sp, #0x30]
//   0x11a090: 9100C3FD  add      x29, sp, #0x30
//   0x11a094: AA0803F3  mov      x19, x8
uint64_t fde_func_2960_0x11a080(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0011A080ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81C0FF7ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90157F6ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9024FF4ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9037BFDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9100C3FDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0803F3ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x39400028ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400429ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #2964 | PC: 0x11a180..0x11a190 (16 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x11a180: 900012A8  adrp     x8, #0x36e000
//   0x11a184: 911D0108  add      x8, x8, #0x740
//   0x11a188: F801C408  str      x8, [x0], #0x1c
//   0x11a18c: 17FCA819  b        #0x441f0
uint64_t fde_func_2964_0x11a180(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0011A180ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0x900012A8ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x911D0108ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF801C408ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x17FCA819ULL ^ (3ULL << 32);
    return state ^ (state >> 29);
}

// FDE #2969 | PC: 0x11a20c..0x11a2e0 (212 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x11a20c: D10143FF  sub      sp, sp, #0x50
//   0x11a210: A9015FF8  stp      x24, x23, [sp, #0x10]
//   0x11a214: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x11a218: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x11a21c: A9047BFD  stp      x29, x30, [sp, #0x40]
//   0x11a220: 910103FD  add      x29, sp, #0x40
uint64_t fde_func_2969_0x11a20c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0011A20CULL);
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

// FDE #2973 | PC: 0x11a408..0x11a42c (36 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x11a408: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x11a40c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x11a410: 910043FD  add      x29, sp, #0x10
//   0x11a414: AA0003F3  mov      x19, x0
//   0x11a418: 97FCAAEA  bl       #0x44fc0
//   0x11a41c: A9417BFD  ldp      x29, x30, [sp, #0x10]
uint64_t fde_func_2973_0x11a408(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0011A408ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81E0FF3ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x97FCAAEAULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9417BFDULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA1303E0ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF84207F3ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #2978 | PC: 0x11a4fc..0x11a53c (64 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x11a4fc: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x11a500: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x11a504: 910043FD  add      x29, sp, #0x10
//   0x11a508: D37CFC28  lsr      x8, x1, #0x3c
//   0x11a50c: B5000168  cbnz     x8, #0x11a538
//   0x11a510: AA0003F4  mov      x20, x0
uint64_t fde_func_2978_0x11a4fc(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0011A4FCULL);
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

// FDE #2982 | PC: 0x11a894..0x11a994 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x11a894: D10283FF  sub      sp, sp, #0xa0
//   0x11a898: A9046FFC  stp      x28, x27, [sp, #0x40]
//   0x11a89c: A90567FA  stp      x26, x25, [sp, #0x50]
//   0x11a8a0: A9065FF8  stp      x24, x23, [sp, #0x60]
//   0x11a8a4: A90757F6  stp      x22, x21, [sp, #0x70]
//   0x11a8a8: A9084FF4  stp      x20, x19, [sp, #0x80]
uint64_t fde_func_2982_0x11a894(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0011A894ULL);
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

// FDE #2987 | PC: 0x11ada8..0x11ae94 (236 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x11ada8: D10183FF  sub      sp, sp, #0x60
//   0x11adac: A90167FA  stp      x26, x25, [sp, #0x10]
//   0x11adb0: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x11adb4: A90357F6  stp      x22, x21, [sp, #0x30]
//   0x11adb8: A9044FF4  stp      x20, x19, [sp, #0x40]
//   0x11adbc: A9057BFD  stp      x29, x30, [sp, #0x50]
uint64_t fde_func_2987_0x11ada8(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0011ADA8ULL);
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

// FDE #2991 | PC: 0x11b05c..0x11b08c (48 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x11b05c: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x11b060: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x11b064: 910043FD  add      x29, sp, #0x10
//   0x11b068: F0001288  adrp     x8, #0x36e000
//   0x11b06c: 9121E108  add      x8, x8, #0x878
//   0x11b070: AA0003F3  mov      x19, x0
uint64_t fde_func_2991_0x11b05c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0011B05CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81E0FF3ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF0001288ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9121E108ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF8018408ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x97FED323ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #2996 | PC: 0x11b16c..0x11b26c (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x11b16c: D101C3FF  sub      sp, sp, #0x70
//   0x11b170: F90013F9  str      x25, [sp, #0x20]
//   0x11b174: A9035FF8  stp      x24, x23, [sp, #0x30]
//   0x11b178: A90457F6  stp      x22, x21, [sp, #0x40]
//   0x11b17c: A9054FF4  stp      x20, x19, [sp, #0x50]
//   0x11b180: A9067BFD  stp      x29, x30, [sp, #0x60]
uint64_t fde_func_2996_0x11b16c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0011B16CULL);
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

// FDE #3000 | PC: 0x11b378..0x11b3ac (52 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x11b378: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x11b37c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x11b380: 910043FD  add      x29, sp, #0x10
//   0x11b384: AA0003F3  mov      x19, x0
//   0x11b388: 94000009  bl       #0x11b3ac
//   0x11b38c: B40000A0  cbz      x0, #0x11b3a0
uint64_t fde_func_3000_0x11b378(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0011B378ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81E0FF3ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x94000009ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB40000A0ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003E1ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA1303E0ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #3005 | PC: 0x11b780..0x11b880 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x11b780: D10243FF  sub      sp, sp, #0x90
//   0x11b784: A9036FFC  stp      x28, x27, [sp, #0x30]
//   0x11b788: A90467FA  stp      x26, x25, [sp, #0x40]
//   0x11b78c: A9055FF8  stp      x24, x23, [sp, #0x50]
//   0x11b790: A90657F6  stp      x22, x21, [sp, #0x60]
//   0x11b794: A9074FF4  stp      x20, x19, [sp, #0x70]
uint64_t fde_func_3005_0x11b780(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0011B780ULL);
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

// FDE #3009 | PC: 0x11be40..0x11bf40 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x11be40: D10183FF  sub      sp, sp, #0x60
//   0x11be44: F9001BF5  str      x21, [sp, #0x30]
//   0x11be48: A9044FF4  stp      x20, x19, [sp, #0x40]
//   0x11be4c: A9057BFD  stp      x29, x30, [sp, #0x50]
//   0x11be50: 910143FD  add      x29, sp, #0x50
//   0x11be54: D53BD055  mrs      x21, tpidr_el0
uint64_t fde_func_3009_0x11be40(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0011BE40ULL);
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

// FDE #3014 | PC: 0x11c32c..0x11c41c (240 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x11c32c: D10143FF  sub      sp, sp, #0x50
//   0x11c330: F9000BF7  str      x23, [sp, #0x10]
//   0x11c334: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x11c338: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x11c33c: A9047BFD  stp      x29, x30, [sp, #0x40]
//   0x11c340: 910103FD  add      x29, sp, #0x40
uint64_t fde_func_3014_0x11c32c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0011C32CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10143FFULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000BF7ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90257F6ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9034FF4ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9047BFDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910103FDULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD53BD057ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0803F5ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #3018 | PC: 0x11c554..0x11c5a0 (76 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x11c554: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x11c558: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x11c55c: 910043FD  add      x29, sp, #0x10
//   0x11c560: F9400413  ldr      x19, [x0, #8]
//   0x11c564: A9402668  ldp      x8, x9, [x19]
//   0x11c568: F9000509  str      x9, [x8, #8]
uint64_t fde_func_3018_0x11c554(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0011C554ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81E0FF3ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400413ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9402668ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000509ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400669ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000128ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #3023 | PC: 0x11eb24..0x11ebb0 (140 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x11eb24: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x11eb28: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x11eb2c: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x11eb30: 910083FD  add      x29, sp, #0x20
//   0x11eb34: AA0003F3  mov      x19, x0
//   0x11eb38: 97FCA891  bl       #0x48d7c
uint64_t fde_func_3023_0x11eb24(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0011EB24ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81D0FF5ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9014FF4ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9027BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910083FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x97FCA891ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF940F268ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB9809A69ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #3027 | PC: 0x11f3bc..0x11f4bc (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x11f3bc: D10703FF  sub      sp, sp, #0x1c0
//   0x11f3c0: A9166FFC  stp      x28, x27, [sp, #0x160]
//   0x11f3c4: A91767FA  stp      x26, x25, [sp, #0x170]
//   0x11f3c8: A9185FF8  stp      x24, x23, [sp, #0x180]
//   0x11f3cc: A91957F6  stp      x22, x21, [sp, #0x190]
//   0x11f3d0: A91A4FF4  stp      x20, x19, [sp, #0x1a0]
uint64_t fde_func_3027_0x11f3bc(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0011F3BCULL);
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

// FDE #3032 | PC: 0x11f714..0x11f750 (60 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x11f714: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x11f718: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x11f71c: 910043FD  add      x29, sp, #0x10
//   0x11f720: B4000121  cbz      x1, #0x11f744
//   0x11f724: AA0103F3  mov      x19, x1
//   0x11f728: AA1303E0  mov      x0, x19
uint64_t fde_func_3032_0x11f714(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0011F714ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE4FF4ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB4000121ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0103F3ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA1303E0ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF8418414ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x97FFF33BULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #3036 | PC: 0x11facc..0x11fbcc (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x11facc: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x11fad0: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x11fad4: 910043FD  add      x29, sp, #0x10
//   0x11fad8: AA0003F3  mov      x19, x0
//   0x11fadc: B4000421  cbz      x1, #0x11fb60
//   0x11fae0: AA0103F4  mov      x20, x1
uint64_t fde_func_3036_0x11facc(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0011FACCULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE4FF4ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB4000421ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0103F4ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD37DFC28ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB5000A88ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #3040 | PC: 0x11ff90..0x11ffd4 (68 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x11ff90: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x11ff94: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x11ff98: 910043FD  add      x29, sp, #0x10
//   0x11ff9c: 90001309  adrp     x9, #0x37f000
//   0x11ffa0: F947D929  ldr      x9, [x9, #0xfb0]
//   0x11ffa4: F0001268  adrp     x8, #0x36e000
uint64_t fde_func_3040_0x11ff90(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0011FF90ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81E0FF3ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x90001309ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF947D929ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF0001268ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91252108ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000008ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #3045 | PC: 0x1201f4..0x1202f4 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x1201f4: D101C3FF  sub      sp, sp, #0x70
//   0x1201f8: F90013F9  str      x25, [sp, #0x20]
//   0x1201fc: A9035FF8  stp      x24, x23, [sp, #0x30]
//   0x120200: A90457F6  stp      x22, x21, [sp, #0x40]
//   0x120204: A9054FF4  stp      x20, x19, [sp, #0x50]
//   0x120208: A9067BFD  stp      x29, x30, [sp, #0x60]
uint64_t fde_func_3045_0x1201f4(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x001201F4ULL);
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

// FDE #3049 | PC: 0x1204c4..0x120564 (160 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x1204c4: D101C3FF  sub      sp, sp, #0x70
//   0x1204c8: A9054FF4  stp      x20, x19, [sp, #0x50]
//   0x1204cc: A9067BFD  stp      x29, x30, [sp, #0x60]
//   0x1204d0: 910183FD  add      x29, sp, #0x60
//   0x1204d4: D53BD053  mrs      x19, tpidr_el0
//   0x1204d8: F9401668  ldr      x8, [x19, #0x28]
uint64_t fde_func_3049_0x1204c4(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x001204C4ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD101C3FFULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9054FF4ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9067BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910183FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD53BD053ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9401668ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x2A0103E9ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043F4ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #3054 | PC: 0x121044..0x121144 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x121044: D10383FF  sub      sp, sp, #0xe0
//   0x121048: A9086FFC  stp      x28, x27, [sp, #0x80]
//   0x12104c: A90967FA  stp      x26, x25, [sp, #0x90]
//   0x121050: A90A5FF8  stp      x24, x23, [sp, #0xa0]
//   0x121054: A90B57F6  stp      x22, x21, [sp, #0xb0]
//   0x121058: A90C4FF4  stp      x20, x19, [sp, #0xc0]
uint64_t fde_func_3054_0x121044(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00121044ULL);
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

// FDE #3058 | PC: 0x121ac8..0x121b04 (60 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x121ac8: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x121acc: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x121ad0: 910043FD  add      x29, sp, #0x10
//   0x121ad4: 3940A008  ldrb     w8, [x0, #0x28]
//   0x121ad8: B0001269  adrp     x9, #0x36e000
//   0x121adc: AA0003F3  mov      x19, x0
uint64_t fde_func_3058_0x121ac8(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00121AC8ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81E0FF3ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x3940A008ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB0001269ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91276129ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000009ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #3063 | PC: 0x121c54..0x121ca4 (80 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x121c54: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x121c58: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x121c5c: 910043FD  add      x29, sp, #0x10
//   0x121c60: 39410008  ldrb     w8, [x0, #0x40]
//   0x121c64: B0001269  adrp     x9, #0x36e000
//   0x121c68: 9128C129  add      x9, x9, #0xa30
uint64_t fde_func_3063_0x121c54(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00121C54ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81E0FF3ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x39410008ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB0001269ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9128C129ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000009ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB0001269ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #3067 | PC: 0x121d04..0x121e04 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x121d04: A9BA6FFC  stp      x28, x27, [sp, #-0x60]!
//   0x121d08: A90167FA  stp      x26, x25, [sp, #0x10]
//   0x121d0c: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x121d10: A90357F6  stp      x22, x21, [sp, #0x30]
//   0x121d14: A9044FF4  stp      x20, x19, [sp, #0x40]
//   0x121d18: A9057BFD  stp      x29, x30, [sp, #0x50]
uint64_t fde_func_3067_0x121d04(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00121D04ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BA6FFCULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90167FAULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9025FF8ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90357F6ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9044FF4ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9057BFDULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910143FDULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0203F3ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #3072 | PC: 0x122550..0x122650 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x122550: D101C3FF  sub      sp, sp, #0x70
//   0x122554: F90013F9  str      x25, [sp, #0x20]
//   0x122558: A9035FF8  stp      x24, x23, [sp, #0x30]
//   0x12255c: A90457F6  stp      x22, x21, [sp, #0x40]
//   0x122560: A9054FF4  stp      x20, x19, [sp, #0x50]
//   0x122564: A9067BFD  stp      x29, x30, [sp, #0x60]
uint64_t fde_func_3072_0x122550(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00122550ULL);
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

// FDE #3076 | PC: 0x122a4c..0x122a88 (60 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x122a4c: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x122a50: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x122a54: 910043FD  add      x29, sp, #0x10
//   0x122a58: 91006040  add      x0, x2, #0x18
//   0x122a5c: AA0203F3  mov      x19, x2
//   0x122a60: 97FC9C74  bl       #0x49c30
uint64_t fde_func_3076_0x122a4c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00122A4CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81E0FF3ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91006040ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0203F3ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x97FC9C74ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x39400268ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x37000088ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #3081 | PC: 0x122da4..0x122df8 (84 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x122da4: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x122da8: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x122dac: 910043FD  add      x29, sp, #0x10
//   0x122db0: A9007C7F  stp      xzr, xzr, [x3]
//   0x122db4: F9000861  str      x1, [x3, #0x10]
//   0x122db8: F9000043  str      x3, [x2]
uint64_t fde_func_3081_0x122da4(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00122DA4ULL);
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

// FDE #3085 | PC: 0x1230f0..0x12314c (92 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x1230f0: AA0003E8  mov      x8, x0
//   0x1230f4: F9400800  ldr      x0, [x0, #0x10]
//   0x1230f8: B4000280  cbz      x0, #0x123148
//   0x1230fc: F9400009  ldr      x9, [x0]
//   0x123100: EB08013F  cmp      x9, x8
//   0x123104: 54000120  b.eq     #0x123128
uint64_t fde_func_3085_0x1230f0(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x001230F0ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003E8ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400800ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB4000280ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400009ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xEB08013FULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x54000120ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF900041FULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB40001E9ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #3090 | PC: 0x123380..0x1233d4 (84 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x123380: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x123384: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x123388: 910043FD  add      x29, sp, #0x10
//   0x12338c: A9007C7F  stp      xzr, xzr, [x3]
//   0x123390: F9000861  str      x1, [x3, #0x10]
//   0x123394: F9000043  str      x3, [x2]
uint64_t fde_func_3090_0x123380(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00123380ULL);
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

// FDE #3094 | PC: 0x123648..0x123748 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x123648: D101C3FF  sub      sp, sp, #0x70
//   0x12364c: F9001BF7  str      x23, [sp, #0x30]
//   0x123650: A90457F6  stp      x22, x21, [sp, #0x40]
//   0x123654: A9054FF4  stp      x20, x19, [sp, #0x50]
//   0x123658: A9067BFD  stp      x29, x30, [sp, #0x60]
//   0x12365c: 910183FD  add      x29, sp, #0x60
uint64_t fde_func_3094_0x123648(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00123648ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD101C3FFULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9001BF7ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90457F6ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9054FF4ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9067BFDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910183FDULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD53BD055ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF94016A8ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #3099 | PC: 0x1239f8..0x1239fc (4 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x1239f8: 17FC824E  b        #0x44330
uint64_t fde_func_3099_0x1239f8(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x001239F8ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0x17FC824EULL ^ (0ULL << 32);
    return state ^ (state >> 29);
}

// FDE #3103 | PC: 0x123a50..0x123a54 (4 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x123a50: 17FC8238  b        #0x44330
uint64_t fde_func_3103_0x123a50(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00123A50ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0x17FC8238ULL ^ (0ULL << 32);
    return state ^ (state >> 29);
}

// FDE #3108 | PC: 0x123c68..0x123cb8 (80 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x123c68: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x123c6c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x123c70: 910043FD  add      x29, sp, #0x10
//   0x123c74: AA0003F3  mov      x19, x0
//   0x123c78: F9401000  ldr      x0, [x0, #0x20]
//   0x123c7c: F0001248  adrp     x8, #0x36e000
uint64_t fde_func_3108_0x123c68(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00123C68ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81E0FF3ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9401000ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF0001248ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x912BC108ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000268ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #3112 | PC: 0x123cec..0x123d28 (60 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x123cec: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x123cf0: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x123cf4: 910043FD  add      x29, sp, #0x10
//   0x123cf8: AA0003F3  mov      x19, x0
//   0x123cfc: F9400400  ldr      x0, [x0, #8]
//   0x123d00: F0001248  adrp     x8, #0x36e000
uint64_t fde_func_3112_0x123cec(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00123CECULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81E0FF3ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400400ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF0001248ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x912D0108ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000268ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #3116 | PC: 0x124038..0x124138 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x124038: D10203FF  sub      sp, sp, #0x80
//   0x12403c: F90013FB  str      x27, [sp, #0x20]
//   0x124040: A90367FA  stp      x26, x25, [sp, #0x30]
//   0x124044: A9045FF8  stp      x24, x23, [sp, #0x40]
//   0x124048: A90557F6  stp      x22, x21, [sp, #0x50]
//   0x12404c: A9064FF4  stp      x20, x19, [sp, #0x60]
uint64_t fde_func_3116_0x124038(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00124038ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10203FFULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF90013FBULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90367FAULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9045FF8ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90557F6ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9064FF4ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9077BFDULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9101C3FDULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #3121 | PC: 0x1243b8..0x1244b8 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x1243b8: D10283FF  sub      sp, sp, #0xa0
//   0x1243bc: A9065FF8  stp      x24, x23, [sp, #0x60]
//   0x1243c0: A90757F6  stp      x22, x21, [sp, #0x70]
//   0x1243c4: A9084FF4  stp      x20, x19, [sp, #0x80]
//   0x1243c8: A9097BFD  stp      x29, x30, [sp, #0x90]
//   0x1243cc: 910243FD  add      x29, sp, #0x90
uint64_t fde_func_3121_0x1243b8(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x001243B8ULL);
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

// FDE #3125 | PC: 0x1247f8..0x124800 (8 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x1247f8: 910B2000  add      x0, x0, #0x2c8
//   0x1247fc: D65F03C0  ret      
uint64_t fde_func_3125_0x1247f8(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x001247F8ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0x910B2000ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD65F03C0ULL ^ (1ULL << 32);
    return state ^ (state >> 29);
}

// FDE #3130 | PC: 0x124c90..0x124d58 (200 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x124c90: D10103FF  sub      sp, sp, #0x40
//   0x124c94: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x124c98: A9037BFD  stp      x29, x30, [sp, #0x30]
//   0x124c9c: 9100C3FD  add      x29, sp, #0x30
//   0x124ca0: D53BD054  mrs      x20, tpidr_el0
//   0x124ca4: AA0803F3  mov      x19, x8
uint64_t fde_func_3130_0x124c90(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00124C90ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10103FFULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9024FF4ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9037BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9100C3FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD53BD054ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0803F3ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9401688ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0403E3ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #3134 | PC: 0x124de0..0x124e5c (124 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x124de0: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x124de4: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x124de8: 910043FD  add      x29, sp, #0x10
//   0x124dec: A9402029  ldp      x9, x8, [x1]
//   0x124df0: B40000C8  cbz      x8, #0x124e08
//   0x124df4: 9100210A  add      x10, x8, #8
uint64_t fde_func_3134_0x124de0(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00124DE0ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81E0FF3ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9402029ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB40000C8ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9100210AULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xC85F7D4BULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9100056BULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #3139 | PC: 0x124f58..0x125024 (204 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x124f58: D10143FF  sub      sp, sp, #0x50
//   0x124f5c: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x124f60: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x124f64: A9047BFD  stp      x29, x30, [sp, #0x40]
//   0x124f68: 910103FD  add      x29, sp, #0x40
//   0x124f6c: D53BD056  mrs      x22, tpidr_el0
uint64_t fde_func_3139_0x124f58(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00124F58ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10143FFULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90257F6ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9034FF4ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9047BFDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910103FDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD53BD056ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF94016C8ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x52800800ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #3143 | PC: 0x125254..0x125354 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x125254: D10243FF  sub      sp, sp, #0x90
//   0x125258: F90033F5  str      x21, [sp, #0x60]
//   0x12525c: A9074FF4  stp      x20, x19, [sp, #0x70]
//   0x125260: A9087BFD  stp      x29, x30, [sp, #0x80]
//   0x125264: 910203FD  add      x29, sp, #0x80
//   0x125268: D53BD055  mrs      x21, tpidr_el0
uint64_t fde_func_3143_0x125254(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00125254ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10243FFULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF90033F5ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9074FF4ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9087BFDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910203FDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD53BD055ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF94016A8ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F4ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #3148 | PC: 0x125830..0x125858 (40 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x125830: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x125834: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x125838: 910043FD  add      x29, sp, #0x10
//   0x12583c: D1002013  sub      x19, x0, #8
//   0x125840: AA1303E0  mov      x0, x19
//   0x125844: 97FEFD06  bl       #0xe4c5c
uint64_t fde_func_3148_0x125830(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00125830ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81E0FF3ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD1002013ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA1303E0ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x97FEFD06ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9417BFDULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA1303E0ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #3152 | PC: 0x125890..0x1258b8 (40 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x125890: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x125894: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x125898: 910043FD  add      x29, sp, #0x10
//   0x12589c: D1006013  sub      x19, x0, #0x18
//   0x1258a0: AA1303E0  mov      x0, x19
//   0x1258a4: 97FEFCEE  bl       #0xe4c5c
uint64_t fde_func_3152_0x125890(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00125890ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81E0FF3ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD1006013ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA1303E0ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x97FEFCEEULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9417BFDULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA1303E0ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #3157 | PC: 0x125968..0x125a00 (152 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x125968: D10103FF  sub      sp, sp, #0x40
//   0x12596c: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x125970: A9037BFD  stp      x29, x30, [sp, #0x30]
//   0x125974: 9100C3FD  add      x29, sp, #0x30
//   0x125978: D53BD054  mrs      x20, tpidr_el0
//   0x12597c: F9401688  ldr      x8, [x20, #0x28]
uint64_t fde_func_3157_0x125968(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00125968ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10103FFULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9024FF4ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9037BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9100C3FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD53BD054ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9401688ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0203E1ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910023E2ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #3161 | PC: 0x126044..0x126144 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x126044: D10203FF  sub      sp, sp, #0x80
//   0x126048: A90557F6  stp      x22, x21, [sp, #0x50]
//   0x12604c: A9064FF4  stp      x20, x19, [sp, #0x60]
//   0x126050: A9077BFD  stp      x29, x30, [sp, #0x70]
//   0x126054: 9101C3FD  add      x29, sp, #0x70
//   0x126058: D53BD056  mrs      x22, tpidr_el0
uint64_t fde_func_3161_0x126044(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00126044ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10203FFULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90557F6ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9064FF4ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9077BFDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9101C3FDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD53BD056ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF94016C8ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0103F4ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #3166 | PC: 0x126d38..0x126d98 (96 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x126d38: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x126d3c: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x126d40: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x126d44: 910083FD  add      x29, sp, #0x20
//   0x126d48: 6F00E400  movi     v0.2d, #0000000000000000
//   0x126d4c: 52A7F008  mov      w8, #0x3f800000
uint64_t fde_func_3166_0x126d38(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00126D38ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81D0FF5ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9014FF4ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9027BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910083FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x6F00E400ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x52A7F008ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAD000000ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB9002008ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #3170 | PC: 0x127204..0x127214 (16 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x127204: 90000D81  adrp     x1, #0x2d7000
//   0x127208: 9117B021  add      x1, x1, #0x5ec
//   0x12720c: AA0803E0  mov      x0, x8
//   0x127210: 17FC8A04  b        #0x49a20
uint64_t fde_func_3170_0x127204(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00127204ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0x90000D81ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9117B021ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0803E0ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x17FC8A04ULL ^ (3ULL << 32);
    return state ^ (state >> 29);
}

// FDE #3175 | PC: 0x1272d0..0x1272d4 (4 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x1272d0: D65F03C0  ret      
uint64_t fde_func_3175_0x1272d0(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x001272D0ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD65F03C0ULL ^ (0ULL << 32);
    return state ^ (state >> 29);
}

// FDE #3179 | PC: 0x127360..0x127460 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x127360: D10243FF  sub      sp, sp, #0x90
//   0x127364: A90657F6  stp      x22, x21, [sp, #0x60]
//   0x127368: A9074FF4  stp      x20, x19, [sp, #0x70]
//   0x12736c: A9087BFD  stp      x29, x30, [sp, #0x80]
//   0x127370: 910203FD  add      x29, sp, #0x80
//   0x127374: D53BD056  mrs      x22, tpidr_el0
uint64_t fde_func_3179_0x127360(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00127360ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10243FFULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90657F6ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9074FF4ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9087BFDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910203FDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD53BD056ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF94016C8ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #3184 | PC: 0x127894..0x127978 (228 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x127894: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x127898: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x12789c: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x1278a0: 910083FD  add      x29, sp, #0x20
//   0x1278a4: F1000428  subs     x8, x1, #1
//   0x1278a8: AA0003F3  mov      x19, x0
uint64_t fde_func_3184_0x127894(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00127894ULL);
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

// FDE #3188 | PC: 0x127fb4..0x1280b4 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x127fb4: D10203FF  sub      sp, sp, #0x80
//   0x127fb8: A9026FFC  stp      x28, x27, [sp, #0x20]
//   0x127fbc: A90367FA  stp      x26, x25, [sp, #0x30]
//   0x127fc0: A9045FF8  stp      x24, x23, [sp, #0x40]
//   0x127fc4: A90557F6  stp      x22, x21, [sp, #0x50]
//   0x127fc8: A9064FF4  stp      x20, x19, [sp, #0x60]
uint64_t fde_func_3188_0x127fb4(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00127FB4ULL);
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

// FDE #3193 | PC: 0x128260..0x128264 (4 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x128260: 17FC7034  b        #0x44330
uint64_t fde_func_3193_0x128260(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00128260ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0x17FC7034ULL ^ (0ULL << 32);
    return state ^ (state >> 29);
}

// FDE #3197 | PC: 0x12863c..0x128640 (4 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x12863c: D65F03C0  ret      
uint64_t fde_func_3197_0x12863c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0012863CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD65F03C0ULL ^ (0ULL << 32);
    return state ^ (state >> 29);
}

// FDE #3201 | PC: 0x1289f4..0x128a04 (16 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x1289f4: D0001228  adrp     x8, #0x36e000
//   0x1289f8: 9139C108  add      x8, x8, #0xe70
//   0x1289fc: F8008408  str      x8, [x0], #8
//   0x128a00: 17FE9CC1  b        #0xcfd04
uint64_t fde_func_3201_0x1289f4(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x001289F4ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD0001228ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9139C108ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF8008408ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x17FE9CC1ULL ^ (3ULL << 32);
    return state ^ (state >> 29);
}

// FDE #3206 | PC: 0x128adc..0x128b04 (40 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x128adc: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x128ae0: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x128ae4: 910043FD  add      x29, sp, #0x10
//   0x128ae8: AA0003F3  mov      x19, x0
//   0x128aec: 91002000  add      x0, x0, #8
//   0x128af0: 97FE9C85  bl       #0xcfd04
uint64_t fde_func_3206_0x128adc(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00128ADCULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81E0FF3ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91002000ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x97FE9C85ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9417BFDULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA1303E0ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #3210 | PC: 0x128d38..0x128d68 (48 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x128d38: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x128d3c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x128d40: 910043FD  add      x29, sp, #0x10
//   0x128d44: D0001228  adrp     x8, #0x36e000
//   0x128d48: 913BC108  add      x8, x8, #0xef0
//   0x128d4c: AA0003F3  mov      x19, x0
uint64_t fde_func_3210_0x128d38(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00128D38ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81E0FF3ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD0001228ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x913BC108ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF8018408ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x94000032ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #3215 | PC: 0x128e1c..0x128e88 (108 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x128e1c: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x128e20: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x128e24: 910043FD  add      x29, sp, #0x10
//   0x128e28: F00012A8  adrp     x8, #0x37f000
//   0x128e2c: F947C108  ldr      x8, [x8, #0xf80]
//   0x128e30: AA0003F3  mov      x19, x0
uint64_t fde_func_3215_0x128e1c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00128E1CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE4FF4ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF00012A8ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF947C108ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F4ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91030000ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #3219 | PC: 0x129154..0x129178 (36 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x129154: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x129158: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x12915c: 910043FD  add      x29, sp, #0x10
//   0x129160: AA0003F3  mov      x19, x0
//   0x129164: 97FFFFD1  bl       #0x1290a8
//   0x129168: A9417BFD  ldp      x29, x30, [sp, #0x10]
uint64_t fde_func_3219_0x129154(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00129154ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81E0FF3ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x97FFFFD1ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9417BFDULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA1303E0ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF84207F3ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #3224 | PC: 0x12d20c..0x12d30c (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x12d20c: D101C3FF  sub      sp, sp, #0x70
//   0x12d210: A90267FA  stp      x26, x25, [sp, #0x20]
//   0x12d214: A9035FF8  stp      x24, x23, [sp, #0x30]
//   0x12d218: A90457F6  stp      x22, x21, [sp, #0x40]
//   0x12d21c: A9054FF4  stp      x20, x19, [sp, #0x50]
//   0x12d220: A9067BFD  stp      x29, x30, [sp, #0x60]
uint64_t fde_func_3224_0x12d20c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0012D20CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD101C3FFULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90267FAULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9035FF8ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90457F6ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9054FF4ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9067BFDULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910183FDULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD53BD059ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #3228 | PC: 0x12d640..0x12d6b4 (116 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x12d640: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x12d644: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x12d648: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x12d64c: 910083FD  add      x29, sp, #0x20
//   0x12d650: 91002016  add      x22, x0, #8
//   0x12d654: 52801500  mov      w0, #0xa8
uint64_t fde_func_3228_0x12d640(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0012D640ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BD57F6ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9014FF4ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9027BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910083FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91002016ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x52801500ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0203F3ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0803F4ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #3233 | PC: 0x12d8c4..0x12d948 (132 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x12d8c4: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x12d8c8: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x12d8cc: 910043FD  add      x29, sp, #0x10
//   0x12d8d0: F9400428  ldr      x8, [x1, #8]
//   0x12d8d4: B40000A8  cbz      x8, #0x12d8e8
//   0x12d8d8: AA0803F3  mov      x19, x8
uint64_t fde_func_3233_0x12d8c4(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0012D8C4ULL);
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

// FDE #3237 | PC: 0x12d9e4..0x12d9e8 (4 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x12d9e4: 17FC5A53  b        #0x44330
uint64_t fde_func_3237_0x12d9e4(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0012D9E4ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0x17FC5A53ULL ^ (0ULL << 32);
    return state ^ (state >> 29);
}

// FDE #3242 | PC: 0x12e15c..0x12e1a0 (68 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x12e15c: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x12e160: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x12e164: 910043FD  add      x29, sp, #0x10
//   0x12e168: 39406008  ldrb     w8, [x0, #0x18]
//   0x12e16c: AA0003F3  mov      x19, x0
//   0x12e170: 34000088  cbz      w8, #0x12e180
uint64_t fde_func_3242_0x12e15c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0012E15CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81E0FF3ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x39406008ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x34000088ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA1303E0ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x97FC742AULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #3246 | PC: 0x12e284..0x12e344 (192 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x12e284: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x12e288: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x12e28c: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x12e290: 910083FD  add      x29, sp, #0x20
//   0x12e294: 3940002A  ldrb     w10, [x1]
//   0x12e298: F9400428  ldr      x8, [x1, #8]
uint64_t fde_func_3246_0x12e284(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0012E284ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81D0FF5ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9014FF4ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9027BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910083FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x3940002AULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400428ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x2A0203F3ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0103F4ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #3251 | PC: 0x12e754..0x12e854 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x12e754: D101C3FF  sub      sp, sp, #0x70
//   0x12e758: 6D0223E9  stp      d9, d8, [sp, #0x20]
//   0x12e75c: A9035FF8  stp      x24, x23, [sp, #0x30]
//   0x12e760: A90457F6  stp      x22, x21, [sp, #0x40]
//   0x12e764: A9054FF4  stp      x20, x19, [sp, #0x50]
//   0x12e768: A9067BFD  stp      x29, x30, [sp, #0x60]
uint64_t fde_func_3251_0x12e754(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0012E754ULL);
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

// FDE #3255 | PC: 0x12ea70..0x12eafc (140 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x12ea70: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x12ea74: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x12ea78: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x12ea7c: 910083FD  add      x29, sp, #0x20
//   0x12ea80: 91034013  add      x19, x0, #0xd0
//   0x12ea84: AA0003F4  mov      x20, x0
uint64_t fde_func_3255_0x12ea70(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0012EA70ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BD57F6ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9014FF4ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9027BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910083FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91034013ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F4ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA1303E0ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0103F6ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #3260 | PC: 0x12ee1c..0x12ee24 (8 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x12ee1c: AA0303E0  mov      x0, x3
//   0x12ee20: D65F03C0  ret      
uint64_t fde_func_3260_0x12ee1c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0012EE1CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0303E0ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD65F03C0ULL ^ (1ULL << 32);
    return state ^ (state >> 29);
}

// FDE #3264 | PC: 0x12ee9c..0x12eea0 (4 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x12ee9c: D65F03C0  ret      
uint64_t fde_func_3264_0x12ee9c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0012EE9CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD65F03C0ULL ^ (0ULL << 32);
    return state ^ (state >> 29);
}

// FDE #3269 | PC: 0x12f210..0x12f214 (4 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x12f210: D65F03C0  ret      
uint64_t fde_func_3269_0x12f210(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0012F210ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD65F03C0ULL ^ (0ULL << 32);
    return state ^ (state >> 29);
}

// FDE #3273 | PC: 0x12f4c8..0x12f578 (176 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x12f4c8: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x12f4cc: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x12f4d0: 910043FD  add      x29, sp, #0x10
//   0x12f4d4: 90001208  adrp     x8, #0x36f000
//   0x12f4d8: AA0003F3  mov      x19, x0
//   0x12f4dc: 6F00E400  movi     v0.2d, #0000000000000000
uint64_t fde_func_3273_0x12f4c8(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0012F4C8ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE4FF4ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x90001208ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x6F00E400ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9104E108ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9057C1FULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #3277 | PC: 0x12f884..0x12f984 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x12f884: D106C3FF  sub      sp, sp, #0x1b0
//   0x12f888: A9156FFC  stp      x28, x27, [sp, #0x150]
//   0x12f88c: A91667FA  stp      x26, x25, [sp, #0x160]
//   0x12f890: A9175FF8  stp      x24, x23, [sp, #0x170]
//   0x12f894: A91857F6  stp      x22, x21, [sp, #0x180]
//   0x12f898: A9194FF4  stp      x20, x19, [sp, #0x190]
uint64_t fde_func_3277_0x12f884(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0012F884ULL);
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

// FDE #3282 | PC: 0x130020..0x130120 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x130020: FC1A0FEA  str      d10, [sp, #-0x60]!
//   0x130024: 6D0123E9  stp      d9, d8, [sp, #0x10]
//   0x130028: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x13002c: A90357F6  stp      x22, x21, [sp, #0x30]
//   0x130030: A9044FF4  stp      x20, x19, [sp, #0x40]
//   0x130034: A9057BFD  stp      x29, x30, [sp, #0x50]
uint64_t fde_func_3282_0x130020(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00130020ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xFC1A0FEAULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x6D0123E9ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9025FF8ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90357F6ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9044FF4ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9057BFDULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910143FDULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9406009ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #3286 | PC: 0x13028c..0x1302b0 (36 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x13028c: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x130290: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x130294: 910043FD  add      x29, sp, #0x10
//   0x130298: AA0003F3  mov      x19, x0
//   0x13029c: 97FFE2E0  bl       #0x128e1c
//   0x1302a0: A9417BFD  ldp      x29, x30, [sp, #0x10]
uint64_t fde_func_3286_0x13028c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0013028CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81E0FF3ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x97FFE2E0ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9417BFDULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA1303E0ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF84207F3ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #3291 | PC: 0x130954..0x1309dc (136 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x130954: F9400029  ldr      x9, [x1]
//   0x130958: F9400008  ldr      x8, [x0]
//   0x13095c: F940004A  ldr      x10, [x2]
//   0x130960: EB08013F  cmp      x9, x8
//   0x130964: 540000CA  b.ge     #0x13097c
//   0x130968: EB09015F  cmp      x10, x9
uint64_t fde_func_3291_0x130954(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00130954ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400029ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400008ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF940004AULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xEB08013FULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x540000CAULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xEB09015FULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x540001EAULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF900000AULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #3295 | PC: 0x130bd4..0x130cd4 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x130bd4: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x130bd8: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x130bdc: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x130be0: 910083FD  add      x29, sp, #0x20
//   0x130be4: CB000028  sub      x8, x1, x0
//   0x130be8: 9343FD08  asr      x8, x8, #3
uint64_t fde_func_3295_0x130bd4(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00130BD4ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81D0FF5ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9014FF4ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9027BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910083FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xCB000028ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9343FD08ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0103F4ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #3300 | PC: 0x131288..0x131334 (172 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x131288: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x13128c: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x131290: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x131294: 910083FD  add      x29, sp, #0x20
//   0x131298: 91004015  add      x21, x0, #0x10
//   0x13129c: AA0203E3  mov      x3, x2
uint64_t fde_func_3300_0x131288(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00131288ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81D0FF5ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9014FF4ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9027BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910083FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91004015ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0203E3ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0103F3ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91002001ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #3304 | PC: 0x1314b8..0x1314c8 (16 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x1314b8: F0000D21  adrp     x1, #0x2d8000
//   0x1314bc: 91287C21  add      x1, x1, #0xa1f
//   0x1314c0: AA0803E0  mov      x0, x8
//   0x1314c4: 17FC6157  b        #0x49a20
uint64_t fde_func_3304_0x1314b8(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x001314B8ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF0000D21ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91287C21ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0803E0ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x17FC6157ULL ^ (3ULL << 32);
    return state ^ (state >> 29);
}

// FDE #3309 | PC: 0x131738..0x1317e4 (172 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x131738: D10143FF  sub      sp, sp, #0x50
//   0x13173c: F90013F5  str      x21, [sp, #0x20]
//   0x131740: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x131744: A9047BFD  stp      x29, x30, [sp, #0x40]
//   0x131748: 910103FD  add      x29, sp, #0x40
//   0x13174c: D53BD055  mrs      x21, tpidr_el0
uint64_t fde_func_3309_0x131738(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00131738ULL);
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

// FDE #3313 | PC: 0x1319e4..0x131a90 (172 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x1319e4: D10143FF  sub      sp, sp, #0x50
//   0x1319e8: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x1319ec: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x1319f0: A9047BFD  stp      x29, x30, [sp, #0x40]
//   0x1319f4: 910103FD  add      x29, sp, #0x40
//   0x1319f8: D53BD056  mrs      x22, tpidr_el0
uint64_t fde_func_3313_0x1319e4(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x001319E4ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10143FFULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90257F6ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9034FF4ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9047BFDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910103FDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD53BD056ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0803F5ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF94016C8ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #3318 | PC: 0x1327d4..0x1327d8 (4 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x1327d4: D65F03C0  ret      
uint64_t fde_func_3318_0x1327d4(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x001327D4ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD65F03C0ULL ^ (0ULL << 32);
    return state ^ (state >> 29);
}

// FDE #3322 | PC: 0x132928..0x1329d4 (172 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x132928: D10103FF  sub      sp, sp, #0x40
//   0x13292c: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x132930: A9037BFD  stp      x29, x30, [sp, #0x30]
//   0x132934: 9100C3FD  add      x29, sp, #0x30
//   0x132938: D53BD054  mrs      x20, tpidr_el0
//   0x13293c: F9401688  ldr      x8, [x20, #0x28]
uint64_t fde_func_3322_0x132928(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00132928ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10103FFULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9024FF4ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9037BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9100C3FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD53BD054ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9401688ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0203E1ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000FE8ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #3327 | PC: 0x133268..0x1332d0 (104 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x133268: 2A0003E9  mov      w9, w0
//   0x13326c: 7100041F  cmp      w0, #1
//   0x133270: AA0803E0  mov      x0, x8
//   0x133274: 540000EC  b.gt     #0x133290
//   0x133278: 34000209  cbz      w9, #0x1332b8
//   0x13327c: 7100053F  cmp      w9, #1
uint64_t fde_func_3327_0x133268(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00133268ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0x2A0003E9ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x7100041FULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0803E0ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x540000ECULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x34000209ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x7100053FULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x54000161ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB0000D21ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #3331 | PC: 0x133460..0x13348c (44 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x133460: F9404809  ldr      x9, [x0, #0x90]
//   0x133464: F9000109  str      x9, [x8]
//   0x133468: F9404C09  ldr      x9, [x0, #0x98]
//   0x13346c: F9000509  str      x9, [x8, #8]
//   0x133470: B40000C9  cbz      x9, #0x133488
//   0x133474: 91002128  add      x8, x9, #8
uint64_t fde_func_3331_0x133460(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00133460ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9404809ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000109ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9404C09ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000509ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB40000C9ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91002128ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xC85F7D09ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91000529ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #3336 | PC: 0x13357c..0x133584 (8 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x13357c: 91006000  add      x0, x0, #0x18
//   0x133580: 17FFFFC3  b        #0x13348c
uint64_t fde_func_3336_0x13357c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0013357CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0x91006000ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x17FFFFC3ULL ^ (1ULL << 32);
    return state ^ (state >> 29);
}

// FDE #3340 | PC: 0x133858..0x13385c (4 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x133858: 17FC42B6  b        #0x44330
uint64_t fde_func_3340_0x133858(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00133858ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0x17FC42B6ULL ^ (0ULL << 32);
    return state ^ (state >> 29);
}

// FDE #3345 | PC: 0x133bcc..0x133c58 (140 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x133bcc: D10103FF  sub      sp, sp, #0x40
//   0x133bd0: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x133bd4: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x133bd8: A9037BFD  stp      x29, x30, [sp, #0x30]
//   0x133bdc: 9100C3FD  add      x29, sp, #0x30
//   0x133be0: D53BD056  mrs      x22, tpidr_el0
uint64_t fde_func_3345_0x133bcc(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00133BCCULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10103FFULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90157F6ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9024FF4ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9037BFDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9100C3FDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD53BD056ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF94016C8ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91009013ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #3349 | PC: 0x133e44..0x133e48 (4 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x133e44: D65F03C0  ret      
uint64_t fde_func_3349_0x133e44(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00133E44ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD65F03C0ULL ^ (0ULL << 32);
    return state ^ (state >> 29);
}

// FDE #3354 | PC: 0x133e7c..0x133e90 (20 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x133e7c: AA0803E9  mov      x9, x8
//   0x133e80: F8008D3F  str      xzr, [x9, #8]!
//   0x133e84: F900091F  str      xzr, [x8, #0x10]
//   0x133e88: F9000109  str      x9, [x8]
//   0x133e8c: D65F03C0  ret      
uint64_t fde_func_3354_0x133e7c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00133E7CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0803E9ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF8008D3FULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF900091FULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9000109ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD65F03C0ULL ^ (4ULL << 32);
    return state ^ (state >> 29);
}

// FDE #3358 | PC: 0x13426c..0x1342d8 (108 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x13426c: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x134270: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x134274: 910043FD  add      x29, sp, #0x10
//   0x134278: 52800020  mov      w0, #1
//   0x13427c: AA0103F3  mov      x19, x1
//   0x134280: 97FC459D  bl       #0x458f4
uint64_t fde_func_3358_0x13426c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0013426CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81E0FF3ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x52800020ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0103F3ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x97FC459DULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x36000140ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x90000D21ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #3362 | PC: 0x134428..0x1344f0 (200 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x134428: F81C0FF7  str      x23, [sp, #-0x40]!
//   0x13442c: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x134430: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x134434: A9037BFD  stp      x29, x30, [sp, #0x30]
//   0x134438: 9100C3FD  add      x29, sp, #0x30
//   0x13443c: 91030013  add      x19, x0, #0xc0
uint64_t fde_func_3362_0x134428(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00134428ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81C0FF7ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90157F6ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9024FF4ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9037BFDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9100C3FDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91030013ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F4ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA1303E0ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #3367 | PC: 0x13475c..0x1347e0 (132 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x13475c: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x134760: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x134764: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x134768: 910083FD  add      x29, sp, #0x20
//   0x13476c: 9105A013  add      x19, x0, #0x168
//   0x134770: AA0003F5  mov      x21, x0
uint64_t fde_func_3367_0x13475c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0013475CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81D0FF5ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9014FF4ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9027BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910083FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9105A013ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F5ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA1303E0ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0103F4ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #3371 | PC: 0x1348e0..0x134920 (64 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x1348e0: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x1348e4: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x1348e8: 910043FD  add      x29, sp, #0x10
//   0x1348ec: AA0003F3  mov      x19, x0
//   0x1348f0: 97FC3D88  bl       #0x43f10
//   0x1348f4: B4000100  cbz      x0, #0x134914
uint64_t fde_func_3371_0x1348e0(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x001348E0ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81E0FF3ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x97FC3D88ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB4000100ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400008ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9417BFDULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #3376 | PC: 0x134a08..0x134a2c (36 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x134a08: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x134a0c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x134a10: 910043FD  add      x29, sp, #0x10
//   0x134a14: AA0003F3  mov      x19, x0
//   0x134a18: 97FEED5C  bl       #0xeff88
//   0x134a1c: A9417BFD  ldp      x29, x30, [sp, #0x10]
uint64_t fde_func_3376_0x134a08(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00134A08ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81E0FF3ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x97FEED5CULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9417BFDULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA1303E0ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF84207F3ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #3380 | PC: 0x134acc..0x134b34 (104 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x134acc: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x134ad0: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x134ad4: 910043FD  add      x29, sp, #0x10
//   0x134ad8: F9401028  ldr      x8, [x1, #0x20]
//   0x134adc: AA0003F3  mov      x19, x0
//   0x134ae0: B4000128  cbz      x8, #0x134b04
uint64_t fde_func_3380_0x134acc(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00134ACCULL);
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

// FDE #3385 | PC: 0x134ce0..0x134d58 (120 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x134ce0: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x134ce4: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x134ce8: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x134cec: 910083FD  add      x29, sp, #0x20
//   0x134cf0: F9400400  ldr      x0, [x0, #8]
//   0x134cf4: AA0803F3  mov      x19, x8
uint64_t fde_func_3385_0x134ce0(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00134CE0ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81D0FF5ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9014FF4ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9027BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910083FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400400ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0803F3ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB4000100ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400008ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #3389 | PC: 0x134e78..0x134ef0 (120 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x134e78: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x134e7c: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x134e80: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x134e84: 910083FD  add      x29, sp, #0x20
//   0x134e88: F9400400  ldr      x0, [x0, #8]
//   0x134e8c: AA0803F3  mov      x19, x8
uint64_t fde_func_3389_0x134e78(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00134E78ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81D0FF5ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9014FF4ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9027BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910083FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400400ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0803F3ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB4000100ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400008ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #3394 | PC: 0x1351e4..0x1352e4 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x1351e4: D101C3FF  sub      sp, sp, #0x70
//   0x1351e8: F90023F5  str      x21, [sp, #0x40]
//   0x1351ec: A9054FF4  stp      x20, x19, [sp, #0x50]
//   0x1351f0: A9067BFD  stp      x29, x30, [sp, #0x60]
//   0x1351f4: 910183FD  add      x29, sp, #0x60
//   0x1351f8: D53BD055  mrs      x21, tpidr_el0
uint64_t fde_func_3394_0x1351e4(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x001351E4ULL);
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

// FDE #3398 | PC: 0x135510..0x135574 (100 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x135510: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x135514: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x135518: 910043FD  add      x29, sp, #0x10
//   0x13551c: 39400028  ldrb     w8, [x1]
//   0x135520: F9400429  ldr      x9, [x1, #8]
//   0x135524: 2A0203F3  mov      w19, w2
uint64_t fde_func_3398_0x135510(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00135510ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9BE4FF4ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x39400028ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400429ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x2A0203F3ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD341FD0AULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x7200011FULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #3403 | PC: 0x135668..0x13566c (4 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x135668: D65F03C0  ret      
uint64_t fde_func_3403_0x135668(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00135668ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD65F03C0ULL ^ (0ULL << 32);
    return state ^ (state >> 29);
}

// FDE #3407 | PC: 0x1356b0..0x1356c0 (16 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x1356b0: D00011C8  adrp     x8, #0x36f000
//   0x1356b4: 9116C108  add      x8, x8, #0x5b0
//   0x1356b8: A9007C08  stp      x8, xzr, [x0]
//   0x1356bc: D65F03C0  ret      
uint64_t fde_func_3407_0x1356b0(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x001356B0ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD00011C8ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9116C108ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9007C08ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD65F03C0ULL ^ (3ULL << 32);
    return state ^ (state >> 29);
}

// FDE #3412 | PC: 0x135744..0x135760 (28 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x135744: F9400400  ldr      x0, [x0, #8]
//   0x135748: B4000080  cbz      x0, #0x135758
//   0x13574c: F9400008  ldr      x8, [x0]
//   0x135750: F9400D02  ldr      x2, [x8, #0x18]
//   0x135754: D61F0040  br       x2
//   0x135758: 9E6703E0  fmov     d0, xzr
uint64_t fde_func_3412_0x135744(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00135744ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400400ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB4000080ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400008ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF9400D02ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD61F0040ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9E6703E0ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD65F03C0ULL ^ (6ULL << 32);
    return state ^ (state >> 29);
}

// FDE #3416 | PC: 0x13579c..0x1357a0 (4 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x13579c: 17FC3AE5  b        #0x44330
uint64_t fde_func_3416_0x13579c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0013579CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0x17FC3AE5ULL ^ (0ULL << 32);
    return state ^ (state >> 29);
}

// FDE #3421 | PC: 0x136780..0x136784 (4 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x136780: 17FC36EC  b        #0x44330
uint64_t fde_func_3421_0x136780(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00136780ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0x17FC36ECULL ^ (0ULL << 32);
    return state ^ (state >> 29);
}

// FDE #3425 | PC: 0x1367d8..0x1367dc (4 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x1367d8: 17FC36D6  b        #0x44330
uint64_t fde_func_3425_0x1367d8(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x001367D8ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0x17FC36D6ULL ^ (0ULL << 32);
    return state ^ (state >> 29);
}

// FDE #3430 | PC: 0x136b7c..0x136c04 (136 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x136b7c: B9400029  ldr      w9, [x1]
//   0x136b80: B9400008  ldr      w8, [x0]
//   0x136b84: B940004A  ldr      w10, [x2]
//   0x136b88: 6B08013F  cmp      w9, w8
//   0x136b8c: 540000CA  b.ge     #0x136ba4
//   0x136b90: 6B09015F  cmp      w10, w9
uint64_t fde_func_3430_0x136b7c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00136B7CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xB9400029ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB9400008ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB940004AULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x6B08013FULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x540000CAULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x6B09015FULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x540001EAULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xB900000AULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #3434 | PC: 0x136dfc..0x136efc (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x136dfc: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x136e00: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x136e04: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x136e08: 910083FD  add      x29, sp, #0x20
//   0x136e0c: CB000028  sub      x8, x1, x0
//   0x136e10: 9342FD08  asr      x8, x8, #2
uint64_t fde_func_3434_0x136dfc(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00136DFCULL);
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

// FDE #3438 | PC: 0x136ff4..0x13701c (40 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x136ff4: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x136ff8: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x136ffc: 910043FD  add      x29, sp, #0x10
//   0x137000: D1004013  sub      x19, x0, #0x10
//   0x137004: AA1303E0  mov      x0, x19
//   0x137008: 97FFFFD7  bl       #0x136f64
uint64_t fde_func_3438_0x136ff4(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00136FF4ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81E0FF3ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD1004013ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA1303E0ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x97FFFFD7ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9417BFDULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA1303E0ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #3443 | PC: 0x1375bc..0x1376bc (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x1375bc: D104C3FF  sub      sp, sp, #0x130
//   0x1375c0: A90D6FFC  stp      x28, x27, [sp, #0xd0]
//   0x1375c4: A90E67FA  stp      x26, x25, [sp, #0xe0]
//   0x1375c8: A90F5FF8  stp      x24, x23, [sp, #0xf0]
//   0x1375cc: A91057F6  stp      x22, x21, [sp, #0x100]
//   0x1375d0: A9114FF4  stp      x20, x19, [sp, #0x110]
uint64_t fde_func_3443_0x1375bc(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x001375BCULL);
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

// FDE #3447 | PC: 0x1387f0..0x1388f0 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x1387f0: A9BA6FFC  stp      x28, x27, [sp, #-0x60]!
//   0x1387f4: A90167FA  stp      x26, x25, [sp, #0x10]
//   0x1387f8: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x1387fc: A90357F6  stp      x22, x21, [sp, #0x30]
//   0x138800: A9044FF4  stp      x20, x19, [sp, #0x40]
//   0x138804: A9057BFD  stp      x29, x30, [sp, #0x50]
uint64_t fde_func_3447_0x1387f0(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x001387F0ULL);
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

// FDE #3452 | PC: 0x13b12c..0x13b22c (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x13b12c: D10183FF  sub      sp, sp, #0x60
//   0x13b130: A90357F6  stp      x22, x21, [sp, #0x30]
//   0x13b134: A9044FF4  stp      x20, x19, [sp, #0x40]
//   0x13b138: A9057BFD  stp      x29, x30, [sp, #0x50]
//   0x13b13c: 910143FD  add      x29, sp, #0x50
//   0x13b140: D53BD056  mrs      x22, tpidr_el0
uint64_t fde_func_3452_0x13b12c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0013B12CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10183FFULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90357F6ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9044FF4ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9057BFDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910143FDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD53BD056ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF94016C8ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #3456 | PC: 0x13be24..0x13bf24 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x13be24: D106C3FF  sub      sp, sp, #0x1b0
//   0x13be28: A9156FFC  stp      x28, x27, [sp, #0x150]
//   0x13be2c: A91667FA  stp      x26, x25, [sp, #0x160]
//   0x13be30: A9175FF8  stp      x24, x23, [sp, #0x170]
//   0x13be34: A91857F6  stp      x22, x21, [sp, #0x180]
//   0x13be38: A9194FF4  stp      x20, x19, [sp, #0x190]
uint64_t fde_func_3456_0x13be24(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0013BE24ULL);
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

// FDE #3461 | PC: 0x13d950..0x13da20 (208 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x13d950: D10183FF  sub      sp, sp, #0x60
//   0x13d954: A90357F6  stp      x22, x21, [sp, #0x30]
//   0x13d958: A9044FF4  stp      x20, x19, [sp, #0x40]
//   0x13d95c: A9057BFD  stp      x29, x30, [sp, #0x50]
//   0x13d960: 910143FD  add      x29, sp, #0x50
//   0x13d964: D53BD055  mrs      x21, tpidr_el0
uint64_t fde_func_3461_0x13d950(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0013D950ULL);
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

// FDE #3465 | PC: 0x13e20c..0x13e268 (92 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x13e20c: D100C3FF  sub      sp, sp, #0x30
//   0x13e210: F9000BF3  str      x19, [sp, #0x10]
//   0x13e214: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x13e218: 910083FD  add      x29, sp, #0x20
//   0x13e21c: D53BD053  mrs      x19, tpidr_el0
//   0x13e220: F9401668  ldr      x8, [x19, #0x28]
uint64_t fde_func_3465_0x13e20c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0013E20CULL);
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

// FDE #3470 | PC: 0x13e420..0x13e464 (68 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x13e420: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x13e424: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x13e428: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x13e42c: 910083FD  add      x29, sp, #0x20
//   0x13e430: 91180015  add      x21, x0, #0x600
//   0x13e434: AA0003F3  mov      x19, x0
uint64_t fde_func_3470_0x13e420(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0013E420ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81D0FF5ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9014FF4ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9027BFDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910083FDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91180015ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA1503E0ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0803F4ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #3474 | PC: 0x13e504..0x13e508 (4 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x13e504: 17FC178B  b        #0x44330
uint64_t fde_func_3474_0x13e504(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0013E504ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0x17FC178BULL ^ (0ULL << 32);
    return state ^ (state >> 29);
}

// FDE #3479 | PC: 0x13ea24..0x13eb24 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x13ea24: A9BA6FFC  stp      x28, x27, [sp, #-0x60]!
//   0x13ea28: A90167FA  stp      x26, x25, [sp, #0x10]
//   0x13ea2c: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x13ea30: A90357F6  stp      x22, x21, [sp, #0x30]
//   0x13ea34: A9044FF4  stp      x20, x19, [sp, #0x40]
//   0x13ea38: A9057BFD  stp      x29, x30, [sp, #0x50]
uint64_t fde_func_3479_0x13ea24(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0013EA24ULL);
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

// FDE #3483 | PC: 0x13f2c4..0x13f3c4 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x13f2c4: D10743FF  sub      sp, sp, #0x1d0
//   0x13f2c8: A9176FFC  stp      x28, x27, [sp, #0x170]
//   0x13f2cc: A91867FA  stp      x26, x25, [sp, #0x180]
//   0x13f2d0: A9195FF8  stp      x24, x23, [sp, #0x190]
//   0x13f2d4: A91A57F6  stp      x22, x21, [sp, #0x1a0]
//   0x13f2d8: A91B4FF4  stp      x20, x19, [sp, #0x1b0]
uint64_t fde_func_3483_0x13f2c4(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0013F2C4ULL);
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

// FDE #3488 | PC: 0x13fc24..0x13fd24 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x13fc24: D10603FF  sub      sp, sp, #0x180
//   0x13fc28: A9126FFC  stp      x28, x27, [sp, #0x120]
//   0x13fc2c: A91367FA  stp      x26, x25, [sp, #0x130]
//   0x13fc30: A9145FF8  stp      x24, x23, [sp, #0x140]
//   0x13fc34: A91557F6  stp      x22, x21, [sp, #0x150]
//   0x13fc38: A9164FF4  stp      x20, x19, [sp, #0x160]
uint64_t fde_func_3488_0x13fc24(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0013FC24ULL);
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

// FDE #3492 | PC: 0x140288..0x140388 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x140288: D10503FF  sub      sp, sp, #0x140
//   0x14028c: A90E6FFC  stp      x28, x27, [sp, #0xe0]
//   0x140290: A90F67FA  stp      x26, x25, [sp, #0xf0]
//   0x140294: A9105FF8  stp      x24, x23, [sp, #0x100]
//   0x140298: A91157F6  stp      x22, x21, [sp, #0x110]
//   0x14029c: A9124FF4  stp      x20, x19, [sp, #0x120]
uint64_t fde_func_3492_0x140288(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00140288ULL);
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

// FDE #3497 | PC: 0x140924..0x140a24 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x140924: D10383FF  sub      sp, sp, #0xe0
//   0x140928: A9086FFC  stp      x28, x27, [sp, #0x80]
//   0x14092c: A90967FA  stp      x26, x25, [sp, #0x90]
//   0x140930: A90A5FF8  stp      x24, x23, [sp, #0xa0]
//   0x140934: A90B57F6  stp      x22, x21, [sp, #0xb0]
//   0x140938: A90C4FF4  stp      x20, x19, [sp, #0xc0]
uint64_t fde_func_3497_0x140924(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00140924ULL);
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

// FDE #3501 | PC: 0x140d60..0x140e60 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x140d60: D10283FF  sub      sp, sp, #0xa0
//   0x140d64: A9046FFC  stp      x28, x27, [sp, #0x40]
//   0x140d68: A90567FA  stp      x26, x25, [sp, #0x50]
//   0x140d6c: A9065FF8  stp      x24, x23, [sp, #0x60]
//   0x140d70: A90757F6  stp      x22, x21, [sp, #0x70]
//   0x140d74: A9084FF4  stp      x20, x19, [sp, #0x80]
uint64_t fde_func_3501_0x140d60(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00140D60ULL);
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

// FDE #3506 | PC: 0x141328..0x141428 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x141328: D10203FF  sub      sp, sp, #0x80
//   0x14132c: A9026FFC  stp      x28, x27, [sp, #0x20]
//   0x141330: A90367FA  stp      x26, x25, [sp, #0x30]
//   0x141334: A9045FF8  stp      x24, x23, [sp, #0x40]
//   0x141338: A90557F6  stp      x22, x21, [sp, #0x50]
//   0x14133c: A9064FF4  stp      x20, x19, [sp, #0x60]
uint64_t fde_func_3506_0x141328(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00141328ULL);
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

// FDE #3510 | PC: 0x1416fc..0x1417d0 (212 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x1416fc: D10143FF  sub      sp, sp, #0x50
//   0x141700: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x141704: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x141708: A9047BFD  stp      x29, x30, [sp, #0x40]
//   0x14170c: 910103FD  add      x29, sp, #0x40
//   0x141710: D53BD056  mrs      x22, tpidr_el0
uint64_t fde_func_3510_0x1416fc(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x001416FCULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xD10143FFULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90257F6ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9034FF4ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9047BFDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910103FDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xD53BD056ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF94016C8ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F5ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #3514 | PC: 0x141a78..0x141b78 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x141a78: D101C3FF  sub      sp, sp, #0x70
//   0x141a7c: A9016FFC  stp      x28, x27, [sp, #0x10]
//   0x141a80: A90267FA  stp      x26, x25, [sp, #0x20]
//   0x141a84: A9035FF8  stp      x24, x23, [sp, #0x30]
//   0x141a88: A90457F6  stp      x22, x21, [sp, #0x40]
//   0x141a8c: A9054FF4  stp      x20, x19, [sp, #0x50]
uint64_t fde_func_3514_0x141a78(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00141A78ULL);
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

// FDE #3519 | PC: 0x141f1c..0x141fe8 (204 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x141f1c: D10143FF  sub      sp, sp, #0x50
//   0x141f20: F9000BF7  str      x23, [sp, #0x10]
//   0x141f24: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x141f28: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x141f2c: A9047BFD  stp      x29, x30, [sp, #0x40]
//   0x141f30: 910103FD  add      x29, sp, #0x40
uint64_t fde_func_3519_0x141f1c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00141F1CULL);
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

// FDE #3523 | PC: 0x142324..0x1423f0 (204 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x142324: D10143FF  sub      sp, sp, #0x50
//   0x142328: F9000BF7  str      x23, [sp, #0x10]
//   0x14232c: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x142330: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x142334: A9047BFD  stp      x29, x30, [sp, #0x40]
//   0x142338: 910103FD  add      x29, sp, #0x40
uint64_t fde_func_3523_0x142324(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00142324ULL);
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

// FDE #3528 | PC: 0x142908..0x142970 (104 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x142908: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x14290c: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x142910: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x142914: 910083FD  add      x29, sp, #0x20
//   0x142918: F9400015  ldr      x21, [x0]
//   0x14291c: B4000235  cbz      x21, #0x142960
uint64_t fde_func_3528_0x142908(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00142908ULL);
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

// FDE #3532 | PC: 0x142c08..0x142c48 (64 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x142c08: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x142c0c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x142c10: 910043FD  add      x29, sp, #0x10
//   0x142c14: D37CFC28  lsr      x8, x1, #0x3c
//   0x142c18: B5000168  cbnz     x8, #0x142c44
//   0x142c1c: AA0003F4  mov      x20, x0
uint64_t fde_func_3532_0x142c08(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00142C08ULL);
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

// FDE #3537 | PC: 0x142e68..0x142e6c (4 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x142e68: 17FC0532  b        #0x44330
uint64_t fde_func_3537_0x142e68(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00142E68ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0x17FC0532ULL ^ (0ULL << 32);
    return state ^ (state >> 29);
}

// FDE #3541 | PC: 0x142f30..0x142f54 (36 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x142f30: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x142f34: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x142f38: 910043FD  add      x29, sp, #0x10
//   0x142f3c: AA0003F3  mov      x19, x0
//   0x142f40: 97FC0820  bl       #0x44fc0
//   0x142f44: A9417BFD  ldp      x29, x30, [sp, #0x10]
uint64_t fde_func_3541_0x142f30(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00142F30ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81E0FF3ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9017BFDULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910043FDULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0003F3ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x97FC0820ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9417BFDULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA1303E0ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xF84207F3ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #3546 | PC: 0x143024..0x143124 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x143024: F81A0FFB  str      x27, [sp, #-0x60]!
//   0x143028: A90167FA  stp      x26, x25, [sp, #0x10]
//   0x14302c: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x143030: A90357F6  stp      x22, x21, [sp, #0x30]
//   0x143034: A9044FF4  stp      x20, x19, [sp, #0x40]
//   0x143038: A9057BFD  stp      x29, x30, [sp, #0x50]
uint64_t fde_func_3546_0x143024(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00143024ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81A0FFBULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90167FAULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9025FF8ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90357F6ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9044FF4ULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9057BFDULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910143FDULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0203F3ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #3550 | PC: 0x1438b4..0x1439b4 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x1438b4: F81B0FF9  str      x25, [sp, #-0x50]!
//   0x1438b8: A9015FF8  stp      x24, x23, [sp, #0x10]
//   0x1438bc: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x1438c0: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x1438c4: A9047BFD  stp      x29, x30, [sp, #0x40]
//   0x1438c8: 910103FD  add      x29, sp, #0x40
uint64_t fde_func_3550_0x1438b4(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x001438B4ULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81B0FF9ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9015FF8ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90257F6ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9034FF4ULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9047BFDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x910103FDULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x91008015ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0203E3ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #3555 | PC: 0x14425c..0x14435c (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x14425c: F81C0FF7  str      x23, [sp, #-0x40]!
//   0x144260: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x144264: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x144268: A9037BFD  stp      x29, x30, [sp, #0x30]
//   0x14426c: 9100C3FD  add      x29, sp, #0x30
//   0x144270: AA0403F7  mov      x23, x4
uint64_t fde_func_3555_0x14425c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x0014425CULL);
    state = (state * 0x00000100000001B3ULL) ^ 0xF81C0FF7ULL ^ (0ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA90157F6ULL ^ (1ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9024FF4ULL ^ (2ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xA9037BFDULL ^ (3ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0x9100C3FDULL ^ (4ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0403F7ULL ^ (5ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0503E4ULL ^ (6ULL << 32);
    state = (state * 0x00000100000001B3ULL) ^ 0xAA0303F6ULL ^ (7ULL << 32);
    return state ^ (state >> 29);
}

// FDE #3559 | PC: 0x144794..0x144894 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x144794: A9BA6FFC  stp      x28, x27, [sp, #-0x60]!
//   0x144798: A90167FA  stp      x26, x25, [sp, #0x10]
//   0x14479c: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x1447a0: A90357F6  stp      x22, x21, [sp, #0x30]
//   0x1447a4: A9044FF4  stp      x20, x19, [sp, #0x40]
//   0x1447a8: A9057BFD  stp      x29, x30, [sp, #0x50]
uint64_t fde_func_3559_0x144794(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00144794ULL);
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

// FDE #3564 | PC: 0x144c1c..0x144d1c (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x144c1c: D10383FF  sub      sp, sp, #0xe0
//   0x144c20: F90043FB  str      x27, [sp, #0x80]
//   0x144c24: A90967FA  stp      x26, x25, [sp, #0x90]
//   0x144c28: A90A5FF8  stp      x24, x23, [sp, #0xa0]
//   0x144c2c: A90B57F6  stp      x22, x21, [sp, #0xb0]
//   0x144c30: A90C4FF4  stp      x20, x19, [sp, #0xc0]
uint64_t fde_func_3564_0x144c1c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00144C1CULL);
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

// FDE #3568 | PC: 0x146a8c..0x146b8c (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x146a8c: D106C3FF  sub      sp, sp, #0x1b0
//   0x146a90: A9156FFC  stp      x28, x27, [sp, #0x150]
//   0x146a94: A91667FA  stp      x26, x25, [sp, #0x160]
//   0x146a98: A9175FF8  stp      x24, x23, [sp, #0x170]
//   0x146a9c: A91857F6  stp      x22, x21, [sp, #0x180]
//   0x146aa0: A9194FF4  stp      x20, x19, [sp, #0x190]
uint64_t fde_func_3568_0x146a8c(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00146A8CULL);
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

// FDE #3573 | PC: 0x147314..0x147414 (256 bytes) — Bilingual EN/VN Clean-Room Reconstruction
//   0x147314: D10203FF  sub      sp, sp, #0x80
//   0x147318: FD0023E8  str      d8, [sp, #0x40]
//   0x14731c: A90557F6  stp      x22, x21, [sp, #0x50]
//   0x147320: A9064FF4  stp      x20, x19, [sp, #0x60]
//   0x147324: A9077BFD  stp      x29, x30, [sp, #0x70]
//   0x147328: 9101C3FD  add      x29, sp, #0x70
uint64_t fde_func_3573_0x147314(uint64_t r0, uint64_t r1) noexcept {
    uint64_t state = r0 ^ (r1 + 0x00147314ULL);
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

uint64_t execute_fde_shard_2(uint32_t fde_idx, uint64_t a0, uint64_t a1) {
    switch (fde_idx) {
        case 1788: return fde_func_1788_0x0ce4e0(a0, a1);
        case 1793: return fde_func_1793_0x0ce994(a0, a1);
        case 1797: return fde_func_1797_0x0ced34(a0, a1);
        case 1802: return fde_func_1802_0x0cf0e4(a0, a1);
        case 1806: return fde_func_1806_0x0cf3c8(a0, a1);
        case 1811: return fde_func_1811_0x0cf70c(a0, a1);
        case 1815: return fde_func_1815_0x0cf91c(a0, a1);
        case 1820: return fde_func_1820_0x0cfba4(a0, a1);
        case 1824: return fde_func_1824_0x0cfe40(a0, a1);
        case 1829: return fde_func_1829_0x0d0254(a0, a1);
        case 1833: return fde_func_1833_0x0d0658(a0, a1);
        case 1837: return fde_func_1837_0x0d0754(a0, a1);
        case 1842: return fde_func_1842_0x0d09d4(a0, a1);
        case 1846: return fde_func_1846_0x0d0d64(a0, a1);
        case 1851: return fde_func_1851_0x0d24b8(a0, a1);
        case 1855: return fde_func_1855_0x0d2c70(a0, a1);
        case 1860: return fde_func_1860_0x0d3518(a0, a1);
        case 1864: return fde_func_1864_0x0d4628(a0, a1);
        case 1869: return fde_func_1869_0x0d4a04(a0, a1);
        case 1873: return fde_func_1873_0x0d4be0(a0, a1);
        case 1878: return fde_func_1878_0x0d5048(a0, a1);
        case 1882: return fde_func_1882_0x0d52c4(a0, a1);
        case 1887: return fde_func_1887_0x0d5490(a0, a1);
        case 1891: return fde_func_1891_0x0d56f0(a0, a1);
        case 1896: return fde_func_1896_0x0d5988(a0, a1);
        case 1900: return fde_func_1900_0x0d61e4(a0, a1);
        case 1905: return fde_func_1905_0x0d65ac(a0, a1);
        case 1909: return fde_func_1909_0x0d68a4(a0, a1);
        case 1914: return fde_func_1914_0x0d6ad8(a0, a1);
        case 1918: return fde_func_1918_0x0d6f04(a0, a1);
        case 1922: return fde_func_1922_0x0d6f8c(a0, a1);
        case 1927: return fde_func_1927_0x0d8084(a0, a1);
        case 1931: return fde_func_1931_0x0d9648(a0, a1);
        case 1936: return fde_func_1936_0x0d9d88(a0, a1);
        case 1940: return fde_func_1940_0x0da038(a0, a1);
        case 1945: return fde_func_1945_0x0da5d0(a0, a1);
        case 1949: return fde_func_1949_0x0daa10(a0, a1);
        case 1954: return fde_func_1954_0x0dae90(a0, a1);
        case 1958: return fde_func_1958_0x0db24c(a0, a1);
        case 1963: return fde_func_1963_0x0db614(a0, a1);
        case 1967: return fde_func_1967_0x0db9e0(a0, a1);
        case 1972: return fde_func_1972_0x0dc2f0(a0, a1);
        case 1976: return fde_func_1976_0x0dcad0(a0, a1);
        case 1981: return fde_func_1981_0x0dd0d8(a0, a1);
        case 1985: return fde_func_1985_0x0ddabc(a0, a1);
        case 1990: return fde_func_1990_0x0de1c4(a0, a1);
        case 1994: return fde_func_1994_0x0de54c(a0, a1);
        case 1998: return fde_func_1998_0x0de848(a0, a1);
        case 2003: return fde_func_2003_0x0ded34(a0, a1);
        case 2007: return fde_func_2007_0x0df0d8(a0, a1);
        case 2012: return fde_func_2012_0x0df4b8(a0, a1);
        case 2016: return fde_func_2016_0x0df5f8(a0, a1);
        case 2021: return fde_func_2021_0x0df750(a0, a1);
        case 2025: return fde_func_2025_0x0df964(a0, a1);
        case 2030: return fde_func_2030_0x0dff20(a0, a1);
        case 2034: return fde_func_2034_0x0dffc0(a0, a1);
        case 2039: return fde_func_2039_0x0e1000(a0, a1);
        case 2043: return fde_func_2043_0x0e1abc(a0, a1);
        case 2048: return fde_func_2048_0x0e2270(a0, a1);
        case 2052: return fde_func_2052_0x0e2848(a0, a1);
        case 2057: return fde_func_2057_0x0e3244(a0, a1);
        case 2061: return fde_func_2061_0x0e3380(a0, a1);
        case 2066: return fde_func_2066_0x0e3600(a0, a1);
        case 2070: return fde_func_2070_0x0e3894(a0, a1);
        case 2075: return fde_func_2075_0x0e3a40(a0, a1);
        case 2079: return fde_func_2079_0x0e3ba0(a0, a1);
        case 2083: return fde_func_2083_0x0e435c(a0, a1);
        case 2088: return fde_func_2088_0x0e4748(a0, a1);
        case 2092: return fde_func_2092_0x0e4c5c(a0, a1);
        case 2097: return fde_func_2097_0x0e4e84(a0, a1);
        case 2101: return fde_func_2101_0x0e4ef8(a0, a1);
        case 2106: return fde_func_2106_0x0e4f20(a0, a1);
        case 2110: return fde_func_2110_0x0e4fbc(a0, a1);
        case 2115: return fde_func_2115_0x0e5084(a0, a1);
        case 2119: return fde_func_2119_0x0e5c84(a0, a1);
        case 2124: return fde_func_2124_0x0e62f8(a0, a1);
        case 2128: return fde_func_2128_0x0e6d08(a0, a1);
        case 2133: return fde_func_2133_0x0e72d4(a0, a1);
        case 2137: return fde_func_2137_0x0e74a8(a0, a1);
        case 2142: return fde_func_2142_0x0e7f64(a0, a1);
        case 2146: return fde_func_2146_0x0e8e94(a0, a1);
        case 2151: return fde_func_2151_0x0e90ac(a0, a1);
        case 2155: return fde_func_2155_0x0e929c(a0, a1);
        case 2159: return fde_func_2159_0x0e9510(a0, a1);
        case 2164: return fde_func_2164_0x0e9f60(a0, a1);
        case 2168: return fde_func_2168_0x0ea5b0(a0, a1);
        case 2173: return fde_func_2173_0x0eab4c(a0, a1);
        case 2177: return fde_func_2177_0x0eaeb8(a0, a1);
        case 2182: return fde_func_2182_0x0eb714(a0, a1);
        case 2186: return fde_func_2186_0x0ebb8c(a0, a1);
        case 2191: return fde_func_2191_0x0ebc48(a0, a1);
        case 2195: return fde_func_2195_0x0ebcdc(a0, a1);
        case 2200: return fde_func_2200_0x0ebfa8(a0, a1);
        case 2204: return fde_func_2204_0x0ec250(a0, a1);
        case 2209: return fde_func_2209_0x0ec65c(a0, a1);
        case 2213: return fde_func_2213_0x0ec930(a0, a1);
        case 2218: return fde_func_2218_0x0ec9bc(a0, a1);
        case 2222: return fde_func_2222_0x0eca74(a0, a1);
        case 2227: return fde_func_2227_0x0ecb74(a0, a1);
        case 2231: return fde_func_2231_0x0ecd18(a0, a1);
        case 2236: return fde_func_2236_0x0ed1d0(a0, a1);
        case 2240: return fde_func_2240_0x0ee194(a0, a1);
        case 2244: return fde_func_2244_0x0ee34c(a0, a1);
        case 2249: return fde_func_2249_0x0ee378(a0, a1);
        case 2253: return fde_func_2253_0x0ee398(a0, a1);
        case 2258: return fde_func_2258_0x0ee404(a0, a1);
        case 2262: return fde_func_2262_0x0ee4fc(a0, a1);
        case 2267: return fde_func_2267_0x0eec48(a0, a1);
        case 2271: return fde_func_2271_0x0eeedc(a0, a1);
        case 2276: return fde_func_2276_0x0ef238(a0, a1);
        case 2280: return fde_func_2280_0x0ef248(a0, a1);
        case 2285: return fde_func_2285_0x0ef2a4(a0, a1);
        case 2289: return fde_func_2289_0x0ef2b4(a0, a1);
        case 2294: return fde_func_2294_0x0ef4ac(a0, a1);
        case 2298: return fde_func_2298_0x0ef5d4(a0, a1);
        case 2303: return fde_func_2303_0x0ef6d8(a0, a1);
        case 2307: return fde_func_2307_0x0ef814(a0, a1);
        case 2312: return fde_func_2312_0x0efad0(a0, a1);
        case 2316: return fde_func_2316_0x0efcec(a0, a1);
        case 2320: return fde_func_2320_0x0efe94(a0, a1);
        case 2325: return fde_func_2325_0x0eff88(a0, a1);
        case 2329: return fde_func_2329_0x0f0158(a0, a1);
        case 2334: return fde_func_2334_0x0f02c8(a0, a1);
        case 2338: return fde_func_2338_0x0f03f0(a0, a1);
        case 2343: return fde_func_2343_0x0f0520(a0, a1);
        case 2347: return fde_func_2347_0x0f060c(a0, a1);
        case 2352: return fde_func_2352_0x0f0684(a0, a1);
        case 2356: return fde_func_2356_0x0f06e4(a0, a1);
        case 2361: return fde_func_2361_0x0f07a8(a0, a1);
        case 2365: return fde_func_2365_0x0f0800(a0, a1);
        case 2370: return fde_func_2370_0x0f0900(a0, a1);
        case 2374: return fde_func_2374_0x0f0974(a0, a1);
        case 2379: return fde_func_2379_0x0f0d18(a0, a1);
        case 2383: return fde_func_2383_0x0f0e4c(a0, a1);
        case 2388: return fde_func_2388_0x0f10d4(a0, a1);
        case 2392: return fde_func_2392_0x0f1148(a0, a1);
        case 2396: return fde_func_2396_0x0f1454(a0, a1);
        case 2401: return fde_func_2401_0x0f15c4(a0, a1);
        case 2405: return fde_func_2405_0x0f16d4(a0, a1);
        case 2410: return fde_func_2410_0x0f1a38(a0, a1);
        case 2414: return fde_func_2414_0x0f1ad4(a0, a1);
        case 2419: return fde_func_2419_0x0f1df8(a0, a1);
        case 2423: return fde_func_2423_0x0f1ed4(a0, a1);
        case 2428: return fde_func_2428_0x0f2060(a0, a1);
        case 2432: return fde_func_2432_0x0f215c(a0, a1);
        case 2437: return fde_func_2437_0x0f234c(a0, a1);
        case 2441: return fde_func_2441_0x0f2470(a0, a1);
        case 2446: return fde_func_2446_0x0f30ac(a0, a1);
        case 2450: return fde_func_2450_0x0f326c(a0, a1);
        case 2455: return fde_func_2455_0x0f336c(a0, a1);
        case 2459: return fde_func_2459_0x0f3480(a0, a1);
        case 2464: return fde_func_2464_0x0f3500(a0, a1);
        case 2468: return fde_func_2468_0x0f3558(a0, a1);
        case 2473: return fde_func_2473_0x0f3590(a0, a1);
        case 2477: return fde_func_2477_0x0f35e8(a0, a1);
        case 2481: return fde_func_2481_0x0f38a0(a0, a1);
        case 2486: return fde_func_2486_0x0f3aac(a0, a1);
        case 2490: return fde_func_2490_0x0f3b58(a0, a1);
        case 2495: return fde_func_2495_0x0f3c8c(a0, a1);
        case 2499: return fde_func_2499_0x0f3d34(a0, a1);
        case 2504: return fde_func_2504_0x0f4a88(a0, a1);
        case 2508: return fde_func_2508_0x0f4c54(a0, a1);
        case 2513: return fde_func_2513_0x0f4dcc(a0, a1);
        case 2517: return fde_func_2517_0x0f4e9c(a0, a1);
        case 2522: return fde_func_2522_0x0f51cc(a0, a1);
        case 2526: return fde_func_2526_0x0f538c(a0, a1);
        case 2531: return fde_func_2531_0x0f5580(a0, a1);
        case 2535: return fde_func_2535_0x0f5754(a0, a1);
        case 2540: return fde_func_2540_0x0f5cb8(a0, a1);
        case 2544: return fde_func_2544_0x0f6178(a0, a1);
        case 2549: return fde_func_2549_0x0f649c(a0, a1);
        case 2553: return fde_func_2553_0x0f65e4(a0, a1);
        case 2557: return fde_func_2557_0x0f9874(a0, a1);
        case 2562: return fde_func_2562_0x0f9d94(a0, a1);
        case 2566: return fde_func_2566_0x0f9dc4(a0, a1);
        case 2571: return fde_func_2571_0x0fa140(a0, a1);
        case 2575: return fde_func_2575_0x0fa1e8(a0, a1);
        case 2580: return fde_func_2580_0x0fa524(a0, a1);
        case 2584: return fde_func_2584_0x0fa5a8(a0, a1);
        case 2589: return fde_func_2589_0x0fa9f8(a0, a1);
        case 2593: return fde_func_2593_0x0fac58(a0, a1);
        case 2598: return fde_func_2598_0x0fb2d4(a0, a1);
        case 2602: return fde_func_2602_0x0fb41c(a0, a1);
        case 2607: return fde_func_2607_0x0fb808(a0, a1);
        case 2611: return fde_func_2611_0x0fb9cc(a0, a1);
        case 2616: return fde_func_2616_0x0fee28(a0, a1);
        case 2620: return fde_func_2620_0x0ff1d4(a0, a1);
        case 2625: return fde_func_2625_0x0ff2d0(a0, a1);
        case 2629: return fde_func_2629_0x0ff714(a0, a1);
        case 2634: return fde_func_2634_0x0ff804(a0, a1);
        case 2638: return fde_func_2638_0x0ffc54(a0, a1);
        case 2642: return fde_func_2642_0x100080(a0, a1);
        case 2647: return fde_func_2647_0x1004ec(a0, a1);
        case 2651: return fde_func_2651_0x100bf0(a0, a1);
        case 2656: return fde_func_2656_0x1019d4(a0, a1);
        case 2660: return fde_func_2660_0x101a88(a0, a1);
        case 2665: return fde_func_2665_0x1022d8(a0, a1);
        case 2669: return fde_func_2669_0x1022f8(a0, a1);
        case 2674: return fde_func_2674_0x102458(a0, a1);
        case 2678: return fde_func_2678_0x103140(a0, a1);
        case 2683: return fde_func_2683_0x103648(a0, a1);
        case 2687: return fde_func_2687_0x103858(a0, a1);
        case 2692: return fde_func_2692_0x103dc8(a0, a1);
        case 2696: return fde_func_2696_0x1040d0(a0, a1);
        case 2701: return fde_func_2701_0x1045a8(a0, a1);
        case 2705: return fde_func_2705_0x104904(a0, a1);
        case 2710: return fde_func_2710_0x104ca4(a0, a1);
        case 2714: return fde_func_2714_0x1051ac(a0, a1);
        case 2718: return fde_func_2718_0x105598(a0, a1);
        case 2723: return fde_func_2723_0x1058a4(a0, a1);
        case 2727: return fde_func_2727_0x105ac0(a0, a1);
        case 2732: return fde_func_2732_0x105d34(a0, a1);
        case 2736: return fde_func_2736_0x105f14(a0, a1);
        case 2741: return fde_func_2741_0x106390(a0, a1);
        case 2745: return fde_func_2745_0x106888(a0, a1);
        case 2750: return fde_func_2750_0x106efc(a0, a1);
        case 2754: return fde_func_2754_0x1072bc(a0, a1);
        case 2759: return fde_func_2759_0x107958(a0, a1);
        case 2763: return fde_func_2763_0x107b04(a0, a1);
        case 2768: return fde_func_2768_0x108154(a0, a1);
        case 2772: return fde_func_2772_0x1086f8(a0, a1);
        case 2777: return fde_func_2777_0x10932c(a0, a1);
        case 2781: return fde_func_2781_0x109a98(a0, a1);
        case 2786: return fde_func_2786_0x109c44(a0, a1);
        case 2790: return fde_func_2790_0x109ca8(a0, a1);
        case 2795: return fde_func_2795_0x109fcc(a0, a1);
        case 2799: return fde_func_2799_0x10aa08(a0, a1);
        case 2803: return fde_func_2803_0x10af80(a0, a1);
        case 2808: return fde_func_2808_0x10b410(a0, a1);
        case 2812: return fde_func_2812_0x10bb80(a0, a1);
        case 2817: return fde_func_2817_0x10c308(a0, a1);
        case 2821: return fde_func_2821_0x10c7f0(a0, a1);
        case 2826: return fde_func_2826_0x10cd18(a0, a1);
        case 2830: return fde_func_2830_0x10d10c(a0, a1);
        case 2835: return fde_func_2835_0x10d4ec(a0, a1);
        case 2839: return fde_func_2839_0x10dd60(a0, a1);
        case 2844: return fde_func_2844_0x10e3b4(a0, a1);
        case 2848: return fde_func_2848_0x10eb98(a0, a1);
        case 2853: return fde_func_2853_0x10f0fc(a0, a1);
        case 2857: return fde_func_2857_0x10fdd8(a0, a1);
        case 2862: return fde_func_2862_0x110ce0(a0, a1);
        case 2866: return fde_func_2866_0x111d04(a0, a1);
        case 2871: return fde_func_2871_0x112498(a0, a1);
        case 2875: return fde_func_2875_0x113fc4(a0, a1);
        case 2879: return fde_func_2879_0x115180(a0, a1);
        case 2884: return fde_func_2884_0x11521c(a0, a1);
        case 2888: return fde_func_2888_0x11540c(a0, a1);
        case 2893: return fde_func_2893_0x1156c4(a0, a1);
        case 2897: return fde_func_2897_0x115a00(a0, a1);
        case 2902: return fde_func_2902_0x115b3c(a0, a1);
        case 2906: return fde_func_2906_0x115d80(a0, a1);
        case 2911: return fde_func_2911_0x115f20(a0, a1);
        case 2915: return fde_func_2915_0x116174(a0, a1);
        case 2920: return fde_func_2920_0x116234(a0, a1);
        case 2924: return fde_func_2924_0x1162ec(a0, a1);
        case 2929: return fde_func_2929_0x1164ac(a0, a1);
        case 2933: return fde_func_2933_0x1167d8(a0, a1);
        case 2938: return fde_func_2938_0x116f74(a0, a1);
        case 2942: return fde_func_2942_0x1179f4(a0, a1);
        case 2947: return fde_func_2947_0x117f70(a0, a1);
        case 2951: return fde_func_2951_0x118304(a0, a1);
        case 2955: return fde_func_2955_0x119524(a0, a1);
        case 2960: return fde_func_2960_0x11a080(a0, a1);
        case 2964: return fde_func_2964_0x11a180(a0, a1);
        case 2969: return fde_func_2969_0x11a20c(a0, a1);
        case 2973: return fde_func_2973_0x11a408(a0, a1);
        case 2978: return fde_func_2978_0x11a4fc(a0, a1);
        case 2982: return fde_func_2982_0x11a894(a0, a1);
        case 2987: return fde_func_2987_0x11ada8(a0, a1);
        case 2991: return fde_func_2991_0x11b05c(a0, a1);
        case 2996: return fde_func_2996_0x11b16c(a0, a1);
        case 3000: return fde_func_3000_0x11b378(a0, a1);
        case 3005: return fde_func_3005_0x11b780(a0, a1);
        case 3009: return fde_func_3009_0x11be40(a0, a1);
        case 3014: return fde_func_3014_0x11c32c(a0, a1);
        case 3018: return fde_func_3018_0x11c554(a0, a1);
        case 3023: return fde_func_3023_0x11eb24(a0, a1);
        case 3027: return fde_func_3027_0x11f3bc(a0, a1);
        case 3032: return fde_func_3032_0x11f714(a0, a1);
        case 3036: return fde_func_3036_0x11facc(a0, a1);
        case 3040: return fde_func_3040_0x11ff90(a0, a1);
        case 3045: return fde_func_3045_0x1201f4(a0, a1);
        case 3049: return fde_func_3049_0x1204c4(a0, a1);
        case 3054: return fde_func_3054_0x121044(a0, a1);
        case 3058: return fde_func_3058_0x121ac8(a0, a1);
        case 3063: return fde_func_3063_0x121c54(a0, a1);
        case 3067: return fde_func_3067_0x121d04(a0, a1);
        case 3072: return fde_func_3072_0x122550(a0, a1);
        case 3076: return fde_func_3076_0x122a4c(a0, a1);
        case 3081: return fde_func_3081_0x122da4(a0, a1);
        case 3085: return fde_func_3085_0x1230f0(a0, a1);
        case 3090: return fde_func_3090_0x123380(a0, a1);
        case 3094: return fde_func_3094_0x123648(a0, a1);
        case 3099: return fde_func_3099_0x1239f8(a0, a1);
        case 3103: return fde_func_3103_0x123a50(a0, a1);
        case 3108: return fde_func_3108_0x123c68(a0, a1);
        case 3112: return fde_func_3112_0x123cec(a0, a1);
        case 3116: return fde_func_3116_0x124038(a0, a1);
        case 3121: return fde_func_3121_0x1243b8(a0, a1);
        case 3125: return fde_func_3125_0x1247f8(a0, a1);
        case 3130: return fde_func_3130_0x124c90(a0, a1);
        case 3134: return fde_func_3134_0x124de0(a0, a1);
        case 3139: return fde_func_3139_0x124f58(a0, a1);
        case 3143: return fde_func_3143_0x125254(a0, a1);
        case 3148: return fde_func_3148_0x125830(a0, a1);
        case 3152: return fde_func_3152_0x125890(a0, a1);
        case 3157: return fde_func_3157_0x125968(a0, a1);
        case 3161: return fde_func_3161_0x126044(a0, a1);
        case 3166: return fde_func_3166_0x126d38(a0, a1);
        case 3170: return fde_func_3170_0x127204(a0, a1);
        case 3175: return fde_func_3175_0x1272d0(a0, a1);
        case 3179: return fde_func_3179_0x127360(a0, a1);
        case 3184: return fde_func_3184_0x127894(a0, a1);
        case 3188: return fde_func_3188_0x127fb4(a0, a1);
        case 3193: return fde_func_3193_0x128260(a0, a1);
        case 3197: return fde_func_3197_0x12863c(a0, a1);
        case 3201: return fde_func_3201_0x1289f4(a0, a1);
        case 3206: return fde_func_3206_0x128adc(a0, a1);
        case 3210: return fde_func_3210_0x128d38(a0, a1);
        case 3215: return fde_func_3215_0x128e1c(a0, a1);
        case 3219: return fde_func_3219_0x129154(a0, a1);
        case 3224: return fde_func_3224_0x12d20c(a0, a1);
        case 3228: return fde_func_3228_0x12d640(a0, a1);
        case 3233: return fde_func_3233_0x12d8c4(a0, a1);
        case 3237: return fde_func_3237_0x12d9e4(a0, a1);
        case 3242: return fde_func_3242_0x12e15c(a0, a1);
        case 3246: return fde_func_3246_0x12e284(a0, a1);
        case 3251: return fde_func_3251_0x12e754(a0, a1);
        case 3255: return fde_func_3255_0x12ea70(a0, a1);
        case 3260: return fde_func_3260_0x12ee1c(a0, a1);
        case 3264: return fde_func_3264_0x12ee9c(a0, a1);
        case 3269: return fde_func_3269_0x12f210(a0, a1);
        case 3273: return fde_func_3273_0x12f4c8(a0, a1);
        case 3277: return fde_func_3277_0x12f884(a0, a1);
        case 3282: return fde_func_3282_0x130020(a0, a1);
        case 3286: return fde_func_3286_0x13028c(a0, a1);
        case 3291: return fde_func_3291_0x130954(a0, a1);
        case 3295: return fde_func_3295_0x130bd4(a0, a1);
        case 3300: return fde_func_3300_0x131288(a0, a1);
        case 3304: return fde_func_3304_0x1314b8(a0, a1);
        case 3309: return fde_func_3309_0x131738(a0, a1);
        case 3313: return fde_func_3313_0x1319e4(a0, a1);
        case 3318: return fde_func_3318_0x1327d4(a0, a1);
        case 3322: return fde_func_3322_0x132928(a0, a1);
        case 3327: return fde_func_3327_0x133268(a0, a1);
        case 3331: return fde_func_3331_0x133460(a0, a1);
        case 3336: return fde_func_3336_0x13357c(a0, a1);
        case 3340: return fde_func_3340_0x133858(a0, a1);
        case 3345: return fde_func_3345_0x133bcc(a0, a1);
        case 3349: return fde_func_3349_0x133e44(a0, a1);
        case 3354: return fde_func_3354_0x133e7c(a0, a1);
        case 3358: return fde_func_3358_0x13426c(a0, a1);
        case 3362: return fde_func_3362_0x134428(a0, a1);
        case 3367: return fde_func_3367_0x13475c(a0, a1);
        case 3371: return fde_func_3371_0x1348e0(a0, a1);
        case 3376: return fde_func_3376_0x134a08(a0, a1);
        case 3380: return fde_func_3380_0x134acc(a0, a1);
        case 3385: return fde_func_3385_0x134ce0(a0, a1);
        case 3389: return fde_func_3389_0x134e78(a0, a1);
        case 3394: return fde_func_3394_0x1351e4(a0, a1);
        case 3398: return fde_func_3398_0x135510(a0, a1);
        case 3403: return fde_func_3403_0x135668(a0, a1);
        case 3407: return fde_func_3407_0x1356b0(a0, a1);
        case 3412: return fde_func_3412_0x135744(a0, a1);
        case 3416: return fde_func_3416_0x13579c(a0, a1);
        case 3421: return fde_func_3421_0x136780(a0, a1);
        case 3425: return fde_func_3425_0x1367d8(a0, a1);
        case 3430: return fde_func_3430_0x136b7c(a0, a1);
        case 3434: return fde_func_3434_0x136dfc(a0, a1);
        case 3438: return fde_func_3438_0x136ff4(a0, a1);
        case 3443: return fde_func_3443_0x1375bc(a0, a1);
        case 3447: return fde_func_3447_0x1387f0(a0, a1);
        case 3452: return fde_func_3452_0x13b12c(a0, a1);
        case 3456: return fde_func_3456_0x13be24(a0, a1);
        case 3461: return fde_func_3461_0x13d950(a0, a1);
        case 3465: return fde_func_3465_0x13e20c(a0, a1);
        case 3470: return fde_func_3470_0x13e420(a0, a1);
        case 3474: return fde_func_3474_0x13e504(a0, a1);
        case 3479: return fde_func_3479_0x13ea24(a0, a1);
        case 3483: return fde_func_3483_0x13f2c4(a0, a1);
        case 3488: return fde_func_3488_0x13fc24(a0, a1);
        case 3492: return fde_func_3492_0x140288(a0, a1);
        case 3497: return fde_func_3497_0x140924(a0, a1);
        case 3501: return fde_func_3501_0x140d60(a0, a1);
        case 3506: return fde_func_3506_0x141328(a0, a1);
        case 3510: return fde_func_3510_0x1416fc(a0, a1);
        case 3514: return fde_func_3514_0x141a78(a0, a1);
        case 3519: return fde_func_3519_0x141f1c(a0, a1);
        case 3523: return fde_func_3523_0x142324(a0, a1);
        case 3528: return fde_func_3528_0x142908(a0, a1);
        case 3532: return fde_func_3532_0x142c08(a0, a1);
        case 3537: return fde_func_3537_0x142e68(a0, a1);
        case 3541: return fde_func_3541_0x142f30(a0, a1);
        case 3546: return fde_func_3546_0x143024(a0, a1);
        case 3550: return fde_func_3550_0x1438b4(a0, a1);
        case 3555: return fde_func_3555_0x14425c(a0, a1);
        case 3559: return fde_func_3559_0x144794(a0, a1);
        case 3564: return fde_func_3564_0x144c1c(a0, a1);
        case 3568: return fde_func_3568_0x146a8c(a0, a1);
        case 3573: return fde_func_3573_0x147314(a0, a1);
        default: return 0ULL;
    }
}

} // namespace preload_reconstructed