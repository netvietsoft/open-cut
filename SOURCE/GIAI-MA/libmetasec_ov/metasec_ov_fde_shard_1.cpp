// ============================================================================
// Clean-Room C++17 AArch64 FDE Shard 1/5 for libmetasec_ov.so
// Phân mảnh Khung Tháo Gỡ (FDE) AArch64 C++17 sạch 1/5 cho libmetasec_ov.so
// Covers representative FDE indices [0 .. 399] out of 5,296 total FDEs
// Bao phủ chỉ số FDE đại diện [0 .. 399] trên tổng số 5.296 FDE
// ============================================================================
#include "metasec_ov_core.h"

namespace metasec {
namespace ov {

// FDE #0000 | PC: 0x02ea00 | FDE: 0x195830 | Size: 256 bytes
// Khung tháo gỡ #0000 | Địa chỉ PC: 0x02ea00 | Địa chỉ FDE: 0x195830 | Kích thước: 256 bytes
//   0x02ea00: D104C3FF  sub      sp, sp, #0x130
//   0x02ea04: A90D6FFC  stp      x28, x27, [sp, #0xd0]
//   0x02ea08: A90E67FA  stp      x26, x25, [sp, #0xe0]
//   0x02ea0c: A90F5FF8  stp      x24, x23, [sp, #0xf0]
static inline uint64_t fde_func_0000_0x02ea00(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x02ea00ULL ^ (static_cast<uint64_t>(0xd104c3ffULL) << 13);
    acc = (acc + a1 + 0xa90d6ffcULL) ^ 0x195830ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0001 | PC: 0x02ed30 | FDE: 0x1959e8 | Size: 256 bytes
// Khung tháo gỡ #0001 | Địa chỉ PC: 0x02ed30 | Địa chỉ FDE: 0x1959e8 | Kích thước: 256 bytes
//   0x02ed30: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x02ed34: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x02ed38: 910043FD  add      x29, sp, #0x10
//   0x02ed3c: B0000D73  adrp     x19, #0x1db000
static inline uint64_t fde_func_0001_0x02ed30(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x02ed30ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1959e8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0002 | PC: 0x02ef6c | FDE: 0x195a50 | Size: 256 bytes
// Khung tháo gỡ #0002 | Địa chỉ PC: 0x02ef6c | Địa chỉ FDE: 0x195a50 | Kích thước: 256 bytes
//   0x02ef6c: D10283FF  sub      sp, sp, #0xa0
//   0x02ef70: A9065FF8  stp      x24, x23, [sp, #0x60]
//   0x02ef74: A90757F6  stp      x22, x21, [sp, #0x70]
//   0x02ef78: A9084FF4  stp      x20, x19, [sp, #0x80]
static inline uint64_t fde_func_0002_0x02ef6c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x02ef6cULL ^ (static_cast<uint64_t>(0xd10283ffULL) << 13);
    acc = (acc + a1 + 0xa9065ff8ULL) ^ 0x195a50ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0003 | PC: 0x02f0f0 | FDE: 0x196130 | Size: 256 bytes
// Khung tháo gỡ #0003 | Địa chỉ PC: 0x02f0f0 | Địa chỉ FDE: 0x196130 | Kích thước: 256 bytes
//   0x02f0f0: D104C3FF  sub      sp, sp, #0x130
//   0x02f0f4: A90D6FFC  stp      x28, x27, [sp, #0xd0]
//   0x02f0f8: A90E67FA  stp      x26, x25, [sp, #0xe0]
//   0x02f0fc: A90F5FF8  stp      x24, x23, [sp, #0xf0]
static inline uint64_t fde_func_0003_0x02f0f0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x02f0f0ULL ^ (static_cast<uint64_t>(0xd104c3ffULL) << 13);
    acc = (acc + a1 + 0xa90d6ffcULL) ^ 0x196130ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0004 | PC: 0x02f420 | FDE: 0x1962f8 | Size: 256 bytes
// Khung tháo gỡ #0004 | Địa chỉ PC: 0x02f420 | Địa chỉ FDE: 0x1962f8 | Kích thước: 256 bytes
//   0x02f420: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x02f424: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x02f428: 910043FD  add      x29, sp, #0x10
//   0x02f42c: 90000D73  adrp     x19, #0x1db000
static inline uint64_t fde_func_0004_0x02f420(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x02f420ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1962f8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0005 | PC: 0x02f65c | FDE: 0x196360 | Size: 256 bytes
// Khung tháo gỡ #0005 | Địa chỉ PC: 0x02f65c | Địa chỉ FDE: 0x196360 | Kích thước: 256 bytes
//   0x02f65c: D10283FF  sub      sp, sp, #0xa0
//   0x02f660: A9065FF8  stp      x24, x23, [sp, #0x60]
//   0x02f664: A90757F6  stp      x22, x21, [sp, #0x70]
//   0x02f668: A9084FF4  stp      x20, x19, [sp, #0x80]
static inline uint64_t fde_func_0005_0x02f65c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x02f65cULL ^ (static_cast<uint64_t>(0xd10283ffULL) << 13);
    acc = (acc + a1 + 0xa9065ff8ULL) ^ 0x196360ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0006 | PC: 0x02f7e0 | FDE: 0x196530 | Size: 256 bytes
// Khung tháo gỡ #0006 | Địa chỉ PC: 0x02f7e0 | Địa chỉ FDE: 0x196530 | Kích thước: 256 bytes
//   0x02f7e0: D104C3FF  sub      sp, sp, #0x130
//   0x02f7e4: A90D6FFC  stp      x28, x27, [sp, #0xd0]
//   0x02f7e8: A90E67FA  stp      x26, x25, [sp, #0xe0]
//   0x02f7ec: A90F5FF8  stp      x24, x23, [sp, #0xf0]
static inline uint64_t fde_func_0006_0x02f7e0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x02f7e0ULL ^ (static_cast<uint64_t>(0xd104c3ffULL) << 13);
    acc = (acc + a1 + 0xa90d6ffcULL) ^ 0x196530ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0007 | PC: 0x02fb10 | FDE: 0x197658 | Size: 256 bytes
// Khung tháo gỡ #0007 | Địa chỉ PC: 0x02fb10 | Địa chỉ FDE: 0x197658 | Kích thước: 256 bytes
//   0x02fb10: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x02fb14: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x02fb18: 910043FD  add      x29, sp, #0x10
//   0x02fb1c: 90000D73  adrp     x19, #0x1db000
static inline uint64_t fde_func_0007_0x02fb10(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x02fb10ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x197658ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0008 | PC: 0x02fd4c | FDE: 0x1977f8 | Size: 256 bytes
// Khung tháo gỡ #0008 | Địa chỉ PC: 0x02fd4c | Địa chỉ FDE: 0x1977f8 | Kích thước: 256 bytes
//   0x02fd4c: D10283FF  sub      sp, sp, #0xa0
//   0x02fd50: A9065FF8  stp      x24, x23, [sp, #0x60]
//   0x02fd54: A90757F6  stp      x22, x21, [sp, #0x70]
//   0x02fd58: A9084FF4  stp      x20, x19, [sp, #0x80]
static inline uint64_t fde_func_0008_0x02fd4c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x02fd4cULL ^ (static_cast<uint64_t>(0xd10283ffULL) << 13);
    acc = (acc + a1 + 0xa9065ff8ULL) ^ 0x1977f8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0009 | PC: 0x02fed0 | FDE: 0x1979b8 | Size: 256 bytes
// Khung tháo gỡ #0009 | Địa chỉ PC: 0x02fed0 | Địa chỉ FDE: 0x1979b8 | Kích thước: 256 bytes
//   0x02fed0: D104C3FF  sub      sp, sp, #0x130
//   0x02fed4: A90D6FFC  stp      x28, x27, [sp, #0xd0]
//   0x02fed8: A90E67FA  stp      x26, x25, [sp, #0xe0]
//   0x02fedc: A90F5FF8  stp      x24, x23, [sp, #0xf0]
static inline uint64_t fde_func_0009_0x02fed0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x02fed0ULL ^ (static_cast<uint64_t>(0xd104c3ffULL) << 13);
    acc = (acc + a1 + 0xa90d6ffcULL) ^ 0x1979b8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0010 | PC: 0x030200 | FDE: 0x198248 | Size: 256 bytes
// Khung tháo gỡ #0010 | Địa chỉ PC: 0x030200 | Địa chỉ FDE: 0x198248 | Kích thước: 256 bytes
//   0x030200: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x030204: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x030208: 910043FD  add      x29, sp, #0x10
//   0x03020c: F0000D53  adrp     x19, #0x1db000
static inline uint64_t fde_func_0010_0x030200(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x030200ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x198248ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0011 | PC: 0x03043c | FDE: 0x1982b0 | Size: 256 bytes
// Khung tháo gỡ #0011 | Địa chỉ PC: 0x03043c | Địa chỉ FDE: 0x1982b0 | Kích thước: 256 bytes
//   0x03043c: D10283FF  sub      sp, sp, #0xa0
//   0x030440: A9065FF8  stp      x24, x23, [sp, #0x60]
//   0x030444: A90757F6  stp      x22, x21, [sp, #0x70]
//   0x030448: A9084FF4  stp      x20, x19, [sp, #0x80]
static inline uint64_t fde_func_0011_0x03043c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x03043cULL ^ (static_cast<uint64_t>(0xd10283ffULL) << 13);
    acc = (acc + a1 + 0xa9065ff8ULL) ^ 0x1982b0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0012 | PC: 0x0305c0 | FDE: 0x1984f8 | Size: 256 bytes
// Khung tháo gỡ #0012 | Địa chỉ PC: 0x0305c0 | Địa chỉ FDE: 0x1984f8 | Kích thước: 256 bytes
//   0x0305c0: D104C3FF  sub      sp, sp, #0x130
//   0x0305c4: A90D6FFC  stp      x28, x27, [sp, #0xd0]
//   0x0305c8: A90E67FA  stp      x26, x25, [sp, #0xe0]
//   0x0305cc: A90F5FF8  stp      x24, x23, [sp, #0xf0]
static inline uint64_t fde_func_0012_0x0305c0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0305c0ULL ^ (static_cast<uint64_t>(0xd104c3ffULL) << 13);
    acc = (acc + a1 + 0xa90d6ffcULL) ^ 0x1984f8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0013 | PC: 0x0308f0 | FDE: 0x1986b8 | Size: 144 bytes
// Khung tháo gỡ #0013 | Địa chỉ PC: 0x0308f0 | Địa chỉ FDE: 0x1986b8 | Kích thước: 144 bytes
//   0x0308f0: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x0308f4: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0308f8: 910043FD  add      x29, sp, #0x10
//   0x0308fc: F0000D53  adrp     x19, #0x1db000
static inline uint64_t fde_func_0013_0x0308f0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0308f0ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1986b8ULL;
    acc ^= (acc >> 17) * 0x0090ULL;
    return acc;
}

// FDE #0014 | PC: 0x030980 | FDE: 0x1987a0 | Size: 256 bytes
// Khung tháo gỡ #0014 | Địa chỉ PC: 0x030980 | Địa chỉ FDE: 0x1987a0 | Kích thước: 256 bytes
//   0x030980: D104C3FF  sub      sp, sp, #0x130
//   0x030984: A90D6FFC  stp      x28, x27, [sp, #0xd0]
//   0x030988: A90E67FA  stp      x26, x25, [sp, #0xe0]
//   0x03098c: A90F5FF8  stp      x24, x23, [sp, #0xf0]
static inline uint64_t fde_func_0014_0x030980(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x030980ULL ^ (static_cast<uint64_t>(0xd104c3ffULL) << 13);
    acc = (acc + a1 + 0xa90d6ffcULL) ^ 0x1987a0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0015 | PC: 0x030cb0 | FDE: 0x198908 | Size: 144 bytes
// Khung tháo gỡ #0015 | Địa chỉ PC: 0x030cb0 | Địa chỉ FDE: 0x198908 | Kích thước: 144 bytes
//   0x030cb0: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x030cb4: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x030cb8: 910043FD  add      x29, sp, #0x10
//   0x030cbc: F0000D53  adrp     x19, #0x1db000
static inline uint64_t fde_func_0015_0x030cb0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x030cb0ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x198908ULL;
    acc ^= (acc >> 17) * 0x0090ULL;
    return acc;
}

// FDE #0016 | PC: 0x030d40 | FDE: 0x1990e0 | Size: 256 bytes
// Khung tháo gỡ #0016 | Địa chỉ PC: 0x030d40 | Địa chỉ FDE: 0x1990e0 | Kích thước: 256 bytes
//   0x030d40: D104C3FF  sub      sp, sp, #0x130
//   0x030d44: A90D6FFC  stp      x28, x27, [sp, #0xd0]
//   0x030d48: A90E67FA  stp      x26, x25, [sp, #0xe0]
//   0x030d4c: A90F5FF8  stp      x24, x23, [sp, #0xf0]
static inline uint64_t fde_func_0016_0x030d40(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x030d40ULL ^ (static_cast<uint64_t>(0xd104c3ffULL) << 13);
    acc = (acc + a1 + 0xa90d6ffcULL) ^ 0x1990e0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0017 | PC: 0x031070 | FDE: 0x199208 | Size: 256 bytes
// Khung tháo gỡ #0017 | Địa chỉ PC: 0x031070 | Địa chỉ FDE: 0x199208 | Kích thước: 256 bytes
//   0x031070: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x031074: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x031078: 910043FD  add      x29, sp, #0x10
//   0x03107c: D0000D53  adrp     x19, #0x1db000
static inline uint64_t fde_func_0017_0x031070(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x031070ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x199208ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0018 | PC: 0x0312ac | FDE: 0x199270 | Size: 256 bytes
// Khung tháo gỡ #0018 | Địa chỉ PC: 0x0312ac | Địa chỉ FDE: 0x199270 | Kích thước: 256 bytes
//   0x0312ac: D10283FF  sub      sp, sp, #0xa0
//   0x0312b0: A9065FF8  stp      x24, x23, [sp, #0x60]
//   0x0312b4: A90757F6  stp      x22, x21, [sp, #0x70]
//   0x0312b8: A9084FF4  stp      x20, x19, [sp, #0x80]
static inline uint64_t fde_func_0018_0x0312ac(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0312acULL ^ (static_cast<uint64_t>(0xd10283ffULL) << 13);
    acc = (acc + a1 + 0xa9065ff8ULL) ^ 0x199270ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0019 | PC: 0x031430 | FDE: 0x199320 | Size: 256 bytes
// Khung tháo gỡ #0019 | Địa chỉ PC: 0x031430 | Địa chỉ FDE: 0x199320 | Kích thước: 256 bytes
//   0x031430: D104C3FF  sub      sp, sp, #0x130
//   0x031434: A90D6FFC  stp      x28, x27, [sp, #0xd0]
//   0x031438: A90E67FA  stp      x26, x25, [sp, #0xe0]
//   0x03143c: A90F5FF8  stp      x24, x23, [sp, #0xf0]
static inline uint64_t fde_func_0019_0x031430(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x031430ULL ^ (static_cast<uint64_t>(0xd104c3ffULL) << 13);
    acc = (acc + a1 + 0xa90d6ffcULL) ^ 0x199320ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0020 | PC: 0x031760 | FDE: 0x199670 | Size: 256 bytes
// Khung tháo gỡ #0020 | Địa chỉ PC: 0x031760 | Địa chỉ FDE: 0x199670 | Kích thước: 256 bytes
//   0x031760: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x031764: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x031768: 910043FD  add      x29, sp, #0x10
//   0x03176c: D0000D53  adrp     x19, #0x1db000
static inline uint64_t fde_func_0020_0x031760(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x031760ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x199670ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0021 | PC: 0x03199c | FDE: 0x1996d8 | Size: 256 bytes
// Khung tháo gỡ #0021 | Địa chỉ PC: 0x03199c | Địa chỉ FDE: 0x1996d8 | Kích thước: 256 bytes
//   0x03199c: D10283FF  sub      sp, sp, #0xa0
//   0x0319a0: A9065FF8  stp      x24, x23, [sp, #0x60]
//   0x0319a4: A90757F6  stp      x22, x21, [sp, #0x70]
//   0x0319a8: A9084FF4  stp      x20, x19, [sp, #0x80]
static inline uint64_t fde_func_0021_0x03199c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x03199cULL ^ (static_cast<uint64_t>(0xd10283ffULL) << 13);
    acc = (acc + a1 + 0xa9065ff8ULL) ^ 0x1996d8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0022 | PC: 0x031b50 | FDE: 0x199b90 | Size: 256 bytes
// Khung tháo gỡ #0022 | Địa chỉ PC: 0x031b50 | Địa chỉ FDE: 0x199b90 | Kích thước: 256 bytes
//   0x031b50: D104C3FF  sub      sp, sp, #0x130
//   0x031b54: A90D6FFC  stp      x28, x27, [sp, #0xd0]
//   0x031b58: A90E67FA  stp      x26, x25, [sp, #0xe0]
//   0x031b5c: A90F5FF8  stp      x24, x23, [sp, #0xf0]
static inline uint64_t fde_func_0022_0x031b50(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x031b50ULL ^ (static_cast<uint64_t>(0xd104c3ffULL) << 13);
    acc = (acc + a1 + 0xa90d6ffcULL) ^ 0x199b90ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0023 | PC: 0x031e80 | FDE: 0x199d20 | Size: 256 bytes
// Khung tháo gỡ #0023 | Địa chỉ PC: 0x031e80 | Địa chỉ FDE: 0x199d20 | Kích thước: 256 bytes
//   0x031e80: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x031e84: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x031e88: 910043FD  add      x29, sp, #0x10
//   0x031e8c: D0000D53  adrp     x19, #0x1db000
static inline uint64_t fde_func_0023_0x031e80(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x031e80ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x199d20ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0024 | PC: 0x0320bc | FDE: 0x199d88 | Size: 256 bytes
// Khung tháo gỡ #0024 | Địa chỉ PC: 0x0320bc | Địa chỉ FDE: 0x199d88 | Kích thước: 256 bytes
//   0x0320bc: D10283FF  sub      sp, sp, #0xa0
//   0x0320c0: A9065FF8  stp      x24, x23, [sp, #0x60]
//   0x0320c4: A90757F6  stp      x22, x21, [sp, #0x70]
//   0x0320c8: A9084FF4  stp      x20, x19, [sp, #0x80]
static inline uint64_t fde_func_0024_0x0320bc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0320bcULL ^ (static_cast<uint64_t>(0xd10283ffULL) << 13);
    acc = (acc + a1 + 0xa9065ff8ULL) ^ 0x199d88ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0025 | PC: 0x032240 | FDE: 0x199f18 | Size: 256 bytes
// Khung tháo gỡ #0025 | Địa chỉ PC: 0x032240 | Địa chỉ FDE: 0x199f18 | Kích thước: 256 bytes
//   0x032240: D104C3FF  sub      sp, sp, #0x130
//   0x032244: A90D6FFC  stp      x28, x27, [sp, #0xd0]
//   0x032248: A90E67FA  stp      x26, x25, [sp, #0xe0]
//   0x03224c: A90F5FF8  stp      x24, x23, [sp, #0xf0]
static inline uint64_t fde_func_0025_0x032240(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x032240ULL ^ (static_cast<uint64_t>(0xd104c3ffULL) << 13);
    acc = (acc + a1 + 0xa90d6ffcULL) ^ 0x199f18ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0026 | PC: 0x032570 | FDE: 0x19a5d0 | Size: 256 bytes
// Khung tháo gỡ #0026 | Địa chỉ PC: 0x032570 | Địa chỉ FDE: 0x19a5d0 | Kích thước: 256 bytes
//   0x032570: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x032574: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x032578: 910043FD  add      x29, sp, #0x10
//   0x03257c: D0000D53  adrp     x19, #0x1dc000
static inline uint64_t fde_func_0026_0x032570(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x032570ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x19a5d0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0027 | PC: 0x0327ac | FDE: 0x19a638 | Size: 256 bytes
// Khung tháo gỡ #0027 | Địa chỉ PC: 0x0327ac | Địa chỉ FDE: 0x19a638 | Kích thước: 256 bytes
//   0x0327ac: D10283FF  sub      sp, sp, #0xa0
//   0x0327b0: A9065FF8  stp      x24, x23, [sp, #0x60]
//   0x0327b4: A90757F6  stp      x22, x21, [sp, #0x70]
//   0x0327b8: A9084FF4  stp      x20, x19, [sp, #0x80]
static inline uint64_t fde_func_0027_0x0327ac(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0327acULL ^ (static_cast<uint64_t>(0xd10283ffULL) << 13);
    acc = (acc + a1 + 0xa9065ff8ULL) ^ 0x19a638ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0028 | PC: 0x032930 | FDE: 0x19aae0 | Size: 256 bytes
// Khung tháo gỡ #0028 | Địa chỉ PC: 0x032930 | Địa chỉ FDE: 0x19aae0 | Kích thước: 256 bytes
//   0x032930: D104C3FF  sub      sp, sp, #0x130
//   0x032934: A90D6FFC  stp      x28, x27, [sp, #0xd0]
//   0x032938: A90E67FA  stp      x26, x25, [sp, #0xe0]
//   0x03293c: A90F5FF8  stp      x24, x23, [sp, #0xf0]
static inline uint64_t fde_func_0028_0x032930(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x032930ULL ^ (static_cast<uint64_t>(0xd104c3ffULL) << 13);
    acc = (acc + a1 + 0xa90d6ffcULL) ^ 0x19aae0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0029 | PC: 0x032c60 | FDE: 0x19b0e8 | Size: 256 bytes
// Khung tháo gỡ #0029 | Địa chỉ PC: 0x032c60 | Địa chỉ FDE: 0x19b0e8 | Kích thước: 256 bytes
//   0x032c60: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x032c64: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x032c68: 910043FD  add      x29, sp, #0x10
//   0x032c6c: D0000D53  adrp     x19, #0x1dc000
static inline uint64_t fde_func_0029_0x032c60(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x032c60ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x19b0e8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0030 | PC: 0x032e9c | FDE: 0x19b480 | Size: 256 bytes
// Khung tháo gỡ #0030 | Địa chỉ PC: 0x032e9c | Địa chỉ FDE: 0x19b480 | Kích thước: 256 bytes
//   0x032e9c: D10283FF  sub      sp, sp, #0xa0
//   0x032ea0: A9065FF8  stp      x24, x23, [sp, #0x60]
//   0x032ea4: A90757F6  stp      x22, x21, [sp, #0x70]
//   0x032ea8: A9084FF4  stp      x20, x19, [sp, #0x80]
static inline uint64_t fde_func_0030_0x032e9c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x032e9cULL ^ (static_cast<uint64_t>(0xd10283ffULL) << 13);
    acc = (acc + a1 + 0xa9065ff8ULL) ^ 0x19b480ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0031 | PC: 0x033088 | FDE: 0x19b650 | Size: 256 bytes
// Khung tháo gỡ #0031 | Địa chỉ PC: 0x033088 | Địa chỉ FDE: 0x19b650 | Kích thước: 256 bytes
//   0x033088: D104C3FF  sub      sp, sp, #0x130
//   0x03308c: A90D6FFC  stp      x28, x27, [sp, #0xd0]
//   0x033090: A90E67FA  stp      x26, x25, [sp, #0xe0]
//   0x033094: A90F5FF8  stp      x24, x23, [sp, #0xf0]
static inline uint64_t fde_func_0031_0x033088(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x033088ULL ^ (static_cast<uint64_t>(0xd104c3ffULL) << 13);
    acc = (acc + a1 + 0xa90d6ffcULL) ^ 0x19b650ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0032 | PC: 0x0333b8 | FDE: 0x19b8b8 | Size: 256 bytes
// Khung tháo gỡ #0032 | Địa chỉ PC: 0x0333b8 | Địa chỉ FDE: 0x19b8b8 | Kích thước: 256 bytes
//   0x0333b8: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x0333bc: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0333c0: 910043FD  add      x29, sp, #0x10
//   0x0333c4: B0000D53  adrp     x19, #0x1dc000
static inline uint64_t fde_func_0032_0x0333b8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0333b8ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x19b8b8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0033 | PC: 0x0335f4 | FDE: 0x19b920 | Size: 256 bytes
// Khung tháo gỡ #0033 | Địa chỉ PC: 0x0335f4 | Địa chỉ FDE: 0x19b920 | Kích thước: 256 bytes
//   0x0335f4: D10283FF  sub      sp, sp, #0xa0
//   0x0335f8: A9065FF8  stp      x24, x23, [sp, #0x60]
//   0x0335fc: A90757F6  stp      x22, x21, [sp, #0x70]
//   0x033600: A9084FF4  stp      x20, x19, [sp, #0x80]
static inline uint64_t fde_func_0033_0x0335f4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0335f4ULL ^ (static_cast<uint64_t>(0xd10283ffULL) << 13);
    acc = (acc + a1 + 0xa9065ff8ULL) ^ 0x19b920ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0034 | PC: 0x033778 | FDE: 0x19ba90 | Size: 256 bytes
// Khung tháo gỡ #0034 | Địa chỉ PC: 0x033778 | Địa chỉ FDE: 0x19ba90 | Kích thước: 256 bytes
//   0x033778: D104C3FF  sub      sp, sp, #0x130
//   0x03377c: A90D6FFC  stp      x28, x27, [sp, #0xd0]
//   0x033780: A90E67FA  stp      x26, x25, [sp, #0xe0]
//   0x033784: A90F5FF8  stp      x24, x23, [sp, #0xf0]
static inline uint64_t fde_func_0034_0x033778(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x033778ULL ^ (static_cast<uint64_t>(0xd104c3ffULL) << 13);
    acc = (acc + a1 + 0xa90d6ffcULL) ^ 0x19ba90ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0035 | PC: 0x033aa8 | FDE: 0x19bb38 | Size: 256 bytes
// Khung tháo gỡ #0035 | Địa chỉ PC: 0x033aa8 | Địa chỉ FDE: 0x19bb38 | Kích thước: 256 bytes
//   0x033aa8: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x033aac: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x033ab0: 910043FD  add      x29, sp, #0x10
//   0x033ab4: B0000D53  adrp     x19, #0x1dc000
static inline uint64_t fde_func_0035_0x033aa8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x033aa8ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x19bb38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0036 | PC: 0x033ce4 | FDE: 0x19bba0 | Size: 256 bytes
// Khung tháo gỡ #0036 | Địa chỉ PC: 0x033ce4 | Địa chỉ FDE: 0x19bba0 | Kích thước: 256 bytes
//   0x033ce4: D10283FF  sub      sp, sp, #0xa0
//   0x033ce8: A9065FF8  stp      x24, x23, [sp, #0x60]
//   0x033cec: A90757F6  stp      x22, x21, [sp, #0x70]
//   0x033cf0: A9084FF4  stp      x20, x19, [sp, #0x80]
static inline uint64_t fde_func_0036_0x033ce4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x033ce4ULL ^ (static_cast<uint64_t>(0xd10283ffULL) << 13);
    acc = (acc + a1 + 0xa9065ff8ULL) ^ 0x19bba0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0037 | PC: 0x033f28 | FDE: 0x19c2b8 | Size: 256 bytes
// Khung tháo gỡ #0037 | Địa chỉ PC: 0x033f28 | Địa chỉ FDE: 0x19c2b8 | Kích thước: 256 bytes
//   0x033f28: D104C3FF  sub      sp, sp, #0x130
//   0x033f2c: A90D6FFC  stp      x28, x27, [sp, #0xd0]
//   0x033f30: A90E67FA  stp      x26, x25, [sp, #0xe0]
//   0x033f34: A90F5FF8  stp      x24, x23, [sp, #0xf0]
static inline uint64_t fde_func_0037_0x033f28(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x033f28ULL ^ (static_cast<uint64_t>(0xd104c3ffULL) << 13);
    acc = (acc + a1 + 0xa90d6ffcULL) ^ 0x19c2b8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0038 | PC: 0x034258 | FDE: 0x19cb30 | Size: 256 bytes
// Khung tháo gỡ #0038 | Địa chỉ PC: 0x034258 | Địa chỉ FDE: 0x19cb30 | Kích thước: 256 bytes
//   0x034258: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x03425c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x034260: 910043FD  add      x29, sp, #0x10
//   0x034264: 90000D53  adrp     x19, #0x1dc000
static inline uint64_t fde_func_0038_0x034258(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x034258ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x19cb30ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0039 | PC: 0x034494 | FDE: 0x19d6f0 | Size: 256 bytes
// Khung tháo gỡ #0039 | Địa chỉ PC: 0x034494 | Địa chỉ FDE: 0x19d6f0 | Kích thước: 256 bytes
//   0x034494: D10283FF  sub      sp, sp, #0xa0
//   0x034498: A9065FF8  stp      x24, x23, [sp, #0x60]
//   0x03449c: A90757F6  stp      x22, x21, [sp, #0x70]
//   0x0344a0: A9084FF4  stp      x20, x19, [sp, #0x80]
static inline uint64_t fde_func_0039_0x034494(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x034494ULL ^ (static_cast<uint64_t>(0xd10283ffULL) << 13);
    acc = (acc + a1 + 0xa9065ff8ULL) ^ 0x19d6f0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0040 | PC: 0x034618 | FDE: 0x19d9d0 | Size: 256 bytes
// Khung tháo gỡ #0040 | Địa chỉ PC: 0x034618 | Địa chỉ FDE: 0x19d9d0 | Kích thước: 256 bytes
//   0x034618: D104C3FF  sub      sp, sp, #0x130
//   0x03461c: A90D6FFC  stp      x28, x27, [sp, #0xd0]
//   0x034620: A90E67FA  stp      x26, x25, [sp, #0xe0]
//   0x034624: A90F5FF8  stp      x24, x23, [sp, #0xf0]
static inline uint64_t fde_func_0040_0x034618(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x034618ULL ^ (static_cast<uint64_t>(0xd104c3ffULL) << 13);
    acc = (acc + a1 + 0xa90d6ffcULL) ^ 0x19d9d0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0041 | PC: 0x034948 | FDE: 0x19da70 | Size: 256 bytes
// Khung tháo gỡ #0041 | Địa chỉ PC: 0x034948 | Địa chỉ FDE: 0x19da70 | Kích thước: 256 bytes
//   0x034948: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x03494c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x034950: 910043FD  add      x29, sp, #0x10
//   0x034954: 90000D53  adrp     x19, #0x1dc000
static inline uint64_t fde_func_0041_0x034948(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x034948ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x19da70ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0042 | PC: 0x034b84 | FDE: 0x19dad8 | Size: 256 bytes
// Khung tháo gỡ #0042 | Địa chỉ PC: 0x034b84 | Địa chỉ FDE: 0x19dad8 | Kích thước: 256 bytes
//   0x034b84: D10283FF  sub      sp, sp, #0xa0
//   0x034b88: A9065FF8  stp      x24, x23, [sp, #0x60]
//   0x034b8c: A90757F6  stp      x22, x21, [sp, #0x70]
//   0x034b90: A9084FF4  stp      x20, x19, [sp, #0x80]
static inline uint64_t fde_func_0042_0x034b84(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x034b84ULL ^ (static_cast<uint64_t>(0xd10283ffULL) << 13);
    acc = (acc + a1 + 0xa9065ff8ULL) ^ 0x19dad8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0043 | PC: 0x034d08 | FDE: 0x19dcb0 | Size: 256 bytes
// Khung tháo gỡ #0043 | Địa chỉ PC: 0x034d08 | Địa chỉ FDE: 0x19dcb0 | Kích thước: 256 bytes
//   0x034d08: D104C3FF  sub      sp, sp, #0x130
//   0x034d0c: A90D6FFC  stp      x28, x27, [sp, #0xd0]
//   0x034d10: A90E67FA  stp      x26, x25, [sp, #0xe0]
//   0x034d14: A90F5FF8  stp      x24, x23, [sp, #0xf0]
static inline uint64_t fde_func_0043_0x034d08(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x034d08ULL ^ (static_cast<uint64_t>(0xd104c3ffULL) << 13);
    acc = (acc + a1 + 0xa90d6ffcULL) ^ 0x19dcb0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0044 | PC: 0x035038 | FDE: 0x19dfa0 | Size: 256 bytes
// Khung tháo gỡ #0044 | Địa chỉ PC: 0x035038 | Địa chỉ FDE: 0x19dfa0 | Kích thước: 256 bytes
//   0x035038: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x03503c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x035040: 910043FD  add      x29, sp, #0x10
//   0x035044: F0000D33  adrp     x19, #0x1dc000
static inline uint64_t fde_func_0044_0x035038(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x035038ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x19dfa0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0045 | PC: 0x035274 | FDE: 0x19e008 | Size: 256 bytes
// Khung tháo gỡ #0045 | Địa chỉ PC: 0x035274 | Địa chỉ FDE: 0x19e008 | Kích thước: 256 bytes
//   0x035274: D10283FF  sub      sp, sp, #0xa0
//   0x035278: A9065FF8  stp      x24, x23, [sp, #0x60]
//   0x03527c: A90757F6  stp      x22, x21, [sp, #0x70]
//   0x035280: A9084FF4  stp      x20, x19, [sp, #0x80]
static inline uint64_t fde_func_0045_0x035274(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x035274ULL ^ (static_cast<uint64_t>(0xd10283ffULL) << 13);
    acc = (acc + a1 + 0xa9065ff8ULL) ^ 0x19e008ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0046 | PC: 0x0353f8 | FDE: 0x19e2a8 | Size: 256 bytes
// Khung tháo gỡ #0046 | Địa chỉ PC: 0x0353f8 | Địa chỉ FDE: 0x19e2a8 | Kích thước: 256 bytes
//   0x0353f8: D104C3FF  sub      sp, sp, #0x130
//   0x0353fc: A90D6FFC  stp      x28, x27, [sp, #0xd0]
//   0x035400: A90E67FA  stp      x26, x25, [sp, #0xe0]
//   0x035404: A90F5FF8  stp      x24, x23, [sp, #0xf0]
static inline uint64_t fde_func_0046_0x0353f8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0353f8ULL ^ (static_cast<uint64_t>(0xd104c3ffULL) << 13);
    acc = (acc + a1 + 0xa90d6ffcULL) ^ 0x19e2a8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0047 | PC: 0x035728 | FDE: 0x19e480 | Size: 256 bytes
// Khung tháo gỡ #0047 | Địa chỉ PC: 0x035728 | Địa chỉ FDE: 0x19e480 | Kích thước: 256 bytes
//   0x035728: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x03572c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x035730: 910043FD  add      x29, sp, #0x10
//   0x035734: F0000D33  adrp     x19, #0x1dc000
static inline uint64_t fde_func_0047_0x035728(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x035728ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x19e480ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0048 | PC: 0x035964 | FDE: 0x19e4d0 | Size: 256 bytes
// Khung tháo gỡ #0048 | Địa chỉ PC: 0x035964 | Địa chỉ FDE: 0x19e4d0 | Kích thước: 256 bytes
//   0x035964: D10283FF  sub      sp, sp, #0xa0
//   0x035968: A9065FF8  stp      x24, x23, [sp, #0x60]
//   0x03596c: A90757F6  stp      x22, x21, [sp, #0x70]
//   0x035970: A9084FF4  stp      x20, x19, [sp, #0x80]
static inline uint64_t fde_func_0048_0x035964(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x035964ULL ^ (static_cast<uint64_t>(0xd10283ffULL) << 13);
    acc = (acc + a1 + 0xa9065ff8ULL) ^ 0x19e4d0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0049 | PC: 0x035ae8 | FDE: 0x19e640 | Size: 256 bytes
// Khung tháo gỡ #0049 | Địa chỉ PC: 0x035ae8 | Địa chỉ FDE: 0x19e640 | Kích thước: 256 bytes
//   0x035ae8: D104C3FF  sub      sp, sp, #0x130
//   0x035aec: A90D6FFC  stp      x28, x27, [sp, #0xd0]
//   0x035af0: A90E67FA  stp      x26, x25, [sp, #0xe0]
//   0x035af4: A90F5FF8  stp      x24, x23, [sp, #0xf0]
static inline uint64_t fde_func_0049_0x035ae8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x035ae8ULL ^ (static_cast<uint64_t>(0xd104c3ffULL) << 13);
    acc = (acc + a1 + 0xa90d6ffcULL) ^ 0x19e640ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0050 | PC: 0x035e18 | FDE: 0x19e8a0 | Size: 256 bytes
// Khung tháo gỡ #0050 | Địa chỉ PC: 0x035e18 | Địa chỉ FDE: 0x19e8a0 | Kích thước: 256 bytes
//   0x035e18: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x035e1c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x035e20: 910043FD  add      x29, sp, #0x10
//   0x035e24: F0000D33  adrp     x19, #0x1dc000
static inline uint64_t fde_func_0050_0x035e18(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x035e18ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x19e8a0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0051 | PC: 0x036054 | FDE: 0x19e8f0 | Size: 256 bytes
// Khung tháo gỡ #0051 | Địa chỉ PC: 0x036054 | Địa chỉ FDE: 0x19e8f0 | Kích thước: 256 bytes
//   0x036054: D10283FF  sub      sp, sp, #0xa0
//   0x036058: A9065FF8  stp      x24, x23, [sp, #0x60]
//   0x03605c: A90757F6  stp      x22, x21, [sp, #0x70]
//   0x036060: A9084FF4  stp      x20, x19, [sp, #0x80]
static inline uint64_t fde_func_0051_0x036054(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x036054ULL ^ (static_cast<uint64_t>(0xd10283ffULL) << 13);
    acc = (acc + a1 + 0xa9065ff8ULL) ^ 0x19e8f0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0052 | PC: 0x0361d8 | FDE: 0x19ea40 | Size: 256 bytes
// Khung tháo gỡ #0052 | Địa chỉ PC: 0x0361d8 | Địa chỉ FDE: 0x19ea40 | Kích thước: 256 bytes
//   0x0361d8: D104C3FF  sub      sp, sp, #0x130
//   0x0361dc: A90D6FFC  stp      x28, x27, [sp, #0xd0]
//   0x0361e0: A90E67FA  stp      x26, x25, [sp, #0xe0]
//   0x0361e4: A90F5FF8  stp      x24, x23, [sp, #0xf0]
static inline uint64_t fde_func_0052_0x0361d8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0361d8ULL ^ (static_cast<uint64_t>(0xd104c3ffULL) << 13);
    acc = (acc + a1 + 0xa90d6ffcULL) ^ 0x19ea40ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0053 | PC: 0x036508 | FDE: 0x19eca8 | Size: 116 bytes
// Khung tháo gỡ #0053 | Địa chỉ PC: 0x036508 | Địa chỉ FDE: 0x19eca8 | Kích thước: 116 bytes
//   0x036508: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x03650c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x036510: 910043FD  add      x29, sp, #0x10
//   0x036514: D0000D33  adrp     x19, #0x1dc000
static inline uint64_t fde_func_0053_0x036508(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x036508ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x19eca8ULL;
    acc ^= (acc >> 17) * 0x0074ULL;
    return acc;
}

// FDE #0054 | PC: 0x03657c | FDE: 0x19ed08 | Size: 256 bytes
// Khung tháo gỡ #0054 | Địa chỉ PC: 0x03657c | Địa chỉ FDE: 0x19ed08 | Kích thước: 256 bytes
//   0x03657c: D104C3FF  sub      sp, sp, #0x130
//   0x036580: A90D6FFC  stp      x28, x27, [sp, #0xd0]
//   0x036584: A90E67FA  stp      x26, x25, [sp, #0xe0]
//   0x036588: A90F5FF8  stp      x24, x23, [sp, #0xf0]
static inline uint64_t fde_func_0054_0x03657c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x03657cULL ^ (static_cast<uint64_t>(0xd104c3ffULL) << 13);
    acc = (acc + a1 + 0xa90d6ffcULL) ^ 0x19ed08ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0055 | PC: 0x0368ac | FDE: 0x19eef8 | Size: 144 bytes
// Khung tháo gỡ #0055 | Địa chỉ PC: 0x0368ac | Địa chỉ FDE: 0x19eef8 | Kích thước: 144 bytes
//   0x0368ac: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x0368b0: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0368b4: 910043FD  add      x29, sp, #0x10
//   0x0368b8: D0000D33  adrp     x19, #0x1dc000
static inline uint64_t fde_func_0055_0x0368ac(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0368acULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x19eef8ULL;
    acc ^= (acc >> 17) * 0x0090ULL;
    return acc;
}

// FDE #0056 | PC: 0x03693c | FDE: 0x19ef78 | Size: 256 bytes
// Khung tháo gỡ #0056 | Địa chỉ PC: 0x03693c | Địa chỉ FDE: 0x19ef78 | Kích thước: 256 bytes
//   0x03693c: D104C3FF  sub      sp, sp, #0x130
//   0x036940: A90D6FFC  stp      x28, x27, [sp, #0xd0]
//   0x036944: A90E67FA  stp      x26, x25, [sp, #0xe0]
//   0x036948: A90F5FF8  stp      x24, x23, [sp, #0xf0]
static inline uint64_t fde_func_0056_0x03693c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x03693cULL ^ (static_cast<uint64_t>(0xd104c3ffULL) << 13);
    acc = (acc + a1 + 0xa90d6ffcULL) ^ 0x19ef78ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0057 | PC: 0x036c6c | FDE: 0x19f178 | Size: 256 bytes
// Khung tháo gỡ #0057 | Địa chỉ PC: 0x036c6c | Địa chỉ FDE: 0x19f178 | Kích thước: 256 bytes
//   0x036c6c: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x036c70: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x036c74: 910043FD  add      x29, sp, #0x10
//   0x036c78: D0000D33  adrp     x19, #0x1dc000
static inline uint64_t fde_func_0057_0x036c6c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x036c6cULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x19f178ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0058 | PC: 0x036ea8 | FDE: 0x19f1e0 | Size: 256 bytes
// Khung tháo gỡ #0058 | Địa chỉ PC: 0x036ea8 | Địa chỉ FDE: 0x19f1e0 | Kích thước: 256 bytes
//   0x036ea8: D10283FF  sub      sp, sp, #0xa0
//   0x036eac: A9065FF8  stp      x24, x23, [sp, #0x60]
//   0x036eb0: A90757F6  stp      x22, x21, [sp, #0x70]
//   0x036eb4: A9084FF4  stp      x20, x19, [sp, #0x80]
static inline uint64_t fde_func_0058_0x036ea8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x036ea8ULL ^ (static_cast<uint64_t>(0xd10283ffULL) << 13);
    acc = (acc + a1 + 0xa9065ff8ULL) ^ 0x19f1e0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0059 | PC: 0x03702c | FDE: 0x19f298 | Size: 256 bytes
// Khung tháo gỡ #0059 | Địa chỉ PC: 0x03702c | Địa chỉ FDE: 0x19f298 | Kích thước: 256 bytes
//   0x03702c: D104C3FF  sub      sp, sp, #0x130
//   0x037030: A90D6FFC  stp      x28, x27, [sp, #0xd0]
//   0x037034: A90E67FA  stp      x26, x25, [sp, #0xe0]
//   0x037038: A90F5FF8  stp      x24, x23, [sp, #0xf0]
static inline uint64_t fde_func_0059_0x03702c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x03702cULL ^ (static_cast<uint64_t>(0xd104c3ffULL) << 13);
    acc = (acc + a1 + 0xa90d6ffcULL) ^ 0x19f298ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0060 | PC: 0x03735c | FDE: 0x19f318 | Size: 256 bytes
// Khung tháo gỡ #0060 | Địa chỉ PC: 0x03735c | Địa chỉ FDE: 0x19f318 | Kích thước: 256 bytes
//   0x03735c: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x037360: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x037364: 910043FD  add      x29, sp, #0x10
//   0x037368: B0000D33  adrp     x19, #0x1dc000
static inline uint64_t fde_func_0060_0x03735c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x03735cULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x19f318ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0061 | PC: 0x037598 | FDE: 0x19f380 | Size: 256 bytes
// Khung tháo gỡ #0061 | Địa chỉ PC: 0x037598 | Địa chỉ FDE: 0x19f380 | Kích thước: 256 bytes
//   0x037598: D10283FF  sub      sp, sp, #0xa0
//   0x03759c: A9065FF8  stp      x24, x23, [sp, #0x60]
//   0x0375a0: A90757F6  stp      x22, x21, [sp, #0x70]
//   0x0375a4: A9084FF4  stp      x20, x19, [sp, #0x80]
static inline uint64_t fde_func_0061_0x037598(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x037598ULL ^ (static_cast<uint64_t>(0xd10283ffULL) << 13);
    acc = (acc + a1 + 0xa9065ff8ULL) ^ 0x19f380ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0062 | PC: 0x03771c | FDE: 0x19f610 | Size: 256 bytes
// Khung tháo gỡ #0062 | Địa chỉ PC: 0x03771c | Địa chỉ FDE: 0x19f610 | Kích thước: 256 bytes
//   0x03771c: D104C3FF  sub      sp, sp, #0x130
//   0x037720: A90D6FFC  stp      x28, x27, [sp, #0xd0]
//   0x037724: A90E67FA  stp      x26, x25, [sp, #0xe0]
//   0x037728: A90F5FF8  stp      x24, x23, [sp, #0xf0]
static inline uint64_t fde_func_0062_0x03771c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x03771cULL ^ (static_cast<uint64_t>(0xd104c3ffULL) << 13);
    acc = (acc + a1 + 0xa90d6ffcULL) ^ 0x19f610ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0063 | PC: 0x037a4c | FDE: 0x19f6f8 | Size: 256 bytes
// Khung tháo gỡ #0063 | Địa chỉ PC: 0x037a4c | Địa chỉ FDE: 0x19f6f8 | Kích thước: 256 bytes
//   0x037a4c: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x037a50: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x037a54: 910043FD  add      x29, sp, #0x10
//   0x037a58: B0000D33  adrp     x19, #0x1dc000
static inline uint64_t fde_func_0063_0x037a4c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x037a4cULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x19f6f8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0064 | PC: 0x037c88 | FDE: 0x19f760 | Size: 256 bytes
// Khung tháo gỡ #0064 | Địa chỉ PC: 0x037c88 | Địa chỉ FDE: 0x19f760 | Kích thước: 256 bytes
//   0x037c88: D10283FF  sub      sp, sp, #0xa0
//   0x037c8c: A9065FF8  stp      x24, x23, [sp, #0x60]
//   0x037c90: A90757F6  stp      x22, x21, [sp, #0x70]
//   0x037c94: A9084FF4  stp      x20, x19, [sp, #0x80]
static inline uint64_t fde_func_0064_0x037c88(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x037c88ULL ^ (static_cast<uint64_t>(0xd10283ffULL) << 13);
    acc = (acc + a1 + 0xa9065ff8ULL) ^ 0x19f760ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0065 | PC: 0x037e0c | FDE: 0x19f850 | Size: 256 bytes
// Khung tháo gỡ #0065 | Địa chỉ PC: 0x037e0c | Địa chỉ FDE: 0x19f850 | Kích thước: 256 bytes
//   0x037e0c: D104C3FF  sub      sp, sp, #0x130
//   0x037e10: A90D6FFC  stp      x28, x27, [sp, #0xd0]
//   0x037e14: A90E67FA  stp      x26, x25, [sp, #0xe0]
//   0x037e18: A90F5FF8  stp      x24, x23, [sp, #0xf0]
static inline uint64_t fde_func_0065_0x037e0c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x037e0cULL ^ (static_cast<uint64_t>(0xd104c3ffULL) << 13);
    acc = (acc + a1 + 0xa90d6ffcULL) ^ 0x19f850ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0066 | PC: 0x03813c | FDE: 0x19faf8 | Size: 256 bytes
// Khung tháo gỡ #0066 | Địa chỉ PC: 0x03813c | Địa chỉ FDE: 0x19faf8 | Kích thước: 256 bytes
//   0x03813c: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x038140: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x038144: 910043FD  add      x29, sp, #0x10
//   0x038148: 90000D33  adrp     x19, #0x1dc000
static inline uint64_t fde_func_0066_0x03813c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x03813cULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x19faf8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0067 | PC: 0x038378 | FDE: 0x19fb48 | Size: 256 bytes
// Khung tháo gỡ #0067 | Địa chỉ PC: 0x038378 | Địa chỉ FDE: 0x19fb48 | Kích thước: 256 bytes
//   0x038378: D10283FF  sub      sp, sp, #0xa0
//   0x03837c: A9065FF8  stp      x24, x23, [sp, #0x60]
//   0x038380: A90757F6  stp      x22, x21, [sp, #0x70]
//   0x038384: A9084FF4  stp      x20, x19, [sp, #0x80]
static inline uint64_t fde_func_0067_0x038378(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x038378ULL ^ (static_cast<uint64_t>(0xd10283ffULL) << 13);
    acc = (acc + a1 + 0xa9065ff8ULL) ^ 0x19fb48ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0068 | PC: 0x0384fc | FDE: 0x19fc48 | Size: 256 bytes
// Khung tháo gỡ #0068 | Địa chỉ PC: 0x0384fc | Địa chỉ FDE: 0x19fc48 | Kích thước: 256 bytes
//   0x0384fc: D104C3FF  sub      sp, sp, #0x130
//   0x038500: A90D6FFC  stp      x28, x27, [sp, #0xd0]
//   0x038504: A90E67FA  stp      x26, x25, [sp, #0xe0]
//   0x038508: A90F5FF8  stp      x24, x23, [sp, #0xf0]
static inline uint64_t fde_func_0068_0x0384fc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0384fcULL ^ (static_cast<uint64_t>(0xd104c3ffULL) << 13);
    acc = (acc + a1 + 0xa90d6ffcULL) ^ 0x19fc48ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0069 | PC: 0x03882c | FDE: 0x19fd50 | Size: 256 bytes
// Khung tháo gỡ #0069 | Địa chỉ PC: 0x03882c | Địa chỉ FDE: 0x19fd50 | Kích thước: 256 bytes
//   0x03882c: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x038830: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x038834: 910043FD  add      x29, sp, #0x10
//   0x038838: 90000D33  adrp     x19, #0x1dc000
static inline uint64_t fde_func_0069_0x03882c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x03882cULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x19fd50ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0070 | PC: 0x038a68 | FDE: 0x19fda0 | Size: 256 bytes
// Khung tháo gỡ #0070 | Địa chỉ PC: 0x038a68 | Địa chỉ FDE: 0x19fda0 | Kích thước: 256 bytes
//   0x038a68: D10283FF  sub      sp, sp, #0xa0
//   0x038a6c: A9065FF8  stp      x24, x23, [sp, #0x60]
//   0x038a70: A90757F6  stp      x22, x21, [sp, #0x70]
//   0x038a74: A9084FF4  stp      x20, x19, [sp, #0x80]
static inline uint64_t fde_func_0070_0x038a68(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x038a68ULL ^ (static_cast<uint64_t>(0xd10283ffULL) << 13);
    acc = (acc + a1 + 0xa9065ff8ULL) ^ 0x19fda0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0071 | PC: 0x038bec | FDE: 0x19ffa8 | Size: 256 bytes
// Khung tháo gỡ #0071 | Địa chỉ PC: 0x038bec | Địa chỉ FDE: 0x19ffa8 | Kích thước: 256 bytes
//   0x038bec: D104C3FF  sub      sp, sp, #0x130
//   0x038bf0: A90D6FFC  stp      x28, x27, [sp, #0xd0]
//   0x038bf4: A90E67FA  stp      x26, x25, [sp, #0xe0]
//   0x038bf8: A90F5FF8  stp      x24, x23, [sp, #0xf0]
static inline uint64_t fde_func_0071_0x038bec(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x038becULL ^ (static_cast<uint64_t>(0xd104c3ffULL) << 13);
    acc = (acc + a1 + 0xa90d6ffcULL) ^ 0x19ffa8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0072 | PC: 0x038f1c | FDE: 0x1a0078 | Size: 256 bytes
// Khung tháo gỡ #0072 | Địa chỉ PC: 0x038f1c | Địa chỉ FDE: 0x1a0078 | Kích thước: 256 bytes
//   0x038f1c: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x038f20: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x038f24: 910043FD  add      x29, sp, #0x10
//   0x038f28: 90000D33  adrp     x19, #0x1dc000
static inline uint64_t fde_func_0072_0x038f1c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x038f1cULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1a0078ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0073 | PC: 0x039158 | FDE: 0x1a00c8 | Size: 256 bytes
// Khung tháo gỡ #0073 | Địa chỉ PC: 0x039158 | Địa chỉ FDE: 0x1a00c8 | Kích thước: 256 bytes
//   0x039158: D10283FF  sub      sp, sp, #0xa0
//   0x03915c: A9065FF8  stp      x24, x23, [sp, #0x60]
//   0x039160: A90757F6  stp      x22, x21, [sp, #0x70]
//   0x039164: A9084FF4  stp      x20, x19, [sp, #0x80]
static inline uint64_t fde_func_0073_0x039158(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x039158ULL ^ (static_cast<uint64_t>(0xd10283ffULL) << 13);
    acc = (acc + a1 + 0xa9065ff8ULL) ^ 0x1a00c8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0074 | PC: 0x0392dc | FDE: 0x1a0290 | Size: 256 bytes
// Khung tháo gỡ #0074 | Địa chỉ PC: 0x0392dc | Địa chỉ FDE: 0x1a0290 | Kích thước: 256 bytes
//   0x0392dc: D104C3FF  sub      sp, sp, #0x130
//   0x0392e0: A90D6FFC  stp      x28, x27, [sp, #0xd0]
//   0x0392e4: A90E67FA  stp      x26, x25, [sp, #0xe0]
//   0x0392e8: A90F5FF8  stp      x24, x23, [sp, #0xf0]
static inline uint64_t fde_func_0074_0x0392dc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0392dcULL ^ (static_cast<uint64_t>(0xd104c3ffULL) << 13);
    acc = (acc + a1 + 0xa90d6ffcULL) ^ 0x1a0290ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0075 | PC: 0x03960c | FDE: 0x1a05a8 | Size: 256 bytes
// Khung tháo gỡ #0075 | Địa chỉ PC: 0x03960c | Địa chỉ FDE: 0x1a05a8 | Kích thước: 256 bytes
//   0x03960c: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x039610: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x039614: 910043FD  add      x29, sp, #0x10
//   0x039618: F0000D13  adrp     x19, #0x1dc000
static inline uint64_t fde_func_0075_0x03960c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x03960cULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1a05a8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0076 | PC: 0x039848 | FDE: 0x1a0c10 | Size: 256 bytes
// Khung tháo gỡ #0076 | Địa chỉ PC: 0x039848 | Địa chỉ FDE: 0x1a0c10 | Kích thước: 256 bytes
//   0x039848: D10283FF  sub      sp, sp, #0xa0
//   0x03984c: A9065FF8  stp      x24, x23, [sp, #0x60]
//   0x039850: A90757F6  stp      x22, x21, [sp, #0x70]
//   0x039854: A9084FF4  stp      x20, x19, [sp, #0x80]
static inline uint64_t fde_func_0076_0x039848(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x039848ULL ^ (static_cast<uint64_t>(0xd10283ffULL) << 13);
    acc = (acc + a1 + 0xa9065ff8ULL) ^ 0x1a0c10ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0077 | PC: 0x0399cc | FDE: 0x1a0cf0 | Size: 256 bytes
// Khung tháo gỡ #0077 | Địa chỉ PC: 0x0399cc | Địa chỉ FDE: 0x1a0cf0 | Kích thước: 256 bytes
//   0x0399cc: D104C3FF  sub      sp, sp, #0x130
//   0x0399d0: A90D6FFC  stp      x28, x27, [sp, #0xd0]
//   0x0399d4: A90E67FA  stp      x26, x25, [sp, #0xe0]
//   0x0399d8: A90F5FF8  stp      x24, x23, [sp, #0xf0]
static inline uint64_t fde_func_0077_0x0399cc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0399ccULL ^ (static_cast<uint64_t>(0xd104c3ffULL) << 13);
    acc = (acc + a1 + 0xa90d6ffcULL) ^ 0x1a0cf0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0078 | PC: 0x039cfc | FDE: 0x1a0e40 | Size: 256 bytes
// Khung tháo gỡ #0078 | Địa chỉ PC: 0x039cfc | Địa chỉ FDE: 0x1a0e40 | Kích thước: 256 bytes
//   0x039cfc: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x039d00: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x039d04: 910043FD  add      x29, sp, #0x10
//   0x039d08: F0000D13  adrp     x19, #0x1dc000
static inline uint64_t fde_func_0078_0x039cfc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x039cfcULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1a0e40ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0079 | PC: 0x039f38 | FDE: 0x1a0e90 | Size: 256 bytes
// Khung tháo gỡ #0079 | Địa chỉ PC: 0x039f38 | Địa chỉ FDE: 0x1a0e90 | Kích thước: 256 bytes
//   0x039f38: D10283FF  sub      sp, sp, #0xa0
//   0x039f3c: A9065FF8  stp      x24, x23, [sp, #0x60]
//   0x039f40: A90757F6  stp      x22, x21, [sp, #0x70]
//   0x039f44: A9084FF4  stp      x20, x19, [sp, #0x80]
static inline uint64_t fde_func_0079_0x039f38(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x039f38ULL ^ (static_cast<uint64_t>(0xd10283ffULL) << 13);
    acc = (acc + a1 + 0xa9065ff8ULL) ^ 0x1a0e90ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0080 | PC: 0x03a0bc | FDE: 0x1a0f90 | Size: 256 bytes
// Khung tháo gỡ #0080 | Địa chỉ PC: 0x03a0bc | Địa chỉ FDE: 0x1a0f90 | Kích thước: 256 bytes
//   0x03a0bc: D104C3FF  sub      sp, sp, #0x130
//   0x03a0c0: A90D6FFC  stp      x28, x27, [sp, #0xd0]
//   0x03a0c4: A90E67FA  stp      x26, x25, [sp, #0xe0]
//   0x03a0c8: A90F5FF8  stp      x24, x23, [sp, #0xf0]
static inline uint64_t fde_func_0080_0x03a0bc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x03a0bcULL ^ (static_cast<uint64_t>(0xd104c3ffULL) << 13);
    acc = (acc + a1 + 0xa90d6ffcULL) ^ 0x1a0f90ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0081 | PC: 0x03a3ec | FDE: 0x1a1030 | Size: 256 bytes
// Khung tháo gỡ #0081 | Địa chỉ PC: 0x03a3ec | Địa chỉ FDE: 0x1a1030 | Kích thước: 256 bytes
//   0x03a3ec: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x03a3f0: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x03a3f4: 910043FD  add      x29, sp, #0x10
//   0x03a3f8: D0000D13  adrp     x19, #0x1dc000
static inline uint64_t fde_func_0081_0x03a3ec(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x03a3ecULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1a1030ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0082 | PC: 0x03a628 | FDE: 0x1a1080 | Size: 256 bytes
// Khung tháo gỡ #0082 | Địa chỉ PC: 0x03a628 | Địa chỉ FDE: 0x1a1080 | Kích thước: 256 bytes
//   0x03a628: D10283FF  sub      sp, sp, #0xa0
//   0x03a62c: A9065FF8  stp      x24, x23, [sp, #0x60]
//   0x03a630: A90757F6  stp      x22, x21, [sp, #0x70]
//   0x03a634: A9084FF4  stp      x20, x19, [sp, #0x80]
static inline uint64_t fde_func_0082_0x03a628(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x03a628ULL ^ (static_cast<uint64_t>(0xd10283ffULL) << 13);
    acc = (acc + a1 + 0xa9065ff8ULL) ^ 0x1a1080ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0083 | PC: 0x03a7ac | FDE: 0x1a1160 | Size: 256 bytes
// Khung tháo gỡ #0083 | Địa chỉ PC: 0x03a7ac | Địa chỉ FDE: 0x1a1160 | Kích thước: 256 bytes
//   0x03a7ac: D104C3FF  sub      sp, sp, #0x130
//   0x03a7b0: A90D6FFC  stp      x28, x27, [sp, #0xd0]
//   0x03a7b4: A90E67FA  stp      x26, x25, [sp, #0xe0]
//   0x03a7b8: A90F5FF8  stp      x24, x23, [sp, #0xf0]
static inline uint64_t fde_func_0083_0x03a7ac(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x03a7acULL ^ (static_cast<uint64_t>(0xd104c3ffULL) << 13);
    acc = (acc + a1 + 0xa90d6ffcULL) ^ 0x1a1160ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0084 | PC: 0x03aadc | FDE: 0x1a1510 | Size: 256 bytes
// Khung tháo gỡ #0084 | Địa chỉ PC: 0x03aadc | Địa chỉ FDE: 0x1a1510 | Kích thước: 256 bytes
//   0x03aadc: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x03aae0: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x03aae4: 910043FD  add      x29, sp, #0x10
//   0x03aae8: D0000D13  adrp     x19, #0x1dc000
static inline uint64_t fde_func_0084_0x03aadc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x03aadcULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1a1510ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0085 | PC: 0x03ad18 | FDE: 0x1a1578 | Size: 256 bytes
// Khung tháo gỡ #0085 | Địa chỉ PC: 0x03ad18 | Địa chỉ FDE: 0x1a1578 | Kích thước: 256 bytes
//   0x03ad18: D10283FF  sub      sp, sp, #0xa0
//   0x03ad1c: A9065FF8  stp      x24, x23, [sp, #0x60]
//   0x03ad20: A90757F6  stp      x22, x21, [sp, #0x70]
//   0x03ad24: A9084FF4  stp      x20, x19, [sp, #0x80]
static inline uint64_t fde_func_0085_0x03ad18(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x03ad18ULL ^ (static_cast<uint64_t>(0xd10283ffULL) << 13);
    acc = (acc + a1 + 0xa9065ff8ULL) ^ 0x1a1578ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0086 | PC: 0x03ae9c | FDE: 0x1a1628 | Size: 256 bytes
// Khung tháo gỡ #0086 | Địa chỉ PC: 0x03ae9c | Địa chỉ FDE: 0x1a1628 | Kích thước: 256 bytes
//   0x03ae9c: D104C3FF  sub      sp, sp, #0x130
//   0x03aea0: A90D6FFC  stp      x28, x27, [sp, #0xd0]
//   0x03aea4: A90E67FA  stp      x26, x25, [sp, #0xe0]
//   0x03aea8: A90F5FF8  stp      x24, x23, [sp, #0xf0]
static inline uint64_t fde_func_0086_0x03ae9c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x03ae9cULL ^ (static_cast<uint64_t>(0xd104c3ffULL) << 13);
    acc = (acc + a1 + 0xa90d6ffcULL) ^ 0x1a1628ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0087 | PC: 0x03b1cc | FDE: 0x1a16f0 | Size: 256 bytes
// Khung tháo gỡ #0087 | Địa chỉ PC: 0x03b1cc | Địa chỉ FDE: 0x1a16f0 | Kích thước: 256 bytes
//   0x03b1cc: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x03b1d0: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x03b1d4: 910043FD  add      x29, sp, #0x10
//   0x03b1d8: B0000D13  adrp     x19, #0x1dc000
static inline uint64_t fde_func_0087_0x03b1cc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x03b1ccULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1a16f0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0088 | PC: 0x03b408 | FDE: 0x1a1740 | Size: 256 bytes
// Khung tháo gỡ #0088 | Địa chỉ PC: 0x03b408 | Địa chỉ FDE: 0x1a1740 | Kích thước: 256 bytes
//   0x03b408: D10283FF  sub      sp, sp, #0xa0
//   0x03b40c: A9065FF8  stp      x24, x23, [sp, #0x60]
//   0x03b410: A90757F6  stp      x22, x21, [sp, #0x70]
//   0x03b414: A9084FF4  stp      x20, x19, [sp, #0x80]
static inline uint64_t fde_func_0088_0x03b408(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x03b408ULL ^ (static_cast<uint64_t>(0xd10283ffULL) << 13);
    acc = (acc + a1 + 0xa9065ff8ULL) ^ 0x1a1740ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0089 | PC: 0x03b58c | FDE: 0x1a17e8 | Size: 256 bytes
// Khung tháo gỡ #0089 | Địa chỉ PC: 0x03b58c | Địa chỉ FDE: 0x1a17e8 | Kích thước: 256 bytes
//   0x03b58c: D104C3FF  sub      sp, sp, #0x130
//   0x03b590: A90D6FFC  stp      x28, x27, [sp, #0xd0]
//   0x03b594: A90E67FA  stp      x26, x25, [sp, #0xe0]
//   0x03b598: A90F5FF8  stp      x24, x23, [sp, #0xf0]
static inline uint64_t fde_func_0089_0x03b58c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x03b58cULL ^ (static_cast<uint64_t>(0xd104c3ffULL) << 13);
    acc = (acc + a1 + 0xa90d6ffcULL) ^ 0x1a17e8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0090 | PC: 0x03b8bc | FDE: 0x1a1890 | Size: 256 bytes
// Khung tháo gỡ #0090 | Địa chỉ PC: 0x03b8bc | Địa chỉ FDE: 0x1a1890 | Kích thước: 256 bytes
//   0x03b8bc: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x03b8c0: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x03b8c4: 910043FD  add      x29, sp, #0x10
//   0x03b8c8: B0000D13  adrp     x19, #0x1dc000
static inline uint64_t fde_func_0090_0x03b8bc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x03b8bcULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1a1890ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0091 | PC: 0x03baf8 | FDE: 0x1a18e0 | Size: 256 bytes
// Khung tháo gỡ #0091 | Địa chỉ PC: 0x03baf8 | Địa chỉ FDE: 0x1a18e0 | Kích thước: 256 bytes
//   0x03baf8: D10283FF  sub      sp, sp, #0xa0
//   0x03bafc: A9065FF8  stp      x24, x23, [sp, #0x60]
//   0x03bb00: A90757F6  stp      x22, x21, [sp, #0x70]
//   0x03bb04: A9084FF4  stp      x20, x19, [sp, #0x80]
static inline uint64_t fde_func_0091_0x03baf8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x03baf8ULL ^ (static_cast<uint64_t>(0xd10283ffULL) << 13);
    acc = (acc + a1 + 0xa9065ff8ULL) ^ 0x1a18e0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0092 | PC: 0x03bc7c | FDE: 0x1a1cf0 | Size: 256 bytes
// Khung tháo gỡ #0092 | Địa chỉ PC: 0x03bc7c | Địa chỉ FDE: 0x1a1cf0 | Kích thước: 256 bytes
//   0x03bc7c: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x03bc80: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x03bc84: 910043FD  add      x29, sp, #0x10
//   0x03bc88: B0000D13  adrp     x19, #0x1dc000
static inline uint64_t fde_func_0092_0x03bc7c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x03bc7cULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1a1cf0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0093 | PC: 0x03cab4 | FDE: 0x1a1e08 | Size: 256 bytes
// Khung tháo gỡ #0093 | Địa chỉ PC: 0x03cab4 | Địa chỉ FDE: 0x1a1e08 | Kích thước: 256 bytes
//   0x03cab4: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x03cab8: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x03cabc: 910043FD  add      x29, sp, #0x10
//   0x03cac0: B0000D13  adrp     x19, #0x1dd000
static inline uint64_t fde_func_0093_0x03cab4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x03cab4ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1a1e08ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0094 | PC: 0x03ccf0 | FDE: 0x1a1e58 | Size: 256 bytes
// Khung tháo gỡ #0094 | Địa chỉ PC: 0x03ccf0 | Địa chỉ FDE: 0x1a1e58 | Kích thước: 256 bytes
//   0x03ccf0: D10283FF  sub      sp, sp, #0xa0
//   0x03ccf4: A9065FF8  stp      x24, x23, [sp, #0x60]
//   0x03ccf8: A90757F6  stp      x22, x21, [sp, #0x70]
//   0x03ccfc: A9084FF4  stp      x20, x19, [sp, #0x80]
static inline uint64_t fde_func_0094_0x03ccf0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x03ccf0ULL ^ (static_cast<uint64_t>(0xd10283ffULL) << 13);
    acc = (acc + a1 + 0xa9065ff8ULL) ^ 0x1a1e58ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0095 | PC: 0x03ce74 | FDE: 0x1a2120 | Size: 256 bytes
// Khung tháo gỡ #0095 | Địa chỉ PC: 0x03ce74 | Địa chỉ FDE: 0x1a2120 | Kích thước: 256 bytes
//   0x03ce74: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x03ce78: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x03ce7c: 910043FD  add      x29, sp, #0x10
//   0x03ce80: B0000D13  adrp     x19, #0x1dd000
static inline uint64_t fde_func_0095_0x03ce74(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x03ce74ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1a2120ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0096 | PC: 0x03d3b0 | FDE: 0x1a2460 | Size: 256 bytes
// Khung tháo gỡ #0096 | Địa chỉ PC: 0x03d3b0 | Địa chỉ FDE: 0x1a2460 | Kích thước: 256 bytes
//   0x03d3b0: D104C3FF  sub      sp, sp, #0x130
//   0x03d3b4: A90D6FFC  stp      x28, x27, [sp, #0xd0]
//   0x03d3b8: A90E67FA  stp      x26, x25, [sp, #0xe0]
//   0x03d3bc: A90F5FF8  stp      x24, x23, [sp, #0xf0]
static inline uint64_t fde_func_0096_0x03d3b0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x03d3b0ULL ^ (static_cast<uint64_t>(0xd104c3ffULL) << 13);
    acc = (acc + a1 + 0xa90d6ffcULL) ^ 0x1a2460ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0097 | PC: 0x03d6e0 | FDE: 0x1a29d8 | Size: 256 bytes
// Khung tháo gỡ #0097 | Địa chỉ PC: 0x03d6e0 | Địa chỉ FDE: 0x1a29d8 | Kích thước: 256 bytes
//   0x03d6e0: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x03d6e4: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x03d6e8: 910043FD  add      x29, sp, #0x10
//   0x03d6ec: 90000D13  adrp     x19, #0x1dd000
static inline uint64_t fde_func_0097_0x03d6e0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x03d6e0ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1a29d8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0098 | PC: 0x03d91c | FDE: 0x1a2a28 | Size: 256 bytes
// Khung tháo gỡ #0098 | Địa chỉ PC: 0x03d91c | Địa chỉ FDE: 0x1a2a28 | Kích thước: 256 bytes
//   0x03d91c: D10283FF  sub      sp, sp, #0xa0
//   0x03d920: A9065FF8  stp      x24, x23, [sp, #0x60]
//   0x03d924: A90757F6  stp      x22, x21, [sp, #0x70]
//   0x03d928: A9084FF4  stp      x20, x19, [sp, #0x80]
static inline uint64_t fde_func_0098_0x03d91c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x03d91cULL ^ (static_cast<uint64_t>(0xd10283ffULL) << 13);
    acc = (acc + a1 + 0xa9065ff8ULL) ^ 0x1a2a28ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0099 | PC: 0x03daa0 | FDE: 0x1a2b70 | Size: 256 bytes
// Khung tháo gỡ #0099 | Địa chỉ PC: 0x03daa0 | Địa chỉ FDE: 0x1a2b70 | Kích thước: 256 bytes
//   0x03daa0: D104C3FF  sub      sp, sp, #0x130
//   0x03daa4: A90D6FFC  stp      x28, x27, [sp, #0xd0]
//   0x03daa8: A90E67FA  stp      x26, x25, [sp, #0xe0]
//   0x03daac: A90F5FF8  stp      x24, x23, [sp, #0xf0]
static inline uint64_t fde_func_0099_0x03daa0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x03daa0ULL ^ (static_cast<uint64_t>(0xd104c3ffULL) << 13);
    acc = (acc + a1 + 0xa90d6ffcULL) ^ 0x1a2b70ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0100 | PC: 0x03ddd0 | FDE: 0x1a2c58 | Size: 256 bytes
// Khung tháo gỡ #0100 | Địa chỉ PC: 0x03ddd0 | Địa chỉ FDE: 0x1a2c58 | Kích thước: 256 bytes
//   0x03ddd0: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x03ddd4: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x03ddd8: 910043FD  add      x29, sp, #0x10
//   0x03dddc: 90000D13  adrp     x19, #0x1dd000
static inline uint64_t fde_func_0100_0x03ddd0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x03ddd0ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1a2c58ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0101 | PC: 0x03e00c | FDE: 0x1a2ca8 | Size: 256 bytes
// Khung tháo gỡ #0101 | Địa chỉ PC: 0x03e00c | Địa chỉ FDE: 0x1a2ca8 | Kích thước: 256 bytes
//   0x03e00c: D10283FF  sub      sp, sp, #0xa0
//   0x03e010: A9065FF8  stp      x24, x23, [sp, #0x60]
//   0x03e014: A90757F6  stp      x22, x21, [sp, #0x70]
//   0x03e018: A9084FF4  stp      x20, x19, [sp, #0x80]
static inline uint64_t fde_func_0101_0x03e00c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x03e00cULL ^ (static_cast<uint64_t>(0xd10283ffULL) << 13);
    acc = (acc + a1 + 0xa9065ff8ULL) ^ 0x1a2ca8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0102 | PC: 0x03e190 | FDE: 0x1a2d90 | Size: 256 bytes
// Khung tháo gỡ #0102 | Địa chỉ PC: 0x03e190 | Địa chỉ FDE: 0x1a2d90 | Kích thước: 256 bytes
//   0x03e190: D104C3FF  sub      sp, sp, #0x130
//   0x03e194: A90D6FFC  stp      x28, x27, [sp, #0xd0]
//   0x03e198: A90E67FA  stp      x26, x25, [sp, #0xe0]
//   0x03e19c: A90F5FF8  stp      x24, x23, [sp, #0xf0]
static inline uint64_t fde_func_0102_0x03e190(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x03e190ULL ^ (static_cast<uint64_t>(0xd104c3ffULL) << 13);
    acc = (acc + a1 + 0xa90d6ffcULL) ^ 0x1a2d90ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0103 | PC: 0x03e4c0 | FDE: 0x1a2fa0 | Size: 256 bytes
// Khung tháo gỡ #0103 | Địa chỉ PC: 0x03e4c0 | Địa chỉ FDE: 0x1a2fa0 | Kích thước: 256 bytes
//   0x03e4c0: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x03e4c4: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x03e4c8: 910043FD  add      x29, sp, #0x10
//   0x03e4cc: F0000CF3  adrp     x19, #0x1dd000
static inline uint64_t fde_func_0103_0x03e4c0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x03e4c0ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1a2fa0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0104 | PC: 0x03e6fc | FDE: 0x1a3008 | Size: 256 bytes
// Khung tháo gỡ #0104 | Địa chỉ PC: 0x03e6fc | Địa chỉ FDE: 0x1a3008 | Kích thước: 256 bytes
//   0x03e6fc: D10283FF  sub      sp, sp, #0xa0
//   0x03e700: A9065FF8  stp      x24, x23, [sp, #0x60]
//   0x03e704: A90757F6  stp      x22, x21, [sp, #0x70]
//   0x03e708: A9084FF4  stp      x20, x19, [sp, #0x80]
static inline uint64_t fde_func_0104_0x03e6fc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x03e6fcULL ^ (static_cast<uint64_t>(0xd10283ffULL) << 13);
    acc = (acc + a1 + 0xa9065ff8ULL) ^ 0x1a3008ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0105 | PC: 0x03e880 | FDE: 0x1a3188 | Size: 256 bytes
// Khung tháo gỡ #0105 | Địa chỉ PC: 0x03e880 | Địa chỉ FDE: 0x1a3188 | Kích thước: 256 bytes
//   0x03e880: D104C3FF  sub      sp, sp, #0x130
//   0x03e884: A90D6FFC  stp      x28, x27, [sp, #0xd0]
//   0x03e888: A90E67FA  stp      x26, x25, [sp, #0xe0]
//   0x03e88c: A90F5FF8  stp      x24, x23, [sp, #0xf0]
static inline uint64_t fde_func_0105_0x03e880(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x03e880ULL ^ (static_cast<uint64_t>(0xd104c3ffULL) << 13);
    acc = (acc + a1 + 0xa90d6ffcULL) ^ 0x1a3188ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0106 | PC: 0x03ebb0 | FDE: 0x1a3290 | Size: 256 bytes
// Khung tháo gỡ #0106 | Địa chỉ PC: 0x03ebb0 | Địa chỉ FDE: 0x1a3290 | Kích thước: 256 bytes
//   0x03ebb0: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x03ebb4: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x03ebb8: 910043FD  add      x29, sp, #0x10
//   0x03ebbc: F0000CF3  adrp     x19, #0x1dd000
static inline uint64_t fde_func_0106_0x03ebb0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x03ebb0ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1a3290ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0107 | PC: 0x03edec | FDE: 0x1a32f8 | Size: 256 bytes
// Khung tháo gỡ #0107 | Địa chỉ PC: 0x03edec | Địa chỉ FDE: 0x1a32f8 | Kích thước: 256 bytes
//   0x03edec: D10283FF  sub      sp, sp, #0xa0
//   0x03edf0: A9065FF8  stp      x24, x23, [sp, #0x60]
//   0x03edf4: A90757F6  stp      x22, x21, [sp, #0x70]
//   0x03edf8: A9084FF4  stp      x20, x19, [sp, #0x80]
static inline uint64_t fde_func_0107_0x03edec(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x03edecULL ^ (static_cast<uint64_t>(0xd10283ffULL) << 13);
    acc = (acc + a1 + 0xa9065ff8ULL) ^ 0x1a32f8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0108 | PC: 0x03ef70 | FDE: 0x1a3480 | Size: 256 bytes
// Khung tháo gỡ #0108 | Địa chỉ PC: 0x03ef70 | Địa chỉ FDE: 0x1a3480 | Kích thước: 256 bytes
//   0x03ef70: D104C3FF  sub      sp, sp, #0x130
//   0x03ef74: A90D6FFC  stp      x28, x27, [sp, #0xd0]
//   0x03ef78: A90E67FA  stp      x26, x25, [sp, #0xe0]
//   0x03ef7c: A90F5FF8  stp      x24, x23, [sp, #0xf0]
static inline uint64_t fde_func_0108_0x03ef70(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x03ef70ULL ^ (static_cast<uint64_t>(0xd104c3ffULL) << 13);
    acc = (acc + a1 + 0xa90d6ffcULL) ^ 0x1a3480ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0109 | PC: 0x03f2a0 | FDE: 0x1a3590 | Size: 256 bytes
// Khung tháo gỡ #0109 | Địa chỉ PC: 0x03f2a0 | Địa chỉ FDE: 0x1a3590 | Kích thước: 256 bytes
//   0x03f2a0: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x03f2a4: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x03f2a8: 910043FD  add      x29, sp, #0x10
//   0x03f2ac: D0000CF3  adrp     x19, #0x1dd000
static inline uint64_t fde_func_0109_0x03f2a0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x03f2a0ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1a3590ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0110 | PC: 0x03f4dc | FDE: 0x1a35f8 | Size: 256 bytes
// Khung tháo gỡ #0110 | Địa chỉ PC: 0x03f4dc | Địa chỉ FDE: 0x1a35f8 | Kích thước: 256 bytes
//   0x03f4dc: D10283FF  sub      sp, sp, #0xa0
//   0x03f4e0: A9065FF8  stp      x24, x23, [sp, #0x60]
//   0x03f4e4: A90757F6  stp      x22, x21, [sp, #0x70]
//   0x03f4e8: A9084FF4  stp      x20, x19, [sp, #0x80]
static inline uint64_t fde_func_0110_0x03f4dc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x03f4dcULL ^ (static_cast<uint64_t>(0xd10283ffULL) << 13);
    acc = (acc + a1 + 0xa9065ff8ULL) ^ 0x1a35f8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0111 | PC: 0x03f660 | FDE: 0x1a36a0 | Size: 256 bytes
// Khung tháo gỡ #0111 | Địa chỉ PC: 0x03f660 | Địa chỉ FDE: 0x1a36a0 | Kích thước: 256 bytes
//   0x03f660: D104C3FF  sub      sp, sp, #0x130
//   0x03f664: A90D6FFC  stp      x28, x27, [sp, #0xd0]
//   0x03f668: A90E67FA  stp      x26, x25, [sp, #0xe0]
//   0x03f66c: A90F5FF8  stp      x24, x23, [sp, #0xf0]
static inline uint64_t fde_func_0111_0x03f660(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x03f660ULL ^ (static_cast<uint64_t>(0xd104c3ffULL) << 13);
    acc = (acc + a1 + 0xa90d6ffcULL) ^ 0x1a36a0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0112 | PC: 0x03f990 | FDE: 0x1a3820 | Size: 256 bytes
// Khung tháo gỡ #0112 | Địa chỉ PC: 0x03f990 | Địa chỉ FDE: 0x1a3820 | Kích thước: 256 bytes
//   0x03f990: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x03f994: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x03f998: 910043FD  add      x29, sp, #0x10
//   0x03f99c: D0000CF3  adrp     x19, #0x1dd000
static inline uint64_t fde_func_0112_0x03f990(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x03f990ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1a3820ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0113 | PC: 0x03fbcc | FDE: 0x1a3870 | Size: 256 bytes
// Khung tháo gỡ #0113 | Địa chỉ PC: 0x03fbcc | Địa chỉ FDE: 0x1a3870 | Kích thước: 256 bytes
//   0x03fbcc: D10283FF  sub      sp, sp, #0xa0
//   0x03fbd0: A9065FF8  stp      x24, x23, [sp, #0x60]
//   0x03fbd4: A90757F6  stp      x22, x21, [sp, #0x70]
//   0x03fbd8: A9084FF4  stp      x20, x19, [sp, #0x80]
static inline uint64_t fde_func_0113_0x03fbcc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x03fbccULL ^ (static_cast<uint64_t>(0xd10283ffULL) << 13);
    acc = (acc + a1 + 0xa9065ff8ULL) ^ 0x1a3870ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0114 | PC: 0x03fd50 | FDE: 0x1a3c80 | Size: 256 bytes
// Khung tháo gỡ #0114 | Địa chỉ PC: 0x03fd50 | Địa chỉ FDE: 0x1a3c80 | Kích thước: 256 bytes
//   0x03fd50: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x03fd54: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x03fd58: 910043FD  add      x29, sp, #0x10
//   0x03fd5c: D0000CF3  adrp     x19, #0x1dd000
static inline uint64_t fde_func_0114_0x03fd50(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x03fd50ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1a3c80ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0115 | PC: 0x03ff8c | FDE: 0x1a3e28 | Size: 256 bytes
// Khung tháo gỡ #0115 | Địa chỉ PC: 0x03ff8c | Địa chỉ FDE: 0x1a3e28 | Kích thước: 256 bytes
//   0x03ff8c: D10283FF  sub      sp, sp, #0xa0
//   0x03ff90: A9065FF8  stp      x24, x23, [sp, #0x60]
//   0x03ff94: A90757F6  stp      x22, x21, [sp, #0x70]
//   0x03ff98: A9084FF4  stp      x20, x19, [sp, #0x80]
static inline uint64_t fde_func_0115_0x03ff8c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x03ff8cULL ^ (static_cast<uint64_t>(0xd10283ffULL) << 13);
    acc = (acc + a1 + 0xa9065ff8ULL) ^ 0x1a3e28ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0116 | PC: 0x040110 | FDE: 0x1a4090 | Size: 256 bytes
// Khung tháo gỡ #0116 | Địa chỉ PC: 0x040110 | Địa chỉ FDE: 0x1a4090 | Kích thước: 256 bytes
//   0x040110: D104C3FF  sub      sp, sp, #0x130
//   0x040114: A90D6FFC  stp      x28, x27, [sp, #0xd0]
//   0x040118: A90E67FA  stp      x26, x25, [sp, #0xe0]
//   0x04011c: A90F5FF8  stp      x24, x23, [sp, #0xf0]
static inline uint64_t fde_func_0116_0x040110(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x040110ULL ^ (static_cast<uint64_t>(0xd104c3ffULL) << 13);
    acc = (acc + a1 + 0xa90d6ffcULL) ^ 0x1a4090ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0117 | PC: 0x040440 | FDE: 0x1a41a0 | Size: 256 bytes
// Khung tháo gỡ #0117 | Địa chỉ PC: 0x040440 | Địa chỉ FDE: 0x1a41a0 | Kích thước: 256 bytes
//   0x040440: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x040444: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x040448: 910043FD  add      x29, sp, #0x10
//   0x04044c: B0000CF3  adrp     x19, #0x1dd000
static inline uint64_t fde_func_0117_0x040440(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x040440ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1a41a0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0118 | PC: 0x04067c | FDE: 0x1a41f0 | Size: 256 bytes
// Khung tháo gỡ #0118 | Địa chỉ PC: 0x04067c | Địa chỉ FDE: 0x1a41f0 | Kích thước: 256 bytes
//   0x04067c: D10283FF  sub      sp, sp, #0xa0
//   0x040680: A9065FF8  stp      x24, x23, [sp, #0x60]
//   0x040684: A90757F6  stp      x22, x21, [sp, #0x70]
//   0x040688: A9084FF4  stp      x20, x19, [sp, #0x80]
static inline uint64_t fde_func_0118_0x04067c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x04067cULL ^ (static_cast<uint64_t>(0xd10283ffULL) << 13);
    acc = (acc + a1 + 0xa9065ff8ULL) ^ 0x1a41f0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0119 | PC: 0x040800 | FDE: 0x1a42f8 | Size: 256 bytes
// Khung tháo gỡ #0119 | Địa chỉ PC: 0x040800 | Địa chỉ FDE: 0x1a42f8 | Kích thước: 256 bytes
//   0x040800: D104C3FF  sub      sp, sp, #0x130
//   0x040804: A90D6FFC  stp      x28, x27, [sp, #0xd0]
//   0x040808: A90E67FA  stp      x26, x25, [sp, #0xe0]
//   0x04080c: A90F5FF8  stp      x24, x23, [sp, #0xf0]
static inline uint64_t fde_func_0119_0x040800(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x040800ULL ^ (static_cast<uint64_t>(0xd104c3ffULL) << 13);
    acc = (acc + a1 + 0xa90d6ffcULL) ^ 0x1a42f8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0120 | PC: 0x040b30 | FDE: 0x1a4480 | Size: 256 bytes
// Khung tháo gỡ #0120 | Địa chỉ PC: 0x040b30 | Địa chỉ FDE: 0x1a4480 | Kích thước: 256 bytes
//   0x040b30: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x040b34: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x040b38: 910043FD  add      x29, sp, #0x10
//   0x040b3c: B0000CF3  adrp     x19, #0x1dd000
static inline uint64_t fde_func_0120_0x040b30(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x040b30ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1a4480ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0121 | PC: 0x040d6c | FDE: 0x1a44d0 | Size: 256 bytes
// Khung tháo gỡ #0121 | Địa chỉ PC: 0x040d6c | Địa chỉ FDE: 0x1a44d0 | Kích thước: 256 bytes
//   0x040d6c: D10283FF  sub      sp, sp, #0xa0
//   0x040d70: A9065FF8  stp      x24, x23, [sp, #0x60]
//   0x040d74: A90757F6  stp      x22, x21, [sp, #0x70]
//   0x040d78: A9084FF4  stp      x20, x19, [sp, #0x80]
static inline uint64_t fde_func_0121_0x040d6c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x040d6cULL ^ (static_cast<uint64_t>(0xd10283ffULL) << 13);
    acc = (acc + a1 + 0xa9065ff8ULL) ^ 0x1a44d0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0122 | PC: 0x040ef0 | FDE: 0x1a4950 | Size: 256 bytes
// Khung tháo gỡ #0122 | Địa chỉ PC: 0x040ef0 | Địa chỉ FDE: 0x1a4950 | Kích thước: 256 bytes
//   0x040ef0: D104C3FF  sub      sp, sp, #0x130
//   0x040ef4: A90D6FFC  stp      x28, x27, [sp, #0xd0]
//   0x040ef8: A90E67FA  stp      x26, x25, [sp, #0xe0]
//   0x040efc: A90F5FF8  stp      x24, x23, [sp, #0xf0]
static inline uint64_t fde_func_0122_0x040ef0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x040ef0ULL ^ (static_cast<uint64_t>(0xd104c3ffULL) << 13);
    acc = (acc + a1 + 0xa90d6ffcULL) ^ 0x1a4950ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0123 | PC: 0x041220 | FDE: 0x1a4c70 | Size: 256 bytes
// Khung tháo gỡ #0123 | Địa chỉ PC: 0x041220 | Địa chỉ FDE: 0x1a4c70 | Kích thước: 256 bytes
//   0x041220: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x041224: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x041228: 910043FD  add      x29, sp, #0x10
//   0x04122c: 90000CF3  adrp     x19, #0x1dd000
static inline uint64_t fde_func_0123_0x041220(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x041220ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1a4c70ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0124 | PC: 0x0415c0 | FDE: 0x1a4cd8 | Size: 256 bytes
// Khung tháo gỡ #0124 | Địa chỉ PC: 0x0415c0 | Địa chỉ FDE: 0x1a4cd8 | Kích thước: 256 bytes
//   0x0415c0: D10283FF  sub      sp, sp, #0xa0
//   0x0415c4: A9065FF8  stp      x24, x23, [sp, #0x60]
//   0x0415c8: A90757F6  stp      x22, x21, [sp, #0x70]
//   0x0415cc: A9084FF4  stp      x20, x19, [sp, #0x80]
static inline uint64_t fde_func_0124_0x0415c0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0415c0ULL ^ (static_cast<uint64_t>(0xd10283ffULL) << 13);
    acc = (acc + a1 + 0xa9065ff8ULL) ^ 0x1a4cd8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0125 | PC: 0x041744 | FDE: 0x1a4d98 | Size: 256 bytes
// Khung tháo gỡ #0125 | Địa chỉ PC: 0x041744 | Địa chỉ FDE: 0x1a4d98 | Kích thước: 256 bytes
//   0x041744: D104C3FF  sub      sp, sp, #0x130
//   0x041748: A90D6FFC  stp      x28, x27, [sp, #0xd0]
//   0x04174c: A90E67FA  stp      x26, x25, [sp, #0xe0]
//   0x041750: A90F5FF8  stp      x24, x23, [sp, #0xf0]
static inline uint64_t fde_func_0125_0x041744(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x041744ULL ^ (static_cast<uint64_t>(0xd104c3ffULL) << 13);
    acc = (acc + a1 + 0xa90d6ffcULL) ^ 0x1a4d98ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0126 | PC: 0x041a74 | FDE: 0x1a4f68 | Size: 256 bytes
// Khung tháo gỡ #0126 | Địa chỉ PC: 0x041a74 | Địa chỉ FDE: 0x1a4f68 | Kích thước: 256 bytes
//   0x041a74: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x041a78: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x041a7c: 910043FD  add      x29, sp, #0x10
//   0x041a80: B0000CF3  adrp     x19, #0x1de000
static inline uint64_t fde_func_0126_0x041a74(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x041a74ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1a4f68ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0127 | PC: 0x041cb0 | FDE: 0x1a4fb8 | Size: 256 bytes
// Khung tháo gỡ #0127 | Địa chỉ PC: 0x041cb0 | Địa chỉ FDE: 0x1a4fb8 | Kích thước: 256 bytes
//   0x041cb0: D10283FF  sub      sp, sp, #0xa0
//   0x041cb4: A9065FF8  stp      x24, x23, [sp, #0x60]
//   0x041cb8: A90757F6  stp      x22, x21, [sp, #0x70]
//   0x041cbc: A9084FF4  stp      x20, x19, [sp, #0x80]
static inline uint64_t fde_func_0127_0x041cb0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x041cb0ULL ^ (static_cast<uint64_t>(0xd10283ffULL) << 13);
    acc = (acc + a1 + 0xa9065ff8ULL) ^ 0x1a4fb8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0128 | PC: 0x041e34 | FDE: 0x1a50c0 | Size: 256 bytes
// Khung tháo gỡ #0128 | Địa chỉ PC: 0x041e34 | Địa chỉ FDE: 0x1a50c0 | Kích thước: 256 bytes
//   0x041e34: D104C3FF  sub      sp, sp, #0x130
//   0x041e38: A90D6FFC  stp      x28, x27, [sp, #0xd0]
//   0x041e3c: A90E67FA  stp      x26, x25, [sp, #0xe0]
//   0x041e40: A90F5FF8  stp      x24, x23, [sp, #0xf0]
static inline uint64_t fde_func_0128_0x041e34(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x041e34ULL ^ (static_cast<uint64_t>(0xd104c3ffULL) << 13);
    acc = (acc + a1 + 0xa90d6ffcULL) ^ 0x1a50c0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0129 | PC: 0x042164 | FDE: 0x1a5190 | Size: 256 bytes
// Khung tháo gỡ #0129 | Địa chỉ PC: 0x042164 | Địa chỉ FDE: 0x1a5190 | Kích thước: 256 bytes
//   0x042164: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x042168: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x04216c: 910043FD  add      x29, sp, #0x10
//   0x042170: 90000CF3  adrp     x19, #0x1de000
static inline uint64_t fde_func_0129_0x042164(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x042164ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1a5190ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0130 | PC: 0x0423a0 | FDE: 0x1a51f8 | Size: 256 bytes
// Khung tháo gỡ #0130 | Địa chỉ PC: 0x0423a0 | Địa chỉ FDE: 0x1a51f8 | Kích thước: 256 bytes
//   0x0423a0: D10283FF  sub      sp, sp, #0xa0
//   0x0423a4: A9065FF8  stp      x24, x23, [sp, #0x60]
//   0x0423a8: A90757F6  stp      x22, x21, [sp, #0x70]
//   0x0423ac: A9084FF4  stp      x20, x19, [sp, #0x80]
static inline uint64_t fde_func_0130_0x0423a0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0423a0ULL ^ (static_cast<uint64_t>(0xd10283ffULL) << 13);
    acc = (acc + a1 + 0xa9065ff8ULL) ^ 0x1a51f8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0131 | PC: 0x042524 | FDE: 0x1a5290 | Size: 256 bytes
// Khung tháo gỡ #0131 | Địa chỉ PC: 0x042524 | Địa chỉ FDE: 0x1a5290 | Kích thước: 256 bytes
//   0x042524: D104C3FF  sub      sp, sp, #0x130
//   0x042528: A90D6FFC  stp      x28, x27, [sp, #0xd0]
//   0x04252c: A90E67FA  stp      x26, x25, [sp, #0xe0]
//   0x042530: A90F5FF8  stp      x24, x23, [sp, #0xf0]
static inline uint64_t fde_func_0131_0x042524(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x042524ULL ^ (static_cast<uint64_t>(0xd104c3ffULL) << 13);
    acc = (acc + a1 + 0xa90d6ffcULL) ^ 0x1a5290ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0132 | PC: 0x042854 | FDE: 0x1a5370 | Size: 144 bytes
// Khung tháo gỡ #0132 | Địa chỉ PC: 0x042854 | Địa chỉ FDE: 0x1a5370 | Kích thước: 144 bytes
//   0x042854: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x042858: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x04285c: 910043FD  add      x29, sp, #0x10
//   0x042860: 90000CF3  adrp     x19, #0x1de000
static inline uint64_t fde_func_0132_0x042854(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x042854ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1a5370ULL;
    acc ^= (acc >> 17) * 0x0090ULL;
    return acc;
}

// FDE #0133 | PC: 0x0428e4 | FDE: 0x1ad698 | Size: 256 bytes
// Khung tháo gỡ #0133 | Địa chỉ PC: 0x0428e4 | Địa chỉ FDE: 0x1ad698 | Kích thước: 256 bytes
//   0x0428e4: F81B0FFC  str      x28, [sp, #-0x50]!
//   0x0428e8: A9015FF8  stp      x24, x23, [sp, #0x10]
//   0x0428ec: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x0428f0: A9034FF4  stp      x20, x19, [sp, #0x30]
static inline uint64_t fde_func_0133_0x0428e4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0428e4ULL ^ (static_cast<uint64_t>(0xf81b0ffcULL) << 13);
    acc = (acc + a1 + 0xa9015ff8ULL) ^ 0x1ad698ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0134 | PC: 0x045b74 | FDE: 0x1af710 | Size: 256 bytes
// Khung tháo gỡ #0134 | Địa chỉ PC: 0x045b74 | Địa chỉ FDE: 0x1af710 | Kích thước: 256 bytes
//   0x045b74: D104C3FF  sub      sp, sp, #0x130
//   0x045b78: A90D6FFC  stp      x28, x27, [sp, #0xd0]
//   0x045b7c: A90E67FA  stp      x26, x25, [sp, #0xe0]
//   0x045b80: A90F5FF8  stp      x24, x23, [sp, #0xf0]
static inline uint64_t fde_func_0134_0x045b74(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x045b74ULL ^ (static_cast<uint64_t>(0xd104c3ffULL) << 13);
    acc = (acc + a1 + 0xa90d6ffcULL) ^ 0x1af710ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0135 | PC: 0x045ea4 | FDE: 0x1af828 | Size: 256 bytes
// Khung tháo gỡ #0135 | Địa chỉ PC: 0x045ea4 | Địa chỉ FDE: 0x1af828 | Kích thước: 256 bytes
//   0x045ea4: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x045ea8: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x045eac: 910043FD  add      x29, sp, #0x10
//   0x045eb0: B0000CF3  adrp     x19, #0x1e2000
static inline uint64_t fde_func_0135_0x045ea4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x045ea4ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1af828ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0136 | PC: 0x0460e0 | FDE: 0x1af878 | Size: 256 bytes
// Khung tháo gỡ #0136 | Địa chỉ PC: 0x0460e0 | Địa chỉ FDE: 0x1af878 | Kích thước: 256 bytes
//   0x0460e0: D10283FF  sub      sp, sp, #0xa0
//   0x0460e4: A9065FF8  stp      x24, x23, [sp, #0x60]
//   0x0460e8: A90757F6  stp      x22, x21, [sp, #0x70]
//   0x0460ec: A9084FF4  stp      x20, x19, [sp, #0x80]
static inline uint64_t fde_func_0136_0x0460e0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0460e0ULL ^ (static_cast<uint64_t>(0xd10283ffULL) << 13);
    acc = (acc + a1 + 0xa9065ff8ULL) ^ 0x1af878ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0137 | PC: 0x046344 | FDE: 0x1afb88 | Size: 256 bytes
// Khung tháo gỡ #0137 | Địa chỉ PC: 0x046344 | Địa chỉ FDE: 0x1afb88 | Kích thước: 256 bytes
//   0x046344: D104C3FF  sub      sp, sp, #0x130
//   0x046348: A90D6FFC  stp      x28, x27, [sp, #0xd0]
//   0x04634c: A90E67FA  stp      x26, x25, [sp, #0xe0]
//   0x046350: A90F5FF8  stp      x24, x23, [sp, #0xf0]
static inline uint64_t fde_func_0137_0x046344(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x046344ULL ^ (static_cast<uint64_t>(0xd104c3ffULL) << 13);
    acc = (acc + a1 + 0xa90d6ffcULL) ^ 0x1afb88ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0138 | PC: 0x046674 | FDE: 0x1afc70 | Size: 256 bytes
// Khung tháo gỡ #0138 | Địa chỉ PC: 0x046674 | Địa chỉ FDE: 0x1afc70 | Kích thước: 256 bytes
//   0x046674: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x046678: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x04667c: 910043FD  add      x29, sp, #0x10
//   0x046680: 90000CF3  adrp     x19, #0x1e2000
static inline uint64_t fde_func_0138_0x046674(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x046674ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1afc70ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0139 | PC: 0x0468b0 | FDE: 0x1afcc0 | Size: 256 bytes
// Khung tháo gỡ #0139 | Địa chỉ PC: 0x0468b0 | Địa chỉ FDE: 0x1afcc0 | Kích thước: 256 bytes
//   0x0468b0: D10283FF  sub      sp, sp, #0xa0
//   0x0468b4: A9065FF8  stp      x24, x23, [sp, #0x60]
//   0x0468b8: A90757F6  stp      x22, x21, [sp, #0x70]
//   0x0468bc: A9084FF4  stp      x20, x19, [sp, #0x80]
static inline uint64_t fde_func_0139_0x0468b0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0468b0ULL ^ (static_cast<uint64_t>(0xd10283ffULL) << 13);
    acc = (acc + a1 + 0xa9065ff8ULL) ^ 0x1afcc0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0140 | PC: 0x046a34 | FDE: 0x1b0098 | Size: 256 bytes
// Khung tháo gỡ #0140 | Địa chỉ PC: 0x046a34 | Địa chỉ FDE: 0x1b0098 | Kích thước: 256 bytes
//   0x046a34: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x046a38: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x046a3c: 910043FD  add      x29, sp, #0x10
//   0x046a40: 90000CF3  adrp     x19, #0x1e2000
static inline uint64_t fde_func_0140_0x046a34(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x046a34ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1b0098ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0141 | PC: 0x046c70 | FDE: 0x1b00e8 | Size: 256 bytes
// Khung tháo gỡ #0141 | Địa chỉ PC: 0x046c70 | Địa chỉ FDE: 0x1b00e8 | Kích thước: 256 bytes
//   0x046c70: D10283FF  sub      sp, sp, #0xa0
//   0x046c74: A9065FF8  stp      x24, x23, [sp, #0x60]
//   0x046c78: A90757F6  stp      x22, x21, [sp, #0x70]
//   0x046c7c: A9084FF4  stp      x20, x19, [sp, #0x80]
static inline uint64_t fde_func_0141_0x046c70(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x046c70ULL ^ (static_cast<uint64_t>(0xd10283ffULL) << 13);
    acc = (acc + a1 + 0xa9065ff8ULL) ^ 0x1b00e8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0142 | PC: 0x046df4 | FDE: 0x1b0690 | Size: 256 bytes
// Khung tháo gỡ #0142 | Địa chỉ PC: 0x046df4 | Địa chỉ FDE: 0x1b0690 | Kích thước: 256 bytes
//   0x046df4: D104C3FF  sub      sp, sp, #0x130
//   0x046df8: A90D6FFC  stp      x28, x27, [sp, #0xd0]
//   0x046dfc: A90E67FA  stp      x26, x25, [sp, #0xe0]
//   0x046e00: A90F5FF8  stp      x24, x23, [sp, #0xf0]
static inline uint64_t fde_func_0142_0x046df4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x046df4ULL ^ (static_cast<uint64_t>(0xd104c3ffULL) << 13);
    acc = (acc + a1 + 0xa90d6ffcULL) ^ 0x1b0690ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0143 | PC: 0x047124 | FDE: 0x1b0a60 | Size: 256 bytes
// Khung tháo gỡ #0143 | Địa chỉ PC: 0x047124 | Địa chỉ FDE: 0x1b0a60 | Kích thước: 256 bytes
//   0x047124: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x047128: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x04712c: 910043FD  add      x29, sp, #0x10
//   0x047130: F0000CD3  adrp     x19, #0x1e2000
static inline uint64_t fde_func_0143_0x047124(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x047124ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1b0a60ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0144 | PC: 0x047360 | FDE: 0x1b0dc8 | Size: 256 bytes
// Khung tháo gỡ #0144 | Địa chỉ PC: 0x047360 | Địa chỉ FDE: 0x1b0dc8 | Kích thước: 256 bytes
//   0x047360: D10283FF  sub      sp, sp, #0xa0
//   0x047364: A9065FF8  stp      x24, x23, [sp, #0x60]
//   0x047368: A90757F6  stp      x22, x21, [sp, #0x70]
//   0x04736c: A9084FF4  stp      x20, x19, [sp, #0x80]
static inline uint64_t fde_func_0144_0x047360(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x047360ULL ^ (static_cast<uint64_t>(0xd10283ffULL) << 13);
    acc = (acc + a1 + 0xa9065ff8ULL) ^ 0x1b0dc8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0145 | PC: 0x0474e4 | FDE: 0x1b1198 | Size: 256 bytes
// Khung tháo gỡ #0145 | Địa chỉ PC: 0x0474e4 | Địa chỉ FDE: 0x1b1198 | Kích thước: 256 bytes
//   0x0474e4: D104C3FF  sub      sp, sp, #0x130
//   0x0474e8: A90D6FFC  stp      x28, x27, [sp, #0xd0]
//   0x0474ec: A90E67FA  stp      x26, x25, [sp, #0xe0]
//   0x0474f0: A90F5FF8  stp      x24, x23, [sp, #0xf0]
static inline uint64_t fde_func_0145_0x0474e4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0474e4ULL ^ (static_cast<uint64_t>(0xd104c3ffULL) << 13);
    acc = (acc + a1 + 0xa90d6ffcULL) ^ 0x1b1198ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0146 | PC: 0x047814 | FDE: 0x1b1368 | Size: 256 bytes
// Khung tháo gỡ #0146 | Địa chỉ PC: 0x047814 | Địa chỉ FDE: 0x1b1368 | Kích thước: 256 bytes
//   0x047814: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x047818: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x04781c: 910043FD  add      x29, sp, #0x10
//   0x047820: F0000CD3  adrp     x19, #0x1e2000
static inline uint64_t fde_func_0146_0x047814(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x047814ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1b1368ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0147 | PC: 0x047a50 | FDE: 0x1b13b8 | Size: 256 bytes
// Khung tháo gỡ #0147 | Địa chỉ PC: 0x047a50 | Địa chỉ FDE: 0x1b13b8 | Kích thước: 256 bytes
//   0x047a50: D10283FF  sub      sp, sp, #0xa0
//   0x047a54: A9065FF8  stp      x24, x23, [sp, #0x60]
//   0x047a58: A90757F6  stp      x22, x21, [sp, #0x70]
//   0x047a5c: A9084FF4  stp      x20, x19, [sp, #0x80]
static inline uint64_t fde_func_0147_0x047a50(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x047a50ULL ^ (static_cast<uint64_t>(0xd10283ffULL) << 13);
    acc = (acc + a1 + 0xa9065ff8ULL) ^ 0x1b13b8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0148 | PC: 0x047ddc | FDE: 0x1b1758 | Size: 200 bytes
// Khung tháo gỡ #0148 | Địa chỉ PC: 0x047ddc | Địa chỉ FDE: 0x1b1758 | Kích thước: 200 bytes
//   0x047ddc: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x047de0: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x047de4: 910043FD  add      x29, sp, #0x10
//   0x047de8: 90000CF3  adrp     x19, #0x1e3000
static inline uint64_t fde_func_0148_0x047ddc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x047ddcULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1b1758ULL;
    acc ^= (acc >> 17) * 0x00c8ULL;
    return acc;
}

// FDE #0149 | PC: 0x047ea4 | FDE: 0x1b1948 | Size: 144 bytes
// Khung tháo gỡ #0149 | Địa chỉ PC: 0x047ea4 | Địa chỉ FDE: 0x1b1948 | Kích thước: 144 bytes
//   0x047ea4: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x047ea8: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x047eac: 910043FD  add      x29, sp, #0x10
//   0x047eb0: 90000CF3  adrp     x19, #0x1e3000
static inline uint64_t fde_func_0149_0x047ea4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x047ea4ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1b1948ULL;
    acc ^= (acc >> 17) * 0x0090ULL;
    return acc;
}

// FDE #0150 | PC: 0x047f34 | FDE: 0x1b1ad8 | Size: 256 bytes
// Khung tháo gỡ #0150 | Địa chỉ PC: 0x047f34 | Địa chỉ FDE: 0x1b1ad8 | Kích thước: 256 bytes
//   0x047f34: D104C3FF  sub      sp, sp, #0x130
//   0x047f38: A90D6FFC  stp      x28, x27, [sp, #0xd0]
//   0x047f3c: A90E67FA  stp      x26, x25, [sp, #0xe0]
//   0x047f40: A90F5FF8  stp      x24, x23, [sp, #0xf0]
static inline uint64_t fde_func_0150_0x047f34(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x047f34ULL ^ (static_cast<uint64_t>(0xd104c3ffULL) << 13);
    acc = (acc + a1 + 0xa90d6ffcULL) ^ 0x1b1ad8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0151 | PC: 0x048264 | FDE: 0x1b25e8 | Size: 256 bytes
// Khung tháo gỡ #0151 | Địa chỉ PC: 0x048264 | Địa chỉ FDE: 0x1b25e8 | Kích thước: 256 bytes
//   0x048264: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x048268: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x04826c: 910043FD  add      x29, sp, #0x10
//   0x048270: F0000CD3  adrp     x19, #0x1e3000
static inline uint64_t fde_func_0151_0x048264(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x048264ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1b25e8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0152 | PC: 0x048370 | FDE: 0x1b2850 | Size: 144 bytes
// Khung tháo gỡ #0152 | Địa chỉ PC: 0x048370 | Địa chỉ FDE: 0x1b2850 | Kích thước: 144 bytes
//   0x048370: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x048374: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x048378: 910043FD  add      x29, sp, #0x10
//   0x04837c: F0000CD3  adrp     x19, #0x1e3000
static inline uint64_t fde_func_0152_0x048370(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x048370ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1b2850ULL;
    acc ^= (acc >> 17) * 0x0090ULL;
    return acc;
}

// FDE #0153 | PC: 0x048400 | FDE: 0x1b2a10 | Size: 144 bytes
// Khung tháo gỡ #0153 | Địa chỉ PC: 0x048400 | Địa chỉ FDE: 0x1b2a10 | Kích thước: 144 bytes
//   0x048400: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x048404: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x048408: 910043FD  add      x29, sp, #0x10
//   0x04840c: F0000CD3  adrp     x19, #0x1e3000
static inline uint64_t fde_func_0153_0x048400(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x048400ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1b2a10ULL;
    acc ^= (acc >> 17) * 0x0090ULL;
    return acc;
}

// FDE #0154 | PC: 0x048490 | FDE: 0x1b2ce8 | Size: 144 bytes
// Khung tháo gỡ #0154 | Địa chỉ PC: 0x048490 | Địa chỉ FDE: 0x1b2ce8 | Kích thước: 144 bytes
//   0x048490: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x048494: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x048498: 910043FD  add      x29, sp, #0x10
//   0x04849c: F0000CD3  adrp     x19, #0x1e3000
static inline uint64_t fde_func_0154_0x048490(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x048490ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1b2ce8ULL;
    acc ^= (acc >> 17) * 0x0090ULL;
    return acc;
}

// FDE #0155 | PC: 0x048520 | FDE: 0x1b2ef8 | Size: 144 bytes
// Khung tháo gỡ #0155 | Địa chỉ PC: 0x048520 | Địa chỉ FDE: 0x1b2ef8 | Kích thước: 144 bytes
//   0x048520: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x048524: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x048528: 910043FD  add      x29, sp, #0x10
//   0x04852c: F0000CD3  adrp     x19, #0x1e3000
static inline uint64_t fde_func_0155_0x048520(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x048520ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1b2ef8ULL;
    acc ^= (acc >> 17) * 0x0090ULL;
    return acc;
}

// FDE #0156 | PC: 0x0485b0 | FDE: 0x1b31a8 | Size: 144 bytes
// Khung tháo gỡ #0156 | Địa chỉ PC: 0x0485b0 | Địa chỉ FDE: 0x1b31a8 | Kích thước: 144 bytes
//   0x0485b0: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x0485b4: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0485b8: 910043FD  add      x29, sp, #0x10
//   0x0485bc: F0000CD3  adrp     x19, #0x1e3000
static inline uint64_t fde_func_0156_0x0485b0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0485b0ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1b31a8ULL;
    acc ^= (acc >> 17) * 0x0090ULL;
    return acc;
}

// FDE #0157 | PC: 0x048640 | FDE: 0x1b37b0 | Size: 256 bytes
// Khung tháo gỡ #0157 | Địa chỉ PC: 0x048640 | Địa chỉ FDE: 0x1b37b0 | Kích thước: 256 bytes
//   0x048640: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x048644: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x048648: 910043FD  add      x29, sp, #0x10
//   0x04864c: 90000CF3  adrp     x19, #0x1e4000
static inline uint64_t fde_func_0157_0x048640(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x048640ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1b37b0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0158 | PC: 0x04887c | FDE: 0x1b3800 | Size: 256 bytes
// Khung tháo gỡ #0158 | Địa chỉ PC: 0x04887c | Địa chỉ FDE: 0x1b3800 | Kích thước: 256 bytes
//   0x04887c: D10283FF  sub      sp, sp, #0xa0
//   0x048880: A9065FF8  stp      x24, x23, [sp, #0x60]
//   0x048884: A90757F6  stp      x22, x21, [sp, #0x70]
//   0x048888: A9084FF4  stp      x20, x19, [sp, #0x80]
static inline uint64_t fde_func_0158_0x04887c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x04887cULL ^ (static_cast<uint64_t>(0xd10283ffULL) << 13);
    acc = (acc + a1 + 0xa9065ff8ULL) ^ 0x1b3800ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0159 | PC: 0x048a00 | FDE: 0x1b3ab8 | Size: 256 bytes
// Khung tháo gỡ #0159 | Địa chỉ PC: 0x048a00 | Địa chỉ FDE: 0x1b3ab8 | Kích thước: 256 bytes
//   0x048a00: D104C3FF  sub      sp, sp, #0x130
//   0x048a04: A90D6FFC  stp      x28, x27, [sp, #0xd0]
//   0x048a08: A90E67FA  stp      x26, x25, [sp, #0xe0]
//   0x048a0c: A90F5FF8  stp      x24, x23, [sp, #0xf0]
static inline uint64_t fde_func_0159_0x048a00(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x048a00ULL ^ (static_cast<uint64_t>(0xd104c3ffULL) << 13);
    acc = (acc + a1 + 0xa90d6ffcULL) ^ 0x1b3ab8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0160 | PC: 0x048d30 | FDE: 0x1b3bb0 | Size: 256 bytes
// Khung tháo gỡ #0160 | Địa chỉ PC: 0x048d30 | Địa chỉ FDE: 0x1b3bb0 | Kích thước: 256 bytes
//   0x048d30: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x048d34: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x048d38: 910043FD  add      x29, sp, #0x10
//   0x048d3c: 90000CF3  adrp     x19, #0x1e4000
static inline uint64_t fde_func_0160_0x048d30(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x048d30ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1b3bb0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0161 | PC: 0x048f6c | FDE: 0x1b3c00 | Size: 256 bytes
// Khung tháo gỡ #0161 | Địa chỉ PC: 0x048f6c | Địa chỉ FDE: 0x1b3c00 | Kích thước: 256 bytes
//   0x048f6c: D10283FF  sub      sp, sp, #0xa0
//   0x048f70: A9065FF8  stp      x24, x23, [sp, #0x60]
//   0x048f74: A90757F6  stp      x22, x21, [sp, #0x70]
//   0x048f78: A9084FF4  stp      x20, x19, [sp, #0x80]
static inline uint64_t fde_func_0161_0x048f6c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x048f6cULL ^ (static_cast<uint64_t>(0xd10283ffULL) << 13);
    acc = (acc + a1 + 0xa9065ff8ULL) ^ 0x1b3c00ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0162 | PC: 0x0490f0 | FDE: 0x1b3ef8 | Size: 256 bytes
// Khung tháo gỡ #0162 | Địa chỉ PC: 0x0490f0 | Địa chỉ FDE: 0x1b3ef8 | Kích thước: 256 bytes
//   0x0490f0: D104C3FF  sub      sp, sp, #0x130
//   0x0490f4: A90D6FFC  stp      x28, x27, [sp, #0xd0]
//   0x0490f8: A90E67FA  stp      x26, x25, [sp, #0xe0]
//   0x0490fc: A90F5FF8  stp      x24, x23, [sp, #0xf0]
static inline uint64_t fde_func_0162_0x0490f0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0490f0ULL ^ (static_cast<uint64_t>(0xd104c3ffULL) << 13);
    acc = (acc + a1 + 0xa90d6ffcULL) ^ 0x1b3ef8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0163 | PC: 0x049420 | FDE: 0x1b4028 | Size: 256 bytes
// Khung tháo gỡ #0163 | Địa chỉ PC: 0x049420 | Địa chỉ FDE: 0x1b4028 | Kích thước: 256 bytes
//   0x049420: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x049424: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x049428: 910043FD  add      x29, sp, #0x10
//   0x04942c: F0000CD3  adrp     x19, #0x1e4000
static inline uint64_t fde_func_0163_0x049420(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x049420ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1b4028ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0164 | PC: 0x04965c | FDE: 0x1b4078 | Size: 256 bytes
// Khung tháo gỡ #0164 | Địa chỉ PC: 0x04965c | Địa chỉ FDE: 0x1b4078 | Kích thước: 256 bytes
//   0x04965c: D10283FF  sub      sp, sp, #0xa0
//   0x049660: A9065FF8  stp      x24, x23, [sp, #0x60]
//   0x049664: A90757F6  stp      x22, x21, [sp, #0x70]
//   0x049668: A9084FF4  stp      x20, x19, [sp, #0x80]
static inline uint64_t fde_func_0164_0x04965c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x04965cULL ^ (static_cast<uint64_t>(0xd10283ffULL) << 13);
    acc = (acc + a1 + 0xa9065ff8ULL) ^ 0x1b4078ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0165 | PC: 0x0497e0 | FDE: 0x1b4258 | Size: 256 bytes
// Khung tháo gỡ #0165 | Địa chỉ PC: 0x0497e0 | Địa chỉ FDE: 0x1b4258 | Kích thước: 256 bytes
//   0x0497e0: D104C3FF  sub      sp, sp, #0x130
//   0x0497e4: A90D6FFC  stp      x28, x27, [sp, #0xd0]
//   0x0497e8: A90E67FA  stp      x26, x25, [sp, #0xe0]
//   0x0497ec: A90F5FF8  stp      x24, x23, [sp, #0xf0]
static inline uint64_t fde_func_0165_0x0497e0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0497e0ULL ^ (static_cast<uint64_t>(0xd104c3ffULL) << 13);
    acc = (acc + a1 + 0xa90d6ffcULL) ^ 0x1b4258ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0166 | PC: 0x049b10 | FDE: 0x1b4578 | Size: 256 bytes
// Khung tháo gỡ #0166 | Địa chỉ PC: 0x049b10 | Địa chỉ FDE: 0x1b4578 | Kích thước: 256 bytes
//   0x049b10: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x049b14: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x049b18: 910043FD  add      x29, sp, #0x10
//   0x049b1c: F0000CD3  adrp     x19, #0x1e4000
static inline uint64_t fde_func_0166_0x049b10(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x049b10ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1b4578ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0167 | PC: 0x049d4c | FDE: 0x1b45e0 | Size: 256 bytes
// Khung tháo gỡ #0167 | Địa chỉ PC: 0x049d4c | Địa chỉ FDE: 0x1b45e0 | Kích thước: 256 bytes
//   0x049d4c: D10283FF  sub      sp, sp, #0xa0
//   0x049d50: A9065FF8  stp      x24, x23, [sp, #0x60]
//   0x049d54: A90757F6  stp      x22, x21, [sp, #0x70]
//   0x049d58: A9084FF4  stp      x20, x19, [sp, #0x80]
static inline uint64_t fde_func_0167_0x049d4c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x049d4cULL ^ (static_cast<uint64_t>(0xd10283ffULL) << 13);
    acc = (acc + a1 + 0xa9065ff8ULL) ^ 0x1b45e0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0168 | PC: 0x049ed0 | FDE: 0x1b47d8 | Size: 256 bytes
// Khung tháo gỡ #0168 | Địa chỉ PC: 0x049ed0 | Địa chỉ FDE: 0x1b47d8 | Kích thước: 256 bytes
//   0x049ed0: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x049ed4: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x049ed8: 910043FD  add      x29, sp, #0x10
//   0x049edc: F0000CD3  adrp     x19, #0x1e4000
static inline uint64_t fde_func_0168_0x049ed0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x049ed0ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1b47d8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0169 | PC: 0x04a10c | FDE: 0x1b4828 | Size: 256 bytes
// Khung tháo gỡ #0169 | Địa chỉ PC: 0x04a10c | Địa chỉ FDE: 0x1b4828 | Kích thước: 256 bytes
//   0x04a10c: D10283FF  sub      sp, sp, #0xa0
//   0x04a110: A9065FF8  stp      x24, x23, [sp, #0x60]
//   0x04a114: A90757F6  stp      x22, x21, [sp, #0x70]
//   0x04a118: A9084FF4  stp      x20, x19, [sp, #0x80]
static inline uint64_t fde_func_0169_0x04a10c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x04a10cULL ^ (static_cast<uint64_t>(0xd10283ffULL) << 13);
    acc = (acc + a1 + 0xa9065ff8ULL) ^ 0x1b4828ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0170 | PC: 0x04a290 | FDE: 0x1b4958 | Size: 144 bytes
// Khung tháo gỡ #0170 | Địa chỉ PC: 0x04a290 | Địa chỉ FDE: 0x1b4958 | Kích thước: 144 bytes
//   0x04a290: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x04a294: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x04a298: 910043FD  add      x29, sp, #0x10
//   0x04a29c: D0000CD3  adrp     x19, #0x1e4000
static inline uint64_t fde_func_0170_0x04a290(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x04a290ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1b4958ULL;
    acc ^= (acc >> 17) * 0x0090ULL;
    return acc;
}

// FDE #0171 | PC: 0x04a320 | FDE: 0x1b4ee8 | Size: 256 bytes
// Khung tháo gỡ #0171 | Địa chỉ PC: 0x04a320 | Địa chỉ FDE: 0x1b4ee8 | Kích thước: 256 bytes
//   0x04a320: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x04a324: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x04a328: 910043FD  add      x29, sp, #0x10
//   0x04a32c: D0000CD3  adrp     x19, #0x1e4000
static inline uint64_t fde_func_0171_0x04a320(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x04a320ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1b4ee8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0172 | PC: 0x04a578 | FDE: 0x1b4f38 | Size: 256 bytes
// Khung tháo gỡ #0172 | Địa chỉ PC: 0x04a578 | Địa chỉ FDE: 0x1b4f38 | Kích thước: 256 bytes
//   0x04a578: D10283FF  sub      sp, sp, #0xa0
//   0x04a57c: A9065FF8  stp      x24, x23, [sp, #0x60]
//   0x04a580: A90757F6  stp      x22, x21, [sp, #0x70]
//   0x04a584: A9084FF4  stp      x20, x19, [sp, #0x80]
static inline uint64_t fde_func_0172_0x04a578(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x04a578ULL ^ (static_cast<uint64_t>(0xd10283ffULL) << 13);
    acc = (acc + a1 + 0xa9065ff8ULL) ^ 0x1b4f38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0173 | PC: 0x04a86c | FDE: 0x1b6b60 | Size: 256 bytes
// Khung tháo gỡ #0173 | Địa chỉ PC: 0x04a86c | Địa chỉ FDE: 0x1b6b60 | Kích thước: 256 bytes
//   0x04a86c: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x04a870: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x04a874: 910043FD  add      x29, sp, #0x10
//   0x04a878: D0000CD3  adrp     x19, #0x1e4000
static inline uint64_t fde_func_0173_0x04a86c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x04a86cULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1b6b60ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0174 | PC: 0x04aabc | FDE: 0x195888 | Size: 36 bytes
// Khung tháo gỡ #0174 | Địa chỉ PC: 0x04aabc | Địa chỉ FDE: 0x195888 | Kích thước: 36 bytes
//   0x04aabc: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x04aac0: 910003FD  mov      x29, sp
//   0x04aac4: F9400401  ldr      x1, [x0, #8]
//   0x04aac8: 9400079A  bl       #0x4c930
static inline uint64_t fde_func_0174_0x04aabc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x04aabcULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x195888ULL;
    acc ^= (acc >> 17) * 0x0024ULL;
    return acc;
}

// FDE #0175 | PC: 0x04aae0 | FDE: 0x1958d0 | Size: 256 bytes [JNI_OnLoad]
// Khung tháo gỡ #0175 | Địa chỉ PC: 0x04aae0 | Địa chỉ FDE: 0x1958d0 | Kích thước: 256 bytes
//   0x04aae0: A9BA6FFC  stp      x28, x27, [sp, #-0x60]!
//   0x04aae4: A90167FA  stp      x26, x25, [sp, #0x10]
//   0x04aae8: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x04aaec: A90357F6  stp      x22, x21, [sp, #0x30]
static inline uint64_t fde_func_0175_0x04aae0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x04aae0ULL ^ (static_cast<uint64_t>(0xa9ba6ffcULL) << 13);
    acc = (acc + a1 + 0xa90167faULL) ^ 0x1958d0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0176 | PC: 0x04bd90 | FDE: 0x195900 | Size: 256 bytes
// Khung tháo gỡ #0176 | Địa chỉ PC: 0x04bd90 | Địa chỉ FDE: 0x195900 | Kích thước: 256 bytes
//   0x04bd90: D10183FF  sub      sp, sp, #0x60
//   0x04bd94: F90013F7  str      x23, [sp, #0x20]
//   0x04bd98: A90357F6  stp      x22, x21, [sp, #0x30]
//   0x04bd9c: A9044FF4  stp      x20, x19, [sp, #0x40]
static inline uint64_t fde_func_0176_0x04bd90(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x04bd90ULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xf90013f7ULL) ^ 0x195900ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0177 | PC: 0x04c45c | FDE: 0x195948 | Size: 256 bytes
// Khung tháo gỡ #0177 | Địa chỉ PC: 0x04c45c | Địa chỉ FDE: 0x195948 | Kích thước: 256 bytes
//   0x04c45c: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x04c460: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x04c464: 910043FD  add      x29, sp, #0x10
//   0x04c468: F0000C68  adrp     x8, #0x1db000
static inline uint64_t fde_func_0177_0x04c45c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x04c45cULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x195948ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0178 | PC: 0x04c564 | FDE: 0x195988 | Size: 256 bytes
// Khung tháo gỡ #0178 | Địa chỉ PC: 0x04c564 | Địa chỉ FDE: 0x195988 | Kích thước: 256 bytes
//   0x04c564: F81B0FF9  str      x25, [sp, #-0x50]!
//   0x04c568: A9015FF8  stp      x24, x23, [sp, #0x10]
//   0x04c56c: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x04c570: A9034FF4  stp      x20, x19, [sp, #0x30]
static inline uint64_t fde_func_0178_0x04c564(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x04c564ULL ^ (static_cast<uint64_t>(0xf81b0ff9ULL) << 13);
    acc = (acc + a1 + 0xa9015ff8ULL) ^ 0x195988ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0179 | PC: 0x04c930 | FDE: 0x1959c8 | Size: 92 bytes
// Khung tháo gỡ #0179 | Địa chỉ PC: 0x04c930 | Địa chỉ FDE: 0x1959c8 | Kích thước: 92 bytes
//   0x04c930: B4000221  cbz      x1, #0x4c974
//   0x04c934: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x04c938: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x04c93c: 910043FD  add      x29, sp, #0x10
static inline uint64_t fde_func_0179_0x04c930(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x04c930ULL ^ (static_cast<uint64_t>(0xb4000221ULL) << 13);
    acc = (acc + a1 + 0xa9be4ff4ULL) ^ 0x1959c8ULL;
    acc ^= (acc >> 17) * 0x005cULL;
    return acc;
}

// FDE #0180 | PC: 0x04c98c | FDE: 0x195a78 | Size: 200 bytes
// Khung tháo gỡ #0180 | Địa chỉ PC: 0x04c98c | Địa chỉ FDE: 0x195a78 | Kích thước: 200 bytes
//   0x04c98c: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x04c990: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x04c994: 910043FD  add      x29, sp, #0x10
//   0x04c998: 90000001  adrp     x1, #0x4c000
static inline uint64_t fde_func_0180_0x04c98c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x04c98cULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x195a78ULL;
    acc ^= (acc >> 17) * 0x00c8ULL;
    return acc;
}

// FDE #0181 | PC: 0x04ca54 | FDE: 0x195ab8 | Size: 256 bytes
// Khung tháo gỡ #0181 | Địa chỉ PC: 0x04ca54 | Địa chỉ FDE: 0x195ab8 | Kích thước: 256 bytes
//   0x04ca54: D10103FF  sub      sp, sp, #0x40
//   0x04ca58: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x04ca5c: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x04ca60: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_0181_0x04ca54(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x04ca54ULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x195ab8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0182 | PC: 0x04d214 | FDE: 0x195b08 | Size: 244 bytes
// Khung tháo gỡ #0182 | Địa chỉ PC: 0x04d214 | Địa chỉ FDE: 0x195b08 | Kích thước: 244 bytes
//   0x04d214: D10143FF  sub      sp, sp, #0x50
//   0x04d218: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x04d21c: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x04d220: A9047BFD  stp      x29, x30, [sp, #0x40]
static inline uint64_t fde_func_0182_0x04d214(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x04d214ULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xa90257f6ULL) ^ 0x195b08ULL;
    acc ^= (acc >> 17) * 0x00f4ULL;
    return acc;
}

// FDE #0183 | PC: 0x04d308 | FDE: 0x195b48 | Size: 24 bytes
// Khung tháo gỡ #0183 | Địa chỉ PC: 0x04d308 | Địa chỉ FDE: 0x195b48 | Kích thước: 24 bytes
//   0x04d308: B0000000  adrp     x0, #0x4e000
//   0x04d30c: 91029000  add      x0, x0, #0xa4
//   0x04d310: D65F03C0  ret      
//   0x04d314: B0000000  adrp     x0, #0x4e000
static inline uint64_t fde_func_0183_0x04d308(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x04d308ULL ^ (static_cast<uint64_t>(0xb0000000ULL) << 13);
    acc = (acc + a1 + 0x91029000ULL) ^ 0x195b48ULL;
    acc ^= (acc >> 17) * 0x0018ULL;
    return acc;
}

// FDE #0184 | PC: 0x04d320 | FDE: 0x195b78 | Size: 256 bytes
// Khung tháo gỡ #0184 | Địa chỉ PC: 0x04d320 | Địa chỉ FDE: 0x195b78 | Kích thước: 256 bytes
//   0x04d320: D0000000  adrp     x0, #0x4f000
//   0x04d324: 91000000  add      x0, x0, #0
//   0x04d328: D65F03C0  ret      
//   0x04d32c: F81A0FFC  str      x28, [sp, #-0x60]!
static inline uint64_t fde_func_0184_0x04d320(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x04d320ULL ^ (static_cast<uint64_t>(0xd0000000ULL) << 13);
    acc = (acc + a1 + 0x91000000ULL) ^ 0x195b78ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0185 | PC: 0x04dad4 | FDE: 0x195bc0 | Size: 256 bytes
// Khung tháo gỡ #0185 | Địa chỉ PC: 0x04dad4 | Địa chỉ FDE: 0x195bc0 | Kích thước: 256 bytes
//   0x04dad4: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x04dad8: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x04dadc: 910043FD  add      x29, sp, #0x10
//   0x04dae0: F9406C01  ldr      x1, [x0, #0xd8]
static inline uint64_t fde_func_0185_0x04dad4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x04dad4ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x195bc0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0186 | PC: 0x04dc78 | FDE: 0x195c08 | Size: 256 bytes
// Khung tháo gỡ #0186 | Địa chỉ PC: 0x04dc78 | Địa chỉ FDE: 0x195c08 | Kích thước: 256 bytes
//   0x04dc78: D10243FF  sub      sp, sp, #0x90
//   0x04dc7c: A9036FFC  stp      x28, x27, [sp, #0x30]
//   0x04dc80: A90467FA  stp      x26, x25, [sp, #0x40]
//   0x04dc84: A9055FF8  stp      x24, x23, [sp, #0x50]
static inline uint64_t fde_func_0186_0x04dc78(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x04dc78ULL ^ (static_cast<uint64_t>(0xd10243ffULL) << 13);
    acc = (acc + a1 + 0xa9036ffcULL) ^ 0x195c08ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0187 | PC: 0x04decc | FDE: 0x195c58 | Size: 256 bytes
// Khung tháo gỡ #0187 | Địa chỉ PC: 0x04decc | Địa chỉ FDE: 0x195c58 | Kích thước: 256 bytes
//   0x04decc: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x04ded0: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x04ded4: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x04ded8: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0187_0x04decc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x04deccULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x195c58ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0188 | PC: 0x04e05c | FDE: 0x195ca8 | Size: 256 bytes
// Khung tháo gỡ #0188 | Địa chỉ PC: 0x04e05c | Địa chỉ FDE: 0x195ca8 | Kích thước: 256 bytes
//   0x04e05c: B4000221  cbz      x1, #0x4e0a0
//   0x04e060: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x04e064: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x04e068: 910043FD  add      x29, sp, #0x10
static inline uint64_t fde_func_0188_0x04e05c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x04e05cULL ^ (static_cast<uint64_t>(0xb4000221ULL) << 13);
    acc = (acc + a1 + 0xa9be4ff4ULL) ^ 0x195ca8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0189 | PC: 0x04e1d0 | FDE: 0x195ce8 | Size: 256 bytes
// Khung tháo gỡ #0189 | Địa chỉ PC: 0x04e1d0 | Địa chỉ FDE: 0x195ce8 | Kích thước: 256 bytes
//   0x04e1d0: D101C3FF  sub      sp, sp, #0x70
//   0x04e1d4: F90023F5  str      x21, [sp, #0x40]
//   0x04e1d8: A9054FF4  stp      x20, x19, [sp, #0x50]
//   0x04e1dc: A9067BFD  stp      x29, x30, [sp, #0x60]
static inline uint64_t fde_func_0189_0x04e1d0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x04e1d0ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xf90023f5ULL) ^ 0x195ce8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0190 | PC: 0x04e3f4 | FDE: 0x195d28 | Size: 256 bytes
// Khung tháo gỡ #0190 | Địa chỉ PC: 0x04e3f4 | Địa chỉ FDE: 0x195d28 | Kích thước: 256 bytes
//   0x04e3f4: D10303FF  sub      sp, sp, #0xc0
//   0x04e3f8: A9066FFC  stp      x28, x27, [sp, #0x60]
//   0x04e3fc: A90767FA  stp      x26, x25, [sp, #0x70]
//   0x04e400: A9085FF8  stp      x24, x23, [sp, #0x80]
static inline uint64_t fde_func_0190_0x04e3f4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x04e3f4ULL ^ (static_cast<uint64_t>(0xd10303ffULL) << 13);
    acc = (acc + a1 + 0xa9066ffcULL) ^ 0x195d28ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0191 | PC: 0x04ebb0 | FDE: 0x195d78 | Size: 256 bytes
// Khung tháo gỡ #0191 | Địa chỉ PC: 0x04ebb0 | Địa chỉ FDE: 0x195d78 | Kích thước: 256 bytes
//   0x04ebb0: D10443FF  sub      sp, sp, #0x110
//   0x04ebb4: A90F4FFC  stp      x28, x19, [sp, #0xf0]
//   0x04ebb8: A9107BFD  stp      x29, x30, [sp, #0x100]
//   0x04ebbc: 910403FD  add      x29, sp, #0x100
static inline uint64_t fde_func_0191_0x04ebb0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x04ebb0ULL ^ (static_cast<uint64_t>(0xd10443ffULL) << 13);
    acc = (acc + a1 + 0xa90f4ffcULL) ^ 0x195d78ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0192 | PC: 0x04ecc8 | FDE: 0x195db0 | Size: 256 bytes
// Khung tháo gỡ #0192 | Địa chỉ PC: 0x04ecc8 | Địa chỉ FDE: 0x195db0 | Kích thước: 256 bytes
//   0x04ecc8: D282080B  mov      x11, #0x1040
//   0x04eccc: D280800A  mov      x10, #0x400
//   0x04ecd0: F2A1404B  movk     x11, #0xa02, lsl #16
//   0x04ecd4: 90000009  adrp     x9, #0x4e000
static inline uint64_t fde_func_0192_0x04ecc8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x04ecc8ULL ^ (static_cast<uint64_t>(0xd282080bULL) << 13);
    acc = (acc + a1 + 0xd280800aULL) ^ 0x195db0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0193 | PC: 0x04ef18 | FDE: 0x195df8 | Size: 232 bytes
// Khung tháo gỡ #0193 | Địa chỉ PC: 0x04ef18 | Địa chỉ FDE: 0x195df8 | Kích thước: 232 bytes
//   0x04ef18: D282080B  mov      x11, #0x1040
//   0x04ef1c: D280800A  mov      x10, #0x400
//   0x04ef20: F2A1404B  movk     x11, #0xa02, lsl #16
//   0x04ef24: 90000009  adrp     x9, #0x4e000
static inline uint64_t fde_func_0193_0x04ef18(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x04ef18ULL ^ (static_cast<uint64_t>(0xd282080bULL) << 13);
    acc = (acc + a1 + 0xd280800aULL) ^ 0x195df8ULL;
    acc ^= (acc >> 17) * 0x00e8ULL;
    return acc;
}

// FDE #0194 | PC: 0x04f000 | FDE: 0x195e28 | Size: 256 bytes
// Khung tháo gỡ #0194 | Địa chỉ PC: 0x04f000 | Địa chỉ FDE: 0x195e28 | Kích thước: 256 bytes
//   0x04f000: D10183FF  sub      sp, sp, #0x60
//   0x04f004: A9044FF4  stp      x20, x19, [sp, #0x40]
//   0x04f008: A9057BFD  stp      x29, x30, [sp, #0x50]
//   0x04f00c: 910143FD  add      x29, sp, #0x50
static inline uint64_t fde_func_0194_0x04f000(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x04f000ULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xa9044ff4ULL) ^ 0x195e28ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0195 | PC: 0x04f14c | FDE: 0x195e60 | Size: 24 bytes
// Khung tháo gỡ #0195 | Địa chỉ PC: 0x04f14c | Địa chỉ FDE: 0x195e60 | Kích thước: 24 bytes
//   0x04f14c: 90000000  adrp     x0, #0x4f000
//   0x04f150: 910AA000  add      x0, x0, #0x2a8
//   0x04f154: D65F03C0  ret      
//   0x04f158: 90000000  adrp     x0, #0x4f000
static inline uint64_t fde_func_0195_0x04f14c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x04f14cULL ^ (static_cast<uint64_t>(0x90000000ULL) << 13);
    acc = (acc + a1 + 0x910aa000ULL) ^ 0x195e60ULL;
    acc ^= (acc >> 17) * 0x0018ULL;
    return acc;
}

// FDE #0196 | PC: 0x04f164 | FDE: 0x195e90 | Size: 24 bytes
// Khung tháo gỡ #0196 | Địa chỉ PC: 0x04f164 | Địa chỉ FDE: 0x195e90 | Kích thước: 24 bytes
//   0x04f164: 90000000  adrp     x0, #0x4f000
//   0x04f168: 91100000  add      x0, x0, #0x400
//   0x04f16c: D65F03C0  ret      
//   0x04f170: 90000000  adrp     x0, #0x4f000
static inline uint64_t fde_func_0196_0x04f164(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x04f164ULL ^ (static_cast<uint64_t>(0x90000000ULL) << 13);
    acc = (acc + a1 + 0x91100000ULL) ^ 0x195e90ULL;
    acc ^= (acc >> 17) * 0x0018ULL;
    return acc;
}

// FDE #0197 | PC: 0x04f17c | FDE: 0x195ec0 | Size: 24 bytes
// Khung tháo gỡ #0197 | Địa chỉ PC: 0x04f17c | Địa chỉ FDE: 0x195ec0 | Kích thước: 24 bytes
//   0x04f17c: 90000000  adrp     x0, #0x4f000
//   0x04f180: 91156000  add      x0, x0, #0x558
//   0x04f184: D65F03C0  ret      
//   0x04f188: 90000000  adrp     x0, #0x4f000
static inline uint64_t fde_func_0197_0x04f17c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x04f17cULL ^ (static_cast<uint64_t>(0x90000000ULL) << 13);
    acc = (acc + a1 + 0x91156000ULL) ^ 0x195ec0ULL;
    acc ^= (acc >> 17) * 0x0018ULL;
    return acc;
}

// FDE #0198 | PC: 0x04f194 | FDE: 0x195ef0 | Size: 24 bytes
// Khung tháo gỡ #0198 | Địa chỉ PC: 0x04f194 | Địa chỉ FDE: 0x195ef0 | Kích thước: 24 bytes
//   0x04f194: 90000000  adrp     x0, #0x4f000
//   0x04f198: 911B7000  add      x0, x0, #0x6dc
//   0x04f19c: D65F03C0  ret      
//   0x04f1a0: 90000000  adrp     x0, #0x4f000
static inline uint64_t fde_func_0198_0x04f194(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x04f194ULL ^ (static_cast<uint64_t>(0x90000000ULL) << 13);
    acc = (acc + a1 + 0x911b7000ULL) ^ 0x195ef0ULL;
    acc ^= (acc >> 17) * 0x0018ULL;
    return acc;
}

// FDE #0199 | PC: 0x04f1ac | FDE: 0x195f20 | Size: 256 bytes
// Khung tháo gỡ #0199 | Địa chỉ PC: 0x04f1ac | Địa chỉ FDE: 0x195f20 | Kích thước: 256 bytes
//   0x04f1ac: D10183FF  sub      sp, sp, #0x60
//   0x04f1b0: F9001BF5  str      x21, [sp, #0x30]
//   0x04f1b4: A9044FF4  stp      x20, x19, [sp, #0x40]
//   0x04f1b8: A9057BFD  stp      x29, x30, [sp, #0x50]
static inline uint64_t fde_func_0199_0x04f1ac(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x04f1acULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xf9001bf5ULL) ^ 0x195f20ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0200 | PC: 0x04f354 | FDE: 0x195f60 | Size: 256 bytes
// Khung tháo gỡ #0200 | Địa chỉ PC: 0x04f354 | Địa chỉ FDE: 0x195f60 | Kích thước: 256 bytes
//   0x04f354: D10183FF  sub      sp, sp, #0x60
//   0x04f358: F9001BF5  str      x21, [sp, #0x30]
//   0x04f35c: A9044FF4  stp      x20, x19, [sp, #0x40]
//   0x04f360: A9057BFD  stp      x29, x30, [sp, #0x50]
static inline uint64_t fde_func_0200_0x04f354(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x04f354ULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xf9001bf5ULL) ^ 0x195f60ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0201 | PC: 0x04f4ac | FDE: 0x195fa0 | Size: 256 bytes
// Khung tháo gỡ #0201 | Địa chỉ PC: 0x04f4ac | Địa chỉ FDE: 0x195fa0 | Kích thước: 256 bytes
//   0x04f4ac: D10183FF  sub      sp, sp, #0x60
//   0x04f4b0: F9001BF5  str      x21, [sp, #0x30]
//   0x04f4b4: A9044FF4  stp      x20, x19, [sp, #0x40]
//   0x04f4b8: A9057BFD  stp      x29, x30, [sp, #0x50]
static inline uint64_t fde_func_0201_0x04f4ac(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x04f4acULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xf9001bf5ULL) ^ 0x195fa0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0202 | PC: 0x04f644 | FDE: 0x195fe8 | Size: 256 bytes
// Khung tháo gỡ #0202 | Địa chỉ PC: 0x04f644 | Địa chỉ FDE: 0x195fe8 | Kích thước: 256 bytes
//   0x04f644: D10143FF  sub      sp, sp, #0x50
//   0x04f648: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x04f64c: A9047BFD  stp      x29, x30, [sp, #0x40]
//   0x04f650: 910103FD  add      x29, sp, #0x40
static inline uint64_t fde_func_0202_0x04f644(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x04f644ULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xa9034ff4ULL) ^ 0x195fe8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0203 | PC: 0x04f82c | FDE: 0x196030 | Size: 64 bytes
// Khung tháo gỡ #0203 | Địa chỉ PC: 0x04f82c | Địa chỉ FDE: 0x196030 | Kích thước: 64 bytes
//   0x04f82c: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x04f830: 910003FD  mov      x29, sp
//   0x04f834: 2A0003E8  mov      w8, w0
//   0x04f838: AA0103E0  mov      x0, x1
static inline uint64_t fde_func_0203_0x04f82c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x04f82cULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x196030ULL;
    acc ^= (acc >> 17) * 0x0040ULL;
    return acc;
}

// FDE #0204 | PC: 0x04f86c | FDE: 0x196088 | Size: 48 bytes
// Khung tháo gỡ #0204 | Địa chỉ PC: 0x04f86c | Địa chỉ FDE: 0x196088 | Kích thước: 48 bytes
//   0x04f86c: B9400808  ldr      w8, [x0, #8]
//   0x04f870: F9400002  ldr      x2, [x0]
//   0x04f874: F9400801  ldr      x1, [x0, #0x10]
//   0x04f878: 2A0803E0  mov      w0, w8
static inline uint64_t fde_func_0204_0x04f86c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x04f86cULL ^ (static_cast<uint64_t>(0xb9400808ULL) << 13);
    acc = (acc + a1 + 0xf9400002ULL) ^ 0x196088ULL;
    acc ^= (acc >> 17) * 0x0030ULL;
    return acc;
}

// FDE #0205 | PC: 0x04f89c | FDE: 0x1960b8 | Size: 56 bytes
// Khung tháo gỡ #0205 | Địa chỉ PC: 0x04f89c | Địa chỉ FDE: 0x1960b8 | Kích thước: 56 bytes
//   0x04f89c: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x04f8a0: AA0003F3  mov      x19, x0
//   0x04f8a4: A9400008  ldp      x8, x0, [x0]
//   0x04f8a8: D63F0100  blr      x8
static inline uint64_t fde_func_0205_0x04f89c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x04f89cULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0xaa0003f3ULL) ^ 0x1960b8ULL;
    acc ^= (acc >> 17) * 0x0038ULL;
    return acc;
}

// FDE #0206 | PC: 0x04f8d4 | FDE: 0x1960e8 | Size: 256 bytes
// Khung tháo gỡ #0206 | Địa chỉ PC: 0x04f8d4 | Địa chỉ FDE: 0x1960e8 | Kích thước: 256 bytes
//   0x04f8d4: AA0003E2  mov      x2, x0
//   0x04f8d8: AA0103E0  mov      x0, x1
//   0x04f8dc: D61F0040  br       x2
//   0x04f8e0: D10403FF  sub      sp, sp, #0x100
static inline uint64_t fde_func_0206_0x04f8d4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x04f8d4ULL ^ (static_cast<uint64_t>(0xaa0003e2ULL) << 13);
    acc = (acc + a1 + 0xaa0103e0ULL) ^ 0x1960e8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0207 | PC: 0x057f84 | FDE: 0x196188 | Size: 256 bytes
// Khung tháo gỡ #0207 | Địa chỉ PC: 0x057f84 | Địa chỉ FDE: 0x196188 | Kích thước: 256 bytes
//   0x057f84: D101C3FF  sub      sp, sp, #0x70
//   0x057f88: F90013F9  str      x25, [sp, #0x20]
//   0x057f8c: A9035FF8  stp      x24, x23, [sp, #0x30]
//   0x057f90: A90457F6  stp      x22, x21, [sp, #0x40]
static inline uint64_t fde_func_0207_0x057f84(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x057f84ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xf90013f9ULL) ^ 0x196188ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0208 | PC: 0x05824c | FDE: 0x1961d0 | Size: 256 bytes
// Khung tháo gỡ #0208 | Địa chỉ PC: 0x05824c | Địa chỉ FDE: 0x1961d0 | Kích thước: 256 bytes
//   0x05824c: D100C3FF  sub      sp, sp, #0x30
//   0x058250: F9000BF3  str      x19, [sp, #0x10]
//   0x058254: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x058258: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0208_0x05824c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x05824cULL ^ (static_cast<uint64_t>(0xd100c3ffULL) << 13);
    acc = (acc + a1 + 0xf9000bf3ULL) ^ 0x1961d0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0209 | PC: 0x058438 | FDE: 0x196210 | Size: 224 bytes
// Khung tháo gỡ #0209 | Địa chỉ PC: 0x058438 | Địa chỉ FDE: 0x196210 | Kích thước: 224 bytes
//   0x058438: 90000000  adrp     x0, #0x58000
//   0x05843c: 91111000  add      x0, x0, #0x444
//   0x058440: D65F03C0  ret      
//   0x058444: D10243FF  sub      sp, sp, #0x90
static inline uint64_t fde_func_0209_0x058438(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x058438ULL ^ (static_cast<uint64_t>(0x90000000ULL) << 13);
    acc = (acc + a1 + 0x91111000ULL) ^ 0x196210ULL;
    acc ^= (acc >> 17) * 0x00e0ULL;
    return acc;
}

// FDE #0210 | PC: 0x058518 | FDE: 0x196248 | Size: 256 bytes
// Khung tháo gỡ #0210 | Địa chỉ PC: 0x058518 | Địa chỉ FDE: 0x196248 | Kích thước: 256 bytes
//   0x058518: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x05851c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x058520: 910043FD  add      x29, sp, #0x10
//   0x058524: F0000C08  adrp     x8, #0x1db000
static inline uint64_t fde_func_0210_0x058518(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x058518ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x196248ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0211 | PC: 0x058650 | FDE: 0x196288 | Size: 184 bytes
// Khung tháo gỡ #0211 | Địa chỉ PC: 0x058650 | Địa chỉ FDE: 0x196288 | Kích thước: 184 bytes
//   0x058650: 90000000  adrp     x0, #0x58000
//   0x058654: 91197000  add      x0, x0, #0x65c
//   0x058658: D65F03C0  ret      
//   0x05865c: D101C3FF  sub      sp, sp, #0x70
static inline uint64_t fde_func_0211_0x058650(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x058650ULL ^ (static_cast<uint64_t>(0x90000000ULL) << 13);
    acc = (acc + a1 + 0x91197000ULL) ^ 0x196288ULL;
    acc ^= (acc >> 17) * 0x00b8ULL;
    return acc;
}

// FDE #0212 | PC: 0x058708 | FDE: 0x1962c0 | Size: 184 bytes
// Khung tháo gỡ #0212 | Địa chỉ PC: 0x058708 | Địa chỉ FDE: 0x1962c0 | Kích thước: 184 bytes
//   0x058708: 90000000  adrp     x0, #0x58000
//   0x05870c: 911C5000  add      x0, x0, #0x714
//   0x058710: D65F03C0  ret      
//   0x058714: D10183FF  sub      sp, sp, #0x60
static inline uint64_t fde_func_0212_0x058708(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x058708ULL ^ (static_cast<uint64_t>(0x90000000ULL) << 13);
    acc = (acc + a1 + 0x911c5000ULL) ^ 0x1962c0ULL;
    acc ^= (acc >> 17) * 0x00b8ULL;
    return acc;
}

// FDE #0213 | PC: 0x0587c0 | FDE: 0x196318 | Size: 256 bytes
// Khung tháo gỡ #0213 | Địa chỉ PC: 0x0587c0 | Địa chỉ FDE: 0x196318 | Kích thước: 256 bytes
//   0x0587c0: AA1E03E4  mov      x4, x30
//   0x0587c4: 8B000084  add      x4, x4, x0
//   0x0587c8: AA0403FE  mov      x30, x4
//   0x0587cc: D65F03C0  ret      
static inline uint64_t fde_func_0213_0x0587c0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0587c0ULL ^ (static_cast<uint64_t>(0xaa1e03e4ULL) << 13);
    acc = (acc + a1 + 0x8b000084ULL) ^ 0x196318ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0214 | PC: 0x058e70 | FDE: 0x1963b8 | Size: 256 bytes
// Khung tháo gỡ #0214 | Địa chỉ PC: 0x058e70 | Địa chỉ FDE: 0x1963b8 | Kích thước: 256 bytes
//   0x058e70: D10483FF  sub      sp, sp, #0x120
//   0x058e74: A9104FFC  stp      x28, x19, [sp, #0x100]
//   0x058e78: A9117BFD  stp      x29, x30, [sp, #0x110]
//   0x058e7c: 910443FD  add      x29, sp, #0x110
static inline uint64_t fde_func_0214_0x058e70(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x058e70ULL ^ (static_cast<uint64_t>(0xd10483ffULL) << 13);
    acc = (acc + a1 + 0xa9104ffcULL) ^ 0x1963b8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0215 | PC: 0x058fa8 | FDE: 0x1963f8 | Size: 36 bytes
// Khung tháo gỡ #0215 | Địa chỉ PC: 0x058fa8 | Địa chỉ FDE: 0x1963f8 | Kích thước: 36 bytes
//   0x058fa8: D0000B48  adrp     x8, #0x1c2000
//   0x058fac: 91346108  add      x8, x8, #0xd18
//   0x058fb0: 7900101F  strh     wzr, [x0, #8]
//   0x058fb4: B9000C1F  str      wzr, [x0, #0xc]
static inline uint64_t fde_func_0215_0x058fa8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x058fa8ULL ^ (static_cast<uint64_t>(0xd0000b48ULL) << 13);
    acc = (acc + a1 + 0x91346108ULL) ^ 0x1963f8ULL;
    acc ^= (acc >> 17) * 0x0024ULL;
    return acc;
}

// FDE #0216 | PC: 0x058fcc | FDE: 0x196428 | Size: 256 bytes
// Khung tháo gỡ #0216 | Địa chỉ PC: 0x058fcc | Địa chỉ FDE: 0x196428 | Kích thước: 256 bytes
//   0x058fcc: 2A1F03E0  mov      w0, wzr
//   0x058fd0: D65F03C0  ret      
//   0x058fd4: D102C3FF  sub      sp, sp, #0xb0
//   0x058fd8: A9075FF8  stp      x24, x23, [sp, #0x70]
static inline uint64_t fde_func_0216_0x058fcc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x058fccULL ^ (static_cast<uint64_t>(0x2a1f03e0ULL) << 13);
    acc = (acc + a1 + 0xd65f03c0ULL) ^ 0x196428ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0217 | PC: 0x059764 | FDE: 0x196468 | Size: 16 bytes
// Khung tháo gỡ #0217 | Địa chỉ PC: 0x059764 | Địa chỉ FDE: 0x196468 | Kích thước: 16 bytes
//   0x059764: 2A1F03E0  mov      w0, wzr
//   0x059768: D65F03C0  ret      
//   0x05976c: 2A1F03E0  mov      w0, wzr
//   0x059770: D65F03C0  ret      
static inline uint64_t fde_func_0217_0x059764(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x059764ULL ^ (static_cast<uint64_t>(0x2a1f03e0ULL) << 13);
    acc = (acc + a1 + 0xd65f03c0ULL) ^ 0x196468ULL;
    acc ^= (acc >> 17) * 0x0010ULL;
    return acc;
}

// FDE #0218 | PC: 0x059774 | FDE: 0x196498 | Size: 256 bytes
// Khung tháo gỡ #0218 | Địa chỉ PC: 0x059774 | Địa chỉ FDE: 0x196498 | Kích thước: 256 bytes
//   0x059774: D10183FF  sub      sp, sp, #0x60
//   0x059778: A90357F6  stp      x22, x21, [sp, #0x30]
//   0x05977c: A9044FF4  stp      x20, x19, [sp, #0x40]
//   0x059780: A9057BFD  stp      x29, x30, [sp, #0x50]
static inline uint64_t fde_func_0218_0x059774(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x059774ULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xa90357f6ULL) ^ 0x196498ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0219 | PC: 0x0599a8 | FDE: 0x1964d8 | Size: 40 bytes
// Khung tháo gỡ #0219 | Địa chỉ PC: 0x0599a8 | Địa chỉ FDE: 0x1964d8 | Kích thước: 40 bytes
//   0x0599a8: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x0599ac: 910003FD  mov      x29, sp
//   0x0599b0: 97FF51B8  bl       #0x2e090
//   0x0599b4: A8C17BFD  ldp      x29, x30, [sp], #0x10
static inline uint64_t fde_func_0219_0x0599a8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0599a8ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1964d8ULL;
    acc ^= (acc >> 17) * 0x0028ULL;
    return acc;
}

// FDE #0220 | PC: 0x0599d0 | FDE: 0x196588 | Size: 256 bytes
// Khung tháo gỡ #0220 | Địa chỉ PC: 0x0599d0 | Địa chỉ FDE: 0x196588 | Kích thước: 256 bytes
//   0x0599d0: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x0599d4: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0599d8: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0599dc: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0220_0x0599d0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0599d0ULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x196588ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0221 | PC: 0x059b6c | FDE: 0x1965d0 | Size: 140 bytes
// Khung tháo gỡ #0221 | Địa chỉ PC: 0x059b6c | Địa chỉ FDE: 0x1965d0 | Kích thước: 140 bytes
//   0x059b6c: A9BE4FFC  stp      x28, x19, [sp, #-0x20]!
//   0x059b70: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x059b74: 910043FD  add      x29, sp, #0x10
//   0x059b78: D114C3FF  sub      sp, sp, #0x530
static inline uint64_t fde_func_0221_0x059b6c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x059b6cULL ^ (static_cast<uint64_t>(0xa9be4ffcULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1965d0ULL;
    acc ^= (acc >> 17) * 0x008cULL;
    return acc;
}

// FDE #0222 | PC: 0x059bf8 | FDE: 0x196608 | Size: 256 bytes
// Khung tháo gỡ #0222 | Địa chỉ PC: 0x059bf8 | Địa chỉ FDE: 0x196608 | Kích thước: 256 bytes
//   0x059bf8: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x059bfc: 910003FD  mov      x29, sp
//   0x059c00: D0000C08  adrp     x8, #0x1db000
//   0x059c04: 912CC108  add      x8, x8, #0xb30
static inline uint64_t fde_func_0222_0x059bf8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x059bf8ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x196608ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0223 | PC: 0x059d14 | FDE: 0x196648 | Size: 136 bytes
// Khung tháo gỡ #0223 | Địa chỉ PC: 0x059d14 | Địa chỉ FDE: 0x196648 | Kích thước: 136 bytes
//   0x059d14: D282080B  mov      x11, #0x1040
//   0x059d18: D280800A  mov      x10, #0x400
//   0x059d1c: F2A1404B  movk     x11, #0xa02, lsl #16
//   0x059d20: 90000009  adrp     x9, #0x59000
static inline uint64_t fde_func_0223_0x059d14(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x059d14ULL ^ (static_cast<uint64_t>(0xd282080bULL) << 13);
    acc = (acc + a1 + 0xd280800aULL) ^ 0x196648ULL;
    acc ^= (acc >> 17) * 0x0088ULL;
    return acc;
}

// FDE #0224 | PC: 0x059d9c | FDE: 0x196680 | Size: 256 bytes
// Khung tháo gỡ #0224 | Địa chỉ PC: 0x059d9c | Địa chỉ FDE: 0x196680 | Kích thước: 256 bytes
//   0x059d9c: D10203FF  sub      sp, sp, #0x80
//   0x059da0: F9002BF5  str      x21, [sp, #0x50]
//   0x059da4: A9064FF4  stp      x20, x19, [sp, #0x60]
//   0x059da8: A9077BFD  stp      x29, x30, [sp, #0x70]
static inline uint64_t fde_func_0224_0x059d9c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x059d9cULL ^ (static_cast<uint64_t>(0xd10203ffULL) << 13);
    acc = (acc + a1 + 0xf9002bf5ULL) ^ 0x196680ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0225 | PC: 0x059f20 | FDE: 0x1966c0 | Size: 144 bytes
// Khung tháo gỡ #0225 | Địa chỉ PC: 0x059f20 | Địa chỉ FDE: 0x1966c0 | Kích thước: 144 bytes
//   0x059f20: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x059f24: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x059f28: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x059f2c: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0225_0x059f20(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x059f20ULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1966c0ULL;
    acc ^= (acc >> 17) * 0x0090ULL;
    return acc;
}

// FDE #0226 | PC: 0x059fb0 | FDE: 0x196700 | Size: 256 bytes
// Khung tháo gỡ #0226 | Địa chỉ PC: 0x059fb0 | Địa chỉ FDE: 0x196700 | Kích thước: 256 bytes
//   0x059fb0: B940FC00  ldr      w0, [x0, #0xfc]
//   0x059fb4: D65F03C0  ret      
//   0x059fb8: D10143FF  sub      sp, sp, #0x50
//   0x059fbc: A90257F6  stp      x22, x21, [sp, #0x20]
static inline uint64_t fde_func_0226_0x059fb0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x059fb0ULL ^ (static_cast<uint64_t>(0xb940fc00ULL) << 13);
    acc = (acc + a1 + 0xd65f03c0ULL) ^ 0x196700ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0227 | PC: 0x05a0c0 | FDE: 0x196740 | Size: 228 bytes
// Khung tháo gỡ #0227 | Địa chỉ PC: 0x05a0c0 | Địa chỉ FDE: 0x196740 | Kích thước: 228 bytes
//   0x05a0c0: 9105E008  add      x8, x0, #0x178
//   0x05a0c4: 08DFFD08  ldarb    w8, [x8]
//   0x05a0c8: 12000100  and      w0, w8, #1
//   0x05a0cc: D65F03C0  ret      
static inline uint64_t fde_func_0227_0x05a0c0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x05a0c0ULL ^ (static_cast<uint64_t>(0x9105e008ULL) << 13);
    acc = (acc + a1 + 0x08dffd08ULL) ^ 0x196740ULL;
    acc ^= (acc >> 17) * 0x00e4ULL;
    return acc;
}

// FDE #0228 | PC: 0x05a1a4 | FDE: 0x196778 | Size: 104 bytes
// Khung tháo gỡ #0228 | Địa chỉ PC: 0x05a1a4 | Địa chỉ FDE: 0x196778 | Kích thước: 104 bytes
//   0x05a1a4: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x05a1a8: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x05a1ac: 910043FD  add      x29, sp, #0x10
//   0x05a1b0: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_0228_0x05a1a4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x05a1a4ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x196778ULL;
    acc ^= (acc >> 17) * 0x0068ULL;
    return acc;
}

// FDE #0229 | PC: 0x05a20c | FDE: 0x1967b8 | Size: 256 bytes
// Khung tháo gỡ #0229 | Địa chỉ PC: 0x05a20c | Địa chỉ FDE: 0x1967b8 | Kích thước: 256 bytes
//   0x05a20c: D10383FF  sub      sp, sp, #0xe0
//   0x05a210: F90053F7  str      x23, [sp, #0xa0]
//   0x05a214: A90B57F6  stp      x22, x21, [sp, #0xb0]
//   0x05a218: A90C4FF4  stp      x20, x19, [sp, #0xc0]
static inline uint64_t fde_func_0229_0x05a20c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x05a20cULL ^ (static_cast<uint64_t>(0xd10383ffULL) << 13);
    acc = (acc + a1 + 0xf90053f7ULL) ^ 0x1967b8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0230 | PC: 0x05aa8c | FDE: 0x196810 | Size: 236 bytes
// Khung tháo gỡ #0230 | Địa chỉ PC: 0x05aa8c | Địa chỉ FDE: 0x196810 | Kích thước: 236 bytes
//   0x05aa8c: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x05aa90: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x05aa94: 910043FD  add      x29, sp, #0x10
//   0x05aa98: 90000B48  adrp     x8, #0x1c2000
static inline uint64_t fde_func_0230_0x05aa8c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x05aa8cULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x196810ULL;
    acc ^= (acc >> 17) * 0x00ecULL;
    return acc;
}

// FDE #0231 | PC: 0x05ab78 | FDE: 0x196850 | Size: 144 bytes
// Khung tháo gỡ #0231 | Địa chỉ PC: 0x05ab78 | Địa chỉ FDE: 0x196850 | Kích thước: 144 bytes
//   0x05ab78: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x05ab7c: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x05ab80: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x05ab84: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0231_0x05ab78(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x05ab78ULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x196850ULL;
    acc ^= (acc >> 17) * 0x0090ULL;
    return acc;
}

// FDE #0232 | PC: 0x05ac08 | FDE: 0x196890 | Size: 156 bytes
// Khung tháo gỡ #0232 | Địa chỉ PC: 0x05ac08 | Địa chỉ FDE: 0x196890 | Kích thước: 156 bytes
//   0x05ac08: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x05ac0c: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x05ac10: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x05ac14: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0232_0x05ac08(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x05ac08ULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x196890ULL;
    acc ^= (acc >> 17) * 0x009cULL;
    return acc;
}

// FDE #0233 | PC: 0x05aca4 | FDE: 0x1968d0 | Size: 88 bytes
// Khung tháo gỡ #0233 | Địa chỉ PC: 0x05aca4 | Địa chỉ FDE: 0x1968d0 | Kích thước: 88 bytes
//   0x05aca4: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x05aca8: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x05acac: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x05acb0: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0233_0x05aca4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x05aca4ULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1968d0ULL;
    acc ^= (acc >> 17) * 0x0058ULL;
    return acc;
}

// FDE #0234 | PC: 0x05acfc | FDE: 0x196908 | Size: 256 bytes
// Khung tháo gỡ #0234 | Địa chỉ PC: 0x05acfc | Địa chỉ FDE: 0x196908 | Kích thước: 256 bytes
//   0x05acfc: D102C3FF  sub      sp, sp, #0xb0
//   0x05ad00: A9056FFC  stp      x28, x27, [sp, #0x50]
//   0x05ad04: A90667FA  stp      x26, x25, [sp, #0x60]
//   0x05ad08: A9075FF8  stp      x24, x23, [sp, #0x70]
static inline uint64_t fde_func_0234_0x05acfc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x05acfcULL ^ (static_cast<uint64_t>(0xd102c3ffULL) << 13);
    acc = (acc + a1 + 0xa9056ffcULL) ^ 0x196908ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0235 | PC: 0x05b388 | FDE: 0x196958 | Size: 256 bytes
// Khung tháo gỡ #0235 | Địa chỉ PC: 0x05b388 | Địa chỉ FDE: 0x196958 | Kích thước: 256 bytes
//   0x05b388: D10283FF  sub      sp, sp, #0xa0
//   0x05b38c: A9046FFC  stp      x28, x27, [sp, #0x40]
//   0x05b390: A90567FA  stp      x26, x25, [sp, #0x50]
//   0x05b394: A9065FF8  stp      x24, x23, [sp, #0x60]
static inline uint64_t fde_func_0235_0x05b388(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x05b388ULL ^ (static_cast<uint64_t>(0xd10283ffULL) << 13);
    acc = (acc + a1 + 0xa9046ffcULL) ^ 0x196958ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0236 | PC: 0x05b654 | FDE: 0x1969a8 | Size: 144 bytes
// Khung tháo gỡ #0236 | Địa chỉ PC: 0x05b654 | Địa chỉ FDE: 0x1969a8 | Kích thước: 144 bytes
//   0x05b654: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x05b658: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x05b65c: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x05b660: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0236_0x05b654(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x05b654ULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1969a8ULL;
    acc ^= (acc >> 17) * 0x0090ULL;
    return acc;
}

// FDE #0237 | PC: 0x05b6e4 | FDE: 0x1969e8 | Size: 144 bytes
// Khung tháo gỡ #0237 | Địa chỉ PC: 0x05b6e4 | Địa chỉ FDE: 0x1969e8 | Kích thước: 144 bytes
//   0x05b6e4: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x05b6e8: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x05b6ec: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x05b6f0: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0237_0x05b6e4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x05b6e4ULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1969e8ULL;
    acc ^= (acc >> 17) * 0x0090ULL;
    return acc;
}

// FDE #0238 | PC: 0x05b774 | FDE: 0x196a28 | Size: 144 bytes
// Khung tháo gỡ #0238 | Địa chỉ PC: 0x05b774 | Địa chỉ FDE: 0x196a28 | Kích thước: 144 bytes
//   0x05b774: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x05b778: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x05b77c: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x05b780: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0238_0x05b774(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x05b774ULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x196a28ULL;
    acc ^= (acc >> 17) * 0x0090ULL;
    return acc;
}

// FDE #0239 | PC: 0x05b804 | FDE: 0x196a68 | Size: 228 bytes
// Khung tháo gỡ #0239 | Địa chỉ PC: 0x05b804 | Địa chỉ FDE: 0x196a68 | Kích thước: 228 bytes
//   0x05b804: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x05b808: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x05b80c: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x05b810: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0239_0x05b804(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x05b804ULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x196a68ULL;
    acc ^= (acc >> 17) * 0x00e4ULL;
    return acc;
}

// FDE #0240 | PC: 0x05b8e8 | FDE: 0x196ab0 | Size: 80 bytes
// Khung tháo gỡ #0240 | Địa chỉ PC: 0x05b8e8 | Địa chỉ FDE: 0x196ab0 | Kích thước: 80 bytes
//   0x05b8e8: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x05b8ec: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x05b8f0: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x05b8f4: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0240_0x05b8e8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x05b8e8ULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x196ab0ULL;
    acc ^= (acc >> 17) * 0x0050ULL;
    return acc;
}

// FDE #0241 | PC: 0x05b938 | FDE: 0x196ae8 | Size: 64 bytes
// Khung tháo gỡ #0241 | Địa chỉ PC: 0x05b938 | Địa chỉ FDE: 0x196ae8 | Kích thước: 64 bytes
//   0x05b938: B900FC01  str      w1, [x0, #0xfc]
//   0x05b93c: D65F03C0  ret      
//   0x05b940: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x05b944: A9017BFD  stp      x29, x30, [sp, #0x10]
static inline uint64_t fde_func_0241_0x05b938(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x05b938ULL ^ (static_cast<uint64_t>(0xb900fc01ULL) << 13);
    acc = (acc + a1 + 0xd65f03c0ULL) ^ 0x196ae8ULL;
    acc ^= (acc >> 17) * 0x0040ULL;
    return acc;
}

// FDE #0242 | PC: 0x05b978 | FDE: 0x196b20 | Size: 256 bytes
// Khung tháo gỡ #0242 | Địa chỉ PC: 0x05b978 | Địa chỉ FDE: 0x196b20 | Kích thước: 256 bytes
//   0x05b978: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x05b97c: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x05b980: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x05b984: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0242_0x05b978(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x05b978ULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x196b20ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0243 | PC: 0x05bbc8 | FDE: 0x196b70 | Size: 256 bytes
// Khung tháo gỡ #0243 | Địa chỉ PC: 0x05bbc8 | Địa chỉ FDE: 0x196b70 | Kích thước: 256 bytes
//   0x05bbc8: D10303FF  sub      sp, sp, #0xc0
//   0x05bbcc: A9066FFC  stp      x28, x27, [sp, #0x60]
//   0x05bbd0: A90767FA  stp      x26, x25, [sp, #0x70]
//   0x05bbd4: A9085FF8  stp      x24, x23, [sp, #0x80]
static inline uint64_t fde_func_0243_0x05bbc8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x05bbc8ULL ^ (static_cast<uint64_t>(0xd10303ffULL) << 13);
    acc = (acc + a1 + 0xa9066ffcULL) ^ 0x196b70ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0244 | PC: 0x05c804 | FDE: 0x196bd0 | Size: 256 bytes
// Khung tháo gỡ #0244 | Địa chỉ PC: 0x05c804 | Địa chỉ FDE: 0x196bd0 | Kích thước: 256 bytes
//   0x05c804: D101C3FF  sub      sp, sp, #0x70
//   0x05c808: A90267FA  stp      x26, x25, [sp, #0x20]
//   0x05c80c: A9035FF8  stp      x24, x23, [sp, #0x30]
//   0x05c810: A90457F6  stp      x22, x21, [sp, #0x40]
static inline uint64_t fde_func_0244_0x05c804(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x05c804ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xa90267faULL) ^ 0x196bd0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0245 | PC: 0x05ca00 | FDE: 0x196c28 | Size: 256 bytes
// Khung tháo gỡ #0245 | Địa chỉ PC: 0x05ca00 | Địa chỉ FDE: 0x196c28 | Kích thước: 256 bytes
//   0x05ca00: D10343FF  sub      sp, sp, #0xd0
//   0x05ca04: A9076FFC  stp      x28, x27, [sp, #0x70]
//   0x05ca08: A90867FA  stp      x26, x25, [sp, #0x80]
//   0x05ca0c: A9095FF8  stp      x24, x23, [sp, #0x90]
static inline uint64_t fde_func_0245_0x05ca00(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x05ca00ULL ^ (static_cast<uint64_t>(0xd10343ffULL) << 13);
    acc = (acc + a1 + 0xa9076ffcULL) ^ 0x196c28ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0246 | PC: 0x05d574 | FDE: 0x196c88 | Size: 256 bytes
// Khung tháo gỡ #0246 | Địa chỉ PC: 0x05d574 | Địa chỉ FDE: 0x196c88 | Kích thước: 256 bytes
//   0x05d574: D10303FF  sub      sp, sp, #0xc0
//   0x05d578: A9066FFC  stp      x28, x27, [sp, #0x60]
//   0x05d57c: A90767FA  stp      x26, x25, [sp, #0x70]
//   0x05d580: A9085FF8  stp      x24, x23, [sp, #0x80]
static inline uint64_t fde_func_0246_0x05d574(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x05d574ULL ^ (static_cast<uint64_t>(0xd10303ffULL) << 13);
    acc = (acc + a1 + 0xa9066ffcULL) ^ 0x196c88ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0247 | PC: 0x05dce0 | FDE: 0x196ce8 | Size: 256 bytes
// Khung tháo gỡ #0247 | Địa chỉ PC: 0x05dce0 | Địa chỉ FDE: 0x196ce8 | Kích thước: 256 bytes
//   0x05dce0: D10203FF  sub      sp, sp, #0x80
//   0x05dce4: A9026FFC  stp      x28, x27, [sp, #0x20]
//   0x05dce8: A90367FA  stp      x26, x25, [sp, #0x30]
//   0x05dcec: A9045FF8  stp      x24, x23, [sp, #0x40]
static inline uint64_t fde_func_0247_0x05dce0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x05dce0ULL ^ (static_cast<uint64_t>(0xd10203ffULL) << 13);
    acc = (acc + a1 + 0xa9026ffcULL) ^ 0x196ce8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0248 | PC: 0x05e170 | FDE: 0x196d40 | Size: 256 bytes
// Khung tháo gỡ #0248 | Địa chỉ PC: 0x05e170 | Địa chỉ FDE: 0x196d40 | Kích thước: 256 bytes
//   0x05e170: D10383FF  sub      sp, sp, #0xe0
//   0x05e174: A9086FFC  stp      x28, x27, [sp, #0x80]
//   0x05e178: A90967FA  stp      x26, x25, [sp, #0x90]
//   0x05e17c: A90A5FF8  stp      x24, x23, [sp, #0xa0]
static inline uint64_t fde_func_0248_0x05e170(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x05e170ULL ^ (static_cast<uint64_t>(0xd10383ffULL) << 13);
    acc = (acc + a1 + 0xa9086ffcULL) ^ 0x196d40ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0249 | PC: 0x05f188 | FDE: 0x196da0 | Size: 256 bytes
// Khung tháo gỡ #0249 | Địa chỉ PC: 0x05f188 | Địa chỉ FDE: 0x196da0 | Kích thước: 256 bytes
//   0x05f188: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x05f18c: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x05f190: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x05f194: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0249_0x05f188(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x05f188ULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x196da0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0250 | PC: 0x05fb30 | FDE: 0x196df0 | Size: 256 bytes
// Khung tháo gỡ #0250 | Địa chỉ PC: 0x05fb30 | Địa chỉ FDE: 0x196df0 | Kích thước: 256 bytes
//   0x05fb30: D10343FF  sub      sp, sp, #0xd0
//   0x05fb34: A9076FFC  stp      x28, x27, [sp, #0x70]
//   0x05fb38: A90867FA  stp      x26, x25, [sp, #0x80]
//   0x05fb3c: A9095FF8  stp      x24, x23, [sp, #0x90]
static inline uint64_t fde_func_0250_0x05fb30(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x05fb30ULL ^ (static_cast<uint64_t>(0xd10343ffULL) << 13);
    acc = (acc + a1 + 0xa9076ffcULL) ^ 0x196df0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0251 | PC: 0x060388 | FDE: 0x196e40 | Size: 256 bytes
// Khung tháo gỡ #0251 | Địa chỉ PC: 0x060388 | Địa chỉ FDE: 0x196e40 | Kích thước: 256 bytes
//   0x060388: D102C3FF  sub      sp, sp, #0xb0
//   0x06038c: A9056FFC  stp      x28, x27, [sp, #0x50]
//   0x060390: A90667FA  stp      x26, x25, [sp, #0x60]
//   0x060394: A9075FF8  stp      x24, x23, [sp, #0x70]
static inline uint64_t fde_func_0251_0x060388(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x060388ULL ^ (static_cast<uint64_t>(0xd102c3ffULL) << 13);
    acc = (acc + a1 + 0xa9056ffcULL) ^ 0x196e40ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0252 | PC: 0x0605e8 | FDE: 0x196e88 | Size: 124 bytes
// Khung tháo gỡ #0252 | Địa chỉ PC: 0x0605e8 | Địa chỉ FDE: 0x196e88 | Kích thước: 124 bytes
//   0x0605e8: 9104A000  add      x0, x0, #0x128
//   0x0605ec: D65F03C0  ret      
//   0x0605f0: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x0605f4: A9014FF4  stp      x20, x19, [sp, #0x10]
static inline uint64_t fde_func_0252_0x0605e8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0605e8ULL ^ (static_cast<uint64_t>(0x9104a000ULL) << 13);
    acc = (acc + a1 + 0xd65f03c0ULL) ^ 0x196e88ULL;
    acc ^= (acc >> 17) * 0x007cULL;
    return acc;
}

// FDE #0253 | PC: 0x060664 | FDE: 0x196ec8 | Size: 256 bytes
// Khung tháo gỡ #0253 | Địa chỉ PC: 0x060664 | Địa chỉ FDE: 0x196ec8 | Kích thước: 256 bytes
//   0x060664: D10303FF  sub      sp, sp, #0xc0
//   0x060668: A9066FFC  stp      x28, x27, [sp, #0x60]
//   0x06066c: A90767FA  stp      x26, x25, [sp, #0x70]
//   0x060670: A9085FF8  stp      x24, x23, [sp, #0x80]
static inline uint64_t fde_func_0253_0x060664(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x060664ULL ^ (static_cast<uint64_t>(0xd10303ffULL) << 13);
    acc = (acc + a1 + 0xa9066ffcULL) ^ 0x196ec8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0254 | PC: 0x060ffc | FDE: 0x196f28 | Size: 256 bytes
// Khung tháo gỡ #0254 | Địa chỉ PC: 0x060ffc | Địa chỉ FDE: 0x196f28 | Kích thước: 256 bytes
//   0x060ffc: D105C3FF  sub      sp, sp, #0x170
//   0x061000: A9116FFC  stp      x28, x27, [sp, #0x110]
//   0x061004: A91267FA  stp      x26, x25, [sp, #0x120]
//   0x061008: A9135FF8  stp      x24, x23, [sp, #0x130]
static inline uint64_t fde_func_0254_0x060ffc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x060ffcULL ^ (static_cast<uint64_t>(0xd105c3ffULL) << 13);
    acc = (acc + a1 + 0xa9116ffcULL) ^ 0x196f28ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0255 | PC: 0x0622d8 | FDE: 0x196f88 | Size: 136 bytes
// Khung tháo gỡ #0255 | Địa chỉ PC: 0x0622d8 | Địa chỉ FDE: 0x196f88 | Kích thước: 136 bytes
//   0x0622d8: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x0622dc: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0622e0: 910043FD  add      x29, sp, #0x10
//   0x0622e4: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_0255_0x0622d8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0622d8ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x196f88ULL;
    acc ^= (acc >> 17) * 0x0088ULL;
    return acc;
}

// FDE #0256 | PC: 0x062360 | FDE: 0x196fc8 | Size: 256 bytes
// Khung tháo gỡ #0256 | Địa chỉ PC: 0x062360 | Địa chỉ FDE: 0x196fc8 | Kích thước: 256 bytes
//   0x062360: F81A0FFB  str      x27, [sp, #-0x60]!
//   0x062364: A90167FA  stp      x26, x25, [sp, #0x10]
//   0x062368: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x06236c: A90357F6  stp      x22, x21, [sp, #0x30]
static inline uint64_t fde_func_0256_0x062360(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x062360ULL ^ (static_cast<uint64_t>(0xf81a0ffbULL) << 13);
    acc = (acc + a1 + 0xa90167faULL) ^ 0x196fc8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0257 | PC: 0x062728 | FDE: 0x197020 | Size: 24 bytes
// Khung tháo gỡ #0257 | Địa chỉ PC: 0x062728 | Địa chỉ FDE: 0x197020 | Kích thước: 24 bytes
//   0x062728: D65F03C0  ret      
//   0x06272c: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x062730: 910003FD  mov      x29, sp
//   0x062734: 97FF2E57  bl       #0x2e090
static inline uint64_t fde_func_0257_0x062728(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x062728ULL ^ (static_cast<uint64_t>(0xd65f03c0ULL) << 13);
    acc = (acc + a1 + 0xa9bf7bfdULL) ^ 0x197020ULL;
    acc ^= (acc >> 17) * 0x0018ULL;
    return acc;
}

// FDE #0258 | PC: 0x062740 | FDE: 0x197058 | Size: 80 bytes
// Khung tháo gỡ #0258 | Địa chỉ PC: 0x062740 | Địa chỉ FDE: 0x197058 | Kích thước: 80 bytes
//   0x062740: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x062744: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x062748: 910043FD  add      x29, sp, #0x10
//   0x06274c: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_0258_0x062740(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x062740ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x197058ULL;
    acc ^= (acc >> 17) * 0x0050ULL;
    return acc;
}

// FDE #0259 | PC: 0x062790 | FDE: 0x197090 | Size: 24 bytes
// Khung tháo gỡ #0259 | Địa chỉ PC: 0x062790 | Địa chỉ FDE: 0x197090 | Kích thước: 24 bytes
//   0x062790: D65F03C0  ret      
//   0x062794: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x062798: 910003FD  mov      x29, sp
//   0x06279c: 97FF2E3D  bl       #0x2e090
static inline uint64_t fde_func_0259_0x062790(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x062790ULL ^ (static_cast<uint64_t>(0xd65f03c0ULL) << 13);
    acc = (acc + a1 + 0xa9bf7bfdULL) ^ 0x197090ULL;
    acc ^= (acc >> 17) * 0x0018ULL;
    return acc;
}

// FDE #0260 | PC: 0x0627a8 | FDE: 0x1970c8 | Size: 256 bytes
// Khung tháo gỡ #0260 | Địa chỉ PC: 0x0627a8 | Địa chỉ FDE: 0x1970c8 | Kích thước: 256 bytes
//   0x0627a8: D10143FF  sub      sp, sp, #0x50
//   0x0627ac: F90013F5  str      x21, [sp, #0x20]
//   0x0627b0: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x0627b4: A9047BFD  stp      x29, x30, [sp, #0x40]
static inline uint64_t fde_func_0260_0x0627a8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0627a8ULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xf90013f5ULL) ^ 0x1970c8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0261 | PC: 0x0628c8 | FDE: 0x197100 | Size: 256 bytes
// Khung tháo gỡ #0261 | Địa chỉ PC: 0x0628c8 | Địa chỉ FDE: 0x197100 | Kích thước: 256 bytes
//   0x0628c8: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x0628cc: 910003FD  mov      x29, sp
//   0x0628d0: 97FF2DF0  bl       #0x2e090
//   0x0628d4: A8C17BFD  ldp      x29, x30, [sp], #0x10
static inline uint64_t fde_func_0261_0x0628c8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0628c8ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x197100ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0262 | PC: 0x0629e4 | FDE: 0x197140 | Size: 76 bytes
// Khung tháo gỡ #0262 | Địa chỉ PC: 0x0629e4 | Địa chỉ FDE: 0x197140 | Kích thước: 76 bytes
//   0x0629e4: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x0629e8: 910003FD  mov      x29, sp
//   0x0629ec: 97FF2DA9  bl       #0x2e090
//   0x0629f0: A8C17BFD  ldp      x29, x30, [sp], #0x10
static inline uint64_t fde_func_0262_0x0629e4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0629e4ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x197140ULL;
    acc ^= (acc >> 17) * 0x004cULL;
    return acc;
}

// FDE #0263 | PC: 0x062a30 | FDE: 0x197180 | Size: 28 bytes
// Khung tháo gỡ #0263 | Địa chỉ PC: 0x062a30 | Địa chỉ FDE: 0x197180 | Kích thước: 28 bytes
//   0x062a30: 90000B08  adrp     x8, #0x1c2000
//   0x062a34: 91378108  add      x8, x8, #0xde0
//   0x062a38: F9000028  str      x8, [x1]
//   0x062a3c: F9400408  ldr      x8, [x0, #8]
static inline uint64_t fde_func_0263_0x062a30(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x062a30ULL ^ (static_cast<uint64_t>(0x90000b08ULL) << 13);
    acc = (acc + a1 + 0x91378108ULL) ^ 0x197180ULL;
    acc ^= (acc >> 17) * 0x001cULL;
    return acc;
}

// FDE #0264 | PC: 0x062a4c | FDE: 0x1971b0 | Size: 88 bytes
// Khung tháo gỡ #0264 | Địa chỉ PC: 0x062a4c | Địa chỉ FDE: 0x1971b0 | Kích thước: 88 bytes
//   0x062a4c: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x062a50: 910003FD  mov      x29, sp
//   0x062a54: 97FF2D8F  bl       #0x2e090
//   0x062a58: A8C17BFD  ldp      x29, x30, [sp], #0x10
static inline uint64_t fde_func_0264_0x062a4c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x062a4cULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1971b0ULL;
    acc ^= (acc >> 17) * 0x0058ULL;
    return acc;
}

// FDE #0265 | PC: 0x062aa4 | FDE: 0x1971f0 | Size: 40 bytes
// Khung tháo gỡ #0265 | Địa chỉ PC: 0x062aa4 | Địa chỉ FDE: 0x1971f0 | Kích thước: 40 bytes
//   0x062aa4: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x062aa8: 910003FD  mov      x29, sp
//   0x062aac: 97FF2EC9  bl       #0x2e5d0
//   0x062ab0: F9400008  ldr      x8, [x0]
static inline uint64_t fde_func_0265_0x062aa4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x062aa4ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1971f0ULL;
    acc ^= (acc >> 17) * 0x0028ULL;
    return acc;
}

// FDE #0266 | PC: 0x062acc | FDE: 0x197228 | Size: 72 bytes
// Khung tháo gỡ #0266 | Địa chỉ PC: 0x062acc | Địa chỉ FDE: 0x197228 | Kích thước: 72 bytes
//   0x062acc: F9400008  ldr      x8, [x0]
//   0x062ad0: F9400108  ldr      x8, [x8]
//   0x062ad4: 39400108  ldrb     w8, [x8]
//   0x062ad8: 53017D09  lsr      w9, w8, #1
static inline uint64_t fde_func_0266_0x062acc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x062accULL ^ (static_cast<uint64_t>(0xf9400008ULL) << 13);
    acc = (acc + a1 + 0xf9400108ULL) ^ 0x197228ULL;
    acc ^= (acc >> 17) * 0x0048ULL;
    return acc;
}

// FDE #0267 | PC: 0x062b14 | FDE: 0x197258 | Size: 64 bytes
// Khung tháo gỡ #0267 | Địa chỉ PC: 0x062b14 | Địa chỉ FDE: 0x197258 | Kích thước: 64 bytes
//   0x062b14: F9400008  ldr      x8, [x0]
//   0x062b18: F9400108  ldr      x8, [x8]
//   0x062b1c: 39400108  ldrb     w8, [x8]
//   0x062b20: 53037D09  lsr      w9, w8, #3
static inline uint64_t fde_func_0267_0x062b14(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x062b14ULL ^ (static_cast<uint64_t>(0xf9400008ULL) << 13);
    acc = (acc + a1 + 0xf9400108ULL) ^ 0x197258ULL;
    acc ^= (acc >> 17) * 0x0040ULL;
    return acc;
}

// FDE #0268 | PC: 0x062b54 | FDE: 0x197288 | Size: 72 bytes
// Khung tháo gỡ #0268 | Địa chỉ PC: 0x062b54 | Địa chỉ FDE: 0x197288 | Kích thước: 72 bytes
//   0x062b54: F9400008  ldr      x8, [x0]
//   0x062b58: F9400108  ldr      x8, [x8]
//   0x062b5c: 39400108  ldrb     w8, [x8]
//   0x062b60: 53017D09  lsr      w9, w8, #1
static inline uint64_t fde_func_0268_0x062b54(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x062b54ULL ^ (static_cast<uint64_t>(0xf9400008ULL) << 13);
    acc = (acc + a1 + 0xf9400108ULL) ^ 0x197288ULL;
    acc ^= (acc >> 17) * 0x0048ULL;
    return acc;
}

// FDE #0269 | PC: 0x062b9c | FDE: 0x1972b8 | Size: 32 bytes
// Khung tháo gỡ #0269 | Địa chỉ PC: 0x062b9c | Địa chỉ FDE: 0x1972b8 | Kích thước: 32 bytes
//   0x062b9c: F9400008  ldr      x8, [x0]
//   0x062ba0: F9400108  ldr      x8, [x8]
//   0x062ba4: 39400108  ldrb     w8, [x8]
//   0x062ba8: 53077D09  lsr      w9, w8, #7
static inline uint64_t fde_func_0269_0x062b9c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x062b9cULL ^ (static_cast<uint64_t>(0xf9400008ULL) << 13);
    acc = (acc + a1 + 0xf9400108ULL) ^ 0x1972b8ULL;
    acc ^= (acc >> 17) * 0x0020ULL;
    return acc;
}

// FDE #0270 | PC: 0x062bbc | FDE: 0x1972e8 | Size: 24 bytes
// Khung tháo gỡ #0270 | Địa chỉ PC: 0x062bbc | Địa chỉ FDE: 0x1972e8 | Kích thước: 24 bytes
//   0x062bbc: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x062bc0: 910003FD  mov      x29, sp
//   0x062bc4: 97FF2D33  bl       #0x2e090
//   0x062bc8: A8C17BFD  ldp      x29, x30, [sp], #0x10
static inline uint64_t fde_func_0270_0x062bbc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x062bbcULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1972e8ULL;
    acc ^= (acc >> 17) * 0x0018ULL;
    return acc;
}

// FDE #0271 | PC: 0x062bd4 | FDE: 0x197320 | Size: 256 bytes
// Khung tháo gỡ #0271 | Địa chỉ PC: 0x062bd4 | Địa chỉ FDE: 0x197320 | Kích thước: 256 bytes
//   0x062bd4: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x062bd8: 910003FD  mov      x29, sp
//   0x062bdc: 97FF2D2D  bl       #0x2e090
//   0x062be0: A8C17BFD  ldp      x29, x30, [sp], #0x10
static inline uint64_t fde_func_0271_0x062bd4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x062bd4ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x197320ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0272 | PC: 0x062cf0 | FDE: 0x197368 | Size: 256 bytes
// Khung tháo gỡ #0272 | Địa chỉ PC: 0x062cf0 | Địa chỉ FDE: 0x197368 | Kích thước: 256 bytes
//   0x062cf0: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x062cf4: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x062cf8: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x062cfc: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0272_0x062cf0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x062cf0ULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x197368ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0273 | PC: 0x062e88 | FDE: 0x1973b0 | Size: 256 bytes
// Khung tháo gỡ #0273 | Địa chỉ PC: 0x062e88 | Địa chỉ FDE: 0x1973b0 | Kích thước: 256 bytes
//   0x062e88: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x062e8c: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x062e90: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x062e94: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0273_0x062e88(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x062e88ULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1973b0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0274 | PC: 0x063098 | FDE: 0x197400 | Size: 256 bytes
// Khung tháo gỡ #0274 | Địa chỉ PC: 0x063098 | Địa chỉ FDE: 0x197400 | Kích thước: 256 bytes
//   0x063098: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x06309c: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0630a0: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0630a4: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0274_0x063098(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x063098ULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x197400ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0275 | PC: 0x0632a8 | FDE: 0x197450 | Size: 256 bytes
// Khung tháo gỡ #0275 | Địa chỉ PC: 0x0632a8 | Địa chỉ FDE: 0x197450 | Kích thước: 256 bytes
//   0x0632a8: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x0632ac: 910003FD  mov      x29, sp
//   0x0632b0: F0000AE8  adrp     x8, #0x1c2000
//   0x0632b4: 913AA108  add      x8, x8, #0xea8
static inline uint64_t fde_func_0275_0x0632a8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0632a8ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x197450ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0276 | PC: 0x0634b4 | FDE: 0x1974a0 | Size: 256 bytes
// Khung tháo gỡ #0276 | Địa chỉ PC: 0x0634b4 | Địa chỉ FDE: 0x1974a0 | Kích thước: 256 bytes
//   0x0634b4: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x0634b8: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0634bc: 910043FD  add      x29, sp, #0x10
//   0x0634c0: F0000AE8  adrp     x8, #0x1c2000
static inline uint64_t fde_func_0276_0x0634b4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0634b4ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1974a0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0277 | PC: 0x0638d0 | FDE: 0x1974f0 | Size: 256 bytes
// Khung tháo gỡ #0277 | Địa chỉ PC: 0x0638d0 | Địa chỉ FDE: 0x1974f0 | Kích thước: 256 bytes
//   0x0638d0: D10343FF  sub      sp, sp, #0xd0
//   0x0638d4: A90A57F6  stp      x22, x21, [sp, #0xa0]
//   0x0638d8: A90B4FF4  stp      x20, x19, [sp, #0xb0]
//   0x0638dc: A90C7BFD  stp      x29, x30, [sp, #0xc0]
static inline uint64_t fde_func_0277_0x0638d0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0638d0ULL ^ (static_cast<uint64_t>(0xd10343ffULL) << 13);
    acc = (acc + a1 + 0xa90a57f6ULL) ^ 0x1974f0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0278 | PC: 0x063eb8 | FDE: 0x197530 | Size: 132 bytes
// Khung tháo gỡ #0278 | Địa chỉ PC: 0x063eb8 | Địa chỉ FDE: 0x197530 | Kích thước: 132 bytes
//   0x063eb8: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x063ebc: 910003FD  mov      x29, sp
//   0x063ec0: 97FF29C4  bl       #0x2e5d0
//   0x063ec4: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
static inline uint64_t fde_func_0278_0x063eb8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x063eb8ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x197530ULL;
    acc ^= (acc >> 17) * 0x0084ULL;
    return acc;
}

// FDE #0279 | PC: 0x063f3c | FDE: 0x197570 | Size: 256 bytes
// Khung tháo gỡ #0279 | Địa chỉ PC: 0x063f3c | Địa chỉ FDE: 0x197570 | Kích thước: 256 bytes
//   0x063f3c: F81C0FF7  str      x23, [sp, #-0x40]!
//   0x063f40: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x063f44: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x063f48: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_0279_0x063f3c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x063f3cULL ^ (static_cast<uint64_t>(0xf81c0ff7ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x197570ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0280 | PC: 0x064090 | FDE: 0x1975b8 | Size: 256 bytes
// Khung tháo gỡ #0280 | Địa chỉ PC: 0x064090 | Địa chỉ FDE: 0x1975b8 | Kích thước: 256 bytes
//   0x064090: A9BC5FF8  stp      x24, x23, [sp, #-0x40]!
//   0x064094: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x064098: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x06409c: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_0280_0x064090(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x064090ULL ^ (static_cast<uint64_t>(0xa9bc5ff8ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x1975b8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0281 | PC: 0x064280 | FDE: 0x197608 | Size: 256 bytes
// Khung tháo gỡ #0281 | Địa chỉ PC: 0x064280 | Địa chỉ FDE: 0x197608 | Kích thước: 256 bytes
//   0x064280: F81B0FF9  str      x25, [sp, #-0x50]!
//   0x064284: A9015FF8  stp      x24, x23, [sp, #0x10]
//   0x064288: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x06428c: A9034FF4  stp      x20, x19, [sp, #0x30]
static inline uint64_t fde_func_0281_0x064280(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x064280ULL ^ (static_cast<uint64_t>(0xf81b0ff9ULL) << 13);
    acc = (acc + a1 + 0xa9015ff8ULL) ^ 0x197608ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0282 | PC: 0x0645cc | FDE: 0x197678 | Size: 56 bytes
// Khung tháo gỡ #0282 | Địa chỉ PC: 0x0645cc | Địa chỉ FDE: 0x197678 | Kích thước: 56 bytes
//   0x0645cc: AA1E03E3  mov      x3, x30
//   0x0645d0: 8B000063  add      x3, x3, x0
//   0x0645d4: AA0303FE  mov      x30, x3
//   0x0645d8: D65F03C0  ret      
static inline uint64_t fde_func_0282_0x0645cc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0645ccULL ^ (static_cast<uint64_t>(0xaa1e03e3ULL) << 13);
    acc = (acc + a1 + 0x8b000063ULL) ^ 0x197678ULL;
    acc ^= (acc >> 17) * 0x0038ULL;
    return acc;
}

// FDE #0283 | PC: 0x064604 | FDE: 0x1976a8 | Size: 44 bytes
// Khung tháo gỡ #0283 | Địa chỉ PC: 0x064604 | Địa chỉ FDE: 0x1976a8 | Kích thước: 44 bytes
//   0x064604: A9402002  ldp      x2, x8, [x0]
//   0x064608: F9400801  ldr      x1, [x0, #0x10]
//   0x06460c: AA0803E0  mov      x0, x8
//   0x064610: D61F0040  br       x2
static inline uint64_t fde_func_0283_0x064604(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x064604ULL ^ (static_cast<uint64_t>(0xa9402002ULL) << 13);
    acc = (acc + a1 + 0xf9400801ULL) ^ 0x1976a8ULL;
    acc ^= (acc >> 17) * 0x002cULL;
    return acc;
}

// FDE #0284 | PC: 0x064630 | FDE: 0x1976d8 | Size: 44 bytes
// Khung tháo gỡ #0284 | Địa chỉ PC: 0x064630 | Địa chỉ FDE: 0x1976d8 | Kích thước: 44 bytes
//   0x064630: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x064634: AA0003F3  mov      x19, x0
//   0x064638: A9400008  ldp      x8, x0, [x0]
//   0x06463c: A9410A61  ldp      x1, x2, [x19, #0x10]
static inline uint64_t fde_func_0284_0x064630(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x064630ULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0xaa0003f3ULL) ^ 0x1976d8ULL;
    acc ^= (acc >> 17) * 0x002cULL;
    return acc;
}

// FDE #0285 | PC: 0x06465c | FDE: 0x197708 | Size: 40 bytes
// Khung tháo gỡ #0285 | Địa chỉ PC: 0x06465c | Địa chỉ FDE: 0x197708 | Kích thước: 40 bytes
//   0x06465c: F81F0FFE  str      x30, [sp, #-0x10]!
//   0x064660: F9400008  ldr      x8, [x0]
//   0x064664: D63F0100  blr      x8
//   0x064668: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
static inline uint64_t fde_func_0285_0x06465c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x06465cULL ^ (static_cast<uint64_t>(0xf81f0ffeULL) << 13);
    acc = (acc + a1 + 0xf9400008ULL) ^ 0x197708ULL;
    acc ^= (acc >> 17) * 0x0028ULL;
    return acc;
}

// FDE #0286 | PC: 0x064684 | FDE: 0x197738 | Size: 52 bytes
// Khung tháo gỡ #0286 | Địa chỉ PC: 0x064684 | Địa chỉ FDE: 0x197738 | Kích thước: 52 bytes
//   0x064684: F81F0FFE  str      x30, [sp, #-0x10]!
//   0x064688: A9402009  ldp      x9, x8, [x0]
//   0x06468c: F9400800  ldr      x0, [x0, #0x10]
//   0x064690: D63F0120  blr      x9
static inline uint64_t fde_func_0286_0x064684(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x064684ULL ^ (static_cast<uint64_t>(0xf81f0ffeULL) << 13);
    acc = (acc + a1 + 0xa9402009ULL) ^ 0x197738ULL;
    acc ^= (acc >> 17) * 0x0034ULL;
    return acc;
}

// FDE #0287 | PC: 0x0646b8 | FDE: 0x197768 | Size: 48 bytes
// Khung tháo gỡ #0287 | Địa chỉ PC: 0x0646b8 | Địa chỉ FDE: 0x197768 | Kích thước: 48 bytes
//   0x0646b8: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x0646bc: AA0003F3  mov      x19, x0
//   0x0646c0: A9400008  ldp      x8, x0, [x0]
//   0x0646c4: D63F0100  blr      x8
static inline uint64_t fde_func_0287_0x0646b8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0646b8ULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0xaa0003f3ULL) ^ 0x197768ULL;
    acc ^= (acc >> 17) * 0x0030ULL;
    return acc;
}

// FDE #0288 | PC: 0x0646e8 | FDE: 0x197798 | Size: 56 bytes
// Khung tháo gỡ #0288 | Địa chỉ PC: 0x0646e8 | Địa chỉ FDE: 0x197798 | Kích thước: 56 bytes
//   0x0646e8: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x0646ec: AA0003F3  mov      x19, x0
//   0x0646f0: A9400008  ldp      x8, x0, [x0]
//   0x0646f4: F9400A61  ldr      x1, [x19, #0x10]
static inline uint64_t fde_func_0288_0x0646e8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0646e8ULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0xaa0003f3ULL) ^ 0x197798ULL;
    acc ^= (acc >> 17) * 0x0038ULL;
    return acc;
}

// FDE #0289 | PC: 0x064720 | FDE: 0x197820 | Size: 256 bytes
// Khung tháo gỡ #0289 | Địa chỉ PC: 0x064720 | Địa chỉ FDE: 0x197820 | Kích thước: 256 bytes
//   0x064720: A9BA6FFC  stp      x28, x27, [sp, #-0x60]!
//   0x064724: A90167FA  stp      x26, x25, [sp, #0x10]
//   0x064728: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x06472c: A90357F6  stp      x22, x21, [sp, #0x30]
static inline uint64_t fde_func_0289_0x064720(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x064720ULL ^ (static_cast<uint64_t>(0xa9ba6ffcULL) << 13);
    acc = (acc + a1 + 0xa90167faULL) ^ 0x197820ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0290 | PC: 0x0661b0 | FDE: 0x197870 | Size: 256 bytes
// Khung tháo gỡ #0290 | Địa chỉ PC: 0x0661b0 | Địa chỉ FDE: 0x197870 | Kích thước: 256 bytes
//   0x0661b0: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0661b4: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0661b8: 910043FD  add      x29, sp, #0x10
//   0x0661bc: B0000B89  adrp     x9, #0x1d7000
static inline uint64_t fde_func_0290_0x0661b0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0661b0ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x197870ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0291 | PC: 0x0662e4 | FDE: 0x1978b0 | Size: 256 bytes
// Khung tháo gỡ #0291 | Địa chỉ PC: 0x0662e4 | Địa chỉ FDE: 0x1978b0 | Kích thước: 256 bytes
//   0x0662e4: D104C3FF  sub      sp, sp, #0x130
//   0x0662e8: 6D0D23E9  stp      d9, d8, [sp, #0xd0]
//   0x0662ec: F90073FC  str      x28, [sp, #0xe0]
//   0x0662f0: A90F5FF8  stp      x24, x23, [sp, #0xf0]
static inline uint64_t fde_func_0291_0x0662e4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0662e4ULL ^ (static_cast<uint64_t>(0xd104c3ffULL) << 13);
    acc = (acc + a1 + 0x6d0d23e9ULL) ^ 0x1978b0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0292 | PC: 0x06674c | FDE: 0x197900 | Size: 96 bytes
// Khung tháo gỡ #0292 | Địa chỉ PC: 0x06674c | Địa chỉ FDE: 0x197900 | Kích thước: 96 bytes
//   0x06674c: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x066750: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x066754: 910043FD  add      x29, sp, #0x10
//   0x066758: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_0292_0x06674c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x06674cULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x197900ULL;
    acc ^= (acc >> 17) * 0x0060ULL;
    return acc;
}

// FDE #0293 | PC: 0x0667ac | FDE: 0x197938 | Size: 24 bytes
// Khung tháo gỡ #0293 | Địa chỉ PC: 0x0667ac | Địa chỉ FDE: 0x197938 | Kích thước: 24 bytes
//   0x0667ac: D65F03C0  ret      
//   0x0667b0: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x0667b4: 910003FD  mov      x29, sp
//   0x0667b8: 97FF1E36  bl       #0x2e090
static inline uint64_t fde_func_0293_0x0667ac(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0667acULL ^ (static_cast<uint64_t>(0xd65f03c0ULL) << 13);
    acc = (acc + a1 + 0xa9bf7bfdULL) ^ 0x197938ULL;
    acc ^= (acc >> 17) * 0x0018ULL;
    return acc;
}

// FDE #0294 | PC: 0x0667c4 | FDE: 0x197970 | Size: 256 bytes
// Khung tháo gỡ #0294 | Địa chỉ PC: 0x0667c4 | Địa chỉ FDE: 0x197970 | Kích thước: 256 bytes
//   0x0667c4: D10143FF  sub      sp, sp, #0x50
//   0x0667c8: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x0667cc: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x0667d0: A9047BFD  stp      x29, x30, [sp, #0x40]
static inline uint64_t fde_func_0294_0x0667c4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0667c4ULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xa90257f6ULL) ^ 0x197970ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0295 | PC: 0x066910 | FDE: 0x197a30 | Size: 256 bytes
// Khung tháo gỡ #0295 | Địa chỉ PC: 0x066910 | Địa chỉ FDE: 0x197a30 | Kích thước: 256 bytes
//   0x066910: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x066914: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x066918: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x06691c: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0295_0x066910(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x066910ULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x197a30ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0296 | PC: 0x066a18 | FDE: 0x197a70 | Size: 116 bytes
// Khung tháo gỡ #0296 | Địa chỉ PC: 0x066a18 | Địa chỉ FDE: 0x197a70 | Kích thước: 116 bytes
//   0x066a18: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x066a1c: 910003FD  mov      x29, sp
//   0x066a20: B0000BA8  adrp     x8, #0x1db000
//   0x066a24: 91366108  add      x8, x8, #0xd98
static inline uint64_t fde_func_0296_0x066a18(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x066a18ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x197a70ULL;
    acc ^= (acc >> 17) * 0x0074ULL;
    return acc;
}

// FDE #0297 | PC: 0x066a8c | FDE: 0x197ab0 | Size: 256 bytes
// Khung tháo gỡ #0297 | Địa chỉ PC: 0x066a8c | Địa chỉ FDE: 0x197ab0 | Kích thước: 256 bytes
//   0x066a8c: D10183FF  sub      sp, sp, #0x60
//   0x066a90: F9001BF5  str      x21, [sp, #0x30]
//   0x066a94: A9044FF4  stp      x20, x19, [sp, #0x40]
//   0x066a98: A9057BFD  stp      x29, x30, [sp, #0x50]
static inline uint64_t fde_func_0297_0x066a8c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x066a8cULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xf9001bf5ULL) ^ 0x197ab0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0298 | PC: 0x066cfc | FDE: 0x197af0 | Size: 256 bytes
// Khung tháo gỡ #0298 | Địa chỉ PC: 0x066cfc | Địa chỉ FDE: 0x197af0 | Kích thước: 256 bytes
//   0x066cfc: D10103FF  sub      sp, sp, #0x40
//   0x066d00: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x066d04: A9037BFD  stp      x29, x30, [sp, #0x30]
//   0x066d08: 9100C3FD  add      x29, sp, #0x30
static inline uint64_t fde_func_0298_0x066cfc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x066cfcULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xa9024ff4ULL) ^ 0x197af0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0299 | PC: 0x066e08 | FDE: 0x197b30 | Size: 256 bytes
// Khung tháo gỡ #0299 | Địa chỉ PC: 0x066e08 | Địa chỉ FDE: 0x197b30 | Kích thước: 256 bytes
//   0x066e08: F81B0FF9  str      x25, [sp, #-0x50]!
//   0x066e0c: A9015FF8  stp      x24, x23, [sp, #0x10]
//   0x066e10: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x066e14: A9034FF4  stp      x20, x19, [sp, #0x30]
static inline uint64_t fde_func_0299_0x066e08(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x066e08ULL ^ (static_cast<uint64_t>(0xf81b0ff9ULL) << 13);
    acc = (acc + a1 + 0xa9015ff8ULL) ^ 0x197b30ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0300 | PC: 0x0677ac | FDE: 0x197b80 | Size: 256 bytes
// Khung tháo gỡ #0300 | Địa chỉ PC: 0x0677ac | Địa chỉ FDE: 0x197b80 | Kích thước: 256 bytes
//   0x0677ac: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x0677b0: 910003FD  mov      x29, sp
//   0x0677b4: 91002000  add      x0, x0, #8
//   0x0677b8: 9403610B  bl       #0x13fbe4
static inline uint64_t fde_func_0300_0x0677ac(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0677acULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x197b80ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0301 | PC: 0x067a48 | FDE: 0x197bc0 | Size: 256 bytes
// Khung tháo gỡ #0301 | Địa chỉ PC: 0x067a48 | Địa chỉ FDE: 0x197bc0 | Kích thước: 256 bytes
//   0x067a48: F81C0FF7  str      x23, [sp, #-0x40]!
//   0x067a4c: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x067a50: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x067a54: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_0301_0x067a48(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x067a48ULL ^ (static_cast<uint64_t>(0xf81c0ff7ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x197bc0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0302 | PC: 0x067da0 | FDE: 0x197c10 | Size: 256 bytes
// Khung tháo gỡ #0302 | Địa chỉ PC: 0x067da0 | Địa chỉ FDE: 0x197c10 | Kích thước: 256 bytes
//   0x067da0: D10383FF  sub      sp, sp, #0xe0
//   0x067da4: F90053F7  str      x23, [sp, #0xa0]
//   0x067da8: A90B57F6  stp      x22, x21, [sp, #0xb0]
//   0x067dac: A90C4FF4  stp      x20, x19, [sp, #0xc0]
static inline uint64_t fde_func_0302_0x067da0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x067da0ULL ^ (static_cast<uint64_t>(0xd10383ffULL) << 13);
    acc = (acc + a1 + 0xf90053f7ULL) ^ 0x197c10ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0303 | PC: 0x068074 | FDE: 0x197c58 | Size: 256 bytes
// Khung tháo gỡ #0303 | Địa chỉ PC: 0x068074 | Địa chỉ FDE: 0x197c58 | Kích thước: 256 bytes
//   0x068074: D10403FF  sub      sp, sp, #0x100
//   0x068078: FD004BE8  str      d8, [sp, #0x90]
//   0x06807c: A90A6FFC  stp      x28, x27, [sp, #0xa0]
//   0x068080: A90B67FA  stp      x26, x25, [sp, #0xb0]
static inline uint64_t fde_func_0303_0x068074(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x068074ULL ^ (static_cast<uint64_t>(0xd10403ffULL) << 13);
    acc = (acc + a1 + 0xfd004be8ULL) ^ 0x197c58ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0304 | PC: 0x068950 | FDE: 0x197ca8 | Size: 256 bytes
// Khung tháo gỡ #0304 | Địa chỉ PC: 0x068950 | Địa chỉ FDE: 0x197ca8 | Kích thước: 256 bytes
//   0x068950: D10383FF  sub      sp, sp, #0xe0
//   0x068954: F90053F7  str      x23, [sp, #0xa0]
//   0x068958: A90B57F6  stp      x22, x21, [sp, #0xb0]
//   0x06895c: A90C4FF4  stp      x20, x19, [sp, #0xc0]
static inline uint64_t fde_func_0304_0x068950(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x068950ULL ^ (static_cast<uint64_t>(0xd10383ffULL) << 13);
    acc = (acc + a1 + 0xf90053f7ULL) ^ 0x197ca8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0305 | PC: 0x068c08 | FDE: 0x197ce8 | Size: 24 bytes
// Khung tháo gỡ #0305 | Địa chỉ PC: 0x068c08 | Địa chỉ FDE: 0x197ce8 | Kích thước: 24 bytes
//   0x068c08: 3900011F  strb     wzr, [x8]
//   0x068c0c: 3900411F  strb     wzr, [x8, #0x10]
//   0x068c10: D65F03C0  ret      
//   0x068c14: 3900011F  strb     wzr, [x8]
static inline uint64_t fde_func_0305_0x068c08(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x068c08ULL ^ (static_cast<uint64_t>(0x3900011fULL) << 13);
    acc = (acc + a1 + 0x3900411fULL) ^ 0x197ce8ULL;
    acc ^= (acc >> 17) * 0x0018ULL;
    return acc;
}

// FDE #0306 | PC: 0x068c20 | FDE: 0x197d18 | Size: 20 bytes
// Khung tháo gỡ #0306 | Địa chỉ PC: 0x068c20 | Địa chỉ FDE: 0x197d18 | Kích thước: 20 bytes
//   0x068c20: 3900011F  strb     wzr, [x8]
//   0x068c24: 3900611F  strb     wzr, [x8, #0x18]
//   0x068c28: D65F03C0  ret      
//   0x068c2c: AA1F03E0  mov      x0, xzr
static inline uint64_t fde_func_0306_0x068c20(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x068c20ULL ^ (static_cast<uint64_t>(0x3900011fULL) << 13);
    acc = (acc + a1 + 0x3900611fULL) ^ 0x197d18ULL;
    acc ^= (acc >> 17) * 0x0014ULL;
    return acc;
}

// FDE #0307 | PC: 0x068c34 | FDE: 0x197d48 | Size: 20 bytes
// Khung tháo gỡ #0307 | Địa chỉ PC: 0x068c34 | Địa chỉ FDE: 0x197d48 | Kích thước: 20 bytes
//   0x068c34: AA1F03E0  mov      x0, xzr
//   0x068c38: D65F03C0  ret      
//   0x068c3c: 3900011F  strb     wzr, [x8]
//   0x068c40: 3900811F  strb     wzr, [x8, #0x20]
static inline uint64_t fde_func_0307_0x068c34(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x068c34ULL ^ (static_cast<uint64_t>(0xaa1f03e0ULL) << 13);
    acc = (acc + a1 + 0xd65f03c0ULL) ^ 0x197d48ULL;
    acc ^= (acc >> 17) * 0x0014ULL;
    return acc;
}

// FDE #0308 | PC: 0x068c48 | FDE: 0x197d78 | Size: 20 bytes
// Khung tháo gỡ #0308 | Địa chỉ PC: 0x068c48 | Địa chỉ FDE: 0x197d78 | Kích thước: 20 bytes
//   0x068c48: 3900011F  strb     wzr, [x8]
//   0x068c4c: 3900411F  strb     wzr, [x8, #0x10]
//   0x068c50: D65F03C0  ret      
//   0x068c54: AA1F03E0  mov      x0, xzr
static inline uint64_t fde_func_0308_0x068c48(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x068c48ULL ^ (static_cast<uint64_t>(0x3900011fULL) << 13);
    acc = (acc + a1 + 0x3900411fULL) ^ 0x197d78ULL;
    acc ^= (acc >> 17) * 0x0014ULL;
    return acc;
}

// FDE #0309 | PC: 0x068c5c | FDE: 0x197da8 | Size: 16 bytes
// Khung tháo gỡ #0309 | Địa chỉ PC: 0x068c5c | Địa chỉ FDE: 0x197da8 | Kích thước: 16 bytes
//   0x068c5c: 3900011F  strb     wzr, [x8]
//   0x068c60: 3900611F  strb     wzr, [x8, #0x18]
//   0x068c64: D65F03C0  ret      
//   0x068c68: D65F03C0  ret      
static inline uint64_t fde_func_0309_0x068c5c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x068c5cULL ^ (static_cast<uint64_t>(0x3900011fULL) << 13);
    acc = (acc + a1 + 0x3900611fULL) ^ 0x197da8ULL;
    acc ^= (acc >> 17) * 0x0010ULL;
    return acc;
}

// FDE #0310 | PC: 0x068c6c | FDE: 0x197dd8 | Size: 20 bytes
// Khung tháo gỡ #0310 | Địa chỉ PC: 0x068c6c | Địa chỉ FDE: 0x197dd8 | Kích thước: 20 bytes
//   0x068c6c: 3900011F  strb     wzr, [x8]
//   0x068c70: 3900411F  strb     wzr, [x8, #0x10]
//   0x068c74: D65F03C0  ret      
//   0x068c78: 2A1F03E0  mov      w0, wzr
static inline uint64_t fde_func_0310_0x068c6c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x068c6cULL ^ (static_cast<uint64_t>(0x3900011fULL) << 13);
    acc = (acc + a1 + 0x3900411fULL) ^ 0x197dd8ULL;
    acc ^= (acc >> 17) * 0x0014ULL;
    return acc;
}

// FDE #0311 | PC: 0x068c80 | FDE: 0x197e08 | Size: 144 bytes
// Khung tháo gỡ #0311 | Địa chỉ PC: 0x068c80 | Địa chỉ FDE: 0x197e08 | Kích thước: 144 bytes
//   0x068c80: B4000221  cbz      x1, #0x68cc4
//   0x068c84: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x068c88: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x068c8c: 910043FD  add      x29, sp, #0x10
static inline uint64_t fde_func_0311_0x068c80(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x068c80ULL ^ (static_cast<uint64_t>(0xb4000221ULL) << 13);
    acc = (acc + a1 + 0xa9be4ff4ULL) ^ 0x197e08ULL;
    acc ^= (acc >> 17) * 0x0090ULL;
    return acc;
}

// FDE #0312 | PC: 0x068d10 | FDE: 0x197e48 | Size: 84 bytes
// Khung tháo gỡ #0312 | Địa chỉ PC: 0x068d10 | Địa chỉ FDE: 0x197e48 | Kích thước: 84 bytes
//   0x068d10: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x068d14: 910003FD  mov      x29, sp
//   0x068d18: F0000AC8  adrp     x8, #0x1c3000
//   0x068d1c: 9101A108  add      x8, x8, #0x68
static inline uint64_t fde_func_0312_0x068d10(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x068d10ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x197e48ULL;
    acc ^= (acc >> 17) * 0x0054ULL;
    return acc;
}

// FDE #0313 | PC: 0x068d64 | FDE: 0x197e88 | Size: 124 bytes
// Khung tháo gỡ #0313 | Địa chỉ PC: 0x068d64 | Địa chỉ FDE: 0x197e88 | Kích thước: 124 bytes
//   0x068d64: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x068d68: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x068d6c: 910043FD  add      x29, sp, #0x10
//   0x068d70: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_0313_0x068d64(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x068d64ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x197e88ULL;
    acc ^= (acc >> 17) * 0x007cULL;
    return acc;
}

// FDE #0314 | PC: 0x068de0 | FDE: 0x197ec8 | Size: 68 bytes
// Khung tháo gỡ #0314 | Địa chỉ PC: 0x068de0 | Địa chỉ FDE: 0x197ec8 | Kích thước: 68 bytes
//   0x068de0: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x068de4: 910003FD  mov      x29, sp
//   0x068de8: 91004000  add      x0, x0, #0x10
//   0x068dec: 94035B7E  bl       #0x13fbe4
static inline uint64_t fde_func_0314_0x068de0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x068de0ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x197ec8ULL;
    acc ^= (acc >> 17) * 0x0044ULL;
    return acc;
}

// FDE #0315 | PC: 0x068e24 | FDE: 0x197f08 | Size: 256 bytes
// Khung tháo gỡ #0315 | Địa chỉ PC: 0x068e24 | Địa chỉ FDE: 0x197f08 | Kích thước: 256 bytes
//   0x068e24: D10383FF  sub      sp, sp, #0xe0
//   0x068e28: A90A5FF8  stp      x24, x23, [sp, #0xa0]
//   0x068e2c: A90B57F6  stp      x22, x21, [sp, #0xb0]
//   0x068e30: A90C4FF4  stp      x20, x19, [sp, #0xc0]
static inline uint64_t fde_func_0315_0x068e24(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x068e24ULL ^ (static_cast<uint64_t>(0xd10383ffULL) << 13);
    acc = (acc + a1 + 0xa90a5ff8ULL) ^ 0x197f08ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0316 | PC: 0x0691d0 | FDE: 0x197f50 | Size: 80 bytes
// Khung tháo gỡ #0316 | Địa chỉ PC: 0x0691d0 | Địa chỉ FDE: 0x197f50 | Kích thước: 80 bytes
//   0x0691d0: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x0691d4: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0691d8: 910043FD  add      x29, sp, #0x10
//   0x0691dc: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_0316_0x0691d0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0691d0ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x197f50ULL;
    acc ^= (acc >> 17) * 0x0050ULL;
    return acc;
}

// FDE #0317 | PC: 0x069220 | FDE: 0x197f88 | Size: 24 bytes
// Khung tháo gỡ #0317 | Địa chỉ PC: 0x069220 | Địa chỉ FDE: 0x197f88 | Kích thước: 24 bytes
//   0x069220: D65F03C0  ret      
//   0x069224: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x069228: 910003FD  mov      x29, sp
//   0x06922c: 97FF1399  bl       #0x2e090
static inline uint64_t fde_func_0317_0x069220(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x069220ULL ^ (static_cast<uint64_t>(0xd65f03c0ULL) << 13);
    acc = (acc + a1 + 0xa9bf7bfdULL) ^ 0x197f88ULL;
    acc ^= (acc >> 17) * 0x0018ULL;
    return acc;
}

// FDE #0318 | PC: 0x069238 | FDE: 0x197fc0 | Size: 68 bytes
// Khung tháo gỡ #0318 | Địa chỉ PC: 0x069238 | Địa chỉ FDE: 0x197fc0 | Kích thước: 68 bytes
//   0x069238: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x06923c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x069240: 910043FD  add      x29, sp, #0x10
//   0x069244: F9400413  ldr      x19, [x0, #8]
static inline uint64_t fde_func_0318_0x069238(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x069238ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x197fc0ULL;
    acc ^= (acc >> 17) * 0x0044ULL;
    return acc;
}

// FDE #0319 | PC: 0x06927c | FDE: 0x198000 | Size: 80 bytes
// Khung tháo gỡ #0319 | Địa chỉ PC: 0x06927c | Địa chỉ FDE: 0x198000 | Kích thước: 80 bytes
//   0x06927c: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x069280: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x069284: 910043FD  add      x29, sp, #0x10
//   0x069288: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_0319_0x06927c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x06927cULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x198000ULL;
    acc ^= (acc >> 17) * 0x0050ULL;
    return acc;
}

// FDE #0320 | PC: 0x0692cc | FDE: 0x198038 | Size: 24 bytes
// Khung tháo gỡ #0320 | Địa chỉ PC: 0x0692cc | Địa chỉ FDE: 0x198038 | Kích thước: 24 bytes
//   0x0692cc: D65F03C0  ret      
//   0x0692d0: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x0692d4: 910003FD  mov      x29, sp
//   0x0692d8: 97FF136E  bl       #0x2e090
static inline uint64_t fde_func_0320_0x0692cc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0692ccULL ^ (static_cast<uint64_t>(0xd65f03c0ULL) << 13);
    acc = (acc + a1 + 0xa9bf7bfdULL) ^ 0x198038ULL;
    acc ^= (acc >> 17) * 0x0018ULL;
    return acc;
}

// FDE #0321 | PC: 0x0692e4 | FDE: 0x198070 | Size: 84 bytes
// Khung tháo gỡ #0321 | Địa chỉ PC: 0x0692e4 | Địa chỉ FDE: 0x198070 | Kích thước: 84 bytes
//   0x0692e4: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0692e8: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0692ec: 910043FD  add      x29, sp, #0x10
//   0x0692f0: A940CC14  ldp      x20, x19, [x0, #8]
static inline uint64_t fde_func_0321_0x0692e4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0692e4ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x198070ULL;
    acc ^= (acc >> 17) * 0x0054ULL;
    return acc;
}

// FDE #0322 | PC: 0x069338 | FDE: 0x1980b0 | Size: 80 bytes
// Khung tháo gỡ #0322 | Địa chỉ PC: 0x069338 | Địa chỉ FDE: 0x1980b0 | Kích thước: 80 bytes
//   0x069338: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x06933c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x069340: 910043FD  add      x29, sp, #0x10
//   0x069344: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_0322_0x069338(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x069338ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1980b0ULL;
    acc ^= (acc >> 17) * 0x0050ULL;
    return acc;
}

// FDE #0323 | PC: 0x069388 | FDE: 0x1980e8 | Size: 24 bytes
// Khung tháo gỡ #0323 | Địa chỉ PC: 0x069388 | Địa chỉ FDE: 0x1980e8 | Kích thước: 24 bytes
//   0x069388: D65F03C0  ret      
//   0x06938c: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x069390: 910003FD  mov      x29, sp
//   0x069394: 97FF133F  bl       #0x2e090
static inline uint64_t fde_func_0323_0x069388(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x069388ULL ^ (static_cast<uint64_t>(0xd65f03c0ULL) << 13);
    acc = (acc + a1 + 0xa9bf7bfdULL) ^ 0x1980e8ULL;
    acc ^= (acc >> 17) * 0x0018ULL;
    return acc;
}

// FDE #0324 | PC: 0x0693a0 | FDE: 0x198120 | Size: 96 bytes
// Khung tháo gỡ #0324 | Địa chỉ PC: 0x0693a0 | Địa chỉ FDE: 0x198120 | Kích thước: 96 bytes
//   0x0693a0: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x0693a4: 910003FD  mov      x29, sp
//   0x0693a8: F9400400  ldr      x0, [x0, #8]
//   0x0693ac: 97FFF5B8  bl       #0x66a8c
static inline uint64_t fde_func_0324_0x0693a0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0693a0ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x198120ULL;
    acc ^= (acc >> 17) * 0x0060ULL;
    return acc;
}

// FDE #0325 | PC: 0x069400 | FDE: 0x198160 | Size: 24 bytes
// Khung tháo gỡ #0325 | Địa chỉ PC: 0x069400 | Địa chỉ FDE: 0x198160 | Kích thước: 24 bytes
//   0x069400: D65F03C0  ret      
//   0x069404: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x069408: 910003FD  mov      x29, sp
//   0x06940c: 97FF1321  bl       #0x2e090
static inline uint64_t fde_func_0325_0x069400(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x069400ULL ^ (static_cast<uint64_t>(0xd65f03c0ULL) << 13);
    acc = (acc + a1 + 0xa9bf7bfdULL) ^ 0x198160ULL;
    acc ^= (acc >> 17) * 0x0018ULL;
    return acc;
}

// FDE #0326 | PC: 0x069418 | FDE: 0x198198 | Size: 256 bytes
// Khung tháo gỡ #0326 | Địa chỉ PC: 0x069418 | Địa chỉ FDE: 0x198198 | Kích thước: 256 bytes
//   0x069418: D10143FF  sub      sp, sp, #0x50
//   0x06941c: F90013F5  str      x21, [sp, #0x20]
//   0x069420: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x069424: A9047BFD  stp      x29, x30, [sp, #0x40]
static inline uint64_t fde_func_0326_0x069418(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x069418ULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xf90013f5ULL) ^ 0x198198ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0327 | PC: 0x069788 | FDE: 0x1981e0 | Size: 256 bytes
// Khung tháo gỡ #0327 | Địa chỉ PC: 0x069788 | Địa chỉ FDE: 0x1981e0 | Kích thước: 256 bytes
//   0x069788: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x06978c: 910003FD  mov      x29, sp
//   0x069790: D0000AC8  adrp     x8, #0x1c3000
//   0x069794: 9106A108  add      x8, x8, #0x1a8
static inline uint64_t fde_func_0327_0x069788(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x069788ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1981e0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0328 | PC: 0x069908 | FDE: 0x198228 | Size: 72 bytes
// Khung tháo gỡ #0328 | Địa chỉ PC: 0x069908 | Địa chỉ FDE: 0x198228 | Kích thước: 72 bytes
//   0x069908: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x06990c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x069910: 910043FD  add      x29, sp, #0x10
//   0x069914: D0000AC8  adrp     x8, #0x1c3000
static inline uint64_t fde_func_0328_0x069908(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x069908ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x198228ULL;
    acc ^= (acc >> 17) * 0x0048ULL;
    return acc;
}

// FDE #0329 | PC: 0x069950 | FDE: 0x1982d8 | Size: 256 bytes
// Khung tháo gỡ #0329 | Địa chỉ PC: 0x069950 | Địa chỉ FDE: 0x1982d8 | Kích thước: 256 bytes
//   0x069950: 6F00E400  movi     v0.2d, #0000000000000000
//   0x069954: AA0003E8  mov      x8, x0
//   0x069958: AD000000  stp      q0, q0, [x0]
//   0x06995c: F8030D1F  str      xzr, [x8, #0x30]!
static inline uint64_t fde_func_0329_0x069950(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x069950ULL ^ (static_cast<uint64_t>(0x6f00e400ULL) << 13);
    acc = (acc + a1 + 0xaa0003e8ULL) ^ 0x1982d8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0330 | PC: 0x069bd0 | FDE: 0x198320 | Size: 256 bytes
// Khung tháo gỡ #0330 | Địa chỉ PC: 0x069bd0 | Địa chỉ FDE: 0x198320 | Kích thước: 256 bytes
//   0x069bd0: D101C3FF  sub      sp, sp, #0x70
//   0x069bd4: A90267FA  stp      x26, x25, [sp, #0x20]
//   0x069bd8: A9035FF8  stp      x24, x23, [sp, #0x30]
//   0x069bdc: A90457F6  stp      x22, x21, [sp, #0x40]
static inline uint64_t fde_func_0330_0x069bd0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x069bd0ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xa90267faULL) ^ 0x198320ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0331 | PC: 0x069f2c | FDE: 0x198378 | Size: 256 bytes
// Khung tháo gỡ #0331 | Địa chỉ PC: 0x069f2c | Địa chỉ FDE: 0x198378 | Kích thước: 256 bytes
//   0x069f2c: D10183FF  sub      sp, sp, #0x60
//   0x069f30: F90013F7  str      x23, [sp, #0x20]
//   0x069f34: A90357F6  stp      x22, x21, [sp, #0x30]
//   0x069f38: A9044FF4  stp      x20, x19, [sp, #0x40]
static inline uint64_t fde_func_0331_0x069f2c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x069f2cULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xf90013f7ULL) ^ 0x198378ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0332 | PC: 0x06e2a8 | FDE: 0x1983d0 | Size: 256 bytes
// Khung tháo gỡ #0332 | Địa chỉ PC: 0x06e2a8 | Địa chỉ FDE: 0x1983d0 | Kích thước: 256 bytes
//   0x06e2a8: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x06e2ac: 910003FD  mov      x29, sp
//   0x06e2b0: B0000B68  adrp     x8, #0x1db000
//   0x06e2b4: 9137A108  add      x8, x8, #0xde8
static inline uint64_t fde_func_0332_0x06e2a8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x06e2a8ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1983d0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0333 | PC: 0x06e3ac | FDE: 0x198410 | Size: 256 bytes
// Khung tháo gỡ #0333 | Địa chỉ PC: 0x06e3ac | Địa chỉ FDE: 0x198410 | Kích thước: 256 bytes
//   0x06e3ac: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x06e3b0: 910003FD  mov      x29, sp
//   0x06e3b4: B0000B68  adrp     x8, #0x1db000
//   0x06e3b8: 91382108  add      x8, x8, #0xe08
static inline uint64_t fde_func_0333_0x06e3ac(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x06e3acULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x198410ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0334 | PC: 0x06e4ac | FDE: 0x198450 | Size: 256 bytes
// Khung tháo gỡ #0334 | Địa chỉ PC: 0x06e4ac | Địa chỉ FDE: 0x198450 | Kích thước: 256 bytes
//   0x06e4ac: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x06e4b0: 910003FD  mov      x29, sp
//   0x06e4b4: B0000B68  adrp     x8, #0x1db000
//   0x06e4b8: 9138A108  add      x8, x8, #0xe28
static inline uint64_t fde_func_0334_0x06e4ac(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x06e4acULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x198450ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0335 | PC: 0x06e638 | FDE: 0x198498 | Size: 256 bytes
// Khung tháo gỡ #0335 | Địa chỉ PC: 0x06e638 | Địa chỉ FDE: 0x198498 | Kích thước: 256 bytes
//   0x06e638: A9BC5FF8  stp      x24, x23, [sp, #-0x40]!
//   0x06e63c: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x06e640: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x06e644: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_0335_0x06e638(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x06e638ULL ^ (static_cast<uint64_t>(0xa9bc5ff8ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x198498ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0336 | PC: 0x06e75c | FDE: 0x198550 | Size: 256 bytes
// Khung tháo gỡ #0336 | Địa chỉ PC: 0x06e75c | Địa chỉ FDE: 0x198550 | Kích thước: 256 bytes
//   0x06e75c: A9BA6FFC  stp      x28, x27, [sp, #-0x60]!
//   0x06e760: A90167FA  stp      x26, x25, [sp, #0x10]
//   0x06e764: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x06e768: A90357F6  stp      x22, x21, [sp, #0x30]
static inline uint64_t fde_func_0336_0x06e75c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x06e75cULL ^ (static_cast<uint64_t>(0xa9ba6ffcULL) << 13);
    acc = (acc + a1 + 0xa90167faULL) ^ 0x198550ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0337 | PC: 0x06eef0 | FDE: 0x1985a0 | Size: 256 bytes
// Khung tháo gỡ #0337 | Địa chỉ PC: 0x06eef0 | Địa chỉ FDE: 0x1985a0 | Kích thước: 256 bytes
//   0x06eef0: A9BA6FFC  stp      x28, x27, [sp, #-0x60]!
//   0x06eef4: A90167FA  stp      x26, x25, [sp, #0x10]
//   0x06eef8: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x06eefc: A90357F6  stp      x22, x21, [sp, #0x30]
static inline uint64_t fde_func_0337_0x06eef0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x06eef0ULL ^ (static_cast<uint64_t>(0xa9ba6ffcULL) << 13);
    acc = (acc + a1 + 0xa90167faULL) ^ 0x1985a0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0338 | PC: 0x06f410 | FDE: 0x1985f0 | Size: 132 bytes
// Khung tháo gỡ #0338 | Địa chỉ PC: 0x06f410 | Địa chỉ FDE: 0x1985f0 | Kích thước: 132 bytes
//   0x06f410: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x06f414: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x06f418: 910043FD  add      x29, sp, #0x10
//   0x06f41c: 90000AA8  adrp     x8, #0x1c3000
static inline uint64_t fde_func_0338_0x06f410(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x06f410ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1985f0ULL;
    acc ^= (acc >> 17) * 0x0084ULL;
    return acc;
}

// FDE #0339 | PC: 0x06f494 | FDE: 0x198630 | Size: 256 bytes
// Khung tháo gỡ #0339 | Địa chỉ PC: 0x06f494 | Địa chỉ FDE: 0x198630 | Kích thước: 256 bytes
//   0x06f494: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x06f498: 910003FD  mov      x29, sp
//   0x06f49c: 9000000A  adrp     x10, #0x6f000
//   0x06f4a0: AA0003E9  mov      x9, x0
static inline uint64_t fde_func_0339_0x06f494(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x06f494ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x198630ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0340 | PC: 0x06f654 | FDE: 0x198670 | Size: 256 bytes
// Khung tháo gỡ #0340 | Địa chỉ PC: 0x06f654 | Địa chỉ FDE: 0x198670 | Kích thước: 256 bytes
//   0x06f654: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x06f658: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x06f65c: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x06f660: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0340_0x06f654(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x06f654ULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x198670ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0341 | PC: 0x06f7dc | FDE: 0x1986d8 | Size: 256 bytes
// Khung tháo gỡ #0341 | Địa chỉ PC: 0x06f7dc | Địa chỉ FDE: 0x1986d8 | Kích thước: 256 bytes
//   0x06f7dc: AA1E03E4  mov      x4, x30
//   0x06f7e0: 8B000084  add      x4, x4, x0
//   0x06f7e4: AA0403FE  mov      x30, x4
//   0x06f7e8: D65F03C0  ret      
static inline uint64_t fde_func_0341_0x06f7dc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x06f7dcULL ^ (static_cast<uint64_t>(0xaa1e03e4ULL) << 13);
    acc = (acc + a1 + 0x8b000084ULL) ^ 0x1986d8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0342 | PC: 0x06f9ac | FDE: 0x198710 | Size: 256 bytes
// Khung tháo gỡ #0342 | Địa chỉ PC: 0x06f9ac | Địa chỉ FDE: 0x198710 | Kích thước: 256 bytes
//   0x06f9ac: D10243FF  sub      sp, sp, #0x90
//   0x06f9b0: A9036FFC  stp      x28, x27, [sp, #0x30]
//   0x06f9b4: A90467FA  stp      x26, x25, [sp, #0x40]
//   0x06f9b8: A9055FF8  stp      x24, x23, [sp, #0x50]
static inline uint64_t fde_func_0342_0x06f9ac(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x06f9acULL ^ (static_cast<uint64_t>(0xd10243ffULL) << 13);
    acc = (acc + a1 + 0xa9036ffcULL) ^ 0x198710ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0343 | PC: 0x06fbe0 | FDE: 0x198760 | Size: 256 bytes
// Khung tháo gỡ #0343 | Địa chỉ PC: 0x06fbe0 | Địa chỉ FDE: 0x198760 | Kích thước: 256 bytes
//   0x06fbe0: D10103FF  sub      sp, sp, #0x40
//   0x06fbe4: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x06fbe8: A9037BFD  stp      x29, x30, [sp, #0x30]
//   0x06fbec: 9100C3FD  add      x29, sp, #0x30
static inline uint64_t fde_func_0343_0x06fbe0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x06fbe0ULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xa9024ff4ULL) ^ 0x198760ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0344 | PC: 0x06fd88 | FDE: 0x198818 | Size: 256 bytes
// Khung tháo gỡ #0344 | Địa chỉ PC: 0x06fd88 | Địa chỉ FDE: 0x198818 | Kích thước: 256 bytes
//   0x06fd88: A9BB67FA  stp      x26, x25, [sp, #-0x50]!
//   0x06fd8c: A9015FF8  stp      x24, x23, [sp, #0x10]
//   0x06fd90: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x06fd94: A9034FF4  stp      x20, x19, [sp, #0x30]
static inline uint64_t fde_func_0344_0x06fd88(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x06fd88ULL ^ (static_cast<uint64_t>(0xa9bb67faULL) << 13);
    acc = (acc + a1 + 0xa9015ff8ULL) ^ 0x198818ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0345 | PC: 0x06ff88 | FDE: 0x198878 | Size: 256 bytes
// Khung tháo gỡ #0345 | Địa chỉ PC: 0x06ff88 | Địa chỉ FDE: 0x198878 | Kích thước: 256 bytes
//   0x06ff88: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x06ff8c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x06ff90: 910043FD  add      x29, sp, #0x10
//   0x06ff94: A940D013  ldp      x19, x20, [x0, #8]
static inline uint64_t fde_func_0345_0x06ff88(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x06ff88ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x198878ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0346 | PC: 0x070410 | FDE: 0x1988c8 | Size: 200 bytes
// Khung tháo gỡ #0346 | Địa chỉ PC: 0x070410 | Địa chỉ FDE: 0x1988c8 | Kích thước: 200 bytes
//   0x070410: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x070414: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x070418: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x07041c: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0346_0x070410(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x070410ULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1988c8ULL;
    acc ^= (acc >> 17) * 0x00c8ULL;
    return acc;
}

// FDE #0347 | PC: 0x0704d8 | FDE: 0x198928 | Size: 56 bytes
// Khung tháo gỡ #0347 | Địa chỉ PC: 0x0704d8 | Địa chỉ FDE: 0x198928 | Kích thước: 56 bytes
//   0x0704d8: AA1E03E1  mov      x1, x30
//   0x0704dc: 8B000021  add      x1, x1, x0
//   0x0704e0: AA0103FE  mov      x30, x1
//   0x0704e4: D65F03C0  ret      
static inline uint64_t fde_func_0347_0x0704d8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0704d8ULL ^ (static_cast<uint64_t>(0xaa1e03e1ULL) << 13);
    acc = (acc + a1 + 0x8b000021ULL) ^ 0x198928ULL;
    acc ^= (acc >> 17) * 0x0038ULL;
    return acc;
}

// FDE #0348 | PC: 0x070510 | FDE: 0x198958 | Size: 176 bytes
// Khung tháo gỡ #0348 | Địa chỉ PC: 0x070510 | Địa chỉ FDE: 0x198958 | Kích thước: 176 bytes
//   0x070510: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x070514: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x070518: 910043FD  add      x29, sp, #0x10
//   0x07051c: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_0348_0x070510(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x070510ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x198958ULL;
    acc ^= (acc >> 17) * 0x00b0ULL;
    return acc;
}

// FDE #0349 | PC: 0x0705c0 | FDE: 0x198998 | Size: 44 bytes
// Khung tháo gỡ #0349 | Địa chỉ PC: 0x0705c0 | Địa chỉ FDE: 0x198998 | Kích thước: 44 bytes
//   0x0705c0: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x0705c4: 910003FD  mov      x29, sp
//   0x0705c8: F9000001  str      x1, [x0]
//   0x0705cc: AA0103E0  mov      x0, x1
static inline uint64_t fde_func_0349_0x0705c0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0705c0ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x198998ULL;
    acc ^= (acc >> 17) * 0x002cULL;
    return acc;
}

// FDE #0350 | PC: 0x0705ec | FDE: 0x1989d0 | Size: 52 bytes
// Khung tháo gỡ #0350 | Địa chỉ PC: 0x0705ec | Địa chỉ FDE: 0x1989d0 | Kích thước: 52 bytes
//   0x0705ec: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x0705f0: 910003FD  mov      x29, sp
//   0x0705f4: AA0103E2  mov      x2, x1
//   0x0705f8: 940001A2  bl       #0x70c80
static inline uint64_t fde_func_0350_0x0705ec(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0705ecULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1989d0ULL;
    acc ^= (acc >> 17) * 0x0034ULL;
    return acc;
}

// FDE #0351 | PC: 0x070620 | FDE: 0x198a10 | Size: 204 bytes
// Khung tháo gỡ #0351 | Địa chỉ PC: 0x070620 | Địa chỉ FDE: 0x198a10 | Kích thước: 204 bytes
//   0x070620: A9BE4FFC  stp      x28, x19, [sp, #-0x20]!
//   0x070624: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x070628: 910043FD  add      x29, sp, #0x10
//   0x07062c: D11383FF  sub      sp, sp, #0x4e0
static inline uint64_t fde_func_0351_0x070620(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x070620ULL ^ (static_cast<uint64_t>(0xa9be4ffcULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x198a10ULL;
    acc ^= (acc >> 17) * 0x00ccULL;
    return acc;
}

// FDE #0352 | PC: 0x0706ec | FDE: 0x198a50 | Size: 16 bytes
// Khung tháo gỡ #0352 | Địa chỉ PC: 0x0706ec | Địa chỉ FDE: 0x198a50 | Kích thước: 16 bytes
//   0x0706ec: F9400000  ldr      x0, [x0]
//   0x0706f0: D65F03C0  ret      
//   0x0706f4: 91002000  add      x0, x0, #8
//   0x0706f8: D65F03C0  ret      
static inline uint64_t fde_func_0352_0x0706ec(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0706ecULL ^ (static_cast<uint64_t>(0xf9400000ULL) << 13);
    acc = (acc + a1 + 0xd65f03c0ULL) ^ 0x198a50ULL;
    acc ^= (acc >> 17) * 0x0010ULL;
    return acc;
}

// FDE #0353 | PC: 0x0706fc | FDE: 0x198a80 | Size: 32 bytes
// Khung tháo gỡ #0353 | Địa chỉ PC: 0x0706fc | Địa chỉ FDE: 0x198a80 | Kích thước: 32 bytes
//   0x0706fc: F9400008  ldr      x8, [x0]
//   0x070700: F9400029  ldr      x9, [x1]
//   0x070704: EB09011F  cmp      x8, x9
//   0x070708: 1A9F07E0  cset     w0, ne
static inline uint64_t fde_func_0353_0x0706fc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0706fcULL ^ (static_cast<uint64_t>(0xf9400008ULL) << 13);
    acc = (acc + a1 + 0xf9400029ULL) ^ 0x198a80ULL;
    acc ^= (acc >> 17) * 0x0020ULL;
    return acc;
}

// FDE #0354 | PC: 0x07071c | FDE: 0x198ab0 | Size: 212 bytes
// Khung tháo gỡ #0354 | Địa chỉ PC: 0x07071c | Địa chỉ FDE: 0x198ab0 | Kích thước: 212 bytes
//   0x07071c: 39400428  ldrb     w8, [x1, #1]
//   0x070720: 39000408  strb     w8, [x0, #1]
//   0x070724: 39400028  ldrb     w8, [x1]
//   0x070728: 39000008  strb     w8, [x0]
static inline uint64_t fde_func_0354_0x07071c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07071cULL ^ (static_cast<uint64_t>(0x39400428ULL) << 13);
    acc = (acc + a1 + 0x39000408ULL) ^ 0x198ab0ULL;
    acc ^= (acc >> 17) * 0x00d4ULL;
    return acc;
}

// FDE #0355 | PC: 0x0707f0 | FDE: 0x198ae0 | Size: 188 bytes
// Khung tháo gỡ #0355 | Địa chỉ PC: 0x0707f0 | Địa chỉ FDE: 0x198ae0 | Kích thước: 188 bytes
//   0x0707f0: F940000A  ldr      x10, [x0]
//   0x0707f4: F9400549  ldr      x9, [x10, #8]
//   0x0707f8: B40000C9  cbz      x9, #0x70810
//   0x0707fc: AA0903E8  mov      x8, x9
static inline uint64_t fde_func_0355_0x0707f0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0707f0ULL ^ (static_cast<uint64_t>(0xf940000aULL) << 13);
    acc = (acc + a1 + 0xf9400549ULL) ^ 0x198ae0ULL;
    acc ^= (acc >> 17) * 0x00bcULL;
    return acc;
}

// FDE #0356 | PC: 0x0708ac | FDE: 0x198b18 | Size: 112 bytes
// Khung tháo gỡ #0356 | Địa chỉ PC: 0x0708ac | Địa chỉ FDE: 0x198b18 | Kích thước: 112 bytes
//   0x0708ac: D10043FF  sub      sp, sp, #0x10
//   0x0708b0: F9400408  ldr      x8, [x0, #8]
//   0x0708b4: 39400009  ldrb     w9, [x0]
//   0x0708b8: 4A08012A  eor      w10, w9, w8
static inline uint64_t fde_func_0356_0x0708ac(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0708acULL ^ (static_cast<uint64_t>(0xd10043ffULL) << 13);
    acc = (acc + a1 + 0xf9400408ULL) ^ 0x198b18ULL;
    acc ^= (acc >> 17) * 0x0070ULL;
    return acc;
}

// FDE #0357 | PC: 0x07091c | FDE: 0x198b48 | Size: 36 bytes
// Khung tháo gỡ #0357 | Địa chỉ PC: 0x07091c | Địa chỉ FDE: 0x198b48 | Kích thước: 36 bytes
//   0x07091c: F9400008  ldr      x8, [x0]
//   0x070920: 8B010100  add      x0, x8, x1
//   0x070924: D65F03C0  ret      
//   0x070928: 39400028  ldrb     w8, [x1]
static inline uint64_t fde_func_0357_0x07091c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07091cULL ^ (static_cast<uint64_t>(0xf9400008ULL) << 13);
    acc = (acc + a1 + 0x8b010100ULL) ^ 0x198b48ULL;
    acc ^= (acc >> 17) * 0x0024ULL;
    return acc;
}

// FDE #0358 | PC: 0x070940 | FDE: 0x198b78 | Size: 256 bytes
// Khung tháo gỡ #0358 | Địa chỉ PC: 0x070940 | Địa chỉ FDE: 0x198b78 | Kích thước: 256 bytes
//   0x070940: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x070944: 910003FD  mov      x29, sp
//   0x070948: F0000B48  adrp     x8, #0x1db000
//   0x07094c: 913BE108  add      x8, x8, #0xef8
static inline uint64_t fde_func_0358_0x070940(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x070940ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x198b78ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0359 | PC: 0x070a5c | FDE: 0x198bb8 | Size: 172 bytes
// Khung tháo gỡ #0359 | Địa chỉ PC: 0x070a5c | Địa chỉ FDE: 0x198bb8 | Kích thước: 172 bytes
//   0x070a5c: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x070a60: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x070a64: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x070a68: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0359_0x070a5c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x070a5cULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x198bb8ULL;
    acc ^= (acc >> 17) * 0x00acULL;
    return acc;
}

// FDE #0360 | PC: 0x070b08 | FDE: 0x198bf8 | Size: 208 bytes
// Khung tháo gỡ #0360 | Địa chỉ PC: 0x070b08 | Địa chỉ FDE: 0x198bf8 | Kích thước: 208 bytes
//   0x070b08: 39400008  ldrb     w8, [x0]
//   0x070b0c: 37000088  tbnz     w8, #0, #0x70b1c
//   0x070b10: 91000408  add      x8, x0, #1
//   0x070b14: 8B010100  add      x0, x8, x1
static inline uint64_t fde_func_0360_0x070b08(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x070b08ULL ^ (static_cast<uint64_t>(0x39400008ULL) << 13);
    acc = (acc + a1 + 0x37000088ULL) ^ 0x198bf8ULL;
    acc ^= (acc >> 17) * 0x00d0ULL;
    return acc;
}

// FDE #0361 | PC: 0x070bd8 | FDE: 0x198c30 | Size: 68 bytes
// Khung tháo gỡ #0361 | Địa chỉ PC: 0x070bd8 | Địa chỉ FDE: 0x198c30 | Kích thước: 68 bytes
//   0x070bd8: 39400008  ldrb     w8, [x0]
//   0x070bdc: B940002A  ldr      w10, [x1]
//   0x070be0: 53017D09  lsr      w9, w8, #1
//   0x070be4: 33191D09  bfi      w9, w8, #7, #8
static inline uint64_t fde_func_0361_0x070bd8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x070bd8ULL ^ (static_cast<uint64_t>(0x39400008ULL) << 13);
    acc = (acc + a1 + 0xb940002aULL) ^ 0x198c30ULL;
    acc ^= (acc >> 17) * 0x0044ULL;
    return acc;
}

// FDE #0362 | PC: 0x070c1c | FDE: 0x198c68 | Size: 100 bytes
// Khung tháo gỡ #0362 | Địa chỉ PC: 0x070c1c | Địa chỉ FDE: 0x198c68 | Kích thước: 100 bytes
//   0x070c1c: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x070c20: 910003FD  mov      x29, sp
//   0x070c24: AA0003E8  mov      x8, x0
//   0x070c28: F9400000  ldr      x0, [x0]
static inline uint64_t fde_func_0362_0x070c1c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x070c1cULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x198c68ULL;
    acc ^= (acc >> 17) * 0x0064ULL;
    return acc;
}

// FDE #0363 | PC: 0x070c80 | FDE: 0x198ca8 | Size: 256 bytes
// Khung tháo gỡ #0363 | Địa chỉ PC: 0x070c80 | Địa chỉ FDE: 0x198ca8 | Kích thước: 256 bytes
//   0x070c80: F81C0FF7  str      x23, [sp, #-0x40]!
//   0x070c84: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x070c88: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x070c8c: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_0363_0x070c80(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x070c80ULL ^ (static_cast<uint64_t>(0xf81c0ff7ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x198ca8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0364 | PC: 0x070db0 | FDE: 0x198d08 | Size: 60 bytes
// Khung tháo gỡ #0364 | Địa chỉ PC: 0x070db0 | Địa chỉ FDE: 0x198d08 | Kích thước: 60 bytes
//   0x070db0: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x070db4: AA0003F3  mov      x19, x0
//   0x070db8: A9400008  ldp      x8, x0, [x0]
//   0x070dbc: D63F0100  blr      x8
static inline uint64_t fde_func_0364_0x070db0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x070db0ULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0xaa0003f3ULL) ^ 0x198d08ULL;
    acc ^= (acc >> 17) * 0x003cULL;
    return acc;
}

// FDE #0365 | PC: 0x070dec | FDE: 0x198d38 | Size: 20 bytes
// Khung tháo gỡ #0365 | Địa chỉ PC: 0x070dec | Địa chỉ FDE: 0x198d38 | Kích thước: 20 bytes
//   0x070dec: A9400001  ldp      x1, x0, [x0]
//   0x070df0: D61F0020  br       x1
//   0x070df4: AA0003E2  mov      x2, x0
//   0x070df8: AA0103E0  mov      x0, x1
static inline uint64_t fde_func_0365_0x070dec(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x070decULL ^ (static_cast<uint64_t>(0xa9400001ULL) << 13);
    acc = (acc + a1 + 0xd61f0020ULL) ^ 0x198d38ULL;
    acc ^= (acc >> 17) * 0x0014ULL;
    return acc;
}

// FDE #0366 | PC: 0x070e00 | FDE: 0x198d68 | Size: 32 bytes
// Khung tháo gỡ #0366 | Địa chỉ PC: 0x070e00 | Địa chỉ FDE: 0x198d68 | Kích thước: 32 bytes
//   0x070e00: A9402002  ldp      x2, x8, [x0]
//   0x070e04: F9400801  ldr      x1, [x0, #0x10]
//   0x070e08: AA0803E0  mov      x0, x8
//   0x070e0c: D61F0040  br       x2
static inline uint64_t fde_func_0366_0x070e00(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x070e00ULL ^ (static_cast<uint64_t>(0xa9402002ULL) << 13);
    acc = (acc + a1 + 0xf9400801ULL) ^ 0x198d68ULL;
    acc ^= (acc >> 17) * 0x0020ULL;
    return acc;
}

// FDE #0367 | PC: 0x070e20 | FDE: 0x198d98 | Size: 64 bytes
// Khung tháo gỡ #0367 | Địa chỉ PC: 0x070e20 | Địa chỉ FDE: 0x198d98 | Kích thước: 64 bytes
//   0x070e20: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x070e24: AA0003F3  mov      x19, x0
//   0x070e28: A9400008  ldp      x8, x0, [x0]
//   0x070e2c: D63F0100  blr      x8
static inline uint64_t fde_func_0367_0x070e20(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x070e20ULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0xaa0003f3ULL) ^ 0x198d98ULL;
    acc ^= (acc >> 17) * 0x0040ULL;
    return acc;
}

// FDE #0368 | PC: 0x070e60 | FDE: 0x198dc8 | Size: 36 bytes
// Khung tháo gỡ #0368 | Địa chỉ PC: 0x070e60 | Địa chỉ FDE: 0x198dc8 | Kích thước: 36 bytes
//   0x070e60: A9400001  ldp      x1, x0, [x0]
//   0x070e64: D61F0020  br       x1
//   0x070e68: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x070e6c: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_0368_0x070e60(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x070e60ULL ^ (static_cast<uint64_t>(0xa9400001ULL) << 13);
    acc = (acc + a1 + 0xd61f0020ULL) ^ 0x198dc8ULL;
    acc ^= (acc >> 17) * 0x0024ULL;
    return acc;
}

// FDE #0369 | PC: 0x070e84 | FDE: 0x198df8 | Size: 44 bytes
// Khung tháo gỡ #0369 | Địa chỉ PC: 0x070e84 | Địa chỉ FDE: 0x198df8 | Kích thước: 44 bytes
//   0x070e84: A9402002  ldp      x2, x8, [x0]
//   0x070e88: F9400801  ldr      x1, [x0, #0x10]
//   0x070e8c: AA0803E0  mov      x0, x8
//   0x070e90: D61F0040  br       x2
static inline uint64_t fde_func_0369_0x070e84(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x070e84ULL ^ (static_cast<uint64_t>(0xa9402002ULL) << 13);
    acc = (acc + a1 + 0xf9400801ULL) ^ 0x198df8ULL;
    acc ^= (acc >> 17) * 0x002cULL;
    return acc;
}

// FDE #0370 | PC: 0x070eb0 | FDE: 0x198e28 | Size: 60 bytes
// Khung tháo gỡ #0370 | Địa chỉ PC: 0x070eb0 | Địa chỉ FDE: 0x198e28 | Kích thước: 60 bytes
//   0x070eb0: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x070eb4: AA0003F3  mov      x19, x0
//   0x070eb8: A9400008  ldp      x8, x0, [x0]
//   0x070ebc: B9401261  ldr      w1, [x19, #0x10]
static inline uint64_t fde_func_0370_0x070eb0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x070eb0ULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0xaa0003f3ULL) ^ 0x198e28ULL;
    acc ^= (acc >> 17) * 0x003cULL;
    return acc;
}

// FDE #0371 | PC: 0x070eec | FDE: 0x198e58 | Size: 32 bytes
// Khung tháo gỡ #0371 | Địa chỉ PC: 0x070eec | Địa chỉ FDE: 0x198e58 | Kích thước: 32 bytes
//   0x070eec: A9402002  ldp      x2, x8, [x0]
//   0x070ef0: F9400801  ldr      x1, [x0, #0x10]
//   0x070ef4: AA0803E0  mov      x0, x8
//   0x070ef8: D61F0040  br       x2
static inline uint64_t fde_func_0371_0x070eec(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x070eecULL ^ (static_cast<uint64_t>(0xa9402002ULL) << 13);
    acc = (acc + a1 + 0xf9400801ULL) ^ 0x198e58ULL;
    acc ^= (acc >> 17) * 0x0020ULL;
    return acc;
}

// FDE #0372 | PC: 0x070f0c | FDE: 0x198e88 | Size: 64 bytes
// Khung tháo gỡ #0372 | Địa chỉ PC: 0x070f0c | Địa chỉ FDE: 0x198e88 | Kích thước: 64 bytes
//   0x070f0c: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x070f10: AA0003F3  mov      x19, x0
//   0x070f14: A9400008  ldp      x8, x0, [x0]
//   0x070f18: D63F0100  blr      x8
static inline uint64_t fde_func_0372_0x070f0c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x070f0cULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0xaa0003f3ULL) ^ 0x198e88ULL;
    acc ^= (acc >> 17) * 0x0040ULL;
    return acc;
}

// FDE #0373 | PC: 0x070f4c | FDE: 0x198eb8 | Size: 48 bytes
// Khung tháo gỡ #0373 | Địa chỉ PC: 0x070f4c | Địa chỉ FDE: 0x198eb8 | Kích thước: 48 bytes
//   0x070f4c: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x070f50: AA0003F3  mov      x19, x0
//   0x070f54: A9400008  ldp      x8, x0, [x0]
//   0x070f58: D63F0100  blr      x8
static inline uint64_t fde_func_0373_0x070f4c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x070f4cULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0xaa0003f3ULL) ^ 0x198eb8ULL;
    acc ^= (acc >> 17) * 0x0030ULL;
    return acc;
}

// FDE #0374 | PC: 0x070f7c | FDE: 0x198ee8 | Size: 60 bytes
// Khung tháo gỡ #0374 | Địa chỉ PC: 0x070f7c | Địa chỉ FDE: 0x198ee8 | Kích thước: 60 bytes
//   0x070f7c: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x070f80: AA0003F3  mov      x19, x0
//   0x070f84: A9400008  ldp      x8, x0, [x0]
//   0x070f88: A9410A61  ldp      x1, x2, [x19, #0x10]
static inline uint64_t fde_func_0374_0x070f7c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x070f7cULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0xaa0003f3ULL) ^ 0x198ee8ULL;
    acc ^= (acc >> 17) * 0x003cULL;
    return acc;
}

// FDE #0375 | PC: 0x070fb8 | FDE: 0x198f18 | Size: 44 bytes
// Khung tháo gỡ #0375 | Địa chỉ PC: 0x070fb8 | Địa chỉ FDE: 0x198f18 | Kích thước: 44 bytes
//   0x070fb8: A9402002  ldp      x2, x8, [x0]
//   0x070fbc: F9400801  ldr      x1, [x0, #0x10]
//   0x070fc0: AA0803E0  mov      x0, x8
//   0x070fc4: D61F0040  br       x2
static inline uint64_t fde_func_0375_0x070fb8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x070fb8ULL ^ (static_cast<uint64_t>(0xa9402002ULL) << 13);
    acc = (acc + a1 + 0xf9400801ULL) ^ 0x198f18ULL;
    acc ^= (acc >> 17) * 0x002cULL;
    return acc;
}

// FDE #0376 | PC: 0x070fe4 | FDE: 0x198f48 | Size: 44 bytes
// Khung tháo gỡ #0376 | Địa chỉ PC: 0x070fe4 | Địa chỉ FDE: 0x198f48 | Kích thước: 44 bytes
//   0x070fe4: A9402002  ldp      x2, x8, [x0]
//   0x070fe8: F9400801  ldr      x1, [x0, #0x10]
//   0x070fec: AA0803E0  mov      x0, x8
//   0x070ff0: D61F0040  br       x2
static inline uint64_t fde_func_0376_0x070fe4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x070fe4ULL ^ (static_cast<uint64_t>(0xa9402002ULL) << 13);
    acc = (acc + a1 + 0xf9400801ULL) ^ 0x198f48ULL;
    acc ^= (acc >> 17) * 0x002cULL;
    return acc;
}

// FDE #0377 | PC: 0x071010 | FDE: 0x198f78 | Size: 60 bytes
// Khung tháo gỡ #0377 | Địa chỉ PC: 0x071010 | Địa chỉ FDE: 0x198f78 | Kích thước: 60 bytes
//   0x071010: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x071014: AA0003F3  mov      x19, x0
//   0x071018: A9400008  ldp      x8, x0, [x0]
//   0x07101c: B9401261  ldr      w1, [x19, #0x10]
static inline uint64_t fde_func_0377_0x071010(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x071010ULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0xaa0003f3ULL) ^ 0x198f78ULL;
    acc ^= (acc >> 17) * 0x003cULL;
    return acc;
}

// FDE #0378 | PC: 0x07104c | FDE: 0x198fa8 | Size: 64 bytes
// Khung tháo gỡ #0378 | Địa chỉ PC: 0x07104c | Địa chỉ FDE: 0x198fa8 | Kích thước: 64 bytes
//   0x07104c: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x071050: AA0003F3  mov      x19, x0
//   0x071054: A9400008  ldp      x8, x0, [x0]
//   0x071058: F9400A61  ldr      x1, [x19, #0x10]
static inline uint64_t fde_func_0378_0x07104c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07104cULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0xaa0003f3ULL) ^ 0x198fa8ULL;
    acc ^= (acc >> 17) * 0x0040ULL;
    return acc;
}

// FDE #0379 | PC: 0x07108c | FDE: 0x198fd8 | Size: 56 bytes
// Khung tháo gỡ #0379 | Địa chỉ PC: 0x07108c | Địa chỉ FDE: 0x198fd8 | Kích thước: 56 bytes
//   0x07108c: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x071090: AA0003F3  mov      x19, x0
//   0x071094: A9400008  ldp      x8, x0, [x0]
//   0x071098: D63F0100  blr      x8
static inline uint64_t fde_func_0379_0x07108c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07108cULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0xaa0003f3ULL) ^ 0x198fd8ULL;
    acc ^= (acc >> 17) * 0x0038ULL;
    return acc;
}

// FDE #0380 | PC: 0x0710c4 | FDE: 0x199008 | Size: 24 bytes
// Khung tháo gỡ #0380 | Địa chỉ PC: 0x0710c4 | Địa chỉ FDE: 0x199008 | Kích thước: 24 bytes
//   0x0710c4: A9400001  ldp      x1, x0, [x0]
//   0x0710c8: D61F0020  br       x1
//   0x0710cc: A9402002  ldp      x2, x8, [x0]
//   0x0710d0: F9400801  ldr      x1, [x0, #0x10]
static inline uint64_t fde_func_0380_0x0710c4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0710c4ULL ^ (static_cast<uint64_t>(0xa9400001ULL) << 13);
    acc = (acc + a1 + 0xd61f0020ULL) ^ 0x199008ULL;
    acc ^= (acc >> 17) * 0x0018ULL;
    return acc;
}

// FDE #0381 | PC: 0x0710dc | FDE: 0x199038 | Size: 48 bytes
// Khung tháo gỡ #0381 | Địa chỉ PC: 0x0710dc | Địa chỉ FDE: 0x199038 | Kích thước: 48 bytes
//   0x0710dc: A9402003  ldp      x3, x8, [x0]
//   0x0710e0: A9410801  ldp      x1, x2, [x0, #0x10]
//   0x0710e4: AA0803E0  mov      x0, x8
//   0x0710e8: D61F0060  br       x3
static inline uint64_t fde_func_0381_0x0710dc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0710dcULL ^ (static_cast<uint64_t>(0xa9402003ULL) << 13);
    acc = (acc + a1 + 0xa9410801ULL) ^ 0x199038ULL;
    acc ^= (acc >> 17) * 0x0030ULL;
    return acc;
}

// FDE #0382 | PC: 0x07110c | FDE: 0x199068 | Size: 64 bytes
// Khung tháo gỡ #0382 | Địa chỉ PC: 0x07110c | Địa chỉ FDE: 0x199068 | Kích thước: 64 bytes
//   0x07110c: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x071110: AA0003F3  mov      x19, x0
//   0x071114: A9400008  ldp      x8, x0, [x0]
//   0x071118: F9400A61  ldr      x1, [x19, #0x10]
static inline uint64_t fde_func_0382_0x07110c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07110cULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0xaa0003f3ULL) ^ 0x199068ULL;
    acc ^= (acc >> 17) * 0x0040ULL;
    return acc;
}

// FDE #0383 | PC: 0x07114c | FDE: 0x199098 | Size: 16 bytes
// Khung tháo gỡ #0383 | Địa chỉ PC: 0x07114c | Địa chỉ FDE: 0x199098 | Kích thước: 16 bytes
//   0x07114c: A9400001  ldp      x1, x0, [x0]
//   0x071150: D61F0020  br       x1
//   0x071154: A9400001  ldp      x1, x0, [x0]
//   0x071158: D61F0020  br       x1
static inline uint64_t fde_func_0383_0x07114c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07114cULL ^ (static_cast<uint64_t>(0xa9400001ULL) << 13);
    acc = (acc + a1 + 0xd61f0020ULL) ^ 0x199098ULL;
    acc ^= (acc >> 17) * 0x0010ULL;
    return acc;
}

// FDE #0384 | PC: 0x07115c | FDE: 0x1990c8 | Size: 256 bytes
// Khung tháo gỡ #0384 | Địa chỉ PC: 0x07115c | Địa chỉ FDE: 0x1990c8 | Kích thước: 256 bytes
//   0x07115c: A9400001  ldp      x1, x0, [x0]
//   0x071160: D61F0020  br       x1
//   0x071164: A9BA6FFC  stp      x28, x27, [sp, #-0x60]!
//   0x071168: A90167FA  stp      x26, x25, [sp, #0x10]
static inline uint64_t fde_func_0384_0x07115c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07115cULL ^ (static_cast<uint64_t>(0xa9400001ULL) << 13);
    acc = (acc + a1 + 0xd61f0020ULL) ^ 0x1990c8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0385 | PC: 0x071934 | FDE: 0x199168 | Size: 256 bytes
// Khung tháo gỡ #0385 | Địa chỉ PC: 0x071934 | Địa chỉ FDE: 0x199168 | Kích thước: 256 bytes
//   0x071934: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x071938: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x07193c: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x071940: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0385_0x071934(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x071934ULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x199168ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0386 | PC: 0x071b60 | FDE: 0x1991b0 | Size: 44 bytes
// Khung tháo gỡ #0386 | Địa chỉ PC: 0x071b60 | Địa chỉ FDE: 0x1991b0 | Kích thước: 44 bytes
//   0x071b60: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x071b64: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x071b68: 910043FD  add      x29, sp, #0x10
//   0x071b6c: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_0386_0x071b60(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x071b60ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1991b0ULL;
    acc ^= (acc >> 17) * 0x002cULL;
    return acc;
}

// FDE #0387 | PC: 0x071b8c | FDE: 0x1991e8 | Size: 184 bytes
// Khung tháo gỡ #0387 | Địa chỉ PC: 0x071b8c | Địa chỉ FDE: 0x1991e8 | Kích thước: 184 bytes
//   0x071b8c: D10443FF  sub      sp, sp, #0x110
//   0x071b90: A90F4FFC  stp      x28, x19, [sp, #0xf0]
//   0x071b94: A9107BFD  stp      x29, x30, [sp, #0x100]
//   0x071b98: 910403FD  add      x29, sp, #0x100
static inline uint64_t fde_func_0387_0x071b8c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x071b8cULL ^ (static_cast<uint64_t>(0xd10443ffULL) << 13);
    acc = (acc + a1 + 0xa90f4ffcULL) ^ 0x1991e8ULL;
    acc ^= (acc >> 17) * 0x00b8ULL;
    return acc;
}

// FDE #0388 | PC: 0x071c44 | FDE: 0x199298 | Size: 256 bytes
// Khung tháo gỡ #0388 | Địa chỉ PC: 0x071c44 | Địa chỉ FDE: 0x199298 | Kích thước: 256 bytes
//   0x071c44: D10103FF  sub      sp, sp, #0x40
//   0x071c48: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x071c4c: A9037BFD  stp      x29, x30, [sp, #0x30]
//   0x071c50: 9100C3FD  add      x29, sp, #0x30
static inline uint64_t fde_func_0388_0x071c44(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x071c44ULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xa9024ff4ULL) ^ 0x199298ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0389 | PC: 0x071db4 | FDE: 0x1992e0 | Size: 256 bytes
// Khung tháo gỡ #0389 | Địa chỉ PC: 0x071db4 | Địa chỉ FDE: 0x1992e0 | Kích thước: 256 bytes
//   0x071db4: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x071db8: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x071dbc: 910043FD  add      x29, sp, #0x10
//   0x071dc0: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_0389_0x071db4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x071db4ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1992e0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0390 | PC: 0x07202c | FDE: 0x199398 | Size: 80 bytes
// Khung tháo gỡ #0390 | Địa chỉ PC: 0x07202c | Địa chỉ FDE: 0x199398 | Kích thước: 80 bytes
//   0x07202c: 91010000  add      x0, x0, #0x40
//   0x072030: EB01001F  cmp      x0, x1
//   0x072034: 540000E0  b.eq     #0x72050
//   0x072038: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
static inline uint64_t fde_func_0390_0x07202c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07202cULL ^ (static_cast<uint64_t>(0x91010000ULL) << 13);
    acc = (acc + a1 + 0xeb01001fULL) ^ 0x199398ULL;
    acc ^= (acc >> 17) * 0x0050ULL;
    return acc;
}

// FDE #0391 | PC: 0x07207c | FDE: 0x1993d8 | Size: 56 bytes
// Khung tháo gỡ #0391 | Địa chỉ PC: 0x07207c | Địa chỉ FDE: 0x1993d8 | Kích thước: 56 bytes
//   0x07207c: A9442408  ldp      x8, x9, [x0, #0x40]
//   0x072080: EB09011F  cmp      x8, x9
//   0x072084: 540000C0  b.eq     #0x7209c
//   0x072088: B840450A  ldr      w10, [x8], #4
static inline uint64_t fde_func_0391_0x07207c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07207cULL ^ (static_cast<uint64_t>(0xa9442408ULL) << 13);
    acc = (acc + a1 + 0xeb09011fULL) ^ 0x1993d8ULL;
    acc ^= (acc >> 17) * 0x0038ULL;
    return acc;
}

// FDE #0392 | PC: 0x0720b4 | FDE: 0x199408 | Size: 256 bytes
// Khung tháo gỡ #0392 | Địa chỉ PC: 0x0720b4 | Địa chỉ FDE: 0x199408 | Kích thước: 256 bytes
//   0x0720b4: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x0720b8: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0720bc: 910043FD  add      x29, sp, #0x10
//   0x0720c0: F9400C08  ldr      x8, [x0, #0x18]
static inline uint64_t fde_func_0392_0x0720b4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0720b4ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x199408ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0393 | PC: 0x0721d4 | FDE: 0x199448 | Size: 256 bytes
// Khung tháo gỡ #0393 | Địa chỉ PC: 0x0721d4 | Địa chỉ FDE: 0x199448 | Kích thước: 256 bytes
//   0x0721d4: D10143FF  sub      sp, sp, #0x50
//   0x0721d8: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x0721dc: A9047BFD  stp      x29, x30, [sp, #0x40]
//   0x0721e0: 910103FD  add      x29, sp, #0x40
static inline uint64_t fde_func_0393_0x0721d4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0721d4ULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xa9034ff4ULL) ^ 0x199448ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0394 | PC: 0x072594 | FDE: 0x199498 | Size: 8 bytes
// Khung tháo gỡ #0394 | Địa chỉ PC: 0x072594 | Địa chỉ FDE: 0x199498 | Kích thước: 8 bytes
//   0x072594: D65F03C0  ret      
//   0x072598: D65F03C0  ret      
static inline uint64_t fde_func_0394_0x072594(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x072594ULL ^ (static_cast<uint64_t>(0xd65f03c0ULL) << 13);
    acc = (acc + a1 + 0xd65f03c0ULL) ^ 0x199498ULL;
    acc ^= (acc >> 17) * 0x0008ULL;
    return acc;
}

// FDE #0395 | PC: 0x07259c | FDE: 0x1994c8 | Size: 16 bytes
// Khung tháo gỡ #0395 | Địa chỉ PC: 0x07259c | Địa chỉ FDE: 0x1994c8 | Kích thước: 16 bytes
//   0x07259c: 2A1F03E0  mov      w0, wzr
//   0x0725a0: D65F03C0  ret      
//   0x0725a4: B9003801  str      w1, [x0, #0x38]
//   0x0725a8: D65F03C0  ret      
static inline uint64_t fde_func_0395_0x07259c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07259cULL ^ (static_cast<uint64_t>(0x2a1f03e0ULL) << 13);
    acc = (acc + a1 + 0xd65f03c0ULL) ^ 0x1994c8ULL;
    acc ^= (acc >> 17) * 0x0010ULL;
    return acc;
}

// FDE #0396 | PC: 0x0725ac | FDE: 0x1994f8 | Size: 136 bytes
// Khung tháo gỡ #0396 | Địa chỉ PC: 0x0725ac | Địa chỉ FDE: 0x1994f8 | Kích thước: 136 bytes
//   0x0725ac: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x0725b0: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0725b4: 910043FD  add      x29, sp, #0x10
//   0x0725b8: F9403001  ldr      x1, [x0, #0x60]
static inline uint64_t fde_func_0396_0x0725ac(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0725acULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1994f8ULL;
    acc ^= (acc >> 17) * 0x0088ULL;
    return acc;
}

// FDE #0397 | PC: 0x072634 | FDE: 0x199538 | Size: 76 bytes
// Khung tháo gỡ #0397 | Địa chỉ PC: 0x072634 | Địa chỉ FDE: 0x199538 | Kích thước: 76 bytes
//   0x072634: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x072638: 910003FD  mov      x29, sp
//   0x07263c: 97FEEE95  bl       #0x2e090
//   0x072640: A8C17BFD  ldp      x29, x30, [sp], #0x10
static inline uint64_t fde_func_0397_0x072634(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x072634ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x199538ULL;
    acc ^= (acc >> 17) * 0x004cULL;
    return acc;
}

// FDE #0398 | PC: 0x072680 | FDE: 0x199578 | Size: 28 bytes
// Khung tháo gỡ #0398 | Địa chỉ PC: 0x072680 | Địa chỉ FDE: 0x199578 | Kích thước: 28 bytes
//   0x072680: B0000A88  adrp     x8, #0x1c3000
//   0x072684: 91138108  add      x8, x8, #0x4e0
//   0x072688: F9000028  str      x8, [x1]
//   0x07268c: 3CC08000  ldur     q0, [x0, #8]
static inline uint64_t fde_func_0398_0x072680(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x072680ULL ^ (static_cast<uint64_t>(0xb0000a88ULL) << 13);
    acc = (acc + a1 + 0x91138108ULL) ^ 0x199578ULL;
    acc ^= (acc >> 17) * 0x001cULL;
    return acc;
}

// FDE #0399 | PC: 0x07269c | FDE: 0x1995a8 | Size: 256 bytes
// Khung tháo gỡ #0399 | Địa chỉ PC: 0x07269c | Địa chỉ FDE: 0x1995a8 | Kích thước: 256 bytes
//   0x07269c: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x0726a0: 910003FD  mov      x29, sp
//   0x0726a4: 97FEEE7B  bl       #0x2e090
//   0x0726a8: A8C17BFD  ldp      x29, x30, [sp], #0x10
static inline uint64_t fde_func_0399_0x07269c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07269cULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1995a8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Shard 1 Dispatcher / Bộ điều phối phân mảnh 1
uint64_t execute_fde_shard_1(uint32_t fde_idx, uint64_t a0, uint64_t a1) {
    switch (fde_idx) {
        case 0: return fde_func_0000_0x02ea00(a0, a1);
        case 1: return fde_func_0001_0x02ed30(a0, a1);
        case 2: return fde_func_0002_0x02ef6c(a0, a1);
        case 3: return fde_func_0003_0x02f0f0(a0, a1);
        case 4: return fde_func_0004_0x02f420(a0, a1);
        case 5: return fde_func_0005_0x02f65c(a0, a1);
        case 6: return fde_func_0006_0x02f7e0(a0, a1);
        case 7: return fde_func_0007_0x02fb10(a0, a1);
        case 8: return fde_func_0008_0x02fd4c(a0, a1);
        case 9: return fde_func_0009_0x02fed0(a0, a1);
        case 10: return fde_func_0010_0x030200(a0, a1);
        case 11: return fde_func_0011_0x03043c(a0, a1);
        case 12: return fde_func_0012_0x0305c0(a0, a1);
        case 13: return fde_func_0013_0x0308f0(a0, a1);
        case 14: return fde_func_0014_0x030980(a0, a1);
        case 15: return fde_func_0015_0x030cb0(a0, a1);
        case 16: return fde_func_0016_0x030d40(a0, a1);
        case 17: return fde_func_0017_0x031070(a0, a1);
        case 18: return fde_func_0018_0x0312ac(a0, a1);
        case 19: return fde_func_0019_0x031430(a0, a1);
        case 20: return fde_func_0020_0x031760(a0, a1);
        case 21: return fde_func_0021_0x03199c(a0, a1);
        case 22: return fde_func_0022_0x031b50(a0, a1);
        case 23: return fde_func_0023_0x031e80(a0, a1);
        case 24: return fde_func_0024_0x0320bc(a0, a1);
        case 25: return fde_func_0025_0x032240(a0, a1);
        case 26: return fde_func_0026_0x032570(a0, a1);
        case 27: return fde_func_0027_0x0327ac(a0, a1);
        case 28: return fde_func_0028_0x032930(a0, a1);
        case 29: return fde_func_0029_0x032c60(a0, a1);
        case 30: return fde_func_0030_0x032e9c(a0, a1);
        case 31: return fde_func_0031_0x033088(a0, a1);
        case 32: return fde_func_0032_0x0333b8(a0, a1);
        case 33: return fde_func_0033_0x0335f4(a0, a1);
        case 34: return fde_func_0034_0x033778(a0, a1);
        case 35: return fde_func_0035_0x033aa8(a0, a1);
        case 36: return fde_func_0036_0x033ce4(a0, a1);
        case 37: return fde_func_0037_0x033f28(a0, a1);
        case 38: return fde_func_0038_0x034258(a0, a1);
        case 39: return fde_func_0039_0x034494(a0, a1);
        case 40: return fde_func_0040_0x034618(a0, a1);
        case 41: return fde_func_0041_0x034948(a0, a1);
        case 42: return fde_func_0042_0x034b84(a0, a1);
        case 43: return fde_func_0043_0x034d08(a0, a1);
        case 44: return fde_func_0044_0x035038(a0, a1);
        case 45: return fde_func_0045_0x035274(a0, a1);
        case 46: return fde_func_0046_0x0353f8(a0, a1);
        case 47: return fde_func_0047_0x035728(a0, a1);
        case 48: return fde_func_0048_0x035964(a0, a1);
        case 49: return fde_func_0049_0x035ae8(a0, a1);
        case 50: return fde_func_0050_0x035e18(a0, a1);
        case 51: return fde_func_0051_0x036054(a0, a1);
        case 52: return fde_func_0052_0x0361d8(a0, a1);
        case 53: return fde_func_0053_0x036508(a0, a1);
        case 54: return fde_func_0054_0x03657c(a0, a1);
        case 55: return fde_func_0055_0x0368ac(a0, a1);
        case 56: return fde_func_0056_0x03693c(a0, a1);
        case 57: return fde_func_0057_0x036c6c(a0, a1);
        case 58: return fde_func_0058_0x036ea8(a0, a1);
        case 59: return fde_func_0059_0x03702c(a0, a1);
        case 60: return fde_func_0060_0x03735c(a0, a1);
        case 61: return fde_func_0061_0x037598(a0, a1);
        case 62: return fde_func_0062_0x03771c(a0, a1);
        case 63: return fde_func_0063_0x037a4c(a0, a1);
        case 64: return fde_func_0064_0x037c88(a0, a1);
        case 65: return fde_func_0065_0x037e0c(a0, a1);
        case 66: return fde_func_0066_0x03813c(a0, a1);
        case 67: return fde_func_0067_0x038378(a0, a1);
        case 68: return fde_func_0068_0x0384fc(a0, a1);
        case 69: return fde_func_0069_0x03882c(a0, a1);
        case 70: return fde_func_0070_0x038a68(a0, a1);
        case 71: return fde_func_0071_0x038bec(a0, a1);
        case 72: return fde_func_0072_0x038f1c(a0, a1);
        case 73: return fde_func_0073_0x039158(a0, a1);
        case 74: return fde_func_0074_0x0392dc(a0, a1);
        case 75: return fde_func_0075_0x03960c(a0, a1);
        case 76: return fde_func_0076_0x039848(a0, a1);
        case 77: return fde_func_0077_0x0399cc(a0, a1);
        case 78: return fde_func_0078_0x039cfc(a0, a1);
        case 79: return fde_func_0079_0x039f38(a0, a1);
        case 80: return fde_func_0080_0x03a0bc(a0, a1);
        case 81: return fde_func_0081_0x03a3ec(a0, a1);
        case 82: return fde_func_0082_0x03a628(a0, a1);
        case 83: return fde_func_0083_0x03a7ac(a0, a1);
        case 84: return fde_func_0084_0x03aadc(a0, a1);
        case 85: return fde_func_0085_0x03ad18(a0, a1);
        case 86: return fde_func_0086_0x03ae9c(a0, a1);
        case 87: return fde_func_0087_0x03b1cc(a0, a1);
        case 88: return fde_func_0088_0x03b408(a0, a1);
        case 89: return fde_func_0089_0x03b58c(a0, a1);
        case 90: return fde_func_0090_0x03b8bc(a0, a1);
        case 91: return fde_func_0091_0x03baf8(a0, a1);
        case 92: return fde_func_0092_0x03bc7c(a0, a1);
        case 93: return fde_func_0093_0x03cab4(a0, a1);
        case 94: return fde_func_0094_0x03ccf0(a0, a1);
        case 95: return fde_func_0095_0x03ce74(a0, a1);
        case 96: return fde_func_0096_0x03d3b0(a0, a1);
        case 97: return fde_func_0097_0x03d6e0(a0, a1);
        case 98: return fde_func_0098_0x03d91c(a0, a1);
        case 99: return fde_func_0099_0x03daa0(a0, a1);
        case 100: return fde_func_0100_0x03ddd0(a0, a1);
        case 101: return fde_func_0101_0x03e00c(a0, a1);
        case 102: return fde_func_0102_0x03e190(a0, a1);
        case 103: return fde_func_0103_0x03e4c0(a0, a1);
        case 104: return fde_func_0104_0x03e6fc(a0, a1);
        case 105: return fde_func_0105_0x03e880(a0, a1);
        case 106: return fde_func_0106_0x03ebb0(a0, a1);
        case 107: return fde_func_0107_0x03edec(a0, a1);
        case 108: return fde_func_0108_0x03ef70(a0, a1);
        case 109: return fde_func_0109_0x03f2a0(a0, a1);
        case 110: return fde_func_0110_0x03f4dc(a0, a1);
        case 111: return fde_func_0111_0x03f660(a0, a1);
        case 112: return fde_func_0112_0x03f990(a0, a1);
        case 113: return fde_func_0113_0x03fbcc(a0, a1);
        case 114: return fde_func_0114_0x03fd50(a0, a1);
        case 115: return fde_func_0115_0x03ff8c(a0, a1);
        case 116: return fde_func_0116_0x040110(a0, a1);
        case 117: return fde_func_0117_0x040440(a0, a1);
        case 118: return fde_func_0118_0x04067c(a0, a1);
        case 119: return fde_func_0119_0x040800(a0, a1);
        case 120: return fde_func_0120_0x040b30(a0, a1);
        case 121: return fde_func_0121_0x040d6c(a0, a1);
        case 122: return fde_func_0122_0x040ef0(a0, a1);
        case 123: return fde_func_0123_0x041220(a0, a1);
        case 124: return fde_func_0124_0x0415c0(a0, a1);
        case 125: return fde_func_0125_0x041744(a0, a1);
        case 126: return fde_func_0126_0x041a74(a0, a1);
        case 127: return fde_func_0127_0x041cb0(a0, a1);
        case 128: return fde_func_0128_0x041e34(a0, a1);
        case 129: return fde_func_0129_0x042164(a0, a1);
        case 130: return fde_func_0130_0x0423a0(a0, a1);
        case 131: return fde_func_0131_0x042524(a0, a1);
        case 132: return fde_func_0132_0x042854(a0, a1);
        case 133: return fde_func_0133_0x0428e4(a0, a1);
        case 134: return fde_func_0134_0x045b74(a0, a1);
        case 135: return fde_func_0135_0x045ea4(a0, a1);
        case 136: return fde_func_0136_0x0460e0(a0, a1);
        case 137: return fde_func_0137_0x046344(a0, a1);
        case 138: return fde_func_0138_0x046674(a0, a1);
        case 139: return fde_func_0139_0x0468b0(a0, a1);
        case 140: return fde_func_0140_0x046a34(a0, a1);
        case 141: return fde_func_0141_0x046c70(a0, a1);
        case 142: return fde_func_0142_0x046df4(a0, a1);
        case 143: return fde_func_0143_0x047124(a0, a1);
        case 144: return fde_func_0144_0x047360(a0, a1);
        case 145: return fde_func_0145_0x0474e4(a0, a1);
        case 146: return fde_func_0146_0x047814(a0, a1);
        case 147: return fde_func_0147_0x047a50(a0, a1);
        case 148: return fde_func_0148_0x047ddc(a0, a1);
        case 149: return fde_func_0149_0x047ea4(a0, a1);
        case 150: return fde_func_0150_0x047f34(a0, a1);
        case 151: return fde_func_0151_0x048264(a0, a1);
        case 152: return fde_func_0152_0x048370(a0, a1);
        case 153: return fde_func_0153_0x048400(a0, a1);
        case 154: return fde_func_0154_0x048490(a0, a1);
        case 155: return fde_func_0155_0x048520(a0, a1);
        case 156: return fde_func_0156_0x0485b0(a0, a1);
        case 157: return fde_func_0157_0x048640(a0, a1);
        case 158: return fde_func_0158_0x04887c(a0, a1);
        case 159: return fde_func_0159_0x048a00(a0, a1);
        case 160: return fde_func_0160_0x048d30(a0, a1);
        case 161: return fde_func_0161_0x048f6c(a0, a1);
        case 162: return fde_func_0162_0x0490f0(a0, a1);
        case 163: return fde_func_0163_0x049420(a0, a1);
        case 164: return fde_func_0164_0x04965c(a0, a1);
        case 165: return fde_func_0165_0x0497e0(a0, a1);
        case 166: return fde_func_0166_0x049b10(a0, a1);
        case 167: return fde_func_0167_0x049d4c(a0, a1);
        case 168: return fde_func_0168_0x049ed0(a0, a1);
        case 169: return fde_func_0169_0x04a10c(a0, a1);
        case 170: return fde_func_0170_0x04a290(a0, a1);
        case 171: return fde_func_0171_0x04a320(a0, a1);
        case 172: return fde_func_0172_0x04a578(a0, a1);
        case 173: return fde_func_0173_0x04a86c(a0, a1);
        case 174: return fde_func_0174_0x04aabc(a0, a1);
        case 175: return fde_func_0175_0x04aae0(a0, a1);
        case 176: return fde_func_0176_0x04bd90(a0, a1);
        case 177: return fde_func_0177_0x04c45c(a0, a1);
        case 178: return fde_func_0178_0x04c564(a0, a1);
        case 179: return fde_func_0179_0x04c930(a0, a1);
        case 180: return fde_func_0180_0x04c98c(a0, a1);
        case 181: return fde_func_0181_0x04ca54(a0, a1);
        case 182: return fde_func_0182_0x04d214(a0, a1);
        case 183: return fde_func_0183_0x04d308(a0, a1);
        case 184: return fde_func_0184_0x04d320(a0, a1);
        case 185: return fde_func_0185_0x04dad4(a0, a1);
        case 186: return fde_func_0186_0x04dc78(a0, a1);
        case 187: return fde_func_0187_0x04decc(a0, a1);
        case 188: return fde_func_0188_0x04e05c(a0, a1);
        case 189: return fde_func_0189_0x04e1d0(a0, a1);
        case 190: return fde_func_0190_0x04e3f4(a0, a1);
        case 191: return fde_func_0191_0x04ebb0(a0, a1);
        case 192: return fde_func_0192_0x04ecc8(a0, a1);
        case 193: return fde_func_0193_0x04ef18(a0, a1);
        case 194: return fde_func_0194_0x04f000(a0, a1);
        case 195: return fde_func_0195_0x04f14c(a0, a1);
        case 196: return fde_func_0196_0x04f164(a0, a1);
        case 197: return fde_func_0197_0x04f17c(a0, a1);
        case 198: return fde_func_0198_0x04f194(a0, a1);
        case 199: return fde_func_0199_0x04f1ac(a0, a1);
        case 200: return fde_func_0200_0x04f354(a0, a1);
        case 201: return fde_func_0201_0x04f4ac(a0, a1);
        case 202: return fde_func_0202_0x04f644(a0, a1);
        case 203: return fde_func_0203_0x04f82c(a0, a1);
        case 204: return fde_func_0204_0x04f86c(a0, a1);
        case 205: return fde_func_0205_0x04f89c(a0, a1);
        case 206: return fde_func_0206_0x04f8d4(a0, a1);
        case 207: return fde_func_0207_0x057f84(a0, a1);
        case 208: return fde_func_0208_0x05824c(a0, a1);
        case 209: return fde_func_0209_0x058438(a0, a1);
        case 210: return fde_func_0210_0x058518(a0, a1);
        case 211: return fde_func_0211_0x058650(a0, a1);
        case 212: return fde_func_0212_0x058708(a0, a1);
        case 213: return fde_func_0213_0x0587c0(a0, a1);
        case 214: return fde_func_0214_0x058e70(a0, a1);
        case 215: return fde_func_0215_0x058fa8(a0, a1);
        case 216: return fde_func_0216_0x058fcc(a0, a1);
        case 217: return fde_func_0217_0x059764(a0, a1);
        case 218: return fde_func_0218_0x059774(a0, a1);
        case 219: return fde_func_0219_0x0599a8(a0, a1);
        case 220: return fde_func_0220_0x0599d0(a0, a1);
        case 221: return fde_func_0221_0x059b6c(a0, a1);
        case 222: return fde_func_0222_0x059bf8(a0, a1);
        case 223: return fde_func_0223_0x059d14(a0, a1);
        case 224: return fde_func_0224_0x059d9c(a0, a1);
        case 225: return fde_func_0225_0x059f20(a0, a1);
        case 226: return fde_func_0226_0x059fb0(a0, a1);
        case 227: return fde_func_0227_0x05a0c0(a0, a1);
        case 228: return fde_func_0228_0x05a1a4(a0, a1);
        case 229: return fde_func_0229_0x05a20c(a0, a1);
        case 230: return fde_func_0230_0x05aa8c(a0, a1);
        case 231: return fde_func_0231_0x05ab78(a0, a1);
        case 232: return fde_func_0232_0x05ac08(a0, a1);
        case 233: return fde_func_0233_0x05aca4(a0, a1);
        case 234: return fde_func_0234_0x05acfc(a0, a1);
        case 235: return fde_func_0235_0x05b388(a0, a1);
        case 236: return fde_func_0236_0x05b654(a0, a1);
        case 237: return fde_func_0237_0x05b6e4(a0, a1);
        case 238: return fde_func_0238_0x05b774(a0, a1);
        case 239: return fde_func_0239_0x05b804(a0, a1);
        case 240: return fde_func_0240_0x05b8e8(a0, a1);
        case 241: return fde_func_0241_0x05b938(a0, a1);
        case 242: return fde_func_0242_0x05b978(a0, a1);
        case 243: return fde_func_0243_0x05bbc8(a0, a1);
        case 244: return fde_func_0244_0x05c804(a0, a1);
        case 245: return fde_func_0245_0x05ca00(a0, a1);
        case 246: return fde_func_0246_0x05d574(a0, a1);
        case 247: return fde_func_0247_0x05dce0(a0, a1);
        case 248: return fde_func_0248_0x05e170(a0, a1);
        case 249: return fde_func_0249_0x05f188(a0, a1);
        case 250: return fde_func_0250_0x05fb30(a0, a1);
        case 251: return fde_func_0251_0x060388(a0, a1);
        case 252: return fde_func_0252_0x0605e8(a0, a1);
        case 253: return fde_func_0253_0x060664(a0, a1);
        case 254: return fde_func_0254_0x060ffc(a0, a1);
        case 255: return fde_func_0255_0x0622d8(a0, a1);
        case 256: return fde_func_0256_0x062360(a0, a1);
        case 257: return fde_func_0257_0x062728(a0, a1);
        case 258: return fde_func_0258_0x062740(a0, a1);
        case 259: return fde_func_0259_0x062790(a0, a1);
        case 260: return fde_func_0260_0x0627a8(a0, a1);
        case 261: return fde_func_0261_0x0628c8(a0, a1);
        case 262: return fde_func_0262_0x0629e4(a0, a1);
        case 263: return fde_func_0263_0x062a30(a0, a1);
        case 264: return fde_func_0264_0x062a4c(a0, a1);
        case 265: return fde_func_0265_0x062aa4(a0, a1);
        case 266: return fde_func_0266_0x062acc(a0, a1);
        case 267: return fde_func_0267_0x062b14(a0, a1);
        case 268: return fde_func_0268_0x062b54(a0, a1);
        case 269: return fde_func_0269_0x062b9c(a0, a1);
        case 270: return fde_func_0270_0x062bbc(a0, a1);
        case 271: return fde_func_0271_0x062bd4(a0, a1);
        case 272: return fde_func_0272_0x062cf0(a0, a1);
        case 273: return fde_func_0273_0x062e88(a0, a1);
        case 274: return fde_func_0274_0x063098(a0, a1);
        case 275: return fde_func_0275_0x0632a8(a0, a1);
        case 276: return fde_func_0276_0x0634b4(a0, a1);
        case 277: return fde_func_0277_0x0638d0(a0, a1);
        case 278: return fde_func_0278_0x063eb8(a0, a1);
        case 279: return fde_func_0279_0x063f3c(a0, a1);
        case 280: return fde_func_0280_0x064090(a0, a1);
        case 281: return fde_func_0281_0x064280(a0, a1);
        case 282: return fde_func_0282_0x0645cc(a0, a1);
        case 283: return fde_func_0283_0x064604(a0, a1);
        case 284: return fde_func_0284_0x064630(a0, a1);
        case 285: return fde_func_0285_0x06465c(a0, a1);
        case 286: return fde_func_0286_0x064684(a0, a1);
        case 287: return fde_func_0287_0x0646b8(a0, a1);
        case 288: return fde_func_0288_0x0646e8(a0, a1);
        case 289: return fde_func_0289_0x064720(a0, a1);
        case 290: return fde_func_0290_0x0661b0(a0, a1);
        case 291: return fde_func_0291_0x0662e4(a0, a1);
        case 292: return fde_func_0292_0x06674c(a0, a1);
        case 293: return fde_func_0293_0x0667ac(a0, a1);
        case 294: return fde_func_0294_0x0667c4(a0, a1);
        case 295: return fde_func_0295_0x066910(a0, a1);
        case 296: return fde_func_0296_0x066a18(a0, a1);
        case 297: return fde_func_0297_0x066a8c(a0, a1);
        case 298: return fde_func_0298_0x066cfc(a0, a1);
        case 299: return fde_func_0299_0x066e08(a0, a1);
        case 300: return fde_func_0300_0x0677ac(a0, a1);
        case 301: return fde_func_0301_0x067a48(a0, a1);
        case 302: return fde_func_0302_0x067da0(a0, a1);
        case 303: return fde_func_0303_0x068074(a0, a1);
        case 304: return fde_func_0304_0x068950(a0, a1);
        case 305: return fde_func_0305_0x068c08(a0, a1);
        case 306: return fde_func_0306_0x068c20(a0, a1);
        case 307: return fde_func_0307_0x068c34(a0, a1);
        case 308: return fde_func_0308_0x068c48(a0, a1);
        case 309: return fde_func_0309_0x068c5c(a0, a1);
        case 310: return fde_func_0310_0x068c6c(a0, a1);
        case 311: return fde_func_0311_0x068c80(a0, a1);
        case 312: return fde_func_0312_0x068d10(a0, a1);
        case 313: return fde_func_0313_0x068d64(a0, a1);
        case 314: return fde_func_0314_0x068de0(a0, a1);
        case 315: return fde_func_0315_0x068e24(a0, a1);
        case 316: return fde_func_0316_0x0691d0(a0, a1);
        case 317: return fde_func_0317_0x069220(a0, a1);
        case 318: return fde_func_0318_0x069238(a0, a1);
        case 319: return fde_func_0319_0x06927c(a0, a1);
        case 320: return fde_func_0320_0x0692cc(a0, a1);
        case 321: return fde_func_0321_0x0692e4(a0, a1);
        case 322: return fde_func_0322_0x069338(a0, a1);
        case 323: return fde_func_0323_0x069388(a0, a1);
        case 324: return fde_func_0324_0x0693a0(a0, a1);
        case 325: return fde_func_0325_0x069400(a0, a1);
        case 326: return fde_func_0326_0x069418(a0, a1);
        case 327: return fde_func_0327_0x069788(a0, a1);
        case 328: return fde_func_0328_0x069908(a0, a1);
        case 329: return fde_func_0329_0x069950(a0, a1);
        case 330: return fde_func_0330_0x069bd0(a0, a1);
        case 331: return fde_func_0331_0x069f2c(a0, a1);
        case 332: return fde_func_0332_0x06e2a8(a0, a1);
        case 333: return fde_func_0333_0x06e3ac(a0, a1);
        case 334: return fde_func_0334_0x06e4ac(a0, a1);
        case 335: return fde_func_0335_0x06e638(a0, a1);
        case 336: return fde_func_0336_0x06e75c(a0, a1);
        case 337: return fde_func_0337_0x06eef0(a0, a1);
        case 338: return fde_func_0338_0x06f410(a0, a1);
        case 339: return fde_func_0339_0x06f494(a0, a1);
        case 340: return fde_func_0340_0x06f654(a0, a1);
        case 341: return fde_func_0341_0x06f7dc(a0, a1);
        case 342: return fde_func_0342_0x06f9ac(a0, a1);
        case 343: return fde_func_0343_0x06fbe0(a0, a1);
        case 344: return fde_func_0344_0x06fd88(a0, a1);
        case 345: return fde_func_0345_0x06ff88(a0, a1);
        case 346: return fde_func_0346_0x070410(a0, a1);
        case 347: return fde_func_0347_0x0704d8(a0, a1);
        case 348: return fde_func_0348_0x070510(a0, a1);
        case 349: return fde_func_0349_0x0705c0(a0, a1);
        case 350: return fde_func_0350_0x0705ec(a0, a1);
        case 351: return fde_func_0351_0x070620(a0, a1);
        case 352: return fde_func_0352_0x0706ec(a0, a1);
        case 353: return fde_func_0353_0x0706fc(a0, a1);
        case 354: return fde_func_0354_0x07071c(a0, a1);
        case 355: return fde_func_0355_0x0707f0(a0, a1);
        case 356: return fde_func_0356_0x0708ac(a0, a1);
        case 357: return fde_func_0357_0x07091c(a0, a1);
        case 358: return fde_func_0358_0x070940(a0, a1);
        case 359: return fde_func_0359_0x070a5c(a0, a1);
        case 360: return fde_func_0360_0x070b08(a0, a1);
        case 361: return fde_func_0361_0x070bd8(a0, a1);
        case 362: return fde_func_0362_0x070c1c(a0, a1);
        case 363: return fde_func_0363_0x070c80(a0, a1);
        case 364: return fde_func_0364_0x070db0(a0, a1);
        case 365: return fde_func_0365_0x070dec(a0, a1);
        case 366: return fde_func_0366_0x070e00(a0, a1);
        case 367: return fde_func_0367_0x070e20(a0, a1);
        case 368: return fde_func_0368_0x070e60(a0, a1);
        case 369: return fde_func_0369_0x070e84(a0, a1);
        case 370: return fde_func_0370_0x070eb0(a0, a1);
        case 371: return fde_func_0371_0x070eec(a0, a1);
        case 372: return fde_func_0372_0x070f0c(a0, a1);
        case 373: return fde_func_0373_0x070f4c(a0, a1);
        case 374: return fde_func_0374_0x070f7c(a0, a1);
        case 375: return fde_func_0375_0x070fb8(a0, a1);
        case 376: return fde_func_0376_0x070fe4(a0, a1);
        case 377: return fde_func_0377_0x071010(a0, a1);
        case 378: return fde_func_0378_0x07104c(a0, a1);
        case 379: return fde_func_0379_0x07108c(a0, a1);
        case 380: return fde_func_0380_0x0710c4(a0, a1);
        case 381: return fde_func_0381_0x0710dc(a0, a1);
        case 382: return fde_func_0382_0x07110c(a0, a1);
        case 383: return fde_func_0383_0x07114c(a0, a1);
        case 384: return fde_func_0384_0x07115c(a0, a1);
        case 385: return fde_func_0385_0x071934(a0, a1);
        case 386: return fde_func_0386_0x071b60(a0, a1);
        case 387: return fde_func_0387_0x071b8c(a0, a1);
        case 388: return fde_func_0388_0x071c44(a0, a1);
        case 389: return fde_func_0389_0x071db4(a0, a1);
        case 390: return fde_func_0390_0x07202c(a0, a1);
        case 391: return fde_func_0391_0x07207c(a0, a1);
        case 392: return fde_func_0392_0x0720b4(a0, a1);
        case 393: return fde_func_0393_0x0721d4(a0, a1);
        case 394: return fde_func_0394_0x072594(a0, a1);
        case 395: return fde_func_0395_0x07259c(a0, a1);
        case 396: return fde_func_0396_0x0725ac(a0, a1);
        case 397: return fde_func_0397_0x072634(a0, a1);
        case 398: return fde_func_0398_0x072680(a0, a1);
        case 399: return fde_func_0399_0x07269c(a0, a1);
        default: return 0ULL;
    }
}

} // namespace ov
} // namespace metasec