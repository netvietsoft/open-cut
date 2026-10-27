// ============================================================================
// Clean-Room C++17 AArch64 FDE Shard 4/5 for libnuro.so
// Phân mảnh FDE AArch64 C++17 sạch 4/5 cho libnuro.so
// Covers FDE indices [1101 .. 1467] out of 1,835 total FDEs (.eh_frame_hdr @ 0x0b8c58)
// Bao phủ chỉ số FDE [1101 .. 1467] trên tổng số 1,835 FDE (.eh_frame_hdr @ 0x0b8c58)
// ============================================================================
#include "nuro_core.h"

namespace nuro {

// FDE #1101 | PC: 0x07b498 | FDE: 0x0c5b38 | Size: 256 bytes
// Hàm FDE #1101 | Địa chỉ PC: 0x07b498 | Địa chỉ FDE: 0x0c5b38 | Kích thước: 256 bytes
//   0x07b498: D10283FF  sub      sp, sp, #0xa0
//   0x07b49c: F90033F7  str      x23, [sp, #0x60]
//   0x07b4a0: A90757F6  stp      x22, x21, [sp, #0x70]
//   0x07b4a4: A9084FF4  stp      x20, x19, [sp, #0x80]
static inline uint64_t fde_func_1101_0x07b498(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07b498ULL ^ (static_cast<uint64_t>(0xd10283ffULL) << 13);
    acc = (acc + a1 + 0xf90033f7ULL) ^ 0x0c5b38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1102 | PC: 0x07b674 | FDE: 0x0c5b68 | Size: 184 bytes
// Hàm FDE #1102 | Địa chỉ PC: 0x07b674 | Địa chỉ FDE: 0x0c5b68 | Kích thước: 184 bytes
//   0x07b674: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x07b678: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x07b67c: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x07b680: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1102_0x07b674(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07b674ULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x0c5b68ULL;
    acc ^= (acc >> 17) * 0x00b8ULL;
    return acc;
}

// FDE #1103 | PC: 0x07b72c | FDE: 0x0c5b90 | Size: 256 bytes
// Hàm FDE #1103 | Địa chỉ PC: 0x07b72c | Địa chỉ FDE: 0x0c5b90 | Kích thước: 256 bytes
//   0x07b72c: A9BB67FA  stp      x26, x25, [sp, #-0x50]!
//   0x07b730: A9015FF8  stp      x24, x23, [sp, #0x10]
//   0x07b734: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x07b738: A9034FF4  stp      x20, x19, [sp, #0x30]
static inline uint64_t fde_func_1103_0x07b72c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07b72cULL ^ (static_cast<uint64_t>(0xa9bb67faULL) << 13);
    acc = (acc + a1 + 0xa9015ff8ULL) ^ 0x0c5b90ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1104 | PC: 0x07b93c | FDE: 0x0c5bc8 | Size: 256 bytes
// Hàm FDE #1104 | Địa chỉ PC: 0x07b93c | Địa chỉ FDE: 0x0c5bc8 | Kích thước: 256 bytes
//   0x07b93c: D10243FF  sub      sp, sp, #0x90
//   0x07b940: A9055FF8  stp      x24, x23, [sp, #0x50]
//   0x07b944: A90657F6  stp      x22, x21, [sp, #0x60]
//   0x07b948: A9074FF4  stp      x20, x19, [sp, #0x70]
static inline uint64_t fde_func_1104_0x07b93c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07b93cULL ^ (static_cast<uint64_t>(0xd10243ffULL) << 13);
    acc = (acc + a1 + 0xa9055ff8ULL) ^ 0x0c5bc8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1105 | PC: 0x07bb78 | FDE: 0x0c5bf8 | Size: 256 bytes
// Hàm FDE #1105 | Địa chỉ PC: 0x07bb78 | Địa chỉ FDE: 0x0c5bf8 | Kích thước: 256 bytes
//   0x07bb78: D10283FF  sub      sp, sp, #0xa0
//   0x07bb7c: A90567FA  stp      x26, x25, [sp, #0x50]
//   0x07bb80: A9065FF8  stp      x24, x23, [sp, #0x60]
//   0x07bb84: A90757F6  stp      x22, x21, [sp, #0x70]
static inline uint64_t fde_func_1105_0x07bb78(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07bb78ULL ^ (static_cast<uint64_t>(0xd10283ffULL) << 13);
    acc = (acc + a1 + 0xa90567faULL) ^ 0x0c5bf8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1106 | PC: 0x07be24 | FDE: 0x0c5c30 | Size: 256 bytes
// Hàm FDE #1106 | Địa chỉ PC: 0x07be24 | Địa chỉ FDE: 0x0c5c30 | Kích thước: 256 bytes
//   0x07be24: D10183FF  sub      sp, sp, #0x60
//   0x07be28: F9001BF5  str      x21, [sp, #0x30]
//   0x07be2c: A9044FF4  stp      x20, x19, [sp, #0x40]
//   0x07be30: A9057BFD  stp      x29, x30, [sp, #0x50]
static inline uint64_t fde_func_1106_0x07be24(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07be24ULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xf9001bf5ULL) ^ 0x0c5c30ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1107 | PC: 0x07bf8c | FDE: 0x0c5db8 | Size: 256 bytes
// Hàm FDE #1107 | Địa chỉ PC: 0x07bf8c | Địa chỉ FDE: 0x0c5db8 | Kích thước: 256 bytes
//   0x07bf8c: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x07bf90: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x07bf94: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x07bf98: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1107_0x07bf8c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07bf8cULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x0c5db8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1108 | PC: 0x07c188 | FDE: 0x0c5c58 | Size: 128 bytes
// Hàm FDE #1108 | Địa chỉ PC: 0x07c188 | Địa chỉ FDE: 0x0c5c58 | Kích thước: 128 bytes
//   0x07c188: D100C3FF  sub      sp, sp, #0x30
//   0x07c18c: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x07c190: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x07c194: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1108_0x07c188(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07c188ULL ^ (static_cast<uint64_t>(0xd100c3ffULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x0c5c58ULL;
    acc ^= (acc >> 17) * 0x0080ULL;
    return acc;
}

// FDE #1109 | PC: 0x07c208 | FDE: 0x0c5c78 | Size: 256 bytes
// Hàm FDE #1109 | Địa chỉ PC: 0x07c208 | Địa chỉ FDE: 0x0c5c78 | Kích thước: 256 bytes
//   0x07c208: D10183FF  sub      sp, sp, #0x60
//   0x07c20c: F90013F7  str      x23, [sp, #0x20]
//   0x07c210: A90357F6  stp      x22, x21, [sp, #0x30]
//   0x07c214: A9044FF4  stp      x20, x19, [sp, #0x40]
static inline uint64_t fde_func_1109_0x07c208(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07c208ULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xf90013f7ULL) ^ 0x0c5c78ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1110 | PC: 0x07c3ac | FDE: 0x0c5ca0 | Size: 256 bytes
// Hàm FDE #1110 | Địa chỉ PC: 0x07c3ac | Địa chỉ FDE: 0x0c5ca0 | Kích thước: 256 bytes
//   0x07c3ac: D10103FF  sub      sp, sp, #0x40
//   0x07c3b0: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x07c3b4: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x07c3b8: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_1110_0x07c3ac(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07c3acULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x0c5ca0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1111 | PC: 0x07c4b0 | FDE: 0x0c5cc8 | Size: 120 bytes
// Hàm FDE #1111 | Địa chỉ PC: 0x07c4b0 | Địa chỉ FDE: 0x0c5cc8 | Kích thước: 120 bytes
//   0x07c4b0: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x07c4b4: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x07c4b8: 910043FD  add      x29, sp, #0x10
//   0x07c4bc: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_1111_0x07c4b0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07c4b0ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x0c5cc8ULL;
    acc ^= (acc >> 17) * 0x0078ULL;
    return acc;
}

// FDE #1112 | PC: 0x07c528 | FDE: 0x0c5ce8 | Size: 168 bytes
// Hàm FDE #1112 | Địa chỉ PC: 0x07c528 | Địa chỉ FDE: 0x0c5ce8 | Kích thước: 168 bytes
//   0x07c528: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x07c52c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x07c530: 910043FD  add      x29, sp, #0x10
//   0x07c534: F9401014  ldr      x20, [x0, #0x20]
static inline uint64_t fde_func_1112_0x07c528(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07c528ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x0c5ce8ULL;
    acc ^= (acc >> 17) * 0x00a8ULL;
    return acc;
}

// FDE #1113 | PC: 0x07c5d0 | FDE: 0x0c5d08 | Size: 168 bytes
// Hàm FDE #1113 | Địa chỉ PC: 0x07c5d0 | Địa chỉ FDE: 0x0c5d08 | Kích thước: 168 bytes
//   0x07c5d0: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x07c5d4: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x07c5d8: 910043FD  add      x29, sp, #0x10
//   0x07c5dc: F9401014  ldr      x20, [x0, #0x20]
static inline uint64_t fde_func_1113_0x07c5d0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07c5d0ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x0c5d08ULL;
    acc ^= (acc >> 17) * 0x00a8ULL;
    return acc;
}

// FDE #1114 | PC: 0x07c678 | FDE: 0x0c5d28 | Size: 48 bytes
// Hàm FDE #1114 | Địa chỉ PC: 0x07c678 | Địa chỉ FDE: 0x0c5d28 | Kích thước: 48 bytes
//   0x07c678: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x07c67c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x07c680: 910043FD  add      x29, sp, #0x10
//   0x07c684: D0000368  adrp     x8, #0xea000
static inline uint64_t fde_func_1114_0x07c678(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07c678ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x0c5d28ULL;
    acc ^= (acc >> 17) * 0x0030ULL;
    return acc;
}

// FDE #1115 | PC: 0x07c6a8 | FDE: 0x0c5d48 | Size: 56 bytes
// Hàm FDE #1115 | Địa chỉ PC: 0x07c6a8 | Địa chỉ FDE: 0x0c5d48 | Kích thước: 56 bytes
//   0x07c6a8: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x07c6ac: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x07c6b0: 910043FD  add      x29, sp, #0x10
//   0x07c6b4: D0000368  adrp     x8, #0xea000
static inline uint64_t fde_func_1115_0x07c6a8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07c6a8ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x0c5d48ULL;
    acc ^= (acc >> 17) * 0x0038ULL;
    return acc;
}

// FDE #1116 | PC: 0x07c6e0 | FDE: 0x0c5d68 | Size: 8 bytes
// Hàm FDE #1116 | Địa chỉ PC: 0x07c6e0 | Địa chỉ FDE: 0x0c5d68 | Kích thước: 8 bytes
//   0x07c6e0: 91006000  add      x0, x0, #0x18
//   0x07c6e4: 14000002  b        #0x7c6ec
static inline uint64_t fde_func_1116_0x07c6e0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07c6e0ULL ^ (static_cast<uint64_t>(0x91006000ULL) << 13);
    acc = (acc + a1 + 0x14000002ULL) ^ 0x0c5d68ULL;
    acc ^= (acc >> 17) * 0x0008ULL;
    return acc;
}

// FDE #1117 | PC: 0x07c6e8 | FDE: 0x0c5d80 | Size: 4 bytes
// Hàm FDE #1117 | Địa chỉ PC: 0x07c6e8 | Địa chỉ FDE: 0x0c5d80 | Kích thước: 4 bytes
//   0x07c6e8: 17FE5846  b        #0x12800
static inline uint64_t fde_func_1117_0x07c6e8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07c6e8ULL ^ (static_cast<uint64_t>(0x17fe5846ULL) << 13);
    acc = (acc + a1 + 0xf81e0ff3ULL) ^ 0x0c5d80ULL;
    acc ^= (acc >> 17) * 0x0004ULL;
    return acc;
}

// FDE #1118 | PC: 0x07c6ec | FDE: 0x0c5d98 | Size: 156 bytes
// Hàm FDE #1118 | Địa chỉ PC: 0x07c6ec | Địa chỉ FDE: 0x0c5d98 | Kích thước: 156 bytes
//   0x07c6ec: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x07c6f0: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x07c6f4: 910043FD  add      x29, sp, #0x10
//   0x07c6f8: 3942A008  ldrb     w8, [x0, #0xa8]
static inline uint64_t fde_func_1118_0x07c6ec(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07c6ecULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x0c5d98ULL;
    acc ^= (acc >> 17) * 0x009cULL;
    return acc;
}

// FDE #1119 | PC: 0x07c788 | FDE: 0x0c5de0 | Size: 44 bytes
// Hàm FDE #1119 | Địa chỉ PC: 0x07c788 | Địa chỉ FDE: 0x0c5de0 | Kích thước: 44 bytes
//   0x07c788: 2A0003E9  mov      w9, w0
//   0x07c78c: 7100081F  cmp      w0, #2
//   0x07c790: AA0803E0  mov      x0, x8
//   0x07c794: 540000A8  b.hi     #0x7c7a8
static inline uint64_t fde_func_1119_0x07c788(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07c788ULL ^ (static_cast<uint64_t>(0x2a0003e9ULL) << 13);
    acc = (acc + a1 + 0x7100081fULL) ^ 0x0c5de0ULL;
    acc ^= (acc >> 17) * 0x002cULL;
    return acc;
}

// FDE #1120 | PC: 0x07c7b4 | FDE: 0x0c5df8 | Size: 84 bytes [_ZN4nuro11SyncChannel6createERKNS_18SyncChannelOptionsE]
// Hàm FDE #1120 | Địa chỉ PC: 0x07c7b4 | Địa chỉ FDE: 0x0c5df8 | Kích thước: 84 bytes
//   0x07c7b4: D10103FF  sub      sp, sp, #0x40
//   0x07c7b8: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x07c7bc: A9037BFD  stp      x29, x30, [sp, #0x30]
//   0x07c7c0: 9100C3FD  add      x29, sp, #0x30
static inline uint64_t fde_func_1120_0x07c7b4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07c7b4ULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xa9024ff4ULL) ^ 0x0c5df8ULL;
    acc ^= (acc >> 17) * 0x0054ULL;
    return acc;
}

// FDE #1121 | PC: 0x07c808 | FDE: 0x0c6038 | Size: 256 bytes
// Hàm FDE #1121 | Địa chỉ PC: 0x07c808 | Địa chỉ FDE: 0x0c6038 | Kích thước: 256 bytes
//   0x07c808: A9BC5FF8  stp      x24, x23, [sp, #-0x40]!
//   0x07c80c: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x07c810: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x07c814: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_1121_0x07c808(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07c808ULL ^ (static_cast<uint64_t>(0xa9bc5ff8ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x0c6038ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1122 | PC: 0x07c90c | FDE: 0x0c5e18 | Size: 48 bytes
// Hàm FDE #1122 | Địa chỉ PC: 0x07c90c | Địa chỉ FDE: 0x0c5e18 | Kích thước: 48 bytes
//   0x07c90c: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x07c910: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x07c914: 910043FD  add      x29, sp, #0x10
//   0x07c918: D0000368  adrp     x8, #0xea000
static inline uint64_t fde_func_1122_0x07c90c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07c90cULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x0c5e18ULL;
    acc ^= (acc >> 17) * 0x0030ULL;
    return acc;
}

// FDE #1123 | PC: 0x07c93c | FDE: 0x0c5e38 | Size: 56 bytes
// Hàm FDE #1123 | Địa chỉ PC: 0x07c93c | Địa chỉ FDE: 0x0c5e38 | Kích thước: 56 bytes
//   0x07c93c: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x07c940: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x07c944: 910043FD  add      x29, sp, #0x10
//   0x07c948: D0000368  adrp     x8, #0xea000
static inline uint64_t fde_func_1123_0x07c93c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07c93cULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x0c5e38ULL;
    acc ^= (acc >> 17) * 0x0038ULL;
    return acc;
}

// FDE #1124 | PC: 0x07c974 | FDE: 0x0c5e58 | Size: 12 bytes
// Hàm FDE #1124 | Địa chỉ PC: 0x07c974 | Địa chỉ FDE: 0x0c5e58 | Kích thước: 12 bytes
//   0x07c974: F8418C08  ldr      x8, [x0, #0x18]!
//   0x07c978: F9400101  ldr      x1, [x8]
//   0x07c97c: D61F0020  br       x1
static inline uint64_t fde_func_1124_0x07c974(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07c974ULL ^ (static_cast<uint64_t>(0xf8418c08ULL) << 13);
    acc = (acc + a1 + 0xf9400101ULL) ^ 0x0c5e58ULL;
    acc ^= (acc >> 17) * 0x000cULL;
    return acc;
}

// FDE #1125 | PC: 0x07c980 | FDE: 0x0c5e70 | Size: 4 bytes
// Hàm FDE #1125 | Địa chỉ PC: 0x07c980 | Địa chỉ FDE: 0x0c5e70 | Kích thước: 4 bytes
//   0x07c980: 17FE57A0  b        #0x12800
static inline uint64_t fde_func_1125_0x07c980(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07c980ULL ^ (static_cast<uint64_t>(0x17fe57a0ULL) << 13);
    acc = (acc + a1 + 0xd10143ffULL) ^ 0x0c5e70ULL;
    acc ^= (acc >> 17) * 0x0004ULL;
    return acc;
}

// FDE #1126 | PC: 0x07c984 | FDE: 0x0c6068 | Size: 256 bytes
// Hàm FDE #1126 | Địa chỉ PC: 0x07c984 | Địa chỉ FDE: 0x0c6068 | Kích thước: 256 bytes
//   0x07c984: D10143FF  sub      sp, sp, #0x50
//   0x07c988: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x07c98c: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x07c990: A9047BFD  stp      x29, x30, [sp, #0x40]
static inline uint64_t fde_func_1126_0x07c984(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07c984ULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xa90257f6ULL) ^ 0x0c6068ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1127 | PC: 0x07cc34 | FDE: 0x0c5e88 | Size: 88 bytes
// Hàm FDE #1127 | Địa chỉ PC: 0x07cc34 | Địa chỉ FDE: 0x0c5e88 | Kích thước: 88 bytes
//   0x07cc34: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x07cc38: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x07cc3c: 910043FD  add      x29, sp, #0x10
//   0x07cc40: F9400413  ldr      x19, [x0, #8]
static inline uint64_t fde_func_1127_0x07cc34(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07cc34ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x0c5e88ULL;
    acc ^= (acc >> 17) * 0x0058ULL;
    return acc;
}

// FDE #1128 | PC: 0x07cc8c | FDE: 0x0c5ea8 | Size: 88 bytes
// Hàm FDE #1128 | Địa chỉ PC: 0x07cc8c | Địa chỉ FDE: 0x0c5ea8 | Kích thước: 88 bytes
//   0x07cc8c: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x07cc90: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x07cc94: 910043FD  add      x29, sp, #0x10
//   0x07cc98: F9400413  ldr      x19, [x0, #8]
static inline uint64_t fde_func_1128_0x07cc8c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07cc8cULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x0c5ea8ULL;
    acc ^= (acc >> 17) * 0x0058ULL;
    return acc;
}

// FDE #1129 | PC: 0x07cce4 | FDE: 0x0c5ec8 | Size: 88 bytes
// Hàm FDE #1129 | Địa chỉ PC: 0x07cce4 | Địa chỉ FDE: 0x0c5ec8 | Kích thước: 88 bytes
//   0x07cce4: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x07cce8: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x07ccec: 910043FD  add      x29, sp, #0x10
//   0x07ccf0: F9400413  ldr      x19, [x0, #8]
static inline uint64_t fde_func_1129_0x07cce4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07cce4ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x0c5ec8ULL;
    acc ^= (acc >> 17) * 0x0058ULL;
    return acc;
}

// FDE #1130 | PC: 0x07cd3c | FDE: 0x0c5ee8 | Size: 16 bytes
// Hàm FDE #1130 | Địa chỉ PC: 0x07cd3c | Địa chỉ FDE: 0x0c5ee8 | Kích thước: 16 bytes
//   0x07cd3c: F9400400  ldr      x0, [x0, #8]
//   0x07cd40: B4000040  cbz      x0, #0x7cd48
//   0x07cd44: 17FE582B  b        #0x12df0
//   0x07cd48: D65F03C0  ret      
static inline uint64_t fde_func_1130_0x07cd3c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07cd3cULL ^ (static_cast<uint64_t>(0xf9400400ULL) << 13);
    acc = (acc + a1 + 0xb4000040ULL) ^ 0x0c5ee8ULL;
    acc ^= (acc >> 17) * 0x0010ULL;
    return acc;
}

// FDE #1131 | PC: 0x07cd4c | FDE: 0x0c6098 | Size: 256 bytes
// Hàm FDE #1131 | Địa chỉ PC: 0x07cd4c | Địa chỉ FDE: 0x0c6098 | Kích thước: 256 bytes
//   0x07cd4c: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x07cd50: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x07cd54: 910043FD  add      x29, sp, #0x10
//   0x07cd58: D0000368  adrp     x8, #0xea000
static inline uint64_t fde_func_1131_0x07cd4c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07cd4cULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x0c6098ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1132 | PC: 0x07cf08 | FDE: 0x0c5f00 | Size: 36 bytes
// Hàm FDE #1132 | Địa chỉ PC: 0x07cf08 | Địa chỉ FDE: 0x0c5f00 | Kích thước: 36 bytes
//   0x07cf08: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x07cf0c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x07cf10: 910043FD  add      x29, sp, #0x10
//   0x07cf14: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_1132_0x07cf08(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07cf08ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x0c5f00ULL;
    acc ^= (acc >> 17) * 0x0024ULL;
    return acc;
}

// FDE #1133 | PC: 0x07cf2c | FDE: 0x0c5f20 | Size: 256 bytes
// Hàm FDE #1133 | Địa chỉ PC: 0x07cf2c | Địa chỉ FDE: 0x0c5f20 | Kích thước: 256 bytes
//   0x07cf2c: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x07cf30: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x07cf34: 910043FD  add      x29, sp, #0x10
//   0x07cf38: F9400028  ldr      x8, [x1]
static inline uint64_t fde_func_1133_0x07cf2c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07cf2cULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x0c5f20ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1134 | PC: 0x07d074 | FDE: 0x0c60c0 | Size: 256 bytes
// Hàm FDE #1134 | Địa chỉ PC: 0x07d074 | Địa chỉ FDE: 0x0c60c0 | Kích thước: 256 bytes
//   0x07d074: D101C3FF  sub      sp, sp, #0x70
//   0x07d078: F90013F9  str      x25, [sp, #0x20]
//   0x07d07c: A9035FF8  stp      x24, x23, [sp, #0x30]
//   0x07d080: A90457F6  stp      x22, x21, [sp, #0x40]
static inline uint64_t fde_func_1134_0x07d074(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07d074ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xf90013f9ULL) ^ 0x0c60c0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1135 | PC: 0x07d350 | FDE: 0x0c60f0 | Size: 256 bytes
// Hàm FDE #1135 | Địa chỉ PC: 0x07d350 | Địa chỉ FDE: 0x0c60f0 | Kích thước: 256 bytes
//   0x07d350: D10443FF  sub      sp, sp, #0x110
//   0x07d354: A90D5FFC  stp      x28, x23, [sp, #0xd0]
//   0x07d358: A90E57F6  stp      x22, x21, [sp, #0xe0]
//   0x07d35c: A90F4FF4  stp      x20, x19, [sp, #0xf0]
static inline uint64_t fde_func_1135_0x07d350(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07d350ULL ^ (static_cast<uint64_t>(0xd10443ffULL) << 13);
    acc = (acc + a1 + 0xa90d5ffcULL) ^ 0x0c60f0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1136 | PC: 0x07d6b8 | FDE: 0x0c5f40 | Size: 16 bytes
// Hàm FDE #1136 | Địa chỉ PC: 0x07d6b8 | Địa chỉ FDE: 0x0c5f40 | Kích thước: 16 bytes
//   0x07d6b8: F9402800  ldr      x0, [x0, #0x50]
//   0x07d6bc: B4000040  cbz      x0, #0x7d6c4
//   0x07d6c0: 14000E6A  b        #0x81068
//   0x07d6c4: D65F03C0  ret      
static inline uint64_t fde_func_1136_0x07d6b8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07d6b8ULL ^ (static_cast<uint64_t>(0xf9402800ULL) << 13);
    acc = (acc + a1 + 0xb4000040ULL) ^ 0x0c5f40ULL;
    acc ^= (acc >> 17) * 0x0010ULL;
    return acc;
}

// FDE #1137 | PC: 0x07d6c8 | FDE: 0x0c5f58 | Size: 256 bytes
// Hàm FDE #1137 | Địa chỉ PC: 0x07d6c8 | Địa chỉ FDE: 0x0c5f58 | Kích thước: 256 bytes
//   0x07d6c8: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x07d6cc: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x07d6d0: 910043FD  add      x29, sp, #0x10
//   0x07d6d4: F9400028  ldr      x8, [x1]
static inline uint64_t fde_func_1137_0x07d6c8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07d6c8ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x0c5f58ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1138 | PC: 0x07d7d0 | FDE: 0x0c6120 | Size: 256 bytes
// Hàm FDE #1138 | Địa chỉ PC: 0x07d7d0 | Địa chỉ FDE: 0x0c6120 | Kích thước: 256 bytes
//   0x07d7d0: D10383FF  sub      sp, sp, #0xe0
//   0x07d7d4: A90A5FF8  stp      x24, x23, [sp, #0xa0]
//   0x07d7d8: A90B57F6  stp      x22, x21, [sp, #0xb0]
//   0x07d7dc: A90C4FF4  stp      x20, x19, [sp, #0xc0]
static inline uint64_t fde_func_1138_0x07d7d0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07d7d0ULL ^ (static_cast<uint64_t>(0xd10383ffULL) << 13);
    acc = (acc + a1 + 0xa90a5ff8ULL) ^ 0x0c6120ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1139 | PC: 0x07dd2c | FDE: 0x0c5f78 | Size: 8 bytes
// Hàm FDE #1139 | Địa chỉ PC: 0x07dd2c | Địa chỉ FDE: 0x0c5f78 | Kích thước: 8 bytes
//   0x07dd2c: D1002000  sub      x0, x0, #8
//   0x07dd30: 17FFFC07  b        #0x7cd4c
static inline uint64_t fde_func_1139_0x07dd2c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07dd2cULL ^ (static_cast<uint64_t>(0xd1002000ULL) << 13);
    acc = (acc + a1 + 0x17fffc07ULL) ^ 0x0c5f78ULL;
    acc ^= (acc >> 17) * 0x0008ULL;
    return acc;
}

// FDE #1140 | PC: 0x07dd34 | FDE: 0x0c5f90 | Size: 40 bytes
// Hàm FDE #1140 | Địa chỉ PC: 0x07dd34 | Địa chỉ FDE: 0x0c5f90 | Kích thước: 40 bytes
//   0x07dd34: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x07dd38: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x07dd3c: 910043FD  add      x29, sp, #0x10
//   0x07dd40: D1002013  sub      x19, x0, #8
static inline uint64_t fde_func_1140_0x07dd34(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07dd34ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x0c5f90ULL;
    acc ^= (acc >> 17) * 0x0028ULL;
    return acc;
}

// FDE #1141 | PC: 0x07dd5c | FDE: 0x0c5fb0 | Size: 8 bytes
// Hàm FDE #1141 | Địa chỉ PC: 0x07dd5c | Địa chỉ FDE: 0x0c5fb0 | Kích thước: 8 bytes
//   0x07dd5c: D1002000  sub      x0, x0, #8
//   0x07dd60: 17FFFE9C  b        #0x7d7d0
static inline uint64_t fde_func_1141_0x07dd5c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07dd5cULL ^ (static_cast<uint64_t>(0xd1002000ULL) << 13);
    acc = (acc + a1 + 0x17fffe9cULL) ^ 0x0c5fb0ULL;
    acc ^= (acc >> 17) * 0x0008ULL;
    return acc;
}

// FDE #1142 | PC: 0x07dd64 | FDE: 0x0c6150 | Size: 256 bytes
// Hàm FDE #1142 | Địa chỉ PC: 0x07dd64 | Địa chỉ FDE: 0x0c6150 | Kích thước: 256 bytes
//   0x07dd64: A9BA6FFC  stp      x28, x27, [sp, #-0x60]!
//   0x07dd68: A90167FA  stp      x26, x25, [sp, #0x10]
//   0x07dd6c: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x07dd70: A90357F6  stp      x22, x21, [sp, #0x30]
static inline uint64_t fde_func_1142_0x07dd64(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07dd64ULL ^ (static_cast<uint64_t>(0xa9ba6ffcULL) << 13);
    acc = (acc + a1 + 0xa90167faULL) ^ 0x0c6150ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1143 | PC: 0x07dea0 | FDE: 0x0c5fc8 | Size: 48 bytes
// Hàm FDE #1143 | Địa chỉ PC: 0x07dea0 | Địa chỉ FDE: 0x0c5fc8 | Kích thước: 48 bytes
//   0x07dea0: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x07dea4: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x07dea8: 910043FD  add      x29, sp, #0x10
//   0x07deac: B0000368  adrp     x8, #0xea000
static inline uint64_t fde_func_1143_0x07dea0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07dea0ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x0c5fc8ULL;
    acc ^= (acc >> 17) * 0x0030ULL;
    return acc;
}

// FDE #1144 | PC: 0x07ded0 | FDE: 0x0c5fe8 | Size: 56 bytes
// Hàm FDE #1144 | Địa chỉ PC: 0x07ded0 | Địa chỉ FDE: 0x0c5fe8 | Kích thước: 56 bytes
//   0x07ded0: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x07ded4: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x07ded8: 910043FD  add      x29, sp, #0x10
//   0x07dedc: B0000368  adrp     x8, #0xea000
static inline uint64_t fde_func_1144_0x07ded0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07ded0ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x0c5fe8ULL;
    acc ^= (acc >> 17) * 0x0038ULL;
    return acc;
}

// FDE #1145 | PC: 0x07df08 | FDE: 0x0c6008 | Size: 8 bytes
// Hàm FDE #1145 | Địa chỉ PC: 0x07df08 | Địa chỉ FDE: 0x0c6008 | Kích thước: 8 bytes
//   0x07df08: 91006000  add      x0, x0, #0x18
//   0x07df0c: 14000747  b        #0x7fc28
static inline uint64_t fde_func_1145_0x07df08(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07df08ULL ^ (static_cast<uint64_t>(0x91006000ULL) << 13);
    acc = (acc + a1 + 0x14000747ULL) ^ 0x0c6008ULL;
    acc ^= (acc >> 17) * 0x0008ULL;
    return acc;
}

// FDE #1146 | PC: 0x07df10 | FDE: 0x0c6020 | Size: 4 bytes
// Hàm FDE #1146 | Địa chỉ PC: 0x07df10 | Địa chỉ FDE: 0x0c6020 | Kích thước: 4 bytes
//   0x07df10: 17FE523C  b        #0x12800
static inline uint64_t fde_func_1146_0x07df10(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07df10ULL ^ (static_cast<uint64_t>(0x17fe523cULL) << 13);
    acc = (acc + a1 + 0xd101c3ffULL) ^ 0x0c6020ULL;
    acc ^= (acc >> 17) * 0x0004ULL;
    return acc;
}

