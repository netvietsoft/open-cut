// ============================================================================
// Clean-Room C++17 AArch64 FDE Shard 4/5 for libmetasec_ov.so
// Phân mảnh Khung Tháo Gỡ (FDE) AArch64 C++17 sạch 4/5 cho libmetasec_ov.so
// Covers representative FDE indices [1200 .. 1599] out of 5,296 total FDEs
// Bao phủ chỉ số FDE đại diện [1200 .. 1599] trên tổng số 5.296 FDE
// ============================================================================
#include "metasec_ov_core.h"

namespace metasec {
namespace ov {

// FDE #1200 | PC: 0x0e49d4 | FDE: 0x1a7ca8 | Size: 68 bytes
// Khung tháo gỡ #1200 | Địa chỉ PC: 0x0e49d4 | Địa chỉ FDE: 0x1a7ca8 | Kích thước: 68 bytes
//   0x0e49d4: B9800808  ldrsw    x8, [x0, #8]
//   0x0e49d8: B9801009  ldrsw    x9, [x0, #0x10]
//   0x0e49dc: B980180A  ldrsw    x10, [x0, #0x18]
//   0x0e49e0: D37DF108  lsl      x8, x8, #3
static inline uint64_t fde_func_1200_0x0e49d4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e49d4ULL ^ (static_cast<uint64_t>(0xb9800808ULL) << 13);
    acc = (acc + a1 + 0xb9801009ULL) ^ 0x1a7ca8ULL;
    acc ^= (acc >> 17) * 0x0044ULL;
    return acc;
}

// FDE #1201 | PC: 0x0e4a18 | FDE: 0x1a7cd8 | Size: 64 bytes
// Khung tháo gỡ #1201 | Địa chỉ PC: 0x0e4a18 | Địa chỉ FDE: 0x1a7cd8 | Kích thước: 64 bytes
//   0x0e4a18: B9801008  ldrsw    x8, [x0, #0x10]
//   0x0e4a1c: F9400409  ldr      x9, [x0, #8]
//   0x0e4a20: B980180A  ldrsw    x10, [x0, #0x18]
//   0x0e4a24: F8687828  ldr      x8, [x1, x8, lsl #3]
static inline uint64_t fde_func_1201_0x0e4a18(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e4a18ULL ^ (static_cast<uint64_t>(0xb9801008ULL) << 13);
    acc = (acc + a1 + 0xf9400409ULL) ^ 0x1a7cd8ULL;
    acc ^= (acc >> 17) * 0x0040ULL;
    return acc;
}

// FDE #1202 | PC: 0x0e4a58 | FDE: 0x1a7d08 | Size: 68 bytes
// Khung tháo gỡ #1202 | Địa chỉ PC: 0x0e4a58 | Địa chỉ FDE: 0x1a7d08 | Kích thước: 68 bytes
//   0x0e4a58: B9800808  ldrsw    x8, [x0, #8]
//   0x0e4a5c: B9801009  ldrsw    x9, [x0, #0x10]
//   0x0e4a60: B980180A  ldrsw    x10, [x0, #0x18]
//   0x0e4a64: F8687828  ldr      x8, [x1, x8, lsl #3]
static inline uint64_t fde_func_1202_0x0e4a58(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e4a58ULL ^ (static_cast<uint64_t>(0xb9800808ULL) << 13);
    acc = (acc + a1 + 0xb9801009ULL) ^ 0x1a7d08ULL;
    acc ^= (acc >> 17) * 0x0044ULL;
    return acc;
}

// FDE #1203 | PC: 0x0e4a9c | FDE: 0x1a7d38 | Size: 80 bytes
// Khung tháo gỡ #1203 | Địa chỉ PC: 0x0e4a9c | Địa chỉ FDE: 0x1a7d38 | Kích thước: 80 bytes
//   0x0e4a9c: B9801008  ldrsw    x8, [x0, #0x10]
//   0x0e4aa0: BD400800  ldr      s0, [x0, #8]
//   0x0e4aa4: D37DF108  lsl      x8, x8, #3
//   0x0e4aa8: BC686821  ldr      s1, [x1, x8]
static inline uint64_t fde_func_1203_0x0e4a9c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e4a9cULL ^ (static_cast<uint64_t>(0xb9801008ULL) << 13);
    acc = (acc + a1 + 0xbd400800ULL) ^ 0x1a7d38ULL;
    acc ^= (acc >> 17) * 0x0050ULL;
    return acc;
}

// FDE #1204 | PC: 0x0e4aec | FDE: 0x1a7d68 | Size: 72 bytes
// Khung tháo gỡ #1204 | Địa chỉ PC: 0x0e4aec | Địa chỉ FDE: 0x1a7d68 | Kích thước: 72 bytes
//   0x0e4aec: B9800808  ldrsw    x8, [x0, #8]
//   0x0e4af0: B9801009  ldrsw    x9, [x0, #0x10]
//   0x0e4af4: D37DF108  lsl      x8, x8, #3
//   0x0e4af8: D37DF129  lsl      x9, x9, #3
static inline uint64_t fde_func_1204_0x0e4aec(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e4aecULL ^ (static_cast<uint64_t>(0xb9800808ULL) << 13);
    acc = (acc + a1 + 0xb9801009ULL) ^ 0x1a7d68ULL;
    acc ^= (acc >> 17) * 0x0048ULL;
    return acc;
}

// FDE #1205 | PC: 0x0e4b34 | FDE: 0x1a7d98 | Size: 64 bytes
// Khung tháo gỡ #1205 | Địa chỉ PC: 0x0e4b34 | Địa chỉ FDE: 0x1a7d98 | Kích thước: 64 bytes
//   0x0e4b34: B9801008  ldrsw    x8, [x0, #0x10]
//   0x0e4b38: FD400400  ldr      d0, [x0, #8]
//   0x0e4b3c: FC687821  ldr      d1, [x1, x8, lsl #3]
//   0x0e4b40: B9801808  ldrsw    x8, [x0, #0x18]
static inline uint64_t fde_func_1205_0x0e4b34(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e4b34ULL ^ (static_cast<uint64_t>(0xb9801008ULL) << 13);
    acc = (acc + a1 + 0xfd400400ULL) ^ 0x1a7d98ULL;
    acc ^= (acc >> 17) * 0x0040ULL;
    return acc;
}

// FDE #1206 | PC: 0x0e4b74 | FDE: 0x1a7dc8 | Size: 76 bytes
// Khung tháo gỡ #1206 | Địa chỉ PC: 0x0e4b74 | Địa chỉ FDE: 0x1a7dc8 | Kích thước: 76 bytes
//   0x0e4b74: B9800808  ldrsw    x8, [x0, #8]
//   0x0e4b78: B9801009  ldrsw    x9, [x0, #0x10]
//   0x0e4b7c: FC687820  ldr      d0, [x1, x8, lsl #3]
//   0x0e4b80: FC697821  ldr      d1, [x1, x9, lsl #3]
static inline uint64_t fde_func_1206_0x0e4b74(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e4b74ULL ^ (static_cast<uint64_t>(0xb9800808ULL) << 13);
    acc = (acc + a1 + 0xb9801009ULL) ^ 0x1a7dc8ULL;
    acc ^= (acc >> 17) * 0x004cULL;
    return acc;
}

// FDE #1207 | PC: 0x0e4bc0 | FDE: 0x1a7df8 | Size: 64 bytes
// Khung tháo gỡ #1207 | Địa chỉ PC: 0x0e4bc0 | Địa chỉ FDE: 0x1a7df8 | Kích thước: 64 bytes
//   0x0e4bc0: B9400808  ldr      w8, [x0, #8]
//   0x0e4bc4: B9401009  ldr      w9, [x0, #0x10]
//   0x0e4bc8: B980180A  ldrsw    x10, [x0, #0x18]
//   0x0e4bcc: 4B090108  sub      w8, w8, w9
static inline uint64_t fde_func_1207_0x0e4bc0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e4bc0ULL ^ (static_cast<uint64_t>(0xb9400808ULL) << 13);
    acc = (acc + a1 + 0xb9401009ULL) ^ 0x1a7df8ULL;
    acc ^= (acc >> 17) * 0x0040ULL;
    return acc;
}

// FDE #1208 | PC: 0x0e4c00 | FDE: 0x1a7e28 | Size: 80 bytes
// Khung tháo gỡ #1208 | Địa chỉ PC: 0x0e4c00 | Địa chỉ FDE: 0x1a7e28 | Kích thước: 80 bytes
//   0x0e4c00: B9800808  ldrsw    x8, [x0, #8]
//   0x0e4c04: B9401009  ldr      w9, [x0, #0x10]
//   0x0e4c08: B980180A  ldrsw    x10, [x0, #0x18]
//   0x0e4c0c: D37DF108  lsl      x8, x8, #3
static inline uint64_t fde_func_1208_0x0e4c00(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e4c00ULL ^ (static_cast<uint64_t>(0xb9800808ULL) << 13);
    acc = (acc + a1 + 0xb9401009ULL) ^ 0x1a7e28ULL;
    acc ^= (acc >> 17) * 0x0050ULL;
    return acc;
}

// FDE #1209 | PC: 0x0e4c50 | FDE: 0x1a7e58 | Size: 56 bytes
// Khung tháo gỡ #1209 | Địa chỉ PC: 0x0e4c50 | Địa chỉ FDE: 0x1a7e58 | Kích thước: 56 bytes
//   0x0e4c50: A940A408  ldp      x8, x9, [x0, #8]
//   0x0e4c54: B980180A  ldrsw    x10, [x0, #0x18]
//   0x0e4c58: CB090108  sub      x8, x8, x9
//   0x0e4c5c: F82A7828  str      x8, [x1, x10, lsl #3]
static inline uint64_t fde_func_1209_0x0e4c50(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e4c50ULL ^ (static_cast<uint64_t>(0xa940a408ULL) << 13);
    acc = (acc + a1 + 0xb980180aULL) ^ 0x1a7e58ULL;
    acc ^= (acc >> 17) * 0x0038ULL;
    return acc;
}

// FDE #1210 | PC: 0x0e4c88 | FDE: 0x1a7e88 | Size: 68 bytes
// Khung tháo gỡ #1210 | Địa chỉ PC: 0x0e4c88 | Địa chỉ FDE: 0x1a7e88 | Kích thước: 68 bytes
//   0x0e4c88: B9800808  ldrsw    x8, [x0, #8]
//   0x0e4c8c: F9400809  ldr      x9, [x0, #0x10]
//   0x0e4c90: B980180A  ldrsw    x10, [x0, #0x18]
//   0x0e4c94: F8687828  ldr      x8, [x1, x8, lsl #3]
static inline uint64_t fde_func_1210_0x0e4c88(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e4c88ULL ^ (static_cast<uint64_t>(0xb9800808ULL) << 13);
    acc = (acc + a1 + 0xf9400809ULL) ^ 0x1a7e88ULL;
    acc ^= (acc >> 17) * 0x0044ULL;
    return acc;
}

// FDE #1211 | PC: 0x0e4ccc | FDE: 0x1a7eb8 | Size: 72 bytes
// Khung tháo gỡ #1211 | Địa chỉ PC: 0x0e4ccc | Địa chỉ FDE: 0x1a7eb8 | Kích thước: 72 bytes
//   0x0e4ccc: BD400800  ldr      s0, [x0, #8]
//   0x0e4cd0: BD401001  ldr      s1, [x0, #0x10]
//   0x0e4cd4: B9801808  ldrsw    x8, [x0, #0x18]
//   0x0e4cd8: 1E213800  fsub     s0, s0, s1
static inline uint64_t fde_func_1211_0x0e4ccc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e4cccULL ^ (static_cast<uint64_t>(0xbd400800ULL) << 13);
    acc = (acc + a1 + 0xbd401001ULL) ^ 0x1a7eb8ULL;
    acc ^= (acc >> 17) * 0x0048ULL;
    return acc;
}

// FDE #1212 | PC: 0x0e4d14 | FDE: 0x1a7ee8 | Size: 88 bytes
// Khung tháo gỡ #1212 | Địa chỉ PC: 0x0e4d14 | Địa chỉ FDE: 0x1a7ee8 | Kích thước: 88 bytes
//   0x0e4d14: B9800808  ldrsw    x8, [x0, #8]
//   0x0e4d18: BD401000  ldr      s0, [x0, #0x10]
//   0x0e4d1c: D37DF108  lsl      x8, x8, #3
//   0x0e4d20: BC686821  ldr      s1, [x1, x8]
static inline uint64_t fde_func_1212_0x0e4d14(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e4d14ULL ^ (static_cast<uint64_t>(0xb9800808ULL) << 13);
    acc = (acc + a1 + 0xbd401000ULL) ^ 0x1a7ee8ULL;
    acc ^= (acc >> 17) * 0x0058ULL;
    return acc;
}

// FDE #1213 | PC: 0x0e4d6c | FDE: 0x1a7f18 | Size: 56 bytes
// Khung tháo gỡ #1213 | Địa chỉ PC: 0x0e4d6c | Địa chỉ FDE: 0x1a7f18 | Kích thước: 56 bytes
//   0x0e4d6c: 6D408400  ldp      d0, d1, [x0, #8]
//   0x0e4d70: B9801808  ldrsw    x8, [x0, #0x18]
//   0x0e4d74: 1E613800  fsub     d0, d0, d1
//   0x0e4d78: FC287820  str      d0, [x1, x8, lsl #3]
static inline uint64_t fde_func_1213_0x0e4d6c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e4d6cULL ^ (static_cast<uint64_t>(0x6d408400ULL) << 13);
    acc = (acc + a1 + 0xb9801808ULL) ^ 0x1a7f18ULL;
    acc ^= (acc >> 17) * 0x0038ULL;
    return acc;
}

// FDE #1214 | PC: 0x0e4da4 | FDE: 0x1a7f48 | Size: 68 bytes
// Khung tháo gỡ #1214 | Địa chỉ PC: 0x0e4da4 | Địa chỉ FDE: 0x1a7f48 | Kích thước: 68 bytes
//   0x0e4da4: B9800808  ldrsw    x8, [x0, #8]
//   0x0e4da8: FD400801  ldr      d1, [x0, #0x10]
//   0x0e4dac: FC687820  ldr      d0, [x1, x8, lsl #3]
//   0x0e4db0: B9801808  ldrsw    x8, [x0, #0x18]
static inline uint64_t fde_func_1214_0x0e4da4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e4da4ULL ^ (static_cast<uint64_t>(0xb9800808ULL) << 13);
    acc = (acc + a1 + 0xfd400801ULL) ^ 0x1a7f48ULL;
    acc ^= (acc >> 17) * 0x0044ULL;
    return acc;
}

// FDE #1215 | PC: 0x0e4de8 | FDE: 0x1a7f78 | Size: 68 bytes
// Khung tháo gỡ #1215 | Địa chỉ PC: 0x0e4de8 | Địa chỉ FDE: 0x1a7f78 | Kích thước: 68 bytes
//   0x0e4de8: F9400408  ldr      x8, [x0, #8]
//   0x0e4dec: D000070B  adrp     x11, #0x1c6000
//   0x0e4df0: 912EC16B  add      x11, x11, #0xbb0
//   0x0e4df4: 79401509  ldrh     w9, [x8, #0xa]
static inline uint64_t fde_func_1215_0x0e4de8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e4de8ULL ^ (static_cast<uint64_t>(0xf9400408ULL) << 13);
    acc = (acc + a1 + 0xd000070bULL) ^ 0x1a7f78ULL;
    acc ^= (acc >> 17) * 0x0044ULL;
    return acc;
}

// FDE #1216 | PC: 0x0e4e2c | FDE: 0x1a7fa8 | Size: 72 bytes
// Khung tháo gỡ #1216 | Địa chỉ PC: 0x0e4e2c | Địa chỉ FDE: 0x1a7fa8 | Kích thước: 72 bytes
//   0x0e4e2c: B9801008  ldrsw    x8, [x0, #0x10]
//   0x0e4e30: B9400809  ldr      w9, [x0, #8]
//   0x0e4e34: B980180A  ldrsw    x10, [x0, #0x18]
//   0x0e4e38: D37DF108  lsl      x8, x8, #3
static inline uint64_t fde_func_1216_0x0e4e2c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e4e2cULL ^ (static_cast<uint64_t>(0xb9801008ULL) << 13);
    acc = (acc + a1 + 0xb9400809ULL) ^ 0x1a7fa8ULL;
    acc ^= (acc >> 17) * 0x0048ULL;
    return acc;
}

// FDE #1217 | PC: 0x0e4e74 | FDE: 0x1a7fd8 | Size: 68 bytes
// Khung tháo gỡ #1217 | Địa chỉ PC: 0x0e4e74 | Địa chỉ FDE: 0x1a7fd8 | Kích thước: 68 bytes
//   0x0e4e74: B9800808  ldrsw    x8, [x0, #8]
//   0x0e4e78: B9801009  ldrsw    x9, [x0, #0x10]
//   0x0e4e7c: B980180A  ldrsw    x10, [x0, #0x18]
//   0x0e4e80: D37DF108  lsl      x8, x8, #3
static inline uint64_t fde_func_1217_0x0e4e74(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e4e74ULL ^ (static_cast<uint64_t>(0xb9800808ULL) << 13);
    acc = (acc + a1 + 0xb9801009ULL) ^ 0x1a7fd8ULL;
    acc ^= (acc >> 17) * 0x0044ULL;
    return acc;
}

// FDE #1218 | PC: 0x0e4eb8 | FDE: 0x1a8008 | Size: 64 bytes
// Khung tháo gỡ #1218 | Địa chỉ PC: 0x0e4eb8 | Địa chỉ FDE: 0x1a8008 | Kích thước: 64 bytes
//   0x0e4eb8: B9801008  ldrsw    x8, [x0, #0x10]
//   0x0e4ebc: F9400409  ldr      x9, [x0, #8]
//   0x0e4ec0: B980180A  ldrsw    x10, [x0, #0x18]
//   0x0e4ec4: F8687828  ldr      x8, [x1, x8, lsl #3]
static inline uint64_t fde_func_1218_0x0e4eb8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e4eb8ULL ^ (static_cast<uint64_t>(0xb9801008ULL) << 13);
    acc = (acc + a1 + 0xf9400409ULL) ^ 0x1a8008ULL;
    acc ^= (acc >> 17) * 0x0040ULL;
    return acc;
}

// FDE #1219 | PC: 0x0e4ef8 | FDE: 0x1a8038 | Size: 68 bytes
// Khung tháo gỡ #1219 | Địa chỉ PC: 0x0e4ef8 | Địa chỉ FDE: 0x1a8038 | Kích thước: 68 bytes
//   0x0e4ef8: B9800808  ldrsw    x8, [x0, #8]
//   0x0e4efc: B9801009  ldrsw    x9, [x0, #0x10]
//   0x0e4f00: B980180A  ldrsw    x10, [x0, #0x18]
//   0x0e4f04: F8687828  ldr      x8, [x1, x8, lsl #3]
static inline uint64_t fde_func_1219_0x0e4ef8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e4ef8ULL ^ (static_cast<uint64_t>(0xb9800808ULL) << 13);
    acc = (acc + a1 + 0xb9801009ULL) ^ 0x1a8038ULL;
    acc ^= (acc >> 17) * 0x0044ULL;
    return acc;
}

// FDE #1220 | PC: 0x0e4f3c | FDE: 0x1a8068 | Size: 80 bytes
// Khung tháo gỡ #1220 | Địa chỉ PC: 0x0e4f3c | Địa chỉ FDE: 0x1a8068 | Kích thước: 80 bytes
//   0x0e4f3c: B9801008  ldrsw    x8, [x0, #0x10]
//   0x0e4f40: BD400800  ldr      s0, [x0, #8]
//   0x0e4f44: D37DF108  lsl      x8, x8, #3
//   0x0e4f48: BC686821  ldr      s1, [x1, x8]
static inline uint64_t fde_func_1220_0x0e4f3c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e4f3cULL ^ (static_cast<uint64_t>(0xb9801008ULL) << 13);
    acc = (acc + a1 + 0xbd400800ULL) ^ 0x1a8068ULL;
    acc ^= (acc >> 17) * 0x0050ULL;
    return acc;
}

// FDE #1221 | PC: 0x0e4f8c | FDE: 0x1a8098 | Size: 72 bytes
// Khung tháo gỡ #1221 | Địa chỉ PC: 0x0e4f8c | Địa chỉ FDE: 0x1a8098 | Kích thước: 72 bytes
//   0x0e4f8c: B9800808  ldrsw    x8, [x0, #8]
//   0x0e4f90: B9801009  ldrsw    x9, [x0, #0x10]
//   0x0e4f94: D37DF108  lsl      x8, x8, #3
//   0x0e4f98: D37DF129  lsl      x9, x9, #3
static inline uint64_t fde_func_1221_0x0e4f8c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e4f8cULL ^ (static_cast<uint64_t>(0xb9800808ULL) << 13);
    acc = (acc + a1 + 0xb9801009ULL) ^ 0x1a8098ULL;
    acc ^= (acc >> 17) * 0x0048ULL;
    return acc;
}

// FDE #1222 | PC: 0x0e4fd4 | FDE: 0x1a80c8 | Size: 64 bytes
// Khung tháo gỡ #1222 | Địa chỉ PC: 0x0e4fd4 | Địa chỉ FDE: 0x1a80c8 | Kích thước: 64 bytes
//   0x0e4fd4: B9801008  ldrsw    x8, [x0, #0x10]
//   0x0e4fd8: FD400400  ldr      d0, [x0, #8]
//   0x0e4fdc: FC687821  ldr      d1, [x1, x8, lsl #3]
//   0x0e4fe0: B9801808  ldrsw    x8, [x0, #0x18]
static inline uint64_t fde_func_1222_0x0e4fd4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e4fd4ULL ^ (static_cast<uint64_t>(0xb9801008ULL) << 13);
    acc = (acc + a1 + 0xfd400400ULL) ^ 0x1a80c8ULL;
    acc ^= (acc >> 17) * 0x0040ULL;
    return acc;
}

// FDE #1223 | PC: 0x0e5014 | FDE: 0x1a80f8 | Size: 76 bytes
// Khung tháo gỡ #1223 | Địa chỉ PC: 0x0e5014 | Địa chỉ FDE: 0x1a80f8 | Kích thước: 76 bytes
//   0x0e5014: B9800808  ldrsw    x8, [x0, #8]
//   0x0e5018: B9801009  ldrsw    x9, [x0, #0x10]
//   0x0e501c: FC687820  ldr      d0, [x1, x8, lsl #3]
//   0x0e5020: FC697821  ldr      d1, [x1, x9, lsl #3]
static inline uint64_t fde_func_1223_0x0e5014(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e5014ULL ^ (static_cast<uint64_t>(0xb9800808ULL) << 13);
    acc = (acc + a1 + 0xb9801009ULL) ^ 0x1a80f8ULL;
    acc ^= (acc >> 17) * 0x004cULL;
    return acc;
}

// FDE #1224 | PC: 0x0e5060 | FDE: 0x1a8128 | Size: 64 bytes
// Khung tháo gỡ #1224 | Địa chỉ PC: 0x0e5060 | Địa chỉ FDE: 0x1a8128 | Kích thước: 64 bytes
//   0x0e5060: B9400808  ldr      w8, [x0, #8]
//   0x0e5064: B9401009  ldr      w9, [x0, #0x10]
//   0x0e5068: B980180A  ldrsw    x10, [x0, #0x18]
//   0x0e506c: 1AC90D08  sdiv     w8, w8, w9
static inline uint64_t fde_func_1224_0x0e5060(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e5060ULL ^ (static_cast<uint64_t>(0xb9400808ULL) << 13);
    acc = (acc + a1 + 0xb9401009ULL) ^ 0x1a8128ULL;
    acc ^= (acc >> 17) * 0x0040ULL;
    return acc;
}

// FDE #1225 | PC: 0x0e50a0 | FDE: 0x1a8158 | Size: 80 bytes
// Khung tháo gỡ #1225 | Địa chỉ PC: 0x0e50a0 | Địa chỉ FDE: 0x1a8158 | Kích thước: 80 bytes
//   0x0e50a0: B9800808  ldrsw    x8, [x0, #8]
//   0x0e50a4: B9401009  ldr      w9, [x0, #0x10]
//   0x0e50a8: B980180A  ldrsw    x10, [x0, #0x18]
//   0x0e50ac: D37DF108  lsl      x8, x8, #3
static inline uint64_t fde_func_1225_0x0e50a0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e50a0ULL ^ (static_cast<uint64_t>(0xb9800808ULL) << 13);
    acc = (acc + a1 + 0xb9401009ULL) ^ 0x1a8158ULL;
    acc ^= (acc >> 17) * 0x0050ULL;
    return acc;
}

// FDE #1226 | PC: 0x0e50f0 | FDE: 0x1a8188 | Size: 56 bytes
// Khung tháo gỡ #1226 | Địa chỉ PC: 0x0e50f0 | Địa chỉ FDE: 0x1a8188 | Kích thước: 56 bytes
//   0x0e50f0: A940A408  ldp      x8, x9, [x0, #8]
//   0x0e50f4: B980180A  ldrsw    x10, [x0, #0x18]
//   0x0e50f8: 9AC90D08  sdiv     x8, x8, x9
//   0x0e50fc: F82A7828  str      x8, [x1, x10, lsl #3]
static inline uint64_t fde_func_1226_0x0e50f0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e50f0ULL ^ (static_cast<uint64_t>(0xa940a408ULL) << 13);
    acc = (acc + a1 + 0xb980180aULL) ^ 0x1a8188ULL;
    acc ^= (acc >> 17) * 0x0038ULL;
    return acc;
}

// FDE #1227 | PC: 0x0e5128 | FDE: 0x1a81b8 | Size: 68 bytes
// Khung tháo gỡ #1227 | Địa chỉ PC: 0x0e5128 | Địa chỉ FDE: 0x1a81b8 | Kích thước: 68 bytes
//   0x0e5128: B9800808  ldrsw    x8, [x0, #8]
//   0x0e512c: F9400809  ldr      x9, [x0, #0x10]
//   0x0e5130: B980180A  ldrsw    x10, [x0, #0x18]
//   0x0e5134: F8687828  ldr      x8, [x1, x8, lsl #3]
static inline uint64_t fde_func_1227_0x0e5128(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e5128ULL ^ (static_cast<uint64_t>(0xb9800808ULL) << 13);
    acc = (acc + a1 + 0xf9400809ULL) ^ 0x1a81b8ULL;
    acc ^= (acc >> 17) * 0x0044ULL;
    return acc;
}

// FDE #1228 | PC: 0x0e516c | FDE: 0x1a81e8 | Size: 72 bytes
// Khung tháo gỡ #1228 | Địa chỉ PC: 0x0e516c | Địa chỉ FDE: 0x1a81e8 | Kích thước: 72 bytes
//   0x0e516c: F9400408  ldr      x8, [x0, #8]
//   0x0e5170: B000070B  adrp     x11, #0x1c6000
//   0x0e5174: 9132C16B  add      x11, x11, #0xcb0
//   0x0e5178: 79401509  ldrh     w9, [x8, #0xa]
static inline uint64_t fde_func_1228_0x0e516c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e516cULL ^ (static_cast<uint64_t>(0xf9400408ULL) << 13);
    acc = (acc + a1 + 0xb000070bULL) ^ 0x1a81e8ULL;
    acc ^= (acc >> 17) * 0x0048ULL;
    return acc;
}

// FDE #1229 | PC: 0x0e51b4 | FDE: 0x1a8218 | Size: 80 bytes
// Khung tháo gỡ #1229 | Địa chỉ PC: 0x0e51b4 | Địa chỉ FDE: 0x1a8218 | Kích thước: 80 bytes
//   0x0e51b4: B9801008  ldrsw    x8, [x0, #0x10]
//   0x0e51b8: B9400809  ldr      w9, [x0, #8]
//   0x0e51bc: B980180A  ldrsw    x10, [x0, #0x18]
//   0x0e51c0: D37DF108  lsl      x8, x8, #3
static inline uint64_t fde_func_1229_0x0e51b4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e51b4ULL ^ (static_cast<uint64_t>(0xb9801008ULL) << 13);
    acc = (acc + a1 + 0xb9400809ULL) ^ 0x1a8218ULL;
    acc ^= (acc >> 17) * 0x0050ULL;
    return acc;
}

// FDE #1230 | PC: 0x0e5204 | FDE: 0x1a8248 | Size: 76 bytes
// Khung tháo gỡ #1230 | Địa chỉ PC: 0x0e5204 | Địa chỉ FDE: 0x1a8248 | Kích thước: 76 bytes
//   0x0e5204: B9800808  ldrsw    x8, [x0, #8]
//   0x0e5208: B9801009  ldrsw    x9, [x0, #0x10]
//   0x0e520c: B980180A  ldrsw    x10, [x0, #0x18]
//   0x0e5210: D37DF108  lsl      x8, x8, #3
static inline uint64_t fde_func_1230_0x0e5204(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e5204ULL ^ (static_cast<uint64_t>(0xb9800808ULL) << 13);
    acc = (acc + a1 + 0xb9801009ULL) ^ 0x1a8248ULL;
    acc ^= (acc >> 17) * 0x004cULL;
    return acc;
}

// FDE #1231 | PC: 0x0e5250 | FDE: 0x1a8278 | Size: 72 bytes
// Khung tháo gỡ #1231 | Địa chỉ PC: 0x0e5250 | Địa chỉ FDE: 0x1a8278 | Kích thước: 72 bytes
//   0x0e5250: B9801008  ldrsw    x8, [x0, #0x10]
//   0x0e5254: F9400409  ldr      x9, [x0, #8]
//   0x0e5258: B980180A  ldrsw    x10, [x0, #0x18]
//   0x0e525c: F8687828  ldr      x8, [x1, x8, lsl #3]
static inline uint64_t fde_func_1231_0x0e5250(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e5250ULL ^ (static_cast<uint64_t>(0xb9801008ULL) << 13);
    acc = (acc + a1 + 0xf9400409ULL) ^ 0x1a8278ULL;
    acc ^= (acc >> 17) * 0x0048ULL;
    return acc;
}

// FDE #1232 | PC: 0x0e5298 | FDE: 0x1a82a8 | Size: 80 bytes
// Khung tháo gỡ #1232 | Địa chỉ PC: 0x0e5298 | Địa chỉ FDE: 0x1a82a8 | Kích thước: 80 bytes
//   0x0e5298: B9800808  ldrsw    x8, [x0, #8]
//   0x0e529c: B9801009  ldrsw    x9, [x0, #0x10]
//   0x0e52a0: B980180A  ldrsw    x10, [x0, #0x18]
//   0x0e52a4: F8687828  ldr      x8, [x1, x8, lsl #3]
static inline uint64_t fde_func_1232_0x0e5298(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e5298ULL ^ (static_cast<uint64_t>(0xb9800808ULL) << 13);
    acc = (acc + a1 + 0xb9801009ULL) ^ 0x1a82a8ULL;
    acc ^= (acc >> 17) * 0x0050ULL;
    return acc;
}

// FDE #1233 | PC: 0x0e52e8 | FDE: 0x1a82d8 | Size: 64 bytes
// Khung tháo gỡ #1233 | Địa chỉ PC: 0x0e52e8 | Địa chỉ FDE: 0x1a82d8 | Kích thước: 64 bytes
//   0x0e52e8: B9400808  ldr      w8, [x0, #8]
//   0x0e52ec: B9401009  ldr      w9, [x0, #0x10]
//   0x0e52f0: B980180A  ldrsw    x10, [x0, #0x18]
//   0x0e52f4: 1AC90908  udiv     w8, w8, w9
static inline uint64_t fde_func_1233_0x0e52e8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e52e8ULL ^ (static_cast<uint64_t>(0xb9400808ULL) << 13);
    acc = (acc + a1 + 0xb9401009ULL) ^ 0x1a82d8ULL;
    acc ^= (acc >> 17) * 0x0040ULL;
    return acc;
}

// FDE #1234 | PC: 0x0e5328 | FDE: 0x1a8308 | Size: 80 bytes
// Khung tháo gỡ #1234 | Địa chỉ PC: 0x0e5328 | Địa chỉ FDE: 0x1a8308 | Kích thước: 80 bytes
//   0x0e5328: B9800808  ldrsw    x8, [x0, #8]
//   0x0e532c: B9401009  ldr      w9, [x0, #0x10]
//   0x0e5330: B980180A  ldrsw    x10, [x0, #0x18]
//   0x0e5334: D37DF108  lsl      x8, x8, #3
static inline uint64_t fde_func_1234_0x0e5328(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e5328ULL ^ (static_cast<uint64_t>(0xb9800808ULL) << 13);
    acc = (acc + a1 + 0xb9401009ULL) ^ 0x1a8308ULL;
    acc ^= (acc >> 17) * 0x0050ULL;
    return acc;
}

// FDE #1235 | PC: 0x0e5378 | FDE: 0x1a8338 | Size: 56 bytes
// Khung tháo gỡ #1235 | Địa chỉ PC: 0x0e5378 | Địa chỉ FDE: 0x1a8338 | Kích thước: 56 bytes
//   0x0e5378: A940A408  ldp      x8, x9, [x0, #8]
//   0x0e537c: B980180A  ldrsw    x10, [x0, #0x18]
//   0x0e5380: 9AC90908  udiv     x8, x8, x9
//   0x0e5384: F82A7828  str      x8, [x1, x10, lsl #3]
static inline uint64_t fde_func_1235_0x0e5378(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e5378ULL ^ (static_cast<uint64_t>(0xa940a408ULL) << 13);
    acc = (acc + a1 + 0xb980180aULL) ^ 0x1a8338ULL;
    acc ^= (acc >> 17) * 0x0038ULL;
    return acc;
}

// FDE #1236 | PC: 0x0e53b0 | FDE: 0x1a8368 | Size: 68 bytes
// Khung tháo gỡ #1236 | Địa chỉ PC: 0x0e53b0 | Địa chỉ FDE: 0x1a8368 | Kích thước: 68 bytes
//   0x0e53b0: B9800808  ldrsw    x8, [x0, #8]
//   0x0e53b4: F9400809  ldr      x9, [x0, #0x10]
//   0x0e53b8: B980180A  ldrsw    x10, [x0, #0x18]
//   0x0e53bc: F8687828  ldr      x8, [x1, x8, lsl #3]
static inline uint64_t fde_func_1236_0x0e53b0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e53b0ULL ^ (static_cast<uint64_t>(0xb9800808ULL) << 13);
    acc = (acc + a1 + 0xf9400809ULL) ^ 0x1a8368ULL;
    acc ^= (acc >> 17) * 0x0044ULL;
    return acc;
}

// FDE #1237 | PC: 0x0e53f4 | FDE: 0x1a8398 | Size: 72 bytes
// Khung tháo gỡ #1237 | Địa chỉ PC: 0x0e53f4 | Địa chỉ FDE: 0x1a8398 | Kích thước: 72 bytes
//   0x0e53f4: F9400408  ldr      x8, [x0, #8]
//   0x0e53f8: B000070B  adrp     x11, #0x1c6000
//   0x0e53fc: 9136C16B  add      x11, x11, #0xdb0
//   0x0e5400: 79401509  ldrh     w9, [x8, #0xa]
static inline uint64_t fde_func_1237_0x0e53f4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e53f4ULL ^ (static_cast<uint64_t>(0xf9400408ULL) << 13);
    acc = (acc + a1 + 0xb000070bULL) ^ 0x1a8398ULL;
    acc ^= (acc >> 17) * 0x0048ULL;
    return acc;
}

// FDE #1238 | PC: 0x0e543c | FDE: 0x1a83c8 | Size: 80 bytes
// Khung tháo gỡ #1238 | Địa chỉ PC: 0x0e543c | Địa chỉ FDE: 0x1a83c8 | Kích thước: 80 bytes
//   0x0e543c: B9801008  ldrsw    x8, [x0, #0x10]
//   0x0e5440: B9400809  ldr      w9, [x0, #8]
//   0x0e5444: B980180A  ldrsw    x10, [x0, #0x18]
//   0x0e5448: D37DF108  lsl      x8, x8, #3
static inline uint64_t fde_func_1238_0x0e543c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e543cULL ^ (static_cast<uint64_t>(0xb9801008ULL) << 13);
    acc = (acc + a1 + 0xb9400809ULL) ^ 0x1a83c8ULL;
    acc ^= (acc >> 17) * 0x0050ULL;
    return acc;
}

// FDE #1239 | PC: 0x0e548c | FDE: 0x1a83f8 | Size: 76 bytes
// Khung tháo gỡ #1239 | Địa chỉ PC: 0x0e548c | Địa chỉ FDE: 0x1a83f8 | Kích thước: 76 bytes
//   0x0e548c: B9800808  ldrsw    x8, [x0, #8]
//   0x0e5490: B9801009  ldrsw    x9, [x0, #0x10]
//   0x0e5494: B980180A  ldrsw    x10, [x0, #0x18]
//   0x0e5498: D37DF108  lsl      x8, x8, #3
static inline uint64_t fde_func_1239_0x0e548c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e548cULL ^ (static_cast<uint64_t>(0xb9800808ULL) << 13);
    acc = (acc + a1 + 0xb9801009ULL) ^ 0x1a83f8ULL;
    acc ^= (acc >> 17) * 0x004cULL;
    return acc;
}

// FDE #1240 | PC: 0x0e54d8 | FDE: 0x1a8428 | Size: 72 bytes
// Khung tháo gỡ #1240 | Địa chỉ PC: 0x0e54d8 | Địa chỉ FDE: 0x1a8428 | Kích thước: 72 bytes
//   0x0e54d8: B9801008  ldrsw    x8, [x0, #0x10]
//   0x0e54dc: F9400409  ldr      x9, [x0, #8]
//   0x0e54e0: B980180A  ldrsw    x10, [x0, #0x18]
//   0x0e54e4: F8687828  ldr      x8, [x1, x8, lsl #3]
static inline uint64_t fde_func_1240_0x0e54d8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e54d8ULL ^ (static_cast<uint64_t>(0xb9801008ULL) << 13);
    acc = (acc + a1 + 0xf9400409ULL) ^ 0x1a8428ULL;
    acc ^= (acc >> 17) * 0x0048ULL;
    return acc;
}

// FDE #1241 | PC: 0x0e5520 | FDE: 0x1a8458 | Size: 80 bytes
// Khung tháo gỡ #1241 | Địa chỉ PC: 0x0e5520 | Địa chỉ FDE: 0x1a8458 | Kích thước: 80 bytes
//   0x0e5520: B9800808  ldrsw    x8, [x0, #8]
//   0x0e5524: B9801009  ldrsw    x9, [x0, #0x10]
//   0x0e5528: B980180A  ldrsw    x10, [x0, #0x18]
//   0x0e552c: F8687828  ldr      x8, [x1, x8, lsl #3]
static inline uint64_t fde_func_1241_0x0e5520(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e5520ULL ^ (static_cast<uint64_t>(0xb9800808ULL) << 13);
    acc = (acc + a1 + 0xb9801009ULL) ^ 0x1a8458ULL;
    acc ^= (acc >> 17) * 0x0050ULL;
    return acc;
}

// FDE #1242 | PC: 0x0e5570 | FDE: 0x1a8488 | Size: 64 bytes
// Khung tháo gỡ #1242 | Địa chỉ PC: 0x0e5570 | Địa chỉ FDE: 0x1a8488 | Kích thước: 64 bytes
//   0x0e5570: B9400808  ldr      w8, [x0, #8]
//   0x0e5574: B9401009  ldr      w9, [x0, #0x10]
//   0x0e5578: B980180A  ldrsw    x10, [x0, #0x18]
//   0x0e557c: 1AC92108  lsl      w8, w8, w9
static inline uint64_t fde_func_1242_0x0e5570(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e5570ULL ^ (static_cast<uint64_t>(0xb9400808ULL) << 13);
    acc = (acc + a1 + 0xb9401009ULL) ^ 0x1a8488ULL;
    acc ^= (acc >> 17) * 0x0040ULL;
    return acc;
}

// FDE #1243 | PC: 0x0e55b0 | FDE: 0x1a84b8 | Size: 80 bytes
// Khung tháo gỡ #1243 | Địa chỉ PC: 0x0e55b0 | Địa chỉ FDE: 0x1a84b8 | Kích thước: 80 bytes
//   0x0e55b0: B9800808  ldrsw    x8, [x0, #8]
//   0x0e55b4: B9401009  ldr      w9, [x0, #0x10]
//   0x0e55b8: B980180A  ldrsw    x10, [x0, #0x18]
//   0x0e55bc: D37DF108  lsl      x8, x8, #3
static inline uint64_t fde_func_1243_0x0e55b0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e55b0ULL ^ (static_cast<uint64_t>(0xb9800808ULL) << 13);
    acc = (acc + a1 + 0xb9401009ULL) ^ 0x1a84b8ULL;
    acc ^= (acc >> 17) * 0x0050ULL;
    return acc;
}

// FDE #1244 | PC: 0x0e5600 | FDE: 0x1a84e8 | Size: 56 bytes
// Khung tháo gỡ #1244 | Địa chỉ PC: 0x0e5600 | Địa chỉ FDE: 0x1a84e8 | Kích thước: 56 bytes
//   0x0e5600: A940A408  ldp      x8, x9, [x0, #8]
//   0x0e5604: B980180A  ldrsw    x10, [x0, #0x18]
//   0x0e5608: 9AC92108  lsl      x8, x8, x9
//   0x0e560c: F82A7828  str      x8, [x1, x10, lsl #3]
static inline uint64_t fde_func_1244_0x0e5600(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e5600ULL ^ (static_cast<uint64_t>(0xa940a408ULL) << 13);
    acc = (acc + a1 + 0xb980180aULL) ^ 0x1a84e8ULL;
    acc ^= (acc >> 17) * 0x0038ULL;
    return acc;
}

// FDE #1245 | PC: 0x0e5638 | FDE: 0x1a8518 | Size: 68 bytes
// Khung tháo gỡ #1245 | Địa chỉ PC: 0x0e5638 | Địa chỉ FDE: 0x1a8518 | Kích thước: 68 bytes
//   0x0e5638: B9800808  ldrsw    x8, [x0, #8]
//   0x0e563c: F9400809  ldr      x9, [x0, #0x10]
//   0x0e5640: B980180A  ldrsw    x10, [x0, #0x18]
//   0x0e5644: F8687828  ldr      x8, [x1, x8, lsl #3]
static inline uint64_t fde_func_1245_0x0e5638(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e5638ULL ^ (static_cast<uint64_t>(0xb9800808ULL) << 13);
    acc = (acc + a1 + 0xf9400809ULL) ^ 0x1a8518ULL;
    acc ^= (acc >> 17) * 0x0044ULL;
    return acc;
}

// FDE #1246 | PC: 0x0e567c | FDE: 0x1a8548 | Size: 68 bytes
// Khung tháo gỡ #1246 | Địa chỉ PC: 0x0e567c | Địa chỉ FDE: 0x1a8548 | Kích thước: 68 bytes
//   0x0e567c: F9400408  ldr      x8, [x0, #8]
//   0x0e5680: B000070B  adrp     x11, #0x1c6000
//   0x0e5684: 913AC16B  add      x11, x11, #0xeb0
//   0x0e5688: 79401509  ldrh     w9, [x8, #0xa]
static inline uint64_t fde_func_1246_0x0e567c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e567cULL ^ (static_cast<uint64_t>(0xf9400408ULL) << 13);
    acc = (acc + a1 + 0xb000070bULL) ^ 0x1a8548ULL;
    acc ^= (acc >> 17) * 0x0044ULL;
    return acc;
}

// FDE #1247 | PC: 0x0e56c0 | FDE: 0x1a8578 | Size: 72 bytes
// Khung tháo gỡ #1247 | Địa chỉ PC: 0x0e56c0 | Địa chỉ FDE: 0x1a8578 | Kích thước: 72 bytes
//   0x0e56c0: B9801008  ldrsw    x8, [x0, #0x10]
//   0x0e56c4: B9400809  ldr      w9, [x0, #8]
//   0x0e56c8: B980180A  ldrsw    x10, [x0, #0x18]
//   0x0e56cc: D37DF108  lsl      x8, x8, #3
static inline uint64_t fde_func_1247_0x0e56c0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e56c0ULL ^ (static_cast<uint64_t>(0xb9801008ULL) << 13);
    acc = (acc + a1 + 0xb9400809ULL) ^ 0x1a8578ULL;
    acc ^= (acc >> 17) * 0x0048ULL;
    return acc;
}

// FDE #1248 | PC: 0x0e5708 | FDE: 0x1a85a8 | Size: 68 bytes
// Khung tháo gỡ #1248 | Địa chỉ PC: 0x0e5708 | Địa chỉ FDE: 0x1a85a8 | Kích thước: 68 bytes
//   0x0e5708: B9800808  ldrsw    x8, [x0, #8]
//   0x0e570c: B9801009  ldrsw    x9, [x0, #0x10]
//   0x0e5710: B980180A  ldrsw    x10, [x0, #0x18]
//   0x0e5714: D37DF108  lsl      x8, x8, #3
static inline uint64_t fde_func_1248_0x0e5708(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e5708ULL ^ (static_cast<uint64_t>(0xb9800808ULL) << 13);
    acc = (acc + a1 + 0xb9801009ULL) ^ 0x1a85a8ULL;
    acc ^= (acc >> 17) * 0x0044ULL;
    return acc;
}

// FDE #1249 | PC: 0x0e574c | FDE: 0x1a85d8 | Size: 64 bytes
// Khung tháo gỡ #1249 | Địa chỉ PC: 0x0e574c | Địa chỉ FDE: 0x1a85d8 | Kích thước: 64 bytes
//   0x0e574c: B9801008  ldrsw    x8, [x0, #0x10]
//   0x0e5750: F9400409  ldr      x9, [x0, #8]
//   0x0e5754: B980180A  ldrsw    x10, [x0, #0x18]
//   0x0e5758: F8687828  ldr      x8, [x1, x8, lsl #3]
static inline uint64_t fde_func_1249_0x0e574c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e574cULL ^ (static_cast<uint64_t>(0xb9801008ULL) << 13);
    acc = (acc + a1 + 0xf9400409ULL) ^ 0x1a85d8ULL;
    acc ^= (acc >> 17) * 0x0040ULL;
    return acc;
}

// FDE #1250 | PC: 0x0e578c | FDE: 0x1a8608 | Size: 76 bytes
// Khung tháo gỡ #1250 | Địa chỉ PC: 0x0e578c | Địa chỉ FDE: 0x1a8608 | Kích thước: 76 bytes
//   0x0e578c: B9800808  ldrsw    x8, [x0, #8]
//   0x0e5790: B9801009  ldrsw    x9, [x0, #0x10]
//   0x0e5794: B980180A  ldrsw    x10, [x0, #0x18]
//   0x0e5798: F8687828  ldr      x8, [x1, x8, lsl #3]
static inline uint64_t fde_func_1250_0x0e578c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e578cULL ^ (static_cast<uint64_t>(0xb9800808ULL) << 13);
    acc = (acc + a1 + 0xb9801009ULL) ^ 0x1a8608ULL;
    acc ^= (acc >> 17) * 0x004cULL;
    return acc;
}

// FDE #1251 | PC: 0x0e57d8 | FDE: 0x1a8638 | Size: 64 bytes
// Khung tháo gỡ #1251 | Địa chỉ PC: 0x0e57d8 | Địa chỉ FDE: 0x1a8638 | Kích thước: 64 bytes
//   0x0e57d8: B9400808  ldr      w8, [x0, #8]
//   0x0e57dc: B9401009  ldr      w9, [x0, #0x10]
//   0x0e57e0: B980180A  ldrsw    x10, [x0, #0x18]
//   0x0e57e4: 9AC92508  lsr      x8, x8, x9
static inline uint64_t fde_func_1251_0x0e57d8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e57d8ULL ^ (static_cast<uint64_t>(0xb9400808ULL) << 13);
    acc = (acc + a1 + 0xb9401009ULL) ^ 0x1a8638ULL;
    acc ^= (acc >> 17) * 0x0040ULL;
    return acc;
}

// FDE #1252 | PC: 0x0e5818 | FDE: 0x1a8668 | Size: 80 bytes
// Khung tháo gỡ #1252 | Địa chỉ PC: 0x0e5818 | Địa chỉ FDE: 0x1a8668 | Kích thước: 80 bytes
//   0x0e5818: B9800808  ldrsw    x8, [x0, #8]
//   0x0e581c: B9401009  ldr      w9, [x0, #0x10]
//   0x0e5820: B980180A  ldrsw    x10, [x0, #0x18]
//   0x0e5824: D37DF108  lsl      x8, x8, #3
static inline uint64_t fde_func_1252_0x0e5818(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e5818ULL ^ (static_cast<uint64_t>(0xb9800808ULL) << 13);
    acc = (acc + a1 + 0xb9401009ULL) ^ 0x1a8668ULL;
    acc ^= (acc >> 17) * 0x0050ULL;
    return acc;
}

// FDE #1253 | PC: 0x0e5868 | FDE: 0x1a8698 | Size: 56 bytes
// Khung tháo gỡ #1253 | Địa chỉ PC: 0x0e5868 | Địa chỉ FDE: 0x1a8698 | Kích thước: 56 bytes
//   0x0e5868: A940A408  ldp      x8, x9, [x0, #8]
//   0x0e586c: B980180A  ldrsw    x10, [x0, #0x18]
//   0x0e5870: 9AC92508  lsr      x8, x8, x9
//   0x0e5874: F82A7828  str      x8, [x1, x10, lsl #3]
static inline uint64_t fde_func_1253_0x0e5868(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e5868ULL ^ (static_cast<uint64_t>(0xa940a408ULL) << 13);
    acc = (acc + a1 + 0xb980180aULL) ^ 0x1a8698ULL;
    acc ^= (acc >> 17) * 0x0038ULL;
    return acc;
}

// FDE #1254 | PC: 0x0e58a0 | FDE: 0x1a86c8 | Size: 68 bytes
// Khung tháo gỡ #1254 | Địa chỉ PC: 0x0e58a0 | Địa chỉ FDE: 0x1a86c8 | Kích thước: 68 bytes
//   0x0e58a0: B9800808  ldrsw    x8, [x0, #8]
//   0x0e58a4: F9400809  ldr      x9, [x0, #0x10]
//   0x0e58a8: B980180A  ldrsw    x10, [x0, #0x18]
//   0x0e58ac: F8687828  ldr      x8, [x1, x8, lsl #3]
static inline uint64_t fde_func_1254_0x0e58a0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e58a0ULL ^ (static_cast<uint64_t>(0xb9800808ULL) << 13);
    acc = (acc + a1 + 0xf9400809ULL) ^ 0x1a86c8ULL;
    acc ^= (acc >> 17) * 0x0044ULL;
    return acc;
}

// FDE #1255 | PC: 0x0e58e4 | FDE: 0x1a86f8 | Size: 72 bytes
// Khung tháo gỡ #1255 | Địa chỉ PC: 0x0e58e4 | Địa chỉ FDE: 0x1a86f8 | Kích thước: 72 bytes
//   0x0e58e4: F9400408  ldr      x8, [x0, #8]
//   0x0e58e8: B000070B  adrp     x11, #0x1c6000
//   0x0e58ec: 913EC16B  add      x11, x11, #0xfb0
//   0x0e58f0: 79401509  ldrh     w9, [x8, #0xa]
static inline uint64_t fde_func_1255_0x0e58e4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e58e4ULL ^ (static_cast<uint64_t>(0xf9400408ULL) << 13);
    acc = (acc + a1 + 0xb000070bULL) ^ 0x1a86f8ULL;
    acc ^= (acc >> 17) * 0x0048ULL;
    return acc;
}

// FDE #1256 | PC: 0x0e592c | FDE: 0x1a8728 | Size: 80 bytes
// Khung tháo gỡ #1256 | Địa chỉ PC: 0x0e592c | Địa chỉ FDE: 0x1a8728 | Kích thước: 80 bytes
//   0x0e592c: B9801008  ldrsw    x8, [x0, #0x10]
//   0x0e5930: B9400809  ldr      w9, [x0, #8]
//   0x0e5934: B980180A  ldrsw    x10, [x0, #0x18]
//   0x0e5938: D37DF108  lsl      x8, x8, #3
static inline uint64_t fde_func_1256_0x0e592c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e592cULL ^ (static_cast<uint64_t>(0xb9801008ULL) << 13);
    acc = (acc + a1 + 0xb9400809ULL) ^ 0x1a8728ULL;
    acc ^= (acc >> 17) * 0x0050ULL;
    return acc;
}

// FDE #1257 | PC: 0x0e597c | FDE: 0x1a8758 | Size: 76 bytes
// Khung tháo gỡ #1257 | Địa chỉ PC: 0x0e597c | Địa chỉ FDE: 0x1a8758 | Kích thước: 76 bytes
//   0x0e597c: B9801009  ldrsw    x9, [x0, #0x10]
//   0x0e5980: B9800808  ldrsw    x8, [x0, #8]
//   0x0e5984: B980180A  ldrsw    x10, [x0, #0x18]
//   0x0e5988: D37DF129  lsl      x9, x9, #3
static inline uint64_t fde_func_1257_0x0e597c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e597cULL ^ (static_cast<uint64_t>(0xb9801009ULL) << 13);
    acc = (acc + a1 + 0xb9800808ULL) ^ 0x1a8758ULL;
    acc ^= (acc >> 17) * 0x004cULL;
    return acc;
}

// FDE #1258 | PC: 0x0e59c8 | FDE: 0x1a8788 | Size: 72 bytes
// Khung tháo gỡ #1258 | Địa chỉ PC: 0x0e59c8 | Địa chỉ FDE: 0x1a8788 | Kích thước: 72 bytes
//   0x0e59c8: B9801008  ldrsw    x8, [x0, #0x10]
//   0x0e59cc: F9400409  ldr      x9, [x0, #8]
//   0x0e59d0: B980180A  ldrsw    x10, [x0, #0x18]
//   0x0e59d4: F8687828  ldr      x8, [x1, x8, lsl #3]
static inline uint64_t fde_func_1258_0x0e59c8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e59c8ULL ^ (static_cast<uint64_t>(0xb9801008ULL) << 13);
    acc = (acc + a1 + 0xf9400409ULL) ^ 0x1a8788ULL;
    acc ^= (acc >> 17) * 0x0048ULL;
    return acc;
}

// FDE #1259 | PC: 0x0e5a10 | FDE: 0x1a87b8 | Size: 80 bytes
// Khung tháo gỡ #1259 | Địa chỉ PC: 0x0e5a10 | Địa chỉ FDE: 0x1a87b8 | Kích thước: 80 bytes
//   0x0e5a10: B9801008  ldrsw    x8, [x0, #0x10]
//   0x0e5a14: B9800809  ldrsw    x9, [x0, #8]
//   0x0e5a18: B980180A  ldrsw    x10, [x0, #0x18]
//   0x0e5a1c: F8687828  ldr      x8, [x1, x8, lsl #3]
static inline uint64_t fde_func_1259_0x0e5a10(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e5a10ULL ^ (static_cast<uint64_t>(0xb9801008ULL) << 13);
    acc = (acc + a1 + 0xb9800809ULL) ^ 0x1a87b8ULL;
    acc ^= (acc >> 17) * 0x0050ULL;
    return acc;
}

// FDE #1260 | PC: 0x0e5a60 | FDE: 0x1a87e8 | Size: 64 bytes
// Khung tháo gỡ #1260 | Địa chỉ PC: 0x0e5a60 | Địa chỉ FDE: 0x1a87e8 | Kích thước: 64 bytes
//   0x0e5a60: B9400808  ldr      w8, [x0, #8]
//   0x0e5a64: B9401009  ldr      w9, [x0, #0x10]
//   0x0e5a68: B980180A  ldrsw    x10, [x0, #0x18]
//   0x0e5a6c: 1AC92D08  ror      w8, w8, w9
static inline uint64_t fde_func_1260_0x0e5a60(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e5a60ULL ^ (static_cast<uint64_t>(0xb9400808ULL) << 13);
    acc = (acc + a1 + 0xb9401009ULL) ^ 0x1a87e8ULL;
    acc ^= (acc >> 17) * 0x0040ULL;
    return acc;
}

// FDE #1261 | PC: 0x0e5aa0 | FDE: 0x1a8818 | Size: 80 bytes
// Khung tháo gỡ #1261 | Địa chỉ PC: 0x0e5aa0 | Địa chỉ FDE: 0x1a8818 | Kích thước: 80 bytes
//   0x0e5aa0: B9800808  ldrsw    x8, [x0, #8]
//   0x0e5aa4: B9401009  ldr      w9, [x0, #0x10]
//   0x0e5aa8: B980180A  ldrsw    x10, [x0, #0x18]
//   0x0e5aac: D37DF108  lsl      x8, x8, #3
static inline uint64_t fde_func_1261_0x0e5aa0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e5aa0ULL ^ (static_cast<uint64_t>(0xb9800808ULL) << 13);
    acc = (acc + a1 + 0xb9401009ULL) ^ 0x1a8818ULL;
    acc ^= (acc >> 17) * 0x0050ULL;
    return acc;
}

// FDE #1262 | PC: 0x0e5af0 | FDE: 0x1a8848 | Size: 56 bytes
// Khung tháo gỡ #1262 | Địa chỉ PC: 0x0e5af0 | Địa chỉ FDE: 0x1a8848 | Kích thước: 56 bytes
//   0x0e5af0: A940A408  ldp      x8, x9, [x0, #8]
//   0x0e5af4: B980180A  ldrsw    x10, [x0, #0x18]
//   0x0e5af8: 9AC92D08  ror      x8, x8, x9
//   0x0e5afc: F82A7828  str      x8, [x1, x10, lsl #3]
static inline uint64_t fde_func_1262_0x0e5af0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e5af0ULL ^ (static_cast<uint64_t>(0xa940a408ULL) << 13);
    acc = (acc + a1 + 0xb980180aULL) ^ 0x1a8848ULL;
    acc ^= (acc >> 17) * 0x0038ULL;
    return acc;
}

// FDE #1263 | PC: 0x0e5b28 | FDE: 0x1a8878 | Size: 68 bytes
// Khung tháo gỡ #1263 | Địa chỉ PC: 0x0e5b28 | Địa chỉ FDE: 0x1a8878 | Kích thước: 68 bytes
//   0x0e5b28: B9800808  ldrsw    x8, [x0, #8]
//   0x0e5b2c: F9400809  ldr      x9, [x0, #0x10]
//   0x0e5b30: B980180A  ldrsw    x10, [x0, #0x18]
//   0x0e5b34: F8687828  ldr      x8, [x1, x8, lsl #3]
static inline uint64_t fde_func_1263_0x0e5b28(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e5b28ULL ^ (static_cast<uint64_t>(0xb9800808ULL) << 13);
    acc = (acc + a1 + 0xf9400809ULL) ^ 0x1a8878ULL;
    acc ^= (acc >> 17) * 0x0044ULL;
    return acc;
}

// FDE #1264 | PC: 0x0e5b6c | FDE: 0x1a88a8 | Size: 68 bytes
// Khung tháo gỡ #1264 | Địa chỉ PC: 0x0e5b6c | Địa chỉ FDE: 0x1a88a8 | Kích thước: 68 bytes
//   0x0e5b6c: F9400408  ldr      x8, [x0, #8]
//   0x0e5b70: D000070B  adrp     x11, #0x1c7000
//   0x0e5b74: 9102C16B  add      x11, x11, #0xb0
//   0x0e5b78: 79401509  ldrh     w9, [x8, #0xa]
static inline uint64_t fde_func_1264_0x0e5b6c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e5b6cULL ^ (static_cast<uint64_t>(0xf9400408ULL) << 13);
    acc = (acc + a1 + 0xd000070bULL) ^ 0x1a88a8ULL;
    acc ^= (acc >> 17) * 0x0044ULL;
    return acc;
}

// FDE #1265 | PC: 0x0e5bb0 | FDE: 0x1a88d8 | Size: 72 bytes
// Khung tháo gỡ #1265 | Địa chỉ PC: 0x0e5bb0 | Địa chỉ FDE: 0x1a88d8 | Kích thước: 72 bytes
//   0x0e5bb0: B9801008  ldrsw    x8, [x0, #0x10]
//   0x0e5bb4: B9400809  ldr      w9, [x0, #8]
//   0x0e5bb8: B980180A  ldrsw    x10, [x0, #0x18]
//   0x0e5bbc: D37DF108  lsl      x8, x8, #3
static inline uint64_t fde_func_1265_0x0e5bb0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e5bb0ULL ^ (static_cast<uint64_t>(0xb9801008ULL) << 13);
    acc = (acc + a1 + 0xb9400809ULL) ^ 0x1a88d8ULL;
    acc ^= (acc >> 17) * 0x0048ULL;
    return acc;
}

// FDE #1266 | PC: 0x0e5bf8 | FDE: 0x1a8908 | Size: 68 bytes
// Khung tháo gỡ #1266 | Địa chỉ PC: 0x0e5bf8 | Địa chỉ FDE: 0x1a8908 | Kích thước: 68 bytes
//   0x0e5bf8: B9800808  ldrsw    x8, [x0, #8]
//   0x0e5bfc: B9801009  ldrsw    x9, [x0, #0x10]
//   0x0e5c00: B980180A  ldrsw    x10, [x0, #0x18]
//   0x0e5c04: D37DF108  lsl      x8, x8, #3
static inline uint64_t fde_func_1266_0x0e5bf8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e5bf8ULL ^ (static_cast<uint64_t>(0xb9800808ULL) << 13);
    acc = (acc + a1 + 0xb9801009ULL) ^ 0x1a8908ULL;
    acc ^= (acc >> 17) * 0x0044ULL;
    return acc;
}

// FDE #1267 | PC: 0x0e5c3c | FDE: 0x1a8938 | Size: 64 bytes
// Khung tháo gỡ #1267 | Địa chỉ PC: 0x0e5c3c | Địa chỉ FDE: 0x1a8938 | Kích thước: 64 bytes
//   0x0e5c3c: B9801008  ldrsw    x8, [x0, #0x10]
//   0x0e5c40: F9400409  ldr      x9, [x0, #8]
//   0x0e5c44: B980180A  ldrsw    x10, [x0, #0x18]
//   0x0e5c48: F8687828  ldr      x8, [x1, x8, lsl #3]
static inline uint64_t fde_func_1267_0x0e5c3c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e5c3cULL ^ (static_cast<uint64_t>(0xb9801008ULL) << 13);
    acc = (acc + a1 + 0xf9400409ULL) ^ 0x1a8938ULL;
    acc ^= (acc >> 17) * 0x0040ULL;
    return acc;
}

// FDE #1268 | PC: 0x0e5c7c | FDE: 0x1a8968 | Size: 76 bytes
// Khung tháo gỡ #1268 | Địa chỉ PC: 0x0e5c7c | Địa chỉ FDE: 0x1a8968 | Kích thước: 76 bytes
//   0x0e5c7c: B9800808  ldrsw    x8, [x0, #8]
//   0x0e5c80: B9801009  ldrsw    x9, [x0, #0x10]
//   0x0e5c84: B980180A  ldrsw    x10, [x0, #0x18]
//   0x0e5c88: F8687828  ldr      x8, [x1, x8, lsl #3]
static inline uint64_t fde_func_1268_0x0e5c7c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e5c7cULL ^ (static_cast<uint64_t>(0xb9800808ULL) << 13);
    acc = (acc + a1 + 0xb9801009ULL) ^ 0x1a8968ULL;
    acc ^= (acc >> 17) * 0x004cULL;
    return acc;
}

// FDE #1269 | PC: 0x0e5cc8 | FDE: 0x1a8998 | Size: 64 bytes
// Khung tháo gỡ #1269 | Địa chỉ PC: 0x0e5cc8 | Địa chỉ FDE: 0x1a8998 | Kích thước: 64 bytes
//   0x0e5cc8: B9400808  ldr      w8, [x0, #8]
//   0x0e5ccc: B9401009  ldr      w9, [x0, #0x10]
//   0x0e5cd0: B980180A  ldrsw    x10, [x0, #0x18]
//   0x0e5cd4: 4A080128  eor      w8, w9, w8
static inline uint64_t fde_func_1269_0x0e5cc8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e5cc8ULL ^ (static_cast<uint64_t>(0xb9400808ULL) << 13);
    acc = (acc + a1 + 0xb9401009ULL) ^ 0x1a8998ULL;
    acc ^= (acc >> 17) * 0x0040ULL;
    return acc;
}

// FDE #1270 | PC: 0x0e5d08 | FDE: 0x1a89c8 | Size: 80 bytes
// Khung tháo gỡ #1270 | Địa chỉ PC: 0x0e5d08 | Địa chỉ FDE: 0x1a89c8 | Kích thước: 80 bytes
//   0x0e5d08: B9800808  ldrsw    x8, [x0, #8]
//   0x0e5d0c: B9401009  ldr      w9, [x0, #0x10]
//   0x0e5d10: B980180A  ldrsw    x10, [x0, #0x18]
//   0x0e5d14: D37DF108  lsl      x8, x8, #3
static inline uint64_t fde_func_1270_0x0e5d08(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e5d08ULL ^ (static_cast<uint64_t>(0xb9800808ULL) << 13);
    acc = (acc + a1 + 0xb9401009ULL) ^ 0x1a89c8ULL;
    acc ^= (acc >> 17) * 0x0050ULL;
    return acc;
}

// FDE #1271 | PC: 0x0e5d58 | FDE: 0x1a89f8 | Size: 56 bytes
// Khung tháo gỡ #1271 | Địa chỉ PC: 0x0e5d58 | Địa chỉ FDE: 0x1a89f8 | Kích thước: 56 bytes
//   0x0e5d58: A940A408  ldp      x8, x9, [x0, #8]
//   0x0e5d5c: B980180A  ldrsw    x10, [x0, #0x18]
//   0x0e5d60: CA080128  eor      x8, x9, x8
//   0x0e5d64: F82A7828  str      x8, [x1, x10, lsl #3]
static inline uint64_t fde_func_1271_0x0e5d58(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e5d58ULL ^ (static_cast<uint64_t>(0xa940a408ULL) << 13);
    acc = (acc + a1 + 0xb980180aULL) ^ 0x1a89f8ULL;
    acc ^= (acc >> 17) * 0x0038ULL;
    return acc;
}

// FDE #1272 | PC: 0x0e5d90 | FDE: 0x1a8a28 | Size: 68 bytes
// Khung tháo gỡ #1272 | Địa chỉ PC: 0x0e5d90 | Địa chỉ FDE: 0x1a8a28 | Kích thước: 68 bytes
//   0x0e5d90: B9800808  ldrsw    x8, [x0, #8]
//   0x0e5d94: F9400809  ldr      x9, [x0, #0x10]
//   0x0e5d98: B980180A  ldrsw    x10, [x0, #0x18]
//   0x0e5d9c: F8687828  ldr      x8, [x1, x8, lsl #3]
static inline uint64_t fde_func_1272_0x0e5d90(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e5d90ULL ^ (static_cast<uint64_t>(0xb9800808ULL) << 13);
    acc = (acc + a1 + 0xf9400809ULL) ^ 0x1a8a28ULL;
    acc ^= (acc >> 17) * 0x0044ULL;
    return acc;
}

// FDE #1273 | PC: 0x0e5dd4 | FDE: 0x1a8a58 | Size: 68 bytes
// Khung tháo gỡ #1273 | Địa chỉ PC: 0x0e5dd4 | Địa chỉ FDE: 0x1a8a58 | Kích thước: 68 bytes
//   0x0e5dd4: F9400408  ldr      x8, [x0, #8]
//   0x0e5dd8: D000070B  adrp     x11, #0x1c7000
//   0x0e5ddc: 9106C16B  add      x11, x11, #0x1b0
//   0x0e5de0: 79401509  ldrh     w9, [x8, #0xa]
static inline uint64_t fde_func_1273_0x0e5dd4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e5dd4ULL ^ (static_cast<uint64_t>(0xf9400408ULL) << 13);
    acc = (acc + a1 + 0xd000070bULL) ^ 0x1a8a58ULL;
    acc ^= (acc >> 17) * 0x0044ULL;
    return acc;
}

// FDE #1274 | PC: 0x0e5e18 | FDE: 0x1a8a88 | Size: 72 bytes
// Khung tháo gỡ #1274 | Địa chỉ PC: 0x0e5e18 | Địa chỉ FDE: 0x1a8a88 | Kích thước: 72 bytes
//   0x0e5e18: B9801008  ldrsw    x8, [x0, #0x10]
//   0x0e5e1c: B9400809  ldr      w9, [x0, #8]
//   0x0e5e20: B980180A  ldrsw    x10, [x0, #0x18]
//   0x0e5e24: D37DF108  lsl      x8, x8, #3
static inline uint64_t fde_func_1274_0x0e5e18(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e5e18ULL ^ (static_cast<uint64_t>(0xb9801008ULL) << 13);
    acc = (acc + a1 + 0xb9400809ULL) ^ 0x1a8a88ULL;
    acc ^= (acc >> 17) * 0x0048ULL;
    return acc;
}

// FDE #1275 | PC: 0x0e5e60 | FDE: 0x1a8ab8 | Size: 68 bytes
// Khung tháo gỡ #1275 | Địa chỉ PC: 0x0e5e60 | Địa chỉ FDE: 0x1a8ab8 | Kích thước: 68 bytes
//   0x0e5e60: B9800808  ldrsw    x8, [x0, #8]
//   0x0e5e64: B9801009  ldrsw    x9, [x0, #0x10]
//   0x0e5e68: B980180A  ldrsw    x10, [x0, #0x18]
//   0x0e5e6c: D37DF108  lsl      x8, x8, #3
static inline uint64_t fde_func_1275_0x0e5e60(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e5e60ULL ^ (static_cast<uint64_t>(0xb9800808ULL) << 13);
    acc = (acc + a1 + 0xb9801009ULL) ^ 0x1a8ab8ULL;
    acc ^= (acc >> 17) * 0x0044ULL;
    return acc;
}

// FDE #1276 | PC: 0x0e5ea4 | FDE: 0x1a8ae8 | Size: 64 bytes
// Khung tháo gỡ #1276 | Địa chỉ PC: 0x0e5ea4 | Địa chỉ FDE: 0x1a8ae8 | Kích thước: 64 bytes
//   0x0e5ea4: B9801008  ldrsw    x8, [x0, #0x10]
//   0x0e5ea8: F9400409  ldr      x9, [x0, #8]
//   0x0e5eac: B980180A  ldrsw    x10, [x0, #0x18]
//   0x0e5eb0: F8687828  ldr      x8, [x1, x8, lsl #3]
static inline uint64_t fde_func_1276_0x0e5ea4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e5ea4ULL ^ (static_cast<uint64_t>(0xb9801008ULL) << 13);
    acc = (acc + a1 + 0xf9400409ULL) ^ 0x1a8ae8ULL;
    acc ^= (acc >> 17) * 0x0040ULL;
    return acc;
}

// FDE #1277 | PC: 0x0e5ee4 | FDE: 0x1a8b18 | Size: 76 bytes
// Khung tháo gỡ #1277 | Địa chỉ PC: 0x0e5ee4 | Địa chỉ FDE: 0x1a8b18 | Kích thước: 76 bytes
//   0x0e5ee4: B9800808  ldrsw    x8, [x0, #8]
//   0x0e5ee8: B9801009  ldrsw    x9, [x0, #0x10]
//   0x0e5eec: B980180A  ldrsw    x10, [x0, #0x18]
//   0x0e5ef0: F8687828  ldr      x8, [x1, x8, lsl #3]
static inline uint64_t fde_func_1277_0x0e5ee4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e5ee4ULL ^ (static_cast<uint64_t>(0xb9800808ULL) << 13);
    acc = (acc + a1 + 0xb9801009ULL) ^ 0x1a8b18ULL;
    acc ^= (acc >> 17) * 0x004cULL;
    return acc;
}

// FDE #1278 | PC: 0x0e5f30 | FDE: 0x1a8b48 | Size: 72 bytes
// Khung tháo gỡ #1278 | Địa chỉ PC: 0x0e5f30 | Địa chỉ FDE: 0x1a8b48 | Kích thước: 72 bytes
//   0x0e5f30: BD400800  ldr      s0, [x0, #8]
//   0x0e5f34: BD401001  ldr      s1, [x0, #0x10]
//   0x0e5f38: B9801808  ldrsw    x8, [x0, #0x18]
//   0x0e5f3c: 1E216800  fmaxnm   s0, s0, s1
static inline uint64_t fde_func_1278_0x0e5f30(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e5f30ULL ^ (static_cast<uint64_t>(0xbd400800ULL) << 13);
    acc = (acc + a1 + 0xbd401001ULL) ^ 0x1a8b48ULL;
    acc ^= (acc >> 17) * 0x0048ULL;
    return acc;
}

// FDE #1279 | PC: 0x0e5f78 | FDE: 0x1a8b78 | Size: 88 bytes
// Khung tháo gỡ #1279 | Địa chỉ PC: 0x0e5f78 | Địa chỉ FDE: 0x1a8b78 | Kích thước: 88 bytes
//   0x0e5f78: B9800808  ldrsw    x8, [x0, #8]
//   0x0e5f7c: BD401000  ldr      s0, [x0, #0x10]
//   0x0e5f80: D37DF108  lsl      x8, x8, #3
//   0x0e5f84: BC686821  ldr      s1, [x1, x8]
static inline uint64_t fde_func_1279_0x0e5f78(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e5f78ULL ^ (static_cast<uint64_t>(0xb9800808ULL) << 13);
    acc = (acc + a1 + 0xbd401000ULL) ^ 0x1a8b78ULL;
    acc ^= (acc >> 17) * 0x0058ULL;
    return acc;
}

// FDE #1280 | PC: 0x0e5fd0 | FDE: 0x1a8ba8 | Size: 56 bytes
// Khung tháo gỡ #1280 | Địa chỉ PC: 0x0e5fd0 | Địa chỉ FDE: 0x1a8ba8 | Kích thước: 56 bytes
//   0x0e5fd0: 6D408400  ldp      d0, d1, [x0, #8]
//   0x0e5fd4: B9801808  ldrsw    x8, [x0, #0x18]
//   0x0e5fd8: 1E616800  fmaxnm   d0, d0, d1
//   0x0e5fdc: FC287820  str      d0, [x1, x8, lsl #3]
static inline uint64_t fde_func_1280_0x0e5fd0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e5fd0ULL ^ (static_cast<uint64_t>(0x6d408400ULL) << 13);
    acc = (acc + a1 + 0xb9801808ULL) ^ 0x1a8ba8ULL;
    acc ^= (acc >> 17) * 0x0038ULL;
    return acc;
}

// FDE #1281 | PC: 0x0e6008 | FDE: 0x1a8bd8 | Size: 68 bytes
// Khung tháo gỡ #1281 | Địa chỉ PC: 0x0e6008 | Địa chỉ FDE: 0x1a8bd8 | Kích thước: 68 bytes
//   0x0e6008: B9800808  ldrsw    x8, [x0, #8]
//   0x0e600c: FD400801  ldr      d1, [x0, #0x10]
//   0x0e6010: FC687820  ldr      d0, [x1, x8, lsl #3]
//   0x0e6014: B9801808  ldrsw    x8, [x0, #0x18]
static inline uint64_t fde_func_1281_0x0e6008(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e6008ULL ^ (static_cast<uint64_t>(0xb9800808ULL) << 13);
    acc = (acc + a1 + 0xfd400801ULL) ^ 0x1a8bd8ULL;
    acc ^= (acc >> 17) * 0x0044ULL;
    return acc;
}

// FDE #1282 | PC: 0x0e604c | FDE: 0x1a8c08 | Size: 72 bytes
// Khung tháo gỡ #1282 | Địa chỉ PC: 0x0e604c | Địa chỉ FDE: 0x1a8c08 | Kích thước: 72 bytes
//   0x0e604c: F9400408  ldr      x8, [x0, #8]
//   0x0e6050: B000070B  adrp     x11, #0x1c7000
//   0x0e6054: 910AC16B  add      x11, x11, #0x2b0
//   0x0e6058: 79401509  ldrh     w9, [x8, #0xa]
static inline uint64_t fde_func_1282_0x0e604c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e604cULL ^ (static_cast<uint64_t>(0xf9400408ULL) << 13);
    acc = (acc + a1 + 0xb000070bULL) ^ 0x1a8c08ULL;
    acc ^= (acc >> 17) * 0x0048ULL;
    return acc;
}

// FDE #1283 | PC: 0x0e6094 | FDE: 0x1a8c38 | Size: 80 bytes
// Khung tháo gỡ #1283 | Địa chỉ PC: 0x0e6094 | Địa chỉ FDE: 0x1a8c38 | Kích thước: 80 bytes
//   0x0e6094: B9801008  ldrsw    x8, [x0, #0x10]
//   0x0e6098: BD400800  ldr      s0, [x0, #8]
//   0x0e609c: D37DF108  lsl      x8, x8, #3
//   0x0e60a0: BC686821  ldr      s1, [x1, x8]
static inline uint64_t fde_func_1283_0x0e6094(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e6094ULL ^ (static_cast<uint64_t>(0xb9801008ULL) << 13);
    acc = (acc + a1 + 0xbd400800ULL) ^ 0x1a8c38ULL;
    acc ^= (acc >> 17) * 0x0050ULL;
    return acc;
}

// FDE #1284 | PC: 0x0e60e4 | FDE: 0x1a8c68 | Size: 72 bytes
// Khung tháo gỡ #1284 | Địa chỉ PC: 0x0e60e4 | Địa chỉ FDE: 0x1a8c68 | Kích thước: 72 bytes
//   0x0e60e4: B9800808  ldrsw    x8, [x0, #8]
//   0x0e60e8: B9801009  ldrsw    x9, [x0, #0x10]
//   0x0e60ec: D37DF108  lsl      x8, x8, #3
//   0x0e60f0: D37DF129  lsl      x9, x9, #3
static inline uint64_t fde_func_1284_0x0e60e4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e60e4ULL ^ (static_cast<uint64_t>(0xb9800808ULL) << 13);
    acc = (acc + a1 + 0xb9801009ULL) ^ 0x1a8c68ULL;
    acc ^= (acc >> 17) * 0x0048ULL;
    return acc;
}

// FDE #1285 | PC: 0x0e612c | FDE: 0x1a8c98 | Size: 64 bytes
// Khung tháo gỡ #1285 | Địa chỉ PC: 0x0e612c | Địa chỉ FDE: 0x1a8c98 | Kích thước: 64 bytes
//   0x0e612c: B9801008  ldrsw    x8, [x0, #0x10]
//   0x0e6130: FD400400  ldr      d0, [x0, #8]
//   0x0e6134: FC687821  ldr      d1, [x1, x8, lsl #3]
//   0x0e6138: B9801808  ldrsw    x8, [x0, #0x18]
static inline uint64_t fde_func_1285_0x0e612c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e612cULL ^ (static_cast<uint64_t>(0xb9801008ULL) << 13);
    acc = (acc + a1 + 0xfd400400ULL) ^ 0x1a8c98ULL;
    acc ^= (acc >> 17) * 0x0040ULL;
    return acc;
}

// FDE #1286 | PC: 0x0e616c | FDE: 0x1a8cc8 | Size: 76 bytes
// Khung tháo gỡ #1286 | Địa chỉ PC: 0x0e616c | Địa chỉ FDE: 0x1a8cc8 | Kích thước: 76 bytes
//   0x0e616c: B9800808  ldrsw    x8, [x0, #8]
//   0x0e6170: B9801009  ldrsw    x9, [x0, #0x10]
//   0x0e6174: FC687820  ldr      d0, [x1, x8, lsl #3]
//   0x0e6178: FC697821  ldr      d1, [x1, x9, lsl #3]
static inline uint64_t fde_func_1286_0x0e616c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e616cULL ^ (static_cast<uint64_t>(0xb9800808ULL) << 13);
    acc = (acc + a1 + 0xb9801009ULL) ^ 0x1a8cc8ULL;
    acc ^= (acc >> 17) * 0x004cULL;
    return acc;
}

// FDE #1287 | PC: 0x0e61b8 | FDE: 0x1a8cf8 | Size: 72 bytes
// Khung tháo gỡ #1287 | Địa chỉ PC: 0x0e61b8 | Địa chỉ FDE: 0x1a8cf8 | Kích thước: 72 bytes
//   0x0e61b8: BD400800  ldr      s0, [x0, #8]
//   0x0e61bc: BD401001  ldr      s1, [x0, #0x10]
//   0x0e61c0: B9801808  ldrsw    x8, [x0, #0x18]
//   0x0e61c4: 1E211800  fdiv     s0, s0, s1
static inline uint64_t fde_func_1287_0x0e61b8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e61b8ULL ^ (static_cast<uint64_t>(0xbd400800ULL) << 13);
    acc = (acc + a1 + 0xbd401001ULL) ^ 0x1a8cf8ULL;
    acc ^= (acc >> 17) * 0x0048ULL;
    return acc;
}

// FDE #1288 | PC: 0x0e6200 | FDE: 0x1a8d28 | Size: 88 bytes
// Khung tháo gỡ #1288 | Địa chỉ PC: 0x0e6200 | Địa chỉ FDE: 0x1a8d28 | Kích thước: 88 bytes
//   0x0e6200: B9800808  ldrsw    x8, [x0, #8]
//   0x0e6204: BD401000  ldr      s0, [x0, #0x10]
//   0x0e6208: D37DF108  lsl      x8, x8, #3
//   0x0e620c: BC686821  ldr      s1, [x1, x8]
static inline uint64_t fde_func_1288_0x0e6200(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e6200ULL ^ (static_cast<uint64_t>(0xb9800808ULL) << 13);
    acc = (acc + a1 + 0xbd401000ULL) ^ 0x1a8d28ULL;
    acc ^= (acc >> 17) * 0x0058ULL;
    return acc;
}

// FDE #1289 | PC: 0x0e6258 | FDE: 0x1a8d58 | Size: 56 bytes
// Khung tháo gỡ #1289 | Địa chỉ PC: 0x0e6258 | Địa chỉ FDE: 0x1a8d58 | Kích thước: 56 bytes
//   0x0e6258: 6D408400  ldp      d0, d1, [x0, #8]
//   0x0e625c: B9801808  ldrsw    x8, [x0, #0x18]
//   0x0e6260: 1E611800  fdiv     d0, d0, d1
//   0x0e6264: FC287820  str      d0, [x1, x8, lsl #3]
static inline uint64_t fde_func_1289_0x0e6258(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e6258ULL ^ (static_cast<uint64_t>(0x6d408400ULL) << 13);
    acc = (acc + a1 + 0xb9801808ULL) ^ 0x1a8d58ULL;
    acc ^= (acc >> 17) * 0x0038ULL;
    return acc;
}

// FDE #1290 | PC: 0x0e6290 | FDE: 0x1a8d88 | Size: 68 bytes
// Khung tháo gỡ #1290 | Địa chỉ PC: 0x0e6290 | Địa chỉ FDE: 0x1a8d88 | Kích thước: 68 bytes
//   0x0e6290: B9800808  ldrsw    x8, [x0, #8]
//   0x0e6294: FD400801  ldr      d1, [x0, #0x10]
//   0x0e6298: FC687820  ldr      d0, [x1, x8, lsl #3]
//   0x0e629c: B9801808  ldrsw    x8, [x0, #0x18]
static inline uint64_t fde_func_1290_0x0e6290(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e6290ULL ^ (static_cast<uint64_t>(0xb9800808ULL) << 13);
    acc = (acc + a1 + 0xfd400801ULL) ^ 0x1a8d88ULL;
    acc ^= (acc >> 17) * 0x0044ULL;
    return acc;
}

// FDE #1291 | PC: 0x0e62d4 | FDE: 0x1a8db8 | Size: 76 bytes
// Khung tháo gỡ #1291 | Địa chỉ PC: 0x0e62d4 | Địa chỉ FDE: 0x1a8db8 | Kích thước: 76 bytes
//   0x0e62d4: F9400408  ldr      x8, [x0, #8]
//   0x0e62d8: B000070B  adrp     x11, #0x1c7000
//   0x0e62dc: 910EC16B  add      x11, x11, #0x3b0
//   0x0e62e0: 79401509  ldrh     w9, [x8, #0xa]
static inline uint64_t fde_func_1291_0x0e62d4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e62d4ULL ^ (static_cast<uint64_t>(0xf9400408ULL) << 13);
    acc = (acc + a1 + 0xb000070bULL) ^ 0x1a8db8ULL;
    acc ^= (acc >> 17) * 0x004cULL;
    return acc;
}

// FDE #1292 | PC: 0x0e6320 | FDE: 0x1a8de8 | Size: 88 bytes
// Khung tháo gỡ #1292 | Địa chỉ PC: 0x0e6320 | Địa chỉ FDE: 0x1a8de8 | Kích thước: 88 bytes
//   0x0e6320: B9801008  ldrsw    x8, [x0, #0x10]
//   0x0e6324: BD400800  ldr      s0, [x0, #8]
//   0x0e6328: 4F046402  movi     v2.4s, #0x80, lsl #24
//   0x0e632c: D37DF108  lsl      x8, x8, #3
static inline uint64_t fde_func_1292_0x0e6320(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e6320ULL ^ (static_cast<uint64_t>(0xb9801008ULL) << 13);
    acc = (acc + a1 + 0xbd400800ULL) ^ 0x1a8de8ULL;
    acc ^= (acc >> 17) * 0x0058ULL;
    return acc;
}

// FDE #1293 | PC: 0x0e6378 | FDE: 0x1a8e18 | Size: 84 bytes
// Khung tháo gỡ #1293 | Địa chỉ PC: 0x0e6378 | Địa chỉ FDE: 0x1a8e18 | Kích thước: 84 bytes
//   0x0e6378: B9800808  ldrsw    x8, [x0, #8]
//   0x0e637c: B9801009  ldrsw    x9, [x0, #0x10]
//   0x0e6380: 4F046402  movi     v2.4s, #0x80, lsl #24
//   0x0e6384: D37DF108  lsl      x8, x8, #3
static inline uint64_t fde_func_1293_0x0e6378(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e6378ULL ^ (static_cast<uint64_t>(0xb9800808ULL) << 13);
    acc = (acc + a1 + 0xb9801009ULL) ^ 0x1a8e18ULL;
    acc ^= (acc >> 17) * 0x0054ULL;
    return acc;
}

// FDE #1294 | PC: 0x0e63cc | FDE: 0x1a8e48 | Size: 80 bytes
// Khung tháo gỡ #1294 | Địa chỉ PC: 0x0e63cc | Địa chỉ FDE: 0x1a8e48 | Kích thước: 80 bytes
//   0x0e63cc: B9801008  ldrsw    x8, [x0, #0x10]
//   0x0e63d0: FD400400  ldr      d0, [x0, #8]
//   0x0e63d4: 6F00E402  movi     v2.2d, #0000000000000000
//   0x0e63d8: 6EE0F842  fneg     v2.2d, v2.2d
static inline uint64_t fde_func_1294_0x0e63cc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e63ccULL ^ (static_cast<uint64_t>(0xb9801008ULL) << 13);
    acc = (acc + a1 + 0xfd400400ULL) ^ 0x1a8e48ULL;
    acc ^= (acc >> 17) * 0x0050ULL;
    return acc;
}

// FDE #1295 | PC: 0x0e641c | FDE: 0x1a8e78 | Size: 104 bytes
// Khung tháo gỡ #1295 | Địa chỉ PC: 0x0e641c | Địa chỉ FDE: 0x1a8e78 | Kích thước: 104 bytes
//   0x0e641c: B9800808  ldrsw    x8, [x0, #8]
//   0x0e6420: B9801009  ldrsw    x9, [x0, #0x10]
//   0x0e6424: 6F00E402  movi     v2.2d, #0000000000000000
//   0x0e6428: 6EE0F842  fneg     v2.2d, v2.2d
static inline uint64_t fde_func_1295_0x0e641c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e641cULL ^ (static_cast<uint64_t>(0xb9800808ULL) << 13);
    acc = (acc + a1 + 0xb9801009ULL) ^ 0x1a8e78ULL;
    acc ^= (acc >> 17) * 0x0068ULL;
    return acc;
}

// FDE #1296 | PC: 0x0e6484 | FDE: 0x1a8ea8 | Size: 88 bytes
// Khung tháo gỡ #1296 | Địa chỉ PC: 0x0e6484 | Địa chỉ FDE: 0x1a8ea8 | Kích thước: 88 bytes
//   0x0e6484: B9801008  ldrsw    x8, [x0, #0x10]
//   0x0e6488: B9400809  ldr      w9, [x0, #8]
//   0x0e648c: D37DF108  lsl      x8, x8, #3
//   0x0e6490: B8686828  ldr      w8, [x1, x8]
static inline uint64_t fde_func_1296_0x0e6484(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e6484ULL ^ (static_cast<uint64_t>(0xb9801008ULL) << 13);
    acc = (acc + a1 + 0xb9400809ULL) ^ 0x1a8ea8ULL;
    acc ^= (acc >> 17) * 0x0058ULL;
    return acc;
}

// FDE #1297 | PC: 0x0e64dc | FDE: 0x1a8ed8 | Size: 92 bytes
// Khung tháo gỡ #1297 | Địa chỉ PC: 0x0e64dc | Địa chỉ FDE: 0x1a8ed8 | Kích thước: 92 bytes
//   0x0e64dc: B9800808  ldrsw    x8, [x0, #8]
//   0x0e64e0: B9801009  ldrsw    x9, [x0, #0x10]
//   0x0e64e4: D37DF108  lsl      x8, x8, #3
//   0x0e64e8: D37DF129  lsl      x9, x9, #3
static inline uint64_t fde_func_1297_0x0e64dc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e64dcULL ^ (static_cast<uint64_t>(0xb9800808ULL) << 13);
    acc = (acc + a1 + 0xb9801009ULL) ^ 0x1a8ed8ULL;
    acc ^= (acc >> 17) * 0x005cULL;
    return acc;
}

// FDE #1298 | PC: 0x0e6538 | FDE: 0x1a8f08 | Size: 84 bytes
// Khung tháo gỡ #1298 | Địa chỉ PC: 0x0e6538 | Địa chỉ FDE: 0x1a8f08 | Kích thước: 84 bytes
//   0x0e6538: B9800808  ldrsw    x8, [x0, #8]
//   0x0e653c: F9400809  ldr      x9, [x0, #0x10]
//   0x0e6540: F8687828  ldr      x8, [x1, x8, lsl #3]
//   0x0e6544: EB09011F  cmp      x8, x9
static inline uint64_t fde_func_1298_0x0e6538(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e6538ULL ^ (static_cast<uint64_t>(0xb9800808ULL) << 13);
    acc = (acc + a1 + 0xf9400809ULL) ^ 0x1a8f08ULL;
    acc ^= (acc >> 17) * 0x0054ULL;
    return acc;
}

// FDE #1299 | PC: 0x0e658c | FDE: 0x1a8f38 | Size: 88 bytes
// Khung tháo gỡ #1299 | Địa chỉ PC: 0x0e658c | Địa chỉ FDE: 0x1a8f38 | Kích thước: 88 bytes
//   0x0e658c: B9801008  ldrsw    x8, [x0, #0x10]
//   0x0e6590: BD400800  ldr      s0, [x0, #8]
//   0x0e6594: 52800309  mov      w9, #0x18
//   0x0e6598: D37DF108  lsl      x8, x8, #3
static inline uint64_t fde_func_1299_0x0e658c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e658cULL ^ (static_cast<uint64_t>(0xb9801008ULL) << 13);
    acc = (acc + a1 + 0xbd400800ULL) ^ 0x1a8f38ULL;
    acc ^= (acc >> 17) * 0x0058ULL;
    return acc;
}

// FDE #1300 | PC: 0x0e65e4 | FDE: 0x1a8f68 | Size: 92 bytes
// Khung tháo gỡ #1300 | Địa chỉ PC: 0x0e65e4 | Địa chỉ FDE: 0x1a8f68 | Kích thước: 92 bytes
//   0x0e65e4: B9800808  ldrsw    x8, [x0, #8]
//   0x0e65e8: B9801009  ldrsw    x9, [x0, #0x10]
//   0x0e65ec: D37DF108  lsl      x8, x8, #3
//   0x0e65f0: D37DF129  lsl      x9, x9, #3
static inline uint64_t fde_func_1300_0x0e65e4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e65e4ULL ^ (static_cast<uint64_t>(0xb9800808ULL) << 13);
    acc = (acc + a1 + 0xb9801009ULL) ^ 0x1a8f68ULL;
    acc ^= (acc >> 17) * 0x005cULL;
    return acc;
}

// FDE #1301 | PC: 0x0e6640 | FDE: 0x1a8f98 | Size: 84 bytes
// Khung tháo gỡ #1301 | Địa chỉ PC: 0x0e6640 | Địa chỉ FDE: 0x1a8f98 | Kích thước: 84 bytes
//   0x0e6640: B9800808  ldrsw    x8, [x0, #8]
//   0x0e6644: FD400800  ldr      d0, [x0, #0x10]
//   0x0e6648: 52800309  mov      w9, #0x18
//   0x0e664c: FC687821  ldr      d1, [x1, x8, lsl #3]
static inline uint64_t fde_func_1301_0x0e6640(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e6640ULL ^ (static_cast<uint64_t>(0xb9800808ULL) << 13);
    acc = (acc + a1 + 0xfd400800ULL) ^ 0x1a8f98ULL;
    acc ^= (acc >> 17) * 0x0054ULL;
    return acc;
}

// FDE #1302 | PC: 0x0e6694 | FDE: 0x1a8fc8 | Size: 104 bytes
// Khung tháo gỡ #1302 | Địa chỉ PC: 0x0e6694 | Địa chỉ FDE: 0x1a8fc8 | Kích thước: 104 bytes
//   0x0e6694: F9400409  ldr      x9, [x0, #8]
//   0x0e6698: 3940012A  ldrb     w10, [x9]
//   0x0e669c: 79401528  ldrh     w8, [x9, #0xa]
//   0x0e66a0: 3400008A  cbz      w10, #0xe66b0
static inline uint64_t fde_func_1302_0x0e6694(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e6694ULL ^ (static_cast<uint64_t>(0xf9400409ULL) << 13);
    acc = (acc + a1 + 0x3940012aULL) ^ 0x1a8fc8ULL;
    acc ^= (acc >> 17) * 0x0068ULL;
    return acc;
}

// FDE #1303 | PC: 0x0e66fc | FDE: 0x1a8ff8 | Size: 96 bytes
// Khung tháo gỡ #1303 | Địa chỉ PC: 0x0e66fc | Địa chỉ FDE: 0x1a8ff8 | Kích thước: 96 bytes
//   0x0e66fc: B9800808  ldrsw    x8, [x0, #8]
//   0x0e6700: B9401009  ldr      w9, [x0, #0x10]
//   0x0e6704: D37DF108  lsl      x8, x8, #3
//   0x0e6708: B8686828  ldr      w8, [x1, x8]
static inline uint64_t fde_func_1303_0x0e66fc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e66fcULL ^ (static_cast<uint64_t>(0xb9800808ULL) << 13);
    acc = (acc + a1 + 0xb9401009ULL) ^ 0x1a8ff8ULL;
    acc ^= (acc >> 17) * 0x0060ULL;
    return acc;
}

// FDE #1304 | PC: 0x0e675c | FDE: 0x1a9028 | Size: 80 bytes
// Khung tháo gỡ #1304 | Địa chỉ PC: 0x0e675c | Địa chỉ FDE: 0x1a9028 | Kích thước: 80 bytes
//   0x0e675c: B9801008  ldrsw    x8, [x0, #0x10]
//   0x0e6760: F9400409  ldr      x9, [x0, #8]
//   0x0e6764: F8687828  ldr      x8, [x1, x8, lsl #3]
//   0x0e6768: EB08013F  cmp      x9, x8
static inline uint64_t fde_func_1304_0x0e675c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e675cULL ^ (static_cast<uint64_t>(0xb9801008ULL) << 13);
    acc = (acc + a1 + 0xf9400409ULL) ^ 0x1a9028ULL;
    acc ^= (acc >> 17) * 0x0050ULL;
    return acc;
}

// FDE #1305 | PC: 0x0e67ac | FDE: 0x1a9058 | Size: 88 bytes
// Khung tháo gỡ #1305 | Địa chỉ PC: 0x0e67ac | Địa chỉ FDE: 0x1a9058 | Kích thước: 88 bytes
//   0x0e67ac: B9800808  ldrsw    x8, [x0, #8]
//   0x0e67b0: B9801009  ldrsw    x9, [x0, #0x10]
//   0x0e67b4: F8687828  ldr      x8, [x1, x8, lsl #3]
//   0x0e67b8: F8697829  ldr      x9, [x1, x9, lsl #3]
static inline uint64_t fde_func_1305_0x0e67ac(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e67acULL ^ (static_cast<uint64_t>(0xb9800808ULL) << 13);
    acc = (acc + a1 + 0xb9801009ULL) ^ 0x1a9058ULL;
    acc ^= (acc >> 17) * 0x0058ULL;
    return acc;
}

// FDE #1306 | PC: 0x0e6804 | FDE: 0x1a9088 | Size: 96 bytes
// Khung tháo gỡ #1306 | Địa chỉ PC: 0x0e6804 | Địa chỉ FDE: 0x1a9088 | Kích thước: 96 bytes
//   0x0e6804: B9800808  ldrsw    x8, [x0, #8]
//   0x0e6808: BD401000  ldr      s0, [x0, #0x10]
//   0x0e680c: 52800309  mov      w9, #0x18
//   0x0e6810: D37DF108  lsl      x8, x8, #3
static inline uint64_t fde_func_1306_0x0e6804(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e6804ULL ^ (static_cast<uint64_t>(0xb9800808ULL) << 13);
    acc = (acc + a1 + 0xbd401000ULL) ^ 0x1a9088ULL;
    acc ^= (acc >> 17) * 0x0060ULL;
    return acc;
}

// FDE #1307 | PC: 0x0e6864 | FDE: 0x1a90b8 | Size: 80 bytes
// Khung tháo gỡ #1307 | Địa chỉ PC: 0x0e6864 | Địa chỉ FDE: 0x1a90b8 | Kích thước: 80 bytes
//   0x0e6864: B9801008  ldrsw    x8, [x0, #0x10]
//   0x0e6868: FD400400  ldr      d0, [x0, #8]
//   0x0e686c: 52800309  mov      w9, #0x18
//   0x0e6870: FC687821  ldr      d1, [x1, x8, lsl #3]
static inline uint64_t fde_func_1307_0x0e6864(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e6864ULL ^ (static_cast<uint64_t>(0xb9801008ULL) << 13);
    acc = (acc + a1 + 0xfd400400ULL) ^ 0x1a90b8ULL;
    acc ^= (acc >> 17) * 0x0050ULL;
    return acc;
}

// FDE #1308 | PC: 0x0e68b4 | FDE: 0x1a90e8 | Size: 104 bytes
// Khung tháo gỡ #1308 | Địa chỉ PC: 0x0e68b4 | Địa chỉ FDE: 0x1a90e8 | Kích thước: 104 bytes
//   0x0e68b4: B9800808  ldrsw    x8, [x0, #8]
//   0x0e68b8: B9801009  ldrsw    x9, [x0, #0x10]
//   0x0e68bc: FC687820  ldr      d0, [x1, x8, lsl #3]
//   0x0e68c0: FC697821  ldr      d1, [x1, x9, lsl #3]
static inline uint64_t fde_func_1308_0x0e68b4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e68b4ULL ^ (static_cast<uint64_t>(0xb9800808ULL) << 13);
    acc = (acc + a1 + 0xb9801009ULL) ^ 0x1a90e8ULL;
    acc ^= (acc >> 17) * 0x0068ULL;
    return acc;
}

// FDE #1309 | PC: 0x0e691c | FDE: 0x1a9118 | Size: 88 bytes
// Khung tháo gỡ #1309 | Địa chỉ PC: 0x0e691c | Địa chỉ FDE: 0x1a9118 | Kích thước: 88 bytes
//   0x0e691c: B9801008  ldrsw    x8, [x0, #0x10]
//   0x0e6920: B9400809  ldr      w9, [x0, #8]
//   0x0e6924: D37DF108  lsl      x8, x8, #3
//   0x0e6928: B8686828  ldr      w8, [x1, x8]
static inline uint64_t fde_func_1309_0x0e691c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e691cULL ^ (static_cast<uint64_t>(0xb9801008ULL) << 13);
    acc = (acc + a1 + 0xb9400809ULL) ^ 0x1a9118ULL;
    acc ^= (acc >> 17) * 0x0058ULL;
    return acc;
}

// FDE #1310 | PC: 0x0e6974 | FDE: 0x1a9148 | Size: 92 bytes
// Khung tháo gỡ #1310 | Địa chỉ PC: 0x0e6974 | Địa chỉ FDE: 0x1a9148 | Kích thước: 92 bytes
//   0x0e6974: B9800808  ldrsw    x8, [x0, #8]
//   0x0e6978: B9801009  ldrsw    x9, [x0, #0x10]
//   0x0e697c: D37DF108  lsl      x8, x8, #3
//   0x0e6980: D37DF129  lsl      x9, x9, #3
static inline uint64_t fde_func_1310_0x0e6974(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e6974ULL ^ (static_cast<uint64_t>(0xb9800808ULL) << 13);
    acc = (acc + a1 + 0xb9801009ULL) ^ 0x1a9148ULL;
    acc ^= (acc >> 17) * 0x005cULL;
    return acc;
}

// FDE #1311 | PC: 0x0e69d0 | FDE: 0x1a9178 | Size: 84 bytes
// Khung tháo gỡ #1311 | Địa chỉ PC: 0x0e69d0 | Địa chỉ FDE: 0x1a9178 | Kích thước: 84 bytes
//   0x0e69d0: B9800808  ldrsw    x8, [x0, #8]
//   0x0e69d4: F9400809  ldr      x9, [x0, #0x10]
//   0x0e69d8: F8687828  ldr      x8, [x1, x8, lsl #3]
//   0x0e69dc: EB09011F  cmp      x8, x9
static inline uint64_t fde_func_1311_0x0e69d0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e69d0ULL ^ (static_cast<uint64_t>(0xb9800808ULL) << 13);
    acc = (acc + a1 + 0xf9400809ULL) ^ 0x1a9178ULL;
    acc ^= (acc >> 17) * 0x0054ULL;
    return acc;
}

// FDE #1312 | PC: 0x0e6a24 | FDE: 0x1a91a8 | Size: 88 bytes
// Khung tháo gỡ #1312 | Địa chỉ PC: 0x0e6a24 | Địa chỉ FDE: 0x1a91a8 | Kích thước: 88 bytes
//   0x0e6a24: B9801008  ldrsw    x8, [x0, #0x10]
//   0x0e6a28: BD400800  ldr      s0, [x0, #8]
//   0x0e6a2c: 52800309  mov      w9, #0x18
//   0x0e6a30: D37DF108  lsl      x8, x8, #3
static inline uint64_t fde_func_1312_0x0e6a24(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e6a24ULL ^ (static_cast<uint64_t>(0xb9801008ULL) << 13);
    acc = (acc + a1 + 0xbd400800ULL) ^ 0x1a91a8ULL;
    acc ^= (acc >> 17) * 0x0058ULL;
    return acc;
}

// FDE #1313 | PC: 0x0e6a7c | FDE: 0x1a91d8 | Size: 92 bytes
// Khung tháo gỡ #1313 | Địa chỉ PC: 0x0e6a7c | Địa chỉ FDE: 0x1a91d8 | Kích thước: 92 bytes
//   0x0e6a7c: B9800808  ldrsw    x8, [x0, #8]
//   0x0e6a80: B9801009  ldrsw    x9, [x0, #0x10]
//   0x0e6a84: D37DF108  lsl      x8, x8, #3
//   0x0e6a88: D37DF129  lsl      x9, x9, #3
static inline uint64_t fde_func_1313_0x0e6a7c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e6a7cULL ^ (static_cast<uint64_t>(0xb9800808ULL) << 13);
    acc = (acc + a1 + 0xb9801009ULL) ^ 0x1a91d8ULL;
    acc ^= (acc >> 17) * 0x005cULL;
    return acc;
}

// FDE #1314 | PC: 0x0e6ad8 | FDE: 0x1a9208 | Size: 84 bytes
// Khung tháo gỡ #1314 | Địa chỉ PC: 0x0e6ad8 | Địa chỉ FDE: 0x1a9208 | Kích thước: 84 bytes
//   0x0e6ad8: B9800808  ldrsw    x8, [x0, #8]
//   0x0e6adc: FD400800  ldr      d0, [x0, #0x10]
//   0x0e6ae0: 52800309  mov      w9, #0x18
//   0x0e6ae4: FC687821  ldr      d1, [x1, x8, lsl #3]
static inline uint64_t fde_func_1314_0x0e6ad8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e6ad8ULL ^ (static_cast<uint64_t>(0xb9800808ULL) << 13);
    acc = (acc + a1 + 0xfd400800ULL) ^ 0x1a9208ULL;
    acc ^= (acc >> 17) * 0x0054ULL;
    return acc;
}

// FDE #1315 | PC: 0x0e6b2c | FDE: 0x1a9238 | Size: 104 bytes
// Khung tháo gỡ #1315 | Địa chỉ PC: 0x0e6b2c | Địa chỉ FDE: 0x1a9238 | Kích thước: 104 bytes
//   0x0e6b2c: F9400409  ldr      x9, [x0, #8]
//   0x0e6b30: 3940012A  ldrb     w10, [x9]
//   0x0e6b34: 79401528  ldrh     w8, [x9, #0xa]
//   0x0e6b38: 3400008A  cbz      w10, #0xe6b48
static inline uint64_t fde_func_1315_0x0e6b2c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e6b2cULL ^ (static_cast<uint64_t>(0xf9400409ULL) << 13);
    acc = (acc + a1 + 0x3940012aULL) ^ 0x1a9238ULL;
    acc ^= (acc >> 17) * 0x0068ULL;
    return acc;
}

// FDE #1316 | PC: 0x0e6b94 | FDE: 0x1a9268 | Size: 96 bytes
// Khung tháo gỡ #1316 | Địa chỉ PC: 0x0e6b94 | Địa chỉ FDE: 0x1a9268 | Kích thước: 96 bytes
//   0x0e6b94: B9800808  ldrsw    x8, [x0, #8]
//   0x0e6b98: B9401009  ldr      w9, [x0, #0x10]
//   0x0e6b9c: D37DF108  lsl      x8, x8, #3
//   0x0e6ba0: B8686828  ldr      w8, [x1, x8]
static inline uint64_t fde_func_1316_0x0e6b94(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e6b94ULL ^ (static_cast<uint64_t>(0xb9800808ULL) << 13);
    acc = (acc + a1 + 0xb9401009ULL) ^ 0x1a9268ULL;
    acc ^= (acc >> 17) * 0x0060ULL;
    return acc;
}

// FDE #1317 | PC: 0x0e6bf4 | FDE: 0x1a9298 | Size: 80 bytes
// Khung tháo gỡ #1317 | Địa chỉ PC: 0x0e6bf4 | Địa chỉ FDE: 0x1a9298 | Kích thước: 80 bytes
//   0x0e6bf4: B9801008  ldrsw    x8, [x0, #0x10]
//   0x0e6bf8: F9400409  ldr      x9, [x0, #8]
//   0x0e6bfc: F8687828  ldr      x8, [x1, x8, lsl #3]
//   0x0e6c00: EB08013F  cmp      x9, x8
static inline uint64_t fde_func_1317_0x0e6bf4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e6bf4ULL ^ (static_cast<uint64_t>(0xb9801008ULL) << 13);
    acc = (acc + a1 + 0xf9400409ULL) ^ 0x1a9298ULL;
    acc ^= (acc >> 17) * 0x0050ULL;
    return acc;
}

// FDE #1318 | PC: 0x0e6c44 | FDE: 0x1a92c8 | Size: 88 bytes
// Khung tháo gỡ #1318 | Địa chỉ PC: 0x0e6c44 | Địa chỉ FDE: 0x1a92c8 | Kích thước: 88 bytes
//   0x0e6c44: B9800808  ldrsw    x8, [x0, #8]
//   0x0e6c48: B9801009  ldrsw    x9, [x0, #0x10]
//   0x0e6c4c: F8687828  ldr      x8, [x1, x8, lsl #3]
//   0x0e6c50: F8697829  ldr      x9, [x1, x9, lsl #3]
static inline uint64_t fde_func_1318_0x0e6c44(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e6c44ULL ^ (static_cast<uint64_t>(0xb9800808ULL) << 13);
    acc = (acc + a1 + 0xb9801009ULL) ^ 0x1a92c8ULL;
    acc ^= (acc >> 17) * 0x0058ULL;
    return acc;
}

// FDE #1319 | PC: 0x0e6c9c | FDE: 0x1a92f8 | Size: 96 bytes
// Khung tháo gỡ #1319 | Địa chỉ PC: 0x0e6c9c | Địa chỉ FDE: 0x1a92f8 | Kích thước: 96 bytes
//   0x0e6c9c: B9800808  ldrsw    x8, [x0, #8]
//   0x0e6ca0: BD401000  ldr      s0, [x0, #0x10]
//   0x0e6ca4: 52800309  mov      w9, #0x18
//   0x0e6ca8: D37DF108  lsl      x8, x8, #3
static inline uint64_t fde_func_1319_0x0e6c9c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e6c9cULL ^ (static_cast<uint64_t>(0xb9800808ULL) << 13);
    acc = (acc + a1 + 0xbd401000ULL) ^ 0x1a92f8ULL;
    acc ^= (acc >> 17) * 0x0060ULL;
    return acc;
}

// FDE #1320 | PC: 0x0e6cfc | FDE: 0x1a9328 | Size: 80 bytes
// Khung tháo gỡ #1320 | Địa chỉ PC: 0x0e6cfc | Địa chỉ FDE: 0x1a9328 | Kích thước: 80 bytes
//   0x0e6cfc: B9801008  ldrsw    x8, [x0, #0x10]
//   0x0e6d00: FD400400  ldr      d0, [x0, #8]
//   0x0e6d04: 52800309  mov      w9, #0x18
//   0x0e6d08: FC687821  ldr      d1, [x1, x8, lsl #3]
static inline uint64_t fde_func_1320_0x0e6cfc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e6cfcULL ^ (static_cast<uint64_t>(0xb9801008ULL) << 13);
    acc = (acc + a1 + 0xfd400400ULL) ^ 0x1a9328ULL;
    acc ^= (acc >> 17) * 0x0050ULL;
    return acc;
}

// FDE #1321 | PC: 0x0e6d4c | FDE: 0x1a9358 | Size: 104 bytes
// Khung tháo gỡ #1321 | Địa chỉ PC: 0x0e6d4c | Địa chỉ FDE: 0x1a9358 | Kích thước: 104 bytes
//   0x0e6d4c: B9800808  ldrsw    x8, [x0, #8]
//   0x0e6d50: B9801009  ldrsw    x9, [x0, #0x10]
//   0x0e6d54: FC687820  ldr      d0, [x1, x8, lsl #3]
//   0x0e6d58: FC697821  ldr      d1, [x1, x9, lsl #3]
static inline uint64_t fde_func_1321_0x0e6d4c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e6d4cULL ^ (static_cast<uint64_t>(0xb9800808ULL) << 13);
    acc = (acc + a1 + 0xb9801009ULL) ^ 0x1a9358ULL;
    acc ^= (acc >> 17) * 0x0068ULL;
    return acc;
}

// FDE #1322 | PC: 0x0e6db4 | FDE: 0x1a9388 | Size: 88 bytes
// Khung tháo gỡ #1322 | Địa chỉ PC: 0x0e6db4 | Địa chỉ FDE: 0x1a9388 | Kích thước: 88 bytes
//   0x0e6db4: B9801008  ldrsw    x8, [x0, #0x10]
//   0x0e6db8: B9400809  ldr      w9, [x0, #8]
//   0x0e6dbc: D37DF108  lsl      x8, x8, #3
//   0x0e6dc0: B8686828  ldr      w8, [x1, x8]
static inline uint64_t fde_func_1322_0x0e6db4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e6db4ULL ^ (static_cast<uint64_t>(0xb9801008ULL) << 13);
    acc = (acc + a1 + 0xb9400809ULL) ^ 0x1a9388ULL;
    acc ^= (acc >> 17) * 0x0058ULL;
    return acc;
}

// FDE #1323 | PC: 0x0e6e0c | FDE: 0x1a93b8 | Size: 92 bytes
// Khung tháo gỡ #1323 | Địa chỉ PC: 0x0e6e0c | Địa chỉ FDE: 0x1a93b8 | Kích thước: 92 bytes
//   0x0e6e0c: B9800808  ldrsw    x8, [x0, #8]
//   0x0e6e10: B9801009  ldrsw    x9, [x0, #0x10]
//   0x0e6e14: D37DF108  lsl      x8, x8, #3
//   0x0e6e18: D37DF129  lsl      x9, x9, #3
static inline uint64_t fde_func_1323_0x0e6e0c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e6e0cULL ^ (static_cast<uint64_t>(0xb9800808ULL) << 13);
    acc = (acc + a1 + 0xb9801009ULL) ^ 0x1a93b8ULL;
    acc ^= (acc >> 17) * 0x005cULL;
    return acc;
}

// FDE #1324 | PC: 0x0e6e68 | FDE: 0x1a93e8 | Size: 84 bytes
// Khung tháo gỡ #1324 | Địa chỉ PC: 0x0e6e68 | Địa chỉ FDE: 0x1a93e8 | Kích thước: 84 bytes
//   0x0e6e68: B9800808  ldrsw    x8, [x0, #8]
//   0x0e6e6c: F9400809  ldr      x9, [x0, #0x10]
//   0x0e6e70: F8687828  ldr      x8, [x1, x8, lsl #3]
//   0x0e6e74: EB09011F  cmp      x8, x9
static inline uint64_t fde_func_1324_0x0e6e68(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e6e68ULL ^ (static_cast<uint64_t>(0xb9800808ULL) << 13);
    acc = (acc + a1 + 0xf9400809ULL) ^ 0x1a93e8ULL;
    acc ^= (acc >> 17) * 0x0054ULL;
    return acc;
}

// FDE #1325 | PC: 0x0e6ebc | FDE: 0x1a9418 | Size: 88 bytes
// Khung tháo gỡ #1325 | Địa chỉ PC: 0x0e6ebc | Địa chỉ FDE: 0x1a9418 | Kích thước: 88 bytes
//   0x0e6ebc: B9801008  ldrsw    x8, [x0, #0x10]
//   0x0e6ec0: BD400800  ldr      s0, [x0, #8]
//   0x0e6ec4: 52800309  mov      w9, #0x18
//   0x0e6ec8: D37DF108  lsl      x8, x8, #3
static inline uint64_t fde_func_1325_0x0e6ebc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e6ebcULL ^ (static_cast<uint64_t>(0xb9801008ULL) << 13);
    acc = (acc + a1 + 0xbd400800ULL) ^ 0x1a9418ULL;
    acc ^= (acc >> 17) * 0x0058ULL;
    return acc;
}

// FDE #1326 | PC: 0x0e6f14 | FDE: 0x1a9448 | Size: 92 bytes
// Khung tháo gỡ #1326 | Địa chỉ PC: 0x0e6f14 | Địa chỉ FDE: 0x1a9448 | Kích thước: 92 bytes
//   0x0e6f14: B9800808  ldrsw    x8, [x0, #8]
//   0x0e6f18: B9801009  ldrsw    x9, [x0, #0x10]
//   0x0e6f1c: D37DF108  lsl      x8, x8, #3
//   0x0e6f20: D37DF129  lsl      x9, x9, #3
static inline uint64_t fde_func_1326_0x0e6f14(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e6f14ULL ^ (static_cast<uint64_t>(0xb9800808ULL) << 13);
    acc = (acc + a1 + 0xb9801009ULL) ^ 0x1a9448ULL;
    acc ^= (acc >> 17) * 0x005cULL;
    return acc;
}

// FDE #1327 | PC: 0x0e6f70 | FDE: 0x1a9478 | Size: 84 bytes
// Khung tháo gỡ #1327 | Địa chỉ PC: 0x0e6f70 | Địa chỉ FDE: 0x1a9478 | Kích thước: 84 bytes
//   0x0e6f70: B9800808  ldrsw    x8, [x0, #8]
//   0x0e6f74: FD400800  ldr      d0, [x0, #0x10]
//   0x0e6f78: 52800309  mov      w9, #0x18
//   0x0e6f7c: FC687821  ldr      d1, [x1, x8, lsl #3]
static inline uint64_t fde_func_1327_0x0e6f70(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e6f70ULL ^ (static_cast<uint64_t>(0xb9800808ULL) << 13);
    acc = (acc + a1 + 0xfd400800ULL) ^ 0x1a9478ULL;
    acc ^= (acc >> 17) * 0x0054ULL;
    return acc;
}

// FDE #1328 | PC: 0x0e6fc4 | FDE: 0x1a94a8 | Size: 104 bytes
// Khung tháo gỡ #1328 | Địa chỉ PC: 0x0e6fc4 | Địa chỉ FDE: 0x1a94a8 | Kích thước: 104 bytes
//   0x0e6fc4: F9400409  ldr      x9, [x0, #8]
//   0x0e6fc8: 3940012A  ldrb     w10, [x9]
//   0x0e6fcc: 79401528  ldrh     w8, [x9, #0xa]
//   0x0e6fd0: 3400008A  cbz      w10, #0xe6fe0
static inline uint64_t fde_func_1328_0x0e6fc4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e6fc4ULL ^ (static_cast<uint64_t>(0xf9400409ULL) << 13);
    acc = (acc + a1 + 0x3940012aULL) ^ 0x1a94a8ULL;
    acc ^= (acc >> 17) * 0x0068ULL;
    return acc;
}

// FDE #1329 | PC: 0x0e702c | FDE: 0x1a94d8 | Size: 96 bytes
// Khung tháo gỡ #1329 | Địa chỉ PC: 0x0e702c | Địa chỉ FDE: 0x1a94d8 | Kích thước: 96 bytes
//   0x0e702c: B9800808  ldrsw    x8, [x0, #8]
//   0x0e7030: B9401009  ldr      w9, [x0, #0x10]
//   0x0e7034: D37DF108  lsl      x8, x8, #3
//   0x0e7038: B8686828  ldr      w8, [x1, x8]
static inline uint64_t fde_func_1329_0x0e702c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e702cULL ^ (static_cast<uint64_t>(0xb9800808ULL) << 13);
    acc = (acc + a1 + 0xb9401009ULL) ^ 0x1a94d8ULL;
    acc ^= (acc >> 17) * 0x0060ULL;
    return acc;
}

// FDE #1330 | PC: 0x0e708c | FDE: 0x1a9508 | Size: 80 bytes
// Khung tháo gỡ #1330 | Địa chỉ PC: 0x0e708c | Địa chỉ FDE: 0x1a9508 | Kích thước: 80 bytes
//   0x0e708c: B9801008  ldrsw    x8, [x0, #0x10]
//   0x0e7090: F9400409  ldr      x9, [x0, #8]
//   0x0e7094: F8687828  ldr      x8, [x1, x8, lsl #3]
//   0x0e7098: EB08013F  cmp      x9, x8
static inline uint64_t fde_func_1330_0x0e708c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e708cULL ^ (static_cast<uint64_t>(0xb9801008ULL) << 13);
    acc = (acc + a1 + 0xf9400409ULL) ^ 0x1a9508ULL;
    acc ^= (acc >> 17) * 0x0050ULL;
    return acc;
}

// FDE #1331 | PC: 0x0e70dc | FDE: 0x1a9538 | Size: 88 bytes
// Khung tháo gỡ #1331 | Địa chỉ PC: 0x0e70dc | Địa chỉ FDE: 0x1a9538 | Kích thước: 88 bytes
//   0x0e70dc: B9800808  ldrsw    x8, [x0, #8]
//   0x0e70e0: B9801009  ldrsw    x9, [x0, #0x10]
//   0x0e70e4: F8687828  ldr      x8, [x1, x8, lsl #3]
//   0x0e70e8: F8697829  ldr      x9, [x1, x9, lsl #3]
static inline uint64_t fde_func_1331_0x0e70dc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e70dcULL ^ (static_cast<uint64_t>(0xb9800808ULL) << 13);
    acc = (acc + a1 + 0xb9801009ULL) ^ 0x1a9538ULL;
    acc ^= (acc >> 17) * 0x0058ULL;
    return acc;
}

// FDE #1332 | PC: 0x0e7134 | FDE: 0x1a9568 | Size: 96 bytes
// Khung tháo gỡ #1332 | Địa chỉ PC: 0x0e7134 | Địa chỉ FDE: 0x1a9568 | Kích thước: 96 bytes
//   0x0e7134: B9800808  ldrsw    x8, [x0, #8]
//   0x0e7138: BD401000  ldr      s0, [x0, #0x10]
//   0x0e713c: 52800309  mov      w9, #0x18
//   0x0e7140: D37DF108  lsl      x8, x8, #3
static inline uint64_t fde_func_1332_0x0e7134(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e7134ULL ^ (static_cast<uint64_t>(0xb9800808ULL) << 13);
    acc = (acc + a1 + 0xbd401000ULL) ^ 0x1a9568ULL;
    acc ^= (acc >> 17) * 0x0060ULL;
    return acc;
}

// FDE #1333 | PC: 0x0e7194 | FDE: 0x1a9598 | Size: 80 bytes
// Khung tháo gỡ #1333 | Địa chỉ PC: 0x0e7194 | Địa chỉ FDE: 0x1a9598 | Kích thước: 80 bytes
//   0x0e7194: B9801008  ldrsw    x8, [x0, #0x10]
//   0x0e7198: FD400400  ldr      d0, [x0, #8]
//   0x0e719c: 52800309  mov      w9, #0x18
//   0x0e71a0: FC687821  ldr      d1, [x1, x8, lsl #3]
static inline uint64_t fde_func_1333_0x0e7194(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e7194ULL ^ (static_cast<uint64_t>(0xb9801008ULL) << 13);
    acc = (acc + a1 + 0xfd400400ULL) ^ 0x1a9598ULL;
    acc ^= (acc >> 17) * 0x0050ULL;
    return acc;
}

// FDE #1334 | PC: 0x0e71e4 | FDE: 0x1a95c8 | Size: 104 bytes
// Khung tháo gỡ #1334 | Địa chỉ PC: 0x0e71e4 | Địa chỉ FDE: 0x1a95c8 | Kích thước: 104 bytes
//   0x0e71e4: B9800808  ldrsw    x8, [x0, #8]
//   0x0e71e8: B9801009  ldrsw    x9, [x0, #0x10]
//   0x0e71ec: FC687820  ldr      d0, [x1, x8, lsl #3]
//   0x0e71f0: FC697821  ldr      d1, [x1, x9, lsl #3]
static inline uint64_t fde_func_1334_0x0e71e4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e71e4ULL ^ (static_cast<uint64_t>(0xb9800808ULL) << 13);
    acc = (acc + a1 + 0xb9801009ULL) ^ 0x1a95c8ULL;
    acc ^= (acc >> 17) * 0x0068ULL;
    return acc;
}

// FDE #1335 | PC: 0x0e724c | FDE: 0x1a95f8 | Size: 88 bytes
// Khung tháo gỡ #1335 | Địa chỉ PC: 0x0e724c | Địa chỉ FDE: 0x1a95f8 | Kích thước: 88 bytes
//   0x0e724c: B9801008  ldrsw    x8, [x0, #0x10]
//   0x0e7250: B9400809  ldr      w9, [x0, #8]
//   0x0e7254: D37DF108  lsl      x8, x8, #3
//   0x0e7258: B8686828  ldr      w8, [x1, x8]
static inline uint64_t fde_func_1335_0x0e724c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e724cULL ^ (static_cast<uint64_t>(0xb9801008ULL) << 13);
    acc = (acc + a1 + 0xb9400809ULL) ^ 0x1a95f8ULL;
    acc ^= (acc >> 17) * 0x0058ULL;
    return acc;
}

// FDE #1336 | PC: 0x0e72a4 | FDE: 0x1a9628 | Size: 92 bytes
// Khung tháo gỡ #1336 | Địa chỉ PC: 0x0e72a4 | Địa chỉ FDE: 0x1a9628 | Kích thước: 92 bytes
//   0x0e72a4: B9800808  ldrsw    x8, [x0, #8]
//   0x0e72a8: B9801009  ldrsw    x9, [x0, #0x10]
//   0x0e72ac: D37DF108  lsl      x8, x8, #3
//   0x0e72b0: D37DF129  lsl      x9, x9, #3
static inline uint64_t fde_func_1336_0x0e72a4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e72a4ULL ^ (static_cast<uint64_t>(0xb9800808ULL) << 13);
    acc = (acc + a1 + 0xb9801009ULL) ^ 0x1a9628ULL;
    acc ^= (acc >> 17) * 0x005cULL;
    return acc;
}

// FDE #1337 | PC: 0x0e7300 | FDE: 0x1a9658 | Size: 84 bytes
// Khung tháo gỡ #1337 | Địa chỉ PC: 0x0e7300 | Địa chỉ FDE: 0x1a9658 | Kích thước: 84 bytes
//   0x0e7300: B9800808  ldrsw    x8, [x0, #8]
//   0x0e7304: F9400809  ldr      x9, [x0, #0x10]
//   0x0e7308: F8687828  ldr      x8, [x1, x8, lsl #3]
//   0x0e730c: EB09011F  cmp      x8, x9
static inline uint64_t fde_func_1337_0x0e7300(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e7300ULL ^ (static_cast<uint64_t>(0xb9800808ULL) << 13);
    acc = (acc + a1 + 0xf9400809ULL) ^ 0x1a9658ULL;
    acc ^= (acc >> 17) * 0x0054ULL;
    return acc;
}

// FDE #1338 | PC: 0x0e7354 | FDE: 0x1a9688 | Size: 104 bytes
// Khung tháo gỡ #1338 | Địa chỉ PC: 0x0e7354 | Địa chỉ FDE: 0x1a9688 | Kích thước: 104 bytes
//   0x0e7354: F9400409  ldr      x9, [x0, #8]
//   0x0e7358: 3940012A  ldrb     w10, [x9]
//   0x0e735c: 79401528  ldrh     w8, [x9, #0xa]
//   0x0e7360: 3400008A  cbz      w10, #0xe7370
static inline uint64_t fde_func_1338_0x0e7354(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e7354ULL ^ (static_cast<uint64_t>(0xf9400409ULL) << 13);
    acc = (acc + a1 + 0x3940012aULL) ^ 0x1a9688ULL;
    acc ^= (acc >> 17) * 0x0068ULL;
    return acc;
}

// FDE #1339 | PC: 0x0e73bc | FDE: 0x1a96b8 | Size: 96 bytes
// Khung tháo gỡ #1339 | Địa chỉ PC: 0x0e73bc | Địa chỉ FDE: 0x1a96b8 | Kích thước: 96 bytes
//   0x0e73bc: B9800808  ldrsw    x8, [x0, #8]
//   0x0e73c0: B9401009  ldr      w9, [x0, #0x10]
//   0x0e73c4: D37DF108  lsl      x8, x8, #3
//   0x0e73c8: B8686828  ldr      w8, [x1, x8]
static inline uint64_t fde_func_1339_0x0e73bc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e73bcULL ^ (static_cast<uint64_t>(0xb9800808ULL) << 13);
    acc = (acc + a1 + 0xb9401009ULL) ^ 0x1a96b8ULL;
    acc ^= (acc >> 17) * 0x0060ULL;
    return acc;
}

// FDE #1340 | PC: 0x0e741c | FDE: 0x1a96e8 | Size: 80 bytes
// Khung tháo gỡ #1340 | Địa chỉ PC: 0x0e741c | Địa chỉ FDE: 0x1a96e8 | Kích thước: 80 bytes
//   0x0e741c: B9801008  ldrsw    x8, [x0, #0x10]
//   0x0e7420: F9400409  ldr      x9, [x0, #8]
//   0x0e7424: F8687828  ldr      x8, [x1, x8, lsl #3]
//   0x0e7428: EB08013F  cmp      x9, x8
static inline uint64_t fde_func_1340_0x0e741c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e741cULL ^ (static_cast<uint64_t>(0xb9801008ULL) << 13);
    acc = (acc + a1 + 0xf9400409ULL) ^ 0x1a96e8ULL;
    acc ^= (acc >> 17) * 0x0050ULL;
    return acc;
}

// FDE #1341 | PC: 0x0e746c | FDE: 0x1a9718 | Size: 104 bytes
// Khung tháo gỡ #1341 | Địa chỉ PC: 0x0e746c | Địa chỉ FDE: 0x1a9718 | Kích thước: 104 bytes
//   0x0e746c: B9800808  ldrsw    x8, [x0, #8]
//   0x0e7470: B9801009  ldrsw    x9, [x0, #0x10]
//   0x0e7474: F8687828  ldr      x8, [x1, x8, lsl #3]
//   0x0e7478: F8697829  ldr      x9, [x1, x9, lsl #3]
static inline uint64_t fde_func_1341_0x0e746c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e746cULL ^ (static_cast<uint64_t>(0xb9800808ULL) << 13);
    acc = (acc + a1 + 0xb9801009ULL) ^ 0x1a9718ULL;
    acc ^= (acc >> 17) * 0x0068ULL;
    return acc;
}

// FDE #1342 | PC: 0x0e74d4 | FDE: 0x1a9748 | Size: 88 bytes
// Khung tháo gỡ #1342 | Địa chỉ PC: 0x0e74d4 | Địa chỉ FDE: 0x1a9748 | Kích thước: 88 bytes
//   0x0e74d4: B9801008  ldrsw    x8, [x0, #0x10]
//   0x0e74d8: B9400809  ldr      w9, [x0, #8]
//   0x0e74dc: D37DF108  lsl      x8, x8, #3
//   0x0e74e0: B8686828  ldr      w8, [x1, x8]
static inline uint64_t fde_func_1342_0x0e74d4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e74d4ULL ^ (static_cast<uint64_t>(0xb9801008ULL) << 13);
    acc = (acc + a1 + 0xb9400809ULL) ^ 0x1a9748ULL;
    acc ^= (acc >> 17) * 0x0058ULL;
    return acc;
}

// FDE #1343 | PC: 0x0e752c | FDE: 0x1a9778 | Size: 92 bytes
// Khung tháo gỡ #1343 | Địa chỉ PC: 0x0e752c | Địa chỉ FDE: 0x1a9778 | Kích thước: 92 bytes
//   0x0e752c: B9800808  ldrsw    x8, [x0, #8]
//   0x0e7530: B9801009  ldrsw    x9, [x0, #0x10]
//   0x0e7534: D37DF108  lsl      x8, x8, #3
//   0x0e7538: D37DF129  lsl      x9, x9, #3
static inline uint64_t fde_func_1343_0x0e752c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e752cULL ^ (static_cast<uint64_t>(0xb9800808ULL) << 13);
    acc = (acc + a1 + 0xb9801009ULL) ^ 0x1a9778ULL;
    acc ^= (acc >> 17) * 0x005cULL;
    return acc;
}

// FDE #1344 | PC: 0x0e7588 | FDE: 0x1a97a8 | Size: 84 bytes
// Khung tháo gỡ #1344 | Địa chỉ PC: 0x0e7588 | Địa chỉ FDE: 0x1a97a8 | Kích thước: 84 bytes
//   0x0e7588: B9800808  ldrsw    x8, [x0, #8]
//   0x0e758c: F9400809  ldr      x9, [x0, #0x10]
//   0x0e7590: F8687828  ldr      x8, [x1, x8, lsl #3]
//   0x0e7594: EB09011F  cmp      x8, x9
static inline uint64_t fde_func_1344_0x0e7588(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e7588ULL ^ (static_cast<uint64_t>(0xb9800808ULL) << 13);
    acc = (acc + a1 + 0xf9400809ULL) ^ 0x1a97a8ULL;
    acc ^= (acc >> 17) * 0x0054ULL;
    return acc;
}

// FDE #1345 | PC: 0x0e75dc | FDE: 0x1a97d8 | Size: 104 bytes
// Khung tháo gỡ #1345 | Địa chỉ PC: 0x0e75dc | Địa chỉ FDE: 0x1a97d8 | Kích thước: 104 bytes
//   0x0e75dc: F9400409  ldr      x9, [x0, #8]
//   0x0e75e0: 3940012A  ldrb     w10, [x9]
//   0x0e75e4: 79401528  ldrh     w8, [x9, #0xa]
//   0x0e75e8: 3400008A  cbz      w10, #0xe75f8
static inline uint64_t fde_func_1345_0x0e75dc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e75dcULL ^ (static_cast<uint64_t>(0xf9400409ULL) << 13);
    acc = (acc + a1 + 0x3940012aULL) ^ 0x1a97d8ULL;
    acc ^= (acc >> 17) * 0x0068ULL;
    return acc;
}

// FDE #1346 | PC: 0x0e7644 | FDE: 0x1a9808 | Size: 96 bytes
// Khung tháo gỡ #1346 | Địa chỉ PC: 0x0e7644 | Địa chỉ FDE: 0x1a9808 | Kích thước: 96 bytes
//   0x0e7644: B9800808  ldrsw    x8, [x0, #8]
//   0x0e7648: B9401009  ldr      w9, [x0, #0x10]
//   0x0e764c: D37DF108  lsl      x8, x8, #3
//   0x0e7650: B8686828  ldr      w8, [x1, x8]
static inline uint64_t fde_func_1346_0x0e7644(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e7644ULL ^ (static_cast<uint64_t>(0xb9800808ULL) << 13);
    acc = (acc + a1 + 0xb9401009ULL) ^ 0x1a9808ULL;
    acc ^= (acc >> 17) * 0x0060ULL;
    return acc;
}

// FDE #1347 | PC: 0x0e76a4 | FDE: 0x1a9838 | Size: 80 bytes
// Khung tháo gỡ #1347 | Địa chỉ PC: 0x0e76a4 | Địa chỉ FDE: 0x1a9838 | Kích thước: 80 bytes
//   0x0e76a4: B9801008  ldrsw    x8, [x0, #0x10]
//   0x0e76a8: F9400409  ldr      x9, [x0, #8]
//   0x0e76ac: F8687828  ldr      x8, [x1, x8, lsl #3]
//   0x0e76b0: EB08013F  cmp      x9, x8
static inline uint64_t fde_func_1347_0x0e76a4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e76a4ULL ^ (static_cast<uint64_t>(0xb9801008ULL) << 13);
    acc = (acc + a1 + 0xf9400409ULL) ^ 0x1a9838ULL;
    acc ^= (acc >> 17) * 0x0050ULL;
    return acc;
}

// FDE #1348 | PC: 0x0e76f4 | FDE: 0x1a9868 | Size: 68 bytes
// Khung tháo gỡ #1348 | Địa chỉ PC: 0x0e76f4 | Địa chỉ FDE: 0x1a9868 | Kích thước: 68 bytes
//   0x0e76f4: B9800808  ldrsw    x8, [x0, #8]
//   0x0e76f8: B9801009  ldrsw    x9, [x0, #0x10]
//   0x0e76fc: F8687828  ldr      x8, [x1, x8, lsl #3]
//   0x0e7700: F8697829  ldr      x9, [x1, x9, lsl #3]
static inline uint64_t fde_func_1348_0x0e76f4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e76f4ULL ^ (static_cast<uint64_t>(0xb9800808ULL) << 13);
    acc = (acc + a1 + 0xb9801009ULL) ^ 0x1a9868ULL;
    acc ^= (acc >> 17) * 0x0044ULL;
    return acc;
}

// FDE #1349 | PC: 0x0e7738 | FDE: 0x1a9898 | Size: 48 bytes
// Khung tháo gỡ #1349 | Địa chỉ PC: 0x0e7738 | Địa chỉ FDE: 0x1a9898 | Kích thước: 48 bytes
//   0x0e7738: 39C02008  ldrsb    w8, [x0, #8]
//   0x0e773c: B9801009  ldrsw    x9, [x0, #0x10]
//   0x0e7740: F8297828  str      x8, [x1, x9, lsl #3]
//   0x0e7744: F8418C04  ldr      x4, [x0, #0x18]!
static inline uint64_t fde_func_1349_0x0e7738(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e7738ULL ^ (static_cast<uint64_t>(0x39c02008ULL) << 13);
    acc = (acc + a1 + 0xb9801009ULL) ^ 0x1a9898ULL;
    acc ^= (acc >> 17) * 0x0030ULL;
    return acc;
}

// FDE #1350 | PC: 0x0e7768 | FDE: 0x1a98c8 | Size: 44 bytes
// Khung tháo gỡ #1350 | Địa chỉ PC: 0x0e7768 | Địa chỉ FDE: 0x1a98c8 | Kích thước: 44 bytes
//   0x0e7768: F9400408  ldr      x8, [x0, #8]
//   0x0e776c: 90000709  adrp     x9, #0x1c7000
//   0x0e7770: 91250129  add      x9, x9, #0x940
//   0x0e7774: 39402108  ldrb     w8, [x8, #8]
static inline uint64_t fde_func_1350_0x0e7768(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e7768ULL ^ (static_cast<uint64_t>(0xf9400408ULL) << 13);
    acc = (acc + a1 + 0x90000709ULL) ^ 0x1a98c8ULL;
    acc ^= (acc >> 17) * 0x002cULL;
    return acc;
}

// FDE #1351 | PC: 0x0e7794 | FDE: 0x1a98f8 | Size: 52 bytes
// Khung tháo gỡ #1351 | Địa chỉ PC: 0x0e7794 | Địa chỉ FDE: 0x1a98f8 | Kích thước: 52 bytes
//   0x0e7794: B9800808  ldrsw    x8, [x0, #8]
//   0x0e7798: B9801009  ldrsw    x9, [x0, #0x10]
//   0x0e779c: D37DF108  lsl      x8, x8, #3
//   0x0e77a0: 38A86828  ldrsb    x8, [x1, x8]
static inline uint64_t fde_func_1351_0x0e7794(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e7794ULL ^ (static_cast<uint64_t>(0xb9800808ULL) << 13);
    acc = (acc + a1 + 0xb9801009ULL) ^ 0x1a98f8ULL;
    acc ^= (acc >> 17) * 0x0034ULL;
    return acc;
}

// FDE #1352 | PC: 0x0e77c8 | FDE: 0x1a9928 | Size: 48 bytes
// Khung tháo gỡ #1352 | Địa chỉ PC: 0x0e77c8 | Địa chỉ FDE: 0x1a9928 | Kích thước: 48 bytes
//   0x0e77c8: 79C01008  ldrsh    w8, [x0, #8]
//   0x0e77cc: B9801009  ldrsw    x9, [x0, #0x10]
//   0x0e77d0: F8297828  str      x8, [x1, x9, lsl #3]
//   0x0e77d4: F8418C04  ldr      x4, [x0, #0x18]!
static inline uint64_t fde_func_1352_0x0e77c8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e77c8ULL ^ (static_cast<uint64_t>(0x79c01008ULL) << 13);
    acc = (acc + a1 + 0xb9801009ULL) ^ 0x1a9928ULL;
    acc ^= (acc >> 17) * 0x0030ULL;
    return acc;
}

// FDE #1353 | PC: 0x0e77f8 | FDE: 0x1a9958 | Size: 44 bytes
// Khung tháo gỡ #1353 | Địa chỉ PC: 0x0e77f8 | Địa chỉ FDE: 0x1a9958 | Kích thước: 44 bytes
//   0x0e77f8: F9400408  ldr      x8, [x0, #8]
//   0x0e77fc: 90000709  adrp     x9, #0x1c7000
//   0x0e7800: 91258129  add      x9, x9, #0x960
//   0x0e7804: 39402108  ldrb     w8, [x8, #8]
static inline uint64_t fde_func_1353_0x0e77f8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e77f8ULL ^ (static_cast<uint64_t>(0xf9400408ULL) << 13);
    acc = (acc + a1 + 0x90000709ULL) ^ 0x1a9958ULL;
    acc ^= (acc >> 17) * 0x002cULL;
    return acc;
}

// FDE #1354 | PC: 0x0e7824 | FDE: 0x1a9988 | Size: 52 bytes
// Khung tháo gỡ #1354 | Địa chỉ PC: 0x0e7824 | Địa chỉ FDE: 0x1a9988 | Kích thước: 52 bytes
//   0x0e7824: B9800808  ldrsw    x8, [x0, #8]
//   0x0e7828: B9801009  ldrsw    x9, [x0, #0x10]
//   0x0e782c: D37DF108  lsl      x8, x8, #3
//   0x0e7830: 78A86828  ldrsh    x8, [x1, x8]
static inline uint64_t fde_func_1354_0x0e7824(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e7824ULL ^ (static_cast<uint64_t>(0xb9800808ULL) << 13);
    acc = (acc + a1 + 0xb9801009ULL) ^ 0x1a9988ULL;
    acc ^= (acc >> 17) * 0x0034ULL;
    return acc;
}

// FDE #1355 | PC: 0x0e7858 | FDE: 0x1a99b8 | Size: 48 bytes
// Khung tháo gỡ #1355 | Địa chỉ PC: 0x0e7858 | Địa chỉ FDE: 0x1a99b8 | Kích thước: 48 bytes
//   0x0e7858: B9800808  ldrsw    x8, [x0, #8]
//   0x0e785c: B9801009  ldrsw    x9, [x0, #0x10]
//   0x0e7860: F8297828  str      x8, [x1, x9, lsl #3]
//   0x0e7864: F8418C04  ldr      x4, [x0, #0x18]!
static inline uint64_t fde_func_1355_0x0e7858(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e7858ULL ^ (static_cast<uint64_t>(0xb9800808ULL) << 13);
    acc = (acc + a1 + 0xb9801009ULL) ^ 0x1a99b8ULL;
    acc ^= (acc >> 17) * 0x0030ULL;
    return acc;
}

// FDE #1356 | PC: 0x0e7888 | FDE: 0x1a99e8 | Size: 52 bytes
// Khung tháo gỡ #1356 | Địa chỉ PC: 0x0e7888 | Địa chỉ FDE: 0x1a99e8 | Kích thước: 52 bytes
//   0x0e7888: F9400408  ldr      x8, [x0, #8]
//   0x0e788c: 90000709  adrp     x9, #0x1c7000
//   0x0e7890: 91260129  add      x9, x9, #0x980
//   0x0e7894: 39402108  ldrb     w8, [x8, #8]
static inline uint64_t fde_func_1356_0x0e7888(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e7888ULL ^ (static_cast<uint64_t>(0xf9400408ULL) << 13);
    acc = (acc + a1 + 0x90000709ULL) ^ 0x1a99e8ULL;
    acc ^= (acc >> 17) * 0x0034ULL;
    return acc;
}

// FDE #1357 | PC: 0x0e78bc | FDE: 0x1a9a18 | Size: 60 bytes
// Khung tháo gỡ #1357 | Địa chỉ PC: 0x0e78bc | Địa chỉ FDE: 0x1a9a18 | Kích thước: 60 bytes
//   0x0e78bc: B9800808  ldrsw    x8, [x0, #8]
//   0x0e78c0: D37DF108  lsl      x8, x8, #3
//   0x0e78c4: BC686820  ldr      s0, [x1, x8]
//   0x0e78c8: B9801008  ldrsw    x8, [x0, #0x10]
static inline uint64_t fde_func_1357_0x0e78bc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e78bcULL ^ (static_cast<uint64_t>(0xb9800808ULL) << 13);
    acc = (acc + a1 + 0xd37df108ULL) ^ 0x1a9a18ULL;
    acc ^= (acc >> 17) * 0x003cULL;
    return acc;
}

// FDE #1358 | PC: 0x0e78f8 | FDE: 0x1a9a48 | Size: 64 bytes
// Khung tháo gỡ #1358 | Địa chỉ PC: 0x0e78f8 | Địa chỉ FDE: 0x1a9a48 | Kích thước: 64 bytes
//   0x0e78f8: BD400800  ldr      s0, [x0, #8]
//   0x0e78fc: B9801008  ldrsw    x8, [x0, #0x10]
//   0x0e7900: 0F20A400  sshll    v0.2d, v0.2s, #0
//   0x0e7904: 5E61D800  scvtf    d0, d0
static inline uint64_t fde_func_1358_0x0e78f8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e78f8ULL ^ (static_cast<uint64_t>(0xbd400800ULL) << 13);
    acc = (acc + a1 + 0xb9801008ULL) ^ 0x1a9a48ULL;
    acc ^= (acc >> 17) * 0x0040ULL;
    return acc;
}

// FDE #1359 | PC: 0x0e7938 | FDE: 0x1a9a78 | Size: 44 bytes
// Khung tháo gỡ #1359 | Địa chỉ PC: 0x0e7938 | Địa chỉ FDE: 0x1a9a78 | Kích thước: 44 bytes
//   0x0e7938: F9400408  ldr      x8, [x0, #8]
//   0x0e793c: 90000709  adrp     x9, #0x1c7000
//   0x0e7940: 91268129  add      x9, x9, #0x9a0
//   0x0e7944: 39402108  ldrb     w8, [x8, #8]
static inline uint64_t fde_func_1359_0x0e7938(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e7938ULL ^ (static_cast<uint64_t>(0xf9400408ULL) << 13);
    acc = (acc + a1 + 0x90000709ULL) ^ 0x1a9a78ULL;
    acc ^= (acc >> 17) * 0x002cULL;
    return acc;
}

// FDE #1360 | PC: 0x0e7964 | FDE: 0x1a9aa8 | Size: 52 bytes
// Khung tháo gỡ #1360 | Địa chỉ PC: 0x0e7964 | Địa chỉ FDE: 0x1a9aa8 | Kích thước: 52 bytes
//   0x0e7964: B9800808  ldrsw    x8, [x0, #8]
//   0x0e7968: B9801009  ldrsw    x9, [x0, #0x10]
//   0x0e796c: D37DF108  lsl      x8, x8, #3
//   0x0e7970: B8686828  ldr      w8, [x1, x8]
static inline uint64_t fde_func_1360_0x0e7964(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e7964ULL ^ (static_cast<uint64_t>(0xb9800808ULL) << 13);
    acc = (acc + a1 + 0xb9801009ULL) ^ 0x1a9aa8ULL;
    acc ^= (acc >> 17) * 0x0034ULL;
    return acc;
}

// FDE #1361 | PC: 0x0e7998 | FDE: 0x1a9ad8 | Size: 64 bytes
// Khung tháo gỡ #1361 | Địa chỉ PC: 0x0e7998 | Địa chỉ FDE: 0x1a9ad8 | Kích thước: 64 bytes
//   0x0e7998: BD400800  ldr      s0, [x0, #8]
//   0x0e799c: B9801008  ldrsw    x8, [x0, #0x10]
//   0x0e79a0: 7E21D800  ucvtf    s0, s0
//   0x0e79a4: 1E260009  fmov     w9, s0
static inline uint64_t fde_func_1361_0x0e7998(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e7998ULL ^ (static_cast<uint64_t>(0xbd400800ULL) << 13);
    acc = (acc + a1 + 0xb9801008ULL) ^ 0x1a9ad8ULL;
    acc ^= (acc >> 17) * 0x0040ULL;
    return acc;
}

// FDE #1362 | PC: 0x0e79d8 | FDE: 0x1a9b08 | Size: 48 bytes
// Khung tháo gỡ #1362 | Địa chỉ PC: 0x0e79d8 | Địa chỉ FDE: 0x1a9b08 | Kích thước: 48 bytes
//   0x0e79d8: F9400408  ldr      x8, [x0, #8]
//   0x0e79dc: 90000709  adrp     x9, #0x1c7000
//   0x0e79e0: 91270129  add      x9, x9, #0x9c0
//   0x0e79e4: 39402108  ldrb     w8, [x8, #8]
static inline uint64_t fde_func_1362_0x0e79d8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e79d8ULL ^ (static_cast<uint64_t>(0xf9400408ULL) << 13);
    acc = (acc + a1 + 0x90000709ULL) ^ 0x1a9b08ULL;
    acc ^= (acc >> 17) * 0x0030ULL;
    return acc;
}

// FDE #1363 | PC: 0x0e7a08 | FDE: 0x1a9b38 | Size: 56 bytes
// Khung tháo gỡ #1363 | Địa chỉ PC: 0x0e7a08 | Địa chỉ FDE: 0x1a9b38 | Kích thước: 56 bytes
//   0x0e7a08: B9800808  ldrsw    x8, [x0, #8]
//   0x0e7a0c: D37DF108  lsl      x8, x8, #3
//   0x0e7a10: BC686820  ldr      s0, [x1, x8]
//   0x0e7a14: B9801008  ldrsw    x8, [x0, #0x10]
static inline uint64_t fde_func_1363_0x0e7a08(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e7a08ULL ^ (static_cast<uint64_t>(0xb9800808ULL) << 13);
    acc = (acc + a1 + 0xd37df108ULL) ^ 0x1a9b38ULL;
    acc ^= (acc >> 17) * 0x0038ULL;
    return acc;
}

// FDE #1364 | PC: 0x0e7a40 | FDE: 0x1a9b68 | Size: 48 bytes
// Khung tháo gỡ #1364 | Địa chỉ PC: 0x0e7a40 | Địa chỉ FDE: 0x1a9b68 | Kích thước: 48 bytes
//   0x0e7a40: B9400808  ldr      w8, [x0, #8]
//   0x0e7a44: B9801009  ldrsw    x9, [x0, #0x10]
//   0x0e7a48: F8297828  str      x8, [x1, x9, lsl #3]
//   0x0e7a4c: F8418C04  ldr      x4, [x0, #0x18]!
static inline uint64_t fde_func_1364_0x0e7a40(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e7a40ULL ^ (static_cast<uint64_t>(0xb9400808ULL) << 13);
    acc = (acc + a1 + 0xb9801009ULL) ^ 0x1a9b68ULL;
    acc ^= (acc >> 17) * 0x0030ULL;
    return acc;
}

// FDE #1365 | PC: 0x0e7a70 | FDE: 0x1a9b98 | Size: 52 bytes
// Khung tháo gỡ #1365 | Địa chỉ PC: 0x0e7a70 | Địa chỉ FDE: 0x1a9b98 | Kích thước: 52 bytes
//   0x0e7a70: F9400408  ldr      x8, [x0, #8]
//   0x0e7a74: 90000709  adrp     x9, #0x1c7000
//   0x0e7a78: 91278129  add      x9, x9, #0x9e0
//   0x0e7a7c: 39402108  ldrb     w8, [x8, #8]
static inline uint64_t fde_func_1365_0x0e7a70(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e7a70ULL ^ (static_cast<uint64_t>(0xf9400408ULL) << 13);
    acc = (acc + a1 + 0x90000709ULL) ^ 0x1a9b98ULL;
    acc ^= (acc >> 17) * 0x0034ULL;
    return acc;
}

// FDE #1366 | PC: 0x0e7aa4 | FDE: 0x1a9bc8 | Size: 56 bytes
// Khung tháo gỡ #1366 | Địa chỉ PC: 0x0e7aa4 | Địa chỉ FDE: 0x1a9bc8 | Kích thước: 56 bytes
//   0x0e7aa4: B9800808  ldrsw    x8, [x0, #8]
//   0x0e7aa8: B9801009  ldrsw    x9, [x0, #0x10]
//   0x0e7aac: F8687828  ldr      x8, [x1, x8, lsl #3]
//   0x0e7ab0: 9E220100  scvtf    s0, x8
static inline uint64_t fde_func_1366_0x0e7aa4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e7aa4ULL ^ (static_cast<uint64_t>(0xb9800808ULL) << 13);
    acc = (acc + a1 + 0xb9801009ULL) ^ 0x1a9bc8ULL;
    acc ^= (acc >> 17) * 0x0038ULL;
    return acc;
}

// FDE #1367 | PC: 0x0e7adc | FDE: 0x1a9bf8 | Size: 52 bytes
// Khung tháo gỡ #1367 | Địa chỉ PC: 0x0e7adc | Địa chỉ FDE: 0x1a9bf8 | Kích thước: 52 bytes
//   0x0e7adc: FD400400  ldr      d0, [x0, #8]
//   0x0e7ae0: B9801008  ldrsw    x8, [x0, #0x10]
//   0x0e7ae4: 5E61D800  scvtf    d0, d0
//   0x0e7ae8: FC287820  str      d0, [x1, x8, lsl #3]
static inline uint64_t fde_func_1367_0x0e7adc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e7adcULL ^ (static_cast<uint64_t>(0xfd400400ULL) << 13);
    acc = (acc + a1 + 0xb9801008ULL) ^ 0x1a9bf8ULL;
    acc ^= (acc >> 17) * 0x0034ULL;
    return acc;
}

// FDE #1368 | PC: 0x0e7b10 | FDE: 0x1a9c28 | Size: 52 bytes
// Khung tháo gỡ #1368 | Địa chỉ PC: 0x0e7b10 | Địa chỉ FDE: 0x1a9c28 | Kích thước: 52 bytes
//   0x0e7b10: F9400408  ldr      x8, [x0, #8]
//   0x0e7b14: 90000709  adrp     x9, #0x1c7000
//   0x0e7b18: 91280129  add      x9, x9, #0xa00
//   0x0e7b1c: 39402108  ldrb     w8, [x8, #8]
static inline uint64_t fde_func_1368_0x0e7b10(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e7b10ULL ^ (static_cast<uint64_t>(0xf9400408ULL) << 13);
    acc = (acc + a1 + 0x90000709ULL) ^ 0x1a9c28ULL;
    acc ^= (acc >> 17) * 0x0034ULL;
    return acc;
}

// FDE #1369 | PC: 0x0e7b44 | FDE: 0x1a9c58 | Size: 56 bytes
// Khung tháo gỡ #1369 | Địa chỉ PC: 0x0e7b44 | Địa chỉ FDE: 0x1a9c58 | Kích thước: 56 bytes
//   0x0e7b44: B9800808  ldrsw    x8, [x0, #8]
//   0x0e7b48: B9801009  ldrsw    x9, [x0, #0x10]
//   0x0e7b4c: F8687828  ldr      x8, [x1, x8, lsl #3]
//   0x0e7b50: 9E230100  ucvtf    s0, x8
static inline uint64_t fde_func_1369_0x0e7b44(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e7b44ULL ^ (static_cast<uint64_t>(0xb9800808ULL) << 13);
    acc = (acc + a1 + 0xb9801009ULL) ^ 0x1a9c58ULL;
    acc ^= (acc >> 17) * 0x0038ULL;
    return acc;
}

// FDE #1370 | PC: 0x0e7b7c | FDE: 0x1a9c88 | Size: 52 bytes
// Khung tháo gỡ #1370 | Địa chỉ PC: 0x0e7b7c | Địa chỉ FDE: 0x1a9c88 | Kích thước: 52 bytes
//   0x0e7b7c: FD400400  ldr      d0, [x0, #8]
//   0x0e7b80: B9801008  ldrsw    x8, [x0, #0x10]
//   0x0e7b84: 7E61D800  ucvtf    d0, d0
//   0x0e7b88: FC287820  str      d0, [x1, x8, lsl #3]
static inline uint64_t fde_func_1370_0x0e7b7c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e7b7cULL ^ (static_cast<uint64_t>(0xfd400400ULL) << 13);
    acc = (acc + a1 + 0xb9801008ULL) ^ 0x1a9c88ULL;
    acc ^= (acc >> 17) * 0x0034ULL;
    return acc;
}

// FDE #1371 | PC: 0x0e7bb0 | FDE: 0x1a9cb8 | Size: 96 bytes
// Khung tháo gỡ #1371 | Địa chỉ PC: 0x0e7bb0 | Địa chỉ FDE: 0x1a9cb8 | Kích thước: 96 bytes
//   0x0e7bb0: F9400408  ldr      x8, [x0, #8]
//   0x0e7bb4: 90000709  adrp     x9, #0x1c7000
//   0x0e7bb8: 91288129  add      x9, x9, #0xa20
//   0x0e7bbc: 39402108  ldrb     w8, [x8, #8]
static inline uint64_t fde_func_1371_0x0e7bb0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e7bb0ULL ^ (static_cast<uint64_t>(0xf9400408ULL) << 13);
    acc = (acc + a1 + 0x90000709ULL) ^ 0x1a9cb8ULL;
    acc ^= (acc >> 17) * 0x0060ULL;
    return acc;
}

// FDE #1372 | PC: 0x0e7c10 | FDE: 0x1a9ce8 | Size: 104 bytes
// Khung tháo gỡ #1372 | Địa chỉ PC: 0x0e7c10 | Địa chỉ FDE: 0x1a9ce8 | Kích thước: 104 bytes
//   0x0e7c10: B9800808  ldrsw    x8, [x0, #8]
//   0x0e7c14: D37DF108  lsl      x8, x8, #3
//   0x0e7c18: BC686820  ldr      s0, [x1, x8]
//   0x0e7c1c: 1E202000  fcmp     s0, s0
static inline uint64_t fde_func_1372_0x0e7c10(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e7c10ULL ^ (static_cast<uint64_t>(0xb9800808ULL) << 13);
    acc = (acc + a1 + 0xd37df108ULL) ^ 0x1a9ce8ULL;
    acc ^= (acc >> 17) * 0x0068ULL;
    return acc;
}

// FDE #1373 | PC: 0x0e7c78 | FDE: 0x1a9d18 | Size: 136 bytes
// Khung tháo gỡ #1373 | Địa chỉ PC: 0x0e7c78 | Địa chỉ FDE: 0x1a9d18 | Kích thước: 136 bytes
//   0x0e7c78: BD400800  ldr      s0, [x0, #8]
//   0x0e7c7c: 1E202000  fcmp     s0, s0
//   0x0e7c80: 54000126  b.vs     #0xe7ca4
//   0x0e7c84: 52A9F008  mov      w8, #0x4f800000
static inline uint64_t fde_func_1373_0x0e7c78(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e7c78ULL ^ (static_cast<uint64_t>(0xbd400800ULL) << 13);
    acc = (acc + a1 + 0x1e202000ULL) ^ 0x1a9d18ULL;
    acc ^= (acc >> 17) * 0x0088ULL;
    return acc;
}

// FDE #1374 | PC: 0x0e7d00 | FDE: 0x1a9d48 | Size: 96 bytes
// Khung tháo gỡ #1374 | Địa chỉ PC: 0x0e7d00 | Địa chỉ FDE: 0x1a9d48 | Kích thước: 96 bytes
//   0x0e7d00: F9400408  ldr      x8, [x0, #8]
//   0x0e7d04: 90000709  adrp     x9, #0x1c7000
//   0x0e7d08: 91290129  add      x9, x9, #0xa40
//   0x0e7d0c: 39402108  ldrb     w8, [x8, #8]
static inline uint64_t fde_func_1374_0x0e7d00(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e7d00ULL ^ (static_cast<uint64_t>(0xf9400408ULL) << 13);
    acc = (acc + a1 + 0x90000709ULL) ^ 0x1a9d48ULL;
    acc ^= (acc >> 17) * 0x0060ULL;
    return acc;
}

// FDE #1375 | PC: 0x0e7d60 | FDE: 0x1a9d78 | Size: 104 bytes
// Khung tháo gỡ #1375 | Địa chỉ PC: 0x0e7d60 | Địa chỉ FDE: 0x1a9d78 | Kích thước: 104 bytes
//   0x0e7d60: B9800808  ldrsw    x8, [x0, #8]
//   0x0e7d64: D37DF108  lsl      x8, x8, #3
//   0x0e7d68: BC686820  ldr      s0, [x1, x8]
//   0x0e7d6c: 1E202000  fcmp     s0, s0
static inline uint64_t fde_func_1375_0x0e7d60(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e7d60ULL ^ (static_cast<uint64_t>(0xb9800808ULL) << 13);
    acc = (acc + a1 + 0xd37df108ULL) ^ 0x1a9d78ULL;
    acc ^= (acc >> 17) * 0x0068ULL;
    return acc;
}

// FDE #1376 | PC: 0x0e7dc8 | FDE: 0x1a9da8 | Size: 136 bytes
// Khung tháo gỡ #1376 | Địa chỉ PC: 0x0e7dc8 | Địa chỉ FDE: 0x1a9da8 | Kích thước: 136 bytes
//   0x0e7dc8: BD400800  ldr      s0, [x0, #8]
//   0x0e7dcc: 1E202000  fcmp     s0, s0
//   0x0e7dd0: 54000126  b.vs     #0xe7df4
//   0x0e7dd4: 52ABF008  mov      w8, #0x5f800000
static inline uint64_t fde_func_1376_0x0e7dc8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e7dc8ULL ^ (static_cast<uint64_t>(0xbd400800ULL) << 13);
    acc = (acc + a1 + 0x1e202000ULL) ^ 0x1a9da8ULL;
    acc ^= (acc >> 17) * 0x0088ULL;
    return acc;
}

// FDE #1377 | PC: 0x0e7e50 | FDE: 0x1a9dd8 | Size: 48 bytes
// Khung tháo gỡ #1377 | Địa chỉ PC: 0x0e7e50 | Địa chỉ FDE: 0x1a9dd8 | Kích thước: 48 bytes
//   0x0e7e50: F9400408  ldr      x8, [x0, #8]
//   0x0e7e54: 90000709  adrp     x9, #0x1c7000
//   0x0e7e58: 91298129  add      x9, x9, #0xa60
//   0x0e7e5c: 39402108  ldrb     w8, [x8, #8]
static inline uint64_t fde_func_1377_0x0e7e50(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e7e50ULL ^ (static_cast<uint64_t>(0xf9400408ULL) << 13);
    acc = (acc + a1 + 0x90000709ULL) ^ 0x1a9dd8ULL;
    acc ^= (acc >> 17) * 0x0030ULL;
    return acc;
}

// FDE #1378 | PC: 0x0e7e80 | FDE: 0x1a9e08 | Size: 56 bytes
// Khung tháo gỡ #1378 | Địa chỉ PC: 0x0e7e80 | Địa chỉ FDE: 0x1a9e08 | Kích thước: 56 bytes
//   0x0e7e80: B9800808  ldrsw    x8, [x0, #8]
//   0x0e7e84: D37DF108  lsl      x8, x8, #3
//   0x0e7e88: BC686820  ldr      s0, [x1, x8]
//   0x0e7e8c: B9801008  ldrsw    x8, [x0, #0x10]
static inline uint64_t fde_func_1378_0x0e7e80(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e7e80ULL ^ (static_cast<uint64_t>(0xb9800808ULL) << 13);
    acc = (acc + a1 + 0xd37df108ULL) ^ 0x1a9e08ULL;
    acc ^= (acc >> 17) * 0x0038ULL;
    return acc;
}

// FDE #1379 | PC: 0x0e7eb8 | FDE: 0x1a9e38 | Size: 148 bytes
// Khung tháo gỡ #1379 | Địa chỉ PC: 0x0e7eb8 | Địa chỉ FDE: 0x1a9e38 | Kích thước: 148 bytes
//   0x0e7eb8: FD400400  ldr      d0, [x0, #8]
//   0x0e7ebc: 1E602000  fcmp     d0, d0
//   0x0e7ec0: 54000166  b.vs     #0xe7eec
//   0x0e7ec4: D2E83C08  mov      x8, #0x41e0000000000000
static inline uint64_t fde_func_1379_0x0e7eb8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e7eb8ULL ^ (static_cast<uint64_t>(0xfd400400ULL) << 13);
    acc = (acc + a1 + 0x1e602000ULL) ^ 0x1a9e38ULL;
    acc ^= (acc >> 17) * 0x0094ULL;
    return acc;
}

// FDE #1380 | PC: 0x0e7f4c | FDE: 0x1a9e68 | Size: 88 bytes
// Khung tháo gỡ #1380 | Địa chỉ PC: 0x0e7f4c | Địa chỉ FDE: 0x1a9e68 | Kích thước: 88 bytes
//   0x0e7f4c: F9400408  ldr      x8, [x0, #8]
//   0x0e7f50: 90000709  adrp     x9, #0x1c7000
//   0x0e7f54: 912A0129  add      x9, x9, #0xa80
//   0x0e7f58: 39402108  ldrb     w8, [x8, #8]
static inline uint64_t fde_func_1380_0x0e7f4c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e7f4cULL ^ (static_cast<uint64_t>(0xf9400408ULL) << 13);
    acc = (acc + a1 + 0x90000709ULL) ^ 0x1a9e68ULL;
    acc ^= (acc >> 17) * 0x0058ULL;
    return acc;
}

// FDE #1381 | PC: 0x0e7fa4 | FDE: 0x1a9e98 | Size: 92 bytes
// Khung tháo gỡ #1381 | Địa chỉ PC: 0x0e7fa4 | Địa chỉ FDE: 0x1a9e98 | Kích thước: 92 bytes
//   0x0e7fa4: B9800808  ldrsw    x8, [x0, #8]
//   0x0e7fa8: FC687820  ldr      d0, [x1, x8, lsl #3]
//   0x0e7fac: 1E602000  fcmp     d0, d0
//   0x0e7fb0: 54000126  b.vs     #0xe7fd4
static inline uint64_t fde_func_1381_0x0e7fa4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e7fa4ULL ^ (static_cast<uint64_t>(0xb9800808ULL) << 13);
    acc = (acc + a1 + 0xfc687820ULL) ^ 0x1a9e98ULL;
    acc ^= (acc >> 17) * 0x005cULL;
    return acc;
}

// FDE #1382 | PC: 0x0e8000 | FDE: 0x1a9ec8 | Size: 148 bytes
// Khung tháo gỡ #1382 | Địa chỉ PC: 0x0e8000 | Địa chỉ FDE: 0x1a9ec8 | Kích thước: 148 bytes
//   0x0e8000: FD400400  ldr      d0, [x0, #8]
//   0x0e8004: 1E602000  fcmp     d0, d0
//   0x0e8008: 54000166  b.vs     #0xe8034
//   0x0e800c: D2E87C08  mov      x8, #0x43e0000000000000
static inline uint64_t fde_func_1382_0x0e8000(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e8000ULL ^ (static_cast<uint64_t>(0xfd400400ULL) << 13);
    acc = (acc + a1 + 0x1e602000ULL) ^ 0x1a9ec8ULL;
    acc ^= (acc >> 17) * 0x0094ULL;
    return acc;
}

// FDE #1383 | PC: 0x0e8094 | FDE: 0x1a9ef8 | Size: 88 bytes
// Khung tháo gỡ #1383 | Địa chỉ PC: 0x0e8094 | Địa chỉ FDE: 0x1a9ef8 | Kích thước: 88 bytes
//   0x0e8094: F9400408  ldr      x8, [x0, #8]
//   0x0e8098: F00006E9  adrp     x9, #0x1c7000
//   0x0e809c: 912A8129  add      x9, x9, #0xaa0
//   0x0e80a0: 39402108  ldrb     w8, [x8, #8]
static inline uint64_t fde_func_1383_0x0e8094(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e8094ULL ^ (static_cast<uint64_t>(0xf9400408ULL) << 13);
    acc = (acc + a1 + 0xf00006e9ULL) ^ 0x1a9ef8ULL;
    acc ^= (acc >> 17) * 0x0058ULL;
    return acc;
}

// FDE #1384 | PC: 0x0e80ec | FDE: 0x1a9f28 | Size: 92 bytes
// Khung tháo gỡ #1384 | Địa chỉ PC: 0x0e80ec | Địa chỉ FDE: 0x1a9f28 | Kích thước: 92 bytes
//   0x0e80ec: B9800808  ldrsw    x8, [x0, #8]
//   0x0e80f0: FC687820  ldr      d0, [x1, x8, lsl #3]
//   0x0e80f4: 1E602000  fcmp     d0, d0
//   0x0e80f8: 54000126  b.vs     #0xe811c
static inline uint64_t fde_func_1384_0x0e80ec(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e80ecULL ^ (static_cast<uint64_t>(0xb9800808ULL) << 13);
    acc = (acc + a1 + 0xfc687820ULL) ^ 0x1a9f28ULL;
    acc ^= (acc >> 17) * 0x005cULL;
    return acc;
}

// FDE #1385 | PC: 0x0e8148 | FDE: 0x1a9f58 | Size: 60 bytes
// Khung tháo gỡ #1385 | Địa chỉ PC: 0x0e8148 | Địa chỉ FDE: 0x1a9f58 | Kích thước: 60 bytes
//   0x0e8148: FD400400  ldr      d0, [x0, #8]
//   0x0e814c: B9801008  ldrsw    x8, [x0, #0x10]
//   0x0e8150: 1E624000  fcvt     s0, d0
//   0x0e8154: 1E260009  fmov     w9, s0
static inline uint64_t fde_func_1385_0x0e8148(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e8148ULL ^ (static_cast<uint64_t>(0xfd400400ULL) << 13);
    acc = (acc + a1 + 0xb9801008ULL) ^ 0x1a9f58ULL;
    acc ^= (acc >> 17) * 0x003cULL;
    return acc;
}

// FDE #1386 | PC: 0x0e8184 | FDE: 0x1a9f88 | Size: 44 bytes
// Khung tháo gỡ #1386 | Địa chỉ PC: 0x0e8184 | Địa chỉ FDE: 0x1a9f88 | Kích thước: 44 bytes
//   0x0e8184: F9400408  ldr      x8, [x0, #8]
//   0x0e8188: F00006E9  adrp     x9, #0x1c7000
//   0x0e818c: 912B0129  add      x9, x9, #0xac0
//   0x0e8190: 39402108  ldrb     w8, [x8, #8]
static inline uint64_t fde_func_1386_0x0e8184(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e8184ULL ^ (static_cast<uint64_t>(0xf9400408ULL) << 13);
    acc = (acc + a1 + 0xf00006e9ULL) ^ 0x1a9f88ULL;
    acc ^= (acc >> 17) * 0x002cULL;
    return acc;
}

// FDE #1387 | PC: 0x0e81b0 | FDE: 0x1a9fb8 | Size: 36 bytes
// Khung tháo gỡ #1387 | Địa chỉ PC: 0x0e81b0 | Địa chỉ FDE: 0x1a9fb8 | Kích thước: 36 bytes
//   0x0e81b0: B9800808  ldrsw    x8, [x0, #8]
//   0x0e81b4: B9801009  ldrsw    x9, [x0, #0x10]
//   0x0e81b8: F8687828  ldr      x8, [x1, x8, lsl #3]
//   0x0e81bc: F8297828  str      x8, [x1, x9, lsl #3]
static inline uint64_t fde_func_1387_0x0e81b0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e81b0ULL ^ (static_cast<uint64_t>(0xb9800808ULL) << 13);
    acc = (acc + a1 + 0xb9801009ULL) ^ 0x1a9fb8ULL;
    acc ^= (acc >> 17) * 0x0024ULL;
    return acc;
}

// FDE #1388 | PC: 0x0e81d4 | FDE: 0x1a9fe8 | Size: 68 bytes
// Khung tháo gỡ #1388 | Địa chỉ PC: 0x0e81d4 | Địa chỉ FDE: 0x1a9fe8 | Kích thước: 68 bytes
//   0x0e81d4: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x0e81d8: 910003FD  mov      x29, sp
//   0x0e81dc: B9400808  ldr      w8, [x0, #8]
//   0x0e81e0: B9402C49  ldr      w9, [x2, #0x2c]
static inline uint64_t fde_func_1388_0x0e81d4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e81d4ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1a9fe8ULL;
    acc ^= (acc >> 17) * 0x0044ULL;
    return acc;
}

// FDE #1389 | PC: 0x0e8218 | FDE: 0x1aa020 | Size: 96 bytes
// Khung tháo gỡ #1389 | Địa chỉ PC: 0x0e8218 | Địa chỉ FDE: 0x1aa020 | Kích thước: 96 bytes
//   0x0e8218: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x0e821c: 910003FD  mov      x29, sp
//   0x0e8220: B9400808  ldr      w8, [x0, #8]
//   0x0e8224: B9402C49  ldr      w9, [x2, #0x2c]
static inline uint64_t fde_func_1389_0x0e8218(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e8218ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1aa020ULL;
    acc ^= (acc >> 17) * 0x0060ULL;
    return acc;
}

// FDE #1390 | PC: 0x0e8278 | FDE: 0x1aa058 | Size: 84 bytes
// Khung tháo gỡ #1390 | Địa chỉ PC: 0x0e8278 | Địa chỉ FDE: 0x1aa058 | Kích thước: 84 bytes
//   0x0e8278: B9400808  ldr      w8, [x0, #8]
//   0x0e827c: 52800209  mov      w9, #0x10
//   0x0e8280: 7100011F  cmp      w8, #0
//   0x0e8284: 52800308  mov      w8, #0x18
static inline uint64_t fde_func_1390_0x0e8278(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e8278ULL ^ (static_cast<uint64_t>(0xb9400808ULL) << 13);
    acc = (acc + a1 + 0x52800209ULL) ^ 0x1aa058ULL;
    acc ^= (acc >> 17) * 0x0054ULL;
    return acc;
}

// FDE #1391 | PC: 0x0e82cc | FDE: 0x1aa088 | Size: 88 bytes
// Khung tháo gỡ #1391 | Địa chỉ PC: 0x0e82cc | Địa chỉ FDE: 0x1aa088 | Kích thước: 88 bytes
//   0x0e82cc: B9400808  ldr      w8, [x0, #8]
//   0x0e82d0: 34000088  cbz      w8, #0xe82e0
//   0x0e82d4: B9801008  ldrsw    x8, [x0, #0x10]
//   0x0e82d8: 8B080C28  add      x8, x1, x8, lsl #3
static inline uint64_t fde_func_1391_0x0e82cc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e82ccULL ^ (static_cast<uint64_t>(0xb9400808ULL) << 13);
    acc = (acc + a1 + 0x34000088ULL) ^ 0x1aa088ULL;
    acc ^= (acc >> 17) * 0x0058ULL;
    return acc;
}

// FDE #1392 | PC: 0x0e8324 | FDE: 0x1aa0b8 | Size: 100 bytes
// Khung tháo gỡ #1392 | Địa chỉ PC: 0x0e8324 | Địa chỉ FDE: 0x1aa0b8 | Kích thước: 100 bytes
//   0x0e8324: B9800808  ldrsw    x8, [x0, #8]
//   0x0e8328: 52800209  mov      w9, #0x10
//   0x0e832c: D37DF108  lsl      x8, x8, #3
//   0x0e8330: B8686828  ldr      w8, [x1, x8]
static inline uint64_t fde_func_1392_0x0e8324(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e8324ULL ^ (static_cast<uint64_t>(0xb9800808ULL) << 13);
    acc = (acc + a1 + 0x52800209ULL) ^ 0x1aa0b8ULL;
    acc ^= (acc >> 17) * 0x0064ULL;
    return acc;
}

// FDE #1393 | PC: 0x0e8388 | FDE: 0x1aa0e8 | Size: 104 bytes
// Khung tháo gỡ #1393 | Địa chỉ PC: 0x0e8388 | Địa chỉ FDE: 0x1aa0e8 | Kích thước: 104 bytes
//   0x0e8388: B9800808  ldrsw    x8, [x0, #8]
//   0x0e838c: D37DF108  lsl      x8, x8, #3
//   0x0e8390: B8686828  ldr      w8, [x1, x8]
//   0x0e8394: 34000088  cbz      w8, #0xe83a4
static inline uint64_t fde_func_1393_0x0e8388(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e8388ULL ^ (static_cast<uint64_t>(0xb9800808ULL) << 13);
    acc = (acc + a1 + 0xd37df108ULL) ^ 0x1aa0e8ULL;
    acc ^= (acc >> 17) * 0x0068ULL;
    return acc;
}

// FDE #1394 | PC: 0x0e83f0 | FDE: 0x1aa118 | Size: 60 bytes
// Khung tháo gỡ #1394 | Địa chỉ PC: 0x0e83f0 | Địa chỉ FDE: 0x1aa118 | Kích thước: 60 bytes
//   0x0e83f0: F9400408  ldr      x8, [x0, #8]
//   0x0e83f4: F00006E9  adrp     x9, #0x1c7000
//   0x0e83f8: 912C4129  add      x9, x9, #0xb10
//   0x0e83fc: 39402108  ldrb     w8, [x8, #8]
static inline uint64_t fde_func_1394_0x0e83f0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e83f0ULL ^ (static_cast<uint64_t>(0xf9400408ULL) << 13);
    acc = (acc + a1 + 0xf00006e9ULL) ^ 0x1aa118ULL;
    acc ^= (acc >> 17) * 0x003cULL;
    return acc;
}

// FDE #1395 | PC: 0x0e842c | FDE: 0x1aa148 | Size: 80 bytes
// Khung tháo gỡ #1395 | Địa chỉ PC: 0x0e842c | Địa chỉ FDE: 0x1aa148 | Kích thước: 80 bytes
//   0x0e842c: B9800808  ldrsw    x8, [x0, #8]
//   0x0e8430: B9801009  ldrsw    x9, [x0, #0x10]
//   0x0e8434: F8687828  ldr      x8, [x1, x8, lsl #3]
//   0x0e8438: D37DF129  lsl      x9, x9, #3
static inline uint64_t fde_func_1395_0x0e842c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e842cULL ^ (static_cast<uint64_t>(0xb9800808ULL) << 13);
    acc = (acc + a1 + 0xb9801009ULL) ^ 0x1aa148ULL;
    acc ^= (acc >> 17) * 0x0050ULL;
    return acc;
}

// FDE #1396 | PC: 0x0e847c | FDE: 0x1aa178 | Size: 88 bytes
// Khung tháo gỡ #1396 | Địa chỉ PC: 0x0e847c | Địa chỉ FDE: 0x1aa178 | Kích thước: 88 bytes
//   0x0e847c: B9400808  ldr      w8, [x0, #8]
//   0x0e8480: B9401009  ldr      w9, [x0, #0x10]
//   0x0e8484: B980180A  ldrsw    x10, [x0, #0x18]
//   0x0e8488: 6B09011F  cmp      w8, w9
static inline uint64_t fde_func_1396_0x0e847c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e847cULL ^ (static_cast<uint64_t>(0xb9400808ULL) << 13);
    acc = (acc + a1 + 0xb9401009ULL) ^ 0x1aa178ULL;
    acc ^= (acc >> 17) * 0x0058ULL;
    return acc;
}

// FDE #1397 | PC: 0x0e84d4 | FDE: 0x1aa1a8 | Size: 104 bytes
// Khung tháo gỡ #1397 | Địa chỉ PC: 0x0e84d4 | Địa chỉ FDE: 0x1aa1a8 | Kích thước: 104 bytes
//   0x0e84d4: B9800808  ldrsw    x8, [x0, #8]
//   0x0e84d8: B9401009  ldr      w9, [x0, #0x10]
//   0x0e84dc: B980180A  ldrsw    x10, [x0, #0x18]
//   0x0e84e0: D37DF108  lsl      x8, x8, #3
static inline uint64_t fde_func_1397_0x0e84d4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e84d4ULL ^ (static_cast<uint64_t>(0xb9800808ULL) << 13);
    acc = (acc + a1 + 0xb9401009ULL) ^ 0x1aa1a8ULL;
    acc ^= (acc >> 17) * 0x0068ULL;
    return acc;
}

// FDE #1398 | PC: 0x0e853c | FDE: 0x1aa1d8 | Size: 80 bytes
// Khung tháo gỡ #1398 | Địa chỉ PC: 0x0e853c | Địa chỉ FDE: 0x1aa1d8 | Kích thước: 80 bytes
//   0x0e853c: A940A408  ldp      x8, x9, [x0, #8]
//   0x0e8540: B980180A  ldrsw    x10, [x0, #0x18]
//   0x0e8544: EB09011F  cmp      x8, x9
//   0x0e8548: D37DF148  lsl      x8, x10, #3
static inline uint64_t fde_func_1398_0x0e853c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e853cULL ^ (static_cast<uint64_t>(0xa940a408ULL) << 13);
    acc = (acc + a1 + 0xb980180aULL) ^ 0x1aa1d8ULL;
    acc ^= (acc >> 17) * 0x0050ULL;
    return acc;
}

// FDE #1399 | PC: 0x0e858c | FDE: 0x1aa208 | Size: 92 bytes
// Khung tháo gỡ #1399 | Địa chỉ PC: 0x0e858c | Địa chỉ FDE: 0x1aa208 | Kích thước: 92 bytes
//   0x0e858c: B9800808  ldrsw    x8, [x0, #8]
//   0x0e8590: F9400809  ldr      x9, [x0, #0x10]
//   0x0e8594: B980180A  ldrsw    x10, [x0, #0x18]
//   0x0e8598: F8687828  ldr      x8, [x1, x8, lsl #3]
static inline uint64_t fde_func_1399_0x0e858c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e858cULL ^ (static_cast<uint64_t>(0xb9800808ULL) << 13);
    acc = (acc + a1 + 0xf9400809ULL) ^ 0x1aa208ULL;
    acc ^= (acc >> 17) * 0x005cULL;
    return acc;
}

// FDE #1400 | PC: 0x0e85e8 | FDE: 0x1aa238 | Size: 88 bytes
// Khung tháo gỡ #1400 | Địa chỉ PC: 0x0e85e8 | Địa chỉ FDE: 0x1aa238 | Kích thước: 88 bytes
//   0x0e85e8: BD400800  ldr      s0, [x0, #8]
//   0x0e85ec: BD401001  ldr      s1, [x0, #0x10]
//   0x0e85f0: B9801808  ldrsw    x8, [x0, #0x18]
//   0x0e85f4: 1E212000  fcmp     s0, s1
static inline uint64_t fde_func_1400_0x0e85e8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e85e8ULL ^ (static_cast<uint64_t>(0xbd400800ULL) << 13);
    acc = (acc + a1 + 0xbd401001ULL) ^ 0x1aa238ULL;
    acc ^= (acc >> 17) * 0x0058ULL;
    return acc;
}

// FDE #1401 | PC: 0x0e8640 | FDE: 0x1aa268 | Size: 104 bytes
// Khung tháo gỡ #1401 | Địa chỉ PC: 0x0e8640 | Địa chỉ FDE: 0x1aa268 | Kích thước: 104 bytes
//   0x0e8640: B9800808  ldrsw    x8, [x0, #8]
//   0x0e8644: BD401000  ldr      s0, [x0, #0x10]
//   0x0e8648: B9801809  ldrsw    x9, [x0, #0x18]
//   0x0e864c: D37DF108  lsl      x8, x8, #3
static inline uint64_t fde_func_1401_0x0e8640(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e8640ULL ^ (static_cast<uint64_t>(0xb9800808ULL) << 13);
    acc = (acc + a1 + 0xbd401000ULL) ^ 0x1aa268ULL;
    acc ^= (acc >> 17) * 0x0068ULL;
    return acc;
}

// FDE #1402 | PC: 0x0e86a8 | FDE: 0x1aa298 | Size: 80 bytes
// Khung tháo gỡ #1402 | Địa chỉ PC: 0x0e86a8 | Địa chỉ FDE: 0x1aa298 | Kích thước: 80 bytes
//   0x0e86a8: 6D408400  ldp      d0, d1, [x0, #8]
//   0x0e86ac: B9801808  ldrsw    x8, [x0, #0x18]
//   0x0e86b0: 1E612000  fcmp     d0, d1
//   0x0e86b4: D37DF108  lsl      x8, x8, #3
static inline uint64_t fde_func_1402_0x0e86a8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e86a8ULL ^ (static_cast<uint64_t>(0x6d408400ULL) << 13);
    acc = (acc + a1 + 0xb9801808ULL) ^ 0x1aa298ULL;
    acc ^= (acc >> 17) * 0x0050ULL;
    return acc;
}

// FDE #1403 | PC: 0x0e86f8 | FDE: 0x1aa2c8 | Size: 92 bytes
// Khung tháo gỡ #1403 | Địa chỉ PC: 0x0e86f8 | Địa chỉ FDE: 0x1aa2c8 | Kích thước: 92 bytes
//   0x0e86f8: B9800808  ldrsw    x8, [x0, #8]
//   0x0e86fc: FD400800  ldr      d0, [x0, #0x10]
//   0x0e8700: B9801809  ldrsw    x9, [x0, #0x18]
//   0x0e8704: FC687821  ldr      d1, [x1, x8, lsl #3]
static inline uint64_t fde_func_1403_0x0e86f8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e86f8ULL ^ (static_cast<uint64_t>(0xb9800808ULL) << 13);
    acc = (acc + a1 + 0xfd400800ULL) ^ 0x1aa2c8ULL;
    acc ^= (acc >> 17) * 0x005cULL;
    return acc;
}

// FDE #1404 | PC: 0x0e8754 | FDE: 0x1aa2f8 | Size: 80 bytes
// Khung tháo gỡ #1404 | Địa chỉ PC: 0x0e8754 | Địa chỉ FDE: 0x1aa2f8 | Kích thước: 80 bytes
//   0x0e8754: F9400408  ldr      x8, [x0, #8]
//   0x0e8758: F00006EB  adrp     x11, #0x1c7000
//   0x0e875c: 912E816B  add      x11, x11, #0xba0
//   0x0e8760: 79402509  ldrh     w9, [x8, #0x12]
static inline uint64_t fde_func_1404_0x0e8754(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e8754ULL ^ (static_cast<uint64_t>(0xf9400408ULL) << 13);
    acc = (acc + a1 + 0xf00006ebULL) ^ 0x1aa2f8ULL;
    acc ^= (acc >> 17) * 0x0050ULL;
    return acc;
}

// FDE #1405 | PC: 0x0e87a4 | FDE: 0x1aa328 | Size: 96 bytes
// Khung tháo gỡ #1405 | Địa chỉ PC: 0x0e87a4 | Địa chỉ FDE: 0x1aa328 | Kích thước: 96 bytes
//   0x0e87a4: B9801008  ldrsw    x8, [x0, #0x10]
//   0x0e87a8: B9400809  ldr      w9, [x0, #8]
//   0x0e87ac: B980180A  ldrsw    x10, [x0, #0x18]
//   0x0e87b0: D37DF108  lsl      x8, x8, #3
static inline uint64_t fde_func_1405_0x0e87a4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e87a4ULL ^ (static_cast<uint64_t>(0xb9801008ULL) << 13);
    acc = (acc + a1 + 0xb9400809ULL) ^ 0x1aa328ULL;
    acc ^= (acc >> 17) * 0x0060ULL;
    return acc;
}

// FDE #1406 | PC: 0x0e8804 | FDE: 0x1aa358 | Size: 92 bytes
// Khung tháo gỡ #1406 | Địa chỉ PC: 0x0e8804 | Địa chỉ FDE: 0x1aa358 | Kích thước: 92 bytes
//   0x0e8804: B9800808  ldrsw    x8, [x0, #8]
//   0x0e8808: B9801009  ldrsw    x9, [x0, #0x10]
//   0x0e880c: B980180A  ldrsw    x10, [x0, #0x18]
//   0x0e8810: D37DF108  lsl      x8, x8, #3
static inline uint64_t fde_func_1406_0x0e8804(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e8804ULL ^ (static_cast<uint64_t>(0xb9800808ULL) << 13);
    acc = (acc + a1 + 0xb9801009ULL) ^ 0x1aa358ULL;
    acc ^= (acc >> 17) * 0x005cULL;
    return acc;
}

// FDE #1407 | PC: 0x0e8860 | FDE: 0x1aa388 | Size: 88 bytes
// Khung tháo gỡ #1407 | Địa chỉ PC: 0x0e8860 | Địa chỉ FDE: 0x1aa388 | Kích thước: 88 bytes
//   0x0e8860: B9801008  ldrsw    x8, [x0, #0x10]
//   0x0e8864: F9400409  ldr      x9, [x0, #8]
//   0x0e8868: B980180A  ldrsw    x10, [x0, #0x18]
//   0x0e886c: F8687828  ldr      x8, [x1, x8, lsl #3]
static inline uint64_t fde_func_1407_0x0e8860(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e8860ULL ^ (static_cast<uint64_t>(0xb9801008ULL) << 13);
    acc = (acc + a1 + 0xf9400409ULL) ^ 0x1aa388ULL;
    acc ^= (acc >> 17) * 0x0058ULL;
    return acc;
}

// FDE #1408 | PC: 0x0e88b8 | FDE: 0x1aa3b8 | Size: 88 bytes
// Khung tháo gỡ #1408 | Địa chỉ PC: 0x0e88b8 | Địa chỉ FDE: 0x1aa3b8 | Kích thước: 88 bytes
//   0x0e88b8: B9800808  ldrsw    x8, [x0, #8]
//   0x0e88bc: B9801009  ldrsw    x9, [x0, #0x10]
//   0x0e88c0: B980180A  ldrsw    x10, [x0, #0x18]
//   0x0e88c4: F8687828  ldr      x8, [x1, x8, lsl #3]
static inline uint64_t fde_func_1408_0x0e88b8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e88b8ULL ^ (static_cast<uint64_t>(0xb9800808ULL) << 13);
    acc = (acc + a1 + 0xb9801009ULL) ^ 0x1aa3b8ULL;
    acc ^= (acc >> 17) * 0x0058ULL;
    return acc;
}

// FDE #1409 | PC: 0x0e8910 | FDE: 0x1aa3e8 | Size: 96 bytes
// Khung tháo gỡ #1409 | Địa chỉ PC: 0x0e8910 | Địa chỉ FDE: 0x1aa3e8 | Kích thước: 96 bytes
//   0x0e8910: B9801008  ldrsw    x8, [x0, #0x10]
//   0x0e8914: BD400800  ldr      s0, [x0, #8]
//   0x0e8918: B9801809  ldrsw    x9, [x0, #0x18]
//   0x0e891c: D37DF108  lsl      x8, x8, #3
static inline uint64_t fde_func_1409_0x0e8910(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e8910ULL ^ (static_cast<uint64_t>(0xb9801008ULL) << 13);
    acc = (acc + a1 + 0xbd400800ULL) ^ 0x1aa3e8ULL;
    acc ^= (acc >> 17) * 0x0060ULL;
    return acc;
}

// FDE #1410 | PC: 0x0e8970 | FDE: 0x1aa418 | Size: 92 bytes
// Khung tháo gỡ #1410 | Địa chỉ PC: 0x0e8970 | Địa chỉ FDE: 0x1aa418 | Kích thước: 92 bytes
//   0x0e8970: B9800808  ldrsw    x8, [x0, #8]
//   0x0e8974: B9801009  ldrsw    x9, [x0, #0x10]
//   0x0e8978: D37DF108  lsl      x8, x8, #3
//   0x0e897c: D37DF129  lsl      x9, x9, #3
static inline uint64_t fde_func_1410_0x0e8970(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e8970ULL ^ (static_cast<uint64_t>(0xb9800808ULL) << 13);
    acc = (acc + a1 + 0xb9801009ULL) ^ 0x1aa418ULL;
    acc ^= (acc >> 17) * 0x005cULL;
    return acc;
}

// FDE #1411 | PC: 0x0e89cc | FDE: 0x1aa448 | Size: 88 bytes
// Khung tháo gỡ #1411 | Địa chỉ PC: 0x0e89cc | Địa chỉ FDE: 0x1aa448 | Kích thước: 88 bytes
//   0x0e89cc: B9801008  ldrsw    x8, [x0, #0x10]
//   0x0e89d0: FD400400  ldr      d0, [x0, #8]
//   0x0e89d4: B9801809  ldrsw    x9, [x0, #0x18]
//   0x0e89d8: FC687821  ldr      d1, [x1, x8, lsl #3]
static inline uint64_t fde_func_1411_0x0e89cc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e89ccULL ^ (static_cast<uint64_t>(0xb9801008ULL) << 13);
    acc = (acc + a1 + 0xfd400400ULL) ^ 0x1aa448ULL;
    acc ^= (acc >> 17) * 0x0058ULL;
    return acc;
}

// FDE #1412 | PC: 0x0e8a24 | FDE: 0x1aa478 | Size: 88 bytes
// Khung tháo gỡ #1412 | Địa chỉ PC: 0x0e8a24 | Địa chỉ FDE: 0x1aa478 | Kích thước: 88 bytes
//   0x0e8a24: B9800808  ldrsw    x8, [x0, #8]
//   0x0e8a28: B9801009  ldrsw    x9, [x0, #0x10]
//   0x0e8a2c: FC687820  ldr      d0, [x1, x8, lsl #3]
//   0x0e8a30: FC697821  ldr      d1, [x1, x9, lsl #3]
static inline uint64_t fde_func_1412_0x0e8a24(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e8a24ULL ^ (static_cast<uint64_t>(0xb9800808ULL) << 13);
    acc = (acc + a1 + 0xb9801009ULL) ^ 0x1aa478ULL;
    acc ^= (acc >> 17) * 0x0058ULL;
    return acc;
}

// FDE #1413 | PC: 0x0e8a7c | FDE: 0x1aa4a8 | Size: 88 bytes
// Khung tháo gỡ #1413 | Địa chỉ PC: 0x0e8a7c | Địa chỉ FDE: 0x1aa4a8 | Kích thước: 88 bytes
//   0x0e8a7c: B9400808  ldr      w8, [x0, #8]
//   0x0e8a80: B9401009  ldr      w9, [x0, #0x10]
//   0x0e8a84: B980180A  ldrsw    x10, [x0, #0x18]
//   0x0e8a88: 6B09011F  cmp      w8, w9
static inline uint64_t fde_func_1413_0x0e8a7c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e8a7cULL ^ (static_cast<uint64_t>(0xb9400808ULL) << 13);
    acc = (acc + a1 + 0xb9401009ULL) ^ 0x1aa4a8ULL;
    acc ^= (acc >> 17) * 0x0058ULL;
    return acc;
}

// FDE #1414 | PC: 0x0e8ad4 | FDE: 0x1aa4d8 | Size: 104 bytes
// Khung tháo gỡ #1414 | Địa chỉ PC: 0x0e8ad4 | Địa chỉ FDE: 0x1aa4d8 | Kích thước: 104 bytes
//   0x0e8ad4: B9800808  ldrsw    x8, [x0, #8]
//   0x0e8ad8: B9401009  ldr      w9, [x0, #0x10]
//   0x0e8adc: B980180A  ldrsw    x10, [x0, #0x18]
//   0x0e8ae0: D37DF108  lsl      x8, x8, #3
static inline uint64_t fde_func_1414_0x0e8ad4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e8ad4ULL ^ (static_cast<uint64_t>(0xb9800808ULL) << 13);
    acc = (acc + a1 + 0xb9401009ULL) ^ 0x1aa4d8ULL;
    acc ^= (acc >> 17) * 0x0068ULL;
    return acc;
}

// FDE #1415 | PC: 0x0e8b3c | FDE: 0x1aa508 | Size: 80 bytes
// Khung tháo gỡ #1415 | Địa chỉ PC: 0x0e8b3c | Địa chỉ FDE: 0x1aa508 | Kích thước: 80 bytes
//   0x0e8b3c: A940A408  ldp      x8, x9, [x0, #8]
//   0x0e8b40: B980180A  ldrsw    x10, [x0, #0x18]
//   0x0e8b44: EB09011F  cmp      x8, x9
//   0x0e8b48: D37DF148  lsl      x8, x10, #3
static inline uint64_t fde_func_1415_0x0e8b3c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e8b3cULL ^ (static_cast<uint64_t>(0xa940a408ULL) << 13);
    acc = (acc + a1 + 0xb980180aULL) ^ 0x1aa508ULL;
    acc ^= (acc >> 17) * 0x0050ULL;
    return acc;
}

// FDE #1416 | PC: 0x0e8b8c | FDE: 0x1aa538 | Size: 92 bytes
// Khung tháo gỡ #1416 | Địa chỉ PC: 0x0e8b8c | Địa chỉ FDE: 0x1aa538 | Kích thước: 92 bytes
//   0x0e8b8c: B9800808  ldrsw    x8, [x0, #8]
//   0x0e8b90: F9400809  ldr      x9, [x0, #0x10]
//   0x0e8b94: B980180A  ldrsw    x10, [x0, #0x18]
//   0x0e8b98: F8687828  ldr      x8, [x1, x8, lsl #3]
static inline uint64_t fde_func_1416_0x0e8b8c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e8b8cULL ^ (static_cast<uint64_t>(0xb9800808ULL) << 13);
    acc = (acc + a1 + 0xf9400809ULL) ^ 0x1aa538ULL;
    acc ^= (acc >> 17) * 0x005cULL;
    return acc;
}

// FDE #1417 | PC: 0x0e8be8 | FDE: 0x1aa568 | Size: 88 bytes
// Khung tháo gỡ #1417 | Địa chỉ PC: 0x0e8be8 | Địa chỉ FDE: 0x1aa568 | Kích thước: 88 bytes
//   0x0e8be8: BD400800  ldr      s0, [x0, #8]
//   0x0e8bec: BD401001  ldr      s1, [x0, #0x10]
//   0x0e8bf0: B9801808  ldrsw    x8, [x0, #0x18]
//   0x0e8bf4: 1E212000  fcmp     s0, s1
static inline uint64_t fde_func_1417_0x0e8be8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e8be8ULL ^ (static_cast<uint64_t>(0xbd400800ULL) << 13);
    acc = (acc + a1 + 0xbd401001ULL) ^ 0x1aa568ULL;
    acc ^= (acc >> 17) * 0x0058ULL;
    return acc;
}

// FDE #1418 | PC: 0x0e8c40 | FDE: 0x1aa598 | Size: 104 bytes
// Khung tháo gỡ #1418 | Địa chỉ PC: 0x0e8c40 | Địa chỉ FDE: 0x1aa598 | Kích thước: 104 bytes
//   0x0e8c40: B9800808  ldrsw    x8, [x0, #8]
//   0x0e8c44: BD401000  ldr      s0, [x0, #0x10]
//   0x0e8c48: B9801809  ldrsw    x9, [x0, #0x18]
//   0x0e8c4c: D37DF108  lsl      x8, x8, #3
static inline uint64_t fde_func_1418_0x0e8c40(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e8c40ULL ^ (static_cast<uint64_t>(0xb9800808ULL) << 13);
    acc = (acc + a1 + 0xbd401000ULL) ^ 0x1aa598ULL;
    acc ^= (acc >> 17) * 0x0068ULL;
    return acc;
}

// FDE #1419 | PC: 0x0e8ca8 | FDE: 0x1aa5c8 | Size: 80 bytes
// Khung tháo gỡ #1419 | Địa chỉ PC: 0x0e8ca8 | Địa chỉ FDE: 0x1aa5c8 | Kích thước: 80 bytes
//   0x0e8ca8: 6D408400  ldp      d0, d1, [x0, #8]
//   0x0e8cac: B9801808  ldrsw    x8, [x0, #0x18]
//   0x0e8cb0: 1E612000  fcmp     d0, d1
//   0x0e8cb4: D37DF108  lsl      x8, x8, #3
static inline uint64_t fde_func_1419_0x0e8ca8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e8ca8ULL ^ (static_cast<uint64_t>(0x6d408400ULL) << 13);
    acc = (acc + a1 + 0xb9801808ULL) ^ 0x1aa5c8ULL;
    acc ^= (acc >> 17) * 0x0050ULL;
    return acc;
}

// FDE #1420 | PC: 0x0e8cf8 | FDE: 0x1aa5f8 | Size: 92 bytes
// Khung tháo gỡ #1420 | Địa chỉ PC: 0x0e8cf8 | Địa chỉ FDE: 0x1aa5f8 | Kích thước: 92 bytes
//   0x0e8cf8: B9800808  ldrsw    x8, [x0, #8]
//   0x0e8cfc: FD400800  ldr      d0, [x0, #0x10]
//   0x0e8d00: B9801809  ldrsw    x9, [x0, #0x18]
//   0x0e8d04: FC687821  ldr      d1, [x1, x8, lsl #3]
static inline uint64_t fde_func_1420_0x0e8cf8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e8cf8ULL ^ (static_cast<uint64_t>(0xb9800808ULL) << 13);
    acc = (acc + a1 + 0xfd400800ULL) ^ 0x1aa5f8ULL;
    acc ^= (acc >> 17) * 0x005cULL;
    return acc;
}

// FDE #1421 | PC: 0x0e8d54 | FDE: 0x1aa628 | Size: 80 bytes
// Khung tháo gỡ #1421 | Địa chỉ PC: 0x0e8d54 | Địa chỉ FDE: 0x1aa628 | Kích thước: 80 bytes
//   0x0e8d54: F9400408  ldr      x8, [x0, #8]
//   0x0e8d58: F00006EB  adrp     x11, #0x1c7000
//   0x0e8d5c: 9132816B  add      x11, x11, #0xca0
//   0x0e8d60: 79402509  ldrh     w9, [x8, #0x12]
static inline uint64_t fde_func_1421_0x0e8d54(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e8d54ULL ^ (static_cast<uint64_t>(0xf9400408ULL) << 13);
    acc = (acc + a1 + 0xf00006ebULL) ^ 0x1aa628ULL;
    acc ^= (acc >> 17) * 0x0050ULL;
    return acc;
}

// FDE #1422 | PC: 0x0e8da4 | FDE: 0x1aa658 | Size: 96 bytes
// Khung tháo gỡ #1422 | Địa chỉ PC: 0x0e8da4 | Địa chỉ FDE: 0x1aa658 | Kích thước: 96 bytes
//   0x0e8da4: B9801008  ldrsw    x8, [x0, #0x10]
//   0x0e8da8: B9400809  ldr      w9, [x0, #8]
//   0x0e8dac: B980180A  ldrsw    x10, [x0, #0x18]
//   0x0e8db0: D37DF108  lsl      x8, x8, #3
static inline uint64_t fde_func_1422_0x0e8da4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e8da4ULL ^ (static_cast<uint64_t>(0xb9801008ULL) << 13);
    acc = (acc + a1 + 0xb9400809ULL) ^ 0x1aa658ULL;
    acc ^= (acc >> 17) * 0x0060ULL;
    return acc;
}

// FDE #1423 | PC: 0x0e8e04 | FDE: 0x1aa688 | Size: 92 bytes
// Khung tháo gỡ #1423 | Địa chỉ PC: 0x0e8e04 | Địa chỉ FDE: 0x1aa688 | Kích thước: 92 bytes
//   0x0e8e04: B9800808  ldrsw    x8, [x0, #8]
//   0x0e8e08: B9801009  ldrsw    x9, [x0, #0x10]
//   0x0e8e0c: B980180A  ldrsw    x10, [x0, #0x18]
//   0x0e8e10: D37DF108  lsl      x8, x8, #3
static inline uint64_t fde_func_1423_0x0e8e04(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e8e04ULL ^ (static_cast<uint64_t>(0xb9800808ULL) << 13);
    acc = (acc + a1 + 0xb9801009ULL) ^ 0x1aa688ULL;
    acc ^= (acc >> 17) * 0x005cULL;
    return acc;
}

// FDE #1424 | PC: 0x0e8e60 | FDE: 0x1aa6b8 | Size: 88 bytes
// Khung tháo gỡ #1424 | Địa chỉ PC: 0x0e8e60 | Địa chỉ FDE: 0x1aa6b8 | Kích thước: 88 bytes
//   0x0e8e60: B9801008  ldrsw    x8, [x0, #0x10]
//   0x0e8e64: F9400409  ldr      x9, [x0, #8]
//   0x0e8e68: B980180A  ldrsw    x10, [x0, #0x18]
//   0x0e8e6c: F8687828  ldr      x8, [x1, x8, lsl #3]
static inline uint64_t fde_func_1424_0x0e8e60(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e8e60ULL ^ (static_cast<uint64_t>(0xb9801008ULL) << 13);
    acc = (acc + a1 + 0xf9400409ULL) ^ 0x1aa6b8ULL;
    acc ^= (acc >> 17) * 0x0058ULL;
    return acc;
}

// FDE #1425 | PC: 0x0e8eb8 | FDE: 0x1aa6e8 | Size: 88 bytes
// Khung tháo gỡ #1425 | Địa chỉ PC: 0x0e8eb8 | Địa chỉ FDE: 0x1aa6e8 | Kích thước: 88 bytes
//   0x0e8eb8: B9800808  ldrsw    x8, [x0, #8]
//   0x0e8ebc: B9801009  ldrsw    x9, [x0, #0x10]
//   0x0e8ec0: B980180A  ldrsw    x10, [x0, #0x18]
//   0x0e8ec4: F8687828  ldr      x8, [x1, x8, lsl #3]
static inline uint64_t fde_func_1425_0x0e8eb8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e8eb8ULL ^ (static_cast<uint64_t>(0xb9800808ULL) << 13);
    acc = (acc + a1 + 0xb9801009ULL) ^ 0x1aa6e8ULL;
    acc ^= (acc >> 17) * 0x0058ULL;
    return acc;
}

// FDE #1426 | PC: 0x0e8f10 | FDE: 0x1aa718 | Size: 96 bytes
// Khung tháo gỡ #1426 | Địa chỉ PC: 0x0e8f10 | Địa chỉ FDE: 0x1aa718 | Kích thước: 96 bytes
//   0x0e8f10: B9801008  ldrsw    x8, [x0, #0x10]
//   0x0e8f14: BD400800  ldr      s0, [x0, #8]
//   0x0e8f18: B9801809  ldrsw    x9, [x0, #0x18]
//   0x0e8f1c: D37DF108  lsl      x8, x8, #3
static inline uint64_t fde_func_1426_0x0e8f10(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e8f10ULL ^ (static_cast<uint64_t>(0xb9801008ULL) << 13);
    acc = (acc + a1 + 0xbd400800ULL) ^ 0x1aa718ULL;
    acc ^= (acc >> 17) * 0x0060ULL;
    return acc;
}

// FDE #1427 | PC: 0x0e8f70 | FDE: 0x1aa748 | Size: 92 bytes
// Khung tháo gỡ #1427 | Địa chỉ PC: 0x0e8f70 | Địa chỉ FDE: 0x1aa748 | Kích thước: 92 bytes
//   0x0e8f70: B9800808  ldrsw    x8, [x0, #8]
//   0x0e8f74: B9801009  ldrsw    x9, [x0, #0x10]
//   0x0e8f78: D37DF108  lsl      x8, x8, #3
//   0x0e8f7c: D37DF129  lsl      x9, x9, #3
static inline uint64_t fde_func_1427_0x0e8f70(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e8f70ULL ^ (static_cast<uint64_t>(0xb9800808ULL) << 13);
    acc = (acc + a1 + 0xb9801009ULL) ^ 0x1aa748ULL;
    acc ^= (acc >> 17) * 0x005cULL;
    return acc;
}

// FDE #1428 | PC: 0x0e8fcc | FDE: 0x1aa778 | Size: 88 bytes
// Khung tháo gỡ #1428 | Địa chỉ PC: 0x0e8fcc | Địa chỉ FDE: 0x1aa778 | Kích thước: 88 bytes
//   0x0e8fcc: B9801008  ldrsw    x8, [x0, #0x10]
//   0x0e8fd0: FD400400  ldr      d0, [x0, #8]
//   0x0e8fd4: B9801809  ldrsw    x9, [x0, #0x18]
//   0x0e8fd8: FC687821  ldr      d1, [x1, x8, lsl #3]
static inline uint64_t fde_func_1428_0x0e8fcc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e8fccULL ^ (static_cast<uint64_t>(0xb9801008ULL) << 13);
    acc = (acc + a1 + 0xfd400400ULL) ^ 0x1aa778ULL;
    acc ^= (acc >> 17) * 0x0058ULL;
    return acc;
}

// FDE #1429 | PC: 0x0e9024 | FDE: 0x1aa7a8 | Size: 88 bytes
// Khung tháo gỡ #1429 | Địa chỉ PC: 0x0e9024 | Địa chỉ FDE: 0x1aa7a8 | Kích thước: 88 bytes
//   0x0e9024: B9800808  ldrsw    x8, [x0, #8]
//   0x0e9028: B9801009  ldrsw    x9, [x0, #0x10]
//   0x0e902c: FC687820  ldr      d0, [x1, x8, lsl #3]
//   0x0e9030: FC697821  ldr      d1, [x1, x9, lsl #3]
static inline uint64_t fde_func_1429_0x0e9024(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e9024ULL ^ (static_cast<uint64_t>(0xb9800808ULL) << 13);
    acc = (acc + a1 + 0xb9801009ULL) ^ 0x1aa7a8ULL;
    acc ^= (acc >> 17) * 0x0058ULL;
    return acc;
}

// FDE #1430 | PC: 0x0e907c | FDE: 0x1aa7d8 | Size: 88 bytes
// Khung tháo gỡ #1430 | Địa chỉ PC: 0x0e907c | Địa chỉ FDE: 0x1aa7d8 | Kích thước: 88 bytes
//   0x0e907c: B9400808  ldr      w8, [x0, #8]
//   0x0e9080: B9401009  ldr      w9, [x0, #0x10]
//   0x0e9084: B980180A  ldrsw    x10, [x0, #0x18]
//   0x0e9088: 6B09011F  cmp      w8, w9
static inline uint64_t fde_func_1430_0x0e907c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e907cULL ^ (static_cast<uint64_t>(0xb9400808ULL) << 13);
    acc = (acc + a1 + 0xb9401009ULL) ^ 0x1aa7d8ULL;
    acc ^= (acc >> 17) * 0x0058ULL;
    return acc;
}

// FDE #1431 | PC: 0x0e90d4 | FDE: 0x1aa808 | Size: 104 bytes
// Khung tháo gỡ #1431 | Địa chỉ PC: 0x0e90d4 | Địa chỉ FDE: 0x1aa808 | Kích thước: 104 bytes
//   0x0e90d4: B9800808  ldrsw    x8, [x0, #8]
//   0x0e90d8: B9401009  ldr      w9, [x0, #0x10]
//   0x0e90dc: B980180A  ldrsw    x10, [x0, #0x18]
//   0x0e90e0: D37DF108  lsl      x8, x8, #3
static inline uint64_t fde_func_1431_0x0e90d4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e90d4ULL ^ (static_cast<uint64_t>(0xb9800808ULL) << 13);
    acc = (acc + a1 + 0xb9401009ULL) ^ 0x1aa808ULL;
    acc ^= (acc >> 17) * 0x0068ULL;
    return acc;
}

// FDE #1432 | PC: 0x0e913c | FDE: 0x1aa838 | Size: 80 bytes
// Khung tháo gỡ #1432 | Địa chỉ PC: 0x0e913c | Địa chỉ FDE: 0x1aa838 | Kích thước: 80 bytes
//   0x0e913c: A940A408  ldp      x8, x9, [x0, #8]
//   0x0e9140: B980180A  ldrsw    x10, [x0, #0x18]
//   0x0e9144: EB09011F  cmp      x8, x9
//   0x0e9148: D37DF148  lsl      x8, x10, #3
static inline uint64_t fde_func_1432_0x0e913c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e913cULL ^ (static_cast<uint64_t>(0xa940a408ULL) << 13);
    acc = (acc + a1 + 0xb980180aULL) ^ 0x1aa838ULL;
    acc ^= (acc >> 17) * 0x0050ULL;
    return acc;
}

// FDE #1433 | PC: 0x0e918c | FDE: 0x1aa868 | Size: 92 bytes
// Khung tháo gỡ #1433 | Địa chỉ PC: 0x0e918c | Địa chỉ FDE: 0x1aa868 | Kích thước: 92 bytes
//   0x0e918c: B9800808  ldrsw    x8, [x0, #8]
//   0x0e9190: F9400809  ldr      x9, [x0, #0x10]
//   0x0e9194: B980180A  ldrsw    x10, [x0, #0x18]
//   0x0e9198: F8687828  ldr      x8, [x1, x8, lsl #3]
static inline uint64_t fde_func_1433_0x0e918c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e918cULL ^ (static_cast<uint64_t>(0xb9800808ULL) << 13);
    acc = (acc + a1 + 0xf9400809ULL) ^ 0x1aa868ULL;
    acc ^= (acc >> 17) * 0x005cULL;
    return acc;
}

// FDE #1434 | PC: 0x0e91e8 | FDE: 0x1aa898 | Size: 88 bytes
// Khung tháo gỡ #1434 | Địa chỉ PC: 0x0e91e8 | Địa chỉ FDE: 0x1aa898 | Kích thước: 88 bytes
//   0x0e91e8: BD400800  ldr      s0, [x0, #8]
//   0x0e91ec: BD401001  ldr      s1, [x0, #0x10]
//   0x0e91f0: B9801808  ldrsw    x8, [x0, #0x18]
//   0x0e91f4: 1E212000  fcmp     s0, s1
static inline uint64_t fde_func_1434_0x0e91e8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e91e8ULL ^ (static_cast<uint64_t>(0xbd400800ULL) << 13);
    acc = (acc + a1 + 0xbd401001ULL) ^ 0x1aa898ULL;
    acc ^= (acc >> 17) * 0x0058ULL;
    return acc;
}

// FDE #1435 | PC: 0x0e9240 | FDE: 0x1aa8c8 | Size: 104 bytes
// Khung tháo gỡ #1435 | Địa chỉ PC: 0x0e9240 | Địa chỉ FDE: 0x1aa8c8 | Kích thước: 104 bytes
//   0x0e9240: B9800808  ldrsw    x8, [x0, #8]
//   0x0e9244: BD401000  ldr      s0, [x0, #0x10]
//   0x0e9248: B9801809  ldrsw    x9, [x0, #0x18]
//   0x0e924c: D37DF108  lsl      x8, x8, #3
static inline uint64_t fde_func_1435_0x0e9240(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e9240ULL ^ (static_cast<uint64_t>(0xb9800808ULL) << 13);
    acc = (acc + a1 + 0xbd401000ULL) ^ 0x1aa8c8ULL;
    acc ^= (acc >> 17) * 0x0068ULL;
    return acc;
}

// FDE #1436 | PC: 0x0e92a8 | FDE: 0x1aa8f8 | Size: 80 bytes
// Khung tháo gỡ #1436 | Địa chỉ PC: 0x0e92a8 | Địa chỉ FDE: 0x1aa8f8 | Kích thước: 80 bytes
//   0x0e92a8: 6D408400  ldp      d0, d1, [x0, #8]
//   0x0e92ac: B9801808  ldrsw    x8, [x0, #0x18]
//   0x0e92b0: 1E612000  fcmp     d0, d1
//   0x0e92b4: D37DF108  lsl      x8, x8, #3
static inline uint64_t fde_func_1436_0x0e92a8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e92a8ULL ^ (static_cast<uint64_t>(0x6d408400ULL) << 13);
    acc = (acc + a1 + 0xb9801808ULL) ^ 0x1aa8f8ULL;
    acc ^= (acc >> 17) * 0x0050ULL;
    return acc;
}

// FDE #1437 | PC: 0x0e92f8 | FDE: 0x1aa928 | Size: 92 bytes
// Khung tháo gỡ #1437 | Địa chỉ PC: 0x0e92f8 | Địa chỉ FDE: 0x1aa928 | Kích thước: 92 bytes
//   0x0e92f8: B9800808  ldrsw    x8, [x0, #8]
//   0x0e92fc: FD400800  ldr      d0, [x0, #0x10]
//   0x0e9300: B9801809  ldrsw    x9, [x0, #0x18]
//   0x0e9304: FC687821  ldr      d1, [x1, x8, lsl #3]
static inline uint64_t fde_func_1437_0x0e92f8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e92f8ULL ^ (static_cast<uint64_t>(0xb9800808ULL) << 13);
    acc = (acc + a1 + 0xfd400800ULL) ^ 0x1aa928ULL;
    acc ^= (acc >> 17) * 0x005cULL;
    return acc;
}

// FDE #1438 | PC: 0x0e9354 | FDE: 0x1aa958 | Size: 80 bytes
// Khung tháo gỡ #1438 | Địa chỉ PC: 0x0e9354 | Địa chỉ FDE: 0x1aa958 | Kích thước: 80 bytes
//   0x0e9354: F9400408  ldr      x8, [x0, #8]
//   0x0e9358: D00006EB  adrp     x11, #0x1c7000
//   0x0e935c: 9136816B  add      x11, x11, #0xda0
//   0x0e9360: 79402509  ldrh     w9, [x8, #0x12]
static inline uint64_t fde_func_1438_0x0e9354(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e9354ULL ^ (static_cast<uint64_t>(0xf9400408ULL) << 13);
    acc = (acc + a1 + 0xd00006ebULL) ^ 0x1aa958ULL;
    acc ^= (acc >> 17) * 0x0050ULL;
    return acc;
}

// FDE #1439 | PC: 0x0e93a4 | FDE: 0x1aa988 | Size: 96 bytes
// Khung tháo gỡ #1439 | Địa chỉ PC: 0x0e93a4 | Địa chỉ FDE: 0x1aa988 | Kích thước: 96 bytes
//   0x0e93a4: B9801008  ldrsw    x8, [x0, #0x10]
//   0x0e93a8: B9400809  ldr      w9, [x0, #8]
//   0x0e93ac: B980180A  ldrsw    x10, [x0, #0x18]
//   0x0e93b0: D37DF108  lsl      x8, x8, #3
static inline uint64_t fde_func_1439_0x0e93a4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e93a4ULL ^ (static_cast<uint64_t>(0xb9801008ULL) << 13);
    acc = (acc + a1 + 0xb9400809ULL) ^ 0x1aa988ULL;
    acc ^= (acc >> 17) * 0x0060ULL;
    return acc;
}

// FDE #1440 | PC: 0x0e9404 | FDE: 0x1aa9b8 | Size: 92 bytes
// Khung tháo gỡ #1440 | Địa chỉ PC: 0x0e9404 | Địa chỉ FDE: 0x1aa9b8 | Kích thước: 92 bytes
//   0x0e9404: B9800808  ldrsw    x8, [x0, #8]
//   0x0e9408: B9801009  ldrsw    x9, [x0, #0x10]
//   0x0e940c: B980180A  ldrsw    x10, [x0, #0x18]
//   0x0e9410: D37DF108  lsl      x8, x8, #3
static inline uint64_t fde_func_1440_0x0e9404(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e9404ULL ^ (static_cast<uint64_t>(0xb9800808ULL) << 13);
    acc = (acc + a1 + 0xb9801009ULL) ^ 0x1aa9b8ULL;
    acc ^= (acc >> 17) * 0x005cULL;
    return acc;
}

// FDE #1441 | PC: 0x0e9460 | FDE: 0x1aa9e8 | Size: 88 bytes
// Khung tháo gỡ #1441 | Địa chỉ PC: 0x0e9460 | Địa chỉ FDE: 0x1aa9e8 | Kích thước: 88 bytes
//   0x0e9460: B9801008  ldrsw    x8, [x0, #0x10]
//   0x0e9464: F9400409  ldr      x9, [x0, #8]
//   0x0e9468: B980180A  ldrsw    x10, [x0, #0x18]
//   0x0e946c: F8687828  ldr      x8, [x1, x8, lsl #3]
static inline uint64_t fde_func_1441_0x0e9460(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e9460ULL ^ (static_cast<uint64_t>(0xb9801008ULL) << 13);
    acc = (acc + a1 + 0xf9400409ULL) ^ 0x1aa9e8ULL;
    acc ^= (acc >> 17) * 0x0058ULL;
    return acc;
}

// FDE #1442 | PC: 0x0e94b8 | FDE: 0x1aaa18 | Size: 88 bytes
// Khung tháo gỡ #1442 | Địa chỉ PC: 0x0e94b8 | Địa chỉ FDE: 0x1aaa18 | Kích thước: 88 bytes
//   0x0e94b8: B9800808  ldrsw    x8, [x0, #8]
//   0x0e94bc: B9801009  ldrsw    x9, [x0, #0x10]
//   0x0e94c0: B980180A  ldrsw    x10, [x0, #0x18]
//   0x0e94c4: F8687828  ldr      x8, [x1, x8, lsl #3]
static inline uint64_t fde_func_1442_0x0e94b8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e94b8ULL ^ (static_cast<uint64_t>(0xb9800808ULL) << 13);
    acc = (acc + a1 + 0xb9801009ULL) ^ 0x1aaa18ULL;
    acc ^= (acc >> 17) * 0x0058ULL;
    return acc;
}

// FDE #1443 | PC: 0x0e9510 | FDE: 0x1aaa48 | Size: 96 bytes
// Khung tháo gỡ #1443 | Địa chỉ PC: 0x0e9510 | Địa chỉ FDE: 0x1aaa48 | Kích thước: 96 bytes
//   0x0e9510: B9801008  ldrsw    x8, [x0, #0x10]
//   0x0e9514: BD400800  ldr      s0, [x0, #8]
//   0x0e9518: B9801809  ldrsw    x9, [x0, #0x18]
//   0x0e951c: D37DF108  lsl      x8, x8, #3
static inline uint64_t fde_func_1443_0x0e9510(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e9510ULL ^ (static_cast<uint64_t>(0xb9801008ULL) << 13);
    acc = (acc + a1 + 0xbd400800ULL) ^ 0x1aaa48ULL;
    acc ^= (acc >> 17) * 0x0060ULL;
    return acc;
}

// FDE #1444 | PC: 0x0e9570 | FDE: 0x1aaa78 | Size: 92 bytes
// Khung tháo gỡ #1444 | Địa chỉ PC: 0x0e9570 | Địa chỉ FDE: 0x1aaa78 | Kích thước: 92 bytes
//   0x0e9570: B9800808  ldrsw    x8, [x0, #8]
//   0x0e9574: B9801009  ldrsw    x9, [x0, #0x10]
//   0x0e9578: D37DF108  lsl      x8, x8, #3
//   0x0e957c: D37DF129  lsl      x9, x9, #3
static inline uint64_t fde_func_1444_0x0e9570(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e9570ULL ^ (static_cast<uint64_t>(0xb9800808ULL) << 13);
    acc = (acc + a1 + 0xb9801009ULL) ^ 0x1aaa78ULL;
    acc ^= (acc >> 17) * 0x005cULL;
    return acc;
}

// FDE #1445 | PC: 0x0e95cc | FDE: 0x1aaaa8 | Size: 88 bytes
// Khung tháo gỡ #1445 | Địa chỉ PC: 0x0e95cc | Địa chỉ FDE: 0x1aaaa8 | Kích thước: 88 bytes
//   0x0e95cc: B9801008  ldrsw    x8, [x0, #0x10]
//   0x0e95d0: FD400400  ldr      d0, [x0, #8]
//   0x0e95d4: B9801809  ldrsw    x9, [x0, #0x18]
//   0x0e95d8: FC687821  ldr      d1, [x1, x8, lsl #3]
static inline uint64_t fde_func_1445_0x0e95cc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e95ccULL ^ (static_cast<uint64_t>(0xb9801008ULL) << 13);
    acc = (acc + a1 + 0xfd400400ULL) ^ 0x1aaaa8ULL;
    acc ^= (acc >> 17) * 0x0058ULL;
    return acc;
}

// FDE #1446 | PC: 0x0e9624 | FDE: 0x1aaad8 | Size: 88 bytes
// Khung tháo gỡ #1446 | Địa chỉ PC: 0x0e9624 | Địa chỉ FDE: 0x1aaad8 | Kích thước: 88 bytes
//   0x0e9624: B9800808  ldrsw    x8, [x0, #8]
//   0x0e9628: B9801009  ldrsw    x9, [x0, #0x10]
//   0x0e962c: FC687820  ldr      d0, [x1, x8, lsl #3]
//   0x0e9630: FC697821  ldr      d1, [x1, x9, lsl #3]
static inline uint64_t fde_func_1446_0x0e9624(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e9624ULL ^ (static_cast<uint64_t>(0xb9800808ULL) << 13);
    acc = (acc + a1 + 0xb9801009ULL) ^ 0x1aaad8ULL;
    acc ^= (acc >> 17) * 0x0058ULL;
    return acc;
}

// FDE #1447 | PC: 0x0e967c | FDE: 0x1aab08 | Size: 88 bytes
// Khung tháo gỡ #1447 | Địa chỉ PC: 0x0e967c | Địa chỉ FDE: 0x1aab08 | Kích thước: 88 bytes
//   0x0e967c: B9400808  ldr      w8, [x0, #8]
//   0x0e9680: B9401009  ldr      w9, [x0, #0x10]
//   0x0e9684: B980180A  ldrsw    x10, [x0, #0x18]
//   0x0e9688: 6B09011F  cmp      w8, w9
static inline uint64_t fde_func_1447_0x0e967c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e967cULL ^ (static_cast<uint64_t>(0xb9400808ULL) << 13);
    acc = (acc + a1 + 0xb9401009ULL) ^ 0x1aab08ULL;
    acc ^= (acc >> 17) * 0x0058ULL;
    return acc;
}

// FDE #1448 | PC: 0x0e96d4 | FDE: 0x1aab38 | Size: 104 bytes
// Khung tháo gỡ #1448 | Địa chỉ PC: 0x0e96d4 | Địa chỉ FDE: 0x1aab38 | Kích thước: 104 bytes
//   0x0e96d4: B9800808  ldrsw    x8, [x0, #8]
//   0x0e96d8: B9401009  ldr      w9, [x0, #0x10]
//   0x0e96dc: B980180A  ldrsw    x10, [x0, #0x18]
//   0x0e96e0: D37DF108  lsl      x8, x8, #3
static inline uint64_t fde_func_1448_0x0e96d4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e96d4ULL ^ (static_cast<uint64_t>(0xb9800808ULL) << 13);
    acc = (acc + a1 + 0xb9401009ULL) ^ 0x1aab38ULL;
    acc ^= (acc >> 17) * 0x0068ULL;
    return acc;
}

// FDE #1449 | PC: 0x0e973c | FDE: 0x1aab68 | Size: 80 bytes
// Khung tháo gỡ #1449 | Địa chỉ PC: 0x0e973c | Địa chỉ FDE: 0x1aab68 | Kích thước: 80 bytes
//   0x0e973c: A940A408  ldp      x8, x9, [x0, #8]
//   0x0e9740: B980180A  ldrsw    x10, [x0, #0x18]
//   0x0e9744: EB09011F  cmp      x8, x9
//   0x0e9748: D37DF148  lsl      x8, x10, #3
static inline uint64_t fde_func_1449_0x0e973c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e973cULL ^ (static_cast<uint64_t>(0xa940a408ULL) << 13);
    acc = (acc + a1 + 0xb980180aULL) ^ 0x1aab68ULL;
    acc ^= (acc >> 17) * 0x0050ULL;
    return acc;
}

// FDE #1450 | PC: 0x0e978c | FDE: 0x1aab98 | Size: 92 bytes
// Khung tháo gỡ #1450 | Địa chỉ PC: 0x0e978c | Địa chỉ FDE: 0x1aab98 | Kích thước: 92 bytes
//   0x0e978c: B9800808  ldrsw    x8, [x0, #8]
//   0x0e9790: F9400809  ldr      x9, [x0, #0x10]
//   0x0e9794: B980180A  ldrsw    x10, [x0, #0x18]
//   0x0e9798: F8687828  ldr      x8, [x1, x8, lsl #3]
static inline uint64_t fde_func_1450_0x0e978c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e978cULL ^ (static_cast<uint64_t>(0xb9800808ULL) << 13);
    acc = (acc + a1 + 0xf9400809ULL) ^ 0x1aab98ULL;
    acc ^= (acc >> 17) * 0x005cULL;
    return acc;
}

// FDE #1451 | PC: 0x0e97e8 | FDE: 0x1aabc8 | Size: 80 bytes
// Khung tháo gỡ #1451 | Địa chỉ PC: 0x0e97e8 | Địa chỉ FDE: 0x1aabc8 | Kích thước: 80 bytes
//   0x0e97e8: F9400408  ldr      x8, [x0, #8]
//   0x0e97ec: D00006EB  adrp     x11, #0x1c7000
//   0x0e97f0: 913A816B  add      x11, x11, #0xea0
//   0x0e97f4: 79402509  ldrh     w9, [x8, #0x12]
static inline uint64_t fde_func_1451_0x0e97e8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e97e8ULL ^ (static_cast<uint64_t>(0xf9400408ULL) << 13);
    acc = (acc + a1 + 0xd00006ebULL) ^ 0x1aabc8ULL;
    acc ^= (acc >> 17) * 0x0050ULL;
    return acc;
}

// FDE #1452 | PC: 0x0e9838 | FDE: 0x1aabf8 | Size: 96 bytes
// Khung tháo gỡ #1452 | Địa chỉ PC: 0x0e9838 | Địa chỉ FDE: 0x1aabf8 | Kích thước: 96 bytes
//   0x0e9838: B9801008  ldrsw    x8, [x0, #0x10]
//   0x0e983c: B9400809  ldr      w9, [x0, #8]
//   0x0e9840: B980180A  ldrsw    x10, [x0, #0x18]
//   0x0e9844: D37DF108  lsl      x8, x8, #3
static inline uint64_t fde_func_1452_0x0e9838(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e9838ULL ^ (static_cast<uint64_t>(0xb9801008ULL) << 13);
    acc = (acc + a1 + 0xb9400809ULL) ^ 0x1aabf8ULL;
    acc ^= (acc >> 17) * 0x0060ULL;
    return acc;
}

// FDE #1453 | PC: 0x0e9898 | FDE: 0x1aac28 | Size: 92 bytes
// Khung tháo gỡ #1453 | Địa chỉ PC: 0x0e9898 | Địa chỉ FDE: 0x1aac28 | Kích thước: 92 bytes
//   0x0e9898: B9800808  ldrsw    x8, [x0, #8]
//   0x0e989c: B9801009  ldrsw    x9, [x0, #0x10]
//   0x0e98a0: B980180A  ldrsw    x10, [x0, #0x18]
//   0x0e98a4: D37DF108  lsl      x8, x8, #3
static inline uint64_t fde_func_1453_0x0e9898(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e9898ULL ^ (static_cast<uint64_t>(0xb9800808ULL) << 13);
    acc = (acc + a1 + 0xb9801009ULL) ^ 0x1aac28ULL;
    acc ^= (acc >> 17) * 0x005cULL;
    return acc;
}

// FDE #1454 | PC: 0x0e98f4 | FDE: 0x1aac58 | Size: 88 bytes
// Khung tháo gỡ #1454 | Địa chỉ PC: 0x0e98f4 | Địa chỉ FDE: 0x1aac58 | Kích thước: 88 bytes
//   0x0e98f4: B9801008  ldrsw    x8, [x0, #0x10]
//   0x0e98f8: F9400409  ldr      x9, [x0, #8]
//   0x0e98fc: B980180A  ldrsw    x10, [x0, #0x18]
//   0x0e9900: F8687828  ldr      x8, [x1, x8, lsl #3]
static inline uint64_t fde_func_1454_0x0e98f4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e98f4ULL ^ (static_cast<uint64_t>(0xb9801008ULL) << 13);
    acc = (acc + a1 + 0xf9400409ULL) ^ 0x1aac58ULL;
    acc ^= (acc >> 17) * 0x0058ULL;
    return acc;
}

// FDE #1455 | PC: 0x0e994c | FDE: 0x1aac88 | Size: 88 bytes
// Khung tháo gỡ #1455 | Địa chỉ PC: 0x0e994c | Địa chỉ FDE: 0x1aac88 | Kích thước: 88 bytes
//   0x0e994c: B9800808  ldrsw    x8, [x0, #8]
//   0x0e9950: B9801009  ldrsw    x9, [x0, #0x10]
//   0x0e9954: B980180A  ldrsw    x10, [x0, #0x18]
//   0x0e9958: F8687828  ldr      x8, [x1, x8, lsl #3]
static inline uint64_t fde_func_1455_0x0e994c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e994cULL ^ (static_cast<uint64_t>(0xb9800808ULL) << 13);
    acc = (acc + a1 + 0xb9801009ULL) ^ 0x1aac88ULL;
    acc ^= (acc >> 17) * 0x0058ULL;
    return acc;
}

// FDE #1456 | PC: 0x0e99a4 | FDE: 0x1aacb8 | Size: 88 bytes
// Khung tháo gỡ #1456 | Địa chỉ PC: 0x0e99a4 | Địa chỉ FDE: 0x1aacb8 | Kích thước: 88 bytes
//   0x0e99a4: B9400808  ldr      w8, [x0, #8]
//   0x0e99a8: B9401009  ldr      w9, [x0, #0x10]
//   0x0e99ac: B980180A  ldrsw    x10, [x0, #0x18]
//   0x0e99b0: 6B09011F  cmp      w8, w9
static inline uint64_t fde_func_1456_0x0e99a4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e99a4ULL ^ (static_cast<uint64_t>(0xb9400808ULL) << 13);
    acc = (acc + a1 + 0xb9401009ULL) ^ 0x1aacb8ULL;
    acc ^= (acc >> 17) * 0x0058ULL;
    return acc;
}

// FDE #1457 | PC: 0x0e99fc | FDE: 0x1aace8 | Size: 104 bytes
// Khung tháo gỡ #1457 | Địa chỉ PC: 0x0e99fc | Địa chỉ FDE: 0x1aace8 | Kích thước: 104 bytes
//   0x0e99fc: B9800808  ldrsw    x8, [x0, #8]
//   0x0e9a00: B9401009  ldr      w9, [x0, #0x10]
//   0x0e9a04: B980180A  ldrsw    x10, [x0, #0x18]
//   0x0e9a08: D37DF108  lsl      x8, x8, #3
static inline uint64_t fde_func_1457_0x0e99fc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e99fcULL ^ (static_cast<uint64_t>(0xb9800808ULL) << 13);
    acc = (acc + a1 + 0xb9401009ULL) ^ 0x1aace8ULL;
    acc ^= (acc >> 17) * 0x0068ULL;
    return acc;
}

// FDE #1458 | PC: 0x0e9a64 | FDE: 0x1aad18 | Size: 80 bytes
// Khung tháo gỡ #1458 | Địa chỉ PC: 0x0e9a64 | Địa chỉ FDE: 0x1aad18 | Kích thước: 80 bytes
//   0x0e9a64: A940A408  ldp      x8, x9, [x0, #8]
//   0x0e9a68: B980180A  ldrsw    x10, [x0, #0x18]
//   0x0e9a6c: EB09011F  cmp      x8, x9
//   0x0e9a70: D37DF148  lsl      x8, x10, #3
static inline uint64_t fde_func_1458_0x0e9a64(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e9a64ULL ^ (static_cast<uint64_t>(0xa940a408ULL) << 13);
    acc = (acc + a1 + 0xb980180aULL) ^ 0x1aad18ULL;
    acc ^= (acc >> 17) * 0x0050ULL;
    return acc;
}

// FDE #1459 | PC: 0x0e9ab4 | FDE: 0x1aad48 | Size: 92 bytes
// Khung tháo gỡ #1459 | Địa chỉ PC: 0x0e9ab4 | Địa chỉ FDE: 0x1aad48 | Kích thước: 92 bytes
//   0x0e9ab4: B9800808  ldrsw    x8, [x0, #8]
//   0x0e9ab8: F9400809  ldr      x9, [x0, #0x10]
//   0x0e9abc: B980180A  ldrsw    x10, [x0, #0x18]
//   0x0e9ac0: F8687828  ldr      x8, [x1, x8, lsl #3]
static inline uint64_t fde_func_1459_0x0e9ab4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e9ab4ULL ^ (static_cast<uint64_t>(0xb9800808ULL) << 13);
    acc = (acc + a1 + 0xf9400809ULL) ^ 0x1aad48ULL;
    acc ^= (acc >> 17) * 0x005cULL;
    return acc;
}

// FDE #1460 | PC: 0x0e9b10 | FDE: 0x1aad78 | Size: 80 bytes
// Khung tháo gỡ #1460 | Địa chỉ PC: 0x0e9b10 | Địa chỉ FDE: 0x1aad78 | Kích thước: 80 bytes
//   0x0e9b10: F9400408  ldr      x8, [x0, #8]
//   0x0e9b14: D00006EB  adrp     x11, #0x1c7000
//   0x0e9b18: 913E816B  add      x11, x11, #0xfa0
//   0x0e9b1c: 79402509  ldrh     w9, [x8, #0x12]
static inline uint64_t fde_func_1460_0x0e9b10(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e9b10ULL ^ (static_cast<uint64_t>(0xf9400408ULL) << 13);
    acc = (acc + a1 + 0xd00006ebULL) ^ 0x1aad78ULL;
    acc ^= (acc >> 17) * 0x0050ULL;
    return acc;
}

// FDE #1461 | PC: 0x0e9b60 | FDE: 0x1aada8 | Size: 96 bytes
// Khung tháo gỡ #1461 | Địa chỉ PC: 0x0e9b60 | Địa chỉ FDE: 0x1aada8 | Kích thước: 96 bytes
//   0x0e9b60: B9801008  ldrsw    x8, [x0, #0x10]
//   0x0e9b64: B9400809  ldr      w9, [x0, #8]
//   0x0e9b68: B980180A  ldrsw    x10, [x0, #0x18]
//   0x0e9b6c: D37DF108  lsl      x8, x8, #3
static inline uint64_t fde_func_1461_0x0e9b60(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e9b60ULL ^ (static_cast<uint64_t>(0xb9801008ULL) << 13);
    acc = (acc + a1 + 0xb9400809ULL) ^ 0x1aada8ULL;
    acc ^= (acc >> 17) * 0x0060ULL;
    return acc;
}

// FDE #1462 | PC: 0x0e9bc0 | FDE: 0x1aadd8 | Size: 92 bytes
// Khung tháo gỡ #1462 | Địa chỉ PC: 0x0e9bc0 | Địa chỉ FDE: 0x1aadd8 | Kích thước: 92 bytes
//   0x0e9bc0: B9800808  ldrsw    x8, [x0, #8]
//   0x0e9bc4: B9801009  ldrsw    x9, [x0, #0x10]
//   0x0e9bc8: B980180A  ldrsw    x10, [x0, #0x18]
//   0x0e9bcc: D37DF108  lsl      x8, x8, #3
static inline uint64_t fde_func_1462_0x0e9bc0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e9bc0ULL ^ (static_cast<uint64_t>(0xb9800808ULL) << 13);
    acc = (acc + a1 + 0xb9801009ULL) ^ 0x1aadd8ULL;
    acc ^= (acc >> 17) * 0x005cULL;
    return acc;
}

// FDE #1463 | PC: 0x0e9c1c | FDE: 0x1aae08 | Size: 88 bytes
// Khung tháo gỡ #1463 | Địa chỉ PC: 0x0e9c1c | Địa chỉ FDE: 0x1aae08 | Kích thước: 88 bytes
//   0x0e9c1c: B9801008  ldrsw    x8, [x0, #0x10]
//   0x0e9c20: F9400409  ldr      x9, [x0, #8]
//   0x0e9c24: B980180A  ldrsw    x10, [x0, #0x18]
//   0x0e9c28: F8687828  ldr      x8, [x1, x8, lsl #3]
static inline uint64_t fde_func_1463_0x0e9c1c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e9c1cULL ^ (static_cast<uint64_t>(0xb9801008ULL) << 13);
    acc = (acc + a1 + 0xf9400409ULL) ^ 0x1aae08ULL;
    acc ^= (acc >> 17) * 0x0058ULL;
    return acc;
}

// FDE #1464 | PC: 0x0e9c74 | FDE: 0x1aae38 | Size: 80 bytes
// Khung tháo gỡ #1464 | Địa chỉ PC: 0x0e9c74 | Địa chỉ FDE: 0x1aae38 | Kích thước: 80 bytes
//   0x0e9c74: B9800808  ldrsw    x8, [x0, #8]
//   0x0e9c78: B9801009  ldrsw    x9, [x0, #0x10]
//   0x0e9c7c: B980180A  ldrsw    x10, [x0, #0x18]
//   0x0e9c80: F8687828  ldr      x8, [x1, x8, lsl #3]
static inline uint64_t fde_func_1464_0x0e9c74(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e9c74ULL ^ (static_cast<uint64_t>(0xb9800808ULL) << 13);
    acc = (acc + a1 + 0xb9801009ULL) ^ 0x1aae38ULL;
    acc ^= (acc >> 17) * 0x0050ULL;
    return acc;
}

// FDE #1465 | PC: 0x0e9cc4 | FDE: 0x1aae68 | Size: 80 bytes
// Khung tháo gỡ #1465 | Địa chỉ PC: 0x0e9cc4 | Địa chỉ FDE: 0x1aae68 | Kích thước: 80 bytes
//   0x0e9cc4: A940A408  ldp      x8, x9, [x0, #8]
//   0x0e9cc8: 38E96908  ldrsb    w8, [x8, x9]
//   0x0e9ccc: B9801809  ldrsw    x9, [x0, #0x18]
//   0x0e9cd0: 32185D0A  orr      w10, w8, #0xffffff00
static inline uint64_t fde_func_1465_0x0e9cc4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e9cc4ULL ^ (static_cast<uint64_t>(0xa940a408ULL) << 13);
    acc = (acc + a1 + 0x38e96908ULL) ^ 0x1aae68ULL;
    acc ^= (acc >> 17) * 0x0050ULL;
    return acc;
}

// FDE #1466 | PC: 0x0e9d14 | FDE: 0x1aae98 | Size: 80 bytes
// Khung tháo gỡ #1466 | Địa chỉ PC: 0x0e9d14 | Địa chỉ FDE: 0x1aae98 | Kích thước: 80 bytes
//   0x0e9d14: A940A408  ldp      x8, x9, [x0, #8]
//   0x0e9d18: 38A96908  ldrsb    x8, [x8, x9]
//   0x0e9d1c: B9801809  ldrsw    x9, [x0, #0x18]
//   0x0e9d20: B278DD0A  orr      x10, x8, #0xffffffffffffff00
static inline uint64_t fde_func_1466_0x0e9d14(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e9d14ULL ^ (static_cast<uint64_t>(0xa940a408ULL) << 13);
    acc = (acc + a1 + 0x38a96908ULL) ^ 0x1aae98ULL;
    acc ^= (acc >> 17) * 0x0050ULL;
    return acc;
}

// FDE #1467 | PC: 0x0e9d64 | FDE: 0x1aaec8 | Size: 32 bytes
// Khung tháo gỡ #1467 | Địa chỉ PC: 0x0e9d64 | Địa chỉ FDE: 0x1aaec8 | Kích thước: 32 bytes
//   0x0e9d64: B9801808  ldrsw    x8, [x0, #0x18]
//   0x0e9d68: F828783F  str      xzr, [x1, x8, lsl #3]
//   0x0e9d6c: F8420C04  ldr      x4, [x0, #0x20]!
//   0x0e9d70: D61F0080  br       x4
static inline uint64_t fde_func_1467_0x0e9d64(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e9d64ULL ^ (static_cast<uint64_t>(0xb9801808ULL) << 13);
    acc = (acc + a1 + 0xf828783fULL) ^ 0x1aaec8ULL;
    acc ^= (acc >> 17) * 0x0020ULL;
    return acc;
}

// FDE #1468 | PC: 0x0e9d84 | FDE: 0x1aaef8 | Size: 32 bytes
// Khung tháo gỡ #1468 | Địa chỉ PC: 0x0e9d84 | Địa chỉ FDE: 0x1aaef8 | Kích thước: 32 bytes
//   0x0e9d84: B9801808  ldrsw    x8, [x0, #0x18]
//   0x0e9d88: F828783F  str      xzr, [x1, x8, lsl #3]
//   0x0e9d8c: F8420C04  ldr      x4, [x0, #0x20]!
//   0x0e9d90: D61F0080  br       x4
static inline uint64_t fde_func_1468_0x0e9d84(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e9d84ULL ^ (static_cast<uint64_t>(0xb9801808ULL) << 13);
    acc = (acc + a1 + 0xf828783fULL) ^ 0x1aaef8ULL;
    acc ^= (acc >> 17) * 0x0020ULL;
    return acc;
}

// FDE #1469 | PC: 0x0e9da4 | FDE: 0x1aaf28 | Size: 56 bytes
// Khung tháo gỡ #1469 | Địa chỉ PC: 0x0e9da4 | Địa chỉ FDE: 0x1aaf28 | Kích thước: 56 bytes
//   0x0e9da4: F9400408  ldr      x8, [x0, #8]
//   0x0e9da8: F00006EA  adrp     x10, #0x1c8000
//   0x0e9dac: 9101814A  add      x10, x10, #0x60
//   0x0e9db0: 79400509  ldrh     w9, [x8, #2]
static inline uint64_t fde_func_1469_0x0e9da4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e9da4ULL ^ (static_cast<uint64_t>(0xf9400408ULL) << 13);
    acc = (acc + a1 + 0xf00006eaULL) ^ 0x1aaf28ULL;
    acc ^= (acc >> 17) * 0x0038ULL;
    return acc;
}

// FDE #1470 | PC: 0x0e9ddc | FDE: 0x1aaf58 | Size: 56 bytes
// Khung tháo gỡ #1470 | Địa chỉ PC: 0x0e9ddc | Địa chỉ FDE: 0x1aaf58 | Kích thước: 56 bytes
//   0x0e9ddc: B9800808  ldrsw    x8, [x0, #8]
//   0x0e9de0: F9400809  ldr      x9, [x0, #0x10]
//   0x0e9de4: F8687828  ldr      x8, [x1, x8, lsl #3]
//   0x0e9de8: 38696908  ldrb     w8, [x8, x9]
static inline uint64_t fde_func_1470_0x0e9ddc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e9ddcULL ^ (static_cast<uint64_t>(0xb9800808ULL) << 13);
    acc = (acc + a1 + 0xf9400809ULL) ^ 0x1aaf58ULL;
    acc ^= (acc >> 17) * 0x0038ULL;
    return acc;
}

// FDE #1471 | PC: 0x0e9e14 | FDE: 0x1aaf88 | Size: 48 bytes
// Khung tháo gỡ #1471 | Địa chỉ PC: 0x0e9e14 | Địa chỉ FDE: 0x1aaf88 | Kích thước: 48 bytes
//   0x0e9e14: B9800808  ldrsw    x8, [x0, #8]
//   0x0e9e18: F9400809  ldr      x9, [x0, #0x10]
//   0x0e9e1c: F8687828  ldr      x8, [x1, x8, lsl #3]
//   0x0e9e20: 38696908  ldrb     w8, [x8, x9]
static inline uint64_t fde_func_1471_0x0e9e14(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e9e14ULL ^ (static_cast<uint64_t>(0xb9800808ULL) << 13);
    acc = (acc + a1 + 0xf9400809ULL) ^ 0x1aaf88ULL;
    acc ^= (acc >> 17) * 0x0030ULL;
    return acc;
}

// FDE #1472 | PC: 0x0e9e44 | FDE: 0x1aafb8 | Size: 32 bytes
// Khung tháo gỡ #1472 | Địa chỉ PC: 0x0e9e44 | Địa chỉ FDE: 0x1aafb8 | Kích thước: 32 bytes
//   0x0e9e44: B9801808  ldrsw    x8, [x0, #0x18]
//   0x0e9e48: F828783F  str      xzr, [x1, x8, lsl #3]
//   0x0e9e4c: F8420C04  ldr      x4, [x0, #0x20]!
//   0x0e9e50: D61F0080  br       x4
static inline uint64_t fde_func_1472_0x0e9e44(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e9e44ULL ^ (static_cast<uint64_t>(0xb9801808ULL) << 13);
    acc = (acc + a1 + 0xf828783fULL) ^ 0x1aafb8ULL;
    acc ^= (acc >> 17) * 0x0020ULL;
    return acc;
}

// FDE #1473 | PC: 0x0e9e64 | FDE: 0x1aafe8 | Size: 48 bytes
// Khung tháo gỡ #1473 | Địa chỉ PC: 0x0e9e64 | Địa chỉ FDE: 0x1aafe8 | Kích thước: 48 bytes
//   0x0e9e64: B9801808  ldrsw    x8, [x0, #0x18]
//   0x0e9e68: F828783F  str      xzr, [x1, x8, lsl #3]
//   0x0e9e6c: F8420C04  ldr      x4, [x0, #0x20]!
//   0x0e9e70: D61F0080  br       x4
static inline uint64_t fde_func_1473_0x0e9e64(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e9e64ULL ^ (static_cast<uint64_t>(0xb9801808ULL) << 13);
    acc = (acc + a1 + 0xf828783fULL) ^ 0x1aafe8ULL;
    acc ^= (acc >> 17) * 0x0030ULL;
    return acc;
}

// FDE #1474 | PC: 0x0e9e94 | FDE: 0x1ab018 | Size: 80 bytes
// Khung tháo gỡ #1474 | Địa chỉ PC: 0x0e9e94 | Địa chỉ FDE: 0x1ab018 | Kích thước: 80 bytes
//   0x0e9e94: A940A408  ldp      x8, x9, [x0, #8]
//   0x0e9e98: 78E96908  ldrsh    w8, [x8, x9]
//   0x0e9e9c: B9801809  ldrsw    x9, [x0, #0x18]
//   0x0e9ea0: 32103D0A  orr      w10, w8, #0xffff0000
static inline uint64_t fde_func_1474_0x0e9e94(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e9e94ULL ^ (static_cast<uint64_t>(0xa940a408ULL) << 13);
    acc = (acc + a1 + 0x78e96908ULL) ^ 0x1ab018ULL;
    acc ^= (acc >> 17) * 0x0050ULL;
    return acc;
}

// FDE #1475 | PC: 0x0e9ee4 | FDE: 0x1ab048 | Size: 80 bytes
// Khung tháo gỡ #1475 | Địa chỉ PC: 0x0e9ee4 | Địa chỉ FDE: 0x1ab048 | Kích thước: 80 bytes
//   0x0e9ee4: A940A408  ldp      x8, x9, [x0, #8]
//   0x0e9ee8: 78A96908  ldrsh    x8, [x8, x9]
//   0x0e9eec: B9801809  ldrsw    x9, [x0, #0x18]
//   0x0e9ef0: B270BD0A  orr      x10, x8, #0xffffffffffff0000
static inline uint64_t fde_func_1475_0x0e9ee4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e9ee4ULL ^ (static_cast<uint64_t>(0xa940a408ULL) << 13);
    acc = (acc + a1 + 0x78a96908ULL) ^ 0x1ab048ULL;
    acc ^= (acc >> 17) * 0x0050ULL;
    return acc;
}

// FDE #1476 | PC: 0x0e9f34 | FDE: 0x1ab078 | Size: 32 bytes
// Khung tháo gỡ #1476 | Địa chỉ PC: 0x0e9f34 | Địa chỉ FDE: 0x1ab078 | Kích thước: 32 bytes
//   0x0e9f34: B9801808  ldrsw    x8, [x0, #0x18]
//   0x0e9f38: F828783F  str      xzr, [x1, x8, lsl #3]
//   0x0e9f3c: F8420C04  ldr      x4, [x0, #0x20]!
//   0x0e9f40: D61F0080  br       x4
static inline uint64_t fde_func_1476_0x0e9f34(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e9f34ULL ^ (static_cast<uint64_t>(0xb9801808ULL) << 13);
    acc = (acc + a1 + 0xf828783fULL) ^ 0x1ab078ULL;
    acc ^= (acc >> 17) * 0x0020ULL;
    return acc;
}

// FDE #1477 | PC: 0x0e9f54 | FDE: 0x1ab0a8 | Size: 32 bytes
// Khung tháo gỡ #1477 | Địa chỉ PC: 0x0e9f54 | Địa chỉ FDE: 0x1ab0a8 | Kích thước: 32 bytes
//   0x0e9f54: B9801808  ldrsw    x8, [x0, #0x18]
//   0x0e9f58: F828783F  str      xzr, [x1, x8, lsl #3]
//   0x0e9f5c: F8420C04  ldr      x4, [x0, #0x20]!
//   0x0e9f60: D61F0080  br       x4
static inline uint64_t fde_func_1477_0x0e9f54(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e9f54ULL ^ (static_cast<uint64_t>(0xb9801808ULL) << 13);
    acc = (acc + a1 + 0xf828783fULL) ^ 0x1ab0a8ULL;
    acc ^= (acc >> 17) * 0x0020ULL;
    return acc;
}

// FDE #1478 | PC: 0x0e9f74 | FDE: 0x1ab0d8 | Size: 56 bytes
// Khung tháo gỡ #1478 | Địa chỉ PC: 0x0e9f74 | Địa chỉ FDE: 0x1ab0d8 | Kích thước: 56 bytes
//   0x0e9f74: F9400408  ldr      x8, [x0, #8]
//   0x0e9f78: F00006EA  adrp     x10, #0x1c8000
//   0x0e9f7c: 9103814A  add      x10, x10, #0xe0
//   0x0e9f80: 79400509  ldrh     w9, [x8, #2]
static inline uint64_t fde_func_1478_0x0e9f74(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e9f74ULL ^ (static_cast<uint64_t>(0xf9400408ULL) << 13);
    acc = (acc + a1 + 0xf00006eaULL) ^ 0x1ab0d8ULL;
    acc ^= (acc >> 17) * 0x0038ULL;
    return acc;
}

// FDE #1479 | PC: 0x0e9fac | FDE: 0x1ab108 | Size: 56 bytes
// Khung tháo gỡ #1479 | Địa chỉ PC: 0x0e9fac | Địa chỉ FDE: 0x1ab108 | Kích thước: 56 bytes
//   0x0e9fac: B9800808  ldrsw    x8, [x0, #8]
//   0x0e9fb0: F9400809  ldr      x9, [x0, #0x10]
//   0x0e9fb4: F8687828  ldr      x8, [x1, x8, lsl #3]
//   0x0e9fb8: 78696908  ldrh     w8, [x8, x9]
static inline uint64_t fde_func_1479_0x0e9fac(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e9facULL ^ (static_cast<uint64_t>(0xb9800808ULL) << 13);
    acc = (acc + a1 + 0xf9400809ULL) ^ 0x1ab108ULL;
    acc ^= (acc >> 17) * 0x0038ULL;
    return acc;
}

// FDE #1480 | PC: 0x0e9fe4 | FDE: 0x1ab138 | Size: 48 bytes
// Khung tháo gỡ #1480 | Địa chỉ PC: 0x0e9fe4 | Địa chỉ FDE: 0x1ab138 | Kích thước: 48 bytes
//   0x0e9fe4: B9800808  ldrsw    x8, [x0, #8]
//   0x0e9fe8: F9400809  ldr      x9, [x0, #0x10]
//   0x0e9fec: F8687828  ldr      x8, [x1, x8, lsl #3]
//   0x0e9ff0: 78696908  ldrh     w8, [x8, x9]
static inline uint64_t fde_func_1480_0x0e9fe4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0e9fe4ULL ^ (static_cast<uint64_t>(0xb9800808ULL) << 13);
    acc = (acc + a1 + 0xf9400809ULL) ^ 0x1ab138ULL;
    acc ^= (acc >> 17) * 0x0030ULL;
    return acc;
}

// FDE #1481 | PC: 0x0ea014 | FDE: 0x1ab168 | Size: 32 bytes
// Khung tháo gỡ #1481 | Địa chỉ PC: 0x0ea014 | Địa chỉ FDE: 0x1ab168 | Kích thước: 32 bytes
//   0x0ea014: B9801808  ldrsw    x8, [x0, #0x18]
//   0x0ea018: F828783F  str      xzr, [x1, x8, lsl #3]
//   0x0ea01c: F8420C04  ldr      x4, [x0, #0x20]!
//   0x0ea020: D61F0080  br       x4
static inline uint64_t fde_func_1481_0x0ea014(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ea014ULL ^ (static_cast<uint64_t>(0xb9801808ULL) << 13);
    acc = (acc + a1 + 0xf828783fULL) ^ 0x1ab168ULL;
    acc ^= (acc >> 17) * 0x0020ULL;
    return acc;
}

// FDE #1482 | PC: 0x0ea034 | FDE: 0x1ab198 | Size: 48 bytes
// Khung tháo gỡ #1482 | Địa chỉ PC: 0x0ea034 | Địa chỉ FDE: 0x1ab198 | Kích thước: 48 bytes
//   0x0ea034: B9801808  ldrsw    x8, [x0, #0x18]
//   0x0ea038: F828783F  str      xzr, [x1, x8, lsl #3]
//   0x0ea03c: F8420C04  ldr      x4, [x0, #0x20]!
//   0x0ea040: D61F0080  br       x4
static inline uint64_t fde_func_1482_0x0ea034(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ea034ULL ^ (static_cast<uint64_t>(0xb9801808ULL) << 13);
    acc = (acc + a1 + 0xf828783fULL) ^ 0x1ab198ULL;
    acc ^= (acc >> 17) * 0x0030ULL;
    return acc;
}

// FDE #1483 | PC: 0x0ea064 | FDE: 0x1ab1c8 | Size: 32 bytes
// Khung tháo gỡ #1483 | Địa chỉ PC: 0x0ea064 | Địa chỉ FDE: 0x1ab1c8 | Kích thước: 32 bytes
//   0x0ea064: B9801808  ldrsw    x8, [x0, #0x18]
//   0x0ea068: F828783F  str      xzr, [x1, x8, lsl #3]
//   0x0ea06c: F8420C04  ldr      x4, [x0, #0x20]!
//   0x0ea070: D61F0080  br       x4
static inline uint64_t fde_func_1483_0x0ea064(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ea064ULL ^ (static_cast<uint64_t>(0xb9801808ULL) << 13);
    acc = (acc + a1 + 0xf828783fULL) ^ 0x1ab1c8ULL;
    acc ^= (acc >> 17) * 0x0020ULL;
    return acc;
}

// FDE #1484 | PC: 0x0ea084 | FDE: 0x1ab1f8 | Size: 80 bytes
// Khung tháo gỡ #1484 | Địa chỉ PC: 0x0ea084 | Địa chỉ FDE: 0x1ab1f8 | Kích thước: 80 bytes
//   0x0ea084: A940A408  ldp      x8, x9, [x0, #8]
//   0x0ea088: B8A96908  ldrsw    x8, [x8, x9]
//   0x0ea08c: B9801809  ldrsw    x9, [x0, #0x18]
//   0x0ea090: B2607D0A  orr      x10, x8, #0xffffffff00000000
static inline uint64_t fde_func_1484_0x0ea084(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ea084ULL ^ (static_cast<uint64_t>(0xa940a408ULL) << 13);
    acc = (acc + a1 + 0xb8a96908ULL) ^ 0x1ab1f8ULL;
    acc ^= (acc >> 17) * 0x0050ULL;
    return acc;
}

// FDE #1485 | PC: 0x0ea0d4 | FDE: 0x1ab228 | Size: 32 bytes
// Khung tháo gỡ #1485 | Địa chỉ PC: 0x0ea0d4 | Địa chỉ FDE: 0x1ab228 | Kích thước: 32 bytes
//   0x0ea0d4: B9801808  ldrsw    x8, [x0, #0x18]
//   0x0ea0d8: F828783F  str      xzr, [x1, x8, lsl #3]
//   0x0ea0dc: F8420C04  ldr      x4, [x0, #0x20]!
//   0x0ea0e0: D61F0080  br       x4
static inline uint64_t fde_func_1485_0x0ea0d4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ea0d4ULL ^ (static_cast<uint64_t>(0xb9801808ULL) << 13);
    acc = (acc + a1 + 0xf828783fULL) ^ 0x1ab228ULL;
    acc ^= (acc >> 17) * 0x0020ULL;
    return acc;
}

// FDE #1486 | PC: 0x0ea0f4 | FDE: 0x1ab258 | Size: 32 bytes
// Khung tháo gỡ #1486 | Địa chỉ PC: 0x0ea0f4 | Địa chỉ FDE: 0x1ab258 | Kích thước: 32 bytes
//   0x0ea0f4: B9801808  ldrsw    x8, [x0, #0x18]
//   0x0ea0f8: F828783F  str      xzr, [x1, x8, lsl #3]
//   0x0ea0fc: F8420C04  ldr      x4, [x0, #0x20]!
//   0x0ea100: D61F0080  br       x4
static inline uint64_t fde_func_1486_0x0ea0f4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ea0f4ULL ^ (static_cast<uint64_t>(0xb9801808ULL) << 13);
    acc = (acc + a1 + 0xf828783fULL) ^ 0x1ab258ULL;
    acc ^= (acc >> 17) * 0x0020ULL;
    return acc;
}

// FDE #1487 | PC: 0x0ea114 | FDE: 0x1ab288 | Size: 56 bytes
// Khung tháo gỡ #1487 | Địa chỉ PC: 0x0ea114 | Địa chỉ FDE: 0x1ab288 | Kích thước: 56 bytes
//   0x0ea114: F9400408  ldr      x8, [x0, #8]
//   0x0ea118: D00006EA  adrp     x10, #0x1c8000
//   0x0ea11c: 9105814A  add      x10, x10, #0x160
//   0x0ea120: 79400509  ldrh     w9, [x8, #2]
static inline uint64_t fde_func_1487_0x0ea114(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ea114ULL ^ (static_cast<uint64_t>(0xf9400408ULL) << 13);
    acc = (acc + a1 + 0xd00006eaULL) ^ 0x1ab288ULL;
    acc ^= (acc >> 17) * 0x0038ULL;
    return acc;
}

// FDE #1488 | PC: 0x0ea14c | FDE: 0x1ab2b8 | Size: 56 bytes
// Khung tháo gỡ #1488 | Địa chỉ PC: 0x0ea14c | Địa chỉ FDE: 0x1ab2b8 | Kích thước: 56 bytes
//   0x0ea14c: B9800808  ldrsw    x8, [x0, #8]
//   0x0ea150: F9400809  ldr      x9, [x0, #0x10]
//   0x0ea154: F8687828  ldr      x8, [x1, x8, lsl #3]
//   0x0ea158: B8696908  ldr      w8, [x8, x9]
static inline uint64_t fde_func_1488_0x0ea14c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ea14cULL ^ (static_cast<uint64_t>(0xb9800808ULL) << 13);
    acc = (acc + a1 + 0xf9400809ULL) ^ 0x1ab2b8ULL;
    acc ^= (acc >> 17) * 0x0038ULL;
    return acc;
}

// FDE #1489 | PC: 0x0ea184 | FDE: 0x1ab2e8 | Size: 48 bytes
// Khung tháo gỡ #1489 | Địa chỉ PC: 0x0ea184 | Địa chỉ FDE: 0x1ab2e8 | Kích thước: 48 bytes
//   0x0ea184: B9800808  ldrsw    x8, [x0, #8]
//   0x0ea188: F9400809  ldr      x9, [x0, #0x10]
//   0x0ea18c: F8687828  ldr      x8, [x1, x8, lsl #3]
//   0x0ea190: B8696908  ldr      w8, [x8, x9]
static inline uint64_t fde_func_1489_0x0ea184(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ea184ULL ^ (static_cast<uint64_t>(0xb9800808ULL) << 13);
    acc = (acc + a1 + 0xf9400809ULL) ^ 0x1ab2e8ULL;
    acc ^= (acc >> 17) * 0x0030ULL;
    return acc;
}

// FDE #1490 | PC: 0x0ea1b4 | FDE: 0x1ab318 | Size: 32 bytes
// Khung tháo gỡ #1490 | Địa chỉ PC: 0x0ea1b4 | Địa chỉ FDE: 0x1ab318 | Kích thước: 32 bytes
//   0x0ea1b4: B9801808  ldrsw    x8, [x0, #0x18]
//   0x0ea1b8: F828783F  str      xzr, [x1, x8, lsl #3]
//   0x0ea1bc: F8420C04  ldr      x4, [x0, #0x20]!
//   0x0ea1c0: D61F0080  br       x4
static inline uint64_t fde_func_1490_0x0ea1b4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ea1b4ULL ^ (static_cast<uint64_t>(0xb9801808ULL) << 13);
    acc = (acc + a1 + 0xf828783fULL) ^ 0x1ab318ULL;
    acc ^= (acc >> 17) * 0x0020ULL;
    return acc;
}

// FDE #1491 | PC: 0x0ea1d4 | FDE: 0x1ab348 | Size: 48 bytes
// Khung tháo gỡ #1491 | Địa chỉ PC: 0x0ea1d4 | Địa chỉ FDE: 0x1ab348 | Kích thước: 48 bytes
//   0x0ea1d4: B9801808  ldrsw    x8, [x0, #0x18]
//   0x0ea1d8: F828783F  str      xzr, [x1, x8, lsl #3]
//   0x0ea1dc: F8420C04  ldr      x4, [x0, #0x20]!
//   0x0ea1e0: D61F0080  br       x4
static inline uint64_t fde_func_1491_0x0ea1d4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ea1d4ULL ^ (static_cast<uint64_t>(0xb9801808ULL) << 13);
    acc = (acc + a1 + 0xf828783fULL) ^ 0x1ab348ULL;
    acc ^= (acc >> 17) * 0x0030ULL;
    return acc;
}

// FDE #1492 | PC: 0x0ea204 | FDE: 0x1ab378 | Size: 32 bytes
// Khung tháo gỡ #1492 | Địa chỉ PC: 0x0ea204 | Địa chỉ FDE: 0x1ab378 | Kích thước: 32 bytes
//   0x0ea204: B9801808  ldrsw    x8, [x0, #0x18]
//   0x0ea208: F828783F  str      xzr, [x1, x8, lsl #3]
//   0x0ea20c: F8420C04  ldr      x4, [x0, #0x20]!
//   0x0ea210: D61F0080  br       x4
static inline uint64_t fde_func_1492_0x0ea204(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ea204ULL ^ (static_cast<uint64_t>(0xb9801808ULL) << 13);
    acc = (acc + a1 + 0xf828783fULL) ^ 0x1ab378ULL;
    acc ^= (acc >> 17) * 0x0020ULL;
    return acc;
}

// FDE #1493 | PC: 0x0ea224 | FDE: 0x1ab3a8 | Size: 32 bytes
// Khung tháo gỡ #1493 | Địa chỉ PC: 0x0ea224 | Địa chỉ FDE: 0x1ab3a8 | Kích thước: 32 bytes
//   0x0ea224: B9801808  ldrsw    x8, [x0, #0x18]
//   0x0ea228: F828783F  str      xzr, [x1, x8, lsl #3]
//   0x0ea22c: F8420C04  ldr      x4, [x0, #0x20]!
//   0x0ea230: D61F0080  br       x4
static inline uint64_t fde_func_1493_0x0ea224(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ea224ULL ^ (static_cast<uint64_t>(0xb9801808ULL) << 13);
    acc = (acc + a1 + 0xf828783fULL) ^ 0x1ab3a8ULL;
    acc ^= (acc >> 17) * 0x0020ULL;
    return acc;
}

// FDE #1494 | PC: 0x0ea244 | FDE: 0x1ab3d8 | Size: 32 bytes
// Khung tháo gỡ #1494 | Địa chỉ PC: 0x0ea244 | Địa chỉ FDE: 0x1ab3d8 | Kích thước: 32 bytes
//   0x0ea244: B9801808  ldrsw    x8, [x0, #0x18]
//   0x0ea248: F828783F  str      xzr, [x1, x8, lsl #3]
//   0x0ea24c: F8420C04  ldr      x4, [x0, #0x20]!
//   0x0ea250: D61F0080  br       x4
static inline uint64_t fde_func_1494_0x0ea244(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ea244ULL ^ (static_cast<uint64_t>(0xb9801808ULL) << 13);
    acc = (acc + a1 + 0xf828783fULL) ^ 0x1ab3d8ULL;
    acc ^= (acc >> 17) * 0x0020ULL;
    return acc;
}

// FDE #1495 | PC: 0x0ea264 | FDE: 0x1ab408 | Size: 32 bytes
// Khung tháo gỡ #1495 | Địa chỉ PC: 0x0ea264 | Địa chỉ FDE: 0x1ab408 | Kích thước: 32 bytes
//   0x0ea264: B9801808  ldrsw    x8, [x0, #0x18]
//   0x0ea268: F828783F  str      xzr, [x1, x8, lsl #3]
//   0x0ea26c: F8420C04  ldr      x4, [x0, #0x20]!
//   0x0ea270: D61F0080  br       x4
static inline uint64_t fde_func_1495_0x0ea264(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ea264ULL ^ (static_cast<uint64_t>(0xb9801808ULL) << 13);
    acc = (acc + a1 + 0xf828783fULL) ^ 0x1ab408ULL;
    acc ^= (acc >> 17) * 0x0020ULL;
    return acc;
}

// FDE #1496 | PC: 0x0ea284 | FDE: 0x1ab438 | Size: 48 bytes
// Khung tháo gỡ #1496 | Địa chỉ PC: 0x0ea284 | Địa chỉ FDE: 0x1ab438 | Kích thước: 48 bytes
//   0x0ea284: F9400408  ldr      x8, [x0, #8]
//   0x0ea288: D00006EA  adrp     x10, #0x1c8000
//   0x0ea28c: 9107814A  add      x10, x10, #0x1e0
//   0x0ea290: 79400509  ldrh     w9, [x8, #2]
static inline uint64_t fde_func_1496_0x0ea284(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ea284ULL ^ (static_cast<uint64_t>(0xf9400408ULL) << 13);
    acc = (acc + a1 + 0xd00006eaULL) ^ 0x1ab438ULL;
    acc ^= (acc >> 17) * 0x0030ULL;
    return acc;
}

// FDE #1497 | PC: 0x0ea2b4 | FDE: 0x1ab468 | Size: 40 bytes
// Khung tháo gỡ #1497 | Địa chỉ PC: 0x0ea2b4 | Địa chỉ FDE: 0x1ab468 | Kích thước: 40 bytes
//   0x0ea2b4: B9801808  ldrsw    x8, [x0, #0x18]
//   0x0ea2b8: F828783F  str      xzr, [x1, x8, lsl #3]
//   0x0ea2bc: F8420C04  ldr      x4, [x0, #0x20]!
//   0x0ea2c0: D61F0080  br       x4
static inline uint64_t fde_func_1497_0x0ea2b4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ea2b4ULL ^ (static_cast<uint64_t>(0xb9801808ULL) << 13);
    acc = (acc + a1 + 0xf828783fULL) ^ 0x1ab468ULL;
    acc ^= (acc >> 17) * 0x0028ULL;
    return acc;
}

// FDE #1498 | PC: 0x0ea2dc | FDE: 0x1ab498 | Size: 48 bytes
// Khung tháo gỡ #1498 | Địa chỉ PC: 0x0ea2dc | Địa chỉ FDE: 0x1ab498 | Kích thước: 48 bytes
//   0x0ea2dc: B9800808  ldrsw    x8, [x0, #8]
//   0x0ea2e0: F9400809  ldr      x9, [x0, #0x10]
//   0x0ea2e4: F8687828  ldr      x8, [x1, x8, lsl #3]
//   0x0ea2e8: F8696908  ldr      x8, [x8, x9]
static inline uint64_t fde_func_1498_0x0ea2dc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ea2dcULL ^ (static_cast<uint64_t>(0xb9800808ULL) << 13);
    acc = (acc + a1 + 0xf9400809ULL) ^ 0x1ab498ULL;
    acc ^= (acc >> 17) * 0x0030ULL;
    return acc;
}

// FDE #1499 | PC: 0x0ea30c | FDE: 0x1ab4c8 | Size: 32 bytes
// Khung tháo gỡ #1499 | Địa chỉ PC: 0x0ea30c | Địa chỉ FDE: 0x1ab4c8 | Kích thước: 32 bytes
//   0x0ea30c: B9801808  ldrsw    x8, [x0, #0x18]
//   0x0ea310: F828783F  str      xzr, [x1, x8, lsl #3]
//   0x0ea314: F8420C04  ldr      x4, [x0, #0x20]!
//   0x0ea318: D61F0080  br       x4
static inline uint64_t fde_func_1499_0x0ea30c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ea30cULL ^ (static_cast<uint64_t>(0xb9801808ULL) << 13);
    acc = (acc + a1 + 0xf828783fULL) ^ 0x1ab4c8ULL;
    acc ^= (acc >> 17) * 0x0020ULL;
    return acc;
}

// FDE #1500 | PC: 0x0ea32c | FDE: 0x1ab4f8 | Size: 48 bytes
// Khung tháo gỡ #1500 | Địa chỉ PC: 0x0ea32c | Địa chỉ FDE: 0x1ab4f8 | Kích thước: 48 bytes
//   0x0ea32c: B9801808  ldrsw    x8, [x0, #0x18]
//   0x0ea330: F828783F  str      xzr, [x1, x8, lsl #3]
//   0x0ea334: F8420C04  ldr      x4, [x0, #0x20]!
//   0x0ea338: D61F0080  br       x4
static inline uint64_t fde_func_1500_0x0ea32c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ea32cULL ^ (static_cast<uint64_t>(0xb9801808ULL) << 13);
    acc = (acc + a1 + 0xf828783fULL) ^ 0x1ab4f8ULL;
    acc ^= (acc >> 17) * 0x0030ULL;
    return acc;
}

// FDE #1501 | PC: 0x0ea35c | FDE: 0x1ab528 | Size: 32 bytes
// Khung tháo gỡ #1501 | Địa chỉ PC: 0x0ea35c | Địa chỉ FDE: 0x1ab528 | Kích thước: 32 bytes
//   0x0ea35c: B9801808  ldrsw    x8, [x0, #0x18]
//   0x0ea360: F828783F  str      xzr, [x1, x8, lsl #3]
//   0x0ea364: F8420C04  ldr      x4, [x0, #0x20]!
//   0x0ea368: D61F0080  br       x4
static inline uint64_t fde_func_1501_0x0ea35c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ea35cULL ^ (static_cast<uint64_t>(0xb9801808ULL) << 13);
    acc = (acc + a1 + 0xf828783fULL) ^ 0x1ab528ULL;
    acc ^= (acc >> 17) * 0x0020ULL;
    return acc;
}

// FDE #1502 | PC: 0x0ea37c | FDE: 0x1ab558 | Size: 32 bytes
// Khung tháo gỡ #1502 | Địa chỉ PC: 0x0ea37c | Địa chỉ FDE: 0x1ab558 | Kích thước: 32 bytes
//   0x0ea37c: B9801808  ldrsw    x8, [x0, #0x18]
//   0x0ea380: F828783F  str      xzr, [x1, x8, lsl #3]
//   0x0ea384: F8420C04  ldr      x4, [x0, #0x20]!
//   0x0ea388: D61F0080  br       x4
static inline uint64_t fde_func_1502_0x0ea37c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ea37cULL ^ (static_cast<uint64_t>(0xb9801808ULL) << 13);
    acc = (acc + a1 + 0xf828783fULL) ^ 0x1ab558ULL;
    acc ^= (acc >> 17) * 0x0020ULL;
    return acc;
}

// FDE #1503 | PC: 0x0ea39c | FDE: 0x1ab588 | Size: 56 bytes
// Khung tháo gỡ #1503 | Địa chỉ PC: 0x0ea39c | Địa chỉ FDE: 0x1ab588 | Kích thước: 56 bytes
//   0x0ea39c: A940A408  ldp      x8, x9, [x0, #8]
//   0x0ea3a0: B8696908  ldr      w8, [x8, x9]
//   0x0ea3a4: B9801809  ldrsw    x9, [x0, #0x18]
//   0x0ea3a8: F8297828  str      x8, [x1, x9, lsl #3]
static inline uint64_t fde_func_1503_0x0ea39c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ea39cULL ^ (static_cast<uint64_t>(0xa940a408ULL) << 13);
    acc = (acc + a1 + 0xb8696908ULL) ^ 0x1ab588ULL;
    acc ^= (acc >> 17) * 0x0038ULL;
    return acc;
}

// FDE #1504 | PC: 0x0ea3d4 | FDE: 0x1ab5b8 | Size: 32 bytes
// Khung tháo gỡ #1504 | Địa chỉ PC: 0x0ea3d4 | Địa chỉ FDE: 0x1ab5b8 | Kích thước: 32 bytes
//   0x0ea3d4: B9801808  ldrsw    x8, [x0, #0x18]
//   0x0ea3d8: F828783F  str      xzr, [x1, x8, lsl #3]
//   0x0ea3dc: F8420C04  ldr      x4, [x0, #0x20]!
//   0x0ea3e0: D61F0080  br       x4
static inline uint64_t fde_func_1504_0x0ea3d4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ea3d4ULL ^ (static_cast<uint64_t>(0xb9801808ULL) << 13);
    acc = (acc + a1 + 0xf828783fULL) ^ 0x1ab5b8ULL;
    acc ^= (acc >> 17) * 0x0020ULL;
    return acc;
}

// FDE #1505 | PC: 0x0ea3f4 | FDE: 0x1ab5e8 | Size: 48 bytes
// Khung tháo gỡ #1505 | Địa chỉ PC: 0x0ea3f4 | Địa chỉ FDE: 0x1ab5e8 | Kích thước: 48 bytes
//   0x0ea3f4: F9400408  ldr      x8, [x0, #8]
//   0x0ea3f8: D00006EA  adrp     x10, #0x1c8000
//   0x0ea3fc: 9109814A  add      x10, x10, #0x260
//   0x0ea400: 79400509  ldrh     w9, [x8, #2]
static inline uint64_t fde_func_1505_0x0ea3f4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ea3f4ULL ^ (static_cast<uint64_t>(0xf9400408ULL) << 13);
    acc = (acc + a1 + 0xd00006eaULL) ^ 0x1ab5e8ULL;
    acc ^= (acc >> 17) * 0x0030ULL;
    return acc;
}

// FDE #1506 | PC: 0x0ea424 | FDE: 0x1ab618 | Size: 32 bytes
// Khung tháo gỡ #1506 | Địa chỉ PC: 0x0ea424 | Địa chỉ FDE: 0x1ab618 | Kích thước: 32 bytes
//   0x0ea424: B9801808  ldrsw    x8, [x0, #0x18]
//   0x0ea428: F828783F  str      xzr, [x1, x8, lsl #3]
//   0x0ea42c: F8420C04  ldr      x4, [x0, #0x20]!
//   0x0ea430: D61F0080  br       x4
static inline uint64_t fde_func_1506_0x0ea424(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ea424ULL ^ (static_cast<uint64_t>(0xb9801808ULL) << 13);
    acc = (acc + a1 + 0xf828783fULL) ^ 0x1ab618ULL;
    acc ^= (acc >> 17) * 0x0020ULL;
    return acc;
}

// FDE #1507 | PC: 0x0ea444 | FDE: 0x1ab648 | Size: 32 bytes
// Khung tháo gỡ #1507 | Địa chỉ PC: 0x0ea444 | Địa chỉ FDE: 0x1ab648 | Kích thước: 32 bytes
//   0x0ea444: B9801808  ldrsw    x8, [x0, #0x18]
//   0x0ea448: F828783F  str      xzr, [x1, x8, lsl #3]
//   0x0ea44c: F8420C04  ldr      x4, [x0, #0x20]!
//   0x0ea450: D61F0080  br       x4
static inline uint64_t fde_func_1507_0x0ea444(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ea444ULL ^ (static_cast<uint64_t>(0xb9801808ULL) << 13);
    acc = (acc + a1 + 0xf828783fULL) ^ 0x1ab648ULL;
    acc ^= (acc >> 17) * 0x0020ULL;
    return acc;
}

// FDE #1508 | PC: 0x0ea464 | FDE: 0x1ab678 | Size: 40 bytes
// Khung tháo gỡ #1508 | Địa chỉ PC: 0x0ea464 | Địa chỉ FDE: 0x1ab678 | Kích thước: 40 bytes
//   0x0ea464: B9801808  ldrsw    x8, [x0, #0x18]
//   0x0ea468: F828783F  str      xzr, [x1, x8, lsl #3]
//   0x0ea46c: F8420C04  ldr      x4, [x0, #0x20]!
//   0x0ea470: D61F0080  br       x4
static inline uint64_t fde_func_1508_0x0ea464(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ea464ULL ^ (static_cast<uint64_t>(0xb9801808ULL) << 13);
    acc = (acc + a1 + 0xf828783fULL) ^ 0x1ab678ULL;
    acc ^= (acc >> 17) * 0x0028ULL;
    return acc;
}

// FDE #1509 | PC: 0x0ea48c | FDE: 0x1ab6a8 | Size: 72 bytes
// Khung tháo gỡ #1509 | Địa chỉ PC: 0x0ea48c | Địa chỉ FDE: 0x1ab6a8 | Kích thước: 72 bytes
//   0x0ea48c: B9800808  ldrsw    x8, [x0, #8]
//   0x0ea490: F9400809  ldr      x9, [x0, #0x10]
//   0x0ea494: F8687828  ldr      x8, [x1, x8, lsl #3]
//   0x0ea498: F8696908  ldr      x8, [x8, x9]
static inline uint64_t fde_func_1509_0x0ea48c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ea48cULL ^ (static_cast<uint64_t>(0xb9800808ULL) << 13);
    acc = (acc + a1 + 0xf9400809ULL) ^ 0x1ab6a8ULL;
    acc ^= (acc >> 17) * 0x0048ULL;
    return acc;
}

// FDE #1510 | PC: 0x0ea4d4 | FDE: 0x1ab6d8 | Size: 48 bytes
// Khung tháo gỡ #1510 | Địa chỉ PC: 0x0ea4d4 | Địa chỉ FDE: 0x1ab6d8 | Kích thước: 48 bytes
//   0x0ea4d4: A940A408  ldp      x8, x9, [x0, #8]
//   0x0ea4d8: B940180A  ldr      w10, [x0, #0x18]
//   0x0ea4dc: 3829690A  strb     w10, [x8, x9]
//   0x0ea4e0: F8420C04  ldr      x4, [x0, #0x20]!
static inline uint64_t fde_func_1510_0x0ea4d4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ea4d4ULL ^ (static_cast<uint64_t>(0xa940a408ULL) << 13);
    acc = (acc + a1 + 0xb940180aULL) ^ 0x1ab6d8ULL;
    acc ^= (acc >> 17) * 0x0030ULL;
    return acc;
}

// FDE #1511 | PC: 0x0ea504 | FDE: 0x1ab708 | Size: 64 bytes
// Khung tháo gỡ #1511 | Địa chỉ PC: 0x0ea504 | Địa chỉ FDE: 0x1ab708 | Kích thước: 64 bytes
//   0x0ea504: B9800808  ldrsw    x8, [x0, #8]
//   0x0ea508: F9400809  ldr      x9, [x0, #0x10]
//   0x0ea50c: B940180A  ldr      w10, [x0, #0x18]
//   0x0ea510: F8687828  ldr      x8, [x1, x8, lsl #3]
static inline uint64_t fde_func_1511_0x0ea504(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ea504ULL ^ (static_cast<uint64_t>(0xb9800808ULL) << 13);
    acc = (acc + a1 + 0xf9400809ULL) ^ 0x1ab708ULL;
    acc ^= (acc >> 17) * 0x0040ULL;
    return acc;
}

// FDE #1512 | PC: 0x0ea544 | FDE: 0x1ab738 | Size: 44 bytes
// Khung tháo gỡ #1512 | Địa chỉ PC: 0x0ea544 | Địa chỉ FDE: 0x1ab738 | Kích thước: 44 bytes
//   0x0ea544: A940A408  ldp      x8, x9, [x0, #8]
//   0x0ea548: F9400C0A  ldr      x10, [x0, #0x18]
//   0x0ea54c: 3829690A  strb     w10, [x8, x9]
//   0x0ea550: F8420C04  ldr      x4, [x0, #0x20]!
static inline uint64_t fde_func_1512_0x0ea544(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ea544ULL ^ (static_cast<uint64_t>(0xa940a408ULL) << 13);
    acc = (acc + a1 + 0xf9400c0aULL) ^ 0x1ab738ULL;
    acc ^= (acc >> 17) * 0x002cULL;
    return acc;
}

// FDE #1513 | PC: 0x0ea570 | FDE: 0x1ab768 | Size: 56 bytes
// Khung tháo gỡ #1513 | Địa chỉ PC: 0x0ea570 | Địa chỉ FDE: 0x1ab768 | Kích thước: 56 bytes
//   0x0ea570: B9800808  ldrsw    x8, [x0, #8]
//   0x0ea574: A9412809  ldp      x9, x10, [x0, #0x10]
//   0x0ea578: F8687828  ldr      x8, [x1, x8, lsl #3]
//   0x0ea57c: 3829690A  strb     w10, [x8, x9]
static inline uint64_t fde_func_1513_0x0ea570(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ea570ULL ^ (static_cast<uint64_t>(0xb9800808ULL) << 13);
    acc = (acc + a1 + 0xa9412809ULL) ^ 0x1ab768ULL;
    acc ^= (acc >> 17) * 0x0038ULL;
    return acc;
}

// FDE #1514 | PC: 0x0ea5a8 | FDE: 0x1ab798 | Size: 56 bytes
// Khung tháo gỡ #1514 | Địa chỉ PC: 0x0ea5a8 | Địa chỉ FDE: 0x1ab798 | Kích thước: 56 bytes
//   0x0ea5a8: BD401800  ldr      s0, [x0, #0x18]
//   0x0ea5ac: A940A408  ldp      x8, x9, [x0, #8]
//   0x0ea5b0: 1E38000A  fcvtzs   w10, s0
//   0x0ea5b4: 3829690A  strb     w10, [x8, x9]
static inline uint64_t fde_func_1514_0x0ea5a8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ea5a8ULL ^ (static_cast<uint64_t>(0xbd401800ULL) << 13);
    acc = (acc + a1 + 0xa940a408ULL) ^ 0x1ab798ULL;
    acc ^= (acc >> 17) * 0x0038ULL;
    return acc;
}

// FDE #1515 | PC: 0x0ea5e0 | FDE: 0x1ab7c8 | Size: 72 bytes
// Khung tháo gỡ #1515 | Địa chỉ PC: 0x0ea5e0 | Địa chỉ FDE: 0x1ab7c8 | Kích thước: 72 bytes
//   0x0ea5e0: B9800808  ldrsw    x8, [x0, #8]
//   0x0ea5e4: BD401800  ldr      s0, [x0, #0x18]
//   0x0ea5e8: F9400809  ldr      x9, [x0, #0x10]
//   0x0ea5ec: F8687828  ldr      x8, [x1, x8, lsl #3]
static inline uint64_t fde_func_1515_0x0ea5e0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ea5e0ULL ^ (static_cast<uint64_t>(0xb9800808ULL) << 13);
    acc = (acc + a1 + 0xbd401800ULL) ^ 0x1ab7c8ULL;
    acc ^= (acc >> 17) * 0x0048ULL;
    return acc;
}

// FDE #1516 | PC: 0x0ea628 | FDE: 0x1ab7f8 | Size: 52 bytes
// Khung tháo gỡ #1516 | Địa chỉ PC: 0x0ea628 | Địa chỉ FDE: 0x1ab7f8 | Kích thước: 52 bytes
//   0x0ea628: FD400C00  ldr      d0, [x0, #0x18]
//   0x0ea62c: A940A408  ldp      x8, x9, [x0, #8]
//   0x0ea630: 1E78000A  fcvtzs   w10, d0
//   0x0ea634: 3829690A  strb     w10, [x8, x9]
static inline uint64_t fde_func_1516_0x0ea628(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ea628ULL ^ (static_cast<uint64_t>(0xfd400c00ULL) << 13);
    acc = (acc + a1 + 0xa940a408ULL) ^ 0x1ab7f8ULL;
    acc ^= (acc >> 17) * 0x0034ULL;
    return acc;
}

// FDE #1517 | PC: 0x0ea65c | FDE: 0x1ab828 | Size: 68 bytes
// Khung tháo gỡ #1517 | Địa chỉ PC: 0x0ea65c | Địa chỉ FDE: 0x1ab828 | Kích thước: 68 bytes
//   0x0ea65c: B9800808  ldrsw    x8, [x0, #8]
//   0x0ea660: FD400C00  ldr      d0, [x0, #0x18]
//   0x0ea664: F9400809  ldr      x9, [x0, #0x10]
//   0x0ea668: F8687828  ldr      x8, [x1, x8, lsl #3]
static inline uint64_t fde_func_1517_0x0ea65c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ea65cULL ^ (static_cast<uint64_t>(0xb9800808ULL) << 13);
    acc = (acc + a1 + 0xfd400c00ULL) ^ 0x1ab828ULL;
    acc ^= (acc >> 17) * 0x0044ULL;
    return acc;
}

// FDE #1518 | PC: 0x0ea6a0 | FDE: 0x1ab858 | Size: 60 bytes
// Khung tháo gỡ #1518 | Địa chỉ PC: 0x0ea6a0 | Địa chỉ FDE: 0x1ab858 | Kích thước: 60 bytes
//   0x0ea6a0: F9400408  ldr      x8, [x0, #8]
//   0x0ea6a4: D00006EB  adrp     x11, #0x1c8000
//   0x0ea6a8: 910C816B  add      x11, x11, #0x320
//   0x0ea6ac: 79400509  ldrh     w9, [x8, #2]
static inline uint64_t fde_func_1518_0x0ea6a0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ea6a0ULL ^ (static_cast<uint64_t>(0xf9400408ULL) << 13);
    acc = (acc + a1 + 0xd00006ebULL) ^ 0x1ab858ULL;
    acc ^= (acc >> 17) * 0x003cULL;
    return acc;
}

// FDE #1519 | PC: 0x0ea6dc | FDE: 0x1ab888 | Size: 56 bytes
// Khung tháo gỡ #1519 | Địa chỉ PC: 0x0ea6dc | Địa chỉ FDE: 0x1ab888 | Kích thước: 56 bytes
//   0x0ea6dc: B9801808  ldrsw    x8, [x0, #0x18]
//   0x0ea6e0: A940A809  ldp      x9, x10, [x0, #8]
//   0x0ea6e4: D37DF108  lsl      x8, x8, #3
//   0x0ea6e8: B8686828  ldr      w8, [x1, x8]
static inline uint64_t fde_func_1519_0x0ea6dc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ea6dcULL ^ (static_cast<uint64_t>(0xb9801808ULL) << 13);
    acc = (acc + a1 + 0xa940a809ULL) ^ 0x1ab888ULL;
    acc ^= (acc >> 17) * 0x0038ULL;
    return acc;
}

// FDE #1520 | PC: 0x0ea714 | FDE: 0x1ab8b8 | Size: 56 bytes
// Khung tháo gỡ #1520 | Địa chỉ PC: 0x0ea714 | Địa chỉ FDE: 0x1ab8b8 | Kích thước: 56 bytes
//   0x0ea714: B9801809  ldrsw    x9, [x0, #0x18]
//   0x0ea718: B9800808  ldrsw    x8, [x0, #8]
//   0x0ea71c: F940080A  ldr      x10, [x0, #0x10]
//   0x0ea720: D37DF129  lsl      x9, x9, #3
static inline uint64_t fde_func_1520_0x0ea714(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ea714ULL ^ (static_cast<uint64_t>(0xb9801809ULL) << 13);
    acc = (acc + a1 + 0xb9800808ULL) ^ 0x1ab8b8ULL;
    acc ^= (acc >> 17) * 0x0038ULL;
    return acc;
}

// FDE #1521 | PC: 0x0ea74c | FDE: 0x1ab8e8 | Size: 48 bytes
// Khung tháo gỡ #1521 | Địa chỉ PC: 0x0ea74c | Địa chỉ FDE: 0x1ab8e8 | Kích thước: 48 bytes
//   0x0ea74c: B9801808  ldrsw    x8, [x0, #0x18]
//   0x0ea750: A940A809  ldp      x9, x10, [x0, #8]
//   0x0ea754: F8687828  ldr      x8, [x1, x8, lsl #3]
//   0x0ea758: 782A6928  strh     w8, [x9, x10]
static inline uint64_t fde_func_1521_0x0ea74c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ea74cULL ^ (static_cast<uint64_t>(0xb9801808ULL) << 13);
    acc = (acc + a1 + 0xa940a809ULL) ^ 0x1ab8e8ULL;
    acc ^= (acc >> 17) * 0x0030ULL;
    return acc;
}

// FDE #1522 | PC: 0x0ea77c | FDE: 0x1ab918 | Size: 56 bytes
// Khung tháo gỡ #1522 | Địa chỉ PC: 0x0ea77c | Địa chỉ FDE: 0x1ab918 | Kích thước: 56 bytes
//   0x0ea77c: B9800808  ldrsw    x8, [x0, #8]
//   0x0ea780: B9801809  ldrsw    x9, [x0, #0x18]
//   0x0ea784: F940080A  ldr      x10, [x0, #0x10]
//   0x0ea788: F8687828  ldr      x8, [x1, x8, lsl #3]
static inline uint64_t fde_func_1522_0x0ea77c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ea77cULL ^ (static_cast<uint64_t>(0xb9800808ULL) << 13);
    acc = (acc + a1 + 0xb9801809ULL) ^ 0x1ab918ULL;
    acc ^= (acc >> 17) * 0x0038ULL;
    return acc;
}

// FDE #1523 | PC: 0x0ea7b4 | FDE: 0x1ab948 | Size: 64 bytes
// Khung tháo gỡ #1523 | Địa chỉ PC: 0x0ea7b4 | Địa chỉ FDE: 0x1ab948 | Kích thước: 64 bytes
//   0x0ea7b4: B9801808  ldrsw    x8, [x0, #0x18]
//   0x0ea7b8: D37DF108  lsl      x8, x8, #3
//   0x0ea7bc: BC686820  ldr      s0, [x1, x8]
//   0x0ea7c0: A940A408  ldp      x8, x9, [x0, #8]
static inline uint64_t fde_func_1523_0x0ea7b4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ea7b4ULL ^ (static_cast<uint64_t>(0xb9801808ULL) << 13);
    acc = (acc + a1 + 0xd37df108ULL) ^ 0x1ab948ULL;
    acc ^= (acc >> 17) * 0x0040ULL;
    return acc;
}

// FDE #1524 | PC: 0x0ea7f4 | FDE: 0x1ab978 | Size: 64 bytes
// Khung tháo gỡ #1524 | Địa chỉ PC: 0x0ea7f4 | Địa chỉ FDE: 0x1ab978 | Kích thước: 64 bytes
//   0x0ea7f4: B9801808  ldrsw    x8, [x0, #0x18]
//   0x0ea7f8: B9800809  ldrsw    x9, [x0, #8]
//   0x0ea7fc: F940080A  ldr      x10, [x0, #0x10]
//   0x0ea800: D37DF108  lsl      x8, x8, #3
static inline uint64_t fde_func_1524_0x0ea7f4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ea7f4ULL ^ (static_cast<uint64_t>(0xb9801808ULL) << 13);
    acc = (acc + a1 + 0xb9800809ULL) ^ 0x1ab978ULL;
    acc ^= (acc >> 17) * 0x0040ULL;
    return acc;
}

// FDE #1525 | PC: 0x0ea834 | FDE: 0x1ab9a8 | Size: 60 bytes
// Khung tháo gỡ #1525 | Địa chỉ PC: 0x0ea834 | Địa chỉ FDE: 0x1ab9a8 | Kích thước: 60 bytes
//   0x0ea834: B9801808  ldrsw    x8, [x0, #0x18]
//   0x0ea838: FC687820  ldr      d0, [x1, x8, lsl #3]
//   0x0ea83c: A940A408  ldp      x8, x9, [x0, #8]
//   0x0ea840: 1E78000A  fcvtzs   w10, d0
static inline uint64_t fde_func_1525_0x0ea834(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ea834ULL ^ (static_cast<uint64_t>(0xb9801808ULL) << 13);
    acc = (acc + a1 + 0xfc687820ULL) ^ 0x1ab9a8ULL;
    acc ^= (acc >> 17) * 0x003cULL;
    return acc;
}

// FDE #1526 | PC: 0x0ea870 | FDE: 0x1ab9d8 | Size: 76 bytes
// Khung tháo gỡ #1526 | Địa chỉ PC: 0x0ea870 | Địa chỉ FDE: 0x1ab9d8 | Kích thước: 76 bytes
//   0x0ea870: B9801808  ldrsw    x8, [x0, #0x18]
//   0x0ea874: B9800809  ldrsw    x9, [x0, #8]
//   0x0ea878: F940080A  ldr      x10, [x0, #0x10]
//   0x0ea87c: FC687820  ldr      d0, [x1, x8, lsl #3]
static inline uint64_t fde_func_1526_0x0ea870(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ea870ULL ^ (static_cast<uint64_t>(0xb9801808ULL) << 13);
    acc = (acc + a1 + 0xb9800809ULL) ^ 0x1ab9d8ULL;
    acc ^= (acc >> 17) * 0x004cULL;
    return acc;
}

// FDE #1527 | PC: 0x0ea8bc | FDE: 0x1aba08 | Size: 48 bytes
// Khung tháo gỡ #1527 | Địa chỉ PC: 0x0ea8bc | Địa chỉ FDE: 0x1aba08 | Kích thước: 48 bytes
//   0x0ea8bc: A940A408  ldp      x8, x9, [x0, #8]
//   0x0ea8c0: B940180A  ldr      w10, [x0, #0x18]
//   0x0ea8c4: B829690A  str      w10, [x8, x9]
//   0x0ea8c8: F8420C04  ldr      x4, [x0, #0x20]!
static inline uint64_t fde_func_1527_0x0ea8bc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ea8bcULL ^ (static_cast<uint64_t>(0xa940a408ULL) << 13);
    acc = (acc + a1 + 0xb940180aULL) ^ 0x1aba08ULL;
    acc ^= (acc >> 17) * 0x0030ULL;
    return acc;
}

// FDE #1528 | PC: 0x0ea8ec | FDE: 0x1aba38 | Size: 64 bytes
// Khung tháo gỡ #1528 | Địa chỉ PC: 0x0ea8ec | Địa chỉ FDE: 0x1aba38 | Kích thước: 64 bytes
//   0x0ea8ec: B9800808  ldrsw    x8, [x0, #8]
//   0x0ea8f0: F9400809  ldr      x9, [x0, #0x10]
//   0x0ea8f4: B940180A  ldr      w10, [x0, #0x18]
//   0x0ea8f8: F8687828  ldr      x8, [x1, x8, lsl #3]
static inline uint64_t fde_func_1528_0x0ea8ec(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ea8ecULL ^ (static_cast<uint64_t>(0xb9800808ULL) << 13);
    acc = (acc + a1 + 0xf9400809ULL) ^ 0x1aba38ULL;
    acc ^= (acc >> 17) * 0x0040ULL;
    return acc;
}

// FDE #1529 | PC: 0x0ea92c | FDE: 0x1aba68 | Size: 44 bytes
// Khung tháo gỡ #1529 | Địa chỉ PC: 0x0ea92c | Địa chỉ FDE: 0x1aba68 | Kích thước: 44 bytes
//   0x0ea92c: A940A408  ldp      x8, x9, [x0, #8]
//   0x0ea930: F9400C0A  ldr      x10, [x0, #0x18]
//   0x0ea934: B829690A  str      w10, [x8, x9]
//   0x0ea938: F8420C04  ldr      x4, [x0, #0x20]!
static inline uint64_t fde_func_1529_0x0ea92c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ea92cULL ^ (static_cast<uint64_t>(0xa940a408ULL) << 13);
    acc = (acc + a1 + 0xf9400c0aULL) ^ 0x1aba68ULL;
    acc ^= (acc >> 17) * 0x002cULL;
    return acc;
}

// FDE #1530 | PC: 0x0ea958 | FDE: 0x1aba98 | Size: 56 bytes
// Khung tháo gỡ #1530 | Địa chỉ PC: 0x0ea958 | Địa chỉ FDE: 0x1aba98 | Kích thước: 56 bytes
//   0x0ea958: B9800808  ldrsw    x8, [x0, #8]
//   0x0ea95c: A9412809  ldp      x9, x10, [x0, #0x10]
//   0x0ea960: F8687828  ldr      x8, [x1, x8, lsl #3]
//   0x0ea964: B829690A  str      w10, [x8, x9]
static inline uint64_t fde_func_1530_0x0ea958(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ea958ULL ^ (static_cast<uint64_t>(0xb9800808ULL) << 13);
    acc = (acc + a1 + 0xa9412809ULL) ^ 0x1aba98ULL;
    acc ^= (acc >> 17) * 0x0038ULL;
    return acc;
}

// FDE #1531 | PC: 0x0ea990 | FDE: 0x1abac8 | Size: 56 bytes
// Khung tháo gỡ #1531 | Địa chỉ PC: 0x0ea990 | Địa chỉ FDE: 0x1abac8 | Kích thước: 56 bytes
//   0x0ea990: BD401800  ldr      s0, [x0, #0x18]
//   0x0ea994: A940A408  ldp      x8, x9, [x0, #8]
//   0x0ea998: 1E39000A  fcvtzu   w10, s0
//   0x0ea99c: B829690A  str      w10, [x8, x9]
static inline uint64_t fde_func_1531_0x0ea990(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ea990ULL ^ (static_cast<uint64_t>(0xbd401800ULL) << 13);
    acc = (acc + a1 + 0xa940a408ULL) ^ 0x1abac8ULL;
    acc ^= (acc >> 17) * 0x0038ULL;
    return acc;
}

// FDE #1532 | PC: 0x0ea9c8 | FDE: 0x1abaf8 | Size: 72 bytes
// Khung tháo gỡ #1532 | Địa chỉ PC: 0x0ea9c8 | Địa chỉ FDE: 0x1abaf8 | Kích thước: 72 bytes
//   0x0ea9c8: B9800808  ldrsw    x8, [x0, #8]
//   0x0ea9cc: BD401800  ldr      s0, [x0, #0x18]
//   0x0ea9d0: F9400809  ldr      x9, [x0, #0x10]
//   0x0ea9d4: F8687828  ldr      x8, [x1, x8, lsl #3]
static inline uint64_t fde_func_1532_0x0ea9c8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ea9c8ULL ^ (static_cast<uint64_t>(0xb9800808ULL) << 13);
    acc = (acc + a1 + 0xbd401800ULL) ^ 0x1abaf8ULL;
    acc ^= (acc >> 17) * 0x0048ULL;
    return acc;
}

// FDE #1533 | PC: 0x0eaa10 | FDE: 0x1abb28 | Size: 52 bytes
// Khung tháo gỡ #1533 | Địa chỉ PC: 0x0eaa10 | Địa chỉ FDE: 0x1abb28 | Kích thước: 52 bytes
//   0x0eaa10: FD400C00  ldr      d0, [x0, #0x18]
//   0x0eaa14: A940A408  ldp      x8, x9, [x0, #8]
//   0x0eaa18: 1E79000A  fcvtzu   w10, d0
//   0x0eaa1c: B829690A  str      w10, [x8, x9]
static inline uint64_t fde_func_1533_0x0eaa10(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0eaa10ULL ^ (static_cast<uint64_t>(0xfd400c00ULL) << 13);
    acc = (acc + a1 + 0xa940a408ULL) ^ 0x1abb28ULL;
    acc ^= (acc >> 17) * 0x0034ULL;
    return acc;
}

// FDE #1534 | PC: 0x0eaa44 | FDE: 0x1abb58 | Size: 68 bytes
// Khung tháo gỡ #1534 | Địa chỉ PC: 0x0eaa44 | Địa chỉ FDE: 0x1abb58 | Kích thước: 68 bytes
//   0x0eaa44: B9800808  ldrsw    x8, [x0, #8]
//   0x0eaa48: FD400C00  ldr      d0, [x0, #0x18]
//   0x0eaa4c: F9400809  ldr      x9, [x0, #0x10]
//   0x0eaa50: F8687828  ldr      x8, [x1, x8, lsl #3]
static inline uint64_t fde_func_1534_0x0eaa44(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0eaa44ULL ^ (static_cast<uint64_t>(0xb9800808ULL) << 13);
    acc = (acc + a1 + 0xfd400c00ULL) ^ 0x1abb58ULL;
    acc ^= (acc >> 17) * 0x0044ULL;
    return acc;
}

// FDE #1535 | PC: 0x0eaa88 | FDE: 0x1abb88 | Size: 60 bytes
// Khung tháo gỡ #1535 | Địa chỉ PC: 0x0eaa88 | Địa chỉ FDE: 0x1abb88 | Kích thước: 60 bytes
//   0x0eaa88: F9400408  ldr      x8, [x0, #8]
//   0x0eaa8c: D00006EB  adrp     x11, #0x1c8000
//   0x0eaa90: 9110816B  add      x11, x11, #0x420
//   0x0eaa94: 79400509  ldrh     w9, [x8, #2]
static inline uint64_t fde_func_1535_0x0eaa88(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0eaa88ULL ^ (static_cast<uint64_t>(0xf9400408ULL) << 13);
    acc = (acc + a1 + 0xd00006ebULL) ^ 0x1abb88ULL;
    acc ^= (acc >> 17) * 0x003cULL;
    return acc;
}

// FDE #1536 | PC: 0x0eaac4 | FDE: 0x1abbb8 | Size: 56 bytes
// Khung tháo gỡ #1536 | Địa chỉ PC: 0x0eaac4 | Địa chỉ FDE: 0x1abbb8 | Kích thước: 56 bytes
//   0x0eaac4: B9801808  ldrsw    x8, [x0, #0x18]
//   0x0eaac8: A940A809  ldp      x9, x10, [x0, #8]
//   0x0eaacc: D37DF108  lsl      x8, x8, #3
//   0x0eaad0: B8686828  ldr      w8, [x1, x8]
static inline uint64_t fde_func_1536_0x0eaac4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0eaac4ULL ^ (static_cast<uint64_t>(0xb9801808ULL) << 13);
    acc = (acc + a1 + 0xa940a809ULL) ^ 0x1abbb8ULL;
    acc ^= (acc >> 17) * 0x0038ULL;
    return acc;
}

// FDE #1537 | PC: 0x0eaafc | FDE: 0x1abbe8 | Size: 56 bytes
// Khung tháo gỡ #1537 | Địa chỉ PC: 0x0eaafc | Địa chỉ FDE: 0x1abbe8 | Kích thước: 56 bytes
//   0x0eaafc: B9801809  ldrsw    x9, [x0, #0x18]
//   0x0eab00: B9800808  ldrsw    x8, [x0, #8]
//   0x0eab04: F940080A  ldr      x10, [x0, #0x10]
//   0x0eab08: D37DF129  lsl      x9, x9, #3
static inline uint64_t fde_func_1537_0x0eaafc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0eaafcULL ^ (static_cast<uint64_t>(0xb9801809ULL) << 13);
    acc = (acc + a1 + 0xb9800808ULL) ^ 0x1abbe8ULL;
    acc ^= (acc >> 17) * 0x0038ULL;
    return acc;
}

// FDE #1538 | PC: 0x0eab34 | FDE: 0x1abc18 | Size: 48 bytes
// Khung tháo gỡ #1538 | Địa chỉ PC: 0x0eab34 | Địa chỉ FDE: 0x1abc18 | Kích thước: 48 bytes
//   0x0eab34: B9801808  ldrsw    x8, [x0, #0x18]
//   0x0eab38: A940A809  ldp      x9, x10, [x0, #8]
//   0x0eab3c: F8687828  ldr      x8, [x1, x8, lsl #3]
//   0x0eab40: F82A6928  str      x8, [x9, x10]
static inline uint64_t fde_func_1538_0x0eab34(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0eab34ULL ^ (static_cast<uint64_t>(0xb9801808ULL) << 13);
    acc = (acc + a1 + 0xa940a809ULL) ^ 0x1abc18ULL;
    acc ^= (acc >> 17) * 0x0030ULL;
    return acc;
}

// FDE #1539 | PC: 0x0eab64 | FDE: 0x1abc48 | Size: 56 bytes
// Khung tháo gỡ #1539 | Địa chỉ PC: 0x0eab64 | Địa chỉ FDE: 0x1abc48 | Kích thước: 56 bytes
//   0x0eab64: B9800808  ldrsw    x8, [x0, #8]
//   0x0eab68: B9801809  ldrsw    x9, [x0, #0x18]
//   0x0eab6c: F940080A  ldr      x10, [x0, #0x10]
//   0x0eab70: F8687828  ldr      x8, [x1, x8, lsl #3]
static inline uint64_t fde_func_1539_0x0eab64(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0eab64ULL ^ (static_cast<uint64_t>(0xb9800808ULL) << 13);
    acc = (acc + a1 + 0xb9801809ULL) ^ 0x1abc48ULL;
    acc ^= (acc >> 17) * 0x0038ULL;
    return acc;
}

// FDE #1540 | PC: 0x0eab9c | FDE: 0x1abc78 | Size: 64 bytes
// Khung tháo gỡ #1540 | Địa chỉ PC: 0x0eab9c | Địa chỉ FDE: 0x1abc78 | Kích thước: 64 bytes
//   0x0eab9c: B9801808  ldrsw    x8, [x0, #0x18]
//   0x0eaba0: D37DF108  lsl      x8, x8, #3
//   0x0eaba4: BC686820  ldr      s0, [x1, x8]
//   0x0eaba8: A940A408  ldp      x8, x9, [x0, #8]
static inline uint64_t fde_func_1540_0x0eab9c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0eab9cULL ^ (static_cast<uint64_t>(0xb9801808ULL) << 13);
    acc = (acc + a1 + 0xd37df108ULL) ^ 0x1abc78ULL;
    acc ^= (acc >> 17) * 0x0040ULL;
    return acc;
}

// FDE #1541 | PC: 0x0eabdc | FDE: 0x1abca8 | Size: 64 bytes
// Khung tháo gỡ #1541 | Địa chỉ PC: 0x0eabdc | Địa chỉ FDE: 0x1abca8 | Kích thước: 64 bytes
//   0x0eabdc: B9801808  ldrsw    x8, [x0, #0x18]
//   0x0eabe0: B9800809  ldrsw    x9, [x0, #8]
//   0x0eabe4: F940080A  ldr      x10, [x0, #0x10]
//   0x0eabe8: D37DF108  lsl      x8, x8, #3
static inline uint64_t fde_func_1541_0x0eabdc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0eabdcULL ^ (static_cast<uint64_t>(0xb9801808ULL) << 13);
    acc = (acc + a1 + 0xb9800809ULL) ^ 0x1abca8ULL;
    acc ^= (acc >> 17) * 0x0040ULL;
    return acc;
}

// FDE #1542 | PC: 0x0eac1c | FDE: 0x1abcd8 | Size: 60 bytes
// Khung tháo gỡ #1542 | Địa chỉ PC: 0x0eac1c | Địa chỉ FDE: 0x1abcd8 | Kích thước: 60 bytes
//   0x0eac1c: B9801808  ldrsw    x8, [x0, #0x18]
//   0x0eac20: FC687820  ldr      d0, [x1, x8, lsl #3]
//   0x0eac24: A940A408  ldp      x8, x9, [x0, #8]
//   0x0eac28: 9E79000A  fcvtzu   x10, d0
static inline uint64_t fde_func_1542_0x0eac1c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0eac1cULL ^ (static_cast<uint64_t>(0xb9801808ULL) << 13);
    acc = (acc + a1 + 0xfc687820ULL) ^ 0x1abcd8ULL;
    acc ^= (acc >> 17) * 0x003cULL;
    return acc;
}

// FDE #1543 | PC: 0x0eac58 | FDE: 0x1abd08 | Size: 76 bytes
// Khung tháo gỡ #1543 | Địa chỉ PC: 0x0eac58 | Địa chỉ FDE: 0x1abd08 | Kích thước: 76 bytes
//   0x0eac58: B9801808  ldrsw    x8, [x0, #0x18]
//   0x0eac5c: B9800809  ldrsw    x9, [x0, #8]
//   0x0eac60: F940080A  ldr      x10, [x0, #0x10]
//   0x0eac64: FC687820  ldr      d0, [x1, x8, lsl #3]
static inline uint64_t fde_func_1543_0x0eac58(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0eac58ULL ^ (static_cast<uint64_t>(0xb9801808ULL) << 13);
    acc = (acc + a1 + 0xb9800809ULL) ^ 0x1abd08ULL;
    acc ^= (acc >> 17) * 0x004cULL;
    return acc;
}

// FDE #1544 | PC: 0x0eaca4 | FDE: 0x1abd38 | Size: 56 bytes
// Khung tháo gỡ #1544 | Địa chỉ PC: 0x0eaca4 | Địa chỉ FDE: 0x1abd38 | Kích thước: 56 bytes
//   0x0eaca4: BD401800  ldr      s0, [x0, #0x18]
//   0x0eaca8: A940A408  ldp      x8, x9, [x0, #8]
//   0x0eacac: 7E21D800  ucvtf    s0, s0
//   0x0eacb0: BC296900  str      s0, [x8, x9]
static inline uint64_t fde_func_1544_0x0eaca4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0eaca4ULL ^ (static_cast<uint64_t>(0xbd401800ULL) << 13);
    acc = (acc + a1 + 0xa940a408ULL) ^ 0x1abd38ULL;
    acc ^= (acc >> 17) * 0x0038ULL;
    return acc;
}

// FDE #1545 | PC: 0x0eacdc | FDE: 0x1abd68 | Size: 72 bytes
// Khung tháo gỡ #1545 | Địa chỉ PC: 0x0eacdc | Địa chỉ FDE: 0x1abd68 | Kích thước: 72 bytes
//   0x0eacdc: B9800808  ldrsw    x8, [x0, #8]
//   0x0eace0: BD401800  ldr      s0, [x0, #0x18]
//   0x0eace4: F9400809  ldr      x9, [x0, #0x10]
//   0x0eace8: F8687828  ldr      x8, [x1, x8, lsl #3]
static inline uint64_t fde_func_1545_0x0eacdc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0eacdcULL ^ (static_cast<uint64_t>(0xb9800808ULL) << 13);
    acc = (acc + a1 + 0xbd401800ULL) ^ 0x1abd68ULL;
    acc ^= (acc >> 17) * 0x0048ULL;
    return acc;
}

// FDE #1546 | PC: 0x0ead24 | FDE: 0x1abd98 | Size: 52 bytes
// Khung tháo gỡ #1546 | Địa chỉ PC: 0x0ead24 | Địa chỉ FDE: 0x1abd98 | Kích thước: 52 bytes
//   0x0ead24: A941200A  ldp      x10, x8, [x0, #0x10]
//   0x0ead28: F9400409  ldr      x9, [x0, #8]
//   0x0ead2c: 9E230100  ucvtf    s0, x8
//   0x0ead30: BC2A6920  str      s0, [x9, x10]
static inline uint64_t fde_func_1546_0x0ead24(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ead24ULL ^ (static_cast<uint64_t>(0xa941200aULL) << 13);
    acc = (acc + a1 + 0xf9400409ULL) ^ 0x1abd98ULL;
    acc ^= (acc >> 17) * 0x0034ULL;
    return acc;
}

// FDE #1547 | PC: 0x0ead58 | FDE: 0x1abdc8 | Size: 64 bytes
// Khung tháo gỡ #1547 | Địa chỉ PC: 0x0ead58 | Địa chỉ FDE: 0x1abdc8 | Kích thước: 64 bytes
//   0x0ead58: B9800808  ldrsw    x8, [x0, #8]
//   0x0ead5c: A9412809  ldp      x9, x10, [x0, #0x10]
//   0x0ead60: F8687828  ldr      x8, [x1, x8, lsl #3]
//   0x0ead64: 9E230140  ucvtf    s0, x10
static inline uint64_t fde_func_1547_0x0ead58(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ead58ULL ^ (static_cast<uint64_t>(0xb9800808ULL) << 13);
    acc = (acc + a1 + 0xa9412809ULL) ^ 0x1abdc8ULL;
    acc ^= (acc >> 17) * 0x0040ULL;
    return acc;
}

// FDE #1548 | PC: 0x0ead98 | FDE: 0x1abdf8 | Size: 48 bytes
// Khung tháo gỡ #1548 | Địa chỉ PC: 0x0ead98 | Địa chỉ FDE: 0x1abdf8 | Kích thước: 48 bytes
//   0x0ead98: A940A408  ldp      x8, x9, [x0, #8]
//   0x0ead9c: B940180A  ldr      w10, [x0, #0x18]
//   0x0eada0: B829690A  str      w10, [x8, x9]
//   0x0eada4: F8420C04  ldr      x4, [x0, #0x20]!
static inline uint64_t fde_func_1548_0x0ead98(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ead98ULL ^ (static_cast<uint64_t>(0xa940a408ULL) << 13);
    acc = (acc + a1 + 0xb940180aULL) ^ 0x1abdf8ULL;
    acc ^= (acc >> 17) * 0x0030ULL;
    return acc;
}

// FDE #1549 | PC: 0x0eadc8 | FDE: 0x1abe28 | Size: 64 bytes
// Khung tháo gỡ #1549 | Địa chỉ PC: 0x0eadc8 | Địa chỉ FDE: 0x1abe28 | Kích thước: 64 bytes
//   0x0eadc8: B9800808  ldrsw    x8, [x0, #8]
//   0x0eadcc: F9400809  ldr      x9, [x0, #0x10]
//   0x0eadd0: B940180A  ldr      w10, [x0, #0x18]
//   0x0eadd4: F8687828  ldr      x8, [x1, x8, lsl #3]
static inline uint64_t fde_func_1549_0x0eadc8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0eadc8ULL ^ (static_cast<uint64_t>(0xb9800808ULL) << 13);
    acc = (acc + a1 + 0xf9400809ULL) ^ 0x1abe28ULL;
    acc ^= (acc >> 17) * 0x0040ULL;
    return acc;
}

// FDE #1550 | PC: 0x0eae08 | FDE: 0x1abe58 | Size: 52 bytes
// Khung tháo gỡ #1550 | Địa chỉ PC: 0x0eae08 | Địa chỉ FDE: 0x1abe58 | Kích thước: 52 bytes
//   0x0eae08: FD400C00  ldr      d0, [x0, #0x18]
//   0x0eae0c: A940A408  ldp      x8, x9, [x0, #8]
//   0x0eae10: 1E624000  fcvt     s0, d0
//   0x0eae14: BC296900  str      s0, [x8, x9]
static inline uint64_t fde_func_1550_0x0eae08(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0eae08ULL ^ (static_cast<uint64_t>(0xfd400c00ULL) << 13);
    acc = (acc + a1 + 0xa940a408ULL) ^ 0x1abe58ULL;
    acc ^= (acc >> 17) * 0x0034ULL;
    return acc;
}

// FDE #1551 | PC: 0x0eae3c | FDE: 0x1abe88 | Size: 68 bytes
// Khung tháo gỡ #1551 | Địa chỉ PC: 0x0eae3c | Địa chỉ FDE: 0x1abe88 | Kích thước: 68 bytes
//   0x0eae3c: B9800808  ldrsw    x8, [x0, #8]
//   0x0eae40: FD400C00  ldr      d0, [x0, #0x18]
//   0x0eae44: F9400809  ldr      x9, [x0, #0x10]
//   0x0eae48: F8687828  ldr      x8, [x1, x8, lsl #3]
static inline uint64_t fde_func_1551_0x0eae3c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0eae3cULL ^ (static_cast<uint64_t>(0xb9800808ULL) << 13);
    acc = (acc + a1 + 0xfd400c00ULL) ^ 0x1abe88ULL;
    acc ^= (acc >> 17) * 0x0044ULL;
    return acc;
}

// FDE #1552 | PC: 0x0eae80 | FDE: 0x1abeb8 | Size: 64 bytes
// Khung tháo gỡ #1552 | Địa chỉ PC: 0x0eae80 | Địa chỉ FDE: 0x1abeb8 | Kích thước: 64 bytes
//   0x0eae80: F9400408  ldr      x8, [x0, #8]
//   0x0eae84: D00006EB  adrp     x11, #0x1c8000
//   0x0eae88: 9114816B  add      x11, x11, #0x520
//   0x0eae8c: 79400509  ldrh     w9, [x8, #2]
static inline uint64_t fde_func_1552_0x0eae80(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0eae80ULL ^ (static_cast<uint64_t>(0xf9400408ULL) << 13);
    acc = (acc + a1 + 0xd00006ebULL) ^ 0x1abeb8ULL;
    acc ^= (acc >> 17) * 0x0040ULL;
    return acc;
}

// FDE #1553 | PC: 0x0eaec0 | FDE: 0x1abee8 | Size: 64 bytes
// Khung tháo gỡ #1553 | Địa chỉ PC: 0x0eaec0 | Địa chỉ FDE: 0x1abee8 | Kích thước: 64 bytes
//   0x0eaec0: B9801808  ldrsw    x8, [x0, #0x18]
//   0x0eaec4: D37DF108  lsl      x8, x8, #3
//   0x0eaec8: BC686820  ldr      s0, [x1, x8]
//   0x0eaecc: A940A408  ldp      x8, x9, [x0, #8]
static inline uint64_t fde_func_1553_0x0eaec0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0eaec0ULL ^ (static_cast<uint64_t>(0xb9801808ULL) << 13);
    acc = (acc + a1 + 0xd37df108ULL) ^ 0x1abee8ULL;
    acc ^= (acc >> 17) * 0x0040ULL;
    return acc;
}

// FDE #1554 | PC: 0x0eaf00 | FDE: 0x1abf18 | Size: 64 bytes
// Khung tháo gỡ #1554 | Địa chỉ PC: 0x0eaf00 | Địa chỉ FDE: 0x1abf18 | Kích thước: 64 bytes
//   0x0eaf00: B9801808  ldrsw    x8, [x0, #0x18]
//   0x0eaf04: B9800809  ldrsw    x9, [x0, #8]
//   0x0eaf08: F940080A  ldr      x10, [x0, #0x10]
//   0x0eaf0c: D37DF108  lsl      x8, x8, #3
static inline uint64_t fde_func_1554_0x0eaf00(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0eaf00ULL ^ (static_cast<uint64_t>(0xb9801808ULL) << 13);
    acc = (acc + a1 + 0xb9800809ULL) ^ 0x1abf18ULL;
    acc ^= (acc >> 17) * 0x0040ULL;
    return acc;
}

// FDE #1555 | PC: 0x0eaf40 | FDE: 0x1abf48 | Size: 60 bytes
// Khung tháo gỡ #1555 | Địa chỉ PC: 0x0eaf40 | Địa chỉ FDE: 0x1abf48 | Kích thước: 60 bytes
//   0x0eaf40: B9801808  ldrsw    x8, [x0, #0x18]
//   0x0eaf44: FC687820  ldr      d0, [x1, x8, lsl #3]
//   0x0eaf48: A940A408  ldp      x8, x9, [x0, #8]
//   0x0eaf4c: 7E61D800  ucvtf    d0, d0
static inline uint64_t fde_func_1555_0x0eaf40(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0eaf40ULL ^ (static_cast<uint64_t>(0xb9801808ULL) << 13);
    acc = (acc + a1 + 0xfc687820ULL) ^ 0x1abf48ULL;
    acc ^= (acc >> 17) * 0x003cULL;
    return acc;
}

// FDE #1556 | PC: 0x0eaf7c | FDE: 0x1abf78 | Size: 60 bytes
// Khung tháo gỡ #1556 | Địa chỉ PC: 0x0eaf7c | Địa chỉ FDE: 0x1abf78 | Kích thước: 60 bytes
//   0x0eaf7c: B9801808  ldrsw    x8, [x0, #0x18]
//   0x0eaf80: B9800809  ldrsw    x9, [x0, #8]
//   0x0eaf84: F940080A  ldr      x10, [x0, #0x10]
//   0x0eaf88: FC687820  ldr      d0, [x1, x8, lsl #3]
static inline uint64_t fde_func_1556_0x0eaf7c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0eaf7cULL ^ (static_cast<uint64_t>(0xb9801808ULL) << 13);
    acc = (acc + a1 + 0xb9800809ULL) ^ 0x1abf78ULL;
    acc ^= (acc >> 17) * 0x003cULL;
    return acc;
}

// FDE #1557 | PC: 0x0eafb8 | FDE: 0x1abfa8 | Size: 64 bytes
// Khung tháo gỡ #1557 | Địa chỉ PC: 0x0eafb8 | Địa chỉ FDE: 0x1abfa8 | Kích thước: 64 bytes
//   0x0eafb8: B9801808  ldrsw    x8, [x0, #0x18]
//   0x0eafbc: D37DF108  lsl      x8, x8, #3
//   0x0eafc0: BC686820  ldr      s0, [x1, x8]
//   0x0eafc4: A940A408  ldp      x8, x9, [x0, #8]
static inline uint64_t fde_func_1557_0x0eafb8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0eafb8ULL ^ (static_cast<uint64_t>(0xb9801808ULL) << 13);
    acc = (acc + a1 + 0xd37df108ULL) ^ 0x1abfa8ULL;
    acc ^= (acc >> 17) * 0x0040ULL;
    return acc;
}

// FDE #1558 | PC: 0x0eaff8 | FDE: 0x1abfd8 | Size: 60 bytes
// Khung tháo gỡ #1558 | Địa chỉ PC: 0x0eaff8 | Địa chỉ FDE: 0x1abfd8 | Kích thước: 60 bytes
//   0x0eaff8: B9801808  ldrsw    x8, [x0, #0x18]
//   0x0eaffc: B9800809  ldrsw    x9, [x0, #8]
//   0x0eb000: F940080A  ldr      x10, [x0, #0x10]
//   0x0eb004: D37DF108  lsl      x8, x8, #3
static inline uint64_t fde_func_1558_0x0eaff8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0eaff8ULL ^ (static_cast<uint64_t>(0xb9801808ULL) << 13);
    acc = (acc + a1 + 0xb9800809ULL) ^ 0x1abfd8ULL;
    acc ^= (acc >> 17) * 0x003cULL;
    return acc;
}

// FDE #1559 | PC: 0x0eb034 | FDE: 0x1ac008 | Size: 48 bytes
// Khung tháo gỡ #1559 | Địa chỉ PC: 0x0eb034 | Địa chỉ FDE: 0x1ac008 | Kích thước: 48 bytes
//   0x0eb034: B9801808  ldrsw    x8, [x0, #0x18]
//   0x0eb038: A940A809  ldp      x9, x10, [x0, #8]
//   0x0eb03c: F8687828  ldr      x8, [x1, x8, lsl #3]
//   0x0eb040: F82A6928  str      x8, [x9, x10]
static inline uint64_t fde_func_1559_0x0eb034(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0eb034ULL ^ (static_cast<uint64_t>(0xb9801808ULL) << 13);
    acc = (acc + a1 + 0xa940a809ULL) ^ 0x1ac008ULL;
    acc ^= (acc >> 17) * 0x0030ULL;
    return acc;
}

// FDE #1560 | PC: 0x0eb064 | FDE: 0x1ac038 | Size: 44 bytes
// Khung tháo gỡ #1560 | Địa chỉ PC: 0x0eb064 | Địa chỉ FDE: 0x1ac038 | Kích thước: 44 bytes
//   0x0eb064: B9800808  ldrsw    x8, [x0, #8]
//   0x0eb068: B9801809  ldrsw    x9, [x0, #0x18]
//   0x0eb06c: F940080A  ldr      x10, [x0, #0x10]
//   0x0eb070: F8687828  ldr      x8, [x1, x8, lsl #3]
static inline uint64_t fde_func_1560_0x0eb064(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0eb064ULL ^ (static_cast<uint64_t>(0xb9800808ULL) << 13);
    acc = (acc + a1 + 0xb9801809ULL) ^ 0x1ac038ULL;
    acc ^= (acc >> 17) * 0x002cULL;
    return acc;
}

// FDE #1561 | PC: 0x0eb090 | FDE: 0x1ac068 | Size: 56 bytes
// Khung tháo gỡ #1561 | Địa chỉ PC: 0x0eb090 | Địa chỉ FDE: 0x1ac068 | Kích thước: 56 bytes
//   0x0eb090: F9400448  ldr      x8, [x2, #8]
//   0x0eb094: B9800809  ldrsw    x9, [x0, #8]
//   0x0eb098: B9402108  ldr      w8, [x8, #0x20]
//   0x0eb09c: D37DF129  lsl      x9, x9, #3
static inline uint64_t fde_func_1561_0x0eb090(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0eb090ULL ^ (static_cast<uint64_t>(0xf9400448ULL) << 13);
    acc = (acc + a1 + 0xb9800809ULL) ^ 0x1ac068ULL;
    acc ^= (acc >> 17) * 0x0038ULL;
    return acc;
}

// FDE #1562 | PC: 0x0eb0c8 | FDE: 0x1ac098 | Size: 256 bytes
// Khung tháo gỡ #1562 | Địa chỉ PC: 0x0eb0c8 | Địa chỉ FDE: 0x1ac098 | Kích thước: 256 bytes
//   0x0eb0c8: D101C3FF  sub      sp, sp, #0x70
//   0x0eb0cc: A9016FFC  stp      x28, x27, [sp, #0x10]
//   0x0eb0d0: A90267FA  stp      x26, x25, [sp, #0x20]
//   0x0eb0d4: A9035FF8  stp      x24, x23, [sp, #0x30]
static inline uint64_t fde_func_1562_0x0eb0c8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0eb0c8ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xa9016ffcULL) ^ 0x1ac098ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1563 | PC: 0x0eb638 | FDE: 0x1ac0f8 | Size: 24 bytes
// Khung tháo gỡ #1563 | Địa chỉ PC: 0x0eb638 | Địa chỉ FDE: 0x1ac0f8 | Kích thước: 24 bytes
//   0x0eb638: 90000000  adrp     x0, #0xeb000
//   0x0eb63c: 91191000  add      x0, x0, #0x644
//   0x0eb640: D65F03C0  ret      
//   0x0eb644: F9400400  ldr      x0, [x0, #8]
static inline uint64_t fde_func_1563_0x0eb638(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0eb638ULL ^ (static_cast<uint64_t>(0x90000000ULL) << 13);
    acc = (acc + a1 + 0x91191000ULL) ^ 0x1ac0f8ULL;
    acc ^= (acc >> 17) * 0x0018ULL;
    return acc;
}

// FDE #1564 | PC: 0x0eb650 | FDE: 0x1ac128 | Size: 64 bytes
// Khung tháo gỡ #1564 | Địa chỉ PC: 0x0eb650 | Địa chỉ FDE: 0x1ac128 | Kích thước: 64 bytes
//   0x0eb650: F9400408  ldr      x8, [x0, #8]
//   0x0eb654: B00006E9  adrp     x9, #0x1c8000
//   0x0eb658: 9116C129  add      x9, x9, #0x5b0
//   0x0eb65c: 39400108  ldrb     w8, [x8]
static inline uint64_t fde_func_1564_0x0eb650(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0eb650ULL ^ (static_cast<uint64_t>(0xf9400408ULL) << 13);
    acc = (acc + a1 + 0xb00006e9ULL) ^ 0x1ac128ULL;
    acc ^= (acc >> 17) * 0x0040ULL;
    return acc;
}

// FDE #1565 | PC: 0x0eb690 | FDE: 0x1ac158 | Size: 64 bytes
// Khung tháo gỡ #1565 | Địa chỉ PC: 0x0eb690 | Địa chỉ FDE: 0x1ac158 | Kích thước: 64 bytes
//   0x0eb690: F9400408  ldr      x8, [x0, #8]
//   0x0eb694: B00006E9  adrp     x9, #0x1c8000
//   0x0eb698: 91170129  add      x9, x9, #0x5c0
//   0x0eb69c: 39400108  ldrb     w8, [x8]
static inline uint64_t fde_func_1565_0x0eb690(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0eb690ULL ^ (static_cast<uint64_t>(0xf9400408ULL) << 13);
    acc = (acc + a1 + 0xb00006e9ULL) ^ 0x1ac158ULL;
    acc ^= (acc >> 17) * 0x0040ULL;
    return acc;
}

// FDE #1566 | PC: 0x0eb6d0 | FDE: 0x1ac188 | Size: 20 bytes
// Khung tháo gỡ #1566 | Địa chỉ PC: 0x0eb6d0 | Địa chỉ FDE: 0x1ac188 | Kích thước: 20 bytes
//   0x0eb6d0: 90000000  adrp     x0, #0xeb000
//   0x0eb6d4: 911B7000  add      x0, x0, #0x6dc
//   0x0eb6d8: D65F03C0  ret      
//   0x0eb6dc: 52800100  mov      w0, #8
static inline uint64_t fde_func_1566_0x0eb6d0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0eb6d0ULL ^ (static_cast<uint64_t>(0x90000000ULL) << 13);
    acc = (acc + a1 + 0x911b7000ULL) ^ 0x1ac188ULL;
    acc ^= (acc >> 17) * 0x0014ULL;
    return acc;
}

// FDE #1567 | PC: 0x0eb6e4 | FDE: 0x1ac1b8 | Size: 256 bytes
// Khung tháo gỡ #1567 | Địa chỉ PC: 0x0eb6e4 | Địa chỉ FDE: 0x1ac1b8 | Kích thước: 256 bytes
//   0x0eb6e4: D10203FF  sub      sp, sp, #0x80
//   0x0eb6e8: A9026FFC  stp      x28, x27, [sp, #0x20]
//   0x0eb6ec: A90367FA  stp      x26, x25, [sp, #0x30]
//   0x0eb6f0: A9045FF8  stp      x24, x23, [sp, #0x40]
static inline uint64_t fde_func_1567_0x0eb6e4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0eb6e4ULL ^ (static_cast<uint64_t>(0xd10203ffULL) << 13);
    acc = (acc + a1 + 0xa9026ffcULL) ^ 0x1ac1b8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1568 | PC: 0x0ebc88 | FDE: 0x1ac200 | Size: 256 bytes
// Khung tháo gỡ #1568 | Địa chỉ PC: 0x0ebc88 | Địa chỉ FDE: 0x1ac200 | Kích thước: 256 bytes
//   0x0ebc88: D10283FF  sub      sp, sp, #0xa0
//   0x0ebc8c: A9046FFC  stp      x28, x27, [sp, #0x40]
//   0x0ebc90: A90567FA  stp      x26, x25, [sp, #0x50]
//   0x0ebc94: A9065FF8  stp      x24, x23, [sp, #0x60]
static inline uint64_t fde_func_1568_0x0ebc88(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ebc88ULL ^ (static_cast<uint64_t>(0xd10283ffULL) << 13);
    acc = (acc + a1 + 0xa9046ffcULL) ^ 0x1ac200ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1569 | PC: 0x0ed900 | FDE: 0x1ac258 | Size: 256 bytes
// Khung tháo gỡ #1569 | Địa chỉ PC: 0x0ed900 | Địa chỉ FDE: 0x1ac258 | Kích thước: 256 bytes
//   0x0ed900: D107C3FF  sub      sp, sp, #0x1f0
//   0x0ed904: A9196FFC  stp      x28, x27, [sp, #0x190]
//   0x0ed908: A91A67FA  stp      x26, x25, [sp, #0x1a0]
//   0x0ed90c: A91B5FF8  stp      x24, x23, [sp, #0x1b0]
static inline uint64_t fde_func_1569_0x0ed900(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ed900ULL ^ (static_cast<uint64_t>(0xd107c3ffULL) << 13);
    acc = (acc + a1 + 0xa9196ffcULL) ^ 0x1ac258ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1570 | PC: 0x0ee118 | FDE: 0x1ac2b0 | Size: 256 bytes
// Khung tháo gỡ #1570 | Địa chỉ PC: 0x0ee118 | Địa chỉ FDE: 0x1ac2b0 | Kích thước: 256 bytes
//   0x0ee118: D10203FF  sub      sp, sp, #0x80
//   0x0ee11c: F9001BF9  str      x25, [sp, #0x30]
//   0x0ee120: A9045FF8  stp      x24, x23, [sp, #0x40]
//   0x0ee124: A90557F6  stp      x22, x21, [sp, #0x50]
static inline uint64_t fde_func_1570_0x0ee118(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ee118ULL ^ (static_cast<uint64_t>(0xd10203ffULL) << 13);
    acc = (acc + a1 + 0xf9001bf9ULL) ^ 0x1ac2b0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1571 | PC: 0x0ee2c4 | FDE: 0x1ac2f8 | Size: 220 bytes
// Khung tháo gỡ #1571 | Địa chỉ PC: 0x0ee2c4 | Địa chỉ FDE: 0x1ac2f8 | Kích thước: 220 bytes
//   0x0ee2c4: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0ee2c8: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0ee2cc: 910043FD  add      x29, sp, #0x10
//   0x0ee2d0: A9007C1F  stp      xzr, xzr, [x0]
static inline uint64_t fde_func_1571_0x0ee2c4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ee2c4ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1ac2f8ULL;
    acc ^= (acc >> 17) * 0x00dcULL;
    return acc;
}

// FDE #1572 | PC: 0x0ee3a0 | FDE: 0x1ac338 | Size: 256 bytes
// Khung tháo gỡ #1572 | Địa chỉ PC: 0x0ee3a0 | Địa chỉ FDE: 0x1ac338 | Kích thước: 256 bytes
//   0x0ee3a0: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x0ee3a4: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0ee3a8: 910043FD  add      x29, sp, #0x10
//   0x0ee3ac: F9400401  ldr      x1, [x0, #8]
static inline uint64_t fde_func_1572_0x0ee3a0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ee3a0ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1ac338ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1573 | PC: 0x0ee510 | FDE: 0x1ac380 | Size: 168 bytes
// Khung tháo gỡ #1573 | Địa chỉ PC: 0x0ee510 | Địa chỉ FDE: 0x1ac380 | Kích thước: 168 bytes
//   0x0ee510: 2A1F03E0  mov      w0, wzr
//   0x0ee514: D65F03C0  ret      
//   0x0ee518: A940200B  ldp      x11, x8, [x0]
//   0x0ee51c: EB0B011F  cmp      x8, x11
static inline uint64_t fde_func_1573_0x0ee510(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ee510ULL ^ (static_cast<uint64_t>(0x2a1f03e0ULL) << 13);
    acc = (acc + a1 + 0xd65f03c0ULL) ^ 0x1ac380ULL;
    acc ^= (acc >> 17) * 0x00a8ULL;
    return acc;
}

// FDE #1574 | PC: 0x0ee5b8 | FDE: 0x1ac3b0 | Size: 256 bytes
// Khung tháo gỡ #1574 | Địa chỉ PC: 0x0ee5b8 | Địa chỉ FDE: 0x1ac3b0 | Kích thước: 256 bytes
//   0x0ee5b8: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0ee5bc: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0ee5c0: 910043FD  add      x29, sp, #0x10
//   0x0ee5c4: F9400808  ldr      x8, [x0, #0x10]
static inline uint64_t fde_func_1574_0x0ee5b8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ee5b8ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1ac3b0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1575 | PC: 0x0ee790 | FDE: 0x1ac3f8 | Size: 156 bytes
// Khung tháo gỡ #1575 | Địa chỉ PC: 0x0ee790 | Địa chỉ FDE: 0x1ac3f8 | Kích thước: 156 bytes
//   0x0ee790: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0ee794: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0ee798: 910043FD  add      x29, sp, #0x10
//   0x0ee79c: D37DFC28  lsr      x8, x1, #0x3d
static inline uint64_t fde_func_1575_0x0ee790(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ee790ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1ac3f8ULL;
    acc ^= (acc >> 17) * 0x009cULL;
    return acc;
}

// FDE #1576 | PC: 0x0ee82c | FDE: 0x1ac430 | Size: 116 bytes
// Khung tháo gỡ #1576 | Địa chỉ PC: 0x0ee82c | Địa chỉ FDE: 0x1ac430 | Kích thước: 116 bytes
//   0x0ee82c: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x0ee830: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0ee834: 910043FD  add      x29, sp, #0x10
//   0x0ee838: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_1576_0x0ee82c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ee82cULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1ac430ULL;
    acc ^= (acc >> 17) * 0x0074ULL;
    return acc;
}

// FDE #1577 | PC: 0x0ee8a0 | FDE: 0x1ac470 | Size: 56 bytes
// Khung tháo gỡ #1577 | Địa chỉ PC: 0x0ee8a0 | Địa chỉ FDE: 0x1ac470 | Kích thước: 56 bytes
//   0x0ee8a0: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x0ee8a4: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0ee8a8: 910043FD  add      x29, sp, #0x10
//   0x0ee8ac: AA1F03E1  mov      x1, xzr
static inline uint64_t fde_func_1577_0x0ee8a0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ee8a0ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1ac470ULL;
    acc ^= (acc >> 17) * 0x0038ULL;
    return acc;
}

// FDE #1578 | PC: 0x0ee8d8 | FDE: 0x1ac4a8 | Size: 48 bytes
// Khung tháo gỡ #1578 | Địa chỉ PC: 0x0ee8d8 | Địa chỉ FDE: 0x1ac4a8 | Kích thước: 48 bytes
//   0x0ee8d8: 528002A0  mov      w0, #0x15
//   0x0ee8dc: D65F03C0  ret      
//   0x0ee8e0: D10083FF  sub      sp, sp, #0x20
//   0x0ee8e4: A9017BFD  stp      x29, x30, [sp, #0x10]
static inline uint64_t fde_func_1578_0x0ee8d8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ee8d8ULL ^ (static_cast<uint64_t>(0x528002a0ULL) << 13);
    acc = (acc + a1 + 0xd65f03c0ULL) ^ 0x1ac4a8ULL;
    acc ^= (acc >> 17) * 0x0030ULL;
    return acc;
}

// FDE #1579 | PC: 0x0ee908 | FDE: 0x1ac4e0 | Size: 120 bytes
// Khung tháo gỡ #1579 | Địa chỉ PC: 0x0ee908 | Địa chỉ FDE: 0x1ac4e0 | Kích thước: 120 bytes
//   0x0ee908: F9400008  ldr      x8, [x0]
//   0x0ee90c: F9005D01  str      x1, [x8, #0xb8]
//   0x0ee910: 90000788  adrp     x8, #0x1de000
//   0x0ee914: B9459900  ldr      w0, [x8, #0x598]
static inline uint64_t fde_func_1579_0x0ee908(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ee908ULL ^ (static_cast<uint64_t>(0xf9400008ULL) << 13);
    acc = (acc + a1 + 0xf9005d01ULL) ^ 0x1ac4e0ULL;
    acc ^= (acc >> 17) * 0x0078ULL;
    return acc;
}

// FDE #1580 | PC: 0x0ee980 | FDE: 0x1ac518 | Size: 224 bytes
// Khung tháo gỡ #1580 | Địa chỉ PC: 0x0ee980 | Địa chỉ FDE: 0x1ac518 | Kích thước: 224 bytes
//   0x0ee980: D10203FF  sub      sp, sp, #0x80
//   0x0ee984: F90023F7  str      x23, [sp, #0x40]
//   0x0ee988: A90557F6  stp      x22, x21, [sp, #0x50]
//   0x0ee98c: A9064FF4  stp      x20, x19, [sp, #0x60]
static inline uint64_t fde_func_1580_0x0ee980(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ee980ULL ^ (static_cast<uint64_t>(0xd10203ffULL) << 13);
    acc = (acc + a1 + 0xf90023f7ULL) ^ 0x1ac518ULL;
    acc ^= (acc >> 17) * 0x00e0ULL;
    return acc;
}

// FDE #1581 | PC: 0x0eea60 | FDE: 0x1ac560 | Size: 120 bytes
// Khung tháo gỡ #1581 | Địa chỉ PC: 0x0eea60 | Địa chỉ FDE: 0x1ac560 | Kích thước: 120 bytes
//   0x0eea60: D100C3FF  sub      sp, sp, #0x30
//   0x0eea64: F9000BF3  str      x19, [sp, #0x10]
//   0x0eea68: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0eea6c: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1581_0x0eea60(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0eea60ULL ^ (static_cast<uint64_t>(0xd100c3ffULL) << 13);
    acc = (acc + a1 + 0xf9000bf3ULL) ^ 0x1ac560ULL;
    acc ^= (acc >> 17) * 0x0078ULL;
    return acc;
}

// FDE #1582 | PC: 0x0eead8 | FDE: 0x1ac5a0 | Size: 256 bytes
// Khung tháo gỡ #1582 | Địa chỉ PC: 0x0eead8 | Địa chỉ FDE: 0x1ac5a0 | Kích thước: 256 bytes
//   0x0eead8: D10283FF  sub      sp, sp, #0xa0
//   0x0eeadc: A9046FFC  stp      x28, x27, [sp, #0x40]
//   0x0eeae0: A90567FA  stp      x26, x25, [sp, #0x50]
//   0x0eeae4: A9065FF8  stp      x24, x23, [sp, #0x60]
static inline uint64_t fde_func_1582_0x0eead8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0eead8ULL ^ (static_cast<uint64_t>(0xd10283ffULL) << 13);
    acc = (acc + a1 + 0xa9046ffcULL) ^ 0x1ac5a0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1583 | PC: 0x0eed20 | FDE: 0x1ac5f8 | Size: 256 bytes
// Khung tháo gỡ #1583 | Địa chỉ PC: 0x0eed20 | Địa chỉ FDE: 0x1ac5f8 | Kích thước: 256 bytes
//   0x0eed20: F9400000  ldr      x0, [x0]
//   0x0eed24: D65F03C0  ret      
//   0x0eed28: D102C3FF  sub      sp, sp, #0xb0
//   0x0eed2c: A9056FFC  stp      x28, x27, [sp, #0x50]
static inline uint64_t fde_func_1583_0x0eed20(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0eed20ULL ^ (static_cast<uint64_t>(0xf9400000ULL) << 13);
    acc = (acc + a1 + 0xd65f03c0ULL) ^ 0x1ac5f8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #1584 | PC: 0x0eeee8 | FDE: 0x1ac640 | Size: 100 bytes
// Khung tháo gỡ #1584 | Địa chỉ PC: 0x0eeee8 | Địa chỉ FDE: 0x1ac640 | Kích thước: 100 bytes
//   0x0eeee8: F9400028  ldr      x8, [x1]
//   0x0eeeec: F9000008  str      x8, [x0]
//   0x0eeef0: D65F03C0  ret      
//   0x0eeef4: F81D0FF5  str      x21, [sp, #-0x30]!
static inline uint64_t fde_func_1584_0x0eeee8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0eeee8ULL ^ (static_cast<uint64_t>(0xf9400028ULL) << 13);
    acc = (acc + a1 + 0xf9000008ULL) ^ 0x1ac640ULL;
    acc ^= (acc >> 17) * 0x0064ULL;
    return acc;
}

// FDE #1585 | PC: 0x0eef4c | FDE: 0x1ac678 | Size: 96 bytes
// Khung tháo gỡ #1585 | Địa chỉ PC: 0x0eef4c | Địa chỉ FDE: 0x1ac678 | Kích thước: 96 bytes
//   0x0eef4c: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x0eef50: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x0eef54: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x0eef58: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_1585_0x0eef4c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0eef4cULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1ac678ULL;
    acc ^= (acc >> 17) * 0x0060ULL;
    return acc;
}

// FDE #1586 | PC: 0x0eefac | FDE: 0x1ac6b0 | Size: 24 bytes
// Khung tháo gỡ #1586 | Địa chỉ PC: 0x0eefac | Địa chỉ FDE: 0x1ac6b0 | Kích thước: 24 bytes
//   0x0eefac: F9400028  ldr      x8, [x1]
//   0x0eefb0: F9000008  str      x8, [x0]
//   0x0eefb4: D65F03C0  ret      
//   0x0eefb8: F9400028  ldr      x8, [x1]
static inline uint64_t fde_func_1586_0x0eefac(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0eefacULL ^ (static_cast<uint64_t>(0xf9400028ULL) << 13);
    acc = (acc + a1 + 0xf9000008ULL) ^ 0x1ac6b0ULL;
    acc ^= (acc >> 17) * 0x0018ULL;
    return acc;
}

// FDE #1587 | PC: 0x0eefc4 | FDE: 0x1ac6e0 | Size: 32 bytes
// Khung tháo gỡ #1587 | Địa chỉ PC: 0x0eefc4 | Địa chỉ FDE: 0x1ac6e0 | Kích thước: 32 bytes
//   0x0eefc4: 12001C09  and      w9, w0, #0xff
//   0x0eefc8: F900011F  str      xzr, [x8]
//   0x0eefcc: B9000109  str      w9, [x8]
//   0x0eefd0: D65F03C0  ret      
static inline uint64_t fde_func_1587_0x0eefc4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0eefc4ULL ^ (static_cast<uint64_t>(0x12001c09ULL) << 13);
    acc = (acc + a1 + 0xf900011fULL) ^ 0x1ac6e0ULL;
    acc ^= (acc >> 17) * 0x0020ULL;
    return acc;
}

// FDE #1588 | PC: 0x0eefe4 | FDE: 0x1ac710 | Size: 32 bytes
// Khung tháo gỡ #1588 | Địa chỉ PC: 0x0eefe4 | Địa chỉ FDE: 0x1ac710 | Kích thước: 32 bytes
//   0x0eefe4: 12001C09  and      w9, w0, #0xff
//   0x0eefe8: F900011F  str      xzr, [x8]
//   0x0eefec: B9000109  str      w9, [x8]
//   0x0eeff0: D65F03C0  ret      
static inline uint64_t fde_func_1588_0x0eefe4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0eefe4ULL ^ (static_cast<uint64_t>(0x12001c09ULL) << 13);
    acc = (acc + a1 + 0xf900011fULL) ^ 0x1ac710ULL;
    acc ^= (acc >> 17) * 0x0020ULL;
    return acc;
}

// FDE #1589 | PC: 0x0ef004 | FDE: 0x1ac740 | Size: 32 bytes
// Khung tháo gỡ #1589 | Địa chỉ PC: 0x0ef004 | Địa chỉ FDE: 0x1ac740 | Kích thước: 32 bytes
//   0x0ef004: 13003C09  sxth     w9, w0
//   0x0ef008: F900011F  str      xzr, [x8]
//   0x0ef00c: B9000109  str      w9, [x8]
//   0x0ef010: D65F03C0  ret      
static inline uint64_t fde_func_1589_0x0ef004(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ef004ULL ^ (static_cast<uint64_t>(0x13003c09ULL) << 13);
    acc = (acc + a1 + 0xf900011fULL) ^ 0x1ac740ULL;
    acc ^= (acc >> 17) * 0x0020ULL;
    return acc;
}

// FDE #1590 | PC: 0x0ef024 | FDE: 0x1ac770 | Size: 32 bytes
// Khung tháo gỡ #1590 | Địa chỉ PC: 0x0ef024 | Địa chỉ FDE: 0x1ac770 | Kích thước: 32 bytes
//   0x0ef024: 12003C09  and      w9, w0, #0xffff
//   0x0ef028: F900011F  str      xzr, [x8]
//   0x0ef02c: B9000109  str      w9, [x8]
//   0x0ef030: D65F03C0  ret      
static inline uint64_t fde_func_1590_0x0ef024(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ef024ULL ^ (static_cast<uint64_t>(0x12003c09ULL) << 13);
    acc = (acc + a1 + 0xf900011fULL) ^ 0x1ac770ULL;
    acc ^= (acc >> 17) * 0x0020ULL;
    return acc;
}

// FDE #1591 | PC: 0x0ef044 | FDE: 0x1ac7a0 | Size: 24 bytes
// Khung tháo gỡ #1591 | Địa chỉ PC: 0x0ef044 | Địa chỉ FDE: 0x1ac7a0 | Kích thước: 24 bytes
//   0x0ef044: F900011F  str      xzr, [x8]
//   0x0ef048: B9000100  str      w0, [x8]
//   0x0ef04c: D65F03C0  ret      
//   0x0ef050: F900001F  str      xzr, [x0]
static inline uint64_t fde_func_1591_0x0ef044(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ef044ULL ^ (static_cast<uint64_t>(0xf900011fULL) << 13);
    acc = (acc + a1 + 0xb9000100ULL) ^ 0x1ac7a0ULL;
    acc ^= (acc >> 17) * 0x0018ULL;
    return acc;
}

// FDE #1592 | PC: 0x0ef05c | FDE: 0x1ac7d0 | Size: 24 bytes
// Khung tháo gỡ #1592 | Địa chỉ PC: 0x0ef05c | Địa chỉ FDE: 0x1ac7d0 | Kích thước: 24 bytes
//   0x0ef05c: F900011F  str      xzr, [x8]
//   0x0ef060: B9000100  str      w0, [x8]
//   0x0ef064: D65F03C0  ret      
//   0x0ef068: F900001F  str      xzr, [x0]
static inline uint64_t fde_func_1592_0x0ef05c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ef05cULL ^ (static_cast<uint64_t>(0xf900011fULL) << 13);
    acc = (acc + a1 + 0xb9000100ULL) ^ 0x1ac7d0ULL;
    acc ^= (acc >> 17) * 0x0018ULL;
    return acc;
}

// FDE #1593 | PC: 0x0ef074 | FDE: 0x1ac800 | Size: 16 bytes
// Khung tháo gỡ #1593 | Địa chỉ PC: 0x0ef074 | Địa chỉ FDE: 0x1ac800 | Kích thước: 16 bytes
//   0x0ef074: F9000100  str      x0, [x8]
//   0x0ef078: D65F03C0  ret      
//   0x0ef07c: F9000001  str      x1, [x0]
//   0x0ef080: D65F03C0  ret      
static inline uint64_t fde_func_1593_0x0ef074(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ef074ULL ^ (static_cast<uint64_t>(0xf9000100ULL) << 13);
    acc = (acc + a1 + 0xd65f03c0ULL) ^ 0x1ac800ULL;
    acc ^= (acc >> 17) * 0x0010ULL;
    return acc;
}

// FDE #1594 | PC: 0x0ef084 | FDE: 0x1ac830 | Size: 16 bytes
// Khung tháo gỡ #1594 | Địa chỉ PC: 0x0ef084 | Địa chỉ FDE: 0x1ac830 | Kích thước: 16 bytes
//   0x0ef084: F9000100  str      x0, [x8]
//   0x0ef088: D65F03C0  ret      
//   0x0ef08c: F9000001  str      x1, [x0]
//   0x0ef090: D65F03C0  ret      
static inline uint64_t fde_func_1594_0x0ef084(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ef084ULL ^ (static_cast<uint64_t>(0xf9000100ULL) << 13);
    acc = (acc + a1 + 0xd65f03c0ULL) ^ 0x1ac830ULL;
    acc ^= (acc >> 17) * 0x0010ULL;
    return acc;
}

// FDE #1595 | PC: 0x0ef094 | FDE: 0x1ac860 | Size: 16 bytes
// Khung tháo gỡ #1595 | Địa chỉ PC: 0x0ef094 | Địa chỉ FDE: 0x1ac860 | Kích thước: 16 bytes
//   0x0ef094: F9000100  str      x0, [x8]
//   0x0ef098: D65F03C0  ret      
//   0x0ef09c: F9000001  str      x1, [x0]
//   0x0ef0a0: D65F03C0  ret      
static inline uint64_t fde_func_1595_0x0ef094(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ef094ULL ^ (static_cast<uint64_t>(0xf9000100ULL) << 13);
    acc = (acc + a1 + 0xd65f03c0ULL) ^ 0x1ac860ULL;
    acc ^= (acc >> 17) * 0x0010ULL;
    return acc;
}

// FDE #1596 | PC: 0x0ef0a4 | FDE: 0x1ac890 | Size: 16 bytes
// Khung tháo gỡ #1596 | Địa chỉ PC: 0x0ef0a4 | Địa chỉ FDE: 0x1ac890 | Kích thước: 16 bytes
//   0x0ef0a4: F9000100  str      x0, [x8]
//   0x0ef0a8: D65F03C0  ret      
//   0x0ef0ac: F9000001  str      x1, [x0]
//   0x0ef0b0: D65F03C0  ret      
static inline uint64_t fde_func_1596_0x0ef0a4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ef0a4ULL ^ (static_cast<uint64_t>(0xf9000100ULL) << 13);
    acc = (acc + a1 + 0xd65f03c0ULL) ^ 0x1ac890ULL;
    acc ^= (acc >> 17) * 0x0010ULL;
    return acc;
}

// FDE #1597 | PC: 0x0ef0b4 | FDE: 0x1ac8c0 | Size: 24 bytes
// Khung tháo gỡ #1597 | Địa chỉ PC: 0x0ef0b4 | Địa chỉ FDE: 0x1ac8c0 | Kích thước: 24 bytes
//   0x0ef0b4: F900011F  str      xzr, [x8]
//   0x0ef0b8: BD000100  str      s0, [x8]
//   0x0ef0bc: D65F03C0  ret      
//   0x0ef0c0: F900001F  str      xzr, [x0]
static inline uint64_t fde_func_1597_0x0ef0b4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ef0b4ULL ^ (static_cast<uint64_t>(0xf900011fULL) << 13);
    acc = (acc + a1 + 0xbd000100ULL) ^ 0x1ac8c0ULL;
    acc ^= (acc >> 17) * 0x0018ULL;
    return acc;
}

// FDE #1598 | PC: 0x0ef0cc | FDE: 0x1ac8f0 | Size: 16 bytes
// Khung tháo gỡ #1598 | Địa chỉ PC: 0x0ef0cc | Địa chỉ FDE: 0x1ac8f0 | Kích thước: 16 bytes
//   0x0ef0cc: FD000100  str      d0, [x8]
//   0x0ef0d0: D65F03C0  ret      
//   0x0ef0d4: FD000000  str      d0, [x0]
//   0x0ef0d8: D65F03C0  ret      
static inline uint64_t fde_func_1598_0x0ef0cc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ef0ccULL ^ (static_cast<uint64_t>(0xfd000100ULL) << 13);
    acc = (acc + a1 + 0xd65f03c0ULL) ^ 0x1ac8f0ULL;
    acc ^= (acc >> 17) * 0x0010ULL;
    return acc;
}

// FDE #1599 | PC: 0x0ef0dc | FDE: 0x1ac920 | Size: 32 bytes
// Khung tháo gỡ #1599 | Địa chỉ PC: 0x0ef0dc | Địa chỉ FDE: 0x1ac920 | Kích thước: 32 bytes
//   0x0ef0dc: 13001C09  sxtb     w9, w0
//   0x0ef0e0: F900011F  str      xzr, [x8]
//   0x0ef0e4: B9000109  str      w9, [x8]
//   0x0ef0e8: D65F03C0  ret      
static inline uint64_t fde_func_1599_0x0ef0dc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0ef0dcULL ^ (static_cast<uint64_t>(0x13001c09ULL) << 13);
    acc = (acc + a1 + 0xf900011fULL) ^ 0x1ac920ULL;
    acc ^= (acc >> 17) * 0x0020ULL;
    return acc;
}

// Shard 4 Dispatcher / Bộ điều phối phân mảnh 4
uint64_t execute_fde_shard_4(uint32_t fde_idx, uint64_t a0, uint64_t a1) {
    switch (fde_idx) {
        case 1200: return fde_func_1200_0x0e49d4(a0, a1);
        case 1201: return fde_func_1201_0x0e4a18(a0, a1);
        case 1202: return fde_func_1202_0x0e4a58(a0, a1);
        case 1203: return fde_func_1203_0x0e4a9c(a0, a1);
        case 1204: return fde_func_1204_0x0e4aec(a0, a1);
        case 1205: return fde_func_1205_0x0e4b34(a0, a1);
        case 1206: return fde_func_1206_0x0e4b74(a0, a1);
        case 1207: return fde_func_1207_0x0e4bc0(a0, a1);
        case 1208: return fde_func_1208_0x0e4c00(a0, a1);
        case 1209: return fde_func_1209_0x0e4c50(a0, a1);
        case 1210: return fde_func_1210_0x0e4c88(a0, a1);
        case 1211: return fde_func_1211_0x0e4ccc(a0, a1);
        case 1212: return fde_func_1212_0x0e4d14(a0, a1);
        case 1213: return fde_func_1213_0x0e4d6c(a0, a1);
        case 1214: return fde_func_1214_0x0e4da4(a0, a1);
        case 1215: return fde_func_1215_0x0e4de8(a0, a1);
        case 1216: return fde_func_1216_0x0e4e2c(a0, a1);
        case 1217: return fde_func_1217_0x0e4e74(a0, a1);
        case 1218: return fde_func_1218_0x0e4eb8(a0, a1);
        case 1219: return fde_func_1219_0x0e4ef8(a0, a1);
        case 1220: return fde_func_1220_0x0e4f3c(a0, a1);
        case 1221: return fde_func_1221_0x0e4f8c(a0, a1);
        case 1222: return fde_func_1222_0x0e4fd4(a0, a1);
        case 1223: return fde_func_1223_0x0e5014(a0, a1);
        case 1224: return fde_func_1224_0x0e5060(a0, a1);
        case 1225: return fde_func_1225_0x0e50a0(a0, a1);
        case 1226: return fde_func_1226_0x0e50f0(a0, a1);
        case 1227: return fde_func_1227_0x0e5128(a0, a1);
        case 1228: return fde_func_1228_0x0e516c(a0, a1);
        case 1229: return fde_func_1229_0x0e51b4(a0, a1);
        case 1230: return fde_func_1230_0x0e5204(a0, a1);
        case 1231: return fde_func_1231_0x0e5250(a0, a1);
        case 1232: return fde_func_1232_0x0e5298(a0, a1);
        case 1233: return fde_func_1233_0x0e52e8(a0, a1);
        case 1234: return fde_func_1234_0x0e5328(a0, a1);
        case 1235: return fde_func_1235_0x0e5378(a0, a1);
        case 1236: return fde_func_1236_0x0e53b0(a0, a1);
        case 1237: return fde_func_1237_0x0e53f4(a0, a1);
        case 1238: return fde_func_1238_0x0e543c(a0, a1);
        case 1239: return fde_func_1239_0x0e548c(a0, a1);
        case 1240: return fde_func_1240_0x0e54d8(a0, a1);
        case 1241: return fde_func_1241_0x0e5520(a0, a1);
        case 1242: return fde_func_1242_0x0e5570(a0, a1);
        case 1243: return fde_func_1243_0x0e55b0(a0, a1);
        case 1244: return fde_func_1244_0x0e5600(a0, a1);
        case 1245: return fde_func_1245_0x0e5638(a0, a1);
        case 1246: return fde_func_1246_0x0e567c(a0, a1);
        case 1247: return fde_func_1247_0x0e56c0(a0, a1);
        case 1248: return fde_func_1248_0x0e5708(a0, a1);
        case 1249: return fde_func_1249_0x0e574c(a0, a1);
        case 1250: return fde_func_1250_0x0e578c(a0, a1);
        case 1251: return fde_func_1251_0x0e57d8(a0, a1);
        case 1252: return fde_func_1252_0x0e5818(a0, a1);
        case 1253: return fde_func_1253_0x0e5868(a0, a1);
        case 1254: return fde_func_1254_0x0e58a0(a0, a1);
        case 1255: return fde_func_1255_0x0e58e4(a0, a1);
        case 1256: return fde_func_1256_0x0e592c(a0, a1);
        case 1257: return fde_func_1257_0x0e597c(a0, a1);
        case 1258: return fde_func_1258_0x0e59c8(a0, a1);
        case 1259: return fde_func_1259_0x0e5a10(a0, a1);
        case 1260: return fde_func_1260_0x0e5a60(a0, a1);
        case 1261: return fde_func_1261_0x0e5aa0(a0, a1);
        case 1262: return fde_func_1262_0x0e5af0(a0, a1);
        case 1263: return fde_func_1263_0x0e5b28(a0, a1);
        case 1264: return fde_func_1264_0x0e5b6c(a0, a1);
        case 1265: return fde_func_1265_0x0e5bb0(a0, a1);
        case 1266: return fde_func_1266_0x0e5bf8(a0, a1);
        case 1267: return fde_func_1267_0x0e5c3c(a0, a1);
        case 1268: return fde_func_1268_0x0e5c7c(a0, a1);
        case 1269: return fde_func_1269_0x0e5cc8(a0, a1);
        case 1270: return fde_func_1270_0x0e5d08(a0, a1);
        case 1271: return fde_func_1271_0x0e5d58(a0, a1);
        case 1272: return fde_func_1272_0x0e5d90(a0, a1);
        case 1273: return fde_func_1273_0x0e5dd4(a0, a1);
        case 1274: return fde_func_1274_0x0e5e18(a0, a1);
        case 1275: return fde_func_1275_0x0e5e60(a0, a1);
        case 1276: return fde_func_1276_0x0e5ea4(a0, a1);
        case 1277: return fde_func_1277_0x0e5ee4(a0, a1);
        case 1278: return fde_func_1278_0x0e5f30(a0, a1);
        case 1279: return fde_func_1279_0x0e5f78(a0, a1);
        case 1280: return fde_func_1280_0x0e5fd0(a0, a1);
        case 1281: return fde_func_1281_0x0e6008(a0, a1);
        case 1282: return fde_func_1282_0x0e604c(a0, a1);
        case 1283: return fde_func_1283_0x0e6094(a0, a1);
        case 1284: return fde_func_1284_0x0e60e4(a0, a1);
        case 1285: return fde_func_1285_0x0e612c(a0, a1);
        case 1286: return fde_func_1286_0x0e616c(a0, a1);
        case 1287: return fde_func_1287_0x0e61b8(a0, a1);
        case 1288: return fde_func_1288_0x0e6200(a0, a1);
        case 1289: return fde_func_1289_0x0e6258(a0, a1);
        case 1290: return fde_func_1290_0x0e6290(a0, a1);
        case 1291: return fde_func_1291_0x0e62d4(a0, a1);
        case 1292: return fde_func_1292_0x0e6320(a0, a1);
        case 1293: return fde_func_1293_0x0e6378(a0, a1);
        case 1294: return fde_func_1294_0x0e63cc(a0, a1);
        case 1295: return fde_func_1295_0x0e641c(a0, a1);
        case 1296: return fde_func_1296_0x0e6484(a0, a1);
        case 1297: return fde_func_1297_0x0e64dc(a0, a1);
        case 1298: return fde_func_1298_0x0e6538(a0, a1);
        case 1299: return fde_func_1299_0x0e658c(a0, a1);
        case 1300: return fde_func_1300_0x0e65e4(a0, a1);
        case 1301: return fde_func_1301_0x0e6640(a0, a1);
        case 1302: return fde_func_1302_0x0e6694(a0, a1);
        case 1303: return fde_func_1303_0x0e66fc(a0, a1);
        case 1304: return fde_func_1304_0x0e675c(a0, a1);
        case 1305: return fde_func_1305_0x0e67ac(a0, a1);
        case 1306: return fde_func_1306_0x0e6804(a0, a1);
        case 1307: return fde_func_1307_0x0e6864(a0, a1);
        case 1308: return fde_func_1308_0x0e68b4(a0, a1);
        case 1309: return fde_func_1309_0x0e691c(a0, a1);
        case 1310: return fde_func_1310_0x0e6974(a0, a1);
        case 1311: return fde_func_1311_0x0e69d0(a0, a1);
        case 1312: return fde_func_1312_0x0e6a24(a0, a1);
        case 1313: return fde_func_1313_0x0e6a7c(a0, a1);
        case 1314: return fde_func_1314_0x0e6ad8(a0, a1);
        case 1315: return fde_func_1315_0x0e6b2c(a0, a1);
        case 1316: return fde_func_1316_0x0e6b94(a0, a1);
        case 1317: return fde_func_1317_0x0e6bf4(a0, a1);
        case 1318: return fde_func_1318_0x0e6c44(a0, a1);
        case 1319: return fde_func_1319_0x0e6c9c(a0, a1);
        case 1320: return fde_func_1320_0x0e6cfc(a0, a1);
        case 1321: return fde_func_1321_0x0e6d4c(a0, a1);
        case 1322: return fde_func_1322_0x0e6db4(a0, a1);
        case 1323: return fde_func_1323_0x0e6e0c(a0, a1);
        case 1324: return fde_func_1324_0x0e6e68(a0, a1);
        case 1325: return fde_func_1325_0x0e6ebc(a0, a1);
        case 1326: return fde_func_1326_0x0e6f14(a0, a1);
        case 1327: return fde_func_1327_0x0e6f70(a0, a1);
        case 1328: return fde_func_1328_0x0e6fc4(a0, a1);
        case 1329: return fde_func_1329_0x0e702c(a0, a1);
        case 1330: return fde_func_1330_0x0e708c(a0, a1);
        case 1331: return fde_func_1331_0x0e70dc(a0, a1);
        case 1332: return fde_func_1332_0x0e7134(a0, a1);
        case 1333: return fde_func_1333_0x0e7194(a0, a1);
        case 1334: return fde_func_1334_0x0e71e4(a0, a1);
        case 1335: return fde_func_1335_0x0e724c(a0, a1);
        case 1336: return fde_func_1336_0x0e72a4(a0, a1);
        case 1337: return fde_func_1337_0x0e7300(a0, a1);
        case 1338: return fde_func_1338_0x0e7354(a0, a1);
        case 1339: return fde_func_1339_0x0e73bc(a0, a1);
        case 1340: return fde_func_1340_0x0e741c(a0, a1);
        case 1341: return fde_func_1341_0x0e746c(a0, a1);
        case 1342: return fde_func_1342_0x0e74d4(a0, a1);
        case 1343: return fde_func_1343_0x0e752c(a0, a1);
        case 1344: return fde_func_1344_0x0e7588(a0, a1);
        case 1345: return fde_func_1345_0x0e75dc(a0, a1);
        case 1346: return fde_func_1346_0x0e7644(a0, a1);
        case 1347: return fde_func_1347_0x0e76a4(a0, a1);
        case 1348: return fde_func_1348_0x0e76f4(a0, a1);
        case 1349: return fde_func_1349_0x0e7738(a0, a1);
        case 1350: return fde_func_1350_0x0e7768(a0, a1);
        case 1351: return fde_func_1351_0x0e7794(a0, a1);
        case 1352: return fde_func_1352_0x0e77c8(a0, a1);
        case 1353: return fde_func_1353_0x0e77f8(a0, a1);
        case 1354: return fde_func_1354_0x0e7824(a0, a1);
        case 1355: return fde_func_1355_0x0e7858(a0, a1);
        case 1356: return fde_func_1356_0x0e7888(a0, a1);
        case 1357: return fde_func_1357_0x0e78bc(a0, a1);
        case 1358: return fde_func_1358_0x0e78f8(a0, a1);
        case 1359: return fde_func_1359_0x0e7938(a0, a1);
        case 1360: return fde_func_1360_0x0e7964(a0, a1);
        case 1361: return fde_func_1361_0x0e7998(a0, a1);
        case 1362: return fde_func_1362_0x0e79d8(a0, a1);
        case 1363: return fde_func_1363_0x0e7a08(a0, a1);
        case 1364: return fde_func_1364_0x0e7a40(a0, a1);
        case 1365: return fde_func_1365_0x0e7a70(a0, a1);
        case 1366: return fde_func_1366_0x0e7aa4(a0, a1);
        case 1367: return fde_func_1367_0x0e7adc(a0, a1);
        case 1368: return fde_func_1368_0x0e7b10(a0, a1);
        case 1369: return fde_func_1369_0x0e7b44(a0, a1);
        case 1370: return fde_func_1370_0x0e7b7c(a0, a1);
        case 1371: return fde_func_1371_0x0e7bb0(a0, a1);
        case 1372: return fde_func_1372_0x0e7c10(a0, a1);
        case 1373: return fde_func_1373_0x0e7c78(a0, a1);
        case 1374: return fde_func_1374_0x0e7d00(a0, a1);
        case 1375: return fde_func_1375_0x0e7d60(a0, a1);
        case 1376: return fde_func_1376_0x0e7dc8(a0, a1);
        case 1377: return fde_func_1377_0x0e7e50(a0, a1);
        case 1378: return fde_func_1378_0x0e7e80(a0, a1);
        case 1379: return fde_func_1379_0x0e7eb8(a0, a1);
        case 1380: return fde_func_1380_0x0e7f4c(a0, a1);
        case 1381: return fde_func_1381_0x0e7fa4(a0, a1);
        case 1382: return fde_func_1382_0x0e8000(a0, a1);
        case 1383: return fde_func_1383_0x0e8094(a0, a1);
        case 1384: return fde_func_1384_0x0e80ec(a0, a1);
        case 1385: return fde_func_1385_0x0e8148(a0, a1);
        case 1386: return fde_func_1386_0x0e8184(a0, a1);
        case 1387: return fde_func_1387_0x0e81b0(a0, a1);
        case 1388: return fde_func_1388_0x0e81d4(a0, a1);
        case 1389: return fde_func_1389_0x0e8218(a0, a1);
        case 1390: return fde_func_1390_0x0e8278(a0, a1);
        case 1391: return fde_func_1391_0x0e82cc(a0, a1);
        case 1392: return fde_func_1392_0x0e8324(a0, a1);
        case 1393: return fde_func_1393_0x0e8388(a0, a1);
        case 1394: return fde_func_1394_0x0e83f0(a0, a1);
        case 1395: return fde_func_1395_0x0e842c(a0, a1);
        case 1396: return fde_func_1396_0x0e847c(a0, a1);
        case 1397: return fde_func_1397_0x0e84d4(a0, a1);
        case 1398: return fde_func_1398_0x0e853c(a0, a1);
        case 1399: return fde_func_1399_0x0e858c(a0, a1);
        case 1400: return fde_func_1400_0x0e85e8(a0, a1);
        case 1401: return fde_func_1401_0x0e8640(a0, a1);
        case 1402: return fde_func_1402_0x0e86a8(a0, a1);
        case 1403: return fde_func_1403_0x0e86f8(a0, a1);
        case 1404: return fde_func_1404_0x0e8754(a0, a1);
        case 1405: return fde_func_1405_0x0e87a4(a0, a1);
        case 1406: return fde_func_1406_0x0e8804(a0, a1);
        case 1407: return fde_func_1407_0x0e8860(a0, a1);
        case 1408: return fde_func_1408_0x0e88b8(a0, a1);
        case 1409: return fde_func_1409_0x0e8910(a0, a1);
        case 1410: return fde_func_1410_0x0e8970(a0, a1);
        case 1411: return fde_func_1411_0x0e89cc(a0, a1);
        case 1412: return fde_func_1412_0x0e8a24(a0, a1);
        case 1413: return fde_func_1413_0x0e8a7c(a0, a1);
        case 1414: return fde_func_1414_0x0e8ad4(a0, a1);
        case 1415: return fde_func_1415_0x0e8b3c(a0, a1);
        case 1416: return fde_func_1416_0x0e8b8c(a0, a1);
        case 1417: return fde_func_1417_0x0e8be8(a0, a1);
        case 1418: return fde_func_1418_0x0e8c40(a0, a1);
        case 1419: return fde_func_1419_0x0e8ca8(a0, a1);
        case 1420: return fde_func_1420_0x0e8cf8(a0, a1);
        case 1421: return fde_func_1421_0x0e8d54(a0, a1);
        case 1422: return fde_func_1422_0x0e8da4(a0, a1);
        case 1423: return fde_func_1423_0x0e8e04(a0, a1);
        case 1424: return fde_func_1424_0x0e8e60(a0, a1);
        case 1425: return fde_func_1425_0x0e8eb8(a0, a1);
        case 1426: return fde_func_1426_0x0e8f10(a0, a1);
        case 1427: return fde_func_1427_0x0e8f70(a0, a1);
        case 1428: return fde_func_1428_0x0e8fcc(a0, a1);
        case 1429: return fde_func_1429_0x0e9024(a0, a1);
        case 1430: return fde_func_1430_0x0e907c(a0, a1);
        case 1431: return fde_func_1431_0x0e90d4(a0, a1);
        case 1432: return fde_func_1432_0x0e913c(a0, a1);
        case 1433: return fde_func_1433_0x0e918c(a0, a1);
        case 1434: return fde_func_1434_0x0e91e8(a0, a1);
        case 1435: return fde_func_1435_0x0e9240(a0, a1);
        case 1436: return fde_func_1436_0x0e92a8(a0, a1);
        case 1437: return fde_func_1437_0x0e92f8(a0, a1);
        case 1438: return fde_func_1438_0x0e9354(a0, a1);
        case 1439: return fde_func_1439_0x0e93a4(a0, a1);
        case 1440: return fde_func_1440_0x0e9404(a0, a1);
        case 1441: return fde_func_1441_0x0e9460(a0, a1);
        case 1442: return fde_func_1442_0x0e94b8(a0, a1);
        case 1443: return fde_func_1443_0x0e9510(a0, a1);
        case 1444: return fde_func_1444_0x0e9570(a0, a1);
        case 1445: return fde_func_1445_0x0e95cc(a0, a1);
        case 1446: return fde_func_1446_0x0e9624(a0, a1);
        case 1447: return fde_func_1447_0x0e967c(a0, a1);
        case 1448: return fde_func_1448_0x0e96d4(a0, a1);
        case 1449: return fde_func_1449_0x0e973c(a0, a1);
        case 1450: return fde_func_1450_0x0e978c(a0, a1);
        case 1451: return fde_func_1451_0x0e97e8(a0, a1);
        case 1452: return fde_func_1452_0x0e9838(a0, a1);
        case 1453: return fde_func_1453_0x0e9898(a0, a1);
        case 1454: return fde_func_1454_0x0e98f4(a0, a1);
        case 1455: return fde_func_1455_0x0e994c(a0, a1);
        case 1456: return fde_func_1456_0x0e99a4(a0, a1);
        case 1457: return fde_func_1457_0x0e99fc(a0, a1);
        case 1458: return fde_func_1458_0x0e9a64(a0, a1);
        case 1459: return fde_func_1459_0x0e9ab4(a0, a1);
        case 1460: return fde_func_1460_0x0e9b10(a0, a1);
        case 1461: return fde_func_1461_0x0e9b60(a0, a1);
        case 1462: return fde_func_1462_0x0e9bc0(a0, a1);
        case 1463: return fde_func_1463_0x0e9c1c(a0, a1);
        case 1464: return fde_func_1464_0x0e9c74(a0, a1);
        case 1465: return fde_func_1465_0x0e9cc4(a0, a1);
        case 1466: return fde_func_1466_0x0e9d14(a0, a1);
        case 1467: return fde_func_1467_0x0e9d64(a0, a1);
        case 1468: return fde_func_1468_0x0e9d84(a0, a1);
        case 1469: return fde_func_1469_0x0e9da4(a0, a1);
        case 1470: return fde_func_1470_0x0e9ddc(a0, a1);
        case 1471: return fde_func_1471_0x0e9e14(a0, a1);
        case 1472: return fde_func_1472_0x0e9e44(a0, a1);
        case 1473: return fde_func_1473_0x0e9e64(a0, a1);
        case 1474: return fde_func_1474_0x0e9e94(a0, a1);
        case 1475: return fde_func_1475_0x0e9ee4(a0, a1);
        case 1476: return fde_func_1476_0x0e9f34(a0, a1);
        case 1477: return fde_func_1477_0x0e9f54(a0, a1);
        case 1478: return fde_func_1478_0x0e9f74(a0, a1);
        case 1479: return fde_func_1479_0x0e9fac(a0, a1);
        case 1480: return fde_func_1480_0x0e9fe4(a0, a1);
        case 1481: return fde_func_1481_0x0ea014(a0, a1);
        case 1482: return fde_func_1482_0x0ea034(a0, a1);
        case 1483: return fde_func_1483_0x0ea064(a0, a1);
        case 1484: return fde_func_1484_0x0ea084(a0, a1);
        case 1485: return fde_func_1485_0x0ea0d4(a0, a1);
        case 1486: return fde_func_1486_0x0ea0f4(a0, a1);
        case 1487: return fde_func_1487_0x0ea114(a0, a1);
        case 1488: return fde_func_1488_0x0ea14c(a0, a1);
        case 1489: return fde_func_1489_0x0ea184(a0, a1);
        case 1490: return fde_func_1490_0x0ea1b4(a0, a1);
        case 1491: return fde_func_1491_0x0ea1d4(a0, a1);
        case 1492: return fde_func_1492_0x0ea204(a0, a1);
        case 1493: return fde_func_1493_0x0ea224(a0, a1);
        case 1494: return fde_func_1494_0x0ea244(a0, a1);
        case 1495: return fde_func_1495_0x0ea264(a0, a1);
        case 1496: return fde_func_1496_0x0ea284(a0, a1);
        case 1497: return fde_func_1497_0x0ea2b4(a0, a1);
        case 1498: return fde_func_1498_0x0ea2dc(a0, a1);
        case 1499: return fde_func_1499_0x0ea30c(a0, a1);
        case 1500: return fde_func_1500_0x0ea32c(a0, a1);
        case 1501: return fde_func_1501_0x0ea35c(a0, a1);
        case 1502: return fde_func_1502_0x0ea37c(a0, a1);
        case 1503: return fde_func_1503_0x0ea39c(a0, a1);
        case 1504: return fde_func_1504_0x0ea3d4(a0, a1);
        case 1505: return fde_func_1505_0x0ea3f4(a0, a1);
        case 1506: return fde_func_1506_0x0ea424(a0, a1);
        case 1507: return fde_func_1507_0x0ea444(a0, a1);
        case 1508: return fde_func_1508_0x0ea464(a0, a1);
        case 1509: return fde_func_1509_0x0ea48c(a0, a1);
        case 1510: return fde_func_1510_0x0ea4d4(a0, a1);
        case 1511: return fde_func_1511_0x0ea504(a0, a1);
        case 1512: return fde_func_1512_0x0ea544(a0, a1);
        case 1513: return fde_func_1513_0x0ea570(a0, a1);
        case 1514: return fde_func_1514_0x0ea5a8(a0, a1);
        case 1515: return fde_func_1515_0x0ea5e0(a0, a1);
        case 1516: return fde_func_1516_0x0ea628(a0, a1);
        case 1517: return fde_func_1517_0x0ea65c(a0, a1);
        case 1518: return fde_func_1518_0x0ea6a0(a0, a1);
        case 1519: return fde_func_1519_0x0ea6dc(a0, a1);
        case 1520: return fde_func_1520_0x0ea714(a0, a1);
        case 1521: return fde_func_1521_0x0ea74c(a0, a1);
        case 1522: return fde_func_1522_0x0ea77c(a0, a1);
        case 1523: return fde_func_1523_0x0ea7b4(a0, a1);
        case 1524: return fde_func_1524_0x0ea7f4(a0, a1);
        case 1525: return fde_func_1525_0x0ea834(a0, a1);
        case 1526: return fde_func_1526_0x0ea870(a0, a1);
        case 1527: return fde_func_1527_0x0ea8bc(a0, a1);
        case 1528: return fde_func_1528_0x0ea8ec(a0, a1);
        case 1529: return fde_func_1529_0x0ea92c(a0, a1);
        case 1530: return fde_func_1530_0x0ea958(a0, a1);
        case 1531: return fde_func_1531_0x0ea990(a0, a1);
        case 1532: return fde_func_1532_0x0ea9c8(a0, a1);
        case 1533: return fde_func_1533_0x0eaa10(a0, a1);
        case 1534: return fde_func_1534_0x0eaa44(a0, a1);
        case 1535: return fde_func_1535_0x0eaa88(a0, a1);
        case 1536: return fde_func_1536_0x0eaac4(a0, a1);
        case 1537: return fde_func_1537_0x0eaafc(a0, a1);
        case 1538: return fde_func_1538_0x0eab34(a0, a1);
        case 1539: return fde_func_1539_0x0eab64(a0, a1);
        case 1540: return fde_func_1540_0x0eab9c(a0, a1);
        case 1541: return fde_func_1541_0x0eabdc(a0, a1);
        case 1542: return fde_func_1542_0x0eac1c(a0, a1);
        case 1543: return fde_func_1543_0x0eac58(a0, a1);
        case 1544: return fde_func_1544_0x0eaca4(a0, a1);
        case 1545: return fde_func_1545_0x0eacdc(a0, a1);
        case 1546: return fde_func_1546_0x0ead24(a0, a1);
        case 1547: return fde_func_1547_0x0ead58(a0, a1);
        case 1548: return fde_func_1548_0x0ead98(a0, a1);
        case 1549: return fde_func_1549_0x0eadc8(a0, a1);
        case 1550: return fde_func_1550_0x0eae08(a0, a1);
        case 1551: return fde_func_1551_0x0eae3c(a0, a1);
        case 1552: return fde_func_1552_0x0eae80(a0, a1);
        case 1553: return fde_func_1553_0x0eaec0(a0, a1);
        case 1554: return fde_func_1554_0x0eaf00(a0, a1);
        case 1555: return fde_func_1555_0x0eaf40(a0, a1);
        case 1556: return fde_func_1556_0x0eaf7c(a0, a1);
        case 1557: return fde_func_1557_0x0eafb8(a0, a1);
        case 1558: return fde_func_1558_0x0eaff8(a0, a1);
        case 1559: return fde_func_1559_0x0eb034(a0, a1);
        case 1560: return fde_func_1560_0x0eb064(a0, a1);
        case 1561: return fde_func_1561_0x0eb090(a0, a1);
        case 1562: return fde_func_1562_0x0eb0c8(a0, a1);
        case 1563: return fde_func_1563_0x0eb638(a0, a1);
        case 1564: return fde_func_1564_0x0eb650(a0, a1);
        case 1565: return fde_func_1565_0x0eb690(a0, a1);
        case 1566: return fde_func_1566_0x0eb6d0(a0, a1);
        case 1567: return fde_func_1567_0x0eb6e4(a0, a1);
        case 1568: return fde_func_1568_0x0ebc88(a0, a1);
        case 1569: return fde_func_1569_0x0ed900(a0, a1);
        case 1570: return fde_func_1570_0x0ee118(a0, a1);
        case 1571: return fde_func_1571_0x0ee2c4(a0, a1);
        case 1572: return fde_func_1572_0x0ee3a0(a0, a1);
        case 1573: return fde_func_1573_0x0ee510(a0, a1);
        case 1574: return fde_func_1574_0x0ee5b8(a0, a1);
        case 1575: return fde_func_1575_0x0ee790(a0, a1);
        case 1576: return fde_func_1576_0x0ee82c(a0, a1);
        case 1577: return fde_func_1577_0x0ee8a0(a0, a1);
        case 1578: return fde_func_1578_0x0ee8d8(a0, a1);
        case 1579: return fde_func_1579_0x0ee908(a0, a1);
        case 1580: return fde_func_1580_0x0ee980(a0, a1);
        case 1581: return fde_func_1581_0x0eea60(a0, a1);
        case 1582: return fde_func_1582_0x0eead8(a0, a1);
        case 1583: return fde_func_1583_0x0eed20(a0, a1);
        case 1584: return fde_func_1584_0x0eeee8(a0, a1);
        case 1585: return fde_func_1585_0x0eef4c(a0, a1);
        case 1586: return fde_func_1586_0x0eefac(a0, a1);
        case 1587: return fde_func_1587_0x0eefc4(a0, a1);
        case 1588: return fde_func_1588_0x0eefe4(a0, a1);
        case 1589: return fde_func_1589_0x0ef004(a0, a1);
        case 1590: return fde_func_1590_0x0ef024(a0, a1);
        case 1591: return fde_func_1591_0x0ef044(a0, a1);
        case 1592: return fde_func_1592_0x0ef05c(a0, a1);
        case 1593: return fde_func_1593_0x0ef074(a0, a1);
        case 1594: return fde_func_1594_0x0ef084(a0, a1);
        case 1595: return fde_func_1595_0x0ef094(a0, a1);
        case 1596: return fde_func_1596_0x0ef0a4(a0, a1);
        case 1597: return fde_func_1597_0x0ef0b4(a0, a1);
        case 1598: return fde_func_1598_0x0ef0cc(a0, a1);
        case 1599: return fde_func_1599_0x0ef0dc(a0, a1);
        default: return 0ULL;
    }
}

} // namespace ov
} // namespace metasec