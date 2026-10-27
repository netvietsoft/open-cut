// ============================================================================
// Clean-Room C++17 AArch64 FDE Shard 5/5 for libnuro.so
// Phân mảnh FDE AArch64 C++17 sạch 5/5 cho libnuro.so
// Covers FDE indices [1468 .. 1834] out of 1,835 total FDEs (.eh_frame_hdr @ 0x0b8c58)
// Bao phủ chỉ số FDE [1468 .. 1834] trên tổng số 1,835 FDE (.eh_frame_hdr @ 0x0b8c58)
// ============================================================================
#include "nuro_core.h"

namespace nuro {

// FDE #1468 | PC: 0x096414 | FDE: 0x0c9c00 | Size: 256 bytes [Java_com_lemon_nuro_ILogHandler_00024CppProxy_native_1onLog]
// Hàm FDE #1468 | Địa chỉ PC: 0x096414 | Địa chỉ FDE: 0x0c9c00 | Kích thước: 256 bytes
//   0x096414: D10183FF  sub      sp, sp, #0x60
//   0x096418: F90013F7  str      x23, [sp, #0x20]
//   0x09641c: A90357F6  stp      x22, x21, [sp, #0x30]
//   0x096420: A9044FF4  stp      x20, x19, [sp, #0x40]
static inline uint64_t fde_func_1468_0x096414(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x096414ULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xf90013f7ULL) ^ 0x0c9c00ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1469 | PC: 0x096518 | FDE: 0x0c9c58 | Size: 120 bytes
// Hàm FDE #1469 | Địa chỉ PC: 0x096518 | Địa chỉ FDE: 0x0c9c58 | Kích thước: 120 bytes
//   0x096518: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x09651c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x096520: 910043FD  add      x29, sp, #0x10
//   0x096524: 52800500  mov      w0, #0x28
static inline uint64_t fde_func_1469_0x096518(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x096518ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x0c9c58ULL;
    acc ^= (acc >> 17) * 0x0078ULL;
    return acc;
}

// FDE #1470 | PC: 0x096590 | FDE: 0x0c9ab0 | Size: 80 bytes
// Hàm FDE #1470 | Địa chỉ PC: 0x096590 | Địa chỉ FDE: 0x0c9ab0 | Kích thước: 80 bytes
//   0x096590: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x096594: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x096598: 910043FD  add      x29, sp, #0x10
//   0x09659c: F9400013  ldr      x19, [x0]
static inline uint64_t fde_func_1470_0x096590(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x096590ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x0c9ab0ULL;
    acc ^= (acc >> 17) * 0x0050ULL;
    return acc;
}

// FDE #1471 | PC: 0x0965e0 | FDE: 0x0c9ca8 | Size: 216 bytes
// Hàm FDE #1471 | Địa chỉ PC: 0x0965e0 | Địa chỉ FDE: 0x0c9ca8 | Kích thước: 216 bytes
//   0x0965e0: D10143FF  sub      sp, sp, #0x50
//   0x0965e4: F90013F5  str      x21, [sp, #0x20]
//   0x0965e8: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x0965ec: A9047BFD  stp      x29, x30, [sp, #0x40]
static inline uint64_t fde_func_1471_0x0965e0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0965e0ULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xf90013f5ULL) ^ 0x0c9ca8ULL;
    acc ^= (acc >> 17) * 0x00d8ULL;
    return acc;
}

// FDE #1472 | PC: 0x0966b8 | FDE: 0x0c9af0 | Size: 72 bytes
// Hàm FDE #1472 | Địa chỉ PC: 0x0966b8 | Địa chỉ FDE: 0x0c9af0 | Kích thước: 72 bytes
//   0x0966b8: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x0966bc: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0966c0: 910043FD  add      x29, sp, #0x10
//   0x0966c4: F9400013  ldr      x19, [x0]
static inline uint64_t fde_func_1472_0x0966b8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0966b8ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x0c9af0ULL;
    acc ^= (acc >> 17) * 0x0048ULL;
    return acc;
}

// FDE #1473 | PC: 0x096700 | FDE: 0x0c9b10 | Size: 88 bytes
// Hàm FDE #1473 | Địa chỉ PC: 0x096700 | Địa chỉ FDE: 0x0c9b10 | Kích thước: 88 bytes
//   0x096700: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x096704: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x096708: 910043FD  add      x29, sp, #0x10
//   0x09670c: F9400413  ldr      x19, [x0, #8]
static inline uint64_t fde_func_1473_0x096700(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x096700ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x0c9b10ULL;
    acc ^= (acc >> 17) * 0x0058ULL;
    return acc;
}

// FDE #1474 | PC: 0x096758 | FDE: 0x0c9cd0 | Size: 12 bytes
// Hàm FDE #1474 | Địa chỉ PC: 0x096758 | Địa chỉ FDE: 0x0c9cd0 | Kích thước: 12 bytes
//   0x096758: B0000101  adrp     x1, #0xb7000
//   0x09675c: 91154421  add      x1, x1, #0x551
//   0x096760: 14003C38  b        #0xa5840
static inline uint64_t fde_func_1474_0x096758(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x096758ULL ^ (static_cast<uint64_t>(0xb0000101ULL) << 13);
    acc = (acc + a1 + 0x91154421ULL) ^ 0x0c9cd0ULL;
    acc ^= (acc >> 17) * 0x000cULL;
    return acc;
}

// FDE #1475 | PC: 0x096764 | FDE: 0x0c9ce8 | Size: 4 bytes
// Hàm FDE #1475 | Địa chỉ PC: 0x096764 | Địa chỉ FDE: 0x0c9ce8 | Kích thước: 4 bytes
//   0x096764: 14003C79  b        #0xa5948
static inline uint64_t fde_func_1475_0x096764(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x096764ULL ^ (static_cast<uint64_t>(0x14003c79ULL) << 13);
    acc = (acc + a1 + 0xb4000162ULL) ^ 0x0c9ce8ULL;
    acc ^= (acc >> 17) * 0x0004ULL;
    return acc;
}

// FDE #1476 | PC: 0x096768 | FDE: 0x0c9d00 | Size: 48 bytes [Java_com_lemon_nuro_ILogger_00024CppProxy_nativeDestroy]
// Hàm FDE #1476 | Địa chỉ PC: 0x096768 | Địa chỉ FDE: 0x0c9d00 | Kích thước: 48 bytes
//   0x096768: B4000162  cbz      x2, #0x96794
//   0x09676c: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x096770: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x096774: 910043FD  add      x29, sp, #0x10
static inline uint64_t fde_func_1476_0x096768(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x096768ULL ^ (static_cast<uint64_t>(0xb4000162ULL) << 13);
    acc = (acc + a1 + 0xf81e0ff3ULL) ^ 0x0c9d00ULL;
    acc ^= (acc >> 17) * 0x0030ULL;
    return acc;
}

// FDE #1477 | PC: 0x096798 | FDE: 0x0c9e18 | Size: 252 bytes
// Hàm FDE #1477 | Địa chỉ PC: 0x096798 | Địa chỉ FDE: 0x0c9e18 | Kích thước: 252 bytes
//   0x096798: D10103FF  sub      sp, sp, #0x40
//   0x09679c: F9000BF5  str      x21, [sp, #0x10]
//   0x0967a0: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x0967a4: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_1477_0x096798(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x096798ULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xf9000bf5ULL) ^ 0x0c9e18ULL;
    acc ^= (acc >> 17) * 0x00fcULL;
    return acc;
}

// FDE #1478 | PC: 0x096894 | FDE: 0x0c9e40 | Size: 256 bytes [Java_com_lemon_nuro_ILogger_00024CppProxy_registerHandler]
// Hàm FDE #1478 | Địa chỉ PC: 0x096894 | Địa chỉ FDE: 0x0c9e40 | Kích thước: 256 bytes
//   0x096894: D10183FF  sub      sp, sp, #0x60
//   0x096898: F90013F7  str      x23, [sp, #0x20]
//   0x09689c: A90357F6  stp      x22, x21, [sp, #0x30]
//   0x0968a0: A9044FF4  stp      x20, x19, [sp, #0x40]
static inline uint64_t fde_func_1478_0x096894(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x096894ULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xf90013f7ULL) ^ 0x0c9e40ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1479 | PC: 0x0969b8 | FDE: 0x0c9e70 | Size: 84 bytes [Java_com_lemon_nuro_ILogger_00024CppProxy_setLogLevel]
// Hàm FDE #1479 | Địa chỉ PC: 0x0969b8 | Địa chỉ FDE: 0x0c9e70 | Kích thước: 84 bytes
//   0x0969b8: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x0969bc: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0969c0: 910043FD  add      x29, sp, #0x10
//   0x0969c4: D00002A8  adrp     x8, #0xec000
static inline uint64_t fde_func_1479_0x0969b8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0969b8ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x0c9e70ULL;
    acc ^= (acc >> 17) * 0x0054ULL;
    return acc;
}

// FDE #1480 | PC: 0x096a0c | FDE: 0x0c9ec0 | Size: 108 bytes
// Hàm FDE #1480 | Địa chỉ PC: 0x096a0c | Địa chỉ FDE: 0x0c9ec0 | Kích thước: 108 bytes
//   0x096a0c: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x096a10: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x096a14: 910043FD  add      x29, sp, #0x10
//   0x096a18: 52800300  mov      w0, #0x18
static inline uint64_t fde_func_1480_0x096a0c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x096a0cULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x0c9ec0ULL;
    acc ^= (acc >> 17) * 0x006cULL;
    return acc;
}

// FDE #1481 | PC: 0x096a78 | FDE: 0x0c9d40 | Size: 60 bytes
// Hàm FDE #1481 | Địa chỉ PC: 0x096a78 | Địa chỉ FDE: 0x0c9d40 | Kích thước: 60 bytes
//   0x096a78: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x096a7c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x096a80: 910043FD  add      x29, sp, #0x10
//   0x096a84: F9400013  ldr      x19, [x0]
static inline uint64_t fde_func_1481_0x096a78(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x096a78ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x0c9d40ULL;
    acc ^= (acc >> 17) * 0x003cULL;
    return acc;
}

// FDE #1482 | PC: 0x096ab4 | FDE: 0x0c9d60 | Size: 256 bytes
// Hàm FDE #1482 | Địa chỉ PC: 0x096ab4 | Địa chỉ FDE: 0x0c9d60 | Kích thước: 256 bytes
//   0x096ab4: D101C3FF  sub      sp, sp, #0x70
//   0x096ab8: F9001BF7  str      x23, [sp, #0x30]
//   0x096abc: A90457F6  stp      x22, x21, [sp, #0x40]
//   0x096ac0: A9054FF4  stp      x20, x19, [sp, #0x50]
static inline uint64_t fde_func_1482_0x096ab4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x096ab4ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xf9001bf7ULL) ^ 0x0c9d60ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1483 | PC: 0x096c34 | FDE: 0x0c9ee8 | Size: 204 bytes
// Hàm FDE #1483 | Địa chỉ PC: 0x096c34 | Địa chỉ FDE: 0x0c9ee8 | Kích thước: 204 bytes
//   0x096c34: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x096c38: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x096c3c: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x096c40: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1483_0x096c34(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x096c34ULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x0c9ee8ULL;
    acc ^= (acc >> 17) * 0x00ccULL;
    return acc;
}

// FDE #1484 | PC: 0x096d00 | FDE: 0x0c9d88 | Size: 48 bytes
// Hàm FDE #1484 | Địa chỉ PC: 0x096d00 | Địa chỉ FDE: 0x0c9d88 | Kích thước: 48 bytes
//   0x096d00: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x096d04: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x096d08: 910043FD  add      x29, sp, #0x10
//   0x096d0c: B00002A8  adrp     x8, #0xeb000
static inline uint64_t fde_func_1484_0x096d00(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x096d00ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x0c9d88ULL;
    acc ^= (acc >> 17) * 0x0030ULL;
    return acc;
}

// FDE #1485 | PC: 0x096d30 | FDE: 0x0c9da8 | Size: 56 bytes
// Hàm FDE #1485 | Địa chỉ PC: 0x096d30 | Địa chỉ FDE: 0x0c9da8 | Kích thước: 56 bytes
//   0x096d30: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x096d34: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x096d38: 910043FD  add      x29, sp, #0x10
//   0x096d3c: B00002A8  adrp     x8, #0xeb000
static inline uint64_t fde_func_1485_0x096d30(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x096d30ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x0c9da8ULL;
    acc ^= (acc >> 17) * 0x0038ULL;
    return acc;
}

// FDE #1486 | PC: 0x096d68 | FDE: 0x0c9dc8 | Size: 8 bytes
// Hàm FDE #1486 | Địa chỉ PC: 0x096d68 | Địa chỉ FDE: 0x0c9dc8 | Kích thước: 8 bytes
//   0x096d68: 91006000  add      x0, x0, #0x18
//   0x096d6c: 17FFFCC4  b        #0x9607c
static inline uint64_t fde_func_1486_0x096d68(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x096d68ULL ^ (static_cast<uint64_t>(0x91006000ULL) << 13);
    acc = (acc + a1 + 0x17fffcc4ULL) ^ 0x0c9dc8ULL;
    acc ^= (acc >> 17) * 0x0008ULL;
    return acc;
}

// FDE #1487 | PC: 0x096d70 | FDE: 0x0c9de0 | Size: 4 bytes
// Hàm FDE #1487 | Địa chỉ PC: 0x096d70 | Địa chỉ FDE: 0x0c9de0 | Kích thước: 4 bytes
//   0x096d70: 17FDEEA4  b        #0x12800
static inline uint64_t fde_func_1487_0x096d70(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x096d70ULL ^ (static_cast<uint64_t>(0x17fdeea4ULL) << 13);
    acc = (acc + a1 + 0xf81e0ff3ULL) ^ 0x0c9de0ULL;
    acc ^= (acc >> 17) * 0x0004ULL;
    return acc;
}

// FDE #1488 | PC: 0x096d74 | FDE: 0x0c9df8 | Size: 88 bytes
// Hàm FDE #1488 | Địa chỉ PC: 0x096d74 | Địa chỉ FDE: 0x0c9df8 | Kích thước: 88 bytes
//   0x096d74: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x096d78: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x096d7c: 910043FD  add      x29, sp, #0x10
//   0x096d80: F9400413  ldr      x19, [x0, #8]
static inline uint64_t fde_func_1488_0x096d74(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x096d74ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x0c9df8ULL;
    acc ^= (acc >> 17) * 0x0058ULL;
    return acc;
}

// FDE #1489 | PC: 0x096dcc | FDE: 0x0c9f18 | Size: 12 bytes
// Hàm FDE #1489 | Địa chỉ PC: 0x096dcc | Địa chỉ FDE: 0x0c9f18 | Kích thước: 12 bytes
//   0x096dcc: B0000101  adrp     x1, #0xb7000
//   0x096dd0: 9119B021  add      x1, x1, #0x66c
//   0x096dd4: 14003A9B  b        #0xa5840
static inline uint64_t fde_func_1489_0x096dcc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x096dccULL ^ (static_cast<uint64_t>(0xb0000101ULL) << 13);
    acc = (acc + a1 + 0x9119b021ULL) ^ 0x0c9f18ULL;
    acc ^= (acc >> 17) * 0x000cULL;
    return acc;
}

// FDE #1490 | PC: 0x096dd8 | FDE: 0x0c9f30 | Size: 4 bytes
// Hàm FDE #1490 | Địa chỉ PC: 0x096dd8 | Địa chỉ FDE: 0x0c9f30 | Kích thước: 4 bytes
//   0x096dd8: 14003ADC  b        #0xa5948
static inline uint64_t fde_func_1490_0x096dd8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x096dd8ULL ^ (static_cast<uint64_t>(0x14003adcULL) << 13);
    acc = (acc + a1 + 0xb4000162ULL) ^ 0x0c9f30ULL;
    acc ^= (acc >> 17) * 0x0004ULL;
    return acc;
}

// FDE #1491 | PC: 0x096ddc | FDE: 0x0c9f48 | Size: 48 bytes [Java_com_lemon_nuro_ITransport_00024CppProxy_nativeDestroy]
// Hàm FDE #1491 | Địa chỉ PC: 0x096ddc | Địa chỉ FDE: 0x0c9f48 | Kích thước: 48 bytes
//   0x096ddc: B4000162  cbz      x2, #0x96e08
//   0x096de0: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x096de4: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x096de8: 910043FD  add      x29, sp, #0x10
static inline uint64_t fde_func_1491_0x096ddc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x096ddcULL ^ (static_cast<uint64_t>(0xb4000162ULL) << 13);
    acc = (acc + a1 + 0xf81e0ff3ULL) ^ 0x0c9f48ULL;
    acc ^= (acc >> 17) * 0x0030ULL;
    return acc;
}

// FDE #1492 | PC: 0x096e0c | FDE: 0x0c9f68 | Size: 208 bytes [Java_com_lemon_nuro_ITransport_00024CppProxy_native_1onMessageReceived]
// Hàm FDE #1492 | Địa chỉ PC: 0x096e0c | Địa chỉ FDE: 0x0c9f68 | Kích thước: 208 bytes
//   0x096e0c: D10143FF  sub      sp, sp, #0x50
//   0x096e10: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x096e14: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x096e18: A9047BFD  stp      x29, x30, [sp, #0x40]
static inline uint64_t fde_func_1492_0x096e0c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x096e0cULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xa90257f6ULL) ^ 0x0c9f68ULL;
    acc ^= (acc >> 17) * 0x00d0ULL;
    return acc;
}

// FDE #1493 | PC: 0x096edc | FDE: 0x0ca010 | Size: 176 bytes
// Hàm FDE #1493 | Địa chỉ PC: 0x096edc | Địa chỉ FDE: 0x0ca010 | Kích thước: 176 bytes
//   0x096edc: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x096ee0: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x096ee4: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x096ee8: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1493_0x096edc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x096edcULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x0ca010ULL;
    acc ^= (acc >> 17) * 0x00b0ULL;
    return acc;
}

// FDE #1494 | PC: 0x096f8c | FDE: 0x0c9f98 | Size: 48 bytes
// Hàm FDE #1494 | Địa chỉ PC: 0x096f8c | Địa chỉ FDE: 0x0c9f98 | Kích thước: 48 bytes
//   0x096f8c: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x096f90: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x096f94: 910043FD  add      x29, sp, #0x10
//   0x096f98: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_1494_0x096f8c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x096f8cULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x0c9f98ULL;
    acc ^= (acc >> 17) * 0x0030ULL;
    return acc;
}

// FDE #1495 | PC: 0x096fbc | FDE: 0x0ca038 | Size: 196 bytes
// Hàm FDE #1495 | Địa chỉ PC: 0x096fbc | Địa chỉ FDE: 0x0ca038 | Kích thước: 196 bytes
//   0x096fbc: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x096fc0: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x096fc4: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x096fc8: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1495_0x096fbc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x096fbcULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x0ca038ULL;
    acc ^= (acc >> 17) * 0x00c4ULL;
    return acc;
}

// FDE #1496 | PC: 0x097080 | FDE: 0x0c9fb8 | Size: 8 bytes
// Hàm FDE #1496 | Địa chỉ PC: 0x097080 | Địa chỉ FDE: 0x0c9fb8 | Kích thước: 8 bytes
//   0x097080: 91002000  add      x0, x0, #8
//   0x097084: 14000001  b        #0x97088
static inline uint64_t fde_func_1496_0x097080(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x097080ULL ^ (static_cast<uint64_t>(0x91002000ULL) << 13);
    acc = (acc + a1 + 0x14000001ULL) ^ 0x0c9fb8ULL;
    acc ^= (acc >> 17) * 0x0008ULL;
    return acc;
}

// FDE #1497 | PC: 0x097088 | FDE: 0x0ca060 | Size: 232 bytes
// Hàm FDE #1497 | Địa chỉ PC: 0x097088 | Địa chỉ FDE: 0x0ca060 | Kích thước: 232 bytes
//   0x097088: D10103FF  sub      sp, sp, #0x40
//   0x09708c: F9000BF5  str      x21, [sp, #0x10]
//   0x097090: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x097094: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_1497_0x097088(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x097088ULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xf9000bf5ULL) ^ 0x0ca060ULL;
    acc ^= (acc >> 17) * 0x00e8ULL;
    return acc;
}

// FDE #1498 | PC: 0x097170 | FDE: 0x0c9fd0 | Size: 40 bytes
// Hàm FDE #1498 | Địa chỉ PC: 0x097170 | Địa chỉ FDE: 0x0c9fd0 | Kích thước: 40 bytes
//   0x097170: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x097174: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x097178: 910043FD  add      x29, sp, #0x10
//   0x09717c: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_1498_0x097170(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x097170ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x0c9fd0ULL;
    acc ^= (acc >> 17) * 0x0028ULL;
    return acc;
}

// FDE #1499 | PC: 0x097198 | FDE: 0x0ca088 | Size: 256 bytes
// Hàm FDE #1499 | Địa chỉ PC: 0x097198 | Địa chỉ FDE: 0x0ca088 | Kích thước: 256 bytes
//   0x097198: D10183FF  sub      sp, sp, #0x60
//   0x09719c: F90013F7  str      x23, [sp, #0x20]
//   0x0971a0: A90357F6  stp      x22, x21, [sp, #0x30]
//   0x0971a4: A9044FF4  stp      x20, x19, [sp, #0x40]
static inline uint64_t fde_func_1499_0x097198(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x097198ULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xf90013f7ULL) ^ 0x0ca088ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1500 | PC: 0x0972a8 | FDE: 0x0ca0b8 | Size: 256 bytes
// Hàm FDE #1500 | Địa chỉ PC: 0x0972a8 | Địa chỉ FDE: 0x0ca0b8 | Kích thước: 256 bytes
//   0x0972a8: D101C3FF  sub      sp, sp, #0x70
//   0x0972ac: A9035FF8  stp      x24, x23, [sp, #0x30]
//   0x0972b0: A90457F6  stp      x22, x21, [sp, #0x40]
//   0x0972b4: A9054FF4  stp      x20, x19, [sp, #0x50]
static inline uint64_t fde_func_1500_0x0972a8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0972a8ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xa9035ff8ULL) ^ 0x0ca0b8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1501 | PC: 0x0973fc | FDE: 0x0c9ff0 | Size: 48 bytes [Java_com_lemon_nuro_ITransportSender_00024CppProxy_nativeDestroy]
// Hàm FDE #1501 | Địa chỉ PC: 0x0973fc | Địa chỉ FDE: 0x0c9ff0 | Kích thước: 48 bytes
//   0x0973fc: B4000162  cbz      x2, #0x97428
//   0x097400: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x097404: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x097408: 910043FD  add      x29, sp, #0x10
static inline uint64_t fde_func_1501_0x0973fc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0973fcULL ^ (static_cast<uint64_t>(0xb4000162ULL) << 13);
    acc = (acc + a1 + 0xf81e0ff3ULL) ^ 0x0c9ff0ULL;
    acc ^= (acc >> 17) * 0x0030ULL;
    return acc;
}

// FDE #1502 | PC: 0x09742c | FDE: 0x0ca0e8 | Size: 252 bytes
// Hàm FDE #1502 | Địa chỉ PC: 0x09742c | Địa chỉ FDE: 0x0ca0e8 | Kích thước: 252 bytes
//   0x09742c: D10103FF  sub      sp, sp, #0x40
//   0x097430: F9000BF5  str      x21, [sp, #0x10]
//   0x097434: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x097438: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_1502_0x09742c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x09742cULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xf9000bf5ULL) ^ 0x0ca0e8ULL;
    acc ^= (acc >> 17) * 0x00fcULL;
    return acc;
}

// FDE #1503 | PC: 0x097528 | FDE: 0x0ca110 | Size: 220 bytes [Java_com_lemon_nuro_ITransportSender_00024CppProxy_native_1sendMessage]
// Hàm FDE #1503 | Địa chỉ PC: 0x097528 | Địa chỉ FDE: 0x0ca110 | Kích thước: 220 bytes
//   0x097528: D10143FF  sub      sp, sp, #0x50
//   0x09752c: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x097530: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x097534: A9047BFD  stp      x29, x30, [sp, #0x40]
static inline uint64_t fde_func_1503_0x097528(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x097528ULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xa90257f6ULL) ^ 0x0ca110ULL;
    acc ^= (acc >> 17) * 0x00dcULL;
    return acc;
}

// FDE #1504 | PC: 0x097604 | FDE: 0x0ca140 | Size: 256 bytes [Java_com_lemon_nuro_ITransportSender_00024CppProxy_native_1httpRequest]
// Hàm FDE #1504 | Địa chỉ PC: 0x097604 | Địa chỉ FDE: 0x0ca140 | Kích thước: 256 bytes
//   0x097604: D10203FF  sub      sp, sp, #0x80
//   0x097608: F90023F7  str      x23, [sp, #0x40]
//   0x09760c: A90557F6  stp      x22, x21, [sp, #0x50]
//   0x097610: A9064FF4  stp      x20, x19, [sp, #0x60]
static inline uint64_t fde_func_1504_0x097604(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x097604ULL ^ (static_cast<uint64_t>(0xd10203ffULL) << 13);
    acc = (acc + a1 + 0xf90023f7ULL) ^ 0x0ca140ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1505 | PC: 0x097814 | FDE: 0x0ca170 | Size: 256 bytes
// Hàm FDE #1505 | Địa chỉ PC: 0x097814 | Địa chỉ FDE: 0x0ca170 | Kích thước: 256 bytes
//   0x097814: D10143FF  sub      sp, sp, #0x50
//   0x097818: F90013F5  str      x21, [sp, #0x20]
//   0x09781c: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x097820: A9047BFD  stp      x29, x30, [sp, #0x40]
static inline uint64_t fde_func_1505_0x097814(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x097814ULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xf90013f5ULL) ^ 0x0ca170ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1506 | PC: 0x097930 | FDE: 0x0ca198 | Size: 256 bytes
// Hàm FDE #1506 | Địa chỉ PC: 0x097930 | Địa chỉ FDE: 0x0ca198 | Kích thước: 256 bytes
//   0x097930: A9BC5FF8  stp      x24, x23, [sp, #-0x40]!
//   0x097934: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x097938: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x09793c: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_1506_0x097930(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x097930ULL ^ (static_cast<uint64_t>(0xa9bc5ff8ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x0ca198ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1507 | PC: 0x097a40 | FDE: 0x0ca238 | Size: 256 bytes
// Hàm FDE #1507 | Địa chỉ PC: 0x097a40 | Địa chỉ FDE: 0x0ca238 | Kích thước: 256 bytes
//   0x097a40: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x097a44: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x097a48: 910043FD  add      x29, sp, #0x10
//   0x097a4c: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_1507_0x097a40(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x097a40ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x0ca238ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1508 | PC: 0x097b48 | FDE: 0x0ca1c8 | Size: 20 bytes
// Hàm FDE #1508 | Địa chỉ PC: 0x097b48 | Địa chỉ FDE: 0x0ca1c8 | Kích thước: 20 bytes
//   0x097b48: F9400001  ldr      x1, [x0]
//   0x097b4c: F900001F  str      xzr, [x0]
//   0x097b50: B4000041  cbz      x1, #0x97b58
//   0x097b54: 140029C7  b        #0xa2270
static inline uint64_t fde_func_1508_0x097b48(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x097b48ULL ^ (static_cast<uint64_t>(0xf9400001ULL) << 13);
    acc = (acc + a1 + 0xf900001fULL) ^ 0x0ca1c8ULL;
    acc ^= (acc >> 17) * 0x0014ULL;
    return acc;
}

// FDE #1509 | PC: 0x097b5c | FDE: 0x0ca260 | Size: 256 bytes
// Hàm FDE #1509 | Địa chỉ PC: 0x097b5c | Địa chỉ FDE: 0x0ca260 | Kích thước: 256 bytes
//   0x097b5c: D10243FF  sub      sp, sp, #0x90
//   0x097b60: A9036FFC  stp      x28, x27, [sp, #0x30]
//   0x097b64: A90467FA  stp      x26, x25, [sp, #0x40]
//   0x097b68: A9055FF8  stp      x24, x23, [sp, #0x50]
static inline uint64_t fde_func_1509_0x097b5c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x097b5cULL ^ (static_cast<uint64_t>(0xd10243ffULL) << 13);
    acc = (acc + a1 + 0xa9036ffcULL) ^ 0x0ca260ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1510 | PC: 0x097dc4 | FDE: 0x0ca298 | Size: 256 bytes
// Hàm FDE #1510 | Địa chỉ PC: 0x097dc4 | Địa chỉ FDE: 0x0ca298 | Kích thước: 256 bytes
//   0x097dc4: A9BB67FC  stp      x28, x25, [sp, #-0x50]!
//   0x097dc8: A9015FF8  stp      x24, x23, [sp, #0x10]
//   0x097dcc: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x097dd0: A9034FF4  stp      x20, x19, [sp, #0x30]
static inline uint64_t fde_func_1510_0x097dc4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x097dc4ULL ^ (static_cast<uint64_t>(0xa9bb67fcULL) << 13);
    acc = (acc + a1 + 0xa9015ff8ULL) ^ 0x0ca298ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1511 | PC: 0x09830c | FDE: 0x0ca1e0 | Size: 256 bytes [_ZN4nuro12InputMessageC2ENSt6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEENS1_8optionalINS_14MessageContentEEENS8_INS_7ContextEEENS8_INS_10ToolResultEEENS8_IS7_EE]
// Hàm FDE #1511 | Địa chỉ PC: 0x09830c | Địa chỉ FDE: 0x0ca1e0 | Kích thước: 256 bytes
//   0x09830c: F9400828  ldr      x8, [x1, #0x10]
//   0x098310: 3DC00020  ldr      q0, [x1]
//   0x098314: F9000808  str      x8, [x0, #0x10]
//   0x098318: AA0003E8  mov      x8, x0
static inline uint64_t fde_func_1511_0x09830c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x09830cULL ^ (static_cast<uint64_t>(0xf9400828ULL) << 13);
    acc = (acc + a1 + 0x3dc00020ULL) ^ 0x0ca1e0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1512 | PC: 0x098544 | FDE: 0x0ca2f8 | Size: 112 bytes
// Hàm FDE #1512 | Địa chỉ PC: 0x098544 | Địa chỉ FDE: 0x0ca2f8 | Kích thước: 112 bytes
//   0x098544: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x098548: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x09854c: 910043FD  add      x29, sp, #0x10
//   0x098550: 52800700  mov      w0, #0x38
static inline uint64_t fde_func_1512_0x098544(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x098544ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x0ca2f8ULL;
    acc ^= (acc >> 17) * 0x0070ULL;
    return acc;
}

// FDE #1513 | PC: 0x0985b4 | FDE: 0x0ca218 | Size: 72 bytes
// Hàm FDE #1513 | Địa chỉ PC: 0x0985b4 | Địa chỉ FDE: 0x0ca218 | Kích thước: 72 bytes
//   0x0985b4: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x0985b8: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0985bc: 910043FD  add      x29, sp, #0x10
//   0x0985c0: F9400013  ldr      x19, [x0]
static inline uint64_t fde_func_1513_0x0985b4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0985b4ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x0ca218ULL;
    acc ^= (acc >> 17) * 0x0048ULL;
    return acc;
}

// FDE #1514 | PC: 0x0985fc | FDE: 0x0ca378 | Size: 168 bytes
// Hàm FDE #1514 | Địa chỉ PC: 0x0985fc | Địa chỉ FDE: 0x0ca378 | Kích thước: 168 bytes
//   0x0985fc: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x098600: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x098604: 910043FD  add      x29, sp, #0x10
//   0x098608: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_1514_0x0985fc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0985fcULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x0ca378ULL;
    acc ^= (acc >> 17) * 0x00a8ULL;
    return acc;
}

// FDE #1515 | PC: 0x0986a4 | FDE: 0x0ca320 | Size: 20 bytes
// Hàm FDE #1515 | Địa chỉ PC: 0x0986a4 | Địa chỉ FDE: 0x0ca320 | Kích thước: 20 bytes
//   0x0986a4: F9400001  ldr      x1, [x0]
//   0x0986a8: F900001F  str      xzr, [x0]
//   0x0986ac: B4000041  cbz      x1, #0x986b4
//   0x0986b0: 140026F0  b        #0xa2270
static inline uint64_t fde_func_1515_0x0986a4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0986a4ULL ^ (static_cast<uint64_t>(0xf9400001ULL) << 13);
    acc = (acc + a1 + 0xf900001fULL) ^ 0x0ca320ULL;
    acc ^= (acc >> 17) * 0x0014ULL;
    return acc;
}

// FDE #1516 | PC: 0x0986b8 | FDE: 0x0ca3a0 | Size: 224 bytes
// Hàm FDE #1516 | Địa chỉ PC: 0x0986b8 | Địa chỉ FDE: 0x0ca3a0 | Kích thước: 224 bytes
//   0x0986b8: D10143FF  sub      sp, sp, #0x50
//   0x0986bc: A9015FF8  stp      x24, x23, [sp, #0x10]
//   0x0986c0: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x0986c4: A9034FF4  stp      x20, x19, [sp, #0x30]
static inline uint64_t fde_func_1516_0x0986b8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0986b8ULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xa9015ff8ULL) ^ 0x0ca3a0ULL;
    acc ^= (acc >> 17) * 0x00e0ULL;
    return acc;
}

// FDE #1517 | PC: 0x098798 | FDE: 0x0ca3d0 | Size: 256 bytes
// Hàm FDE #1517 | Địa chỉ PC: 0x098798 | Địa chỉ FDE: 0x0ca3d0 | Kích thước: 256 bytes
//   0x098798: D101C3FF  sub      sp, sp, #0x70
//   0x09879c: F9001BF7  str      x23, [sp, #0x30]
//   0x0987a0: A90457F6  stp      x22, x21, [sp, #0x40]
//   0x0987a4: A9054FF4  stp      x20, x19, [sp, #0x50]
static inline uint64_t fde_func_1517_0x098798(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x098798ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xf9001bf7ULL) ^ 0x0ca3d0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1518 | PC: 0x0988a0 | FDE: 0x0ca428 | Size: 112 bytes
// Hàm FDE #1518 | Địa chỉ PC: 0x0988a0 | Địa chỉ FDE: 0x0ca428 | Kích thước: 112 bytes
//   0x0988a0: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0988a4: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0988a8: 910043FD  add      x29, sp, #0x10
//   0x0988ac: 52800400  mov      w0, #0x20
static inline uint64_t fde_func_1518_0x0988a0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0988a0ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x0ca428ULL;
    acc ^= (acc >> 17) * 0x0070ULL;
    return acc;
}

// FDE #1519 | PC: 0x098910 | FDE: 0x0ca358 | Size: 72 bytes
// Hàm FDE #1519 | Địa chỉ PC: 0x098910 | Địa chỉ FDE: 0x0ca358 | Kích thước: 72 bytes
//   0x098910: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x098914: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x098918: 910043FD  add      x29, sp, #0x10
//   0x09891c: F9400013  ldr      x19, [x0]
static inline uint64_t fde_func_1519_0x098910(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x098910ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x0ca358ULL;
    acc ^= (acc >> 17) * 0x0048ULL;
    return acc;
}