// FDE #1147 | PC: 0x07df14 | FDE: 0x0c6208 | Size: 256 bytes
// Hàm FDE #1147 | Địa chỉ PC: 0x07df14 | Địa chỉ FDE: 0x0c6208 | Kích thước: 256 bytes
//   0x07df14: D101C3FF  sub      sp, sp, #0x70
//   0x07df18: F90023F5  str      x21, [sp, #0x40]
//   0x07df1c: A9054FF4  stp      x20, x19, [sp, #0x50]
//   0x07df20: A9067BFD  stp      x29, x30, [sp, #0x60]
static inline uint64_t fde_func_1147_0x07df14(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07df14ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xf90023f5ULL) ^ 0x0c6208ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1148 | PC: 0x07e070 | FDE: 0x0c6230 | Size: 256 bytes
// Hàm FDE #1148 | Địa chỉ PC: 0x07e070 | Địa chỉ FDE: 0x0c6230 | Kích thước: 256 bytes
//   0x07e070: D103C3FF  sub      sp, sp, #0xf0
//   0x07e074: A90C57F6  stp      x22, x21, [sp, #0xc0]
//   0x07e078: A90D4FF4  stp      x20, x19, [sp, #0xd0]
//   0x07e07c: A90E7BFD  stp      x29, x30, [sp, #0xe0]
static inline uint64_t fde_func_1148_0x07e070(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07e070ULL ^ (static_cast<uint64_t>(0xd103c3ffULL) << 13);
    acc = (acc + a1 + 0xa90c57f6ULL) ^ 0x0c6230ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1149 | PC: 0x07e2ec | FDE: 0x0c6260 | Size: 256 bytes
// Hàm FDE #1149 | Địa chỉ PC: 0x07e2ec | Địa chỉ FDE: 0x0c6260 | Kích thước: 256 bytes
//   0x07e2ec: A9BA6FFC  stp      x28, x27, [sp, #-0x60]!
//   0x07e2f0: A90167FA  stp      x26, x25, [sp, #0x10]
//   0x07e2f4: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x07e2f8: A90357F6  stp      x22, x21, [sp, #0x30]
static inline uint64_t fde_func_1149_0x07e2ec(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07e2ecULL ^ (static_cast<uint64_t>(0xa9ba6ffcULL) << 13);
    acc = (acc + a1 + 0xa90167faULL) ^ 0x0c6260ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1150 | PC: 0x07ec30 | FDE: 0x0c6298 | Size: 256 bytes
// Hàm FDE #1150 | Địa chỉ PC: 0x07ec30 | Địa chỉ FDE: 0x0c6298 | Kích thước: 256 bytes
//   0x07ec30: A9BB67FA  stp      x26, x25, [sp, #-0x50]!
//   0x07ec34: A9015FF8  stp      x24, x23, [sp, #0x10]
//   0x07ec38: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x07ec3c: A9034FF4  stp      x20, x19, [sp, #0x30]
static inline uint64_t fde_func_1150_0x07ec30(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07ec30ULL ^ (static_cast<uint64_t>(0xa9bb67faULL) << 13);
    acc = (acc + a1 + 0xa9015ff8ULL) ^ 0x0c6298ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1151 | PC: 0x07ee1c | FDE: 0x0c6188 | Size: 256 bytes
// Hàm FDE #1151 | Địa chỉ PC: 0x07ee1c | Địa chỉ FDE: 0x0c6188 | Kích thước: 256 bytes
//   0x07ee1c: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x07ee20: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x07ee24: 910043FD  add      x29, sp, #0x10
//   0x07ee28: AA0103F4  mov      x20, x1
static inline uint64_t fde_func_1151_0x07ee1c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07ee1cULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x0c6188ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1152 | PC: 0x07f024 | FDE: 0x0c62d0 | Size: 256 bytes
// Hàm FDE #1152 | Địa chỉ PC: 0x07f024 | Địa chỉ FDE: 0x0c62d0 | Kích thước: 256 bytes
//   0x07f024: F81B0FF9  str      x25, [sp, #-0x50]!
//   0x07f028: A9015FF8  stp      x24, x23, [sp, #0x10]
//   0x07f02c: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x07f030: A9034FF4  stp      x20, x19, [sp, #0x30]
static inline uint64_t fde_func_1152_0x07f024(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07f024ULL ^ (static_cast<uint64_t>(0xf81b0ff9ULL) << 13);
    acc = (acc + a1 + 0xa9015ff8ULL) ^ 0x0c62d0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1153 | PC: 0x07f1e4 | FDE: 0x0c61a8 | Size: 164 bytes
// Hàm FDE #1153 | Địa chỉ PC: 0x07f1e4 | Địa chỉ FDE: 0x0c61a8 | Kích thước: 164 bytes
//   0x07f1e4: D10443FF  sub      sp, sp, #0x110
//   0x07f1e8: A90F4FFC  stp      x28, x19, [sp, #0xf0]
//   0x07f1ec: A9107BFD  stp      x29, x30, [sp, #0x100]
//   0x07f1f0: 910403FD  add      x29, sp, #0x100
static inline uint64_t fde_func_1153_0x07f1e4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07f1e4ULL ^ (static_cast<uint64_t>(0xd10443ffULL) << 13);
    acc = (acc + a1 + 0xa90f4ffcULL) ^ 0x0c61a8ULL;
    acc ^= (acc >> 17) * 0x00a4ULL;
    return acc;
}

// FDE #1154 | PC: 0x07f288 | FDE: 0x0c6300 | Size: 256 bytes
// Hàm FDE #1154 | Địa chỉ PC: 0x07f288 | Địa chỉ FDE: 0x0c6300 | Kích thước: 256 bytes
//   0x07f288: A9BC5FF8  stp      x24, x23, [sp, #-0x40]!
//   0x07f28c: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x07f290: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x07f294: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_1154_0x07f288(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07f288ULL ^ (static_cast<uint64_t>(0xa9bc5ff8ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x0c6300ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1155 | PC: 0x07f4c0 | FDE: 0x0c61c8 | Size: 228 bytes
// Hàm FDE #1155 | Địa chỉ PC: 0x07f4c0 | Địa chỉ FDE: 0x0c61c8 | Kích thước: 228 bytes
//   0x07f4c0: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x07f4c4: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x07f4c8: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x07f4cc: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1155_0x07f4c0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07f4c0ULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x0c61c8ULL;
    acc ^= (acc >> 17) * 0x00e4ULL;
    return acc;
}

// FDE #1156 | PC: 0x07f5a4 | FDE: 0x0c61e8 | Size: 256 bytes
// Hàm FDE #1156 | Địa chỉ PC: 0x07f5a4 | Địa chỉ FDE: 0x0c61e8 | Kích thước: 256 bytes
//   0x07f5a4: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x07f5a8: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x07f5ac: 910043FD  add      x29, sp, #0x10
//   0x07f5b0: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_1156_0x07f5a4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07f5a4ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x0c61e8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1157 | PC: 0x07f72c | FDE: 0x0c6330 | Size: 172 bytes
// Hàm FDE #1157 | Địa chỉ PC: 0x07f72c | Địa chỉ FDE: 0x0c6330 | Kích thước: 172 bytes
//   0x07f72c: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x07f730: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x07f734: 910043FD  add      x29, sp, #0x10
//   0x07f738: 39400008  ldrb     w8, [x0]
static inline uint64_t fde_func_1157_0x07f72c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07f72cULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x0c6330ULL;
    acc ^= (acc >> 17) * 0x00acULL;
    return acc;
}

// FDE #1158 | PC: 0x07f7d8 | FDE: 0x0c67e8 | Size: 256 bytes
// Hàm FDE #1158 | Địa chỉ PC: 0x07f7d8 | Địa chỉ FDE: 0x0c67e8 | Kích thước: 256 bytes
//   0x07f7d8: D101C3FF  sub      sp, sp, #0x70
//   0x07f7dc: F9000BFB  str      x27, [sp, #0x10]
//   0x07f7e0: A90267FA  stp      x26, x25, [sp, #0x20]
//   0x07f7e4: A9035FF8  stp      x24, x23, [sp, #0x30]
static inline uint64_t fde_func_1158_0x07f7d8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07f7d8ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xf9000bfbULL) ^ 0x0c67e8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1159 | PC: 0x07faac | FDE: 0x0c6350 | Size: 124 bytes
// Hàm FDE #1159 | Địa chỉ PC: 0x07faac | Địa chỉ FDE: 0x0c6350 | Kích thước: 124 bytes
//   0x07faac: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x07fab0: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x07fab4: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x07fab8: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1159_0x07faac(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07faacULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x0c6350ULL;
    acc ^= (acc >> 17) * 0x007cULL;
    return acc;
}

// FDE #1160 | PC: 0x07fb28 | FDE: 0x0c6370 | Size: 116 bytes
// Hàm FDE #1160 | Địa chỉ PC: 0x07fb28 | Địa chỉ FDE: 0x0c6370 | Kích thước: 116 bytes
//   0x07fb28: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x07fb2c: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x07fb30: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x07fb34: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1160_0x07fb28(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07fb28ULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x0c6370ULL;
    acc ^= (acc >> 17) * 0x0074ULL;
    return acc;
}

// FDE #1161 | PC: 0x07fb9c | FDE: 0x0c6398 | Size: 16 bytes
// Hàm FDE #1161 | Địa chỉ PC: 0x07fb9c | Địa chỉ FDE: 0x0c6398 | Kích thước: 16 bytes
//   0x07fb9c: F9400400  ldr      x0, [x0, #8]
//   0x07fba0: B4000040  cbz      x0, #0x7fba8
//   0x07fba4: 17FE4C93  b        #0x12df0
//   0x07fba8: D65F03C0  ret      
static inline uint64_t fde_func_1161_0x07fb9c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07fb9cULL ^ (static_cast<uint64_t>(0xf9400400ULL) << 13);
    acc = (acc + a1 + 0xb4000040ULL) ^ 0x0c6398ULL;
    acc ^= (acc >> 17) * 0x0010ULL;
    return acc;
}

// FDE #1162 | PC: 0x07fbac | FDE: 0x0c63b0 | Size: 108 bytes
// Hàm FDE #1162 | Địa chỉ PC: 0x07fbac | Địa chỉ FDE: 0x0c63b0 | Kích thước: 108 bytes
//   0x07fbac: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x07fbb0: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x07fbb4: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x07fbb8: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1162_0x07fbac(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07fbacULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x0c63b0ULL;
    acc ^= (acc >> 17) * 0x006cULL;
    return acc;
}

// FDE #1163 | PC: 0x07fc18 | FDE: 0x0c63d0 | Size: 16 bytes
// Hàm FDE #1163 | Địa chỉ PC: 0x07fc18 | Địa chỉ FDE: 0x0c63d0 | Kích thước: 16 bytes
//   0x07fc18: F9400400  ldr      x0, [x0, #8]
//   0x07fc1c: B4000040  cbz      x0, #0x7fc24
//   0x07fc20: 17FE4C74  b        #0x12df0
//   0x07fc24: D65F03C0  ret      
static inline uint64_t fde_func_1163_0x07fc18(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07fc18ULL ^ (static_cast<uint64_t>(0xf9400400ULL) << 13);
    acc = (acc + a1 + 0xb4000040ULL) ^ 0x0c63d0ULL;
    acc ^= (acc >> 17) * 0x0010ULL;
    return acc;
}

// FDE #1164 | PC: 0x07fc28 | FDE: 0x0c6820 | Size: 256 bytes
// Hàm FDE #1164 | Địa chỉ PC: 0x07fc28 | Địa chỉ FDE: 0x0c6820 | Kích thước: 256 bytes
//   0x07fc28: D10143FF  sub      sp, sp, #0x50
//   0x07fc2c: F9000BF7  str      x23, [sp, #0x10]
//   0x07fc30: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x07fc34: A9034FF4  stp      x20, x19, [sp, #0x30]
static inline uint64_t fde_func_1164_0x07fc28(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07fc28ULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xf9000bf7ULL) ^ 0x0c6820ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1165 | PC: 0x080060 | FDE: 0x0c6850 | Size: 256 bytes
// Hàm FDE #1165 | Địa chỉ PC: 0x080060 | Địa chỉ FDE: 0x0c6850 | Kích thước: 256 bytes
//   0x080060: D10143FF  sub      sp, sp, #0x50
//   0x080064: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x080068: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x08006c: A9047BFD  stp      x29, x30, [sp, #0x40]
static inline uint64_t fde_func_1165_0x080060(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x080060ULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xa90257f6ULL) ^ 0x0c6850ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1166 | PC: 0x080304 | FDE: 0x0c6880 | Size: 256 bytes
// Hàm FDE #1166 | Địa chỉ PC: 0x080304 | Địa chỉ FDE: 0x0c6880 | Kích thước: 256 bytes
//   0x080304: D10303FF  sub      sp, sp, #0xc0
//   0x080308: A9066FFC  stp      x28, x27, [sp, #0x60]
//   0x08030c: A90767FA  stp      x26, x25, [sp, #0x70]
//   0x080310: A9085FF8  stp      x24, x23, [sp, #0x80]
static inline uint64_t fde_func_1166_0x080304(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x080304ULL ^ (static_cast<uint64_t>(0xd10303ffULL) << 13);
    acc = (acc + a1 + 0xa9066ffcULL) ^ 0x0c6880ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1167 | PC: 0x0806f0 | FDE: 0x0c68b8 | Size: 256 bytes
// Hàm FDE #1167 | Địa chỉ PC: 0x0806f0 | Địa chỉ FDE: 0x0c68b8 | Kích thước: 256 bytes
//   0x0806f0: F81C0FF7  str      x23, [sp, #-0x40]!
//   0x0806f4: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x0806f8: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x0806fc: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_1167_0x0806f0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0806f0ULL ^ (static_cast<uint64_t>(0xf81c0ff7ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x0c68b8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1168 | PC: 0x0807f0 | FDE: 0x0c63e8 | Size: 228 bytes
// Hàm FDE #1168 | Địa chỉ PC: 0x0807f0 | Địa chỉ FDE: 0x0c63e8 | Kích thước: 228 bytes
//   0x0807f0: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x0807f4: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0807f8: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0807fc: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1168_0x0807f0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0807f0ULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x0c63e8ULL;
    acc ^= (acc >> 17) * 0x00e4ULL;
    return acc;
}

// FDE #1169 | PC: 0x0808d4 | FDE: 0x0c6408 | Size: 256 bytes
// Hàm FDE #1169 | Địa chỉ PC: 0x0808d4 | Địa chỉ FDE: 0x0c6408 | Kích thước: 256 bytes
//   0x0808d4: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x0808d8: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0808dc: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0808e0: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1169_0x0808d4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0808d4ULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x0c6408ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1170 | PC: 0x0809e4 | FDE: 0x0c68e8 | Size: 256 bytes
// Hàm FDE #1170 | Địa chỉ PC: 0x0809e4 | Địa chỉ FDE: 0x0c68e8 | Kích thước: 256 bytes
//   0x0809e4: D10183FF  sub      sp, sp, #0x60
//   0x0809e8: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x0809ec: A90357F6  stp      x22, x21, [sp, #0x30]
//   0x0809f0: A9044FF4  stp      x20, x19, [sp, #0x40]
static inline uint64_t fde_func_1170_0x0809e4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0809e4ULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xa9025ff8ULL) ^ 0x0c68e8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1171 | PC: 0x080c48 | FDE: 0x0c6428 | Size: 256 bytes
// Hàm FDE #1171 | Địa chỉ PC: 0x080c48 | Địa chỉ FDE: 0x0c6428 | Kích thước: 256 bytes
//   0x080c48: D10183FF  sub      sp, sp, #0x60
//   0x080c4c: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x080c50: A90357F6  stp      x22, x21, [sp, #0x30]
//   0x080c54: A9044FF4  stp      x20, x19, [sp, #0x40]
static inline uint64_t fde_func_1171_0x080c48(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x080c48ULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xa9025ff8ULL) ^ 0x0c6428ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1172 | PC: 0x080e84 | FDE: 0x0c6918 | Size: 256 bytes
// Hàm FDE #1172 | Địa chỉ PC: 0x080e84 | Địa chỉ FDE: 0x0c6918 | Kích thước: 256 bytes
//   0x080e84: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x080e88: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x080e8c: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x080e90: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1172_0x080e84(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x080e84ULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x0c6918ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1173 | PC: 0x081068 | FDE: 0x0c6450 | Size: 252 bytes
// Hàm FDE #1173 | Địa chỉ PC: 0x081068 | Địa chỉ FDE: 0x0c6450 | Kích thước: 252 bytes
//   0x081068: F81C0FF7  str      x23, [sp, #-0x40]!
//   0x08106c: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x081070: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x081074: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_1173_0x081068(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x081068ULL ^ (static_cast<uint64_t>(0xf81c0ff7ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x0c6450ULL;
    acc ^= (acc >> 17) * 0x00fcULL;
    return acc;
}

// FDE #1174 | PC: 0x081164 | FDE: 0x0c6940 | Size: 256 bytes
// Hàm FDE #1174 | Địa chỉ PC: 0x081164 | Địa chỉ FDE: 0x0c6940 | Kích thước: 256 bytes
//   0x081164: D10203FF  sub      sp, sp, #0x80
//   0x081168: F9001BF9  str      x25, [sp, #0x30]
//   0x08116c: A9045FF8  stp      x24, x23, [sp, #0x40]
//   0x081170: A90557F6  stp      x22, x21, [sp, #0x50]
static inline uint64_t fde_func_1174_0x081164(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x081164ULL ^ (static_cast<uint64_t>(0xd10203ffULL) << 13);
    acc = (acc + a1 + 0xf9001bf9ULL) ^ 0x0c6940ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1175 | PC: 0x08135c | FDE: 0x0c6970 | Size: 256 bytes
// Hàm FDE #1175 | Địa chỉ PC: 0x08135c | Địa chỉ FDE: 0x0c6970 | Kích thước: 256 bytes
//   0x08135c: D10583FF  sub      sp, sp, #0x160
//   0x081360: A9106FFC  stp      x28, x27, [sp, #0x100]
//   0x081364: A91167FA  stp      x26, x25, [sp, #0x110]
//   0x081368: A9125FF8  stp      x24, x23, [sp, #0x120]
static inline uint64_t fde_func_1175_0x08135c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x08135cULL ^ (static_cast<uint64_t>(0xd10583ffULL) << 13);
    acc = (acc + a1 + 0xa9106ffcULL) ^ 0x0c6970ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1176 | PC: 0x081e10 | FDE: 0x0c69a8 | Size: 180 bytes
// Hàm FDE #1176 | Địa chỉ PC: 0x081e10 | Địa chỉ FDE: 0x0c69a8 | Kích thước: 180 bytes
//   0x081e10: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x081e14: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x081e18: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x081e1c: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1176_0x081e10(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x081e10ULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x0c69a8ULL;
    acc ^= (acc >> 17) * 0x00b4ULL;
    return acc;
}

// FDE #1177 | PC: 0x081ec4 | FDE: 0x0c69d8 | Size: 256 bytes
// Hàm FDE #1177 | Địa chỉ PC: 0x081ec4 | Địa chỉ FDE: 0x0c69d8 | Kích thước: 256 bytes
//   0x081ec4: D10303FF  sub      sp, sp, #0xc0
//   0x081ec8: A9066FFC  stp      x28, x27, [sp, #0x60]
//   0x081ecc: A90767FA  stp      x26, x25, [sp, #0x70]
//   0x081ed0: A9085FF8  stp      x24, x23, [sp, #0x80]
static inline uint64_t fde_func_1177_0x081ec4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x081ec4ULL ^ (static_cast<uint64_t>(0xd10303ffULL) << 13);
    acc = (acc + a1 + 0xa9066ffcULL) ^ 0x0c69d8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1178 | PC: 0x0828e8 | FDE: 0x0c6a10 | Size: 256 bytes
// Hàm FDE #1178 | Địa chỉ PC: 0x0828e8 | Địa chỉ FDE: 0x0c6a10 | Kích thước: 256 bytes
//   0x0828e8: D10503FF  sub      sp, sp, #0x140
//   0x0828ec: A90E6FFC  stp      x28, x27, [sp, #0xe0]
//   0x0828f0: A90F67FA  stp      x26, x25, [sp, #0xf0]
//   0x0828f4: A9105FF8  stp      x24, x23, [sp, #0x100]
static inline uint64_t fde_func_1178_0x0828e8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0828e8ULL ^ (static_cast<uint64_t>(0xd10503ffULL) << 13);
    acc = (acc + a1 + 0xa90e6ffcULL) ^ 0x0c6a10ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1179 | PC: 0x083154 | FDE: 0x0c6a48 | Size: 256 bytes
// Hàm FDE #1179 | Địa chỉ PC: 0x083154 | Địa chỉ FDE: 0x0c6a48 | Kích thước: 256 bytes
//   0x083154: F81A0FFB  str      x27, [sp, #-0x60]!
//   0x083158: A90167FA  stp      x26, x25, [sp, #0x10]
//   0x08315c: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x083160: A90357F6  stp      x22, x21, [sp, #0x30]
static inline uint64_t fde_func_1179_0x083154(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x083154ULL ^ (static_cast<uint64_t>(0xf81a0ffbULL) << 13);
    acc = (acc + a1 + 0xa90167faULL) ^ 0x0c6a48ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1180 | PC: 0x0833b4 | FDE: 0x0c6478 | Size: 148 bytes
// Hàm FDE #1180 | Địa chỉ PC: 0x0833b4 | Địa chỉ FDE: 0x0c6478 | Kích thước: 148 bytes
//   0x0833b4: D10103FF  sub      sp, sp, #0x40
//   0x0833b8: F9000BF5  str      x21, [sp, #0x10]
//   0x0833bc: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x0833c0: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_1180_0x0833b4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0833b4ULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xf9000bf5ULL) ^ 0x0c6478ULL;
    acc ^= (acc >> 17) * 0x0094ULL;
    return acc;
}

// FDE #1181 | PC: 0x083448 | FDE: 0x0c6a80 | Size: 256 bytes
// Hàm FDE #1181 | Địa chỉ PC: 0x083448 | Địa chỉ FDE: 0x0c6a80 | Kích thước: 256 bytes
//   0x083448: D10343FF  sub      sp, sp, #0xd0
//   0x08344c: A9076FFC  stp      x28, x27, [sp, #0x70]
//   0x083450: A90867FA  stp      x26, x25, [sp, #0x80]
//   0x083454: A9095FF8  stp      x24, x23, [sp, #0x90]
static inline uint64_t fde_func_1181_0x083448(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x083448ULL ^ (static_cast<uint64_t>(0xd10343ffULL) << 13);
    acc = (acc + a1 + 0xa9076ffcULL) ^ 0x0c6a80ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1182 | PC: 0x0839f8 | FDE: 0x0c6ab8 | Size: 256 bytes
// Hàm FDE #1182 | Địa chỉ PC: 0x0839f8 | Địa chỉ FDE: 0x0c6ab8 | Kích thước: 256 bytes
//   0x0839f8: D10403FF  sub      sp, sp, #0x100
//   0x0839fc: A90A6FFC  stp      x28, x27, [sp, #0xa0]
//   0x083a00: A90B67FA  stp      x26, x25, [sp, #0xb0]
//   0x083a04: A90C5FF8  stp      x24, x23, [sp, #0xc0]
static inline uint64_t fde_func_1182_0x0839f8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0839f8ULL ^ (static_cast<uint64_t>(0xd10403ffULL) << 13);
    acc = (acc + a1 + 0xa90a6ffcULL) ^ 0x0c6ab8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1183 | PC: 0x083f14 | FDE: 0x0c6af0 | Size: 256 bytes
// Hàm FDE #1183 | Địa chỉ PC: 0x083f14 | Địa chỉ FDE: 0x0c6af0 | Kích thước: 256 bytes
//   0x083f14: D10643FF  sub      sp, sp, #0x190
//   0x083f18: F9009BFC  str      x28, [sp, #0x130]
//   0x083f1c: A91467FA  stp      x26, x25, [sp, #0x140]
//   0x083f20: A9155FF8  stp      x24, x23, [sp, #0x150]
static inline uint64_t fde_func_1183_0x083f14(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x083f14ULL ^ (static_cast<uint64_t>(0xd10643ffULL) << 13);
    acc = (acc + a1 + 0xf9009bfcULL) ^ 0x0c6af0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1184 | PC: 0x084644 | FDE: 0x0c6b28 | Size: 256 bytes
// Hàm FDE #1184 | Địa chỉ PC: 0x084644 | Địa chỉ FDE: 0x0c6b28 | Kích thước: 256 bytes
//   0x084644: D10343FF  sub      sp, sp, #0xd0
//   0x084648: F9003BFB  str      x27, [sp, #0x70]
//   0x08464c: A90867FA  stp      x26, x25, [sp, #0x80]
//   0x084650: A9095FF8  stp      x24, x23, [sp, #0x90]
static inline uint64_t fde_func_1184_0x084644(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x084644ULL ^ (static_cast<uint64_t>(0xd10343ffULL) << 13);
    acc = (acc + a1 + 0xf9003bfbULL) ^ 0x0c6b28ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1185 | PC: 0x084e68 | FDE: 0x0c6b60 | Size: 256 bytes
// Hàm FDE #1185 | Địa chỉ PC: 0x084e68 | Địa chỉ FDE: 0x0c6b60 | Kích thước: 256 bytes
//   0x084e68: F81C0FF7  str      x23, [sp, #-0x40]!
//   0x084e6c: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x084e70: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x084e74: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_1185_0x084e68(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x084e68ULL ^ (static_cast<uint64_t>(0xf81c0ff7ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x0c6b60ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1186 | PC: 0x084fc0 | FDE: 0x0c6b90 | Size: 168 bytes
// Hàm FDE #1186 | Địa chỉ PC: 0x084fc0 | Địa chỉ FDE: 0x0c6b90 | Kích thước: 168 bytes
//   0x084fc0: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x084fc4: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x084fc8: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x084fcc: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1186_0x084fc0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x084fc0ULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x0c6b90ULL;
    acc ^= (acc >> 17) * 0x00a8ULL;
    return acc;
}

// FDE #1187 | PC: 0x085068 | FDE: 0x0c6bc0 | Size: 256 bytes
// Hàm FDE #1187 | Địa chỉ PC: 0x085068 | Địa chỉ FDE: 0x0c6bc0 | Kích thước: 256 bytes
//   0x085068: D10203FF  sub      sp, sp, #0x80
//   0x08506c: A9026FFC  stp      x28, x27, [sp, #0x20]
//   0x085070: A90367FA  stp      x26, x25, [sp, #0x30]
//   0x085074: A9045FF8  stp      x24, x23, [sp, #0x40]
static inline uint64_t fde_func_1187_0x085068(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x085068ULL ^ (static_cast<uint64_t>(0xd10203ffULL) << 13);
    acc = (acc + a1 + 0xa9026ffcULL) ^ 0x0c6bc0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1188 | PC: 0x0853ac | FDE: 0x0c6498 | Size: 228 bytes
// Hàm FDE #1188 | Địa chỉ PC: 0x0853ac | Địa chỉ FDE: 0x0c6498 | Kích thước: 228 bytes
//   0x0853ac: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x0853b0: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0853b4: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0853b8: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1188_0x0853ac(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0853acULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x0c6498ULL;
    acc ^= (acc >> 17) * 0x00e4ULL;
    return acc;
}

// FDE #1189 | PC: 0x085490 | FDE: 0x0c64b8 | Size: 256 bytes
// Hàm FDE #1189 | Địa chỉ PC: 0x085490 | Địa chỉ FDE: 0x0c64b8 | Kích thước: 256 bytes
//   0x085490: D10203FF  sub      sp, sp, #0x80
//   0x085494: A9026FFC  stp      x28, x27, [sp, #0x20]
//   0x085498: A90367FA  stp      x26, x25, [sp, #0x30]
//   0x08549c: A9045FF8  stp      x24, x23, [sp, #0x40]
static inline uint64_t fde_func_1189_0x085490(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x085490ULL ^ (static_cast<uint64_t>(0xd10203ffULL) << 13);
    acc = (acc + a1 + 0xa9026ffcULL) ^ 0x0c64b8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1190 | PC: 0x085700 | FDE: 0x0c64e8 | Size: 248 bytes
// Hàm FDE #1190 | Địa chỉ PC: 0x085700 | Địa chỉ FDE: 0x0c64e8 | Kích thước: 248 bytes
//   0x085700: F81B0FF9  str      x25, [sp, #-0x50]!
//   0x085704: A9015FF8  stp      x24, x23, [sp, #0x10]
//   0x085708: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x08570c: A9034FF4  stp      x20, x19, [sp, #0x30]
static inline uint64_t fde_func_1190_0x085700(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x085700ULL ^ (static_cast<uint64_t>(0xf81b0ff9ULL) << 13);
    acc = (acc + a1 + 0xa9015ff8ULL) ^ 0x0c64e8ULL;
    acc ^= (acc >> 17) * 0x00f8ULL;
    return acc;
}

// FDE #1191 | PC: 0x0857f8 | FDE: 0x0c6510 | Size: 256 bytes
// Hàm FDE #1191 | Địa chỉ PC: 0x0857f8 | Địa chỉ FDE: 0x0c6510 | Kích thước: 256 bytes
//   0x0857f8: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x0857fc: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x085800: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x085804: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1191_0x0857f8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0857f8ULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x0c6510ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1192 | PC: 0x0859b0 | FDE: 0x0c6538 | Size: 224 bytes
// Hàm FDE #1192 | Địa chỉ PC: 0x0859b0 | Địa chỉ FDE: 0x0c6538 | Kích thước: 224 bytes
//   0x0859b0: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x0859b4: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0859b8: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0859bc: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1192_0x0859b0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0859b0ULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x0c6538ULL;
    acc ^= (acc >> 17) * 0x00e0ULL;
    return acc;
}

// FDE #1193 | PC: 0x085a90 | FDE: 0x0c6560 | Size: 180 bytes
// Hàm FDE #1193 | Địa chỉ PC: 0x085a90 | Địa chỉ FDE: 0x0c6560 | Kích thước: 180 bytes
//   0x085a90: F81C0FF7  str      x23, [sp, #-0x40]!
//   0x085a94: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x085a98: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x085a9c: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_1193_0x085a90(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x085a90ULL ^ (static_cast<uint64_t>(0xf81c0ff7ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x0c6560ULL;
    acc ^= (acc >> 17) * 0x00b4ULL;
    return acc;
}

// FDE #1194 | PC: 0x085b44 | FDE: 0x0c6bf8 | Size: 256 bytes
// Hàm FDE #1194 | Địa chỉ PC: 0x085b44 | Địa chỉ FDE: 0x0c6bf8 | Kích thước: 256 bytes
//   0x085b44: D10143FF  sub      sp, sp, #0x50
//   0x085b48: F90013F5  str      x21, [sp, #0x20]
//   0x085b4c: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x085b50: A9047BFD  stp      x29, x30, [sp, #0x40]
static inline uint64_t fde_func_1194_0x085b44(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x085b44ULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xf90013f5ULL) ^ 0x0c6bf8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1195 | PC: 0x085c6c | FDE: 0x0c6c20 | Size: 256 bytes
// Hàm FDE #1195 | Địa chỉ PC: 0x085c6c | Địa chỉ FDE: 0x0c6c20 | Kích thước: 256 bytes
//   0x085c6c: A9BC5FF8  stp      x24, x23, [sp, #-0x40]!
//   0x085c70: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x085c74: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x085c78: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_1195_0x085c6c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x085c6cULL ^ (static_cast<uint64_t>(0xa9bc5ff8ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x0c6c20ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1196 | PC: 0x085ed4 | FDE: 0x0c6c50 | Size: 256 bytes
// Hàm FDE #1196 | Địa chỉ PC: 0x085ed4 | Địa chỉ FDE: 0x0c6c50 | Kích thước: 256 bytes
//   0x085ed4: D101C3FF  sub      sp, sp, #0x70
//   0x085ed8: F9000BFB  str      x27, [sp, #0x10]
//   0x085edc: A90267FA  stp      x26, x25, [sp, #0x20]
//   0x085ee0: A9035FF8  stp      x24, x23, [sp, #0x30]
static inline uint64_t fde_func_1196_0x085ed4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x085ed4ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xf9000bfbULL) ^ 0x0c6c50ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1197 | PC: 0x0860a0 | FDE: 0x0c6588 | Size: 192 bytes
// Hàm FDE #1197 | Địa chỉ PC: 0x0860a0 | Địa chỉ FDE: 0x0c6588 | Kích thước: 192 bytes
//   0x0860a0: D10183FF  sub      sp, sp, #0x60
//   0x0860a4: F90013F7  str      x23, [sp, #0x20]
//   0x0860a8: A90357F6  stp      x22, x21, [sp, #0x30]
//   0x0860ac: A9044FF4  stp      x20, x19, [sp, #0x40]
static inline uint64_t fde_func_1197_0x0860a0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0860a0ULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xf90013f7ULL) ^ 0x0c6588ULL;
    acc ^= (acc >> 17) * 0x00c0ULL;
    return acc;
}

// FDE #1198 | PC: 0x086160 | FDE: 0x0c65b0 | Size: 256 bytes
// Hàm FDE #1198 | Địa chỉ PC: 0x086160 | Địa chỉ FDE: 0x0c65b0 | Kích thước: 256 bytes
//   0x086160: F9400409  ldr      x9, [x0, #8]
//   0x086164: F940042A  ldr      x10, [x1, #8]
//   0x086168: 9E670120  fmov     d0, x9
//   0x08616c: 0E205800  cnt      v0.8b, v0.8b
static inline uint64_t fde_func_1198_0x086160(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x086160ULL ^ (static_cast<uint64_t>(0xf9400409ULL) << 13);
    acc = (acc + a1 + 0xf940042aULL) ^ 0x0c65b0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1199 | PC: 0x0862ac | FDE: 0x0c65c8 | Size: 256 bytes
// Hàm FDE #1199 | Địa chỉ PC: 0x0862ac | Địa chỉ FDE: 0x0c65c8 | Kích thước: 256 bytes
//   0x0862ac: F9400409  ldr      x9, [x0, #8]
//   0x0862b0: F940042A  ldr      x10, [x1, #8]
//   0x0862b4: 9E670120  fmov     d0, x9
//   0x0862b8: 0E205800  cnt      v0.8b, v0.8b
static inline uint64_t fde_func_1199_0x0862ac(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0862acULL ^ (static_cast<uint64_t>(0xf9400409ULL) << 13);
    acc = (acc + a1 + 0xf940042aULL) ^ 0x0c65c8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1200 | PC: 0x0863f8 | FDE: 0x0c6c88 | Size: 256 bytes
// Hàm FDE #1200 | Địa chỉ PC: 0x0863f8 | Địa chỉ FDE: 0x0c6c88 | Kích thước: 256 bytes
//   0x0863f8: F81B0FF9  str      x25, [sp, #-0x50]!
//   0x0863fc: A9015FF8  stp      x24, x23, [sp, #0x10]
//   0x086400: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x086404: A9034FF4  stp      x20, x19, [sp, #0x30]
static inline uint64_t fde_func_1200_0x0863f8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0863f8ULL ^ (static_cast<uint64_t>(0xf81b0ff9ULL) << 13);
    acc = (acc + a1 + 0xa9015ff8ULL) ^ 0x0c6c88ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1201 | PC: 0x086640 | FDE: 0x0c65e0 | Size: 256 bytes
// Hàm FDE #1201 | Địa chỉ PC: 0x086640 | Địa chỉ FDE: 0x0c65e0 | Kích thước: 256 bytes
//   0x086640: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x086644: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x086648: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x08664c: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1201_0x086640(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x086640ULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x0c65e0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1202 | PC: 0x0867f8 | FDE: 0x0c6608 | Size: 256 bytes
// Hàm FDE #1202 | Địa chỉ PC: 0x0867f8 | Địa chỉ FDE: 0x0c6608 | Kích thước: 256 bytes
//   0x0867f8: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x0867fc: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x086800: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x086804: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1202_0x0867f8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0867f8ULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x0c6608ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1203 | PC: 0x086a00 | FDE: 0x0c6630 | Size: 256 bytes
// Hàm FDE #1203 | Địa chỉ PC: 0x086a00 | Địa chỉ FDE: 0x0c6630 | Kích thước: 256 bytes
//   0x086a00: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x086a04: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x086a08: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x086a0c: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1203_0x086a00(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x086a00ULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x0c6630ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1204 | PC: 0x086d18 | FDE: 0x0c6658 | Size: 184 bytes
// Hàm FDE #1204 | Địa chỉ PC: 0x086d18 | Địa chỉ FDE: 0x0c6658 | Kích thước: 184 bytes
//   0x086d18: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x086d1c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x086d20: 910043FD  add      x29, sp, #0x10
//   0x086d24: 90000328  adrp     x8, #0xea000
static inline uint64_t fde_func_1204_0x086d18(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x086d18ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x0c6658ULL;
    acc ^= (acc >> 17) * 0x00b8ULL;
    return acc;
}

// FDE #1205 | PC: 0x086dd0 | FDE: 0x0c6678 | Size: 192 bytes
// Hàm FDE #1205 | Địa chỉ PC: 0x086dd0 | Địa chỉ FDE: 0x0c6678 | Kích thước: 192 bytes
//   0x086dd0: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x086dd4: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x086dd8: 910043FD  add      x29, sp, #0x10
//   0x086ddc: 90000328  adrp     x8, #0xea000
static inline uint64_t fde_func_1205_0x086dd0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x086dd0ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x0c6678ULL;
    acc ^= (acc >> 17) * 0x00c0ULL;
    return acc;
}

// FDE #1206 | PC: 0x086e90 | FDE: 0x0c6698 | Size: 12 bytes
// Hàm FDE #1206 | Địa chỉ PC: 0x086e90 | Địa chỉ FDE: 0x0c6698 | Kích thước: 12 bytes
//   0x086e90: F8418C08  ldr      x8, [x0, #0x18]!
//   0x086e94: F9400101  ldr      x1, [x8]
//   0x086e98: D61F0020  br       x1
static inline uint64_t fde_func_1206_0x086e90(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x086e90ULL ^ (static_cast<uint64_t>(0xf8418c08ULL) << 13);
    acc = (acc + a1 + 0xf9400101ULL) ^ 0x0c6698ULL;
    acc ^= (acc >> 17) * 0x000cULL;
    return acc;
}

// FDE #1207 | PC: 0x086e9c | FDE: 0x0c66b0 | Size: 4 bytes
// Hàm FDE #1207 | Địa chỉ PC: 0x086e9c | Địa chỉ FDE: 0x0c66b0 | Kích thước: 4 bytes
//   0x086e9c: 17FE2E59  b        #0x12800
static inline uint64_t fde_func_1207_0x086e9c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x086e9cULL ^ (static_cast<uint64_t>(0x17fe2e59ULL) << 13);
    acc = (acc + a1 + 0xd10143ffULL) ^ 0x0c66b0ULL;
    acc ^= (acc >> 17) * 0x0004ULL;
    return acc;
}

