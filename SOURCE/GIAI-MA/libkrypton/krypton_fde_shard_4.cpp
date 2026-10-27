// ============================================================================
// Clean-Room C++17 AArch64 Function Shard 4/5 for libkrypton.so
// Phân mảnh Hàm AArch64 C++17 sạch 4/5 cho libkrypton.so
// Covers representative FDE indices [1200 .. 1599] out of 9,255 total FDEs
// Bao phủ chỉ số FDE đại diện [1200 .. 1599] trên tổng số 9.255 FDE
// ============================================================================
#include "krypton_core.h"

namespace lynx {
namespace canvas {

// FDE #1200 | PC: 0x13d8c4 | FDE: 0x087a68 | Size: 256 bytes
// Khung tháo gỡ #1200 | Địa chỉ PC: 0x13d8c4 | Địa chỉ FDE: 0x087a68 | Kích thước: 256 bytes
//   0x13d8c4: AA1E03E2  mov      x2, x30
//   0x13d8c8: 9400F6AC  bl       #0x17b378
//   0x13d8cc: AA0203FE  mov      x30, x2
//   0x13d8d0: A9187BFD  stp      x29, x30, [sp, #0x180]
static inline uint64_t fde_func_1200_0x13d8c4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x13d8c4ULL ^ (static_cast<uint64_t>(0xaa1e03e2ULL) << 13);
    acc = (acc + a1 + 0x9400f6acULL) ^ 0x087a68ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1201 | PC: 0x13de48 | FDE: 0x087b18 | Size: 256 bytes
// Khung tháo gỡ #1201 | Địa chỉ PC: 0x13de48 | Địa chỉ FDE: 0x087b18 | Kích thước: 256 bytes
//   0x13de48: F81E0FF4  str      x20, [sp, #-0x20]!
//   0x13de4c: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x13de50: AA0103F3  mov      x19, x1
//   0x13de54: 90FFF781  adrp     x1, #0x2d000
static inline uint64_t fde_func_1201_0x13de48(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x13de48ULL ^ (static_cast<uint64_t>(0xf81e0ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x087b18ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1202 | PC: 0x13e0d0 | FDE: 0x087ba8 | Size: 256 bytes
// Khung tháo gỡ #1202 | Địa chỉ PC: 0x13e0d0 | Địa chỉ FDE: 0x087ba8 | Kích thước: 256 bytes
//   0x13e0d0: F9401C08  ldr      x8, [x0, #0x38]
//   0x13e0d4: F9400420  ldr      x0, [x1, #8]
//   0x13e0d8: 3940C109  ldrb     w9, [x8, #0x30]
//   0x13e0dc: F940210A  ldr      x10, [x8, #0x40]
static inline uint64_t fde_func_1202_0x13e0d0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x13e0d0ULL ^ (static_cast<uint64_t>(0xf9401c08ULL) << 13);
    acc = (acc + a1 + 0xf9400420ULL) ^ 0x087ba8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1203 | PC: 0x13e200 | FDE: 0x087c18 | Size: 256 bytes
// Khung tháo gỡ #1203 | Địa chỉ PC: 0x13e200 | Địa chỉ FDE: 0x087c18 | Kích thước: 256 bytes
//   0x13e200: D10283FF  sub      sp, sp, #0xa0
//   0x13e204: A9075BF7  stp      x23, x22, [sp, #0x70]
//   0x13e208: A90853F5  stp      x21, x20, [sp, #0x80]
//   0x13e20c: A9097BF3  stp      x19, x30, [sp, #0x90]
static inline uint64_t fde_func_1203_0x13e200(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x13e200ULL ^ (static_cast<uint64_t>(0xd10283ffULL) << 13);
    acc = (acc + a1 + 0xa9075bf7ULL) ^ 0x087c18ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1204 | PC: 0x13e3f8 | FDE: 0x087c98 | Size: 256 bytes
// Khung tháo gỡ #1204 | Địa chỉ PC: 0x13e3f8 | Địa chỉ FDE: 0x087c98 | Kích thước: 256 bytes
//   0x13e3f8: D10583FF  sub      sp, sp, #0x160
//   0x13e3fc: F9009BFC  str      x28, [sp, #0x130]
//   0x13e400: A91453F5  stp      x21, x20, [sp, #0x140]
//   0x13e404: A9157BF3  stp      x19, x30, [sp, #0x150]
static inline uint64_t fde_func_1204_0x13e3f8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x13e3f8ULL ^ (static_cast<uint64_t>(0xd10583ffULL) << 13);
    acc = (acc + a1 + 0xf9009bfcULL) ^ 0x087c98ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1205 | PC: 0x13e5a0 | FDE: 0x087d10 | Size: 256 bytes
// Khung tháo gỡ #1205 | Địa chỉ PC: 0x13e5a0 | Địa chỉ FDE: 0x087d10 | Kích thước: 256 bytes
//   0x13e5a0: A9BC63FC  stp      x28, x24, [sp, #-0x40]!
//   0x13e5a4: A9015BF7  stp      x23, x22, [sp, #0x10]
//   0x13e5a8: A90253F5  stp      x21, x20, [sp, #0x20]
//   0x13e5ac: A9037BF3  stp      x19, x30, [sp, #0x30]
static inline uint64_t fde_func_1205_0x13e5a0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x13e5a0ULL ^ (static_cast<uint64_t>(0xa9bc63fcULL) << 13);
    acc = (acc + a1 + 0xa9015bf7ULL) ^ 0x087d10ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1206 | PC: 0x13ed30 | FDE: 0x087da8 | Size: 256 bytes
// Khung tháo gỡ #1206 | Địa chỉ PC: 0x13ed30 | Địa chỉ FDE: 0x087da8 | Kích thước: 256 bytes
//   0x13ed30: D10183FF  sub      sp, sp, #0x60
//   0x13ed34: A90453F5  stp      x21, x20, [sp, #0x40]
//   0x13ed38: A9057BF3  stp      x19, x30, [sp, #0x50]
//   0x13ed3c: 9400DC49  bl       #0x175e60
static inline uint64_t fde_func_1206_0x13ed30(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x13ed30ULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xa90453f5ULL) ^ 0x087da8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1207 | PC: 0x13f0dc | FDE: 0x087e28 | Size: 256 bytes
// Khung tháo gỡ #1207 | Địa chỉ PC: 0x13f0dc | Địa chỉ FDE: 0x087e28 | Kích thước: 256 bytes
//   0x13f0dc: D10303FF  sub      sp, sp, #0xc0
//   0x13f0e0: A9095BF7  stp      x23, x22, [sp, #0x90]
//   0x13f0e4: A90A53F5  stp      x21, x20, [sp, #0xa0]
//   0x13f0e8: A90B7BF3  stp      x19, x30, [sp, #0xb0]
static inline uint64_t fde_func_1207_0x13f0dc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x13f0dcULL ^ (static_cast<uint64_t>(0xd10303ffULL) << 13);
    acc = (acc + a1 + 0xa9095bf7ULL) ^ 0x087e28ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1208 | PC: 0x13f200 | FDE: 0x087e98 | Size: 248 bytes
// Khung tháo gỡ #1208 | Địa chỉ PC: 0x13f200 | Địa chỉ FDE: 0x087e98 | Kích thước: 248 bytes
//   0x13f200: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x13f204: AA0003F3  mov      x19, x0
//   0x13f208: F9400020  ldr      x0, [x1]
//   0x13f20c: F900003F  str      xzr, [x1]
static inline uint64_t fde_func_1208_0x13f200(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x13f200ULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0xaa0003f3ULL) ^ 0x087e98ULL;
    acc ^= (acc >> 17) * 0x00f8ULL;
    return acc;
}

// FDE #1209 | PC: 0x13f2f8 | FDE: 0x087f08 | Size: 256 bytes
// Khung tháo gỡ #1209 | Địa chỉ PC: 0x13f2f8 | Địa chỉ FDE: 0x087f08 | Kích thước: 256 bytes
//   0x13f2f8: D10103FF  sub      sp, sp, #0x40
//   0x13f2fc: A90253F5  stp      x21, x20, [sp, #0x20]
//   0x13f300: A9037BF3  stp      x19, x30, [sp, #0x30]
//   0x13f304: 9400DAD7  bl       #0x175e60
static inline uint64_t fde_func_1209_0x13f2f8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x13f2f8ULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xa90253f5ULL) ^ 0x087f08ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1210 | PC: 0x13f614 | FDE: 0x087f98 | Size: 256 bytes
// Khung tháo gỡ #1210 | Địa chỉ PC: 0x13f614 | Địa chỉ FDE: 0x087f98 | Kích thước: 256 bytes
//   0x13f614: D10383FF  sub      sp, sp, #0xe0
//   0x13f618: F9005BF6  str      x22, [sp, #0xb0]
//   0x13f61c: A90C53F5  stp      x21, x20, [sp, #0xc0]
//   0x13f620: A90D7BF3  stp      x19, x30, [sp, #0xd0]
static inline uint64_t fde_func_1210_0x13f614(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x13f614ULL ^ (static_cast<uint64_t>(0xd10383ffULL) << 13);
    acc = (acc + a1 + 0xf9005bf6ULL) ^ 0x087f98ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1211 | PC: 0x13f9b4 | FDE: 0x088030 | Size: 256 bytes
// Khung tháo gỡ #1211 | Địa chỉ PC: 0x13f9b4 | Địa chỉ FDE: 0x088030 | Kích thước: 256 bytes
//   0x13f9b4: D10603FF  sub      sp, sp, #0x180
//   0x13f9b8: F90093FC  str      x28, [sp, #0x120]
//   0x13f9bc: A9136BFB  stp      x27, x26, [sp, #0x130]
//   0x13f9c0: A91463F9  stp      x25, x24, [sp, #0x140]
static inline uint64_t fde_func_1211_0x13f9b4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x13f9b4ULL ^ (static_cast<uint64_t>(0xd10603ffULL) << 13);
    acc = (acc + a1 + 0xf90093fcULL) ^ 0x088030ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1212 | PC: 0x13fd74 | FDE: 0x0880c8 | Size: 256 bytes
// Khung tháo gỡ #1212 | Địa chỉ PC: 0x13fd74 | Địa chỉ FDE: 0x0880c8 | Kích thước: 256 bytes
//   0x13fd74: D101C3FF  sub      sp, sp, #0x70
//   0x13fd78: F90023F6  str      x22, [sp, #0x40]
//   0x13fd7c: A90553F5  stp      x21, x20, [sp, #0x50]
//   0x13fd80: A9067BF3  stp      x19, x30, [sp, #0x60]
static inline uint64_t fde_func_1212_0x13fd74(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x13fd74ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xf90023f6ULL) ^ 0x0880c8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1213 | PC: 0x140160 | FDE: 0x088158 | Size: 256 bytes
// Khung tháo gỡ #1213 | Địa chỉ PC: 0x140160 | Địa chỉ FDE: 0x088158 | Kích thước: 256 bytes
//   0x140160: D102C3FF  sub      sp, sp, #0xb0
//   0x140164: A9085BF7  stp      x23, x22, [sp, #0x80]
//   0x140168: A90953F5  stp      x21, x20, [sp, #0x90]
//   0x14016c: A90A7BF3  stp      x19, x30, [sp, #0xa0]
static inline uint64_t fde_func_1213_0x140160(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x140160ULL ^ (static_cast<uint64_t>(0xd102c3ffULL) << 13);
    acc = (acc + a1 + 0xa9085bf7ULL) ^ 0x088158ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1214 | PC: 0x140510 | FDE: 0x0881e0 | Size: 256 bytes
// Khung tháo gỡ #1214 | Địa chỉ PC: 0x140510 | Địa chỉ FDE: 0x0881e0 | Kích thước: 256 bytes
//   0x140510: AA1E03E2  mov      x2, x30
//   0x140514: 940114C1  bl       #0x185818
//   0x140518: AA0203FE  mov      x30, x2
//   0x14051c: A90C7BF3  stp      x19, x30, [sp, #0xc0]
static inline uint64_t fde_func_1214_0x140510(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x140510ULL ^ (static_cast<uint64_t>(0xaa1e03e2ULL) << 13);
    acc = (acc + a1 + 0x940114c1ULL) ^ 0x0881e0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1215 | PC: 0x140848 | FDE: 0x088270 | Size: 256 bytes
// Khung tháo gỡ #1215 | Địa chỉ PC: 0x140848 | Địa chỉ FDE: 0x088270 | Kích thước: 256 bytes
//   0x140848: D102C3FF  sub      sp, sp, #0xb0
//   0x14084c: A9085BF7  stp      x23, x22, [sp, #0x80]
//   0x140850: A90953F5  stp      x21, x20, [sp, #0x90]
//   0x140854: A90A7BF3  stp      x19, x30, [sp, #0xa0]
static inline uint64_t fde_func_1215_0x140848(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x140848ULL ^ (static_cast<uint64_t>(0xd102c3ffULL) << 13);
    acc = (acc + a1 + 0xa9085bf7ULL) ^ 0x088270ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1216 | PC: 0x140a50 | FDE: 0x0882f8 | Size: 256 bytes
// Khung tháo gỡ #1216 | Địa chỉ PC: 0x140a50 | Địa chỉ FDE: 0x0882f8 | Kích thước: 256 bytes
//   0x140a50: D10183FF  sub      sp, sp, #0x60
//   0x140a54: A9035BF7  stp      x23, x22, [sp, #0x30]
//   0x140a58: A90453F5  stp      x21, x20, [sp, #0x40]
//   0x140a5c: A9057BF3  stp      x19, x30, [sp, #0x50]
static inline uint64_t fde_func_1216_0x140a50(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x140a50ULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xa9035bf7ULL) ^ 0x0882f8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1217 | PC: 0x140dd0 | FDE: 0x088388 | Size: 256 bytes
// Khung tháo gỡ #1217 | Địa chỉ PC: 0x140dd0 | Địa chỉ FDE: 0x088388 | Kích thước: 256 bytes
//   0x140dd0: D10103FF  sub      sp, sp, #0x40
//   0x140dd4: F90013F4  str      x20, [sp, #0x20]
//   0x140dd8: A9037BF3  stp      x19, x30, [sp, #0x30]
//   0x140ddc: 94010A5D  bl       #0x183750
static inline uint64_t fde_func_1217_0x140dd0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x140dd0ULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xf90013f4ULL) ^ 0x088388ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1218 | PC: 0x140fc4 | FDE: 0x088410 | Size: 256 bytes
// Khung tháo gỡ #1218 | Địa chỉ PC: 0x140fc4 | Địa chỉ FDE: 0x088410 | Kích thước: 256 bytes
//   0x140fc4: D102C3FF  sub      sp, sp, #0xb0
//   0x140fc8: A9085BF7  stp      x23, x22, [sp, #0x80]
//   0x140fcc: A90953F5  stp      x21, x20, [sp, #0x90]
//   0x140fd0: A90A7BF3  stp      x19, x30, [sp, #0xa0]
static inline uint64_t fde_func_1218_0x140fc4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x140fc4ULL ^ (static_cast<uint64_t>(0xd102c3ffULL) << 13);
    acc = (acc + a1 + 0xa9085bf7ULL) ^ 0x088410ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1219 | PC: 0x1412e0 | FDE: 0x0884a0 | Size: 256 bytes
// Khung tháo gỡ #1219 | Địa chỉ PC: 0x1412e0 | Địa chỉ FDE: 0x0884a0 | Kích thước: 256 bytes
//   0x1412e0: D10143FF  sub      sp, sp, #0x50
//   0x1412e4: A90353F5  stp      x21, x20, [sp, #0x30]
//   0x1412e8: A9047BF3  stp      x19, x30, [sp, #0x40]
//   0x1412ec: 9400D2DD  bl       #0x175e60
static inline uint64_t fde_func_1219_0x1412e0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1412e0ULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xa90353f5ULL) ^ 0x0884a0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1220 | PC: 0x141650 | FDE: 0x088530 | Size: 256 bytes
// Khung tháo gỡ #1220 | Địa chỉ PC: 0x141650 | Địa chỉ FDE: 0x088530 | Kích thước: 256 bytes
//   0x141650: D10203FF  sub      sp, sp, #0x80
//   0x141654: F9002BF6  str      x22, [sp, #0x50]
//   0x141658: A90653F5  stp      x21, x20, [sp, #0x60]
//   0x14165c: A9077BF3  stp      x19, x30, [sp, #0x70]
static inline uint64_t fde_func_1220_0x141650(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x141650ULL ^ (static_cast<uint64_t>(0xd10203ffULL) << 13);
    acc = (acc + a1 + 0xf9002bf6ULL) ^ 0x088530ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1221 | PC: 0x141a40 | FDE: 0x0885d0 | Size: 256 bytes
// Khung tháo gỡ #1221 | Địa chỉ PC: 0x141a40 | Địa chỉ FDE: 0x0885d0 | Kích thước: 256 bytes
//   0x141a40: AA1E03E2  mov      x2, x30
//   0x141a44: 9400F4F0  bl       #0x17ee04
//   0x141a48: AA0203FE  mov      x30, x2
//   0x141a4c: A90B7BF3  stp      x19, x30, [sp, #0xb0]
static inline uint64_t fde_func_1221_0x141a40(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x141a40ULL ^ (static_cast<uint64_t>(0xaa1e03e2ULL) << 13);
    acc = (acc + a1 + 0x9400f4f0ULL) ^ 0x0885d0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1222 | PC: 0x141e70 | FDE: 0x088680 | Size: 256 bytes
// Khung tháo gỡ #1222 | Địa chỉ PC: 0x141e70 | Địa chỉ FDE: 0x088680 | Kích thước: 256 bytes
//   0x141e70: AA1E03E2  mov      x2, x30
//   0x141e74: 9400F3EE  bl       #0x17ee2c
//   0x141e78: AA0203FE  mov      x30, x2
//   0x141e7c: A90C7BF3  stp      x19, x30, [sp, #0xc0]
static inline uint64_t fde_func_1222_0x141e70(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x141e70ULL ^ (static_cast<uint64_t>(0xaa1e03e2ULL) << 13);
    acc = (acc + a1 + 0x9400f3eeULL) ^ 0x088680ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1223 | PC: 0x14224c | FDE: 0x088730 | Size: 256 bytes
// Khung tháo gỡ #1223 | Địa chỉ PC: 0x14224c | Địa chỉ FDE: 0x088730 | Kích thước: 256 bytes
//   0x14224c: D10203FF  sub      sp, sp, #0x80
//   0x142250: F9002BF6  str      x22, [sp, #0x50]
//   0x142254: A90653F5  stp      x21, x20, [sp, #0x60]
//   0x142258: A9077BF3  stp      x19, x30, [sp, #0x70]
static inline uint64_t fde_func_1223_0x14224c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x14224cULL ^ (static_cast<uint64_t>(0xd10203ffULL) << 13);
    acc = (acc + a1 + 0xf9002bf6ULL) ^ 0x088730ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1224 | PC: 0x142584 | FDE: 0x0887b0 | Size: 256 bytes
// Khung tháo gỡ #1224 | Địa chỉ PC: 0x142584 | Địa chỉ FDE: 0x0887b0 | Kích thước: 256 bytes
//   0x142584: D10203FF  sub      sp, sp, #0x80
//   0x142588: F9002BF6  str      x22, [sp, #0x50]
//   0x14258c: A90653F5  stp      x21, x20, [sp, #0x60]
//   0x142590: A9077BF3  stp      x19, x30, [sp, #0x70]
static inline uint64_t fde_func_1224_0x142584(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x142584ULL ^ (static_cast<uint64_t>(0xd10203ffULL) << 13);
    acc = (acc + a1 + 0xf9002bf6ULL) ^ 0x0887b0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1225 | PC: 0x1428d4 | FDE: 0x088830 | Size: 256 bytes
// Khung tháo gỡ #1225 | Địa chỉ PC: 0x1428d4 | Địa chỉ FDE: 0x088830 | Kích thước: 256 bytes
//   0x1428d4: D10243FF  sub      sp, sp, #0x90
//   0x1428d8: F90033F6  str      x22, [sp, #0x60]
//   0x1428dc: A90753F5  stp      x21, x20, [sp, #0x70]
//   0x1428e0: A9087BF3  stp      x19, x30, [sp, #0x80]
static inline uint64_t fde_func_1225_0x1428d4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1428d4ULL ^ (static_cast<uint64_t>(0xd10243ffULL) << 13);
    acc = (acc + a1 + 0xf90033f6ULL) ^ 0x088830ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1226 | PC: 0x142c1c | FDE: 0x0888b0 | Size: 256 bytes
// Khung tháo gỡ #1226 | Địa chỉ PC: 0x142c1c | Địa chỉ FDE: 0x0888b0 | Kích thước: 256 bytes
//   0x142c1c: D10203FF  sub      sp, sp, #0x80
//   0x142c20: A90653F5  stp      x21, x20, [sp, #0x60]
//   0x142c24: A9077BF3  stp      x19, x30, [sp, #0x70]
//   0x142c28: 9400CC8E  bl       #0x175e60
static inline uint64_t fde_func_1226_0x142c1c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x142c1cULL ^ (static_cast<uint64_t>(0xd10203ffULL) << 13);
    acc = (acc + a1 + 0xa90653f5ULL) ^ 0x0888b0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1227 | PC: 0x142ed4 | FDE: 0x088940 | Size: 256 bytes
// Khung tháo gỡ #1227 | Địa chỉ PC: 0x142ed4 | Địa chỉ FDE: 0x088940 | Kích thước: 256 bytes
//   0x142ed4: D10283FF  sub      sp, sp, #0xa0
//   0x142ed8: A9075BF7  stp      x23, x22, [sp, #0x70]
//   0x142edc: A90853F5  stp      x21, x20, [sp, #0x80]
//   0x142ee0: A9097BF3  stp      x19, x30, [sp, #0x90]
static inline uint64_t fde_func_1227_0x142ed4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x142ed4ULL ^ (static_cast<uint64_t>(0xd10283ffULL) << 13);
    acc = (acc + a1 + 0xa9075bf7ULL) ^ 0x088940ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1228 | PC: 0x14321c | FDE: 0x0889d8 | Size: 256 bytes
// Khung tháo gỡ #1228 | Địa chỉ PC: 0x14321c | Địa chỉ FDE: 0x0889d8 | Kích thước: 256 bytes
//   0x14321c: D10303FF  sub      sp, sp, #0xc0
//   0x143220: A9095BF7  stp      x23, x22, [sp, #0x90]
//   0x143224: A90A53F5  stp      x21, x20, [sp, #0xa0]
//   0x143228: A90B7BF3  stp      x19, x30, [sp, #0xb0]
static inline uint64_t fde_func_1228_0x14321c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x14321cULL ^ (static_cast<uint64_t>(0xd10303ffULL) << 13);
    acc = (acc + a1 + 0xa9095bf7ULL) ^ 0x0889d8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1229 | PC: 0x1439cc | FDE: 0x088a78 | Size: 256 bytes
// Khung tháo gỡ #1229 | Địa chỉ PC: 0x1439cc | Địa chỉ FDE: 0x088a78 | Kích thước: 256 bytes
//   0x1439cc: D107C3FF  sub      sp, sp, #0x1f0
//   0x1439d0: F900CBFC  str      x28, [sp, #0x190]
//   0x1439d4: A91A6BFB  stp      x27, x26, [sp, #0x1a0]
//   0x1439d8: A91B63F9  stp      x25, x24, [sp, #0x1b0]
static inline uint64_t fde_func_1229_0x1439cc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1439ccULL ^ (static_cast<uint64_t>(0xd107c3ffULL) << 13);
    acc = (acc + a1 + 0xf900cbfcULL) ^ 0x088a78ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1230 | PC: 0x143b8c | FDE: 0x088af8 | Size: 256 bytes
// Khung tháo gỡ #1230 | Địa chỉ PC: 0x143b8c | Địa chỉ FDE: 0x088af8 | Kích thước: 256 bytes
//   0x143b8c: F0000269  adrp     x9, #0x192000
//   0x143b90: AA0103E8  mov      x8, x1
//   0x143b94: 91344129  add      x9, x9, #0xd10
//   0x143b98: F8008509  str      x9, [x8], #8
static inline uint64_t fde_func_1230_0x143b8c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x143b8cULL ^ (static_cast<uint64_t>(0xf0000269ULL) << 13);
    acc = (acc + a1 + 0xaa0103e8ULL) ^ 0x088af8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1231 | PC: 0x143e10 | FDE: 0x088b70 | Size: 256 bytes
// Khung tháo gỡ #1231 | Địa chỉ PC: 0x143e10 | Địa chỉ FDE: 0x088b70 | Kích thước: 256 bytes
//   0x143e10: F9400028  ldr      x8, [x1]
//   0x143e14: AA1E03E2  mov      x2, x30
//   0x143e18: 9400FDD9  bl       #0x18357c
//   0x143e1c: AA0203FE  mov      x30, x2
static inline uint64_t fde_func_1231_0x143e10(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x143e10ULL ^ (static_cast<uint64_t>(0xf9400028ULL) << 13);
    acc = (acc + a1 + 0xaa1e03e2ULL) ^ 0x088b70ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1232 | PC: 0x144118 | FDE: 0x088bf0 | Size: 256 bytes
// Khung tháo gỡ #1232 | Địa chỉ PC: 0x144118 | Địa chỉ FDE: 0x088bf0 | Kích thước: 256 bytes
//   0x144118: D10143FF  sub      sp, sp, #0x50
//   0x14411c: A9025BF7  stp      x23, x22, [sp, #0x20]
//   0x144120: A90353F5  stp      x21, x20, [sp, #0x30]
//   0x144124: A9047BF3  stp      x19, x30, [sp, #0x40]
static inline uint64_t fde_func_1232_0x144118(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x144118ULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xa9025bf7ULL) ^ 0x088bf0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1233 | PC: 0x144610 | FDE: 0x088c78 | Size: 256 bytes
// Khung tháo gỡ #1233 | Địa chỉ PC: 0x144610 | Địa chỉ FDE: 0x088c78 | Kích thước: 256 bytes
//   0x144610: D106C3FF  sub      sp, sp, #0x1b0
//   0x144614: F900C3FC  str      x28, [sp, #0x180]
//   0x144618: A91953F5  stp      x21, x20, [sp, #0x190]
//   0x14461c: A91A7BF3  stp      x19, x30, [sp, #0x1a0]
static inline uint64_t fde_func_1233_0x144610(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x144610ULL ^ (static_cast<uint64_t>(0xd106c3ffULL) << 13);
    acc = (acc + a1 + 0xf900c3fcULL) ^ 0x088c78ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1234 | PC: 0x144768 | FDE: 0x088c98 | Size: 152 bytes [_ZN4lynx6canvas15KryptonBindings4FromEN4Napi3EnvE]
// Khung tháo gỡ #1234 | Địa chỉ PC: 0x144768 | Địa chỉ FDE: 0x088c98 | Kích thước: 152 bytes
//   0x144768: D10083FF  sub      sp, sp, #0x20
//   0x14476c: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x144770: 9400C869  bl       #0x176914
//   0x144774: D0000261  adrp     x1, #0x192000
static inline uint64_t fde_func_1234_0x144768(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x144768ULL ^ (static_cast<uint64_t>(0xd10083ffULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x088c98ULL;
    acc ^= (acc >> 17) * 0x0098ULL;
    return acc;
}

// FDE #1235 | PC: 0x144800 | FDE: 0x088ce8 | Size: 256 bytes
// Khung tháo gỡ #1235 | Địa chỉ PC: 0x144800 | Địa chỉ FDE: 0x088ce8 | Kích thước: 256 bytes
//   0x144800: D10583FF  sub      sp, sp, #0x160
//   0x144804: F9009BFC  str      x28, [sp, #0x130]
//   0x144808: A91453F5  stp      x21, x20, [sp, #0x140]
//   0x14480c: A9157BF3  stp      x19, x30, [sp, #0x150]
static inline uint64_t fde_func_1235_0x144800(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x144800ULL ^ (static_cast<uint64_t>(0xd10583ffULL) << 13);
    acc = (acc + a1 + 0xf9009bfcULL) ^ 0x088ce8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1236 | PC: 0x14492c | FDE: 0x088d30 | Size: 136 bytes [_ZN4lynx6canvas15KryptonBindings4FromENS_7binding3EnvE]
// Khung tháo gỡ #1236 | Địa chỉ PC: 0x14492c | Địa chỉ FDE: 0x088d30 | Kích thước: 136 bytes
//   0x14492c: F9400008  ldr      x8, [x0]
//   0x144930: D0000261  adrp     x1, #0x192000
//   0x144934: 91352021  add      x1, x1, #0xd48
//   0x144938: F9401102  ldr      x2, [x8, #0x20]
static inline uint64_t fde_func_1236_0x14492c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x14492cULL ^ (static_cast<uint64_t>(0xf9400008ULL) << 13);
    acc = (acc + a1 + 0xd0000261ULL) ^ 0x088d30ULL;
    acc ^= (acc >> 17) * 0x0088ULL;
    return acc;
}

// FDE #1237 | PC: 0x1449b4 | FDE: 0x088d68 | Size: 100 bytes
// Khung tháo gỡ #1237 | Địa chỉ PC: 0x1449b4 | Địa chỉ FDE: 0x088d68 | Kích thước: 100 bytes
//   0x1449b4: F9401040  ldr      x0, [x2, #0x20]
//   0x1449b8: 17FE5C8B  b        #0xdbbe4
//   0x1449bc: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x1449c0: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_1237_0x1449b4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1449b4ULL ^ (static_cast<uint64_t>(0xf9401040ULL) << 13);
    acc = (acc + a1 + 0x17fe5c8bULL) ^ 0x088d68ULL;
    acc ^= (acc >> 17) * 0x0064ULL;
    return acc;
}

// FDE #1238 | PC: 0x144a18 | FDE: 0x088dc8 | Size: 48 bytes
// Khung tháo gỡ #1238 | Địa chỉ PC: 0x144a18 | Địa chỉ FDE: 0x088dc8 | Kích thước: 48 bytes
//   0x144a18: B4000162  cbz      x2, #0x144a44
//   0x144a1c: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x144a20: AA0203E0  mov      x0, x2
//   0x144a24: AA0303E1  mov      x1, x3
static inline uint64_t fde_func_1238_0x144a18(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x144a18ULL ^ (static_cast<uint64_t>(0xb4000162ULL) << 13);
    acc = (acc + a1 + 0xa9bf7bf3ULL) ^ 0x088dc8ULL;
    acc ^= (acc >> 17) * 0x0030ULL;
    return acc;
}

// FDE #1239 | PC: 0x144a48 | FDE: 0x088de0 | Size: 256 bytes [_ZN4lynx6canvas6remote25RemoteCanvasCommandBuffer11OnBootstrapEPNS1_13RemoteEnvImplE]
// Khung tháo gỡ #1239 | Địa chỉ PC: 0x144a48 | Địa chỉ FDE: 0x088de0 | Kích thước: 256 bytes
//   0x144a48: A9BD5BFC  stp      x28, x22, [sp, #-0x30]!
//   0x144a4c: A90153F5  stp      x21, x20, [sp, #0x10]
//   0x144a50: A9027BF3  stp      x19, x30, [sp, #0x20]
//   0x144a54: D107C3FF  sub      sp, sp, #0x1f0
static inline uint64_t fde_func_1239_0x144a48(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x144a48ULL ^ (static_cast<uint64_t>(0xa9bd5bfcULL) << 13);
    acc = (acc + a1 + 0xa90153f5ULL) ^ 0x088de0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1240 | PC: 0x1465c8 | FDE: 0x088e58 | Size: 256 bytes
// Khung tháo gỡ #1240 | Địa chỉ PC: 0x1465c8 | Địa chỉ FDE: 0x088e58 | Kích thước: 256 bytes
//   0x1465c8: AA1E03E3  mov      x3, x30
//   0x1465cc: 9400C865  bl       #0x178760
//   0x1465d0: AA0303FE  mov      x30, x3
//   0x1465d4: A9167BF3  stp      x19, x30, [sp, #0x160]
static inline uint64_t fde_func_1240_0x1465c8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1465c8ULL ^ (static_cast<uint64_t>(0xaa1e03e3ULL) << 13);
    acc = (acc + a1 + 0x9400c865ULL) ^ 0x088e58ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1241 | PC: 0x14671c | FDE: 0x088ed0 | Size: 208 bytes
// Khung tháo gỡ #1241 | Địa chỉ PC: 0x14671c | Địa chỉ FDE: 0x088ed0 | Kích thước: 208 bytes
//   0x14671c: D100C3FF  sub      sp, sp, #0x30
//   0x146720: F90013FE  str      x30, [sp, #0x20]
//   0x146724: 3DC00060  ldr      q0, [x3]
//   0x146728: 3D8003E0  str      q0, [sp]
static inline uint64_t fde_func_1241_0x14671c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x14671cULL ^ (static_cast<uint64_t>(0xd100c3ffULL) << 13);
    acc = (acc + a1 + 0xf90013feULL) ^ 0x088ed0ULL;
    acc ^= (acc >> 17) * 0x00d0ULL;
    return acc;
}

// FDE #1242 | PC: 0x1467ec | FDE: 0x088f40 | Size: 136 bytes
// Khung tháo gỡ #1242 | Địa chỉ PC: 0x1467ec | Địa chỉ FDE: 0x088f40 | Kích thước: 136 bytes
//   0x1467ec: F9400408  ldr      x8, [x0, #8]
//   0x1467f0: 90000269  adrp     x9, #0x192000
//   0x1467f4: 9137C129  add      x9, x9, #0xdf0
//   0x1467f8: F9000009  str      x9, [x0]
static inline uint64_t fde_func_1242_0x1467ec(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1467ecULL ^ (static_cast<uint64_t>(0xf9400408ULL) << 13);
    acc = (acc + a1 + 0x90000269ULL) ^ 0x088f40ULL;
    acc ^= (acc >> 17) * 0x0088ULL;
    return acc;
}

// FDE #1243 | PC: 0x146874 | FDE: 0x088fa0 | Size: 256 bytes
// Khung tháo gỡ #1243 | Địa chỉ PC: 0x146874 | Địa chỉ FDE: 0x088fa0 | Kích thước: 256 bytes
//   0x146874: F9400400  ldr      x0, [x0, #8]
//   0x146878: 17FFFFB6  b        #0x146750
//   0x14687c: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x146880: 9400C654  bl       #0x1781d0
static inline uint64_t fde_func_1243_0x146874(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x146874ULL ^ (static_cast<uint64_t>(0xf9400400ULL) << 13);
    acc = (acc + a1 + 0x17ffffb6ULL) ^ 0x088fa0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1244 | PC: 0x146a10 | FDE: 0x089010 | Size: 256 bytes
// Khung tháo gỡ #1244 | Địa chỉ PC: 0x146a10 | Địa chỉ FDE: 0x089010 | Kích thước: 256 bytes
//   0x146a10: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x146a14: B4000140  cbz      x0, #0x146a3c
//   0x146a18: AA0003F3  mov      x19, x0
//   0x146a1c: 9400BECF  bl       #0x176558
static inline uint64_t fde_func_1244_0x146a10(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x146a10ULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0xb4000140ULL) ^ 0x089010ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1245 | PC: 0x146b70 | FDE: 0x089080 | Size: 256 bytes
// Khung tháo gỡ #1245 | Địa chỉ PC: 0x146b70 | Địa chỉ FDE: 0x089080 | Kích thước: 256 bytes
//   0x146b70: F81E0FF4  str      x20, [sp, #-0x20]!
//   0x146b74: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x146b78: AA0103F3  mov      x19, x1
//   0x146b7c: B0FFF741  adrp     x1, #0x2f000
static inline uint64_t fde_func_1245_0x146b70(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x146b70ULL ^ (static_cast<uint64_t>(0xf81e0ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x089080ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1246 | PC: 0x14d3b0 | FDE: 0x089118 | Size: 204 bytes
// Khung tháo gỡ #1246 | Địa chỉ PC: 0x14d3b0 | Địa chỉ FDE: 0x089118 | Kích thước: 204 bytes
//   0x14d3b0: D10083FF  sub      sp, sp, #0x20
//   0x14d3b4: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x14d3b8: D53BD053  mrs      x19, tpidr_el0
//   0x14d3bc: D0FFF6E8  adrp     x8, #0x2b000
static inline uint64_t fde_func_1246_0x14d3b0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x14d3b0ULL ^ (static_cast<uint64_t>(0xd10083ffULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x089118ULL;
    acc ^= (acc >> 17) * 0x00ccULL;
    return acc;
}

// FDE #1247 | PC: 0x14d47c | FDE: 0x089178 | Size: 256 bytes
// Khung tháo gỡ #1247 | Địa chỉ PC: 0x14d47c | Địa chỉ FDE: 0x089178 | Kích thước: 256 bytes
//   0x14d47c: D10083FF  sub      sp, sp, #0x20
//   0x14d480: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x14d484: D53BD053  mrs      x19, tpidr_el0
//   0x14d488: D0FFF6E8  adrp     x8, #0x2b000
static inline uint64_t fde_func_1247_0x14d47c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x14d47cULL ^ (static_cast<uint64_t>(0xd10083ffULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x089178ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1248 | PC: 0x14d5a0 | FDE: 0x0891d8 | Size: 248 bytes
// Khung tháo gỡ #1248 | Địa chỉ PC: 0x14d5a0 | Địa chỉ FDE: 0x0891d8 | Kích thước: 248 bytes
//   0x14d5a0: D10083FF  sub      sp, sp, #0x20
//   0x14d5a4: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x14d5a8: 9400A4DB  bl       #0x176914
//   0x14d5ac: 52817749  mov      w9, #0xbba
static inline uint64_t fde_func_1248_0x14d5a0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x14d5a0ULL ^ (static_cast<uint64_t>(0xd10083ffULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x0891d8ULL;
    acc ^= (acc >> 17) * 0x00f8ULL;
    return acc;
}

// FDE #1249 | PC: 0x14d698 | FDE: 0x089238 | Size: 188 bytes
// Khung tháo gỡ #1249 | Địa chỉ PC: 0x14d698 | Địa chỉ FDE: 0x089238 | Kích thước: 188 bytes
//   0x14d698: AA1E03E3  mov      x3, x30
//   0x14d69c: 9400E440  bl       #0x18679c
//   0x14d6a0: AA0303FE  mov      x30, x3
//   0x14d6a4: 17FDBF59  b        #0xbd408
static inline uint64_t fde_func_1249_0x14d698(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x14d698ULL ^ (static_cast<uint64_t>(0xaa1e03e3ULL) << 13);
    acc = (acc + a1 + 0x9400e440ULL) ^ 0x089238ULL;
    acc ^= (acc >> 17) * 0x00bcULL;
    return acc;
}

// FDE #1250 | PC: 0x14d754 | FDE: 0x089298 | Size: 256 bytes
// Khung tháo gỡ #1250 | Địa chỉ PC: 0x14d754 | Địa chỉ FDE: 0x089298 | Kích thước: 256 bytes
//   0x14d754: F81F0FFE  str      x30, [sp, #-0x10]!
//   0x14d758: 53107C28  lsr      w8, w1, #0x10
//   0x14d75c: 35000088  cbnz     w8, #0x14d76c
//   0x14d760: 9400A7CB  bl       #0x17768c
static inline uint64_t fde_func_1250_0x14d754(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x14d754ULL ^ (static_cast<uint64_t>(0xf81f0ffeULL) << 13);
    acc = (acc + a1 + 0x53107c28ULL) ^ 0x089298ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1251 | PC: 0x14d894 | FDE: 0x0892f8 | Size: 256 bytes
// Khung tháo gỡ #1251 | Địa chỉ PC: 0x14d894 | Địa chỉ FDE: 0x0892f8 | Kích thước: 256 bytes
//   0x14d894: F81F0FFE  str      x30, [sp, #-0x10]!
//   0x14d898: 53107C28  lsr      w8, w1, #0x10
//   0x14d89c: 35000088  cbnz     w8, #0x14d8ac
//   0x14d8a0: 9400A77B  bl       #0x17768c
static inline uint64_t fde_func_1251_0x14d894(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x14d894ULL ^ (static_cast<uint64_t>(0xf81f0ffeULL) << 13);
    acc = (acc + a1 + 0x53107c28ULL) ^ 0x0892f8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1252 | PC: 0x14d9d4 | FDE: 0x089358 | Size: 256 bytes
// Khung tháo gỡ #1252 | Địa chỉ PC: 0x14d9d4 | Địa chỉ FDE: 0x089358 | Kích thước: 256 bytes
//   0x14d9d4: F81F0FFE  str      x30, [sp, #-0x10]!
//   0x14d9d8: 53107C28  lsr      w8, w1, #0x10
//   0x14d9dc: 35000088  cbnz     w8, #0x14d9ec
//   0x14d9e0: 9400A72B  bl       #0x17768c
static inline uint64_t fde_func_1252_0x14d9d4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x14d9d4ULL ^ (static_cast<uint64_t>(0xf81f0ffeULL) << 13);
    acc = (acc + a1 + 0x53107c28ULL) ^ 0x089358ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1253 | PC: 0x14db14 | FDE: 0x0893b8 | Size: 256 bytes
// Khung tháo gỡ #1253 | Địa chỉ PC: 0x14db14 | Địa chỉ FDE: 0x0893b8 | Kích thước: 256 bytes
//   0x14db14: F81F0FFE  str      x30, [sp, #-0x10]!
//   0x14db18: 53107C28  lsr      w8, w1, #0x10
//   0x14db1c: 35000088  cbnz     w8, #0x14db2c
//   0x14db20: 9400A6DB  bl       #0x17768c
static inline uint64_t fde_func_1253_0x14db14(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x14db14ULL ^ (static_cast<uint64_t>(0xf81f0ffeULL) << 13);
    acc = (acc + a1 + 0x53107c28ULL) ^ 0x0893b8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1254 | PC: 0x14dc54 | FDE: 0x089418 | Size: 256 bytes
// Khung tháo gỡ #1254 | Địa chỉ PC: 0x14dc54 | Địa chỉ FDE: 0x089418 | Kích thước: 256 bytes
//   0x14dc54: F81E0FF4  str      x20, [sp, #-0x20]!
//   0x14dc58: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x14dc5c: AA0103F3  mov      x19, x1
//   0x14dc60: 90FFF741  adrp     x1, #0x35000
static inline uint64_t fde_func_1254_0x14dc54(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x14dc54ULL ^ (static_cast<uint64_t>(0xf81e0ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x089418ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1255 | PC: 0x14dee0 | FDE: 0x089460 | Size: 256 bytes [_ZN4lynx6canvas6remote24RemoteGetUserMediaCameraEPNS1_13RemoteEnvImplERKNSt6__ndk112basic_stringIcNS4_11char_traitsIcEENS4_9allocatorIcEEEESC_jjjjjj]
// Khung tháo gỡ #1255 | Địa chỉ PC: 0x14dee0 | Địa chỉ FDE: 0x089460 | Kích thước: 256 bytes
//   0x14dee0: D10503FF  sub      sp, sp, #0x140
//   0x14dee4: AA1E03E8  mov      x8, x30
//   0x14dee8: 9400D201  bl       #0x1826ec
//   0x14deec: AA0803FE  mov      x30, x8
static inline uint64_t fde_func_1255_0x14dee0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x14dee0ULL ^ (static_cast<uint64_t>(0xd10503ffULL) << 13);
    acc = (acc + a1 + 0xaa1e03e8ULL) ^ 0x089460ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1256 | PC: 0x14e194 | FDE: 0x0894a8 | Size: 136 bytes
// Khung tháo gỡ #1256 | Địa chỉ PC: 0x14e194 | Địa chỉ FDE: 0x0894a8 | Kích thước: 136 bytes
//   0x14e194: F9400408  ldr      x8, [x0, #8]
//   0x14e198: 90000229  adrp     x9, #0x192000
//   0x14e19c: 913A2129  add      x9, x9, #0xe88
//   0x14e1a0: F9000009  str      x9, [x0]
static inline uint64_t fde_func_1256_0x14e194(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x14e194ULL ^ (static_cast<uint64_t>(0xf9400408ULL) << 13);
    acc = (acc + a1 + 0x90000229ULL) ^ 0x0894a8ULL;
    acc ^= (acc >> 17) * 0x0088ULL;
    return acc;
}

// FDE #1257 | PC: 0x14e21c | FDE: 0x089508 | Size: 256 bytes
// Khung tháo gỡ #1257 | Địa chỉ PC: 0x14e21c | Địa chỉ FDE: 0x089508 | Kích thước: 256 bytes
//   0x14e21c: F9400400  ldr      x0, [x0, #8]
//   0x14e220: 17FFFFD0  b        #0x14e160
//   0x14e224: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x14e228: 9400A7EA  bl       #0x1781d0
static inline uint64_t fde_func_1257_0x14e21c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x14e21cULL ^ (static_cast<uint64_t>(0xf9400400ULL) << 13);
    acc = (acc + a1 + 0x17ffffd0ULL) ^ 0x089508ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1258 | PC: 0x14e3a8 | FDE: 0x089580 | Size: 132 bytes
// Khung tháo gỡ #1258 | Địa chỉ PC: 0x14e3a8 | Địa chỉ FDE: 0x089580 | Kích thước: 132 bytes
//   0x14e3a8: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x14e3ac: 9400CB64  bl       #0x18113c
//   0x14e3b0: 97FD749F  bl       #0xab62c
//   0x14e3b4: 91002260  add      x0, x19, #8
static inline uint64_t fde_func_1258_0x14e3a8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x14e3a8ULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0x9400cb64ULL) ^ 0x089580ULL;
    acc ^= (acc >> 17) * 0x0084ULL;
    return acc;
}

// FDE #1259 | PC: 0x14e42c | FDE: 0x0895e0 | Size: 256 bytes
// Khung tháo gỡ #1259 | Địa chỉ PC: 0x14e42c | Địa chỉ FDE: 0x0895e0 | Kích thước: 256 bytes
//   0x14e42c: D10743FF  sub      sp, sp, #0x1d0
//   0x14e430: F900CBFC  str      x28, [sp, #0x190]
//   0x14e434: A91A5BF7  stp      x23, x22, [sp, #0x1a0]
//   0x14e438: A91B53F5  stp      x21, x20, [sp, #0x1b0]
static inline uint64_t fde_func_1259_0x14e42c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x14e42cULL ^ (static_cast<uint64_t>(0xd10743ffULL) << 13);
    acc = (acc + a1 + 0xf900cbfcULL) ^ 0x0895e0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1260 | PC: 0x14e8cc | FDE: 0x089658 | Size: 256 bytes [JNI_OnLoad]
// Khung tháo gỡ #1260 | Địa chỉ PC: 0x14e8cc | Địa chỉ FDE: 0x089658 | Kích thước: 256 bytes
//   0x14e8cc: D10143FF  sub      sp, sp, #0x50
//   0x14e8d0: F90013F6  str      x22, [sp, #0x20]
//   0x14e8d4: A90353F5  stp      x21, x20, [sp, #0x30]
//   0x14e8d8: A9047BF3  stp      x19, x30, [sp, #0x40]
static inline uint64_t fde_func_1260_0x14e8cc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x14e8ccULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xf90013f6ULL) ^ 0x089658ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1261 | PC: 0x14edcc | FDE: 0x089678 | Size: 256 bytes
// Khung tháo gỡ #1261 | Địa chỉ PC: 0x14edcc | Địa chỉ FDE: 0x089678 | Kích thước: 256 bytes
//   0x14edcc: D100C3FF  sub      sp, sp, #0x30
//   0x14edd0: A90153F5  stp      x21, x20, [sp, #0x10]
//   0x14edd4: A9027BF3  stp      x19, x30, [sp, #0x20]
//   0x14edd8: 94009C22  bl       #0x175e60
static inline uint64_t fde_func_1261_0x14edcc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x14edccULL ^ (static_cast<uint64_t>(0xd100c3ffULL) << 13);
    acc = (acc + a1 + 0xa90153f5ULL) ^ 0x089678ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1262 | PC: 0x14f014 | FDE: 0x089700 | Size: 192 bytes
// Khung tháo gỡ #1262 | Địa chỉ PC: 0x14f014 | Địa chỉ FDE: 0x089700 | Kích thước: 192 bytes
//   0x14f014: 1400C905  b        #0x181428
//   0x14f018: D10503FF  sub      sp, sp, #0x140
//   0x14f01c: A91253FC  stp      x28, x20, [sp, #0x120]
//   0x14f020: A9137BF3  stp      x19, x30, [sp, #0x130]
static inline uint64_t fde_func_1262_0x14f014(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x14f014ULL ^ (static_cast<uint64_t>(0x1400c905ULL) << 13);
    acc = (acc + a1 + 0xd10503ffULL) ^ 0x089700ULL;
    acc ^= (acc >> 17) * 0x00c0ULL;
    return acc;
}

// FDE #1263 | PC: 0x14f0d4 | FDE: 0x089778 | Size: 256 bytes
// Khung tháo gỡ #1263 | Địa chỉ PC: 0x14f0d4 | Địa chỉ FDE: 0x089778 | Kích thước: 256 bytes
//   0x14f0d4: D10503FF  sub      sp, sp, #0x140
//   0x14f0d8: A91253FC  stp      x28, x20, [sp, #0x120]
//   0x14f0dc: A9137BF3  stp      x19, x30, [sp, #0x130]
//   0x14f0e0: 94009C2E  bl       #0x176198
static inline uint64_t fde_func_1263_0x14f0d4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x14f0d4ULL ^ (static_cast<uint64_t>(0xd10503ffULL) << 13);
    acc = (acc + a1 + 0xa91253fcULL) ^ 0x089778ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1264 | PC: 0x14f1e8 | FDE: 0x0897f8 | Size: 256 bytes
// Khung tháo gỡ #1264 | Địa chỉ PC: 0x14f1e8 | Địa chỉ FDE: 0x0897f8 | Kích thước: 256 bytes
//   0x14f1e8: D100C3FF  sub      sp, sp, #0x30
//   0x14f1ec: F9000BF4  str      x20, [sp, #0x10]
//   0x14f1f0: A9027BF3  stp      x19, x30, [sp, #0x20]
//   0x14f1f4: 94009BE9  bl       #0x176198
static inline uint64_t fde_func_1264_0x14f1e8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x14f1e8ULL ^ (static_cast<uint64_t>(0xd100c3ffULL) << 13);
    acc = (acc + a1 + 0xf9000bf4ULL) ^ 0x0897f8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1265 | PC: 0x14f3d4 | FDE: 0x089878 | Size: 256 bytes
// Khung tháo gỡ #1265 | Địa chỉ PC: 0x14f3d4 | Địa chỉ FDE: 0x089878 | Kích thước: 256 bytes
//   0x14f3d4: D10283FF  sub      sp, sp, #0xa0
//   0x14f3d8: F90043F4  str      x20, [sp, #0x80]
//   0x14f3dc: A9097BF3  stp      x19, x30, [sp, #0x90]
//   0x14f3e0: 9400A4AD  bl       #0x178694
static inline uint64_t fde_func_1265_0x14f3d4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x14f3d4ULL ^ (static_cast<uint64_t>(0xd10283ffULL) << 13);
    acc = (acc + a1 + 0xf90043f4ULL) ^ 0x089878ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1266 | PC: 0x14f570 | FDE: 0x0898f8 | Size: 256 bytes
// Khung tháo gỡ #1266 | Địa chỉ PC: 0x14f570 | Địa chỉ FDE: 0x0898f8 | Kích thước: 256 bytes
//   0x14f570: D102C3FF  sub      sp, sp, #0xb0
//   0x14f574: F9004BF4  str      x20, [sp, #0x90]
//   0x14f578: A90A7BF3  stp      x19, x30, [sp, #0xa0]
//   0x14f57c: 94009CE6  bl       #0x176914
static inline uint64_t fde_func_1266_0x14f570(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x14f570ULL ^ (static_cast<uint64_t>(0xd102c3ffULL) << 13);
    acc = (acc + a1 + 0xf9004bf4ULL) ^ 0x0898f8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1267 | PC: 0x14f778 | FDE: 0x089980 | Size: 256 bytes
// Khung tháo gỡ #1267 | Địa chỉ PC: 0x14f778 | Địa chỉ FDE: 0x089980 | Kích thước: 256 bytes
//   0x14f778: D10143FF  sub      sp, sp, #0x50
//   0x14f77c: F90013F6  str      x22, [sp, #0x20]
//   0x14f780: A90353F5  stp      x21, x20, [sp, #0x30]
//   0x14f784: A9047BF3  stp      x19, x30, [sp, #0x40]
static inline uint64_t fde_func_1267_0x14f778(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x14f778ULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xf90013f6ULL) ^ 0x089980ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1268 | PC: 0x14f88c | FDE: 0x0899f0 | Size: 128 bytes
// Khung tháo gỡ #1268 | Địa chỉ PC: 0x14f88c | Địa chỉ FDE: 0x0899f0 | Kích thước: 128 bytes
//   0x14f88c: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x14f890: A9420413  ldp      x19, x1, [x0, #0x20]
//   0x14f894: 9400A51F  bl       #0x178d10
//   0x14f898: 94009984  bl       #0x175ea8
static inline uint64_t fde_func_1268_0x14f88c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x14f88cULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0xa9420413ULL) ^ 0x0899f0ULL;
    acc ^= (acc >> 17) * 0x0080ULL;
    return acc;
}

// FDE #1269 | PC: 0x14f90c | FDE: 0x089a58 | Size: 144 bytes
// Khung tháo gỡ #1269 | Địa chỉ PC: 0x14f90c | Địa chỉ FDE: 0x089a58 | Kích thước: 144 bytes
//   0x14f90c: D1006000  sub      x0, x0, #0x18
//   0x14f910: 17FFFFDF  b        #0x14f88c
//   0x14f914: D1006000  sub      x0, x0, #0x18
//   0x14f918: 17FFFFE3  b        #0x14f8a4
static inline uint64_t fde_func_1269_0x14f90c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x14f90cULL ^ (static_cast<uint64_t>(0xd1006000ULL) << 13);
    acc = (acc + a1 + 0x17ffffdfULL) ^ 0x089a58ULL;
    acc ^= (acc >> 17) * 0x0090ULL;
    return acc;
}

// FDE #1270 | PC: 0x14f99c | FDE: 0x089ac0 | Size: 184 bytes
// Khung tháo gỡ #1270 | Địa chỉ PC: 0x14f99c | Địa chỉ FDE: 0x089ac0 | Kích thước: 184 bytes
//   0x14f99c: 91002000  add      x0, x0, #8
//   0x14f9a0: 1400DF70  b        #0x187760
//   0x14f9a4: A9BD5BF7  stp      x23, x22, [sp, #-0x30]!
//   0x14f9a8: A90153F5  stp      x21, x20, [sp, #0x10]
static inline uint64_t fde_func_1270_0x14f99c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x14f99cULL ^ (static_cast<uint64_t>(0x91002000ULL) << 13);
    acc = (acc + a1 + 0x1400df70ULL) ^ 0x089ac0ULL;
    acc ^= (acc >> 17) * 0x00b8ULL;
    return acc;
}

// FDE #1271 | PC: 0x14fa54 | FDE: 0x089b30 | Size: 172 bytes
// Khung tháo gỡ #1271 | Địa chỉ PC: 0x14fa54 | Địa chỉ FDE: 0x089b30 | Kích thước: 172 bytes
//   0x14fa54: F81E0FF4  str      x20, [sp, #-0x20]!
//   0x14fa58: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x14fa5c: A9408413  ldp      x19, x1, [x0, #8]
//   0x14fa60: AA0803F4  mov      x20, x8
static inline uint64_t fde_func_1271_0x14fa54(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x14fa54ULL ^ (static_cast<uint64_t>(0xf81e0ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x089b30ULL;
    acc ^= (acc >> 17) * 0x00acULL;
    return acc;
}

// FDE #1272 | PC: 0x14fb00 | FDE: 0x089ba8 | Size: 172 bytes
// Khung tháo gỡ #1272 | Địa chỉ PC: 0x14fb00 | Địa chỉ FDE: 0x089ba8 | Kích thước: 172 bytes
//   0x14fb00: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x14fb04: AA0003F3  mov      x19, x0
//   0x14fb08: 97FFFFF4  bl       #0x14fad8
//   0x14fb0c: AA1303E0  mov      x0, x19
static inline uint64_t fde_func_1272_0x14fb00(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x14fb00ULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0xaa0003f3ULL) ^ 0x089ba8ULL;
    acc ^= (acc >> 17) * 0x00acULL;
    return acc;
}

// FDE #1273 | PC: 0x14fbac | FDE: 0x089c20 | Size: 256 bytes
// Khung tháo gỡ #1273 | Địa chỉ PC: 0x14fbac | Địa chỉ FDE: 0x089c20 | Kích thước: 256 bytes
//   0x14fbac: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x14fbb0: 94009EF4  bl       #0x177780
//   0x14fbb4: B4000100  cbz      x0, #0x14fbd4
//   0x14fbb8: F9400008  ldr      x8, [x0]
static inline uint64_t fde_func_1273_0x14fbac(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x14fbacULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0x94009ef4ULL) ^ 0x089c20ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1274 | PC: 0x1500ec | FDE: 0x089c98 | Size: 256 bytes
// Khung tháo gỡ #1274 | Địa chỉ PC: 0x1500ec | Địa chỉ FDE: 0x089c98 | Kích thước: 256 bytes
//   0x1500ec: D10083FF  sub      sp, sp, #0x20
//   0x1500f0: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x1500f4: 9400C321  bl       #0x180d78
//   0x1500f8: AA0003E8  mov      x8, x0
static inline uint64_t fde_func_1274_0x1500ec(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1500ecULL ^ (static_cast<uint64_t>(0xd10083ffULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x089c98ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1275 | PC: 0x150228 | FDE: 0x089d00 | Size: 192 bytes
// Khung tháo gỡ #1275 | Địa chỉ PC: 0x150228 | Địa chỉ FDE: 0x089d00 | Kích thước: 192 bytes
//   0x150228: D100C3FF  sub      sp, sp, #0x30
//   0x15022c: A9027BF3  stp      x19, x30, [sp, #0x20]
//   0x150230: 9400A939  bl       #0x17a714
//   0x150234: 9400DCA3  bl       #0x1874c0
static inline uint64_t fde_func_1275_0x150228(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x150228ULL ^ (static_cast<uint64_t>(0xd100c3ffULL) << 13);
    acc = (acc + a1 + 0xa9027bf3ULL) ^ 0x089d00ULL;
    acc ^= (acc >> 17) * 0x00c0ULL;
    return acc;
}

// FDE #1276 | PC: 0x1502e8 | FDE: 0x089d68 | Size: 176 bytes
// Khung tháo gỡ #1276 | Địa chỉ PC: 0x1502e8 | Địa chỉ FDE: 0x089d68 | Kích thước: 176 bytes
//   0x1502e8: D100C3FF  sub      sp, sp, #0x30
//   0x1502ec: A9027BF3  stp      x19, x30, [sp, #0x20]
//   0x1502f0: 9400BBFA  bl       #0x17f2d8
//   0x1502f4: 97FFFFCD  bl       #0x150228
static inline uint64_t fde_func_1276_0x1502e8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1502e8ULL ^ (static_cast<uint64_t>(0xd100c3ffULL) << 13);
    acc = (acc + a1 + 0xa9027bf3ULL) ^ 0x089d68ULL;
    acc ^= (acc >> 17) * 0x00b0ULL;
    return acc;
}

// FDE #1277 | PC: 0x150398 | FDE: 0x089dd0 | Size: 240 bytes
// Khung tháo gỡ #1277 | Địa chỉ PC: 0x150398 | Địa chỉ FDE: 0x089dd0 | Kích thước: 240 bytes
//   0x150398: D100C3FF  sub      sp, sp, #0x30
//   0x15039c: A9027BF3  stp      x19, x30, [sp, #0x20]
//   0x1503a0: 9400A8DD  bl       #0x17a714
//   0x1503a4: 9400DC33  bl       #0x187470
static inline uint64_t fde_func_1277_0x150398(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x150398ULL ^ (static_cast<uint64_t>(0xd100c3ffULL) << 13);
    acc = (acc + a1 + 0xa9027bf3ULL) ^ 0x089dd0ULL;
    acc ^= (acc >> 17) * 0x00f0ULL;
    return acc;
}

// FDE #1278 | PC: 0x150488 | FDE: 0x089e38 | Size: 256 bytes
// Khung tháo gỡ #1278 | Địa chỉ PC: 0x150488 | Địa chỉ FDE: 0x089e38 | Kích thước: 256 bytes
//   0x150488: D10103FF  sub      sp, sp, #0x40
//   0x15048c: A90253F5  stp      x21, x20, [sp, #0x20]
//   0x150490: A9037BF3  stp      x19, x30, [sp, #0x30]
//   0x150494: 94009E75  bl       #0x177e68
static inline uint64_t fde_func_1278_0x150488(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x150488ULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xa90253f5ULL) ^ 0x089e38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1279 | PC: 0x15066c | FDE: 0x089eb8 | Size: 256 bytes
// Khung tháo gỡ #1279 | Địa chỉ PC: 0x15066c | Địa chỉ FDE: 0x089eb8 | Kích thước: 256 bytes
//   0x15066c: F81E0FF4  str      x20, [sp, #-0x20]!
//   0x150670: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x150674: 9400DAAF  bl       #0x187130
//   0x150678: 2A0203E1  mov      w1, w2
static inline uint64_t fde_func_1279_0x15066c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x15066cULL ^ (static_cast<uint64_t>(0xf81e0ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x089eb8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1280 | PC: 0x150978 | FDE: 0x089f40 | Size: 244 bytes
// Khung tháo gỡ #1280 | Địa chỉ PC: 0x150978 | Địa chỉ FDE: 0x089f40 | Kích thước: 244 bytes
//   0x150978: F81E0FF4  str      x20, [sp, #-0x20]!
//   0x15097c: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x150980: F9400408  ldr      x8, [x0, #8]
//   0x150984: EB01011F  cmp      x8, x1
static inline uint64_t fde_func_1280_0x150978(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x150978ULL ^ (static_cast<uint64_t>(0xf81e0ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x089f40ULL;
    acc ^= (acc >> 17) * 0x00f4ULL;
    return acc;
}

// FDE #1281 | PC: 0x150a6c | FDE: 0x089fb0 | Size: 208 bytes
// Khung tháo gỡ #1281 | Địa chỉ PC: 0x150a6c | Địa chỉ FDE: 0x089fb0 | Kích thước: 208 bytes
//   0x150a6c: D100C3FF  sub      sp, sp, #0x30
//   0x150a70: F9000BF4  str      x20, [sp, #0x10]
//   0x150a74: A9027BF3  stp      x19, x30, [sp, #0x20]
//   0x150a78: 94009DBC  bl       #0x178168
static inline uint64_t fde_func_1281_0x150a6c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x150a6cULL ^ (static_cast<uint64_t>(0xd100c3ffULL) << 13);
    acc = (acc + a1 + 0xf9000bf4ULL) ^ 0x089fb0ULL;
    acc ^= (acc >> 17) * 0x00d0ULL;
    return acc;
}

// FDE #1282 | PC: 0x150b3c | FDE: 0x08a020 | Size: 44 bytes
// Khung tháo gỡ #1282 | Địa chỉ PC: 0x150b3c | Địa chỉ FDE: 0x08a020 | Kích thước: 44 bytes
//   0x150b3c: AA0103E0  mov      x0, x1
//   0x150b40: 17FD675C  b        #0xaa8b0
//   0x150b44: AA0103E0  mov      x0, x1
//   0x150b48: 17FD6735  b        #0xaa81c
static inline uint64_t fde_func_1282_0x150b3c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x150b3cULL ^ (static_cast<uint64_t>(0xaa0103e0ULL) << 13);
    acc = (acc + a1 + 0x17fd675cULL) ^ 0x08a020ULL;
    acc ^= (acc >> 17) * 0x002cULL;
    return acc;
}

// FDE #1283 | PC: 0x150b68 | FDE: 0x08a080 | Size: 64 bytes
// Khung tháo gỡ #1283 | Địa chỉ PC: 0x150b68 | Địa chỉ FDE: 0x08a080 | Kích thước: 64 bytes
//   0x150b68: AA0103E0  mov      x0, x1
//   0x150b6c: 17FD6B35  b        #0xab840
//   0x150b70: AA0103E0  mov      x0, x1
//   0x150b74: 17FF4ECC  b        #0x1246a4
static inline uint64_t fde_func_1283_0x150b68(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x150b68ULL ^ (static_cast<uint64_t>(0xaa0103e0ULL) << 13);
    acc = (acc + a1 + 0x17fd6b35ULL) ^ 0x08a080ULL;
    acc ^= (acc >> 17) * 0x0040ULL;
    return acc;
}

// FDE #1284 | PC: 0x150ba8 | FDE: 0x08a0e0 | Size: 248 bytes
// Khung tháo gỡ #1284 | Địa chỉ PC: 0x150ba8 | Địa chỉ FDE: 0x08a0e0 | Kích thước: 248 bytes
//   0x150ba8: F81E0FF4  str      x20, [sp, #-0x20]!
//   0x150bac: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x150bb0: AA0003F3  mov      x19, x0
//   0x150bb4: B40000F3  cbz      x19, #0x150bd0
static inline uint64_t fde_func_1284_0x150ba8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x150ba8ULL ^ (static_cast<uint64_t>(0xf81e0ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x08a0e0ULL;
    acc ^= (acc >> 17) * 0x00f8ULL;
    return acc;
}

// FDE #1285 | PC: 0x150ca0 | FDE: 0x08a150 | Size: 160 bytes
// Khung tháo gỡ #1285 | Địa chỉ PC: 0x150ca0 | Địa chỉ FDE: 0x08a150 | Kích thước: 160 bytes
//   0x150ca0: D100C3FF  sub      sp, sp, #0x30
//   0x150ca4: F90013FE  str      x30, [sp, #0x20]
//   0x150ca8: F0FFF6C9  adrp     x9, #0x2b000
//   0x150cac: 9400B915  bl       #0x17f100
static inline uint64_t fde_func_1285_0x150ca0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x150ca0ULL ^ (static_cast<uint64_t>(0xd100c3ffULL) << 13);
    acc = (acc + a1 + 0xf90013feULL) ^ 0x08a150ULL;
    acc ^= (acc >> 17) * 0x00a0ULL;
    return acc;
}

// FDE #1286 | PC: 0x150d40 | FDE: 0x08a1b0 | Size: 244 bytes
// Khung tháo gỡ #1286 | Địa chỉ PC: 0x150d40 | Địa chỉ FDE: 0x08a1b0 | Kích thước: 244 bytes
//   0x150d40: D100C3FF  sub      sp, sp, #0x30
//   0x150d44: F90013FE  str      x30, [sp, #0x20]
//   0x150d48: F0FFF6C9  adrp     x9, #0x2b000
//   0x150d4c: 9400B8ED  bl       #0x17f100
static inline uint64_t fde_func_1286_0x150d40(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x150d40ULL ^ (static_cast<uint64_t>(0xd100c3ffULL) << 13);
    acc = (acc + a1 + 0xf90013feULL) ^ 0x08a1b0ULL;
    acc ^= (acc >> 17) * 0x00f4ULL;
    return acc;
}

// FDE #1287 | PC: 0x150e34 | FDE: 0x08a210 | Size: 160 bytes
// Khung tháo gỡ #1287 | Địa chỉ PC: 0x150e34 | Địa chỉ FDE: 0x08a210 | Kích thước: 160 bytes
//   0x150e34: D10103FF  sub      sp, sp, #0x40
//   0x150e38: F9000BF6  str      x22, [sp, #0x10]
//   0x150e3c: A90253F5  stp      x21, x20, [sp, #0x20]
//   0x150e40: A9037BF3  stp      x19, x30, [sp, #0x30]
static inline uint64_t fde_func_1287_0x150e34(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x150e34ULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xf9000bf6ULL) ^ 0x08a210ULL;
    acc ^= (acc >> 17) * 0x00a0ULL;
    return acc;
}

// FDE #1288 | PC: 0x150ed4 | FDE: 0x08a278 | Size: 108 bytes
// Khung tháo gỡ #1288 | Địa chỉ PC: 0x150ed4 | Địa chỉ FDE: 0x08a278 | Kích thước: 108 bytes
//   0x150ed4: AA0103E0  mov      x0, x1
//   0x150ed8: AA0203E1  mov      x1, x2
//   0x150edc: 17FE01EE  b        #0xd1694
//   0x150ee0: AA0103E0  mov      x0, x1
static inline uint64_t fde_func_1288_0x150ed4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x150ed4ULL ^ (static_cast<uint64_t>(0xaa0103e0ULL) << 13);
    acc = (acc + a1 + 0xaa0203e1ULL) ^ 0x08a278ULL;
    acc ^= (acc >> 17) * 0x006cULL;
    return acc;
}

// FDE #1289 | PC: 0x150f40 | FDE: 0x08a2e0 | Size: 152 bytes
// Khung tháo gỡ #1289 | Địa chỉ PC: 0x150f40 | Địa chỉ FDE: 0x08a2e0 | Kích thước: 152 bytes
//   0x150f40: F81E0FF4  str      x20, [sp, #-0x20]!
//   0x150f44: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x150f48: AA0103F4  mov      x20, x1
//   0x150f4c: AA0103E0  mov      x0, x1
static inline uint64_t fde_func_1289_0x150f40(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x150f40ULL ^ (static_cast<uint64_t>(0xf81e0ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x08a2e0ULL;
    acc ^= (acc >> 17) * 0x0098ULL;
    return acc;
}

// FDE #1290 | PC: 0x150fd8 | FDE: 0x08a350 | Size: 256 bytes
// Khung tháo gỡ #1290 | Địa chỉ PC: 0x150fd8 | Địa chỉ FDE: 0x08a350 | Kích thước: 256 bytes
//   0x150fd8: AA0103E0  mov      x0, x1
//   0x150fdc: AA0203E1  mov      x1, x2
//   0x150fe0: 17FF4D96  b        #0x124638
//   0x150fe4: AA0103E0  mov      x0, x1
static inline uint64_t fde_func_1290_0x150fd8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x150fd8ULL ^ (static_cast<uint64_t>(0xaa0103e0ULL) << 13);
    acc = (acc + a1 + 0xaa0203e1ULL) ^ 0x08a350ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1291 | PC: 0x151234 | FDE: 0x08a3d0 | Size: 176 bytes
// Khung tháo gỡ #1291 | Địa chỉ PC: 0x151234 | Địa chỉ FDE: 0x08a3d0 | Kích thước: 176 bytes
//   0x151234: D10103FF  sub      sp, sp, #0x40
//   0x151238: F9000BF6  str      x22, [sp, #0x10]
//   0x15123c: A90253F5  stp      x21, x20, [sp, #0x20]
//   0x151240: A9037BF3  stp      x19, x30, [sp, #0x30]
static inline uint64_t fde_func_1291_0x151234(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x151234ULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xf9000bf6ULL) ^ 0x08a3d0ULL;
    acc ^= (acc >> 17) * 0x00b0ULL;
    return acc;
}

// FDE #1292 | PC: 0x1512e4 | FDE: 0x08a438 | Size: 220 bytes
// Khung tháo gỡ #1292 | Địa chỉ PC: 0x1512e4 | Địa chỉ FDE: 0x08a438 | Kích thước: 220 bytes
//   0x1512e4: F9400048  ldr      x8, [x2]
//   0x1512e8: F900005F  str      xzr, [x2]
//   0x1512ec: 1400A789  b        #0x17b110
//   0x1512f0: AA0103E0  mov      x0, x1
static inline uint64_t fde_func_1292_0x1512e4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1512e4ULL ^ (static_cast<uint64_t>(0xf9400048ULL) << 13);
    acc = (acc + a1 + 0xf900005fULL) ^ 0x08a438ULL;
    acc ^= (acc >> 17) * 0x00dcULL;
    return acc;
}

// FDE #1293 | PC: 0x1513c0 | FDE: 0x08a4a8 | Size: 256 bytes
// Khung tháo gỡ #1293 | Địa chỉ PC: 0x1513c0 | Địa chỉ FDE: 0x08a4a8 | Kích thước: 256 bytes
//   0x1513c0: F81E0FF4  str      x20, [sp, #-0x20]!
//   0x1513c4: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x1513c8: 940099BA  bl       #0x177ab0
//   0x1513cc: 7100051F  cmp      w8, #1
static inline uint64_t fde_func_1293_0x1513c0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1513c0ULL ^ (static_cast<uint64_t>(0xf81e0ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x08a4a8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1294 | PC: 0x1514c8 | FDE: 0x08a528 | Size: 256 bytes
// Khung tháo gỡ #1294 | Địa chỉ PC: 0x1514c8 | Địa chỉ FDE: 0x08a528 | Kích thước: 256 bytes
//   0x1514c8: F81E0FF4  str      x20, [sp, #-0x20]!
//   0x1514cc: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x1514d0: 94009978  bl       #0x177ab0
//   0x1514d4: 7100151F  cmp      w8, #5
static inline uint64_t fde_func_1294_0x1514c8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1514c8ULL ^ (static_cast<uint64_t>(0xf81e0ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x08a528ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1295 | PC: 0x1515d8 | FDE: 0x08a5a8 | Size: 256 bytes
// Khung tháo gỡ #1295 | Địa chỉ PC: 0x1515d8 | Địa chỉ FDE: 0x08a5a8 | Kích thước: 256 bytes
//   0x1515d8: F81E0FF4  str      x20, [sp, #-0x20]!
//   0x1515dc: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x1515e0: 94009934  bl       #0x177ab0
//   0x1515e4: 7100251F  cmp      w8, #9
static inline uint64_t fde_func_1295_0x1515d8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1515d8ULL ^ (static_cast<uint64_t>(0xf81e0ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x08a5a8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1296 | PC: 0x1516f0 | FDE: 0x08a628 | Size: 256 bytes
// Khung tháo gỡ #1296 | Địa chỉ PC: 0x1516f0 | Địa chỉ FDE: 0x08a628 | Kích thước: 256 bytes
//   0x1516f0: A9BE53F5  stp      x21, x20, [sp, #-0x20]!
//   0x1516f4: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x1516f8: 9400C428  bl       #0x182798
//   0x1516fc: 7100351F  cmp      w8, #0xd
static inline uint64_t fde_func_1296_0x1516f0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1516f0ULL ^ (static_cast<uint64_t>(0xa9be53f5ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x08a628ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1297 | PC: 0x1518b0 | FDE: 0x08a6a8 | Size: 256 bytes
// Khung tháo gỡ #1297 | Địa chỉ PC: 0x1518b0 | Địa chỉ FDE: 0x08a6a8 | Kích thước: 256 bytes
//   0x1518b0: AA1E03E3  mov      x3, x30
//   0x1518b4: 9400A67C  bl       #0x17b2a4
//   0x1518b8: AA0303FE  mov      x30, x3
//   0x1518bc: A9047BF3  stp      x19, x30, [sp, #0x40]
static inline uint64_t fde_func_1297_0x1518b0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1518b0ULL ^ (static_cast<uint64_t>(0xaa1e03e3ULL) << 13);
    acc = (acc + a1 + 0x9400a67cULL) ^ 0x08a6a8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1298 | PC: 0x151f14 | FDE: 0x08a718 | Size: 256 bytes
// Khung tháo gỡ #1298 | Địa chỉ PC: 0x151f14 | Địa chỉ FDE: 0x08a718 | Kích thước: 256 bytes
//   0x151f14: A9BE53F5  stp      x21, x20, [sp, #-0x20]!
//   0x151f18: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x151f1c: B40001A0  cbz      x0, #0x151f50
//   0x151f20: AA0103F3  mov      x19, x1
static inline uint64_t fde_func_1298_0x151f14(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x151f14ULL ^ (static_cast<uint64_t>(0xa9be53f5ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x08a718ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1299 | PC: 0x152360 | FDE: 0x08a788 | Size: 256 bytes
// Khung tháo gỡ #1299 | Địa chỉ PC: 0x152360 | Địa chỉ FDE: 0x08a788 | Kích thước: 256 bytes
//   0x152360: F81D0FF6  str      x22, [sp, #-0x30]!
//   0x152364: A90153F5  stp      x21, x20, [sp, #0x10]
//   0x152368: A9027BF3  stp      x19, x30, [sp, #0x20]
//   0x15236c: AA1F03F4  mov      x20, xzr
static inline uint64_t fde_func_1299_0x152360(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x152360ULL ^ (static_cast<uint64_t>(0xf81d0ff6ULL) << 13);
    acc = (acc + a1 + 0xa90153f5ULL) ^ 0x08a788ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1300 | PC: 0x1525e4 | FDE: 0x08a800 | Size: 256 bytes
// Khung tháo gỡ #1300 | Địa chỉ PC: 0x1525e4 | Địa chỉ FDE: 0x08a800 | Kích thước: 256 bytes
//   0x1525e4: D10183FF  sub      sp, sp, #0x60
//   0x1525e8: F9000BFA  str      x26, [sp, #0x10]
//   0x1525ec: A90263F9  stp      x25, x24, [sp, #0x20]
//   0x1525f0: A9035BF7  stp      x23, x22, [sp, #0x30]
static inline uint64_t fde_func_1300_0x1525e4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1525e4ULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xf9000bfaULL) ^ 0x08a800ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1301 | PC: 0x152884 | FDE: 0x08a888 | Size: 256 bytes
// Khung tháo gỡ #1301 | Địa chỉ PC: 0x152884 | Địa chỉ FDE: 0x08a888 | Kích thước: 256 bytes
//   0x152884: F81D0FF6  str      x22, [sp, #-0x30]!
//   0x152888: A90153F5  stp      x21, x20, [sp, #0x10]
//   0x15288c: A9027BF3  stp      x19, x30, [sp, #0x20]
//   0x152890: AA0203F3  mov      x19, x2
static inline uint64_t fde_func_1301_0x152884(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x152884ULL ^ (static_cast<uint64_t>(0xf81d0ff6ULL) << 13);
    acc = (acc + a1 + 0xa90153f5ULL) ^ 0x08a888ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1302 | PC: 0x1529ac | FDE: 0x08a8f0 | Size: 256 bytes
// Khung tháo gỡ #1302 | Địa chỉ PC: 0x1529ac | Địa chỉ FDE: 0x08a8f0 | Kích thước: 256 bytes
//   0x1529ac: A940240A  ldp      x10, x9, [x0]
//   0x1529b0: F100015F  cmp      x10, #0
//   0x1529b4: DA8A5548  cneg     x8, x10, mi
//   0x1529b8: F100013F  cmp      x9, #0
static inline uint64_t fde_func_1302_0x1529ac(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1529acULL ^ (static_cast<uint64_t>(0xa940240aULL) << 13);
    acc = (acc + a1 + 0xf100015fULL) ^ 0x08a8f0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1303 | PC: 0x152b48 | FDE: 0x08a950 | Size: 256 bytes
// Khung tháo gỡ #1303 | Địa chỉ PC: 0x152b48 | Địa chỉ FDE: 0x08a950 | Kích thước: 256 bytes
//   0x152b48: D10083FF  sub      sp, sp, #0x20
//   0x152b4c: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x152b50: B9400808  ldr      w8, [x0, #8]
//   0x152b54: 34000088  cbz      w8, #0x152b64
static inline uint64_t fde_func_1303_0x152b48(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x152b48ULL ^ (static_cast<uint64_t>(0xd10083ffULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x08a950ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1304 | PC: 0x152d3c | FDE: 0x08a9c0 | Size: 256 bytes
// Khung tháo gỡ #1304 | Địa chỉ PC: 0x152d3c | Địa chỉ FDE: 0x08a9c0 | Kích thước: 256 bytes
//   0x152d3c: F81C0FF8  str      x24, [sp, #-0x40]!
//   0x152d40: A9015BF7  stp      x23, x22, [sp, #0x10]
//   0x152d44: A90253F5  stp      x21, x20, [sp, #0x20]
//   0x152d48: A9037BF3  stp      x19, x30, [sp, #0x30]
static inline uint64_t fde_func_1304_0x152d3c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x152d3cULL ^ (static_cast<uint64_t>(0xf81c0ff8ULL) << 13);
    acc = (acc + a1 + 0xa9015bf7ULL) ^ 0x08a9c0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1305 | PC: 0x153018 | FDE: 0x08aa38 | Size: 256 bytes
// Khung tháo gỡ #1305 | Địa chỉ PC: 0x153018 | Địa chỉ FDE: 0x08aa38 | Kích thước: 256 bytes
//   0x153018: D10103FF  sub      sp, sp, #0x40
//   0x15301c: F9000BF6  str      x22, [sp, #0x10]
//   0x153020: A90253F5  stp      x21, x20, [sp, #0x20]
//   0x153024: A9037BF3  stp      x19, x30, [sp, #0x30]
static inline uint64_t fde_func_1305_0x153018(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x153018ULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xf9000bf6ULL) ^ 0x08aa38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1306 | PC: 0x15315c | FDE: 0x08aab0 | Size: 256 bytes
// Khung tháo gỡ #1306 | Địa chỉ PC: 0x15315c | Địa chỉ FDE: 0x08aab0 | Kích thước: 256 bytes
//   0x15315c: D100C3FF  sub      sp, sp, #0x30
//   0x153160: A90153F5  stp      x21, x20, [sp, #0x10]
//   0x153164: A9027BF3  stp      x19, x30, [sp, #0x20]
//   0x153168: F9409408  ldr      x8, [x0, #0x128]
static inline uint64_t fde_func_1306_0x15315c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x15315cULL ^ (static_cast<uint64_t>(0xd100c3ffULL) << 13);
    acc = (acc + a1 + 0xa90153f5ULL) ^ 0x08aab0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1307 | PC: 0x153928 | FDE: 0x08ab40 | Size: 256 bytes
// Khung tháo gỡ #1307 | Địa chỉ PC: 0x153928 | Địa chỉ FDE: 0x08ab40 | Kích thước: 256 bytes
//   0x153928: F81D0FF6  str      x22, [sp, #-0x30]!
//   0x15392c: A90153F5  stp      x21, x20, [sp, #0x10]
//   0x153930: A9027BF3  stp      x19, x30, [sp, #0x20]
//   0x153934: B4000180  cbz      x0, #0x153964
static inline uint64_t fde_func_1307_0x153928(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x153928ULL ^ (static_cast<uint64_t>(0xf81d0ff6ULL) << 13);
    acc = (acc + a1 + 0xa90153f5ULL) ^ 0x08ab40ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1308 | PC: 0x153b0c | FDE: 0x08abc8 | Size: 256 bytes
// Khung tháo gỡ #1308 | Địa chỉ PC: 0x153b0c | Địa chỉ FDE: 0x08abc8 | Kích thước: 256 bytes
//   0x153b0c: B40002C0  cbz      x0, #0x153b64
//   0x153b10: A9BE53F5  stp      x21, x20, [sp, #-0x20]!
//   0x153b14: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x153b18: 94008CD8  bl       #0x176e78
static inline uint64_t fde_func_1308_0x153b0c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x153b0cULL ^ (static_cast<uint64_t>(0xb40002c0ULL) << 13);
    acc = (acc + a1 + 0xa9be53f5ULL) ^ 0x08abc8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1309 | PC: 0x153c0c | FDE: 0x08ac38 | Size: 256 bytes
// Khung tháo gỡ #1309 | Địa chỉ PC: 0x153c0c | Địa chỉ FDE: 0x08ac38 | Kích thước: 256 bytes
//   0x153c0c: 39404008  ldrb     w8, [x0, #0x10]
//   0x153c10: 37080068  tbnz     w8, #1, #0x153c1c
//   0x153c14: 52800468  mov      w8, #0x23
//   0x153c18: 14000004  b        #0x153c28
static inline uint64_t fde_func_1309_0x153c0c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x153c0cULL ^ (static_cast<uint64_t>(0x39404008ULL) << 13);
    acc = (acc + a1 + 0x37080068ULL) ^ 0x08ac38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1310 | PC: 0x154074 | FDE: 0x08acb0 | Size: 256 bytes
// Khung tháo gỡ #1310 | Địa chỉ PC: 0x154074 | Địa chỉ FDE: 0x08acb0 | Kích thước: 256 bytes
//   0x154074: F81F0FFE  str      x30, [sp, #-0x10]!
//   0x154078: B4000060  cbz      x0, #0x154084
//   0x15407c: 39404008  ldrb     w8, [x0, #0x10]
//   0x154080: 37080068  tbnz     w8, #1, #0x15408c
static inline uint64_t fde_func_1310_0x154074(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x154074ULL ^ (static_cast<uint64_t>(0xf81f0ffeULL) << 13);
    acc = (acc + a1 + 0xb4000060ULL) ^ 0x08acb0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1311 | PC: 0x154364 | FDE: 0x08ad30 | Size: 256 bytes
// Khung tháo gỡ #1311 | Địa chỉ PC: 0x154364 | Địa chỉ FDE: 0x08ad30 | Kích thước: 256 bytes
//   0x154364: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x154368: 528E8D81  mov      w1, #0x746c
//   0x15436c: 72ADEEA1  movk     w1, #0x6f75, lsl #16
//   0x154370: AA1F03E2  mov      x2, xzr
static inline uint64_t fde_func_1311_0x154364(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x154364ULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0x528e8d81ULL) ^ 0x08ad30ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1312 | PC: 0x15467c | FDE: 0x08adb0 | Size: 256 bytes
// Khung tháo gỡ #1312 | Địa chỉ PC: 0x15467c | Địa chỉ FDE: 0x08adb0 | Kích thước: 256 bytes
//   0x15467c: AA1E03E4  mov      x4, x30
//   0x154680: 94008DD4  bl       #0x177dd0
//   0x154684: AA0403FE  mov      x30, x4
//   0x154688: A9047BF3  stp      x19, x30, [sp, #0x40]
static inline uint64_t fde_func_1312_0x15467c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x15467cULL ^ (static_cast<uint64_t>(0xaa1e03e4ULL) << 13);
    acc = (acc + a1 + 0x94008dd4ULL) ^ 0x08adb0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1313 | PC: 0x15499c | FDE: 0x08ae38 | Size: 256 bytes
// Khung tháo gỡ #1313 | Địa chỉ PC: 0x15499c | Địa chỉ FDE: 0x08ae38 | Kích thước: 256 bytes
//   0x15499c: A9BE53F5  stp      x21, x20, [sp, #-0x20]!
//   0x1549a0: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x1549a4: AA0103F5  mov      x21, x1
//   0x1549a8: D0FFF6C1  adrp     x1, #0x2e000
static inline uint64_t fde_func_1313_0x15499c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x15499cULL ^ (static_cast<uint64_t>(0xa9be53f5ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x08ae38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1314 | PC: 0x154bd4 | FDE: 0x08aeb0 | Size: 256 bytes
// Khung tháo gỡ #1314 | Địa chỉ PC: 0x154bd4 | Địa chỉ FDE: 0x08aeb0 | Kích thước: 256 bytes
//   0x154bd4: B7F80081  tbnz     x1, #0x3f, #0x154be4
//   0x154bd8: F9400808  ldr      x8, [x0, #0x10]
//   0x154bdc: 8B010101  add      x1, x8, x1
//   0x154be0: 17FFFFE6  b        #0x154b78
static inline uint64_t fde_func_1314_0x154bd4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x154bd4ULL ^ (static_cast<uint64_t>(0xb7f80081ULL) << 13);
    acc = (acc + a1 + 0xf9400808ULL) ^ 0x08aeb0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1315 | PC: 0x154da0 | FDE: 0x08af28 | Size: 256 bytes
// Khung tháo gỡ #1315 | Địa chỉ PC: 0x154da0 | Địa chỉ FDE: 0x08af28 | Kích thước: 256 bytes
//   0x154da0: F81E0FF4  str      x20, [sp, #-0x20]!
//   0x154da4: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x154da8: 9400966E  bl       #0x17a760
//   0x154dac: 94000007  bl       #0x154dc8
static inline uint64_t fde_func_1315_0x154da0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x154da0ULL ^ (static_cast<uint64_t>(0xf81e0ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x08af28ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1316 | PC: 0x154f1c | FDE: 0x08af98 | Size: 256 bytes
// Khung tháo gỡ #1316 | Địa chỉ PC: 0x154f1c | Địa chỉ FDE: 0x08af98 | Kích thước: 256 bytes
//   0x154f1c: A9442009  ldp      x9, x8, [x0, #0x40]
//   0x154f20: 9100052A  add      x10, x9, #1
//   0x154f24: EB08015F  cmp      x10, x8
//   0x154f28: 540000C2  b.hs     #0x154f40
static inline uint64_t fde_func_1316_0x154f1c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x154f1cULL ^ (static_cast<uint64_t>(0xa9442009ULL) << 13);
    acc = (acc + a1 + 0x9100052aULL) ^ 0x08af98ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1317 | PC: 0x1551e8 | FDE: 0x08b010 | Size: 256 bytes
// Khung tháo gỡ #1317 | Địa chỉ PC: 0x1551e8 | Địa chỉ FDE: 0x08b010 | Kích thước: 256 bytes
//   0x1551e8: D100C3FF  sub      sp, sp, #0x30
//   0x1551ec: A9027BF3  stp      x19, x30, [sp, #0x20]
//   0x1551f0: 9400A84C  bl       #0x17f320
//   0x1551f4: F94007E0  ldr      x0, [sp, #8]
static inline uint64_t fde_func_1317_0x1551e8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1551e8ULL ^ (static_cast<uint64_t>(0xd100c3ffULL) << 13);
    acc = (acc + a1 + 0xa9027bf3ULL) ^ 0x08b010ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1318 | PC: 0x155324 | FDE: 0x08b070 | Size: 256 bytes
// Khung tháo gỡ #1318 | Địa chỉ PC: 0x155324 | Địa chỉ FDE: 0x08b070 | Kích thước: 256 bytes
//   0x155324: AA000028  orr      x8, x1, x0
//   0x155328: B4000128  cbz      x8, #0x15534c
//   0x15532c: D10083FF  sub      sp, sp, #0x20
//   0x155330: A900FBE1  stp      x1, x30, [sp, #8]
static inline uint64_t fde_func_1318_0x155324(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x155324ULL ^ (static_cast<uint64_t>(0xaa000028ULL) << 13);
    acc = (acc + a1 + 0xb4000128ULL) ^ 0x08b070ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1319 | PC: 0x1554ac | FDE: 0x08b0e0 | Size: 256 bytes
// Khung tháo gỡ #1319 | Địa chỉ PC: 0x1554ac | Địa chỉ FDE: 0x08b0e0 | Kích thước: 256 bytes
//   0x1554ac: F100085F  cmp      x2, #2
//   0x1554b0: 540000E3  b.lo     #0x1554cc
//   0x1554b4: 39400028  ldrb     w8, [x1]
//   0x1554b8: 340000A8  cbz      w8, #0x1554cc
static inline uint64_t fde_func_1319_0x1554ac(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1554acULL ^ (static_cast<uint64_t>(0xf100085fULL) << 13);
    acc = (acc + a1 + 0x540000e3ULL) ^ 0x08b0e0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1320 | PC: 0x1556e4 | FDE: 0x08b158 | Size: 256 bytes
// Khung tháo gỡ #1320 | Địa chỉ PC: 0x1556e4 | Địa chỉ FDE: 0x08b158 | Kích thước: 256 bytes
//   0x1556e4: D100C3FF  sub      sp, sp, #0x30
//   0x1556e8: A90153F5  stp      x21, x20, [sp, #0x10]
//   0x1556ec: A9027BF3  stp      x19, x30, [sp, #0x20]
//   0x1556f0: AA0003F5  mov      x21, x0
static inline uint64_t fde_func_1320_0x1556e4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1556e4ULL ^ (static_cast<uint64_t>(0xd100c3ffULL) << 13);
    acc = (acc + a1 + 0xa90153f5ULL) ^ 0x08b158ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1321 | PC: 0x1557fc | FDE: 0x08b1c8 | Size: 200 bytes
// Khung tháo gỡ #1321 | Địa chỉ PC: 0x1557fc | Địa chỉ FDE: 0x08b1c8 | Kích thước: 200 bytes
//   0x1557fc: B9402809  ldr      w9, [x0, #0x28]
//   0x155800: F9400008  ldr      x8, [x0]
//   0x155804: 9100C022  add      x2, x1, #0x30
//   0x155808: B9002829  str      w9, [x1, #0x28]
static inline uint64_t fde_func_1321_0x1557fc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1557fcULL ^ (static_cast<uint64_t>(0xb9402809ULL) << 13);
    acc = (acc + a1 + 0xf9400008ULL) ^ 0x08b1c8ULL;
    acc ^= (acc >> 17) * 0x00c8ULL;
    return acc;
}

// FDE #1322 | PC: 0x1558c4 | FDE: 0x08b230 | Size: 188 bytes
// Khung tháo gỡ #1322 | Địa chỉ PC: 0x1558c4 | Địa chỉ FDE: 0x08b230 | Kích thước: 188 bytes
//   0x1558c4: A9BE53F5  stp      x21, x20, [sp, #-0x20]!
//   0x1558c8: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x1558cc: AA0003F3  mov      x19, x0
//   0x1558d0: F9400008  ldr      x8, [x0]
static inline uint64_t fde_func_1322_0x1558c4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1558c4ULL ^ (static_cast<uint64_t>(0xa9be53f5ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x08b230ULL;
    acc ^= (acc >> 17) * 0x00bcULL;
    return acc;
}

// FDE #1323 | PC: 0x155980 | FDE: 0x08b2a0 | Size: 256 bytes
// Khung tháo gỡ #1323 | Địa chỉ PC: 0x155980 | Địa chỉ FDE: 0x08b2a0 | Kích thước: 256 bytes
//   0x155980: F81D0FF6  str      x22, [sp, #-0x30]!
//   0x155984: A90153F5  stp      x21, x20, [sp, #0x10]
//   0x155988: A9027BF3  stp      x19, x30, [sp, #0x20]
//   0x15598c: B4000280  cbz      x0, #0x1559dc
static inline uint64_t fde_func_1323_0x155980(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x155980ULL ^ (static_cast<uint64_t>(0xf81d0ff6ULL) << 13);
    acc = (acc + a1 + 0xa90153f5ULL) ^ 0x08b2a0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1324 | PC: 0x155b90 | FDE: 0x08b318 | Size: 256 bytes
// Khung tháo gỡ #1324 | Địa chỉ PC: 0x155b90 | Địa chỉ FDE: 0x08b318 | Kích thước: 256 bytes
//   0x155b90: F81E0FF4  str      x20, [sp, #-0x20]!
//   0x155b94: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x155b98: F9400401  ldr      x1, [x0, #8]
//   0x155b9c: F9401014  ldr      x20, [x0, #0x20]
static inline uint64_t fde_func_1324_0x155b90(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x155b90ULL ^ (static_cast<uint64_t>(0xf81e0ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x08b318ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1325 | PC: 0x1560e0 | FDE: 0x08b3b0 | Size: 256 bytes
// Khung tháo gỡ #1325 | Địa chỉ PC: 0x1560e0 | Địa chỉ FDE: 0x08b3b0 | Kích thước: 256 bytes
//   0x1560e0: F81D0FF6  str      x22, [sp, #-0x30]!
//   0x1560e4: A90153F5  stp      x21, x20, [sp, #0x10]
//   0x1560e8: A9027BF3  stp      x19, x30, [sp, #0x20]
//   0x1560ec: 39406008  ldrb     w8, [x0, #0x18]
static inline uint64_t fde_func_1325_0x1560e0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1560e0ULL ^ (static_cast<uint64_t>(0xf81d0ff6ULL) << 13);
    acc = (acc + a1 + 0xa90153f5ULL) ^ 0x08b3b0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1326 | PC: 0x156480 | FDE: 0x08b440 | Size: 256 bytes
// Khung tháo gỡ #1326 | Địa chỉ PC: 0x156480 | Địa chỉ FDE: 0x08b440 | Kích thước: 256 bytes
//   0x156480: F81E0FF4  str      x20, [sp, #-0x20]!
//   0x156484: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x156488: B9401C08  ldr      w8, [x0, #0x1c]
//   0x15648c: 94007DDA  bl       #0x175bf4
static inline uint64_t fde_func_1326_0x156480(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x156480ULL ^ (static_cast<uint64_t>(0xf81e0ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x08b440ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1327 | PC: 0x156ad4 | FDE: 0x08b4c8 | Size: 256 bytes
// Khung tháo gỡ #1327 | Địa chỉ PC: 0x156ad4 | Địa chỉ FDE: 0x08b4c8 | Kích thước: 256 bytes
//   0x156ad4: AA1E03E4  mov      x4, x30
//   0x156ad8: 94007CDC  bl       #0x175e48
//   0x156adc: AA0403FE  mov      x30, x4
//   0x156ae0: A9057BFD  stp      x29, x30, [sp, #0x50]
static inline uint64_t fde_func_1327_0x156ad4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x156ad4ULL ^ (static_cast<uint64_t>(0xaa1e03e4ULL) << 13);
    acc = (acc + a1 + 0x94007cdcULL) ^ 0x08b4c8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1328 | PC: 0x157940 | FDE: 0x08b560 | Size: 148 bytes
// Khung tháo gỡ #1328 | Địa chỉ PC: 0x157940 | Địa chỉ FDE: 0x08b560 | Kích thước: 148 bytes
//   0x157940: A9BE53F5  stp      x21, x20, [sp, #-0x20]!
//   0x157944: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x157948: 94009922  bl       #0x17ddd0
//   0x15794c: B50000C3  cbnz     x3, #0x157964
static inline uint64_t fde_func_1328_0x157940(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x157940ULL ^ (static_cast<uint64_t>(0xa9be53f5ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x08b560ULL;
    acc ^= (acc >> 17) * 0x0094ULL;
    return acc;
}

// FDE #1329 | PC: 0x1579d4 | FDE: 0x08b5c8 | Size: 160 bytes
// Khung tháo gỡ #1329 | Địa chỉ PC: 0x1579d4 | Địa chỉ FDE: 0x08b5c8 | Kích thước: 160 bytes
//   0x1579d4: F9400008  ldr      x8, [x0]
//   0x1579d8: F9423D08  ldr      x8, [x8, #0x478]
//   0x1579dc: 910C3108  add      x8, x8, #0x30c
//   0x1579e0: F9000C08  str      x8, [x0, #0x18]
static inline uint64_t fde_func_1329_0x1579d4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1579d4ULL ^ (static_cast<uint64_t>(0xf9400008ULL) << 13);
    acc = (acc + a1 + 0xf9423d08ULL) ^ 0x08b5c8ULL;
    acc ^= (acc >> 17) * 0x00a0ULL;
    return acc;
}

// FDE #1330 | PC: 0x157a74 | FDE: 0x08b628 | Size: 92 bytes
// Khung tháo gỡ #1330 | Địa chỉ PC: 0x157a74 | Địa chỉ FDE: 0x08b628 | Kích thước: 92 bytes
//   0x157a74: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x157a78: F9401001  ldr      x1, [x0, #0x20]
//   0x157a7c: AA0003F3  mov      x19, x0
//   0x157a80: B4000081  cbz      x1, #0x157a90
static inline uint64_t fde_func_1330_0x157a74(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x157a74ULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0xf9401001ULL) ^ 0x08b628ULL;
    acc ^= (acc >> 17) * 0x005cULL;
    return acc;
}

// FDE #1331 | PC: 0x157ad0 | FDE: 0x08b688 | Size: 256 bytes
// Khung tháo gỡ #1331 | Địa chỉ PC: 0x157ad0 | Địa chỉ FDE: 0x08b688 | Kích thước: 256 bytes
//   0x157ad0: 529FFFE8  mov      w8, #0xffff
//   0x157ad4: 6B08003F  cmp      w1, w8
//   0x157ad8: 54000041  b.ne     #0x157ae0
//   0x157adc: 140083DF  b        #0x178a58
static inline uint64_t fde_func_1331_0x157ad0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x157ad0ULL ^ (static_cast<uint64_t>(0x529fffe8ULL) << 13);
    acc = (acc + a1 + 0x6b08003fULL) ^ 0x08b688ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1332 | PC: 0x159630 | FDE: 0x08b708 | Size: 256 bytes
// Khung tháo gỡ #1332 | Địa chỉ PC: 0x159630 | Địa chỉ FDE: 0x08b708 | Kích thước: 256 bytes
//   0x159630: F81C0FF8  str      x24, [sp, #-0x40]!
//   0x159634: A9015BF7  stp      x23, x22, [sp, #0x10]
//   0x159638: A90253F5  stp      x21, x20, [sp, #0x20]
//   0x15963c: A9037BF3  stp      x19, x30, [sp, #0x30]
static inline uint64_t fde_func_1332_0x159630(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x159630ULL ^ (static_cast<uint64_t>(0xf81c0ff8ULL) << 13);
    acc = (acc + a1 + 0xa9015bf7ULL) ^ 0x08b708ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1333 | PC: 0x159a10 | FDE: 0x08b7a0 | Size: 256 bytes
// Khung tháo gỡ #1333 | Địa chỉ PC: 0x159a10 | Địa chỉ FDE: 0x08b7a0 | Kích thước: 256 bytes
//   0x159a10: F9409408  ldr      x8, [x0, #0x128]
//   0x159a14: B4000048  cbz      x8, #0x159a1c
//   0x159a18: F900211F  str      xzr, [x8, #0x40]
//   0x159a1c: D65F03C0  ret      
static inline uint64_t fde_func_1333_0x159a10(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x159a10ULL ^ (static_cast<uint64_t>(0xf9409408ULL) << 13);
    acc = (acc + a1 + 0xb4000048ULL) ^ 0x08b7a0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1334 | PC: 0x15a2a8 | FDE: 0x08b828 | Size: 256 bytes
// Khung tháo gỡ #1334 | Địa chỉ PC: 0x15a2a8 | Địa chỉ FDE: 0x08b828 | Kích thước: 256 bytes
//   0x15a2a8: AA1E03E2  mov      x2, x30
//   0x15a2ac: 940084A0  bl       #0x17b52c
//   0x15a2b0: AA0203FE  mov      x30, x2
//   0x15a2b4: A9067BF3  stp      x19, x30, [sp, #0x60]
static inline uint64_t fde_func_1334_0x15a2a8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x15a2a8ULL ^ (static_cast<uint64_t>(0xaa1e03e2ULL) << 13);
    acc = (acc + a1 + 0x940084a0ULL) ^ 0x08b828ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1335 | PC: 0x15a520 | FDE: 0x08b8b0 | Size: 256 bytes
// Khung tháo gỡ #1335 | Địa chỉ PC: 0x15a520 | Địa chỉ FDE: 0x08b8b0 | Kích thước: 256 bytes
//   0x15a520: F9423C08  ldr      x8, [x0, #0x478]
//   0x15a524: 9114E100  add      x0, x8, #0x538
//   0x15a528: 14000009  b        #0x15a54c
//   0x15a52c: F9423C08  ldr      x8, [x0, #0x478]
static inline uint64_t fde_func_1335_0x15a520(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x15a520ULL ^ (static_cast<uint64_t>(0xf9423c08ULL) << 13);
    acc = (acc + a1 + 0x9114e100ULL) ^ 0x08b8b0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1336 | PC: 0x15a6bc | FDE: 0x08b920 | Size: 256 bytes
// Khung tháo gỡ #1336 | Địa chỉ PC: 0x15a6bc | Địa chỉ FDE: 0x08b920 | Kích thước: 256 bytes
//   0x15a6bc: D100C3FF  sub      sp, sp, #0x30
//   0x15a6c0: A90153F5  stp      x21, x20, [sp, #0x10]
//   0x15a6c4: A9027BF3  stp      x19, x30, [sp, #0x20]
//   0x15a6c8: D53BD055  mrs      x21, tpidr_el0
static inline uint64_t fde_func_1336_0x15a6bc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x15a6bcULL ^ (static_cast<uint64_t>(0xd100c3ffULL) << 13);
    acc = (acc + a1 + 0xa90153f5ULL) ^ 0x08b920ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1337 | PC: 0x15a8fc | FDE: 0x08b9a0 | Size: 256 bytes
// Khung tháo gỡ #1337 | Địa chỉ PC: 0x15a8fc | Địa chỉ FDE: 0x08b9a0 | Kích thước: 256 bytes
//   0x15a8fc: F81D0FF6  str      x22, [sp, #-0x30]!
//   0x15a900: A90153F5  stp      x21, x20, [sp, #0x10]
//   0x15a904: A9027BF3  stp      x19, x30, [sp, #0x20]
//   0x15a908: F9400C08  ldr      x8, [x0, #0x18]
static inline uint64_t fde_func_1337_0x15a8fc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x15a8fcULL ^ (static_cast<uint64_t>(0xf81d0ff6ULL) << 13);
    acc = (acc + a1 + 0xa90153f5ULL) ^ 0x08b9a0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1338 | PC: 0x15b0d8 | FDE: 0x08ba48 | Size: 256 bytes
// Khung tháo gỡ #1338 | Địa chỉ PC: 0x15b0d8 | Địa chỉ FDE: 0x08ba48 | Kích thước: 256 bytes
//   0x15b0d8: D100C3FF  sub      sp, sp, #0x30
//   0x15b0dc: A90153F5  stp      x21, x20, [sp, #0x10]
//   0x15b0e0: A9027BF3  stp      x19, x30, [sp, #0x20]
//   0x15b0e4: B9000FFF  str      wzr, [sp, #0xc]
static inline uint64_t fde_func_1338_0x15b0d8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x15b0d8ULL ^ (static_cast<uint64_t>(0xd100c3ffULL) << 13);
    acc = (acc + a1 + 0xa90153f5ULL) ^ 0x08ba48ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1339 | PC: 0x15b2a4 | FDE: 0x08bac8 | Size: 256 bytes
// Khung tháo gỡ #1339 | Địa chỉ PC: 0x15b2a4 | Địa chỉ FDE: 0x08bac8 | Kích thước: 256 bytes
//   0x15b2a4: AA1E03E3  mov      x3, x30
//   0x15b2a8: 94006AE8  bl       #0x175e48
//   0x15b2ac: AA0303FE  mov      x30, x3
//   0x15b2b0: A9057BFD  stp      x29, x30, [sp, #0x50]
static inline uint64_t fde_func_1339_0x15b2a4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x15b2a4ULL ^ (static_cast<uint64_t>(0xaa1e03e3ULL) << 13);
    acc = (acc + a1 + 0x94006ae8ULL) ^ 0x08bac8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1340 | PC: 0x15b7e0 | FDE: 0x08bb50 | Size: 256 bytes
// Khung tháo gỡ #1340 | Địa chỉ PC: 0x15b7e0 | Địa chỉ FDE: 0x08bb50 | Kích thước: 256 bytes
//   0x15b7e0: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x15b7e4: 39400028  ldrb     w8, [x1]
//   0x15b7e8: AA0203F3  mov      x19, x2
//   0x15b7ec: 7103FD1F  cmp      w8, #0xff
static inline uint64_t fde_func_1340_0x15b7e0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x15b7e0ULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0x39400028ULL) ^ 0x08bb50ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1341 | PC: 0x15bfac | FDE: 0x08bbd0 | Size: 256 bytes
// Khung tháo gỡ #1341 | Địa chỉ PC: 0x15bfac | Địa chỉ FDE: 0x08bbd0 | Kích thước: 256 bytes
//   0x15bfac: A9BE53F5  stp      x21, x20, [sp, #-0x20]!
//   0x15bfb0: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x15bfb4: A9422014  ldp      x20, x8, [x0, #0x20]
//   0x15bfb8: 91008289  add      x9, x20, #0x20
static inline uint64_t fde_func_1341_0x15bfac(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x15bfacULL ^ (static_cast<uint64_t>(0xa9be53f5ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x08bbd0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1342 | PC: 0x15c160 | FDE: 0x08bc50 | Size: 256 bytes
// Khung tháo gỡ #1342 | Địa chỉ PC: 0x15c160 | Địa chỉ FDE: 0x08bc50 | Kích thước: 256 bytes
//   0x15c160: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x15c164: F9401C13  ldr      x19, [x0, #0x38]
//   0x15c168: B40000F3  cbz      x19, #0x15c184
//   0x15c16c: 9400A139  bl       #0x184650
static inline uint64_t fde_func_1342_0x15c160(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x15c160ULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0xf9401c13ULL) ^ 0x08bc50ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1343 | PC: 0x15c46c | FDE: 0x08bcc8 | Size: 256 bytes
// Khung tháo gỡ #1343 | Địa chỉ PC: 0x15c46c | Địa chỉ FDE: 0x08bcc8 | Kích thước: 256 bytes
//   0x15c46c: AA1E03E4  mov      x4, x30
//   0x15c470: 94006A07  bl       #0x176c8c
//   0x15c474: AA0403FE  mov      x30, x4
//   0x15c478: A9087BFD  stp      x29, x30, [sp, #0x80]
static inline uint64_t fde_func_1343_0x15c46c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x15c46cULL ^ (static_cast<uint64_t>(0xaa1e03e4ULL) << 13);
    acc = (acc + a1 + 0x94006a07ULL) ^ 0x08bcc8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1344 | PC: 0x15c738 | FDE: 0x08bd48 | Size: 256 bytes
// Khung tháo gỡ #1344 | Địa chỉ PC: 0x15c738 | Địa chỉ FDE: 0x08bd48 | Kích thước: 256 bytes
//   0x15c738: F9423C08  ldr      x8, [x0, #0x478]
//   0x15c73c: B40001E8  cbz      x8, #0x15c778
//   0x15c740: B9474D09  ldr      w9, [x8, #0x74c]
//   0x15c744: 529FFFEA  mov      w10, #0xffff
static inline uint64_t fde_func_1344_0x15c738(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x15c738ULL ^ (static_cast<uint64_t>(0xf9423c08ULL) << 13);
    acc = (acc + a1 + 0xb40001e8ULL) ^ 0x08bd48ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1345 | PC: 0x15c950 | FDE: 0x08bdc0 | Size: 256 bytes
// Khung tháo gỡ #1345 | Địa chỉ PC: 0x15c950 | Địa chỉ FDE: 0x08bdc0 | Kích thước: 256 bytes
//   0x15c950: F81E0FF4  str      x20, [sp, #-0x20]!
//   0x15c954: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x15c958: F941B808  ldr      x8, [x0, #0x370]
//   0x15c95c: F9423C14  ldr      x20, [x0, #0x478]
static inline uint64_t fde_func_1345_0x15c950(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x15c950ULL ^ (static_cast<uint64_t>(0xf81e0ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x08bdc0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1346 | PC: 0x15cbb8 | FDE: 0x08be38 | Size: 228 bytes
// Khung tháo gỡ #1346 | Địa chỉ PC: 0x15cbb8 | Địa chỉ FDE: 0x08be38 | Kích thước: 228 bytes
//   0x15cbb8: F81F0FFE  str      x30, [sp, #-0x10]!
//   0x15cbbc: 9BA17C41  umull    x1, w2, w1
//   0x15cbc0: 910033E2  add      x2, sp, #0xc
//   0x15cbc4: 97FFD730  bl       #0x152884
static inline uint64_t fde_func_1346_0x15cbb8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x15cbb8ULL ^ (static_cast<uint64_t>(0xf81f0ffeULL) << 13);
    acc = (acc + a1 + 0x9ba17c41ULL) ^ 0x08be38ULL;
    acc ^= (acc >> 17) * 0x00e4ULL;
    return acc;
}

// FDE #1347 | PC: 0x15cc9c | FDE: 0x08bea0 | Size: 256 bytes
// Khung tháo gỡ #1347 | Địa chỉ PC: 0x15cc9c | Địa chỉ FDE: 0x08bea0 | Kích thước: 256 bytes
//   0x15cc9c: A9BD5BF7  stp      x23, x22, [sp, #-0x30]!
//   0x15cca0: A90153F5  stp      x21, x20, [sp, #0x10]
//   0x15cca4: A9027BF3  stp      x19, x30, [sp, #0x20]
//   0x15cca8: 37F802A1  tbnz     w1, #0x1f, #0x15ccfc
static inline uint64_t fde_func_1347_0x15cc9c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x15cc9cULL ^ (static_cast<uint64_t>(0xa9bd5bf7ULL) << 13);
    acc = (acc + a1 + 0xa90153f5ULL) ^ 0x08bea0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1348 | PC: 0x15ce94 | FDE: 0x08bf18 | Size: 256 bytes
// Khung tháo gỡ #1348 | Địa chỉ PC: 0x15ce94 | Địa chỉ FDE: 0x08bf18 | Kích thước: 256 bytes
//   0x15ce94: F9400801  ldr      x1, [x0, #0x10]
//   0x15ce98: 14000300  b        #0x15da98
//   0x15ce9c: F81E0FF4  str      x20, [sp, #-0x20]!
//   0x15cea0: A9017BF3  stp      x19, x30, [sp, #0x10]
static inline uint64_t fde_func_1348_0x15ce94(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x15ce94ULL ^ (static_cast<uint64_t>(0xf9400801ULL) << 13);
    acc = (acc + a1 + 0x14000300ULL) ^ 0x08bf18ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1349 | PC: 0x15d058 | FDE: 0x08bf88 | Size: 256 bytes
// Khung tháo gỡ #1349 | Địa chỉ PC: 0x15d058 | Địa chỉ FDE: 0x08bf88 | Kích thước: 256 bytes
//   0x15d058: D10103FF  sub      sp, sp, #0x40
//   0x15d05c: A9015BF7  stp      x23, x22, [sp, #0x10]
//   0x15d060: A90253F5  stp      x21, x20, [sp, #0x20]
//   0x15d064: A9037BF3  stp      x19, x30, [sp, #0x30]
static inline uint64_t fde_func_1349_0x15d058(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x15d058ULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xa9015bf7ULL) ^ 0x08bf88ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1350 | PC: 0x15d3f0 | FDE: 0x08c018 | Size: 256 bytes
// Khung tháo gỡ #1350 | Địa chỉ PC: 0x15d3f0 | Địa chỉ FDE: 0x08c018 | Kích thước: 256 bytes
//   0x15d3f0: AA1E03E4  mov      x4, x30
//   0x15d3f4: 94007636  bl       #0x17accc
//   0x15d3f8: AA0403FE  mov      x30, x4
//   0x15d3fc: A9067BF3  stp      x19, x30, [sp, #0x60]
static inline uint64_t fde_func_1350_0x15d3f0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x15d3f0ULL ^ (static_cast<uint64_t>(0xaa1e03e4ULL) << 13);
    acc = (acc + a1 + 0x94007636ULL) ^ 0x08c018ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1351 | PC: 0x15db08 | FDE: 0x08c0c0 | Size: 256 bytes
// Khung tháo gỡ #1351 | Địa chỉ PC: 0x15db08 | Địa chỉ FDE: 0x08c0c0 | Kích thước: 256 bytes
//   0x15db08: AA1E03E3  mov      x3, x30
//   0x15db0c: 9400637C  bl       #0x1768fc
//   0x15db10: AA0303FE  mov      x30, x3
//   0x15db14: A9057BF3  stp      x19, x30, [sp, #0x50]
static inline uint64_t fde_func_1351_0x15db08(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x15db08ULL ^ (static_cast<uint64_t>(0xaa1e03e3ULL) << 13);
    acc = (acc + a1 + 0x9400637cULL) ^ 0x08c0c0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1352 | PC: 0x15e08c | FDE: 0x08c158 | Size: 256 bytes
// Khung tháo gỡ #1352 | Địa chỉ PC: 0x15e08c | Địa chỉ FDE: 0x08c158 | Kích thước: 256 bytes
//   0x15e08c: F9400008  ldr      x8, [x0]
//   0x15e090: EB01011F  cmp      x8, x1
//   0x15e094: 540000E2  b.hs     #0x15e0b0
//   0x15e098: 39400109  ldrb     w9, [x8]
static inline uint64_t fde_func_1352_0x15e08c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x15e08cULL ^ (static_cast<uint64_t>(0xf9400008ULL) << 13);
    acc = (acc + a1 + 0xeb01011fULL) ^ 0x08c158ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1353 | PC: 0x15e2e4 | FDE: 0x08c1c8 | Size: 256 bytes
// Khung tháo gỡ #1353 | Địa chỉ PC: 0x15e2e4 | Địa chỉ FDE: 0x08c1c8 | Kích thước: 256 bytes
//   0x15e2e4: F9400009  ldr      x9, [x0]
//   0x15e2e8: EB01013F  cmp      x9, x1
//   0x15e2ec: 54000482  b.hs     #0x15e37c
//   0x15e2f0: D37FF86C  lsl      x12, x3, #1
static inline uint64_t fde_func_1353_0x15e2e4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x15e2e4ULL ^ (static_cast<uint64_t>(0xf9400009ULL) << 13);
    acc = (acc + a1 + 0xeb01013fULL) ^ 0x08c1c8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1354 | PC: 0x15e504 | FDE: 0x08c230 | Size: 256 bytes
// Khung tháo gỡ #1354 | Địa chỉ PC: 0x15e504 | Địa chỉ FDE: 0x08c230 | Kích thước: 256 bytes
//   0x15e504: 340000E1  cbz      w1, #0x15e520
//   0x15e508: F9400C00  ldr      x0, [x0, #0x18]
//   0x15e50c: AA1E03E2  mov      x2, x30
//   0x15e510: 940090C0  bl       #0x182810
static inline uint64_t fde_func_1354_0x15e504(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x15e504ULL ^ (static_cast<uint64_t>(0x340000e1ULL) << 13);
    acc = (acc + a1 + 0xf9400c00ULL) ^ 0x08c230ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1355 | PC: 0x15e610 | FDE: 0x08c298 | Size: 256 bytes
// Khung tháo gỡ #1355 | Địa chỉ PC: 0x15e610 | Địa chỉ FDE: 0x08c298 | Kích thước: 256 bytes
//   0x15e610: A9BE53F5  stp      x21, x20, [sp, #-0x20]!
//   0x15e614: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x15e618: B9408008  ldr      w8, [x0, #0x80]
//   0x15e61c: 71000D1F  cmp      w8, #3
static inline uint64_t fde_func_1355_0x15e610(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x15e610ULL ^ (static_cast<uint64_t>(0xa9be53f5ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x08c298ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1356 | PC: 0x15e814 | FDE: 0x08c318 | Size: 256 bytes
// Khung tháo gỡ #1356 | Địa chỉ PC: 0x15e814 | Địa chỉ FDE: 0x08c318 | Kích thước: 256 bytes
//   0x15e814: AA1E03E3  mov      x3, x30
//   0x15e818: 94005D8C  bl       #0x175e48
//   0x15e81c: AA0303FE  mov      x30, x3
//   0x15e820: A9057BFD  stp      x29, x30, [sp, #0x50]
static inline uint64_t fde_func_1356_0x15e814(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x15e814ULL ^ (static_cast<uint64_t>(0xaa1e03e3ULL) << 13);
    acc = (acc + a1 + 0x94005d8cULL) ^ 0x08c318ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1357 | PC: 0x15f48c | FDE: 0x08c3b0 | Size: 256 bytes
// Khung tháo gỡ #1357 | Địa chỉ PC: 0x15f48c | Địa chỉ FDE: 0x08c3b0 | Kích thước: 256 bytes
//   0x15f48c: A9BE53F5  stp      x21, x20, [sp, #-0x20]!
//   0x15f490: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x15f494: F9401C14  ldr      x20, [x0, #0x38]
//   0x15f498: 9400871D  bl       #0x18110c
static inline uint64_t fde_func_1357_0x15f48c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x15f48cULL ^ (static_cast<uint64_t>(0xa9be53f5ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x08c3b0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1358 | PC: 0x1616a8 | FDE: 0x08c450 | Size: 256 bytes
// Khung tháo gỡ #1358 | Địa chỉ PC: 0x1616a8 | Địa chỉ FDE: 0x08c450 | Kích thước: 256 bytes
//   0x1616a8: B40006C0  cbz      x0, #0x161780
//   0x1616ac: 79400008  ldrh     w8, [x0]
//   0x1616b0: F100091F  cmp      x8, #2
//   0x1616b4: 540000C2  b.hs     #0x1616cc
static inline uint64_t fde_func_1358_0x1616a8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1616a8ULL ^ (static_cast<uint64_t>(0xb40006c0ULL) << 13);
    acc = (acc + a1 + 0x79400008ULL) ^ 0x08c450ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1359 | PC: 0x1618a0 | FDE: 0x08c4c0 | Size: 256 bytes
// Khung tháo gỡ #1359 | Địa chỉ PC: 0x1618a0 | Địa chỉ FDE: 0x08c4c0 | Kích thước: 256 bytes
//   0x1618a0: A9412009  ldp      x9, x8, [x0, #0x10]
//   0x1618a4: EB09011F  cmp      x8, x9
//   0x1618a8: 540000A2  b.hs     #0x1618bc
//   0x1618ac: 91000509  add      x9, x8, #1
static inline uint64_t fde_func_1359_0x1618a0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1618a0ULL ^ (static_cast<uint64_t>(0xa9412009ULL) << 13);
    acc = (acc + a1 + 0xeb09011fULL) ^ 0x08c4c0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1360 | PC: 0x1619e0 | FDE: 0x08c520 | Size: 256 bytes
// Khung tháo gỡ #1360 | Địa chỉ PC: 0x1619e0 | Địa chỉ FDE: 0x08c520 | Kích thước: 256 bytes
//   0x1619e0: A9412009  ldp      x9, x8, [x0, #0x10]
//   0x1619e4: CB090109  sub      x9, x8, x9
//   0x1619e8: D343FD29  lsr      x9, x9, #3
//   0x1619ec: 6B01013F  cmp      w9, w1
static inline uint64_t fde_func_1360_0x1619e0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1619e0ULL ^ (static_cast<uint64_t>(0xa9412009ULL) << 13);
    acc = (acc + a1 + 0xcb090109ULL) ^ 0x08c520ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1361 | PC: 0x161bf8 | FDE: 0x08c598 | Size: 256 bytes
// Khung tháo gỡ #1361 | Địa chỉ PC: 0x161bf8 | Địa chỉ FDE: 0x08c598 | Kích thước: 256 bytes
//   0x161bf8: AA1E03E3  mov      x3, x30
//   0x161bfc: 94006D03  bl       #0x17d008
//   0x161c00: AA0303FE  mov      x30, x3
//   0x161c04: A9057BF3  stp      x19, x30, [sp, #0x50]
static inline uint64_t fde_func_1361_0x161bf8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x161bf8ULL ^ (static_cast<uint64_t>(0xaa1e03e3ULL) << 13);
    acc = (acc + a1 + 0x94006d03ULL) ^ 0x08c598ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1362 | PC: 0x161fbc | FDE: 0x08c628 | Size: 256 bytes
// Khung tháo gỡ #1362 | Địa chỉ PC: 0x161fbc | Địa chỉ FDE: 0x08c628 | Kích thước: 256 bytes
//   0x161fbc: AA1E03E6  mov      x6, x30
//   0x161fc0: 94005763  bl       #0x177d4c
//   0x161fc4: AA0603FE  mov      x30, x6
//   0x161fc8: A90A7BFD  stp      x29, x30, [sp, #0xa0]
static inline uint64_t fde_func_1362_0x161fbc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x161fbcULL ^ (static_cast<uint64_t>(0xaa1e03e6ULL) << 13);
    acc = (acc + a1 + 0x94005763ULL) ^ 0x08c628ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1363 | PC: 0x16225c | FDE: 0x08c6a8 | Size: 256 bytes
// Khung tháo gỡ #1363 | Địa chỉ PC: 0x16225c | Địa chỉ FDE: 0x08c6a8 | Kích thước: 256 bytes
//   0x16225c: B9402009  ldr      w9, [x0, #0x20]
//   0x162260: A941200A  ldp      x10, x8, [x0, #0x10]
//   0x162264: 8B090D49  add      x9, x10, x9, lsl #3
//   0x162268: EB09011F  cmp      x8, x9
static inline uint64_t fde_func_1363_0x16225c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x16225cULL ^ (static_cast<uint64_t>(0xb9402009ULL) << 13);
    acc = (acc + a1 + 0xa941200aULL) ^ 0x08c6a8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1364 | PC: 0x1623a0 | FDE: 0x08c710 | Size: 256 bytes
// Khung tháo gỡ #1364 | Địa chỉ PC: 0x1623a0 | Địa chỉ FDE: 0x08c710 | Kích thước: 256 bytes
//   0x1623a0: F81D0FF6  str      x22, [sp, #-0x30]!
//   0x1623a4: A90153F5  stp      x21, x20, [sp, #0x10]
//   0x1623a8: A9027BF3  stp      x19, x30, [sp, #0x20]
//   0x1623ac: AA0103F3  mov      x19, x1
static inline uint64_t fde_func_1364_0x1623a0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1623a0ULL ^ (static_cast<uint64_t>(0xf81d0ff6ULL) << 13);
    acc = (acc + a1 + 0xa90153f5ULL) ^ 0x08c710ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1365 | PC: 0x162ab0 | FDE: 0x08c790 | Size: 256 bytes
// Khung tháo gỡ #1365 | Địa chỉ PC: 0x162ab0 | Địa chỉ FDE: 0x08c790 | Kích thước: 256 bytes
//   0x162ab0: F81C0FF8  str      x24, [sp, #-0x40]!
//   0x162ab4: A9015BF7  stp      x23, x22, [sp, #0x10]
//   0x162ab8: A90253F5  stp      x21, x20, [sp, #0x20]
//   0x162abc: A9037BF3  stp      x19, x30, [sp, #0x30]
static inline uint64_t fde_func_1365_0x162ab0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x162ab0ULL ^ (static_cast<uint64_t>(0xf81c0ff8ULL) << 13);
    acc = (acc + a1 + 0xa9015bf7ULL) ^ 0x08c790ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1366 | PC: 0x162f28 | FDE: 0x08c818 | Size: 256 bytes
// Khung tháo gỡ #1366 | Địa chỉ PC: 0x162f28 | Địa chỉ FDE: 0x08c818 | Kích thước: 256 bytes
//   0x162f28: AA1E03E6  mov      x6, x30
//   0x162f2c: 940053C4  bl       #0x177e3c
//   0x162f30: AA0603FE  mov      x30, x6
//   0x162f34: A90D7BFD  stp      x29, x30, [sp, #0xd0]
static inline uint64_t fde_func_1366_0x162f28(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x162f28ULL ^ (static_cast<uint64_t>(0xaa1e03e6ULL) << 13);
    acc = (acc + a1 + 0x940053c4ULL) ^ 0x08c818ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1367 | PC: 0x16366c | FDE: 0x08c8a8 | Size: 256 bytes
// Khung tháo gỡ #1367 | Địa chỉ PC: 0x16366c | Địa chỉ FDE: 0x08c8a8 | Kích thước: 256 bytes
//   0x16366c: F81D0FF6  str      x22, [sp, #-0x30]!
//   0x163670: A90153F5  stp      x21, x20, [sp, #0x10]
//   0x163674: A9027BF3  stp      x19, x30, [sp, #0x20]
//   0x163678: 39416008  ldrb     w8, [x0, #0x58]
static inline uint64_t fde_func_1367_0x16366c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x16366cULL ^ (static_cast<uint64_t>(0xf81d0ff6ULL) << 13);
    acc = (acc + a1 + 0xa90153f5ULL) ^ 0x08c8a8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1368 | PC: 0x1637f8 | FDE: 0x08c920 | Size: 256 bytes
// Khung tháo gỡ #1368 | Địa chỉ PC: 0x1637f8 | Địa chỉ FDE: 0x08c920 | Kích thước: 256 bytes
//   0x1637f8: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x1637fc: F9400401  ldr      x1, [x0, #8]
//   0x163800: AA0003F3  mov      x19, x0
//   0x163804: B4000061  cbz      x1, #0x163810
static inline uint64_t fde_func_1368_0x1637f8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1637f8ULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0xf9400401ULL) ^ 0x08c920ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1369 | PC: 0x163ecc | FDE: 0x08c9a8 | Size: 256 bytes
// Khung tháo gỡ #1369 | Địa chỉ PC: 0x163ecc | Địa chỉ FDE: 0x08c9a8 | Kích thước: 256 bytes
//   0x163ecc: D10083FF  sub      sp, sp, #0x20
//   0x163ed0: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x163ed4: AA0103F3  mov      x19, x1
//   0x163ed8: 52800068  mov      w8, #3
static inline uint64_t fde_func_1369_0x163ecc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x163eccULL ^ (static_cast<uint64_t>(0xd10083ffULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x08c9a8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1370 | PC: 0x1640f4 | FDE: 0x08ca18 | Size: 256 bytes
// Khung tháo gỡ #1370 | Địa chỉ PC: 0x1640f4 | Địa chỉ FDE: 0x08ca18 | Kích thước: 256 bytes
//   0x1640f4: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x1640f8: AA0003F3  mov      x19, x0
//   0x1640fc: 94000023  bl       #0x164188
//   0x164100: B9401A68  ldr      w8, [x19, #0x18]
static inline uint64_t fde_func_1370_0x1640f4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1640f4ULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0xaa0003f3ULL) ^ 0x08ca18ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1371 | PC: 0x16422c | FDE: 0x08ca78 | Size: 256 bytes
// Khung tháo gỡ #1371 | Địa chỉ PC: 0x16422c | Địa chỉ FDE: 0x08ca78 | Kích thước: 256 bytes
//   0x16422c: F81D0FF6  str      x22, [sp, #-0x30]!
//   0x164230: A90153F5  stp      x21, x20, [sp, #0x10]
//   0x164234: A9027BF3  stp      x19, x30, [sp, #0x20]
//   0x164238: 7103FC3F  cmp      w1, #0xff
static inline uint64_t fde_func_1371_0x16422c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x16422cULL ^ (static_cast<uint64_t>(0xf81d0ff6ULL) << 13);
    acc = (acc + a1 + 0xa90153f5ULL) ^ 0x08ca78ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1372 | PC: 0x164338 | FDE: 0x08cae8 | Size: 160 bytes
// Khung tháo gỡ #1372 | Địa chỉ PC: 0x164338 | Địa chỉ FDE: 0x08cae8 | Kích thước: 160 bytes
//   0x164338: F9400008  ldr      x8, [x0]
//   0x16433c: B9422D09  ldr      w9, [x8, #0x22c]
//   0x164340: B9001809  str      w9, [x0, #0x18]
//   0x164344: B942310A  ldr      w10, [x8, #0x230]
static inline uint64_t fde_func_1372_0x164338(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x164338ULL ^ (static_cast<uint64_t>(0xf9400008ULL) << 13);
    acc = (acc + a1 + 0xb9422d09ULL) ^ 0x08cae8ULL;
    acc ^= (acc >> 17) * 0x00a0ULL;
    return acc;
}

// FDE #1373 | PC: 0x1643d8 | FDE: 0x08cb48 | Size: 80 bytes
// Khung tháo gỡ #1373 | Địa chỉ PC: 0x1643d8 | Địa chỉ FDE: 0x08cb48 | Kích thước: 80 bytes
//   0x1643d8: F9400005  ldr      x5, [x0]
//   0x1643dc: F94184A8  ldr      x8, [x5, #0x308]
//   0x1643e0: F9400506  ldr      x6, [x8, #8]
//   0x1643e4: B40000E6  cbz      x6, #0x164400
static inline uint64_t fde_func_1373_0x1643d8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1643d8ULL ^ (static_cast<uint64_t>(0xf9400005ULL) << 13);
    acc = (acc + a1 + 0xf94184a8ULL) ^ 0x08cb48ULL;
    acc ^= (acc >> 17) * 0x0050ULL;
    return acc;
}

// FDE #1374 | PC: 0x164428 | FDE: 0x08cba8 | Size: 256 bytes
// Khung tháo gỡ #1374 | Địa chỉ PC: 0x164428 | Địa chỉ FDE: 0x08cba8 | Kích thước: 256 bytes
//   0x164428: F81D0FF6  str      x22, [sp, #-0x30]!
//   0x16442c: A90153F5  stp      x21, x20, [sp, #0x10]
//   0x164430: A9027BF3  stp      x19, x30, [sp, #0x20]
//   0x164434: 52802008  mov      w8, #0x100
static inline uint64_t fde_func_1374_0x164428(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x164428ULL ^ (static_cast<uint64_t>(0xf81d0ff6ULL) << 13);
    acc = (acc + a1 + 0xa90153f5ULL) ^ 0x08cba8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1375 | PC: 0x164578 | FDE: 0x08cc18 | Size: 256 bytes
// Khung tháo gỡ #1375 | Địa chỉ PC: 0x164578 | Địa chỉ FDE: 0x08cc18 | Kích thước: 256 bytes
//   0x164578: A9BE53F5  stp      x21, x20, [sp, #-0x20]!
//   0x16457c: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x164580: 39420008  ldrb     w8, [x0, #0x80]
//   0x164584: 34000068  cbz      w8, #0x164590
static inline uint64_t fde_func_1375_0x164578(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x164578ULL ^ (static_cast<uint64_t>(0xa9be53f5ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x08cc18ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1376 | PC: 0x1647d0 | FDE: 0x08cc98 | Size: 256 bytes
// Khung tháo gỡ #1376 | Địa chỉ PC: 0x1647d0 | Địa chỉ FDE: 0x08cc98 | Kích thước: 256 bytes
//   0x1647d0: 4A003408  eor      w8, w0, w0, lsl #13
//   0x1647d4: 4A484508  eor      w8, w8, w8, lsr #17
//   0x1647d8: 4A081500  eor      w0, w8, w8, lsl #5
//   0x1647dc: D65F03C0  ret      
static inline uint64_t fde_func_1376_0x1647d0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1647d0ULL ^ (static_cast<uint64_t>(0x4a003408ULL) << 13);
    acc = (acc + a1 + 0x4a484508ULL) ^ 0x08cc98ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1377 | PC: 0x1659c8 | FDE: 0x08cd20 | Size: 256 bytes
// Khung tháo gỡ #1377 | Địa chỉ PC: 0x1659c8 | Địa chỉ FDE: 0x08cd20 | Kích thước: 256 bytes
//   0x1659c8: F100001F  cmp      x0, #0
//   0x1659cc: DA805408  cneg     x8, x0, mi
//   0x1659d0: F100003F  cmp      x1, #0
//   0x1659d4: DA815429  cneg     x9, x1, mi
static inline uint64_t fde_func_1377_0x1659c8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1659c8ULL ^ (static_cast<uint64_t>(0xf100001fULL) << 13);
    acc = (acc + a1 + 0xda805408ULL) ^ 0x08cd20ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1378 | PC: 0x165e30 | FDE: 0x08cd98 | Size: 256 bytes
// Khung tháo gỡ #1378 | Địa chỉ PC: 0x165e30 | Địa chỉ FDE: 0x08cd98 | Kích thước: 256 bytes
//   0x165e30: AA1E03E4  mov      x4, x30
//   0x165e34: 9400551C  bl       #0x17b2a4
//   0x165e38: AA0403FE  mov      x30, x4
//   0x165e3c: A9047BF3  stp      x19, x30, [sp, #0x40]
static inline uint64_t fde_func_1378_0x165e30(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x165e30ULL ^ (static_cast<uint64_t>(0xaa1e03e4ULL) << 13);
    acc = (acc + a1 + 0x9400551cULL) ^ 0x08cd98ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1379 | PC: 0x166508 | FDE: 0x08ce10 | Size: 256 bytes
// Khung tháo gỡ #1379 | Địa chỉ PC: 0x166508 | Địa chỉ FDE: 0x08ce10 | Kích thước: 256 bytes
//   0x166508: 52803308  mov      w8, #0x198
//   0x16650c: 9BA80028  umaddl   x8, w1, w8, x0
//   0x166510: B940090B  ldr      w11, [x8, #8]
//   0x166514: 3400042B  cbz      w11, #0x166598
static inline uint64_t fde_func_1379_0x166508(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x166508ULL ^ (static_cast<uint64_t>(0x52803308ULL) << 13);
    acc = (acc + a1 + 0x9ba80028ULL) ^ 0x08ce10ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1380 | PC: 0x166768 | FDE: 0x08ce78 | Size: 256 bytes
// Khung tháo gỡ #1380 | Địa chỉ PC: 0x166768 | Địa chỉ FDE: 0x08ce78 | Kích thước: 256 bytes
//   0x166768: F81E0FF4  str      x20, [sp, #-0x20]!
//   0x16676c: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x166770: 94005A23  bl       #0x17cffc
//   0x166774: AA0103F4  mov      x20, x1
static inline uint64_t fde_func_1380_0x166768(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x166768ULL ^ (static_cast<uint64_t>(0xf81e0ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x08ce78ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1381 | PC: 0x1669a8 | FDE: 0x08cef8 | Size: 256 bytes
// Khung tháo gỡ #1381 | Địa chỉ PC: 0x1669a8 | Địa chỉ FDE: 0x08cef8 | Kích thước: 256 bytes
//   0x1669a8: 52800028  mov      w8, #1
//   0x1669ac: 140054F3  b        #0x17bd78
//   0x1669b0: 1400021A  b        #0x167218
//   0x1669b4: D100C3FF  sub      sp, sp, #0x30
static inline uint64_t fde_func_1381_0x1669a8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1669a8ULL ^ (static_cast<uint64_t>(0x52800028ULL) << 13);
    acc = (acc + a1 + 0x140054f3ULL) ^ 0x08cef8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1382 | PC: 0x166b7c | FDE: 0x08cf68 | Size: 256 bytes
// Khung tháo gỡ #1382 | Địa chỉ PC: 0x166b7c | Địa chỉ FDE: 0x08cf68 | Kích thước: 256 bytes
//   0x166b7c: A9BE53F5  stp      x21, x20, [sp, #-0x20]!
//   0x166b80: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x166b84: B9400808  ldr      w8, [x0, #8]
//   0x166b88: 35000248  cbnz     w8, #0x166bd0
static inline uint64_t fde_func_1382_0x166b7c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x166b7cULL ^ (static_cast<uint64_t>(0xa9be53f5ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x08cf68ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1383 | PC: 0x166cd0 | FDE: 0x08cfe8 | Size: 256 bytes
// Khung tháo gỡ #1383 | Địa chỉ PC: 0x166cd0 | Địa chỉ FDE: 0x08cfe8 | Kích thước: 256 bytes
//   0x166cd0: F81C0FF8  str      x24, [sp, #-0x40]!
//   0x166cd4: A9015BF7  stp      x23, x22, [sp, #0x10]
//   0x166cd8: A90253F5  stp      x21, x20, [sp, #0x20]
//   0x166cdc: A9037BF3  stp      x19, x30, [sp, #0x30]
static inline uint64_t fde_func_1383_0x166cd0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x166cd0ULL ^ (static_cast<uint64_t>(0xf81c0ff8ULL) << 13);
    acc = (acc + a1 + 0xa9015bf7ULL) ^ 0x08cfe8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1384 | PC: 0x166ecc | FDE: 0x08d070 | Size: 256 bytes
// Khung tháo gỡ #1384 | Địa chỉ PC: 0x166ecc | Địa chỉ FDE: 0x08d070 | Kích thước: 256 bytes
//   0x166ecc: D10083FF  sub      sp, sp, #0x20
//   0x166ed0: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x166ed4: B9400009  ldr      w9, [x0]
//   0x166ed8: AA0203F3  mov      x19, x2
static inline uint64_t fde_func_1384_0x166ecc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x166eccULL ^ (static_cast<uint64_t>(0xd10083ffULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x08d070ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1385 | PC: 0x167090 | FDE: 0x08d0e8 | Size: 256 bytes
// Khung tháo gỡ #1385 | Địa chỉ PC: 0x167090 | Địa chỉ FDE: 0x08d0e8 | Kích thước: 256 bytes
//   0x167090: D10183FF  sub      sp, sp, #0x60
//   0x167094: AA1E03E5  mov      x5, x30
//   0x167098: 940040C0  bl       #0x177398
//   0x16709c: AA0503FE  mov      x30, x5
static inline uint64_t fde_func_1385_0x167090(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x167090ULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xaa1e03e5ULL) ^ 0x08d0e8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1386 | PC: 0x16742c | FDE: 0x08d180 | Size: 256 bytes
// Khung tháo gỡ #1386 | Địa chỉ PC: 0x16742c | Địa chỉ FDE: 0x08d180 | Kích thước: 256 bytes
//   0x16742c: B9400008  ldr      w8, [x0]
//   0x167430: 6B01011F  cmp      w8, w1
//   0x167434: 54000149  b.ls     #0x16745c
//   0x167438: F9400408  ldr      x8, [x0, #8]
static inline uint64_t fde_func_1386_0x16742c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x16742cULL ^ (static_cast<uint64_t>(0xb9400008ULL) << 13);
    acc = (acc + a1 + 0x6b01011fULL) ^ 0x08d180ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1387 | PC: 0x167718 | FDE: 0x08d1e8 | Size: 36 bytes
// Khung tháo gỡ #1387 | Địa chỉ PC: 0x167718 | Địa chỉ FDE: 0x08d1e8 | Kích thước: 36 bytes
//   0x167718: 91024000  add      x0, x0, #0x90
//   0x16771c: D65F03C0  ret      
//   0x167720: 9102A000  add      x0, x0, #0xa8
//   0x167724: D65F03C0  ret      
static inline uint64_t fde_func_1387_0x167718(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x167718ULL ^ (static_cast<uint64_t>(0x91024000ULL) << 13);
    acc = (acc + a1 + 0xd65f03c0ULL) ^ 0x08d1e8ULL;
    acc ^= (acc >> 17) * 0x0024ULL;
    return acc;
}

// FDE #1388 | PC: 0x16773c | FDE: 0x08d248 | Size: 88 bytes
// Khung tháo gỡ #1388 | Địa chỉ PC: 0x16773c | Địa chỉ FDE: 0x08d248 | Kích thước: 88 bytes
//   0x16773c: 7104041F  cmp      w0, #0x101
//   0x167740: D0FFF769  adrp     x9, #0x55000
//   0x167744: 1A8083E8  csel     w8, wzr, w0, hi
//   0x167748: 9125B129  add      x9, x9, #0x96c
static inline uint64_t fde_func_1388_0x16773c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x16773cULL ^ (static_cast<uint64_t>(0x7104041fULL) << 13);
    acc = (acc + a1 + 0xd0fff769ULL) ^ 0x08d248ULL;
    acc ^= (acc >> 17) * 0x0058ULL;
    return acc;
}

// FDE #1389 | PC: 0x167794 | FDE: 0x08d2a8 | Size: 256 bytes
// Khung tháo gỡ #1389 | Địa chỉ PC: 0x167794 | Địa chỉ FDE: 0x08d2a8 | Kích thước: 256 bytes
//   0x167794: D10103FF  sub      sp, sp, #0x40
//   0x167798: A90253F5  stp      x21, x20, [sp, #0x20]
//   0x16779c: A9037BF3  stp      x19, x30, [sp, #0x30]
//   0x1677a0: AA0103F4  mov      x20, x1
static inline uint64_t fde_func_1389_0x167794(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x167794ULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xa90253f5ULL) ^ 0x08d2a8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1390 | PC: 0x167b98 | FDE: 0x08d330 | Size: 256 bytes
// Khung tháo gỡ #1390 | Địa chỉ PC: 0x167b98 | Địa chỉ FDE: 0x08d330 | Kích thước: 256 bytes
//   0x167b98: D100C3FF  sub      sp, sp, #0x30
//   0x167b9c: A90153F5  stp      x21, x20, [sp, #0x10]
//   0x167ba0: A9027BF3  stp      x19, x30, [sp, #0x20]
//   0x167ba4: AA0203F3  mov      x19, x2
static inline uint64_t fde_func_1390_0x167b98(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x167b98ULL ^ (static_cast<uint64_t>(0xd100c3ffULL) << 13);
    acc = (acc + a1 + 0xa90153f5ULL) ^ 0x08d330ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1391 | PC: 0x168298 | FDE: 0x08d3d0 | Size: 256 bytes
// Khung tháo gỡ #1391 | Địa chỉ PC: 0x168298 | Địa chỉ FDE: 0x08d3d0 | Kích thước: 256 bytes
//   0x168298: AA1F03E8  mov      x8, xzr
//   0x16829c: AA1F03E9  mov      x9, xzr
//   0x1682a0: 1280000A  mov      w10, #-1
//   0x1682a4: B900004A  str      w10, [x2]
static inline uint64_t fde_func_1391_0x168298(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x168298ULL ^ (static_cast<uint64_t>(0xaa1f03e8ULL) << 13);
    acc = (acc + a1 + 0xaa1f03e9ULL) ^ 0x08d3d0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1392 | PC: 0x168418 | FDE: 0x08d430 | Size: 256 bytes
// Khung tháo gỡ #1392 | Địa chỉ PC: 0x168418 | Địa chỉ FDE: 0x08d430 | Kích thước: 256 bytes
//   0x168418: 528000C8  mov      w8, #6
//   0x16841c: B40002C3  cbz      x3, #0x168474
//   0x168420: B40002A4  cbz      x4, #0x168474
//   0x168424: 79424009  ldrh     w9, [x0, #0x120]
static inline uint64_t fde_func_1392_0x168418(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x168418ULL ^ (static_cast<uint64_t>(0x528000c8ULL) << 13);
    acc = (acc + a1 + 0xb40002c3ULL) ^ 0x08d430ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1393 | PC: 0x169830 | FDE: 0x08d4c8 | Size: 256 bytes
// Khung tháo gỡ #1393 | Địa chỉ PC: 0x169830 | Địa chỉ FDE: 0x08d4c8 | Kích thước: 256 bytes
//   0x169830: B4000DA0  cbz      x0, #0x1699e4
//   0x169834: A9BE53F5  stp      x21, x20, [sp, #-0x20]!
//   0x169838: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x16983c: F941B815  ldr      x21, [x0, #0x370]
static inline uint64_t fde_func_1393_0x169830(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x169830ULL ^ (static_cast<uint64_t>(0xb4000da0ULL) << 13);
    acc = (acc + a1 + 0xa9be53f5ULL) ^ 0x08d4c8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1394 | PC: 0x169ab0 | FDE: 0x08d540 | Size: 256 bytes
// Khung tháo gỡ #1394 | Địa chỉ PC: 0x169ab0 | Địa chỉ FDE: 0x08d540 | Kích thước: 256 bytes
//   0x169ab0: A9BE53F5  stp      x21, x20, [sp, #-0x20]!
//   0x169ab4: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x169ab8: F941A008  ldr      x8, [x0, #0x340]
//   0x169abc: AA0103F4  mov      x20, x1
static inline uint64_t fde_func_1394_0x169ab0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x169ab0ULL ^ (static_cast<uint64_t>(0xa9be53f5ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x08d540ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1395 | PC: 0x169fa8 | FDE: 0x08d5d0 | Size: 256 bytes
// Khung tháo gỡ #1395 | Địa chỉ PC: 0x169fa8 | Địa chỉ FDE: 0x08d5d0 | Kích thước: 256 bytes
//   0x169fa8: F81D0FF6  str      x22, [sp, #-0x30]!
//   0x169fac: A90153F5  stp      x21, x20, [sp, #0x10]
//   0x169fb0: A9027BF3  stp      x19, x30, [sp, #0x20]
//   0x169fb4: F9412415  ldr      x21, [x0, #0x248]
static inline uint64_t fde_func_1395_0x169fa8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x169fa8ULL ^ (static_cast<uint64_t>(0xf81d0ff6ULL) << 13);
    acc = (acc + a1 + 0xa90153f5ULL) ^ 0x08d5d0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1396 | PC: 0x16a344 | FDE: 0x08d658 | Size: 256 bytes
// Khung tháo gỡ #1396 | Địa chỉ PC: 0x16a344 | Địa chỉ FDE: 0x08d658 | Kích thước: 256 bytes
//   0x16a344: 528CAC82  mov      w2, #0x6564
//   0x16a348: 72AC4D02  movk     w2, #0x6268, lsl #16
//   0x16a34c: 14001307  b        #0x16ef68
//   0x16a350: AA1E03E7  mov      x7, x30
static inline uint64_t fde_func_1396_0x16a344(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x16a344ULL ^ (static_cast<uint64_t>(0x528cac82ULL) << 13);
    acc = (acc + a1 + 0x72ac4d02ULL) ^ 0x08d658ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1397 | PC: 0x16acd8 | FDE: 0x08d6d8 | Size: 256 bytes
// Khung tháo gỡ #1397 | Địa chỉ PC: 0x16acd8 | Địa chỉ FDE: 0x08d6d8 | Kích thước: 256 bytes
//   0x16acd8: AA1E03E2  mov      x2, x30
//   0x16acdc: 9400341C  bl       #0x177d4c
//   0x16ace0: AA0203FE  mov      x30, x2
//   0x16ace4: A90A7BFD  stp      x29, x30, [sp, #0xa0]
static inline uint64_t fde_func_1397_0x16acd8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x16acd8ULL ^ (static_cast<uint64_t>(0xaa1e03e2ULL) << 13);
    acc = (acc + a1 + 0x9400341cULL) ^ 0x08d6d8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1398 | PC: 0x16b434 | FDE: 0x08d768 | Size: 256 bytes
// Khung tháo gỡ #1398 | Địa chỉ PC: 0x16b434 | Địa chỉ FDE: 0x08d768 | Kích thước: 256 bytes
//   0x16b434: 17FFA1F6  b        #0x153c0c
//   0x16b438: F81D0FF6  str      x22, [sp, #-0x30]!
//   0x16b43c: A90153F5  stp      x21, x20, [sp, #0x10]
//   0x16b440: A9027BF3  stp      x19, x30, [sp, #0x20]
static inline uint64_t fde_func_1398_0x16b434(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x16b434ULL ^ (static_cast<uint64_t>(0x17ffa1f6ULL) << 13);
    acc = (acc + a1 + 0xf81d0ff6ULL) ^ 0x08d768ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1399 | PC: 0x16bcf4 | FDE: 0x08d7f0 | Size: 256 bytes
// Khung tháo gỡ #1399 | Địa chỉ PC: 0x16bcf4 | Địa chỉ FDE: 0x08d7f0 | Kích thước: 256 bytes
//   0x16bcf4: F81E0FF4  str      x20, [sp, #-0x20]!
//   0x16bcf8: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x16bcfc: F942BC13  ldr      x19, [x0, #0x578]
//   0x16bd00: B40000F3  cbz      x19, #0x16bd1c
static inline uint64_t fde_func_1399_0x16bcf4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x16bcf4ULL ^ (static_cast<uint64_t>(0xf81e0ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x08d7f0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1400 | PC: 0x16bf2c | FDE: 0x08d860 | Size: 256 bytes
// Khung tháo gỡ #1400 | Địa chỉ PC: 0x16bf2c | Địa chỉ FDE: 0x08d860 | Kích thước: 256 bytes
//   0x16bf2c: F942C009  ldr      x9, [x0, #0x580]
//   0x16bf30: B4000609  cbz      x9, #0x16bff0
//   0x16bf34: F9402528  ldr      x8, [x9, #0x48]
//   0x16bf38: B40005C8  cbz      x8, #0x16bff0
static inline uint64_t fde_func_1400_0x16bf2c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x16bf2cULL ^ (static_cast<uint64_t>(0xf942c009ULL) << 13);
    acc = (acc + a1 + 0xb4000609ULL) ^ 0x08d860ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1401 | PC: 0x16c400 | FDE: 0x08d8d0 | Size: 256 bytes
// Khung tháo gỡ #1401 | Địa chỉ PC: 0x16c400 | Địa chỉ FDE: 0x08d8d0 | Kích thước: 256 bytes
//   0x16c400: D10143FF  sub      sp, sp, #0x50
//   0x16c404: F90013F6  str      x22, [sp, #0x20]
//   0x16c408: A90353F5  stp      x21, x20, [sp, #0x30]
//   0x16c40c: A9047BF3  stp      x19, x30, [sp, #0x40]
static inline uint64_t fde_func_1401_0x16c400(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x16c400ULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xf90013f6ULL) ^ 0x08d8d0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1402 | PC: 0x16d32c | FDE: 0x08d970 | Size: 256 bytes
// Khung tháo gỡ #1402 | Địa chỉ PC: 0x16d32c | Địa chỉ FDE: 0x08d970 | Kích thước: 256 bytes
//   0x16d32c: F81E0FF4  str      x20, [sp, #-0x20]!
//   0x16d330: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x16d334: 79401013  ldrh     w19, [x0, #8]
//   0x16d338: F9400C14  ldr      x20, [x0, #0x18]
static inline uint64_t fde_func_1402_0x16d32c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x16d32cULL ^ (static_cast<uint64_t>(0xf81e0ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x08d970ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1403 | PC: 0x16d514 | FDE: 0x08d9e0 | Size: 256 bytes
// Khung tháo gỡ #1403 | Địa chỉ PC: 0x16d514 | Địa chỉ FDE: 0x08d9e0 | Kích thước: 256 bytes
//   0x16d514: AA1E03E8  mov      x8, x30
//   0x16d518: 9400224C  bl       #0x175e48
//   0x16d51c: AA0803FE  mov      x30, x8
//   0x16d520: A9057BFD  stp      x29, x30, [sp, #0x50]
static inline uint64_t fde_func_1403_0x16d514(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x16d514ULL ^ (static_cast<uint64_t>(0xaa1e03e8ULL) << 13);
    acc = (acc + a1 + 0x9400224cULL) ^ 0x08d9e0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1404 | PC: 0x16ebb0 | FDE: 0x08da78 | Size: 256 bytes
// Khung tháo gỡ #1404 | Địa chỉ PC: 0x16ebb0 | Địa chỉ FDE: 0x08da78 | Kích thước: 256 bytes
//   0x16ebb0: D101C3FF  sub      sp, sp, #0x70
//   0x16ebb4: AA1E03E6  mov      x6, x30
//   0x16ebb8: 94001FAA  bl       #0x176a60
//   0x16ebbc: AA0603FE  mov      x30, x6
static inline uint64_t fde_func_1404_0x16ebb0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x16ebb0ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xaa1e03e6ULL) ^ 0x08da78ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1405 | PC: 0x16eeb8 | FDE: 0x08daf0 | Size: 256 bytes
// Khung tháo gỡ #1405 | Địa chỉ PC: 0x16eeb8 | Địa chỉ FDE: 0x08daf0 | Kích thước: 256 bytes
//   0x16eeb8: A9BE53F5  stp      x21, x20, [sp, #-0x20]!
//   0x16eebc: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x16eec0: 5290B908  mov      w8, #0x85c8
//   0x16eec4: F8686814  ldr      x20, [x0, x8]
static inline uint64_t fde_func_1405_0x16eeb8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x16eeb8ULL ^ (static_cast<uint64_t>(0xa9be53f5ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x08daf0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1406 | PC: 0x16f1ac | FDE: 0x08db70 | Size: 96 bytes
// Khung tháo gỡ #1406 | Địa chỉ PC: 0x16f1ac | Địa chỉ FDE: 0x08db70 | Kích thước: 96 bytes
//   0x16f1ac: F9400005  ldr      x5, [x0]
//   0x16f1b0: F941BCA8  ldr      x8, [x5, #0x378]
//   0x16f1b4: F9400506  ldr      x6, [x8, #8]
//   0x16f1b8: B40000E6  cbz      x6, #0x16f1d4
static inline uint64_t fde_func_1406_0x16f1ac(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x16f1acULL ^ (static_cast<uint64_t>(0xf9400005ULL) << 13);
    acc = (acc + a1 + 0xf941bca8ULL) ^ 0x08db70ULL;
    acc ^= (acc >> 17) * 0x0060ULL;
    return acc;
}

// FDE #1407 | PC: 0x16f20c | FDE: 0x08dbd0 | Size: 256 bytes
// Khung tháo gỡ #1407 | Địa chỉ PC: 0x16f20c | Địa chỉ FDE: 0x08dbd0 | Kích thước: 256 bytes
//   0x16f20c: F9000C01  str      x1, [x0, #0x18]
//   0x16f210: 39401828  ldrb     w8, [x1, #6]
//   0x16f214: 39401C29  ldrb     w9, [x1, #7]
//   0x16f218: 3940202A  ldrb     w10, [x1, #8]
static inline uint64_t fde_func_1407_0x16f20c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x16f20cULL ^ (static_cast<uint64_t>(0xf9000c01ULL) << 13);
    acc = (acc + a1 + 0x39401828ULL) ^ 0x08dbd0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1408 | PC: 0x16f33c | FDE: 0x08dc40 | Size: 256 bytes
// Khung tháo gỡ #1408 | Địa chỉ PC: 0x16f33c | Địa chỉ FDE: 0x08dc40 | Kích thước: 256 bytes
//   0x16f33c: F81C0FF8  str      x24, [sp, #-0x40]!
//   0x16f340: A9015BF7  stp      x23, x22, [sp, #0x10]
//   0x16f344: A90253F5  stp      x21, x20, [sp, #0x20]
//   0x16f348: A9037BF3  stp      x19, x30, [sp, #0x30]
static inline uint64_t fde_func_1408_0x16f33c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x16f33cULL ^ (static_cast<uint64_t>(0xf81c0ff8ULL) << 13);
    acc = (acc + a1 + 0xa9015bf7ULL) ^ 0x08dc40ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1409 | PC: 0x16f840 | FDE: 0x08dce0 | Size: 256 bytes
// Khung tháo gỡ #1409 | Địa chỉ PC: 0x16f840 | Địa chỉ FDE: 0x08dce0 | Kích thước: 256 bytes
//   0x16f840: F81F0FFE  str      x30, [sp, #-0x10]!
//   0x16f844: F940842A  ldr      x10, [x1, #0x108]
//   0x16f848: 91002809  add      x9, x0, #0xa
//   0x16f84c: 94004594  bl       #0x180e9c
static inline uint64_t fde_func_1409_0x16f840(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x16f840ULL ^ (static_cast<uint64_t>(0xf81f0ffeULL) << 13);
    acc = (acc + a1 + 0xf940842aULL) ^ 0x08dce0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1410 | PC: 0x16fb98 | FDE: 0x08dd48 | Size: 256 bytes
// Khung tháo gỡ #1410 | Địa chỉ PC: 0x16fb98 | Địa chỉ FDE: 0x08dd48 | Kích thước: 256 bytes
//   0x16fb98: A9BC63F9  stp      x25, x24, [sp, #-0x40]!
//   0x16fb9c: A9015BF7  stp      x23, x22, [sp, #0x10]
//   0x16fba0: A90253F5  stp      x21, x20, [sp, #0x20]
//   0x16fba4: A9037BF3  stp      x19, x30, [sp, #0x30]
static inline uint64_t fde_func_1410_0x16fb98(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x16fb98ULL ^ (static_cast<uint64_t>(0xa9bc63f9ULL) << 13);
    acc = (acc + a1 + 0xa9015bf7ULL) ^ 0x08dd48ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1411 | PC: 0x16fd3c | FDE: 0x08ddc0 | Size: 256 bytes
// Khung tháo gỡ #1411 | Địa chỉ PC: 0x16fd3c | Địa chỉ FDE: 0x08ddc0 | Kích thước: 256 bytes
//   0x16fd3c: B8407409  ldr      w9, [x0], #7
//   0x16fd40: 2A1F03E8  mov      w8, wzr
//   0x16fd44: 5AC00929  rev      w9, w9
//   0x16fd48: 6B09011F  cmp      w8, w9
static inline uint64_t fde_func_1411_0x16fd3c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x16fd3cULL ^ (static_cast<uint64_t>(0xb8407409ULL) << 13);
    acc = (acc + a1 + 0x2a1f03e8ULL) ^ 0x08ddc0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1412 | PC: 0x16fe64 | FDE: 0x08de28 | Size: 256 bytes
// Khung tháo gỡ #1412 | Địa chỉ PC: 0x16fe64 | Địa chỉ FDE: 0x08de28 | Kích thước: 256 bytes
//   0x16fe64: F81F0FFE  str      x30, [sp, #-0x10]!
//   0x16fe68: F940842A  ldr      x10, [x1, #0x108]
//   0x16fe6c: 91004009  add      x9, x0, #0x10
//   0x16fe70: 9400440B  bl       #0x180e9c
static inline uint64_t fde_func_1412_0x16fe64(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x16fe64ULL ^ (static_cast<uint64_t>(0xf81f0ffeULL) << 13);
    acc = (acc + a1 + 0xf940842aULL) ^ 0x08de28ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1413 | PC: 0x1700ec | FDE: 0x08de90 | Size: 256 bytes
// Khung tháo gỡ #1413 | Địa chỉ PC: 0x1700ec | Địa chỉ FDE: 0x08de90 | Kích thước: 256 bytes
//   0x1700ec: F81F0FFE  str      x30, [sp, #-0x10]!
//   0x1700f0: B9000FE1  str      w1, [sp, #0xc]
//   0x1700f4: 9400572E  bl       #0x185dac
//   0x1700f8: 94000095  bl       #0x17034c
static inline uint64_t fde_func_1413_0x1700ec(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1700ecULL ^ (static_cast<uint64_t>(0xf81f0ffeULL) << 13);
    acc = (acc + a1 + 0xb9000fe1ULL) ^ 0x08de90ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1414 | PC: 0x170254 | FDE: 0x08def8 | Size: 256 bytes
// Khung tháo gỡ #1414 | Địa chỉ PC: 0x170254 | Địa chỉ FDE: 0x08def8 | Kích thước: 256 bytes
//   0x170254: F940180C  ldr      x12, [x0, #0x30]
//   0x170258: F9400008  ldr      x8, [x0]
//   0x17025c: A9442809  ldp      x9, x10, [x0, #0x40]
//   0x170260: 5280018B  mov      w11, #0xc
static inline uint64_t fde_func_1414_0x170254(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x170254ULL ^ (static_cast<uint64_t>(0xf940180cULL) << 13);
    acc = (acc + a1 + 0xf9400008ULL) ^ 0x08def8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1415 | PC: 0x1704a8 | FDE: 0x08df60 | Size: 256 bytes
// Khung tháo gỡ #1415 | Địa chỉ PC: 0x1704a8 | Địa chỉ FDE: 0x08df60 | Kích thước: 256 bytes
//   0x1704a8: B9400028  ldr      w8, [x1]
//   0x1704ac: 3100051F  cmn      w8, #1
//   0x1704b0: 54000320  b.eq     #0x170514
//   0x1704b4: F9400C0A  ldr      x10, [x0, #0x18]
static inline uint64_t fde_func_1415_0x1704a8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1704a8ULL ^ (static_cast<uint64_t>(0xb9400028ULL) << 13);
    acc = (acc + a1 + 0x3100051fULL) ^ 0x08df60ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1416 | PC: 0x170644 | FDE: 0x08dfc0 | Size: 256 bytes
// Khung tháo gỡ #1416 | Địa chỉ PC: 0x170644 | Địa chỉ FDE: 0x08dfc0 | Kích thước: 256 bytes
//   0x170644: B9400028  ldr      w8, [x1]
//   0x170648: 3100051F  cmn      w8, #1
//   0x17064c: 540004E0  b.eq     #0x1706e8
//   0x170650: F9400C0A  ldr      x10, [x0, #0x18]
static inline uint64_t fde_func_1416_0x170644(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x170644ULL ^ (static_cast<uint64_t>(0xb9400028ULL) << 13);
    acc = (acc + a1 + 0x3100051fULL) ^ 0x08dfc0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1417 | PC: 0x1708d8 | FDE: 0x08e020 | Size: 256 bytes
// Khung tháo gỡ #1417 | Địa chỉ PC: 0x1708d8 | Địa chỉ FDE: 0x08e020 | Kích thước: 256 bytes
//   0x1708d8: B9400028  ldr      w8, [x1]
//   0x1708dc: 11000509  add      w9, w8, #1
//   0x1708e0: 53107D28  lsr      w8, w9, #0x10
//   0x1708e4: 35000388  cbnz     w8, #0x170954
static inline uint64_t fde_func_1417_0x1708d8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1708d8ULL ^ (static_cast<uint64_t>(0xb9400028ULL) << 13);
    acc = (acc + a1 + 0x11000509ULL) ^ 0x08e020ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1418 | PC: 0x170a20 | FDE: 0x08e080 | Size: 256 bytes
// Khung tháo gỡ #1418 | Địa chỉ PC: 0x170a20 | Địa chỉ FDE: 0x08e080 | Kích thước: 256 bytes
//   0x170a20: F81F0FFE  str      x30, [sp, #-0x10]!
//   0x170a24: 53107C28  lsr      w8, w1, #0x10
//   0x170a28: B9000FE1  str      w1, [sp, #0xc]
//   0x170a2c: 34000068  cbz      w8, #0x170a38
static inline uint64_t fde_func_1418_0x170a20(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x170a20ULL ^ (static_cast<uint64_t>(0xf81f0ffeULL) << 13);
    acc = (acc + a1 + 0x53107c28ULL) ^ 0x08e080ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1419 | PC: 0x170de4 | FDE: 0x08e0f0 | Size: 256 bytes
// Khung tháo gỡ #1419 | Địa chỉ PC: 0x170de4 | Địa chỉ FDE: 0x08e0f0 | Kích thước: 256 bytes
//   0x170de4: F81C0FF9  str      x25, [sp, #-0x40]!
//   0x170de8: A9015FF8  stp      x24, x23, [sp, #0x10]
//   0x170dec: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x170df0: A9034FF4  stp      x20, x19, [sp, #0x30]
static inline uint64_t fde_func_1419_0x170de4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x170de4ULL ^ (static_cast<uint64_t>(0xf81c0ff9ULL) << 13);
    acc = (acc + a1 + 0xa9015ff8ULL) ^ 0x08e0f0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1420 | PC: 0x171648 | FDE: 0x08e180 | Size: 256 bytes
// Khung tháo gỡ #1420 | Địa chỉ PC: 0x171648 | Địa chỉ FDE: 0x08e180 | Kích thước: 256 bytes
//   0x171648: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x17164c: F9400C00  ldr      x0, [x0, #0x18]
//   0x171650: 2A0103F3  mov      w19, w1
//   0x171654: 940000C9  bl       #0x171978
static inline uint64_t fde_func_1420_0x171648(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x171648ULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0xf9400c00ULL) ^ 0x08e180ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1421 | PC: 0x171978 | FDE: 0x08e1e8 | Size: 256 bytes
// Khung tháo gỡ #1421 | Địa chỉ PC: 0x171978 | Địa chỉ FDE: 0x08e1e8 | Kích thước: 256 bytes
//   0x171978: 53107C28  lsr      w8, w1, #0x10
//   0x17197c: 35000288  cbnz     w8, #0x1719cc
//   0x171980: 53087C29  lsr      w9, w1, #8
//   0x171984: 91001808  add      x8, x0, #6
static inline uint64_t fde_func_1421_0x171978(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x171978ULL ^ (static_cast<uint64_t>(0x53107c28ULL) << 13);
    acc = (acc + a1 + 0x35000288ULL) ^ 0x08e1e8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1422 | PC: 0x171a88 | FDE: 0x08e248 | Size: 128 bytes
// Khung tháo gỡ #1422 | Địa chỉ PC: 0x171a88 | Địa chỉ FDE: 0x08e248 | Kích thước: 128 bytes
//   0x171a88: F9400C08  ldr      x8, [x0, #0x18]
//   0x171a8c: F900043F  str      xzr, [x1, #8]
//   0x171a90: 14001D96  b        #0x1790e8
//   0x171a94: F9400008  ldr      x8, [x0]
static inline uint64_t fde_func_1422_0x171a88(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x171a88ULL ^ (static_cast<uint64_t>(0xf9400c08ULL) << 13);
    acc = (acc + a1 + 0xf900043fULL) ^ 0x08e248ULL;
    acc ^= (acc >> 17) * 0x0080ULL;
    return acc;
}

// FDE #1423 | PC: 0x171b08 | FDE: 0x08e2b0 | Size: 256 bytes
// Khung tháo gỡ #1423 | Địa chỉ PC: 0x171b08 | Địa chỉ FDE: 0x08e2b0 | Kích thước: 256 bytes
//   0x171b08: AA1E03E2  mov      x2, x30
//   0x171b0c: 940010CF  bl       #0x175e48
//   0x171b10: AA0203FE  mov      x30, x2
//   0x171b14: A9057BFD  stp      x29, x30, [sp, #0x50]
static inline uint64_t fde_func_1423_0x171b08(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x171b08ULL ^ (static_cast<uint64_t>(0xaa1e03e2ULL) << 13);
    acc = (acc + a1 + 0x940010cfULL) ^ 0x08e2b0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1424 | PC: 0x172140 | FDE: 0x08e338 | Size: 256 bytes
// Khung tháo gỡ #1424 | Địa chỉ PC: 0x172140 | Địa chỉ FDE: 0x08e338 | Kích thước: 256 bytes
//   0x172140: F81F0FFE  str      x30, [sp, #-0x10]!
//   0x172144: AA0203E9  mov      x9, x2
//   0x172148: D37EF408  lsl      x8, x0, #2
//   0x17214c: D37EF422  lsl      x2, x1, #2
static inline uint64_t fde_func_1424_0x172140(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x172140ULL ^ (static_cast<uint64_t>(0xf81f0ffeULL) << 13);
    acc = (acc + a1 + 0xaa0203e9ULL) ^ 0x08e338ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1425 | PC: 0x172798 | FDE: 0x08e3d0 | Size: 256 bytes
// Khung tháo gỡ #1425 | Địa chỉ PC: 0x172798 | Địa chỉ FDE: 0x08e3d0 | Kích thước: 256 bytes
//   0x172798: F81F0FFE  str      x30, [sp, #-0x10]!
//   0x17279c: B9402808  ldr      w8, [x0, #0x28]
//   0x1727a0: 6B080048  subs     w8, w2, w8
//   0x1727a4: 54000284  b.mi     #0x1727f4
static inline uint64_t fde_func_1425_0x172798(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x172798ULL ^ (static_cast<uint64_t>(0xf81f0ffeULL) << 13);
    acc = (acc + a1 + 0xb9402808ULL) ^ 0x08e3d0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1426 | PC: 0x172d98 | FDE: 0x08e450 | Size: 244 bytes
// Khung tháo gỡ #1426 | Địa chỉ PC: 0x172d98 | Địa chỉ FDE: 0x08e450 | Kích thước: 244 bytes
//   0x172d98: 6F00E400  movi     v0.2d, #0000000000000000
//   0x172d9c: AD000040  stp      q0, q0, [x2]
//   0x172da0: B9409028  ldr      w8, [x1, #0x90]
//   0x172da4: B9402009  ldr      w9, [x0, #0x20]
static inline uint64_t fde_func_1426_0x172d98(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x172d98ULL ^ (static_cast<uint64_t>(0x6f00e400ULL) << 13);
    acc = (acc + a1 + 0xad000040ULL) ^ 0x08e450ULL;
    acc ^= (acc >> 17) * 0x00f4ULL;
    return acc;
}

// FDE #1427 | PC: 0x172e8c | FDE: 0x08e4b0 | Size: 256 bytes
// Khung tháo gỡ #1427 | Địa chỉ PC: 0x172e8c | Địa chỉ FDE: 0x08e4b0 | Kích thước: 256 bytes
//   0x172e8c: F81E0FF4  str      x20, [sp, #-0x20]!
//   0x172e90: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x172e94: AA0003F4  mov      x20, x0
//   0x172e98: D0000100  adrp     x0, #0x194000
static inline uint64_t fde_func_1427_0x172e8c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x172e8cULL ^ (static_cast<uint64_t>(0xf81e0ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x08e4b0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1428 | PC: 0x17345c | FDE: 0x08e538 | Size: 256 bytes
// Khung tháo gỡ #1428 | Địa chỉ PC: 0x17345c | Địa chỉ FDE: 0x08e538 | Kích thước: 256 bytes
//   0x17345c: 3903801F  strb     wzr, [x0, #0xe0]
//   0x173460: D65F03C0  ret      
//   0x173464: F9409408  ldr      x8, [x0, #0x128]
//   0x173468: F9400100  ldr      x0, [x8]
static inline uint64_t fde_func_1428_0x17345c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x17345cULL ^ (static_cast<uint64_t>(0x3903801fULL) << 13);
    acc = (acc + a1 + 0xd65f03c0ULL) ^ 0x08e538ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1429 | PC: 0x173a90 | FDE: 0x08e5b0 | Size: 256 bytes
// Khung tháo gỡ #1429 | Địa chỉ PC: 0x173a90 | Địa chỉ FDE: 0x08e5b0 | Kích thước: 256 bytes
//   0x173a90: D10103FF  sub      sp, sp, #0x40
//   0x173a94: A9015BF7  stp      x23, x22, [sp, #0x10]
//   0x173a98: A90253F5  stp      x21, x20, [sp, #0x20]
//   0x173a9c: A9037BF3  stp      x19, x30, [sp, #0x30]
static inline uint64_t fde_func_1429_0x173a90(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x173a90ULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xa9015bf7ULL) ^ 0x08e5b0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1430 | PC: 0x173d74 | FDE: 0x08e630 | Size: 256 bytes
// Khung tháo gỡ #1430 | Địa chỉ PC: 0x173d74 | Địa chỉ FDE: 0x08e630 | Kích thước: 256 bytes
//   0x173d74: 3947C009  ldrb     w9, [x0, #0x1f0]
//   0x173d78: 340000E9  cbz      w9, #0x173d94
//   0x173d7c: F941B809  ldr      x9, [x0, #0x370]
//   0x173d80: 2A0103E8  mov      w8, w1
static inline uint64_t fde_func_1430_0x173d74(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x173d74ULL ^ (static_cast<uint64_t>(0x3947c009ULL) << 13);
    acc = (acc + a1 + 0x340000e9ULL) ^ 0x08e630ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1431 | PC: 0x174800 | FDE: 0x08e6b8 | Size: 256 bytes
// Khung tháo gỡ #1431 | Địa chỉ PC: 0x174800 | Địa chỉ FDE: 0x08e6b8 | Kích thước: 256 bytes
//   0x174800: F9425C09  ldr      x9, [x0, #0x4b8]
//   0x174804: EB21413F  cmp      x9, w1, uxtw
//   0x174808: 54000289  b.ls     #0x174858
//   0x17480c: 79430C08  ldrh     w8, [x0, #0x186]
static inline uint64_t fde_func_1431_0x174800(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x174800ULL ^ (static_cast<uint64_t>(0xf9425c09ULL) << 13);
    acc = (acc + a1 + 0xeb21413fULL) ^ 0x08e6b8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1432 | PC: 0x174a4c | FDE: 0x08e718 | Size: 256 bytes
// Khung tháo gỡ #1432 | Địa chỉ PC: 0x174a4c | Địa chỉ FDE: 0x08e718 | Kích thước: 256 bytes
//   0x174a4c: F9400008  ldr      x8, [x0]
//   0x174a50: F9400029  ldr      x9, [x1]
//   0x174a54: 39400108  ldrb     w8, [x8]
//   0x174a58: 39400129  ldrb     w9, [x9]
static inline uint64_t fde_func_1432_0x174a4c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x174a4cULL ^ (static_cast<uint64_t>(0xf9400008ULL) << 13);
    acc = (acc + a1 + 0xf9400029ULL) ^ 0x08e718ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1433 | PC: 0x174ddc | FDE: 0x08e790 | Size: 256 bytes
// Khung tháo gỡ #1433 | Địa chỉ PC: 0x174ddc | Địa chỉ FDE: 0x08e790 | Kích thước: 256 bytes
//   0x174ddc: AA1E03E1  mov      x1, x30
//   0x174de0: 940006C7  bl       #0x1768fc
//   0x174de4: AA0103FE  mov      x30, x1
//   0x174de8: A9057BF3  stp      x19, x30, [sp, #0x50]
static inline uint64_t fde_func_1433_0x174ddc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x174ddcULL ^ (static_cast<uint64_t>(0xaa1e03e1ULL) << 13);
    acc = (acc + a1 + 0x940006c7ULL) ^ 0x08e790ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1434 | PC: 0x1750b0 | FDE: 0x08e818 | Size: 256 bytes
// Khung tháo gỡ #1434 | Địa chỉ PC: 0x1750b0 | Địa chỉ FDE: 0x08e818 | Kích thước: 256 bytes
//   0x1750b0: B0FFF70A  adrp     x10, #0x56000
//   0x1750b4: B0FFF709  adrp     x9, #0x56000
//   0x1750b8: F1000C5F  cmp      x2, #3
//   0x1750bc: 9118214A  add      x10, x10, #0x608
static inline uint64_t fde_func_1434_0x1750b0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1750b0ULL ^ (static_cast<uint64_t>(0xb0fff70aULL) << 13);
    acc = (acc + a1 + 0xb0fff709ULL) ^ 0x08e818ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1435 | PC: 0x1753f4 | FDE: 0x08e878 | Size: 256 bytes
// Khung tháo gỡ #1435 | Địa chỉ PC: 0x1753f4 | Địa chỉ FDE: 0x08e878 | Kích thước: 256 bytes
//   0x1753f4: F81D0FFC  str      x28, [sp, #-0x30]!
//   0x1753f8: A90153F5  stp      x21, x20, [sp, #0x10]
//   0x1753fc: A9027BF3  stp      x19, x30, [sp, #0x20]
//   0x175400: D14007FF  sub      sp, sp, #1, lsl #12
static inline uint64_t fde_func_1435_0x1753f4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1753f4ULL ^ (static_cast<uint64_t>(0xf81d0ffcULL) << 13);
    acc = (acc + a1 + 0xa90153f5ULL) ^ 0x08e878ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1436 | PC: 0x175718 | FDE: 0x08e8e0 | Size: 200 bytes
// Khung tháo gỡ #1436 | Địa chỉ PC: 0x175718 | Địa chỉ FDE: 0x08e8e0 | Kích thước: 200 bytes
//   0x175718: B9811008  ldrsw    x8, [x0, #0x110]
//   0x17571c: AA1F03E9  mov      x9, xzr
//   0x175720: EB08013F  cmp      x9, x8
//   0x175724: 5400016A  b.ge     #0x175750
static inline uint64_t fde_func_1436_0x175718(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x175718ULL ^ (static_cast<uint64_t>(0xb9811008ULL) << 13);
    acc = (acc + a1 + 0xaa1f03e9ULL) ^ 0x08e8e0ULL;
    acc ^= (acc >> 17) * 0x00c8ULL;
    return acc;
}

// FDE #1437 | PC: 0x1757e0 | FDE: 0x08e940 | Size: 168 bytes
// Khung tháo gỡ #1437 | Địa chỉ PC: 0x1757e0 | Địa chỉ FDE: 0x08e940 | Kích thước: 168 bytes
//   0x1757e0: B9811008  ldrsw    x8, [x0, #0x110]
//   0x1757e4: AA1F03E9  mov      x9, xzr
//   0x1757e8: EB08013F  cmp      x9, x8
//   0x1757ec: 540001AA  b.ge     #0x175820
static inline uint64_t fde_func_1437_0x1757e0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1757e0ULL ^ (static_cast<uint64_t>(0xb9811008ULL) << 13);
    acc = (acc + a1 + 0xaa1f03e9ULL) ^ 0x08e940ULL;
    acc ^= (acc >> 17) * 0x00a8ULL;
    return acc;
}

// FDE #1438 | PC: 0x175888 | FDE: 0x08e9a0 | Size: 40 bytes
// Khung tháo gỡ #1438 | Địa chỉ PC: 0x175888 | Địa chỉ FDE: 0x08e9a0 | Kích thước: 40 bytes
//   0x175888: AA1303E0  mov      x0, x19
//   0x17588c: 17FF6A76  b        #0x150264
//   0x175890: 528179A2  mov      w2, #0xbcd
//   0x175894: AA1603E0  mov      x0, x22
static inline uint64_t fde_func_1438_0x175888(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x175888ULL ^ (static_cast<uint64_t>(0xaa1303e0ULL) << 13);
    acc = (acc + a1 + 0x17ff6a76ULL) ^ 0x08e9a0ULL;
    acc ^= (acc >> 17) * 0x0028ULL;
    return acc;
}

// FDE #1439 | PC: 0x1758b0 | FDE: 0x08ea00 | Size: 128 bytes
// Khung tháo gỡ #1439 | Địa chỉ PC: 0x1758b0 | Địa chỉ FDE: 0x08ea00 | Kích thước: 128 bytes
//   0x1758b0: AA1603E0  mov      x0, x22
//   0x1758b4: 2A1703E1  mov      w1, w23
//   0x1758b8: 17FF5FE3  b        #0x14d844
//   0x1758bc: A90893E3  stp      x3, x4, [sp, #0x88]
static inline uint64_t fde_func_1439_0x1758b0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1758b0ULL ^ (static_cast<uint64_t>(0xaa1603e0ULL) << 13);
    acc = (acc + a1 + 0x2a1703e1ULL) ^ 0x08ea00ULL;
    acc ^= (acc >> 17) * 0x0080ULL;
    return acc;
}

// FDE #1440 | PC: 0x175930 | FDE: 0x08ea60 | Size: 72 bytes
// Khung tháo gỡ #1440 | Địa chỉ PC: 0x175930 | Địa chỉ FDE: 0x08ea60 | Kích thước: 72 bytes
//   0x175930: F9400FE9  ldr      x9, [sp, #0x18]
//   0x175934: EB09011F  cmp      x8, x9
//   0x175938: D65F03C0  ret      
//   0x17593c: F94097E9  ldr      x9, [sp, #0x128]
static inline uint64_t fde_func_1440_0x175930(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x175930ULL ^ (static_cast<uint64_t>(0xf9400fe9ULL) << 13);
    acc = (acc + a1 + 0xeb09011fULL) ^ 0x08ea60ULL;
    acc ^= (acc >> 17) * 0x0048ULL;
    return acc;
}

// FDE #1441 | PC: 0x175978 | FDE: 0x08eac0 | Size: 44 bytes
// Khung tháo gỡ #1441 | Địa chỉ PC: 0x175978 | Địa chỉ FDE: 0x08eac0 | Kích thước: 44 bytes
//   0x175978: AA1603E0  mov      x0, x22
//   0x17597c: 2A1703E1  mov      w1, w23
//   0x175980: 17FF5EF4  b        #0x14d550
//   0x175984: 910063E0  add      x0, sp, #0x18
static inline uint64_t fde_func_1441_0x175978(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x175978ULL ^ (static_cast<uint64_t>(0xaa1603e0ULL) << 13);
    acc = (acc + a1 + 0x2a1703e1ULL) ^ 0x08eac0ULL;
    acc ^= (acc >> 17) * 0x002cULL;
    return acc;
}

// FDE #1442 | PC: 0x1759a4 | FDE: 0x08eb20 | Size: 48 bytes
// Khung tháo gỡ #1442 | Địa chỉ PC: 0x1759a4 | Địa chỉ FDE: 0x08eb20 | Kích thước: 48 bytes
//   0x1759a4: AA1403E0  mov      x0, x20
//   0x1759a8: 17FDBEA3  b        #0xe5434
//   0x1759ac: F9400660  ldr      x0, [x19, #8]
//   0x1759b0: 2A1F03E1  mov      w1, wzr
static inline uint64_t fde_func_1442_0x1759a4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1759a4ULL ^ (static_cast<uint64_t>(0xaa1403e0ULL) << 13);
    acc = (acc + a1 + 0x17fdbea3ULL) ^ 0x08eb20ULL;
    acc ^= (acc >> 17) * 0x0030ULL;
    return acc;
}

// FDE #1443 | PC: 0x1759d4 | FDE: 0x08eb80 | Size: 52 bytes
// Khung tháo gỡ #1443 | Địa chỉ PC: 0x1759d4 | Địa chỉ FDE: 0x08eb80 | Kích thước: 52 bytes
//   0x1759d4: AA1303E0  mov      x0, x19
//   0x1759d8: 2A1F03E1  mov      w1, wzr
//   0x1759dc: 17FF6A22  b        #0x150264
//   0x1759e0: F94007E9  ldr      x9, [sp, #8]
static inline uint64_t fde_func_1443_0x1759d4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1759d4ULL ^ (static_cast<uint64_t>(0xaa1303e0ULL) << 13);
    acc = (acc + a1 + 0x2a1f03e1ULL) ^ 0x08eb80ULL;
    acc ^= (acc >> 17) * 0x0034ULL;
    return acc;
}

// FDE #1444 | PC: 0x175a08 | FDE: 0x08ebe0 | Size: 112 bytes
// Khung tháo gỡ #1444 | Địa chỉ PC: 0x175a08 | Địa chỉ FDE: 0x08ebe0 | Kích thước: 112 bytes
//   0x175a08: F81F0FFE  str      x30, [sp, #-0x10]!
//   0x175a0c: D53BD05A  mrs      x26, tpidr_el0
//   0x175a10: F9401748  ldr      x8, [x26, #0x28]
//   0x175a14: 9100C018  add      x24, x0, #0x30
static inline uint64_t fde_func_1444_0x175a08(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x175a08ULL ^ (static_cast<uint64_t>(0xf81f0ffeULL) << 13);
    acc = (acc + a1 + 0xd53bd05aULL) ^ 0x08ebe0ULL;
    acc ^= (acc >> 17) * 0x0070ULL;
    return acc;
}

// FDE #1445 | PC: 0x175a78 | FDE: 0x08ec48 | Size: 96 bytes
// Khung tháo gỡ #1445 | Địa chỉ PC: 0x175a78 | Địa chỉ FDE: 0x08ec48 | Kích thước: 96 bytes
//   0x175a78: 2A1F03E0  mov      w0, wzr
//   0x175a7c: D65F03C0  ret      
//   0x175a80: F9400A88  ldr      x8, [x20, #0x10]
//   0x175a84: AA1403E0  mov      x0, x20
static inline uint64_t fde_func_1445_0x175a78(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x175a78ULL ^ (static_cast<uint64_t>(0x2a1f03e0ULL) << 13);
    acc = (acc + a1 + 0xd65f03c0ULL) ^ 0x08ec48ULL;
    acc ^= (acc >> 17) * 0x0060ULL;
    return acc;
}

// FDE #1446 | PC: 0x175ad8 | FDE: 0x08eca8 | Size: 44 bytes
// Khung tháo gỡ #1446 | Địa chỉ PC: 0x175ad8 | Địa chỉ FDE: 0x08eca8 | Kích thước: 44 bytes
//   0x175ad8: 2A1F03E4  mov      w4, wzr
//   0x175adc: 17FE2473  b        #0xfeca8
//   0x175ae0: A94153F5  ldp      x21, x20, [sp, #0x10]
//   0x175ae4: 9100C3FF  add      sp, sp, #0x30
static inline uint64_t fde_func_1446_0x175ad8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x175ad8ULL ^ (static_cast<uint64_t>(0x2a1f03e4ULL) << 13);
    acc = (acc + a1 + 0x17fe2473ULL) ^ 0x08eca8ULL;
    acc ^= (acc >> 17) * 0x002cULL;
    return acc;
}

// FDE #1447 | PC: 0x175b04 | FDE: 0x08ed08 | Size: 52 bytes
// Khung tháo gỡ #1447 | Địa chỉ PC: 0x175b04 | Địa chỉ FDE: 0x08ed08 | Kích thước: 52 bytes
//   0x175b04: F9400008  ldr      x8, [x0]
//   0x175b08: F9401508  ldr      x8, [x8, #0x28]
//   0x175b0c: D61F0100  br       x8
//   0x175b10: 9100C3FF  add      sp, sp, #0x30
static inline uint64_t fde_func_1447_0x175b04(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x175b04ULL ^ (static_cast<uint64_t>(0xf9400008ULL) << 13);
    acc = (acc + a1 + 0xf9401508ULL) ^ 0x08ed08ULL;
    acc ^= (acc >> 17) * 0x0034ULL;
    return acc;
}

// FDE #1448 | PC: 0x175b38 | FDE: 0x08ed68 | Size: 72 bytes
// Khung tháo gỡ #1448 | Địa chỉ PC: 0x175b38 | Địa chỉ FDE: 0x08ed68 | Kích thước: 72 bytes
//   0x175b38: 885F7D09  ldxr     w9, [x8]
//   0x175b3c: 11000529  add      w9, w9, #1
//   0x175b40: 880A7D09  stxr     w10, w9, [x8]
//   0x175b44: D65F03C0  ret      
static inline uint64_t fde_func_1448_0x175b38(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x175b38ULL ^ (static_cast<uint64_t>(0x885f7d09ULL) << 13);
    acc = (acc + a1 + 0x11000529ULL) ^ 0x08ed68ULL;
    acc ^= (acc >> 17) * 0x0048ULL;
    return acc;
}

// FDE #1449 | PC: 0x175b80 | FDE: 0x08edc8 | Size: 116 bytes
// Khung tháo gỡ #1449 | Địa chỉ PC: 0x175b80 | Địa chỉ FDE: 0x08edc8 | Kích thước: 116 bytes
//   0x175b80: F9401508  ldr      x8, [x8, #0x28]
//   0x175b84: D61F0100  br       x8
//   0x175b88: A94453F5  ldp      x21, x20, [sp, #0x40]
//   0x175b8c: A9435BF7  ldp      x23, x22, [sp, #0x30]
static inline uint64_t fde_func_1449_0x175b80(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x175b80ULL ^ (static_cast<uint64_t>(0xf9401508ULL) << 13);
    acc = (acc + a1 + 0xd61f0100ULL) ^ 0x08edc8ULL;
    acc ^= (acc >> 17) * 0x0074ULL;
    return acc;
}

// FDE #1450 | PC: 0x175bf4 | FDE: 0x08ee30 | Size: 48 bytes
// Khung tháo gỡ #1450 | Địa chỉ PC: 0x175bf4 | Địa chỉ FDE: 0x08ee30 | Kích thước: 48 bytes
//   0x175bf4: AA0003F3  mov      x19, x0
//   0x175bf8: AA0103F4  mov      x20, x1
//   0x175bfc: D65F03C0  ret      
//   0x175c00: F94027E9  ldr      x9, [sp, #0x48]
static inline uint64_t fde_func_1450_0x175bf4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x175bf4ULL ^ (static_cast<uint64_t>(0xaa0003f3ULL) << 13);
    acc = (acc + a1 + 0xaa0103f4ULL) ^ 0x08ee30ULL;
    acc ^= (acc >> 17) * 0x0030ULL;
    return acc;
}

// FDE #1451 | PC: 0x175c24 | FDE: 0x08ee90 | Size: 36 bytes
// Khung tháo gỡ #1451 | Địa chỉ PC: 0x175c24 | Địa chỉ FDE: 0x08ee90 | Kích thước: 36 bytes
//   0x175c24: 910043E0  add      x0, sp, #0x10
//   0x175c28: F9000BE8  str      x8, [sp, #0x10]
//   0x175c2c: 1400479D  b        #0x187aa0
//   0x175c30: A8C253F5  ldp      x21, x20, [sp], #0x20
static inline uint64_t fde_func_1451_0x175c24(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x175c24ULL ^ (static_cast<uint64_t>(0x910043e0ULL) << 13);
    acc = (acc + a1 + 0xf9000be8ULL) ^ 0x08ee90ULL;
    acc ^= (acc >> 17) * 0x0024ULL;
    return acc;
}

// FDE #1452 | PC: 0x175c48 | FDE: 0x08eef0 | Size: 104 bytes
// Khung tháo gỡ #1452 | Địa chỉ PC: 0x175c48 | Địa chỉ FDE: 0x08eef0 | Kích thước: 104 bytes
//   0x175c48: A95653F5  ldp      x21, x20, [sp, #0x160]
//   0x175c4c: A9555BF7  ldp      x23, x22, [sp, #0x150]
//   0x175c50: A95463F9  ldp      x25, x24, [sp, #0x140]
//   0x175c54: A9536BFC  ldp      x28, x26, [sp, #0x130]
static inline uint64_t fde_func_1452_0x175c48(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x175c48ULL ^ (static_cast<uint64_t>(0xa95653f5ULL) << 13);
    acc = (acc + a1 + 0xa9555bf7ULL) ^ 0x08eef0ULL;
    acc ^= (acc >> 17) * 0x0068ULL;
    return acc;
}

// FDE #1453 | PC: 0x175cb0 | FDE: 0x08ef50 | Size: 52 bytes
// Khung tháo gỡ #1453 | Địa chỉ PC: 0x175cb0 | Địa chỉ FDE: 0x08ef50 | Kích thước: 52 bytes
//   0x175cb0: F9400668  ldr      x8, [x19, #8]
//   0x175cb4: AA0003F5  mov      x21, x0
//   0x175cb8: 910083E0  add      x0, sp, #0x20
//   0x175cbc: F90013E8  str      x8, [sp, #0x20]
static inline uint64_t fde_func_1453_0x175cb0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x175cb0ULL ^ (static_cast<uint64_t>(0xf9400668ULL) << 13);
    acc = (acc + a1 + 0xaa0003f5ULL) ^ 0x08ef50ULL;
    acc ^= (acc >> 17) * 0x0034ULL;
    return acc;
}

// FDE #1454 | PC: 0x175ce4 | FDE: 0x08efb0 | Size: 76 bytes
// Khung tháo gỡ #1454 | Địa chỉ PC: 0x175ce4 | Địa chỉ FDE: 0x08efb0 | Kích thước: 76 bytes
//   0x175ce4: F94023E8  ldr      x8, [sp, #0x40]
//   0x175ce8: F94013E9  ldr      x9, [sp, #0x20]
//   0x175cec: 910023E0  add      x0, sp, #8
//   0x175cf0: F9400108  ldr      x8, [x8]
static inline uint64_t fde_func_1454_0x175ce4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x175ce4ULL ^ (static_cast<uint64_t>(0xf94023e8ULL) << 13);
    acc = (acc + a1 + 0xf94013e9ULL) ^ 0x08efb0ULL;
    acc ^= (acc >> 17) * 0x004cULL;
    return acc;
}

// FDE #1455 | PC: 0x175d30 | FDE: 0x08f010 | Size: 116 bytes
// Khung tháo gỡ #1455 | Địa chỉ PC: 0x175d30 | Địa chỉ FDE: 0x08f010 | Kích thước: 116 bytes
//   0x175d30: F9401FE9  ldr      x9, [sp, #0x38]
//   0x175d34: EB09011F  cmp      x8, x9
//   0x175d38: D65F03C0  ret      
//   0x175d3c: 9101C3FF  add      sp, sp, #0x70
static inline uint64_t fde_func_1455_0x175d30(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x175d30ULL ^ (static_cast<uint64_t>(0xf9401fe9ULL) << 13);
    acc = (acc + a1 + 0xeb09011fULL) ^ 0x08f010ULL;
    acc ^= (acc >> 17) * 0x0074ULL;
    return acc;
}

// FDE #1456 | PC: 0x175da4 | FDE: 0x08f070 | Size: 108 bytes
// Khung tháo gỡ #1456 | Địa chỉ PC: 0x175da4 | Địa chỉ FDE: 0x08f070 | Kích thước: 108 bytes
//   0x175da4: F81F0FFE  str      x30, [sp, #-0x10]!
//   0x175da8: 97FCD04E  bl       #0xa9ee0
//   0x175dac: B0FFF5E1  adrp     x1, #0x32000
//   0x175db0: 91004260  add      x0, x19, #0x10
static inline uint64_t fde_func_1456_0x175da4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x175da4ULL ^ (static_cast<uint64_t>(0xf81f0ffeULL) << 13);
    acc = (acc + a1 + 0x97fcd04eULL) ^ 0x08f070ULL;
    acc ^= (acc >> 17) * 0x006cULL;
    return acc;
}

// FDE #1457 | PC: 0x175e10 | FDE: 0x08f0d8 | Size: 80 bytes
// Khung tháo gỡ #1457 | Địa chỉ PC: 0x175e10 | Địa chỉ FDE: 0x08f0d8 | Kích thước: 80 bytes
//   0x175e10: 910063E0  add      x0, sp, #0x18
//   0x175e14: 12800002  mov      w2, #-1
//   0x175e18: AA1F03E3  mov      x3, xzr
//   0x175e1c: AA1F03E4  mov      x4, xzr
static inline uint64_t fde_func_1457_0x175e10(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x175e10ULL ^ (static_cast<uint64_t>(0x910063e0ULL) << 13);
    acc = (acc + a1 + 0x12800002ULL) ^ 0x08f0d8ULL;
    acc ^= (acc >> 17) * 0x0050ULL;
    return acc;
}

// FDE #1458 | PC: 0x175e60 | FDE: 0x08f138 | Size: 84 bytes
// Khung tháo gỡ #1458 | Địa chỉ PC: 0x175e60 | Địa chỉ FDE: 0x08f138 | Kích thước: 84 bytes
//   0x175e60: D53BD055  mrs      x21, tpidr_el0
//   0x175e64: F94016A8  ldr      x8, [x21, #0x28]
//   0x175e68: AA0103F3  mov      x19, x1
//   0x175e6c: D65F03C0  ret      
static inline uint64_t fde_func_1458_0x175e60(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x175e60ULL ^ (static_cast<uint64_t>(0xd53bd055ULL) << 13);
    acc = (acc + a1 + 0xf94016a8ULL) ^ 0x08f138ULL;
    acc ^= (acc >> 17) * 0x0054ULL;
    return acc;
}

// FDE #1459 | PC: 0x175eb4 | FDE: 0x08f198 | Size: 72 bytes
// Khung tháo gỡ #1459 | Địa chỉ PC: 0x175eb4 | Địa chỉ FDE: 0x08f198 | Kích thước: 72 bytes
//   0x175eb4: 52800021  mov      w1, #1
//   0x175eb8: AA1303E0  mov      x0, x19
//   0x175ebc: 4EA01C08  mov      v8.16b, v0.16b
//   0x175ec0: 17FF6916  b        #0x150318
static inline uint64_t fde_func_1459_0x175eb4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x175eb4ULL ^ (static_cast<uint64_t>(0x52800021ULL) << 13);
    acc = (acc + a1 + 0xaa1303e0ULL) ^ 0x08f198ULL;
    acc ^= (acc >> 17) * 0x0048ULL;
    return acc;
}

// FDE #1460 | PC: 0x175efc | FDE: 0x08f1f8 | Size: 56 bytes
// Khung tháo gỡ #1460 | Địa chỉ PC: 0x175efc | Địa chỉ FDE: 0x08f1f8 | Kích thước: 56 bytes
//   0x175efc: F0FFF601  adrp     x1, #0x38000
//   0x175f00: 913A8821  add      x1, x1, #0xea2
//   0x175f04: 17FCCA7C  b        #0xa88f4
//   0x175f08: F0FFF601  adrp     x1, #0x38000
static inline uint64_t fde_func_1460_0x175efc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x175efcULL ^ (static_cast<uint64_t>(0xf0fff601ULL) << 13);
    acc = (acc + a1 + 0x913a8821ULL) ^ 0x08f1f8ULL;
    acc ^= (acc >> 17) * 0x0038ULL;
    return acc;
}

// FDE #1461 | PC: 0x175f34 | FDE: 0x08f258 | Size: 88 bytes
// Khung tháo gỡ #1461 | Địa chỉ PC: 0x175f34 | Địa chỉ FDE: 0x08f258 | Kích thước: 88 bytes
//   0x175f34: A90107E0  stp      x0, x1, [sp, #0x10]
//   0x175f38: 910043E0  add      x0, sp, #0x10
//   0x175f3c: 14004EA5  b        #0x1899d0
//   0x175f40: A9464FF4  ldp      x20, x19, [sp, #0x60]
static inline uint64_t fde_func_1461_0x175f34(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x175f34ULL ^ (static_cast<uint64_t>(0xa90107e0ULL) << 13);
    acc = (acc + a1 + 0x910043e0ULL) ^ 0x08f258ULL;
    acc ^= (acc >> 17) * 0x0058ULL;
    return acc;
}

// FDE #1462 | PC: 0x175f8c | FDE: 0x08f2b8 | Size: 72 bytes
// Khung tháo gỡ #1462 | Địa chỉ PC: 0x175f8c | Địa chỉ FDE: 0x08f2b8 | Kích thước: 72 bytes
//   0x175f8c: F94003E0  ldr      x0, [sp]
//   0x175f90: F90003FF  str      xzr, [sp]
//   0x175f94: D65F03C0  ret      
//   0x175f98: AA1603E0  mov      x0, x22
static inline uint64_t fde_func_1462_0x175f8c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x175f8cULL ^ (static_cast<uint64_t>(0xf94003e0ULL) << 13);
    acc = (acc + a1 + 0xf90003ffULL) ^ 0x08f2b8ULL;
    acc ^= (acc >> 17) * 0x0048ULL;
    return acc;
}

// FDE #1463 | PC: 0x175fd4 | FDE: 0x08f318 | Size: 72 bytes
// Khung tháo gỡ #1463 | Địa chỉ PC: 0x175fd4 | Địa chỉ FDE: 0x08f318 | Kích thước: 72 bytes
//   0x175fd4: 910203FF  add      sp, sp, #0x80
//   0x175fd8: D65F03C0  ret      
//   0x175fdc: D1000408  sub      x8, x0, #1
//   0x175fe0: DAC01108  clz      x8, x8
static inline uint64_t fde_func_1463_0x175fd4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x175fd4ULL ^ (static_cast<uint64_t>(0x910203ffULL) << 13);
    acc = (acc + a1 + 0xd65f03c0ULL) ^ 0x08f318ULL;
    acc ^= (acc >> 17) * 0x0048ULL;
    return acc;
}

// FDE #1464 | PC: 0x17601c | FDE: 0x08f378 | Size: 68 bytes
// Khung tháo gỡ #1464 | Địa chỉ PC: 0x17601c | Địa chỉ FDE: 0x08f378 | Kích thước: 68 bytes
//   0x17601c: F900010F  str      x15, [x8]
//   0x176020: F940026F  ldr      x15, [x19]
//   0x176024: F86D79EF  ldr      x15, [x15, x13, lsl #3]
//   0x176028: F94001EF  ldr      x15, [x15]
static inline uint64_t fde_func_1464_0x17601c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x17601cULL ^ (static_cast<uint64_t>(0xf900010fULL) << 13);
    acc = (acc + a1 + 0xf940026fULL) ^ 0x08f378ULL;
    acc ^= (acc >> 17) * 0x0044ULL;
    return acc;
}

// FDE #1465 | PC: 0x176060 | FDE: 0x08f3d8 | Size: 96 bytes
// Khung tháo gỡ #1465 | Địa chỉ PC: 0x176060 | Địa chỉ FDE: 0x08f3d8 | Kích thước: 96 bytes
//   0x176060: F9400108  ldr      x8, [x8]
//   0x176064: D61F0100  br       x8
//   0x176068: F1000EDF  cmp      x22, #3
//   0x17606c: D10006C8  sub      x8, x22, #1
static inline uint64_t fde_func_1465_0x176060(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x176060ULL ^ (static_cast<uint64_t>(0xf9400108ULL) << 13);
    acc = (acc + a1 + 0xd61f0100ULL) ^ 0x08f3d8ULL;
    acc ^= (acc >> 17) * 0x0060ULL;
    return acc;
}

// FDE #1466 | PC: 0x1760c0 | FDE: 0x08f438 | Size: 96 bytes
// Khung tháo gỡ #1466 | Địa chỉ PC: 0x1760c0 | Địa chỉ FDE: 0x08f438 | Kích thước: 96 bytes
//   0x1760c0: 914007E8  add      x8, sp, #1, lsl #12
//   0x1760c4: 914007E1  add      x1, sp, #1, lsl #12
//   0x1760c8: 91030108  add      x8, x8, #0xc0
//   0x1760cc: 91030021  add      x1, x1, #0xc0
static inline uint64_t fde_func_1466_0x1760c0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1760c0ULL ^ (static_cast<uint64_t>(0x914007e8ULL) << 13);
    acc = (acc + a1 + 0x914007e1ULL) ^ 0x08f438ULL;
    acc ^= (acc >> 17) * 0x0060ULL;
    return acc;
}

// FDE #1467 | PC: 0x176120 | FDE: 0x08f498 | Size: 104 bytes
// Khung tháo gỡ #1467 | Địa chỉ PC: 0x176120 | Địa chỉ FDE: 0x08f498 | Kích thước: 104 bytes
//   0x176120: AA1403E1  mov      x1, x20
//   0x176124: AA1303E2  mov      x2, x19
//   0x176128: AA0003F5  mov      x21, x0
//   0x17612c: 14004425  b        #0x1871c0
static inline uint64_t fde_func_1467_0x176120(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x176120ULL ^ (static_cast<uint64_t>(0xaa1403e1ULL) << 13);
    acc = (acc + a1 + 0xaa1303e2ULL) ^ 0x08f498ULL;
    acc ^= (acc >> 17) * 0x0068ULL;
    return acc;
}

// FDE #1468 | PC: 0x176188 | FDE: 0x08f4f8 | Size: 44 bytes
// Khung tháo gỡ #1468 | Địa chỉ PC: 0x176188 | Địa chỉ FDE: 0x08f4f8 | Kích thước: 44 bytes
//   0x176188: F9000BE8  str      x8, [sp, #0x10]
//   0x17618c: 14004645  b        #0x187aa0
//   0x176190: AA1703E0  mov      x0, x23
//   0x176194: 17FDBCA8  b        #0xe5434
static inline uint64_t fde_func_1468_0x176188(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x176188ULL ^ (static_cast<uint64_t>(0xf9000be8ULL) << 13);
    acc = (acc + a1 + 0x14004645ULL) ^ 0x08f4f8ULL;
    acc ^= (acc >> 17) * 0x002cULL;
    return acc;
}

// FDE #1469 | PC: 0x1761b4 | FDE: 0x08f558 | Size: 148 bytes
// Khung tháo gỡ #1469 | Địa chỉ PC: 0x1761b4 | Địa chỉ FDE: 0x08f558 | Kích thước: 148 bytes
//   0x1761b4: A90817E4  stp      x4, x5, [sp, #0x80]
//   0x1761b8: A9091FE6  stp      x6, x7, [sp, #0x90]
//   0x1761bc: AD0007E0  stp      q0, q1, [sp]
//   0x1761c0: AD010FE2  stp      q2, q3, [sp, #0x20]
static inline uint64_t fde_func_1469_0x1761b4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1761b4ULL ^ (static_cast<uint64_t>(0xa90817e4ULL) << 13);
    acc = (acc + a1 + 0xa9091fe6ULL) ^ 0x08f558ULL;
    acc ^= (acc >> 17) * 0x0094ULL;
    return acc;
}

// FDE #1470 | PC: 0x176248 | FDE: 0x08f5b8 | Size: 124 bytes
// Khung tháo gỡ #1470 | Địa chỉ PC: 0x176248 | Địa chỉ FDE: 0x08f5b8 | Kích thước: 124 bytes
//   0x176248: AA1603E0  mov      x0, x22
//   0x17624c: 2A1703E1  mov      w1, w23
//   0x176250: 17FF5CEA  b        #0x14d5f8
//   0x176254: 2A0403E6  mov      w6, w4
static inline uint64_t fde_func_1470_0x176248(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x176248ULL ^ (static_cast<uint64_t>(0xaa1603e0ULL) << 13);
    acc = (acc + a1 + 0x2a1703e1ULL) ^ 0x08f5b8ULL;
    acc ^= (acc >> 17) * 0x007cULL;
    return acc;
}

// FDE #1471 | PC: 0x1762c4 | FDE: 0x08f618 | Size: 84 bytes
// Khung tháo gỡ #1471 | Địa chỉ PC: 0x1762c4 | Địa chỉ FDE: 0x08f618 | Kích thước: 84 bytes
//   0x1762c4: D53BD056  mrs      x22, tpidr_el0
//   0x1762c8: F94016C8  ldr      x8, [x22, #0x28]
//   0x1762cc: AA0103F3  mov      x19, x1
//   0x1762d0: D65F03C0  ret      
static inline uint64_t fde_func_1471_0x1762c4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1762c4ULL ^ (static_cast<uint64_t>(0xd53bd056ULL) << 13);
    acc = (acc + a1 + 0xf94016c8ULL) ^ 0x08f618ULL;
    acc ^= (acc >> 17) * 0x0054ULL;
    return acc;
}

// FDE #1472 | PC: 0x176318 | FDE: 0x08f678 | Size: 60 bytes
// Khung tháo gỡ #1472 | Địa chỉ PC: 0x176318 | Địa chỉ FDE: 0x08f678 | Kích thước: 60 bytes
//   0x176318: F9000BE0  str      x0, [sp, #0x10]
//   0x17631c: 910043E0  add      x0, sp, #0x10
//   0x176320: 14004D0C  b        #0x189750
//   0x176324: F90003E0  str      x0, [sp]
static inline uint64_t fde_func_1472_0x176318(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x176318ULL ^ (static_cast<uint64_t>(0xf9000be0ULL) << 13);
    acc = (acc + a1 + 0x910043e0ULL) ^ 0x08f678ULL;
    acc ^= (acc >> 17) * 0x003cULL;
    return acc;
}

// FDE #1473 | PC: 0x176354 | FDE: 0x08f6d8 | Size: 84 bytes
// Khung tháo gỡ #1473 | Địa chỉ PC: 0x176354 | Địa chỉ FDE: 0x08f6d8 | Kích thước: 84 bytes
//   0x176354: 910063E0  add      x0, sp, #0x18
//   0x176358: AA1F03E3  mov      x3, xzr
//   0x17635c: AA1F03E5  mov      x5, xzr
//   0x176360: 17FEE567  b        #0x12f8fc
static inline uint64_t fde_func_1473_0x176354(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x176354ULL ^ (static_cast<uint64_t>(0x910063e0ULL) << 13);
    acc = (acc + a1 + 0xaa1f03e3ULL) ^ 0x08f6d8ULL;
    acc ^= (acc >> 17) * 0x0054ULL;
    return acc;
}

// FDE #1474 | PC: 0x1763a8 | FDE: 0x08f738 | Size: 72 bytes
// Khung tháo gỡ #1474 | Địa chỉ PC: 0x1763a8 | Địa chỉ FDE: 0x08f738 | Kích thước: 72 bytes
//   0x1763a8: D53BD055  mrs      x21, tpidr_el0
//   0x1763ac: F94016A8  ldr      x8, [x21, #0x28]
//   0x1763b0: 910003F4  mov      x20, sp
//   0x1763b4: F9000FE8  str      x8, [sp, #0x18]
static inline uint64_t fde_func_1474_0x1763a8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1763a8ULL ^ (static_cast<uint64_t>(0xd53bd055ULL) << 13);
    acc = (acc + a1 + 0xf94016a8ULL) ^ 0x08f738ULL;
    acc ^= (acc >> 17) * 0x0048ULL;
    return acc;
}

// FDE #1475 | PC: 0x1763f0 | FDE: 0x08f798 | Size: 64 bytes
// Khung tháo gỡ #1475 | Địa chỉ PC: 0x1763f0 | Địa chỉ FDE: 0x08f798 | Kích thước: 64 bytes
//   0x1763f0: AA1403E0  mov      x0, x20
//   0x1763f4: AA1F03E3  mov      x3, xzr
//   0x1763f8: 14004EA6  b        #0x189e90
//   0x1763fc: 910023E0  add      x0, sp, #8
static inline uint64_t fde_func_1475_0x1763f0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1763f0ULL ^ (static_cast<uint64_t>(0xaa1403e0ULL) << 13);
    acc = (acc + a1 + 0xaa1f03e3ULL) ^ 0x08f798ULL;
    acc ^= (acc >> 17) * 0x0040ULL;
    return acc;
}

// FDE #1476 | PC: 0x176430 | FDE: 0x08f7f8 | Size: 144 bytes
// Khung tháo gỡ #1476 | Địa chỉ PC: 0x176430 | Địa chỉ FDE: 0x08f7f8 | Kích thước: 144 bytes
//   0x176430: F9000028  str      x8, [x1]
//   0x176434: B9400808  ldr      w8, [x0, #8]
//   0x176438: B9000828  str      w8, [x1, #8]
//   0x17643c: D65F03C0  ret      
static inline uint64_t fde_func_1476_0x176430(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x176430ULL ^ (static_cast<uint64_t>(0xf9000028ULL) << 13);
    acc = (acc + a1 + 0xb9400808ULL) ^ 0x08f7f8ULL;
    acc ^= (acc >> 17) * 0x0090ULL;
    return acc;
}

// FDE #1477 | PC: 0x1764c0 | FDE: 0x08f858 | Size: 60 bytes
// Khung tháo gỡ #1477 | Địa chỉ PC: 0x1764c0 | Địa chỉ FDE: 0x08f858 | Kích thước: 60 bytes
//   0x1764c0: 910083E0  add      x0, sp, #0x20
//   0x1764c4: F90013E8  str      x8, [sp, #0x20]
//   0x1764c8: 14004576  b        #0x187aa0
//   0x1764cc: A94453F5  ldp      x21, x20, [sp, #0x40]
static inline uint64_t fde_func_1477_0x1764c0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1764c0ULL ^ (static_cast<uint64_t>(0x910083e0ULL) << 13);
    acc = (acc + a1 + 0xf90013e8ULL) ^ 0x08f858ULL;
    acc ^= (acc >> 17) * 0x003cULL;
    return acc;
}

// FDE #1478 | PC: 0x1764fc | FDE: 0x08f8b8 | Size: 92 bytes
// Khung tháo gỡ #1478 | Địa chỉ PC: 0x1764fc | Địa chỉ FDE: 0x08f8b8 | Kích thước: 92 bytes
//   0x1764fc: D53BD058  mrs      x24, tpidr_el0
//   0x176500: F9401708  ldr      x8, [x24, #0x28]
//   0x176504: D65F03C0  ret      
//   0x176508: AA1403E0  mov      x0, x20
static inline uint64_t fde_func_1478_0x1764fc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1764fcULL ^ (static_cast<uint64_t>(0xd53bd058ULL) << 13);
    acc = (acc + a1 + 0xf9401708ULL) ^ 0x08f8b8ULL;
    acc ^= (acc >> 17) * 0x005cULL;
    return acc;
}

// FDE #1479 | PC: 0x176558 | FDE: 0x08f918 | Size: 72 bytes
// Khung tháo gỡ #1479 | Địa chỉ PC: 0x176558 | Địa chỉ FDE: 0x08f918 | Kích thước: 72 bytes
//   0x176558: 885F7E68  ldxr     w8, [x19]
//   0x17655c: 71000508  subs     w8, w8, #1
//   0x176560: 8809FE68  stlxr    w9, w8, [x19]
//   0x176564: D65F03C0  ret      
static inline uint64_t fde_func_1479_0x176558(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x176558ULL ^ (static_cast<uint64_t>(0x885f7e68ULL) << 13);
    acc = (acc + a1 + 0x71000508ULL) ^ 0x08f918ULL;
    acc ^= (acc >> 17) * 0x0048ULL;
    return acc;
}

// FDE #1480 | PC: 0x1765a0 | FDE: 0x08f978 | Size: 64 bytes
// Khung tháo gỡ #1480 | Địa chỉ PC: 0x1765a0 | Địa chỉ FDE: 0x08f978 | Kích thước: 64 bytes
//   0x1765a0: 52800061  mov      w1, #3
//   0x1765a4: AA1303E0  mov      x0, x19
//   0x1765a8: 4EA01C0A  mov      v10.16b, v0.16b
//   0x1765ac: 17FF675B  b        #0x150318
static inline uint64_t fde_func_1480_0x1765a0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1765a0ULL ^ (static_cast<uint64_t>(0x52800061ULL) << 13);
    acc = (acc + a1 + 0xaa1303e0ULL) ^ 0x08f978ULL;
    acc ^= (acc >> 17) * 0x0040ULL;
    return acc;
}

// FDE #1481 | PC: 0x1765e0 | FDE: 0x08f9d8 | Size: 88 bytes
// Khung tháo gỡ #1481 | Địa chỉ PC: 0x1765e0 | Địa chỉ FDE: 0x08f9d8 | Kích thước: 88 bytes
//   0x1765e0: F9000288  str      x8, [x20]
//   0x1765e4: F9400668  ldr      x8, [x19, #8]
//   0x1765e8: F9000688  str      x8, [x20, #8]
//   0x1765ec: F9400A68  ldr      x8, [x19, #0x10]
static inline uint64_t fde_func_1481_0x1765e0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1765e0ULL ^ (static_cast<uint64_t>(0xf9000288ULL) << 13);
    acc = (acc + a1 + 0xf9400668ULL) ^ 0x08f9d8ULL;
    acc ^= (acc >> 17) * 0x0058ULL;
    return acc;
}

// FDE #1482 | PC: 0x176638 | FDE: 0x08fa38 | Size: 64 bytes
// Khung tháo gỡ #1482 | Địa chỉ PC: 0x176638 | Địa chỉ FDE: 0x08fa38 | Kích thước: 64 bytes
//   0x176638: A9402428  ldp      x8, x9, [x1]
//   0x17663c: A9007C3F  stp      xzr, xzr, [x1]
//   0x176640: AA0003F3  mov      x19, x0
//   0x176644: F9400400  ldr      x0, [x0, #8]
static inline uint64_t fde_func_1482_0x176638(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x176638ULL ^ (static_cast<uint64_t>(0xa9402428ULL) << 13);
    acc = (acc + a1 + 0xa9007c3fULL) ^ 0x08fa38ULL;
    acc ^= (acc >> 17) * 0x0040ULL;
    return acc;
}

// FDE #1483 | PC: 0x176678 | FDE: 0x08fa98 | Size: 100 bytes
// Khung tháo gỡ #1483 | Địa chỉ PC: 0x176678 | Địa chỉ FDE: 0x08fa98 | Kích thước: 100 bytes
//   0x176678: F9400008  ldr      x8, [x0]
//   0x17667c: F9401501  ldr      x1, [x8, #0x28]
//   0x176680: D61F0020  br       x1
//   0x176684: AA1403E0  mov      x0, x20
static inline uint64_t fde_func_1483_0x176678(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x176678ULL ^ (static_cast<uint64_t>(0xf9400008ULL) << 13);
    acc = (acc + a1 + 0xf9401501ULL) ^ 0x08fa98ULL;
    acc ^= (acc >> 17) * 0x0064ULL;
    return acc;
}

// FDE #1484 | PC: 0x1766dc | FDE: 0x08faf8 | Size: 60 bytes
// Khung tháo gỡ #1484 | Địa chỉ PC: 0x1766dc | Địa chỉ FDE: 0x08faf8 | Kích thước: 60 bytes
//   0x1766dc: F9401268  ldr      x8, [x19, #0x20]
//   0x1766e0: F9400660  ldr      x0, [x19, #8]
//   0x1766e4: F100111F  cmp      x8, #4
//   0x1766e8: D65F03C0  ret      
static inline uint64_t fde_func_1484_0x1766dc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1766dcULL ^ (static_cast<uint64_t>(0xf9401268ULL) << 13);
    acc = (acc + a1 + 0xf9400660ULL) ^ 0x08faf8ULL;
    acc ^= (acc >> 17) * 0x003cULL;
    return acc;
}

// FDE #1485 | PC: 0x176718 | FDE: 0x08fb58 | Size: 148 bytes
// Khung tháo gỡ #1485 | Địa chỉ PC: 0x176718 | Địa chỉ FDE: 0x08fb58 | Kích thước: 148 bytes
//   0x176718: F9400008  ldr      x8, [x0]
//   0x17671c: F9400909  ldr      x9, [x8, #0x10]
//   0x176720: 910003E8  mov      x8, sp
//   0x176724: D61F0120  br       x9
static inline uint64_t fde_func_1485_0x176718(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x176718ULL ^ (static_cast<uint64_t>(0xf9400008ULL) << 13);
    acc = (acc + a1 + 0xf9400909ULL) ^ 0x08fb58ULL;
    acc ^= (acc >> 17) * 0x0094ULL;
    return acc;
}

// FDE #1486 | PC: 0x1767ac | FDE: 0x08fbb8 | Size: 80 bytes
// Khung tháo gỡ #1486 | Địa chỉ PC: 0x1767ac | Địa chỉ FDE: 0x08fbb8 | Kích thước: 80 bytes
//   0x1767ac: B9000A7F  str      wzr, [x19, #8]
//   0x1767b0: 3900427F  strb     wzr, [x19, #0x10]
//   0x1767b4: B9003A7F  str      wzr, [x19, #0x38]
//   0x1767b8: FD000260  str      d0, [x19]
static inline uint64_t fde_func_1486_0x1767ac(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1767acULL ^ (static_cast<uint64_t>(0xb9000a7fULL) << 13);
    acc = (acc + a1 + 0x3900427fULL) ^ 0x08fbb8ULL;
    acc ^= (acc >> 17) * 0x0050ULL;
    return acc;
}

// FDE #1487 | PC: 0x1767fc | FDE: 0x08fc18 | Size: 60 bytes
// Khung tháo gỡ #1487 | Địa chỉ PC: 0x1767fc | Địa chỉ FDE: 0x08fc18 | Kích thước: 60 bytes
//   0x1767fc: 7200011F  tst      w8, #1
//   0x176800: 9A890141  csel     x1, x10, x9, eq
//   0x176804: 140042FF  b        #0x187400
//   0x176808: A94353F5  ldp      x21, x20, [sp, #0x30]
static inline uint64_t fde_func_1487_0x1767fc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1767fcULL ^ (static_cast<uint64_t>(0x7200011fULL) << 13);
    acc = (acc + a1 + 0x9a890141ULL) ^ 0x08fc18ULL;
    acc ^= (acc >> 17) * 0x003cULL;
    return acc;
}

// FDE #1488 | PC: 0x176838 | FDE: 0x08fc78 | Size: 68 bytes
// Khung tháo gỡ #1488 | Địa chỉ PC: 0x176838 | Địa chỉ FDE: 0x08fc78 | Kích thước: 68 bytes
//   0x176838: 91006280  add      x0, x20, #0x18
//   0x17683c: F84207F4  ldr      x20, [sp], #0x20
//   0x176840: 17FF6A7D  b        #0x151234
//   0x176844: 91030021  add      x1, x1, #0xc0
static inline uint64_t fde_func_1488_0x176838(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x176838ULL ^ (static_cast<uint64_t>(0x91006280ULL) << 13);
    acc = (acc + a1 + 0xf84207f4ULL) ^ 0x08fc78ULL;
    acc ^= (acc >> 17) * 0x0044ULL;
    return acc;
}

// FDE #1489 | PC: 0x17687c | FDE: 0x08fcd8 | Size: 64 bytes
// Khung tháo gỡ #1489 | Địa chỉ PC: 0x17687c | Địa chỉ FDE: 0x08fcd8 | Kích thước: 64 bytes
//   0x17687c: F90007E0  str      x0, [sp, #8]
//   0x176880: 910023E0  add      x0, sp, #8
//   0x176884: 14004BB3  b        #0x189750
//   0x176888: F9409FE9  ldr      x9, [sp, #0x138]
static inline uint64_t fde_func_1489_0x17687c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x17687cULL ^ (static_cast<uint64_t>(0xf90007e0ULL) << 13);
    acc = (acc + a1 + 0x910023e0ULL) ^ 0x08fcd8ULL;
    acc ^= (acc >> 17) * 0x0040ULL;
    return acc;
}

// FDE #1490 | PC: 0x1768bc | FDE: 0x08fd38 | Size: 64 bytes
// Khung tháo gỡ #1490 | Địa chỉ PC: 0x1768bc | Địa chỉ FDE: 0x08fd38 | Kích thước: 64 bytes
//   0x1768bc: 9105C3FF  add      sp, sp, #0x170
//   0x1768c0: D65F03C0  ret      
//   0x1768c4: F9403FE9  ldr      x9, [sp, #0x78]
//   0x1768c8: EB09011F  cmp      x8, x9
static inline uint64_t fde_func_1490_0x1768bc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1768bcULL ^ (static_cast<uint64_t>(0x9105c3ffULL) << 13);
    acc = (acc + a1 + 0xd65f03c0ULL) ^ 0x08fd38ULL;
    acc ^= (acc >> 17) * 0x0040ULL;
    return acc;
}

// FDE #1491 | PC: 0x1768fc | FDE: 0x08fd98 | Size: 72 bytes
// Khung tháo gỡ #1491 | Địa chỉ PC: 0x1768fc | Địa chỉ FDE: 0x08fd98 | Kích thước: 72 bytes
//   0x1768fc: F81A0FFC  str      x28, [sp, #-0x60]!
//   0x176900: A9016BFB  stp      x27, x26, [sp, #0x10]
//   0x176904: A90263F9  stp      x25, x24, [sp, #0x20]
//   0x176908: A9035BF7  stp      x23, x22, [sp, #0x30]
static inline uint64_t fde_func_1491_0x1768fc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1768fcULL ^ (static_cast<uint64_t>(0xf81a0ffcULL) << 13);
    acc = (acc + a1 + 0xa9016bfbULL) ^ 0x08fd98ULL;
    acc ^= (acc >> 17) * 0x0048ULL;
    return acc;
}

// FDE #1492 | PC: 0x176944 | FDE: 0x08fdf8 | Size: 88 bytes
// Khung tháo gỡ #1492 | Địa chỉ PC: 0x176944 | Địa chỉ FDE: 0x08fdf8 | Kích thước: 88 bytes
//   0x176944: F9402660  ldr      x0, [x19, #0x48]
//   0x176948: 140042BE  b        #0x187440
//   0x17694c: 531F7AC8  lsl      w8, w22, #1
//   0x176950: 1AD70909  udiv     w9, w8, w23
static inline uint64_t fde_func_1492_0x176944(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x176944ULL ^ (static_cast<uint64_t>(0xf9402660ULL) << 13);
    acc = (acc + a1 + 0x140042beULL) ^ 0x08fdf8ULL;
    acc ^= (acc >> 17) * 0x0058ULL;
    return acc;
}

// FDE #1493 | PC: 0x17699c | FDE: 0x08fe58 | Size: 52 bytes
// Khung tháo gỡ #1493 | Địa chỉ PC: 0x17699c | Địa chỉ FDE: 0x08fe58 | Kích thước: 52 bytes
//   0x17699c: 910243FF  add      sp, sp, #0x90
//   0x1769a0: D65F03C0  ret      
//   0x1769a4: F9400008  ldr      x8, [x0]
//   0x1769a8: F9401908  ldr      x8, [x8, #0x30]
static inline uint64_t fde_func_1493_0x17699c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x17699cULL ^ (static_cast<uint64_t>(0x910243ffULL) << 13);
    acc = (acc + a1 + 0xd65f03c0ULL) ^ 0x08fe58ULL;
    acc ^= (acc >> 17) * 0x0034ULL;
    return acc;
}

// FDE #1494 | PC: 0x1769d0 | FDE: 0x08feb8 | Size: 108 bytes
// Khung tháo gỡ #1494 | Địa chỉ PC: 0x1769d0 | Địa chỉ FDE: 0x08feb8 | Kích thước: 108 bytes
//   0x1769d0: AA0003F4  mov      x20, x0
//   0x1769d4: AA0103F3  mov      x19, x1
//   0x1769d8: D65F03C0  ret      
//   0x1769dc: F940C3E9  ldr      x9, [sp, #0x180]
static inline uint64_t fde_func_1494_0x1769d0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1769d0ULL ^ (static_cast<uint64_t>(0xaa0003f4ULL) << 13);
    acc = (acc + a1 + 0xaa0103f3ULL) ^ 0x08feb8ULL;
    acc ^= (acc >> 17) * 0x006cULL;
    return acc;
}

// FDE #1495 | PC: 0x176a3c | FDE: 0x08ff18 | Size: 76 bytes
// Khung tháo gỡ #1495 | Địa chỉ PC: 0x176a3c | Địa chỉ FDE: 0x08ff18 | Kích thước: 76 bytes
//   0x176a3c: 9E670280  fmov     d0, x20
//   0x176a40: F94006D8  ldr      x24, [x22, #8]
//   0x176a44: 0E205800  cnt      v0.8b, v0.8b
//   0x176a48: 2E303800  uaddlv   h0, v0.8b
static inline uint64_t fde_func_1495_0x176a3c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x176a3cULL ^ (static_cast<uint64_t>(0x9e670280ULL) << 13);
    acc = (acc + a1 + 0xf94006d8ULL) ^ 0x08ff18ULL;
    acc ^= (acc >> 17) * 0x004cULL;
    return acc;
}

// FDE #1496 | PC: 0x176a88 | FDE: 0x08ff78 | Size: 96 bytes
// Khung tháo gỡ #1496 | Địa chỉ PC: 0x176a88 | Địa chỉ FDE: 0x08ff78 | Kích thước: 96 bytes
//   0x176a88: D0FFF5E1  adrp     x1, #0x34000
//   0x176a8c: 913A9821  add      x1, x1, #0xea6
//   0x176a90: 910023E0  add      x0, sp, #8
//   0x176a94: D65F03C0  ret      
static inline uint64_t fde_func_1496_0x176a88(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x176a88ULL ^ (static_cast<uint64_t>(0xd0fff5e1ULL) << 13);
    acc = (acc + a1 + 0x913a9821ULL) ^ 0x08ff78ULL;
    acc ^= (acc >> 17) * 0x0060ULL;
    return acc;
}

// FDE #1497 | PC: 0x176ae8 | FDE: 0x08ffd8 | Size: 44 bytes
// Khung tháo gỡ #1497 | Địa chỉ PC: 0x176ae8 | Địa chỉ FDE: 0x08ffd8 | Kích thước: 44 bytes
//   0x176ae8: 91004100  add      x0, x8, #0x10
//   0x176aec: 17FF67FD  b        #0x150ae0
//   0x176af0: F94003E8  ldr      x8, [sp]
//   0x176af4: F90003FF  str      xzr, [sp]
static inline uint64_t fde_func_1497_0x176ae8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x176ae8ULL ^ (static_cast<uint64_t>(0x91004100ULL) << 13);
    acc = (acc + a1 + 0x17ff67fdULL) ^ 0x08ffd8ULL;
    acc ^= (acc >> 17) * 0x002cULL;
    return acc;
}

// FDE #1498 | PC: 0x176b14 | FDE: 0x090038 | Size: 116 bytes
// Khung tháo gỡ #1498 | Địa chỉ PC: 0x176b14 | Địa chỉ FDE: 0x090038 | Kích thước: 116 bytes
//   0x176b14: F0FFF601  adrp     x1, #0x39000
//   0x176b18: 9139B821  add      x1, x1, #0xe6e
//   0x176b1c: 17FCC776  b        #0xa88f4
//   0x176b20: D53BD056  mrs      x22, tpidr_el0
static inline uint64_t fde_func_1498_0x176b14(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x176b14ULL ^ (static_cast<uint64_t>(0xf0fff601ULL) << 13);
    acc = (acc + a1 + 0x9139b821ULL) ^ 0x090038ULL;
    acc ^= (acc >> 17) * 0x0074ULL;
    return acc;
}

// FDE #1499 | PC: 0x176b88 | FDE: 0x090098 | Size: 52 bytes
// Khung tháo gỡ #1499 | Địa chỉ PC: 0x176b88 | Địa chỉ FDE: 0x090098 | Kích thước: 52 bytes
//   0x176b88: 910023E0  add      x0, sp, #8
//   0x176b8c: F90007F4  str      x20, [sp, #8]
//   0x176b90: 14004AF0  b        #0x189750
//   0x176b94: B0FFF603  adrp     x3, #0x37000
static inline uint64_t fde_func_1499_0x176b88(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x176b88ULL ^ (static_cast<uint64_t>(0x910023e0ULL) << 13);
    acc = (acc + a1 + 0xf90007f4ULL) ^ 0x090098ULL;
    acc ^= (acc >> 17) * 0x0034ULL;
    return acc;
}

// FDE #1500 | PC: 0x176bbc | FDE: 0x0900f8 | Size: 76 bytes
// Khung tháo gỡ #1500 | Địa chỉ PC: 0x176bbc | Địa chỉ FDE: 0x0900f8 | Kích thước: 76 bytes
//   0x176bbc: F9400273  ldr      x19, [x19]
//   0x176bc0: F9400281  ldr      x1, [x20]
//   0x176bc4: AA1303E0  mov      x0, x19
//   0x176bc8: 140043AE  b        #0x187a80
static inline uint64_t fde_func_1500_0x176bbc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x176bbcULL ^ (static_cast<uint64_t>(0xf9400273ULL) << 13);
    acc = (acc + a1 + 0xf9400281ULL) ^ 0x0900f8ULL;
    acc ^= (acc >> 17) * 0x004cULL;
    return acc;
}

// FDE #1501 | PC: 0x176c08 | FDE: 0x090158 | Size: 120 bytes
// Khung tháo gỡ #1501 | Địa chỉ PC: 0x176c08 | Địa chỉ FDE: 0x090158 | Kích thước: 120 bytes
//   0x176c08: 910063E1  add      x1, sp, #0x18
//   0x176c0c: AA1303E0  mov      x0, x19
//   0x176c10: 17FF62C5  b        #0x14f724
//   0x176c14: A9454FF4  ldp      x20, x19, [sp, #0x50]
static inline uint64_t fde_func_1501_0x176c08(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x176c08ULL ^ (static_cast<uint64_t>(0x910063e1ULL) << 13);
    acc = (acc + a1 + 0xaa1303e0ULL) ^ 0x090158ULL;
    acc ^= (acc >> 17) * 0x0078ULL;
    return acc;
}

// FDE #1502 | PC: 0x176c80 | FDE: 0x0901b8 | Size: 68 bytes
// Khung tháo gỡ #1502 | Địa chỉ PC: 0x176c80 | Địa chỉ FDE: 0x0901b8 | Kích thước: 68 bytes
//   0x176c80: D53BD055  mrs      x21, tpidr_el0
//   0x176c84: F94016A8  ldr      x8, [x21, #0x28]
//   0x176c88: D65F03C0  ret      
//   0x176c8c: D10243FF  sub      sp, sp, #0x90
static inline uint64_t fde_func_1502_0x176c80(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x176c80ULL ^ (static_cast<uint64_t>(0xd53bd055ULL) << 13);
    acc = (acc + a1 + 0xf94016a8ULL) ^ 0x0901b8ULL;
    acc ^= (acc >> 17) * 0x0044ULL;
    return acc;
}

// FDE #1503 | PC: 0x176cc4 | FDE: 0x090218 | Size: 96 bytes
// Khung tháo gỡ #1503 | Địa chỉ PC: 0x176cc4 | Địa chỉ FDE: 0x090218 | Kích thước: 96 bytes
//   0x176cc4: AA1303E0  mov      x0, x19
//   0x176cc8: 4EA01C0A  mov      v10.16b, v0.16b
//   0x176ccc: 17FF6593  b        #0x150318
//   0x176cd0: B9400268  ldr      w8, [x19]
static inline uint64_t fde_func_1503_0x176cc4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x176cc4ULL ^ (static_cast<uint64_t>(0xaa1303e0ULL) << 13);
    acc = (acc + a1 + 0x4ea01c0aULL) ^ 0x090218ULL;
    acc ^= (acc >> 17) * 0x0060ULL;
    return acc;
}

// FDE #1504 | PC: 0x176d24 | FDE: 0x090278 | Size: 68 bytes
// Khung tháo gỡ #1504 | Địa chỉ PC: 0x176d24 | Địa chỉ FDE: 0x090278 | Kích thước: 68 bytes
//   0x176d24: D53BD053  mrs      x19, tpidr_el0
//   0x176d28: F9401668  ldr      x8, [x19, #0x28]
//   0x176d2c: F9000FE8  str      x8, [sp, #0x18]
//   0x176d30: A90087E0  stp      x0, x1, [sp, #8]
static inline uint64_t fde_func_1504_0x176d24(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x176d24ULL ^ (static_cast<uint64_t>(0xd53bd053ULL) << 13);
    acc = (acc + a1 + 0xf9401668ULL) ^ 0x090278ULL;
    acc ^= (acc >> 17) * 0x0044ULL;
    return acc;
}

// FDE #1505 | PC: 0x176d68 | FDE: 0x0902d8 | Size: 104 bytes
// Khung tháo gỡ #1505 | Địa chỉ PC: 0x176d68 | Địa chỉ FDE: 0x0902d8 | Kích thước: 104 bytes
//   0x176d68: 0E205800  cnt      v0.8b, v0.8b
//   0x176d6c: 2E303800  uaddlv   h0, v0.8b
//   0x176d70: 1E260009  fmov     w9, s0
//   0x176d74: F100053F  cmp      x9, #1
static inline uint64_t fde_func_1505_0x176d68(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x176d68ULL ^ (static_cast<uint64_t>(0x0e205800ULL) << 13);
    acc = (acc + a1 + 0x2e303800ULL) ^ 0x0902d8ULL;
    acc ^= (acc >> 17) * 0x0068ULL;
    return acc;
}

// FDE #1506 | PC: 0x176dd0 | FDE: 0x090338 | Size: 64 bytes
// Khung tháo gỡ #1506 | Địa chỉ PC: 0x176dd0 | Địa chỉ FDE: 0x090338 | Kích thước: 64 bytes
//   0x176dd0: 914007F5  add      x21, sp, #1, lsl #12
//   0x176dd4: 910302B5  add      x21, x21, #0xc0
//   0x176dd8: B910CBFF  str      wzr, [sp, #0x10c8]
//   0x176ddc: FD0863E0  str      d0, [sp, #0x10c0]
static inline uint64_t fde_func_1506_0x176dd0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x176dd0ULL ^ (static_cast<uint64_t>(0x914007f5ULL) << 13);
    acc = (acc + a1 + 0x910302b5ULL) ^ 0x090338ULL;
    acc ^= (acc >> 17) * 0x0040ULL;
    return acc;
}

// FDE #1507 | PC: 0x176e10 | FDE: 0x090398 | Size: 76 bytes
// Khung tháo gỡ #1507 | Địa chỉ PC: 0x176e10 | Địa chỉ FDE: 0x090398 | Kích thước: 76 bytes
//   0x176e10: A95353FC  ldp      x28, x20, [sp, #0x130]
//   0x176e14: 910543FF  add      sp, sp, #0x150
//   0x176e18: D65F03C0  ret      
//   0x176e1c: D53BD055  mrs      x21, tpidr_el0
static inline uint64_t fde_func_1507_0x176e10(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x176e10ULL ^ (static_cast<uint64_t>(0xa95353fcULL) << 13);
    acc = (acc + a1 + 0x910543ffULL) ^ 0x090398ULL;
    acc ^= (acc >> 17) * 0x004cULL;
    return acc;
}

// FDE #1508 | PC: 0x176e5c | FDE: 0x0903f8 | Size: 104 bytes
// Khung tháo gỡ #1508 | Địa chỉ PC: 0x176e5c | Địa chỉ FDE: 0x0903f8 | Kích thước: 104 bytes
//   0x176e5c: 910023E0  add      x0, sp, #8
//   0x176e60: 12800002  mov      w2, #-1
//   0x176e64: AA1F03E3  mov      x3, xzr
//   0x176e68: AA1F03E4  mov      x4, xzr
static inline uint64_t fde_func_1508_0x176e5c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x176e5cULL ^ (static_cast<uint64_t>(0x910023e0ULL) << 13);
    acc = (acc + a1 + 0x12800002ULL) ^ 0x0903f8ULL;
    acc ^= (acc >> 17) * 0x0068ULL;
    return acc;
}

// FDE #1509 | PC: 0x176ec4 | FDE: 0x090458 | Size: 124 bytes
// Khung tháo gỡ #1509 | Địa chỉ PC: 0x176ec4 | Địa chỉ FDE: 0x090458 | Kích thước: 124 bytes
//   0x176ec4: B9400A68  ldr      w8, [x19, #8]
//   0x176ec8: 11000508  add      w8, w8, #1
//   0x176ecc: B9000A68  str      w8, [x19, #8]
//   0x176ed0: D65F03C0  ret      
static inline uint64_t fde_func_1509_0x176ec4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x176ec4ULL ^ (static_cast<uint64_t>(0xb9400a68ULL) << 13);
    acc = (acc + a1 + 0x11000508ULL) ^ 0x090458ULL;
    acc ^= (acc >> 17) * 0x007cULL;
    return acc;
}

// FDE #1510 | PC: 0x176f40 | FDE: 0x0904b8 | Size: 132 bytes
// Khung tháo gỡ #1510 | Địa chỉ PC: 0x176f40 | Địa chỉ FDE: 0x0904b8 | Kích thước: 132 bytes
//   0x176f40: D10603FF  sub      sp, sp, #0x180
//   0x176f44: A9136BFC  stp      x28, x26, [sp, #0x130]
//   0x176f48: A91463F9  stp      x25, x24, [sp, #0x140]
//   0x176f4c: A9155BF7  stp      x23, x22, [sp, #0x150]
static inline uint64_t fde_func_1510_0x176f40(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x176f40ULL ^ (static_cast<uint64_t>(0xd10603ffULL) << 13);
    acc = (acc + a1 + 0xa9136bfcULL) ^ 0x0904b8ULL;
    acc ^= (acc >> 17) * 0x0084ULL;
    return acc;
}

// FDE #1511 | PC: 0x176fc4 | FDE: 0x090518 | Size: 44 bytes
// Khung tháo gỡ #1511 | Địa chỉ PC: 0x176fc4 | Địa chỉ FDE: 0x090518 | Kích thước: 44 bytes
//   0x176fc4: F9401908  ldr      x8, [x8, #0x30]
//   0x176fc8: D61F0100  br       x8
//   0x176fcc: AA1303E0  mov      x0, x19
//   0x176fd0: 17FDB919  b        #0xe5434
static inline uint64_t fde_func_1511_0x176fc4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x176fc4ULL ^ (static_cast<uint64_t>(0xf9401908ULL) << 13);
    acc = (acc + a1 + 0xd61f0100ULL) ^ 0x090518ULL;
    acc ^= (acc >> 17) * 0x002cULL;
    return acc;
}

// FDE #1512 | PC: 0x176ff0 | FDE: 0x090578 | Size: 168 bytes
// Khung tháo gỡ #1512 | Địa chỉ PC: 0x176ff0 | Địa chỉ FDE: 0x090578 | Kích thước: 168 bytes
//   0x176ff0: 531F7AC8  lsl      w8, w22, #1
//   0x176ff4: 0B1606C9  add      w9, w22, w22, lsl #1
//   0x176ff8: 1AD7090A  udiv     w10, w8, w23
//   0x176ffc: 1AD7092B  udiv     w11, w9, w23
static inline uint64_t fde_func_1512_0x176ff0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x176ff0ULL ^ (static_cast<uint64_t>(0x531f7ac8ULL) << 13);
    acc = (acc + a1 + 0x0b1606c9ULL) ^ 0x090578ULL;
    acc ^= (acc >> 17) * 0x00a8ULL;
    return acc;
}

// FDE #1513 | PC: 0x177098 | FDE: 0x0905d8 | Size: 32 bytes
// Khung tháo gỡ #1513 | Địa chỉ PC: 0x177098 | Địa chỉ FDE: 0x0905d8 | Kích thước: 32 bytes
//   0x177098: F9400908  ldr      x8, [x8, #0x10]
//   0x17709c: D61F0100  br       x8
//   0x1770a0: AA1F03E4  mov      x4, xzr
//   0x1770a4: 17FF6EF9  b        #0x152c88
static inline uint64_t fde_func_1513_0x177098(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x177098ULL ^ (static_cast<uint64_t>(0xf9400908ULL) << 13);
    acc = (acc + a1 + 0xd61f0100ULL) ^ 0x0905d8ULL;
    acc ^= (acc >> 17) * 0x0020ULL;
    return acc;
}

// FDE #1514 | PC: 0x1770b8 | FDE: 0x090638 | Size: 48 bytes
// Khung tháo gỡ #1514 | Địa chỉ PC: 0x1770b8 | Địa chỉ FDE: 0x090638 | Kích thước: 48 bytes
//   0x1770b8: AA1303E0  mov      x0, x19
//   0x1770bc: 17FF14B8  b        #0x13c39c
//   0x1770c0: 910003E0  mov      x0, sp
//   0x1770c4: 17FCC731  b        #0xa8d88
static inline uint64_t fde_func_1514_0x1770b8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1770b8ULL ^ (static_cast<uint64_t>(0xaa1303e0ULL) << 13);
    acc = (acc + a1 + 0x17ff14b8ULL) ^ 0x090638ULL;
    acc ^= (acc >> 17) * 0x0030ULL;
    return acc;
}

// FDE #1515 | PC: 0x1770e8 | FDE: 0x090698 | Size: 108 bytes
// Khung tháo gỡ #1515 | Địa chỉ PC: 0x1770e8 | Địa chỉ FDE: 0x090698 | Kích thước: 108 bytes
//   0x1770e8: B87D5AA1  ldr      w1, [x21, w29, uxtw #2]
//   0x1770ec: F9403FE0  ldr      x0, [sp, #0x78]
//   0x1770f0: 11000E73  add      w19, w19, #3
//   0x1770f4: 17FECB33  b        #0x129dc0
static inline uint64_t fde_func_1515_0x1770e8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1770e8ULL ^ (static_cast<uint64_t>(0xb87d5aa1ULL) << 13);
    acc = (acc + a1 + 0xf9403fe0ULL) ^ 0x090698ULL;
    acc ^= (acc >> 17) * 0x006cULL;
    return acc;
}

// FDE #1516 | PC: 0x177154 | FDE: 0x0906f8 | Size: 112 bytes
// Khung tháo gỡ #1516 | Địa chỉ PC: 0x177154 | Địa chỉ FDE: 0x0906f8 | Kích thước: 112 bytes
//   0x177154: A94A4FF4  ldp      x20, x19, [sp, #0xa0]
//   0x177158: A94957F6  ldp      x22, x21, [sp, #0x90]
//   0x17715c: A9485FF8  ldp      x24, x23, [sp, #0x80]
//   0x177160: A94767FA  ldp      x26, x25, [sp, #0x70]
static inline uint64_t fde_func_1516_0x177154(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x177154ULL ^ (static_cast<uint64_t>(0xa94a4ff4ULL) << 13);
    acc = (acc + a1 + 0xa94957f6ULL) ^ 0x0906f8ULL;
    acc ^= (acc >> 17) * 0x0070ULL;
    return acc;
}

// FDE #1517 | PC: 0x1771c4 | FDE: 0x090758 | Size: 80 bytes
// Khung tháo gỡ #1517 | Địa chỉ PC: 0x1771c4 | Địa chỉ FDE: 0x090758 | Kích thước: 80 bytes
//   0x1771c4: F9000FE0  str      x0, [sp, #0x18]
//   0x1771c8: 910063E0  add      x0, sp, #0x18
//   0x1771cc: 14004961  b        #0x189750
//   0x1771d0: F81F0FFE  str      x30, [sp, #-0x10]!
static inline uint64_t fde_func_1517_0x1771c4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1771c4ULL ^ (static_cast<uint64_t>(0xf9000fe0ULL) << 13);
    acc = (acc + a1 + 0x910063e0ULL) ^ 0x090758ULL;
    acc ^= (acc >> 17) * 0x0050ULL;
    return acc;
}

// FDE #1518 | PC: 0x177214 | FDE: 0x0907c0 | Size: 56 bytes
// Khung tháo gỡ #1518 | Địa chỉ PC: 0x177214 | Địa chỉ FDE: 0x0907c0 | Kích thước: 56 bytes
//   0x177214: 52800021  mov      w1, #1
//   0x177218: AA1403E0  mov      x0, x20
//   0x17721c: 17FE1F0E  b        #0xfee54
//   0x177220: F9400668  ldr      x8, [x19, #8]
static inline uint64_t fde_func_1518_0x177214(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x177214ULL ^ (static_cast<uint64_t>(0x52800021ULL) << 13);
    acc = (acc + a1 + 0xaa1403e0ULL) ^ 0x0907c0ULL;
    acc ^= (acc >> 17) * 0x0038ULL;
    return acc;
}

// FDE #1519 | PC: 0x17724c | FDE: 0x090820 | Size: 108 bytes
// Khung tháo gỡ #1519 | Địa chỉ PC: 0x17724c | Địa chỉ FDE: 0x090820 | Kích thước: 108 bytes
//   0x17724c: AA1503E0  mov      x0, x21
//   0x177250: AA1403E1  mov      x1, x20
//   0x177254: D65F03C0  ret      
//   0x177258: 2A1603E2  mov      w2, w22
static inline uint64_t fde_func_1519_0x17724c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x17724cULL ^ (static_cast<uint64_t>(0xaa1503e0ULL) << 13);
    acc = (acc + a1 + 0xaa1403e1ULL) ^ 0x090820ULL;
    acc ^= (acc >> 17) * 0x006cULL;
    return acc;
}

// FDE #1520 | PC: 0x1772b8 | FDE: 0x090880 | Size: 192 bytes
// Khung tháo gỡ #1520 | Địa chỉ PC: 0x1772b8 | Địa chỉ FDE: 0x090880 | Kích thước: 192 bytes
//   0x1772b8: AA0203E3  mov      x3, x2
//   0x1772bc: F90013E8  str      x8, [sp, #0x20]
//   0x1772c0: 9100B3E8  add      x8, sp, #0x2c
//   0x1772c4: 9100E3E9  add      x9, sp, #0x38
static inline uint64_t fde_func_1520_0x1772b8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1772b8ULL ^ (static_cast<uint64_t>(0xaa0203e3ULL) << 13);
    acc = (acc + a1 + 0xf90013e8ULL) ^ 0x090880ULL;
    acc ^= (acc >> 17) * 0x00c0ULL;
    return acc;
}

// FDE #1521 | PC: 0x177378 | FDE: 0x0908e0 | Size: 124 bytes
// Khung tháo gỡ #1521 | Địa chỉ PC: 0x177378 | Địa chỉ FDE: 0x0908e0 | Kích thước: 124 bytes
//   0x177378: 9100E3E8  add      x8, sp, #0x38
//   0x17737c: B0FFF5F4  adrp     x20, #0x34000
//   0x177380: D0FFF616  adrp     x22, #0x39000
//   0x177384: AA1F03F7  mov      x23, xzr
static inline uint64_t fde_func_1521_0x177378(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x177378ULL ^ (static_cast<uint64_t>(0x9100e3e8ULL) << 13);
    acc = (acc + a1 + 0xb0fff5f4ULL) ^ 0x0908e0ULL;
    acc ^= (acc >> 17) * 0x007cULL;
    return acc;
}

// FDE #1522 | PC: 0x1773f4 | FDE: 0x090948 | Size: 64 bytes
// Khung tháo gỡ #1522 | Địa chỉ PC: 0x1773f4 | Địa chỉ FDE: 0x090948 | Kích thước: 64 bytes
//   0x1773f4: AA1603E0  mov      x0, x22
//   0x1773f8: AA1503E1  mov      x1, x21
//   0x1773fc: AA1403E2  mov      x2, x20
//   0x177400: D65F03C0  ret      
static inline uint64_t fde_func_1522_0x1773f4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1773f4ULL ^ (static_cast<uint64_t>(0xaa1603e0ULL) << 13);
    acc = (acc + a1 + 0xaa1503e1ULL) ^ 0x090948ULL;
    acc ^= (acc >> 17) * 0x0040ULL;
    return acc;
}

// FDE #1523 | PC: 0x177434 | FDE: 0x0909a8 | Size: 52 bytes
// Khung tháo gỡ #1523 | Địa chỉ PC: 0x177434 | Địa chỉ FDE: 0x0909a8 | Kích thước: 52 bytes
//   0x177434: 910063E1  add      x1, sp, #0x18
//   0x177438: AA0003F3  mov      x19, x0
//   0x17743c: 17FF60CF  b        #0x14f778
//   0x177440: 9112B863  add      x3, x3, #0x4ae
static inline uint64_t fde_func_1523_0x177434(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x177434ULL ^ (static_cast<uint64_t>(0x910063e1ULL) << 13);
    acc = (acc + a1 + 0xaa0003f3ULL) ^ 0x0909a8ULL;
    acc ^= (acc >> 17) * 0x0034ULL;
    return acc;
}

// FDE #1524 | PC: 0x177468 | FDE: 0x090a08 | Size: 72 bytes
// Khung tháo gỡ #1524 | Địa chỉ PC: 0x177468 | Địa chỉ FDE: 0x090a08 | Kích thước: 72 bytes
//   0x177468: A94353F5  ldp      x21, x20, [sp, #0x30]
//   0x17746c: A9425BF7  ldp      x23, x22, [sp, #0x20]
//   0x177470: A94163F9  ldp      x25, x24, [sp, #0x10]
//   0x177474: 910143FF  add      sp, sp, #0x50
static inline uint64_t fde_func_1524_0x177468(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x177468ULL ^ (static_cast<uint64_t>(0xa94353f5ULL) << 13);
    acc = (acc + a1 + 0xa9425bf7ULL) ^ 0x090a08ULL;
    acc ^= (acc >> 17) * 0x0048ULL;
    return acc;
}

// FDE #1525 | PC: 0x1774b0 | FDE: 0x090a68 | Size: 160 bytes
// Khung tháo gỡ #1525 | Địa chỉ PC: 0x1774b0 | Địa chỉ FDE: 0x090a68 | Kích thước: 160 bytes
//   0x1774b0: B87D5AA1  ldr      w1, [x21, w29, uxtw #2]
//   0x1774b4: F9403FE0  ldr      x0, [sp, #0x78]
//   0x1774b8: 11000E77  add      w23, w19, #3
//   0x1774bc: 17FECA41  b        #0x129dc0
static inline uint64_t fde_func_1525_0x1774b0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1774b0ULL ^ (static_cast<uint64_t>(0xb87d5aa1ULL) << 13);
    acc = (acc + a1 + 0xf9403fe0ULL) ^ 0x090a68ULL;
    acc ^= (acc >> 17) * 0x00a0ULL;
    return acc;
}

// FDE #1526 | PC: 0x177550 | FDE: 0x090ac8 | Size: 80 bytes
// Khung tháo gỡ #1526 | Địa chỉ PC: 0x177550 | Địa chỉ FDE: 0x090ac8 | Kích thước: 80 bytes
//   0x177550: D10643FF  sub      sp, sp, #0x190
//   0x177554: F9009BFC  str      x28, [sp, #0x130]
//   0x177558: A9146BFB  stp      x27, x26, [sp, #0x140]
//   0x17755c: A91563F9  stp      x25, x24, [sp, #0x150]
static inline uint64_t fde_func_1526_0x177550(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x177550ULL ^ (static_cast<uint64_t>(0xd10643ffULL) << 13);
    acc = (acc + a1 + 0xf9009bfcULL) ^ 0x090ac8ULL;
    acc ^= (acc >> 17) * 0x0050ULL;
    return acc;
}

// FDE #1527 | PC: 0x1775a0 | FDE: 0x090b28 | Size: 84 bytes
// Khung tháo gỡ #1527 | Địa chỉ PC: 0x1775a0 | Địa chỉ FDE: 0x090b28 | Kích thước: 84 bytes
//   0x1775a0: D53BD054  mrs      x20, tpidr_el0
//   0x1775a4: F9401688  ldr      x8, [x20, #0x28]
//   0x1775a8: AA0003F3  mov      x19, x0
//   0x1775ac: F9002FE8  str      x8, [sp, #0x58]
static inline uint64_t fde_func_1527_0x1775a0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1775a0ULL ^ (static_cast<uint64_t>(0xd53bd054ULL) << 13);
    acc = (acc + a1 + 0xf9401688ULL) ^ 0x090b28ULL;
    acc ^= (acc >> 17) * 0x0054ULL;
    return acc;
}

// FDE #1528 | PC: 0x1775f4 | FDE: 0x090b88 | Size: 84 bytes
// Khung tháo gỡ #1528 | Địa chỉ PC: 0x1775f4 | Địa chỉ FDE: 0x090b88 | Kích thước: 84 bytes
//   0x1775f4: F9400268  ldr      x8, [x19]
//   0x1775f8: AA1303E0  mov      x0, x19
//   0x1775fc: F9400D08  ldr      x8, [x8, #0x18]
//   0x177600: D61F0100  br       x8
static inline uint64_t fde_func_1528_0x1775f4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1775f4ULL ^ (static_cast<uint64_t>(0xf9400268ULL) << 13);
    acc = (acc + a1 + 0xaa1303e0ULL) ^ 0x090b88ULL;
    acc ^= (acc >> 17) * 0x0054ULL;
    return acc;
}

// FDE #1529 | PC: 0x177648 | FDE: 0x090bf0 | Size: 80 bytes
// Khung tháo gỡ #1529 | Địa chỉ PC: 0x177648 | Địa chỉ FDE: 0x090bf0 | Kích thước: 80 bytes
//   0x177648: B90003E0  str      w0, [sp]
//   0x17764c: F94013E0  ldr      x0, [sp, #0x20]
//   0x177650: 2A1703E1  mov      w1, w23
//   0x177654: 2A1803E2  mov      w2, w24
static inline uint64_t fde_func_1529_0x177648(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x177648ULL ^ (static_cast<uint64_t>(0xb90003e0ULL) << 13);
    acc = (acc + a1 + 0xf94013e0ULL) ^ 0x090bf0ULL;
    acc ^= (acc >> 17) * 0x0050ULL;
    return acc;
}

// FDE #1530 | PC: 0x177698 | FDE: 0x090c50 | Size: 56 bytes
// Khung tháo gỡ #1530 | Địa chỉ PC: 0x177698 | Địa chỉ FDE: 0x090c50 | Kích thước: 56 bytes
//   0x177698: A90007E0  stp      x0, x1, [sp]
//   0x17769c: 910003E0  mov      x0, sp
//   0x1776a0: 140048C8  b        #0x1899c0
//   0x1776a4: F9401668  ldr      x8, [x19, #0x28]
static inline uint64_t fde_func_1530_0x177698(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x177698ULL ^ (static_cast<uint64_t>(0xa90007e0ULL) << 13);
    acc = (acc + a1 + 0x910003e0ULL) ^ 0x090c50ULL;
    acc ^= (acc >> 17) * 0x0038ULL;
    return acc;
}

// FDE #1531 | PC: 0x1776d0 | FDE: 0x090cb0 | Size: 36 bytes
// Khung tháo gỡ #1531 | Địa chỉ PC: 0x1776d0 | Địa chỉ FDE: 0x090cb0 | Kích thước: 36 bytes
//   0x1776d0: AA1303E0  mov      x0, x19
//   0x1776d4: 17FF6014  b        #0x14f724
//   0x1776d8: 910023E0  add      x0, sp, #8
//   0x1776dc: F90007E8  str      x8, [sp, #8]
static inline uint64_t fde_func_1531_0x1776d0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1776d0ULL ^ (static_cast<uint64_t>(0xaa1303e0ULL) << 13);
    acc = (acc + a1 + 0x17ff6014ULL) ^ 0x090cb0ULL;
    acc ^= (acc >> 17) * 0x0024ULL;
    return acc;
}

// FDE #1532 | PC: 0x1776f4 | FDE: 0x090d10 | Size: 96 bytes
// Khung tháo gỡ #1532 | Địa chỉ PC: 0x1776f4 | Địa chỉ FDE: 0x090d10 | Kích thước: 96 bytes
//   0x1776f4: F940C7E8  ldr      x8, [sp, #0x188]
//   0x1776f8: 910143E0  add      x0, sp, #0x50
//   0x1776fc: F9002BFF  str      xzr, [sp, #0x50]
//   0x177700: 91000508  add      x8, x8, #1
static inline uint64_t fde_func_1532_0x1776f4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1776f4ULL ^ (static_cast<uint64_t>(0xf940c7e8ULL) << 13);
    acc = (acc + a1 + 0x910143e0ULL) ^ 0x090d10ULL;
    acc ^= (acc >> 17) * 0x0060ULL;
    return acc;
}

// FDE #1533 | PC: 0x177754 | FDE: 0x090d70 | Size: 56 bytes
// Khung tháo gỡ #1533 | Địa chỉ PC: 0x177754 | Địa chỉ FDE: 0x090d70 | Kích thước: 56 bytes
//   0x177754: 90FFF603  adrp     x3, #0x37000
//   0x177758: AA0003E1  mov      x1, x0
//   0x17775c: D65F03C0  ret      
//   0x177760: AA1803E0  mov      x0, x24
static inline uint64_t fde_func_1533_0x177754(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x177754ULL ^ (static_cast<uint64_t>(0x90fff603ULL) << 13);
    acc = (acc + a1 + 0xaa0003e1ULL) ^ 0x090d70ULL;
    acc ^= (acc >> 17) * 0x0038ULL;
    return acc;
}

// FDE #1534 | PC: 0x17778c | FDE: 0x090dd0 | Size: 64 bytes
// Khung tháo gỡ #1534 | Địa chỉ PC: 0x17778c | Địa chỉ FDE: 0x090dd0 | Kích thước: 64 bytes
//   0x17778c: AA0003F3  mov      x19, x0
//   0x177790: 52800500  mov      w0, #0x28
//   0x177794: AA0303F6  mov      x22, x3
//   0x177798: AA0203F7  mov      x23, x2
static inline uint64_t fde_func_1534_0x17778c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x17778cULL ^ (static_cast<uint64_t>(0xaa0003f3ULL) << 13);
    acc = (acc + a1 + 0x52800500ULL) ^ 0x090dd0ULL;
    acc ^= (acc >> 17) * 0x0040ULL;
    return acc;
}

// FDE #1535 | PC: 0x1777cc | FDE: 0x090e30 | Size: 84 bytes
// Khung tháo gỡ #1535 | Địa chỉ PC: 0x1777cc | Địa chỉ FDE: 0x090e30 | Kích thước: 84 bytes
//   0x1777cc: D10283FF  sub      sp, sp, #0xa0
//   0x1777d0: A9046FFC  stp      x28, x27, [sp, #0x40]
//   0x1777d4: A90567FA  stp      x26, x25, [sp, #0x50]
//   0x1777d8: A9065FF8  stp      x24, x23, [sp, #0x60]
static inline uint64_t fde_func_1535_0x1777cc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1777ccULL ^ (static_cast<uint64_t>(0xd10283ffULL) << 13);
    acc = (acc + a1 + 0xa9046ffcULL) ^ 0x090e30ULL;
    acc ^= (acc >> 17) * 0x0054ULL;
    return acc;
}

// FDE #1536 | PC: 0x177820 | FDE: 0x090e90 | Size: 76 bytes
// Khung tháo gỡ #1536 | Địa chỉ PC: 0x177820 | Địa chỉ FDE: 0x090e90 | Kích thước: 76 bytes
//   0x177820: 914007E0  add      x0, sp, #1, lsl #12
//   0x177824: 91030000  add      x0, x0, #0xc0
//   0x177828: 1E620100  scvtf    d0, w8
//   0x17782c: 17FF64EB  b        #0x150bd8
static inline uint64_t fde_func_1536_0x177820(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x177820ULL ^ (static_cast<uint64_t>(0x914007e0ULL) << 13);
    acc = (acc + a1 + 0x91030000ULL) ^ 0x090e90ULL;
    acc ^= (acc >> 17) * 0x004cULL;
    return acc;
}

// FDE #1537 | PC: 0x17786c | FDE: 0x090ef0 | Size: 64 bytes
// Khung tháo gỡ #1537 | Địa chỉ PC: 0x17786c | Địa chỉ FDE: 0x090ef0 | Kích thước: 64 bytes
//   0x17786c: 9100E3E0  add      x0, sp, #0x38
//   0x177870: AA1F03E3  mov      x3, xzr
//   0x177874: AA1F03E5  mov      x5, xzr
//   0x177878: 17FEFAF8  b        #0x136458
static inline uint64_t fde_func_1537_0x17786c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x17786cULL ^ (static_cast<uint64_t>(0x9100e3e0ULL) << 13);
    acc = (acc + a1 + 0xaa1f03e3ULL) ^ 0x090ef0ULL;
    acc ^= (acc >> 17) * 0x0040ULL;
    return acc;
}

// FDE #1538 | PC: 0x1778ac | FDE: 0x090f50 | Size: 68 bytes
// Khung tháo gỡ #1538 | Địa chỉ PC: 0x1778ac | Địa chỉ FDE: 0x090f50 | Kích thước: 68 bytes
//   0x1778ac: A90007E0  stp      x0, x1, [sp]
//   0x1778b0: 910003E0  mov      x0, sp
//   0x1778b4: 14004847  b        #0x1899d0
//   0x1778b8: 910103E1  add      x1, sp, #0x40
static inline uint64_t fde_func_1538_0x1778ac(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1778acULL ^ (static_cast<uint64_t>(0xa90007e0ULL) << 13);
    acc = (acc + a1 + 0x910003e0ULL) ^ 0x090f50ULL;
    acc ^= (acc >> 17) * 0x0044ULL;
    return acc;
}

// FDE #1539 | PC: 0x1778f0 | FDE: 0x090fb0 | Size: 68 bytes
// Khung tháo gỡ #1539 | Địa chỉ PC: 0x1778f0 | Địa chỉ FDE: 0x090fb0 | Kích thước: 68 bytes
//   0x1778f0: 910063E0  add      x0, sp, #0x18
//   0x1778f4: 14004833  b        #0x1899c0
//   0x1778f8: A94353F5  ldp      x21, x20, [sp, #0x30]
//   0x1778fc: 6D4223E9  ldp      d9, d8, [sp, #0x20]
static inline uint64_t fde_func_1539_0x1778f0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1778f0ULL ^ (static_cast<uint64_t>(0x910063e0ULL) << 13);
    acc = (acc + a1 + 0x14004833ULL) ^ 0x090fb0ULL;
    acc ^= (acc >> 17) * 0x0044ULL;
    return acc;
}

// FDE #1540 | PC: 0x177934 | FDE: 0x091010 | Size: 76 bytes
// Khung tháo gỡ #1540 | Địa chỉ PC: 0x177934 | Địa chỉ FDE: 0x091010 | Kích thước: 76 bytes
//   0x177934: D53BD054  mrs      x20, tpidr_el0
//   0x177938: F9401688  ldr      x8, [x20, #0x28]
//   0x17793c: AA0103F3  mov      x19, x1
//   0x177940: F90007E8  str      x8, [sp, #8]
static inline uint64_t fde_func_1540_0x177934(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x177934ULL ^ (static_cast<uint64_t>(0xd53bd054ULL) << 13);
    acc = (acc + a1 + 0xf9401688ULL) ^ 0x091010ULL;
    acc ^= (acc >> 17) * 0x004cULL;
    return acc;
}

// FDE #1541 | PC: 0x177980 | FDE: 0x091070 | Size: 60 bytes
// Khung tháo gỡ #1541 | Địa chỉ PC: 0x177980 | Địa chỉ FDE: 0x091070 | Kích thước: 60 bytes
//   0x177980: F9400109  ldr      x9, [x8]
//   0x177984: AA0803E0  mov      x0, x8
//   0x177988: F9400929  ldr      x9, [x9, #0x10]
//   0x17798c: D61F0120  br       x9
static inline uint64_t fde_func_1541_0x177980(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x177980ULL ^ (static_cast<uint64_t>(0xf9400109ULL) << 13);
    acc = (acc + a1 + 0xaa0803e0ULL) ^ 0x091070ULL;
    acc ^= (acc >> 17) * 0x003cULL;
    return acc;
}

// FDE #1542 | PC: 0x1779bc | FDE: 0x0910d0 | Size: 80 bytes
// Khung tháo gỡ #1542 | Địa chỉ PC: 0x1779bc | Địa chỉ FDE: 0x0910d0 | Kích thước: 80 bytes
//   0x1779bc: AA1303E1  mov      x1, x19
//   0x1779c0: 17FF62C8  b        #0x1504e0
//   0x1779c4: AA1503E0  mov      x0, x21
//   0x1779c8: AA1603E3  mov      x3, x22
static inline uint64_t fde_func_1542_0x1779bc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1779bcULL ^ (static_cast<uint64_t>(0xaa1303e1ULL) << 13);
    acc = (acc + a1 + 0x17ff62c8ULL) ^ 0x0910d0ULL;
    acc ^= (acc >> 17) * 0x0050ULL;
    return acc;
}

// FDE #1543 | PC: 0x177a0c | FDE: 0x091130 | Size: 144 bytes
// Khung tháo gỡ #1543 | Địa chỉ PC: 0x177a0c | Địa chỉ FDE: 0x091130 | Kích thước: 144 bytes
//   0x177a0c: B9400268  ldr      w8, [x19]
//   0x177a10: 914007E2  add      x2, sp, #1, lsl #12
//   0x177a14: 91030042  add      x2, x2, #0xc0
//   0x177a18: 8B080AA9  add      x9, x21, x8, lsl #2
static inline uint64_t fde_func_1543_0x177a0c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x177a0cULL ^ (static_cast<uint64_t>(0xb9400268ULL) << 13);
    acc = (acc + a1 + 0x914007e2ULL) ^ 0x091130ULL;
    acc ^= (acc >> 17) * 0x0090ULL;
    return acc;
}

// FDE #1544 | PC: 0x177a9c | FDE: 0x091190 | Size: 56 bytes
// Khung tháo gỡ #1544 | Địa chỉ PC: 0x177a9c | Địa chỉ FDE: 0x091190 | Kích thước: 56 bytes
//   0x177a9c: B0FFF5E1  adrp     x1, #0x34000
//   0x177aa0: 914007E0  add      x0, sp, #1, lsl #12
//   0x177aa4: 9136F821  add      x1, x1, #0xdbe
//   0x177aa8: 91030000  add      x0, x0, #0xc0
static inline uint64_t fde_func_1544_0x177a9c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x177a9cULL ^ (static_cast<uint64_t>(0xb0fff5e1ULL) << 13);
    acc = (acc + a1 + 0x914007e0ULL) ^ 0x091190ULL;
    acc ^= (acc >> 17) * 0x0038ULL;
    return acc;
}

// FDE #1545 | PC: 0x177ad4 | FDE: 0x0911f0 | Size: 96 bytes
// Khung tháo gỡ #1545 | Địa chỉ PC: 0x177ad4 | Địa chỉ FDE: 0x0911f0 | Kích thước: 96 bytes
//   0x177ad4: 91000501  add      x1, x8, #1
//   0x177ad8: 17FCF73C  b        #0xb57c8
//   0x177adc: D53BD055  mrs      x21, tpidr_el0
//   0x177ae0: F94016A8  ldr      x8, [x21, #0x28]
static inline uint64_t fde_func_1545_0x177ad4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x177ad4ULL ^ (static_cast<uint64_t>(0x91000501ULL) << 13);
    acc = (acc + a1 + 0x17fcf73cULL) ^ 0x0911f0ULL;
    acc ^= (acc >> 17) * 0x0060ULL;
    return acc;
}

// FDE #1546 | PC: 0x177b34 | FDE: 0x091250 | Size: 60 bytes
// Khung tháo gỡ #1546 | Địa chỉ PC: 0x177b34 | Địa chỉ FDE: 0x091250 | Kích thước: 60 bytes
//   0x177b34: A9007C1F  stp      xzr, xzr, [x0]
//   0x177b38: F900081F  str      xzr, [x0, #0x10]
//   0x177b3c: A9402428  ldp      x8, x9, [x1]
//   0x177b40: EB080128  subs     x8, x9, x8
static inline uint64_t fde_func_1546_0x177b34(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x177b34ULL ^ (static_cast<uint64_t>(0xa9007c1fULL) << 13);
    acc = (acc + a1 + 0xf900081fULL) ^ 0x091250ULL;
    acc ^= (acc >> 17) * 0x003cULL;
    return acc;
}

// FDE #1547 | PC: 0x177b70 | FDE: 0x0912b8 | Size: 76 bytes
// Khung tháo gỡ #1547 | Địa chỉ PC: 0x177b70 | Địa chỉ FDE: 0x0912b8 | Kích thước: 76 bytes
//   0x177b70: B94006E2  ldr      w2, [x23, #4]
//   0x177b74: 29419AE5  ldp      w5, w6, [x23, #0xc]
//   0x177b78: 8B384AA3  add      x3, x21, w24, uxtw #2
//   0x177b7c: AA1C03E0  mov      x0, x28
static inline uint64_t fde_func_1547_0x177b70(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x177b70ULL ^ (static_cast<uint64_t>(0xb94006e2ULL) << 13);
    acc = (acc + a1 + 0x29419ae5ULL) ^ 0x0912b8ULL;
    acc ^= (acc >> 17) * 0x004cULL;
    return acc;
}

// FDE #1548 | PC: 0x177bbc | FDE: 0x091318 | Size: 44 bytes
// Khung tháo gỡ #1548 | Địa chỉ PC: 0x177bbc | Địa chỉ FDE: 0x091318 | Kích thước: 44 bytes
//   0x177bbc: AA0003F4  mov      x20, x0
//   0x177bc0: 17FCC54E  b        #0xa90f8
//   0x177bc4: 11000E77  add      w23, w19, #3
//   0x177bc8: 2A1703F3  mov      w19, w23
static inline uint64_t fde_func_1548_0x177bbc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x177bbcULL ^ (static_cast<uint64_t>(0xaa0003f4ULL) << 13);
    acc = (acc + a1 + 0x17fcc54eULL) ^ 0x091318ULL;
    acc ^= (acc >> 17) * 0x002cULL;
    return acc;
}

// FDE #1549 | PC: 0x177be8 | FDE: 0x091378 | Size: 76 bytes
// Khung tháo gỡ #1549 | Địa chỉ PC: 0x177be8 | Địa chỉ FDE: 0x091378 | Kích thước: 76 bytes
//   0x177be8: A90123E9  stp      x9, x8, [sp, #0x10]
//   0x177bec: A9002BEB  stp      x11, x10, [sp]
//   0x177bf0: 17FDFF39  b        #0xf78d4
//   0x177bf4: D53BD05A  mrs      x26, tpidr_el0
static inline uint64_t fde_func_1549_0x177be8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x177be8ULL ^ (static_cast<uint64_t>(0xa90123e9ULL) << 13);
    acc = (acc + a1 + 0xa9002bebULL) ^ 0x091378ULL;
    acc ^= (acc >> 17) * 0x004cULL;
    return acc;
}

// FDE #1550 | PC: 0x177c34 | FDE: 0x0913d8 | Size: 40 bytes
// Khung tháo gỡ #1550 | Địa chỉ PC: 0x177c34 | Địa chỉ FDE: 0x0913d8 | Kích thước: 40 bytes
//   0x177c34: B0000100  adrp     x0, #0x198000
//   0x177c38: 91076000  add      x0, x0, #0x1d8
//   0x177c3c: 14003DE1  b        #0x1873c0
//   0x177c40: 52800300  mov      w0, #0x18
static inline uint64_t fde_func_1550_0x177c34(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x177c34ULL ^ (static_cast<uint64_t>(0xb0000100ULL) << 13);
    acc = (acc + a1 + 0x91076000ULL) ^ 0x0913d8ULL;
    acc ^= (acc >> 17) * 0x0028ULL;
    return acc;
}

// FDE #1551 | PC: 0x177c5c | FDE: 0x091438 | Size: 40 bytes
// Khung tháo gỡ #1551 | Địa chỉ PC: 0x177c5c | Địa chỉ FDE: 0x091438 | Kích thước: 40 bytes
//   0x177c5c: 910543FF  add      sp, sp, #0x150
//   0x177c60: D65F03C0  ret      
//   0x177c64: F9401668  ldr      x8, [x19, #0x28]
//   0x177c68: F9400501  ldr      x1, [x8, #8]
static inline uint64_t fde_func_1551_0x177c5c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x177c5cULL ^ (static_cast<uint64_t>(0x910543ffULL) << 13);
    acc = (acc + a1 + 0xd65f03c0ULL) ^ 0x091438ULL;
    acc ^= (acc >> 17) * 0x0028ULL;
    return acc;
}

// FDE #1552 | PC: 0x177c84 | FDE: 0x091498 | Size: 48 bytes
// Khung tháo gỡ #1552 | Địa chỉ PC: 0x177c84 | Địa chỉ FDE: 0x091498 | Kích thước: 48 bytes
//   0x177c84: F9400408  ldr      x8, [x0, #8]
//   0x177c88: 91006001  add      x1, x0, #0x18
//   0x177c8c: F9400908  ldr      x8, [x8, #0x10]
//   0x177c90: AA0803E0  mov      x0, x8
static inline uint64_t fde_func_1552_0x177c84(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x177c84ULL ^ (static_cast<uint64_t>(0xf9400408ULL) << 13);
    acc = (acc + a1 + 0x91006001ULL) ^ 0x091498ULL;
    acc ^= (acc >> 17) * 0x0030ULL;
    return acc;
}

// FDE #1553 | PC: 0x177cb4 | FDE: 0x0914f8 | Size: 56 bytes
// Khung tháo gỡ #1553 | Địa chỉ PC: 0x177cb4 | Địa chỉ FDE: 0x0914f8 | Kích thước: 56 bytes
//   0x177cb4: AA1603E1  mov      x1, x22
//   0x177cb8: 17FCC30F  b        #0xa88f4
//   0x177cbc: A90002D7  stp      x23, x0, [x22]
//   0x177cc0: AA1603E0  mov      x0, x22
static inline uint64_t fde_func_1553_0x177cb4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x177cb4ULL ^ (static_cast<uint64_t>(0xaa1603e1ULL) << 13);
    acc = (acc + a1 + 0x17fcc30fULL) ^ 0x0914f8ULL;
    acc ^= (acc >> 17) * 0x0038ULL;
    return acc;
}

// FDE #1554 | PC: 0x177cec | FDE: 0x091558 | Size: 72 bytes
// Khung tháo gỡ #1554 | Địa chỉ PC: 0x177cec | Địa chỉ FDE: 0x091558 | Kích thước: 72 bytes
//   0x177cec: F81F0FFE  str      x30, [sp, #-0x10]!
//   0x177cf0: 52800401  mov      w1, #0x20
//   0x177cf4: AA1903E0  mov      x0, x25
//   0x177cf8: 97FDB5CF  bl       #0xe5434
static inline uint64_t fde_func_1554_0x177cec(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x177cecULL ^ (static_cast<uint64_t>(0xf81f0ffeULL) << 13);
    acc = (acc + a1 + 0x52800401ULL) ^ 0x091558ULL;
    acc ^= (acc >> 17) * 0x0048ULL;
    return acc;
}

// FDE #1555 | PC: 0x177d34 | FDE: 0x0915c0 | Size: 64 bytes
// Khung tháo gỡ #1555 | Địa chỉ PC: 0x177d34 | Địa chỉ FDE: 0x0915c0 | Kích thước: 64 bytes
//   0x177d34: F9401268  ldr      x8, [x19, #0x20]
//   0x177d38: F9400660  ldr      x0, [x19, #8]
//   0x177d3c: F100291F  cmp      x8, #0xa
//   0x177d40: D65F03C0  ret      
static inline uint64_t fde_func_1555_0x177d34(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x177d34ULL ^ (static_cast<uint64_t>(0xf9401268ULL) << 13);
    acc = (acc + a1 + 0xf9400660ULL) ^ 0x0915c0ULL;
    acc ^= (acc >> 17) * 0x0040ULL;
    return acc;
}

// FDE #1556 | PC: 0x177d74 | FDE: 0x091620 | Size: 84 bytes
// Khung tháo gỡ #1556 | Địa chỉ PC: 0x177d74 | Địa chỉ FDE: 0x091620 | Kích thước: 84 bytes
//   0x177d74: 52800B00  mov      w0, #0x58
//   0x177d78: 14003D6A  b        #0x187320
//   0x177d7c: F1000EFF  cmp      x23, #3
//   0x177d80: D10006E8  sub      x8, x23, #1
static inline uint64_t fde_func_1556_0x177d74(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x177d74ULL ^ (static_cast<uint64_t>(0x52800b00ULL) << 13);
    acc = (acc + a1 + 0x14003d6aULL) ^ 0x091620ULL;
    acc ^= (acc >> 17) * 0x0054ULL;
    return acc;
}

// FDE #1557 | PC: 0x177dc8 | FDE: 0x091680 | Size: 52 bytes
// Khung tháo gỡ #1557 | Địa chỉ PC: 0x177dc8 | Địa chỉ FDE: 0x091680 | Kích thước: 52 bytes
//   0x177dc8: 9100E3E0  add      x0, sp, #0x38
//   0x177dcc: 14003EED  b        #0x187980
//   0x177dd0: D10143FF  sub      sp, sp, #0x50
//   0x177dd4: A90163F9  stp      x25, x24, [sp, #0x10]
static inline uint64_t fde_func_1557_0x177dc8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x177dc8ULL ^ (static_cast<uint64_t>(0x9100e3e0ULL) << 13);
    acc = (acc + a1 + 0x14003eedULL) ^ 0x091680ULL;
    acc ^= (acc >> 17) * 0x0034ULL;
    return acc;
}

// FDE #1558 | PC: 0x177dfc | FDE: 0x0916e0 | Size: 48 bytes
// Khung tháo gỡ #1558 | Địa chỉ PC: 0x177dfc | Địa chỉ FDE: 0x0916e0 | Kích thước: 48 bytes
//   0x177dfc: 91000508  add      x8, x8, #1
//   0x177e00: 9E230101  ucvtf    s1, x8
//   0x177e04: D65F03C0  ret      
//   0x177e08: F94007E0  ldr      x0, [sp, #8]
static inline uint64_t fde_func_1558_0x177dfc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x177dfcULL ^ (static_cast<uint64_t>(0x91000508ULL) << 13);
    acc = (acc + a1 + 0x9e230101ULL) ^ 0x0916e0ULL;
    acc ^= (acc >> 17) * 0x0030ULL;
    return acc;
}

// FDE #1559 | PC: 0x177e2c | FDE: 0x091740 | Size: 92 bytes
// Khung tháo gỡ #1559 | Địa chỉ PC: 0x177e2c | Địa chỉ FDE: 0x091740 | Kích thước: 92 bytes
//   0x177e2c: A90087E0  stp      x0, x1, [sp, #8]
//   0x177e30: 910023E0  add      x0, sp, #8
//   0x177e34: 910063E1  add      x1, sp, #0x18
//   0x177e38: 1400429E  b        #0x1888b0
static inline uint64_t fde_func_1559_0x177e2c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x177e2cULL ^ (static_cast<uint64_t>(0xa90087e0ULL) << 13);
    acc = (acc + a1 + 0x910023e0ULL) ^ 0x091740ULL;
    acc ^= (acc >> 17) * 0x005cULL;
    return acc;
}

// FDE #1560 | PC: 0x177e88 | FDE: 0x0917a0 | Size: 56 bytes
// Khung tháo gỡ #1560 | Địa chỉ PC: 0x177e88 | Địa chỉ FDE: 0x0917a0 | Kích thước: 56 bytes
//   0x177e88: 294116E4  ldp      w4, w5, [x23, #8]
//   0x177e8c: 8B384AA2  add      x2, x21, w24, uxtw #2
//   0x177e90: AA1C03E0  mov      x0, x28
//   0x177e94: D65F03C0  ret      
static inline uint64_t fde_func_1560_0x177e88(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x177e88ULL ^ (static_cast<uint64_t>(0x294116e4ULL) << 13);
    acc = (acc + a1 + 0x8b384aa2ULL) ^ 0x0917a0ULL;
    acc ^= (acc >> 17) * 0x0038ULL;
    return acc;
}

// FDE #1561 | PC: 0x177ec0 | FDE: 0x091800 | Size: 56 bytes
// Khung tháo gỡ #1561 | Địa chỉ PC: 0x177ec0 | Địa chỉ FDE: 0x091800 | Kích thước: 56 bytes
//   0x177ec0: AA0003F3  mov      x19, x0
//   0x177ec4: 910042E0  add      x0, x23, #0x10
//   0x177ec8: AA0103F4  mov      x20, x1
//   0x177ecc: 17FF6305  b        #0x150ae0
static inline uint64_t fde_func_1561_0x177ec0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x177ec0ULL ^ (static_cast<uint64_t>(0xaa0003f3ULL) << 13);
    acc = (acc + a1 + 0x910042e0ULL) ^ 0x091800ULL;
    acc ^= (acc >> 17) * 0x0038ULL;
    return acc;
}

// FDE #1562 | PC: 0x177ef8 | FDE: 0x091860 | Size: 68 bytes
// Khung tháo gỡ #1562 | Địa chỉ PC: 0x177ef8 | Địa chỉ FDE: 0x091860 | Kích thước: 68 bytes
//   0x177ef8: AA1403E0  mov      x0, x20
//   0x177efc: 14003D05  b        #0x187310
//   0x177f00: AA1403E1  mov      x1, x20
//   0x177f04: 17FEAFD7  b        #0x123e60
static inline uint64_t fde_func_1562_0x177ef8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x177ef8ULL ^ (static_cast<uint64_t>(0xaa1403e0ULL) << 13);
    acc = (acc + a1 + 0x14003d05ULL) ^ 0x091860ULL;
    acc ^= (acc >> 17) * 0x0044ULL;
    return acc;
}

// FDE #1563 | PC: 0x177f3c | FDE: 0x0918c0 | Size: 144 bytes
// Khung tháo gỡ #1563 | Địa chỉ PC: 0x177f3c | Địa chỉ FDE: 0x0918c0 | Kích thước: 144 bytes
//   0x177f3c: 2A0403E6  mov      w6, w4
//   0x177f40: AA0303E4  mov      x4, x3
//   0x177f44: AA0203E3  mov      x3, x2
//   0x177f48: F90013E8  str      x8, [sp, #0x20]
static inline uint64_t fde_func_1563_0x177f3c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x177f3cULL ^ (static_cast<uint64_t>(0x2a0403e6ULL) << 13);
    acc = (acc + a1 + 0xaa0303e4ULL) ^ 0x0918c0ULL;
    acc ^= (acc >> 17) * 0x0090ULL;
    return acc;
}

// FDE #1564 | PC: 0x177fcc | FDE: 0x091920 | Size: 60 bytes
// Khung tháo gỡ #1564 | Địa chỉ PC: 0x177fcc | Địa chỉ FDE: 0x091920 | Kích thước: 60 bytes
//   0x177fcc: F9414668  ldr      x8, [x19, #0x288]
//   0x177fd0: F942E260  ldr      x0, [x19, #0x5c0]
//   0x177fd4: F100011F  cmp      x8, #0
//   0x177fd8: 1A9F07E1  cset     w1, ne
static inline uint64_t fde_func_1564_0x177fcc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x177fccULL ^ (static_cast<uint64_t>(0xf9414668ULL) << 13);
    acc = (acc + a1 + 0xf942e260ULL) ^ 0x091920ULL;
    acc ^= (acc >> 17) * 0x003cULL;
    return acc;
}

// FDE #1565 | PC: 0x178008 | FDE: 0x091980 | Size: 44 bytes
// Khung tháo gỡ #1565 | Địa chỉ PC: 0x178008 | Địa chỉ FDE: 0x091980 | Kích thước: 44 bytes
//   0x178008: F90013E0  str      x0, [sp, #0x20]
//   0x17800c: 910083E0  add      x0, sp, #0x20
//   0x178010: 140045D0  b        #0x189750
//   0x178014: 52800022  mov      w2, #1
static inline uint64_t fde_func_1565_0x178008(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x178008ULL ^ (static_cast<uint64_t>(0xf90013e0ULL) << 13);
    acc = (acc + a1 + 0x910083e0ULL) ^ 0x091980ULL;
    acc ^= (acc >> 17) * 0x002cULL;
    return acc;
}

// FDE #1566 | PC: 0x178034 | FDE: 0x0919e0 | Size: 84 bytes
// Khung tháo gỡ #1566 | Địa chỉ PC: 0x178034 | Địa chỉ FDE: 0x0919e0 | Kích thước: 84 bytes
//   0x178034: 910063E0  add      x0, sp, #0x18
//   0x178038: 17FCC354  b        #0xa8d88
//   0x17803c: 910063E0  add      x0, sp, #0x18
//   0x178040: F9000FE8  str      x8, [sp, #0x18]
static inline uint64_t fde_func_1566_0x178034(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x178034ULL ^ (static_cast<uint64_t>(0x910063e0ULL) << 13);
    acc = (acc + a1 + 0x17fcc354ULL) ^ 0x0919e0ULL;
    acc ^= (acc >> 17) * 0x0054ULL;
    return acc;
}

// FDE #1567 | PC: 0x178088 | FDE: 0x091a40 | Size: 144 bytes
// Khung tháo gỡ #1567 | Địa chỉ PC: 0x178088 | Địa chỉ FDE: 0x091a40 | Kích thước: 144 bytes
//   0x178088: F9402508  ldr      x8, [x8, #0x48]
//   0x17808c: D61F0100  br       x8
//   0x178090: A94253F5  ldp      x21, x20, [sp, #0x20]
//   0x178094: A9415BF7  ldp      x23, x22, [sp, #0x10]
static inline uint64_t fde_func_1567_0x178088(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x178088ULL ^ (static_cast<uint64_t>(0xf9402508ULL) << 13);
    acc = (acc + a1 + 0xd61f0100ULL) ^ 0x091a40ULL;
    acc ^= (acc >> 17) * 0x0090ULL;
    return acc;
}

// FDE #1568 | PC: 0x178118 | FDE: 0x091aa0 | Size: 120 bytes
// Khung tháo gỡ #1568 | Địa chỉ PC: 0x178118 | Địa chỉ FDE: 0x091aa0 | Kích thước: 120 bytes
//   0x178118: D53BD056  mrs      x22, tpidr_el0
//   0x17811c: F94016C8  ldr      x8, [x22, #0x28]
//   0x178120: AA0003F4  mov      x20, x0
//   0x178124: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_1568_0x178118(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x178118ULL ^ (static_cast<uint64_t>(0xd53bd056ULL) << 13);
    acc = (acc + a1 + 0xf94016c8ULL) ^ 0x091aa0ULL;
    acc ^= (acc >> 17) * 0x0078ULL;
    return acc;
}

// FDE #1569 | PC: 0x178190 | FDE: 0x091b00 | Size: 52 bytes
// Khung tháo gỡ #1569 | Địa chỉ PC: 0x178190 | Địa chỉ FDE: 0x091b00 | Kích thước: 52 bytes
//   0x178190: F9400668  ldr      x8, [x19, #8]
//   0x178194: F9000008  str      x8, [x0]
//   0x178198: D65F03C0  ret      
//   0x17819c: A94453F5  ldp      x21, x20, [sp, #0x40]
static inline uint64_t fde_func_1569_0x178190(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x178190ULL ^ (static_cast<uint64_t>(0xf9400668ULL) << 13);
    acc = (acc + a1 + 0xf9000008ULL) ^ 0x091b00ULL;
    acc ^= (acc >> 17) * 0x0034ULL;
    return acc;
}

// FDE #1570 | PC: 0x1781c4 | FDE: 0x091b60 | Size: 48 bytes
// Khung tháo gỡ #1570 | Địa chỉ PC: 0x1781c4 | Địa chỉ FDE: 0x091b60 | Kích thước: 48 bytes
//   0x1781c4: F85E8108  ldur     x8, [x8, #-0x18]
//   0x1781c8: 8B080260  add      x0, x19, x8
//   0x1781cc: 17FCC22E  b        #0xa8a84
//   0x1781d0: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_1570_0x1781c4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1781c4ULL ^ (static_cast<uint64_t>(0xf85e8108ULL) << 13);
    acc = (acc + a1 + 0x8b080260ULL) ^ 0x091b60ULL;
    acc ^= (acc >> 17) * 0x0030ULL;
    return acc;
}

// FDE #1571 | PC: 0x1781f4 | FDE: 0x091bc0 | Size: 116 bytes
// Khung tháo gỡ #1571 | Địa chỉ PC: 0x1781f4 | Địa chỉ FDE: 0x091bc0 | Kích thước: 116 bytes
//   0x1781f4: D10C0109  sub      x9, x8, #0x300
//   0x1781f8: D10BC10A  sub      x10, x8, #0x2f0
//   0x1781fc: D10B810B  sub      x11, x8, #0x2e0
//   0x178200: D10B4108  sub      x8, x8, #0x2d0
static inline uint64_t fde_func_1571_0x1781f4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1781f4ULL ^ (static_cast<uint64_t>(0xd10c0109ULL) << 13);
    acc = (acc + a1 + 0xd10bc10aULL) ^ 0x091bc0ULL;
    acc ^= (acc >> 17) * 0x0074ULL;
    return acc;
}

// FDE #1572 | PC: 0x178268 | FDE: 0x091c20 | Size: 88 bytes
// Khung tháo gỡ #1572 | Địa chỉ PC: 0x178268 | Địa chỉ FDE: 0x091c20 | Kích thước: 88 bytes
//   0x178268: F9401E80  ldr      x0, [x20, #0x38]
//   0x17826c: 4EA01C03  mov      v3.16b, v0.16b
//   0x178270: 4EA81D00  mov      v0.16b, v8.16b
//   0x178274: 4EA91D21  mov      v1.16b, v9.16b
static inline uint64_t fde_func_1572_0x178268(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x178268ULL ^ (static_cast<uint64_t>(0xf9401e80ULL) << 13);
    acc = (acc + a1 + 0x4ea01c03ULL) ^ 0x091c20ULL;
    acc ^= (acc >> 17) * 0x0058ULL;
    return acc;
}

// FDE #1573 | PC: 0x1782c0 | FDE: 0x091c80 | Size: 52 bytes
// Khung tháo gỡ #1573 | Địa chỉ PC: 0x1782c0 | Địa chỉ FDE: 0x091c80 | Kích thước: 52 bytes
//   0x1782c0: F9401268  ldr      x8, [x19, #0x20]
//   0x1782c4: F9400660  ldr      x0, [x19, #8]
//   0x1782c8: D65F03C0  ret      
//   0x1782cc: F9401268  ldr      x8, [x19, #0x20]
static inline uint64_t fde_func_1573_0x1782c0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1782c0ULL ^ (static_cast<uint64_t>(0xf9401268ULL) << 13);
    acc = (acc + a1 + 0xf9400660ULL) ^ 0x091c80ULL;
    acc ^= (acc >> 17) * 0x0034ULL;
    return acc;
}

// FDE #1574 | PC: 0x1782f4 | FDE: 0x091ce0 | Size: 56 bytes
// Khung tháo gỡ #1574 | Địa chỉ PC: 0x1782f4 | Địa chỉ FDE: 0x091ce0 | Kích thước: 56 bytes
//   0x1782f4: 9100A3E0  add      x0, sp, #0x28
//   0x1782f8: 14003C4E  b        #0x187430
//   0x1782fc: 885FFD09  ldaxr    w9, [x8]
//   0x178300: 0B140129  add      w9, w9, w20
static inline uint64_t fde_func_1574_0x1782f4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1782f4ULL ^ (static_cast<uint64_t>(0x9100a3e0ULL) << 13);
    acc = (acc + a1 + 0x14003c4eULL) ^ 0x091ce0ULL;
    acc ^= (acc >> 17) * 0x0038ULL;
    return acc;
}

// FDE #1575 | PC: 0x17832c | FDE: 0x091d40 | Size: 72 bytes
// Khung tháo gỡ #1575 | Địa chỉ PC: 0x17832c | Địa chỉ FDE: 0x091d40 | Kích thước: 72 bytes
//   0x17832c: F81F0FFE  str      x30, [sp, #-0x10]!
//   0x178330: AA1703E0  mov      x0, x23
//   0x178334: 97FDB440  bl       #0xe5434
//   0x178338: AA0003F6  mov      x22, x0
static inline uint64_t fde_func_1575_0x17832c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x17832cULL ^ (static_cast<uint64_t>(0xf81f0ffeULL) << 13);
    acc = (acc + a1 + 0xaa1703e0ULL) ^ 0x091d40ULL;
    acc ^= (acc >> 17) * 0x0048ULL;
    return acc;
}

// FDE #1576 | PC: 0x178374 | FDE: 0x091da8 | Size: 44 bytes
// Khung tháo gỡ #1576 | Địa chỉ PC: 0x178374 | Địa chỉ FDE: 0x091da8 | Kích thước: 44 bytes
//   0x178374: AA0103F5  mov      x21, x1
//   0x178378: AA0003F3  mov      x19, x0
//   0x17837c: D65F03C0  ret      
//   0x178380: F90007E8  str      x8, [sp, #8]
static inline uint64_t fde_func_1576_0x178374(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x178374ULL ^ (static_cast<uint64_t>(0xaa0103f5ULL) << 13);
    acc = (acc + a1 + 0xaa0003f3ULL) ^ 0x091da8ULL;
    acc ^= (acc >> 17) * 0x002cULL;
    return acc;
}

// FDE #1577 | PC: 0x1783a0 | FDE: 0x091e08 | Size: 52 bytes
// Khung tháo gỡ #1577 | Địa chỉ PC: 0x1783a0 | Địa chỉ FDE: 0x091e08 | Kích thước: 52 bytes
//   0x1783a0: AA0003F3  mov      x19, x0
//   0x1783a4: F90097E8  str      x8, [sp, #0x128]
//   0x1783a8: F9000009  str      x9, [x0]
//   0x1783ac: D65F03C0  ret      
static inline uint64_t fde_func_1577_0x1783a0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1783a0ULL ^ (static_cast<uint64_t>(0xaa0003f3ULL) << 13);
    acc = (acc + a1 + 0xf90097e8ULL) ^ 0x091e08ULL;
    acc ^= (acc >> 17) * 0x0034ULL;
    return acc;
}

// FDE #1578 | PC: 0x1783d4 | FDE: 0x091e68 | Size: 112 bytes
// Khung tháo gỡ #1578 | Địa chỉ PC: 0x1783d4 | Địa chỉ FDE: 0x091e68 | Kích thước: 112 bytes
//   0x1783d4: A9574FF4  ldp      x20, x19, [sp, #0x170]
//   0x1783d8: A95657F6  ldp      x22, x21, [sp, #0x160]
//   0x1783dc: A9555FF8  ldp      x24, x23, [sp, #0x150]
//   0x1783e0: A95467FA  ldp      x26, x25, [sp, #0x140]
static inline uint64_t fde_func_1578_0x1783d4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1783d4ULL ^ (static_cast<uint64_t>(0xa9574ff4ULL) << 13);
    acc = (acc + a1 + 0xa95657f6ULL) ^ 0x091e68ULL;
    acc ^= (acc >> 17) * 0x0070ULL;
    return acc;
}

// FDE #1579 | PC: 0x178444 | FDE: 0x091ec8 | Size: 108 bytes
// Khung tháo gỡ #1579 | Địa chỉ PC: 0x178444 | Địa chỉ FDE: 0x091ec8 | Kích thước: 108 bytes
//   0x178444: 5281BC20  mov      w0, #0xde1
//   0x178448: 52850061  mov      w1, #0x2803
//   0x17844c: 529025E2  mov      w2, #0x812f
//   0x178450: 140041B0  b        #0x188b10
static inline uint64_t fde_func_1579_0x178444(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x178444ULL ^ (static_cast<uint64_t>(0x5281bc20ULL) << 13);
    acc = (acc + a1 + 0x52850061ULL) ^ 0x091ec8ULL;
    acc ^= (acc >> 17) * 0x006cULL;
    return acc;
}

// FDE #1580 | PC: 0x1784b0 | FDE: 0x091f28 | Size: 84 bytes
// Khung tháo gỡ #1580 | Địa chỉ PC: 0x1784b0 | Địa chỉ FDE: 0x091f28 | Kích thước: 84 bytes
//   0x1784b0: 8B284AA0  add      x0, x21, w8, uxtw #2
//   0x1784b4: 914007E8  add      x8, sp, #1, lsl #12
//   0x1784b8: 91020108  add      x8, x8, #0x80
//   0x1784bc: 140045ED  b        #0x189c70
static inline uint64_t fde_func_1580_0x1784b0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1784b0ULL ^ (static_cast<uint64_t>(0x8b284aa0ULL) << 13);
    acc = (acc + a1 + 0x914007e8ULL) ^ 0x091f28ULL;
    acc ^= (acc >> 17) * 0x0054ULL;
    return acc;
}

// FDE #1581 | PC: 0x178504 | FDE: 0x091f88 | Size: 92 bytes
// Khung tháo gỡ #1581 | Địa chỉ PC: 0x178504 | Địa chỉ FDE: 0x091f88 | Kích thước: 92 bytes
//   0x178504: 52800021  mov      w1, #1
//   0x178508: 1400466A  b        #0x189eb0
//   0x17850c: 9100C015  add      x21, x0, #0x30
//   0x178510: 2A0103F4  mov      w20, w1
static inline uint64_t fde_func_1581_0x178504(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x178504ULL ^ (static_cast<uint64_t>(0x52800021ULL) << 13);
    acc = (acc + a1 + 0x1400466aULL) ^ 0x091f88ULL;
    acc ^= (acc >> 17) * 0x005cULL;
    return acc;
}

// FDE #1582 | PC: 0x178560 | FDE: 0x091fe8 | Size: 92 bytes
// Khung tháo gỡ #1582 | Địa chỉ PC: 0x178560 | Địa chỉ FDE: 0x091fe8 | Kích thước: 92 bytes
//   0x178560: D37DF280  lsl      x0, x20, #3
//   0x178564: 14003B6F  b        #0x187320
//   0x178568: 2A0403E2  mov      w2, w4
//   0x17856c: 2A0503E3  mov      w3, w5
static inline uint64_t fde_func_1582_0x178560(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x178560ULL ^ (static_cast<uint64_t>(0xd37df280ULL) << 13);
    acc = (acc + a1 + 0x14003b6fULL) ^ 0x091fe8ULL;
    acc ^= (acc >> 17) * 0x005cULL;
    return acc;
}

// FDE #1583 | PC: 0x1785bc | FDE: 0x092048 | Size: 48 bytes
// Khung tháo gỡ #1583 | Địa chỉ PC: 0x1785bc | Địa chỉ FDE: 0x092048 | Kích thước: 48 bytes
//   0x1785bc: A900FC1F  stp      xzr, xzr, [x0, #8]
//   0x1785c0: F9000008  str      x8, [x0]
//   0x1785c4: D65F03C0  ret      
//   0x1785c8: F9407FE9  ldr      x9, [sp, #0xf8]
static inline uint64_t fde_func_1583_0x1785bc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1785bcULL ^ (static_cast<uint64_t>(0xa900fc1fULL) << 13);
    acc = (acc + a1 + 0xf9000008ULL) ^ 0x092048ULL;
    acc ^= (acc >> 17) * 0x0030ULL;
    return acc;
}

// FDE #1584 | PC: 0x1785ec | FDE: 0x0920a8 | Size: 76 bytes
// Khung tháo gỡ #1584 | Địa chỉ PC: 0x1785ec | Địa chỉ FDE: 0x0920a8 | Kích thước: 76 bytes
//   0x1785ec: 910203E0  add      x0, sp, #0x80
//   0x1785f0: 14003BBC  b        #0x1874e0
//   0x1785f4: 2A1703E3  mov      w3, w23
//   0x1785f8: 2A1603E4  mov      w4, w22
static inline uint64_t fde_func_1584_0x1785ec(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1785ecULL ^ (static_cast<uint64_t>(0x910203e0ULL) << 13);
    acc = (acc + a1 + 0x14003bbcULL) ^ 0x0920a8ULL;
    acc ^= (acc >> 17) * 0x004cULL;
    return acc;
}

// FDE #1585 | PC: 0x178638 | FDE: 0x092108 | Size: 44 bytes
// Khung tháo gỡ #1585 | Địa chỉ PC: 0x178638 | Địa chỉ FDE: 0x092108 | Kích thước: 44 bytes
//   0x178638: F9402A61  ldr      x1, [x19, #0x50]
//   0x17863c: AA0003F6  mov      x22, x0
//   0x178640: D65F03C0  ret      
//   0x178644: 910383FF  add      sp, sp, #0xe0
static inline uint64_t fde_func_1585_0x178638(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x178638ULL ^ (static_cast<uint64_t>(0xf9402a61ULL) << 13);
    acc = (acc + a1 + 0xaa0003f6ULL) ^ 0x092108ULL;
    acc ^= (acc >> 17) * 0x002cULL;
    return acc;
}

// FDE #1586 | PC: 0x178664 | FDE: 0x092168 | Size: 48 bytes
// Khung tháo gỡ #1586 | Địa chỉ PC: 0x178664 | Địa chỉ FDE: 0x092168 | Kích thước: 48 bytes
//   0x178664: A90587E0  stp      x0, x1, [sp, #0x58]
//   0x178668: 910163E0  add      x0, sp, #0x58
//   0x17866c: 14003BA9  b        #0x187510
//   0x178670: F9401668  ldr      x8, [x19, #0x28]
static inline uint64_t fde_func_1586_0x178664(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x178664ULL ^ (static_cast<uint64_t>(0xa90587e0ULL) << 13);
    acc = (acc + a1 + 0x910163e0ULL) ^ 0x092168ULL;
    acc ^= (acc >> 17) * 0x0030ULL;
    return acc;
}

// FDE #1587 | PC: 0x178694 | FDE: 0x0921c8 | Size: 84 bytes
// Khung tháo gỡ #1587 | Địa chỉ PC: 0x178694 | Địa chỉ FDE: 0x0921c8 | Kích thước: 84 bytes
//   0x178694: D53BD054  mrs      x20, tpidr_el0
//   0x178698: F9401688  ldr      x8, [x20, #0x28]
//   0x17869c: AA0103E2  mov      x2, x1
//   0x1786a0: AA0003E1  mov      x1, x0
static inline uint64_t fde_func_1587_0x178694(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x178694ULL ^ (static_cast<uint64_t>(0xd53bd054ULL) << 13);
    acc = (acc + a1 + 0xf9401688ULL) ^ 0x0921c8ULL;
    acc ^= (acc >> 17) * 0x0054ULL;
    return acc;
}

// FDE #1588 | PC: 0x1786e8 | FDE: 0x092228 | Size: 44 bytes
// Khung tháo gỡ #1588 | Địa chỉ PC: 0x1786e8 | Địa chỉ FDE: 0x092228 | Kích thước: 44 bytes
//   0x1786e8: AA1303E0  mov      x0, x19
//   0x1786ec: 2A1F03E1  mov      w1, wzr
//   0x1786f0: 17FF5F39  b        #0x1503d4
//   0x1786f4: AA1603E0  mov      x0, x22
static inline uint64_t fde_func_1588_0x1786e8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1786e8ULL ^ (static_cast<uint64_t>(0xaa1303e0ULL) << 13);
    acc = (acc + a1 + 0x2a1f03e1ULL) ^ 0x092228ULL;
    acc ^= (acc >> 17) * 0x002cULL;
    return acc;
}

// FDE #1589 | PC: 0x178714 | FDE: 0x092288 | Size: 68 bytes
// Khung tháo gỡ #1589 | Địa chỉ PC: 0x178714 | Địa chỉ FDE: 0x092288 | Kích thước: 68 bytes
//   0x178714: AA0003F3  mov      x19, x0
//   0x178718: AA1603E0  mov      x0, x22
//   0x17871c: 2A1403E1  mov      w1, w20
//   0x178720: 17FF37EC  b        #0x1466d0
static inline uint64_t fde_func_1589_0x178714(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x178714ULL ^ (static_cast<uint64_t>(0xaa0003f3ULL) << 13);
    acc = (acc + a1 + 0xaa1603e0ULL) ^ 0x092288ULL;
    acc ^= (acc >> 17) * 0x0044ULL;
    return acc;
}

// FDE #1590 | PC: 0x178758 | FDE: 0x0922e8 | Size: 60 bytes
// Khung tháo gỡ #1590 | Địa chỉ PC: 0x178758 | Địa chỉ FDE: 0x0922e8 | Kích thước: 60 bytes
//   0x178758: 910023E0  add      x0, sp, #8
//   0x17875c: 14003B21  b        #0x1873e0
//   0x178760: D105C3FF  sub      sp, sp, #0x170
//   0x178764: F9009BFC  str      x28, [sp, #0x130]
static inline uint64_t fde_func_1590_0x178758(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x178758ULL ^ (static_cast<uint64_t>(0x910023e0ULL) << 13);
    acc = (acc + a1 + 0x14003b21ULL) ^ 0x0922e8ULL;
    acc ^= (acc >> 17) * 0x003cULL;
    return acc;
}

// FDE #1591 | PC: 0x178794 | FDE: 0x092348 | Size: 80 bytes
// Khung tháo gỡ #1591 | Địa chỉ PC: 0x178794 | Địa chỉ FDE: 0x092348 | Kích thước: 80 bytes
//   0x178794: F9401BE1  ldr      x1, [sp, #0x30]
//   0x178798: F94013F4  ldr      x20, [sp, #0x20]
//   0x17879c: D65F03C0  ret      
//   0x1787a0: AA0003E6  mov      x6, x0
static inline uint64_t fde_func_1591_0x178794(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x178794ULL ^ (static_cast<uint64_t>(0xf9401be1ULL) << 13);
    acc = (acc + a1 + 0xf94013f4ULL) ^ 0x092348ULL;
    acc ^= (acc >> 17) * 0x0050ULL;
    return acc;
}

// FDE #1592 | PC: 0x1787e4 | FDE: 0x0923a8 | Size: 112 bytes
// Khung tháo gỡ #1592 | Địa chỉ PC: 0x1787e4 | Địa chỉ FDE: 0x0923a8 | Kích thước: 112 bytes
//   0x1787e4: B9400274  ldr      w20, [x19]
//   0x1787e8: 11000688  add      w8, w20, #1
//   0x1787ec: B9000268  str      w8, [x19]
//   0x1787f0: D65F03C0  ret      
static inline uint64_t fde_func_1592_0x1787e4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1787e4ULL ^ (static_cast<uint64_t>(0xb9400274ULL) << 13);
    acc = (acc + a1 + 0x11000688ULL) ^ 0x0923a8ULL;
    acc ^= (acc >> 17) * 0x0070ULL;
    return acc;
}

// FDE #1593 | PC: 0x178854 | FDE: 0x092408 | Size: 128 bytes
// Khung tháo gỡ #1593 | Địa chỉ PC: 0x178854 | Địa chỉ FDE: 0x092408 | Kích thước: 128 bytes
//   0x178854: 8B080AB5  add      x21, x21, x8, lsl #2
//   0x178858: 11001D08  add      w8, w8, #7
//   0x17885c: B9000268  str      w8, [x19]
//   0x178860: B9401AB4  ldr      w20, [x21, #0x18]
static inline uint64_t fde_func_1593_0x178854(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x178854ULL ^ (static_cast<uint64_t>(0x8b080ab5ULL) << 13);
    acc = (acc + a1 + 0x11001d08ULL) ^ 0x092408ULL;
    acc ^= (acc >> 17) * 0x0080ULL;
    return acc;
}

// FDE #1594 | PC: 0x1788d4 | FDE: 0x092468 | Size: 120 bytes
// Khung tháo gỡ #1594 | Địa chỉ PC: 0x1788d4 | Địa chỉ FDE: 0x092468 | Kích thước: 120 bytes
//   0x1788d4: B9400269  ldr      w9, [x19]
//   0x1788d8: 1100152A  add      w10, w9, #5
//   0x1788dc: 8B090AA8  add      x8, x21, x9, lsl #2
//   0x1788e0: B900026A  str      w10, [x19]
static inline uint64_t fde_func_1594_0x1788d4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1788d4ULL ^ (static_cast<uint64_t>(0xb9400269ULL) << 13);
    acc = (acc + a1 + 0x1100152aULL) ^ 0x092468ULL;
    acc ^= (acc >> 17) * 0x0078ULL;
    return acc;
}

// FDE #1595 | PC: 0x17894c | FDE: 0x0924c8 | Size: 84 bytes
// Khung tháo gỡ #1595 | Địa chỉ PC: 0x17894c | Địa chỉ FDE: 0x0924c8 | Kích thước: 84 bytes
//   0x17894c: F1000F3F  cmp      x25, #3
//   0x178950: D1000728  sub      x8, x25, #1
//   0x178954: 1A9F27E9  cset     w9, lo
//   0x178958: EA08033F  tst      x25, x8
static inline uint64_t fde_func_1595_0x17894c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x17894cULL ^ (static_cast<uint64_t>(0xf1000f3fULL) << 13);
    acc = (acc + a1 + 0xd1000728ULL) ^ 0x0924c8ULL;
    acc ^= (acc >> 17) * 0x0054ULL;
    return acc;
}

// FDE #1596 | PC: 0x1789a0 | FDE: 0x092528 | Size: 60 bytes
// Khung tháo gỡ #1596 | Địa chỉ PC: 0x1789a0 | Địa chỉ FDE: 0x092528 | Kích thước: 60 bytes
//   0x1789a0: 910303FF  add      sp, sp, #0xc0
//   0x1789a4: D65F03C0  ret      
//   0x1789a8: 9100E3E0  add      x0, sp, #0x38
//   0x1789ac: 14003AA1  b        #0x187430
static inline uint64_t fde_func_1596_0x1789a0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1789a0ULL ^ (static_cast<uint64_t>(0x910303ffULL) << 13);
    acc = (acc + a1 + 0xd65f03c0ULL) ^ 0x092528ULL;
    acc ^= (acc >> 17) * 0x003cULL;
    return acc;
}

// FDE #1597 | PC: 0x1789dc | FDE: 0x092590 | Size: 48 bytes
// Khung tháo gỡ #1597 | Địa chỉ PC: 0x1789dc | Địa chỉ FDE: 0x092590 | Kích thước: 48 bytes
//   0x1789dc: 910243E0  add      x0, sp, #0x90
//   0x1789e0: 14003AC0  b        #0x1874e0
//   0x1789e4: F9400269  ldr      x9, [x19]
//   0x1789e8: 5280002A  mov      w10, #1
static inline uint64_t fde_func_1597_0x1789dc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1789dcULL ^ (static_cast<uint64_t>(0x910243e0ULL) << 13);
    acc = (acc + a1 + 0x14003ac0ULL) ^ 0x092590ULL;
    acc ^= (acc >> 17) * 0x0030ULL;
    return acc;
}

// FDE #1598 | PC: 0x178a0c | FDE: 0x0925f0 | Size: 76 bytes
// Khung tháo gỡ #1598 | Địa chỉ PC: 0x178a0c | Địa chỉ FDE: 0x0925f0 | Kích thước: 76 bytes
//   0x178a0c: D101C3FF  sub      sp, sp, #0x70
//   0x178a10: A9026BFB  stp      x27, x26, [sp, #0x20]
//   0x178a14: A90363F9  stp      x25, x24, [sp, #0x30]
//   0x178a18: A9045BF7  stp      x23, x22, [sp, #0x40]
static inline uint64_t fde_func_1598_0x178a0c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x178a0cULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xa9026bfbULL) ^ 0x0925f0ULL;
    acc ^= (acc >> 17) * 0x004cULL;
    return acc;
}

// FDE #1599 | PC: 0x178a58 | FDE: 0x092650 | Size: 68 bytes
// Khung tháo gỡ #1599 | Địa chỉ PC: 0x178a58 | Địa chỉ FDE: 0x092650 | Kích thước: 68 bytes
//   0x178a58: AA1F03E0  mov      x0, xzr
//   0x178a5c: D65F03C0  ret      
//   0x178a60: AA1F03E8  mov      x8, xzr
//   0x178a64: F9000674  str      x20, [x19, #8]
static inline uint64_t fde_func_1599_0x178a58(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x178a58ULL ^ (static_cast<uint64_t>(0xaa1f03e0ULL) << 13);
    acc = (acc + a1 + 0xd65f03c0ULL) ^ 0x092650ULL;
    acc ^= (acc >> 17) * 0x0044ULL;
    return acc;
}

// Shard 4 Dispatcher / Bộ điều phối phân mảnh 4
uint64_t execute_fde_shard_4(uint32_t fde_idx, uint64_t a0, uint64_t a1) {
    switch (fde_idx) {
        case 1200: return fde_func_1200_0x13d8c4(a0, a1);
        case 1201: return fde_func_1201_0x13de48(a0, a1);
        case 1202: return fde_func_1202_0x13e0d0(a0, a1);
        case 1203: return fde_func_1203_0x13e200(a0, a1);
        case 1204: return fde_func_1204_0x13e3f8(a0, a1);
        case 1205: return fde_func_1205_0x13e5a0(a0, a1);
        case 1206: return fde_func_1206_0x13ed30(a0, a1);
        case 1207: return fde_func_1207_0x13f0dc(a0, a1);
        case 1208: return fde_func_1208_0x13f200(a0, a1);
        case 1209: return fde_func_1209_0x13f2f8(a0, a1);
        case 1210: return fde_func_1210_0x13f614(a0, a1);
        case 1211: return fde_func_1211_0x13f9b4(a0, a1);
        case 1212: return fde_func_1212_0x13fd74(a0, a1);
        case 1213: return fde_func_1213_0x140160(a0, a1);
        case 1214: return fde_func_1214_0x140510(a0, a1);
        case 1215: return fde_func_1215_0x140848(a0, a1);
        case 1216: return fde_func_1216_0x140a50(a0, a1);
        case 1217: return fde_func_1217_0x140dd0(a0, a1);
        case 1218: return fde_func_1218_0x140fc4(a0, a1);
        case 1219: return fde_func_1219_0x1412e0(a0, a1);
        case 1220: return fde_func_1220_0x141650(a0, a1);
        case 1221: return fde_func_1221_0x141a40(a0, a1);
        case 1222: return fde_func_1222_0x141e70(a0, a1);
        case 1223: return fde_func_1223_0x14224c(a0, a1);
        case 1224: return fde_func_1224_0x142584(a0, a1);
        case 1225: return fde_func_1225_0x1428d4(a0, a1);
        case 1226: return fde_func_1226_0x142c1c(a0, a1);
        case 1227: return fde_func_1227_0x142ed4(a0, a1);
        case 1228: return fde_func_1228_0x14321c(a0, a1);
        case 1229: return fde_func_1229_0x1439cc(a0, a1);
        case 1230: return fde_func_1230_0x143b8c(a0, a1);
        case 1231: return fde_func_1231_0x143e10(a0, a1);
        case 1232: return fde_func_1232_0x144118(a0, a1);
        case 1233: return fde_func_1233_0x144610(a0, a1);
        case 1234: return fde_func_1234_0x144768(a0, a1);
        case 1235: return fde_func_1235_0x144800(a0, a1);
        case 1236: return fde_func_1236_0x14492c(a0, a1);
        case 1237: return fde_func_1237_0x1449b4(a0, a1);
        case 1238: return fde_func_1238_0x144a18(a0, a1);
        case 1239: return fde_func_1239_0x144a48(a0, a1);
        case 1240: return fde_func_1240_0x1465c8(a0, a1);
        case 1241: return fde_func_1241_0x14671c(a0, a1);
        case 1242: return fde_func_1242_0x1467ec(a0, a1);
        case 1243: return fde_func_1243_0x146874(a0, a1);
        case 1244: return fde_func_1244_0x146a10(a0, a1);
        case 1245: return fde_func_1245_0x146b70(a0, a1);
        case 1246: return fde_func_1246_0x14d3b0(a0, a1);
        case 1247: return fde_func_1247_0x14d47c(a0, a1);
        case 1248: return fde_func_1248_0x14d5a0(a0, a1);
        case 1249: return fde_func_1249_0x14d698(a0, a1);
        case 1250: return fde_func_1250_0x14d754(a0, a1);
        case 1251: return fde_func_1251_0x14d894(a0, a1);
        case 1252: return fde_func_1252_0x14d9d4(a0, a1);
        case 1253: return fde_func_1253_0x14db14(a0, a1);
        case 1254: return fde_func_1254_0x14dc54(a0, a1);
        case 1255: return fde_func_1255_0x14dee0(a0, a1);
        case 1256: return fde_func_1256_0x14e194(a0, a1);
        case 1257: return fde_func_1257_0x14e21c(a0, a1);
        case 1258: return fde_func_1258_0x14e3a8(a0, a1);
        case 1259: return fde_func_1259_0x14e42c(a0, a1);
        case 1260: return fde_func_1260_0x14e8cc(a0, a1);
        case 1261: return fde_func_1261_0x14edcc(a0, a1);
        case 1262: return fde_func_1262_0x14f014(a0, a1);
        case 1263: return fde_func_1263_0x14f0d4(a0, a1);
        case 1264: return fde_func_1264_0x14f1e8(a0, a1);
        case 1265: return fde_func_1265_0x14f3d4(a0, a1);
        case 1266: return fde_func_1266_0x14f570(a0, a1);
        case 1267: return fde_func_1267_0x14f778(a0, a1);
        case 1268: return fde_func_1268_0x14f88c(a0, a1);
        case 1269: return fde_func_1269_0x14f90c(a0, a1);
        case 1270: return fde_func_1270_0x14f99c(a0, a1);
        case 1271: return fde_func_1271_0x14fa54(a0, a1);
        case 1272: return fde_func_1272_0x14fb00(a0, a1);
        case 1273: return fde_func_1273_0x14fbac(a0, a1);
        case 1274: return fde_func_1274_0x1500ec(a0, a1);
        case 1275: return fde_func_1275_0x150228(a0, a1);
        case 1276: return fde_func_1276_0x1502e8(a0, a1);
        case 1277: return fde_func_1277_0x150398(a0, a1);
        case 1278: return fde_func_1278_0x150488(a0, a1);
        case 1279: return fde_func_1279_0x15066c(a0, a1);
        case 1280: return fde_func_1280_0x150978(a0, a1);
        case 1281: return fde_func_1281_0x150a6c(a0, a1);
        case 1282: return fde_func_1282_0x150b3c(a0, a1);
        case 1283: return fde_func_1283_0x150b68(a0, a1);
        case 1284: return fde_func_1284_0x150ba8(a0, a1);
        case 1285: return fde_func_1285_0x150ca0(a0, a1);
        case 1286: return fde_func_1286_0x150d40(a0, a1);
        case 1287: return fde_func_1287_0x150e34(a0, a1);
        case 1288: return fde_func_1288_0x150ed4(a0, a1);
        case 1289: return fde_func_1289_0x150f40(a0, a1);
        case 1290: return fde_func_1290_0x150fd8(a0, a1);
        case 1291: return fde_func_1291_0x151234(a0, a1);
        case 1292: return fde_func_1292_0x1512e4(a0, a1);
        case 1293: return fde_func_1293_0x1513c0(a0, a1);
        case 1294: return fde_func_1294_0x1514c8(a0, a1);
        case 1295: return fde_func_1295_0x1515d8(a0, a1);
        case 1296: return fde_func_1296_0x1516f0(a0, a1);
        case 1297: return fde_func_1297_0x1518b0(a0, a1);
        case 1298: return fde_func_1298_0x151f14(a0, a1);
        case 1299: return fde_func_1299_0x152360(a0, a1);
        case 1300: return fde_func_1300_0x1525e4(a0, a1);
        case 1301: return fde_func_1301_0x152884(a0, a1);
        case 1302: return fde_func_1302_0x1529ac(a0, a1);
        case 1303: return fde_func_1303_0x152b48(a0, a1);
        case 1304: return fde_func_1304_0x152d3c(a0, a1);
        case 1305: return fde_func_1305_0x153018(a0, a1);
        case 1306: return fde_func_1306_0x15315c(a0, a1);
        case 1307: return fde_func_1307_0x153928(a0, a1);
        case 1308: return fde_func_1308_0x153b0c(a0, a1);
        case 1309: return fde_func_1309_0x153c0c(a0, a1);
        case 1310: return fde_func_1310_0x154074(a0, a1);
        case 1311: return fde_func_1311_0x154364(a0, a1);
        case 1312: return fde_func_1312_0x15467c(a0, a1);
        case 1313: return fde_func_1313_0x15499c(a0, a1);
        case 1314: return fde_func_1314_0x154bd4(a0, a1);
        case 1315: return fde_func_1315_0x154da0(a0, a1);
        case 1316: return fde_func_1316_0x154f1c(a0, a1);
        case 1317: return fde_func_1317_0x1551e8(a0, a1);
        case 1318: return fde_func_1318_0x155324(a0, a1);
        case 1319: return fde_func_1319_0x1554ac(a0, a1);
        case 1320: return fde_func_1320_0x1556e4(a0, a1);
        case 1321: return fde_func_1321_0x1557fc(a0, a1);
        case 1322: return fde_func_1322_0x1558c4(a0, a1);
        case 1323: return fde_func_1323_0x155980(a0, a1);
        case 1324: return fde_func_1324_0x155b90(a0, a1);
        case 1325: return fde_func_1325_0x1560e0(a0, a1);
        case 1326: return fde_func_1326_0x156480(a0, a1);
        case 1327: return fde_func_1327_0x156ad4(a0, a1);
        case 1328: return fde_func_1328_0x157940(a0, a1);
        case 1329: return fde_func_1329_0x1579d4(a0, a1);
        case 1330: return fde_func_1330_0x157a74(a0, a1);
        case 1331: return fde_func_1331_0x157ad0(a0, a1);
        case 1332: return fde_func_1332_0x159630(a0, a1);
        case 1333: return fde_func_1333_0x159a10(a0, a1);
        case 1334: return fde_func_1334_0x15a2a8(a0, a1);
        case 1335: return fde_func_1335_0x15a520(a0, a1);
        case 1336: return fde_func_1336_0x15a6bc(a0, a1);
        case 1337: return fde_func_1337_0x15a8fc(a0, a1);
        case 1338: return fde_func_1338_0x15b0d8(a0, a1);
        case 1339: return fde_func_1339_0x15b2a4(a0, a1);
        case 1340: return fde_func_1340_0x15b7e0(a0, a1);
        case 1341: return fde_func_1341_0x15bfac(a0, a1);
        case 1342: return fde_func_1342_0x15c160(a0, a1);
        case 1343: return fde_func_1343_0x15c46c(a0, a1);
        case 1344: return fde_func_1344_0x15c738(a0, a1);
        case 1345: return fde_func_1345_0x15c950(a0, a1);
        case 1346: return fde_func_1346_0x15cbb8(a0, a1);
        case 1347: return fde_func_1347_0x15cc9c(a0, a1);
        case 1348: return fde_func_1348_0x15ce94(a0, a1);
        case 1349: return fde_func_1349_0x15d058(a0, a1);
        case 1350: return fde_func_1350_0x15d3f0(a0, a1);
        case 1351: return fde_func_1351_0x15db08(a0, a1);
        case 1352: return fde_func_1352_0x15e08c(a0, a1);
        case 1353: return fde_func_1353_0x15e2e4(a0, a1);
        case 1354: return fde_func_1354_0x15e504(a0, a1);
        case 1355: return fde_func_1355_0x15e610(a0, a1);
        case 1356: return fde_func_1356_0x15e814(a0, a1);
        case 1357: return fde_func_1357_0x15f48c(a0, a1);
        case 1358: return fde_func_1358_0x1616a8(a0, a1);
        case 1359: return fde_func_1359_0x1618a0(a0, a1);
        case 1360: return fde_func_1360_0x1619e0(a0, a1);
        case 1361: return fde_func_1361_0x161bf8(a0, a1);
        case 1362: return fde_func_1362_0x161fbc(a0, a1);
        case 1363: return fde_func_1363_0x16225c(a0, a1);
        case 1364: return fde_func_1364_0x1623a0(a0, a1);
        case 1365: return fde_func_1365_0x162ab0(a0, a1);
        case 1366: return fde_func_1366_0x162f28(a0, a1);
        case 1367: return fde_func_1367_0x16366c(a0, a1);
        case 1368: return fde_func_1368_0x1637f8(a0, a1);
        case 1369: return fde_func_1369_0x163ecc(a0, a1);
        case 1370: return fde_func_1370_0x1640f4(a0, a1);
        case 1371: return fde_func_1371_0x16422c(a0, a1);
        case 1372: return fde_func_1372_0x164338(a0, a1);
        case 1373: return fde_func_1373_0x1643d8(a0, a1);
        case 1374: return fde_func_1374_0x164428(a0, a1);
        case 1375: return fde_func_1375_0x164578(a0, a1);
        case 1376: return fde_func_1376_0x1647d0(a0, a1);
        case 1377: return fde_func_1377_0x1659c8(a0, a1);
        case 1378: return fde_func_1378_0x165e30(a0, a1);
        case 1379: return fde_func_1379_0x166508(a0, a1);
        case 1380: return fde_func_1380_0x166768(a0, a1);
        case 1381: return fde_func_1381_0x1669a8(a0, a1);
        case 1382: return fde_func_1382_0x166b7c(a0, a1);
        case 1383: return fde_func_1383_0x166cd0(a0, a1);
        case 1384: return fde_func_1384_0x166ecc(a0, a1);
        case 1385: return fde_func_1385_0x167090(a0, a1);
        case 1386: return fde_func_1386_0x16742c(a0, a1);
        case 1387: return fde_func_1387_0x167718(a0, a1);
        case 1388: return fde_func_1388_0x16773c(a0, a1);
        case 1389: return fde_func_1389_0x167794(a0, a1);
        case 1390: return fde_func_1390_0x167b98(a0, a1);
        case 1391: return fde_func_1391_0x168298(a0, a1);
        case 1392: return fde_func_1392_0x168418(a0, a1);
        case 1393: return fde_func_1393_0x169830(a0, a1);
        case 1394: return fde_func_1394_0x169ab0(a0, a1);
        case 1395: return fde_func_1395_0x169fa8(a0, a1);
        case 1396: return fde_func_1396_0x16a344(a0, a1);
        case 1397: return fde_func_1397_0x16acd8(a0, a1);
        case 1398: return fde_func_1398_0x16b434(a0, a1);
        case 1399: return fde_func_1399_0x16bcf4(a0, a1);
        case 1400: return fde_func_1400_0x16bf2c(a0, a1);
        case 1401: return fde_func_1401_0x16c400(a0, a1);
        case 1402: return fde_func_1402_0x16d32c(a0, a1);
        case 1403: return fde_func_1403_0x16d514(a0, a1);
        case 1404: return fde_func_1404_0x16ebb0(a0, a1);
        case 1405: return fde_func_1405_0x16eeb8(a0, a1);
        case 1406: return fde_func_1406_0x16f1ac(a0, a1);
        case 1407: return fde_func_1407_0x16f20c(a0, a1);
        case 1408: return fde_func_1408_0x16f33c(a0, a1);
        case 1409: return fde_func_1409_0x16f840(a0, a1);
        case 1410: return fde_func_1410_0x16fb98(a0, a1);
        case 1411: return fde_func_1411_0x16fd3c(a0, a1);
        case 1412: return fde_func_1412_0x16fe64(a0, a1);
        case 1413: return fde_func_1413_0x1700ec(a0, a1);
        case 1414: return fde_func_1414_0x170254(a0, a1);
        case 1415: return fde_func_1415_0x1704a8(a0, a1);
        case 1416: return fde_func_1416_0x170644(a0, a1);
        case 1417: return fde_func_1417_0x1708d8(a0, a1);
        case 1418: return fde_func_1418_0x170a20(a0, a1);
        case 1419: return fde_func_1419_0x170de4(a0, a1);
        case 1420: return fde_func_1420_0x171648(a0, a1);
        case 1421: return fde_func_1421_0x171978(a0, a1);
        case 1422: return fde_func_1422_0x171a88(a0, a1);
        case 1423: return fde_func_1423_0x171b08(a0, a1);
        case 1424: return fde_func_1424_0x172140(a0, a1);
        case 1425: return fde_func_1425_0x172798(a0, a1);
        case 1426: return fde_func_1426_0x172d98(a0, a1);
        case 1427: return fde_func_1427_0x172e8c(a0, a1);
        case 1428: return fde_func_1428_0x17345c(a0, a1);
        case 1429: return fde_func_1429_0x173a90(a0, a1);
        case 1430: return fde_func_1430_0x173d74(a0, a1);
        case 1431: return fde_func_1431_0x174800(a0, a1);
        case 1432: return fde_func_1432_0x174a4c(a0, a1);
        case 1433: return fde_func_1433_0x174ddc(a0, a1);
        case 1434: return fde_func_1434_0x1750b0(a0, a1);
        case 1435: return fde_func_1435_0x1753f4(a0, a1);
        case 1436: return fde_func_1436_0x175718(a0, a1);
        case 1437: return fde_func_1437_0x1757e0(a0, a1);
        case 1438: return fde_func_1438_0x175888(a0, a1);
        case 1439: return fde_func_1439_0x1758b0(a0, a1);
        case 1440: return fde_func_1440_0x175930(a0, a1);
        case 1441: return fde_func_1441_0x175978(a0, a1);
        case 1442: return fde_func_1442_0x1759a4(a0, a1);
        case 1443: return fde_func_1443_0x1759d4(a0, a1);
        case 1444: return fde_func_1444_0x175a08(a0, a1);
        case 1445: return fde_func_1445_0x175a78(a0, a1);
        case 1446: return fde_func_1446_0x175ad8(a0, a1);
        case 1447: return fde_func_1447_0x175b04(a0, a1);
        case 1448: return fde_func_1448_0x175b38(a0, a1);
        case 1449: return fde_func_1449_0x175b80(a0, a1);
        case 1450: return fde_func_1450_0x175bf4(a0, a1);
        case 1451: return fde_func_1451_0x175c24(a0, a1);
        case 1452: return fde_func_1452_0x175c48(a0, a1);
        case 1453: return fde_func_1453_0x175cb0(a0, a1);
        case 1454: return fde_func_1454_0x175ce4(a0, a1);
        case 1455: return fde_func_1455_0x175d30(a0, a1);
        case 1456: return fde_func_1456_0x175da4(a0, a1);
        case 1457: return fde_func_1457_0x175e10(a0, a1);
        case 1458: return fde_func_1458_0x175e60(a0, a1);
        case 1459: return fde_func_1459_0x175eb4(a0, a1);
        case 1460: return fde_func_1460_0x175efc(a0, a1);
        case 1461: return fde_func_1461_0x175f34(a0, a1);
        case 1462: return fde_func_1462_0x175f8c(a0, a1);
        case 1463: return fde_func_1463_0x175fd4(a0, a1);
        case 1464: return fde_func_1464_0x17601c(a0, a1);
        case 1465: return fde_func_1465_0x176060(a0, a1);
        case 1466: return fde_func_1466_0x1760c0(a0, a1);
        case 1467: return fde_func_1467_0x176120(a0, a1);
        case 1468: return fde_func_1468_0x176188(a0, a1);
        case 1469: return fde_func_1469_0x1761b4(a0, a1);
        case 1470: return fde_func_1470_0x176248(a0, a1);
        case 1471: return fde_func_1471_0x1762c4(a0, a1);
        case 1472: return fde_func_1472_0x176318(a0, a1);
        case 1473: return fde_func_1473_0x176354(a0, a1);
        case 1474: return fde_func_1474_0x1763a8(a0, a1);
        case 1475: return fde_func_1475_0x1763f0(a0, a1);
        case 1476: return fde_func_1476_0x176430(a0, a1);
        case 1477: return fde_func_1477_0x1764c0(a0, a1);
        case 1478: return fde_func_1478_0x1764fc(a0, a1);
        case 1479: return fde_func_1479_0x176558(a0, a1);
        case 1480: return fde_func_1480_0x1765a0(a0, a1);
        case 1481: return fde_func_1481_0x1765e0(a0, a1);
        case 1482: return fde_func_1482_0x176638(a0, a1);
        case 1483: return fde_func_1483_0x176678(a0, a1);
        case 1484: return fde_func_1484_0x1766dc(a0, a1);
        case 1485: return fde_func_1485_0x176718(a0, a1);
        case 1486: return fde_func_1486_0x1767ac(a0, a1);
        case 1487: return fde_func_1487_0x1767fc(a0, a1);
        case 1488: return fde_func_1488_0x176838(a0, a1);
        case 1489: return fde_func_1489_0x17687c(a0, a1);
        case 1490: return fde_func_1490_0x1768bc(a0, a1);
        case 1491: return fde_func_1491_0x1768fc(a0, a1);
        case 1492: return fde_func_1492_0x176944(a0, a1);
        case 1493: return fde_func_1493_0x17699c(a0, a1);
        case 1494: return fde_func_1494_0x1769d0(a0, a1);
        case 1495: return fde_func_1495_0x176a3c(a0, a1);
        case 1496: return fde_func_1496_0x176a88(a0, a1);
        case 1497: return fde_func_1497_0x176ae8(a0, a1);
        case 1498: return fde_func_1498_0x176b14(a0, a1);
        case 1499: return fde_func_1499_0x176b88(a0, a1);
        case 1500: return fde_func_1500_0x176bbc(a0, a1);
        case 1501: return fde_func_1501_0x176c08(a0, a1);
        case 1502: return fde_func_1502_0x176c80(a0, a1);
        case 1503: return fde_func_1503_0x176cc4(a0, a1);
        case 1504: return fde_func_1504_0x176d24(a0, a1);
        case 1505: return fde_func_1505_0x176d68(a0, a1);
        case 1506: return fde_func_1506_0x176dd0(a0, a1);
        case 1507: return fde_func_1507_0x176e10(a0, a1);
        case 1508: return fde_func_1508_0x176e5c(a0, a1);
        case 1509: return fde_func_1509_0x176ec4(a0, a1);
        case 1510: return fde_func_1510_0x176f40(a0, a1);
        case 1511: return fde_func_1511_0x176fc4(a0, a1);
        case 1512: return fde_func_1512_0x176ff0(a0, a1);
        case 1513: return fde_func_1513_0x177098(a0, a1);
        case 1514: return fde_func_1514_0x1770b8(a0, a1);
        case 1515: return fde_func_1515_0x1770e8(a0, a1);
        case 1516: return fde_func_1516_0x177154(a0, a1);
        case 1517: return fde_func_1517_0x1771c4(a0, a1);
        case 1518: return fde_func_1518_0x177214(a0, a1);
        case 1519: return fde_func_1519_0x17724c(a0, a1);
        case 1520: return fde_func_1520_0x1772b8(a0, a1);
        case 1521: return fde_func_1521_0x177378(a0, a1);
        case 1522: return fde_func_1522_0x1773f4(a0, a1);
        case 1523: return fde_func_1523_0x177434(a0, a1);
        case 1524: return fde_func_1524_0x177468(a0, a1);
        case 1525: return fde_func_1525_0x1774b0(a0, a1);
        case 1526: return fde_func_1526_0x177550(a0, a1);
        case 1527: return fde_func_1527_0x1775a0(a0, a1);
        case 1528: return fde_func_1528_0x1775f4(a0, a1);
        case 1529: return fde_func_1529_0x177648(a0, a1);
        case 1530: return fde_func_1530_0x177698(a0, a1);
        case 1531: return fde_func_1531_0x1776d0(a0, a1);
        case 1532: return fde_func_1532_0x1776f4(a0, a1);
        case 1533: return fde_func_1533_0x177754(a0, a1);
        case 1534: return fde_func_1534_0x17778c(a0, a1);
        case 1535: return fde_func_1535_0x1777cc(a0, a1);
        case 1536: return fde_func_1536_0x177820(a0, a1);
        case 1537: return fde_func_1537_0x17786c(a0, a1);
        case 1538: return fde_func_1538_0x1778ac(a0, a1);
        case 1539: return fde_func_1539_0x1778f0(a0, a1);
        case 1540: return fde_func_1540_0x177934(a0, a1);
        case 1541: return fde_func_1541_0x177980(a0, a1);
        case 1542: return fde_func_1542_0x1779bc(a0, a1);
        case 1543: return fde_func_1543_0x177a0c(a0, a1);
        case 1544: return fde_func_1544_0x177a9c(a0, a1);
        case 1545: return fde_func_1545_0x177ad4(a0, a1);
        case 1546: return fde_func_1546_0x177b34(a0, a1);
        case 1547: return fde_func_1547_0x177b70(a0, a1);
        case 1548: return fde_func_1548_0x177bbc(a0, a1);
        case 1549: return fde_func_1549_0x177be8(a0, a1);
        case 1550: return fde_func_1550_0x177c34(a0, a1);
        case 1551: return fde_func_1551_0x177c5c(a0, a1);
        case 1552: return fde_func_1552_0x177c84(a0, a1);
        case 1553: return fde_func_1553_0x177cb4(a0, a1);
        case 1554: return fde_func_1554_0x177cec(a0, a1);
        case 1555: return fde_func_1555_0x177d34(a0, a1);
        case 1556: return fde_func_1556_0x177d74(a0, a1);
        case 1557: return fde_func_1557_0x177dc8(a0, a1);
        case 1558: return fde_func_1558_0x177dfc(a0, a1);
        case 1559: return fde_func_1559_0x177e2c(a0, a1);
        case 1560: return fde_func_1560_0x177e88(a0, a1);
        case 1561: return fde_func_1561_0x177ec0(a0, a1);
        case 1562: return fde_func_1562_0x177ef8(a0, a1);
        case 1563: return fde_func_1563_0x177f3c(a0, a1);
        case 1564: return fde_func_1564_0x177fcc(a0, a1);
        case 1565: return fde_func_1565_0x178008(a0, a1);
        case 1566: return fde_func_1566_0x178034(a0, a1);
        case 1567: return fde_func_1567_0x178088(a0, a1);
        case 1568: return fde_func_1568_0x178118(a0, a1);
        case 1569: return fde_func_1569_0x178190(a0, a1);
        case 1570: return fde_func_1570_0x1781c4(a0, a1);
        case 1571: return fde_func_1571_0x1781f4(a0, a1);
        case 1572: return fde_func_1572_0x178268(a0, a1);
        case 1573: return fde_func_1573_0x1782c0(a0, a1);
        case 1574: return fde_func_1574_0x1782f4(a0, a1);
        case 1575: return fde_func_1575_0x17832c(a0, a1);
        case 1576: return fde_func_1576_0x178374(a0, a1);
        case 1577: return fde_func_1577_0x1783a0(a0, a1);
        case 1578: return fde_func_1578_0x1783d4(a0, a1);
        case 1579: return fde_func_1579_0x178444(a0, a1);
        case 1580: return fde_func_1580_0x1784b0(a0, a1);
        case 1581: return fde_func_1581_0x178504(a0, a1);
        case 1582: return fde_func_1582_0x178560(a0, a1);
        case 1583: return fde_func_1583_0x1785bc(a0, a1);
        case 1584: return fde_func_1584_0x1785ec(a0, a1);
        case 1585: return fde_func_1585_0x178638(a0, a1);
        case 1586: return fde_func_1586_0x178664(a0, a1);
        case 1587: return fde_func_1587_0x178694(a0, a1);
        case 1588: return fde_func_1588_0x1786e8(a0, a1);
        case 1589: return fde_func_1589_0x178714(a0, a1);
        case 1590: return fde_func_1590_0x178758(a0, a1);
        case 1591: return fde_func_1591_0x178794(a0, a1);
        case 1592: return fde_func_1592_0x1787e4(a0, a1);
        case 1593: return fde_func_1593_0x178854(a0, a1);
        case 1594: return fde_func_1594_0x1788d4(a0, a1);
        case 1595: return fde_func_1595_0x17894c(a0, a1);
        case 1596: return fde_func_1596_0x1789a0(a0, a1);
        case 1597: return fde_func_1597_0x1789dc(a0, a1);
        case 1598: return fde_func_1598_0x178a0c(a0, a1);
        case 1599: return fde_func_1599_0x178a58(a0, a1);
        default: return 0ULL;
    }
}

} // namespace canvas
} // namespace lynx