// FDE #1520 | PC: 0x098958 | FDE: 0x0ca450 | Size: 12 bytes
// Hàm FDE #1520 | Địa chỉ PC: 0x098958 | Địa chỉ FDE: 0x0ca450 | Kích thước: 12 bytes
//   0x098958: F00000E1  adrp     x1, #0xb7000
//   0x09895c: 91285821  add      x1, x1, #0xa16
//   0x098960: 140033B8  b        #0xa5840
static inline uint64_t fde_func_1520_0x098958(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x098958ULL ^ (static_cast<uint64_t>(0xf00000e1ULL) << 13);
    acc = (acc + a1 + 0x91285821ULL) ^ 0x0ca450ULL;
    acc ^= (acc >> 17) * 0x000cULL;
    return acc;
}

// FDE #1521 | PC: 0x098964 | FDE: 0x0ca468 | Size: 4 bytes
// Hàm FDE #1521 | Địa chỉ PC: 0x098964 | Địa chỉ FDE: 0x0ca468 | Kích thước: 4 bytes
//   0x098964: 140033F9  b        #0xa5948
static inline uint64_t fde_func_1521_0x098964(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x098964ULL ^ (static_cast<uint64_t>(0x140033f9ULL) << 13);
    acc = (acc + a1 + 0xb4000162ULL) ^ 0x0ca468ULL;
    acc ^= (acc >> 17) * 0x0004ULL;
    return acc;
}

// FDE #1522 | PC: 0x098968 | FDE: 0x0ca480 | Size: 48 bytes [Java_com_lemon_nuro_MessageUtils_00024CppProxy_nativeDestroy]
// Hàm FDE #1522 | Địa chỉ PC: 0x098968 | Địa chỉ FDE: 0x0ca480 | Kích thước: 48 bytes
//   0x098968: B4000162  cbz      x2, #0x98994
//   0x09896c: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x098970: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x098974: 910043FD  add      x29, sp, #0x10
static inline uint64_t fde_func_1522_0x098968(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x098968ULL ^ (static_cast<uint64_t>(0xb4000162ULL) << 13);
    acc = (acc + a1 + 0xf81e0ff3ULL) ^ 0x0ca480ULL;
    acc ^= (acc >> 17) * 0x0030ULL;
    return acc;
}

// FDE #1523 | PC: 0x098998 | FDE: 0x0ca500 | Size: 252 bytes
// Hàm FDE #1523 | Địa chỉ PC: 0x098998 | Địa chỉ FDE: 0x0ca500 | Kích thước: 252 bytes
//   0x098998: D10103FF  sub      sp, sp, #0x40
//   0x09899c: F9000BF5  str      x21, [sp, #0x10]
//   0x0989a0: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x0989a4: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_1523_0x098998(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x098998ULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xf9000bf5ULL) ^ 0x0ca500ULL;
    acc ^= (acc >> 17) * 0x00fcULL;
    return acc;
}

// FDE #1524 | PC: 0x098a94 | FDE: 0x0ca528 | Size: 256 bytes [Java_com_lemon_nuro_MessageUtils_00024CppProxy_toolCalls2JsonString]
// Hàm FDE #1524 | Địa chỉ PC: 0x098a94 | Địa chỉ FDE: 0x0ca528 | Kích thước: 256 bytes
//   0x098a94: D10203FF  sub      sp, sp, #0x80
//   0x098a98: F90023F7  str      x23, [sp, #0x40]
//   0x098a9c: A90557F6  stp      x22, x21, [sp, #0x50]
//   0x098aa0: A9064FF4  stp      x20, x19, [sp, #0x60]
static inline uint64_t fde_func_1524_0x098a94(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x098a94ULL ^ (static_cast<uint64_t>(0xd10203ffULL) << 13);
    acc = (acc + a1 + 0xf90023f7ULL) ^ 0x0ca528ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1525 | PC: 0x098c08 | FDE: 0x0ca580 | Size: 108 bytes
// Hàm FDE #1525 | Địa chỉ PC: 0x098c08 | Địa chỉ FDE: 0x0ca580 | Kích thước: 108 bytes
//   0x098c08: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x098c0c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x098c10: 910043FD  add      x29, sp, #0x10
//   0x098c14: 52800300  mov      w0, #0x18
static inline uint64_t fde_func_1525_0x098c08(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x098c08ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x0ca580ULL;
    acc ^= (acc >> 17) * 0x006cULL;
    return acc;
}

// FDE #1526 | PC: 0x098c74 | FDE: 0x0ca4c0 | Size: 60 bytes
// Hàm FDE #1526 | Địa chỉ PC: 0x098c74 | Địa chỉ FDE: 0x0ca4c0 | Kích thước: 60 bytes
//   0x098c74: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x098c78: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x098c7c: 910043FD  add      x29, sp, #0x10
//   0x098c80: F9400013  ldr      x19, [x0]
static inline uint64_t fde_func_1526_0x098c74(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x098c74ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x0ca4c0ULL;
    acc ^= (acc >> 17) * 0x003cULL;
    return acc;
}

// FDE #1527 | PC: 0x098cb0 | FDE: 0x0ca4e0 | Size: 88 bytes
// Hàm FDE #1527 | Địa chỉ PC: 0x098cb0 | Địa chỉ FDE: 0x0ca4e0 | Kích thước: 88 bytes
//   0x098cb0: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x098cb4: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x098cb8: 910043FD  add      x29, sp, #0x10
//   0x098cbc: F9400413  ldr      x19, [x0, #8]
static inline uint64_t fde_func_1527_0x098cb0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x098cb0ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x0ca4e0ULL;
    acc ^= (acc >> 17) * 0x0058ULL;
    return acc;
}

// FDE #1528 | PC: 0x098d08 | FDE: 0x0ca600 | Size: 168 bytes
// Hàm FDE #1528 | Địa chỉ PC: 0x098d08 | Địa chỉ FDE: 0x0ca600 | Kích thước: 168 bytes
//   0x098d08: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x098d0c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x098d10: 910043FD  add      x29, sp, #0x10
//   0x098d14: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_1528_0x098d08(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x098d08ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x0ca600ULL;
    acc ^= (acc >> 17) * 0x00a8ULL;
    return acc;
}

// FDE #1529 | PC: 0x098db0 | FDE: 0x0ca5a8 | Size: 20 bytes
// Hàm FDE #1529 | Địa chỉ PC: 0x098db0 | Địa chỉ FDE: 0x0ca5a8 | Kích thước: 20 bytes
//   0x098db0: F9400001  ldr      x1, [x0]
//   0x098db4: F900001F  str      xzr, [x0]
//   0x098db8: B4000041  cbz      x1, #0x98dc0
//   0x098dbc: 1400252D  b        #0xa2270
static inline uint64_t fde_func_1529_0x098db0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x098db0ULL ^ (static_cast<uint64_t>(0xf9400001ULL) << 13);
    acc = (acc + a1 + 0xf900001fULL) ^ 0x0ca5a8ULL;
    acc ^= (acc >> 17) * 0x0014ULL;
    return acc;
}

// FDE #1530 | PC: 0x098dc4 | FDE: 0x0ca628 | Size: 224 bytes
// Hàm FDE #1530 | Địa chỉ PC: 0x098dc4 | Địa chỉ FDE: 0x0ca628 | Kích thước: 224 bytes
//   0x098dc4: D10143FF  sub      sp, sp, #0x50
//   0x098dc8: A9015FF8  stp      x24, x23, [sp, #0x10]
//   0x098dcc: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x098dd0: A9034FF4  stp      x20, x19, [sp, #0x30]
static inline uint64_t fde_func_1530_0x098dc4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x098dc4ULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xa9015ff8ULL) ^ 0x0ca628ULL;
    acc ^= (acc >> 17) * 0x00e0ULL;
    return acc;
}

// FDE #1531 | PC: 0x098ea4 | FDE: 0x0ca658 | Size: 252 bytes
// Hàm FDE #1531 | Địa chỉ PC: 0x098ea4 | Địa chỉ FDE: 0x0ca658 | Kích thước: 252 bytes
//   0x098ea4: D101C3FF  sub      sp, sp, #0x70
//   0x098ea8: A9035FF8  stp      x24, x23, [sp, #0x30]
//   0x098eac: A90457F6  stp      x22, x21, [sp, #0x40]
//   0x098eb0: A9054FF4  stp      x20, x19, [sp, #0x50]
static inline uint64_t fde_func_1531_0x098ea4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x098ea4ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xa9035ff8ULL) ^ 0x0ca658ULL;
    acc ^= (acc >> 17) * 0x00fcULL;
    return acc;
}

// FDE #1532 | PC: 0x098fa0 | FDE: 0x0ca6b0 | Size: 112 bytes
// Hàm FDE #1532 | Địa chỉ PC: 0x098fa0 | Địa chỉ FDE: 0x0ca6b0 | Kích thước: 112 bytes
//   0x098fa0: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x098fa4: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x098fa8: 910043FD  add      x29, sp, #0x10
//   0x098fac: 52800400  mov      w0, #0x20
static inline uint64_t fde_func_1532_0x098fa0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x098fa0ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x0ca6b0ULL;
    acc ^= (acc >> 17) * 0x0070ULL;
    return acc;
}

// FDE #1533 | PC: 0x099010 | FDE: 0x0ca5e0 | Size: 72 bytes
// Hàm FDE #1533 | Địa chỉ PC: 0x099010 | Địa chỉ FDE: 0x0ca5e0 | Kích thước: 72 bytes
//   0x099010: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x099014: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x099018: 910043FD  add      x29, sp, #0x10
//   0x09901c: F9400013  ldr      x19, [x0]
static inline uint64_t fde_func_1533_0x099010(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x099010ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x0ca5e0ULL;
    acc ^= (acc >> 17) * 0x0048ULL;
    return acc;
}

// FDE #1534 | PC: 0x099058 | FDE: 0x0ca730 | Size: 168 bytes
// Hàm FDE #1534 | Địa chỉ PC: 0x099058 | Địa chỉ FDE: 0x0ca730 | Kích thước: 168 bytes
//   0x099058: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x09905c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x099060: 910043FD  add      x29, sp, #0x10
//   0x099064: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_1534_0x099058(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x099058ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x0ca730ULL;
    acc ^= (acc >> 17) * 0x00a8ULL;
    return acc;
}

// FDE #1535 | PC: 0x099100 | FDE: 0x0ca6d8 | Size: 20 bytes
// Hàm FDE #1535 | Địa chỉ PC: 0x099100 | Địa chỉ FDE: 0x0ca6d8 | Kích thước: 20 bytes
//   0x099100: F9400001  ldr      x1, [x0]
//   0x099104: F900001F  str      xzr, [x0]
//   0x099108: B4000041  cbz      x1, #0x99110
//   0x09910c: 14002459  b        #0xa2270
static inline uint64_t fde_func_1535_0x099100(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x099100ULL ^ (static_cast<uint64_t>(0xf9400001ULL) << 13);
    acc = (acc + a1 + 0xf900001fULL) ^ 0x0ca6d8ULL;
    acc ^= (acc >> 17) * 0x0014ULL;
    return acc;
}

// FDE #1536 | PC: 0x099114 | FDE: 0x0ca758 | Size: 256 bytes
// Hàm FDE #1536 | Địa chỉ PC: 0x099114 | Địa chỉ FDE: 0x0ca758 | Kích thước: 256 bytes
//   0x099114: D101C3FF  sub      sp, sp, #0x70
//   0x099118: F90013F9  str      x25, [sp, #0x20]
//   0x09911c: A9035FF8  stp      x24, x23, [sp, #0x30]
//   0x099120: A90457F6  stp      x22, x21, [sp, #0x40]
static inline uint64_t fde_func_1536_0x099114(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x099114ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xf90013f9ULL) ^ 0x0ca758ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1537 | PC: 0x099240 | FDE: 0x0ca788 | Size: 256 bytes
// Hàm FDE #1537 | Địa chỉ PC: 0x099240 | Địa chỉ FDE: 0x0ca788 | Kích thước: 256 bytes
//   0x099240: D10243FF  sub      sp, sp, #0x90
//   0x099244: F9002BF7  str      x23, [sp, #0x50]
//   0x099248: A90657F6  stp      x22, x21, [sp, #0x60]
//   0x09924c: A9074FF4  stp      x20, x19, [sp, #0x70]
static inline uint64_t fde_func_1537_0x099240(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x099240ULL ^ (static_cast<uint64_t>(0xd10243ffULL) << 13);
    acc = (acc + a1 + 0xf9002bf7ULL) ^ 0x0ca788ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1538 | PC: 0x099368 | FDE: 0x0ca7e0 | Size: 112 bytes
// Hàm FDE #1538 | Địa chỉ PC: 0x099368 | Địa chỉ FDE: 0x0ca7e0 | Kích thước: 112 bytes
//   0x099368: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x09936c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x099370: 910043FD  add      x29, sp, #0x10
//   0x099374: 52800400  mov      w0, #0x20
static inline uint64_t fde_func_1538_0x099368(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x099368ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x0ca7e0ULL;
    acc ^= (acc >> 17) * 0x0070ULL;
    return acc;
}

// FDE #1539 | PC: 0x0993d8 | FDE: 0x0ca710 | Size: 72 bytes
// Hàm FDE #1539 | Địa chỉ PC: 0x0993d8 | Địa chỉ FDE: 0x0ca710 | Kích thước: 72 bytes
//   0x0993d8: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x0993dc: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0993e0: 910043FD  add      x29, sp, #0x10
//   0x0993e4: F9400013  ldr      x19, [x0]
static inline uint64_t fde_func_1539_0x0993d8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0993d8ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x0ca710ULL;
    acc ^= (acc >> 17) * 0x0048ULL;
    return acc;
}

// FDE #1540 | PC: 0x099420 | FDE: 0x0ca910 | Size: 168 bytes
// Hàm FDE #1540 | Địa chỉ PC: 0x099420 | Địa chỉ FDE: 0x0ca910 | Kích thước: 168 bytes
//   0x099420: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x099424: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x099428: 910043FD  add      x29, sp, #0x10
//   0x09942c: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_1540_0x099420(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x099420ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x0ca910ULL;
    acc ^= (acc >> 17) * 0x00a8ULL;
    return acc;
}

// FDE #1541 | PC: 0x0994c8 | FDE: 0x0ca808 | Size: 20 bytes
// Hàm FDE #1541 | Địa chỉ PC: 0x0994c8 | Địa chỉ FDE: 0x0ca808 | Kích thước: 20 bytes
//   0x0994c8: F9400001  ldr      x1, [x0]
//   0x0994cc: F900001F  str      xzr, [x0]
//   0x0994d0: B4000041  cbz      x1, #0x994d8
//   0x0994d4: 14002367  b        #0xa2270
static inline uint64_t fde_func_1541_0x0994c8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0994c8ULL ^ (static_cast<uint64_t>(0xf9400001ULL) << 13);
    acc = (acc + a1 + 0xf900001fULL) ^ 0x0ca808ULL;
    acc ^= (acc >> 17) * 0x0014ULL;
    return acc;
}

// FDE #1542 | PC: 0x0994dc | FDE: 0x0ca938 | Size: 256 bytes
// Hàm FDE #1542 | Địa chỉ PC: 0x0994dc | Địa chỉ FDE: 0x0ca938 | Kích thước: 256 bytes
//   0x0994dc: D101C3FF  sub      sp, sp, #0x70
//   0x0994e0: F90013F9  str      x25, [sp, #0x20]
//   0x0994e4: A9035FF8  stp      x24, x23, [sp, #0x30]
//   0x0994e8: A90457F6  stp      x22, x21, [sp, #0x40]
static inline uint64_t fde_func_1542_0x0994dc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0994dcULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xf90013f9ULL) ^ 0x0ca938ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1543 | PC: 0x099608 | FDE: 0x0ca968 | Size: 256 bytes
// Hàm FDE #1543 | Địa chỉ PC: 0x099608 | Địa chỉ FDE: 0x0ca968 | Kích thước: 256 bytes
//   0x099608: D10183FF  sub      sp, sp, #0x60
//   0x09960c: A90167FA  stp      x26, x25, [sp, #0x10]
//   0x099610: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x099614: A90357F6  stp      x22, x21, [sp, #0x30]
static inline uint64_t fde_func_1543_0x099608(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x099608ULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xa90167faULL) ^ 0x0ca968ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1544 | PC: 0x09974c | FDE: 0x0ca9a0 | Size: 256 bytes
// Hàm FDE #1544 | Địa chỉ PC: 0x09974c | Địa chỉ FDE: 0x0ca9a0 | Kích thước: 256 bytes
//   0x09974c: D10243FF  sub      sp, sp, #0x90
//   0x099750: F9002BF7  str      x23, [sp, #0x50]
//   0x099754: A90657F6  stp      x22, x21, [sp, #0x60]
//   0x099758: A9074FF4  stp      x20, x19, [sp, #0x70]
static inline uint64_t fde_func_1544_0x09974c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x09974cULL ^ (static_cast<uint64_t>(0xd10243ffULL) << 13);
    acc = (acc + a1 + 0xf9002bf7ULL) ^ 0x0ca9a0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1545 | PC: 0x099878 | FDE: 0x0ca9d0 | Size: 256 bytes
// Hàm FDE #1545 | Địa chỉ PC: 0x099878 | Địa chỉ FDE: 0x0ca9d0 | Kích thước: 256 bytes
//   0x099878: D10203FF  sub      sp, sp, #0x80
//   0x09987c: F90013FB  str      x27, [sp, #0x20]
//   0x099880: A90367FA  stp      x26, x25, [sp, #0x30]
//   0x099884: A9045FF8  stp      x24, x23, [sp, #0x40]
static inline uint64_t fde_func_1545_0x099878(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x099878ULL ^ (static_cast<uint64_t>(0xd10203ffULL) << 13);
    acc = (acc + a1 + 0xf90013fbULL) ^ 0x0ca9d0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1546 | PC: 0x099a14 | FDE: 0x0caa30 | Size: 112 bytes
// Hàm FDE #1546 | Địa chỉ PC: 0x099a14 | Địa chỉ FDE: 0x0caa30 | Kích thước: 112 bytes
//   0x099a14: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x099a18: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x099a1c: 910043FD  add      x29, sp, #0x10
//   0x099a20: 52800400  mov      w0, #0x20
static inline uint64_t fde_func_1546_0x099a14(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x099a14ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x0caa30ULL;
    acc ^= (acc >> 17) * 0x0070ULL;
    return acc;
}

// FDE #1547 | PC: 0x099a84 | FDE: 0x0ca840 | Size: 72 bytes
// Hàm FDE #1547 | Địa chỉ PC: 0x099a84 | Địa chỉ FDE: 0x0ca840 | Kích thước: 72 bytes
//   0x099a84: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x099a88: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x099a8c: 910043FD  add      x29, sp, #0x10
//   0x099a90: F9400013  ldr      x19, [x0]
static inline uint64_t fde_func_1547_0x099a84(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x099a84ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x0ca840ULL;
    acc ^= (acc >> 17) * 0x0048ULL;
    return acc;
}

// FDE #1548 | PC: 0x099acc | FDE: 0x0caa80 | Size: 212 bytes
// Hàm FDE #1548 | Địa chỉ PC: 0x099acc | Địa chỉ FDE: 0x0caa80 | Kích thước: 212 bytes
//   0x099acc: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x099ad0: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x099ad4: 910043FD  add      x29, sp, #0x10
//   0x099ad8: 52800300  mov      w0, #0x18
static inline uint64_t fde_func_1548_0x099acc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x099accULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x0caa80ULL;
    acc ^= (acc >> 17) * 0x00d4ULL;
    return acc;
}

// FDE #1549 | PC: 0x099ba0 | FDE: 0x0ca880 | Size: 72 bytes
// Hàm FDE #1549 | Địa chỉ PC: 0x099ba0 | Địa chỉ FDE: 0x0ca880 | Kích thước: 72 bytes
//   0x099ba0: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x099ba4: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x099ba8: 910043FD  add      x29, sp, #0x10
//   0x099bac: F9400013  ldr      x19, [x0]
static inline uint64_t fde_func_1549_0x099ba0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x099ba0ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x0ca880ULL;
    acc ^= (acc >> 17) * 0x0048ULL;
    return acc;
}

// FDE #1550 | PC: 0x099be8 | FDE: 0x0ca8a0 | Size: 176 bytes
// Hàm FDE #1550 | Địa chỉ PC: 0x099be8 | Địa chỉ FDE: 0x0ca8a0 | Kích thước: 176 bytes
//   0x099be8: A9BC5FF8  stp      x24, x23, [sp, #-0x40]!
//   0x099bec: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x099bf0: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x099bf4: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_1550_0x099be8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x099be8ULL ^ (static_cast<uint64_t>(0xa9bc5ff8ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x0ca8a0ULL;
    acc ^= (acc >> 17) * 0x00b0ULL;
    return acc;
}

// FDE #1551 | PC: 0x099c98 | FDE: 0x0ca8c8 | Size: 248 bytes
// Hàm FDE #1551 | Địa chỉ PC: 0x099c98 | Địa chỉ FDE: 0x0ca8c8 | Kích thước: 248 bytes
//   0x099c98: F81B0FF9  str      x25, [sp, #-0x50]!
//   0x099c9c: A9015FF8  stp      x24, x23, [sp, #0x10]
//   0x099ca0: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x099ca4: A9034FF4  stp      x20, x19, [sp, #0x30]
static inline uint64_t fde_func_1551_0x099c98(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x099c98ULL ^ (static_cast<uint64_t>(0xf81b0ff9ULL) << 13);
    acc = (acc + a1 + 0xa9015ff8ULL) ^ 0x0ca8c8ULL;
    acc ^= (acc >> 17) * 0x00f8ULL;
    return acc;
}

// FDE #1552 | PC: 0x099d90 | FDE: 0x0ca8f0 | Size: 156 bytes
// Hàm FDE #1552 | Địa chỉ PC: 0x099d90 | Địa chỉ FDE: 0x0ca8f0 | Kích thước: 156 bytes
//   0x099d90: D10483FF  sub      sp, sp, #0x120
//   0x099d94: A9104FFC  stp      x28, x19, [sp, #0x100]
//   0x099d98: A9117BFD  stp      x29, x30, [sp, #0x110]
//   0x099d9c: 910443FD  add      x29, sp, #0x110
static inline uint64_t fde_func_1552_0x099d90(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x099d90ULL ^ (static_cast<uint64_t>(0xd10483ffULL) << 13);
    acc = (acc + a1 + 0xa9104ffcULL) ^ 0x0ca8f0ULL;
    acc ^= (acc >> 17) * 0x009cULL;
    return acc;
}

// FDE #1553 | PC: 0x099e2c | FDE: 0x0cab28 | Size: 136 bytes
// Hàm FDE #1553 | Địa chỉ PC: 0x099e2c | Địa chỉ FDE: 0x0cab28 | Kích thước: 136 bytes
//   0x099e2c: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x099e30: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x099e34: 910043FD  add      x29, sp, #0x10
//   0x099e38: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_1553_0x099e2c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x099e2cULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x0cab28ULL;
    acc ^= (acc >> 17) * 0x0088ULL;
    return acc;
}

// FDE #1554 | PC: 0x099eb4 | FDE: 0x0caaa8 | Size: 20 bytes
// Hàm FDE #1554 | Địa chỉ PC: 0x099eb4 | Địa chỉ FDE: 0x0caaa8 | Kích thước: 20 bytes
//   0x099eb4: F9400001  ldr      x1, [x0]
//   0x099eb8: F900001F  str      xzr, [x0]
//   0x099ebc: B4000041  cbz      x1, #0x99ec4
//   0x099ec0: 140020EC  b        #0xa2270
static inline uint64_t fde_func_1554_0x099eb4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x099eb4ULL ^ (static_cast<uint64_t>(0xf9400001ULL) << 13);
    acc = (acc + a1 + 0xf900001fULL) ^ 0x0caaa8ULL;
    acc ^= (acc >> 17) * 0x0014ULL;
    return acc;
}

// FDE #1555 | PC: 0x099ec8 | FDE: 0x0cab50 | Size: 216 bytes
// Hàm FDE #1555 | Địa chỉ PC: 0x099ec8 | Địa chỉ FDE: 0x0cab50 | Kích thước: 216 bytes
//   0x099ec8: D10143FF  sub      sp, sp, #0x50
//   0x099ecc: F9000BF7  str      x23, [sp, #0x10]
//   0x099ed0: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x099ed4: A9034FF4  stp      x20, x19, [sp, #0x30]
static inline uint64_t fde_func_1555_0x099ec8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x099ec8ULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xf9000bf7ULL) ^ 0x0cab50ULL;
    acc ^= (acc >> 17) * 0x00d8ULL;
    return acc;
}

// FDE #1556 | PC: 0x099fa0 | FDE: 0x0cab80 | Size: 256 bytes
// Hàm FDE #1556 | Địa chỉ PC: 0x099fa0 | Địa chỉ FDE: 0x0cab80 | Kích thước: 256 bytes
//   0x099fa0: D10143FF  sub      sp, sp, #0x50
//   0x099fa4: A9015FF8  stp      x24, x23, [sp, #0x10]
//   0x099fa8: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x099fac: A9034FF4  stp      x20, x19, [sp, #0x30]
static inline uint64_t fde_func_1556_0x099fa0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x099fa0ULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xa9015ff8ULL) ^ 0x0cab80ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1557 | PC: 0x09a0d4 | FDE: 0x0cabb0 | Size: 204 bytes
// Hàm FDE #1557 | Địa chỉ PC: 0x09a0d4 | Địa chỉ FDE: 0x0cabb0 | Kích thước: 204 bytes
//   0x09a0d4: D10183FF  sub      sp, sp, #0x60
//   0x09a0d8: A90357F6  stp      x22, x21, [sp, #0x30]
//   0x09a0dc: A9044FF4  stp      x20, x19, [sp, #0x40]
//   0x09a0e0: A9057BFD  stp      x29, x30, [sp, #0x50]
static inline uint64_t fde_func_1557_0x09a0d4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x09a0d4ULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xa90357f6ULL) ^ 0x0cabb0ULL;
    acc ^= (acc >> 17) * 0x00ccULL;
    return acc;
}

// FDE #1558 | PC: 0x09a1a0 | FDE: 0x0cabe0 | Size: 256 bytes
// Hàm FDE #1558 | Địa chỉ PC: 0x09a1a0 | Địa chỉ FDE: 0x0cabe0 | Kích thước: 256 bytes
//   0x09a1a0: D10243FF  sub      sp, sp, #0x90
//   0x09a1a4: A90467FA  stp      x26, x25, [sp, #0x40]
//   0x09a1a8: A9055FF8  stp      x24, x23, [sp, #0x50]
//   0x09a1ac: A90657F6  stp      x22, x21, [sp, #0x60]
static inline uint64_t fde_func_1558_0x09a1a0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x09a1a0ULL ^ (static_cast<uint64_t>(0xd10243ffULL) << 13);
    acc = (acc + a1 + 0xa90467faULL) ^ 0x0cabe0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1559 | PC: 0x09a3e0 | FDE: 0x0cac40 | Size: 212 bytes
// Hàm FDE #1559 | Địa chỉ PC: 0x09a3e0 | Địa chỉ FDE: 0x0cac40 | Kích thước: 212 bytes
//   0x09a3e0: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x09a3e4: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x09a3e8: 910043FD  add      x29, sp, #0x10
//   0x09a3ec: 52800300  mov      w0, #0x18
static inline uint64_t fde_func_1559_0x09a3e0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x09a3e0ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x0cac40ULL;
    acc ^= (acc >> 17) * 0x00d4ULL;
    return acc;
}

// FDE #1560 | PC: 0x09a4b4 | FDE: 0x0caae0 | Size: 72 bytes
// Hàm FDE #1560 | Địa chỉ PC: 0x09a4b4 | Địa chỉ FDE: 0x0caae0 | Kích thước: 72 bytes
//   0x09a4b4: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x09a4b8: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x09a4bc: 910043FD  add      x29, sp, #0x10
//   0x09a4c0: F9400013  ldr      x19, [x0]
static inline uint64_t fde_func_1560_0x09a4b4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x09a4b4ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x0caae0ULL;
    acc ^= (acc >> 17) * 0x0048ULL;
    return acc;
}

// FDE #1561 | PC: 0x09a4fc | FDE: 0x0cab00 | Size: 256 bytes
// Hàm FDE #1561 | Địa chỉ PC: 0x09a4fc | Địa chỉ FDE: 0x0cab00 | Kích thước: 256 bytes
//   0x09a4fc: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x09a500: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x09a504: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x09a508: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1561_0x09a4fc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x09a4fcULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x0cab00ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1562 | PC: 0x09a668 | FDE: 0x0cac68 | Size: 12 bytes
// Hàm FDE #1562 | Địa chỉ PC: 0x09a668 | Địa chỉ FDE: 0x0cac68 | Kích thước: 12 bytes
//   0x09a668: B00000E1  adrp     x1, #0xb7000
//   0x09a66c: 912F5421  add      x1, x1, #0xbd5
//   0x09a670: 14002C74  b        #0xa5840
static inline uint64_t fde_func_1562_0x09a668(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x09a668ULL ^ (static_cast<uint64_t>(0xb00000e1ULL) << 13);
    acc = (acc + a1 + 0x912f5421ULL) ^ 0x0cac68ULL;
    acc ^= (acc >> 17) * 0x000cULL;
    return acc;
}

// FDE #1563 | PC: 0x09a674 | FDE: 0x0cac80 | Size: 4 bytes
// Hàm FDE #1563 | Địa chỉ PC: 0x09a674 | Địa chỉ FDE: 0x0cac80 | Kích thước: 4 bytes
//   0x09a674: 14002CB5  b        #0xa5948
static inline uint64_t fde_func_1563_0x09a674(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x09a674ULL ^ (static_cast<uint64_t>(0x14002cb5ULL) << 13);
    acc = (acc + a1 + 0xb4000162ULL) ^ 0x0cac80ULL;
    acc ^= (acc >> 17) * 0x0004ULL;
    return acc;
}

// FDE #1564 | PC: 0x09a678 | FDE: 0x0cac98 | Size: 48 bytes [Java_com_lemon_nuro_SyncChannel_00024CppProxy_nativeDestroy]
// Hàm FDE #1564 | Địa chỉ PC: 0x09a678 | Địa chỉ FDE: 0x0cac98 | Kích thước: 48 bytes
//   0x09a678: B4000162  cbz      x2, #0x9a6a4
//   0x09a67c: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x09a680: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x09a684: 910043FD  add      x29, sp, #0x10
static inline uint64_t fde_func_1564_0x09a678(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x09a678ULL ^ (static_cast<uint64_t>(0xb4000162ULL) << 13);
    acc = (acc + a1 + 0xf81e0ff3ULL) ^ 0x0cac98ULL;
    acc ^= (acc >> 17) * 0x0030ULL;
    return acc;
}

// FDE #1565 | PC: 0x09a6a8 | FDE: 0x0cae88 | Size: 252 bytes
// Hàm FDE #1565 | Địa chỉ PC: 0x09a6a8 | Địa chỉ FDE: 0x0cae88 | Kích thước: 252 bytes
//   0x09a6a8: D10103FF  sub      sp, sp, #0x40
//   0x09a6ac: F9000BF5  str      x21, [sp, #0x10]
//   0x09a6b0: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x09a6b4: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_1565_0x09a6a8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x09a6a8ULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xf9000bf5ULL) ^ 0x0cae88ULL;
    acc ^= (acc >> 17) * 0x00fcULL;
    return acc;
}

// FDE #1566 | PC: 0x09a7a4 | FDE: 0x0caeb0 | Size: 256 bytes [Java_com_lemon_nuro_SyncChannel_00024CppProxy_create]
// Hàm FDE #1566 | Địa chỉ PC: 0x09a7a4 | Địa chỉ FDE: 0x0caeb0 | Kích thước: 256 bytes
//   0x09a7a4: D10283FF  sub      sp, sp, #0xa0
//   0x09a7a8: F90033F7  str      x23, [sp, #0x60]
//   0x09a7ac: A90757F6  stp      x22, x21, [sp, #0x70]
//   0x09a7b0: A9084FF4  stp      x20, x19, [sp, #0x80]
static inline uint64_t fde_func_1566_0x09a7a4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x09a7a4ULL ^ (static_cast<uint64_t>(0xd10283ffULL) << 13);
    acc = (acc + a1 + 0xf90033f7ULL) ^ 0x0caeb0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1567 | PC: 0x09a91c | FDE: 0x0cacb8 | Size: 88 bytes
// Hàm FDE #1567 | Địa chỉ PC: 0x09a91c | Địa chỉ FDE: 0x0cacb8 | Kích thước: 88 bytes
//   0x09a91c: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x09a920: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x09a924: 910043FD  add      x29, sp, #0x10
//   0x09a928: F9400413  ldr      x19, [x0, #8]
static inline uint64_t fde_func_1567_0x09a91c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x09a91cULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x0cacb8ULL;
    acc ^= (acc >> 17) * 0x0058ULL;
    return acc;
}

// FDE #1568 | PC: 0x09a974 | FDE: 0x0caee0 | Size: 256 bytes [Java_com_lemon_nuro_SyncChannel_00024CppProxy_native_1listen]
// Hàm FDE #1568 | Địa chỉ PC: 0x09a974 | Địa chỉ FDE: 0x0caee0 | Kích thước: 256 bytes
//   0x09a974: D10183FF  sub      sp, sp, #0x60
//   0x09a978: F90013F7  str      x23, [sp, #0x20]
//   0x09a97c: A90357F6  stp      x22, x21, [sp, #0x30]
//   0x09a980: A9044FF4  stp      x20, x19, [sp, #0x40]
static inline uint64_t fde_func_1568_0x09a974(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x09a974ULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xf90013f7ULL) ^ 0x0caee0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1569 | PC: 0x09aaac | FDE: 0x0caf10 | Size: 256 bytes [Java_com_lemon_nuro_SyncChannel_00024CppProxy_native_1connect]
// Hàm FDE #1569 | Địa chỉ PC: 0x09aaac | Địa chỉ FDE: 0x0caf10 | Kích thước: 256 bytes
//   0x09aaac: D101C3FF  sub      sp, sp, #0x70
//   0x09aab0: F9001BF7  str      x23, [sp, #0x30]
//   0x09aab4: A90457F6  stp      x22, x21, [sp, #0x40]
//   0x09aab8: A9054FF4  stp      x20, x19, [sp, #0x50]
static inline uint64_t fde_func_1569_0x09aaac(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x09aaacULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xf9001bf7ULL) ^ 0x0caf10ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1570 | PC: 0x09ac68 | FDE: 0x0caf40 | Size: 256 bytes [Java_com_lemon_nuro_SyncChannel_00024CppProxy_native_1sync]
// Hàm FDE #1570 | Địa chỉ PC: 0x09ac68 | Địa chỉ FDE: 0x0caf40 | Kích thước: 256 bytes
//   0x09ac68: D10303FF  sub      sp, sp, #0xc0
//   0x09ac6c: A90957F6  stp      x22, x21, [sp, #0x90]
//   0x09ac70: A90A4FF4  stp      x20, x19, [sp, #0xa0]
//   0x09ac74: A90B7BFD  stp      x29, x30, [sp, #0xb0]
static inline uint64_t fde_func_1570_0x09ac68(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x09ac68ULL ^ (static_cast<uint64_t>(0xd10303ffULL) << 13);
    acc = (acc + a1 + 0xa90957f6ULL) ^ 0x0caf40ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1571 | PC: 0x09adc4 | FDE: 0x0caf70 | Size: 92 bytes [Java_com_lemon_nuro_SyncChannel_00024CppProxy_native_1flush]
// Hàm FDE #1571 | Địa chỉ PC: 0x09adc4 | Địa chỉ FDE: 0x0caf70 | Kích thước: 92 bytes
//   0x09adc4: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x09adc8: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x09adcc: 910043FD  add      x29, sp, #0x10
//   0x09add0: F9400848  ldr      x8, [x2, #0x10]
static inline uint64_t fde_func_1571_0x09adc4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x09adc4ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x0caf70ULL;
    acc ^= (acc >> 17) * 0x005cULL;
    return acc;
}