// FDE #1208 | PC: 0x086ea0 | FDE: 0x0c6cb8 | Size: 256 bytes
// Hàm FDE #1208 | Địa chỉ PC: 0x086ea0 | Địa chỉ FDE: 0x0c6cb8 | Kích thước: 256 bytes
//   0x086ea0: D10143FF  sub      sp, sp, #0x50
//   0x086ea4: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x086ea8: A9047BFD  stp      x29, x30, [sp, #0x40]
//   0x086eac: 910103FD  add      x29, sp, #0x40
static inline uint64_t fde_func_1208_0x086ea0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x086ea0ULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xa9034ff4ULL) ^ 0x0c6cb8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1209 | PC: 0x087014 | FDE: 0x0c66c8 | Size: 256 bytes
// Hàm FDE #1209 | Địa chỉ PC: 0x087014 | Địa chỉ FDE: 0x0c66c8 | Kích thước: 256 bytes
//   0x087014: F81B0FF9  str      x25, [sp, #-0x50]!
//   0x087018: A9015FF8  stp      x24, x23, [sp, #0x10]
//   0x08701c: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x087020: A9034FF4  stp      x20, x19, [sp, #0x30]
static inline uint64_t fde_func_1209_0x087014(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x087014ULL ^ (static_cast<uint64_t>(0xf81b0ff9ULL) << 13);
    acc = (acc + a1 + 0xa9015ff8ULL) ^ 0x0c66c8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1210 | PC: 0x087188 | FDE: 0x0c66f0 | Size: 256 bytes
// Hàm FDE #1210 | Địa chỉ PC: 0x087188 | Địa chỉ FDE: 0x0c66f0 | Kích thước: 256 bytes
//   0x087188: A9BC5FF8  stp      x24, x23, [sp, #-0x40]!
//   0x08718c: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x087190: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x087194: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_1210_0x087188(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x087188ULL ^ (static_cast<uint64_t>(0xa9bc5ff8ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x0c66f0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1211 | PC: 0x0872f0 | FDE: 0x0c6ce0 | Size: 256 bytes
// Hàm FDE #1211 | Địa chỉ PC: 0x0872f0 | Địa chỉ FDE: 0x0c6ce0 | Kích thước: 256 bytes
//   0x0872f0: D10203FF  sub      sp, sp, #0x80
//   0x0872f4: A9026FFC  stp      x28, x27, [sp, #0x20]
//   0x0872f8: A90367FA  stp      x26, x25, [sp, #0x30]
//   0x0872fc: A9045FF8  stp      x24, x23, [sp, #0x40]
static inline uint64_t fde_func_1211_0x0872f0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0872f0ULL ^ (static_cast<uint64_t>(0xd10203ffULL) << 13);
    acc = (acc + a1 + 0xa9026ffcULL) ^ 0x0c6ce0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1212 | PC: 0x087634 | FDE: 0x0c6718 | Size: 228 bytes
// Hàm FDE #1212 | Địa chỉ PC: 0x087634 | Địa chỉ FDE: 0x0c6718 | Kích thước: 228 bytes
//   0x087634: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x087638: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x08763c: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x087640: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1212_0x087634(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x087634ULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x0c6718ULL;
    acc ^= (acc >> 17) * 0x00e4ULL;
    return acc;
}

// FDE #1213 | PC: 0x087718 | FDE: 0x0c6738 | Size: 256 bytes
// Hàm FDE #1213 | Địa chỉ PC: 0x087718 | Địa chỉ FDE: 0x0c6738 | Kích thước: 256 bytes
//   0x087718: D10203FF  sub      sp, sp, #0x80
//   0x08771c: A9026FFC  stp      x28, x27, [sp, #0x20]
//   0x087720: A90367FA  stp      x26, x25, [sp, #0x30]
//   0x087724: A9045FF8  stp      x24, x23, [sp, #0x40]
static inline uint64_t fde_func_1213_0x087718(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x087718ULL ^ (static_cast<uint64_t>(0xd10203ffULL) << 13);
    acc = (acc + a1 + 0xa9026ffcULL) ^ 0x0c6738ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1214 | PC: 0x087988 | FDE: 0x0c6d18 | Size: 256 bytes
// Hàm FDE #1214 | Địa chỉ PC: 0x087988 | Địa chỉ FDE: 0x0c6d18 | Kích thước: 256 bytes
//   0x087988: F81B0FF9  str      x25, [sp, #-0x50]!
//   0x08798c: A9015FF8  stp      x24, x23, [sp, #0x10]
//   0x087990: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x087994: A9034FF4  stp      x20, x19, [sp, #0x30]
static inline uint64_t fde_func_1214_0x087988(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x087988ULL ^ (static_cast<uint64_t>(0xf81b0ff9ULL) << 13);
    acc = (acc + a1 + 0xa9015ff8ULL) ^ 0x0c6d18ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1215 | PC: 0x087c08 | FDE: 0x0c6768 | Size: 228 bytes
// Hàm FDE #1215 | Địa chỉ PC: 0x087c08 | Địa chỉ FDE: 0x0c6768 | Kích thước: 228 bytes
//   0x087c08: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x087c0c: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x087c10: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x087c14: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1215_0x087c08(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x087c08ULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x0c6768ULL;
    acc ^= (acc >> 17) * 0x00e4ULL;
    return acc;
}

// FDE #1216 | PC: 0x087cec | FDE: 0x0c6788 | Size: 256 bytes
// Hàm FDE #1216 | Địa chỉ PC: 0x087cec | Địa chỉ FDE: 0x0c6788 | Kích thước: 256 bytes
//   0x087cec: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x087cf0: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x087cf4: 910043FD  add      x29, sp, #0x10
//   0x087cf8: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_1216_0x087cec(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x087cecULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x0c6788ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1217 | PC: 0x087e74 | FDE: 0x0c6d48 | Size: 256 bytes
// Hàm FDE #1217 | Địa chỉ PC: 0x087e74 | Địa chỉ FDE: 0x0c6d48 | Kích thước: 256 bytes
//   0x087e74: F81C0FF7  str      x23, [sp, #-0x40]!
//   0x087e78: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x087e7c: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x087e80: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_1217_0x087e74(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x087e74ULL ^ (static_cast<uint64_t>(0xf81c0ff7ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x0c6d48ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1218 | PC: 0x087fbc | FDE: 0x0c67a8 | Size: 256 bytes
// Hàm FDE #1218 | Địa chỉ PC: 0x087fbc | Địa chỉ FDE: 0x0c67a8 | Kích thước: 256 bytes
//   0x087fbc: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x087fc0: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x087fc4: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x087fc8: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1218_0x087fbc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x087fbcULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x0c67a8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1219 | PC: 0x0880f0 | FDE: 0x0c67c8 | Size: 256 bytes
// Hàm FDE #1219 | Địa chỉ PC: 0x0880f0 | Địa chỉ FDE: 0x0c67c8 | Kích thước: 256 bytes
//   0x0880f0: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x0880f4: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0880f8: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0880fc: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1219_0x0880f0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0880f0ULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x0c67c8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1220 | PC: 0x088250 | FDE: 0x0c6d78 | Size: 140 bytes
// Hàm FDE #1220 | Địa chỉ PC: 0x088250 | Địa chỉ FDE: 0x0c6d78 | Kích thước: 140 bytes
//   0x088250: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x088254: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x088258: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x08825c: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1220_0x088250(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x088250ULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x0c6d78ULL;
    acc ^= (acc >> 17) * 0x008cULL;
    return acc;
}

// FDE #1221 | PC: 0x0882dc | FDE: 0x0c6da8 | Size: 256 bytes
// Hàm FDE #1221 | Địa chỉ PC: 0x0882dc | Địa chỉ FDE: 0x0c6da8 | Kích thước: 256 bytes
//   0x0882dc: D10203FF  sub      sp, sp, #0x80
//   0x0882e0: F90023F7  str      x23, [sp, #0x40]
//   0x0882e4: A90557F6  stp      x22, x21, [sp, #0x50]
//   0x0882e8: A9064FF4  stp      x20, x19, [sp, #0x60]
static inline uint64_t fde_func_1221_0x0882dc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0882dcULL ^ (static_cast<uint64_t>(0xd10203ffULL) << 13);
    acc = (acc + a1 + 0xf90023f7ULL) ^ 0x0c6da8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1222 | PC: 0x08843c | FDE: 0x0c6dd8 | Size: 256 bytes
// Hàm FDE #1222 | Địa chỉ PC: 0x08843c | Địa chỉ FDE: 0x0c6dd8 | Kích thước: 256 bytes
//   0x08843c: D10183FF  sub      sp, sp, #0x60
//   0x088440: F9001BF5  str      x21, [sp, #0x30]
//   0x088444: A9044FF4  stp      x20, x19, [sp, #0x40]
//   0x088448: A9057BFD  stp      x29, x30, [sp, #0x50]
static inline uint64_t fde_func_1222_0x08843c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x08843cULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xf9001bf5ULL) ^ 0x0c6dd8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1223 | PC: 0x08857c | FDE: 0x0c6e00 | Size: 256 bytes
// Hàm FDE #1223 | Địa chỉ PC: 0x08857c | Địa chỉ FDE: 0x0c6e00 | Kích thước: 256 bytes
//   0x08857c: D102C3FF  sub      sp, sp, #0xb0
//   0x088580: F9003BF7  str      x23, [sp, #0x70]
//   0x088584: A90857F6  stp      x22, x21, [sp, #0x80]
//   0x088588: A9094FF4  stp      x20, x19, [sp, #0x90]
static inline uint64_t fde_func_1223_0x08857c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x08857cULL ^ (static_cast<uint64_t>(0xd102c3ffULL) << 13);
    acc = (acc + a1 + 0xf9003bf7ULL) ^ 0x0c6e00ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1224 | PC: 0x088870 | FDE: 0x0c6e30 | Size: 256 bytes
// Hàm FDE #1224 | Địa chỉ PC: 0x088870 | Địa chỉ FDE: 0x0c6e30 | Kích thước: 256 bytes
//   0x088870: D101C3FF  sub      sp, sp, #0x70
//   0x088874: A90457F6  stp      x22, x21, [sp, #0x40]
//   0x088878: A9054FF4  stp      x20, x19, [sp, #0x50]
//   0x08887c: A9067BFD  stp      x29, x30, [sp, #0x60]
static inline uint64_t fde_func_1224_0x088870(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x088870ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xa90457f6ULL) ^ 0x0c6e30ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1225 | PC: 0x088d40 | FDE: 0x0c6e60 | Size: 256 bytes
// Hàm FDE #1225 | Địa chỉ PC: 0x088d40 | Địa chỉ FDE: 0x0c6e60 | Kích thước: 256 bytes
//   0x088d40: D10383FF  sub      sp, sp, #0xe0
//   0x088d44: F90053F7  str      x23, [sp, #0xa0]
//   0x088d48: A90B57F6  stp      x22, x21, [sp, #0xb0]
//   0x088d4c: A90C4FF4  stp      x20, x19, [sp, #0xc0]
static inline uint64_t fde_func_1225_0x088d40(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x088d40ULL ^ (static_cast<uint64_t>(0xd10383ffULL) << 13);
    acc = (acc + a1 + 0xf90053f7ULL) ^ 0x0c6e60ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1226 | PC: 0x0891a4 | FDE: 0x0c6e90 | Size: 256 bytes
// Hàm FDE #1226 | Địa chỉ PC: 0x0891a4 | Địa chỉ FDE: 0x0c6e90 | Kích thước: 256 bytes
//   0x0891a4: D101C3FF  sub      sp, sp, #0x70
//   0x0891a8: A90457F6  stp      x22, x21, [sp, #0x40]
//   0x0891ac: A9054FF4  stp      x20, x19, [sp, #0x50]
//   0x0891b0: A9067BFD  stp      x29, x30, [sp, #0x60]
static inline uint64_t fde_func_1226_0x0891a4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0891a4ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xa90457f6ULL) ^ 0x0c6e90ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1227 | PC: 0x089970 | FDE: 0x0c6f28 | Size: 256 bytes
// Hàm FDE #1227 | Địa chỉ PC: 0x089970 | Địa chỉ FDE: 0x0c6f28 | Kích thước: 256 bytes
//   0x089970: D10203FF  sub      sp, sp, #0x80
//   0x089974: F90023F7  str      x23, [sp, #0x40]
//   0x089978: A90557F6  stp      x22, x21, [sp, #0x50]
//   0x08997c: A9064FF4  stp      x20, x19, [sp, #0x60]
static inline uint64_t fde_func_1227_0x089970(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x089970ULL ^ (static_cast<uint64_t>(0xd10203ffULL) << 13);
    acc = (acc + a1 + 0xf90023f7ULL) ^ 0x0c6f28ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1228 | PC: 0x089b04 | FDE: 0x0c6f58 | Size: 256 bytes
// Hàm FDE #1228 | Địa chỉ PC: 0x089b04 | Địa chỉ FDE: 0x0c6f58 | Kích thước: 256 bytes
//   0x089b04: D10203FF  sub      sp, sp, #0x80
//   0x089b08: F90023F7  str      x23, [sp, #0x40]
//   0x089b0c: A90557F6  stp      x22, x21, [sp, #0x50]
//   0x089b10: A9064FF4  stp      x20, x19, [sp, #0x60]
static inline uint64_t fde_func_1228_0x089b04(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x089b04ULL ^ (static_cast<uint64_t>(0xd10203ffULL) << 13);
    acc = (acc + a1 + 0xf90023f7ULL) ^ 0x0c6f58ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1229 | PC: 0x089d08 | FDE: 0x0c6f88 | Size: 256 bytes
// Hàm FDE #1229 | Địa chỉ PC: 0x089d08 | Địa chỉ FDE: 0x0c6f88 | Kích thước: 256 bytes
//   0x089d08: F81C0FF7  str      x23, [sp, #-0x40]!
//   0x089d0c: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x089d10: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x089d14: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_1229_0x089d08(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x089d08ULL ^ (static_cast<uint64_t>(0xf81c0ff7ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x0c6f88ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1230 | PC: 0x089e0c | FDE: 0x0c6fb8 | Size: 256 bytes
// Hàm FDE #1230 | Địa chỉ PC: 0x089e0c | Địa chỉ FDE: 0x0c6fb8 | Kích thước: 256 bytes
//   0x089e0c: D101C3FF  sub      sp, sp, #0x70
//   0x089e10: F90023F5  str      x21, [sp, #0x40]
//   0x089e14: A9054FF4  stp      x20, x19, [sp, #0x50]
//   0x089e18: A9067BFD  stp      x29, x30, [sp, #0x60]
static inline uint64_t fde_func_1230_0x089e0c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x089e0cULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xf90023f5ULL) ^ 0x0c6fb8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1231 | PC: 0x089f64 | FDE: 0x0c6fe0 | Size: 256 bytes
// Hàm FDE #1231 | Địa chỉ PC: 0x089f64 | Địa chỉ FDE: 0x0c6fe0 | Kích thước: 256 bytes
//   0x089f64: D10243FF  sub      sp, sp, #0x90
//   0x089f68: A90657F6  stp      x22, x21, [sp, #0x60]
//   0x089f6c: A9074FF4  stp      x20, x19, [sp, #0x70]
//   0x089f70: A9087BFD  stp      x29, x30, [sp, #0x80]
static inline uint64_t fde_func_1231_0x089f64(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x089f64ULL ^ (static_cast<uint64_t>(0xd10243ffULL) << 13);
    acc = (acc + a1 + 0xa90657f6ULL) ^ 0x0c6fe0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1232 | PC: 0x08a130 | FDE: 0x0c6ec0 | Size: 256 bytes
// Hàm FDE #1232 | Địa chỉ PC: 0x08a130 | Địa chỉ FDE: 0x0c6ec0 | Kích thước: 256 bytes
//   0x08a130: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x08a134: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x08a138: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x08a13c: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1232_0x08a130(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x08a130ULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x0c6ec0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1233 | PC: 0x08a34c | FDE: 0x0c7010 | Size: 256 bytes
// Hàm FDE #1233 | Địa chỉ PC: 0x08a34c | Địa chỉ FDE: 0x0c7010 | Kích thước: 256 bytes
//   0x08a34c: D10483FF  sub      sp, sp, #0x120
//   0x08a350: F9006BFC  str      x28, [sp, #0xd0]
//   0x08a354: A90E5FF8  stp      x24, x23, [sp, #0xe0]
//   0x08a358: A90F57F6  stp      x22, x21, [sp, #0xf0]
static inline uint64_t fde_func_1233_0x08a34c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x08a34cULL ^ (static_cast<uint64_t>(0xd10483ffULL) << 13);
    acc = (acc + a1 + 0xf9006bfcULL) ^ 0x0c7010ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1234 | PC: 0x08a5bc | FDE: 0x0c7040 | Size: 256 bytes
// Hàm FDE #1234 | Địa chỉ PC: 0x08a5bc | Địa chỉ FDE: 0x0c7040 | Kích thước: 256 bytes
//   0x08a5bc: D101C3FF  sub      sp, sp, #0x70
//   0x08a5c0: A9035FF8  stp      x24, x23, [sp, #0x30]
//   0x08a5c4: A90457F6  stp      x22, x21, [sp, #0x40]
//   0x08a5c8: A9054FF4  stp      x20, x19, [sp, #0x50]
static inline uint64_t fde_func_1234_0x08a5bc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x08a5bcULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xa9035ff8ULL) ^ 0x0c7040ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1235 | PC: 0x08aa20 | FDE: 0x0c6ee8 | Size: 256 bytes
// Hàm FDE #1235 | Địa chỉ PC: 0x08aa20 | Địa chỉ FDE: 0x0c6ee8 | Kích thước: 256 bytes
//   0x08aa20: F81B0FF9  str      x25, [sp, #-0x50]!
//   0x08aa24: A9015FF8  stp      x24, x23, [sp, #0x10]
//   0x08aa28: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x08aa2c: A9034FF4  stp      x20, x19, [sp, #0x30]
static inline uint64_t fde_func_1235_0x08aa20(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x08aa20ULL ^ (static_cast<uint64_t>(0xf81b0ff9ULL) << 13);
    acc = (acc + a1 + 0xa9015ff8ULL) ^ 0x0c6ee8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1236 | PC: 0x08adec | FDE: 0x0c6f10 | Size: 256 bytes
// Hàm FDE #1236 | Địa chỉ PC: 0x08adec | Địa chỉ FDE: 0x0c6f10 | Kích thước: 256 bytes
//   0x08adec: AA0003E8  mov      x8, x0
//   0x08adf0: F940000A  ldr      x10, [x0]
//   0x08adf4: F9400420  ldr      x0, [x1, #8]
//   0x08adf8: EB02015F  cmp      x10, x2
static inline uint64_t fde_func_1236_0x08adec(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x08adecULL ^ (static_cast<uint64_t>(0xaa0003e8ULL) << 13);
    acc = (acc + a1 + 0xf940000aULL) ^ 0x0c6f10ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1237 | PC: 0x08b090 | FDE: 0x0c7350 | Size: 256 bytes
// Hàm FDE #1237 | Địa chỉ PC: 0x08b090 | Địa chỉ FDE: 0x0c7350 | Kích thước: 256 bytes
//   0x08b090: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x08b094: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x08b098: 910043FD  add      x29, sp, #0x10
//   0x08b09c: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_1237_0x08b090(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x08b090ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x0c7350ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1238 | PC: 0x08b218 | FDE: 0x0c7070 | Size: 20 bytes
// Hàm FDE #1238 | Địa chỉ PC: 0x08b218 | Địa chỉ FDE: 0x0c7070 | Kích thước: 20 bytes
//   0x08b218: F9400001  ldr      x1, [x0]
//   0x08b21c: F900001F  str      xzr, [x0]
//   0x08b220: B4000041  cbz      x1, #0x8b228
//   0x08b224: 14005C13  b        #0xa2270
static inline uint64_t fde_func_1238_0x08b218(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x08b218ULL ^ (static_cast<uint64_t>(0xf9400001ULL) << 13);
    acc = (acc + a1 + 0xf900001fULL) ^ 0x0c7070ULL;
    acc ^= (acc >> 17) * 0x0014ULL;
    return acc;
}

// FDE #1239 | PC: 0x08b22c | FDE: 0x0c7378 | Size: 256 bytes
// Hàm FDE #1239 | Địa chỉ PC: 0x08b22c | Địa chỉ FDE: 0x0c7378 | Kích thước: 256 bytes
//   0x08b22c: D10383FF  sub      sp, sp, #0xe0
//   0x08b230: A9086FFC  stp      x28, x27, [sp, #0x80]
//   0x08b234: A90967FA  stp      x26, x25, [sp, #0x90]
//   0x08b238: A90A5FF8  stp      x24, x23, [sp, #0xa0]
static inline uint64_t fde_func_1239_0x08b22c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x08b22cULL ^ (static_cast<uint64_t>(0xd10383ffULL) << 13);
    acc = (acc + a1 + 0xa9086ffcULL) ^ 0x0c7378ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1240 | PC: 0x08b540 | FDE: 0x0c7088 | Size: 156 bytes
// Hàm FDE #1240 | Địa chỉ PC: 0x08b540 | Địa chỉ FDE: 0x0c7088 | Kích thước: 156 bytes
//   0x08b540: D10483FF  sub      sp, sp, #0x120
//   0x08b544: A9104FFC  stp      x28, x19, [sp, #0x100]
//   0x08b548: A9117BFD  stp      x29, x30, [sp, #0x110]
//   0x08b54c: 910443FD  add      x29, sp, #0x110
static inline uint64_t fde_func_1240_0x08b540(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x08b540ULL ^ (static_cast<uint64_t>(0xd10483ffULL) << 13);
    acc = (acc + a1 + 0xa9104ffcULL) ^ 0x0c7088ULL;
    acc ^= (acc >> 17) * 0x009cULL;
    return acc;
}

// FDE #1241 | PC: 0x08b5dc | FDE: 0x0c73b0 | Size: 256 bytes
// Hàm FDE #1241 | Địa chỉ PC: 0x08b5dc | Địa chỉ FDE: 0x0c73b0 | Kích thước: 256 bytes
//   0x08b5dc: D105C3FF  sub      sp, sp, #0x170
//   0x08b5e0: A9116FFC  stp      x28, x27, [sp, #0x110]
//   0x08b5e4: A91267FA  stp      x26, x25, [sp, #0x120]
//   0x08b5e8: A9135FF8  stp      x24, x23, [sp, #0x130]
static inline uint64_t fde_func_1241_0x08b5dc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x08b5dcULL ^ (static_cast<uint64_t>(0xd105c3ffULL) << 13);
    acc = (acc + a1 + 0xa9116ffcULL) ^ 0x0c73b0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1242 | PC: 0x08bb4c | FDE: 0x0c7410 | Size: 220 bytes
// Hàm FDE #1242 | Địa chỉ PC: 0x08bb4c | Địa chỉ FDE: 0x0c7410 | Kích thước: 220 bytes
//   0x08bb4c: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x08bb50: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x08bb54: 910043FD  add      x29, sp, #0x10
//   0x08bb58: 52800300  mov      w0, #0x18
static inline uint64_t fde_func_1242_0x08bb4c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x08bb4cULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x0c7410ULL;
    acc ^= (acc >> 17) * 0x00dcULL;
    return acc;
}

// FDE #1243 | PC: 0x08bc28 | FDE: 0x0c70c8 | Size: 72 bytes
// Hàm FDE #1243 | Địa chỉ PC: 0x08bc28 | Địa chỉ FDE: 0x0c70c8 | Kích thước: 72 bytes
//   0x08bc28: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x08bc2c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x08bc30: 910043FD  add      x29, sp, #0x10
//   0x08bc34: F9400013  ldr      x19, [x0]
static inline uint64_t fde_func_1243_0x08bc28(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x08bc28ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x0c70c8ULL;
    acc ^= (acc >> 17) * 0x0048ULL;
    return acc;
}

// FDE #1244 | PC: 0x08bc70 | FDE: 0x0c7460 | Size: 216 bytes
// Hàm FDE #1244 | Địa chỉ PC: 0x08bc70 | Địa chỉ FDE: 0x0c7460 | Kích thước: 216 bytes
//   0x08bc70: D10143FF  sub      sp, sp, #0x50
//   0x08bc74: F90013F5  str      x21, [sp, #0x20]
//   0x08bc78: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x08bc7c: A9047BFD  stp      x29, x30, [sp, #0x40]
static inline uint64_t fde_func_1244_0x08bc70(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x08bc70ULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xf90013f5ULL) ^ 0x0c7460ULL;
    acc ^= (acc >> 17) * 0x00d8ULL;
    return acc;
}

// FDE #1245 | PC: 0x08bd48 | FDE: 0x0c7108 | Size: 72 bytes
// Hàm FDE #1245 | Địa chỉ PC: 0x08bd48 | Địa chỉ FDE: 0x0c7108 | Kích thước: 72 bytes
//   0x08bd48: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x08bd4c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x08bd50: 910043FD  add      x29, sp, #0x10
//   0x08bd54: F9400013  ldr      x19, [x0]
static inline uint64_t fde_func_1245_0x08bd48(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x08bd48ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x0c7108ULL;
    acc ^= (acc >> 17) * 0x0048ULL;
    return acc;
}

// FDE #1246 | PC: 0x08bd90 | FDE: 0x0c74b0 | Size: 216 bytes
// Hàm FDE #1246 | Địa chỉ PC: 0x08bd90 | Địa chỉ FDE: 0x0c74b0 | Kích thước: 216 bytes
//   0x08bd90: D10143FF  sub      sp, sp, #0x50
//   0x08bd94: F90013F5  str      x21, [sp, #0x20]
//   0x08bd98: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x08bd9c: A9047BFD  stp      x29, x30, [sp, #0x40]
static inline uint64_t fde_func_1246_0x08bd90(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x08bd90ULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xf90013f5ULL) ^ 0x0c74b0ULL;
    acc ^= (acc >> 17) * 0x00d8ULL;
    return acc;
}

// FDE #1247 | PC: 0x08be68 | FDE: 0x0c7148 | Size: 72 bytes
// Hàm FDE #1247 | Địa chỉ PC: 0x08be68 | Địa chỉ FDE: 0x0c7148 | Kích thước: 72 bytes
//   0x08be68: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x08be6c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x08be70: 910043FD  add      x29, sp, #0x10
//   0x08be74: F9400013  ldr      x19, [x0]
static inline uint64_t fde_func_1247_0x08be68(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x08be68ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x0c7148ULL;
    acc ^= (acc >> 17) * 0x0048ULL;
    return acc;
}

// FDE #1248 | PC: 0x08beb0 | FDE: 0x0c7500 | Size: 112 bytes
// Hàm FDE #1248 | Địa chỉ PC: 0x08beb0 | Địa chỉ FDE: 0x0c7500 | Kích thước: 112 bytes
//   0x08beb0: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x08beb4: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x08beb8: 910043FD  add      x29, sp, #0x10
//   0x08bebc: 52800B00  mov      w0, #0x58
static inline uint64_t fde_func_1248_0x08beb0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x08beb0ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x0c7500ULL;
    acc ^= (acc >> 17) * 0x0070ULL;
    return acc;
}

// FDE #1249 | PC: 0x08bf20 | FDE: 0x0c7188 | Size: 72 bytes
// Hàm FDE #1249 | Địa chỉ PC: 0x08bf20 | Địa chỉ FDE: 0x0c7188 | Kích thước: 72 bytes
//   0x08bf20: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x08bf24: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x08bf28: 910043FD  add      x29, sp, #0x10
//   0x08bf2c: F9400013  ldr      x19, [x0]
static inline uint64_t fde_func_1249_0x08bf20(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x08bf20ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x0c7188ULL;
    acc ^= (acc >> 17) * 0x0048ULL;
    return acc;
}

// FDE #1250 | PC: 0x08bf68 | FDE: 0x0c7550 | Size: 256 bytes
// Hàm FDE #1250 | Địa chỉ PC: 0x08bf68 | Địa chỉ FDE: 0x0c7550 | Kích thước: 256 bytes
//   0x08bf68: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x08bf6c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x08bf70: 910043FD  add      x29, sp, #0x10
//   0x08bf74: 52800500  mov      w0, #0x28
static inline uint64_t fde_func_1250_0x08bf68(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x08bf68ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x0c7550ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1251 | PC: 0x08c088 | FDE: 0x0c71c8 | Size: 72 bytes
// Hàm FDE #1251 | Địa chỉ PC: 0x08c088 | Địa chỉ FDE: 0x0c71c8 | Kích thước: 72 bytes
//   0x08c088: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x08c08c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x08c090: 910043FD  add      x29, sp, #0x10
//   0x08c094: F9400013  ldr      x19, [x0]
static inline uint64_t fde_func_1251_0x08c088(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x08c088ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x0c71c8ULL;
    acc ^= (acc >> 17) * 0x0048ULL;
    return acc;
}

// FDE #1252 | PC: 0x08c0d0 | FDE: 0x0c71e8 | Size: 4 bytes
// Hàm FDE #1252 | Địa chỉ PC: 0x08c0d0 | Địa chỉ FDE: 0x0c71e8 | Kích thước: 4 bytes
//   0x08c0d0: 17FE19CC  b        #0x12800
static inline uint64_t fde_func_1252_0x08c0d0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x08c0d0ULL ^ (static_cast<uint64_t>(0x17fe19ccULL) << 13);
    acc = (acc + a1 + 0xf81e0ff3ULL) ^ 0x0c71e8ULL;
    acc ^= (acc >> 17) * 0x0004ULL;
    return acc;
}

// FDE #1253 | PC: 0x08c0d4 | FDE: 0x0c7200 | Size: 56 bytes
// Hàm FDE #1253 | Địa chỉ PC: 0x08c0d4 | Địa chỉ FDE: 0x0c7200 | Kích thước: 56 bytes
//   0x08c0d4: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x08c0d8: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x08c0dc: 910043FD  add      x29, sp, #0x10
//   0x08c0e0: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_1253_0x08c0d4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x08c0d4ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x0c7200ULL;
    acc ^= (acc >> 17) * 0x0038ULL;
    return acc;
}

// FDE #1254 | PC: 0x08c10c | FDE: 0x0c7220 | Size: 24 bytes
// Hàm FDE #1254 | Địa chỉ PC: 0x08c10c | Địa chỉ FDE: 0x0c7220 | Kích thước: 24 bytes
//   0x08c10c: F00002E8  adrp     x8, #0xeb000
//   0x08c110: 91002108  add      x8, x8, #8
//   0x08c114: F9000028  str      x8, [x1]
//   0x08c118: F9400408  ldr      x8, [x0, #8]
static inline uint64_t fde_func_1254_0x08c10c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x08c10cULL ^ (static_cast<uint64_t>(0xf00002e8ULL) << 13);
    acc = (acc + a1 + 0x91002108ULL) ^ 0x0c7220ULL;
    acc ^= (acc >> 17) * 0x0018ULL;
    return acc;
}

// FDE #1255 | PC: 0x08c124 | FDE: 0x0c7238 | Size: 4 bytes
// Hàm FDE #1255 | Địa chỉ PC: 0x08c124 | Địa chỉ FDE: 0x0c7238 | Kích thước: 4 bytes
//   0x08c124: D65F03C0  ret      
static inline uint64_t fde_func_1255_0x08c124(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x08c124ULL ^ (static_cast<uint64_t>(0xd65f03c0ULL) << 13);
    acc = (acc + a1 + 0x17fe19b6ULL) ^ 0x0c7238ULL;
    acc ^= (acc >> 17) * 0x0004ULL;
    return acc;
}

// FDE #1256 | PC: 0x08c128 | FDE: 0x0c7250 | Size: 4 bytes
// Hàm FDE #1256 | Địa chỉ PC: 0x08c128 | Địa chỉ FDE: 0x0c7250 | Kích thước: 4 bytes
//   0x08c128: 17FE19B6  b        #0x12800
static inline uint64_t fde_func_1256_0x08c128(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x08c128ULL ^ (static_cast<uint64_t>(0x17fe19b6ULL) << 13);
    acc = (acc + a1 + 0xf9400400ULL) ^ 0x0c7250ULL;
    acc ^= (acc >> 17) * 0x0004ULL;
    return acc;
}

