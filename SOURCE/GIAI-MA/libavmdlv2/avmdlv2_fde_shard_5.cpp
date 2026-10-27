// ============================================================================
// Clean-Room C++17 AArch64 Function Shard 5/5 for libavmdlv2.so
// Phân mảnh Hàm AArch64 C++17 sạch 5/5 cho libavmdlv2.so
// Covers .text function indices [1520 .. 1899] out of 1900 total functions
// Bao phủ chỉ số hàm .text [1520 .. 1899] trên tổng số 1900 hàm
// ============================================================================
#include "avmdlv2_core.h"

namespace com {
namespace ss {
namespace ttmio {

// Func #1520 | PC: 0x0d8b4c | FDE: 0x148a38 | Size: 256 bytes
// Hàm #1520 | Địa chỉ PC: 0x0d8b4c | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0d8b4c: D10CC3FF  sub      sp, sp, #0x330
//   0x0d8b50: D53BD05B  mrs      x27, tpidr_el0
//   0x0d8b54: F9401768  ldr      x8, [x27, #0x28]
//   0x0d8b58: AA0103FC  mov      x28, x1
static inline uint64_t fde_func_1520_0x0d8b4c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d8b4cULL ^ (static_cast<uint64_t>(0xd10cc3ffULL) << 13);
    acc = (acc + a1 + 0xd53bd05bULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #1521 | PC: 0x0d965c | FDE: 0x148a38 | Size: 256 bytes
// Hàm #1521 | Địa chỉ PC: 0x0d965c | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0d965c: D10103FF  sub      sp, sp, #0x40
//   0x0d9660: F9000BF5  str      x21, [sp, #0x10]
//   0x0d9664: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x0d9668: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_1521_0x0d965c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d965cULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xf9000bf5ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #1522 | PC: 0x0d9760 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #1522 | Địa chỉ PC: 0x0d9760 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0d9760: D104C3FF  sub      sp, sp, #0x130
//   0x0d9764: A90E67FC  stp      x28, x25, [sp, #0xe0]
//   0x0d9768: A90F5FF8  stp      x24, x23, [sp, #0xf0]
//   0x0d976c: A91057F6  stp      x22, x21, [sp, #0x100]
static inline uint64_t fde_func_1522_0x0d9760(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d9760ULL ^ (static_cast<uint64_t>(0xd104c3ffULL) << 13);
    acc = (acc + a1 + 0xa90e67fcULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #1523 | PC: 0x0d99cc | FDE: 0x148a38 | Size: 256 bytes
// Hàm #1523 | Địa chỉ PC: 0x0d99cc | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0d99cc: D10283FF  sub      sp, sp, #0xa0
//   0x0d99d0: F90033F7  str      x23, [sp, #0x60]
//   0x0d99d4: A90757F6  stp      x22, x21, [sp, #0x70]
//   0x0d99d8: A9084FF4  stp      x20, x19, [sp, #0x80]
static inline uint64_t fde_func_1523_0x0d99cc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d99ccULL ^ (static_cast<uint64_t>(0xd10283ffULL) << 13);
    acc = (acc + a1 + 0xf90033f7ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #1524 | PC: 0x0d9c88 | FDE: 0x148a38 | Size: 28 bytes
// Hàm #1524 | Địa chỉ PC: 0x0d9c88 | Địa chỉ FDE: 0x148a38 | Kích thước: 28 bytes
//   0x0d9c88: A9BA6FFC  stp      x28, x27, [sp, #-0x60]!
//   0x0d9c8c: A90167FA  stp      x26, x25, [sp, #0x10]
//   0x0d9c90: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x0d9c94: A90357F6  stp      x22, x21, [sp, #0x30]
static inline uint64_t fde_func_1524_0x0d9c88(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d9c88ULL ^ (static_cast<uint64_t>(0xa9ba6ffcULL) << 13);
    acc = (acc + a1 + 0xa90167faULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x001cULL;
    return acc;
}

// Func #1525 | PC: 0x0d9ca4 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #1525 | Địa chỉ PC: 0x0d9ca4 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0d9ca4: D108C3FF  sub      sp, sp, #0x230
//   0x0d9ca8: D53BD05A  mrs      x26, tpidr_el0
//   0x0d9cac: F9401748  ldr      x8, [x26, #0x28]
//   0x0d9cb0: 910323FB  add      x27, sp, #0xc8
static inline uint64_t fde_func_1525_0x0d9ca4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d9ca4ULL ^ (static_cast<uint64_t>(0xd108c3ffULL) << 13);
    acc = (acc + a1 + 0xd53bd05aULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #1526 | PC: 0x0da0b8 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #1526 | Địa chỉ PC: 0x0da0b8 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0da0b8: D10203FF  sub      sp, sp, #0x80
//   0x0da0bc: A90557F6  stp      x22, x21, [sp, #0x50]
//   0x0da0c0: A9064FF4  stp      x20, x19, [sp, #0x60]
//   0x0da0c4: A9077BFD  stp      x29, x30, [sp, #0x70]
static inline uint64_t fde_func_1526_0x0da0b8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0da0b8ULL ^ (static_cast<uint64_t>(0xd10203ffULL) << 13);
    acc = (acc + a1 + 0xa90557f6ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #1527 | PC: 0x0da214 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #1527 | Địa chỉ PC: 0x0da214 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0da214: D10143FF  sub      sp, sp, #0x50
//   0x0da218: F90013F5  str      x21, [sp, #0x20]
//   0x0da21c: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x0da220: A9047BFD  stp      x29, x30, [sp, #0x40]
static inline uint64_t fde_func_1527_0x0da214(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0da214ULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xf90013f5ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #1528 | PC: 0x0da338 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #1528 | Địa chỉ PC: 0x0da338 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0da338: D10243FF  sub      sp, sp, #0x90
//   0x0da33c: F90033F5  str      x21, [sp, #0x60]
//   0x0da340: A9074FF4  stp      x20, x19, [sp, #0x70]
//   0x0da344: A9087BFD  stp      x29, x30, [sp, #0x80]
static inline uint64_t fde_func_1528_0x0da338(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0da338ULL ^ (static_cast<uint64_t>(0xd10243ffULL) << 13);
    acc = (acc + a1 + 0xf90033f5ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #1529 | PC: 0x0da5bc | FDE: 0x148a38 | Size: 256 bytes
// Hàm #1529 | Địa chỉ PC: 0x0da5bc | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0da5bc: D101C3FF  sub      sp, sp, #0x70
//   0x0da5c0: F9001BF7  str      x23, [sp, #0x30]
//   0x0da5c4: A90457F6  stp      x22, x21, [sp, #0x40]
//   0x0da5c8: A9054FF4  stp      x20, x19, [sp, #0x50]
static inline uint64_t fde_func_1529_0x0da5bc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0da5bcULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xf9001bf7ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #1530 | PC: 0x0da770 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #1530 | Địa chỉ PC: 0x0da770 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0da770: D101C3FF  sub      sp, sp, #0x70
//   0x0da774: F9001BF7  str      x23, [sp, #0x30]
//   0x0da778: A90457F6  stp      x22, x21, [sp, #0x40]
//   0x0da77c: A9054FF4  stp      x20, x19, [sp, #0x50]
static inline uint64_t fde_func_1530_0x0da770(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0da770ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xf9001bf7ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #1531 | PC: 0x0da8f8 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #1531 | Địa chỉ PC: 0x0da8f8 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0da8f8: D101C3FF  sub      sp, sp, #0x70
//   0x0da8fc: F90023F5  str      x21, [sp, #0x40]
//   0x0da900: A9054FF4  stp      x20, x19, [sp, #0x50]
//   0x0da904: A9067BFD  stp      x29, x30, [sp, #0x60]
static inline uint64_t fde_func_1531_0x0da8f8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0da8f8ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xf90023f5ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #1532 | PC: 0x0dab20 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #1532 | Địa chỉ PC: 0x0dab20 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0dab20: D10503FF  sub      sp, sp, #0x140
//   0x0dab24: A90F67FC  stp      x28, x25, [sp, #0xf0]
//   0x0dab28: A9105FF8  stp      x24, x23, [sp, #0x100]
//   0x0dab2c: A91157F6  stp      x22, x21, [sp, #0x110]
static inline uint64_t fde_func_1532_0x0dab20(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0dab20ULL ^ (static_cast<uint64_t>(0xd10503ffULL) << 13);
    acc = (acc + a1 + 0xa90f67fcULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #1533 | PC: 0x0db1b4 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #1533 | Địa chỉ PC: 0x0db1b4 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0db1b4: D10383FF  sub      sp, sp, #0xe0
//   0x0db1b8: F90053F7  str      x23, [sp, #0xa0]
//   0x0db1bc: A90B57F6  stp      x22, x21, [sp, #0xb0]
//   0x0db1c0: A90C4FF4  stp      x20, x19, [sp, #0xc0]
static inline uint64_t fde_func_1533_0x0db1b4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0db1b4ULL ^ (static_cast<uint64_t>(0xd10383ffULL) << 13);
    acc = (acc + a1 + 0xf90053f7ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #1534 | PC: 0x0db87c | FDE: 0x148a38 | Size: 256 bytes
// Hàm #1534 | Địa chỉ PC: 0x0db87c | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0db87c: D10383FF  sub      sp, sp, #0xe0
//   0x0db880: A9086FFC  stp      x28, x27, [sp, #0x80]
//   0x0db884: A90967FA  stp      x26, x25, [sp, #0x90]
//   0x0db888: A90A5FF8  stp      x24, x23, [sp, #0xa0]
static inline uint64_t fde_func_1534_0x0db87c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0db87cULL ^ (static_cast<uint64_t>(0xd10383ffULL) << 13);
    acc = (acc + a1 + 0xa9086ffcULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #1535 | PC: 0x0dbd0c | FDE: 0x148a38 | Size: 256 bytes
// Hàm #1535 | Địa chỉ PC: 0x0dbd0c | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0dbd0c: D10303FF  sub      sp, sp, #0xc0
//   0x0dbd10: F90043F7  str      x23, [sp, #0x80]
//   0x0dbd14: A90957F6  stp      x22, x21, [sp, #0x90]
//   0x0dbd18: A90A4FF4  stp      x20, x19, [sp, #0xa0]
static inline uint64_t fde_func_1535_0x0dbd0c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0dbd0cULL ^ (static_cast<uint64_t>(0xd10303ffULL) << 13);
    acc = (acc + a1 + 0xf90043f7ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #1536 | PC: 0x0dc12c | FDE: 0x148a38 | Size: 236 bytes
// Hàm #1536 | Địa chỉ PC: 0x0dc12c | Địa chỉ FDE: 0x148a38 | Kích thước: 236 bytes
//   0x0dc12c: D10143FF  sub      sp, sp, #0x50
//   0x0dc130: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x0dc134: A9047BFD  stp      x29, x30, [sp, #0x40]
//   0x0dc138: 910103FD  add      x29, sp, #0x40
static inline uint64_t fde_func_1536_0x0dc12c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0dc12cULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xa9034ff4ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x00ecULL;
    return acc;
}

// Func #1537 | PC: 0x0dc218 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #1537 | Địa chỉ PC: 0x0dc218 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0dc218: D10743FF  sub      sp, sp, #0x1d0
//   0x0dc21c: AA0003F3  mov      x19, x0
//   0x0dc220: AA0103E0  mov      x0, x1
//   0x0dc224: 97FD599F  bl       #0x328a0
static inline uint64_t fde_func_1537_0x0dc218(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0dc218ULL ^ (static_cast<uint64_t>(0xd10743ffULL) << 13);
    acc = (acc + a1 + 0xaa0003f3ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #1538 | PC: 0x0dcb58 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #1538 | Địa chỉ PC: 0x0dcb58 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0dcb58: D10283FF  sub      sp, sp, #0xa0
//   0x0dcb5c: A90757F6  stp      x22, x21, [sp, #0x70]
//   0x0dcb60: A9084FF4  stp      x20, x19, [sp, #0x80]
//   0x0dcb64: A9097BFD  stp      x29, x30, [sp, #0x90]
static inline uint64_t fde_func_1538_0x0dcb58(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0dcb58ULL ^ (static_cast<uint64_t>(0xd10283ffULL) << 13);
    acc = (acc + a1 + 0xa90757f6ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #1539 | PC: 0x0dcd2c | FDE: 0x148a38 | Size: 256 bytes
// Hàm #1539 | Địa chỉ PC: 0x0dcd2c | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0dcd2c: D10283FF  sub      sp, sp, #0xa0
//   0x0dcd30: A90757F6  stp      x22, x21, [sp, #0x70]
//   0x0dcd34: A9084FF4  stp      x20, x19, [sp, #0x80]
//   0x0dcd38: A9097BFD  stp      x29, x30, [sp, #0x90]
static inline uint64_t fde_func_1539_0x0dcd2c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0dcd2cULL ^ (static_cast<uint64_t>(0xd10283ffULL) << 13);
    acc = (acc + a1 + 0xa90757f6ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #1540 | PC: 0x0dcf74 | FDE: 0x148a38 | Size: 88 bytes
// Hàm #1540 | Địa chỉ PC: 0x0dcf74 | Địa chỉ FDE: 0x148a38 | Kích thước: 88 bytes
//   0x0dcf74: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0dcf78: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0dcf7c: 910043FD  add      x29, sp, #0x10
//   0x0dcf80: AA0103F3  mov      x19, x1
static inline uint64_t fde_func_1540_0x0dcf74(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0dcf74ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0058ULL;
    return acc;
}

// Func #1541 | PC: 0x0dcfcc | FDE: 0x148a38 | Size: 88 bytes
// Hàm #1541 | Địa chỉ PC: 0x0dcfcc | Địa chỉ FDE: 0x148a38 | Kích thước: 88 bytes
//   0x0dcfcc: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0dcfd0: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0dcfd4: 910043FD  add      x29, sp, #0x10
//   0x0dcfd8: AA0103F3  mov      x19, x1
static inline uint64_t fde_func_1541_0x0dcfcc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0dcfccULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0058ULL;
    return acc;
}

// Func #1542 | PC: 0x0dd024 | FDE: 0x148a38 | Size: 184 bytes
// Hàm #1542 | Địa chỉ PC: 0x0dd024 | Địa chỉ FDE: 0x148a38 | Kích thước: 184 bytes
//   0x0dd024: D10143FF  sub      sp, sp, #0x50
//   0x0dd028: F90013F5  str      x21, [sp, #0x20]
//   0x0dd02c: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x0dd030: A9047BFD  stp      x29, x30, [sp, #0x40]
static inline uint64_t fde_func_1542_0x0dd024(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0dd024ULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xf90013f5ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x00b8ULL;
    return acc;
}

// Func #1543 | PC: 0x0dd0dc | FDE: 0x148a38 | Size: 256 bytes
// Hàm #1543 | Địa chỉ PC: 0x0dd0dc | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0dd0dc: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x0dd0e0: 910003FD  mov      x29, sp
//   0x0dd0e4: 97FD560F  bl       #0x32920
//   0x0dd0e8: 97FD5626  bl       #0x32980
static inline uint64_t fde_func_1543_0x0dd0dc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0dd0dcULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #1544 | PC: 0x0dd378 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #1544 | Địa chỉ PC: 0x0dd378 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0dd378: D10583FF  sub      sp, sp, #0x160
//   0x0dd37c: A9125FFC  stp      x28, x23, [sp, #0x120]
//   0x0dd380: A91357F6  stp      x22, x21, [sp, #0x130]
//   0x0dd384: A9144FF4  stp      x20, x19, [sp, #0x140]
static inline uint64_t fde_func_1544_0x0dd378(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0dd378ULL ^ (static_cast<uint64_t>(0xd10583ffULL) << 13);
    acc = (acc + a1 + 0xa9125ffcULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #1545 | PC: 0x0dd5f0 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #1545 | Địa chỉ PC: 0x0dd5f0 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0dd5f0: D10203FF  sub      sp, sp, #0x80
//   0x0dd5f4: F9002BF5  str      x21, [sp, #0x50]
//   0x0dd5f8: A9064FF4  stp      x20, x19, [sp, #0x60]
//   0x0dd5fc: A9077BFD  stp      x29, x30, [sp, #0x70]
static inline uint64_t fde_func_1545_0x0dd5f0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0dd5f0ULL ^ (static_cast<uint64_t>(0xd10203ffULL) << 13);
    acc = (acc + a1 + 0xf9002bf5ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #1546 | PC: 0x0dd974 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #1546 | Địa chỉ PC: 0x0dd974 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0dd974: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0dd978: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0dd97c: 910043FD  add      x29, sp, #0x10
//   0x0dd980: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_1546_0x0dd974(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0dd974ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #1547 | PC: 0x0ddca4 | FDE: 0x148a38 | Size: 100 bytes
// Hàm #1547 | Địa chỉ PC: 0x0ddca4 | Địa chỉ FDE: 0x148a38 | Kích thước: 100 bytes
//   0x0ddca4: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0ddca8: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0ddcac: 910043FD  add      x29, sp, #0x10
//   0x0ddcb0: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_1547_0x0ddca4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ddca4ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0064ULL;
    return acc;
}

// Func #1548 | PC: 0x0ddd08 | FDE: 0x148a38 | Size: 224 bytes
// Hàm #1548 | Địa chỉ PC: 0x0ddd08 | Địa chỉ FDE: 0x148a38 | Kích thước: 224 bytes
//   0x0ddd08: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0ddd0c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0ddd10: 910043FD  add      x29, sp, #0x10
//   0x0ddd14: D00003C8  adrp     x8, #0x157000
static inline uint64_t fde_func_1548_0x0ddd08(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ddd08ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x00e0ULL;
    return acc;
}

// Func #1549 | PC: 0x0ddde8 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #1549 | Địa chỉ PC: 0x0ddde8 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0ddde8: D10183FF  sub      sp, sp, #0x60
//   0x0dddec: F9001BF5  str      x21, [sp, #0x30]
//   0x0dddf0: A9044FF4  stp      x20, x19, [sp, #0x40]
//   0x0dddf4: A9057BFD  stp      x29, x30, [sp, #0x50]
static inline uint64_t fde_func_1549_0x0ddde8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ddde8ULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xf9001bf5ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #1550 | PC: 0x0ddf38 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #1550 | Địa chỉ PC: 0x0ddf38 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0ddf38: D10103FF  sub      sp, sp, #0x40
//   0x0ddf3c: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x0ddf40: A9037BFD  stp      x29, x30, [sp, #0x30]
//   0x0ddf44: 9100C3FD  add      x29, sp, #0x30
static inline uint64_t fde_func_1550_0x0ddf38(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ddf38ULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xa9024ff4ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #1551 | PC: 0x0de0ac | FDE: 0x148a38 | Size: 256 bytes
// Hàm #1551 | Địa chỉ PC: 0x0de0ac | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0de0ac: D10183FF  sub      sp, sp, #0x60
//   0x0de0b0: F9001BF5  str      x21, [sp, #0x30]
//   0x0de0b4: A9044FF4  stp      x20, x19, [sp, #0x40]
//   0x0de0b8: A9057BFD  stp      x29, x30, [sp, #0x50]
static inline uint64_t fde_func_1551_0x0de0ac(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0de0acULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xf9001bf5ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #1552 | PC: 0x0de1b4 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #1552 | Địa chỉ PC: 0x0de1b4 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0de1b4: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0de1b8: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0de1bc: 910043FD  add      x29, sp, #0x10
//   0x0de1c0: D00003F4  adrp     x20, #0x15c000
static inline uint64_t fde_func_1552_0x0de1b4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0de1b4ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #1553 | PC: 0x0de32c | FDE: 0x148a38 | Size: 184 bytes
// Hàm #1553 | Địa chỉ PC: 0x0de32c | Địa chỉ FDE: 0x148a38 | Kích thước: 184 bytes
//   0x0de32c: D10503FF  sub      sp, sp, #0x140
//   0x0de330: A91157FC  stp      x28, x21, [sp, #0x110]
//   0x0de334: A9124FF4  stp      x20, x19, [sp, #0x120]
//   0x0de338: A9137BFD  stp      x29, x30, [sp, #0x130]
static inline uint64_t fde_func_1553_0x0de32c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0de32cULL ^ (static_cast<uint64_t>(0xd10503ffULL) << 13);
    acc = (acc + a1 + 0xa91157fcULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x00b8ULL;
    return acc;
}

// Func #1554 | PC: 0x0de3e4 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #1554 | Địa chỉ PC: 0x0de3e4 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0de3e4: D10583FF  sub      sp, sp, #0x160
//   0x0de3e8: A9125FFC  stp      x28, x23, [sp, #0x120]
//   0x0de3ec: A91357F6  stp      x22, x21, [sp, #0x130]
//   0x0de3f0: A9144FF4  stp      x20, x19, [sp, #0x140]
static inline uint64_t fde_func_1554_0x0de3e4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0de3e4ULL ^ (static_cast<uint64_t>(0xd10583ffULL) << 13);
    acc = (acc + a1 + 0xa9125ffcULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #1555 | PC: 0x0de878 | FDE: 0x148a38 | Size: 160 bytes
// Hàm #1555 | Địa chỉ PC: 0x0de878 | Địa chỉ FDE: 0x148a38 | Kích thước: 160 bytes
//   0x0de878: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x0de87c: 910003FD  mov      x29, sp
//   0x0de880: F9400400  ldr      x0, [x0, #8]
//   0x0de884: 97FFFE0A  bl       #0xde0ac
static inline uint64_t fde_func_1555_0x0de878(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0de878ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x00a0ULL;
    return acc;
}

// Func #1556 | PC: 0x0de918 | FDE: 0x148a38 | Size: 68 bytes
// Hàm #1556 | Địa chỉ PC: 0x0de918 | Địa chỉ FDE: 0x148a38 | Kích thước: 68 bytes
//   0x0de918: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x0de91c: 910003FD  mov      x29, sp
//   0x0de920: F9400400  ldr      x0, [x0, #8]
//   0x0de924: 97FFFDE2  bl       #0xde0ac
static inline uint64_t fde_func_1556_0x0de918(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0de918ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0044ULL;
    return acc;
}

// Func #1557 | PC: 0x0de95c | FDE: 0x148a38 | Size: 204 bytes
// Hàm #1557 | Địa chỉ PC: 0x0de95c | Địa chỉ FDE: 0x148a38 | Kích thước: 204 bytes
//   0x0de95c: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x0de960: 910003FD  mov      x29, sp
//   0x0de964: D00003E8  adrp     x8, #0x15c000
//   0x0de968: 9114C108  add      x8, x8, #0x530
static inline uint64_t fde_func_1557_0x0de95c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0de95cULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x00ccULL;
    return acc;
}

// Func #1558 | PC: 0x0dea28 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #1558 | Địa chỉ PC: 0x0dea28 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0dea28: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0dea2c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0dea30: 910043FD  add      x29, sp, #0x10
//   0x0dea34: B00003E8  adrp     x8, #0x15b000
static inline uint64_t fde_func_1558_0x0dea28(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0dea28ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #1559 | PC: 0x0ded30 | FDE: 0x148a38 | Size: 52 bytes
// Hàm #1559 | Địa chỉ PC: 0x0ded30 | Địa chỉ FDE: 0x148a38 | Kích thước: 52 bytes
//   0x0ded30: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x0ded34: 910003FD  mov      x29, sp
//   0x0ded38: 3940F008  ldrb     w8, [x0, #0x3c]
//   0x0ded3c: 34000068  cbz      w8, #0xded48
static inline uint64_t fde_func_1559_0x0ded30(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ded30ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0034ULL;
    return acc;
}

// Func #1560 | PC: 0x0ded64 | FDE: 0x148a38 | Size: 28 bytes
// Hàm #1560 | Địa chỉ PC: 0x0ded64 | Địa chỉ FDE: 0x148a38 | Kích thước: 28 bytes
//   0x0ded64: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x0ded68: 910003FD  mov      x29, sp
//   0x0ded6c: AA0203E1  mov      x1, x2
//   0x0ded70: 94000004  bl       #0xded80
static inline uint64_t fde_func_1560_0x0ded64(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ded64ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x001cULL;
    return acc;
}

// Func #1561 | PC: 0x0ded80 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #1561 | Địa chỉ PC: 0x0ded80 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0ded80: D10203FF  sub      sp, sp, #0x80
//   0x0ded84: F9001BF9  str      x25, [sp, #0x30]
//   0x0ded88: A9045FF8  stp      x24, x23, [sp, #0x40]
//   0x0ded8c: A90557F6  stp      x22, x21, [sp, #0x50]
static inline uint64_t fde_func_1561_0x0ded80(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ded80ULL ^ (static_cast<uint64_t>(0xd10203ffULL) << 13);
    acc = (acc + a1 + 0xf9001bf9ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #1562 | PC: 0x0df26c | FDE: 0x148a38 | Size: 120 bytes
// Hàm #1562 | Địa chỉ PC: 0x0df26c | Địa chỉ FDE: 0x148a38 | Kích thước: 120 bytes
//   0x0df26c: D100C3FF  sub      sp, sp, #0x30
//   0x0df270: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0df274: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0df278: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1562_0x0df26c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0df26cULL ^ (static_cast<uint64_t>(0xd100c3ffULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0078ULL;
    return acc;
}

// Func #1563 | PC: 0x0df2e4 | FDE: 0x148a38 | Size: 228 bytes
// Hàm #1563 | Địa chỉ PC: 0x0df2e4 | Địa chỉ FDE: 0x148a38 | Kích thước: 228 bytes
//   0x0df2e4: D10103FF  sub      sp, sp, #0x40
//   0x0df2e8: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x0df2ec: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x0df2f0: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_1563_0x0df2e4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0df2e4ULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x00e4ULL;
    return acc;
}

// Func #1564 | PC: 0x0df3c8 | FDE: 0x148a38 | Size: 228 bytes
// Hàm #1564 | Địa chỉ PC: 0x0df3c8 | Địa chỉ FDE: 0x148a38 | Kích thước: 228 bytes
//   0x0df3c8: D10103FF  sub      sp, sp, #0x40
//   0x0df3cc: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x0df3d0: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x0df3d4: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_1564_0x0df3c8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0df3c8ULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x00e4ULL;
    return acc;
}

// Func #1565 | PC: 0x0df4ac | FDE: 0x148a38 | Size: 160 bytes
// Hàm #1565 | Địa chỉ PC: 0x0df4ac | Địa chỉ FDE: 0x148a38 | Kích thước: 160 bytes
//   0x0df4ac: D10103FF  sub      sp, sp, #0x40
//   0x0df4b0: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x0df4b4: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x0df4b8: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_1565_0x0df4ac(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0df4acULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x00a0ULL;
    return acc;
}

// Func #1566 | PC: 0x0df54c | FDE: 0x148a38 | Size: 256 bytes
// Hàm #1566 | Địa chỉ PC: 0x0df54c | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0df54c: D13083FF  sub      sp, sp, #0xc20
//   0x0df550: F9404C08  ldr      x8, [x0, #0x98]
//   0x0df554: F100051F  cmp      x8, #1
//   0x0df558: 54000F8B  b.lt     #0xdf748
static inline uint64_t fde_func_1566_0x0df54c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0df54cULL ^ (static_cast<uint64_t>(0xd13083ffULL) << 13);
    acc = (acc + a1 + 0xf9404c08ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #1567 | PC: 0x0df7d8 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #1567 | Địa chỉ PC: 0x0df7d8 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0df7d8: D10103FF  sub      sp, sp, #0x40
//   0x0df7dc: F9000BF5  str      x21, [sp, #0x10]
//   0x0df7e0: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x0df7e4: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_1567_0x0df7d8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0df7d8ULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xf9000bf5ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #1568 | PC: 0x0df92c | FDE: 0x148a38 | Size: 148 bytes
// Hàm #1568 | Địa chỉ PC: 0x0df92c | Địa chỉ FDE: 0x148a38 | Kích thước: 148 bytes
//   0x0df92c: D10103FF  sub      sp, sp, #0x40
//   0x0df930: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x0df934: A9037BFD  stp      x29, x30, [sp, #0x30]
//   0x0df938: 9100C3FD  add      x29, sp, #0x30
static inline uint64_t fde_func_1568_0x0df92c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0df92cULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xa9024ff4ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0094ULL;
    return acc;
}

// Func #1569 | PC: 0x0df9c0 | FDE: 0x148a38 | Size: 104 bytes
// Hàm #1569 | Địa chỉ PC: 0x0df9c0 | Địa chỉ FDE: 0x148a38 | Kích thước: 104 bytes
//   0x0df9c0: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0df9c4: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0df9c8: 910043FD  add      x29, sp, #0x10
//   0x0df9cc: AA0103E8  mov      x8, x1
static inline uint64_t fde_func_1569_0x0df9c0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0df9c0ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0068ULL;
    return acc;
}

// Func #1570 | PC: 0x0dfa28 | FDE: 0x148a38 | Size: 60 bytes
// Hàm #1570 | Địa chỉ PC: 0x0dfa28 | Địa chỉ FDE: 0x148a38 | Kích thước: 60 bytes
//   0x0dfa28: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x0dfa2c: 910003FD  mov      x29, sp
//   0x0dfa30: 97FD4BBC  bl       #0x32920
//   0x0dfa34: 97FD4BD3  bl       #0x32980
static inline uint64_t fde_func_1570_0x0dfa28(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0dfa28ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x003cULL;
    return acc;
}

// Func #1571 | PC: 0x0dfa64 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #1571 | Địa chỉ PC: 0x0dfa64 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0dfa64: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x0dfa68: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0dfa6c: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0dfa70: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1571_0x0dfa64(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0dfa64ULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #1572 | PC: 0x0dfb90 | FDE: 0x148a38 | Size: 120 bytes
// Hàm #1572 | Địa chỉ PC: 0x0dfb90 | Địa chỉ FDE: 0x148a38 | Kích thước: 120 bytes
//   0x0dfb90: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0dfb94: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0dfb98: 910043FD  add      x29, sp, #0x10
//   0x0dfb9c: 97FD5085  bl       #0x33db0
static inline uint64_t fde_func_1572_0x0dfb90(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0dfb90ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0078ULL;
    return acc;
}

// Func #1573 | PC: 0x0dfc08 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #1573 | Địa chỉ PC: 0x0dfc08 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0dfc08: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0dfc0c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0dfc10: 910043FD  add      x29, sp, #0x10
//   0x0dfc14: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_1573_0x0dfc08(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0dfc08ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #1574 | PC: 0x0dfe9c | FDE: 0x148a38 | Size: 256 bytes
// Hàm #1574 | Địa chỉ PC: 0x0dfe9c | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0dfe9c: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0dfea0: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0dfea4: 910043FD  add      x29, sp, #0x10
//   0x0dfea8: F9400808  ldr      x8, [x0, #0x10]
static inline uint64_t fde_func_1574_0x0dfe9c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0dfe9cULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #1575 | PC: 0x0dffb8 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #1575 | Địa chỉ PC: 0x0dffb8 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0dffb8: D10143FF  sub      sp, sp, #0x50
//   0x0dffbc: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x0dffc0: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x0dffc4: A9047BFD  stp      x29, x30, [sp, #0x40]
static inline uint64_t fde_func_1575_0x0dffb8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0dffb8ULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xa90257f6ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #1576 | PC: 0x0e00fc | FDE: 0x148a38 | Size: 256 bytes
// Hàm #1576 | Địa chỉ PC: 0x0e00fc | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0e00fc: D104C3FF  sub      sp, sp, #0x130
//   0x0e0100: A90D6FFC  stp      x28, x27, [sp, #0xd0]
//   0x0e0104: A90E67FA  stp      x26, x25, [sp, #0xe0]
//   0x0e0108: A90F5FF8  stp      x24, x23, [sp, #0xf0]
static inline uint64_t fde_func_1576_0x0e00fc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e00fcULL ^ (static_cast<uint64_t>(0xd104c3ffULL) << 13);
    acc = (acc + a1 + 0xa90d6ffcULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #1577 | PC: 0x0e0364 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #1577 | Địa chỉ PC: 0x0e0364 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0e0364: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x0e0368: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0e036c: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0e0370: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1577_0x0e0364(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e0364ULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #1578 | PC: 0x0e0540 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #1578 | Địa chỉ PC: 0x0e0540 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0e0540: D101C3FF  sub      sp, sp, #0x70
//   0x0e0544: A90457F6  stp      x22, x21, [sp, #0x40]
//   0x0e0548: A9054FF4  stp      x20, x19, [sp, #0x50]
//   0x0e054c: A9067BFD  stp      x29, x30, [sp, #0x60]
static inline uint64_t fde_func_1578_0x0e0540(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e0540ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xa90457f6ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #1579 | PC: 0x0e074c | FDE: 0x148a38 | Size: 256 bytes
// Hàm #1579 | Địa chỉ PC: 0x0e074c | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0e074c: D10183FF  sub      sp, sp, #0x60
//   0x0e0750: A90357F6  stp      x22, x21, [sp, #0x30]
//   0x0e0754: A9044FF4  stp      x20, x19, [sp, #0x40]
//   0x0e0758: A9057BFD  stp      x29, x30, [sp, #0x50]
static inline uint64_t fde_func_1579_0x0e074c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e074cULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xa90357f6ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #1580 | PC: 0x0e0888 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #1580 | Địa chỉ PC: 0x0e0888 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0e0888: D10543FF  sub      sp, sp, #0x150
//   0x0e088c: A91067FC  stp      x28, x25, [sp, #0x100]
//   0x0e0890: A9115FF8  stp      x24, x23, [sp, #0x110]
//   0x0e0894: A91257F6  stp      x22, x21, [sp, #0x120]
static inline uint64_t fde_func_1580_0x0e0888(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e0888ULL ^ (static_cast<uint64_t>(0xd10543ffULL) << 13);
    acc = (acc + a1 + 0xa91067fcULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #1581 | PC: 0x0e0b0c | FDE: 0x148a38 | Size: 256 bytes
// Hàm #1581 | Địa chỉ PC: 0x0e0b0c | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0e0b0c: D10703FF  sub      sp, sp, #0x1c0
//   0x0e0b10: A91957FC  stp      x28, x21, [sp, #0x190]
//   0x0e0b14: A91A4FF4  stp      x20, x19, [sp, #0x1a0]
//   0x0e0b18: A91B7BFD  stp      x29, x30, [sp, #0x1b0]
static inline uint64_t fde_func_1581_0x0e0b0c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e0b0cULL ^ (static_cast<uint64_t>(0xd10703ffULL) << 13);
    acc = (acc + a1 + 0xa91957fcULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #1582 | PC: 0x0e0d48 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #1582 | Địa chỉ PC: 0x0e0d48 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0e0d48: D106C3FF  sub      sp, sp, #0x1b0
//   0x0e0d4c: FD00A3E8  str      d8, [sp, #0x140]
//   0x0e0d50: A9156FFC  stp      x28, x27, [sp, #0x150]
//   0x0e0d54: A91667FA  stp      x26, x25, [sp, #0x160]
static inline uint64_t fde_func_1582_0x0e0d48(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e0d48ULL ^ (static_cast<uint64_t>(0xd106c3ffULL) << 13);
    acc = (acc + a1 + 0xfd00a3e8ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #1583 | PC: 0x0e130c | FDE: 0x148a38 | Size: 256 bytes
// Hàm #1583 | Địa chỉ PC: 0x0e130c | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0e130c: A9BB67FA  stp      x26, x25, [sp, #-0x50]!
//   0x0e1310: A9015FF8  stp      x24, x23, [sp, #0x10]
//   0x0e1314: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x0e1318: A9034FF4  stp      x20, x19, [sp, #0x30]
static inline uint64_t fde_func_1583_0x0e130c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e130cULL ^ (static_cast<uint64_t>(0xa9bb67faULL) << 13);
    acc = (acc + a1 + 0xa9015ff8ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #1584 | PC: 0x0e144c | FDE: 0x148a38 | Size: 256 bytes
// Hàm #1584 | Địa chỉ PC: 0x0e144c | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0e144c: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0e1450: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0e1454: 910043FD  add      x29, sp, #0x10
//   0x0e1458: D37DFC28  lsr      x8, x1, #0x3d
static inline uint64_t fde_func_1584_0x0e144c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e144cULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #1585 | PC: 0x0e1594 | FDE: 0x148a38 | Size: 72 bytes
// Hàm #1585 | Địa chỉ PC: 0x0e1594 | Địa chỉ FDE: 0x148a38 | Kích thước: 72 bytes
//   0x0e1594: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0e1598: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0e159c: 910043FD  add      x29, sp, #0x10
//   0x0e15a0: 91008013  add      x19, x0, #0x20
static inline uint64_t fde_func_1585_0x0e1594(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e1594ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0048ULL;
    return acc;
}

// Func #1586 | PC: 0x0e15dc | FDE: 0x148a38 | Size: 256 bytes
// Hàm #1586 | Địa chỉ PC: 0x0e15dc | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0e15dc: D10143FF  sub      sp, sp, #0x50
//   0x0e15e0: F90013F5  str      x21, [sp, #0x20]
//   0x0e15e4: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x0e15e8: A9047BFD  stp      x29, x30, [sp, #0x40]
static inline uint64_t fde_func_1586_0x0e15dc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e15dcULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xf90013f5ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #1587 | PC: 0x0e1750 | FDE: 0x148a38 | Size: 152 bytes
// Hàm #1587 | Địa chỉ PC: 0x0e1750 | Địa chỉ FDE: 0x148a38 | Kích thước: 152 bytes
//   0x0e1750: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x0e1754: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0e1758: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0e175c: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1587_0x0e1750(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e1750ULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0098ULL;
    return acc;
}

// Func #1588 | PC: 0x0e17e8 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #1588 | Địa chỉ PC: 0x0e17e8 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0e17e8: D10103FF  sub      sp, sp, #0x40
//   0x0e17ec: A90107F5  stp      x21, x1, [sp, #0x10]
//   0x0e17f0: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x0e17f4: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_1588_0x0e17e8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e17e8ULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xa90107f5ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #1589 | PC: 0x0e1958 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #1589 | Địa chỉ PC: 0x0e1958 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0e1958: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x0e195c: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0e1960: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0e1964: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1589_0x0e1958(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e1958ULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #1590 | PC: 0x0e1aac | FDE: 0x148a38 | Size: 256 bytes
// Hàm #1590 | Địa chỉ PC: 0x0e1aac | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0e1aac: D10283FF  sub      sp, sp, #0xa0
//   0x0e1ab0: FD001BEA  str      d10, [sp, #0x30]
//   0x0e1ab4: 6D03A3E9  stp      d9, d8, [sp, #0x38]
//   0x0e1ab8: F90027FB  str      x27, [sp, #0x48]
static inline uint64_t fde_func_1590_0x0e1aac(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e1aacULL ^ (static_cast<uint64_t>(0xd10283ffULL) << 13);
    acc = (acc + a1 + 0xfd001beaULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #1591 | PC: 0x0e1c64 | FDE: 0x148a38 | Size: 196 bytes
// Hàm #1591 | Địa chỉ PC: 0x0e1c64 | Địa chỉ FDE: 0x148a38 | Kích thước: 196 bytes
//   0x0e1c64: D10103FF  sub      sp, sp, #0x40
//   0x0e1c68: A90107F5  stp      x21, x1, [sp, #0x10]
//   0x0e1c6c: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x0e1c70: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_1591_0x0e1c64(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e1c64ULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xa90107f5ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x00c4ULL;
    return acc;
}

// Func #1592 | PC: 0x0e1d28 | FDE: 0x148a38 | Size: 120 bytes
// Hàm #1592 | Địa chỉ PC: 0x0e1d28 | Địa chỉ FDE: 0x148a38 | Kích thước: 120 bytes
//   0x0e1d28: D100C3FF  sub      sp, sp, #0x30
//   0x0e1d2c: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0e1d30: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0e1d34: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1592_0x0e1d28(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e1d28ULL ^ (static_cast<uint64_t>(0xd100c3ffULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0078ULL;
    return acc;
}

// Func #1593 | PC: 0x0e1da0 | FDE: 0x148a38 | Size: 56 bytes
// Hàm #1593 | Địa chỉ PC: 0x0e1da0 | Địa chỉ FDE: 0x148a38 | Kích thước: 56 bytes
//   0x0e1da0: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0e1da4: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0e1da8: 910043FD  add      x29, sp, #0x10
//   0x0e1dac: 91002014  add      x20, x0, #8
static inline uint64_t fde_func_1593_0x0e1da0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e1da0ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0038ULL;
    return acc;
}

// Func #1594 | PC: 0x0e1dd8 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #1594 | Địa chỉ PC: 0x0e1dd8 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0e1dd8: D10143FF  sub      sp, sp, #0x50
//   0x0e1ddc: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x0e1de0: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x0e1de4: A9047BFD  stp      x29, x30, [sp, #0x40]
static inline uint64_t fde_func_1594_0x0e1dd8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e1dd8ULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xa90257f6ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #1595 | PC: 0x0e212c | FDE: 0x148a38 | Size: 36 bytes
// Hàm #1595 | Địa chỉ PC: 0x0e212c | Địa chỉ FDE: 0x148a38 | Kích thước: 36 bytes
//   0x0e212c: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x0e2130: 910003FD  mov      x29, sp
//   0x0e2134: 97FD41FB  bl       #0x32920
//   0x0e2138: 97FD4212  bl       #0x32980
static inline uint64_t fde_func_1595_0x0e212c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e212cULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0024ULL;
    return acc;
}

// Func #1596 | PC: 0x0e2150 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #1596 | Địa chỉ PC: 0x0e2150 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0e2150: D10483FF  sub      sp, sp, #0x120
//   0x0e2154: A90C6FFC  stp      x28, x27, [sp, #0xc0]
//   0x0e2158: A90D67FA  stp      x26, x25, [sp, #0xd0]
//   0x0e215c: A90E5FF8  stp      x24, x23, [sp, #0xe0]
static inline uint64_t fde_func_1596_0x0e2150(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e2150ULL ^ (static_cast<uint64_t>(0xd10483ffULL) << 13);
    acc = (acc + a1 + 0xa90c6ffcULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #1597 | PC: 0x0e2a8c | FDE: 0x148a38 | Size: 64 bytes
// Hàm #1597 | Địa chỉ PC: 0x0e2a8c | Địa chỉ FDE: 0x148a38 | Kích thước: 64 bytes
//   0x0e2a8c: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0e2a90: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0e2a94: 910043FD  add      x29, sp, #0x10
//   0x0e2a98: D37CFC28  lsr      x8, x1, #0x3c
static inline uint64_t fde_func_1597_0x0e2a8c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e2a8cULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0040ULL;
    return acc;
}

// Func #1598 | PC: 0x0e2acc | FDE: 0x148a38 | Size: 256 bytes
// Hàm #1598 | Địa chỉ PC: 0x0e2acc | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0e2acc: D10203FF  sub      sp, sp, #0x80
//   0x0e2ad0: F90013FB  str      x27, [sp, #0x20]
//   0x0e2ad4: A90367FA  stp      x26, x25, [sp, #0x30]
//   0x0e2ad8: A9045FF8  stp      x24, x23, [sp, #0x40]
static inline uint64_t fde_func_1598_0x0e2acc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e2accULL ^ (static_cast<uint64_t>(0xd10203ffULL) << 13);
    acc = (acc + a1 + 0xf90013fbULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #1599 | PC: 0x0e2f34 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #1599 | Địa chỉ PC: 0x0e2f34 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0e2f34: D100C3FF  sub      sp, sp, #0x30
//   0x0e2f38: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0e2f3c: 910083FD  add      x29, sp, #0x20
//   0x0e2f40: D53BD048  mrs      x8, tpidr_el0
static inline uint64_t fde_func_1599_0x0e2f34(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e2f34ULL ^ (static_cast<uint64_t>(0xd100c3ffULL) << 13);
    acc = (acc + a1 + 0xa9027bfdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #1600 | PC: 0x0e3088 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #1600 | Địa chỉ PC: 0x0e3088 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0e3088: D10183FF  sub      sp, sp, #0x60
//   0x0e308c: F90013F7  str      x23, [sp, #0x20]
//   0x0e3090: A90357F6  stp      x22, x21, [sp, #0x30]
//   0x0e3094: A9044FF4  stp      x20, x19, [sp, #0x40]
static inline uint64_t fde_func_1600_0x0e3088(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e3088ULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xf90013f7ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #1601 | PC: 0x0e31a8 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #1601 | Địa chỉ PC: 0x0e31a8 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0e31a8: D10183FF  sub      sp, sp, #0x60
//   0x0e31ac: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x0e31b0: A90357F6  stp      x22, x21, [sp, #0x30]
//   0x0e31b4: A9044FF4  stp      x20, x19, [sp, #0x40]
static inline uint64_t fde_func_1601_0x0e31a8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e31a8ULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xa9025ff8ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #1602 | PC: 0x0e330c | FDE: 0x148a38 | Size: 256 bytes
// Hàm #1602 | Địa chỉ PC: 0x0e330c | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0e330c: D10143FF  sub      sp, sp, #0x50
//   0x0e3310: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x0e3314: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x0e3318: A9047BFD  stp      x29, x30, [sp, #0x40]
static inline uint64_t fde_func_1602_0x0e330c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e330cULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xa90257f6ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #1603 | PC: 0x0e34cc | FDE: 0x148a38 | Size: 256 bytes
// Hàm #1603 | Địa chỉ PC: 0x0e34cc | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0e34cc: D10203FF  sub      sp, sp, #0x80
//   0x0e34d0: F9001BF9  str      x25, [sp, #0x30]
//   0x0e34d4: A9045FF8  stp      x24, x23, [sp, #0x40]
//   0x0e34d8: A90557F6  stp      x22, x21, [sp, #0x50]
static inline uint64_t fde_func_1603_0x0e34cc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e34ccULL ^ (static_cast<uint64_t>(0xd10203ffULL) << 13);
    acc = (acc + a1 + 0xf9001bf9ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #1604 | PC: 0x0e38f0 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #1604 | Địa chỉ PC: 0x0e38f0 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0e38f0: A9BC5FF8  stp      x24, x23, [sp, #-0x40]!
//   0x0e38f4: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x0e38f8: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x0e38fc: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_1604_0x0e38f0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e38f0ULL ^ (static_cast<uint64_t>(0xa9bc5ff8ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #1605 | PC: 0x0e3b58 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #1605 | Địa chỉ PC: 0x0e3b58 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0e3b58: A9BC5FF8  stp      x24, x23, [sp, #-0x40]!
//   0x0e3b5c: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x0e3b60: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x0e3b64: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_1605_0x0e3b58(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e3b58ULL ^ (static_cast<uint64_t>(0xa9bc5ff8ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #1606 | PC: 0x0e3cf8 | FDE: 0x148a38 | Size: 60 bytes
// Hàm #1606 | Địa chỉ PC: 0x0e3cf8 | Địa chỉ FDE: 0x148a38 | Kích thước: 60 bytes
//   0x0e3cf8: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0e3cfc: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0e3d00: 910043FD  add      x29, sp, #0x10
//   0x0e3d04: AA0103F3  mov      x19, x1
static inline uint64_t fde_func_1606_0x0e3cf8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e3cf8ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x003cULL;
    return acc;
}

// Func #1607 | PC: 0x0e3d34 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #1607 | Địa chỉ PC: 0x0e3d34 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0e3d34: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x0e3d38: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0e3d3c: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0e3d40: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1607_0x0e3d34(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e3d34ULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #1608 | PC: 0x0e3f30 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #1608 | Địa chỉ PC: 0x0e3f30 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0e3f30: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0e3f34: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0e3f38: 910043FD  add      x29, sp, #0x10
//   0x0e3f3c: D37CFC28  lsr      x8, x1, #0x3c
static inline uint64_t fde_func_1608_0x0e3f30(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e3f30ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #1609 | PC: 0x0e44f0 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #1609 | Địa chỉ PC: 0x0e44f0 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0e44f0: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x0e44f4: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0e44f8: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0e44fc: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1609_0x0e44f0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e44f0ULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #1610 | PC: 0x0e4840 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #1610 | Địa chỉ PC: 0x0e4840 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0e4840: D10103FF  sub      sp, sp, #0x40
//   0x0e4844: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x0e4848: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x0e484c: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_1610_0x0e4840(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e4840ULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #1611 | PC: 0x0e4970 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #1611 | Địa chỉ PC: 0x0e4970 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0e4970: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0e4974: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0e4978: 910043FD  add      x29, sp, #0x10
//   0x0e497c: AA0103F3  mov      x19, x1
static inline uint64_t fde_func_1611_0x0e4970(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e4970ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #1612 | PC: 0x0e4b10 | FDE: 0x148a38 | Size: 116 bytes
// Hàm #1612 | Địa chỉ PC: 0x0e4b10 | Địa chỉ FDE: 0x148a38 | Kích thước: 116 bytes
//   0x0e4b10: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x0e4b14: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0e4b18: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0e4b1c: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1612_0x0e4b10(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e4b10ULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0074ULL;
    return acc;
}

// Func #1613 | PC: 0x0e4b84 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #1613 | Địa chỉ PC: 0x0e4b84 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0e4b84: D10183FF  sub      sp, sp, #0x60
//   0x0e4b88: F90013F7  str      x23, [sp, #0x20]
//   0x0e4b8c: A90357F6  stp      x22, x21, [sp, #0x30]
//   0x0e4b90: A9044FF4  stp      x20, x19, [sp, #0x40]
static inline uint64_t fde_func_1613_0x0e4b84(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e4b84ULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xf90013f7ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #1614 | PC: 0x0e4d4c | FDE: 0x148a38 | Size: 120 bytes
// Hàm #1614 | Địa chỉ PC: 0x0e4d4c | Địa chỉ FDE: 0x148a38 | Kích thước: 120 bytes
//   0x0e4d4c: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0e4d50: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0e4d54: 910043FD  add      x29, sp, #0x10
//   0x0e4d58: 39402008  ldrb     w8, [x0, #8]
static inline uint64_t fde_func_1614_0x0e4d4c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e4d4cULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0078ULL;
    return acc;
}

// Func #1615 | PC: 0x0e4dc4 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #1615 | Địa chỉ PC: 0x0e4dc4 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0e4dc4: A9BB67FA  stp      x26, x25, [sp, #-0x50]!
//   0x0e4dc8: A9015FF8  stp      x24, x23, [sp, #0x10]
//   0x0e4dcc: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x0e4dd0: A9034FF4  stp      x20, x19, [sp, #0x30]
static inline uint64_t fde_func_1615_0x0e4dc4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e4dc4ULL ^ (static_cast<uint64_t>(0xa9bb67faULL) << 13);
    acc = (acc + a1 + 0xa9015ff8ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #1616 | PC: 0x0e4f0c | FDE: 0x148a38 | Size: 256 bytes
// Hàm #1616 | Địa chỉ PC: 0x0e4f0c | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0e4f0c: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x0e4f10: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0e4f14: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0e4f18: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1616_0x0e4f0c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e4f0cULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #1617 | PC: 0x0e5040 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #1617 | Địa chỉ PC: 0x0e5040 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0e5040: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0e5044: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0e5048: 910043FD  add      x29, sp, #0x10
//   0x0e504c: AA0103F3  mov      x19, x1
static inline uint64_t fde_func_1617_0x0e5040(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e5040ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #1618 | PC: 0x0e5260 | FDE: 0x148a38 | Size: 28 bytes
// Hàm #1618 | Địa chỉ PC: 0x0e5260 | Địa chỉ FDE: 0x148a38 | Kích thước: 28 bytes
//   0x0e5260: A9BA6FFC  stp      x28, x27, [sp, #-0x60]!
//   0x0e5264: A90167FA  stp      x26, x25, [sp, #0x10]
//   0x0e5268: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x0e526c: A90357F6  stp      x22, x21, [sp, #0x30]
static inline uint64_t fde_func_1618_0x0e5260(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e5260ULL ^ (static_cast<uint64_t>(0xa9ba6ffcULL) << 13);
    acc = (acc + a1 + 0xa90167faULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x001cULL;
    return acc;
}

// Func #1619 | PC: 0x0e527c | FDE: 0x148a38 | Size: 256 bytes
// Hàm #1619 | Địa chỉ PC: 0x0e527c | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0e527c: D10883FF  sub      sp, sp, #0x220
//   0x0e5280: D53BD058  mrs      x24, tpidr_el0
//   0x0e5284: F9401708  ldr      x8, [x24, #0x28]
//   0x0e5288: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_1619_0x0e527c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e527cULL ^ (static_cast<uint64_t>(0xd10883ffULL) << 13);
    acc = (acc + a1 + 0xd53bd058ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #1620 | PC: 0x0e5744 | FDE: 0x148a38 | Size: 224 bytes
// Hàm #1620 | Địa chỉ PC: 0x0e5744 | Địa chỉ FDE: 0x148a38 | Kích thước: 224 bytes
//   0x0e5744: D10203FF  sub      sp, sp, #0x80
//   0x0e5748: A90557F6  stp      x22, x21, [sp, #0x50]
//   0x0e574c: A9064FF4  stp      x20, x19, [sp, #0x60]
//   0x0e5750: A9077BFD  stp      x29, x30, [sp, #0x70]
static inline uint64_t fde_func_1620_0x0e5744(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e5744ULL ^ (static_cast<uint64_t>(0xd10203ffULL) << 13);
    acc = (acc + a1 + 0xa90557f6ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x00e0ULL;
    return acc;
}

// Func #1621 | PC: 0x0e5824 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #1621 | Địa chỉ PC: 0x0e5824 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0e5824: D101C3FF  sub      sp, sp, #0x70
//   0x0e5828: A9035FF8  stp      x24, x23, [sp, #0x30]
//   0x0e582c: A90457F6  stp      x22, x21, [sp, #0x40]
//   0x0e5830: A9054FF4  stp      x20, x19, [sp, #0x50]
static inline uint64_t fde_func_1621_0x0e5824(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e5824ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xa9035ff8ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #1622 | PC: 0x0e5ba8 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #1622 | Địa chỉ PC: 0x0e5ba8 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0e5ba8: D100C3FF  sub      sp, sp, #0x30
//   0x0e5bac: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0e5bb0: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0e5bb4: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1622_0x0e5ba8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e5ba8ULL ^ (static_cast<uint64_t>(0xd100c3ffULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #1623 | PC: 0x0e5cc0 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #1623 | Địa chỉ PC: 0x0e5cc0 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0e5cc0: D100C3FF  sub      sp, sp, #0x30
//   0x0e5cc4: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0e5cc8: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0e5ccc: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1623_0x0e5cc0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e5cc0ULL ^ (static_cast<uint64_t>(0xd100c3ffULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #1624 | PC: 0x0e5dd8 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #1624 | Địa chỉ PC: 0x0e5dd8 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0e5dd8: D10643FF  sub      sp, sp, #0x190
//   0x0e5ddc: F900ABFC  str      x28, [sp, #0x150]
//   0x0e5de0: A91657F6  stp      x22, x21, [sp, #0x160]
//   0x0e5de4: A9174FF4  stp      x20, x19, [sp, #0x170]
static inline uint64_t fde_func_1624_0x0e5dd8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e5dd8ULL ^ (static_cast<uint64_t>(0xd10643ffULL) << 13);
    acc = (acc + a1 + 0xf900abfcULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #1625 | PC: 0x0e6110 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #1625 | Địa chỉ PC: 0x0e6110 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0e6110: D10643FF  sub      sp, sp, #0x190
//   0x0e6114: F900ABFC  str      x28, [sp, #0x150]
//   0x0e6118: A91657F6  stp      x22, x21, [sp, #0x160]
//   0x0e611c: A9174FF4  stp      x20, x19, [sp, #0x170]
static inline uint64_t fde_func_1625_0x0e6110(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e6110ULL ^ (static_cast<uint64_t>(0xd10643ffULL) << 13);
    acc = (acc + a1 + 0xf900abfcULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #1626 | PC: 0x0e65d0 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #1626 | Địa chỉ PC: 0x0e65d0 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0e65d0: D10683FF  sub      sp, sp, #0x1a0
//   0x0e65d4: F900B3FC  str      x28, [sp, #0x160]
//   0x0e65d8: A91757F6  stp      x22, x21, [sp, #0x170]
//   0x0e65dc: A9184FF4  stp      x20, x19, [sp, #0x180]
static inline uint64_t fde_func_1626_0x0e65d0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e65d0ULL ^ (static_cast<uint64_t>(0xd10683ffULL) << 13);
    acc = (acc + a1 + 0xf900b3fcULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #1627 | PC: 0x0e6950 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #1627 | Địa chỉ PC: 0x0e6950 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0e6950: D10683FF  sub      sp, sp, #0x1a0
//   0x0e6954: A9146FFC  stp      x28, x27, [sp, #0x140]
//   0x0e6958: A91567FA  stp      x26, x25, [sp, #0x150]
//   0x0e695c: A9165FF8  stp      x24, x23, [sp, #0x160]
static inline uint64_t fde_func_1627_0x0e6950(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e6950ULL ^ (static_cast<uint64_t>(0xd10683ffULL) << 13);
    acc = (acc + a1 + 0xa9146ffcULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #1628 | PC: 0x0e6dfc | FDE: 0x148a38 | Size: 256 bytes
// Hàm #1628 | Địa chỉ PC: 0x0e6dfc | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0e6dfc: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x0e6e00: 910003FD  mov      x29, sp
//   0x0e6e04: B9409C08  ldr      w8, [x0, #0x9c]
//   0x0e6e08: AA0003E2  mov      x2, x0
static inline uint64_t fde_func_1628_0x0e6dfc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e6dfcULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #1629 | PC: 0x0e6f78 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #1629 | Địa chỉ PC: 0x0e6f78 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0e6f78: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0e6f7c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0e6f80: 910043FD  add      x29, sp, #0x10
//   0x0e6f84: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_1629_0x0e6f78(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e6f78ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #1630 | PC: 0x0e72a8 | FDE: 0x148a38 | Size: 100 bytes
// Hàm #1630 | Địa chỉ PC: 0x0e72a8 | Địa chỉ FDE: 0x148a38 | Kích thước: 100 bytes
//   0x0e72a8: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0e72ac: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0e72b0: 910043FD  add      x29, sp, #0x10
//   0x0e72b4: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_1630_0x0e72a8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e72a8ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0064ULL;
    return acc;
}

// Func #1631 | PC: 0x0e730c | FDE: 0x148a38 | Size: 224 bytes
// Hàm #1631 | Địa chỉ PC: 0x0e730c | Địa chỉ FDE: 0x148a38 | Kích thước: 224 bytes
//   0x0e730c: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0e7310: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0e7314: 910043FD  add      x29, sp, #0x10
//   0x0e7318: 90000388  adrp     x8, #0x157000
static inline uint64_t fde_func_1631_0x0e730c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e730cULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x00e0ULL;
    return acc;
}

// Func #1632 | PC: 0x0e73ec | FDE: 0x148a38 | Size: 256 bytes
// Hàm #1632 | Địa chỉ PC: 0x0e73ec | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0e73ec: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x0e73f0: 910003FD  mov      x29, sp
//   0x0e73f4: AA0003E8  mov      x8, x0
//   0x0e73f8: F9400400  ldr      x0, [x0, #8]
static inline uint64_t fde_func_1632_0x0e73ec(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e73ecULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #1633 | PC: 0x0e75cc | FDE: 0x148a38 | Size: 200 bytes
// Hàm #1633 | Địa chỉ PC: 0x0e75cc | Địa chỉ FDE: 0x148a38 | Kích thước: 200 bytes
//   0x0e75cc: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x0e75d0: 910003FD  mov      x29, sp
//   0x0e75d4: F9400400  ldr      x0, [x0, #8]
//   0x0e75d8: B9405408  ldr      w8, [x0, #0x54]
static inline uint64_t fde_func_1633_0x0e75cc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e75ccULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x00c8ULL;
    return acc;
}

// Func #1634 | PC: 0x0e7694 | FDE: 0x148a38 | Size: 176 bytes
// Hàm #1634 | Địa chỉ PC: 0x0e7694 | Địa chỉ FDE: 0x148a38 | Kích thước: 176 bytes
//   0x0e7694: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x0e7698: 910003FD  mov      x29, sp
//   0x0e769c: F9400400  ldr      x0, [x0, #8]
//   0x0e76a0: 12800004  mov      w4, #-1
static inline uint64_t fde_func_1634_0x0e7694(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e7694ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x00b0ULL;
    return acc;
}

// Func #1635 | PC: 0x0e7744 | FDE: 0x148a38 | Size: 84 bytes
// Hàm #1635 | Địa chỉ PC: 0x0e7744 | Địa chỉ FDE: 0x148a38 | Kích thước: 84 bytes
//   0x0e7744: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x0e7748: 910003FD  mov      x29, sp
//   0x0e774c: F9400400  ldr      x0, [x0, #8]
//   0x0e7750: 12800004  mov      w4, #-1
static inline uint64_t fde_func_1635_0x0e7744(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e7744ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0054ULL;
    return acc;
}

// Func #1636 | PC: 0x0e7798 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #1636 | Địa chỉ PC: 0x0e7798 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0e7798: D101C3FF  sub      sp, sp, #0x70
//   0x0e779c: F9001BF7  str      x23, [sp, #0x30]
//   0x0e77a0: A90457F6  stp      x22, x21, [sp, #0x40]
//   0x0e77a4: A9054FF4  stp      x20, x19, [sp, #0x50]
static inline uint64_t fde_func_1636_0x0e7798(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e7798ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xf9001bf7ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #1637 | PC: 0x0e7c30 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #1637 | Địa chỉ PC: 0x0e7c30 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0e7c30: D101C3FF  sub      sp, sp, #0x70
//   0x0e7c34: F9001BF7  str      x23, [sp, #0x30]
//   0x0e7c38: A90457F6  stp      x22, x21, [sp, #0x40]
//   0x0e7c3c: A9054FF4  stp      x20, x19, [sp, #0x50]
static inline uint64_t fde_func_1637_0x0e7c30(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e7c30ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xf9001bf7ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #1638 | PC: 0x0e7ec4 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #1638 | Địa chỉ PC: 0x0e7ec4 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0e7ec4: D10683FF  sub      sp, sp, #0x1a0
//   0x0e7ec8: F900B3FC  str      x28, [sp, #0x160]
//   0x0e7ecc: A91757F6  stp      x22, x21, [sp, #0x170]
//   0x0e7ed0: A9184FF4  stp      x20, x19, [sp, #0x180]
static inline uint64_t fde_func_1638_0x0e7ec4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e7ec4ULL ^ (static_cast<uint64_t>(0xd10683ffULL) << 13);
    acc = (acc + a1 + 0xf900b3fcULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #1639 | PC: 0x0e816c | FDE: 0x148a38 | Size: 256 bytes
// Hàm #1639 | Địa chỉ PC: 0x0e816c | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0e816c: D10203FF  sub      sp, sp, #0x80
//   0x0e8170: A90557F6  stp      x22, x21, [sp, #0x50]
//   0x0e8174: A9064FF4  stp      x20, x19, [sp, #0x60]
//   0x0e8178: A9077BFD  stp      x29, x30, [sp, #0x70]
static inline uint64_t fde_func_1639_0x0e816c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e816cULL ^ (static_cast<uint64_t>(0xd10203ffULL) << 13);
    acc = (acc + a1 + 0xa90557f6ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #1640 | PC: 0x0e8270 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #1640 | Địa chỉ PC: 0x0e8270 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0e8270: D107C3FF  sub      sp, sp, #0x1f0
//   0x0e8274: AA0003F3  mov      x19, x0
//   0x0e8278: 910163E0  add      x0, sp, #0x58
//   0x0e827c: 97FD31B1  bl       #0x34940
static inline uint64_t fde_func_1640_0x0e8270(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e8270ULL ^ (static_cast<uint64_t>(0xd107c3ffULL) << 13);
    acc = (acc + a1 + 0xaa0003f3ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #1641 | PC: 0x0e86e0 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #1641 | Địa chỉ PC: 0x0e86e0 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0e86e0: D10203FF  sub      sp, sp, #0x80
//   0x0e86e4: F9002BF5  str      x21, [sp, #0x50]
//   0x0e86e8: A9064FF4  stp      x20, x19, [sp, #0x60]
//   0x0e86ec: A9077BFD  stp      x29, x30, [sp, #0x70]
static inline uint64_t fde_func_1641_0x0e86e0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e86e0ULL ^ (static_cast<uint64_t>(0xd10203ffULL) << 13);
    acc = (acc + a1 + 0xf9002bf5ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #1642 | PC: 0x0e8814 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #1642 | Địa chỉ PC: 0x0e8814 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0e8814: D10183FF  sub      sp, sp, #0x60
//   0x0e8818: F90023F3  str      x19, [sp, #0x40]
//   0x0e881c: A9057BFD  stp      x29, x30, [sp, #0x50]
//   0x0e8820: 910143FD  add      x29, sp, #0x50
static inline uint64_t fde_func_1642_0x0e8814(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e8814ULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xf90023f3ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #1643 | PC: 0x0e898c | FDE: 0x148a38 | Size: 256 bytes
// Hàm #1643 | Địa chỉ PC: 0x0e898c | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0e898c: D10483FF  sub      sp, sp, #0x120
//   0x0e8990: A90D67FC  stp      x28, x25, [sp, #0xd0]
//   0x0e8994: A90E5FF8  stp      x24, x23, [sp, #0xe0]
//   0x0e8998: A90F57F6  stp      x22, x21, [sp, #0xf0]
static inline uint64_t fde_func_1643_0x0e898c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e898cULL ^ (static_cast<uint64_t>(0xd10483ffULL) << 13);
    acc = (acc + a1 + 0xa90d67fcULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #1644 | PC: 0x0e8b18 | FDE: 0x148a38 | Size: 80 bytes
// Hàm #1644 | Địa chỉ PC: 0x0e8b18 | Địa chỉ FDE: 0x148a38 | Kích thước: 80 bytes
//   0x0e8b18: D10103FF  sub      sp, sp, #0x40
//   0x0e8b1c: F90013F3  str      x19, [sp, #0x20]
//   0x0e8b20: A9037BFD  stp      x29, x30, [sp, #0x30]
//   0x0e8b24: 9100C3FD  add      x29, sp, #0x30
static inline uint64_t fde_func_1644_0x0e8b18(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e8b18ULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xf90013f3ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0050ULL;
    return acc;
}

// Func #1645 | PC: 0x0e8b68 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #1645 | Địa chỉ PC: 0x0e8b68 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0e8b68: D101C3FF  sub      sp, sp, #0x70
//   0x0e8b6c: A9054FF4  stp      x20, x19, [sp, #0x50]
//   0x0e8b70: A9067BFD  stp      x29, x30, [sp, #0x60]
//   0x0e8b74: 910183FD  add      x29, sp, #0x60
static inline uint64_t fde_func_1645_0x0e8b68(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e8b68ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xa9054ff4ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #1646 | PC: 0x0e8d04 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #1646 | Địa chỉ PC: 0x0e8d04 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0e8d04: D10143FF  sub      sp, sp, #0x50
//   0x0e8d08: F90013F5  str      x21, [sp, #0x20]
//   0x0e8d0c: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x0e8d10: A9047BFD  stp      x29, x30, [sp, #0x40]
static inline uint64_t fde_func_1646_0x0e8d04(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e8d04ULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xf90013f5ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #1647 | PC: 0x0e8e84 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #1647 | Địa chỉ PC: 0x0e8e84 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0e8e84: D10483FF  sub      sp, sp, #0x120
//   0x0e8e88: A90C6FFC  stp      x28, x27, [sp, #0xc0]
//   0x0e8e8c: A90D67FA  stp      x26, x25, [sp, #0xd0]
//   0x0e8e90: A90E5FF8  stp      x24, x23, [sp, #0xe0]
static inline uint64_t fde_func_1647_0x0e8e84(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e8e84ULL ^ (static_cast<uint64_t>(0xd10483ffULL) << 13);
    acc = (acc + a1 + 0xa90c6ffcULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #1648 | PC: 0x0e9060 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #1648 | Địa chỉ PC: 0x0e9060 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0e9060: D101C3FF  sub      sp, sp, #0x70
//   0x0e9064: A9054FF4  stp      x20, x19, [sp, #0x50]
//   0x0e9068: A9067BFD  stp      x29, x30, [sp, #0x60]
//   0x0e906c: 910183FD  add      x29, sp, #0x60
static inline uint64_t fde_func_1648_0x0e9060(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e9060ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xa9054ff4ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #1649 | PC: 0x0e9298 | FDE: 0x148a38 | Size: 28 bytes
// Hàm #1649 | Địa chỉ PC: 0x0e9298 | Địa chỉ FDE: 0x148a38 | Kích thước: 28 bytes
//   0x0e9298: A9BA6FFC  stp      x28, x27, [sp, #-0x60]!
//   0x0e929c: A90167FA  stp      x26, x25, [sp, #0x10]
//   0x0e92a0: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x0e92a4: A90357F6  stp      x22, x21, [sp, #0x30]
static inline uint64_t fde_func_1649_0x0e9298(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e9298ULL ^ (static_cast<uint64_t>(0xa9ba6ffcULL) << 13);
    acc = (acc + a1 + 0xa90167faULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x001cULL;
    return acc;
}

// Func #1650 | PC: 0x0e92b4 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #1650 | Địa chỉ PC: 0x0e92b4 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0e92b4: D10883FF  sub      sp, sp, #0x220
//   0x0e92b8: 9103E014  add      x20, x0, #0xf8
//   0x0e92bc: AA0003F3  mov      x19, x0
//   0x0e92c0: D101C3A8  sub      x8, x29, #0x70
static inline uint64_t fde_func_1650_0x0e92b4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e92b4ULL ^ (static_cast<uint64_t>(0xd10883ffULL) << 13);
    acc = (acc + a1 + 0x9103e014ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #1651 | PC: 0x0e9b78 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #1651 | Địa chỉ PC: 0x0e9b78 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0e9b78: D10203FF  sub      sp, sp, #0x80
//   0x0e9b7c: A90367FA  stp      x26, x25, [sp, #0x30]
//   0x0e9b80: A9045FF8  stp      x24, x23, [sp, #0x40]
//   0x0e9b84: A90557F6  stp      x22, x21, [sp, #0x50]
static inline uint64_t fde_func_1651_0x0e9b78(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e9b78ULL ^ (static_cast<uint64_t>(0xd10203ffULL) << 13);
    acc = (acc + a1 + 0xa90367faULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #1652 | PC: 0x0e9cbc | FDE: 0x148a38 | Size: 256 bytes
// Hàm #1652 | Địa chỉ PC: 0x0e9cbc | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0e9cbc: D10503FF  sub      sp, sp, #0x140
//   0x0e9cc0: F90073FC  str      x28, [sp, #0xe0]
//   0x0e9cc4: A90F67FA  stp      x26, x25, [sp, #0xf0]
//   0x0e9cc8: A9105FF8  stp      x24, x23, [sp, #0x100]
static inline uint64_t fde_func_1652_0x0e9cbc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e9cbcULL ^ (static_cast<uint64_t>(0xd10503ffULL) << 13);
    acc = (acc + a1 + 0xf90073fcULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #1653 | PC: 0x0e9e60 | FDE: 0x148a38 | Size: 80 bytes
// Hàm #1653 | Địa chỉ PC: 0x0e9e60 | Địa chỉ FDE: 0x148a38 | Kích thước: 80 bytes
//   0x0e9e60: D100C3FF  sub      sp, sp, #0x30
//   0x0e9e64: F9000BF3  str      x19, [sp, #0x10]
//   0x0e9e68: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0e9e6c: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1653_0x0e9e60(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e9e60ULL ^ (static_cast<uint64_t>(0xd100c3ffULL) << 13);
    acc = (acc + a1 + 0xf9000bf3ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0050ULL;
    return acc;
}

// Func #1654 | PC: 0x0e9eb0 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #1654 | Địa chỉ PC: 0x0e9eb0 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0e9eb0: D10303FF  sub      sp, sp, #0xc0
//   0x0e9eb4: A9085FF8  stp      x24, x23, [sp, #0x80]
//   0x0e9eb8: A90957F6  stp      x22, x21, [sp, #0x90]
//   0x0e9ebc: A90A4FF4  stp      x20, x19, [sp, #0xa0]
static inline uint64_t fde_func_1654_0x0e9eb0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e9eb0ULL ^ (static_cast<uint64_t>(0xd10303ffULL) << 13);
    acc = (acc + a1 + 0xa9085ff8ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #1655 | PC: 0x0ea1bc | FDE: 0x148a38 | Size: 256 bytes
// Hàm #1655 | Địa chỉ PC: 0x0ea1bc | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0ea1bc: D10243FF  sub      sp, sp, #0x90
//   0x0ea1c0: F90033F5  str      x21, [sp, #0x60]
//   0x0ea1c4: A9074FF4  stp      x20, x19, [sp, #0x70]
//   0x0ea1c8: A9087BFD  stp      x29, x30, [sp, #0x80]
static inline uint64_t fde_func_1655_0x0ea1bc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ea1bcULL ^ (static_cast<uint64_t>(0xd10243ffULL) << 13);
    acc = (acc + a1 + 0xf90033f5ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #1656 | PC: 0x0ea2cc | FDE: 0x148a38 | Size: 256 bytes [_ZN3com2ss5ttmio11SocketUtils22convertIpListToAddressENSt6__ndk112basic_stringIcNS3_11char_traitsIcEENS3_9allocatorIcEEEE]
// Hàm #1656 | Địa chỉ PC: 0x0ea2cc | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0ea2cc: D102C3FF  sub      sp, sp, #0xb0
//   0x0ea2d0: A9056FFC  stp      x28, x27, [sp, #0x50]
//   0x0ea2d4: A90667FA  stp      x26, x25, [sp, #0x60]
//   0x0ea2d8: A9075FF8  stp      x24, x23, [sp, #0x70]
static inline uint64_t fde_func_1656_0x0ea2cc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ea2ccULL ^ (static_cast<uint64_t>(0xd102c3ffULL) << 13);
    acc = (acc + a1 + 0xa9056ffcULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #1657 | PC: 0x0ea4e4 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #1657 | Địa chỉ PC: 0x0ea4e4 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0ea4e4: D10303FF  sub      sp, sp, #0xc0
//   0x0ea4e8: A9066FFC  stp      x28, x27, [sp, #0x60]
//   0x0ea4ec: A90767FA  stp      x26, x25, [sp, #0x70]
//   0x0ea4f0: A9085FF8  stp      x24, x23, [sp, #0x80]
static inline uint64_t fde_func_1657_0x0ea4e4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ea4e4ULL ^ (static_cast<uint64_t>(0xd10303ffULL) << 13);
    acc = (acc + a1 + 0xa9066ffcULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #1658 | PC: 0x0ea780 | FDE: 0x148a38 | Size: 136 bytes
// Hàm #1658 | Địa chỉ PC: 0x0ea780 | Địa chỉ FDE: 0x148a38 | Kích thước: 136 bytes
//   0x0ea780: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0ea784: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0ea788: 910043FD  add      x29, sp, #0x10
//   0x0ea78c: AA0103F3  mov      x19, x1
static inline uint64_t fde_func_1658_0x0ea780(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ea780ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0088ULL;
    return acc;
}

// Func #1659 | PC: 0x0ea808 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #1659 | Địa chỉ PC: 0x0ea808 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0ea808: D10503FF  sub      sp, sp, #0x140
//   0x0ea80c: A91157FC  stp      x28, x21, [sp, #0x110]
//   0x0ea810: A9124FF4  stp      x20, x19, [sp, #0x120]
//   0x0ea814: A9137BFD  stp      x29, x30, [sp, #0x130]
static inline uint64_t fde_func_1659_0x0ea808(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ea808ULL ^ (static_cast<uint64_t>(0xd10503ffULL) << 13);
    acc = (acc + a1 + 0xa91157fcULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #1660 | PC: 0x0ea9c0 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #1660 | Địa chỉ PC: 0x0ea9c0 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0ea9c0: D109C3FF  sub      sp, sp, #0x270
//   0x0ea9c4: 910B0014  add      x20, x0, #0x2c0
//   0x0ea9c8: AA0003F3  mov      x19, x0
//   0x0ea9cc: AA1403E0  mov      x0, x20
static inline uint64_t fde_func_1660_0x0ea9c0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ea9c0ULL ^ (static_cast<uint64_t>(0xd109c3ffULL) << 13);
    acc = (acc + a1 + 0x910b0014ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #1661 | PC: 0x0eb040 | FDE: 0x148a38 | Size: 28 bytes
// Hàm #1661 | Địa chỉ PC: 0x0eb040 | Địa chỉ FDE: 0x148a38 | Kích thước: 28 bytes
//   0x0eb040: A9BA6FFC  stp      x28, x27, [sp, #-0x60]!
//   0x0eb044: A90167FA  stp      x26, x25, [sp, #0x10]
//   0x0eb048: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x0eb04c: A90357F6  stp      x22, x21, [sp, #0x30]
static inline uint64_t fde_func_1661_0x0eb040(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0eb040ULL ^ (static_cast<uint64_t>(0xa9ba6ffcULL) << 13);
    acc = (acc + a1 + 0xa90167faULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x001cULL;
    return acc;
}

// Func #1662 | PC: 0x0eb05c | FDE: 0x148a38 | Size: 256 bytes
// Hàm #1662 | Địa chỉ PC: 0x0eb05c | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0eb05c: D10683FF  sub      sp, sp, #0x1a0
//   0x0eb060: D53BD058  mrs      x24, tpidr_el0
//   0x0eb064: F9401709  ldr      x9, [x24, #0x28]
//   0x0eb068: AA0803F4  mov      x20, x8
static inline uint64_t fde_func_1662_0x0eb05c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0eb05cULL ^ (static_cast<uint64_t>(0xd10683ffULL) << 13);
    acc = (acc + a1 + 0xd53bd058ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #1663 | PC: 0x0eb2dc | FDE: 0x148a38 | Size: 256 bytes
// Hàm #1663 | Địa chỉ PC: 0x0eb2dc | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0eb2dc: D10783FF  sub      sp, sp, #0x1e0
//   0x0eb2e0: F900C3FC  str      x28, [sp, #0x180]
//   0x0eb2e4: A91967FA  stp      x26, x25, [sp, #0x190]
//   0x0eb2e8: A91A5FF8  stp      x24, x23, [sp, #0x1a0]
static inline uint64_t fde_func_1663_0x0eb2dc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0eb2dcULL ^ (static_cast<uint64_t>(0xd10783ffULL) << 13);
    acc = (acc + a1 + 0xf900c3fcULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #1664 | PC: 0x0eb568 | FDE: 0x148a38 | Size: 80 bytes
// Hàm #1664 | Địa chỉ PC: 0x0eb568 | Địa chỉ FDE: 0x148a38 | Kích thước: 80 bytes
//   0x0eb568: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0eb56c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0eb570: 910043FD  add      x29, sp, #0x10
//   0x0eb574: A9405028  ldp      x8, x20, [x1]
static inline uint64_t fde_func_1664_0x0eb568(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0eb568ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0050ULL;
    return acc;
}

// Func #1665 | PC: 0x0eb5b8 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #1665 | Địa chỉ PC: 0x0eb5b8 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0eb5b8: D10243FF  sub      sp, sp, #0x90
//   0x0eb5bc: A9036FFC  stp      x28, x27, [sp, #0x30]
//   0x0eb5c0: A90467FA  stp      x26, x25, [sp, #0x40]
//   0x0eb5c4: A9055FF8  stp      x24, x23, [sp, #0x50]
static inline uint64_t fde_func_1665_0x0eb5b8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0eb5b8ULL ^ (static_cast<uint64_t>(0xd10243ffULL) << 13);
    acc = (acc + a1 + 0xa9036ffcULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #1666 | PC: 0x0eb798 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #1666 | Địa chỉ PC: 0x0eb798 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0eb798: D10103FF  sub      sp, sp, #0x40
//   0x0eb79c: F9000BF5  str      x21, [sp, #0x10]
//   0x0eb7a0: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x0eb7a4: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_1666_0x0eb798(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0eb798ULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xf9000bf5ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #1667 | PC: 0x0eb8cc | FDE: 0x148a38 | Size: 256 bytes
// Hàm #1667 | Địa chỉ PC: 0x0eb8cc | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0eb8cc: D10283FF  sub      sp, sp, #0xa0
//   0x0eb8d0: F9003BF5  str      x21, [sp, #0x70]
//   0x0eb8d4: A9084FF4  stp      x20, x19, [sp, #0x80]
//   0x0eb8d8: A9097BFD  stp      x29, x30, [sp, #0x90]
static inline uint64_t fde_func_1667_0x0eb8cc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0eb8ccULL ^ (static_cast<uint64_t>(0xd10283ffULL) << 13);
    acc = (acc + a1 + 0xf9003bf5ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #1668 | PC: 0x0ebbc4 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #1668 | Địa chỉ PC: 0x0ebbc4 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0ebbc4: D102C3FF  sub      sp, sp, #0xb0
//   0x0ebbc8: F90033F9  str      x25, [sp, #0x60]
//   0x0ebbcc: A9075FF8  stp      x24, x23, [sp, #0x70]
//   0x0ebbd0: A90857F6  stp      x22, x21, [sp, #0x80]
static inline uint64_t fde_func_1668_0x0ebbc4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ebbc4ULL ^ (static_cast<uint64_t>(0xd102c3ffULL) << 13);
    acc = (acc + a1 + 0xf90033f9ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #1669 | PC: 0x0ebe54 | FDE: 0x148a38 | Size: 36 bytes
// Hàm #1669 | Địa chỉ PC: 0x0ebe54 | Địa chỉ FDE: 0x148a38 | Kích thước: 36 bytes
//   0x0ebe54: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x0ebe58: 910003FD  mov      x29, sp
//   0x0ebe5c: 91102000  add      x0, x0, #0x408
//   0x0ebe60: 94000BCD  bl       #0xeed94
static inline uint64_t fde_func_1669_0x0ebe54(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ebe54ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0024ULL;
    return acc;
}

// Func #1670 | PC: 0x0ebe78 | FDE: 0x148a38 | Size: 96 bytes
// Hàm #1670 | Địa chỉ PC: 0x0ebe78 | Địa chỉ FDE: 0x148a38 | Kích thước: 96 bytes
//   0x0ebe78: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x0ebe7c: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0ebe80: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0ebe84: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1670_0x0ebe78(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ebe78ULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0060ULL;
    return acc;
}

// Func #1671 | PC: 0x0ebed8 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #1671 | Địa chỉ PC: 0x0ebed8 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0ebed8: D104C3FF  sub      sp, sp, #0x130
//   0x0ebedc: A90D6FFC  stp      x28, x27, [sp, #0xd0]
//   0x0ebee0: A90E67FA  stp      x26, x25, [sp, #0xe0]
//   0x0ebee4: A90F5FF8  stp      x24, x23, [sp, #0xf0]
static inline uint64_t fde_func_1671_0x0ebed8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ebed8ULL ^ (static_cast<uint64_t>(0xd104c3ffULL) << 13);
    acc = (acc + a1 + 0xa90d6ffcULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #1672 | PC: 0x0ec0d8 | FDE: 0x148a38 | Size: 104 bytes
// Hàm #1672 | Địa chỉ PC: 0x0ec0d8 | Địa chỉ FDE: 0x148a38 | Kích thước: 104 bytes
//   0x0ec0d8: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x0ec0dc: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0ec0e0: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0ec0e4: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1672_0x0ec0d8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ec0d8ULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0068ULL;
    return acc;
}

// Func #1673 | PC: 0x0ec140 | FDE: 0x148a38 | Size: 152 bytes
// Hàm #1673 | Địa chỉ PC: 0x0ec140 | Địa chỉ FDE: 0x148a38 | Kích thước: 152 bytes
//   0x0ec140: D100C3FF  sub      sp, sp, #0x30
//   0x0ec144: F9000BF3  str      x19, [sp, #0x10]
//   0x0ec148: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0ec14c: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1673_0x0ec140(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ec140ULL ^ (static_cast<uint64_t>(0xd100c3ffULL) << 13);
    acc = (acc + a1 + 0xf9000bf3ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0098ULL;
    return acc;
}

// Func #1674 | PC: 0x0ec1d8 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #1674 | Địa chỉ PC: 0x0ec1d8 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0ec1d8: D101C3FF  sub      sp, sp, #0x70
//   0x0ec1dc: F9001BF7  str      x23, [sp, #0x30]
//   0x0ec1e0: A90457F6  stp      x22, x21, [sp, #0x40]
//   0x0ec1e4: A9054FF4  stp      x20, x19, [sp, #0x50]
static inline uint64_t fde_func_1674_0x0ec1d8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ec1d8ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xf9001bf7ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #1675 | PC: 0x0ec340 | FDE: 0x148a38 | Size: 180 bytes
// Hàm #1675 | Địa chỉ PC: 0x0ec340 | Địa chỉ FDE: 0x148a38 | Kích thước: 180 bytes
//   0x0ec340: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x0ec344: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0ec348: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0ec34c: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1675_0x0ec340(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ec340ULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x00b4ULL;
    return acc;
}

// Func #1676 | PC: 0x0ec3f4 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #1676 | Địa chỉ PC: 0x0ec3f4 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0ec3f4: D10143FF  sub      sp, sp, #0x50
//   0x0ec3f8: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x0ec3fc: A9047BFD  stp      x29, x30, [sp, #0x40]
//   0x0ec400: 910103FD  add      x29, sp, #0x40
static inline uint64_t fde_func_1676_0x0ec3f4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ec3f4ULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xa9034ff4ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #1677 | PC: 0x0ec590 | FDE: 0x148a38 | Size: 120 bytes
// Hàm #1677 | Địa chỉ PC: 0x0ec590 | Địa chỉ FDE: 0x148a38 | Kích thước: 120 bytes
//   0x0ec590: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0ec594: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0ec598: 910043FD  add      x29, sp, #0x10
//   0x0ec59c: B4000121  cbz      x1, #0xec5c0
static inline uint64_t fde_func_1677_0x0ec590(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ec590ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0078ULL;
    return acc;
}

// Func #1678 | PC: 0x0ec608 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #1678 | Địa chỉ PC: 0x0ec608 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0ec608: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0ec60c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0ec610: 910043FD  add      x29, sp, #0x10
//   0x0ec614: B4000161  cbz      x1, #0xec640
static inline uint64_t fde_func_1678_0x0ec608(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ec608ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #1679 | PC: 0x0ec840 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #1679 | Địa chỉ PC: 0x0ec840 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0ec840: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0ec844: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0ec848: 910043FD  add      x29, sp, #0x10
//   0x0ec84c: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_1679_0x0ec840(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ec840ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #1680 | PC: 0x0ecb30 | FDE: 0x148a38 | Size: 80 bytes
// Hàm #1680 | Địa chỉ PC: 0x0ecb30 | Địa chỉ FDE: 0x148a38 | Kích thước: 80 bytes
//   0x0ecb30: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0ecb34: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0ecb38: 910043FD  add      x29, sp, #0x10
//   0x0ecb3c: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_1680_0x0ecb30(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ecb30ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0050ULL;
    return acc;
}

// Func #1681 | PC: 0x0ecb80 | FDE: 0x148a38 | Size: 140 bytes
// Hàm #1681 | Địa chỉ PC: 0x0ecb80 | Địa chỉ FDE: 0x148a38 | Kích thước: 140 bytes
//   0x0ecb80: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0ecb84: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0ecb88: 910043FD  add      x29, sp, #0x10
//   0x0ecb8c: F0000348  adrp     x8, #0x157000
static inline uint64_t fde_func_1681_0x0ecb80(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ecb80ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x008cULL;
    return acc;
}

// Func #1682 | PC: 0x0ecc0c | FDE: 0x148a38 | Size: 256 bytes
// Hàm #1682 | Địa chỉ PC: 0x0ecc0c | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0ecc0c: D10103FF  sub      sp, sp, #0x40
//   0x0ecc10: F9000BF5  str      x21, [sp, #0x10]
//   0x0ecc14: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x0ecc18: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_1682_0x0ecc0c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ecc0cULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xf9000bf5ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #1683 | PC: 0x0ece6c | FDE: 0x148a38 | Size: 256 bytes
// Hàm #1683 | Địa chỉ PC: 0x0ece6c | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0ece6c: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0ece70: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0ece74: 910043FD  add      x29, sp, #0x10
//   0x0ece78: AA0003F4  mov      x20, x0
static inline uint64_t fde_func_1683_0x0ece6c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ece6cULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #1684 | PC: 0x0ecfb0 | FDE: 0x148a38 | Size: 128 bytes
// Hàm #1684 | Địa chỉ PC: 0x0ecfb0 | Địa chỉ FDE: 0x148a38 | Kích thước: 128 bytes
//   0x0ecfb0: D100C3FF  sub      sp, sp, #0x30
//   0x0ecfb4: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0ecfb8: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0ecfbc: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1684_0x0ecfb0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ecfb0ULL ^ (static_cast<uint64_t>(0xd100c3ffULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0080ULL;
    return acc;
}

// Func #1685 | PC: 0x0ed030 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #1685 | Địa chỉ PC: 0x0ed030 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0ed030: D100C3FF  sub      sp, sp, #0x30
//   0x0ed034: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0ed038: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0ed03c: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1685_0x0ed030(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ed030ULL ^ (static_cast<uint64_t>(0xd100c3ffULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #1686 | PC: 0x0ed3c0 | FDE: 0x148a38 | Size: 192 bytes
// Hàm #1686 | Địa chỉ PC: 0x0ed3c0 | Địa chỉ FDE: 0x148a38 | Kích thước: 192 bytes
//   0x0ed3c0: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0ed3c4: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0ed3c8: 910043FD  add      x29, sp, #0x10
//   0x0ed3cc: AA0003F4  mov      x20, x0
static inline uint64_t fde_func_1686_0x0ed3c0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ed3c0ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x00c0ULL;
    return acc;
}

// Func #1687 | PC: 0x0ed480 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #1687 | Địa chỉ PC: 0x0ed480 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0ed480: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x0ed484: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0ed488: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0ed48c: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1687_0x0ed480(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ed480ULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #1688 | PC: 0x0ed620 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #1688 | Địa chỉ PC: 0x0ed620 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0ed620: D10203FF  sub      sp, sp, #0x80
//   0x0ed624: A9026FFC  stp      x28, x27, [sp, #0x20]
//   0x0ed628: A90367FA  stp      x26, x25, [sp, #0x30]
//   0x0ed62c: A9045FF8  stp      x24, x23, [sp, #0x40]
static inline uint64_t fde_func_1688_0x0ed620(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ed620ULL ^ (static_cast<uint64_t>(0xd10203ffULL) << 13);
    acc = (acc + a1 + 0xa9026ffcULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #1689 | PC: 0x0ed9e0 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #1689 | Địa chỉ PC: 0x0ed9e0 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0ed9e0: D10203FF  sub      sp, sp, #0x80
//   0x0ed9e4: A9026FFC  stp      x28, x27, [sp, #0x20]
//   0x0ed9e8: A90367FA  stp      x26, x25, [sp, #0x30]
//   0x0ed9ec: A9045FF8  stp      x24, x23, [sp, #0x40]
static inline uint64_t fde_func_1689_0x0ed9e0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ed9e0ULL ^ (static_cast<uint64_t>(0xd10203ffULL) << 13);
    acc = (acc + a1 + 0xa9026ffcULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #1690 | PC: 0x0edc34 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #1690 | Địa chỉ PC: 0x0edc34 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0edc34: D10243FF  sub      sp, sp, #0x90
//   0x0edc38: A9036FFC  stp      x28, x27, [sp, #0x30]
//   0x0edc3c: A90467FA  stp      x26, x25, [sp, #0x40]
//   0x0edc40: A9055FF8  stp      x24, x23, [sp, #0x50]
static inline uint64_t fde_func_1690_0x0edc34(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0edc34ULL ^ (static_cast<uint64_t>(0xd10243ffULL) << 13);
    acc = (acc + a1 + 0xa9036ffcULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #1691 | PC: 0x0edff0 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #1691 | Địa chỉ PC: 0x0edff0 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0edff0: D10183FF  sub      sp, sp, #0x60
//   0x0edff4: A90167FA  stp      x26, x25, [sp, #0x10]
//   0x0edff8: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x0edffc: A90357F6  stp      x22, x21, [sp, #0x30]
static inline uint64_t fde_func_1691_0x0edff0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0edff0ULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xa90167faULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #1692 | PC: 0x0ee244 | FDE: 0x148a38 | Size: 132 bytes
// Hàm #1692 | Địa chỉ PC: 0x0ee244 | Địa chỉ FDE: 0x148a38 | Kích thước: 132 bytes
//   0x0ee244: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0ee248: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0ee24c: 910043FD  add      x29, sp, #0x10
//   0x0ee250: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_1692_0x0ee244(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ee244ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0084ULL;
    return acc;
}

// Func #1693 | PC: 0x0ee2c8 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #1693 | Địa chỉ PC: 0x0ee2c8 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0ee2c8: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0ee2cc: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0ee2d0: 910043FD  add      x29, sp, #0x10
//   0x0ee2d4: B0000368  adrp     x8, #0x15b000
static inline uint64_t fde_func_1693_0x0ee2c8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ee2c8ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #1694 | PC: 0x0ee3d8 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #1694 | Địa chỉ PC: 0x0ee3d8 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0ee3d8: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0ee3dc: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0ee3e0: 910043FD  add      x29, sp, #0x10
//   0x0ee3e4: AA0003F4  mov      x20, x0
static inline uint64_t fde_func_1694_0x0ee3d8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ee3d8ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #1695 | PC: 0x0ee55c | FDE: 0x148a38 | Size: 132 bytes
// Hàm #1695 | Địa chỉ PC: 0x0ee55c | Địa chỉ FDE: 0x148a38 | Kích thước: 132 bytes
//   0x0ee55c: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0ee560: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0ee564: 910043FD  add      x29, sp, #0x10
//   0x0ee568: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_1695_0x0ee55c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ee55cULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0084ULL;
    return acc;
}

// Func #1696 | PC: 0x0ee5e0 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #1696 | Địa chỉ PC: 0x0ee5e0 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0ee5e0: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0ee5e4: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0ee5e8: 910043FD  add      x29, sp, #0x10
//   0x0ee5ec: B0000368  adrp     x8, #0x15b000
static inline uint64_t fde_func_1696_0x0ee5e0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ee5e0ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #1697 | PC: 0x0ee6f0 | FDE: 0x148a38 | Size: 200 bytes
// Hàm #1697 | Địa chỉ PC: 0x0ee6f0 | Địa chỉ FDE: 0x148a38 | Kích thước: 200 bytes
//   0x0ee6f0: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0ee6f4: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0ee6f8: 910043FD  add      x29, sp, #0x10
//   0x0ee6fc: AA0003F4  mov      x20, x0
static inline uint64_t fde_func_1697_0x0ee6f0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ee6f0ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x00c8ULL;
    return acc;
}

// Func #1698 | PC: 0x0ee7b8 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #1698 | Địa chỉ PC: 0x0ee7b8 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0ee7b8: D101C3FF  sub      sp, sp, #0x70
//   0x0ee7bc: F90013F9  str      x25, [sp, #0x20]
//   0x0ee7c0: A9035FF8  stp      x24, x23, [sp, #0x30]
//   0x0ee7c4: A90457F6  stp      x22, x21, [sp, #0x40]
static inline uint64_t fde_func_1698_0x0ee7b8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ee7b8ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xf90013f9ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #1699 | PC: 0x0eead8 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #1699 | Địa chỉ PC: 0x0eead8 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0eead8: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0eeadc: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0eeae0: 910043FD  add      x29, sp, #0x10
//   0x0eeae4: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_1699_0x0eead8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0eead8ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #1700 | PC: 0x0eef28 | FDE: 0x148a38 | Size: 84 bytes
// Hàm #1700 | Địa chỉ PC: 0x0eef28 | Địa chỉ FDE: 0x148a38 | Kích thước: 84 bytes
//   0x0eef28: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0eef2c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0eef30: 910043FD  add      x29, sp, #0x10
//   0x0eef34: F9400808  ldr      x8, [x0, #0x10]
static inline uint64_t fde_func_1700_0x0eef28(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0eef28ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0054ULL;
    return acc;
}

// Func #1701 | PC: 0x0eef7c | FDE: 0x148a38 | Size: 256 bytes
// Hàm #1701 | Địa chỉ PC: 0x0eef7c | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0eef7c: D101C3FF  sub      sp, sp, #0x70
//   0x0eef80: F90013F9  str      x25, [sp, #0x20]
//   0x0eef84: A9035FF8  stp      x24, x23, [sp, #0x30]
//   0x0eef88: A90457F6  stp      x22, x21, [sp, #0x40]
static inline uint64_t fde_func_1701_0x0eef7c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0eef7cULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xf90013f9ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #1702 | PC: 0x0ef2dc | FDE: 0x148a38 | Size: 256 bytes
// Hàm #1702 | Địa chỉ PC: 0x0ef2dc | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0ef2dc: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0ef2e0: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0ef2e4: 910043FD  add      x29, sp, #0x10
//   0x0ef2e8: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_1702_0x0ef2dc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ef2dcULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #1703 | PC: 0x0ef594 | FDE: 0x148a38 | Size: 128 bytes
// Hàm #1703 | Địa chỉ PC: 0x0ef594 | Địa chỉ FDE: 0x148a38 | Kích thước: 128 bytes
//   0x0ef594: D100C3FF  sub      sp, sp, #0x30
//   0x0ef598: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0ef59c: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0ef5a0: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1703_0x0ef594(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ef594ULL ^ (static_cast<uint64_t>(0xd100c3ffULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0080ULL;
    return acc;
}

// Func #1704 | PC: 0x0ef614 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #1704 | Địa chỉ PC: 0x0ef614 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0ef614: D100C3FF  sub      sp, sp, #0x30
//   0x0ef618: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0ef61c: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0ef620: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1704_0x0ef614(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ef614ULL ^ (static_cast<uint64_t>(0xd100c3ffULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #1705 | PC: 0x0ef9a4 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #1705 | Địa chỉ PC: 0x0ef9a4 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0ef9a4: D10483FF  sub      sp, sp, #0x120
//   0x0ef9a8: F9007BFC  str      x28, [sp, #0xf0]
//   0x0ef9ac: A9104FF4  stp      x20, x19, [sp, #0x100]
//   0x0ef9b0: A9117BFD  stp      x29, x30, [sp, #0x110]
static inline uint64_t fde_func_1705_0x0ef9a4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ef9a4ULL ^ (static_cast<uint64_t>(0xd10483ffULL) << 13);
    acc = (acc + a1 + 0xf9007bfcULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #1706 | PC: 0x0efbb0 | FDE: 0x148a38 | Size: 124 bytes
// Hàm #1706 | Địa chỉ PC: 0x0efbb0 | Địa chỉ FDE: 0x148a38 | Kích thước: 124 bytes
//   0x0efbb0: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x0efbb4: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0efbb8: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0efbbc: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1706_0x0efbb0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0efbb0ULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x007cULL;
    return acc;
}

// Func #1707 | PC: 0x0efc2c | FDE: 0x148a38 | Size: 108 bytes
// Hàm #1707 | Địa chỉ PC: 0x0efc2c | Địa chỉ FDE: 0x148a38 | Kích thước: 108 bytes
//   0x0efc2c: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0efc30: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0efc34: 910043FD  add      x29, sp, #0x10
//   0x0efc38: B9400008  ldr      w8, [x0]
static inline uint64_t fde_func_1707_0x0efc2c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0efc2cULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x006cULL;
    return acc;
}

// Func #1708 | PC: 0x0efc98 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #1708 | Địa chỉ PC: 0x0efc98 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0efc98: D10183FF  sub      sp, sp, #0x60
//   0x0efc9c: F90013F7  str      x23, [sp, #0x20]
//   0x0efca0: A90357F6  stp      x22, x21, [sp, #0x30]
//   0x0efca4: A9044FF4  stp      x20, x19, [sp, #0x40]
static inline uint64_t fde_func_1708_0x0efc98(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0efc98ULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xf90013f7ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #1709 | PC: 0x0efdf4 | FDE: 0x148a38 | Size: 216 bytes
// Hàm #1709 | Địa chỉ PC: 0x0efdf4 | Địa chỉ FDE: 0x148a38 | Kích thước: 216 bytes
//   0x0efdf4: A9BB67FA  stp      x26, x25, [sp, #-0x50]!
//   0x0efdf8: A9015FF8  stp      x24, x23, [sp, #0x10]
//   0x0efdfc: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x0efe00: A9034FF4  stp      x20, x19, [sp, #0x30]
static inline uint64_t fde_func_1709_0x0efdf4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0efdf4ULL ^ (static_cast<uint64_t>(0xa9bb67faULL) << 13);
    acc = (acc + a1 + 0xa9015ff8ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x00d8ULL;
    return acc;
}

// Func #1710 | PC: 0x0efecc | FDE: 0x148a38 | Size: 256 bytes
// Hàm #1710 | Địa chỉ PC: 0x0efecc | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0efecc: D101C3FF  sub      sp, sp, #0x70
//   0x0efed0: F90013F9  str      x25, [sp, #0x20]
//   0x0efed4: A9035FF8  stp      x24, x23, [sp, #0x30]
//   0x0efed8: A90457F6  stp      x22, x21, [sp, #0x40]
static inline uint64_t fde_func_1710_0x0efecc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0efeccULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xf90013f9ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #1711 | PC: 0x0f0090 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #1711 | Địa chỉ PC: 0x0f0090 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0f0090: D10103FF  sub      sp, sp, #0x40
//   0x0f0094: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x0f0098: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x0f009c: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_1711_0x0f0090(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0f0090ULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #1712 | PC: 0x0f01c0 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #1712 | Địa chỉ PC: 0x0f01c0 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0f01c0: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0f01c4: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0f01c8: 910043FD  add      x29, sp, #0x10
//   0x0f01cc: F9400808  ldr      x8, [x0, #0x10]
static inline uint64_t fde_func_1712_0x0f01c0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0f01c0ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #1713 | PC: 0x0f0588 | FDE: 0x148a38 | Size: 120 bytes
// Hàm #1713 | Địa chỉ PC: 0x0f0588 | Địa chỉ FDE: 0x148a38 | Kích thước: 120 bytes
//   0x0f0588: D10103FF  sub      sp, sp, #0x40
//   0x0f058c: F9000BF5  str      x21, [sp, #0x10]
//   0x0f0590: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x0f0594: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_1713_0x0f0588(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0f0588ULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xf9000bf5ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0078ULL;
    return acc;
}

// Func #1714 | PC: 0x0f0600 | FDE: 0x148a38 | Size: 120 bytes
// Hàm #1714 | Địa chỉ PC: 0x0f0600 | Địa chỉ FDE: 0x148a38 | Kích thước: 120 bytes
//   0x0f0600: D100C3FF  sub      sp, sp, #0x30
//   0x0f0604: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0f0608: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0f060c: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1714_0x0f0600(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0f0600ULL ^ (static_cast<uint64_t>(0xd100c3ffULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0078ULL;
    return acc;
}

// Func #1715 | PC: 0x0f0678 | FDE: 0x148a38 | Size: 52 bytes
// Hàm #1715 | Địa chỉ PC: 0x0f0678 | Địa chỉ FDE: 0x148a38 | Kích thước: 52 bytes
//   0x0f0678: D10083FF  sub      sp, sp, #0x20
//   0x0f067c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0f0680: 910043FD  add      x29, sp, #0x10
//   0x0f0684: AA0103E2  mov      x2, x1
static inline uint64_t fde_func_1715_0x0f0678(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0f0678ULL ^ (static_cast<uint64_t>(0xd10083ffULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0034ULL;
    return acc;
}

// Func #1716 | PC: 0x0f06ac | FDE: 0x148a38 | Size: 76 bytes
// Hàm #1716 | Địa chỉ PC: 0x0f06ac | Địa chỉ FDE: 0x148a38 | Kích thước: 76 bytes
//   0x0f06ac: D100C3FF  sub      sp, sp, #0x30
//   0x0f06b0: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0f06b4: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0f06b8: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1716_0x0f06ac(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0f06acULL ^ (static_cast<uint64_t>(0xd100c3ffULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x004cULL;
    return acc;
}

// Func #1717 | PC: 0x0f06f8 | FDE: 0x148a38 | Size: 200 bytes
// Hàm #1717 | Địa chỉ PC: 0x0f06f8 | Địa chỉ FDE: 0x148a38 | Kích thước: 200 bytes
//   0x0f06f8: D100C3FF  sub      sp, sp, #0x30
//   0x0f06fc: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0f0700: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0f0704: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1717_0x0f06f8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0f06f8ULL ^ (static_cast<uint64_t>(0xd100c3ffULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x00c8ULL;
    return acc;
}

// Func #1718 | PC: 0x0f07c0 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #1718 | Địa chỉ PC: 0x0f07c0 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0f07c0: D10203FF  sub      sp, sp, #0x80
//   0x0f07c4: F90013FB  str      x27, [sp, #0x20]
//   0x0f07c8: A90367FA  stp      x26, x25, [sp, #0x30]
//   0x0f07cc: A9045FF8  stp      x24, x23, [sp, #0x40]
static inline uint64_t fde_func_1718_0x0f07c0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0f07c0ULL ^ (static_cast<uint64_t>(0xd10203ffULL) << 13);
    acc = (acc + a1 + 0xf90013fbULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #1719 | PC: 0x0f0b94 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #1719 | Địa chỉ PC: 0x0f0b94 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0f0b94: D10203FF  sub      sp, sp, #0x80
//   0x0f0b98: A90367FA  stp      x26, x25, [sp, #0x30]
//   0x0f0b9c: A9045FF8  stp      x24, x23, [sp, #0x40]
//   0x0f0ba0: A90557F6  stp      x22, x21, [sp, #0x50]
static inline uint64_t fde_func_1719_0x0f0b94(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0f0b94ULL ^ (static_cast<uint64_t>(0xd10203ffULL) << 13);
    acc = (acc + a1 + 0xa90367faULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #1720 | PC: 0x0f108c | FDE: 0x148a38 | Size: 256 bytes
// Hàm #1720 | Địa chỉ PC: 0x0f108c | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0f108c: D10203FF  sub      sp, sp, #0x80
//   0x0f1090: A90367FA  stp      x26, x25, [sp, #0x30]
//   0x0f1094: A9045FF8  stp      x24, x23, [sp, #0x40]
//   0x0f1098: A90557F6  stp      x22, x21, [sp, #0x50]
static inline uint64_t fde_func_1720_0x0f108c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0f108cULL ^ (static_cast<uint64_t>(0xd10203ffULL) << 13);
    acc = (acc + a1 + 0xa90367faULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #1721 | PC: 0x0f1284 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #1721 | Địa chỉ PC: 0x0f1284 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0f1284: D10143FF  sub      sp, sp, #0x50
//   0x0f1288: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x0f128c: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x0f1290: A9047BFD  stp      x29, x30, [sp, #0x40]
static inline uint64_t fde_func_1721_0x0f1284(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0f1284ULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xa90257f6ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #1722 | PC: 0x0f1414 | FDE: 0x148a38 | Size: 192 bytes
// Hàm #1722 | Địa chỉ PC: 0x0f1414 | Địa chỉ FDE: 0x148a38 | Kích thước: 192 bytes
//   0x0f1414: D10143FF  sub      sp, sp, #0x50
//   0x0f1418: A901D7FF  stp      xzr, x21, [sp, #0x18]
//   0x0f141c: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x0f1420: A9047BFD  stp      x29, x30, [sp, #0x40]
static inline uint64_t fde_func_1722_0x0f1414(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0f1414ULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xa901d7ffULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x00c0ULL;
    return acc;
}

// Func #1723 | PC: 0x0f14d4 | FDE: 0x148a38 | Size: 68 bytes
// Hàm #1723 | Địa chỉ PC: 0x0f14d4 | Địa chỉ FDE: 0x148a38 | Kích thước: 68 bytes
//   0x0f14d4: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0f14d8: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0f14dc: 910043FD  add      x29, sp, #0x10
//   0x0f14e0: 91022014  add      x20, x0, #0x88
static inline uint64_t fde_func_1723_0x0f14d4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0f14d4ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0044ULL;
    return acc;
}

// Func #1724 | PC: 0x0f1518 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #1724 | Địa chỉ PC: 0x0f1518 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0f1518: D10103FF  sub      sp, sp, #0x40
//   0x0f151c: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x0f1520: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x0f1524: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_1724_0x0f1518(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0f1518ULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #1725 | PC: 0x0f1668 | FDE: 0x148a38 | Size: 96 bytes
// Hàm #1725 | Địa chỉ PC: 0x0f1668 | Địa chỉ FDE: 0x148a38 | Kích thước: 96 bytes
//   0x0f1668: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0f166c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0f1670: 910043FD  add      x29, sp, #0x10
//   0x0f1674: F9400808  ldr      x8, [x0, #0x10]
static inline uint64_t fde_func_1725_0x0f1668(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0f1668ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0060ULL;
    return acc;
}

// Func #1726 | PC: 0x0f16c8 | FDE: 0x148a38 | Size: 64 bytes
// Hàm #1726 | Địa chỉ PC: 0x0f16c8 | Địa chỉ FDE: 0x148a38 | Kích thước: 64 bytes
//   0x0f16c8: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0f16cc: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0f16d0: 910043FD  add      x29, sp, #0x10
//   0x0f16d4: AA0103F3  mov      x19, x1
static inline uint64_t fde_func_1726_0x0f16c8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0f16c8ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0040ULL;
    return acc;
}

// Func #1727 | PC: 0x0f1708 | FDE: 0x148a38 | Size: 76 bytes
// Hàm #1727 | Địa chỉ PC: 0x0f1708 | Địa chỉ FDE: 0x148a38 | Kích thước: 76 bytes
//   0x0f1708: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0f170c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0f1710: 910043FD  add      x29, sp, #0x10
//   0x0f1714: AA0103F3  mov      x19, x1
static inline uint64_t fde_func_1727_0x0f1708(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0f1708ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x004cULL;
    return acc;
}

// Func #1728 | PC: 0x0f1754 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #1728 | Địa chỉ PC: 0x0f1754 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0f1754: D10103FF  sub      sp, sp, #0x40
//   0x0f1758: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x0f175c: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x0f1760: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_1728_0x0f1754(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0f1754ULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #1729 | PC: 0x0f18d0 | FDE: 0x148a38 | Size: 104 bytes
// Hàm #1729 | Địa chỉ PC: 0x0f18d0 | Địa chỉ FDE: 0x148a38 | Kích thước: 104 bytes
//   0x0f18d0: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x0f18d4: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0f18d8: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0f18dc: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1729_0x0f18d0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0f18d0ULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0068ULL;
    return acc;
}

// Func #1730 | PC: 0x0f1938 | FDE: 0x148a38 | Size: 80 bytes
// Hàm #1730 | Địa chỉ PC: 0x0f1938 | Địa chỉ FDE: 0x148a38 | Kích thước: 80 bytes
//   0x0f1938: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0f193c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0f1940: 910043FD  add      x29, sp, #0x10
//   0x0f1944: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_1730_0x0f1938(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0f1938ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0050ULL;
    return acc;
}

// Func #1731 | PC: 0x0f1988 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #1731 | Địa chỉ PC: 0x0f1988 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0f1988: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x0f198c: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0f1990: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0f1994: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1731_0x0f1988(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0f1988ULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #1732 | PC: 0x0f1bb4 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #1732 | Địa chỉ PC: 0x0f1bb4 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0f1bb4: A9BC5FF8  stp      x24, x23, [sp, #-0x40]!
//   0x0f1bb8: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x0f1bbc: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x0f1bc0: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_1732_0x0f1bb4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0f1bb4ULL ^ (static_cast<uint64_t>(0xa9bc5ff8ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #1733 | PC: 0x0f1cc0 | FDE: 0x148a38 | Size: 196 bytes
// Hàm #1733 | Địa chỉ PC: 0x0f1cc0 | Địa chỉ FDE: 0x148a38 | Kích thước: 196 bytes
//   0x0f1cc0: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0f1cc4: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0f1cc8: 910043FD  add      x29, sp, #0x10
//   0x0f1ccc: AA0103F3  mov      x19, x1
static inline uint64_t fde_func_1733_0x0f1cc0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0f1cc0ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x00c4ULL;
    return acc;
}

// Func #1734 | PC: 0x0f1d84 | FDE: 0x148a38 | Size: 136 bytes
// Hàm #1734 | Địa chỉ PC: 0x0f1d84 | Địa chỉ FDE: 0x148a38 | Kích thước: 136 bytes
//   0x0f1d84: D10103FF  sub      sp, sp, #0x40
//   0x0f1d88: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x0f1d8c: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x0f1d90: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_1734_0x0f1d84(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0f1d84ULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0088ULL;
    return acc;
}

// Func #1735 | PC: 0x0f1e0c | FDE: 0x148a38 | Size: 256 bytes
// Hàm #1735 | Địa chỉ PC: 0x0f1e0c | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0f1e0c: A9BA6FFC  stp      x28, x27, [sp, #-0x60]!
//   0x0f1e10: A90167FA  stp      x26, x25, [sp, #0x10]
//   0x0f1e14: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x0f1e18: A90357F6  stp      x22, x21, [sp, #0x30]
static inline uint64_t fde_func_1735_0x0f1e0c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0f1e0cULL ^ (static_cast<uint64_t>(0xa9ba6ffcULL) << 13);
    acc = (acc + a1 + 0xa90167faULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #1736 | PC: 0x0f20a4 | FDE: 0x148a38 | Size: 60 bytes
// Hàm #1736 | Địa chỉ PC: 0x0f20a4 | Địa chỉ FDE: 0x148a38 | Kích thước: 60 bytes
//   0x0f20a4: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0f20a8: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0f20ac: 910043FD  add      x29, sp, #0x10
//   0x0f20b0: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_1736_0x0f20a4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0f20a4ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x003cULL;
    return acc;
}

// Func #1737 | PC: 0x0f20e0 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #1737 | Địa chỉ PC: 0x0f20e0 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0f20e0: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x0f20e4: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0f20e8: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0f20ec: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1737_0x0f20e0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0f20e0ULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #1738 | PC: 0x0f248c | FDE: 0x148a38 | Size: 256 bytes
// Hàm #1738 | Địa chỉ PC: 0x0f248c | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0f248c: A9BA6FFC  stp      x28, x27, [sp, #-0x60]!
//   0x0f2490: A90167FA  stp      x26, x25, [sp, #0x10]
//   0x0f2494: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x0f2498: A90357F6  stp      x22, x21, [sp, #0x30]
static inline uint64_t fde_func_1738_0x0f248c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0f248cULL ^ (static_cast<uint64_t>(0xa9ba6ffcULL) << 13);
    acc = (acc + a1 + 0xa90167faULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #1739 | PC: 0x0f2608 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #1739 | Địa chỉ PC: 0x0f2608 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0f2608: D10603FF  sub      sp, sp, #0x180
//   0x0f260c: A9126FFC  stp      x28, x27, [sp, #0x120]
//   0x0f2610: A91367FA  stp      x26, x25, [sp, #0x130]
//   0x0f2614: A9145FF8  stp      x24, x23, [sp, #0x140]
static inline uint64_t fde_func_1739_0x0f2608(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0f2608ULL ^ (static_cast<uint64_t>(0xd10603ffULL) << 13);
    acc = (acc + a1 + 0xa9126ffcULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #1740 | PC: 0x0f2850 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #1740 | Địa chỉ PC: 0x0f2850 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0f2850: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0f2854: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0f2858: 910043FD  add      x29, sp, #0x10
//   0x0f285c: AA0003F4  mov      x20, x0
static inline uint64_t fde_func_1740_0x0f2850(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0f2850ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #1741 | PC: 0x0f2cd4 | FDE: 0x148a38 | Size: 204 bytes
// Hàm #1741 | Địa chỉ PC: 0x0f2cd4 | Địa chỉ FDE: 0x148a38 | Kích thước: 204 bytes
//   0x0f2cd4: D100C3FF  sub      sp, sp, #0x30
//   0x0f2cd8: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0f2cdc: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0f2ce0: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1741_0x0f2cd4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0f2cd4ULL ^ (static_cast<uint64_t>(0xd100c3ffULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x00ccULL;
    return acc;
}

// Func #1742 | PC: 0x0f2da0 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #1742 | Địa chỉ PC: 0x0f2da0 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0f2da0: D10243FF  sub      sp, sp, #0x90
//   0x0f2da4: A9036FFC  stp      x28, x27, [sp, #0x30]
//   0x0f2da8: A90467FA  stp      x26, x25, [sp, #0x40]
//   0x0f2dac: A9055FF8  stp      x24, x23, [sp, #0x50]
static inline uint64_t fde_func_1742_0x0f2da0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0f2da0ULL ^ (static_cast<uint64_t>(0xd10243ffULL) << 13);
    acc = (acc + a1 + 0xa9036ffcULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #1743 | PC: 0x0f3214 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #1743 | Địa chỉ PC: 0x0f3214 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0f3214: D10203FF  sub      sp, sp, #0x80
//   0x0f3218: A9026FFC  stp      x28, x27, [sp, #0x20]
//   0x0f321c: A90367FA  stp      x26, x25, [sp, #0x30]
//   0x0f3220: A9045FF8  stp      x24, x23, [sp, #0x40]
static inline uint64_t fde_func_1743_0x0f3214(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0f3214ULL ^ (static_cast<uint64_t>(0xd10203ffULL) << 13);
    acc = (acc + a1 + 0xa9026ffcULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #1744 | PC: 0x0f36a8 | FDE: 0x148a38 | Size: 56 bytes
// Hàm #1744 | Địa chỉ PC: 0x0f36a8 | Địa chỉ FDE: 0x148a38 | Kích thước: 56 bytes
//   0x0f36a8: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0f36ac: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0f36b0: 910043FD  add      x29, sp, #0x10
//   0x0f36b4: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_1744_0x0f36a8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0f36a8ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0038ULL;
    return acc;
}

// Func #1745 | PC: 0x0f36e0 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #1745 | Địa chỉ PC: 0x0f36e0 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0f36e0: D102C3FF  sub      sp, sp, #0xb0
//   0x0f36e4: A9056FFC  stp      x28, x27, [sp, #0x50]
//   0x0f36e8: A90667FA  stp      x26, x25, [sp, #0x60]
//   0x0f36ec: A9075FF8  stp      x24, x23, [sp, #0x70]
static inline uint64_t fde_func_1745_0x0f36e0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0f36e0ULL ^ (static_cast<uint64_t>(0xd102c3ffULL) << 13);
    acc = (acc + a1 + 0xa9056ffcULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #1746 | PC: 0x0f3c50 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #1746 | Địa chỉ PC: 0x0f3c50 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0f3c50: D10683FF  sub      sp, sp, #0x1a0
//   0x0f3c54: A9146FFC  stp      x28, x27, [sp, #0x140]
//   0x0f3c58: A91567FA  stp      x26, x25, [sp, #0x150]
//   0x0f3c5c: A9165FF8  stp      x24, x23, [sp, #0x160]
static inline uint64_t fde_func_1746_0x0f3c50(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0f3c50ULL ^ (static_cast<uint64_t>(0xd10683ffULL) << 13);
    acc = (acc + a1 + 0xa9146ffcULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #1747 | PC: 0x0f40ac | FDE: 0x148a38 | Size: 160 bytes
// Hàm #1747 | Địa chỉ PC: 0x0f40ac | Địa chỉ FDE: 0x148a38 | Kích thước: 160 bytes
//   0x0f40ac: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x0f40b0: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0f40b4: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0f40b8: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1747_0x0f40ac(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0f40acULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x00a0ULL;
    return acc;
}

// Func #1748 | PC: 0x0f414c | FDE: 0x148a38 | Size: 256 bytes
// Hàm #1748 | Địa chỉ PC: 0x0f414c | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0f414c: D10103FF  sub      sp, sp, #0x40
//   0x0f4150: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x0f4154: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x0f4158: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_1748_0x0f414c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0f414cULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #1749 | PC: 0x0f442c | FDE: 0x148a38 | Size: 256 bytes
// Hàm #1749 | Địa chỉ PC: 0x0f442c | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0f442c: D10183FF  sub      sp, sp, #0x60
//   0x0f4430: F9000BF9  str      x25, [sp, #0x10]
//   0x0f4434: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x0f4438: A90357F6  stp      x22, x21, [sp, #0x30]
static inline uint64_t fde_func_1749_0x0f442c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0f442cULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xf9000bf9ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #1750 | PC: 0x0f47dc | FDE: 0x148a38 | Size: 256 bytes
// Hàm #1750 | Địa chỉ PC: 0x0f47dc | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0f47dc: D10203FF  sub      sp, sp, #0x80
//   0x0f47e0: A9045FF8  stp      x24, x23, [sp, #0x40]
//   0x0f47e4: A90557F6  stp      x22, x21, [sp, #0x50]
//   0x0f47e8: A9064FF4  stp      x20, x19, [sp, #0x60]
static inline uint64_t fde_func_1750_0x0f47dc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0f47dcULL ^ (static_cast<uint64_t>(0xd10203ffULL) << 13);
    acc = (acc + a1 + 0xa9045ff8ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #1751 | PC: 0x0f4a4c | FDE: 0x148a38 | Size: 256 bytes
// Hàm #1751 | Địa chỉ PC: 0x0f4a4c | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0f4a4c: D10103FF  sub      sp, sp, #0x40
//   0x0f4a50: F9000BF5  str      x21, [sp, #0x10]
//   0x0f4a54: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x0f4a58: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_1751_0x0f4a4c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0f4a4cULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xf9000bf5ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #1752 | PC: 0x0f4b6c | FDE: 0x148a38 | Size: 76 bytes
// Hàm #1752 | Địa chỉ PC: 0x0f4b6c | Địa chỉ FDE: 0x148a38 | Kích thước: 76 bytes
//   0x0f4b6c: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0f4b70: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0f4b74: 910043FD  add      x29, sp, #0x10
//   0x0f4b78: 2A0103F4  mov      w20, w1
static inline uint64_t fde_func_1752_0x0f4b6c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0f4b6cULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x004cULL;
    return acc;
}

// Func #1753 | PC: 0x0f4bb8 | FDE: 0x148a38 | Size: 72 bytes
// Hàm #1753 | Địa chỉ PC: 0x0f4bb8 | Địa chỉ FDE: 0x148a38 | Kích thước: 72 bytes
//   0x0f4bb8: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0f4bbc: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0f4bc0: 910043FD  add      x29, sp, #0x10
//   0x0f4bc4: 91008014  add      x20, x0, #0x20
static inline uint64_t fde_func_1753_0x0f4bb8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0f4bb8ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0048ULL;
    return acc;
}

// Func #1754 | PC: 0x0f4c00 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #1754 | Địa chỉ PC: 0x0f4c00 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0f4c00: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x0f4c04: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0f4c08: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0f4c0c: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1754_0x0f4c00(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0f4c00ULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #1755 | PC: 0x0f4d2c | FDE: 0x148a38 | Size: 256 bytes
// Hàm #1755 | Địa chỉ PC: 0x0f4d2c | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0f4d2c: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0f4d30: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0f4d34: 910043FD  add      x29, sp, #0x10
//   0x0f4d38: AA0103F3  mov      x19, x1
static inline uint64_t fde_func_1755_0x0f4d2c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0f4d2cULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #1756 | PC: 0x0f4e38 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #1756 | Địa chỉ PC: 0x0f4e38 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0f4e38: D10183FF  sub      sp, sp, #0x60
//   0x0f4e3c: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x0f4e40: A90357F6  stp      x22, x21, [sp, #0x30]
//   0x0f4e44: A9044FF4  stp      x20, x19, [sp, #0x40]
static inline uint64_t fde_func_1756_0x0f4e38(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0f4e38ULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xa9025ff8ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #1757 | PC: 0x0f5048 | FDE: 0x148a38 | Size: 80 bytes
// Hàm #1757 | Địa chỉ PC: 0x0f5048 | Địa chỉ FDE: 0x148a38 | Kích thước: 80 bytes
//   0x0f5048: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0f504c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0f5050: 910043FD  add      x29, sp, #0x10
//   0x0f5054: A940A014  ldp      x20, x8, [x0, #8]
static inline uint64_t fde_func_1757_0x0f5048(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0f5048ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0050ULL;
    return acc;
}

// Func #1758 | PC: 0x0f5098 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #1758 | Địa chỉ PC: 0x0f5098 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0f5098: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x0f509c: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0f50a0: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0f50a4: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1758_0x0f5098(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0f5098ULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #1759 | PC: 0x0f51d8 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #1759 | Địa chỉ PC: 0x0f51d8 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0f51d8: D10143FF  sub      sp, sp, #0x50
//   0x0f51dc: F9000BF7  str      x23, [sp, #0x10]
//   0x0f51e0: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x0f51e4: A9034FF4  stp      x20, x19, [sp, #0x30]
static inline uint64_t fde_func_1759_0x0f51d8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0f51d8ULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xf9000bf7ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #1760 | PC: 0x0f547c | FDE: 0x148a38 | Size: 84 bytes
// Hàm #1760 | Địa chỉ PC: 0x0f547c | Địa chỉ FDE: 0x148a38 | Kích thước: 84 bytes
//   0x0f547c: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0f5480: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0f5484: 910043FD  add      x29, sp, #0x10
//   0x0f5488: 91005013  add      x19, x0, #0x14
static inline uint64_t fde_func_1760_0x0f547c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0f547cULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0054ULL;
    return acc;
}

// Func #1761 | PC: 0x0f54d0 | FDE: 0x148a38 | Size: 188 bytes
// Hàm #1761 | Địa chỉ PC: 0x0f54d0 | Địa chỉ FDE: 0x148a38 | Kích thước: 188 bytes
//   0x0f54d0: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0f54d4: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0f54d8: 910043FD  add      x29, sp, #0x10
//   0x0f54dc: 91005013  add      x19, x0, #0x14
static inline uint64_t fde_func_1761_0x0f54d0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0f54d0ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x00bcULL;
    return acc;
}

// Func #1762 | PC: 0x0f558c | FDE: 0x148a38 | Size: 84 bytes
// Hàm #1762 | Địa chỉ PC: 0x0f558c | Địa chỉ FDE: 0x148a38 | Kích thước: 84 bytes
//   0x0f558c: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0f5590: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0f5594: 910043FD  add      x29, sp, #0x10
//   0x0f5598: 91005013  add      x19, x0, #0x14
static inline uint64_t fde_func_1762_0x0f558c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0f558cULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0054ULL;
    return acc;
}

// Func #1763 | PC: 0x0f55e0 | FDE: 0x148a38 | Size: 152 bytes
// Hàm #1763 | Địa chỉ PC: 0x0f55e0 | Địa chỉ FDE: 0x148a38 | Kích thước: 152 bytes
//   0x0f55e0: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0f55e4: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0f55e8: 910043FD  add      x29, sp, #0x10
//   0x0f55ec: F9403008  ldr      x8, [x0, #0x60]
static inline uint64_t fde_func_1763_0x0f55e0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0f55e0ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0098ULL;
    return acc;
}

// Func #1764 | PC: 0x0f5678 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #1764 | Địa chỉ PC: 0x0f5678 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0f5678: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x0f567c: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0f5680: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0f5684: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1764_0x0f5678(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0f5678ULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #1765 | PC: 0x106cc0 | FDE: 0x148a38 | Size: 256 bytes [_ZNSt6__ndk110shared_ptrIN3com2ss5ttmio16MIOVodNetAdapterEED2Ev]
// Hàm #1765 | Địa chỉ PC: 0x106cc0 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x106cc0: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x106cc4: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x106cc8: 910043FD  add      x29, sp, #0x10
//   0x106ccc: F9400413  ldr      x19, [x0, #8]
static inline uint64_t fde_func_1765_0x106cc0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x106cc0ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #1766 | PC: 0x108498 | FDE: 0x148a38 | Size: 100 bytes [_ZN3com2ss5ttmio24MDLLinkQualitySampleInfoC2EbllliPKcli]
// Hàm #1766 | Địa chỉ PC: 0x108498 | Địa chỉ FDE: 0x148a38 | Kích thước: 100 bytes
//   0x108498: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x10849c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x1084a0: 910043FD  add      x29, sp, #0x10
//   0x1084a4: B94013A8  ldr      w8, [x29, #0x10]
static inline uint64_t fde_func_1766_0x108498(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x108498ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0064ULL;
    return acc;
}

// Func #1767 | PC: 0x1084fc | FDE: 0x148a38 | Size: 128 bytes [_ZN3com2ss5ttmio24MDLLinkQualitySampleInfoC1ERKS2_]
// Hàm #1767 | Địa chỉ PC: 0x1084fc | Địa chỉ FDE: 0x148a38 | Kích thước: 128 bytes
//   0x1084fc: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x108500: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x108504: 910043FD  add      x29, sp, #0x10
//   0x108508: 6F00E400  movi     v0.2d, #0000000000000000
static inline uint64_t fde_func_1767_0x1084fc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1084fcULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0080ULL;
    return acc;
}

// Func #1768 | PC: 0x10857c | FDE: 0x148a38 | Size: 104 bytes [_ZN3com2ss5ttmio24MDLLinkQualitySampleInfoaSERKS2_]
// Hàm #1768 | Địa chỉ PC: 0x10857c | Địa chỉ FDE: 0x148a38 | Kích thước: 104 bytes
//   0x10857c: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x108580: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x108584: 910043FD  add      x29, sp, #0x10
//   0x108588: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_1768_0x10857c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x10857cULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0068ULL;
    return acc;
}

// Func #1769 | PC: 0x1085e4 | FDE: 0x148a38 | Size: 20 bytes [_ZN3com2ss5ttmio24MDLLinkQualitySampleInfoD2Ev]
// Hàm #1769 | Địa chỉ PC: 0x1085e4 | Địa chỉ FDE: 0x148a38 | Kích thước: 20 bytes
//   0x1085e4: 39408008  ldrb     w8, [x0, #0x20]
//   0x1085e8: 37000048  tbnz     w8, #0, #0x1085f0
//   0x1085ec: D65F03C0  ret      
//   0x1085f0: F9401800  ldr      x0, [x0, #0x30]
static inline uint64_t fde_func_1769_0x1085e4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1085e4ULL ^ (static_cast<uint64_t>(0x39408008ULL) << 13);
    acc = (acc + a1 + 0x37000048ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0014ULL;
    return acc;
}

// Func #1770 | PC: 0x1085f8 | FDE: 0x148a38 | Size: 256 bytes [_ZN3com2ss5ttmio24MDLLinkQualitySampleInfo9printInfoEPKc]
// Hàm #1770 | Địa chỉ PC: 0x1085f8 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x1085f8: D65F03C0  ret      
//   0x1085fc: F0000288  adrp     x8, #0x15b000
//   0x108600: F9445508  ldr      x8, [x8, #0x8a8]
//   0x108604: AA0003E9  mov      x9, x0
static inline uint64_t fde_func_1770_0x1085f8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1085f8ULL ^ (static_cast<uint64_t>(0xd65f03c0ULL) << 13);
    acc = (acc + a1 + 0xf0000288ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #1771 | PC: 0x115610 | FDE: 0x148a38 | Size: 256 bytes [_ZN3com2ss5ttmio15MDLConfigCenter11getStrValueEi]
// Hàm #1771 | Địa chỉ PC: 0x115610 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x115610: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x115614: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x115618: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x11561c: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1771_0x115610(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x115610ULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #1772 | PC: 0x115c00 | FDE: 0x148a38 | Size: 256 bytes [_ZN3com2ss5ttmio28ff_convertStatusCodeToMdlErrEib]
// Hàm #1772 | Địa chỉ PC: 0x115c00 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x115c00: 51032008  sub      w8, w0, #0xc8
//   0x115c04: 71018D1F  cmp      w8, #0x63
//   0x115c08: 54000088  b.hi     #0x115c18
//   0x115c0c: 37000061  tbnz     w1, #0, #0x115c18
static inline uint64_t fde_func_1772_0x115c00(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x115c00ULL ^ (static_cast<uint64_t>(0x51032008ULL) << 13);
    acc = (acc + a1 + 0x71018d1fULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #1773 | PC: 0x116640 | FDE: 0x148a38 | Size: 12 bytes [_ZN3com2ss5ttmio2IDC2Ev]
// Hàm #1773 | Địa chỉ PC: 0x116640 | Địa chỉ FDE: 0x148a38 | Kích thước: 12 bytes
//   0x116640: A9007C1F  stp      xzr, xzr, [x0]
//   0x116644: B900101F  str      wzr, [x0, #0x10]
//   0x116648: D65F03C0  ret      
static inline uint64_t fde_func_1773_0x116640(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x116640ULL ^ (static_cast<uint64_t>(0xa9007c1fULL) << 13);
    acc = (acc + a1 + 0xb900101fULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x000cULL;
    return acc;
}

// Func #1774 | PC: 0x11664c | FDE: 0x148a38 | Size: 20 bytes [_ZN3com2ss5ttmio2IDC1EPh]
// Hàm #1774 | Địa chỉ PC: 0x11664c | Địa chỉ FDE: 0x148a38 | Kích thước: 20 bytes
//   0x11664c: B9401028  ldr      w8, [x1, #0x10]
//   0x116650: 3DC00020  ldr      q0, [x1]
//   0x116654: B9001008  str      w8, [x0, #0x10]
//   0x116658: 3D800000  str      q0, [x0]
static inline uint64_t fde_func_1774_0x11664c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x11664cULL ^ (static_cast<uint64_t>(0xb9401028ULL) << 13);
    acc = (acc + a1 + 0x3dc00020ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0014ULL;
    return acc;
}

// Func #1775 | PC: 0x116660 | FDE: 0x148a38 | Size: 12 bytes [_ZN3com2ss5ttmio2IDC1ERKNSt6__ndk112basic_stringIcNS3_11char_traitsIcEENS3_9allocatorIcEEEE]
// Hàm #1775 | Địa chỉ PC: 0x116660 | Địa chỉ FDE: 0x148a38 | Kích thước: 12 bytes
//   0x116660: A9007C1F  stp      xzr, xzr, [x0]
//   0x116664: B900101F  str      wzr, [x0, #0x10]
//   0x116668: 17FC75AA  b        #0x33d10
static inline uint64_t fde_func_1775_0x116660(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x116660ULL ^ (static_cast<uint64_t>(0xa9007c1fULL) << 13);
    acc = (acc + a1 + 0xb900101fULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x000cULL;
    return acc;
}

// Func #1776 | PC: 0x11666c | FDE: 0x148a38 | Size: 228 bytes [_ZN3com2ss5ttmio2ID5parseERKNSt6__ndk112basic_stringIcNS3_11char_traitsIcEENS3_9allocatorIcEEEE]
// Hàm #1776 | Địa chỉ PC: 0x11666c | Địa chỉ FDE: 0x148a38 | Kích thước: 228 bytes
//   0x11666c: 3940002C  ldrb     w12, [x1]
//   0x116670: F9400428  ldr      x8, [x1, #8]
//   0x116674: D341FD89  lsr      x9, x12, #1
//   0x116678: 7200019F  tst      w12, #1
static inline uint64_t fde_func_1776_0x11666c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x11666cULL ^ (static_cast<uint64_t>(0x3940002cULL) << 13);
    acc = (acc + a1 + 0xf9400428ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x00e4ULL;
    return acc;
}

// Func #1777 | PC: 0x116750 | FDE: 0x148a38 | Size: 80 bytes [_ZN3com2ss5ttmio2ID4ctoiEc]
// Hàm #1777 | Địa chỉ PC: 0x116750 | Địa chỉ FDE: 0x148a38 | Kích thước: 80 bytes
//   0x116750: 5100C028  sub      w8, w1, #0x30
//   0x116754: 12001D08  and      w8, w8, #0xff
//   0x116758: 7100291F  cmp      w8, #0xa
//   0x11675c: 12001C28  and      w8, w1, #0xff
static inline uint64_t fde_func_1777_0x116750(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x116750ULL ^ (static_cast<uint64_t>(0x5100c028ULL) << 13);
    acc = (acc + a1 + 0x12001d08ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0050ULL;
    return acc;
}

// Func #1778 | PC: 0x1167a0 | FDE: 0x148a38 | Size: 256 bytes [_ZN3com2ss5ttmio2ID5toStrEv]
// Hàm #1778 | Địa chỉ PC: 0x1167a0 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x1167a0: D10243FF  sub      sp, sp, #0x90
//   0x1167a4: F90023F9  str      x25, [sp, #0x40]
//   0x1167a8: A9055FF8  stp      x24, x23, [sp, #0x50]
//   0x1167ac: A90657F6  stp      x22, x21, [sp, #0x60]
static inline uint64_t fde_func_1778_0x1167a0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1167a0ULL ^ (static_cast<uint64_t>(0xd10243ffULL) << 13);
    acc = (acc + a1 + 0xf90023f9ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #1779 | PC: 0x1168b0 | FDE: 0x148a38 | Size: 100 bytes [_ZN3com2ss5ttmio2ID10BCDtoASCIIEPKhiPc]
// Hàm #1779 | Địa chỉ PC: 0x1168b0 | Địa chỉ FDE: 0x148a38 | Kích thước: 100 bytes
//   0x1168b0: F81C0FF7  str      x23, [sp, #-0x40]!
//   0x1168b4: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x1168b8: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x1168bc: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_1779_0x1168b0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1168b0ULL ^ (static_cast<uint64_t>(0xf81c0ff7ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0064ULL;
    return acc;
}

// Func #1780 | PC: 0x116914 | FDE: 0x148a38 | Size: 256 bytes [_ZN3com2ss5ttmio2ID8toLogStrEv]
// Hàm #1780 | Địa chỉ PC: 0x116914 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x116914: D10243FF  sub      sp, sp, #0x90
//   0x116918: F90023F9  str      x25, [sp, #0x40]
//   0x11691c: A9055FF8  stp      x24, x23, [sp, #0x50]
//   0x116920: A90657F6  stp      x22, x21, [sp, #0x60]
static inline uint64_t fde_func_1780_0x116914(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x116914ULL ^ (static_cast<uint64_t>(0xd10243ffULL) << 13);
    acc = (acc + a1 + 0xf90023f9ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #1781 | PC: 0x116a24 | FDE: 0x148a38 | Size: 92 bytes [_ZN3com2ss5ttmio2ID7isEmptyEv]
// Hàm #1781 | Địa chỉ PC: 0x116a24 | Địa chỉ FDE: 0x148a38 | Kích thước: 92 bytes
//   0x116a24: D10103FF  sub      sp, sp, #0x40
//   0x116a28: F90013F3  str      x19, [sp, #0x20]
//   0x116a2c: A9037BFD  stp      x29, x30, [sp, #0x30]
//   0x116a30: 9100C3FD  add      x29, sp, #0x30
static inline uint64_t fde_func_1781_0x116a24(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x116a24ULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xf90013f3ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x005cULL;
    return acc;
}

// Func #1782 | PC: 0x116a80 | FDE: 0x148a38 | Size: 12 bytes [_ZN3com2ss5ttmio2ID5resetEv]
// Hàm #1782 | Địa chỉ PC: 0x116a80 | Địa chỉ FDE: 0x148a38 | Kích thước: 12 bytes
//   0x116a80: A9007C1F  stp      xzr, xzr, [x0]
//   0x116a84: B900101F  str      wzr, [x0, #0x10]
//   0x116a88: D65F03C0  ret      
static inline uint64_t fde_func_1782_0x116a80(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x116a80ULL ^ (static_cast<uint64_t>(0xa9007c1fULL) << 13);
    acc = (acc + a1 + 0xb900101fULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x000cULL;
    return acc;
}

// Func #1783 | PC: 0x116a8c | FDE: 0x148a38 | Size: 4 bytes [_ZN3com2ss5ttmio2ID6getBufEv]
// Hàm #1783 | Địa chỉ PC: 0x116a8c | Địa chỉ FDE: 0x148a38 | Kích thước: 4 bytes
//   0x116a8c: D65F03C0  ret      
static inline uint64_t fde_func_1783_0x116a8c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x116a8cULL ^ (static_cast<uint64_t>(0xd65f03c0ULL) << 13);
    acc = (acc + a1 + 0xeb01001fULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0004ULL;
    return acc;
}

// Func #1784 | PC: 0x116a90 | FDE: 0x148a38 | Size: 28 bytes [_ZN3com2ss5ttmio2IDaSERKS2_]
// Hàm #1784 | Địa chỉ PC: 0x116a90 | Địa chỉ FDE: 0x148a38 | Kích thước: 28 bytes
//   0x116a90: EB01001F  cmp      x0, x1
//   0x116a94: 540000A0  b.eq     #0x116aa8
//   0x116a98: B9401028  ldr      w8, [x1, #0x10]
//   0x116a9c: 3DC00020  ldr      q0, [x1]
static inline uint64_t fde_func_1784_0x116a90(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x116a90ULL ^ (static_cast<uint64_t>(0xeb01001fULL) << 13);
    acc = (acc + a1 + 0x540000a0ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x001cULL;
    return acc;
}

// Func #1785 | PC: 0x116aac | FDE: 0x148a38 | Size: 32 bytes [_ZNK3com2ss5ttmio2IDeqERKS2_]
// Hàm #1785 | Địa chỉ PC: 0x116aac | Địa chỉ FDE: 0x148a38 | Kích thước: 32 bytes
//   0x116aac: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x116ab0: 910003FD  mov      x29, sp
//   0x116ab4: 52800282  mov      w2, #0x14
//   0x116ab8: 97FC7056  bl       #0x32c10
static inline uint64_t fde_func_1785_0x116aac(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x116aacULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0020ULL;
    return acc;
}

// Func #1786 | PC: 0x116acc | FDE: 0x148a38 | Size: 32 bytes [_ZNK3com2ss5ttmio2IDneERKS2_]
// Hàm #1786 | Địa chỉ PC: 0x116acc | Địa chỉ FDE: 0x148a38 | Kích thước: 32 bytes
//   0x116acc: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x116ad0: 910003FD  mov      x29, sp
//   0x116ad4: 52800282  mov      w2, #0x14
//   0x116ad8: 97FC704E  bl       #0x32c10
static inline uint64_t fde_func_1786_0x116acc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x116accULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0020ULL;
    return acc;
}

// Func #1787 | PC: 0x116aec | FDE: 0x148a38 | Size: 28 bytes [_ZNK3com2ss5ttmio2IDltERKS2_]
// Hàm #1787 | Địa chỉ PC: 0x116aec | Địa chỉ FDE: 0x148a38 | Kích thước: 28 bytes
//   0x116aec: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x116af0: 910003FD  mov      x29, sp
//   0x116af4: 52800282  mov      w2, #0x14
//   0x116af8: 97FC7046  bl       #0x32c10
static inline uint64_t fde_func_1787_0x116aec(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x116aecULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x001cULL;
    return acc;
}

// Func #1788 | PC: 0x116b08 | FDE: 0x148a38 | Size: 36 bytes [_ZN3com2ss5ttmio5CHashC1Ev]
// Hàm #1788 | Địa chỉ PC: 0x116b08 | Địa chỉ FDE: 0x148a38 | Kích thước: 36 bytes
//   0x116b08: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x116b0c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x116b10: 910043FD  add      x29, sp, #0x10
//   0x116b14: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_1788_0x116b08(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x116b08ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0024ULL;
    return acc;
}

// Func #1789 | PC: 0x116b2c | FDE: 0x148a38 | Size: 4 bytes [_ZN3com2ss5ttmio5CHashD2Ev]
// Hàm #1789 | Địa chỉ PC: 0x116b2c | Địa chỉ FDE: 0x148a38 | Kích thước: 4 bytes
//   0x116b2c: 14000090  b        #0x116d6c
static inline uint64_t fde_func_1789_0x116b2c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x116b2cULL ^ (static_cast<uint64_t>(0x14000090ULL) << 13);
    acc = (acc + a1 + 0x14000090ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0004ULL;
    return acc;
}

// Func #1790 | PC: 0x116b30 | FDE: 0x148a38 | Size: 4 bytes [_ZN3com2ss5ttmio5CHash3addEPhj]
// Hàm #1790 | Địa chỉ PC: 0x116b30 | Địa chỉ FDE: 0x148a38 | Kích thước: 4 bytes
//   0x116b30: 14000090  b        #0x116d70
static inline uint64_t fde_func_1790_0x116b30(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x116b30ULL ^ (static_cast<uint64_t>(0x14000090ULL) << 13);
    acc = (acc + a1 + 0x14000379ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0004ULL;
    return acc;
}

// Func #1791 | PC: 0x116b34 | FDE: 0x148a38 | Size: 4 bytes [_ZN3com2ss5ttmio5CHash6finishEv]
// Hàm #1791 | Địa chỉ PC: 0x116b34 | Địa chỉ FDE: 0x148a38 | Kích thước: 4 bytes
//   0x116b34: 14000379  b        #0x117918
static inline uint64_t fde_func_1791_0x116b34(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x116b34ULL ^ (static_cast<uint64_t>(0x14000379ULL) << 13);
    acc = (acc + a1 + 0xd100c3ffULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0004ULL;
    return acc;
}

// Func #1792 | PC: 0x116b38 | FDE: 0x148a38 | Size: 120 bytes [_ZN3com2ss5ttmio5CHash9getHashIDEv]
// Hàm #1792 | Địa chỉ PC: 0x116b38 | Địa chỉ FDE: 0x148a38 | Kích thước: 120 bytes
//   0x116b38: D100C3FF  sub      sp, sp, #0x30
//   0x116b3c: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x116b40: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x116b44: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1792_0x116b38(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x116b38ULL ^ (static_cast<uint64_t>(0xd100c3ffULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0078ULL;
    return acc;
}

// Func #1793 | PC: 0x116bb0 | FDE: 0x148a38 | Size: 256 bytes [mdl_tracer_v2]
// Hàm #1793 | Địa chỉ PC: 0x116bb0 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x116bb0: F81A0FFC  str      x28, [sp, #-0x60]!
//   0x116bb4: A90167FA  stp      x26, x25, [sp, #0x10]
//   0x116bb8: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x116bbc: A90357F6  stp      x22, x21, [sp, #0x30]
static inline uint64_t fde_func_1793_0x116bb0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x116bb0ULL ^ (static_cast<uint64_t>(0xf81a0ffcULL) << 13);
    acc = (acc + a1 + 0xa90167faULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #1794 | PC: 0x118a1c | FDE: 0x148a38 | Size: 104 bytes [_ZN3com2ss5ttmio13MDLThreadPoolC2Ev]
// Hàm #1794 | Địa chỉ PC: 0x118a1c | Địa chỉ FDE: 0x148a38 | Kích thước: 104 bytes
//   0x118a1c: F0000208  adrp     x8, #0x15b000
//   0x118a20: F944C108  ldr      x8, [x8, #0x980]
//   0x118a24: 52800069  mov      w9, #3
//   0x118a28: B9000809  str      w9, [x0, #8]
static inline uint64_t fde_func_1794_0x118a1c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x118a1cULL ^ (static_cast<uint64_t>(0xf0000208ULL) << 13);
    acc = (acc + a1 + 0xf944c108ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0068ULL;
    return acc;
}

// Func #1795 | PC: 0x118a84 | FDE: 0x148a38 | Size: 100 bytes [_ZN3com2ss5ttmio13MDLThreadPoolD1Ev]
// Hàm #1795 | Địa chỉ PC: 0x118a84 | Địa chỉ FDE: 0x148a38 | Kích thước: 100 bytes
//   0x118a84: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x118a88: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x118a8c: 910043FD  add      x29, sp, #0x10
//   0x118a90: F0000208  adrp     x8, #0x15b000
static inline uint64_t fde_func_1795_0x118a84(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x118a84ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0064ULL;
    return acc;
}

// Func #1796 | PC: 0x118ae8 | FDE: 0x148a38 | Size: 92 bytes [_ZN3com2ss5ttmio13MDLThreadPool7close_lEv]
// Hàm #1796 | Địa chỉ PC: 0x118ae8 | Địa chỉ FDE: 0x148a38 | Kích thước: 92 bytes
//   0x118ae8: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x118aec: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x118af0: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x118af4: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1796_0x118ae8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x118ae8ULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x005cULL;
    return acc;
}

// Func #1797 | PC: 0x118b44 | FDE: 0x148a38 | Size: 36 bytes [_ZN3com2ss5ttmio13MDLThreadPoolD0Ev]
// Hàm #1797 | Địa chỉ PC: 0x118b44 | Địa chỉ FDE: 0x148a38 | Kích thước: 36 bytes
//   0x118b44: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x118b48: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x118b4c: 910043FD  add      x29, sp, #0x10
//   0x118b50: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_1797_0x118b44(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x118b44ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0024ULL;
    return acc;
}

// Func #1798 | PC: 0x118b68 | FDE: 0x148a38 | Size: 256 bytes [_ZN3com2ss5ttmio13MDLThreadPool6open_lEb]
// Hàm #1798 | Địa chỉ PC: 0x118b68 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x118b68: A9BC5FF8  stp      x24, x23, [sp, #-0x40]!
//   0x118b6c: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x118b70: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x118b74: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_1798_0x118b68(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x118b68ULL ^ (static_cast<uint64_t>(0xa9bc5ff8ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #1799 | PC: 0x118ce4 | FDE: 0x148a38 | Size: 256 bytes [_ZN3com2ss5ttmio13MDLThreadPool18tryTriggerCheckTTLEPNS0_3ttm10mdl2_utils8AVThreadE]
// Hàm #1799 | Địa chỉ PC: 0x118ce4 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x118ce4: D10343FF  sub      sp, sp, #0xd0
//   0x118ce8: A9095FF8  stp      x24, x23, [sp, #0x90]
//   0x118cec: A90A57F6  stp      x22, x21, [sp, #0xa0]
//   0x118cf0: A90B4FF4  stp      x20, x19, [sp, #0xb0]
static inline uint64_t fde_func_1799_0x118ce4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x118ce4ULL ^ (static_cast<uint64_t>(0xd10343ffULL) << 13);
    acc = (acc + a1 + 0xa9095ff8ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #1800 | PC: 0x118e3c | FDE: 0x148a38 | Size: 208 bytes [_ZN3com2ss5ttmio13MDLThreadPool9getThreadEbPKc]
// Hàm #1800 | Địa chỉ PC: 0x118e3c | Địa chỉ FDE: 0x148a38 | Kích thước: 208 bytes
//   0x118e3c: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x118e40: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x118e44: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x118e48: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1800_0x118e3c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x118e3cULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x00d0ULL;
    return acc;
}

// Func #1801 | PC: 0x118f0c | FDE: 0x148a38 | Size: 256 bytes [_ZN3com2ss5ttmio13MDLThreadPool10freeThreadEPNS0_3ttm10mdl2_utils8AVThreadE]
// Hàm #1801 | Địa chỉ PC: 0x118f0c | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x118f0c: F81C0FF7  str      x23, [sp, #-0x40]!
//   0x118f10: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x118f14: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x118f18: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_1801_0x118f0c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x118f0cULL ^ (static_cast<uint64_t>(0xf81c0ff7ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #1802 | PC: 0x11900c | FDE: 0x148a38 | Size: 60 bytes [_ZNK3com2ss5ttmio13MDLThreadPool7isExistERNSt6__ndk14listIPNS0_3ttm10mdl2_utils8AVThreadENS3_9allocatorIS8_EEEES8_]
// Hàm #1802 | Địa chỉ PC: 0x11900c | Địa chỉ FDE: 0x148a38 | Kích thước: 60 bytes
//   0x11900c: 3942C008  ldrb     w8, [x0, #0xb0]
//   0x119010: 34000068  cbz      w8, #0x11901c
//   0x119014: 2A1F03E0  mov      w0, wzr
//   0x119018: D65F03C0  ret      
static inline uint64_t fde_func_1802_0x11900c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x11900cULL ^ (static_cast<uint64_t>(0x3942c008ULL) << 13);
    acc = (acc + a1 + 0x34000068ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x003cULL;
    return acc;
}

// Func #1803 | PC: 0x119048 | FDE: 0x148a38 | Size: 128 bytes [_ZN3com2ss5ttmio13MDLThreadPool11threadStartEv]
// Hàm #1803 | Địa chỉ PC: 0x119048 | Địa chỉ FDE: 0x148a38 | Kích thước: 128 bytes
//   0x119048: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x11904c: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x119050: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x119054: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1803_0x119048(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x119048ULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0080ULL;
    return acc;
}

// Func #1804 | PC: 0x1190c8 | FDE: 0x148a38 | Size: 256 bytes [_ZN3com2ss5ttmio13MDLThreadPool9threadEndEv]
// Hàm #1804 | Địa chỉ PC: 0x1190c8 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x1190c8: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x1190cc: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x1190d0: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x1190d4: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1804_0x1190c8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1190c8ULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #1805 | PC: 0x1191d0 | FDE: 0x148a38 | Size: 256 bytes [_ZN3com2ss5ttmio13MDLThreadPool12bindResourceEPvPFvS3_E]
// Hàm #1805 | Địa chỉ PC: 0x1191d0 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x1191d0: F81B0FF9  str      x25, [sp, #-0x50]!
//   0x1191d4: A9015FF8  stp      x24, x23, [sp, #0x10]
//   0x1191d8: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x1191dc: A9034FF4  stp      x20, x19, [sp, #0x30]
static inline uint64_t fde_func_1805_0x1191d0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1191d0ULL ^ (static_cast<uint64_t>(0xf81b0ff9ULL) << 13);
    acc = (acc + a1 + 0xa9015ff8ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #1806 | PC: 0x1192dc | FDE: 0x148a38 | Size: 136 bytes [_ZN3com2ss5ttmio13MDLThreadPool17getThreadResourceEv]
// Hàm #1806 | Địa chỉ PC: 0x1192dc | Địa chỉ FDE: 0x148a38 | Kích thước: 136 bytes
//   0x1192dc: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x1192e0: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x1192e4: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x1192e8: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1806_0x1192dc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1192dcULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0088ULL;
    return acc;
}

// Func #1807 | PC: 0x119364 | FDE: 0x148a38 | Size: 108 bytes [_ZN3com2ss5ttmio13MDLThreadPool13closeInternalEv]
// Hàm #1807 | Địa chỉ PC: 0x119364 | Địa chỉ FDE: 0x148a38 | Kích thước: 108 bytes
//   0x119364: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x119368: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x11936c: 910043FD  add      x29, sp, #0x10
//   0x119370: F9402408  ldr      x8, [x0, #0x48]
static inline uint64_t fde_func_1807_0x119364(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x119364ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x006cULL;
    return acc;
}

// Func #1808 | PC: 0x1193d0 | FDE: 0x148a38 | Size: 68 bytes [_ZN3com2ss5ttmio13MDLThreadPool16setMinThreadSizeEi]
// Hàm #1808 | Địa chỉ PC: 0x1193d0 | Địa chỉ FDE: 0x148a38 | Kích thước: 68 bytes
//   0x1193d0: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x1193d4: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x1193d8: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x1193dc: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1808_0x1193d0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1193d0ULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0044ULL;
    return acc;
}

// Func #1809 | PC: 0x119414 | FDE: 0x148a38 | Size: 8 bytes [_ZN3com2ss5ttmio13MDLThreadPool15setEventHandlerEPNS1_13MDLEventQueueE]
// Hàm #1809 | Địa chỉ PC: 0x119414 | Địa chỉ FDE: 0x148a38 | Kích thước: 8 bytes
//   0x119414: F9005401  str      x1, [x0, #0xa8]
//   0x119418: D65F03C0  ret      
static inline uint64_t fde_func_1809_0x119414(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x119414ULL ^ (static_cast<uint64_t>(0xf9005401ULL) << 13);
    acc = (acc + a1 + 0xd65f03c0ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0008ULL;
    return acc;
}

// Func #1810 | PC: 0x11941c | FDE: 0x148a38 | Size: 224 bytes [_ZN3com2ss5ttmio13MDLThreadPool15checkIdleThreadEPNS0_3ttm10mdl2_utils8AVThreadE]
// Hàm #1810 | Địa chỉ PC: 0x11941c | Địa chỉ FDE: 0x148a38 | Kích thước: 224 bytes
//   0x11941c: F81C0FF7  str      x23, [sp, #-0x40]!
//   0x119420: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x119424: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x119428: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_1810_0x11941c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x11941cULL ^ (static_cast<uint64_t>(0xf81c0ff7ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x00e0ULL;
    return acc;
}

// Func #1811 | PC: 0x1194fc | FDE: 0x148a38 | Size: 256 bytes [_ZN3com2ss5ttmio13MDLThreadPool12startThread2ERNS0_6vcbkit6RefPtrINS3_6ThreadEEERKNS4_INS3_5BlockEEERKNS3_10ThreadAttrE]
// Hàm #1811 | Địa chỉ PC: 0x1194fc | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x1194fc: F81C0FF7  str      x23, [sp, #-0x40]!
//   0x119500: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x119504: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x119508: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_1811_0x1194fc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1194fcULL ^ (static_cast<uint64_t>(0xf81c0ff7ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #1812 | PC: 0x119738 | FDE: 0x148a38 | Size: 76 bytes [_ZN3com2ss5ttmio14getCurrentTimeEv]
// Hàm #1812 | Địa chỉ PC: 0x119738 | Địa chỉ FDE: 0x148a38 | Kích thước: 76 bytes
//   0x119738: D10083FF  sub      sp, sp, #0x20
//   0x11973c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x119740: 910043FD  add      x29, sp, #0x10
//   0x119744: 910003E0  mov      x0, sp
static inline uint64_t fde_func_1812_0x119738(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x119738ULL ^ (static_cast<uint64_t>(0xd10083ffULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x004cULL;
    return acc;
}

// Func #1813 | PC: 0x119784 | FDE: 0x148a38 | Size: 52 bytes [_ZN3com2ss5ttmio22getCurrentTimeMicroSecEv]
// Hàm #1813 | Địa chỉ PC: 0x119784 | Địa chỉ FDE: 0x148a38 | Kích thước: 52 bytes
//   0x119784: D10083FF  sub      sp, sp, #0x20
//   0x119788: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x11978c: 910043FD  add      x29, sp, #0x10
//   0x119790: 910003E0  mov      x0, sp
static inline uint64_t fde_func_1813_0x119784(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x119784ULL ^ (static_cast<uint64_t>(0xd10083ffULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0034ULL;
    return acc;
}

// Func #1814 | PC: 0x1197b8 | FDE: 0x148a38 | Size: 256 bytes [_ZN3com2ss5ttmio18MDLTimedEventQueueC1EbPKc]
// Hàm #1814 | Địa chỉ PC: 0x1197b8 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x1197b8: D10203FF  sub      sp, sp, #0x80
//   0x1197bc: A90367FA  stp      x26, x25, [sp, #0x30]
//   0x1197c0: A9045FF8  stp      x24, x23, [sp, #0x40]
//   0x1197c4: A90557F6  stp      x22, x21, [sp, #0x50]
static inline uint64_t fde_func_1814_0x1197b8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1197b8ULL ^ (static_cast<uint64_t>(0xd10203ffULL) << 13);
    acc = (acc + a1 + 0xa90367faULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #1815 | PC: 0x11997c | FDE: 0x148a38 | Size: 216 bytes [_ZN3com2ss5ttmio18MDLTimedEventQueueD2Ev]
// Hàm #1815 | Địa chỉ PC: 0x11997c | Địa chỉ FDE: 0x148a38 | Kích thước: 216 bytes
//   0x11997c: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x119980: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x119984: 910043FD  add      x29, sp, #0x10
//   0x119988: D0000208  adrp     x8, #0x15b000
static inline uint64_t fde_func_1815_0x11997c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x11997cULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x00d8ULL;
    return acc;
}

// Func #1816 | PC: 0x119a54 | FDE: 0x148a38 | Size: 248 bytes [_ZN3com2ss5ttmio18MDLTimedEventQueue4stopEv]
// Hàm #1816 | Địa chỉ PC: 0x119a54 | Địa chỉ FDE: 0x148a38 | Kích thước: 248 bytes
//   0x119a54: D10303FF  sub      sp, sp, #0xc0
//   0x119a58: A90957F6  stp      x22, x21, [sp, #0x90]
//   0x119a5c: A90A4FF4  stp      x20, x19, [sp, #0xa0]
//   0x119a60: A90B7BFD  stp      x29, x30, [sp, #0xb0]
static inline uint64_t fde_func_1816_0x119a54(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x119a54ULL ^ (static_cast<uint64_t>(0xd10303ffULL) << 13);
    acc = (acc + a1 + 0xa90957f6ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x00f8ULL;
    return acc;
}

// Func #1817 | PC: 0x119b4c | FDE: 0x148a38 | Size: 36 bytes [_ZN3com2ss5ttmio18MDLTimedEventQueueD0Ev]
// Hàm #1817 | Địa chỉ PC: 0x119b4c | Địa chỉ FDE: 0x148a38 | Kích thước: 36 bytes
//   0x119b4c: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x119b50: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x119b54: 910043FD  add      x29, sp, #0x10
//   0x119b58: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_1817_0x119b4c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x119b4cULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0024ULL;
    return acc;
}

// Func #1818 | PC: 0x119b70 | FDE: 0x148a38 | Size: 12 bytes [_ZN3com2ss5ttmio18MDLTimedEventQueue8endQueueEv]
// Hàm #1818 | Địa chỉ PC: 0x119b70 | Địa chỉ FDE: 0x148a38 | Kích thước: 12 bytes
//   0x119b70: 9100A008  add      x8, x0, #0x28
//   0x119b74: 089FFD1F  stlrb    wzr, [x8]
//   0x119b78: D65F03C0  ret      
static inline uint64_t fde_func_1818_0x119b70(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x119b70ULL ^ (static_cast<uint64_t>(0x9100a008ULL) << 13);
    acc = (acc + a1 + 0x089ffd1fULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x000cULL;
    return acc;
}

// Func #1819 | PC: 0x119b7c | FDE: 0x148a38 | Size: 256 bytes [_ZN3com2ss5ttmio18MDLTimedEventQueue9postEventERNS1_8MDLEventE]
// Hàm #1819 | Địa chỉ PC: 0x119b7c | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x119b7c: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x119b80: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x119b84: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x119b88: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1819_0x119b7c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x119b7cULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #1820 | PC: 0x119cac | FDE: 0x148a38 | Size: 256 bytes [_ZN3com2ss5ttmio18MDLTimedEventQueue11insertQueueEPNS2_15MDLEventWrapperEi]
// Hàm #1820 | Địa chỉ PC: 0x119cac | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x119cac: F81C0FF7  str      x23, [sp, #-0x40]!
//   0x119cb0: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x119cb4: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x119cb8: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_1820_0x119cac(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x119cacULL ^ (static_cast<uint64_t>(0xf81c0ff7ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #1821 | PC: 0x119df0 | FDE: 0x148a38 | Size: 232 bytes [_ZN3com2ss5ttmio18MDLTimedEventQueue14postEventDelayERNS1_8MDLEventEi]
// Hàm #1821 | Địa chỉ PC: 0x119df0 | Địa chỉ FDE: 0x148a38 | Kích thước: 232 bytes
//   0x119df0: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x119df4: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x119df8: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x119dfc: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1821_0x119df0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x119df0ULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x00e8ULL;
    return acc;
}

// Func #1822 | PC: 0x119ed8 | FDE: 0x148a38 | Size: 256 bytes [_ZN3com2ss5ttmio18MDLTimedEventQueue19postEventIfNotExistERNS1_8MDLEventEi]
// Hàm #1822 | Địa chỉ PC: 0x119ed8 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x119ed8: A9BC5FF8  stp      x24, x23, [sp, #-0x40]!
//   0x119edc: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x119ee0: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x119ee4: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_1822_0x119ed8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x119ed8ULL ^ (static_cast<uint64_t>(0xa9bc5ff8ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #1823 | PC: 0x11a018 | FDE: 0x148a38 | Size: 256 bytes [_ZN3com2ss5ttmio18MDLTimedEventQueue24postEventDelayIfNotExistERNS1_8MDLEventEii]
// Hàm #1823 | Địa chỉ PC: 0x11a018 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x11a018: F81B0FF9  str      x25, [sp, #-0x50]!
//   0x11a01c: A9015FF8  stp      x24, x23, [sp, #0x10]
//   0x11a020: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x11a024: A9034FF4  stp      x20, x19, [sp, #0x30]
static inline uint64_t fde_func_1823_0x11a018(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x11a018ULL ^ (static_cast<uint64_t>(0xf81b0ff9ULL) << 13);
    acc = (acc + a1 + 0xa9015ff8ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #1824 | PC: 0x11a170 | FDE: 0x148a38 | Size: 256 bytes [_ZN3com2ss5ttmio18MDLTimedEventQueue9sendEventERNS1_8MDLEventE]
// Hàm #1824 | Địa chỉ PC: 0x11a170 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x11a170: D10183FF  sub      sp, sp, #0x60
//   0x11a174: F9000BF9  str      x25, [sp, #0x10]
//   0x11a178: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x11a17c: A90357F6  stp      x22, x21, [sp, #0x30]
static inline uint64_t fde_func_1824_0x11a170(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x11a170ULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xf9000bf9ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #1825 | PC: 0x11a3d4 | FDE: 0x148a38 | Size: 244 bytes [_ZN3com2ss5ttmio18MDLTimedEventQueue10eraseEventEi]
// Hàm #1825 | Địa chỉ PC: 0x11a3d4 | Địa chỉ FDE: 0x148a38 | Kích thước: 244 bytes
//   0x11a3d4: 3100043F  cmn      w1, #1
//   0x11a3d8: 540002A0  b.eq     #0x11a42c
//   0x11a3dc: F81C0FF7  str      x23, [sp, #-0x40]!
//   0x11a3e0: A90157F6  stp      x22, x21, [sp, #0x10]
static inline uint64_t fde_func_1825_0x11a3d4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x11a3d4ULL ^ (static_cast<uint64_t>(0x3100043fULL) << 13);
    acc = (acc + a1 + 0x540002a0ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x00f4ULL;
    return acc;
}

// Func #1826 | PC: 0x11a4c8 | FDE: 0x148a38 | Size: 256 bytes [_ZN3com2ss5ttmio18MDLTimedEventQueue7processEv]
// Hàm #1826 | Địa chỉ PC: 0x11a4c8 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x11a4c8: F81B0FF9  str      x25, [sp, #-0x50]!
//   0x11a4cc: A9015FF8  stp      x24, x23, [sp, #0x10]
//   0x11a4d0: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x11a4d4: A9034FF4  stp      x20, x19, [sp, #0x30]
static inline uint64_t fde_func_1826_0x11a4c8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x11a4c8ULL ^ (static_cast<uint64_t>(0xf81b0ff9ULL) << 13);
    acc = (acc + a1 + 0xa9015ff8ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #1827 | PC: 0x11a618 | FDE: 0x148a38 | Size: 256 bytes [_ZN3com2ss5ttmio18MDLTimedEventQueue9waitEventEv]
// Hàm #1827 | Địa chỉ PC: 0x11a618 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x11a618: D10203FF  sub      sp, sp, #0x80
//   0x11a61c: A9045FF8  stp      x24, x23, [sp, #0x40]
//   0x11a620: A90557F6  stp      x22, x21, [sp, #0x50]
//   0x11a624: A9064FF4  stp      x20, x19, [sp, #0x60]
static inline uint64_t fde_func_1827_0x11a618(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x11a618ULL ^ (static_cast<uint64_t>(0xd10203ffULL) << 13);
    acc = (acc + a1 + 0xa9045ff8ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #1828 | PC: 0x11a780 | FDE: 0x148a38 | Size: 256 bytes [_ZN3com2ss5ttmio18MDLTimedEventQueue10clearQueueEv]
// Hàm #1828 | Địa chỉ PC: 0x11a780 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x11a780: F81B0FF9  str      x25, [sp, #-0x50]!
//   0x11a784: A9015FF8  stp      x24, x23, [sp, #0x10]
//   0x11a788: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x11a78c: A9034FF4  stp      x20, x19, [sp, #0x30]
static inline uint64_t fde_func_1828_0x11a780(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x11a780ULL ^ (static_cast<uint64_t>(0xf81b0ff9ULL) << 13);
    acc = (acc + a1 + 0xa9015ff8ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #1829 | PC: 0x11a8d8 | FDE: 0x148a38 | Size: 148 bytes [_ZN3com2ss5ttmio20MDLEventQueueFactoryC2Ev]
// Hàm #1829 | Địa chỉ PC: 0x11a8d8 | Địa chỉ FDE: 0x148a38 | Kích thước: 148 bytes
//   0x11a8d8: 6F00E400  movi     v0.2d, #0000000000000000
//   0x11a8dc: F900301F  str      xzr, [x0, #0x60]
//   0x11a8e0: 3C81C000  stur     q0, [x0, #0x1c]
//   0x11a8e4: AD000000  stp      q0, q0, [x0]
static inline uint64_t fde_func_1829_0x11a8d8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x11a8d8ULL ^ (static_cast<uint64_t>(0x6f00e400ULL) << 13);
    acc = (acc + a1 + 0xf900301fULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0094ULL;
    return acc;
}

// Func #1830 | PC: 0x11a96c | FDE: 0x148a38 | Size: 56 bytes [_ZN3com2ss5ttmio20MDLEventQueueFactory16setHighQueueSizeEi]
// Hàm #1830 | Địa chỉ PC: 0x11a96c | Địa chỉ FDE: 0x148a38 | Kích thước: 56 bytes
//   0x11a96c: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x11a970: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x11a974: 910043FD  add      x29, sp, #0x10
//   0x11a978: 2A0103F3  mov      w19, w1
static inline uint64_t fde_func_1830_0x11a96c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x11a96cULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0038ULL;
    return acc;
}

// Func #1831 | PC: 0x11a9a4 | FDE: 0x148a38 | Size: 172 bytes [_ZN3com2ss5ttmio20MDLEventQueueFactory16getNewEventQueueEv]
// Hàm #1831 | Địa chỉ PC: 0x11a9a4 | Địa chỉ FDE: 0x148a38 | Kích thước: 172 bytes
//   0x11a9a4: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x11a9a8: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x11a9ac: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x11a9b0: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1831_0x11a9a4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x11a9a4ULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x00acULL;
    return acc;
}

// Func #1832 | PC: 0x11aa50 | FDE: 0x148a38 | Size: 124 bytes [_ZN3com2ss5ttmio20MDLEventQueueFactory19getGlobalEventQueueEi]
// Hàm #1832 | Địa chỉ PC: 0x11aa50 | Địa chỉ FDE: 0x148a38 | Kích thước: 124 bytes
//   0x11aa50: 7100083F  cmp      w1, #2
//   0x11aa54: 5400006B  b.lt     #0x11aa60
//   0x11aa58: 91016001  add      x1, x0, #0x58
//   0x11aa5c: 14000004  b        #0x11aa6c
static inline uint64_t fde_func_1832_0x11aa50(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x11aa50ULL ^ (static_cast<uint64_t>(0x7100083fULL) << 13);
    acc = (acc + a1 + 0x5400006bULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x007cULL;
    return acc;
}

// Func #1833 | PC: 0x11aacc | FDE: 0x148a38 | Size: 256 bytes [_ZN3com2ss5ttmio20MDLEventQueueFactory13getEventQueueERNSt6__ndk110shared_ptrINS1_13MDLEventQueueEEEb]
// Hàm #1833 | Địa chỉ PC: 0x11aacc | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x11aacc: D10143FF  sub      sp, sp, #0x50
//   0x11aad0: A9015FF8  stp      x24, x23, [sp, #0x10]
//   0x11aad4: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x11aad8: A9034FF4  stp      x20, x19, [sp, #0x30]
static inline uint64_t fde_func_1833_0x11aacc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x11aaccULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xa9015ff8ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #1834 | PC: 0x11ac30 | FDE: 0x148a38 | Size: 256 bytes [_ZN3com2ss5ttmio15MIOEventAdapterC2ERKNSt6__ndk112basic_stringIcNS3_11char_traitsIcEENS3_9allocatorIcEEEEb]
// Hàm #1834 | Địa chỉ PC: 0x11ac30 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x11ac30: D100C3FF  sub      sp, sp, #0x30
//   0x11ac34: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x11ac38: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x11ac3c: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1834_0x11ac30(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x11ac30ULL ^ (static_cast<uint64_t>(0xd100c3ffULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #1835 | PC: 0x11ad84 | FDE: 0x148a38 | Size: 68 bytes [_ZN3com2ss5ttmio15MIOEventAdapterD2Ev]
// Hàm #1835 | Địa chỉ PC: 0x11ad84 | Địa chỉ FDE: 0x148a38 | Kích thước: 68 bytes
//   0x11ad84: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x11ad88: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x11ad8c: 910043FD  add      x29, sp, #0x10
//   0x11ad90: B0000208  adrp     x8, #0x15b000
static inline uint64_t fde_func_1835_0x11ad84(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x11ad84ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0044ULL;
    return acc;
}

// Func #1836 | PC: 0x11adc8 | FDE: 0x148a38 | Size: 80 bytes [_ZN3com2ss5ttmio15MIOEventAdapterD0Ev]
// Hàm #1836 | Địa chỉ PC: 0x11adc8 | Địa chỉ FDE: 0x148a38 | Kích thước: 80 bytes
//   0x11adc8: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x11adcc: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x11add0: 910043FD  add      x29, sp, #0x10
//   0x11add4: B0000208  adrp     x8, #0x15b000
static inline uint64_t fde_func_1836_0x11adc8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x11adc8ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0050ULL;
    return acc;
}

// Func #1837 | PC: 0x11ae18 | FDE: 0x148a38 | Size: 4 bytes [_ZN3com2ss5ttmio15MIOEventAdapter8endQueueEv]
// Hàm #1837 | Địa chỉ PC: 0x11ae18 | Địa chỉ FDE: 0x148a38 | Kích thước: 4 bytes
//   0x11ae18: D65F03C0  ret      
static inline uint64_t fde_func_1837_0x11ae18(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x11ae18ULL ^ (static_cast<uint64_t>(0xd65f03c0ULL) << 13);
    acc = (acc + a1 + 0xd103c3ffULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0004ULL;
    return acc;
}

// Func #1838 | PC: 0x11ae1c | FDE: 0x148a38 | Size: 256 bytes [_ZN3com2ss5ttmio15MIOEventAdapter9postEventERNS1_8MDLEventE]
// Hàm #1838 | Địa chỉ PC: 0x11ae1c | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x11ae1c: D103C3FF  sub      sp, sp, #0xf0
//   0x11ae20: A90C57F6  stp      x22, x21, [sp, #0xc0]
//   0x11ae24: A90D4FF4  stp      x20, x19, [sp, #0xd0]
//   0x11ae28: A90E7BFD  stp      x29, x30, [sp, #0xe0]
static inline uint64_t fde_func_1838_0x11ae1c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x11ae1cULL ^ (static_cast<uint64_t>(0xd103c3ffULL) << 13);
    acc = (acc + a1 + 0xa90c57f6ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #1839 | PC: 0x11afe4 | FDE: 0x148a38 | Size: 256 bytes [_ZN3com2ss5ttmio15MIOEventAdapter14postEventDelayERNS1_8MDLEventEi]
// Hàm #1839 | Địa chỉ PC: 0x11afe4 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x11afe4: D10403FF  sub      sp, sp, #0x100
//   0x11afe8: F90063F7  str      x23, [sp, #0xc0]
//   0x11afec: A90D57F6  stp      x22, x21, [sp, #0xd0]
//   0x11aff0: A90E4FF4  stp      x20, x19, [sp, #0xe0]
static inline uint64_t fde_func_1839_0x11afe4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x11afe4ULL ^ (static_cast<uint64_t>(0xd10403ffULL) << 13);
    acc = (acc + a1 + 0xf90063f7ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #1840 | PC: 0x11b1bc | FDE: 0x148a38 | Size: 256 bytes [_ZN3com2ss5ttmio15MIOEventAdapter19postEventIfNotExistERNS1_8MDLEventEi]
// Hàm #1840 | Địa chỉ PC: 0x11b1bc | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x11b1bc: D10143FF  sub      sp, sp, #0x50
//   0x11b1c0: F9000BF7  str      x23, [sp, #0x10]
//   0x11b1c4: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x11b1c8: A9034FF4  stp      x20, x19, [sp, #0x30]
static inline uint64_t fde_func_1840_0x11b1bc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x11b1bcULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xf9000bf7ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #1841 | PC: 0x11b2d0 | FDE: 0x148a38 | Size: 256 bytes [_ZN3com2ss5ttmio15MIOEventAdapter24postEventDelayIfNotExistERNS1_8MDLEventEii]
// Hàm #1841 | Địa chỉ PC: 0x11b2d0 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x11b2d0: D10143FF  sub      sp, sp, #0x50
//   0x11b2d4: A9015FF8  stp      x24, x23, [sp, #0x10]
//   0x11b2d8: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x11b2dc: A9034FF4  stp      x20, x19, [sp, #0x30]
static inline uint64_t fde_func_1841_0x11b2d0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x11b2d0ULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xa9015ff8ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #1842 | PC: 0x11b3ec | FDE: 0x148a38 | Size: 256 bytes [_ZN3com2ss5ttmio15MIOEventAdapter9sendEventERNS1_8MDLEventE]
// Hàm #1842 | Địa chỉ PC: 0x11b3ec | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x11b3ec: D103C3FF  sub      sp, sp, #0xf0
//   0x11b3f0: A90C57F6  stp      x22, x21, [sp, #0xc0]
//   0x11b3f4: A90D4FF4  stp      x20, x19, [sp, #0xd0]
//   0x11b3f8: A90E7BFD  stp      x29, x30, [sp, #0xe0]
static inline uint64_t fde_func_1842_0x11b3ec(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x11b3ecULL ^ (static_cast<uint64_t>(0xd103c3ffULL) << 13);
    acc = (acc + a1 + 0xa90c57f6ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #1843 | PC: 0x11b504 | FDE: 0x148a38 | Size: 212 bytes [_ZN3com2ss5ttmio15MIOEventAdapter10eraseEventEi]
// Hàm #1843 | Địa chỉ PC: 0x11b504 | Địa chỉ FDE: 0x148a38 | Kích thước: 212 bytes
//   0x11b504: D100C3FF  sub      sp, sp, #0x30
//   0x11b508: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x11b50c: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x11b510: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1843_0x11b504(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x11b504ULL ^ (static_cast<uint64_t>(0xd100c3ffULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x00d4ULL;
    return acc;
}

// Func #1844 | PC: 0x11b5d8 | FDE: 0x148a38 | Size: 20 bytes [_ZN3com2ss5ttmio15MIOEventAdapter12postMIOEventERNS1_8MIOEventE]
// Hàm #1844 | Địa chỉ PC: 0x11b5d8 | Địa chỉ FDE: 0x148a38 | Kích thước: 20 bytes
//   0x11b5d8: F9400800  ldr      x0, [x0, #0x10]
//   0x11b5dc: 2A1F03E2  mov      w2, wzr
//   0x11b5e0: F9400009  ldr      x9, [x0]
//   0x11b5e4: F9401523  ldr      x3, [x9, #0x28]
static inline uint64_t fde_func_1844_0x11b5d8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x11b5d8ULL ^ (static_cast<uint64_t>(0xf9400800ULL) << 13);
    acc = (acc + a1 + 0x2a1f03e2ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0014ULL;
    return acc;
}

// Func #1845 | PC: 0x11b5ec | FDE: 0x148a38 | Size: 24 bytes [_ZN3com2ss5ttmio15MIOEventAdapter17postMIOEventDelayERNS1_8MIOEventEi]
// Hàm #1845 | Địa chỉ PC: 0x11b5ec | Địa chỉ FDE: 0x148a38 | Kích thước: 24 bytes
//   0x11b5ec: F9400800  ldr      x0, [x0, #0x10]
//   0x11b5f0: F9400009  ldr      x9, [x0]
//   0x11b5f4: F9401923  ldr      x3, [x9, #0x30]
//   0x11b5f8: 52807D09  mov      w9, #0x3e8
static inline uint64_t fde_func_1845_0x11b5ec(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x11b5ecULL ^ (static_cast<uint64_t>(0xf9400800ULL) << 13);
    acc = (acc + a1 + 0xf9400009ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0018ULL;
    return acc;
}

// Func #1846 | PC: 0x11b604 | FDE: 0x148a38 | Size: 232 bytes [_ZN3com2ss5ttmio15MIOEventAdapter22postMIOEventIfNotExistERNS1_8MIOEventENSt6__ndk110shared_ptrINS1_16MIOEventResponseEEE]
// Hàm #1846 | Địa chỉ PC: 0x11b604 | Địa chỉ FDE: 0x148a38 | Kích thước: 232 bytes
//   0x11b604: D10143FF  sub      sp, sp, #0x50
//   0x11b608: A9015FF8  stp      x24, x23, [sp, #0x10]
//   0x11b60c: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x11b610: A9034FF4  stp      x20, x19, [sp, #0x30]
static inline uint64_t fde_func_1846_0x11b604(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x11b604ULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xa9015ff8ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x00e8ULL;
    return acc;
}

// Func #1847 | PC: 0x11b6ec | FDE: 0x148a38 | Size: 244 bytes [_ZN3com2ss5ttmio15MIOEventAdapter27postMIOEventDelayIfNotExistERNS1_8MIOEventEiNSt6__ndk110shared_ptrINS1_16MIOEventResponseEEE]
// Hàm #1847 | Địa chỉ PC: 0x11b6ec | Địa chỉ FDE: 0x148a38 | Kích thước: 244 bytes
//   0x11b6ec: D10183FF  sub      sp, sp, #0x60
//   0x11b6f0: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x11b6f4: A90357F6  stp      x22, x21, [sp, #0x30]
//   0x11b6f8: A9044FF4  stp      x20, x19, [sp, #0x40]
static inline uint64_t fde_func_1847_0x11b6ec(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x11b6ecULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xa9025ff8ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x00f4ULL;
    return acc;
}

// Func #1848 | PC: 0x11b7e0 | FDE: 0x148a38 | Size: 156 bytes [_ZN3com2ss5ttmio15MIOEventAdapter13eraseMIOEventENSt6__ndk110shared_ptrINS1_16MIOEventResponseEEE]
// Hàm #1848 | Địa chỉ PC: 0x11b7e0 | Địa chỉ FDE: 0x148a38 | Kích thước: 156 bytes
//   0x11b7e0: D100C3FF  sub      sp, sp, #0x30
//   0x11b7e4: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x11b7e8: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x11b7ec: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1848_0x11b7e0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x11b7e0ULL ^ (static_cast<uint64_t>(0xd100c3ffULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x009cULL;
    return acc;
}

// Func #1849 | PC: 0x11b87c | FDE: 0x148a38 | Size: 20 bytes [_ZN3com2ss5ttmio15MIOEventAdapter12sendMIOEventERNS1_8MIOEventE]
// Hàm #1849 | Địa chỉ PC: 0x11b87c | Địa chỉ FDE: 0x148a38 | Kích thước: 20 bytes
//   0x11b87c: F9400800  ldr      x0, [x0, #0x10]
//   0x11b880: 2A1F03E2  mov      w2, wzr
//   0x11b884: F9400008  ldr      x8, [x0]
//   0x11b888: F9401103  ldr      x3, [x8, #0x20]
static inline uint64_t fde_func_1849_0x11b87c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x11b87cULL ^ (static_cast<uint64_t>(0xf9400800ULL) << 13);
    acc = (acc + a1 + 0x2a1f03e2ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0014ULL;
    return acc;
}

// Func #1850 | PC: 0x11b890 | FDE: 0x148a38 | Size: 8 bytes [_ZN3com2ss5ttmio13MDLEventQueue12postMIOEventERNS1_8MIOEventE]
// Hàm #1850 | Địa chỉ PC: 0x11b890 | Địa chỉ FDE: 0x148a38 | Kích thước: 8 bytes
//   0x11b890: A9007D1F  stp      xzr, xzr, [x8]
//   0x11b894: D65F03C0  ret      
static inline uint64_t fde_func_1850_0x11b890(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x11b890ULL ^ (static_cast<uint64_t>(0xa9007d1fULL) << 13);
    acc = (acc + a1 + 0xd65f03c0ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0008ULL;
    return acc;
}

// Func #1851 | PC: 0x11b898 | FDE: 0x148a38 | Size: 8 bytes [_ZN3com2ss5ttmio13MDLEventQueue17postMIOEventDelayERNS1_8MIOEventEi]
// Hàm #1851 | Địa chỉ PC: 0x11b898 | Địa chỉ FDE: 0x148a38 | Kích thước: 8 bytes
//   0x11b898: A9007D1F  stp      xzr, xzr, [x8]
//   0x11b89c: D65F03C0  ret      
static inline uint64_t fde_func_1851_0x11b898(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x11b898ULL ^ (static_cast<uint64_t>(0xa9007d1fULL) << 13);
    acc = (acc + a1 + 0xd65f03c0ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0008ULL;
    return acc;
}

// Func #1852 | PC: 0x11b8a0 | FDE: 0x148a38 | Size: 8 bytes [_ZN3com2ss5ttmio13MDLEventQueue22postMIOEventIfNotExistERNS1_8MIOEventENSt6__ndk110shared_ptrINS1_16MIOEventResponseEEE]
// Hàm #1852 | Địa chỉ PC: 0x11b8a0 | Địa chỉ FDE: 0x148a38 | Kích thước: 8 bytes
//   0x11b8a0: A9007D1F  stp      xzr, xzr, [x8]
//   0x11b8a4: D65F03C0  ret      
static inline uint64_t fde_func_1852_0x11b8a0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x11b8a0ULL ^ (static_cast<uint64_t>(0xa9007d1fULL) << 13);
    acc = (acc + a1 + 0xd65f03c0ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0008ULL;
    return acc;
}

// Func #1853 | PC: 0x11b8a8 | FDE: 0x148a38 | Size: 8 bytes [_ZN3com2ss5ttmio13MDLEventQueue27postMIOEventDelayIfNotExistERNS1_8MIOEventEiNSt6__ndk110shared_ptrINS1_16MIOEventResponseEEE]
// Hàm #1853 | Địa chỉ PC: 0x11b8a8 | Địa chỉ FDE: 0x148a38 | Kích thước: 8 bytes
//   0x11b8a8: A9007D1F  stp      xzr, xzr, [x8]
//   0x11b8ac: D65F03C0  ret      
static inline uint64_t fde_func_1853_0x11b8a8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x11b8a8ULL ^ (static_cast<uint64_t>(0xa9007d1fULL) << 13);
    acc = (acc + a1 + 0xd65f03c0ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0008ULL;
    return acc;
}

// Func #1854 | PC: 0x11b8b0 | FDE: 0x148a38 | Size: 8 bytes [_ZN3com2ss5ttmio13MDLEventQueue13eraseMIOEventENSt6__ndk110shared_ptrINS1_16MIOEventResponseEEE]
// Hàm #1854 | Địa chỉ PC: 0x11b8b0 | Địa chỉ FDE: 0x148a38 | Kích thước: 8 bytes
//   0x11b8b0: 52800020  mov      w0, #1
//   0x11b8b4: D65F03C0  ret      
static inline uint64_t fde_func_1854_0x11b8b0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x11b8b0ULL ^ (static_cast<uint64_t>(0x52800020ULL) << 13);
    acc = (acc + a1 + 0xd65f03c0ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0008ULL;
    return acc;
}

// Func #1855 | PC: 0x11b8b8 | FDE: 0x148a38 | Size: 8 bytes [_ZN3com2ss5ttmio13MDLEventQueue12sendMIOEventERNS1_8MIOEventE]
// Hàm #1855 | Địa chỉ PC: 0x11b8b8 | Địa chỉ FDE: 0x148a38 | Kích thước: 8 bytes
//   0x11b8b8: 2A1F03E0  mov      w0, wzr
//   0x11b8bc: D65F03C0  ret      
static inline uint64_t fde_func_1855_0x11b8b8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x11b8b8ULL ^ (static_cast<uint64_t>(0x2a1f03e0ULL) << 13);
    acc = (acc + a1 + 0xd65f03c0ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0008ULL;
    return acc;
}

// Func #1856 | PC: 0x11b8c0 | FDE: 0x148a38 | Size: 256 bytes [_ZN3com2ss5ttmio15MIOEventAdapter9rawWorkerEv]
// Hàm #1856 | Địa chỉ PC: 0x11b8c0 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x11b8c0: F9400809  ldr      x9, [x0, #0x10]
//   0x11b8c4: F9000109  str      x9, [x8]
//   0x11b8c8: F9400C09  ldr      x9, [x0, #0x18]
//   0x11b8cc: F9000509  str      x9, [x8, #8]
static inline uint64_t fde_func_1856_0x11b8c0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x11b8c0ULL ^ (static_cast<uint64_t>(0xf9400809ULL) << 13);
    acc = (acc + a1 + 0xf9000109ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #1857 | PC: 0x11e258 | FDE: 0x148a38 | Size: 144 bytes [_ZN3com2ss5ttmio15parseQueryValueEPKcS3_]
// Hàm #1857 | Địa chỉ PC: 0x11e258 | Địa chỉ FDE: 0x148a38 | Kích thước: 144 bytes
//   0x11e258: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x11e25c: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x11e260: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x11e264: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1857_0x11e258(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x11e258ULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0090ULL;
    return acc;
}

// Func #1858 | PC: 0x11e2e8 | FDE: 0x148a38 | Size: 256 bytes [_ZN3com2ss5ttmio21parseStringQueryValueEPKcS3_]
// Hàm #1858 | Địa chỉ PC: 0x11e2e8 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x11e2e8: F81C0FF7  str      x23, [sp, #-0x40]!
//   0x11e2ec: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x11e2f0: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x11e2f4: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_1858_0x11e2e8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x11e2e8ULL ^ (static_cast<uint64_t>(0xf81c0ff7ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #1859 | PC: 0x11e9e8 | FDE: 0x148a38 | Size: 256 bytes [_ZN3com2ss5ttmio15getItemFromBtagERKNSt6__ndk112basic_stringIcNS2_11char_traitsIcEENS2_9allocatorIcEEEEi]
// Hàm #1859 | Địa chỉ PC: 0x11e9e8 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x11e9e8: D10283FF  sub      sp, sp, #0xa0
//   0x11e9ec: A9046FFC  stp      x28, x27, [sp, #0x40]
//   0x11e9f0: A90567FA  stp      x26, x25, [sp, #0x50]
//   0x11e9f4: A9065FF8  stp      x24, x23, [sp, #0x60]
static inline uint64_t fde_func_1859_0x11e9e8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x11e9e8ULL ^ (static_cast<uint64_t>(0xd10283ffULL) << 13);
    acc = (acc + a1 + 0xa9046ffcULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #1860 | PC: 0x11ec14 | FDE: 0x148a38 | Size: 256 bytes [_ZN3com2ss5ttmio20getItemFromBtagValueEmi]
// Hàm #1860 | Địa chỉ PC: 0x11ec14 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x11ec14: 0B010428  add      w8, w1, w1, lsl #1
//   0x11ec18: 9AC82408  lsr      x8, x0, x8
//   0x11ec1c: 12000900  and      w0, w8, #7
//   0x11ec20: D65F03C0  ret      
static inline uint64_t fde_func_1860_0x11ec14(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x11ec14ULL ^ (static_cast<uint64_t>(0x0b010428ULL) << 13);
    acc = (acc + a1 + 0x9ac82408ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #1861 | PC: 0x11f21c | FDE: 0x148a38 | Size: 256 bytes [_ZN3com2ss5ttmio17parseUrlParameterERKNSt6__ndk112basic_stringIcNS2_11char_traitsIcEENS2_9allocatorIcEEEESA_]
// Hàm #1861 | Địa chỉ PC: 0x11f21c | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x11f21c: D10243FF  sub      sp, sp, #0x90
//   0x11f220: A9036FFC  stp      x28, x27, [sp, #0x30]
//   0x11f224: A90467FA  stp      x26, x25, [sp, #0x40]
//   0x11f228: A9055FF8  stp      x24, x23, [sp, #0x50]
static inline uint64_t fde_func_1861_0x11f21c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x11f21cULL ^ (static_cast<uint64_t>(0xd10243ffULL) << 13);
    acc = (acc + a1 + 0xa9036ffcULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #1862 | PC: 0x11f42c | FDE: 0x148a38 | Size: 28 bytes [_ZN3com2ss5ttmio10safeStringEPKc]
// Hàm #1862 | Địa chỉ PC: 0x11f42c | Địa chỉ FDE: 0x148a38 | Kích thước: 28 bytes
//   0x11f42c: AA0003E1  mov      x1, x0
//   0x11f430: AA0803E0  mov      x0, x8
//   0x11f434: B4000041  cbz      x1, #0x11f43c
//   0x11f438: 17FC5799  b        #0x3529c
static inline uint64_t fde_func_1862_0x11f42c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x11f42cULL ^ (static_cast<uint64_t>(0xaa0003e1ULL) << 13);
    acc = (acc + a1 + 0xaa0803e0ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x001cULL;
    return acc;
}

// Func #1863 | PC: 0x11f448 | FDE: 0x148a38 | Size: 24 bytes [_ZN3com2ss5ttmio14certVerifyImplEPvPKcs]
// Hàm #1863 | Địa chỉ PC: 0x11f448 | Địa chỉ FDE: 0x148a38 | Kích thước: 24 bytes
//   0x11f448: AA0103E8  mov      x8, x1
//   0x11f44c: 13003C43  sxth     w3, w2
//   0x11f450: AA0003E1  mov      x1, x0
//   0x11f454: AA1F03E0  mov      x0, xzr
static inline uint64_t fde_func_1863_0x11f448(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x11f448ULL ^ (static_cast<uint64_t>(0xaa0103e8ULL) << 13);
    acc = (acc + a1 + 0x13003c43ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0018ULL;
    return acc;
}

// Func #1864 | PC: 0x11f460 | FDE: 0x148a38 | Size: 256 bytes [_ZN3com2ss5ttmio22convertIpListToAddressEPKc]
// Hàm #1864 | Địa chỉ PC: 0x11f460 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x11f460: D10383FF  sub      sp, sp, #0xe0
//   0x11f464: A9086FFC  stp      x28, x27, [sp, #0x80]
//   0x11f468: A90967FA  stp      x26, x25, [sp, #0x90]
//   0x11f46c: A90A5FF8  stp      x24, x23, [sp, #0xa0]
static inline uint64_t fde_func_1864_0x11f460(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x11f460ULL ^ (static_cast<uint64_t>(0xd10383ffULL) << 13);
    acc = (acc + a1 + 0xa9086ffcULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #1865 | PC: 0x11f8cc | FDE: 0x148a38 | Size: 256 bytes [_ZN3com2ss5ttmio17convertToKVStringERKNSt6__ndk13mapINS2_12basic_stringIcNS2_11char_traitsIcEENS2_9allocatorIcEEEES9_NS2_4lessIS9_EENS7_INS2_4pairIKS9_S9_EEEEEE]
// Hàm #1865 | Địa chỉ PC: 0x11f8cc | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x11f8cc: D10683FF  sub      sp, sp, #0x1a0
//   0x11f8d0: A9146FFC  stp      x28, x27, [sp, #0x140]
//   0x11f8d4: A91567FA  stp      x26, x25, [sp, #0x150]
//   0x11f8d8: A9165FF8  stp      x24, x23, [sp, #0x160]
static inline uint64_t fde_func_1865_0x11f8cc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x11f8ccULL ^ (static_cast<uint64_t>(0xd10683ffULL) << 13);
    acc = (acc + a1 + 0xa9146ffcULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #1866 | PC: 0x11fafc | FDE: 0x148a38 | Size: 256 bytes [_ZN3com2ss5ttmio12needRedirectEi]
// Hàm #1866 | Địa chỉ PC: 0x11fafc | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x11fafc: 5104B408  sub      w8, w0, #0x12d
//   0x11fb00: 71001D1F  cmp      w8, #7
//   0x11fb04: 540000A8  b.hi     #0x11fb18
//   0x11fb08: 528018E9  mov      w9, #0xc7
static inline uint64_t fde_func_1866_0x11fafc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x11fafcULL ^ (static_cast<uint64_t>(0x5104b408ULL) << 13);
    acc = (acc + a1 + 0x71001d1fULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #1867 | PC: 0x131b3c | FDE: 0x148a38 | Size: 96 bytes [_ZN3com2ss3ttm10mdl2_utils8AVThreadC2EPNS2_16AVThreadListenerE]
// Hàm #1867 | Địa chỉ PC: 0x131b3c | Địa chỉ FDE: 0x148a38 | Kích thước: 96 bytes
//   0x131b3c: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x131b40: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x131b44: 910043FD  add      x29, sp, #0x10
//   0x131b48: 528000A8  mov      w8, #5
static inline uint64_t fde_func_1867_0x131b3c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x131b3cULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0060ULL;
    return acc;
}

// Func #1868 | PC: 0x131b9c | FDE: 0x148a38 | Size: 56 bytes [_ZN3com2ss3ttm10mdl2_utils8AVThreadD2Ev]
// Hàm #1868 | Địa chỉ PC: 0x131b9c | Địa chỉ FDE: 0x148a38 | Kích thước: 56 bytes
//   0x131b9c: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x131ba0: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x131ba4: 910043FD  add      x29, sp, #0x10
//   0x131ba8: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_1868_0x131b9c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x131b9cULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0038ULL;
    return acc;
}

// Func #1869 | PC: 0x131bd4 | FDE: 0x148a38 | Size: 8 bytes [_ZN3com2ss3ttm10mdl2_utils8AVThread5getIdEv]
// Hàm #1869 | Địa chỉ PC: 0x131bd4 | Địa chỉ FDE: 0x148a38 | Kích thước: 8 bytes
//   0x131bd4: F9400800  ldr      x0, [x0, #0x10]
//   0x131bd8: D65F03C0  ret      
static inline uint64_t fde_func_1869_0x131bd4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x131bd4ULL ^ (static_cast<uint64_t>(0xf9400800ULL) << 13);
    acc = (acc + a1 + 0xd65f03c0ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0008ULL;
    return acc;
}

// Func #1870 | PC: 0x131bdc | FDE: 0x148a38 | Size: 116 bytes [_ZN3com2ss3ttm10mdl2_utils8AVThread7setNameEPKc]
// Hàm #1870 | Địa chỉ PC: 0x131bdc | Địa chỉ FDE: 0x148a38 | Kích thước: 116 bytes
//   0x131bdc: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x131be0: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x131be4: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x131be8: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1870_0x131bdc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x131bdcULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0074ULL;
    return acc;
}

// Func #1871 | PC: 0x131c50 | FDE: 0x148a38 | Size: 232 bytes [_ZN3com2ss3ttm10mdl2_utils8AVThread4openEPNS2_11AVProcessorE]
// Hàm #1871 | Địa chỉ PC: 0x131c50 | Địa chỉ FDE: 0x148a38 | Kích thước: 232 bytes
//   0x131c50: D101C3FF  sub      sp, sp, #0x70
//   0x131c54: A90457F6  stp      x22, x21, [sp, #0x40]
//   0x131c58: A9054FF4  stp      x20, x19, [sp, #0x50]
//   0x131c5c: A9067BFD  stp      x29, x30, [sp, #0x60]
static inline uint64_t fde_func_1871_0x131c50(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x131c50ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xa90457f6ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x00e8ULL;
    return acc;
}

// Func #1872 | PC: 0x131d38 | FDE: 0x148a38 | Size: 24 bytes [_ZN3com2ss3ttm10mdl2_utils8AVThread10thread_funEPv]
// Hàm #1872 | Địa chỉ PC: 0x131d38 | Địa chỉ FDE: 0x148a38 | Kích thước: 24 bytes
//   0x131d38: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x131d3c: 910003FD  mov      x29, sp
//   0x131d40: 97FC0730  bl       #0x33a00
//   0x131d44: AA1F03E0  mov      x0, xzr
static inline uint64_t fde_func_1872_0x131d38(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x131d38ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0018ULL;
    return acc;
}

// Func #1873 | PC: 0x131d50 | FDE: 0x148a38 | Size: 256 bytes [_ZN3com2ss3ttm10mdl2_utils8AVThread3runEv]
// Hàm #1873 | Địa chỉ PC: 0x131d50 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x131d50: F81B0FF9  str      x25, [sp, #-0x50]!
//   0x131d54: A9015FF8  stp      x24, x23, [sp, #0x10]
//   0x131d58: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x131d5c: A9034FF4  stp      x20, x19, [sp, #0x30]
static inline uint64_t fde_func_1873_0x131d50(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x131d50ULL ^ (static_cast<uint64_t>(0xf81b0ff9ULL) << 13);
    acc = (acc + a1 + 0xa9015ff8ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #1874 | PC: 0x131e94 | FDE: 0x148a38 | Size: 96 bytes [_ZN3com2ss3ttm10mdl2_utils8AVThread5closeEv]
// Hàm #1874 | Địa chỉ PC: 0x131e94 | Địa chỉ FDE: 0x148a38 | Kích thước: 96 bytes
//   0x131e94: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x131e98: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x131e9c: 910043FD  add      x29, sp, #0x10
//   0x131ea0: B9400008  ldr      w8, [x0]
static inline uint64_t fde_func_1874_0x131e94(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x131e94ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0060ULL;
    return acc;
}

// Func #1875 | PC: 0x131ef4 | FDE: 0x148a38 | Size: 8 bytes [_ZN3com2ss3ttm10mdl2_utils8AVThread12setProcessorEPNS2_11AVProcessorE]
// Hàm #1875 | Địa chỉ PC: 0x131ef4 | Địa chỉ FDE: 0x148a38 | Kích thước: 8 bytes
//   0x131ef4: F9006801  str      x1, [x0, #0xd0]
//   0x131ef8: D65F03C0  ret      
static inline uint64_t fde_func_1875_0x131ef4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x131ef4ULL ^ (static_cast<uint64_t>(0xf9006801ULL) << 13);
    acc = (acc + a1 + 0xd65f03c0ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0008ULL;
    return acc;
}

// Func #1876 | PC: 0x131efc | FDE: 0x148a38 | Size: 164 bytes [_ZN3com2ss3ttm10mdl2_utils8AVThread5startEb]
// Hàm #1876 | Địa chỉ PC: 0x131efc | Địa chỉ FDE: 0x148a38 | Kích thước: 164 bytes
//   0x131efc: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x131f00: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x131f04: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x131f08: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1876_0x131efc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x131efcULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x00a4ULL;
    return acc;
}

// Func #1877 | PC: 0x131fa0 | FDE: 0x148a38 | Size: 72 bytes [_ZN3com2ss3ttm10mdl2_utils8AVThread4stopEv]
// Hàm #1877 | Địa chỉ PC: 0x131fa0 | Địa chỉ FDE: 0x148a38 | Kích thước: 72 bytes
//   0x131fa0: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x131fa4: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x131fa8: 910043FD  add      x29, sp, #0x10
//   0x131fac: 91006013  add      x19, x0, #0x18
static inline uint64_t fde_func_1877_0x131fa0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x131fa0ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0048ULL;
    return acc;
}

// Func #1878 | PC: 0x131fe8 | FDE: 0x148a38 | Size: 8 bytes [_ZN3com2ss3ttm10mdl2_utils8AVThread18setIdleExpiredTimeEl]
// Hàm #1878 | Địa chỉ PC: 0x131fe8 | Địa chỉ FDE: 0x148a38 | Kích thước: 8 bytes
//   0x131fe8: F9007001  str      x1, [x0, #0xe0]
//   0x131fec: D65F03C0  ret      
static inline uint64_t fde_func_1878_0x131fe8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x131fe8ULL ^ (static_cast<uint64_t>(0xf9007001ULL) << 13);
    acc = (acc + a1 + 0xd65f03c0ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0008ULL;
    return acc;
}

// Func #1879 | PC: 0x131ff0 | FDE: 0x148a38 | Size: 8 bytes [_ZN3com2ss3ttm10mdl2_utils8AVThread18getIdleExpiredTimeEv]
// Hàm #1879 | Địa chỉ PC: 0x131ff0 | Địa chỉ FDE: 0x148a38 | Kích thước: 8 bytes
//   0x131ff0: F9407000  ldr      x0, [x0, #0xe0]
//   0x131ff4: D65F03C0  ret      
static inline uint64_t fde_func_1879_0x131ff0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x131ff0ULL ^ (static_cast<uint64_t>(0xf9407000ULL) << 13);
    acc = (acc + a1 + 0xd65f03c0ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0008ULL;
    return acc;
}

// Func #1880 | PC: 0x131ff8 | FDE: 0x148a38 | Size: 36 bytes [_ZN3com2ss3ttm11MDLNotifyerC2Ev]
// Hàm #1880 | Địa chỉ PC: 0x131ff8 | Địa chỉ FDE: 0x148a38 | Kích thước: 36 bytes
//   0x131ff8: D0000148  adrp     x8, #0x15b000
//   0x131ffc: F9453D08  ldr      x8, [x8, #0xa78]
//   0x132000: 6F00E400  movi     v0.2d, #0000000000000000
//   0x132004: 3C808000  stur     q0, [x0, #8]
static inline uint64_t fde_func_1880_0x131ff8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x131ff8ULL ^ (static_cast<uint64_t>(0xd0000148ULL) << 13);
    acc = (acc + a1 + 0xf9453d08ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0024ULL;
    return acc;
}

// Func #1881 | PC: 0x13201c | FDE: 0x148a38 | Size: 4 bytes [_ZN3com2ss3ttm11MDLNotifyerD2Ev]
// Hàm #1881 | Địa chỉ PC: 0x13201c | Địa chỉ FDE: 0x148a38 | Kích thước: 4 bytes
//   0x13201c: D65F03C0  ret      
static inline uint64_t fde_func_1881_0x13201c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x13201cULL ^ (static_cast<uint64_t>(0xd65f03c0ULL) << 13);
    acc = (acc + a1 + 0x17fc0414ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0004ULL;
    return acc;
}

// Func #1882 | PC: 0x132020 | FDE: 0x148a38 | Size: 4 bytes [_ZN3com2ss3ttm11MDLNotifyerD0Ev]
// Hàm #1882 | Địa chỉ PC: 0x132020 | Địa chỉ FDE: 0x148a38 | Kích thước: 4 bytes
//   0x132020: 17FC0414  b        #0x33070
static inline uint64_t fde_func_1882_0x132020(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x132020ULL ^ (static_cast<uint64_t>(0x17fc0414ULL) << 13);
    acc = (acc + a1 + 0xf9400c05ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0004ULL;
    return acc;
}

// Func #1883 | PC: 0x132024 | FDE: 0x148a38 | Size: 20 bytes [_ZN3com2ss3ttm11MDLNotifyer12onNotifyInfoEiiiPKc]
// Hàm #1883 | Địa chỉ PC: 0x132024 | Địa chỉ FDE: 0x148a38 | Kích thước: 20 bytes
//   0x132024: F9400C05  ldr      x5, [x0, #0x18]
//   0x132028: B4000065  cbz      x5, #0x132034
//   0x13202c: F9400400  ldr      x0, [x0, #8]
//   0x132030: D61F00A0  br       x5
static inline uint64_t fde_func_1883_0x132024(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x132024ULL ^ (static_cast<uint64_t>(0xf9400c05ULL) << 13);
    acc = (acc + a1 + 0xb4000065ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0014ULL;
    return acc;
}

// Func #1884 | PC: 0x132038 | FDE: 0x148a38 | Size: 20 bytes [_ZN3com2ss3ttm11MDLNotifyer9onLogInfoEiiPKc]
// Hàm #1884 | Địa chỉ PC: 0x132038 | Địa chỉ FDE: 0x148a38 | Kích thước: 20 bytes
//   0x132038: F9400804  ldr      x4, [x0, #0x10]
//   0x13203c: B4000064  cbz      x4, #0x132048
//   0x132040: F9400400  ldr      x0, [x0, #8]
//   0x132044: D61F0080  br       x4
static inline uint64_t fde_func_1884_0x132038(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x132038ULL ^ (static_cast<uint64_t>(0xf9400804ULL) << 13);
    acc = (acc + a1 + 0xb4000064ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0014ULL;
    return acc;
}

// Func #1885 | PC: 0x13204c | FDE: 0x148a38 | Size: 24 bytes [_ZN3com2ss3ttm11MDLNotifyer13getInt64ValueEilPKc]
// Hàm #1885 | Địa chỉ PC: 0x13204c | Địa chỉ FDE: 0x148a38 | Kích thước: 24 bytes
//   0x13204c: F9401004  ldr      x4, [x0, #0x20]
//   0x132050: B4000064  cbz      x4, #0x13205c
//   0x132054: F9400400  ldr      x0, [x0, #8]
//   0x132058: D61F0080  br       x4
static inline uint64_t fde_func_1885_0x13204c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x13204cULL ^ (static_cast<uint64_t>(0xf9401004ULL) << 13);
    acc = (acc + a1 + 0xb4000064ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0018ULL;
    return acc;
}

// Func #1886 | PC: 0x132064 | FDE: 0x148a38 | Size: 28 bytes [_ZN3com2ss3ttm11MDLNotifyer14getStringValueEiiPKc]
// Hàm #1886 | Địa chỉ PC: 0x132064 | Địa chỉ FDE: 0x148a38 | Kích thước: 28 bytes
//   0x132064: F9401404  ldr      x4, [x0, #0x28]
//   0x132068: B4000084  cbz      x4, #0x132078
//   0x13206c: F9400400  ldr      x0, [x0, #8]
//   0x132070: 93407C42  sxtw     x2, w2
static inline uint64_t fde_func_1886_0x132064(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x132064ULL ^ (static_cast<uint64_t>(0xf9401404ULL) << 13);
    acc = (acc + a1 + 0xb4000084ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x001cULL;
    return acc;
}

// Func #1887 | PC: 0x132080 | FDE: 0x148a38 | Size: 20 bytes [_ZN3com2ss3ttm11MDLNotifyer17onLoaderEventInfoEiPKcS4_illl]
// Hàm #1887 | Địa chỉ PC: 0x132080 | Địa chỉ FDE: 0x148a38 | Kích thước: 20 bytes
//   0x132080: F9401808  ldr      x8, [x0, #0x30]
//   0x132084: B4000068  cbz      x8, #0x132090
//   0x132088: F9400400  ldr      x0, [x0, #8]
//   0x13208c: D61F0100  br       x8
static inline uint64_t fde_func_1887_0x132080(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x132080ULL ^ (static_cast<uint64_t>(0xf9401808ULL) << 13);
    acc = (acc + a1 + 0xb4000068ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0014ULL;
    return acc;
}

// Func #1888 | PC: 0x132094 | FDE: 0x148a38 | Size: 16 bytes [_ZN3com2ss3ttm11MDLNotifyer15setUserCallbackEPvPFvS3_iiPKcEPFvS3_iiiS5_EPFlS3_ilS5_EPFPcS3_ilS5_EPFvS3_iS5_S5_illlE]
// Hàm #1888 | Địa chỉ PC: 0x132094 | Địa chỉ FDE: 0x148a38 | Kích thước: 16 bytes
//   0x132094: A9008801  stp      x1, x2, [x0, #8]
//   0x132098: A9019003  stp      x3, x4, [x0, #0x18]
//   0x13209c: A9029805  stp      x5, x6, [x0, #0x28]
//   0x1320a0: D65F03C0  ret      
static inline uint64_t fde_func_1888_0x132094(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x132094ULL ^ (static_cast<uint64_t>(0xa9008801ULL) << 13);
    acc = (acc + a1 + 0xa9019003ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0010ULL;
    return acc;
}

// Func #1889 | PC: 0x1320a4 | FDE: 0x148a50 | Size: 256 bytes
// Hàm #1889 | Địa chỉ PC: 0x1320a4 | Địa chỉ FDE: 0x148a50 | Kích thước: 256 bytes
//   0x1320a4: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x1320a8: 9E660000  fmov     x0, d0
//   0x1320ac: 9EAE0001  fmov     x1, v0.d[1]
//   0x1320b0: 910003FD  mov      x29, sp
static inline uint64_t fde_func_1889_0x1320a4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1320a4ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x9e660000ULL) ^ 0x148a50ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #1890 | PC: 0x1321e0 | FDE: 0x148a78 | Size: 256 bytes
// Hàm #1890 | Địa chỉ PC: 0x1321e0 | Địa chỉ FDE: 0x148a78 | Kích thước: 256 bytes
//   0x1321e0: 9E660000  fmov     x0, d0
//   0x1321e4: 9EAE0001  fmov     x1, v0.d[1]
//   0x1321e8: A9BD7BFD  stp      x29, x30, [sp, #-0x30]!
//   0x1321ec: AA0003E3  mov      x3, x0
static inline uint64_t fde_func_1890_0x1321e0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1321e0ULL ^ (static_cast<uint64_t>(0x9e660000ULL) << 13);
    acc = (acc + a1 + 0x9eae0001ULL) ^ 0x148a78ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #1891 | PC: 0x1328c0 | FDE: 0x148aa8 | Size: 256 bytes
// Hàm #1891 | Địa chỉ PC: 0x1328c0 | Địa chỉ FDE: 0x148aa8 | Kích thước: 256 bytes
//   0x1328c0: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x1328c4: 9E660000  fmov     x0, d0
//   0x1328c8: 9EAE0001  fmov     x1, v0.d[1]
//   0x1328cc: 910003FD  mov      x29, sp
static inline uint64_t fde_func_1891_0x1328c0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1328c0ULL ^ (static_cast<uint64_t>(0xa9be7bfdULL) << 13);
    acc = (acc + a1 + 0x9e660000ULL) ^ 0x148aa8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #1892 | PC: 0x1333d4 | FDE: 0x148ad0 | Size: 140 bytes
// Hàm #1892 | Địa chỉ PC: 0x1333d4 | Địa chỉ FDE: 0x148ad0 | Kích thước: 140 bytes
//   0x1333d4: B4000300  cbz      x0, #0x133434
//   0x1333d8: D37FFC01  lsr      x1, x0, #0x3f
//   0x1333dc: D2880DE3  mov      x3, #0x406f
//   0x1333e0: 6B1F003F  cmp      w1, wzr
static inline uint64_t fde_func_1892_0x1333d4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1333d4ULL ^ (static_cast<uint64_t>(0xb4000300ULL) << 13);
    acc = (acc + a1 + 0xd37ffc01ULL) ^ 0x148ad0ULL;
    acc ^= (acc >> 17) * 0x008cULL;
    return acc;
}

// Func #1893 | PC: 0x133460 | FDE: 0x148ae8 | Size: 64 bytes
// Hàm #1893 | Địa chỉ PC: 0x133460 | Địa chỉ FDE: 0x148ae8 | Kích thước: 64 bytes
//   0x133460: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x133464: 90000001  adrp     x1, #0x133000
//   0x133468: 910003FD  mov      x29, sp
//   0x13346c: F9000BF3  str      x19, [sp, #0x10]
static inline uint64_t fde_func_1893_0x133460(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x133460ULL ^ (static_cast<uint64_t>(0xa9be7bfdULL) << 13);
    acc = (acc + a1 + 0x90000001ULL) ^ 0x148ae8ULL;
    acc ^= (acc >> 17) * 0x0040ULL;
    return acc;
}

// Func #1894 | PC: 0x1334a0 | FDE: 0x148b10 | Size: 128 bytes
// Hàm #1894 | Địa chỉ PC: 0x1334a0 | Địa chỉ FDE: 0x148b10 | Kích thước: 128 bytes
//   0x1334a0: A9BD7BFD  stp      x29, x30, [sp, #-0x30]!
//   0x1334a4: AA0003E1  mov      x1, x0
//   0x1334a8: 910003FD  mov      x29, sp
//   0x1334ac: F9400000  ldr      x0, [x0]
static inline uint64_t fde_func_1894_0x1334a0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1334a0ULL ^ (static_cast<uint64_t>(0xa9bd7bfdULL) << 13);
    acc = (acc + a1 + 0xaa0003e1ULL) ^ 0x148b10ULL;
    acc ^= (acc >> 17) * 0x0080ULL;
    return acc;
}

// Func #1895 | PC: 0x133520 | FDE: 0x148b50 | Size: 152 bytes
// Hàm #1895 | Địa chỉ PC: 0x133520 | Địa chỉ FDE: 0x148b50 | Kích thước: 152 bytes
//   0x133520: A9BD7BFD  stp      x29, x30, [sp, #-0x30]!
//   0x133524: 910003FD  mov      x29, sp
//   0x133528: A90153F3  stp      x19, x20, [sp, #0x10]
//   0x13352c: F9400414  ldr      x20, [x0, #8]
static inline uint64_t fde_func_1895_0x133520(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x133520ULL ^ (static_cast<uint64_t>(0xa9bd7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x148b50ULL;
    acc ^= (acc >> 17) * 0x0098ULL;
    return acc;
}

// Func #1896 | PC: 0x1335b8 | FDE: 0x148b80 | Size: 32 bytes
// Hàm #1896 | Địa chỉ PC: 0x1335b8 | Địa chỉ FDE: 0x148b80 | Kích thước: 32 bytes
//   0x1335b8: B0000140  adrp     x0, #0x15c000
//   0x1335bc: 9119A001  add      x1, x0, #0x668
//   0x1335c0: B9400422  ldr      w2, [x1, #4]
//   0x1335c4: 34000082  cbz      w2, #0x1335d4
static inline uint64_t fde_func_1896_0x1335b8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1335b8ULL ^ (static_cast<uint64_t>(0xb0000140ULL) << 13);
    acc = (acc + a1 + 0x9119a001ULL) ^ 0x148b80ULL;
    acc ^= (acc >> 17) * 0x0020ULL;
    return acc;
}

// Func #1897 | PC: 0x1335d8 | FDE: 0x148b98 | Size: 256 bytes
// Hàm #1897 | Địa chỉ PC: 0x1335d8 | Địa chỉ FDE: 0x148b98 | Kích thước: 256 bytes
//   0x1335d8: 90000141  adrp     x1, #0x15b000
//   0x1335dc: A9BC7BFD  stp      x29, x30, [sp, #-0x40]!
//   0x1335e0: 910003FD  mov      x29, sp
//   0x1335e4: F942B821  ldr      x1, [x1, #0x570]
static inline uint64_t fde_func_1897_0x1335d8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1335d8ULL ^ (static_cast<uint64_t>(0x90000141ULL) << 13);
    acc = (acc + a1 + 0xa9bc7bfdULL) ^ 0x148b98ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #1898 | PC: 0x133730 | FDE: 0x148bd0 | Size: 60 bytes
// Hàm #1898 | Địa chỉ PC: 0x133730 | Địa chỉ FDE: 0x148bd0 | Kích thước: 60 bytes
//   0x133730: F9400004  ldr      x4, [x0]
//   0x133734: EB01009F  cmp      x4, x1
//   0x133738: 54000062  b.hs     #0x133744
//   0x13373c: F9000001  str      x1, [x0]
static inline uint64_t fde_func_1898_0x133730(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x133730ULL ^ (static_cast<uint64_t>(0xf9400004ULL) << 13);
    acc = (acc + a1 + 0xeb01009fULL) ^ 0x148bd0ULL;
    acc ^= (acc >> 17) * 0x003cULL;
    return acc;
}

// Func #1899 | PC: 0x13376c | FDE: 0x148be8 | Size: 108 bytes
// Hàm #1899 | Địa chỉ PC: 0x13376c | Địa chỉ FDE: 0x148be8 | Kích thước: 108 bytes
//   0x13376c: 36000080  tbz      w0, #0, #0x13377c
//   0x133770: 1E2703E1  fmov     s1, wzr
//   0x133774: 1E211820  fdiv     s0, s1, s1
//   0x133778: D53B4421  mrs      x1, fpsr
static inline uint64_t fde_func_1899_0x13376c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x13376cULL ^ (static_cast<uint64_t>(0x36000080ULL) << 13);
    acc = (acc + a1 + 0x1e2703e1ULL) ^ 0x148be8ULL;
    acc ^= (acc >> 17) * 0x006cULL;
    return acc;
}

// Shard 5 Dispatcher / Bộ điều phối phân mảnh 5
uint64_t execute_fde_shard_5(uint32_t fde_idx, uint64_t a0, uint64_t a1) {
    switch (fde_idx) {
        case 1520: return fde_func_1520_0x0d8b4c(a0, a1);
        case 1521: return fde_func_1521_0x0d965c(a0, a1);
        case 1522: return fde_func_1522_0x0d9760(a0, a1);
        case 1523: return fde_func_1523_0x0d99cc(a0, a1);
        case 1524: return fde_func_1524_0x0d9c88(a0, a1);
        case 1525: return fde_func_1525_0x0d9ca4(a0, a1);
        case 1526: return fde_func_1526_0x0da0b8(a0, a1);
        case 1527: return fde_func_1527_0x0da214(a0, a1);
        case 1528: return fde_func_1528_0x0da338(a0, a1);
        case 1529: return fde_func_1529_0x0da5bc(a0, a1);
        case 1530: return fde_func_1530_0x0da770(a0, a1);
        case 1531: return fde_func_1531_0x0da8f8(a0, a1);
        case 1532: return fde_func_1532_0x0dab20(a0, a1);
        case 1533: return fde_func_1533_0x0db1b4(a0, a1);
        case 1534: return fde_func_1534_0x0db87c(a0, a1);
        case 1535: return fde_func_1535_0x0dbd0c(a0, a1);
        case 1536: return fde_func_1536_0x0dc12c(a0, a1);
        case 1537: return fde_func_1537_0x0dc218(a0, a1);
        case 1538: return fde_func_1538_0x0dcb58(a0, a1);
        case 1539: return fde_func_1539_0x0dcd2c(a0, a1);
        case 1540: return fde_func_1540_0x0dcf74(a0, a1);
        case 1541: return fde_func_1541_0x0dcfcc(a0, a1);
        case 1542: return fde_func_1542_0x0dd024(a0, a1);
        case 1543: return fde_func_1543_0x0dd0dc(a0, a1);
        case 1544: return fde_func_1544_0x0dd378(a0, a1);
        case 1545: return fde_func_1545_0x0dd5f0(a0, a1);
        case 1546: return fde_func_1546_0x0dd974(a0, a1);
        case 1547: return fde_func_1547_0x0ddca4(a0, a1);
        case 1548: return fde_func_1548_0x0ddd08(a0, a1);
        case 1549: return fde_func_1549_0x0ddde8(a0, a1);
        case 1550: return fde_func_1550_0x0ddf38(a0, a1);
        case 1551: return fde_func_1551_0x0de0ac(a0, a1);
        case 1552: return fde_func_1552_0x0de1b4(a0, a1);
        case 1553: return fde_func_1553_0x0de32c(a0, a1);
        case 1554: return fde_func_1554_0x0de3e4(a0, a1);
        case 1555: return fde_func_1555_0x0de878(a0, a1);
        case 1556: return fde_func_1556_0x0de918(a0, a1);
        case 1557: return fde_func_1557_0x0de95c(a0, a1);
        case 1558: return fde_func_1558_0x0dea28(a0, a1);
        case 1559: return fde_func_1559_0x0ded30(a0, a1);
        case 1560: return fde_func_1560_0x0ded64(a0, a1);
        case 1561: return fde_func_1561_0x0ded80(a0, a1);
        case 1562: return fde_func_1562_0x0df26c(a0, a1);
        case 1563: return fde_func_1563_0x0df2e4(a0, a1);
        case 1564: return fde_func_1564_0x0df3c8(a0, a1);
        case 1565: return fde_func_1565_0x0df4ac(a0, a1);
        case 1566: return fde_func_1566_0x0df54c(a0, a1);
        case 1567: return fde_func_1567_0x0df7d8(a0, a1);
        case 1568: return fde_func_1568_0x0df92c(a0, a1);
        case 1569: return fde_func_1569_0x0df9c0(a0, a1);
        case 1570: return fde_func_1570_0x0dfa28(a0, a1);
        case 1571: return fde_func_1571_0x0dfa64(a0, a1);
        case 1572: return fde_func_1572_0x0dfb90(a0, a1);
        case 1573: return fde_func_1573_0x0dfc08(a0, a1);
        case 1574: return fde_func_1574_0x0dfe9c(a0, a1);
        case 1575: return fde_func_1575_0x0dffb8(a0, a1);
        case 1576: return fde_func_1576_0x0e00fc(a0, a1);
        case 1577: return fde_func_1577_0x0e0364(a0, a1);
        case 1578: return fde_func_1578_0x0e0540(a0, a1);
        case 1579: return fde_func_1579_0x0e074c(a0, a1);
        case 1580: return fde_func_1580_0x0e0888(a0, a1);
        case 1581: return fde_func_1581_0x0e0b0c(a0, a1);
        case 1582: return fde_func_1582_0x0e0d48(a0, a1);
        case 1583: return fde_func_1583_0x0e130c(a0, a1);
        case 1584: return fde_func_1584_0x0e144c(a0, a1);
        case 1585: return fde_func_1585_0x0e1594(a0, a1);
        case 1586: return fde_func_1586_0x0e15dc(a0, a1);
        case 1587: return fde_func_1587_0x0e1750(a0, a1);
        case 1588: return fde_func_1588_0x0e17e8(a0, a1);
        case 1589: return fde_func_1589_0x0e1958(a0, a1);
        case 1590: return fde_func_1590_0x0e1aac(a0, a1);
        case 1591: return fde_func_1591_0x0e1c64(a0, a1);
        case 1592: return fde_func_1592_0x0e1d28(a0, a1);
        case 1593: return fde_func_1593_0x0e1da0(a0, a1);
        case 1594: return fde_func_1594_0x0e1dd8(a0, a1);
        case 1595: return fde_func_1595_0x0e212c(a0, a1);
        case 1596: return fde_func_1596_0x0e2150(a0, a1);
        case 1597: return fde_func_1597_0x0e2a8c(a0, a1);
        case 1598: return fde_func_1598_0x0e2acc(a0, a1);
        case 1599: return fde_func_1599_0x0e2f34(a0, a1);
        case 1600: return fde_func_1600_0x0e3088(a0, a1);
        case 1601: return fde_func_1601_0x0e31a8(a0, a1);
        case 1602: return fde_func_1602_0x0e330c(a0, a1);
        case 1603: return fde_func_1603_0x0e34cc(a0, a1);
        case 1604: return fde_func_1604_0x0e38f0(a0, a1);
        case 1605: return fde_func_1605_0x0e3b58(a0, a1);
        case 1606: return fde_func_1606_0x0e3cf8(a0, a1);
        case 1607: return fde_func_1607_0x0e3d34(a0, a1);
        case 1608: return fde_func_1608_0x0e3f30(a0, a1);
        case 1609: return fde_func_1609_0x0e44f0(a0, a1);
        case 1610: return fde_func_1610_0x0e4840(a0, a1);
        case 1611: return fde_func_1611_0x0e4970(a0, a1);
        case 1612: return fde_func_1612_0x0e4b10(a0, a1);
        case 1613: return fde_func_1613_0x0e4b84(a0, a1);
        case 1614: return fde_func_1614_0x0e4d4c(a0, a1);
        case 1615: return fde_func_1615_0x0e4dc4(a0, a1);
        case 1616: return fde_func_1616_0x0e4f0c(a0, a1);
        case 1617: return fde_func_1617_0x0e5040(a0, a1);
        case 1618: return fde_func_1618_0x0e5260(a0, a1);
        case 1619: return fde_func_1619_0x0e527c(a0, a1);
        case 1620: return fde_func_1620_0x0e5744(a0, a1);
        case 1621: return fde_func_1621_0x0e5824(a0, a1);
        case 1622: return fde_func_1622_0x0e5ba8(a0, a1);
        case 1623: return fde_func_1623_0x0e5cc0(a0, a1);
        case 1624: return fde_func_1624_0x0e5dd8(a0, a1);
        case 1625: return fde_func_1625_0x0e6110(a0, a1);
        case 1626: return fde_func_1626_0x0e65d0(a0, a1);
        case 1627: return fde_func_1627_0x0e6950(a0, a1);
        case 1628: return fde_func_1628_0x0e6dfc(a0, a1);
        case 1629: return fde_func_1629_0x0e6f78(a0, a1);
        case 1630: return fde_func_1630_0x0e72a8(a0, a1);
        case 1631: return fde_func_1631_0x0e730c(a0, a1);
        case 1632: return fde_func_1632_0x0e73ec(a0, a1);
        case 1633: return fde_func_1633_0x0e75cc(a0, a1);
        case 1634: return fde_func_1634_0x0e7694(a0, a1);
        case 1635: return fde_func_1635_0x0e7744(a0, a1);
        case 1636: return fde_func_1636_0x0e7798(a0, a1);
        case 1637: return fde_func_1637_0x0e7c30(a0, a1);
        case 1638: return fde_func_1638_0x0e7ec4(a0, a1);
        case 1639: return fde_func_1639_0x0e816c(a0, a1);
        case 1640: return fde_func_1640_0x0e8270(a0, a1);
        case 1641: return fde_func_1641_0x0e86e0(a0, a1);
        case 1642: return fde_func_1642_0x0e8814(a0, a1);
        case 1643: return fde_func_1643_0x0e898c(a0, a1);
        case 1644: return fde_func_1644_0x0e8b18(a0, a1);
        case 1645: return fde_func_1645_0x0e8b68(a0, a1);
        case 1646: return fde_func_1646_0x0e8d04(a0, a1);
        case 1647: return fde_func_1647_0x0e8e84(a0, a1);
        case 1648: return fde_func_1648_0x0e9060(a0, a1);
        case 1649: return fde_func_1649_0x0e9298(a0, a1);
        case 1650: return fde_func_1650_0x0e92b4(a0, a1);
        case 1651: return fde_func_1651_0x0e9b78(a0, a1);
        case 1652: return fde_func_1652_0x0e9cbc(a0, a1);
        case 1653: return fde_func_1653_0x0e9e60(a0, a1);
        case 1654: return fde_func_1654_0x0e9eb0(a0, a1);
        case 1655: return fde_func_1655_0x0ea1bc(a0, a1);
        case 1656: return fde_func_1656_0x0ea2cc(a0, a1);
        case 1657: return fde_func_1657_0x0ea4e4(a0, a1);
        case 1658: return fde_func_1658_0x0ea780(a0, a1);
        case 1659: return fde_func_1659_0x0ea808(a0, a1);
        case 1660: return fde_func_1660_0x0ea9c0(a0, a1);
        case 1661: return fde_func_1661_0x0eb040(a0, a1);
        case 1662: return fde_func_1662_0x0eb05c(a0, a1);
        case 1663: return fde_func_1663_0x0eb2dc(a0, a1);
        case 1664: return fde_func_1664_0x0eb568(a0, a1);
        case 1665: return fde_func_1665_0x0eb5b8(a0, a1);
        case 1666: return fde_func_1666_0x0eb798(a0, a1);
        case 1667: return fde_func_1667_0x0eb8cc(a0, a1);
        case 1668: return fde_func_1668_0x0ebbc4(a0, a1);
        case 1669: return fde_func_1669_0x0ebe54(a0, a1);
        case 1670: return fde_func_1670_0x0ebe78(a0, a1);
        case 1671: return fde_func_1671_0x0ebed8(a0, a1);
        case 1672: return fde_func_1672_0x0ec0d8(a0, a1);
        case 1673: return fde_func_1673_0x0ec140(a0, a1);
        case 1674: return fde_func_1674_0x0ec1d8(a0, a1);
        case 1675: return fde_func_1675_0x0ec340(a0, a1);
        case 1676: return fde_func_1676_0x0ec3f4(a0, a1);
        case 1677: return fde_func_1677_0x0ec590(a0, a1);
        case 1678: return fde_func_1678_0x0ec608(a0, a1);
        case 1679: return fde_func_1679_0x0ec840(a0, a1);
        case 1680: return fde_func_1680_0x0ecb30(a0, a1);
        case 1681: return fde_func_1681_0x0ecb80(a0, a1);
        case 1682: return fde_func_1682_0x0ecc0c(a0, a1);
        case 1683: return fde_func_1683_0x0ece6c(a0, a1);
        case 1684: return fde_func_1684_0x0ecfb0(a0, a1);
        case 1685: return fde_func_1685_0x0ed030(a0, a1);
        case 1686: return fde_func_1686_0x0ed3c0(a0, a1);
        case 1687: return fde_func_1687_0x0ed480(a0, a1);
        case 1688: return fde_func_1688_0x0ed620(a0, a1);
        case 1689: return fde_func_1689_0x0ed9e0(a0, a1);
        case 1690: return fde_func_1690_0x0edc34(a0, a1);
        case 1691: return fde_func_1691_0x0edff0(a0, a1);
        case 1692: return fde_func_1692_0x0ee244(a0, a1);
        case 1693: return fde_func_1693_0x0ee2c8(a0, a1);
        case 1694: return fde_func_1694_0x0ee3d8(a0, a1);
        case 1695: return fde_func_1695_0x0ee55c(a0, a1);
        case 1696: return fde_func_1696_0x0ee5e0(a0, a1);
        case 1697: return fde_func_1697_0x0ee6f0(a0, a1);
        case 1698: return fde_func_1698_0x0ee7b8(a0, a1);
        case 1699: return fde_func_1699_0x0eead8(a0, a1);
        case 1700: return fde_func_1700_0x0eef28(a0, a1);
        case 1701: return fde_func_1701_0x0eef7c(a0, a1);
        case 1702: return fde_func_1702_0x0ef2dc(a0, a1);
        case 1703: return fde_func_1703_0x0ef594(a0, a1);
        case 1704: return fde_func_1704_0x0ef614(a0, a1);
        case 1705: return fde_func_1705_0x0ef9a4(a0, a1);
        case 1706: return fde_func_1706_0x0efbb0(a0, a1);
        case 1707: return fde_func_1707_0x0efc2c(a0, a1);
        case 1708: return fde_func_1708_0x0efc98(a0, a1);
        case 1709: return fde_func_1709_0x0efdf4(a0, a1);
        case 1710: return fde_func_1710_0x0efecc(a0, a1);
        case 1711: return fde_func_1711_0x0f0090(a0, a1);
        case 1712: return fde_func_1712_0x0f01c0(a0, a1);
        case 1713: return fde_func_1713_0x0f0588(a0, a1);
        case 1714: return fde_func_1714_0x0f0600(a0, a1);
        case 1715: return fde_func_1715_0x0f0678(a0, a1);
        case 1716: return fde_func_1716_0x0f06ac(a0, a1);
        case 1717: return fde_func_1717_0x0f06f8(a0, a1);
        case 1718: return fde_func_1718_0x0f07c0(a0, a1);
        case 1719: return fde_func_1719_0x0f0b94(a0, a1);
        case 1720: return fde_func_1720_0x0f108c(a0, a1);
        case 1721: return fde_func_1721_0x0f1284(a0, a1);
        case 1722: return fde_func_1722_0x0f1414(a0, a1);
        case 1723: return fde_func_1723_0x0f14d4(a0, a1);
        case 1724: return fde_func_1724_0x0f1518(a0, a1);
        case 1725: return fde_func_1725_0x0f1668(a0, a1);
        case 1726: return fde_func_1726_0x0f16c8(a0, a1);
        case 1727: return fde_func_1727_0x0f1708(a0, a1);
        case 1728: return fde_func_1728_0x0f1754(a0, a1);
        case 1729: return fde_func_1729_0x0f18d0(a0, a1);
        case 1730: return fde_func_1730_0x0f1938(a0, a1);
        case 1731: return fde_func_1731_0x0f1988(a0, a1);
        case 1732: return fde_func_1732_0x0f1bb4(a0, a1);
        case 1733: return fde_func_1733_0x0f1cc0(a0, a1);
        case 1734: return fde_func_1734_0x0f1d84(a0, a1);
        case 1735: return fde_func_1735_0x0f1e0c(a0, a1);
        case 1736: return fde_func_1736_0x0f20a4(a0, a1);
        case 1737: return fde_func_1737_0x0f20e0(a0, a1);
        case 1738: return fde_func_1738_0x0f248c(a0, a1);
        case 1739: return fde_func_1739_0x0f2608(a0, a1);
        case 1740: return fde_func_1740_0x0f2850(a0, a1);
        case 1741: return fde_func_1741_0x0f2cd4(a0, a1);
        case 1742: return fde_func_1742_0x0f2da0(a0, a1);
        case 1743: return fde_func_1743_0x0f3214(a0, a1);
        case 1744: return fde_func_1744_0x0f36a8(a0, a1);
        case 1745: return fde_func_1745_0x0f36e0(a0, a1);
        case 1746: return fde_func_1746_0x0f3c50(a0, a1);
        case 1747: return fde_func_1747_0x0f40ac(a0, a1);
        case 1748: return fde_func_1748_0x0f414c(a0, a1);
        case 1749: return fde_func_1749_0x0f442c(a0, a1);
        case 1750: return fde_func_1750_0x0f47dc(a0, a1);
        case 1751: return fde_func_1751_0x0f4a4c(a0, a1);
        case 1752: return fde_func_1752_0x0f4b6c(a0, a1);
        case 1753: return fde_func_1753_0x0f4bb8(a0, a1);
        case 1754: return fde_func_1754_0x0f4c00(a0, a1);
        case 1755: return fde_func_1755_0x0f4d2c(a0, a1);
        case 1756: return fde_func_1756_0x0f4e38(a0, a1);
        case 1757: return fde_func_1757_0x0f5048(a0, a1);
        case 1758: return fde_func_1758_0x0f5098(a0, a1);
        case 1759: return fde_func_1759_0x0f51d8(a0, a1);
        case 1760: return fde_func_1760_0x0f547c(a0, a1);
        case 1761: return fde_func_1761_0x0f54d0(a0, a1);
        case 1762: return fde_func_1762_0x0f558c(a0, a1);
        case 1763: return fde_func_1763_0x0f55e0(a0, a1);
        case 1764: return fde_func_1764_0x0f5678(a0, a1);
        case 1765: return fde_func_1765_0x106cc0(a0, a1);
        case 1766: return fde_func_1766_0x108498(a0, a1);
        case 1767: return fde_func_1767_0x1084fc(a0, a1);
        case 1768: return fde_func_1768_0x10857c(a0, a1);
        case 1769: return fde_func_1769_0x1085e4(a0, a1);
        case 1770: return fde_func_1770_0x1085f8(a0, a1);
        case 1771: return fde_func_1771_0x115610(a0, a1);
        case 1772: return fde_func_1772_0x115c00(a0, a1);
        case 1773: return fde_func_1773_0x116640(a0, a1);
        case 1774: return fde_func_1774_0x11664c(a0, a1);
        case 1775: return fde_func_1775_0x116660(a0, a1);
        case 1776: return fde_func_1776_0x11666c(a0, a1);
        case 1777: return fde_func_1777_0x116750(a0, a1);
        case 1778: return fde_func_1778_0x1167a0(a0, a1);
        case 1779: return fde_func_1779_0x1168b0(a0, a1);
        case 1780: return fde_func_1780_0x116914(a0, a1);
        case 1781: return fde_func_1781_0x116a24(a0, a1);
        case 1782: return fde_func_1782_0x116a80(a0, a1);
        case 1783: return fde_func_1783_0x116a8c(a0, a1);
        case 1784: return fde_func_1784_0x116a90(a0, a1);
        case 1785: return fde_func_1785_0x116aac(a0, a1);
        case 1786: return fde_func_1786_0x116acc(a0, a1);
        case 1787: return fde_func_1787_0x116aec(a0, a1);
        case 1788: return fde_func_1788_0x116b08(a0, a1);
        case 1789: return fde_func_1789_0x116b2c(a0, a1);
        case 1790: return fde_func_1790_0x116b30(a0, a1);
        case 1791: return fde_func_1791_0x116b34(a0, a1);
        case 1792: return fde_func_1792_0x116b38(a0, a1);
        case 1793: return fde_func_1793_0x116bb0(a0, a1);
        case 1794: return fde_func_1794_0x118a1c(a0, a1);
        case 1795: return fde_func_1795_0x118a84(a0, a1);
        case 1796: return fde_func_1796_0x118ae8(a0, a1);
        case 1797: return fde_func_1797_0x118b44(a0, a1);
        case 1798: return fde_func_1798_0x118b68(a0, a1);
        case 1799: return fde_func_1799_0x118ce4(a0, a1);
        case 1800: return fde_func_1800_0x118e3c(a0, a1);
        case 1801: return fde_func_1801_0x118f0c(a0, a1);
        case 1802: return fde_func_1802_0x11900c(a0, a1);
        case 1803: return fde_func_1803_0x119048(a0, a1);
        case 1804: return fde_func_1804_0x1190c8(a0, a1);
        case 1805: return fde_func_1805_0x1191d0(a0, a1);
        case 1806: return fde_func_1806_0x1192dc(a0, a1);
        case 1807: return fde_func_1807_0x119364(a0, a1);
        case 1808: return fde_func_1808_0x1193d0(a0, a1);
        case 1809: return fde_func_1809_0x119414(a0, a1);
        case 1810: return fde_func_1810_0x11941c(a0, a1);
        case 1811: return fde_func_1811_0x1194fc(a0, a1);
        case 1812: return fde_func_1812_0x119738(a0, a1);
        case 1813: return fde_func_1813_0x119784(a0, a1);
        case 1814: return fde_func_1814_0x1197b8(a0, a1);
        case 1815: return fde_func_1815_0x11997c(a0, a1);
        case 1816: return fde_func_1816_0x119a54(a0, a1);
        case 1817: return fde_func_1817_0x119b4c(a0, a1);
        case 1818: return fde_func_1818_0x119b70(a0, a1);
        case 1819: return fde_func_1819_0x119b7c(a0, a1);
        case 1820: return fde_func_1820_0x119cac(a0, a1);
        case 1821: return fde_func_1821_0x119df0(a0, a1);
        case 1822: return fde_func_1822_0x119ed8(a0, a1);
        case 1823: return fde_func_1823_0x11a018(a0, a1);
        case 1824: return fde_func_1824_0x11a170(a0, a1);
        case 1825: return fde_func_1825_0x11a3d4(a0, a1);
        case 1826: return fde_func_1826_0x11a4c8(a0, a1);
        case 1827: return fde_func_1827_0x11a618(a0, a1);
        case 1828: return fde_func_1828_0x11a780(a0, a1);
        case 1829: return fde_func_1829_0x11a8d8(a0, a1);
        case 1830: return fde_func_1830_0x11a96c(a0, a1);
        case 1831: return fde_func_1831_0x11a9a4(a0, a1);
        case 1832: return fde_func_1832_0x11aa50(a0, a1);
        case 1833: return fde_func_1833_0x11aacc(a0, a1);
        case 1834: return fde_func_1834_0x11ac30(a0, a1);
        case 1835: return fde_func_1835_0x11ad84(a0, a1);
        case 1836: return fde_func_1836_0x11adc8(a0, a1);
        case 1837: return fde_func_1837_0x11ae18(a0, a1);
        case 1838: return fde_func_1838_0x11ae1c(a0, a1);
        case 1839: return fde_func_1839_0x11afe4(a0, a1);
        case 1840: return fde_func_1840_0x11b1bc(a0, a1);
        case 1841: return fde_func_1841_0x11b2d0(a0, a1);
        case 1842: return fde_func_1842_0x11b3ec(a0, a1);
        case 1843: return fde_func_1843_0x11b504(a0, a1);
        case 1844: return fde_func_1844_0x11b5d8(a0, a1);
        case 1845: return fde_func_1845_0x11b5ec(a0, a1);
        case 1846: return fde_func_1846_0x11b604(a0, a1);
        case 1847: return fde_func_1847_0x11b6ec(a0, a1);
        case 1848: return fde_func_1848_0x11b7e0(a0, a1);
        case 1849: return fde_func_1849_0x11b87c(a0, a1);
        case 1850: return fde_func_1850_0x11b890(a0, a1);
        case 1851: return fde_func_1851_0x11b898(a0, a1);
        case 1852: return fde_func_1852_0x11b8a0(a0, a1);
        case 1853: return fde_func_1853_0x11b8a8(a0, a1);
        case 1854: return fde_func_1854_0x11b8b0(a0, a1);
        case 1855: return fde_func_1855_0x11b8b8(a0, a1);
        case 1856: return fde_func_1856_0x11b8c0(a0, a1);
        case 1857: return fde_func_1857_0x11e258(a0, a1);
        case 1858: return fde_func_1858_0x11e2e8(a0, a1);
        case 1859: return fde_func_1859_0x11e9e8(a0, a1);
        case 1860: return fde_func_1860_0x11ec14(a0, a1);
        case 1861: return fde_func_1861_0x11f21c(a0, a1);
        case 1862: return fde_func_1862_0x11f42c(a0, a1);
        case 1863: return fde_func_1863_0x11f448(a0, a1);
        case 1864: return fde_func_1864_0x11f460(a0, a1);
        case 1865: return fde_func_1865_0x11f8cc(a0, a1);
        case 1866: return fde_func_1866_0x11fafc(a0, a1);
        case 1867: return fde_func_1867_0x131b3c(a0, a1);
        case 1868: return fde_func_1868_0x131b9c(a0, a1);
        case 1869: return fde_func_1869_0x131bd4(a0, a1);
        case 1870: return fde_func_1870_0x131bdc(a0, a1);
        case 1871: return fde_func_1871_0x131c50(a0, a1);
        case 1872: return fde_func_1872_0x131d38(a0, a1);
        case 1873: return fde_func_1873_0x131d50(a0, a1);
        case 1874: return fde_func_1874_0x131e94(a0, a1);
        case 1875: return fde_func_1875_0x131ef4(a0, a1);
        case 1876: return fde_func_1876_0x131efc(a0, a1);
        case 1877: return fde_func_1877_0x131fa0(a0, a1);
        case 1878: return fde_func_1878_0x131fe8(a0, a1);
        case 1879: return fde_func_1879_0x131ff0(a0, a1);
        case 1880: return fde_func_1880_0x131ff8(a0, a1);
        case 1881: return fde_func_1881_0x13201c(a0, a1);
        case 1882: return fde_func_1882_0x132020(a0, a1);
        case 1883: return fde_func_1883_0x132024(a0, a1);
        case 1884: return fde_func_1884_0x132038(a0, a1);
        case 1885: return fde_func_1885_0x13204c(a0, a1);
        case 1886: return fde_func_1886_0x132064(a0, a1);
        case 1887: return fde_func_1887_0x132080(a0, a1);
        case 1888: return fde_func_1888_0x132094(a0, a1);
        case 1889: return fde_func_1889_0x1320a4(a0, a1);
        case 1890: return fde_func_1890_0x1321e0(a0, a1);
        case 1891: return fde_func_1891_0x1328c0(a0, a1);
        case 1892: return fde_func_1892_0x1333d4(a0, a1);
        case 1893: return fde_func_1893_0x133460(a0, a1);
        case 1894: return fde_func_1894_0x1334a0(a0, a1);
        case 1895: return fde_func_1895_0x133520(a0, a1);
        case 1896: return fde_func_1896_0x1335b8(a0, a1);
        case 1897: return fde_func_1897_0x1335d8(a0, a1);
        case 1898: return fde_func_1898_0x133730(a0, a1);
        case 1899: return fde_func_1899_0x13376c(a0, a1);
        default: return 0ULL;
    }
}

} // namespace ttmio
} // namespace ss
} // namespace com