// FDE #1572 | PC: 0x09ae20 | FDE: 0x0caf98 | Size: 256 bytes [Java_com_lemon_nuro_SyncChannel_00024CppProxy_native_1setFileUploader]
// Hàm FDE #1572 | Địa chỉ PC: 0x09ae20 | Địa chỉ FDE: 0x0caf98 | Kích thước: 256 bytes
//   0x09ae20: D10183FF  sub      sp, sp, #0x60
//   0x09ae24: F90013F7  str      x23, [sp, #0x20]
//   0x09ae28: A90357F6  stp      x22, x21, [sp, #0x30]
//   0x09ae2c: A9044FF4  stp      x20, x19, [sp, #0x40]
static inline uint64_t fde_func_1572_0x09ae20(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x09ae20ULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xf90013f7ULL) ^ 0x0caf98ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1573 | PC: 0x09af58 | FDE: 0x0caff0 | Size: 108 bytes
// Hàm FDE #1573 | Địa chỉ PC: 0x09af58 | Địa chỉ FDE: 0x0caff0 | Kích thước: 108 bytes
//   0x09af58: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x09af5c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x09af60: 910043FD  add      x29, sp, #0x10
//   0x09af64: 52800300  mov      w0, #0x18
static inline uint64_t fde_func_1573_0x09af58(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x09af58ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x0caff0ULL;
    acc ^= (acc >> 17) * 0x006cULL;
    return acc;
}

// FDE #1574 | PC: 0x09afc4 | FDE: 0x0cacf8 | Size: 60 bytes
// Hàm FDE #1574 | Địa chỉ PC: 0x09afc4 | Địa chỉ FDE: 0x0cacf8 | Kích thước: 60 bytes
//   0x09afc4: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x09afc8: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x09afcc: 910043FD  add      x29, sp, #0x10
//   0x09afd0: F9400013  ldr      x19, [x0]
static inline uint64_t fde_func_1574_0x09afc4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x09afc4ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x0cacf8ULL;
    acc ^= (acc >> 17) * 0x003cULL;
    return acc;
}

// FDE #1575 | PC: 0x09b000 | FDE: 0x0cb040 | Size: 100 bytes
// Hàm FDE #1575 | Địa chỉ PC: 0x09b000 | Địa chỉ FDE: 0x0cb040 | Kích thước: 100 bytes
//   0x09b000: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x09b004: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x09b008: 910043FD  add      x29, sp, #0x10
//   0x09b00c: 52800900  mov      w0, #0x48
static inline uint64_t fde_func_1575_0x09b000(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x09b000ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x0cb040ULL;
    acc ^= (acc >> 17) * 0x0064ULL;
    return acc;
}

// FDE #1576 | PC: 0x09b064 | FDE: 0x0cad38 | Size: 60 bytes
// Hàm FDE #1576 | Địa chỉ PC: 0x09b064 | Địa chỉ FDE: 0x0cad38 | Kích thước: 60 bytes
//   0x09b064: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x09b068: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x09b06c: 910043FD  add      x29, sp, #0x10
//   0x09b070: F9400013  ldr      x19, [x0]
static inline uint64_t fde_func_1576_0x09b064(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x09b064ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x0cad38ULL;
    acc ^= (acc >> 17) * 0x003cULL;
    return acc;
}

// FDE #1577 | PC: 0x09b0a0 | FDE: 0x0cb068 | Size: 256 bytes
// Hàm FDE #1577 | Địa chỉ PC: 0x09b0a0 | Địa chỉ FDE: 0x0cb068 | Kích thước: 256 bytes
//   0x09b0a0: D10143FF  sub      sp, sp, #0x50
//   0x09b0a4: F90013F5  str      x21, [sp, #0x20]
//   0x09b0a8: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x09b0ac: A9047BFD  stp      x29, x30, [sp, #0x40]
static inline uint64_t fde_func_1577_0x09b0a0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x09b0a0ULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xf90013f5ULL) ^ 0x0cb068ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1578 | PC: 0x09b1bc | FDE: 0x0cb090 | Size: 256 bytes
// Hàm FDE #1578 | Địa chỉ PC: 0x09b1bc | Địa chỉ FDE: 0x0cb090 | Kích thước: 256 bytes
//   0x09b1bc: A9BC5FF8  stp      x24, x23, [sp, #-0x40]!
//   0x09b1c0: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x09b1c4: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x09b1c8: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_1578_0x09b1bc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x09b1bcULL ^ (static_cast<uint64_t>(0xa9bc5ff8ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x0cb090ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1579 | PC: 0x09b2cc | FDE: 0x0cad58 | Size: 256 bytes
// Hàm FDE #1579 | Địa chỉ PC: 0x09b2cc | Địa chỉ FDE: 0x0cad58 | Kích thước: 256 bytes
//   0x09b2cc: D101C3FF  sub      sp, sp, #0x70
//   0x09b2d0: F9001BF7  str      x23, [sp, #0x30]
//   0x09b2d4: A90457F6  stp      x22, x21, [sp, #0x40]
//   0x09b2d8: A9054FF4  stp      x20, x19, [sp, #0x50]
static inline uint64_t fde_func_1579_0x09b2cc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x09b2ccULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xf9001bf7ULL) ^ 0x0cad58ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1580 | PC: 0x09b44c | FDE: 0x0cb0c0 | Size: 204 bytes
// Hàm FDE #1580 | Địa chỉ PC: 0x09b44c | Địa chỉ FDE: 0x0cb0c0 | Kích thước: 204 bytes
//   0x09b44c: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x09b450: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x09b454: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x09b458: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1580_0x09b44c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x09b44cULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x0cb0c0ULL;
    acc ^= (acc >> 17) * 0x00ccULL;
    return acc;
}

// FDE #1581 | PC: 0x09b518 | FDE: 0x0cad80 | Size: 48 bytes
// Hàm FDE #1581 | Địa chỉ PC: 0x09b518 | Địa chỉ FDE: 0x0cad80 | Kích thước: 48 bytes
//   0x09b518: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x09b51c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x09b520: 910043FD  add      x29, sp, #0x10
//   0x09b524: 90000288  adrp     x8, #0xeb000
static inline uint64_t fde_func_1581_0x09b518(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x09b518ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x0cad80ULL;
    acc ^= (acc >> 17) * 0x0030ULL;
    return acc;
}

// FDE #1582 | PC: 0x09b548 | FDE: 0x0cada0 | Size: 56 bytes
// Hàm FDE #1582 | Địa chỉ PC: 0x09b548 | Địa chỉ FDE: 0x0cada0 | Kích thước: 56 bytes
//   0x09b548: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x09b54c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x09b550: 910043FD  add      x29, sp, #0x10
//   0x09b554: 90000288  adrp     x8, #0xeb000
static inline uint64_t fde_func_1582_0x09b548(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x09b548ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x0cada0ULL;
    acc ^= (acc >> 17) * 0x0038ULL;
    return acc;
}

// FDE #1583 | PC: 0x09b580 | FDE: 0x0cadc0 | Size: 8 bytes
// Hàm FDE #1583 | Địa chỉ PC: 0x09b580 | Địa chỉ FDE: 0x0cadc0 | Kích thước: 8 bytes
//   0x09b580: 91006000  add      x0, x0, #0x18
//   0x09b584: 14000133  b        #0x9ba50
static inline uint64_t fde_func_1583_0x09b580(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x09b580ULL ^ (static_cast<uint64_t>(0x91006000ULL) << 13);
    acc = (acc + a1 + 0x14000133ULL) ^ 0x0cadc0ULL;
    acc ^= (acc >> 17) * 0x0008ULL;
    return acc;
}

// FDE #1584 | PC: 0x09b588 | FDE: 0x0cadd8 | Size: 4 bytes
// Hàm FDE #1584 | Địa chỉ PC: 0x09b588 | Địa chỉ FDE: 0x0cadd8 | Kích thước: 4 bytes
//   0x09b588: 17FDDC9E  b        #0x12800
static inline uint64_t fde_func_1584_0x09b588(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x09b588ULL ^ (static_cast<uint64_t>(0x17fddc9eULL) << 13);
    acc = (acc + a1 + 0xd101c3ffULL) ^ 0x0cadd8ULL;
    acc ^= (acc >> 17) * 0x0004ULL;
    return acc;
}

// FDE #1585 | PC: 0x09b58c | FDE: 0x0cadf0 | Size: 256 bytes
// Hàm FDE #1585 | Địa chỉ PC: 0x09b58c | Địa chỉ FDE: 0x0cadf0 | Kích thước: 256 bytes
//   0x09b58c: D101C3FF  sub      sp, sp, #0x70
//   0x09b590: F9001BF7  str      x23, [sp, #0x30]
//   0x09b594: A90457F6  stp      x22, x21, [sp, #0x40]
//   0x09b598: A9054FF4  stp      x20, x19, [sp, #0x50]
static inline uint64_t fde_func_1585_0x09b58c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x09b58cULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xf9001bf7ULL) ^ 0x0cadf0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1586 | PC: 0x09b70c | FDE: 0x0cb0f0 | Size: 204 bytes
// Hàm FDE #1586 | Địa chỉ PC: 0x09b70c | Địa chỉ FDE: 0x0cb0f0 | Kích thước: 204 bytes
//   0x09b70c: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x09b710: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x09b714: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x09b718: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1586_0x09b70c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x09b70cULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x0cb0f0ULL;
    acc ^= (acc >> 17) * 0x00ccULL;
    return acc;
}

// FDE #1587 | PC: 0x09b7d8 | FDE: 0x0cae18 | Size: 48 bytes
// Hàm FDE #1587 | Địa chỉ PC: 0x09b7d8 | Địa chỉ FDE: 0x0cae18 | Kích thước: 48 bytes
//   0x09b7d8: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x09b7dc: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x09b7e0: 910043FD  add      x29, sp, #0x10
//   0x09b7e4: 90000288  adrp     x8, #0xeb000
static inline uint64_t fde_func_1587_0x09b7d8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x09b7d8ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x0cae18ULL;
    acc ^= (acc >> 17) * 0x0030ULL;
    return acc;
}

// FDE #1588 | PC: 0x09b808 | FDE: 0x0cae38 | Size: 56 bytes
// Hàm FDE #1588 | Địa chỉ PC: 0x09b808 | Địa chỉ FDE: 0x0cae38 | Kích thước: 56 bytes
//   0x09b808: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x09b80c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x09b810: 910043FD  add      x29, sp, #0x10
//   0x09b814: 90000288  adrp     x8, #0xeb000
static inline uint64_t fde_func_1588_0x09b808(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x09b808ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x0cae38ULL;
    acc ^= (acc >> 17) * 0x0038ULL;
    return acc;
}

// FDE #1589 | PC: 0x09b840 | FDE: 0x0cae58 | Size: 8 bytes
// Hàm FDE #1589 | Địa chỉ PC: 0x09b840 | Địa chỉ FDE: 0x0cae58 | Kích thước: 8 bytes
//   0x09b840: 91006000  add      x0, x0, #0x18
//   0x09b844: 17FFE855  b        #0x95998
static inline uint64_t fde_func_1589_0x09b840(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x09b840ULL ^ (static_cast<uint64_t>(0x91006000ULL) << 13);
    acc = (acc + a1 + 0x17ffe855ULL) ^ 0x0cae58ULL;
    acc ^= (acc >> 17) * 0x0008ULL;
    return acc;
}

// FDE #1590 | PC: 0x09b848 | FDE: 0x0cae70 | Size: 4 bytes
// Hàm FDE #1590 | Địa chỉ PC: 0x09b848 | Địa chỉ FDE: 0x0cae70 | Kích thước: 4 bytes
//   0x09b848: 17FDDBEE  b        #0x12800
static inline uint64_t fde_func_1590_0x09b848(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x09b848ULL ^ (static_cast<uint64_t>(0x17fddbeeULL) << 13);
    acc = (acc + a1 + 0xf81d0ff5ULL) ^ 0x0cae70ULL;
    acc ^= (acc >> 17) * 0x0004ULL;
    return acc;
}

// FDE #1591 | PC: 0x09b84c | FDE: 0x0cb198 | Size: 256 bytes
// Hàm FDE #1591 | Địa chỉ PC: 0x09b84c | Địa chỉ FDE: 0x0cb198 | Kích thước: 256 bytes
//   0x09b84c: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x09b850: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x09b854: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x09b858: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1591_0x09b84c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x09b84cULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x0cb198ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1592 | PC: 0x09b95c | FDE: 0x0cb120 | Size: 48 bytes
// Hàm FDE #1592 | Địa chỉ PC: 0x09b95c | Địa chỉ FDE: 0x0cb120 | Kích thước: 48 bytes
//   0x09b95c: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x09b960: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x09b964: 910043FD  add      x29, sp, #0x10
//   0x09b968: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_1592_0x09b95c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x09b95cULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x0cb120ULL;
    acc ^= (acc >> 17) * 0x0030ULL;
    return acc;
}

// FDE #1593 | PC: 0x09b98c | FDE: 0x0cb1c0 | Size: 196 bytes
// Hàm FDE #1593 | Địa chỉ PC: 0x09b98c | Địa chỉ FDE: 0x0cb1c0 | Kích thước: 196 bytes
//   0x09b98c: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x09b990: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x09b994: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x09b998: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1593_0x09b98c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x09b98cULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x0cb1c0ULL;
    acc ^= (acc >> 17) * 0x00c4ULL;
    return acc;
}

// FDE #1594 | PC: 0x09ba50 | FDE: 0x0cb140 | Size: 8 bytes
// Hàm FDE #1594 | Địa chỉ PC: 0x09ba50 | Địa chỉ FDE: 0x0cb140 | Kích thước: 8 bytes
//   0x09ba50: 91002000  add      x0, x0, #8
//   0x09ba54: 14000001  b        #0x9ba58
static inline uint64_t fde_func_1594_0x09ba50(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x09ba50ULL ^ (static_cast<uint64_t>(0x91002000ULL) << 13);
    acc = (acc + a1 + 0x14000001ULL) ^ 0x0cb140ULL;
    acc ^= (acc >> 17) * 0x0008ULL;
    return acc;
}

// FDE #1595 | PC: 0x09ba58 | FDE: 0x0cb1e8 | Size: 232 bytes
// Hàm FDE #1595 | Địa chỉ PC: 0x09ba58 | Địa chỉ FDE: 0x0cb1e8 | Kích thước: 232 bytes
//   0x09ba58: D10103FF  sub      sp, sp, #0x40
//   0x09ba5c: F9000BF5  str      x21, [sp, #0x10]
//   0x09ba60: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x09ba64: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_1595_0x09ba58(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x09ba58ULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xf9000bf5ULL) ^ 0x0cb1e8ULL;
    acc ^= (acc >> 17) * 0x00e8ULL;
    return acc;
}

// FDE #1596 | PC: 0x09bb40 | FDE: 0x0cb158 | Size: 40 bytes
// Hàm FDE #1596 | Địa chỉ PC: 0x09bb40 | Địa chỉ FDE: 0x0cb158 | Kích thước: 40 bytes
//   0x09bb40: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x09bb44: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x09bb48: 910043FD  add      x29, sp, #0x10
//   0x09bb4c: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_1596_0x09bb40(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x09bb40ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x0cb158ULL;
    acc ^= (acc >> 17) * 0x0028ULL;
    return acc;
}

// FDE #1597 | PC: 0x09bb68 | FDE: 0x0cb210 | Size: 256 bytes
// Hàm FDE #1597 | Địa chỉ PC: 0x09bb68 | Địa chỉ FDE: 0x0cb210 | Kích thước: 256 bytes
//   0x09bb68: D10183FF  sub      sp, sp, #0x60
//   0x09bb6c: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x09bb70: A90357F6  stp      x22, x21, [sp, #0x30]
//   0x09bb74: A9044FF4  stp      x20, x19, [sp, #0x40]
static inline uint64_t fde_func_1597_0x09bb68(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x09bb68ULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xa9025ff8ULL) ^ 0x0cb210ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1598 | PC: 0x09bc70 | FDE: 0x0cb240 | Size: 256 bytes
// Hàm FDE #1598 | Địa chỉ PC: 0x09bc70 | Địa chỉ FDE: 0x0cb240 | Kích thước: 256 bytes
//   0x09bc70: D10183FF  sub      sp, sp, #0x60
//   0x09bc74: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x09bc78: A90357F6  stp      x22, x21, [sp, #0x30]
//   0x09bc7c: A9044FF4  stp      x20, x19, [sp, #0x40]
static inline uint64_t fde_func_1598_0x09bc70(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x09bc70ULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xa9025ff8ULL) ^ 0x0cb240ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1599 | PC: 0x09bd78 | FDE: 0x0cb270 | Size: 256 bytes
// Hàm FDE #1599 | Địa chỉ PC: 0x09bd78 | Địa chỉ FDE: 0x0cb270 | Kích thước: 256 bytes
//   0x09bd78: D101C3FF  sub      sp, sp, #0x70
//   0x09bd7c: A9035FF8  stp      x24, x23, [sp, #0x30]
//   0x09bd80: A90457F6  stp      x22, x21, [sp, #0x40]
//   0x09bd84: A9054FF4  stp      x20, x19, [sp, #0x50]
static inline uint64_t fde_func_1599_0x09bd78(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x09bd78ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xa9035ff8ULL) ^ 0x0cb270ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1600 | PC: 0x09bec4 | FDE: 0x0cb2a0 | Size: 256 bytes
// Hàm FDE #1600 | Địa chỉ PC: 0x09bec4 | Địa chỉ FDE: 0x0cb2a0 | Kích thước: 256 bytes
//   0x09bec4: D10183FF  sub      sp, sp, #0x60
//   0x09bec8: F90013F7  str      x23, [sp, #0x20]
//   0x09becc: A90357F6  stp      x22, x21, [sp, #0x30]
//   0x09bed0: A9044FF4  stp      x20, x19, [sp, #0x40]
static inline uint64_t fde_func_1600_0x09bec4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x09bec4ULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xf90013f7ULL) ^ 0x0cb2a0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1601 | PC: 0x09bfc4 | FDE: 0x0cb2d0 | Size: 256 bytes
// Hàm FDE #1601 | Địa chỉ PC: 0x09bfc4 | Địa chỉ FDE: 0x0cb2d0 | Kích thước: 256 bytes
//   0x09bfc4: D10183FF  sub      sp, sp, #0x60
//   0x09bfc8: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x09bfcc: A90357F6  stp      x22, x21, [sp, #0x30]
//   0x09bfd0: A9044FF4  stp      x20, x19, [sp, #0x40]
static inline uint64_t fde_func_1601_0x09bfc4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x09bfc4ULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xa9025ff8ULL) ^ 0x0cb2d0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1602 | PC: 0x09c0cc | FDE: 0x0cb178 | Size: 48 bytes [Java_com_lemon_nuro_SyncChannelListener_00024CppProxy_nativeDestroy]
// Hàm FDE #1602 | Địa chỉ PC: 0x09c0cc | Địa chỉ FDE: 0x0cb178 | Kích thước: 48 bytes
//   0x09c0cc: B4000162  cbz      x2, #0x9c0f8
//   0x09c0d0: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x09c0d4: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x09c0d8: 910043FD  add      x29, sp, #0x10
static inline uint64_t fde_func_1602_0x09c0cc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x09c0ccULL ^ (static_cast<uint64_t>(0xb4000162ULL) << 13);
    acc = (acc + a1 + 0xf81e0ff3ULL) ^ 0x0cb178ULL;
    acc ^= (acc >> 17) * 0x0030ULL;
    return acc;
}

// FDE #1603 | PC: 0x09c0fc | FDE: 0x0cb300 | Size: 252 bytes
// Hàm FDE #1603 | Địa chỉ PC: 0x09c0fc | Địa chỉ FDE: 0x0cb300 | Kích thước: 252 bytes
//   0x09c0fc: D10103FF  sub      sp, sp, #0x40
//   0x09c100: F9000BF5  str      x21, [sp, #0x10]
//   0x09c104: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x09c108: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_1603_0x09c0fc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x09c0fcULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xf9000bf5ULL) ^ 0x0cb300ULL;
    acc ^= (acc >> 17) * 0x00fcULL;
    return acc;
}

// FDE #1604 | PC: 0x09c1f8 | FDE: 0x0cb328 | Size: 216 bytes [Java_com_lemon_nuro_SyncChannelListener_00024CppProxy_native_1onAck]
// Hàm FDE #1604 | Địa chỉ PC: 0x09c1f8 | Địa chỉ FDE: 0x0cb328 | Kích thước: 216 bytes
//   0x09c1f8: D10143FF  sub      sp, sp, #0x50
//   0x09c1fc: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x09c200: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x09c204: A9047BFD  stp      x29, x30, [sp, #0x40]
static inline uint64_t fde_func_1604_0x09c1f8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x09c1f8ULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xa90257f6ULL) ^ 0x0cb328ULL;
    acc ^= (acc >> 17) * 0x00d8ULL;
    return acc;
}

// FDE #1605 | PC: 0x09c2d0 | FDE: 0x0cb358 | Size: 216 bytes [Java_com_lemon_nuro_SyncChannelListener_00024CppProxy_native_1onNack]
// Hàm FDE #1605 | Địa chỉ PC: 0x09c2d0 | Địa chỉ FDE: 0x0cb358 | Kích thước: 216 bytes
//   0x09c2d0: D10143FF  sub      sp, sp, #0x50
//   0x09c2d4: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x09c2d8: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x09c2dc: A9047BFD  stp      x29, x30, [sp, #0x40]
static inline uint64_t fde_func_1605_0x09c2d0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x09c2d0ULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xa90257f6ULL) ^ 0x0cb358ULL;
    acc ^= (acc >> 17) * 0x00d8ULL;
    return acc;
}

// FDE #1606 | PC: 0x09c3a8 | FDE: 0x0cb388 | Size: 256 bytes [Java_com_lemon_nuro_SyncChannelListener_00024CppProxy_native_1onQuery]
// Hàm FDE #1606 | Địa chỉ PC: 0x09c3a8 | Địa chỉ FDE: 0x0cb388 | Kích thước: 256 bytes
//   0x09c3a8: D101C3FF  sub      sp, sp, #0x70
//   0x09c3ac: A90457F6  stp      x22, x21, [sp, #0x40]
//   0x09c3b0: A9054FF4  stp      x20, x19, [sp, #0x50]
//   0x09c3b4: A9067BFD  stp      x29, x30, [sp, #0x60]
static inline uint64_t fde_func_1606_0x09c3a8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x09c3a8ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xa90457f6ULL) ^ 0x0cb388ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1607 | PC: 0x09c4c4 | FDE: 0x0cb3b8 | Size: 208 bytes [Java_com_lemon_nuro_SyncChannelListener_00024CppProxy_native_1onCollect]
// Hàm FDE #1607 | Địa chỉ PC: 0x09c4c4 | Địa chỉ FDE: 0x0cb3b8 | Kích thước: 208 bytes
//   0x09c4c4: D10143FF  sub      sp, sp, #0x50
//   0x09c4c8: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x09c4cc: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x09c4d0: A9047BFD  stp      x29, x30, [sp, #0x40]
static inline uint64_t fde_func_1607_0x09c4c4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x09c4c4ULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xa90257f6ULL) ^ 0x0cb3b8ULL;
    acc ^= (acc >> 17) * 0x00d0ULL;
    return acc;
}

// FDE #1608 | PC: 0x09c594 | FDE: 0x0cb3e8 | Size: 256 bytes [Java_com_lemon_nuro_SyncChannelListener_00024CppProxy_native_1onSentResult]
// Hàm FDE #1608 | Địa chỉ PC: 0x09c594 | Địa chỉ FDE: 0x0cb3e8 | Kích thước: 256 bytes
//   0x09c594: D101C3FF  sub      sp, sp, #0x70
//   0x09c598: F90013F9  str      x25, [sp, #0x20]
//   0x09c59c: A9035FF8  stp      x24, x23, [sp, #0x30]
//   0x09c5a0: A90457F6  stp      x22, x21, [sp, #0x40]
static inline uint64_t fde_func_1608_0x09c594(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x09c594ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xf90013f9ULL) ^ 0x0cb3e8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1609 | PC: 0x09c718 | FDE: 0x0cb470 | Size: 256 bytes
// Hàm FDE #1609 | Địa chỉ PC: 0x09c718 | Địa chỉ FDE: 0x0cb470 | Kích thước: 256 bytes
//   0x09c718: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x09c71c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x09c720: 910043FD  add      x29, sp, #0x10
//   0x09c724: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_1609_0x09c718(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x09c718ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x0cb470ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1610 | PC: 0x09c840 | FDE: 0x0cb418 | Size: 20 bytes
// Hàm FDE #1610 | Địa chỉ PC: 0x09c840 | Địa chỉ FDE: 0x0cb418 | Kích thước: 20 bytes
//   0x09c840: F9400001  ldr      x1, [x0]
//   0x09c844: F900001F  str      xzr, [x0]
//   0x09c848: B4000041  cbz      x1, #0x9c850
//   0x09c84c: 14001689  b        #0xa2270
static inline uint64_t fde_func_1610_0x09c840(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x09c840ULL ^ (static_cast<uint64_t>(0xf9400001ULL) << 13);
    acc = (acc + a1 + 0xf900001fULL) ^ 0x0cb418ULL;
    acc ^= (acc >> 17) * 0x0014ULL;
    return acc;
}

// FDE #1611 | PC: 0x09c854 | FDE: 0x0cb498 | Size: 256 bytes
// Hàm FDE #1611 | Địa chỉ PC: 0x09c854 | Địa chỉ FDE: 0x0cb498 | Kích thước: 256 bytes
//   0x09c854: D102C3FF  sub      sp, sp, #0xb0
//   0x09c858: A9056FFC  stp      x28, x27, [sp, #0x50]
//   0x09c85c: A90667FA  stp      x26, x25, [sp, #0x60]
//   0x09c860: A9075FF8  stp      x24, x23, [sp, #0x70]
static inline uint64_t fde_func_1611_0x09c854(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x09c854ULL ^ (static_cast<uint64_t>(0xd102c3ffULL) << 13);
    acc = (acc + a1 + 0xa9056ffcULL) ^ 0x0cb498ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1612 | PC: 0x09cb9c | FDE: 0x0cb4d0 | Size: 256 bytes
// Hàm FDE #1612 | Địa chỉ PC: 0x09cb9c | Địa chỉ FDE: 0x0cb4d0 | Kích thước: 256 bytes
//   0x09cb9c: D10383FF  sub      sp, sp, #0xe0
//   0x09cba0: A9086FFC  stp      x28, x27, [sp, #0x80]
//   0x09cba4: A90967FA  stp      x26, x25, [sp, #0x90]
//   0x09cba8: A90A5FF8  stp      x24, x23, [sp, #0xa0]
static inline uint64_t fde_func_1612_0x09cb9c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x09cb9cULL ^ (static_cast<uint64_t>(0xd10383ffULL) << 13);
    acc = (acc + a1 + 0xa9086ffcULL) ^ 0x0cb4d0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1613 | PC: 0x09cf2c | FDE: 0x0cb530 | Size: 112 bytes
// Hàm FDE #1613 | Địa chỉ PC: 0x09cf2c | Địa chỉ FDE: 0x0cb530 | Kích thước: 112 bytes
//   0x09cf2c: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x09cf30: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x09cf34: 910043FD  add      x29, sp, #0x10
//   0x09cf38: 52800800  mov      w0, #0x40
static inline uint64_t fde_func_1613_0x09cf2c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x09cf2cULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x0cb530ULL;
    acc ^= (acc >> 17) * 0x0070ULL;
    return acc;
}

// FDE #1614 | PC: 0x09cf9c | FDE: 0x0cb450 | Size: 72 bytes
// Hàm FDE #1614 | Địa chỉ PC: 0x09cf9c | Địa chỉ FDE: 0x0cb450 | Kích thước: 72 bytes
//   0x09cf9c: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x09cfa0: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x09cfa4: 910043FD  add      x29, sp, #0x10
//   0x09cfa8: F9400013  ldr      x19, [x0]
static inline uint64_t fde_func_1614_0x09cf9c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x09cf9cULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x0cb450ULL;
    acc ^= (acc >> 17) * 0x0048ULL;
    return acc;
}

// FDE #1615 | PC: 0x09cfe4 | FDE: 0x0cb5f0 | Size: 256 bytes
// Hàm FDE #1615 | Địa chỉ PC: 0x09cfe4 | Địa chỉ FDE: 0x0cb5f0 | Kích thước: 256 bytes
//   0x09cfe4: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x09cfe8: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x09cfec: 910043FD  add      x29, sp, #0x10
//   0x09cff0: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_1615_0x09cfe4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x09cfe4ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x0cb5f0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1616 | PC: 0x09d10c | FDE: 0x0cb558 | Size: 20 bytes
// Hàm FDE #1616 | Địa chỉ PC: 0x09d10c | Địa chỉ FDE: 0x0cb558 | Kích thước: 20 bytes
//   0x09d10c: F9400001  ldr      x1, [x0]
//   0x09d110: F900001F  str      xzr, [x0]
//   0x09d114: B4000041  cbz      x1, #0x9d11c
//   0x09d118: 14001456  b        #0xa2270
static inline uint64_t fde_func_1616_0x09d10c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x09d10cULL ^ (static_cast<uint64_t>(0xf9400001ULL) << 13);
    acc = (acc + a1 + 0xf900001fULL) ^ 0x0cb558ULL;
    acc ^= (acc >> 17) * 0x0014ULL;
    return acc;
}

// FDE #1617 | PC: 0x09d120 | FDE: 0x0cb618 | Size: 256 bytes
// Hàm FDE #1617 | Địa chỉ PC: 0x09d120 | Địa chỉ FDE: 0x0cb618 | Kích thước: 256 bytes
//   0x09d120: D10283FF  sub      sp, sp, #0xa0
//   0x09d124: A9046FFC  stp      x28, x27, [sp, #0x40]
//   0x09d128: A90567FA  stp      x26, x25, [sp, #0x50]
//   0x09d12c: A9065FF8  stp      x24, x23, [sp, #0x60]
static inline uint64_t fde_func_1617_0x09d120(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x09d120ULL ^ (static_cast<uint64_t>(0xd10283ffULL) << 13);
    acc = (acc + a1 + 0xa9046ffcULL) ^ 0x0cb618ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1618 | PC: 0x09d36c | FDE: 0x0cb650 | Size: 256 bytes
// Hàm FDE #1618 | Địa chỉ PC: 0x09d36c | Địa chỉ FDE: 0x0cb650 | Kích thước: 256 bytes
//   0x09d36c: D10383FF  sub      sp, sp, #0xe0
//   0x09d370: A9086FFC  stp      x28, x27, [sp, #0x80]
//   0x09d374: A90967FA  stp      x26, x25, [sp, #0x90]
//   0x09d378: A90A5FF8  stp      x24, x23, [sp, #0xa0]
static inline uint64_t fde_func_1618_0x09d36c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x09d36cULL ^ (static_cast<uint64_t>(0xd10383ffULL) << 13);
    acc = (acc + a1 + 0xa9086ffcULL) ^ 0x0cb650ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1619 | PC: 0x09d670 | FDE: 0x0cb6b0 | Size: 216 bytes
// Hàm FDE #1619 | Địa chỉ PC: 0x09d670 | Địa chỉ FDE: 0x0cb6b0 | Kích thước: 216 bytes
//   0x09d670: D10143FF  sub      sp, sp, #0x50
//   0x09d674: F90013F5  str      x21, [sp, #0x20]
//   0x09d678: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x09d67c: A9047BFD  stp      x29, x30, [sp, #0x40]
static inline uint64_t fde_func_1619_0x09d670(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x09d670ULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xf90013f5ULL) ^ 0x0cb6b0ULL;
    acc ^= (acc >> 17) * 0x00d8ULL;
    return acc;
}

// FDE #1620 | PC: 0x09d748 | FDE: 0x0cb590 | Size: 72 bytes
// Hàm FDE #1620 | Địa chỉ PC: 0x09d748 | Địa chỉ FDE: 0x0cb590 | Kích thước: 72 bytes
//   0x09d748: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x09d74c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x09d750: 910043FD  add      x29, sp, #0x10
//   0x09d754: F9400013  ldr      x19, [x0]
static inline uint64_t fde_func_1620_0x09d748(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x09d748ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x0cb590ULL;
    acc ^= (acc >> 17) * 0x0048ULL;
    return acc;
}

// FDE #1621 | PC: 0x09d790 | FDE: 0x0cb700 | Size: 112 bytes
// Hàm FDE #1621 | Địa chỉ PC: 0x09d790 | Địa chỉ FDE: 0x0cb700 | Kích thước: 112 bytes
//   0x09d790: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x09d794: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x09d798: 910043FD  add      x29, sp, #0x10
//   0x09d79c: 52800800  mov      w0, #0x40
static inline uint64_t fde_func_1621_0x09d790(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x09d790ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x0cb700ULL;
    acc ^= (acc >> 17) * 0x0070ULL;
    return acc;
}

// FDE #1622 | PC: 0x09d800 | FDE: 0x0cb5d0 | Size: 72 bytes
// Hàm FDE #1622 | Địa chỉ PC: 0x09d800 | Địa chỉ FDE: 0x0cb5d0 | Kích thước: 72 bytes
//   0x09d800: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x09d804: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x09d808: 910043FD  add      x29, sp, #0x10
//   0x09d80c: F9400013  ldr      x19, [x0]
static inline uint64_t fde_func_1622_0x09d800(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x09d800ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x0cb5d0ULL;
    acc ^= (acc >> 17) * 0x0048ULL;
    return acc;
}

// FDE #1623 | PC: 0x09d848 | FDE: 0x0cb780 | Size: 232 bytes
// Hàm FDE #1623 | Địa chỉ PC: 0x09d848 | Địa chỉ FDE: 0x0cb780 | Kích thước: 232 bytes
//   0x09d848: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x09d84c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x09d850: 910043FD  add      x29, sp, #0x10
//   0x09d854: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_1623_0x09d848(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x09d848ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x0cb780ULL;
    acc ^= (acc >> 17) * 0x00e8ULL;
    return acc;
}

// FDE #1624 | PC: 0x09d930 | FDE: 0x0cb728 | Size: 20 bytes
// Hàm FDE #1624 | Địa chỉ PC: 0x09d930 | Địa chỉ FDE: 0x0cb728 | Kích thước: 20 bytes
//   0x09d930: F9400001  ldr      x1, [x0]
//   0x09d934: F900001F  str      xzr, [x0]
//   0x09d938: B4000041  cbz      x1, #0x9d940
//   0x09d93c: 1400124D  b        #0xa2270
static inline uint64_t fde_func_1624_0x09d930(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x09d930ULL ^ (static_cast<uint64_t>(0xf9400001ULL) << 13);
    acc = (acc + a1 + 0xf900001fULL) ^ 0x0cb728ULL;
    acc ^= (acc >> 17) * 0x0014ULL;
    return acc;
}