// FDE #1257 | PC: 0x08c12c | FDE: 0x0c7268 | Size: 8 bytes
// Hàm FDE #1257 | Địa chỉ PC: 0x08c12c | Địa chỉ FDE: 0x0c7268 | Kích thước: 8 bytes
//   0x08c12c: F9400400  ldr      x0, [x0, #8]
//   0x08c130: D61F0000  br       x0
static inline uint64_t fde_func_1257_0x08c12c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x08c12cULL ^ (static_cast<uint64_t>(0xf9400400ULL) << 13);
    acc = (acc + a1 + 0xd61f0000ULL) ^ 0x0c7268ULL;
    acc ^= (acc >> 17) * 0x0008ULL;
    return acc;
}

// FDE #1258 | PC: 0x08c134 | FDE: 0x0c7280 | Size: 28 bytes
// Hàm FDE #1258 | Địa chỉ PC: 0x08c134 | Địa chỉ FDE: 0x0c7280 | Kích thước: 28 bytes
//   0x08c134: F00002E9  adrp     x9, #0xeb000
//   0x08c138: F9400428  ldr      x8, [x1, #8]
//   0x08c13c: F9471529  ldr      x9, [x9, #0xe28]
//   0x08c140: 9100200A  add      x10, x0, #8
static inline uint64_t fde_func_1258_0x08c134(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x08c134ULL ^ (static_cast<uint64_t>(0xf00002e9ULL) << 13);
    acc = (acc + a1 + 0xf9400428ULL) ^ 0x0c7280ULL;
    acc ^= (acc >> 17) * 0x001cULL;
    return acc;
}

// FDE #1259 | PC: 0x08c150 | FDE: 0x0c7298 | Size: 12 bytes
// Hàm FDE #1259 | Địa chỉ PC: 0x08c150 | Địa chỉ FDE: 0x0c7298 | Kích thước: 12 bytes
//   0x08c150: F00002E0  adrp     x0, #0xeb000
//   0x08c154: F947D800  ldr      x0, [x0, #0xfb0]
//   0x08c158: D65F03C0  ret      
static inline uint64_t fde_func_1259_0x08c150(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x08c150ULL ^ (static_cast<uint64_t>(0xf00002e0ULL) << 13);
    acc = (acc + a1 + 0xf947d800ULL) ^ 0x0c7298ULL;
    acc ^= (acc >> 17) * 0x000cULL;
    return acc;
}

// FDE #1260 | PC: 0x08c15c | FDE: 0x0c72b0 | Size: 4 bytes
// Hàm FDE #1260 | Địa chỉ PC: 0x08c15c | Địa chỉ FDE: 0x0c72b0 | Kích thước: 4 bytes
//   0x08c15c: D65F03C0  ret      
static inline uint64_t fde_func_1260_0x08c15c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x08c15cULL ^ (static_cast<uint64_t>(0xd65f03c0ULL) << 13);
    acc = (acc + a1 + 0xd10143ffULL) ^ 0x0c72b0ULL;
    acc ^= (acc >> 17) * 0x0004ULL;
    return acc;
}

// FDE #1261 | PC: 0x08c160 | FDE: 0x0c7578 | Size: 256 bytes
// Hàm FDE #1261 | Địa chỉ PC: 0x08c160 | Địa chỉ FDE: 0x0c7578 | Kích thước: 256 bytes
//   0x08c160: D10143FF  sub      sp, sp, #0x50
//   0x08c164: A9015FF8  stp      x24, x23, [sp, #0x10]
//   0x08c168: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x08c16c: A9034FF4  stp      x20, x19, [sp, #0x30]
static inline uint64_t fde_func_1261_0x08c160(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x08c160ULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xa9015ff8ULL) ^ 0x0c7578ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1262 | PC: 0x08c294 | FDE: 0x0c72c8 | Size: 156 bytes
// Hàm FDE #1262 | Địa chỉ PC: 0x08c294 | Địa chỉ FDE: 0x0c72c8 | Kích thước: 156 bytes
//   0x08c294: D10483FF  sub      sp, sp, #0x120
//   0x08c298: A9104FFC  stp      x28, x19, [sp, #0x100]
//   0x08c29c: A9117BFD  stp      x29, x30, [sp, #0x110]
//   0x08c2a0: 910443FD  add      x29, sp, #0x110
static inline uint64_t fde_func_1262_0x08c294(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x08c294ULL ^ (static_cast<uint64_t>(0xd10483ffULL) << 13);
    acc = (acc + a1 + 0xa9104ffcULL) ^ 0x0c72c8ULL;
    acc ^= (acc >> 17) * 0x009cULL;
    return acc;
}

// FDE #1263 | PC: 0x08c330 | FDE: 0x0c75a8 | Size: 256 bytes
// Hàm FDE #1263 | Địa chỉ PC: 0x08c330 | Địa chỉ FDE: 0x0c75a8 | Kích thước: 256 bytes
//   0x08c330: D10483FF  sub      sp, sp, #0x120
//   0x08c334: A90C6FFC  stp      x28, x27, [sp, #0xc0]
//   0x08c338: A90D67FA  stp      x26, x25, [sp, #0xd0]
//   0x08c33c: A90E5FF8  stp      x24, x23, [sp, #0xe0]
static inline uint64_t fde_func_1263_0x08c330(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x08c330ULL ^ (static_cast<uint64_t>(0xd10483ffULL) << 13);
    acc = (acc + a1 + 0xa90c6ffcULL) ^ 0x0c75a8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1264 | PC: 0x08c750 | FDE: 0x0c72e8 | Size: 156 bytes
// Hàm FDE #1264 | Địa chỉ PC: 0x08c750 | Địa chỉ FDE: 0x0c72e8 | Kích thước: 156 bytes
//   0x08c750: D10483FF  sub      sp, sp, #0x120
//   0x08c754: A9104FFC  stp      x28, x19, [sp, #0x100]
//   0x08c758: A9117BFD  stp      x29, x30, [sp, #0x110]
//   0x08c75c: 910443FD  add      x29, sp, #0x110
static inline uint64_t fde_func_1264_0x08c750(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x08c750ULL ^ (static_cast<uint64_t>(0xd10483ffULL) << 13);
    acc = (acc + a1 + 0xa9104ffcULL) ^ 0x0c72e8ULL;
    acc ^= (acc >> 17) * 0x009cULL;
    return acc;
}

// FDE #1265 | PC: 0x08c7ec | FDE: 0x0c7308 | Size: 156 bytes
// Hàm FDE #1265 | Địa chỉ PC: 0x08c7ec | Địa chỉ FDE: 0x0c7308 | Kích thước: 156 bytes
//   0x08c7ec: D10483FF  sub      sp, sp, #0x120
//   0x08c7f0: A9104FFC  stp      x28, x19, [sp, #0x100]
//   0x08c7f4: A9117BFD  stp      x29, x30, [sp, #0x110]
//   0x08c7f8: 910443FD  add      x29, sp, #0x110
static inline uint64_t fde_func_1265_0x08c7ec(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x08c7ecULL ^ (static_cast<uint64_t>(0xd10483ffULL) << 13);
    acc = (acc + a1 + 0xa9104ffcULL) ^ 0x0c7308ULL;
    acc ^= (acc >> 17) * 0x009cULL;
    return acc;
}

// FDE #1266 | PC: 0x08c888 | FDE: 0x0c7328 | Size: 256 bytes
// Hàm FDE #1266 | Địa chỉ PC: 0x08c888 | Địa chỉ FDE: 0x0c7328 | Kích thước: 256 bytes
//   0x08c888: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x08c88c: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x08c890: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x08c894: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1266_0x08c888(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x08c888ULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x0c7328ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1267 | PC: 0x08cb64 | FDE: 0x0c7638 | Size: 136 bytes
// Hàm FDE #1267 | Địa chỉ PC: 0x08cb64 | Địa chỉ FDE: 0x0c7638 | Kích thước: 136 bytes
//   0x08cb64: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x08cb68: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x08cb6c: 910043FD  add      x29, sp, #0x10
//   0x08cb70: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_1267_0x08cb64(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x08cb64ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x0c7638ULL;
    acc ^= (acc >> 17) * 0x0088ULL;
    return acc;
}

// FDE #1268 | PC: 0x08cbec | FDE: 0x0c75e0 | Size: 20 bytes
// Hàm FDE #1268 | Địa chỉ PC: 0x08cbec | Địa chỉ FDE: 0x0c75e0 | Kích thước: 20 bytes
//   0x08cbec: F9400001  ldr      x1, [x0]
//   0x08cbf0: F900001F  str      xzr, [x0]
//   0x08cbf4: B4000041  cbz      x1, #0x8cbfc
//   0x08cbf8: 1400559E  b        #0xa2270
static inline uint64_t fde_func_1268_0x08cbec(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x08cbecULL ^ (static_cast<uint64_t>(0xf9400001ULL) << 13);
    acc = (acc + a1 + 0xf900001fULL) ^ 0x0c75e0ULL;
    acc ^= (acc >> 17) * 0x0014ULL;
    return acc;
}

// FDE #1269 | PC: 0x08cc00 | FDE: 0x0c7660 | Size: 216 bytes
// Hàm FDE #1269 | Địa chỉ PC: 0x08cc00 | Địa chỉ FDE: 0x0c7660 | Kích thước: 216 bytes
//   0x08cc00: D10143FF  sub      sp, sp, #0x50
//   0x08cc04: F9000BF7  str      x23, [sp, #0x10]
//   0x08cc08: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x08cc0c: A9034FF4  stp      x20, x19, [sp, #0x30]
static inline uint64_t fde_func_1269_0x08cc00(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x08cc00ULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xf9000bf7ULL) ^ 0x0c7660ULL;
    acc ^= (acc >> 17) * 0x00d8ULL;
    return acc;
}

// FDE #1270 | PC: 0x08ccd8 | FDE: 0x0c7690 | Size: 204 bytes
// Hàm FDE #1270 | Địa chỉ PC: 0x08ccd8 | Địa chỉ FDE: 0x0c7690 | Kích thước: 204 bytes
//   0x08ccd8: D10183FF  sub      sp, sp, #0x60
//   0x08ccdc: A90357F6  stp      x22, x21, [sp, #0x30]
//   0x08cce0: A9044FF4  stp      x20, x19, [sp, #0x40]
//   0x08cce4: A9057BFD  stp      x29, x30, [sp, #0x50]
static inline uint64_t fde_func_1270_0x08ccd8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x08ccd8ULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xa90357f6ULL) ^ 0x0c7690ULL;
    acc ^= (acc >> 17) * 0x00ccULL;
    return acc;
}

// FDE #1271 | PC: 0x08cda4 | FDE: 0x0c76e8 | Size: 212 bytes
// Hàm FDE #1271 | Địa chỉ PC: 0x08cda4 | Địa chỉ FDE: 0x0c76e8 | Kích thước: 212 bytes
//   0x08cda4: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x08cda8: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x08cdac: 910043FD  add      x29, sp, #0x10
//   0x08cdb0: 52800300  mov      w0, #0x18
static inline uint64_t fde_func_1271_0x08cda4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x08cda4ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x0c76e8ULL;
    acc ^= (acc >> 17) * 0x00d4ULL;
    return acc;
}

// FDE #1272 | PC: 0x08ce78 | FDE: 0x0c7618 | Size: 72 bytes
// Hàm FDE #1272 | Địa chỉ PC: 0x08ce78 | Địa chỉ FDE: 0x0c7618 | Kích thước: 72 bytes
//   0x08ce78: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x08ce7c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x08ce80: 910043FD  add      x29, sp, #0x10
//   0x08ce84: F9400013  ldr      x19, [x0]
static inline uint64_t fde_func_1272_0x08ce78(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x08ce78ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x0c7618ULL;
    acc ^= (acc >> 17) * 0x0048ULL;
    return acc;
}

// FDE #1273 | PC: 0x08cec0 | FDE: 0x0c7790 | Size: 232 bytes
// Hàm FDE #1273 | Địa chỉ PC: 0x08cec0 | Địa chỉ FDE: 0x0c7790 | Kích thước: 232 bytes
//   0x08cec0: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x08cec4: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x08cec8: 910043FD  add      x29, sp, #0x10
//   0x08cecc: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_1273_0x08cec0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x08cec0ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x0c7790ULL;
    acc ^= (acc >> 17) * 0x00e8ULL;
    return acc;
}

// FDE #1274 | PC: 0x08cfa8 | FDE: 0x0c7710 | Size: 20 bytes
// Hàm FDE #1274 | Địa chỉ PC: 0x08cfa8 | Địa chỉ FDE: 0x0c7710 | Kích thước: 20 bytes
//   0x08cfa8: F9400001  ldr      x1, [x0]
//   0x08cfac: F900001F  str      xzr, [x0]
//   0x08cfb0: B4000041  cbz      x1, #0x8cfb8
//   0x08cfb4: 140054AF  b        #0xa2270
static inline uint64_t fde_func_1274_0x08cfa8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x08cfa8ULL ^ (static_cast<uint64_t>(0xf9400001ULL) << 13);
    acc = (acc + a1 + 0xf900001fULL) ^ 0x0c7710ULL;
    acc ^= (acc >> 17) * 0x0014ULL;
    return acc;
}

// FDE #1275 | PC: 0x08cfbc | FDE: 0x0c77b8 | Size: 256 bytes
// Hàm FDE #1275 | Địa chỉ PC: 0x08cfbc | Địa chỉ FDE: 0x0c77b8 | Kích thước: 256 bytes
//   0x08cfbc: D10243FF  sub      sp, sp, #0x90
//   0x08cfc0: F9001BFB  str      x27, [sp, #0x30]
//   0x08cfc4: A90467FA  stp      x26, x25, [sp, #0x40]
//   0x08cfc8: A9055FF8  stp      x24, x23, [sp, #0x50]
static inline uint64_t fde_func_1275_0x08cfbc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x08cfbcULL ^ (static_cast<uint64_t>(0xd10243ffULL) << 13);
    acc = (acc + a1 + 0xf9001bfbULL) ^ 0x0c77b8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1276 | PC: 0x08d1e0 | FDE: 0x0c77f0 | Size: 256 bytes
// Hàm FDE #1276 | Địa chỉ PC: 0x08d1e0 | Địa chỉ FDE: 0x0c77f0 | Kích thước: 256 bytes
//   0x08d1e0: D10443FF  sub      sp, sp, #0x110
//   0x08d1e4: A90B6FFC  stp      x28, x27, [sp, #0xb0]
//   0x08d1e8: A90C67FA  stp      x26, x25, [sp, #0xc0]
//   0x08d1ec: A90D5FF8  stp      x24, x23, [sp, #0xd0]
static inline uint64_t fde_func_1276_0x08d1e0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x08d1e0ULL ^ (static_cast<uint64_t>(0xd10443ffULL) << 13);
    acc = (acc + a1 + 0xa90b6ffcULL) ^ 0x0c77f0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1277 | PC: 0x08d660 | FDE: 0x0c7850 | Size: 112 bytes
// Hàm FDE #1277 | Địa chỉ PC: 0x08d660 | Địa chỉ FDE: 0x0c7850 | Kích thước: 112 bytes
//   0x08d660: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x08d664: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x08d668: 910043FD  add      x29, sp, #0x10
//   0x08d66c: 52800600  mov      w0, #0x30
static inline uint64_t fde_func_1277_0x08d660(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x08d660ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x0c7850ULL;
    acc ^= (acc >> 17) * 0x0070ULL;
    return acc;
}

// FDE #1278 | PC: 0x08d6d0 | FDE: 0x0c7748 | Size: 72 bytes
// Hàm FDE #1278 | Địa chỉ PC: 0x08d6d0 | Địa chỉ FDE: 0x0c7748 | Kích thước: 72 bytes
//   0x08d6d0: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x08d6d4: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x08d6d8: 910043FD  add      x29, sp, #0x10
//   0x08d6dc: F9400013  ldr      x19, [x0]
static inline uint64_t fde_func_1278_0x08d6d0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x08d6d0ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x0c7748ULL;
    acc ^= (acc >> 17) * 0x0048ULL;
    return acc;
}

// FDE #1279 | PC: 0x08d718 | FDE: 0x0c7878 | Size: 256 bytes
// Hàm FDE #1279 | Địa chỉ PC: 0x08d718 | Địa chỉ FDE: 0x0c7878 | Kích thước: 256 bytes
//   0x08d718: D10143FF  sub      sp, sp, #0x50
//   0x08d71c: A9015FF8  stp      x24, x23, [sp, #0x10]
//   0x08d720: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x08d724: A9034FF4  stp      x20, x19, [sp, #0x30]
static inline uint64_t fde_func_1279_0x08d718(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x08d718ULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xa9015ff8ULL) ^ 0x0c7878ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1280 | PC: 0x08d84c | FDE: 0x0c78a8 | Size: 256 bytes
// Hàm FDE #1280 | Địa chỉ PC: 0x08d84c | Địa chỉ FDE: 0x0c78a8 | Kích thước: 256 bytes
//   0x08d84c: D10143FF  sub      sp, sp, #0x50
//   0x08d850: A9015FF8  stp      x24, x23, [sp, #0x10]
//   0x08d854: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x08d858: A9034FF4  stp      x20, x19, [sp, #0x30]
static inline uint64_t fde_func_1280_0x08d84c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x08d84cULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xa9015ff8ULL) ^ 0x0c78a8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1281 | PC: 0x08d980 | FDE: 0x0c78d8 | Size: 256 bytes
// Hàm FDE #1281 | Địa chỉ PC: 0x08d980 | Địa chỉ FDE: 0x0c78d8 | Kích thước: 256 bytes
//   0x08d980: D10203FF  sub      sp, sp, #0x80
//   0x08d984: F9001BF9  str      x25, [sp, #0x30]
//   0x08d988: A9045FF8  stp      x24, x23, [sp, #0x40]
//   0x08d98c: A90557F6  stp      x22, x21, [sp, #0x50]
static inline uint64_t fde_func_1281_0x08d980(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x08d980ULL ^ (static_cast<uint64_t>(0xd10203ffULL) << 13);
    acc = (acc + a1 + 0xf9001bf9ULL) ^ 0x0c78d8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1282 | PC: 0x08db68 | FDE: 0x0c7908 | Size: 256 bytes
// Hàm FDE #1282 | Địa chỉ PC: 0x08db68 | Địa chỉ FDE: 0x0c7908 | Kích thước: 256 bytes
//   0x08db68: D103C3FF  sub      sp, sp, #0xf0
//   0x08db6c: A9096FFC  stp      x28, x27, [sp, #0x90]
//   0x08db70: A90A67FA  stp      x26, x25, [sp, #0xa0]
//   0x08db74: A90B5FF8  stp      x24, x23, [sp, #0xb0]
static inline uint64_t fde_func_1282_0x08db68(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x08db68ULL ^ (static_cast<uint64_t>(0xd103c3ffULL) << 13);
    acc = (acc + a1 + 0xa9096ffcULL) ^ 0x0c7908ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1283 | PC: 0x08de40 | FDE: 0x0c7768 | Size: 256 bytes
// Hàm FDE #1283 | Địa chỉ PC: 0x08de40 | Địa chỉ FDE: 0x0c7768 | Kích thước: 256 bytes
//   0x08de40: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x08de44: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x08de48: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x08de4c: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1283_0x08de40(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x08de40ULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x0c7768ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1284 | PC: 0x08e0b4 | FDE: 0x0c7940 | Size: 12 bytes
// Hàm FDE #1284 | Địa chỉ PC: 0x08e0b4 | Địa chỉ FDE: 0x0c7940 | Kích thước: 12 bytes
//   0x08e0b4: F0000121  adrp     x1, #0xb5000
//   0x08e0b8: 913AE421  add      x1, x1, #0xeb9
//   0x08e0bc: 14005DE1  b        #0xa5840
static inline uint64_t fde_func_1284_0x08e0b4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x08e0b4ULL ^ (static_cast<uint64_t>(0xf0000121ULL) << 13);
    acc = (acc + a1 + 0x913ae421ULL) ^ 0x0c7940ULL;
    acc ^= (acc >> 17) * 0x000cULL;
    return acc;
}

// FDE #1285 | PC: 0x08e0c0 | FDE: 0x0c7958 | Size: 4 bytes
// Hàm FDE #1285 | Địa chỉ PC: 0x08e0c0 | Địa chỉ FDE: 0x0c7958 | Kích thước: 4 bytes
//   0x08e0c0: 14005E22  b        #0xa5948
static inline uint64_t fde_func_1285_0x08e0c0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x08e0c0ULL ^ (static_cast<uint64_t>(0x14005e22ULL) << 13);
    acc = (acc + a1 + 0xb4000162ULL) ^ 0x0c7958ULL;
    acc ^= (acc >> 17) * 0x0004ULL;
    return acc;
}

// FDE #1286 | PC: 0x08e0c4 | FDE: 0x0c7970 | Size: 48 bytes [Java_com_lemon_nuro_Conversation_00024CppProxy_nativeDestroy]
// Hàm FDE #1286 | Địa chỉ PC: 0x08e0c4 | Địa chỉ FDE: 0x0c7970 | Kích thước: 48 bytes
//   0x08e0c4: B4000162  cbz      x2, #0x8e0f0
//   0x08e0c8: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x08e0cc: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x08e0d0: 910043FD  add      x29, sp, #0x10
static inline uint64_t fde_func_1286_0x08e0c4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x08e0c4ULL ^ (static_cast<uint64_t>(0xb4000162ULL) << 13);
    acc = (acc + a1 + 0xf81e0ff3ULL) ^ 0x0c7970ULL;
    acc ^= (acc >> 17) * 0x0030ULL;
    return acc;
}

// FDE #1287 | PC: 0x08e0f4 | FDE: 0x0c7cc0 | Size: 252 bytes
// Hàm FDE #1287 | Địa chỉ PC: 0x08e0f4 | Địa chỉ FDE: 0x0c7cc0 | Kích thước: 252 bytes
//   0x08e0f4: D10103FF  sub      sp, sp, #0x40
//   0x08e0f8: F9000BF5  str      x21, [sp, #0x10]
//   0x08e0fc: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x08e100: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_1287_0x08e0f4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x08e0f4ULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xf9000bf5ULL) ^ 0x0c7cc0ULL;
    acc ^= (acc >> 17) * 0x00fcULL;
    return acc;
}

// FDE #1288 | PC: 0x08e1f0 | FDE: 0x0c7ce8 | Size: 256 bytes [Java_com_lemon_nuro_Conversation_00024CppProxy_native_1listen]
// Hàm FDE #1288 | Địa chỉ PC: 0x08e1f0 | Địa chỉ FDE: 0x0c7ce8 | Kích thước: 256 bytes
//   0x08e1f0: D10183FF  sub      sp, sp, #0x60
//   0x08e1f4: F90013F7  str      x23, [sp, #0x20]
//   0x08e1f8: A90357F6  stp      x22, x21, [sp, #0x30]
//   0x08e1fc: A9044FF4  stp      x20, x19, [sp, #0x40]
static inline uint64_t fde_func_1288_0x08e1f0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x08e1f0ULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xf90013f7ULL) ^ 0x0c7ce8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1289 | PC: 0x08e328 | FDE: 0x0c7d18 | Size: 256 bytes [Java_com_lemon_nuro_Conversation_00024CppProxy_native_1connect]
// Hàm FDE #1289 | Địa chỉ PC: 0x08e328 | Địa chỉ FDE: 0x0c7d18 | Kích thước: 256 bytes
//   0x08e328: D101C3FF  sub      sp, sp, #0x70
//   0x08e32c: F9001BF7  str      x23, [sp, #0x30]
//   0x08e330: A90457F6  stp      x22, x21, [sp, #0x40]
//   0x08e334: A9054FF4  stp      x20, x19, [sp, #0x50]
static inline uint64_t fde_func_1289_0x08e328(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x08e328ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xf9001bf7ULL) ^ 0x0c7d18ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1290 | PC: 0x08e4e4 | FDE: 0x0c7990 | Size: 88 bytes
// Hàm FDE #1290 | Địa chỉ PC: 0x08e4e4 | Địa chỉ FDE: 0x0c7990 | Kích thước: 88 bytes
//   0x08e4e4: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x08e4e8: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x08e4ec: 910043FD  add      x29, sp, #0x10
//   0x08e4f0: F9400413  ldr      x19, [x0, #8]
static inline uint64_t fde_func_1290_0x08e4e4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x08e4e4ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x0c7990ULL;
    acc ^= (acc >> 17) * 0x0058ULL;
    return acc;
}

// FDE #1291 | PC: 0x08e53c | FDE: 0x0c7d48 | Size: 212 bytes [Java_com_lemon_nuro_Conversation_00024CppProxy_native_1send]
// Hàm FDE #1291 | Địa chỉ PC: 0x08e53c | Địa chỉ FDE: 0x0c7d48 | Kích thước: 212 bytes
//   0x08e53c: D10683FF  sub      sp, sp, #0x1a0
//   0x08e540: F900B3FC  str      x28, [sp, #0x160]
//   0x08e544: A91757F6  stp      x22, x21, [sp, #0x170]
//   0x08e548: A9184FF4  stp      x20, x19, [sp, #0x180]
static inline uint64_t fde_func_1291_0x08e53c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x08e53cULL ^ (static_cast<uint64_t>(0xd10683ffULL) << 13);
    acc = (acc + a1 + 0xf900b3fcULL) ^ 0x0c7d48ULL;
    acc ^= (acc >> 17) * 0x00d4ULL;
    return acc;
}

// FDE #1292 | PC: 0x08e610 | FDE: 0x0c79b0 | Size: 256 bytes [_ZN4nuro12InputMessageD2Ev]
// Hàm FDE #1292 | Địa chỉ PC: 0x08e610 | Địa chỉ FDE: 0x0c79b0 | Kích thước: 256 bytes
//   0x08e610: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x08e614: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x08e618: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x08e61c: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1292_0x08e610(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x08e610ULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x0c79b0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1293 | PC: 0x08e720 | FDE: 0x0c7d78 | Size: 212 bytes [Java_com_lemon_nuro_Conversation_00024CppProxy_native_1reply]
// Hàm FDE #1293 | Địa chỉ PC: 0x08e720 | Địa chỉ FDE: 0x0c7d78 | Kích thước: 212 bytes
//   0x08e720: D10683FF  sub      sp, sp, #0x1a0
//   0x08e724: F900B3FC  str      x28, [sp, #0x160]
//   0x08e728: A91757F6  stp      x22, x21, [sp, #0x170]
//   0x08e72c: A9184FF4  stp      x20, x19, [sp, #0x180]
static inline uint64_t fde_func_1293_0x08e720(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x08e720ULL ^ (static_cast<uint64_t>(0xd10683ffULL) << 13);
    acc = (acc + a1 + 0xf900b3fcULL) ^ 0x0c7d78ULL;
    acc ^= (acc >> 17) * 0x00d4ULL;
    return acc;
}

// FDE #1294 | PC: 0x08e7f4 | FDE: 0x0c7da8 | Size: 212 bytes [Java_com_lemon_nuro_Conversation_00024CppProxy_native_1retry]
// Hàm FDE #1294 | Địa chỉ PC: 0x08e7f4 | Địa chỉ FDE: 0x0c7da8 | Kích thước: 212 bytes
//   0x08e7f4: D10683FF  sub      sp, sp, #0x1a0
//   0x08e7f8: F900B3FC  str      x28, [sp, #0x160]
//   0x08e7fc: A91757F6  stp      x22, x21, [sp, #0x170]
//   0x08e800: A9184FF4  stp      x20, x19, [sp, #0x180]
static inline uint64_t fde_func_1294_0x08e7f4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x08e7f4ULL ^ (static_cast<uint64_t>(0xd10683ffULL) << 13);
    acc = (acc + a1 + 0xf900b3fcULL) ^ 0x0c7da8ULL;
    acc ^= (acc >> 17) * 0x00d4ULL;
    return acc;
}

// FDE #1295 | PC: 0x08e8c8 | FDE: 0x0c7dd8 | Size: 212 bytes [Java_com_lemon_nuro_Conversation_00024CppProxy_native_1cancel]
// Hàm FDE #1295 | Địa chỉ PC: 0x08e8c8 | Địa chỉ FDE: 0x0c7dd8 | Kích thước: 212 bytes
//   0x08e8c8: D10683FF  sub      sp, sp, #0x1a0
//   0x08e8cc: F900B3FC  str      x28, [sp, #0x160]
//   0x08e8d0: A91757F6  stp      x22, x21, [sp, #0x170]
//   0x08e8d4: A9184FF4  stp      x20, x19, [sp, #0x180]
static inline uint64_t fde_func_1295_0x08e8c8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x08e8c8ULL ^ (static_cast<uint64_t>(0xd10683ffULL) << 13);
    acc = (acc + a1 + 0xf900b3fcULL) ^ 0x0c7dd8ULL;
    acc ^= (acc >> 17) * 0x00d4ULL;
    return acc;
}

// FDE #1296 | PC: 0x08e99c | FDE: 0x0c7e08 | Size: 256 bytes [Java_com_lemon_nuro_Conversation_00024CppProxy_native_1popupHistoryMessages]
// Hàm FDE #1296 | Địa chỉ PC: 0x08e99c | Địa chỉ FDE: 0x0c7e08 | Kích thước: 256 bytes
//   0x08e99c: A9BB67FA  stp      x26, x25, [sp, #-0x50]!
//   0x08e9a0: A9015FF8  stp      x24, x23, [sp, #0x10]
//   0x08e9a4: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x08e9a8: A9034FF4  stp      x20, x19, [sp, #0x30]
static inline uint64_t fde_func_1296_0x08e99c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x08e99cULL ^ (static_cast<uint64_t>(0xa9bb67faULL) << 13);
    acc = (acc + a1 + 0xa9015ff8ULL) ^ 0x0c7e08ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1297 | PC: 0x08eac4 | FDE: 0x0c7e40 | Size: 120 bytes [Java_com_lemon_nuro_Conversation_00024CppProxy_native_1setRunMode]
// Hàm FDE #1297 | Địa chỉ PC: 0x08eac4 | Địa chỉ FDE: 0x0c7e40 | Kích thước: 120 bytes
//   0x08eac4: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x08eac8: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x08eacc: 910043FD  add      x29, sp, #0x10
//   0x08ead0: F9400854  ldr      x20, [x2, #0x10]
static inline uint64_t fde_func_1297_0x08eac4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x08eac4ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x0c7e40ULL;
    acc ^= (acc >> 17) * 0x0078ULL;
    return acc;
}

// FDE #1298 | PC: 0x08eb3c | FDE: 0x0c7e68 | Size: 208 bytes [Java_com_lemon_nuro_Conversation_00024CppProxy_native_1setBabiParams]
// Hàm FDE #1298 | Địa chỉ PC: 0x08eb3c | Địa chỉ FDE: 0x0c7e68 | Kích thước: 208 bytes
//   0x08eb3c: D10143FF  sub      sp, sp, #0x50
//   0x08eb40: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x08eb44: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x08eb48: A9047BFD  stp      x29, x30, [sp, #0x40]
static inline uint64_t fde_func_1298_0x08eb3c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x08eb3cULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xa90257f6ULL) ^ 0x0c7e68ULL;
    acc ^= (acc >> 17) * 0x00d0ULL;
    return acc;
}

// FDE #1299 | PC: 0x08ec0c | FDE: 0x0c7e98 | Size: 96 bytes [Java_com_lemon_nuro_Conversation_00024CppProxy_native_1recoverRemoteSection]
// Hàm FDE #1299 | Địa chỉ PC: 0x08ec0c | Địa chỉ FDE: 0x0c7e98 | Kích thước: 96 bytes
//   0x08ec0c: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x08ec10: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x08ec14: 910043FD  add      x29, sp, #0x10
//   0x08ec18: F9400848  ldr      x8, [x2, #0x10]
static inline uint64_t fde_func_1299_0x08ec0c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x08ec0cULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x0c7e98ULL;
    acc ^= (acc >> 17) * 0x0060ULL;
    return acc;
}

// FDE #1300 | PC: 0x08ec6c | FDE: 0x0c7ec0 | Size: 92 bytes [Java_com_lemon_nuro_Conversation_00024CppProxy_native_1cancelRecoverRemoteSection]
// Hàm FDE #1300 | Địa chỉ PC: 0x08ec6c | Địa chỉ FDE: 0x0c7ec0 | Kích thước: 92 bytes
//   0x08ec6c: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x08ec70: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x08ec74: 910043FD  add      x29, sp, #0x10
//   0x08ec78: F9400848  ldr      x8, [x2, #0x10]
static inline uint64_t fde_func_1300_0x08ec6c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x08ec6cULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x0c7ec0ULL;
    acc ^= (acc >> 17) * 0x005cULL;
    return acc;
}

// FDE #1301 | PC: 0x08ecc8 | FDE: 0x0c7ee8 | Size: 228 bytes [Java_com_lemon_nuro_Conversation_00024CppProxy_native_1recoverRemoteSections]
// Hàm FDE #1301 | Địa chỉ PC: 0x08ecc8 | Địa chỉ FDE: 0x0c7ee8 | Kích thước: 228 bytes
//   0x08ecc8: D10143FF  sub      sp, sp, #0x50
//   0x08eccc: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x08ecd0: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x08ecd4: A9047BFD  stp      x29, x30, [sp, #0x40]
static inline uint64_t fde_func_1301_0x08ecc8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x08ecc8ULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xa90257f6ULL) ^ 0x0c7ee8ULL;
    acc ^= (acc >> 17) * 0x00e4ULL;
    return acc;
}

