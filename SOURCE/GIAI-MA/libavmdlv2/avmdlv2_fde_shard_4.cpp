// ============================================================================
// Clean-Room C++17 AArch64 Function Shard 4/5 for libavmdlv2.so
// Phân mảnh Hàm AArch64 C++17 sạch 4/5 cho libavmdlv2.so
// Covers .text function indices [1140 .. 1519] out of 1900 total functions
// Bao phủ chỉ số hàm .text [1140 .. 1519] trên tổng số 1900 hàm
// ============================================================================
#include "avmdlv2_core.h"

namespace com {
namespace ss {
namespace ttmio {

// Func #1140 | PC: 0x0b0f18 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #1140 | Địa chỉ PC: 0x0b0f18 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0b0f18: D10103FF  sub      sp, sp, #0x40
//   0x0b0f1c: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x0b0f20: A9037BFD  stp      x29, x30, [sp, #0x30]
//   0x0b0f24: 9100C3FD  add      x29, sp, #0x30
static inline uint64_t fde_func_1140_0x0b0f18(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b0f18ULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xa9024ff4ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #1141 | PC: 0x0b108c | FDE: 0x148a38 | Size: 160 bytes
// Hàm #1141 | Địa chỉ PC: 0x0b108c | Địa chỉ FDE: 0x148a38 | Kích thước: 160 bytes
//   0x0b108c: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x0b1090: 910003FD  mov      x29, sp
//   0x0b1094: F9400400  ldr      x0, [x0, #8]
//   0x0b1098: 97FFF1B9  bl       #0xad77c
static inline uint64_t fde_func_1141_0x0b108c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b108cULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x00a0ULL;
    return acc;
}

// Func #1142 | PC: 0x0b112c | FDE: 0x148a38 | Size: 160 bytes
// Hàm #1142 | Địa chỉ PC: 0x0b112c | Địa chỉ FDE: 0x148a38 | Kích thước: 160 bytes
//   0x0b112c: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x0b1130: 910003FD  mov      x29, sp
//   0x0b1134: F9400400  ldr      x0, [x0, #8]
//   0x0b1138: 97FFE9E0  bl       #0xab8b8
static inline uint64_t fde_func_1142_0x0b112c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b112cULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x00a0ULL;
    return acc;
}

// Func #1143 | PC: 0x0b11cc | FDE: 0x148a38 | Size: 164 bytes
// Hàm #1143 | Địa chỉ PC: 0x0b11cc | Địa chỉ FDE: 0x148a38 | Kích thước: 164 bytes
//   0x0b11cc: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x0b11d0: 910003FD  mov      x29, sp
//   0x0b11d4: F9400400  ldr      x0, [x0, #8]
//   0x0b11d8: 2A1F03E1  mov      w1, wzr
static inline uint64_t fde_func_1143_0x0b11cc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b11ccULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x00a4ULL;
    return acc;
}

// Func #1144 | PC: 0x0b1270 | FDE: 0x148a38 | Size: 180 bytes
// Hàm #1144 | Địa chỉ PC: 0x0b1270 | Địa chỉ FDE: 0x148a38 | Kích thước: 180 bytes
//   0x0b1270: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x0b1274: 910003FD  mov      x29, sp
//   0x0b1278: F9400400  ldr      x0, [x0, #8]
//   0x0b127c: 2A1F03E1  mov      w1, wzr
static inline uint64_t fde_func_1144_0x0b1270(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b1270ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x00b4ULL;
    return acc;
}

// Func #1145 | PC: 0x0b1324 | FDE: 0x148a38 | Size: 168 bytes
// Hàm #1145 | Địa chỉ PC: 0x0b1324 | Địa chỉ FDE: 0x148a38 | Kích thước: 168 bytes
//   0x0b1324: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x0b1328: 910003FD  mov      x29, sp
//   0x0b132c: A9408408  ldp      x8, x1, [x0, #8]
//   0x0b1330: F9400C02  ldr      x2, [x0, #0x18]
static inline uint64_t fde_func_1145_0x0b1324(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b1324ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x00a8ULL;
    return acc;
}

// Func #1146 | PC: 0x0b13cc | FDE: 0x148a38 | Size: 160 bytes
// Hàm #1146 | Địa chỉ PC: 0x0b13cc | Địa chỉ FDE: 0x148a38 | Kích thước: 160 bytes
//   0x0b13cc: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x0b13d0: 910003FD  mov      x29, sp
//   0x0b13d4: F9400400  ldr      x0, [x0, #8]
//   0x0b13d8: 97FFED75  bl       #0xac9ac
static inline uint64_t fde_func_1146_0x0b13cc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b13ccULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x00a0ULL;
    return acc;
}

// Func #1147 | PC: 0x0b146c | FDE: 0x148a38 | Size: 160 bytes
// Hàm #1147 | Địa chỉ PC: 0x0b146c | Địa chỉ FDE: 0x148a38 | Kích thước: 160 bytes
//   0x0b146c: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x0b1470: 910003FD  mov      x29, sp
//   0x0b1474: F9400400  ldr      x0, [x0, #8]
//   0x0b1478: 97FFE7C2  bl       #0xab380
static inline uint64_t fde_func_1147_0x0b146c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b146cULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x00a0ULL;
    return acc;
}

// Func #1148 | PC: 0x0b150c | FDE: 0x148a38 | Size: 256 bytes
// Hàm #1148 | Địa chỉ PC: 0x0b150c | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0b150c: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x0b1510: 910003FD  mov      x29, sp
//   0x0b1514: F9400400  ldr      x0, [x0, #8]
//   0x0b1518: 97FFF1AC  bl       #0xadbc8
static inline uint64_t fde_func_1148_0x0b150c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b150cULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #1149 | PC: 0x0b16b0 | FDE: 0x148a38 | Size: 88 bytes
// Hàm #1149 | Địa chỉ PC: 0x0b16b0 | Địa chỉ FDE: 0x148a38 | Kích thước: 88 bytes
//   0x0b16b0: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0b16b4: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0b16b8: 910043FD  add      x29, sp, #0x10
//   0x0b16bc: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_1149_0x0b16b0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b16b0ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0058ULL;
    return acc;
}

// Func #1150 | PC: 0x0b1708 | FDE: 0x148a38 | Size: 128 bytes
// Hàm #1150 | Địa chỉ PC: 0x0b1708 | Địa chỉ FDE: 0x148a38 | Kích thước: 128 bytes
//   0x0b1708: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0b170c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0b1710: 910043FD  add      x29, sp, #0x10
//   0x0b1714: F0000508  adrp     x8, #0x154000
static inline uint64_t fde_func_1150_0x0b1708(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b1708ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0080ULL;
    return acc;
}

// Func #1151 | PC: 0x0b1788 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #1151 | Địa chỉ PC: 0x0b1788 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0b1788: D10143FF  sub      sp, sp, #0x50
//   0x0b178c: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x0b1790: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x0b1794: A9047BFD  stp      x29, x30, [sp, #0x40]
static inline uint64_t fde_func_1151_0x0b1788(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b1788ULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xa90257f6ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #1152 | PC: 0x0b18d4 | FDE: 0x148a38 | Size: 188 bytes
// Hàm #1152 | Địa chỉ PC: 0x0b18d4 | Địa chỉ FDE: 0x148a38 | Kích thước: 188 bytes
//   0x0b18d4: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x0b18d8: 910003FD  mov      x29, sp
//   0x0b18dc: A9408408  ldp      x8, x1, [x0, #8]
//   0x0b18e0: B9401802  ldr      w2, [x0, #0x18]
static inline uint64_t fde_func_1152_0x0b18d4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b18d4ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x00bcULL;
    return acc;
}

// Func #1153 | PC: 0x0b1990 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #1153 | Địa chỉ PC: 0x0b1990 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0b1990: D100C3FF  sub      sp, sp, #0x30
//   0x0b1994: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0b1998: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0b199c: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1153_0x0b1990(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b1990ULL ^ (static_cast<uint64_t>(0xd100c3ffULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #1154 | PC: 0x0b1b84 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #1154 | Địa chỉ PC: 0x0b1b84 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0b1b84: D10103FF  sub      sp, sp, #0x40
//   0x0b1b88: F9000BF5  str      x21, [sp, #0x10]
//   0x0b1b8c: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x0b1b90: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_1154_0x0b1b84(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b1b84ULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xf9000bf5ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #1155 | PC: 0x0b1d0c | FDE: 0x148a38 | Size: 256 bytes
// Hàm #1155 | Địa chỉ PC: 0x0b1d0c | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0b1d0c: D10103FF  sub      sp, sp, #0x40
//   0x0b1d10: F9000BF5  str      x21, [sp, #0x10]
//   0x0b1d14: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x0b1d18: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_1155_0x0b1d0c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b1d0cULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xf9000bf5ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #1156 | PC: 0x0b1f48 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #1156 | Địa chỉ PC: 0x0b1f48 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0b1f48: D10103FF  sub      sp, sp, #0x40
//   0x0b1f4c: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x0b1f50: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x0b1f54: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_1156_0x0b1f48(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b1f48ULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #1157 | PC: 0x0b20f0 | FDE: 0x148a38 | Size: 144 bytes
// Hàm #1157 | Địa chỉ PC: 0x0b20f0 | Địa chỉ FDE: 0x148a38 | Kích thước: 144 bytes
//   0x0b20f0: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x0b20f4: 910003FD  mov      x29, sp
//   0x0b20f8: A9408008  ldp      x8, x0, [x0, #8]
//   0x0b20fc: 52800029  mov      w9, #1
static inline uint64_t fde_func_1157_0x0b20f0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b20f0ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0090ULL;
    return acc;
}

// Func #1158 | PC: 0x0b2180 | FDE: 0x148a38 | Size: 88 bytes
// Hàm #1158 | Địa chỉ PC: 0x0b2180 | Địa chỉ FDE: 0x148a38 | Kích thước: 88 bytes
//   0x0b2180: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0b2184: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0b2188: 910043FD  add      x29, sp, #0x10
//   0x0b218c: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_1158_0x0b2180(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b2180ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0058ULL;
    return acc;
}

// Func #1159 | PC: 0x0b21d8 | FDE: 0x148a38 | Size: 128 bytes
// Hàm #1159 | Địa chỉ PC: 0x0b21d8 | Địa chỉ FDE: 0x148a38 | Kích thước: 128 bytes
//   0x0b21d8: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0b21dc: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0b21e0: 910043FD  add      x29, sp, #0x10
//   0x0b21e4: D0000508  adrp     x8, #0x154000
static inline uint64_t fde_func_1159_0x0b21d8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b21d8ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0080ULL;
    return acc;
}

// Func #1160 | PC: 0x0b2258 | FDE: 0x148a38 | Size: 148 bytes
// Hàm #1160 | Địa chỉ PC: 0x0b2258 | Địa chỉ FDE: 0x148a38 | Kích thước: 148 bytes
//   0x0b2258: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x0b225c: 910003FD  mov      x29, sp
//   0x0b2260: F9400408  ldr      x8, [x0, #8]
//   0x0b2264: B9401001  ldr      w1, [x0, #0x10]
static inline uint64_t fde_func_1160_0x0b2258(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b2258ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0094ULL;
    return acc;
}

// Func #1161 | PC: 0x0b22ec | FDE: 0x148a38 | Size: 88 bytes
// Hàm #1161 | Địa chỉ PC: 0x0b22ec | Địa chỉ FDE: 0x148a38 | Kích thước: 88 bytes
//   0x0b22ec: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0b22f0: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0b22f4: 910043FD  add      x29, sp, #0x10
//   0x0b22f8: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_1161_0x0b22ec(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b22ecULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0058ULL;
    return acc;
}

// Func #1162 | PC: 0x0b2344 | FDE: 0x148a38 | Size: 128 bytes
// Hàm #1162 | Địa chỉ PC: 0x0b2344 | Địa chỉ FDE: 0x148a38 | Kích thước: 128 bytes
//   0x0b2344: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0b2348: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0b234c: 910043FD  add      x29, sp, #0x10
//   0x0b2350: D0000508  adrp     x8, #0x154000
static inline uint64_t fde_func_1162_0x0b2344(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b2344ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0080ULL;
    return acc;
}

// Func #1163 | PC: 0x0b23c4 | FDE: 0x148a38 | Size: 148 bytes
// Hàm #1163 | Địa chỉ PC: 0x0b23c4 | Địa chỉ FDE: 0x148a38 | Kích thước: 148 bytes
//   0x0b23c4: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x0b23c8: 910003FD  mov      x29, sp
//   0x0b23cc: F9400408  ldr      x8, [x0, #8]
//   0x0b23d0: B9401001  ldr      w1, [x0, #0x10]
static inline uint64_t fde_func_1163_0x0b23c4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b23c4ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0094ULL;
    return acc;
}

// Func #1164 | PC: 0x0b2458 | FDE: 0x148a38 | Size: 88 bytes
// Hàm #1164 | Địa chỉ PC: 0x0b2458 | Địa chỉ FDE: 0x148a38 | Kích thước: 88 bytes
//   0x0b2458: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0b245c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0b2460: 910043FD  add      x29, sp, #0x10
//   0x0b2464: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_1164_0x0b2458(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b2458ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0058ULL;
    return acc;
}

// Func #1165 | PC: 0x0b24b0 | FDE: 0x148a38 | Size: 128 bytes
// Hàm #1165 | Địa chỉ PC: 0x0b24b0 | Địa chỉ FDE: 0x148a38 | Kích thước: 128 bytes
//   0x0b24b0: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0b24b4: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0b24b8: 910043FD  add      x29, sp, #0x10
//   0x0b24bc: D0000508  adrp     x8, #0x154000
static inline uint64_t fde_func_1165_0x0b24b0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b24b0ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0080ULL;
    return acc;
}

// Func #1166 | PC: 0x0b2530 | FDE: 0x148a38 | Size: 148 bytes
// Hàm #1166 | Địa chỉ PC: 0x0b2530 | Địa chỉ FDE: 0x148a38 | Kích thước: 148 bytes
//   0x0b2530: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x0b2534: 910003FD  mov      x29, sp
//   0x0b2538: F9400408  ldr      x8, [x0, #8]
//   0x0b253c: B9401001  ldr      w1, [x0, #0x10]
static inline uint64_t fde_func_1166_0x0b2530(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b2530ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0094ULL;
    return acc;
}

// Func #1167 | PC: 0x0b25c4 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #1167 | Địa chỉ PC: 0x0b25c4 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0b25c4: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0b25c8: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0b25cc: 910043FD  add      x29, sp, #0x10
//   0x0b25d0: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_1167_0x0b25c4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b25c4ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #1168 | PC: 0x0b26dc | FDE: 0x148a38 | Size: 256 bytes
// Hàm #1168 | Địa chỉ PC: 0x0b26dc | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0b26dc: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0b26e0: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0b26e4: 910043FD  add      x29, sp, #0x10
//   0x0b26e8: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_1168_0x0b26dc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b26dcULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #1169 | PC: 0x0b27f4 | FDE: 0x148a38 | Size: 88 bytes
// Hàm #1169 | Địa chỉ PC: 0x0b27f4 | Địa chỉ FDE: 0x148a38 | Kích thước: 88 bytes
//   0x0b27f4: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0b27f8: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0b27fc: 910043FD  add      x29, sp, #0x10
//   0x0b2800: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_1169_0x0b27f4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b27f4ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0058ULL;
    return acc;
}

// Func #1170 | PC: 0x0b284c | FDE: 0x148a38 | Size: 128 bytes
// Hàm #1170 | Địa chỉ PC: 0x0b284c | Địa chỉ FDE: 0x148a38 | Kích thước: 128 bytes
//   0x0b284c: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0b2850: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0b2854: 910043FD  add      x29, sp, #0x10
//   0x0b2858: D0000508  adrp     x8, #0x154000
static inline uint64_t fde_func_1170_0x0b284c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b284cULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0080ULL;
    return acc;
}

// Func #1171 | PC: 0x0b28cc | FDE: 0x148a38 | Size: 148 bytes
// Hàm #1171 | Địa chỉ PC: 0x0b28cc | Địa chỉ FDE: 0x148a38 | Kích thước: 148 bytes
//   0x0b28cc: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x0b28d0: 910003FD  mov      x29, sp
//   0x0b28d4: F9400408  ldr      x8, [x0, #8]
//   0x0b28d8: B9401001  ldr      w1, [x0, #0x10]
static inline uint64_t fde_func_1171_0x0b28cc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b28ccULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0094ULL;
    return acc;
}

// Func #1172 | PC: 0x0b2960 | FDE: 0x148a38 | Size: 88 bytes
// Hàm #1172 | Địa chỉ PC: 0x0b2960 | Địa chỉ FDE: 0x148a38 | Kích thước: 88 bytes
//   0x0b2960: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0b2964: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0b2968: 910043FD  add      x29, sp, #0x10
//   0x0b296c: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_1172_0x0b2960(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b2960ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0058ULL;
    return acc;
}

// Func #1173 | PC: 0x0b29b8 | FDE: 0x148a38 | Size: 128 bytes
// Hàm #1173 | Địa chỉ PC: 0x0b29b8 | Địa chỉ FDE: 0x148a38 | Kích thước: 128 bytes
//   0x0b29b8: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0b29bc: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0b29c0: 910043FD  add      x29, sp, #0x10
//   0x0b29c4: D0000508  adrp     x8, #0x154000
static inline uint64_t fde_func_1173_0x0b29b8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b29b8ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0080ULL;
    return acc;
}

// Func #1174 | PC: 0x0b2a38 | FDE: 0x148a38 | Size: 148 bytes
// Hàm #1174 | Địa chỉ PC: 0x0b2a38 | Địa chỉ FDE: 0x148a38 | Kích thước: 148 bytes
//   0x0b2a38: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x0b2a3c: 910003FD  mov      x29, sp
//   0x0b2a40: F9400408  ldr      x8, [x0, #8]
//   0x0b2a44: B9401001  ldr      w1, [x0, #0x10]
static inline uint64_t fde_func_1174_0x0b2a38(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b2a38ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0094ULL;
    return acc;
}

// Func #1175 | PC: 0x0b2acc | FDE: 0x148a38 | Size: 88 bytes
// Hàm #1175 | Địa chỉ PC: 0x0b2acc | Địa chỉ FDE: 0x148a38 | Kích thước: 88 bytes
//   0x0b2acc: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0b2ad0: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0b2ad4: 910043FD  add      x29, sp, #0x10
//   0x0b2ad8: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_1175_0x0b2acc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b2accULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0058ULL;
    return acc;
}

// Func #1176 | PC: 0x0b2b24 | FDE: 0x148a38 | Size: 128 bytes
// Hàm #1176 | Địa chỉ PC: 0x0b2b24 | Địa chỉ FDE: 0x148a38 | Kích thước: 128 bytes
//   0x0b2b24: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0b2b28: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0b2b2c: 910043FD  add      x29, sp, #0x10
//   0x0b2b30: D0000508  adrp     x8, #0x154000
static inline uint64_t fde_func_1176_0x0b2b24(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b2b24ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0080ULL;
    return acc;
}

// Func #1177 | PC: 0x0b2ba4 | FDE: 0x148a38 | Size: 148 bytes
// Hàm #1177 | Địa chỉ PC: 0x0b2ba4 | Địa chỉ FDE: 0x148a38 | Kích thước: 148 bytes
//   0x0b2ba4: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x0b2ba8: 910003FD  mov      x29, sp
//   0x0b2bac: F9400408  ldr      x8, [x0, #8]
//   0x0b2bb0: B9401001  ldr      w1, [x0, #0x10]
static inline uint64_t fde_func_1177_0x0b2ba4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b2ba4ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0094ULL;
    return acc;
}

// Func #1178 | PC: 0x0b2c38 | FDE: 0x148a38 | Size: 88 bytes
// Hàm #1178 | Địa chỉ PC: 0x0b2c38 | Địa chỉ FDE: 0x148a38 | Kích thước: 88 bytes
//   0x0b2c38: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0b2c3c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0b2c40: 910043FD  add      x29, sp, #0x10
//   0x0b2c44: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_1178_0x0b2c38(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b2c38ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0058ULL;
    return acc;
}

// Func #1179 | PC: 0x0b2c90 | FDE: 0x148a38 | Size: 128 bytes
// Hàm #1179 | Địa chỉ PC: 0x0b2c90 | Địa chỉ FDE: 0x148a38 | Kích thước: 128 bytes
//   0x0b2c90: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0b2c94: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0b2c98: 910043FD  add      x29, sp, #0x10
//   0x0b2c9c: F0000508  adrp     x8, #0x155000
static inline uint64_t fde_func_1179_0x0b2c90(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b2c90ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0080ULL;
    return acc;
}

// Func #1180 | PC: 0x0b2d10 | FDE: 0x148a38 | Size: 148 bytes
// Hàm #1180 | Địa chỉ PC: 0x0b2d10 | Địa chỉ FDE: 0x148a38 | Kích thước: 148 bytes
//   0x0b2d10: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x0b2d14: 910003FD  mov      x29, sp
//   0x0b2d18: F9400408  ldr      x8, [x0, #8]
//   0x0b2d1c: B9401001  ldr      w1, [x0, #0x10]
static inline uint64_t fde_func_1180_0x0b2d10(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b2d10ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0094ULL;
    return acc;
}

// Func #1181 | PC: 0x0b2da4 | FDE: 0x148a38 | Size: 88 bytes
// Hàm #1181 | Địa chỉ PC: 0x0b2da4 | Địa chỉ FDE: 0x148a38 | Kích thước: 88 bytes
//   0x0b2da4: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0b2da8: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0b2dac: 910043FD  add      x29, sp, #0x10
//   0x0b2db0: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_1181_0x0b2da4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b2da4ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0058ULL;
    return acc;
}

// Func #1182 | PC: 0x0b2dfc | FDE: 0x148a38 | Size: 128 bytes
// Hàm #1182 | Địa chỉ PC: 0x0b2dfc | Địa chỉ FDE: 0x148a38 | Kích thước: 128 bytes
//   0x0b2dfc: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0b2e00: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0b2e04: 910043FD  add      x29, sp, #0x10
//   0x0b2e08: F0000508  adrp     x8, #0x155000
static inline uint64_t fde_func_1182_0x0b2dfc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b2dfcULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0080ULL;
    return acc;
}

// Func #1183 | PC: 0x0b2e7c | FDE: 0x148a38 | Size: 192 bytes
// Hàm #1183 | Địa chỉ PC: 0x0b2e7c | Địa chỉ FDE: 0x148a38 | Kích thước: 192 bytes
//   0x0b2e7c: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x0b2e80: 910003FD  mov      x29, sp
//   0x0b2e84: F9400408  ldr      x8, [x0, #8]
//   0x0b2e88: B9401001  ldr      w1, [x0, #0x10]
static inline uint64_t fde_func_1183_0x0b2e7c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b2e7cULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x00c0ULL;
    return acc;
}

// Func #1184 | PC: 0x0b2f3c | FDE: 0x148a38 | Size: 256 bytes
// Hàm #1184 | Địa chỉ PC: 0x0b2f3c | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0b2f3c: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x0b2f40: 910003FD  mov      x29, sp
//   0x0b2f44: F9400400  ldr      x0, [x0, #8]
//   0x0b2f48: 97FFEB56  bl       #0xadca0
static inline uint64_t fde_func_1184_0x0b2f3c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b2f3cULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #1185 | PC: 0x0b30a4 | FDE: 0x148a38 | Size: 172 bytes
// Hàm #1185 | Địa chỉ PC: 0x0b30a4 | Địa chỉ FDE: 0x148a38 | Kích thước: 172 bytes
//   0x0b30a4: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x0b30a8: 910003FD  mov      x29, sp
//   0x0b30ac: F9400408  ldr      x8, [x0, #8]
//   0x0b30b0: B9401001  ldr      w1, [x0, #0x10]
static inline uint64_t fde_func_1185_0x0b30a4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b30a4ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x00acULL;
    return acc;
}

// Func #1186 | PC: 0x0b3150 | FDE: 0x148a38 | Size: 164 bytes
// Hàm #1186 | Địa chỉ PC: 0x0b3150 | Địa chỉ FDE: 0x148a38 | Kích thước: 164 bytes
//   0x0b3150: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x0b3154: 910003FD  mov      x29, sp
//   0x0b3158: F9400400  ldr      x0, [x0, #8]
//   0x0b315c: 52800021  mov      w1, #1
static inline uint64_t fde_func_1186_0x0b3150(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b3150ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x00a4ULL;
    return acc;
}

// Func #1187 | PC: 0x0b31f4 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #1187 | Địa chỉ PC: 0x0b31f4 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0b31f4: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x0b31f8: 910003FD  mov      x29, sp
//   0x0b31fc: F9400400  ldr      x0, [x0, #8]
//   0x0b3200: 52800021  mov      w1, #1
static inline uint64_t fde_func_1187_0x0b31f4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b31f4ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #1188 | PC: 0x0b33e4 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #1188 | Địa chỉ PC: 0x0b33e4 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0b33e4: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x0b33e8: 910003FD  mov      x29, sp
//   0x0b33ec: F9400400  ldr      x0, [x0, #8]
//   0x0b33f0: 97FFF52D  bl       #0xb08a4
static inline uint64_t fde_func_1188_0x0b33e4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b33e4ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #1189 | PC: 0x0b3738 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #1189 | Địa chỉ PC: 0x0b3738 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0b3738: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0b373c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0b3740: 910043FD  add      x29, sp, #0x10
//   0x0b3744: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_1189_0x0b3738(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b3738ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #1190 | PC: 0x0b39cc | FDE: 0x148a38 | Size: 256 bytes
// Hàm #1190 | Địa chỉ PC: 0x0b39cc | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0b39cc: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0b39d0: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0b39d4: 910043FD  add      x29, sp, #0x10
//   0x0b39d8: 90000548  adrp     x8, #0x15b000
static inline uint64_t fde_func_1190_0x0b39cc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b39ccULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #1191 | PC: 0x0b3acc | FDE: 0x148a38 | Size: 28 bytes
// Hàm #1191 | Địa chỉ PC: 0x0b3acc | Địa chỉ FDE: 0x148a38 | Kích thước: 28 bytes
//   0x0b3acc: A9BA6FFC  stp      x28, x27, [sp, #-0x60]!
//   0x0b3ad0: A90167FA  stp      x26, x25, [sp, #0x10]
//   0x0b3ad4: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x0b3ad8: A90357F6  stp      x22, x21, [sp, #0x30]
static inline uint64_t fde_func_1191_0x0b3acc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b3accULL ^ (static_cast<uint64_t>(0xa9ba6ffcULL) << 13);
    acc = (acc + a1 + 0xa90167faULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x001cULL;
    return acc;
}