// FDE #1625 | PC: 0x09d944 | FDE: 0x0cb7a8 | Size: 256 bytes
// Hàm FDE #1625 | Địa chỉ PC: 0x09d944 | Địa chỉ FDE: 0x0cb7a8 | Kích thước: 256 bytes
//   0x09d944: D10203FF  sub      sp, sp, #0x80
//   0x09d948: F90013FB  str      x27, [sp, #0x20]
//   0x09d94c: A90367FA  stp      x26, x25, [sp, #0x30]
//   0x09d950: A9045FF8  stp      x24, x23, [sp, #0x40]
static inline uint64_t fde_func_1625_0x09d944(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x09d944ULL ^ (static_cast<uint64_t>(0xd10203ffULL) << 13);
    acc = (acc + a1 + 0xf90013fbULL) ^ 0x0cb7a8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1626 | PC: 0x09dae4 | FDE: 0x0cb7e0 | Size: 256 bytes
// Hàm FDE #1626 | Địa chỉ PC: 0x09dae4 | Địa chỉ FDE: 0x0cb7e0 | Kích thước: 256 bytes
//   0x09dae4: D103C3FF  sub      sp, sp, #0xf0
//   0x09dae8: A9096FFC  stp      x28, x27, [sp, #0x90]
//   0x09daec: A90A67FA  stp      x26, x25, [sp, #0xa0]
//   0x09daf0: A90B5FF8  stp      x24, x23, [sp, #0xb0]
static inline uint64_t fde_func_1626_0x09dae4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x09dae4ULL ^ (static_cast<uint64_t>(0xd103c3ffULL) << 13);
    acc = (acc + a1 + 0xa9096ffcULL) ^ 0x0cb7e0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1627 | PC: 0x09dd1c | FDE: 0x0cb840 | Size: 112 bytes
// Hàm FDE #1627 | Địa chỉ PC: 0x09dd1c | Địa chỉ FDE: 0x0cb840 | Kích thước: 112 bytes
//   0x09dd1c: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x09dd20: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x09dd24: 910043FD  add      x29, sp, #0x10
//   0x09dd28: 52800600  mov      w0, #0x30
static inline uint64_t fde_func_1627_0x09dd1c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x09dd1cULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x0cb840ULL;
    acc ^= (acc >> 17) * 0x0070ULL;
    return acc;
}

// FDE #1628 | PC: 0x09dd8c | FDE: 0x0cb760 | Size: 72 bytes
// Hàm FDE #1628 | Địa chỉ PC: 0x09dd8c | Địa chỉ FDE: 0x0cb760 | Kích thước: 72 bytes
//   0x09dd8c: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x09dd90: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x09dd94: 910043FD  add      x29, sp, #0x10
//   0x09dd98: F9400013  ldr      x19, [x0]
static inline uint64_t fde_func_1628_0x09dd8c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x09dd8cULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x0cb760ULL;
    acc ^= (acc >> 17) * 0x0048ULL;
    return acc;
}

// FDE #1629 | PC: 0x09ddd4 | FDE: 0x0cb900 | Size: 256 bytes
// Hàm FDE #1629 | Địa chỉ PC: 0x09ddd4 | Địa chỉ FDE: 0x0cb900 | Kích thước: 256 bytes
//   0x09ddd4: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x09ddd8: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x09dddc: 910043FD  add      x29, sp, #0x10
//   0x09dde0: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_1629_0x09ddd4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x09ddd4ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x0cb900ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1630 | PC: 0x09defc | FDE: 0x0cb868 | Size: 20 bytes
// Hàm FDE #1630 | Địa chỉ PC: 0x09defc | Địa chỉ FDE: 0x0cb868 | Kích thước: 20 bytes
//   0x09defc: F9400001  ldr      x1, [x0]
//   0x09df00: F900001F  str      xzr, [x0]
//   0x09df04: B4000041  cbz      x1, #0x9df0c
//   0x09df08: 140010DA  b        #0xa2270
static inline uint64_t fde_func_1630_0x09defc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x09defcULL ^ (static_cast<uint64_t>(0xf9400001ULL) << 13);
    acc = (acc + a1 + 0xf900001fULL) ^ 0x0cb868ULL;
    acc ^= (acc >> 17) * 0x0014ULL;
    return acc;
}

// FDE #1631 | PC: 0x09df10 | FDE: 0x0cb928 | Size: 256 bytes
// Hàm FDE #1631 | Địa chỉ PC: 0x09df10 | Địa chỉ FDE: 0x0cb928 | Kích thước: 256 bytes
//   0x09df10: D102C3FF  sub      sp, sp, #0xb0
//   0x09df14: A9056FFC  stp      x28, x27, [sp, #0x50]
//   0x09df18: A90667FA  stp      x26, x25, [sp, #0x60]
//   0x09df1c: A9075FF8  stp      x24, x23, [sp, #0x70]
static inline uint64_t fde_func_1631_0x09df10(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x09df10ULL ^ (static_cast<uint64_t>(0xd102c3ffULL) << 13);
    acc = (acc + a1 + 0xa9056ffcULL) ^ 0x0cb928ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1632 | PC: 0x09e1ac | FDE: 0x0cb960 | Size: 256 bytes
// Hàm FDE #1632 | Địa chỉ PC: 0x09e1ac | Địa chỉ FDE: 0x0cb960 | Kích thước: 256 bytes
//   0x09e1ac: D103C3FF  sub      sp, sp, #0xf0
//   0x09e1b0: A9096FFC  stp      x28, x27, [sp, #0x90]
//   0x09e1b4: A90A67FA  stp      x26, x25, [sp, #0xa0]
//   0x09e1b8: A90B5FF8  stp      x24, x23, [sp, #0xb0]
static inline uint64_t fde_func_1632_0x09e1ac(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x09e1acULL ^ (static_cast<uint64_t>(0xd103c3ffULL) << 13);
    acc = (acc + a1 + 0xa9096ffcULL) ^ 0x0cb960ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1633 | PC: 0x09e578 | FDE: 0x0cb9c0 | Size: 216 bytes
// Hàm FDE #1633 | Địa chỉ PC: 0x09e578 | Địa chỉ FDE: 0x0cb9c0 | Kích thước: 216 bytes
//   0x09e578: D10143FF  sub      sp, sp, #0x50
//   0x09e57c: F90013F5  str      x21, [sp, #0x20]
//   0x09e580: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x09e584: A9047BFD  stp      x29, x30, [sp, #0x40]
static inline uint64_t fde_func_1633_0x09e578(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x09e578ULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xf90013f5ULL) ^ 0x0cb9c0ULL;
    acc ^= (acc >> 17) * 0x00d8ULL;
    return acc;
}

// FDE #1634 | PC: 0x09e650 | FDE: 0x0cb8a0 | Size: 72 bytes
// Hàm FDE #1634 | Địa chỉ PC: 0x09e650 | Địa chỉ FDE: 0x0cb8a0 | Kích thước: 72 bytes
//   0x09e650: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x09e654: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x09e658: 910043FD  add      x29, sp, #0x10
//   0x09e65c: F9400013  ldr      x19, [x0]
static inline uint64_t fde_func_1634_0x09e650(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x09e650ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x0cb8a0ULL;
    acc ^= (acc >> 17) * 0x0048ULL;
    return acc;
}

// FDE #1635 | PC: 0x09e698 | FDE: 0x0cba10 | Size: 112 bytes
// Hàm FDE #1635 | Địa chỉ PC: 0x09e698 | Địa chỉ FDE: 0x0cba10 | Kích thước: 112 bytes
//   0x09e698: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x09e69c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x09e6a0: 910043FD  add      x29, sp, #0x10
//   0x09e6a4: 52800800  mov      w0, #0x40
static inline uint64_t fde_func_1635_0x09e698(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x09e698ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x0cba10ULL;
    acc ^= (acc >> 17) * 0x0070ULL;
    return acc;
}

// FDE #1636 | PC: 0x09e708 | FDE: 0x0cb8e0 | Size: 72 bytes
// Hàm FDE #1636 | Địa chỉ PC: 0x09e708 | Địa chỉ FDE: 0x0cb8e0 | Kích thước: 72 bytes
//   0x09e708: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x09e70c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x09e710: 910043FD  add      x29, sp, #0x10
//   0x09e714: F9400013  ldr      x19, [x0]
static inline uint64_t fde_func_1636_0x09e708(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x09e708ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x0cb8e0ULL;
    acc ^= (acc >> 17) * 0x0048ULL;
    return acc;
}

// FDE #1637 | PC: 0x09e750 | FDE: 0x0cbad0 | Size: 256 bytes
// Hàm FDE #1637 | Địa chỉ PC: 0x09e750 | Địa chỉ FDE: 0x0cbad0 | Kích thước: 256 bytes
//   0x09e750: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x09e754: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x09e758: 910043FD  add      x29, sp, #0x10
//   0x09e75c: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_1637_0x09e750(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x09e750ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x0cbad0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1638 | PC: 0x09e878 | FDE: 0x0cba38 | Size: 20 bytes
// Hàm FDE #1638 | Địa chỉ PC: 0x09e878 | Địa chỉ FDE: 0x0cba38 | Kích thước: 20 bytes
//   0x09e878: F9400001  ldr      x1, [x0]
//   0x09e87c: F900001F  str      xzr, [x0]
//   0x09e880: B4000041  cbz      x1, #0x9e888
//   0x09e884: 14000E7B  b        #0xa2270
static inline uint64_t fde_func_1638_0x09e878(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x09e878ULL ^ (static_cast<uint64_t>(0xf9400001ULL) << 13);
    acc = (acc + a1 + 0xf900001fULL) ^ 0x0cba38ULL;
    acc ^= (acc >> 17) * 0x0014ULL;
    return acc;
}

// FDE #1639 | PC: 0x09e88c | FDE: 0x0cbaf8 | Size: 256 bytes
// Hàm FDE #1639 | Địa chỉ PC: 0x09e88c | Địa chỉ FDE: 0x0cbaf8 | Kích thước: 256 bytes
//   0x09e88c: D10283FF  sub      sp, sp, #0xa0
//   0x09e890: A9046FFC  stp      x28, x27, [sp, #0x40]
//   0x09e894: A90567FA  stp      x26, x25, [sp, #0x50]
//   0x09e898: A9065FF8  stp      x24, x23, [sp, #0x60]
static inline uint64_t fde_func_1639_0x09e88c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x09e88cULL ^ (static_cast<uint64_t>(0xd10283ffULL) << 13);
    acc = (acc + a1 + 0xa9046ffcULL) ^ 0x0cbaf8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1640 | PC: 0x09eabc | FDE: 0x0cbb30 | Size: 256 bytes
// Hàm FDE #1640 | Địa chỉ PC: 0x09eabc | Địa chỉ FDE: 0x0cbb30 | Kích thước: 256 bytes
//   0x09eabc: D103C3FF  sub      sp, sp, #0xf0
//   0x09eac0: F9004BFB  str      x27, [sp, #0x90]
//   0x09eac4: A90A67FA  stp      x26, x25, [sp, #0xa0]
//   0x09eac8: A90B5FF8  stp      x24, x23, [sp, #0xb0]
static inline uint64_t fde_func_1640_0x09eabc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x09eabcULL ^ (static_cast<uint64_t>(0xd103c3ffULL) << 13);
    acc = (acc + a1 + 0xf9004bfbULL) ^ 0x0cbb30ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1641 | PC: 0x09ed78 | FDE: 0x0cbb90 | Size: 216 bytes
// Hàm FDE #1641 | Địa chỉ PC: 0x09ed78 | Địa chỉ FDE: 0x0cbb90 | Kích thước: 216 bytes
//   0x09ed78: D10143FF  sub      sp, sp, #0x50
//   0x09ed7c: F90013F5  str      x21, [sp, #0x20]
//   0x09ed80: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x09ed84: A9047BFD  stp      x29, x30, [sp, #0x40]
static inline uint64_t fde_func_1641_0x09ed78(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x09ed78ULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xf90013f5ULL) ^ 0x0cbb90ULL;
    acc ^= (acc >> 17) * 0x00d8ULL;
    return acc;
}

// FDE #1642 | PC: 0x09ee50 | FDE: 0x0cba70 | Size: 72 bytes
// Hàm FDE #1642 | Địa chỉ PC: 0x09ee50 | Địa chỉ FDE: 0x0cba70 | Kích thước: 72 bytes
//   0x09ee50: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x09ee54: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x09ee58: 910043FD  add      x29, sp, #0x10
//   0x09ee5c: F9400013  ldr      x19, [x0]
static inline uint64_t fde_func_1642_0x09ee50(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x09ee50ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x0cba70ULL;
    acc ^= (acc >> 17) * 0x0048ULL;
    return acc;
}

// FDE #1643 | PC: 0x09ee98 | FDE: 0x0cbbe0 | Size: 112 bytes
// Hàm FDE #1643 | Địa chỉ PC: 0x09ee98 | Địa chỉ FDE: 0x0cbbe0 | Kích thước: 112 bytes
//   0x09ee98: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x09ee9c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x09eea0: 910043FD  add      x29, sp, #0x10
//   0x09eea4: 52800800  mov      w0, #0x40
static inline uint64_t fde_func_1643_0x09ee98(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x09ee98ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x0cbbe0ULL;
    acc ^= (acc >> 17) * 0x0070ULL;
    return acc;
}

// FDE #1644 | PC: 0x09ef08 | FDE: 0x0cbab0 | Size: 72 bytes
// Hàm FDE #1644 | Địa chỉ PC: 0x09ef08 | Địa chỉ FDE: 0x0cbab0 | Kích thước: 72 bytes
//   0x09ef08: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x09ef0c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x09ef10: 910043FD  add      x29, sp, #0x10
//   0x09ef14: F9400013  ldr      x19, [x0]
static inline uint64_t fde_func_1644_0x09ef08(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x09ef08ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x0cbab0ULL;
    acc ^= (acc >> 17) * 0x0048ULL;
    return acc;
}

// FDE #1645 | PC: 0x09ef50 | FDE: 0x0cbc88 | Size: 256 bytes
// Hàm FDE #1645 | Địa chỉ PC: 0x09ef50 | Địa chỉ FDE: 0x0cbc88 | Kích thước: 256 bytes
//   0x09ef50: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x09ef54: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x09ef58: 910043FD  add      x29, sp, #0x10
//   0x09ef5c: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_1645_0x09ef50(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x09ef50ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x0cbc88ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1646 | PC: 0x09f058 | FDE: 0x0cbc08 | Size: 20 bytes
// Hàm FDE #1646 | Địa chỉ PC: 0x09f058 | Địa chỉ FDE: 0x0cbc08 | Kích thước: 20 bytes
//   0x09f058: F9400001  ldr      x1, [x0]
//   0x09f05c: F900001F  str      xzr, [x0]
//   0x09f060: B4000041  cbz      x1, #0x9f068
//   0x09f064: 14000C83  b        #0xa2270
static inline uint64_t fde_func_1646_0x09f058(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x09f058ULL ^ (static_cast<uint64_t>(0xf9400001ULL) << 13);
    acc = (acc + a1 + 0xf900001fULL) ^ 0x0cbc08ULL;
    acc ^= (acc >> 17) * 0x0014ULL;
    return acc;
}

// FDE #1647 | PC: 0x09f06c | FDE: 0x0cbcb0 | Size: 256 bytes
// Hàm FDE #1647 | Địa chỉ PC: 0x09f06c | Địa chỉ FDE: 0x0cbcb0 | Kích thước: 256 bytes
//   0x09f06c: D10243FF  sub      sp, sp, #0x90
//   0x09f070: F9001BFB  str      x27, [sp, #0x30]
//   0x09f074: A90467FA  stp      x26, x25, [sp, #0x40]
//   0x09f078: A9055FF8  stp      x24, x23, [sp, #0x50]
static inline uint64_t fde_func_1647_0x09f06c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x09f06cULL ^ (static_cast<uint64_t>(0xd10243ffULL) << 13);
    acc = (acc + a1 + 0xf9001bfbULL) ^ 0x0cbcb0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1648 | PC: 0x09f250 | FDE: 0x0cbce8 | Size: 256 bytes
// Hàm FDE #1648 | Địa chỉ PC: 0x09f250 | Địa chỉ FDE: 0x0cbce8 | Kích thước: 256 bytes
//   0x09f250: D10143FF  sub      sp, sp, #0x50
//   0x09f254: A9015FF8  stp      x24, x23, [sp, #0x10]
//   0x09f258: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x09f25c: A9034FF4  stp      x20, x19, [sp, #0x30]
static inline uint64_t fde_func_1648_0x09f250(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x09f250ULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xa9015ff8ULL) ^ 0x0cbce8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1649 | PC: 0x09f384 | FDE: 0x0cbd18 | Size: 256 bytes
// Hàm FDE #1649 | Địa chỉ PC: 0x09f384 | Địa chỉ FDE: 0x0cbd18 | Kích thước: 256 bytes
//   0x09f384: D10383FF  sub      sp, sp, #0xe0
//   0x09f388: F90043FB  str      x27, [sp, #0x80]
//   0x09f38c: A90967FA  stp      x26, x25, [sp, #0x90]
//   0x09f390: A90A5FF8  stp      x24, x23, [sp, #0xa0]
static inline uint64_t fde_func_1649_0x09f384(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x09f384ULL ^ (static_cast<uint64_t>(0xd10383ffULL) << 13);
    acc = (acc + a1 + 0xf90043fbULL) ^ 0x0cbd18ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1650 | PC: 0x09f61c | FDE: 0x0cbd50 | Size: 256 bytes
// Hàm FDE #1650 | Địa chỉ PC: 0x09f61c | Địa chỉ FDE: 0x0cbd50 | Kích thước: 256 bytes
//   0x09f61c: D103C3FF  sub      sp, sp, #0xf0
//   0x09f620: A9096FFC  stp      x28, x27, [sp, #0x90]
//   0x09f624: A90A67FA  stp      x26, x25, [sp, #0xa0]
//   0x09f628: A90B5FF8  stp      x24, x23, [sp, #0xb0]
static inline uint64_t fde_func_1650_0x09f61c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x09f61cULL ^ (static_cast<uint64_t>(0xd103c3ffULL) << 13);
    acc = (acc + a1 + 0xa9096ffcULL) ^ 0x0cbd50ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1651 | PC: 0x09f914 | FDE: 0x0cbdb0 | Size: 112 bytes
// Hàm FDE #1651 | Địa chỉ PC: 0x09f914 | Địa chỉ FDE: 0x0cbdb0 | Kích thước: 112 bytes
//   0x09f914: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x09f918: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x09f91c: 910043FD  add      x29, sp, #0x10
//   0x09f920: 52800700  mov      w0, #0x38
static inline uint64_t fde_func_1651_0x09f914(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x09f914ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x0cbdb0ULL;
    acc ^= (acc >> 17) * 0x0070ULL;
    return acc;
}

// FDE #1652 | PC: 0x09f984 | FDE: 0x0cbc40 | Size: 72 bytes
// Hàm FDE #1652 | Địa chỉ PC: 0x09f984 | Địa chỉ FDE: 0x0cbc40 | Kích thước: 72 bytes
//   0x09f984: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x09f988: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x09f98c: 910043FD  add      x29, sp, #0x10
//   0x09f990: F9400013  ldr      x19, [x0]
static inline uint64_t fde_func_1652_0x09f984(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x09f984ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x0cbc40ULL;
    acc ^= (acc >> 17) * 0x0048ULL;
    return acc;
}

// FDE #1653 | PC: 0x09f9cc | FDE: 0x0cbc60 | Size: 256 bytes
// Hàm FDE #1653 | Địa chỉ PC: 0x09f9cc | Địa chỉ FDE: 0x0cbc60 | Kích thước: 256 bytes
//   0x09f9cc: D101C3FF  sub      sp, sp, #0x70
//   0x09f9d0: A9035FF8  stp      x24, x23, [sp, #0x30]
//   0x09f9d4: A90457F6  stp      x22, x21, [sp, #0x40]
//   0x09f9d8: A9054FF4  stp      x20, x19, [sp, #0x50]
static inline uint64_t fde_func_1653_0x09f9cc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x09f9ccULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xa9035ff8ULL) ^ 0x0cbc60ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1654 | PC: 0x09fc60 | FDE: 0x0cbe48 | Size: 256 bytes
// Hàm FDE #1654 | Địa chỉ PC: 0x09fc60 | Địa chỉ FDE: 0x0cbe48 | Kích thước: 256 bytes
//   0x09fc60: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x09fc64: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x09fc68: 910043FD  add      x29, sp, #0x10
//   0x09fc6c: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_1654_0x09fc60(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x09fc60ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x0cbe48ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1655 | PC: 0x09fe28 | FDE: 0x0cbdd8 | Size: 20 bytes
// Hàm FDE #1655 | Địa chỉ PC: 0x09fe28 | Địa chỉ FDE: 0x0cbdd8 | Kích thước: 20 bytes
//   0x09fe28: F9400001  ldr      x1, [x0]
//   0x09fe2c: F900001F  str      xzr, [x0]
//   0x09fe30: B4000041  cbz      x1, #0x9fe38
//   0x09fe34: 1400090F  b        #0xa2270
static inline uint64_t fde_func_1655_0x09fe28(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x09fe28ULL ^ (static_cast<uint64_t>(0xf9400001ULL) << 13);
    acc = (acc + a1 + 0xf900001fULL) ^ 0x0cbdd8ULL;
    acc ^= (acc >> 17) * 0x0014ULL;
    return acc;
}

// FDE #1656 | PC: 0x09fe3c | FDE: 0x0cbe70 | Size: 256 bytes
// Hàm FDE #1656 | Địa chỉ PC: 0x09fe3c | Địa chỉ FDE: 0x0cbe70 | Kích thước: 256 bytes
//   0x09fe3c: D10483FF  sub      sp, sp, #0x120
//   0x09fe40: A90C6FFC  stp      x28, x27, [sp, #0xc0]
//   0x09fe44: A90D67FA  stp      x26, x25, [sp, #0xd0]
//   0x09fe48: A90E5FF8  stp      x24, x23, [sp, #0xe0]
static inline uint64_t fde_func_1656_0x09fe3c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x09fe3cULL ^ (static_cast<uint64_t>(0xd10483ffULL) << 13);
    acc = (acc + a1 + 0xa90c6ffcULL) ^ 0x0cbe70ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1657 | PC: 0x0a0264 | FDE: 0x0cbea8 | Size: 256 bytes
// Hàm FDE #1657 | Địa chỉ PC: 0x0a0264 | Địa chỉ FDE: 0x0cbea8 | Kích thước: 256 bytes
//   0x0a0264: A9BB67FC  stp      x28, x25, [sp, #-0x50]!
//   0x0a0268: A9015FF8  stp      x24, x23, [sp, #0x10]
//   0x0a026c: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x0a0270: A9034FF4  stp      x20, x19, [sp, #0x30]
static inline uint64_t fde_func_1657_0x0a0264(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a0264ULL ^ (static_cast<uint64_t>(0xa9bb67fcULL) << 13);
    acc = (acc + a1 + 0xa9015ff8ULL) ^ 0x0cbea8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1658 | PC: 0x0a0a0c | FDE: 0x0cbdf0 | Size: 256 bytes [_ZN4nuro11UserMessageC2ENSt6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEES7_NS1_8optionalINS_11SectionInfoEEENS8_INS_14MessageContentEEENS8_INS_7ContextEEENS8_INS_10ToolResultEEENS_13MessageStatusENS8_IS7_EESI_lNS_13MessageSourceE]
// Hàm FDE #1658 | Địa chỉ PC: 0x0a0a0c | Địa chỉ FDE: 0x0cbdf0 | Kích thước: 256 bytes
//   0x0a0a0c: F9400828  ldr      x8, [x1, #0x10]
//   0x0a0a10: 3DC00020  ldr      q0, [x1]
//   0x0a0a14: F9000808  str      x8, [x0, #0x10]
//   0x0a0a18: 3D800000  str      q0, [x0]
static inline uint64_t fde_func_1658_0x0a0a0c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a0a0cULL ^ (static_cast<uint64_t>(0xf9400828ULL) << 13);
    acc = (acc + a1 + 0x3dc00020ULL) ^ 0x0cbdf0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1659 | PC: 0x0a0cf4 | FDE: 0x0cbf08 | Size: 112 bytes
// Hàm FDE #1659 | Địa chỉ PC: 0x0a0cf4 | Địa chỉ FDE: 0x0cbf08 | Kích thước: 112 bytes
//   0x0a0cf4: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0a0cf8: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0a0cfc: 910043FD  add      x29, sp, #0x10
//   0x0a0d00: 52800D00  mov      w0, #0x68
static inline uint64_t fde_func_1659_0x0a0cf4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a0cf4ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x0cbf08ULL;
    acc ^= (acc >> 17) * 0x0070ULL;
    return acc;
}

// FDE #1660 | PC: 0x0a0d64 | FDE: 0x0cbe28 | Size: 72 bytes
// Hàm FDE #1660 | Địa chỉ PC: 0x0a0d64 | Địa chỉ FDE: 0x0cbe28 | Kích thước: 72 bytes
//   0x0a0d64: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x0a0d68: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0a0d6c: 910043FD  add      x29, sp, #0x10
//   0x0a0d70: F9400013  ldr      x19, [x0]
static inline uint64_t fde_func_1660_0x0a0d64(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a0d64ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x0cbe28ULL;
    acc ^= (acc >> 17) * 0x0048ULL;
    return acc;
}

// FDE #1661 | PC: 0x0a0dac | FDE: 0x0cc3f8 | Size: 256 bytes
// Hàm FDE #1661 | Địa chỉ PC: 0x0a0dac | Địa chỉ FDE: 0x0cc3f8 | Kích thước: 256 bytes
//   0x0a0dac: D10243FF  sub      sp, sp, #0x90
//   0x0a0db0: F9001BFB  str      x27, [sp, #0x30]
//   0x0a0db4: A90467FA  stp      x26, x25, [sp, #0x40]
//   0x0a0db8: A9055FF8  stp      x24, x23, [sp, #0x50]
static inline uint64_t fde_func_1661_0x0a0dac(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a0dacULL ^ (static_cast<uint64_t>(0xd10243ffULL) << 13);
    acc = (acc + a1 + 0xf9001bfbULL) ^ 0x0cc3f8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1662 | PC: 0x0a0fd0 | FDE: 0x0cc430 | Size: 240 bytes
// Hàm FDE #1662 | Địa chỉ PC: 0x0a0fd0 | Địa chỉ FDE: 0x0cc430 | Kích thước: 240 bytes
//   0x0a0fd0: D10183FF  sub      sp, sp, #0x60
//   0x0a0fd4: F90013F7  str      x23, [sp, #0x20]
//   0x0a0fd8: A90357F6  stp      x22, x21, [sp, #0x30]
//   0x0a0fdc: A9044FF4  stp      x20, x19, [sp, #0x40]
static inline uint64_t fde_func_1662_0x0a0fd0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a0fd0ULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xf90013f7ULL) ^ 0x0cc430ULL;
    acc ^= (acc >> 17) * 0x00f0ULL;
    return acc;
}

// FDE #1663 | PC: 0x0a10c0 | FDE: 0x0cbf30 | Size: 40 bytes
// Hàm FDE #1663 | Địa chỉ PC: 0x0a10c0 | Địa chỉ FDE: 0x0cbf30 | Kích thước: 40 bytes
//   0x0a10c0: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x0a10c4: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0a10c8: 910043FD  add      x29, sp, #0x10
//   0x0a10cc: A9400428  ldp      x8, x1, [x1]
static inline uint64_t fde_func_1663_0x0a10c0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a10c0ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x0cbf30ULL;
    acc ^= (acc >> 17) * 0x0028ULL;
    return acc;
}

// FDE #1664 | PC: 0x0a10e8 | FDE: 0x0cc460 | Size: 256 bytes
// Hàm FDE #1664 | Địa chỉ PC: 0x0a10e8 | Địa chỉ FDE: 0x0cc460 | Kích thước: 256 bytes
//   0x0a10e8: D10103FF  sub      sp, sp, #0x40
//   0x0a10ec: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x0a10f0: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x0a10f4: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_1664_0x0a10e8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a10e8ULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x0cc460ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1665 | PC: 0x0a1248 | FDE: 0x0cbf50 | Size: 44 bytes
// Hàm FDE #1665 | Địa chỉ PC: 0x0a1248 | Địa chỉ FDE: 0x0cbf50 | Kích thước: 44 bytes
//   0x0a1248: F9400028  ldr      x8, [x1]
//   0x0a124c: F9400049  ldr      x9, [x2]
//   0x0a1250: F9400508  ldr      x8, [x8, #8]
//   0x0a1254: F9400529  ldr      x9, [x9, #8]
static inline uint64_t fde_func_1665_0x0a1248(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a1248ULL ^ (static_cast<uint64_t>(0xf9400028ULL) << 13);
    acc = (acc + a1 + 0xf9400049ULL) ^ 0x0cbf50ULL;
    acc ^= (acc >> 17) * 0x002cULL;
    return acc;
}

// FDE #1666 | PC: 0x0a1274 | FDE: 0x0cc490 | Size: 256 bytes
// Hàm FDE #1666 | Địa chỉ PC: 0x0a1274 | Địa chỉ FDE: 0x0cc490 | Kích thước: 256 bytes
//   0x0a1274: D10143FF  sub      sp, sp, #0x50
//   0x0a1278: F9000BF7  str      x23, [sp, #0x10]
//   0x0a127c: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x0a1280: A9034FF4  stp      x20, x19, [sp, #0x30]
static inline uint64_t fde_func_1666_0x0a1274(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a1274ULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xf9000bf7ULL) ^ 0x0cc490ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1667 | PC: 0x0a13e4 | FDE: 0x0cbf68 | Size: 72 bytes
// Hàm FDE #1667 | Địa chỉ PC: 0x0a13e4 | Địa chỉ FDE: 0x0cbf68 | Kích thước: 72 bytes
//   0x0a13e4: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x0a13e8: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0a13ec: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0a13f0: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1667_0x0a13e4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a13e4ULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x0cbf68ULL;
    acc ^= (acc >> 17) * 0x0048ULL;
    return acc;
}

// FDE #1668 | PC: 0x0a142c | FDE: 0x0cc4c0 | Size: 188 bytes
// Hàm FDE #1668 | Địa chỉ PC: 0x0a142c | Địa chỉ FDE: 0x0cc4c0 | Kích thước: 188 bytes
//   0x0a142c: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x0a1430: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0a1434: 910043FD  add      x29, sp, #0x10
//   0x0a1438: F0000248  adrp     x8, #0xec000
static inline uint64_t fde_func_1668_0x0a142c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a142cULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x0cc4c0ULL;
    acc ^= (acc >> 17) * 0x00bcULL;
    return acc;
}

// FDE #1669 | PC: 0x0a14e8 | FDE: 0x0cbf90 | Size: 80 bytes
// Hàm FDE #1669 | Địa chỉ PC: 0x0a14e8 | Địa chỉ FDE: 0x0cbf90 | Kích thước: 80 bytes
//   0x0a14e8: D100C3FF  sub      sp, sp, #0x30
//   0x0a14ec: F9000BF3  str      x19, [sp, #0x10]
//   0x0a14f0: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0a14f4: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1669_0x0a14e8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a14e8ULL ^ (static_cast<uint64_t>(0xd100c3ffULL) << 13);
    acc = (acc + a1 + 0xf9000bf3ULL) ^ 0x0cbf90ULL;
    acc ^= (acc >> 17) * 0x0050ULL;
    return acc;
}

// FDE #1670 | PC: 0x0a1538 | FDE: 0x0cc4e8 | Size: 168 bytes
// Hàm FDE #1670 | Địa chỉ PC: 0x0a1538 | Địa chỉ FDE: 0x0cc4e8 | Kích thước: 168 bytes
//   0x0a1538: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x0a153c: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0a1540: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0a1544: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1670_0x0a1538(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a1538ULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x0cc4e8ULL;
    acc ^= (acc >> 17) * 0x00a8ULL;
    return acc;
}

// FDE #1671 | PC: 0x0a15e0 | FDE: 0x0cc518 | Size: 256 bytes
// Hàm FDE #1671 | Địa chỉ PC: 0x0a15e0 | Địa chỉ FDE: 0x0cc518 | Kích thước: 256 bytes
//   0x0a15e0: D10203FF  sub      sp, sp, #0x80
//   0x0a15e4: A90367FA  stp      x26, x25, [sp, #0x30]
//   0x0a15e8: A9045FF8  stp      x24, x23, [sp, #0x40]
//   0x0a15ec: A90557F6  stp      x22, x21, [sp, #0x50]
static inline uint64_t fde_func_1671_0x0a15e0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a15e0ULL ^ (static_cast<uint64_t>(0xd10203ffULL) << 13);
    acc = (acc + a1 + 0xa90367faULL) ^ 0x0cc518ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1672 | PC: 0x0a16f4 | FDE: 0x0cc550 | Size: 220 bytes
// Hàm FDE #1672 | Địa chỉ PC: 0x0a16f4 | Địa chỉ FDE: 0x0cc550 | Kích thước: 220 bytes
//   0x0a16f4: D10183FF  sub      sp, sp, #0x60
//   0x0a16f8: F90013F7  str      x23, [sp, #0x20]
//   0x0a16fc: A90357F6  stp      x22, x21, [sp, #0x30]
//   0x0a1700: A9044FF4  stp      x20, x19, [sp, #0x40]
static inline uint64_t fde_func_1672_0x0a16f4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a16f4ULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xf90013f7ULL) ^ 0x0cc550ULL;
    acc ^= (acc >> 17) * 0x00dcULL;
    return acc;
}

// FDE #1673 | PC: 0x0a17d0 | FDE: 0x0cbfb0 | Size: 72 bytes
// Hàm FDE #1673 | Địa chỉ PC: 0x0a17d0 | Địa chỉ FDE: 0x0cbfb0 | Kích thước: 72 bytes
//   0x0a17d0: A9402428  ldp      x8, x9, [x1]
//   0x0a17d4: D285AD2B  mov      x11, #0x2d69
//   0x0a17d8: F2BD670B  movk     x11, #0xeb38, lsl #16
//   0x0a17dc: F2DD410B  movk     x11, #0xea08, lsl #32
static inline uint64_t fde_func_1673_0x0a17d0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a17d0ULL ^ (static_cast<uint64_t>(0xa9402428ULL) << 13);
    acc = (acc + a1 + 0xd285ad2bULL) ^ 0x0cbfb0ULL;
    acc ^= (acc >> 17) * 0x0048ULL;
    return acc;
}

// FDE #1674 | PC: 0x0a1818 | FDE: 0x0cbfc8 | Size: 52 bytes
// Hàm FDE #1674 | Địa chỉ PC: 0x0a1818 | Địa chỉ FDE: 0x0cbfc8 | Kích thước: 52 bytes
//   0x0a1818: F9400028  ldr      x8, [x1]
//   0x0a181c: F9400049  ldr      x9, [x2]
//   0x0a1820: F9400508  ldr      x8, [x8, #8]
//   0x0a1824: F9400529  ldr      x9, [x9, #8]
static inline uint64_t fde_func_1674_0x0a1818(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a1818ULL ^ (static_cast<uint64_t>(0xf9400028ULL) << 13);
    acc = (acc + a1 + 0xf9400049ULL) ^ 0x0cbfc8ULL;
    acc ^= (acc >> 17) * 0x0034ULL;
    return acc;
}