// FDE #1302 | PC: 0x08edac | FDE: 0x0c7f18 | Size: 92 bytes [Java_com_lemon_nuro_Conversation_00024CppProxy_native_1cancelRecoverRemoteSections]
// Hàm FDE #1302 | Địa chỉ PC: 0x08edac | Địa chỉ FDE: 0x0c7f18 | Kích thước: 92 bytes
//   0x08edac: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x08edb0: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x08edb4: 910043FD  add      x29, sp, #0x10
//   0x08edb8: F9400848  ldr      x8, [x2, #0x10]
static inline uint64_t fde_func_1302_0x08edac(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x08edacULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x0c7f18ULL;
    acc ^= (acc >> 17) * 0x005cULL;
    return acc;
}

// FDE #1303 | PC: 0x08ee08 | FDE: 0x0c7f40 | Size: 256 bytes [Java_com_lemon_nuro_Conversation_00024CppProxy_native_1takeXray]
// Hàm FDE #1303 | Địa chỉ PC: 0x08ee08 | Địa chỉ FDE: 0x0c7f40 | Kích thước: 256 bytes
//   0x08ee08: D10283FF  sub      sp, sp, #0xa0
//   0x08ee0c: A90757F6  stp      x22, x21, [sp, #0x70]
//   0x08ee10: A9084FF4  stp      x20, x19, [sp, #0x80]
//   0x08ee14: A9097BFD  stp      x29, x30, [sp, #0x90]
static inline uint64_t fde_func_1303_0x08ee08(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x08ee08ULL ^ (static_cast<uint64_t>(0xd10283ffULL) << 13);
    acc = (acc + a1 + 0xa90757f6ULL) ^ 0x0c7f40ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1304 | PC: 0x08ef80 | FDE: 0x0c7f98 | Size: 108 bytes
// Hàm FDE #1304 | Địa chỉ PC: 0x08ef80 | Địa chỉ FDE: 0x0c7f98 | Kích thước: 108 bytes
//   0x08ef80: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x08ef84: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x08ef88: 910043FD  add      x29, sp, #0x10
//   0x08ef8c: 52800300  mov      w0, #0x18
static inline uint64_t fde_func_1304_0x08ef80(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x08ef80ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x0c7f98ULL;
    acc ^= (acc >> 17) * 0x006cULL;
    return acc;
}

// FDE #1305 | PC: 0x08efec | FDE: 0x0c79f0 | Size: 60 bytes
// Hàm FDE #1305 | Địa chỉ PC: 0x08efec | Địa chỉ FDE: 0x0c79f0 | Kích thước: 60 bytes
//   0x08efec: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x08eff0: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x08eff4: 910043FD  add      x29, sp, #0x10
//   0x08eff8: F9400013  ldr      x19, [x0]
static inline uint64_t fde_func_1305_0x08efec(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x08efecULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x0c79f0ULL;
    acc ^= (acc >> 17) * 0x003cULL;
    return acc;
}

// FDE #1306 | PC: 0x08f028 | FDE: 0x0c7fe8 | Size: 100 bytes
// Hàm FDE #1306 | Địa chỉ PC: 0x08f028 | Địa chỉ FDE: 0x0c7fe8 | Kích thước: 100 bytes
//   0x08f028: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x08f02c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x08f030: 910043FD  add      x29, sp, #0x10
//   0x08f034: 52800B00  mov      w0, #0x58
static inline uint64_t fde_func_1306_0x08f028(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x08f028ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x0c7fe8ULL;
    acc ^= (acc >> 17) * 0x0064ULL;
    return acc;
}

// FDE #1307 | PC: 0x08f08c | FDE: 0x0c7a30 | Size: 60 bytes
// Hàm FDE #1307 | Địa chỉ PC: 0x08f08c | Địa chỉ FDE: 0x0c7a30 | Kích thước: 60 bytes
//   0x08f08c: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x08f090: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x08f094: 910043FD  add      x29, sp, #0x10
//   0x08f098: F9400013  ldr      x19, [x0]
static inline uint64_t fde_func_1307_0x08f08c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x08f08cULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x0c7a30ULL;
    acc ^= (acc >> 17) * 0x003cULL;
    return acc;
}

// FDE #1308 | PC: 0x08f0c8 | FDE: 0x0c8038 | Size: 100 bytes
// Hàm FDE #1308 | Địa chỉ PC: 0x08f0c8 | Địa chỉ FDE: 0x0c8038 | Kích thước: 100 bytes
//   0x08f0c8: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x08f0cc: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x08f0d0: 910043FD  add      x29, sp, #0x10
//   0x08f0d4: 52800300  mov      w0, #0x18
static inline uint64_t fde_func_1308_0x08f0c8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x08f0c8ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x0c8038ULL;
    acc ^= (acc >> 17) * 0x0064ULL;
    return acc;
}

// FDE #1309 | PC: 0x08f12c | FDE: 0x0c7a70 | Size: 60 bytes
// Hàm FDE #1309 | Địa chỉ PC: 0x08f12c | Địa chỉ FDE: 0x0c7a70 | Kích thước: 60 bytes
//   0x08f12c: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x08f130: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x08f134: 910043FD  add      x29, sp, #0x10
//   0x08f138: F9400013  ldr      x19, [x0]
static inline uint64_t fde_func_1309_0x08f12c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x08f12cULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x0c7a70ULL;
    acc ^= (acc >> 17) * 0x003cULL;
    return acc;
}

// FDE #1310 | PC: 0x08f168 | FDE: 0x0c8088 | Size: 100 bytes
// Hàm FDE #1310 | Địa chỉ PC: 0x08f168 | Địa chỉ FDE: 0x0c8088 | Kích thước: 100 bytes
//   0x08f168: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x08f16c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x08f170: 910043FD  add      x29, sp, #0x10
//   0x08f174: 52800600  mov      w0, #0x30
static inline uint64_t fde_func_1310_0x08f168(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x08f168ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x0c8088ULL;
    acc ^= (acc >> 17) * 0x0064ULL;
    return acc;
}

// FDE #1311 | PC: 0x08f1cc | FDE: 0x0c7ab0 | Size: 60 bytes
// Hàm FDE #1311 | Địa chỉ PC: 0x08f1cc | Địa chỉ FDE: 0x0c7ab0 | Kích thước: 60 bytes
//   0x08f1cc: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x08f1d0: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x08f1d4: 910043FD  add      x29, sp, #0x10
//   0x08f1d8: F9400013  ldr      x19, [x0]
static inline uint64_t fde_func_1311_0x08f1cc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x08f1ccULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x0c7ab0ULL;
    acc ^= (acc >> 17) * 0x003cULL;
    return acc;
}

// FDE #1312 | PC: 0x08f208 | FDE: 0x0c80d8 | Size: 216 bytes
// Hàm FDE #1312 | Địa chỉ PC: 0x08f208 | Địa chỉ FDE: 0x0c80d8 | Kích thước: 216 bytes
//   0x08f208: D10143FF  sub      sp, sp, #0x50
//   0x08f20c: F90013F5  str      x21, [sp, #0x20]
//   0x08f210: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x08f214: A9047BFD  stp      x29, x30, [sp, #0x40]
static inline uint64_t fde_func_1312_0x08f208(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x08f208ULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xf90013f5ULL) ^ 0x0c80d8ULL;
    acc ^= (acc >> 17) * 0x00d8ULL;
    return acc;
}

// FDE #1313 | PC: 0x08f2e0 | FDE: 0x0c7af0 | Size: 72 bytes
// Hàm FDE #1313 | Địa chỉ PC: 0x08f2e0 | Địa chỉ FDE: 0x0c7af0 | Kích thước: 72 bytes
//   0x08f2e0: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x08f2e4: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x08f2e8: 910043FD  add      x29, sp, #0x10
//   0x08f2ec: F9400013  ldr      x19, [x0]
static inline uint64_t fde_func_1313_0x08f2e0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x08f2e0ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x0c7af0ULL;
    acc ^= (acc >> 17) * 0x0048ULL;
    return acc;
}

// FDE #1314 | PC: 0x08f328 | FDE: 0x0c8128 | Size: 212 bytes
// Hàm FDE #1314 | Địa chỉ PC: 0x08f328 | Địa chỉ FDE: 0x0c8128 | Kích thước: 212 bytes
//   0x08f328: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x08f32c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x08f330: 910043FD  add      x29, sp, #0x10
//   0x08f334: 52800300  mov      w0, #0x18
static inline uint64_t fde_func_1314_0x08f328(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x08f328ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x0c8128ULL;
    acc ^= (acc >> 17) * 0x00d4ULL;
    return acc;
}

// FDE #1315 | PC: 0x08f3fc | FDE: 0x0c7b30 | Size: 72 bytes
// Hàm FDE #1315 | Địa chỉ PC: 0x08f3fc | Địa chỉ FDE: 0x0c7b30 | Kích thước: 72 bytes
//   0x08f3fc: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x08f400: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x08f404: 910043FD  add      x29, sp, #0x10
//   0x08f408: F9400013  ldr      x19, [x0]
static inline uint64_t fde_func_1315_0x08f3fc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x08f3fcULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x0c7b30ULL;
    acc ^= (acc >> 17) * 0x0048ULL;
    return acc;
}

// FDE #1316 | PC: 0x08f444 | FDE: 0x0c7b50 | Size: 256 bytes
// Hàm FDE #1316 | Địa chỉ PC: 0x08f444 | Địa chỉ FDE: 0x0c7b50 | Kích thước: 256 bytes
//   0x08f444: D101C3FF  sub      sp, sp, #0x70
//   0x08f448: F9001BF7  str      x23, [sp, #0x30]
//   0x08f44c: A90457F6  stp      x22, x21, [sp, #0x40]
//   0x08f450: A9054FF4  stp      x20, x19, [sp, #0x50]
static inline uint64_t fde_func_1316_0x08f444(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x08f444ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xf9001bf7ULL) ^ 0x0c7b50ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1317 | PC: 0x08f5c4 | FDE: 0x0c8150 | Size: 204 bytes
// Hàm FDE #1317 | Địa chỉ PC: 0x08f5c4 | Địa chỉ FDE: 0x0c8150 | Kích thước: 204 bytes
//   0x08f5c4: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x08f5c8: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x08f5cc: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x08f5d0: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1317_0x08f5c4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x08f5c4ULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x0c8150ULL;
    acc ^= (acc >> 17) * 0x00ccULL;
    return acc;
}

// FDE #1318 | PC: 0x08f690 | FDE: 0x0c7b78 | Size: 48 bytes
// Hàm FDE #1318 | Địa chỉ PC: 0x08f690 | Địa chỉ FDE: 0x0c7b78 | Kích thước: 48 bytes
//   0x08f690: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x08f694: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x08f698: 910043FD  add      x29, sp, #0x10
//   0x08f69c: 900002E8  adrp     x8, #0xeb000
static inline uint64_t fde_func_1318_0x08f690(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x08f690ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x0c7b78ULL;
    acc ^= (acc >> 17) * 0x0030ULL;
    return acc;
}

// FDE #1319 | PC: 0x08f6c0 | FDE: 0x0c7b98 | Size: 56 bytes
// Hàm FDE #1319 | Địa chỉ PC: 0x08f6c0 | Địa chỉ FDE: 0x0c7b98 | Kích thước: 56 bytes
//   0x08f6c0: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x08f6c4: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x08f6c8: 910043FD  add      x29, sp, #0x10
//   0x08f6cc: 900002E8  adrp     x8, #0xeb000
static inline uint64_t fde_func_1319_0x08f6c0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x08f6c0ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x0c7b98ULL;
    acc ^= (acc >> 17) * 0x0038ULL;
    return acc;
}

// FDE #1320 | PC: 0x08f6f8 | FDE: 0x0c7bb8 | Size: 8 bytes
// Hàm FDE #1320 | Địa chỉ PC: 0x08f6f8 | Địa chỉ FDE: 0x0c7bb8 | Kích thước: 8 bytes
//   0x08f6f8: 91006000  add      x0, x0, #0x18
//   0x08f6fc: 1400088F  b        #0x91938
static inline uint64_t fde_func_1320_0x08f6f8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x08f6f8ULL ^ (static_cast<uint64_t>(0x91006000ULL) << 13);
    acc = (acc + a1 + 0x1400088fULL) ^ 0x0c7bb8ULL;
    acc ^= (acc >> 17) * 0x0008ULL;
    return acc;
}

// FDE #1321 | PC: 0x08f700 | FDE: 0x0c7bd0 | Size: 4 bytes
// Hàm FDE #1321 | Địa chỉ PC: 0x08f700 | Địa chỉ FDE: 0x0c7bd0 | Kích thước: 4 bytes
//   0x08f700: 17FE0C40  b        #0x12800
static inline uint64_t fde_func_1321_0x08f700(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x08f700ULL ^ (static_cast<uint64_t>(0x17fe0c40ULL) << 13);
    acc = (acc + a1 + 0xd101c3ffULL) ^ 0x0c7bd0ULL;
    acc ^= (acc >> 17) * 0x0004ULL;
    return acc;
}

// FDE #1322 | PC: 0x08f704 | FDE: 0x0c7be8 | Size: 256 bytes
// Hàm FDE #1322 | Địa chỉ PC: 0x08f704 | Địa chỉ FDE: 0x0c7be8 | Kích thước: 256 bytes
//   0x08f704: D101C3FF  sub      sp, sp, #0x70
//   0x08f708: F9001BF7  str      x23, [sp, #0x30]
//   0x08f70c: A90457F6  stp      x22, x21, [sp, #0x40]
//   0x08f710: A9054FF4  stp      x20, x19, [sp, #0x50]
static inline uint64_t fde_func_1322_0x08f704(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x08f704ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xf9001bf7ULL) ^ 0x0c7be8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1323 | PC: 0x08f884 | FDE: 0x0c8180 | Size: 204 bytes
// Hàm FDE #1323 | Địa chỉ PC: 0x08f884 | Địa chỉ FDE: 0x0c8180 | Kích thước: 204 bytes
//   0x08f884: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x08f888: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x08f88c: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x08f890: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1323_0x08f884(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x08f884ULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x0c8180ULL;
    acc ^= (acc >> 17) * 0x00ccULL;
    return acc;
}

// FDE #1324 | PC: 0x08f950 | FDE: 0x0c7c10 | Size: 48 bytes
// Hàm FDE #1324 | Địa chỉ PC: 0x08f950 | Địa chỉ FDE: 0x0c7c10 | Kích thước: 48 bytes
//   0x08f950: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x08f954: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x08f958: 910043FD  add      x29, sp, #0x10
//   0x08f95c: 900002E8  adrp     x8, #0xeb000
static inline uint64_t fde_func_1324_0x08f950(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x08f950ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x0c7c10ULL;
    acc ^= (acc >> 17) * 0x0030ULL;
    return acc;
}

// FDE #1325 | PC: 0x08f980 | FDE: 0x0c7c30 | Size: 56 bytes
// Hàm FDE #1325 | Địa chỉ PC: 0x08f980 | Địa chỉ FDE: 0x0c7c30 | Kích thước: 56 bytes
//   0x08f980: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x08f984: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x08f988: 910043FD  add      x29, sp, #0x10
//   0x08f98c: 900002E8  adrp     x8, #0xeb000
static inline uint64_t fde_func_1325_0x08f980(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x08f980ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x0c7c30ULL;
    acc ^= (acc >> 17) * 0x0038ULL;
    return acc;
}

// FDE #1326 | PC: 0x08f9b8 | FDE: 0x0c7c50 | Size: 8 bytes
// Hàm FDE #1326 | Địa chỉ PC: 0x08f9b8 | Địa chỉ FDE: 0x0c7c50 | Kích thước: 8 bytes
//   0x08f9b8: 91006000  add      x0, x0, #0x18
//   0x08f9bc: 14001DB1  b        #0x97080
static inline uint64_t fde_func_1326_0x08f9b8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x08f9b8ULL ^ (static_cast<uint64_t>(0x91006000ULL) << 13);
    acc = (acc + a1 + 0x14001db1ULL) ^ 0x0c7c50ULL;
    acc ^= (acc >> 17) * 0x0008ULL;
    return acc;
}

// FDE #1327 | PC: 0x08f9c0 | FDE: 0x0c7c68 | Size: 4 bytes
// Hàm FDE #1327 | Địa chỉ PC: 0x08f9c0 | Địa chỉ FDE: 0x0c7c68 | Kích thước: 4 bytes
//   0x08f9c0: 17FE0B90  b        #0x12800
static inline uint64_t fde_func_1327_0x08f9c0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x08f9c0ULL ^ (static_cast<uint64_t>(0x17fe0b90ULL) << 13);
    acc = (acc + a1 + 0xd10143ffULL) ^ 0x0c7c68ULL;
    acc ^= (acc >> 17) * 0x0004ULL;
    return acc;
}

// FDE #1328 | PC: 0x08f9c4 | FDE: 0x0c81b0 | Size: 256 bytes
// Hàm FDE #1328 | Địa chỉ PC: 0x08f9c4 | Địa chỉ FDE: 0x0c81b0 | Kích thước: 256 bytes
//   0x08f9c4: D10143FF  sub      sp, sp, #0x50
//   0x08f9c8: F90013F5  str      x21, [sp, #0x20]
//   0x08f9cc: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x08f9d0: A9047BFD  stp      x29, x30, [sp, #0x40]
static inline uint64_t fde_func_1328_0x08f9c4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x08f9c4ULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xf90013f5ULL) ^ 0x0c81b0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1329 | PC: 0x08fae0 | FDE: 0x0c81d8 | Size: 256 bytes
// Hàm FDE #1329 | Địa chỉ PC: 0x08fae0 | Địa chỉ FDE: 0x0c81d8 | Kích thước: 256 bytes
//   0x08fae0: A9BC5FF8  stp      x24, x23, [sp, #-0x40]!
//   0x08fae4: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x08fae8: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x08faec: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_1329_0x08fae0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x08fae0ULL ^ (static_cast<uint64_t>(0xa9bc5ff8ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x0c81d8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1330 | PC: 0x08fbf0 | FDE: 0x0c8208 | Size: 252 bytes
// Hàm FDE #1330 | Địa chỉ PC: 0x08fbf0 | Địa chỉ FDE: 0x0c8208 | Kích thước: 252 bytes
//   0x08fbf0: D10103FF  sub      sp, sp, #0x40
//   0x08fbf4: F9000BF5  str      x21, [sp, #0x10]
//   0x08fbf8: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x08fbfc: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_1330_0x08fbf0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x08fbf0ULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xf9000bf5ULL) ^ 0x0c8208ULL;
    acc ^= (acc >> 17) * 0x00fcULL;
    return acc;
}

// FDE #1331 | PC: 0x08fcec | FDE: 0x0c7c80 | Size: 88 bytes
// Hàm FDE #1331 | Địa chỉ PC: 0x08fcec | Địa chỉ FDE: 0x0c7c80 | Kích thước: 88 bytes
//   0x08fcec: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x08fcf0: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x08fcf4: 910043FD  add      x29, sp, #0x10
//   0x08fcf8: F9400413  ldr      x19, [x0, #8]
static inline uint64_t fde_func_1331_0x08fcec(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x08fcecULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x0c7c80ULL;
    acc ^= (acc >> 17) * 0x0058ULL;
    return acc;
}

// FDE #1332 | PC: 0x08fd44 | FDE: 0x0c7ca0 | Size: 88 bytes
// Hàm FDE #1332 | Địa chỉ PC: 0x08fd44 | Địa chỉ FDE: 0x0c7ca0 | Kích thước: 88 bytes
//   0x08fd44: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x08fd48: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x08fd4c: 910043FD  add      x29, sp, #0x10
//   0x08fd50: F9400413  ldr      x19, [x0, #8]
static inline uint64_t fde_func_1332_0x08fd44(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x08fd44ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x0c7ca0ULL;
    acc ^= (acc >> 17) * 0x0058ULL;
    return acc;
}

// FDE #1333 | PC: 0x08fd9c | FDE: 0x0c8288 | Size: 232 bytes
// Hàm FDE #1333 | Địa chỉ PC: 0x08fd9c | Địa chỉ FDE: 0x0c8288 | Kích thước: 232 bytes
//   0x08fd9c: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x08fda0: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x08fda4: 910043FD  add      x29, sp, #0x10
//   0x08fda8: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_1333_0x08fd9c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x08fd9cULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x0c8288ULL;
    acc ^= (acc >> 17) * 0x00e8ULL;
    return acc;
}

// FDE #1334 | PC: 0x08fe84 | FDE: 0x0c8230 | Size: 20 bytes
// Hàm FDE #1334 | Địa chỉ PC: 0x08fe84 | Địa chỉ FDE: 0x0c8230 | Kích thước: 20 bytes
//   0x08fe84: F9400001  ldr      x1, [x0]
//   0x08fe88: F900001F  str      xzr, [x0]
//   0x08fe8c: B4000041  cbz      x1, #0x8fe94
//   0x08fe90: 140048F8  b        #0xa2270
static inline uint64_t fde_func_1334_0x08fe84(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x08fe84ULL ^ (static_cast<uint64_t>(0xf9400001ULL) << 13);
    acc = (acc + a1 + 0xf900001fULL) ^ 0x0c8230ULL;
    acc ^= (acc >> 17) * 0x0014ULL;
    return acc;
}

// FDE #1335 | PC: 0x08fe98 | FDE: 0x0c82b0 | Size: 256 bytes
// Hàm FDE #1335 | Địa chỉ PC: 0x08fe98 | Địa chỉ FDE: 0x0c82b0 | Kích thước: 256 bytes
//   0x08fe98: D10243FF  sub      sp, sp, #0x90
//   0x08fe9c: F9001BFB  str      x27, [sp, #0x30]
//   0x08fea0: A90467FA  stp      x26, x25, [sp, #0x40]
//   0x08fea4: A9055FF8  stp      x24, x23, [sp, #0x50]
static inline uint64_t fde_func_1335_0x08fe98(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x08fe98ULL ^ (static_cast<uint64_t>(0xd10243ffULL) << 13);
    acc = (acc + a1 + 0xf9001bfbULL) ^ 0x0c82b0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1336 | PC: 0x09005c | FDE: 0x0c82e8 | Size: 256 bytes
// Hàm FDE #1336 | Địa chỉ PC: 0x09005c | Địa chỉ FDE: 0x0c82e8 | Kích thước: 256 bytes
//   0x09005c: D10303FF  sub      sp, sp, #0xc0
//   0x090060: F90043F7  str      x23, [sp, #0x80]
//   0x090064: A90957F6  stp      x22, x21, [sp, #0x90]
//   0x090068: A90A4FF4  stp      x20, x19, [sp, #0xa0]
static inline uint64_t fde_func_1336_0x09005c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x09005cULL ^ (static_cast<uint64_t>(0xd10303ffULL) << 13);
    acc = (acc + a1 + 0xf90043f7ULL) ^ 0x0c82e8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1337 | PC: 0x090254 | FDE: 0x0c8340 | Size: 112 bytes
// Hàm FDE #1337 | Địa chỉ PC: 0x090254 | Địa chỉ FDE: 0x0c8340 | Kích thước: 112 bytes
//   0x090254: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x090258: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x09025c: 910043FD  add      x29, sp, #0x10
//   0x090260: 52800600  mov      w0, #0x30
static inline uint64_t fde_func_1337_0x090254(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x090254ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x0c8340ULL;
    acc ^= (acc >> 17) * 0x0070ULL;
    return acc;
}

// FDE #1338 | PC: 0x0902c4 | FDE: 0x0c8268 | Size: 72 bytes
// Hàm FDE #1338 | Địa chỉ PC: 0x0902c4 | Địa chỉ FDE: 0x0c8268 | Kích thước: 72 bytes
//   0x0902c4: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x0902c8: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0902cc: 910043FD  add      x29, sp, #0x10
//   0x0902d0: F9400013  ldr      x19, [x0]
static inline uint64_t fde_func_1338_0x0902c4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0902c4ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x0c8268ULL;
    acc ^= (acc >> 17) * 0x0048ULL;
    return acc;
}

// FDE #1339 | PC: 0x09030c | FDE: 0x0c8368 | Size: 12 bytes
// Hàm FDE #1339 | Địa chỉ PC: 0x09030c | Địa chỉ FDE: 0x0c8368 | Kích thước: 12 bytes
//   0x09030c: D0000121  adrp     x1, #0xb6000
//   0x090310: 91132421  add      x1, x1, #0x4c9
//   0x090314: 1400554B  b        #0xa5840
static inline uint64_t fde_func_1339_0x09030c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x09030cULL ^ (static_cast<uint64_t>(0xd0000121ULL) << 13);
    acc = (acc + a1 + 0x91132421ULL) ^ 0x0c8368ULL;
    acc ^= (acc >> 17) * 0x000cULL;
    return acc;
}

// FDE #1340 | PC: 0x090318 | FDE: 0x0c8380 | Size: 4 bytes
// Hàm FDE #1340 | Địa chỉ PC: 0x090318 | Địa chỉ FDE: 0x0c8380 | Kích thước: 4 bytes
//   0x090318: 1400558C  b        #0xa5948
static inline uint64_t fde_func_1340_0x090318(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x090318ULL ^ (static_cast<uint64_t>(0x1400558cULL) << 13);
    acc = (acc + a1 + 0xb4000162ULL) ^ 0x0c8380ULL;
    acc ^= (acc >> 17) * 0x0004ULL;
    return acc;
}

// FDE #1341 | PC: 0x09031c | FDE: 0x0c8398 | Size: 48 bytes [Java_com_lemon_nuro_ConversationHub_00024CppProxy_nativeDestroy]
// Hàm FDE #1341 | Địa chỉ PC: 0x09031c | Địa chỉ FDE: 0x0c8398 | Kích thước: 48 bytes
//   0x09031c: B4000162  cbz      x2, #0x90348
//   0x090320: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x090324: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x090328: 910043FD  add      x29, sp, #0x10
static inline uint64_t fde_func_1341_0x09031c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x09031cULL ^ (static_cast<uint64_t>(0xb4000162ULL) << 13);
    acc = (acc + a1 + 0xf81e0ff3ULL) ^ 0x0c8398ULL;
    acc ^= (acc >> 17) * 0x0030ULL;
    return acc;
}

// FDE #1342 | PC: 0x09034c | FDE: 0x0c8418 | Size: 252 bytes
// Hàm FDE #1342 | Địa chỉ PC: 0x09034c | Địa chỉ FDE: 0x0c8418 | Kích thước: 252 bytes
//   0x09034c: D10103FF  sub      sp, sp, #0x40
//   0x090350: F9000BF5  str      x21, [sp, #0x10]
//   0x090354: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x090358: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_1342_0x09034c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x09034cULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xf9000bf5ULL) ^ 0x0c8418ULL;
    acc ^= (acc >> 17) * 0x00fcULL;
    return acc;
}

// FDE #1343 | PC: 0x090448 | FDE: 0x0c8440 | Size: 256 bytes [Java_com_lemon_nuro_ConversationHub_00024CppProxy_instance]
// Hàm FDE #1343 | Địa chỉ PC: 0x090448 | Địa chỉ FDE: 0x0c8440 | Kích thước: 256 bytes
//   0x090448: D10183FF  sub      sp, sp, #0x60
//   0x09044c: F90013F7  str      x23, [sp, #0x20]
//   0x090450: A90357F6  stp      x22, x21, [sp, #0x30]
//   0x090454: A9044FF4  stp      x20, x19, [sp, #0x40]
static inline uint64_t fde_func_1343_0x090448(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x090448ULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xf90013f7ULL) ^ 0x0c8440ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1344 | PC: 0x090574 | FDE: 0x0c83b8 | Size: 88 bytes
// Hàm FDE #1344 | Địa chỉ PC: 0x090574 | Địa chỉ FDE: 0x0c83b8 | Kích thước: 88 bytes
//   0x090574: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x090578: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x09057c: 910043FD  add      x29, sp, #0x10
//   0x090580: F9400413  ldr      x19, [x0, #8]
static inline uint64_t fde_func_1344_0x090574(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x090574ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x0c83b8ULL;
    acc ^= (acc >> 17) * 0x0058ULL;
    return acc;
}

// FDE #1345 | PC: 0x0905cc | FDE: 0x0c8470 | Size: 208 bytes [Java_com_lemon_nuro_ConversationHub_00024CppProxy_native_1config]
// Hàm FDE #1345 | Địa chỉ PC: 0x0905cc | Địa chỉ FDE: 0x0c8470 | Kích thước: 208 bytes
//   0x0905cc: D10143FF  sub      sp, sp, #0x50
//   0x0905d0: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x0905d4: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x0905d8: A9047BFD  stp      x29, x30, [sp, #0x40]
static inline uint64_t fde_func_1345_0x0905cc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0905ccULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xa90257f6ULL) ^ 0x0c8470ULL;
    acc ^= (acc >> 17) * 0x00d0ULL;
    return acc;
}

// FDE #1346 | PC: 0x09069c | FDE: 0x0c84a0 | Size: 256 bytes [Java_com_lemon_nuro_ConversationHub_00024CppProxy_native_1open]
// Hàm FDE #1346 | Địa chỉ PC: 0x09069c | Địa chỉ FDE: 0x0c84a0 | Kích thước: 256 bytes
//   0x09069c: D10303FF  sub      sp, sp, #0xc0
//   0x0906a0: F90043F7  str      x23, [sp, #0x80]
//   0x0906a4: A90957F6  stp      x22, x21, [sp, #0x90]
//   0x0906a8: A90A4FF4  stp      x20, x19, [sp, #0xa0]
static inline uint64_t fde_func_1346_0x09069c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x09069cULL ^ (static_cast<uint64_t>(0xd10303ffULL) << 13);
    acc = (acc + a1 + 0xf90043f7ULL) ^ 0x0c84a0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1347 | PC: 0x090870 | FDE: 0x0c84d0 | Size: 208 bytes [Java_com_lemon_nuro_ConversationHub_00024CppProxy_native_1close]
// Hàm FDE #1347 | Địa chỉ PC: 0x090870 | Địa chỉ FDE: 0x0c84d0 | Kích thước: 208 bytes
//   0x090870: D10143FF  sub      sp, sp, #0x50
//   0x090874: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x090878: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x09087c: A9047BFD  stp      x29, x30, [sp, #0x40]
static inline uint64_t fde_func_1347_0x090870(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x090870ULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xa90257f6ULL) ^ 0x0c84d0ULL;
    acc ^= (acc >> 17) * 0x00d0ULL;
    return acc;
}

// FDE #1348 | PC: 0x090940 | FDE: 0x0c8500 | Size: 256 bytes [Java_com_lemon_nuro_ConversationHub_00024CppProxy_native_1list]
// Hàm FDE #1348 | Địa chỉ PC: 0x090940 | Địa chỉ FDE: 0x0c8500 | Kích thước: 256 bytes
//   0x090940: D10203FF  sub      sp, sp, #0x80
//   0x090944: F9001BF9  str      x25, [sp, #0x30]
//   0x090948: A9045FF8  stp      x24, x23, [sp, #0x40]
//   0x09094c: A90557F6  stp      x22, x21, [sp, #0x50]
static inline uint64_t fde_func_1348_0x090940(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x090940ULL ^ (static_cast<uint64_t>(0xd10203ffULL) << 13);
    acc = (acc + a1 + 0xf9001bf9ULL) ^ 0x0c8500ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1349 | PC: 0x090ae4 | FDE: 0x0c8530 | Size: 256 bytes
// Hàm FDE #1349 | Địa chỉ PC: 0x090ae4 | Địa chỉ FDE: 0x0c8530 | Kích thước: 256 bytes
//   0x090ae4: D10143FF  sub      sp, sp, #0x50
//   0x090ae8: A9015FF8  stp      x24, x23, [sp, #0x10]
//   0x090aec: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x090af0: A9034FF4  stp      x20, x19, [sp, #0x30]
static inline uint64_t fde_func_1349_0x090ae4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x090ae4ULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xa9015ff8ULL) ^ 0x0c8530ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1350 | PC: 0x090c18 | FDE: 0x0c8560 | Size: 220 bytes [Java_com_lemon_nuro_ConversationHub_00024CppProxy_native_1remove]
// Hàm FDE #1350 | Địa chỉ PC: 0x090c18 | Địa chỉ FDE: 0x0c8560 | Kích thước: 220 bytes
//   0x090c18: D10143FF  sub      sp, sp, #0x50
//   0x090c1c: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x090c20: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x090c24: A9047BFD  stp      x29, x30, [sp, #0x40]
static inline uint64_t fde_func_1350_0x090c18(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x090c18ULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xa90257f6ULL) ^ 0x0c8560ULL;
    acc ^= (acc >> 17) * 0x00dcULL;
    return acc;
}

// FDE #1351 | PC: 0x090cf4 | FDE: 0x0c85b8 | Size: 108 bytes
// Hàm FDE #1351 | Địa chỉ PC: 0x090cf4 | Địa chỉ FDE: 0x0c85b8 | Kích thước: 108 bytes
//   0x090cf4: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x090cf8: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x090cfc: 910043FD  add      x29, sp, #0x10
//   0x090d00: 52800300  mov      w0, #0x18
static inline uint64_t fde_func_1351_0x090cf4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x090cf4ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x0c85b8ULL;
    acc ^= (acc >> 17) * 0x006cULL;
    return acc;
}

// FDE #1352 | PC: 0x090d60 | FDE: 0x0c83f8 | Size: 60 bytes
// Hàm FDE #1352 | Địa chỉ PC: 0x090d60 | Địa chỉ FDE: 0x0c83f8 | Kích thước: 60 bytes
//   0x090d60: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x090d64: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x090d68: 910043FD  add      x29, sp, #0x10
//   0x090d6c: F9400013  ldr      x19, [x0]
static inline uint64_t fde_func_1352_0x090d60(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x090d60ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x0c83f8ULL;
    acc ^= (acc >> 17) * 0x003cULL;
    return acc;
}

