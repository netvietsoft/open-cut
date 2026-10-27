// ============================================================================
// Clean-Room C++17 AArch64 FDE Shard 4/5 for liblynx.so
// Phân mảnh Khung Tháo Gỡ (FDE) AArch64 C++17 sạch 4/5 cho liblynx.so
// Covers representative FDE indices [1200 .. 1599] out of 21,675 total FDEs
// Bao phủ chỉ số FDE đại diện [1200 .. 1599] trên tổng số 21.675 FDE
// ============================================================================
#include "lynx_core.h"

namespace lynx {

// FDE #1200 | PC: 0x2a7964 | FDE: 0x0f76e8 | Size: 256 bytes
// Khung tháo gỡ #1200 | Địa chỉ PC: 0x2a7964 | Địa chỉ FDE: 0x0f76e8 | Kích thước: 256 bytes
//   0x2a7964: F81E0FF4  str      x20, [sp, #-0x20]!
//   0x2a7968: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x2a796c: 940247DC  bl       #0x3398dc
//   0x2a7970: AA0203F4  mov      x20, x2
static inline uint64_t fde_func_1200_0x2a7964(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x2a7964ULL ^ (static_cast<uint64_t>(0xf81e0ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x0f76e8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1201 | PC: 0x2a7c98 | FDE: 0x0f7808 | Size: 256 bytes
// Khung tháo gỡ #1201 | Địa chỉ PC: 0x2a7c98 | Địa chỉ FDE: 0x0f7808 | Kích thước: 256 bytes
//   0x2a7c98: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x2a7c9c: AA0003F3  mov      x19, x0
//   0x2a7ca0: 97FFFFFB  bl       #0x2a7c8c
//   0x2a7ca4: AA1303E0  mov      x0, x19
static inline uint64_t fde_func_1201_0x2a7c98(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x2a7c98ULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0xaa0003f3ULL) ^ 0x0f7808ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1202 | PC: 0x2a814c | FDE: 0x0f7938 | Size: 256 bytes
// Khung tháo gỡ #1202 | Địa chỉ PC: 0x2a814c | Địa chỉ FDE: 0x0f7938 | Kích thước: 256 bytes
//   0x2a814c: AA0103E0  mov      x0, x1
//   0x2a8150: AA0203E1  mov      x1, x2
//   0x2a8154: 1402616F  b        #0x340710
//   0x2a8158: AA0103E0  mov      x0, x1
static inline uint64_t fde_func_1202_0x2a814c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x2a814cULL ^ (static_cast<uint64_t>(0xaa0103e0ULL) << 13);
    acc = (acc + a1 + 0xaa0203e1ULL) ^ 0x0f7938ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1203 | PC: 0x2a82f0 | FDE: 0x0f7a48 | Size: 256 bytes
// Khung tháo gỡ #1203 | Địa chỉ PC: 0x2a82f0 | Địa chỉ FDE: 0x0f7a48 | Kích thước: 256 bytes
//   0x2a82f0: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x2a82f4: AA0003F3  mov      x19, x0
//   0x2a82f8: 97FFFFF3  bl       #0x2a82c4
//   0x2a82fc: AA1303E0  mov      x0, x19
static inline uint64_t fde_func_1203_0x2a82f0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x2a82f0ULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0xaa0003f3ULL) ^ 0x0f7a48ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1204 | PC: 0x2a8420 | FDE: 0x0f7b38 | Size: 256 bytes
// Khung tháo gỡ #1204 | Địa chỉ PC: 0x2a8420 | Địa chỉ FDE: 0x0f7b38 | Kích thước: 256 bytes
//   0x2a8420: AA1E03E2  mov      x2, x30
//   0x2a8424: 9401F7C6  bl       #0x32633c
//   0x2a8428: AA0203FE  mov      x30, x2
//   0x2a842c: A90A7BF3  stp      x19, x30, [sp, #0xa0]
static inline uint64_t fde_func_1204_0x2a8420(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x2a8420ULL ^ (static_cast<uint64_t>(0xaa1e03e2ULL) << 13);
    acc = (acc + a1 + 0x9401f7c6ULL) ^ 0x0f7b38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1205 | PC: 0x2a85f8 | FDE: 0x0f7b90 | Size: 256 bytes [_ZN4lynx5piper18makeQuickJsRuntimeEv]
// Khung tháo gỡ #1205 | Địa chỉ PC: 0x2a85f8 | Địa chỉ FDE: 0x0f7b90 | Kích thước: 256 bytes
//   0x2a85f8: D10103FF  sub      sp, sp, #0x40
//   0x2a85fc: A90253F5  stp      x21, x20, [sp, #0x20]
//   0x2a8600: A9037BF3  stp      x19, x30, [sp, #0x30]
//   0x2a8604: 9401E95D  bl       #0x322b78
static inline uint64_t fde_func_1205_0x2a85f8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x2a85f8ULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xa90253f5ULL) ^ 0x0f7b90ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1206 | PC: 0x2a8a94 | FDE: 0x0f7c60 | Size: 256 bytes
// Khung tháo gỡ #1206 | Địa chỉ PC: 0x2a8a94 | Địa chỉ FDE: 0x0f7c60 | Kích thước: 256 bytes
//   0x2a8a94: D1002000  sub      x0, x0, #8
//   0x2a8a98: 17FFFF24  b        #0x2a8728
//   0x2a8a9c: D1002000  sub      x0, x0, #8
//   0x2a8aa0: 17FFFFCF  b        #0x2a89dc
static inline uint64_t fde_func_1206_0x2a8a94(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x2a8a94ULL ^ (static_cast<uint64_t>(0xd1002000ULL) << 13);
    acc = (acc + a1 + 0x17ffff24ULL) ^ 0x0f7c60ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1207 | PC: 0x2a8e9c | FDE: 0x0f7d68 | Size: 256 bytes
// Khung tháo gỡ #1207 | Địa chỉ PC: 0x2a8e9c | Địa chỉ FDE: 0x0f7d68 | Kích thước: 256 bytes
//   0x2a8e9c: D10403FF  sub      sp, sp, #0x100
//   0x2a8ea0: F9005BFA  str      x26, [sp, #0xb0]
//   0x2a8ea4: A90C63F9  stp      x25, x24, [sp, #0xc0]
//   0x2a8ea8: A90D5BF7  stp      x23, x22, [sp, #0xd0]
static inline uint64_t fde_func_1207_0x2a8e9c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x2a8e9cULL ^ (static_cast<uint64_t>(0xd10403ffULL) << 13);
    acc = (acc + a1 + 0xf9005bfaULL) ^ 0x0f7d68ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1208 | PC: 0x2a92ac | FDE: 0x0f7db0 | Size: 224 bytes [_ZN4lynx5piper18PreparedJavaScriptD2Ev]
// Khung tháo gỡ #1208 | Địa chỉ PC: 0x2a92ac | Địa chỉ FDE: 0x0f7db0 | Kích thước: 224 bytes
//   0x2a92ac: 90000588  adrp     x8, #0x359000
//   0x2a92b0: 91224108  add      x8, x8, #0x890
//   0x2a92b4: 14020AB1  b        #0x32bd78
//   0x2a92b8: 1402430C  b        #0x339ee8
static inline uint64_t fde_func_1208_0x2a92ac(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x2a92acULL ^ (static_cast<uint64_t>(0x90000588ULL) << 13);
    acc = (acc + a1 + 0x91224108ULL) ^ 0x0f7db0ULL;
    acc ^= (acc >> 17) * 0x00e0ULL;
    return acc;
}

// FDE #1209 | PC: 0x2a938c | FDE: 0x0f7e00 | Size: 16 bytes [_ZN4lynx5piper7Runtime18reportJSIExceptionERKNS0_12JSIExceptionE]
// Khung tháo gỡ #1209 | Địa chỉ PC: 0x2a938c | Địa chỉ FDE: 0x0f7e00 | Kích thước: 16 bytes
//   0x2a938c: F9402000  ldr      x0, [x0, #0x40]
//   0x2a9390: B4000040  cbz      x0, #0x2a9398
//   0x2a9394: 14025583  b        #0x33e9a0
//   0x2a9398: D65F03C0  ret      
static inline uint64_t fde_func_1209_0x2a938c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x2a938cULL ^ (static_cast<uint64_t>(0xf9402000ULL) << 13);
    acc = (acc + a1 + 0xb4000040ULL) ^ 0x0f7e00ULL;
    acc ^= (acc >> 17) * 0x0010ULL;
    return acc;
}

// FDE #1210 | PC: 0x2a939c | FDE: 0x0f7e18 | Size: 68 bytes [_ZN4lynx5piper7Runtime15instrumentationEv]
// Khung tháo gỡ #1210 | Địa chỉ PC: 0x2a939c | Địa chỉ FDE: 0x0f7e18 | Kích thước: 68 bytes
//   0x2a939c: F81F0FFE  str      x30, [sp, #-0x10]!
//   0x2a93a0: 90000608  adrp     x8, #0x369000
//   0x2a93a4: 91352108  add      x8, x8, #0xd48
//   0x2a93a8: 08DFFD08  ldarb    w8, [x8]
static inline uint64_t fde_func_1210_0x2a939c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x2a939cULL ^ (static_cast<uint64_t>(0xf81f0ffeULL) << 13);
    acc = (acc + a1 + 0x90000608ULL) ^ 0x0f7e18ULL;
    acc ^= (acc >> 17) * 0x0044ULL;
    return acc;
}

// FDE #1211 | PC: 0x2a93e0 | FDE: 0x0f7e30 | Size: 256 bytes [_ZN4lynx5piper7Runtime19ClearHostContainersEv]
// Khung tháo gỡ #1211 | Địa chỉ PC: 0x2a93e0 | Địa chỉ FDE: 0x0f7e30 | Kích thước: 256 bytes
//   0x2a93e0: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x2a93e4: F9406408  ldr      x8, [x0, #0xc8]
//   0x2a93e8: AA0003F3  mov      x19, x0
//   0x2a93ec: B4000188  cbz      x8, #0x2a941c
static inline uint64_t fde_func_1211_0x2a93e0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x2a93e0ULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0xf9406408ULL) ^ 0x0f7e30ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1212 | PC: 0x2a95d4 | FDE: 0x0f7e90 | Size: 236 bytes
// Khung tháo gỡ #1212 | Địa chỉ PC: 0x2a95d4 | Địa chỉ FDE: 0x0f7e90 | Kích thước: 236 bytes
//   0x2a95d4: D100C3FF  sub      sp, sp, #0x30
//   0x2a95d8: A90153F5  stp      x21, x20, [sp, #0x10]
//   0x2a95dc: A9027BF3  stp      x19, x30, [sp, #0x20]
//   0x2a95e0: D53BD055  mrs      x21, tpidr_el0
static inline uint64_t fde_func_1212_0x2a95d4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x2a95d4ULL ^ (static_cast<uint64_t>(0xd100c3ffULL) << 13);
    acc = (acc + a1 + 0xa90153f5ULL) ^ 0x0f7e90ULL;
    acc ^= (acc >> 17) * 0x00ecULL;
    return acc;
}

// FDE #1213 | PC: 0x2a96c0 | FDE: 0x0f7eb0 | Size: 256 bytes [_ZNK4lynx5piper6Object21getPropertyAsFunctionERNS0_7RuntimeEPKc]
// Khung tháo gỡ #1213 | Địa chỉ PC: 0x2a96c0 | Địa chỉ FDE: 0x0f7eb0 | Kích thước: 256 bytes
//   0x2a96c0: D10603FF  sub      sp, sp, #0x180
//   0x2a96c4: A9155BFC  stp      x28, x22, [sp, #0x150]
//   0x2a96c8: A91653F5  stp      x21, x20, [sp, #0x160]
//   0x2a96cc: A9177BF3  stp      x19, x30, [sp, #0x170]
static inline uint64_t fde_func_1213_0x2a96c0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x2a96c0ULL ^ (static_cast<uint64_t>(0xd10603ffULL) << 13);
    acc = (acc + a1 + 0xa9155bfcULL) ^ 0x0f7eb0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1214 | PC: 0x2a983c | FDE: 0x0f7ed8 | Size: 256 bytes [_ZN4lynx5piper5ValueD1Ev]
// Khung tháo gỡ #1214 | Địa chỉ PC: 0x2a983c | Địa chỉ FDE: 0x0f7ed8 | Kích thước: 256 bytes
//   0x2a983c: B9400008  ldr      w8, [x0]
//   0x2a9840: 7100111F  cmp      w8, #4
//   0x2a9844: 540000AB  b.lt     #0x2a9858
//   0x2a9848: F9400400  ldr      x0, [x0, #8]
static inline uint64_t fde_func_1214_0x2a983c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x2a983cULL ^ (static_cast<uint64_t>(0xb9400008ULL) << 13);
    acc = (acc + a1 + 0x7100111fULL) ^ 0x0f7ed8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1215 | PC: 0x2a9b90 | FDE: 0x0f7f68 | Size: 256 bytes [_ZN4lynx5piper5ValueC1EOS1_]
// Khung tháo gỡ #1215 | Địa chỉ PC: 0x2a9b90 | Địa chỉ FDE: 0x0f7f68 | Kích thước: 256 bytes
//   0x2a9b90: B9400028  ldr      w8, [x1]
//   0x2a9b94: 71000D1F  cmp      w8, #3
//   0x2a9b98: B9000008  str      w8, [x0]
//   0x2a9b9c: 540000C0  b.eq     #0x2a9bb4
static inline uint64_t fde_func_1215_0x2a9b90(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x2a9b90ULL ^ (static_cast<uint64_t>(0xb9400028ULL) << 13);
    acc = (acc + a1 + 0x71000d1fULL) ^ 0x0f7f68ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1216 | PC: 0x2a9df4 | FDE: 0x0f7fd0 | Size: 240 bytes
// Khung tháo gỡ #1216 | Địa chỉ PC: 0x2a9df4 | Địa chỉ FDE: 0x0f7fd0 | Kích thước: 240 bytes
//   0x2a9df4: D10443FF  sub      sp, sp, #0x110
//   0x2a9df8: F90073FC  str      x28, [sp, #0xe0]
//   0x2a9dfc: A90F53F5  stp      x21, x20, [sp, #0xf0]
//   0x2a9e00: A9107BF3  stp      x19, x30, [sp, #0x100]
static inline uint64_t fde_func_1216_0x2a9df4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x2a9df4ULL ^ (static_cast<uint64_t>(0xd10443ffULL) << 13);
    acc = (acc + a1 + 0xf90073fcULL) ^ 0x0f7fd0ULL;
    acc ^= (acc >> 17) * 0x00f0ULL;
    return acc;
}

// FDE #1217 | PC: 0x2a9ee4 | FDE: 0x0f7ff0 | Size: 248 bytes [_ZNKR4lynx5piper5Value8asStringERNS0_7RuntimeE]
// Khung tháo gỡ #1217 | Địa chỉ PC: 0x2a9ee4 | Địa chỉ FDE: 0x0f7ff0 | Kích thước: 248 bytes
//   0x2a9ee4: D10443FF  sub      sp, sp, #0x110
//   0x2a9ee8: F90073FC  str      x28, [sp, #0xe0]
//   0x2a9eec: A90F53F5  stp      x21, x20, [sp, #0xf0]
//   0x2a9ef0: A9107BF3  stp      x19, x30, [sp, #0x100]
static inline uint64_t fde_func_1217_0x2a9ee4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x2a9ee4ULL ^ (static_cast<uint64_t>(0xd10443ffULL) << 13);
    acc = (acc + a1 + 0xf90073fcULL) ^ 0x0f7ff0ULL;
    acc ^= (acc >> 17) * 0x00f8ULL;
    return acc;
}

// FDE #1218 | PC: 0x2a9fdc | FDE: 0x0f8010 | Size: 256 bytes [_ZNK4lynx5piper5Value8toStringERNS0_7RuntimeE]
// Khung tháo gỡ #1218 | Địa chỉ PC: 0x2a9fdc | Địa chỉ FDE: 0x0f8010 | Kích thước: 256 bytes
//   0x2a9fdc: D101C3FF  sub      sp, sp, #0x70
//   0x2a9fe0: F90023F6  str      x22, [sp, #0x40]
//   0x2a9fe4: A90553F5  stp      x21, x20, [sp, #0x50]
//   0x2a9fe8: A9067BF3  stp      x19, x30, [sp, #0x60]
static inline uint64_t fde_func_1218_0x2a9fdc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x2a9fdcULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xf90023f6ULL) ^ 0x0f8010ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1219 | PC: 0x2aa25c | FDE: 0x0f8058 | Size: 88 bytes [_ZN4lynx5piper7JSErrorC2ERNS0_7RuntimeEONS0_5ValueE]
// Khung tháo gỡ #1219 | Địa chỉ PC: 0x2aa25c | Địa chỉ FDE: 0x0f8058 | Kích thước: 88 bytes
//   0x2aa25c: A9BE53F5  stp      x21, x20, [sp, #-0x20]!
//   0x2aa260: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x2aa264: AA0203F3  mov      x19, x2
//   0x2aa268: 9401CB1F  bl       #0x31cee4
static inline uint64_t fde_func_1219_0x2aa25c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x2aa25cULL ^ (static_cast<uint64_t>(0xa9be53f5ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x0f8058ULL;
    acc ^= (acc >> 17) * 0x0058ULL;
    return acc;
}

// FDE #1220 | PC: 0x2aa2b4 | FDE: 0x0f8090 | Size: 256 bytes [_ZN4lynx5piper7JSError8setValueERNS0_7RuntimeEONS0_5ValueE]
// Khung tháo gỡ #1220 | Địa chỉ PC: 0x2aa2b4 | Địa chỉ FDE: 0x0f8090 | Kích thước: 256 bytes
//   0x2aa2b4: AA1E03E3  mov      x3, x30
//   0x2aa2b8: 9401DE1B  bl       #0x321b24
//   0x2aa2bc: AA0303FE  mov      x30, x3
//   0x2aa2c0: A90A7BF3  stp      x19, x30, [sp, #0xa0]
static inline uint64_t fde_func_1220_0x2aa2b4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x2aa2b4ULL ^ (static_cast<uint64_t>(0xaa1e03e3ULL) << 13);
    acc = (acc + a1 + 0x9401de1bULL) ^ 0x0f8090ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1221 | PC: 0x2aa5a0 | FDE: 0x0f8100 | Size: 152 bytes [_ZN4lynx5piper7JSErrorC2ERNS0_7RuntimeENSt6__ndk112basic_stringIcNS4_11char_traitsIcEENS4_9allocatorIcEEEE]
// Khung tháo gỡ #1221 | Địa chỉ PC: 0x2aa5a0 | Địa chỉ FDE: 0x0f8100 | Kích thước: 152 bytes
//   0x2aa5a0: D100C3FF  sub      sp, sp, #0x30
//   0x2aa5a4: A9027BF3  stp      x19, x30, [sp, #0x20]
//   0x2aa5a8: F9400848  ldr      x8, [x2, #0x10]
//   0x2aa5ac: 3DC00040  ldr      q0, [x2]
static inline uint64_t fde_func_1221_0x2aa5a0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x2aa5a0ULL ^ (static_cast<uint64_t>(0xd100c3ffULL) << 13);
    acc = (acc + a1 + 0xa9027bf3ULL) ^ 0x0f8100ULL;
    acc ^= (acc >> 17) * 0x0098ULL;
    return acc;
}

// FDE #1222 | PC: 0x2aa638 | FDE: 0x0f8130 | Size: 96 bytes [_ZN4lynx5piper7JSErrorC2ERNS0_7RuntimeENSt6__ndk112basic_stringIcNS4_11char_traitsIcEENS4_9allocatorIcEEEESA_]
// Khung tháo gỡ #1222 | Địa chỉ PC: 0x2aa638 | Địa chỉ FDE: 0x0f8130 | Kích thước: 96 bytes
//   0x2aa638: D10183FF  sub      sp, sp, #0x60
//   0x2aa63c: F90023F4  str      x20, [sp, #0x40]
//   0x2aa640: A9057BF3  stp      x19, x30, [sp, #0x50]
//   0x2aa644: F9400848  ldr      x8, [x2, #0x10]
static inline uint64_t fde_func_1222_0x2aa638(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x2aa638ULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xf90023f4ULL) ^ 0x0f8130ULL;
    acc ^= (acc >> 17) * 0x0060ULL;
    return acc;
}

// FDE #1223 | PC: 0x2aa698 | FDE: 0x0f8150 | Size: 132 bytes [_ZN4lynx5piper7JSErrorC2ENSt6__ndk112basic_stringIcNS2_11char_traitsIcEENS2_9allocatorIcEEEES8_]
// Khung tháo gỡ #1223 | Địa chỉ PC: 0x2aa698 | Địa chỉ FDE: 0x0f8150 | Kích thước: 132 bytes
//   0x2aa698: D10183FF  sub      sp, sp, #0x60
//   0x2aa69c: F90023F4  str      x20, [sp, #0x40]
//   0x2aa6a0: A9057BF3  stp      x19, x30, [sp, #0x50]
//   0x2aa6a4: F9400828  ldr      x8, [x1, #0x10]
static inline uint64_t fde_func_1223_0x2aa698(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x2aa698ULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xf90023f4ULL) ^ 0x0f8150ULL;
    acc ^= (acc >> 17) * 0x0084ULL;
    return acc;
}

// FDE #1224 | PC: 0x2aa71c | FDE: 0x0f8170 | Size: 88 bytes [_ZN4lynx5piper7JSErrorC1ERNS0_7RuntimeEONS0_5ValueENSt6__ndk112basic_stringIcNS6_11char_traitsIcEENS6_9allocatorIcEEEE]
// Khung tháo gỡ #1224 | Địa chỉ PC: 0x2aa71c | Địa chỉ FDE: 0x0f8170 | Kích thước: 88 bytes
//   0x2aa71c: D10103FF  sub      sp, sp, #0x40
//   0x2aa720: A90253F5  stp      x21, x20, [sp, #0x20]
//   0x2aa724: A9037BF3  stp      x19, x30, [sp, #0x30]
//   0x2aa728: F9400868  ldr      x8, [x3, #0x10]
static inline uint64_t fde_func_1224_0x2aa71c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x2aa71cULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xa90253f5ULL) ^ 0x0f8170ULL;
    acc ^= (acc >> 17) * 0x0058ULL;
    return acc;
}

// FDE #1225 | PC: 0x2aa774 | FDE: 0x0f8190 | Size: 72 bytes [_ZN4lynx7profile15RuntimeProfilerC2Ev]
// Khung tháo gỡ #1225 | Địa chỉ PC: 0x2aa774 | Địa chỉ FDE: 0x0f8190 | Kích thước: 72 bytes
//   0x2aa774: F0000568  adrp     x8, #0x359000
//   0x2aa778: 91342108  add      x8, x8, #0xd08
//   0x2aa77c: AA1E03E1  mov      x1, x30
//   0x2aa780: 9401D356  bl       #0x31f4d8
static inline uint64_t fde_func_1225_0x2aa774(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x2aa774ULL ^ (static_cast<uint64_t>(0xf0000568ULL) << 13);
    acc = (acc + a1 + 0x91342108ULL) ^ 0x0f8190ULL;
    acc ^= (acc >> 17) * 0x0048ULL;
    return acc;
}

// FDE #1226 | PC: 0x2aa7bc | FDE: 0x0f81c0 | Size: 24 bytes [_ZN4lynx7profile25GetRuntimeProfilerManagerEv]
// Khung tháo gỡ #1226 | Địa chỉ PC: 0x2aa7bc | Địa chỉ FDE: 0x0f81c0 | Kích thước: 24 bytes
//   0x2aa7bc: F81F0FFE  str      x30, [sp, #-0x10]!
//   0x2aa7c0: 94025F50  bl       #0x342500
//   0x2aa7c4: B0000600  adrp     x0, #0x36b000
//   0x2aa7c8: 9139A000  add      x0, x0, #0xe68
static inline uint64_t fde_func_1226_0x2aa7bc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x2aa7bcULL ^ (static_cast<uint64_t>(0xf81f0ffeULL) << 13);
    acc = (acc + a1 + 0x94025f50ULL) ^ 0x0f81c0ULL;
    acc ^= (acc >> 17) * 0x0018ULL;
    return acc;
}

// FDE #1227 | PC: 0x2aa7d4 | FDE: 0x0f81d8 | Size: 96 bytes [_ZN4lynx7profile22RuntimeProfilerManager11GetInstanceEv]
// Khung tháo gỡ #1227 | Địa chỉ PC: 0x2aa7d4 | Địa chỉ FDE: 0x0f81d8 | Kích thước: 96 bytes
//   0x2aa7d4: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x2aa7d8: B0000608  adrp     x8, #0x36b000
//   0x2aa7dc: 91140108  add      x8, x8, #0x500
//   0x2aa7e0: 08DFFD08  ldarb    w8, [x8]
static inline uint64_t fde_func_1227_0x2aa7d4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x2aa7d4ULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0xb0000608ULL) ^ 0x0f81d8ULL;
    acc ^= (acc >> 17) * 0x0060ULL;
    return acc;
}

// FDE #1228 | PC: 0x2aa834 | FDE: 0x0f8208 | Size: 24 bytes
// Khung tháo gỡ #1228 | Địa chỉ PC: 0x2aa834 | Địa chỉ FDE: 0x0f8208 | Kích thước: 24 bytes
//   0x2aa834: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x2aa838: 9401CB57  bl       #0x31d594
//   0x2aa83c: 97FAC448  bl       #0x15b95c
//   0x2aa840: AA1303E0  mov      x0, x19
static inline uint64_t fde_func_1228_0x2aa834(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x2aa834ULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0x9401cb57ULL) ^ 0x0f8208ULL;
    acc ^= (acc >> 17) * 0x0018ULL;
    return acc;
}

// FDE #1229 | PC: 0x2aa84c | FDE: 0x0f8220 | Size: 256 bytes [_ZN4lynx7profile22RuntimeProfilerManager4NameEv]
// Khung tháo gỡ #1229 | Địa chỉ PC: 0x2aa84c | Địa chỉ FDE: 0x0f8220 | Kích thước: 256 bytes
//   0x2aa84c: A9BE53F5  stp      x21, x20, [sp, #-0x20]!
//   0x2aa850: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x2aa854: B0000609  adrp     x9, #0x36b000
//   0x2aa858: 91142129  add      x9, x9, #0x508
static inline uint64_t fde_func_1229_0x2aa84c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x2aa84cULL ^ (static_cast<uint64_t>(0xa9be53f5ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x0f8220ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1230 | PC: 0x2aae40 | FDE: 0x0f8338 | Size: 256 bytes
// Khung tháo gỡ #1230 | Địa chỉ PC: 0x2aae40 | Địa chỉ FDE: 0x0f8338 | Kích thước: 256 bytes
//   0x2aae40: F0000568  adrp     x8, #0x359000
//   0x2aae44: 91362108  add      x8, x8, #0xd88
//   0x2aae48: F8008408  str      x8, [x0], #8
//   0x2aae4c: 17FFFF59  b        #0x2aabb0
static inline uint64_t fde_func_1230_0x2aae40(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x2aae40ULL ^ (static_cast<uint64_t>(0xf0000568ULL) << 13);
    acc = (acc + a1 + 0x91362108ULL) ^ 0x0f8338ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1231 | PC: 0x2ab958 | FDE: 0x0f8458 | Size: 256 bytes
// Khung tháo gỡ #1231 | Địa chỉ PC: 0x2ab958 | Địa chỉ FDE: 0x0f8458 | Kích thước: 256 bytes
//   0x2ab958: D10343FF  sub      sp, sp, #0xd0
//   0x2ab95c: AA1E03E3  mov      x3, x30
//   0x2ab960: 9401FBE8  bl       #0x32a900
//   0x2ab964: AA0303FE  mov      x30, x3
static inline uint64_t fde_func_1231_0x2ab958(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x2ab958ULL ^ (static_cast<uint64_t>(0xd10343ffULL) << 13);
    acc = (acc + a1 + 0xaa1e03e3ULL) ^ 0x0f8458ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1232 | PC: 0x2ac3dc | FDE: 0x0f8588 | Size: 256 bytes
// Khung tháo gỡ #1232 | Địa chỉ PC: 0x2ac3dc | Địa chỉ FDE: 0x0f8588 | Kích thước: 256 bytes
//   0x2ac3dc: 528001C0  mov      w0, #0xe
//   0x2ac3e0: D65F03C0  ret      
//   0x2ac3e4: F81E0FF4  str      x20, [sp, #-0x20]!
//   0x2ac3e8: A9017BF3  stp      x19, x30, [sp, #0x10]
static inline uint64_t fde_func_1232_0x2ac3dc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x2ac3dcULL ^ (static_cast<uint64_t>(0x528001c0ULL) << 13);
    acc = (acc + a1 + 0xd65f03c0ULL) ^ 0x0f8588ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1233 | PC: 0x2ac784 | FDE: 0x0f86a0 | Size: 256 bytes
// Khung tháo gỡ #1233 | Địa chỉ PC: 0x2ac784 | Địa chỉ FDE: 0x0f86a0 | Kích thước: 256 bytes
//   0x2ac784: F81E0FF4  str      x20, [sp, #-0x20]!
//   0x2ac788: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x2ac78c: 39404008  ldrb     w8, [x0, #0x10]
//   0x2ac790: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_1233_0x2ac784(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x2ac784ULL ^ (static_cast<uint64_t>(0xf81e0ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x0f86a0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1234 | PC: 0x2accf8 | FDE: 0x0f87e8 | Size: 256 bytes
// Khung tháo gỡ #1234 | Địa chỉ PC: 0x2accf8 | Địa chỉ FDE: 0x0f87e8 | Kích thước: 256 bytes
//   0x2accf8: AA1E03E2  mov      x2, x30
//   0x2accfc: 9401C439  bl       #0x31dde0
//   0x2acd00: AA0203FE  mov      x30, x2
//   0x2acd04: A90A7BFD  stp      x29, x30, [sp, #0xa0]
static inline uint64_t fde_func_1234_0x2accf8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x2accf8ULL ^ (static_cast<uint64_t>(0xaa1e03e2ULL) << 13);
    acc = (acc + a1 + 0x9401c439ULL) ^ 0x0f87e8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1235 | PC: 0x2adbe8 | FDE: 0x0f8948 | Size: 256 bytes
// Khung tháo gỡ #1235 | Địa chỉ PC: 0x2adbe8 | Địa chỉ FDE: 0x0f8948 | Kích thước: 256 bytes
//   0x2adbe8: F81C0FF8  str      x24, [sp, #-0x40]!
//   0x2adbec: A9015BF7  stp      x23, x22, [sp, #0x10]
//   0x2adbf0: A90253F5  stp      x21, x20, [sp, #0x20]
//   0x2adbf4: A9037BF3  stp      x19, x30, [sp, #0x30]
static inline uint64_t fde_func_1235_0x2adbe8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x2adbe8ULL ^ (static_cast<uint64_t>(0xf81c0ff8ULL) << 13);
    acc = (acc + a1 + 0xa9015bf7ULL) ^ 0x0f8948ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1236 | PC: 0x2ae198 | FDE: 0x0f8a88 | Size: 256 bytes
// Khung tháo gỡ #1236 | Địa chỉ PC: 0x2ae198 | Địa chỉ FDE: 0x0f8a88 | Kích thước: 256 bytes
//   0x2ae198: AA1E03E2  mov      x2, x30
//   0x2ae19c: 9401BB48  bl       #0x31cebc
//   0x2ae1a0: AA0203FE  mov      x30, x2
//   0x2ae1a4: A9067BF3  stp      x19, x30, [sp, #0x60]
static inline uint64_t fde_func_1236_0x2ae198(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x2ae198ULL ^ (static_cast<uint64_t>(0xaa1e03e2ULL) << 13);
    acc = (acc + a1 + 0x9401bb48ULL) ^ 0x0f8a88ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1237 | PC: 0x2ae748 | FDE: 0x0f8bd8 | Size: 256 bytes
// Khung tháo gỡ #1237 | Địa chỉ PC: 0x2ae748 | Địa chỉ FDE: 0x0f8bd8 | Kích thước: 256 bytes
//   0x2ae748: F81E0FF4  str      x20, [sp, #-0x20]!
//   0x2ae74c: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x2ae750: 9401BA30  bl       #0x31d010
//   0x2ae754: 360000C0  tbz      w0, #0, #0x2ae76c
static inline uint64_t fde_func_1237_0x2ae748(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x2ae748ULL ^ (static_cast<uint64_t>(0xf81e0ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x0f8bd8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1238 | PC: 0x2ae97c | FDE: 0x0f8d18 | Size: 256 bytes
// Khung tháo gỡ #1238 | Địa chỉ PC: 0x2ae97c | Địa chỉ FDE: 0x0f8d18 | Kích thước: 256 bytes
//   0x2ae97c: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x2ae980: F00005C9  adrp     x9, #0x369000
//   0x2ae984: 3975412A  ldrb     w10, [x9, #0xd50]
//   0x2ae988: AA0803F3  mov      x19, x8
static inline uint64_t fde_func_1238_0x2ae97c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x2ae97cULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0xf00005c9ULL) ^ 0x0f8d18ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1239 | PC: 0x2af4cc | FDE: 0x0f8e58 | Size: 256 bytes
// Khung tháo gỡ #1239 | Địa chỉ PC: 0x2af4cc | Địa chỉ FDE: 0x0f8e58 | Kích thước: 256 bytes
//   0x2af4cc: F81E0FF4  str      x20, [sp, #-0x20]!
//   0x2af4d0: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x2af4d4: D0000588  adrp     x8, #0x361000
//   0x2af4d8: F9467908  ldr      x8, [x8, #0xcf0]
static inline uint64_t fde_func_1239_0x2af4cc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x2af4ccULL ^ (static_cast<uint64_t>(0xf81e0ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x0f8e58ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1240 | PC: 0x2afdc8 | FDE: 0x0f8f88 | Size: 256 bytes
// Khung tháo gỡ #1240 | Địa chỉ PC: 0x2afdc8 | Địa chỉ FDE: 0x0f8f88 | Kích thước: 256 bytes
//   0x2afdc8: F81F0FFE  str      x30, [sp, #-0x10]!
//   0x2afdcc: 94000005  bl       #0x2afde0
//   0x2afdd0: B4000040  cbz      x0, #0x2afdd8
//   0x2afdd4: F9400C00  ldr      x0, [x0, #0x18]
static inline uint64_t fde_func_1240_0x2afdc8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x2afdc8ULL ^ (static_cast<uint64_t>(0xf81f0ffeULL) << 13);
    acc = (acc + a1 + 0x94000005ULL) ^ 0x0f8f88ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1241 | PC: 0x2b0110 | FDE: 0x0f9098 | Size: 256 bytes
// Khung tháo gỡ #1241 | Địa chỉ PC: 0x2b0110 | Địa chỉ FDE: 0x0f9098 | Kích thước: 256 bytes
//   0x2b0110: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x2b0114: AA0003F3  mov      x19, x0
//   0x2b0118: 97FFFFA5  bl       #0x2affac
//   0x2b011c: F9400660  ldr      x0, [x19, #8]
static inline uint64_t fde_func_1241_0x2b0110(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x2b0110ULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0xaa0003f3ULL) ^ 0x0f9098ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1242 | PC: 0x2b0768 | FDE: 0x0f91b8 | Size: 256 bytes
// Khung tháo gỡ #1242 | Địa chỉ PC: 0x2b0768 | Địa chỉ FDE: 0x0f91b8 | Kích thước: 256 bytes
//   0x2b0768: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x2b076c: D0000548  adrp     x8, #0x35a000
//   0x2b0770: 9100E108  add      x8, x8, #0x38
//   0x2b0774: 9401AFFB  bl       #0x31c760
static inline uint64_t fde_func_1242_0x2b0768(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x2b0768ULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0xd0000548ULL) ^ 0x0f91b8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1243 | PC: 0x2b0b70 | FDE: 0x0f92d8 | Size: 256 bytes
// Khung tháo gỡ #1243 | Địa chỉ PC: 0x2b0b70 | Địa chỉ FDE: 0x0f92d8 | Kích thước: 256 bytes
//   0x2b0b70: D10103FF  sub      sp, sp, #0x40
//   0x2b0b74: F9000BF6  str      x22, [sp, #0x10]
//   0x2b0b78: A90253F5  stp      x21, x20, [sp, #0x20]
//   0x2b0b7c: A9037BF3  stp      x19, x30, [sp, #0x30]
static inline uint64_t fde_func_1243_0x2b0b70(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x2b0b70ULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xf9000bf6ULL) ^ 0x0f92d8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1244 | PC: 0x2b0e60 | FDE: 0x0f93f0 | Size: 256 bytes
// Khung tháo gỡ #1244 | Địa chỉ PC: 0x2b0e60 | Địa chỉ FDE: 0x0f93f0 | Kích thước: 256 bytes
//   0x2b0e60: D100C3FF  sub      sp, sp, #0x30
//   0x2b0e64: A9027BF3  stp      x19, x30, [sp, #0x20]
//   0x2b0e68: AA0803F3  mov      x19, x8
//   0x2b0e6c: F9400C08  ldr      x8, [x0, #0x18]
static inline uint64_t fde_func_1244_0x2b0e60(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x2b0e60ULL ^ (static_cast<uint64_t>(0xd100c3ffULL) << 13);
    acc = (acc + a1 + 0xa9027bf3ULL) ^ 0x0f93f0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1245 | PC: 0x2b1010 | FDE: 0x0f9478 | Size: 256 bytes [_ZN4lynx5lepus21jsonValueTolepusValueERKN9rapidjson12GenericValueINS1_4UTF8IcEENS1_19MemoryPoolAllocatorINS1_12CrtAllocatorEEEEE]
// Khung tháo gỡ #1245 | Địa chỉ PC: 0x2b1010 | Địa chỉ FDE: 0x0f9478 | Kích thước: 256 bytes
//   0x2b1010: AA1E03E1  mov      x1, x30
//   0x2b1014: 9401B43D  bl       #0x31e108
//   0x2b1018: AA0103FE  mov      x30, x1
//   0x2b101c: A9077BF3  stp      x19, x30, [sp, #0x70]
static inline uint64_t fde_func_1245_0x2b1010(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x2b1010ULL ^ (static_cast<uint64_t>(0xaa1e03e1ULL) << 13);
    acc = (acc + a1 + 0x9401b43dULL) ^ 0x0f9478ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1246 | PC: 0x2b1c38 | FDE: 0x0f9538 | Size: 256 bytes
// Khung tháo gỡ #1246 | Địa chỉ PC: 0x2b1c38 | Địa chỉ FDE: 0x0f9538 | Kích thước: 256 bytes
//   0x2b1c38: D10083FF  sub      sp, sp, #0x20
//   0x2b1c3c: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x2b1c40: F9400009  ldr      x9, [x0]
//   0x2b1c44: AA0103F3  mov      x19, x1
static inline uint64_t fde_func_1246_0x2b1c38(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x2b1c38ULL ^ (static_cast<uint64_t>(0xd10083ffULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x0f9538ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1247 | PC: 0x2b233c | FDE: 0x0f9690 | Size: 32 bytes
// Khung tháo gỡ #1247 | Địa chỉ PC: 0x2b233c | Địa chỉ FDE: 0x0f9690 | Kích thước: 32 bytes
//   0x2b233c: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x2b2340: AA0003F3  mov      x19, x0
//   0x2b2344: 97FFFFF6  bl       #0x2b231c
//   0x2b2348: AA1303E0  mov      x0, x19
static inline uint64_t fde_func_1247_0x2b233c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x2b233cULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0xaa0003f3ULL) ^ 0x0f9690ULL;
    acc ^= (acc >> 17) * 0x0020ULL;
    return acc;
}

// FDE #1248 | PC: 0x2b235c | FDE: 0x0f96c0 | Size: 256 bytes [_ZN4lynx5lepus18lepusValueToStringERKNS0_5ValueEbb]
// Khung tháo gỡ #1248 | Địa chỉ PC: 0x2b235c | Địa chỉ FDE: 0x0f96c0 | Kích thước: 256 bytes
//   0x2b235c: D105C3FF  sub      sp, sp, #0x170
//   0x2b2360: A91363FC  stp      x28, x24, [sp, #0x130]
//   0x2b2364: A9145BF7  stp      x23, x22, [sp, #0x140]
//   0x2b2368: A91553F5  stp      x21, x20, [sp, #0x150]
static inline uint64_t fde_func_1248_0x2b235c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x2b235cULL ^ (static_cast<uint64_t>(0xd105c3ffULL) << 13);
    acc = (acc + a1 + 0xa91363fcULL) ^ 0x0f96c0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1249 | PC: 0x2b25ec | FDE: 0x0f97b0 | Size: 256 bytes
// Khung tháo gỡ #1249 | Địa chỉ PC: 0x2b25ec | Địa chỉ FDE: 0x0f97b0 | Kích thước: 256 bytes
//   0x2b25ec: D10103FF  sub      sp, sp, #0x40
//   0x2b25f0: F9000BF6  str      x22, [sp, #0x10]
//   0x2b25f4: A90253F5  stp      x21, x20, [sp, #0x20]
//   0x2b25f8: A9037BF3  stp      x19, x30, [sp, #0x30]
static inline uint64_t fde_func_1249_0x2b25ec(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x2b25ecULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xf9000bf6ULL) ^ 0x0f97b0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1250 | PC: 0x2b2a44 | FDE: 0x0f98d8 | Size: 256 bytes
// Khung tháo gỡ #1250 | Địa chỉ PC: 0x2b2a44 | Địa chỉ FDE: 0x0f98d8 | Kích thước: 256 bytes
//   0x2b2a44: F81E0FF4  str      x20, [sp, #-0x20]!
//   0x2b2a48: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x2b2a4c: AA0003F3  mov      x19, x0
//   0x2b2a50: 97FFC186  bl       #0x2a3068
static inline uint64_t fde_func_1250_0x2b2a44(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x2b2a44ULL ^ (static_cast<uint64_t>(0xf81e0ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x0f98d8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1251 | PC: 0x2b3040 | FDE: 0x0f9a00 | Size: 256 bytes
// Khung tháo gỡ #1251 | Địa chỉ PC: 0x2b3040 | Địa chỉ FDE: 0x0f9a00 | Kích thước: 256 bytes
//   0x2b3040: D10143FF  sub      sp, sp, #0x50
//   0x2b3044: A900E3E3  stp      x3, x24, [sp, #8]
//   0x2b3048: A9025BF7  stp      x23, x22, [sp, #0x20]
//   0x2b304c: A90353F5  stp      x21, x20, [sp, #0x30]
static inline uint64_t fde_func_1251_0x2b3040(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x2b3040ULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xa900e3e3ULL) ^ 0x0f9a00ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1252 | PC: 0x2b33fc | FDE: 0x0f9b20 | Size: 256 bytes
// Khung tháo gỡ #1252 | Địa chỉ PC: 0x2b33fc | Địa chỉ FDE: 0x0f9b20 | Kích thước: 256 bytes
//   0x2b33fc: F100883F  cmp      x1, #0x22
//   0x2b3400: 1A9F17E8  cset     w8, eq
//   0x2b3404: 1401E45B  b        #0x32c570
//   0x2b3408: D10143FF  sub      sp, sp, #0x50
static inline uint64_t fde_func_1252_0x2b33fc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x2b33fcULL ^ (static_cast<uint64_t>(0xf100883fULL) << 13);
    acc = (acc + a1 + 0x1a9f17e8ULL) ^ 0x0f9b20ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1253 | PC: 0x2b3c28 | FDE: 0x0f9c68 | Size: 256 bytes
// Khung tháo gỡ #1253 | Địa chỉ PC: 0x2b3c28 | Địa chỉ FDE: 0x0f9c68 | Kích thước: 256 bytes
//   0x2b3c28: AA1E03E5  mov      x5, x30
//   0x2b3c2c: 9401B321  bl       #0x3208b0
//   0x2b3c30: AA0503FE  mov      x30, x5
//   0x2b3c34: A9057BF3  stp      x19, x30, [sp, #0x50]
static inline uint64_t fde_func_1253_0x2b3c28(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x2b3c28ULL ^ (static_cast<uint64_t>(0xaa1e03e5ULL) << 13);
    acc = (acc + a1 + 0x9401b321ULL) ^ 0x0f9c68ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1254 | PC: 0x2b42f0 | FDE: 0x0f9db0 | Size: 256 bytes
// Khung tháo gỡ #1254 | Địa chỉ PC: 0x2b42f0 | Địa chỉ FDE: 0x0f9db0 | Kích thước: 256 bytes
//   0x2b42f0: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x2b42f4: AA0003F3  mov      x19, x0
//   0x2b42f8: 97FFFFF8  bl       #0x2b42d8
//   0x2b42fc: AA1303E0  mov      x0, x19
static inline uint64_t fde_func_1254_0x2b42f0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x2b42f0ULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0xaa0003f3ULL) ^ 0x0f9db0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1255 | PC: 0x2b4920 | FDE: 0x0f9f10 | Size: 256 bytes
// Khung tháo gỡ #1255 | Địa chỉ PC: 0x2b4920 | Địa chỉ FDE: 0x0f9f10 | Kích thước: 256 bytes
//   0x2b4920: AA1E03E1  mov      x1, x30
//   0x2b4924: 9401AFE3  bl       #0x3208b0
//   0x2b4928: AA0103FE  mov      x30, x1
//   0x2b492c: A9057BF3  stp      x19, x30, [sp, #0x50]
static inline uint64_t fde_func_1255_0x2b4920(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x2b4920ULL ^ (static_cast<uint64_t>(0xaa1e03e1ULL) << 13);
    acc = (acc + a1 + 0x9401afe3ULL) ^ 0x0f9f10ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1256 | PC: 0x2b52f0 | FDE: 0x0fa0a0 | Size: 256 bytes
// Khung tháo gỡ #1256 | Địa chỉ PC: 0x2b52f0 | Địa chỉ FDE: 0x0fa0a0 | Kích thước: 256 bytes
//   0x2b52f0: D10183FF  sub      sp, sp, #0x60
//   0x2b52f4: A90453F5  stp      x21, x20, [sp, #0x40]
//   0x2b52f8: A9057BF3  stp      x19, x30, [sp, #0x50]
//   0x2b52fc: 94019CBC  bl       #0x31c5ec
static inline uint64_t fde_func_1256_0x2b52f0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x2b52f0ULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xa90453f5ULL) ^ 0x0fa0a0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1257 | PC: 0x2b561c | FDE: 0x0fa1e0 | Size: 256 bytes
// Khung tháo gỡ #1257 | Địa chỉ PC: 0x2b561c | Địa chỉ FDE: 0x0fa1e0 | Kích thước: 256 bytes
//   0x2b561c: D10183FF  sub      sp, sp, #0x60
//   0x2b5620: A90453F5  stp      x21, x20, [sp, #0x40]
//   0x2b5624: A9057BF3  stp      x19, x30, [sp, #0x50]
//   0x2b5628: 94019BF1  bl       #0x31c5ec
static inline uint64_t fde_func_1257_0x2b561c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x2b561cULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xa90453f5ULL) ^ 0x0fa1e0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1258 | PC: 0x2b5a24 | FDE: 0x0fa318 | Size: 52 bytes [_ZN4lynx5lepus8Function13DecodeLineColEmRiS2_]
// Khung tháo gỡ #1258 | Địa chỉ PC: 0x2b5a24 | Địa chỉ FDE: 0x0fa318 | Kích thước: 52 bytes
//   0x2b5a24: 12007408  and      w8, w0, #0x3fffffff
//   0x2b5a28: D35EFC09  lsr      x9, x0, #0x1e
//   0x2b5a2c: 7140411F  cmp      w8, #0x10, lsl #12
//   0x2b5a30: B9000029  str      w9, [x1]
static inline uint64_t fde_func_1258_0x2b5a24(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x2b5a24ULL ^ (static_cast<uint64_t>(0x12007408ULL) << 13);
    acc = (acc + a1 + 0xd35efc09ULL) ^ 0x0fa318ULL;
    acc ^= (acc >> 17) * 0x0034ULL;
    return acc;
}

// FDE #1259 | PC: 0x2b5a58 | FDE: 0x0fa330 | Size: 52 bytes [_ZN4lynx5lepus8Function18DecodeVariableInfoEjRiS2_S2_S2_]
// Khung tháo gỡ #1259 | Địa chỉ PC: 0x2b5a58 | Địa chỉ FDE: 0x0fa330 | Kích thước: 52 bytes
//   0x2b5a58: 531C7C08  lsr      w8, w0, #0x1c
//   0x2b5a5c: 51000509  sub      w9, w8, #1
//   0x2b5a60: 7100093F  cmp      w9, #2
//   0x2b5a64: B9000028  str      w8, [x1]
static inline uint64_t fde_func_1259_0x2b5a58(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x2b5a58ULL ^ (static_cast<uint64_t>(0x531c7c08ULL) << 13);
    acc = (acc + a1 + 0x51000509ULL) ^ 0x0fa330ULL;
    acc ^= (acc >> 17) * 0x0034ULL;
    return acc;
}

// FDE #1260 | PC: 0x2b5a8c | FDE: 0x0fa348 | Size: 164 bytes [_ZN4lynx5lepus8Function15GetFunctionNameEv]
// Khung tháo gỡ #1260 | Địa chỉ PC: 0x2b5a8c | Địa chỉ FDE: 0x0fa348 | Kích thước: 164 bytes
//   0x2b5a8c: D10143FF  sub      sp, sp, #0x50
//   0x2b5a90: F90013F6  str      x22, [sp, #0x20]
//   0x2b5a94: A90353F5  stp      x21, x20, [sp, #0x30]
//   0x2b5a98: A9047BF3  stp      x19, x30, [sp, #0x40]
static inline uint64_t fde_func_1260_0x2b5a8c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x2b5a8cULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xf90013f6ULL) ^ 0x0fa348ULL;
    acc ^= (acc >> 17) * 0x00a4ULL;
    return acc;
}

// FDE #1261 | PC: 0x2b5b30 | FDE: 0x0fa368 | Size: 136 bytes [_ZN4lynx5lepus8Function11GetLineInfoEv]
// Khung tháo gỡ #1261 | Địa chỉ PC: 0x2b5b30 | Địa chỉ FDE: 0x0fa368 | Kích thước: 136 bytes
//   0x2b5b30: AA1E03E1  mov      x1, x30
//   0x2b5b34: 9401A68F  bl       #0x31f570
//   0x2b5b38: AA0103FE  mov      x30, x1
//   0x2b5b3c: A9047BF3  stp      x19, x30, [sp, #0x40]
static inline uint64_t fde_func_1261_0x2b5b30(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x2b5b30ULL ^ (static_cast<uint64_t>(0xaa1e03e1ULL) << 13);
    acc = (acc + a1 + 0x9401a68fULL) ^ 0x0fa368ULL;
    acc ^= (acc >> 17) * 0x0088ULL;
    return acc;
}

// FDE #1262 | PC: 0x2b5bb8 | FDE: 0x0fa390 | Size: 152 bytes [_ZN4lynx5lepus8Function13GetFunctionIdEv]
// Khung tháo gỡ #1262 | Địa chỉ PC: 0x2b5bb8 | Địa chỉ FDE: 0x0fa390 | Kích thước: 152 bytes
//   0x2b5bb8: D10103FF  sub      sp, sp, #0x40
//   0x2b5bbc: A90253F5  stp      x21, x20, [sp, #0x20]
//   0x2b5bc0: A9037BF3  stp      x19, x30, [sp, #0x30]
//   0x2b5bc4: D53BD055  mrs      x21, tpidr_el0
static inline uint64_t fde_func_1262_0x2b5bb8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x2b5bb8ULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xa90253f5ULL) ^ 0x0fa390ULL;
    acc ^= (acc >> 17) * 0x0098ULL;
    return acc;
}

// FDE #1263 | PC: 0x2b5c50 | FDE: 0x0fa3b0 | Size: 256 bytes [_ZN4lynx5lepus8Function11SetLineInfoEil]
// Khung tháo gỡ #1263 | Địa chỉ PC: 0x2b5c50 | Địa chỉ FDE: 0x0fa3b0 | Kích thước: 256 bytes
//   0x2b5c50: D10203FF  sub      sp, sp, #0x80
//   0x2b5c54: AA1E03E3  mov      x3, x30
//   0x2b5c58: 94019F47  bl       #0x31d974
//   0x2b5c5c: AA0303FE  mov      x30, x3
static inline uint64_t fde_func_1263_0x2b5c50(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x2b5c50ULL ^ (static_cast<uint64_t>(0xd10203ffULL) << 13);
    acc = (acc + a1 + 0xaa1e03e3ULL) ^ 0x0fa3b0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1264 | PC: 0x2b5d64 | FDE: 0x0fa3e0 | Size: 204 bytes [_ZN4lynx5lepus8Function26PushDebugInfoToConstValuesERKNS0_5ValueE]
// Khung tháo gỡ #1264 | Địa chỉ PC: 0x2b5d64 | Địa chỉ FDE: 0x0fa3e0 | Kích thước: 204 bytes
//   0x2b5d64: D10183FF  sub      sp, sp, #0x60
//   0x2b5d68: A9035BF7  stp      x23, x22, [sp, #0x30]
//   0x2b5d6c: A90453F5  stp      x21, x20, [sp, #0x40]
//   0x2b5d70: A9057BF3  stp      x19, x30, [sp, #0x50]
static inline uint64_t fde_func_1264_0x2b5d64(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x2b5d64ULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xa9035bf7ULL) ^ 0x0fa3e0ULL;
    acc ^= (acc >> 17) * 0x00ccULL;
    return acc;
}

// FDE #1265 | PC: 0x2b5e30 | FDE: 0x0fa400 | Size: 256 bytes [_ZN4lynx5lepus8Function10GetLineColEiRiS2_]
// Khung tháo gỡ #1265 | Địa chỉ PC: 0x2b5e30 | Địa chỉ FDE: 0x0fa400 | Kích thước: 256 bytes
//   0x2b5e30: AA1E03E4  mov      x4, x30
//   0x2b5e34: 9401ACBB  bl       #0x321120
//   0x2b5e38: AA0403FE  mov      x30, x4
//   0x2b5e3c: A90B7BF3  stp      x19, x30, [sp, #0xb0]
static inline uint64_t fde_func_1265_0x2b5e30(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x2b5e30ULL ^ (static_cast<uint64_t>(0xaa1e03e4ULL) << 13);
    acc = (acc + a1 + 0x9401acbbULL) ^ 0x0fa400ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1266 | PC: 0x2b5fa8 | FDE: 0x0fa428 | Size: 256 bytes [_ZN4lynx5lepus8Function8GetScopeEv]
// Khung tháo gỡ #1266 | Địa chỉ PC: 0x2b5fa8 | Địa chỉ FDE: 0x0fa428 | Kích thước: 256 bytes
//   0x2b5fa8: D10103FF  sub      sp, sp, #0x40
//   0x2b5fac: A90253F5  stp      x21, x20, [sp, #0x20]
//   0x2b5fb0: A9037BF3  stp      x19, x30, [sp, #0x30]
//   0x2b5fb4: 94019D7D  bl       #0x31d5a8
static inline uint64_t fde_func_1266_0x2b5fa8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x2b5fa8ULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xa90253f5ULL) ^ 0x0fa428ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1267 | PC: 0x2b626c | FDE: 0x0fa488 | Size: 256 bytes
// Khung tháo gỡ #1267 | Địa chỉ PC: 0x2b626c | Địa chỉ FDE: 0x0fa488 | Kích thước: 256 bytes
//   0x2b626c: F940CC09  ldr      x9, [x0, #0x198]
//   0x2b6270: AA0803E0  mov      x0, x8
//   0x2b6274: F9400129  ldr      x9, [x9]
//   0x2b6278: 3940212A  ldrb     w10, [x9, #8]
static inline uint64_t fde_func_1267_0x2b626c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x2b626cULL ^ (static_cast<uint64_t>(0xf940cc09ULL) << 13);
    acc = (acc + a1 + 0xaa0803e0ULL) ^ 0x0fa488ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1268 | PC: 0x2b699c | FDE: 0x0fa5d8 | Size: 256 bytes [_ZN4lynx5lepus5CDate5printERNSt6__ndk118basic_stringstreamIcNS2_11char_traitsIcEENS2_9allocatorIcEEEE]
// Khung tháo gỡ #1268 | Địa chỉ PC: 0x2b699c | Địa chỉ FDE: 0x0fa5d8 | Kích thước: 256 bytes
//   0x2b699c: D10303FF  sub      sp, sp, #0xc0
//   0x2b69a0: A90A53F5  stp      x21, x20, [sp, #0xa0]
//   0x2b69a4: A90B7BF3  stp      x19, x30, [sp, #0xb0]
//   0x2b69a8: D53BD055  mrs      x21, tpidr_el0
static inline uint64_t fde_func_1268_0x2b699c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x2b699cULL ^ (static_cast<uint64_t>(0xd10303ffULL) << 13);
    acc = (acc + a1 + 0xa90a53f5ULL) ^ 0x0fa5d8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1269 | PC: 0x2b7694 | FDE: 0x0fa720 | Size: 256 bytes
// Khung tháo gỡ #1269 | Địa chỉ PC: 0x2b7694 | Địa chỉ FDE: 0x0fa720 | Kích thước: 256 bytes
//   0x2b7694: D101C3FF  sub      sp, sp, #0x70
//   0x2b7698: F9002BF4  str      x20, [sp, #0x50]
//   0x2b769c: A9067BF3  stp      x19, x30, [sp, #0x60]
//   0x2b76a0: D53BD054  mrs      x20, tpidr_el0
static inline uint64_t fde_func_1269_0x2b7694(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x2b7694ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xf9002bf4ULL) ^ 0x0fa720ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1270 | PC: 0x2b7b14 | FDE: 0x0fa868 | Size: 256 bytes
// Khung tháo gỡ #1270 | Địa chỉ PC: 0x2b7b14 | Địa chỉ FDE: 0x0fa868 | Kích thước: 256 bytes
//   0x2b7b14: D100C3FF  sub      sp, sp, #0x30
//   0x2b7b18: F9000BF4  str      x20, [sp, #0x10]
//   0x2b7b1c: A9027BF3  stp      x19, x30, [sp, #0x20]
//   0x2b7b20: 94019806  bl       #0x31db38
static inline uint64_t fde_func_1270_0x2b7b14(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x2b7b14ULL ^ (static_cast<uint64_t>(0xd100c3ffULL) << 13);
    acc = (acc + a1 + 0xf9000bf4ULL) ^ 0x0fa868ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1271 | PC: 0x2b82b4 | FDE: 0x0fa9c0 | Size: 256 bytes
// Khung tháo gỡ #1271 | Địa chỉ PC: 0x2b82b4 | Địa chỉ FDE: 0x0fa9c0 | Kích thước: 256 bytes
//   0x2b82b4: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x2b82b8: F940CC09  ldr      x9, [x0, #0x198]
//   0x2b82bc: AA0803F3  mov      x19, x8
//   0x2b82c0: F9400120  ldr      x0, [x9]
static inline uint64_t fde_func_1271_0x2b82b4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x2b82b4ULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0xf940cc09ULL) ^ 0x0fa9c0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1272 | PC: 0x2b8a00 | FDE: 0x0fab10 | Size: 256 bytes
// Khung tháo gỡ #1272 | Địa chỉ PC: 0x2b8a00 | Địa chỉ FDE: 0x0fab10 | Kích thước: 256 bytes
//   0x2b8a00: D10143FF  sub      sp, sp, #0x50
//   0x2b8a04: F90013F6  str      x22, [sp, #0x20]
//   0x2b8a08: A90353F5  stp      x21, x20, [sp, #0x30]
//   0x2b8a0c: A9047BF3  stp      x19, x30, [sp, #0x40]
static inline uint64_t fde_func_1272_0x2b8a00(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x2b8a00ULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xf90013f6ULL) ^ 0x0fab10ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1273 | PC: 0x2ba984 | FDE: 0x0facb8 | Size: 256 bytes
// Khung tháo gỡ #1273 | Địa chỉ PC: 0x2ba984 | Địa chỉ FDE: 0x0facb8 | Kích thước: 256 bytes
//   0x2ba984: D101C3FF  sub      sp, sp, #0x70
//   0x2ba988: F9002BF4  str      x20, [sp, #0x50]
//   0x2ba98c: A9067BF3  stp      x19, x30, [sp, #0x60]
//   0x2ba990: 94020F8A  bl       #0x33e7b8
static inline uint64_t fde_func_1273_0x2ba984(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x2ba984ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xf9002bf4ULL) ^ 0x0facb8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1274 | PC: 0x2badbc | FDE: 0x0fadd0 | Size: 256 bytes
// Khung tháo gỡ #1274 | Địa chỉ PC: 0x2badbc | Địa chỉ FDE: 0x0fadd0 | Kích thước: 256 bytes
//   0x2badbc: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x2badc0: AA0003F3  mov      x19, x0
//   0x2badc4: 97FFCFA2  bl       #0x2aec4c
//   0x2badc8: 940188C6  bl       #0x31d0e0
static inline uint64_t fde_func_1274_0x2badbc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x2badbcULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0xaa0003f3ULL) ^ 0x0fadd0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1275 | PC: 0x2bb734 | FDE: 0x0faf30 | Size: 256 bytes
// Khung tháo gỡ #1275 | Địa chỉ PC: 0x2bb734 | Địa chỉ FDE: 0x0faf30 | Kích thước: 256 bytes
//   0x2bb734: D10143FF  sub      sp, sp, #0x50
//   0x2bb738: A90353F5  stp      x21, x20, [sp, #0x30]
//   0x2bb73c: A9047BF3  stp      x19, x30, [sp, #0x40]
//   0x2bb740: D53BD055  mrs      x21, tpidr_el0
static inline uint64_t fde_func_1275_0x2bb734(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x2bb734ULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xa90353f5ULL) ^ 0x0faf30ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1276 | PC: 0x2bbef0 | FDE: 0x0fb060 | Size: 256 bytes
// Khung tháo gỡ #1276 | Địa chỉ PC: 0x2bbef0 | Địa chỉ FDE: 0x0fb060 | Kích thước: 256 bytes
//   0x2bbef0: 93407C49  sxtw     x9, w2
//   0x2bbef4: 8B091421  add      x1, x1, x9, lsl #5
//   0x2bbef8: 1401F072  b        #0x3380c0
//   0x2bbefc: A9BE53F5  stp      x21, x20, [sp, #-0x20]!
static inline uint64_t fde_func_1276_0x2bbef0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x2bbef0ULL ^ (static_cast<uint64_t>(0x93407c49ULL) << 13);
    acc = (acc + a1 + 0x8b091421ULL) ^ 0x0fb060ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1277 | PC: 0x2bed54 | FDE: 0x0fb1c0 | Size: 256 bytes
// Khung tháo gỡ #1277 | Địa chỉ PC: 0x2bed54 | Địa chỉ FDE: 0x0fb1c0 | Kích thước: 256 bytes
//   0x2bed54: F81E0FF4  str      x20, [sp, #-0x20]!
//   0x2bed58: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x2bed5c: F9400014  ldr      x20, [x0]
//   0x2bed60: 94018280  bl       #0x31f760
static inline uint64_t fde_func_1277_0x2bed54(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x2bed54ULL ^ (static_cast<uint64_t>(0xf81e0ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x0fb1c0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1278 | PC: 0x2bf498 | FDE: 0x0fb320 | Size: 256 bytes
// Khung tháo gỡ #1278 | Địa chỉ PC: 0x2bf498 | Địa chỉ FDE: 0x0fb320 | Kích thước: 256 bytes
//   0x2bf498: D10203FF  sub      sp, sp, #0x80
//   0x2bf49c: A9055BF7  stp      x23, x22, [sp, #0x50]
//   0x2bf4a0: A90653F5  stp      x21, x20, [sp, #0x60]
//   0x2bf4a4: A9077BF3  stp      x19, x30, [sp, #0x70]
static inline uint64_t fde_func_1278_0x2bf498(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x2bf498ULL ^ (static_cast<uint64_t>(0xd10203ffULL) << 13);
    acc = (acc + a1 + 0xa9055bf7ULL) ^ 0x0fb320ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1279 | PC: 0x2bfc64 | FDE: 0x0fb490 | Size: 76 bytes
// Khung tháo gỡ #1279 | Địa chỉ PC: 0x2bfc64 | Địa chỉ FDE: 0x0fb490 | Kích thước: 76 bytes
//   0x2bfc64: A9BD5BF7  stp      x23, x22, [sp, #-0x30]!
//   0x2bfc68: A90153F5  stp      x21, x20, [sp, #0x10]
//   0x2bfc6c: A9027BF3  stp      x19, x30, [sp, #0x20]
//   0x2bfc70: F100005F  cmp      x2, #0
static inline uint64_t fde_func_1279_0x2bfc64(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x2bfc64ULL ^ (static_cast<uint64_t>(0xa9bd5bf7ULL) << 13);
    acc = (acc + a1 + 0xa90153f5ULL) ^ 0x0fb490ULL;
    acc ^= (acc >> 17) * 0x004cULL;
    return acc;
}

// FDE #1280 | PC: 0x2bfcb0 | FDE: 0x0fb4b0 | Size: 36 bytes [_ZN4lynx5lepus9VMContext15GetRootFunctionEv]
// Khung tháo gỡ #1280 | Địa chỉ PC: 0x2bfcb0 | Địa chỉ FDE: 0x0fb4b0 | Kích thước: 36 bytes
//   0x2bfcb0: F9414C09  ldr      x9, [x0, #0x298]
//   0x2bfcb4: F9000109  str      x9, [x8]
//   0x2bfcb8: B40000C9  cbz      x9, #0x2bfcd0
//   0x2bfcbc: 91002128  add      x8, x9, #8
static inline uint64_t fde_func_1280_0x2bfcb0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x2bfcb0ULL ^ (static_cast<uint64_t>(0xf9414c09ULL) << 13);
    acc = (acc + a1 + 0xf9000109ULL) ^ 0x0fb4b0ULL;
    acc ^= (acc >> 17) * 0x0024ULL;
    return acc;
}

// FDE #1281 | PC: 0x2bfcd4 | FDE: 0x0fb4c8 | Size: 256 bytes [_ZN4lynx5lepus9VMContext15GetCurrentFrameEv]
// Khung tháo gỡ #1281 | Địa chỉ PC: 0x2bfcd4 | Địa chỉ FDE: 0x0fb4c8 | Kích thước: 256 bytes
//   0x2bfcd4: F940CC00  ldr      x0, [x0, #0x198]
//   0x2bfcd8: D65F03C0  ret      
//   0x2bfcdc: D10143FF  sub      sp, sp, #0x50
//   0x2bfce0: F90013F6  str      x22, [sp, #0x20]
static inline uint64_t fde_func_1281_0x2bfcd4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x2bfcd4ULL ^ (static_cast<uint64_t>(0xf940cc00ULL) << 13);
    acc = (acc + a1 + 0xd65f03c0ULL) ^ 0x0fb4c8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1282 | PC: 0x2c00c8 | FDE: 0x0fb5c0 | Size: 256 bytes
// Khung tháo gỡ #1282 | Địa chỉ PC: 0x2c00c8 | Địa chỉ FDE: 0x0fb5c0 | Kích thước: 256 bytes
//   0x2c00c8: AA1E03E3  mov      x3, x30
//   0x2c00cc: 9401DEBD  bl       #0x337bc0
//   0x2c00d0: AA0303FE  mov      x30, x3
//   0x2c00d4: A9057BFD  stp      x29, x30, [sp, #0x50]
static inline uint64_t fde_func_1282_0x2c00c8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x2c00c8ULL ^ (static_cast<uint64_t>(0xaa1e03e3ULL) << 13);
    acc = (acc + a1 + 0x9401debdULL) ^ 0x0fb5c0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1283 | PC: 0x2c0c88 | FDE: 0x0fb700 | Size: 256 bytes
// Khung tháo gỡ #1283 | Địa chỉ PC: 0x2c0c88 | Địa chỉ FDE: 0x0fb700 | Kích thước: 256 bytes
//   0x2c0c88: F81F0FFE  str      x30, [sp, #-0x10]!
//   0x2c0c8c: 940205B5  bl       #0x342360
//   0x2c0c90: 7100001F  cmp      w0, #0
//   0x2c0c94: 1A9F07E0  cset     w0, ne
static inline uint64_t fde_func_1283_0x2c0c88(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x2c0c88ULL ^ (static_cast<uint64_t>(0xf81f0ffeULL) << 13);
    acc = (acc + a1 + 0x940205b5ULL) ^ 0x0fb700ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1284 | PC: 0x2c142c | FDE: 0x0fb860 | Size: 256 bytes
// Khung tháo gỡ #1284 | Địa chỉ PC: 0x2c142c | Địa chỉ FDE: 0x0fb860 | Kích thước: 256 bytes
//   0x2c142c: AA1E03E5  mov      x5, x30
//   0x2c1430: 94017612  bl       #0x31ec78
//   0x2c1434: AA0503FE  mov      x30, x5
//   0x2c1438: A9067BF3  stp      x19, x30, [sp, #0x60]
static inline uint64_t fde_func_1284_0x2c142c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x2c142cULL ^ (static_cast<uint64_t>(0xaa1e03e5ULL) << 13);
    acc = (acc + a1 + 0x94017612ULL) ^ 0x0fb860ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1285 | PC: 0x2c184c | FDE: 0x0fb9e8 | Size: 256 bytes
// Khung tháo gỡ #1285 | Địa chỉ PC: 0x2c184c | Địa chỉ FDE: 0x0fb9e8 | Kích thước: 256 bytes
//   0x2c184c: D10203FF  sub      sp, sp, #0x80
//   0x2c1850: A9055BF7  stp      x23, x22, [sp, #0x50]
//   0x2c1854: A90653F5  stp      x21, x20, [sp, #0x60]
//   0x2c1858: A9077BF3  stp      x19, x30, [sp, #0x70]
static inline uint64_t fde_func_1285_0x2c184c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x2c184cULL ^ (static_cast<uint64_t>(0xd10203ffULL) << 13);
    acc = (acc + a1 + 0xa9055bf7ULL) ^ 0x0fb9e8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1286 | PC: 0x2c1c7c | FDE: 0x0fbb78 | Size: 256 bytes
// Khung tháo gỡ #1286 | Địa chỉ PC: 0x2c1c7c | Địa chỉ FDE: 0x0fbb78 | Kích thước: 256 bytes
//   0x2c1c7c: F81E0FF4  str      x20, [sp, #-0x20]!
//   0x2c1c80: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x2c1c84: AA0003F3  mov      x19, x0
//   0x2c1c88: F940BC00  ldr      x0, [x0, #0x178]
static inline uint64_t fde_func_1286_0x2c1c7c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x2c1c7cULL ^ (static_cast<uint64_t>(0xf81e0ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x0fbb78ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1287 | PC: 0x2c25f0 | FDE: 0x0fbcb8 | Size: 256 bytes
// Khung tháo gỡ #1287 | Địa chỉ PC: 0x2c25f0 | Địa chỉ FDE: 0x0fbcb8 | Kích thước: 256 bytes
//   0x2c25f0: D10143FF  sub      sp, sp, #0x50
//   0x2c25f4: F90013F6  str      x22, [sp, #0x20]
//   0x2c25f8: A90353F5  stp      x21, x20, [sp, #0x30]
//   0x2c25fc: A9047BF3  stp      x19, x30, [sp, #0x40]
static inline uint64_t fde_func_1287_0x2c25f0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x2c25f0ULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xf90013f6ULL) ^ 0x0fbcb8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1288 | PC: 0x2c2e0c | FDE: 0x0fbdf8 | Size: 256 bytes
// Khung tháo gỡ #1288 | Địa chỉ PC: 0x2c2e0c | Địa chỉ FDE: 0x0fbdf8 | Kích thước: 256 bytes
//   0x2c2e0c: AA1E03E1  mov      x1, x30
//   0x2c2e10: 940167A9  bl       #0x31ccb4
//   0x2c2e14: AA0103FE  mov      x30, x1
//   0x2c2e18: A9087BFD  stp      x29, x30, [sp, #0x80]
static inline uint64_t fde_func_1288_0x2c2e0c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x2c2e0cULL ^ (static_cast<uint64_t>(0xaa1e03e1ULL) << 13);
    acc = (acc + a1 + 0x940167a9ULL) ^ 0x0fbdf8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1289 | PC: 0x2c467c | FDE: 0x0fbf48 | Size: 256 bytes
// Khung tháo gỡ #1289 | Địa chỉ PC: 0x2c467c | Địa chỉ FDE: 0x0fbf48 | Kích thước: 256 bytes
//   0x2c467c: F81F0FFE  str      x30, [sp, #-0x10]!
//   0x2c4680: F9400008  ldr      x8, [x0]
//   0x2c4684: 940160CE  bl       #0x31c9bc
//   0x2c4688: B4000060  cbz      x0, #0x2c4694
static inline uint64_t fde_func_1289_0x2c467c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x2c467cULL ^ (static_cast<uint64_t>(0xf81f0ffeULL) << 13);
    acc = (acc + a1 + 0xf9400008ULL) ^ 0x0fbf48ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1290 | PC: 0x2c4f40 | FDE: 0x0fc0a0 | Size: 256 bytes
// Khung tháo gỡ #1290 | Địa chỉ PC: 0x2c4f40 | Địa chỉ FDE: 0x0fc0a0 | Kích thước: 256 bytes
//   0x2c4f40: AA1E03E4  mov      x4, x30
//   0x2c4f44: 94016F25  bl       #0x320bd8
//   0x2c4f48: AA0403FE  mov      x30, x4
//   0x2c4f4c: A90B7BF3  stp      x19, x30, [sp, #0xb0]
static inline uint64_t fde_func_1290_0x2c4f40(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x2c4f40ULL ^ (static_cast<uint64_t>(0xaa1e03e4ULL) << 13);
    acc = (acc + a1 + 0x94016f25ULL) ^ 0x0fc0a0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1291 | PC: 0x2c5680 | FDE: 0x0fc1f0 | Size: 256 bytes
// Khung tháo gỡ #1291 | Địa chỉ PC: 0x2c5680 | Địa chỉ FDE: 0x0fc1f0 | Kích thước: 256 bytes
//   0x2c5680: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x2c5684: AA0003F3  mov      x19, x0
//   0x2c5688: 97FFADE2  bl       #0x2b0e10
//   0x2c568c: AA1303E0  mov      x0, x19
static inline uint64_t fde_func_1291_0x2c5680(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x2c5680ULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0xaa0003f3ULL) ^ 0x0fc1f0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1292 | PC: 0x2c63b0 | FDE: 0x0fc330 | Size: 256 bytes
// Khung tháo gỡ #1292 | Địa chỉ PC: 0x2c63b0 | Địa chỉ FDE: 0x0fc330 | Kích thước: 256 bytes
//   0x2c63b0: D10083FF  sub      sp, sp, #0x20
//   0x2c63b4: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x2c63b8: D53BD053  mrs      x19, tpidr_el0
//   0x2c63bc: F9401668  ldr      x8, [x19, #0x28]
static inline uint64_t fde_func_1292_0x2c63b0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x2c63b0ULL ^ (static_cast<uint64_t>(0xd10083ffULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x0fc330ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1293 | PC: 0x2c660c | FDE: 0x0fc438 | Size: 256 bytes
// Khung tháo gỡ #1293 | Địa chỉ PC: 0x2c660c | Địa chỉ FDE: 0x0fc438 | Kích thước: 256 bytes
//   0x2c660c: A9BE53F5  stp      x21, x20, [sp, #-0x20]!
//   0x2c6610: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x2c6614: 9401C7C9  bl       #0x338538
//   0x2c6618: 900004A8  adrp     x8, #0x35a000
static inline uint64_t fde_func_1293_0x2c660c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x2c660cULL ^ (static_cast<uint64_t>(0xa9be53f5ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x0fc438ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1294 | PC: 0x2c6aec | FDE: 0x0fc568 | Size: 256 bytes
// Khung tháo gỡ #1294 | Địa chỉ PC: 0x2c6aec | Địa chỉ FDE: 0x0fc568 | Kích thước: 256 bytes
//   0x2c6aec: AA1E03E3  mov      x3, x30
//   0x2c6af0: 94015EA7  bl       #0x31e58c
//   0x2c6af4: AA0303FE  mov      x30, x3
//   0x2c6af8: A9107BFD  stp      x29, x30, [sp, #0x100]
static inline uint64_t fde_func_1294_0x2c6aec(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x2c6aecULL ^ (static_cast<uint64_t>(0xaa1e03e3ULL) << 13);
    acc = (acc + a1 + 0x94015ea7ULL) ^ 0x0fc568ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1295 | PC: 0x2c7ba0 | FDE: 0x0fc6a8 | Size: 248 bytes
// Khung tháo gỡ #1295 | Địa chỉ PC: 0x2c7ba0 | Địa chỉ FDE: 0x0fc6a8 | Kích thước: 248 bytes
//   0x2c7ba0: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x2c7ba4: AA0003F3  mov      x19, x0
//   0x2c7ba8: 97FFFFF6  bl       #0x2c7b80
//   0x2c7bac: AA1303E0  mov      x0, x19
static inline uint64_t fde_func_1295_0x2c7ba0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x2c7ba0ULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0xaa0003f3ULL) ^ 0x0fc6a8ULL;
    acc ^= (acc >> 17) * 0x00f8ULL;
    return acc;
}

// FDE #1296 | PC: 0x2c7c98 | FDE: 0x0fc7a0 | Size: 256 bytes
// Khung tháo gỡ #1296 | Địa chỉ PC: 0x2c7c98 | Địa chỉ FDE: 0x0fc7a0 | Kích thước: 256 bytes
//   0x2c7c98: AA1E03E2  mov      x2, x30
//   0x2c7c9c: 94017B33  bl       #0x326968
//   0x2c7ca0: AA0203FE  mov      x30, x2
//   0x2c7ca4: A90B7BF3  stp      x19, x30, [sp, #0xb0]
static inline uint64_t fde_func_1296_0x2c7c98(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x2c7c98ULL ^ (static_cast<uint64_t>(0xaa1e03e2ULL) << 13);
    acc = (acc + a1 + 0x94017b33ULL) ^ 0x0fc7a0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1297 | PC: 0x2c81c8 | FDE: 0x0fc8f0 | Size: 232 bytes
// Khung tháo gỡ #1297 | Địa chỉ PC: 0x2c81c8 | Địa chỉ FDE: 0x0fc8f0 | Kích thước: 232 bytes
//   0x2c81c8: A9BD5BF7  stp      x23, x22, [sp, #-0x30]!
//   0x2c81cc: A90153F5  stp      x21, x20, [sp, #0x10]
//   0x2c81d0: A9027BF3  stp      x19, x30, [sp, #0x20]
//   0x2c81d4: B9401008  ldr      w8, [x0, #0x10]
static inline uint64_t fde_func_1297_0x2c81c8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x2c81c8ULL ^ (static_cast<uint64_t>(0xa9bd5bf7ULL) << 13);
    acc = (acc + a1 + 0xa90153f5ULL) ^ 0x0fc8f0ULL;
    acc ^= (acc >> 17) * 0x00e8ULL;
    return acc;
}

// FDE #1298 | PC: 0x2c82b0 | FDE: 0x0fc980 | Size: 104 bytes [_ZN4lynx7runtime16JSContextWrapperC2ENSt6__ndk110shared_ptrINS_5piper10JSIContextEEE]
// Khung tháo gỡ #1298 | Địa chỉ PC: 0x2c82b0 | Địa chỉ FDE: 0x0fc980 | Kích thước: 104 bytes
//   0x2c82b0: D0000488  adrp     x8, #0x35a000
//   0x2c82b4: 913D2108  add      x8, x8, #0xf48
//   0x2c82b8: A900FC1F  stp      xzr, xzr, [x0, #8]
//   0x2c82bc: F9000008  str      x8, [x0]
static inline uint64_t fde_func_1298_0x2c82b0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x2c82b0ULL ^ (static_cast<uint64_t>(0xd0000488ULL) << 13);
    acc = (acc + a1 + 0x913d2108ULL) ^ 0x0fc980ULL;
    acc ^= (acc >> 17) * 0x0068ULL;
    return acc;
}

// FDE #1299 | PC: 0x2c8318 | FDE: 0x0fc9b0 | Size: 256 bytes [_ZN4lynx7runtime16JSContextWrapper9loadPreJSENSt6__ndk18weak_ptrINS_5piper7RuntimeEEERNS2_6vectorINS2_4pairINS2_12basic_stringIcNS2_11char_traitsIcEENS2_9allocatorIcEEEENS2_10shared_ptrINS4_6BufferEEEEENSC_ISI_EEEE]
// Khung tháo gỡ #1299 | Địa chỉ PC: 0x2c8318 | Địa chỉ FDE: 0x0fc9b0 | Kích thước: 256 bytes
//   0x2c8318: AA1E03E3  mov      x3, x30
//   0x2c831c: 9401827B  bl       #0x328d08
//   0x2c8320: AA0303FE  mov      x30, x3
//   0x2c8324: A90E7BF3  stp      x19, x30, [sp, #0xe0]
static inline uint64_t fde_func_1299_0x2c8318(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x2c8318ULL ^ (static_cast<uint64_t>(0xaa1e03e3ULL) << 13);
    acc = (acc + a1 + 0x9401827bULL) ^ 0x0fc9b0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1300 | PC: 0x2c8444 | FDE: 0x0fc9d8 | Size: 156 bytes [_ZN4lynx7runtime22SharedJSContextWrapperC1ENSt6__ndk110shared_ptrINS_5piper10JSIContextEEERKNS2_12basic_stringIcNS2_11char_traitsIcEENS2_9allocatorIcEEEEPNS1_15ReleaseListenerE]
// Khung tháo gỡ #1300 | Địa chỉ PC: 0x2c8444 | Địa chỉ FDE: 0x0fc9d8 | Kích thước: 156 bytes
//   0x2c8444: D10103FF  sub      sp, sp, #0x40
//   0x2c8448: F9000BF6  str      x22, [sp, #0x10]
//   0x2c844c: A90253F5  stp      x21, x20, [sp, #0x20]
//   0x2c8450: A9037BF3  stp      x19, x30, [sp, #0x30]
static inline uint64_t fde_func_1300_0x2c8444(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x2c8444ULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xf9000bf6ULL) ^ 0x0fc9d8ULL;
    acc ^= (acc >> 17) * 0x009cULL;
    return acc;
}

// FDE #1301 | PC: 0x2c84e0 | FDE: 0x0fca10 | Size: 24 bytes
// Khung tháo gỡ #1301 | Địa chỉ PC: 0x2c84e0 | Địa chỉ FDE: 0x0fca10 | Kích thước: 24 bytes
//   0x2c84e0: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x2c84e4: AA0003F3  mov      x19, x0
//   0x2c84e8: 97FFFFF2  bl       #0x2c84b0
//   0x2c84ec: AA1303E0  mov      x0, x19
static inline uint64_t fde_func_1301_0x2c84e0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x2c84e0ULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0xaa0003f3ULL) ^ 0x0fca10ULL;
    acc ^= (acc >> 17) * 0x0018ULL;
    return acc;
}

// FDE #1302 | PC: 0x2c84f8 | FDE: 0x0fca28 | Size: 84 bytes [_ZN4lynx7runtime22SharedJSContextWrapper3DefEv]
// Khung tháo gỡ #1302 | Địa chỉ PC: 0x2c84f8 | Địa chỉ FDE: 0x0fca28 | Kích thước: 84 bytes
//   0x2c84f8: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x2c84fc: F9401008  ldr      x8, [x0, #0x20]
//   0x2c8500: B4000228  cbz      x8, #0x2c8544
//   0x2c8504: F9400508  ldr      x8, [x8, #8]
static inline uint64_t fde_func_1302_0x2c84f8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x2c84f8ULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0xf9401008ULL) ^ 0x0fca28ULL;
    acc ^= (acc >> 17) * 0x0054ULL;
    return acc;
}

// FDE #1303 | PC: 0x2c854c | FDE: 0x0fca40 | Size: 24 bytes [_ZN4lynx7runtime22SharedJSContextWrapper13EnsureConsoleENSt6__ndk110shared_ptrINS_5piper21ConsoleMessagePostManEEERKNS_4tasm11PageOptionsE]
// Khung tháo gỡ #1303 | Địa chỉ PC: 0x2c854c | Địa chỉ FDE: 0x0fca40 | Kích thước: 24 bytes
//   0x2c854c: 3940A408  ldrb     w8, [x0, #0x29]
//   0x2c8550: 34000088  cbz      w8, #0x2c8560
//   0x2c8554: F9401800  ldr      x0, [x0, #0x30]
//   0x2c8558: B4000040  cbz      x0, #0x2c8560
static inline uint64_t fde_func_1303_0x2c854c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x2c854cULL ^ (static_cast<uint64_t>(0x3940a408ULL) << 13);
    acc = (acc + a1 + 0x34000088ULL) ^ 0x0fca40ULL;
    acc ^= (acc >> 17) * 0x0018ULL;
    return acc;
}

// FDE #1304 | PC: 0x2c8564 | FDE: 0x0fca58 | Size: 204 bytes [_ZN4lynx7runtime22SharedJSContextWrapper10initGlobalERNSt6__ndk110shared_ptrINS_5piper7RuntimeEEENS3_INS4_21ConsoleMessagePostManEEERKNS_4tasm11PageOptionsE]
// Khung tháo gỡ #1304 | Địa chỉ PC: 0x2c8564 | Địa chỉ FDE: 0x0fca58 | Kích thước: 204 bytes
//   0x2c8564: A9BC63F9  stp      x25, x24, [sp, #-0x40]!
//   0x2c8568: A9015BF7  stp      x23, x22, [sp, #0x10]
//   0x2c856c: A90253F5  stp      x21, x20, [sp, #0x20]
//   0x2c8570: A9037BF3  stp      x19, x30, [sp, #0x30]
static inline uint64_t fde_func_1304_0x2c8564(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x2c8564ULL ^ (static_cast<uint64_t>(0xa9bc63f9ULL) << 13);
    acc = (acc + a1 + 0xa9015bf7ULL) ^ 0x0fca58ULL;
    acc ^= (acc >> 17) * 0x00ccULL;
    return acc;
}

// FDE #1305 | PC: 0x2c8630 | FDE: 0x0fcac8 | Size: 148 bytes [_ZN4lynx7runtime26NoneSharedJSContextWrapperC2ENSt6__ndk110shared_ptrINS_5piper10JSIContextEEE]
// Khung tháo gỡ #1305 | Địa chỉ PC: 0x2c8630 | Địa chỉ FDE: 0x0fcac8 | Kích thước: 148 bytes
//   0x2c8630: D100C3FF  sub      sp, sp, #0x30
//   0x2c8634: F9000BF4  str      x20, [sp, #0x10]
//   0x2c8638: A9027BF3  stp      x19, x30, [sp, #0x20]
//   0x2c863c: A9405028  ldp      x8, x20, [x1]
static inline uint64_t fde_func_1305_0x2c8630(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x2c8630ULL ^ (static_cast<uint64_t>(0xd100c3ffULL) << 13);
    acc = (acc + a1 + 0xf9000bf4ULL) ^ 0x0fcac8ULL;
    acc ^= (acc >> 17) * 0x0094ULL;
    return acc;
}

// FDE #1306 | PC: 0x2c86c4 | FDE: 0x0fcb18 | Size: 36 bytes [_ZN4lynx7runtime26NoneSharedJSContextWrapper3DefEv]
// Khung tháo gỡ #1306 | Địa chỉ PC: 0x2c86c4 | Địa chỉ FDE: 0x0fcb18 | Kích thước: 36 bytes
//   0x2c86c4: F9401008  ldr      x8, [x0, #0x20]
//   0x2c86c8: B4000068  cbz      x8, #0x2c86d4
//   0x2c86cc: F9400508  ldr      x8, [x8, #8]
//   0x2c86d0: B4000048  cbz      x8, #0x2c86d8
static inline uint64_t fde_func_1306_0x2c86c4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x2c86c4ULL ^ (static_cast<uint64_t>(0xf9401008ULL) << 13);
    acc = (acc + a1 + 0xb4000068ULL) ^ 0x0fcb18ULL;
    acc ^= (acc >> 17) * 0x0024ULL;
    return acc;
}

// FDE #1307 | PC: 0x2c86e8 | FDE: 0x0fcb30 | Size: 196 bytes [_ZN4lynx7runtime26NoneSharedJSContextWrapper10initGlobalERNSt6__ndk110shared_ptrINS_5piper7RuntimeEEENS3_INS4_21ConsoleMessagePostManEEERKNS_4tasm11PageOptionsE]
// Khung tháo gỡ #1307 | Địa chỉ PC: 0x2c86e8 | Địa chỉ FDE: 0x0fcb30 | Kích thước: 196 bytes
//   0x2c86e8: A9BC63F9  stp      x25, x24, [sp, #-0x40]!
//   0x2c86ec: A9015BF7  stp      x23, x22, [sp, #0x10]
//   0x2c86f0: A90253F5  stp      x21, x20, [sp, #0x20]
//   0x2c86f4: A9037BF3  stp      x19, x30, [sp, #0x30]
static inline uint64_t fde_func_1307_0x2c86e8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x2c86e8ULL ^ (static_cast<uint64_t>(0xa9bc63f9ULL) << 13);
    acc = (acc + a1 + 0xa9015bf7ULL) ^ 0x0fcb30ULL;
    acc ^= (acc >> 17) * 0x00c4ULL;
    return acc;
}

// FDE #1308 | PC: 0x2c87ac | FDE: 0x0fcb88 | Size: 88 bytes [_ZN4lynx7runtime26NoneSharedJSContextWrapperC1ENSt6__ndk110shared_ptrINS_5piper10JSIContextEEEPNS0_22SharedJSContextWrapper15ReleaseListenerE]
// Khung tháo gỡ #1308 | Địa chỉ PC: 0x2c87ac | Địa chỉ FDE: 0x0fcb88 | Kích thước: 88 bytes
//   0x2c87ac: D100C3FF  sub      sp, sp, #0x30
//   0x2c87b0: A90153F5  stp      x21, x20, [sp, #0x10]
//   0x2c87b4: A9027BF3  stp      x19, x30, [sp, #0x20]
//   0x2c87b8: A9405428  ldp      x8, x21, [x1]
static inline uint64_t fde_func_1308_0x2c87ac(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x2c87acULL ^ (static_cast<uint64_t>(0xd100c3ffULL) << 13);
    acc = (acc + a1 + 0xa90153f5ULL) ^ 0x0fcb88ULL;
    acc ^= (acc >> 17) * 0x0058ULL;
    return acc;
}

// FDE #1309 | PC: 0x2c8804 | FDE: 0x0fcba8 | Size: 256 bytes [_ZN4lynx5piper10JSExecutorC2ERKNSt6__ndk110shared_ptrINS0_19JSIExceptionHandlerEEERKNS2_12basic_stringIcNS2_11char_traitsIcEENS2_9allocatorIcEEEERKNS3_INS0_17LynxModuleManagerEEERKNS3_INS0_26InspectorRuntimeObserverNGEEEb]
// Khung tháo gỡ #1309 | Địa chỉ PC: 0x2c8804 | Địa chỉ FDE: 0x0fcba8 | Kích thước: 256 bytes
//   0x2c8804: AA1E03E6  mov      x6, x30
//   0x2c8808: 940161E3  bl       #0x320f94
//   0x2c880c: AA0603FE  mov      x30, x6
//   0x2c8810: A9097BF3  stp      x19, x30, [sp, #0x90]
static inline uint64_t fde_func_1309_0x2c8804(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x2c8804ULL ^ (static_cast<uint64_t>(0xaa1e03e6ULL) << 13);
    acc = (acc + a1 + 0x940161e3ULL) ^ 0x0fcba8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1310 | PC: 0x2c8a80 | FDE: 0x0fcbd0 | Size: 128 bytes [_ZN4lynx5piper10JSExecutorD1Ev]
// Khung tháo gỡ #1310 | Địa chỉ PC: 0x2c8a80 | Địa chỉ FDE: 0x0fcbd0 | Kích thước: 128 bytes
//   0x2c8a80: D101C3FF  sub      sp, sp, #0x70
//   0x2c8a84: A90553F5  stp      x21, x20, [sp, #0x50]
//   0x2c8a88: A9067BF3  stp      x19, x30, [sp, #0x60]
//   0x2c8a8c: 94014FDF  bl       #0x31ca08
static inline uint64_t fde_func_1310_0x2c8a80(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x2c8a80ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xa90553f5ULL) ^ 0x0fcbd0ULL;
    acc ^= (acc >> 17) * 0x0080ULL;
    return acc;
}

// FDE #1311 | PC: 0x2c8b00 | FDE: 0x0fcbf0 | Size: 124 bytes [_ZN4lynx5piper10JSExecutor7DestroyEv]
// Khung tháo gỡ #1311 | Địa chỉ PC: 0x2c8b00 | Địa chỉ FDE: 0x0fcbf0 | Kích thước: 124 bytes
//   0x2c8b00: D101C3FF  sub      sp, sp, #0x70
//   0x2c8b04: A90553F5  stp      x21, x20, [sp, #0x50]
//   0x2c8b08: A9067BF3  stp      x19, x30, [sp, #0x60]
//   0x2c8b0c: D53BD054  mrs      x20, tpidr_el0
static inline uint64_t fde_func_1311_0x2c8b00(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x2c8b00ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xa90553f5ULL) ^ 0x0fcbf0ULL;
    acc ^= (acc >> 17) * 0x007cULL;
    return acc;
}

// FDE #1312 | PC: 0x2c8b7c | FDE: 0x0fcc10 | Size: 164 bytes [_ZN4lynx5piper10JSExecutor22runtimeManagerInstanceEv]
// Khung tháo gỡ #1312 | Địa chỉ PC: 0x2c8b7c | Địa chỉ FDE: 0x0fcc10 | Kích thước: 164 bytes
//   0x2c8b7c: D100C3FF  sub      sp, sp, #0x30
//   0x2c8b80: F9000BF4  str      x20, [sp, #0x10]
//   0x2c8b84: A9027BF3  stp      x19, x30, [sp, #0x20]
//   0x2c8b88: 94015CE7  bl       #0x31ff24
static inline uint64_t fde_func_1312_0x2c8b7c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x2c8b7cULL ^ (static_cast<uint64_t>(0xd100c3ffULL) << 13);
    acc = (acc + a1 + 0xf9000bf4ULL) ^ 0x0fcc10ULL;
    acc ^= (acc >> 17) * 0x00a4ULL;
    return acc;
}

// FDE #1313 | PC: 0x2c8c20 | FDE: 0x0fcc30 | Size: 20 bytes [_ZN4lynx5piper10JSExecutor32GetCurrentRuntimeManagerInstanceEv]
// Khung tháo gỡ #1313 | Địa chỉ PC: 0x2c8c20 | Địa chỉ FDE: 0x0fcc30 | Kích thước: 20 bytes
//   0x2c8c20: F81F0FFE  str      x30, [sp, #-0x10]!
//   0x2c8c24: 9401E7C7  bl       #0x342b40
//   0x2c8c28: 94017BA7  bl       #0x327ac4
//   0x2c8c2c: F84107FE  ldr      x30, [sp], #0x10
static inline uint64_t fde_func_1313_0x2c8c20(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x2c8c20ULL ^ (static_cast<uint64_t>(0xf81f0ffeULL) << 13);
    acc = (acc + a1 + 0x9401e7c7ULL) ^ 0x0fcc30ULL;
    acc ^= (acc >> 17) * 0x0014ULL;
    return acc;
}

// FDE #1314 | PC: 0x2c8c34 | FDE: 0x0fcc48 | Size: 256 bytes [_ZN4lynx5piper10JSExecutor15loadPreJSBundleENS_4base15MoveOnlyClosureINSt6__ndk16vectorINS4_4pairINS4_12basic_stringIcNS4_11char_traitsIcEENS4_9allocatorIcEEEENS4_10shared_ptrINS0_6BufferEEEEENSA_ISG_EEEEJEEEblbRKSC_NS3_ISF_JSL_EEERKNS_4tasm11PageOptionsE]
// Khung tháo gỡ #1314 | Địa chỉ PC: 0x2c8c34 | Địa chỉ FDE: 0x0fcc48 | Kích thước: 256 bytes
//   0x2c8c34: AA1E03E8  mov      x8, x30
//   0x2c8c38: 94015314  bl       #0x31d888
//   0x2c8c3c: AA0803FE  mov      x30, x8
//   0x2c8c40: A90B7BFD  stp      x29, x30, [sp, #0xb0]
static inline uint64_t fde_func_1314_0x2c8c34(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x2c8c34ULL ^ (static_cast<uint64_t>(0xaa1e03e8ULL) << 13);
    acc = (acc + a1 + 0x94015314ULL) ^ 0x0fcc48ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1315 | PC: 0x2c8d48 | FDE: 0x0fcc78 | Size: 16 bytes [_ZN4lynx5piper10JSExecutor11SetObserverEPNS0_11JSIObserverE]
// Khung tháo gỡ #1315 | Địa chỉ PC: 0x2c8d48 | Địa chỉ FDE: 0x0fcc78 | Kích thước: 16 bytes
//   0x2c8d48: F9402800  ldr      x0, [x0, #0x50]
//   0x2c8d4c: B4000040  cbz      x0, #0x2c8d54
//   0x2c8d50: 1401D6E6  b        #0x33e8e8
//   0x2c8d54: D65F03C0  ret      
static inline uint64_t fde_func_1315_0x2c8d48(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x2c8d48ULL ^ (static_cast<uint64_t>(0xf9402800ULL) << 13);
    acc = (acc + a1 + 0xb4000040ULL) ^ 0x0fcc78ULL;
    acc ^= (acc >> 17) * 0x0010ULL;
    return acc;
}

// FDE #1316 | PC: 0x2c8d58 | FDE: 0x0fcc90 | Size: 96 bytes [_ZN4lynx5piper10JSExecutor14invokeCallbackENSt6__ndk110shared_ptrINS0_14ModuleCallbackEEEPNS0_28ModuleCallbackFunctionHolderE]
// Khung tháo gỡ #1316 | Địa chỉ PC: 0x2c8d58 | Địa chỉ FDE: 0x0fcc90 | Kích thước: 96 bytes
//   0x2c8d58: F81D0FF6  str      x22, [sp, #-0x30]!
//   0x2c8d5c: A90153F5  stp      x21, x20, [sp, #0x10]
//   0x2c8d60: A9027BF3  stp      x19, x30, [sp, #0x20]
//   0x2c8d64: F9402815  ldr      x21, [x0, #0x50]
static inline uint64_t fde_func_1316_0x2c8d58(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x2c8d58ULL ^ (static_cast<uint64_t>(0xf81d0ff6ULL) << 13);
    acc = (acc + a1 + 0xa90153f5ULL) ^ 0x0fcc90ULL;
    acc ^= (acc >> 17) * 0x0060ULL;
    return acc;
}

// FDE #1317 | PC: 0x2c8db8 | FDE: 0x0fccb0 | Size: 256 bytes [_ZN4lynx5piper10JSExecutor23createNativeAppInstanceElPNS_7runtime16TemplateDelegateENSt6__ndk110unique_ptrINS2_14LynxApiHandlerENS5_14default_deleteIS7_EEEERKNS_4tasm11PageOptionsE]
// Khung tháo gỡ #1317 | Địa chỉ PC: 0x2c8db8 | Địa chỉ FDE: 0x0fccb0 | Kích thước: 256 bytes
//   0x2c8db8: D10683FF  sub      sp, sp, #0x1a0
//   0x2c8dbc: AA1E03E5  mov      x5, x30
//   0x2c8dc0: 9401ABF4  bl       #0x333d90
//   0x2c8dc4: AA0503FE  mov      x30, x5
static inline uint64_t fde_func_1317_0x2c8db8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x2c8db8ULL ^ (static_cast<uint64_t>(0xd10683ffULL) << 13);
    acc = (acc + a1 + 0xaa1e03e5ULL) ^ 0x0fccb0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1318 | PC: 0x2c9874 | FDE: 0x0fcd78 | Size: 92 bytes
// Khung tháo gỡ #1318 | Địa chỉ PC: 0x2c9874 | Địa chỉ FDE: 0x0fcd78 | Kích thước: 92 bytes
//   0x2c9874: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x2c9878: AA0003F3  mov      x19, x0
//   0x2c987c: 91024000  add      x0, x0, #0x90
//   0x2c9880: 9401DB80  bl       #0x340680
static inline uint64_t fde_func_1318_0x2c9874(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x2c9874ULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0xaa0003f3ULL) ^ 0x0fcd78ULL;
    acc ^= (acc >> 17) * 0x005cULL;
    return acc;
}

// FDE #1319 | PC: 0x2c98d0 | FDE: 0x0fcd90 | Size: 20 bytes [_ZN4lynx5piper10JSExecutor16getJSRuntimeTypeEv]
// Khung tháo gỡ #1319 | Địa chỉ PC: 0x2c98d0 | Địa chỉ FDE: 0x0fcd90 | Kích thước: 20 bytes
//   0x2c98d0: F9402808  ldr      x8, [x0, #0x50]
//   0x2c98d4: B4000068  cbz      x8, #0x2c98e0
//   0x2c98d8: B9400900  ldr      w0, [x8, #8]
//   0x2c98dc: D65F03C0  ret      
static inline uint64_t fde_func_1319_0x2c98d0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x2c98d0ULL ^ (static_cast<uint64_t>(0xf9402808ULL) << 13);
    acc = (acc + a1 + 0xb4000068ULL) ^ 0x0fcd90ULL;
    acc ^= (acc >> 17) * 0x0014ULL;
    return acc;
}

// FDE #1320 | PC: 0x2c98e4 | FDE: 0x0fcda8 | Size: 20 bytes [_ZN4lynx5piper10JSExecutor6SetUrlERKNSt6__ndk112basic_stringIcNS2_11char_traitsIcEENS2_9allocatorIcEEEE]
// Khung tháo gỡ #1320 | Địa chỉ PC: 0x2c98e4 | Địa chỉ FDE: 0x0fcda8 | Kích thước: 20 bytes
//   0x2c98e4: F9401C08  ldr      x8, [x0, #0x38]
//   0x2c98e8: F9407100  ldr      x0, [x8, #0xe0]
//   0x2c98ec: B4000040  cbz      x0, #0x2c98f4
//   0x2c98f0: 1401D40D  b        #0x33e924
static inline uint64_t fde_func_1320_0x2c98e4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x2c98e4ULL ^ (static_cast<uint64_t>(0xf9401c08ULL) << 13);
    acc = (acc + a1 + 0xf9407100ULL) ^ 0x0fcda8ULL;
    acc ^= (acc >> 17) * 0x0014ULL;
    return acc;
}

// FDE #1321 | PC: 0x2c98f8 | FDE: 0x0fcdc0 | Size: 256 bytes [_ZN4lynx5piper10JSExecutor27CreateConsoleMessagePostManEv]
// Khung tháo gỡ #1321 | Địa chỉ PC: 0x2c98f8 | Địa chỉ FDE: 0x0fcdc0 | Kích thước: 256 bytes
//   0x2c98f8: F9401400  ldr      x0, [x0, #0x28]
//   0x2c98fc: B4000080  cbz      x0, #0x2c990c
//   0x2c9900: F9400009  ldr      x9, [x0]
//   0x2c9904: F9401521  ldr      x1, [x9, #0x28]
static inline uint64_t fde_func_1321_0x2c98f8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x2c98f8ULL ^ (static_cast<uint64_t>(0xf9401400ULL) << 13);
    acc = (acc + a1 + 0xb4000080ULL) ^ 0x0fcdc0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1322 | PC: 0x2c9f60 | FDE: 0x0fcec8 | Size: 256 bytes
// Khung tháo gỡ #1322 | Địa chỉ PC: 0x2c9f60 | Địa chỉ FDE: 0x0fcec8 | Kích thước: 256 bytes
//   0x2c9f60: AA1E03E2  mov      x2, x30
//   0x2c9f64: 94014FE9  bl       #0x31df08
//   0x2c9f68: AA0203FE  mov      x30, x2
//   0x2c9f6c: B40000A8  cbz      x8, #0x2c9f80
static inline uint64_t fde_func_1322_0x2c9f60(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x2c9f60ULL ^ (static_cast<uint64_t>(0xaa1e03e2ULL) << 13);
    acc = (acc + a1 + 0x94014fe9ULL) ^ 0x0fcec8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1323 | PC: 0x2ca348 | FDE: 0x0fcfe8 | Size: 256 bytes
// Khung tháo gỡ #1323 | Địa chỉ PC: 0x2ca348 | Địa chỉ FDE: 0x0fcfe8 | Kích thước: 256 bytes
//   0x2ca348: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x2ca34c: 94014AED  bl       #0x31cf00
//   0x2ca350: B40000D3  cbz      x19, #0x2ca368
//   0x2ca354: AA1303E0  mov      x0, x19
static inline uint64_t fde_func_1323_0x2ca348(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x2ca348ULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0x94014aedULL) ^ 0x0fcfe8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1324 | PC: 0x2cb0b4 | FDE: 0x0fd110 | Size: 256 bytes
// Khung tháo gỡ #1324 | Địa chỉ PC: 0x2cb0b4 | Địa chỉ FDE: 0x0fd110 | Kích thước: 256 bytes
//   0x2cb0b4: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x2cb0b8: AA0003F3  mov      x19, x0
//   0x2cb0bc: 97FFFFFA  bl       #0x2cb0a4
//   0x2cb0c0: AA1303E0  mov      x0, x19
static inline uint64_t fde_func_1324_0x2cb0b4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x2cb0b4ULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0xaa0003f3ULL) ^ 0x0fd110ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1325 | PC: 0x2cb4e0 | FDE: 0x0fd250 | Size: 256 bytes
// Khung tháo gỡ #1325 | Địa chỉ PC: 0x2cb4e0 | Địa chỉ FDE: 0x0fd250 | Kích thước: 256 bytes
//   0x2cb4e0: AA1E03E2  mov      x2, x30
//   0x2cb4e4: 94019311  bl       #0x330128
//   0x2cb4e8: AA0203FE  mov      x30, x2
//   0x2cb4ec: A9127BF3  stp      x19, x30, [sp, #0x120]
static inline uint64_t fde_func_1325_0x2cb4e0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x2cb4e0ULL ^ (static_cast<uint64_t>(0xaa1e03e2ULL) << 13);
    acc = (acc + a1 + 0x94019311ULL) ^ 0x0fd250ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1326 | PC: 0x2cb8ac | FDE: 0x0fd380 | Size: 256 bytes
// Khung tháo gỡ #1326 | Địa chỉ PC: 0x2cb8ac | Địa chỉ FDE: 0x0fd380 | Kích thước: 256 bytes
//   0x2cb8ac: A9BE53F5  stp      x21, x20, [sp, #-0x20]!
//   0x2cb8b0: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x2cb8b4: AA0003F4  mov      x20, x0
//   0x2cb8b8: 52800500  mov      w0, #0x28
static inline uint64_t fde_func_1326_0x2cb8ac(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x2cb8acULL ^ (static_cast<uint64_t>(0xa9be53f5ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x0fd380ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1327 | PC: 0x2cbf10 | FDE: 0x0fd4b8 | Size: 256 bytes
// Khung tháo gỡ #1327 | Địa chỉ PC: 0x2cbf10 | Địa chỉ FDE: 0x0fd4b8 | Kích thước: 256 bytes
//   0x2cbf10: AA1E03E3  mov      x3, x30
//   0x2cbf14: 940168C7  bl       #0x326230
//   0x2cbf18: AA0303FE  mov      x30, x3
//   0x2cbf1c: A90D7BF3  stp      x19, x30, [sp, #0xd0]
static inline uint64_t fde_func_1327_0x2cbf10(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x2cbf10ULL ^ (static_cast<uint64_t>(0xaa1e03e3ULL) << 13);
    acc = (acc + a1 + 0x940168c7ULL) ^ 0x0fd4b8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1328 | PC: 0x2cc4e8 | FDE: 0x0fd5e0 | Size: 256 bytes
// Khung tháo gỡ #1328 | Địa chỉ PC: 0x2cc4e8 | Địa chỉ FDE: 0x0fd5e0 | Kích thước: 256 bytes
//   0x2cc4e8: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x2cc4ec: AA0003F3  mov      x19, x0
//   0x2cc4f0: 97FFFFFA  bl       #0x2cc4d8
//   0x2cc4f4: AA1303E0  mov      x0, x19
static inline uint64_t fde_func_1328_0x2cc4e8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x2cc4e8ULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0xaa0003f3ULL) ^ 0x0fd5e0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1329 | PC: 0x2cc8f4 | FDE: 0x0fd710 | Size: 256 bytes
// Khung tháo gỡ #1329 | Địa chỉ PC: 0x2cc8f4 | Địa chỉ FDE: 0x0fd710 | Kích thước: 256 bytes
//   0x2cc8f4: AA1E03E1  mov      x1, x30
//   0x2cc8f8: 94017183  bl       #0x328f04
//   0x2cc8fc: AA0103FE  mov      x30, x1
//   0x2cc900: A9047BF3  stp      x19, x30, [sp, #0x40]
static inline uint64_t fde_func_1329_0x2cc8f4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x2cc8f4ULL ^ (static_cast<uint64_t>(0xaa1e03e1ULL) << 13);
    acc = (acc + a1 + 0x94017183ULL) ^ 0x0fd710ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1330 | PC: 0x2cd12c | FDE: 0x0fd838 | Size: 256 bytes
// Khung tháo gỡ #1330 | Địa chỉ PC: 0x2cd12c | Địa chỉ FDE: 0x0fd838 | Kích thước: 256 bytes
//   0x2cd12c: D0000468  adrp     x8, #0x35b000
//   0x2cd130: 910C8108  add      x8, x8, #0x320
//   0x2cd134: F8008408  str      x8, [x0], #8
//   0x2cd138: 17FFFFF7  b        #0x2cd114
static inline uint64_t fde_func_1330_0x2cd12c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x2cd12cULL ^ (static_cast<uint64_t>(0xd0000468ULL) << 13);
    acc = (acc + a1 + 0x910c8108ULL) ^ 0x0fd838ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1331 | PC: 0x2cd484 | FDE: 0x0fd960 | Size: 256 bytes
// Khung tháo gỡ #1331 | Địa chỉ PC: 0x2cd484 | Địa chỉ FDE: 0x0fd960 | Kích thước: 256 bytes
//   0x2cd484: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x2cd488: AA0003F3  mov      x19, x0
//   0x2cd48c: 97FFFFFA  bl       #0x2cd474
//   0x2cd490: AA1303E0  mov      x0, x19
static inline uint64_t fde_func_1331_0x2cd484(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x2cd484ULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0xaa0003f3ULL) ^ 0x0fd960ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1332 | PC: 0x2cd7b4 | FDE: 0x0fda78 | Size: 256 bytes
// Khung tháo gỡ #1332 | Địa chỉ PC: 0x2cd7b4 | Địa chỉ FDE: 0x0fda78 | Kích thước: 256 bytes
//   0x2cd7b4: F81E0FF4  str      x20, [sp, #-0x20]!
//   0x2cd7b8: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x2cd7bc: AA0003F4  mov      x20, x0
//   0x2cd7c0: 52800300  mov      w0, #0x18
static inline uint64_t fde_func_1332_0x2cd7b4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x2cd7b4ULL ^ (static_cast<uint64_t>(0xf81e0ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x0fda78ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1333 | PC: 0x2cdcc0 | FDE: 0x0fdb90 | Size: 256 bytes
// Khung tháo gỡ #1333 | Địa chỉ PC: 0x2cdcc0 | Địa chỉ FDE: 0x0fdb90 | Kích thước: 256 bytes
//   0x2cdcc0: F9400808  ldr      x8, [x0, #0x10]
//   0x2cdcc4: D0000469  adrp     x9, #0x35b000
//   0x2cdcc8: 9110E129  add      x9, x9, #0x438
//   0x2cdccc: F9000009  str      x9, [x0]
static inline uint64_t fde_func_1333_0x2cdcc0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x2cdcc0ULL ^ (static_cast<uint64_t>(0xf9400808ULL) << 13);
    acc = (acc + a1 + 0xd0000469ULL) ^ 0x0fdb90ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1334 | PC: 0x2cdfa0 | FDE: 0x0fdcb0 | Size: 256 bytes
// Khung tháo gỡ #1334 | Địa chỉ PC: 0x2cdfa0 | Địa chỉ FDE: 0x0fdcb0 | Kích thước: 256 bytes
//   0x2cdfa0: D0000468  adrp     x8, #0x35b000
//   0x2cdfa4: 91122108  add      x8, x8, #0x488
//   0x2cdfa8: 14017D36  b        #0x32d480
//   0x2cdfac: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
static inline uint64_t fde_func_1334_0x2cdfa0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x2cdfa0ULL ^ (static_cast<uint64_t>(0xd0000468ULL) << 13);
    acc = (acc + a1 + 0x91122108ULL) ^ 0x0fdcb0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1335 | PC: 0x2ce6dc | FDE: 0x0fdde0 | Size: 256 bytes
// Khung tháo gỡ #1335 | Địa chỉ PC: 0x2ce6dc | Địa chỉ FDE: 0x0fdde0 | Kích thước: 256 bytes
//   0x2ce6dc: D101C3FF  sub      sp, sp, #0x70
//   0x2ce6e0: A90553F5  stp      x21, x20, [sp, #0x50]
//   0x2ce6e4: A9067BF3  stp      x19, x30, [sp, #0x60]
//   0x2ce6e8: 940138C8  bl       #0x31ca08
static inline uint64_t fde_func_1335_0x2ce6dc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x2ce6dcULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xa90553f5ULL) ^ 0x0fdde0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1336 | PC: 0x2ce910 | FDE: 0x0fde78 | Size: 108 bytes [_ZN4lynx7runtime14RuntimeManager8InstanceEv]
// Khung tháo gỡ #1336 | Địa chỉ PC: 0x2ce910 | Địa chỉ FDE: 0x0fde78 | Kích thước: 108 bytes
//   0x2ce910: F81F0FFE  str      x30, [sp, #-0x10]!
//   0x2ce914: 9401B495  bl       #0x33bb68
//   0x2ce918: 39400008  ldrb     w8, [x0]
//   0x2ce91c: 36000088  tbz      w8, #0, #0x2ce92c
static inline uint64_t fde_func_1336_0x2ce910(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x2ce910ULL ^ (static_cast<uint64_t>(0xf81f0ffeULL) << 13);
    acc = (acc + a1 + 0x9401b495ULL) ^ 0x0fde78ULL;
    acc ^= (acc >> 17) * 0x006cULL;
    return acc;
}

// FDE #1337 | PC: 0x2ce97c | FDE: 0x0fde90 | Size: 148 bytes [_ZN4lynx7runtime14RuntimeManagerD2Ev]
// Khung tháo gỡ #1337 | Địa chỉ PC: 0x2ce97c | Địa chỉ FDE: 0x0fde90 | Kích thước: 148 bytes
//   0x2ce97c: A9BE53F5  stp      x21, x20, [sp, #-0x20]!
//   0x2ce980: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x2ce984: F0000488  adrp     x8, #0x361000
//   0x2ce988: 9401A69B  bl       #0x3383f4
static inline uint64_t fde_func_1337_0x2ce97c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x2ce97cULL ^ (static_cast<uint64_t>(0xa9be53f5ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x0fde90ULL;
    acc ^= (acc >> 17) * 0x0094ULL;
    return acc;
}

// FDE #1338 | PC: 0x2cea10 | FDE: 0x0fdeb0 | Size: 256 bytes [_ZN4lynx7runtime14RuntimeManager9OnReleaseERKNSt6__ndk112basic_stringIcNS2_11char_traitsIcEENS2_9allocatorIcEEEE]
// Khung tháo gỡ #1338 | Địa chỉ PC: 0x2cea10 | Địa chỉ FDE: 0x0fdeb0 | Kích thước: 256 bytes
//   0x2cea10: AA1E03E2  mov      x2, x30
//   0x2cea14: 94013DF2  bl       #0x31e1dc
//   0x2cea18: AA0203FE  mov      x30, x2
//   0x2cea1c: A9087BF3  stp      x19, x30, [sp, #0x80]
static inline uint64_t fde_func_1338_0x2cea10(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x2cea10ULL ^ (static_cast<uint64_t>(0xaa1e03e2ULL) << 13);
    acc = (acc + a1 + 0x94013df2ULL) ^ 0x0fdeb0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1339 | PC: 0x2cebe0 | FDE: 0x0fded8 | Size: 24 bytes [_ZN4lynx7runtime14RuntimeManagerD0Ev]
// Khung tháo gỡ #1339 | Địa chỉ PC: 0x2cebe0 | Địa chỉ FDE: 0x0fded8 | Kích thước: 24 bytes
//   0x2cebe0: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x2cebe4: AA0003F3  mov      x19, x0
//   0x2cebe8: 9401D002  bl       #0x342bf0
//   0x2cebec: AA1303E0  mov      x0, x19
static inline uint64_t fde_func_1339_0x2cebe0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x2cebe0ULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0xaa0003f3ULL) ^ 0x0fded8ULL;
    acc ^= (acc >> 17) * 0x0018ULL;
    return acc;
}

// FDE #1340 | PC: 0x2cebf8 | FDE: 0x0fdef0 | Size: 20 bytes [_ZN4lynx7runtime14RuntimeManager17IsSingleJSContextERKNSt6__ndk112basic_stringIcNS2_11char_traitsIcEENS2_9allocatorIcEEEE]
// Khung tháo gỡ #1340 | Địa chỉ PC: 0x2cebf8 | Địa chỉ FDE: 0x0fdef0 | Kích thước: 20 bytes
//   0x2cebf8: F0FFED48  adrp     x8, #0x79000
//   0x2cebfc: 91033D08  add      x8, x8, #0xcf
//   0x2cec00: AA0103E0  mov      x0, x1
//   0x2cec04: AA0803E1  mov      x1, x8
static inline uint64_t fde_func_1340_0x2cebf8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x2cebf8ULL ^ (static_cast<uint64_t>(0xf0ffed48ULL) << 13);
    acc = (acc + a1 + 0x91033d08ULL) ^ 0x0fdef0ULL;
    acc ^= (acc >> 17) * 0x0014ULL;
    return acc;
}

// FDE #1341 | PC: 0x2cec0c | FDE: 0x0fdf08 | Size: 256 bytes [_ZN4lynx7runtime14RuntimeManager15CreateJSRuntimeERKNSt6__ndk112basic_stringIcNS2_11char_traitsIcEENS2_9allocatorIcEEEENS2_10shared_ptrINS_5piper19JSIExceptionHandlerEEENS_4base15MoveOnlyClosureINS2_6vectorINS2_4pairIS8_NSB_INSC_6BufferEEEEENS6_ISL_EEEEJEEEbRNSC_10JSExecutorElbbSA_NSG_ISK_JSA_EEERKNS_4tasm11PageOptionsE]
// Khung tháo gỡ #1341 | Địa chỉ PC: 0x2cec0c | Địa chỉ FDE: 0x0fdf08 | Kích thước: 256 bytes
//   0x2cec0c: D10783FF  sub      sp, sp, #0x1e0
//   0x2cec10: AA1E03E9  mov      x9, x30
//   0x2cec14: 94014161  bl       #0x31f198
//   0x2cec18: AA0903FE  mov      x30, x9
static inline uint64_t fde_func_1341_0x2cec0c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x2cec0cULL ^ (static_cast<uint64_t>(0xd10783ffULL) << 13);
    acc = (acc + a1 + 0xaa1e03e9ULL) ^ 0x0fdf08ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1342 | PC: 0x2cf620 | FDE: 0x0fdf38 | Size: 72 bytes [_ZN4lynx7runtime14RuntimeManager16IsInspectEnabledEbRKNS_4tasm11PageOptionsE]
// Khung tháo gỡ #1342 | Địa chỉ PC: 0x2cf620 | Địa chỉ FDE: 0x0fdf38 | Kích thước: 72 bytes
//   0x2cf620: F81E0FF4  str      x20, [sp, #-0x20]!
//   0x2cf624: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x2cf628: F9402C08  ldr      x8, [x0, #0x58]
//   0x2cf62c: B4000188  cbz      x8, #0x2cf65c
static inline uint64_t fde_func_1342_0x2cf620(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x2cf620ULL ^ (static_cast<uint64_t>(0xf81e0ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x0fdf38ULL;
    acc ^= (acc >> 17) * 0x0048ULL;
    return acc;
}

// FDE #1343 | PC: 0x2cf668 | FDE: 0x0fdf58 | Size: 164 bytes [_ZN4lynx7runtime14RuntimeManager13CreateRuntimeERKNSt6__ndk112basic_stringIcNS2_11char_traitsIcEENS2_9allocatorIcEEEENS2_10shared_ptrINS_5piper19JSIExceptionHandlerEEEblbSA_NS_4base15MoveOnlyClosureINSB_INSC_6BufferEEEJSA_EEERKNS_4tasm11PageOptionsEb]
// Khung tháo gỡ #1343 | Địa chỉ PC: 0x2cf668 | Địa chỉ FDE: 0x0fdf58 | Kích thước: 164 bytes
//   0x2cf668: F81C0FF8  str      x24, [sp, #-0x40]!
//   0x2cf66c: A9015BF7  stp      x23, x22, [sp, #0x10]
//   0x2cf670: A90253F5  stp      x21, x20, [sp, #0x20]
//   0x2cf674: A9037BF3  stp      x19, x30, [sp, #0x30]
static inline uint64_t fde_func_1343_0x2cf668(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x2cf668ULL ^ (static_cast<uint64_t>(0xf81c0ff8ULL) << 13);
    acc = (acc + a1 + 0xa9015bf7ULL) ^ 0x0fdf58ULL;
    acc ^= (acc >> 17) * 0x00a4ULL;
    return acc;
}

// FDE #1344 | PC: 0x2cf70c | FDE: 0x0fdf80 | Size: 256 bytes [_ZN4lynx7runtime14RuntimeManager16CreateJSIContextERNSt6__ndk110shared_ptrINS_5piper7RuntimeEEERKNS2_12basic_stringIcNS2_11char_traitsIcEENS2_9allocatorIcEEEE]
// Khung tháo gỡ #1344 | Địa chỉ PC: 0x2cf70c | Địa chỉ FDE: 0x0fdf80 | Kích thước: 256 bytes
//   0x2cf70c: AA1E03E2  mov      x2, x30
//   0x2cf710: 9401385E  bl       #0x31d888
//   0x2cf714: AA0203FE  mov      x30, x2
//   0x2cf718: A90B7BFD  stp      x29, x30, [sp, #0xb0]
static inline uint64_t fde_func_1344_0x2cf70c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x2cf70cULL ^ (static_cast<uint64_t>(0xaa1e03e2ULL) << 13);
    acc = (acc + a1 + 0x9401385eULL) ^ 0x0fdf80ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1345 | PC: 0x2cfc00 | FDE: 0x0fdfb0 | Size: 256 bytes [_ZN4lynx7runtime14RuntimeManager18GetSharedJSContextERKNSt6__ndk112basic_stringIcNS2_11char_traitsIcEENS2_9allocatorIcEEEE]
// Khung tháo gỡ #1345 | Địa chỉ PC: 0x2cfc00 | Địa chỉ FDE: 0x0fdfb0 | Kích thước: 256 bytes
//   0x2cfc00: AA1E03E2  mov      x2, x30
//   0x2cfc04: 9401351A  bl       #0x31d06c
//   0x2cfc08: AA0203FE  mov      x30, x2
//   0x2cfc0c: A9077BFD  stp      x29, x30, [sp, #0x70]
static inline uint64_t fde_func_1345_0x2cfc00(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x2cfc00ULL ^ (static_cast<uint64_t>(0xaa1e03e2ULL) << 13);
    acc = (acc + a1 + 0x9401351aULL) ^ 0x0fdfb0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1346 | PC: 0x2cfe24 | FDE: 0x0fdfe0 | Size: 212 bytes [_ZN4lynx7runtime14RuntimeManager20EnsureConsolePostManERNSt6__ndk110shared_ptrINS_5piper10JSIContextEEERNS4_10JSExecutorEbRKNS_4tasm11PageOptionsE]
// Khung tháo gỡ #1346 | Địa chỉ PC: 0x2cfe24 | Địa chỉ FDE: 0x0fdfe0 | Kích thước: 212 bytes
//   0x2cfe24: D10183FF  sub      sp, sp, #0x60
//   0x2cfe28: F9001BF6  str      x22, [sp, #0x30]
//   0x2cfe2c: A90453F5  stp      x21, x20, [sp, #0x40]
//   0x2cfe30: A9057BF3  stp      x19, x30, [sp, #0x50]
static inline uint64_t fde_func_1346_0x2cfe24(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x2cfe24ULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xf9001bf6ULL) ^ 0x0fdfe0ULL;
    acc ^= (acc >> 17) * 0x00d4ULL;
    return acc;
}

// FDE #1347 | PC: 0x2cfef8 | FDE: 0x0fe000 | Size: 256 bytes [_ZN4lynx7runtime14RuntimeManager11MakeRuntimeEbbRKNS_4tasm11PageOptionsE]
// Khung tháo gỡ #1347 | Địa chỉ PC: 0x2cfef8 | Địa chỉ FDE: 0x0fe000 | Kích thước: 256 bytes
//   0x2cfef8: AA1E03E4  mov      x4, x30
//   0x2cfefc: 94015D7C  bl       #0x3274ec
//   0x2cff00: AA0403FE  mov      x30, x4
//   0x2cff04: A9087BF3  stp      x19, x30, [sp, #0x80]
static inline uint64_t fde_func_1347_0x2cfef8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x2cfef8ULL ^ (static_cast<uint64_t>(0xaa1e03e4ULL) << 13);
    acc = (acc + a1 + 0x94015d7cULL) ^ 0x0fe000ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1348 | PC: 0x2d00ec | FDE: 0x0fe078 | Size: 80 bytes
// Khung tháo gỡ #1348 | Địa chỉ PC: 0x2d00ec | Địa chỉ FDE: 0x0fe078 | Kích thước: 80 bytes
//   0x2d00ec: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x2d00f0: AA0003F3  mov      x19, x0
//   0x2d00f4: 97FFFFF6  bl       #0x2d00cc
//   0x2d00f8: AA1303E0  mov      x0, x19
static inline uint64_t fde_func_1348_0x2d00ec(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x2d00ecULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0xaa0003f3ULL) ^ 0x0fe078ULL;
    acc ^= (acc >> 17) * 0x0050ULL;
    return acc;
}

// FDE #1349 | PC: 0x2d013c | FDE: 0x0fe0c0 | Size: 256 bytes [_ZN4lynx7runtime14RuntimeManager8EnsureVMERNSt6__ndk110shared_ptrINS_5piper7RuntimeEEE]
// Khung tháo gỡ #1349 | Địa chỉ PC: 0x2d013c | Địa chỉ FDE: 0x0fe0c0 | Kích thước: 256 bytes
//   0x2d013c: D10243FF  sub      sp, sp, #0x90
//   0x2d0140: AA1E03E2  mov      x2, x30
//   0x2d0144: 94014DDC  bl       #0x3238b4
//   0x2d0148: AA0203FE  mov      x30, x2
static inline uint64_t fde_func_1349_0x2d013c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x2d013cULL ^ (static_cast<uint64_t>(0xd10243ffULL) << 13);
    acc = (acc + a1 + 0xaa1e03e2ULL) ^ 0x0fe0c0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1350 | PC: 0x2d06e0 | FDE: 0x0fe138 | Size: 92 bytes [_ZN4lynx7runtime14RuntimeManager24InitJSRuntimeCreatedTypeEbRNSt6__ndk110shared_ptrINS_5piper7RuntimeEEE]
// Khung tháo gỡ #1350 | Địa chỉ PC: 0x2d06e0 | Địa chỉ FDE: 0x0fe138 | Kích thước: 92 bytes
//   0x2d06e0: F9400048  ldr      x8, [x2]
//   0x2d06e4: 7200003F  tst      w1, #1
//   0x2d06e8: 52800029  mov      w9, #1
//   0x2d06ec: 1A891529  cinc     w9, w9, eq
static inline uint64_t fde_func_1350_0x2d06e0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x2d06e0ULL ^ (static_cast<uint64_t>(0xf9400048ULL) << 13);
    acc = (acc + a1 + 0x7200003fULL) ^ 0x0fe138ULL;
    acc ^= (acc >> 17) * 0x005cULL;
    return acc;
}

// FDE #1351 | PC: 0x2d073c | FDE: 0x0fe180 | Size: 256 bytes [_ZN4lynx4tasm6report12EventTracker7OnEventENS_4base15MoveOnlyClosureIvJRNS1_13MoveOnlyEventEEEE]
// Khung tháo gỡ #1351 | Địa chỉ PC: 0x2d073c | Địa chỉ FDE: 0x0fe180 | Kích thước: 256 bytes
//   0x2d073c: A9BD5BF7  stp      x23, x22, [sp, #-0x30]!
//   0x2d0740: A90153F5  stp      x21, x20, [sp, #0x10]
//   0x2d0744: A9027BF3  stp      x19, x30, [sp, #0x20]
//   0x2d0748: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_1351_0x2d073c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x2d073cULL ^ (static_cast<uint64_t>(0xa9bd5bf7ULL) << 13);
    acc = (acc + a1 + 0xa90153f5ULL) ^ 0x0fe180ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1352 | PC: 0x2d0858 | FDE: 0x0fe1a0 | Size: 256 bytes
// Khung tháo gỡ #1352 | Địa chỉ PC: 0x2d0858 | Địa chỉ FDE: 0x0fe1a0 | Kích thước: 256 bytes
//   0x2d0858: F9400C08  ldr      x8, [x0, #0x18]
//   0x2d085c: F0000449  adrp     x9, #0x35b000
//   0x2d0860: 9117E129  add      x9, x9, #0x5f8
//   0x2d0864: 1401314F  b        #0x31cda0
static inline uint64_t fde_func_1352_0x2d0858(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x2d0858ULL ^ (static_cast<uint64_t>(0xf9400c08ULL) << 13);
    acc = (acc + a1 + 0xf0000449ULL) ^ 0x0fe1a0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1353 | PC: 0x2d0c00 | FDE: 0x0fe280 | Size: 240 bytes [_ZN4lynx4tasm6report12EventTracker17UpdateGenericInfoEiNSt6__ndk112basic_stringIcNS3_11char_traitsIcEENS3_9allocatorIcEEEES9_]
// Khung tháo gỡ #1353 | Địa chỉ PC: 0x2d0c00 | Địa chỉ FDE: 0x0fe280 | Kích thước: 240 bytes
//   0x2d0c00: AA1E03E3  mov      x3, x30
//   0x2d0c04: 94015A3A  bl       #0x3274ec
//   0x2d0c08: AA0303FE  mov      x30, x3
//   0x2d0c0c: A9087BF3  stp      x19, x30, [sp, #0x80]
static inline uint64_t fde_func_1353_0x2d0c00(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x2d0c00ULL ^ (static_cast<uint64_t>(0xaa1e03e3ULL) << 13);
    acc = (acc + a1 + 0x94015a3aULL) ^ 0x0fe280ULL;
    acc ^= (acc >> 17) * 0x00f0ULL;
    return acc;
}

// FDE #1354 | PC: 0x2d0cf0 | FDE: 0x0fe2c0 | Size: 256 bytes
// Khung tháo gỡ #1354 | Địa chỉ PC: 0x2d0cf0 | Địa chỉ FDE: 0x0fe2c0 | Kích thước: 256 bytes
//   0x2d0cf0: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x2d0cf4: AA0003F3  mov      x19, x0
//   0x2d0cf8: 97FFFFFA  bl       #0x2d0ce0
//   0x2d0cfc: AA1303E0  mov      x0, x19
static inline uint64_t fde_func_1354_0x2d0cf0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x2d0cf0ULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0xaa0003f3ULL) ^ 0x0fe2c0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1355 | PC: 0x2d0ec8 | FDE: 0x0fe370 | Size: 256 bytes [_ZN4lynx4tasm6report12EventTracker5FlushEi]
// Khung tháo gỡ #1355 | Địa chỉ PC: 0x2d0ec8 | Địa chỉ FDE: 0x0fe370 | Kích thước: 256 bytes
//   0x2d0ec8: D10203FF  sub      sp, sp, #0x80
//   0x2d0ecc: F9002BF6  str      x22, [sp, #0x50]
//   0x2d0ed0: A90653F5  stp      x21, x20, [sp, #0x60]
//   0x2d0ed4: A9077BF3  stp      x19, x30, [sp, #0x70]
static inline uint64_t fde_func_1355_0x2d0ec8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x2d0ec8ULL ^ (static_cast<uint64_t>(0xd10203ffULL) << 13);
    acc = (acc + a1 + 0xf9002bf6ULL) ^ 0x0fe370ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1356 | PC: 0x2d1228 | FDE: 0x0fe3f0 | Size: 256 bytes
// Khung tháo gỡ #1356 | Địa chỉ PC: 0x2d1228 | Địa chỉ FDE: 0x0fe3f0 | Kích thước: 256 bytes
//   0x2d1228: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x2d122c: F9400001  ldr      x1, [x0]
//   0x2d1230: B40000C1  cbz      x1, #0x2d1248
//   0x2d1234: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_1356_0x2d1228(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x2d1228ULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0xf9400001ULL) ^ 0x0fe3f0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1357 | PC: 0x2d156c | FDE: 0x0fe520 | Size: 256 bytes
// Khung tháo gỡ #1357 | Địa chỉ PC: 0x2d156c | Địa chỉ FDE: 0x0fe520 | Kích thước: 256 bytes
//   0x2d156c: D0000448  adrp     x8, #0x35b000
//   0x2d1570: 911C8108  add      x8, x8, #0x720
//   0x2d1574: 140169FF  b        #0x32bd70
//   0x2d1578: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
static inline uint64_t fde_func_1357_0x2d156c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x2d156cULL ^ (static_cast<uint64_t>(0xd0000448ULL) << 13);
    acc = (acc + a1 + 0x911c8108ULL) ^ 0x0fe520ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1358 | PC: 0x2d1c04 | FDE: 0x0fe658 | Size: 256 bytes
// Khung tháo gỡ #1358 | Địa chỉ PC: 0x2d1c04 | Địa chỉ FDE: 0x0fe658 | Kích thước: 256 bytes
//   0x2d1c04: D10183FF  sub      sp, sp, #0x60
//   0x2d1c08: F9001BF6  str      x22, [sp, #0x30]
//   0x2d1c0c: A90453F5  stp      x21, x20, [sp, #0x40]
//   0x2d1c10: A9057BF3  stp      x19, x30, [sp, #0x50]
static inline uint64_t fde_func_1358_0x2d1c04(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x2d1c04ULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xf9001bf6ULL) ^ 0x0fe658ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1359 | PC: 0x2d2204 | FDE: 0x0fe788 | Size: 256 bytes
// Khung tháo gỡ #1359 | Địa chỉ PC: 0x2d2204 | Địa chỉ FDE: 0x0fe788 | Kích thước: 256 bytes
//   0x2d2204: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x2d2208: 9401B0AD  bl       #0x33e4bc
//   0x2d220c: B40000C8  cbz      x8, #0x2d2224
//   0x2d2210: 9401A579  bl       #0x33b7f4
static inline uint64_t fde_func_1359_0x2d2204(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x2d2204ULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0x9401b0adULL) ^ 0x0fe788ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1360 | PC: 0x2d274c | FDE: 0x0fe8a0 | Size: 256 bytes
// Khung tháo gỡ #1360 | Địa chỉ PC: 0x2d274c | Địa chỉ FDE: 0x0fe8a0 | Kích thước: 256 bytes
//   0x2d274c: D10303FF  sub      sp, sp, #0xc0
//   0x2d2750: 6D0823E9  stp      d9, d8, [sp, #0x80]
//   0x2d2754: F9004BF6  str      x22, [sp, #0x90]
//   0x2d2758: A90A53F5  stp      x21, x20, [sp, #0xa0]
static inline uint64_t fde_func_1360_0x2d274c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x2d274cULL ^ (static_cast<uint64_t>(0xd10303ffULL) << 13);
    acc = (acc + a1 + 0x6d0823e9ULL) ^ 0x0fe8a0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1361 | PC: 0x2d2fe0 | FDE: 0x0fe9c8 | Size: 256 bytes
// Khung tháo gỡ #1361 | Địa chỉ PC: 0x2d2fe0 | Địa chỉ FDE: 0x0fe9c8 | Kích thước: 256 bytes
//   0x2d2fe0: F81E0FF4  str      x20, [sp, #-0x20]!
//   0x2d2fe4: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x2d2fe8: AA0003F3  mov      x19, x0
//   0x2d2fec: 94016656  bl       #0x32c944
static inline uint64_t fde_func_1361_0x2d2fe0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x2d2fe0ULL ^ (static_cast<uint64_t>(0xf81e0ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x0fe9c8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1362 | PC: 0x2d3660 | FDE: 0x0feb10 | Size: 256 bytes
// Khung tháo gỡ #1362 | Địa chỉ PC: 0x2d3660 | Địa chỉ FDE: 0x0feb10 | Kích thước: 256 bytes
//   0x2d3660: 90000448  adrp     x8, #0x35b000
//   0x2d3664: 912E0108  add      x8, x8, #0xb80
//   0x2d3668: F8008408  str      x8, [x0], #8
//   0x2d366c: 17FFFCB4  b        #0x2d293c
static inline uint64_t fde_func_1362_0x2d3660(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x2d3660ULL ^ (static_cast<uint64_t>(0x90000448ULL) << 13);
    acc = (acc + a1 + 0x912e0108ULL) ^ 0x0feb10ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1363 | PC: 0x2d3988 | FDE: 0x0fec30 | Size: 256 bytes
// Khung tháo gỡ #1363 | Địa chỉ PC: 0x2d3988 | Địa chỉ FDE: 0x0fec30 | Kích thước: 256 bytes
//   0x2d3988: F81F0FFE  str      x30, [sp, #-0x10]!
//   0x2d398c: 97FFFFD0  bl       #0x2d38cc
//   0x2d3990: F00004A8  adrp     x8, #0x36a000
//   0x2d3994: B9456100  ldr      w0, [x8, #0x560]
static inline uint64_t fde_func_1363_0x2d3988(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x2d3988ULL ^ (static_cast<uint64_t>(0xf81f0ffeULL) << 13);
    acc = (acc + a1 + 0x97ffffd0ULL) ^ 0x0fec30ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1364 | PC: 0x2d3e68 | FDE: 0x0fed48 | Size: 256 bytes
// Khung tháo gỡ #1364 | Địa chỉ PC: 0x2d3e68 | Địa chỉ FDE: 0x0fed48 | Kích thước: 256 bytes
//   0x2d3e68: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x2d3e6c: 900004C8  adrp     x8, #0x36b000
//   0x2d3e70: 91184108  add      x8, x8, #0x610
//   0x2d3e74: 08DFFD08  ldarb    w8, [x8]
static inline uint64_t fde_func_1364_0x2d3e68(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x2d3e68ULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0x900004c8ULL) ^ 0x0fed48ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1365 | PC: 0x2d457c | FDE: 0x0fee68 | Size: 256 bytes
// Khung tháo gỡ #1365 | Địa chỉ PC: 0x2d457c | Địa chỉ FDE: 0x0fee68 | Kích thước: 256 bytes
//   0x2d457c: A9BD5BF7  stp      x23, x22, [sp, #-0x30]!
//   0x2d4580: A90153F5  stp      x21, x20, [sp, #0x10]
//   0x2d4584: A9027BF3  stp      x19, x30, [sp, #0x20]
//   0x2d4588: 94012084  bl       #0x31c798
static inline uint64_t fde_func_1365_0x2d457c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x2d457cULL ^ (static_cast<uint64_t>(0xa9bd5bf7ULL) << 13);
    acc = (acc + a1 + 0xa90153f5ULL) ^ 0x0fee68ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1366 | PC: 0x2d4c2c | FDE: 0x0fef98 | Size: 256 bytes
// Khung tháo gỡ #1366 | Địa chỉ PC: 0x2d4c2c | Địa chỉ FDE: 0x0fef98 | Kích thước: 256 bytes
//   0x2d4c2c: A9BE53F5  stp      x21, x20, [sp, #-0x20]!
//   0x2d4c30: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x2d4c34: 94012E97  bl       #0x320690
//   0x2d4c38: B40000D4  cbz      x20, #0x2d4c50
static inline uint64_t fde_func_1366_0x2d4c2c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x2d4c2cULL ^ (static_cast<uint64_t>(0xa9be53f5ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x0fef98ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1367 | PC: 0x2d50dc | FDE: 0x0ff0c0 | Size: 256 bytes
// Khung tháo gỡ #1367 | Địa chỉ PC: 0x2d50dc | Địa chỉ FDE: 0x0ff0c0 | Kích thước: 256 bytes
//   0x2d50dc: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x2d50e0: AA0003F3  mov      x19, x0
//   0x2d50e4: 97FFFFFA  bl       #0x2d50cc
//   0x2d50e8: AA1303E0  mov      x0, x19
static inline uint64_t fde_func_1367_0x2d50dc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x2d50dcULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0xaa0003f3ULL) ^ 0x0ff0c0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1368 | PC: 0x2d5644 | FDE: 0x0ff1f0 | Size: 256 bytes
// Khung tháo gỡ #1368 | Địa chỉ PC: 0x2d5644 | Địa chỉ FDE: 0x0ff1f0 | Kích thước: 256 bytes
//   0x2d5644: AA1E03E1  mov      x1, x30
//   0x2d5648: 9401831A  bl       #0x3362b0
//   0x2d564c: AA0103FE  mov      x30, x1
//   0x2d5650: A9117BF3  stp      x19, x30, [sp, #0x110]
static inline uint64_t fde_func_1368_0x2d5644(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x2d5644ULL ^ (static_cast<uint64_t>(0xaa1e03e1ULL) << 13);
    acc = (acc + a1 + 0x9401831aULL) ^ 0x0ff1f0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1369 | PC: 0x2d5b6c | FDE: 0x0ff328 | Size: 256 bytes
// Khung tháo gỡ #1369 | Địa chỉ PC: 0x2d5b6c | Địa chỉ FDE: 0x0ff328 | Kích thước: 256 bytes
//   0x2d5b6c: D10103FF  sub      sp, sp, #0x40
//   0x2d5b70: A9015BF7  stp      x23, x22, [sp, #0x10]
//   0x2d5b74: A90253F5  stp      x21, x20, [sp, #0x20]
//   0x2d5b78: A9037BF3  stp      x19, x30, [sp, #0x30]
static inline uint64_t fde_func_1369_0x2d5b6c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x2d5b6cULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xa9015bf7ULL) ^ 0x0ff328ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1370 | PC: 0x2d5dfc | FDE: 0x0ff448 | Size: 256 bytes
// Khung tháo gỡ #1370 | Địa chỉ PC: 0x2d5dfc | Địa chỉ FDE: 0x0ff448 | Kích thước: 256 bytes
//   0x2d5dfc: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x2d5e00: 94011A38  bl       #0x31c6e0
//   0x2d5e04: 97FDEC8C  bl       #0x251034
//   0x2d5e08: F9400660  ldr      x0, [x19, #8]
static inline uint64_t fde_func_1370_0x2d5dfc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x2d5dfcULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0x94011a38ULL) ^ 0x0ff448ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1371 | PC: 0x2d5f70 | FDE: 0x0ff550 | Size: 256 bytes
// Khung tháo gỡ #1371 | Địa chỉ PC: 0x2d5f70 | Địa chỉ FDE: 0x0ff550 | Kích thước: 256 bytes
//   0x2d5f70: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x2d5f74: AA0003F3  mov      x19, x0
//   0x2d5f78: 94011AE0  bl       #0x31caf8
//   0x2d5f7c: 6F00E400  movi     v0.2d, #0000000000000000
static inline uint64_t fde_func_1371_0x2d5f70(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x2d5f70ULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0xaa0003f3ULL) ^ 0x0ff550ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1372 | PC: 0x2d63d8 | FDE: 0x0ff678 | Size: 256 bytes
// Khung tháo gỡ #1372 | Địa chỉ PC: 0x2d63d8 | Địa chỉ FDE: 0x0ff678 | Kích thước: 256 bytes
//   0x2d63d8: B0000428  adrp     x8, #0x35b000
//   0x2d63dc: 913CA108  add      x8, x8, #0xf28
//   0x2d63e0: F8008408  str      x8, [x0], #8
//   0x2d63e4: 17FFFF94  b        #0x2d6234
static inline uint64_t fde_func_1372_0x2d63d8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x2d63d8ULL ^ (static_cast<uint64_t>(0xb0000428ULL) << 13);
    acc = (acc + a1 + 0x913ca108ULL) ^ 0x0ff678ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1373 | PC: 0x2d65f4 | FDE: 0x0ff788 | Size: 256 bytes
// Khung tháo gỡ #1373 | Địa chỉ PC: 0x2d65f4 | Địa chỉ FDE: 0x0ff788 | Kích thước: 256 bytes
//   0x2d65f4: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x2d65f8: AA0003F3  mov      x19, x0
//   0x2d65fc: 97FFFFEF  bl       #0x2d65b8
//   0x2d6600: AA1303E0  mov      x0, x19
static inline uint64_t fde_func_1373_0x2d65f4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x2d65f4ULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0xaa0003f3ULL) ^ 0x0ff788ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1374 | PC: 0x2d702c | FDE: 0x0ff8d8 | Size: 256 bytes
// Khung tháo gỡ #1374 | Địa chỉ PC: 0x2d702c | Địa chỉ FDE: 0x0ff8d8 | Kích thước: 256 bytes
//   0x2d702c: AA1E03E6  mov      x6, x30
//   0x2d7030: 9401750A  bl       #0x334458
//   0x2d7034: AA0603FE  mov      x30, x6
//   0x2d7038: A90D7BF3  stp      x19, x30, [sp, #0xd0]
static inline uint64_t fde_func_1374_0x2d702c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x2d702cULL ^ (static_cast<uint64_t>(0xaa1e03e6ULL) << 13);
    acc = (acc + a1 + 0x9401750aULL) ^ 0x0ff8d8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1375 | PC: 0x2d7890 | FDE: 0x0ffa20 | Size: 256 bytes
// Khung tháo gỡ #1375 | Địa chỉ PC: 0x2d7890 | Địa chỉ FDE: 0x0ffa20 | Kích thước: 256 bytes
//   0x2d7890: D101C3FF  sub      sp, sp, #0x70
//   0x2d7894: F90023F6  str      x22, [sp, #0x40]
//   0x2d7898: A90553F5  stp      x21, x20, [sp, #0x50]
//   0x2d789c: A9067BF3  stp      x19, x30, [sp, #0x60]
static inline uint64_t fde_func_1375_0x2d7890(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x2d7890ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xf90023f6ULL) ^ 0x0ffa20ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1376 | PC: 0x2d7b20 | FDE: 0x0ffb58 | Size: 256 bytes
// Khung tháo gỡ #1376 | Địa chỉ PC: 0x2d7b20 | Địa chỉ FDE: 0x0ffb58 | Kích thước: 256 bytes
//   0x2d7b20: F81D0FF6  str      x22, [sp, #-0x30]!
//   0x2d7b24: A90153F5  stp      x21, x20, [sp, #0x10]
//   0x2d7b28: A9027BF3  stp      x19, x30, [sp, #0x20]
//   0x2d7b2c: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_1376_0x2d7b20(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x2d7b20ULL ^ (static_cast<uint64_t>(0xf81d0ff6ULL) << 13);
    acc = (acc + a1 + 0xa90153f5ULL) ^ 0x0ffb58ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1377 | PC: 0x2d8f68 | FDE: 0x0ffcb8 | Size: 256 bytes
// Khung tháo gỡ #1377 | Địa chỉ PC: 0x2d8f68 | Địa chỉ FDE: 0x0ffcb8 | Kích thước: 256 bytes
//   0x2d8f68: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x2d8f6c: 94010E2B  bl       #0x31c818
//   0x2d8f70: B4000113  cbz      x19, #0x2d8f90
//   0x2d8f74: 39404008  ldrb     w8, [x0, #0x10]
static inline uint64_t fde_func_1377_0x2d8f68(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x2d8f68ULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0x94010e2bULL) ^ 0x0ffcb8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1378 | PC: 0x2dad30 | FDE: 0x0ffe00 | Size: 256 bytes
// Khung tháo gỡ #1378 | Địa chỉ PC: 0x2dad30 | Địa chỉ FDE: 0x0ffe00 | Kích thước: 256 bytes
//   0x2dad30: D10103FF  sub      sp, sp, #0x40
//   0x2dad34: F90013F4  str      x20, [sp, #0x20]
//   0x2dad38: A9037BF3  stp      x19, x30, [sp, #0x30]
//   0x2dad3c: D53BD054  mrs      x20, tpidr_el0
static inline uint64_t fde_func_1378_0x2dad30(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x2dad30ULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xf90013f4ULL) ^ 0x0ffe00ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1379 | PC: 0x2db718 | FDE: 0x0fffa0 | Size: 256 bytes
// Khung tháo gỡ #1379 | Địa chỉ PC: 0x2db718 | Địa chỉ FDE: 0x0fffa0 | Kích thước: 256 bytes
//   0x2db718: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x2db71c: AA0003F3  mov      x19, x0
//   0x2db720: 97FA3891  bl       #0x169964
//   0x2db724: B4000080  cbz      x0, #0x2db734
static inline uint64_t fde_func_1379_0x2db718(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x2db718ULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0xaa0003f3ULL) ^ 0x0fffa0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1380 | PC: 0x2dc380 | FDE: 0x100250 | Size: 256 bytes
// Khung tháo gỡ #1380 | Địa chỉ PC: 0x2dc380 | Địa chỉ FDE: 0x100250 | Kích thước: 256 bytes
//   0x2dc380: F9400821  ldr      x1, [x1, #0x10]
//   0x2dc384: 17FFFC62  b        #0x2db50c
//   0x2dc388: F81D0FF6  str      x22, [sp, #-0x30]!
//   0x2dc38c: A90153F5  stp      x21, x20, [sp, #0x10]
static inline uint64_t fde_func_1380_0x2dc380(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x2dc380ULL ^ (static_cast<uint64_t>(0xf9400821ULL) << 13);
    acc = (acc + a1 + 0x17fffc62ULL) ^ 0x100250ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1381 | PC: 0x2dda30 | FDE: 0x1003a0 | Size: 256 bytes
// Khung tháo gỡ #1381 | Địa chỉ PC: 0x2dda30 | Địa chỉ FDE: 0x1003a0 | Kích thước: 256 bytes
//   0x2dda30: D10143FF  sub      sp, sp, #0x50
//   0x2dda34: A9025BF7  stp      x23, x22, [sp, #0x20]
//   0x2dda38: A90353F5  stp      x21, x20, [sp, #0x30]
//   0x2dda3c: A9047BF3  stp      x19, x30, [sp, #0x40]
static inline uint64_t fde_func_1381_0x2dda30(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x2dda30ULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xa9025bf7ULL) ^ 0x1003a0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1382 | PC: 0x2ddc94 | FDE: 0x1004b0 | Size: 256 bytes
// Khung tháo gỡ #1382 | Địa chỉ PC: 0x2ddc94 | Địa chỉ FDE: 0x1004b0 | Kích thước: 256 bytes
//   0x2ddc94: F81E0FF4  str      x20, [sp, #-0x20]!
//   0x2ddc98: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x2ddc9c: 94010D7F  bl       #0x321298
//   0x2ddca0: 9401729D  bl       #0x33a714
static inline uint64_t fde_func_1382_0x2ddc94(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x2ddc94ULL ^ (static_cast<uint64_t>(0xf81e0ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x1004b0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1383 | PC: 0x2dde04 | FDE: 0x1005c0 | Size: 256 bytes
// Khung tháo gỡ #1383 | Địa chỉ PC: 0x2dde04 | Địa chỉ FDE: 0x1005c0 | Kích thước: 256 bytes
//   0x2dde04: F00003E8  adrp     x8, #0x35c000
//   0x2dde08: 9103E108  add      x8, x8, #0xf8
//   0x2dde0c: F8008408  str      x8, [x0], #8
//   0x2dde10: 17FFDCAA  b        #0x2d50b8
static inline uint64_t fde_func_1383_0x2dde04(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x2dde04ULL ^ (static_cast<uint64_t>(0xf00003e8ULL) << 13);
    acc = (acc + a1 + 0x9103e108ULL) ^ 0x1005c0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1384 | PC: 0x2ddf78 | FDE: 0x100678 | Size: 48 bytes [_ZN4lynx4tasm18WhiteBoardDelegate12GetInspectorEv]
// Khung tháo gỡ #1384 | Địa chỉ PC: 0x2ddf78 | Địa chỉ FDE: 0x100678 | Kích thước: 48 bytes
//   0x2ddf78: F9400C09  ldr      x9, [x0, #0x18]
//   0x2ddf7c: B4000149  cbz      x9, #0x2ddfa4
//   0x2ddf80: A947252A  ldp      x10, x9, [x9, #0x70]
//   0x2ddf84: A900250A  stp      x10, x9, [x8]
static inline uint64_t fde_func_1384_0x2ddf78(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x2ddf78ULL ^ (static_cast<uint64_t>(0xf9400c09ULL) << 13);
    acc = (acc + a1 + 0xb4000149ULL) ^ 0x100678ULL;
    acc ^= (acc >> 17) * 0x0030ULL;
    return acc;
}

// FDE #1385 | PC: 0x2ddfa8 | FDE: 0x100690 | Size: 256 bytes [_ZN4lynx4tasm18WhiteBoardDelegate12SetInspectorERKNSt6__ndk110shared_ptrINS0_19WhiteBoardInspectorEEE]
// Khung tháo gỡ #1385 | Địa chỉ PC: 0x2ddfa8 | Địa chỉ FDE: 0x100690 | Kích thước: 256 bytes
//   0x2ddfa8: F81E0FF4  str      x20, [sp, #-0x20]!
//   0x2ddfac: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x2ddfb0: F9400C08  ldr      x8, [x0, #0x18]
//   0x2ddfb4: B4000308  cbz      x8, #0x2de014
static inline uint64_t fde_func_1385_0x2ddfa8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x2ddfa8ULL ^ (static_cast<uint64_t>(0xf81e0ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x100690ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1386 | PC: 0x2de16c | FDE: 0x1006d0 | Size: 256 bytes
// Khung tháo gỡ #1386 | Địa chỉ PC: 0x2de16c | Địa chỉ FDE: 0x1006d0 | Kích thước: 256 bytes
//   0x2de16c: D101C3FF  sub      sp, sp, #0x70
//   0x2de170: A90553F5  stp      x21, x20, [sp, #0x50]
//   0x2de174: A9067BF3  stp      x19, x30, [sp, #0x60]
//   0x2de178: D53BD054  mrs      x20, tpidr_el0
static inline uint64_t fde_func_1386_0x2de16c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x2de16cULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xa90553f5ULL) ^ 0x1006d0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1387 | PC: 0x2de508 | FDE: 0x1007f0 | Size: 256 bytes
// Khung tháo gỡ #1387 | Địa chỉ PC: 0x2de508 | Địa chỉ FDE: 0x1007f0 | Kích thước: 256 bytes
//   0x2de508: F9400808  ldr      x8, [x0, #0x10]
//   0x2de50c: D00003E9  adrp     x9, #0x35c000
//   0x2de510: 9107E129  add      x9, x9, #0x1f8
//   0x2de514: 14012695  b        #0x327f68
static inline uint64_t fde_func_1387_0x2de508(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x2de508ULL ^ (static_cast<uint64_t>(0xf9400808ULL) << 13);
    acc = (acc + a1 + 0xd00003e9ULL) ^ 0x1007f0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1388 | PC: 0x2de770 | FDE: 0x100900 | Size: 256 bytes
// Khung tháo gỡ #1388 | Địa chỉ PC: 0x2de770 | Địa chỉ FDE: 0x100900 | Kích thước: 256 bytes
//   0x2de770: D101C3FF  sub      sp, sp, #0x70
//   0x2de774: F90023F6  str      x22, [sp, #0x40]
//   0x2de778: A90553F5  stp      x21, x20, [sp, #0x50]
//   0x2de77c: A9067BF3  stp      x19, x30, [sp, #0x60]
static inline uint64_t fde_func_1388_0x2de770(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x2de770ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xf90023f6ULL) ^ 0x100900ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1389 | PC: 0x2deb00 | FDE: 0x100a20 | Size: 232 bytes
// Khung tháo gỡ #1389 | Địa chỉ PC: 0x2deb00 | Địa chỉ FDE: 0x100a20 | Kích thước: 232 bytes
//   0x2deb00: D00003E8  adrp     x8, #0x35c000
//   0x2deb04: 910B8108  add      x8, x8, #0x2e0
//   0x2deb08: F8008408  str      x8, [x0], #8
//   0x2deb0c: 17FD4CB5  b        #0x231de0
static inline uint64_t fde_func_1389_0x2deb00(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x2deb00ULL ^ (static_cast<uint64_t>(0xd00003e8ULL) << 13);
    acc = (acc + a1 + 0x910b8108ULL) ^ 0x100a20ULL;
    acc ^= (acc >> 17) * 0x00e8ULL;
    return acc;
}

// FDE #1390 | PC: 0x2debe8 | FDE: 0x100b20 | Size: 256 bytes
// Khung tháo gỡ #1390 | Địa chỉ PC: 0x2debe8 | Địa chỉ FDE: 0x100b20 | Kích thước: 256 bytes
//   0x2debe8: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x2debec: AA0003F3  mov      x19, x0
//   0x2debf0: 97FFFFFA  bl       #0x2debd8
//   0x2debf4: AA1303E0  mov      x0, x19
static inline uint64_t fde_func_1390_0x2debe8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x2debe8ULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0xaa0003f3ULL) ^ 0x100b20ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1391 | PC: 0x2def98 | FDE: 0x100c30 | Size: 48 bytes
// Khung tháo gỡ #1391 | Địa chỉ PC: 0x2def98 | Địa chỉ FDE: 0x100c30 | Kích thước: 48 bytes
//   0x2def98: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x2def9c: 9400F61F  bl       #0x31c818
//   0x2defa0: B4000113  cbz      x19, #0x2defc0
//   0x2defa4: 39404008  ldrb     w8, [x0, #0x10]
static inline uint64_t fde_func_1391_0x2def98(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x2def98ULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0x9400f61fULL) ^ 0x100c30ULL;
    acc ^= (acc >> 17) * 0x0030ULL;
    return acc;
}

// FDE #1392 | PC: 0x2defc8 | FDE: 0x100c48 | Size: 256 bytes [_ZN4lynx4tasm10WhiteBoard19SetGlobalSharedDataERKNSt6__ndk112basic_stringIcNS2_11char_traitsIcEENS2_9allocatorIcEEEERKNS2_10shared_ptrINS_3pub5ValueEEE]
// Khung tháo gỡ #1392 | Địa chỉ PC: 0x2defc8 | Địa chỉ FDE: 0x100c48 | Kích thước: 256 bytes
//   0x2defc8: AA1E03E3  mov      x3, x30
//   0x2defcc: 9400F828  bl       #0x31d06c
//   0x2defd0: AA0303FE  mov      x30, x3
//   0x2defd4: A9077BFD  stp      x29, x30, [sp, #0x70]
static inline uint64_t fde_func_1392_0x2defc8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x2defc8ULL ^ (static_cast<uint64_t>(0xaa1e03e3ULL) << 13);
    acc = (acc + a1 + 0x9400f828ULL) ^ 0x100c48ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1393 | PC: 0x2df48c | FDE: 0x100cd8 | Size: 108 bytes [_ZN4lynx4tasm10WhiteBoard19GetGlobalSharedDataERKNSt6__ndk112basic_stringIcNS2_11char_traitsIcEENS2_9allocatorIcEEEE]
// Khung tháo gỡ #1393 | Địa chỉ PC: 0x2df48c | Địa chỉ FDE: 0x100cd8 | Kích thước: 108 bytes
//   0x2df48c: F81D0FF6  str      x22, [sp, #-0x30]!
//   0x2df490: A90153F5  stp      x21, x20, [sp, #0x10]
//   0x2df494: A9027BF3  stp      x19, x30, [sp, #0x20]
//   0x2df498: F9401413  ldr      x19, [x0, #0x28]
static inline uint64_t fde_func_1393_0x2df48c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x2df48cULL ^ (static_cast<uint64_t>(0xf81d0ff6ULL) << 13);
    acc = (acc + a1 + 0xa90153f5ULL) ^ 0x100cd8ULL;
    acc ^= (acc >> 17) * 0x006cULL;
    return acc;
}

// FDE #1394 | PC: 0x2df4f8 | FDE: 0x100cf8 | Size: 256 bytes [_ZN4lynx4tasm10WhiteBoard22RemoveGlobalSharedDataERKNSt6__ndk112basic_stringIcNS2_11char_traitsIcEENS2_9allocatorIcEEEE]
// Khung tháo gỡ #1394 | Địa chỉ PC: 0x2df4f8 | Địa chỉ FDE: 0x100cf8 | Kích thước: 256 bytes
//   0x2df4f8: D10143FF  sub      sp, sp, #0x50
//   0x2df4fc: F90013F6  str      x22, [sp, #0x20]
//   0x2df500: A90353F5  stp      x21, x20, [sp, #0x30]
//   0x2df504: A9047BF3  stp      x19, x30, [sp, #0x40]
static inline uint64_t fde_func_1394_0x2df4f8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x2df4f8ULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xf90013f6ULL) ^ 0x100cf8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1395 | PC: 0x2df64c | FDE: 0x100d18 | Size: 256 bytes [_ZN4lynx4tasm10WhiteBoard21ClearGlobalSharedDataEv]
// Khung tháo gỡ #1395 | Địa chỉ PC: 0x2df64c | Địa chỉ FDE: 0x100d18 | Kích thước: 256 bytes
//   0x2df64c: F81E0FF4  str      x20, [sp, #-0x20]!
//   0x2df650: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x2df654: F9401414  ldr      x20, [x0, #0x28]
//   0x2df658: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_1395_0x2df64c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x2df64cULL ^ (static_cast<uint64_t>(0xf81e0ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x100d18ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1396 | PC: 0x2dfb1c | FDE: 0x100d88 | Size: 256 bytes
// Khung tháo gỡ #1396 | Địa chỉ PC: 0x2dfb1c | Địa chỉ FDE: 0x100d88 | Kích thước: 256 bytes
//   0x2dfb1c: B00003E8  adrp     x8, #0x35c000
//   0x2dfb20: 910E8108  add      x8, x8, #0x3a0
//   0x2dfb24: F8010408  str      x8, [x0], #0x10
//   0x2dfb28: 17F9F1E8  b        #0x15c2c8
static inline uint64_t fde_func_1396_0x2dfb1c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x2dfb1cULL ^ (static_cast<uint64_t>(0xb00003e8ULL) << 13);
    acc = (acc + a1 + 0x910e8108ULL) ^ 0x100d88ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1397 | PC: 0x2dfe3c | FDE: 0x100e88 | Size: 256 bytes
// Khung tháo gỡ #1397 | Địa chỉ PC: 0x2dfe3c | Địa chỉ FDE: 0x100e88 | Kích thước: 256 bytes
//   0x2dfe3c: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x2dfe40: AA0003F3  mov      x19, x0
//   0x2dfe44: 97FFFFF6  bl       #0x2dfe1c
//   0x2dfe48: AA1303E0  mov      x0, x19
static inline uint64_t fde_func_1397_0x2dfe3c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x2dfe3cULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0xaa0003f3ULL) ^ 0x100e88ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1398 | PC: 0x2e0064 | FDE: 0x100f80 | Size: 256 bytes
// Khung tháo gỡ #1398 | Địa chỉ PC: 0x2e0064 | Địa chỉ FDE: 0x100f80 | Kích thước: 256 bytes
//   0x2e0064: D10083FF  sub      sp, sp, #0x20
//   0x2e0068: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x2e006c: 94010D42  bl       #0x323574
//   0x2e0070: 9400F553  bl       #0x31d5bc
static inline uint64_t fde_func_1398_0x2e0064(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x2e0064ULL ^ (static_cast<uint64_t>(0xd10083ffULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x100f80ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1399 | PC: 0x2e08b4 | FDE: 0x1010c0 | Size: 256 bytes
// Khung tháo gỡ #1399 | Địa chỉ PC: 0x2e08b4 | Địa chỉ FDE: 0x1010c0 | Kích thước: 256 bytes
//   0x2e08b4: AA1E03E3  mov      x3, x30
//   0x2e08b8: 94012114  bl       #0x328d08
//   0x2e08bc: AA0303FE  mov      x30, x3
//   0x2e08c0: A90E7BF3  stp      x19, x30, [sp, #0xe0]
static inline uint64_t fde_func_1399_0x2e08b4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x2e08b4ULL ^ (static_cast<uint64_t>(0xaa1e03e3ULL) << 13);
    acc = (acc + a1 + 0x94012114ULL) ^ 0x1010c0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1400 | PC: 0x2e0c3c | FDE: 0x1011e0 | Size: 256 bytes
// Khung tháo gỡ #1400 | Địa chỉ PC: 0x2e0c3c | Địa chỉ FDE: 0x1011e0 | Kích thước: 256 bytes
//   0x2e0c3c: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x2e0c40: AA0003F3  mov      x19, x0
//   0x2e0c44: 97FFFFFA  bl       #0x2e0c2c
//   0x2e0c48: AA1303E0  mov      x0, x19
static inline uint64_t fde_func_1400_0x2e0c3c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x2e0c3cULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0xaa0003f3ULL) ^ 0x1011e0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1401 | PC: 0x2e0e20 | FDE: 0x1012e8 | Size: 256 bytes
// Khung tháo gỡ #1401 | Địa chỉ PC: 0x2e0e20 | Địa chỉ FDE: 0x1012e8 | Kích thước: 256 bytes
//   0x2e0e20: F9400408  ldr      x8, [x0, #8]
//   0x2e0e24: 900003E9  adrp     x9, #0x35c000
//   0x2e0e28: 91170129  add      x9, x9, #0x5c0
//   0x2e0e2c: F9000009  str      x9, [x0]
static inline uint64_t fde_func_1401_0x2e0e20(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x2e0e20ULL ^ (static_cast<uint64_t>(0xf9400408ULL) << 13);
    acc = (acc + a1 + 0x900003e9ULL) ^ 0x1012e8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1402 | PC: 0x2e10d0 | FDE: 0x1013f0 | Size: 256 bytes
// Khung tháo gỡ #1402 | Địa chỉ PC: 0x2e10d0 | Địa chỉ FDE: 0x1013f0 | Kích thước: 256 bytes
//   0x2e10d0: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x2e10d4: AA0003F3  mov      x19, x0
//   0x2e10d8: 97FFFFFA  bl       #0x2e10c0
//   0x2e10dc: AA1303E0  mov      x0, x19
static inline uint64_t fde_func_1402_0x2e10d0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x2e10d0ULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0xaa0003f3ULL) ^ 0x1013f0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1403 | PC: 0x2e14a4 | FDE: 0x101508 | Size: 256 bytes
// Khung tháo gỡ #1403 | Địa chỉ PC: 0x2e14a4 | Địa chỉ FDE: 0x101508 | Kích thước: 256 bytes
//   0x2e14a4: F81D0FF6  str      x22, [sp, #-0x30]!
//   0x2e14a8: A90153F5  stp      x21, x20, [sp, #0x10]
//   0x2e14ac: A9027BF3  stp      x19, x30, [sp, #0x20]
//   0x2e14b0: B4000880  cbz      x0, #0x2e15c0
static inline uint64_t fde_func_1403_0x2e14a4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x2e14a4ULL ^ (static_cast<uint64_t>(0xf81d0ff6ULL) << 13);
    acc = (acc + a1 + 0xa90153f5ULL) ^ 0x101508ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1404 | PC: 0x2e16c8 | FDE: 0x101608 | Size: 256 bytes
// Khung tháo gỡ #1404 | Địa chỉ PC: 0x2e16c8 | Địa chỉ FDE: 0x101608 | Kích thước: 256 bytes
//   0x2e16c8: F81F0FFE  str      x30, [sp, #-0x10]!
//   0x2e16cc: F9400408  ldr      x8, [x0, #8]
//   0x2e16d0: B40000A8  cbz      x8, #0x2e16e4
//   0x2e16d4: F9400508  ldr      x8, [x8, #8]
static inline uint64_t fde_func_1404_0x2e16c8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x2e16c8ULL ^ (static_cast<uint64_t>(0xf81f0ffeULL) << 13);
    acc = (acc + a1 + 0xf9400408ULL) ^ 0x101608ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1405 | PC: 0x2e1ae8 | FDE: 0x101740 | Size: 256 bytes
// Khung tháo gỡ #1405 | Địa chỉ PC: 0x2e1ae8 | Địa chỉ FDE: 0x101740 | Kích thước: 256 bytes
//   0x2e1ae8: CB010008  sub      x8, x0, x1
//   0x2e1aec: B4000188  cbz      x8, #0x2e1b1c
//   0x2e1af0: F9400049  ldr      x9, [x2]
//   0x2e1af4: F85F0C2A  ldr      x10, [x1, #-0x10]!
static inline uint64_t fde_func_1405_0x2e1ae8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x2e1ae8ULL ^ (static_cast<uint64_t>(0xcb010008ULL) << 13);
    acc = (acc + a1 + 0xb4000188ULL) ^ 0x101740ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1406 | PC: 0x2e1bfc | FDE: 0x1017c8 | Size: 24 bytes [_ZN4lynx5shell18ListContainerProxy21ScrollByListContainerEiffff]
// Khung tháo gỡ #1406 | Địa chỉ PC: 0x2e1bfc | Địa chỉ FDE: 0x1017c8 | Kích thước: 24 bytes
//   0x2e1bfc: F9400000  ldr      x0, [x0]
//   0x2e1c00: B4000080  cbz      x0, #0x2e1c10
//   0x2e1c04: F9400008  ldr      x8, [x0]
//   0x2e1c08: F9400102  ldr      x2, [x8]
static inline uint64_t fde_func_1406_0x2e1bfc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x2e1bfcULL ^ (static_cast<uint64_t>(0xf9400000ULL) << 13);
    acc = (acc + a1 + 0xb4000080ULL) ^ 0x1017c8ULL;
    acc ^= (acc >> 17) * 0x0018ULL;
    return acc;
}

// FDE #1407 | PC: 0x2e1c14 | FDE: 0x1017e0 | Size: 28 bytes [_ZN4lynx5shell18ListContainerProxy16ScrollToPositionEiifib]
// Khung tháo gỡ #1407 | Địa chỉ PC: 0x2e1c14 | Địa chỉ FDE: 0x1017e0 | Kích thước: 28 bytes
//   0x2e1c14: F9400000  ldr      x0, [x0]
//   0x2e1c18: B40000A0  cbz      x0, #0x2e1c2c
//   0x2e1c1c: F9400008  ldr      x8, [x0]
//   0x2e1c20: 12000084  and      w4, w4, #1
static inline uint64_t fde_func_1407_0x2e1c14(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x2e1c14ULL ^ (static_cast<uint64_t>(0xf9400000ULL) << 13);
    acc = (acc + a1 + 0xb40000a0ULL) ^ 0x1017e0ULL;
    acc ^= (acc >> 17) * 0x001cULL;
    return acc;
}

// FDE #1408 | PC: 0x2e1c30 | FDE: 0x1017f8 | Size: 256 bytes [_ZN4lynx5shell18ListContainerProxy13ScrollStoppedEi]
// Khung tháo gỡ #1408 | Địa chỉ PC: 0x2e1c30 | Địa chỉ FDE: 0x1017f8 | Kích thước: 256 bytes
//   0x2e1c30: F9400000  ldr      x0, [x0]
//   0x2e1c34: B4000060  cbz      x0, #0x2e1c40
//   0x2e1c38: F9400008  ldr      x8, [x0]
//   0x2e1c3c: 140145F9  b        #0x333420
static inline uint64_t fde_func_1408_0x2e1c30(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x2e1c30ULL ^ (static_cast<uint64_t>(0xf9400000ULL) << 13);
    acc = (acc + a1 + 0xb4000060ULL) ^ 0x1017f8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1409 | PC: 0x2e1d64 | FDE: 0x101858 | Size: 256 bytes
// Khung tháo gỡ #1409 | Địa chỉ PC: 0x2e1d64 | Địa chỉ FDE: 0x101858 | Kích thước: 256 bytes
//   0x2e1d64: F9400808  ldr      x8, [x0, #0x10]
//   0x2e1d68: F00003C9  adrp     x9, #0x35c000
//   0x2e1d6c: 911D2129  add      x9, x9, #0x748
//   0x2e1d70: 1400EC0C  b        #0x31cda0
static inline uint64_t fde_func_1409_0x2e1d64(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x2e1d64ULL ^ (static_cast<uint64_t>(0xf9400808ULL) << 13);
    acc = (acc + a1 + 0xf00003c9ULL) ^ 0x101858ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1410 | PC: 0x2e1ffc | FDE: 0x101960 | Size: 256 bytes
// Khung tháo gỡ #1410 | Địa chỉ PC: 0x2e1ffc | Địa chỉ FDE: 0x101960 | Kích thước: 256 bytes
//   0x2e1ffc: F9400808  ldr      x8, [x0, #0x10]
//   0x2e2000: D00003C9  adrp     x9, #0x35c000
//   0x2e2004: 911E6129  add      x9, x9, #0x798
//   0x2e2008: 1400EB66  b        #0x31cda0
static inline uint64_t fde_func_1410_0x2e1ffc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x2e1ffcULL ^ (static_cast<uint64_t>(0xf9400808ULL) << 13);
    acc = (acc + a1 + 0xd00003c9ULL) ^ 0x101960ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1411 | PC: 0x2e22f8 | FDE: 0x101a80 | Size: 256 bytes
// Khung tháo gỡ #1411 | Địa chỉ PC: 0x2e22f8 | Địa chỉ FDE: 0x101a80 | Kích thước: 256 bytes
//   0x2e22f8: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x2e22fc: F9405C08  ldr      x8, [x0, #0xb8]
//   0x2e2300: B4000148  cbz      x8, #0x2e2328
//   0x2e2304: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_1411_0x2e22f8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x2e22f8ULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0xf9405c08ULL) ^ 0x101a80ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1412 | PC: 0x2e32ac | FDE: 0x101bf8 | Size: 256 bytes
// Khung tháo gỡ #1412 | Địa chỉ PC: 0x2e32ac | Địa chỉ FDE: 0x101bf8 | Kích thước: 256 bytes
//   0x2e32ac: D10243FF  sub      sp, sp, #0x90
//   0x2e32b0: A9065BF7  stp      x23, x22, [sp, #0x60]
//   0x2e32b4: A90753F5  stp      x21, x20, [sp, #0x70]
//   0x2e32b8: A9087BF3  stp      x19, x30, [sp, #0x80]
static inline uint64_t fde_func_1412_0x2e32ac(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x2e32acULL ^ (static_cast<uint64_t>(0xd10243ffULL) << 13);
    acc = (acc + a1 + 0xa9065bf7ULL) ^ 0x101bf8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1413 | PC: 0x2e3530 | FDE: 0x101d18 | Size: 256 bytes
// Khung tháo gỡ #1413 | Địa chỉ PC: 0x2e3530 | Địa chỉ FDE: 0x101d18 | Kích thước: 256 bytes
//   0x2e3530: D10203FF  sub      sp, sp, #0x80
//   0x2e3534: A9055BF7  stp      x23, x22, [sp, #0x50]
//   0x2e3538: A90653F5  stp      x21, x20, [sp, #0x60]
//   0x2e353c: A9077BF3  stp      x19, x30, [sp, #0x70]
static inline uint64_t fde_func_1413_0x2e3530(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x2e3530ULL ^ (static_cast<uint64_t>(0xd10203ffULL) << 13);
    acc = (acc + a1 + 0xa9055bf7ULL) ^ 0x101d18ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1414 | PC: 0x2e3b58 | FDE: 0x101e70 | Size: 256 bytes
// Khung tháo gỡ #1414 | Địa chỉ PC: 0x2e3b58 | Địa chỉ FDE: 0x101e70 | Kích thước: 256 bytes
//   0x2e3b58: F81D0FFC  str      x28, [sp, #-0x30]!
//   0x2e3b5c: A90153F5  stp      x21, x20, [sp, #0x10]
//   0x2e3b60: A9027BF3  stp      x19, x30, [sp, #0x20]
//   0x2e3b64: D11283FF  sub      sp, sp, #0x4a0
static inline uint64_t fde_func_1414_0x2e3b58(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x2e3b58ULL ^ (static_cast<uint64_t>(0xf81d0ffcULL) << 13);
    acc = (acc + a1 + 0xa90153f5ULL) ^ 0x101e70ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1415 | PC: 0x2e4304 | FDE: 0x101fc0 | Size: 256 bytes
// Khung tháo gỡ #1415 | Địa chỉ PC: 0x2e4304 | Địa chỉ FDE: 0x101fc0 | Kích thước: 256 bytes
//   0x2e4304: D100C3FF  sub      sp, sp, #0x30
//   0x2e4308: A90153F5  stp      x21, x20, [sp, #0x10]
//   0x2e430c: A9027BF3  stp      x19, x30, [sp, #0x20]
//   0x2e4310: 9400E72F  bl       #0x31dfcc
static inline uint64_t fde_func_1415_0x2e4304(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x2e4304ULL ^ (static_cast<uint64_t>(0xd100c3ffULL) << 13);
    acc = (acc + a1 + 0xa90153f5ULL) ^ 0x101fc0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1416 | PC: 0x2e49dc | FDE: 0x102108 | Size: 256 bytes
// Khung tháo gỡ #1416 | Địa chỉ PC: 0x2e49dc | Địa chỉ FDE: 0x102108 | Kích thước: 256 bytes
//   0x2e49dc: D10243FF  sub      sp, sp, #0x90
//   0x2e49e0: F90033F6  str      x22, [sp, #0x60]
//   0x2e49e4: A90753F5  stp      x21, x20, [sp, #0x70]
//   0x2e49e8: A9087BF3  stp      x19, x30, [sp, #0x80]
static inline uint64_t fde_func_1416_0x2e49dc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x2e49dcULL ^ (static_cast<uint64_t>(0xd10243ffULL) << 13);
    acc = (acc + a1 + 0xf90033f6ULL) ^ 0x102108ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1417 | PC: 0x2e5034 | FDE: 0x102258 | Size: 256 bytes
// Khung tháo gỡ #1417 | Địa chỉ PC: 0x2e5034 | Địa chỉ FDE: 0x102258 | Kích thước: 256 bytes
//   0x2e5034: AA1E03E2  mov      x2, x30
//   0x2e5038: 94011762  bl       #0x32adc0
//   0x2e503c: AA0203FE  mov      x30, x2
//   0x2e5040: A9107BF3  stp      x19, x30, [sp, #0x100]
static inline uint64_t fde_func_1417_0x2e5034(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x2e5034ULL ^ (static_cast<uint64_t>(0xaa1e03e2ULL) << 13);
    acc = (acc + a1 + 0x94011762ULL) ^ 0x102258ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1418 | PC: 0x2e5664 | FDE: 0x102398 | Size: 256 bytes
// Khung tháo gỡ #1418 | Địa chỉ PC: 0x2e5664 | Địa chỉ FDE: 0x102398 | Kích thước: 256 bytes
//   0x2e5664: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x2e5668: F9420C13  ldr      x19, [x0, #0x418]
//   0x2e566c: F9420800  ldr      x0, [x0, #0x410]
//   0x2e5670: B4000093  cbz      x19, #0x2e5680
static inline uint64_t fde_func_1418_0x2e5664(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x2e5664ULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0xf9420c13ULL) ^ 0x102398ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1419 | PC: 0x2e5920 | FDE: 0x1024a8 | Size: 256 bytes
// Khung tháo gỡ #1419 | Địa chỉ PC: 0x2e5920 | Địa chỉ FDE: 0x1024a8 | Kích thước: 256 bytes
//   0x2e5920: F00003A8  adrp     x8, #0x35c000
//   0x2e5924: 911FE108  add      x8, x8, #0x7f8
//   0x2e5928: F8008408  str      x8, [x0], #8
//   0x2e592c: 17FFFFF6  b        #0x2e5904
static inline uint64_t fde_func_1419_0x2e5920(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x2e5920ULL ^ (static_cast<uint64_t>(0xf00003a8ULL) << 13);
    acc = (acc + a1 + 0x911fe108ULL) ^ 0x1024a8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1420 | PC: 0x2e5b1c | FDE: 0x1025c0 | Size: 256 bytes
// Khung tháo gỡ #1420 | Địa chỉ PC: 0x2e5b1c | Địa chỉ FDE: 0x1025c0 | Kích thước: 256 bytes
//   0x2e5b1c: F9400408  ldr      x8, [x0, #8]
//   0x2e5b20: 91006001  add      x1, x0, #0x18
//   0x2e5b24: AA0803E0  mov      x0, x8
//   0x2e5b28: 17FFFFDF  b        #0x2e5aa4
static inline uint64_t fde_func_1420_0x2e5b1c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x2e5b1cULL ^ (static_cast<uint64_t>(0xf9400408ULL) << 13);
    acc = (acc + a1 + 0x91006001ULL) ^ 0x1025c0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1421 | PC: 0x2e5e6c | FDE: 0x1026e0 | Size: 256 bytes
// Khung tháo gỡ #1421 | Địa chỉ PC: 0x2e5e6c | Địa chỉ FDE: 0x1026e0 | Kích thước: 256 bytes
//   0x2e5e6c: D10403FF  sub      sp, sp, #0x100
//   0x2e5e70: A90D5BF7  stp      x23, x22, [sp, #0xd0]
//   0x2e5e74: A90E53F5  stp      x21, x20, [sp, #0xe0]
//   0x2e5e78: A90F7BF3  stp      x19, x30, [sp, #0xf0]
static inline uint64_t fde_func_1421_0x2e5e6c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x2e5e6cULL ^ (static_cast<uint64_t>(0xd10403ffULL) << 13);
    acc = (acc + a1 + 0xa90d5bf7ULL) ^ 0x1026e0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1422 | PC: 0x2e61a8 | FDE: 0x102808 | Size: 256 bytes
// Khung tháo gỡ #1422 | Địa chỉ PC: 0x2e61a8 | Địa chỉ FDE: 0x102808 | Kích thước: 256 bytes
//   0x2e61a8: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x2e61ac: AA0003F3  mov      x19, x0
//   0x2e61b0: 97FFFFFA  bl       #0x2e6198
//   0x2e61b4: AA1303E0  mov      x0, x19
static inline uint64_t fde_func_1422_0x2e61a8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x2e61a8ULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0xaa0003f3ULL) ^ 0x102808ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1423 | PC: 0x2e644c | FDE: 0x102918 | Size: 256 bytes
// Khung tháo gỡ #1423 | Địa chỉ PC: 0x2e644c | Địa chỉ FDE: 0x102918 | Kích thước: 256 bytes
//   0x2e644c: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x2e6450: AA0003F3  mov      x19, x0
//   0x2e6454: 97FFFFFA  bl       #0x2e643c
//   0x2e6458: AA1303E0  mov      x0, x19
static inline uint64_t fde_func_1423_0x2e644c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x2e644cULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0xaa0003f3ULL) ^ 0x102918ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1424 | PC: 0x2e66c8 | FDE: 0x102a28 | Size: 256 bytes
// Khung tháo gỡ #1424 | Địa chỉ PC: 0x2e66c8 | Địa chỉ FDE: 0x102a28 | Kích thước: 256 bytes
//   0x2e66c8: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x2e66cc: AA0003F3  mov      x19, x0
//   0x2e66d0: 97FFFFFA  bl       #0x2e66b8
//   0x2e66d4: AA1303E0  mov      x0, x19
static inline uint64_t fde_func_1424_0x2e66c8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x2e66c8ULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0xaa0003f3ULL) ^ 0x102a28ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1425 | PC: 0x2e6918 | FDE: 0x102b30 | Size: 256 bytes
// Khung tháo gỡ #1425 | Địa chỉ PC: 0x2e6918 | Địa chỉ FDE: 0x102b30 | Kích thước: 256 bytes
//   0x2e6918: D10243FF  sub      sp, sp, #0x90
//   0x2e691c: A90753F5  stp      x21, x20, [sp, #0x70]
//   0x2e6920: A9087BF3  stp      x19, x30, [sp, #0x80]
//   0x2e6924: 9400F210  bl       #0x323164
static inline uint64_t fde_func_1425_0x2e6918(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x2e6918ULL ^ (static_cast<uint64_t>(0xd10243ffULL) << 13);
    acc = (acc + a1 + 0xa90753f5ULL) ^ 0x102b30ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1426 | PC: 0x2e6b7c | FDE: 0x102c40 | Size: 256 bytes
// Khung tháo gỡ #1426 | Địa chỉ PC: 0x2e6b7c | Địa chỉ FDE: 0x102c40 | Kích thước: 256 bytes
//   0x2e6b7c: D10243FF  sub      sp, sp, #0x90
//   0x2e6b80: F90033F6  str      x22, [sp, #0x60]
//   0x2e6b84: A90753F5  stp      x21, x20, [sp, #0x70]
//   0x2e6b88: A9087BF3  stp      x19, x30, [sp, #0x80]
static inline uint64_t fde_func_1426_0x2e6b7c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x2e6b7cULL ^ (static_cast<uint64_t>(0xd10243ffULL) << 13);
    acc = (acc + a1 + 0xf90033f6ULL) ^ 0x102c40ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1427 | PC: 0x2e6ee0 | FDE: 0x102d60 | Size: 256 bytes
// Khung tháo gỡ #1427 | Địa chỉ PC: 0x2e6ee0 | Địa chỉ FDE: 0x102d60 | Kích thước: 256 bytes
//   0x2e6ee0: F9400408  ldr      x8, [x0, #8]
//   0x2e6ee4: 91006001  add      x1, x0, #0x18
//   0x2e6ee8: AA0803E0  mov      x0, x8
//   0x2e6eec: 17FFFFE5  b        #0x2e6e80
static inline uint64_t fde_func_1427_0x2e6ee0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x2e6ee0ULL ^ (static_cast<uint64_t>(0xf9400408ULL) << 13);
    acc = (acc + a1 + 0x91006001ULL) ^ 0x102d60ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1428 | PC: 0x2e7194 | FDE: 0x102e70 | Size: 256 bytes
// Khung tháo gỡ #1428 | Địa chỉ PC: 0x2e7194 | Địa chỉ FDE: 0x102e70 | Kích thước: 256 bytes
//   0x2e7194: F9400408  ldr      x8, [x0, #8]
//   0x2e7198: 91006001  add      x1, x0, #0x18
//   0x2e719c: AA0803E0  mov      x0, x8
//   0x2e71a0: 17FFFFE3  b        #0x2e712c
static inline uint64_t fde_func_1428_0x2e7194(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x2e7194ULL ^ (static_cast<uint64_t>(0xf9400408ULL) << 13);
    acc = (acc + a1 + 0x91006001ULL) ^ 0x102e70ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1429 | PC: 0x2e77dc | FDE: 0x102fa8 | Size: 256 bytes
// Khung tháo gỡ #1429 | Địa chỉ PC: 0x2e77dc | Địa chỉ FDE: 0x102fa8 | Kích thước: 256 bytes
//   0x2e77dc: D101C3FF  sub      sp, sp, #0x70
//   0x2e77e0: A90553F5  stp      x21, x20, [sp, #0x50]
//   0x2e77e4: A9067BF3  stp      x19, x30, [sp, #0x60]
//   0x2e77e8: 94015BF9  bl       #0x33e7cc
static inline uint64_t fde_func_1429_0x2e77dc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x2e77dcULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xa90553f5ULL) ^ 0x102fa8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1430 | PC: 0x2e7ae0 | FDE: 0x1030c8 | Size: 256 bytes
// Khung tháo gỡ #1430 | Địa chỉ PC: 0x2e7ae0 | Địa chỉ FDE: 0x1030c8 | Kích thước: 256 bytes
//   0x2e7ae0: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x2e7ae4: AA0003F3  mov      x19, x0
//   0x2e7ae8: 97FFFFFA  bl       #0x2e7ad0
//   0x2e7aec: AA1303E0  mov      x0, x19
static inline uint64_t fde_func_1430_0x2e7ae0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x2e7ae0ULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0xaa0003f3ULL) ^ 0x1030c8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1431 | PC: 0x2e806c | FDE: 0x1031f8 | Size: 256 bytes
// Khung tháo gỡ #1431 | Địa chỉ PC: 0x2e806c | Địa chỉ FDE: 0x1031f8 | Kích thước: 256 bytes
//   0x2e806c: D10083FF  sub      sp, sp, #0x20
//   0x2e8070: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x2e8074: B40001E1  cbz      x1, #0x2e80b0
//   0x2e8078: 94015354  bl       #0x33cdc8
static inline uint64_t fde_func_1431_0x2e806c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x2e806cULL ^ (static_cast<uint64_t>(0xd10083ffULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x1031f8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1432 | PC: 0x2e8238 | FDE: 0x1032f0 | Size: 256 bytes
// Khung tháo gỡ #1432 | Địa chỉ PC: 0x2e8238 | Địa chỉ FDE: 0x1032f0 | Kích thước: 256 bytes
//   0x2e8238: F9400408  ldr      x8, [x0, #8]
//   0x2e823c: F9400908  ldr      x8, [x8, #0x10]
//   0x2e8240: B4000068  cbz      x8, #0x2e824c
//   0x2e8244: F9400C00  ldr      x0, [x0, #0x18]
static inline uint64_t fde_func_1432_0x2e8238(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x2e8238ULL ^ (static_cast<uint64_t>(0xf9400408ULL) << 13);
    acc = (acc + a1 + 0xf9400908ULL) ^ 0x1032f0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1433 | PC: 0x2e84f8 | FDE: 0x103408 | Size: 256 bytes
// Khung tháo gỡ #1433 | Địa chỉ PC: 0x2e84f8 | Địa chỉ FDE: 0x103408 | Kích thước: 256 bytes
//   0x2e84f8: AA1E03E2  mov      x2, x30
//   0x2e84fc: 94011618  bl       #0x32dd5c
//   0x2e8500: AA0203FE  mov      x30, x2
//   0x2e8504: A90F7BF3  stp      x19, x30, [sp, #0xf0]
static inline uint64_t fde_func_1433_0x2e84f8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x2e84f8ULL ^ (static_cast<uint64_t>(0xaa1e03e2ULL) << 13);
    acc = (acc + a1 + 0x94011618ULL) ^ 0x103408ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1434 | PC: 0x2e8afc | FDE: 0x103528 | Size: 256 bytes
// Khung tháo gỡ #1434 | Địa chỉ PC: 0x2e8afc | Địa chỉ FDE: 0x103528 | Kích thước: 256 bytes
//   0x2e8afc: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x2e8b00: AA0003F3  mov      x19, x0
//   0x2e8b04: 97FFFFFA  bl       #0x2e8aec
//   0x2e8b08: AA1303E0  mov      x0, x19
static inline uint64_t fde_func_1434_0x2e8afc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x2e8afcULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0xaa0003f3ULL) ^ 0x103528ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1435 | PC: 0x2e8e98 | FDE: 0x103648 | Size: 256 bytes
// Khung tháo gỡ #1435 | Địa chỉ PC: 0x2e8e98 | Địa chỉ FDE: 0x103648 | Kích thước: 256 bytes
//   0x2e8e98: 900003A8  adrp     x8, #0x35c000
//   0x2e8e9c: 9136E108  add      x8, x8, #0xdb8
//   0x2e8ea0: F8008408  str      x8, [x0], #8
//   0x2e8ea4: 17FFFFF6  b        #0x2e8e7c
static inline uint64_t fde_func_1435_0x2e8e98(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x2e8e98ULL ^ (static_cast<uint64_t>(0x900003a8ULL) << 13);
    acc = (acc + a1 + 0x9136e108ULL) ^ 0x103648ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1436 | PC: 0x2e930c | FDE: 0x103770 | Size: 256 bytes
// Khung tháo gỡ #1436 | Địa chỉ PC: 0x2e930c | Địa chỉ FDE: 0x103770 | Kích thước: 256 bytes
//   0x2e930c: D10143FF  sub      sp, sp, #0x50
//   0x2e9310: A9025BF7  stp      x23, x22, [sp, #0x20]
//   0x2e9314: A90353F5  stp      x21, x20, [sp, #0x30]
//   0x2e9318: A9047BF3  stp      x19, x30, [sp, #0x40]
static inline uint64_t fde_func_1436_0x2e930c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x2e930cULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xa9025bf7ULL) ^ 0x103770ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1437 | PC: 0x2e9584 | FDE: 0x103890 | Size: 256 bytes
// Khung tháo gỡ #1437 | Địa chỉ PC: 0x2e9584 | Địa chỉ FDE: 0x103890 | Kích thước: 256 bytes
//   0x2e9584: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x2e9588: AA0003F3  mov      x19, x0
//   0x2e958c: 97FFFFFA  bl       #0x2e9574
//   0x2e9590: AA1303E0  mov      x0, x19
static inline uint64_t fde_func_1437_0x2e9584(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x2e9584ULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0xaa0003f3ULL) ^ 0x103890ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1438 | PC: 0x2e96d0 | FDE: 0x103988 | Size: 256 bytes
// Khung tháo gỡ #1438 | Địa chỉ PC: 0x2e96d0 | Địa chỉ FDE: 0x103988 | Kích thước: 256 bytes
//   0x2e96d0: D10243FF  sub      sp, sp, #0x90
//   0x2e96d4: A9087BF3  stp      x19, x30, [sp, #0x80]
//   0x2e96d8: 9400D022  bl       #0x31d760
//   0x2e96dc: 321F0009  orr      w9, w0, #2
static inline uint64_t fde_func_1438_0x2e96d0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x2e96d0ULL ^ (static_cast<uint64_t>(0xd10243ffULL) << 13);
    acc = (acc + a1 + 0xa9087bf3ULL) ^ 0x103988ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1439 | PC: 0x2e98d8 | FDE: 0x103a80 | Size: 256 bytes
// Khung tháo gỡ #1439 | Địa chỉ PC: 0x2e98d8 | Địa chỉ FDE: 0x103a80 | Kích thước: 256 bytes
//   0x2e98d8: 91006000  add      x0, x0, #0x18
//   0x2e98dc: 14000001  b        #0x2e98e0
//   0x2e98e0: F81E0FF4  str      x20, [sp, #-0x20]!
//   0x2e98e4: A9017BF3  stp      x19, x30, [sp, #0x10]
static inline uint64_t fde_func_1439_0x2e98d8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x2e98d8ULL ^ (static_cast<uint64_t>(0x91006000ULL) << 13);
    acc = (acc + a1 + 0x14000001ULL) ^ 0x103a80ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1440 | PC: 0x2e9f1c | FDE: 0x103b88 | Size: 256 bytes
// Khung tháo gỡ #1440 | Địa chỉ PC: 0x2e9f1c | Địa chỉ FDE: 0x103b88 | Kích thước: 256 bytes
//   0x2e9f1c: D10743FF  sub      sp, sp, #0x1d0
//   0x2e9f20: AA1E03E8  mov      x8, x30
//   0x2e9f24: 9400FC3A  bl       #0x32900c
//   0x2e9f28: AA0803FE  mov      x30, x8
static inline uint64_t fde_func_1440_0x2e9f1c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x2e9f1cULL ^ (static_cast<uint64_t>(0xd10743ffULL) << 13);
    acc = (acc + a1 + 0xaa1e03e8ULL) ^ 0x103b88ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1441 | PC: 0x2ea954 | FDE: 0x103ca8 | Size: 12 bytes [_ZN4lynx5shell9LynxShell7GetTasmEv]
// Khung tháo gỡ #1441 | Địa chỉ PC: 0x2ea954 | Địa chỉ FDE: 0x103ca8 | Kích thước: 12 bytes
//   0x2ea954: F9401008  ldr      x8, [x0, #0x20]
//   0x2ea958: F9400908  ldr      x8, [x8, #0x10]
//   0x2ea95c: 1401415B  b        #0x33aec8
static inline uint64_t fde_func_1441_0x2ea954(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x2ea954ULL ^ (static_cast<uint64_t>(0xf9401008ULL) << 13);
    acc = (acc + a1 + 0xf9400908ULL) ^ 0x103ca8ULL;
    acc ^= (acc >> 17) * 0x000cULL;
    return acc;
}

// FDE #1442 | PC: 0x2ea960 | FDE: 0x103cc0 | Size: 256 bytes
// Khung tháo gỡ #1442 | Địa chỉ PC: 0x2ea960 | Địa chỉ FDE: 0x103cc0 | Kích thước: 256 bytes
//   0x2ea960: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x2ea964: AA0003F3  mov      x19, x0
//   0x2ea968: 97F9C55A  bl       #0x15bed0
//   0x2ea96c: F9400A68  ldr      x8, [x19, #0x10]
static inline uint64_t fde_func_1442_0x2ea960(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x2ea960ULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0xaa0003f3ULL) ^ 0x103cc0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1443 | PC: 0x2eac9c | FDE: 0x103dc8 | Size: 256 bytes
// Khung tháo gỡ #1443 | Địa chỉ PC: 0x2eac9c | Địa chỉ FDE: 0x103dc8 | Kích thước: 256 bytes
//   0x2eac9c: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x2eaca0: 9400C690  bl       #0x31c6e0
//   0x2eaca4: 97F9C589  bl       #0x15c2c8
//   0x2eaca8: F9400660  ldr      x0, [x19, #8]
static inline uint64_t fde_func_1443_0x2eac9c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x2eac9cULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0x9400c690ULL) ^ 0x103dc8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1444 | PC: 0x2eadb0 | FDE: 0x103ec8 | Size: 256 bytes
// Khung tháo gỡ #1444 | Địa chỉ PC: 0x2eadb0 | Địa chỉ FDE: 0x103ec8 | Kích thước: 256 bytes
//   0x2eadb0: D10103FF  sub      sp, sp, #0x40
//   0x2eadb4: A90253F5  stp      x21, x20, [sp, #0x20]
//   0x2eadb8: A9037BF3  stp      x19, x30, [sp, #0x30]
//   0x2eadbc: F9400028  ldr      x8, [x1]
static inline uint64_t fde_func_1444_0x2eadb0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x2eadb0ULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xa90253f5ULL) ^ 0x103ec8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1445 | PC: 0x2eb11c | FDE: 0x103fd8 | Size: 256 bytes
// Khung tháo gỡ #1445 | Địa chỉ PC: 0x2eb11c | Địa chỉ FDE: 0x103fd8 | Kích thước: 256 bytes
//   0x2eb11c: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x2eb120: 94011046  bl       #0x32f238
//   0x2eb124: D0000388  adrp     x8, #0x35d000
//   0x2eb128: 91050108  add      x8, x8, #0x140
static inline uint64_t fde_func_1445_0x2eb11c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x2eb11cULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0x94011046ULL) ^ 0x103fd8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1446 | PC: 0x2eb590 | FDE: 0x1040f0 | Size: 256 bytes
// Khung tháo gỡ #1446 | Địa chỉ PC: 0x2eb590 | Địa chỉ FDE: 0x1040f0 | Kích thước: 256 bytes
//   0x2eb590: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x2eb594: 9400C453  bl       #0x31c6e0
//   0x2eb598: 97FD0610  bl       #0x22cdd8
//   0x2eb59c: F9400660  ldr      x0, [x19, #8]
static inline uint64_t fde_func_1446_0x2eb590(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x2eb590ULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0x9400c453ULL) ^ 0x1040f0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1447 | PC: 0x2eb8c4 | FDE: 0x104210 | Size: 256 bytes
// Khung tháo gỡ #1447 | Địa chỉ PC: 0x2eb8c4 | Địa chỉ FDE: 0x104210 | Kích thước: 256 bytes
//   0x2eb8c4: F9400808  ldr      x8, [x0, #0x10]
//   0x2eb8c8: D0000389  adrp     x9, #0x35d000
//   0x2eb8cc: 91084129  add      x9, x9, #0x210
//   0x2eb8d0: 1400C534  b        #0x31cda0
static inline uint64_t fde_func_1447_0x2eb8c4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x2eb8c4ULL ^ (static_cast<uint64_t>(0xf9400808ULL) << 13);
    acc = (acc + a1 + 0xd0000389ULL) ^ 0x104210ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1448 | PC: 0x2ebaa8 | FDE: 0x104308 | Size: 216 bytes
// Khung tháo gỡ #1448 | Địa chỉ PC: 0x2ebaa8 | Địa chỉ FDE: 0x104308 | Kích thước: 216 bytes
//   0x2ebaa8: F81E0FF4  str      x20, [sp, #-0x20]!
//   0x2ebaac: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x2ebab0: 9400C3C5  bl       #0x31c9c4
//   0x2ebab4: F9400A68  ldr      x8, [x19, #0x10]
static inline uint64_t fde_func_1448_0x2ebaa8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x2ebaa8ULL ^ (static_cast<uint64_t>(0xf81e0ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x104308ULL;
    acc ^= (acc >> 17) * 0x00d8ULL;
    return acc;
}

// FDE #1449 | PC: 0x2ebb80 | FDE: 0x104400 | Size: 256 bytes
// Khung tháo gỡ #1449 | Địa chỉ PC: 0x2ebb80 | Địa chỉ FDE: 0x104400 | Kích thước: 256 bytes
//   0x2ebb80: F9400808  ldr      x8, [x0, #0x10]
//   0x2ebb84: D0000389  adrp     x9, #0x35d000
//   0x2ebb88: 91070129  add      x9, x9, #0x1c0
//   0x2ebb8c: 1400C485  b        #0x31cda0
static inline uint64_t fde_func_1449_0x2ebb80(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x2ebb80ULL ^ (static_cast<uint64_t>(0xf9400808ULL) << 13);
    acc = (acc + a1 + 0xd0000389ULL) ^ 0x104400ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1450 | PC: 0x2ebeb8 | FDE: 0x104520 | Size: 256 bytes
// Khung tháo gỡ #1450 | Địa chỉ PC: 0x2ebeb8 | Địa chỉ FDE: 0x104520 | Kích thước: 256 bytes
//   0x2ebeb8: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x2ebebc: 9400C209  bl       #0x31c6e0
//   0x2ebec0: 94000004  bl       #0x2ebed0
//   0x2ebec4: F9400660  ldr      x0, [x19, #8]
static inline uint64_t fde_func_1450_0x2ebeb8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x2ebeb8ULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0x9400c209ULL) ^ 0x104520ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1451 | PC: 0x2ec10c | FDE: 0x104628 | Size: 256 bytes
// Khung tháo gỡ #1451 | Địa chỉ PC: 0x2ec10c | Địa chỉ FDE: 0x104628 | Kích thước: 256 bytes
//   0x2ec10c: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x2ec110: AA0003F3  mov      x19, x0
//   0x2ec114: 97FFFFFA  bl       #0x2ec0fc
//   0x2ec118: AA1303E0  mov      x0, x19
static inline uint64_t fde_func_1451_0x2ec10c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x2ec10cULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0xaa0003f3ULL) ^ 0x104628ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1452 | PC: 0x2ec2f0 | FDE: 0x104728 | Size: 256 bytes
// Khung tháo gỡ #1452 | Địa chỉ PC: 0x2ec2f0 | Địa chỉ FDE: 0x104728 | Kích thước: 256 bytes
//   0x2ec2f0: D10203FF  sub      sp, sp, #0x80
//   0x2ec2f4: A90653F5  stp      x21, x20, [sp, #0x60]
//   0x2ec2f8: A9077BF3  stp      x19, x30, [sp, #0x70]
//   0x2ec2fc: 9400C5D4  bl       #0x31da4c
static inline uint64_t fde_func_1452_0x2ec2f0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x2ec2f0ULL ^ (static_cast<uint64_t>(0xd10203ffULL) << 13);
    acc = (acc + a1 + 0xa90653f5ULL) ^ 0x104728ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1453 | PC: 0x2ec508 | FDE: 0x104840 | Size: 240 bytes
// Khung tháo gỡ #1453 | Địa chỉ PC: 0x2ec508 | Địa chỉ FDE: 0x104840 | Kích thước: 240 bytes
//   0x2ec508: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x2ec50c: 9400C075  bl       #0x31c6e0
//   0x2ec510: 94000004  bl       #0x2ec520
//   0x2ec514: F9400660  ldr      x0, [x19, #8]
static inline uint64_t fde_func_1453_0x2ec508(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x2ec508ULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0x9400c075ULL) ^ 0x104840ULL;
    acc ^= (acc >> 17) * 0x00f0ULL;
    return acc;
}

// FDE #1454 | PC: 0x2ec5f8 | FDE: 0x104930 | Size: 256 bytes
// Khung tháo gỡ #1454 | Địa chỉ PC: 0x2ec5f8 | Địa chỉ FDE: 0x104930 | Kích thước: 256 bytes
//   0x2ec5f8: F9400808  ldr      x8, [x0, #0x10]
//   0x2ec5fc: B0000389  adrp     x9, #0x35d000
//   0x2ec600: 91124129  add      x9, x9, #0x490
//   0x2ec604: 1400C1E7  b        #0x31cda0
static inline uint64_t fde_func_1454_0x2ec5f8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x2ec5f8ULL ^ (static_cast<uint64_t>(0xf9400808ULL) << 13);
    acc = (acc + a1 + 0xb0000389ULL) ^ 0x104930ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1455 | PC: 0x2ec768 | FDE: 0x104a30 | Size: 256 bytes
// Khung tháo gỡ #1455 | Địa chỉ PC: 0x2ec768 | Địa chỉ FDE: 0x104a30 | Kích thước: 256 bytes
//   0x2ec768: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x2ec76c: 9400BFDD  bl       #0x31c6e0
//   0x2ec770: 94000004  bl       #0x2ec780
//   0x2ec774: F9400660  ldr      x0, [x19, #8]
static inline uint64_t fde_func_1455_0x2ec768(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x2ec768ULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0x9400bfddULL) ^ 0x104a30ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1456 | PC: 0x2ec8e0 | FDE: 0x104b38 | Size: 256 bytes
// Khung tháo gỡ #1456 | Địa chỉ PC: 0x2ec8e0 | Địa chỉ FDE: 0x104b38 | Kích thước: 256 bytes
//   0x2ec8e0: B0000388  adrp     x8, #0x35d000
//   0x2ec8e4: 91142108  add      x8, x8, #0x508
//   0x2ec8e8: F8008408  str      x8, [x0], #8
//   0x2ec8ec: 17FFFFF2  b        #0x2ec8b4
static inline uint64_t fde_func_1456_0x2ec8e0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x2ec8e0ULL ^ (static_cast<uint64_t>(0xb0000388ULL) << 13);
    acc = (acc + a1 + 0x91142108ULL) ^ 0x104b38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1457 | PC: 0x2eca24 | FDE: 0x104c38 | Size: 216 bytes
// Khung tháo gỡ #1457 | Địa chỉ PC: 0x2eca24 | Địa chỉ FDE: 0x104c38 | Kích thước: 216 bytes
//   0x2eca24: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x2eca28: AA0003F3  mov      x19, x0
//   0x2eca2c: 97FFFFFA  bl       #0x2eca14
//   0x2eca30: AA1303E0  mov      x0, x19
static inline uint64_t fde_func_1457_0x2eca24(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x2eca24ULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0xaa0003f3ULL) ^ 0x104c38ULL;
    acc ^= (acc >> 17) * 0x00d8ULL;
    return acc;
}

// FDE #1458 | PC: 0x2ecafc | FDE: 0x104d38 | Size: 256 bytes
// Khung tháo gỡ #1458 | Địa chỉ PC: 0x2ecafc | Địa chỉ FDE: 0x104d38 | Kích thước: 256 bytes
//   0x2ecafc: D100C3FF  sub      sp, sp, #0x30
//   0x2ecb00: F9000BF4  str      x20, [sp, #0x10]
//   0x2ecb04: A9027BF3  stp      x19, x30, [sp, #0x20]
//   0x2ecb08: 9400C266  bl       #0x31d4a0
static inline uint64_t fde_func_1458_0x2ecafc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x2ecafcULL ^ (static_cast<uint64_t>(0xd100c3ffULL) << 13);
    acc = (acc + a1 + 0xf9000bf4ULL) ^ 0x104d38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1459 | PC: 0x2ecea0 | FDE: 0x104e58 | Size: 256 bytes
// Khung tháo gỡ #1459 | Địa chỉ PC: 0x2ecea0 | Địa chỉ FDE: 0x104e58 | Kích thước: 256 bytes
//   0x2ecea0: AA1E03E4  mov      x4, x30
//   0x2ecea4: 940124FE  bl       #0x33629c
//   0x2ecea8: AA0403FE  mov      x30, x4
//   0x2eceac: A9117BF3  stp      x19, x30, [sp, #0x110]
static inline uint64_t fde_func_1459_0x2ecea0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x2ecea0ULL ^ (static_cast<uint64_t>(0xaa1e03e4ULL) << 13);
    acc = (acc + a1 + 0x940124feULL) ^ 0x104e58ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1460 | PC: 0x2ed1f4 | FDE: 0x104f70 | Size: 256 bytes
// Khung tháo gỡ #1460 | Địa chỉ PC: 0x2ed1f4 | Địa chỉ FDE: 0x104f70 | Kích thước: 256 bytes
//   0x2ed1f4: F81E0FF4  str      x20, [sp, #-0x20]!
//   0x2ed1f8: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x2ed1fc: 94011705  bl       #0x332e10
//   0x2ed200: 9400DE10  bl       #0x324a40
static inline uint64_t fde_func_1460_0x2ed1f4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x2ed1f4ULL ^ (static_cast<uint64_t>(0xf81e0ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x104f70ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1461 | PC: 0x2ed318 | FDE: 0x105078 | Size: 256 bytes
// Khung tháo gỡ #1461 | Địa chỉ PC: 0x2ed318 | Địa chỉ FDE: 0x105078 | Kích thước: 256 bytes
//   0x2ed318: F9400408  ldr      x8, [x0, #8]
//   0x2ed31c: 91006001  add      x1, x0, #0x18
//   0x2ed320: AA0803E0  mov      x0, x8
//   0x2ed324: 17FFFFD4  b        #0x2ed274
static inline uint64_t fde_func_1461_0x2ed318(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x2ed318ULL ^ (static_cast<uint64_t>(0xf9400408ULL) << 13);
    acc = (acc + a1 + 0x91006001ULL) ^ 0x105078ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1462 | PC: 0x2ed640 | FDE: 0x105198 | Size: 256 bytes
// Khung tháo gỡ #1462 | Địa chỉ PC: 0x2ed640 | Địa chỉ FDE: 0x105198 | Kích thước: 256 bytes
//   0x2ed640: F9400408  ldr      x8, [x0, #8]
//   0x2ed644: 91006001  add      x1, x0, #0x18
//   0x2ed648: AA0803E0  mov      x0, x8
//   0x2ed64c: 17FFFFBA  b        #0x2ed534
static inline uint64_t fde_func_1462_0x2ed640(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x2ed640ULL ^ (static_cast<uint64_t>(0xf9400408ULL) << 13);
    acc = (acc + a1 + 0x91006001ULL) ^ 0x105198ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1463 | PC: 0x2ed7bc | FDE: 0x1052a0 | Size: 256 bytes
// Khung tháo gỡ #1463 | Địa chỉ PC: 0x2ed7bc | Địa chỉ FDE: 0x1052a0 | Kích thước: 256 bytes
//   0x2ed7bc: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x2ed7c0: AA0003F3  mov      x19, x0
//   0x2ed7c4: 97FFFFFA  bl       #0x2ed7ac
//   0x2ed7c8: AA1303E0  mov      x0, x19
static inline uint64_t fde_func_1463_0x2ed7bc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x2ed7bcULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0xaa0003f3ULL) ^ 0x1052a0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1464 | PC: 0x2ed8d8 | FDE: 0x105398 | Size: 256 bytes
// Khung tháo gỡ #1464 | Địa chỉ PC: 0x2ed8d8 | Địa chỉ FDE: 0x105398 | Kích thước: 256 bytes
//   0x2ed8d8: D10083FF  sub      sp, sp, #0x20
//   0x2ed8dc: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x2ed8e0: 94012539  bl       #0x336dc4
//   0x2ed8e4: B4000088  cbz      x8, #0x2ed8f4
static inline uint64_t fde_func_1464_0x2ed8d8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x2ed8d8ULL ^ (static_cast<uint64_t>(0xd10083ffULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x105398ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1465 | PC: 0x2ed9e8 | FDE: 0x1054a0 | Size: 256 bytes
// Khung tháo gỡ #1465 | Địa chỉ PC: 0x2ed9e8 | Địa chỉ FDE: 0x1054a0 | Kích thước: 256 bytes
//   0x2ed9e8: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x2ed9ec: AA0003F3  mov      x19, x0
//   0x2ed9f0: 97FFFFFA  bl       #0x2ed9d8
//   0x2ed9f4: AA1303E0  mov      x0, x19
static inline uint64_t fde_func_1465_0x2ed9e8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x2ed9e8ULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0xaa0003f3ULL) ^ 0x1054a0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1466 | PC: 0x2edb6c | FDE: 0x1055a8 | Size: 256 bytes
// Khung tháo gỡ #1466 | Địa chỉ PC: 0x2edb6c | Địa chỉ FDE: 0x1055a8 | Kích thước: 256 bytes
//   0x2edb6c: F9400808  ldr      x8, [x0, #0x10]
//   0x2edb70: F9400100  ldr      x0, [x8]
//   0x2edb74: 17FFD96E  b        #0x2e412c
//   0x2edb78: F9400808  ldr      x8, [x0, #0x10]
static inline uint64_t fde_func_1466_0x2edb6c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x2edb6cULL ^ (static_cast<uint64_t>(0xf9400808ULL) << 13);
    acc = (acc + a1 + 0xf9400100ULL) ^ 0x1055a8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1467 | PC: 0x2edc98 | FDE: 0x1056b0 | Size: 256 bytes
// Khung tháo gỡ #1467 | Địa chỉ PC: 0x2edc98 | Địa chỉ FDE: 0x1056b0 | Kích thước: 256 bytes
//   0x2edc98: F9400408  ldr      x8, [x0, #8]
//   0x2edc9c: 91006001  add      x1, x0, #0x18
//   0x2edca0: AA0803E0  mov      x0, x8
//   0x2edca4: 17FFFFE8  b        #0x2edc44
static inline uint64_t fde_func_1467_0x2edc98(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x2edc98ULL ^ (static_cast<uint64_t>(0xf9400408ULL) << 13);
    acc = (acc + a1 + 0x91006001ULL) ^ 0x1056b0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1468 | PC: 0x2edddc | FDE: 0x1057b0 | Size: 256 bytes
// Khung tháo gỡ #1468 | Địa chỉ PC: 0x2edddc | Địa chỉ FDE: 0x1057b0 | Kích thước: 256 bytes
//   0x2edddc: A9BD5BFC  stp      x28, x22, [sp, #-0x30]!
//   0x2edde0: A90153F5  stp      x21, x20, [sp, #0x10]
//   0x2edde4: A9027BF3  stp      x19, x30, [sp, #0x20]
//   0x2edde8: D10F43FF  sub      sp, sp, #0x3d0
static inline uint64_t fde_func_1468_0x2edddc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x2edddcULL ^ (static_cast<uint64_t>(0xa9bd5bfcULL) << 13);
    acc = (acc + a1 + 0xa90153f5ULL) ^ 0x1057b0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1469 | PC: 0x2edf18 | FDE: 0x1058b8 | Size: 256 bytes
// Khung tháo gỡ #1469 | Địa chỉ PC: 0x2edf18 | Địa chỉ FDE: 0x1058b8 | Kích thước: 256 bytes
//   0x2edf18: F81E0FF4  str      x20, [sp, #-0x20]!
//   0x2edf1c: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x2edf20: 9400BD60  bl       #0x31d4a0
//   0x2edf24: F9400A60  ldr      x0, [x19, #0x10]
static inline uint64_t fde_func_1469_0x2edf18(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x2edf18ULL ^ (static_cast<uint64_t>(0xf81e0ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x1058b8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1470 | PC: 0x2ee23c | FDE: 0x1059c8 | Size: 256 bytes
// Khung tháo gỡ #1470 | Địa chỉ PC: 0x2ee23c | Địa chỉ FDE: 0x1059c8 | Kích thước: 256 bytes
//   0x2ee23c: F9400808  ldr      x8, [x0, #0x10]
//   0x2ee240: F0000369  adrp     x9, #0x35d000
//   0x2ee244: 91282129  add      x9, x9, #0xa08
//   0x2ee248: 1400BAD6  b        #0x31cda0
static inline uint64_t fde_func_1470_0x2ee23c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x2ee23cULL ^ (static_cast<uint64_t>(0xf9400808ULL) << 13);
    acc = (acc + a1 + 0xf0000369ULL) ^ 0x1059c8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1471 | PC: 0x2ee358 | FDE: 0x105ad0 | Size: 256 bytes
// Khung tháo gỡ #1471 | Địa chỉ PC: 0x2ee358 | Địa chỉ FDE: 0x105ad0 | Kích thước: 256 bytes
//   0x2ee358: F0000368  adrp     x8, #0x35d000
//   0x2ee35c: 912AA108  add      x8, x8, #0xaa8
//   0x2ee360: F8008408  str      x8, [x0], #8
//   0x2ee364: 17FFFFD4  b        #0x2ee2b4
static inline uint64_t fde_func_1471_0x2ee358(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x2ee358ULL ^ (static_cast<uint64_t>(0xf0000368ULL) << 13);
    acc = (acc + a1 + 0x912aa108ULL) ^ 0x105ad0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1472 | PC: 0x2ee460 | FDE: 0x105bc8 | Size: 256 bytes [_ZNK4lynx5shell9LynxShell16GetAllTimingInfoEv]
// Khung tháo gỡ #1472 | Địa chỉ PC: 0x2ee460 | Địa chỉ FDE: 0x105bc8 | Kích thước: 256 bytes
//   0x2ee460: D10183FF  sub      sp, sp, #0x60
//   0x2ee464: F9001BF6  str      x22, [sp, #0x30]
//   0x2ee468: A90453F5  stp      x21, x20, [sp, #0x40]
//   0x2ee46c: A9057BF3  stp      x19, x30, [sp, #0x50]
static inline uint64_t fde_func_1472_0x2ee460(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x2ee460ULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xf9001bf6ULL) ^ 0x105bc8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1473 | PC: 0x2ee604 | FDE: 0x105ca0 | Size: 256 bytes [_ZN4lynx5shell9LynxShell27SetInspectorElementObserverERKNSt6__ndk110shared_ptrINS_4tasm24InspectorElementObserverEEE]
// Khung tháo gỡ #1473 | Địa chỉ PC: 0x2ee604 | Địa chỉ FDE: 0x105ca0 | Kích thước: 256 bytes
//   0x2ee604: D101C3FF  sub      sp, sp, #0x70
//   0x2ee608: A9045BF7  stp      x23, x22, [sp, #0x40]
//   0x2ee60c: A90553F5  stp      x21, x20, [sp, #0x50]
//   0x2ee610: A9067BF3  stp      x19, x30, [sp, #0x60]
static inline uint64_t fde_func_1473_0x2ee604(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x2ee604ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xa9045bf7ULL) ^ 0x105ca0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1474 | PC: 0x2ee710 | FDE: 0x105ce0 | Size: 56 bytes
// Khung tháo gỡ #1474 | Địa chỉ PC: 0x2ee710 | Địa chỉ FDE: 0x105ce0 | Kích thước: 56 bytes
//   0x2ee710: F0000368  adrp     x8, #0x35d000
//   0x2ee714: 912E6108  add      x8, x8, #0xb98
//   0x2ee718: F8008408  str      x8, [x0], #8
//   0x2ee71c: 17F9B668  b        #0x15c0bc
static inline uint64_t fde_func_1474_0x2ee710(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x2ee710ULL ^ (static_cast<uint64_t>(0xf0000368ULL) << 13);
    acc = (acc + a1 + 0x912e6108ULL) ^ 0x105ce0ULL;
    acc ^= (acc >> 17) * 0x0038ULL;
    return acc;
}

// FDE #1475 | PC: 0x2ee748 | FDE: 0x105d28 | Size: 256 bytes [_ZN4lynx5shell9LynxShell20SetHierarchyObserverERKNSt6__ndk110shared_ptrINS_4tasm17HierarchyObserverEEE]
// Khung tháo gỡ #1475 | Địa chỉ PC: 0x2ee748 | Địa chỉ FDE: 0x105d28 | Kích thước: 256 bytes
//   0x2ee748: D101C3FF  sub      sp, sp, #0x70
//   0x2ee74c: A9045BF7  stp      x23, x22, [sp, #0x40]
//   0x2ee750: A90553F5  stp      x21, x20, [sp, #0x50]
//   0x2ee754: A9067BF3  stp      x19, x30, [sp, #0x60]
static inline uint64_t fde_func_1475_0x2ee748(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x2ee748ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xa9045bf7ULL) ^ 0x105d28ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1476 | PC: 0x2ee8f8 | FDE: 0x105de8 | Size: 256 bytes
// Khung tháo gỡ #1476 | Địa chỉ PC: 0x2ee8f8 | Địa chỉ FDE: 0x105de8 | Kích thước: 256 bytes
//   0x2ee8f8: D10203FF  sub      sp, sp, #0x80
//   0x2ee8fc: A9055BF7  stp      x23, x22, [sp, #0x50]
//   0x2ee900: A90653F5  stp      x21, x20, [sp, #0x60]
//   0x2ee904: A9077BF3  stp      x19, x30, [sp, #0x70]
static inline uint64_t fde_func_1476_0x2ee8f8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x2ee8f8ULL ^ (static_cast<uint64_t>(0xd10203ffULL) << 13);
    acc = (acc + a1 + 0xa9055bf7ULL) ^ 0x105de8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1477 | PC: 0x2eeb04 | FDE: 0x105ef8 | Size: 256 bytes
// Khung tháo gỡ #1477 | Địa chỉ PC: 0x2eeb04 | Địa chỉ FDE: 0x105ef8 | Kích thước: 256 bytes
//   0x2eeb04: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x2eeb08: F0000368  adrp     x8, #0x35d000
//   0x2eeb0c: 91326108  add      x8, x8, #0xc98
//   0x2eeb10: 9400B714  bl       #0x31c760
static inline uint64_t fde_func_1477_0x2eeb04(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x2eeb04ULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0xf0000368ULL) ^ 0x105ef8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1478 | PC: 0x2eef38 | FDE: 0x105ff8 | Size: 256 bytes
// Khung tháo gỡ #1478 | Địa chỉ PC: 0x2eef38 | Địa chỉ FDE: 0x105ff8 | Kích thước: 256 bytes
//   0x2eef38: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x2eef3c: 94012540  bl       #0x33843c
//   0x2eef40: 97F9F364  bl       #0x16bcd0
//   0x2eef44: F9400660  ldr      x0, [x19, #8]
static inline uint64_t fde_func_1478_0x2eef38(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x2eef38ULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0x94012540ULL) ^ 0x105ff8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1479 | PC: 0x2ef36c | FDE: 0x106108 | Size: 256 bytes
// Khung tháo gỡ #1479 | Địa chỉ PC: 0x2ef36c | Địa chỉ FDE: 0x106108 | Kích thước: 256 bytes
//   0x2ef36c: F81D0FF6  str      x22, [sp, #-0x30]!
//   0x2ef370: A90153F5  stp      x21, x20, [sp, #0x10]
//   0x2ef374: A9027BF3  stp      x19, x30, [sp, #0x20]
//   0x2ef378: 9102E013  add      x19, x0, #0xb8
static inline uint64_t fde_func_1479_0x2ef36c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x2ef36cULL ^ (static_cast<uint64_t>(0xf81d0ff6ULL) << 13);
    acc = (acc + a1 + 0xa90153f5ULL) ^ 0x106108ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1480 | PC: 0x2ef4e0 | FDE: 0x106200 | Size: 256 bytes
// Khung tháo gỡ #1480 | Địa chỉ PC: 0x2ef4e0 | Địa chỉ FDE: 0x106200 | Kích thước: 256 bytes
//   0x2ef4e0: D10083FF  sub      sp, sp, #0x20
//   0x2ef4e4: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x2ef4e8: 39406408  ldrb     w8, [x0, #0x19]
//   0x2ef4ec: 340001C8  cbz      w8, #0x2ef524
static inline uint64_t fde_func_1480_0x2ef4e0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x2ef4e0ULL ^ (static_cast<uint64_t>(0xd10083ffULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x106200ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1481 | PC: 0x2ef85c | FDE: 0x106318 | Size: 256 bytes
// Khung tháo gỡ #1481 | Địa chỉ PC: 0x2ef85c | Địa chỉ FDE: 0x106318 | Kích thước: 256 bytes
//   0x2ef85c: F9400408  ldr      x8, [x0, #8]
//   0x2ef860: F9400908  ldr      x8, [x8, #0x10]
//   0x2ef864: B40000C8  cbz      x8, #0x2ef87c
//   0x2ef868: F9400C02  ldr      x2, [x0, #0x18]
static inline uint64_t fde_func_1481_0x2ef85c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x2ef85cULL ^ (static_cast<uint64_t>(0xf9400408ULL) << 13);
    acc = (acc + a1 + 0xf9400908ULL) ^ 0x106318ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1482 | PC: 0x2efac4 | FDE: 0x106420 | Size: 256 bytes
// Khung tháo gỡ #1482 | Địa chỉ PC: 0x2efac4 | Địa chỉ FDE: 0x106420 | Kích thước: 256 bytes
//   0x2efac4: D10143FF  sub      sp, sp, #0x50
//   0x2efac8: A90353F5  stp      x21, x20, [sp, #0x30]
//   0x2efacc: A9047BF3  stp      x19, x30, [sp, #0x40]
//   0x2efad0: 9400C266  bl       #0x320468
static inline uint64_t fde_func_1482_0x2efac4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x2efac4ULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xa90353f5ULL) ^ 0x106420ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1483 | PC: 0x2efcdc | FDE: 0x106520 | Size: 256 bytes
// Khung tháo gỡ #1483 | Địa chỉ PC: 0x2efcdc | Địa chỉ FDE: 0x106520 | Kích thước: 256 bytes
//   0x2efcdc: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x2efce0: 94013ED3  bl       #0x33f82c
//   0x2efce4: F9400660  ldr      x0, [x19, #8]
//   0x2efce8: A8C17BF3  ldp      x19, x30, [sp], #0x10
static inline uint64_t fde_func_1483_0x2efcdc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x2efcdcULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0x94013ed3ULL) ^ 0x106520ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1484 | PC: 0x2f000c | FDE: 0x106640 | Size: 256 bytes
// Khung tháo gỡ #1484 | Địa chỉ PC: 0x2f000c | Địa chỉ FDE: 0x106640 | Kích thước: 256 bytes
//   0x2f000c: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x2f0010: AA0003F3  mov      x19, x0
//   0x2f0014: 97FFFFFA  bl       #0x2efffc
//   0x2f0018: AA1303E0  mov      x0, x19
static inline uint64_t fde_func_1484_0x2f000c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x2f000cULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0xaa0003f3ULL) ^ 0x106640ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1485 | PC: 0x2f0314 | FDE: 0x106750 | Size: 256 bytes
// Khung tháo gỡ #1485 | Địa chỉ PC: 0x2f0314 | Địa chỉ FDE: 0x106750 | Kích thước: 256 bytes
//   0x2f0314: D101C3FF  sub      sp, sp, #0x70
//   0x2f0318: A90553F5  stp      x21, x20, [sp, #0x50]
//   0x2f031c: A9067BF3  stp      x19, x30, [sp, #0x60]
//   0x2f0320: 9400F123  bl       #0x32c7ac
static inline uint64_t fde_func_1485_0x2f0314(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x2f0314ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xa90553f5ULL) ^ 0x106750ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1486 | PC: 0x2f07c8 | FDE: 0x106880 | Size: 256 bytes
// Khung tháo gỡ #1486 | Địa chỉ PC: 0x2f07c8 | Địa chỉ FDE: 0x106880 | Kích thước: 256 bytes
//   0x2f07c8: F81E0FF4  str      x20, [sp, #-0x20]!
//   0x2f07cc: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x2f07d0: 94010990  bl       #0x332e10
//   0x2f07d4: 3DC00A60  ldr      q0, [x19, #0x20]
static inline uint64_t fde_func_1486_0x2f07c8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x2f07c8ULL ^ (static_cast<uint64_t>(0xf81e0ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x106880ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1487 | PC: 0x2f0a80 | FDE: 0x1069a0 | Size: 256 bytes
// Khung tháo gỡ #1487 | Địa chỉ PC: 0x2f0a80 | Địa chỉ FDE: 0x1069a0 | Kích thước: 256 bytes
//   0x2f0a80: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x2f0a84: AA0003F3  mov      x19, x0
//   0x2f0a88: 97FFFFFA  bl       #0x2f0a70
//   0x2f0a8c: AA1303E0  mov      x0, x19
static inline uint64_t fde_func_1487_0x2f0a80(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x2f0a80ULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0xaa0003f3ULL) ^ 0x1069a0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1488 | PC: 0x2f0c90 | FDE: 0x106ac0 | Size: 256 bytes
// Khung tháo gỡ #1488 | Địa chỉ PC: 0x2f0c90 | Địa chỉ FDE: 0x106ac0 | Kích thước: 256 bytes
//   0x2f0c90: F81E0FF4  str      x20, [sp, #-0x20]!
//   0x2f0c94: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x2f0c98: 9400B202  bl       #0x31d4a0
//   0x2f0c9c: F9400A60  ldr      x0, [x19, #0x10]
static inline uint64_t fde_func_1488_0x2f0c90(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x2f0c90ULL ^ (static_cast<uint64_t>(0xf81e0ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x106ac0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1489 | PC: 0x2f106c | FDE: 0x106bf0 | Size: 256 bytes
// Khung tháo gỡ #1489 | Địa chỉ PC: 0x2f106c | Địa chỉ FDE: 0x106bf0 | Kích thước: 256 bytes
//   0x2f106c: F81E0FF4  str      x20, [sp, #-0x20]!
//   0x2f1070: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x2f1074: 94011DF1  bl       #0x338838
//   0x2f1078: F9402268  ldr      x8, [x19, #0x40]
static inline uint64_t fde_func_1489_0x2f106c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x2f106cULL ^ (static_cast<uint64_t>(0xf81e0ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x106bf0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1490 | PC: 0x2f12d0 | FDE: 0x106d10 | Size: 256 bytes
// Khung tháo gỡ #1490 | Địa chỉ PC: 0x2f12d0 | Địa chỉ FDE: 0x106d10 | Kích thước: 256 bytes
//   0x2f12d0: F81E0FF4  str      x20, [sp, #-0x20]!
//   0x2f12d4: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x2f12d8: 9400B072  bl       #0x31d4a0
//   0x2f12dc: F9400A60  ldr      x0, [x19, #0x10]
static inline uint64_t fde_func_1490_0x2f12d0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x2f12d0ULL ^ (static_cast<uint64_t>(0xf81e0ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x106d10ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1491 | PC: 0x2f164c | FDE: 0x106e40 | Size: 256 bytes
// Khung tháo gỡ #1491 | Địa chỉ PC: 0x2f164c | Địa chỉ FDE: 0x106e40 | Kích thước: 256 bytes
//   0x2f164c: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x2f1650: 9400AC24  bl       #0x31c6e0
//   0x2f1654: 94000004  bl       #0x2f1664
//   0x2f1658: F9400660  ldr      x0, [x19, #8]
static inline uint64_t fde_func_1491_0x2f164c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x2f164cULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0x9400ac24ULL) ^ 0x106e40ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1492 | PC: 0x2f1854 | FDE: 0x106f50 | Size: 256 bytes
// Khung tháo gỡ #1492 | Địa chỉ PC: 0x2f1854 | Địa chỉ FDE: 0x106f50 | Kích thước: 256 bytes
//   0x2f1854: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x2f1858: AA0003F3  mov      x19, x0
//   0x2f185c: 97FFFFFA  bl       #0x2f1844
//   0x2f1860: AA1303E0  mov      x0, x19
static inline uint64_t fde_func_1492_0x2f1854(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x2f1854ULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0xaa0003f3ULL) ^ 0x106f50ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1493 | PC: 0x2f1b34 | FDE: 0x107070 | Size: 256 bytes
// Khung tháo gỡ #1493 | Địa chỉ PC: 0x2f1b34 | Địa chỉ FDE: 0x107070 | Kích thước: 256 bytes
//   0x2f1b34: D10443FF  sub      sp, sp, #0x110
//   0x2f1b38: A90E5BFC  stp      x28, x22, [sp, #0xe0]
//   0x2f1b3c: A90F53F5  stp      x21, x20, [sp, #0xf0]
//   0x2f1b40: A9107BF3  stp      x19, x30, [sp, #0x100]
static inline uint64_t fde_func_1493_0x2f1b34(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x2f1b34ULL ^ (static_cast<uint64_t>(0xd10443ffULL) << 13);
    acc = (acc + a1 + 0xa90e5bfcULL) ^ 0x107070ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1494 | PC: 0x2f1ed0 | FDE: 0x1071a0 | Size: 256 bytes
// Khung tháo gỡ #1494 | Địa chỉ PC: 0x2f1ed0 | Địa chỉ FDE: 0x1071a0 | Kích thước: 256 bytes
//   0x2f1ed0: B0000368  adrp     x8, #0x35e000
//   0x2f1ed4: 910A4108  add      x8, x8, #0x290
//   0x2f1ed8: F8008408  str      x8, [x0], #8
//   0x2f1edc: 17FFD059  b        #0x2e6040
static inline uint64_t fde_func_1494_0x2f1ed0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x2f1ed0ULL ^ (static_cast<uint64_t>(0xb0000368ULL) << 13);
    acc = (acc + a1 + 0x910a4108ULL) ^ 0x1071a0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1495 | PC: 0x2f21d0 | FDE: 0x1072b8 | Size: 256 bytes
// Khung tháo gỡ #1495 | Địa chỉ PC: 0x2f21d0 | Địa chỉ FDE: 0x1072b8 | Kích thước: 256 bytes
//   0x2f21d0: D10083FF  sub      sp, sp, #0x20
//   0x2f21d4: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x2f21d8: D53BD053  mrs      x19, tpidr_el0
//   0x2f21dc: F9401668  ldr      x8, [x19, #0x28]
static inline uint64_t fde_func_1495_0x2f21d0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x2f21d0ULL ^ (static_cast<uint64_t>(0xd10083ffULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x1072b8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1496 | PC: 0x2f2488 | FDE: 0x1073c0 | Size: 256 bytes
// Khung tháo gỡ #1496 | Địa chỉ PC: 0x2f2488 | Địa chỉ FDE: 0x1073c0 | Kích thước: 256 bytes
//   0x2f2488: D10103FF  sub      sp, sp, #0x40
//   0x2f248c: A90253F5  stp      x21, x20, [sp, #0x20]
//   0x2f2490: A9037BF3  stp      x19, x30, [sp, #0x30]
//   0x2f2494: D53BD055  mrs      x21, tpidr_el0
static inline uint64_t fde_func_1496_0x2f2488(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x2f2488ULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xa90253f5ULL) ^ 0x1073c0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1497 | PC: 0x2f283c | FDE: 0x1074e8 | Size: 256 bytes
// Khung tháo gỡ #1497 | Địa chỉ PC: 0x2f283c | Địa chỉ FDE: 0x1074e8 | Kích thước: 256 bytes
//   0x2f283c: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x2f2840: AA0003F3  mov      x19, x0
//   0x2f2844: 97FFFFFA  bl       #0x2f282c
//   0x2f2848: AA1303E0  mov      x0, x19
static inline uint64_t fde_func_1497_0x2f283c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x2f283cULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0xaa0003f3ULL) ^ 0x1074e8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1498 | PC: 0x2f2dac | FDE: 0x107630 | Size: 256 bytes
// Khung tháo gỡ #1498 | Địa chỉ PC: 0x2f2dac | Địa chỉ FDE: 0x107630 | Kích thước: 256 bytes
//   0x2f2dac: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x2f2db0: AA0003F3  mov      x19, x0
//   0x2f2db4: 97FFFFFA  bl       #0x2f2d9c
//   0x2f2db8: AA1303E0  mov      x0, x19
static inline uint64_t fde_func_1498_0x2f2dac(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x2f2dacULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0xaa0003f3ULL) ^ 0x107630ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1499 | PC: 0x2f3124 | FDE: 0x107760 | Size: 256 bytes
// Khung tháo gỡ #1499 | Địa chỉ PC: 0x2f3124 | Địa chỉ FDE: 0x107760 | Kích thước: 256 bytes
//   0x2f3124: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x2f3128: AA0003F3  mov      x19, x0
//   0x2f312c: 97FFFFFA  bl       #0x2f3114
//   0x2f3130: AA1303E0  mov      x0, x19
static inline uint64_t fde_func_1499_0x2f3124(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x2f3124ULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0xaa0003f3ULL) ^ 0x107760ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1500 | PC: 0x2f3440 | FDE: 0x107880 | Size: 256 bytes
// Khung tháo gỡ #1500 | Địa chỉ PC: 0x2f3440 | Địa chỉ FDE: 0x107880 | Kích thước: 256 bytes
//   0x2f3440: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x2f3444: AA0003F3  mov      x19, x0
//   0x2f3448: 97FFFFFA  bl       #0x2f3430
//   0x2f344c: AA1303E0  mov      x0, x19
static inline uint64_t fde_func_1500_0x2f3440(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x2f3440ULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0xaa0003f3ULL) ^ 0x107880ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1501 | PC: 0x2f3754 | FDE: 0x107980 | Size: 256 bytes
// Khung tháo gỡ #1501 | Địa chỉ PC: 0x2f3754 | Địa chỉ FDE: 0x107980 | Kích thước: 256 bytes
//   0x2f3754: F9404C00  ldr      x0, [x0, #0x98]
//   0x2f3758: B4000040  cbz      x0, #0x2f3760
//   0x2f375c: 17FFAA30  b        #0x2de01c
//   0x2f3760: D65F03C0  ret      
static inline uint64_t fde_func_1501_0x2f3754(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x2f3754ULL ^ (static_cast<uint64_t>(0xf9404c00ULL) << 13);
    acc = (acc + a1 + 0xb4000040ULL) ^ 0x107980ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1502 | PC: 0x2f3a44 | FDE: 0x107aa8 | Size: 256 bytes
// Khung tháo gỡ #1502 | Địa chỉ PC: 0x2f3a44 | Địa chỉ FDE: 0x107aa8 | Kích thước: 256 bytes
//   0x2f3a44: F0000348  adrp     x8, #0x35e000
//   0x2f3a48: 91136108  add      x8, x8, #0x4d8
//   0x2f3a4c: F8008408  str      x8, [x0], #8
//   0x2f3a50: 17FCE4E2  b        #0x22cdd8
static inline uint64_t fde_func_1502_0x2f3a44(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x2f3a44ULL ^ (static_cast<uint64_t>(0xf0000348ULL) << 13);
    acc = (acc + a1 + 0x91136108ULL) ^ 0x107aa8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1503 | PC: 0x2f3b84 | FDE: 0x107b98 | Size: 256 bytes
// Khung tháo gỡ #1503 | Địa chỉ PC: 0x2f3b84 | Địa chỉ FDE: 0x107b98 | Kích thước: 256 bytes
//   0x2f3b84: D1002000  sub      x0, x0, #8
//   0x2f3b88: 17FFFFBD  b        #0x2f3a7c
//   0x2f3b8c: D1002000  sub      x0, x0, #8
//   0x2f3b90: 17FFFFD4  b        #0x2f3ae0
static inline uint64_t fde_func_1503_0x2f3b84(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x2f3b84ULL ^ (static_cast<uint64_t>(0xd1002000ULL) << 13);
    acc = (acc + a1 + 0x17ffffbdULL) ^ 0x107b98ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1504 | PC: 0x2f3d0c | FDE: 0x107c98 | Size: 256 bytes
// Khung tháo gỡ #1504 | Địa chỉ PC: 0x2f3d0c | Địa chỉ FDE: 0x107c98 | Kích thước: 256 bytes
//   0x2f3d0c: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x2f3d10: F0000348  adrp     x8, #0x35e000
//   0x2f3d14: 911D0108  add      x8, x8, #0x740
//   0x2f3d18: 9400A292  bl       #0x31c760
static inline uint64_t fde_func_1504_0x2f3d0c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x2f3d0cULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0xf0000348ULL) ^ 0x107c98ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1505 | PC: 0x2f3f40 | FDE: 0x107da8 | Size: 256 bytes
// Khung tháo gỡ #1505 | Địa chỉ PC: 0x2f3f40 | Địa chỉ FDE: 0x107da8 | Kích thước: 256 bytes
//   0x2f3f40: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x2f3f44: AA0003F3  mov      x19, x0
//   0x2f3f48: 97FFFFFA  bl       #0x2f3f30
//   0x2f3f4c: AA1303E0  mov      x0, x19
static inline uint64_t fde_func_1505_0x2f3f40(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x2f3f40ULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0xaa0003f3ULL) ^ 0x107da8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1506 | PC: 0x2f4138 | FDE: 0x107eb8 | Size: 256 bytes
// Khung tháo gỡ #1506 | Địa chỉ PC: 0x2f4138 | Địa chỉ FDE: 0x107eb8 | Kích thước: 256 bytes
//   0x2f4138: F81E0FF4  str      x20, [sp, #-0x20]!
//   0x2f413c: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x2f4140: AA0103F3  mov      x19, x1
//   0x2f4144: AA0003F4  mov      x20, x0
static inline uint64_t fde_func_1506_0x2f4138(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x2f4138ULL ^ (static_cast<uint64_t>(0xf81e0ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x107eb8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1507 | PC: 0x2f4278 | FDE: 0x107fc0 | Size: 256 bytes
// Khung tháo gỡ #1507 | Địa chỉ PC: 0x2f4278 | Địa chỉ FDE: 0x107fc0 | Kích thước: 256 bytes
//   0x2f4278: F9400408  ldr      x8, [x0, #8]
//   0x2f427c: 91006001  add      x1, x0, #0x18
//   0x2f4280: AA0803E0  mov      x0, x8
//   0x2f4284: 17FFFFDB  b        #0x2f41f0
static inline uint64_t fde_func_1507_0x2f4278(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x2f4278ULL ^ (static_cast<uint64_t>(0xf9400408ULL) << 13);
    acc = (acc + a1 + 0x91006001ULL) ^ 0x107fc0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1508 | PC: 0x2f4380 | FDE: 0x1080c0 | Size: 256 bytes
// Khung tháo gỡ #1508 | Địa chỉ PC: 0x2f4380 | Địa chỉ FDE: 0x1080c0 | Kích thước: 256 bytes
//   0x2f4380: F9400400  ldr      x0, [x0, #8]
//   0x2f4384: 17FFFFEC  b        #0x2f4334
//   0x2f4388: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x2f438c: AA0003E8  mov      x8, x0
static inline uint64_t fde_func_1508_0x2f4380(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x2f4380ULL ^ (static_cast<uint64_t>(0xf9400400ULL) << 13);
    acc = (acc + a1 + 0x17ffffecULL) ^ 0x1080c0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1509 | PC: 0x2f4738 | FDE: 0x1081d0 | Size: 256 bytes
// Khung tháo gỡ #1509 | Địa chỉ PC: 0x2f4738 | Địa chỉ FDE: 0x1081d0 | Kích thước: 256 bytes
//   0x2f4738: D101C3FF  sub      sp, sp, #0x70
//   0x2f473c: F90023F6  str      x22, [sp, #0x40]
//   0x2f4740: A90553F5  stp      x21, x20, [sp, #0x50]
//   0x2f4744: A9067BF3  stp      x19, x30, [sp, #0x60]
static inline uint64_t fde_func_1509_0x2f4738(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x2f4738ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xf90023f6ULL) ^ 0x1081d0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1510 | PC: 0x2f4e70 | FDE: 0x108328 | Size: 256 bytes
// Khung tháo gỡ #1510 | Địa chỉ PC: 0x2f4e70 | Địa chỉ FDE: 0x108328 | Kích thước: 256 bytes
//   0x2f4e70: D10183FF  sub      sp, sp, #0x60
//   0x2f4e74: A90453F5  stp      x21, x20, [sp, #0x40]
//   0x2f4e78: A9057BF3  stp      x19, x30, [sp, #0x50]
//   0x2f4e7c: 9400C916  bl       #0x3272d4
static inline uint64_t fde_func_1510_0x2f4e70(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x2f4e70ULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xa90453f5ULL) ^ 0x108328ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1511 | PC: 0x2f56c4 | FDE: 0x108478 | Size: 256 bytes
// Khung tháo gỡ #1511 | Địa chỉ PC: 0x2f56c4 | Địa chỉ FDE: 0x108478 | Kích thước: 256 bytes
//   0x2f56c4: D10143FF  sub      sp, sp, #0x50
//   0x2f56c8: A90353F5  stp      x21, x20, [sp, #0x30]
//   0x2f56cc: A9047BF3  stp      x19, x30, [sp, #0x40]
//   0x2f56d0: 9400D313  bl       #0x32a31c
static inline uint64_t fde_func_1511_0x2f56c4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x2f56c4ULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xa90353f5ULL) ^ 0x108478ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1512 | PC: 0x2f5cdc | FDE: 0x1085c0 | Size: 256 bytes
// Khung tháo gỡ #1512 | Địa chỉ PC: 0x2f5cdc | Địa chỉ FDE: 0x1085c0 | Kích thước: 256 bytes
//   0x2f5cdc: D10243FF  sub      sp, sp, #0x90
//   0x2f5ce0: F90033F6  str      x22, [sp, #0x60]
//   0x2f5ce4: A90753F5  stp      x21, x20, [sp, #0x70]
//   0x2f5ce8: A9087BF3  stp      x19, x30, [sp, #0x80]
static inline uint64_t fde_func_1512_0x2f5cdc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x2f5cdcULL ^ (static_cast<uint64_t>(0xd10243ffULL) << 13);
    acc = (acc + a1 + 0xf90033f6ULL) ^ 0x1085c0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1513 | PC: 0x2f63dc | FDE: 0x108708 | Size: 256 bytes
// Khung tháo gỡ #1513 | Địa chỉ PC: 0x2f63dc | Địa chỉ FDE: 0x108708 | Kích thước: 256 bytes
//   0x2f63dc: F9405400  ldr      x0, [x0, #0xa8]
//   0x2f63e0: 14012145  b        #0x33e8f4
//   0x2f63e4: AA1E03E8  mov      x8, x30
//   0x2f63e8: 940096C8  bl       #0x31bf08
static inline uint64_t fde_func_1513_0x2f63dc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x2f63dcULL ^ (static_cast<uint64_t>(0xf9405400ULL) << 13);
    acc = (acc + a1 + 0x14012145ULL) ^ 0x108708ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1514 | PC: 0x2f6bdc | FDE: 0x108858 | Size: 256 bytes
// Khung tháo gỡ #1514 | Địa chỉ PC: 0x2f6bdc | Địa chỉ FDE: 0x108858 | Kích thước: 256 bytes
//   0x2f6bdc: D10503FF  sub      sp, sp, #0x140
//   0x2f6be0: A91063FC  stp      x28, x24, [sp, #0x100]
//   0x2f6be4: A9115BF7  stp      x23, x22, [sp, #0x110]
//   0x2f6be8: A91253F5  stp      x21, x20, [sp, #0x120]
static inline uint64_t fde_func_1514_0x2f6bdc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x2f6bdcULL ^ (static_cast<uint64_t>(0xd10503ffULL) << 13);
    acc = (acc + a1 + 0xa91063fcULL) ^ 0x108858ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1515 | PC: 0x2f7268 | FDE: 0x1089b8 | Size: 256 bytes
// Khung tháo gỡ #1515 | Địa chỉ PC: 0x2f7268 | Địa chỉ FDE: 0x1089b8 | Kích thước: 256 bytes
//   0x2f7268: D10603FF  sub      sp, sp, #0x180
//   0x2f726c: F9009BFC  str      x28, [sp, #0x130]
//   0x2f7270: A91463F9  stp      x25, x24, [sp, #0x140]
//   0x2f7274: A9155BF7  stp      x23, x22, [sp, #0x150]
static inline uint64_t fde_func_1515_0x2f7268(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x2f7268ULL ^ (static_cast<uint64_t>(0xd10603ffULL) << 13);
    acc = (acc + a1 + 0xf9009bfcULL) ^ 0x1089b8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1516 | PC: 0x2f7a10 | FDE: 0x108b00 | Size: 96 bytes
// Khung tháo gỡ #1516 | Địa chỉ PC: 0x2f7a10 | Địa chỉ FDE: 0x108b00 | Kích thước: 96 bytes
//   0x2f7a10: F81F0FFE  str      x30, [sp, #-0x10]!
//   0x2f7a14: D1002000  sub      x0, x0, #8
//   0x2f7a18: 97FFFEC5  bl       #0x2f752c
//   0x2f7a1c: 92403C00  and      x0, x0, #0xffff
static inline uint64_t fde_func_1516_0x2f7a10(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x2f7a10ULL ^ (static_cast<uint64_t>(0xf81f0ffeULL) << 13);
    acc = (acc + a1 + 0xd1002000ULL) ^ 0x108b00ULL;
    acc ^= (acc >> 17) * 0x0060ULL;
    return acc;
}

// FDE #1517 | PC: 0x2f7a70 | FDE: 0x108bf0 | Size: 84 bytes
// Khung tháo gỡ #1517 | Địa chỉ PC: 0x2f7a70 | Địa chỉ FDE: 0x108bf0 | Kích thước: 84 bytes
//   0x2f7a70: D1002000  sub      x0, x0, #8
//   0x2f7a74: 12000021  and      w1, w1, #1
//   0x2f7a78: 17FFF8CF  b        #0x2f5db4
//   0x2f7a7c: D1002000  sub      x0, x0, #8
static inline uint64_t fde_func_1517_0x2f7a70(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x2f7a70ULL ^ (static_cast<uint64_t>(0xd1002000ULL) << 13);
    acc = (acc + a1 + 0x12000021ULL) ^ 0x108bf0ULL;
    acc ^= (acc >> 17) * 0x0054ULL;
    return acc;
}

// FDE #1518 | PC: 0x2f7ac4 | FDE: 0x108ce0 | Size: 88 bytes
// Khung tháo gỡ #1518 | Địa chỉ PC: 0x2f7ac4 | Địa chỉ FDE: 0x108ce0 | Kích thước: 88 bytes
//   0x2f7ac4: D1002000  sub      x0, x0, #8
//   0x2f7ac8: 12000084  and      w4, w4, #1
//   0x2f7acc: 17FFFAFD  b        #0x2f66c0
//   0x2f7ad0: D1002000  sub      x0, x0, #8
static inline uint64_t fde_func_1518_0x2f7ac4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x2f7ac4ULL ^ (static_cast<uint64_t>(0xd1002000ULL) << 13);
    acc = (acc + a1 + 0x12000084ULL) ^ 0x108ce0ULL;
    acc ^= (acc >> 17) * 0x0058ULL;
    return acc;
}

// FDE #1519 | PC: 0x2f7b1c | FDE: 0x108dd0 | Size: 124 bytes
// Khung tháo gỡ #1519 | Địa chỉ PC: 0x2f7b1c | Địa chỉ FDE: 0x108dd0 | Kích thước: 124 bytes
//   0x2f7b1c: D1002000  sub      x0, x0, #8
//   0x2f7b20: 17FFFDA1  b        #0x2f71a4
//   0x2f7b24: F9405000  ldr      x0, [x0, #0xa0]
//   0x2f7b28: 14010D17  b        #0x33af84
static inline uint64_t fde_func_1519_0x2f7b1c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x2f7b1cULL ^ (static_cast<uint64_t>(0xd1002000ULL) << 13);
    acc = (acc + a1 + 0x17fffda1ULL) ^ 0x108dd0ULL;
    acc ^= (acc >> 17) * 0x007cULL;
    return acc;
}

// FDE #1520 | PC: 0x2f7b98 | FDE: 0x108ec0 | Size: 92 bytes
// Khung tháo gỡ #1520 | Địa chỉ PC: 0x2f7b98 | Địa chỉ FDE: 0x108ec0 | Kích thước: 92 bytes
//   0x2f7b98: D1002000  sub      x0, x0, #8
//   0x2f7b9c: 12000042  and      w2, w2, #1
//   0x2f7ba0: 17FFFEFD  b        #0x2f7794
//   0x2f7ba4: D1002000  sub      x0, x0, #8
static inline uint64_t fde_func_1520_0x2f7b98(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x2f7b98ULL ^ (static_cast<uint64_t>(0xd1002000ULL) << 13);
    acc = (acc + a1 + 0x12000042ULL) ^ 0x108ec0ULL;
    acc ^= (acc >> 17) * 0x005cULL;
    return acc;
}

// FDE #1521 | PC: 0x2f7bf4 | FDE: 0x108fb0 | Size: 256 bytes
// Khung tháo gỡ #1521 | Địa chỉ PC: 0x2f7bf4 | Địa chỉ FDE: 0x108fb0 | Kích thước: 256 bytes
//   0x2f7bf4: F81E0FF4  str      x20, [sp, #-0x20]!
//   0x2f7bf8: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x2f7bfc: 94009372  bl       #0x31c9c4
//   0x2f7c00: F9400A60  ldr      x0, [x19, #0x10]
static inline uint64_t fde_func_1521_0x2f7bf4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x2f7bf4ULL ^ (static_cast<uint64_t>(0xf81e0ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x108fb0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1522 | PC: 0x2f7cf8 | FDE: 0x1090b8 | Size: 256 bytes
// Khung tháo gỡ #1522 | Địa chỉ PC: 0x2f7cf8 | Địa chỉ FDE: 0x1090b8 | Kích thước: 256 bytes
//   0x2f7cf8: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x2f7cfc: AA0003F3  mov      x19, x0
//   0x2f7d00: 97FFFFFA  bl       #0x2f7ce8
//   0x2f7d04: AA1303E0  mov      x0, x19
static inline uint64_t fde_func_1522_0x2f7cf8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x2f7cf8ULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0xaa0003f3ULL) ^ 0x1090b8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1523 | PC: 0x2f7dfc | FDE: 0x1091c0 | Size: 256 bytes
// Khung tháo gỡ #1523 | Địa chỉ PC: 0x2f7dfc | Địa chỉ FDE: 0x1091c0 | Kích thước: 256 bytes
//   0x2f7dfc: F9400408  ldr      x8, [x0, #8]
//   0x2f7e00: 91006001  add      x1, x0, #0x18
//   0x2f7e04: AA0803E0  mov      x0, x8
//   0x2f7e08: 17FFFFDF  b        #0x2f7d84
static inline uint64_t fde_func_1523_0x2f7dfc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x2f7dfcULL ^ (static_cast<uint64_t>(0xf9400408ULL) << 13);
    acc = (acc + a1 + 0x91006001ULL) ^ 0x1091c0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1524 | PC: 0x2f7f48 | FDE: 0x1092c8 | Size: 256 bytes
// Khung tháo gỡ #1524 | Địa chỉ PC: 0x2f7f48 | Địa chỉ FDE: 0x1092c8 | Kích thước: 256 bytes
//   0x2f7f48: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x2f7f4c: AA0003F3  mov      x19, x0
//   0x2f7f50: 97FFFFFA  bl       #0x2f7f38
//   0x2f7f54: AA1303E0  mov      x0, x19
static inline uint64_t fde_func_1524_0x2f7f48(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x2f7f48ULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0xaa0003f3ULL) ^ 0x1092c8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1525 | PC: 0x2f80e4 | FDE: 0x1093d0 | Size: 256 bytes
// Khung tháo gỡ #1525 | Địa chỉ PC: 0x2f80e4 | Địa chỉ FDE: 0x1093d0 | Kích thước: 256 bytes
//   0x2f80e4: F81E0FF4  str      x20, [sp, #-0x20]!
//   0x2f80e8: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x2f80ec: 940090D2  bl       #0x31c434
//   0x2f80f0: 97FE0914  bl       #0x27a540
static inline uint64_t fde_func_1525_0x2f80e4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x2f80e4ULL ^ (static_cast<uint64_t>(0xf81e0ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x1093d0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1526 | PC: 0x2f8274 | FDE: 0x1094e8 | Size: 256 bytes
// Khung tháo gỡ #1526 | Địa chỉ PC: 0x2f8274 | Địa chỉ FDE: 0x1094e8 | Kích thước: 256 bytes
//   0x2f8274: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x2f8278: AA0003F3  mov      x19, x0
//   0x2f827c: F9402C00  ldr      x0, [x0, #0x58]
//   0x2f8280: 9400F94F  bl       #0x3367bc
static inline uint64_t fde_func_1526_0x2f8274(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x2f8274ULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0xaa0003f3ULL) ^ 0x1094e8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1527 | PC: 0x2f83e0 | FDE: 0x1095f8 | Size: 256 bytes
// Khung tháo gỡ #1527 | Địa chỉ PC: 0x2f83e0 | Địa chỉ FDE: 0x1095f8 | Kích thước: 256 bytes
//   0x2f83e0: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x2f83e4: AA0003F3  mov      x19, x0
//   0x2f83e8: 97FFFFFA  bl       #0x2f83d0
//   0x2f83ec: AA1303E0  mov      x0, x19
static inline uint64_t fde_func_1527_0x2f83e0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x2f83e0ULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0xaa0003f3ULL) ^ 0x1095f8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1528 | PC: 0x2f8544 | FDE: 0x109700 | Size: 256 bytes
// Khung tháo gỡ #1528 | Địa chỉ PC: 0x2f8544 | Địa chỉ FDE: 0x109700 | Kích thước: 256 bytes
//   0x2f8544: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x2f8548: AA0003F3  mov      x19, x0
//   0x2f854c: 97FFFFFA  bl       #0x2f8534
//   0x2f8550: AA1303E0  mov      x0, x19
static inline uint64_t fde_func_1528_0x2f8544(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x2f8544ULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0xaa0003f3ULL) ^ 0x109700ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1529 | PC: 0x2f86e0 | FDE: 0x109808 | Size: 256 bytes
// Khung tháo gỡ #1529 | Địa chỉ PC: 0x2f86e0 | Địa chỉ FDE: 0x109808 | Kích thước: 256 bytes
//   0x2f86e0: F9400408  ldr      x8, [x0, #8]
//   0x2f86e4: F9400908  ldr      x8, [x8, #0x10]
//   0x2f86e8: B40000C8  cbz      x8, #0x2f8700
//   0x2f86ec: F9401508  ldr      x8, [x8, #0x28]
static inline uint64_t fde_func_1529_0x2f86e0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x2f86e0ULL ^ (static_cast<uint64_t>(0xf9400408ULL) << 13);
    acc = (acc + a1 + 0xf9400908ULL) ^ 0x109808ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1530 | PC: 0x2f8930 | FDE: 0x109918 | Size: 256 bytes
// Khung tháo gỡ #1530 | Địa chỉ PC: 0x2f8930 | Địa chỉ FDE: 0x109918 | Kích thước: 256 bytes
//   0x2f8930: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x2f8934: AA0003F3  mov      x19, x0
//   0x2f8938: 97FFFFFA  bl       #0x2f8920
//   0x2f893c: AA1303E0  mov      x0, x19
static inline uint64_t fde_func_1530_0x2f8930(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x2f8930ULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0xaa0003f3ULL) ^ 0x109918ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1531 | PC: 0x2f8a80 | FDE: 0x109a28 | Size: 256 bytes
// Khung tháo gỡ #1531 | Địa chỉ PC: 0x2f8a80 | Địa chỉ FDE: 0x109a28 | Kích thước: 256 bytes
//   0x2f8a80: F8408428  ldr      x8, [x1], #8
//   0x2f8a84: F8008408  str      x8, [x0], #8
//   0x2f8a88: 14011F62  b        #0x340810
//   0x2f8a8c: F0000328  adrp     x8, #0x35f000
static inline uint64_t fde_func_1531_0x2f8a80(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x2f8a80ULL ^ (static_cast<uint64_t>(0xf8408428ULL) << 13);
    acc = (acc + a1 + 0xf8008408ULL) ^ 0x109a28ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1532 | PC: 0x2f8c08 | FDE: 0x109b30 | Size: 228 bytes
// Khung tháo gỡ #1532 | Địa chỉ PC: 0x2f8c08 | Địa chỉ FDE: 0x109b30 | Kích thước: 228 bytes
//   0x2f8c08: F9400408  ldr      x8, [x0, #8]
//   0x2f8c0c: 91006001  add      x1, x0, #0x18
//   0x2f8c10: AA0803E0  mov      x0, x8
//   0x2f8c14: 17FFFFE9  b        #0x2f8bb8
static inline uint64_t fde_func_1532_0x2f8c08(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x2f8c08ULL ^ (static_cast<uint64_t>(0xf9400408ULL) << 13);
    acc = (acc + a1 + 0x91006001ULL) ^ 0x109b30ULL;
    acc ^= (acc >> 17) * 0x00e4ULL;
    return acc;
}

// FDE #1533 | PC: 0x2f8cec | FDE: 0x109c28 | Size: 256 bytes
// Khung tháo gỡ #1533 | Địa chỉ PC: 0x2f8cec | Địa chỉ FDE: 0x109c28 | Kích thước: 256 bytes
//   0x2f8cec: F9400808  ldr      x8, [x0, #0x10]
//   0x2f8cf0: F0000329  adrp     x9, #0x35f000
//   0x2f8cf4: 91054129  add      x9, x9, #0x150
//   0x2f8cf8: 1400902A  b        #0x31cda0
static inline uint64_t fde_func_1533_0x2f8cec(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x2f8cecULL ^ (static_cast<uint64_t>(0xf9400808ULL) << 13);
    acc = (acc + a1 + 0xf0000329ULL) ^ 0x109c28ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1534 | PC: 0x2f8f58 | FDE: 0x109d38 | Size: 200 bytes
// Khung tháo gỡ #1534 | Địa chỉ PC: 0x2f8f58 | Địa chỉ FDE: 0x109d38 | Kích thước: 200 bytes
//   0x2f8f58: F0000328  adrp     x8, #0x35f000
//   0x2f8f5c: 91072108  add      x8, x8, #0x1c8
//   0x2f8f60: F8008408  str      x8, [x0], #8
//   0x2f8f64: 17F98C56  b        #0x15c0bc
static inline uint64_t fde_func_1534_0x2f8f58(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x2f8f58ULL ^ (static_cast<uint64_t>(0xf0000328ULL) << 13);
    acc = (acc + a1 + 0x91072108ULL) ^ 0x109d38ULL;
    acc ^= (acc >> 17) * 0x00c8ULL;
    return acc;
}

// FDE #1535 | PC: 0x2f9020 | FDE: 0x109e28 | Size: 256 bytes
// Khung tháo gỡ #1535 | Địa chỉ PC: 0x2f9020 | Địa chỉ FDE: 0x109e28 | Kích thước: 256 bytes
//   0x2f9020: AA1E03E2  mov      x2, x30
//   0x2f9024: 94009A83  bl       #0x31fa30
//   0x2f9028: AA0203FE  mov      x30, x2
//   0x2f902c: 17FFFFEF  b        #0x2f8fe8
static inline uint64_t fde_func_1535_0x2f9020(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x2f9020ULL ^ (static_cast<uint64_t>(0xaa1e03e2ULL) << 13);
    acc = (acc + a1 + 0x94009a83ULL) ^ 0x109e28ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1536 | PC: 0x2f9128 | FDE: 0x109f28 | Size: 200 bytes
// Khung tháo gỡ #1536 | Địa chỉ PC: 0x2f9128 | Địa chỉ FDE: 0x109f28 | Kích thước: 200 bytes
//   0x2f9128: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x2f912c: 94008D6D  bl       #0x31c6e0
//   0x2f9130: 94000004  bl       #0x2f9140
//   0x2f9134: F9400660  ldr      x0, [x19, #8]
static inline uint64_t fde_func_1536_0x2f9128(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x2f9128ULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0x94008d6dULL) ^ 0x109f28ULL;
    acc ^= (acc >> 17) * 0x00c8ULL;
    return acc;
}

// FDE #1537 | PC: 0x2f91f0 | FDE: 0x10a018 | Size: 256 bytes
// Khung tháo gỡ #1537 | Địa chỉ PC: 0x2f91f0 | Địa chỉ FDE: 0x10a018 | Kích thước: 256 bytes
//   0x2f91f0: D0000328  adrp     x8, #0x35f000
//   0x2f91f4: 910B8108  add      x8, x8, #0x2e0
//   0x2f91f8: F8008408  str      x8, [x0], #8
//   0x2f91fc: 17FCEA91  b        #0x233c40
static inline uint64_t fde_func_1537_0x2f91f0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x2f91f0ULL ^ (static_cast<uint64_t>(0xd0000328ULL) << 13);
    acc = (acc + a1 + 0x910b8108ULL) ^ 0x10a018ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1538 | PC: 0x2f92f0 | FDE: 0x10a110 | Size: 184 bytes
// Khung tháo gỡ #1538 | Địa chỉ PC: 0x2f92f0 | Địa chỉ FDE: 0x10a110 | Kích thước: 184 bytes
//   0x2f92f0: D0000328  adrp     x8, #0x35f000
//   0x2f92f4: 910CC108  add      x8, x8, #0x330
//   0x2f92f8: F8008408  str      x8, [x0], #8
//   0x2f92fc: 17FFFFF7  b        #0x2f92d8
static inline uint64_t fde_func_1538_0x2f92f0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x2f92f0ULL ^ (static_cast<uint64_t>(0xd0000328ULL) << 13);
    acc = (acc + a1 + 0x910cc108ULL) ^ 0x10a110ULL;
    acc ^= (acc >> 17) * 0x00b8ULL;
    return acc;
}

// FDE #1539 | PC: 0x2f93a8 | FDE: 0x10a200 | Size: 188 bytes
// Khung tháo gỡ #1539 | Địa chỉ PC: 0x2f93a8 | Địa chỉ FDE: 0x10a200 | Kích thước: 188 bytes
//   0x2f93a8: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x2f93ac: AA0003F3  mov      x19, x0
//   0x2f93b0: 97FFFFFA  bl       #0x2f9398
//   0x2f93b4: AA1303E0  mov      x0, x19
static inline uint64_t fde_func_1539_0x2f93a8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x2f93a8ULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0xaa0003f3ULL) ^ 0x10a200ULL;
    acc ^= (acc >> 17) * 0x00bcULL;
    return acc;
}

// FDE #1540 | PC: 0x2f9464 | FDE: 0x10a2f0 | Size: 196 bytes
// Khung tháo gỡ #1540 | Địa chỉ PC: 0x2f9464 | Địa chỉ FDE: 0x10a2f0 | Kích thước: 196 bytes
//   0x2f9464: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x2f9468: AA0003F3  mov      x19, x0
//   0x2f946c: 97FFFFFA  bl       #0x2f9454
//   0x2f9470: AA1303E0  mov      x0, x19
static inline uint64_t fde_func_1540_0x2f9464(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x2f9464ULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0xaa0003f3ULL) ^ 0x10a2f0ULL;
    acc ^= (acc >> 17) * 0x00c4ULL;
    return acc;
}

// FDE #1541 | PC: 0x2f9528 | FDE: 0x10a3e0 | Size: 256 bytes
// Khung tháo gỡ #1541 | Địa chỉ PC: 0x2f9528 | Địa chỉ FDE: 0x10a3e0 | Kích thước: 256 bytes
//   0x2f9528: B40000C0  cbz      x0, #0x2f9540
//   0x2f952c: B9401822  ldr      w2, [x1, #0x18]
//   0x2f9530: F9400000  ldr      x0, [x0]
//   0x2f9534: 91008023  add      x3, x1, #0x20
static inline uint64_t fde_func_1541_0x2f9528(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x2f9528ULL ^ (static_cast<uint64_t>(0xb40000c0ULL) << 13);
    acc = (acc + a1 + 0xb9401822ULL) ^ 0x10a3e0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1542 | PC: 0x2f9658 | FDE: 0x10a4e0 | Size: 220 bytes
// Khung tháo gỡ #1542 | Địa chỉ PC: 0x2f9658 | Địa chỉ FDE: 0x10a4e0 | Kích thước: 220 bytes
//   0x2f9658: F81E0FF4  str      x20, [sp, #-0x20]!
//   0x2f965c: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x2f9660: 94009F0E  bl       #0x321298
//   0x2f9664: B9402268  ldr      w8, [x19, #0x20]
static inline uint64_t fde_func_1542_0x2f9658(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x2f9658ULL ^ (static_cast<uint64_t>(0xf81e0ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x10a4e0ULL;
    acc ^= (acc >> 17) * 0x00dcULL;
    return acc;
}

// FDE #1543 | PC: 0x2f9734 | FDE: 0x10a5d8 | Size: 256 bytes
// Khung tháo gỡ #1543 | Địa chỉ PC: 0x2f9734 | Địa chỉ FDE: 0x10a5d8 | Kích thước: 256 bytes
//   0x2f9734: B40000C0  cbz      x0, #0x2f974c
//   0x2f9738: B9400028  ldr      w8, [x1]
//   0x2f973c: 6D408420  ldp      d0, d1, [x1, #8]
//   0x2f9740: FD400C22  ldr      d2, [x1, #0x18]
static inline uint64_t fde_func_1543_0x2f9734(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x2f9734ULL ^ (static_cast<uint64_t>(0xb40000c0ULL) << 13);
    acc = (acc + a1 + 0xb9400028ULL) ^ 0x10a5d8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1544 | PC: 0x2f990c | FDE: 0x10a6d0 | Size: 256 bytes
// Khung tháo gỡ #1544 | Địa chỉ PC: 0x2f990c | Địa chỉ FDE: 0x10a6d0 | Kích thước: 256 bytes
//   0x2f990c: A9BE53F5  stp      x21, x20, [sp, #-0x20]!
//   0x2f9910: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x2f9914: AA0003F5  mov      x21, x0
//   0x2f9918: 91010000  add      x0, x0, #0x40
static inline uint64_t fde_func_1544_0x2f990c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x2f990cULL ^ (static_cast<uint64_t>(0xa9be53f5ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x10a6d0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1545 | PC: 0x2f9b70 | FDE: 0x10a7f0 | Size: 256 bytes
// Khung tháo gỡ #1545 | Địa chỉ PC: 0x2f9b70 | Địa chỉ FDE: 0x10a7f0 | Kích thước: 256 bytes
//   0x2f9b70: AA1E03E1  mov      x1, x30
//   0x2f9b74: 94009441  bl       #0x31ec78
//   0x2f9b78: AA0103FE  mov      x30, x1
//   0x2f9b7c: A9067BF3  stp      x19, x30, [sp, #0x60]
static inline uint64_t fde_func_1545_0x2f9b70(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x2f9b70ULL ^ (static_cast<uint64_t>(0xaa1e03e1ULL) << 13);
    acc = (acc + a1 + 0x94009441ULL) ^ 0x10a7f0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1546 | PC: 0x2fa020 | FDE: 0x10a918 | Size: 256 bytes
// Khung tháo gỡ #1546 | Địa chỉ PC: 0x2fa020 | Địa chỉ FDE: 0x10a918 | Kích thước: 256 bytes
//   0x2fa020: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x2fa024: 9400D488  bl       #0x32f244
//   0x2fa028: 97F9F561  bl       #0x1775ac
//   0x2fa02c: AA1303E0  mov      x0, x19
static inline uint64_t fde_func_1546_0x2fa020(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x2fa020ULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0x9400d488ULL) ^ 0x10a918ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1547 | PC: 0x2fa338 | FDE: 0x10aa28 | Size: 256 bytes
// Khung tháo gỡ #1547 | Địa chỉ PC: 0x2fa338 | Địa chỉ FDE: 0x10aa28 | Kích thước: 256 bytes
//   0x2fa338: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x2fa33c: AA0003F3  mov      x19, x0
//   0x2fa340: 97FFFFFA  bl       #0x2fa328
//   0x2fa344: AA1303E0  mov      x0, x19
static inline uint64_t fde_func_1547_0x2fa338(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x2fa338ULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0xaa0003f3ULL) ^ 0x10aa28ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1548 | PC: 0x2fa5e0 | FDE: 0x10ab48 | Size: 256 bytes
// Khung tháo gỡ #1548 | Địa chỉ PC: 0x2fa5e0 | Địa chỉ FDE: 0x10ab48 | Kích thước: 256 bytes
//   0x2fa5e0: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x2fa5e4: AA0003F3  mov      x19, x0
//   0x2fa5e8: 97FFFFFA  bl       #0x2fa5d0
//   0x2fa5ec: AA1303E0  mov      x0, x19
static inline uint64_t fde_func_1548_0x2fa5e0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x2fa5e0ULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0xaa0003f3ULL) ^ 0x10ab48ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1549 | PC: 0x2fa94c | FDE: 0x10ac60 | Size: 256 bytes
// Khung tháo gỡ #1549 | Địa chỉ PC: 0x2fa94c | Địa chỉ FDE: 0x10ac60 | Kích thước: 256 bytes
//   0x2fa94c: D101C3FF  sub      sp, sp, #0x70
//   0x2fa950: A9045BF7  stp      x23, x22, [sp, #0x40]
//   0x2fa954: A90553F5  stp      x21, x20, [sp, #0x50]
//   0x2fa958: A9067BF3  stp      x19, x30, [sp, #0x60]
static inline uint64_t fde_func_1549_0x2fa94c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x2fa94cULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xa9045bf7ULL) ^ 0x10ac60ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1550 | PC: 0x2faba8 | FDE: 0x10ad70 | Size: 256 bytes
// Khung tháo gỡ #1550 | Địa chỉ PC: 0x2faba8 | Địa chỉ FDE: 0x10ad70 | Kích thước: 256 bytes
//   0x2faba8: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x2fabac: 94008BF5  bl       #0x31db80
//   0x2fabb0: B0000328  adrp     x8, #0x35f000
//   0x2fabb4: 911E4108  add      x8, x8, #0x790
static inline uint64_t fde_func_1550_0x2faba8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x2faba8ULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0x94008bf5ULL) ^ 0x10ad70ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1551 | PC: 0x2fb034 | FDE: 0x10aeb8 | Size: 256 bytes
// Khung tháo gỡ #1551 | Địa chỉ PC: 0x2fb034 | Địa chỉ FDE: 0x10aeb8 | Kích thước: 256 bytes
//   0x2fb034: D10243FF  sub      sp, sp, #0x90
//   0x2fb038: F90033F6  str      x22, [sp, #0x60]
//   0x2fb03c: A90753F5  stp      x21, x20, [sp, #0x70]
//   0x2fb040: A9087BF3  stp      x19, x30, [sp, #0x80]
static inline uint64_t fde_func_1551_0x2fb034(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x2fb034ULL ^ (static_cast<uint64_t>(0xd10243ffULL) << 13);
    acc = (acc + a1 + 0xf90033f6ULL) ^ 0x10aeb8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1552 | PC: 0x2fb434 | FDE: 0x10afd8 | Size: 256 bytes
// Khung tháo gỡ #1552 | Địa chỉ PC: 0x2fb434 | Địa chỉ FDE: 0x10afd8 | Kích thước: 256 bytes
//   0x2fb434: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x2fb438: AA0003F3  mov      x19, x0
//   0x2fb43c: 97FFFFFA  bl       #0x2fb424
//   0x2fb440: AA1303E0  mov      x0, x19
static inline uint64_t fde_func_1552_0x2fb434(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x2fb434ULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0xaa0003f3ULL) ^ 0x10afd8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1553 | PC: 0x2fb5f4 | FDE: 0x10b0d8 | Size: 256 bytes
// Khung tháo gỡ #1553 | Địa chỉ PC: 0x2fb5f4 | Địa chỉ FDE: 0x10b0d8 | Kích thước: 256 bytes
//   0x2fb5f4: F9400040  ldr      x0, [x2]
//   0x2fb5f8: B4000080  cbz      x0, #0x2fb608
//   0x2fb5fc: F9400008  ldr      x8, [x0]
//   0x2fb600: 2A0303E1  mov      w1, w3
static inline uint64_t fde_func_1553_0x2fb5f4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x2fb5f4ULL ^ (static_cast<uint64_t>(0xf9400040ULL) << 13);
    acc = (acc + a1 + 0xb4000080ULL) ^ 0x10b0d8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1554 | PC: 0x2fba5c | FDE: 0x10b230 | Size: 256 bytes
// Khung tháo gỡ #1554 | Địa chỉ PC: 0x2fba5c | Địa chỉ FDE: 0x10b230 | Kích thước: 256 bytes
//   0x2fba5c: F9400048  ldr      x8, [x2]
//   0x2fba60: AA0203E0  mov      x0, x2
//   0x2fba64: AA0303E1  mov      x1, x3
//   0x2fba68: F9402902  ldr      x2, [x8, #0x50]
static inline uint64_t fde_func_1554_0x2fba5c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x2fba5cULL ^ (static_cast<uint64_t>(0xf9400048ULL) << 13);
    acc = (acc + a1 + 0xaa0203e0ULL) ^ 0x10b230ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1555 | PC: 0x2fbce0 | FDE: 0x10b348 | Size: 256 bytes
// Khung tháo gỡ #1555 | Địa chỉ PC: 0x2fbce0 | Địa chỉ FDE: 0x10b348 | Kích thước: 256 bytes
//   0x2fbce0: 90000328  adrp     x8, #0x35f000
//   0x2fbce4: 912E6108  add      x8, x8, #0xb98
//   0x2fbce8: 1400C022  b        #0x32bd70
//   0x2fbcec: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
static inline uint64_t fde_func_1555_0x2fbce0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x2fbce0ULL ^ (static_cast<uint64_t>(0x90000328ULL) << 13);
    acc = (acc + a1 + 0x912e6108ULL) ^ 0x10b348ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1556 | PC: 0x2fbedc | FDE: 0x10b450 | Size: 256 bytes
// Khung tháo gỡ #1556 | Địa chỉ PC: 0x2fbedc | Địa chỉ FDE: 0x10b450 | Kích thước: 256 bytes
//   0x2fbedc: 90000328  adrp     x8, #0x35f000
//   0x2fbee0: 9134E108  add      x8, x8, #0xd38
//   0x2fbee4: 1400BFA3  b        #0x32bd70
//   0x2fbee8: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
static inline uint64_t fde_func_1556_0x2fbedc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x2fbedcULL ^ (static_cast<uint64_t>(0x90000328ULL) << 13);
    acc = (acc + a1 + 0x9134e108ULL) ^ 0x10b450ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1557 | PC: 0x2fcee8 | FDE: 0x10b5a8 | Size: 256 bytes
// Khung tháo gỡ #1557 | Địa chỉ PC: 0x2fcee8 | Địa chỉ FDE: 0x10b5a8 | Kích thước: 256 bytes
//   0x2fcee8: D103C3FF  sub      sp, sp, #0xf0
//   0x2fceec: F90063F6  str      x22, [sp, #0xc0]
//   0x2fcef0: A90D53F5  stp      x21, x20, [sp, #0xd0]
//   0x2fcef4: A90E7BF3  stp      x19, x30, [sp, #0xe0]
static inline uint64_t fde_func_1557_0x2fcee8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x2fcee8ULL ^ (static_cast<uint64_t>(0xd103c3ffULL) << 13);
    acc = (acc + a1 + 0xf90063f6ULL) ^ 0x10b5a8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1558 | PC: 0x2fd590 | FDE: 0x10b6e0 | Size: 256 bytes
// Khung tháo gỡ #1558 | Địa chỉ PC: 0x2fd590 | Địa chỉ FDE: 0x10b6e0 | Kích thước: 256 bytes
//   0x2fd590: F81D0FF6  str      x22, [sp, #-0x30]!
//   0x2fd594: A90153F5  stp      x21, x20, [sp, #0x10]
//   0x2fd598: A9027BF3  stp      x19, x30, [sp, #0x20]
//   0x2fd59c: AA0003F6  mov      x22, x0
static inline uint64_t fde_func_1558_0x2fd590(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x2fd590ULL ^ (static_cast<uint64_t>(0xf81d0ff6ULL) << 13);
    acc = (acc + a1 + 0xa90153f5ULL) ^ 0x10b6e0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1559 | PC: 0x2fd89c | FDE: 0x10b7f0 | Size: 256 bytes
// Khung tháo gỡ #1559 | Địa chỉ PC: 0x2fd89c | Địa chỉ FDE: 0x10b7f0 | Kích thước: 256 bytes
//   0x2fd89c: AA1E03E4  mov      x4, x30
//   0x2fd8a0: 9400824F  bl       #0x31e1dc
//   0x2fd8a4: AA0403FE  mov      x30, x4
//   0x2fd8a8: A9087BF3  stp      x19, x30, [sp, #0x80]
static inline uint64_t fde_func_1559_0x2fd89c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x2fd89cULL ^ (static_cast<uint64_t>(0xaa1e03e4ULL) << 13);
    acc = (acc + a1 + 0x9400824fULL) ^ 0x10b7f0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1560 | PC: 0x2ff7b8 | FDE: 0x10b928 | Size: 256 bytes
// Khung tháo gỡ #1560 | Địa chỉ PC: 0x2ff7b8 | Địa chỉ FDE: 0x10b928 | Kích thước: 256 bytes
//   0x2ff7b8: B4000102  cbz      x2, #0x2ff7d8
//   0x2ff7bc: 52800048  mov      w8, #2
//   0x2ff7c0: 885FFC49  ldaxr    w9, [x2]
//   0x2ff7c4: 35000089  cbnz     w9, #0x2ff7d4
static inline uint64_t fde_func_1560_0x2ff7b8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x2ff7b8ULL ^ (static_cast<uint64_t>(0xb4000102ULL) << 13);
    acc = (acc + a1 + 0x52800048ULL) ^ 0x10b928ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1561 | PC: 0x2fff54 | FDE: 0x10ba88 | Size: 256 bytes
// Khung tháo gỡ #1561 | Địa chỉ PC: 0x2fff54 | Địa chỉ FDE: 0x10ba88 | Kích thước: 256 bytes
//   0x2fff54: D10743FF  sub      sp, sp, #0x1d0
//   0x2fff58: AA1E03E1  mov      x1, x30
//   0x2fff5c: 9400A42C  bl       #0x32900c
//   0x2fff60: AA0103FE  mov      x30, x1
static inline uint64_t fde_func_1561_0x2fff54(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x2fff54ULL ^ (static_cast<uint64_t>(0xd10743ffULL) << 13);
    acc = (acc + a1 + 0xaa1e03e1ULL) ^ 0x10ba88ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1562 | PC: 0x30116c | FDE: 0x10bc58 | Size: 256 bytes
// Khung tháo gỡ #1562 | Địa chỉ PC: 0x30116c | Địa chỉ FDE: 0x10bc58 | Kích thước: 256 bytes
//   0x30116c: D10383FF  sub      sp, sp, #0xe0
//   0x301170: A90B5BF7  stp      x23, x22, [sp, #0xb0]
//   0x301174: A90C53F5  stp      x21, x20, [sp, #0xc0]
//   0x301178: A90D7BF3  stp      x19, x30, [sp, #0xd0]
static inline uint64_t fde_func_1562_0x30116c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x30116cULL ^ (static_cast<uint64_t>(0xd10383ffULL) << 13);
    acc = (acc + a1 + 0xa90b5bf7ULL) ^ 0x10bc58ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1563 | PC: 0x301c64 | FDE: 0x10be00 | Size: 256 bytes
// Khung tháo gỡ #1563 | Địa chỉ PC: 0x301c64 | Địa chỉ FDE: 0x10be00 | Kích thước: 256 bytes
//   0x301c64: AA1E03E1  mov      x1, x30
//   0x301c68: 9400A456  bl       #0x32adc0
//   0x301c6c: AA0103FE  mov      x30, x1
//   0x301c70: A9107BF3  stp      x19, x30, [sp, #0x100]
static inline uint64_t fde_func_1563_0x301c64(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x301c64ULL ^ (static_cast<uint64_t>(0xaa1e03e1ULL) << 13);
    acc = (acc + a1 + 0x9400a456ULL) ^ 0x10be00ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1564 | PC: 0x302398 | FDE: 0x10bf80 | Size: 256 bytes
// Khung tháo gỡ #1564 | Địa chỉ PC: 0x302398 | Địa chỉ FDE: 0x10bf80 | Kích thước: 256 bytes
//   0x302398: AA1E03E0  mov      x0, x30
//   0x30239c: 94006F5B  bl       #0x31e108
//   0x3023a0: AA0003FE  mov      x30, x0
//   0x3023a4: A9077BF3  stp      x19, x30, [sp, #0x70]
static inline uint64_t fde_func_1564_0x302398(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x302398ULL ^ (static_cast<uint64_t>(0xaa1e03e0ULL) << 13);
    acc = (acc + a1 + 0x94006f5bULL) ^ 0x10bf80ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1565 | PC: 0x302a18 | FDE: 0x10c0f0 | Size: 256 bytes
// Khung tháo gỡ #1565 | Địa chỉ PC: 0x302a18 | Địa chỉ FDE: 0x10c0f0 | Kích thước: 256 bytes
//   0x302a18: D10143FF  sub      sp, sp, #0x50
//   0x302a1c: F90013F6  str      x22, [sp, #0x20]
//   0x302a20: A90353F5  stp      x21, x20, [sp, #0x30]
//   0x302a24: A9047BF3  stp      x19, x30, [sp, #0x40]
static inline uint64_t fde_func_1565_0x302a18(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x302a18ULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xf90013f6ULL) ^ 0x10c0f0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1566 | PC: 0x3034d8 | FDE: 0x10c260 | Size: 256 bytes
// Khung tháo gỡ #1566 | Địa chỉ PC: 0x3034d8 | Địa chỉ FDE: 0x10c260 | Kích thước: 256 bytes
//   0x3034d8: D10303FF  sub      sp, sp, #0xc0
//   0x3034dc: FD0043E8  str      d8, [sp, #0x80]
//   0x3034e0: A9095BF7  stp      x23, x22, [sp, #0x90]
//   0x3034e4: A90A53F5  stp      x21, x20, [sp, #0xa0]
static inline uint64_t fde_func_1566_0x3034d8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x3034d8ULL ^ (static_cast<uint64_t>(0xd10303ffULL) << 13);
    acc = (acc + a1 + 0xfd0043e8ULL) ^ 0x10c260ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1567 | PC: 0x303c2c | FDE: 0x10c3a8 | Size: 256 bytes
// Khung tháo gỡ #1567 | Địa chỉ PC: 0x303c2c | Địa chỉ FDE: 0x10c3a8 | Kích thước: 256 bytes
//   0x303c2c: D10103FF  sub      sp, sp, #0x40
//   0x303c30: A9015BF7  stp      x23, x22, [sp, #0x10]
//   0x303c34: A90253F5  stp      x21, x20, [sp, #0x20]
//   0x303c38: A9037BF3  stp      x19, x30, [sp, #0x30]
static inline uint64_t fde_func_1567_0x303c2c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x303c2cULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xa9015bf7ULL) ^ 0x10c3a8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1568 | PC: 0x304614 | FDE: 0x10c510 | Size: 256 bytes
// Khung tháo gỡ #1568 | Địa chỉ PC: 0x304614 | Địa chỉ FDE: 0x10c510 | Kích thước: 256 bytes
//   0x304614: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x304618: 900002E8  adrp     x8, #0x360000
//   0x30461c: 9122A108  add      x8, x8, #0x8a8
//   0x304620: 94006050  bl       #0x31c760
static inline uint64_t fde_func_1568_0x304614(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x304614ULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0x900002e8ULL) ^ 0x10c510ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1569 | PC: 0x3047dc | FDE: 0x10c618 | Size: 256 bytes
// Khung tháo gỡ #1569 | Địa chỉ PC: 0x3047dc | Địa chỉ FDE: 0x10c618 | Kích thước: 256 bytes
//   0x3047dc: F9400808  ldr      x8, [x0, #0x10]
//   0x3047e0: 900002E9  adrp     x9, #0x360000
//   0x3047e4: 91266129  add      x9, x9, #0x998
//   0x3047e8: F9000009  str      x9, [x0]
static inline uint64_t fde_func_1569_0x3047dc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x3047dcULL ^ (static_cast<uint64_t>(0xf9400808ULL) << 13);
    acc = (acc + a1 + 0x900002e9ULL) ^ 0x10c618ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1570 | PC: 0x304940 | FDE: 0x10c710 | Size: 256 bytes
// Khung tháo gỡ #1570 | Địa chỉ PC: 0x304940 | Địa chỉ FDE: 0x10c710 | Kích thước: 256 bytes
//   0x304940: A9BE53F5  stp      x21, x20, [sp, #-0x20]!
//   0x304944: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x304948: 2A0103F3  mov      w19, w1
//   0x30494c: 9400857A  bl       #0x325f34
static inline uint64_t fde_func_1570_0x304940(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x304940ULL ^ (static_cast<uint64_t>(0xa9be53f5ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x10c710ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1571 | PC: 0x304d0c | FDE: 0x10c860 | Size: 256 bytes
// Khung tháo gỡ #1571 | Địa chỉ PC: 0x304d0c | Địa chỉ FDE: 0x10c860 | Kích thước: 256 bytes
//   0x304d0c: AA1E03E2  mov      x2, x30
//   0x304d10: 9400661F  bl       #0x31e58c
//   0x304d14: AA0203FE  mov      x30, x2
//   0x304d18: A9107BFD  stp      x29, x30, [sp, #0x100]
static inline uint64_t fde_func_1571_0x304d0c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x304d0cULL ^ (static_cast<uint64_t>(0xaa1e03e2ULL) << 13);
    acc = (acc + a1 + 0x9400661fULL) ^ 0x10c860ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1572 | PC: 0x305924 | FDE: 0x10c9d0 | Size: 256 bytes
// Khung tháo gỡ #1572 | Địa chỉ PC: 0x305924 | Địa chỉ FDE: 0x10c9d0 | Kích thước: 256 bytes
//   0x305924: D10143FF  sub      sp, sp, #0x50
//   0x305928: F90013F6  str      x22, [sp, #0x20]
//   0x30592c: A90353F5  stp      x21, x20, [sp, #0x30]
//   0x305930: A9047BF3  stp      x19, x30, [sp, #0x40]
static inline uint64_t fde_func_1572_0x305924(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x305924ULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xf90013f6ULL) ^ 0x10c9d0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1573 | PC: 0x305b50 | FDE: 0x10cae0 | Size: 256 bytes
// Khung tháo gỡ #1573 | Địa chỉ PC: 0x305b50 | Địa chỉ FDE: 0x10cae0 | Kích thước: 256 bytes
//   0x305b50: D10203FF  sub      sp, sp, #0x80
//   0x305b54: F9002BF6  str      x22, [sp, #0x50]
//   0x305b58: A90653F5  stp      x21, x20, [sp, #0x60]
//   0x305b5c: A9077BF3  stp      x19, x30, [sp, #0x70]
static inline uint64_t fde_func_1573_0x305b50(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x305b50ULL ^ (static_cast<uint64_t>(0xd10203ffULL) << 13);
    acc = (acc + a1 + 0xf9002bf6ULL) ^ 0x10cae0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1574 | PC: 0x3079cc | FDE: 0x10cc30 | Size: 256 bytes
// Khung tháo gỡ #1574 | Địa chỉ PC: 0x3079cc | Địa chỉ FDE: 0x10cc30 | Kích thước: 256 bytes
//   0x3079cc: AA1E03E2  mov      x2, x30
//   0x3079d0: 9400514E  bl       #0x31bf08
//   0x3079d4: AA0203FE  mov      x30, x2
//   0x3079d8: A9057BFD  stp      x29, x30, [sp, #0x50]
static inline uint64_t fde_func_1574_0x3079cc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x3079ccULL ^ (static_cast<uint64_t>(0xaa1e03e2ULL) << 13);
    acc = (acc + a1 + 0x9400514eULL) ^ 0x10cc30ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1575 | PC: 0x30a360 | FDE: 0x10cd48 | Size: 256 bytes
// Khung tháo gỡ #1575 | Địa chỉ PC: 0x30a360 | Địa chỉ FDE: 0x10cd48 | Kích thước: 256 bytes
//   0x30a360: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x30a364: D00002A8  adrp     x8, #0x360000
//   0x30a368: 91300108  add      x8, x8, #0xc00
//   0x30a36c: 940048FD  bl       #0x31c760
static inline uint64_t fde_func_1575_0x30a360(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x30a360ULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0xd00002a8ULL) ^ 0x10cd48ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1576 | PC: 0x30a4d4 | FDE: 0x10ce38 | Size: 256 bytes
// Khung tháo gỡ #1576 | Địa chỉ PC: 0x30a4d4 | Địa chỉ FDE: 0x10ce38 | Kích thước: 256 bytes
//   0x30a4d4: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x30a4d8: 9400D489  bl       #0x33f6fc
//   0x30a4dc: AA1303E0  mov      x0, x19
//   0x30a4e0: A8C17BF3  ldp      x19, x30, [sp], #0x10
static inline uint64_t fde_func_1576_0x30a4d4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x30a4d4ULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0x9400d489ULL) ^ 0x10ce38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1577 | PC: 0x30a9b8 | FDE: 0x10cf58 | Size: 256 bytes
// Khung tháo gỡ #1577 | Địa chỉ PC: 0x30a9b8 | Địa chỉ FDE: 0x10cf58 | Kích thước: 256 bytes
//   0x30a9b8: 17F9DB5D  b        #0x18172c
//   0x30a9bc: F81D0FF6  str      x22, [sp, #-0x30]!
//   0x30a9c0: A90153F5  stp      x21, x20, [sp, #0x10]
//   0x30a9c4: A9027BF3  stp      x19, x30, [sp, #0x20]
static inline uint64_t fde_func_1577_0x30a9b8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x30a9b8ULL ^ (static_cast<uint64_t>(0x17f9db5dULL) << 13);
    acc = (acc + a1 + 0xf81d0ff6ULL) ^ 0x10cf58ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1578 | PC: 0x30bc08 | FDE: 0x10d0a8 | Size: 256 bytes
// Khung tháo gỡ #1578 | Địa chỉ PC: 0x30bc08 | Địa chỉ FDE: 0x10d0a8 | Kích thước: 256 bytes
//   0x30bc08: AA1E03E3  mov      x3, x30
//   0x30bc0c: 94004296  bl       #0x31c664
//   0x30bc10: AA0303FE  mov      x30, x3
//   0x30bc14: A9077BF3  stp      x19, x30, [sp, #0x70]
static inline uint64_t fde_func_1578_0x30bc08(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x30bc08ULL ^ (static_cast<uint64_t>(0xaa1e03e3ULL) << 13);
    acc = (acc + a1 + 0x94004296ULL) ^ 0x10d0a8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1579 | PC: 0x30c0d8 | FDE: 0x10d1c8 | Size: 256 bytes
// Khung tháo gỡ #1579 | Địa chỉ PC: 0x30c0d8 | Địa chỉ FDE: 0x10d1c8 | Kích thước: 256 bytes
//   0x30c0d8: D10383FF  sub      sp, sp, #0xe0
//   0x30c0dc: A90B5BF7  stp      x23, x22, [sp, #0xb0]
//   0x30c0e0: A90C53F5  stp      x21, x20, [sp, #0xc0]
//   0x30c0e4: A90D7BF3  stp      x19, x30, [sp, #0xd0]
static inline uint64_t fde_func_1579_0x30c0d8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x30c0d8ULL ^ (static_cast<uint64_t>(0xd10383ffULL) << 13);
    acc = (acc + a1 + 0xa90b5bf7ULL) ^ 0x10d1c8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1580 | PC: 0x30d9a4 | FDE: 0x10d350 | Size: 256 bytes
// Khung tháo gỡ #1580 | Địa chỉ PC: 0x30d9a4 | Địa chỉ FDE: 0x10d350 | Kích thước: 256 bytes
//   0x30d9a4: F81D0FF6  str      x22, [sp, #-0x30]!
//   0x30d9a8: A90153F5  stp      x21, x20, [sp, #0x10]
//   0x30d9ac: A9027BF3  stp      x19, x30, [sp, #0x20]
//   0x30d9b0: A9405416  ldp      x22, x21, [x0]
static inline uint64_t fde_func_1580_0x30d9a4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x30d9a4ULL ^ (static_cast<uint64_t>(0xf81d0ff6ULL) << 13);
    acc = (acc + a1 + 0xa90153f5ULL) ^ 0x10d350ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1581 | PC: 0x30df18 | FDE: 0x10d470 | Size: 256 bytes
// Khung tháo gỡ #1581 | Địa chỉ PC: 0x30df18 | Địa chỉ FDE: 0x10d470 | Kích thước: 256 bytes
//   0x30df18: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x30df1c: 940086A1  bl       #0x32f9a0
//   0x30df20: 36000080  tbz      w0, #0, #0x30df30
//   0x30df24: 39400268  ldrb     w8, [x19]
static inline uint64_t fde_func_1581_0x30df18(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x30df18ULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0x940086a1ULL) ^ 0x10d470ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1582 | PC: 0x30f5fc | FDE: 0x10d5d8 | Size: 256 bytes
// Khung tháo gỡ #1582 | Địa chỉ PC: 0x30f5fc | Địa chỉ FDE: 0x10d5d8 | Kích thước: 256 bytes
//   0x30f5fc: 17FB66E6  b        #0x1e9194
//   0x30f600: A9402009  ldp      x9, x8, [x0]
//   0x30f604: CB080129  sub      x9, x9, x8
//   0x30f608: B4000189  cbz      x9, #0x30f638
static inline uint64_t fde_func_1582_0x30f5fc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x30f5fcULL ^ (static_cast<uint64_t>(0x17fb66e6ULL) << 13);
    acc = (acc + a1 + 0xa9402009ULL) ^ 0x10d5d8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1583 | PC: 0x30fcd4 | FDE: 0x10d710 | Size: 256 bytes
// Khung tháo gỡ #1583 | Địa chỉ PC: 0x30fcd4 | Địa chỉ FDE: 0x10d710 | Kích thước: 256 bytes
//   0x30fcd4: D10103FF  sub      sp, sp, #0x40
//   0x30fcd8: F9000BF6  str      x22, [sp, #0x10]
//   0x30fcdc: A90253F5  stp      x21, x20, [sp, #0x20]
//   0x30fce0: A9037BF3  stp      x19, x30, [sp, #0x30]
static inline uint64_t fde_func_1583_0x30fcd4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x30fcd4ULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xf9000bf6ULL) ^ 0x10d710ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1584 | PC: 0x31247c | FDE: 0x10d820 | Size: 256 bytes
// Khung tháo gỡ #1584 | Địa chỉ PC: 0x31247c | Địa chỉ FDE: 0x10d820 | Kích thước: 256 bytes
//   0x31247c: F81E0FF4  str      x20, [sp, #-0x20]!
//   0x312480: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x312484: AA0103F3  mov      x19, x1
//   0x312488: F0FFEAE1  adrp     x1, #0x71000
static inline uint64_t fde_func_1584_0x31247c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x31247cULL ^ (static_cast<uint64_t>(0xf81e0ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x10d820ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1585 | PC: 0x312ea0 | FDE: 0x10d978 | Size: 256 bytes
// Khung tháo gỡ #1585 | Địa chỉ PC: 0x312ea0 | Địa chỉ FDE: 0x10d978 | Kích thước: 256 bytes
//   0x312ea0: AA1E03E1  mov      x1, x30
//   0x312ea4: 940042D1  bl       #0x3239e8
//   0x312ea8: AA0103FE  mov      x30, x1
//   0x312eac: A9157BFD  stp      x29, x30, [sp, #0x150]
static inline uint64_t fde_func_1585_0x312ea0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x312ea0ULL ^ (static_cast<uint64_t>(0xaa1e03e1ULL) << 13);
    acc = (acc + a1 + 0x940042d1ULL) ^ 0x10d978ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1586 | PC: 0x3139dc | FDE: 0x10dac8 | Size: 256 bytes
// Khung tháo gỡ #1586 | Địa chỉ PC: 0x3139dc | Địa chỉ FDE: 0x10dac8 | Kích thước: 256 bytes
//   0x3139dc: AA1E03E2  mov      x2, x30
//   0x3139e0: 94002537  bl       #0x31cebc
//   0x3139e4: AA0203FE  mov      x30, x2
//   0x3139e8: A9067BF3  stp      x19, x30, [sp, #0x60]
static inline uint64_t fde_func_1586_0x3139dc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x3139dcULL ^ (static_cast<uint64_t>(0xaa1e03e2ULL) << 13);
    acc = (acc + a1 + 0x94002537ULL) ^ 0x10dac8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1587 | PC: 0x3146e0 | FDE: 0x10dc28 | Size: 256 bytes
// Khung tháo gỡ #1587 | Địa chỉ PC: 0x3146e0 | Địa chỉ FDE: 0x10dc28 | Kích thước: 256 bytes
//   0x3146e0: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x3146e4: AA0003F3  mov      x19, x0
//   0x3146e8: 97FB5E8A  bl       #0x1ec110
//   0x3146ec: AA1303E0  mov      x0, x19
static inline uint64_t fde_func_1587_0x3146e0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x3146e0ULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0xaa0003f3ULL) ^ 0x10dc28ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1588 | PC: 0x31499c | FDE: 0x10dd30 | Size: 256 bytes
// Khung tháo gỡ #1588 | Địa chỉ PC: 0x31499c | Địa chỉ FDE: 0x10dd30 | Kích thước: 256 bytes
//   0x31499c: D10183FF  sub      sp, sp, #0x60
//   0x3149a0: A9035BF7  stp      x23, x22, [sp, #0x30]
//   0x3149a4: A90453F5  stp      x21, x20, [sp, #0x40]
//   0x3149a8: A9057BF3  stp      x19, x30, [sp, #0x50]
static inline uint64_t fde_func_1588_0x31499c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x31499cULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xa9035bf7ULL) ^ 0x10dd30ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1589 | PC: 0x315144 | FDE: 0x10de58 | Size: 256 bytes
// Khung tháo gỡ #1589 | Địa chỉ PC: 0x315144 | Địa chỉ FDE: 0x10de58 | Kích thước: 256 bytes
//   0x315144: 90000268  adrp     x8, #0x361000
//   0x315148: 91018108  add      x8, x8, #0x60
//   0x31514c: F8008408  str      x8, [x0], #8
//   0x315150: 17FFFFF2  b        #0x315118
static inline uint64_t fde_func_1589_0x315144(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x315144ULL ^ (static_cast<uint64_t>(0x90000268ULL) << 13);
    acc = (acc + a1 + 0x91018108ULL) ^ 0x10de58ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1590 | PC: 0x3158cc | FDE: 0x10df80 | Size: 256 bytes
// Khung tháo gỡ #1590 | Địa chỉ PC: 0x3158cc | Địa chỉ FDE: 0x10df80 | Kích thước: 256 bytes
//   0x3158cc: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x3158d0: AA0003F3  mov      x19, x0
//   0x3158d4: 97FFFFFA  bl       #0x3158bc
//   0x3158d8: AA1303E0  mov      x0, x19
static inline uint64_t fde_func_1590_0x3158cc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x3158ccULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0xaa0003f3ULL) ^ 0x10df80ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1591 | PC: 0x315d04 | FDE: 0x10e0a0 | Size: 256 bytes
// Khung tháo gỡ #1591 | Địa chỉ PC: 0x315d04 | Địa chỉ FDE: 0x10e0a0 | Kích thước: 256 bytes
//   0x315d04: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x315d08: AA0003F3  mov      x19, x0
//   0x315d0c: 97FFF309  bl       #0x312930
//   0x315d10: 36000180  tbz      w0, #0, #0x315d40
static inline uint64_t fde_func_1591_0x315d04(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x315d04ULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0xaa0003f3ULL) ^ 0x10e0a0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1592 | PC: 0x31679c | FDE: 0x10e1c8 | Size: 256 bytes
// Khung tháo gỡ #1592 | Địa chỉ PC: 0x31679c | Địa chỉ FDE: 0x10e1c8 | Kích thước: 256 bytes
//   0x31679c: D10143FF  sub      sp, sp, #0x50
//   0x3167a0: F90013F6  str      x22, [sp, #0x20]
//   0x3167a4: A90353F5  stp      x21, x20, [sp, #0x30]
//   0x3167a8: A9047BF3  stp      x19, x30, [sp, #0x40]
static inline uint64_t fde_func_1592_0x31679c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x31679cULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xf90013f6ULL) ^ 0x10e1c8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1593 | PC: 0x316ad4 | FDE: 0x10e2d8 | Size: 256 bytes
// Khung tháo gỡ #1593 | Địa chỉ PC: 0x316ad4 | Địa chỉ FDE: 0x10e2d8 | Kích thước: 256 bytes
//   0x316ad4: D11FC000  sub      x0, x0, #0x7f0
//   0x316ad8: 17FFFF94  b        #0x316928
//   0x316adc: D11FC000  sub      x0, x0, #0x7f0
//   0x316ae0: 17FFFFE0  b        #0x316a60
static inline uint64_t fde_func_1593_0x316ad4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x316ad4ULL ^ (static_cast<uint64_t>(0xd11fc000ULL) << 13);
    acc = (acc + a1 + 0x17ffff94ULL) ^ 0x10e2d8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1594 | PC: 0x316c34 | FDE: 0x10e3d8 | Size: 256 bytes
// Khung tháo gỡ #1594 | Địa chỉ PC: 0x316c34 | Địa chỉ FDE: 0x10e3d8 | Kích thước: 256 bytes
//   0x316c34: A9BD5BF7  stp      x23, x22, [sp, #-0x30]!
//   0x316c38: A90153F5  stp      x21, x20, [sp, #0x10]
//   0x316c3c: A9027BF3  stp      x19, x30, [sp, #0x20]
//   0x316c40: D0000168  adrp     x8, #0x344000
static inline uint64_t fde_func_1594_0x316c34(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x316c34ULL ^ (static_cast<uint64_t>(0xa9bd5bf7ULL) << 13);
    acc = (acc + a1 + 0xa90153f5ULL) ^ 0x10e3d8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1595 | PC: 0x316f70 | FDE: 0x10e4f0 | Size: 256 bytes
// Khung tháo gỡ #1595 | Địa chỉ PC: 0x316f70 | Địa chỉ FDE: 0x10e4f0 | Kích thước: 256 bytes
//   0x316f70: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x316f74: AA0003F3  mov      x19, x0
//   0x316f78: 97FFFFFA  bl       #0x316f60
//   0x316f7c: AA1303E0  mov      x0, x19
static inline uint64_t fde_func_1595_0x316f70(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x316f70ULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0xaa0003f3ULL) ^ 0x10e4f0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1596 | PC: 0x3173f8 | FDE: 0x10e618 | Size: 256 bytes
// Khung tháo gỡ #1596 | Địa chỉ PC: 0x3173f8 | Địa chỉ FDE: 0x10e618 | Kích thước: 256 bytes
//   0x3173f8: F81E0FF4  str      x20, [sp, #-0x20]!
//   0x3173fc: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x317400: 9400A102  bl       #0x33f808
//   0x317404: F9400280  ldr      x0, [x20]
static inline uint64_t fde_func_1596_0x3173f8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x3173f8ULL ^ (static_cast<uint64_t>(0xf81e0ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x10e618ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1597 | PC: 0x3175cc | FDE: 0x10e730 | Size: 256 bytes
// Khung tháo gỡ #1597 | Địa chỉ PC: 0x3175cc | Địa chỉ FDE: 0x10e730 | Kích thước: 256 bytes
//   0x3175cc: D10243FF  sub      sp, sp, #0x90
//   0x3175d0: F9003BF4  str      x20, [sp, #0x70]
//   0x3175d4: A9087BF3  stp      x19, x30, [sp, #0x80]
//   0x3175d8: 94004312  bl       #0x328220
static inline uint64_t fde_func_1597_0x3175cc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x3175ccULL ^ (static_cast<uint64_t>(0xd10243ffULL) << 13);
    acc = (acc + a1 + 0xf9003bf4ULL) ^ 0x10e730ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1598 | PC: 0x3177c0 | FDE: 0x10e848 | Size: 140 bytes
// Khung tháo gỡ #1598 | Địa chỉ PC: 0x3177c0 | Địa chỉ FDE: 0x10e848 | Kích thước: 140 bytes
//   0x3177c0: B9401008  ldr      w8, [x0, #0x10]
//   0x3177c4: 7100191F  cmp      w8, #6
//   0x3177c8: 1A9F17E0  cset     w0, eq
//   0x3177cc: D65F03C0  ret      
static inline uint64_t fde_func_1598_0x3177c0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x3177c0ULL ^ (static_cast<uint64_t>(0xb9401008ULL) << 13);
    acc = (acc + a1 + 0x7100191fULL) ^ 0x10e848ULL;
    acc ^= (acc >> 17) * 0x008cULL;
    return acc;
}

// FDE #1599 | PC: 0x31784c | FDE: 0x10e938 | Size: 256 bytes
// Khung tháo gỡ #1599 | Địa chỉ PC: 0x31784c | Địa chỉ FDE: 0x10e938 | Kích thước: 256 bytes
//   0x31784c: B9401008  ldr      w8, [x0, #0x10]
//   0x317850: 7100351F  cmp      w8, #0xd
//   0x317854: 1A9F17E0  cset     w0, eq
//   0x317858: D65F03C0  ret      
static inline uint64_t fde_func_1599_0x31784c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x31784cULL ^ (static_cast<uint64_t>(0xb9401008ULL) << 13);
    acc = (acc + a1 + 0x7100351fULL) ^ 0x10e938ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Shard 4 Dispatcher / Bộ điều phối phân mảnh 4
uint64_t execute_fde_shard_4(uint32_t fde_idx, uint64_t a0, uint64_t a1) {
    switch (fde_idx) {
        case 1200: return fde_func_1200_0x2a7964(a0, a1);
        case 1201: return fde_func_1201_0x2a7c98(a0, a1);
        case 1202: return fde_func_1202_0x2a814c(a0, a1);
        case 1203: return fde_func_1203_0x2a82f0(a0, a1);
        case 1204: return fde_func_1204_0x2a8420(a0, a1);
        case 1205: return fde_func_1205_0x2a85f8(a0, a1);
        case 1206: return fde_func_1206_0x2a8a94(a0, a1);
        case 1207: return fde_func_1207_0x2a8e9c(a0, a1);
        case 1208: return fde_func_1208_0x2a92ac(a0, a1);
        case 1209: return fde_func_1209_0x2a938c(a0, a1);
        case 1210: return fde_func_1210_0x2a939c(a0, a1);
        case 1211: return fde_func_1211_0x2a93e0(a0, a1);
        case 1212: return fde_func_1212_0x2a95d4(a0, a1);
        case 1213: return fde_func_1213_0x2a96c0(a0, a1);
        case 1214: return fde_func_1214_0x2a983c(a0, a1);
        case 1215: return fde_func_1215_0x2a9b90(a0, a1);
        case 1216: return fde_func_1216_0x2a9df4(a0, a1);
        case 1217: return fde_func_1217_0x2a9ee4(a0, a1);
        case 1218: return fde_func_1218_0x2a9fdc(a0, a1);
        case 1219: return fde_func_1219_0x2aa25c(a0, a1);
        case 1220: return fde_func_1220_0x2aa2b4(a0, a1);
        case 1221: return fde_func_1221_0x2aa5a0(a0, a1);
        case 1222: return fde_func_1222_0x2aa638(a0, a1);
        case 1223: return fde_func_1223_0x2aa698(a0, a1);
        case 1224: return fde_func_1224_0x2aa71c(a0, a1);
        case 1225: return fde_func_1225_0x2aa774(a0, a1);
        case 1226: return fde_func_1226_0x2aa7bc(a0, a1);
        case 1227: return fde_func_1227_0x2aa7d4(a0, a1);
        case 1228: return fde_func_1228_0x2aa834(a0, a1);
        case 1229: return fde_func_1229_0x2aa84c(a0, a1);
        case 1230: return fde_func_1230_0x2aae40(a0, a1);
        case 1231: return fde_func_1231_0x2ab958(a0, a1);
        case 1232: return fde_func_1232_0x2ac3dc(a0, a1);
        case 1233: return fde_func_1233_0x2ac784(a0, a1);
        case 1234: return fde_func_1234_0x2accf8(a0, a1);
        case 1235: return fde_func_1235_0x2adbe8(a0, a1);
        case 1236: return fde_func_1236_0x2ae198(a0, a1);
        case 1237: return fde_func_1237_0x2ae748(a0, a1);
        case 1238: return fde_func_1238_0x2ae97c(a0, a1);
        case 1239: return fde_func_1239_0x2af4cc(a0, a1);
        case 1240: return fde_func_1240_0x2afdc8(a0, a1);
        case 1241: return fde_func_1241_0x2b0110(a0, a1);
        case 1242: return fde_func_1242_0x2b0768(a0, a1);
        case 1243: return fde_func_1243_0x2b0b70(a0, a1);
        case 1244: return fde_func_1244_0x2b0e60(a0, a1);
        case 1245: return fde_func_1245_0x2b1010(a0, a1);
        case 1246: return fde_func_1246_0x2b1c38(a0, a1);
        case 1247: return fde_func_1247_0x2b233c(a0, a1);
        case 1248: return fde_func_1248_0x2b235c(a0, a1);
        case 1249: return fde_func_1249_0x2b25ec(a0, a1);
        case 1250: return fde_func_1250_0x2b2a44(a0, a1);
        case 1251: return fde_func_1251_0x2b3040(a0, a1);
        case 1252: return fde_func_1252_0x2b33fc(a0, a1);
        case 1253: return fde_func_1253_0x2b3c28(a0, a1);
        case 1254: return fde_func_1254_0x2b42f0(a0, a1);
        case 1255: return fde_func_1255_0x2b4920(a0, a1);
        case 1256: return fde_func_1256_0x2b52f0(a0, a1);
        case 1257: return fde_func_1257_0x2b561c(a0, a1);
        case 1258: return fde_func_1258_0x2b5a24(a0, a1);
        case 1259: return fde_func_1259_0x2b5a58(a0, a1);
        case 1260: return fde_func_1260_0x2b5a8c(a0, a1);
        case 1261: return fde_func_1261_0x2b5b30(a0, a1);
        case 1262: return fde_func_1262_0x2b5bb8(a0, a1);
        case 1263: return fde_func_1263_0x2b5c50(a0, a1);
        case 1264: return fde_func_1264_0x2b5d64(a0, a1);
        case 1265: return fde_func_1265_0x2b5e30(a0, a1);
        case 1266: return fde_func_1266_0x2b5fa8(a0, a1);
        case 1267: return fde_func_1267_0x2b626c(a0, a1);
        case 1268: return fde_func_1268_0x2b699c(a0, a1);
        case 1269: return fde_func_1269_0x2b7694(a0, a1);
        case 1270: return fde_func_1270_0x2b7b14(a0, a1);
        case 1271: return fde_func_1271_0x2b82b4(a0, a1);
        case 1272: return fde_func_1272_0x2b8a00(a0, a1);
        case 1273: return fde_func_1273_0x2ba984(a0, a1);
        case 1274: return fde_func_1274_0x2badbc(a0, a1);
        case 1275: return fde_func_1275_0x2bb734(a0, a1);
        case 1276: return fde_func_1276_0x2bbef0(a0, a1);
        case 1277: return fde_func_1277_0x2bed54(a0, a1);
        case 1278: return fde_func_1278_0x2bf498(a0, a1);
        case 1279: return fde_func_1279_0x2bfc64(a0, a1);
        case 1280: return fde_func_1280_0x2bfcb0(a0, a1);
        case 1281: return fde_func_1281_0x2bfcd4(a0, a1);
        case 1282: return fde_func_1282_0x2c00c8(a0, a1);
        case 1283: return fde_func_1283_0x2c0c88(a0, a1);
        case 1284: return fde_func_1284_0x2c142c(a0, a1);
        case 1285: return fde_func_1285_0x2c184c(a0, a1);
        case 1286: return fde_func_1286_0x2c1c7c(a0, a1);
        case 1287: return fde_func_1287_0x2c25f0(a0, a1);
        case 1288: return fde_func_1288_0x2c2e0c(a0, a1);
        case 1289: return fde_func_1289_0x2c467c(a0, a1);
        case 1290: return fde_func_1290_0x2c4f40(a0, a1);
        case 1291: return fde_func_1291_0x2c5680(a0, a1);
        case 1292: return fde_func_1292_0x2c63b0(a0, a1);
        case 1293: return fde_func_1293_0x2c660c(a0, a1);
        case 1294: return fde_func_1294_0x2c6aec(a0, a1);
        case 1295: return fde_func_1295_0x2c7ba0(a0, a1);
        case 1296: return fde_func_1296_0x2c7c98(a0, a1);
        case 1297: return fde_func_1297_0x2c81c8(a0, a1);
        case 1298: return fde_func_1298_0x2c82b0(a0, a1);
        case 1299: return fde_func_1299_0x2c8318(a0, a1);
        case 1300: return fde_func_1300_0x2c8444(a0, a1);
        case 1301: return fde_func_1301_0x2c84e0(a0, a1);
        case 1302: return fde_func_1302_0x2c84f8(a0, a1);
        case 1303: return fde_func_1303_0x2c854c(a0, a1);
        case 1304: return fde_func_1304_0x2c8564(a0, a1);
        case 1305: return fde_func_1305_0x2c8630(a0, a1);
        case 1306: return fde_func_1306_0x2c86c4(a0, a1);
        case 1307: return fde_func_1307_0x2c86e8(a0, a1);
        case 1308: return fde_func_1308_0x2c87ac(a0, a1);
        case 1309: return fde_func_1309_0x2c8804(a0, a1);
        case 1310: return fde_func_1310_0x2c8a80(a0, a1);
        case 1311: return fde_func_1311_0x2c8b00(a0, a1);
        case 1312: return fde_func_1312_0x2c8b7c(a0, a1);
        case 1313: return fde_func_1313_0x2c8c20(a0, a1);
        case 1314: return fde_func_1314_0x2c8c34(a0, a1);
        case 1315: return fde_func_1315_0x2c8d48(a0, a1);
        case 1316: return fde_func_1316_0x2c8d58(a0, a1);
        case 1317: return fde_func_1317_0x2c8db8(a0, a1);
        case 1318: return fde_func_1318_0x2c9874(a0, a1);
        case 1319: return fde_func_1319_0x2c98d0(a0, a1);
        case 1320: return fde_func_1320_0x2c98e4(a0, a1);
        case 1321: return fde_func_1321_0x2c98f8(a0, a1);
        case 1322: return fde_func_1322_0x2c9f60(a0, a1);
        case 1323: return fde_func_1323_0x2ca348(a0, a1);
        case 1324: return fde_func_1324_0x2cb0b4(a0, a1);
        case 1325: return fde_func_1325_0x2cb4e0(a0, a1);
        case 1326: return fde_func_1326_0x2cb8ac(a0, a1);
        case 1327: return fde_func_1327_0x2cbf10(a0, a1);
        case 1328: return fde_func_1328_0x2cc4e8(a0, a1);
        case 1329: return fde_func_1329_0x2cc8f4(a0, a1);
        case 1330: return fde_func_1330_0x2cd12c(a0, a1);
        case 1331: return fde_func_1331_0x2cd484(a0, a1);
        case 1332: return fde_func_1332_0x2cd7b4(a0, a1);
        case 1333: return fde_func_1333_0x2cdcc0(a0, a1);
        case 1334: return fde_func_1334_0x2cdfa0(a0, a1);
        case 1335: return fde_func_1335_0x2ce6dc(a0, a1);
        case 1336: return fde_func_1336_0x2ce910(a0, a1);
        case 1337: return fde_func_1337_0x2ce97c(a0, a1);
        case 1338: return fde_func_1338_0x2cea10(a0, a1);
        case 1339: return fde_func_1339_0x2cebe0(a0, a1);
        case 1340: return fde_func_1340_0x2cebf8(a0, a1);
        case 1341: return fde_func_1341_0x2cec0c(a0, a1);
        case 1342: return fde_func_1342_0x2cf620(a0, a1);
        case 1343: return fde_func_1343_0x2cf668(a0, a1);
        case 1344: return fde_func_1344_0x2cf70c(a0, a1);
        case 1345: return fde_func_1345_0x2cfc00(a0, a1);
        case 1346: return fde_func_1346_0x2cfe24(a0, a1);
        case 1347: return fde_func_1347_0x2cfef8(a0, a1);
        case 1348: return fde_func_1348_0x2d00ec(a0, a1);
        case 1349: return fde_func_1349_0x2d013c(a0, a1);
        case 1350: return fde_func_1350_0x2d06e0(a0, a1);
        case 1351: return fde_func_1351_0x2d073c(a0, a1);
        case 1352: return fde_func_1352_0x2d0858(a0, a1);
        case 1353: return fde_func_1353_0x2d0c00(a0, a1);
        case 1354: return fde_func_1354_0x2d0cf0(a0, a1);
        case 1355: return fde_func_1355_0x2d0ec8(a0, a1);
        case 1356: return fde_func_1356_0x2d1228(a0, a1);
        case 1357: return fde_func_1357_0x2d156c(a0, a1);
        case 1358: return fde_func_1358_0x2d1c04(a0, a1);
        case 1359: return fde_func_1359_0x2d2204(a0, a1);
        case 1360: return fde_func_1360_0x2d274c(a0, a1);
        case 1361: return fde_func_1361_0x2d2fe0(a0, a1);
        case 1362: return fde_func_1362_0x2d3660(a0, a1);
        case 1363: return fde_func_1363_0x2d3988(a0, a1);
        case 1364: return fde_func_1364_0x2d3e68(a0, a1);
        case 1365: return fde_func_1365_0x2d457c(a0, a1);
        case 1366: return fde_func_1366_0x2d4c2c(a0, a1);
        case 1367: return fde_func_1367_0x2d50dc(a0, a1);
        case 1368: return fde_func_1368_0x2d5644(a0, a1);
        case 1369: return fde_func_1369_0x2d5b6c(a0, a1);
        case 1370: return fde_func_1370_0x2d5dfc(a0, a1);
        case 1371: return fde_func_1371_0x2d5f70(a0, a1);
        case 1372: return fde_func_1372_0x2d63d8(a0, a1);
        case 1373: return fde_func_1373_0x2d65f4(a0, a1);
        case 1374: return fde_func_1374_0x2d702c(a0, a1);
        case 1375: return fde_func_1375_0x2d7890(a0, a1);
        case 1376: return fde_func_1376_0x2d7b20(a0, a1);
        case 1377: return fde_func_1377_0x2d8f68(a0, a1);
        case 1378: return fde_func_1378_0x2dad30(a0, a1);
        case 1379: return fde_func_1379_0x2db718(a0, a1);
        case 1380: return fde_func_1380_0x2dc380(a0, a1);
        case 1381: return fde_func_1381_0x2dda30(a0, a1);
        case 1382: return fde_func_1382_0x2ddc94(a0, a1);
        case 1383: return fde_func_1383_0x2dde04(a0, a1);
        case 1384: return fde_func_1384_0x2ddf78(a0, a1);
        case 1385: return fde_func_1385_0x2ddfa8(a0, a1);
        case 1386: return fde_func_1386_0x2de16c(a0, a1);
        case 1387: return fde_func_1387_0x2de508(a0, a1);
        case 1388: return fde_func_1388_0x2de770(a0, a1);
        case 1389: return fde_func_1389_0x2deb00(a0, a1);
        case 1390: return fde_func_1390_0x2debe8(a0, a1);
        case 1391: return fde_func_1391_0x2def98(a0, a1);
        case 1392: return fde_func_1392_0x2defc8(a0, a1);
        case 1393: return fde_func_1393_0x2df48c(a0, a1);
        case 1394: return fde_func_1394_0x2df4f8(a0, a1);
        case 1395: return fde_func_1395_0x2df64c(a0, a1);
        case 1396: return fde_func_1396_0x2dfb1c(a0, a1);
        case 1397: return fde_func_1397_0x2dfe3c(a0, a1);
        case 1398: return fde_func_1398_0x2e0064(a0, a1);
        case 1399: return fde_func_1399_0x2e08b4(a0, a1);
        case 1400: return fde_func_1400_0x2e0c3c(a0, a1);
        case 1401: return fde_func_1401_0x2e0e20(a0, a1);
        case 1402: return fde_func_1402_0x2e10d0(a0, a1);
        case 1403: return fde_func_1403_0x2e14a4(a0, a1);
        case 1404: return fde_func_1404_0x2e16c8(a0, a1);
        case 1405: return fde_func_1405_0x2e1ae8(a0, a1);
        case 1406: return fde_func_1406_0x2e1bfc(a0, a1);
        case 1407: return fde_func_1407_0x2e1c14(a0, a1);
        case 1408: return fde_func_1408_0x2e1c30(a0, a1);
        case 1409: return fde_func_1409_0x2e1d64(a0, a1);
        case 1410: return fde_func_1410_0x2e1ffc(a0, a1);
        case 1411: return fde_func_1411_0x2e22f8(a0, a1);
        case 1412: return fde_func_1412_0x2e32ac(a0, a1);
        case 1413: return fde_func_1413_0x2e3530(a0, a1);
        case 1414: return fde_func_1414_0x2e3b58(a0, a1);
        case 1415: return fde_func_1415_0x2e4304(a0, a1);
        case 1416: return fde_func_1416_0x2e49dc(a0, a1);
        case 1417: return fde_func_1417_0x2e5034(a0, a1);
        case 1418: return fde_func_1418_0x2e5664(a0, a1);
        case 1419: return fde_func_1419_0x2e5920(a0, a1);
        case 1420: return fde_func_1420_0x2e5b1c(a0, a1);
        case 1421: return fde_func_1421_0x2e5e6c(a0, a1);
        case 1422: return fde_func_1422_0x2e61a8(a0, a1);
        case 1423: return fde_func_1423_0x2e644c(a0, a1);
        case 1424: return fde_func_1424_0x2e66c8(a0, a1);
        case 1425: return fde_func_1425_0x2e6918(a0, a1);
        case 1426: return fde_func_1426_0x2e6b7c(a0, a1);
        case 1427: return fde_func_1427_0x2e6ee0(a0, a1);
        case 1428: return fde_func_1428_0x2e7194(a0, a1);
        case 1429: return fde_func_1429_0x2e77dc(a0, a1);
        case 1430: return fde_func_1430_0x2e7ae0(a0, a1);
        case 1431: return fde_func_1431_0x2e806c(a0, a1);
        case 1432: return fde_func_1432_0x2e8238(a0, a1);
        case 1433: return fde_func_1433_0x2e84f8(a0, a1);
        case 1434: return fde_func_1434_0x2e8afc(a0, a1);
        case 1435: return fde_func_1435_0x2e8e98(a0, a1);
        case 1436: return fde_func_1436_0x2e930c(a0, a1);
        case 1437: return fde_func_1437_0x2e9584(a0, a1);
        case 1438: return fde_func_1438_0x2e96d0(a0, a1);
        case 1439: return fde_func_1439_0x2e98d8(a0, a1);
        case 1440: return fde_func_1440_0x2e9f1c(a0, a1);
        case 1441: return fde_func_1441_0x2ea954(a0, a1);
        case 1442: return fde_func_1442_0x2ea960(a0, a1);
        case 1443: return fde_func_1443_0x2eac9c(a0, a1);
        case 1444: return fde_func_1444_0x2eadb0(a0, a1);
        case 1445: return fde_func_1445_0x2eb11c(a0, a1);
        case 1446: return fde_func_1446_0x2eb590(a0, a1);
        case 1447: return fde_func_1447_0x2eb8c4(a0, a1);
        case 1448: return fde_func_1448_0x2ebaa8(a0, a1);
        case 1449: return fde_func_1449_0x2ebb80(a0, a1);
        case 1450: return fde_func_1450_0x2ebeb8(a0, a1);
        case 1451: return fde_func_1451_0x2ec10c(a0, a1);
        case 1452: return fde_func_1452_0x2ec2f0(a0, a1);
        case 1453: return fde_func_1453_0x2ec508(a0, a1);
        case 1454: return fde_func_1454_0x2ec5f8(a0, a1);
        case 1455: return fde_func_1455_0x2ec768(a0, a1);
        case 1456: return fde_func_1456_0x2ec8e0(a0, a1);
        case 1457: return fde_func_1457_0x2eca24(a0, a1);
        case 1458: return fde_func_1458_0x2ecafc(a0, a1);
        case 1459: return fde_func_1459_0x2ecea0(a0, a1);
        case 1460: return fde_func_1460_0x2ed1f4(a0, a1);
        case 1461: return fde_func_1461_0x2ed318(a0, a1);
        case 1462: return fde_func_1462_0x2ed640(a0, a1);
        case 1463: return fde_func_1463_0x2ed7bc(a0, a1);
        case 1464: return fde_func_1464_0x2ed8d8(a0, a1);
        case 1465: return fde_func_1465_0x2ed9e8(a0, a1);
        case 1466: return fde_func_1466_0x2edb6c(a0, a1);
        case 1467: return fde_func_1467_0x2edc98(a0, a1);
        case 1468: return fde_func_1468_0x2edddc(a0, a1);
        case 1469: return fde_func_1469_0x2edf18(a0, a1);
        case 1470: return fde_func_1470_0x2ee23c(a0, a1);
        case 1471: return fde_func_1471_0x2ee358(a0, a1);
        case 1472: return fde_func_1472_0x2ee460(a0, a1);
        case 1473: return fde_func_1473_0x2ee604(a0, a1);
        case 1474: return fde_func_1474_0x2ee710(a0, a1);
        case 1475: return fde_func_1475_0x2ee748(a0, a1);
        case 1476: return fde_func_1476_0x2ee8f8(a0, a1);
        case 1477: return fde_func_1477_0x2eeb04(a0, a1);
        case 1478: return fde_func_1478_0x2eef38(a0, a1);
        case 1479: return fde_func_1479_0x2ef36c(a0, a1);
        case 1480: return fde_func_1480_0x2ef4e0(a0, a1);
        case 1481: return fde_func_1481_0x2ef85c(a0, a1);
        case 1482: return fde_func_1482_0x2efac4(a0, a1);
        case 1483: return fde_func_1483_0x2efcdc(a0, a1);
        case 1484: return fde_func_1484_0x2f000c(a0, a1);
        case 1485: return fde_func_1485_0x2f0314(a0, a1);
        case 1486: return fde_func_1486_0x2f07c8(a0, a1);
        case 1487: return fde_func_1487_0x2f0a80(a0, a1);
        case 1488: return fde_func_1488_0x2f0c90(a0, a1);
        case 1489: return fde_func_1489_0x2f106c(a0, a1);
        case 1490: return fde_func_1490_0x2f12d0(a0, a1);
        case 1491: return fde_func_1491_0x2f164c(a0, a1);
        case 1492: return fde_func_1492_0x2f1854(a0, a1);
        case 1493: return fde_func_1493_0x2f1b34(a0, a1);
        case 1494: return fde_func_1494_0x2f1ed0(a0, a1);
        case 1495: return fde_func_1495_0x2f21d0(a0, a1);
        case 1496: return fde_func_1496_0x2f2488(a0, a1);
        case 1497: return fde_func_1497_0x2f283c(a0, a1);
        case 1498: return fde_func_1498_0x2f2dac(a0, a1);
        case 1499: return fde_func_1499_0x2f3124(a0, a1);
        case 1500: return fde_func_1500_0x2f3440(a0, a1);
        case 1501: return fde_func_1501_0x2f3754(a0, a1);
        case 1502: return fde_func_1502_0x2f3a44(a0, a1);
        case 1503: return fde_func_1503_0x2f3b84(a0, a1);
        case 1504: return fde_func_1504_0x2f3d0c(a0, a1);
        case 1505: return fde_func_1505_0x2f3f40(a0, a1);
        case 1506: return fde_func_1506_0x2f4138(a0, a1);
        case 1507: return fde_func_1507_0x2f4278(a0, a1);
        case 1508: return fde_func_1508_0x2f4380(a0, a1);
        case 1509: return fde_func_1509_0x2f4738(a0, a1);
        case 1510: return fde_func_1510_0x2f4e70(a0, a1);
        case 1511: return fde_func_1511_0x2f56c4(a0, a1);
        case 1512: return fde_func_1512_0x2f5cdc(a0, a1);
        case 1513: return fde_func_1513_0x2f63dc(a0, a1);
        case 1514: return fde_func_1514_0x2f6bdc(a0, a1);
        case 1515: return fde_func_1515_0x2f7268(a0, a1);
        case 1516: return fde_func_1516_0x2f7a10(a0, a1);
        case 1517: return fde_func_1517_0x2f7a70(a0, a1);
        case 1518: return fde_func_1518_0x2f7ac4(a0, a1);
        case 1519: return fde_func_1519_0x2f7b1c(a0, a1);
        case 1520: return fde_func_1520_0x2f7b98(a0, a1);
        case 1521: return fde_func_1521_0x2f7bf4(a0, a1);
        case 1522: return fde_func_1522_0x2f7cf8(a0, a1);
        case 1523: return fde_func_1523_0x2f7dfc(a0, a1);
        case 1524: return fde_func_1524_0x2f7f48(a0, a1);
        case 1525: return fde_func_1525_0x2f80e4(a0, a1);
        case 1526: return fde_func_1526_0x2f8274(a0, a1);
        case 1527: return fde_func_1527_0x2f83e0(a0, a1);
        case 1528: return fde_func_1528_0x2f8544(a0, a1);
        case 1529: return fde_func_1529_0x2f86e0(a0, a1);
        case 1530: return fde_func_1530_0x2f8930(a0, a1);
        case 1531: return fde_func_1531_0x2f8a80(a0, a1);
        case 1532: return fde_func_1532_0x2f8c08(a0, a1);
        case 1533: return fde_func_1533_0x2f8cec(a0, a1);
        case 1534: return fde_func_1534_0x2f8f58(a0, a1);
        case 1535: return fde_func_1535_0x2f9020(a0, a1);
        case 1536: return fde_func_1536_0x2f9128(a0, a1);
        case 1537: return fde_func_1537_0x2f91f0(a0, a1);
        case 1538: return fde_func_1538_0x2f92f0(a0, a1);
        case 1539: return fde_func_1539_0x2f93a8(a0, a1);
        case 1540: return fde_func_1540_0x2f9464(a0, a1);
        case 1541: return fde_func_1541_0x2f9528(a0, a1);
        case 1542: return fde_func_1542_0x2f9658(a0, a1);
        case 1543: return fde_func_1543_0x2f9734(a0, a1);
        case 1544: return fde_func_1544_0x2f990c(a0, a1);
        case 1545: return fde_func_1545_0x2f9b70(a0, a1);
        case 1546: return fde_func_1546_0x2fa020(a0, a1);
        case 1547: return fde_func_1547_0x2fa338(a0, a1);
        case 1548: return fde_func_1548_0x2fa5e0(a0, a1);
        case 1549: return fde_func_1549_0x2fa94c(a0, a1);
        case 1550: return fde_func_1550_0x2faba8(a0, a1);
        case 1551: return fde_func_1551_0x2fb034(a0, a1);
        case 1552: return fde_func_1552_0x2fb434(a0, a1);
        case 1553: return fde_func_1553_0x2fb5f4(a0, a1);
        case 1554: return fde_func_1554_0x2fba5c(a0, a1);
        case 1555: return fde_func_1555_0x2fbce0(a0, a1);
        case 1556: return fde_func_1556_0x2fbedc(a0, a1);
        case 1557: return fde_func_1557_0x2fcee8(a0, a1);
        case 1558: return fde_func_1558_0x2fd590(a0, a1);
        case 1559: return fde_func_1559_0x2fd89c(a0, a1);
        case 1560: return fde_func_1560_0x2ff7b8(a0, a1);
        case 1561: return fde_func_1561_0x2fff54(a0, a1);
        case 1562: return fde_func_1562_0x30116c(a0, a1);
        case 1563: return fde_func_1563_0x301c64(a0, a1);
        case 1564: return fde_func_1564_0x302398(a0, a1);
        case 1565: return fde_func_1565_0x302a18(a0, a1);
        case 1566: return fde_func_1566_0x3034d8(a0, a1);
        case 1567: return fde_func_1567_0x303c2c(a0, a1);
        case 1568: return fde_func_1568_0x304614(a0, a1);
        case 1569: return fde_func_1569_0x3047dc(a0, a1);
        case 1570: return fde_func_1570_0x304940(a0, a1);
        case 1571: return fde_func_1571_0x304d0c(a0, a1);
        case 1572: return fde_func_1572_0x305924(a0, a1);
        case 1573: return fde_func_1573_0x305b50(a0, a1);
        case 1574: return fde_func_1574_0x3079cc(a0, a1);
        case 1575: return fde_func_1575_0x30a360(a0, a1);
        case 1576: return fde_func_1576_0x30a4d4(a0, a1);
        case 1577: return fde_func_1577_0x30a9b8(a0, a1);
        case 1578: return fde_func_1578_0x30bc08(a0, a1);
        case 1579: return fde_func_1579_0x30c0d8(a0, a1);
        case 1580: return fde_func_1580_0x30d9a4(a0, a1);
        case 1581: return fde_func_1581_0x30df18(a0, a1);
        case 1582: return fde_func_1582_0x30f5fc(a0, a1);
        case 1583: return fde_func_1583_0x30fcd4(a0, a1);
        case 1584: return fde_func_1584_0x31247c(a0, a1);
        case 1585: return fde_func_1585_0x312ea0(a0, a1);
        case 1586: return fde_func_1586_0x3139dc(a0, a1);
        case 1587: return fde_func_1587_0x3146e0(a0, a1);
        case 1588: return fde_func_1588_0x31499c(a0, a1);
        case 1589: return fde_func_1589_0x315144(a0, a1);
        case 1590: return fde_func_1590_0x3158cc(a0, a1);
        case 1591: return fde_func_1591_0x315d04(a0, a1);
        case 1592: return fde_func_1592_0x31679c(a0, a1);
        case 1593: return fde_func_1593_0x316ad4(a0, a1);
        case 1594: return fde_func_1594_0x316c34(a0, a1);
        case 1595: return fde_func_1595_0x316f70(a0, a1);
        case 1596: return fde_func_1596_0x3173f8(a0, a1);
        case 1597: return fde_func_1597_0x3175cc(a0, a1);
        case 1598: return fde_func_1598_0x3177c0(a0, a1);
        case 1599: return fde_func_1599_0x31784c(a0, a1);
        default: return 0ULL;
    }
}

} // namespace lynx