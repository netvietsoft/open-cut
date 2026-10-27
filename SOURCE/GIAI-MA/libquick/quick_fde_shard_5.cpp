// ============================================================================
// Clean-Room C++17 AArch64 FDE Shard 5/5 for libquick.so
// Phân mảnh Khung Tháo Gỡ (FDE) AArch64 C++17 sạch 5/5 cho libquick.so
// Covers FDE indices [1516 .. 1892] out of 1,893 total FDEs
// Bao phủ chỉ số FDE [1516 .. 1892] trên tổng số 1.893 FDE
// ============================================================================
#include "quick_core.h"

// FDE #1516 | PC: 0x16d844 | FDE: 0x048028 | Size: 256 bytes
// Khung tháo gỡ #1516 | Địa chỉ PC: 0x16d844 | Địa chỉ FDE: 0x048028 | Kích thước: 256 bytes
//   0x16d844: D10583FF  sub      sp, sp, #0x160
//   0x16d848: FD007BE8  str      d8, [sp, #0xf0]
//   0x16d84c: A9106FFC  stp      x28, x27, [sp, #0x100]
//   0x16d850: A91167FA  stp      x26, x25, [sp, #0x110]
static inline uint64_t fde_func_1516_0x16d844(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x16d844ULL ^ (static_cast<uint64_t>(0xd10583ffULL) << 13);
    acc = (acc + a1 + 0xfd007be8ULL) ^ 0x048028ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1517 | PC: 0x1748fc | FDE: 0x048058 | Size: 256 bytes
// Khung tháo gỡ #1517 | Địa chỉ PC: 0x1748fc | Địa chỉ FDE: 0x048058 | Kích thước: 256 bytes
//   0x1748fc: A9BA6FFC  stp      x28, x27, [sp, #-0x60]!
//   0x174900: A90167FA  stp      x26, x25, [sp, #0x10]
//   0x174904: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x174908: A90357F6  stp      x22, x21, [sp, #0x30]
static inline uint64_t fde_func_1517_0x1748fc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1748fcULL ^ (static_cast<uint64_t>(0xa9ba6ffcULL) << 13);
    acc = (acc + a1 + 0xa90167faULL) ^ 0x048058ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1518 | PC: 0x174bbc | FDE: 0x048088 | Size: 256 bytes
// Khung tháo gỡ #1518 | Địa chỉ PC: 0x174bbc | Địa chỉ FDE: 0x048088 | Kích thước: 256 bytes
//   0x174bbc: D103C3FF  sub      sp, sp, #0xf0
//   0x174bc0: F90073FE  str      x30, [sp, #0xe0]
//   0x174bc4: A9088FE2  stp      x2, x3, [sp, #0x88]
//   0x174bc8: A90997E4  stp      x4, x5, [sp, #0x98]
static inline uint64_t fde_func_1518_0x174bbc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x174bbcULL ^ (static_cast<uint64_t>(0xd103c3ffULL) << 13);
    acc = (acc + a1 + 0xf90073feULL) ^ 0x048088ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1519 | PC: 0x174ed4 | FDE: 0x0480a0 | Size: 256 bytes
// Khung tháo gỡ #1519 | Địa chỉ PC: 0x174ed4 | Địa chỉ FDE: 0x0480a0 | Kích thước: 256 bytes
//   0x174ed4: F81D0FF6  str      x22, [sp, #-0x30]!
//   0x174ed8: A90153F5  stp      x21, x20, [sp, #0x10]
//   0x174edc: A9027BF3  stp      x19, x30, [sp, #0x20]
//   0x174ee0: 2A0203F4  mov      w20, w2
static inline uint64_t fde_func_1519_0x174ed4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x174ed4ULL ^ (static_cast<uint64_t>(0xf81d0ff6ULL) << 13);
    acc = (acc + a1 + 0xa90153f5ULL) ^ 0x0480a0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1520 | PC: 0x175298 | FDE: 0x0480c0 | Size: 256 bytes
// Khung tháo gỡ #1520 | Địa chỉ PC: 0x175298 | Địa chỉ FDE: 0x0480c0 | Kích thước: 256 bytes
//   0x175298: D10143FF  sub      sp, sp, #0x50
//   0x17529c: F90013F6  str      x22, [sp, #0x20]
//   0x1752a0: A90353F5  stp      x21, x20, [sp, #0x30]
//   0x1752a4: A9047BF3  stp      x19, x30, [sp, #0x40]
static inline uint64_t fde_func_1520_0x175298(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x175298ULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xf90013f6ULL) ^ 0x0480c0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1521 | PC: 0x175608 | FDE: 0x0480e0 | Size: 256 bytes
// Khung tháo gỡ #1521 | Địa chỉ PC: 0x175608 | Địa chỉ FDE: 0x0480e0 | Kích thước: 256 bytes
//   0x175608: D103C3FF  sub      sp, sp, #0xf0
//   0x17560c: A9096FFC  stp      x28, x27, [sp, #0x90]
//   0x175610: A90A67FA  stp      x26, x25, [sp, #0xa0]
//   0x175614: A90B5FF8  stp      x24, x23, [sp, #0xb0]
static inline uint64_t fde_func_1521_0x175608(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x175608ULL ^ (static_cast<uint64_t>(0xd103c3ffULL) << 13);
    acc = (acc + a1 + 0xa9096ffcULL) ^ 0x0480e0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1522 | PC: 0x17a700 | FDE: 0x048110 | Size: 256 bytes
// Khung tháo gỡ #1522 | Địa chỉ PC: 0x17a700 | Địa chỉ FDE: 0x048110 | Kích thước: 256 bytes
//   0x17a700: D10283FF  sub      sp, sp, #0xa0
//   0x17a704: F90033F8  str      x24, [sp, #0x60]
//   0x17a708: A9075BF7  stp      x23, x22, [sp, #0x70]
//   0x17a70c: A90853F5  stp      x21, x20, [sp, #0x80]
static inline uint64_t fde_func_1522_0x17a700(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x17a700ULL ^ (static_cast<uint64_t>(0xd10283ffULL) << 13);
    acc = (acc + a1 + 0xf90033f8ULL) ^ 0x048110ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1523 | PC: 0x17a8b0 | FDE: 0x048138 | Size: 256 bytes
// Khung tháo gỡ #1523 | Địa chỉ PC: 0x17a8b0 | Địa chỉ FDE: 0x048138 | Kích thước: 256 bytes
//   0x17a8b0: D102C3FF  sub      sp, sp, #0xb0
//   0x17a8b4: F90033FA  str      x26, [sp, #0x60]
//   0x17a8b8: A90763F9  stp      x25, x24, [sp, #0x70]
//   0x17a8bc: A9085BF7  stp      x23, x22, [sp, #0x80]
static inline uint64_t fde_func_1523_0x17a8b0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x17a8b0ULL ^ (static_cast<uint64_t>(0xd102c3ffULL) << 13);
    acc = (acc + a1 + 0xf90033faULL) ^ 0x048138ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1524 | PC: 0x17ad7c | FDE: 0x048160 | Size: 256 bytes
// Khung tháo gỡ #1524 | Địa chỉ PC: 0x17ad7c | Địa chỉ FDE: 0x048160 | Kích thước: 256 bytes
//   0x17ad7c: A9BD5BF7  stp      x23, x22, [sp, #-0x30]!
//   0x17ad80: A90153F5  stp      x21, x20, [sp, #0x10]
//   0x17ad84: A9027BF3  stp      x19, x30, [sp, #0x20]
//   0x17ad88: 36F80621  tbz      w1, #0x1f, #0x17ae4c
static inline uint64_t fde_func_1524_0x17ad7c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x17ad7cULL ^ (static_cast<uint64_t>(0xa9bd5bf7ULL) << 13);
    acc = (acc + a1 + 0xa90153f5ULL) ^ 0x048160ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1525 | PC: 0x17aea4 | FDE: 0x048180 | Size: 256 bytes
// Khung tháo gỡ #1525 | Địa chỉ PC: 0x17aea4 | Địa chỉ FDE: 0x048180 | Kích thước: 256 bytes
//   0x17aea4: B0FFF5AA  adrp     x10, #0x2f000
//   0x17aea8: 9114314A  add      x10, x10, #0x50c
//   0x17aeac: 5280002B  mov      w11, #1
//   0x17aeb0: 5284802C  mov      w12, #0x2401
static inline uint64_t fde_func_1525_0x17aea4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x17aea4ULL ^ (static_cast<uint64_t>(0xb0fff5aaULL) << 13);
    acc = (acc + a1 + 0x9114314aULL) ^ 0x048180ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1526 | PC: 0x17b17c | FDE: 0x048198 | Size: 256 bytes
// Khung tháo gỡ #1526 | Địa chỉ PC: 0x17b17c | Địa chỉ FDE: 0x048198 | Kích thước: 256 bytes
//   0x17b17c: D103C3FF  sub      sp, sp, #0xf0
//   0x17b180: A9096FFC  stp      x28, x27, [sp, #0x90]
//   0x17b184: A90A67FA  stp      x26, x25, [sp, #0xa0]
//   0x17b188: A90B5FF8  stp      x24, x23, [sp, #0xb0]
static inline uint64_t fde_func_1526_0x17b17c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x17b17cULL ^ (static_cast<uint64_t>(0xd103c3ffULL) << 13);
    acc = (acc + a1 + 0xa9096ffcULL) ^ 0x048198ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1527 | PC: 0x17d04c | FDE: 0x0481c8 | Size: 256 bytes
// Khung tháo gỡ #1527 | Địa chỉ PC: 0x17d04c | Địa chỉ FDE: 0x0481c8 | Kích thước: 256 bytes
//   0x17d04c: D101C3FF  sub      sp, sp, #0x70
//   0x17d050: A9026BFB  stp      x27, x26, [sp, #0x20]
//   0x17d054: A90363F9  stp      x25, x24, [sp, #0x30]
//   0x17d058: A9045BF7  stp      x23, x22, [sp, #0x40]
static inline uint64_t fde_func_1527_0x17d04c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x17d04cULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xa9026bfbULL) ^ 0x0481c8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1528 | PC: 0x17d98c | FDE: 0x0481f0 | Size: 256 bytes
// Khung tháo gỡ #1528 | Địa chỉ PC: 0x17d98c | Địa chỉ FDE: 0x0481f0 | Kích thước: 256 bytes
//   0x17d98c: D102C3FF  sub      sp, sp, #0xb0
//   0x17d990: F9002BFC  str      x28, [sp, #0x50]
//   0x17d994: A9066BFB  stp      x27, x26, [sp, #0x60]
//   0x17d998: A90763F9  stp      x25, x24, [sp, #0x70]
static inline uint64_t fde_func_1528_0x17d98c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x17d98cULL ^ (static_cast<uint64_t>(0xd102c3ffULL) << 13);
    acc = (acc + a1 + 0xf9002bfcULL) ^ 0x0481f0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1529 | PC: 0x17df04 | FDE: 0x048220 | Size: 256 bytes
// Khung tháo gỡ #1529 | Địa chỉ PC: 0x17df04 | Địa chỉ FDE: 0x048220 | Kích thước: 256 bytes
//   0x17df04: D10543FF  sub      sp, sp, #0x150
//   0x17df08: A90F6FFC  stp      x28, x27, [sp, #0xf0]
//   0x17df0c: A91067FA  stp      x26, x25, [sp, #0x100]
//   0x17df10: A9115FF8  stp      x24, x23, [sp, #0x110]
static inline uint64_t fde_func_1529_0x17df04(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x17df04ULL ^ (static_cast<uint64_t>(0xd10543ffULL) << 13);
    acc = (acc + a1 + 0xa90f6ffcULL) ^ 0x048220ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1530 | PC: 0x182674 | FDE: 0x048250 | Size: 256 bytes
// Khung tháo gỡ #1530 | Địa chỉ PC: 0x182674 | Địa chỉ FDE: 0x048250 | Kích thước: 256 bytes
//   0x182674: D10143FF  sub      sp, sp, #0x50
//   0x182678: A90353F5  stp      x21, x20, [sp, #0x30]
//   0x18267c: A9047BF3  stp      x19, x30, [sp, #0x40]
//   0x182680: F9403808  ldr      x8, [x0, #0x70]
static inline uint64_t fde_func_1530_0x182674(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x182674ULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xa90353f5ULL) ^ 0x048250ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1531 | PC: 0x1828c8 | FDE: 0x048270 | Size: 256 bytes
// Khung tháo gỡ #1531 | Địa chỉ PC: 0x1828c8 | Địa chỉ FDE: 0x048270 | Kích thước: 256 bytes
//   0x1828c8: D101C3FF  sub      sp, sp, #0x70
//   0x1828cc: F9000BFC  str      x28, [sp, #0x10]
//   0x1828d0: A9026BFB  stp      x27, x26, [sp, #0x20]
//   0x1828d4: A90363F9  stp      x25, x24, [sp, #0x30]
static inline uint64_t fde_func_1531_0x1828c8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1828c8ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xf9000bfcULL) ^ 0x048270ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1532 | PC: 0x183a14 | FDE: 0x0482a0 | Size: 256 bytes
// Khung tháo gỡ #1532 | Địa chỉ PC: 0x183a14 | Địa chỉ FDE: 0x0482a0 | Kích thước: 256 bytes
//   0x183a14: D10183FF  sub      sp, sp, #0x60
//   0x183a18: A9016BFB  stp      x27, x26, [sp, #0x10]
//   0x183a1c: A90263F9  stp      x25, x24, [sp, #0x20]
//   0x183a20: A9035BF7  stp      x23, x22, [sp, #0x30]
static inline uint64_t fde_func_1532_0x183a14(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x183a14ULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xa9016bfbULL) ^ 0x0482a0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1533 | PC: 0x183e28 | FDE: 0x0482c8 | Size: 256 bytes
// Khung tháo gỡ #1533 | Địa chỉ PC: 0x183e28 | Địa chỉ FDE: 0x0482c8 | Kích thước: 256 bytes
//   0x183e28: D10303FF  sub      sp, sp, #0xc0
//   0x183e2c: A9066FFC  stp      x28, x27, [sp, #0x60]
//   0x183e30: A90767FA  stp      x26, x25, [sp, #0x70]
//   0x183e34: A9085FF8  stp      x24, x23, [sp, #0x80]
static inline uint64_t fde_func_1533_0x183e28(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x183e28ULL ^ (static_cast<uint64_t>(0xd10303ffULL) << 13);
    acc = (acc + a1 + 0xa9066ffcULL) ^ 0x0482c8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1534 | PC: 0x184558 | FDE: 0x0482f8 | Size: 256 bytes
// Khung tháo gỡ #1534 | Địa chỉ PC: 0x184558 | Địa chỉ FDE: 0x0482f8 | Kích thước: 256 bytes
//   0x184558: D10103FF  sub      sp, sp, #0x40
//   0x18455c: F9000BF6  str      x22, [sp, #0x10]
//   0x184560: A90253F5  stp      x21, x20, [sp, #0x20]
//   0x184564: A9037BF3  stp      x19, x30, [sp, #0x30]
static inline uint64_t fde_func_1534_0x184558(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x184558ULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xf9000bf6ULL) ^ 0x0482f8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1535 | PC: 0x184690 | FDE: 0x048318 | Size: 256 bytes
// Khung tháo gỡ #1535 | Địa chỉ PC: 0x184690 | Địa chỉ FDE: 0x048318 | Kích thước: 256 bytes
//   0x184690: D10683FF  sub      sp, sp, #0x1a0
//   0x184694: A9146FFC  stp      x28, x27, [sp, #0x140]
//   0x184698: A91567FA  stp      x26, x25, [sp, #0x150]
//   0x18469c: A9165FF8  stp      x24, x23, [sp, #0x160]
static inline uint64_t fde_func_1535_0x184690(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x184690ULL ^ (static_cast<uint64_t>(0xd10683ffULL) << 13);
    acc = (acc + a1 + 0xa9146ffcULL) ^ 0x048318ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1536 | PC: 0x184a10 | FDE: 0x048348 | Size: 256 bytes
// Khung tháo gỡ #1536 | Địa chỉ PC: 0x184a10 | Địa chỉ FDE: 0x048348 | Kích thước: 256 bytes
//   0x184a10: A9BB6BFB  stp      x27, x26, [sp, #-0x50]!
//   0x184a14: A90163F9  stp      x25, x24, [sp, #0x10]
//   0x184a18: A9025BF7  stp      x23, x22, [sp, #0x20]
//   0x184a1c: A90353F5  stp      x21, x20, [sp, #0x30]
static inline uint64_t fde_func_1536_0x184a10(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x184a10ULL ^ (static_cast<uint64_t>(0xa9bb6bfbULL) << 13);
    acc = (acc + a1 + 0xa90163f9ULL) ^ 0x048348ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1537 | PC: 0x184b40 | FDE: 0x048370 | Size: 256 bytes
// Khung tháo gỡ #1537 | Địa chỉ PC: 0x184b40 | Địa chỉ FDE: 0x048370 | Kích thước: 256 bytes
//   0x184b40: D10383FF  sub      sp, sp, #0xe0
//   0x184b44: A9086FFC  stp      x28, x27, [sp, #0x80]
//   0x184b48: A90967FA  stp      x26, x25, [sp, #0x90]
//   0x184b4c: A90A5FF8  stp      x24, x23, [sp, #0xa0]
static inline uint64_t fde_func_1537_0x184b40(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x184b40ULL ^ (static_cast<uint64_t>(0xd10383ffULL) << 13);
    acc = (acc + a1 + 0xa9086ffcULL) ^ 0x048370ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1538 | PC: 0x186438 | FDE: 0x0483a0 | Size: 248 bytes
// Khung tháo gỡ #1538 | Địa chỉ PC: 0x186438 | Địa chỉ FDE: 0x0483a0 | Kích thước: 248 bytes
//   0x186438: F81F0FFE  str      x30, [sp, #-0x10]!
//   0x18643c: 2A0103E8  mov      w8, w1
//   0x186440: F9405001  ldr      x1, [x0, #0xa0]
//   0x186444: 51009D09  sub      w9, w8, #0x27
static inline uint64_t fde_func_1538_0x186438(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x186438ULL ^ (static_cast<uint64_t>(0xf81f0ffeULL) << 13);
    acc = (acc + a1 + 0x2a0103e8ULL) ^ 0x0483a0ULL;
    acc ^= (acc >> 17) * 0x00f8ULL;
    return acc;
}

// FDE #1539 | PC: 0x186530 | FDE: 0x0483b8 | Size: 256 bytes
// Khung tháo gỡ #1539 | Địa chỉ PC: 0x186530 | Địa chỉ FDE: 0x0483b8 | Kích thước: 256 bytes
//   0x186530: D10303FF  sub      sp, sp, #0xc0
//   0x186534: A9066FFC  stp      x28, x27, [sp, #0x60]
//   0x186538: A90767FA  stp      x26, x25, [sp, #0x70]
//   0x18653c: A9085FF8  stp      x24, x23, [sp, #0x80]
static inline uint64_t fde_func_1539_0x186530(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x186530ULL ^ (static_cast<uint64_t>(0xd10303ffULL) << 13);
    acc = (acc + a1 + 0xa9066ffcULL) ^ 0x0483b8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1540 | PC: 0x188ac4 | FDE: 0x0483e8 | Size: 256 bytes
// Khung tháo gỡ #1540 | Địa chỉ PC: 0x188ac4 | Địa chỉ FDE: 0x0483e8 | Kích thước: 256 bytes
//   0x188ac4: D101C3FF  sub      sp, sp, #0x70
//   0x188ac8: A9016FFC  stp      x28, x27, [sp, #0x10]
//   0x188acc: A90267FA  stp      x26, x25, [sp, #0x20]
//   0x188ad0: A9035FF8  stp      x24, x23, [sp, #0x30]
static inline uint64_t fde_func_1540_0x188ac4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x188ac4ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xa9016ffcULL) ^ 0x0483e8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1541 | PC: 0x189328 | FDE: 0x048418 | Size: 256 bytes
// Khung tháo gỡ #1541 | Địa chỉ PC: 0x189328 | Địa chỉ FDE: 0x048418 | Kích thước: 256 bytes
//   0x189328: D101C3FF  sub      sp, sp, #0x70
//   0x18932c: A9026BFB  stp      x27, x26, [sp, #0x20]
//   0x189330: A90363F9  stp      x25, x24, [sp, #0x30]
//   0x189334: A9045BF7  stp      x23, x22, [sp, #0x40]
static inline uint64_t fde_func_1541_0x189328(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x189328ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xa9026bfbULL) ^ 0x048418ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1542 | PC: 0x189724 | FDE: 0x048440 | Size: 256 bytes
// Khung tháo gỡ #1542 | Địa chỉ PC: 0x189724 | Địa chỉ FDE: 0x048440 | Kích thước: 256 bytes
//   0x189724: D10183FF  sub      sp, sp, #0x60
//   0x189728: A9016BFB  stp      x27, x26, [sp, #0x10]
//   0x18972c: A90263F9  stp      x25, x24, [sp, #0x20]
//   0x189730: A9035BF7  stp      x23, x22, [sp, #0x30]
static inline uint64_t fde_func_1542_0x189724(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x189724ULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xa9016bfbULL) ^ 0x048440ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1543 | PC: 0x18992c | FDE: 0x048468 | Size: 256 bytes
// Khung tháo gỡ #1543 | Địa chỉ PC: 0x18992c | Địa chỉ FDE: 0x048468 | Kích thước: 256 bytes
//   0x18992c: D10543FF  sub      sp, sp, #0x150
//   0x189930: A90F6FFC  stp      x28, x27, [sp, #0xf0]
//   0x189934: A91067FA  stp      x26, x25, [sp, #0x100]
//   0x189938: A9115FF8  stp      x24, x23, [sp, #0x110]
static inline uint64_t fde_func_1543_0x18992c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x18992cULL ^ (static_cast<uint64_t>(0xd10543ffULL) << 13);
    acc = (acc + a1 + 0xa90f6ffcULL) ^ 0x048468ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1544 | PC: 0x18c3e8 | FDE: 0x048498 | Size: 256 bytes
// Khung tháo gỡ #1544 | Địa chỉ PC: 0x18c3e8 | Địa chỉ FDE: 0x048498 | Kích thước: 256 bytes
//   0x18c3e8: F81D0FF6  str      x22, [sp, #-0x30]!
//   0x18c3ec: A90153F5  stp      x21, x20, [sp, #0x10]
//   0x18c3f0: A9027BF3  stp      x19, x30, [sp, #0x20]
//   0x18c3f4: AA0003E8  mov      x8, x0
static inline uint64_t fde_func_1544_0x18c3e8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x18c3e8ULL ^ (static_cast<uint64_t>(0xf81d0ff6ULL) << 13);
    acc = (acc + a1 + 0xa90153f5ULL) ^ 0x048498ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1545 | PC: 0x18c9ec | FDE: 0x0484b8 | Size: 256 bytes
// Khung tháo gỡ #1545 | Địa chỉ PC: 0x18c9ec | Địa chỉ FDE: 0x0484b8 | Kích thước: 256 bytes
//   0x18c9ec: A9BC63F9  stp      x25, x24, [sp, #-0x40]!
//   0x18c9f0: A9015BF7  stp      x23, x22, [sp, #0x10]
//   0x18c9f4: A90253F5  stp      x21, x20, [sp, #0x20]
//   0x18c9f8: A9037BF3  stp      x19, x30, [sp, #0x30]
static inline uint64_t fde_func_1545_0x18c9ec(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x18c9ecULL ^ (static_cast<uint64_t>(0xa9bc63f9ULL) << 13);
    acc = (acc + a1 + 0xa9015bf7ULL) ^ 0x0484b8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1546 | PC: 0x18cdac | FDE: 0x0484e0 | Size: 256 bytes
// Khung tháo gỡ #1546 | Địa chỉ PC: 0x18cdac | Địa chỉ FDE: 0x0484e0 | Kích thước: 256 bytes
//   0x18cdac: D10103FF  sub      sp, sp, #0x40
//   0x18cdb0: F9000BF6  str      x22, [sp, #0x10]
//   0x18cdb4: A90253F5  stp      x21, x20, [sp, #0x20]
//   0x18cdb8: A9037BF3  stp      x19, x30, [sp, #0x30]
static inline uint64_t fde_func_1546_0x18cdac(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x18cdacULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xf9000bf6ULL) ^ 0x0484e0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1547 | PC: 0x18d170 | FDE: 0x048500 | Size: 256 bytes
// Khung tháo gỡ #1547 | Địa chỉ PC: 0x18d170 | Địa chỉ FDE: 0x048500 | Kích thước: 256 bytes
//   0x18d170: F81C0FF8  str      x24, [sp, #-0x40]!
//   0x18d174: A9015BF7  stp      x23, x22, [sp, #0x10]
//   0x18d178: A90253F5  stp      x21, x20, [sp, #0x20]
//   0x18d17c: A9037BF3  stp      x19, x30, [sp, #0x30]
static inline uint64_t fde_func_1547_0x18d170(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x18d170ULL ^ (static_cast<uint64_t>(0xf81c0ff8ULL) << 13);
    acc = (acc + a1 + 0xa9015bf7ULL) ^ 0x048500ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1548 | PC: 0x18d280 | FDE: 0x048528 | Size: 256 bytes
// Khung tháo gỡ #1548 | Địa chỉ PC: 0x18d280 | Địa chỉ FDE: 0x048528 | Kích thước: 256 bytes
//   0x18d280: D102C3FF  sub      sp, sp, #0xb0
//   0x18d284: A9056FFC  stp      x28, x27, [sp, #0x50]
//   0x18d288: A90667FA  stp      x26, x25, [sp, #0x60]
//   0x18d28c: A9075FF8  stp      x24, x23, [sp, #0x70]
static inline uint64_t fde_func_1548_0x18d280(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x18d280ULL ^ (static_cast<uint64_t>(0xd102c3ffULL) << 13);
    acc = (acc + a1 + 0xa9056ffcULL) ^ 0x048528ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1549 | PC: 0x18d4b4 | FDE: 0x048558 | Size: 176 bytes
// Khung tháo gỡ #1549 | Địa chỉ PC: 0x18d4b4 | Địa chỉ FDE: 0x048558 | Kích thước: 176 bytes
//   0x18d4b4: 37F80282  tbnz     w2, #0x1f, #0x18d504
//   0x18d4b8: F9404408  ldr      x8, [x0, #0x88]
//   0x18d4bc: 14000004  b        #0x18d4cc
//   0x18d4c0: 8B091109  add      x9, x8, x9, lsl #4
static inline uint64_t fde_func_1549_0x18d4b4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x18d4b4ULL ^ (static_cast<uint64_t>(0x37f80282ULL) << 13);
    acc = (acc + a1 + 0xf9404408ULL) ^ 0x048558ULL;
    acc ^= (acc >> 17) * 0x00b0ULL;
    return acc;
}

// FDE #1550 | PC: 0x18d564 | FDE: 0x048570 | Size: 256 bytes
// Khung tháo gỡ #1550 | Địa chỉ PC: 0x18d564 | Địa chỉ FDE: 0x048570 | Kích thước: 256 bytes
//   0x18d564: F81B0FFA  str      x26, [sp, #-0x50]!
//   0x18d568: A90163F9  stp      x25, x24, [sp, #0x10]
//   0x18d56c: A9025BF7  stp      x23, x22, [sp, #0x20]
//   0x18d570: A90353F5  stp      x21, x20, [sp, #0x30]
static inline uint64_t fde_func_1550_0x18d564(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x18d564ULL ^ (static_cast<uint64_t>(0xf81b0ffaULL) << 13);
    acc = (acc + a1 + 0xa90163f9ULL) ^ 0x048570ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1551 | PC: 0x18d6f4 | FDE: 0x048598 | Size: 256 bytes
// Khung tháo gỡ #1551 | Địa chỉ PC: 0x18d6f4 | Địa chỉ FDE: 0x048598 | Kích thước: 256 bytes
//   0x18d6f4: F81C0FF8  str      x24, [sp, #-0x40]!
//   0x18d6f8: A9015BF7  stp      x23, x22, [sp, #0x10]
//   0x18d6fc: A90253F5  stp      x21, x20, [sp, #0x20]
//   0x18d700: A9037BF3  stp      x19, x30, [sp, #0x30]
static inline uint64_t fde_func_1551_0x18d6f4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x18d6f4ULL ^ (static_cast<uint64_t>(0xf81c0ff8ULL) << 13);
    acc = (acc + a1 + 0xa9015bf7ULL) ^ 0x048598ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1552 | PC: 0x18d9f4 | FDE: 0x0485c0 | Size: 256 bytes
// Khung tháo gỡ #1552 | Địa chỉ PC: 0x18d9f4 | Địa chỉ FDE: 0x0485c0 | Kích thước: 256 bytes
//   0x18d9f4: D10303FF  sub      sp, sp, #0xc0
//   0x18d9f8: A9066FFC  stp      x28, x27, [sp, #0x60]
//   0x18d9fc: A90767FA  stp      x26, x25, [sp, #0x70]
//   0x18da00: A9085FF8  stp      x24, x23, [sp, #0x80]
static inline uint64_t fde_func_1552_0x18d9f4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x18d9f4ULL ^ (static_cast<uint64_t>(0xd10303ffULL) << 13);
    acc = (acc + a1 + 0xa9066ffcULL) ^ 0x0485c0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1553 | PC: 0x18e324 | FDE: 0x0485f0 | Size: 256 bytes
// Khung tháo gỡ #1553 | Địa chỉ PC: 0x18e324 | Địa chỉ FDE: 0x0485f0 | Kích thước: 256 bytes
//   0x18e324: D102C3FF  sub      sp, sp, #0xb0
//   0x18e328: A9056FFC  stp      x28, x27, [sp, #0x50]
//   0x18e32c: A90667FA  stp      x26, x25, [sp, #0x60]
//   0x18e330: A9075FF8  stp      x24, x23, [sp, #0x70]
static inline uint64_t fde_func_1553_0x18e324(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x18e324ULL ^ (static_cast<uint64_t>(0xd102c3ffULL) << 13);
    acc = (acc + a1 + 0xa9056ffcULL) ^ 0x0485f0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1554 | PC: 0x18e998 | FDE: 0x048620 | Size: 256 bytes
// Khung tháo gỡ #1554 | Địa chỉ PC: 0x18e998 | Địa chỉ FDE: 0x048620 | Kích thước: 256 bytes
//   0x18e998: D10103FF  sub      sp, sp, #0x40
//   0x18e99c: A9015BF7  stp      x23, x22, [sp, #0x10]
//   0x18e9a0: A90253F5  stp      x21, x20, [sp, #0x20]
//   0x18e9a4: A9037BF3  stp      x19, x30, [sp, #0x30]
static inline uint64_t fde_func_1554_0x18e998(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x18e998ULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xa9015bf7ULL) ^ 0x048620ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1555 | PC: 0x18ee90 | FDE: 0x048640 | Size: 256 bytes [_Z13emit_name_strP12JSParseStatePKhS2_]
// Khung tháo gỡ #1555 | Địa chỉ PC: 0x18ee90 | Địa chỉ FDE: 0x048640 | Kích thước: 256 bytes
//   0x18ee90: F81C0FF8  str      x24, [sp, #-0x40]!
//   0x18ee94: A9015BF7  stp      x23, x22, [sp, #0x10]
//   0x18ee98: A90253F5  stp      x21, x20, [sp, #0x20]
//   0x18ee9c: A9037BF3  stp      x19, x30, [sp, #0x30]
static inline uint64_t fde_func_1555_0x18ee90(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x18ee90ULL ^ (static_cast<uint64_t>(0xf81c0ff8ULL) << 13);
    acc = (acc + a1 + 0xa9015bf7ULL) ^ 0x048640ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1556 | PC: 0x18efdc | FDE: 0x048668 | Size: 256 bytes
// Khung tháo gỡ #1556 | Địa chỉ PC: 0x18efdc | Địa chỉ FDE: 0x048668 | Kích thước: 256 bytes
//   0x18efdc: D10143FF  sub      sp, sp, #0x50
//   0x18efe0: A90163F9  stp      x25, x24, [sp, #0x10]
//   0x18efe4: A9025BF7  stp      x23, x22, [sp, #0x20]
//   0x18efe8: A90353F5  stp      x21, x20, [sp, #0x30]
static inline uint64_t fde_func_1556_0x18efdc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x18efdcULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xa90163f9ULL) ^ 0x048668ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1557 | PC: 0x18f204 | FDE: 0x048690 | Size: 256 bytes
// Khung tháo gỡ #1557 | Địa chỉ PC: 0x18f204 | Địa chỉ FDE: 0x048690 | Kích thước: 256 bytes
//   0x18f204: F81E0FF4  str      x20, [sp, #-0x20]!
//   0x18f208: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x18f20c: B9401808  ldr      w8, [x0, #0x18]
//   0x18f210: AA0003F4  mov      x20, x0
static inline uint64_t fde_func_1557_0x18f204(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x18f204ULL ^ (static_cast<uint64_t>(0xf81e0ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x048690ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1558 | PC: 0x18f324 | FDE: 0x0486b0 | Size: 256 bytes
// Khung tháo gỡ #1558 | Địa chỉ PC: 0x18f324 | Địa chỉ FDE: 0x0486b0 | Kích thước: 256 bytes
//   0x18f324: D10143FF  sub      sp, sp, #0x50
//   0x18f328: F9000BF8  str      x24, [sp, #0x10]
//   0x18f32c: A9025BF7  stp      x23, x22, [sp, #0x20]
//   0x18f330: A90353F5  stp      x21, x20, [sp, #0x30]
static inline uint64_t fde_func_1558_0x18f324(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x18f324ULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xf9000bf8ULL) ^ 0x0486b0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1559 | PC: 0x18f688 | FDE: 0x0486d8 | Size: 256 bytes
// Khung tháo gỡ #1559 | Địa chỉ PC: 0x18f688 | Địa chỉ FDE: 0x0486d8 | Kích thước: 256 bytes
//   0x18f688: D10103FF  sub      sp, sp, #0x40
//   0x18f68c: A9015BF7  stp      x23, x22, [sp, #0x10]
//   0x18f690: A90253F5  stp      x21, x20, [sp, #0x20]
//   0x18f694: A9037BF3  stp      x19, x30, [sp, #0x30]
static inline uint64_t fde_func_1559_0x18f688(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x18f688ULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xa9015bf7ULL) ^ 0x0486d8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1560 | PC: 0x18f85c | FDE: 0x0486f8 | Size: 256 bytes
// Khung tháo gỡ #1560 | Địa chỉ PC: 0x18f85c | Địa chỉ FDE: 0x0486f8 | Kích thước: 256 bytes
//   0x18f85c: F81B0FFA  str      x26, [sp, #-0x50]!
//   0x18f860: A90163F9  stp      x25, x24, [sp, #0x10]
//   0x18f864: A9025BF7  stp      x23, x22, [sp, #0x20]
//   0x18f868: A90353F5  stp      x21, x20, [sp, #0x30]
static inline uint64_t fde_func_1560_0x18f85c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x18f85cULL ^ (static_cast<uint64_t>(0xf81b0ffaULL) << 13);
    acc = (acc + a1 + 0xa90163f9ULL) ^ 0x0486f8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1561 | PC: 0x18fa58 | FDE: 0x048720 | Size: 256 bytes
// Khung tháo gỡ #1561 | Địa chỉ PC: 0x18fa58 | Địa chỉ FDE: 0x048720 | Kích thước: 256 bytes
//   0x18fa58: D10143FF  sub      sp, sp, #0x50
//   0x18fa5c: F9000BF8  str      x24, [sp, #0x10]
//   0x18fa60: A9025BF7  stp      x23, x22, [sp, #0x20]
//   0x18fa64: A90353F5  stp      x21, x20, [sp, #0x30]
static inline uint64_t fde_func_1561_0x18fa58(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x18fa58ULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xf9000bf8ULL) ^ 0x048720ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1562 | PC: 0x190054 | FDE: 0x048748 | Size: 256 bytes
// Khung tháo gỡ #1562 | Địa chỉ PC: 0x190054 | Địa chỉ FDE: 0x048748 | Kích thước: 256 bytes
//   0x190054: D10143FF  sub      sp, sp, #0x50
//   0x190058: F9000BF8  str      x24, [sp, #0x10]
//   0x19005c: A9025BF7  stp      x23, x22, [sp, #0x20]
//   0x190060: A90353F5  stp      x21, x20, [sp, #0x30]
static inline uint64_t fde_func_1562_0x190054(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x190054ULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xf9000bf8ULL) ^ 0x048748ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1563 | PC: 0x19023c | FDE: 0x048770 | Size: 256 bytes
// Khung tháo gỡ #1563 | Địa chỉ PC: 0x19023c | Địa chỉ FDE: 0x048770 | Kích thước: 256 bytes
//   0x19023c: F81D0FF6  str      x22, [sp, #-0x30]!
//   0x190240: A90153F5  stp      x21, x20, [sp, #0x10]
//   0x190244: A9027BF3  stp      x19, x30, [sp, #0x20]
//   0x190248: B9401808  ldr      w8, [x0, #0x18]
static inline uint64_t fde_func_1563_0x19023c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x19023cULL ^ (static_cast<uint64_t>(0xf81d0ff6ULL) << 13);
    acc = (acc + a1 + 0xa90153f5ULL) ^ 0x048770ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1564 | PC: 0x190374 | FDE: 0x048790 | Size: 256 bytes
// Khung tháo gỡ #1564 | Địa chỉ PC: 0x190374 | Địa chỉ FDE: 0x048790 | Kích thước: 256 bytes
//   0x190374: A9BB6BFB  stp      x27, x26, [sp, #-0x50]!
//   0x190378: A90163F9  stp      x25, x24, [sp, #0x10]
//   0x19037c: A9025BF7  stp      x23, x22, [sp, #0x20]
//   0x190380: A90353F5  stp      x21, x20, [sp, #0x30]
static inline uint64_t fde_func_1564_0x190374(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x190374ULL ^ (static_cast<uint64_t>(0xa9bb6bfbULL) << 13);
    acc = (acc + a1 + 0xa90163f9ULL) ^ 0x048790ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1565 | PC: 0x1904ec | FDE: 0x0487b8 | Size: 256 bytes
// Khung tháo gỡ #1565 | Địa chỉ PC: 0x1904ec | Địa chỉ FDE: 0x0487b8 | Kích thước: 256 bytes
//   0x1904ec: F81C0FF8  str      x24, [sp, #-0x40]!
//   0x1904f0: A9015BF7  stp      x23, x22, [sp, #0x10]
//   0x1904f4: A90253F5  stp      x21, x20, [sp, #0x20]
//   0x1904f8: A9037BF3  stp      x19, x30, [sp, #0x30]
static inline uint64_t fde_func_1565_0x1904ec(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1904ecULL ^ (static_cast<uint64_t>(0xf81c0ff8ULL) << 13);
    acc = (acc + a1 + 0xa9015bf7ULL) ^ 0x0487b8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1566 | PC: 0x190664 | FDE: 0x0487e0 | Size: 256 bytes
// Khung tháo gỡ #1566 | Địa chỉ PC: 0x190664 | Địa chỉ FDE: 0x0487e0 | Kích thước: 256 bytes
//   0x190664: F81F0FFE  str      x30, [sp, #-0x10]!
//   0x190668: 39420829  ldrb     w9, [x1, #0x82]
//   0x19066c: B9405028  ldr      w8, [x1, #0x50]
//   0x190670: 37000169  tbnz     w9, #0, #0x19069c
static inline uint64_t fde_func_1566_0x190664(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x190664ULL ^ (static_cast<uint64_t>(0xf81f0ffeULL) << 13);
    acc = (acc + a1 + 0x39420829ULL) ^ 0x0487e0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1567 | PC: 0x1907bc | FDE: 0x0487f8 | Size: 256 bytes
// Khung tháo gỡ #1567 | Địa chỉ PC: 0x1907bc | Địa chỉ FDE: 0x0487f8 | Kích thước: 256 bytes
//   0x1907bc: D10303FF  sub      sp, sp, #0xc0
//   0x1907c0: FD002BE8  str      d8, [sp, #0x50]
//   0x1907c4: A9066FFC  stp      x28, x27, [sp, #0x60]
//   0x1907c8: A90767FA  stp      x26, x25, [sp, #0x70]
static inline uint64_t fde_func_1567_0x1907bc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1907bcULL ^ (static_cast<uint64_t>(0xd10303ffULL) << 13);
    acc = (acc + a1 + 0xfd002be8ULL) ^ 0x0487f8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1568 | PC: 0x19100c | FDE: 0x048828 | Size: 124 bytes
// Khung tháo gỡ #1568 | Địa chỉ PC: 0x19100c | Địa chỉ FDE: 0x048828 | Kích thước: 124 bytes
//   0x19100c: D10083FF  sub      sp, sp, #0x20
//   0x191010: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x191014: AA0003F3  mov      x19, x0
//   0x191018: 910003E0  mov      x0, sp
static inline uint64_t fde_func_1568_0x19100c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x19100cULL ^ (static_cast<uint64_t>(0xd10083ffULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x048828ULL;
    acc ^= (acc >> 17) * 0x007cULL;
    return acc;
}

// FDE #1569 | PC: 0x191088 | FDE: 0x048840 | Size: 256 bytes
// Khung tháo gỡ #1569 | Địa chỉ PC: 0x191088 | Địa chỉ FDE: 0x048840 | Kích thước: 256 bytes
//   0x191088: D104C3FF  sub      sp, sp, #0x130
//   0x19108c: F9006BFC  str      x28, [sp, #0xd0]
//   0x191090: A90E6BFB  stp      x27, x26, [sp, #0xe0]
//   0x191094: A90F63F9  stp      x25, x24, [sp, #0xf0]
static inline uint64_t fde_func_1569_0x191088(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x191088ULL ^ (static_cast<uint64_t>(0xd104c3ffULL) << 13);
    acc = (acc + a1 + 0xf9006bfcULL) ^ 0x048840ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1570 | PC: 0x191e58 | FDE: 0x048870 | Size: 256 bytes
// Khung tháo gỡ #1570 | Địa chỉ PC: 0x191e58 | Địa chỉ FDE: 0x048870 | Kích thước: 256 bytes
//   0x191e58: D10283FF  sub      sp, sp, #0xa0
//   0x191e5c: A9056BFB  stp      x27, x26, [sp, #0x50]
//   0x191e60: A90663F9  stp      x25, x24, [sp, #0x60]
//   0x191e64: A9075BF7  stp      x23, x22, [sp, #0x70]
static inline uint64_t fde_func_1570_0x191e58(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x191e58ULL ^ (static_cast<uint64_t>(0xd10283ffULL) << 13);
    acc = (acc + a1 + 0xa9056bfbULL) ^ 0x048870ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1571 | PC: 0x191ffc | FDE: 0x0488a0 | Size: 256 bytes
// Khung tháo gỡ #1571 | Địa chỉ PC: 0x191ffc | Địa chỉ FDE: 0x0488a0 | Kích thước: 256 bytes
//   0x191ffc: D10243FF  sub      sp, sp, #0x90
//   0x192000: 6D0523E9  stp      d9, d8, [sp, #0x50]
//   0x192004: F90033F6  str      x22, [sp, #0x60]
//   0x192008: A90753F5  stp      x21, x20, [sp, #0x70]
static inline uint64_t fde_func_1571_0x191ffc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x191ffcULL ^ (static_cast<uint64_t>(0xd10243ffULL) << 13);
    acc = (acc + a1 + 0x6d0523e9ULL) ^ 0x0488a0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1572 | PC: 0x192340 | FDE: 0x0488c8 | Size: 256 bytes
// Khung tháo gỡ #1572 | Địa chỉ PC: 0x192340 | Địa chỉ FDE: 0x0488c8 | Kích thước: 256 bytes
//   0x192340: F8404008  ldur     x8, [x0, #4]
//   0x192344: B940002C  ldr      w12, [x1]
//   0x192348: 12007909  and      w9, w8, #0x7fffffff
//   0x19234c: 6B09019F  cmp      w12, w9
static inline uint64_t fde_func_1572_0x192340(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x192340ULL ^ (static_cast<uint64_t>(0xf8404008ULL) << 13);
    acc = (acc + a1 + 0xb940002cULL) ^ 0x0488c8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1573 | PC: 0x19246c | FDE: 0x0488e0 | Size: 256 bytes
// Khung tháo gỡ #1573 | Địa chỉ PC: 0x19246c | Địa chỉ FDE: 0x0488e0 | Kích thước: 256 bytes
//   0x19246c: D10483FF  sub      sp, sp, #0x120
//   0x192470: FD0053EC  str      d12, [sp, #0xa0]
//   0x192474: 6D0AABEB  stp      d11, d10, [sp, #0xa8]
//   0x192478: 6D0BA3E9  stp      d9, d8, [sp, #0xb8]
static inline uint64_t fde_func_1573_0x19246c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x19246cULL ^ (static_cast<uint64_t>(0xd10483ffULL) << 13);
    acc = (acc + a1 + 0xfd0053ecULL) ^ 0x0488e0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1574 | PC: 0x1928b0 | FDE: 0x048920 | Size: 256 bytes
// Khung tháo gỡ #1574 | Địa chỉ PC: 0x1928b0 | Địa chỉ FDE: 0x048920 | Kích thước: 256 bytes
//   0x1928b0: D10203FF  sub      sp, sp, #0x80
//   0x1928b4: F9002BF6  str      x22, [sp, #0x50]
//   0x1928b8: A90653F5  stp      x21, x20, [sp, #0x60]
//   0x1928bc: A9077BF3  stp      x19, x30, [sp, #0x70]
static inline uint64_t fde_func_1574_0x1928b0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1928b0ULL ^ (static_cast<uint64_t>(0xd10203ffULL) << 13);
    acc = (acc + a1 + 0xf9002bf6ULL) ^ 0x048920ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1575 | PC: 0x192e1c | FDE: 0x048940 | Size: 256 bytes
// Khung tháo gỡ #1575 | Địa chỉ PC: 0x192e1c | Địa chỉ FDE: 0x048940 | Kích thước: 256 bytes
//   0x192e1c: F81F0FFE  str      x30, [sp, #-0x10]!
//   0x192e20: B4000721  cbz      x1, #0x192f04
//   0x192e24: D2800048  mov      x8, #2
//   0x192e28: F2FFFFE8  movk     x8, #0xffff, lsl #48
static inline uint64_t fde_func_1575_0x192e1c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x192e1cULL ^ (static_cast<uint64_t>(0xf81f0ffeULL) << 13);
    acc = (acc + a1 + 0xb4000721ULL) ^ 0x048940ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1576 | PC: 0x192f1c | FDE: 0x048958 | Size: 256 bytes
// Khung tháo gỡ #1576 | Địa chỉ PC: 0x192f1c | Địa chỉ FDE: 0x048958 | Kích thước: 256 bytes
//   0x192f1c: F81D0FF6  str      x22, [sp, #-0x30]!
//   0x192f20: A90153F5  stp      x21, x20, [sp, #0x10]
//   0x192f24: A9027BF3  stp      x19, x30, [sp, #0x20]
//   0x192f28: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_1576_0x192f1c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x192f1cULL ^ (static_cast<uint64_t>(0xf81d0ff6ULL) << 13);
    acc = (acc + a1 + 0xa90153f5ULL) ^ 0x048958ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1577 | PC: 0x19307c | FDE: 0x048978 | Size: 256 bytes
// Khung tháo gỡ #1577 | Địa chỉ PC: 0x19307c | Địa chỉ FDE: 0x048978 | Kích thước: 256 bytes
//   0x19307c: D10183FF  sub      sp, sp, #0x60
//   0x193080: A9057BF3  stp      x19, x30, [sp, #0x50]
//   0x193084: D53BD053  mrs      x19, tpidr_el0
//   0x193088: F9401668  ldr      x8, [x19, #0x28]
static inline uint64_t fde_func_1577_0x19307c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x19307cULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xa9057bf3ULL) ^ 0x048978ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1578 | PC: 0x1931e4 | FDE: 0x048990 | Size: 244 bytes
// Khung tháo gỡ #1578 | Địa chỉ PC: 0x1931e4 | Địa chỉ FDE: 0x048990 | Kích thước: 244 bytes
//   0x1931e4: D101C3FF  sub      sp, sp, #0x70
//   0x1931e8: F9002BF4  str      x20, [sp, #0x50]
//   0x1931ec: A9067BF3  stp      x19, x30, [sp, #0x60]
//   0x1931f0: D53BD054  mrs      x20, tpidr_el0
static inline uint64_t fde_func_1578_0x1931e4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1931e4ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xf9002bf4ULL) ^ 0x048990ULL;
    acc ^= (acc >> 17) * 0x00f4ULL;
    return acc;
}

// FDE #1579 | PC: 0x1932d8 | FDE: 0x0489b0 | Size: 256 bytes
// Khung tháo gỡ #1579 | Địa chỉ PC: 0x1932d8 | Địa chỉ FDE: 0x0489b0 | Kích thước: 256 bytes
//   0x1932d8: FC1C0FE8  str      d8, [sp, #-0x40]!
//   0x1932dc: A9015BF7  stp      x23, x22, [sp, #0x10]
//   0x1932e0: A90253F5  stp      x21, x20, [sp, #0x20]
//   0x1932e4: A9037BF3  stp      x19, x30, [sp, #0x30]
static inline uint64_t fde_func_1579_0x1932d8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1932d8ULL ^ (static_cast<uint64_t>(0xfc1c0fe8ULL) << 13);
    acc = (acc + a1 + 0xa9015bf7ULL) ^ 0x0489b0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1580 | PC: 0x193554 | FDE: 0x0489d8 | Size: 256 bytes
// Khung tháo gỡ #1580 | Địa chỉ PC: 0x193554 | Địa chỉ FDE: 0x0489d8 | Kích thước: 256 bytes
//   0x193554: D10303FF  sub      sp, sp, #0xc0
//   0x193558: FD0033E8  str      d8, [sp, #0x60]
//   0x19355c: F90037FC  str      x28, [sp, #0x68]
//   0x193560: A9076BFB  stp      x27, x26, [sp, #0x70]
static inline uint64_t fde_func_1580_0x193554(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x193554ULL ^ (static_cast<uint64_t>(0xd10303ffULL) << 13);
    acc = (acc + a1 + 0xfd0033e8ULL) ^ 0x0489d8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1581 | PC: 0x1937fc | FDE: 0x048a08 | Size: 256 bytes
// Khung tháo gỡ #1581 | Địa chỉ PC: 0x1937fc | Địa chỉ FDE: 0x048a08 | Kích thước: 256 bytes
//   0x1937fc: D10143FF  sub      sp, sp, #0x50
//   0x193800: F90013F6  str      x22, [sp, #0x20]
//   0x193804: A90353F5  stp      x21, x20, [sp, #0x30]
//   0x193808: A9047BF3  stp      x19, x30, [sp, #0x40]
static inline uint64_t fde_func_1581_0x1937fc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1937fcULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xf90013f6ULL) ^ 0x048a08ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1582 | PC: 0x1939c4 | FDE: 0x048a28 | Size: 256 bytes
// Khung tháo gỡ #1582 | Địa chỉ PC: 0x1939c4 | Địa chỉ FDE: 0x048a28 | Kích thước: 256 bytes
//   0x1939c4: D10183FF  sub      sp, sp, #0x60
//   0x1939c8: A9016BFB  stp      x27, x26, [sp, #0x10]
//   0x1939cc: A90263F9  stp      x25, x24, [sp, #0x20]
//   0x1939d0: A9035BF7  stp      x23, x22, [sp, #0x30]
static inline uint64_t fde_func_1582_0x1939c4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1939c4ULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xa9016bfbULL) ^ 0x048a28ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1583 | PC: 0x193e38 | FDE: 0x048a50 | Size: 256 bytes
// Khung tháo gỡ #1583 | Địa chỉ PC: 0x193e38 | Địa chỉ FDE: 0x048a50 | Kích thước: 256 bytes
//   0x193e38: D10283FF  sub      sp, sp, #0xa0
//   0x193e3c: A9046FFC  stp      x28, x27, [sp, #0x40]
//   0x193e40: A90567FA  stp      x26, x25, [sp, #0x50]
//   0x193e44: A9065FF8  stp      x24, x23, [sp, #0x60]
static inline uint64_t fde_func_1583_0x193e38(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x193e38ULL ^ (static_cast<uint64_t>(0xd10283ffULL) << 13);
    acc = (acc + a1 + 0xa9046ffcULL) ^ 0x048a50ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1584 | PC: 0x194100 | FDE: 0x048a80 | Size: 212 bytes
// Khung tháo gỡ #1584 | Địa chỉ PC: 0x194100 | Địa chỉ FDE: 0x048a80 | Kích thước: 212 bytes
//   0x194100: F100483F  cmp      x1, #0x12
//   0x194104: 54000240  b.eq     #0x19414c
//   0x194108: B0000148  adrp     x8, #0x1bd000
//   0x19410c: F9400809  ldr      x9, [x0, #0x10]
static inline uint64_t fde_func_1584_0x194100(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x194100ULL ^ (static_cast<uint64_t>(0xf100483fULL) << 13);
    acc = (acc + a1 + 0x54000240ULL) ^ 0x048a80ULL;
    acc ^= (acc >> 17) * 0x00d4ULL;
    return acc;
}

// FDE #1585 | PC: 0x1941d4 | FDE: 0x048a98 | Size: 256 bytes
// Khung tháo gỡ #1585 | Địa chỉ PC: 0x1941d4 | Địa chỉ FDE: 0x048a98 | Kích thước: 256 bytes
//   0x1941d4: FC1B0FE8  str      d8, [sp, #-0x50]!
//   0x1941d8: A90163F9  stp      x25, x24, [sp, #0x10]
//   0x1941dc: A9025BF7  stp      x23, x22, [sp, #0x20]
//   0x1941e0: A90353F5  stp      x21, x20, [sp, #0x30]
static inline uint64_t fde_func_1585_0x1941d4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1941d4ULL ^ (static_cast<uint64_t>(0xfc1b0fe8ULL) << 13);
    acc = (acc + a1 + 0xa90163f9ULL) ^ 0x048a98ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1586 | PC: 0x194620 | FDE: 0x048ac0 | Size: 256 bytes
// Khung tháo gỡ #1586 | Địa chỉ PC: 0x194620 | Địa chỉ FDE: 0x048ac0 | Kích thước: 256 bytes
//   0x194620: F81C0FF8  str      x24, [sp, #-0x40]!
//   0x194624: A9015BF7  stp      x23, x22, [sp, #0x10]
//   0x194628: A90253F5  stp      x21, x20, [sp, #0x20]
//   0x19462c: A9037BF3  stp      x19, x30, [sp, #0x30]
static inline uint64_t fde_func_1586_0x194620(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x194620ULL ^ (static_cast<uint64_t>(0xf81c0ff8ULL) << 13);
    acc = (acc + a1 + 0xa9015bf7ULL) ^ 0x048ac0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1587 | PC: 0x194810 | FDE: 0x048ae8 | Size: 256 bytes
// Khung tháo gỡ #1587 | Địa chỉ PC: 0x194810 | Địa chỉ FDE: 0x048ae8 | Kích thước: 256 bytes
//   0x194810: D10283FF  sub      sp, sp, #0xa0
//   0x194814: F9002BFA  str      x26, [sp, #0x50]
//   0x194818: A90663F9  stp      x25, x24, [sp, #0x60]
//   0x19481c: A9075BF7  stp      x23, x22, [sp, #0x70]
static inline uint64_t fde_func_1587_0x194810(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x194810ULL ^ (static_cast<uint64_t>(0xd10283ffULL) << 13);
    acc = (acc + a1 + 0xf9002bfaULL) ^ 0x048ae8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1588 | PC: 0x194bf8 | FDE: 0x048b10 | Size: 208 bytes
// Khung tháo gỡ #1588 | Địa chỉ PC: 0x194bf8 | Địa chỉ FDE: 0x048b10 | Kích thước: 208 bytes
//   0x194bf8: F81E0FF4  str      x20, [sp, #-0x20]!
//   0x194bfc: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x194c00: F100483F  cmp      x1, #0x12
//   0x194c04: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_1588_0x194bf8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x194bf8ULL ^ (static_cast<uint64_t>(0xf81e0ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x048b10ULL;
    acc ^= (acc >> 17) * 0x00d0ULL;
    return acc;
}

// FDE #1589 | PC: 0x194cc8 | FDE: 0x048b30 | Size: 20 bytes
// Khung tháo gỡ #1589 | Địa chỉ PC: 0x194cc8 | Địa chỉ FDE: 0x048b30 | Kích thước: 20 bytes
//   0x194cc8: F9406401  ldr      x1, [x0, #0xc8]
//   0x194ccc: F9400062  ldr      x2, [x3]
//   0x194cd0: 52800063  mov      w3, #3
//   0x194cd4: 12800004  mov      w4, #-1
static inline uint64_t fde_func_1589_0x194cc8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x194cc8ULL ^ (static_cast<uint64_t>(0xf9406401ULL) << 13);
    acc = (acc + a1 + 0xf9400062ULL) ^ 0x048b30ULL;
    acc ^= (acc >> 17) * 0x0014ULL;
    return acc;
}

// FDE #1590 | PC: 0x194cdc | FDE: 0x048b48 | Size: 256 bytes
// Khung tháo gỡ #1590 | Địa chỉ PC: 0x194cdc | Địa chỉ FDE: 0x048b48 | Kích thước: 256 bytes
//   0x194cdc: D10383FF  sub      sp, sp, #0xe0
//   0x194ce0: A9086FFC  stp      x28, x27, [sp, #0x80]
//   0x194ce4: A90967FA  stp      x26, x25, [sp, #0x90]
//   0x194ce8: A90A5FF8  stp      x24, x23, [sp, #0xa0]
static inline uint64_t fde_func_1590_0x194cdc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x194cdcULL ^ (static_cast<uint64_t>(0xd10383ffULL) << 13);
    acc = (acc + a1 + 0xa9086ffcULL) ^ 0x048b48ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1591 | PC: 0x195784 | FDE: 0x048b78 | Size: 156 bytes
// Khung tháo gỡ #1591 | Địa chỉ PC: 0x195784 | Địa chỉ FDE: 0x048b78 | Kích thước: 156 bytes
//   0x195784: F81E0FF4  str      x20, [sp, #-0x20]!
//   0x195788: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x19578c: F9400061  ldr      x1, [x3]
//   0x195790: 2A1F03E2  mov      w2, wzr
static inline uint64_t fde_func_1591_0x195784(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x195784ULL ^ (static_cast<uint64_t>(0xf81e0ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x048b78ULL;
    acc ^= (acc >> 17) * 0x009cULL;
    return acc;
}

// FDE #1592 | PC: 0x195820 | FDE: 0x048b98 | Size: 136 bytes
// Khung tháo gỡ #1592 | Địa chỉ PC: 0x195820 | Địa chỉ FDE: 0x048b98 | Kích thước: 136 bytes
//   0x195820: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x195824: F9400069  ldr      x9, [x3]
//   0x195828: D2800028  mov      x8, #1
//   0x19582c: F2E00028  movk     x8, #1, lsl #48
static inline uint64_t fde_func_1592_0x195820(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x195820ULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0xf9400069ULL) ^ 0x048b98ULL;
    acc ^= (acc >> 17) * 0x0088ULL;
    return acc;
}

// FDE #1593 | PC: 0x1958a8 | FDE: 0x048bb0 | Size: 256 bytes
// Khung tháo gỡ #1593 | Địa chỉ PC: 0x1958a8 | Địa chỉ FDE: 0x048bb0 | Kích thước: 256 bytes
//   0x1958a8: F81D0FF6  str      x22, [sp, #-0x30]!
//   0x1958ac: A90153F5  stp      x21, x20, [sp, #0x10]
//   0x1958b0: A9027BF3  stp      x19, x30, [sp, #0x20]
//   0x1958b4: 90000156  adrp     x22, #0x1bd000
static inline uint64_t fde_func_1593_0x1958a8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1958a8ULL ^ (static_cast<uint64_t>(0xf81d0ff6ULL) << 13);
    acc = (acc + a1 + 0xa90153f5ULL) ^ 0x048bb0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1594 | PC: 0x195ac8 | FDE: 0x048bd0 | Size: 256 bytes
// Khung tháo gỡ #1594 | Địa chỉ PC: 0x195ac8 | Địa chỉ FDE: 0x048bd0 | Kích thước: 256 bytes
//   0x195ac8: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x195acc: D2800029  mov      x9, #1
//   0x195ad0: F2E00029  movk     x9, #1, lsl #48
//   0x195ad4: 92504428  and      x8, x1, #0xffff000000000003
static inline uint64_t fde_func_1594_0x195ac8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x195ac8ULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0xd2800029ULL) ^ 0x048bd0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1595 | PC: 0x195c20 | FDE: 0x048be8 | Size: 256 bytes
// Khung tháo gỡ #1595 | Địa chỉ PC: 0x195c20 | Địa chỉ FDE: 0x048be8 | Kích thước: 256 bytes
//   0x195c20: D10243FF  sub      sp, sp, #0x90
//   0x195c24: F9002BF8  str      x24, [sp, #0x50]
//   0x195c28: A9065BF7  stp      x23, x22, [sp, #0x60]
//   0x195c2c: A90753F5  stp      x21, x20, [sp, #0x70]
static inline uint64_t fde_func_1595_0x195c20(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x195c20ULL ^ (static_cast<uint64_t>(0xd10243ffULL) << 13);
    acc = (acc + a1 + 0xf9002bf8ULL) ^ 0x048be8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1596 | PC: 0x195f44 | FDE: 0x048c10 | Size: 12 bytes
// Khung tháo gỡ #1596 | Địa chỉ PC: 0x195f44 | Địa chỉ FDE: 0x048c10 | Kích thước: 12 bytes
//   0x195f44: F8408461  ldr      x1, [x3], #8
//   0x195f48: 2A1F03E4  mov      w4, wzr
//   0x195f4c: 17FD8B7A  b        #0xf8d34
static inline uint64_t fde_func_1596_0x195f44(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x195f44ULL ^ (static_cast<uint64_t>(0xf8408461ULL) << 13);
    acc = (acc + a1 + 0x2a1f03e4ULL) ^ 0x048c10ULL;
    acc ^= (acc >> 17) * 0x000cULL;
    return acc;
}

// FDE #1597 | PC: 0x195f50 | FDE: 0x048c28 | Size: 256 bytes
// Khung tháo gỡ #1597 | Địa chỉ PC: 0x195f50 | Địa chỉ FDE: 0x048c28 | Kích thước: 256 bytes
//   0x195f50: D101C3FF  sub      sp, sp, #0x70
//   0x195f54: A9016FFC  stp      x28, x27, [sp, #0x10]
//   0x195f58: A90267FA  stp      x26, x25, [sp, #0x20]
//   0x195f5c: A9035FF8  stp      x24, x23, [sp, #0x30]
static inline uint64_t fde_func_1597_0x195f50(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x195f50ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xa9016ffcULL) ^ 0x048c28ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1598 | PC: 0x196108 | FDE: 0x048c58 | Size: 256 bytes
// Khung tháo gỡ #1598 | Địa chỉ PC: 0x196108 | Địa chỉ FDE: 0x048c58 | Kích thước: 256 bytes
//   0x196108: D10183FF  sub      sp, sp, #0x60
//   0x19610c: A90263F9  stp      x25, x24, [sp, #0x20]
//   0x196110: A9035BF7  stp      x23, x22, [sp, #0x30]
//   0x196114: A90453F5  stp      x21, x20, [sp, #0x40]
static inline uint64_t fde_func_1598_0x196108(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x196108ULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xa90263f9ULL) ^ 0x048c58ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1599 | PC: 0x1962cc | FDE: 0x048c80 | Size: 256 bytes
// Khung tháo gỡ #1599 | Địa chỉ PC: 0x1962cc | Địa chỉ FDE: 0x048c80 | Kích thước: 256 bytes
//   0x1962cc: D10103FF  sub      sp, sp, #0x40
//   0x1962d0: A9015BF7  stp      x23, x22, [sp, #0x10]
//   0x1962d4: A90253F5  stp      x21, x20, [sp, #0x20]
//   0x1962d8: A9037BF3  stp      x19, x30, [sp, #0x30]
static inline uint64_t fde_func_1599_0x1962cc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1962ccULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xa9015bf7ULL) ^ 0x048c80ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1600 | PC: 0x196404 | FDE: 0x048ca0 | Size: 256 bytes
// Khung tháo gỡ #1600 | Địa chỉ PC: 0x196404 | Địa chỉ FDE: 0x048ca0 | Kích thước: 256 bytes
//   0x196404: F81C0FF8  str      x24, [sp, #-0x40]!
//   0x196408: A9015BF7  stp      x23, x22, [sp, #0x10]
//   0x19640c: A90253F5  stp      x21, x20, [sp, #0x20]
//   0x196410: A9037BF3  stp      x19, x30, [sp, #0x30]
static inline uint64_t fde_func_1600_0x196404(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x196404ULL ^ (static_cast<uint64_t>(0xf81c0ff8ULL) << 13);
    acc = (acc + a1 + 0xa9015bf7ULL) ^ 0x048ca0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1601 | PC: 0x19655c | FDE: 0x048cc8 | Size: 256 bytes [lepus_object_getOwnPropertyDescriptor]
// Khung tháo gỡ #1601 | Địa chỉ PC: 0x19655c | Địa chỉ FDE: 0x048cc8 | Kích thước: 256 bytes
//   0x19655c: D10243FF  sub      sp, sp, #0x90
//   0x196560: F9001BFC  str      x28, [sp, #0x30]
//   0x196564: A9046BFB  stp      x27, x26, [sp, #0x40]
//   0x196568: A90563F9  stp      x25, x24, [sp, #0x50]
static inline uint64_t fde_func_1601_0x19655c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x19655cULL ^ (static_cast<uint64_t>(0xd10243ffULL) << 13);
    acc = (acc + a1 + 0xf9001bfcULL) ^ 0x048cc8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1602 | PC: 0x196c1c | FDE: 0x048cf8 | Size: 228 bytes
// Khung tháo gỡ #1602 | Địa chỉ PC: 0x196c1c | Địa chỉ FDE: 0x048cf8 | Kích thước: 228 bytes
//   0x196c1c: F81E0FF4  str      x20, [sp, #-0x20]!
//   0x196c20: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x196c24: F9400061  ldr      x1, [x3]
//   0x196c28: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_1602_0x196c1c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x196c1cULL ^ (static_cast<uint64_t>(0xf81e0ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x048cf8ULL;
    acc ^= (acc >> 17) * 0x00e4ULL;
    return acc;
}

// FDE #1603 | PC: 0x196d00 | FDE: 0x048d18 | Size: 256 bytes
// Khung tháo gỡ #1603 | Địa chỉ PC: 0x196d00 | Địa chỉ FDE: 0x048d18 | Kích thước: 256 bytes
//   0x196d00: D10103FF  sub      sp, sp, #0x40
//   0x196d04: A9015BF7  stp      x23, x22, [sp, #0x10]
//   0x196d08: A90253F5  stp      x21, x20, [sp, #0x20]
//   0x196d0c: A9037BF3  stp      x19, x30, [sp, #0x30]
static inline uint64_t fde_func_1603_0x196d00(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x196d00ULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xa9015bf7ULL) ^ 0x048d18ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1604 | PC: 0x196e34 | FDE: 0x048d38 | Size: 256 bytes
// Khung tháo gỡ #1604 | Địa chỉ PC: 0x196e34 | Địa chỉ FDE: 0x048d38 | Kích thước: 256 bytes
//   0x196e34: A9BD5BF7  stp      x23, x22, [sp, #-0x30]!
//   0x196e38: A90153F5  stp      x21, x20, [sp, #0x10]
//   0x196e3c: A9027BF3  stp      x19, x30, [sp, #0x20]
//   0x196e40: F9400061  ldr      x1, [x3]
static inline uint64_t fde_func_1604_0x196e34(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x196e34ULL ^ (static_cast<uint64_t>(0xa9bd5bf7ULL) << 13);
    acc = (acc + a1 + 0xa90153f5ULL) ^ 0x048d38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1605 | PC: 0x196f50 | FDE: 0x048d58 | Size: 68 bytes
// Khung tháo gỡ #1605 | Địa chỉ PC: 0x196f50 | Địa chỉ FDE: 0x048d58 | Kích thước: 68 bytes
//   0x196f50: F81F0FFE  str      x30, [sp, #-0x10]!
//   0x196f54: F9400061  ldr      x1, [x3]
//   0x196f58: B4000121  cbz      x1, #0x196f7c
//   0x196f5c: D2800048  mov      x8, #2
static inline uint64_t fde_func_1605_0x196f50(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x196f50ULL ^ (static_cast<uint64_t>(0xf81f0ffeULL) << 13);
    acc = (acc + a1 + 0xf9400061ULL) ^ 0x048d58ULL;
    acc ^= (acc >> 17) * 0x0044ULL;
    return acc;
}

// FDE #1606 | PC: 0x196f94 | FDE: 0x048d70 | Size: 256 bytes
// Khung tháo gỡ #1606 | Địa chỉ PC: 0x196f94 | Địa chỉ FDE: 0x048d70 | Kích thước: 256 bytes
//   0x196f94: F81C0FF8  str      x24, [sp, #-0x40]!
//   0x196f98: A9015BF7  stp      x23, x22, [sp, #0x10]
//   0x196f9c: A90253F5  stp      x21, x20, [sp, #0x20]
//   0x196fa0: A9037BF3  stp      x19, x30, [sp, #0x30]
static inline uint64_t fde_func_1606_0x196f94(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x196f94ULL ^ (static_cast<uint64_t>(0xf81c0ff8ULL) << 13);
    acc = (acc + a1 + 0xa9015bf7ULL) ^ 0x048d70ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1607 | PC: 0x197108 | FDE: 0x048d98 | Size: 256 bytes
// Khung tháo gỡ #1607 | Địa chỉ PC: 0x197108 | Địa chỉ FDE: 0x048d98 | Kích thước: 256 bytes
//   0x197108: D10143FF  sub      sp, sp, #0x50
//   0x19710c: A90163F9  stp      x25, x24, [sp, #0x10]
//   0x197110: A9025BF7  stp      x23, x22, [sp, #0x20]
//   0x197114: A90353F5  stp      x21, x20, [sp, #0x30]
static inline uint64_t fde_func_1607_0x197108(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x197108ULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xa90163f9ULL) ^ 0x048d98ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1608 | PC: 0x1972e4 | FDE: 0x048dc0 | Size: 52 bytes
// Khung tháo gỡ #1608 | Địa chỉ PC: 0x1972e4 | Địa chỉ FDE: 0x048dc0 | Kích thước: 52 bytes
//   0x1972e4: F81F0FFE  str      x30, [sp, #-0x10]!
//   0x1972e8: A9400861  ldp      x1, x2, [x3]
//   0x1972ec: 2A1F03E3  mov      w3, wzr
//   0x1972f0: 97FDA598  bl       #0x100950
static inline uint64_t fde_func_1608_0x1972e4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1972e4ULL ^ (static_cast<uint64_t>(0xf81f0ffeULL) << 13);
    acc = (acc + a1 + 0xa9400861ULL) ^ 0x048dc0ULL;
    acc ^= (acc >> 17) * 0x0034ULL;
    return acc;
}

// FDE #1609 | PC: 0x197318 | FDE: 0x048dd8 | Size: 256 bytes
// Khung tháo gỡ #1609 | Địa chỉ PC: 0x197318 | Địa chỉ FDE: 0x048dd8 | Kích thước: 256 bytes
//   0x197318: D10103FF  sub      sp, sp, #0x40
//   0x19731c: FD000BE8  str      d8, [sp, #0x10]
//   0x197320: F9000FF6  str      x22, [sp, #0x18]
//   0x197324: A90253F5  stp      x21, x20, [sp, #0x20]
static inline uint64_t fde_func_1609_0x197318(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x197318ULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xfd000be8ULL) ^ 0x048dd8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1610 | PC: 0x1975c0 | FDE: 0x048e00 | Size: 256 bytes
// Khung tháo gỡ #1610 | Địa chỉ PC: 0x1975c0 | Địa chỉ FDE: 0x048e00 | Kích thước: 256 bytes
//   0x1975c0: D10103FF  sub      sp, sp, #0x40
//   0x1975c4: FD000BE8  str      d8, [sp, #0x10]
//   0x1975c8: A90253F5  stp      x21, x20, [sp, #0x20]
//   0x1975cc: A9037BF3  stp      x19, x30, [sp, #0x30]
static inline uint64_t fde_func_1610_0x1975c0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1975c0ULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xfd000be8ULL) ^ 0x048e00ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1611 | PC: 0x1976e0 | FDE: 0x048e20 | Size: 96 bytes
// Khung tháo gỡ #1611 | Địa chỉ PC: 0x1976e0 | Địa chỉ FDE: 0x048e20 | Kích thước: 96 bytes
//   0x1976e0: F9406C08  ldr      x8, [x0, #0xd8]
//   0x1976e4: D29BA3A9  mov      x9, #0xdd1d
//   0x1976e8: F2A9ED89  movk     x9, #0x4f6c, lsl #16
//   0x1976ec: F2DE9229  movk     x9, #0xf491, lsl #32
static inline uint64_t fde_func_1611_0x1976e0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1976e0ULL ^ (static_cast<uint64_t>(0xf9406c08ULL) << 13);
    acc = (acc + a1 + 0xd29ba3a9ULL) ^ 0x048e20ULL;
    acc ^= (acc >> 17) * 0x0060ULL;
    return acc;
}

// FDE #1612 | PC: 0x197740 | FDE: 0x048e38 | Size: 84 bytes
// Khung tháo gỡ #1612 | Địa chỉ PC: 0x197740 | Địa chỉ FDE: 0x048e38 | Kích thước: 84 bytes
//   0x197740: F81E0FF4  str      x20, [sp, #-0x20]!
//   0x197744: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x197748: F9400062  ldr      x2, [x3]
//   0x19774c: 910033E1  add      x1, sp, #0xc
static inline uint64_t fde_func_1612_0x197740(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x197740ULL ^ (static_cast<uint64_t>(0xf81e0ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x048e38ULL;
    acc ^= (acc >> 17) * 0x0054ULL;
    return acc;
}

// FDE #1613 | PC: 0x197794 | FDE: 0x048e58 | Size: 52 bytes
// Khung tháo gỡ #1613 | Địa chỉ PC: 0x197794 | Địa chỉ FDE: 0x048e58 | Kích thước: 52 bytes
//   0x197794: F81F0FFE  str      x30, [sp, #-0x10]!
//   0x197798: F9400062  ldr      x2, [x3]
//   0x19779c: 910033E1  add      x1, sp, #0xc
//   0x1977a0: 97FDE951  bl       #0x111ce4
static inline uint64_t fde_func_1613_0x197794(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x197794ULL ^ (static_cast<uint64_t>(0xf81f0ffeULL) << 13);
    acc = (acc + a1 + 0xf9400062ULL) ^ 0x048e58ULL;
    acc ^= (acc >> 17) * 0x0034ULL;
    return acc;
}

// FDE #1614 | PC: 0x1977c8 | FDE: 0x048e70 | Size: 256 bytes
// Khung tháo gỡ #1614 | Địa chỉ PC: 0x1977c8 | Địa chỉ FDE: 0x048e70 | Kích thước: 256 bytes
//   0x1977c8: D10243FF  sub      sp, sp, #0x90
//   0x1977cc: F9002BF8  str      x24, [sp, #0x50]
//   0x1977d0: A9065BF7  stp      x23, x22, [sp, #0x60]
//   0x1977d4: A90753F5  stp      x21, x20, [sp, #0x70]
static inline uint64_t fde_func_1614_0x1977c8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1977c8ULL ^ (static_cast<uint64_t>(0xd10243ffULL) << 13);
    acc = (acc + a1 + 0xf9002bf8ULL) ^ 0x048e70ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1615 | PC: 0x197ad4 | FDE: 0x048e98 | Size: 256 bytes
// Khung tháo gỡ #1615 | Địa chỉ PC: 0x197ad4 | Địa chỉ FDE: 0x048e98 | Kích thước: 256 bytes
//   0x197ad4: F81C0FF8  str      x24, [sp, #-0x40]!
//   0x197ad8: A9015BF7  stp      x23, x22, [sp, #0x10]
//   0x197adc: A90253F5  stp      x21, x20, [sp, #0x20]
//   0x197ae0: A9037BF3  stp      x19, x30, [sp, #0x30]
static inline uint64_t fde_func_1615_0x197ad4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x197ad4ULL ^ (static_cast<uint64_t>(0xf81c0ff8ULL) << 13);
    acc = (acc + a1 + 0xa9015bf7ULL) ^ 0x048e98ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1616 | PC: 0x197d2c | FDE: 0x048ec0 | Size: 256 bytes
// Khung tháo gỡ #1616 | Địa chỉ PC: 0x197d2c | Địa chỉ FDE: 0x048ec0 | Kích thước: 256 bytes
//   0x197d2c: D10143FF  sub      sp, sp, #0x50
//   0x197d30: A90163F9  stp      x25, x24, [sp, #0x10]
//   0x197d34: A9025BF7  stp      x23, x22, [sp, #0x20]
//   0x197d38: A90353F5  stp      x21, x20, [sp, #0x30]
static inline uint64_t fde_func_1616_0x197d2c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x197d2cULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xa90163f9ULL) ^ 0x048ec0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1617 | PC: 0x198094 | FDE: 0x048ee8 | Size: 256 bytes
// Khung tháo gỡ #1617 | Địa chỉ PC: 0x198094 | Địa chỉ FDE: 0x048ee8 | Kích thước: 256 bytes
//   0x198094: A9BA6FFC  stp      x28, x27, [sp, #-0x60]!
//   0x198098: A90167FA  stp      x26, x25, [sp, #0x10]
//   0x19809c: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x1980a0: A90357F6  stp      x22, x21, [sp, #0x30]
static inline uint64_t fde_func_1617_0x198094(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x198094ULL ^ (static_cast<uint64_t>(0xa9ba6ffcULL) << 13);
    acc = (acc + a1 + 0xa90167faULL) ^ 0x048ee8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1618 | PC: 0x1981ec | FDE: 0x048f18 | Size: 256 bytes
// Khung tháo gỡ #1618 | Địa chỉ PC: 0x1981ec | Địa chỉ FDE: 0x048f18 | Kích thước: 256 bytes
//   0x1981ec: F81C0FF8  str      x24, [sp, #-0x40]!
//   0x1981f0: A9015BF7  stp      x23, x22, [sp, #0x10]
//   0x1981f4: A90253F5  stp      x21, x20, [sp, #0x20]
//   0x1981f8: A9037BF3  stp      x19, x30, [sp, #0x30]
static inline uint64_t fde_func_1618_0x1981ec(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1981ecULL ^ (static_cast<uint64_t>(0xf81c0ff8ULL) << 13);
    acc = (acc + a1 + 0xa9015bf7ULL) ^ 0x048f18ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1619 | PC: 0x19848c | FDE: 0x048f40 | Size: 256 bytes
// Khung tháo gỡ #1619 | Địa chỉ PC: 0x19848c | Địa chỉ FDE: 0x048f40 | Kích thước: 256 bytes
//   0x19848c: D10203FF  sub      sp, sp, #0x80
//   0x198490: A9026FFC  stp      x28, x27, [sp, #0x20]
//   0x198494: A90367FA  stp      x26, x25, [sp, #0x30]
//   0x198498: A9045FF8  stp      x24, x23, [sp, #0x40]
static inline uint64_t fde_func_1619_0x19848c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x19848cULL ^ (static_cast<uint64_t>(0xd10203ffULL) << 13);
    acc = (acc + a1 + 0xa9026ffcULL) ^ 0x048f40ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1620 | PC: 0x19897c | FDE: 0x048f70 | Size: 256 bytes
// Khung tháo gỡ #1620 | Địa chỉ PC: 0x19897c | Địa chỉ FDE: 0x048f70 | Kích thước: 256 bytes
//   0x19897c: D101C3FF  sub      sp, sp, #0x70
//   0x198980: A9016FFC  stp      x28, x27, [sp, #0x10]
//   0x198984: A90267FA  stp      x26, x25, [sp, #0x20]
//   0x198988: A9035FF8  stp      x24, x23, [sp, #0x30]
static inline uint64_t fde_func_1620_0x19897c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x19897cULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xa9016ffcULL) ^ 0x048f70ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1621 | PC: 0x198e7c | FDE: 0x048fa0 | Size: 256 bytes
// Khung tháo gỡ #1621 | Địa chỉ PC: 0x198e7c | Địa chỉ FDE: 0x048fa0 | Kích thước: 256 bytes
//   0x198e7c: D101C3FF  sub      sp, sp, #0x70
//   0x198e80: A90363F9  stp      x25, x24, [sp, #0x30]
//   0x198e84: A9045BF7  stp      x23, x22, [sp, #0x40]
//   0x198e88: A90553F5  stp      x21, x20, [sp, #0x50]
static inline uint64_t fde_func_1621_0x198e7c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x198e7cULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xa90363f9ULL) ^ 0x048fa0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1622 | PC: 0x1992e0 | FDE: 0x048fc8 | Size: 256 bytes
// Khung tháo gỡ #1622 | Địa chỉ PC: 0x1992e0 | Địa chỉ FDE: 0x048fc8 | Kích thước: 256 bytes
//   0x1992e0: D102C3FF  sub      sp, sp, #0xb0
//   0x1992e4: A9056FFC  stp      x28, x27, [sp, #0x50]
//   0x1992e8: A90667FA  stp      x26, x25, [sp, #0x60]
//   0x1992ec: A9075FF8  stp      x24, x23, [sp, #0x70]
static inline uint64_t fde_func_1622_0x1992e0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1992e0ULL ^ (static_cast<uint64_t>(0xd102c3ffULL) << 13);
    acc = (acc + a1 + 0xa9056ffcULL) ^ 0x048fc8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1623 | PC: 0x199968 | FDE: 0x048ff8 | Size: 256 bytes
// Khung tháo gỡ #1623 | Địa chỉ PC: 0x199968 | Địa chỉ FDE: 0x048ff8 | Kích thước: 256 bytes
//   0x199968: D10183FF  sub      sp, sp, #0x60
//   0x19996c: A9016BFB  stp      x27, x26, [sp, #0x10]
//   0x199970: A90263F9  stp      x25, x24, [sp, #0x20]
//   0x199974: A9035BF7  stp      x23, x22, [sp, #0x30]
static inline uint64_t fde_func_1623_0x199968(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x199968ULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xa9016bfbULL) ^ 0x048ff8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1624 | PC: 0x199c84 | FDE: 0x049020 | Size: 256 bytes
// Khung tháo gỡ #1624 | Địa chỉ PC: 0x199c84 | Địa chỉ FDE: 0x049020 | Kích thước: 256 bytes
//   0x199c84: D10183FF  sub      sp, sp, #0x60
//   0x199c88: A9016BFB  stp      x27, x26, [sp, #0x10]
//   0x199c8c: A90263F9  stp      x25, x24, [sp, #0x20]
//   0x199c90: A9035BF7  stp      x23, x22, [sp, #0x30]
static inline uint64_t fde_func_1624_0x199c84(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x199c84ULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xa9016bfbULL) ^ 0x049020ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1625 | PC: 0x199fa0 | FDE: 0x049048 | Size: 256 bytes
// Khung tháo gỡ #1625 | Địa chỉ PC: 0x199fa0 | Địa chỉ FDE: 0x049048 | Kích thước: 256 bytes
//   0x199fa0: D10183FF  sub      sp, sp, #0x60
//   0x199fa4: A9016BFB  stp      x27, x26, [sp, #0x10]
//   0x199fa8: A90263F9  stp      x25, x24, [sp, #0x20]
//   0x199fac: A9035BF7  stp      x23, x22, [sp, #0x30]
static inline uint64_t fde_func_1625_0x199fa0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x199fa0ULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xa9016bfbULL) ^ 0x049048ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1626 | PC: 0x19a2bc | FDE: 0x049070 | Size: 256 bytes
// Khung tháo gỡ #1626 | Địa chỉ PC: 0x19a2bc | Địa chỉ FDE: 0x049070 | Kích thước: 256 bytes
//   0x19a2bc: D10243FF  sub      sp, sp, #0x90
//   0x19a2c0: F9001BFC  str      x28, [sp, #0x30]
//   0x19a2c4: A9046BFB  stp      x27, x26, [sp, #0x40]
//   0x19a2c8: A90563F9  stp      x25, x24, [sp, #0x50]
static inline uint64_t fde_func_1626_0x19a2bc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x19a2bcULL ^ (static_cast<uint64_t>(0xd10243ffULL) << 13);
    acc = (acc + a1 + 0xf9001bfcULL) ^ 0x049070ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1627 | PC: 0x19a6f0 | FDE: 0x0490a0 | Size: 256 bytes
// Khung tháo gỡ #1627 | Địa chỉ PC: 0x19a6f0 | Địa chỉ FDE: 0x0490a0 | Kích thước: 256 bytes
//   0x19a6f0: D10343FF  sub      sp, sp, #0xd0
//   0x19a6f4: A9076FFC  stp      x28, x27, [sp, #0x70]
//   0x19a6f8: A90867FA  stp      x26, x25, [sp, #0x80]
//   0x19a6fc: A9095FF8  stp      x24, x23, [sp, #0x90]
static inline uint64_t fde_func_1627_0x19a6f0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x19a6f0ULL ^ (static_cast<uint64_t>(0xd10343ffULL) << 13);
    acc = (acc + a1 + 0xa9076ffcULL) ^ 0x0490a0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1628 | PC: 0x19b04c | FDE: 0x0490d0 | Size: 256 bytes
// Khung tháo gỡ #1628 | Địa chỉ PC: 0x19b04c | Địa chỉ FDE: 0x0490d0 | Kích thước: 256 bytes
//   0x19b04c: D10283FF  sub      sp, sp, #0xa0
//   0x19b050: A9046FFC  stp      x28, x27, [sp, #0x40]
//   0x19b054: A90567FA  stp      x26, x25, [sp, #0x50]
//   0x19b058: A9065FF8  stp      x24, x23, [sp, #0x60]
static inline uint64_t fde_func_1628_0x19b04c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x19b04cULL ^ (static_cast<uint64_t>(0xd10283ffULL) << 13);
    acc = (acc + a1 + 0xa9046ffcULL) ^ 0x0490d0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1629 | PC: 0x19b6c4 | FDE: 0x049100 | Size: 256 bytes
// Khung tháo gỡ #1629 | Địa chỉ PC: 0x19b6c4 | Địa chỉ FDE: 0x049100 | Kích thước: 256 bytes
//   0x19b6c4: A9BD5BF7  stp      x23, x22, [sp, #-0x30]!
//   0x19b6c8: A90153F5  stp      x21, x20, [sp, #0x10]
//   0x19b6cc: A9027BF3  stp      x19, x30, [sp, #0x20]
//   0x19b6d0: B27C0028  orr      x8, x1, #0x10
static inline uint64_t fde_func_1629_0x19b6c4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x19b6c4ULL ^ (static_cast<uint64_t>(0xa9bd5bf7ULL) << 13);
    acc = (acc + a1 + 0xa90153f5ULL) ^ 0x049100ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1630 | PC: 0x19ba3c | FDE: 0x049120 | Size: 256 bytes
// Khung tháo gỡ #1630 | Địa chỉ PC: 0x19ba3c | Địa chỉ FDE: 0x049120 | Kích thước: 256 bytes
//   0x19ba3c: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x19ba40: D2800049  mov      x9, #2
//   0x19ba44: 92504428  and      x8, x1, #0xffff000000000003
//   0x19ba48: F2E00029  movk     x9, #1, lsl #48
static inline uint64_t fde_func_1630_0x19ba3c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x19ba3cULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0xd2800049ULL) ^ 0x049120ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1631 | PC: 0x19bbb0 | FDE: 0x049138 | Size: 4 bytes
// Khung tháo gỡ #1631 | Địa chỉ PC: 0x19bbb0 | Địa chỉ FDE: 0x049138 | Kích thước: 4 bytes
//   0x19bbb0: 17FEDCB1  b        #0x152e74
static inline uint64_t fde_func_1631_0x19bbb0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x19bbb0ULL ^ (static_cast<uint64_t>(0x17fedcb1ULL) << 13);
    acc = (acc + a1 + 0xf81b0ffaULL) ^ 0x049138ULL;
    acc ^= (acc >> 17) * 0x0004ULL;
    return acc;
}

// FDE #1632 | PC: 0x19bbb4 | FDE: 0x049150 | Size: 256 bytes
// Khung tháo gỡ #1632 | Địa chỉ PC: 0x19bbb4 | Địa chỉ FDE: 0x049150 | Kích thước: 256 bytes
//   0x19bbb4: F81B0FFA  str      x26, [sp, #-0x50]!
//   0x19bbb8: A90163F9  stp      x25, x24, [sp, #0x10]
//   0x19bbbc: A9025BF7  stp      x23, x22, [sp, #0x20]
//   0x19bbc0: A90353F5  stp      x21, x20, [sp, #0x30]
static inline uint64_t fde_func_1632_0x19bbb4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x19bbb4ULL ^ (static_cast<uint64_t>(0xf81b0ffaULL) << 13);
    acc = (acc + a1 + 0xa90163f9ULL) ^ 0x049150ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1633 | PC: 0x19bdf0 | FDE: 0x049178 | Size: 256 bytes
// Khung tháo gỡ #1633 | Địa chỉ PC: 0x19bdf0 | Địa chỉ FDE: 0x049178 | Kích thước: 256 bytes
//   0x19bdf0: D10283FF  sub      sp, sp, #0xa0
//   0x19bdf4: A9046FFC  stp      x28, x27, [sp, #0x40]
//   0x19bdf8: A90567FA  stp      x26, x25, [sp, #0x50]
//   0x19bdfc: A9065FF8  stp      x24, x23, [sp, #0x60]
static inline uint64_t fde_func_1633_0x19bdf0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x19bdf0ULL ^ (static_cast<uint64_t>(0xd10283ffULL) << 13);
    acc = (acc + a1 + 0xa9046ffcULL) ^ 0x049178ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1634 | PC: 0x19c148 | FDE: 0x0491a8 | Size: 256 bytes
// Khung tháo gỡ #1634 | Địa chỉ PC: 0x19c148 | Địa chỉ FDE: 0x0491a8 | Kích thước: 256 bytes
//   0x19c148: D10243FF  sub      sp, sp, #0x90
//   0x19c14c: A9036FFC  stp      x28, x27, [sp, #0x30]
//   0x19c150: A90467FA  stp      x26, x25, [sp, #0x40]
//   0x19c154: A9055FF8  stp      x24, x23, [sp, #0x50]
static inline uint64_t fde_func_1634_0x19c148(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x19c148ULL ^ (static_cast<uint64_t>(0xd10243ffULL) << 13);
    acc = (acc + a1 + 0xa9036ffcULL) ^ 0x0491a8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1635 | PC: 0x19ca84 | FDE: 0x0491d8 | Size: 256 bytes
// Khung tháo gỡ #1635 | Địa chỉ PC: 0x19ca84 | Địa chỉ FDE: 0x0491d8 | Kích thước: 256 bytes
//   0x19ca84: F81A0FFC  str      x28, [sp, #-0x60]!
//   0x19ca88: A9016BFB  stp      x27, x26, [sp, #0x10]
//   0x19ca8c: A90263F9  stp      x25, x24, [sp, #0x20]
//   0x19ca90: A9035BF7  stp      x23, x22, [sp, #0x30]
static inline uint64_t fde_func_1635_0x19ca84(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x19ca84ULL ^ (static_cast<uint64_t>(0xf81a0ffcULL) << 13);
    acc = (acc + a1 + 0xa9016bfbULL) ^ 0x0491d8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1636 | PC: 0x19cd0c | FDE: 0x049208 | Size: 256 bytes
// Khung tháo gỡ #1636 | Địa chỉ PC: 0x19cd0c | Địa chỉ FDE: 0x049208 | Kích thước: 256 bytes
//   0x19cd0c: D10183FF  sub      sp, sp, #0x60
//   0x19cd10: A9035BF7  stp      x23, x22, [sp, #0x30]
//   0x19cd14: A90453F5  stp      x21, x20, [sp, #0x40]
//   0x19cd18: A9057BF3  stp      x19, x30, [sp, #0x50]
static inline uint64_t fde_func_1636_0x19cd0c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x19cd0cULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xa9035bf7ULL) ^ 0x049208ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1637 | PC: 0x19ce9c | FDE: 0x049228 | Size: 256 bytes
// Khung tháo gỡ #1637 | Địa chỉ PC: 0x19ce9c | Địa chỉ FDE: 0x049228 | Kích thước: 256 bytes
//   0x19ce9c: D10183FF  sub      sp, sp, #0x60
//   0x19cea0: A9035BF7  stp      x23, x22, [sp, #0x30]
//   0x19cea4: A90453F5  stp      x21, x20, [sp, #0x40]
//   0x19cea8: A9057BF3  stp      x19, x30, [sp, #0x50]
static inline uint64_t fde_func_1637_0x19ce9c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x19ce9cULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xa9035bf7ULL) ^ 0x049228ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1638 | PC: 0x19d010 | FDE: 0x049248 | Size: 256 bytes
// Khung tháo gỡ #1638 | Địa chỉ PC: 0x19d010 | Địa chỉ FDE: 0x049248 | Kích thước: 256 bytes
//   0x19d010: D102C3FF  sub      sp, sp, #0xb0
//   0x19d014: A9056FFC  stp      x28, x27, [sp, #0x50]
//   0x19d018: A90667FA  stp      x26, x25, [sp, #0x60]
//   0x19d01c: A9075FF8  stp      x24, x23, [sp, #0x70]
static inline uint64_t fde_func_1638_0x19d010(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x19d010ULL ^ (static_cast<uint64_t>(0xd102c3ffULL) << 13);
    acc = (acc + a1 + 0xa9056ffcULL) ^ 0x049248ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1639 | PC: 0x19d74c | FDE: 0x049278 | Size: 256 bytes
// Khung tháo gỡ #1639 | Địa chỉ PC: 0x19d74c | Địa chỉ FDE: 0x049278 | Kích thước: 256 bytes
//   0x19d74c: F81E0FF4  str      x20, [sp, #-0x20]!
//   0x19d750: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x19d754: 927FF828  and      x8, x1, #0xfffffffffffffffe
//   0x19d758: AA0103F4  mov      x20, x1
static inline uint64_t fde_func_1639_0x19d74c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x19d74cULL ^ (static_cast<uint64_t>(0xf81e0ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x049278ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1640 | PC: 0x19d8c8 | FDE: 0x049298 | Size: 240 bytes
// Khung tháo gỡ #1640 | Địa chỉ PC: 0x19d8c8 | Địa chỉ FDE: 0x049298 | Kích thước: 240 bytes
//   0x19d8c8: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x19d8cc: 927FF828  and      x8, x1, #0xfffffffffffffffe
//   0x19d8d0: AA0103F3  mov      x19, x1
//   0x19d8d4: F100191F  cmp      x8, #6
static inline uint64_t fde_func_1640_0x19d8c8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x19d8c8ULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0x927ff828ULL) ^ 0x049298ULL;
    acc ^= (acc >> 17) * 0x00f0ULL;
    return acc;
}

// FDE #1641 | PC: 0x19d9b8 | FDE: 0x0492b0 | Size: 256 bytes
// Khung tháo gỡ #1641 | Địa chỉ PC: 0x19d9b8 | Địa chỉ FDE: 0x0492b0 | Kích thước: 256 bytes
//   0x19d9b8: D10103FF  sub      sp, sp, #0x40
//   0x19d9bc: A9015BF7  stp      x23, x22, [sp, #0x10]
//   0x19d9c0: A90253F5  stp      x21, x20, [sp, #0x20]
//   0x19d9c4: A9037BF3  stp      x19, x30, [sp, #0x30]
static inline uint64_t fde_func_1641_0x19d9b8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x19d9b8ULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xa9015bf7ULL) ^ 0x0492b0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1642 | PC: 0x19dccc | FDE: 0x0492d0 | Size: 256 bytes
// Khung tháo gỡ #1642 | Địa chỉ PC: 0x19dccc | Địa chỉ FDE: 0x0492d0 | Kích thước: 256 bytes
//   0x19dccc: D100C3FF  sub      sp, sp, #0x30
//   0x19dcd0: A90153F5  stp      x21, x20, [sp, #0x10]
//   0x19dcd4: A9027BF3  stp      x19, x30, [sp, #0x20]
//   0x19dcd8: AA0303F4  mov      x20, x3
static inline uint64_t fde_func_1642_0x19dccc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x19dcccULL ^ (static_cast<uint64_t>(0xd100c3ffULL) << 13);
    acc = (acc + a1 + 0xa90153f5ULL) ^ 0x0492d0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1643 | PC: 0x19def0 | FDE: 0x0492f0 | Size: 256 bytes
// Khung tháo gỡ #1643 | Địa chỉ PC: 0x19def0 | Địa chỉ FDE: 0x0492f0 | Kích thước: 256 bytes
//   0x19def0: F81D0FF6  str      x22, [sp, #-0x30]!
//   0x19def4: A90153F5  stp      x21, x20, [sp, #0x10]
//   0x19def8: A9027BF3  stp      x19, x30, [sp, #0x20]
//   0x19defc: AA0303F4  mov      x20, x3
static inline uint64_t fde_func_1643_0x19def0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x19def0ULL ^ (static_cast<uint64_t>(0xf81d0ff6ULL) << 13);
    acc = (acc + a1 + 0xa90153f5ULL) ^ 0x0492f0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1644 | PC: 0x19e1ec | FDE: 0x049310 | Size: 256 bytes
// Khung tháo gỡ #1644 | Địa chỉ PC: 0x19e1ec | Địa chỉ FDE: 0x049310 | Kích thước: 256 bytes
//   0x19e1ec: D10203FF  sub      sp, sp, #0x80
//   0x19e1f0: A9055BF7  stp      x23, x22, [sp, #0x50]
//   0x19e1f4: A90653F5  stp      x21, x20, [sp, #0x60]
//   0x19e1f8: A9077BF3  stp      x19, x30, [sp, #0x70]
static inline uint64_t fde_func_1644_0x19e1ec(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x19e1ecULL ^ (static_cast<uint64_t>(0xd10203ffULL) << 13);
    acc = (acc + a1 + 0xa9055bf7ULL) ^ 0x049310ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1645 | PC: 0x19e4f8 | FDE: 0x049338 | Size: 4 bytes
// Khung tháo gỡ #1645 | Địa chỉ PC: 0x19e4f8 | Địa chỉ FDE: 0x049338 | Kích thước: 4 bytes
//   0x19e4f8: 14000001  b        #0x19e4fc
static inline uint64_t fde_func_1645_0x19e4f8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x19e4f8ULL ^ (static_cast<uint64_t>(0x14000001ULL) << 13);
    acc = (acc + a1 + 0xa9bf7bf3ULL) ^ 0x049338ULL;
    acc ^= (acc >> 17) * 0x0004ULL;
    return acc;
}

// FDE #1646 | PC: 0x19e4fc | FDE: 0x049350 | Size: 256 bytes
// Khung tháo gỡ #1646 | Địa chỉ PC: 0x19e4fc | Địa chỉ FDE: 0x049350 | Kích thước: 256 bytes
//   0x19e4fc: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x19e500: AA0103F3  mov      x19, x1
//   0x19e504: D371FC28  lsr      x8, x1, #0x31
//   0x19e508: B6800041  tbz      x1, #0x30, #0x19e510
static inline uint64_t fde_func_1646_0x19e4fc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x19e4fcULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0xaa0103f3ULL) ^ 0x049350ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1647 | PC: 0x19e734 | FDE: 0x049368 | Size: 140 bytes
// Khung tháo gỡ #1647 | Địa chỉ PC: 0x19e734 | Địa chỉ FDE: 0x049368 | Kích thước: 140 bytes
//   0x19e734: F81E0FF4  str      x20, [sp, #-0x20]!
//   0x19e738: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x19e73c: F9400061  ldr      x1, [x3]
//   0x19e740: AA0303F4  mov      x20, x3
static inline uint64_t fde_func_1647_0x19e734(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x19e734ULL ^ (static_cast<uint64_t>(0xf81e0ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x049368ULL;
    acc ^= (acc >> 17) * 0x008cULL;
    return acc;
}

// FDE #1648 | PC: 0x19e7c0 | FDE: 0x049388 | Size: 256 bytes
// Khung tháo gỡ #1648 | Địa chỉ PC: 0x19e7c0 | Địa chỉ FDE: 0x049388 | Kích thước: 256 bytes
//   0x19e7c0: D10343FF  sub      sp, sp, #0xd0
//   0x19e7c4: A9076FFC  stp      x28, x27, [sp, #0x70]
//   0x19e7c8: A90867FA  stp      x26, x25, [sp, #0x80]
//   0x19e7cc: A9095FF8  stp      x24, x23, [sp, #0x90]
static inline uint64_t fde_func_1648_0x19e7c0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x19e7c0ULL ^ (static_cast<uint64_t>(0xd10343ffULL) << 13);
    acc = (acc + a1 + 0xa9076ffcULL) ^ 0x049388ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1649 | PC: 0x19f560 | FDE: 0x0493b8 | Size: 256 bytes
// Khung tháo gỡ #1649 | Địa chỉ PC: 0x19f560 | Địa chỉ FDE: 0x0493b8 | Kích thước: 256 bytes
//   0x19f560: D101C3FF  sub      sp, sp, #0x70
//   0x19f564: A9016FFC  stp      x28, x27, [sp, #0x10]
//   0x19f568: A90267FA  stp      x26, x25, [sp, #0x20]
//   0x19f56c: A9035FF8  stp      x24, x23, [sp, #0x30]
static inline uint64_t fde_func_1649_0x19f560(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x19f560ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xa9016ffcULL) ^ 0x0493b8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1650 | PC: 0x19f828 | FDE: 0x0493e8 | Size: 256 bytes
// Khung tháo gỡ #1650 | Địa chỉ PC: 0x19f828 | Địa chỉ FDE: 0x0493e8 | Kích thước: 256 bytes
//   0x19f828: D10203FF  sub      sp, sp, #0x80
//   0x19f82c: A9026FFC  stp      x28, x27, [sp, #0x20]
//   0x19f830: A90367FA  stp      x26, x25, [sp, #0x30]
//   0x19f834: A9045FF8  stp      x24, x23, [sp, #0x40]
static inline uint64_t fde_func_1650_0x19f828(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x19f828ULL ^ (static_cast<uint64_t>(0xd10203ffULL) << 13);
    acc = (acc + a1 + 0xa9026ffcULL) ^ 0x0493e8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1651 | PC: 0x19fe38 | FDE: 0x049418 | Size: 256 bytes
// Khung tháo gỡ #1651 | Địa chỉ PC: 0x19fe38 | Địa chỉ FDE: 0x049418 | Kích thước: 256 bytes
//   0x19fe38: D101C3FF  sub      sp, sp, #0x70
//   0x19fe3c: F9000BFC  str      x28, [sp, #0x10]
//   0x19fe40: A9026BFB  stp      x27, x26, [sp, #0x20]
//   0x19fe44: A90363F9  stp      x25, x24, [sp, #0x30]
static inline uint64_t fde_func_1651_0x19fe38(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x19fe38ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xf9000bfcULL) ^ 0x049418ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1652 | PC: 0x1a02c8 | FDE: 0x049448 | Size: 256 bytes
// Khung tháo gỡ #1652 | Địa chỉ PC: 0x1a02c8 | Địa chỉ FDE: 0x049448 | Kích thước: 256 bytes
//   0x1a02c8: D10243FF  sub      sp, sp, #0x90
//   0x1a02cc: A9036FFC  stp      x28, x27, [sp, #0x30]
//   0x1a02d0: A90467FA  stp      x26, x25, [sp, #0x40]
//   0x1a02d4: A9055FF8  stp      x24, x23, [sp, #0x50]
static inline uint64_t fde_func_1652_0x1a02c8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1a02c8ULL ^ (static_cast<uint64_t>(0xd10243ffULL) << 13);
    acc = (acc + a1 + 0xa9036ffcULL) ^ 0x049448ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1653 | PC: 0x1a0bc4 | FDE: 0x049478 | Size: 256 bytes
// Khung tháo gỡ #1653 | Địa chỉ PC: 0x1a0bc4 | Địa chỉ FDE: 0x049478 | Kích thước: 256 bytes
//   0x1a0bc4: D10203FF  sub      sp, sp, #0x80
//   0x1a0bc8: A9026FFC  stp      x28, x27, [sp, #0x20]
//   0x1a0bcc: A90367FA  stp      x26, x25, [sp, #0x30]
//   0x1a0bd0: A9045FF8  stp      x24, x23, [sp, #0x40]
static inline uint64_t fde_func_1653_0x1a0bc4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1a0bc4ULL ^ (static_cast<uint64_t>(0xd10203ffULL) << 13);
    acc = (acc + a1 + 0xa9026ffcULL) ^ 0x049478ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1654 | PC: 0x1a11bc | FDE: 0x0494a8 | Size: 256 bytes
// Khung tháo gỡ #1654 | Địa chỉ PC: 0x1a11bc | Địa chỉ FDE: 0x0494a8 | Kích thước: 256 bytes
//   0x1a11bc: D101C3FF  sub      sp, sp, #0x70
//   0x1a11c0: F9000BFC  str      x28, [sp, #0x10]
//   0x1a11c4: A9026BFB  stp      x27, x26, [sp, #0x20]
//   0x1a11c8: A90363F9  stp      x25, x24, [sp, #0x30]
static inline uint64_t fde_func_1654_0x1a11bc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1a11bcULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xf9000bfcULL) ^ 0x0494a8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1655 | PC: 0x1a1654 | FDE: 0x0494d8 | Size: 256 bytes
// Khung tháo gỡ #1655 | Địa chỉ PC: 0x1a1654 | Địa chỉ FDE: 0x0494d8 | Kích thước: 256 bytes
//   0x1a1654: D10283FF  sub      sp, sp, #0xa0
//   0x1a1658: A9046FFC  stp      x28, x27, [sp, #0x40]
//   0x1a165c: A90567FA  stp      x26, x25, [sp, #0x50]
//   0x1a1660: A9065FF8  stp      x24, x23, [sp, #0x60]
static inline uint64_t fde_func_1655_0x1a1654(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1a1654ULL ^ (static_cast<uint64_t>(0xd10283ffULL) << 13);
    acc = (acc + a1 + 0xa9046ffcULL) ^ 0x0494d8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1656 | PC: 0x1a1dd4 | FDE: 0x049508 | Size: 256 bytes
// Khung tháo gỡ #1656 | Địa chỉ PC: 0x1a1dd4 | Địa chỉ FDE: 0x049508 | Kích thước: 256 bytes
//   0x1a1dd4: F81C0FF8  str      x24, [sp, #-0x40]!
//   0x1a1dd8: A9015BF7  stp      x23, x22, [sp, #0x10]
//   0x1a1ddc: A90253F5  stp      x21, x20, [sp, #0x20]
//   0x1a1de0: A9037BF3  stp      x19, x30, [sp, #0x30]
static inline uint64_t fde_func_1656_0x1a1dd4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1a1dd4ULL ^ (static_cast<uint64_t>(0xf81c0ff8ULL) << 13);
    acc = (acc + a1 + 0xa9015bf7ULL) ^ 0x049508ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1657 | PC: 0x1a20b8 | FDE: 0x049530 | Size: 256 bytes
// Khung tháo gỡ #1657 | Địa chỉ PC: 0x1a20b8 | Địa chỉ FDE: 0x049530 | Kích thước: 256 bytes
//   0x1a20b8: D10283FF  sub      sp, sp, #0xa0
//   0x1a20bc: A9046FFC  stp      x28, x27, [sp, #0x40]
//   0x1a20c0: A90567FA  stp      x26, x25, [sp, #0x50]
//   0x1a20c4: A9065FF8  stp      x24, x23, [sp, #0x60]
static inline uint64_t fde_func_1657_0x1a20b8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1a20b8ULL ^ (static_cast<uint64_t>(0xd10283ffULL) << 13);
    acc = (acc + a1 + 0xa9046ffcULL) ^ 0x049530ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1658 | PC: 0x1a2664 | FDE: 0x049560 | Size: 256 bytes
// Khung tháo gỡ #1658 | Địa chỉ PC: 0x1a2664 | Địa chỉ FDE: 0x049560 | Kích thước: 256 bytes
//   0x1a2664: D10303FF  sub      sp, sp, #0xc0
//   0x1a2668: A9066FFC  stp      x28, x27, [sp, #0x60]
//   0x1a266c: A90767FA  stp      x26, x25, [sp, #0x70]
//   0x1a2670: A9085FF8  stp      x24, x23, [sp, #0x80]
static inline uint64_t fde_func_1658_0x1a2664(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1a2664ULL ^ (static_cast<uint64_t>(0xd10303ffULL) << 13);
    acc = (acc + a1 + 0xa9066ffcULL) ^ 0x049560ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1659 | PC: 0x1a2eb8 | FDE: 0x049590 | Size: 256 bytes
// Khung tháo gỡ #1659 | Địa chỉ PC: 0x1a2eb8 | Địa chỉ FDE: 0x049590 | Kích thước: 256 bytes
//   0x1a2eb8: D10303FF  sub      sp, sp, #0xc0
//   0x1a2ebc: A9066FFC  stp      x28, x27, [sp, #0x60]
//   0x1a2ec0: A90767FA  stp      x26, x25, [sp, #0x70]
//   0x1a2ec4: A9085FF8  stp      x24, x23, [sp, #0x80]
static inline uint64_t fde_func_1659_0x1a2eb8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1a2eb8ULL ^ (static_cast<uint64_t>(0xd10303ffULL) << 13);
    acc = (acc + a1 + 0xa9066ffcULL) ^ 0x049590ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1660 | PC: 0x1a3b40 | FDE: 0x0495c0 | Size: 256 bytes
// Khung tháo gỡ #1660 | Địa chỉ PC: 0x1a3b40 | Địa chỉ FDE: 0x0495c0 | Kích thước: 256 bytes
//   0x1a3b40: D101C3FF  sub      sp, sp, #0x70
//   0x1a3b44: A9026BFB  stp      x27, x26, [sp, #0x20]
//   0x1a3b48: A90363F9  stp      x25, x24, [sp, #0x30]
//   0x1a3b4c: A9045BF7  stp      x23, x22, [sp, #0x40]
static inline uint64_t fde_func_1660_0x1a3b40(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1a3b40ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xa9026bfbULL) ^ 0x0495c0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1661 | PC: 0x1a3ff8 | FDE: 0x0495e8 | Size: 256 bytes
// Khung tháo gỡ #1661 | Địa chỉ PC: 0x1a3ff8 | Địa chỉ FDE: 0x0495e8 | Kích thước: 256 bytes
//   0x1a3ff8: D101C3FF  sub      sp, sp, #0x70
//   0x1a3ffc: F9000BFC  str      x28, [sp, #0x10]
//   0x1a4000: A9026BFB  stp      x27, x26, [sp, #0x20]
//   0x1a4004: A90363F9  stp      x25, x24, [sp, #0x30]
static inline uint64_t fde_func_1661_0x1a3ff8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1a3ff8ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xf9000bfcULL) ^ 0x0495e8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1662 | PC: 0x1a44dc | FDE: 0x049618 | Size: 256 bytes
// Khung tháo gỡ #1662 | Địa chỉ PC: 0x1a44dc | Địa chỉ FDE: 0x049618 | Kích thước: 256 bytes
//   0x1a44dc: D102C3FF  sub      sp, sp, #0xb0
//   0x1a44e0: A9056FFC  stp      x28, x27, [sp, #0x50]
//   0x1a44e4: A90667FA  stp      x26, x25, [sp, #0x60]
//   0x1a44e8: A9075FF8  stp      x24, x23, [sp, #0x70]
static inline uint64_t fde_func_1662_0x1a44dc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1a44dcULL ^ (static_cast<uint64_t>(0xd102c3ffULL) << 13);
    acc = (acc + a1 + 0xa9056ffcULL) ^ 0x049618ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1663 | PC: 0x1a4af8 | FDE: 0x049648 | Size: 256 bytes
// Khung tháo gỡ #1663 | Địa chỉ PC: 0x1a4af8 | Địa chỉ FDE: 0x049648 | Kích thước: 256 bytes
//   0x1a4af8: D10183FF  sub      sp, sp, #0x60
//   0x1a4afc: F90013F8  str      x24, [sp, #0x20]
//   0x1a4b00: A9035BF7  stp      x23, x22, [sp, #0x30]
//   0x1a4b04: A90453F5  stp      x21, x20, [sp, #0x40]
static inline uint64_t fde_func_1663_0x1a4af8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1a4af8ULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xf90013f8ULL) ^ 0x049648ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1664 | PC: 0x1a4de0 | FDE: 0x049670 | Size: 256 bytes
// Khung tháo gỡ #1664 | Địa chỉ PC: 0x1a4de0 | Địa chỉ FDE: 0x049670 | Kích thước: 256 bytes
//   0x1a4de0: D10243FF  sub      sp, sp, #0x90
//   0x1a4de4: A90563F9  stp      x25, x24, [sp, #0x50]
//   0x1a4de8: A9065BF7  stp      x23, x22, [sp, #0x60]
//   0x1a4dec: A90753F5  stp      x21, x20, [sp, #0x70]
static inline uint64_t fde_func_1664_0x1a4de0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1a4de0ULL ^ (static_cast<uint64_t>(0xd10243ffULL) << 13);
    acc = (acc + a1 + 0xa90563f9ULL) ^ 0x049670ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1665 | PC: 0x1a5244 | FDE: 0x049698 | Size: 256 bytes
// Khung tháo gỡ #1665 | Địa chỉ PC: 0x1a5244 | Địa chỉ FDE: 0x049698 | Kích thước: 256 bytes
//   0x1a5244: D10103FF  sub      sp, sp, #0x40
//   0x1a5248: A9015BF7  stp      x23, x22, [sp, #0x10]
//   0x1a524c: A90253F5  stp      x21, x20, [sp, #0x20]
//   0x1a5250: A9037BF3  stp      x19, x30, [sp, #0x30]
static inline uint64_t fde_func_1665_0x1a5244(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1a5244ULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xa9015bf7ULL) ^ 0x049698ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1666 | PC: 0x1a53cc | FDE: 0x0496b8 | Size: 256 bytes
// Khung tháo gỡ #1666 | Địa chỉ PC: 0x1a53cc | Địa chỉ FDE: 0x0496b8 | Kích thước: 256 bytes
//   0x1a53cc: A9BD5BF7  stp      x23, x22, [sp, #-0x30]!
//   0x1a53d0: A90153F5  stp      x21, x20, [sp, #0x10]
//   0x1a53d4: A9027BF3  stp      x19, x30, [sp, #0x20]
//   0x1a53d8: AA0103F3  mov      x19, x1
static inline uint64_t fde_func_1666_0x1a53cc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1a53ccULL ^ (static_cast<uint64_t>(0xa9bd5bf7ULL) << 13);
    acc = (acc + a1 + 0xa90153f5ULL) ^ 0x0496b8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1667 | PC: 0x1a54d4 | FDE: 0x0496d8 | Size: 256 bytes
// Khung tháo gỡ #1667 | Địa chỉ PC: 0x1a54d4 | Địa chỉ FDE: 0x0496d8 | Kích thước: 256 bytes
//   0x1a54d4: D10243FF  sub      sp, sp, #0x90
//   0x1a54d8: A9036FFC  stp      x28, x27, [sp, #0x30]
//   0x1a54dc: A90467FA  stp      x26, x25, [sp, #0x40]
//   0x1a54e0: A9055FF8  stp      x24, x23, [sp, #0x50]
static inline uint64_t fde_func_1667_0x1a54d4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1a54d4ULL ^ (static_cast<uint64_t>(0xd10243ffULL) << 13);
    acc = (acc + a1 + 0xa9036ffcULL) ^ 0x0496d8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1668 | PC: 0x1a5d40 | FDE: 0x049708 | Size: 256 bytes
// Khung tháo gỡ #1668 | Địa chỉ PC: 0x1a5d40 | Địa chỉ FDE: 0x049708 | Kích thước: 256 bytes
//   0x1a5d40: A9BD5BF7  stp      x23, x22, [sp, #-0x30]!
//   0x1a5d44: A90153F5  stp      x21, x20, [sp, #0x10]
//   0x1a5d48: A9027BF3  stp      x19, x30, [sp, #0x20]
//   0x1a5d4c: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_1668_0x1a5d40(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1a5d40ULL ^ (static_cast<uint64_t>(0xa9bd5bf7ULL) << 13);
    acc = (acc + a1 + 0xa90153f5ULL) ^ 0x049708ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1669 | PC: 0x1a5ef4 | FDE: 0x049728 | Size: 52 bytes
// Khung tháo gỡ #1669 | Địa chỉ PC: 0x1a5ef4 | Địa chỉ FDE: 0x049728 | Kích thước: 52 bytes
//   0x1a5ef4: F81F0FFE  str      x30, [sp, #-0x10]!
//   0x1a5ef8: AA0103E2  mov      x2, x1
//   0x1a5efc: F9400061  ldr      x1, [x3]
//   0x1a5f00: 97FD9832  bl       #0x10bfc8
static inline uint64_t fde_func_1669_0x1a5ef4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1a5ef4ULL ^ (static_cast<uint64_t>(0xf81f0ffeULL) << 13);
    acc = (acc + a1 + 0xaa0103e2ULL) ^ 0x049728ULL;
    acc ^= (acc >> 17) * 0x0034ULL;
    return acc;
}

// FDE #1670 | PC: 0x1a5f28 | FDE: 0x049740 | Size: 256 bytes
// Khung tháo gỡ #1670 | Địa chỉ PC: 0x1a5f28 | Địa chỉ FDE: 0x049740 | Kích thước: 256 bytes
//   0x1a5f28: D101C3FF  sub      sp, sp, #0x70
//   0x1a5f2c: F9002BF4  str      x20, [sp, #0x50]
//   0x1a5f30: A9067BF3  stp      x19, x30, [sp, #0x60]
//   0x1a5f34: D53BD054  mrs      x20, tpidr_el0
static inline uint64_t fde_func_1670_0x1a5f28(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1a5f28ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xf9002bf4ULL) ^ 0x049740ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1671 | PC: 0x1a6074 | FDE: 0x049760 | Size: 16 bytes
// Khung tháo gỡ #1671 | Địa chỉ PC: 0x1a6074 | Địa chỉ FDE: 0x049760 | Kích thước: 16 bytes
//   0x1a6074: 528006C2  mov      w2, #0x36
//   0x1a6078: 2A1F03E3  mov      w3, wzr
//   0x1a607c: AA1F03E4  mov      x4, xzr
//   0x1a6080: 17FE4ADF  b        #0x138bfc
static inline uint64_t fde_func_1671_0x1a6074(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1a6074ULL ^ (static_cast<uint64_t>(0x528006c2ULL) << 13);
    acc = (acc + a1 + 0x2a1f03e3ULL) ^ 0x049760ULL;
    acc ^= (acc >> 17) * 0x0010ULL;
    return acc;
}

// FDE #1672 | PC: 0x1a6084 | FDE: 0x049778 | Size: 4 bytes
// Khung tháo gỡ #1672 | Địa chỉ PC: 0x1a6084 | Địa chỉ FDE: 0x049778 | Kích thước: 4 bytes
//   0x1a6084: 17FD46CD  b        #0xf7bb8
static inline uint64_t fde_func_1672_0x1a6084(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1a6084ULL ^ (static_cast<uint64_t>(0x17fd46cdULL) << 13);
    acc = (acc + a1 + 0xf81c0ff8ULL) ^ 0x049778ULL;
    acc ^= (acc >> 17) * 0x0004ULL;
    return acc;
}

// FDE #1673 | PC: 0x1a6088 | FDE: 0x049790 | Size: 256 bytes
// Khung tháo gỡ #1673 | Địa chỉ PC: 0x1a6088 | Địa chỉ FDE: 0x049790 | Kích thước: 256 bytes
//   0x1a6088: F81C0FF8  str      x24, [sp, #-0x40]!
//   0x1a608c: A9015BF7  stp      x23, x22, [sp, #0x10]
//   0x1a6090: A90253F5  stp      x21, x20, [sp, #0x20]
//   0x1a6094: A9037BF3  stp      x19, x30, [sp, #0x30]
static inline uint64_t fde_func_1673_0x1a6088(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1a6088ULL ^ (static_cast<uint64_t>(0xf81c0ff8ULL) << 13);
    acc = (acc + a1 + 0xa9015bf7ULL) ^ 0x049790ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1674 | PC: 0x1a6208 | FDE: 0x0497b8 | Size: 256 bytes
// Khung tháo gỡ #1674 | Địa chỉ PC: 0x1a6208 | Địa chỉ FDE: 0x0497b8 | Kích thước: 256 bytes
//   0x1a6208: D101C3FF  sub      sp, sp, #0x70
//   0x1a620c: A9016FFC  stp      x28, x27, [sp, #0x10]
//   0x1a6210: A90267FA  stp      x26, x25, [sp, #0x20]
//   0x1a6214: A9035FF8  stp      x24, x23, [sp, #0x30]
static inline uint64_t fde_func_1674_0x1a6208(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1a6208ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xa9016ffcULL) ^ 0x0497b8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1675 | PC: 0x1a6488 | FDE: 0x0497e8 | Size: 256 bytes
// Khung tháo gỡ #1675 | Địa chỉ PC: 0x1a6488 | Địa chỉ FDE: 0x0497e8 | Kích thước: 256 bytes
//   0x1a6488: D101C3FF  sub      sp, sp, #0x70
//   0x1a648c: F9001BF8  str      x24, [sp, #0x30]
//   0x1a6490: A9045BF7  stp      x23, x22, [sp, #0x40]
//   0x1a6494: A90553F5  stp      x21, x20, [sp, #0x50]
static inline uint64_t fde_func_1675_0x1a6488(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1a6488ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xf9001bf8ULL) ^ 0x0497e8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1676 | PC: 0x1a65f4 | FDE: 0x049810 | Size: 256 bytes
// Khung tháo gỡ #1676 | Địa chỉ PC: 0x1a65f4 | Địa chỉ FDE: 0x049810 | Kích thước: 256 bytes
//   0x1a65f4: A9BD5BF7  stp      x23, x22, [sp, #-0x30]!
//   0x1a65f8: A90153F5  stp      x21, x20, [sp, #0x10]
//   0x1a65fc: A9027BF3  stp      x19, x30, [sp, #0x20]
//   0x1a6600: AA0003F4  mov      x20, x0
static inline uint64_t fde_func_1676_0x1a65f4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1a65f4ULL ^ (static_cast<uint64_t>(0xa9bd5bf7ULL) << 13);
    acc = (acc + a1 + 0xa90153f5ULL) ^ 0x049810ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1677 | PC: 0x1a6738 | FDE: 0x049830 | Size: 124 bytes
// Khung tháo gỡ #1677 | Địa chỉ PC: 0x1a6738 | Địa chỉ FDE: 0x049830 | Kích thước: 124 bytes
//   0x1a6738: F81F0FFE  str      x30, [sp, #-0x10]!
//   0x1a673c: B27C0028  orr      x8, x1, #0x10
//   0x1a6740: F100491F  cmp      x8, #0x12
//   0x1a6744: 540000E1  b.ne     #0x1a6760
static inline uint64_t fde_func_1677_0x1a6738(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1a6738ULL ^ (static_cast<uint64_t>(0xf81f0ffeULL) << 13);
    acc = (acc + a1 + 0xb27c0028ULL) ^ 0x049830ULL;
    acc ^= (acc >> 17) * 0x007cULL;
    return acc;
}

// FDE #1678 | PC: 0x1a67b4 | FDE: 0x049848 | Size: 256 bytes
// Khung tháo gỡ #1678 | Địa chỉ PC: 0x1a67b4 | Địa chỉ FDE: 0x049848 | Kích thước: 256 bytes
//   0x1a67b4: F81C0FF8  str      x24, [sp, #-0x40]!
//   0x1a67b8: A9015BF7  stp      x23, x22, [sp, #0x10]
//   0x1a67bc: A90253F5  stp      x21, x20, [sp, #0x20]
//   0x1a67c0: A9037BF3  stp      x19, x30, [sp, #0x30]
static inline uint64_t fde_func_1678_0x1a67b4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1a67b4ULL ^ (static_cast<uint64_t>(0xf81c0ff8ULL) << 13);
    acc = (acc + a1 + 0xa9015bf7ULL) ^ 0x049848ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1679 | PC: 0x1a69e4 | FDE: 0x049870 | Size: 256 bytes
// Khung tháo gỡ #1679 | Địa chỉ PC: 0x1a69e4 | Địa chỉ FDE: 0x049870 | Kích thước: 256 bytes
//   0x1a69e4: D101C3FF  sub      sp, sp, #0x70
//   0x1a69e8: A90363F9  stp      x25, x24, [sp, #0x30]
//   0x1a69ec: A9045BF7  stp      x23, x22, [sp, #0x40]
//   0x1a69f0: A90553F5  stp      x21, x20, [sp, #0x50]
static inline uint64_t fde_func_1679_0x1a69e4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1a69e4ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xa90363f9ULL) ^ 0x049870ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1680 | PC: 0x1a6c0c | FDE: 0x049898 | Size: 256 bytes
// Khung tháo gỡ #1680 | Địa chỉ PC: 0x1a6c0c | Địa chỉ FDE: 0x049898 | Kích thước: 256 bytes
//   0x1a6c0c: A9BE53F5  stp      x21, x20, [sp, #-0x20]!
//   0x1a6c10: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x1a6c14: F9400061  ldr      x1, [x3]
//   0x1a6c18: D2800048  mov      x8, #2
static inline uint64_t fde_func_1680_0x1a6c0c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1a6c0cULL ^ (static_cast<uint64_t>(0xa9be53f5ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x049898ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1681 | PC: 0x1a6d48 | FDE: 0x0498b8 | Size: 180 bytes
// Khung tháo gỡ #1681 | Địa chỉ PC: 0x1a6d48 | Địa chỉ FDE: 0x0498b8 | Kích thước: 180 bytes
//   0x1a6d48: F81E0FF4  str      x20, [sp, #-0x20]!
//   0x1a6d4c: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x1a6d50: A9400873  ldp      x19, x2, [x3]
//   0x1a6d54: 52800023  mov      w3, #1
static inline uint64_t fde_func_1681_0x1a6d48(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1a6d48ULL ^ (static_cast<uint64_t>(0xf81e0ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x0498b8ULL;
    acc ^= (acc >> 17) * 0x00b4ULL;
    return acc;
}

// FDE #1682 | PC: 0x1a6dfc | FDE: 0x0498d8 | Size: 256 bytes
// Khung tháo gỡ #1682 | Địa chỉ PC: 0x1a6dfc | Địa chỉ FDE: 0x0498d8 | Kích thước: 256 bytes
//   0x1a6dfc: A9BD5BF7  stp      x23, x22, [sp, #-0x30]!
//   0x1a6e00: A90153F5  stp      x21, x20, [sp, #0x10]
//   0x1a6e04: A9027BF3  stp      x19, x30, [sp, #0x20]
//   0x1a6e08: F9400061  ldr      x1, [x3]
static inline uint64_t fde_func_1682_0x1a6dfc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1a6dfcULL ^ (static_cast<uint64_t>(0xa9bd5bf7ULL) << 13);
    acc = (acc + a1 + 0xa90153f5ULL) ^ 0x0498d8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1683 | PC: 0x1a6f14 | FDE: 0x0498f8 | Size: 16 bytes
// Khung tháo gỡ #1683 | Địa chỉ PC: 0x1a6f14 | Địa chỉ FDE: 0x0498f8 | Kích thước: 16 bytes
//   0x1a6f14: F9400061  ldr      x1, [x3]
//   0x1a6f18: 52800022  mov      w2, #1
//   0x1a6f1c: 2A1F03E3  mov      w3, wzr
//   0x1a6f20: 17FEB250  b        #0x153860
static inline uint64_t fde_func_1683_0x1a6f14(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1a6f14ULL ^ (static_cast<uint64_t>(0xf9400061ULL) << 13);
    acc = (acc + a1 + 0x52800022ULL) ^ 0x0498f8ULL;
    acc ^= (acc >> 17) * 0x0010ULL;
    return acc;
}

// FDE #1684 | PC: 0x1a6f24 | FDE: 0x049910 | Size: 16 bytes
// Khung tháo gỡ #1684 | Địa chỉ PC: 0x1a6f24 | Địa chỉ FDE: 0x049910 | Kích thước: 16 bytes
//   0x1a6f24: F9400061  ldr      x1, [x3]
//   0x1a6f28: 52800042  mov      w2, #2
//   0x1a6f2c: 2A1F03E3  mov      w3, wzr
//   0x1a6f30: 17FEB24C  b        #0x153860
static inline uint64_t fde_func_1684_0x1a6f24(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1a6f24ULL ^ (static_cast<uint64_t>(0xf9400061ULL) << 13);
    acc = (acc + a1 + 0x52800042ULL) ^ 0x049910ULL;
    acc ^= (acc >> 17) * 0x0010ULL;
    return acc;
}

// FDE #1685 | PC: 0x1a6f34 | FDE: 0x049928 | Size: 16 bytes
// Khung tháo gỡ #1685 | Địa chỉ PC: 0x1a6f34 | Địa chỉ FDE: 0x049928 | Kích thước: 16 bytes
//   0x1a6f34: F9400061  ldr      x1, [x3]
//   0x1a6f38: 52800222  mov      w2, #0x11
//   0x1a6f3c: 2A0403E3  mov      w3, w4
//   0x1a6f40: 17FEB248  b        #0x153860
static inline uint64_t fde_func_1685_0x1a6f34(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1a6f34ULL ^ (static_cast<uint64_t>(0xf9400061ULL) << 13);
    acc = (acc + a1 + 0x52800222ULL) ^ 0x049928ULL;
    acc ^= (acc >> 17) * 0x0010ULL;
    return acc;
}

// FDE #1686 | PC: 0x1a6f44 | FDE: 0x049940 | Size: 256 bytes
// Khung tháo gỡ #1686 | Địa chỉ PC: 0x1a6f44 | Địa chỉ FDE: 0x049940 | Kích thước: 256 bytes
//   0x1a6f44: D10243FF  sub      sp, sp, #0x90
//   0x1a6f48: A9036FFC  stp      x28, x27, [sp, #0x30]
//   0x1a6f4c: A90467FA  stp      x26, x25, [sp, #0x40]
//   0x1a6f50: A9055FF8  stp      x24, x23, [sp, #0x50]
static inline uint64_t fde_func_1686_0x1a6f44(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1a6f44ULL ^ (static_cast<uint64_t>(0xd10243ffULL) << 13);
    acc = (acc + a1 + 0xa9036ffcULL) ^ 0x049940ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1687 | PC: 0x1a73f8 | FDE: 0x049970 | Size: 256 bytes
// Khung tháo gỡ #1687 | Địa chỉ PC: 0x1a73f8 | Địa chỉ FDE: 0x049970 | Kích thước: 256 bytes
//   0x1a73f8: A9BD5BF7  stp      x23, x22, [sp, #-0x30]!
//   0x1a73fc: A90153F5  stp      x21, x20, [sp, #0x10]
//   0x1a7400: A9027BF3  stp      x19, x30, [sp, #0x20]
//   0x1a7404: A9405474  ldp      x20, x21, [x3]
static inline uint64_t fde_func_1687_0x1a73f8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1a73f8ULL ^ (static_cast<uint64_t>(0xa9bd5bf7ULL) << 13);
    acc = (acc + a1 + 0xa90153f5ULL) ^ 0x049970ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1688 | PC: 0x1a7524 | FDE: 0x049990 | Size: 256 bytes
// Khung tháo gỡ #1688 | Địa chỉ PC: 0x1a7524 | Địa chỉ FDE: 0x049990 | Kích thước: 256 bytes
//   0x1a7524: A9BA6FFC  stp      x28, x27, [sp, #-0x60]!
//   0x1a7528: A90167FA  stp      x26, x25, [sp, #0x10]
//   0x1a752c: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x1a7530: A90357F6  stp      x22, x21, [sp, #0x30]
static inline uint64_t fde_func_1688_0x1a7524(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1a7524ULL ^ (static_cast<uint64_t>(0xa9ba6ffcULL) << 13);
    acc = (acc + a1 + 0xa90167faULL) ^ 0x049990ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1689 | PC: 0x1a78ac | FDE: 0x0499c0 | Size: 256 bytes
// Khung tháo gỡ #1689 | Địa chỉ PC: 0x1a78ac | Địa chỉ FDE: 0x0499c0 | Kích thước: 256 bytes
//   0x1a78ac: D10283FF  sub      sp, sp, #0xa0
//   0x1a78b0: A9046FFC  stp      x28, x27, [sp, #0x40]
//   0x1a78b4: A90567FA  stp      x26, x25, [sp, #0x50]
//   0x1a78b8: A9065FF8  stp      x24, x23, [sp, #0x60]
static inline uint64_t fde_func_1689_0x1a78ac(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1a78acULL ^ (static_cast<uint64_t>(0xd10283ffULL) << 13);
    acc = (acc + a1 + 0xa9046ffcULL) ^ 0x0499c0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1690 | PC: 0x1a7aec | FDE: 0x0499f0 | Size: 256 bytes
// Khung tháo gỡ #1690 | Địa chỉ PC: 0x1a7aec | Địa chỉ FDE: 0x0499f0 | Kích thước: 256 bytes
//   0x1a7aec: D101C3FF  sub      sp, sp, #0x70
//   0x1a7af0: F9002BF4  str      x20, [sp, #0x50]
//   0x1a7af4: A9067BF3  stp      x19, x30, [sp, #0x60]
//   0x1a7af8: D53BD054  mrs      x20, tpidr_el0
static inline uint64_t fde_func_1690_0x1a7aec(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1a7aecULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xf9002bf4ULL) ^ 0x0499f0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1691 | PC: 0x1a7d14 | FDE: 0x049a10 | Size: 256 bytes
// Khung tháo gỡ #1691 | Địa chỉ PC: 0x1a7d14 | Địa chỉ FDE: 0x049a10 | Kích thước: 256 bytes
//   0x1a7d14: D101C3FF  sub      sp, sp, #0x70
//   0x1a7d18: A9016FFC  stp      x28, x27, [sp, #0x10]
//   0x1a7d1c: A90267FA  stp      x26, x25, [sp, #0x20]
//   0x1a7d20: A9035FF8  stp      x24, x23, [sp, #0x30]
static inline uint64_t fde_func_1691_0x1a7d14(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1a7d14ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xa9016ffcULL) ^ 0x049a10ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1692 | PC: 0x1a83f4 | FDE: 0x049a40 | Size: 256 bytes
// Khung tháo gỡ #1692 | Địa chỉ PC: 0x1a83f4 | Địa chỉ FDE: 0x049a40 | Kích thước: 256 bytes
//   0x1a83f4: D10243FF  sub      sp, sp, #0x90
//   0x1a83f8: A9036FFC  stp      x28, x27, [sp, #0x30]
//   0x1a83fc: A90467FA  stp      x26, x25, [sp, #0x40]
//   0x1a8400: A9055FF8  stp      x24, x23, [sp, #0x50]
static inline uint64_t fde_func_1692_0x1a83f4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1a83f4ULL ^ (static_cast<uint64_t>(0xd10243ffULL) << 13);
    acc = (acc + a1 + 0xa9036ffcULL) ^ 0x049a40ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1693 | PC: 0x1a8734 | FDE: 0x049a70 | Size: 8 bytes [LEPUS_GetContextOpaque]
// Khung tháo gỡ #1693 | Địa chỉ PC: 0x1a8734 | Địa chỉ FDE: 0x049a70 | Kích thước: 8 bytes
//   0x1a8734: F9408400  ldr      x0, [x0, #0x108]
//   0x1a8738: D65F03C0  ret      
static inline uint64_t fde_func_1693_0x1a8734(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1a8734ULL ^ (static_cast<uint64_t>(0xf9408400ULL) << 13);
    acc = (acc + a1 + 0xd65f03c0ULL) ^ 0x049a70ULL;
    acc ^= (acc >> 17) * 0x0008ULL;
    return acc;
}

// FDE #1694 | PC: 0x1a873c | FDE: 0x049a88 | Size: 8 bytes [LEPUS_SetContextOpaque]
// Khung tháo gỡ #1694 | Địa chỉ PC: 0x1a873c | Địa chỉ FDE: 0x049a88 | Kích thước: 8 bytes
//   0x1a873c: F9008401  str      x1, [x0, #0x108]
//   0x1a8740: D65F03C0  ret      
static inline uint64_t fde_func_1694_0x1a873c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1a873cULL ^ (static_cast<uint64_t>(0xf9008401ULL) << 13);
    acc = (acc + a1 + 0xd65f03c0ULL) ^ 0x049a88ULL;
    acc ^= (acc >> 17) * 0x0008ULL;
    return acc;
}

// FDE #1695 | PC: 0x1a8744 | FDE: 0x049aa0 | Size: 208 bytes [LEPUS_SetClassProto]
// Khung tháo gỡ #1695 | Địa chỉ PC: 0x1a8744 | Địa chỉ FDE: 0x049aa0 | Kích thước: 208 bytes
//   0x1a8744: A9BE53F5  stp      x21, x20, [sp, #-0x20]!
//   0x1a8748: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x1a874c: 3945800A  ldrb     w10, [x0, #0x160]
//   0x1a8750: F9401C09  ldr      x9, [x0, #0x38]
static inline uint64_t fde_func_1695_0x1a8744(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1a8744ULL ^ (static_cast<uint64_t>(0xa9be53f5ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x049aa0ULL;
    acc ^= (acc >> 17) * 0x00d0ULL;
    return acc;
}

// FDE #1696 | PC: 0x1a8814 | FDE: 0x049ac0 | Size: 152 bytes [LEPUS_GetClassProto]
// Khung tháo gỡ #1696 | Địa chỉ PC: 0x1a8814 | Địa chỉ FDE: 0x049ac0 | Kích thước: 152 bytes
//   0x1a8814: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x1a8818: F9401C08  ldr      x8, [x0, #0x38]
//   0x1a881c: 39458009  ldrb     w9, [x0, #0x160]
//   0x1a8820: F8615913  ldr      x19, [x8, w1, uxtw #3]
static inline uint64_t fde_func_1696_0x1a8814(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1a8814ULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0xf9401c08ULL) ^ 0x049ac0ULL;
    acc ^= (acc >> 17) * 0x0098ULL;
    return acc;
}

// FDE #1697 | PC: 0x1a88ac | FDE: 0x049ad8 | Size: 8 bytes [LEPUS_GetRuntime]
// Khung tháo gỡ #1697 | Địa chỉ PC: 0x1a88ac | Địa chỉ FDE: 0x049ad8 | Kích thước: 8 bytes
//   0x1a88ac: F9400800  ldr      x0, [x0, #0x10]
//   0x1a88b0: D65F03C0  ret      
static inline uint64_t fde_func_1697_0x1a88ac(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1a88acULL ^ (static_cast<uint64_t>(0xf9400800ULL) << 13);
    acc = (acc + a1 + 0xd65f03c0ULL) ^ 0x049ad8ULL;
    acc ^= (acc >> 17) * 0x0008ULL;
    return acc;
}

// FDE #1698 | PC: 0x1a88b4 | FDE: 0x049af0 | Size: 12 bytes [LEPUS_SetMaxStackSize]
// Khung tháo gỡ #1698 | Địa chỉ PC: 0x1a88b4 | Địa chỉ FDE: 0x049af0 | Kích thước: 12 bytes
//   0x1a88b4: F9400808  ldr      x8, [x0, #0x10]
//   0x1a88b8: F9006D01  str      x1, [x8, #0xd8]
//   0x1a88bc: D65F03C0  ret      
static inline uint64_t fde_func_1698_0x1a88b4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1a88b4ULL ^ (static_cast<uint64_t>(0xf9400808ULL) << 13);
    acc = (acc + a1 + 0xf9006d01ULL) ^ 0x049af0ULL;
    acc ^= (acc >> 17) * 0x000cULL;
    return acc;
}

// FDE #1699 | PC: 0x1a88c0 | FDE: 0x049b08 | Size: 52 bytes [LEPUS_NewInt64]
// Khung tháo gỡ #1699 | Địa chỉ PC: 0x1a88c0 | Địa chỉ FDE: 0x049b08 | Kích thước: 52 bytes
//   0x1a88c0: 39458009  ldrb     w9, [x0, #0x160]
//   0x1a88c4: 52B00008  mov      w8, #-0xffffffff80000000
//   0x1a88c8: 8B080028  add      x8, x1, x8
//   0x1a88cc: D360FD08  lsr      x8, x8, #0x20
static inline uint64_t fde_func_1699_0x1a88c0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1a88c0ULL ^ (static_cast<uint64_t>(0x39458009ULL) << 13);
    acc = (acc + a1 + 0x52b00008ULL) ^ 0x049b08ULL;
    acc ^= (acc >> 17) * 0x0034ULL;
    return acc;
}

// FDE #1700 | PC: 0x1a88f4 | FDE: 0x049b20 | Size: 176 bytes [_Z21__JS_NewAtomInit_NOGCP12LEPUSRuntimePKciii]
// Khung tháo gỡ #1700 | Địa chỉ PC: 0x1a88f4 | Địa chỉ FDE: 0x049b20 | Kích thước: 176 bytes
//   0x1a88f4: F81C0FF8  str      x24, [sp, #-0x40]!
//   0x1a88f8: A9015BF7  stp      x23, x22, [sp, #0x10]
//   0x1a88fc: A90253F5  stp      x21, x20, [sp, #0x20]
//   0x1a8900: A9037BF3  stp      x19, x30, [sp, #0x30]
static inline uint64_t fde_func_1700_0x1a88f4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1a88f4ULL ^ (static_cast<uint64_t>(0xf81c0ff8ULL) << 13);
    acc = (acc + a1 + 0xa9015bf7ULL) ^ 0x049b20ULL;
    acc ^= (acc >> 17) * 0x00b0ULL;
    return acc;
}

// FDE #1701 | PC: 0x1a89a4 | FDE: 0x049b48 | Size: 40 bytes [LEPUS_DupAtom]
// Khung tháo gỡ #1701 | Địa chỉ PC: 0x1a89a4 | Địa chỉ FDE: 0x049b48 | Kích thước: 40 bytes
//   0x1a89a4: 71032C3F  cmp      w1, #0xcb
//   0x1a89a8: 540000EB  b.lt     #0x1a89c4
//   0x1a89ac: F9400808  ldr      x8, [x0, #0x10]
//   0x1a89b0: F9402108  ldr      x8, [x8, #0x40]
static inline uint64_t fde_func_1701_0x1a89a4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1a89a4ULL ^ (static_cast<uint64_t>(0x71032c3fULL) << 13);
    acc = (acc + a1 + 0x540000ebULL) ^ 0x049b48ULL;
    acc ^= (acc >> 17) * 0x0028ULL;
    return acc;
}

// FDE #1702 | PC: 0x1a89cc | FDE: 0x049b60 | Size: 48 bytes [LEPUS_NewAtom]
// Khung tháo gỡ #1702 | Địa chỉ PC: 0x1a89cc | Địa chỉ FDE: 0x049b60 | Kích thước: 48 bytes
//   0x1a89cc: F81E0FF4  str      x20, [sp, #-0x20]!
//   0x1a89d0: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x1a89d4: AA0003F4  mov      x20, x0
//   0x1a89d8: AA0103E0  mov      x0, x1
static inline uint64_t fde_func_1702_0x1a89cc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1a89ccULL ^ (static_cast<uint64_t>(0xf81e0ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x049b60ULL;
    acc ^= (acc >> 17) * 0x0030ULL;
    return acc;
}

// FDE #1703 | PC: 0x1a89fc | FDE: 0x049b80 | Size: 84 bytes [LEPUS_NewString]
// Khung tháo gỡ #1703 | Địa chỉ PC: 0x1a89fc | Địa chỉ FDE: 0x049b80 | Kích thước: 84 bytes
//   0x1a89fc: F81E0FF4  str      x20, [sp, #-0x20]!
//   0x1a8a00: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x1a8a04: 39458008  ldrb     w8, [x0, #0x160]
//   0x1a8a08: AA0003F4  mov      x20, x0
static inline uint64_t fde_func_1703_0x1a89fc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1a89fcULL ^ (static_cast<uint64_t>(0xf81e0ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x049b80ULL;
    acc ^= (acc >> 17) * 0x0054ULL;
    return acc;
}

// FDE #1704 | PC: 0x1a8a50 | FDE: 0x049ba0 | Size: 228 bytes [LEPUS_AtomToValue]
// Khung tháo gỡ #1704 | Địa chỉ PC: 0x1a8a50 | Địa chỉ FDE: 0x049ba0 | Kích thước: 228 bytes
//   0x1a8a50: D101C3FF  sub      sp, sp, #0x70
//   0x1a8a54: F9002BF4  str      x20, [sp, #0x50]
//   0x1a8a58: A9067BF3  stp      x19, x30, [sp, #0x60]
//   0x1a8a5c: D53BD054  mrs      x20, tpidr_el0
static inline uint64_t fde_func_1704_0x1a8a50(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1a8a50ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xf9002bf4ULL) ^ 0x049ba0ULL;
    acc ^= (acc >> 17) * 0x00e4ULL;
    return acc;
}

// FDE #1705 | PC: 0x1a8b34 | FDE: 0x049bc0 | Size: 216 bytes [LEPUS_AtomToString]
// Khung tháo gỡ #1705 | Địa chỉ PC: 0x1a8b34 | Địa chỉ FDE: 0x049bc0 | Kích thước: 216 bytes
//   0x1a8b34: D101C3FF  sub      sp, sp, #0x70
//   0x1a8b38: F9002BF4  str      x20, [sp, #0x50]
//   0x1a8b3c: A9067BF3  stp      x19, x30, [sp, #0x60]
//   0x1a8b40: D53BD054  mrs      x20, tpidr_el0
static inline uint64_t fde_func_1705_0x1a8b34(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1a8b34ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xf9002bf4ULL) ^ 0x049bc0ULL;
    acc ^= (acc >> 17) * 0x00d8ULL;
    return acc;
}

// FDE #1706 | PC: 0x1a8c0c | FDE: 0x049be0 | Size: 52 bytes [LEPUS_NewClassID]
// Khung tháo gỡ #1706 | Địa chỉ PC: 0x1a8c0c | Địa chỉ FDE: 0x049be0 | Kích thước: 52 bytes
//   0x1a8c0c: B9400008  ldr      w8, [x0]
//   0x1a8c10: 34000068  cbz      w8, #0x1a8c1c
//   0x1a8c14: 2A0803E0  mov      w0, w8
//   0x1a8c18: D65F03C0  ret      
static inline uint64_t fde_func_1706_0x1a8c0c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1a8c0cULL ^ (static_cast<uint64_t>(0xb9400008ULL) << 13);
    acc = (acc + a1 + 0x34000068ULL) ^ 0x049be0ULL;
    acc ^= (acc >> 17) * 0x0034ULL;
    return acc;
}

// FDE #1707 | PC: 0x1a8c40 | FDE: 0x049bf8 | Size: 48 bytes [LEPUS_IsRegisteredClass]
// Khung tháo gỡ #1707 | Địa chỉ PC: 0x1a8c40 | Địa chỉ FDE: 0x049bf8 | Kích thước: 48 bytes
//   0x1a8c40: B9404C08  ldr      w8, [x0, #0x4c]
//   0x1a8c44: 6B01011F  cmp      w8, w1
//   0x1a8c48: 54000109  b.ls     #0x1a8c68
//   0x1a8c4c: F9402808  ldr      x8, [x0, #0x50]
static inline uint64_t fde_func_1707_0x1a8c40(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1a8c40ULL ^ (static_cast<uint64_t>(0xb9404c08ULL) << 13);
    acc = (acc + a1 + 0x6b01011fULL) ^ 0x049bf8ULL;
    acc ^= (acc >> 17) * 0x0030ULL;
    return acc;
}

// FDE #1708 | PC: 0x1a8c70 | FDE: 0x049c10 | Size: 256 bytes [LEPUS_NewClass]
// Khung tháo gỡ #1708 | Địa chỉ PC: 0x1a8c70 | Địa chỉ FDE: 0x049c10 | Kích thước: 256 bytes
//   0x1a8c70: A9BA6FFC  stp      x28, x27, [sp, #-0x60]!
//   0x1a8c74: A90167FA  stp      x26, x25, [sp, #0x10]
//   0x1a8c78: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x1a8c7c: A90357F6  stp      x22, x21, [sp, #0x30]
static inline uint64_t fde_func_1708_0x1a8c70(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1a8c70ULL ^ (static_cast<uint64_t>(0xa9ba6ffcULL) << 13);
    acc = (acc + a1 + 0xa90167faULL) ^ 0x049c10ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1709 | PC: 0x1a8e58 | FDE: 0x049c40 | Size: 16 bytes [LEPUS_ToCStringLen2]
// Khung tháo gỡ #1709 | Địa chỉ PC: 0x1a8e58 | Địa chỉ FDE: 0x049c40 | Kích thước: 16 bytes
//   0x1a8e58: 39458008  ldrb     w8, [x0, #0x160]
//   0x1a8e5c: 34000048  cbz      w8, #0x1a8e64
//   0x1a8e60: 17FB65B8  b        #0x82540
//   0x1a8e64: 17FD86BF  b        #0x10a960
static inline uint64_t fde_func_1709_0x1a8e58(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1a8e58ULL ^ (static_cast<uint64_t>(0x39458008ULL) << 13);
    acc = (acc + a1 + 0x34000048ULL) ^ 0x049c40ULL;
    acc ^= (acc >> 17) * 0x0010ULL;
    return acc;
}

// FDE #1710 | PC: 0x1a8e68 | FDE: 0x049c58 | Size: 108 bytes [LEPUS_FreeCString]
// Khung tháo gỡ #1710 | Địa chỉ PC: 0x1a8e68 | Địa chỉ FDE: 0x049c58 | Kích thước: 108 bytes
//   0x1a8e68: A9BE53F5  stp      x21, x20, [sp, #-0x20]!
//   0x1a8e6c: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x1a8e70: B40002C1  cbz      x1, #0x1a8ec8
//   0x1a8e74: B00000A9  adrp     x9, #0x1bd000
static inline uint64_t fde_func_1710_0x1a8e68(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1a8e68ULL ^ (static_cast<uint64_t>(0xa9be53f5ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x049c58ULL;
    acc ^= (acc >> 17) * 0x006cULL;
    return acc;
}

// FDE #1711 | PC: 0x1a8ed4 | FDE: 0x049c78 | Size: 160 bytes [JS_GetSeparableStringContent]
// Khung tháo gỡ #1711 | Địa chỉ PC: 0x1a8ed4 | Địa chỉ FDE: 0x049c78 | Kích thước: 160 bytes
//   0x1a8ed4: F81E0FF4  str      x20, [sp, #-0x20]!
//   0x1a8ed8: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x1a8edc: AA0003F3  mov      x19, x0
//   0x1a8ee0: 97FD8EE4  bl       #0x10ca70
static inline uint64_t fde_func_1711_0x1a8ed4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1a8ed4ULL ^ (static_cast<uint64_t>(0xf81e0ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x049c78ULL;
    acc ^= (acc >> 17) * 0x00a0ULL;
    return acc;
}

// FDE #1712 | PC: 0x1a8f74 | FDE: 0x049c98 | Size: 256 bytes [LEPUS_NewObjectProtoClass]
// Khung tháo gỡ #1712 | Địa chỉ PC: 0x1a8f74 | Địa chỉ FDE: 0x049c98 | Kích thước: 256 bytes
//   0x1a8f74: F81E0FF4  str      x20, [sp, #-0x20]!
//   0x1a8f78: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x1a8f7c: 39458009  ldrb     w9, [x0, #0x160]
//   0x1a8f80: 2A0203F3  mov      w19, w2
static inline uint64_t fde_func_1712_0x1a8f74(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1a8f74ULL ^ (static_cast<uint64_t>(0xf81e0ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x049c98ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1713 | PC: 0x1a9080 | FDE: 0x049cb8 | Size: 32 bytes [LEPUS_NewObjectClass]
// Khung tháo gỡ #1713 | Địa chỉ PC: 0x1a9080 | Địa chỉ FDE: 0x049cb8 | Kích thước: 32 bytes
//   0x1a9080: 39458008  ldrb     w8, [x0, #0x160]
//   0x1a9084: 2A0103E2  mov      w2, w1
//   0x1a9088: 34000068  cbz      w8, #0x1a9094
//   0x1a908c: 2A0203E1  mov      w1, w2
static inline uint64_t fde_func_1713_0x1a9080(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1a9080ULL ^ (static_cast<uint64_t>(0x39458008ULL) << 13);
    acc = (acc + a1 + 0x2a0103e2ULL) ^ 0x049cb8ULL;
    acc ^= (acc >> 17) * 0x0020ULL;
    return acc;
}

// FDE #1714 | PC: 0x1a90a0 | FDE: 0x049cd0 | Size: 20 bytes [LEPUS_NewObjectProto]
// Khung tháo gỡ #1714 | Địa chỉ PC: 0x1a90a0 | Địa chỉ FDE: 0x049cd0 | Kích thước: 20 bytes
//   0x1a90a0: 39458008  ldrb     w8, [x0, #0x160]
//   0x1a90a4: 34000048  cbz      w8, #0x1a90ac
//   0x1a90a8: 17FB963C  b        #0x8e998
//   0x1a90ac: 52800022  mov      w2, #1
static inline uint64_t fde_func_1714_0x1a90a0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1a90a0ULL ^ (static_cast<uint64_t>(0x39458008ULL) << 13);
    acc = (acc + a1 + 0x34000048ULL) ^ 0x049cd0ULL;
    acc ^= (acc >> 17) * 0x0014ULL;
    return acc;
}

// FDE #1715 | PC: 0x1a90b4 | FDE: 0x049ce8 | Size: 36 bytes [LEPUS_NewArray]
// Khung tháo gỡ #1715 | Địa chỉ PC: 0x1a90b4 | Địa chỉ FDE: 0x049ce8 | Kích thước: 36 bytes
//   0x1a90b4: F9401801  ldr      x1, [x0, #0x30]
//   0x1a90b8: 39458009  ldrb     w9, [x0, #0x160]
//   0x1a90bc: 52800042  mov      w2, #2
//   0x1a90c0: B9400028  ldr      w8, [x1]
static inline uint64_t fde_func_1715_0x1a90b4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1a90b4ULL ^ (static_cast<uint64_t>(0xf9401801ULL) << 13);
    acc = (acc + a1 + 0x39458009ULL) ^ 0x049ce8ULL;
    acc ^= (acc >> 17) * 0x0024ULL;
    return acc;
}

// FDE #1716 | PC: 0x1a90d8 | FDE: 0x049d00 | Size: 28 bytes [LEPUS_NewObject]
// Khung tháo gỡ #1716 | Địa chỉ PC: 0x1a90d8 | Địa chỉ FDE: 0x049d00 | Kích thước: 28 bytes
//   0x1a90d8: 39458008  ldrb     w8, [x0, #0x160]
//   0x1a90dc: 34000048  cbz      w8, #0x1a90e4
//   0x1a90e0: 17FB760C  b        #0x86910
//   0x1a90e4: F9401C08  ldr      x8, [x0, #0x38]
static inline uint64_t fde_func_1716_0x1a90d8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1a90d8ULL ^ (static_cast<uint64_t>(0x39458008ULL) << 13);
    acc = (acc + a1 + 0x34000048ULL) ^ 0x049d00ULL;
    acc ^= (acc >> 17) * 0x001cULL;
    return acc;
}

// FDE #1717 | PC: 0x1a90f4 | FDE: 0x049d18 | Size: 56 bytes [lepus_class_has_bytecode]
// Khung tháo gỡ #1717 | Địa chỉ PC: 0x1a90f4 | Địa chỉ FDE: 0x049d18 | Kích thước: 56 bytes
//   0x1a90f4: 7100C01F  cmp      w0, #0x30
//   0x1a90f8: 54000148  b.hi     #0x1a9120
//   0x1a90fc: 2A0003E8  mov      w8, w0
//   0x1a9100: 52800029  mov      w9, #1
static inline uint64_t fde_func_1717_0x1a90f4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1a90f4ULL ^ (static_cast<uint64_t>(0x7100c01fULL) << 13);
    acc = (acc + a1 + 0x54000148ULL) ^ 0x049d18ULL;
    acc ^= (acc >> 17) * 0x0038ULL;
    return acc;
}

// FDE #1718 | PC: 0x1a912c | FDE: 0x049d30 | Size: 20 bytes [LEPUS_NewCFunction2]
// Khung tháo gỡ #1718 | Địa chỉ PC: 0x1a912c | Địa chỉ FDE: 0x049d30 | Kích thước: 20 bytes
//   0x1a912c: 39458008  ldrb     w8, [x0, #0x160]
//   0x1a9130: F9402006  ldr      x6, [x0, #0x40]
//   0x1a9134: 34000048  cbz      w8, #0x1a913c
//   0x1a9138: 17FB9398  b        #0x8df98
static inline uint64_t fde_func_1718_0x1a912c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1a912cULL ^ (static_cast<uint64_t>(0x39458008ULL) << 13);
    acc = (acc + a1 + 0xf9402006ULL) ^ 0x049d30ULL;
    acc ^= (acc >> 17) * 0x0014ULL;
    return acc;
}

// FDE #1719 | PC: 0x1a9140 | FDE: 0x049d48 | Size: 48 bytes [LEPUS_SetOpaque]
// Khung tháo gỡ #1719 | Địa chỉ PC: 0x1a9140 | Địa chỉ FDE: 0x049d48 | Kích thước: 48 bytes
//   0x1a9140: B4000160  cbz      x0, #0x1a916c
//   0x1a9144: D2800048  mov      x8, #2
//   0x1a9148: F2FFFFE8  movk     x8, #0xffff, lsl #48
//   0x1a914c: 8A080008  and      x8, x0, x8
static inline uint64_t fde_func_1719_0x1a9140(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1a9140ULL ^ (static_cast<uint64_t>(0xb4000160ULL) << 13);
    acc = (acc + a1 + 0xd2800048ULL) ^ 0x049d48ULL;
    acc ^= (acc >> 17) * 0x0030ULL;
    return acc;
}

// FDE #1720 | PC: 0x1a9170 | FDE: 0x049d60 | Size: 8 bytes [LEPUS_IsGCMode]
// Khung tháo gỡ #1720 | Địa chỉ PC: 0x1a9170 | Địa chỉ FDE: 0x049d60 | Kích thước: 8 bytes
//   0x1a9170: 39458000  ldrb     w0, [x0, #0x160]
//   0x1a9174: D65F03C0  ret      
static inline uint64_t fde_func_1720_0x1a9170(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1a9170ULL ^ (static_cast<uint64_t>(0x39458000ULL) << 13);
    acc = (acc + a1 + 0xd65f03c0ULL) ^ 0x049d60ULL;
    acc ^= (acc >> 17) * 0x0008ULL;
    return acc;
}

// FDE #1721 | PC: 0x1a9178 | FDE: 0x049d78 | Size: 8 bytes [LEPUS_IsGCModeRT]
// Khung tháo gỡ #1721 | Địa chỉ PC: 0x1a9178 | Địa chỉ FDE: 0x049d78 | Kích thước: 8 bytes
//   0x1a9178: 394CC000  ldrb     w0, [x0, #0x330]
//   0x1a917c: D65F03C0  ret      
static inline uint64_t fde_func_1721_0x1a9178(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1a9178ULL ^ (static_cast<uint64_t>(0x394cc000ULL) << 13);
    acc = (acc + a1 + 0xd65f03c0ULL) ^ 0x049d78ULL;
    acc ^= (acc >> 17) * 0x0008ULL;
    return acc;
}

// FDE #1722 | PC: 0x1a9180 | FDE: 0x049d90 | Size: 8 bytes [__JS_FreeValue]
// Khung tháo gỡ #1722 | Địa chỉ PC: 0x1a9180 | Địa chỉ FDE: 0x049d90 | Kích thước: 8 bytes
//   0x1a9180: F9400800  ldr      x0, [x0, #0x10]
//   0x1a9184: 17FCFF14  b        #0xe8dd4
static inline uint64_t fde_func_1722_0x1a9180(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1a9180ULL ^ (static_cast<uint64_t>(0xf9400800ULL) << 13);
    acc = (acc + a1 + 0x17fcff14ULL) ^ 0x049d90ULL;
    acc ^= (acc >> 17) * 0x0008ULL;
    return acc;
}

// FDE #1723 | PC: 0x1a9188 | FDE: 0x049da8 | Size: 40 bytes [CheckObjectRt]
// Khung tháo gỡ #1723 | Địa chỉ PC: 0x1a9188 | Địa chỉ FDE: 0x049da8 | Kích thước: 40 bytes
//   0x1a9188: 39551008  ldrb     w8, [x0, #0x544]
//   0x1a918c: 35000048  cbnz     w8, #0x1a9194
//   0x1a9190: D65F03C0  ret      
//   0x1a9194: F9403009  ldr      x9, [x0, #0x60]
static inline uint64_t fde_func_1723_0x1a9188(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1a9188ULL ^ (static_cast<uint64_t>(0x39551008ULL) << 13);
    acc = (acc + a1 + 0x35000048ULL) ^ 0x049da8ULL;
    acc ^= (acc >> 17) * 0x0028ULL;
    return acc;
}

// FDE #1724 | PC: 0x1a91b0 | FDE: 0x049dc0 | Size: 28 bytes [LEPUS_MarkValue]
// Khung tháo gỡ #1724 | Địa chỉ PC: 0x1a91b0 | Địa chỉ FDE: 0x049dc0 | Kích thước: 28 bytes
//   0x1a91b0: 394CC008  ldrb     w8, [x0, #0x330]
//   0x1a91b4: AA0203E4  mov      x4, x2
//   0x1a91b8: 34000068  cbz      w8, #0x1a91c4
//   0x1a91bc: 93407C62  sxtw     x2, w3
static inline uint64_t fde_func_1724_0x1a91b0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1a91b0ULL ^ (static_cast<uint64_t>(0x394cc008ULL) << 13);
    acc = (acc + a1 + 0xaa0203e4ULL) ^ 0x049dc0ULL;
    acc ^= (acc >> 17) * 0x001cULL;
    return acc;
}

// FDE #1725 | PC: 0x1a91cc | FDE: 0x049dd8 | Size: 8 bytes [LEPUS_IsInGCSweep]
// Khung tháo gỡ #1725 | Địa chỉ PC: 0x1a91cc | Địa chỉ FDE: 0x049dd8 | Kích thước: 8 bytes
//   0x1a91cc: 39C30000  ldrsb    w0, [x0, #0xc0]
//   0x1a91d0: D65F03C0  ret      
static inline uint64_t fde_func_1725_0x1a91cc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1a91ccULL ^ (static_cast<uint64_t>(0x39c30000ULL) << 13);
    acc = (acc + a1 + 0xd65f03c0ULL) ^ 0x049dd8ULL;
    acc ^= (acc >> 17) * 0x0008ULL;
    return acc;
}

// FDE #1726 | PC: 0x1a91d4 | FDE: 0x049df0 | Size: 148 bytes [LEPUS_GetGlobalObject]
// Khung tháo gỡ #1726 | Địa chỉ PC: 0x1a91d4 | Địa chỉ FDE: 0x049df0 | Kích thước: 148 bytes
//   0x1a91d4: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x1a91d8: 39458008  ldrb     w8, [x0, #0x160]
//   0x1a91dc: F9406413  ldr      x19, [x0, #0xc8]
//   0x1a91e0: 350003E8  cbnz     w8, #0x1a925c
static inline uint64_t fde_func_1726_0x1a91d4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1a91d4ULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0x39458008ULL) ^ 0x049df0ULL;
    acc ^= (acc >> 17) * 0x0094ULL;
    return acc;
}

// FDE #1727 | PC: 0x1a9268 | FDE: 0x049e08 | Size: 60 bytes [LEPUS_IsError]
// Khung tháo gỡ #1727 | Địa chỉ PC: 0x1a9268 | Địa chỉ FDE: 0x049e08 | Kích thước: 60 bytes
//   0x1a9268: 2A1F03E0  mov      w0, wzr
//   0x1a926c: B40001A1  cbz      x1, #0x1a92a0
//   0x1a9270: D2800048  mov      x8, #2
//   0x1a9274: F2FFFFE8  movk     x8, #0xffff, lsl #48
static inline uint64_t fde_func_1727_0x1a9268(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1a9268ULL ^ (static_cast<uint64_t>(0x2a1f03e0ULL) << 13);
    acc = (acc + a1 + 0xb40001a1ULL) ^ 0x049e08ULL;
    acc ^= (acc >> 17) * 0x003cULL;
    return acc;
}

// FDE #1728 | PC: 0x1a92a4 | FDE: 0x049e20 | Size: 24 bytes [LEPUS_GetException]
// Khung tháo gỡ #1728 | Địa chỉ PC: 0x1a92a4 | Địa chỉ FDE: 0x049e20 | Kích thước: 24 bytes
//   0x1a92a4: F9400808  ldr      x8, [x0, #0x10]
//   0x1a92a8: 52800049  mov      w9, #2
//   0x1a92ac: F9407100  ldr      x0, [x8, #0xe0]
//   0x1a92b0: F9007109  str      x9, [x8, #0xe0]
static inline uint64_t fde_func_1728_0x1a92a4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1a92a4ULL ^ (static_cast<uint64_t>(0xf9400808ULL) << 13);
    acc = (acc + a1 + 0x52800049ULL) ^ 0x049e20ULL;
    acc ^= (acc >> 17) * 0x0018ULL;
    return acc;
}

// FDE #1729 | PC: 0x1a92bc | FDE: 0x049e38 | Size: 92 bytes [get_leb128_u64]
// Khung tháo gỡ #1729 | Địa chỉ PC: 0x1a92bc | Địa chỉ FDE: 0x049e38 | Kích thước: 92 bytes
//   0x1a92bc: EB02003F  cmp      x1, x2
//   0x1a92c0: 54000202  b.hs     #0x1a9300
//   0x1a92c4: AA1F03E9  mov      x9, xzr
//   0x1a92c8: AA1F03E8  mov      x8, xzr
static inline uint64_t fde_func_1729_0x1a92bc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1a92bcULL ^ (static_cast<uint64_t>(0xeb02003fULL) << 13);
    acc = (acc + a1 + 0x54000202ULL) ^ 0x049e38ULL;
    acc ^= (acc >> 17) * 0x005cULL;
    return acc;
}

// FDE #1730 | PC: 0x1a9318 | FDE: 0x049e50 | Size: 124 bytes [get_sleb128_u64]
// Khung tháo gỡ #1730 | Địa chỉ PC: 0x1a9318 | Địa chỉ FDE: 0x049e50 | Kích thước: 124 bytes
//   0x1a9318: EB02003F  cmp      x1, x2
//   0x1a931c: 54000083  b.lo     #0x1a932c
//   0x1a9320: AA1F03E9  mov      x9, xzr
//   0x1a9324: 12800008  mov      w8, #-1
static inline uint64_t fde_func_1730_0x1a9318(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1a9318ULL ^ (static_cast<uint64_t>(0xeb02003fULL) << 13);
    acc = (acc + a1 + 0x54000083ULL) ^ 0x049e50ULL;
    acc ^= (acc >> 17) * 0x007cULL;
    return acc;
}

// FDE #1731 | PC: 0x1a9394 | FDE: 0x049e68 | Size: 244 bytes [LEPUS_DefinePropertyValue]
// Khung tháo gỡ #1731 | Địa chỉ PC: 0x1a9394 | Địa chỉ FDE: 0x049e68 | Kích thước: 244 bytes
//   0x1a9394: F81D0FF6  str      x22, [sp, #-0x30]!
//   0x1a9398: A90153F5  stp      x21, x20, [sp, #0x10]
//   0x1a939c: A9027BF3  stp      x19, x30, [sp, #0x20]
//   0x1a93a0: 39458008  ldrb     w8, [x0, #0x160]
static inline uint64_t fde_func_1731_0x1a9394(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1a9394ULL ^ (static_cast<uint64_t>(0xf81d0ff6ULL) << 13);
    acc = (acc + a1 + 0xa90153f5ULL) ^ 0x049e68ULL;
    acc ^= (acc >> 17) * 0x00f4ULL;
    return acc;
}

// FDE #1732 | PC: 0x1a9488 | FDE: 0x049e88 | Size: 32 bytes [LEPUS_NewError]
// Khung tháo gỡ #1732 | Địa chỉ PC: 0x1a9488 | Địa chỉ FDE: 0x049e88 | Kích thước: 32 bytes
//   0x1a9488: 39458008  ldrb     w8, [x0, #0x160]
//   0x1a948c: 34000068  cbz      w8, #0x1a9498
//   0x1a9490: 52800061  mov      w1, #3
//   0x1a9494: 17FBC0F2  b        #0x9985c
static inline uint64_t fde_func_1732_0x1a9488(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1a9488ULL ^ (static_cast<uint64_t>(0x39458008ULL) << 13);
    acc = (acc + a1 + 0x34000068ULL) ^ 0x049e88ULL;
    acc ^= (acc >> 17) * 0x0020ULL;
    return acc;
}

// FDE #1733 | PC: 0x1a94a8 | FDE: 0x049ea0 | Size: 136 bytes
// Khung tháo gỡ #1733 | Địa chỉ PC: 0x1a94a8 | Địa chỉ FDE: 0x049ea0 | Kích thước: 136 bytes
//   0x1a94a8: D101C3FF  sub      sp, sp, #0x70
//   0x1a94ac: F9002BF4  str      x20, [sp, #0x50]
//   0x1a94b0: A9067BF3  stp      x19, x30, [sp, #0x60]
//   0x1a94b4: D53BD054  mrs      x20, tpidr_el0
static inline uint64_t fde_func_1733_0x1a94a8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1a94a8ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xf9002bf4ULL) ^ 0x049ea0ULL;
    acc ^= (acc >> 17) * 0x0088ULL;
    return acc;
}

// FDE #1734 | PC: 0x1a9530 | FDE: 0x049ec0 | Size: 28 bytes
// Khung tháo gỡ #1734 | Địa chỉ PC: 0x1a9530 | Địa chỉ FDE: 0x049ec0 | Kích thước: 28 bytes
//   0x1a9530: F81F0FFE  str      x30, [sp, #-0x10]!
//   0x1a9534: B0FFF441  adrp     x1, #0x32000
//   0x1a9538: 910ADC21  add      x1, x1, #0x2b7
//   0x1a953c: 97FD3EBE  bl       #0xf9034
static inline uint64_t fde_func_1734_0x1a9530(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1a9530ULL ^ (static_cast<uint64_t>(0xf81f0ffeULL) << 13);
    acc = (acc + a1 + 0xb0fff441ULL) ^ 0x049ec0ULL;
    acc ^= (acc >> 17) * 0x001cULL;
    return acc;
}

// FDE #1735 | PC: 0x1a954c | FDE: 0x049ed8 | Size: 24 bytes [LEPUS_SetPrototype]
// Khung tháo gỡ #1735 | Địa chỉ PC: 0x1a954c | Địa chỉ FDE: 0x049ed8 | Kích thước: 24 bytes
//   0x1a954c: 39458008  ldrb     w8, [x0, #0x160]
//   0x1a9550: 34000068  cbz      w8, #0x1a955c
//   0x1a9554: 52800023  mov      w3, #1
//   0x1a9558: 17FBC5F8  b        #0x9ad38
static inline uint64_t fde_func_1735_0x1a954c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1a954cULL ^ (static_cast<uint64_t>(0x39458008ULL) << 13);
    acc = (acc + a1 + 0x34000068ULL) ^ 0x049ed8ULL;
    acc ^= (acc >> 17) * 0x0018ULL;
    return acc;
}

// FDE #1736 | PC: 0x1a9564 | FDE: 0x049ef0 | Size: 16 bytes [LEPUS_GetPrototype]
// Khung tháo gỡ #1736 | Địa chỉ PC: 0x1a9564 | Địa chỉ FDE: 0x049ef0 | Kích thước: 16 bytes
//   0x1a9564: 39458008  ldrb     w8, [x0, #0x160]
//   0x1a9568: 34000048  cbz      w8, #0x1a9570
//   0x1a956c: 17FB5F80  b        #0x8136c
//   0x1a9570: 17FD4152  b        #0xf9ab8
static inline uint64_t fde_func_1736_0x1a9564(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1a9564ULL ^ (static_cast<uint64_t>(0x39458008ULL) << 13);
    acc = (acc + a1 + 0x34000048ULL) ^ 0x049ef0ULL;
    acc ^= (acc >> 17) * 0x0010ULL;
    return acc;
}

// FDE #1737 | PC: 0x1a9574 | FDE: 0x049f08 | Size: 16 bytes [LEPUS_IsInstanceOf]
// Khung tháo gỡ #1737 | Địa chỉ PC: 0x1a9574 | Địa chỉ FDE: 0x049f08 | Kích thước: 16 bytes
//   0x1a9574: 39458008  ldrb     w8, [x0, #0x160]
//   0x1a9578: 34000048  cbz      w8, #0x1a9580
//   0x1a957c: 17FCB2EB  b        #0xd6128
//   0x1a9580: 17FD7D98  b        #0x108be0
static inline uint64_t fde_func_1737_0x1a9574(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1a9574ULL ^ (static_cast<uint64_t>(0x39458008ULL) << 13);
    acc = (acc + a1 + 0x34000048ULL) ^ 0x049f08ULL;
    acc ^= (acc >> 17) * 0x0010ULL;
    return acc;
}

// FDE #1738 | PC: 0x1a9584 | FDE: 0x049f20 | Size: 16 bytes [LEPUS_GetPropertyInternal]
// Khung tháo gỡ #1738 | Địa chỉ PC: 0x1a9584 | Địa chỉ FDE: 0x049f20 | Kích thước: 16 bytes
//   0x1a9584: 39458008  ldrb     w8, [x0, #0x160]
//   0x1a9588: 34000048  cbz      w8, #0x1a9590
//   0x1a958c: 17FB5D53  b        #0x80ad8
//   0x1a9590: 17FD369C  b        #0xf7000
static inline uint64_t fde_func_1738_0x1a9584(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1a9584ULL ^ (static_cast<uint64_t>(0x39458008ULL) << 13);
    acc = (acc + a1 + 0x34000048ULL) ^ 0x049f20ULL;
    acc ^= (acc >> 17) * 0x0010ULL;
    return acc;
}

// FDE #1739 | PC: 0x1a9594 | FDE: 0x049f38 | Size: 80 bytes [LEPUS_GetPropertyUint32]
// Khung tháo gỡ #1739 | Địa chỉ PC: 0x1a9594 | Địa chỉ FDE: 0x049f38 | Kích thước: 80 bytes
//   0x1a9594: 39458008  ldrb     w8, [x0, #0x160]
//   0x1a9598: 340000A8  cbz      w8, #0x1a95ac
//   0x1a959c: 37F80102  tbnz     w2, #0x1f, #0x1a95bc
//   0x1a95a0: 2A0203E8  mov      w8, w2
static inline uint64_t fde_func_1739_0x1a9594(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1a9594ULL ^ (static_cast<uint64_t>(0x39458008ULL) << 13);
    acc = (acc + a1 + 0x340000a8ULL) ^ 0x049f38ULL;
    acc ^= (acc >> 17) * 0x0050ULL;
    return acc;
}

// FDE #1740 | PC: 0x1a95e4 | FDE: 0x049f50 | Size: 128 bytes [LEPUS_GetOwnPropertyNames]
// Khung tháo gỡ #1740 | Địa chỉ PC: 0x1a95e4 | Địa chỉ FDE: 0x049f50 | Kích thước: 128 bytes
//   0x1a95e4: F81F0FFE  str      x30, [sp, #-0x10]!
//   0x1a95e8: D2800048  mov      x8, #2
//   0x1a95ec: F2FFFFE8  movk     x8, #0xffff, lsl #48
//   0x1a95f0: 39458009  ldrb     w9, [x0, #0x160]
static inline uint64_t fde_func_1740_0x1a95e4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1a95e4ULL ^ (static_cast<uint64_t>(0xf81f0ffeULL) << 13);
    acc = (acc + a1 + 0xd2800048ULL) ^ 0x049f50ULL;
    acc ^= (acc >> 17) * 0x0080ULL;
    return acc;
}

// FDE #1741 | PC: 0x1a9664 | FDE: 0x049f68 | Size: 128 bytes [LEPUS_GetOwnProperty]
// Khung tháo gỡ #1741 | Địa chỉ PC: 0x1a9664 | Địa chỉ FDE: 0x049f68 | Kích thước: 128 bytes
//   0x1a9664: F81F0FFE  str      x30, [sp, #-0x10]!
//   0x1a9668: D2800048  mov      x8, #2
//   0x1a966c: F2FFFFE8  movk     x8, #0xffff, lsl #48
//   0x1a9670: 39458009  ldrb     w9, [x0, #0x160]
static inline uint64_t fde_func_1741_0x1a9664(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1a9664ULL ^ (static_cast<uint64_t>(0xf81f0ffeULL) << 13);
    acc = (acc + a1 + 0xd2800048ULL) ^ 0x049f68ULL;
    acc ^= (acc >> 17) * 0x0080ULL;
    return acc;
}

// FDE #1742 | PC: 0x1a96e4 | FDE: 0x049f80 | Size: 136 bytes [LEPUS_IsExtensible]
// Khung tháo gỡ #1742 | Địa chỉ PC: 0x1a96e4 | Địa chỉ FDE: 0x049f80 | Kích thước: 136 bytes
//   0x1a96e4: D2800048  mov      x8, #2
//   0x1a96e8: F2FFFFE8  movk     x8, #0xffff, lsl #48
//   0x1a96ec: 39458009  ldrb     w9, [x0, #0x160]
//   0x1a96f0: EA08003F  tst      x1, x8
static inline uint64_t fde_func_1742_0x1a96e4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1a96e4ULL ^ (static_cast<uint64_t>(0xd2800048ULL) << 13);
    acc = (acc + a1 + 0xf2ffffe8ULL) ^ 0x049f80ULL;
    acc ^= (acc >> 17) * 0x0088ULL;
    return acc;
}

// FDE #1743 | PC: 0x1a976c | FDE: 0x049f98 | Size: 24 bytes [LEPUS_ToPropertyKey]
// Khung tháo gỡ #1743 | Địa chỉ PC: 0x1a976c | Địa chỉ FDE: 0x049f98 | Kích thước: 24 bytes
//   0x1a976c: 39458008  ldrb     w8, [x0, #0x160]
//   0x1a9770: 34000068  cbz      w8, #0x1a977c
//   0x1a9774: 52800022  mov      w2, #1
//   0x1a9778: 17FB589F  b        #0x7f9f4
static inline uint64_t fde_func_1743_0x1a976c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1a976cULL ^ (static_cast<uint64_t>(0x39458008ULL) << 13);
    acc = (acc + a1 + 0x34000068ULL) ^ 0x049f98ULL;
    acc ^= (acc >> 17) * 0x0018ULL;
    return acc;
}

// FDE #1744 | PC: 0x1a9784 | FDE: 0x049fb0 | Size: 16 bytes [LEPUS_SetPropertyInternal]
// Khung tháo gỡ #1744 | Địa chỉ PC: 0x1a9784 | Địa chỉ FDE: 0x049fb0 | Kích thước: 16 bytes
//   0x1a9784: 39458008  ldrb     w8, [x0, #0x160]
//   0x1a9788: 34000048  cbz      w8, #0x1a9790
//   0x1a978c: 17FB7E09  b        #0x88fb0
//   0x1a9790: 17FD52C1  b        #0xfe294
static inline uint64_t fde_func_1744_0x1a9784(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1a9784ULL ^ (static_cast<uint64_t>(0x39458008ULL) << 13);
    acc = (acc + a1 + 0x34000048ULL) ^ 0x049fb0ULL;
    acc ^= (acc >> 17) * 0x0010ULL;
    return acc;
}

// FDE #1745 | PC: 0x1a9794 | FDE: 0x049fc8 | Size: 96 bytes [LEPUS_SetPropertyUint32]
// Khung tháo gỡ #1745 | Địa chỉ PC: 0x1a9794 | Địa chỉ FDE: 0x049fc8 | Kích thước: 96 bytes
//   0x1a9794: 39458008  ldrb     w8, [x0, #0x160]
//   0x1a9798: 340000C8  cbz      w8, #0x1a97b0
//   0x1a979c: 37F80142  tbnz     w2, #0x1f, #0x1a97c4
//   0x1a97a0: 2A0203E8  mov      w8, w2
static inline uint64_t fde_func_1745_0x1a9794(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1a9794ULL ^ (static_cast<uint64_t>(0x39458008ULL) << 13);
    acc = (acc + a1 + 0x340000c8ULL) ^ 0x049fc8ULL;
    acc ^= (acc >> 17) * 0x0060ULL;
    return acc;
}

// FDE #1746 | PC: 0x1a97f4 | FDE: 0x049fe0 | Size: 156 bytes [LEPUS_SetPropertyStr]
// Khung tháo gỡ #1746 | Địa chỉ PC: 0x1a97f4 | Địa chỉ FDE: 0x049fe0 | Kích thước: 156 bytes
//   0x1a97f4: F81D0FF6  str      x22, [sp, #-0x30]!
//   0x1a97f8: A90153F5  stp      x21, x20, [sp, #0x10]
//   0x1a97fc: A9027BF3  stp      x19, x30, [sp, #0x20]
//   0x1a9800: 39458008  ldrb     w8, [x0, #0x160]
static inline uint64_t fde_func_1746_0x1a97f4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1a97f4ULL ^ (static_cast<uint64_t>(0xf81d0ff6ULL) << 13);
    acc = (acc + a1 + 0xa90153f5ULL) ^ 0x049fe0ULL;
    acc ^= (acc >> 17) * 0x009cULL;
    return acc;
}

// FDE #1747 | PC: 0x1a9890 | FDE: 0x04a000 | Size: 16 bytes [LEPUS_DefineProperty]
// Khung tháo gỡ #1747 | Địa chỉ PC: 0x1a9890 | Địa chỉ FDE: 0x04a000 | Kích thước: 16 bytes
//   0x1a9890: 39458008  ldrb     w8, [x0, #0x160]
//   0x1a9894: 34000048  cbz      w8, #0x1a989c
//   0x1a9898: 17FB7458  b        #0x869f8
//   0x1a989c: 17FD4735  b        #0xfb570
static inline uint64_t fde_func_1747_0x1a9890(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1a9890ULL ^ (static_cast<uint64_t>(0x39458008ULL) << 13);
    acc = (acc + a1 + 0x34000048ULL) ^ 0x04a000ULL;
    acc ^= (acc >> 17) * 0x0010ULL;
    return acc;
}

// FDE #1748 | PC: 0x1a98a0 | FDE: 0x04a018 | Size: 64 bytes [LEPUS_VisitLEPUSValue]
// Khung tháo gỡ #1748 | Địa chỉ PC: 0x1a98a0 | Địa chỉ FDE: 0x04a018 | Kích thước: 64 bytes
//   0x1a98a0: F81F0FFE  str      x30, [sp, #-0x10]!
//   0x1a98a4: 394CC008  ldrb     w8, [x0, #0x330]
//   0x1a98a8: 34000108  cbz      w8, #0x1a98c8
//   0x1a98ac: F9418C08  ldr      x8, [x0, #0x318]
static inline uint64_t fde_func_1748_0x1a98a0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1a98a0ULL ^ (static_cast<uint64_t>(0xf81f0ffeULL) << 13);
    acc = (acc + a1 + 0x394cc008ULL) ^ 0x04a018ULL;
    acc ^= (acc >> 17) * 0x0040ULL;
    return acc;
}

// FDE #1749 | PC: 0x1a98e0 | FDE: 0x04a030 | Size: 156 bytes [DisposeGlobal]
// Khung tháo gỡ #1749 | Địa chỉ PC: 0x1a98e0 | Địa chỉ FDE: 0x04a030 | Kích thước: 156 bytes
//   0x1a98e0: 394CC008  ldrb     w8, [x0, #0x330]
//   0x1a98e4: 340004A8  cbz      w8, #0x1a9978
//   0x1a98e8: B4000481  cbz      x1, #0x1a9978
//   0x1a98ec: 39406028  ldrb     w8, [x1, #0x18]
static inline uint64_t fde_func_1749_0x1a98e0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1a98e0ULL ^ (static_cast<uint64_t>(0x394cc008ULL) << 13);
    acc = (acc + a1 + 0x340004a8ULL) ^ 0x04a030ULL;
    acc ^= (acc >> 17) * 0x009cULL;
    return acc;
}

// FDE #1750 | PC: 0x1a997c | FDE: 0x04a048 | Size: 28 bytes [GlobalizeReference]
// Khung tháo gỡ #1750 | Địa chỉ PC: 0x1a997c | Địa chỉ FDE: 0x04a048 | Kích thước: 28 bytes
//   0x1a997c: 394CC008  ldrb     w8, [x0, #0x330]
//   0x1a9980: 34000088  cbz      w8, #0x1a9990
//   0x1a9984: F9418000  ldr      x0, [x0, #0x300]
//   0x1a9988: 12000042  and      w2, w2, #1
static inline uint64_t fde_func_1750_0x1a997c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1a997cULL ^ (static_cast<uint64_t>(0x394cc008ULL) << 13);
    acc = (acc + a1 + 0x34000088ULL) ^ 0x04a048ULL;
    acc ^= (acc >> 17) * 0x001cULL;
    return acc;
}

// FDE #1751 | PC: 0x1a9998 | FDE: 0x04a060 | Size: 16 bytes [LEPUS_GetGlobalVar]
// Khung tháo gỡ #1751 | Địa chỉ PC: 0x1a9998 | Địa chỉ FDE: 0x04a060 | Kích thước: 16 bytes
//   0x1a9998: 39458008  ldrb     w8, [x0, #0x160]
//   0x1a999c: 34000048  cbz      w8, #0x1a99a4
//   0x1a99a0: 17FCC4CB  b        #0xdaccc
//   0x1a99a4: 17FD4522  b        #0xfae2c
static inline uint64_t fde_func_1751_0x1a9998(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1a9998ULL ^ (static_cast<uint64_t>(0x39458008ULL) << 13);
    acc = (acc + a1 + 0x34000048ULL) ^ 0x04a060ULL;
    acc ^= (acc >> 17) * 0x0010ULL;
    return acc;
}

// FDE #1752 | PC: 0x1a99a8 | FDE: 0x04a078 | Size: 16 bytes [LEPUS_SetGlobalVar]
// Khung tháo gỡ #1752 | Địa chỉ PC: 0x1a99a8 | Địa chỉ FDE: 0x04a078 | Kích thước: 16 bytes
//   0x1a99a8: 39458008  ldrb     w8, [x0, #0x160]
//   0x1a99ac: 34000048  cbz      w8, #0x1a99b4
//   0x1a99b0: 17FCC5AE  b        #0xdb068
//   0x1a99b4: 17FD4581  b        #0xfafb8
static inline uint64_t fde_func_1752_0x1a99a8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1a99a8ULL ^ (static_cast<uint64_t>(0x39458008ULL) << 13);
    acc = (acc + a1 + 0x34000048ULL) ^ 0x04a078ULL;
    acc ^= (acc >> 17) * 0x0010ULL;
    return acc;
}

// FDE #1753 | PC: 0x1a99b8 | FDE: 0x04a090 | Size: 128 bytes [LEPUS_IsFunction]
// Khung tháo gỡ #1753 | Địa chỉ PC: 0x1a99b8 | Địa chỉ FDE: 0x04a090 | Kích thước: 128 bytes
//   0x1a99b8: 2A1F03E8  mov      w8, wzr
//   0x1a99bc: B40003A1  cbz      x1, #0x1a9a30
//   0x1a99c0: D2800049  mov      x9, #2
//   0x1a99c4: F2FFFFE9  movk     x9, #0xffff, lsl #48
static inline uint64_t fde_func_1753_0x1a99b8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1a99b8ULL ^ (static_cast<uint64_t>(0x2a1f03e8ULL) << 13);
    acc = (acc + a1 + 0xb40003a1ULL) ^ 0x04a090ULL;
    acc ^= (acc >> 17) * 0x0080ULL;
    return acc;
}

// FDE #1754 | PC: 0x1a9a38 | FDE: 0x04a0a8 | Size: 56 bytes [LEPUS_IsConstructor]
// Khung tháo gỡ #1754 | Địa chỉ PC: 0x1a9a38 | Địa chỉ FDE: 0x04a0a8 | Kích thước: 56 bytes
//   0x1a9a38: 2A1F03E0  mov      w0, wzr
//   0x1a9a3c: B4000181  cbz      x1, #0x1a9a6c
//   0x1a9a40: D2800048  mov      x8, #2
//   0x1a9a44: F2FFFFE8  movk     x8, #0xffff, lsl #48
static inline uint64_t fde_func_1754_0x1a9a38(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1a9a38ULL ^ (static_cast<uint64_t>(0x2a1f03e0ULL) << 13);
    acc = (acc + a1 + 0xb4000181ULL) ^ 0x04a0a8ULL;
    acc ^= (acc >> 17) * 0x0038ULL;
    return acc;
}

// FDE #1755 | PC: 0x1a9a70 | FDE: 0x04a0c0 | Size: 72 bytes [LEPUS_SetConstructorBit]
// Khung tháo gỡ #1755 | Địa chỉ PC: 0x1a9a70 | Địa chỉ FDE: 0x04a0c0 | Kích thước: 72 bytes
//   0x1a9a70: 2A1F03E0  mov      w0, wzr
//   0x1a9a74: B4000201  cbz      x1, #0x1a9ab4
//   0x1a9a78: D2800048  mov      x8, #2
//   0x1a9a7c: F2FFFFE8  movk     x8, #0xffff, lsl #48
static inline uint64_t fde_func_1755_0x1a9a70(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1a9a70ULL ^ (static_cast<uint64_t>(0x2a1f03e0ULL) << 13);
    acc = (acc + a1 + 0xb4000201ULL) ^ 0x04a0c0ULL;
    acc ^= (acc >> 17) * 0x0048ULL;
    return acc;
}

// FDE #1756 | PC: 0x1a9ab8 | FDE: 0x04a0d8 | Size: 80 bytes [LEPUS_ResetUncatchableError]
// Khung tháo gỡ #1756 | Địa chỉ PC: 0x1a9ab8 | Địa chỉ FDE: 0x04a0d8 | Kích thước: 80 bytes
//   0x1a9ab8: F9400808  ldr      x8, [x0, #0x10]
//   0x1a9abc: D2800049  mov      x9, #2
//   0x1a9ac0: F2FFFFE9  movk     x9, #0xffff, lsl #48
//   0x1a9ac4: F9407108  ldr      x8, [x8, #0xe0]
static inline uint64_t fde_func_1756_0x1a9ab8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1a9ab8ULL ^ (static_cast<uint64_t>(0xf9400808ULL) << 13);
    acc = (acc + a1 + 0xd2800049ULL) ^ 0x04a0d8ULL;
    acc ^= (acc >> 17) * 0x0050ULL;
    return acc;
}

// FDE #1757 | PC: 0x1a9b08 | FDE: 0x04a0f0 | Size: 76 bytes [LEPUS_GetOpaque]
// Khung tháo gỡ #1757 | Địa chỉ PC: 0x1a9b08 | Địa chỉ FDE: 0x04a0f0 | Kích thước: 76 bytes
//   0x1a9b08: AA0003E8  mov      x8, x0
//   0x1a9b0c: AA1F03E0  mov      x0, xzr
//   0x1a9b10: B40001C8  cbz      x8, #0x1a9b48
//   0x1a9b14: D2800049  mov      x9, #2
static inline uint64_t fde_func_1757_0x1a9b08(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1a9b08ULL ^ (static_cast<uint64_t>(0xaa0003e8ULL) << 13);
    acc = (acc + a1 + 0xaa1f03e0ULL) ^ 0x04a0f0ULL;
    acc ^= (acc >> 17) * 0x004cULL;
    return acc;
}

// FDE #1758 | PC: 0x1a9b54 | FDE: 0x04a108 | Size: 184 bytes [LEPUS_ToBool]
// Khung tháo gỡ #1758 | Địa chỉ PC: 0x1a9b54 | Địa chỉ FDE: 0x04a108 | Kích thước: 184 bytes
//   0x1a9b54: F81E0FF4  str      x20, [sp, #-0x20]!
//   0x1a9b58: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x1a9b5c: 39458008  ldrb     w8, [x0, #0x160]
//   0x1a9b60: AA0103F3  mov      x19, x1
static inline uint64_t fde_func_1758_0x1a9b54(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1a9b54ULL ^ (static_cast<uint64_t>(0xf81e0ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x04a108ULL;
    acc ^= (acc >> 17) * 0x00b8ULL;
    return acc;
}

// FDE #1759 | PC: 0x1a9c0c | FDE: 0x04a128 | Size: 256 bytes
// Khung tháo gỡ #1759 | Địa chỉ PC: 0x1a9c0c | Địa chỉ FDE: 0x04a128 | Kích thước: 256 bytes
//   0x1a9c0c: F0FFF448  adrp     x8, #0x34000
//   0x1a9c10: F0FFF449  adrp     x9, #0x34000
//   0x1a9c14: F0FFF44A  adrp     x10, #0x34000
//   0x1a9c18: 9138D108  add      x8, x8, #0xe34
static inline uint64_t fde_func_1759_0x1a9c0c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1a9c0cULL ^ (static_cast<uint64_t>(0xf0fff448ULL) << 13);
    acc = (acc + a1 + 0xf0fff449ULL) ^ 0x04a128ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1760 | PC: 0x1a9d58 | FDE: 0x04a140 | Size: 12 bytes [LEPUS_SetNoStrictMode]
// Khung tháo gỡ #1760 | Địa chỉ PC: 0x1a9d58 | Địa chỉ FDE: 0x04a140 | Kích thước: 12 bytes
//   0x1a9d58: 52800028  mov      w8, #1
//   0x1a9d5c: B9011808  str      w8, [x0, #0x118]
//   0x1a9d60: D65F03C0  ret      
static inline uint64_t fde_func_1760_0x1a9d58(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1a9d58ULL ^ (static_cast<uint64_t>(0x52800028ULL) << 13);
    acc = (acc + a1 + 0xb9011808ULL) ^ 0x04a140ULL;
    acc ^= (acc >> 17) * 0x000cULL;
    return acc;
}

// FDE #1761 | PC: 0x1a9d64 | FDE: 0x04a158 | Size: 24 bytes [LEPUS_ToString]
// Khung tháo gỡ #1761 | Địa chỉ PC: 0x1a9d64 | Địa chỉ FDE: 0x04a158 | Kích thước: 24 bytes
//   0x1a9d64: 39458008  ldrb     w8, [x0, #0x160]
//   0x1a9d68: 34000068  cbz      w8, #0x1a9d74
//   0x1a9d6c: 2A1F03E2  mov      w2, wzr
//   0x1a9d70: 17FB5721  b        #0x7f9f4
static inline uint64_t fde_func_1761_0x1a9d64(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1a9d64ULL ^ (static_cast<uint64_t>(0x39458008ULL) << 13);
    acc = (acc + a1 + 0x34000068ULL) ^ 0x04a158ULL;
    acc ^= (acc >> 17) * 0x0018ULL;
    return acc;
}

// FDE #1762 | PC: 0x1a9d7c | FDE: 0x04a170 | Size: 52 bytes [_Z20JS_StringToBigIntErrP12LEPUSContext10LEPUSValue]
// Khung tháo gỡ #1762 | Địa chỉ PC: 0x1a9d7c | Địa chỉ FDE: 0x04a170 | Kích thước: 52 bytes
//   0x1a9d7c: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x1a9d80: AA0003F3  mov      x19, x0
//   0x1a9d84: 97FD8DA1  bl       #0x10d408
//   0x1a9d88: D2EFFF48  mov      x8, #0x7ffa000000000000
static inline uint64_t fde_func_1762_0x1a9d7c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1a9d7cULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0xaa0003f3ULL) ^ 0x04a170ULL;
    acc ^= (acc >> 17) * 0x0034ULL;
    return acc;
}

// FDE #1763 | PC: 0x1a9db0 | FDE: 0x04a188 | Size: 168 bytes [LEPUS_ToBigInt64]
// Khung tháo gỡ #1763 | Địa chỉ PC: 0x1a9db0 | Địa chỉ FDE: 0x04a188 | Kích thước: 168 bytes
//   0x1a9db0: A9BE53F5  stp      x21, x20, [sp, #-0x20]!
//   0x1a9db4: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x1a9db8: 92503C48  and      x8, x2, #0xffff000000000000
//   0x1a9dbc: D2E00029  mov      x9, #0x1000000000000
static inline uint64_t fde_func_1763_0x1a9db0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1a9db0ULL ^ (static_cast<uint64_t>(0xa9be53f5ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x04a188ULL;
    acc ^= (acc >> 17) * 0x00a8ULL;
    return acc;
}

// FDE #1764 | PC: 0x1a9e58 | FDE: 0x04a1a8 | Size: 216 bytes [LEPUS_NewLepusWrap]
// Khung tháo gỡ #1764 | Địa chỉ PC: 0x1a9e58 | Địa chỉ FDE: 0x04a1a8 | Kích thước: 216 bytes
//   0x1a9e58: A9BE53F5  stp      x21, x20, [sp, #-0x20]!
//   0x1a9e5c: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x1a9e60: 39458008  ldrb     w8, [x0, #0x160]
//   0x1a9e64: 2A0203F3  mov      w19, w2
static inline uint64_t fde_func_1764_0x1a9e58(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1a9e58ULL ^ (static_cast<uint64_t>(0xa9be53f5ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x04a1a8ULL;
    acc ^= (acc >> 17) * 0x00d8ULL;
    return acc;
}

// FDE #1765 | PC: 0x1a9f30 | FDE: 0x04a1c8 | Size: 12 bytes [RegisterGCInfoCallback]
// Khung tháo gỡ #1765 | Địa chỉ PC: 0x1a9f30 | Địa chỉ FDE: 0x04a1c8 | Kích thước: 12 bytes
//   0x1a9f30: B4000040  cbz      x0, #0x1a9f38
//   0x1a9f34: F9011001  str      x1, [x0, #0x220]
//   0x1a9f38: D65F03C0  ret      
static inline uint64_t fde_func_1765_0x1a9f30(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1a9f30ULL ^ (static_cast<uint64_t>(0xb4000040ULL) << 13);
    acc = (acc + a1 + 0xf9011001ULL) ^ 0x04a1c8ULL;
    acc ^= (acc >> 17) * 0x000cULL;
    return acc;
}

// FDE #1766 | PC: 0x1a9f3c | FDE: 0x04a1e0 | Size: 80 bytes [RegisterLepusRefCallbacks]
// Khung tháo gỡ #1766 | Địa chỉ PC: 0x1a9f3c | Địa chỉ FDE: 0x04a1e0 | Kích thước: 80 bytes
//   0x1a9f3c: B4000260  cbz      x0, #0x1a9f88
//   0x1a9f40: F9400028  ldr      x8, [x1]
//   0x1a9f44: F900E008  str      x8, [x0, #0x1c0]
//   0x1a9f48: F9400428  ldr      x8, [x1, #8]
static inline uint64_t fde_func_1766_0x1a9f3c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1a9f3cULL ^ (static_cast<uint64_t>(0xb4000260ULL) << 13);
    acc = (acc + a1 + 0xf9400028ULL) ^ 0x04a1e0ULL;
    acc ^= (acc >> 17) * 0x0050ULL;
    return acc;
}

// FDE #1767 | PC: 0x1a9f8c | FDE: 0x04a1f8 | Size: 256 bytes [RegisterPrimJSCallbacks]
// Khung tháo gỡ #1767 | Địa chỉ PC: 0x1a9f8c | Địa chỉ FDE: 0x04a1f8 | Kích thước: 256 bytes
//   0x1a9f8c: B4000480  cbz      x0, #0x1aa01c
//   0x1a9f90: B4000461  cbz      x1, #0x1aa01c
//   0x1a9f94: 7100045F  cmp      w2, #1
//   0x1a9f98: 5400044B  b.lt     #0x1aa020
static inline uint64_t fde_func_1767_0x1a9f8c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1a9f8cULL ^ (static_cast<uint64_t>(0xb4000480ULL) << 13);
    acc = (acc + a1 + 0xb4000461ULL) ^ 0x04a1f8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1768 | PC: 0x1aa0d4 | FDE: 0x04a210 | Size: 124 bytes [LEPUS_SetStringCache]
// Khung tháo gỡ #1768 | Địa chỉ PC: 0x1aa0d4 | Địa chỉ FDE: 0x04a210 | Kích thước: 124 bytes
//   0x1aa0d4: 39458009  ldrb     w9, [x0, #0x160]
//   0x1aa0d8: 92504428  and      x8, x1, #0xffff000000000003
//   0x1aa0dc: B25047E9  mov      x9, #-0xfffffffffffd
//   0x1aa0e0: EB09011F  cmp      x8, x9
static inline uint64_t fde_func_1768_0x1aa0d4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1aa0d4ULL ^ (static_cast<uint64_t>(0x39458009ULL) << 13);
    acc = (acc + a1 + 0x92504428ULL) ^ 0x04a210ULL;
    acc ^= (acc >> 17) * 0x007cULL;
    return acc;
}

// FDE #1769 | PC: 0x1aa150 | FDE: 0x04a228 | Size: 256 bytes [LEPUS_Call]
// Khung tháo gỡ #1769 | Địa chỉ PC: 0x1aa150 | Địa chỉ FDE: 0x04a228 | Kích thước: 256 bytes
//   0x1aa150: A9BC63F9  stp      x25, x24, [sp, #-0x40]!
//   0x1aa154: A9015BF7  stp      x23, x22, [sp, #0x10]
//   0x1aa158: A90253F5  stp      x21, x20, [sp, #0x20]
//   0x1aa15c: A9037BF3  stp      x19, x30, [sp, #0x30]
static inline uint64_t fde_func_1769_0x1aa150(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1aa150ULL ^ (static_cast<uint64_t>(0xa9bc63f9ULL) << 13);
    acc = (acc + a1 + 0xa9015bf7ULL) ^ 0x04a228ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1770 | PC: 0x1aa260 | FDE: 0x04a250 | Size: 24 bytes [LEPUS_CallConstructor2]
// Khung tháo gỡ #1770 | Địa chỉ PC: 0x1aa260 | Địa chỉ FDE: 0x04a250 | Kích thước: 24 bytes
//   0x1aa260: 39458008  ldrb     w8, [x0, #0x160]
//   0x1aa264: 34000068  cbz      w8, #0x1aa270
//   0x1aa268: 52800045  mov      w5, #2
//   0x1aa26c: 17FB70C9  b        #0x86590
static inline uint64_t fde_func_1770_0x1aa260(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1aa260ULL ^ (static_cast<uint64_t>(0x39458008ULL) << 13);
    acc = (acc + a1 + 0x34000068ULL) ^ 0x04a250ULL;
    acc ^= (acc >> 17) * 0x0018ULL;
    return acc;
}

// FDE #1771 | PC: 0x1aa278 | FDE: 0x04a268 | Size: 40 bytes [LEPUS_CallConstructor]
// Khung tháo gỡ #1771 | Địa chỉ PC: 0x1aa278 | Địa chỉ FDE: 0x04a268 | Kích thước: 40 bytes
//   0x1aa278: 39458008  ldrb     w8, [x0, #0x160]
//   0x1aa27c: AA0303E4  mov      x4, x3
//   0x1aa280: 2A0203E3  mov      w3, w2
//   0x1aa284: 34000088  cbz      w8, #0x1aa294
static inline uint64_t fde_func_1771_0x1aa278(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1aa278ULL ^ (static_cast<uint64_t>(0x39458008ULL) << 13);
    acc = (acc + a1 + 0xaa0303e4ULL) ^ 0x04a268ULL;
    acc ^= (acc >> 17) * 0x0028ULL;
    return acc;
}

// FDE #1772 | PC: 0x1aa2a0 | FDE: 0x04a280 | Size: 208 bytes
// Khung tháo gỡ #1772 | Địa chỉ PC: 0x1aa2a0 | Địa chỉ FDE: 0x04a280 | Kích thước: 208 bytes
//   0x1aa2a0: F81E0FF4  str      x20, [sp, #-0x20]!
//   0x1aa2a4: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x1aa2a8: B9401808  ldr      w8, [x0, #0x18]
//   0x1aa2ac: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_1772_0x1aa2a0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1aa2a0ULL ^ (static_cast<uint64_t>(0xf81e0ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x04a280ULL;
    acc ^= (acc >> 17) * 0x00d0ULL;
    return acc;
}

// FDE #1773 | PC: 0x1aa370 | FDE: 0x04a2a0 | Size: 224 bytes [LEPUS_NewCModule]
// Khung tháo gỡ #1773 | Địa chỉ PC: 0x1aa370 | Địa chỉ FDE: 0x04a2a0 | Kích thước: 224 bytes
//   0x1aa370: F81C0FF8  str      x24, [sp, #-0x40]!
//   0x1aa374: A9015BF7  stp      x23, x22, [sp, #0x10]
//   0x1aa378: A90253F5  stp      x21, x20, [sp, #0x20]
//   0x1aa37c: A9037BF3  stp      x19, x30, [sp, #0x30]
static inline uint64_t fde_func_1773_0x1aa370(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1aa370ULL ^ (static_cast<uint64_t>(0xf81c0ff8ULL) << 13);
    acc = (acc + a1 + 0xa9015bf7ULL) ^ 0x04a2a0ULL;
    acc ^= (acc >> 17) * 0x00e0ULL;
    return acc;
}

// FDE #1774 | PC: 0x1aa450 | FDE: 0x04a2c8 | Size: 256 bytes [LEPUS_SetModuleExport]
// Khung tháo gỡ #1774 | Địa chỉ PC: 0x1aa450 | Địa chỉ FDE: 0x04a2c8 | Kích thước: 256 bytes
//   0x1aa450: A9BC63F9  stp      x25, x24, [sp, #-0x40]!
//   0x1aa454: A9015BF7  stp      x23, x22, [sp, #0x10]
//   0x1aa458: A90253F5  stp      x21, x20, [sp, #0x20]
//   0x1aa45c: A9037BF3  stp      x19, x30, [sp, #0x30]
static inline uint64_t fde_func_1774_0x1aa450(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1aa450ULL ^ (static_cast<uint64_t>(0xa9bc63f9ULL) << 13);
    acc = (acc + a1 + 0xa9015bf7ULL) ^ 0x04a2c8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1775 | PC: 0x1aa6d4 | FDE: 0x04a2f0 | Size: 12 bytes [LEPUS_SetModuleLoaderFunc]
// Khung tháo gỡ #1775 | Địa chỉ PC: 0x1aa6d4 | Địa chỉ FDE: 0x04a2f0 | Kích thước: 12 bytes
//   0x1aa6d4: A9118801  stp      x1, x2, [x0, #0x118]
//   0x1aa6d8: F9009403  str      x3, [x0, #0x128]
//   0x1aa6dc: D65F03C0  ret      
static inline uint64_t fde_func_1775_0x1aa6d4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1aa6d4ULL ^ (static_cast<uint64_t>(0xa9118801ULL) << 13);
    acc = (acc + a1 + 0xf9009403ULL) ^ 0x04a2f0ULL;
    acc ^= (acc >> 17) * 0x000cULL;
    return acc;
}

// FDE #1776 | PC: 0x1aa6e0 | FDE: 0x04a308 | Size: 24 bytes [LEPUS_NewPromiseCapability]
// Khung tháo gỡ #1776 | Địa chỉ PC: 0x1aa6e0 | Địa chỉ FDE: 0x04a308 | Kích thước: 24 bytes
//   0x1aa6e0: 39458008  ldrb     w8, [x0, #0x160]
//   0x1aa6e4: 34000068  cbz      w8, #0x1aa6f0
//   0x1aa6e8: 52800242  mov      w2, #0x12
//   0x1aa6ec: 17FBB0BF  b        #0x969e8
static inline uint64_t fde_func_1776_0x1aa6e0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1aa6e0ULL ^ (static_cast<uint64_t>(0x39458008ULL) << 13);
    acc = (acc + a1 + 0x34000068ULL) ^ 0x04a308ULL;
    acc ^= (acc >> 17) * 0x0018ULL;
    return acc;
}

// FDE #1777 | PC: 0x1aa6f8 | FDE: 0x04a320 | Size: 32 bytes [LEPUS_EvalFunction]
// Khung tháo gỡ #1777 | Địa chỉ PC: 0x1aa6f8 | Địa chỉ FDE: 0x04a320 | Kích thước: 32 bytes
//   0x1aa6f8: 39458008  ldrb     w8, [x0, #0x160]
//   0x1aa6fc: 34000088  cbz      w8, #0x1aa70c
//   0x1aa700: AA1F03E3  mov      x3, xzr
//   0x1aa704: AA1F03E4  mov      x4, xzr
static inline uint64_t fde_func_1777_0x1aa6f8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1aa6f8ULL ^ (static_cast<uint64_t>(0x39458008ULL) << 13);
    acc = (acc + a1 + 0x34000088ULL) ^ 0x04a320ULL;
    acc ^= (acc >> 17) * 0x0020ULL;
    return acc;
}

// FDE #1778 | PC: 0x1aa718 | FDE: 0x04a338 | Size: 92 bytes [LEPUS_Eval]
// Khung tháo gỡ #1778 | Địa chỉ PC: 0x1aa718 | Địa chỉ FDE: 0x04a338 | Kích thước: 92 bytes
//   0x1aa718: D10083FF  sub      sp, sp, #0x20
//   0x1aa71c: F9000BFE  str      x30, [sp, #0x10]
//   0x1aa720: 39458009  ldrb     w9, [x0, #0x160]
//   0x1aa724: F9408008  ldr      x8, [x0, #0x100]
static inline uint64_t fde_func_1778_0x1aa718(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1aa718ULL ^ (static_cast<uint64_t>(0xd10083ffULL) << 13);
    acc = (acc + a1 + 0xf9000bfeULL) ^ 0x04a338ULL;
    acc ^= (acc >> 17) * 0x005cULL;
    return acc;
}

// FDE #1779 | PC: 0x1aa774 | FDE: 0x04a350 | Size: 96 bytes [LEPUS_Eval2]
// Khung tháo gỡ #1779 | Địa chỉ PC: 0x1aa774 | Địa chỉ FDE: 0x04a350 | Kích thước: 96 bytes
//   0x1aa774: D10083FF  sub      sp, sp, #0x20
//   0x1aa778: F9000BFE  str      x30, [sp, #0x10]
//   0x1aa77c: 3945800A  ldrb     w10, [x0, #0x160]
//   0x1aa780: F9408009  ldr      x9, [x0, #0x100]
static inline uint64_t fde_func_1779_0x1aa774(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1aa774ULL ^ (static_cast<uint64_t>(0xd10083ffULL) << 13);
    acc = (acc + a1 + 0xf9000bfeULL) ^ 0x04a350ULL;
    acc ^= (acc >> 17) * 0x0060ULL;
    return acc;
}

// FDE #1780 | PC: 0x1aa7d4 | FDE: 0x04a368 | Size: 256 bytes [LEPUS_EvalBinary]
// Khung tháo gỡ #1780 | Địa chỉ PC: 0x1aa7d4 | Địa chỉ FDE: 0x04a368 | Kích thước: 256 bytes
//   0x1aa7d4: F81D0FF6  str      x22, [sp, #-0x30]!
//   0x1aa7d8: A90153F5  stp      x21, x20, [sp, #0x10]
//   0x1aa7dc: A9027BF3  stp      x19, x30, [sp, #0x20]
//   0x1aa7e0: 39458008  ldrb     w8, [x0, #0x160]
static inline uint64_t fde_func_1780_0x1aa7d4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1aa7d4ULL ^ (static_cast<uint64_t>(0xf81d0ff6ULL) << 13);
    acc = (acc + a1 + 0xa90153f5ULL) ^ 0x04a368ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1781 | PC: 0x1aa968 | FDE: 0x04a388 | Size: 84 bytes [_Z15JS_IsNewVersionP12LEPUSContext]
// Khung tháo gỡ #1781 | Địa chỉ PC: 0x1aa968 | Địa chỉ FDE: 0x04a388 | Kích thước: 84 bytes
//   0x1aa968: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x1aa96c: F9409413  ldr      x19, [x0, #0x128]
//   0x1aa970: B4000213  cbz      x19, #0x1aa9b0
//   0x1aa974: 39400268  ldrb     w8, [x19]
static inline uint64_t fde_func_1781_0x1aa968(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1aa968ULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0xf9409413ULL) ^ 0x04a388ULL;
    acc ^= (acc >> 17) * 0x0054ULL;
    return acc;
}

// FDE #1782 | PC: 0x1aa9bc | FDE: 0x04a3a0 | Size: 12 bytes [LEPUS_GetPrimjsVersion]
// Khung tháo gỡ #1782 | Địa chỉ PC: 0x1aa9bc | Địa chỉ FDE: 0x04a3a0 | Kích thước: 12 bytes
//   0x1aa9bc: 52803980  mov      w0, #0x1cc
//   0x1aa9c0: 72B95600  movk     w0, #0xcab0, lsl #16
//   0x1aa9c4: D65F03C0  ret      
static inline uint64_t fde_func_1782_0x1aa9bc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1aa9bcULL ^ (static_cast<uint64_t>(0x52803980ULL) << 13);
    acc = (acc + a1 + 0x72b95600ULL) ^ 0x04a3a0ULL;
    acc ^= (acc >> 17) * 0x000cULL;
    return acc;
}

// FDE #1783 | PC: 0x1aa9c8 | FDE: 0x04a3b8 | Size: 20 bytes [_Z23JS_CheckBytecodeVersionm]
// Khung tháo gỡ #1783 | Địa chỉ PC: 0x1aa9c8 | Địa chỉ FDE: 0x04a3b8 | Kích thước: 20 bytes
//   0x1aa9c8: 52803988  mov      w8, #0x1cc
//   0x1aa9cc: 72B95608  movk     w8, #0xcab0, lsl #16
//   0x1aa9d0: 6B08001F  cmp      w0, w8
//   0x1aa9d4: 1A9F97E0  cset     w0, hi
static inline uint64_t fde_func_1783_0x1aa9c8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1aa9c8ULL ^ (static_cast<uint64_t>(0x52803988ULL) << 13);
    acc = (acc + a1 + 0x72b95608ULL) ^ 0x04a3b8ULL;
    acc ^= (acc >> 17) * 0x0014ULL;
    return acc;
}

// FDE #1784 | PC: 0x1aa9dc | FDE: 0x04a3d0 | Size: 256 bytes [LEPUS_SetModuleExportList]
// Khung tháo gỡ #1784 | Địa chỉ PC: 0x1aa9dc | Địa chỉ FDE: 0x04a3d0 | Kích thước: 256 bytes
//   0x1aa9dc: D101C3FF  sub      sp, sp, #0x70
//   0x1aa9e0: A9016FFC  stp      x28, x27, [sp, #0x10]
//   0x1aa9e4: A90267FA  stp      x26, x25, [sp, #0x20]
//   0x1aa9e8: A9035FF8  stp      x24, x23, [sp, #0x30]
static inline uint64_t fde_func_1784_0x1aa9dc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1aa9dcULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xa9016ffcULL) ^ 0x04a3d0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1785 | PC: 0x1aabe4 | FDE: 0x04a400 | Size: 256 bytes [LEPUS_DeepEqual]
// Khung tháo gỡ #1785 | Địa chỉ PC: 0x1aabe4 | Địa chỉ FDE: 0x04a400 | Kích thước: 256 bytes
//   0x1aabe4: D10203FF  sub      sp, sp, #0x80
//   0x1aabe8: A9026FFC  stp      x28, x27, [sp, #0x20]
//   0x1aabec: A90367FA  stp      x26, x25, [sp, #0x30]
//   0x1aabf0: A9045FF8  stp      x24, x23, [sp, #0x40]
static inline uint64_t fde_func_1785_0x1aabe4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1aabe4ULL ^ (static_cast<uint64_t>(0xd10203ffULL) << 13);
    acc = (acc + a1 + 0xa9026ffcULL) ^ 0x04a400ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1786 | PC: 0x1ab2b0 | FDE: 0x04a430 | Size: 256 bytes [LEPUS_IterateObject]
// Khung tháo gỡ #1786 | Địa chỉ PC: 0x1ab2b0 | Địa chỉ FDE: 0x04a430 | Kích thước: 256 bytes
//   0x1ab2b0: D101C3FF  sub      sp, sp, #0x70
//   0x1ab2b4: A9016FFC  stp      x28, x27, [sp, #0x10]
//   0x1ab2b8: A90267FA  stp      x26, x25, [sp, #0x20]
//   0x1ab2bc: A9035FF8  stp      x24, x23, [sp, #0x30]
static inline uint64_t fde_func_1786_0x1ab2b0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1ab2b0ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xa9016ffcULL) ^ 0x04a430ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1787 | PC: 0x1ab638 | FDE: 0x04a460 | Size: 20 bytes [_Z11lre_reallocPvS_m]
// Khung tháo gỡ #1787 | Địa chỉ PC: 0x1ab638 | Địa chỉ FDE: 0x04a460 | Kích thước: 20 bytes
//   0x1ab638: F9400808  ldr      x8, [x0, #0x10]
//   0x1ab63c: 2A1F03E3  mov      w3, wzr
//   0x1ab640: F9400904  ldr      x4, [x8, #0x10]
//   0x1ab644: 910D2100  add      x0, x8, #0x348
static inline uint64_t fde_func_1787_0x1ab638(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1ab638ULL ^ (static_cast<uint64_t>(0xf9400808ULL) << 13);
    acc = (acc + a1 + 0x2a1f03e3ULL) ^ 0x04a460ULL;
    acc ^= (acc >> 17) * 0x0014ULL;
    return acc;
}

// FDE #1788 | PC: 0x1ab64c | FDE: 0x04a478 | Size: 256 bytes [LEPUS_MoveUnhandledRejectionToException]
// Khung tháo gỡ #1788 | Địa chỉ PC: 0x1ab64c | Địa chỉ FDE: 0x04a478 | Kích thước: 256 bytes
//   0x1ab64c: A9BE53F5  stp      x21, x20, [sp, #-0x20]!
//   0x1ab650: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x1ab654: 39458009  ldrb     w9, [x0, #0x160]
//   0x1ab658: F9400808  ldr      x8, [x0, #0x10]
static inline uint64_t fde_func_1788_0x1ab64c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1ab64cULL ^ (static_cast<uint64_t>(0xa9be53f5ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x04a478ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1789 | PC: 0x1ab788 | FDE: 0x04a498 | Size: 28 bytes [LEPUS_GetHeapSize]
// Khung tháo gỡ #1789 | Địa chỉ PC: 0x1ab788 | Địa chỉ FDE: 0x04a498 | Kích thước: 28 bytes
//   0x1ab788: 394CC008  ldrb     w8, [x0, #0x330]
//   0x1ab78c: 52808609  mov      w9, #0x430
//   0x1ab790: 7100011F  cmp      w8, #0
//   0x1ab794: 52806A08  mov      w8, #0x350
static inline uint64_t fde_func_1789_0x1ab788(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1ab788ULL ^ (static_cast<uint64_t>(0x394cc008ULL) << 13);
    acc = (acc + a1 + 0x52808609ULL) ^ 0x04a498ULL;
    acc ^= (acc >> 17) * 0x001cULL;
    return acc;
}

// FDE #1790 | PC: 0x1ab7a4 | FDE: 0x04a4b0 | Size: 84 bytes [LEPUS_IsArrayBuffer]
// Khung tháo gỡ #1790 | Địa chỉ PC: 0x1ab7a4 | Địa chỉ FDE: 0x04a4b0 | Kích thước: 84 bytes
//   0x1ab7a4: AA0003E8  mov      x8, x0
//   0x1ab7a8: 2A1F03E0  mov      w0, wzr
//   0x1ab7ac: B4000208  cbz      x8, #0x1ab7ec
//   0x1ab7b0: D2800049  mov      x9, #2
static inline uint64_t fde_func_1790_0x1ab7a4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1ab7a4ULL ^ (static_cast<uint64_t>(0xaa0003e8ULL) << 13);
    acc = (acc + a1 + 0x2a1f03e0ULL) ^ 0x04a4b0ULL;
    acc ^= (acc >> 17) * 0x0054ULL;
    return acc;
}

// FDE #1791 | PC: 0x1ab7f8 | FDE: 0x04a4c8 | Size: 64 bytes [LEPUS_IsTypedArray]
// Khung tháo gỡ #1791 | Địa chỉ PC: 0x1ab7f8 | Địa chỉ FDE: 0x04a4c8 | Kích thước: 64 bytes
//   0x1ab7f8: 2A1F03E0  mov      w0, wzr
//   0x1ab7fc: B40001C1  cbz      x1, #0x1ab834
//   0x1ab800: D2800048  mov      x8, #2
//   0x1ab804: F2FFFFE8  movk     x8, #0xffff, lsl #48
static inline uint64_t fde_func_1791_0x1ab7f8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1ab7f8ULL ^ (static_cast<uint64_t>(0x2a1f03e0ULL) << 13);
    acc = (acc + a1 + 0xb40001c1ULL) ^ 0x04a4c8ULL;
    acc ^= (acc >> 17) * 0x0040ULL;
    return acc;
}

// FDE #1792 | PC: 0x1ab838 | FDE: 0x04a4e0 | Size: 24 bytes [LEPUS_StrictEq]
// Khung tháo gỡ #1792 | Địa chỉ PC: 0x1ab838 | Địa chỉ FDE: 0x04a4e0 | Kích thước: 24 bytes
//   0x1ab838: 39458008  ldrb     w8, [x0, #0x160]
//   0x1ab83c: 34000068  cbz      w8, #0x1ab848
//   0x1ab840: 2A1F03E3  mov      w3, wzr
//   0x1ab844: 17FB69B5  b        #0x85f18
static inline uint64_t fde_func_1792_0x1ab838(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1ab838ULL ^ (static_cast<uint64_t>(0x39458008ULL) << 13);
    acc = (acc + a1 + 0x34000068ULL) ^ 0x04a4e0ULL;
    acc ^= (acc >> 17) * 0x0018ULL;
    return acc;
}

// FDE #1793 | PC: 0x1ab850 | FDE: 0x04a4f8 | Size: 256 bytes [LEPUS_SameValue]
// Khung tháo gỡ #1793 | Địa chỉ PC: 0x1ab850 | Địa chỉ FDE: 0x04a4f8 | Kích thước: 256 bytes
//   0x1ab850: F81D0FF6  str      x22, [sp, #-0x30]!
//   0x1ab854: A90153F5  stp      x21, x20, [sp, #0x10]
//   0x1ab858: A9027BF3  stp      x19, x30, [sp, #0x20]
//   0x1ab85c: 39458008  ldrb     w8, [x0, #0x160]
static inline uint64_t fde_func_1793_0x1ab850(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1ab850ULL ^ (static_cast<uint64_t>(0xf81d0ff6ULL) << 13);
    acc = (acc + a1 + 0xa90153f5ULL) ^ 0x04a4f8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1794 | PC: 0x1ab9a0 | FDE: 0x04a518 | Size: 52 bytes [LEPUS_NewArrayBuffer]
// Khung tháo gỡ #1794 | Địa chỉ PC: 0x1ab9a0 | Địa chỉ FDE: 0x04a518 | Kích thước: 52 bytes
//   0x1ab9a0: 39458009  ldrb     w9, [x0, #0x160]
//   0x1ab9a4: AA0303E8  mov      x8, x3
//   0x1ab9a8: 710000BF  cmp      w5, #0
//   0x1ab9ac: 5280026A  mov      w10, #0x13
static inline uint64_t fde_func_1794_0x1ab9a0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1ab9a0ULL ^ (static_cast<uint64_t>(0x39458009ULL) << 13);
    acc = (acc + a1 + 0xaa0303e8ULL) ^ 0x04a518ULL;
    acc ^= (acc >> 17) * 0x0034ULL;
    return acc;
}

// FDE #1795 | PC: 0x1ab9d4 | FDE: 0x04a530 | Size: 64 bytes [LEPUS_NewArrayBufferCopy]
// Khung tháo gỡ #1795 | Địa chỉ PC: 0x1ab9d4 | Địa chỉ FDE: 0x04a530 | Kích thước: 64 bytes
//   0x1ab9d4: 39458008  ldrb     w8, [x0, #0x160]
//   0x1ab9d8: AA0103E4  mov      x4, x1
//   0x1ab9dc: 340000E8  cbz      w8, #0x1ab9f8
//   0x1ab9e0: 52800241  mov      w1, #0x12
static inline uint64_t fde_func_1795_0x1ab9d4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1ab9d4ULL ^ (static_cast<uint64_t>(0x39458008ULL) << 13);
    acc = (acc + a1 + 0xaa0103e4ULL) ^ 0x04a530ULL;
    acc ^= (acc >> 17) * 0x0040ULL;
    return acc;
}

// FDE #1796 | PC: 0x1aba14 | FDE: 0x04a548 | Size: 256 bytes [LEPUS_DetachArrayBuffer]
// Khung tháo gỡ #1796 | Địa chỉ PC: 0x1aba14 | Địa chỉ FDE: 0x04a548 | Kích thước: 256 bytes
//   0x1aba14: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x1aba18: D2800048  mov      x8, #2
//   0x1aba1c: F2FFFFE8  movk     x8, #0xffff, lsl #48
//   0x1aba20: 39458009  ldrb     w9, [x0, #0x160]
static inline uint64_t fde_func_1796_0x1aba14(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1aba14ULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0xd2800048ULL) ^ 0x04a548ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1797 | PC: 0x1abb7c | FDE: 0x04a560 | Size: 240 bytes [LEPUS_GetArrayBuffer]
// Khung tháo gỡ #1797 | Địa chỉ PC: 0x1abb7c | Địa chỉ FDE: 0x04a560 | Kích thước: 240 bytes
//   0x1abb7c: D101C3FF  sub      sp, sp, #0x70
//   0x1abb80: A90553F5  stp      x21, x20, [sp, #0x50]
//   0x1abb84: A9067BF3  stp      x19, x30, [sp, #0x60]
//   0x1abb88: D53BD055  mrs      x21, tpidr_el0
static inline uint64_t fde_func_1797_0x1abb7c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1abb7cULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xa90553f5ULL) ^ 0x04a560ULL;
    acc ^= (acc >> 17) * 0x00f0ULL;
    return acc;
}

// FDE #1798 | PC: 0x1abc6c | FDE: 0x04a580 | Size: 256 bytes [LEPUS_MoveArrayBuffer]
// Khung tháo gỡ #1798 | Địa chỉ PC: 0x1abc6c | Địa chỉ FDE: 0x04a580 | Kích thước: 256 bytes
//   0x1abc6c: D10203FF  sub      sp, sp, #0x80
//   0x1abc70: F9002BF6  str      x22, [sp, #0x50]
//   0x1abc74: A90653F5  stp      x21, x20, [sp, #0x60]
//   0x1abc78: A9077BF3  stp      x19, x30, [sp, #0x70]
static inline uint64_t fde_func_1798_0x1abc6c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1abc6cULL ^ (static_cast<uint64_t>(0xd10203ffULL) << 13);
    acc = (acc + a1 + 0xf9002bf6ULL) ^ 0x04a580ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1799 | PC: 0x1abd94 | FDE: 0x04a5a0 | Size: 84 bytes [LEPUS_ToJSON]
// Khung tháo gỡ #1799 | Địa chỉ PC: 0x1abd94 | Địa chỉ FDE: 0x04a5a0 | Kích thước: 84 bytes
//   0x1abd94: D100C3FF  sub      sp, sp, #0x30
//   0x1abd98: A9027BF3  stp      x19, x30, [sp, #0x20]
//   0x1abd9c: D53BD053  mrs      x19, tpidr_el0
//   0x1abda0: F9401668  ldr      x8, [x19, #0x28]
static inline uint64_t fde_func_1799_0x1abd94(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1abd94ULL ^ (static_cast<uint64_t>(0xd100c3ffULL) << 13);
    acc = (acc + a1 + 0xa9027bf3ULL) ^ 0x04a5a0ULL;
    acc ^= (acc >> 17) * 0x0054ULL;
    return acc;
}

// FDE #1800 | PC: 0x1abde8 | FDE: 0x04a5b8 | Size: 224 bytes [LEPUS_NewWString]
// Khung tháo gỡ #1800 | Địa chỉ PC: 0x1abde8 | Địa chỉ FDE: 0x04a5b8 | Kích thước: 224 bytes
//   0x1abde8: A9BD5BF7  stp      x23, x22, [sp, #-0x30]!
//   0x1abdec: A90153F5  stp      x21, x20, [sp, #0x10]
//   0x1abdf0: A9027BF3  stp      x19, x30, [sp, #0x20]
//   0x1abdf4: 39458008  ldrb     w8, [x0, #0x160]
static inline uint64_t fde_func_1800_0x1abde8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1abde8ULL ^ (static_cast<uint64_t>(0xa9bd5bf7ULL) << 13);
    acc = (acc + a1 + 0xa90153f5ULL) ^ 0x04a5b8ULL;
    acc ^= (acc >> 17) * 0x00e0ULL;
    return acc;
}

// FDE #1801 | PC: 0x1abec8 | FDE: 0x04a5d8 | Size: 256 bytes [LEPUS_ToWString]
// Khung tháo gỡ #1801 | Địa chỉ PC: 0x1abec8 | Địa chỉ FDE: 0x04a5d8 | Kích thước: 256 bytes
//   0x1abec8: D10183FF  sub      sp, sp, #0x60
//   0x1abecc: A9016BFB  stp      x27, x26, [sp, #0x10]
//   0x1abed0: A90263F9  stp      x25, x24, [sp, #0x20]
//   0x1abed4: A9035BF7  stp      x23, x22, [sp, #0x30]
static inline uint64_t fde_func_1801_0x1abec8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1abec8ULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xa9016bfbULL) ^ 0x04a5d8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1802 | PC: 0x1ac214 | FDE: 0x04a600 | Size: 76 bytes [LEPUS_GetStringLength]
// Khung tháo gỡ #1802 | Địa chỉ PC: 0x1ac214 | Địa chỉ FDE: 0x04a600 | Kích thước: 76 bytes
//   0x1ac214: D2800049  mov      x9, #2
//   0x1ac218: 92504428  and      x8, x1, #0xffff000000000003
//   0x1ac21c: F2E00029  movk     x9, #1, lsl #48
//   0x1ac220: EB09011F  cmp      x8, x9
static inline uint64_t fde_func_1802_0x1ac214(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1ac214ULL ^ (static_cast<uint64_t>(0xd2800049ULL) << 13);
    acc = (acc + a1 + 0x92504428ULL) ^ 0x04a600ULL;
    acc ^= (acc >> 17) * 0x004cULL;
    return acc;
}

// FDE #1803 | PC: 0x1ac260 | FDE: 0x04a618 | Size: 132 bytes [LEPUS_GetStringChars]
// Khung tháo gỡ #1803 | Địa chỉ PC: 0x1ac260 | Địa chỉ FDE: 0x04a618 | Kích thước: 132 bytes
//   0x1ac260: F81F0FFE  str      x30, [sp, #-0x10]!
//   0x1ac264: 39458009  ldrb     w9, [x0, #0x160]
//   0x1ac268: 92504428  and      x8, x1, #0xffff000000000003
//   0x1ac26c: 340000C9  cbz      w9, #0x1ac284
static inline uint64_t fde_func_1803_0x1ac260(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1ac260ULL ^ (static_cast<uint64_t>(0xf81f0ffeULL) << 13);
    acc = (acc + a1 + 0x39458009ULL) ^ 0x04a618ULL;
    acc ^= (acc >> 17) * 0x0084ULL;
    return acc;
}

// FDE #1804 | PC: 0x1ac2e4 | FDE: 0x04a630 | Size: 52 bytes [LEPUS_GetClassID]
// Khung tháo gỡ #1804 | Địa chỉ PC: 0x1ac2e4 | Địa chỉ FDE: 0x04a630 | Kích thước: 52 bytes
//   0x1ac2e4: 2A1F03E0  mov      w0, wzr
//   0x1ac2e8: B4000161  cbz      x1, #0x1ac314
//   0x1ac2ec: D2800048  mov      x8, #2
//   0x1ac2f0: F2FFFFE8  movk     x8, #0xffff, lsl #48
static inline uint64_t fde_func_1804_0x1ac2e4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1ac2e4ULL ^ (static_cast<uint64_t>(0x2a1f03e0ULL) << 13);
    acc = (acc + a1 + 0xb4000161ULL) ^ 0x04a630ULL;
    acc ^= (acc >> 17) * 0x0034ULL;
    return acc;
}

// FDE #1805 | PC: 0x1ac318 | FDE: 0x04a648 | Size: 28 bytes [LEPUS_NewArrayWithValue]
// Khung tháo gỡ #1805 | Địa chỉ PC: 0x1ac318 | Địa chỉ FDE: 0x04a648 | Kích thước: 28 bytes
//   0x1ac318: 39458008  ldrb     w8, [x0, #0x160]
//   0x1ac31c: AA0203E3  mov      x3, x2
//   0x1ac320: 2A0103E2  mov      w2, w1
//   0x1ac324: 2A1F03E1  mov      w1, wzr
static inline uint64_t fde_func_1805_0x1ac318(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1ac318ULL ^ (static_cast<uint64_t>(0x39458008ULL) << 13);
    acc = (acc + a1 + 0xaa0203e3ULL) ^ 0x04a648ULL;
    acc ^= (acc >> 17) * 0x001cULL;
    return acc;
}

// FDE #1806 | PC: 0x1ac334 | FDE: 0x04a660 | Size: 252 bytes [LEPUS_NewTypedArray]
// Khung tháo gỡ #1806 | Địa chỉ PC: 0x1ac334 | Địa chỉ FDE: 0x04a660 | Kích thước: 252 bytes
//   0x1ac334: D10103FF  sub      sp, sp, #0x40
//   0x1ac338: A9015BF7  stp      x23, x22, [sp, #0x10]
//   0x1ac33c: A90253F5  stp      x21, x20, [sp, #0x20]
//   0x1ac340: A9037BF3  stp      x19, x30, [sp, #0x30]
static inline uint64_t fde_func_1806_0x1ac334(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1ac334ULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xa9015bf7ULL) ^ 0x04a660ULL;
    acc ^= (acc >> 17) * 0x00fcULL;
    return acc;
}

// FDE #1807 | PC: 0x1ac430 | FDE: 0x04a680 | Size: 140 bytes [LEPUS_NewTypedArrayWithBuffer]
// Khung tháo gỡ #1807 | Địa chỉ PC: 0x1ac430 | Địa chỉ FDE: 0x04a680 | Kích thước: 140 bytes
//   0x1ac430: D100C3FF  sub      sp, sp, #0x30
//   0x1ac434: A9027BF3  stp      x19, x30, [sp, #0x20]
//   0x1ac438: D53BD053  mrs      x19, tpidr_el0
//   0x1ac43c: F9401668  ldr      x8, [x19, #0x28]
static inline uint64_t fde_func_1807_0x1ac430(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1ac430ULL ^ (static_cast<uint64_t>(0xd100c3ffULL) << 13);
    acc = (acc + a1 + 0xa9027bf3ULL) ^ 0x04a680ULL;
    acc ^= (acc >> 17) * 0x008cULL;
    return acc;
}

// FDE #1808 | PC: 0x1ac4bc | FDE: 0x04a698 | Size: 40 bytes [LEPUS_CallConstructorV]
// Khung tháo gỡ #1808 | Địa chỉ PC: 0x1ac4bc | Địa chỉ FDE: 0x04a698 | Kích thước: 40 bytes
//   0x1ac4bc: 39458008  ldrb     w8, [x0, #0x160]
//   0x1ac4c0: AA0303E4  mov      x4, x3
//   0x1ac4c4: 2A0203E3  mov      w3, w2
//   0x1ac4c8: 34000088  cbz      w8, #0x1ac4d8
static inline uint64_t fde_func_1808_0x1ac4bc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1ac4bcULL ^ (static_cast<uint64_t>(0x39458008ULL) << 13);
    acc = (acc + a1 + 0xaa0303e4ULL) ^ 0x04a698ULL;
    acc ^= (acc >> 17) * 0x0028ULL;
    return acc;
}

// FDE #1809 | PC: 0x1ac4e4 | FDE: 0x04a6b0 | Size: 196 bytes [LEPUS_CallV]
// Khung tháo gỡ #1809 | Địa chỉ PC: 0x1ac4e4 | Địa chỉ FDE: 0x04a6b0 | Kích thước: 196 bytes
//   0x1ac4e4: A9BD5BF7  stp      x23, x22, [sp, #-0x30]!
//   0x1ac4e8: A90153F5  stp      x21, x20, [sp, #0x10]
//   0x1ac4ec: A9027BF3  stp      x19, x30, [sp, #0x20]
//   0x1ac4f0: 39458008  ldrb     w8, [x0, #0x160]
static inline uint64_t fde_func_1809_0x1ac4e4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1ac4e4ULL ^ (static_cast<uint64_t>(0xa9bd5bf7ULL) << 13);
    acc = (acc + a1 + 0xa90153f5ULL) ^ 0x04a6b0ULL;
    acc ^= (acc >> 17) * 0x00c4ULL;
    return acc;
}

// FDE #1810 | PC: 0x1ac5a8 | FDE: 0x04a6d0 | Size: 12 bytes [LEPUS_IsPrimjsEnabled]
// Khung tháo gỡ #1810 | Địa chỉ PC: 0x1ac5a8 | Địa chỉ FDE: 0x04a6d0 | Kích thước: 12 bytes
//   0x1ac5a8: B4000040  cbz      x0, #0x1ac5b0
//   0x1ac5ac: 39486000  ldrb     w0, [x0, #0x218]
//   0x1ac5b0: D65F03C0  ret      
static inline uint64_t fde_func_1810_0x1ac5a8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1ac5a8ULL ^ (static_cast<uint64_t>(0xb4000040ULL) << 13);
    acc = (acc + a1 + 0x39486000ULL) ^ 0x04a6d0ULL;
    acc ^= (acc >> 17) * 0x000cULL;
    return acc;
}

// FDE #1811 | PC: 0x1ac5b4 | FDE: 0x04a6e8 | Size: 252 bytes [LEPUS_GetTypedArrayBuffer]
// Khung tháo gỡ #1811 | Địa chỉ PC: 0x1ac5b4 | Địa chỉ FDE: 0x04a6e8 | Kích thước: 252 bytes
//   0x1ac5b4: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x1ac5b8: B4000301  cbz      x1, #0x1ac618
//   0x1ac5bc: D2800048  mov      x8, #2
//   0x1ac5c0: F2FFFFE8  movk     x8, #0xffff, lsl #48
static inline uint64_t fde_func_1811_0x1ac5b4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1ac5b4ULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0xb4000301ULL) ^ 0x04a6e8ULL;
    acc ^= (acc >> 17) * 0x00fcULL;
    return acc;
}

// FDE #1812 | PC: 0x1ac6b0 | FDE: 0x04a700 | Size: 76 bytes [LEPUS_GetTypedArrayType]
// Khung tháo gỡ #1812 | Địa chỉ PC: 0x1ac6b0 | Địa chỉ FDE: 0x04a700 | Kích thước: 76 bytes
//   0x1ac6b0: B4000221  cbz      x1, #0x1ac6f4
//   0x1ac6b4: D2800048  mov      x8, #2
//   0x1ac6b8: F2FFFFE8  movk     x8, #0xffff, lsl #48
//   0x1ac6bc: 8A080028  and      x8, x1, x8
static inline uint64_t fde_func_1812_0x1ac6b0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1ac6b0ULL ^ (static_cast<uint64_t>(0xb4000221ULL) << 13);
    acc = (acc + a1 + 0xd2800048ULL) ^ 0x04a700ULL;
    acc ^= (acc >> 17) * 0x004cULL;
    return acc;
}

// FDE #1813 | PC: 0x1ac6fc | FDE: 0x04a718 | Size: 60 bytes [LEPUS_IsDataView]
// Khung tháo gỡ #1813 | Địa chỉ PC: 0x1ac6fc | Địa chỉ FDE: 0x04a718 | Kích thước: 60 bytes
//   0x1ac6fc: 2A1F03E0  mov      w0, wzr
//   0x1ac700: B40001A1  cbz      x1, #0x1ac734
//   0x1ac704: D2800048  mov      x8, #2
//   0x1ac708: F2FFFFE8  movk     x8, #0xffff, lsl #48
static inline uint64_t fde_func_1813_0x1ac6fc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1ac6fcULL ^ (static_cast<uint64_t>(0x2a1f03e0ULL) << 13);
    acc = (acc + a1 + 0xb40001a1ULL) ^ 0x04a718ULL;
    acc ^= (acc >> 17) * 0x003cULL;
    return acc;
}

// FDE #1814 | PC: 0x1ac738 | FDE: 0x04a730 | Size: 16 bytes [LEPUS_GetTypedArrayClassID]
// Khung tháo gỡ #1814 | Địa chỉ PC: 0x1ac738 | Địa chỉ FDE: 0x04a730 | Kích thước: 16 bytes
//   0x1ac738: 11005008  add      w8, w0, #0x14
//   0x1ac73c: 7100001F  cmp      w0, #0
//   0x1ac740: 5A9F1100  csinv    w0, w8, wzr, ne
//   0x1ac744: D65F03C0  ret      
static inline uint64_t fde_func_1814_0x1ac738(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1ac738ULL ^ (static_cast<uint64_t>(0x11005008ULL) << 13);
    acc = (acc + a1 + 0x7100001fULL) ^ 0x04a730ULL;
    acc ^= (acc >> 17) * 0x0010ULL;
    return acc;
}

// FDE #1815 | PC: 0x1ac748 | FDE: 0x04a748 | Size: 256 bytes [LEPUS_DeepCopy]
// Khung tháo gỡ #1815 | Địa chỉ PC: 0x1ac748 | Địa chỉ FDE: 0x04a748 | Kích thước: 256 bytes
//   0x1ac748: D10143FF  sub      sp, sp, #0x50
//   0x1ac74c: A9025BF7  stp      x23, x22, [sp, #0x20]
//   0x1ac750: A90353F5  stp      x21, x20, [sp, #0x30]
//   0x1ac754: A9047BF3  stp      x19, x30, [sp, #0x40]
static inline uint64_t fde_func_1815_0x1ac748(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1ac748ULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xa9025bf7ULL) ^ 0x04a748ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1816 | PC: 0x1ac88c | FDE: 0x04a768 | Size: 256 bytes [LEPUS_NewObjectWithArgs]
// Khung tháo gỡ #1816 | Địa chỉ PC: 0x1ac88c | Địa chỉ FDE: 0x04a768 | Kích thước: 256 bytes
//   0x1ac88c: D10203FF  sub      sp, sp, #0x80
//   0x1ac890: A9026FFC  stp      x28, x27, [sp, #0x20]
//   0x1ac894: A90367FA  stp      x26, x25, [sp, #0x30]
//   0x1ac898: A9045FF8  stp      x24, x23, [sp, #0x40]
static inline uint64_t fde_func_1816_0x1ac88c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1ac88cULL ^ (static_cast<uint64_t>(0xd10203ffULL) << 13);
    acc = (acc + a1 + 0xa9026ffcULL) ^ 0x04a768ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1817 | PC: 0x1acb9c | FDE: 0x04a798 | Size: 256 bytes [LEPUS_NewArrayWithArgs]
// Khung tháo gỡ #1817 | Địa chỉ PC: 0x1acb9c | Địa chỉ FDE: 0x04a798 | Kích thước: 256 bytes
//   0x1acb9c: D10143FF  sub      sp, sp, #0x50
//   0x1acba0: A90163F9  stp      x25, x24, [sp, #0x10]
//   0x1acba4: A9025BF7  stp      x23, x22, [sp, #0x20]
//   0x1acba8: A90353F5  stp      x21, x20, [sp, #0x30]
static inline uint64_t fde_func_1817_0x1acb9c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1acb9cULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xa90163f9ULL) ^ 0x04a798ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1818 | PC: 0x1aced4 | FDE: 0x04a7c0 | Size: 144 bytes [LEPUS_GetStringUtf8]
// Khung tháo gỡ #1818 | Địa chỉ PC: 0x1aced4 | Địa chỉ FDE: 0x04a7c0 | Kích thước: 144 bytes
//   0x1aced4: B9400428  ldr      w8, [x1, #4]
//   0x1aced8: 37F80128  tbnz     w8, #0x1f, #0x1acefc
//   0x1acedc: 72007908  ands     w8, w8, #0x7fffffff
//   0x1acee0: 91006020  add      x0, x1, #0x18
static inline uint64_t fde_func_1818_0x1aced4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1aced4ULL ^ (static_cast<uint64_t>(0xb9400428ULL) << 13);
    acc = (acc + a1 + 0x37f80128ULL) ^ 0x04a7c0ULL;
    acc ^= (acc >> 17) * 0x0090ULL;
    return acc;
}

// FDE #1819 | PC: 0x1acf64 | FDE: 0x04a7d8 | Size: 156 bytes [SetLynxTargetSdkVersion]
// Khung tháo gỡ #1819 | Địa chỉ PC: 0x1acf64 | Địa chỉ FDE: 0x04a7d8 | Kích thước: 156 bytes
//   0x1acf64: A9BE53F5  stp      x21, x20, [sp, #-0x20]!
//   0x1acf68: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x1acf6c: B40002E1  cbz      x1, #0x1acfc8
//   0x1acf70: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_1819_0x1acf64(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1acf64ULL ^ (static_cast<uint64_t>(0xa9be53f5ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x04a7d8ULL;
    acc ^= (acc >> 17) * 0x009cULL;
    return acc;
}

// FDE #1820 | PC: 0x1ad000 | FDE: 0x04a7f8 | Size: 12 bytes [_Z19SetDebugInfoOutsideP12LEPUSContextb]
// Khung tháo gỡ #1820 | Địa chỉ PC: 0x1ad000 | Địa chỉ FDE: 0x04a7f8 | Kích thước: 12 bytes
//   0x1ad000: 12000028  and      w8, w1, #1
//   0x1ad004: 39048008  strb     w8, [x0, #0x120]
//   0x1ad008: D65F03C0  ret      
static inline uint64_t fde_func_1820_0x1ad000(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1ad000ULL ^ (static_cast<uint64_t>(0x12000028ULL) << 13);
    acc = (acc + a1 + 0x39048008ULL) ^ 0x04a7f8ULL;
    acc ^= (acc >> 17) * 0x000cULL;
    return acc;
}

// FDE #1821 | PC: 0x1ad00c | FDE: 0x04a810 | Size: 200 bytes [AllocateQJSValueValue]
// Khung tháo gỡ #1821 | Địa chỉ PC: 0x1ad00c | Địa chỉ FDE: 0x04a810 | Kích thước: 200 bytes
//   0x1ad00c: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x1ad010: F9418408  ldr      x8, [x0, #0x308]
//   0x1ad014: F9400513  ldr      x19, [x8, #8]
//   0x1ad018: F9400E60  ldr      x0, [x19, #0x18]
static inline uint64_t fde_func_1821_0x1ad00c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1ad00cULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0xf9418408ULL) ^ 0x04a810ULL;
    acc ^= (acc >> 17) * 0x00c8ULL;
    return acc;
}

// FDE #1822 | PC: 0x1ad0d4 | FDE: 0x04a828 | Size: 116 bytes [FreeQJSValueValue]
// Khung tháo gỡ #1822 | Địa chỉ PC: 0x1ad0d4 | Địa chỉ FDE: 0x04a828 | Kích thước: 116 bytes
//   0x1ad0d4: 3940C428  ldrb     w8, [x1, #0x31]
//   0x1ad0d8: 5288050A  mov      w10, #0x4028
//   0x1ad0dc: CB081828  sub      x8, x1, x8, lsl #6
//   0x1ad0e0: F9600908  ldr      x8, [x8, #0x4010]
static inline uint64_t fde_func_1822_0x1ad0d4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1ad0d4ULL ^ (static_cast<uint64_t>(0x3940c428ULL) << 13);
    acc = (acc + a1 + 0x5288050aULL) ^ 0x04a828ULL;
    acc ^= (acc >> 17) * 0x0074ULL;
    return acc;
}

// FDE #1823 | PC: 0x1ad148 | FDE: 0x04a840 | Size: 28 bytes [ClearGlobalWeak]
// Khung tháo gỡ #1823 | Địa chỉ PC: 0x1ad148 | Địa chỉ FDE: 0x04a840 | Kích thước: 28 bytes
//   0x1ad148: 394CC008  ldrb     w8, [x0, #0x330]
//   0x1ad14c: 340000A8  cbz      w8, #0x1ad160
//   0x1ad150: B4000081  cbz      x1, #0x1ad160
//   0x1ad154: 52800028  mov      w8, #1
static inline uint64_t fde_func_1823_0x1ad148(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1ad148ULL ^ (static_cast<uint64_t>(0x394cc008ULL) << 13);
    acc = (acc + a1 + 0x340000a8ULL) ^ 0x04a840ULL;
    acc ^= (acc >> 17) * 0x001cULL;
    return acc;
}

// FDE #1824 | PC: 0x1ad164 | FDE: 0x04a858 | Size: 28 bytes [SetGlobalWeak]
// Khung tháo gỡ #1824 | Địa chỉ PC: 0x1ad164 | Địa chỉ FDE: 0x04a858 | Kích thước: 28 bytes
//   0x1ad164: 394CC008  ldrb     w8, [x0, #0x330]
//   0x1ad168: 340000A8  cbz      w8, #0x1ad17c
//   0x1ad16c: B4000081  cbz      x1, #0x1ad17c
//   0x1ad170: 52800048  mov      w8, #2
static inline uint64_t fde_func_1824_0x1ad164(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1ad164ULL ^ (static_cast<uint64_t>(0x394cc008ULL) << 13);
    acc = (acc + a1 + 0x340000a8ULL) ^ 0x04a858ULL;
    acc ^= (acc >> 17) * 0x001cULL;
    return acc;
}

// FDE #1825 | PC: 0x1ad180 | FDE: 0x04a870 | Size: 24 bytes [GetNapiScope]
// Khung tháo gỡ #1825 | Địa chỉ PC: 0x1ad180 | Địa chỉ FDE: 0x04a870 | Kích thước: 24 bytes
//   0x1ad180: 39458008  ldrb     w8, [x0, #0x160]
//   0x1ad184: 34000068  cbz      w8, #0x1ad190
//   0x1ad188: F940A400  ldr      x0, [x0, #0x148]
//   0x1ad18c: D65F03C0  ret      
static inline uint64_t fde_func_1825_0x1ad180(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1ad180ULL ^ (static_cast<uint64_t>(0x39458008ULL) << 13);
    acc = (acc + a1 + 0x34000068ULL) ^ 0x04a870ULL;
    acc ^= (acc >> 17) * 0x0018ULL;
    return acc;
}

// FDE #1826 | PC: 0x1ad198 | FDE: 0x04a888 | Size: 64 bytes [InitNapiScope]
// Khung tháo gỡ #1826 | Địa chỉ PC: 0x1ad198 | Địa chỉ FDE: 0x04a888 | Kích thước: 64 bytes
//   0x1ad198: F81E0FF4  str      x20, [sp, #-0x20]!
//   0x1ad19c: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x1ad1a0: 39458014  ldrb     w20, [x0, #0x160]
//   0x1ad1a4: 34000154  cbz      w20, #0x1ad1cc
static inline uint64_t fde_func_1826_0x1ad198(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1ad198ULL ^ (static_cast<uint64_t>(0xf81e0ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x04a888ULL;
    acc ^= (acc >> 17) * 0x0040ULL;
    return acc;
}

// FDE #1827 | PC: 0x1ad1d8 | FDE: 0x04a8a8 | Size: 256 bytes [FreeNapiScope]
// Khung tháo gỡ #1827 | Địa chỉ PC: 0x1ad1d8 | Địa chỉ FDE: 0x04a8a8 | Kích thước: 256 bytes
//   0x1ad1d8: A9BA6FFC  stp      x28, x27, [sp, #-0x60]!
//   0x1ad1dc: A90167FA  stp      x26, x25, [sp, #0x10]
//   0x1ad1e0: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x1ad1e4: A90357F6  stp      x22, x21, [sp, #0x30]
static inline uint64_t fde_func_1827_0x1ad1d8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1ad1d8ULL ^ (static_cast<uint64_t>(0xa9ba6ffcULL) << 13);
    acc = (acc + a1 + 0xa90167faULL) ^ 0x04a8a8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1828 | PC: 0x1ad32c | FDE: 0x04a8d8 | Size: 16 bytes [SetNapiScope]
// Khung tháo gỡ #1828 | Địa chỉ PC: 0x1ad32c | Địa chỉ FDE: 0x04a8d8 | Kích thước: 16 bytes
//   0x1ad32c: 39458008  ldrb     w8, [x0, #0x160]
//   0x1ad330: 34000048  cbz      w8, #0x1ad338
//   0x1ad334: F900A401  str      x1, [x0, #0x148]
//   0x1ad338: D65F03C0  ret      
static inline uint64_t fde_func_1828_0x1ad32c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1ad32cULL ^ (static_cast<uint64_t>(0x39458008ULL) << 13);
    acc = (acc + a1 + 0x34000048ULL) ^ 0x04a8d8ULL;
    acc ^= (acc >> 17) * 0x0010ULL;
    return acc;
}

// FDE #1829 | PC: 0x1ad33c | FDE: 0x04a8f0 | Size: 24 bytes [SetWeakState]
// Khung tháo gỡ #1829 | Địa chỉ PC: 0x1ad33c | Địa chỉ FDE: 0x04a8f0 | Kích thước: 24 bytes
//   0x1ad33c: 394CC008  ldrb     w8, [x0, #0x330]
//   0x1ad340: 34000088  cbz      w8, #0x1ad350
//   0x1ad344: B4000061  cbz      x1, #0x1ad350
//   0x1ad348: 52800048  mov      w8, #2
static inline uint64_t fde_func_1829_0x1ad33c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1ad33cULL ^ (static_cast<uint64_t>(0x394cc008ULL) << 13);
    acc = (acc + a1 + 0x34000088ULL) ^ 0x04a8f0ULL;
    acc ^= (acc >> 17) * 0x0018ULL;
    return acc;
}

// FDE #1830 | PC: 0x1ad354 | FDE: 0x04a908 | Size: 24 bytes [LEPUS_SetGCPauseSuppressionMode]
// Khung tháo gỡ #1830 | Địa chỉ PC: 0x1ad354 | Địa chỉ FDE: 0x04a908 | Kích thước: 24 bytes
//   0x1ad354: 394CC008  ldrb     w8, [x0, #0x330]
//   0x1ad358: 34000088  cbz      w8, #0x1ad368
//   0x1ad35c: F9418C08  ldr      x8, [x0, #0x318]
//   0x1ad360: 12000029  and      w9, w1, #1
static inline uint64_t fde_func_1830_0x1ad354(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1ad354ULL ^ (static_cast<uint64_t>(0x394cc008ULL) << 13);
    acc = (acc + a1 + 0x34000088ULL) ^ 0x04a908ULL;
    acc ^= (acc >> 17) * 0x0018ULL;
    return acc;
}

// FDE #1831 | PC: 0x1ad36c | FDE: 0x04a920 | Size: 36 bytes [LEPUS_GetGCPauseSuppressionMode]
// Khung tháo gỡ #1831 | Địa chỉ PC: 0x1ad36c | Địa chỉ FDE: 0x04a920 | Kích thước: 36 bytes
//   0x1ad36c: 394CC008  ldrb     w8, [x0, #0x330]
//   0x1ad370: 340000C8  cbz      w8, #0x1ad388
//   0x1ad374: F9418C08  ldr      x8, [x0, #0x318]
//   0x1ad378: 39405108  ldrb     w8, [x8, #0x14]
static inline uint64_t fde_func_1831_0x1ad36c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1ad36cULL ^ (static_cast<uint64_t>(0x394cc008ULL) << 13);
    acc = (acc + a1 + 0x340000c8ULL) ^ 0x04a920ULL;
    acc ^= (acc >> 17) * 0x0024ULL;
    return acc;
}

// FDE #1832 | PC: 0x1ad390 | FDE: 0x04a938 | Size: 8 bytes [CheckValidPtr]
// Khung tháo gỡ #1832 | Địa chỉ PC: 0x1ad390 | Địa chỉ FDE: 0x04a938 | Kích thước: 8 bytes
//   0x1ad390: 52800020  mov      w0, #1
//   0x1ad394: D65F03C0  ret      
static inline uint64_t fde_func_1832_0x1ad390(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1ad390ULL ^ (static_cast<uint64_t>(0x52800020ULL) << 13);
    acc = (acc + a1 + 0xd65f03c0ULL) ^ 0x04a938ULL;
    acc ^= (acc >> 17) * 0x0008ULL;
    return acc;
}

// FDE #1833 | PC: 0x1ad398 | FDE: 0x04a950 | Size: 256 bytes [LEPUS_SetFuncFileName]
// Khung tháo gỡ #1833 | Địa chỉ PC: 0x1ad398 | Địa chỉ FDE: 0x04a950 | Kích thước: 256 bytes
//   0x1ad398: D10203FF  sub      sp, sp, #0x80
//   0x1ad39c: A9026FFC  stp      x28, x27, [sp, #0x20]
//   0x1ad3a0: A90367FA  stp      x26, x25, [sp, #0x30]
//   0x1ad3a4: A9045FF8  stp      x24, x23, [sp, #0x40]
static inline uint64_t fde_func_1833_0x1ad398(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1ad398ULL ^ (static_cast<uint64_t>(0xd10203ffULL) << 13);
    acc = (acc + a1 + 0xa9026ffcULL) ^ 0x04a950ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1834 | PC: 0x1ad660 | FDE: 0x04a980 | Size: 16 bytes [InitLynxTraceEnv]
// Khung tháo gỡ #1834 | Địa chỉ PC: 0x1ad660 | Địa chỉ FDE: 0x04a980 | Kích thước: 16 bytes
//   0x1ad660: 90000088  adrp     x8, #0x1bd000
//   0x1ad664: F9412D08  ldr      x8, [x8, #0x258]
//   0x1ad668: A9000500  stp      x0, x1, [x8]
//   0x1ad66c: D65F03C0  ret      
static inline uint64_t fde_func_1834_0x1ad660(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1ad660ULL ^ (static_cast<uint64_t>(0x90000088ULL) << 13);
    acc = (acc + a1 + 0xf9412d08ULL) ^ 0x04a980ULL;
    acc ^= (acc >> 17) * 0x0010ULL;
    return acc;
}

// FDE #1835 | PC: 0x1ad670 | FDE: 0x04a998 | Size: 204 bytes [SetObjectCtxCheckStatus]
// Khung tháo gỡ #1835 | Địa chỉ PC: 0x1ad670 | Địa chỉ FDE: 0x04a998 | Kích thước: 204 bytes
//   0x1ad670: A9BE53F5  stp      x21, x20, [sp, #-0x20]!
//   0x1ad674: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x1ad678: F9400808  ldr      x8, [x0, #0x10]
//   0x1ad67c: 12000029  and      w9, w1, #1
static inline uint64_t fde_func_1835_0x1ad670(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1ad670ULL ^ (static_cast<uint64_t>(0xa9be53f5ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x04a998ULL;
    acc ^= (acc >> 17) * 0x00ccULL;
    return acc;
}

// FDE #1836 | PC: 0x1ad73c | FDE: 0x04a9b8 | Size: 176 bytes [LEPUS_PushObjectCheckTid]
// Khung tháo gỡ #1836 | Địa chỉ PC: 0x1ad73c | Địa chỉ FDE: 0x04a9b8 | Kích thước: 176 bytes
//   0x1ad73c: A9BE53F5  stp      x21, x20, [sp, #-0x20]!
//   0x1ad740: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x1ad744: 39458808  ldrb     w8, [x0, #0x162]
//   0x1ad748: 34000288  cbz      w8, #0x1ad798
static inline uint64_t fde_func_1836_0x1ad73c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1ad73cULL ^ (static_cast<uint64_t>(0xa9be53f5ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x04a9b8ULL;
    acc ^= (acc >> 17) * 0x00b0ULL;
    return acc;
}

// FDE #1837 | PC: 0x1ad7ec | FDE: 0x04a9d8 | Size: 60 bytes [UpdateOuterObjSize]
// Khung tháo gỡ #1837 | Địa chỉ PC: 0x1ad7ec | Địa chỉ FDE: 0x04a9d8 | Kích thước: 60 bytes
//   0x1ad7ec: 340001C1  cbz      w1, #0x1ad824
//   0x1ad7f0: 394CC008  ldrb     w8, [x0, #0x330]
//   0x1ad7f4: 34000188  cbz      w8, #0x1ad824
//   0x1ad7f8: F9422408  ldr      x8, [x0, #0x448]
static inline uint64_t fde_func_1837_0x1ad7ec(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1ad7ecULL ^ (static_cast<uint64_t>(0x340001c1ULL) << 13);
    acc = (acc + a1 + 0x394cc008ULL) ^ 0x04a9d8ULL;
    acc ^= (acc >> 17) * 0x003cULL;
    return acc;
}

// FDE #1838 | PC: 0x1ad828 | FDE: 0x04a9f0 | Size: 36 bytes [_Z24NapiAdjustExternalMemoryP12LEPUSRuntimel]
// Khung tháo gỡ #1838 | Địa chỉ PC: 0x1ad828 | Địa chỉ FDE: 0x04a9f0 | Kích thước: 36 bytes
//   0x1ad828: 394CC009  ldrb     w9, [x0, #0x330]
//   0x1ad82c: 340000C9  cbz      w9, #0x1ad844
//   0x1ad830: F9422409  ldr      x9, [x0, #0x448]
//   0x1ad834: AA0003E8  mov      x8, x0
static inline uint64_t fde_func_1838_0x1ad828(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1ad828ULL ^ (static_cast<uint64_t>(0x394cc009ULL) << 13);
    acc = (acc + a1 + 0x340000c9ULL) ^ 0x04a9f0ULL;
    acc ^= (acc >> 17) * 0x0024ULL;
    return acc;
}

// FDE #1839 | PC: 0x1ad84c | FDE: 0x04aa08 | Size: 8 bytes [LEPUS_SetGCObserver]
// Khung tháo gỡ #1839 | Địa chỉ PC: 0x1ad84c | Địa chỉ FDE: 0x04aa08 | Kích thước: 8 bytes
//   0x1ad84c: F9029C01  str      x1, [x0, #0x538]
//   0x1ad850: D65F03C0  ret      
static inline uint64_t fde_func_1839_0x1ad84c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1ad84cULL ^ (static_cast<uint64_t>(0xf9029c01ULL) << 13);
    acc = (acc + a1 + 0xd65f03c0ULL) ^ 0x04aa08ULL;
    acc ^= (acc >> 17) * 0x0008ULL;
    return acc;
}

// FDE #1840 | PC: 0x1ad854 | FDE: 0x04aa20 | Size: 8 bytes [LEPUS_GetGCObserver]
// Khung tháo gỡ #1840 | Địa chỉ PC: 0x1ad854 | Địa chỉ FDE: 0x04aa20 | Kích thước: 8 bytes
//   0x1ad854: F9429C00  ldr      x0, [x0, #0x538]
//   0x1ad858: D65F03C0  ret      
static inline uint64_t fde_func_1840_0x1ad854(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1ad854ULL ^ (static_cast<uint64_t>(0xf9429c00ULL) << 13);
    acc = (acc + a1 + 0xd65f03c0ULL) ^ 0x04aa20ULL;
    acc ^= (acc >> 17) * 0x0008ULL;
    return acc;
}

// FDE #1841 | PC: 0x1ad85c | FDE: 0x04aa38 | Size: 12 bytes [_ZN5vmsdk7general7android6InitVMEP7_JavaVM]
// Khung tháo gỡ #1841 | Địa chỉ PC: 0x1ad85c | Địa chỉ FDE: 0x04aa38 | Kích thước: 12 bytes
//   0x1ad85c: 900000A8  adrp     x8, #0x1c1000
//   0x1ad860: F9079900  str      x0, [x8, #0xf30]
//   0x1ad864: D65F03C0  ret      
static inline uint64_t fde_func_1841_0x1ad85c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1ad85cULL ^ (static_cast<uint64_t>(0x900000a8ULL) << 13);
    acc = (acc + a1 + 0xf9079900ULL) ^ 0x04aa38ULL;
    acc ^= (acc >> 17) * 0x000cULL;
    return acc;
}

// FDE #1842 | PC: 0x1ad868 | FDE: 0x04aa50 | Size: 192 bytes [_ZN5vmsdk7general7android19AttachCurrentThreadEv]
// Khung tháo gỡ #1842 | Địa chỉ PC: 0x1ad868 | Địa chỉ FDE: 0x04aa50 | Kích thước: 192 bytes
//   0x1ad868: D10183FF  sub      sp, sp, #0x60
//   0x1ad86c: A90453F5  stp      x21, x20, [sp, #0x40]
//   0x1ad870: A9057BF3  stp      x19, x30, [sp, #0x50]
//   0x1ad874: D53BD053  mrs      x19, tpidr_el0
static inline uint64_t fde_func_1842_0x1ad868(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1ad868ULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xa90453f5ULL) ^ 0x04aa50ULL;
    acc ^= (acc >> 17) * 0x00c0ULL;
    return acc;
}

// FDE #1843 | PC: 0x1ad928 | FDE: 0x04aa70 | Size: 28 bytes [_ZN5vmsdk7general7android12DetachFromVMEv]
// Khung tháo gỡ #1843 | Địa chỉ PC: 0x1ad928 | Địa chỉ FDE: 0x04aa70 | Kích thước: 28 bytes
//   0x1ad928: 900000A8  adrp     x8, #0x1c1000
//   0x1ad92c: F9479900  ldr      x0, [x8, #0xf30]
//   0x1ad930: B4000080  cbz      x0, #0x1ad940
//   0x1ad934: F9400008  ldr      x8, [x0]
static inline uint64_t fde_func_1843_0x1ad928(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1ad928ULL ^ (static_cast<uint64_t>(0x900000a8ULL) << 13);
    acc = (acc + a1 + 0xf9479900ULL) ^ 0x04aa70ULL;
    acc ^= (acc >> 17) * 0x001cULL;
    return acc;
}

// FDE #1844 | PC: 0x1ad944 | FDE: 0x04aa88 | Size: 88 bytes [_ZN5vmsdk7general7android8GetClassEP7_JNIEnvPKc]
// Khung tháo gỡ #1844 | Địa chỉ PC: 0x1ad944 | Địa chỉ FDE: 0x04aa88 | Kích thước: 88 bytes
//   0x1ad944: F81E0FF4  str      x20, [sp, #-0x20]!
//   0x1ad948: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x1ad94c: F9400009  ldr      x9, [x0]
//   0x1ad950: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_1844_0x1ad944(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1ad944ULL ^ (static_cast<uint64_t>(0xf81e0ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x04aa88ULL;
    acc ^= (acc >> 17) * 0x0058ULL;
    return acc;
}

// FDE #1845 | PC: 0x1ad99c | FDE: 0x04aaa8 | Size: 8 bytes
// Khung tháo gỡ #1845 | Địa chỉ PC: 0x1ad99c | Địa chỉ FDE: 0x04aaa8 | Kích thước: 8 bytes
//   0x1ad99c: F9400400  ldr      x0, [x0, #8]
//   0x1ad9a0: D65F03C0  ret      
static inline uint64_t fde_func_1845_0x1ad99c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1ad99cULL ^ (static_cast<uint64_t>(0xf9400400ULL) << 13);
    acc = (acc + a1 + 0xd65f03c0ULL) ^ 0x04aaa8ULL;
    acc ^= (acc >> 17) * 0x0008ULL;
    return acc;
}

// FDE #1846 | PC: 0x1ad9a4 | FDE: 0x04aac0 | Size: 4 bytes
// Khung tháo gỡ #1846 | Địa chỉ PC: 0x1ad9a4 | Địa chỉ FDE: 0x04aac0 | Kích thước: 4 bytes
//   0x1ad9a4: 14000460  b        #0x1aeb24
static inline uint64_t fde_func_1846_0x1ad9a4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1ad9a4ULL ^ (static_cast<uint64_t>(0x14000460ULL) << 13);
    acc = (acc + a1 + 0xd101c3ffULL) ^ 0x04aac0ULL;
    acc ^= (acc >> 17) * 0x0004ULL;
    return acc;
}

// FDE #1847 | PC: 0x1ad9a8 | FDE: 0x04aad8 | Size: 252 bytes [_ZN5vmsdk7general7android7JavaRefIP8_jobjectE15ReleaseLocalRefEP7_JNIEnv]
// Khung tháo gỡ #1847 | Địa chỉ PC: 0x1ad9a8 | Địa chỉ FDE: 0x04aad8 | Kích thước: 252 bytes
//   0x1ad9a8: D101C3FF  sub      sp, sp, #0x70
//   0x1ad9ac: F90023F6  str      x22, [sp, #0x40]
//   0x1ad9b0: A90553F5  stp      x21, x20, [sp, #0x50]
//   0x1ad9b4: A9067BF3  stp      x19, x30, [sp, #0x60]
static inline uint64_t fde_func_1847_0x1ad9a8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1ad9a8ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xf90023f6ULL) ^ 0x04aad8ULL;
    acc ^= (acc >> 17) * 0x00fcULL;
    return acc;
}

// FDE #1848 | PC: 0x1adaa4 | FDE: 0x04aaf8 | Size: 4 bytes
// Khung tháo gỡ #1848 | Địa chỉ PC: 0x1adaa4 | Địa chỉ FDE: 0x04aaf8 | Kích thước: 4 bytes
//   0x1adaa4: 1400046B  b        #0x1aec50
static inline uint64_t fde_func_1848_0x1adaa4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1adaa4ULL ^ (static_cast<uint64_t>(0x1400046bULL) << 13);
    acc = (acc + a1 + 0x140004f8ULL) ^ 0x04aaf8ULL;
    acc ^= (acc >> 17) * 0x0004ULL;
    return acc;
}

// FDE #1849 | PC: 0x1adaa8 | FDE: 0x04ab10 | Size: 4 bytes
// Khung tháo gỡ #1849 | Địa chỉ PC: 0x1adaa8 | Địa chỉ FDE: 0x04ab10 | Kích thước: 4 bytes
//   0x1adaa8: 140004F8  b        #0x1aee88
static inline uint64_t fde_func_1849_0x1adaa8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1adaa8ULL ^ (static_cast<uint64_t>(0x140004f8ULL) << 13);
    acc = (acc + a1 + 0x1400055aULL) ^ 0x04ab10ULL;
    acc ^= (acc >> 17) * 0x0004ULL;
    return acc;
}

// FDE #1850 | PC: 0x1adaac | FDE: 0x04ab28 | Size: 4 bytes
// Khung tháo gỡ #1850 | Địa chỉ PC: 0x1adaac | Địa chỉ FDE: 0x04ab28 | Kích thước: 4 bytes
//   0x1adaac: 1400055A  b        #0x1af014
static inline uint64_t fde_func_1850_0x1adaac(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1adaacULL ^ (static_cast<uint64_t>(0x1400055aULL) << 13);
    acc = (acc + a1 + 0xd101c3ffULL) ^ 0x04ab28ULL;
    acc ^= (acc >> 17) * 0x0004ULL;
    return acc;
}

// FDE #1851 | PC: 0x1adab0 | FDE: 0x04ab40 | Size: 252 bytes [_ZN5vmsdk7general7android7JavaRefIP8_jobjectE20ReleaseWeakGlobalRefEP7_JNIEnv]
// Khung tháo gỡ #1851 | Địa chỉ PC: 0x1adab0 | Địa chỉ FDE: 0x04ab40 | Kích thước: 252 bytes
//   0x1adab0: D101C3FF  sub      sp, sp, #0x70
//   0x1adab4: F90023F6  str      x22, [sp, #0x40]
//   0x1adab8: A90553F5  stp      x21, x20, [sp, #0x50]
//   0x1adabc: A9067BF3  stp      x19, x30, [sp, #0x60]
static inline uint64_t fde_func_1851_0x1adab0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1adab0ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xf90023f6ULL) ^ 0x04ab40ULL;
    acc ^= (acc >> 17) * 0x00fcULL;
    return acc;
}

// FDE #1852 | PC: 0x1adbac | FDE: 0x04ab60 | Size: 16 bytes
// Khung tháo gỡ #1852 | Địa chỉ PC: 0x1adbac | Địa chỉ FDE: 0x04ab60 | Kích thước: 16 bytes
//   0x1adbac: F9400408  ldr      x8, [x0, #8]
//   0x1adbb0: F900041F  str      xzr, [x0, #8]
//   0x1adbb4: AA0803E0  mov      x0, x8
//   0x1adbb8: D65F03C0  ret      
static inline uint64_t fde_func_1852_0x1adbac(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1adbacULL ^ (static_cast<uint64_t>(0xf9400408ULL) << 13);
    acc = (acc + a1 + 0xf900041fULL) ^ 0x04ab60ULL;
    acc ^= (acc >> 17) * 0x0010ULL;
    return acc;
}

// FDE #1853 | PC: 0x1adbbc | FDE: 0x04ab78 | Size: 100 bytes [_ZN5vmsdk7general7android14GetGlobalClassEP7_JNIEnvPKc]
// Khung tháo gỡ #1853 | Địa chỉ PC: 0x1adbbc | Địa chỉ FDE: 0x04ab78 | Kích thước: 100 bytes
//   0x1adbbc: A9BE53F5  stp      x21, x20, [sp, #-0x20]!
//   0x1adbc0: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x1adbc4: F9400009  ldr      x9, [x0]
//   0x1adbc8: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_1853_0x1adbbc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1adbbcULL ^ (static_cast<uint64_t>(0xa9be53f5ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x04ab78ULL;
    acc ^= (acc >> 17) * 0x0064ULL;
    return acc;
}

// FDE #1854 | PC: 0x1adc20 | FDE: 0x04ab98 | Size: 56 bytes [_ZN5vmsdk7general7android9GetMethodEP7_JNIEnvP7_jclassNS1_10MethodTypeEPKcS8_]
// Khung tháo gỡ #1854 | Địa chỉ PC: 0x1adc20 | Địa chỉ FDE: 0x04ab98 | Kích thước: 56 bytes
//   0x1adc20: B40000E1  cbz      x1, #0x1adc3c
//   0x1adc24: 7100045F  cmp      w2, #1
//   0x1adc28: 540000E0  b.eq     #0x1adc44
//   0x1adc2c: 35000082  cbnz     w2, #0x1adc3c
static inline uint64_t fde_func_1854_0x1adc20(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1adc20ULL ^ (static_cast<uint64_t>(0xb40000e1ULL) << 13);
    acc = (acc + a1 + 0x7100045fULL) ^ 0x04ab98ULL;
    acc ^= (acc >> 17) * 0x0038ULL;
    return acc;
}

// FDE #1855 | PC: 0x1adc58 | FDE: 0x04abb0 | Size: 92 bytes [_ZN5vmsdk7general7android9GetMethodEP7_JNIEnvP7_jclassNS1_10MethodTypeEPKcS8_Pl]
// Khung tháo gỡ #1855 | Địa chỉ PC: 0x1adc58 | Địa chỉ FDE: 0x04abb0 | Kích thước: 92 bytes
//   0x1adc58: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x1adc5c: F94000A8  ldr      x8, [x5]
//   0x1adc60: B5000248  cbnz     x8, #0x1adca8
//   0x1adc64: AA0503F3  mov      x19, x5
static inline uint64_t fde_func_1855_0x1adc58(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1adc58ULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0xf94000a8ULL) ^ 0x04abb0ULL;
    acc ^= (acc >> 17) * 0x005cULL;
    return acc;
}

// FDE #1856 | PC: 0x1adcb4 | FDE: 0x04abc8 | Size: 32 bytes [_ZN5vmsdk7general7android12HasExceptionEP7_JNIEnv]
// Khung tháo gỡ #1856 | Địa chỉ PC: 0x1adcb4 | Địa chỉ FDE: 0x04abc8 | Kích thước: 32 bytes
//   0x1adcb4: F81F0FFE  str      x30, [sp, #-0x10]!
//   0x1adcb8: F9400008  ldr      x8, [x0]
//   0x1adcbc: F9439108  ldr      x8, [x8, #0x720]
//   0x1adcc0: D63F0100  blr      x8
static inline uint64_t fde_func_1856_0x1adcb4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1adcb4ULL ^ (static_cast<uint64_t>(0xf81f0ffeULL) << 13);
    acc = (acc + a1 + 0xf9400008ULL) ^ 0x04abc8ULL;
    acc ^= (acc >> 17) * 0x0020ULL;
    return acc;
}

// FDE #1857 | PC: 0x1adcd4 | FDE: 0x04abe0 | Size: 84 bytes [_ZN5vmsdk7general7android14ClearExceptionEP7_JNIEnv]
// Khung tháo gỡ #1857 | Địa chỉ PC: 0x1adcd4 | Địa chỉ FDE: 0x04abe0 | Kích thước: 84 bytes
//   0x1adcd4: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x1adcd8: F9400008  ldr      x8, [x0]
//   0x1adcdc: AA0003F3  mov      x19, x0
//   0x1adce0: F9439108  ldr      x8, [x8, #0x720]
static inline uint64_t fde_func_1857_0x1adcd4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1adcd4ULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0xf9400008ULL) ^ 0x04abe0ULL;
    acc ^= (acc >> 17) * 0x0054ULL;
    return acc;
}

// FDE #1858 | PC: 0x1add28 | FDE: 0x04abf8 | Size: 256 bytes
// Khung tháo gỡ #1858 | Địa chỉ PC: 0x1add28 | Địa chỉ FDE: 0x04abf8 | Kích thước: 256 bytes
//   0x1add28: D105C3FF  sub      sp, sp, #0x170
//   0x1add2c: A9116FFC  stp      x28, x27, [sp, #0x110]
//   0x1add30: A91267FA  stp      x26, x25, [sp, #0x120]
//   0x1add34: A9135FF8  stp      x24, x23, [sp, #0x130]
static inline uint64_t fde_func_1858_0x1add28(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1add28ULL ^ (static_cast<uint64_t>(0xd105c3ffULL) << 13);
    acc = (acc + a1 + 0xa9116ffcULL) ^ 0x04abf8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1859 | PC: 0x1ae40c | FDE: 0x04ac28 | Size: 152 bytes
// Khung tháo gỡ #1859 | Địa chỉ PC: 0x1ae40c | Địa chỉ FDE: 0x04ac28 | Kích thước: 152 bytes
//   0x1ae40c: D10483FF  sub      sp, sp, #0x120
//   0x1ae410: F90083FC  str      x28, [sp, #0x100]
//   0x1ae414: A9117BF3  stp      x19, x30, [sp, #0x110]
//   0x1ae418: A90893E3  stp      x3, x4, [sp, #0x88]
static inline uint64_t fde_func_1859_0x1ae40c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1ae40cULL ^ (static_cast<uint64_t>(0xd10483ffULL) << 13);
    acc = (acc + a1 + 0xf90083fcULL) ^ 0x04ac28ULL;
    acc ^= (acc >> 17) * 0x0098ULL;
    return acc;
}

// FDE #1860 | PC: 0x1ae4a4 | FDE: 0x04ac48 | Size: 192 bytes
// Khung tháo gỡ #1860 | Địa chỉ PC: 0x1ae4a4 | Địa chỉ FDE: 0x04ac48 | Kích thước: 192 bytes
//   0x1ae4a4: F81D0FF6  str      x22, [sp, #-0x30]!
//   0x1ae4a8: A90153F5  stp      x21, x20, [sp, #0x10]
//   0x1ae4ac: A9027BF3  stp      x19, x30, [sp, #0x20]
//   0x1ae4b0: 39400008  ldrb     w8, [x0]
static inline uint64_t fde_func_1860_0x1ae4a4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1ae4a4ULL ^ (static_cast<uint64_t>(0xf81d0ff6ULL) << 13);
    acc = (acc + a1 + 0xa90153f5ULL) ^ 0x04ac48ULL;
    acc ^= (acc >> 17) * 0x00c0ULL;
    return acc;
}

// FDE #1861 | PC: 0x1ae564 | FDE: 0x04ac68 | Size: 256 bytes [_ZN5vmsdk7general7android14CheckExceptionEP7_JNIEnv]
// Khung tháo gỡ #1861 | Địa chỉ PC: 0x1ae564 | Địa chỉ FDE: 0x04ac68 | Kích thước: 256 bytes
//   0x1ae564: D10283FF  sub      sp, sp, #0xa0
//   0x1ae568: A9075BF7  stp      x23, x22, [sp, #0x70]
//   0x1ae56c: A90853F5  stp      x21, x20, [sp, #0x80]
//   0x1ae570: A9097BF3  stp      x19, x30, [sp, #0x90]
static inline uint64_t fde_func_1861_0x1ae564(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1ae564ULL ^ (static_cast<uint64_t>(0xd10283ffULL) << 13);
    acc = (acc + a1 + 0xa9075bf7ULL) ^ 0x04ac68ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1862 | PC: 0x1aea9c | FDE: 0x04ac90 | Size: 72 bytes
// Khung tháo gỡ #1862 | Địa chỉ PC: 0x1aea9c | Địa chỉ FDE: 0x04ac90 | Kích thước: 72 bytes
//   0x1aea9c: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x1aeaa0: D0000068  adrp     x8, #0x1bc000
//   0x1aeaa4: 91326108  add      x8, x8, #0xc98
//   0x1aeaa8: AA1F03E1  mov      x1, xzr
static inline uint64_t fde_func_1862_0x1aea9c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1aea9cULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0xd0000068ULL) ^ 0x04ac90ULL;
    acc ^= (acc >> 17) * 0x0048ULL;
    return acc;
}

// FDE #1863 | PC: 0x1aeae4 | FDE: 0x04acc8 | Size: 4 bytes
// Khung tháo gỡ #1863 | Địa chỉ PC: 0x1aeae4 | Địa chỉ FDE: 0x04acc8 | Kích thước: 4 bytes
//   0x1aeae4: 140008E3  b        #0x1b0e70
static inline uint64_t fde_func_1863_0x1aeae4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1aeae4ULL ^ (static_cast<uint64_t>(0x140008e3ULL) << 13);
    acc = (acc + a1 + 0xaa0003e8ULL) ^ 0x04acc8ULL;
    acc ^= (acc >> 17) * 0x0004ULL;
    return acc;
}

// FDE #1864 | PC: 0x1aeae8 | FDE: 0x04ace0 | Size: 24 bytes
// Khung tháo gỡ #1864 | Địa chỉ PC: 0x1aeae8 | Địa chỉ FDE: 0x04ace0 | Kích thước: 24 bytes
//   0x1aeae8: AA0003E8  mov      x8, x0
//   0x1aeaec: F9400000  ldr      x0, [x0]
//   0x1aeaf0: B4000060  cbz      x0, #0x1aeafc
//   0x1aeaf4: F9000500  str      x0, [x8, #8]
static inline uint64_t fde_func_1864_0x1aeae8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1aeae8ULL ^ (static_cast<uint64_t>(0xaa0003e8ULL) << 13);
    acc = (acc + a1 + 0xf9400000ULL) ^ 0x04ace0ULL;
    acc ^= (acc >> 17) * 0x0018ULL;
    return acc;
}

// FDE #1865 | PC: 0x1aeb00 | FDE: 0x04acf8 | Size: 36 bytes [_ZN5vmsdk7general7android7JavaRefIP8_jobjectEC1Ev]
// Khung tháo gỡ #1865 | Địa chỉ PC: 0x1aeb00 | Địa chỉ FDE: 0x04acf8 | Kích thước: 36 bytes
//   0x1aeb00: F0000069  adrp     x9, #0x1bd000
//   0x1aeb04: F9413129  ldr      x9, [x9, #0x260]
//   0x1aeb08: 91004008  add      x8, x0, #0x10
//   0x1aeb0c: 90FFF421  adrp     x1, #0x32000
static inline uint64_t fde_func_1865_0x1aeb00(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1aeb00ULL ^ (static_cast<uint64_t>(0xf0000069ULL) << 13);
    acc = (acc + a1 + 0xf9413129ULL) ^ 0x04acf8ULL;
    acc ^= (acc >> 17) * 0x0024ULL;
    return acc;
}

// FDE #1866 | PC: 0x1aeb24 | FDE: 0x04ad10 | Size: 256 bytes [_ZN5vmsdk7general7android7JavaRefIP8_jobjectE16ResetNewLocalRefEP7_JNIEnvS4_]
// Khung tháo gỡ #1866 | Địa chỉ PC: 0x1aeb24 | Địa chỉ FDE: 0x04ad10 | Kích thước: 256 bytes
//   0x1aeb24: D10203FF  sub      sp, sp, #0x80
//   0x1aeb28: F90023F8  str      x24, [sp, #0x40]
//   0x1aeb2c: A9055BF7  stp      x23, x22, [sp, #0x50]
//   0x1aeb30: A90653F5  stp      x21, x20, [sp, #0x60]
static inline uint64_t fde_func_1866_0x1aeb24(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1aeb24ULL ^ (static_cast<uint64_t>(0xd10203ffULL) << 13);
    acc = (acc + a1 + 0xf90023f8ULL) ^ 0x04ad10ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1867 | PC: 0x1aec50 | FDE: 0x04ad38 | Size: 256 bytes [_ZN5vmsdk7general7android7JavaRefIP8_jobjectE17ResetNewGlobalRefEP7_JNIEnvS4_]
// Khung tháo gỡ #1867 | Địa chỉ PC: 0x1aec50 | Địa chỉ FDE: 0x04ad38 | Kích thước: 256 bytes
//   0x1aec50: D10283FF  sub      sp, sp, #0xa0
//   0x1aec54: F90023FC  str      x28, [sp, #0x40]
//   0x1aec58: A9056BFB  stp      x27, x26, [sp, #0x50]
//   0x1aec5c: A90663F9  stp      x25, x24, [sp, #0x60]
static inline uint64_t fde_func_1867_0x1aec50(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1aec50ULL ^ (static_cast<uint64_t>(0xd10283ffULL) << 13);
    acc = (acc + a1 + 0xf90023fcULL) ^ 0x04ad38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1868 | PC: 0x1aee88 | FDE: 0x04ad68 | Size: 256 bytes [_ZN5vmsdk7general7android7JavaRefIP8_jobjectE16ReleaseGlobalRefEP7_JNIEnv]
// Khung tháo gỡ #1868 | Địa chỉ PC: 0x1aee88 | Địa chỉ FDE: 0x04ad68 | Kích thước: 256 bytes
//   0x1aee88: D101C3FF  sub      sp, sp, #0x70
//   0x1aee8c: A9045BF7  stp      x23, x22, [sp, #0x40]
//   0x1aee90: A90553F5  stp      x21, x20, [sp, #0x50]
//   0x1aee94: A9067BF3  stp      x19, x30, [sp, #0x60]
static inline uint64_t fde_func_1868_0x1aee88(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1aee88ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xa9045bf7ULL) ^ 0x04ad68ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1869 | PC: 0x1af014 | FDE: 0x04ad88 | Size: 256 bytes [_ZN5vmsdk7general7android7JavaRefIP8_jobjectE21ResetNewWeakGlobalRefEP7_JNIEnvS4_]
// Khung tháo gỡ #1869 | Địa chỉ PC: 0x1af014 | Địa chỉ FDE: 0x04ad88 | Kích thước: 256 bytes
//   0x1af014: D10203FF  sub      sp, sp, #0x80
//   0x1af018: F90023F8  str      x24, [sp, #0x40]
//   0x1af01c: A9055BF7  stp      x23, x22, [sp, #0x50]
//   0x1af020: A90653F5  stp      x21, x20, [sp, #0x60]
static inline uint64_t fde_func_1869_0x1af014(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1af014ULL ^ (static_cast<uint64_t>(0xd10203ffULL) << 13);
    acc = (acc + a1 + 0xf90023f8ULL) ^ 0x04ad88ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1870 | PC: 0x1af140 | FDE: 0x04adb0 | Size: 36 bytes [_ZN5vmsdk7general7android7JavaRefIP8_jobjectEC1EP7_JNIEnvS4_]
// Khung tháo gỡ #1870 | Địa chỉ PC: 0x1af140 | Địa chỉ FDE: 0x04adb0 | Kích thước: 36 bytes
//   0x1af140: D0000069  adrp     x9, #0x1bd000
//   0x1af144: F9413129  ldr      x9, [x9, #0x260]
//   0x1af148: 91004008  add      x8, x0, #0x10
//   0x1af14c: F0FFF401  adrp     x1, #0x32000
static inline uint64_t fde_func_1870_0x1af140(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1af140ULL ^ (static_cast<uint64_t>(0xd0000069ULL) << 13);
    acc = (acc + a1 + 0xf9413129ULL) ^ 0x04adb0ULL;
    acc ^= (acc >> 17) * 0x0024ULL;
    return acc;
}

// FDE #1871 | PC: 0x1af164 | FDE: 0x04adc8 | Size: 28 bytes [_ZN5vmsdk7general7logging8InitAlogEPFvjPKcS3_E]
// Khung tháo gỡ #1871 | Địa chỉ PC: 0x1af164 | Địa chỉ FDE: 0x04adc8 | Kích thước: 28 bytes
//   0x1af164: F0000088  adrp     x8, #0x1c2000
//   0x1af168: F9401109  ldr      x9, [x8, #0x20]
//   0x1af16c: B5000069  cbnz     x9, #0x1af178
//   0x1af170: B4000060  cbz      x0, #0x1af17c
static inline uint64_t fde_func_1871_0x1af164(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1af164ULL ^ (static_cast<uint64_t>(0xf0000088ULL) << 13);
    acc = (acc + a1 + 0xf9401109ULL) ^ 0x04adc8ULL;
    acc ^= (acc >> 17) * 0x001cULL;
    return acc;
}

// FDE #1872 | PC: 0x1af180 | FDE: 0x04ade0 | Size: 32 bytes [_ZN5vmsdk7general7logging10ALogWriteFEPKcS3_]
// Khung tháo gỡ #1872 | Địa chỉ PC: 0x1af180 | Địa chỉ FDE: 0x04ade0 | Kích thước: 32 bytes
//   0x1af180: F0000088  adrp     x8, #0x1c2000
//   0x1af184: F9401103  ldr      x3, [x8, #0x20]
//   0x1af188: B40000A3  cbz      x3, #0x1af19c
//   0x1af18c: AA0103E2  mov      x2, x1
static inline uint64_t fde_func_1872_0x1af180(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1af180ULL ^ (static_cast<uint64_t>(0xf0000088ULL) << 13);
    acc = (acc + a1 + 0xf9401103ULL) ^ 0x04ade0ULL;
    acc ^= (acc >> 17) * 0x0020ULL;
    return acc;
}

// FDE #1873 | PC: 0x1af1a0 | FDE: 0x04adf8 | Size: 152 bytes [_ZN6primjs7general7logging28useAndroidLogPrintLogMessageEPNS1_10LogMessageE]
// Khung tháo gỡ #1873 | Địa chỉ PC: 0x1af1a0 | Địa chỉ FDE: 0x04adf8 | Kích thước: 152 bytes
//   0x1af1a0: D10103FF  sub      sp, sp, #0x40
//   0x1af1a4: A90253F5  stp      x21, x20, [sp, #0x20]
//   0x1af1a8: A9037BF3  stp      x19, x30, [sp, #0x30]
//   0x1af1ac: D53BD054  mrs      x20, tpidr_el0
static inline uint64_t fde_func_1873_0x1af1a0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1af1a0ULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xa90253f5ULL) ^ 0x04adf8ULL;
    acc ^= (acc >> 17) * 0x0098ULL;
    return acc;
}

// FDE #1874 | PC: 0x1af238 | FDE: 0x04ae18 | Size: 256 bytes [_ZN6primjs7general7logging3LogEPNS1_10LogMessageE]
// Khung tháo gỡ #1874 | Địa chỉ PC: 0x1af238 | Địa chỉ FDE: 0x04ae18 | Kích thước: 256 bytes
//   0x1af238: D10203FF  sub      sp, sp, #0x80
//   0x1af23c: F90023F8  str      x24, [sp, #0x40]
//   0x1af240: A9055BF7  stp      x23, x22, [sp, #0x50]
//   0x1af244: A90653F5  stp      x21, x20, [sp, #0x60]
static inline uint64_t fde_func_1874_0x1af238(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1af238ULL ^ (static_cast<uint64_t>(0xd10203ffULL) << 13);
    acc = (acc + a1 + 0xf90023f8ULL) ^ 0x04ae18ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1875 | PC: 0x1af4f4 | FDE: 0x04ae40 | Size: 152 bytes
// Khung tháo gỡ #1875 | Địa chỉ PC: 0x1af4f4 | Địa chỉ FDE: 0x04ae40 | Kích thước: 152 bytes
//   0x1af4f4: D10483FF  sub      sp, sp, #0x120
//   0x1af4f8: F90083FC  str      x28, [sp, #0x100]
//   0x1af4fc: A9117BF3  stp      x19, x30, [sp, #0x110]
//   0x1af500: A90893E3  stp      x3, x4, [sp, #0x88]
static inline uint64_t fde_func_1875_0x1af4f4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1af4f4ULL ^ (static_cast<uint64_t>(0xd10483ffULL) << 13);
    acc = (acc + a1 + 0xf90083fcULL) ^ 0x04ae40ULL;
    acc ^= (acc >> 17) * 0x0098ULL;
    return acc;
}

// FDE #1876 | PC: 0x1af58c | FDE: 0x04ae60 | Size: 256 bytes [_ZN5vmsdk7general7logging11RegisterJNIEP7_JNIEnv]
// Khung tháo gỡ #1876 | Địa chỉ PC: 0x1af58c | Địa chỉ FDE: 0x04ae60 | Kích thước: 256 bytes
//   0x1af58c: D10283FF  sub      sp, sp, #0xa0
//   0x1af590: A9075BF7  stp      x23, x22, [sp, #0x70]
//   0x1af594: A90853F5  stp      x21, x20, [sp, #0x80]
//   0x1af598: A9097BF3  stp      x19, x30, [sp, #0x90]
static inline uint64_t fde_func_1876_0x1af58c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1af58cULL ^ (static_cast<uint64_t>(0xd10283ffULL) << 13);
    acc = (acc + a1 + 0xa9075bf7ULL) ^ 0x04ae60ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1877 | PC: 0x1af730 | FDE: 0x04ae88 | Size: 24 bytes
// Khung tháo gỡ #1877 | Địa chỉ PC: 0x1af730 | Địa chỉ FDE: 0x04ae88 | Kích thước: 24 bytes
//   0x1af730: 71000C5F  cmp      w2, #3
//   0x1af734: 52800068  mov      w8, #3
//   0x1af738: 1A88B048  csel     w8, w2, w8, lt
//   0x1af73c: B0000089  adrp     x9, #0x1c0000
static inline uint64_t fde_func_1877_0x1af730(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1af730ULL ^ (static_cast<uint64_t>(0x71000c5fULL) << 13);
    acc = (acc + a1 + 0x52800068ULL) ^ 0x04ae88ULL;
    acc ^= (acc >> 17) * 0x0018ULL;
    return acc;
}

// FDE #1878 | PC: 0x1af748 | FDE: 0x04aea0 | Size: 44 bytes
// Khung tháo gỡ #1878 | Địa chỉ PC: 0x1af748 | Địa chỉ FDE: 0x04aea0 | Kích thước: 44 bytes
//   0x1af748: F0000088  adrp     x8, #0x1c2000
//   0x1af74c: F9401109  ldr      x9, [x8, #0x20]
//   0x1af750: B5000069  cbnz     x9, #0x1af75c
//   0x1af754: B40000C2  cbz      x2, #0x1af76c
static inline uint64_t fde_func_1878_0x1af748(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1af748ULL ^ (static_cast<uint64_t>(0xf0000088ULL) << 13);
    acc = (acc + a1 + 0xf9401109ULL) ^ 0x04aea0ULL;
    acc ^= (acc >> 17) * 0x002cULL;
    return acc;
}

// FDE #1879 | PC: 0x1af774 | FDE: 0x04aeb8 | Size: 256 bytes
// Khung tháo gỡ #1879 | Địa chỉ PC: 0x1af774 | Địa chỉ FDE: 0x04aeb8 | Kích thước: 256 bytes
//   0x1af774: D102C3FF  sub      sp, sp, #0xb0
//   0x1af778: A9066BFB  stp      x27, x26, [sp, #0x60]
//   0x1af77c: A90763F9  stp      x25, x24, [sp, #0x70]
//   0x1af780: A9085BF7  stp      x23, x22, [sp, #0x80]
static inline uint64_t fde_func_1879_0x1af774(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1af774ULL ^ (static_cast<uint64_t>(0xd102c3ffULL) << 13);
    acc = (acc + a1 + 0xa9066bfbULL) ^ 0x04aeb8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1880 | PC: 0x1afa10 | FDE: 0x04aee8 | Size: 256 bytes [_ZN5vmsdk7general7logging10GetALogPtrEv]
// Khung tháo gỡ #1880 | Địa chỉ PC: 0x1afa10 | Địa chỉ FDE: 0x04aee8 | Kích thước: 256 bytes
//   0x1afa10: D101C3FF  sub      sp, sp, #0x70
//   0x1afa14: F90023F6  str      x22, [sp, #0x40]
//   0x1afa18: A90553F5  stp      x21, x20, [sp, #0x50]
//   0x1afa1c: A9067BF3  stp      x19, x30, [sp, #0x60]
static inline uint64_t fde_func_1880_0x1afa10(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1afa10ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xf90023f6ULL) ^ 0x04aee8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1881 | PC: 0x1afb6c | FDE: 0x04af08 | Size: 152 bytes
// Khung tháo gỡ #1881 | Địa chỉ PC: 0x1afb6c | Địa chỉ FDE: 0x04af08 | Kích thước: 152 bytes
//   0x1afb6c: D10483FF  sub      sp, sp, #0x120
//   0x1afb70: F90083FC  str      x28, [sp, #0x100]
//   0x1afb74: A9117BF3  stp      x19, x30, [sp, #0x110]
//   0x1afb78: A90893E3  stp      x3, x4, [sp, #0x88]
static inline uint64_t fde_func_1881_0x1afb6c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1afb6cULL ^ (static_cast<uint64_t>(0xd10483ffULL) << 13);
    acc = (acc + a1 + 0xf90083fcULL) ^ 0x04af08ULL;
    acc ^= (acc >> 17) * 0x0098ULL;
    return acc;
}

// FDE #1882 | PC: 0x1afc04 | FDE: 0x04af28 | Size: 24 bytes [_ZN5vmsdk7general7logging19InternalLogFromJavaEiPKcS3_]
// Khung tháo gỡ #1882 | Địa chỉ PC: 0x1afc04 | Địa chỉ FDE: 0x04af28 | Kích thước: 24 bytes
//   0x1afc04: F0000088  adrp     x8, #0x1c2000
//   0x1afc08: F9401103  ldr      x3, [x8, #0x20]
//   0x1afc0c: B4000063  cbz      x3, #0x1afc18
//   0x1afc10: 51000800  sub      w0, w0, #2
static inline uint64_t fde_func_1882_0x1afc04(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1afc04ULL ^ (static_cast<uint64_t>(0xf0000088ULL) << 13);
    acc = (acc + a1 + 0xf9401103ULL) ^ 0x04af28ULL;
    acc ^= (acc >> 17) * 0x0018ULL;
    return acc;
}

// FDE #1883 | PC: 0x1afc1c | FDE: 0x04af40 | Size: 252 bytes [JNI_OnLoad]
// Khung tháo gỡ #1883 | Địa chỉ PC: 0x1afc1c | Địa chỉ FDE: 0x04af40 | Kích thước: 252 bytes
//   0x1afc1c: D101C3FF  sub      sp, sp, #0x70
//   0x1afc20: F90023F6  str      x22, [sp, #0x40]
//   0x1afc24: A90553F5  stp      x21, x20, [sp, #0x50]
//   0x1afc28: A9067BF3  stp      x19, x30, [sp, #0x60]
static inline uint64_t fde_func_1883_0x1afc1c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1afc1cULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xf90023f6ULL) ^ 0x04af40ULL;
    acc ^= (acc >> 17) * 0x00fcULL;
    return acc;
}

// FDE #1884 | PC: 0x1afd18 | FDE: 0x04af60 | Size: 256 bytes [_ZN5vmsdk7monitor7android19VmSdkMonitorAndroid11RegisterJNIEP7_JNIEnv]
// Khung tháo gỡ #1884 | Địa chỉ PC: 0x1afd18 | Địa chỉ FDE: 0x04af60 | Kích thước: 256 bytes
//   0x1afd18: D10243FF  sub      sp, sp, #0x90
//   0x1afd1c: A90753F5  stp      x21, x20, [sp, #0x70]
//   0x1afd20: A9087BF3  stp      x19, x30, [sp, #0x80]
//   0x1afd24: D53BD054  mrs      x20, tpidr_el0
static inline uint64_t fde_func_1884_0x1afd18(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1afd18ULL ^ (static_cast<uint64_t>(0xd10243ffULL) << 13);
    acc = (acc + a1 + 0xa90753f5ULL) ^ 0x04af60ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1885 | PC: 0x1afe90 | FDE: 0x04af80 | Size: 256 bytes [_ZN5vmsdk7monitor7android19VmSdkMonitorAndroid12MonitorEventEPKcS4_S4_S4_]
// Khung tháo gỡ #1885 | Địa chỉ PC: 0x1afe90 | Địa chỉ FDE: 0x04af80 | Kích thước: 256 bytes
//   0x1afe90: D10583FF  sub      sp, sp, #0x160
//   0x1afe94: A9106FFC  stp      x28, x27, [sp, #0x100]
//   0x1afe98: A91167FA  stp      x26, x25, [sp, #0x110]
//   0x1afe9c: A9125FF8  stp      x24, x23, [sp, #0x120]
static inline uint64_t fde_func_1885_0x1afe90(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1afe90ULL ^ (static_cast<uint64_t>(0xd10583ffULL) << 13);
    acc = (acc + a1 + 0xa9106ffcULL) ^ 0x04af80ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1886 | PC: 0x1b03cc | FDE: 0x04afb0 | Size: 256 bytes [_ZN5vmsdk7monitor7android19VmSdkMonitorAndroid18GetSettingsWithKeyEPKc]
// Khung tháo gỡ #1886 | Địa chỉ PC: 0x1b03cc | Địa chỉ FDE: 0x04afb0 | Kích thước: 256 bytes
//   0x1b03cc: D10303FF  sub      sp, sp, #0xc0
//   0x1b03d0: F9003BFA  str      x26, [sp, #0x70]
//   0x1b03d4: A90863F9  stp      x25, x24, [sp, #0x80]
//   0x1b03d8: A9095BF7  stp      x23, x22, [sp, #0x90]
static inline uint64_t fde_func_1886_0x1b03cc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1b03ccULL ^ (static_cast<uint64_t>(0xd10303ffULL) << 13);
    acc = (acc + a1 + 0xf9003bfaULL) ^ 0x04afb0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1887 | PC: 0x1b0650 | FDE: 0x04afd8 | Size: 152 bytes
// Khung tháo gỡ #1887 | Địa chỉ PC: 0x1b0650 | Địa chỉ FDE: 0x04afd8 | Kích thước: 152 bytes
//   0x1b0650: D10483FF  sub      sp, sp, #0x120
//   0x1b0654: F90083FC  str      x28, [sp, #0x100]
//   0x1b0658: A9117BF3  stp      x19, x30, [sp, #0x110]
//   0x1b065c: A90893E3  stp      x3, x4, [sp, #0x88]
static inline uint64_t fde_func_1887_0x1b0650(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1b0650ULL ^ (static_cast<uint64_t>(0xd10483ffULL) << 13);
    acc = (acc + a1 + 0xf90083fcULL) ^ 0x04afd8ULL;
    acc ^= (acc >> 17) * 0x0098ULL;
    return acc;
}

// FDE #1888 | PC: 0x1b06e8 | FDE: 0x04aff8 | Size: 256 bytes [_ZN5vmsdk7monitor7android19VmSdkMonitorAndroid15GetSettingsFlagEv]
// Khung tháo gỡ #1888 | Địa chỉ PC: 0x1b06e8 | Địa chỉ FDE: 0x04aff8 | Kích thước: 256 bytes
//   0x1b06e8: D101C3FF  sub      sp, sp, #0x70
//   0x1b06ec: F90023F6  str      x22, [sp, #0x40]
//   0x1b06f0: A90553F5  stp      x21, x20, [sp, #0x50]
//   0x1b06f4: A9067BF3  stp      x19, x30, [sp, #0x60]
static inline uint64_t fde_func_1888_0x1b06e8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1b06e8ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xf90023f6ULL) ^ 0x04aff8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1889 | PC: 0x1b0840 | FDE: 0x04b018 | Size: 152 bytes
// Khung tháo gỡ #1889 | Địa chỉ PC: 0x1b0840 | Địa chỉ FDE: 0x04b018 | Kích thước: 152 bytes
//   0x1b0840: D10483FF  sub      sp, sp, #0x120
//   0x1b0844: F90083FC  str      x28, [sp, #0x100]
//   0x1b0848: A9117BF3  stp      x19, x30, [sp, #0x110]
//   0x1b084c: A90893E3  stp      x3, x4, [sp, #0x88]
static inline uint64_t fde_func_1889_0x1b0840(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1b0840ULL ^ (static_cast<uint64_t>(0xd10483ffULL) << 13);
    acc = (acc + a1 + 0xf90083fcULL) ^ 0x04b018ULL;
    acc ^= (acc >> 17) * 0x0098ULL;
    return acc;
}

// FDE #1890 | PC: 0x1b08d8 | FDE: 0x04b038 | Size: 4 bytes [_Z12MonitorEventPKcS0_S0_S0_]
// Khung tháo gỡ #1890 | Địa chỉ PC: 0x1b08d8 | Địa chỉ FDE: 0x04b038 | Kích thước: 4 bytes
//   0x1b08d8: 17FFFD6E  b        #0x1afe90
static inline uint64_t fde_func_1890_0x1b08d8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1b08d8ULL ^ (static_cast<uint64_t>(0x17fffd6eULL) << 13);
    acc = (acc + a1 + 0x17fffebcULL) ^ 0x04b038ULL;
    acc ^= (acc >> 17) * 0x0004ULL;
    return acc;
}

// FDE #1891 | PC: 0x1b08dc | FDE: 0x04b050 | Size: 4 bytes [_Z18GetSettingsWithKeyPKc]
// Khung tháo gỡ #1891 | Địa chỉ PC: 0x1b08dc | Địa chỉ FDE: 0x04b050 | Kích thước: 4 bytes
//   0x1b08dc: 17FFFEBC  b        #0x1b03cc
static inline uint64_t fde_func_1891_0x1b08dc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1b08dcULL ^ (static_cast<uint64_t>(0x17fffebcULL) << 13);
    acc = (acc + a1 + 0x17ffff82ULL) ^ 0x04b050ULL;
    acc ^= (acc >> 17) * 0x0004ULL;
    return acc;
}

// FDE #1892 | PC: 0x1b08e0 | FDE: 0x04b068 | Size: 4 bytes [_Z15GetSettingsFlagv]
// Khung tháo gỡ #1892 | Địa chỉ PC: 0x1b08e0 | Địa chỉ FDE: 0x04b068 | Kích thước: 4 bytes
//   0x1b08e0: 17FFFF82  b        #0x1b06e8
static inline uint64_t fde_func_1892_0x1b08e0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1b08e0ULL ^ (static_cast<uint64_t>(0x17ffff82ULL) << 13);
    acc = (acc + a1 + 0x00000000ULL) ^ 0x04b068ULL;
    acc ^= (acc >> 17) * 0x0004ULL;
    return acc;
}

// Shard 5 Dispatcher / Bộ điều phối phân mảnh 5
uint64_t execute_fde_shard_5(uint32_t fde_idx, uint64_t a0, uint64_t a1) {
    switch (fde_idx) {
        case 1516: return fde_func_1516_0x16d844(a0, a1);
        case 1517: return fde_func_1517_0x1748fc(a0, a1);
        case 1518: return fde_func_1518_0x174bbc(a0, a1);
        case 1519: return fde_func_1519_0x174ed4(a0, a1);
        case 1520: return fde_func_1520_0x175298(a0, a1);
        case 1521: return fde_func_1521_0x175608(a0, a1);
        case 1522: return fde_func_1522_0x17a700(a0, a1);
        case 1523: return fde_func_1523_0x17a8b0(a0, a1);
        case 1524: return fde_func_1524_0x17ad7c(a0, a1);
        case 1525: return fde_func_1525_0x17aea4(a0, a1);
        case 1526: return fde_func_1526_0x17b17c(a0, a1);
        case 1527: return fde_func_1527_0x17d04c(a0, a1);
        case 1528: return fde_func_1528_0x17d98c(a0, a1);
        case 1529: return fde_func_1529_0x17df04(a0, a1);
        case 1530: return fde_func_1530_0x182674(a0, a1);
        case 1531: return fde_func_1531_0x1828c8(a0, a1);
        case 1532: return fde_func_1532_0x183a14(a0, a1);
        case 1533: return fde_func_1533_0x183e28(a0, a1);
        case 1534: return fde_func_1534_0x184558(a0, a1);
        case 1535: return fde_func_1535_0x184690(a0, a1);
        case 1536: return fde_func_1536_0x184a10(a0, a1);
        case 1537: return fde_func_1537_0x184b40(a0, a1);
        case 1538: return fde_func_1538_0x186438(a0, a1);
        case 1539: return fde_func_1539_0x186530(a0, a1);
        case 1540: return fde_func_1540_0x188ac4(a0, a1);
        case 1541: return fde_func_1541_0x189328(a0, a1);
        case 1542: return fde_func_1542_0x189724(a0, a1);
        case 1543: return fde_func_1543_0x18992c(a0, a1);
        case 1544: return fde_func_1544_0x18c3e8(a0, a1);
        case 1545: return fde_func_1545_0x18c9ec(a0, a1);
        case 1546: return fde_func_1546_0x18cdac(a0, a1);
        case 1547: return fde_func_1547_0x18d170(a0, a1);
        case 1548: return fde_func_1548_0x18d280(a0, a1);
        case 1549: return fde_func_1549_0x18d4b4(a0, a1);
        case 1550: return fde_func_1550_0x18d564(a0, a1);
        case 1551: return fde_func_1551_0x18d6f4(a0, a1);
        case 1552: return fde_func_1552_0x18d9f4(a0, a1);
        case 1553: return fde_func_1553_0x18e324(a0, a1);
        case 1554: return fde_func_1554_0x18e998(a0, a1);
        case 1555: return fde_func_1555_0x18ee90(a0, a1);
        case 1556: return fde_func_1556_0x18efdc(a0, a1);
        case 1557: return fde_func_1557_0x18f204(a0, a1);
        case 1558: return fde_func_1558_0x18f324(a0, a1);
        case 1559: return fde_func_1559_0x18f688(a0, a1);
        case 1560: return fde_func_1560_0x18f85c(a0, a1);
        case 1561: return fde_func_1561_0x18fa58(a0, a1);
        case 1562: return fde_func_1562_0x190054(a0, a1);
        case 1563: return fde_func_1563_0x19023c(a0, a1);
        case 1564: return fde_func_1564_0x190374(a0, a1);
        case 1565: return fde_func_1565_0x1904ec(a0, a1);
        case 1566: return fde_func_1566_0x190664(a0, a1);
        case 1567: return fde_func_1567_0x1907bc(a0, a1);
        case 1568: return fde_func_1568_0x19100c(a0, a1);
        case 1569: return fde_func_1569_0x191088(a0, a1);
        case 1570: return fde_func_1570_0x191e58(a0, a1);
        case 1571: return fde_func_1571_0x191ffc(a0, a1);
        case 1572: return fde_func_1572_0x192340(a0, a1);
        case 1573: return fde_func_1573_0x19246c(a0, a1);
        case 1574: return fde_func_1574_0x1928b0(a0, a1);
        case 1575: return fde_func_1575_0x192e1c(a0, a1);
        case 1576: return fde_func_1576_0x192f1c(a0, a1);
        case 1577: return fde_func_1577_0x19307c(a0, a1);
        case 1578: return fde_func_1578_0x1931e4(a0, a1);
        case 1579: return fde_func_1579_0x1932d8(a0, a1);
        case 1580: return fde_func_1580_0x193554(a0, a1);
        case 1581: return fde_func_1581_0x1937fc(a0, a1);
        case 1582: return fde_func_1582_0x1939c4(a0, a1);
        case 1583: return fde_func_1583_0x193e38(a0, a1);
        case 1584: return fde_func_1584_0x194100(a0, a1);
        case 1585: return fde_func_1585_0x1941d4(a0, a1);
        case 1586: return fde_func_1586_0x194620(a0, a1);
        case 1587: return fde_func_1587_0x194810(a0, a1);
        case 1588: return fde_func_1588_0x194bf8(a0, a1);
        case 1589: return fde_func_1589_0x194cc8(a0, a1);
        case 1590: return fde_func_1590_0x194cdc(a0, a1);
        case 1591: return fde_func_1591_0x195784(a0, a1);
        case 1592: return fde_func_1592_0x195820(a0, a1);
        case 1593: return fde_func_1593_0x1958a8(a0, a1);
        case 1594: return fde_func_1594_0x195ac8(a0, a1);
        case 1595: return fde_func_1595_0x195c20(a0, a1);
        case 1596: return fde_func_1596_0x195f44(a0, a1);
        case 1597: return fde_func_1597_0x195f50(a0, a1);
        case 1598: return fde_func_1598_0x196108(a0, a1);
        case 1599: return fde_func_1599_0x1962cc(a0, a1);
        case 1600: return fde_func_1600_0x196404(a0, a1);
        case 1601: return fde_func_1601_0x19655c(a0, a1);
        case 1602: return fde_func_1602_0x196c1c(a0, a1);
        case 1603: return fde_func_1603_0x196d00(a0, a1);
        case 1604: return fde_func_1604_0x196e34(a0, a1);
        case 1605: return fde_func_1605_0x196f50(a0, a1);
        case 1606: return fde_func_1606_0x196f94(a0, a1);
        case 1607: return fde_func_1607_0x197108(a0, a1);
        case 1608: return fde_func_1608_0x1972e4(a0, a1);
        case 1609: return fde_func_1609_0x197318(a0, a1);
        case 1610: return fde_func_1610_0x1975c0(a0, a1);
        case 1611: return fde_func_1611_0x1976e0(a0, a1);
        case 1612: return fde_func_1612_0x197740(a0, a1);
        case 1613: return fde_func_1613_0x197794(a0, a1);
        case 1614: return fde_func_1614_0x1977c8(a0, a1);
        case 1615: return fde_func_1615_0x197ad4(a0, a1);
        case 1616: return fde_func_1616_0x197d2c(a0, a1);
        case 1617: return fde_func_1617_0x198094(a0, a1);
        case 1618: return fde_func_1618_0x1981ec(a0, a1);
        case 1619: return fde_func_1619_0x19848c(a0, a1);
        case 1620: return fde_func_1620_0x19897c(a0, a1);
        case 1621: return fde_func_1621_0x198e7c(a0, a1);
        case 1622: return fde_func_1622_0x1992e0(a0, a1);
        case 1623: return fde_func_1623_0x199968(a0, a1);
        case 1624: return fde_func_1624_0x199c84(a0, a1);
        case 1625: return fde_func_1625_0x199fa0(a0, a1);
        case 1626: return fde_func_1626_0x19a2bc(a0, a1);
        case 1627: return fde_func_1627_0x19a6f0(a0, a1);
        case 1628: return fde_func_1628_0x19b04c(a0, a1);
        case 1629: return fde_func_1629_0x19b6c4(a0, a1);
        case 1630: return fde_func_1630_0x19ba3c(a0, a1);
        case 1631: return fde_func_1631_0x19bbb0(a0, a1);
        case 1632: return fde_func_1632_0x19bbb4(a0, a1);
        case 1633: return fde_func_1633_0x19bdf0(a0, a1);
        case 1634: return fde_func_1634_0x19c148(a0, a1);
        case 1635: return fde_func_1635_0x19ca84(a0, a1);
        case 1636: return fde_func_1636_0x19cd0c(a0, a1);
        case 1637: return fde_func_1637_0x19ce9c(a0, a1);
        case 1638: return fde_func_1638_0x19d010(a0, a1);
        case 1639: return fde_func_1639_0x19d74c(a0, a1);
        case 1640: return fde_func_1640_0x19d8c8(a0, a1);
        case 1641: return fde_func_1641_0x19d9b8(a0, a1);
        case 1642: return fde_func_1642_0x19dccc(a0, a1);
        case 1643: return fde_func_1643_0x19def0(a0, a1);
        case 1644: return fde_func_1644_0x19e1ec(a0, a1);
        case 1645: return fde_func_1645_0x19e4f8(a0, a1);
        case 1646: return fde_func_1646_0x19e4fc(a0, a1);
        case 1647: return fde_func_1647_0x19e734(a0, a1);
        case 1648: return fde_func_1648_0x19e7c0(a0, a1);
        case 1649: return fde_func_1649_0x19f560(a0, a1);
        case 1650: return fde_func_1650_0x19f828(a0, a1);
        case 1651: return fde_func_1651_0x19fe38(a0, a1);
        case 1652: return fde_func_1652_0x1a02c8(a0, a1);
        case 1653: return fde_func_1653_0x1a0bc4(a0, a1);
        case 1654: return fde_func_1654_0x1a11bc(a0, a1);
        case 1655: return fde_func_1655_0x1a1654(a0, a1);
        case 1656: return fde_func_1656_0x1a1dd4(a0, a1);
        case 1657: return fde_func_1657_0x1a20b8(a0, a1);
        case 1658: return fde_func_1658_0x1a2664(a0, a1);
        case 1659: return fde_func_1659_0x1a2eb8(a0, a1);
        case 1660: return fde_func_1660_0x1a3b40(a0, a1);
        case 1661: return fde_func_1661_0x1a3ff8(a0, a1);
        case 1662: return fde_func_1662_0x1a44dc(a0, a1);
        case 1663: return fde_func_1663_0x1a4af8(a0, a1);
        case 1664: return fde_func_1664_0x1a4de0(a0, a1);
        case 1665: return fde_func_1665_0x1a5244(a0, a1);
        case 1666: return fde_func_1666_0x1a53cc(a0, a1);
        case 1667: return fde_func_1667_0x1a54d4(a0, a1);
        case 1668: return fde_func_1668_0x1a5d40(a0, a1);
        case 1669: return fde_func_1669_0x1a5ef4(a0, a1);
        case 1670: return fde_func_1670_0x1a5f28(a0, a1);
        case 1671: return fde_func_1671_0x1a6074(a0, a1);
        case 1672: return fde_func_1672_0x1a6084(a0, a1);
        case 1673: return fde_func_1673_0x1a6088(a0, a1);
        case 1674: return fde_func_1674_0x1a6208(a0, a1);
        case 1675: return fde_func_1675_0x1a6488(a0, a1);
        case 1676: return fde_func_1676_0x1a65f4(a0, a1);
        case 1677: return fde_func_1677_0x1a6738(a0, a1);
        case 1678: return fde_func_1678_0x1a67b4(a0, a1);
        case 1679: return fde_func_1679_0x1a69e4(a0, a1);
        case 1680: return fde_func_1680_0x1a6c0c(a0, a1);
        case 1681: return fde_func_1681_0x1a6d48(a0, a1);
        case 1682: return fde_func_1682_0x1a6dfc(a0, a1);
        case 1683: return fde_func_1683_0x1a6f14(a0, a1);
        case 1684: return fde_func_1684_0x1a6f24(a0, a1);
        case 1685: return fde_func_1685_0x1a6f34(a0, a1);
        case 1686: return fde_func_1686_0x1a6f44(a0, a1);
        case 1687: return fde_func_1687_0x1a73f8(a0, a1);
        case 1688: return fde_func_1688_0x1a7524(a0, a1);
        case 1689: return fde_func_1689_0x1a78ac(a0, a1);
        case 1690: return fde_func_1690_0x1a7aec(a0, a1);
        case 1691: return fde_func_1691_0x1a7d14(a0, a1);
        case 1692: return fde_func_1692_0x1a83f4(a0, a1);
        case 1693: return fde_func_1693_0x1a8734(a0, a1);
        case 1694: return fde_func_1694_0x1a873c(a0, a1);
        case 1695: return fde_func_1695_0x1a8744(a0, a1);
        case 1696: return fde_func_1696_0x1a8814(a0, a1);
        case 1697: return fde_func_1697_0x1a88ac(a0, a1);
        case 1698: return fde_func_1698_0x1a88b4(a0, a1);
        case 1699: return fde_func_1699_0x1a88c0(a0, a1);
        case 1700: return fde_func_1700_0x1a88f4(a0, a1);
        case 1701: return fde_func_1701_0x1a89a4(a0, a1);
        case 1702: return fde_func_1702_0x1a89cc(a0, a1);
        case 1703: return fde_func_1703_0x1a89fc(a0, a1);
        case 1704: return fde_func_1704_0x1a8a50(a0, a1);
        case 1705: return fde_func_1705_0x1a8b34(a0, a1);
        case 1706: return fde_func_1706_0x1a8c0c(a0, a1);
        case 1707: return fde_func_1707_0x1a8c40(a0, a1);
        case 1708: return fde_func_1708_0x1a8c70(a0, a1);
        case 1709: return fde_func_1709_0x1a8e58(a0, a1);
        case 1710: return fde_func_1710_0x1a8e68(a0, a1);
        case 1711: return fde_func_1711_0x1a8ed4(a0, a1);
        case 1712: return fde_func_1712_0x1a8f74(a0, a1);
        case 1713: return fde_func_1713_0x1a9080(a0, a1);
        case 1714: return fde_func_1714_0x1a90a0(a0, a1);
        case 1715: return fde_func_1715_0x1a90b4(a0, a1);
        case 1716: return fde_func_1716_0x1a90d8(a0, a1);
        case 1717: return fde_func_1717_0x1a90f4(a0, a1);
        case 1718: return fde_func_1718_0x1a912c(a0, a1);
        case 1719: return fde_func_1719_0x1a9140(a0, a1);
        case 1720: return fde_func_1720_0x1a9170(a0, a1);
        case 1721: return fde_func_1721_0x1a9178(a0, a1);
        case 1722: return fde_func_1722_0x1a9180(a0, a1);
        case 1723: return fde_func_1723_0x1a9188(a0, a1);
        case 1724: return fde_func_1724_0x1a91b0(a0, a1);
        case 1725: return fde_func_1725_0x1a91cc(a0, a1);
        case 1726: return fde_func_1726_0x1a91d4(a0, a1);
        case 1727: return fde_func_1727_0x1a9268(a0, a1);
        case 1728: return fde_func_1728_0x1a92a4(a0, a1);
        case 1729: return fde_func_1729_0x1a92bc(a0, a1);
        case 1730: return fde_func_1730_0x1a9318(a0, a1);
        case 1731: return fde_func_1731_0x1a9394(a0, a1);
        case 1732: return fde_func_1732_0x1a9488(a0, a1);
        case 1733: return fde_func_1733_0x1a94a8(a0, a1);
        case 1734: return fde_func_1734_0x1a9530(a0, a1);
        case 1735: return fde_func_1735_0x1a954c(a0, a1);
        case 1736: return fde_func_1736_0x1a9564(a0, a1);
        case 1737: return fde_func_1737_0x1a9574(a0, a1);
        case 1738: return fde_func_1738_0x1a9584(a0, a1);
        case 1739: return fde_func_1739_0x1a9594(a0, a1);
        case 1740: return fde_func_1740_0x1a95e4(a0, a1);
        case 1741: return fde_func_1741_0x1a9664(a0, a1);
        case 1742: return fde_func_1742_0x1a96e4(a0, a1);
        case 1743: return fde_func_1743_0x1a976c(a0, a1);
        case 1744: return fde_func_1744_0x1a9784(a0, a1);
        case 1745: return fde_func_1745_0x1a9794(a0, a1);
        case 1746: return fde_func_1746_0x1a97f4(a0, a1);
        case 1747: return fde_func_1747_0x1a9890(a0, a1);
        case 1748: return fde_func_1748_0x1a98a0(a0, a1);
        case 1749: return fde_func_1749_0x1a98e0(a0, a1);
        case 1750: return fde_func_1750_0x1a997c(a0, a1);
        case 1751: return fde_func_1751_0x1a9998(a0, a1);
        case 1752: return fde_func_1752_0x1a99a8(a0, a1);
        case 1753: return fde_func_1753_0x1a99b8(a0, a1);
        case 1754: return fde_func_1754_0x1a9a38(a0, a1);
        case 1755: return fde_func_1755_0x1a9a70(a0, a1);
        case 1756: return fde_func_1756_0x1a9ab8(a0, a1);
        case 1757: return fde_func_1757_0x1a9b08(a0, a1);
        case 1758: return fde_func_1758_0x1a9b54(a0, a1);
        case 1759: return fde_func_1759_0x1a9c0c(a0, a1);
        case 1760: return fde_func_1760_0x1a9d58(a0, a1);
        case 1761: return fde_func_1761_0x1a9d64(a0, a1);
        case 1762: return fde_func_1762_0x1a9d7c(a0, a1);
        case 1763: return fde_func_1763_0x1a9db0(a0, a1);
        case 1764: return fde_func_1764_0x1a9e58(a0, a1);
        case 1765: return fde_func_1765_0x1a9f30(a0, a1);
        case 1766: return fde_func_1766_0x1a9f3c(a0, a1);
        case 1767: return fde_func_1767_0x1a9f8c(a0, a1);
        case 1768: return fde_func_1768_0x1aa0d4(a0, a1);
        case 1769: return fde_func_1769_0x1aa150(a0, a1);
        case 1770: return fde_func_1770_0x1aa260(a0, a1);
        case 1771: return fde_func_1771_0x1aa278(a0, a1);
        case 1772: return fde_func_1772_0x1aa2a0(a0, a1);
        case 1773: return fde_func_1773_0x1aa370(a0, a1);
        case 1774: return fde_func_1774_0x1aa450(a0, a1);
        case 1775: return fde_func_1775_0x1aa6d4(a0, a1);
        case 1776: return fde_func_1776_0x1aa6e0(a0, a1);
        case 1777: return fde_func_1777_0x1aa6f8(a0, a1);
        case 1778: return fde_func_1778_0x1aa718(a0, a1);
        case 1779: return fde_func_1779_0x1aa774(a0, a1);
        case 1780: return fde_func_1780_0x1aa7d4(a0, a1);
        case 1781: return fde_func_1781_0x1aa968(a0, a1);
        case 1782: return fde_func_1782_0x1aa9bc(a0, a1);
        case 1783: return fde_func_1783_0x1aa9c8(a0, a1);
        case 1784: return fde_func_1784_0x1aa9dc(a0, a1);
        case 1785: return fde_func_1785_0x1aabe4(a0, a1);
        case 1786: return fde_func_1786_0x1ab2b0(a0, a1);
        case 1787: return fde_func_1787_0x1ab638(a0, a1);
        case 1788: return fde_func_1788_0x1ab64c(a0, a1);
        case 1789: return fde_func_1789_0x1ab788(a0, a1);
        case 1790: return fde_func_1790_0x1ab7a4(a0, a1);
        case 1791: return fde_func_1791_0x1ab7f8(a0, a1);
        case 1792: return fde_func_1792_0x1ab838(a0, a1);
        case 1793: return fde_func_1793_0x1ab850(a0, a1);
        case 1794: return fde_func_1794_0x1ab9a0(a0, a1);
        case 1795: return fde_func_1795_0x1ab9d4(a0, a1);
        case 1796: return fde_func_1796_0x1aba14(a0, a1);
        case 1797: return fde_func_1797_0x1abb7c(a0, a1);
        case 1798: return fde_func_1798_0x1abc6c(a0, a1);
        case 1799: return fde_func_1799_0x1abd94(a0, a1);
        case 1800: return fde_func_1800_0x1abde8(a0, a1);
        case 1801: return fde_func_1801_0x1abec8(a0, a1);
        case 1802: return fde_func_1802_0x1ac214(a0, a1);
        case 1803: return fde_func_1803_0x1ac260(a0, a1);
        case 1804: return fde_func_1804_0x1ac2e4(a0, a1);
        case 1805: return fde_func_1805_0x1ac318(a0, a1);
        case 1806: return fde_func_1806_0x1ac334(a0, a1);
        case 1807: return fde_func_1807_0x1ac430(a0, a1);
        case 1808: return fde_func_1808_0x1ac4bc(a0, a1);
        case 1809: return fde_func_1809_0x1ac4e4(a0, a1);
        case 1810: return fde_func_1810_0x1ac5a8(a0, a1);
        case 1811: return fde_func_1811_0x1ac5b4(a0, a1);
        case 1812: return fde_func_1812_0x1ac6b0(a0, a1);
        case 1813: return fde_func_1813_0x1ac6fc(a0, a1);
        case 1814: return fde_func_1814_0x1ac738(a0, a1);
        case 1815: return fde_func_1815_0x1ac748(a0, a1);
        case 1816: return fde_func_1816_0x1ac88c(a0, a1);
        case 1817: return fde_func_1817_0x1acb9c(a0, a1);
        case 1818: return fde_func_1818_0x1aced4(a0, a1);
        case 1819: return fde_func_1819_0x1acf64(a0, a1);
        case 1820: return fde_func_1820_0x1ad000(a0, a1);
        case 1821: return fde_func_1821_0x1ad00c(a0, a1);
        case 1822: return fde_func_1822_0x1ad0d4(a0, a1);
        case 1823: return fde_func_1823_0x1ad148(a0, a1);
        case 1824: return fde_func_1824_0x1ad164(a0, a1);
        case 1825: return fde_func_1825_0x1ad180(a0, a1);
        case 1826: return fde_func_1826_0x1ad198(a0, a1);
        case 1827: return fde_func_1827_0x1ad1d8(a0, a1);
        case 1828: return fde_func_1828_0x1ad32c(a0, a1);
        case 1829: return fde_func_1829_0x1ad33c(a0, a1);
        case 1830: return fde_func_1830_0x1ad354(a0, a1);
        case 1831: return fde_func_1831_0x1ad36c(a0, a1);
        case 1832: return fde_func_1832_0x1ad390(a0, a1);
        case 1833: return fde_func_1833_0x1ad398(a0, a1);
        case 1834: return fde_func_1834_0x1ad660(a0, a1);
        case 1835: return fde_func_1835_0x1ad670(a0, a1);
        case 1836: return fde_func_1836_0x1ad73c(a0, a1);
        case 1837: return fde_func_1837_0x1ad7ec(a0, a1);
        case 1838: return fde_func_1838_0x1ad828(a0, a1);
        case 1839: return fde_func_1839_0x1ad84c(a0, a1);
        case 1840: return fde_func_1840_0x1ad854(a0, a1);
        case 1841: return fde_func_1841_0x1ad85c(a0, a1);
        case 1842: return fde_func_1842_0x1ad868(a0, a1);
        case 1843: return fde_func_1843_0x1ad928(a0, a1);
        case 1844: return fde_func_1844_0x1ad944(a0, a1);
        case 1845: return fde_func_1845_0x1ad99c(a0, a1);
        case 1846: return fde_func_1846_0x1ad9a4(a0, a1);
        case 1847: return fde_func_1847_0x1ad9a8(a0, a1);
        case 1848: return fde_func_1848_0x1adaa4(a0, a1);
        case 1849: return fde_func_1849_0x1adaa8(a0, a1);
        case 1850: return fde_func_1850_0x1adaac(a0, a1);
        case 1851: return fde_func_1851_0x1adab0(a0, a1);
        case 1852: return fde_func_1852_0x1adbac(a0, a1);
        case 1853: return fde_func_1853_0x1adbbc(a0, a1);
        case 1854: return fde_func_1854_0x1adc20(a0, a1);
        case 1855: return fde_func_1855_0x1adc58(a0, a1);
        case 1856: return fde_func_1856_0x1adcb4(a0, a1);
        case 1857: return fde_func_1857_0x1adcd4(a0, a1);
        case 1858: return fde_func_1858_0x1add28(a0, a1);
        case 1859: return fde_func_1859_0x1ae40c(a0, a1);
        case 1860: return fde_func_1860_0x1ae4a4(a0, a1);
        case 1861: return fde_func_1861_0x1ae564(a0, a1);
        case 1862: return fde_func_1862_0x1aea9c(a0, a1);
        case 1863: return fde_func_1863_0x1aeae4(a0, a1);
        case 1864: return fde_func_1864_0x1aeae8(a0, a1);
        case 1865: return fde_func_1865_0x1aeb00(a0, a1);
        case 1866: return fde_func_1866_0x1aeb24(a0, a1);
        case 1867: return fde_func_1867_0x1aec50(a0, a1);
        case 1868: return fde_func_1868_0x1aee88(a0, a1);
        case 1869: return fde_func_1869_0x1af014(a0, a1);
        case 1870: return fde_func_1870_0x1af140(a0, a1);
        case 1871: return fde_func_1871_0x1af164(a0, a1);
        case 1872: return fde_func_1872_0x1af180(a0, a1);
        case 1873: return fde_func_1873_0x1af1a0(a0, a1);
        case 1874: return fde_func_1874_0x1af238(a0, a1);
        case 1875: return fde_func_1875_0x1af4f4(a0, a1);
        case 1876: return fde_func_1876_0x1af58c(a0, a1);
        case 1877: return fde_func_1877_0x1af730(a0, a1);
        case 1878: return fde_func_1878_0x1af748(a0, a1);
        case 1879: return fde_func_1879_0x1af774(a0, a1);
        case 1880: return fde_func_1880_0x1afa10(a0, a1);
        case 1881: return fde_func_1881_0x1afb6c(a0, a1);
        case 1882: return fde_func_1882_0x1afc04(a0, a1);
        case 1883: return fde_func_1883_0x1afc1c(a0, a1);
        case 1884: return fde_func_1884_0x1afd18(a0, a1);
        case 1885: return fde_func_1885_0x1afe90(a0, a1);
        case 1886: return fde_func_1886_0x1b03cc(a0, a1);
        case 1887: return fde_func_1887_0x1b0650(a0, a1);
        case 1888: return fde_func_1888_0x1b06e8(a0, a1);
        case 1889: return fde_func_1889_0x1b0840(a0, a1);
        case 1890: return fde_func_1890_0x1b08d8(a0, a1);
        case 1891: return fde_func_1891_0x1b08dc(a0, a1);
        case 1892: return fde_func_1892_0x1b08e0(a0, a1);
        default: return 0ULL;
    }
}