// FDE #1353 | PC: 0x090d9c | FDE: 0x0c85e0 | Size: 256 bytes
// Hàm FDE #1353 | Địa chỉ PC: 0x090d9c | Địa chỉ FDE: 0x0c85e0 | Kích thước: 256 bytes
//   0x090d9c: D10143FF  sub      sp, sp, #0x50
//   0x090da0: F90013F5  str      x21, [sp, #0x20]
//   0x090da4: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x090da8: A9047BFD  stp      x29, x30, [sp, #0x40]
static inline uint64_t fde_func_1353_0x090d9c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x090d9cULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xf90013f5ULL) ^ 0x0c85e0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1354 | PC: 0x090eb8 | FDE: 0x0c8608 | Size: 256 bytes
// Hàm FDE #1354 | Địa chỉ PC: 0x090eb8 | Địa chỉ FDE: 0x0c8608 | Kích thước: 256 bytes
//   0x090eb8: A9BC5FF8  stp      x24, x23, [sp, #-0x40]!
//   0x090ebc: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x090ec0: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x090ec4: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_1354_0x090eb8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x090eb8ULL ^ (static_cast<uint64_t>(0xa9bc5ff8ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x0c8608ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1355 | PC: 0x090fc8 | FDE: 0x0c8638 | Size: 256 bytes
// Hàm FDE #1355 | Địa chỉ PC: 0x090fc8 | Địa chỉ FDE: 0x0c8638 | Kích thước: 256 bytes
//   0x090fc8: D10143FF  sub      sp, sp, #0x50
//   0x090fcc: F90013F5  str      x21, [sp, #0x20]
//   0x090fd0: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x090fd4: A9047BFD  stp      x29, x30, [sp, #0x40]
static inline uint64_t fde_func_1355_0x090fc8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x090fc8ULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xf90013f5ULL) ^ 0x0c8638ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1356 | PC: 0x0910e4 | FDE: 0x0c8660 | Size: 256 bytes
// Hàm FDE #1356 | Địa chỉ PC: 0x0910e4 | Địa chỉ FDE: 0x0c8660 | Kích thước: 256 bytes
//   0x0910e4: A9BC5FF8  stp      x24, x23, [sp, #-0x40]!
//   0x0910e8: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x0910ec: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x0910f0: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_1356_0x0910e4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0910e4ULL ^ (static_cast<uint64_t>(0xa9bc5ff8ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x0c8660ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1357 | PC: 0x0911f4 | FDE: 0x0c86e8 | Size: 232 bytes
// Hàm FDE #1357 | Địa chỉ PC: 0x0911f4 | Địa chỉ FDE: 0x0c86e8 | Kích thước: 232 bytes
//   0x0911f4: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0911f8: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0911fc: 910043FD  add      x29, sp, #0x10
//   0x091200: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_1357_0x0911f4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0911f4ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x0c86e8ULL;
    acc ^= (acc >> 17) * 0x00e8ULL;
    return acc;
}

// FDE #1358 | PC: 0x0912dc | FDE: 0x0c8690 | Size: 20 bytes
// Hàm FDE #1358 | Địa chỉ PC: 0x0912dc | Địa chỉ FDE: 0x0c8690 | Kích thước: 20 bytes
//   0x0912dc: F9400001  ldr      x1, [x0]
//   0x0912e0: F900001F  str      xzr, [x0]
//   0x0912e4: B4000041  cbz      x1, #0x912ec
//   0x0912e8: 140043E2  b        #0xa2270
static inline uint64_t fde_func_1358_0x0912dc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0912dcULL ^ (static_cast<uint64_t>(0xf9400001ULL) << 13);
    acc = (acc + a1 + 0xf900001fULL) ^ 0x0c8690ULL;
    acc ^= (acc >> 17) * 0x0014ULL;
    return acc;
}

// FDE #1359 | PC: 0x0912f0 | FDE: 0x0c8710 | Size: 256 bytes
// Hàm FDE #1359 | Địa chỉ PC: 0x0912f0 | Địa chỉ FDE: 0x0c8710 | Kích thước: 256 bytes
//   0x0912f0: D101C3FF  sub      sp, sp, #0x70
//   0x0912f4: A90267FA  stp      x26, x25, [sp, #0x20]
//   0x0912f8: A9035FF8  stp      x24, x23, [sp, #0x30]
//   0x0912fc: A90457F6  stp      x22, x21, [sp, #0x40]
static inline uint64_t fde_func_1359_0x0912f0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0912f0ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xa90267faULL) ^ 0x0c8710ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1360 | PC: 0x091468 | FDE: 0x0c8748 | Size: 256 bytes
// Hàm FDE #1360 | Địa chỉ PC: 0x091468 | Địa chỉ FDE: 0x0c8748 | Kích thước: 256 bytes
//   0x091468: D10283FF  sub      sp, sp, #0xa0
//   0x09146c: F90033F7  str      x23, [sp, #0x60]
//   0x091470: A90757F6  stp      x22, x21, [sp, #0x70]
//   0x091474: A9084FF4  stp      x20, x19, [sp, #0x80]
static inline uint64_t fde_func_1360_0x091468(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x091468ULL ^ (static_cast<uint64_t>(0xd10283ffULL) << 13);
    acc = (acc + a1 + 0xf90033f7ULL) ^ 0x0c8748ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1361 | PC: 0x09163c | FDE: 0x0c87a0 | Size: 112 bytes
// Hàm FDE #1361 | Địa chỉ PC: 0x09163c | Địa chỉ FDE: 0x0c87a0 | Kích thước: 112 bytes
//   0x09163c: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x091640: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x091644: 910043FD  add      x29, sp, #0x10
//   0x091648: 52800600  mov      w0, #0x30
static inline uint64_t fde_func_1361_0x09163c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x09163cULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x0c87a0ULL;
    acc ^= (acc >> 17) * 0x0070ULL;
    return acc;
}

// FDE #1362 | PC: 0x0916ac | FDE: 0x0c86c8 | Size: 72 bytes
// Hàm FDE #1362 | Địa chỉ PC: 0x0916ac | Địa chỉ FDE: 0x0c86c8 | Kích thước: 72 bytes
//   0x0916ac: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x0916b0: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0916b4: 910043FD  add      x29, sp, #0x10
//   0x0916b8: F9400013  ldr      x19, [x0]
static inline uint64_t fde_func_1362_0x0916ac(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0916acULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x0c86c8ULL;
    acc ^= (acc >> 17) * 0x0048ULL;
    return acc;
}

// FDE #1363 | PC: 0x0916f4 | FDE: 0x0c8958 | Size: 256 bytes
// Hàm FDE #1363 | Địa chỉ PC: 0x0916f4 | Địa chỉ FDE: 0x0c8958 | Kích thước: 256 bytes
//   0x0916f4: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x0916f8: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0916fc: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x091700: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1363_0x0916f4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0916f4ULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x0c8958ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1364 | PC: 0x091844 | FDE: 0x0c87c8 | Size: 48 bytes
// Hàm FDE #1364 | Địa chỉ PC: 0x091844 | Địa chỉ FDE: 0x0c87c8 | Kích thước: 48 bytes
//   0x091844: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x091848: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x09184c: 910043FD  add      x29, sp, #0x10
//   0x091850: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_1364_0x091844(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x091844ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x0c87c8ULL;
    acc ^= (acc >> 17) * 0x0030ULL;
    return acc;
}

// FDE #1365 | PC: 0x091874 | FDE: 0x0c8980 | Size: 196 bytes
// Hàm FDE #1365 | Địa chỉ PC: 0x091874 | Địa chỉ FDE: 0x0c8980 | Kích thước: 196 bytes
//   0x091874: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x091878: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x09187c: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x091880: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1365_0x091874(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x091874ULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x0c8980ULL;
    acc ^= (acc >> 17) * 0x00c4ULL;
    return acc;
}

// FDE #1366 | PC: 0x091938 | FDE: 0x0c87e8 | Size: 8 bytes
// Hàm FDE #1366 | Địa chỉ PC: 0x091938 | Địa chỉ FDE: 0x0c87e8 | Kích thước: 8 bytes
//   0x091938: 91002000  add      x0, x0, #8
//   0x09193c: 14000001  b        #0x91940
static inline uint64_t fde_func_1366_0x091938(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x091938ULL ^ (static_cast<uint64_t>(0x91002000ULL) << 13);
    acc = (acc + a1 + 0x14000001ULL) ^ 0x0c87e8ULL;
    acc ^= (acc >> 17) * 0x0008ULL;
    return acc;
}

// FDE #1367 | PC: 0x091940 | FDE: 0x0c89a8 | Size: 232 bytes
// Hàm FDE #1367 | Địa chỉ PC: 0x091940 | Địa chỉ FDE: 0x0c89a8 | Kích thước: 232 bytes
//   0x091940: D10103FF  sub      sp, sp, #0x40
//   0x091944: F9000BF5  str      x21, [sp, #0x10]
//   0x091948: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x09194c: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_1367_0x091940(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x091940ULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xf9000bf5ULL) ^ 0x0c89a8ULL;
    acc ^= (acc >> 17) * 0x00e8ULL;
    return acc;
}

// FDE #1368 | PC: 0x091a28 | FDE: 0x0c8800 | Size: 40 bytes
// Hàm FDE #1368 | Địa chỉ PC: 0x091a28 | Địa chỉ FDE: 0x0c8800 | Kích thước: 40 bytes
//   0x091a28: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x091a2c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x091a30: 910043FD  add      x29, sp, #0x10
//   0x091a34: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_1368_0x091a28(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x091a28ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x0c8800ULL;
    acc ^= (acc >> 17) * 0x0028ULL;
    return acc;
}

// FDE #1369 | PC: 0x091a50 | FDE: 0x0c89d0 | Size: 256 bytes
// Hàm FDE #1369 | Địa chỉ PC: 0x091a50 | Địa chỉ FDE: 0x0c89d0 | Kích thước: 256 bytes
//   0x091a50: D101C3FF  sub      sp, sp, #0x70
//   0x091a54: A9035FF8  stp      x24, x23, [sp, #0x30]
//   0x091a58: A90457F6  stp      x22, x21, [sp, #0x40]
//   0x091a5c: A9054FF4  stp      x20, x19, [sp, #0x50]
static inline uint64_t fde_func_1369_0x091a50(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x091a50ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xa9035ff8ULL) ^ 0x0c89d0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1370 | PC: 0x091ba4 | FDE: 0x0c8820 | Size: 156 bytes
// Hàm FDE #1370 | Địa chỉ PC: 0x091ba4 | Địa chỉ FDE: 0x0c8820 | Kích thước: 156 bytes
//   0x091ba4: D10483FF  sub      sp, sp, #0x120
//   0x091ba8: A9104FFC  stp      x28, x19, [sp, #0x100]
//   0x091bac: A9117BFD  stp      x29, x30, [sp, #0x110]
//   0x091bb0: 910443FD  add      x29, sp, #0x110
static inline uint64_t fde_func_1370_0x091ba4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x091ba4ULL ^ (static_cast<uint64_t>(0xd10483ffULL) << 13);
    acc = (acc + a1 + 0xa9104ffcULL) ^ 0x0c8820ULL;
    acc ^= (acc >> 17) * 0x009cULL;
    return acc;
}

// FDE #1371 | PC: 0x091c40 | FDE: 0x0c8a00 | Size: 256 bytes
// Hàm FDE #1371 | Địa chỉ PC: 0x091c40 | Địa chỉ FDE: 0x0c8a00 | Kích thước: 256 bytes
//   0x091c40: D10183FF  sub      sp, sp, #0x60
//   0x091c44: F90013F7  str      x23, [sp, #0x20]
//   0x091c48: A90357F6  stp      x22, x21, [sp, #0x30]
//   0x091c4c: A9044FF4  stp      x20, x19, [sp, #0x40]
static inline uint64_t fde_func_1371_0x091c40(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x091c40ULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xf90013f7ULL) ^ 0x0c8a00ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1372 | PC: 0x091d40 | FDE: 0x0c8a30 | Size: 256 bytes
// Hàm FDE #1372 | Địa chỉ PC: 0x091d40 | Địa chỉ FDE: 0x0c8a30 | Kích thước: 256 bytes
//   0x091d40: D10183FF  sub      sp, sp, #0x60
//   0x091d44: F90013F7  str      x23, [sp, #0x20]
//   0x091d48: A90357F6  stp      x22, x21, [sp, #0x30]
//   0x091d4c: A9044FF4  stp      x20, x19, [sp, #0x40]
static inline uint64_t fde_func_1372_0x091d40(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x091d40ULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xf90013f7ULL) ^ 0x0c8a30ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1373 | PC: 0x091e40 | FDE: 0x0c8a60 | Size: 256 bytes
// Hàm FDE #1373 | Địa chỉ PC: 0x091e40 | Địa chỉ FDE: 0x0c8a60 | Kích thước: 256 bytes
//   0x091e40: D10183FF  sub      sp, sp, #0x60
//   0x091e44: F90013F7  str      x23, [sp, #0x20]
//   0x091e48: A90357F6  stp      x22, x21, [sp, #0x30]
//   0x091e4c: A9044FF4  stp      x20, x19, [sp, #0x40]
static inline uint64_t fde_func_1373_0x091e40(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x091e40ULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xf90013f7ULL) ^ 0x0c8a60ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1374 | PC: 0x091f40 | FDE: 0x0c8a90 | Size: 256 bytes
// Hàm FDE #1374 | Địa chỉ PC: 0x091f40 | Địa chỉ FDE: 0x0c8a90 | Kích thước: 256 bytes
//   0x091f40: D10203FF  sub      sp, sp, #0x80
//   0x091f44: F9001BF9  str      x25, [sp, #0x30]
//   0x091f48: A9045FF8  stp      x24, x23, [sp, #0x40]
//   0x091f4c: A90557F6  stp      x22, x21, [sp, #0x50]
static inline uint64_t fde_func_1374_0x091f40(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x091f40ULL ^ (static_cast<uint64_t>(0xd10203ffULL) << 13);
    acc = (acc + a1 + 0xf9001bf9ULL) ^ 0x0c8a90ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1375 | PC: 0x092104 | FDE: 0x0c8ac0 | Size: 256 bytes
// Hàm FDE #1375 | Địa chỉ PC: 0x092104 | Địa chỉ FDE: 0x0c8ac0 | Kích thước: 256 bytes
//   0x092104: D101C3FF  sub      sp, sp, #0x70
//   0x092108: A9035FF8  stp      x24, x23, [sp, #0x30]
//   0x09210c: A90457F6  stp      x22, x21, [sp, #0x40]
//   0x092110: A9054FF4  stp      x20, x19, [sp, #0x50]
static inline uint64_t fde_func_1375_0x092104(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x092104ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xa9035ff8ULL) ^ 0x0c8ac0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1376 | PC: 0x09226c | FDE: 0x0c8af0 | Size: 256 bytes
// Hàm FDE #1376 | Địa chỉ PC: 0x09226c | Địa chỉ FDE: 0x0c8af0 | Kích thước: 256 bytes
//   0x09226c: D101C3FF  sub      sp, sp, #0x70
//   0x092270: A9035FF8  stp      x24, x23, [sp, #0x30]
//   0x092274: A90457F6  stp      x22, x21, [sp, #0x40]
//   0x092278: A9054FF4  stp      x20, x19, [sp, #0x50]
static inline uint64_t fde_func_1376_0x09226c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x09226cULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xa9035ff8ULL) ^ 0x0c8af0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1377 | PC: 0x0923b8 | FDE: 0x0c8840 | Size: 48 bytes [Java_com_lemon_nuro_ConversationListener_00024CppProxy_nativeDestroy]
// Hàm FDE #1377 | Địa chỉ PC: 0x0923b8 | Địa chỉ FDE: 0x0c8840 | Kích thước: 48 bytes
//   0x0923b8: B4000162  cbz      x2, #0x923e4
//   0x0923bc: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x0923c0: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0923c4: 910043FD  add      x29, sp, #0x10
static inline uint64_t fde_func_1377_0x0923b8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0923b8ULL ^ (static_cast<uint64_t>(0xb4000162ULL) << 13);
    acc = (acc + a1 + 0xf81e0ff3ULL) ^ 0x0c8840ULL;
    acc ^= (acc >> 17) * 0x0030ULL;
    return acc;
}

// FDE #1378 | PC: 0x0923e8 | FDE: 0x0c8b20 | Size: 252 bytes
// Hàm FDE #1378 | Địa chỉ PC: 0x0923e8 | Địa chỉ FDE: 0x0c8b20 | Kích thước: 252 bytes
//   0x0923e8: D10103FF  sub      sp, sp, #0x40
//   0x0923ec: F9000BF5  str      x21, [sp, #0x10]
//   0x0923f0: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x0923f4: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_1378_0x0923e8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0923e8ULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xf9000bf5ULL) ^ 0x0c8b20ULL;
    acc ^= (acc >> 17) * 0x00fcULL;
    return acc;
}

// FDE #1379 | PC: 0x0924e4 | FDE: 0x0c8b48 | Size: 236 bytes [Java_com_lemon_nuro_ConversationListener_00024CppProxy_native_1onAck]
// Hàm FDE #1379 | Địa chỉ PC: 0x0924e4 | Địa chỉ FDE: 0x0c8b48 | Kích thước: 236 bytes
//   0x0924e4: D10143FF  sub      sp, sp, #0x50
//   0x0924e8: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x0924ec: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x0924f0: A9047BFD  stp      x29, x30, [sp, #0x40]
static inline uint64_t fde_func_1379_0x0924e4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0924e4ULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xa90257f6ULL) ^ 0x0c8b48ULL;
    acc ^= (acc >> 17) * 0x00ecULL;
    return acc;
}

// FDE #1380 | PC: 0x0925d0 | FDE: 0x0c8b78 | Size: 200 bytes [Java_com_lemon_nuro_ConversationListener_00024CppProxy_native_1onAssistantMessage]
// Hàm FDE #1380 | Địa chỉ PC: 0x0925d0 | Địa chỉ FDE: 0x0c8b78 | Kích thước: 200 bytes
//   0x0925d0: D10483FF  sub      sp, sp, #0x120
//   0x0925d4: F90073FC  str      x28, [sp, #0xe0]
//   0x0925d8: A90F57F6  stp      x22, x21, [sp, #0xf0]
//   0x0925dc: A9104FF4  stp      x20, x19, [sp, #0x100]
static inline uint64_t fde_func_1380_0x0925d0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0925d0ULL ^ (static_cast<uint64_t>(0xd10483ffULL) << 13);
    acc = (acc + a1 + 0xf90073fcULL) ^ 0x0c8b78ULL;
    acc ^= (acc >> 17) * 0x00c8ULL;
    return acc;
}

// FDE #1381 | PC: 0x092698 | FDE: 0x0c8ba8 | Size: 200 bytes [Java_com_lemon_nuro_ConversationListener_00024CppProxy_native_1onUserMessage]
// Hàm FDE #1381 | Địa chỉ PC: 0x092698 | Địa chỉ FDE: 0x0c8ba8 | Kích thước: 200 bytes
//   0x092698: F81C0FFC  str      x28, [sp, #-0x40]!
//   0x09269c: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x0926a0: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x0926a4: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_1381_0x092698(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x092698ULL ^ (static_cast<uint64_t>(0xf81c0ffcULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x0c8ba8ULL;
    acc ^= (acc >> 17) * 0x00c8ULL;
    return acc;
}

// FDE #1382 | PC: 0x092760 | FDE: 0x0c8bd8 | Size: 256 bytes [Java_com_lemon_nuro_ConversationListener_00024CppProxy_native_1onSystemMessage]
// Hàm FDE #1382 | Địa chỉ PC: 0x092760 | Địa chỉ FDE: 0x0c8bd8 | Kích thước: 256 bytes
//   0x092760: D10283FF  sub      sp, sp, #0xa0
//   0x092764: A90757F6  stp      x22, x21, [sp, #0x70]
//   0x092768: A9084FF4  stp      x20, x19, [sp, #0x80]
//   0x09276c: A9097BFD  stp      x29, x30, [sp, #0x90]
static inline uint64_t fde_func_1382_0x092760(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x092760ULL ^ (static_cast<uint64_t>(0xd10283ffULL) << 13);
    acc = (acc + a1 + 0xa90757f6ULL) ^ 0x0c8bd8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1383 | PC: 0x092880 | FDE: 0x0c8c08 | Size: 256 bytes [Java_com_lemon_nuro_ConversationListener_00024CppProxy_native_1onSectionStatus]
// Hàm FDE #1383 | Địa chỉ PC: 0x092880 | Địa chỉ FDE: 0x0c8c08 | Kích thước: 256 bytes
//   0x092880: D102C3FF  sub      sp, sp, #0xb0
//   0x092884: A9075FF8  stp      x24, x23, [sp, #0x70]
//   0x092888: A90857F6  stp      x22, x21, [sp, #0x80]
//   0x09288c: A9094FF4  stp      x20, x19, [sp, #0x90]
static inline uint64_t fde_func_1383_0x092880(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x092880ULL ^ (static_cast<uint64_t>(0xd102c3ffULL) << 13);
    acc = (acc + a1 + 0xa9075ff8ULL) ^ 0x0c8c08ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1384 | PC: 0x092a0c | FDE: 0x0c8c38 | Size: 256 bytes [Java_com_lemon_nuro_ConversationListener_00024CppProxy_native_1onRecoverStatus]
// Hàm FDE #1384 | Địa chỉ PC: 0x092a0c | Địa chỉ FDE: 0x0c8c38 | Kích thước: 256 bytes
//   0x092a0c: D10243FF  sub      sp, sp, #0x90
//   0x092a10: F9002BF7  str      x23, [sp, #0x50]
//   0x092a14: A90657F6  stp      x22, x21, [sp, #0x60]
//   0x092a18: A9074FF4  stp      x20, x19, [sp, #0x70]
static inline uint64_t fde_func_1384_0x092a0c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x092a0cULL ^ (static_cast<uint64_t>(0xd10243ffULL) << 13);
    acc = (acc + a1 + 0xf9002bf7ULL) ^ 0x0c8c38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1385 | PC: 0x092b50 | FDE: 0x0c8c68 | Size: 256 bytes [Java_com_lemon_nuro_ConversationListener_00024CppProxy_native_1onTracingEvent]
// Hàm FDE #1385 | Địa chỉ PC: 0x092b50 | Địa chỉ FDE: 0x0c8c68 | Kích thước: 256 bytes
//   0x092b50: D101C3FF  sub      sp, sp, #0x70
//   0x092b54: A90457F6  stp      x22, x21, [sp, #0x40]
//   0x092b58: A9054FF4  stp      x20, x19, [sp, #0x50]
//   0x092b5c: A9067BFD  stp      x29, x30, [sp, #0x60]
static inline uint64_t fde_func_1385_0x092b50(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x092b50ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xa90457f6ULL) ^ 0x0c8c68ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1386 | PC: 0x092c6c | FDE: 0x0c8cc0 | Size: 216 bytes
// Hàm FDE #1386 | Địa chỉ PC: 0x092c6c | Địa chỉ FDE: 0x0c8cc0 | Kích thước: 216 bytes
//   0x092c6c: D10143FF  sub      sp, sp, #0x50
//   0x092c70: F90013F5  str      x21, [sp, #0x20]
//   0x092c74: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x092c78: A9047BFD  stp      x29, x30, [sp, #0x40]
static inline uint64_t fde_func_1386_0x092c6c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x092c6cULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xf90013f5ULL) ^ 0x0c8cc0ULL;
    acc ^= (acc >> 17) * 0x00d8ULL;
    return acc;
}

// FDE #1387 | PC: 0x092d44 | FDE: 0x0c8880 | Size: 72 bytes
// Hàm FDE #1387 | Địa chỉ PC: 0x092d44 | Địa chỉ FDE: 0x0c8880 | Kích thước: 72 bytes
//   0x092d44: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x092d48: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x092d4c: 910043FD  add      x29, sp, #0x10
//   0x092d50: F9400013  ldr      x19, [x0]
static inline uint64_t fde_func_1387_0x092d44(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x092d44ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x0c8880ULL;
    acc ^= (acc >> 17) * 0x0048ULL;
    return acc;
}

// FDE #1388 | PC: 0x092d8c | FDE: 0x0c8d10 | Size: 216 bytes
// Hàm FDE #1388 | Địa chỉ PC: 0x092d8c | Địa chỉ FDE: 0x0c8d10 | Kích thước: 216 bytes
//   0x092d8c: D10143FF  sub      sp, sp, #0x50
//   0x092d90: F90013F5  str      x21, [sp, #0x20]
//   0x092d94: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x092d98: A9047BFD  stp      x29, x30, [sp, #0x40]
static inline uint64_t fde_func_1388_0x092d8c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x092d8cULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xf90013f5ULL) ^ 0x0c8d10ULL;
    acc ^= (acc >> 17) * 0x00d8ULL;
    return acc;
}

// FDE #1389 | PC: 0x092e64 | FDE: 0x0c88c0 | Size: 72 bytes
// Hàm FDE #1389 | Địa chỉ PC: 0x092e64 | Địa chỉ FDE: 0x0c88c0 | Kích thước: 72 bytes
//   0x092e64: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x092e68: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x092e6c: 910043FD  add      x29, sp, #0x10
//   0x092e70: F9400013  ldr      x19, [x0]
static inline uint64_t fde_func_1389_0x092e64(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x092e64ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x0c88c0ULL;
    acc ^= (acc >> 17) * 0x0048ULL;
    return acc;
}

// FDE #1390 | PC: 0x092eac | FDE: 0x0c8d60 | Size: 216 bytes
// Hàm FDE #1390 | Địa chỉ PC: 0x092eac | Địa chỉ FDE: 0x0c8d60 | Kích thước: 216 bytes
//   0x092eac: D10143FF  sub      sp, sp, #0x50
//   0x092eb0: F90013F5  str      x21, [sp, #0x20]
//   0x092eb4: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x092eb8: A9047BFD  stp      x29, x30, [sp, #0x40]
static inline uint64_t fde_func_1390_0x092eac(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x092eacULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xf90013f5ULL) ^ 0x0c8d60ULL;
    acc ^= (acc >> 17) * 0x00d8ULL;
    return acc;
}

// FDE #1391 | PC: 0x092f84 | FDE: 0x0c8900 | Size: 72 bytes
// Hàm FDE #1391 | Địa chỉ PC: 0x092f84 | Địa chỉ FDE: 0x0c8900 | Kích thước: 72 bytes
//   0x092f84: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x092f88: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x092f8c: 910043FD  add      x29, sp, #0x10
//   0x092f90: F9400013  ldr      x19, [x0]
static inline uint64_t fde_func_1391_0x092f84(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x092f84ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x0c8900ULL;
    acc ^= (acc >> 17) * 0x0048ULL;
    return acc;
}

// FDE #1392 | PC: 0x092fcc | FDE: 0x0c8920 | Size: 88 bytes
// Hàm FDE #1392 | Địa chỉ PC: 0x092fcc | Địa chỉ FDE: 0x0c8920 | Kích thước: 88 bytes
//   0x092fcc: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x092fd0: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x092fd4: 910043FD  add      x29, sp, #0x10
//   0x092fd8: F9400413  ldr      x19, [x0, #8]
static inline uint64_t fde_func_1392_0x092fcc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x092fccULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x0c8920ULL;
    acc ^= (acc >> 17) * 0x0058ULL;
    return acc;
}

// FDE #1393 | PC: 0x093024 | FDE: 0x0c8940 | Size: 20 bytes
// Hàm FDE #1393 | Địa chỉ PC: 0x093024 | Địa chỉ FDE: 0x0c8940 | Kích thước: 20 bytes
//   0x093024: F9400001  ldr      x1, [x0]
//   0x093028: F900001F  str      xzr, [x0]
//   0x09302c: B4000041  cbz      x1, #0x93034
//   0x093030: 14003C90  b        #0xa2270
static inline uint64_t fde_func_1393_0x093024(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x093024ULL ^ (static_cast<uint64_t>(0xf9400001ULL) << 13);
    acc = (acc + a1 + 0xf900001fULL) ^ 0x0c8940ULL;
    acc ^= (acc >> 17) * 0x0014ULL;
    return acc;
}

// FDE #1394 | PC: 0x093038 | FDE: 0x0c8e40 | Size: 256 bytes
// Hàm FDE #1394 | Địa chỉ PC: 0x093038 | Địa chỉ FDE: 0x0c8e40 | Kích thước: 256 bytes
//   0x093038: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x09303c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x093040: 910043FD  add      x29, sp, #0x10
//   0x093044: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_1394_0x093038(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x093038ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x0c8e40ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1395 | PC: 0x0931c0 | FDE: 0x0c8d88 | Size: 20 bytes
// Hàm FDE #1395 | Địa chỉ PC: 0x0931c0 | Địa chỉ FDE: 0x0c8d88 | Kích thước: 20 bytes
//   0x0931c0: F9400001  ldr      x1, [x0]
//   0x0931c4: F900001F  str      xzr, [x0]
//   0x0931c8: B4000041  cbz      x1, #0x931d0
//   0x0931cc: 14003C29  b        #0xa2270
static inline uint64_t fde_func_1395_0x0931c0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0931c0ULL ^ (static_cast<uint64_t>(0xf9400001ULL) << 13);
    acc = (acc + a1 + 0xf900001fULL) ^ 0x0c8d88ULL;
    acc ^= (acc >> 17) * 0x0014ULL;
    return acc;
}

// FDE #1396 | PC: 0x0931d4 | FDE: 0x0c8e68 | Size: 256 bytes
// Hàm FDE #1396 | Địa chỉ PC: 0x0931d4 | Địa chỉ FDE: 0x0c8e68 | Kích thước: 256 bytes
//   0x0931d4: D10403FF  sub      sp, sp, #0x100
//   0x0931d8: A90A6FFC  stp      x28, x27, [sp, #0xa0]
//   0x0931dc: A90B67FA  stp      x26, x25, [sp, #0xb0]
//   0x0931e0: A90C5FF8  stp      x24, x23, [sp, #0xc0]
static inline uint64_t fde_func_1396_0x0931d4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0931d4ULL ^ (static_cast<uint64_t>(0xd10403ffULL) << 13);
    acc = (acc + a1 + 0xa90a6ffcULL) ^ 0x0c8e68ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1397 | PC: 0x093688 | FDE: 0x0c8ea0 | Size: 256 bytes
// Hàm FDE #1397 | Địa chỉ PC: 0x093688 | Địa chỉ FDE: 0x0c8ea0 | Kích thước: 256 bytes
//   0x093688: D103C3FF  sub      sp, sp, #0xf0
//   0x09368c: A9096FFC  stp      x28, x27, [sp, #0x90]
//   0x093690: A90A67FA  stp      x26, x25, [sp, #0xa0]
//   0x093694: A90B5FF8  stp      x24, x23, [sp, #0xb0]
static inline uint64_t fde_func_1397_0x093688(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x093688ULL ^ (static_cast<uint64_t>(0xd103c3ffULL) << 13);
    acc = (acc + a1 + 0xa9096ffcULL) ^ 0x0c8ea0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1398 | PC: 0x093b60 | FDE: 0x0c8f00 | Size: 112 bytes
// Hàm FDE #1398 | Địa chỉ PC: 0x093b60 | Địa chỉ FDE: 0x0c8f00 | Kích thước: 112 bytes
//   0x093b60: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x093b64: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x093b68: 910043FD  add      x29, sp, #0x10
//   0x093b6c: 52800B00  mov      w0, #0x58
static inline uint64_t fde_func_1398_0x093b60(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x093b60ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x0c8f00ULL;
    acc ^= (acc >> 17) * 0x0070ULL;
    return acc;
}

// FDE #1399 | PC: 0x093bd0 | FDE: 0x0c8dc0 | Size: 72 bytes
// Hàm FDE #1399 | Địa chỉ PC: 0x093bd0 | Địa chỉ FDE: 0x0c8dc0 | Kích thước: 72 bytes
//   0x093bd0: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x093bd4: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x093bd8: 910043FD  add      x29, sp, #0x10
//   0x093bdc: F9400013  ldr      x19, [x0]
static inline uint64_t fde_func_1399_0x093bd0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x093bd0ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x0c8dc0ULL;
    acc ^= (acc >> 17) * 0x0048ULL;
    return acc;
}

// FDE #1400 | PC: 0x093c18 | FDE: 0x0c8f50 | Size: 212 bytes
// Hàm FDE #1400 | Địa chỉ PC: 0x093c18 | Địa chỉ FDE: 0x0c8f50 | Kích thước: 212 bytes
//   0x093c18: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x093c1c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x093c20: 910043FD  add      x29, sp, #0x10
//   0x093c24: 52800300  mov      w0, #0x18
static inline uint64_t fde_func_1400_0x093c18(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x093c18ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x0c8f50ULL;
    acc ^= (acc >> 17) * 0x00d4ULL;
    return acc;
}

// FDE #1401 | PC: 0x093cec | FDE: 0x0c8e00 | Size: 72 bytes
// Hàm FDE #1401 | Địa chỉ PC: 0x093cec | Địa chỉ FDE: 0x0c8e00 | Kích thước: 72 bytes
//   0x093cec: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x093cf0: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x093cf4: 910043FD  add      x29, sp, #0x10
//   0x093cf8: F9400013  ldr      x19, [x0]
static inline uint64_t fde_func_1401_0x093cec(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x093cecULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x0c8e00ULL;
    acc ^= (acc >> 17) * 0x0048ULL;
    return acc;
}

// FDE #1402 | PC: 0x093d34 | FDE: 0x0c8e20 | Size: 156 bytes
// Hàm FDE #1402 | Địa chỉ PC: 0x093d34 | Địa chỉ FDE: 0x0c8e20 | Kích thước: 156 bytes
//   0x093d34: D10483FF  sub      sp, sp, #0x120
//   0x093d38: A9104FFC  stp      x28, x19, [sp, #0x100]
//   0x093d3c: A9117BFD  stp      x29, x30, [sp, #0x110]
//   0x093d40: 910443FD  add      x29, sp, #0x110
static inline uint64_t fde_func_1402_0x093d34(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x093d34ULL ^ (static_cast<uint64_t>(0xd10483ffULL) << 13);
    acc = (acc + a1 + 0xa9104ffcULL) ^ 0x0c8e20ULL;
    acc ^= (acc >> 17) * 0x009cULL;
    return acc;
}