// Func #1192 | PC: 0x0b3ae8 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #1192 | Địa chỉ PC: 0x0b3ae8 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0b3ae8: D10983FF  sub      sp, sp, #0x260
//   0x0b3aec: AA0003F3  mov      x19, x0
//   0x0b3af0: 910643E0  add      x0, sp, #0x190
//   0x0b3af4: AA0103F4  mov      x20, x1
static inline uint64_t fde_func_1192_0x0b3ae8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b3ae8ULL ^ (static_cast<uint64_t>(0xd10983ffULL) << 13);
    acc = (acc + a1 + 0xaa0003f3ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #1193 | PC: 0x0b4acc | FDE: 0x148a38 | Size: 256 bytes
// Hàm #1193 | Địa chỉ PC: 0x0b4acc | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0b4acc: D10203FF  sub      sp, sp, #0x80
//   0x0b4ad0: A9026FFC  stp      x28, x27, [sp, #0x20]
//   0x0b4ad4: A90367FA  stp      x26, x25, [sp, #0x30]
//   0x0b4ad8: A9045FF8  stp      x24, x23, [sp, #0x40]
static inline uint64_t fde_func_1193_0x0b4acc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b4accULL ^ (static_cast<uint64_t>(0xd10203ffULL) << 13);
    acc = (acc + a1 + 0xa9026ffcULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #1194 | PC: 0x0b4ee0 | FDE: 0x148a38 | Size: 28 bytes
// Hàm #1194 | Địa chỉ PC: 0x0b4ee0 | Địa chỉ FDE: 0x148a38 | Kích thước: 28 bytes
//   0x0b4ee0: A9BA6FFC  stp      x28, x27, [sp, #-0x60]!
//   0x0b4ee4: A90167FA  stp      x26, x25, [sp, #0x10]
//   0x0b4ee8: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x0b4eec: A90357F6  stp      x22, x21, [sp, #0x30]
static inline uint64_t fde_func_1194_0x0b4ee0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b4ee0ULL ^ (static_cast<uint64_t>(0xa9ba6ffcULL) << 13);
    acc = (acc + a1 + 0xa90167faULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x001cULL;
    return acc;
}

// Func #1195 | PC: 0x0b4efc | FDE: 0x148a38 | Size: 256 bytes
// Hàm #1195 | Địa chỉ PC: 0x0b4efc | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0b4efc: D120C3FF  sub      sp, sp, #0x830
//   0x0b4f00: AA0003F4  mov      x20, x0
//   0x0b4f04: D10223A0  sub      x0, x29, #0x88
//   0x0b4f08: 2A1F03E1  mov      w1, wzr
static inline uint64_t fde_func_1195_0x0b4efc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b4efcULL ^ (static_cast<uint64_t>(0xd120c3ffULL) << 13);
    acc = (acc + a1 + 0xaa0003f4ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #1196 | PC: 0x0b5a0c | FDE: 0x148a38 | Size: 28 bytes
// Hàm #1196 | Địa chỉ PC: 0x0b5a0c | Địa chỉ FDE: 0x148a38 | Kích thước: 28 bytes
//   0x0b5a0c: A9BA6FFC  stp      x28, x27, [sp, #-0x60]!
//   0x0b5a10: A90167FA  stp      x26, x25, [sp, #0x10]
//   0x0b5a14: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x0b5a18: A90357F6  stp      x22, x21, [sp, #0x30]
static inline uint64_t fde_func_1196_0x0b5a0c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b5a0cULL ^ (static_cast<uint64_t>(0xa9ba6ffcULL) << 13);
    acc = (acc + a1 + 0xa90167faULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x001cULL;
    return acc;
}

// Func #1197 | PC: 0x0b5a28 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #1197 | Địa chỉ PC: 0x0b5a28 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0b5a28: D10A03FF  sub      sp, sp, #0x280
//   0x0b5a2c: 39400028  ldrb     w8, [x1]
//   0x0b5a30: F9400429  ldr      x9, [x1, #8]
//   0x0b5a34: D341FD0A  lsr      x10, x8, #1
static inline uint64_t fde_func_1197_0x0b5a28(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b5a28ULL ^ (static_cast<uint64_t>(0xd10a03ffULL) << 13);
    acc = (acc + a1 + 0x39400028ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #1198 | PC: 0x0b6a00 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #1198 | Địa chỉ PC: 0x0b6a00 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0b6a00: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0b6a04: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0b6a08: 910043FD  add      x29, sp, #0x10
//   0x0b6a0c: F9400028  ldr      x8, [x1]
static inline uint64_t fde_func_1198_0x0b6a00(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b6a00ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #1199 | PC: 0x0b6b3c | FDE: 0x148a38 | Size: 256 bytes
// Hàm #1199 | Địa chỉ PC: 0x0b6b3c | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0b6b3c: D11343FF  sub      sp, sp, #0x4d0
//   0x0b6b40: D53BD057  mrs      x23, tpidr_el0
//   0x0b6b44: F94016E8  ldr      x8, [x23, #0x28]
//   0x0b6b48: F81903A8  stur     x8, [x29, #-0x70]
static inline uint64_t fde_func_1199_0x0b6b3c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b6b3cULL ^ (static_cast<uint64_t>(0xd11343ffULL) << 13);
    acc = (acc + a1 + 0xd53bd057ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #1200 | PC: 0x0b7338 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #1200 | Địa chỉ PC: 0x0b7338 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0b7338: D10103FF  sub      sp, sp, #0x40
//   0x0b733c: F90013F3  str      x19, [sp, #0x20]
//   0x0b7340: A9037BFD  stp      x29, x30, [sp, #0x30]
//   0x0b7344: 9100C3FD  add      x29, sp, #0x30
static inline uint64_t fde_func_1200_0x0b7338(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b7338ULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xf90013f3ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #1201 | PC: 0x0b75d4 | FDE: 0x148a38 | Size: 228 bytes
// Hàm #1201 | Địa chỉ PC: 0x0b75d4 | Địa chỉ FDE: 0x148a38 | Kích thước: 228 bytes
//   0x0b75d4: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x0b75d8: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0b75dc: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0b75e0: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1201_0x0b75d4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b75d4ULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x00e4ULL;
    return acc;
}

// Func #1202 | PC: 0x0b76b8 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #1202 | Địa chỉ PC: 0x0b76b8 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0b76b8: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x0b76bc: 910003FD  mov      x29, sp
//   0x0b76c0: 5284E2E9  mov      w9, #0x2717
//   0x0b76c4: 6B09003F  cmp      w1, w9
static inline uint64_t fde_func_1202_0x0b76b8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b76b8ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #1203 | PC: 0x0b7800 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #1203 | Địa chỉ PC: 0x0b7800 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0b7800: A9BB67FA  stp      x26, x25, [sp, #-0x50]!
//   0x0b7804: A9015FF8  stp      x24, x23, [sp, #0x10]
//   0x0b7808: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x0b780c: A9034FF4  stp      x20, x19, [sp, #0x30]
static inline uint64_t fde_func_1203_0x0b7800(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b7800ULL ^ (static_cast<uint64_t>(0xa9bb67faULL) << 13);
    acc = (acc + a1 + 0xa9015ff8ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #1204 | PC: 0x0b7a24 | FDE: 0x148a38 | Size: 76 bytes
// Hàm #1204 | Địa chỉ PC: 0x0b7a24 | Địa chỉ FDE: 0x148a38 | Kích thước: 76 bytes
//   0x0b7a24: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0b7a28: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0b7a2c: 910043FD  add      x29, sp, #0x10
//   0x0b7a30: B201F3E8  mov      x8, #-0x5555555555555556
static inline uint64_t fde_func_1204_0x0b7a24(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b7a24ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x004cULL;
    return acc;
}

// Func #1205 | PC: 0x0b7a70 | FDE: 0x148a38 | Size: 168 bytes
// Hàm #1205 | Địa chỉ PC: 0x0b7a70 | Địa chỉ FDE: 0x148a38 | Kích thước: 168 bytes
//   0x0b7a70: D10103FF  sub      sp, sp, #0x40
//   0x0b7a74: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x0b7a78: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x0b7a7c: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_1205_0x0b7a70(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b7a70ULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x00a8ULL;
    return acc;
}

// Func #1206 | PC: 0x0b7b18 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #1206 | Địa chỉ PC: 0x0b7b18 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0b7b18: D10143FF  sub      sp, sp, #0x50
//   0x0b7b1c: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x0b7b20: A9047BFD  stp      x29, x30, [sp, #0x40]
//   0x0b7b24: 910103FD  add      x29, sp, #0x40
static inline uint64_t fde_func_1206_0x0b7b18(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b7b18ULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xa9034ff4ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #1207 | PC: 0x0b7f44 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #1207 | Địa chỉ PC: 0x0b7f44 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0b7f44: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x0b7f48: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0b7f4c: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0b7f50: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1207_0x0b7f44(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b7f44ULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #1208 | PC: 0x0b904c | FDE: 0x148a38 | Size: 160 bytes
// Hàm #1208 | Địa chỉ PC: 0x0b904c | Địa chỉ FDE: 0x148a38 | Kích thước: 160 bytes
//   0x0b904c: A9BC5FF8  stp      x24, x23, [sp, #-0x40]!
//   0x0b9050: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x0b9054: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x0b9058: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_1208_0x0b904c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b904cULL ^ (static_cast<uint64_t>(0xa9bc5ff8ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x00a0ULL;
    return acc;
}

// Func #1209 | PC: 0x0b90ec | FDE: 0x148a38 | Size: 256 bytes
// Hàm #1209 | Địa chỉ PC: 0x0b90ec | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0b90ec: A9BC5FF8  stp      x24, x23, [sp, #-0x40]!
//   0x0b90f0: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x0b90f4: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x0b90f8: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_1209_0x0b90ec(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b90ecULL ^ (static_cast<uint64_t>(0xa9bc5ff8ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #1210 | PC: 0x0b922c | FDE: 0x148a38 | Size: 256 bytes
// Hàm #1210 | Địa chỉ PC: 0x0b922c | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0b922c: A9BC5FF8  stp      x24, x23, [sp, #-0x40]!
//   0x0b9230: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x0b9234: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x0b9238: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_1210_0x0b922c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b922cULL ^ (static_cast<uint64_t>(0xa9bc5ff8ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #1211 | PC: 0x0b936c | FDE: 0x148a38 | Size: 256 bytes
// Hàm #1211 | Địa chỉ PC: 0x0b936c | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0b936c: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x0b9370: 910003FD  mov      x29, sp
//   0x0b9374: 97FDEB17  bl       #0x33fd0
//   0x0b9378: 17FDE73E  b        #0x33070
static inline uint64_t fde_func_1211_0x0b936c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b936cULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #1212 | PC: 0x0b95fc | FDE: 0x148a38 | Size: 256 bytes
// Hàm #1212 | Địa chỉ PC: 0x0b95fc | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0b95fc: D101C3FF  sub      sp, sp, #0x70
//   0x0b9600: A90457F6  stp      x22, x21, [sp, #0x40]
//   0x0b9604: A9054FF4  stp      x20, x19, [sp, #0x50]
//   0x0b9608: A9067BFD  stp      x29, x30, [sp, #0x60]
static inline uint64_t fde_func_1212_0x0b95fc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b95fcULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xa90457f6ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #1213 | PC: 0x0b9878 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #1213 | Địa chỉ PC: 0x0b9878 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0b9878: A9BC5FF8  stp      x24, x23, [sp, #-0x40]!
//   0x0b987c: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x0b9880: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x0b9884: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_1213_0x0b9878(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b9878ULL ^ (static_cast<uint64_t>(0xa9bc5ff8ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #1214 | PC: 0x0b9e40 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #1214 | Địa chỉ PC: 0x0b9e40 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0b9e40: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x0b9e44: 910003FD  mov      x29, sp
//   0x0b9e48: 97FDE862  bl       #0x33fd0
//   0x0b9e4c: F81E0FF3  str      x19, [sp, #-0x20]!
static inline uint64_t fde_func_1214_0x0b9e40(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0b9e40ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #1215 | PC: 0x0ba114 | FDE: 0x148a38 | Size: 140 bytes
// Hàm #1215 | Địa chỉ PC: 0x0ba114 | Địa chỉ FDE: 0x148a38 | Kích thước: 140 bytes
//   0x0ba114: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x0ba118: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0ba11c: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0ba120: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1215_0x0ba114(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ba114ULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x008cULL;
    return acc;
}

// Func #1216 | PC: 0x0ba1a0 | FDE: 0x148a38 | Size: 104 bytes
// Hàm #1216 | Địa chỉ PC: 0x0ba1a0 | Địa chỉ FDE: 0x148a38 | Kích thước: 104 bytes
//   0x0ba1a0: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0ba1a4: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0ba1a8: 910043FD  add      x29, sp, #0x10
//   0x0ba1ac: B0000508  adrp     x8, #0x15b000
static inline uint64_t fde_func_1216_0x0ba1a0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ba1a0ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0068ULL;
    return acc;
}

// Func #1217 | PC: 0x0ba208 | FDE: 0x148a38 | Size: 100 bytes
// Hàm #1217 | Địa chỉ PC: 0x0ba208 | Địa chỉ FDE: 0x148a38 | Kích thước: 100 bytes
//   0x0ba208: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0ba20c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0ba210: 910043FD  add      x29, sp, #0x10
//   0x0ba214: B0000508  adrp     x8, #0x15b000
static inline uint64_t fde_func_1217_0x0ba208(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ba208ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0064ULL;
    return acc;
}

// Func #1218 | PC: 0x0ba26c | FDE: 0x148a38 | Size: 256 bytes
// Hàm #1218 | Địa chỉ PC: 0x0ba26c | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0ba26c: D10283FF  sub      sp, sp, #0xa0
//   0x0ba270: A90757F6  stp      x22, x21, [sp, #0x70]
//   0x0ba274: A9084FF4  stp      x20, x19, [sp, #0x80]
//   0x0ba278: A9097BFD  stp      x29, x30, [sp, #0x90]
static inline uint64_t fde_func_1218_0x0ba26c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ba26cULL ^ (static_cast<uint64_t>(0xd10283ffULL) << 13);
    acc = (acc + a1 + 0xa90757f6ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #1219 | PC: 0x0ba3e8 | FDE: 0x148a38 | Size: 112 bytes
// Hàm #1219 | Địa chỉ PC: 0x0ba3e8 | Địa chỉ FDE: 0x148a38 | Kích thước: 112 bytes
//   0x0ba3e8: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x0ba3ec: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0ba3f0: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0ba3f4: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1219_0x0ba3e8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ba3e8ULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0070ULL;
    return acc;
}

// Func #1220 | PC: 0x0ba458 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #1220 | Địa chỉ PC: 0x0ba458 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0ba458: D10483FF  sub      sp, sp, #0x120
//   0x0ba45c: A90C6FFC  stp      x28, x27, [sp, #0xc0]
//   0x0ba460: A90D67FA  stp      x26, x25, [sp, #0xd0]
//   0x0ba464: A90E5FF8  stp      x24, x23, [sp, #0xe0]
static inline uint64_t fde_func_1220_0x0ba458(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ba458ULL ^ (static_cast<uint64_t>(0xd10483ffULL) << 13);
    acc = (acc + a1 + 0xa90c6ffcULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #1221 | PC: 0x0ba8d0 | FDE: 0x148a38 | Size: 76 bytes
// Hàm #1221 | Địa chỉ PC: 0x0ba8d0 | Địa chỉ FDE: 0x148a38 | Kích thước: 76 bytes
//   0x0ba8d0: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0ba8d4: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0ba8d8: 910043FD  add      x29, sp, #0x10
//   0x0ba8dc: B201F3E8  mov      x8, #-0x5555555555555556
static inline uint64_t fde_func_1221_0x0ba8d0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ba8d0ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x004cULL;
    return acc;
}

// Func #1222 | PC: 0x0ba91c | FDE: 0x148a38 | Size: 256 bytes
// Hàm #1222 | Địa chỉ PC: 0x0ba91c | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0ba91c: D10143FF  sub      sp, sp, #0x50
//   0x0ba920: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x0ba924: A9047BFD  stp      x29, x30, [sp, #0x40]
//   0x0ba928: 910103FD  add      x29, sp, #0x40
static inline uint64_t fde_func_1222_0x0ba91c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ba91cULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xa9034ff4ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #1223 | PC: 0x0bab00 | FDE: 0x148a38 | Size: 12 bytes
// Hàm #1223 | Địa chỉ PC: 0x0bab00 | Địa chỉ FDE: 0x148a38 | Kích thước: 12 bytes
//   0x0bab00: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x0bab04: 910003FD  mov      x29, sp
//   0x0bab08: 97FDE532  bl       #0x33fd0
static inline uint64_t fde_func_1223_0x0bab00(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0bab00ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x000cULL;
    return acc;
}

// Func #1224 | PC: 0x0bab0c | FDE: 0x148a38 | Size: 128 bytes
// Hàm #1224 | Địa chỉ PC: 0x0bab0c | Địa chỉ FDE: 0x148a38 | Kích thước: 128 bytes
//   0x0bab0c: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x0bab10: 910003FD  mov      x29, sp
//   0x0bab14: 97FDE52F  bl       #0x33fd0
//   0x0bab18: F81D0FF5  str      x21, [sp, #-0x30]!
static inline uint64_t fde_func_1224_0x0bab0c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0bab0cULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0080ULL;
    return acc;
}

// Func #1225 | PC: 0x0bab8c | FDE: 0x148a38 | Size: 256 bytes
// Hàm #1225 | Địa chỉ PC: 0x0bab8c | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0bab8c: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0bab90: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0bab94: 910043FD  add      x29, sp, #0x10
//   0x0bab98: AA0103F3  mov      x19, x1
static inline uint64_t fde_func_1225_0x0bab8c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0bab8cULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #1226 | PC: 0x0baca4 | FDE: 0x148a38 | Size: 136 bytes
// Hàm #1226 | Địa chỉ PC: 0x0baca4 | Địa chỉ FDE: 0x148a38 | Kích thước: 136 bytes
//   0x0baca4: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0baca8: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0bacac: 910043FD  add      x29, sp, #0x10
//   0x0bacb0: A940A014  ldp      x20, x8, [x0, #8]
static inline uint64_t fde_func_1226_0x0baca4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0baca4ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0088ULL;
    return acc;
}

// Func #1227 | PC: 0x0bad2c | FDE: 0x148a38 | Size: 256 bytes
// Hàm #1227 | Địa chỉ PC: 0x0bad2c | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0bad2c: D10183FF  sub      sp, sp, #0x60
//   0x0bad30: F9001BF5  str      x21, [sp, #0x30]
//   0x0bad34: A9044FF4  stp      x20, x19, [sp, #0x40]
//   0x0bad38: A9057BFD  stp      x29, x30, [sp, #0x50]
static inline uint64_t fde_func_1227_0x0bad2c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0bad2cULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xf9001bf5ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #1228 | PC: 0x0bb168 | FDE: 0x148a38 | Size: 64 bytes
// Hàm #1228 | Địa chỉ PC: 0x0bb168 | Địa chỉ FDE: 0x148a38 | Kích thước: 64 bytes
//   0x0bb168: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0bb16c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0bb170: 910043FD  add      x29, sp, #0x10
//   0x0bb174: D37CFC28  lsr      x8, x1, #0x3c
static inline uint64_t fde_func_1228_0x0bb168(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0bb168ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0040ULL;
    return acc;
}

// Func #1229 | PC: 0x0bb1a8 | FDE: 0x148a38 | Size: 116 bytes
// Hàm #1229 | Địa chỉ PC: 0x0bb1a8 | Địa chỉ FDE: 0x148a38 | Kích thước: 116 bytes
//   0x0bb1a8: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x0bb1ac: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0bb1b0: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0bb1b4: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1229_0x0bb1a8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0bb1a8ULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0074ULL;
    return acc;
}

// Func #1230 | PC: 0x0bb21c | FDE: 0x148a38 | Size: 256 bytes
// Hàm #1230 | Địa chỉ PC: 0x0bb21c | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0bb21c: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x0bb220: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0bb224: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0bb228: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1230_0x0bb21c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0bb21cULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #1231 | PC: 0x0bb42c | FDE: 0x148a38 | Size: 92 bytes
// Hàm #1231 | Địa chỉ PC: 0x0bb42c | Địa chỉ FDE: 0x148a38 | Kích thước: 92 bytes
//   0x0bb42c: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0bb430: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0bb434: 910043FD  add      x29, sp, #0x10
//   0x0bb438: 39406008  ldrb     w8, [x0, #0x18]
static inline uint64_t fde_func_1231_0x0bb42c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0bb42cULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x005cULL;
    return acc;
}

// Func #1232 | PC: 0x0bb488 | FDE: 0x148a38 | Size: 184 bytes
// Hàm #1232 | Địa chỉ PC: 0x0bb488 | Địa chỉ FDE: 0x148a38 | Kích thước: 184 bytes
//   0x0bb488: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x0bb48c: 910003FD  mov      x29, sp
//   0x0bb490: 97FDE2D0  bl       #0x33fd0
//   0x0bb494: F81E0FF3  str      x19, [sp, #-0x20]!
static inline uint64_t fde_func_1232_0x0bb488(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0bb488ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x00b8ULL;
    return acc;
}

// Func #1233 | PC: 0x0bb540 | FDE: 0x148a38 | Size: 12 bytes
// Hàm #1233 | Địa chỉ PC: 0x0bb540 | Địa chỉ FDE: 0x148a38 | Kích thước: 12 bytes
//   0x0bb540: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x0bb544: 910003FD  mov      x29, sp
//   0x0bb548: 97FDE2A2  bl       #0x33fd0
static inline uint64_t fde_func_1233_0x0bb540(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0bb540ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x000cULL;
    return acc;
}

// Func #1234 | PC: 0x0bb54c | FDE: 0x148a38 | Size: 256 bytes
// Hàm #1234 | Địa chỉ PC: 0x0bb54c | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0bb54c: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0bb550: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0bb554: 910043FD  add      x29, sp, #0x10
//   0x0bb558: AA0103F4  mov      x20, x1
static inline uint64_t fde_func_1234_0x0bb54c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0bb54cULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #1235 | PC: 0x0bbbd0 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #1235 | Địa chỉ PC: 0x0bbbd0 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0bbbd0: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x0bbbd4: 910003FD  mov      x29, sp
//   0x0bbbd8: 97FDE0FE  bl       #0x33fd0
//   0x0bbbdc: F81D0FF5  str      x21, [sp, #-0x30]!
static inline uint64_t fde_func_1235_0x0bbbd0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0bbbd0ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #1236 | PC: 0x0bbd60 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #1236 | Địa chỉ PC: 0x0bbd60 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0bbd60: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0bbd64: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0bbd68: 910043FD  add      x29, sp, #0x10
//   0x0bbd6c: A9412428  ldp      x8, x9, [x1, #0x10]
static inline uint64_t fde_func_1236_0x0bbd60(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0bbd60ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #1237 | PC: 0x0bc2ac | FDE: 0x148a38 | Size: 256 bytes
// Hàm #1237 | Địa chỉ PC: 0x0bc2ac | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0bc2ac: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x0bc2b0: 910003FD  mov      x29, sp
//   0x0bc2b4: A9422828  ldp      x8, x10, [x1, #0x20]
//   0x0bc2b8: B9401009  ldr      w9, [x0, #0x10]
static inline uint64_t fde_func_1237_0x0bc2ac(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0bc2acULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #1238 | PC: 0x0bc57c | FDE: 0x148a38 | Size: 256 bytes
// Hàm #1238 | Địa chỉ PC: 0x0bc57c | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0bc57c: D10183FF  sub      sp, sp, #0x60
//   0x0bc580: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x0bc584: A90357F6  stp      x22, x21, [sp, #0x30]
//   0x0bc588: A9044FF4  stp      x20, x19, [sp, #0x40]
static inline uint64_t fde_func_1238_0x0bc57c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0bc57cULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xa9025ff8ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #1239 | PC: 0x0bc7d0 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #1239 | Địa chỉ PC: 0x0bc7d0 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0bc7d0: D10243FF  sub      sp, sp, #0x90
//   0x0bc7d4: A9036FFC  stp      x28, x27, [sp, #0x30]
//   0x0bc7d8: A90467FA  stp      x26, x25, [sp, #0x40]
//   0x0bc7dc: A9055FF8  stp      x24, x23, [sp, #0x50]
static inline uint64_t fde_func_1239_0x0bc7d0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0bc7d0ULL ^ (static_cast<uint64_t>(0xd10243ffULL) << 13);
    acc = (acc + a1 + 0xa9036ffcULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #1240 | PC: 0x0bd068 | FDE: 0x148a38 | Size: 184 bytes
// Hàm #1240 | Địa chỉ PC: 0x0bd068 | Địa chỉ FDE: 0x148a38 | Kích thước: 184 bytes
//   0x0bd068: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x0bd06c: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0bd070: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0bd074: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1240_0x0bd068(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0bd068ULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x00b8ULL;
    return acc;
}

// Func #1241 | PC: 0x0bd120 | FDE: 0x148a38 | Size: 240 bytes
// Hàm #1241 | Địa chỉ PC: 0x0bd120 | Địa chỉ FDE: 0x148a38 | Kích thước: 240 bytes
//   0x0bd120: D10183FF  sub      sp, sp, #0x60
//   0x0bd124: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x0bd128: A90357F6  stp      x22, x21, [sp, #0x30]
//   0x0bd12c: A9044FF4  stp      x20, x19, [sp, #0x40]
static inline uint64_t fde_func_1241_0x0bd120(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0bd120ULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xa9025ff8ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x00f0ULL;
    return acc;
}

// Func #1242 | PC: 0x0bd210 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #1242 | Địa chỉ PC: 0x0bd210 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0bd210: D101C3FF  sub      sp, sp, #0x70
//   0x0bd214: A9035FF8  stp      x24, x23, [sp, #0x30]
//   0x0bd218: A90457F6  stp      x22, x21, [sp, #0x40]
//   0x0bd21c: A9054FF4  stp      x20, x19, [sp, #0x50]
static inline uint64_t fde_func_1242_0x0bd210(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0bd210ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xa9035ff8ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #1243 | PC: 0x0bd3f4 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #1243 | Địa chỉ PC: 0x0bd3f4 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0bd3f4: D10183FF  sub      sp, sp, #0x60
//   0x0bd3f8: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x0bd3fc: A90357F6  stp      x22, x21, [sp, #0x30]
//   0x0bd400: A9044FF4  stp      x20, x19, [sp, #0x40]
static inline uint64_t fde_func_1243_0x0bd3f4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0bd3f4ULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xa9025ff8ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #1244 | PC: 0x0bd544 | FDE: 0x148a38 | Size: 12 bytes
// Hàm #1244 | Địa chỉ PC: 0x0bd544 | Địa chỉ FDE: 0x148a38 | Kích thước: 12 bytes
//   0x0bd544: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x0bd548: 910003FD  mov      x29, sp
//   0x0bd54c: 97FDDAA1  bl       #0x33fd0
static inline uint64_t fde_func_1244_0x0bd544(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0bd544ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x000cULL;
    return acc;
}

// Func #1245 | PC: 0x0bd550 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #1245 | Địa chỉ PC: 0x0bd550 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0bd550: D10303FF  sub      sp, sp, #0xc0
//   0x0bd554: F9003BF9  str      x25, [sp, #0x70]
//   0x0bd558: A9085FF8  stp      x24, x23, [sp, #0x80]
//   0x0bd55c: A90957F6  stp      x22, x21, [sp, #0x90]
static inline uint64_t fde_func_1245_0x0bd550(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0bd550ULL ^ (static_cast<uint64_t>(0xd10303ffULL) << 13);
    acc = (acc + a1 + 0xf9003bf9ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #1246 | PC: 0x0bd8c8 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #1246 | Địa chỉ PC: 0x0bd8c8 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0bd8c8: D101C3FF  sub      sp, sp, #0x70
//   0x0bd8cc: A90457F6  stp      x22, x21, [sp, #0x40]
//   0x0bd8d0: A9054FF4  stp      x20, x19, [sp, #0x50]
//   0x0bd8d4: A9067BFD  stp      x29, x30, [sp, #0x60]
static inline uint64_t fde_func_1246_0x0bd8c8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0bd8c8ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xa90457f6ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #1247 | PC: 0x0bda9c | FDE: 0x148a38 | Size: 244 bytes
// Hàm #1247 | Địa chỉ PC: 0x0bda9c | Địa chỉ FDE: 0x148a38 | Kích thước: 244 bytes
//   0x0bda9c: D100C3FF  sub      sp, sp, #0x30
//   0x0bdaa0: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0bdaa4: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0bdaa8: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1247_0x0bda9c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0bda9cULL ^ (static_cast<uint64_t>(0xd100c3ffULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x00f4ULL;
    return acc;
}

// Func #1248 | PC: 0x0bdb90 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #1248 | Địa chỉ PC: 0x0bdb90 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0bdb90: D10103FF  sub      sp, sp, #0x40
//   0x0bdb94: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x0bdb98: A9037BFD  stp      x29, x30, [sp, #0x30]
//   0x0bdb9c: 9100C3FD  add      x29, sp, #0x30
static inline uint64_t fde_func_1248_0x0bdb90(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0bdb90ULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xa9024ff4ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #1249 | PC: 0x0bde28 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #1249 | Địa chỉ PC: 0x0bde28 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0bde28: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0bde2c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0bde30: 910043FD  add      x29, sp, #0x10
//   0x0bde34: EB02003F  cmp      x1, x2
static inline uint64_t fde_func_1249_0x0bde28(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0bde28ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #1250 | PC: 0x0be124 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #1250 | Địa chỉ PC: 0x0be124 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0be124: D10343FF  sub      sp, sp, #0xd0
//   0x0be128: F90043F9  str      x25, [sp, #0x80]
//   0x0be12c: A9095FF8  stp      x24, x23, [sp, #0x90]
//   0x0be130: A90A57F6  stp      x22, x21, [sp, #0xa0]
static inline uint64_t fde_func_1250_0x0be124(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0be124ULL ^ (static_cast<uint64_t>(0xd10343ffULL) << 13);
    acc = (acc + a1 + 0xf90043f9ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #1251 | PC: 0x0be6b4 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #1251 | Địa chỉ PC: 0x0be6b4 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0be6b4: A9BB67FA  stp      x26, x25, [sp, #-0x50]!
//   0x0be6b8: A9015FF8  stp      x24, x23, [sp, #0x10]
//   0x0be6bc: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x0be6c0: A9034FF4  stp      x20, x19, [sp, #0x30]
static inline uint64_t fde_func_1251_0x0be6b4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0be6b4ULL ^ (static_cast<uint64_t>(0xa9bb67faULL) << 13);
    acc = (acc + a1 + 0xa9015ff8ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #1252 | PC: 0x0be7f0 | FDE: 0x148a38 | Size: 12 bytes
// Hàm #1252 | Địa chỉ PC: 0x0be7f0 | Địa chỉ FDE: 0x148a38 | Kích thước: 12 bytes
//   0x0be7f0: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x0be7f4: 910003FD  mov      x29, sp
//   0x0be7f8: 97FDD5F6  bl       #0x33fd0
static inline uint64_t fde_func_1252_0x0be7f0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0be7f0ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x000cULL;
    return acc;
}

// Func #1253 | PC: 0x0be7fc | FDE: 0x148a38 | Size: 72 bytes
// Hàm #1253 | Địa chỉ PC: 0x0be7fc | Địa chỉ FDE: 0x148a38 | Kích thước: 72 bytes
//   0x0be7fc: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0be800: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0be804: 910043FD  add      x29, sp, #0x10
//   0x0be808: A9492014  ldp      x20, x8, [x0, #0x90]
static inline uint64_t fde_func_1253_0x0be7fc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0be7fcULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0048ULL;
    return acc;
}

// Func #1254 | PC: 0x0be844 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #1254 | Địa chỉ PC: 0x0be844 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0be844: D101C3FF  sub      sp, sp, #0x70
//   0x0be848: A9035FF8  stp      x24, x23, [sp, #0x30]
//   0x0be84c: A90457F6  stp      x22, x21, [sp, #0x40]
//   0x0be850: A9054FF4  stp      x20, x19, [sp, #0x50]
static inline uint64_t fde_func_1254_0x0be844(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0be844ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xa9035ff8ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #1255 | PC: 0x0bea28 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #1255 | Địa chỉ PC: 0x0bea28 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0bea28: D10183FF  sub      sp, sp, #0x60
//   0x0bea2c: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x0bea30: A90357F6  stp      x22, x21, [sp, #0x30]
//   0x0bea34: A9044FF4  stp      x20, x19, [sp, #0x40]
static inline uint64_t fde_func_1255_0x0bea28(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0bea28ULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xa9025ff8ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #1256 | PC: 0x0beb78 | FDE: 0x148a38 | Size: 12 bytes
// Hàm #1256 | Địa chỉ PC: 0x0beb78 | Địa chỉ FDE: 0x148a38 | Kích thước: 12 bytes
//   0x0beb78: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x0beb7c: 910003FD  mov      x29, sp
//   0x0beb80: 97FDD514  bl       #0x33fd0
static inline uint64_t fde_func_1256_0x0beb78(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0beb78ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x000cULL;
    return acc;
}

// Func #1257 | PC: 0x0beb84 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #1257 | Địa chỉ PC: 0x0beb84 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0beb84: D10183FF  sub      sp, sp, #0x60
//   0x0beb88: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x0beb8c: A90357F6  stp      x22, x21, [sp, #0x30]
//   0x0beb90: A9044FF4  stp      x20, x19, [sp, #0x40]
static inline uint64_t fde_func_1257_0x0beb84(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0beb84ULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xa9025ff8ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #1258 | PC: 0x0bee3c | FDE: 0x148a38 | Size: 240 bytes
// Hàm #1258 | Địa chỉ PC: 0x0bee3c | Địa chỉ FDE: 0x148a38 | Kích thước: 240 bytes
//   0x0bee3c: D10183FF  sub      sp, sp, #0x60
//   0x0bee40: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x0bee44: A90357F6  stp      x22, x21, [sp, #0x30]
//   0x0bee48: A9044FF4  stp      x20, x19, [sp, #0x40]
static inline uint64_t fde_func_1258_0x0bee3c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0bee3cULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xa9025ff8ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x00f0ULL;
    return acc;
}

// Func #1259 | PC: 0x0bef2c | FDE: 0x148a38 | Size: 256 bytes
// Hàm #1259 | Địa chỉ PC: 0x0bef2c | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0bef2c: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x0bef30: 910003FD  mov      x29, sp
//   0x0bef34: 97FDD427  bl       #0x33fd0
//   0x0bef38: F81D0FF5  str      x21, [sp, #-0x30]!
static inline uint64_t fde_func_1259_0x0bef2c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0bef2cULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #1260 | PC: 0x0bf078 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #1260 | Địa chỉ PC: 0x0bf078 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0bf078: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0bf07c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0bf080: 910043FD  add      x29, sp, #0x10
//   0x0bf084: A940A014  ldp      x20, x8, [x0, #8]
static inline uint64_t fde_func_1260_0x0bf078(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0bf078ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #1261 | PC: 0x0bf1ac | FDE: 0x148a38 | Size: 240 bytes
// Hàm #1261 | Địa chỉ PC: 0x0bf1ac | Địa chỉ FDE: 0x148a38 | Kích thước: 240 bytes
//   0x0bf1ac: A9BA6FFC  stp      x28, x27, [sp, #-0x60]!
//   0x0bf1b0: A90167FA  stp      x26, x25, [sp, #0x10]
//   0x0bf1b4: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x0bf1b8: A90357F6  stp      x22, x21, [sp, #0x30]
static inline uint64_t fde_func_1261_0x0bf1ac(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0bf1acULL ^ (static_cast<uint64_t>(0xa9ba6ffcULL) << 13);
    acc = (acc + a1 + 0xa90167faULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x00f0ULL;
    return acc;
}

// Func #1262 | PC: 0x0bf29c | FDE: 0x148a38 | Size: 172 bytes
// Hàm #1262 | Địa chỉ PC: 0x0bf29c | Địa chỉ FDE: 0x148a38 | Kích thước: 172 bytes
//   0x0bf29c: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x0bf2a0: 910003FD  mov      x29, sp
//   0x0bf2a4: AA0103E0  mov      x0, x1
//   0x0bf2a8: EB02003F  cmp      x1, x2
static inline uint64_t fde_func_1262_0x0bf29c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0bf29cULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x00acULL;
    return acc;
}

// Func #1263 | PC: 0x0bf348 | FDE: 0x148a38 | Size: 12 bytes
// Hàm #1263 | Địa chỉ PC: 0x0bf348 | Địa chỉ FDE: 0x148a38 | Kích thước: 12 bytes
//   0x0bf348: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x0bf34c: 910003FD  mov      x29, sp
//   0x0bf350: 97FDD320  bl       #0x33fd0
static inline uint64_t fde_func_1263_0x0bf348(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0bf348ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x000cULL;
    return acc;
}

// Func #1264 | PC: 0x0bf354 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #1264 | Địa chỉ PC: 0x0bf354 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0bf354: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x0bf358: 910003FD  mov      x29, sp
//   0x0bf35c: 97FDD31D  bl       #0x33fd0
//   0x0bf360: F81E0FF3  str      x19, [sp, #-0x20]!
static inline uint64_t fde_func_1264_0x0bf354(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0bf354ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #1265 | PC: 0x0bf6a4 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #1265 | Địa chỉ PC: 0x0bf6a4 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0bf6a4: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x0bf6a8: 910003FD  mov      x29, sp
//   0x0bf6ac: 97FDD249  bl       #0x33fd0
//   0x0bf6b0: F81C0FF7  str      x23, [sp, #-0x40]!
static inline uint64_t fde_func_1265_0x0bf6a4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0bf6a4ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #1266 | PC: 0x0bfa14 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #1266 | Địa chỉ PC: 0x0bfa14 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0bfa14: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x0bfa18: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0bfa1c: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0bfa20: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1266_0x0bfa14(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0bfa14ULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #1267 | PC: 0x0c01b4 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #1267 | Địa chỉ PC: 0x0c01b4 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0c01b4: D10543FF  sub      sp, sp, #0x150
//   0x0c01b8: A90F6FFC  stp      x28, x27, [sp, #0xf0]
//   0x0c01bc: A91067FA  stp      x26, x25, [sp, #0x100]
//   0x0c01c0: A9115FF8  stp      x24, x23, [sp, #0x110]
static inline uint64_t fde_func_1267_0x0c01b4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0c01b4ULL ^ (static_cast<uint64_t>(0xd10543ffULL) << 13);
    acc = (acc + a1 + 0xa90f6ffcULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #1268 | PC: 0x0c0570 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #1268 | Địa chỉ PC: 0x0c0570 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0c0570: D10703FF  sub      sp, sp, #0x1c0
//   0x0c0574: A9166FFC  stp      x28, x27, [sp, #0x160]
//   0x0c0578: A91767FA  stp      x26, x25, [sp, #0x170]
//   0x0c057c: A9185FF8  stp      x24, x23, [sp, #0x180]
static inline uint64_t fde_func_1268_0x0c0570(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0c0570ULL ^ (static_cast<uint64_t>(0xd10703ffULL) << 13);
    acc = (acc + a1 + 0xa9166ffcULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #1269 | PC: 0x0c09a4 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #1269 | Địa chỉ PC: 0x0c09a4 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0c09a4: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0c09a8: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0c09ac: 910043FD  add      x29, sp, #0x10
//   0x0c09b0: A940A408  ldp      x8, x9, [x0, #8]
static inline uint64_t fde_func_1269_0x0c09a4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0c09a4ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #1270 | PC: 0x0c0aa8 | FDE: 0x148a38 | Size: 128 bytes
// Hàm #1270 | Địa chỉ PC: 0x0c0aa8 | Địa chỉ FDE: 0x148a38 | Kích thước: 128 bytes
//   0x0c0aa8: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0c0aac: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0c0ab0: 910043FD  add      x29, sp, #0x10
//   0x0c0ab4: AA0003F4  mov      x20, x0
static inline uint64_t fde_func_1270_0x0c0aa8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0c0aa8ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0080ULL;
    return acc;
}

// Func #1271 | PC: 0x0c0b28 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #1271 | Địa chỉ PC: 0x0c0b28 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0c0b28: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0c0b2c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0c0b30: 910043FD  add      x29, sp, #0x10
//   0x0c0b34: F9401008  ldr      x8, [x0, #0x20]
static inline uint64_t fde_func_1271_0x0c0b28(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0c0b28ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #1272 | PC: 0x0c0c68 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #1272 | Địa chỉ PC: 0x0c0c68 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0c0c68: D10203FF  sub      sp, sp, #0x80
//   0x0c0c6c: F9001BF9  str      x25, [sp, #0x30]
//   0x0c0c70: A9045FF8  stp      x24, x23, [sp, #0x40]
//   0x0c0c74: A90557F6  stp      x22, x21, [sp, #0x50]
static inline uint64_t fde_func_1272_0x0c0c68(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0c0c68ULL ^ (static_cast<uint64_t>(0xd10203ffULL) << 13);
    acc = (acc + a1 + 0xf9001bf9ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #1273 | PC: 0x0c108c | FDE: 0x148a38 | Size: 256 bytes
// Hàm #1273 | Địa chỉ PC: 0x0c108c | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0c108c: A9BC5FF8  stp      x24, x23, [sp, #-0x40]!
//   0x0c1090: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x0c1094: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x0c1098: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_1273_0x0c108c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0c108cULL ^ (static_cast<uint64_t>(0xa9bc5ff8ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #1274 | PC: 0x0c12f4 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #1274 | Địa chỉ PC: 0x0c12f4 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0c12f4: A9BC5FF8  stp      x24, x23, [sp, #-0x40]!
//   0x0c12f8: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x0c12fc: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x0c1300: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_1274_0x0c12f4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0c12f4ULL ^ (static_cast<uint64_t>(0xa9bc5ff8ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #1275 | PC: 0x0c14a4 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #1275 | Địa chỉ PC: 0x0c14a4 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0c14a4: A9BC5FF8  stp      x24, x23, [sp, #-0x40]!
//   0x0c14a8: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x0c14ac: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x0c14b0: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_1275_0x0c14a4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0c14a4ULL ^ (static_cast<uint64_t>(0xa9bc5ff8ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #1276 | PC: 0x0c15d8 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #1276 | Địa chỉ PC: 0x0c15d8 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0c15d8: D10203FF  sub      sp, sp, #0x80
//   0x0c15dc: F9001BF9  str      x25, [sp, #0x30]
//   0x0c15e0: A9045FF8  stp      x24, x23, [sp, #0x40]
//   0x0c15e4: A90557F6  stp      x22, x21, [sp, #0x50]
static inline uint64_t fde_func_1276_0x0c15d8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0c15d8ULL ^ (static_cast<uint64_t>(0xd10203ffULL) << 13);
    acc = (acc + a1 + 0xf9001bf9ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #1277 | PC: 0x0c18d0 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #1277 | Địa chỉ PC: 0x0c18d0 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0c18d0: A9BC5FF8  stp      x24, x23, [sp, #-0x40]!
//   0x0c18d4: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x0c18d8: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x0c18dc: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_1277_0x0c18d0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0c18d0ULL ^ (static_cast<uint64_t>(0xa9bc5ff8ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #1278 | PC: 0x0c1bb8 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #1278 | Địa chỉ PC: 0x0c1bb8 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0c1bb8: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x0c1bbc: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0c1bc0: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0c1bc4: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1278_0x0c1bb8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0c1bb8ULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #1279 | PC: 0x0c1d90 | FDE: 0x148a38 | Size: 148 bytes
// Hàm #1279 | Địa chỉ PC: 0x0c1d90 | Địa chỉ FDE: 0x148a38 | Kích thước: 148 bytes
//   0x0c1d90: D10103FF  sub      sp, sp, #0x40
//   0x0c1d94: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x0c1d98: A9037BFD  stp      x29, x30, [sp, #0x30]
//   0x0c1d9c: 9100C3FD  add      x29, sp, #0x30
static inline uint64_t fde_func_1279_0x0c1d90(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0c1d90ULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xa9024ff4ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0094ULL;
    return acc;
}

// Func #1280 | PC: 0x0c1e24 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #1280 | Địa chỉ PC: 0x0c1e24 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0c1e24: D10303FF  sub      sp, sp, #0xc0
//   0x0c1e28: A90957F6  stp      x22, x21, [sp, #0x90]
//   0x0c1e2c: A90A4FF4  stp      x20, x19, [sp, #0xa0]
//   0x0c1e30: A90B7BFD  stp      x29, x30, [sp, #0xb0]
static inline uint64_t fde_func_1280_0x0c1e24(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0c1e24ULL ^ (static_cast<uint64_t>(0xd10303ffULL) << 13);
    acc = (acc + a1 + 0xa90957f6ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #1281 | PC: 0x0c1f34 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #1281 | Địa chỉ PC: 0x0c1f34 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0c1f34: D105C3FF  sub      sp, sp, #0x170
//   0x0c1f38: A91267FC  stp      x28, x25, [sp, #0x120]
//   0x0c1f3c: A9135FF8  stp      x24, x23, [sp, #0x130]
//   0x0c1f40: A91457F6  stp      x22, x21, [sp, #0x140]
static inline uint64_t fde_func_1281_0x0c1f34(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0c1f34ULL ^ (static_cast<uint64_t>(0xd105c3ffULL) << 13);
    acc = (acc + a1 + 0xa91267fcULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #1282 | PC: 0x0c2380 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #1282 | Địa chỉ PC: 0x0c2380 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0c2380: D10343FF  sub      sp, sp, #0xd0
//   0x0c2384: A90A57F6  stp      x22, x21, [sp, #0xa0]
//   0x0c2388: A90B4FF4  stp      x20, x19, [sp, #0xb0]
//   0x0c238c: A90C7BFD  stp      x29, x30, [sp, #0xc0]
static inline uint64_t fde_func_1282_0x0c2380(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0c2380ULL ^ (static_cast<uint64_t>(0xd10343ffULL) << 13);
    acc = (acc + a1 + 0xa90a57f6ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #1283 | PC: 0x0c2514 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #1283 | Địa chỉ PC: 0x0c2514 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0c2514: D10303FF  sub      sp, sp, #0xc0
//   0x0c2518: A90957F6  stp      x22, x21, [sp, #0x90]
//   0x0c251c: A90A4FF4  stp      x20, x19, [sp, #0xa0]
//   0x0c2520: A90B7BFD  stp      x29, x30, [sp, #0xb0]
static inline uint64_t fde_func_1283_0x0c2514(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0c2514ULL ^ (static_cast<uint64_t>(0xd10303ffULL) << 13);
    acc = (acc + a1 + 0xa90957f6ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #1284 | PC: 0x0c2620 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #1284 | Địa chỉ PC: 0x0c2620 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0c2620: D10343FF  sub      sp, sp, #0xd0
//   0x0c2624: A9095FF8  stp      x24, x23, [sp, #0x90]
//   0x0c2628: A90A57F6  stp      x22, x21, [sp, #0xa0]
//   0x0c262c: A90B4FF4  stp      x20, x19, [sp, #0xb0]
static inline uint64_t fde_func_1284_0x0c2620(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0c2620ULL ^ (static_cast<uint64_t>(0xd10343ffULL) << 13);
    acc = (acc + a1 + 0xa9095ff8ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #1285 | PC: 0x0c27bc | FDE: 0x148a38 | Size: 248 bytes
// Hàm #1285 | Địa chỉ PC: 0x0c27bc | Địa chỉ FDE: 0x148a38 | Kích thước: 248 bytes
//   0x0c27bc: D10143FF  sub      sp, sp, #0x50
//   0x0c27c0: F90013F5  str      x21, [sp, #0x20]
//   0x0c27c4: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x0c27c8: A9047BFD  stp      x29, x30, [sp, #0x40]
static inline uint64_t fde_func_1285_0x0c27bc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0c27bcULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xf90013f5ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x00f8ULL;
    return acc;
}

// Func #1286 | PC: 0x0c28b4 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #1286 | Địa chỉ PC: 0x0c28b4 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0c28b4: D10303FF  sub      sp, sp, #0xc0
//   0x0c28b8: A90957F6  stp      x22, x21, [sp, #0x90]
//   0x0c28bc: A90A4FF4  stp      x20, x19, [sp, #0xa0]
//   0x0c28c0: A90B7BFD  stp      x29, x30, [sp, #0xb0]
static inline uint64_t fde_func_1286_0x0c28b4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0c28b4ULL ^ (static_cast<uint64_t>(0xd10303ffULL) << 13);
    acc = (acc + a1 + 0xa90957f6ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #1287 | PC: 0x0c29c0 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #1287 | Địa chỉ PC: 0x0c29c0 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0c29c0: D10303FF  sub      sp, sp, #0xc0
//   0x0c29c4: A90957F6  stp      x22, x21, [sp, #0x90]
//   0x0c29c8: A90A4FF4  stp      x20, x19, [sp, #0xa0]
//   0x0c29cc: A90B7BFD  stp      x29, x30, [sp, #0xb0]
static inline uint64_t fde_func_1287_0x0c29c0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0c29c0ULL ^ (static_cast<uint64_t>(0xd10303ffULL) << 13);
    acc = (acc + a1 + 0xa90957f6ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #1288 | PC: 0x0c2acc | FDE: 0x148a38 | Size: 160 bytes
// Hàm #1288 | Địa chỉ PC: 0x0c2acc | Địa chỉ FDE: 0x148a38 | Kích thước: 160 bytes
//   0x0c2acc: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x0c2ad0: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0c2ad4: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0c2ad8: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1288_0x0c2acc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0c2accULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x00a0ULL;
    return acc;
}

// Func #1289 | PC: 0x0c2b6c | FDE: 0x148a38 | Size: 256 bytes
// Hàm #1289 | Địa chỉ PC: 0x0c2b6c | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0c2b6c: D10303FF  sub      sp, sp, #0xc0
//   0x0c2b70: A90957F6  stp      x22, x21, [sp, #0x90]
//   0x0c2b74: A90A4FF4  stp      x20, x19, [sp, #0xa0]
//   0x0c2b78: A90B7BFD  stp      x29, x30, [sp, #0xb0]
static inline uint64_t fde_func_1289_0x0c2b6c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0c2b6cULL ^ (static_cast<uint64_t>(0xd10303ffULL) << 13);
    acc = (acc + a1 + 0xa90957f6ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #1290 | PC: 0x0c2c6c | FDE: 0x148a38 | Size: 256 bytes
// Hàm #1290 | Địa chỉ PC: 0x0c2c6c | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0c2c6c: D10303FF  sub      sp, sp, #0xc0
//   0x0c2c70: A90957F6  stp      x22, x21, [sp, #0x90]
//   0x0c2c74: A90A4FF4  stp      x20, x19, [sp, #0xa0]
//   0x0c2c78: A90B7BFD  stp      x29, x30, [sp, #0xb0]
static inline uint64_t fde_func_1290_0x0c2c6c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0c2c6cULL ^ (static_cast<uint64_t>(0xd10303ffULL) << 13);
    acc = (acc + a1 + 0xa90957f6ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #1291 | PC: 0x0c2d6c | FDE: 0x148a38 | Size: 256 bytes
// Hàm #1291 | Địa chỉ PC: 0x0c2d6c | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0c2d6c: D10183FF  sub      sp, sp, #0x60
//   0x0c2d70: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x0c2d74: A90357F6  stp      x22, x21, [sp, #0x30]
//   0x0c2d78: A9044FF4  stp      x20, x19, [sp, #0x40]
static inline uint64_t fde_func_1291_0x0c2d6c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0c2d6cULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xa9025ff8ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #1292 | PC: 0x0c2f00 | FDE: 0x148a38 | Size: 172 bytes
// Hàm #1292 | Địa chỉ PC: 0x0c2f00 | Địa chỉ FDE: 0x148a38 | Kích thước: 172 bytes
//   0x0c2f00: D10103FF  sub      sp, sp, #0x40
//   0x0c2f04: A900D7FF  stp      xzr, x21, [sp, #8]
//   0x0c2f08: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x0c2f0c: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_1292_0x0c2f00(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0c2f00ULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xa900d7ffULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x00acULL;
    return acc;
}

// Func #1293 | PC: 0x0c2fac | FDE: 0x148a38 | Size: 256 bytes
// Hàm #1293 | Địa chỉ PC: 0x0c2fac | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0c2fac: A9BA6FFC  stp      x28, x27, [sp, #-0x60]!
//   0x0c2fb0: A90167FA  stp      x26, x25, [sp, #0x10]
//   0x0c2fb4: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x0c2fb8: A90357F6  stp      x22, x21, [sp, #0x30]
static inline uint64_t fde_func_1293_0x0c2fac(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0c2facULL ^ (static_cast<uint64_t>(0xa9ba6ffcULL) << 13);
    acc = (acc + a1 + 0xa90167faULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #1294 | PC: 0x0c3130 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #1294 | Địa chỉ PC: 0x0c3130 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0c3130: D10143FF  sub      sp, sp, #0x50
//   0x0c3134: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x0c3138: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x0c313c: A9047BFD  stp      x29, x30, [sp, #0x40]
static inline uint64_t fde_func_1294_0x0c3130(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0c3130ULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xa90257f6ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #1295 | PC: 0x0c3274 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #1295 | Địa chỉ PC: 0x0c3274 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0c3274: D10143FF  sub      sp, sp, #0x50
//   0x0c3278: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x0c327c: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x0c3280: A9047BFD  stp      x29, x30, [sp, #0x40]
static inline uint64_t fde_func_1295_0x0c3274(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0c3274ULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xa90257f6ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #1296 | PC: 0x0c33b8 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #1296 | Địa chỉ PC: 0x0c33b8 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0c33b8: D10143FF  sub      sp, sp, #0x50
//   0x0c33bc: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x0c33c0: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x0c33c4: A9047BFD  stp      x29, x30, [sp, #0x40]
static inline uint64_t fde_func_1296_0x0c33b8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0c33b8ULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xa90257f6ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #1297 | PC: 0x0c34f8 | FDE: 0x148a38 | Size: 88 bytes
// Hàm #1297 | Địa chỉ PC: 0x0c34f8 | Địa chỉ FDE: 0x148a38 | Kích thước: 88 bytes
//   0x0c34f8: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x0c34fc: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0c3500: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0c3504: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1297_0x0c34f8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0c34f8ULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0058ULL;
    return acc;
}

// Func #1298 | PC: 0x0c3550 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #1298 | Địa chỉ PC: 0x0c3550 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0c3550: A9BB67FA  stp      x26, x25, [sp, #-0x50]!
//   0x0c3554: A9015FF8  stp      x24, x23, [sp, #0x10]
//   0x0c3558: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x0c355c: A9034FF4  stp      x20, x19, [sp, #0x30]
static inline uint64_t fde_func_1298_0x0c3550(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0c3550ULL ^ (static_cast<uint64_t>(0xa9bb67faULL) << 13);
    acc = (acc + a1 + 0xa9015ff8ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #1299 | PC: 0x0c36ac | FDE: 0x148a38 | Size: 256 bytes
// Hàm #1299 | Địa chỉ PC: 0x0c36ac | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0c36ac: D10183FF  sub      sp, sp, #0x60
//   0x0c36b0: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x0c36b4: A90357F6  stp      x22, x21, [sp, #0x30]
//   0x0c36b8: A9044FF4  stp      x20, x19, [sp, #0x40]
static inline uint64_t fde_func_1299_0x0c36ac(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0c36acULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xa9025ff8ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #1300 | PC: 0x0c38d4 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #1300 | Địa chỉ PC: 0x0c38d4 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0c38d4: D10343FF  sub      sp, sp, #0xd0
//   0x0c38d8: F9004BF7  str      x23, [sp, #0x90]
//   0x0c38dc: A90A57F6  stp      x22, x21, [sp, #0xa0]
//   0x0c38e0: A90B4FF4  stp      x20, x19, [sp, #0xb0]
static inline uint64_t fde_func_1300_0x0c38d4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0c38d4ULL ^ (static_cast<uint64_t>(0xd10343ffULL) << 13);
    acc = (acc + a1 + 0xf9004bf7ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #1301 | PC: 0x0c3a80 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #1301 | Địa chỉ PC: 0x0c3a80 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0c3a80: D104C3FF  sub      sp, sp, #0x130
//   0x0c3a84: A90D6FFC  stp      x28, x27, [sp, #0xd0]
//   0x0c3a88: A90E67FA  stp      x26, x25, [sp, #0xe0]
//   0x0c3a8c: A90F5FF8  stp      x24, x23, [sp, #0xf0]
static inline uint64_t fde_func_1301_0x0c3a80(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0c3a80ULL ^ (static_cast<uint64_t>(0xd104c3ffULL) << 13);
    acc = (acc + a1 + 0xa90d6ffcULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #1302 | PC: 0x0c3e8c | FDE: 0x148a38 | Size: 64 bytes
// Hàm #1302 | Địa chỉ PC: 0x0c3e8c | Địa chỉ FDE: 0x148a38 | Kích thước: 64 bytes
//   0x0c3e8c: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0c3e90: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0c3e94: 910043FD  add      x29, sp, #0x10
//   0x0c3e98: AA0103F3  mov      x19, x1
static inline uint64_t fde_func_1302_0x0c3e8c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0c3e8cULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0040ULL;
    return acc;
}

// Func #1303 | PC: 0x0c3ecc | FDE: 0x148a38 | Size: 160 bytes
// Hàm #1303 | Địa chỉ PC: 0x0c3ecc | Địa chỉ FDE: 0x148a38 | Kích thước: 160 bytes
//   0x0c3ecc: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0c3ed0: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0c3ed4: 910043FD  add      x29, sp, #0x10
//   0x0c3ed8: AA0103F3  mov      x19, x1
static inline uint64_t fde_func_1303_0x0c3ecc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0c3eccULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x00a0ULL;
    return acc;
}

// Func #1304 | PC: 0x0c3f6c | FDE: 0x148a38 | Size: 256 bytes
// Hàm #1304 | Địa chỉ PC: 0x0c3f6c | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0c3f6c: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0c3f70: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0c3f74: 910043FD  add      x29, sp, #0x10
//   0x0c3f78: F9400414  ldr      x20, [x0, #8]
static inline uint64_t fde_func_1304_0x0c3f6c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0c3f6cULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #1305 | PC: 0x0c41fc | FDE: 0x148a38 | Size: 224 bytes
// Hàm #1305 | Địa chỉ PC: 0x0c41fc | Địa chỉ FDE: 0x148a38 | Kích thước: 224 bytes
//   0x0c41fc: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0c4200: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0c4204: 910043FD  add      x29, sp, #0x10
//   0x0c4208: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_1305_0x0c41fc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0c41fcULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x00e0ULL;
    return acc;
}

// Func #1306 | PC: 0x0c42dc | FDE: 0x148a38 | Size: 20 bytes
// Hàm #1306 | Địa chỉ PC: 0x0c42dc | Địa chỉ FDE: 0x148a38 | Kích thước: 20 bytes
//   0x0c42dc: A9BC5FFC  stp      x28, x23, [sp, #-0x40]!
//   0x0c42e0: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x0c42e4: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x0c42e8: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_1306_0x0c42dc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0c42dcULL ^ (static_cast<uint64_t>(0xa9bc5ffcULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0014ULL;
    return acc;
}

// Func #1307 | PC: 0x0c42f0 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #1307 | Địa chỉ PC: 0x0c42f0 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0c42f0: D130C3FF  sub      sp, sp, #0xc30
//   0x0c42f4: F9400413  ldr      x19, [x0, #8]
//   0x0c42f8: AA0003F4  mov      x20, x0
//   0x0c42fc: 9100A3E0  add      x0, sp, #0x28
static inline uint64_t fde_func_1307_0x0c42f0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0c42f0ULL ^ (static_cast<uint64_t>(0xd130c3ffULL) << 13);
    acc = (acc + a1 + 0xf9400413ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #1308 | PC: 0x0c44c0 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #1308 | Địa chỉ PC: 0x0c44c0 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0c44c0: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0c44c4: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0c44c8: 910043FD  add      x29, sp, #0x10
//   0x0c44cc: AA0103F4  mov      x20, x1
static inline uint64_t fde_func_1308_0x0c44c0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0c44c0ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #1309 | PC: 0x0c4640 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #1309 | Địa chỉ PC: 0x0c4640 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0c4640: D100C3FF  sub      sp, sp, #0x30
//   0x0c4644: F9000BF3  str      x19, [sp, #0x10]
//   0x0c4648: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0c464c: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1309_0x0c4640(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0c4640ULL ^ (static_cast<uint64_t>(0xd100c3ffULL) << 13);
    acc = (acc + a1 + 0xf9000bf3ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #1310 | PC: 0x0c47e0 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #1310 | Địa chỉ PC: 0x0c47e0 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0c47e0: D100C3FF  sub      sp, sp, #0x30
//   0x0c47e4: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0c47e8: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0c47ec: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1310_0x0c47e0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0c47e0ULL ^ (static_cast<uint64_t>(0xd100c3ffULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #1311 | PC: 0x0c49b4 | FDE: 0x148a38 | Size: 16 bytes
// Hàm #1311 | Địa chỉ PC: 0x0c49b4 | Địa chỉ FDE: 0x148a38 | Kích thước: 16 bytes
//   0x0c49b4: A9BD57FC  stp      x28, x21, [sp, #-0x30]!
//   0x0c49b8: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0c49bc: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0c49c0: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1311_0x0c49b4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0c49b4ULL ^ (static_cast<uint64_t>(0xa9bd57fcULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0010ULL;
    return acc;
}

// Func #1312 | PC: 0x0c49c4 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #1312 | Địa chỉ PC: 0x0c49c4 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0c49c4: D130C3FF  sub      sp, sp, #0xc30
//   0x0c49c8: F9400414  ldr      x20, [x0, #8]
//   0x0c49cc: AA0003F3  mov      x19, x0
//   0x0c49d0: 9100A3E0  add      x0, sp, #0x28
static inline uint64_t fde_func_1312_0x0c49c4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0c49c4ULL ^ (static_cast<uint64_t>(0xd130c3ffULL) << 13);
    acc = (acc + a1 + 0xf9400414ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #1313 | PC: 0x0c4c54 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #1313 | Địa chỉ PC: 0x0c4c54 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0c4c54: D100C3FF  sub      sp, sp, #0x30
//   0x0c4c58: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0c4c5c: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0c4c60: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1313_0x0c4c54(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0c4c54ULL ^ (static_cast<uint64_t>(0xd100c3ffULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #1314 | PC: 0x0c4e08 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #1314 | Địa chỉ PC: 0x0c4e08 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0c4e08: D100C3FF  sub      sp, sp, #0x30
//   0x0c4e0c: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0c4e10: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0c4e14: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1314_0x0c4e08(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0c4e08ULL ^ (static_cast<uint64_t>(0xd100c3ffULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #1315 | PC: 0x0c4f18 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #1315 | Địa chỉ PC: 0x0c4f18 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0c4f18: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x0c4f1c: 910003FD  mov      x29, sp
//   0x0c4f20: F9400408  ldr      x8, [x0, #8]
//   0x0c4f24: 91004001  add      x1, x0, #0x10
static inline uint64_t fde_func_1315_0x0c4f18(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0c4f18ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #1316 | PC: 0x0c50e0 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #1316 | Địa chỉ PC: 0x0c50e0 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0c50e0: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x0c50e4: 910003FD  mov      x29, sp
//   0x0c50e8: F9400408  ldr      x8, [x0, #8]
//   0x0c50ec: 91004001  add      x1, x0, #0x10
static inline uint64_t fde_func_1316_0x0c50e0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0c50e0ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #1317 | PC: 0x0c5224 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #1317 | Địa chỉ PC: 0x0c5224 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0c5224: D10183FF  sub      sp, sp, #0x60
//   0x0c5228: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x0c522c: A90357F6  stp      x22, x21, [sp, #0x30]
//   0x0c5230: A9044FF4  stp      x20, x19, [sp, #0x40]
static inline uint64_t fde_func_1317_0x0c5224(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0c5224ULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xa9025ff8ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #1318 | PC: 0x0c53b0 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #1318 | Địa chỉ PC: 0x0c53b0 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0c53b0: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0c53b4: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0c53b8: 910043FD  add      x29, sp, #0x10
//   0x0c53bc: AA0003E8  mov      x8, x0
static inline uint64_t fde_func_1318_0x0c53b0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0c53b0ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #1319 | PC: 0x0c56d8 | FDE: 0x148a38 | Size: 76 bytes
// Hàm #1319 | Địa chỉ PC: 0x0c56d8 | Địa chỉ FDE: 0x148a38 | Kích thước: 76 bytes
//   0x0c56d8: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x0c56dc: 910003FD  mov      x29, sp
//   0x0c56e0: F9400408  ldr      x8, [x0, #8]
//   0x0c56e4: 91004001  add      x1, x0, #0x10
static inline uint64_t fde_func_1319_0x0c56d8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0c56d8ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x004cULL;
    return acc;
}

// Func #1320 | PC: 0x0c5724 | FDE: 0x148a38 | Size: 140 bytes [_ZN3com2ss5ttmio21MDLIOManagerImplement11getInstanceEv]
// Hàm #1320 | Địa chỉ PC: 0x0c5724 | Địa chỉ FDE: 0x148a38 | Kích thước: 140 bytes
//   0x0c5724: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0c5728: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0c572c: 910043FD  add      x29, sp, #0x10
//   0x0c5730: F00004B4  adrp     x20, #0x15c000
static inline uint64_t fde_func_1320_0x0c5724(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0c5724ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x008cULL;
    return acc;
}

// Func #1321 | PC: 0x0c57b0 | FDE: 0x148a38 | Size: 256 bytes [_ZN3com2ss5ttmio19getIoTaskInfoHolderEv]
// Hàm #1321 | Địa chỉ PC: 0x0c57b0 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0c57b0: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x0c57b4: 910003FD  mov      x29, sp
//   0x0c57b8: 97FDBC06  bl       #0x347d0
//   0x0c57bc: 91002008  add      x8, x0, #8
static inline uint64_t fde_func_1321_0x0c57b0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0c57b0ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #1322 | PC: 0x0c58c8 | FDE: 0x148a38 | Size: 228 bytes
// Hàm #1322 | Địa chỉ PC: 0x0c58c8 | Địa chỉ FDE: 0x148a38 | Kích thước: 228 bytes
//   0x0c58c8: D10103FF  sub      sp, sp, #0x40
//   0x0c58cc: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x0c58d0: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x0c58d4: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_1322_0x0c58c8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0c58c8ULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x00e4ULL;
    return acc;
}

// Func #1323 | PC: 0x0c59ac | FDE: 0x148a38 | Size: 112 bytes
// Hàm #1323 | Địa chỉ PC: 0x0c59ac | Địa chỉ FDE: 0x148a38 | Kích thước: 112 bytes
//   0x0c59ac: D10243FF  sub      sp, sp, #0x90
//   0x0c59b0: A9074FF4  stp      x20, x19, [sp, #0x70]
//   0x0c59b4: A9087BFD  stp      x29, x30, [sp, #0x80]
//   0x0c59b8: 910203FD  add      x29, sp, #0x80
static inline uint64_t fde_func_1323_0x0c59ac(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0c59acULL ^ (static_cast<uint64_t>(0xd10243ffULL) << 13);
    acc = (acc + a1 + 0xa9074ff4ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0070ULL;
    return acc;
}

// Func #1324 | PC: 0x0c5a1c | FDE: 0x148a38 | Size: 256 bytes
// Hàm #1324 | Địa chỉ PC: 0x0c5a1c | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0c5a1c: D10383FF  sub      sp, sp, #0xe0
//   0x0c5a20: A90A5FF8  stp      x24, x23, [sp, #0xa0]
//   0x0c5a24: A90B57F6  stp      x22, x21, [sp, #0xb0]
//   0x0c5a28: A90C4FF4  stp      x20, x19, [sp, #0xc0]
static inline uint64_t fde_func_1324_0x0c5a1c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0c5a1cULL ^ (static_cast<uint64_t>(0xd10383ffULL) << 13);
    acc = (acc + a1 + 0xa90a5ff8ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #1325 | PC: 0x0c5d40 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #1325 | Địa chỉ PC: 0x0c5d40 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0c5d40: D10503FF  sub      sp, sp, #0x140
//   0x0c5d44: A90E6FFC  stp      x28, x27, [sp, #0xe0]
//   0x0c5d48: A90F67FA  stp      x26, x25, [sp, #0xf0]
//   0x0c5d4c: A9105FF8  stp      x24, x23, [sp, #0x100]
static inline uint64_t fde_func_1325_0x0c5d40(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0c5d40ULL ^ (static_cast<uint64_t>(0xd10503ffULL) << 13);
    acc = (acc + a1 + 0xa90e6ffcULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #1326 | PC: 0x0c63f4 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #1326 | Địa chỉ PC: 0x0c63f4 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0c63f4: D10383FF  sub      sp, sp, #0xe0
//   0x0c63f8: F90053F7  str      x23, [sp, #0xa0]
//   0x0c63fc: A90B57F6  stp      x22, x21, [sp, #0xb0]
//   0x0c6400: A90C4FF4  stp      x20, x19, [sp, #0xc0]
static inline uint64_t fde_func_1326_0x0c63f4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0c63f4ULL ^ (static_cast<uint64_t>(0xd10383ffULL) << 13);
    acc = (acc + a1 + 0xf90053f7ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #1327 | PC: 0x0c65a8 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #1327 | Địa chỉ PC: 0x0c65a8 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0c65a8: D102C3FF  sub      sp, sp, #0xb0
//   0x0c65ac: A90667FA  stp      x26, x25, [sp, #0x60]
//   0x0c65b0: A9075FF8  stp      x24, x23, [sp, #0x70]
//   0x0c65b4: A90857F6  stp      x22, x21, [sp, #0x80]
static inline uint64_t fde_func_1327_0x0c65a8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0c65a8ULL ^ (static_cast<uint64_t>(0xd102c3ffULL) << 13);
    acc = (acc + a1 + 0xa90667faULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #1328 | PC: 0x0c69fc | FDE: 0x148a38 | Size: 256 bytes
// Hàm #1328 | Địa chỉ PC: 0x0c69fc | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0c69fc: D101C3FF  sub      sp, sp, #0x70
//   0x0c6a00: A9035FF8  stp      x24, x23, [sp, #0x30]
//   0x0c6a04: A90457F6  stp      x22, x21, [sp, #0x40]
//   0x0c6a08: A9054FF4  stp      x20, x19, [sp, #0x50]
static inline uint64_t fde_func_1328_0x0c69fc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0c69fcULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xa9035ff8ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #1329 | PC: 0x0c6bfc | FDE: 0x148a38 | Size: 248 bytes
// Hàm #1329 | Địa chỉ PC: 0x0c6bfc | Địa chỉ FDE: 0x148a38 | Kích thước: 248 bytes
//   0x0c6bfc: D10183FF  sub      sp, sp, #0x60
//   0x0c6c00: F90013F7  str      x23, [sp, #0x20]
//   0x0c6c04: A90357F6  stp      x22, x21, [sp, #0x30]
//   0x0c6c08: A9044FF4  stp      x20, x19, [sp, #0x40]
static inline uint64_t fde_func_1329_0x0c6bfc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0c6bfcULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xf90013f7ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x00f8ULL;
    return acc;
}

// Func #1330 | PC: 0x0c6cf4 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #1330 | Địa chỉ PC: 0x0c6cf4 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0c6cf4: D100C3FF  sub      sp, sp, #0x30
//   0x0c6cf8: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0c6cfc: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0c6d00: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1330_0x0c6cf4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0c6cf4ULL ^ (static_cast<uint64_t>(0xd100c3ffULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #1331 | PC: 0x0c703c | FDE: 0x148a38 | Size: 128 bytes
// Hàm #1331 | Địa chỉ PC: 0x0c703c | Địa chỉ FDE: 0x148a38 | Kích thước: 128 bytes
//   0x0c703c: D10243FF  sub      sp, sp, #0x90
//   0x0c7040: A9074FF4  stp      x20, x19, [sp, #0x70]
//   0x0c7044: A9087BFD  stp      x29, x30, [sp, #0x80]
//   0x0c7048: 910203FD  add      x29, sp, #0x80
static inline uint64_t fde_func_1331_0x0c703c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0c703cULL ^ (static_cast<uint64_t>(0xd10243ffULL) << 13);
    acc = (acc + a1 + 0xa9074ff4ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0080ULL;
    return acc;
}

// Func #1332 | PC: 0x0c70bc | FDE: 0x148a38 | Size: 256 bytes
// Hàm #1332 | Địa chỉ PC: 0x0c70bc | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0c70bc: D103C3FF  sub      sp, sp, #0xf0
//   0x0c70c0: F9004BFB  str      x27, [sp, #0x90]
//   0x0c70c4: A90A67FA  stp      x26, x25, [sp, #0xa0]
//   0x0c70c8: A90B5FF8  stp      x24, x23, [sp, #0xb0]
static inline uint64_t fde_func_1332_0x0c70bc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0c70bcULL ^ (static_cast<uint64_t>(0xd103c3ffULL) << 13);
    acc = (acc + a1 + 0xf9004bfbULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #1333 | PC: 0x0c7300 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #1333 | Địa chỉ PC: 0x0c7300 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0c7300: D10383FF  sub      sp, sp, #0xe0
//   0x0c7304: F90053F7  str      x23, [sp, #0xa0]
//   0x0c7308: A90B57F6  stp      x22, x21, [sp, #0xb0]
//   0x0c730c: A90C4FF4  stp      x20, x19, [sp, #0xc0]
static inline uint64_t fde_func_1333_0x0c7300(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0c7300ULL ^ (static_cast<uint64_t>(0xd10383ffULL) << 13);
    acc = (acc + a1 + 0xf90053f7ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #1334 | PC: 0x0c74a8 | FDE: 0x148a38 | Size: 52 bytes
// Hàm #1334 | Địa chỉ PC: 0x0c74a8 | Địa chỉ FDE: 0x148a38 | Kích thước: 52 bytes
//   0x0c74a8: D10083FF  sub      sp, sp, #0x20
//   0x0c74ac: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0c74b0: 910043FD  add      x29, sp, #0x10
//   0x0c74b4: AA0103E2  mov      x2, x1
static inline uint64_t fde_func_1334_0x0c74a8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0c74a8ULL ^ (static_cast<uint64_t>(0xd10083ffULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0034ULL;
    return acc;
}

// Func #1335 | PC: 0x0c74dc | FDE: 0x148a38 | Size: 52 bytes
// Hàm #1335 | Địa chỉ PC: 0x0c74dc | Địa chỉ FDE: 0x148a38 | Kích thước: 52 bytes
//   0x0c74dc: D10083FF  sub      sp, sp, #0x20
//   0x0c74e0: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0c74e4: 910043FD  add      x29, sp, #0x10
//   0x0c74e8: AA0103E2  mov      x2, x1
static inline uint64_t fde_func_1335_0x0c74dc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0c74dcULL ^ (static_cast<uint64_t>(0xd10083ffULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0034ULL;
    return acc;
}

// Func #1336 | PC: 0x0c7510 | FDE: 0x148a38 | Size: 256 bytes [_ZN3com2ss5ttmio21MDLIOManagerImplement17getInfoInt64ValueENS1_16MDLIoTaskInfoKeyEPKcl]
// Hàm #1336 | Địa chỉ PC: 0x0c7510 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0c7510: F9401C00  ldr      x0, [x0, #0x38]
//   0x0c7514: B40002C0  cbz      x0, #0xc756c
//   0x0c7518: 510FA428  sub      w8, w1, #0x3e9
//   0x0c751c: 7100211F  cmp      w8, #8
static inline uint64_t fde_func_1336_0x0c7510(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0c7510ULL ^ (static_cast<uint64_t>(0xf9401c00ULL) << 13);
    acc = (acc + a1 + 0xb40002c0ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #1337 | PC: 0x0c7654 | FDE: 0x148a38 | Size: 136 bytes
// Hàm #1337 | Địa chỉ PC: 0x0c7654 | Địa chỉ FDE: 0x148a38 | Kích thước: 136 bytes
//   0x0c7654: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0c7658: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0c765c: 910043FD  add      x29, sp, #0x10
//   0x0c7660: AA0103F3  mov      x19, x1
static inline uint64_t fde_func_1337_0x0c7654(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0c7654ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0088ULL;
    return acc;
}

// Func #1338 | PC: 0x0c76dc | FDE: 0x148a38 | Size: 256 bytes
// Hàm #1338 | Địa chỉ PC: 0x0c76dc | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0c76dc: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0c76e0: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0c76e4: 910043FD  add      x29, sp, #0x10
//   0x0c76e8: AA0103F3  mov      x19, x1
static inline uint64_t fde_func_1338_0x0c76dc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0c76dcULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #1339 | PC: 0x0c77e0 | FDE: 0x148a38 | Size: 152 bytes
// Hàm #1339 | Địa chỉ PC: 0x0c77e0 | Địa chỉ FDE: 0x148a38 | Kích thước: 152 bytes
//   0x0c77e0: D10103FF  sub      sp, sp, #0x40
//   0x0c77e4: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x0c77e8: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x0c77ec: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_1339_0x0c77e0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0c77e0ULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0098ULL;
    return acc;
}

// Func #1340 | PC: 0x0c7878 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #1340 | Địa chỉ PC: 0x0c7878 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0c7878: A9BA6FFC  stp      x28, x27, [sp, #-0x60]!
//   0x0c787c: A90167FA  stp      x26, x25, [sp, #0x10]
//   0x0c7880: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x0c7884: A90357F6  stp      x22, x21, [sp, #0x30]
static inline uint64_t fde_func_1340_0x0c7878(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0c7878ULL ^ (static_cast<uint64_t>(0xa9ba6ffcULL) << 13);
    acc = (acc + a1 + 0xa90167faULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #1341 | PC: 0x0c7b24 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #1341 | Địa chỉ PC: 0x0c7b24 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0c7b24: A9BC5FF8  stp      x24, x23, [sp, #-0x40]!
//   0x0c7b28: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x0c7b2c: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x0c7b30: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_1341_0x0c7b24(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0c7b24ULL ^ (static_cast<uint64_t>(0xa9bc5ff8ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #1342 | PC: 0x0c7cfc | FDE: 0x148a38 | Size: 256 bytes
// Hàm #1342 | Địa chỉ PC: 0x0c7cfc | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0c7cfc: D10103FF  sub      sp, sp, #0x40
//   0x0c7d00: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x0c7d04: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x0c7d08: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_1342_0x0c7cfc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0c7cfcULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #1343 | PC: 0x0c7e88 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #1343 | Địa chỉ PC: 0x0c7e88 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0c7e88: A9BA6FFC  stp      x28, x27, [sp, #-0x60]!
//   0x0c7e8c: A90167FA  stp      x26, x25, [sp, #0x10]
//   0x0c7e90: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x0c7e94: A90357F6  stp      x22, x21, [sp, #0x30]
static inline uint64_t fde_func_1343_0x0c7e88(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0c7e88ULL ^ (static_cast<uint64_t>(0xa9ba6ffcULL) << 13);
    acc = (acc + a1 + 0xa90167faULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #1344 | PC: 0x0c7ff0 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #1344 | Địa chỉ PC: 0x0c7ff0 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0c7ff0: A9BC5FF8  stp      x24, x23, [sp, #-0x40]!
//   0x0c7ff4: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x0c7ff8: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x0c7ffc: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_1344_0x0c7ff0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0c7ff0ULL ^ (static_cast<uint64_t>(0xa9bc5ff8ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #1345 | PC: 0x0c8248 | FDE: 0x148a38 | Size: 220 bytes
// Hàm #1345 | Địa chỉ PC: 0x0c8248 | Địa chỉ FDE: 0x148a38 | Kích thước: 220 bytes
//   0x0c8248: D10103FF  sub      sp, sp, #0x40
//   0x0c824c: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x0c8250: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x0c8254: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_1345_0x0c8248(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0c8248ULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x00dcULL;
    return acc;
}

// Func #1346 | PC: 0x0c8324 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #1346 | Địa chỉ PC: 0x0c8324 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0c8324: D10143FF  sub      sp, sp, #0x50
//   0x0c8328: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x0c832c: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x0c8330: A9047BFD  stp      x29, x30, [sp, #0x40]
static inline uint64_t fde_func_1346_0x0c8324(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0c8324ULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xa90257f6ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #1347 | PC: 0x0c860c | FDE: 0x148a38 | Size: 256 bytes
// Hàm #1347 | Địa chỉ PC: 0x0c860c | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0c860c: D101C3FF  sub      sp, sp, #0x70
//   0x0c8610: A90457F6  stp      x22, x21, [sp, #0x40]
//   0x0c8614: A9054FF4  stp      x20, x19, [sp, #0x50]
//   0x0c8618: A9067BFD  stp      x29, x30, [sp, #0x60]
static inline uint64_t fde_func_1347_0x0c860c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0c860cULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xa90457f6ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #1348 | PC: 0x0c8998 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #1348 | Địa chỉ PC: 0x0c8998 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0c8998: D10143FF  sub      sp, sp, #0x50
//   0x0c899c: F90013F5  str      x21, [sp, #0x20]
//   0x0c89a0: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x0c89a4: A9047BFD  stp      x29, x30, [sp, #0x40]
static inline uint64_t fde_func_1348_0x0c8998(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0c8998ULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xf90013f5ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #1349 | PC: 0x0c8cc0 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #1349 | Địa chỉ PC: 0x0c8cc0 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0c8cc0: D10303FF  sub      sp, sp, #0xc0
//   0x0c8cc4: A90767FA  stp      x26, x25, [sp, #0x70]
//   0x0c8cc8: A9085FF8  stp      x24, x23, [sp, #0x80]
//   0x0c8ccc: A90957F6  stp      x22, x21, [sp, #0x90]
static inline uint64_t fde_func_1349_0x0c8cc0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0c8cc0ULL ^ (static_cast<uint64_t>(0xd10303ffULL) << 13);
    acc = (acc + a1 + 0xa90767faULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #1350 | PC: 0x0c9068 | FDE: 0x148a38 | Size: 232 bytes
// Hàm #1350 | Địa chỉ PC: 0x0c9068 | Địa chỉ FDE: 0x148a38 | Kích thước: 232 bytes
//   0x0c9068: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x0c906c: 910003FD  mov      x29, sp
//   0x0c9070: F9407C00  ldr      x0, [x0, #0xf8]
//   0x0c9074: B4000040  cbz      x0, #0xc907c
static inline uint64_t fde_func_1350_0x0c9068(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0c9068ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x00e8ULL;
    return acc;
}

// Func #1351 | PC: 0x0c9150 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #1351 | Địa chỉ PC: 0x0c9150 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0c9150: D10203FF  sub      sp, sp, #0x80
//   0x0c9154: F90023F7  str      x23, [sp, #0x40]
//   0x0c9158: A90557F6  stp      x22, x21, [sp, #0x50]
//   0x0c915c: A9064FF4  stp      x20, x19, [sp, #0x60]
static inline uint64_t fde_func_1351_0x0c9150(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0c9150ULL ^ (static_cast<uint64_t>(0xd10203ffULL) << 13);
    acc = (acc + a1 + 0xf90023f7ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #1352 | PC: 0x0c9490 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #1352 | Địa chỉ PC: 0x0c9490 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0c9490: D10483FF  sub      sp, sp, #0x120
//   0x0c9494: A90D67FC  stp      x28, x25, [sp, #0xd0]
//   0x0c9498: A90E5FF8  stp      x24, x23, [sp, #0xe0]
//   0x0c949c: A90F57F6  stp      x22, x21, [sp, #0xf0]
static inline uint64_t fde_func_1352_0x0c9490(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0c9490ULL ^ (static_cast<uint64_t>(0xd10483ffULL) << 13);
    acc = (acc + a1 + 0xa90d67fcULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #1353 | PC: 0x0c9700 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #1353 | Địa chỉ PC: 0x0c9700 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0c9700: D10403FF  sub      sp, sp, #0x100
//   0x0c9704: A90C5FF8  stp      x24, x23, [sp, #0xc0]
//   0x0c9708: A90D57F6  stp      x22, x21, [sp, #0xd0]
//   0x0c970c: A90E4FF4  stp      x20, x19, [sp, #0xe0]
static inline uint64_t fde_func_1353_0x0c9700(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0c9700ULL ^ (static_cast<uint64_t>(0xd10403ffULL) << 13);
    acc = (acc + a1 + 0xa90c5ff8ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #1354 | PC: 0x0c9a58 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #1354 | Địa chỉ PC: 0x0c9a58 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0c9a58: D10243FF  sub      sp, sp, #0x90
//   0x0c9a5c: A9055FF8  stp      x24, x23, [sp, #0x50]
//   0x0c9a60: A90657F6  stp      x22, x21, [sp, #0x60]
//   0x0c9a64: A9074FF4  stp      x20, x19, [sp, #0x70]
static inline uint64_t fde_func_1354_0x0c9a58(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0c9a58ULL ^ (static_cast<uint64_t>(0xd10243ffULL) << 13);
    acc = (acc + a1 + 0xa9055ff8ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #1355 | PC: 0x0c9e04 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #1355 | Địa chỉ PC: 0x0c9e04 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0c9e04: A9BA6FFC  stp      x28, x27, [sp, #-0x60]!
//   0x0c9e08: A90167FA  stp      x26, x25, [sp, #0x10]
//   0x0c9e0c: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x0c9e10: A90357F6  stp      x22, x21, [sp, #0x30]
static inline uint64_t fde_func_1355_0x0c9e04(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0c9e04ULL ^ (static_cast<uint64_t>(0xa9ba6ffcULL) << 13);
    acc = (acc + a1 + 0xa90167faULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #1356 | PC: 0x0c9f90 | FDE: 0x148a38 | Size: 28 bytes
// Hàm #1356 | Địa chỉ PC: 0x0c9f90 | Địa chỉ FDE: 0x148a38 | Kích thước: 28 bytes
//   0x0c9f90: A9BA6FFC  stp      x28, x27, [sp, #-0x60]!
//   0x0c9f94: A90167FA  stp      x26, x25, [sp, #0x10]
//   0x0c9f98: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x0c9f9c: A90357F6  stp      x22, x21, [sp, #0x30]
static inline uint64_t fde_func_1356_0x0c9f90(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0c9f90ULL ^ (static_cast<uint64_t>(0xa9ba6ffcULL) << 13);
    acc = (acc + a1 + 0xa90167faULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x001cULL;
    return acc;
}

// Func #1357 | PC: 0x0c9fac | FDE: 0x148a38 | Size: 256 bytes
// Hàm #1357 | Địa chỉ PC: 0x0c9fac | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0c9fac: D10903FF  sub      sp, sp, #0x240
//   0x0c9fb0: F9401008  ldr      x8, [x0, #0x20]
//   0x0c9fb4: 92F0000A  mov      x10, #0x7fffffffffffffff
//   0x0c9fb8: AA0103F3  mov      x19, x1
static inline uint64_t fde_func_1357_0x0c9fac(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0c9facULL ^ (static_cast<uint64_t>(0xd10903ffULL) << 13);
    acc = (acc + a1 + 0xf9401008ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #1358 | PC: 0x0cb360 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #1358 | Địa chỉ PC: 0x0cb360 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0cb360: D10283FF  sub      sp, sp, #0xa0
//   0x0cb364: F9002BF9  str      x25, [sp, #0x50]
//   0x0cb368: A9065FF8  stp      x24, x23, [sp, #0x60]
//   0x0cb36c: A90757F6  stp      x22, x21, [sp, #0x70]
static inline uint64_t fde_func_1358_0x0cb360(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0cb360ULL ^ (static_cast<uint64_t>(0xd10283ffULL) << 13);
    acc = (acc + a1 + 0xf9002bf9ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #1359 | PC: 0x0cb6f4 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #1359 | Địa chỉ PC: 0x0cb6f4 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0cb6f4: D10143FF  sub      sp, sp, #0x50
//   0x0cb6f8: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x0cb6fc: A9047BFD  stp      x29, x30, [sp, #0x40]
//   0x0cb700: 910103FD  add      x29, sp, #0x40
static inline uint64_t fde_func_1359_0x0cb6f4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0cb6f4ULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xa9034ff4ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #1360 | PC: 0x0cb8fc | FDE: 0x148a38 | Size: 112 bytes [_ZN3com2ss5ttmio16MDLObjectPcIoReqC1ENSt6__ndk110shared_ptrINS1_12MDLP2PLoaderEEENS4_INS1_8MDLIoReqEEEPNS1_21MDLIoTaskEventHandlerEbRKNS3_12basic_stringIcNS3_11char_traitsIcEENS3_9allocatorIcEEEESI_]
// Hàm #1360 | Địa chỉ PC: 0x0cb8fc | Địa chỉ FDE: 0x148a38 | Kích thước: 112 bytes
//   0x0cb8fc: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0cb900: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0cb904: 910043FD  add      x29, sp, #0x10
//   0x0cb908: 52807D28  mov      w8, #0x3e9
static inline uint64_t fde_func_1360_0x0cb8fc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0cb8fcULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0070ULL;
    return acc;
}

// Func #1361 | PC: 0x0cb96c | FDE: 0x148a38 | Size: 248 bytes [_ZN3com2ss5ttmio16MDLObjectPcIoReqC1ERKS2_]
// Hàm #1361 | Địa chỉ PC: 0x0cb96c | Địa chỉ FDE: 0x148a38 | Kích thước: 248 bytes
//   0x0cb96c: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0cb970: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0cb974: 910043FD  add      x29, sp, #0x10
//   0x0cb978: A941242A  ldp      x10, x9, [x1, #0x10]
static inline uint64_t fde_func_1361_0x0cb96c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0cb96cULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x00f8ULL;
    return acc;
}

// Func #1362 | PC: 0x0cba64 | FDE: 0x148a38 | Size: 256 bytes [_ZN3com2ss5ttmio16MDLObjectPcIoReqaSERKS2_]
// Hàm #1362 | Địa chỉ PC: 0x0cba64 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0cba64: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x0cba68: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0cba6c: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0cba70: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1362_0x0cba64(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0cba64ULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #1363 | PC: 0x0cbb68 | FDE: 0x148a38 | Size: 88 bytes [_ZN3com2ss5ttmio16MDLObjectPcIoReqD2Ev]
// Hàm #1363 | Địa chỉ PC: 0x0cbb68 | Địa chỉ FDE: 0x148a38 | Kích thước: 88 bytes
//   0x0cbb68: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x0cbb6c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0cbb70: 910043FD  add      x29, sp, #0x10
//   0x0cbb74: 90000489  adrp     x9, #0x15b000
static inline uint64_t fde_func_1363_0x0cbb68(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0cbb68ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0058ULL;
    return acc;
}

// Func #1364 | PC: 0x0cbbc0 | FDE: 0x148a38 | Size: 36 bytes [_ZN3com2ss5ttmio16MDLObjectPcIoReqD0Ev]
// Hàm #1364 | Địa chỉ PC: 0x0cbbc0 | Địa chỉ FDE: 0x148a38 | Kích thước: 36 bytes
//   0x0cbbc0: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x0cbbc4: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0cbbc8: 910043FD  add      x29, sp, #0x10
//   0x0cbbcc: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_1364_0x0cbbc0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0cbbc0ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0024ULL;
    return acc;
}

// Func #1365 | PC: 0x0cbbe4 | FDE: 0x148a38 | Size: 52 bytes [_ZN3com2ss5ttmio16MDLObjectPcIoReq5cloneEv]
// Hàm #1365 | Địa chỉ PC: 0x0cbbe4 | Địa chỉ FDE: 0x148a38 | Kích thước: 52 bytes
//   0x0cbbe4: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0cbbe8: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0cbbec: 910043FD  add      x29, sp, #0x10
//   0x0cbbf0: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_1365_0x0cbbe4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0cbbe4ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0034ULL;
    return acc;
}

// Func #1366 | PC: 0x0cbc18 | FDE: 0x148a38 | Size: 44 bytes [_ZN3com2ss5ttmio16MDLObjectPcIoReq12getP2pLoaderEv]
// Hàm #1366 | Địa chỉ PC: 0x0cbc18 | Địa chỉ FDE: 0x148a38 | Kích thước: 44 bytes
//   0x0cbc18: F9400809  ldr      x9, [x0, #0x10]
//   0x0cbc1c: F9000109  str      x9, [x8]
//   0x0cbc20: F9400C09  ldr      x9, [x0, #0x18]
//   0x0cbc24: F9000509  str      x9, [x8, #8]
static inline uint64_t fde_func_1366_0x0cbc18(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0cbc18ULL ^ (static_cast<uint64_t>(0xf9400809ULL) << 13);
    acc = (acc + a1 + 0xf9000109ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x002cULL;
    return acc;
}

// Func #1367 | PC: 0x0cbc44 | FDE: 0x148a38 | Size: 44 bytes [_ZN3com2ss5ttmio16MDLObjectPcIoReq8getIoReqEv]
// Hàm #1367 | Địa chỉ PC: 0x0cbc44 | Địa chỉ FDE: 0x148a38 | Kích thước: 44 bytes
//   0x0cbc44: F9401009  ldr      x9, [x0, #0x20]
//   0x0cbc48: F9000109  str      x9, [x8]
//   0x0cbc4c: F9401409  ldr      x9, [x0, #0x28]
//   0x0cbc50: F9000509  str      x9, [x8, #8]
static inline uint64_t fde_func_1367_0x0cbc44(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0cbc44ULL ^ (static_cast<uint64_t>(0xf9401009ULL) << 13);
    acc = (acc + a1 + 0xf9000109ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x002cULL;
    return acc;
}

// Func #1368 | PC: 0x0cbc70 | FDE: 0x148a38 | Size: 8 bytes [_ZN3com2ss5ttmio16MDLObjectPcIoReq14getIoEvHandlerEv]
// Hàm #1368 | Địa chỉ PC: 0x0cbc70 | Địa chỉ FDE: 0x148a38 | Kích thước: 8 bytes
//   0x0cbc70: F9401800  ldr      x0, [x0, #0x30]
//   0x0cbc74: D65F03C0  ret      
static inline uint64_t fde_func_1368_0x0cbc70(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0cbc70ULL ^ (static_cast<uint64_t>(0xf9401800ULL) << 13);
    acc = (acc + a1 + 0xd65f03c0ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0008ULL;
    return acc;
}

// Func #1369 | PC: 0x0cbc78 | FDE: 0x148a38 | Size: 8 bytes [_ZN3com2ss5ttmio16MDLObjectPcIoReq9getN80UrlEv]
// Hàm #1369 | Địa chỉ PC: 0x0cbc78 | Địa chỉ FDE: 0x148a38 | Kích thước: 8 bytes
//   0x0cbc78: 91010000  add      x0, x0, #0x40
//   0x0cbc7c: D65F03C0  ret      
static inline uint64_t fde_func_1369_0x0cbc78(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0cbc78ULL ^ (static_cast<uint64_t>(0x91010000ULL) << 13);
    acc = (acc + a1 + 0xd65f03c0ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0008ULL;
    return acc;
}

// Func #1370 | PC: 0x0cbc80 | FDE: 0x148a38 | Size: 8 bytes [_ZN3com2ss5ttmio16MDLObjectPcIoReq8getIsN80Ev]
// Hàm #1370 | Địa chỉ PC: 0x0cbc80 | Địa chỉ FDE: 0x148a38 | Kích thước: 8 bytes
//   0x0cbc80: 3940E000  ldrb     w0, [x0, #0x38]
//   0x0cbc84: D65F03C0  ret      
static inline uint64_t fde_func_1370_0x0cbc80(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0cbc80ULL ^ (static_cast<uint64_t>(0x3940e000ULL) << 13);
    acc = (acc + a1 + 0xd65f03c0ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0008ULL;
    return acc;
}

// Func #1371 | PC: 0x0cbc88 | FDE: 0x148a38 | Size: 16 bytes [_ZN3com2ss5ttmio16MDLObjectPcIoReq10getN80HostEv]
// Hàm #1371 | Địa chỉ PC: 0x0cbc88 | Địa chỉ FDE: 0x148a38 | Kích thước: 16 bytes
//   0x0cbc88: 91016000  add      x0, x0, #0x58
//   0x0cbc8c: D65F03C0  ret      
//   0x0cbc90: B9400800  ldr      w0, [x0, #8]
//   0x0cbc94: D65F03C0  ret      
static inline uint64_t fde_func_1371_0x0cbc88(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0cbc88ULL ^ (static_cast<uint64_t>(0x91016000ULL) << 13);
    acc = (acc + a1 + 0xd65f03c0ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0010ULL;
    return acc;
}

// Func #1372 | PC: 0x0cbc98 | FDE: 0x148a38 | Size: 192 bytes [_ZN3com2ss5ttmio21MDLLinkQualityManager11getInstanceEv]
// Hàm #1372 | Địa chỉ PC: 0x0cbc98 | Địa chỉ FDE: 0x148a38 | Kích thước: 192 bytes
//   0x0cbc98: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x0cbc9c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0cbca0: 910043FD  add      x29, sp, #0x10
//   0x0cbca4: B0000493  adrp     x19, #0x15c000
static inline uint64_t fde_func_1372_0x0cbc98(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0cbc98ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x00c0ULL;
    return acc;
}

// Func #1373 | PC: 0x0cbd58 | FDE: 0x148a38 | Size: 36 bytes [_ZN3com2ss5ttmio21MDLLinkQualityManagerC2Ev]
// Hàm #1373 | Địa chỉ PC: 0x0cbd58 | Địa chỉ FDE: 0x148a38 | Kích thước: 36 bytes
//   0x0cbd58: AA0003E8  mov      x8, x0
//   0x0cbd5c: 6F00E400  movi     v0.2d, #0000000000000000
//   0x0cbd60: F8008D1F  str      xzr, [x8, #8]!
//   0x0cbd64: F900081F  str      xzr, [x0, #0x10]
static inline uint64_t fde_func_1373_0x0cbd58(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0cbd58ULL ^ (static_cast<uint64_t>(0xaa0003e8ULL) << 13);
    acc = (acc + a1 + 0x6f00e400ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0024ULL;
    return acc;
}

// Func #1374 | PC: 0x0cbd7c | FDE: 0x148a38 | Size: 44 bytes [_ZN3com2ss5ttmio21MDLLinkQualityManagerD2Ev]
// Hàm #1374 | Địa chỉ PC: 0x0cbd7c | Địa chỉ FDE: 0x148a38 | Kích thước: 44 bytes
//   0x0cbd7c: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x0cbd80: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0cbd84: 910043FD  add      x29, sp, #0x10
//   0x0cbd88: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_1374_0x0cbd7c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0cbd7cULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x002cULL;
    return acc;
}

// Func #1375 | PC: 0x0cbda8 | FDE: 0x148a38 | Size: 256 bytes [_ZN3com2ss5ttmio21MDLLinkQualityManager26onSampleByNetProtocolScoreEPNS1_24MDLLinkQualitySampleInfoE]
// Hàm #1375 | Địa chỉ PC: 0x0cbda8 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0cbda8: D10143FF  sub      sp, sp, #0x50
//   0x0cbdac: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x0cbdb0: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x0cbdb4: A9047BFD  stp      x29, x30, [sp, #0x40]
static inline uint64_t fde_func_1375_0x0cbda8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0cbda8ULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xa90257f6ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #1376 | PC: 0x0cbef0 | FDE: 0x148a38 | Size: 212 bytes [_ZN3com2ss5ttmio21MDLLinkQualityManager21getProtocolByQuicItemERNS1_12ReqProtoTypeES4_l]
// Hàm #1376 | Địa chỉ PC: 0x0cbef0 | Địa chỉ FDE: 0x148a38 | Kích thước: 212 bytes
//   0x0cbef0: D10143FF  sub      sp, sp, #0x50
//   0x0cbef4: F9000BF7  str      x23, [sp, #0x10]
//   0x0cbef8: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x0cbefc: A9034FF4  stp      x20, x19, [sp, #0x30]
static inline uint64_t fde_func_1376_0x0cbef0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0cbef0ULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xf9000bf7ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x00d4ULL;
    return acc;
}

// Func #1377 | PC: 0x0cbfc4 | FDE: 0x148a38 | Size: 212 bytes [_ZN3com2ss5ttmio21MDLLinkQualityManager22getLinkScoreByQuicItemElRlS3_Rb]
// Hàm #1377 | Địa chỉ PC: 0x0cbfc4 | Địa chỉ FDE: 0x148a38 | Kích thước: 212 bytes
//   0x0cbfc4: D10183FF  sub      sp, sp, #0x60
//   0x0cbfc8: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x0cbfcc: A90357F6  stp      x22, x21, [sp, #0x30]
//   0x0cbfd0: A9044FF4  stp      x20, x19, [sp, #0x40]
static inline uint64_t fde_func_1377_0x0cbfc4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0cbfc4ULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xa9025ff8ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x00d4ULL;
    return acc;
}

// Func #1378 | PC: 0x0cc098 | FDE: 0x148a38 | Size: 156 bytes [_ZN3com2ss5ttmio21MDLLinkQualityManager5resetEv]
// Hàm #1378 | Địa chỉ PC: 0x0cc098 | Địa chỉ FDE: 0x148a38 | Kích thước: 156 bytes
//   0x0cc098: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x0cc09c: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0cc0a0: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0cc0a4: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1378_0x0cc098(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0cc098ULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x009cULL;
    return acc;
}

// Func #1379 | PC: 0x0cc134 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #1379 | Địa chỉ PC: 0x0cc134 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0cc134: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0cc138: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0cc13c: 910043FD  add      x29, sp, #0x10
//   0x0cc140: AA0103F3  mov      x19, x1
static inline uint64_t fde_func_1379_0x0cc134(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0cc134ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #1380 | PC: 0x0cc294 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #1380 | Địa chỉ PC: 0x0cc294 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0cc294: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0cc298: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0cc29c: 910043FD  add      x29, sp, #0x10
//   0x0cc2a0: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_1380_0x0cc294(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0cc294ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #1381 | PC: 0x0cc3e8 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #1381 | Địa chỉ PC: 0x0cc3e8 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0cc3e8: D10283FF  sub      sp, sp, #0xa0
//   0x0cc3ec: F90023FB  str      x27, [sp, #0x40]
//   0x0cc3f0: A90567FA  stp      x26, x25, [sp, #0x50]
//   0x0cc3f4: A9065FF8  stp      x24, x23, [sp, #0x60]
static inline uint64_t fde_func_1381_0x0cc3e8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0cc3e8ULL ^ (static_cast<uint64_t>(0xd10283ffULL) << 13);
    acc = (acc + a1 + 0xf90023fbULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #1382 | PC: 0x0cc548 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #1382 | Địa chỉ PC: 0x0cc548 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0cc548: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0cc54c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0cc550: 910043FD  add      x29, sp, #0x10
//   0x0cc554: F0000468  adrp     x8, #0x15b000
static inline uint64_t fde_func_1382_0x0cc548(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0cc548ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #1383 | PC: 0x0cc6a4 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #1383 | Địa chỉ PC: 0x0cc6a4 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0cc6a4: D10283FF  sub      sp, sp, #0xa0
//   0x0cc6a8: F90023FB  str      x27, [sp, #0x40]
//   0x0cc6ac: A90567FA  stp      x26, x25, [sp, #0x50]
//   0x0cc6b0: A9065FF8  stp      x24, x23, [sp, #0x60]
static inline uint64_t fde_func_1383_0x0cc6a4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0cc6a4ULL ^ (static_cast<uint64_t>(0xd10283ffULL) << 13);
    acc = (acc + a1 + 0xf90023fbULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #1384 | PC: 0x0cc930 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #1384 | Địa chỉ PC: 0x0cc930 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0cc930: D10403FF  sub      sp, sp, #0x100
//   0x0cc934: A90A6FFC  stp      x28, x27, [sp, #0xa0]
//   0x0cc938: A90B67FA  stp      x26, x25, [sp, #0xb0]
//   0x0cc93c: A90C5FF8  stp      x24, x23, [sp, #0xc0]
static inline uint64_t fde_func_1384_0x0cc930(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0cc930ULL ^ (static_cast<uint64_t>(0xd10403ffULL) << 13);
    acc = (acc + a1 + 0xa90a6ffcULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #1385 | PC: 0x0cd6a0 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #1385 | Địa chỉ PC: 0x0cd6a0 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0cd6a0: D10403FF  sub      sp, sp, #0x100
//   0x0cd6a4: A90A6FFC  stp      x28, x27, [sp, #0xa0]
//   0x0cd6a8: A90B67FA  stp      x26, x25, [sp, #0xb0]
//   0x0cd6ac: A90C5FF8  stp      x24, x23, [sp, #0xc0]
static inline uint64_t fde_func_1385_0x0cd6a0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0cd6a0ULL ^ (static_cast<uint64_t>(0xd10403ffULL) << 13);
    acc = (acc + a1 + 0xa90a6ffcULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #1386 | PC: 0x0ce520 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #1386 | Địa chỉ PC: 0x0ce520 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0ce520: D101C3FF  sub      sp, sp, #0x70
//   0x0ce524: A90267FA  stp      x26, x25, [sp, #0x20]
//   0x0ce528: A9035FF8  stp      x24, x23, [sp, #0x30]
//   0x0ce52c: A90457F6  stp      x22, x21, [sp, #0x40]
static inline uint64_t fde_func_1386_0x0ce520(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ce520ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xa90267faULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #1387 | PC: 0x0ce84c | FDE: 0x148a38 | Size: 256 bytes
// Hàm #1387 | Địa chỉ PC: 0x0ce84c | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0ce84c: D10403FF  sub      sp, sp, #0x100
//   0x0ce850: A90A6FFC  stp      x28, x27, [sp, #0xa0]
//   0x0ce854: A90B67FA  stp      x26, x25, [sp, #0xb0]
//   0x0ce858: A90C5FF8  stp      x24, x23, [sp, #0xc0]
static inline uint64_t fde_func_1387_0x0ce84c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ce84cULL ^ (static_cast<uint64_t>(0xd10403ffULL) << 13);
    acc = (acc + a1 + 0xa90a6ffcULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #1388 | PC: 0x0cf514 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #1388 | Địa chỉ PC: 0x0cf514 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0cf514: D10403FF  sub      sp, sp, #0x100
//   0x0cf518: A90A6FFC  stp      x28, x27, [sp, #0xa0]
//   0x0cf51c: A90B67FA  stp      x26, x25, [sp, #0xb0]
//   0x0cf520: A90C5FF8  stp      x24, x23, [sp, #0xc0]
static inline uint64_t fde_func_1388_0x0cf514(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0cf514ULL ^ (static_cast<uint64_t>(0xd10403ffULL) << 13);
    acc = (acc + a1 + 0xa90a6ffcULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #1389 | PC: 0x0cfd08 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #1389 | Địa chỉ PC: 0x0cfd08 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0cfd08: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0cfd0c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0cfd10: 910043FD  add      x29, sp, #0x10
//   0x0cfd14: B4000981  cbz      x1, #0xcfe44
static inline uint64_t fde_func_1389_0x0cfd08(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0cfd08ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #1390 | PC: 0x0cfe50 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #1390 | Địa chỉ PC: 0x0cfe50 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0cfe50: D10183FF  sub      sp, sp, #0x60
//   0x0cfe54: A90167FA  stp      x26, x25, [sp, #0x10]
//   0x0cfe58: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x0cfe5c: A90357F6  stp      x22, x21, [sp, #0x30]
static inline uint64_t fde_func_1390_0x0cfe50(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0cfe50ULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xa90167faULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #1391 | PC: 0x0cfff0 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #1391 | Địa chỉ PC: 0x0cfff0 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0cfff0: D10143FF  sub      sp, sp, #0x50
//   0x0cfff4: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x0cfff8: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x0cfffc: A9047BFD  stp      x29, x30, [sp, #0x40]
static inline uint64_t fde_func_1391_0x0cfff0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0cfff0ULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xa90257f6ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #1392 | PC: 0x0d01d8 | FDE: 0x148a38 | Size: 212 bytes
// Hàm #1392 | Địa chỉ PC: 0x0d01d8 | Địa chỉ FDE: 0x148a38 | Kích thước: 212 bytes
//   0x0d01d8: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x0d01dc: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0d01e0: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0d01e4: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1392_0x0d01d8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d01d8ULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x00d4ULL;
    return acc;
}

// Func #1393 | PC: 0x0d02ac | FDE: 0x148a38 | Size: 256 bytes
// Hàm #1393 | Địa chỉ PC: 0x0d02ac | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0d02ac: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0d02b0: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0d02b4: 910043FD  add      x29, sp, #0x10
//   0x0d02b8: B9402408  ldr      w8, [x0, #0x24]
static inline uint64_t fde_func_1393_0x0d02ac(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d02acULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #1394 | PC: 0x0d0400 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #1394 | Địa chỉ PC: 0x0d0400 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0d0400: A9BB67FA  stp      x26, x25, [sp, #-0x50]!
//   0x0d0404: A9015FF8  stp      x24, x23, [sp, #0x10]
//   0x0d0408: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x0d040c: A9034FF4  stp      x20, x19, [sp, #0x30]
static inline uint64_t fde_func_1394_0x0d0400(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d0400ULL ^ (static_cast<uint64_t>(0xa9bb67faULL) << 13);
    acc = (acc + a1 + 0xa9015ff8ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #1395 | PC: 0x0d068c | FDE: 0x148a38 | Size: 28 bytes
// Hàm #1395 | Địa chỉ PC: 0x0d068c | Địa chỉ FDE: 0x148a38 | Kích thước: 28 bytes
//   0x0d068c: A9BA6FFC  stp      x28, x27, [sp, #-0x60]!
//   0x0d0690: A90167FA  stp      x26, x25, [sp, #0x10]
//   0x0d0694: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x0d0698: A90357F6  stp      x22, x21, [sp, #0x30]
static inline uint64_t fde_func_1395_0x0d068c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d068cULL ^ (static_cast<uint64_t>(0xa9ba6ffcULL) << 13);
    acc = (acc + a1 + 0xa90167faULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x001cULL;
    return acc;
}

// Func #1396 | PC: 0x0d06a8 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #1396 | Địa chỉ PC: 0x0d06a8 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0d06a8: D11103FF  sub      sp, sp, #0x440
//   0x0d06ac: D53BD05B  mrs      x27, tpidr_el0
//   0x0d06b0: F9401768  ldr      x8, [x27, #0x28]
//   0x0d06b4: AA0203F6  mov      x22, x2
static inline uint64_t fde_func_1396_0x0d06a8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d06a8ULL ^ (static_cast<uint64_t>(0xd11103ffULL) << 13);
    acc = (acc + a1 + 0xd53bd05bULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #1397 | PC: 0x0d09c0 | FDE: 0x148a38 | Size: 24 bytes
// Hàm #1397 | Địa chỉ PC: 0x0d09c0 | Địa chỉ FDE: 0x148a38 | Kích thước: 24 bytes
//   0x0d09c0: A9BB67FC  stp      x28, x25, [sp, #-0x50]!
//   0x0d09c4: A9015FF8  stp      x24, x23, [sp, #0x10]
//   0x0d09c8: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x0d09cc: A9034FF4  stp      x20, x19, [sp, #0x30]
static inline uint64_t fde_func_1397_0x0d09c0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d09c0ULL ^ (static_cast<uint64_t>(0xa9bb67fcULL) << 13);
    acc = (acc + a1 + 0xa9015ff8ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0018ULL;
    return acc;
}

// Func #1398 | PC: 0x0d09d8 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #1398 | Địa chỉ PC: 0x0d09d8 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0d09d8: D11043FF  sub      sp, sp, #0x410
//   0x0d09dc: D53BD059  mrs      x25, tpidr_el0
//   0x0d09e0: F9401728  ldr      x8, [x25, #0x28]
//   0x0d09e4: F81B83A8  stur     x8, [x29, #-0x48]
static inline uint64_t fde_func_1398_0x0d09d8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d09d8ULL ^ (static_cast<uint64_t>(0xd11043ffULL) << 13);
    acc = (acc + a1 + 0xd53bd059ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #1399 | PC: 0x0d0b10 | FDE: 0x148a38 | Size: 156 bytes
// Hàm #1399 | Địa chỉ PC: 0x0d0b10 | Địa chỉ FDE: 0x148a38 | Kích thước: 156 bytes
//   0x0d0b10: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0d0b14: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0d0b18: 910043FD  add      x29, sp, #0x10
//   0x0d0b1c: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_1399_0x0d0b10(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d0b10ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x009cULL;
    return acc;
}

// Func #1400 | PC: 0x0d0bac | FDE: 0x148a38 | Size: 28 bytes
// Hàm #1400 | Địa chỉ PC: 0x0d0bac | Địa chỉ FDE: 0x148a38 | Kích thước: 28 bytes
//   0x0d0bac: A9BA6FFC  stp      x28, x27, [sp, #-0x60]!
//   0x0d0bb0: A90167FA  stp      x26, x25, [sp, #0x10]
//   0x0d0bb4: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x0d0bb8: A90357F6  stp      x22, x21, [sp, #0x30]
static inline uint64_t fde_func_1400_0x0d0bac(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d0bacULL ^ (static_cast<uint64_t>(0xa9ba6ffcULL) << 13);
    acc = (acc + a1 + 0xa90167faULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x001cULL;
    return acc;
}

// Func #1401 | PC: 0x0d0bc8 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #1401 | Địa chỉ PC: 0x0d0bc8 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0d0bc8: D110C3FF  sub      sp, sp, #0x430
//   0x0d0bcc: D53BD05A  mrs      x26, tpidr_el0
//   0x0d0bd0: F9401748  ldr      x8, [x26, #0x28]
//   0x0d0bd4: F81A03A8  stur     x8, [x29, #-0x60]
static inline uint64_t fde_func_1401_0x0d0bc8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d0bc8ULL ^ (static_cast<uint64_t>(0xd110c3ffULL) << 13);
    acc = (acc + a1 + 0xd53bd05aULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #1402 | PC: 0x0d0db0 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #1402 | Địa chỉ PC: 0x0d0db0 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0d0db0: D10383FF  sub      sp, sp, #0xe0
//   0x0d0db4: A9086FFC  stp      x28, x27, [sp, #0x80]
//   0x0d0db8: A90967FA  stp      x26, x25, [sp, #0x90]
//   0x0d0dbc: A90A5FF8  stp      x24, x23, [sp, #0xa0]
static inline uint64_t fde_func_1402_0x0d0db0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d0db0ULL ^ (static_cast<uint64_t>(0xd10383ffULL) << 13);
    acc = (acc + a1 + 0xa9086ffcULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #1403 | PC: 0x0d10d4 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #1403 | Địa chỉ PC: 0x0d10d4 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0d10d4: D10243FF  sub      sp, sp, #0x90
//   0x0d10d8: A9036FFC  stp      x28, x27, [sp, #0x30]
//   0x0d10dc: A90467FA  stp      x26, x25, [sp, #0x40]
//   0x0d10e0: A9055FF8  stp      x24, x23, [sp, #0x50]
static inline uint64_t fde_func_1403_0x0d10d4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d10d4ULL ^ (static_cast<uint64_t>(0xd10243ffULL) << 13);
    acc = (acc + a1 + 0xa9036ffcULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #1404 | PC: 0x0d155c | FDE: 0x148a38 | Size: 28 bytes
// Hàm #1404 | Địa chỉ PC: 0x0d155c | Địa chỉ FDE: 0x148a38 | Kích thước: 28 bytes
//   0x0d155c: A9BA6FFC  stp      x28, x27, [sp, #-0x60]!
//   0x0d1560: A90167FA  stp      x26, x25, [sp, #0x10]
//   0x0d1564: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x0d1568: A90357F6  stp      x22, x21, [sp, #0x30]
static inline uint64_t fde_func_1404_0x0d155c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d155cULL ^ (static_cast<uint64_t>(0xa9ba6ffcULL) << 13);
    acc = (acc + a1 + 0xa90167faULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x001cULL;
    return acc;
}

// Func #1405 | PC: 0x0d1578 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #1405 | Địa chỉ PC: 0x0d1578 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0d1578: D11143FF  sub      sp, sp, #0x450
//   0x0d157c: D53BD05A  mrs      x26, tpidr_el0
//   0x0d1580: F9401748  ldr      x8, [x26, #0x28]
//   0x0d1584: 52927C09  mov      w9, #0x93e0
static inline uint64_t fde_func_1405_0x0d1578(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d1578ULL ^ (static_cast<uint64_t>(0xd11143ffULL) << 13);
    acc = (acc + a1 + 0xd53bd05aULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #1406 | PC: 0x0d17e4 | FDE: 0x148a38 | Size: 208 bytes
// Hàm #1406 | Địa chỉ PC: 0x0d17e4 | Địa chỉ FDE: 0x148a38 | Kích thước: 208 bytes
//   0x0d17e4: D10183FF  sub      sp, sp, #0x60
//   0x0d17e8: A902D7FF  stp      xzr, x21, [sp, #0x28]
//   0x0d17ec: A9044FF4  stp      x20, x19, [sp, #0x40]
//   0x0d17f0: A9057BFD  stp      x29, x30, [sp, #0x50]
static inline uint64_t fde_func_1406_0x0d17e4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d17e4ULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xa902d7ffULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x00d0ULL;
    return acc;
}

// Func #1407 | PC: 0x0d18b4 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #1407 | Địa chỉ PC: 0x0d18b4 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0d18b4: D10183FF  sub      sp, sp, #0x60
//   0x0d18b8: A902D7FF  stp      xzr, x21, [sp, #0x28]
//   0x0d18bc: A9044FF4  stp      x20, x19, [sp, #0x40]
//   0x0d18c0: A9057BFD  stp      x29, x30, [sp, #0x50]
static inline uint64_t fde_func_1407_0x0d18b4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d18b4ULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xa902d7ffULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #1408 | PC: 0x0d1a3c | FDE: 0x148a38 | Size: 256 bytes
// Hàm #1408 | Địa chỉ PC: 0x0d1a3c | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0d1a3c: D10143FF  sub      sp, sp, #0x50
//   0x0d1a40: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x0d1a44: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x0d1a48: A9047BFD  stp      x29, x30, [sp, #0x40]
static inline uint64_t fde_func_1408_0x0d1a3c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d1a3cULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xa90257f6ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #1409 | PC: 0x0d1c4c | FDE: 0x148a38 | Size: 156 bytes
// Hàm #1409 | Địa chỉ PC: 0x0d1c4c | Địa chỉ FDE: 0x148a38 | Kích thước: 156 bytes
//   0x0d1c4c: D10143FF  sub      sp, sp, #0x50
//   0x0d1c50: F90013F5  str      x21, [sp, #0x20]
//   0x0d1c54: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x0d1c58: A9047BFD  stp      x29, x30, [sp, #0x40]
static inline uint64_t fde_func_1409_0x0d1c4c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d1c4cULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xf90013f5ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x009cULL;
    return acc;
}

// Func #1410 | PC: 0x0d1ce8 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #1410 | Địa chỉ PC: 0x0d1ce8 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0d1ce8: D101C3FF  sub      sp, sp, #0x70
//   0x0d1cec: A903D7FF  stp      xzr, x21, [sp, #0x38]
//   0x0d1cf0: A9054FF4  stp      x20, x19, [sp, #0x50]
//   0x0d1cf4: A9067BFD  stp      x29, x30, [sp, #0x60]
static inline uint64_t fde_func_1410_0x0d1ce8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d1ce8ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xa903d7ffULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #1411 | PC: 0x0d1ffc | FDE: 0x148a38 | Size: 256 bytes
// Hàm #1411 | Địa chỉ PC: 0x0d1ffc | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0d1ffc: D101C3FF  sub      sp, sp, #0x70
//   0x0d2000: F90013F9  str      x25, [sp, #0x20]
//   0x0d2004: A9035FF8  stp      x24, x23, [sp, #0x30]
//   0x0d2008: A90457F6  stp      x22, x21, [sp, #0x40]
static inline uint64_t fde_func_1411_0x0d1ffc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d1ffcULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xf90013f9ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #1412 | PC: 0x0d21dc | FDE: 0x148a38 | Size: 256 bytes
// Hàm #1412 | Địa chỉ PC: 0x0d21dc | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0d21dc: D101C3FF  sub      sp, sp, #0x70
//   0x0d21e0: F9001BF7  str      x23, [sp, #0x30]
//   0x0d21e4: A90457F6  stp      x22, x21, [sp, #0x40]
//   0x0d21e8: A9054FF4  stp      x20, x19, [sp, #0x50]
static inline uint64_t fde_func_1412_0x0d21dc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d21dcULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xf9001bf7ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #1413 | PC: 0x0d2590 | FDE: 0x148a38 | Size: 192 bytes
// Hàm #1413 | Địa chỉ PC: 0x0d2590 | Địa chỉ FDE: 0x148a38 | Kích thước: 192 bytes
//   0x0d2590: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x0d2594: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0d2598: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0d259c: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1413_0x0d2590(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d2590ULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x00c0ULL;
    return acc;
}

// Func #1414 | PC: 0x0d2650 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #1414 | Địa chỉ PC: 0x0d2650 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0d2650: D10143FF  sub      sp, sp, #0x50
//   0x0d2654: F9000BF7  str      x23, [sp, #0x10]
//   0x0d2658: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x0d265c: A9034FF4  stp      x20, x19, [sp, #0x30]
static inline uint64_t fde_func_1414_0x0d2650(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d2650ULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xf9000bf7ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #1415 | PC: 0x0d27e8 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #1415 | Địa chỉ PC: 0x0d27e8 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0d27e8: D103C3FF  sub      sp, sp, #0xf0
//   0x0d27ec: A90A67FA  stp      x26, x25, [sp, #0xa0]
//   0x0d27f0: A90B5FF8  stp      x24, x23, [sp, #0xb0]
//   0x0d27f4: A90C57F6  stp      x22, x21, [sp, #0xc0]
static inline uint64_t fde_func_1415_0x0d27e8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d27e8ULL ^ (static_cast<uint64_t>(0xd103c3ffULL) << 13);
    acc = (acc + a1 + 0xa90a67faULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #1416 | PC: 0x0d29b4 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #1416 | Địa chỉ PC: 0x0d29b4 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0d29b4: D10143FF  sub      sp, sp, #0x50
//   0x0d29b8: F9000BF7  str      x23, [sp, #0x10]
//   0x0d29bc: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x0d29c0: A9034FF4  stp      x20, x19, [sp, #0x30]
static inline uint64_t fde_func_1416_0x0d29b4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d29b4ULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xf9000bf7ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #1417 | PC: 0x0d2c0c | FDE: 0x148a38 | Size: 256 bytes
// Hàm #1417 | Địa chỉ PC: 0x0d2c0c | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0d2c0c: D10103FF  sub      sp, sp, #0x40
//   0x0d2c10: F9000BF5  str      x21, [sp, #0x10]
//   0x0d2c14: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x0d2c18: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_1417_0x0d2c0c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d2c0cULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xf9000bf5ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #1418 | PC: 0x0d2d9c | FDE: 0x148a38 | Size: 256 bytes
// Hàm #1418 | Địa chỉ PC: 0x0d2d9c | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0d2d9c: D10143FF  sub      sp, sp, #0x50
//   0x0d2da0: F90013F5  str      x21, [sp, #0x20]
//   0x0d2da4: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x0d2da8: A9047BFD  stp      x29, x30, [sp, #0x40]
static inline uint64_t fde_func_1418_0x0d2d9c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d2d9cULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xf90013f5ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #1419 | PC: 0x0d2f54 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #1419 | Địa chỉ PC: 0x0d2f54 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0d2f54: D10203FF  sub      sp, sp, #0x80
//   0x0d2f58: F90023F7  str      x23, [sp, #0x40]
//   0x0d2f5c: A90557F6  stp      x22, x21, [sp, #0x50]
//   0x0d2f60: A9064FF4  stp      x20, x19, [sp, #0x60]
static inline uint64_t fde_func_1419_0x0d2f54(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d2f54ULL ^ (static_cast<uint64_t>(0xd10203ffULL) << 13);
    acc = (acc + a1 + 0xf90023f7ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #1420 | PC: 0x0d3200 | FDE: 0x148a38 | Size: 232 bytes
// Hàm #1420 | Địa chỉ PC: 0x0d3200 | Địa chỉ FDE: 0x148a38 | Kích thước: 232 bytes
//   0x0d3200: D10203FF  sub      sp, sp, #0x80
//   0x0d3204: F90023F7  str      x23, [sp, #0x40]
//   0x0d3208: A90557F6  stp      x22, x21, [sp, #0x50]
//   0x0d320c: A9064FF4  stp      x20, x19, [sp, #0x60]
static inline uint64_t fde_func_1420_0x0d3200(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d3200ULL ^ (static_cast<uint64_t>(0xd10203ffULL) << 13);
    acc = (acc + a1 + 0xf90023f7ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x00e8ULL;
    return acc;
}

// Func #1421 | PC: 0x0d32e8 | FDE: 0x148a38 | Size: 28 bytes
// Hàm #1421 | Địa chỉ PC: 0x0d32e8 | Địa chỉ FDE: 0x148a38 | Kích thước: 28 bytes
//   0x0d32e8: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x0d32ec: 910003FD  mov      x29, sp
//   0x0d32f0: D10D4000  sub      x0, x0, #0x350
//   0x0d32f4: 97FFFFC3  bl       #0xd3200
static inline uint64_t fde_func_1421_0x0d32e8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d32e8ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x001cULL;
    return acc;
}

// Func #1422 | PC: 0x0d3304 | FDE: 0x148a38 | Size: 236 bytes
// Hàm #1422 | Địa chỉ PC: 0x0d3304 | Địa chỉ FDE: 0x148a38 | Kích thước: 236 bytes
//   0x0d3304: D10203FF  sub      sp, sp, #0x80
//   0x0d3308: F90023F7  str      x23, [sp, #0x40]
//   0x0d330c: A90557F6  stp      x22, x21, [sp, #0x50]
//   0x0d3310: A9064FF4  stp      x20, x19, [sp, #0x60]
static inline uint64_t fde_func_1422_0x0d3304(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d3304ULL ^ (static_cast<uint64_t>(0xd10203ffULL) << 13);
    acc = (acc + a1 + 0xf90023f7ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x00ecULL;
    return acc;
}

// Func #1423 | PC: 0x0d33f0 | FDE: 0x148a38 | Size: 200 bytes
// Hàm #1423 | Địa chỉ PC: 0x0d33f0 | Địa chỉ FDE: 0x148a38 | Kích thước: 200 bytes
//   0x0d33f0: D10203FF  sub      sp, sp, #0x80
//   0x0d33f4: F90023F7  str      x23, [sp, #0x40]
//   0x0d33f8: A90557F6  stp      x22, x21, [sp, #0x50]
//   0x0d33fc: A9064FF4  stp      x20, x19, [sp, #0x60]
static inline uint64_t fde_func_1423_0x0d33f0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d33f0ULL ^ (static_cast<uint64_t>(0xd10203ffULL) << 13);
    acc = (acc + a1 + 0xf90023f7ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x00c8ULL;
    return acc;
}

// Func #1424 | PC: 0x0d34b8 | FDE: 0x148a38 | Size: 28 bytes
// Hàm #1424 | Địa chỉ PC: 0x0d34b8 | Địa chỉ FDE: 0x148a38 | Kích thước: 28 bytes
//   0x0d34b8: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x0d34bc: 910003FD  mov      x29, sp
//   0x0d34c0: D10D4000  sub      x0, x0, #0x350
//   0x0d34c4: 97FFFFCB  bl       #0xd33f0
static inline uint64_t fde_func_1424_0x0d34b8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d34b8ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x001cULL;
    return acc;
}

// Func #1425 | PC: 0x0d34d4 | FDE: 0x148a38 | Size: 100 bytes
// Hàm #1425 | Địa chỉ PC: 0x0d34d4 | Địa chỉ FDE: 0x148a38 | Kích thước: 100 bytes
//   0x0d34d4: D10183FF  sub      sp, sp, #0x60
//   0x0d34d8: F90023F3  str      x19, [sp, #0x40]
//   0x0d34dc: A9057BFD  stp      x29, x30, [sp, #0x50]
//   0x0d34e0: 910143FD  add      x29, sp, #0x50
static inline uint64_t fde_func_1425_0x0d34d4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d34d4ULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xf90023f3ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0064ULL;
    return acc;
}

// Func #1426 | PC: 0x0d3538 | FDE: 0x148a38 | Size: 28 bytes
// Hàm #1426 | Địa chỉ PC: 0x0d3538 | Địa chỉ FDE: 0x148a38 | Kích thước: 28 bytes
//   0x0d3538: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x0d353c: 910003FD  mov      x29, sp
//   0x0d3540: D10D4000  sub      x0, x0, #0x350
//   0x0d3544: 97FFFFE4  bl       #0xd34d4
static inline uint64_t fde_func_1426_0x0d3538(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d3538ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x001cULL;
    return acc;
}

// Func #1427 | PC: 0x0d3554 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #1427 | Địa chỉ PC: 0x0d3554 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0d3554: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x0d3558: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0d355c: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0d3560: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1427_0x0d3554(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d3554ULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #1428 | PC: 0x0d365c | FDE: 0x148a38 | Size: 28 bytes
// Hàm #1428 | Địa chỉ PC: 0x0d365c | Địa chỉ FDE: 0x148a38 | Kích thước: 28 bytes
//   0x0d365c: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x0d3660: 910003FD  mov      x29, sp
//   0x0d3664: 910EC000  add      x0, x0, #0x3b0
//   0x0d3668: 9400D410  bl       #0x1086a8
static inline uint64_t fde_func_1428_0x0d365c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d365cULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x001cULL;
    return acc;
}

// Func #1429 | PC: 0x0d3678 | FDE: 0x148a38 | Size: 28 bytes
// Hàm #1429 | Địa chỉ PC: 0x0d3678 | Địa chỉ FDE: 0x148a38 | Kích thước: 28 bytes
//   0x0d3678: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x0d367c: 910003FD  mov      x29, sp
//   0x0d3680: 91018000  add      x0, x0, #0x60
//   0x0d3684: 9400D409  bl       #0x1086a8
static inline uint64_t fde_func_1429_0x0d3678(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d3678ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x001cULL;
    return acc;
}

// Func #1430 | PC: 0x0d3694 | FDE: 0x148a38 | Size: 28 bytes
// Hàm #1430 | Địa chỉ PC: 0x0d3694 | Địa chỉ FDE: 0x148a38 | Kích thước: 28 bytes
//   0x0d3694: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x0d3698: 910003FD  mov      x29, sp
//   0x0d369c: 910EC000  add      x0, x0, #0x3b0
//   0x0d36a0: 9400D415  bl       #0x1086f4
static inline uint64_t fde_func_1430_0x0d3694(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d3694ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x001cULL;
    return acc;
}

// Func #1431 | PC: 0x0d36b0 | FDE: 0x148a38 | Size: 28 bytes
// Hàm #1431 | Địa chỉ PC: 0x0d36b0 | Địa chỉ FDE: 0x148a38 | Kích thước: 28 bytes
//   0x0d36b0: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x0d36b4: 910003FD  mov      x29, sp
//   0x0d36b8: 91018000  add      x0, x0, #0x60
//   0x0d36bc: 9400D40E  bl       #0x1086f4
static inline uint64_t fde_func_1431_0x0d36b0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d36b0ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x001cULL;
    return acc;
}

// Func #1432 | PC: 0x0d36cc | FDE: 0x148a38 | Size: 28 bytes
// Hàm #1432 | Địa chỉ PC: 0x0d36cc | Địa chỉ FDE: 0x148a38 | Kích thước: 28 bytes
//   0x0d36cc: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x0d36d0: 910003FD  mov      x29, sp
//   0x0d36d4: 910EC000  add      x0, x0, #0x3b0
//   0x0d36d8: 9400D41D  bl       #0x10874c
static inline uint64_t fde_func_1432_0x0d36cc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d36ccULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x001cULL;
    return acc;
}

// Func #1433 | PC: 0x0d36e8 | FDE: 0x148a38 | Size: 28 bytes
// Hàm #1433 | Địa chỉ PC: 0x0d36e8 | Địa chỉ FDE: 0x148a38 | Kích thước: 28 bytes
//   0x0d36e8: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x0d36ec: 910003FD  mov      x29, sp
//   0x0d36f0: 91018000  add      x0, x0, #0x60
//   0x0d36f4: 9400D416  bl       #0x10874c
static inline uint64_t fde_func_1433_0x0d36e8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d36e8ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x001cULL;
    return acc;
}

// Func #1434 | PC: 0x0d3704 | FDE: 0x148a38 | Size: 28 bytes
// Hàm #1434 | Địa chỉ PC: 0x0d3704 | Địa chỉ FDE: 0x148a38 | Kích thước: 28 bytes
//   0x0d3704: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x0d3708: 910003FD  mov      x29, sp
//   0x0d370c: 910EC000  add      x0, x0, #0x3b0
//   0x0d3710: 9400D438  bl       #0x1087f0
static inline uint64_t fde_func_1434_0x0d3704(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d3704ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x001cULL;
    return acc;
}

// Func #1435 | PC: 0x0d3720 | FDE: 0x148a38 | Size: 168 bytes
// Hàm #1435 | Địa chỉ PC: 0x0d3720 | Địa chỉ FDE: 0x148a38 | Kích thước: 168 bytes
//   0x0d3720: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x0d3724: 910003FD  mov      x29, sp
//   0x0d3728: 91018000  add      x0, x0, #0x60
//   0x0d372c: 9400D431  bl       #0x1087f0
static inline uint64_t fde_func_1435_0x0d3720(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d3720ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x00a8ULL;
    return acc;
}

// Func #1436 | PC: 0x0d37c8 | FDE: 0x148a38 | Size: 120 bytes
// Hàm #1436 | Địa chỉ PC: 0x0d37c8 | Địa chỉ FDE: 0x148a38 | Kích thước: 120 bytes
//   0x0d37c8: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0d37cc: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0d37d0: 910043FD  add      x29, sp, #0x10
//   0x0d37d4: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_1436_0x0d37c8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d37c8ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0078ULL;
    return acc;
}

// Func #1437 | PC: 0x0d3840 | FDE: 0x148a38 | Size: 192 bytes
// Hàm #1437 | Địa chỉ PC: 0x0d3840 | Địa chỉ FDE: 0x148a38 | Kích thước: 192 bytes
//   0x0d3840: D10183FF  sub      sp, sp, #0x60
//   0x0d3844: A9044FF4  stp      x20, x19, [sp, #0x40]
//   0x0d3848: A9057BFD  stp      x29, x30, [sp, #0x50]
//   0x0d384c: 910143FD  add      x29, sp, #0x50
static inline uint64_t fde_func_1437_0x0d3840(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d3840ULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xa9044ff4ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x00c0ULL;
    return acc;
}

// Func #1438 | PC: 0x0d3900 | FDE: 0x148a38 | Size: 28 bytes
// Hàm #1438 | Địa chỉ PC: 0x0d3900 | Địa chỉ FDE: 0x148a38 | Kích thước: 28 bytes
//   0x0d3900: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x0d3904: 910003FD  mov      x29, sp
//   0x0d3908: D10D8000  sub      x0, x0, #0x360
//   0x0d390c: 97FFFFCD  bl       #0xd3840
static inline uint64_t fde_func_1438_0x0d3900(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d3900ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x001cULL;
    return acc;
}

// Func #1439 | PC: 0x0d391c | FDE: 0x148a38 | Size: 200 bytes
// Hàm #1439 | Địa chỉ PC: 0x0d391c | Địa chỉ FDE: 0x148a38 | Kích thước: 200 bytes
//   0x0d391c: D10183FF  sub      sp, sp, #0x60
//   0x0d3920: A90357F6  stp      x22, x21, [sp, #0x30]
//   0x0d3924: A9044FF4  stp      x20, x19, [sp, #0x40]
//   0x0d3928: A9057BFD  stp      x29, x30, [sp, #0x50]
static inline uint64_t fde_func_1439_0x0d391c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d391cULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xa90357f6ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x00c8ULL;
    return acc;
}

// Func #1440 | PC: 0x0d39e4 | FDE: 0x148a38 | Size: 28 bytes
// Hàm #1440 | Địa chỉ PC: 0x0d39e4 | Địa chỉ FDE: 0x148a38 | Kích thước: 28 bytes
//   0x0d39e4: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x0d39e8: 910003FD  mov      x29, sp
//   0x0d39ec: D10D8000  sub      x0, x0, #0x360
//   0x0d39f0: 97FFFFCB  bl       #0xd391c
static inline uint64_t fde_func_1440_0x0d39e4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d39e4ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x001cULL;
    return acc;
}

// Func #1441 | PC: 0x0d3a00 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #1441 | Địa chỉ PC: 0x0d3a00 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0d3a00: D10303FF  sub      sp, sp, #0xc0
//   0x0d3a04: A9066FFC  stp      x28, x27, [sp, #0x60]
//   0x0d3a08: A90767FA  stp      x26, x25, [sp, #0x70]
//   0x0d3a0c: A9085FF8  stp      x24, x23, [sp, #0x80]
static inline uint64_t fde_func_1441_0x0d3a00(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d3a00ULL ^ (static_cast<uint64_t>(0xd10303ffULL) << 13);
    acc = (acc + a1 + 0xa9066ffcULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #1442 | PC: 0x0d3f50 | FDE: 0x148a38 | Size: 124 bytes
// Hàm #1442 | Địa chỉ PC: 0x0d3f50 | Địa chỉ FDE: 0x148a38 | Kích thước: 124 bytes
//   0x0d3f50: D10103FF  sub      sp, sp, #0x40
//   0x0d3f54: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x0d3f58: A9037BFD  stp      x29, x30, [sp, #0x30]
//   0x0d3f5c: 9100C3FD  add      x29, sp, #0x30
static inline uint64_t fde_func_1442_0x0d3f50(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d3f50ULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xa9024ff4ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x007cULL;
    return acc;
}

// Func #1443 | PC: 0x0d3fcc | FDE: 0x148a38 | Size: 256 bytes
// Hàm #1443 | Địa chỉ PC: 0x0d3fcc | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0d3fcc: D10103FF  sub      sp, sp, #0x40
//   0x0d3fd0: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x0d3fd4: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x0d3fd8: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_1443_0x0d3fcc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d3fccULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #1444 | PC: 0x0d4338 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #1444 | Địa chỉ PC: 0x0d4338 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0d4338: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0d433c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0d4340: 910043FD  add      x29, sp, #0x10
//   0x0d4344: AA0103F3  mov      x19, x1
static inline uint64_t fde_func_1444_0x0d4338(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d4338ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #1445 | PC: 0x0d4484 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #1445 | Địa chỉ PC: 0x0d4484 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0d4484: A9BC5FF8  stp      x24, x23, [sp, #-0x40]!
//   0x0d4488: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x0d448c: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x0d4490: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_1445_0x0d4484(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d4484ULL ^ (static_cast<uint64_t>(0xa9bc5ff8ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #1446 | PC: 0x0d4590 | FDE: 0x148a38 | Size: 136 bytes
// Hàm #1446 | Địa chỉ PC: 0x0d4590 | Địa chỉ FDE: 0x148a38 | Kích thước: 136 bytes
//   0x0d4590: D10103FF  sub      sp, sp, #0x40
//   0x0d4594: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x0d4598: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x0d459c: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_1446_0x0d4590(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d4590ULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0088ULL;
    return acc;
}

// Func #1447 | PC: 0x0d4618 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #1447 | Địa chỉ PC: 0x0d4618 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0d4618: A9BA6FFC  stp      x28, x27, [sp, #-0x60]!
//   0x0d461c: A90167FA  stp      x26, x25, [sp, #0x10]
//   0x0d4620: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x0d4624: A90357F6  stp      x22, x21, [sp, #0x30]
static inline uint64_t fde_func_1447_0x0d4618(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d4618ULL ^ (static_cast<uint64_t>(0xa9ba6ffcULL) << 13);
    acc = (acc + a1 + 0xa90167faULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #1448 | PC: 0x0d47ec | FDE: 0x148a38 | Size: 256 bytes
// Hàm #1448 | Địa chỉ PC: 0x0d47ec | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0d47ec: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0d47f0: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0d47f4: 910043FD  add      x29, sp, #0x10
//   0x0d47f8: AA0103F3  mov      x19, x1
static inline uint64_t fde_func_1448_0x0d47ec(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d47ecULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #1449 | PC: 0x0d4984 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #1449 | Địa chỉ PC: 0x0d4984 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0d4984: D101C3FF  sub      sp, sp, #0x70
//   0x0d4988: F90013F9  str      x25, [sp, #0x20]
//   0x0d498c: A9035FF8  stp      x24, x23, [sp, #0x30]
//   0x0d4990: A90457F6  stp      x22, x21, [sp, #0x40]
static inline uint64_t fde_func_1449_0x0d4984(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d4984ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xf90013f9ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #1450 | PC: 0x0d4b74 | FDE: 0x148a38 | Size: 88 bytes
// Hàm #1450 | Địa chỉ PC: 0x0d4b74 | Địa chỉ FDE: 0x148a38 | Kích thước: 88 bytes
//   0x0d4b74: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0d4b78: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0d4b7c: 910043FD  add      x29, sp, #0x10
//   0x0d4b80: 91047013  add      x19, x0, #0x11c
static inline uint64_t fde_func_1450_0x0d4b74(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d4b74ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0058ULL;
    return acc;
}

// Func #1451 | PC: 0x0d4bcc | FDE: 0x148a38 | Size: 64 bytes
// Hàm #1451 | Địa chỉ PC: 0x0d4bcc | Địa chỉ FDE: 0x148a38 | Kích thước: 64 bytes
//   0x0d4bcc: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0d4bd0: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0d4bd4: 910043FD  add      x29, sp, #0x10
//   0x0d4bd8: 91047014  add      x20, x0, #0x11c
static inline uint64_t fde_func_1451_0x0d4bcc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d4bccULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0040ULL;
    return acc;
}

// Func #1452 | PC: 0x0d4c0c | FDE: 0x148a38 | Size: 256 bytes
// Hàm #1452 | Địa chỉ PC: 0x0d4c0c | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0d4c0c: D10283FF  sub      sp, sp, #0xa0
//   0x0d4c10: A9046FFC  stp      x28, x27, [sp, #0x40]
//   0x0d4c14: A90567FA  stp      x26, x25, [sp, #0x50]
//   0x0d4c18: A9065FF8  stp      x24, x23, [sp, #0x60]
static inline uint64_t fde_func_1452_0x0d4c0c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d4c0cULL ^ (static_cast<uint64_t>(0xd10283ffULL) << 13);
    acc = (acc + a1 + 0xa9046ffcULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #1453 | PC: 0x0d5188 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #1453 | Địa chỉ PC: 0x0d5188 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0d5188: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x0d518c: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0d5190: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0d5194: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1453_0x0d5188(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d5188ULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #1454 | PC: 0x0d52fc | FDE: 0x148a38 | Size: 204 bytes
// Hàm #1454 | Địa chỉ PC: 0x0d52fc | Địa chỉ FDE: 0x148a38 | Kích thước: 204 bytes
//   0x0d52fc: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0d5300: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0d5304: 910043FD  add      x29, sp, #0x10
//   0x0d5308: 91047014  add      x20, x0, #0x11c
static inline uint64_t fde_func_1454_0x0d52fc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d52fcULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x00ccULL;
    return acc;
}

// Func #1455 | PC: 0x0d53c8 | FDE: 0x148a38 | Size: 80 bytes
// Hàm #1455 | Địa chỉ PC: 0x0d53c8 | Địa chỉ FDE: 0x148a38 | Kích thước: 80 bytes
//   0x0d53c8: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0d53cc: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0d53d0: 910043FD  add      x29, sp, #0x10
//   0x0d53d4: 91047013  add      x19, x0, #0x11c
static inline uint64_t fde_func_1455_0x0d53c8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d53c8ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0050ULL;
    return acc;
}

// Func #1456 | PC: 0x0d5418 | FDE: 0x148a38 | Size: 144 bytes
// Hàm #1456 | Địa chỉ PC: 0x0d5418 | Địa chỉ FDE: 0x148a38 | Kích thước: 144 bytes
//   0x0d5418: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x0d541c: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0d5420: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0d5424: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1456_0x0d5418(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d5418ULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0090ULL;
    return acc;
}

// Func #1457 | PC: 0x0d54a8 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #1457 | Địa chỉ PC: 0x0d54a8 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0d54a8: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x0d54ac: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0d54b0: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0d54b4: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1457_0x0d54a8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d54a8ULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #1458 | PC: 0x0d5670 | FDE: 0x148a38 | Size: 232 bytes
// Hàm #1458 | Địa chỉ PC: 0x0d5670 | Địa chỉ FDE: 0x148a38 | Kích thước: 232 bytes
//   0x0d5670: A9BC5FF8  stp      x24, x23, [sp, #-0x40]!
//   0x0d5674: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x0d5678: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x0d567c: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_1458_0x0d5670(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d5670ULL ^ (static_cast<uint64_t>(0xa9bc5ff8ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x00e8ULL;
    return acc;
}

// Func #1459 | PC: 0x0d5758 | FDE: 0x148a38 | Size: 68 bytes
// Hàm #1459 | Địa chỉ PC: 0x0d5758 | Địa chỉ FDE: 0x148a38 | Kích thước: 68 bytes
//   0x0d5758: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x0d575c: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0d5760: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0d5764: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1459_0x0d5758(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d5758ULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0044ULL;
    return acc;
}

// Func #1460 | PC: 0x0d579c | FDE: 0x148a38 | Size: 256 bytes
// Hàm #1460 | Địa chỉ PC: 0x0d579c | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0d579c: D101C3FF  sub      sp, sp, #0x70
//   0x0d57a0: F90013F9  str      x25, [sp, #0x20]
//   0x0d57a4: A9035FF8  stp      x24, x23, [sp, #0x30]
//   0x0d57a8: A90457F6  stp      x22, x21, [sp, #0x40]
static inline uint64_t fde_func_1460_0x0d579c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d579cULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xf90013f9ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #1461 | PC: 0x0d5948 | FDE: 0x148a38 | Size: 200 bytes
// Hàm #1461 | Địa chỉ PC: 0x0d5948 | Địa chỉ FDE: 0x148a38 | Kích thước: 200 bytes
//   0x0d5948: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0d594c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0d5950: 910043FD  add      x29, sp, #0x10
//   0x0d5954: 2A0103F3  mov      w19, w1
static inline uint64_t fde_func_1461_0x0d5948(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d5948ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x00c8ULL;
    return acc;
}

// Func #1462 | PC: 0x0d5a10 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #1462 | Địa chỉ PC: 0x0d5a10 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0d5a10: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0d5a14: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0d5a18: 910043FD  add      x29, sp, #0x10
//   0x0d5a1c: B9415008  ldr      w8, [x0, #0x150]
static inline uint64_t fde_func_1462_0x0d5a10(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d5a10ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #1463 | PC: 0x0d5bb0 | FDE: 0x148a38 | Size: 88 bytes [_ZN3com2ss5ttmio23GetUpLoadStorageHandlerEv]
// Hàm #1463 | Địa chỉ PC: 0x0d5bb0 | Địa chỉ FDE: 0x148a38 | Kích thước: 88 bytes
//   0x0d5bb0: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x0d5bb4: 910003FD  mov      x29, sp
//   0x0d5bb8: 97FD735A  bl       #0x32920
//   0x0d5bbc: 97FD7371  bl       #0x32980
static inline uint64_t fde_func_1463_0x0d5bb0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d5bb0ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0058ULL;
    return acc;
}

// Func #1464 | PC: 0x0d5c08 | FDE: 0x148a38 | Size: 88 bytes [_ZN3com2ss5ttmio22GetStorageUploadHandleEv]
// Hàm #1464 | Địa chỉ PC: 0x0d5c08 | Địa chỉ FDE: 0x148a38 | Kích thước: 88 bytes
//   0x0d5c08: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x0d5c0c: 910003FD  mov      x29, sp
//   0x0d5c10: 97FD7344  bl       #0x32920
//   0x0d5c14: 97FD735B  bl       #0x32980
static inline uint64_t fde_func_1464_0x0d5c08(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d5c08ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0058ULL;
    return acc;
}

// Func #1465 | PC: 0x0d5c60 | FDE: 0x148a38 | Size: 232 bytes [_ZN3com2ss5ttmio19MDLQuicStateManager11getInstanceEv]
// Hàm #1465 | Địa chỉ PC: 0x0d5c60 | Địa chỉ FDE: 0x148a38 | Kích thước: 232 bytes
//   0x0d5c60: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0d5c64: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0d5c68: 910043FD  add      x29, sp, #0x10
//   0x0d5c6c: F0000434  adrp     x20, #0x15c000
static inline uint64_t fde_func_1465_0x0d5c60(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d5c60ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x00e8ULL;
    return acc;
}

// Func #1466 | PC: 0x0d5d48 | FDE: 0x148a38 | Size: 84 bytes [_ZN3com2ss5ttmio19MDLQuicStateManagerC1Ev]
// Hàm #1466 | Địa chỉ PC: 0x0d5d48 | Địa chỉ FDE: 0x148a38 | Kích thước: 84 bytes
//   0x0d5d48: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x0d5d4c: 910003FD  mov      x29, sp
//   0x0d5d50: 91008008  add      x8, x0, #0x20
//   0x0d5d54: A9022008  stp      x8, x8, [x0, #0x20]
static inline uint64_t fde_func_1466_0x0d5d48(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d5d48ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0054ULL;
    return acc;
}

// Func #1467 | PC: 0x0d5d9c | FDE: 0x148a38 | Size: 88 bytes [_ZN3com2ss5ttmio19MDLQuicStateManagerD2Ev]
// Hàm #1467 | Địa chỉ PC: 0x0d5d9c | Địa chỉ FDE: 0x148a38 | Kích thước: 88 bytes
//   0x0d5d9c: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x0d5da0: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0d5da4: 910043FD  add      x29, sp, #0x10
//   0x0d5da8: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_1467_0x0d5d9c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d5d9cULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0058ULL;
    return acc;
}

// Func #1468 | PC: 0x0d5df4 | FDE: 0x148a38 | Size: 256 bytes [_ZN3com2ss5ttmio19MDLQuicStateManager12isQuicBrokenEPKc]
// Hàm #1468 | Địa chỉ PC: 0x0d5df4 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0d5df4: D105C3FF  sub      sp, sp, #0x170
//   0x0d5df8: F90093FC  str      x28, [sp, #0x120]
//   0x0d5dfc: A9135FF8  stp      x24, x23, [sp, #0x130]
//   0x0d5e00: A91457F6  stp      x22, x21, [sp, #0x140]
static inline uint64_t fde_func_1468_0x0d5df4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d5df4ULL ^ (static_cast<uint64_t>(0xd105c3ffULL) << 13);
    acc = (acc + a1 + 0xf90093fcULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #1469 | PC: 0x0d5f10 | FDE: 0x148a38 | Size: 192 bytes
// Hàm #1469 | Địa chỉ PC: 0x0d5f10 | Địa chỉ FDE: 0x148a38 | Kích thước: 192 bytes
//   0x0d5f10: D10143FF  sub      sp, sp, #0x50
//   0x0d5f14: A901D7FF  stp      xzr, x21, [sp, #0x18]
//   0x0d5f18: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x0d5f1c: A9047BFD  stp      x29, x30, [sp, #0x40]
static inline uint64_t fde_func_1469_0x0d5f10(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d5f10ULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xa901d7ffULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x00c0ULL;
    return acc;
}

// Func #1470 | PC: 0x0d5fd0 | FDE: 0x148a38 | Size: 52 bytes [_ZN3com2ss5ttmio19MDLQuicStateManager21resetQuicBrokenStatusEv]
// Hàm #1470 | Địa chỉ PC: 0x0d5fd0 | Địa chỉ FDE: 0x148a38 | Kích thước: 52 bytes
//   0x0d5fd0: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0d5fd4: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0d5fd8: 910043FD  add      x29, sp, #0x10
//   0x0d5fdc: 91036014  add      x20, x0, #0xd8
static inline uint64_t fde_func_1470_0x0d5fd0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d5fd0ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0034ULL;
    return acc;
}

// Func #1471 | PC: 0x0d6004 | FDE: 0x148a38 | Size: 120 bytes [_ZN3com2ss5ttmio19MDLQuicStateManager14markQuicBrokenEPKc]
// Hàm #1471 | Địa chỉ PC: 0x0d6004 | Địa chỉ FDE: 0x148a38 | Kích thước: 120 bytes
//   0x0d6004: D10503FF  sub      sp, sp, #0x140
//   0x0d6008: F9008BFC  str      x28, [sp, #0x110]
//   0x0d600c: A9124FF4  stp      x20, x19, [sp, #0x120]
//   0x0d6010: A9137BFD  stp      x29, x30, [sp, #0x130]
static inline uint64_t fde_func_1471_0x0d6004(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d6004ULL ^ (static_cast<uint64_t>(0xd10503ffULL) << 13);
    acc = (acc + a1 + 0xf9008bfcULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0078ULL;
    return acc;
}

// Func #1472 | PC: 0x0d607c | FDE: 0x148a38 | Size: 256 bytes [_ZN3com2ss5ttmio19MDLQuicStateManager20markQuicBrokenByHostEPKc]
// Hàm #1472 | Địa chỉ PC: 0x0d607c | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0d607c: D10143FF  sub      sp, sp, #0x50
//   0x0d6080: A9015FF8  stp      x24, x23, [sp, #0x10]
//   0x0d6084: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x0d6088: A9034FF4  stp      x20, x19, [sp, #0x30]
static inline uint64_t fde_func_1472_0x0d607c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d607cULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xa9015ff8ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #1473 | PC: 0x0d6238 | FDE: 0x148a38 | Size: 8 bytes [_ZN3com2ss5ttmio19MDLQuicStateManager17isQuicEverSucceedEv]
// Hàm #1473 | Địa chỉ PC: 0x0d6238 | Địa chỉ FDE: 0x148a38 | Kích thước: 8 bytes
//   0x0d6238: 39406400  ldrb     w0, [x0, #0x19]
//   0x0d623c: D65F03C0  ret      
static inline uint64_t fde_func_1473_0x0d6238(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d6238ULL ^ (static_cast<uint64_t>(0x39406400ULL) << 13);
    acc = (acc + a1 + 0xd65f03c0ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0008ULL;
    return acc;
}

// Func #1474 | PC: 0x0d6240 | FDE: 0x148a38 | Size: 8 bytes [_ZN3com2ss5ttmio19MDLQuicStateManager14quicRacingNumsEv]
// Hàm #1474 | Địa chỉ PC: 0x0d6240 | Địa chỉ FDE: 0x148a38 | Kích thước: 8 bytes
//   0x0d6240: B9403000  ldr      w0, [x0, #0x30]
//   0x0d6244: D65F03C0  ret      
static inline uint64_t fde_func_1474_0x0d6240(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d6240ULL ^ (static_cast<uint64_t>(0xb9403000ULL) << 13);
    acc = (acc + a1 + 0xd65f03c0ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0008ULL;
    return acc;
}

// Func #1475 | PC: 0x0d6248 | FDE: 0x148a38 | Size: 8 bytes [_ZN3com2ss5ttmio19MDLQuicStateManager16http1xRacingNumsEv]
// Hàm #1475 | Địa chỉ PC: 0x0d6248 | Địa chỉ FDE: 0x148a38 | Kích thước: 8 bytes
//   0x0d6248: B9404800  ldr      w0, [x0, #0x48]
//   0x0d624c: D65F03C0  ret      
static inline uint64_t fde_func_1475_0x0d6248(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d6248ULL ^ (static_cast<uint64_t>(0xb9404800ULL) << 13);
    acc = (acc + a1 + 0xd65f03c0ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0008ULL;
    return acc;
}

// Func #1476 | PC: 0x0d6250 | FDE: 0x148a38 | Size: 132 bytes [_ZN3com2ss5ttmio19MDLQuicStateManager19addToQuicRacingListEl]
// Hàm #1476 | Địa chỉ PC: 0x0d6250 | Địa chỉ FDE: 0x148a38 | Kích thước: 132 bytes
//   0x0d6250: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x0d6254: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0d6258: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0d625c: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1476_0x0d6250(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d6250ULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0084ULL;
    return acc;
}

// Func #1477 | PC: 0x0d62d4 | FDE: 0x148a38 | Size: 132 bytes [_ZN3com2ss5ttmio19MDLQuicStateManager21addToHttp1xRacingListEl]
// Hàm #1477 | Địa chỉ PC: 0x0d62d4 | Địa chỉ FDE: 0x148a38 | Kích thước: 132 bytes
//   0x0d62d4: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x0d62d8: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0d62dc: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0d62e0: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1477_0x0d62d4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d62d4ULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0084ULL;
    return acc;
}

// Func #1478 | PC: 0x0d6358 | FDE: 0x148a38 | Size: 116 bytes [_ZN3com2ss5ttmio19MDLQuicStateManager11updateSpeedERKNS1_10MDLMessageE]
// Hàm #1478 | Địa chỉ PC: 0x0d6358 | Địa chỉ FDE: 0x148a38 | Kích thước: 116 bytes
//   0x0d6358: D100C3FF  sub      sp, sp, #0x30
//   0x0d635c: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0d6360: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0d6364: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1478_0x0d6358(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d6358ULL ^ (static_cast<uint64_t>(0xd100c3ffULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0074ULL;
    return acc;
}

// Func #1479 | PC: 0x0d63cc | FDE: 0x148a38 | Size: 256 bytes [_ZN3com2ss5ttmio19MDLQuicStateManager28insertOneSpeedSampleIntoListERKNS1_10MDLMessageERNSt6__ndk14listIlNS6_9allocatorIlEEEESB_]
// Hàm #1479 | Địa chỉ PC: 0x0d63cc | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0d63cc: D10143FF  sub      sp, sp, #0x50
//   0x0d63d0: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x0d63d4: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x0d63d8: A9047BFD  stp      x29, x30, [sp, #0x40]
static inline uint64_t fde_func_1479_0x0d63cc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d63ccULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xa90257f6ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #1480 | PC: 0x0d6500 | FDE: 0x148a38 | Size: 212 bytes [_ZN3com2ss5ttmio19MDLQuicStateManager23maybeUpdateRacingResultEv]
// Hàm #1480 | Địa chỉ PC: 0x0d6500 | Địa chỉ FDE: 0x148a38 | Kích thước: 212 bytes
//   0x0d6500: D10183FF  sub      sp, sp, #0x60
//   0x0d6504: A90357F6  stp      x22, x21, [sp, #0x30]
//   0x0d6508: A9044FF4  stp      x20, x19, [sp, #0x40]
//   0x0d650c: A9057BFD  stp      x29, x30, [sp, #0x50]
static inline uint64_t fde_func_1480_0x0d6500(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d6500ULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xa90357f6ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x00d4ULL;
    return acc;
}

// Func #1481 | PC: 0x0d65d4 | FDE: 0x148a38 | Size: 256 bytes [_ZN3com2ss5ttmio19MDLQuicStateManager8calSpeedERKNS1_10MDLMessageE]
// Hàm #1481 | Địa chỉ PC: 0x0d65d4 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0d65d4: D10143FF  sub      sp, sp, #0x50
//   0x0d65d8: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x0d65dc: A9047BFD  stp      x29, x30, [sp, #0x40]
//   0x0d65e0: 910103FD  add      x29, sp, #0x40
static inline uint64_t fde_func_1481_0x0d65d4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d65d4ULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xa9034ff4ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #1482 | PC: 0x0d66e8 | FDE: 0x148a38 | Size: 256 bytes [_ZN3com2ss5ttmio19MDLQuicStateManager11calAvgSpeedENSt6__ndk14listIlNS3_9allocatorIlEEEE]
// Hàm #1482 | Địa chỉ PC: 0x0d66e8 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0d66e8: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x0d66ec: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0d66f0: 910043FD  add      x29, sp, #0x10
//   0x0d66f4: AA0103F3  mov      x19, x1
static inline uint64_t fde_func_1482_0x0d66e8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d66e8ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #1483 | PC: 0x0d6820 | FDE: 0x148a38 | Size: 88 bytes [_ZN3com2ss5ttmio19MDLQuicStateManager23updateSpeedRacingStatusEb]
// Hàm #1483 | Địa chỉ PC: 0x0d6820 | Địa chỉ FDE: 0x148a38 | Kích thước: 88 bytes
//   0x0d6820: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x0d6824: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0d6828: 910043FD  add      x29, sp, #0x10
//   0x0d682c: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_1483_0x0d6820(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d6820ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0058ULL;
    return acc;
}

// Func #1484 | PC: 0x0d6878 | FDE: 0x148a38 | Size: 16 bytes [_ZN3com2ss5ttmio19MDLQuicStateManager18isQuicRacedSucceedEv]
// Hàm #1484 | Địa chỉ PC: 0x0d6878 | Địa chỉ FDE: 0x148a38 | Kích thước: 16 bytes
//   0x0d6878: 91006C08  add      x8, x0, #0x1b
//   0x0d687c: 08DFFD08  ldarb    w8, [x8]
//   0x0d6880: 12000100  and      w0, w8, #1
//   0x0d6884: D65F03C0  ret      
static inline uint64_t fde_func_1484_0x0d6878(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d6878ULL ^ (static_cast<uint64_t>(0x91006c08ULL) << 13);
    acc = (acc + a1 + 0x08dffd08ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0010ULL;
    return acc;
}

// Func #1485 | PC: 0x0d6888 | FDE: 0x148a38 | Size: 16 bytes [_ZN3com2ss5ttmio19MDLQuicStateManager19setRacingInProgressEb]
// Hàm #1485 | Địa chỉ PC: 0x0d6888 | Địa chỉ FDE: 0x148a38 | Kích thước: 16 bytes
//   0x0d6888: 12000028  and      w8, w1, #1
//   0x0d688c: 91007009  add      x9, x0, #0x1c
//   0x0d6890: 089FFD28  stlrb    w8, [x9]
//   0x0d6894: D65F03C0  ret      
static inline uint64_t fde_func_1485_0x0d6888(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d6888ULL ^ (static_cast<uint64_t>(0x12000028ULL) << 13);
    acc = (acc + a1 + 0x91007009ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0010ULL;
    return acc;
}

// Func #1486 | PC: 0x0d6898 | FDE: 0x148a38 | Size: 16 bytes [_ZN3com2ss5ttmio19MDLQuicStateManager18isRacingInProgressEv]
// Hàm #1486 | Địa chỉ PC: 0x0d6898 | Địa chỉ FDE: 0x148a38 | Kích thước: 16 bytes
//   0x0d6898: 91007008  add      x8, x0, #0x1c
//   0x0d689c: 08DFFD08  ldarb    w8, [x8]
//   0x0d68a0: 12000100  and      w0, w8, #1
//   0x0d68a4: D65F03C0  ret      
static inline uint64_t fde_func_1486_0x0d6898(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d6898ULL ^ (static_cast<uint64_t>(0x91007008ULL) << 13);
    acc = (acc + a1 + 0x08dffd08ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0010ULL;
    return acc;
}

// Func #1487 | PC: 0x0d68a8 | FDE: 0x148a38 | Size: 96 bytes [_ZN3com2ss5ttmio19MDLQuicStateManager21resetQuicRacingStatusEv]
// Hàm #1487 | Địa chỉ PC: 0x0d68a8 | Địa chỉ FDE: 0x148a38 | Kích thước: 96 bytes
//   0x0d68a8: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0d68ac: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0d68b0: 910043FD  add      x29, sp, #0x10
//   0x0d68b4: 91022014  add      x20, x0, #0x88
static inline uint64_t fde_func_1487_0x0d68a8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d68a8ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0060ULL;
    return acc;
}

// Func #1488 | PC: 0x0d6908 | FDE: 0x148a38 | Size: 76 bytes [_ZN3com2ss5ttmio19MDLQuicStateManager23updateQuicPreconnStatusEb]
// Hàm #1488 | Địa chỉ PC: 0x0d6908 | Địa chỉ FDE: 0x148a38 | Kích thước: 76 bytes
//   0x0d6908: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x0d690c: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0d6910: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0d6914: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1488_0x0d6908(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d6908ULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x004cULL;
    return acc;
}

// Func #1489 | PC: 0x0d6954 | FDE: 0x148a38 | Size: 8 bytes [_ZN3com2ss5ttmio19MDLQuicStateManager14quicConnectingEv]
// Hàm #1489 | Địa chỉ PC: 0x0d6954 | Địa chỉ FDE: 0x148a38 | Kích thước: 8 bytes
//   0x0d6954: 39406000  ldrb     w0, [x0, #0x18]
//   0x0d6958: D65F03C0  ret      
static inline uint64_t fde_func_1489_0x0d6954(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d6954ULL ^ (static_cast<uint64_t>(0x39406000ULL) << 13);
    acc = (acc + a1 + 0xd65f03c0ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0008ULL;
    return acc;
}

// Func #1490 | PC: 0x0d695c | FDE: 0x148a38 | Size: 12 bytes [_ZN3com2ss5ttmio19MDLQuicStateManager17setQuicConnectingEb]
// Hàm #1490 | Địa chỉ PC: 0x0d695c | Địa chỉ FDE: 0x148a38 | Kích thước: 12 bytes
//   0x0d695c: 12000028  and      w8, w1, #1
//   0x0d6960: 39006008  strb     w8, [x0, #0x18]
//   0x0d6964: D65F03C0  ret      
static inline uint64_t fde_func_1490_0x0d695c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d695cULL ^ (static_cast<uint64_t>(0x12000028ULL) << 13);
    acc = (acc + a1 + 0x39006008ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x000cULL;
    return acc;
}

// Func #1491 | PC: 0x0d6968 | FDE: 0x148a38 | Size: 12 bytes [_ZN3com2ss5ttmio19MDLQuicStateManager22setNewQuicConnectStartEv]
// Hàm #1491 | Địa chỉ PC: 0x0d6968 | Địa chỉ FDE: 0x148a38 | Kích thước: 12 bytes
//   0x0d6968: 52800028  mov      w8, #1
//   0x0d696c: 39006808  strb     w8, [x0, #0x1a]
//   0x0d6970: D65F03C0  ret      
static inline uint64_t fde_func_1491_0x0d6968(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d6968ULL ^ (static_cast<uint64_t>(0x52800028ULL) << 13);
    acc = (acc + a1 + 0x39006808ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x000cULL;
    return acc;
}

// Func #1492 | PC: 0x0d6974 | FDE: 0x148a38 | Size: 160 bytes [_ZN3com2ss5ttmio19MDLQuicStateManager22resetQuicConnectStatusEv]
// Hàm #1492 | Địa chỉ PC: 0x0d6974 | Địa chỉ FDE: 0x148a38 | Kích thước: 160 bytes
//   0x0d6974: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0d6978: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0d697c: 910043FD  add      x29, sp, #0x10
//   0x0d6980: 9102C014  add      x20, x0, #0xb0
static inline uint64_t fde_func_1492_0x0d6974(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d6974ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x00a0ULL;
    return acc;
}

// Func #1493 | PC: 0x0d6a14 | FDE: 0x148a38 | Size: 92 bytes
// Hàm #1493 | Địa chỉ PC: 0x0d6a14 | Địa chỉ FDE: 0x148a38 | Kích thước: 92 bytes
//   0x0d6a14: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0d6a18: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0d6a1c: 910043FD  add      x29, sp, #0x10
//   0x0d6a20: F9400808  ldr      x8, [x0, #0x10]
static inline uint64_t fde_func_1493_0x0d6a14(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d6a14ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x005cULL;
    return acc;
}

// Func #1494 | PC: 0x0d6a70 | FDE: 0x148a38 | Size: 212 bytes
// Hàm #1494 | Địa chỉ PC: 0x0d6a70 | Địa chỉ FDE: 0x148a38 | Kích thước: 212 bytes
//   0x0d6a70: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0d6a74: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0d6a78: 910043FD  add      x29, sp, #0x10
//   0x0d6a7c: F9400808  ldr      x8, [x0, #0x10]
static inline uint64_t fde_func_1494_0x0d6a70(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d6a70ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x00d4ULL;
    return acc;
}

// Func #1495 | PC: 0x0d6b44 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #1495 | Địa chỉ PC: 0x0d6b44 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0d6b44: D10143FF  sub      sp, sp, #0x50
//   0x0d6b48: F90013F5  str      x21, [sp, #0x20]
//   0x0d6b4c: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x0d6b50: A9047BFD  stp      x29, x30, [sp, #0x40]
static inline uint64_t fde_func_1495_0x0d6b44(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d6b44ULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xf90013f5ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #1496 | PC: 0x0d6d94 | FDE: 0x148a38 | Size: 80 bytes
// Hàm #1496 | Địa chỉ PC: 0x0d6d94 | Địa chỉ FDE: 0x148a38 | Kích thước: 80 bytes
//   0x0d6d94: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0d6d98: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0d6d9c: 910043FD  add      x29, sp, #0x10
//   0x0d6da0: AA0303F3  mov      x19, x3
static inline uint64_t fde_func_1496_0x0d6d94(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d6d94ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0050ULL;
    return acc;
}

// Func #1497 | PC: 0x0d6de4 | FDE: 0x148a38 | Size: 44 bytes
// Hàm #1497 | Địa chỉ PC: 0x0d6de4 | Địa chỉ FDE: 0x148a38 | Kích thước: 44 bytes
//   0x0d6de4: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0d6de8: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0d6dec: 910043FD  add      x29, sp, #0x10
//   0x0d6df0: 2A0203F3  mov      w19, w2
static inline uint64_t fde_func_1497_0x0d6de4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d6de4ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x002cULL;
    return acc;
}

// Func #1498 | PC: 0x0d6e10 | FDE: 0x148a38 | Size: 44 bytes
// Hàm #1498 | Địa chỉ PC: 0x0d6e10 | Địa chỉ FDE: 0x148a38 | Kích thước: 44 bytes
//   0x0d6e10: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0d6e14: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0d6e18: 910043FD  add      x29, sp, #0x10
//   0x0d6e1c: 2A0203F3  mov      w19, w2
static inline uint64_t fde_func_1498_0x0d6e10(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d6e10ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x002cULL;
    return acc;
}

// Func #1499 | PC: 0x0d6e3c | FDE: 0x148a38 | Size: 256 bytes
// Hàm #1499 | Địa chỉ PC: 0x0d6e3c | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0d6e3c: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0d6e40: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0d6e44: 910043FD  add      x29, sp, #0x10
//   0x0d6e48: B0000428  adrp     x8, #0x15b000
static inline uint64_t fde_func_1499_0x0d6e3c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d6e3cULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #1500 | PC: 0x0d706c | FDE: 0x148a38 | Size: 60 bytes
// Hàm #1500 | Địa chỉ PC: 0x0d706c | Địa chỉ FDE: 0x148a38 | Kích thước: 60 bytes
//   0x0d706c: D100C3FF  sub      sp, sp, #0x30
//   0x0d7070: F9000BF3  str      x19, [sp, #0x10]
//   0x0d7074: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0d7078: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1500_0x0d706c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d706cULL ^ (static_cast<uint64_t>(0xd100c3ffULL) << 13);
    acc = (acc + a1 + 0xf9000bf3ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x003cULL;
    return acc;
}

// Func #1501 | PC: 0x0d70a8 | FDE: 0x148a38 | Size: 92 bytes
// Hàm #1501 | Địa chỉ PC: 0x0d70a8 | Địa chỉ FDE: 0x148a38 | Kích thước: 92 bytes
//   0x0d70a8: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0d70ac: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0d70b0: 910043FD  add      x29, sp, #0x10
//   0x0d70b4: AA0103F3  mov      x19, x1
static inline uint64_t fde_func_1501_0x0d70a8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d70a8ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x005cULL;
    return acc;
}

// Func #1502 | PC: 0x0d7104 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #1502 | Địa chỉ PC: 0x0d7104 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0d7104: D10143FF  sub      sp, sp, #0x50
//   0x0d7108: F90013F5  str      x21, [sp, #0x20]
//   0x0d710c: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x0d7110: A9047BFD  stp      x29, x30, [sp, #0x40]
static inline uint64_t fde_func_1502_0x0d7104(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d7104ULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xf90013f5ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #1503 | PC: 0x0d7254 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #1503 | Địa chỉ PC: 0x0d7254 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0d7254: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0d7258: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0d725c: 910043FD  add      x29, sp, #0x10
//   0x0d7260: AA0203F4  mov      x20, x2
static inline uint64_t fde_func_1503_0x0d7254(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d7254ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #1504 | PC: 0x0d7394 | FDE: 0x148a38 | Size: 92 bytes
// Hàm #1504 | Địa chỉ PC: 0x0d7394 | Địa chỉ FDE: 0x148a38 | Kích thước: 92 bytes
//   0x0d7394: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0d7398: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0d739c: 910043FD  add      x29, sp, #0x10
//   0x0d73a0: AA0003F4  mov      x20, x0
static inline uint64_t fde_func_1504_0x0d7394(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d7394ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x005cULL;
    return acc;
}

// Func #1505 | PC: 0x0d73f0 | FDE: 0x148a38 | Size: 80 bytes
// Hàm #1505 | Địa chỉ PC: 0x0d73f0 | Địa chỉ FDE: 0x148a38 | Kích thước: 80 bytes
//   0x0d73f0: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0d73f4: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0d73f8: 910043FD  add      x29, sp, #0x10
//   0x0d73fc: AA0003F4  mov      x20, x0
static inline uint64_t fde_func_1505_0x0d73f0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d73f0ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0050ULL;
    return acc;
}

// Func #1506 | PC: 0x0d7440 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #1506 | Địa chỉ PC: 0x0d7440 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0d7440: D10183FF  sub      sp, sp, #0x60
//   0x0d7444: F90013F7  str      x23, [sp, #0x20]
//   0x0d7448: A90357F6  stp      x22, x21, [sp, #0x30]
//   0x0d744c: A9044FF4  stp      x20, x19, [sp, #0x40]
static inline uint64_t fde_func_1506_0x0d7440(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d7440ULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xf90013f7ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #1507 | PC: 0x0d7668 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #1507 | Địa chỉ PC: 0x0d7668 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0d7668: D107C3FF  sub      sp, sp, #0x1f0
//   0x0d766c: A91B5FFC  stp      x28, x23, [sp, #0x1b0]
//   0x0d7670: A91C57F6  stp      x22, x21, [sp, #0x1c0]
//   0x0d7674: A91D4FF4  stp      x20, x19, [sp, #0x1d0]
static inline uint64_t fde_func_1507_0x0d7668(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d7668ULL ^ (static_cast<uint64_t>(0xd107c3ffULL) << 13);
    acc = (acc + a1 + 0xa91b5ffcULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #1508 | PC: 0x0d7a1c | FDE: 0x148a38 | Size: 256 bytes
// Hàm #1508 | Địa chỉ PC: 0x0d7a1c | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0d7a1c: D101C3FF  sub      sp, sp, #0x70
//   0x0d7a20: A90457F6  stp      x22, x21, [sp, #0x40]
//   0x0d7a24: A9054FF4  stp      x20, x19, [sp, #0x50]
//   0x0d7a28: A9067BFD  stp      x29, x30, [sp, #0x60]
static inline uint64_t fde_func_1508_0x0d7a1c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d7a1cULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xa90457f6ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #1509 | PC: 0x0d7be8 | FDE: 0x148a38 | Size: 228 bytes
// Hàm #1509 | Địa chỉ PC: 0x0d7be8 | Địa chỉ FDE: 0x148a38 | Kích thước: 228 bytes
//   0x0d7be8: D101C3FF  sub      sp, sp, #0x70
//   0x0d7bec: F90013F9  str      x25, [sp, #0x20]
//   0x0d7bf0: A9035FF8  stp      x24, x23, [sp, #0x30]
//   0x0d7bf4: A90457F6  stp      x22, x21, [sp, #0x40]
static inline uint64_t fde_func_1509_0x0d7be8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d7be8ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xf90013f9ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x00e4ULL;
    return acc;
}

// Func #1510 | PC: 0x0d7ccc | FDE: 0x148a38 | Size: 256 bytes
// Hàm #1510 | Địa chỉ PC: 0x0d7ccc | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0d7ccc: D10283FF  sub      sp, sp, #0xa0
//   0x0d7cd0: F9002BF9  str      x25, [sp, #0x50]
//   0x0d7cd4: A9065FF8  stp      x24, x23, [sp, #0x60]
//   0x0d7cd8: A90757F6  stp      x22, x21, [sp, #0x70]
static inline uint64_t fde_func_1510_0x0d7ccc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d7cccULL ^ (static_cast<uint64_t>(0xd10283ffULL) << 13);
    acc = (acc + a1 + 0xf9002bf9ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #1511 | PC: 0x0d7f40 | FDE: 0x148a38 | Size: 108 bytes
// Hàm #1511 | Địa chỉ PC: 0x0d7f40 | Địa chỉ FDE: 0x148a38 | Kích thước: 108 bytes
//   0x0d7f40: D10143FF  sub      sp, sp, #0x50
//   0x0d7f44: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x0d7f48: A9047BFD  stp      x29, x30, [sp, #0x40]
//   0x0d7f4c: 910103FD  add      x29, sp, #0x40
static inline uint64_t fde_func_1511_0x0d7f40(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d7f40ULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xa9034ff4ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x006cULL;
    return acc;
}

// Func #1512 | PC: 0x0d7fac | FDE: 0x148a38 | Size: 20 bytes [_ZN3com2ss5ttmio19MDLQuicHeDownloader6DeleteEPNS1_16MIOVodNetAdapterE]
// Hàm #1512 | Địa chỉ PC: 0x0d7fac | Địa chỉ FDE: 0x148a38 | Kích thước: 20 bytes
//   0x0d7fac: B4000080  cbz      x0, #0xd7fbc
//   0x0d7fb0: F9400008  ldr      x8, [x0]
//   0x0d7fb4: F9400501  ldr      x1, [x8, #8]
//   0x0d7fb8: D61F0020  br       x1
static inline uint64_t fde_func_1512_0x0d7fac(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d7facULL ^ (static_cast<uint64_t>(0xb4000080ULL) << 13);
    acc = (acc + a1 + 0xf9400008ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0014ULL;
    return acc;
}

// Func #1513 | PC: 0x0d7fc0 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #1513 | Địa chỉ PC: 0x0d7fc0 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0d7fc0: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x0d7fc4: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0d7fc8: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0d7fcc: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1513_0x0d7fc0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d7fc0ULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #1514 | PC: 0x0d8180 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #1514 | Địa chỉ PC: 0x0d8180 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0d8180: D10103FF  sub      sp, sp, #0x40
//   0x0d8184: F9000BF5  str      x21, [sp, #0x10]
//   0x0d8188: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x0d818c: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_1514_0x0d8180(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d8180ULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xf9000bf5ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #1515 | PC: 0x0d82dc | FDE: 0x148a38 | Size: 256 bytes
// Hàm #1515 | Địa chỉ PC: 0x0d82dc | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0d82dc: D102C3FF  sub      sp, sp, #0xb0
//   0x0d82e0: F90043F5  str      x21, [sp, #0x80]
//   0x0d82e4: A9094FF4  stp      x20, x19, [sp, #0x90]
//   0x0d82e8: A90A7BFD  stp      x29, x30, [sp, #0xa0]
static inline uint64_t fde_func_1515_0x0d82dc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d82dcULL ^ (static_cast<uint64_t>(0xd102c3ffULL) << 13);
    acc = (acc + a1 + 0xf90043f5ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #1516 | PC: 0x0d868c | FDE: 0x148a38 | Size: 256 bytes
// Hàm #1516 | Địa chỉ PC: 0x0d868c | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0d868c: D10283FF  sub      sp, sp, #0xa0
//   0x0d8690: F9003BF5  str      x21, [sp, #0x70]
//   0x0d8694: A9084FF4  stp      x20, x19, [sp, #0x80]
//   0x0d8698: A9097BFD  stp      x29, x30, [sp, #0x90]
static inline uint64_t fde_func_1516_0x0d868c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d868cULL ^ (static_cast<uint64_t>(0xd10283ffULL) << 13);
    acc = (acc + a1 + 0xf9003bf5ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #1517 | PC: 0x0d8944 | FDE: 0x148a38 | Size: 176 bytes
// Hàm #1517 | Địa chỉ PC: 0x0d8944 | Địa chỉ FDE: 0x148a38 | Kích thước: 176 bytes
//   0x0d8944: D10583FF  sub      sp, sp, #0x160
//   0x0d8948: A91357FC  stp      x28, x21, [sp, #0x130]
//   0x0d894c: A9144FF4  stp      x20, x19, [sp, #0x140]
//   0x0d8950: A9157BFD  stp      x29, x30, [sp, #0x150]
static inline uint64_t fde_func_1517_0x0d8944(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d8944ULL ^ (static_cast<uint64_t>(0xd10583ffULL) << 13);
    acc = (acc + a1 + 0xa91357fcULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x00b0ULL;
    return acc;
}

// Func #1518 | PC: 0x0d89f4 | FDE: 0x148a38 | Size: 256 bytes
// Hàm #1518 | Địa chỉ PC: 0x0d89f4 | Địa chỉ FDE: 0x148a38 | Kích thước: 256 bytes
//   0x0d89f4: D10143FF  sub      sp, sp, #0x50
//   0x0d89f8: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x0d89fc: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x0d8a00: A9047BFD  stp      x29, x30, [sp, #0x40]
static inline uint64_t fde_func_1518_0x0d89f4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d89f4ULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xa90257f6ULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Func #1519 | PC: 0x0d8b30 | FDE: 0x148a38 | Size: 28 bytes
// Hàm #1519 | Địa chỉ PC: 0x0d8b30 | Địa chỉ FDE: 0x148a38 | Kích thước: 28 bytes
//   0x0d8b30: A9BA6FFC  stp      x28, x27, [sp, #-0x60]!
//   0x0d8b34: A90167FA  stp      x26, x25, [sp, #0x10]
//   0x0d8b38: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x0d8b3c: A90357F6  stp      x22, x21, [sp, #0x30]
static inline uint64_t fde_func_1519_0x0d8b30(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0d8b30ULL ^ (static_cast<uint64_t>(0xa9ba6ffcULL) << 13);
    acc = (acc + a1 + 0xa90167faULL) ^ 0x148a38ULL;
    acc ^= (acc >> 17) * 0x001cULL;
    return acc;
}

// Shard 4 Dispatcher / Bộ điều phối phân mảnh 4
uint64_t execute_fde_shard_4(uint32_t fde_idx, uint64_t a0, uint64_t a1) {
    switch (fde_idx) {
        case 1140: return fde_func_1140_0x0b0f18(a0, a1);
        case 1141: return fde_func_1141_0x0b108c(a0, a1);
        case 1142: return fde_func_1142_0x0b112c(a0, a1);
        case 1143: return fde_func_1143_0x0b11cc(a0, a1);
        case 1144: return fde_func_1144_0x0b1270(a0, a1);
        case 1145: return fde_func_1145_0x0b1324(a0, a1);
        case 1146: return fde_func_1146_0x0b13cc(a0, a1);
        case 1147: return fde_func_1147_0x0b146c(a0, a1);
        case 1148: return fde_func_1148_0x0b150c(a0, a1);
        case 1149: return fde_func_1149_0x0b16b0(a0, a1);
        case 1150: return fde_func_1150_0x0b1708(a0, a1);
        case 1151: return fde_func_1151_0x0b1788(a0, a1);
        case 1152: return fde_func_1152_0x0b18d4(a0, a1);
        case 1153: return fde_func_1153_0x0b1990(a0, a1);
        case 1154: return fde_func_1154_0x0b1b84(a0, a1);
        case 1155: return fde_func_1155_0x0b1d0c(a0, a1);
        case 1156: return fde_func_1156_0x0b1f48(a0, a1);
        case 1157: return fde_func_1157_0x0b20f0(a0, a1);
        case 1158: return fde_func_1158_0x0b2180(a0, a1);
        case 1159: return fde_func_1159_0x0b21d8(a0, a1);
        case 1160: return fde_func_1160_0x0b2258(a0, a1);
        case 1161: return fde_func_1161_0x0b22ec(a0, a1);
        case 1162: return fde_func_1162_0x0b2344(a0, a1);
        case 1163: return fde_func_1163_0x0b23c4(a0, a1);
        case 1164: return fde_func_1164_0x0b2458(a0, a1);
        case 1165: return fde_func_1165_0x0b24b0(a0, a1);
        case 1166: return fde_func_1166_0x0b2530(a0, a1);
        case 1167: return fde_func_1167_0x0b25c4(a0, a1);
        case 1168: return fde_func_1168_0x0b26dc(a0, a1);
        case 1169: return fde_func_1169_0x0b27f4(a0, a1);
        case 1170: return fde_func_1170_0x0b284c(a0, a1);
        case 1171: return fde_func_1171_0x0b28cc(a0, a1);
        case 1172: return fde_func_1172_0x0b2960(a0, a1);
        case 1173: return fde_func_1173_0x0b29b8(a0, a1);
        case 1174: return fde_func_1174_0x0b2a38(a0, a1);
        case 1175: return fde_func_1175_0x0b2acc(a0, a1);
        case 1176: return fde_func_1176_0x0b2b24(a0, a1);
        case 1177: return fde_func_1177_0x0b2ba4(a0, a1);
        case 1178: return fde_func_1178_0x0b2c38(a0, a1);
        case 1179: return fde_func_1179_0x0b2c90(a0, a1);
        case 1180: return fde_func_1180_0x0b2d10(a0, a1);
        case 1181: return fde_func_1181_0x0b2da4(a0, a1);
        case 1182: return fde_func_1182_0x0b2dfc(a0, a1);
        case 1183: return fde_func_1183_0x0b2e7c(a0, a1);
        case 1184: return fde_func_1184_0x0b2f3c(a0, a1);
        case 1185: return fde_func_1185_0x0b30a4(a0, a1);
        case 1186: return fde_func_1186_0x0b3150(a0, a1);
        case 1187: return fde_func_1187_0x0b31f4(a0, a1);
        case 1188: return fde_func_1188_0x0b33e4(a0, a1);
        case 1189: return fde_func_1189_0x0b3738(a0, a1);
        case 1190: return fde_func_1190_0x0b39cc(a0, a1);
        case 1191: return fde_func_1191_0x0b3acc(a0, a1);
        case 1192: return fde_func_1192_0x0b3ae8(a0, a1);
        case 1193: return fde_func_1193_0x0b4acc(a0, a1);
        case 1194: return fde_func_1194_0x0b4ee0(a0, a1);
        case 1195: return fde_func_1195_0x0b4efc(a0, a1);
        case 1196: return fde_func_1196_0x0b5a0c(a0, a1);
        case 1197: return fde_func_1197_0x0b5a28(a0, a1);
        case 1198: return fde_func_1198_0x0b6a00(a0, a1);
        case 1199: return fde_func_1199_0x0b6b3c(a0, a1);
        case 1200: return fde_func_1200_0x0b7338(a0, a1);
        case 1201: return fde_func_1201_0x0b75d4(a0, a1);
        case 1202: return fde_func_1202_0x0b76b8(a0, a1);
        case 1203: return fde_func_1203_0x0b7800(a0, a1);
        case 1204: return fde_func_1204_0x0b7a24(a0, a1);
        case 1205: return fde_func_1205_0x0b7a70(a0, a1);
        case 1206: return fde_func_1206_0x0b7b18(a0, a1);
        case 1207: return fde_func_1207_0x0b7f44(a0, a1);
        case 1208: return fde_func_1208_0x0b904c(a0, a1);
        case 1209: return fde_func_1209_0x0b90ec(a0, a1);
        case 1210: return fde_func_1210_0x0b922c(a0, a1);
        case 1211: return fde_func_1211_0x0b936c(a0, a1);
        case 1212: return fde_func_1212_0x0b95fc(a0, a1);
        case 1213: return fde_func_1213_0x0b9878(a0, a1);
        case 1214: return fde_func_1214_0x0b9e40(a0, a1);
        case 1215: return fde_func_1215_0x0ba114(a0, a1);
        case 1216: return fde_func_1216_0x0ba1a0(a0, a1);
        case 1217: return fde_func_1217_0x0ba208(a0, a1);
        case 1218: return fde_func_1218_0x0ba26c(a0, a1);
        case 1219: return fde_func_1219_0x0ba3e8(a0, a1);
        case 1220: return fde_func_1220_0x0ba458(a0, a1);
        case 1221: return fde_func_1221_0x0ba8d0(a0, a1);
        case 1222: return fde_func_1222_0x0ba91c(a0, a1);
        case 1223: return fde_func_1223_0x0bab00(a0, a1);
        case 1224: return fde_func_1224_0x0bab0c(a0, a1);
        case 1225: return fde_func_1225_0x0bab8c(a0, a1);
        case 1226: return fde_func_1226_0x0baca4(a0, a1);
        case 1227: return fde_func_1227_0x0bad2c(a0, a1);
        case 1228: return fde_func_1228_0x0bb168(a0, a1);
        case 1229: return fde_func_1229_0x0bb1a8(a0, a1);
        case 1230: return fde_func_1230_0x0bb21c(a0, a1);
        case 1231: return fde_func_1231_0x0bb42c(a0, a1);
        case 1232: return fde_func_1232_0x0bb488(a0, a1);
        case 1233: return fde_func_1233_0x0bb540(a0, a1);
        case 1234: return fde_func_1234_0x0bb54c(a0, a1);
        case 1235: return fde_func_1235_0x0bbbd0(a0, a1);
        case 1236: return fde_func_1236_0x0bbd60(a0, a1);
        case 1237: return fde_func_1237_0x0bc2ac(a0, a1);
        case 1238: return fde_func_1238_0x0bc57c(a0, a1);
        case 1239: return fde_func_1239_0x0bc7d0(a0, a1);
        case 1240: return fde_func_1240_0x0bd068(a0, a1);
        case 1241: return fde_func_1241_0x0bd120(a0, a1);
        case 1242: return fde_func_1242_0x0bd210(a0, a1);
        case 1243: return fde_func_1243_0x0bd3f4(a0, a1);
        case 1244: return fde_func_1244_0x0bd544(a0, a1);
        case 1245: return fde_func_1245_0x0bd550(a0, a1);
        case 1246: return fde_func_1246_0x0bd8c8(a0, a1);
        case 1247: return fde_func_1247_0x0bda9c(a0, a1);
        case 1248: return fde_func_1248_0x0bdb90(a0, a1);
        case 1249: return fde_func_1249_0x0bde28(a0, a1);
        case 1250: return fde_func_1250_0x0be124(a0, a1);
        case 1251: return fde_func_1251_0x0be6b4(a0, a1);
        case 1252: return fde_func_1252_0x0be7f0(a0, a1);
        case 1253: return fde_func_1253_0x0be7fc(a0, a1);
        case 1254: return fde_func_1254_0x0be844(a0, a1);
        case 1255: return fde_func_1255_0x0bea28(a0, a1);
        case 1256: return fde_func_1256_0x0beb78(a0, a1);
        case 1257: return fde_func_1257_0x0beb84(a0, a1);
        case 1258: return fde_func_1258_0x0bee3c(a0, a1);
        case 1259: return fde_func_1259_0x0bef2c(a0, a1);
        case 1260: return fde_func_1260_0x0bf078(a0, a1);
        case 1261: return fde_func_1261_0x0bf1ac(a0, a1);
        case 1262: return fde_func_1262_0x0bf29c(a0, a1);
        case 1263: return fde_func_1263_0x0bf348(a0, a1);
        case 1264: return fde_func_1264_0x0bf354(a0, a1);
        case 1265: return fde_func_1265_0x0bf6a4(a0, a1);
        case 1266: return fde_func_1266_0x0bfa14(a0, a1);
        case 1267: return fde_func_1267_0x0c01b4(a0, a1);
        case 1268: return fde_func_1268_0x0c0570(a0, a1);
        case 1269: return fde_func_1269_0x0c09a4(a0, a1);
        case 1270: return fde_func_1270_0x0c0aa8(a0, a1);
        case 1271: return fde_func_1271_0x0c0b28(a0, a1);
        case 1272: return fde_func_1272_0x0c0c68(a0, a1);
        case 1273: return fde_func_1273_0x0c108c(a0, a1);
        case 1274: return fde_func_1274_0x0c12f4(a0, a1);
        case 1275: return fde_func_1275_0x0c14a4(a0, a1);
        case 1276: return fde_func_1276_0x0c15d8(a0, a1);
        case 1277: return fde_func_1277_0x0c18d0(a0, a1);
        case 1278: return fde_func_1278_0x0c1bb8(a0, a1);
        case 1279: return fde_func_1279_0x0c1d90(a0, a1);
        case 1280: return fde_func_1280_0x0c1e24(a0, a1);
        case 1281: return fde_func_1281_0x0c1f34(a0, a1);
        case 1282: return fde_func_1282_0x0c2380(a0, a1);
        case 1283: return fde_func_1283_0x0c2514(a0, a1);
        case 1284: return fde_func_1284_0x0c2620(a0, a1);
        case 1285: return fde_func_1285_0x0c27bc(a0, a1);
        case 1286: return fde_func_1286_0x0c28b4(a0, a1);
        case 1287: return fde_func_1287_0x0c29c0(a0, a1);
        case 1288: return fde_func_1288_0x0c2acc(a0, a1);
        case 1289: return fde_func_1289_0x0c2b6c(a0, a1);
        case 1290: return fde_func_1290_0x0c2c6c(a0, a1);
        case 1291: return fde_func_1291_0x0c2d6c(a0, a1);
        case 1292: return fde_func_1292_0x0c2f00(a0, a1);
        case 1293: return fde_func_1293_0x0c2fac(a0, a1);
        case 1294: return fde_func_1294_0x0c3130(a0, a1);
        case 1295: return fde_func_1295_0x0c3274(a0, a1);
        case 1296: return fde_func_1296_0x0c33b8(a0, a1);
        case 1297: return fde_func_1297_0x0c34f8(a0, a1);
        case 1298: return fde_func_1298_0x0c3550(a0, a1);
        case 1299: return fde_func_1299_0x0c36ac(a0, a1);
        case 1300: return fde_func_1300_0x0c38d4(a0, a1);
        case 1301: return fde_func_1301_0x0c3a80(a0, a1);
        case 1302: return fde_func_1302_0x0c3e8c(a0, a1);
        case 1303: return fde_func_1303_0x0c3ecc(a0, a1);
        case 1304: return fde_func_1304_0x0c3f6c(a0, a1);
        case 1305: return fde_func_1305_0x0c41fc(a0, a1);
        case 1306: return fde_func_1306_0x0c42dc(a0, a1);
        case 1307: return fde_func_1307_0x0c42f0(a0, a1);
        case 1308: return fde_func_1308_0x0c44c0(a0, a1);
        case 1309: return fde_func_1309_0x0c4640(a0, a1);
        case 1310: return fde_func_1310_0x0c47e0(a0, a1);
        case 1311: return fde_func_1311_0x0c49b4(a0, a1);
        case 1312: return fde_func_1312_0x0c49c4(a0, a1);
        case 1313: return fde_func_1313_0x0c4c54(a0, a1);
        case 1314: return fde_func_1314_0x0c4e08(a0, a1);
        case 1315: return fde_func_1315_0x0c4f18(a0, a1);
        case 1316: return fde_func_1316_0x0c50e0(a0, a1);
        case 1317: return fde_func_1317_0x0c5224(a0, a1);
        case 1318: return fde_func_1318_0x0c53b0(a0, a1);
        case 1319: return fde_func_1319_0x0c56d8(a0, a1);
        case 1320: return fde_func_1320_0x0c5724(a0, a1);
        case 1321: return fde_func_1321_0x0c57b0(a0, a1);
        case 1322: return fde_func_1322_0x0c58c8(a0, a1);
        case 1323: return fde_func_1323_0x0c59ac(a0, a1);
        case 1324: return fde_func_1324_0x0c5a1c(a0, a1);
        case 1325: return fde_func_1325_0x0c5d40(a0, a1);
        case 1326: return fde_func_1326_0x0c63f4(a0, a1);
        case 1327: return fde_func_1327_0x0c65a8(a0, a1);
        case 1328: return fde_func_1328_0x0c69fc(a0, a1);
        case 1329: return fde_func_1329_0x0c6bfc(a0, a1);
        case 1330: return fde_func_1330_0x0c6cf4(a0, a1);
        case 1331: return fde_func_1331_0x0c703c(a0, a1);
        case 1332: return fde_func_1332_0x0c70bc(a0, a1);
        case 1333: return fde_func_1333_0x0c7300(a0, a1);
        case 1334: return fde_func_1334_0x0c74a8(a0, a1);
        case 1335: return fde_func_1335_0x0c74dc(a0, a1);
        case 1336: return fde_func_1336_0x0c7510(a0, a1);
        case 1337: return fde_func_1337_0x0c7654(a0, a1);
        case 1338: return fde_func_1338_0x0c76dc(a0, a1);
        case 1339: return fde_func_1339_0x0c77e0(a0, a1);
        case 1340: return fde_func_1340_0x0c7878(a0, a1);
        case 1341: return fde_func_1341_0x0c7b24(a0, a1);
        case 1342: return fde_func_1342_0x0c7cfc(a0, a1);
        case 1343: return fde_func_1343_0x0c7e88(a0, a1);
        case 1344: return fde_func_1344_0x0c7ff0(a0, a1);
        case 1345: return fde_func_1345_0x0c8248(a0, a1);
        case 1346: return fde_func_1346_0x0c8324(a0, a1);
        case 1347: return fde_func_1347_0x0c860c(a0, a1);
        case 1348: return fde_func_1348_0x0c8998(a0, a1);
        case 1349: return fde_func_1349_0x0c8cc0(a0, a1);
        case 1350: return fde_func_1350_0x0c9068(a0, a1);
        case 1351: return fde_func_1351_0x0c9150(a0, a1);
        case 1352: return fde_func_1352_0x0c9490(a0, a1);
        case 1353: return fde_func_1353_0x0c9700(a0, a1);
        case 1354: return fde_func_1354_0x0c9a58(a0, a1);
        case 1355: return fde_func_1355_0x0c9e04(a0, a1);
        case 1356: return fde_func_1356_0x0c9f90(a0, a1);
        case 1357: return fde_func_1357_0x0c9fac(a0, a1);
        case 1358: return fde_func_1358_0x0cb360(a0, a1);
        case 1359: return fde_func_1359_0x0cb6f4(a0, a1);
        case 1360: return fde_func_1360_0x0cb8fc(a0, a1);
        case 1361: return fde_func_1361_0x0cb96c(a0, a1);
        case 1362: return fde_func_1362_0x0cba64(a0, a1);
        case 1363: return fde_func_1363_0x0cbb68(a0, a1);
        case 1364: return fde_func_1364_0x0cbbc0(a0, a1);
        case 1365: return fde_func_1365_0x0cbbe4(a0, a1);
        case 1366: return fde_func_1366_0x0cbc18(a0, a1);
        case 1367: return fde_func_1367_0x0cbc44(a0, a1);
        case 1368: return fde_func_1368_0x0cbc70(a0, a1);
        case 1369: return fde_func_1369_0x0cbc78(a0, a1);
        case 1370: return fde_func_1370_0x0cbc80(a0, a1);
        case 1371: return fde_func_1371_0x0cbc88(a0, a1);
        case 1372: return fde_func_1372_0x0cbc98(a0, a1);
        case 1373: return fde_func_1373_0x0cbd58(a0, a1);
        case 1374: return fde_func_1374_0x0cbd7c(a0, a1);
        case 1375: return fde_func_1375_0x0cbda8(a0, a1);
        case 1376: return fde_func_1376_0x0cbef0(a0, a1);
        case 1377: return fde_func_1377_0x0cbfc4(a0, a1);
        case 1378: return fde_func_1378_0x0cc098(a0, a1);
        case 1379: return fde_func_1379_0x0cc134(a0, a1);
        case 1380: return fde_func_1380_0x0cc294(a0, a1);
        case 1381: return fde_func_1381_0x0cc3e8(a0, a1);
        case 1382: return fde_func_1382_0x0cc548(a0, a1);
        case 1383: return fde_func_1383_0x0cc6a4(a0, a1);
        case 1384: return fde_func_1384_0x0cc930(a0, a1);
        case 1385: return fde_func_1385_0x0cd6a0(a0, a1);
        case 1386: return fde_func_1386_0x0ce520(a0, a1);
        case 1387: return fde_func_1387_0x0ce84c(a0, a1);
        case 1388: return fde_func_1388_0x0cf514(a0, a1);
        case 1389: return fde_func_1389_0x0cfd08(a0, a1);
        case 1390: return fde_func_1390_0x0cfe50(a0, a1);
        case 1391: return fde_func_1391_0x0cfff0(a0, a1);
        case 1392: return fde_func_1392_0x0d01d8(a0, a1);
        case 1393: return fde_func_1393_0x0d02ac(a0, a1);
        case 1394: return fde_func_1394_0x0d0400(a0, a1);
        case 1395: return fde_func_1395_0x0d068c(a0, a1);
        case 1396: return fde_func_1396_0x0d06a8(a0, a1);
        case 1397: return fde_func_1397_0x0d09c0(a0, a1);
        case 1398: return fde_func_1398_0x0d09d8(a0, a1);
        case 1399: return fde_func_1399_0x0d0b10(a0, a1);
        case 1400: return fde_func_1400_0x0d0bac(a0, a1);
        case 1401: return fde_func_1401_0x0d0bc8(a0, a1);
        case 1402: return fde_func_1402_0x0d0db0(a0, a1);
        case 1403: return fde_func_1403_0x0d10d4(a0, a1);
        case 1404: return fde_func_1404_0x0d155c(a0, a1);
        case 1405: return fde_func_1405_0x0d1578(a0, a1);
        case 1406: return fde_func_1406_0x0d17e4(a0, a1);
        case 1407: return fde_func_1407_0x0d18b4(a0, a1);
        case 1408: return fde_func_1408_0x0d1a3c(a0, a1);
        case 1409: return fde_func_1409_0x0d1c4c(a0, a1);
        case 1410: return fde_func_1410_0x0d1ce8(a0, a1);
        case 1411: return fde_func_1411_0x0d1ffc(a0, a1);
        case 1412: return fde_func_1412_0x0d21dc(a0, a1);
        case 1413: return fde_func_1413_0x0d2590(a0, a1);
        case 1414: return fde_func_1414_0x0d2650(a0, a1);
        case 1415: return fde_func_1415_0x0d27e8(a0, a1);
        case 1416: return fde_func_1416_0x0d29b4(a0, a1);
        case 1417: return fde_func_1417_0x0d2c0c(a0, a1);
        case 1418: return fde_func_1418_0x0d2d9c(a0, a1);
        case 1419: return fde_func_1419_0x0d2f54(a0, a1);
        case 1420: return fde_func_1420_0x0d3200(a0, a1);
        case 1421: return fde_func_1421_0x0d32e8(a0, a1);
        case 1422: return fde_func_1422_0x0d3304(a0, a1);
        case 1423: return fde_func_1423_0x0d33f0(a0, a1);
        case 1424: return fde_func_1424_0x0d34b8(a0, a1);
        case 1425: return fde_func_1425_0x0d34d4(a0, a1);
        case 1426: return fde_func_1426_0x0d3538(a0, a1);
        case 1427: return fde_func_1427_0x0d3554(a0, a1);
        case 1428: return fde_func_1428_0x0d365c(a0, a1);
        case 1429: return fde_func_1429_0x0d3678(a0, a1);
        case 1430: return fde_func_1430_0x0d3694(a0, a1);
        case 1431: return fde_func_1431_0x0d36b0(a0, a1);
        case 1432: return fde_func_1432_0x0d36cc(a0, a1);
        case 1433: return fde_func_1433_0x0d36e8(a0, a1);
        case 1434: return fde_func_1434_0x0d3704(a0, a1);
        case 1435: return fde_func_1435_0x0d3720(a0, a1);
        case 1436: return fde_func_1436_0x0d37c8(a0, a1);
        case 1437: return fde_func_1437_0x0d3840(a0, a1);
        case 1438: return fde_func_1438_0x0d3900(a0, a1);
        case 1439: return fde_func_1439_0x0d391c(a0, a1);
        case 1440: return fde_func_1440_0x0d39e4(a0, a1);
        case 1441: return fde_func_1441_0x0d3a00(a0, a1);
        case 1442: return fde_func_1442_0x0d3f50(a0, a1);
        case 1443: return fde_func_1443_0x0d3fcc(a0, a1);
        case 1444: return fde_func_1444_0x0d4338(a0, a1);
        case 1445: return fde_func_1445_0x0d4484(a0, a1);
        case 1446: return fde_func_1446_0x0d4590(a0, a1);
        case 1447: return fde_func_1447_0x0d4618(a0, a1);
        case 1448: return fde_func_1448_0x0d47ec(a0, a1);
        case 1449: return fde_func_1449_0x0d4984(a0, a1);
        case 1450: return fde_func_1450_0x0d4b74(a0, a1);
        case 1451: return fde_func_1451_0x0d4bcc(a0, a1);
        case 1452: return fde_func_1452_0x0d4c0c(a0, a1);
        case 1453: return fde_func_1453_0x0d5188(a0, a1);
        case 1454: return fde_func_1454_0x0d52fc(a0, a1);
        case 1455: return fde_func_1455_0x0d53c8(a0, a1);
        case 1456: return fde_func_1456_0x0d5418(a0, a1);
        case 1457: return fde_func_1457_0x0d54a8(a0, a1);
        case 1458: return fde_func_1458_0x0d5670(a0, a1);
        case 1459: return fde_func_1459_0x0d5758(a0, a1);
        case 1460: return fde_func_1460_0x0d579c(a0, a1);
        case 1461: return fde_func_1461_0x0d5948(a0, a1);
        case 1462: return fde_func_1462_0x0d5a10(a0, a1);
        case 1463: return fde_func_1463_0x0d5bb0(a0, a1);
        case 1464: return fde_func_1464_0x0d5c08(a0, a1);
        case 1465: return fde_func_1465_0x0d5c60(a0, a1);
        case 1466: return fde_func_1466_0x0d5d48(a0, a1);
        case 1467: return fde_func_1467_0x0d5d9c(a0, a1);
        case 1468: return fde_func_1468_0x0d5df4(a0, a1);
        case 1469: return fde_func_1469_0x0d5f10(a0, a1);
        case 1470: return fde_func_1470_0x0d5fd0(a0, a1);
        case 1471: return fde_func_1471_0x0d6004(a0, a1);
        case 1472: return fde_func_1472_0x0d607c(a0, a1);
        case 1473: return fde_func_1473_0x0d6238(a0, a1);
        case 1474: return fde_func_1474_0x0d6240(a0, a1);
        case 1475: return fde_func_1475_0x0d6248(a0, a1);
        case 1476: return fde_func_1476_0x0d6250(a0, a1);
        case 1477: return fde_func_1477_0x0d62d4(a0, a1);
        case 1478: return fde_func_1478_0x0d6358(a0, a1);
        case 1479: return fde_func_1479_0x0d63cc(a0, a1);
        case 1480: return fde_func_1480_0x0d6500(a0, a1);
        case 1481: return fde_func_1481_0x0d65d4(a0, a1);
        case 1482: return fde_func_1482_0x0d66e8(a0, a1);
        case 1483: return fde_func_1483_0x0d6820(a0, a1);
        case 1484: return fde_func_1484_0x0d6878(a0, a1);
        case 1485: return fde_func_1485_0x0d6888(a0, a1);
        case 1486: return fde_func_1486_0x0d6898(a0, a1);
        case 1487: return fde_func_1487_0x0d68a8(a0, a1);
        case 1488: return fde_func_1488_0x0d6908(a0, a1);
        case 1489: return fde_func_1489_0x0d6954(a0, a1);
        case 1490: return fde_func_1490_0x0d695c(a0, a1);
        case 1491: return fde_func_1491_0x0d6968(a0, a1);
        case 1492: return fde_func_1492_0x0d6974(a0, a1);
        case 1493: return fde_func_1493_0x0d6a14(a0, a1);
        case 1494: return fde_func_1494_0x0d6a70(a0, a1);
        case 1495: return fde_func_1495_0x0d6b44(a0, a1);
        case 1496: return fde_func_1496_0x0d6d94(a0, a1);
        case 1497: return fde_func_1497_0x0d6de4(a0, a1);
        case 1498: return fde_func_1498_0x0d6e10(a0, a1);
        case 1499: return fde_func_1499_0x0d6e3c(a0, a1);
        case 1500: return fde_func_1500_0x0d706c(a0, a1);
        case 1501: return fde_func_1501_0x0d70a8(a0, a1);
        case 1502: return fde_func_1502_0x0d7104(a0, a1);
        case 1503: return fde_func_1503_0x0d7254(a0, a1);
        case 1504: return fde_func_1504_0x0d7394(a0, a1);
        case 1505: return fde_func_1505_0x0d73f0(a0, a1);
        case 1506: return fde_func_1506_0x0d7440(a0, a1);
        case 1507: return fde_func_1507_0x0d7668(a0, a1);
        case 1508: return fde_func_1508_0x0d7a1c(a0, a1);
        case 1509: return fde_func_1509_0x0d7be8(a0, a1);
        case 1510: return fde_func_1510_0x0d7ccc(a0, a1);
        case 1511: return fde_func_1511_0x0d7f40(a0, a1);
        case 1512: return fde_func_1512_0x0d7fac(a0, a1);
        case 1513: return fde_func_1513_0x0d7fc0(a0, a1);
        case 1514: return fde_func_1514_0x0d8180(a0, a1);
        case 1515: return fde_func_1515_0x0d82dc(a0, a1);
        case 1516: return fde_func_1516_0x0d868c(a0, a1);
        case 1517: return fde_func_1517_0x0d8944(a0, a1);
        case 1518: return fde_func_1518_0x0d89f4(a0, a1);
        case 1519: return fde_func_1519_0x0d8b30(a0, a1);
        default: return 0ULL;
    }
}

} // namespace ttmio
} // namespace ss
} // namespace com