// FDE #1675 | PC: 0x0a184c | FDE: 0x0cbfe0 | Size: 64 bytes
// Hàm FDE #1675 | Địa chỉ PC: 0x0a184c | Địa chỉ FDE: 0x0cbfe0 | Kích thước: 64 bytes
//   0x0a184c: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x0a1850: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0a1854: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0a1858: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1675_0x0a184c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a184cULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x0cbfe0ULL;
    acc ^= (acc >> 17) * 0x0040ULL;
    return acc;
}

// FDE #1676 | PC: 0x0a188c | FDE: 0x0cc580 | Size: 252 bytes
// Hàm FDE #1676 | Địa chỉ PC: 0x0a188c | Địa chỉ FDE: 0x0cc580 | Kích thước: 252 bytes
//   0x0a188c: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x0a1890: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0a1894: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0a1898: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1676_0x0a188c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a188cULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x0cc580ULL;
    acc ^= (acc >> 17) * 0x00fcULL;
    return acc;
}

// FDE #1677 | PC: 0x0a1988 | FDE: 0x0cc000 | Size: 80 bytes
// Hàm FDE #1677 | Địa chỉ PC: 0x0a1988 | Địa chỉ FDE: 0x0cc000 | Kích thước: 80 bytes
//   0x0a1988: D100C3FF  sub      sp, sp, #0x30
//   0x0a198c: F9000BF3  str      x19, [sp, #0x10]
//   0x0a1990: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0a1994: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1677_0x0a1988(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a1988ULL ^ (static_cast<uint64_t>(0xd100c3ffULL) << 13);
    acc = (acc + a1 + 0xf9000bf3ULL) ^ 0x0cc000ULL;
    acc ^= (acc >> 17) * 0x0050ULL;
    return acc;
}

// FDE #1678 | PC: 0x0a19d8 | FDE: 0x0cc020 | Size: 108 bytes
// Hàm FDE #1678 | Địa chỉ PC: 0x0a19d8 | Địa chỉ FDE: 0x0cc020 | Kích thước: 108 bytes
//   0x0a19d8: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x0a19dc: 910003FD  mov      x29, sp
//   0x0a19e0: F0000248  adrp     x8, #0xec000
//   0x0a19e4: 91378108  add      x8, x8, #0xde0
static inline uint64_t fde_func_1678_0x0a19d8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a19d8ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x0cc020ULL;
    acc ^= (acc >> 17) * 0x006cULL;
    return acc;
}

// FDE #1679 | PC: 0x0a1a44 | FDE: 0x0cc040 | Size: 140 bytes
// Hàm FDE #1679 | Địa chỉ PC: 0x0a1a44 | Địa chỉ FDE: 0x0cc040 | Kích thước: 140 bytes
//   0x0a1a44: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x0a1a48: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0a1a4c: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0a1a50: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1679_0x0a1a44(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a1a44ULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x0cc040ULL;
    acc ^= (acc >> 17) * 0x008cULL;
    return acc;
}

// FDE #1680 | PC: 0x0a1ad0 | FDE: 0x0cc060 | Size: 100 bytes
// Hàm FDE #1680 | Địa chỉ PC: 0x0a1ad0 | Địa chỉ FDE: 0x0cc060 | Kích thước: 100 bytes
//   0x0a1ad0: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x0a1ad4: 910003FD  mov      x29, sp
//   0x0a1ad8: F0000248  adrp     x8, #0xec000
//   0x0a1adc: 91384108  add      x8, x8, #0xe10
static inline uint64_t fde_func_1680_0x0a1ad0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a1ad0ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x0cc060ULL;
    acc ^= (acc >> 17) * 0x0064ULL;
    return acc;
}

// FDE #1681 | PC: 0x0a1b34 | FDE: 0x0cc5a8 | Size: 248 bytes
// Hàm FDE #1681 | Địa chỉ PC: 0x0a1b34 | Địa chỉ FDE: 0x0cc5a8 | Kích thước: 248 bytes
//   0x0a1b34: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x0a1b38: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0a1b3c: 910043FD  add      x29, sp, #0x10
//   0x0a1b40: F0000249  adrp     x9, #0xec000
static inline uint64_t fde_func_1681_0x0a1b34(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a1b34ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x0cc5a8ULL;
    acc ^= (acc >> 17) * 0x00f8ULL;
    return acc;
}

// FDE #1682 | PC: 0x0a1c2c | FDE: 0x0cc5d0 | Size: 256 bytes
// Hàm FDE #1682 | Địa chỉ PC: 0x0a1c2c | Địa chỉ FDE: 0x0cc5d0 | Kích thước: 256 bytes
//   0x0a1c2c: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x0a1c30: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0a1c34: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0a1c38: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1682_0x0a1c2c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a1c2cULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x0cc5d0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1683 | PC: 0x0a1d90 | FDE: 0x0cc600 | Size: 256 bytes
// Hàm FDE #1683 | Địa chỉ PC: 0x0a1d90 | Địa chỉ FDE: 0x0cc600 | Kích thước: 256 bytes
//   0x0a1d90: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0a1d94: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0a1d98: 910043FD  add      x29, sp, #0x10
//   0x0a1d9c: F0000248  adrp     x8, #0xec000
static inline uint64_t fde_func_1683_0x0a1d90(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a1d90ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x0cc600ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1684 | PC: 0x0a1eec | FDE: 0x0cc628 | Size: 256 bytes
// Hàm FDE #1684 | Địa chỉ PC: 0x0a1eec | Địa chỉ FDE: 0x0cc628 | Kích thước: 256 bytes
//   0x0a1eec: D101C3FF  sub      sp, sp, #0x70
//   0x0a1ef0: A9035FF8  stp      x24, x23, [sp, #0x30]
//   0x0a1ef4: A90457F6  stp      x22, x21, [sp, #0x40]
//   0x0a1ef8: A9054FF4  stp      x20, x19, [sp, #0x50]
static inline uint64_t fde_func_1684_0x0a1eec(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a1eecULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xa9035ff8ULL) ^ 0x0cc628ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1685 | PC: 0x0a2130 | FDE: 0x0cc658 | Size: 24 bytes
// Hàm FDE #1685 | Địa chỉ PC: 0x0a2130 | Địa chỉ FDE: 0x0cc658 | Kích thước: 24 bytes
//   0x0a2130: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x0a2134: 910003FD  mov      x29, sp
//   0x0a2138: 94000D91  bl       #0xa577c
//   0x0a213c: A8C17BFD  ldp      x29, x30, [sp], #0x10
static inline uint64_t fde_func_1685_0x0a2130(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a2130ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x0cc658ULL;
    acc ^= (acc >> 17) * 0x0018ULL;
    return acc;
}

// FDE #1686 | PC: 0x0a2148 | FDE: 0x0cc080 | Size: 244 bytes
// Hàm FDE #1686 | Địa chỉ PC: 0x0a2148 | Địa chỉ FDE: 0x0cc080 | Kích thước: 244 bytes
//   0x0a2148: D10103FF  sub      sp, sp, #0x40
//   0x0a214c: F9000BF5  str      x21, [sp, #0x10]
//   0x0a2150: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x0a2154: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_1686_0x0a2148(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a2148ULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xf9000bf5ULL) ^ 0x0cc080ULL;
    acc ^= (acc >> 17) * 0x00f4ULL;
    return acc;
}

// FDE #1687 | PC: 0x0a223c | FDE: 0x0cc0a0 | Size: 12 bytes
// Hàm FDE #1687 | Địa chỉ PC: 0x0a223c | Địa chỉ FDE: 0x0cc0a0 | Kích thước: 12 bytes
//   0x0a223c: D0000248  adrp     x8, #0xec000
//   0x0a2240: F9070D1F  str      xzr, [x8, #0xe18]
//   0x0a2244: D65F03C0  ret      
static inline uint64_t fde_func_1687_0x0a223c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a223cULL ^ (static_cast<uint64_t>(0xd0000248ULL) << 13);
    acc = (acc + a1 + 0xf9070d1fULL) ^ 0x0cc0a0ULL;
    acc ^= (acc >> 17) * 0x000cULL;
    return acc;
}

// FDE #1688 | PC: 0x0a2248 | FDE: 0x0cc680 | Size: 40 bytes
// Hàm FDE #1688 | Địa chỉ PC: 0x0a2248 | Địa chỉ FDE: 0x0cc680 | Kích thước: 40 bytes
//   0x0a2248: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x0a224c: 910003FD  mov      x29, sp
//   0x0a2250: D0000248  adrp     x8, #0xec000
//   0x0a2254: F9470D00  ldr      x0, [x8, #0xe18]
static inline uint64_t fde_func_1688_0x0a2248(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a2248ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x0cc680ULL;
    acc ^= (acc >> 17) * 0x0028ULL;
    return acc;
}

// FDE #1689 | PC: 0x0a2270 | FDE: 0x0cc6a8 | Size: 156 bytes
// Hàm FDE #1689 | Địa chỉ PC: 0x0a2270 | Địa chỉ FDE: 0x0cc6a8 | Kích thước: 156 bytes
//   0x0a2270: D100C3FF  sub      sp, sp, #0x30
//   0x0a2274: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0a2278: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0a227c: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1689_0x0a2270(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a2270ULL ^ (static_cast<uint64_t>(0xd100c3ffULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x0cc6a8ULL;
    acc ^= (acc >> 17) * 0x009cULL;
    return acc;
}

// FDE #1690 | PC: 0x0a230c | FDE: 0x0cc6d0 | Size: 256 bytes
// Hàm FDE #1690 | Địa chỉ PC: 0x0a230c | Địa chỉ FDE: 0x0cc6d0 | Kích thước: 256 bytes
//   0x0a230c: D10103FF  sub      sp, sp, #0x40
//   0x0a2310: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x0a2314: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x0a2318: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_1690_0x0a230c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a230cULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x0cc6d0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1691 | PC: 0x0a241c | FDE: 0x0cc700 | Size: 44 bytes
// Hàm FDE #1691 | Địa chỉ PC: 0x0a241c | Địa chỉ FDE: 0x0cc700 | Kích thước: 44 bytes
//   0x0a241c: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x0a2420: 910003FD  mov      x29, sp
//   0x0a2424: F9400029  ldr      x9, [x1]
//   0x0a2428: AA0103E8  mov      x8, x1
static inline uint64_t fde_func_1691_0x0a241c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a241cULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x0cc700ULL;
    acc ^= (acc >> 17) * 0x002cULL;
    return acc;
}

// FDE #1692 | PC: 0x0a2448 | FDE: 0x0cc728 | Size: 104 bytes
// Hàm FDE #1692 | Địa chỉ PC: 0x0a2448 | Địa chỉ FDE: 0x0cc728 | Kích thước: 104 bytes
//   0x0a2448: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x0a244c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0a2450: 910043FD  add      x29, sp, #0x10
//   0x0a2454: B4000120  cbz      x0, #0xa2478
static inline uint64_t fde_func_1692_0x0a2448(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a2448ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x0cc728ULL;
    acc ^= (acc >> 17) * 0x0068ULL;
    return acc;
}

// FDE #1693 | PC: 0x0a24b0 | FDE: 0x0cc750 | Size: 92 bytes
// Hàm FDE #1693 | Địa chỉ PC: 0x0a24b0 | Địa chỉ FDE: 0x0cc750 | Kích thước: 92 bytes
//   0x0a24b0: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x0a24b4: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0a24b8: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0a24bc: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1693_0x0a24b0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a24b0ULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x0cc750ULL;
    acc ^= (acc >> 17) * 0x005cULL;
    return acc;
}

// FDE #1694 | PC: 0x0a250c | FDE: 0x0cc778 | Size: 84 bytes
// Hàm FDE #1694 | Địa chỉ PC: 0x0a250c | Địa chỉ FDE: 0x0cc778 | Kích thước: 84 bytes
//   0x0a250c: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0a2510: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0a2514: 910043FD  add      x29, sp, #0x10
//   0x0a2518: B0000248  adrp     x8, #0xeb000
static inline uint64_t fde_func_1694_0x0a250c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a250cULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x0cc778ULL;
    acc ^= (acc >> 17) * 0x0054ULL;
    return acc;
}

// FDE #1695 | PC: 0x0a2560 | FDE: 0x0cc7a0 | Size: 188 bytes
// Hàm FDE #1695 | Địa chỉ PC: 0x0a2560 | Địa chỉ FDE: 0x0cc7a0 | Kích thước: 188 bytes
//   0x0a2560: D10103FF  sub      sp, sp, #0x40
//   0x0a2564: F9000BF5  str      x21, [sp, #0x10]
//   0x0a2568: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x0a256c: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_1695_0x0a2560(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a2560ULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xf9000bf5ULL) ^ 0x0cc7a0ULL;
    acc ^= (acc >> 17) * 0x00bcULL;
    return acc;
}

// FDE #1696 | PC: 0x0a261c | FDE: 0x0cc0b8 | Size: 156 bytes
// Hàm FDE #1696 | Địa chỉ PC: 0x0a261c | Địa chỉ FDE: 0x0cc0b8 | Kích thước: 156 bytes
//   0x0a261c: D10483FF  sub      sp, sp, #0x120
//   0x0a2620: A9104FFC  stp      x28, x19, [sp, #0x100]
//   0x0a2624: A9117BFD  stp      x29, x30, [sp, #0x110]
//   0x0a2628: 910443FD  add      x29, sp, #0x110
static inline uint64_t fde_func_1696_0x0a261c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a261cULL ^ (static_cast<uint64_t>(0xd10483ffULL) << 13);
    acc = (acc + a1 + 0xa9104ffcULL) ^ 0x0cc0b8ULL;
    acc ^= (acc >> 17) * 0x009cULL;
    return acc;
}

// FDE #1697 | PC: 0x0a26b8 | FDE: 0x0cc0d8 | Size: 196 bytes
// Hàm FDE #1697 | Địa chỉ PC: 0x0a26b8 | Địa chỉ FDE: 0x0cc0d8 | Kích thước: 196 bytes
//   0x0a26b8: D10503FF  sub      sp, sp, #0x140
//   0x0a26bc: F90083FC  str      x28, [sp, #0x100]
//   0x0a26c0: A91157F6  stp      x22, x21, [sp, #0x110]
//   0x0a26c4: A9124FF4  stp      x20, x19, [sp, #0x120]
static inline uint64_t fde_func_1697_0x0a26b8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a26b8ULL ^ (static_cast<uint64_t>(0xd10503ffULL) << 13);
    acc = (acc + a1 + 0xf90083fcULL) ^ 0x0cc0d8ULL;
    acc ^= (acc >> 17) * 0x00c4ULL;
    return acc;
}

// FDE #1698 | PC: 0x0a277c | FDE: 0x0cc100 | Size: 156 bytes
// Hàm FDE #1698 | Địa chỉ PC: 0x0a277c | Địa chỉ FDE: 0x0cc100 | Kích thước: 156 bytes
//   0x0a277c: D10443FF  sub      sp, sp, #0x110
//   0x0a2780: A90F4FFC  stp      x28, x19, [sp, #0xf0]
//   0x0a2784: A9107BFD  stp      x29, x30, [sp, #0x100]
//   0x0a2788: 910403FD  add      x29, sp, #0x100
static inline uint64_t fde_func_1698_0x0a277c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a277cULL ^ (static_cast<uint64_t>(0xd10443ffULL) << 13);
    acc = (acc + a1 + 0xa90f4ffcULL) ^ 0x0cc100ULL;
    acc ^= (acc >> 17) * 0x009cULL;
    return acc;
}

// FDE #1699 | PC: 0x0a2818 | FDE: 0x0cc7c8 | Size: 256 bytes
// Hàm FDE #1699 | Địa chỉ PC: 0x0a2818 | Địa chỉ FDE: 0x0cc7c8 | Kích thước: 256 bytes
//   0x0a2818: D10143FF  sub      sp, sp, #0x50
//   0x0a281c: A9015FF8  stp      x24, x23, [sp, #0x10]
//   0x0a2820: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x0a2824: A9034FF4  stp      x20, x19, [sp, #0x30]
static inline uint64_t fde_func_1699_0x0a2818(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a2818ULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xa9015ff8ULL) ^ 0x0cc7c8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1700 | PC: 0x0a2adc | FDE: 0x0cc7f8 | Size: 256 bytes
// Hàm FDE #1700 | Địa chỉ PC: 0x0a2adc | Địa chỉ FDE: 0x0cc7f8 | Kích thước: 256 bytes
//   0x0a2adc: D10143FF  sub      sp, sp, #0x50
//   0x0a2ae0: A9015FF8  stp      x24, x23, [sp, #0x10]
//   0x0a2ae4: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x0a2ae8: A9034FF4  stp      x20, x19, [sp, #0x30]
static inline uint64_t fde_func_1700_0x0a2adc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a2adcULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xa9015ff8ULL) ^ 0x0cc7f8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1701 | PC: 0x0a2e18 | FDE: 0x0cc828 | Size: 256 bytes
// Hàm FDE #1701 | Địa chỉ PC: 0x0a2e18 | Địa chỉ FDE: 0x0cc828 | Kích thước: 256 bytes
//   0x0a2e18: D10143FF  sub      sp, sp, #0x50
//   0x0a2e1c: A9015FF8  stp      x24, x23, [sp, #0x10]
//   0x0a2e20: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x0a2e24: A9034FF4  stp      x20, x19, [sp, #0x30]
static inline uint64_t fde_func_1701_0x0a2e18(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a2e18ULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xa9015ff8ULL) ^ 0x0cc828ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1702 | PC: 0x0a3154 | FDE: 0x0cc858 | Size: 256 bytes
// Hàm FDE #1702 | Địa chỉ PC: 0x0a3154 | Địa chỉ FDE: 0x0cc858 | Kích thước: 256 bytes
//   0x0a3154: D10143FF  sub      sp, sp, #0x50
//   0x0a3158: A9015FF8  stp      x24, x23, [sp, #0x10]
//   0x0a315c: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x0a3160: A9034FF4  stp      x20, x19, [sp, #0x30]
static inline uint64_t fde_func_1702_0x0a3154(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a3154ULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xa9015ff8ULL) ^ 0x0cc858ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1703 | PC: 0x0a3490 | FDE: 0x0cc888 | Size: 256 bytes
// Hàm FDE #1703 | Địa chỉ PC: 0x0a3490 | Địa chỉ FDE: 0x0cc888 | Kích thước: 256 bytes
//   0x0a3490: D101C3FF  sub      sp, sp, #0x70
//   0x0a3494: A90457F6  stp      x22, x21, [sp, #0x40]
//   0x0a3498: A9054FF4  stp      x20, x19, [sp, #0x50]
//   0x0a349c: A9067BFD  stp      x29, x30, [sp, #0x60]
static inline uint64_t fde_func_1703_0x0a3490(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a3490ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xa90457f6ULL) ^ 0x0cc888ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1704 | PC: 0x0a3650 | FDE: 0x0cc8b8 | Size: 256 bytes
// Hàm FDE #1704 | Địa chỉ PC: 0x0a3650 | Địa chỉ FDE: 0x0cc8b8 | Kích thước: 256 bytes
//   0x0a3650: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x0a3654: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0a3658: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0a365c: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1704_0x0a3650(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a3650ULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x0cc8b8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1705 | PC: 0x0a3770 | FDE: 0x0cc8e0 | Size: 256 bytes
// Hàm FDE #1705 | Địa chỉ PC: 0x0a3770 | Địa chỉ FDE: 0x0cc8e0 | Kích thước: 256 bytes
//   0x0a3770: D10103FF  sub      sp, sp, #0x40
//   0x0a3774: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x0a3778: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x0a377c: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_1705_0x0a3770(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a3770ULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x0cc8e0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1706 | PC: 0x0a393c | FDE: 0x0cc910 | Size: 256 bytes
// Hàm FDE #1706 | Địa chỉ PC: 0x0a393c | Địa chỉ FDE: 0x0cc910 | Kích thước: 256 bytes
//   0x0a393c: D10103FF  sub      sp, sp, #0x40
//   0x0a3940: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x0a3944: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x0a3948: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_1706_0x0a393c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a393cULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x0cc910ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1707 | PC: 0x0a3b8c | FDE: 0x0cc940 | Size: 256 bytes
// Hàm FDE #1707 | Địa chỉ PC: 0x0a3b8c | Địa chỉ FDE: 0x0cc940 | Kích thước: 256 bytes
//   0x0a3b8c: F81B0FF9  str      x25, [sp, #-0x50]!
//   0x0a3b90: A9015FF8  stp      x24, x23, [sp, #0x10]
//   0x0a3b94: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x0a3b98: A9034FF4  stp      x20, x19, [sp, #0x30]
static inline uint64_t fde_func_1707_0x0a3b8c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a3b8cULL ^ (static_cast<uint64_t>(0xf81b0ff9ULL) << 13);
    acc = (acc + a1 + 0xa9015ff8ULL) ^ 0x0cc940ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1708 | PC: 0x0a3e68 | FDE: 0x0cc970 | Size: 256 bytes
// Hàm FDE #1708 | Địa chỉ PC: 0x0a3e68 | Địa chỉ FDE: 0x0cc970 | Kích thước: 256 bytes
//   0x0a3e68: F81A0FFB  str      x27, [sp, #-0x60]!
//   0x0a3e6c: A90167FA  stp      x26, x25, [sp, #0x10]
//   0x0a3e70: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x0a3e74: A90357F6  stp      x22, x21, [sp, #0x30]
static inline uint64_t fde_func_1708_0x0a3e68(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a3e68ULL ^ (static_cast<uint64_t>(0xf81a0ffbULL) << 13);
    acc = (acc + a1 + 0xa90167faULL) ^ 0x0cc970ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1709 | PC: 0x0a4054 | FDE: 0x0cc9a8 | Size: 252 bytes
// Hàm FDE #1709 | Địa chỉ PC: 0x0a4054 | Địa chỉ FDE: 0x0cc9a8 | Kích thước: 252 bytes
//   0x0a4054: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x0a4058: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0a405c: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0a4060: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1709_0x0a4054(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a4054ULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x0cc9a8ULL;
    acc ^= (acc >> 17) * 0x00fcULL;
    return acc;
}

// FDE #1710 | PC: 0x0a4150 | FDE: 0x0cc9d0 | Size: 220 bytes
// Hàm FDE #1710 | Địa chỉ PC: 0x0a4150 | Địa chỉ FDE: 0x0cc9d0 | Kích thước: 220 bytes
//   0x0a4150: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0a4154: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0a4158: 910043FD  add      x29, sp, #0x10
//   0x0a415c: B40002E0  cbz      x0, #0xa41b8
static inline uint64_t fde_func_1710_0x0a4150(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a4150ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x0cc9d0ULL;
    acc ^= (acc >> 17) * 0x00dcULL;
    return acc;
}

// FDE #1711 | PC: 0x0a422c | FDE: 0x0cc9f8 | Size: 48 bytes
// Hàm FDE #1711 | Địa chỉ PC: 0x0a422c | Địa chỉ FDE: 0x0cc9f8 | Kích thước: 48 bytes
//   0x0a422c: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x0a4230: 910003FD  mov      x29, sp
//   0x0a4234: 39402008  ldrb     w8, [x0, #8]
//   0x0a4238: 340000C8  cbz      w8, #0xa4250
static inline uint64_t fde_func_1711_0x0a422c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a422cULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x0cc9f8ULL;
    acc ^= (acc >> 17) * 0x0030ULL;
    return acc;
}

// FDE #1712 | PC: 0x0a425c | FDE: 0x0cc120 | Size: 12 bytes
// Hàm FDE #1712 | Địa chỉ PC: 0x0a425c | Địa chỉ FDE: 0x0cc120 | Kích thước: 12 bytes
//   0x0a425c: F9400008  ldr      x8, [x0]
//   0x0a4260: F9405102  ldr      x2, [x8, #0xa0]
//   0x0a4264: D61F0040  br       x2
static inline uint64_t fde_func_1712_0x0a425c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a425cULL ^ (static_cast<uint64_t>(0xf9400008ULL) << 13);
    acc = (acc + a1 + 0xf9405102ULL) ^ 0x0cc120ULL;
    acc ^= (acc >> 17) * 0x000cULL;
    return acc;
}

// FDE #1713 | PC: 0x0a4268 | FDE: 0x0cca20 | Size: 256 bytes
// Hàm FDE #1713 | Địa chỉ PC: 0x0a4268 | Địa chỉ FDE: 0x0cca20 | Kích thước: 256 bytes
//   0x0a4268: D10243FF  sub      sp, sp, #0x90
//   0x0a426c: A9036FFC  stp      x28, x27, [sp, #0x30]
//   0x0a4270: A90467FA  stp      x26, x25, [sp, #0x40]
//   0x0a4274: A9055FF8  stp      x24, x23, [sp, #0x50]
static inline uint64_t fde_func_1713_0x0a4268(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a4268ULL ^ (static_cast<uint64_t>(0xd10243ffULL) << 13);
    acc = (acc + a1 + 0xa9036ffcULL) ^ 0x0cca20ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1714 | PC: 0x0a4768 | FDE: 0x0cca58 | Size: 256 bytes
// Hàm FDE #1714 | Địa chỉ PC: 0x0a4768 | Địa chỉ FDE: 0x0cca58 | Kích thước: 256 bytes
//   0x0a4768: A9BC5FF8  stp      x24, x23, [sp, #-0x40]!
//   0x0a476c: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x0a4770: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x0a4774: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_1714_0x0a4768(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a4768ULL ^ (static_cast<uint64_t>(0xa9bc5ff8ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x0cca58ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1715 | PC: 0x0a496c | FDE: 0x0cca88 | Size: 256 bytes
// Hàm FDE #1715 | Địa chỉ PC: 0x0a496c | Địa chỉ FDE: 0x0cca88 | Kích thước: 256 bytes
//   0x0a496c: D10143FF  sub      sp, sp, #0x50
//   0x0a4970: F90013F5  str      x21, [sp, #0x20]
//   0x0a4974: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x0a4978: A9047BFD  stp      x29, x30, [sp, #0x40]
static inline uint64_t fde_func_1715_0x0a496c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a496cULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xf90013f5ULL) ^ 0x0cca88ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1716 | PC: 0x0a4ad0 | FDE: 0x0ccab0 | Size: 256 bytes
// Hàm FDE #1716 | Địa chỉ PC: 0x0a4ad0 | Địa chỉ FDE: 0x0ccab0 | Kích thước: 256 bytes
//   0x0a4ad0: D101C3FF  sub      sp, sp, #0x70
//   0x0a4ad4: A9016FFC  stp      x28, x27, [sp, #0x10]
//   0x0a4ad8: A90267FA  stp      x26, x25, [sp, #0x20]
//   0x0a4adc: A9035FF8  stp      x24, x23, [sp, #0x30]
static inline uint64_t fde_func_1716_0x0a4ad0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a4ad0ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xa9016ffcULL) ^ 0x0ccab0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1717 | PC: 0x0a4d6c | FDE: 0x0ccae8 | Size: 256 bytes
// Hàm FDE #1717 | Địa chỉ PC: 0x0a4d6c | Địa chỉ FDE: 0x0ccae8 | Kích thước: 256 bytes
//   0x0a4d6c: D102C3FF  sub      sp, sp, #0xb0
//   0x0a4d70: A9056FFC  stp      x28, x27, [sp, #0x50]
//   0x0a4d74: A90667FA  stp      x26, x25, [sp, #0x60]
//   0x0a4d78: A9075FF8  stp      x24, x23, [sp, #0x70]
static inline uint64_t fde_func_1717_0x0a4d6c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a4d6cULL ^ (static_cast<uint64_t>(0xd102c3ffULL) << 13);
    acc = (acc + a1 + 0xa9056ffcULL) ^ 0x0ccae8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1718 | PC: 0x0a52dc | FDE: 0x0ccb20 | Size: 256 bytes
// Hàm FDE #1718 | Địa chỉ PC: 0x0a52dc | Địa chỉ FDE: 0x0ccb20 | Kích thước: 256 bytes
//   0x0a52dc: A9BB67FA  stp      x26, x25, [sp, #-0x50]!
//   0x0a52e0: A9015FF8  stp      x24, x23, [sp, #0x10]
//   0x0a52e4: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x0a52e8: A9034FF4  stp      x20, x19, [sp, #0x30]
static inline uint64_t fde_func_1718_0x0a52dc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a52dcULL ^ (static_cast<uint64_t>(0xa9bb67faULL) << 13);
    acc = (acc + a1 + 0xa9015ff8ULL) ^ 0x0ccb20ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1719 | PC: 0x0a5448 | FDE: 0x0ccb58 | Size: 256 bytes
// Hàm FDE #1719 | Địa chỉ PC: 0x0a5448 | Địa chỉ FDE: 0x0ccb58 | Kích thước: 256 bytes
//   0x0a5448: F81C0FF7  str      x23, [sp, #-0x40]!
//   0x0a544c: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x0a5450: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x0a5454: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_1719_0x0a5448(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a5448ULL ^ (static_cast<uint64_t>(0xf81c0ff7ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x0ccb58ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1720 | PC: 0x0a55dc | FDE: 0x0ccb88 | Size: 256 bytes
// Hàm FDE #1720 | Địa chỉ PC: 0x0a55dc | Địa chỉ FDE: 0x0ccb88 | Kích thước: 256 bytes
//   0x0a55dc: A9BA6FFC  stp      x28, x27, [sp, #-0x60]!
//   0x0a55e0: A90167FA  stp      x26, x25, [sp, #0x10]
//   0x0a55e4: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x0a55e8: A90357F6  stp      x22, x21, [sp, #0x30]
static inline uint64_t fde_func_1720_0x0a55dc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a55dcULL ^ (static_cast<uint64_t>(0xa9ba6ffcULL) << 13);
    acc = (acc + a1 + 0xa90167faULL) ^ 0x0ccb88ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1721 | PC: 0x0a5764 | FDE: 0x0ccbc0 | Size: 24 bytes
// Hàm FDE #1721 | Địa chỉ PC: 0x0a5764 | Địa chỉ FDE: 0x0ccbc0 | Kích thước: 24 bytes
//   0x0a5764: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x0a5768: 910003FD  mov      x29, sp
//   0x0a576c: 94000004  bl       #0xa577c
//   0x0a5770: A8C17BFD  ldp      x29, x30, [sp], #0x10
static inline uint64_t fde_func_1721_0x0a5764(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a5764ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x0ccbc0ULL;
    acc ^= (acc >> 17) * 0x0018ULL;
    return acc;
}

// FDE #1722 | PC: 0x0a577c | FDE: 0x0ccbe8 | Size: 196 bytes
// Hàm FDE #1722 | Địa chỉ PC: 0x0a577c | Địa chỉ FDE: 0x0ccbe8 | Kích thước: 196 bytes
//   0x0a577c: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x0a5780: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0a5784: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0a5788: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1722_0x0a577c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a577cULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x0ccbe8ULL;
    acc ^= (acc >> 17) * 0x00c4ULL;
    return acc;
}

// FDE #1723 | PC: 0x0a5840 | FDE: 0x0ccc10 | Size: 252 bytes
// Hàm FDE #1723 | Địa chỉ PC: 0x0a5840 | Địa chỉ FDE: 0x0ccc10 | Kích thước: 252 bytes
//   0x0a5840: D100C3FF  sub      sp, sp, #0x30
//   0x0a5844: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0a5848: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0a584c: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1723_0x0a5840(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a5840ULL ^ (static_cast<uint64_t>(0xd100c3ffULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x0ccc10ULL;
    acc ^= (acc >> 17) * 0x00fcULL;
    return acc;
}

// FDE #1724 | PC: 0x0a593c | FDE: 0x0cc138 | Size: 12 bytes
// Hàm FDE #1724 | Địa chỉ PC: 0x0a593c | Địa chỉ FDE: 0x0cc138 | Kích thước: 12 bytes
//   0x0a593c: A9007C1F  stp      xzr, xzr, [x0]
//   0x0a5940: F900081F  str      xzr, [x0, #0x10]
//   0x0a5944: D65F03C0  ret      
static inline uint64_t fde_func_1724_0x0a593c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a593cULL ^ (static_cast<uint64_t>(0xa9007c1fULL) << 13);
    acc = (acc + a1 + 0xf900081fULL) ^ 0x0cc138ULL;
    acc ^= (acc >> 17) * 0x000cULL;
    return acc;
}

// FDE #1725 | PC: 0x0a5948 | FDE: 0x0ccc38 | Size: 160 bytes
// Hàm FDE #1725 | Địa chỉ PC: 0x0a5948 | Địa chỉ FDE: 0x0ccc38 | Kích thước: 160 bytes
//   0x0a5948: D100C3FF  sub      sp, sp, #0x30
//   0x0a594c: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0a5950: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0a5954: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1725_0x0a5948(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a5948ULL ^ (static_cast<uint64_t>(0xd100c3ffULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x0ccc38ULL;
    acc ^= (acc >> 17) * 0x00a0ULL;
    return acc;
}

// FDE #1726 | PC: 0x0a59e8 | FDE: 0x0ccc88 | Size: 256 bytes
// Hàm FDE #1726 | Địa chỉ PC: 0x0a59e8 | Địa chỉ FDE: 0x0ccc88 | Kích thước: 256 bytes
//   0x0a59e8: D10103FF  sub      sp, sp, #0x40
//   0x0a59ec: F9000BF5  str      x21, [sp, #0x10]
//   0x0a59f0: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x0a59f4: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_1726_0x0a59e8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a59e8ULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xf9000bf5ULL) ^ 0x0ccc88ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1727 | PC: 0x0a5af8 | FDE: 0x0cc168 | Size: 8 bytes
// Hàm FDE #1727 | Địa chỉ PC: 0x0a5af8 | Địa chỉ FDE: 0x0cc168 | Kích thước: 8 bytes
//   0x0a5af8: AA1F03E1  mov      x1, xzr
//   0x0a5afc: 140002BE  b        #0xa65f4
static inline uint64_t fde_func_1727_0x0a5af8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a5af8ULL ^ (static_cast<uint64_t>(0xaa1f03e1ULL) << 13);
    acc = (acc + a1 + 0x140002beULL) ^ 0x0cc168ULL;
    acc ^= (acc >> 17) * 0x0008ULL;
    return acc;
}

// FDE #1728 | PC: 0x0a5b00 | FDE: 0x0cccd8 | Size: 80 bytes
// Hàm FDE #1728 | Địa chỉ PC: 0x0a5b00 | Địa chỉ FDE: 0x0cccd8 | Kích thước: 80 bytes
//   0x0a5b00: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0a5b04: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0a5b08: 910043FD  add      x29, sp, #0x10
//   0x0a5b0c: 52800300  mov      w0, #0x18
static inline uint64_t fde_func_1728_0x0a5b00(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a5b00ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x0cccd8ULL;
    acc ^= (acc >> 17) * 0x0050ULL;
    return acc;
}