// FDE #1403 | PC: 0x093dd0 | FDE: 0x0c8f78 | Size: 28 bytes [JNI_OnLoad]
// Hàm FDE #1403 | Địa chỉ PC: 0x093dd0 | Địa chỉ FDE: 0x0c8f78 | Kích thước: 28 bytes
//   0x093dd0: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x093dd4: 910003FD  mov      x29, sp
//   0x093dd8: 94003845  bl       #0xa1eec
//   0x093ddc: 528000C0  mov      w0, #6
static inline uint64_t fde_func_1403_0x093dd0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x093dd0ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x0c8f78ULL;
    acc ^= (acc >> 17) * 0x001cULL;
    return acc;
}

// FDE #1404 | PC: 0x093dec | FDE: 0x0c8f98 | Size: 4 bytes [JNI_OnUnload]
// Hàm FDE #1404 | Địa chỉ PC: 0x093dec | Địa chỉ FDE: 0x0c8f98 | Kích thước: 4 bytes
//   0x093dec: 14003914  b        #0xa223c
static inline uint64_t fde_func_1404_0x093dec(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x093decULL ^ (static_cast<uint64_t>(0x14003914ULL) << 13);
    acc = (acc + a1 + 0xa9be4ff4ULL) ^ 0x0c8f98ULL;
    acc ^= (acc >> 17) * 0x0004ULL;
    return acc;
}

// FDE #1405 | PC: 0x093df0 | FDE: 0x0c9048 | Size: 256 bytes
// Hàm FDE #1405 | Địa chỉ PC: 0x093df0 | Địa chỉ FDE: 0x0c9048 | Kích thước: 256 bytes
//   0x093df0: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x093df4: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x093df8: 910043FD  add      x29, sp, #0x10
//   0x093dfc: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_1405_0x093df0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x093df0ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x0c9048ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1406 | PC: 0x093f18 | FDE: 0x0c8fb0 | Size: 20 bytes
// Hàm FDE #1406 | Địa chỉ PC: 0x093f18 | Địa chỉ FDE: 0x0c8fb0 | Kích thước: 20 bytes
//   0x093f18: F9400001  ldr      x1, [x0]
//   0x093f1c: F900001F  str      xzr, [x0]
//   0x093f20: B4000041  cbz      x1, #0x93f28
//   0x093f24: 140038D3  b        #0xa2270
static inline uint64_t fde_func_1406_0x093f18(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x093f18ULL ^ (static_cast<uint64_t>(0xf9400001ULL) << 13);
    acc = (acc + a1 + 0xf900001fULL) ^ 0x0c8fb0ULL;
    acc ^= (acc >> 17) * 0x0014ULL;
    return acc;
}

// FDE #1407 | PC: 0x093f2c | FDE: 0x0c9070 | Size: 256 bytes
// Hàm FDE #1407 | Địa chỉ PC: 0x093f2c | Địa chỉ FDE: 0x0c9070 | Kích thước: 256 bytes
//   0x093f2c: D10283FF  sub      sp, sp, #0xa0
//   0x093f30: A9046FFC  stp      x28, x27, [sp, #0x40]
//   0x093f34: A90567FA  stp      x26, x25, [sp, #0x50]
//   0x093f38: A9065FF8  stp      x24, x23, [sp, #0x60]
static inline uint64_t fde_func_1407_0x093f2c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x093f2cULL ^ (static_cast<uint64_t>(0xd10283ffULL) << 13);
    acc = (acc + a1 + 0xa9046ffcULL) ^ 0x0c9070ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1408 | PC: 0x09414c | FDE: 0x0c90a8 | Size: 256 bytes
// Hàm FDE #1408 | Địa chỉ PC: 0x09414c | Địa chỉ FDE: 0x0c90a8 | Kích thước: 256 bytes
//   0x09414c: D10343FF  sub      sp, sp, #0xd0
//   0x094150: F90043F9  str      x25, [sp, #0x80]
//   0x094154: A9095FF8  stp      x24, x23, [sp, #0x90]
//   0x094158: A90A57F6  stp      x22, x21, [sp, #0xa0]
static inline uint64_t fde_func_1408_0x09414c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x09414cULL ^ (static_cast<uint64_t>(0xd10343ffULL) << 13);
    acc = (acc + a1 + 0xf90043f9ULL) ^ 0x0c90a8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1409 | PC: 0x0943a0 | FDE: 0x0c9100 | Size: 216 bytes
// Hàm FDE #1409 | Địa chỉ PC: 0x0943a0 | Địa chỉ FDE: 0x0c9100 | Kích thước: 216 bytes
//   0x0943a0: D10143FF  sub      sp, sp, #0x50
//   0x0943a4: F90013F5  str      x21, [sp, #0x20]
//   0x0943a8: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x0943ac: A9047BFD  stp      x29, x30, [sp, #0x40]
static inline uint64_t fde_func_1409_0x0943a0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0943a0ULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xf90013f5ULL) ^ 0x0c9100ULL;
    acc ^= (acc >> 17) * 0x00d8ULL;
    return acc;
}

// FDE #1410 | PC: 0x094478 | FDE: 0x0c8fe8 | Size: 72 bytes
// Hàm FDE #1410 | Địa chỉ PC: 0x094478 | Địa chỉ FDE: 0x0c8fe8 | Kích thước: 72 bytes
//   0x094478: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x09447c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x094480: 910043FD  add      x29, sp, #0x10
//   0x094484: F9400013  ldr      x19, [x0]
static inline uint64_t fde_func_1410_0x094478(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x094478ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x0c8fe8ULL;
    acc ^= (acc >> 17) * 0x0048ULL;
    return acc;
}

// FDE #1411 | PC: 0x0944c0 | FDE: 0x0c9150 | Size: 112 bytes
// Hàm FDE #1411 | Địa chỉ PC: 0x0944c0 | Địa chỉ FDE: 0x0c9150 | Kích thước: 112 bytes
//   0x0944c0: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0944c4: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0944c8: 910043FD  add      x29, sp, #0x10
//   0x0944cc: 52800800  mov      w0, #0x40
static inline uint64_t fde_func_1411_0x0944c0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0944c0ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x0c9150ULL;
    acc ^= (acc >> 17) * 0x0070ULL;
    return acc;
}

// FDE #1412 | PC: 0x094530 | FDE: 0x0c9028 | Size: 72 bytes
// Hàm FDE #1412 | Địa chỉ PC: 0x094530 | Địa chỉ FDE: 0x0c9028 | Kích thước: 72 bytes
//   0x094530: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x094534: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x094538: 910043FD  add      x29, sp, #0x10
//   0x09453c: F9400013  ldr      x19, [x0]
static inline uint64_t fde_func_1412_0x094530(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x094530ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x0c9028ULL;
    acc ^= (acc >> 17) * 0x0048ULL;
    return acc;
}

// FDE #1413 | PC: 0x094578 | FDE: 0x0c9178 | Size: 12 bytes
// Hàm FDE #1413 | Địa chỉ PC: 0x094578 | Địa chỉ FDE: 0x0c9178 | Kích thước: 12 bytes
//   0x094578: D0000101  adrp     x1, #0xb6000
//   0x09457c: 913B9C21  add      x1, x1, #0xee7
//   0x094580: 140044B0  b        #0xa5840
static inline uint64_t fde_func_1413_0x094578(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x094578ULL ^ (static_cast<uint64_t>(0xd0000101ULL) << 13);
    acc = (acc + a1 + 0x913b9c21ULL) ^ 0x0c9178ULL;
    acc ^= (acc >> 17) * 0x000cULL;
    return acc;
}

// FDE #1414 | PC: 0x094584 | FDE: 0x0c9190 | Size: 4 bytes
// Hàm FDE #1414 | Địa chỉ PC: 0x094584 | Địa chỉ FDE: 0x0c9190 | Kích thước: 4 bytes
//   0x094584: 140044F1  b        #0xa5948
static inline uint64_t fde_func_1414_0x094584(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x094584ULL ^ (static_cast<uint64_t>(0x140044f1ULL) << 13);
    acc = (acc + a1 + 0xb4000162ULL) ^ 0x0c9190ULL;
    acc ^= (acc >> 17) * 0x0004ULL;
    return acc;
}

// FDE #1415 | PC: 0x094588 | FDE: 0x0c91a8 | Size: 48 bytes [Java_com_lemon_nuro_FileUploadStatusCallback_00024CppProxy_nativeDestroy]
// Hàm FDE #1415 | Địa chỉ PC: 0x094588 | Địa chỉ FDE: 0x0c91a8 | Kích thước: 48 bytes
//   0x094588: B4000162  cbz      x2, #0x945b4
//   0x09458c: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x094590: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x094594: 910043FD  add      x29, sp, #0x10
static inline uint64_t fde_func_1415_0x094588(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x094588ULL ^ (static_cast<uint64_t>(0xb4000162ULL) << 13);
    acc = (acc + a1 + 0xf81e0ff3ULL) ^ 0x0c91a8ULL;
    acc ^= (acc >> 17) * 0x0030ULL;
    return acc;
}

// FDE #1416 | PC: 0x0945b8 | FDE: 0x0c9228 | Size: 252 bytes
// Hàm FDE #1416 | Địa chỉ PC: 0x0945b8 | Địa chỉ FDE: 0x0c9228 | Kích thước: 252 bytes
//   0x0945b8: D10103FF  sub      sp, sp, #0x40
//   0x0945bc: F9000BF5  str      x21, [sp, #0x10]
//   0x0945c0: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x0945c4: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_1416_0x0945b8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0945b8ULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xf9000bf5ULL) ^ 0x0c9228ULL;
    acc ^= (acc >> 17) * 0x00fcULL;
    return acc;
}

// FDE #1417 | PC: 0x0946b4 | FDE: 0x0c9250 | Size: 96 bytes [Java_com_lemon_nuro_FileUploadStatusCallback_00024CppProxy_native_1onUploadProgress]
// Hàm FDE #1417 | Địa chỉ PC: 0x0946b4 | Địa chỉ FDE: 0x0c9250 | Kích thước: 96 bytes
//   0x0946b4: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x0946b8: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0946bc: 910043FD  add      x29, sp, #0x10
//   0x0946c0: F9400848  ldr      x8, [x2, #0x10]
static inline uint64_t fde_func_1417_0x0946b4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0946b4ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x0c9250ULL;
    acc ^= (acc >> 17) * 0x0060ULL;
    return acc;
}

// FDE #1418 | PC: 0x094714 | FDE: 0x0c9278 | Size: 256 bytes [Java_com_lemon_nuro_FileUploadStatusCallback_00024CppProxy_native_1onUploadSuccess]
// Hàm FDE #1418 | Địa chỉ PC: 0x094714 | Địa chỉ FDE: 0x0c9278 | Kích thước: 256 bytes
//   0x094714: D10203FF  sub      sp, sp, #0x80
//   0x094718: F90023F7  str      x23, [sp, #0x40]
//   0x09471c: A90557F6  stp      x22, x21, [sp, #0x50]
//   0x094720: A9064FF4  stp      x20, x19, [sp, #0x60]
static inline uint64_t fde_func_1418_0x094714(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x094714ULL ^ (static_cast<uint64_t>(0xd10203ffULL) << 13);
    acc = (acc + a1 + 0xf90023f7ULL) ^ 0x0c9278ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1419 | PC: 0x094840 | FDE: 0x0c92a8 | Size: 216 bytes [Java_com_lemon_nuro_FileUploadStatusCallback_00024CppProxy_native_1onUploadFailed]
// Hàm FDE #1419 | Địa chỉ PC: 0x094840 | Địa chỉ FDE: 0x0c92a8 | Kích thước: 216 bytes
//   0x094840: D10143FF  sub      sp, sp, #0x50
//   0x094844: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x094848: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x09484c: A9047BFD  stp      x29, x30, [sp, #0x40]
static inline uint64_t fde_func_1419_0x094840(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x094840ULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xa90257f6ULL) ^ 0x0c92a8ULL;
    acc ^= (acc >> 17) * 0x00d8ULL;
    return acc;
}

// FDE #1420 | PC: 0x094918 | FDE: 0x0c92d8 | Size: 92 bytes [Java_com_lemon_nuro_FileUploadStatusCallback_00024CppProxy_native_1onUploadCanceled]
// Hàm FDE #1420 | Địa chỉ PC: 0x094918 | Địa chỉ FDE: 0x0c92d8 | Kích thước: 92 bytes
//   0x094918: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x09491c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x094920: 910043FD  add      x29, sp, #0x10
//   0x094924: F9400848  ldr      x8, [x2, #0x10]
static inline uint64_t fde_func_1420_0x094918(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x094918ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x0c92d8ULL;
    acc ^= (acc >> 17) * 0x005cULL;
    return acc;
}

// FDE #1421 | PC: 0x094974 | FDE: 0x0c9328 | Size: 108 bytes
// Hàm FDE #1421 | Địa chỉ PC: 0x094974 | Địa chỉ FDE: 0x0c9328 | Kích thước: 108 bytes
//   0x094974: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x094978: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x09497c: 910043FD  add      x29, sp, #0x10
//   0x094980: 52800300  mov      w0, #0x18
static inline uint64_t fde_func_1421_0x094974(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x094974ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x0c9328ULL;
    acc ^= (acc >> 17) * 0x006cULL;
    return acc;
}

// FDE #1422 | PC: 0x0949e0 | FDE: 0x0c91e8 | Size: 60 bytes
// Hàm FDE #1422 | Địa chỉ PC: 0x0949e0 | Địa chỉ FDE: 0x0c91e8 | Kích thước: 60 bytes
//   0x0949e0: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x0949e4: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0949e8: 910043FD  add      x29, sp, #0x10
//   0x0949ec: F9400013  ldr      x19, [x0]
static inline uint64_t fde_func_1422_0x0949e0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0949e0ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x0c91e8ULL;
    acc ^= (acc >> 17) * 0x003cULL;
    return acc;
}

// FDE #1423 | PC: 0x094a1c | FDE: 0x0c9208 | Size: 88 bytes
// Hàm FDE #1423 | Địa chỉ PC: 0x094a1c | Địa chỉ FDE: 0x0c9208 | Kích thước: 88 bytes
//   0x094a1c: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x094a20: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x094a24: 910043FD  add      x29, sp, #0x10
//   0x094a28: F9400413  ldr      x19, [x0, #8]
static inline uint64_t fde_func_1423_0x094a1c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x094a1cULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x0c9208ULL;
    acc ^= (acc >> 17) * 0x0058ULL;
    return acc;
}

// FDE #1424 | PC: 0x094a74 | FDE: 0x0c9350 | Size: 12 bytes
// Hàm FDE #1424 | Địa chỉ PC: 0x094a74 | Địa chỉ FDE: 0x0c9350 | Kích thước: 12 bytes
//   0x094a74: F0000101  adrp     x1, #0xb7000
//   0x094a78: 91028021  add      x1, x1, #0xa0
//   0x094a7c: 14004371  b        #0xa5840
static inline uint64_t fde_func_1424_0x094a74(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x094a74ULL ^ (static_cast<uint64_t>(0xf0000101ULL) << 13);
    acc = (acc + a1 + 0x91028021ULL) ^ 0x0c9350ULL;
    acc ^= (acc >> 17) * 0x000cULL;
    return acc;
}

// FDE #1425 | PC: 0x094a80 | FDE: 0x0c9368 | Size: 4 bytes
// Hàm FDE #1425 | Địa chỉ PC: 0x094a80 | Địa chỉ FDE: 0x0c9368 | Kích thước: 4 bytes
//   0x094a80: 140043B2  b        #0xa5948
static inline uint64_t fde_func_1425_0x094a80(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x094a80ULL ^ (static_cast<uint64_t>(0x140043b2ULL) << 13);
    acc = (acc + a1 + 0xb4000162ULL) ^ 0x0c9368ULL;
    acc ^= (acc >> 17) * 0x0004ULL;
    return acc;
}

// FDE #1426 | PC: 0x094a84 | FDE: 0x0c9380 | Size: 48 bytes [Java_com_lemon_nuro_HttpCallback_00024CppProxy_nativeDestroy]
// Hàm FDE #1426 | Địa chỉ PC: 0x094a84 | Địa chỉ FDE: 0x0c9380 | Kích thước: 48 bytes
//   0x094a84: B4000162  cbz      x2, #0x94ab0
//   0x094a88: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x094a8c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x094a90: 910043FD  add      x29, sp, #0x10
static inline uint64_t fde_func_1426_0x094a84(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x094a84ULL ^ (static_cast<uint64_t>(0xb4000162ULL) << 13);
    acc = (acc + a1 + 0xf81e0ff3ULL) ^ 0x0c9380ULL;
    acc ^= (acc >> 17) * 0x0030ULL;
    return acc;
}

// FDE #1427 | PC: 0x094ab4 | FDE: 0x0c9400 | Size: 252 bytes
// Hàm FDE #1427 | Địa chỉ PC: 0x094ab4 | Địa chỉ FDE: 0x0c9400 | Kích thước: 252 bytes
//   0x094ab4: D10103FF  sub      sp, sp, #0x40
//   0x094ab8: F9000BF5  str      x21, [sp, #0x10]
//   0x094abc: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x094ac0: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_1427_0x094ab4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x094ab4ULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xf9000bf5ULL) ^ 0x0c9400ULL;
    acc ^= (acc >> 17) * 0x00fcULL;
    return acc;
}

// FDE #1428 | PC: 0x094bb0 | FDE: 0x0c9428 | Size: 224 bytes [Java_com_lemon_nuro_HttpCallback_00024CppProxy_native_1onResponse]
// Hàm FDE #1428 | Địa chỉ PC: 0x094bb0 | Địa chỉ FDE: 0x0c9428 | Kích thước: 224 bytes
//   0x094bb0: D10183FF  sub      sp, sp, #0x60
//   0x094bb4: A90357F6  stp      x22, x21, [sp, #0x30]
//   0x094bb8: A9044FF4  stp      x20, x19, [sp, #0x40]
//   0x094bbc: A9057BFD  stp      x29, x30, [sp, #0x50]
static inline uint64_t fde_func_1428_0x094bb0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x094bb0ULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xa90357f6ULL) ^ 0x0c9428ULL;
    acc ^= (acc >> 17) * 0x00e0ULL;
    return acc;
}

// FDE #1429 | PC: 0x094c90 | FDE: 0x0c9480 | Size: 108 bytes
// Hàm FDE #1429 | Địa chỉ PC: 0x094c90 | Địa chỉ FDE: 0x0c9480 | Kích thước: 108 bytes
//   0x094c90: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x094c94: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x094c98: 910043FD  add      x29, sp, #0x10
//   0x094c9c: 52800300  mov      w0, #0x18
static inline uint64_t fde_func_1429_0x094c90(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x094c90ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x0c9480ULL;
    acc ^= (acc >> 17) * 0x006cULL;
    return acc;
}

// FDE #1430 | PC: 0x094cfc | FDE: 0x0c93c0 | Size: 60 bytes
// Hàm FDE #1430 | Địa chỉ PC: 0x094cfc | Địa chỉ FDE: 0x0c93c0 | Kích thước: 60 bytes
//   0x094cfc: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x094d00: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x094d04: 910043FD  add      x29, sp, #0x10
//   0x094d08: F9400013  ldr      x19, [x0]
static inline uint64_t fde_func_1430_0x094cfc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x094cfcULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x0c93c0ULL;
    acc ^= (acc >> 17) * 0x003cULL;
    return acc;
}

// FDE #1431 | PC: 0x094d38 | FDE: 0x0c93e0 | Size: 88 bytes
// Hàm FDE #1431 | Địa chỉ PC: 0x094d38 | Địa chỉ FDE: 0x0c93e0 | Kích thước: 88 bytes
//   0x094d38: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x094d3c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x094d40: 910043FD  add      x29, sp, #0x10
//   0x094d44: F9400413  ldr      x19, [x0, #8]
static inline uint64_t fde_func_1431_0x094d38(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x094d38ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x0c93e0ULL;
    acc ^= (acc >> 17) * 0x0058ULL;
    return acc;
}

// FDE #1432 | PC: 0x094d90 | FDE: 0x0c9580 | Size: 200 bytes
// Hàm FDE #1432 | Địa chỉ PC: 0x094d90 | Địa chỉ FDE: 0x0c9580 | Kích thước: 200 bytes
//   0x094d90: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x094d94: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x094d98: 910043FD  add      x29, sp, #0x10
//   0x094d9c: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_1432_0x094d90(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x094d90ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x0c9580ULL;
    acc ^= (acc >> 17) * 0x00c8ULL;
    return acc;
}

// FDE #1433 | PC: 0x094e58 | FDE: 0x0c94a8 | Size: 20 bytes
// Hàm FDE #1433 | Địa chỉ PC: 0x094e58 | Địa chỉ FDE: 0x0c94a8 | Kích thước: 20 bytes
//   0x094e58: F9400001  ldr      x1, [x0]
//   0x094e5c: F900001F  str      xzr, [x0]
//   0x094e60: B4000041  cbz      x1, #0x94e68
//   0x094e64: 14003503  b        #0xa2270
static inline uint64_t fde_func_1433_0x094e58(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x094e58ULL ^ (static_cast<uint64_t>(0xf9400001ULL) << 13);
    acc = (acc + a1 + 0xf900001fULL) ^ 0x0c94a8ULL;
    acc ^= (acc >> 17) * 0x0014ULL;
    return acc;
}

// FDE #1434 | PC: 0x094e6c | FDE: 0x0c95a8 | Size: 256 bytes
// Hàm FDE #1434 | Địa chỉ PC: 0x094e6c | Địa chỉ FDE: 0x0c95a8 | Kích thước: 256 bytes
//   0x094e6c: D101C3FF  sub      sp, sp, #0x70
//   0x094e70: A90267FA  stp      x26, x25, [sp, #0x20]
//   0x094e74: A9035FF8  stp      x24, x23, [sp, #0x30]
//   0x094e78: A90457F6  stp      x22, x21, [sp, #0x40]
static inline uint64_t fde_func_1434_0x094e6c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x094e6cULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xa90267faULL) ^ 0x0c95a8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1435 | PC: 0x09500c | FDE: 0x0c95e0 | Size: 256 bytes
// Hàm FDE #1435 | Địa chỉ PC: 0x09500c | Địa chỉ FDE: 0x0c95e0 | Kích thước: 256 bytes
//   0x09500c: D10243FF  sub      sp, sp, #0x90
//   0x095010: F90023F9  str      x25, [sp, #0x40]
//   0x095014: A9055FF8  stp      x24, x23, [sp, #0x50]
//   0x095018: A90657F6  stp      x22, x21, [sp, #0x60]
static inline uint64_t fde_func_1435_0x09500c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x09500cULL ^ (static_cast<uint64_t>(0xd10243ffULL) << 13);
    acc = (acc + a1 + 0xf90023f9ULL) ^ 0x0c95e0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1436 | PC: 0x09518c | FDE: 0x0c9638 | Size: 216 bytes
// Hàm FDE #1436 | Địa chỉ PC: 0x09518c | Địa chỉ FDE: 0x0c9638 | Kích thước: 216 bytes
//   0x09518c: D10143FF  sub      sp, sp, #0x50
//   0x095190: F90013F5  str      x21, [sp, #0x20]
//   0x095194: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x095198: A9047BFD  stp      x29, x30, [sp, #0x40]
static inline uint64_t fde_func_1436_0x09518c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x09518cULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xf90013f5ULL) ^ 0x0c9638ULL;
    acc ^= (acc >> 17) * 0x00d8ULL;
    return acc;
}

// FDE #1437 | PC: 0x095264 | FDE: 0x0c94e0 | Size: 72 bytes
// Hàm FDE #1437 | Địa chỉ PC: 0x095264 | Địa chỉ FDE: 0x0c94e0 | Kích thước: 72 bytes
//   0x095264: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x095268: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x09526c: 910043FD  add      x29, sp, #0x10
//   0x095270: F9400013  ldr      x19, [x0]
static inline uint64_t fde_func_1437_0x095264(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x095264ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x0c94e0ULL;
    acc ^= (acc >> 17) * 0x0048ULL;
    return acc;
}

// FDE #1438 | PC: 0x0952ac | FDE: 0x0c9688 | Size: 216 bytes
// Hàm FDE #1438 | Địa chỉ PC: 0x0952ac | Địa chỉ FDE: 0x0c9688 | Kích thước: 216 bytes
//   0x0952ac: D10143FF  sub      sp, sp, #0x50
//   0x0952b0: F90013F5  str      x21, [sp, #0x20]
//   0x0952b4: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x0952b8: A9047BFD  stp      x29, x30, [sp, #0x40]
static inline uint64_t fde_func_1438_0x0952ac(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0952acULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xf90013f5ULL) ^ 0x0c9688ULL;
    acc ^= (acc >> 17) * 0x00d8ULL;
    return acc;
}

// FDE #1439 | PC: 0x095384 | FDE: 0x0c9520 | Size: 72 bytes
// Hàm FDE #1439 | Địa chỉ PC: 0x095384 | Địa chỉ FDE: 0x0c9520 | Kích thước: 72 bytes
//   0x095384: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x095388: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x09538c: 910043FD  add      x29, sp, #0x10
//   0x095390: F9400013  ldr      x19, [x0]
static inline uint64_t fde_func_1439_0x095384(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x095384ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x0c9520ULL;
    acc ^= (acc >> 17) * 0x0048ULL;
    return acc;
}

// FDE #1440 | PC: 0x0953cc | FDE: 0x0c96d8 | Size: 112 bytes
// Hàm FDE #1440 | Địa chỉ PC: 0x0953cc | Địa chỉ FDE: 0x0c96d8 | Kích thước: 112 bytes
//   0x0953cc: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0953d0: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0953d4: 910043FD  add      x29, sp, #0x10
//   0x0953d8: 52800500  mov      w0, #0x28
static inline uint64_t fde_func_1440_0x0953cc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0953ccULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x0c96d8ULL;
    acc ^= (acc >> 17) * 0x0070ULL;
    return acc;
}

// FDE #1441 | PC: 0x09543c | FDE: 0x0c9560 | Size: 72 bytes
// Hàm FDE #1441 | Địa chỉ PC: 0x09543c | Địa chỉ FDE: 0x0c9560 | Kích thước: 72 bytes
//   0x09543c: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x095440: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x095444: 910043FD  add      x29, sp, #0x10
//   0x095448: F9400013  ldr      x19, [x0]
static inline uint64_t fde_func_1441_0x09543c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x09543cULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x0c9560ULL;
    acc ^= (acc >> 17) * 0x0048ULL;
    return acc;
}

// FDE #1442 | PC: 0x095484 | FDE: 0x0c9758 | Size: 168 bytes
// Hàm FDE #1442 | Địa chỉ PC: 0x095484 | Địa chỉ FDE: 0x0c9758 | Kích thước: 168 bytes
//   0x095484: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x095488: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x09548c: 910043FD  add      x29, sp, #0x10
//   0x095490: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_1442_0x095484(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x095484ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x0c9758ULL;
    acc ^= (acc >> 17) * 0x00a8ULL;
    return acc;
}

// FDE #1443 | PC: 0x09552c | FDE: 0x0c9700 | Size: 20 bytes
// Hàm FDE #1443 | Địa chỉ PC: 0x09552c | Địa chỉ FDE: 0x0c9700 | Kích thước: 20 bytes
//   0x09552c: F9400001  ldr      x1, [x0]
//   0x095530: F900001F  str      xzr, [x0]
//   0x095534: B4000041  cbz      x1, #0x9553c
//   0x095538: 1400334E  b        #0xa2270
static inline uint64_t fde_func_1443_0x09552c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x09552cULL ^ (static_cast<uint64_t>(0xf9400001ULL) << 13);
    acc = (acc + a1 + 0xf900001fULL) ^ 0x0c9700ULL;
    acc ^= (acc >> 17) * 0x0014ULL;
    return acc;
}

// FDE #1444 | PC: 0x095540 | FDE: 0x0c9780 | Size: 248 bytes
// Hàm FDE #1444 | Địa chỉ PC: 0x095540 | Địa chỉ FDE: 0x0c9780 | Kích thước: 248 bytes
//   0x095540: D10143FF  sub      sp, sp, #0x50
//   0x095544: A9015FF8  stp      x24, x23, [sp, #0x10]
//   0x095548: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x09554c: A9034FF4  stp      x20, x19, [sp, #0x30]
static inline uint64_t fde_func_1444_0x095540(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x095540ULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xa9015ff8ULL) ^ 0x0c9780ULL;
    acc ^= (acc >> 17) * 0x00f8ULL;
    return acc;
}

// FDE #1445 | PC: 0x095638 | FDE: 0x0c97b0 | Size: 256 bytes
// Hàm FDE #1445 | Địa chỉ PC: 0x095638 | Địa chỉ FDE: 0x0c97b0 | Kích thước: 256 bytes
//   0x095638: D10203FF  sub      sp, sp, #0x80
//   0x09563c: A9045FF8  stp      x24, x23, [sp, #0x40]
//   0x095640: A90557F6  stp      x22, x21, [sp, #0x50]
//   0x095644: A9064FF4  stp      x20, x19, [sp, #0x60]
static inline uint64_t fde_func_1445_0x095638(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x095638ULL ^ (static_cast<uint64_t>(0xd10203ffULL) << 13);
    acc = (acc + a1 + 0xa9045ff8ULL) ^ 0x0c97b0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1446 | PC: 0x095764 | FDE: 0x0c9808 | Size: 112 bytes
// Hàm FDE #1446 | Địa chỉ PC: 0x095764 | Địa chỉ FDE: 0x0c9808 | Kích thước: 112 bytes
//   0x095764: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x095768: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x09576c: 910043FD  add      x29, sp, #0x10
//   0x095770: 52800400  mov      w0, #0x20
static inline uint64_t fde_func_1446_0x095764(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x095764ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x0c9808ULL;
    acc ^= (acc >> 17) * 0x0070ULL;
    return acc;
}

// FDE #1447 | PC: 0x0957d4 | FDE: 0x0c9738 | Size: 72 bytes
// Hàm FDE #1447 | Địa chỉ PC: 0x0957d4 | Địa chỉ FDE: 0x0c9738 | Kích thước: 72 bytes
//   0x0957d4: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x0957d8: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0957dc: 910043FD  add      x29, sp, #0x10
//   0x0957e0: F9400013  ldr      x19, [x0]
static inline uint64_t fde_func_1447_0x0957d4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0957d4ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x0c9738ULL;
    acc ^= (acc >> 17) * 0x0048ULL;
    return acc;
}

// FDE #1448 | PC: 0x09581c | FDE: 0x0c98c8 | Size: 136 bytes
// Hàm FDE #1448 | Địa chỉ PC: 0x09581c | Địa chỉ FDE: 0x0c98c8 | Kích thước: 136 bytes
//   0x09581c: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x095820: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x095824: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x095828: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1448_0x09581c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x09581cULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x0c98c8ULL;
    acc ^= (acc >> 17) * 0x0088ULL;
    return acc;
}

// FDE #1449 | PC: 0x0958a4 | FDE: 0x0c9830 | Size: 48 bytes
// Hàm FDE #1449 | Địa chỉ PC: 0x0958a4 | Địa chỉ FDE: 0x0c9830 | Kích thước: 48 bytes
//   0x0958a4: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x0958a8: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0958ac: 910043FD  add      x29, sp, #0x10
//   0x0958b0: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_1449_0x0958a4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0958a4ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x0c9830ULL;
    acc ^= (acc >> 17) * 0x0030ULL;
    return acc;
}

// FDE #1450 | PC: 0x0958d4 | FDE: 0x0c98f0 | Size: 196 bytes
// Hàm FDE #1450 | Địa chỉ PC: 0x0958d4 | Địa chỉ FDE: 0x0c98f0 | Kích thước: 196 bytes
//   0x0958d4: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x0958d8: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0958dc: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0958e0: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1450_0x0958d4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0958d4ULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x0c98f0ULL;
    acc ^= (acc >> 17) * 0x00c4ULL;
    return acc;
}

// FDE #1451 | PC: 0x095998 | FDE: 0x0c9850 | Size: 8 bytes
// Hàm FDE #1451 | Địa chỉ PC: 0x095998 | Địa chỉ FDE: 0x0c9850 | Kích thước: 8 bytes
//   0x095998: 91002000  add      x0, x0, #8
//   0x09599c: 14000001  b        #0x959a0
static inline uint64_t fde_func_1451_0x095998(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x095998ULL ^ (static_cast<uint64_t>(0x91002000ULL) << 13);
    acc = (acc + a1 + 0x14000001ULL) ^ 0x0c9850ULL;
    acc ^= (acc >> 17) * 0x0008ULL;
    return acc;
}

// FDE #1452 | PC: 0x0959a0 | FDE: 0x0c9918 | Size: 232 bytes
// Hàm FDE #1452 | Địa chỉ PC: 0x0959a0 | Địa chỉ FDE: 0x0c9918 | Kích thước: 232 bytes
//   0x0959a0: D10103FF  sub      sp, sp, #0x40
//   0x0959a4: F9000BF5  str      x21, [sp, #0x10]
//   0x0959a8: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x0959ac: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_1452_0x0959a0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0959a0ULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xf9000bf5ULL) ^ 0x0c9918ULL;
    acc ^= (acc >> 17) * 0x00e8ULL;
    return acc;
}

// FDE #1453 | PC: 0x095a88 | FDE: 0x0c9868 | Size: 40 bytes
// Hàm FDE #1453 | Địa chỉ PC: 0x095a88 | Địa chỉ FDE: 0x0c9868 | Kích thước: 40 bytes
//   0x095a88: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x095a8c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x095a90: 910043FD  add      x29, sp, #0x10
//   0x095a94: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_1453_0x095a88(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x095a88ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x0c9868ULL;
    acc ^= (acc >> 17) * 0x0028ULL;
    return acc;
}

// FDE #1454 | PC: 0x095ab0 | FDE: 0x0c9940 | Size: 256 bytes
// Hàm FDE #1454 | Địa chỉ PC: 0x095ab0 | Địa chỉ FDE: 0x0c9940 | Kích thước: 256 bytes
//   0x095ab0: D101C3FF  sub      sp, sp, #0x70
//   0x095ab4: A9035FF8  stp      x24, x23, [sp, #0x30]
//   0x095ab8: A90457F6  stp      x22, x21, [sp, #0x40]
//   0x095abc: A9054FF4  stp      x20, x19, [sp, #0x50]
static inline uint64_t fde_func_1454_0x095ab0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x095ab0ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xa9035ff8ULL) ^ 0x0c9940ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1455 | PC: 0x095c04 | FDE: 0x0c9998 | Size: 120 bytes
// Hàm FDE #1455 | Địa chỉ PC: 0x095c04 | Địa chỉ FDE: 0x0c9998 | Kích thước: 120 bytes
//   0x095c04: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x095c08: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x095c0c: 910043FD  add      x29, sp, #0x10
//   0x095c10: 52800500  mov      w0, #0x28
static inline uint64_t fde_func_1455_0x095c04(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x095c04ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x0c9998ULL;
    acc ^= (acc >> 17) * 0x0078ULL;
    return acc;
}

// FDE #1456 | PC: 0x095c7c | FDE: 0x0c98a8 | Size: 80 bytes
// Hàm FDE #1456 | Địa chỉ PC: 0x095c7c | Địa chỉ FDE: 0x0c98a8 | Kích thước: 80 bytes
//   0x095c7c: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x095c80: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x095c84: 910043FD  add      x29, sp, #0x10
//   0x095c88: F9400013  ldr      x19, [x0]
static inline uint64_t fde_func_1456_0x095c7c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x095c7cULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x0c98a8ULL;
    acc ^= (acc >> 17) * 0x0050ULL;
    return acc;
}

// FDE #1457 | PC: 0x095ccc | FDE: 0x0c99c0 | Size: 256 bytes
// Hàm FDE #1457 | Địa chỉ PC: 0x095ccc | Địa chỉ FDE: 0x0c99c0 | Kích thước: 256 bytes
//   0x095ccc: D10143FF  sub      sp, sp, #0x50
//   0x095cd0: F90013F5  str      x21, [sp, #0x20]
//   0x095cd4: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x095cd8: A9047BFD  stp      x29, x30, [sp, #0x40]
static inline uint64_t fde_func_1457_0x095ccc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x095cccULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xf90013f5ULL) ^ 0x0c99c0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1458 | PC: 0x095de8 | FDE: 0x0c99e8 | Size: 256 bytes
// Hàm FDE #1458 | Địa chỉ PC: 0x095de8 | Địa chỉ FDE: 0x0c99e8 | Kích thước: 256 bytes
//   0x095de8: A9BC5FF8  stp      x24, x23, [sp, #-0x40]!
//   0x095dec: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x095df0: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x095df4: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_1458_0x095de8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x095de8ULL ^ (static_cast<uint64_t>(0xa9bc5ff8ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x0c99e8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1459 | PC: 0x095ef8 | FDE: 0x0c9b30 | Size: 144 bytes
// Hàm FDE #1459 | Địa chỉ PC: 0x095ef8 | Địa chỉ FDE: 0x0c9b30 | Kích thước: 144 bytes
//   0x095ef8: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x095efc: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x095f00: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x095f04: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1459_0x095ef8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x095ef8ULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x0c9b30ULL;
    acc ^= (acc >> 17) * 0x0090ULL;
    return acc;
}

// FDE #1460 | PC: 0x095f88 | FDE: 0x0c9a18 | Size: 48 bytes
// Hàm FDE #1460 | Địa chỉ PC: 0x095f88 | Địa chỉ FDE: 0x0c9a18 | Kích thước: 48 bytes
//   0x095f88: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x095f8c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x095f90: 910043FD  add      x29, sp, #0x10
//   0x095f94: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_1460_0x095f88(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x095f88ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x0c9a18ULL;
    acc ^= (acc >> 17) * 0x0030ULL;
    return acc;
}

// FDE #1461 | PC: 0x095fb8 | FDE: 0x0c9b58 | Size: 196 bytes
// Hàm FDE #1461 | Địa chỉ PC: 0x095fb8 | Địa chỉ FDE: 0x0c9b58 | Kích thước: 196 bytes
//   0x095fb8: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x095fbc: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x095fc0: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x095fc4: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1461_0x095fb8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x095fb8ULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x0c9b58ULL;
    acc ^= (acc >> 17) * 0x00c4ULL;
    return acc;
}

// FDE #1462 | PC: 0x09607c | FDE: 0x0c9a38 | Size: 8 bytes
// Hàm FDE #1462 | Địa chỉ PC: 0x09607c | Địa chỉ FDE: 0x0c9a38 | Kích thước: 8 bytes
//   0x09607c: 91002000  add      x0, x0, #8
//   0x096080: 14000001  b        #0x96084
static inline uint64_t fde_func_1462_0x09607c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x09607cULL ^ (static_cast<uint64_t>(0x91002000ULL) << 13);
    acc = (acc + a1 + 0x14000001ULL) ^ 0x0c9a38ULL;
    acc ^= (acc >> 17) * 0x0008ULL;
    return acc;
}

// FDE #1463 | PC: 0x096084 | FDE: 0x0c9b80 | Size: 232 bytes
// Hàm FDE #1463 | Địa chỉ PC: 0x096084 | Địa chỉ FDE: 0x0c9b80 | Kích thước: 232 bytes
//   0x096084: D10103FF  sub      sp, sp, #0x40
//   0x096088: F9000BF5  str      x21, [sp, #0x10]
//   0x09608c: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x096090: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_1463_0x096084(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x096084ULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xf9000bf5ULL) ^ 0x0c9b80ULL;
    acc ^= (acc >> 17) * 0x00e8ULL;
    return acc;
}

// FDE #1464 | PC: 0x09616c | FDE: 0x0c9a50 | Size: 40 bytes
// Hàm FDE #1464 | Địa chỉ PC: 0x09616c | Địa chỉ FDE: 0x0c9a50 | Kích thước: 40 bytes
//   0x09616c: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x096170: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x096174: 910043FD  add      x29, sp, #0x10
//   0x096178: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_1464_0x09616c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x09616cULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x0c9a50ULL;
    acc ^= (acc >> 17) * 0x0028ULL;
    return acc;
}

// FDE #1465 | PC: 0x096194 | FDE: 0x0c9ba8 | Size: 256 bytes
// Hàm FDE #1465 | Địa chỉ PC: 0x096194 | Địa chỉ FDE: 0x0c9ba8 | Kích thước: 256 bytes
//   0x096194: D101C3FF  sub      sp, sp, #0x70
//   0x096198: A9035FF8  stp      x24, x23, [sp, #0x30]
//   0x09619c: A90457F6  stp      x22, x21, [sp, #0x40]
//   0x0961a0: A9054FF4  stp      x20, x19, [sp, #0x50]
static inline uint64_t fde_func_1465_0x096194(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x096194ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xa9035ff8ULL) ^ 0x0c9ba8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1466 | PC: 0x0962e8 | FDE: 0x0c9a70 | Size: 48 bytes [Java_com_lemon_nuro_ILogHandler_00024CppProxy_nativeDestroy]
// Hàm FDE #1466 | Địa chỉ PC: 0x0962e8 | Địa chỉ FDE: 0x0c9a70 | Kích thước: 48 bytes
//   0x0962e8: B4000162  cbz      x2, #0x96314
//   0x0962ec: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x0962f0: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0962f4: 910043FD  add      x29, sp, #0x10
static inline uint64_t fde_func_1466_0x0962e8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0962e8ULL ^ (static_cast<uint64_t>(0xb4000162ULL) << 13);
    acc = (acc + a1 + 0xf81e0ff3ULL) ^ 0x0c9a70ULL;
    acc ^= (acc >> 17) * 0x0030ULL;
    return acc;
}

// FDE #1467 | PC: 0x096318 | FDE: 0x0c9bd8 | Size: 252 bytes
// Hàm FDE #1467 | Địa chỉ PC: 0x096318 | Địa chỉ FDE: 0x0c9bd8 | Kích thước: 252 bytes
//   0x096318: D10103FF  sub      sp, sp, #0x40
//   0x09631c: F9000BF5  str      x21, [sp, #0x10]
//   0x096320: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x096324: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_1467_0x096318(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x096318ULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xf9000bf5ULL) ^ 0x0c9bd8ULL;
    acc ^= (acc >> 17) * 0x00fcULL;
    return acc;
}

// Shard 4 Dispatcher / Bộ điều phối phân mảnh 4
uint64_t execute_fde_shard_4(uint32_t fde_idx, uint64_t a0, uint64_t a1) {
    switch (fde_idx) {
        case 1101: return fde_func_1101_0x07b498(a0, a1);
        case 1102: return fde_func_1102_0x07b674(a0, a1);
        case 1103: return fde_func_1103_0x07b72c(a0, a1);
        case 1104: return fde_func_1104_0x07b93c(a0, a1);
        case 1105: return fde_func_1105_0x07bb78(a0, a1);
        case 1106: return fde_func_1106_0x07be24(a0, a1);
        case 1107: return fde_func_1107_0x07bf8c(a0, a1);
        case 1108: return fde_func_1108_0x07c188(a0, a1);
        case 1109: return fde_func_1109_0x07c208(a0, a1);
        case 1110: return fde_func_1110_0x07c3ac(a0, a1);
        case 1111: return fde_func_1111_0x07c4b0(a0, a1);
        case 1112: return fde_func_1112_0x07c528(a0, a1);
        case 1113: return fde_func_1113_0x07c5d0(a0, a1);
        case 1114: return fde_func_1114_0x07c678(a0, a1);
        case 1115: return fde_func_1115_0x07c6a8(a0, a1);
        case 1116: return fde_func_1116_0x07c6e0(a0, a1);
        case 1117: return fde_func_1117_0x07c6e8(a0, a1);
        case 1118: return fde_func_1118_0x07c6ec(a0, a1);
        case 1119: return fde_func_1119_0x07c788(a0, a1);
        case 1120: return fde_func_1120_0x07c7b4(a0, a1);
        case 1121: return fde_func_1121_0x07c808(a0, a1);
        case 1122: return fde_func_1122_0x07c90c(a0, a1);
        case 1123: return fde_func_1123_0x07c93c(a0, a1);
        case 1124: return fde_func_1124_0x07c974(a0, a1);
        case 1125: return fde_func_1125_0x07c980(a0, a1);
        case 1126: return fde_func_1126_0x07c984(a0, a1);
        case 1127: return fde_func_1127_0x07cc34(a0, a1);
        case 1128: return fde_func_1128_0x07cc8c(a0, a1);
        case 1129: return fde_func_1129_0x07cce4(a0, a1);
        case 1130: return fde_func_1130_0x07cd3c(a0, a1);
        case 1131: return fde_func_1131_0x07cd4c(a0, a1);
        case 1132: return fde_func_1132_0x07cf08(a0, a1);
        case 1133: return fde_func_1133_0x07cf2c(a0, a1);
        case 1134: return fde_func_1134_0x07d074(a0, a1);
        case 1135: return fde_func_1135_0x07d350(a0, a1);
        case 1136: return fde_func_1136_0x07d6b8(a0, a1);
        case 1137: return fde_func_1137_0x07d6c8(a0, a1);
        case 1138: return fde_func_1138_0x07d7d0(a0, a1);
        case 1139: return fde_func_1139_0x07dd2c(a0, a1);
        case 1140: return fde_func_1140_0x07dd34(a0, a1);
        case 1141: return fde_func_1141_0x07dd5c(a0, a1);
        case 1142: return fde_func_1142_0x07dd64(a0, a1);
        case 1143: return fde_func_1143_0x07dea0(a0, a1);
        case 1144: return fde_func_1144_0x07ded0(a0, a1);
        case 1145: return fde_func_1145_0x07df08(a0, a1);
        case 1146: return fde_func_1146_0x07df10(a0, a1);
        case 1147: return fde_func_1147_0x07df14(a0, a1);
        case 1148: return fde_func_1148_0x07e070(a0, a1);
        case 1149: return fde_func_1149_0x07e2ec(a0, a1);
        case 1150: return fde_func_1150_0x07ec30(a0, a1);
        case 1151: return fde_func_1151_0x07ee1c(a0, a1);
        case 1152: return fde_func_1152_0x07f024(a0, a1);
        case 1153: return fde_func_1153_0x07f1e4(a0, a1);
        case 1154: return fde_func_1154_0x07f288(a0, a1);
        case 1155: return fde_func_1155_0x07f4c0(a0, a1);
        case 1156: return fde_func_1156_0x07f5a4(a0, a1);
        case 1157: return fde_func_1157_0x07f72c(a0, a1);
        case 1158: return fde_func_1158_0x07f7d8(a0, a1);
        case 1159: return fde_func_1159_0x07faac(a0, a1);
        case 1160: return fde_func_1160_0x07fb28(a0, a1);
        case 1161: return fde_func_1161_0x07fb9c(a0, a1);
        case 1162: return fde_func_1162_0x07fbac(a0, a1);
        case 1163: return fde_func_1163_0x07fc18(a0, a1);
        case 1164: return fde_func_1164_0x07fc28(a0, a1);
        case 1165: return fde_func_1165_0x080060(a0, a1);
        case 1166: return fde_func_1166_0x080304(a0, a1);
        case 1167: return fde_func_1167_0x0806f0(a0, a1);
        case 1168: return fde_func_1168_0x0807f0(a0, a1);
        case 1169: return fde_func_1169_0x0808d4(a0, a1);
        case 1170: return fde_func_1170_0x0809e4(a0, a1);
        case 1171: return fde_func_1171_0x080c48(a0, a1);
        case 1172: return fde_func_1172_0x080e84(a0, a1);
        case 1173: return fde_func_1173_0x081068(a0, a1);
        case 1174: return fde_func_1174_0x081164(a0, a1);
        case 1175: return fde_func_1175_0x08135c(a0, a1);
        case 1176: return fde_func_1176_0x081e10(a0, a1);
        case 1177: return fde_func_1177_0x081ec4(a0, a1);
        case 1178: return fde_func_1178_0x0828e8(a0, a1);
        case 1179: return fde_func_1179_0x083154(a0, a1);
        case 1180: return fde_func_1180_0x0833b4(a0, a1);
        case 1181: return fde_func_1181_0x083448(a0, a1);
        case 1182: return fde_func_1182_0x0839f8(a0, a1);
        case 1183: return fde_func_1183_0x083f14(a0, a1);
        case 1184: return fde_func_1184_0x084644(a0, a1);
        case 1185: return fde_func_1185_0x084e68(a0, a1);
        case 1186: return fde_func_1186_0x084fc0(a0, a1);
        case 1187: return fde_func_1187_0x085068(a0, a1);
        case 1188: return fde_func_1188_0x0853ac(a0, a1);
        case 1189: return fde_func_1189_0x085490(a0, a1);
        case 1190: return fde_func_1190_0x085700(a0, a1);
        case 1191: return fde_func_1191_0x0857f8(a0, a1);
        case 1192: return fde_func_1192_0x0859b0(a0, a1);
        case 1193: return fde_func_1193_0x085a90(a0, a1);
        case 1194: return fde_func_1194_0x085b44(a0, a1);
        case 1195: return fde_func_1195_0x085c6c(a0, a1);
        case 1196: return fde_func_1196_0x085ed4(a0, a1);
        case 1197: return fde_func_1197_0x0860a0(a0, a1);
        case 1198: return fde_func_1198_0x086160(a0, a1);
        case 1199: return fde_func_1199_0x0862ac(a0, a1);
        case 1200: return fde_func_1200_0x0863f8(a0, a1);
        case 1201: return fde_func_1201_0x086640(a0, a1);
        case 1202: return fde_func_1202_0x0867f8(a0, a1);
        case 1203: return fde_func_1203_0x086a00(a0, a1);
        case 1204: return fde_func_1204_0x086d18(a0, a1);
        case 1205: return fde_func_1205_0x086dd0(a0, a1);
        case 1206: return fde_func_1206_0x086e90(a0, a1);
        case 1207: return fde_func_1207_0x086e9c(a0, a1);
        case 1208: return fde_func_1208_0x086ea0(a0, a1);
        case 1209: return fde_func_1209_0x087014(a0, a1);
        case 1210: return fde_func_1210_0x087188(a0, a1);
        case 1211: return fde_func_1211_0x0872f0(a0, a1);
        case 1212: return fde_func_1212_0x087634(a0, a1);
        case 1213: return fde_func_1213_0x087718(a0, a1);
        case 1214: return fde_func_1214_0x087988(a0, a1);
        case 1215: return fde_func_1215_0x087c08(a0, a1);
        case 1216: return fde_func_1216_0x087cec(a0, a1);
        case 1217: return fde_func_1217_0x087e74(a0, a1);
        case 1218: return fde_func_1218_0x087fbc(a0, a1);
        case 1219: return fde_func_1219_0x0880f0(a0, a1);
        case 1220: return fde_func_1220_0x088250(a0, a1);
        case 1221: return fde_func_1221_0x0882dc(a0, a1);
        case 1222: return fde_func_1222_0x08843c(a0, a1);
        case 1223: return fde_func_1223_0x08857c(a0, a1);
        case 1224: return fde_func_1224_0x088870(a0, a1);
        case 1225: return fde_func_1225_0x088d40(a0, a1);
        case 1226: return fde_func_1226_0x0891a4(a0, a1);
        case 1227: return fde_func_1227_0x089970(a0, a1);
        case 1228: return fde_func_1228_0x089b04(a0, a1);
        case 1229: return fde_func_1229_0x089d08(a0, a1);
        case 1230: return fde_func_1230_0x089e0c(a0, a1);
        case 1231: return fde_func_1231_0x089f64(a0, a1);
        case 1232: return fde_func_1232_0x08a130(a0, a1);
        case 1233: return fde_func_1233_0x08a34c(a0, a1);
        case 1234: return fde_func_1234_0x08a5bc(a0, a1);
        case 1235: return fde_func_1235_0x08aa20(a0, a1);
        case 1236: return fde_func_1236_0x08adec(a0, a1);
        case 1237: return fde_func_1237_0x08b090(a0, a1);
        case 1238: return fde_func_1238_0x08b218(a0, a1);
        case 1239: return fde_func_1239_0x08b22c(a0, a1);
        case 1240: return fde_func_1240_0x08b540(a0, a1);
        case 1241: return fde_func_1241_0x08b5dc(a0, a1);
        case 1242: return fde_func_1242_0x08bb4c(a0, a1);
        case 1243: return fde_func_1243_0x08bc28(a0, a1);
        case 1244: return fde_func_1244_0x08bc70(a0, a1);
        case 1245: return fde_func_1245_0x08bd48(a0, a1);
        case 1246: return fde_func_1246_0x08bd90(a0, a1);
        case 1247: return fde_func_1247_0x08be68(a0, a1);
        case 1248: return fde_func_1248_0x08beb0(a0, a1);
        case 1249: return fde_func_1249_0x08bf20(a0, a1);
        case 1250: return fde_func_1250_0x08bf68(a0, a1);
        case 1251: return fde_func_1251_0x08c088(a0, a1);
        case 1252: return fde_func_1252_0x08c0d0(a0, a1);
        case 1253: return fde_func_1253_0x08c0d4(a0, a1);
        case 1254: return fde_func_1254_0x08c10c(a0, a1);
        case 1255: return fde_func_1255_0x08c124(a0, a1);
        case 1256: return fde_func_1256_0x08c128(a0, a1);
        case 1257: return fde_func_1257_0x08c12c(a0, a1);
        case 1258: return fde_func_1258_0x08c134(a0, a1);
        case 1259: return fde_func_1259_0x08c150(a0, a1);
        case 1260: return fde_func_1260_0x08c15c(a0, a1);
        case 1261: return fde_func_1261_0x08c160(a0, a1);
        case 1262: return fde_func_1262_0x08c294(a0, a1);
        case 1263: return fde_func_1263_0x08c330(a0, a1);
        case 1264: return fde_func_1264_0x08c750(a0, a1);
        case 1265: return fde_func_1265_0x08c7ec(a0, a1);
        case 1266: return fde_func_1266_0x08c888(a0, a1);
        case 1267: return fde_func_1267_0x08cb64(a0, a1);
        case 1268: return fde_func_1268_0x08cbec(a0, a1);
        case 1269: return fde_func_1269_0x08cc00(a0, a1);
        case 1270: return fde_func_1270_0x08ccd8(a0, a1);
        case 1271: return fde_func_1271_0x08cda4(a0, a1);
        case 1272: return fde_func_1272_0x08ce78(a0, a1);
        case 1273: return fde_func_1273_0x08cec0(a0, a1);
        case 1274: return fde_func_1274_0x08cfa8(a0, a1);
        case 1275: return fde_func_1275_0x08cfbc(a0, a1);
        case 1276: return fde_func_1276_0x08d1e0(a0, a1);
        case 1277: return fde_func_1277_0x08d660(a0, a1);
        case 1278: return fde_func_1278_0x08d6d0(a0, a1);
        case 1279: return fde_func_1279_0x08d718(a0, a1);
        case 1280: return fde_func_1280_0x08d84c(a0, a1);
        case 1281: return fde_func_1281_0x08d980(a0, a1);
        case 1282: return fde_func_1282_0x08db68(a0, a1);
        case 1283: return fde_func_1283_0x08de40(a0, a1);
        case 1284: return fde_func_1284_0x08e0b4(a0, a1);
        case 1285: return fde_func_1285_0x08e0c0(a0, a1);
        case 1286: return fde_func_1286_0x08e0c4(a0, a1);
        case 1287: return fde_func_1287_0x08e0f4(a0, a1);
        case 1288: return fde_func_1288_0x08e1f0(a0, a1);
        case 1289: return fde_func_1289_0x08e328(a0, a1);
        case 1290: return fde_func_1290_0x08e4e4(a0, a1);
        case 1291: return fde_func_1291_0x08e53c(a0, a1);
        case 1292: return fde_func_1292_0x08e610(a0, a1);
        case 1293: return fde_func_1293_0x08e720(a0, a1);
        case 1294: return fde_func_1294_0x08e7f4(a0, a1);
        case 1295: return fde_func_1295_0x08e8c8(a0, a1);
        case 1296: return fde_func_1296_0x08e99c(a0, a1);
        case 1297: return fde_func_1297_0x08eac4(a0, a1);
        case 1298: return fde_func_1298_0x08eb3c(a0, a1);
        case 1299: return fde_func_1299_0x08ec0c(a0, a1);
        case 1300: return fde_func_1300_0x08ec6c(a0, a1);
        case 1301: return fde_func_1301_0x08ecc8(a0, a1);
        case 1302: return fde_func_1302_0x08edac(a0, a1);
        case 1303: return fde_func_1303_0x08ee08(a0, a1);
        case 1304: return fde_func_1304_0x08ef80(a0, a1);
        case 1305: return fde_func_1305_0x08efec(a0, a1);
        case 1306: return fde_func_1306_0x08f028(a0, a1);
        case 1307: return fde_func_1307_0x08f08c(a0, a1);
        case 1308: return fde_func_1308_0x08f0c8(a0, a1);
        case 1309: return fde_func_1309_0x08f12c(a0, a1);
        case 1310: return fde_func_1310_0x08f168(a0, a1);
        case 1311: return fde_func_1311_0x08f1cc(a0, a1);
        case 1312: return fde_func_1312_0x08f208(a0, a1);
        case 1313: return fde_func_1313_0x08f2e0(a0, a1);
        case 1314: return fde_func_1314_0x08f328(a0, a1);
        case 1315: return fde_func_1315_0x08f3fc(a0, a1);
        case 1316: return fde_func_1316_0x08f444(a0, a1);
        case 1317: return fde_func_1317_0x08f5c4(a0, a1);
        case 1318: return fde_func_1318_0x08f690(a0, a1);
        case 1319: return fde_func_1319_0x08f6c0(a0, a1);
        case 1320: return fde_func_1320_0x08f6f8(a0, a1);
        case 1321: return fde_func_1321_0x08f700(a0, a1);
        case 1322: return fde_func_1322_0x08f704(a0, a1);
        case 1323: return fde_func_1323_0x08f884(a0, a1);
        case 1324: return fde_func_1324_0x08f950(a0, a1);
        case 1325: return fde_func_1325_0x08f980(a0, a1);
        case 1326: return fde_func_1326_0x08f9b8(a0, a1);
        case 1327: return fde_func_1327_0x08f9c0(a0, a1);
        case 1328: return fde_func_1328_0x08f9c4(a0, a1);
        case 1329: return fde_func_1329_0x08fae0(a0, a1);
        case 1330: return fde_func_1330_0x08fbf0(a0, a1);
        case 1331: return fde_func_1331_0x08fcec(a0, a1);
        case 1332: return fde_func_1332_0x08fd44(a0, a1);
        case 1333: return fde_func_1333_0x08fd9c(a0, a1);
        case 1334: return fde_func_1334_0x08fe84(a0, a1);
        case 1335: return fde_func_1335_0x08fe98(a0, a1);
        case 1336: return fde_func_1336_0x09005c(a0, a1);
        case 1337: return fde_func_1337_0x090254(a0, a1);
        case 1338: return fde_func_1338_0x0902c4(a0, a1);
        case 1339: return fde_func_1339_0x09030c(a0, a1);
        case 1340: return fde_func_1340_0x090318(a0, a1);
        case 1341: return fde_func_1341_0x09031c(a0, a1);
        case 1342: return fde_func_1342_0x09034c(a0, a1);
        case 1343: return fde_func_1343_0x090448(a0, a1);
        case 1344: return fde_func_1344_0x090574(a0, a1);
        case 1345: return fde_func_1345_0x0905cc(a0, a1);
        case 1346: return fde_func_1346_0x09069c(a0, a1);
        case 1347: return fde_func_1347_0x090870(a0, a1);
        case 1348: return fde_func_1348_0x090940(a0, a1);
        case 1349: return fde_func_1349_0x090ae4(a0, a1);
        case 1350: return fde_func_1350_0x090c18(a0, a1);
        case 1351: return fde_func_1351_0x090cf4(a0, a1);
        case 1352: return fde_func_1352_0x090d60(a0, a1);
        case 1353: return fde_func_1353_0x090d9c(a0, a1);
        case 1354: return fde_func_1354_0x090eb8(a0, a1);
        case 1355: return fde_func_1355_0x090fc8(a0, a1);
        case 1356: return fde_func_1356_0x0910e4(a0, a1);
        case 1357: return fde_func_1357_0x0911f4(a0, a1);
        case 1358: return fde_func_1358_0x0912dc(a0, a1);
        case 1359: return fde_func_1359_0x0912f0(a0, a1);
        case 1360: return fde_func_1360_0x091468(a0, a1);
        case 1361: return fde_func_1361_0x09163c(a0, a1);
        case 1362: return fde_func_1362_0x0916ac(a0, a1);
        case 1363: return fde_func_1363_0x0916f4(a0, a1);
        case 1364: return fde_func_1364_0x091844(a0, a1);
        case 1365: return fde_func_1365_0x091874(a0, a1);
        case 1366: return fde_func_1366_0x091938(a0, a1);
        case 1367: return fde_func_1367_0x091940(a0, a1);
        case 1368: return fde_func_1368_0x091a28(a0, a1);
        case 1369: return fde_func_1369_0x091a50(a0, a1);
        case 1370: return fde_func_1370_0x091ba4(a0, a1);
        case 1371: return fde_func_1371_0x091c40(a0, a1);
        case 1372: return fde_func_1372_0x091d40(a0, a1);
        case 1373: return fde_func_1373_0x091e40(a0, a1);
        case 1374: return fde_func_1374_0x091f40(a0, a1);
        case 1375: return fde_func_1375_0x092104(a0, a1);
        case 1376: return fde_func_1376_0x09226c(a0, a1);
        case 1377: return fde_func_1377_0x0923b8(a0, a1);
        case 1378: return fde_func_1378_0x0923e8(a0, a1);
        case 1379: return fde_func_1379_0x0924e4(a0, a1);
        case 1380: return fde_func_1380_0x0925d0(a0, a1);
        case 1381: return fde_func_1381_0x092698(a0, a1);
        case 1382: return fde_func_1382_0x092760(a0, a1);
        case 1383: return fde_func_1383_0x092880(a0, a1);
        case 1384: return fde_func_1384_0x092a0c(a0, a1);
        case 1385: return fde_func_1385_0x092b50(a0, a1);
        case 1386: return fde_func_1386_0x092c6c(a0, a1);
        case 1387: return fde_func_1387_0x092d44(a0, a1);
        case 1388: return fde_func_1388_0x092d8c(a0, a1);
        case 1389: return fde_func_1389_0x092e64(a0, a1);
        case 1390: return fde_func_1390_0x092eac(a0, a1);
        case 1391: return fde_func_1391_0x092f84(a0, a1);
        case 1392: return fde_func_1392_0x092fcc(a0, a1);
        case 1393: return fde_func_1393_0x093024(a0, a1);
        case 1394: return fde_func_1394_0x093038(a0, a1);
        case 1395: return fde_func_1395_0x0931c0(a0, a1);
        case 1396: return fde_func_1396_0x0931d4(a0, a1);
        case 1397: return fde_func_1397_0x093688(a0, a1);
        case 1398: return fde_func_1398_0x093b60(a0, a1);
        case 1399: return fde_func_1399_0x093bd0(a0, a1);
        case 1400: return fde_func_1400_0x093c18(a0, a1);
        case 1401: return fde_func_1401_0x093cec(a0, a1);
        case 1402: return fde_func_1402_0x093d34(a0, a1);
        case 1403: return fde_func_1403_0x093dd0(a0, a1);
        case 1404: return fde_func_1404_0x093dec(a0, a1);
        case 1405: return fde_func_1405_0x093df0(a0, a1);
        case 1406: return fde_func_1406_0x093f18(a0, a1);
        case 1407: return fde_func_1407_0x093f2c(a0, a1);
        case 1408: return fde_func_1408_0x09414c(a0, a1);
        case 1409: return fde_func_1409_0x0943a0(a0, a1);
        case 1410: return fde_func_1410_0x094478(a0, a1);
        case 1411: return fde_func_1411_0x0944c0(a0, a1);
        case 1412: return fde_func_1412_0x094530(a0, a1);
        case 1413: return fde_func_1413_0x094578(a0, a1);
        case 1414: return fde_func_1414_0x094584(a0, a1);
        case 1415: return fde_func_1415_0x094588(a0, a1);
        case 1416: return fde_func_1416_0x0945b8(a0, a1);
        case 1417: return fde_func_1417_0x0946b4(a0, a1);
        case 1418: return fde_func_1418_0x094714(a0, a1);
        case 1419: return fde_func_1419_0x094840(a0, a1);
        case 1420: return fde_func_1420_0x094918(a0, a1);
        case 1421: return fde_func_1421_0x094974(a0, a1);
        case 1422: return fde_func_1422_0x0949e0(a0, a1);
        case 1423: return fde_func_1423_0x094a1c(a0, a1);
        case 1424: return fde_func_1424_0x094a74(a0, a1);
        case 1425: return fde_func_1425_0x094a80(a0, a1);
        case 1426: return fde_func_1426_0x094a84(a0, a1);
        case 1427: return fde_func_1427_0x094ab4(a0, a1);
        case 1428: return fde_func_1428_0x094bb0(a0, a1);
        case 1429: return fde_func_1429_0x094c90(a0, a1);
        case 1430: return fde_func_1430_0x094cfc(a0, a1);
        case 1431: return fde_func_1431_0x094d38(a0, a1);
        case 1432: return fde_func_1432_0x094d90(a0, a1);
        case 1433: return fde_func_1433_0x094e58(a0, a1);
        case 1434: return fde_func_1434_0x094e6c(a0, a1);
        case 1435: return fde_func_1435_0x09500c(a0, a1);
        case 1436: return fde_func_1436_0x09518c(a0, a1);
        case 1437: return fde_func_1437_0x095264(a0, a1);
        case 1438: return fde_func_1438_0x0952ac(a0, a1);
        case 1439: return fde_func_1439_0x095384(a0, a1);
        case 1440: return fde_func_1440_0x0953cc(a0, a1);
        case 1441: return fde_func_1441_0x09543c(a0, a1);
        case 1442: return fde_func_1442_0x095484(a0, a1);
        case 1443: return fde_func_1443_0x09552c(a0, a1);
        case 1444: return fde_func_1444_0x095540(a0, a1);
        case 1445: return fde_func_1445_0x095638(a0, a1);
        case 1446: return fde_func_1446_0x095764(a0, a1);
        case 1447: return fde_func_1447_0x0957d4(a0, a1);
        case 1448: return fde_func_1448_0x09581c(a0, a1);
        case 1449: return fde_func_1449_0x0958a4(a0, a1);
        case 1450: return fde_func_1450_0x0958d4(a0, a1);
        case 1451: return fde_func_1451_0x095998(a0, a1);
        case 1452: return fde_func_1452_0x0959a0(a0, a1);
        case 1453: return fde_func_1453_0x095a88(a0, a1);
        case 1454: return fde_func_1454_0x095ab0(a0, a1);
        case 1455: return fde_func_1455_0x095c04(a0, a1);
        case 1456: return fde_func_1456_0x095c7c(a0, a1);
        case 1457: return fde_func_1457_0x095ccc(a0, a1);
        case 1458: return fde_func_1458_0x095de8(a0, a1);
        case 1459: return fde_func_1459_0x095ef8(a0, a1);
        case 1460: return fde_func_1460_0x095f88(a0, a1);
        case 1461: return fde_func_1461_0x095fb8(a0, a1);
        case 1462: return fde_func_1462_0x09607c(a0, a1);
        case 1463: return fde_func_1463_0x096084(a0, a1);
        case 1464: return fde_func_1464_0x09616c(a0, a1);
        case 1465: return fde_func_1465_0x096194(a0, a1);
        case 1466: return fde_func_1466_0x0962e8(a0, a1);
        case 1467: return fde_func_1467_0x096318(a0, a1);
        default: return 0ULL;
    }
}

} // namespace nuro