// FDE #1729 | PC: 0x0a5b50 | FDE: 0x0cc1a0 | Size: 8 bytes
// Hàm FDE #1729 | Địa chỉ PC: 0x0a5b50 | Địa chỉ FDE: 0x0cc1a0 | Kích thước: 8 bytes
//   0x0a5b50: AA1F03E1  mov      x1, xzr
//   0x0a5b54: 1400053C  b        #0xa7044
static inline uint64_t fde_func_1729_0x0a5b50(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a5b50ULL ^ (static_cast<uint64_t>(0xaa1f03e1ULL) << 13);
    acc = (acc + a1 + 0x1400053cULL) ^ 0x0cc1a0ULL;
    acc ^= (acc >> 17) * 0x0008ULL;
    return acc;
}

// FDE #1730 | PC: 0x0a5b58 | FDE: 0x0ccd00 | Size: 196 bytes
// Hàm FDE #1730 | Địa chỉ PC: 0x0a5b58 | Địa chỉ FDE: 0x0ccd00 | Kích thước: 196 bytes
//   0x0a5b58: D10103FF  sub      sp, sp, #0x40
//   0x0a5b5c: F9000BF5  str      x21, [sp, #0x10]
//   0x0a5b60: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x0a5b64: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_1730_0x0a5b58(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a5b58ULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xf9000bf5ULL) ^ 0x0ccd00ULL;
    acc ^= (acc >> 17) * 0x00c4ULL;
    return acc;
}

// FDE #1731 | PC: 0x0a5c1c | FDE: 0x0cc1b8 | Size: 256 bytes
// Hàm FDE #1731 | Địa chỉ PC: 0x0a5c1c | Địa chỉ FDE: 0x0cc1b8 | Kích thước: 256 bytes
//   0x0a5c1c: F81A0FFB  str      x27, [sp, #-0x60]!
//   0x0a5c20: A90167FA  stp      x26, x25, [sp, #0x10]
//   0x0a5c24: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x0a5c28: A90357F6  stp      x22, x21, [sp, #0x30]
static inline uint64_t fde_func_1731_0x0a5c1c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a5c1cULL ^ (static_cast<uint64_t>(0xf81a0ffbULL) << 13);
    acc = (acc + a1 + 0xa90167faULL) ^ 0x0cc1b8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1732 | PC: 0x0a5e54 | FDE: 0x0cc1e8 | Size: 256 bytes
// Hàm FDE #1732 | Địa chỉ PC: 0x0a5e54 | Địa chỉ FDE: 0x0cc1e8 | Kích thước: 256 bytes
//   0x0a5e54: A9BA6FFC  stp      x28, x27, [sp, #-0x60]!
//   0x0a5e58: A90167FA  stp      x26, x25, [sp, #0x10]
//   0x0a5e5c: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x0a5e60: A90357F6  stp      x22, x21, [sp, #0x30]
static inline uint64_t fde_func_1732_0x0a5e54(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a5e54ULL ^ (static_cast<uint64_t>(0xa9ba6ffcULL) << 13);
    acc = (acc + a1 + 0xa90167faULL) ^ 0x0cc1e8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1733 | PC: 0x0a610c | FDE: 0x0ccd28 | Size: 256 bytes
// Hàm FDE #1733 | Địa chỉ PC: 0x0a610c | Địa chỉ FDE: 0x0ccd28 | Kích thước: 256 bytes
//   0x0a610c: A9BB67FA  stp      x26, x25, [sp, #-0x50]!
//   0x0a6110: A9015FF8  stp      x24, x23, [sp, #0x10]
//   0x0a6114: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x0a6118: A9034FF4  stp      x20, x19, [sp, #0x30]
static inline uint64_t fde_func_1733_0x0a610c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a610cULL ^ (static_cast<uint64_t>(0xa9bb67faULL) << 13);
    acc = (acc + a1 + 0xa9015ff8ULL) ^ 0x0ccd28ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1734 | PC: 0x0a62a8 | FDE: 0x0ccd60 | Size: 256 bytes
// Hàm FDE #1734 | Địa chỉ PC: 0x0a62a8 | Địa chỉ FDE: 0x0ccd60 | Kích thước: 256 bytes
//   0x0a62a8: F81A0FFB  str      x27, [sp, #-0x60]!
//   0x0a62ac: A90167FA  stp      x26, x25, [sp, #0x10]
//   0x0a62b0: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x0a62b4: A90357F6  stp      x22, x21, [sp, #0x30]
static inline uint64_t fde_func_1734_0x0a62a8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a62a8ULL ^ (static_cast<uint64_t>(0xf81a0ffbULL) << 13);
    acc = (acc + a1 + 0xa90167faULL) ^ 0x0ccd60ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1735 | PC: 0x0a63dc | FDE: 0x0ccd98 | Size: 256 bytes
// Hàm FDE #1735 | Địa chỉ PC: 0x0a63dc | Địa chỉ FDE: 0x0ccd98 | Kích thước: 256 bytes
//   0x0a63dc: F81A0FFB  str      x27, [sp, #-0x60]!
//   0x0a63e0: A90167FA  stp      x26, x25, [sp, #0x10]
//   0x0a63e4: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x0a63e8: A90357F6  stp      x22, x21, [sp, #0x30]
static inline uint64_t fde_func_1735_0x0a63dc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a63dcULL ^ (static_cast<uint64_t>(0xf81a0ffbULL) << 13);
    acc = (acc + a1 + 0xa90167faULL) ^ 0x0ccd98ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1736 | PC: 0x0a65f4 | FDE: 0x0ccdd0 | Size: 188 bytes
// Hàm FDE #1736 | Địa chỉ PC: 0x0a65f4 | Địa chỉ FDE: 0x0ccdd0 | Kích thước: 188 bytes
//   0x0a65f4: D10103FF  sub      sp, sp, #0x40
//   0x0a65f8: F9000BF5  str      x21, [sp, #0x10]
//   0x0a65fc: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x0a6600: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_1736_0x0a65f4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a65f4ULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xf9000bf5ULL) ^ 0x0ccdd0ULL;
    acc ^= (acc >> 17) * 0x00bcULL;
    return acc;
}

// FDE #1737 | PC: 0x0a66b0 | FDE: 0x0cc218 | Size: 256 bytes
// Hàm FDE #1737 | Địa chỉ PC: 0x0a66b0 | Địa chỉ FDE: 0x0cc218 | Kích thước: 256 bytes
//   0x0a66b0: F81B0FF9  str      x25, [sp, #-0x50]!
//   0x0a66b4: A9015FF8  stp      x24, x23, [sp, #0x10]
//   0x0a66b8: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x0a66bc: A9034FF4  stp      x20, x19, [sp, #0x30]
static inline uint64_t fde_func_1737_0x0a66b0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a66b0ULL ^ (static_cast<uint64_t>(0xf81b0ff9ULL) << 13);
    acc = (acc + a1 + 0xa9015ff8ULL) ^ 0x0cc218ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1738 | PC: 0x0a67c8 | FDE: 0x0cc240 | Size: 256 bytes
// Hàm FDE #1738 | Địa chỉ PC: 0x0a67c8 | Địa chỉ FDE: 0x0cc240 | Kích thước: 256 bytes
//   0x0a67c8: F9400409  ldr      x9, [x0, #8]
//   0x0a67cc: F940042A  ldr      x10, [x1, #8]
//   0x0a67d0: 9E670120  fmov     d0, x9
//   0x0a67d4: 0E205800  cnt      v0.8b, v0.8b
static inline uint64_t fde_func_1738_0x0a67c8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a67c8ULL ^ (static_cast<uint64_t>(0xf9400409ULL) << 13);
    acc = (acc + a1 + 0xf940042aULL) ^ 0x0cc240ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1739 | PC: 0x0a6914 | FDE: 0x0ccdf8 | Size: 256 bytes
// Hàm FDE #1739 | Địa chỉ PC: 0x0a6914 | Địa chỉ FDE: 0x0ccdf8 | Kích thước: 256 bytes
//   0x0a6914: A9BA6FFC  stp      x28, x27, [sp, #-0x60]!
//   0x0a6918: A90167FA  stp      x26, x25, [sp, #0x10]
//   0x0a691c: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x0a6920: A90357F6  stp      x22, x21, [sp, #0x30]
static inline uint64_t fde_func_1739_0x0a6914(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a6914ULL ^ (static_cast<uint64_t>(0xa9ba6ffcULL) << 13);
    acc = (acc + a1 + 0xa90167faULL) ^ 0x0ccdf8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1740 | PC: 0x0a6ba8 | FDE: 0x0cc258 | Size: 228 bytes
// Hàm FDE #1740 | Địa chỉ PC: 0x0a6ba8 | Địa chỉ FDE: 0x0cc258 | Kích thước: 228 bytes
//   0x0a6ba8: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x0a6bac: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0a6bb0: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0a6bb4: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1740_0x0a6ba8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a6ba8ULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x0cc258ULL;
    acc ^= (acc >> 17) * 0x00e4ULL;
    return acc;
}

// FDE #1741 | PC: 0x0a6c8c | FDE: 0x0cc278 | Size: 256 bytes
// Hàm FDE #1741 | Địa chỉ PC: 0x0a6c8c | Địa chỉ FDE: 0x0cc278 | Kích thước: 256 bytes
//   0x0a6c8c: F81A0FFB  str      x27, [sp, #-0x60]!
//   0x0a6c90: A90167FA  stp      x26, x25, [sp, #0x10]
//   0x0a6c94: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x0a6c98: A90357F6  stp      x22, x21, [sp, #0x30]
static inline uint64_t fde_func_1741_0x0a6c8c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a6c8cULL ^ (static_cast<uint64_t>(0xf81a0ffbULL) << 13);
    acc = (acc + a1 + 0xa90167faULL) ^ 0x0cc278ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1742 | PC: 0x0a6e7c | FDE: 0x0cc2a8 | Size: 36 bytes
// Hàm FDE #1742 | Địa chỉ PC: 0x0a6e7c | Địa chỉ FDE: 0x0cc2a8 | Kích thước: 36 bytes
//   0x0a6e7c: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x0a6e80: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0a6e84: 910043FD  add      x29, sp, #0x10
//   0x0a6e88: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_1742_0x0a6e7c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a6e7cULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x0cc2a8ULL;
    acc ^= (acc >> 17) * 0x0024ULL;
    return acc;
}

// FDE #1743 | PC: 0x0a6ea0 | FDE: 0x0cc2c8 | Size: 132 bytes
// Hàm FDE #1743 | Địa chỉ PC: 0x0a6ea0 | Địa chỉ FDE: 0x0cc2c8 | Kích thước: 132 bytes
//   0x0a6ea0: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x0a6ea4: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0a6ea8: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0a6eac: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1743_0x0a6ea0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a6ea0ULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x0cc2c8ULL;
    acc ^= (acc >> 17) * 0x0084ULL;
    return acc;
}

// FDE #1744 | PC: 0x0a6f24 | FDE: 0x0cc2e8 | Size: 28 bytes
// Hàm FDE #1744 | Địa chỉ PC: 0x0a6f24 | Địa chỉ FDE: 0x0cc2e8 | Kích thước: 28 bytes
//   0x0a6f24: F9400428  ldr      x8, [x1, #8]
//   0x0a6f28: D0000089  adrp     x9, #0xb8000
//   0x0a6f2c: 91291D29  add      x9, x9, #0xa47
//   0x0a6f30: 9100600A  add      x10, x0, #0x18
static inline uint64_t fde_func_1744_0x0a6f24(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a6f24ULL ^ (static_cast<uint64_t>(0xf9400428ULL) << 13);
    acc = (acc + a1 + 0xd0000089ULL) ^ 0x0cc2e8ULL;
    acc ^= (acc >> 17) * 0x001cULL;
    return acc;
}

// FDE #1745 | PC: 0x0a6f40 | FDE: 0x0cc300 | Size: 4 bytes
// Hàm FDE #1745 | Địa chỉ PC: 0x0a6f40 | Địa chỉ FDE: 0x0cc300 | Kích thước: 4 bytes
//   0x0a6f40: 17FDAE30  b        #0x12800
static inline uint64_t fde_func_1745_0x0a6f40(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a6f40ULL ^ (static_cast<uint64_t>(0x17fdae30ULL) << 13);
    acc = (acc + a1 + 0xd100c3ffULL) ^ 0x0cc300ULL;
    acc ^= (acc >> 17) * 0x0004ULL;
    return acc;
}

// FDE #1746 | PC: 0x0a6f44 | FDE: 0x0cce30 | Size: 256 bytes
// Hàm FDE #1746 | Địa chỉ PC: 0x0a6f44 | Địa chỉ FDE: 0x0cce30 | Kích thước: 256 bytes
//   0x0a6f44: D100C3FF  sub      sp, sp, #0x30
//   0x0a6f48: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0a6f4c: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0a6f50: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1746_0x0a6f44(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a6f44ULL ^ (static_cast<uint64_t>(0xd100c3ffULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x0cce30ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1747 | PC: 0x0a7044 | FDE: 0x0cce58 | Size: 188 bytes
// Hàm FDE #1747 | Địa chỉ PC: 0x0a7044 | Địa chỉ FDE: 0x0cce58 | Kích thước: 188 bytes
//   0x0a7044: D10103FF  sub      sp, sp, #0x40
//   0x0a7048: F9000BF5  str      x21, [sp, #0x10]
//   0x0a704c: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x0a7050: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_1747_0x0a7044(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a7044ULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xf9000bf5ULL) ^ 0x0cce58ULL;
    acc ^= (acc >> 17) * 0x00bcULL;
    return acc;
}

// FDE #1748 | PC: 0x0a7100 | FDE: 0x0cc318 | Size: 256 bytes
// Hàm FDE #1748 | Địa chỉ PC: 0x0a7100 | Địa chỉ FDE: 0x0cc318 | Kích thước: 256 bytes
//   0x0a7100: F9400408  ldr      x8, [x0, #8]
//   0x0a7104: B40007E8  cbz      x8, #0xa7200
//   0x0a7108: A940242B  ldp      x11, x9, [x1]
//   0x0a710c: D285AD2C  mov      x12, #0x2d69
static inline uint64_t fde_func_1748_0x0a7100(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a7100ULL ^ (static_cast<uint64_t>(0xf9400408ULL) << 13);
    acc = (acc + a1 + 0xb40007e8ULL) ^ 0x0cc318ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1749 | PC: 0x0a720c | FDE: 0x0cce80 | Size: 256 bytes
// Hàm FDE #1749 | Địa chỉ PC: 0x0a720c | Địa chỉ FDE: 0x0cce80 | Kích thước: 256 bytes
//   0x0a720c: D10143FF  sub      sp, sp, #0x50
//   0x0a7210: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x0a7214: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x0a7218: A9047BFD  stp      x29, x30, [sp, #0x40]
static inline uint64_t fde_func_1749_0x0a720c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a720cULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xa90257f6ULL) ^ 0x0cce80ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1750 | PC: 0x0a7388 | FDE: 0x0cc330 | Size: 256 bytes
// Hàm FDE #1750 | Địa chỉ PC: 0x0a7388 | Địa chỉ FDE: 0x0cc330 | Kích thước: 256 bytes
//   0x0a7388: F9400409  ldr      x9, [x0, #8]
//   0x0a738c: F940042A  ldr      x10, [x1, #8]
//   0x0a7390: 9E670120  fmov     d0, x9
//   0x0a7394: 0E205800  cnt      v0.8b, v0.8b
static inline uint64_t fde_func_1750_0x0a7388(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a7388ULL ^ (static_cast<uint64_t>(0xf9400409ULL) << 13);
    acc = (acc + a1 + 0xf940042aULL) ^ 0x0cc330ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1751 | PC: 0x0a74d4 | FDE: 0x0cceb0 | Size: 196 bytes
// Hàm FDE #1751 | Địa chỉ PC: 0x0a74d4 | Địa chỉ FDE: 0x0cceb0 | Kích thước: 196 bytes
//   0x0a74d4: D10103FF  sub      sp, sp, #0x40
//   0x0a74d8: F9000BF5  str      x21, [sp, #0x10]
//   0x0a74dc: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x0a74e0: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_1751_0x0a74d4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a74d4ULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xf9000bf5ULL) ^ 0x0cceb0ULL;
    acc ^= (acc >> 17) * 0x00c4ULL;
    return acc;
}

// FDE #1752 | PC: 0x0a7598 | FDE: 0x0cced8 | Size: 256 bytes
// Hàm FDE #1752 | Địa chỉ PC: 0x0a7598 | Địa chỉ FDE: 0x0cced8 | Kích thước: 256 bytes
//   0x0a7598: D10183FF  sub      sp, sp, #0x60
//   0x0a759c: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x0a75a0: A90357F6  stp      x22, x21, [sp, #0x30]
//   0x0a75a4: A9044FF4  stp      x20, x19, [sp, #0x40]
static inline uint64_t fde_func_1752_0x0a7598(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a7598ULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xa9025ff8ULL) ^ 0x0cced8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1753 | PC: 0x0a7848 | FDE: 0x0ccf08 | Size: 256 bytes
// Hàm FDE #1753 | Địa chỉ PC: 0x0a7848 | Địa chỉ FDE: 0x0ccf08 | Kích thước: 256 bytes
//   0x0a7848: D10183FF  sub      sp, sp, #0x60
//   0x0a784c: F9000BF9  str      x25, [sp, #0x10]
//   0x0a7850: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x0a7854: A90357F6  stp      x22, x21, [sp, #0x30]
static inline uint64_t fde_func_1753_0x0a7848(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a7848ULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xf9000bf9ULL) ^ 0x0ccf08ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1754 | PC: 0x0a79b0 | FDE: 0x0cc348 | Size: 228 bytes
// Hàm FDE #1754 | Địa chỉ PC: 0x0a79b0 | Địa chỉ FDE: 0x0cc348 | Kích thước: 228 bytes
//   0x0a79b0: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x0a79b4: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0a79b8: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0a79bc: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1754_0x0a79b0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a79b0ULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x0cc348ULL;
    acc ^= (acc >> 17) * 0x00e4ULL;
    return acc;
}

// FDE #1755 | PC: 0x0a7a94 | FDE: 0x0ccf38 | Size: 256 bytes
// Hàm FDE #1755 | Địa chỉ PC: 0x0a7a94 | Địa chỉ FDE: 0x0ccf38 | Kích thước: 256 bytes
//   0x0a7a94: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x0a7a98: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0a7a9c: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0a7aa0: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1755_0x0a7a94(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a7a94ULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x0ccf38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1756 | PC: 0x0a7bbc | FDE: 0x0cc368 | Size: 256 bytes
// Hàm FDE #1756 | Địa chỉ PC: 0x0a7bbc | Địa chỉ FDE: 0x0cc368 | Kích thước: 256 bytes
//   0x0a7bbc: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0a7bc0: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0a7bc4: 910043FD  add      x29, sp, #0x10
//   0x0a7bc8: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_1756_0x0a7bbc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a7bbcULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x0cc368ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1757 | PC: 0x0a7d5c | FDE: 0x0cc388 | Size: 36 bytes
// Hàm FDE #1757 | Địa chỉ PC: 0x0a7d5c | Địa chỉ FDE: 0x0cc388 | Kích thước: 36 bytes
//   0x0a7d5c: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x0a7d60: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0a7d64: 910043FD  add      x29, sp, #0x10
//   0x0a7d68: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_1757_0x0a7d5c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a7d5cULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x0cc388ULL;
    acc ^= (acc >> 17) * 0x0024ULL;
    return acc;
}

// FDE #1758 | PC: 0x0a7d80 | FDE: 0x0cc3a8 | Size: 64 bytes
// Hàm FDE #1758 | Địa chỉ PC: 0x0a7d80 | Địa chỉ FDE: 0x0cc3a8 | Kích thước: 64 bytes
//   0x0a7d80: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x0a7d84: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0a7d88: 910043FD  add      x29, sp, #0x10
//   0x0a7d8c: F9400C13  ldr      x19, [x0, #0x18]
static inline uint64_t fde_func_1758_0x0a7d80(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a7d80ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x0cc3a8ULL;
    acc ^= (acc >> 17) * 0x0040ULL;
    return acc;
}

// FDE #1759 | PC: 0x0a7dc0 | FDE: 0x0cc3c8 | Size: 28 bytes
// Hàm FDE #1759 | Địa chỉ PC: 0x0a7dc0 | Địa chỉ FDE: 0x0cc3c8 | Kích thước: 28 bytes
//   0x0a7dc0: F9400428  ldr      x8, [x1, #8]
//   0x0a7dc4: B0000089  adrp     x9, #0xb8000
//   0x0a7dc8: 912CA129  add      x9, x9, #0xb28
//   0x0a7dcc: 9100600A  add      x10, x0, #0x18
static inline uint64_t fde_func_1759_0x0a7dc0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a7dc0ULL ^ (static_cast<uint64_t>(0xf9400428ULL) << 13);
    acc = (acc + a1 + 0xb0000089ULL) ^ 0x0cc3c8ULL;
    acc ^= (acc >> 17) * 0x001cULL;
    return acc;
}

// FDE #1760 | PC: 0x0a7ddc | FDE: 0x0cc3e0 | Size: 4 bytes
// Hàm FDE #1760 | Địa chỉ PC: 0x0a7ddc | Địa chỉ FDE: 0x0cc3e0 | Kích thước: 4 bytes
//   0x0a7ddc: 17FDAA89  b        #0x12800
static inline uint64_t fde_func_1760_0x0a7ddc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a7ddcULL ^ (static_cast<uint64_t>(0x17fdaa89ULL) << 13);
    acc = (acc + a1 + 0xd10143ffULL) ^ 0x0cc3e0ULL;
    acc ^= (acc >> 17) * 0x0004ULL;
    return acc;
}

// FDE #1761 | PC: 0x0a7de0 | FDE: 0x0ccf60 | Size: 236 bytes
// Hàm FDE #1761 | Địa chỉ PC: 0x0a7de0 | Địa chỉ FDE: 0x0ccf60 | Kích thước: 236 bytes
//   0x0a7de0: D10143FF  sub      sp, sp, #0x50
//   0x0a7de4: A9015FF8  stp      x24, x23, [sp, #0x10]
//   0x0a7de8: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x0a7dec: A9034FF4  stp      x20, x19, [sp, #0x30]
static inline uint64_t fde_func_1761_0x0a7de0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a7de0ULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xa9015ff8ULL) ^ 0x0ccf60ULL;
    acc ^= (acc >> 17) * 0x00ecULL;
    return acc;
}

// FDE #1762 | PC: 0x0a7ecc | FDE: 0x0ccfa8 | Size: 256 bytes
// Hàm FDE #1762 | Địa chỉ PC: 0x0a7ecc | Địa chỉ FDE: 0x0ccfa8 | Kích thước: 256 bytes
//   0x0a7ecc: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x0a7ed0: 9E660000  fmov     x0, d0
//   0x0a7ed4: 9EAE0001  fmov     x1, v0.d[1]
//   0x0a7ed8: 910003FD  mov      x29, sp
static inline uint64_t fde_func_1762_0x0a7ecc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a7eccULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x9e660000ULL) ^ 0x0ccfa8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1763 | PC: 0x0a8008 | FDE: 0x0ccfd0 | Size: 256 bytes
// Hàm FDE #1763 | Địa chỉ PC: 0x0a8008 | Địa chỉ FDE: 0x0ccfd0 | Kích thước: 256 bytes
//   0x0a8008: 9E660000  fmov     x0, d0
//   0x0a800c: 9EAE0001  fmov     x1, v0.d[1]
//   0x0a8010: A9BD7BFD  stp      x29, x30, [sp, #-0x30]!
//   0x0a8014: AA0003E3  mov      x3, x0
static inline uint64_t fde_func_1763_0x0a8008(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a8008ULL ^ (static_cast<uint64_t>(0x9e660000ULL) << 13);
    acc = (acc + a1 + 0x9eae0001ULL) ^ 0x0ccfd0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1764 | PC: 0x0a86e8 | FDE: 0x0cd000 | Size: 256 bytes
// Hàm FDE #1764 | Địa chỉ PC: 0x0a86e8 | Địa chỉ FDE: 0x0cd000 | Kích thước: 256 bytes
//   0x0a86e8: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x0a86ec: 9E660000  fmov     x0, d0
//   0x0a86f0: 9EAE0001  fmov     x1, v0.d[1]
//   0x0a86f4: 910003FD  mov      x29, sp
static inline uint64_t fde_func_1764_0x0a86e8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a86e8ULL ^ (static_cast<uint64_t>(0xa9be7bfdULL) << 13);
    acc = (acc + a1 + 0x9e660000ULL) ^ 0x0cd000ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1765 | PC: 0x0a91fc | FDE: 0x0cd028 | Size: 140 bytes
// Hàm FDE #1765 | Địa chỉ PC: 0x0a91fc | Địa chỉ FDE: 0x0cd028 | Kích thước: 140 bytes
//   0x0a91fc: B4000300  cbz      x0, #0xa925c
//   0x0a9200: D37FFC01  lsr      x1, x0, #0x3f
//   0x0a9204: D2880DE3  mov      x3, #0x406f
//   0x0a9208: 6B1F003F  cmp      w1, wzr
static inline uint64_t fde_func_1765_0x0a91fc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a91fcULL ^ (static_cast<uint64_t>(0xb4000300ULL) << 13);
    acc = (acc + a1 + 0xd37ffc01ULL) ^ 0x0cd028ULL;
    acc ^= (acc >> 17) * 0x008cULL;
    return acc;
}

// FDE #1766 | PC: 0x0a9288 | FDE: 0x0cd040 | Size: 40 bytes
// Hàm FDE #1766 | Địa chỉ PC: 0x0a9288 | Địa chỉ FDE: 0x0cd040 | Kích thước: 40 bytes
//   0x0a9288: D2800002  mov      x2, #0
//   0x0a928c: 52800003  mov      w3, #0
//   0x0a9290: 38401405  ldrb     w5, [x0], #1
//   0x0a9294: 924018A4  and      x4, x5, #0x7f
static inline uint64_t fde_func_1766_0x0a9288(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a9288ULL ^ (static_cast<uint64_t>(0xd2800002ULL) << 13);
    acc = (acc + a1 + 0x52800003ULL) ^ 0x0cd040ULL;
    acc ^= (acc >> 17) * 0x0028ULL;
    return acc;
}

// FDE #1767 | PC: 0x0a92b0 | FDE: 0x0cd058 | Size: 64 bytes
// Hàm FDE #1767 | Địa chỉ PC: 0x0a92b0 | Địa chỉ FDE: 0x0cd058 | Kích thước: 64 bytes
//   0x0a92b0: D2800002  mov      x2, #0
//   0x0a92b4: 52800003  mov      w3, #0
//   0x0a92b8: 38401404  ldrb     w4, [x0], #1
//   0x0a92bc: 92401885  and      x5, x4, #0x7f
static inline uint64_t fde_func_1767_0x0a92b0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a92b0ULL ^ (static_cast<uint64_t>(0xd2800002ULL) << 13);
    acc = (acc + a1 + 0x52800003ULL) ^ 0x0cd058ULL;
    acc ^= (acc >> 17) * 0x0040ULL;
    return acc;
}

// FDE #1768 | PC: 0x0a92f0 | FDE: 0x0cd070 | Size: 240 bytes
// Hàm FDE #1768 | Địa chỉ PC: 0x0a92f0 | Địa chỉ FDE: 0x0cd070 | Kích thước: 240 bytes
//   0x0a92f0: A9BC7BFD  stp      x29, x30, [sp, #-0x40]!
//   0x0a92f4: 910003FD  mov      x29, sp
//   0x0a92f8: A90153F3  stp      x19, x20, [sp, #0x10]
//   0x0a92fc: 53001C14  uxtb     w20, w0
static inline uint64_t fde_func_1768_0x0a92f0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a92f0ULL ^ (static_cast<uint64_t>(0xa9bc7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x0cd070ULL;
    acc ^= (acc >> 17) * 0x00f0ULL;
    return acc;
}

// FDE #1769 | PC: 0x0a93e0 | FDE: 0x0cd0a8 | Size: 256 bytes
// Hàm FDE #1769 | Địa chỉ PC: 0x0a93e0 | Địa chỉ FDE: 0x0cd0a8 | Kích thước: 256 bytes
//   0x0a93e0: F0000202  adrp     x2, #0xec000
//   0x0a93e4: 52800100  mov      w0, #8
//   0x0a93e8: 91394041  add      x1, x2, #0xe50
//   0x0a93ec: 39394040  strb     w0, [x2, #0xe50]
static inline uint64_t fde_func_1769_0x0a93e0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a93e0ULL ^ (static_cast<uint64_t>(0xf0000202ULL) << 13);
    acc = (acc + a1 + 0x52800100ULL) ^ 0x0cd0a8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1770 | PC: 0x0a94f4 | FDE: 0x0cd0c0 | Size: 60 bytes
// Hàm FDE #1770 | Địa chỉ PC: 0x0a94f4 | Địa chỉ FDE: 0x0cd0c0 | Kích thước: 60 bytes
//   0x0a94f4: F0000203  adrp     x3, #0xec000
//   0x0a94f8: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x0a94fc: 910003FD  mov      x29, sp
//   0x0a9500: 3979BC63  ldrb     w3, [x3, #0xe6f]
static inline uint64_t fde_func_1770_0x0a94f4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a94f4ULL ^ (static_cast<uint64_t>(0xf0000203ULL) << 13);
    acc = (acc + a1 + 0xa9bf7bfdULL) ^ 0x0cd0c0ULL;
    acc ^= (acc >> 17) * 0x003cULL;
    return acc;
}

// FDE #1771 | PC: 0x0a9530 | FDE: 0x0cd0e8 | Size: 88 bytes
// Hàm FDE #1771 | Địa chỉ PC: 0x0a9530 | Địa chỉ FDE: 0x0cd0e8 | Kích thước: 88 bytes
//   0x0a9530: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x0a9534: 7101843F  cmp      w1, #0x61
//   0x0a9538: 910003FD  mov      x29, sp
//   0x0a953c: 5400004D  b.le     #0xa9544
static inline uint64_t fde_func_1771_0x0a9530(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a9530ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x7101843fULL) ^ 0x0cd0e8ULL;
    acc ^= (acc >> 17) * 0x0058ULL;
    return acc;
}

// FDE #1772 | PC: 0x0a9588 | FDE: 0x0cd110 | Size: 256 bytes
// Hàm FDE #1772 | Địa chỉ PC: 0x0a9588 | Địa chỉ FDE: 0x0cd110 | Kích thước: 256 bytes
//   0x0a9588: A9BC7BFD  stp      x29, x30, [sp, #-0x40]!
//   0x0a958c: 910003FD  mov      x29, sp
//   0x0a9590: A9025BF5  stp      x21, x22, [sp, #0x20]
//   0x0a9594: AA0003F5  mov      x21, x0
static inline uint64_t fde_func_1772_0x0a9588(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a9588ULL ^ (static_cast<uint64_t>(0xa9bc7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x0cd110ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1773 | PC: 0x0a9694 | FDE: 0x0cd148 | Size: 8 bytes
// Hàm FDE #1773 | Địa chỉ PC: 0x0a9694 | Địa chỉ FDE: 0x0cd148 | Kích thước: 8 bytes
//   0x0a9694: F9418800  ldr      x0, [x0, #0x310]
//   0x0a9698: D65F03C0  ret      
static inline uint64_t fde_func_1773_0x0a9694(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a9694ULL ^ (static_cast<uint64_t>(0xf9418800ULL) << 13);
    acc = (acc + a1 + 0xd65f03c0ULL) ^ 0x0cd148ULL;
    acc ^= (acc >> 17) * 0x0008ULL;
    return acc;
}

// FDE #1774 | PC: 0x0a969c | FDE: 0x0cd160 | Size: 88 bytes
// Hàm FDE #1774 | Địa chỉ PC: 0x0a969c | Địa chỉ FDE: 0x0cd160 | Kích thước: 88 bytes
//   0x0a969c: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x0a96a0: 7101843F  cmp      w1, #0x61
//   0x0a96a4: 910003FD  mov      x29, sp
//   0x0a96a8: 5400004D  b.le     #0xa96b0
static inline uint64_t fde_func_1774_0x0a969c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a969cULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x7101843fULL) ^ 0x0cd160ULL;
    acc ^= (acc >> 17) * 0x0058ULL;
    return acc;
}

// FDE #1775 | PC: 0x0a96f4 | FDE: 0x0cd188 | Size: 8 bytes
// Hàm FDE #1775 | Địa chỉ PC: 0x0a96f4 | Địa chỉ FDE: 0x0cd188 | Kích thước: 8 bytes
//   0x0a96f4: F9418C00  ldr      x0, [x0, #0x318]
//   0x0a96f8: D65F03C0  ret      
static inline uint64_t fde_func_1775_0x0a96f4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a96f4ULL ^ (static_cast<uint64_t>(0xf9418c00ULL) << 13);
    acc = (acc + a1 + 0xd65f03c0ULL) ^ 0x0cd188ULL;
    acc ^= (acc >> 17) * 0x0008ULL;
    return acc;
}

// FDE #1776 | PC: 0x0a96fc | FDE: 0x0cd1a0 | Size: 20 bytes
// Hàm FDE #1776 | Địa chỉ PC: 0x0a96fc | Địa chỉ FDE: 0x0cd1a0 | Kích thước: 20 bytes
//   0x0a96fc: F941A002  ldr      x2, [x0, #0x340]
//   0x0a9700: F9418C00  ldr      x0, [x0, #0x318]
//   0x0a9704: D37FFC42  lsr      x2, x2, #0x3f
//   0x0a9708: B9000022  str      w2, [x1]
static inline uint64_t fde_func_1776_0x0a96fc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a96fcULL ^ (static_cast<uint64_t>(0xf941a002ULL) << 13);
    acc = (acc + a1 + 0xf9418c00ULL) ^ 0x0cd1a0ULL;
    acc ^= (acc >> 17) * 0x0014ULL;
    return acc;
}

// FDE #1777 | PC: 0x0a9710 | FDE: 0x0cd1b8 | Size: 8 bytes
// Hàm FDE #1777 | Địa chỉ PC: 0x0a9710 | Địa chỉ FDE: 0x0cd1b8 | Kích thước: 8 bytes
//   0x0a9710: F9018C01  str      x1, [x0, #0x318]
//   0x0a9714: D65F03C0  ret      
static inline uint64_t fde_func_1777_0x0a9710(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a9710ULL ^ (static_cast<uint64_t>(0xf9018c01ULL) << 13);
    acc = (acc + a1 + 0xd65f03c0ULL) ^ 0x0cd1b8ULL;
    acc ^= (acc >> 17) * 0x0008ULL;
    return acc;
}

// FDE #1778 | PC: 0x0a9718 | FDE: 0x0cd1d0 | Size: 8 bytes
// Hàm FDE #1778 | Địa chỉ PC: 0x0a9718 | Địa chỉ FDE: 0x0cd1d0 | Kích thước: 8 bytes
//   0x0a9718: F9419000  ldr      x0, [x0, #0x320]
//   0x0a971c: D65F03C0  ret      
static inline uint64_t fde_func_1778_0x0a9718(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a9718ULL ^ (static_cast<uint64_t>(0xf9419000ULL) << 13);
    acc = (acc + a1 + 0xd65f03c0ULL) ^ 0x0cd1d0ULL;
    acc ^= (acc >> 17) * 0x0008ULL;
    return acc;
}

// FDE #1779 | PC: 0x0a9720 | FDE: 0x0cd1e8 | Size: 8 bytes
// Hàm FDE #1779 | Địa chỉ PC: 0x0a9720 | Địa chỉ FDE: 0x0cd1e8 | Kích thước: 8 bytes
//   0x0a9720: F9419C00  ldr      x0, [x0, #0x338]
//   0x0a9724: D65F03C0  ret      
static inline uint64_t fde_func_1779_0x0a9720(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a9720ULL ^ (static_cast<uint64_t>(0xf9419c00ULL) << 13);
    acc = (acc + a1 + 0xd65f03c0ULL) ^ 0x0cd1e8ULL;
    acc ^= (acc >> 17) * 0x0008ULL;
    return acc;
}

// FDE #1780 | PC: 0x0a9728 | FDE: 0x0cd200 | Size: 40 bytes
// Hàm FDE #1780 | Địa chỉ PC: 0x0a9728 | Địa chỉ FDE: 0x0cd200 | Kích thước: 40 bytes
//   0x0a9728: A9BD7BFD  stp      x29, x30, [sp, #-0x30]!
//   0x0a972c: D1000400  sub      x0, x0, #1
//   0x0a9730: 910003FD  mov      x29, sp
//   0x0a9734: 910063A1  add      x1, x29, #0x18
static inline uint64_t fde_func_1780_0x0a9728(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a9728ULL ^ (static_cast<uint64_t>(0xa9bd7bfdULL) << 13);
    acc = (acc + a1 + 0xd1000400ULL) ^ 0x0cd200ULL;
    acc ^= (acc >> 17) * 0x0028ULL;
    return acc;
}

// FDE #1781 | PC: 0x0a9750 | FDE: 0x0cd228 | Size: 8 bytes
// Hàm FDE #1781 | Địa chỉ PC: 0x0a9750 | Địa chỉ FDE: 0x0cd228 | Kích thước: 8 bytes
//   0x0a9750: F9419800  ldr      x0, [x0, #0x330]
//   0x0a9754: D65F03C0  ret      
static inline uint64_t fde_func_1781_0x0a9750(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a9750ULL ^ (static_cast<uint64_t>(0xf9419800ULL) << 13);
    acc = (acc + a1 + 0xd65f03c0ULL) ^ 0x0cd228ULL;
    acc ^= (acc >> 17) * 0x0008ULL;
    return acc;
}

// FDE #1782 | PC: 0x0a9758 | FDE: 0x0cd240 | Size: 8 bytes
// Hàm FDE #1782 | Địa chỉ PC: 0x0a9758 | Địa chỉ FDE: 0x0cd240 | Kích thước: 8 bytes
//   0x0a9758: F9419400  ldr      x0, [x0, #0x328]
//   0x0a975c: D65F03C0  ret      
static inline uint64_t fde_func_1782_0x0a9758(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a9758ULL ^ (static_cast<uint64_t>(0xf9419400ULL) << 13);
    acc = (acc + a1 + 0xd65f03c0ULL) ^ 0x0cd240ULL;
    acc ^= (acc >> 17) * 0x0008ULL;
    return acc;
}

// FDE #1783 | PC: 0x0a9760 | FDE: 0x0cd258 | Size: 120 bytes
// Hàm FDE #1783 | Địa chỉ PC: 0x0a9760 | Địa chỉ FDE: 0x0cd258 | Kích thước: 120 bytes
//   0x0a9760: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x0a9764: 53001C02  uxtb     w2, w0
//   0x0a9768: AA0103E0  mov      x0, x1
//   0x0a976c: 7103FC5F  cmp      w2, #0xff
static inline uint64_t fde_func_1783_0x0a9760(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a9760ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x53001c02ULL) ^ 0x0cd258ULL;
    acc ^= (acc >> 17) * 0x0078ULL;
    return acc;
}

// FDE #1784 | PC: 0x0a97d8 | FDE: 0x0cd298 | Size: 256 bytes
// Hàm FDE #1784 | Địa chỉ PC: 0x0a97d8 | Địa chỉ FDE: 0x0cd298 | Kích thước: 256 bytes
//   0x0a97d8: A9B77BFD  stp      x29, x30, [sp, #-0x90]!
//   0x0a97dc: 910003FD  mov      x29, sp
//   0x0a97e0: A9025BF5  stp      x21, x22, [sp, #0x20]
//   0x0a97e4: A90363F7  stp      x23, x24, [sp, #0x30]
static inline uint64_t fde_func_1784_0x0a97d8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a97d8ULL ^ (static_cast<uint64_t>(0xa9b77bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x0cd298ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1785 | PC: 0x0a9cd0 | FDE: 0x0cd2e8 | Size: 256 bytes
// Hàm FDE #1785 | Địa chỉ PC: 0x0a9cd0 | Địa chỉ FDE: 0x0cd2e8 | Kích thước: 256 bytes
//   0x0a9cd0: A9B77BFD  stp      x29, x30, [sp, #-0x90]!
//   0x0a9cd4: D280D002  mov      x2, #0x680
//   0x0a9cd8: 910003FD  mov      x29, sp
//   0x0a9cdc: A90153F3  stp      x19, x20, [sp, #0x10]
static inline uint64_t fde_func_1785_0x0a9cd0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0a9cd0ULL ^ (static_cast<uint64_t>(0xa9b77bfdULL) << 13);
    acc = (acc + a1 + 0xd280d002ULL) ^ 0x0cd2e8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1786 | PC: 0x0aa0f4 | FDE: 0x0cd330 | Size: 256 bytes
// Hàm FDE #1786 | Địa chỉ PC: 0x0aa0f4 | Địa chỉ FDE: 0x0cd330 | Kích thước: 256 bytes
//   0x0aa0f4: D108C3FF  sub      sp, sp, #0x230
//   0x0aa0f8: AA0003E4  mov      x4, x0
//   0x0aa0fc: A9BA7BFD  stp      x29, x30, [sp, #-0x60]!
//   0x0aa100: 910003FD  mov      x29, sp
static inline uint64_t fde_func_1786_0x0aa0f4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0aa0f4ULL ^ (static_cast<uint64_t>(0xd108c3ffULL) << 13);
    acc = (acc + a1 + 0xaa0003e4ULL) ^ 0x0cd330ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1787 | PC: 0x0aa6a8 | FDE: 0x0cd388 | Size: 256 bytes
// Hàm FDE #1787 | Địa chỉ PC: 0x0aa6a8 | Địa chỉ FDE: 0x0cd388 | Kích thước: 256 bytes
//   0x0aa6a8: D10F83FF  sub      sp, sp, #0x3e0
//   0x0aa6ac: D2807802  mov      x2, #0x3c0
//   0x0aa6b0: A9BA7BFD  stp      x29, x30, [sp, #-0x60]!
//   0x0aa6b4: 910003FD  mov      x29, sp
static inline uint64_t fde_func_1787_0x0aa6a8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0aa6a8ULL ^ (static_cast<uint64_t>(0xd10f83ffULL) << 13);
    acc = (acc + a1 + 0xd2807802ULL) ^ 0x0cd388ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1788 | PC: 0x0aa8b4 | FDE: 0x0cd3e8 | Size: 220 bytes
// Hàm FDE #1788 | Địa chỉ PC: 0x0aa8b4 | Địa chỉ FDE: 0x0cd3e8 | Kích thước: 220 bytes
//   0x0aa8b4: D11A43FF  sub      sp, sp, #0x690
//   0x0aa8b8: A9BC7BFD  stp      x29, x30, [sp, #-0x40]!
//   0x0aa8bc: 910003FD  mov      x29, sp
//   0x0aa8c0: A90153F3  stp      x19, x20, [sp, #0x10]
static inline uint64_t fde_func_1788_0x0aa8b4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0aa8b4ULL ^ (static_cast<uint64_t>(0xd11a43ffULL) << 13);
    acc = (acc + a1 + 0xa9bc7bfdULL) ^ 0x0cd3e8ULL;
    acc ^= (acc >> 17) * 0x00dcULL;
    return acc;
}

// FDE #1789 | PC: 0x0aa990 | FDE: 0x0cd430 | Size: 76 bytes
// Hàm FDE #1789 | Địa chỉ PC: 0x0aa990 | Địa chỉ FDE: 0x0cd430 | Kích thước: 76 bytes
//   0x0aa990: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x0aa994: 910003FD  mov      x29, sp
//   0x0aa998: A90153F3  stp      x19, x20, [sp, #0x10]
//   0x0aa99c: AA0103F3  mov      x19, x1
static inline uint64_t fde_func_1789_0x0aa990(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0aa990ULL ^ (static_cast<uint64_t>(0xa9be7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x0cd430ULL;
    acc ^= (acc >> 17) * 0x004cULL;
    return acc;
}

// FDE #1790 | PC: 0x0aa9dc | FDE: 0x0cd460 | Size: 192 bytes
// Hàm FDE #1790 | Địa chỉ PC: 0x0aa9dc | Địa chỉ FDE: 0x0cd460 | Kích thước: 192 bytes
//   0x0aa9dc: D11A03FF  sub      sp, sp, #0x680
//   0x0aa9e0: A9BC7BFD  stp      x29, x30, [sp, #-0x40]!
//   0x0aa9e4: 910003FD  mov      x29, sp
//   0x0aa9e8: A90153F3  stp      x19, x20, [sp, #0x10]
static inline uint64_t fde_func_1790_0x0aa9dc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0aa9dcULL ^ (static_cast<uint64_t>(0xd11a03ffULL) << 13);
    acc = (acc + a1 + 0xa9bc7bfdULL) ^ 0x0cd460ULL;
    acc ^= (acc >> 17) * 0x00c0ULL;
    return acc;
}

// FDE #1791 | PC: 0x0aaa9c | FDE: 0x0cd4b0 | Size: 236 bytes
// Hàm FDE #1791 | Địa chỉ PC: 0x0aaa9c | Địa chỉ FDE: 0x0cd4b0 | Kích thước: 236 bytes
//   0x0aaa9c: D11A03FF  sub      sp, sp, #0x680
//   0x0aaaa0: A9BB7BFD  stp      x29, x30, [sp, #-0x50]!
//   0x0aaaa4: 910003FD  mov      x29, sp
//   0x0aaaa8: A90363F7  stp      x23, x24, [sp, #0x30]
static inline uint64_t fde_func_1791_0x0aaa9c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0aaa9cULL ^ (static_cast<uint64_t>(0xd11a03ffULL) << 13);
    acc = (acc + a1 + 0xa9bb7bfdULL) ^ 0x0cd4b0ULL;
    acc ^= (acc >> 17) * 0x00ecULL;
    return acc;
}

// FDE #1792 | PC: 0x0aab88 | FDE: 0x0cd508 | Size: 244 bytes
// Hàm FDE #1792 | Địa chỉ PC: 0x0aab88 | Địa chỉ FDE: 0x0cd508 | Kích thước: 244 bytes
//   0x0aab88: D12903FF  sub      sp, sp, #0xa40
//   0x0aab8c: D2807802  mov      x2, #0x3c0
//   0x0aab90: A9BD7BFD  stp      x29, x30, [sp, #-0x30]!
//   0x0aab94: 910003FD  mov      x29, sp
static inline uint64_t fde_func_1792_0x0aab88(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0aab88ULL ^ (static_cast<uint64_t>(0xd12903ffULL) << 13);
    acc = (acc + a1 + 0xd2807802ULL) ^ 0x0cd508ULL;
    acc ^= (acc >> 17) * 0x00f4ULL;
    return acc;
}

// FDE #1793 | PC: 0x0aac7c | FDE: 0x0cd548 | Size: 4 bytes
// Hàm FDE #1793 | Địa chỉ PC: 0x0aac7c | Địa chỉ FDE: 0x0cd548 | Kích thước: 4 bytes
//   0x0aac7c: D65F03C0  ret      
static inline uint64_t fde_func_1793_0x0aac7c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0aac7cULL ^ (static_cast<uint64_t>(0xd65f03c0ULL) << 13);
    acc = (acc + a1 + 0xd13843ffULL) ^ 0x0cd548ULL;
    acc ^= (acc >> 17) * 0x0004ULL;
    return acc;
}

// FDE #1794 | PC: 0x0aac80 | FDE: 0x0cd560 | Size: 256 bytes
// Hàm FDE #1794 | Địa chỉ PC: 0x0aac80 | Địa chỉ FDE: 0x0cd560 | Kích thước: 256 bytes
//   0x0aac80: D13843FF  sub      sp, sp, #0xe10
//   0x0aac84: A9B47BFD  stp      x29, x30, [sp, #-0xc0]!
//   0x0aac88: 910003FD  mov      x29, sp
//   0x0aac8c: A9045BF5  stp      x21, x22, [sp, #0x40]
static inline uint64_t fde_func_1794_0x0aac80(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0aac80ULL ^ (static_cast<uint64_t>(0xd13843ffULL) << 13);
    acc = (acc + a1 + 0xa9b47bfdULL) ^ 0x0cd560ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1795 | PC: 0x0aadf8 | FDE: 0x0cd608 | Size: 244 bytes
// Hàm FDE #1795 | Địa chỉ PC: 0x0aadf8 | Địa chỉ FDE: 0x0cd608 | Kích thước: 244 bytes
//   0x0aadf8: D11E43FF  sub      sp, sp, #0x790
//   0x0aadfc: A9B47BFD  stp      x29, x30, [sp, #-0xc0]!
//   0x0aae00: 910003FD  mov      x29, sp
//   0x0aae04: A90353F3  stp      x19, x20, [sp, #0x30]
static inline uint64_t fde_func_1795_0x0aadf8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0aadf8ULL ^ (static_cast<uint64_t>(0xd11e43ffULL) << 13);
    acc = (acc + a1 + 0xa9b47bfdULL) ^ 0x0cd608ULL;
    acc ^= (acc >> 17) * 0x00f4ULL;
    return acc;
}

// FDE #1796 | PC: 0x0aaeec | FDE: 0x0cd6b0 | Size: 252 bytes
// Hàm FDE #1796 | Địa chỉ PC: 0x0aaeec | Địa chỉ FDE: 0x0cd6b0 | Kích thước: 252 bytes
//   0x0aaeec: D11E43FF  sub      sp, sp, #0x790
//   0x0aaef0: A9B47BFD  stp      x29, x30, [sp, #-0xc0]!
//   0x0aaef4: 910003FD  mov      x29, sp
//   0x0aaef8: A90353F3  stp      x19, x20, [sp, #0x30]
static inline uint64_t fde_func_1796_0x0aaeec(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0aaeecULL ^ (static_cast<uint64_t>(0xd11e43ffULL) << 13);
    acc = (acc + a1 + 0xa9b47bfdULL) ^ 0x0cd6b0ULL;
    acc ^= (acc >> 17) * 0x00fcULL;
    return acc;
}

// FDE #1797 | PC: 0x0aafe8 | FDE: 0x0cd758 | Size: 248 bytes
// Hàm FDE #1797 | Địa chỉ PC: 0x0aafe8 | Địa chỉ FDE: 0x0cd758 | Kích thước: 248 bytes
//   0x0aafe8: D11E43FF  sub      sp, sp, #0x790
//   0x0aafec: A9B47BFD  stp      x29, x30, [sp, #-0xc0]!
//   0x0aaff0: 910003FD  mov      x29, sp
//   0x0aaff4: 6D0827E8  stp      d8, d9, [sp, #0x80]
static inline uint64_t fde_func_1797_0x0aafe8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0aafe8ULL ^ (static_cast<uint64_t>(0xd11e43ffULL) << 13);
    acc = (acc + a1 + 0xa9b47bfdULL) ^ 0x0cd758ULL;
    acc ^= (acc >> 17) * 0x00f8ULL;
    return acc;
}

// FDE #1798 | PC: 0x0ab0e0 | FDE: 0x0cd800 | Size: 36 bytes
// Hàm FDE #1798 | Địa chỉ PC: 0x0ab0e0 | Địa chỉ FDE: 0x0cd800 | Kích thước: 36 bytes
//   0x0ab0e0: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x0ab0e4: 910003FD  mov      x29, sp
//   0x0ab0e8: F9400402  ldr      x2, [x0, #8]
//   0x0ab0ec: B4000082  cbz      x2, #0xab0fc
static inline uint64_t fde_func_1798_0x0ab0e0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ab0e0ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x0cd800ULL;
    acc ^= (acc >> 17) * 0x0024ULL;
    return acc;
}

// FDE #1799 | PC: 0x0ab104 | FDE: 0x0cd828 | Size: 208 bytes
// Hàm FDE #1799 | Địa chỉ PC: 0x0ab104 | Địa chỉ FDE: 0x0cd828 | Kích thước: 208 bytes
//   0x0ab104: D12903FF  sub      sp, sp, #0xa40
//   0x0ab108: AA1E03E2  mov      x2, x30
//   0x0ab10c: A9B67BFD  stp      x29, x30, [sp, #-0xa0]!
//   0x0ab110: 910003FD  mov      x29, sp
static inline uint64_t fde_func_1799_0x0ab104(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ab104ULL ^ (static_cast<uint64_t>(0xd12903ffULL) << 13);
    acc = (acc + a1 + 0xaa1e03e2ULL) ^ 0x0cd828ULL;
    acc ^= (acc >> 17) * 0x00d0ULL;
    return acc;
}

// FDE #1800 | PC: 0x0ab1d4 | FDE: 0x0cd8c0 | Size: 40 bytes
// Hàm FDE #1800 | Địa chỉ PC: 0x0ab1d4 | Địa chỉ FDE: 0x0cd8c0 | Kích thước: 40 bytes
//   0x0ab1d4: D2800002  mov      x2, #0
//   0x0ab1d8: 52800003  mov      w3, #0
//   0x0ab1dc: 38401405  ldrb     w5, [x0], #1
//   0x0ab1e0: 924018A4  and      x4, x5, #0x7f
static inline uint64_t fde_func_1800_0x0ab1d4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ab1d4ULL ^ (static_cast<uint64_t>(0xd2800002ULL) << 13);
    acc = (acc + a1 + 0x52800003ULL) ^ 0x0cd8c0ULL;
    acc ^= (acc >> 17) * 0x0028ULL;
    return acc;
}

// FDE #1801 | PC: 0x0ab1fc | FDE: 0x0cd8d8 | Size: 64 bytes
// Hàm FDE #1801 | Địa chỉ PC: 0x0ab1fc | Địa chỉ FDE: 0x0cd8d8 | Kích thước: 64 bytes
//   0x0ab1fc: D2800002  mov      x2, #0
//   0x0ab200: 52800003  mov      w3, #0
//   0x0ab204: 38401404  ldrb     w4, [x0], #1
//   0x0ab208: 92401885  and      x5, x4, #0x7f
static inline uint64_t fde_func_1801_0x0ab1fc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ab1fcULL ^ (static_cast<uint64_t>(0xd2800002ULL) << 13);
    acc = (acc + a1 + 0x52800003ULL) ^ 0x0cd8d8ULL;
    acc ^= (acc >> 17) * 0x0040ULL;
    return acc;
}

// FDE #1802 | PC: 0x0ab23c | FDE: 0x0cd8f0 | Size: 28 bytes
// Hàm FDE #1802 | Địa chỉ PC: 0x0ab23c | Địa chỉ FDE: 0x0cd8f0 | Kích thước: 28 bytes
//   0x0ab23c: F9400423  ldr      x3, [x1, #8]
//   0x0ab240: F9400441  ldr      x1, [x2, #8]
//   0x0ab244: EB01007F  cmp      x3, x1
//   0x0ab248: 5A9F23E0  csetm    w0, lo
static inline uint64_t fde_func_1802_0x0ab23c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ab23cULL ^ (static_cast<uint64_t>(0xf9400423ULL) << 13);
    acc = (acc + a1 + 0xf9400441ULL) ^ 0x0cd8f0ULL;
    acc ^= (acc >> 17) * 0x001cULL;
    return acc;
}

// FDE #1803 | PC: 0x0ab258 | FDE: 0x0cd908 | Size: 192 bytes
// Hàm FDE #1803 | Địa chỉ PC: 0x0ab258 | Địa chỉ FDE: 0x0cd908 | Kích thước: 192 bytes
//   0x0ab258: A9BA7BFD  stp      x29, x30, [sp, #-0x60]!
//   0x0ab25c: 910003FD  mov      x29, sp
//   0x0ab260: A90153F3  stp      x19, x20, [sp, #0x10]
//   0x0ab264: 531F7873  lsl      w19, w3, #1
static inline uint64_t fde_func_1803_0x0ab258(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ab258ULL ^ (static_cast<uint64_t>(0xa9ba7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x0cd908ULL;
    acc ^= (acc >> 17) * 0x00c0ULL;
    return acc;
}

// FDE #1804 | PC: 0x0ab318 | FDE: 0x0cd948 | Size: 180 bytes
// Hàm FDE #1804 | Địa chỉ PC: 0x0ab318 | Địa chỉ FDE: 0x0cd948 | Kích thước: 180 bytes
//   0x0ab318: A9BB7BFD  stp      x29, x30, [sp, #-0x50]!
//   0x0ab31c: 910003FD  mov      x29, sp
//   0x0ab320: A90153F3  stp      x19, x20, [sp, #0x10]
//   0x0ab324: F9400453  ldr      x19, [x2, #8]
static inline uint64_t fde_func_1804_0x0ab318(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ab318ULL ^ (static_cast<uint64_t>(0xa9bb7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x0cd948ULL;
    acc ^= (acc >> 17) * 0x00b4ULL;
    return acc;
}

// FDE #1805 | PC: 0x0ab3cc | FDE: 0x0cd988 | Size: 96 bytes
// Hàm FDE #1805 | Địa chỉ PC: 0x0ab3cc | Địa chỉ FDE: 0x0cd988 | Kích thước: 96 bytes
//   0x0ab3cc: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x0ab3d0: 53001C00  uxtb     w0, w0
//   0x0ab3d4: 7103FC1F  cmp      w0, #0xff
//   0x0ab3d8: 910003FD  mov      x29, sp
static inline uint64_t fde_func_1805_0x0ab3cc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ab3ccULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x53001c00ULL) ^ 0x0cd988ULL;
    acc ^= (acc >> 17) * 0x0060ULL;
    return acc;
}

// FDE #1806 | PC: 0x0ab42c | FDE: 0x0cd9b0 | Size: 96 bytes
// Hàm FDE #1806 | Địa chỉ PC: 0x0ab42c | Địa chỉ FDE: 0x0cd9b0 | Kích thước: 96 bytes
//   0x0ab42c: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x0ab430: 53001C00  uxtb     w0, w0
//   0x0ab434: 7103FC1F  cmp      w0, #0xff
//   0x0ab438: 910003FD  mov      x29, sp
static inline uint64_t fde_func_1806_0x0ab42c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ab42cULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x53001c00ULL) ^ 0x0cd9b0ULL;
    acc ^= (acc >> 17) * 0x0060ULL;
    return acc;
}

// FDE #1807 | PC: 0x0ab48c | FDE: 0x0cd9d8 | Size: 96 bytes
// Hàm FDE #1807 | Địa chỉ PC: 0x0ab48c | Địa chỉ FDE: 0x0cd9d8 | Kích thước: 96 bytes
//   0x0ab48c: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x0ab490: 53001C00  uxtb     w0, w0
//   0x0ab494: 7103FC1F  cmp      w0, #0xff
//   0x0ab498: 910003FD  mov      x29, sp
static inline uint64_t fde_func_1807_0x0ab48c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ab48cULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x53001c00ULL) ^ 0x0cd9d8ULL;
    acc ^= (acc >> 17) * 0x0060ULL;
    return acc;
}

// FDE #1808 | PC: 0x0ab4ec | FDE: 0x0cda00 | Size: 240 bytes
// Hàm FDE #1808 | Địa chỉ PC: 0x0ab4ec | Địa chỉ FDE: 0x0cda00 | Kích thước: 240 bytes
//   0x0ab4ec: A9BC7BFD  stp      x29, x30, [sp, #-0x40]!
//   0x0ab4f0: 910003FD  mov      x29, sp
//   0x0ab4f4: A90153F3  stp      x19, x20, [sp, #0x10]
//   0x0ab4f8: 53001C14  uxtb     w20, w0
static inline uint64_t fde_func_1808_0x0ab4ec(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ab4ecULL ^ (static_cast<uint64_t>(0xa9bc7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x0cda00ULL;
    acc ^= (acc >> 17) * 0x00f0ULL;
    return acc;
}

// FDE #1809 | PC: 0x0ab5dc | FDE: 0x0cda38 | Size: 144 bytes
// Hàm FDE #1809 | Địa chỉ PC: 0x0ab5dc | Địa chỉ FDE: 0x0cda38 | Kích thước: 144 bytes
//   0x0ab5dc: A9BB7BFD  stp      x29, x30, [sp, #-0x50]!
//   0x0ab5e0: 910003FD  mov      x29, sp
//   0x0ab5e4: A90153F3  stp      x19, x20, [sp, #0x10]
//   0x0ab5e8: 79404013  ldrh     w19, [x0, #0x20]
static inline uint64_t fde_func_1809_0x0ab5dc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ab5dcULL ^ (static_cast<uint64_t>(0xa9bb7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x0cda38ULL;
    acc ^= (acc >> 17) * 0x0090ULL;
    return acc;
}

// FDE #1810 | PC: 0x0ab66c | FDE: 0x0cda70 | Size: 252 bytes
// Hàm FDE #1810 | Địa chỉ PC: 0x0ab66c | Địa chỉ FDE: 0x0cda70 | Kích thước: 252 bytes
//   0x0ab66c: A9BC7BFD  stp      x29, x30, [sp, #-0x40]!
//   0x0ab670: 910003FD  mov      x29, sp
//   0x0ab674: A90153F3  stp      x19, x20, [sp, #0x10]
//   0x0ab678: 91002414  add      x20, x0, #9
static inline uint64_t fde_func_1810_0x0ab66c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ab66cULL ^ (static_cast<uint64_t>(0xa9bc7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x0cda70ULL;
    acc ^= (acc >> 17) * 0x00fcULL;
    return acc;
}

// FDE #1811 | PC: 0x0ab768 | FDE: 0x0cdaa0 | Size: 256 bytes
// Hàm FDE #1811 | Địa chỉ PC: 0x0ab768 | Địa chỉ FDE: 0x0cdaa0 | Kích thước: 256 bytes
//   0x0ab768: A9B97BFD  stp      x29, x30, [sp, #-0x70]!
//   0x0ab76c: 910003FD  mov      x29, sp
//   0x0ab770: A9025BF5  stp      x21, x22, [sp, #0x20]
//   0x0ab774: AA0003F6  mov      x22, x0
static inline uint64_t fde_func_1811_0x0ab768(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ab768ULL ^ (static_cast<uint64_t>(0xa9b97bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x0cdaa0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1812 | PC: 0x0ab8c8 | FDE: 0x0cdae8 | Size: 16 bytes
// Hàm FDE #1812 | Địa chỉ PC: 0x0ab8c8 | Địa chỉ FDE: 0x0cdae8 | Kích thước: 16 bytes
//   0x0ab8c8: 91001001  add      x1, x0, #4
//   0x0ab8cc: B9800400  ldrsw    x0, [x0, #4]
//   0x0ab8d0: CB000020  sub      x0, x1, x0
//   0x0ab8d4: 17FFFF66  b        #0xab66c
static inline uint64_t fde_func_1812_0x0ab8c8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ab8c8ULL ^ (static_cast<uint64_t>(0x91001001ULL) << 13);
    acc = (acc + a1 + 0xb9800400ULL) ^ 0x0cdae8ULL;
    acc ^= (acc >> 17) * 0x0010ULL;
    return acc;
}

// FDE #1813 | PC: 0x0ab8d8 | FDE: 0x0cdb00 | Size: 256 bytes
// Hàm FDE #1813 | Địa chỉ PC: 0x0ab8d8 | Địa chỉ FDE: 0x0cdb00 | Kích thước: 256 bytes
//   0x0ab8d8: A9B77BFD  stp      x29, x30, [sp, #-0x90]!
//   0x0ab8dc: F100BC3F  cmp      x1, #0x2f
//   0x0ab8e0: 910003FD  mov      x29, sp
//   0x0ab8e4: A90153F3  stp      x19, x20, [sp, #0x10]
static inline uint64_t fde_func_1813_0x0ab8d8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ab8d8ULL ^ (static_cast<uint64_t>(0xa9b77bfdULL) << 13);
    acc = (acc + a1 + 0xf100bc3fULL) ^ 0x0cdb00ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1814 | PC: 0x0abcf4 | FDE: 0x0cdb40 | Size: 156 bytes
// Hàm FDE #1814 | Địa chỉ PC: 0x0abcf4 | Địa chỉ FDE: 0x0cdb40 | Kích thước: 156 bytes
//   0x0abcf4: A9BC7BFD  stp      x29, x30, [sp, #-0x40]!
//   0x0abcf8: 910003FD  mov      x29, sp
//   0x0abcfc: A9025BF5  stp      x21, x22, [sp, #0x20]
//   0x0abd00: AA0003F5  mov      x21, x0
static inline uint64_t fde_func_1814_0x0abcf4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0abcf4ULL ^ (static_cast<uint64_t>(0xa9bc7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x0cdb40ULL;
    acc ^= (acc >> 17) * 0x009cULL;
    return acc;
}

// FDE #1815 | PC: 0x0abd90 | FDE: 0x0cdb78 | Size: 256 bytes
// Hàm FDE #1815 | Địa chỉ PC: 0x0abd90 | Địa chỉ FDE: 0x0cdb78 | Kích thước: 256 bytes
//   0x0abd90: A9B97BFD  stp      x29, x30, [sp, #-0x70]!
//   0x0abd94: 910003FD  mov      x29, sp
//   0x0abd98: A90153F3  stp      x19, x20, [sp, #0x10]
//   0x0abd9c: A90363F7  stp      x23, x24, [sp, #0x30]
static inline uint64_t fde_func_1815_0x0abd90(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0abd90ULL ^ (static_cast<uint64_t>(0xa9b97bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x0cdb78ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1816 | PC: 0x0abef0 | FDE: 0x0cdbc0 | Size: 256 bytes
// Hàm FDE #1816 | Địa chỉ PC: 0x0abef0 | Địa chỉ FDE: 0x0cdbc0 | Kích thước: 256 bytes
//   0x0abef0: A9B97BFD  stp      x29, x30, [sp, #-0x70]!
//   0x0abef4: 910003FD  mov      x29, sp
//   0x0abef8: A9025BF5  stp      x21, x22, [sp, #0x20]
//   0x0abefc: AA0003F6  mov      x22, x0
static inline uint64_t fde_func_1816_0x0abef0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0abef0ULL ^ (static_cast<uint64_t>(0xa9b97bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x0cdbc0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1817 | PC: 0x0ac024 | FDE: 0x0cdc08 | Size: 256 bytes
// Hàm FDE #1817 | Địa chỉ PC: 0x0ac024 | Địa chỉ FDE: 0x0cdc08 | Kích thước: 256 bytes
//   0x0ac024: A9B77BFD  stp      x29, x30, [sp, #-0x90]!
//   0x0ac028: 910003FD  mov      x29, sp
//   0x0ac02c: A9025BF5  stp      x21, x22, [sp, #0x20]
//   0x0ac030: AA0103F6  mov      x22, x1
static inline uint64_t fde_func_1817_0x0ac024(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ac024ULL ^ (static_cast<uint64_t>(0xa9b77bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x0cdc08ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1818 | PC: 0x0ac594 | FDE: 0x0cdc58 | Size: 156 bytes
// Hàm FDE #1818 | Địa chỉ PC: 0x0ac594 | Địa chỉ FDE: 0x0cdc58 | Kích thước: 156 bytes
//   0x0ac594: A9BD7BFD  stp      x29, x30, [sp, #-0x30]!
//   0x0ac598: 910003FD  mov      x29, sp
//   0x0ac59c: A90153F3  stp      x19, x20, [sp, #0x10]
//   0x0ac5a0: F90013F5  str      x21, [sp, #0x20]
static inline uint64_t fde_func_1818_0x0ac594(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ac594ULL ^ (static_cast<uint64_t>(0xa9bd7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x0cdc58ULL;
    acc ^= (acc >> 17) * 0x009cULL;
    return acc;
}

// FDE #1819 | PC: 0x0ac630 | FDE: 0x0cdc98 | Size: 12 bytes
// Hàm FDE #1819 | Địa chỉ PC: 0x0ac630 | Địa chỉ FDE: 0x0cdc98 | Kích thước: 12 bytes
//   0x0ac630: D2800002  mov      x2, #0
//   0x0ac634: D2800003  mov      x3, #0
//   0x0ac638: 17FFFFD7  b        #0xac594
static inline uint64_t fde_func_1819_0x0ac630(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ac630ULL ^ (static_cast<uint64_t>(0xd2800002ULL) << 13);
    acc = (acc + a1 + 0xd2800003ULL) ^ 0x0cdc98ULL;
    acc ^= (acc >> 17) * 0x000cULL;
    return acc;
}

// FDE #1820 | PC: 0x0ac63c | FDE: 0x0cdcb0 | Size: 64 bytes
// Hàm FDE #1820 | Địa chỉ PC: 0x0ac63c | Địa chỉ FDE: 0x0cdcb0 | Kích thước: 64 bytes
//   0x0ac63c: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x0ac640: 910003FD  mov      x29, sp
//   0x0ac644: B9400001  ldr      w1, [x0]
//   0x0ac648: F9000BF3  str      x19, [sp, #0x10]
static inline uint64_t fde_func_1820_0x0ac63c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ac63cULL ^ (static_cast<uint64_t>(0xa9be7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x0cdcb0ULL;
    acc ^= (acc >> 17) * 0x0040ULL;
    return acc;
}

// FDE #1821 | PC: 0x0ac67c | FDE: 0x0cdce8 | Size: 148 bytes
// Hàm FDE #1821 | Địa chỉ PC: 0x0ac67c | Địa chỉ FDE: 0x0cdce8 | Kích thước: 148 bytes
//   0x0ac67c: A9BD7BFD  stp      x29, x30, [sp, #-0x30]!
//   0x0ac680: 92800004  mov      x4, #-1
//   0x0ac684: 910003FD  mov      x29, sp
//   0x0ac688: A90153F3  stp      x19, x20, [sp, #0x10]
static inline uint64_t fde_func_1821_0x0ac67c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ac67cULL ^ (static_cast<uint64_t>(0xa9bd7bfdULL) << 13);
    acc = (acc + a1 + 0x92800004ULL) ^ 0x0cdce8ULL;
    acc ^= (acc >> 17) * 0x0094ULL;
    return acc;
}

// FDE #1822 | PC: 0x0ac710 | FDE: 0x0cdd20 | Size: 12 bytes
// Hàm FDE #1822 | Địa chỉ PC: 0x0ac710 | Địa chỉ FDE: 0x0cdd20 | Kích thước: 12 bytes
//   0x0ac710: D2800002  mov      x2, #0
//   0x0ac714: D2800003  mov      x3, #0
//   0x0ac718: 17FFFFD9  b        #0xac67c
static inline uint64_t fde_func_1822_0x0ac710(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ac710ULL ^ (static_cast<uint64_t>(0xd2800002ULL) << 13);
    acc = (acc + a1 + 0xd2800003ULL) ^ 0x0cdd20ULL;
    acc ^= (acc >> 17) * 0x000cULL;
    return acc;
}

// FDE #1823 | PC: 0x0ac71c | FDE: 0x0cdd38 | Size: 44 bytes
// Hàm FDE #1823 | Địa chỉ PC: 0x0ac71c | Địa chỉ FDE: 0x0cdd38 | Kích thước: 44 bytes
//   0x0ac71c: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x0ac720: 910003FD  mov      x29, sp
//   0x0ac724: F9000BF3  str      x19, [sp, #0x10]
//   0x0ac728: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_1823_0x0ac71c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ac71cULL ^ (static_cast<uint64_t>(0xa9be7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x0cdd38ULL;
    acc ^= (acc >> 17) * 0x002cULL;
    return acc;
}

// FDE #1824 | PC: 0x0ac748 | FDE: 0x0cdd60 | Size: 256 bytes
// Hàm FDE #1824 | Địa chỉ PC: 0x0ac748 | Địa chỉ FDE: 0x0cdd60 | Kích thước: 256 bytes
//   0x0ac748: A9BD7BFD  stp      x29, x30, [sp, #-0x30]!
//   0x0ac74c: 910003FD  mov      x29, sp
//   0x0ac750: A90153F3  stp      x19, x20, [sp, #0x10]
//   0x0ac754: A9025BF5  stp      x21, x22, [sp, #0x20]
static inline uint64_t fde_func_1824_0x0ac748(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ac748ULL ^ (static_cast<uint64_t>(0xa9bd7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x0cdd60ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1825 | PC: 0x0ac848 | FDE: 0x0cdd90 | Size: 4 bytes
// Hàm FDE #1825 | Địa chỉ PC: 0x0ac848 | Địa chỉ FDE: 0x0cdd90 | Kích thước: 4 bytes
//   0x0ac848: 17FFFFC0  b        #0xac748
static inline uint64_t fde_func_1825_0x0ac848(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ac848ULL ^ (static_cast<uint64_t>(0x17ffffc0ULL) << 13);
    acc = (acc + a1 + 0xa9bf7bfdULL) ^ 0x0cdd90ULL;
    acc ^= (acc >> 17) * 0x0004ULL;
    return acc;
}

// FDE #1826 | PC: 0x0ac84c | FDE: 0x0cdda8 | Size: 36 bytes
// Hàm FDE #1826 | Địa chỉ PC: 0x0ac84c | Địa chỉ FDE: 0x0cdda8 | Kích thước: 36 bytes
//   0x0ac84c: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x0ac850: 910003FD  mov      x29, sp
//   0x0ac854: B9400001  ldr      w1, [x0]
//   0x0ac858: 34000081  cbz      w1, #0xac868
static inline uint64_t fde_func_1826_0x0ac84c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ac84cULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x0cdda8ULL;
    acc ^= (acc >> 17) * 0x0024ULL;
    return acc;
}

// FDE #1827 | PC: 0x0ac870 | FDE: 0x0cddd8 | Size: 256 bytes
// Hàm FDE #1827 | Địa chỉ PC: 0x0ac870 | Địa chỉ FDE: 0x0cddd8 | Kích thước: 256 bytes
//   0x0ac870: A9B87BFD  stp      x29, x30, [sp, #-0x80]!
//   0x0ac874: 910003FD  mov      x29, sp
//   0x0ac878: A9025BF5  stp      x21, x22, [sp, #0x20]
//   0x0ac87c: F00001F5  adrp     x21, #0xeb000
static inline uint64_t fde_func_1827_0x0ac870(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ac870ULL ^ (static_cast<uint64_t>(0xa9b87bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x0cddd8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1828 | PC: 0x0aca34 | FDE: 0x0cde18 | Size: 64 bytes
// Hàm FDE #1828 | Địa chỉ PC: 0x0aca34 | Địa chỉ FDE: 0x0cde18 | Kích thước: 64 bytes
//   0x0aca34: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x0aca38: 90000001  adrp     x1, #0xac000
//   0x0aca3c: 910003FD  mov      x29, sp
//   0x0aca40: F9000BF3  str      x19, [sp, #0x10]
static inline uint64_t fde_func_1828_0x0aca34(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0aca34ULL ^ (static_cast<uint64_t>(0xa9be7bfdULL) << 13);
    acc = (acc + a1 + 0x90000001ULL) ^ 0x0cde18ULL;
    acc ^= (acc >> 17) * 0x0040ULL;
    return acc;
}

// FDE #1829 | PC: 0x0aca74 | FDE: 0x0cde40 | Size: 128 bytes
// Hàm FDE #1829 | Địa chỉ PC: 0x0aca74 | Địa chỉ FDE: 0x0cde40 | Kích thước: 128 bytes
//   0x0aca74: A9BD7BFD  stp      x29, x30, [sp, #-0x30]!
//   0x0aca78: AA0003E1  mov      x1, x0
//   0x0aca7c: 910003FD  mov      x29, sp
//   0x0aca80: F9400000  ldr      x0, [x0]
static inline uint64_t fde_func_1829_0x0aca74(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0aca74ULL ^ (static_cast<uint64_t>(0xa9bd7bfdULL) << 13);
    acc = (acc + a1 + 0xaa0003e1ULL) ^ 0x0cde40ULL;
    acc ^= (acc >> 17) * 0x0080ULL;
    return acc;
}

// FDE #1830 | PC: 0x0acaf4 | FDE: 0x0cde80 | Size: 152 bytes
// Hàm FDE #1830 | Địa chỉ PC: 0x0acaf4 | Địa chỉ FDE: 0x0cde80 | Kích thước: 152 bytes
//   0x0acaf4: A9BD7BFD  stp      x29, x30, [sp, #-0x30]!
//   0x0acaf8: 910003FD  mov      x29, sp
//   0x0acafc: A90153F3  stp      x19, x20, [sp, #0x10]
//   0x0acb00: F9400414  ldr      x20, [x0, #8]
static inline uint64_t fde_func_1830_0x0acaf4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0acaf4ULL ^ (static_cast<uint64_t>(0xa9bd7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x0cde80ULL;
    acc ^= (acc >> 17) * 0x0098ULL;
    return acc;
}

// FDE #1831 | PC: 0x0acb8c | FDE: 0x0cdeb0 | Size: 32 bytes
// Hàm FDE #1831 | Địa chỉ PC: 0x0acb8c | Địa chỉ FDE: 0x0cdeb0 | Kích thước: 32 bytes
//   0x0acb8c: B0000200  adrp     x0, #0xed000
//   0x0acb90: 91024001  add      x1, x0, #0x90
//   0x0acb94: B9400422  ldr      w2, [x1, #4]
//   0x0acb98: 34000082  cbz      w2, #0xacba8
static inline uint64_t fde_func_1831_0x0acb8c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0acb8cULL ^ (static_cast<uint64_t>(0xb0000200ULL) << 13);
    acc = (acc + a1 + 0x91024001ULL) ^ 0x0cdeb0ULL;
    acc ^= (acc >> 17) * 0x0020ULL;
    return acc;
}

// FDE #1832 | PC: 0x0acbac | FDE: 0x0cdec8 | Size: 256 bytes
// Hàm FDE #1832 | Địa chỉ PC: 0x0acbac | Địa chỉ FDE: 0x0cdec8 | Kích thước: 256 bytes
//   0x0acbac: F00001E1  adrp     x1, #0xeb000
//   0x0acbb0: A9BC7BFD  stp      x29, x30, [sp, #-0x40]!
//   0x0acbb4: 910003FD  mov      x29, sp
//   0x0acbb8: F9479421  ldr      x1, [x1, #0xf28]
static inline uint64_t fde_func_1832_0x0acbac(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0acbacULL ^ (static_cast<uint64_t>(0xf00001e1ULL) << 13);
    acc = (acc + a1 + 0xa9bc7bfdULL) ^ 0x0cdec8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1833 | PC: 0x0acd04 | FDE: 0x0cdf00 | Size: 60 bytes
// Hàm FDE #1833 | Địa chỉ PC: 0x0acd04 | Địa chỉ FDE: 0x0cdf00 | Kích thước: 60 bytes
//   0x0acd04: F9400004  ldr      x4, [x0]
//   0x0acd08: EB01009F  cmp      x4, x1
//   0x0acd0c: 54000062  b.hs     #0xacd18
//   0x0acd10: F9000001  str      x1, [x0]
static inline uint64_t fde_func_1833_0x0acd04(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0acd04ULL ^ (static_cast<uint64_t>(0xf9400004ULL) << 13);
    acc = (acc + a1 + 0xeb01009fULL) ^ 0x0cdf00ULL;
    acc ^= (acc >> 17) * 0x003cULL;
    return acc;
}

// FDE #1834 | PC: 0x0acd40 | FDE: 0x0cdf18 | Size: 108 bytes
// Hàm FDE #1834 | Địa chỉ PC: 0x0acd40 | Địa chỉ FDE: 0x0cdf18 | Kích thước: 108 bytes
//   0x0acd40: 36000080  tbz      w0, #0, #0xacd50
//   0x0acd44: 1E2703E1  fmov     s1, wzr
//   0x0acd48: 1E211820  fdiv     s0, s1, s1
//   0x0acd4c: D53B4421  mrs      x1, fpsr
static inline uint64_t fde_func_1834_0x0acd40(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0acd40ULL ^ (static_cast<uint64_t>(0x36000080ULL) << 13);
    acc = (acc + a1 + 0x1e2703e1ULL) ^ 0x0cdf18ULL;
    acc ^= (acc >> 17) * 0x006cULL;
    return acc;
}

// Shard 5 Dispatcher / Bộ điều phối phân mảnh 5
uint64_t execute_fde_shard_5(uint32_t fde_idx, uint64_t a0, uint64_t a1) {
    switch (fde_idx) {
        case 1468: return fde_func_1468_0x096414(a0, a1);
        case 1469: return fde_func_1469_0x096518(a0, a1);
        case 1470: return fde_func_1470_0x096590(a0, a1);
        case 1471: return fde_func_1471_0x0965e0(a0, a1);
        case 1472: return fde_func_1472_0x0966b8(a0, a1);
        case 1473: return fde_func_1473_0x096700(a0, a1);
        case 1474: return fde_func_1474_0x096758(a0, a1);
        case 1475: return fde_func_1475_0x096764(a0, a1);
        case 1476: return fde_func_1476_0x096768(a0, a1);
        case 1477: return fde_func_1477_0x096798(a0, a1);
        case 1478: return fde_func_1478_0x096894(a0, a1);
        case 1479: return fde_func_1479_0x0969b8(a0, a1);
        case 1480: return fde_func_1480_0x096a0c(a0, a1);
        case 1481: return fde_func_1481_0x096a78(a0, a1);
        case 1482: return fde_func_1482_0x096ab4(a0, a1);
        case 1483: return fde_func_1483_0x096c34(a0, a1);
        case 1484: return fde_func_1484_0x096d00(a0, a1);
        case 1485: return fde_func_1485_0x096d30(a0, a1);
        case 1486: return fde_func_1486_0x096d68(a0, a1);
        case 1487: return fde_func_1487_0x096d70(a0, a1);
        case 1488: return fde_func_1488_0x096d74(a0, a1);
        case 1489: return fde_func_1489_0x096dcc(a0, a1);
        case 1490: return fde_func_1490_0x096dd8(a0, a1);
        case 1491: return fde_func_1491_0x096ddc(a0, a1);
        case 1492: return fde_func_1492_0x096e0c(a0, a1);
        case 1493: return fde_func_1493_0x096edc(a0, a1);
        case 1494: return fde_func_1494_0x096f8c(a0, a1);
        case 1495: return fde_func_1495_0x096fbc(a0, a1);
        case 1496: return fde_func_1496_0x097080(a0, a1);
        case 1497: return fde_func_1497_0x097088(a0, a1);
        case 1498: return fde_func_1498_0x097170(a0, a1);
        case 1499: return fde_func_1499_0x097198(a0, a1);
        case 1500: return fde_func_1500_0x0972a8(a0, a1);
        case 1501: return fde_func_1501_0x0973fc(a0, a1);
        case 1502: return fde_func_1502_0x09742c(a0, a1);
        case 1503: return fde_func_1503_0x097528(a0, a1);
        case 1504: return fde_func_1504_0x097604(a0, a1);
        case 1505: return fde_func_1505_0x097814(a0, a1);
        case 1506: return fde_func_1506_0x097930(a0, a1);
        case 1507: return fde_func_1507_0x097a40(a0, a1);
        case 1508: return fde_func_1508_0x097b48(a0, a1);
        case 1509: return fde_func_1509_0x097b5c(a0, a1);
        case 1510: return fde_func_1510_0x097dc4(a0, a1);
        case 1511: return fde_func_1511_0x09830c(a0, a1);
        case 1512: return fde_func_1512_0x098544(a0, a1);
        case 1513: return fde_func_1513_0x0985b4(a0, a1);
        case 1514: return fde_func_1514_0x0985fc(a0, a1);
        case 1515: return fde_func_1515_0x0986a4(a0, a1);
        case 1516: return fde_func_1516_0x0986b8(a0, a1);
        case 1517: return fde_func_1517_0x098798(a0, a1);
        case 1518: return fde_func_1518_0x0988a0(a0, a1);
        case 1519: return fde_func_1519_0x098910(a0, a1);
        case 1520: return fde_func_1520_0x098958(a0, a1);
        case 1521: return fde_func_1521_0x098964(a0, a1);
        case 1522: return fde_func_1522_0x098968(a0, a1);
        case 1523: return fde_func_1523_0x098998(a0, a1);
        case 1524: return fde_func_1524_0x098a94(a0, a1);
        case 1525: return fde_func_1525_0x098c08(a0, a1);
        case 1526: return fde_func_1526_0x098c74(a0, a1);
        case 1527: return fde_func_1527_0x098cb0(a0, a1);
        case 1528: return fde_func_1528_0x098d08(a0, a1);
        case 1529: return fde_func_1529_0x098db0(a0, a1);
        case 1530: return fde_func_1530_0x098dc4(a0, a1);
        case 1531: return fde_func_1531_0x098ea4(a0, a1);
        case 1532: return fde_func_1532_0x098fa0(a0, a1);
        case 1533: return fde_func_1533_0x099010(a0, a1);
        case 1534: return fde_func_1534_0x099058(a0, a1);
        case 1535: return fde_func_1535_0x099100(a0, a1);
        case 1536: return fde_func_1536_0x099114(a0, a1);
        case 1537: return fde_func_1537_0x099240(a0, a1);
        case 1538: return fde_func_1538_0x099368(a0, a1);
        case 1539: return fde_func_1539_0x0993d8(a0, a1);
        case 1540: return fde_func_1540_0x099420(a0, a1);
        case 1541: return fde_func_1541_0x0994c8(a0, a1);
        case 1542: return fde_func_1542_0x0994dc(a0, a1);
        case 1543: return fde_func_1543_0x099608(a0, a1);
        case 1544: return fde_func_1544_0x09974c(a0, a1);
        case 1545: return fde_func_1545_0x099878(a0, a1);
        case 1546: return fde_func_1546_0x099a14(a0, a1);
        case 1547: return fde_func_1547_0x099a84(a0, a1);
        case 1548: return fde_func_1548_0x099acc(a0, a1);
        case 1549: return fde_func_1549_0x099ba0(a0, a1);
        case 1550: return fde_func_1550_0x099be8(a0, a1);
        case 1551: return fde_func_1551_0x099c98(a0, a1);
        case 1552: return fde_func_1552_0x099d90(a0, a1);
        case 1553: return fde_func_1553_0x099e2c(a0, a1);
        case 1554: return fde_func_1554_0x099eb4(a0, a1);
        case 1555: return fde_func_1555_0x099ec8(a0, a1);
        case 1556: return fde_func_1556_0x099fa0(a0, a1);
        case 1557: return fde_func_1557_0x09a0d4(a0, a1);
        case 1558: return fde_func_1558_0x09a1a0(a0, a1);
        case 1559: return fde_func_1559_0x09a3e0(a0, a1);
        case 1560: return fde_func_1560_0x09a4b4(a0, a1);
        case 1561: return fde_func_1561_0x09a4fc(a0, a1);
        case 1562: return fde_func_1562_0x09a668(a0, a1);
        case 1563: return fde_func_1563_0x09a674(a0, a1);
        case 1564: return fde_func_1564_0x09a678(a0, a1);
        case 1565: return fde_func_1565_0x09a6a8(a0, a1);
        case 1566: return fde_func_1566_0x09a7a4(a0, a1);
        case 1567: return fde_func_1567_0x09a91c(a0, a1);
        case 1568: return fde_func_1568_0x09a974(a0, a1);
        case 1569: return fde_func_1569_0x09aaac(a0, a1);
        case 1570: return fde_func_1570_0x09ac68(a0, a1);
        case 1571: return fde_func_1571_0x09adc4(a0, a1);
        case 1572: return fde_func_1572_0x09ae20(a0, a1);
        case 1573: return fde_func_1573_0x09af58(a0, a1);
        case 1574: return fde_func_1574_0x09afc4(a0, a1);
        case 1575: return fde_func_1575_0x09b000(a0, a1);
        case 1576: return fde_func_1576_0x09b064(a0, a1);
        case 1577: return fde_func_1577_0x09b0a0(a0, a1);
        case 1578: return fde_func_1578_0x09b1bc(a0, a1);
        case 1579: return fde_func_1579_0x09b2cc(a0, a1);
        case 1580: return fde_func_1580_0x09b44c(a0, a1);
        case 1581: return fde_func_1581_0x09b518(a0, a1);
        case 1582: return fde_func_1582_0x09b548(a0, a1);
        case 1583: return fde_func_1583_0x09b580(a0, a1);
        case 1584: return fde_func_1584_0x09b588(a0, a1);
        case 1585: return fde_func_1585_0x09b58c(a0, a1);
        case 1586: return fde_func_1586_0x09b70c(a0, a1);
        case 1587: return fde_func_1587_0x09b7d8(a0, a1);
        case 1588: return fde_func_1588_0x09b808(a0, a1);
        case 1589: return fde_func_1589_0x09b840(a0, a1);
        case 1590: return fde_func_1590_0x09b848(a0, a1);
        case 1591: return fde_func_1591_0x09b84c(a0, a1);
        case 1592: return fde_func_1592_0x09b95c(a0, a1);
        case 1593: return fde_func_1593_0x09b98c(a0, a1);
        case 1594: return fde_func_1594_0x09ba50(a0, a1);
        case 1595: return fde_func_1595_0x09ba58(a0, a1);
        case 1596: return fde_func_1596_0x09bb40(a0, a1);
        case 1597: return fde_func_1597_0x09bb68(a0, a1);
        case 1598: return fde_func_1598_0x09bc70(a0, a1);
        case 1599: return fde_func_1599_0x09bd78(a0, a1);
        case 1600: return fde_func_1600_0x09bec4(a0, a1);
        case 1601: return fde_func_1601_0x09bfc4(a0, a1);
        case 1602: return fde_func_1602_0x09c0cc(a0, a1);
        case 1603: return fde_func_1603_0x09c0fc(a0, a1);
        case 1604: return fde_func_1604_0x09c1f8(a0, a1);
        case 1605: return fde_func_1605_0x09c2d0(a0, a1);
        case 1606: return fde_func_1606_0x09c3a8(a0, a1);
        case 1607: return fde_func_1607_0x09c4c4(a0, a1);
        case 1608: return fde_func_1608_0x09c594(a0, a1);
        case 1609: return fde_func_1609_0x09c718(a0, a1);
        case 1610: return fde_func_1610_0x09c840(a0, a1);
        case 1611: return fde_func_1611_0x09c854(a0, a1);
        case 1612: return fde_func_1612_0x09cb9c(a0, a1);
        case 1613: return fde_func_1613_0x09cf2c(a0, a1);
        case 1614: return fde_func_1614_0x09cf9c(a0, a1);
        case 1615: return fde_func_1615_0x09cfe4(a0, a1);
        case 1616: return fde_func_1616_0x09d10c(a0, a1);
        case 1617: return fde_func_1617_0x09d120(a0, a1);
        case 1618: return fde_func_1618_0x09d36c(a0, a1);
        case 1619: return fde_func_1619_0x09d670(a0, a1);
        case 1620: return fde_func_1620_0x09d748(a0, a1);
        case 1621: return fde_func_1621_0x09d790(a0, a1);
        case 1622: return fde_func_1622_0x09d800(a0, a1);
        case 1623: return fde_func_1623_0x09d848(a0, a1);
        case 1624: return fde_func_1624_0x09d930(a0, a1);
        case 1625: return fde_func_1625_0x09d944(a0, a1);
        case 1626: return fde_func_1626_0x09dae4(a0, a1);
        case 1627: return fde_func_1627_0x09dd1c(a0, a1);
        case 1628: return fde_func_1628_0x09dd8c(a0, a1);
        case 1629: return fde_func_1629_0x09ddd4(a0, a1);
        case 1630: return fde_func_1630_0x09defc(a0, a1);
        case 1631: return fde_func_1631_0x09df10(a0, a1);
        case 1632: return fde_func_1632_0x09e1ac(a0, a1);
        case 1633: return fde_func_1633_0x09e578(a0, a1);
        case 1634: return fde_func_1634_0x09e650(a0, a1);
        case 1635: return fde_func_1635_0x09e698(a0, a1);
        case 1636: return fde_func_1636_0x09e708(a0, a1);
        case 1637: return fde_func_1637_0x09e750(a0, a1);
        case 1638: return fde_func_1638_0x09e878(a0, a1);
        case 1639: return fde_func_1639_0x09e88c(a0, a1);
        case 1640: return fde_func_1640_0x09eabc(a0, a1);
        case 1641: return fde_func_1641_0x09ed78(a0, a1);
        case 1642: return fde_func_1642_0x09ee50(a0, a1);
        case 1643: return fde_func_1643_0x09ee98(a0, a1);
        case 1644: return fde_func_1644_0x09ef08(a0, a1);
        case 1645: return fde_func_1645_0x09ef50(a0, a1);
        case 1646: return fde_func_1646_0x09f058(a0, a1);
        case 1647: return fde_func_1647_0x09f06c(a0, a1);
        case 1648: return fde_func_1648_0x09f250(a0, a1);
        case 1649: return fde_func_1649_0x09f384(a0, a1);
        case 1650: return fde_func_1650_0x09f61c(a0, a1);
        case 1651: return fde_func_1651_0x09f914(a0, a1);
        case 1652: return fde_func_1652_0x09f984(a0, a1);
        case 1653: return fde_func_1653_0x09f9cc(a0, a1);
        case 1654: return fde_func_1654_0x09fc60(a0, a1);
        case 1655: return fde_func_1655_0x09fe28(a0, a1);
        case 1656: return fde_func_1656_0x09fe3c(a0, a1);
        case 1657: return fde_func_1657_0x0a0264(a0, a1);
        case 1658: return fde_func_1658_0x0a0a0c(a0, a1);
        case 1659: return fde_func_1659_0x0a0cf4(a0, a1);
        case 1660: return fde_func_1660_0x0a0d64(a0, a1);
        case 1661: return fde_func_1661_0x0a0dac(a0, a1);
        case 1662: return fde_func_1662_0x0a0fd0(a0, a1);
        case 1663: return fde_func_1663_0x0a10c0(a0, a1);
        case 1664: return fde_func_1664_0x0a10e8(a0, a1);
        case 1665: return fde_func_1665_0x0a1248(a0, a1);
        case 1666: return fde_func_1666_0x0a1274(a0, a1);
        case 1667: return fde_func_1667_0x0a13e4(a0, a1);
        case 1668: return fde_func_1668_0x0a142c(a0, a1);
        case 1669: return fde_func_1669_0x0a14e8(a0, a1);
        case 1670: return fde_func_1670_0x0a1538(a0, a1);
        case 1671: return fde_func_1671_0x0a15e0(a0, a1);
        case 1672: return fde_func_1672_0x0a16f4(a0, a1);
        case 1673: return fde_func_1673_0x0a17d0(a0, a1);
        case 1674: return fde_func_1674_0x0a1818(a0, a1);
        case 1675: return fde_func_1675_0x0a184c(a0, a1);
        case 1676: return fde_func_1676_0x0a188c(a0, a1);
        case 1677: return fde_func_1677_0x0a1988(a0, a1);
        case 1678: return fde_func_1678_0x0a19d8(a0, a1);
        case 1679: return fde_func_1679_0x0a1a44(a0, a1);
        case 1680: return fde_func_1680_0x0a1ad0(a0, a1);
        case 1681: return fde_func_1681_0x0a1b34(a0, a1);
        case 1682: return fde_func_1682_0x0a1c2c(a0, a1);
        case 1683: return fde_func_1683_0x0a1d90(a0, a1);
        case 1684: return fde_func_1684_0x0a1eec(a0, a1);
        case 1685: return fde_func_1685_0x0a2130(a0, a1);
        case 1686: return fde_func_1686_0x0a2148(a0, a1);
        case 1687: return fde_func_1687_0x0a223c(a0, a1);
        case 1688: return fde_func_1688_0x0a2248(a0, a1);
        case 1689: return fde_func_1689_0x0a2270(a0, a1);
        case 1690: return fde_func_1690_0x0a230c(a0, a1);
        case 1691: return fde_func_1691_0x0a241c(a0, a1);
        case 1692: return fde_func_1692_0x0a2448(a0, a1);
        case 1693: return fde_func_1693_0x0a24b0(a0, a1);
        case 1694: return fde_func_1694_0x0a250c(a0, a1);
        case 1695: return fde_func_1695_0x0a2560(a0, a1);
        case 1696: return fde_func_1696_0x0a261c(a0, a1);
        case 1697: return fde_func_1697_0x0a26b8(a0, a1);
        case 1698: return fde_func_1698_0x0a277c(a0, a1);
        case 1699: return fde_func_1699_0x0a2818(a0, a1);
        case 1700: return fde_func_1700_0x0a2adc(a0, a1);
        case 1701: return fde_func_1701_0x0a2e18(a0, a1);
        case 1702: return fde_func_1702_0x0a3154(a0, a1);
        case 1703: return fde_func_1703_0x0a3490(a0, a1);
        case 1704: return fde_func_1704_0x0a3650(a0, a1);
        case 1705: return fde_func_1705_0x0a3770(a0, a1);
        case 1706: return fde_func_1706_0x0a393c(a0, a1);
        case 1707: return fde_func_1707_0x0a3b8c(a0, a1);
        case 1708: return fde_func_1708_0x0a3e68(a0, a1);
        case 1709: return fde_func_1709_0x0a4054(a0, a1);
        case 1710: return fde_func_1710_0x0a4150(a0, a1);
        case 1711: return fde_func_1711_0x0a422c(a0, a1);
        case 1712: return fde_func_1712_0x0a425c(a0, a1);
        case 1713: return fde_func_1713_0x0a4268(a0, a1);
        case 1714: return fde_func_1714_0x0a4768(a0, a1);
        case 1715: return fde_func_1715_0x0a496c(a0, a1);
        case 1716: return fde_func_1716_0x0a4ad0(a0, a1);
        case 1717: return fde_func_1717_0x0a4d6c(a0, a1);
        case 1718: return fde_func_1718_0x0a52dc(a0, a1);
        case 1719: return fde_func_1719_0x0a5448(a0, a1);
        case 1720: return fde_func_1720_0x0a55dc(a0, a1);
        case 1721: return fde_func_1721_0x0a5764(a0, a1);
        case 1722: return fde_func_1722_0x0a577c(a0, a1);
        case 1723: return fde_func_1723_0x0a5840(a0, a1);
        case 1724: return fde_func_1724_0x0a593c(a0, a1);
        case 1725: return fde_func_1725_0x0a5948(a0, a1);
        case 1726: return fde_func_1726_0x0a59e8(a0, a1);
        case 1727: return fde_func_1727_0x0a5af8(a0, a1);
        case 1728: return fde_func_1728_0x0a5b00(a0, a1);
        case 1729: return fde_func_1729_0x0a5b50(a0, a1);
        case 1730: return fde_func_1730_0x0a5b58(a0, a1);
        case 1731: return fde_func_1731_0x0a5c1c(a0, a1);
        case 1732: return fde_func_1732_0x0a5e54(a0, a1);
        case 1733: return fde_func_1733_0x0a610c(a0, a1);
        case 1734: return fde_func_1734_0x0a62a8(a0, a1);
        case 1735: return fde_func_1735_0x0a63dc(a0, a1);
        case 1736: return fde_func_1736_0x0a65f4(a0, a1);
        case 1737: return fde_func_1737_0x0a66b0(a0, a1);
        case 1738: return fde_func_1738_0x0a67c8(a0, a1);
        case 1739: return fde_func_1739_0x0a6914(a0, a1);
        case 1740: return fde_func_1740_0x0a6ba8(a0, a1);
        case 1741: return fde_func_1741_0x0a6c8c(a0, a1);
        case 1742: return fde_func_1742_0x0a6e7c(a0, a1);
        case 1743: return fde_func_1743_0x0a6ea0(a0, a1);
        case 1744: return fde_func_1744_0x0a6f24(a0, a1);
        case 1745: return fde_func_1745_0x0a6f40(a0, a1);
        case 1746: return fde_func_1746_0x0a6f44(a0, a1);
        case 1747: return fde_func_1747_0x0a7044(a0, a1);
        case 1748: return fde_func_1748_0x0a7100(a0, a1);
        case 1749: return fde_func_1749_0x0a720c(a0, a1);
        case 1750: return fde_func_1750_0x0a7388(a0, a1);
        case 1751: return fde_func_1751_0x0a74d4(a0, a1);
        case 1752: return fde_func_1752_0x0a7598(a0, a1);
        case 1753: return fde_func_1753_0x0a7848(a0, a1);
        case 1754: return fde_func_1754_0x0a79b0(a0, a1);
        case 1755: return fde_func_1755_0x0a7a94(a0, a1);
        case 1756: return fde_func_1756_0x0a7bbc(a0, a1);
        case 1757: return fde_func_1757_0x0a7d5c(a0, a1);
        case 1758: return fde_func_1758_0x0a7d80(a0, a1);
        case 1759: return fde_func_1759_0x0a7dc0(a0, a1);
        case 1760: return fde_func_1760_0x0a7ddc(a0, a1);
        case 1761: return fde_func_1761_0x0a7de0(a0, a1);
        case 1762: return fde_func_1762_0x0a7ecc(a0, a1);
        case 1763: return fde_func_1763_0x0a8008(a0, a1);
        case 1764: return fde_func_1764_0x0a86e8(a0, a1);
        case 1765: return fde_func_1765_0x0a91fc(a0, a1);
        case 1766: return fde_func_1766_0x0a9288(a0, a1);
        case 1767: return fde_func_1767_0x0a92b0(a0, a1);
        case 1768: return fde_func_1768_0x0a92f0(a0, a1);
        case 1769: return fde_func_1769_0x0a93e0(a0, a1);
        case 1770: return fde_func_1770_0x0a94f4(a0, a1);
        case 1771: return fde_func_1771_0x0a9530(a0, a1);
        case 1772: return fde_func_1772_0x0a9588(a0, a1);
        case 1773: return fde_func_1773_0x0a9694(a0, a1);
        case 1774: return fde_func_1774_0x0a969c(a0, a1);
        case 1775: return fde_func_1775_0x0a96f4(a0, a1);
        case 1776: return fde_func_1776_0x0a96fc(a0, a1);
        case 1777: return fde_func_1777_0x0a9710(a0, a1);
        case 1778: return fde_func_1778_0x0a9718(a0, a1);
        case 1779: return fde_func_1779_0x0a9720(a0, a1);
        case 1780: return fde_func_1780_0x0a9728(a0, a1);
        case 1781: return fde_func_1781_0x0a9750(a0, a1);
        case 1782: return fde_func_1782_0x0a9758(a0, a1);
        case 1783: return fde_func_1783_0x0a9760(a0, a1);
        case 1784: return fde_func_1784_0x0a97d8(a0, a1);
        case 1785: return fde_func_1785_0x0a9cd0(a0, a1);
        case 1786: return fde_func_1786_0x0aa0f4(a0, a1);
        case 1787: return fde_func_1787_0x0aa6a8(a0, a1);
        case 1788: return fde_func_1788_0x0aa8b4(a0, a1);
        case 1789: return fde_func_1789_0x0aa990(a0, a1);
        case 1790: return fde_func_1790_0x0aa9dc(a0, a1);
        case 1791: return fde_func_1791_0x0aaa9c(a0, a1);
        case 1792: return fde_func_1792_0x0aab88(a0, a1);
        case 1793: return fde_func_1793_0x0aac7c(a0, a1);
        case 1794: return fde_func_1794_0x0aac80(a0, a1);
        case 1795: return fde_func_1795_0x0aadf8(a0, a1);
        case 1796: return fde_func_1796_0x0aaeec(a0, a1);
        case 1797: return fde_func_1797_0x0aafe8(a0, a1);
        case 1798: return fde_func_1798_0x0ab0e0(a0, a1);
        case 1799: return fde_func_1799_0x0ab104(a0, a1);
        case 1800: return fde_func_1800_0x0ab1d4(a0, a1);
        case 1801: return fde_func_1801_0x0ab1fc(a0, a1);
        case 1802: return fde_func_1802_0x0ab23c(a0, a1);
        case 1803: return fde_func_1803_0x0ab258(a0, a1);
        case 1804: return fde_func_1804_0x0ab318(a0, a1);
        case 1805: return fde_func_1805_0x0ab3cc(a0, a1);
        case 1806: return fde_func_1806_0x0ab42c(a0, a1);
        case 1807: return fde_func_1807_0x0ab48c(a0, a1);
        case 1808: return fde_func_1808_0x0ab4ec(a0, a1);
        case 1809: return fde_func_1809_0x0ab5dc(a0, a1);
        case 1810: return fde_func_1810_0x0ab66c(a0, a1);
        case 1811: return fde_func_1811_0x0ab768(a0, a1);
        case 1812: return fde_func_1812_0x0ab8c8(a0, a1);
        case 1813: return fde_func_1813_0x0ab8d8(a0, a1);
        case 1814: return fde_func_1814_0x0abcf4(a0, a1);
        case 1815: return fde_func_1815_0x0abd90(a0, a1);
        case 1816: return fde_func_1816_0x0abef0(a0, a1);
        case 1817: return fde_func_1817_0x0ac024(a0, a1);
        case 1818: return fde_func_1818_0x0ac594(a0, a1);
        case 1819: return fde_func_1819_0x0ac630(a0, a1);
        case 1820: return fde_func_1820_0x0ac63c(a0, a1);
        case 1821: return fde_func_1821_0x0ac67c(a0, a1);
        case 1822: return fde_func_1822_0x0ac710(a0, a1);
        case 1823: return fde_func_1823_0x0ac71c(a0, a1);
        case 1824: return fde_func_1824_0x0ac748(a0, a1);
        case 1825: return fde_func_1825_0x0ac848(a0, a1);
        case 1826: return fde_func_1826_0x0ac84c(a0, a1);
        case 1827: return fde_func_1827_0x0ac870(a0, a1);
        case 1828: return fde_func_1828_0x0aca34(a0, a1);
        case 1829: return fde_func_1829_0x0aca74(a0, a1);
        case 1830: return fde_func_1830_0x0acaf4(a0, a1);
        case 1831: return fde_func_1831_0x0acb8c(a0, a1);
        case 1832: return fde_func_1832_0x0acbac(a0, a1);
        case 1833: return fde_func_1833_0x0acd04(a0, a1);
        case 1834: return fde_func_1834_0x0acd40(a0, a1);
        default: return 0ULL;
    }
}

} // namespace nuro