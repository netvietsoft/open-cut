// ============================================================================
// Clean-Room C++17 AArch64 Complementary FDE Shard 2/5 for libpythonA_RelWithDebInfo.so
// Phân mảnh Khung Tháo Gỡ (FDE) Bổ Sung AArch64 C++17 sạch 2/5 cho libpythonA_RelWithDebInfo.so
// Covers FDE indices [2464 .. 2927] out of 4,320 total FDEs
// Bao phủ chỉ số FDE [2464 .. 2927] trên tổng số 4.320 FDE
// ============================================================================
#include "pythonA_rel_core.h"

// FDE #2464 | PC: 0x10c2e4 | FDE: 0x1e5d78 | Size: 144 bytes [_PyErr_Clear]
// Khung tháo gỡ #2464 | Địa chỉ PC: 0x10c2e4 | Địa chỉ FDE: 0x1e5d78 | Kích thước: 144 bytes
//   0x10c2e4: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x10c2e8: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x10c2ec: 910043FD  add      x29, sp, #0x10
//   0x10c2f0: AA0003E8  mov      x8, x0
static inline uint64_t fde_func_2464_0x10c2e4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x10c2e4ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1e5d78ULL;
    acc ^= (acc >> 17) * 0x0090ULL;
    return acc;
}

// FDE #2465 | PC: 0x10c374 | FDE: 0x1e5d98 | Size: 256 bytes
// Khung tháo gỡ #2465 | Địa chỉ PC: 0x10c374 | Địa chỉ FDE: 0x1e5d98 | Kích thước: 256 bytes
//   0x10c374: D10143FF  sub      sp, sp, #0x50
//   0x10c378: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x10c37c: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x10c380: A9047BFD  stp      x29, x30, [sp, #0x40]
static inline uint64_t fde_func_2465_0x10c374(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x10c374ULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xa90257f6ULL) ^ 0x1e5d98ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #2466 | PC: 0x10c518 | FDE: 0x1e5dc0 | Size: 44 bytes [PyErr_SetObject]
// Khung tháo gỡ #2466 | Địa chỉ PC: 0x10c518 | Địa chỉ FDE: 0x1e5dc0 | Kích thước: 44 bytes
//   0x10c518: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x10c51c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x10c520: 910043FD  add      x29, sp, #0x10
//   0x10c524: AA0103F3  mov      x19, x1
static inline uint64_t fde_func_2466_0x10c518(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x10c518ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1e5dc0ULL;
    acc ^= (acc >> 17) * 0x002cULL;
    return acc;
}

// FDE #2467 | PC: 0x10c544 | FDE: 0x1e5de0 | Size: 112 bytes [_PyErr_SetKeyError]
// Khung tháo gỡ #2467 | Địa chỉ PC: 0x10c544 | Địa chỉ FDE: 0x1e5de0 | Kích thước: 112 bytes
//   0x10c544: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x10c548: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x10c54c: 910043FD  add      x29, sp, #0x10
//   0x10c550: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_2467_0x10c544(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x10c544ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1e5de0ULL;
    acc ^= (acc >> 17) * 0x0070ULL;
    return acc;
}

// FDE #2468 | PC: 0x10c5b4 | FDE: 0x1e5e00 | Size: 8 bytes [_PyErr_SetNone]
// Khung tháo gỡ #2468 | Địa chỉ PC: 0x10c5b4 | Địa chỉ FDE: 0x1e5e00 | Kích thước: 8 bytes
//   0x10c5b4: AA1F03E2  mov      x2, xzr
//   0x10c5b8: 17FD41DA  b        #0x5cd20
static inline uint64_t fde_func_2468_0x10c5b4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x10c5b4ULL ^ (static_cast<uint64_t>(0xaa1f03e2ULL) << 13);
    acc = (acc + a1 + 0x17fd41daULL) ^ 0x1e5e00ULL;
    acc ^= (acc >> 17) * 0x0008ULL;
    return acc;
}

// FDE #2469 | PC: 0x10c5bc | FDE: 0x1e5e18 | Size: 40 bytes [PyErr_SetNone]
// Khung tháo gỡ #2469 | Địa chỉ PC: 0x10c5bc | Địa chỉ FDE: 0x1e5e18 | Kích thước: 40 bytes
//   0x10c5bc: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x10c5c0: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x10c5c4: 910043FD  add      x29, sp, #0x10
//   0x10c5c8: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_2469_0x10c5bc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x10c5bcULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1e5e18ULL;
    acc ^= (acc >> 17) * 0x0028ULL;
    return acc;
}

// FDE #2470 | PC: 0x10c5e4 | FDE: 0x1e5e38 | Size: 108 bytes [_PyErr_SetString]
// Khung tháo gỡ #2470 | Địa chỉ PC: 0x10c5e4 | Địa chỉ FDE: 0x1e5e38 | Kích thước: 108 bytes
//   0x10c5e4: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x10c5e8: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x10c5ec: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x10c5f0: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_2470_0x10c5e4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x10c5e4ULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1e5e38ULL;
    acc ^= (acc >> 17) * 0x006cULL;
    return acc;
}

// FDE #2471 | PC: 0x10c650 | FDE: 0x1e5e58 | Size: 116 bytes [PyErr_SetString]
// Khung tháo gỡ #2471 | Địa chỉ PC: 0x10c650 | Địa chỉ FDE: 0x1e5e58 | Kích thước: 116 bytes
//   0x10c650: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x10c654: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x10c658: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x10c65c: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_2471_0x10c650(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x10c650ULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1e5e58ULL;
    acc ^= (acc >> 17) * 0x0074ULL;
    return acc;
}

// FDE #2472 | PC: 0x10c6c4 | FDE: 0x1e5e78 | Size: 24 bytes [PyErr_Occurred]
// Khung tháo gỡ #2472 | Địa chỉ PC: 0x10c6c4 | Địa chỉ FDE: 0x1e5e78 | Kích thước: 24 bytes
//   0x10c6c4: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x10c6c8: 910003FD  mov      x29, sp
//   0x10c6cc: 97FD343D  bl       #0x597c0
//   0x10c6d0: F9402C00  ldr      x0, [x0, #0x58]
static inline uint64_t fde_func_2472_0x10c6c4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x10c6c4ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1e5e78ULL;
    acc ^= (acc >> 17) * 0x0018ULL;
    return acc;
}

// FDE #2473 | PC: 0x10c6dc | FDE: 0x1e5e98 | Size: 212 bytes [PyErr_GivenExceptionMatches]
// Khung tháo gỡ #2473 | Địa chỉ PC: 0x10c6dc | Địa chỉ FDE: 0x1e5e98 | Kích thước: 212 bytes
//   0x10c6dc: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x10c6e0: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x10c6e4: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x10c6e8: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_2473_0x10c6dc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x10c6dcULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1e5e98ULL;
    acc ^= (acc >> 17) * 0x00d4ULL;
    return acc;
}

// FDE #2474 | PC: 0x10c7b0 | FDE: 0x1e5eb8 | Size: 8 bytes [_PyErr_ExceptionMatches]
// Khung tháo gỡ #2474 | Địa chỉ PC: 0x10c7b0 | Địa chỉ FDE: 0x1e5eb8 | Kích thước: 8 bytes
//   0x10c7b0: F9402C00  ldr      x0, [x0, #0x58]
//   0x10c7b4: 17FD34FF  b        #0x59bb0
static inline uint64_t fde_func_2474_0x10c7b0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x10c7b0ULL ^ (static_cast<uint64_t>(0xf9402c00ULL) << 13);
    acc = (acc + a1 + 0x17fd34ffULL) ^ 0x1e5eb8ULL;
    acc ^= (acc >> 17) * 0x0008ULL;
    return acc;
}

// FDE #2475 | PC: 0x10c7b8 | FDE: 0x1e5ed0 | Size: 40 bytes [PyErr_ExceptionMatches]
// Khung tháo gỡ #2475 | Địa chỉ PC: 0x10c7b8 | Địa chỉ FDE: 0x1e5ed0 | Kích thước: 40 bytes
//   0x10c7b8: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x10c7bc: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x10c7c0: 910043FD  add      x29, sp, #0x10
//   0x10c7c4: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_2475_0x10c7b8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x10c7b8ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1e5ed0ULL;
    acc ^= (acc >> 17) * 0x0028ULL;
    return acc;
}

// FDE #2476 | PC: 0x10c7e0 | FDE: 0x1e5ef0 | Size: 256 bytes [_PyErr_NormalizeException]
// Khung tháo gỡ #2476 | Địa chỉ PC: 0x10c7e0 | Địa chỉ FDE: 0x1e5ef0 | Kích thước: 256 bytes
//   0x10c7e0: A9BA6FFC  stp      x28, x27, [sp, #-0x60]!
//   0x10c7e4: A90167FA  stp      x26, x25, [sp, #0x10]
//   0x10c7e8: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x10c7ec: A90357F6  stp      x22, x21, [sp, #0x30]
static inline uint64_t fde_func_2476_0x10c7e0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x10c7e0ULL ^ (static_cast<uint64_t>(0xa9ba6ffcULL) << 13);
    acc = (acc + a1 + 0xa90167faULL) ^ 0x1e5ef0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #2477 | PC: 0x10ca44 | FDE: 0x1e5f20 | Size: 36 bytes [_PyErr_Fetch]
// Khung tháo gỡ #2477 | Địa chỉ PC: 0x10ca44 | Địa chỉ FDE: 0x1e5f20 | Kích thước: 36 bytes
//   0x10ca44: F9402C08  ldr      x8, [x0, #0x58]
//   0x10ca48: F9000028  str      x8, [x1]
//   0x10ca4c: F9403008  ldr      x8, [x0, #0x60]
//   0x10ca50: F9000048  str      x8, [x2]
static inline uint64_t fde_func_2477_0x10ca44(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x10ca44ULL ^ (static_cast<uint64_t>(0xf9402c08ULL) << 13);
    acc = (acc + a1 + 0xf9000028ULL) ^ 0x1e5f20ULL;
    acc ^= (acc >> 17) * 0x0024ULL;
    return acc;
}

// FDE #2478 | PC: 0x10ca68 | FDE: 0x1e5f38 | Size: 60 bytes [PyErr_NormalizeException]
// Khung tháo gỡ #2478 | Địa chỉ PC: 0x10ca68 | Địa chỉ FDE: 0x1e5f38 | Kích thước: 60 bytes
//   0x10ca68: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x10ca6c: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x10ca70: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x10ca74: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_2478_0x10ca68(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x10ca68ULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1e5f38ULL;
    acc ^= (acc >> 17) * 0x003cULL;
    return acc;
}

// FDE #2479 | PC: 0x10caa4 | FDE: 0x1e5f58 | Size: 80 bytes [PyErr_Fetch]
// Khung tháo gỡ #2479 | Địa chỉ PC: 0x10caa4 | Địa chỉ FDE: 0x1e5f58 | Kích thước: 80 bytes
//   0x10caa4: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x10caa8: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x10caac: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x10cab0: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_2479_0x10caa4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x10caa4ULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1e5f58ULL;
    acc ^= (acc >> 17) * 0x0050ULL;
    return acc;
}

// FDE #2480 | PC: 0x10caf4 | FDE: 0x1e5f78 | Size: 148 bytes [PyErr_Clear]
// Khung tháo gỡ #2480 | Địa chỉ PC: 0x10caf4 | Địa chỉ FDE: 0x1e5f78 | Kích thước: 148 bytes
//   0x10caf4: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x10caf8: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x10cafc: 910043FD  add      x29, sp, #0x10
//   0x10cb00: 97FD3330  bl       #0x597c0
static inline uint64_t fde_func_2480_0x10caf4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x10caf4ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1e5f78ULL;
    acc ^= (acc >> 17) * 0x0094ULL;
    return acc;
}

// FDE #2481 | PC: 0x10cb88 | FDE: 0x1e5f98 | Size: 124 bytes [_PyErr_GetExcInfo]
// Khung tháo gỡ #2481 | Địa chỉ PC: 0x10cb88 | Địa chỉ FDE: 0x1e5f98 | Kích thước: 124 bytes
//   0x10cb88: F0000789  adrp     x9, #0x1ff000
//   0x10cb8c: F940480B  ldr      x11, [x0, #0x90]
//   0x10cb90: F945F129  ldr      x9, [x9, #0xbe0]
//   0x10cb94: 14000003  b        #0x10cba0
static inline uint64_t fde_func_2481_0x10cb88(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x10cb88ULL ^ (static_cast<uint64_t>(0xf0000789ULL) << 13);
    acc = (acc + a1 + 0xf940480bULL) ^ 0x1e5f98ULL;
    acc ^= (acc >> 17) * 0x007cULL;
    return acc;
}

// FDE #2482 | PC: 0x10cc04 | FDE: 0x1e5fb0 | Size: 168 bytes [PyErr_GetExcInfo]
// Khung tháo gỡ #2482 | Địa chỉ PC: 0x10cc04 | Địa chỉ FDE: 0x1e5fb0 | Kích thước: 168 bytes
//   0x10cc04: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x10cc08: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x10cc0c: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x10cc10: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_2482_0x10cc04(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x10cc04ULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1e5fb0ULL;
    acc ^= (acc >> 17) * 0x00a8ULL;
    return acc;
}

// FDE #2483 | PC: 0x10ccac | FDE: 0x1e5fd0 | Size: 184 bytes [PyErr_SetExcInfo]
// Khung tháo gỡ #2483 | Địa chỉ PC: 0x10ccac | Địa chỉ FDE: 0x1e5fd0 | Kích thước: 184 bytes
//   0x10ccac: F81C0FF7  str      x23, [sp, #-0x40]!
//   0x10ccb0: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x10ccb4: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x10ccb8: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_2483_0x10ccac(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x10ccacULL ^ (static_cast<uint64_t>(0xf81c0ff7ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x1e5fd0ULL;
    acc ^= (acc >> 17) * 0x00b8ULL;
    return acc;
}

// FDE #2484 | PC: 0x10cd64 | FDE: 0x1e5ff8 | Size: 256 bytes [_PyErr_ChainExceptions]
// Khung tháo gỡ #2484 | Địa chỉ PC: 0x10cd64 | Địa chỉ FDE: 0x1e5ff8 | Kích thước: 256 bytes
//   0x10cd64: D10183FF  sub      sp, sp, #0x60
//   0x10cd68: A90357F6  stp      x22, x21, [sp, #0x30]
//   0x10cd6c: A9044FF4  stp      x20, x19, [sp, #0x40]
//   0x10cd70: A9057BFD  stp      x29, x30, [sp, #0x50]
static inline uint64_t fde_func_2484_0x10cd64(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x10cd64ULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xa90357f6ULL) ^ 0x1e5ff8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #2485 | PC: 0x10cecc | FDE: 0x1e6020 | Size: 256 bytes [_PyErr_ChainStackItem]
// Khung tháo gỡ #2485 | Địa chỉ PC: 0x10cecc | Địa chỉ FDE: 0x1e6020 | Kích thước: 256 bytes
//   0x10cecc: D10183FF  sub      sp, sp, #0x60
//   0x10ced0: F9000BF9  str      x25, [sp, #0x10]
//   0x10ced4: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x10ced8: A90357F6  stp      x22, x21, [sp, #0x30]
static inline uint64_t fde_func_2485_0x10cecc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x10ceccULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xf9000bf9ULL) ^ 0x1e6020ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #2486 | PC: 0x10d008 | FDE: 0x1e6048 | Size: 152 bytes [_PyErr_FormatFromCauseTstate]
// Khung tháo gỡ #2486 | Địa chỉ PC: 0x10d008 | Địa chỉ FDE: 0x1e6048 | Kích thước: 152 bytes
//   0x10d008: D10483FF  sub      sp, sp, #0x120
//   0x10d00c: A9104FFC  stp      x28, x19, [sp, #0x100]
//   0x10d010: A9117BFD  stp      x29, x30, [sp, #0x110]
//   0x10d014: 910443FD  add      x29, sp, #0x110
static inline uint64_t fde_func_2486_0x10d008(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x10d008ULL ^ (static_cast<uint64_t>(0xd10483ffULL) << 13);
    acc = (acc + a1 + 0xa9104ffcULL) ^ 0x1e6048ULL;
    acc ^= (acc >> 17) * 0x0098ULL;
    return acc;
}

// FDE #2487 | PC: 0x10d0a0 | FDE: 0x1e6068 | Size: 256 bytes
// Khung tháo gỡ #2487 | Địa chỉ PC: 0x10d0a0 | Địa chỉ FDE: 0x1e6068 | Kích thước: 256 bytes
//   0x10d0a0: D10203FF  sub      sp, sp, #0x80
//   0x10d0a4: A9045FF8  stp      x24, x23, [sp, #0x40]
//   0x10d0a8: A90557F6  stp      x22, x21, [sp, #0x50]
//   0x10d0ac: A9064FF4  stp      x20, x19, [sp, #0x60]
static inline uint64_t fde_func_2487_0x10d0a0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x10d0a0ULL ^ (static_cast<uint64_t>(0xd10203ffULL) << 13);
    acc = (acc + a1 + 0xa9045ff8ULL) ^ 0x1e6068ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #2488 | PC: 0x10d1e0 | FDE: 0x1e6090 | Size: 188 bytes [_PyErr_FormatFromCause]
// Khung tháo gỡ #2488 | Địa chỉ PC: 0x10d1e0 | Địa chỉ FDE: 0x1e6090 | Kích thước: 188 bytes
//   0x10d1e0: D10503FF  sub      sp, sp, #0x140
//   0x10d1e4: F90083FC  str      x28, [sp, #0x100]
//   0x10d1e8: A91157F6  stp      x22, x21, [sp, #0x110]
//   0x10d1ec: A9124FF4  stp      x20, x19, [sp, #0x120]
static inline uint64_t fde_func_2488_0x10d1e0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x10d1e0ULL ^ (static_cast<uint64_t>(0xd10503ffULL) << 13);
    acc = (acc + a1 + 0xf90083fcULL) ^ 0x1e6090ULL;
    acc ^= (acc >> 17) * 0x00bcULL;
    return acc;
}

// FDE #2489 | PC: 0x10d29c | FDE: 0x1e60b8 | Size: 116 bytes [PyErr_BadArgument]
// Khung tháo gỡ #2489 | Địa chỉ PC: 0x10d29c | Địa chỉ FDE: 0x1e60b8 | Kích thước: 116 bytes
//   0x10d29c: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x10d2a0: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x10d2a4: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x10d2a8: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_2489_0x10d29c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x10d29cULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1e60b8ULL;
    acc ^= (acc >> 17) * 0x0074ULL;
    return acc;
}

// FDE #2490 | PC: 0x10d310 | FDE: 0x1e60d8 | Size: 68 bytes [_PyErr_NoMemory]
// Khung tháo gỡ #2490 | Địa chỉ PC: 0x10d310 | Địa chỉ FDE: 0x1e60d8 | Kích thước: 68 bytes
//   0x10d310: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x10d314: 910003FD  mov      x29, sp
//   0x10d318: D0000788  adrp     x8, #0x1ff000
//   0x10d31c: F9442508  ldr      x8, [x8, #0x848]
static inline uint64_t fde_func_2490_0x10d310(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x10d310ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1e60d8ULL;
    acc ^= (acc >> 17) * 0x0044ULL;
    return acc;
}

// FDE #2491 | PC: 0x10d354 | FDE: 0x1e60f8 | Size: 72 bytes [PyErr_NoMemory]
// Khung tháo gỡ #2491 | Địa chỉ PC: 0x10d354 | Địa chỉ FDE: 0x1e60f8 | Kích thước: 72 bytes
//   0x10d354: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x10d358: 910003FD  mov      x29, sp
//   0x10d35c: 97FD3119  bl       #0x597c0
//   0x10d360: D0000788  adrp     x8, #0x1ff000
static inline uint64_t fde_func_2491_0x10d354(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x10d354ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1e60f8ULL;
    acc ^= (acc >> 17) * 0x0048ULL;
    return acc;
}

// FDE #2492 | PC: 0x10d39c | FDE: 0x1e6118 | Size: 28 bytes [PyErr_SetFromErrnoWithFilenameObject]
// Khung tháo gỡ #2492 | Địa chỉ PC: 0x10d39c | Địa chỉ FDE: 0x1e6118 | Kích thước: 28 bytes
//   0x10d39c: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x10d3a0: 910003FD  mov      x29, sp
//   0x10d3a4: AA1F03E2  mov      x2, xzr
//   0x10d3a8: 97FD3A12  bl       #0x5bbf0
static inline uint64_t fde_func_2492_0x10d39c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x10d39cULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1e6118ULL;
    acc ^= (acc >> 17) * 0x001cULL;
    return acc;
}

// FDE #2493 | PC: 0x10d3b8 | FDE: 0x1e6138 | Size: 256 bytes [PyErr_SetFromErrnoWithFilenameObjects]
// Khung tháo gỡ #2493 | Địa chỉ PC: 0x10d3b8 | Địa chỉ FDE: 0x1e6138 | Kích thước: 256 bytes
//   0x10d3b8: A9BC5FF8  stp      x24, x23, [sp, #-0x40]!
//   0x10d3bc: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x10d3c0: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x10d3c4: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_2493_0x10d3b8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x10d3b8ULL ^ (static_cast<uint64_t>(0xa9bc5ff8ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x1e6138ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #2494 | PC: 0x10d51c | FDE: 0x1e6160 | Size: 108 bytes [PyErr_SetFromErrnoWithFilename]
// Khung tháo gỡ #2494 | Địa chỉ PC: 0x10d51c | Địa chỉ FDE: 0x1e6160 | Kích thước: 108 bytes
//   0x10d51c: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x10d520: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x10d524: 910043FD  add      x29, sp, #0x10
//   0x10d528: AA0003F4  mov      x20, x0
static inline uint64_t fde_func_2494_0x10d51c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x10d51cULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1e6160ULL;
    acc ^= (acc >> 17) * 0x006cULL;
    return acc;
}

// FDE #2495 | PC: 0x10d588 | FDE: 0x1e6180 | Size: 32 bytes [PyErr_SetFromErrno]
// Khung tháo gỡ #2495 | Địa chỉ PC: 0x10d588 | Địa chỉ FDE: 0x1e6180 | Kích thước: 32 bytes
//   0x10d588: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x10d58c: 910003FD  mov      x29, sp
//   0x10d590: AA1F03E1  mov      x1, xzr
//   0x10d594: AA1F03E2  mov      x2, xzr
static inline uint64_t fde_func_2495_0x10d588(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x10d588ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1e6180ULL;
    acc ^= (acc >> 17) * 0x0020ULL;
    return acc;
}

// FDE #2496 | PC: 0x10d5a8 | FDE: 0x1e61a0 | Size: 256 bytes [PyErr_SetImportErrorSubclass]
// Khung tháo gỡ #2496 | Địa chỉ PC: 0x10d5a8 | Địa chỉ FDE: 0x1e61a0 | Kích thước: 256 bytes
//   0x10d5a8: D10183FF  sub      sp, sp, #0x60
//   0x10d5ac: F9000BF9  str      x25, [sp, #0x10]
//   0x10d5b0: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x10d5b4: A90357F6  stp      x22, x21, [sp, #0x30]
static inline uint64_t fde_func_2496_0x10d5a8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x10d5a8ULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xf9000bf9ULL) ^ 0x1e61a0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #2497 | PC: 0x10d744 | FDE: 0x1e61c8 | Size: 52 bytes [PyErr_SetImportError]
// Khung tháo gỡ #2497 | Địa chỉ PC: 0x10d744 | Địa chỉ FDE: 0x1e61c8 | Kích thước: 52 bytes
//   0x10d744: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x10d748: 910003FD  mov      x29, sp
//   0x10d74c: D0000788  adrp     x8, #0x1ff000
//   0x10d750: F946E908  ldr      x8, [x8, #0xdd0]
static inline uint64_t fde_func_2497_0x10d744(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x10d744ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1e61c8ULL;
    acc ^= (acc >> 17) * 0x0034ULL;
    return acc;
}

// FDE #2498 | PC: 0x10d778 | FDE: 0x1e61e8 | Size: 96 bytes [_PyErr_BadInternalCall]
// Khung tháo gỡ #2498 | Địa chỉ PC: 0x10d778 | Địa chỉ FDE: 0x1e61e8 | Kích thước: 96 bytes
//   0x10d778: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x10d77c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x10d780: 910043FD  add      x29, sp, #0x10
//   0x10d784: 2A0103F3  mov      w19, w1
static inline uint64_t fde_func_2498_0x10d778(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x10d778ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1e61e8ULL;
    acc ^= (acc >> 17) * 0x0060ULL;
    return acc;
}

// FDE #2499 | PC: 0x10d7d8 | FDE: 0x1e6208 | Size: 124 bytes [PyErr_BadInternalCall]
// Khung tháo gỡ #2499 | Địa chỉ PC: 0x10d7d8 | Địa chỉ FDE: 0x1e6208 | Kích thước: 124 bytes
//   0x10d7d8: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x10d7dc: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x10d7e0: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x10d7e4: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_2499_0x10d7d8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x10d7d8ULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1e6208ULL;
    acc ^= (acc >> 17) * 0x007cULL;
    return acc;
}

// FDE #2500 | PC: 0x10d854 | FDE: 0x1e6228 | Size: 84 bytes [PyErr_FormatV]
// Khung tháo gỡ #2500 | Địa chỉ PC: 0x10d854 | Địa chỉ FDE: 0x1e6228 | Kích thước: 84 bytes
//   0x10d854: D10143FF  sub      sp, sp, #0x50
//   0x10d858: F90013F5  str      x21, [sp, #0x20]
//   0x10d85c: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x10d860: A9047BFD  stp      x29, x30, [sp, #0x40]
static inline uint64_t fde_func_2500_0x10d854(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x10d854ULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xf90013f5ULL) ^ 0x1e6228ULL;
    acc ^= (acc >> 17) * 0x0054ULL;
    return acc;
}

// FDE #2501 | PC: 0x10d8a8 | FDE: 0x1e6248 | Size: 256 bytes
// Khung tháo gỡ #2501 | Địa chỉ PC: 0x10d8a8 | Địa chỉ FDE: 0x1e6248 | Kích thước: 256 bytes
//   0x10d8a8: D10203FF  sub      sp, sp, #0x80
//   0x10d8ac: F9001BF9  str      x25, [sp, #0x30]
//   0x10d8b0: A9045FF8  stp      x24, x23, [sp, #0x40]
//   0x10d8b4: A90557F6  stp      x22, x21, [sp, #0x50]
static inline uint64_t fde_func_2501_0x10d8a8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x10d8a8ULL ^ (static_cast<uint64_t>(0xd10203ffULL) << 13);
    acc = (acc + a1 + 0xf9001bf9ULL) ^ 0x1e6248ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #2502 | PC: 0x10d9b4 | FDE: 0x1e6270 | Size: 188 bytes [PyErr_Format]
// Khung tháo gỡ #2502 | Địa chỉ PC: 0x10d9b4 | Địa chỉ FDE: 0x1e6270 | Kích thước: 188 bytes
//   0x10d9b4: D10503FF  sub      sp, sp, #0x140
//   0x10d9b8: F90083FC  str      x28, [sp, #0x100]
//   0x10d9bc: A91157F6  stp      x22, x21, [sp, #0x110]
//   0x10d9c0: A9124FF4  stp      x20, x19, [sp, #0x120]
static inline uint64_t fde_func_2502_0x10d9b4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x10d9b4ULL ^ (static_cast<uint64_t>(0xd10503ffULL) << 13);
    acc = (acc + a1 + 0xf90083fcULL) ^ 0x1e6270ULL;
    acc ^= (acc >> 17) * 0x00bcULL;
    return acc;
}

// FDE #2503 | PC: 0x10da70 | FDE: 0x1e6298 | Size: 256 bytes [PyErr_NewException]
// Khung tháo gỡ #2503 | Địa chỉ PC: 0x10da70 | Địa chỉ FDE: 0x1e6298 | Kích thước: 256 bytes
//   0x10da70: F81C0FF7  str      x23, [sp, #-0x40]!
//   0x10da74: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x10da78: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x10da7c: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_2503_0x10da70(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x10da70ULL ^ (static_cast<uint64_t>(0xf81c0ff7ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x1e6298ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #2504 | PC: 0x10dc4c | FDE: 0x1e62c0 | Size: 236 bytes [PyErr_NewExceptionWithDoc]
// Khung tháo gỡ #2504 | Địa chỉ PC: 0x10dc4c | Địa chỉ FDE: 0x1e62c0 | Kích thước: 236 bytes
//   0x10dc4c: A9BC5FF8  stp      x24, x23, [sp, #-0x40]!
//   0x10dc50: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x10dc54: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x10dc58: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_2504_0x10dc4c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x10dc4cULL ^ (static_cast<uint64_t>(0xa9bc5ff8ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x1e62c0ULL;
    acc ^= (acc >> 17) * 0x00ecULL;
    return acc;
}

// FDE #2505 | PC: 0x10dd38 | FDE: 0x1e62e8 | Size: 116 bytes [_PyErr_InitTypes]
// Khung tháo gỡ #2505 | Địa chỉ PC: 0x10dd38 | Địa chỉ FDE: 0x1e62e8 | Kích thước: 116 bytes
//   0x10dd38: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x10dd3c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x10dd40: 910043FD  add      x29, sp, #0x10
//   0x10dd44: F00008A9  adrp     x9, #0x224000
static inline uint64_t fde_func_2505_0x10dd38(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x10dd38ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1e62e8ULL;
    acc ^= (acc >> 17) * 0x0074ULL;
    return acc;
}

// FDE #2506 | PC: 0x10ddac | FDE: 0x1e6308 | Size: 192 bytes [_PyErr_WriteUnraisableDefaultHook]
// Khung tháo gỡ #2506 | Địa chỉ PC: 0x10ddac | Địa chỉ FDE: 0x1e6308 | Kích thước: 192 bytes
//   0x10ddac: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x10ddb0: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x10ddb4: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x10ddb8: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_2506_0x10ddac(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x10ddacULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1e6308ULL;
    acc ^= (acc >> 17) * 0x00c0ULL;
    return acc;
}

// FDE #2507 | PC: 0x10de6c | FDE: 0x1e6328 | Size: 256 bytes
// Khung tháo gỡ #2507 | Địa chỉ PC: 0x10de6c | Địa chỉ FDE: 0x1e6328 | Kích thước: 256 bytes
//   0x10de6c: D101C3FF  sub      sp, sp, #0x70
//   0x10de70: A9016FFC  stp      x28, x27, [sp, #0x10]
//   0x10de74: A90267FA  stp      x26, x25, [sp, #0x20]
//   0x10de78: A9035FF8  stp      x24, x23, [sp, #0x30]
static inline uint64_t fde_func_2507_0x10de6c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x10de6cULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xa9016ffcULL) ^ 0x1e6328ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #2508 | PC: 0x10e3e0 | FDE: 0x1e6358 | Size: 256 bytes [_PyErr_WriteUnraisableMsg]
// Khung tháo gỡ #2508 | Địa chỉ PC: 0x10e3e0 | Địa chỉ FDE: 0x1e6358 | Kích thước: 256 bytes
//   0x10e3e0: D10283FF  sub      sp, sp, #0xa0
//   0x10e3e4: A9046FFC  stp      x28, x27, [sp, #0x40]
//   0x10e3e8: A90567FA  stp      x26, x25, [sp, #0x50]
//   0x10e3ec: A9065FF8  stp      x24, x23, [sp, #0x60]
static inline uint64_t fde_func_2508_0x10e3e0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x10e3e0ULL ^ (static_cast<uint64_t>(0xd10283ffULL) << 13);
    acc = (acc + a1 + 0xa9046ffcULL) ^ 0x1e6358ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #2509 | PC: 0x10e980 | FDE: 0x1e6388 | Size: 12 bytes [PyErr_WriteUnraisable]
// Khung tháo gỡ #2509 | Địa chỉ PC: 0x10e980 | Địa chỉ FDE: 0x1e6388 | Kích thước: 12 bytes
//   0x10e980: AA0003E1  mov      x1, x0
//   0x10e984: AA1F03E0  mov      x0, xzr
//   0x10e988: 17FD326E  b        #0x5b340
static inline uint64_t fde_func_2509_0x10e980(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x10e980ULL ^ (static_cast<uint64_t>(0xaa0003e1ULL) << 13);
    acc = (acc + a1 + 0xaa1f03e0ULL) ^ 0x1e6388ULL;
    acc ^= (acc >> 17) * 0x000cULL;
    return acc;
}

// FDE #2510 | PC: 0x10e98c | FDE: 0x1e63a0 | Size: 8 bytes [PyErr_SyntaxLocation]
// Khung tháo gỡ #2510 | Địa chỉ PC: 0x10e98c | Địa chỉ FDE: 0x1e63a0 | Kích thước: 8 bytes
//   0x10e98c: 12800002  mov      w2, #-1
//   0x10e990: 17FD383C  b        #0x5ca80
static inline uint64_t fde_func_2510_0x10e98c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x10e98cULL ^ (static_cast<uint64_t>(0x12800002ULL) << 13);
    acc = (acc + a1 + 0x17fd383cULL) ^ 0x1e63a0ULL;
    acc ^= (acc >> 17) * 0x0008ULL;
    return acc;
}

// FDE #2511 | PC: 0x10e994 | FDE: 0x1e63b8 | Size: 256 bytes [PyErr_SyntaxLocationEx]
// Khung tháo gỡ #2511 | Địa chỉ PC: 0x10e994 | Địa chỉ FDE: 0x1e63b8 | Kích thước: 256 bytes
//   0x10e994: F81C0FF7  str      x23, [sp, #-0x40]!
//   0x10e998: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x10e99c: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x10e9a0: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_2511_0x10e994(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x10e994ULL ^ (static_cast<uint64_t>(0xf81c0ff7ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x1e63b8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #2512 | PC: 0x10eaa8 | FDE: 0x1e63e0 | Size: 12 bytes [PyErr_SyntaxLocationObject]
// Khung tháo gỡ #2512 | Địa chỉ PC: 0x10eaa8 | Địa chỉ FDE: 0x1e63e0 | Kích thước: 12 bytes
//   0x10eaa8: 12800004  mov      w4, #-1
//   0x10eaac: 2A0103E3  mov      w3, w1
//   0x10eab0: 14000001  b        #0x10eab4
static inline uint64_t fde_func_2512_0x10eaa8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x10eaa8ULL ^ (static_cast<uint64_t>(0x12800004ULL) << 13);
    acc = (acc + a1 + 0x2a0103e3ULL) ^ 0x1e63e0ULL;
    acc ^= (acc >> 17) * 0x000cULL;
    return acc;
}

// FDE #2513 | PC: 0x10eab4 | FDE: 0x1e63f8 | Size: 256 bytes
// Khung tháo gỡ #2513 | Địa chỉ PC: 0x10eab4 | Địa chỉ FDE: 0x1e63f8 | Kích thước: 256 bytes
//   0x10eab4: D10283FF  sub      sp, sp, #0xa0
//   0x10eab8: A9046FFC  stp      x28, x27, [sp, #0x40]
//   0x10eabc: A90567FA  stp      x26, x25, [sp, #0x50]
//   0x10eac0: A9065FF8  stp      x24, x23, [sp, #0x60]
static inline uint64_t fde_func_2513_0x10eab4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x10eab4ULL ^ (static_cast<uint64_t>(0xd10283ffULL) << 13);
    acc = (acc + a1 + 0xa9046ffcULL) ^ 0x1e63f8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #2514 | PC: 0x10f360 | FDE: 0x1e6428 | Size: 4 bytes [PyErr_RangedSyntaxLocationObject]
// Khung tháo gỡ #2514 | Địa chỉ PC: 0x10f360 | Địa chỉ FDE: 0x1e6428 | Kích thước: 4 bytes
//   0x10f360: 17FFFDD5  b        #0x10eab4
static inline uint64_t fde_func_2514_0x10f360(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x10f360ULL ^ (static_cast<uint64_t>(0x17fffdd5ULL) << 13);
    acc = (acc + a1 + 0xa9be4ff4ULL) ^ 0x1e6428ULL;
    acc ^= (acc >> 17) * 0x0004ULL;
    return acc;
}

// FDE #2515 | PC: 0x10f364 | FDE: 0x1e6440 | Size: 96 bytes [PyErr_ProgramText]
// Khung tháo gỡ #2515 | Địa chỉ PC: 0x10f364 | Địa chỉ FDE: 0x1e6440 | Kích thước: 96 bytes
//   0x10f364: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x10f368: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x10f36c: 910043FD  add      x29, sp, #0x10
//   0x10f370: B4000200  cbz      x0, #0x10f3b0
static inline uint64_t fde_func_2515_0x10f364(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x10f364ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1e6440ULL;
    acc ^= (acc >> 17) * 0x0060ULL;
    return acc;
}

// FDE #2516 | PC: 0x10f3c4 | FDE: 0x1e6460 | Size: 256 bytes [PyErr_ProgramTextObject]
// Khung tháo gỡ #2516 | Địa chỉ PC: 0x10f3c4 | Địa chỉ FDE: 0x1e6460 | Kích thước: 256 bytes
//   0x10f3c4: A9BC5FFC  stp      x28, x23, [sp, #-0x40]!
//   0x10f3c8: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x10f3cc: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x10f3d0: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_2516_0x10f3c4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x10f3c4ULL ^ (static_cast<uint64_t>(0xa9bc5ffcULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x1e6460ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #2517 | PC: 0x10f514 | FDE: 0x1e6488 | Size: 96 bytes [_BDPythonVM_PyErr_UnExpected]
// Khung tháo gỡ #2517 | Địa chỉ PC: 0x10f514 | Địa chỉ FDE: 0x1e6488 | Kích thước: 96 bytes
//   0x10f514: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x10f518: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x10f51c: 910043FD  add      x29, sp, #0x10
//   0x10f520: 2A0103F3  mov      w19, w1
static inline uint64_t fde_func_2517_0x10f514(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x10f514ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1e6488ULL;
    acc ^= (acc >> 17) * 0x0060ULL;
    return acc;
}

// FDE #2518 | PC: 0x10f574 | FDE: 0x1e64a8 | Size: 256 bytes [Py_FrozenMain]
// Khung tháo gỡ #2518 | Địa chỉ PC: 0x10f574 | Địa chỉ FDE: 0x1e64a8 | Kích thước: 256 bytes
//   0x10f574: A9BA6FFC  stp      x28, x27, [sp, #-0x60]!
//   0x10f578: A90167FA  stp      x26, x25, [sp, #0x10]
//   0x10f57c: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x10f580: A90357F6  stp      x22, x21, [sp, #0x30]
static inline uint64_t fde_func_2518_0x10f574(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x10f574ULL ^ (static_cast<uint64_t>(0xa9ba6ffcULL) << 13);
    acc = (acc + a1 + 0xa90167faULL) ^ 0x1e64a8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #2519 | PC: 0x10f94c | FDE: 0x1e64d8 | Size: 156 bytes [PyArg_Parse]
// Khung tháo gỡ #2519 | Địa chỉ PC: 0x10f94c | Địa chỉ FDE: 0x1e64d8 | Kích thước: 156 bytes
//   0x10f94c: D10403FF  sub      sp, sp, #0x100
//   0x10f950: F90073F3  str      x19, [sp, #0xe0]
//   0x10f954: A90F7BFD  stp      x29, x30, [sp, #0xf0]
//   0x10f958: 9103C3FD  add      x29, sp, #0xf0
static inline uint64_t fde_func_2519_0x10f94c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x10f94cULL ^ (static_cast<uint64_t>(0xd10403ffULL) << 13);
    acc = (acc + a1 + 0xf90073f3ULL) ^ 0x1e64d8ULL;
    acc ^= (acc >> 17) * 0x009cULL;
    return acc;
}

// FDE #2520 | PC: 0x10f9e8 | FDE: 0x1e64f8 | Size: 156 bytes [_PyArg_Parse_SizeT]
// Khung tháo gỡ #2520 | Địa chỉ PC: 0x10f9e8 | Địa chỉ FDE: 0x1e64f8 | Kích thước: 156 bytes
//   0x10f9e8: D10403FF  sub      sp, sp, #0x100
//   0x10f9ec: F90073F3  str      x19, [sp, #0xe0]
//   0x10f9f0: A90F7BFD  stp      x29, x30, [sp, #0xf0]
//   0x10f9f4: 9103C3FD  add      x29, sp, #0xf0
static inline uint64_t fde_func_2520_0x10f9e8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x10f9e8ULL ^ (static_cast<uint64_t>(0xd10403ffULL) << 13);
    acc = (acc + a1 + 0xf90073f3ULL) ^ 0x1e64f8ULL;
    acc ^= (acc >> 17) * 0x009cULL;
    return acc;
}

// FDE #2521 | PC: 0x10fa84 | FDE: 0x1e6518 | Size: 196 bytes [PyArg_ParseTuple]
// Khung tháo gỡ #2521 | Địa chỉ PC: 0x10fa84 | Địa chỉ FDE: 0x1e6518 | Kích thước: 196 bytes
//   0x10fa84: D10403FF  sub      sp, sp, #0x100
//   0x10fa88: F90073F3  str      x19, [sp, #0xe0]
//   0x10fa8c: A90F7BFD  stp      x29, x30, [sp, #0xf0]
//   0x10fa90: 9103C3FD  add      x29, sp, #0xf0
static inline uint64_t fde_func_2521_0x10fa84(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x10fa84ULL ^ (static_cast<uint64_t>(0xd10403ffULL) << 13);
    acc = (acc + a1 + 0xf90073f3ULL) ^ 0x1e6518ULL;
    acc ^= (acc >> 17) * 0x00c4ULL;
    return acc;
}

// FDE #2522 | PC: 0x10fb48 | FDE: 0x1e6538 | Size: 196 bytes [_PyArg_ParseTuple_SizeT]
// Khung tháo gỡ #2522 | Địa chỉ PC: 0x10fb48 | Địa chỉ FDE: 0x1e6538 | Kích thước: 196 bytes
//   0x10fb48: D10403FF  sub      sp, sp, #0x100
//   0x10fb4c: F90073F3  str      x19, [sp, #0xe0]
//   0x10fb50: A90F7BFD  stp      x29, x30, [sp, #0xf0]
//   0x10fb54: 9103C3FD  add      x29, sp, #0xf0
static inline uint64_t fde_func_2522_0x10fb48(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x10fb48ULL ^ (static_cast<uint64_t>(0xd10403ffULL) << 13);
    acc = (acc + a1 + 0xf90073f3ULL) ^ 0x1e6538ULL;
    acc ^= (acc >> 17) * 0x00c4ULL;
    return acc;
}

// FDE #2523 | PC: 0x10fc0c | FDE: 0x1e6558 | Size: 160 bytes [_PyArg_ParseStack]
// Khung tháo gỡ #2523 | Địa chỉ PC: 0x10fc0c | Địa chỉ FDE: 0x1e6558 | Kích thước: 160 bytes
//   0x10fc0c: D103C3FF  sub      sp, sp, #0xf0
//   0x10fc10: F9006BF3  str      x19, [sp, #0xd0]
//   0x10fc14: A90E7BFD  stp      x29, x30, [sp, #0xe0]
//   0x10fc18: 910383FD  add      x29, sp, #0xe0
static inline uint64_t fde_func_2523_0x10fc0c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x10fc0cULL ^ (static_cast<uint64_t>(0xd103c3ffULL) << 13);
    acc = (acc + a1 + 0xf9006bf3ULL) ^ 0x1e6558ULL;
    acc ^= (acc >> 17) * 0x00a0ULL;
    return acc;
}

// FDE #2524 | PC: 0x10fcac | FDE: 0x1e6578 | Size: 256 bytes
// Khung tháo gỡ #2524 | Địa chỉ PC: 0x10fcac | Địa chỉ FDE: 0x1e6578 | Kích thước: 256 bytes
//   0x10fcac: A9BA6FFC  stp      x28, x27, [sp, #-0x60]!
//   0x10fcb0: A90167FA  stp      x26, x25, [sp, #0x10]
//   0x10fcb4: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x10fcb8: A90357F6  stp      x22, x21, [sp, #0x30]
static inline uint64_t fde_func_2524_0x10fcac(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x10fcacULL ^ (static_cast<uint64_t>(0xa9ba6ffcULL) << 13);
    acc = (acc + a1 + 0xa90167faULL) ^ 0x1e6578ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #2525 | PC: 0x110290 | FDE: 0x1e65a8 | Size: 160 bytes [_PyArg_ParseStack_SizeT]
// Khung tháo gỡ #2525 | Địa chỉ PC: 0x110290 | Địa chỉ FDE: 0x1e65a8 | Kích thước: 160 bytes
//   0x110290: D103C3FF  sub      sp, sp, #0xf0
//   0x110294: F9006BF3  str      x19, [sp, #0xd0]
//   0x110298: A90E7BFD  stp      x29, x30, [sp, #0xe0]
//   0x11029c: 910383FD  add      x29, sp, #0xe0
static inline uint64_t fde_func_2525_0x110290(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x110290ULL ^ (static_cast<uint64_t>(0xd103c3ffULL) << 13);
    acc = (acc + a1 + 0xf9006bf3ULL) ^ 0x1e65a8ULL;
    acc ^= (acc >> 17) * 0x00a0ULL;
    return acc;
}

// FDE #2526 | PC: 0x110330 | FDE: 0x1e65c8 | Size: 140 bytes [PyArg_VaParse]
// Khung tháo gỡ #2526 | Địa chỉ PC: 0x110330 | Địa chỉ FDE: 0x1e65c8 | Kích thước: 140 bytes
//   0x110330: D10143FF  sub      sp, sp, #0x50
//   0x110334: F9001BF3  str      x19, [sp, #0x30]
//   0x110338: A9047BFD  stp      x29, x30, [sp, #0x40]
//   0x11033c: 910103FD  add      x29, sp, #0x40
static inline uint64_t fde_func_2526_0x110330(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x110330ULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xf9001bf3ULL) ^ 0x1e65c8ULL;
    acc ^= (acc >> 17) * 0x008cULL;
    return acc;
}

// FDE #2527 | PC: 0x1103bc | FDE: 0x1e65e8 | Size: 140 bytes [_PyArg_VaParse_SizeT]
// Khung tháo gỡ #2527 | Địa chỉ PC: 0x1103bc | Địa chỉ FDE: 0x1e65e8 | Kích thước: 140 bytes
//   0x1103bc: D10143FF  sub      sp, sp, #0x50
//   0x1103c0: F9001BF3  str      x19, [sp, #0x30]
//   0x1103c4: A9047BFD  stp      x29, x30, [sp, #0x40]
//   0x1103c8: 910103FD  add      x29, sp, #0x40
static inline uint64_t fde_func_2527_0x1103bc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1103bcULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xf9001bf3ULL) ^ 0x1e65e8ULL;
    acc ^= (acc >> 17) * 0x008cULL;
    return acc;
}

// FDE #2528 | PC: 0x110448 | FDE: 0x1e6608 | Size: 80 bytes [_PyArg_BadArgument]
// Khung tháo gỡ #2528 | Địa chỉ PC: 0x110448 | Địa chỉ FDE: 0x1e6608 | Kích thước: 80 bytes
//   0x110448: F0000768  adrp     x8, #0x1ff000
//   0x11044c: F9447908  ldr      x8, [x8, #0x8f0]
//   0x110450: F000076A  adrp     x10, #0x1ff000
//   0x110454: AA0203E4  mov      x4, x2
static inline uint64_t fde_func_2528_0x110448(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x110448ULL ^ (static_cast<uint64_t>(0xf0000768ULL) << 13);
    acc = (acc + a1 + 0xf9447908ULL) ^ 0x1e6608ULL;
    acc ^= (acc >> 17) * 0x0050ULL;
    return acc;
}

// FDE #2529 | PC: 0x110498 | FDE: 0x1e6620 | Size: 200 bytes [PyArg_ParseTupleAndKeywords]
// Khung tháo gỡ #2529 | Địa chỉ PC: 0x110498 | Địa chỉ FDE: 0x1e6620 | Kích thước: 200 bytes
//   0x110498: D103C3FF  sub      sp, sp, #0xf0
//   0x11049c: F9006BF3  str      x19, [sp, #0xd0]
//   0x1104a0: A90E7BFD  stp      x29, x30, [sp, #0xe0]
//   0x1104a4: 910383FD  add      x29, sp, #0xe0
static inline uint64_t fde_func_2529_0x110498(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x110498ULL ^ (static_cast<uint64_t>(0xd103c3ffULL) << 13);
    acc = (acc + a1 + 0xf9006bf3ULL) ^ 0x1e6620ULL;
    acc ^= (acc >> 17) * 0x00c8ULL;
    return acc;
}

// FDE #2530 | PC: 0x110560 | FDE: 0x1e6640 | Size: 256 bytes
// Khung tháo gỡ #2530 | Địa chỉ PC: 0x110560 | Địa chỉ FDE: 0x1e6640 | Kích thước: 256 bytes
//   0x110560: A9BA6FFC  stp      x28, x27, [sp, #-0x60]!
//   0x110564: A90167FA  stp      x26, x25, [sp, #0x10]
//   0x110568: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x11056c: A90357F6  stp      x22, x21, [sp, #0x30]
static inline uint64_t fde_func_2530_0x110560(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x110560ULL ^ (static_cast<uint64_t>(0xa9ba6ffcULL) << 13);
    acc = (acc + a1 + 0xa90167faULL) ^ 0x1e6640ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #2531 | PC: 0x111170 | FDE: 0x1e6670 | Size: 200 bytes [_PyArg_ParseTupleAndKeywords_SizeT]
// Khung tháo gỡ #2531 | Địa chỉ PC: 0x111170 | Địa chỉ FDE: 0x1e6670 | Kích thước: 200 bytes
//   0x111170: D103C3FF  sub      sp, sp, #0xf0
//   0x111174: F9006BF3  str      x19, [sp, #0xd0]
//   0x111178: A90E7BFD  stp      x29, x30, [sp, #0xe0]
//   0x11117c: 910383FD  add      x29, sp, #0xe0
static inline uint64_t fde_func_2531_0x111170(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x111170ULL ^ (static_cast<uint64_t>(0xd103c3ffULL) << 13);
    acc = (acc + a1 + 0xf9006bf3ULL) ^ 0x1e6670ULL;
    acc ^= (acc >> 17) * 0x00c8ULL;
    return acc;
}

// FDE #2532 | PC: 0x111238 | FDE: 0x1e6690 | Size: 148 bytes [PyArg_VaParseTupleAndKeywords]
// Khung tháo gỡ #2532 | Địa chỉ PC: 0x111238 | Địa chỉ FDE: 0x1e6690 | Kích thước: 148 bytes
//   0x111238: D10143FF  sub      sp, sp, #0x50
//   0x11123c: F9001BF3  str      x19, [sp, #0x30]
//   0x111240: A9047BFD  stp      x29, x30, [sp, #0x40]
//   0x111244: 910103FD  add      x29, sp, #0x40
static inline uint64_t fde_func_2532_0x111238(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x111238ULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xf9001bf3ULL) ^ 0x1e6690ULL;
    acc ^= (acc >> 17) * 0x0094ULL;
    return acc;
}

// FDE #2533 | PC: 0x1112cc | FDE: 0x1e66b0 | Size: 148 bytes [_PyArg_VaParseTupleAndKeywords_SizeT]
// Khung tháo gỡ #2533 | Địa chỉ PC: 0x1112cc | Địa chỉ FDE: 0x1e66b0 | Kích thước: 148 bytes
//   0x1112cc: D10143FF  sub      sp, sp, #0x50
//   0x1112d0: F9001BF3  str      x19, [sp, #0x30]
//   0x1112d4: A9047BFD  stp      x29, x30, [sp, #0x40]
//   0x1112d8: 910103FD  add      x29, sp, #0x40
static inline uint64_t fde_func_2533_0x1112cc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1112ccULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xf9001bf3ULL) ^ 0x1e66b0ULL;
    acc ^= (acc >> 17) * 0x0094ULL;
    return acc;
}

// FDE #2534 | PC: 0x111360 | FDE: 0x1e66d0 | Size: 220 bytes [_PyArg_ParseTupleAndKeywordsFast]
// Khung tháo gỡ #2534 | Địa chỉ PC: 0x111360 | Địa chỉ FDE: 0x1e66d0 | Kích thước: 220 bytes
//   0x111360: D103C3FF  sub      sp, sp, #0xf0
//   0x111364: F9006BF3  str      x19, [sp, #0xd0]
//   0x111368: A90E7BFD  stp      x29, x30, [sp, #0xe0]
//   0x11136c: 910383FD  add      x29, sp, #0xe0
static inline uint64_t fde_func_2534_0x111360(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x111360ULL ^ (static_cast<uint64_t>(0xd103c3ffULL) << 13);
    acc = (acc + a1 + 0xf9006bf3ULL) ^ 0x1e66d0ULL;
    acc ^= (acc >> 17) * 0x00dcULL;
    return acc;
}

// FDE #2535 | PC: 0x11143c | FDE: 0x1e66f0 | Size: 220 bytes [_PyArg_ParseTupleAndKeywordsFast_SizeT]
// Khung tháo gỡ #2535 | Địa chỉ PC: 0x11143c | Địa chỉ FDE: 0x1e66f0 | Kích thước: 220 bytes
//   0x11143c: D103C3FF  sub      sp, sp, #0xf0
//   0x111440: F9006BF3  str      x19, [sp, #0xd0]
//   0x111444: A90E7BFD  stp      x29, x30, [sp, #0xe0]
//   0x111448: 910383FD  add      x29, sp, #0xe0
static inline uint64_t fde_func_2535_0x11143c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x11143cULL ^ (static_cast<uint64_t>(0xd103c3ffULL) << 13);
    acc = (acc + a1 + 0xf9006bf3ULL) ^ 0x1e66f0ULL;
    acc ^= (acc >> 17) * 0x00dcULL;
    return acc;
}

// FDE #2536 | PC: 0x111518 | FDE: 0x1e6710 | Size: 152 bytes [_PyArg_ParseStackAndKeywords]
// Khung tháo gỡ #2536 | Địa chỉ PC: 0x111518 | Địa chỉ FDE: 0x1e6710 | Kích thước: 152 bytes
//   0x111518: D103C3FF  sub      sp, sp, #0xf0
//   0x11151c: F9006BF3  str      x19, [sp, #0xd0]
//   0x111520: A90E7BFD  stp      x29, x30, [sp, #0xe0]
//   0x111524: 910383FD  add      x29, sp, #0xe0
static inline uint64_t fde_func_2536_0x111518(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x111518ULL ^ (static_cast<uint64_t>(0xd103c3ffULL) << 13);
    acc = (acc + a1 + 0xf9006bf3ULL) ^ 0x1e6710ULL;
    acc ^= (acc >> 17) * 0x0098ULL;
    return acc;
}

// FDE #2537 | PC: 0x1115b0 | FDE: 0x1e6730 | Size: 256 bytes
// Khung tháo gỡ #2537 | Địa chỉ PC: 0x1115b0 | Địa chỉ FDE: 0x1e6730 | Kích thước: 256 bytes
//   0x1115b0: A9BA6FFC  stp      x28, x27, [sp, #-0x60]!
//   0x1115b4: A90167FA  stp      x26, x25, [sp, #0x10]
//   0x1115b8: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x1115bc: A90357F6  stp      x22, x21, [sp, #0x30]
static inline uint64_t fde_func_2537_0x1115b0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1115b0ULL ^ (static_cast<uint64_t>(0xa9ba6ffcULL) << 13);
    acc = (acc + a1 + 0xa90167faULL) ^ 0x1e6730ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #2538 | PC: 0x111e80 | FDE: 0x1e6760 | Size: 152 bytes [_PyArg_ParseStackAndKeywords_SizeT]
// Khung tháo gỡ #2538 | Địa chỉ PC: 0x111e80 | Địa chỉ FDE: 0x1e6760 | Kích thước: 152 bytes
//   0x111e80: D103C3FF  sub      sp, sp, #0xf0
//   0x111e84: F9006BF3  str      x19, [sp, #0xd0]
//   0x111e88: A90E7BFD  stp      x29, x30, [sp, #0xe0]
//   0x111e8c: 910383FD  add      x29, sp, #0xe0
static inline uint64_t fde_func_2538_0x111e80(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x111e80ULL ^ (static_cast<uint64_t>(0xd103c3ffULL) << 13);
    acc = (acc + a1 + 0xf9006bf3ULL) ^ 0x1e6760ULL;
    acc ^= (acc >> 17) * 0x0098ULL;
    return acc;
}

// FDE #2539 | PC: 0x111f18 | FDE: 0x1e6780 | Size: 160 bytes [_PyArg_VaParseTupleAndKeywordsFast]
// Khung tháo gỡ #2539 | Địa chỉ PC: 0x111f18 | Địa chỉ FDE: 0x1e6780 | Kích thước: 160 bytes
//   0x111f18: D10143FF  sub      sp, sp, #0x50
//   0x111f1c: F9001BF3  str      x19, [sp, #0x30]
//   0x111f20: A9047BFD  stp      x29, x30, [sp, #0x40]
//   0x111f24: 910103FD  add      x29, sp, #0x40
static inline uint64_t fde_func_2539_0x111f18(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x111f18ULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xf9001bf3ULL) ^ 0x1e6780ULL;
    acc ^= (acc >> 17) * 0x00a0ULL;
    return acc;
}

// FDE #2540 | PC: 0x111fb8 | FDE: 0x1e67a0 | Size: 160 bytes [_PyArg_VaParseTupleAndKeywordsFast_SizeT]
// Khung tháo gỡ #2540 | Địa chỉ PC: 0x111fb8 | Địa chỉ FDE: 0x1e67a0 | Kích thước: 160 bytes
//   0x111fb8: D10143FF  sub      sp, sp, #0x50
//   0x111fbc: F9001BF3  str      x19, [sp, #0x30]
//   0x111fc0: A9047BFD  stp      x29, x30, [sp, #0x40]
//   0x111fc4: 910103FD  add      x29, sp, #0x40
static inline uint64_t fde_func_2540_0x111fb8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x111fb8ULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xf9001bf3ULL) ^ 0x1e67a0ULL;
    acc ^= (acc >> 17) * 0x00a0ULL;
    return acc;
}

// FDE #2541 | PC: 0x112058 | FDE: 0x1e67c0 | Size: 96 bytes [PyArg_ValidateKeywordArguments]
// Khung tháo gỡ #2541 | Địa chỉ PC: 0x112058 | Địa chỉ FDE: 0x1e67c0 | Kích thước: 96 bytes
//   0x112058: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x11205c: 910003FD  mov      x29, sp
//   0x112060: F9400408  ldr      x8, [x0, #8]
//   0x112064: 3942AD08  ldrb     w8, [x8, #0xab]
static inline uint64_t fde_func_2541_0x112058(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x112058ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1e67c0ULL;
    acc ^= (acc >> 17) * 0x0060ULL;
    return acc;
}

// FDE #2542 | PC: 0x1120b8 | FDE: 0x1e67e0 | Size: 256 bytes [_PyArg_UnpackKeywords]
// Khung tháo gỡ #2542 | Địa chỉ PC: 0x1120b8 | Địa chỉ FDE: 0x1e67e0 | Kích thước: 256 bytes
//   0x1120b8: D10343FF  sub      sp, sp, #0xd0
//   0x1120bc: A9076FFC  stp      x28, x27, [sp, #0x70]
//   0x1120c0: A90867FA  stp      x26, x25, [sp, #0x80]
//   0x1120c4: A9095FF8  stp      x24, x23, [sp, #0x90]
static inline uint64_t fde_func_2542_0x1120b8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1120b8ULL ^ (static_cast<uint64_t>(0xd10343ffULL) << 13);
    acc = (acc + a1 + 0xa9076ffcULL) ^ 0x1e67e0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #2543 | PC: 0x112798 | FDE: 0x1e6810 | Size: 256 bytes
// Khung tháo gỡ #2543 | Địa chỉ PC: 0x112798 | Địa chỉ FDE: 0x1e6810 | Kích thước: 256 bytes
//   0x112798: D10203FF  sub      sp, sp, #0x80
//   0x11279c: A9026FFC  stp      x28, x27, [sp, #0x20]
//   0x1127a0: A90367FA  stp      x26, x25, [sp, #0x30]
//   0x1127a4: A9045FF8  stp      x24, x23, [sp, #0x40]
static inline uint64_t fde_func_2543_0x112798(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x112798ULL ^ (static_cast<uint64_t>(0xd10203ffULL) << 13);
    acc = (acc + a1 + 0xa9026ffcULL) ^ 0x1e6810ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #2544 | PC: 0x112b1c | FDE: 0x1e6840 | Size: 256 bytes [_PyArg_CheckPositional]
// Khung tháo gỡ #2544 | Địa chỉ PC: 0x112b1c | Địa chỉ FDE: 0x1e6840 | Kích thước: 256 bytes
//   0x112b1c: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x112b20: 910003FD  mov      x29, sp
//   0x112b24: AA0303E4  mov      x4, x3
//   0x112b28: AA0203E8  mov      x8, x2
static inline uint64_t fde_func_2544_0x112b1c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x112b1cULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1e6840ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #2545 | PC: 0x112c1c | FDE: 0x1e6860 | Size: 256 bytes [PyArg_UnpackTuple]
// Khung tháo gỡ #2545 | Địa chỉ PC: 0x112c1c | Địa chỉ FDE: 0x1e6860 | Kích thước: 256 bytes
//   0x112c1c: D10443FF  sub      sp, sp, #0x110
//   0x112c20: A90D5FFC  stp      x28, x23, [sp, #0xd0]
//   0x112c24: A90E57F6  stp      x22, x21, [sp, #0xe0]
//   0x112c28: A90F4FF4  stp      x20, x19, [sp, #0xf0]
static inline uint64_t fde_func_2545_0x112c1c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x112c1cULL ^ (static_cast<uint64_t>(0xd10443ffULL) << 13);
    acc = (acc + a1 + 0xa90d5ffcULL) ^ 0x1e6860ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #2546 | PC: 0x112d48 | FDE: 0x1e6888 | Size: 256 bytes [_PyArg_UnpackStack]
// Khung tháo gỡ #2546 | Địa chỉ PC: 0x112d48 | Địa chỉ FDE: 0x1e6888 | Kích thước: 256 bytes
//   0x112d48: D10403FF  sub      sp, sp, #0x100
//   0x112d4c: F90063F7  str      x23, [sp, #0xc0]
//   0x112d50: A90D57F6  stp      x22, x21, [sp, #0xd0]
//   0x112d54: A90E4FF4  stp      x20, x19, [sp, #0xe0]
static inline uint64_t fde_func_2546_0x112d48(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x112d48ULL ^ (static_cast<uint64_t>(0xd10403ffULL) << 13);
    acc = (acc + a1 + 0xf90063f7ULL) ^ 0x1e6888ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #2547 | PC: 0x112e48 | FDE: 0x1e68b0 | Size: 112 bytes [_PyArg_NoKeywords]
// Khung tháo gỡ #2547 | Địa chỉ PC: 0x112e48 | Địa chỉ FDE: 0x1e68b0 | Kích thước: 112 bytes
//   0x112e48: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x112e4c: 910003FD  mov      x29, sp
//   0x112e50: B40002E1  cbz      x1, #0x112eac
//   0x112e54: B0000769  adrp     x9, #0x1ff000
static inline uint64_t fde_func_2547_0x112e48(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x112e48ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1e68b0ULL;
    acc ^= (acc >> 17) * 0x0070ULL;
    return acc;
}

// FDE #2548 | PC: 0x112eb8 | FDE: 0x1e68d0 | Size: 112 bytes [_PyArg_NoPositional]
// Khung tháo gỡ #2548 | Địa chỉ PC: 0x112eb8 | Địa chỉ FDE: 0x1e68d0 | Kích thước: 112 bytes
//   0x112eb8: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x112ebc: 910003FD  mov      x29, sp
//   0x112ec0: B40002E1  cbz      x1, #0x112f1c
//   0x112ec4: B0000769  adrp     x9, #0x1ff000
static inline uint64_t fde_func_2548_0x112eb8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x112eb8ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1e68d0ULL;
    acc ^= (acc >> 17) * 0x0070ULL;
    return acc;
}

// FDE #2549 | PC: 0x112f28 | FDE: 0x1e68f0 | Size: 72 bytes [_PyArg_NoKwnames]
// Khung tháo gỡ #2549 | Địa chỉ PC: 0x112f28 | Địa chỉ FDE: 0x1e68f0 | Kích thước: 72 bytes
//   0x112f28: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x112f2c: 910003FD  mov      x29, sp
//   0x112f30: B40001A1  cbz      x1, #0x112f64
//   0x112f34: F9400828  ldr      x8, [x1, #0x10]
static inline uint64_t fde_func_2549_0x112f28(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x112f28ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1e68f0ULL;
    acc ^= (acc >> 17) * 0x0048ULL;
    return acc;
}

// FDE #2550 | PC: 0x112f70 | FDE: 0x1e6910 | Size: 4 bytes [_PyArg_Fini]
// Khung tháo gỡ #2550 | Địa chỉ PC: 0x112f70 | Địa chỉ FDE: 0x1e6910 | Kích thước: 4 bytes
//   0x112f70: D65F03C0  ret      
static inline uint64_t fde_func_2550_0x112f70(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x112f70ULL ^ (static_cast<uint64_t>(0xd65f03c0ULL) << 13);
    acc = (acc + a1 + 0xd103c3ffULL) ^ 0x1e6910ULL;
    acc ^= (acc >> 17) * 0x0004ULL;
    return acc;
}

// FDE #2551 | PC: 0x112f74 | FDE: 0x1e6928 | Size: 256 bytes
// Khung tháo gỡ #2551 | Địa chỉ PC: 0x112f74 | Địa chỉ FDE: 0x1e6928 | Kích thước: 256 bytes
//   0x112f74: D103C3FF  sub      sp, sp, #0xf0
//   0x112f78: 6D0823E9  stp      d9, d8, [sp, #0x80]
//   0x112f7c: A9096FFC  stp      x28, x27, [sp, #0x90]
//   0x112f80: A90A67FA  stp      x26, x25, [sp, #0xa0]
static inline uint64_t fde_func_2551_0x112f74(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x112f74ULL ^ (static_cast<uint64_t>(0xd103c3ffULL) << 13);
    acc = (acc + a1 + 0x6d0823e9ULL) ^ 0x1e6928ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #2552 | PC: 0x114c34 | FDE: 0x1e6960 | Size: 256 bytes
// Khung tháo gỡ #2552 | Địa chỉ PC: 0x114c34 | Địa chỉ FDE: 0x1e6960 | Kích thước: 256 bytes
//   0x114c34: F81A0FFC  str      x28, [sp, #-0x60]!
//   0x114c38: A90167FA  stp      x26, x25, [sp, #0x10]
//   0x114c3c: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x114c40: A90357F6  stp      x22, x21, [sp, #0x30]
static inline uint64_t fde_func_2552_0x114c34(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x114c34ULL ^ (static_cast<uint64_t>(0xf81a0ffcULL) << 13);
    acc = (acc + a1 + 0xa90167faULL) ^ 0x1e6960ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #2553 | PC: 0x114dd4 | FDE: 0x1e6990 | Size: 32 bytes
// Khung tháo gỡ #2553 | Địa chỉ PC: 0x114dd4 | Địa chỉ FDE: 0x1e6990 | Kích thước: 32 bytes
//   0x114dd4: B40000C1  cbz      x1, #0x114dec
//   0x114dd8: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x114ddc: 910003FD  mov      x29, sp
//   0x114de0: AA0103E0  mov      x0, x1
static inline uint64_t fde_func_2553_0x114dd4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x114dd4ULL ^ (static_cast<uint64_t>(0xb40000c1ULL) << 13);
    acc = (acc + a1 + 0xa9bf7bfdULL) ^ 0x1e6990ULL;
    acc ^= (acc >> 17) * 0x0020ULL;
    return acc;
}

// FDE #2554 | PC: 0x114df4 | FDE: 0x1e69b0 | Size: 32 bytes
// Khung tháo gỡ #2554 | Địa chỉ PC: 0x114df4 | Địa chỉ FDE: 0x1e69b0 | Kích thước: 32 bytes
//   0x114df4: B40000C1  cbz      x1, #0x114e0c
//   0x114df8: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x114dfc: 910003FD  mov      x29, sp
//   0x114e00: AA0103E0  mov      x0, x1
static inline uint64_t fde_func_2554_0x114df4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x114df4ULL ^ (static_cast<uint64_t>(0xb40000c1ULL) << 13);
    acc = (acc + a1 + 0xa9bf7bfdULL) ^ 0x1e69b0ULL;
    acc ^= (acc >> 17) * 0x0020ULL;
    return acc;
}

// FDE #2555 | PC: 0x114e14 | FDE: 0x1e69d0 | Size: 256 bytes
// Khung tháo gỡ #2555 | Địa chỉ PC: 0x114e14 | Địa chỉ FDE: 0x1e69d0 | Kích thước: 256 bytes
//   0x114e14: D10103FF  sub      sp, sp, #0x40
//   0x114e18: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x114e1c: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x114e20: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_2555_0x114e14(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x114e14ULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x1e69d0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #2556 | PC: 0x1150ac | FDE: 0x1e69f8 | Size: 12 bytes [Py_GetCompiler]
// Khung tháo gỡ #2556 | Địa chỉ PC: 0x1150ac | Địa chỉ FDE: 0x1e69f8 | Kích thước: 12 bytes
//   0x1150ac: F0000500  adrp     x0, #0x1b8000
//   0x1150b0: 91146800  add      x0, x0, #0x51a
//   0x1150b4: D65F03C0  ret      
static inline uint64_t fde_func_2556_0x1150ac(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1150acULL ^ (static_cast<uint64_t>(0xf0000500ULL) << 13);
    acc = (acc + a1 + 0x91146800ULL) ^ 0x1e69f8ULL;
    acc ^= (acc >> 17) * 0x000cULL;
    return acc;
}

// FDE #2557 | PC: 0x1150b8 | FDE: 0x1e6a10 | Size: 12 bytes [Py_GetCopyright]
// Khung tháo gỡ #2557 | Địa chỉ PC: 0x1150b8 | Địa chỉ FDE: 0x1e6a10 | Kích thước: 12 bytes
//   0x1150b8: F0000500  adrp     x0, #0x1b8000
//   0x1150bc: 91162C00  add      x0, x0, #0x58b
//   0x1150c0: D65F03C0  ret      
static inline uint64_t fde_func_2557_0x1150b8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1150b8ULL ^ (static_cast<uint64_t>(0xf0000500ULL) << 13);
    acc = (acc + a1 + 0x91162c00ULL) ^ 0x1e6a10ULL;
    acc ^= (acc >> 17) * 0x000cULL;
    return acc;
}

// FDE #2558 | PC: 0x1150c4 | FDE: 0x1e6a28 | Size: 12 bytes [Py_GetPlatform]
// Khung tháo gỡ #2558 | Địa chỉ PC: 0x1150c4 | Địa chỉ FDE: 0x1e6a28 | Kích thước: 12 bytes
//   0x1150c4: D0000540  adrp     x0, #0x1bf000
//   0x1150c8: 910E4800  add      x0, x0, #0x392
//   0x1150cc: D65F03C0  ret      
static inline uint64_t fde_func_2558_0x1150c4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1150c4ULL ^ (static_cast<uint64_t>(0xd0000540ULL) << 13);
    acc = (acc + a1 + 0x910e4800ULL) ^ 0x1e6a28ULL;
    acc ^= (acc >> 17) * 0x000cULL;
    return acc;
}

// FDE #2559 | PC: 0x1150d0 | FDE: 0x1e6a40 | Size: 84 bytes [Py_GetVersion]
// Khung tháo gỡ #2559 | Địa chỉ PC: 0x1150d0 | Địa chỉ FDE: 0x1e6a40 | Kích thước: 84 bytes
//   0x1150d0: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x1150d4: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x1150d8: 910043FD  add      x29, sp, #0x10
//   0x1150dc: 97FD0CAD  bl       #0x58390
static inline uint64_t fde_func_2559_0x1150d0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1150d0ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1e6a40ULL;
    acc ^= (acc >> 17) * 0x0054ULL;
    return acc;
}

// FDE #2560 | PC: 0x115124 | FDE: 0x1e6a60 | Size: 4 bytes [_Py_hashtable_hash_ptr]
// Khung tháo gỡ #2560 | Địa chỉ PC: 0x115124 | Địa chỉ FDE: 0x1e6a60 | Kích thước: 4 bytes
//   0x115124: 17FD1F53  b        #0x5ce70
static inline uint64_t fde_func_2560_0x115124(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x115124ULL ^ (static_cast<uint64_t>(0x17fd1f53ULL) << 13);
    acc = (acc + a1 + 0xeb01001fULL) ^ 0x1e6a60ULL;
    acc ^= (acc >> 17) * 0x0004ULL;
    return acc;
}

// FDE #2561 | PC: 0x115128 | FDE: 0x1e6a78 | Size: 12 bytes [_Py_hashtable_compare_direct]
// Khung tháo gỡ #2561 | Địa chỉ PC: 0x115128 | Địa chỉ FDE: 0x1e6a78 | Kích thước: 12 bytes
//   0x115128: EB01001F  cmp      x0, x1
//   0x11512c: 1A9F17E0  cset     w0, eq
//   0x115130: D65F03C0  ret      
static inline uint64_t fde_func_2561_0x115128(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x115128ULL ^ (static_cast<uint64_t>(0xeb01001fULL) << 13);
    acc = (acc + a1 + 0x1a9f17e0ULL) ^ 0x1e6a78ULL;
    acc ^= (acc >> 17) * 0x000cULL;
    return acc;
}

// FDE #2562 | PC: 0x115134 | FDE: 0x1e6a90 | Size: 20 bytes [_Py_hashtable_size]
// Khung tháo gỡ #2562 | Địa chỉ PC: 0x115134 | Địa chỉ FDE: 0x1e6a90 | Kích thước: 20 bytes
//   0x115134: A9402009  ldp      x9, x8, [x0]
//   0x115138: D37DF108  lsl      x8, x8, #3
//   0x11513c: 8B091508  add      x8, x8, x9, lsl #5
//   0x115140: 91014100  add      x0, x8, #0x50
static inline uint64_t fde_func_2562_0x115134(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x115134ULL ^ (static_cast<uint64_t>(0xa9402009ULL) << 13);
    acc = (acc + a1 + 0xd37df108ULL) ^ 0x1e6a90ULL;
    acc ^= (acc >> 17) * 0x0014ULL;
    return acc;
}

// FDE #2563 | PC: 0x115148 | FDE: 0x1e6aa8 | Size: 124 bytes [_Py_hashtable_get_entry_generic]
// Khung tháo gỡ #2563 | Địa chỉ PC: 0x115148 | Địa chỉ FDE: 0x1e6aa8 | Kích thước: 124 bytes
//   0x115148: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x11514c: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x115150: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x115154: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_2563_0x115148(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x115148ULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1e6aa8ULL;
    acc ^= (acc >> 17) * 0x007cULL;
    return acc;
}

// FDE #2564 | PC: 0x1151c4 | FDE: 0x1e6ad0 | Size: 244 bytes [_Py_hashtable_steal]
// Khung tháo gỡ #2564 | Địa chỉ PC: 0x1151c4 | Địa chỉ FDE: 0x1e6ad0 | Kích thước: 244 bytes
//   0x1151c4: A9BC5FF8  stp      x24, x23, [sp, #-0x40]!
//   0x1151c8: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x1151cc: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x1151d0: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_2564_0x1151c4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1151c4ULL ^ (static_cast<uint64_t>(0xa9bc5ff8ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x1e6ad0ULL;
    acc ^= (acc >> 17) * 0x00f4ULL;
    return acc;
}

// FDE #2565 | PC: 0x1152b8 | FDE: 0x1e6af8 | Size: 256 bytes
// Khung tháo gỡ #2565 | Địa chỉ PC: 0x1152b8 | Địa chỉ FDE: 0x1e6af8 | Kích thước: 256 bytes
//   0x1152b8: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x1152bc: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x1152c0: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x1152c4: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_2565_0x1152b8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1152b8ULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1e6af8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #2566 | PC: 0x1153c8 | FDE: 0x1e6b20 | Size: 208 bytes [_Py_hashtable_set]
// Khung tháo gỡ #2566 | Địa chỉ PC: 0x1153c8 | Địa chỉ FDE: 0x1e6b20 | Kích thước: 208 bytes
//   0x1153c8: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x1153cc: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x1153d0: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x1153d4: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_2566_0x1153c8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1153c8ULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1e6b20ULL;
    acc ^= (acc >> 17) * 0x00d0ULL;
    return acc;
}

// FDE #2567 | PC: 0x115498 | FDE: 0x1e6b48 | Size: 32 bytes [_Py_hashtable_get]
// Khung tháo gỡ #2567 | Địa chỉ PC: 0x115498 | Địa chỉ FDE: 0x1e6b48 | Kích thước: 32 bytes
//   0x115498: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x11549c: 910003FD  mov      x29, sp
//   0x1154a0: F9400C08  ldr      x8, [x0, #0x18]
//   0x1154a4: D63F0100  blr      x8
static inline uint64_t fde_func_2567_0x115498(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x115498ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1e6b48ULL;
    acc ^= (acc >> 17) * 0x0020ULL;
    return acc;
}

// FDE #2568 | PC: 0x1154b8 | FDE: 0x1e6b68 | Size: 132 bytes [_Py_hashtable_foreach]
// Khung tháo gỡ #2568 | Địa chỉ PC: 0x1154b8 | Địa chỉ FDE: 0x1e6b68 | Kích thước: 132 bytes
//   0x1154b8: F81C0FF7  str      x23, [sp, #-0x40]!
//   0x1154bc: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x1154c0: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x1154c4: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_2568_0x1154b8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1154b8ULL ^ (static_cast<uint64_t>(0xf81c0ff7ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x1e6b68ULL;
    acc ^= (acc >> 17) * 0x0084ULL;
    return acc;
}

// FDE #2569 | PC: 0x11553c | FDE: 0x1e6b90 | Size: 244 bytes [_Py_hashtable_new_full]
// Khung tháo gỡ #2569 | Địa chỉ PC: 0x11553c | Địa chỉ FDE: 0x1e6b90 | Kích thước: 244 bytes
//   0x11553c: F81B0FF9  str      x25, [sp, #-0x50]!
//   0x115540: A9015FF8  stp      x24, x23, [sp, #0x10]
//   0x115544: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x115548: A9034FF4  stp      x20, x19, [sp, #0x30]
static inline uint64_t fde_func_2569_0x11553c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x11553cULL ^ (static_cast<uint64_t>(0xf81b0ff9ULL) << 13);
    acc = (acc + a1 + 0xa9015ff8ULL) ^ 0x1e6b90ULL;
    acc ^= (acc >> 17) * 0x00f4ULL;
    return acc;
}

// FDE #2570 | PC: 0x115630 | FDE: 0x1e6bb8 | Size: 80 bytes
// Khung tháo gỡ #2570 | Địa chỉ PC: 0x115630 | Địa chỉ FDE: 0x1e6bb8 | Kích thước: 80 bytes
//   0x115630: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x115634: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x115638: 910043FD  add      x29, sp, #0x10
//   0x11563c: AA0003F4  mov      x20, x0
static inline uint64_t fde_func_2570_0x115630(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x115630ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1e6bb8ULL;
    acc ^= (acc >> 17) * 0x0050ULL;
    return acc;
}

// FDE #2571 | PC: 0x115680 | FDE: 0x1e6bd8 | Size: 208 bytes [_Py_hashtable_new]
// Khung tháo gỡ #2571 | Địa chỉ PC: 0x115680 | Địa chỉ FDE: 0x1e6bd8 | Kích thước: 208 bytes
//   0x115680: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x115684: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x115688: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x11568c: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_2571_0x115680(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x115680ULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1e6bd8ULL;
    acc ^= (acc >> 17) * 0x00d0ULL;
    return acc;
}

// FDE #2572 | PC: 0x115750 | FDE: 0x1e6bf8 | Size: 164 bytes [_Py_hashtable_clear]
// Khung tháo gỡ #2572 | Địa chỉ PC: 0x115750 | Địa chỉ FDE: 0x1e6bf8 | Kích thước: 164 bytes
//   0x115750: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x115754: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x115758: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x11575c: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_2572_0x115750(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x115750ULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1e6bf8ULL;
    acc ^= (acc >> 17) * 0x00a4ULL;
    return acc;
}

// FDE #2573 | PC: 0x1157f4 | FDE: 0x1e6c20 | Size: 164 bytes [_Py_hashtable_destroy]
// Khung tháo gỡ #2573 | Địa chỉ PC: 0x1157f4 | Địa chỉ FDE: 0x1e6c20 | Kích thước: 164 bytes
//   0x1157f4: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x1157f8: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x1157fc: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x115800: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_2573_0x1157f4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1157f4ULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1e6c20ULL;
    acc ^= (acc >> 17) * 0x00a4ULL;
    return acc;
}

// FDE #2574 | PC: 0x115898 | FDE: 0x1e6c48 | Size: 28 bytes [get_import_state]
// Khung tháo gỡ #2574 | Địa chỉ PC: 0x115898 | Địa chỉ FDE: 0x1e6c48 | Kích thước: 28 bytes
//   0x115898: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x11589c: 910003FD  mov      x29, sp
//   0x1158a0: 97FD1C34  bl       #0x5c970
//   0x1158a4: 52869D08  mov      w8, #0x34e8
static inline uint64_t fde_func_2574_0x115898(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x115898ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1e6c48ULL;
    acc ^= (acc >> 17) * 0x001cULL;
    return acc;
}

// FDE #2575 | PC: 0x1158b4 | FDE: 0x1e6c68 | Size: 256 bytes [_PyImportZip_Init]
// Khung tháo gỡ #2575 | Địa chỉ PC: 0x1158b4 | Địa chỉ FDE: 0x1e6c68 | Kích thước: 256 bytes
//   0x1158b4: A9BC5FF8  stp      x24, x23, [sp, #-0x40]!
//   0x1158b8: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x1158bc: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x1158c0: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_2575_0x1158b4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1158b4ULL ^ (static_cast<uint64_t>(0xa9bc5ff8ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x1e6c68ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #2576 | PC: 0x115a8c | FDE: 0x1e6c90 | Size: 132 bytes [PyImport_ImportModule]
// Khung tháo gỡ #2576 | Địa chỉ PC: 0x115a8c | Địa chỉ FDE: 0x1e6c90 | Kích thước: 132 bytes
//   0x115a8c: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x115a90: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x115a94: 910043FD  add      x29, sp, #0x10
//   0x115a98: 97FD1A8A  bl       #0x5c4c0
static inline uint64_t fde_func_2576_0x115a8c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x115a8cULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1e6c90ULL;
    acc ^= (acc >> 17) * 0x0084ULL;
    return acc;
}

// FDE #2577 | PC: 0x115b10 | FDE: 0x1e6cb0 | Size: 164 bytes [_PyImport_AcquireLock]
// Khung tháo gỡ #2577 | Địa chỉ PC: 0x115b10 | Địa chỉ FDE: 0x1e6cb0 | Kích thước: 164 bytes
//   0x115b10: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x115b14: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x115b18: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x115b1c: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_2577_0x115b10(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x115b10ULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1e6cb0ULL;
    acc ^= (acc >> 17) * 0x00a4ULL;
    return acc;
}

// FDE #2578 | PC: 0x115bb4 | FDE: 0x1e6cd0 | Size: 116 bytes [_PyImport_ReleaseLock]
// Khung tháo gỡ #2578 | Địa chỉ PC: 0x115bb4 | Địa chỉ FDE: 0x1e6cd0 | Kích thước: 116 bytes
//   0x115bb4: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x115bb8: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x115bbc: 910043FD  add      x29, sp, #0x10
//   0x115bc0: 97FD1B6C  bl       #0x5c970
static inline uint64_t fde_func_2578_0x115bb4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x115bb4ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1e6cd0ULL;
    acc ^= (acc >> 17) * 0x0074ULL;
    return acc;
}

// FDE #2579 | PC: 0x115c28 | FDE: 0x1e6cf0 | Size: 184 bytes [_PyImport_ReInitLock]
// Khung tháo gỡ #2579 | Địa chỉ PC: 0x115c28 | Địa chỉ FDE: 0x1e6cf0 | Kích thước: 184 bytes
//   0x115c28: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x115c2c: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x115c30: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x115c34: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_2579_0x115c28(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x115c28ULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1e6cf0ULL;
    acc ^= (acc >> 17) * 0x00b8ULL;
    return acc;
}

// FDE #2580 | PC: 0x115ce0 | FDE: 0x1e6d10 | Size: 100 bytes [_PyImport_Fini]
// Khung tháo gỡ #2580 | Địa chỉ PC: 0x115ce0 | Địa chỉ FDE: 0x1e6d10 | Kích thước: 100 bytes
//   0x115ce0: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x115ce4: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x115ce8: 910043FD  add      x29, sp, #0x10
//   0x115cec: 97FD1B21  bl       #0x5c970
static inline uint64_t fde_func_2580_0x115ce0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x115ce0ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1e6d10ULL;
    acc ^= (acc >> 17) * 0x0064ULL;
    return acc;
}

// FDE #2581 | PC: 0x115d44 | FDE: 0x1e6d30 | Size: 124 bytes [_PyImport_Fini2]
// Khung tháo gỡ #2581 | Địa chỉ PC: 0x115d44 | Địa chỉ FDE: 0x1e6d30 | Kích thước: 124 bytes
//   0x115d44: D10143FF  sub      sp, sp, #0x50
//   0x115d48: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x115d4c: A9047BFD  stp      x29, x30, [sp, #0x40]
//   0x115d50: 910103FD  add      x29, sp, #0x40
static inline uint64_t fde_func_2581_0x115d44(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x115d44ULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xa9034ff4ULL) ^ 0x1e6d30ULL;
    acc ^= (acc >> 17) * 0x007cULL;
    return acc;
}

// FDE #2582 | PC: 0x115dc0 | FDE: 0x1e6d50 | Size: 64 bytes [PyImport_GetModuleDict]
// Khung tháo gỡ #2582 | Địa chỉ PC: 0x115dc0 | Địa chỉ FDE: 0x1e6d50 | Kích thước: 64 bytes
//   0x115dc0: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x115dc4: 910003FD  mov      x29, sp
//   0x115dc8: D0000748  adrp     x8, #0x1ff000
//   0x115dcc: F943B908  ldr      x8, [x8, #0x770]
static inline uint64_t fde_func_2582_0x115dc0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x115dc0ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1e6d50ULL;
    acc ^= (acc >> 17) * 0x0040ULL;
    return acc;
}

// FDE #2583 | PC: 0x115e00 | FDE: 0x1e6d70 | Size: 16 bytes [_PyImport_IsInitialized]
// Khung tháo gỡ #2583 | Địa chỉ PC: 0x115e00 | Địa chỉ FDE: 0x1e6d70 | Kích thước: 16 bytes
//   0x115e00: F9421408  ldr      x8, [x0, #0x428]
//   0x115e04: F100011F  cmp      x8, #0
//   0x115e08: 1A9F07E0  cset     w0, ne
//   0x115e0c: D65F03C0  ret      
static inline uint64_t fde_func_2583_0x115e00(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x115e00ULL ^ (static_cast<uint64_t>(0xf9421408ULL) << 13);
    acc = (acc + a1 + 0xf100011fULL) ^ 0x1e6d70ULL;
    acc ^= (acc >> 17) * 0x0010ULL;
    return acc;
}

// FDE #2584 | PC: 0x115e10 | FDE: 0x1e6d88 | Size: 32 bytes [_PyImport_GetModuleId]
// Khung tháo gỡ #2584 | Địa chỉ PC: 0x115e10 | Địa chỉ FDE: 0x1e6d88 | Kích thước: 32 bytes
//   0x115e10: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x115e14: 910003FD  mov      x29, sp
//   0x115e18: 97FD110A  bl       #0x5a240
//   0x115e1c: B4000060  cbz      x0, #0x115e28
static inline uint64_t fde_func_2584_0x115e10(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x115e10ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1e6d88ULL;
    acc ^= (acc >> 17) * 0x0020ULL;
    return acc;
}

// FDE #2585 | PC: 0x115e30 | FDE: 0x1e6da8 | Size: 256 bytes [PyImport_GetModule]
// Khung tháo gỡ #2585 | Địa chỉ PC: 0x115e30 | Địa chỉ FDE: 0x1e6da8 | Kích thước: 256 bytes
//   0x115e30: D101C3FF  sub      sp, sp, #0x70
//   0x115e34: F90013F9  str      x25, [sp, #0x20]
//   0x115e38: A9035FF8  stp      x24, x23, [sp, #0x30]
//   0x115e3c: A90457F6  stp      x22, x21, [sp, #0x40]
static inline uint64_t fde_func_2585_0x115e30(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x115e30ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xf90013f9ULL) ^ 0x1e6da8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #2586 | PC: 0x115f64 | FDE: 0x1e6dd0 | Size: 68 bytes [_PyImport_SetModule]
// Khung tháo gỡ #2586 | Địa chỉ PC: 0x115f64 | Địa chỉ FDE: 0x1e6dd0 | Kích thước: 68 bytes
//   0x115f64: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x115f68: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x115f6c: 910043FD  add      x29, sp, #0x10
//   0x115f70: D0000748  adrp     x8, #0x1ff000
static inline uint64_t fde_func_2586_0x115f64(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x115f64ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1e6dd0ULL;
    acc ^= (acc >> 17) * 0x0044ULL;
    return acc;
}

// FDE #2587 | PC: 0x115fa8 | FDE: 0x1e6df0 | Size: 68 bytes [_PyImport_SetModuleString]
// Khung tháo gỡ #2587 | Địa chỉ PC: 0x115fa8 | Địa chỉ FDE: 0x1e6df0 | Kích thước: 68 bytes
//   0x115fa8: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x115fac: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x115fb0: 910043FD  add      x29, sp, #0x10
//   0x115fb4: D0000748  adrp     x8, #0x1ff000
static inline uint64_t fde_func_2587_0x115fa8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x115fa8ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1e6df0ULL;
    acc ^= (acc >> 17) * 0x0044ULL;
    return acc;
}

// FDE #2588 | PC: 0x115fec | FDE: 0x1e6e10 | Size: 256 bytes [PyImport_GetMagicNumber]
// Khung tháo gỡ #2588 | Địa chỉ PC: 0x115fec | Địa chỉ FDE: 0x1e6e10 | Kích thước: 256 bytes
//   0x115fec: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x115ff0: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x115ff4: 910043FD  add      x29, sp, #0x10
//   0x115ff8: 10748048  adr      x8, #0x1ff000
static inline uint64_t fde_func_2588_0x115fec(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x115fecULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1e6e10ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #2589 | PC: 0x117090 | FDE: 0x1e6e30 | Size: 16 bytes [PyImport_GetMagicTag]
// Khung tháo gỡ #2589 | Địa chỉ PC: 0x117090 | Địa chỉ FDE: 0x1e6e30 | Kích thước: 16 bytes
//   0x117090: 90000748  adrp     x8, #0x1ff000
//   0x117094: F946D108  ldr      x8, [x8, #0xda0]
//   0x117098: F9400100  ldr      x0, [x8]
//   0x11709c: D65F03C0  ret      
static inline uint64_t fde_func_2589_0x117090(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x117090ULL ^ (static_cast<uint64_t>(0x90000748ULL) << 13);
    acc = (acc + a1 + 0xf946d108ULL) ^ 0x1e6e30ULL;
    acc ^= (acc >> 17) * 0x0010ULL;
    return acc;
}

// FDE #2590 | PC: 0x1170a0 | FDE: 0x1e6e48 | Size: 256 bytes [_PyImport_FixupExtensionObject]
// Khung tháo gỡ #2590 | Địa chỉ PC: 0x1170a0 | Địa chỉ FDE: 0x1e6e48 | Kích thước: 256 bytes
//   0x1170a0: A9BC5FF8  stp      x24, x23, [sp, #-0x40]!
//   0x1170a4: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x1170a8: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x1170ac: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_2590_0x1170a0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1170a0ULL ^ (static_cast<uint64_t>(0xa9bc5ff8ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x1e6e48ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #2591 | PC: 0x117240 | FDE: 0x1e6e70 | Size: 116 bytes [_PyImport_FixupBuiltin]
// Khung tháo gỡ #2591 | Địa chỉ PC: 0x117240 | Địa chỉ FDE: 0x1e6e70 | Kích thước: 116 bytes
//   0x117240: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x117244: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x117248: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x11724c: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_2591_0x117240(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x117240ULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1e6e70ULL;
    acc ^= (acc >> 17) * 0x0074ULL;
    return acc;
}

// FDE #2592 | PC: 0x1172b4 | FDE: 0x1e6e90 | Size: 144 bytes [PyImport_AddModuleObject]
// Khung tháo gỡ #2592 | Địa chỉ PC: 0x1172b4 | Địa chỉ FDE: 0x1e6e90 | Kích thước: 144 bytes
//   0x1172b4: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x1172b8: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x1172bc: 910043FD  add      x29, sp, #0x10
//   0x1172c0: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_2592_0x1172b4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1172b4ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1e6e90ULL;
    acc ^= (acc >> 17) * 0x0090ULL;
    return acc;
}

// FDE #2593 | PC: 0x117344 | FDE: 0x1e6eb0 | Size: 256 bytes
// Khung tháo gỡ #2593 | Địa chỉ PC: 0x117344 | Địa chỉ FDE: 0x1e6eb0 | Kích thước: 256 bytes
//   0x117344: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x117348: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x11734c: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x117350: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_2593_0x117344(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x117344ULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1e6eb0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #2594 | PC: 0x11748c | FDE: 0x1e6ed8 | Size: 80 bytes [PyImport_AddModule]
// Khung tháo gỡ #2594 | Địa chỉ PC: 0x11748c | Địa chỉ FDE: 0x1e6ed8 | Kích thước: 80 bytes
//   0x11748c: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x117490: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x117494: 910043FD  add      x29, sp, #0x10
//   0x117498: 97FD140A  bl       #0x5c4c0
static inline uint64_t fde_func_2594_0x11748c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x11748cULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1e6ed8ULL;
    acc ^= (acc >> 17) * 0x0050ULL;
    return acc;
}

// FDE #2595 | PC: 0x1174dc | FDE: 0x1e6ef8 | Size: 96 bytes [PyImport_ExecCodeModule]
// Khung tháo gỡ #2595 | Địa chỉ PC: 0x1174dc | Địa chỉ FDE: 0x1e6ef8 | Kích thước: 96 bytes
//   0x1174dc: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x1174e0: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x1174e4: 910043FD  add      x29, sp, #0x10
//   0x1174e8: AA0103F4  mov      x20, x1
static inline uint64_t fde_func_2595_0x1174dc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1174dcULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1e6ef8ULL;
    acc ^= (acc >> 17) * 0x0060ULL;
    return acc;
}

// FDE #2596 | PC: 0x11753c | FDE: 0x1e6f18 | Size: 256 bytes [PyImport_ExecCodeModuleWithPathnames]
// Khung tháo gỡ #2596 | Địa chỉ PC: 0x11753c | Địa chỉ FDE: 0x1e6f18 | Kích thước: 256 bytes
//   0x11753c: D10183FF  sub      sp, sp, #0x60
//   0x117540: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x117544: A90357F6  stp      x22, x21, [sp, #0x30]
//   0x117548: A9044FF4  stp      x20, x19, [sp, #0x40]
static inline uint64_t fde_func_2596_0x11753c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x11753cULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xa9025ff8ULL) ^ 0x1e6f18ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #2597 | PC: 0x1176f4 | FDE: 0x1e6f40 | Size: 8 bytes [PyImport_ExecCodeModuleEx]
// Khung tháo gỡ #2597 | Địa chỉ PC: 0x1176f4 | Địa chỉ FDE: 0x1e6f40 | Kích thước: 8 bytes
//   0x1176f4: AA1F03E3  mov      x3, xzr
//   0x1176f8: 17FD0712  b        #0x59340
static inline uint64_t fde_func_2597_0x1176f4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1176f4ULL ^ (static_cast<uint64_t>(0xaa1f03e3ULL) << 13);
    acc = (acc + a1 + 0x17fd0712ULL) ^ 0x1e6f40ULL;
    acc ^= (acc >> 17) * 0x0008ULL;
    return acc;
}

// FDE #2598 | PC: 0x1176fc | FDE: 0x1e6f58 | Size: 256 bytes [PyImport_ExecCodeModuleObject]
// Khung tháo gỡ #2598 | Địa chỉ PC: 0x1176fc | Địa chỉ FDE: 0x1e6f58 | Kích thước: 256 bytes
//   0x1176fc: F81B0FF9  str      x25, [sp, #-0x50]!
//   0x117700: A9015FF8  stp      x24, x23, [sp, #0x10]
//   0x117704: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x117708: A9034FF4  stp      x20, x19, [sp, #0x30]
static inline uint64_t fde_func_2598_0x1176fc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1176fcULL ^ (static_cast<uint64_t>(0xf81b0ff9ULL) << 13);
    acc = (acc + a1 + 0xa9015ff8ULL) ^ 0x1e6f58ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #2599 | PC: 0x117830 | FDE: 0x1e6f80 | Size: 192 bytes
// Khung tháo gỡ #2599 | Địa chỉ PC: 0x117830 | Địa chỉ FDE: 0x1e6f80 | Kích thước: 192 bytes
//   0x117830: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x117834: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x117838: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x11783c: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_2599_0x117830(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x117830ULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1e6f80ULL;
    acc ^= (acc >> 17) * 0x00c0ULL;
    return acc;
}

// FDE #2600 | PC: 0x1178f0 | FDE: 0x1e6fa8 | Size: 144 bytes
// Khung tháo gỡ #2600 | Địa chỉ PC: 0x1178f0 | Địa chỉ FDE: 0x1e6fa8 | Kích thước: 144 bytes
//   0x1178f0: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x1178f4: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x1178f8: 910043FD  add      x29, sp, #0x10
//   0x1178fc: AA0103F3  mov      x19, x1
static inline uint64_t fde_func_2600_0x1178f0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1178f0ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1e6fa8ULL;
    acc ^= (acc >> 17) * 0x0090ULL;
    return acc;
}

// FDE #2601 | PC: 0x117980 | FDE: 0x1e6fc8 | Size: 256 bytes [PyImport_GetImporter]
// Khung tháo gỡ #2601 | Địa chỉ PC: 0x117980 | Địa chỉ FDE: 0x1e6fc8 | Kích thước: 256 bytes
//   0x117980: D10203FF  sub      sp, sp, #0x80
//   0x117984: A9026FFC  stp      x28, x27, [sp, #0x20]
//   0x117988: A90367FA  stp      x26, x25, [sp, #0x30]
//   0x11798c: A9045FF8  stp      x24, x23, [sp, #0x40]
static inline uint64_t fde_func_2601_0x117980(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x117980ULL ^ (static_cast<uint64_t>(0xd10203ffULL) << 13);
    acc = (acc + a1 + 0xa9026ffcULL) ^ 0x1e6fc8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #2602 | PC: 0x117b7c | FDE: 0x1e6ff8 | Size: 256 bytes [PyImport_ImportFrozenModuleObject]
// Khung tháo gỡ #2602 | Địa chỉ PC: 0x117b7c | Địa chỉ FDE: 0x1e6ff8 | Kích thước: 256 bytes
//   0x117b7c: A9BC5FF8  stp      x24, x23, [sp, #-0x40]!
//   0x117b80: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x117b84: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x117b88: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_2602_0x117b7c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x117b7cULL ^ (static_cast<uint64_t>(0xa9bc5ff8ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x1e6ff8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #2603 | PC: 0x117dac | FDE: 0x1e7020 | Size: 80 bytes [PyImport_ImportFrozenModule]
// Khung tháo gỡ #2603 | Địa chỉ PC: 0x117dac | Địa chỉ FDE: 0x1e7020 | Kích thước: 80 bytes
//   0x117dac: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x117db0: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x117db4: 910043FD  add      x29, sp, #0x10
//   0x117db8: 97FD120E  bl       #0x5c5f0
static inline uint64_t fde_func_2603_0x117dac(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x117dacULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1e7020ULL;
    acc ^= (acc >> 17) * 0x0050ULL;
    return acc;
}

// FDE #2604 | PC: 0x117dfc | FDE: 0x1e7040 | Size: 92 bytes [PyImport_Import]
// Khung tháo gỡ #2604 | Địa chỉ PC: 0x117dfc | Địa chỉ FDE: 0x1e7040 | Kích thước: 92 bytes
//   0x117dfc: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x117e00: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x117e04: 910043FD  add      x29, sp, #0x10
//   0x117e08: 90000754  adrp     x20, #0x1ff000
static inline uint64_t fde_func_2604_0x117dfc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x117dfcULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1e7040ULL;
    acc ^= (acc >> 17) * 0x005cULL;
    return acc;
}

// FDE #2605 | PC: 0x117e58 | FDE: 0x1e7060 | Size: 132 bytes [PyImport_ImportModuleNoBlock]
// Khung tháo gỡ #2605 | Địa chỉ PC: 0x117e58 | Địa chỉ FDE: 0x1e7060 | Kích thước: 132 bytes
//   0x117e58: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x117e5c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x117e60: 910043FD  add      x29, sp, #0x10
//   0x117e64: 97FD1197  bl       #0x5c4c0
static inline uint64_t fde_func_2605_0x117e58(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x117e58ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1e7060ULL;
    acc ^= (acc >> 17) * 0x0084ULL;
    return acc;
}

// FDE #2606 | PC: 0x117edc | FDE: 0x1e7080 | Size: 220 bytes
// Khung tháo gỡ #2606 | Địa chỉ PC: 0x117edc | Địa chỉ FDE: 0x1e7080 | Kích thước: 220 bytes
//   0x117edc: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x117ee0: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x117ee4: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x117ee8: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_2606_0x117edc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x117edcULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1e7080ULL;
    acc ^= (acc >> 17) * 0x00dcULL;
    return acc;
}

// FDE #2607 | PC: 0x117fb8 | FDE: 0x1e70a0 | Size: 256 bytes
// Khung tháo gỡ #2607 | Địa chỉ PC: 0x117fb8 | Địa chỉ FDE: 0x1e70a0 | Kích thước: 256 bytes
//   0x117fb8: D10203FF  sub      sp, sp, #0x80
//   0x117fbc: A9026FFC  stp      x28, x27, [sp, #0x20]
//   0x117fc0: A90367FA  stp      x26, x25, [sp, #0x30]
//   0x117fc4: A9045FF8  stp      x24, x23, [sp, #0x40]
static inline uint64_t fde_func_2607_0x117fb8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x117fb8ULL ^ (static_cast<uint64_t>(0xd10203ffULL) << 13);
    acc = (acc + a1 + 0xa9026ffcULL) ^ 0x1e70a0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #2608 | PC: 0x118164 | FDE: 0x1e70d0 | Size: 256 bytes [PyImport_ImportModuleLevelObject]
// Khung tháo gỡ #2608 | Địa chỉ PC: 0x118164 | Địa chỉ FDE: 0x1e70d0 | Kích thước: 256 bytes
//   0x118164: D10243FF  sub      sp, sp, #0x90
//   0x118168: A9036FFC  stp      x28, x27, [sp, #0x30]
//   0x11816c: A90467FA  stp      x26, x25, [sp, #0x40]
//   0x118170: A9055FF8  stp      x24, x23, [sp, #0x50]
static inline uint64_t fde_func_2608_0x118164(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x118164ULL ^ (static_cast<uint64_t>(0xd10243ffULL) << 13);
    acc = (acc + a1 + 0xa9036ffcULL) ^ 0x1e70d0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #2609 | PC: 0x118aa8 | FDE: 0x1e7100 | Size: 112 bytes [PyImport_ImportModuleLevel]
// Khung tháo gỡ #2609 | Địa chỉ PC: 0x118aa8 | Địa chỉ FDE: 0x1e7100 | Kích thước: 112 bytes
//   0x118aa8: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x118aac: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x118ab0: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x118ab4: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_2609_0x118aa8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x118aa8ULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1e7100ULL;
    acc ^= (acc >> 17) * 0x0070ULL;
    return acc;
}

// FDE #2610 | PC: 0x118b18 | FDE: 0x1e7128 | Size: 256 bytes [PyImport_ReloadModule]
// Khung tháo gỡ #2610 | Địa chỉ PC: 0x118b18 | Địa chỉ FDE: 0x1e7128 | Kích thước: 256 bytes
//   0x118b18: D10143FF  sub      sp, sp, #0x50
//   0x118b1c: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x118b20: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x118b24: A9047BFD  stp      x29, x30, [sp, #0x40]
static inline uint64_t fde_func_2610_0x118b18(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x118b18ULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xa90257f6ULL) ^ 0x1e7128ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #2611 | PC: 0x118c58 | FDE: 0x1e7150 | Size: 256 bytes [_PyImport_Import]
// Khung tháo gỡ #2611 | Địa chỉ PC: 0x118c58 | Địa chỉ FDE: 0x1e7150 | Kích thước: 256 bytes
//   0x118c58: F81B0FF9  str      x25, [sp, #-0x50]!
//   0x118c5c: A9015FF8  stp      x24, x23, [sp, #0x10]
//   0x118c60: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x118c64: A9034FF4  stp      x20, x19, [sp, #0x30]
static inline uint64_t fde_func_2611_0x118c58(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x118c58ULL ^ (static_cast<uint64_t>(0xf81b0ff9ULL) << 13);
    acc = (acc + a1 + 0xa9015ff8ULL) ^ 0x1e7150ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #2612 | PC: 0x118eb4 | FDE: 0x1e7178 | Size: 12 bytes [PyInit__imp]
// Khung tháo gỡ #2612 | Địa chỉ PC: 0x118eb4 | Địa chỉ FDE: 0x1e7178 | Kích thước: 12 bytes
//   0x118eb4: F00007E0  adrp     x0, #0x217000
//   0x118eb8: 911E2000  add      x0, x0, #0x788
//   0x118ebc: 17FCFED9  b        #0x58a20
static inline uint64_t fde_func_2612_0x118eb4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x118eb4ULL ^ (static_cast<uint64_t>(0xf00007e0ULL) << 13);
    acc = (acc + a1 + 0x911e2000ULL) ^ 0x1e7178ULL;
    acc ^= (acc >> 17) * 0x000cULL;
    return acc;
}

// FDE #2613 | PC: 0x118ec0 | FDE: 0x1e7190 | Size: 256 bytes [_PyImport_BootstrapImp]
// Khung tháo gỡ #2613 | Địa chỉ PC: 0x118ec0 | Địa chỉ FDE: 0x1e7190 | Kích thước: 256 bytes
//   0x118ec0: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x118ec4: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x118ec8: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x118ecc: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_2613_0x118ec0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x118ec0ULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1e7190ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #2614 | PC: 0x119010 | FDE: 0x1e71b8 | Size: 256 bytes
// Khung tháo gỡ #2614 | Địa chỉ PC: 0x119010 | Địa chỉ FDE: 0x1e71b8 | Kích thước: 256 bytes
//   0x119010: F81C0FF7  str      x23, [sp, #-0x40]!
//   0x119014: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x119018: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x11901c: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_2614_0x119010(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x119010ULL ^ (static_cast<uint64_t>(0xf81c0ff7ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x1e71b8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #2615 | PC: 0x119150 | FDE: 0x1e71e0 | Size: 256 bytes [PyImport_ExtendInittab]
// Khung tháo gỡ #2615 | Địa chỉ PC: 0x119150 | Địa chỉ FDE: 0x1e71e0 | Kích thước: 256 bytes
//   0x119150: D10203FF  sub      sp, sp, #0x80
//   0x119154: F9001BF9  str      x25, [sp, #0x30]
//   0x119158: A9045FF8  stp      x24, x23, [sp, #0x40]
//   0x11915c: A90557F6  stp      x22, x21, [sp, #0x50]
static inline uint64_t fde_func_2615_0x119150(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x119150ULL ^ (static_cast<uint64_t>(0xd10203ffULL) << 13);
    acc = (acc + a1 + 0xf9001bf9ULL) ^ 0x1e71e0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #2616 | PC: 0x119284 | FDE: 0x1e7208 | Size: 80 bytes [PyImport_AppendInittab]
// Khung tháo gỡ #2616 | Địa chỉ PC: 0x119284 | Địa chỉ FDE: 0x1e7208 | Kích thước: 80 bytes
//   0x119284: D10143FF  sub      sp, sp, #0x50
//   0x119288: F9001BF3  str      x19, [sp, #0x30]
//   0x11928c: A9047BFD  stp      x29, x30, [sp, #0x40]
//   0x119290: 910103FD  add      x29, sp, #0x40
static inline uint64_t fde_func_2616_0x119284(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x119284ULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xf9001bf3ULL) ^ 0x1e7208ULL;
    acc ^= (acc >> 17) * 0x0050ULL;
    return acc;
}

// FDE #2617 | PC: 0x1192d4 | FDE: 0x1e7228 | Size: 256 bytes [BDPythonImportEncryptName]
// Khung tháo gỡ #2617 | Địa chỉ PC: 0x1192d4 | Địa chỉ FDE: 0x1e7228 | Kích thước: 256 bytes
//   0x1192d4: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x1192d8: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x1192dc: 910043FD  add      x29, sp, #0x10
//   0x1192e0: AA0103F4  mov      x20, x1
static inline uint64_t fde_func_2617_0x1192d4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1192d4ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1e7228ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #2618 | PC: 0x119424 | FDE: 0x1e7248 | Size: 224 bytes
// Khung tháo gỡ #2618 | Địa chỉ PC: 0x119424 | Địa chỉ FDE: 0x1e7248 | Kích thước: 224 bytes
//   0x119424: D10143FF  sub      sp, sp, #0x50
//   0x119428: F90013F5  str      x21, [sp, #0x20]
//   0x11942c: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x119430: A9047BFD  stp      x29, x30, [sp, #0x40]
static inline uint64_t fde_func_2618_0x119424(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x119424ULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xf90013f5ULL) ^ 0x1e7248ULL;
    acc ^= (acc >> 17) * 0x00e0ULL;
    return acc;
}

// FDE #2619 | PC: 0x119504 | FDE: 0x1e7268 | Size: 228 bytes
// Khung tháo gỡ #2619 | Địa chỉ PC: 0x119504 | Địa chỉ FDE: 0x1e7268 | Kích thước: 228 bytes
//   0x119504: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x119508: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x11950c: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x119510: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_2619_0x119504(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x119504ULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1e7268ULL;
    acc ^= (acc >> 17) * 0x00e4ULL;
    return acc;
}

// FDE #2620 | PC: 0x1195e8 | FDE: 0x1e7290 | Size: 32 bytes
// Khung tháo gỡ #2620 | Địa chỉ PC: 0x1195e8 | Địa chỉ FDE: 0x1e7290 | Kích thước: 32 bytes
//   0x1195e8: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x1195ec: 910003FD  mov      x29, sp
//   0x1195f0: 97FD0CE0  bl       #0x5c970
//   0x1195f4: F95A7808  ldr      x8, [x0, #0x34f0]
static inline uint64_t fde_func_2620_0x1195e8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1195e8ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1e7290ULL;
    acc ^= (acc >> 17) * 0x0020ULL;
    return acc;
}

// FDE #2621 | PC: 0x119608 | FDE: 0x1e72b0 | Size: 40 bytes
// Khung tháo gỡ #2621 | Địa chỉ PC: 0x119608 | Địa chỉ FDE: 0x1e72b0 | Kích thước: 40 bytes
//   0x119608: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x11960c: 910003FD  mov      x29, sp
//   0x119610: 97FD09DC  bl       #0x5bd80
//   0x119614: D0000720  adrp     x0, #0x1ff000
static inline uint64_t fde_func_2621_0x119608(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x119608ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1e72b0ULL;
    acc ^= (acc >> 17) * 0x0028ULL;
    return acc;
}

// FDE #2622 | PC: 0x119630 | FDE: 0x1e72d0 | Size: 148 bytes
// Khung tháo gỡ #2622 | Địa chỉ PC: 0x119630 | Địa chỉ FDE: 0x1e72d0 | Kích thước: 148 bytes
//   0x119630: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x119634: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x119638: 910043FD  add      x29, sp, #0x10
//   0x11963c: 97FD0CCD  bl       #0x5c970
static inline uint64_t fde_func_2622_0x119630(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x119630ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1e72d0ULL;
    acc ^= (acc >> 17) * 0x0094ULL;
    return acc;
}

// FDE #2623 | PC: 0x1196c4 | FDE: 0x1e72f0 | Size: 248 bytes
// Khung tháo gỡ #2623 | Địa chỉ PC: 0x1196c4 | Địa chỉ FDE: 0x1e72f0 | Kích thước: 248 bytes
//   0x1196c4: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x1196c8: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x1196cc: 910043FD  add      x29, sp, #0x10
//   0x1196d0: F9400428  ldr      x8, [x1, #8]
static inline uint64_t fde_func_2623_0x1196c4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1196c4ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1e72f0ULL;
    acc ^= (acc >> 17) * 0x00f8ULL;
    return acc;
}

// FDE #2624 | PC: 0x1197bc | FDE: 0x1e7310 | Size: 240 bytes
// Khung tháo gỡ #2624 | Địa chỉ PC: 0x1197bc | Địa chỉ FDE: 0x1e7310 | Kích thước: 240 bytes
//   0x1197bc: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x1197c0: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x1197c4: 910043FD  add      x29, sp, #0x10
//   0x1197c8: F9400428  ldr      x8, [x1, #8]
static inline uint64_t fde_func_2624_0x1197bc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1197bcULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1e7310ULL;
    acc ^= (acc >> 17) * 0x00f0ULL;
    return acc;
}

// FDE #2625 | PC: 0x1198ac | FDE: 0x1e7330 | Size: 148 bytes
// Khung tháo gỡ #2625 | Địa chỉ PC: 0x1198ac | Địa chỉ FDE: 0x1e7330 | Kích thước: 148 bytes
//   0x1198ac: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x1198b0: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x1198b4: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x1198b8: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_2625_0x1198ac(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1198acULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1e7330ULL;
    acc ^= (acc >> 17) * 0x0094ULL;
    return acc;
}

// FDE #2626 | PC: 0x119940 | FDE: 0x1e7358 | Size: 176 bytes
// Khung tháo gỡ #2626 | Địa chỉ PC: 0x119940 | Địa chỉ FDE: 0x1e7358 | Kích thước: 176 bytes
//   0x119940: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x119944: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x119948: 910043FD  add      x29, sp, #0x10
//   0x11994c: F9400428  ldr      x8, [x1, #8]
static inline uint64_t fde_func_2626_0x119940(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x119940ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1e7358ULL;
    acc ^= (acc >> 17) * 0x00b0ULL;
    return acc;
}

// FDE #2627 | PC: 0x1199f0 | FDE: 0x1e7378 | Size: 236 bytes
// Khung tháo gỡ #2627 | Địa chỉ PC: 0x1199f0 | Địa chỉ FDE: 0x1e7378 | Kích thước: 236 bytes
//   0x1199f0: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x1199f4: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x1199f8: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x1199fc: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_2627_0x1199f0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1199f0ULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1e7378ULL;
    acc ^= (acc >> 17) * 0x00ecULL;
    return acc;
}

// FDE #2628 | PC: 0x119adc | FDE: 0x1e7398 | Size: 184 bytes
// Khung tháo gỡ #2628 | Địa chỉ PC: 0x119adc | Địa chỉ FDE: 0x1e7398 | Kích thước: 184 bytes
//   0x119adc: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x119ae0: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x119ae4: 910043FD  add      x29, sp, #0x10
//   0x119ae8: F9400428  ldr      x8, [x1, #8]
static inline uint64_t fde_func_2628_0x119adc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x119adcULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1e7398ULL;
    acc ^= (acc >> 17) * 0x00b8ULL;
    return acc;
}

// FDE #2629 | PC: 0x119b94 | FDE: 0x1e73b8 | Size: 256 bytes
// Khung tháo gỡ #2629 | Địa chỉ PC: 0x119b94 | Địa chỉ FDE: 0x1e73b8 | Kích thước: 256 bytes
//   0x119b94: F81C0FF7  str      x23, [sp, #-0x40]!
//   0x119b98: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x119b9c: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x119ba0: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_2629_0x119b94(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x119b94ULL ^ (static_cast<uint64_t>(0xf81c0ff7ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x1e73b8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #2630 | PC: 0x119d64 | FDE: 0x1e73e0 | Size: 156 bytes
// Khung tháo gỡ #2630 | Địa chỉ PC: 0x119d64 | Địa chỉ FDE: 0x1e73e0 | Kích thước: 156 bytes
//   0x119d64: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x119d68: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x119d6c: 910043FD  add      x29, sp, #0x10
//   0x119d70: D0000728  adrp     x8, #0x1ff000
static inline uint64_t fde_func_2630_0x119d64(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x119d64ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1e73e0ULL;
    acc ^= (acc >> 17) * 0x009cULL;
    return acc;
}

// FDE #2631 | PC: 0x119e00 | FDE: 0x1e7400 | Size: 156 bytes
// Khung tháo gỡ #2631 | Địa chỉ PC: 0x119e00 | Địa chỉ FDE: 0x1e7400 | Kích thước: 156 bytes
//   0x119e00: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x119e04: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x119e08: 910043FD  add      x29, sp, #0x10
//   0x119e0c: D0000728  adrp     x8, #0x1ff000
static inline uint64_t fde_func_2631_0x119e00(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x119e00ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1e7400ULL;
    acc ^= (acc >> 17) * 0x009cULL;
    return acc;
}

// FDE #2632 | PC: 0x119e9c | FDE: 0x1e7420 | Size: 256 bytes
// Khung tháo gỡ #2632 | Địa chỉ PC: 0x119e9c | Địa chỉ FDE: 0x1e7420 | Kích thước: 256 bytes
//   0x119e9c: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x119ea0: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x119ea4: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x119ea8: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_2632_0x119e9c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x119e9cULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1e7420ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #2633 | PC: 0x119fe4 | FDE: 0x1e7440 | Size: 256 bytes
// Khung tháo gỡ #2633 | Địa chỉ PC: 0x119fe4 | Địa chỉ FDE: 0x1e7440 | Kích thước: 256 bytes
//   0x119fe4: D102C3FF  sub      sp, sp, #0xb0
//   0x119fe8: F90043F5  str      x21, [sp, #0x80]
//   0x119fec: A9094FF4  stp      x20, x19, [sp, #0x90]
//   0x119ff0: A90A7BFD  stp      x29, x30, [sp, #0xa0]
static inline uint64_t fde_func_2633_0x119fe4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x119fe4ULL ^ (static_cast<uint64_t>(0xd102c3ffULL) << 13);
    acc = (acc + a1 + 0xf90043f5ULL) ^ 0x1e7440ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #2634 | PC: 0x11a140 | FDE: 0x1e7460 | Size: 256 bytes
// Khung tháo gỡ #2634 | Địa chỉ PC: 0x11a140 | Địa chỉ FDE: 0x1e7460 | Kích thước: 256 bytes
//   0x11a140: A9BC5FF8  stp      x24, x23, [sp, #-0x40]!
//   0x11a144: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x11a148: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x11a14c: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_2634_0x11a140(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x11a140ULL ^ (static_cast<uint64_t>(0xa9bc5ff8ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x1e7460ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #2635 | PC: 0x11a2ac | FDE: 0x1e7488 | Size: 184 bytes
// Khung tháo gỡ #2635 | Địa chỉ PC: 0x11a2ac | Địa chỉ FDE: 0x1e7488 | Kích thước: 184 bytes
//   0x11a2ac: F81C0FF7  str      x23, [sp, #-0x40]!
//   0x11a2b0: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x11a2b4: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x11a2b8: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_2635_0x11a2ac(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x11a2acULL ^ (static_cast<uint64_t>(0xf81c0ff7ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x1e7488ULL;
    acc ^= (acc >> 17) * 0x00b8ULL;
    return acc;
}

// FDE #2636 | PC: 0x11a364 | FDE: 0x1e74b0 | Size: 112 bytes
// Khung tháo gỡ #2636 | Địa chỉ PC: 0x11a364 | Địa chỉ FDE: 0x1e74b0 | Kích thước: 112 bytes
//   0x11a364: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x11a368: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x11a36c: 910043FD  add      x29, sp, #0x10
//   0x11a370: AA0003F4  mov      x20, x0
static inline uint64_t fde_func_2636_0x11a364(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x11a364ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1e74b0ULL;
    acc ^= (acc >> 17) * 0x0070ULL;
    return acc;
}

// FDE #2637 | PC: 0x11a3d4 | FDE: 0x1e74d0 | Size: 256 bytes [_PyImport_LoadDynamicModuleWithSpec]
// Khung tháo gỡ #2637 | Địa chỉ PC: 0x11a3d4 | Địa chỉ FDE: 0x1e74d0 | Kích thước: 256 bytes
//   0x11a3d4: A9BA6FFC  stp      x28, x27, [sp, #-0x60]!
//   0x11a3d8: A90167FA  stp      x26, x25, [sp, #0x10]
//   0x11a3dc: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x11a3e0: A90357F6  stp      x22, x21, [sp, #0x30]
static inline uint64_t fde_func_2637_0x11a3d4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x11a3d4ULL ^ (static_cast<uint64_t>(0xa9ba6ffcULL) << 13);
    acc = (acc + a1 + 0xa90167faULL) ^ 0x1e74d0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #2638 | PC: 0x11a968 | FDE: 0x1e7500 | Size: 256 bytes [_PyImport_FindSharedFuncptr]
// Khung tháo gỡ #2638 | Địa chỉ PC: 0x11a968 | Địa chỉ FDE: 0x1e7500 | Kích thước: 256 bytes
//   0x11a968: F81B0FFC  str      x28, [sp, #-0x50]!
//   0x11a96c: A9015FF8  stp      x24, x23, [sp, #0x10]
//   0x11a970: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x11a974: A9034FF4  stp      x20, x19, [sp, #0x30]
static inline uint64_t fde_func_2638_0x11a968(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x11a968ULL ^ (static_cast<uint64_t>(0xf81b0ffcULL) << 13);
    acc = (acc + a1 + 0xa9015ff8ULL) ^ 0x1e7500ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #2639 | PC: 0x11abf4 | FDE: 0x1e7528 | Size: 12 bytes [PyStatus_Ok]
// Khung tháo gỡ #2639 | Địa chỉ PC: 0x11abf4 | Địa chỉ FDE: 0x1e7528 | Kích thước: 12 bytes
//   0x11abf4: 6F00E400  movi     v0.2d, #0000000000000000
//   0x11abf8: AD000100  stp      q0, q0, [x8]
//   0x11abfc: D65F03C0  ret      
static inline uint64_t fde_func_2639_0x11abf4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x11abf4ULL ^ (static_cast<uint64_t>(0x6f00e400ULL) << 13);
    acc = (acc + a1 + 0xad000100ULL) ^ 0x1e7528ULL;
    acc ^= (acc >> 17) * 0x000cULL;
    return acc;
}

// FDE #2640 | PC: 0x11ac00 | FDE: 0x1e7540 | Size: 20 bytes [PyStatus_Error]
// Khung tháo gỡ #2640 | Địa chỉ PC: 0x11ac00 | Địa chỉ FDE: 0x1e7540 | Kích thước: 20 bytes
//   0x11ac00: 52800029  mov      w9, #1
//   0x11ac04: A900811F  stp      xzr, x0, [x8, #8]
//   0x11ac08: B9000109  str      w9, [x8]
//   0x11ac0c: B900191F  str      wzr, [x8, #0x18]
static inline uint64_t fde_func_2640_0x11ac00(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x11ac00ULL ^ (static_cast<uint64_t>(0x52800029ULL) << 13);
    acc = (acc + a1 + 0xa900811fULL) ^ 0x1e7540ULL;
    acc ^= (acc >> 17) * 0x0014ULL;
    return acc;
}

// FDE #2641 | PC: 0x11ac14 | FDE: 0x1e7558 | Size: 36 bytes [PyStatus_NoMemory]
// Khung tháo gỡ #2641 | Địa chỉ PC: 0x11ac14 | Địa chỉ FDE: 0x1e7558 | Kích thước: 36 bytes
//   0x11ac14: B000044A  adrp     x10, #0x1a3000
//   0x11ac18: 913CB14A  add      x10, x10, #0xf2c
//   0x11ac1c: 6F00E400  movi     v0.2d, #0000000000000000
//   0x11ac20: 52800029  mov      w9, #1
static inline uint64_t fde_func_2641_0x11ac14(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x11ac14ULL ^ (static_cast<uint64_t>(0xb000044aULL) << 13);
    acc = (acc + a1 + 0x913cb14aULL) ^ 0x1e7558ULL;
    acc ^= (acc >> 17) * 0x0024ULL;
    return acc;
}

// FDE #2642 | PC: 0x11ac38 | FDE: 0x1e7570 | Size: 24 bytes [PyStatus_Exit]
// Khung tháo gỡ #2642 | Địa chỉ PC: 0x11ac38 | Địa chỉ FDE: 0x1e7570 | Kích thước: 24 bytes
//   0x11ac38: 6F00E400  movi     v0.2d, #0000000000000000
//   0x11ac3c: 52800049  mov      w9, #2
//   0x11ac40: AD000100  stp      q0, q0, [x8]
//   0x11ac44: B9000109  str      w9, [x8]
static inline uint64_t fde_func_2642_0x11ac38(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x11ac38ULL ^ (static_cast<uint64_t>(0x6f00e400ULL) << 13);
    acc = (acc + a1 + 0x52800049ULL) ^ 0x1e7570ULL;
    acc ^= (acc >> 17) * 0x0018ULL;
    return acc;
}

// FDE #2643 | PC: 0x11ac50 | FDE: 0x1e7588 | Size: 16 bytes [PyStatus_IsError]
// Khung tháo gỡ #2643 | Địa chỉ PC: 0x11ac50 | Địa chỉ FDE: 0x1e7588 | Kích thước: 16 bytes
//   0x11ac50: B9400008  ldr      w8, [x0]
//   0x11ac54: 7100051F  cmp      w8, #1
//   0x11ac58: 1A9F17E0  cset     w0, eq
//   0x11ac5c: D65F03C0  ret      
static inline uint64_t fde_func_2643_0x11ac50(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x11ac50ULL ^ (static_cast<uint64_t>(0xb9400008ULL) << 13);
    acc = (acc + a1 + 0x7100051fULL) ^ 0x1e7588ULL;
    acc ^= (acc >> 17) * 0x0010ULL;
    return acc;
}

// FDE #2644 | PC: 0x11ac60 | FDE: 0x1e75a0 | Size: 16 bytes [PyStatus_IsExit]
// Khung tháo gỡ #2644 | Địa chỉ PC: 0x11ac60 | Địa chỉ FDE: 0x1e75a0 | Kích thước: 16 bytes
//   0x11ac60: B9400008  ldr      w8, [x0]
//   0x11ac64: 7100091F  cmp      w8, #2
//   0x11ac68: 1A9F17E0  cset     w0, eq
//   0x11ac6c: D65F03C0  ret      
static inline uint64_t fde_func_2644_0x11ac60(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x11ac60ULL ^ (static_cast<uint64_t>(0xb9400008ULL) << 13);
    acc = (acc + a1 + 0x7100091fULL) ^ 0x1e75a0ULL;
    acc ^= (acc >> 17) * 0x0010ULL;
    return acc;
}

// FDE #2645 | PC: 0x11ac70 | FDE: 0x1e75b8 | Size: 16 bytes [PyStatus_Exception]
// Khung tháo gỡ #2645 | Địa chỉ PC: 0x11ac70 | Địa chỉ FDE: 0x1e75b8 | Kích thước: 16 bytes
//   0x11ac70: B9400008  ldr      w8, [x0]
//   0x11ac74: 7100011F  cmp      w8, #0
//   0x11ac78: 1A9F07E0  cset     w0, ne
//   0x11ac7c: D65F03C0  ret      
static inline uint64_t fde_func_2645_0x11ac70(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x11ac70ULL ^ (static_cast<uint64_t>(0xb9400008ULL) << 13);
    acc = (acc + a1 + 0x7100011fULL) ^ 0x1e75b8ULL;
    acc ^= (acc >> 17) * 0x0010ULL;
    return acc;
}

// FDE #2646 | PC: 0x11ac80 | FDE: 0x1e75d0 | Size: 120 bytes [_PyErr_SetFromPyStatus]
// Khung tháo gỡ #2646 | Địa chỉ PC: 0x11ac80 | Địa chỉ FDE: 0x1e75d0 | Kích thước: 120 bytes
//   0x11ac80: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x11ac84: 910003FD  mov      x29, sp
//   0x11ac88: B9400009  ldr      w9, [x0]
//   0x11ac8c: 7100053F  cmp      w9, #1
static inline uint64_t fde_func_2646_0x11ac80(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x11ac80ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1e75d0ULL;
    acc ^= (acc >> 17) * 0x0078ULL;
    return acc;
}

// FDE #2647 | PC: 0x11acf8 | FDE: 0x1e75f0 | Size: 84 bytes [_PyWideStringList_Clear]
// Khung tháo gỡ #2647 | Địa chỉ PC: 0x11acf8 | Địa chỉ FDE: 0x1e75f0 | Kích thước: 84 bytes
//   0x11acf8: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x11acfc: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x11ad00: 910043FD  add      x29, sp, #0x10
//   0x11ad04: F9400008  ldr      x8, [x0]
static inline uint64_t fde_func_2647_0x11acf8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x11acf8ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1e75f0ULL;
    acc ^= (acc >> 17) * 0x0054ULL;
    return acc;
}

// FDE #2648 | PC: 0x11ad4c | FDE: 0x1e7610 | Size: 256 bytes [_PyWideStringList_Copy]
// Khung tháo gỡ #2648 | Địa chỉ PC: 0x11ad4c | Địa chỉ FDE: 0x1e7610 | Kích thước: 256 bytes
//   0x11ad4c: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x11ad50: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x11ad54: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x11ad58: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_2648_0x11ad4c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x11ad4cULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1e7610ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #2649 | PC: 0x11ae70 | FDE: 0x1e7638 | Size: 256 bytes [PyWideStringList_Insert]
// Khung tháo gỡ #2649 | Địa chỉ PC: 0x11ae70 | Địa chỉ FDE: 0x1e7638 | Kích thước: 256 bytes
//   0x11ae70: F81B0FF9  str      x25, [sp, #-0x50]!
//   0x11ae74: A9015FF8  stp      x24, x23, [sp, #0x10]
//   0x11ae78: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x11ae7c: A9034FF4  stp      x20, x19, [sp, #0x30]
static inline uint64_t fde_func_2649_0x11ae70(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x11ae70ULL ^ (static_cast<uint64_t>(0xf81b0ff9ULL) << 13);
    acc = (acc + a1 + 0xa9015ff8ULL) ^ 0x1e7638ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #2650 | PC: 0x11af74 | FDE: 0x1e7660 | Size: 12 bytes [PyWideStringList_Append]
// Khung tháo gỡ #2650 | Địa chỉ PC: 0x11af74 | Địa chỉ FDE: 0x1e7660 | Kích thước: 12 bytes
//   0x11af74: AA0103E2  mov      x2, x1
//   0x11af78: F9400001  ldr      x1, [x0]
//   0x11af7c: 17FCF51D  b        #0x583f0
static inline uint64_t fde_func_2650_0x11af74(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x11af74ULL ^ (static_cast<uint64_t>(0xaa0103e2ULL) << 13);
    acc = (acc + a1 + 0xf9400001ULL) ^ 0x1e7660ULL;
    acc ^= (acc >> 17) * 0x000cULL;
    return acc;
}

// FDE #2651 | PC: 0x11af80 | FDE: 0x1e7678 | Size: 116 bytes [_PyWideStringList_Extend]
// Khung tháo gỡ #2651 | Địa chỉ PC: 0x11af80 | Địa chỉ FDE: 0x1e7678 | Kích thước: 116 bytes
//   0x11af80: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x11af84: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x11af88: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x11af8c: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_2651_0x11af80(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x11af80ULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1e7678ULL;
    acc ^= (acc >> 17) * 0x0074ULL;
    return acc;
}

// FDE #2652 | PC: 0x11aff4 | FDE: 0x1e76a0 | Size: 148 bytes [_PyWideStringList_AsList]
// Khung tháo gỡ #2652 | Địa chỉ PC: 0x11aff4 | Địa chỉ FDE: 0x1e76a0 | Kích thước: 148 bytes
//   0x11aff4: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x11aff8: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x11affc: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x11b000: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_2652_0x11aff4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x11aff4ULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1e76a0ULL;
    acc ^= (acc >> 17) * 0x0094ULL;
    return acc;
}

// FDE #2653 | PC: 0x11b088 | FDE: 0x1e76c0 | Size: 216 bytes [Py_SetStandardStreamEncoding]
// Khung tháo gỡ #2653 | Địa chỉ PC: 0x11b088 | Địa chỉ FDE: 0x1e76c0 | Kích thước: 216 bytes
//   0x11b088: D10183FF  sub      sp, sp, #0x60
//   0x11b08c: A90357F6  stp      x22, x21, [sp, #0x30]
//   0x11b090: A9044FF4  stp      x20, x19, [sp, #0x40]
//   0x11b094: A9057BFD  stp      x29, x30, [sp, #0x50]
static inline uint64_t fde_func_2653_0x11b088(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x11b088ULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xa90357f6ULL) ^ 0x1e76c0ULL;
    acc ^= (acc >> 17) * 0x00d8ULL;
    return acc;
}

// FDE #2654 | PC: 0x11b160 | FDE: 0x1e76e8 | Size: 128 bytes [_Py_ClearStandardStreamEncoding]
// Khung tháo gỡ #2654 | Địa chỉ PC: 0x11b160 | Địa chỉ FDE: 0x1e76e8 | Kích thước: 128 bytes
//   0x11b160: D10143FF  sub      sp, sp, #0x50
//   0x11b164: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x11b168: A9047BFD  stp      x29, x30, [sp, #0x40]
//   0x11b16c: 910103FD  add      x29, sp, #0x40
static inline uint64_t fde_func_2654_0x11b160(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x11b160ULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xa9034ff4ULL) ^ 0x1e76e8ULL;
    acc ^= (acc >> 17) * 0x0080ULL;
    return acc;
}

// FDE #2655 | PC: 0x11b1e0 | FDE: 0x1e7708 | Size: 164 bytes [_Py_ClearArgcArgv]
// Khung tháo gỡ #2655 | Địa chỉ PC: 0x11b1e0 | Địa chỉ FDE: 0x1e7708 | Kích thước: 164 bytes
//   0x11b1e0: D10183FF  sub      sp, sp, #0x60
//   0x11b1e4: F9001BF5  str      x21, [sp, #0x30]
//   0x11b1e8: A9044FF4  stp      x20, x19, [sp, #0x40]
//   0x11b1ec: A9057BFD  stp      x29, x30, [sp, #0x50]
static inline uint64_t fde_func_2655_0x11b1e0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x11b1e0ULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xf9001bf5ULL) ^ 0x1e7708ULL;
    acc ^= (acc >> 17) * 0x00a4ULL;
    return acc;
}

// FDE #2656 | PC: 0x11b284 | FDE: 0x1e7728 | Size: 28 bytes [Py_GetArgcArgv]
// Khung tháo gỡ #2656 | Địa chỉ PC: 0x11b284 | Địa chỉ FDE: 0x1e7728 | Kích thước: 28 bytes
//   0x11b284: D0000848  adrp     x8, #0x225000
//   0x11b288: 910C4108  add      x8, x8, #0x310
//   0x11b28c: F9400109  ldr      x9, [x8]
//   0x11b290: B9000009  str      w9, [x0]
static inline uint64_t fde_func_2656_0x11b284(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x11b284ULL ^ (static_cast<uint64_t>(0xd0000848ULL) << 13);
    acc = (acc + a1 + 0x910c4108ULL) ^ 0x1e7728ULL;
    acc ^= (acc >> 17) * 0x001cULL;
    return acc;
}

// FDE #2657 | PC: 0x11b2a0 | FDE: 0x1e7740 | Size: 256 bytes [PyConfig_Clear]
// Khung tháo gỡ #2657 | Địa chỉ PC: 0x11b2a0 | Địa chỉ FDE: 0x1e7740 | Kích thước: 256 bytes
//   0x11b2a0: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x11b2a4: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x11b2a8: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x11b2ac: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_2657_0x11b2a0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x11b2a0ULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1e7740ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #2658 | PC: 0x11b4d8 | FDE: 0x1e7760 | Size: 156 bytes [_PyConfig_InitCompatConfig]
// Khung tháo gỡ #2658 | Địa chỉ PC: 0x11b4d8 | Địa chỉ FDE: 0x1e7760 | Kích thước: 156 bytes
//   0x11b4d8: 6F00E400  movi     v0.2d, #0000000000000000
//   0x11b4dc: AD0B0000  stp      q0, q0, [x0, #0x160]
//   0x11b4e0: AD0A0000  stp      q0, q0, [x0, #0x140]
//   0x11b4e4: AD090000  stp      q0, q0, [x0, #0x120]
static inline uint64_t fde_func_2658_0x11b4d8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x11b4d8ULL ^ (static_cast<uint64_t>(0x6f00e400ULL) << 13);
    acc = (acc + a1 + 0xad0b0000ULL) ^ 0x1e7760ULL;
    acc ^= (acc >> 17) * 0x009cULL;
    return acc;
}

// FDE #2659 | PC: 0x11b574 | FDE: 0x1e7778 | Size: 172 bytes [PyConfig_InitPythonConfig]
// Khung tháo gỡ #2659 | Địa chỉ PC: 0x11b574 | Địa chỉ FDE: 0x1e7778 | Kích thước: 172 bytes
//   0x11b574: 6F00E400  movi     v0.2d, #0000000000000000
//   0x11b578: AD0B0000  stp      q0, q0, [x0, #0x160]
//   0x11b57c: AD0A0000  stp      q0, q0, [x0, #0x140]
//   0x11b580: AD090000  stp      q0, q0, [x0, #0x120]
static inline uint64_t fde_func_2659_0x11b574(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x11b574ULL ^ (static_cast<uint64_t>(0x6f00e400ULL) << 13);
    acc = (acc + a1 + 0xad0b0000ULL) ^ 0x1e7778ULL;
    acc ^= (acc >> 17) * 0x00acULL;
    return acc;
}

// FDE #2660 | PC: 0x11b620 | FDE: 0x1e7790 | Size: 148 bytes [PyConfig_InitIsolatedConfig]
// Khung tháo gỡ #2660 | Địa chỉ PC: 0x11b620 | Địa chỉ FDE: 0x1e7790 | Kích thước: 148 bytes
//   0x11b620: 6F00E400  movi     v0.2d, #0000000000000000
//   0x11b624: D2C00028  mov      x8, #0x100000000
//   0x11b628: AD0B0000  stp      q0, q0, [x0, #0x160]
//   0x11b62c: AD0A0000  stp      q0, q0, [x0, #0x140]
static inline uint64_t fde_func_2660_0x11b620(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x11b620ULL ^ (static_cast<uint64_t>(0x6f00e400ULL) << 13);
    acc = (acc + a1 + 0xd2c00028ULL) ^ 0x1e7790ULL;
    acc ^= (acc >> 17) * 0x0094ULL;
    return acc;
}

// FDE #2661 | PC: 0x11b6b4 | FDE: 0x1e77a8 | Size: 204 bytes [PyConfig_SetString]
// Khung tháo gỡ #2661 | Địa chỉ PC: 0x11b6b4 | Địa chỉ FDE: 0x1e77a8 | Kích thước: 204 bytes
//   0x11b6b4: D10183FF  sub      sp, sp, #0x60
//   0x11b6b8: A90357F6  stp      x22, x21, [sp, #0x30]
//   0x11b6bc: A9044FF4  stp      x20, x19, [sp, #0x40]
//   0x11b6c0: A9057BFD  stp      x29, x30, [sp, #0x50]
static inline uint64_t fde_func_2661_0x11b6b4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x11b6b4ULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xa90357f6ULL) ^ 0x1e77a8ULL;
    acc ^= (acc >> 17) * 0x00ccULL;
    return acc;
}

// FDE #2662 | PC: 0x11b780 | FDE: 0x1e77d0 | Size: 228 bytes [PyConfig_SetBytesString]
// Khung tháo gỡ #2662 | Địa chỉ PC: 0x11b780 | Địa chỉ FDE: 0x1e77d0 | Kích thước: 228 bytes
//   0x11b780: D10183FF  sub      sp, sp, #0x60
//   0x11b784: A90357F6  stp      x22, x21, [sp, #0x30]
//   0x11b788: A9044FF4  stp      x20, x19, [sp, #0x40]
//   0x11b78c: A9057BFD  stp      x29, x30, [sp, #0x50]
static inline uint64_t fde_func_2662_0x11b780(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x11b780ULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xa90357f6ULL) ^ 0x1e77d0ULL;
    acc ^= (acc >> 17) * 0x00e4ULL;
    return acc;
}

// FDE #2663 | PC: 0x11b864 | FDE: 0x1e77f8 | Size: 256 bytes [_PyConfig_Copy]
// Khung tháo gỡ #2663 | Địa chỉ PC: 0x11b864 | Địa chỉ FDE: 0x1e77f8 | Kích thước: 256 bytes
//   0x11b864: D10203FF  sub      sp, sp, #0x80
//   0x11b868: F9001BF9  str      x25, [sp, #0x30]
//   0x11b86c: A9045FF8  stp      x24, x23, [sp, #0x40]
//   0x11b870: A90557F6  stp      x22, x21, [sp, #0x50]
static inline uint64_t fde_func_2663_0x11b864(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x11b864ULL ^ (static_cast<uint64_t>(0xd10203ffULL) << 13);
    acc = (acc + a1 + 0xf9001bf9ULL) ^ 0x1e77f8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #2664 | PC: 0x11be8c | FDE: 0x1e7820 | Size: 256 bytes [_PyConfig_AsDict]
// Khung tháo gỡ #2664 | Địa chỉ PC: 0x11be8c | Địa chỉ FDE: 0x1e7820 | Kích thước: 256 bytes
//   0x11be8c: F81C0FF7  str      x23, [sp, #-0x40]!
//   0x11be90: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x11be94: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x11be98: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_2664_0x11be8c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x11be8cULL ^ (static_cast<uint64_t>(0xf81c0ff7ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x1e7820ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #2665 | PC: 0x11d190 | FDE: 0x1e7848 | Size: 256 bytes [_PyConfig_FromDict]
// Khung tháo gỡ #2665 | Địa chỉ PC: 0x11d190 | Địa chỉ FDE: 0x1e7848 | Kích thước: 256 bytes
//   0x11d190: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x11d194: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x11d198: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x11d19c: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_2665_0x11d190(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x11d190ULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1e7848ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #2666 | PC: 0x11def4 | FDE: 0x1e7868 | Size: 200 bytes
// Khung tháo gỡ #2666 | Địa chỉ PC: 0x11def4 | Địa chỉ FDE: 0x1e7868 | Kích thước: 200 bytes
//   0x11def4: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x11def8: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x11defc: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x11df00: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_2666_0x11def4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x11def4ULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1e7868ULL;
    acc ^= (acc >> 17) * 0x00c8ULL;
    return acc;
}

// FDE #2667 | PC: 0x11dfbc | FDE: 0x1e7888 | Size: 256 bytes
// Khung tháo gỡ #2667 | Địa chỉ PC: 0x11dfbc | Địa chỉ FDE: 0x1e7888 | Kích thước: 256 bytes
//   0x11dfbc: D101C3FF  sub      sp, sp, #0x70
//   0x11dfc0: F9001BF7  str      x23, [sp, #0x30]
//   0x11dfc4: A90457F6  stp      x22, x21, [sp, #0x40]
//   0x11dfc8: A9054FF4  stp      x20, x19, [sp, #0x50]
static inline uint64_t fde_func_2667_0x11dfbc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x11dfbcULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xf9001bf7ULL) ^ 0x1e7888ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #2668 | PC: 0x11e118 | FDE: 0x1e78b0 | Size: 256 bytes
// Khung tháo gỡ #2668 | Địa chỉ PC: 0x11e118 | Địa chỉ FDE: 0x1e78b0 | Kích thước: 256 bytes
//   0x11e118: D101C3FF  sub      sp, sp, #0x70
//   0x11e11c: A9035FF8  stp      x24, x23, [sp, #0x30]
//   0x11e120: A90457F6  stp      x22, x21, [sp, #0x40]
//   0x11e124: A9054FF4  stp      x20, x19, [sp, #0x50]
static inline uint64_t fde_func_2668_0x11e118(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x11e118ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xa9035ff8ULL) ^ 0x1e78b0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #2669 | PC: 0x11e2ec | FDE: 0x1e78d8 | Size: 256 bytes [_PyConfig_Write]
// Khung tháo gỡ #2669 | Địa chỉ PC: 0x11e2ec | Địa chỉ FDE: 0x1e78d8 | Kích thước: 256 bytes
//   0x11e2ec: D10203FF  sub      sp, sp, #0x80
//   0x11e2f0: F90023F7  str      x23, [sp, #0x40]
//   0x11e2f4: A90557F6  stp      x22, x21, [sp, #0x50]
//   0x11e2f8: A9064FF4  stp      x20, x19, [sp, #0x60]
static inline uint64_t fde_func_2669_0x11e2ec(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x11e2ecULL ^ (static_cast<uint64_t>(0xd10203ffULL) << 13);
    acc = (acc + a1 + 0xf90023f7ULL) ^ 0x1e78d8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #2670 | PC: 0x11e5ec | FDE: 0x1e7900 | Size: 132 bytes [_PyConfig_SetPyArgv]
// Khung tháo gỡ #2670 | Địa chỉ PC: 0x11e5ec | Địa chỉ FDE: 0x1e7900 | Kích thước: 132 bytes
//   0x11e5ec: D10183FF  sub      sp, sp, #0x60
//   0x11e5f0: A90357F6  stp      x22, x21, [sp, #0x30]
//   0x11e5f4: A9044FF4  stp      x20, x19, [sp, #0x40]
//   0x11e5f8: A9057BFD  stp      x29, x30, [sp, #0x50]
static inline uint64_t fde_func_2670_0x11e5ec(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x11e5ecULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xa90357f6ULL) ^ 0x1e7900ULL;
    acc ^= (acc >> 17) * 0x0084ULL;
    return acc;
}

// FDE #2671 | PC: 0x11e670 | FDE: 0x1e7928 | Size: 148 bytes [PyConfig_SetBytesArgv]
// Khung tháo gỡ #2671 | Địa chỉ PC: 0x11e670 | Địa chỉ FDE: 0x1e7928 | Kích thước: 148 bytes
//   0x11e670: D10203FF  sub      sp, sp, #0x80
//   0x11e674: F9002BF5  str      x21, [sp, #0x50]
//   0x11e678: A9064FF4  stp      x20, x19, [sp, #0x60]
//   0x11e67c: A9077BFD  stp      x29, x30, [sp, #0x70]
static inline uint64_t fde_func_2671_0x11e670(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x11e670ULL ^ (static_cast<uint64_t>(0xd10203ffULL) << 13);
    acc = (acc + a1 + 0xf9002bf5ULL) ^ 0x1e7928ULL;
    acc ^= (acc >> 17) * 0x0094ULL;
    return acc;
}

// FDE #2672 | PC: 0x11e704 | FDE: 0x1e7948 | Size: 144 bytes [PyConfig_SetArgv]
// Khung tháo gỡ #2672 | Địa chỉ PC: 0x11e704 | Địa chỉ FDE: 0x1e7948 | Kích thước: 144 bytes
//   0x11e704: D10203FF  sub      sp, sp, #0x80
//   0x11e708: F9002BF5  str      x21, [sp, #0x50]
//   0x11e70c: A9064FF4  stp      x20, x19, [sp, #0x60]
//   0x11e710: A9077BFD  stp      x29, x30, [sp, #0x70]
static inline uint64_t fde_func_2672_0x11e704(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x11e704ULL ^ (static_cast<uint64_t>(0xd10203ffULL) << 13);
    acc = (acc + a1 + 0xf9002bf5ULL) ^ 0x1e7948ULL;
    acc ^= (acc >> 17) * 0x0090ULL;
    return acc;
}

// FDE #2673 | PC: 0x11e794 | FDE: 0x1e7968 | Size: 208 bytes [PyConfig_SetWideStringList]
// Khung tháo gỡ #2673 | Địa chỉ PC: 0x11e794 | Địa chỉ FDE: 0x1e7968 | Kích thước: 208 bytes
//   0x11e794: D10203FF  sub      sp, sp, #0x80
//   0x11e798: F90023F7  str      x23, [sp, #0x40]
//   0x11e79c: A90557F6  stp      x22, x21, [sp, #0x50]
//   0x11e7a0: A9064FF4  stp      x20, x19, [sp, #0x60]
static inline uint64_t fde_func_2673_0x11e794(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x11e794ULL ^ (static_cast<uint64_t>(0xd10203ffULL) << 13);
    acc = (acc + a1 + 0xf90023f7ULL) ^ 0x1e7968ULL;
    acc ^= (acc >> 17) * 0x00d0ULL;
    return acc;
}

// FDE #2674 | PC: 0x11e864 | FDE: 0x1e7990 | Size: 256 bytes [_PyConfig_Read]
// Khung tháo gỡ #2674 | Địa chỉ PC: 0x11e864 | Địa chỉ FDE: 0x1e7990 | Kích thước: 256 bytes
//   0x11e864: D105C3FF  sub      sp, sp, #0x170
//   0x11e868: FD0083E8  str      d8, [sp, #0x100]
//   0x11e86c: A9116FFC  stp      x28, x27, [sp, #0x110]
//   0x11e870: A91267FA  stp      x26, x25, [sp, #0x120]
static inline uint64_t fde_func_2674_0x11e864(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x11e864ULL ^ (static_cast<uint64_t>(0xd105c3ffULL) << 13);
    acc = (acc + a1 + 0xfd0083e8ULL) ^ 0x1e7990ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #2675 | PC: 0x120828 | FDE: 0x1e79c0 | Size: 8 bytes [PyConfig_Read]
// Khung tháo gỡ #2675 | Địa chỉ PC: 0x120828 | Địa chỉ FDE: 0x1e79c0 | Kích thước: 8 bytes
//   0x120828: 52800021  mov      w1, #1
//   0x12082c: 17FCDFE1  b        #0x587b0
static inline uint64_t fde_func_2675_0x120828(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x120828ULL ^ (static_cast<uint64_t>(0x52800021ULL) << 13);
    acc = (acc + a1 + 0x17fcdfe1ULL) ^ 0x1e79c0ULL;
    acc ^= (acc >> 17) * 0x0008ULL;
    return acc;
}

// FDE #2676 | PC: 0x120830 | FDE: 0x1e79d8 | Size: 256 bytes [_Py_GetConfigsAsDict]
// Khung tháo gỡ #2676 | Địa chỉ PC: 0x120830 | Địa chỉ FDE: 0x1e79d8 | Kích thước: 256 bytes
//   0x120830: F81C0FF7  str      x23, [sp, #-0x40]!
//   0x120834: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x120838: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x12083c: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_2676_0x120830(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x120830ULL ^ (static_cast<uint64_t>(0xf81c0ff7ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x1e79d8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #2677 | PC: 0x121000 | FDE: 0x1e7a00 | Size: 256 bytes [_Py_DumpPathConfig]
// Khung tháo gỡ #2677 | Địa chỉ PC: 0x121000 | Địa chỉ FDE: 0x1e7a00 | Kích thước: 256 bytes
//   0x121000: D10183FF  sub      sp, sp, #0x60
//   0x121004: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x121008: A90357F6  stp      x22, x21, [sp, #0x30]
//   0x12100c: A9044FF4  stp      x20, x19, [sp, #0x40]
static inline uint64_t fde_func_2677_0x121000(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x121000ULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xa9025ff8ULL) ^ 0x1e7a00ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #2678 | PC: 0x1213e0 | FDE: 0x1e7a28 | Size: 220 bytes
// Khung tháo gỡ #2678 | Địa chỉ PC: 0x1213e0 | Địa chỉ FDE: 0x1e7a28 | Kích thước: 220 bytes
//   0x1213e0: B4000680  cbz      x0, #0x1214b0
//   0x1213e4: A9BC5FF8  stp      x24, x23, [sp, #-0x40]!
//   0x1213e8: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x1213ec: A9024FF4  stp      x20, x19, [sp, #0x20]
static inline uint64_t fde_func_2678_0x1213e0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1213e0ULL ^ (static_cast<uint64_t>(0xb4000680ULL) << 13);
    acc = (acc + a1 + 0xa9bc5ff8ULL) ^ 0x1e7a28ULL;
    acc ^= (acc >> 17) * 0x00dcULL;
    return acc;
}

// FDE #2679 | PC: 0x1214bc | FDE: 0x1e7a50 | Size: 184 bytes [bd_marshal_dump_impl_extern]
// Khung tháo gỡ #2679 | Địa chỉ PC: 0x1214bc | Địa chỉ FDE: 0x1e7a50 | Kích thước: 184 bytes
//   0x1214bc: D10143FF  sub      sp, sp, #0x50
//   0x1214c0: F90013F5  str      x21, [sp, #0x20]
//   0x1214c4: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x1214c8: A9047BFD  stp      x29, x30, [sp, #0x40]
static inline uint64_t fde_func_2679_0x1214bc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1214bcULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xf90013f5ULL) ^ 0x1e7a50ULL;
    acc ^= (acc >> 17) * 0x00b8ULL;
    return acc;
}

// FDE #2680 | PC: 0x121574 | FDE: 0x1e7a70 | Size: 136 bytes [PyMarshal_WriteLongToFile]
// Khung tháo gỡ #2680 | Địa chỉ PC: 0x121574 | Địa chỉ FDE: 0x1e7a70 | Kích thước: 136 bytes
//   0x121574: D101C3FF  sub      sp, sp, #0x70
//   0x121578: F9002BF3  str      x19, [sp, #0x50]
//   0x12157c: A9067BFD  stp      x29, x30, [sp, #0x60]
//   0x121580: 910183FD  add      x29, sp, #0x60
static inline uint64_t fde_func_2680_0x121574(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x121574ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xf9002bf3ULL) ^ 0x1e7a70ULL;
    acc ^= (acc >> 17) * 0x0088ULL;
    return acc;
}

// FDE #2681 | PC: 0x1215fc | FDE: 0x1e7a90 | Size: 256 bytes
// Khung tháo gỡ #2681 | Địa chỉ PC: 0x1215fc | Địa chỉ FDE: 0x1e7a90 | Kích thước: 256 bytes
//   0x1215fc: A9BC5FF8  stp      x24, x23, [sp, #-0x40]!
//   0x121600: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x121604: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x121608: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_2681_0x1215fc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1215fcULL ^ (static_cast<uint64_t>(0xa9bc5ff8ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x1e7a90ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #2682 | PC: 0x12197c | FDE: 0x1e7ab8 | Size: 256 bytes [PyMarshal_WriteObjectToFile]
// Khung tháo gỡ #2682 | Địa chỉ PC: 0x12197c | Địa chỉ FDE: 0x1e7ab8 | Kích thước: 256 bytes
//   0x12197c: F81C0FFC  str      x28, [sp, #-0x40]!
//   0x121980: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x121984: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x121988: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_2682_0x12197c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x12197cULL ^ (static_cast<uint64_t>(0xf81c0ffcULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x1e7ab8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #2683 | PC: 0x121a94 | FDE: 0x1e7ae0 | Size: 256 bytes
// Khung tháo gỡ #2683 | Địa chỉ PC: 0x121a94 | Địa chỉ FDE: 0x1e7ae0 | Kích thước: 256 bytes
//   0x121a94: D10343FF  sub      sp, sp, #0xd0
//   0x121a98: F9003BFB  str      x27, [sp, #0x70]
//   0x121a9c: A90867FA  stp      x26, x25, [sp, #0x80]
//   0x121aa0: A9095FF8  stp      x24, x23, [sp, #0x90]
static inline uint64_t fde_func_2683_0x121a94(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x121a94ULL ^ (static_cast<uint64_t>(0xd10343ffULL) << 13);
    acc = (acc + a1 + 0xf9003bfbULL) ^ 0x1e7ae0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #2684 | PC: 0x123f48 | FDE: 0x1e7b10 | Size: 128 bytes [PyMarshal_ReadShortFromFile]
// Khung tháo gỡ #2684 | Địa chỉ PC: 0x123f48 | Địa chỉ FDE: 0x1e7b10 | Kích thước: 128 bytes
//   0x123f48: D10183FF  sub      sp, sp, #0x60
//   0x123f4c: F90023F3  str      x19, [sp, #0x40]
//   0x123f50: A9057BFD  stp      x29, x30, [sp, #0x50]
//   0x123f54: 910143FD  add      x29, sp, #0x50
static inline uint64_t fde_func_2684_0x123f48(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x123f48ULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xf90023f3ULL) ^ 0x1e7b10ULL;
    acc ^= (acc >> 17) * 0x0080ULL;
    return acc;
}

// FDE #2685 | PC: 0x123fc8 | FDE: 0x1e7b30 | Size: 136 bytes [PyMarshal_ReadLongFromFile]
// Khung tháo gỡ #2685 | Địa chỉ PC: 0x123fc8 | Địa chỉ FDE: 0x1e7b30 | Kích thước: 136 bytes
//   0x123fc8: D10183FF  sub      sp, sp, #0x60
//   0x123fcc: F90023F3  str      x19, [sp, #0x40]
//   0x123fd0: A9057BFD  stp      x29, x30, [sp, #0x50]
//   0x123fd4: 910143FD  add      x29, sp, #0x50
static inline uint64_t fde_func_2685_0x123fc8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x123fc8ULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xf90023f3ULL) ^ 0x1e7b30ULL;
    acc ^= (acc >> 17) * 0x0088ULL;
    return acc;
}

// FDE #2686 | PC: 0x124050 | FDE: 0x1e7b50 | Size: 256 bytes [PyMarshal_ReadLastObjectFromFile]
// Khung tháo gỡ #2686 | Địa chỉ PC: 0x124050 | Địa chỉ FDE: 0x1e7b50 | Kích thước: 256 bytes
//   0x124050: D10303FF  sub      sp, sp, #0xc0
//   0x124054: A90957F6  stp      x22, x21, [sp, #0x90]
//   0x124058: A90A4FF4  stp      x20, x19, [sp, #0xa0]
//   0x12405c: A90B7BFD  stp      x29, x30, [sp, #0xb0]
static inline uint64_t fde_func_2686_0x124050(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x124050ULL ^ (static_cast<uint64_t>(0xd10303ffULL) << 13);
    acc = (acc + a1 + 0xa90957f6ULL) ^ 0x1e7b50ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #2687 | PC: 0x1241a4 | FDE: 0x1e7b78 | Size: 160 bytes [PyMarshal_ReadObjectFromString]
// Khung tháo gỡ #2687 | Địa chỉ PC: 0x1241a4 | Địa chỉ FDE: 0x1e7b78 | Kích thước: 160 bytes
//   0x1241a4: D101C3FF  sub      sp, sp, #0x70
//   0x1241a8: A9054FF4  stp      x20, x19, [sp, #0x50]
//   0x1241ac: A9067BFD  stp      x29, x30, [sp, #0x60]
//   0x1241b0: 910183FD  add      x29, sp, #0x60
static inline uint64_t fde_func_2687_0x1241a4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1241a4ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xa9054ff4ULL) ^ 0x1e7b78ULL;
    acc ^= (acc >> 17) * 0x00a0ULL;
    return acc;
}

// FDE #2688 | PC: 0x124244 | FDE: 0x1e7b98 | Size: 160 bytes [PyMarshal_ReadObjectFromFile]
// Khung tháo gỡ #2688 | Địa chỉ PC: 0x124244 | Địa chỉ FDE: 0x1e7b98 | Kích thước: 160 bytes
//   0x124244: D101C3FF  sub      sp, sp, #0x70
//   0x124248: A9054FF4  stp      x20, x19, [sp, #0x50]
//   0x12424c: A9067BFD  stp      x29, x30, [sp, #0x60]
//   0x124250: 910183FD  add      x29, sp, #0x60
static inline uint64_t fde_func_2688_0x124244(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x124244ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xa9054ff4ULL) ^ 0x1e7b98ULL;
    acc ^= (acc >> 17) * 0x00a0ULL;
    return acc;
}

// FDE #2689 | PC: 0x1242e4 | FDE: 0x1e7bb8 | Size: 204 bytes
// Khung tháo gỡ #2689 | Địa chỉ PC: 0x1242e4 | Địa chỉ FDE: 0x1e7bb8 | Kích thước: 204 bytes
//   0x1242e4: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x1242e8: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x1242ec: 910043FD  add      x29, sp, #0x10
//   0x1242f0: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_2689_0x1242e4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1242e4ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1e7bb8ULL;
    acc ^= (acc >> 17) * 0x00ccULL;
    return acc;
}

// FDE #2690 | PC: 0x1243b0 | FDE: 0x1e7bd8 | Size: 256 bytes [PyMarshal_WriteObjectToString]
// Khung tháo gỡ #2690 | Địa chỉ PC: 0x1243b0 | Địa chỉ FDE: 0x1e7bd8 | Kích thước: 256 bytes
//   0x1243b0: D10203FF  sub      sp, sp, #0x80
//   0x1243b4: A90557F6  stp      x22, x21, [sp, #0x50]
//   0x1243b8: A9064FF4  stp      x20, x19, [sp, #0x60]
//   0x1243bc: A9077BFD  stp      x29, x30, [sp, #0x70]
static inline uint64_t fde_func_2690_0x1243b0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1243b0ULL ^ (static_cast<uint64_t>(0xd10203ffULL) << 13);
    acc = (acc + a1 + 0xa90557f6ULL) ^ 0x1e7bd8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #2691 | PC: 0x124570 | FDE: 0x1e7c00 | Size: 12 bytes [PyMarshal_Init]
// Khung tháo gỡ #2691 | Địa chỉ PC: 0x124570 | Địa chỉ FDE: 0x1e7c00 | Kích thước: 12 bytes
//   0x124570: F0000780  adrp     x0, #0x217000
//   0x124574: 912BE000  add      x0, x0, #0xaf8
//   0x124578: 17FCD12A  b        #0x58a20
static inline uint64_t fde_func_2691_0x124570(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x124570ULL ^ (static_cast<uint64_t>(0xf0000780ULL) << 13);
    acc = (acc + a1 + 0x912be000ULL) ^ 0x1e7c00ULL;
    acc ^= (acc >> 17) * 0x000cULL;
    return acc;
}

// FDE #2692 | PC: 0x12457c | FDE: 0x1e7c18 | Size: 28 bytes
// Khung tháo gỡ #2692 | Địa chỉ PC: 0x12457c | Địa chỉ FDE: 0x1e7c18 | Kích thước: 28 bytes
//   0x12457c: B40000A0  cbz      x0, #0x124590
//   0x124580: F9400008  ldr      x8, [x0]
//   0x124584: F1000508  subs     x8, x8, #1
//   0x124588: F9000008  str      x8, [x0]
static inline uint64_t fde_func_2692_0x12457c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x12457cULL ^ (static_cast<uint64_t>(0xb40000a0ULL) << 13);
    acc = (acc + a1 + 0xf9400008ULL) ^ 0x1e7c18ULL;
    acc ^= (acc >> 17) * 0x001cULL;
    return acc;
}

// FDE #2693 | PC: 0x124598 | FDE: 0x1e7c30 | Size: 256 bytes
// Khung tháo gỡ #2693 | Địa chỉ PC: 0x124598 | Địa chỉ FDE: 0x1e7c30 | Kích thước: 256 bytes
//   0x124598: D10203FF  sub      sp, sp, #0x80
//   0x12459c: A9026FFC  stp      x28, x27, [sp, #0x20]
//   0x1245a0: A90367FA  stp      x26, x25, [sp, #0x30]
//   0x1245a4: A9045FF8  stp      x24, x23, [sp, #0x40]
static inline uint64_t fde_func_2693_0x124598(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x124598ULL ^ (static_cast<uint64_t>(0xd10203ffULL) << 13);
    acc = (acc + a1 + 0xa9026ffcULL) ^ 0x1e7c30ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #2694 | PC: 0x124afc | FDE: 0x1e7c60 | Size: 256 bytes
// Khung tháo gỡ #2694 | Địa chỉ PC: 0x124afc | Địa chỉ FDE: 0x1e7c60 | Kích thước: 256 bytes
//   0x124afc: F81B0FF9  str      x25, [sp, #-0x50]!
//   0x124b00: A9015FF8  stp      x24, x23, [sp, #0x10]
//   0x124b04: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x124b08: A9034FF4  stp      x20, x19, [sp, #0x30]
static inline uint64_t fde_func_2694_0x124afc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x124afcULL ^ (static_cast<uint64_t>(0xf81b0ff9ULL) << 13);
    acc = (acc + a1 + 0xa9015ff8ULL) ^ 0x1e7c60ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #2695 | PC: 0x124c4c | FDE: 0x1e7c88 | Size: 256 bytes
// Khung tháo gỡ #2695 | Địa chỉ PC: 0x124c4c | Địa chỉ FDE: 0x1e7c88 | Kích thước: 256 bytes
//   0x124c4c: D10283FF  sub      sp, sp, #0xa0
//   0x124c50: A9065FF8  stp      x24, x23, [sp, #0x60]
//   0x124c54: A90757F6  stp      x22, x21, [sp, #0x70]
//   0x124c58: A9084FF4  stp      x20, x19, [sp, #0x80]
static inline uint64_t fde_func_2695_0x124c4c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x124c4cULL ^ (static_cast<uint64_t>(0xd10283ffULL) << 13);
    acc = (acc + a1 + 0xa9065ff8ULL) ^ 0x1e7c88ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #2696 | PC: 0x124e44 | FDE: 0x1e7cb0 | Size: 256 bytes
// Khung tháo gỡ #2696 | Địa chỉ PC: 0x124e44 | Địa chỉ FDE: 0x1e7cb0 | Kích thước: 256 bytes
//   0x124e44: D104C3FF  sub      sp, sp, #0x130
//   0x124e48: FD005BEA  str      d10, [sp, #0xb0]
//   0x124e4c: 6D0C23E9  stp      d9, d8, [sp, #0xc0]
//   0x124e50: A90D6FFC  stp      x28, x27, [sp, #0xd0]
static inline uint64_t fde_func_2696_0x124e44(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x124e44ULL ^ (static_cast<uint64_t>(0xd104c3ffULL) << 13);
    acc = (acc + a1 + 0xfd005beaULL) ^ 0x1e7cb0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #2697 | PC: 0x1263e4 | FDE: 0x1e7ce8 | Size: 248 bytes
// Khung tháo gỡ #2697 | Địa chỉ PC: 0x1263e4 | Địa chỉ FDE: 0x1e7ce8 | Kích thước: 248 bytes
//   0x1263e4: D10503FF  sub      sp, sp, #0x140
//   0x1263e8: A91157FC  stp      x28, x21, [sp, #0x110]
//   0x1263ec: A9124FF4  stp      x20, x19, [sp, #0x120]
//   0x1263f0: A9137BFD  stp      x29, x30, [sp, #0x130]
static inline uint64_t fde_func_2697_0x1263e4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1263e4ULL ^ (static_cast<uint64_t>(0xd10503ffULL) << 13);
    acc = (acc + a1 + 0xa91157fcULL) ^ 0x1e7ce8ULL;
    acc ^= (acc >> 17) * 0x00f8ULL;
    return acc;
}

// FDE #2698 | PC: 0x1264dc | FDE: 0x1e7d10 | Size: 256 bytes
// Khung tháo gỡ #2698 | Địa chỉ PC: 0x1264dc | Địa chỉ FDE: 0x1e7d10 | Kích thước: 256 bytes
//   0x1264dc: D10183FF  sub      sp, sp, #0x60
//   0x1264e0: F90013F7  str      x23, [sp, #0x20]
//   0x1264e4: A90357F6  stp      x22, x21, [sp, #0x30]
//   0x1264e8: A9044FF4  stp      x20, x19, [sp, #0x40]
static inline uint64_t fde_func_2698_0x1264dc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1264dcULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xf90013f7ULL) ^ 0x1e7d10ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #2699 | PC: 0x1265fc | FDE: 0x1e7d38 | Size: 256 bytes
// Khung tháo gỡ #2699 | Địa chỉ PC: 0x1265fc | Địa chỉ FDE: 0x1e7d38 | Kích thước: 256 bytes
//   0x1265fc: D10203FF  sub      sp, sp, #0x80
//   0x126600: F9002BF5  str      x21, [sp, #0x50]
//   0x126604: A9064FF4  stp      x20, x19, [sp, #0x60]
//   0x126608: A9077BFD  stp      x29, x30, [sp, #0x70]
static inline uint64_t fde_func_2699_0x1265fc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1265fcULL ^ (static_cast<uint64_t>(0xd10203ffULL) << 13);
    acc = (acc + a1 + 0xf9002bf5ULL) ^ 0x1e7d38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #2700 | PC: 0x126714 | FDE: 0x1e7d58 | Size: 160 bytes
// Khung tháo gỡ #2700 | Địa chỉ PC: 0x126714 | Địa chỉ FDE: 0x1e7d58 | Kích thước: 160 bytes
//   0x126714: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x126718: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x12671c: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x126720: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_2700_0x126714(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x126714ULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1e7d58ULL;
    acc ^= (acc >> 17) * 0x00a0ULL;
    return acc;
}

// FDE #2701 | PC: 0x1267b4 | FDE: 0x1e7d78 | Size: 256 bytes
// Khung tháo gỡ #2701 | Địa chỉ PC: 0x1267b4 | Địa chỉ FDE: 0x1e7d78 | Kích thước: 256 bytes
//   0x1267b4: D10303FF  sub      sp, sp, #0xc0
//   0x1267b8: A90A4FF4  stp      x20, x19, [sp, #0xa0]
//   0x1267bc: A90B7BFD  stp      x29, x30, [sp, #0xb0]
//   0x1267c0: 9102C3FD  add      x29, sp, #0xb0
static inline uint64_t fde_func_2701_0x1267b4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1267b4ULL ^ (static_cast<uint64_t>(0xd10303ffULL) << 13);
    acc = (acc + a1 + 0xa90a4ff4ULL) ^ 0x1e7d78ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #2702 | PC: 0x1268d0 | FDE: 0x1e7d98 | Size: 36 bytes
// Khung tháo gỡ #2702 | Địa chỉ PC: 0x1268d0 | Địa chỉ FDE: 0x1e7d98 | Kích thước: 36 bytes
//   0x1268d0: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x1268d4: 910003FD  mov      x29, sp
//   0x1268d8: B0000501  adrp     x1, #0x1c7000
//   0x1268dc: 9135E821  add      x1, x1, #0xd7a
static inline uint64_t fde_func_2702_0x1268d0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1268d0ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1e7d98ULL;
    acc ^= (acc >> 17) * 0x0024ULL;
    return acc;
}

// FDE #2703 | PC: 0x1268f4 | FDE: 0x1e7db8 | Size: 148 bytes [_Py_convert_optional_to_ssize_t]
// Khung tháo gỡ #2703 | Địa chỉ PC: 0x1268f4 | Địa chỉ FDE: 0x1e7db8 | Kích thước: 148 bytes
//   0x1268f4: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x1268f8: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x1268fc: 910043FD  add      x29, sp, #0x10
//   0x126900: B00006C8  adrp     x8, #0x1ff000
static inline uint64_t fde_func_2703_0x1268f4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1268f4ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1e7db8ULL;
    acc ^= (acc >> 17) * 0x0094ULL;
    return acc;
}

// FDE #2704 | PC: 0x126988 | FDE: 0x1e7dd8 | Size: 240 bytes [Py_BuildValue]
// Khung tháo gỡ #2704 | Địa chỉ PC: 0x126988 | Địa chỉ FDE: 0x1e7dd8 | Kích thước: 240 bytes
//   0x126988: D10543FF  sub      sp, sp, #0x150
//   0x12698c: A9134FFC  stp      x28, x19, [sp, #0x130]
//   0x126990: A9147BFD  stp      x29, x30, [sp, #0x140]
//   0x126994: 910503FD  add      x29, sp, #0x140
static inline uint64_t fde_func_2704_0x126988(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x126988ULL ^ (static_cast<uint64_t>(0xd10543ffULL) << 13);
    acc = (acc + a1 + 0xa9134ffcULL) ^ 0x1e7dd8ULL;
    acc ^= (acc >> 17) * 0x00f0ULL;
    return acc;
}

// FDE #2705 | PC: 0x126a78 | FDE: 0x1e7df8 | Size: 244 bytes [_Py_BuildValue_SizeT]
// Khung tháo gỡ #2705 | Địa chỉ PC: 0x126a78 | Địa chỉ FDE: 0x1e7df8 | Kích thước: 244 bytes
//   0x126a78: D10543FF  sub      sp, sp, #0x150
//   0x126a7c: A9134FFC  stp      x28, x19, [sp, #0x130]
//   0x126a80: A9147BFD  stp      x29, x30, [sp, #0x140]
//   0x126a84: 910503FD  add      x29, sp, #0x140
static inline uint64_t fde_func_2705_0x126a78(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x126a78ULL ^ (static_cast<uint64_t>(0xd10543ffULL) << 13);
    acc = (acc + a1 + 0xa9134ffcULL) ^ 0x1e7df8ULL;
    acc ^= (acc >> 17) * 0x00f4ULL;
    return acc;
}

// FDE #2706 | PC: 0x126b6c | FDE: 0x1e7e18 | Size: 172 bytes [Py_VaBuildValue]
// Khung tháo gỡ #2706 | Địa chỉ PC: 0x126b6c | Địa chỉ FDE: 0x1e7e18 | Kích thước: 172 bytes
//   0x126b6c: D101C3FF  sub      sp, sp, #0x70
//   0x126b70: F9002BF3  str      x19, [sp, #0x50]
//   0x126b74: A9067BFD  stp      x29, x30, [sp, #0x60]
//   0x126b78: 910183FD  add      x29, sp, #0x60
static inline uint64_t fde_func_2706_0x126b6c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x126b6cULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xf9002bf3ULL) ^ 0x1e7e18ULL;
    acc ^= (acc >> 17) * 0x00acULL;
    return acc;
}

// FDE #2707 | PC: 0x126c18 | FDE: 0x1e7e38 | Size: 176 bytes [_Py_VaBuildValue_SizeT]
// Khung tháo gỡ #2707 | Địa chỉ PC: 0x126c18 | Địa chỉ FDE: 0x1e7e38 | Kích thước: 176 bytes
//   0x126c18: D101C3FF  sub      sp, sp, #0x70
//   0x126c1c: F9002BF3  str      x19, [sp, #0x50]
//   0x126c20: A9067BFD  stp      x29, x30, [sp, #0x60]
//   0x126c24: 910183FD  add      x29, sp, #0x60
static inline uint64_t fde_func_2707_0x126c18(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x126c18ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xf9002bf3ULL) ^ 0x1e7e38ULL;
    acc ^= (acc >> 17) * 0x00b0ULL;
    return acc;
}

// FDE #2708 | PC: 0x126cc8 | FDE: 0x1e7e58 | Size: 88 bytes [_Py_VaBuildStack]
// Khung tháo gỡ #2708 | Địa chỉ PC: 0x126cc8 | Địa chỉ FDE: 0x1e7e58 | Kích thước: 88 bytes
//   0x126cc8: D10143FF  sub      sp, sp, #0x50
//   0x126ccc: F9001BF3  str      x19, [sp, #0x30]
//   0x126cd0: A9047BFD  stp      x29, x30, [sp, #0x40]
//   0x126cd4: 910103FD  add      x29, sp, #0x40
static inline uint64_t fde_func_2708_0x126cc8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x126cc8ULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xf9001bf3ULL) ^ 0x1e7e58ULL;
    acc ^= (acc >> 17) * 0x0058ULL;
    return acc;
}

// FDE #2709 | PC: 0x126d20 | FDE: 0x1e7e78 | Size: 256 bytes
// Khung tháo gỡ #2709 | Địa chỉ PC: 0x126d20 | Địa chỉ FDE: 0x1e7e78 | Kích thước: 256 bytes
//   0x126d20: D10243FF  sub      sp, sp, #0x90
//   0x126d24: F9001BFB  str      x27, [sp, #0x30]
//   0x126d28: A90467FA  stp      x26, x25, [sp, #0x40]
//   0x126d2c: A9055FF8  stp      x24, x23, [sp, #0x50]
static inline uint64_t fde_func_2709_0x126d20(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x126d20ULL ^ (static_cast<uint64_t>(0xd10243ffULL) << 13);
    acc = (acc + a1 + 0xf9001bfbULL) ^ 0x1e7e78ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #2710 | PC: 0x126ebc | FDE: 0x1e7ea8 | Size: 88 bytes [_Py_VaBuildStack_SizeT]
// Khung tháo gỡ #2710 | Địa chỉ PC: 0x126ebc | Địa chỉ FDE: 0x1e7ea8 | Kích thước: 88 bytes
//   0x126ebc: D10143FF  sub      sp, sp, #0x50
//   0x126ec0: F9001BF3  str      x19, [sp, #0x30]
//   0x126ec4: A9047BFD  stp      x29, x30, [sp, #0x40]
//   0x126ec8: 910103FD  add      x29, sp, #0x40
static inline uint64_t fde_func_2710_0x126ebc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x126ebcULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xf9001bf3ULL) ^ 0x1e7ea8ULL;
    acc ^= (acc >> 17) * 0x0058ULL;
    return acc;
}

// FDE #2711 | PC: 0x126f14 | FDE: 0x1e7ec8 | Size: 220 bytes [PyModule_AddObjectRef]
// Khung tháo gỡ #2711 | Địa chỉ PC: 0x126f14 | Địa chỉ FDE: 0x1e7ec8 | Kích thước: 220 bytes
//   0x126f14: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x126f18: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x126f1c: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x126f20: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_2711_0x126f14(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x126f14ULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1e7ec8ULL;
    acc ^= (acc >> 17) * 0x00dcULL;
    return acc;
}

// FDE #2712 | PC: 0x126ff0 | FDE: 0x1e7ee8 | Size: 68 bytes [PyModule_AddObject]
// Khung tháo gỡ #2712 | Địa chỉ PC: 0x126ff0 | Địa chỉ FDE: 0x1e7ee8 | Kích thước: 68 bytes
//   0x126ff0: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x126ff4: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x126ff8: 910043FD  add      x29, sp, #0x10
//   0x126ffc: AA0203F3  mov      x19, x2
static inline uint64_t fde_func_2712_0x126ff0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x126ff0ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1e7ee8ULL;
    acc ^= (acc >> 17) * 0x0044ULL;
    return acc;
}

// FDE #2713 | PC: 0x127034 | FDE: 0x1e7f08 | Size: 112 bytes [PyModule_AddIntConstant]
// Khung tháo gỡ #2713 | Địa chỉ PC: 0x127034 | Địa chỉ FDE: 0x1e7f08 | Kích thước: 112 bytes
//   0x127034: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x127038: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x12703c: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x127040: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_2713_0x127034(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x127034ULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1e7f08ULL;
    acc ^= (acc >> 17) * 0x0070ULL;
    return acc;
}

// FDE #2714 | PC: 0x1270a4 | FDE: 0x1e7f28 | Size: 112 bytes [PyModule_AddStringConstant]
// Khung tháo gỡ #2714 | Địa chỉ PC: 0x1270a4 | Địa chỉ FDE: 0x1e7f28 | Kích thước: 112 bytes
//   0x1270a4: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x1270a8: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x1270ac: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x1270b0: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_2714_0x1270a4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1270a4ULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1e7f28ULL;
    acc ^= (acc >> 17) * 0x0070ULL;
    return acc;
}

// FDE #2715 | PC: 0x127114 | FDE: 0x1e7f48 | Size: 80 bytes [PyModule_AddType]
// Khung tháo gỡ #2715 | Địa chỉ PC: 0x127114 | Địa chỉ FDE: 0x1e7f48 | Kích thước: 80 bytes
//   0x127114: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x127118: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x12711c: 910043FD  add      x29, sp, #0x10
//   0x127120: AA0003F4  mov      x20, x0
static inline uint64_t fde_func_2715_0x127114(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x127114ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1e7f48ULL;
    acc ^= (acc >> 17) * 0x0050ULL;
    return acc;
}

// FDE #2716 | PC: 0x127164 | FDE: 0x1e7f68 | Size: 184 bytes
// Khung tháo gỡ #2716 | Địa chỉ PC: 0x127164 | Địa chỉ FDE: 0x1e7f68 | Kích thước: 184 bytes
//   0x127164: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x127168: 910003FD  mov      x29, sp
//   0x12716c: 3940000B  ldrb     w11, [x0]
//   0x127170: 6B21017F  cmp      w11, w1, uxtb
static inline uint64_t fde_func_2716_0x127164(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x127164ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1e7f68ULL;
    acc ^= (acc >> 17) * 0x00b8ULL;
    return acc;
}

// FDE #2717 | PC: 0x12721c | FDE: 0x1e7f88 | Size: 256 bytes
// Khung tháo gỡ #2717 | Địa chỉ PC: 0x12721c | Địa chỉ FDE: 0x1e7f88 | Kích thước: 256 bytes
//   0x12721c: D101C3FF  sub      sp, sp, #0x70
//   0x127220: A9016FFC  stp      x28, x27, [sp, #0x10]
//   0x127224: A90267FA  stp      x26, x25, [sp, #0x20]
//   0x127228: A9035FF8  stp      x24, x23, [sp, #0x30]
static inline uint64_t fde_func_2717_0x12721c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x12721cULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xa9016ffcULL) ^ 0x1e7f88ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #2718 | PC: 0x127ba4 | FDE: 0x1e7fb8 | Size: 256 bytes
// Khung tháo gỡ #2718 | Địa chỉ PC: 0x127ba4 | Địa chỉ FDE: 0x1e7fb8 | Kích thước: 256 bytes
//   0x127ba4: F81B0FF9  str      x25, [sp, #-0x50]!
//   0x127ba8: A9015FF8  stp      x24, x23, [sp, #0x10]
//   0x127bac: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x127bb0: A9034FF4  stp      x20, x19, [sp, #0x30]
static inline uint64_t fde_func_2718_0x127ba4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x127ba4ULL ^ (static_cast<uint64_t>(0xf81b0ff9ULL) << 13);
    acc = (acc + a1 + 0xa9015ff8ULL) ^ 0x1e7fb8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #2719 | PC: 0x127ce0 | FDE: 0x1e7fe0 | Size: 256 bytes
// Khung tháo gỡ #2719 | Địa chỉ PC: 0x127ce0 | Địa chỉ FDE: 0x1e7fe0 | Kích thước: 256 bytes
//   0x127ce0: D10203FF  sub      sp, sp, #0x80
//   0x127ce4: F90013FB  str      x27, [sp, #0x20]
//   0x127ce8: A90367FA  stp      x26, x25, [sp, #0x30]
//   0x127cec: A9045FF8  stp      x24, x23, [sp, #0x40]
static inline uint64_t fde_func_2719_0x127ce0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x127ce0ULL ^ (static_cast<uint64_t>(0xd10203ffULL) << 13);
    acc = (acc + a1 + 0xf90013fbULL) ^ 0x1e7fe0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #2720 | PC: 0x127e30 | FDE: 0x1e8010 | Size: 208 bytes [PyOS_snprintf]
// Khung tháo gỡ #2720 | Địa chỉ PC: 0x127e30 | Địa chỉ FDE: 0x1e8010 | Kích thước: 208 bytes
//   0x127e30: D10543FF  sub      sp, sp, #0x150
//   0x127e34: A91257FC  stp      x28, x21, [sp, #0x120]
//   0x127e38: A9134FF4  stp      x20, x19, [sp, #0x130]
//   0x127e3c: A9147BFD  stp      x29, x30, [sp, #0x140]
static inline uint64_t fde_func_2720_0x127e30(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x127e30ULL ^ (static_cast<uint64_t>(0xd10543ffULL) << 13);
    acc = (acc + a1 + 0xa91257fcULL) ^ 0x1e8010ULL;
    acc ^= (acc >> 17) * 0x00d0ULL;
    return acc;
}

// FDE #2721 | PC: 0x127f00 | FDE: 0x1e8038 | Size: 136 bytes [PyOS_vsnprintf]
// Khung tháo gỡ #2721 | Địa chỉ PC: 0x127f00 | Địa chỉ FDE: 0x1e8038 | Kích thước: 136 bytes
//   0x127f00: D10183FF  sub      sp, sp, #0x60
//   0x127f04: F9001BF5  str      x21, [sp, #0x30]
//   0x127f08: A9044FF4  stp      x20, x19, [sp, #0x40]
//   0x127f0c: A9057BFD  stp      x29, x30, [sp, #0x50]
static inline uint64_t fde_func_2721_0x127f00(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x127f00ULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xf9001bf5ULL) ^ 0x1e8038ULL;
    acc ^= (acc >> 17) * 0x0088ULL;
    return acc;
}

// FDE #2722 | PC: 0x127f88 | FDE: 0x1e8058 | Size: 256 bytes [PyOS_strtoul]
// Khung tháo gỡ #2722 | Địa chỉ PC: 0x127f88 | Địa chỉ FDE: 0x1e8058 | Kích thước: 256 bytes
//   0x127f88: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x127f8c: 910003FD  mov      x29, sp
//   0x127f90: 900006C8  adrp     x8, #0x1ff000
//   0x127f94: 3940000A  ldrb     w10, [x0]
static inline uint64_t fde_func_2722_0x127f88(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x127f88ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1e8058ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #2723 | PC: 0x128248 | FDE: 0x1e8078 | Size: 152 bytes [PyOS_strtol]
// Khung tháo gỡ #2723 | Địa chỉ PC: 0x128248 | Địa chỉ FDE: 0x1e8078 | Kích thước: 152 bytes
//   0x128248: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x12824c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x128250: 910043FD  add      x29, sp, #0x10
//   0x128254: 39400013  ldrb     w19, [x0]
static inline uint64_t fde_func_2723_0x128248(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x128248ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1e8078ULL;
    acc ^= (acc >> 17) * 0x0098ULL;
    return acc;
}

// FDE #2724 | PC: 0x1282e0 | FDE: 0x1e8098 | Size: 192 bytes [_PyPathConfig_ClearGlobal]
// Khung tháo gỡ #2724 | Địa chỉ PC: 0x1282e0 | Địa chỉ FDE: 0x1e8098 | Kích thước: 192 bytes
//   0x1282e0: D10203FF  sub      sp, sp, #0x80
//   0x1282e4: A9064FF4  stp      x20, x19, [sp, #0x60]
//   0x1282e8: A9077BFD  stp      x29, x30, [sp, #0x70]
//   0x1282ec: 9101C3FD  add      x29, sp, #0x70
static inline uint64_t fde_func_2724_0x1282e0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1282e0ULL ^ (static_cast<uint64_t>(0xd10203ffULL) << 13);
    acc = (acc + a1 + 0xa9064ff4ULL) ^ 0x1e8098ULL;
    acc ^= (acc >> 17) * 0x00c0ULL;
    return acc;
}

// FDE #2725 | PC: 0x1283a0 | FDE: 0x1e80b8 | Size: 256 bytes [_PyPathConfig_AsDict]
// Khung tháo gỡ #2725 | Địa chỉ PC: 0x1283a0 | Địa chỉ FDE: 0x1e80b8 | Kích thước: 256 bytes
//   0x1283a0: F81C0FF7  str      x23, [sp, #-0x40]!
//   0x1283a4: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x1283a8: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x1283ac: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_2725_0x1283a0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1283a0ULL ^ (static_cast<uint64_t>(0xf81c0ff7ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x1e80b8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #2726 | PC: 0x128650 | FDE: 0x1e80e0 | Size: 16 bytes [_PyConfig_WritePathConfig]
// Khung tháo gỡ #2726 | Địa chỉ PC: 0x128650 | Địa chỉ FDE: 0x1e80e0 | Kích thước: 16 bytes
//   0x128650: AA0003E1  mov      x1, x0
//   0x128654: F00006A0  adrp     x0, #0x1ff000
//   0x128658: F9444400  ldr      x0, [x0, #0x888]
//   0x12865c: 14000001  b        #0x128660
static inline uint64_t fde_func_2726_0x128650(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x128650ULL ^ (static_cast<uint64_t>(0xaa0003e1ULL) << 13);
    acc = (acc + a1 + 0xf00006a0ULL) ^ 0x1e80e0ULL;
    acc ^= (acc >> 17) * 0x0010ULL;
    return acc;
}

// FDE #2727 | PC: 0x128660 | FDE: 0x1e80f8 | Size: 256 bytes
// Khung tháo gỡ #2727 | Địa chỉ PC: 0x128660 | Địa chỉ FDE: 0x1e80f8 | Kích thước: 256 bytes
//   0x128660: D10243FF  sub      sp, sp, #0x90
//   0x128664: A9036FFC  stp      x28, x27, [sp, #0x30]
//   0x128668: A90467FA  stp      x26, x25, [sp, #0x40]
//   0x12866c: A9055FF8  stp      x24, x23, [sp, #0x50]
static inline uint64_t fde_func_2727_0x128660(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x128660ULL ^ (static_cast<uint64_t>(0xd10243ffULL) << 13);
    acc = (acc + a1 + 0xa9036ffcULL) ^ 0x1e80f8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #2728 | PC: 0x1288fc | FDE: 0x1e8128 | Size: 256 bytes [_PyConfig_InitPathConfig]
// Khung tháo gỡ #2728 | Địa chỉ PC: 0x1288fc | Địa chỉ FDE: 0x1e8128 | Kích thước: 256 bytes
//   0x1288fc: D10483FF  sub      sp, sp, #0x120
//   0x128900: A90C6FFC  stp      x28, x27, [sp, #0xc0]
//   0x128904: A90D67FA  stp      x26, x25, [sp, #0xd0]
//   0x128908: A90E5FF8  stp      x24, x23, [sp, #0xe0]
static inline uint64_t fde_func_2728_0x1288fc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1288fcULL ^ (static_cast<uint64_t>(0xd10483ffULL) << 13);
    acc = (acc + a1 + 0xa90c6ffcULL) ^ 0x1e8128ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #2729 | PC: 0x128da0 | FDE: 0x1e8158 | Size: 256 bytes [Py_SetPath]
// Khung tháo gỡ #2729 | Địa chỉ PC: 0x128da0 | Địa chỉ FDE: 0x1e8158 | Kích thước: 256 bytes
//   0x128da0: D10183FF  sub      sp, sp, #0x60
//   0x128da4: A90357F6  stp      x22, x21, [sp, #0x30]
//   0x128da8: A9044FF4  stp      x20, x19, [sp, #0x40]
//   0x128dac: A9057BFD  stp      x29, x30, [sp, #0x50]
static inline uint64_t fde_func_2729_0x128da0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x128da0ULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xa90357f6ULL) ^ 0x1e8158ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #2730 | PC: 0x128edc | FDE: 0x1e8180 | Size: 20 bytes
// Khung tháo gỡ #2730 | Địa chỉ PC: 0x128edc | Địa chỉ FDE: 0x1e8180 | Kích thước: 20 bytes
//   0x128edc: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x128ee0: 910003FD  mov      x29, sp
//   0x128ee4: F0000481  adrp     x1, #0x1bb000
//   0x128ee8: 913B8421  add      x1, x1, #0xee1
static inline uint64_t fde_func_2730_0x128edc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x128edcULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1e8180ULL;
    acc ^= (acc >> 17) * 0x0014ULL;
    return acc;
}

// FDE #2731 | PC: 0x128ef0 | FDE: 0x1e81a0 | Size: 152 bytes [Py_SetPythonHome]
// Khung tháo gỡ #2731 | Địa chỉ PC: 0x128ef0 | Địa chỉ FDE: 0x1e81a0 | Kích thước: 152 bytes
//   0x128ef0: D10183FF  sub      sp, sp, #0x60
//   0x128ef4: F9001BF5  str      x21, [sp, #0x30]
//   0x128ef8: A9044FF4  stp      x20, x19, [sp, #0x40]
//   0x128efc: A9057BFD  stp      x29, x30, [sp, #0x50]
static inline uint64_t fde_func_2731_0x128ef0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x128ef0ULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xf9001bf5ULL) ^ 0x1e81a0ULL;
    acc ^= (acc >> 17) * 0x0098ULL;
    return acc;
}

// FDE #2732 | PC: 0x128f88 | FDE: 0x1e81c0 | Size: 160 bytes [Py_SetProgramName]
// Khung tháo gỡ #2732 | Địa chỉ PC: 0x128f88 | Địa chỉ FDE: 0x1e81c0 | Kích thước: 160 bytes
//   0x128f88: D10183FF  sub      sp, sp, #0x60
//   0x128f8c: F9001BF5  str      x21, [sp, #0x30]
//   0x128f90: A9044FF4  stp      x20, x19, [sp, #0x40]
//   0x128f94: A9057BFD  stp      x29, x30, [sp, #0x50]
static inline uint64_t fde_func_2732_0x128f88(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x128f88ULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xf9001bf5ULL) ^ 0x1e81c0ULL;
    acc ^= (acc >> 17) * 0x00a0ULL;
    return acc;
}

// FDE #2733 | PC: 0x129028 | FDE: 0x1e81e0 | Size: 160 bytes [_Py_SetProgramFullPath]
// Khung tháo gỡ #2733 | Địa chỉ PC: 0x129028 | Địa chỉ FDE: 0x1e81e0 | Kích thước: 160 bytes
//   0x129028: D10183FF  sub      sp, sp, #0x60
//   0x12902c: F9001BF5  str      x21, [sp, #0x30]
//   0x129030: A9044FF4  stp      x20, x19, [sp, #0x40]
//   0x129034: A9057BFD  stp      x29, x30, [sp, #0x50]
static inline uint64_t fde_func_2733_0x129028(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x129028ULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xf9001bf5ULL) ^ 0x1e81e0ULL;
    acc ^= (acc >> 17) * 0x00a0ULL;
    return acc;
}

// FDE #2734 | PC: 0x1290c8 | FDE: 0x1e8200 | Size: 16 bytes [Py_GetPath]
// Khung tháo gỡ #2734 | Địa chỉ PC: 0x1290c8 | Địa chỉ FDE: 0x1e8200 | Kích thước: 16 bytes
//   0x1290c8: D00006A8  adrp     x8, #0x1ff000
//   0x1290cc: F9444508  ldr      x8, [x8, #0x888]
//   0x1290d0: F9400D00  ldr      x0, [x8, #0x18]
//   0x1290d4: D65F03C0  ret      
static inline uint64_t fde_func_2734_0x1290c8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1290c8ULL ^ (static_cast<uint64_t>(0xd00006a8ULL) << 13);
    acc = (acc + a1 + 0xf9444508ULL) ^ 0x1e8200ULL;
    acc ^= (acc >> 17) * 0x0010ULL;
    return acc;
}

// FDE #2735 | PC: 0x1290d8 | FDE: 0x1e8218 | Size: 16 bytes [Py_GetPrefix]
// Khung tháo gỡ #2735 | Địa chỉ PC: 0x1290d8 | Địa chỉ FDE: 0x1e8218 | Kích thước: 16 bytes
//   0x1290d8: D00006A8  adrp     x8, #0x1ff000
//   0x1290dc: F9444508  ldr      x8, [x8, #0x888]
//   0x1290e0: F9400500  ldr      x0, [x8, #8]
//   0x1290e4: D65F03C0  ret      
static inline uint64_t fde_func_2735_0x1290d8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1290d8ULL ^ (static_cast<uint64_t>(0xd00006a8ULL) << 13);
    acc = (acc + a1 + 0xf9444508ULL) ^ 0x1e8218ULL;
    acc ^= (acc >> 17) * 0x0010ULL;
    return acc;
}

// FDE #2736 | PC: 0x1290e8 | FDE: 0x1e8230 | Size: 16 bytes [Py_GetExecPrefix]
// Khung tháo gỡ #2736 | Địa chỉ PC: 0x1290e8 | Địa chỉ FDE: 0x1e8230 | Kích thước: 16 bytes
//   0x1290e8: D00006A8  adrp     x8, #0x1ff000
//   0x1290ec: F9444508  ldr      x8, [x8, #0x888]
//   0x1290f0: F9400900  ldr      x0, [x8, #0x10]
//   0x1290f4: D65F03C0  ret      
static inline uint64_t fde_func_2736_0x1290e8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1290e8ULL ^ (static_cast<uint64_t>(0xd00006a8ULL) << 13);
    acc = (acc + a1 + 0xf9444508ULL) ^ 0x1e8230ULL;
    acc ^= (acc >> 17) * 0x0010ULL;
    return acc;
}

// FDE #2737 | PC: 0x1290f8 | FDE: 0x1e8248 | Size: 16 bytes [Py_GetProgramFullPath]
// Khung tháo gỡ #2737 | Địa chỉ PC: 0x1290f8 | Địa chỉ FDE: 0x1e8248 | Kích thước: 16 bytes
//   0x1290f8: D00006A8  adrp     x8, #0x1ff000
//   0x1290fc: F9444508  ldr      x8, [x8, #0x888]
//   0x129100: F9400100  ldr      x0, [x8]
//   0x129104: D65F03C0  ret      
static inline uint64_t fde_func_2737_0x1290f8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1290f8ULL ^ (static_cast<uint64_t>(0xd00006a8ULL) << 13);
    acc = (acc + a1 + 0xf9444508ULL) ^ 0x1e8248ULL;
    acc ^= (acc >> 17) * 0x0010ULL;
    return acc;
}

// FDE #2738 | PC: 0x129108 | FDE: 0x1e8260 | Size: 16 bytes [Py_GetPythonHome]
// Khung tháo gỡ #2738 | Địa chỉ PC: 0x129108 | Địa chỉ FDE: 0x1e8260 | Kích thước: 16 bytes
//   0x129108: D00006A8  adrp     x8, #0x1ff000
//   0x12910c: F9444508  ldr      x8, [x8, #0x888]
//   0x129110: F9401500  ldr      x0, [x8, #0x28]
//   0x129114: D65F03C0  ret      
static inline uint64_t fde_func_2738_0x129108(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x129108ULL ^ (static_cast<uint64_t>(0xd00006a8ULL) << 13);
    acc = (acc + a1 + 0xf9444508ULL) ^ 0x1e8260ULL;
    acc ^= (acc >> 17) * 0x0010ULL;
    return acc;
}

// FDE #2739 | PC: 0x129118 | FDE: 0x1e8278 | Size: 16 bytes [Py_GetProgramName]
// Khung tháo gỡ #2739 | Địa chỉ PC: 0x129118 | Địa chỉ FDE: 0x1e8278 | Kích thước: 16 bytes
//   0x129118: D00006A8  adrp     x8, #0x1ff000
//   0x12911c: F9444508  ldr      x8, [x8, #0x888]
//   0x129120: F9401100  ldr      x0, [x8, #0x20]
//   0x129124: D65F03C0  ret      
static inline uint64_t fde_func_2739_0x129118(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x129118ULL ^ (static_cast<uint64_t>(0xd00006a8ULL) << 13);
    acc = (acc + a1 + 0xf9444508ULL) ^ 0x1e8278ULL;
    acc ^= (acc >> 17) * 0x0010ULL;
    return acc;
}

// FDE #2740 | PC: 0x129128 | FDE: 0x1e8290 | Size: 256 bytes [_PyPathConfig_ComputeSysPath0]
// Khung tháo gỡ #2740 | Địa chỉ PC: 0x129128 | Địa chỉ FDE: 0x1e8290 | Kích thước: 256 bytes
//   0x129128: F81C0FFC  str      x28, [sp, #-0x40]!
//   0x12912c: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x129130: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x129134: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_2740_0x129128(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x129128ULL ^ (static_cast<uint64_t>(0xf81c0ffcULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x1e8290ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #2741 | PC: 0x129318 | FDE: 0x1e82b8 | Size: 256 bytes [_Py_FindEnvConfigValue]
// Khung tháo gỡ #2741 | Địa chỉ PC: 0x129318 | Địa chỉ FDE: 0x1e82b8 | Kích thước: 256 bytes
//   0x129318: A9BA6FFC  stp      x28, x27, [sp, #-0x60]!
//   0x12931c: A90167FA  stp      x26, x25, [sp, #0x10]
//   0x129320: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x129324: A90357F6  stp      x22, x21, [sp, #0x30]
static inline uint64_t fde_func_2741_0x129318(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x129318ULL ^ (static_cast<uint64_t>(0xa9ba6ffcULL) << 13);
    acc = (acc + a1 + 0xa90167faULL) ^ 0x1e82b8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #2742 | PC: 0x1294dc | FDE: 0x1e82e8 | Size: 104 bytes [_Py_ClearFileSystemEncoding]
// Khung tháo gỡ #2742 | Địa chỉ PC: 0x1294dc | Địa chỉ FDE: 0x1e82e8 | Kích thước: 104 bytes
//   0x1294dc: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x1294e0: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x1294e4: 910043FD  add      x29, sp, #0x10
//   0x1294e8: D00006A8  adrp     x8, #0x1ff000
static inline uint64_t fde_func_2742_0x1294dc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1294dcULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1e82e8ULL;
    acc ^= (acc >> 17) * 0x0068ULL;
    return acc;
}

// FDE #2743 | PC: 0x129544 | FDE: 0x1e8308 | Size: 188 bytes [_Py_SetFileSystemEncoding]
// Khung tháo gỡ #2743 | Địa chỉ PC: 0x129544 | Địa chỉ FDE: 0x1e8308 | Kích thước: 188 bytes
//   0x129544: A9BC5FF8  stp      x24, x23, [sp, #-0x40]!
//   0x129548: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x12954c: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x129550: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_2743_0x129544(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x129544ULL ^ (static_cast<uint64_t>(0xa9bc5ff8ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x1e8308ULL;
    acc ^= (acc >> 17) * 0x00bcULL;
    return acc;
}

// FDE #2744 | PC: 0x129600 | FDE: 0x1e8330 | Size: 256 bytes [_PyArgv_AsWstrList]
// Khung tháo gỡ #2744 | Địa chỉ PC: 0x129600 | Địa chỉ FDE: 0x1e8330 | Kích thước: 256 bytes
//   0x129600: D10183FF  sub      sp, sp, #0x60
//   0x129604: F90013F7  str      x23, [sp, #0x20]
//   0x129608: A90357F6  stp      x22, x21, [sp, #0x30]
//   0x12960c: A9044FF4  stp      x20, x19, [sp, #0x40]
static inline uint64_t fde_func_2744_0x129600(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x129600ULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xf90013f7ULL) ^ 0x1e8330ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #2745 | PC: 0x129760 | FDE: 0x1e8358 | Size: 36 bytes [_PyPreCmdline_Clear]
// Khung tháo gỡ #2745 | Địa chỉ PC: 0x129760 | Địa chỉ FDE: 0x1e8358 | Kích thước: 36 bytes
//   0x129760: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x129764: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x129768: 910043FD  add      x29, sp, #0x10
//   0x12976c: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_2745_0x129760(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x129760ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1e8358ULL;
    acc ^= (acc >> 17) * 0x0024ULL;
    return acc;
}

// FDE #2746 | PC: 0x129784 | FDE: 0x1e8378 | Size: 16 bytes [_PyPreCmdline_SetArgv]
// Khung tháo gỡ #2746 | Địa chỉ PC: 0x129784 | Địa chỉ FDE: 0x1e8378 | Kích thước: 16 bytes
//   0x129784: AA0003E9  mov      x9, x0
//   0x129788: AA0103E0  mov      x0, x1
//   0x12978c: AA0903E1  mov      x1, x9
//   0x129790: 17FCC684  b        #0x5b1a0
static inline uint64_t fde_func_2746_0x129784(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x129784ULL ^ (static_cast<uint64_t>(0xaa0003e9ULL) << 13);
    acc = (acc + a1 + 0xaa0103e0ULL) ^ 0x1e8378ULL;
    acc ^= (acc >> 17) * 0x0010ULL;
    return acc;
}

// FDE #2747 | PC: 0x129794 | FDE: 0x1e8390 | Size: 156 bytes [_PyPreCmdline_SetConfig]
// Khung tháo gỡ #2747 | Địa chỉ PC: 0x129794 | Địa chỉ FDE: 0x1e8390 | Kích thước: 156 bytes
//   0x129794: D10183FF  sub      sp, sp, #0x60
//   0x129798: A90357F6  stp      x22, x21, [sp, #0x30]
//   0x12979c: A9044FF4  stp      x20, x19, [sp, #0x40]
//   0x1297a0: A9057BFD  stp      x29, x30, [sp, #0x50]
static inline uint64_t fde_func_2747_0x129794(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x129794ULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xa90357f6ULL) ^ 0x1e8390ULL;
    acc ^= (acc >> 17) * 0x009cULL;
    return acc;
}

// FDE #2748 | PC: 0x129830 | FDE: 0x1e83b8 | Size: 256 bytes [_PyPreCmdline_Read]
// Khung tháo gỡ #2748 | Địa chỉ PC: 0x129830 | Địa chỉ FDE: 0x1e83b8 | Kích thước: 256 bytes
//   0x129830: D10183FF  sub      sp, sp, #0x60
//   0x129834: A90167FA  stp      x26, x25, [sp, #0x10]
//   0x129838: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x12983c: A90357F6  stp      x22, x21, [sp, #0x30]
static inline uint64_t fde_func_2748_0x129830(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x129830ULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xa90167faULL) ^ 0x1e83b8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #2749 | PC: 0x129af8 | FDE: 0x1e83e8 | Size: 172 bytes [_Py_get_xoption]
// Khung tháo gỡ #2749 | Địa chỉ PC: 0x129af8 | Địa chỉ FDE: 0x1e83e8 | Kích thước: 172 bytes
//   0x129af8: F81C0FF7  str      x23, [sp, #-0x40]!
//   0x129afc: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x129b00: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x129b04: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_2749_0x129af8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x129af8ULL ^ (static_cast<uint64_t>(0xf81c0ff7ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x1e83e8ULL;
    acc ^= (acc >> 17) * 0x00acULL;
    return acc;
}

// FDE #2750 | PC: 0x129ba4 | FDE: 0x1e8410 | Size: 52 bytes [_Py_GetEnv]
// Khung tháo gỡ #2750 | Địa chỉ PC: 0x129ba4 | Địa chỉ FDE: 0x1e8410 | Kích thước: 52 bytes
//   0x129ba4: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x129ba8: 910003FD  mov      x29, sp
//   0x129bac: 34000100  cbz      w0, #0x129bcc
//   0x129bb0: AA0103E0  mov      x0, x1
static inline uint64_t fde_func_2750_0x129ba4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x129ba4ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1e8410ULL;
    acc ^= (acc >> 17) * 0x0034ULL;
    return acc;
}

// FDE #2751 | PC: 0x129bd8 | FDE: 0x1e8430 | Size: 32 bytes [_PyPreConfig_InitCompatConfig]
// Khung tháo gỡ #2751 | Địa chỉ PC: 0x129bd8 | Địa chỉ FDE: 0x1e8430 | Kích thước: 32 bytes
//   0x129bd8: 90000428  adrp     x8, #0x1ad000
//   0x129bdc: D0000489  adrp     x9, #0x1bb000
//   0x129be0: 3DC06100  ldr      q0, [x8, #0x180]
//   0x129be4: 3DC3D521  ldr      q1, [x9, #0xf50]
static inline uint64_t fde_func_2751_0x129bd8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x129bd8ULL ^ (static_cast<uint64_t>(0x90000428ULL) << 13);
    acc = (acc + a1 + 0xd0000489ULL) ^ 0x1e8430ULL;
    acc ^= (acc >> 17) * 0x0020ULL;
    return acc;
}

// FDE #2752 | PC: 0x129bf8 | FDE: 0x1e8448 | Size: 32 bytes [PyPreConfig_InitPythonConfig]
// Khung tháo gỡ #2752 | Địa chỉ PC: 0x129bf8 | Địa chỉ FDE: 0x1e8448 | Kích thước: 32 bytes
//   0x129bf8: D0000488  adrp     x8, #0x1bb000
//   0x129bfc: F0000469  adrp     x9, #0x1b8000
//   0x129c00: 3DC3D900  ldr      q0, [x8, #0xf60]
//   0x129c04: 3DC3F121  ldr      q1, [x9, #0xfc0]
static inline uint64_t fde_func_2752_0x129bf8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x129bf8ULL ^ (static_cast<uint64_t>(0xd0000488ULL) << 13);
    acc = (acc + a1 + 0xf0000469ULL) ^ 0x1e8448ULL;
    acc ^= (acc >> 17) * 0x0020ULL;
    return acc;
}

// FDE #2753 | PC: 0x129c18 | FDE: 0x1e8460 | Size: 36 bytes [PyPreConfig_InitIsolatedConfig]
// Khung tháo gỡ #2753 | Địa chỉ PC: 0x129c18 | Địa chỉ FDE: 0x1e8460 | Kích thước: 36 bytes
//   0x129c18: D0000488  adrp     x8, #0x1bb000
//   0x129c1c: 3DC3DD00  ldr      q0, [x8, #0xf70]
//   0x129c20: D2C00068  mov      x8, #0x300000000
//   0x129c24: A9017C1F  stp      xzr, xzr, [x0, #0x10]
static inline uint64_t fde_func_2753_0x129c18(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x129c18ULL ^ (static_cast<uint64_t>(0xd0000488ULL) << 13);
    acc = (acc + a1 + 0x3dc3dd00ULL) ^ 0x1e8460ULL;
    acc ^= (acc >> 17) * 0x0024ULL;
    return acc;
}

// FDE #2754 | PC: 0x129c3c | FDE: 0x1e8478 | Size: 88 bytes [_PyPreConfig_InitFromPreConfig]
// Khung tháo gỡ #2754 | Địa chỉ PC: 0x129c3c | Địa chỉ FDE: 0x1e8478 | Kích thước: 88 bytes
//   0x129c3c: D0000489  adrp     x9, #0x1bb000
//   0x129c40: 3DC3D920  ldr      q0, [x9, #0xf60]
//   0x129c44: F0000469  adrp     x9, #0x1b8000
//   0x129c48: 3DC3F121  ldr      q1, [x9, #0xfc0]
static inline uint64_t fde_func_2754_0x129c3c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x129c3cULL ^ (static_cast<uint64_t>(0xd0000489ULL) << 13);
    acc = (acc + a1 + 0x3dc3d920ULL) ^ 0x1e8478ULL;
    acc ^= (acc >> 17) * 0x0058ULL;
    return acc;
}

// FDE #2755 | PC: 0x129c94 | FDE: 0x1e8490 | Size: 180 bytes [_PyPreConfig_InitFromConfig]
// Khung tháo gỡ #2755 | Địa chỉ PC: 0x129c94 | Địa chỉ FDE: 0x1e8490 | Kích thước: 180 bytes
//   0x129c94: B9400028  ldr      w8, [x1]
//   0x129c98: 71000D1F  cmp      w8, #3
//   0x129c9c: 54000160  b.eq     #0x129cc8
//   0x129ca0: 7100091F  cmp      w8, #2
static inline uint64_t fde_func_2755_0x129c94(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x129c94ULL ^ (static_cast<uint64_t>(0xb9400028ULL) << 13);
    acc = (acc + a1 + 0x71000d1fULL) ^ 0x1e8490ULL;
    acc ^= (acc >> 17) * 0x00b4ULL;
    return acc;
}

// FDE #2756 | PC: 0x129d48 | FDE: 0x1e84a8 | Size: 68 bytes [_PyPreConfig_GetConfig]
// Khung tháo gỡ #2756 | Địa chỉ PC: 0x129d48 | Địa chỉ FDE: 0x1e84a8 | Kích thước: 68 bytes
//   0x129d48: B9405028  ldr      w8, [x1, #0x50]
//   0x129d4c: 3100051F  cmn      w8, #1
//   0x129d50: 54000040  b.eq     #0x129d58
//   0x129d54: B9000408  str      w8, [x0, #4]
static inline uint64_t fde_func_2756_0x129d48(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x129d48ULL ^ (static_cast<uint64_t>(0xb9405028ULL) << 13);
    acc = (acc + a1 + 0x3100051fULL) ^ 0x1e84a8ULL;
    acc ^= (acc >> 17) * 0x0044ULL;
    return acc;
}

// FDE #2757 | PC: 0x129d8c | FDE: 0x1e84c0 | Size: 256 bytes [_PyPreConfig_AsDict]
// Khung tháo gỡ #2757 | Địa chỉ PC: 0x129d8c | Địa chỉ FDE: 0x1e84c0 | Kích thước: 256 bytes
//   0x129d8c: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x129d90: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x129d94: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x129d98: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_2757_0x129d8c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x129d8cULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1e84c0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #2758 | PC: 0x12a094 | FDE: 0x1e84e8 | Size: 128 bytes [_Py_str_to_int]
// Khung tháo gỡ #2758 | Địa chỉ PC: 0x12a094 | Địa chỉ FDE: 0x1e84e8 | Kích thước: 128 bytes
//   0x12a094: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x12a098: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x12a09c: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x12a0a0: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_2758_0x12a094(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x12a094ULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1e84e8ULL;
    acc ^= (acc >> 17) * 0x0080ULL;
    return acc;
}

// FDE #2759 | PC: 0x12a114 | FDE: 0x1e8508 | Size: 172 bytes [_Py_get_env_flag]
// Khung tháo gỡ #2759 | Địa chỉ PC: 0x12a114 | Địa chỉ FDE: 0x1e8508 | Kích thước: 172 bytes
//   0x12a114: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x12a118: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x12a11c: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x12a120: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_2759_0x12a114(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x12a114ULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1e8508ULL;
    acc ^= (acc >> 17) * 0x00acULL;
    return acc;
}

// FDE #2760 | PC: 0x12a1c0 | FDE: 0x1e8528 | Size: 256 bytes [_PyPreConfig_Read]
// Khung tháo gỡ #2760 | Địa chỉ PC: 0x12a1c0 | Địa chỉ FDE: 0x1e8528 | Kích thước: 256 bytes
//   0x12a1c0: D10443FF  sub      sp, sp, #0x110
//   0x12a1c4: A90B6FFC  stp      x28, x27, [sp, #0xb0]
//   0x12a1c8: A90C67FA  stp      x26, x25, [sp, #0xc0]
//   0x12a1cc: A90D5FF8  stp      x24, x23, [sp, #0xd0]
static inline uint64_t fde_func_2760_0x12a1c0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x12a1c0ULL ^ (static_cast<uint64_t>(0xd10443ffULL) << 13);
    acc = (acc + a1 + 0xa90b6ffcULL) ^ 0x1e8528ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #2761 | PC: 0x12a870 | FDE: 0x1e8558 | Size: 256 bytes [_PyPreConfig_Write]
// Khung tháo gỡ #2761 | Địa chỉ PC: 0x12a870 | Địa chỉ FDE: 0x1e8558 | Kích thước: 256 bytes
//   0x12a870: D101C3FF  sub      sp, sp, #0x70
//   0x12a874: F9000BFB  str      x27, [sp, #0x10]
//   0x12a878: A90267FA  stp      x26, x25, [sp, #0x20]
//   0x12a87c: A9035FF8  stp      x24, x23, [sp, #0x30]
static inline uint64_t fde_func_2761_0x12a870(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x12a870ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xf9000bfbULL) ^ 0x1e8558ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #2762 | PC: 0x12a9b4 | FDE: 0x1e8588 | Size: 156 bytes [_PyArena_New]
// Khung tháo gỡ #2762 | Địa chỉ PC: 0x12a9b4 | Địa chỉ FDE: 0x1e8588 | Kích thước: 156 bytes
//   0x12a9b4: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x12a9b8: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x12a9bc: 910043FD  add      x29, sp, #0x10
//   0x12a9c0: 52800300  mov      w0, #0x18
static inline uint64_t fde_func_2762_0x12a9b4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x12a9b4ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1e8588ULL;
    acc ^= (acc >> 17) * 0x009cULL;
    return acc;
}

// FDE #2763 | PC: 0x12aa50 | FDE: 0x1e85a8 | Size: 80 bytes [_PyArena_Free]
// Khung tháo gỡ #2763 | Địa chỉ PC: 0x12aa50 | Địa chỉ FDE: 0x1e85a8 | Kích thước: 80 bytes
//   0x12aa50: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x12aa54: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x12aa58: 910043FD  add      x29, sp, #0x10
//   0x12aa5c: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_2763_0x12aa50(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x12aa50ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1e85a8ULL;
    acc ^= (acc >> 17) * 0x0050ULL;
    return acc;
}

// FDE #2764 | PC: 0x12aaa0 | FDE: 0x1e85c8 | Size: 172 bytes [_PyArena_Malloc]
// Khung tháo gỡ #2764 | Địa chỉ PC: 0x12aaa0 | Địa chỉ FDE: 0x1e85c8 | Kích thước: 172 bytes
//   0x12aaa0: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x12aaa4: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x12aaa8: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x12aaac: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_2764_0x12aaa0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x12aaa0ULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1e85c8ULL;
    acc ^= (acc >> 17) * 0x00acULL;
    return acc;
}

// FDE #2765 | PC: 0x12ab4c | FDE: 0x1e85f0 | Size: 72 bytes [_PyArena_AddPyObject]
// Khung tháo gỡ #2765 | Địa chỉ PC: 0x12ab4c | Địa chỉ FDE: 0x1e85f0 | Kích thước: 72 bytes
//   0x12ab4c: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x12ab50: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x12ab54: 910043FD  add      x29, sp, #0x10
//   0x12ab58: F9400800  ldr      x0, [x0, #0x10]
static inline uint64_t fde_func_2765_0x12ab4c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x12ab4cULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1e85f0ULL;
    acc ^= (acc >> 17) * 0x0048ULL;
    return acc;
}

// FDE #2766 | PC: 0x12ab94 | FDE: 0x1e8610 | Size: 8 bytes [PyFPE_dummy]
// Khung tháo gỡ #2766 | Địa chỉ PC: 0x12ab94 | Địa chỉ FDE: 0x1e8610 | Kích thước: 8 bytes
//   0x12ab94: 1E6E1000  fmov     d0, #1.00000000
//   0x12ab98: D65F03C0  ret      
static inline uint64_t fde_func_2766_0x12ab94(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x12ab94ULL ^ (static_cast<uint64_t>(0x1e6e1000ULL) << 13);
    acc = (acc + a1 + 0xd65f03c0ULL) ^ 0x1e8610ULL;
    acc ^= (acc >> 17) * 0x0008ULL;
    return acc;
}

// FDE #2767 | PC: 0x12ab9c | FDE: 0x1e8628 | Size: 256 bytes [_Py_HashDouble]
// Khung tháo gỡ #2767 | Địa chỉ PC: 0x12ab9c | Địa chỉ FDE: 0x1e8628 | Kích thước: 256 bytes
//   0x12ab9c: D2EFFE08  mov      x8, #0x7ff0000000000000
//   0x12aba0: 1E60C001  fabs     d1, d0
//   0x12aba4: 9E670102  fmov     d2, x8
//   0x12aba8: 1E622020  fcmp     d1, d2
static inline uint64_t fde_func_2767_0x12ab9c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x12ab9cULL ^ (static_cast<uint64_t>(0xd2effe08ULL) << 13);
    acc = (acc + a1 + 0x1e60c001ULL) ^ 0x1e8628ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #2768 | PC: 0x12acfc | FDE: 0x1e8648 | Size: 20 bytes [_Py_HashPointer]
// Khung tháo gỡ #2768 | Địa chỉ PC: 0x12acfc | Địa chỉ FDE: 0x1e8648 | Kích thước: 20 bytes
//   0x12acfc: 93C01008  ror      x8, x0, #4
//   0x12ad00: B100051F  cmn      x8, #1
//   0x12ad04: 92800029  mov      x9, #-2
//   0x12ad08: 9A880120  csel     x0, x9, x8, eq
static inline uint64_t fde_func_2768_0x12acfc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x12acfcULL ^ (static_cast<uint64_t>(0x93c01008ULL) << 13);
    acc = (acc + a1 + 0xb100051fULL) ^ 0x1e8648ULL;
    acc ^= (acc >> 17) * 0x0014ULL;
    return acc;
}

// FDE #2769 | PC: 0x12ad10 | FDE: 0x1e8660 | Size: 8 bytes [_Py_HashPointerRaw]
// Khung tháo gỡ #2769 | Địa chỉ PC: 0x12ad10 | Địa chỉ FDE: 0x1e8660 | Kích thước: 8 bytes
//   0x12ad10: 93C01000  ror      x0, x0, #4
//   0x12ad14: D65F03C0  ret      
static inline uint64_t fde_func_2769_0x12ad10(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x12ad10ULL ^ (static_cast<uint64_t>(0x93c01000ULL) << 13);
    acc = (acc + a1 + 0xd65f03c0ULL) ^ 0x1e8660ULL;
    acc ^= (acc >> 17) * 0x0008ULL;
    return acc;
}

// FDE #2770 | PC: 0x12ad18 | FDE: 0x1e8678 | Size: 52 bytes [_Py_HashBytes]
// Khung tháo gỡ #2770 | Địa chỉ PC: 0x12ad18 | Địa chỉ FDE: 0x1e8678 | Kích thước: 52 bytes
//   0x12ad18: B4000161  cbz      x1, #0x12ad44
//   0x12ad1c: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x12ad20: 910003FD  mov      x29, sp
//   0x12ad24: B0000768  adrp     x8, #0x217000
static inline uint64_t fde_func_2770_0x12ad18(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x12ad18ULL ^ (static_cast<uint64_t>(0xb4000161ULL) << 13);
    acc = (acc + a1 + 0xa9bf7bfdULL) ^ 0x1e8678ULL;
    acc ^= (acc >> 17) * 0x0034ULL;
    return acc;
}

// FDE #2771 | PC: 0x12ad4c | FDE: 0x1e8698 | Size: 4 bytes [_PyHash_Fini]
// Khung tháo gỡ #2771 | Địa chỉ PC: 0x12ad4c | Địa chỉ FDE: 0x1e8698 | Kích thước: 4 bytes
//   0x12ad4c: D65F03C0  ret      
static inline uint64_t fde_func_2771_0x12ad4c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x12ad4cULL ^ (static_cast<uint64_t>(0xd65f03c0ULL) << 13);
    acc = (acc + a1 + 0xb0000760ULL) ^ 0x1e8698ULL;
    acc ^= (acc >> 17) * 0x0004ULL;
    return acc;
}

// FDE #2772 | PC: 0x12ad50 | FDE: 0x1e86b0 | Size: 12 bytes [PyHash_GetFuncDef]
// Khung tháo gỡ #2772 | Địa chỉ PC: 0x12ad50 | Địa chỉ FDE: 0x1e86b0 | Kích thước: 12 bytes
//   0x12ad50: B0000760  adrp     x0, #0x217000
//   0x12ad54: 91314000  add      x0, x0, #0xc50
//   0x12ad58: D65F03C0  ret      
static inline uint64_t fde_func_2772_0x12ad50(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x12ad50ULL ^ (static_cast<uint64_t>(0xb0000760ULL) << 13);
    acc = (acc + a1 + 0x91314000ULL) ^ 0x1e86b0ULL;
    acc ^= (acc >> 17) * 0x000cULL;
    return acc;
}

// FDE #2773 | PC: 0x12ad5c | FDE: 0x1e86c8 | Size: 256 bytes [_Py_KeyedHash]
// Khung tháo gỡ #2773 | Địa chỉ PC: 0x12ad5c | Địa chỉ FDE: 0x1e86c8 | Kích thước: 256 bytes
//   0x12ad5c: D28CAEA9  mov      x9, #0x6575
//   0x12ad60: D28E4C2D  mov      x13, #0x7261
//   0x12ad64: D28CAE68  mov      x8, #0x6573
//   0x12ad68: D28DEDAA  mov      x10, #0x6f6d
static inline uint64_t fde_func_2773_0x12ad5c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x12ad5cULL ^ (static_cast<uint64_t>(0xd28caea9ULL) << 13);
    acc = (acc + a1 + 0xd28e4c2dULL) ^ 0x1e86c8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #2774 | PC: 0x12afe0 | FDE: 0x1e86e0 | Size: 176 bytes
// Khung tháo gỡ #2774 | Địa chỉ PC: 0x12afe0 | Địa chỉ FDE: 0x1e86e0 | Kích thước: 176 bytes
//   0x12afe0: B00006A9  adrp     x9, #0x1ff000
//   0x12afe4: F9474D29  ldr      x9, [x9, #0xe98]
//   0x12afe8: 91001C2A  add      x10, x1, #7
//   0x12afec: F100003F  cmp      x1, #0
static inline uint64_t fde_func_2774_0x12afe0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x12afe0ULL ^ (static_cast<uint64_t>(0xb00006a9ULL) << 13);
    acc = (acc + a1 + 0xf9474d29ULL) ^ 0x1e86e0ULL;
    acc ^= (acc >> 17) * 0x00b0ULL;
    return acc;
}

// FDE #2775 | PC: 0x12b090 | FDE: 0x1e86f8 | Size: 16 bytes [BDPythonVMIsExit]
// Khung tháo gỡ #2775 | Địa chỉ PC: 0x12b090 | Địa chỉ FDE: 0x1e86f8 | Kích thước: 16 bytes
//   0x12b090: 900006A8  adrp     x8, #0x1ff000
//   0x12b094: F9457108  ldr      x8, [x8, #0xae0]
//   0x12b098: B9400100  ldr      w0, [x8]
//   0x12b09c: D65F03C0  ret      
static inline uint64_t fde_func_2775_0x12b090(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x12b090ULL ^ (static_cast<uint64_t>(0x900006a8ULL) << 13);
    acc = (acc + a1 + 0xf9457108ULL) ^ 0x1e86f8ULL;
    acc ^= (acc >> 17) * 0x0010ULL;
    return acc;
}

// FDE #2776 | PC: 0x12b0a0 | FDE: 0x1e8710 | Size: 48 bytes [_PyRuntime_Initialize]
// Khung tháo gỡ #2776 | Địa chỉ PC: 0x12b0a0 | Địa chỉ FDE: 0x1e8710 | Kích thước: 48 bytes
//   0x12b0a0: D00007C9  adrp     x9, #0x225000
//   0x12b0a4: 394E612A  ldrb     w10, [x9, #0x398]
//   0x12b0a8: 7100055F  cmp      w10, #1
//   0x12b0ac: 54000081  b.ne     #0x12b0bc
static inline uint64_t fde_func_2776_0x12b0a0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x12b0a0ULL ^ (static_cast<uint64_t>(0xd00007c9ULL) << 13);
    acc = (acc + a1 + 0x394e612aULL) ^ 0x1e8710ULL;
    acc ^= (acc >> 17) * 0x0030ULL;
    return acc;
}

// FDE #2777 | PC: 0x12b0d0 | FDE: 0x1e8728 | Size: 36 bytes [_PyRuntime_Finalize]
// Khung tháo gỡ #2777 | Địa chỉ PC: 0x12b0d0 | Địa chỉ FDE: 0x1e8728 | Kích thước: 36 bytes
//   0x12b0d0: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x12b0d4: 910003FD  mov      x29, sp
//   0x12b0d8: 900006A0  adrp     x0, #0x1ff000
//   0x12b0dc: F943B800  ldr      x0, [x0, #0x770]
static inline uint64_t fde_func_2777_0x12b0d0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x12b0d0ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1e8728ULL;
    acc ^= (acc >> 17) * 0x0024ULL;
    return acc;
}

// FDE #2778 | PC: 0x12b0f4 | FDE: 0x1e8748 | Size: 24 bytes [_Py_IsFinalizing]
// Khung tháo gỡ #2778 | Địa chỉ PC: 0x12b0f4 | Địa chỉ FDE: 0x1e8748 | Kích thước: 24 bytes
//   0x12b0f4: 900006A8  adrp     x8, #0x1ff000
//   0x12b0f8: F943B908  ldr      x8, [x8, #0x770]
//   0x12b0fc: F9400908  ldr      x8, [x8, #0x10]
//   0x12b100: F100011F  cmp      x8, #0
static inline uint64_t fde_func_2778_0x12b0f4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x12b0f4ULL ^ (static_cast<uint64_t>(0x900006a8ULL) << 13);
    acc = (acc + a1 + 0xf943b908ULL) ^ 0x1e8748ULL;
    acc ^= (acc >> 17) * 0x0018ULL;
    return acc;
}

// FDE #2779 | PC: 0x12b10c | FDE: 0x1e8760 | Size: 16 bytes [_Py_IsCoreInitialized]
// Khung tháo gỡ #2779 | Địa chỉ PC: 0x12b10c | Địa chỉ FDE: 0x1e8760 | Kích thước: 16 bytes
//   0x12b10c: 900006A8  adrp     x8, #0x1ff000
//   0x12b110: F943B908  ldr      x8, [x8, #0x770]
//   0x12b114: B9400900  ldr      w0, [x8, #8]
//   0x12b118: D65F03C0  ret      
static inline uint64_t fde_func_2779_0x12b10c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x12b10cULL ^ (static_cast<uint64_t>(0x900006a8ULL) << 13);
    acc = (acc + a1 + 0xf943b908ULL) ^ 0x1e8760ULL;
    acc ^= (acc >> 17) * 0x0010ULL;
    return acc;
}

// FDE #2780 | PC: 0x12b11c | FDE: 0x1e8778 | Size: 16 bytes [Py_IsInitialized]
// Khung tháo gỡ #2780 | Địa chỉ PC: 0x12b11c | Địa chỉ FDE: 0x1e8778 | Kích thước: 16 bytes
//   0x12b11c: 900006A8  adrp     x8, #0x1ff000
//   0x12b120: F943B908  ldr      x8, [x8, #0x770]
//   0x12b124: B9400D00  ldr      w0, [x8, #0xc]
//   0x12b128: D65F03C0  ret      
static inline uint64_t fde_func_2780_0x12b11c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x12b11cULL ^ (static_cast<uint64_t>(0x900006a8ULL) << 13);
    acc = (acc + a1 + 0xf943b908ULL) ^ 0x1e8778ULL;
    acc ^= (acc >> 17) * 0x0010ULL;
    return acc;
}

// FDE #2781 | PC: 0x12b12c | FDE: 0x1e8790 | Size: 92 bytes [_Py_LegacyLocaleDetected]
// Khung tháo gỡ #2781 | Địa chỉ PC: 0x12b12c | Địa chỉ FDE: 0x1e8790 | Kích thước: 92 bytes
//   0x12b12c: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x12b130: 910003FD  mov      x29, sp
//   0x12b134: 34000180  cbz      w0, #0x12b164
//   0x12b138: 2A1F03E0  mov      w0, wzr
static inline uint64_t fde_func_2781_0x12b12c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x12b12cULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1e8790ULL;
    acc ^= (acc >> 17) * 0x005cULL;
    return acc;
}

// FDE #2782 | PC: 0x12b188 | FDE: 0x1e87b0 | Size: 96 bytes [_Py_IsLocaleCoercionTarget]
// Khung tháo gỡ #2782 | Địa chỉ PC: 0x12b188 | Địa chỉ FDE: 0x1e87b0 | Kích thước: 96 bytes
//   0x12b188: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x12b18c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x12b190: 910043FD  add      x29, sp, #0x10
//   0x12b194: B0000481  adrp     x1, #0x1bc000
static inline uint64_t fde_func_2782_0x12b188(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x12b188ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1e87b0ULL;
    acc ^= (acc >> 17) * 0x0060ULL;
    return acc;
}

// FDE #2783 | PC: 0x12b1e8 | FDE: 0x1e87d0 | Size: 8 bytes [_Py_CoerceLegacyLocale]
// Khung tháo gỡ #2783 | Địa chỉ PC: 0x12b1e8 | Địa chỉ FDE: 0x1e87d0 | Kích thước: 8 bytes
//   0x12b1e8: 2A1F03E0  mov      w0, wzr
//   0x12b1ec: D65F03C0  ret      
static inline uint64_t fde_func_2783_0x12b1e8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x12b1e8ULL ^ (static_cast<uint64_t>(0x2a1f03e0ULL) << 13);
    acc = (acc + a1 + 0xd65f03c0ULL) ^ 0x1e87d0ULL;
    acc ^= (acc >> 17) * 0x0008ULL;
    return acc;
}

// FDE #2784 | PC: 0x12b1f0 | FDE: 0x1e87e8 | Size: 248 bytes [_Py_SetLocaleFromEnv]
// Khung tháo gỡ #2784 | Địa chỉ PC: 0x12b1f0 | Địa chỉ FDE: 0x1e87e8 | Kích thước: 248 bytes
//   0x12b1f0: D10183FF  sub      sp, sp, #0x60
//   0x12b1f4: A90357F6  stp      x22, x21, [sp, #0x30]
//   0x12b1f8: A9044FF4  stp      x20, x19, [sp, #0x40]
//   0x12b1fc: A9057BFD  stp      x29, x30, [sp, #0x50]
static inline uint64_t fde_func_2784_0x12b1f0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x12b1f0ULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xa90357f6ULL) ^ 0x1e87e8ULL;
    acc ^= (acc >> 17) * 0x00f8ULL;
    return acc;
}

// FDE #2785 | PC: 0x12b2e8 | FDE: 0x1e8810 | Size: 256 bytes [_PyInterpreterState_SetConfig]
// Khung tháo gỡ #2785 | Địa chỉ PC: 0x12b2e8 | Địa chỉ FDE: 0x1e8810 | Kích thước: 256 bytes
//   0x12b2e8: A9BD57FC  stp      x28, x21, [sp, #-0x30]!
//   0x12b2ec: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x12b2f0: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x12b2f4: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_2785_0x12b2e8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x12b2e8ULL ^ (static_cast<uint64_t>(0xa9bd57fcULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1e8810ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #2786 | PC: 0x12b3f0 | FDE: 0x1e8838 | Size: 220 bytes
// Khung tháo gỡ #2786 | Địa chỉ PC: 0x12b3f0 | Địa chỉ FDE: 0x1e8838 | Kích thước: 220 bytes
//   0x12b3f0: D10283FF  sub      sp, sp, #0xa0
//   0x12b3f4: F9003BF5  str      x21, [sp, #0x70]
//   0x12b3f8: A9084FF4  stp      x20, x19, [sp, #0x80]
//   0x12b3fc: A9097BFD  stp      x29, x30, [sp, #0x90]
static inline uint64_t fde_func_2786_0x12b3f0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x12b3f0ULL ^ (static_cast<uint64_t>(0xd10283ffULL) << 13);
    acc = (acc + a1 + 0xf9003bf5ULL) ^ 0x1e8838ULL;
    acc ^= (acc >> 17) * 0x00dcULL;
    return acc;
}

// FDE #2787 | PC: 0x12b4cc | FDE: 0x1e8858 | Size: 256 bytes [_Py_PreInitializeFromPyArgv]
// Khung tháo gỡ #2787 | Địa chỉ PC: 0x12b4cc | Địa chỉ FDE: 0x1e8858 | Kích thước: 256 bytes
//   0x12b4cc: D10303FF  sub      sp, sp, #0xc0
//   0x12b4d0: F90043F7  str      x23, [sp, #0x80]
//   0x12b4d4: A90957F6  stp      x22, x21, [sp, #0x90]
//   0x12b4d8: A90A4FF4  stp      x20, x19, [sp, #0xa0]
static inline uint64_t fde_func_2787_0x12b4cc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x12b4ccULL ^ (static_cast<uint64_t>(0xd10303ffULL) << 13);
    acc = (acc + a1 + 0xf90043f7ULL) ^ 0x1e8858ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #2788 | PC: 0x12b678 | FDE: 0x1e8880 | Size: 88 bytes [Py_PreInitializeFromBytesArgs]
// Khung tháo gỡ #2788 | Địa chỉ PC: 0x12b678 | Địa chỉ FDE: 0x1e8880 | Kích thước: 88 bytes
//   0x12b678: D10143FF  sub      sp, sp, #0x50
//   0x12b67c: F9001BF3  str      x19, [sp, #0x30]
//   0x12b680: A9047BFD  stp      x29, x30, [sp, #0x40]
//   0x12b684: 910103FD  add      x29, sp, #0x40
static inline uint64_t fde_func_2788_0x12b678(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x12b678ULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xf9001bf3ULL) ^ 0x1e8880ULL;
    acc ^= (acc >> 17) * 0x0058ULL;
    return acc;
}

// FDE #2789 | PC: 0x12b6d0 | FDE: 0x1e88a0 | Size: 84 bytes [Py_PreInitializeFromArgs]
// Khung tháo gỡ #2789 | Địa chỉ PC: 0x12b6d0 | Địa chỉ FDE: 0x1e88a0 | Kích thước: 84 bytes
//   0x12b6d0: D10143FF  sub      sp, sp, #0x50
//   0x12b6d4: F9001BF3  str      x19, [sp, #0x30]
//   0x12b6d8: A9047BFD  stp      x29, x30, [sp, #0x40]
//   0x12b6dc: 910103FD  add      x29, sp, #0x40
static inline uint64_t fde_func_2789_0x12b6d0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x12b6d0ULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xf9001bf3ULL) ^ 0x1e88a0ULL;
    acc ^= (acc >> 17) * 0x0054ULL;
    return acc;
}

// FDE #2790 | PC: 0x12b724 | FDE: 0x1e88c0 | Size: 8 bytes [Py_PreInitialize]
// Khung tháo gỡ #2790 | Địa chỉ PC: 0x12b724 | Địa chỉ FDE: 0x1e88c0 | Kích thước: 8 bytes
//   0x12b724: AA1F03E1  mov      x1, xzr
//   0x12b728: 17FCBDF2  b        #0x5aef0
static inline uint64_t fde_func_2790_0x12b724(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x12b724ULL ^ (static_cast<uint64_t>(0xaa1f03e1ULL) << 13);
    acc = (acc + a1 + 0x17fcbdf2ULL) ^ 0x1e88c0ULL;
    acc ^= (acc >> 17) * 0x0008ULL;
    return acc;
}

// FDE #2791 | PC: 0x12b72c | FDE: 0x1e88d8 | Size: 256 bytes [_Py_PreInitializeFromConfig]
// Khung tháo gỡ #2791 | Địa chỉ PC: 0x12b72c | Địa chỉ FDE: 0x1e88d8 | Kích thước: 256 bytes
//   0x12b72c: D102C3FF  sub      sp, sp, #0xb0
//   0x12b730: A90857F6  stp      x22, x21, [sp, #0x80]
//   0x12b734: A9094FF4  stp      x20, x19, [sp, #0x90]
//   0x12b738: A90A7BFD  stp      x29, x30, [sp, #0xa0]
static inline uint64_t fde_func_2791_0x12b72c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x12b72cULL ^ (static_cast<uint64_t>(0xd102c3ffULL) << 13);
    acc = (acc + a1 + 0xa90857f6ULL) ^ 0x1e88d8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #2792 | PC: 0x12b840 | FDE: 0x1e8900 | Size: 256 bytes [Py_InitializeFromConfig]
// Khung tháo gỡ #2792 | Địa chỉ PC: 0x12b840 | Địa chỉ FDE: 0x1e8900 | Kích thước: 256 bytes
//   0x12b840: A9BC5FFC  stp      x28, x23, [sp, #-0x40]!
//   0x12b844: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x12b848: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x12b84c: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_2792_0x12b840(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x12b840ULL ^ (static_cast<uint64_t>(0xa9bc5ffcULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x1e8900ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #2793 | PC: 0x12bd38 | FDE: 0x1e8928 | Size: 256 bytes [Py_InitializeEx]
// Khung tháo gỡ #2793 | Địa chỉ PC: 0x12bd38 | Địa chỉ FDE: 0x1e8928 | Kích thước: 256 bytes
//   0x12bd38: A9BD57FC  stp      x28, x21, [sp, #-0x30]!
//   0x12bd3c: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x12bd40: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x12bd44: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_2793_0x12bd38(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x12bd38ULL ^ (static_cast<uint64_t>(0xa9bd57fcULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1e8928ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #2794 | PC: 0x12be5c | FDE: 0x1e8950 | Size: 84 bytes [Py_ExitStatusException]
// Khung tháo gỡ #2794 | Địa chỉ PC: 0x12be5c | Địa chỉ FDE: 0x1e8950 | Kích thước: 84 bytes
//   0x12be5c: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x12be60: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x12be64: 910043FD  add      x29, sp, #0x10
//   0x12be68: B9400008  ldr      w8, [x0]
static inline uint64_t fde_func_2794_0x12be5c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x12be5cULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1e8950ULL;
    acc ^= (acc >> 17) * 0x0054ULL;
    return acc;
}

// FDE #2795 | PC: 0x12beb0 | FDE: 0x1e8970 | Size: 8 bytes [Py_Initialize]
// Khung tháo gỡ #2795 | Địa chỉ PC: 0x12beb0 | Địa chỉ FDE: 0x1e8970 | Kích thước: 8 bytes
//   0x12beb0: 52800020  mov      w0, #1
//   0x12beb4: 17FCB6FB  b        #0x59aa0
static inline uint64_t fde_func_2795_0x12beb0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x12beb0ULL ^ (static_cast<uint64_t>(0x52800020ULL) << 13);
    acc = (acc + a1 + 0x17fcb6fbULL) ^ 0x1e8970ULL;
    acc ^= (acc >> 17) * 0x0008ULL;
    return acc;
}

// FDE #2796 | PC: 0x12beb8 | FDE: 0x1e8988 | Size: 256 bytes [_Py_InitializeMain]
// Khung tháo gỡ #2796 | Địa chỉ PC: 0x12beb8 | Địa chỉ FDE: 0x1e8988 | Kích thước: 256 bytes
//   0x12beb8: D101C3FF  sub      sp, sp, #0x70
//   0x12bebc: A9054FF4  stp      x20, x19, [sp, #0x50]
//   0x12bec0: A9067BFD  stp      x29, x30, [sp, #0x60]
//   0x12bec4: 910183FD  add      x29, sp, #0x60
static inline uint64_t fde_func_2796_0x12beb8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x12beb8ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xa9054ff4ULL) ^ 0x1e8988ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #2797 | PC: 0x12bff8 | FDE: 0x1e89a8 | Size: 256 bytes [Py_FinalizeEx]
// Khung tháo gỡ #2797 | Địa chỉ PC: 0x12bff8 | Địa chỉ FDE: 0x1e89a8 | Kích thước: 256 bytes
//   0x12bff8: D10183FF  sub      sp, sp, #0x60
//   0x12bffc: A90167FA  stp      x26, x25, [sp, #0x10]
//   0x12c000: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x12c004: A90357F6  stp      x22, x21, [sp, #0x30]
static inline uint64_t fde_func_2797_0x12bff8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x12bff8ULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xa90167faULL) ^ 0x1e89a8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #2798 | PC: 0x12c250 | FDE: 0x1e89d8 | Size: 256 bytes
// Khung tháo gỡ #2798 | Địa chỉ PC: 0x12c250 | Địa chỉ FDE: 0x1e89d8 | Kích thước: 256 bytes
//   0x12c250: D10143FF  sub      sp, sp, #0x50
//   0x12c254: A9015FF8  stp      x24, x23, [sp, #0x10]
//   0x12c258: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x12c25c: A9034FF4  stp      x20, x19, [sp, #0x30]
static inline uint64_t fde_func_2798_0x12c250(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x12c250ULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xa9015ff8ULL) ^ 0x1e89d8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #2799 | PC: 0x12c41c | FDE: 0x1e8a00 | Size: 256 bytes
// Khung tháo gỡ #2799 | Địa chỉ PC: 0x12c41c | Địa chỉ FDE: 0x1e8a00 | Kích thước: 256 bytes
//   0x12c41c: D10283FF  sub      sp, sp, #0xa0
//   0x12c420: A9046FFC  stp      x28, x27, [sp, #0x40]
//   0x12c424: A90567FA  stp      x26, x25, [sp, #0x50]
//   0x12c428: A9065FF8  stp      x24, x23, [sp, #0x60]
static inline uint64_t fde_func_2799_0x12c41c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x12c41cULL ^ (static_cast<uint64_t>(0xd10283ffULL) << 13);
    acc = (acc + a1 + 0xa9046ffcULL) ^ 0x1e8a00ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #2800 | PC: 0x12cb78 | FDE: 0x1e8a30 | Size: 184 bytes
// Khung tháo gỡ #2800 | Địa chỉ PC: 0x12cb78 | Địa chỉ FDE: 0x1e8a30 | Kích thước: 184 bytes
//   0x12cb78: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x12cb7c: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x12cb80: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x12cb84: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_2800_0x12cb78(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x12cb78ULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1e8a30ULL;
    acc ^= (acc >> 17) * 0x00b8ULL;
    return acc;
}

// FDE #2801 | PC: 0x12cc30 | FDE: 0x1e8a50 | Size: 156 bytes [BDPythonVMDeallocSizeOptimizeFiles]
// Khung tháo gỡ #2801 | Địa chỉ PC: 0x12cc30 | Địa chỉ FDE: 0x1e8a50 | Kích thước: 156 bytes
//   0x12cc30: A9BC5FF8  stp      x24, x23, [sp, #-0x40]!
//   0x12cc34: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x12cc38: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x12cc3c: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_2801_0x12cc30(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x12cc30ULL ^ (static_cast<uint64_t>(0xa9bc5ff8ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x1e8a50ULL;
    acc ^= (acc >> 17) * 0x009cULL;
    return acc;
}

// FDE #2802 | PC: 0x12cccc | FDE: 0x1e8a78 | Size: 4 bytes [Py_Finalize]
// Khung tháo gỡ #2802 | Địa chỉ PC: 0x12cccc | Địa chỉ FDE: 0x1e8a78 | Kích thước: 4 bytes
//   0x12cccc: 17FCC099  b        #0x5cf30
static inline uint64_t fde_func_2802_0x12cccc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x12ccccULL ^ (static_cast<uint64_t>(0x17fcc099ULL) << 13);
    acc = (acc + a1 + 0xd10303ffULL) ^ 0x1e8a78ULL;
    acc ^= (acc >> 17) * 0x0004ULL;
    return acc;
}

// FDE #2803 | PC: 0x12ccd0 | FDE: 0x1e8a90 | Size: 256 bytes [_Py_NewInterpreter]
// Khung tháo gỡ #2803 | Địa chỉ PC: 0x12ccd0 | Địa chỉ FDE: 0x1e8a90 | Kích thước: 256 bytes
//   0x12ccd0: D10303FF  sub      sp, sp, #0xc0
//   0x12ccd4: F90043F7  str      x23, [sp, #0x80]
//   0x12ccd8: A90957F6  stp      x22, x21, [sp, #0x90]
//   0x12ccdc: A90A4FF4  stp      x20, x19, [sp, #0xa0]
static inline uint64_t fde_func_2803_0x12ccd0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x12ccd0ULL ^ (static_cast<uint64_t>(0xd10303ffULL) << 13);
    acc = (acc + a1 + 0xf90043f7ULL) ^ 0x1e8a90ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #2804 | PC: 0x12ced8 | FDE: 0x1e8ab8 | Size: 8 bytes [Py_NewInterpreter]
// Khung tháo gỡ #2804 | Địa chỉ PC: 0x12ced8 | Địa chỉ FDE: 0x1e8ab8 | Kích thước: 8 bytes
//   0x12ced8: 2A1F03E0  mov      w0, wzr
//   0x12cedc: 17FCAE39  b        #0x587c0
static inline uint64_t fde_func_2804_0x12ced8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x12ced8ULL ^ (static_cast<uint64_t>(0x2a1f03e0ULL) << 13);
    acc = (acc + a1 + 0x17fcae39ULL) ^ 0x1e8ab8ULL;
    acc ^= (acc >> 17) * 0x0008ULL;
    return acc;
}

// FDE #2805 | PC: 0x12cee0 | FDE: 0x1e8ad0 | Size: 256 bytes [Py_EndInterpreter]
// Khung tháo gỡ #2805 | Địa chỉ PC: 0x12cee0 | Địa chỉ FDE: 0x1e8ad0 | Kích thước: 256 bytes
//   0x12cee0: D10103FF  sub      sp, sp, #0x40
//   0x12cee4: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x12cee8: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x12ceec: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_2805_0x12cee0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x12cee0ULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x1e8ad0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #2806 | PC: 0x12d064 | FDE: 0x1e8af8 | Size: 56 bytes [_Py_FatalErrorFunc]
// Khung tháo gỡ #2806 | Địa chỉ PC: 0x12d064 | Địa chỉ FDE: 0x1e8af8 | Kích thước: 56 bytes
//   0x12d064: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x12d068: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x12d06c: 910043FD  add      x29, sp, #0x10
//   0x12d070: D0000688  adrp     x8, #0x1ff000
static inline uint64_t fde_func_2806_0x12d064(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x12d064ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1e8af8ULL;
    acc ^= (acc >> 17) * 0x0038ULL;
    return acc;
}

// FDE #2807 | PC: 0x12d09c | FDE: 0x1e8b18 | Size: 256 bytes [_Py_DumpExtensionModules]
// Khung tháo gỡ #2807 | Địa chỉ PC: 0x12d09c | Địa chỉ FDE: 0x1e8b18 | Kích thước: 256 bytes
//   0x12d09c: D10243FF  sub      sp, sp, #0x90
//   0x12d0a0: A90467FA  stp      x26, x25, [sp, #0x40]
//   0x12d0a4: A9055FF8  stp      x24, x23, [sp, #0x50]
//   0x12d0a8: A90657F6  stp      x22, x21, [sp, #0x60]
static inline uint64_t fde_func_2807_0x12d09c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x12d09cULL ^ (static_cast<uint64_t>(0xd10243ffULL) << 13);
    acc = (acc + a1 + 0xa90467faULL) ^ 0x1e8b18ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #2808 | PC: 0x12d334 | FDE: 0x1e8b48 | Size: 52 bytes [Py_FatalError]
// Khung tháo gỡ #2808 | Địa chỉ PC: 0x12d334 | Địa chỉ FDE: 0x1e8b48 | Kích thước: 52 bytes
//   0x12d334: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x12d338: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x12d33c: 910043FD  add      x29, sp, #0x10
//   0x12d340: D0000688  adrp     x8, #0x1ff000
static inline uint64_t fde_func_2808_0x12d334(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x12d334ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1e8b48ULL;
    acc ^= (acc >> 17) * 0x0034ULL;
    return acc;
}

// FDE #2809 | PC: 0x12d368 | FDE: 0x1e8b68 | Size: 256 bytes
// Khung tháo gỡ #2809 | Địa chỉ PC: 0x12d368 | Địa chỉ FDE: 0x1e8b68 | Kích thước: 256 bytes
//   0x12d368: D10203FF  sub      sp, sp, #0x80
//   0x12d36c: F90013FB  str      x27, [sp, #0x20]
//   0x12d370: A90367FA  stp      x26, x25, [sp, #0x30]
//   0x12d374: A9045FF8  stp      x24, x23, [sp, #0x40]
static inline uint64_t fde_func_2809_0x12d368(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x12d368ULL ^ (static_cast<uint64_t>(0xd10203ffULL) << 13);
    acc = (acc + a1 + 0xf90013fbULL) ^ 0x1e8b68ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #2810 | PC: 0x12d844 | FDE: 0x1e8b98 | Size: 256 bytes [_Py_FatalErrorFormat]
// Khung tháo gỡ #2810 | Địa chỉ PC: 0x12d844 | Địa chỉ FDE: 0x1e8b98 | Kích thước: 256 bytes
//   0x12d844: D104C3FF  sub      sp, sp, #0x130
//   0x12d848: A90F5FFC  stp      x28, x23, [sp, #0xf0]
//   0x12d84c: A91057F6  stp      x22, x21, [sp, #0x100]
//   0x12d850: A9114FF4  stp      x20, x19, [sp, #0x110]
static inline uint64_t fde_func_2810_0x12d844(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x12d844ULL ^ (static_cast<uint64_t>(0xd104c3ffULL) << 13);
    acc = (acc + a1 + 0xa90f5ffcULL) ^ 0x1e8b98ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #2811 | PC: 0x12d984 | FDE: 0x1e8bc0 | Size: 20 bytes
// Khung tháo gỡ #2811 | Địa chỉ PC: 0x12d984 | Địa chỉ FDE: 0x1e8bc0 | Kích thước: 20 bytes
//   0x12d984: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x12d988: 910003FD  mov      x29, sp
//   0x12d98c: 36F80040  tbz      w0, #0x1f, #0x12d994
//   0x12d990: 940007C5  bl       #0x12f8a4
static inline uint64_t fde_func_2811_0x12d984(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x12d984ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1e8bc0ULL;
    acc ^= (acc >> 17) * 0x0014ULL;
    return acc;
}

// FDE #2812 | PC: 0x12d998 | FDE: 0x1e8be0 | Size: 52 bytes
// Khung tháo gỡ #2812 | Địa chỉ PC: 0x12d998 | Địa chỉ FDE: 0x1e8be0 | Kích thước: 52 bytes
//   0x12d998: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x12d99c: 910003FD  mov      x29, sp
//   0x12d9a0: D0000688  adrp     x8, #0x1ff000
//   0x12d9a4: F9464D08  ldr      x8, [x8, #0xc98]
static inline uint64_t fde_func_2812_0x12d998(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x12d998ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1e8be0ULL;
    acc ^= (acc >> 17) * 0x0034ULL;
    return acc;
}

// FDE #2813 | PC: 0x12d9cc | FDE: 0x1e8c00 | Size: 56 bytes [Py_AtExit]
// Khung tháo gỡ #2813 | Địa chỉ PC: 0x12d9cc | Địa chỉ FDE: 0x1e8c00 | Kích thước: 56 bytes
//   0x12d9cc: D0000689  adrp     x9, #0x1ff000
//   0x12d9d0: F943B929  ldr      x9, [x9, #0x770]
//   0x12d9d4: B981512A  ldrsw    x10, [x9, #0x150]
//   0x12d9d8: 71007D5F  cmp      w10, #0x1f
static inline uint64_t fde_func_2813_0x12d9cc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x12d9ccULL ^ (static_cast<uint64_t>(0xd0000689ULL) << 13);
    acc = (acc + a1 + 0xf943b929ULL) ^ 0x1e8c00ULL;
    acc ^= (acc >> 17) * 0x0038ULL;
    return acc;
}

// FDE #2814 | PC: 0x12da04 | FDE: 0x1e8c18 | Size: 16 bytes [Py_Exit]
// Khung tháo gỡ #2814 | Địa chỉ PC: 0x12da04 | Địa chỉ FDE: 0x1e8c18 | Kích thước: 16 bytes
//   0x12da04: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x12da08: 910003FD  mov      x29, sp
//   0x12da0c: 97FCBD49  bl       #0x5cf30
//   0x12da10: 97FFFFE2  bl       #0x12d998
static inline uint64_t fde_func_2814_0x12da04(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x12da04ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1e8c18ULL;
    acc ^= (acc >> 17) * 0x0010ULL;
    return acc;
}

// FDE #2815 | PC: 0x12da14 | FDE: 0x1e8c38 | Size: 120 bytes [Py_FdIsInteractive]
// Khung tháo gỡ #2815 | Địa chỉ PC: 0x12da14 | Địa chỉ FDE: 0x1e8c38 | Kích thước: 120 bytes
//   0x12da14: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x12da18: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x12da1c: 910043FD  add      x29, sp, #0x10
//   0x12da20: AA0103F3  mov      x19, x1
static inline uint64_t fde_func_2815_0x12da14(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x12da14ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1e8c38ULL;
    acc ^= (acc >> 17) * 0x0078ULL;
    return acc;
}

// FDE #2816 | PC: 0x12da8c | FDE: 0x1e8c58 | Size: 120 bytes [_Py_FdIsInteractive]
// Khung tháo gỡ #2816 | Địa chỉ PC: 0x12da8c | Địa chỉ FDE: 0x1e8c58 | Kích thước: 120 bytes
//   0x12da8c: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x12da90: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x12da94: 910043FD  add      x29, sp, #0x10
//   0x12da98: AA0103F3  mov      x19, x1
static inline uint64_t fde_func_2816_0x12da8c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x12da8cULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1e8c58ULL;
    acc ^= (acc >> 17) * 0x0078ULL;
    return acc;
}

// FDE #2817 | PC: 0x12db04 | FDE: 0x1e8c78 | Size: 88 bytes [PyOS_getsig]
// Khung tháo gỡ #2817 | Địa chỉ PC: 0x12db04 | Địa chỉ FDE: 0x1e8c78 | Kích thước: 88 bytes
//   0x12db04: D10143FF  sub      sp, sp, #0x50
//   0x12db08: F9001BF3  str      x19, [sp, #0x30]
//   0x12db0c: A9047BFD  stp      x29, x30, [sp, #0x40]
//   0x12db10: 910103FD  add      x29, sp, #0x40
static inline uint64_t fde_func_2817_0x12db04(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x12db04ULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xf9001bf3ULL) ^ 0x1e8c78ULL;
    acc ^= (acc >> 17) * 0x0058ULL;
    return acc;
}

// FDE #2818 | PC: 0x12db5c | FDE: 0x1e8c98 | Size: 120 bytes [PyOS_setsig]
// Khung tháo gỡ #2818 | Địa chỉ PC: 0x12db5c | Địa chỉ FDE: 0x1e8c98 | Kích thước: 120 bytes
//   0x12db5c: D101C3FF  sub      sp, sp, #0x70
//   0x12db60: A9054FF4  stp      x20, x19, [sp, #0x50]
//   0x12db64: A9067BFD  stp      x29, x30, [sp, #0x60]
//   0x12db68: 910183FD  add      x29, sp, #0x60
static inline uint64_t fde_func_2818_0x12db5c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x12db5cULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xa9054ff4ULL) ^ 0x1e8c98ULL;
    acc ^= (acc >> 17) * 0x0078ULL;
    return acc;
}

// FDE #2819 | PC: 0x12dbd4 | FDE: 0x1e8cb8 | Size: 72 bytes [BDPythonVMDeallocFrozenImportModules]
// Khung tháo gỡ #2819 | Địa chỉ PC: 0x12dbd4 | Địa chỉ FDE: 0x1e8cb8 | Kích thước: 72 bytes
//   0x12dbd4: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x12dbd8: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x12dbdc: 910043FD  add      x29, sp, #0x10
//   0x12dbe0: 900007D3  adrp     x19, #0x225000
static inline uint64_t fde_func_2819_0x12dbd4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x12dbd4ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1e8cb8ULL;
    acc ^= (acc >> 17) * 0x0048ULL;
    return acc;
}

// FDE #2820 | PC: 0x12dc1c | FDE: 0x1e8cd8 | Size: 256 bytes [BDPythonVMSetupFrozenImportModules]
// Khung tháo gỡ #2820 | Địa chỉ PC: 0x12dc1c | Địa chỉ FDE: 0x1e8cd8 | Kích thước: 256 bytes
//   0x12dc1c: D10343FF  sub      sp, sp, #0xd0
//   0x12dc20: F90043F9  str      x25, [sp, #0x80]
//   0x12dc24: A9095FF8  stp      x24, x23, [sp, #0x90]
//   0x12dc28: A90A57F6  stp      x22, x21, [sp, #0xa0]
static inline uint64_t fde_func_2820_0x12dc1c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x12dc1cULL ^ (static_cast<uint64_t>(0xd10343ffULL) << 13);
    acc = (acc + a1 + 0xf90043f9ULL) ^ 0x1e8cd8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #2821 | PC: 0x12ddb8 | FDE: 0x1e8d00 | Size: 188 bytes [BDPythonVMSetIndexFile1]
// Khung tháo gỡ #2821 | Địa chỉ PC: 0x12ddb8 | Địa chỉ FDE: 0x1e8d00 | Kích thước: 188 bytes
//   0x12ddb8: D102C3FF  sub      sp, sp, #0xb0
//   0x12ddbc: A90857F6  stp      x22, x21, [sp, #0x80]
//   0x12ddc0: A9094FF4  stp      x20, x19, [sp, #0x90]
//   0x12ddc4: A90A7BFD  stp      x29, x30, [sp, #0xa0]
static inline uint64_t fde_func_2821_0x12ddb8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x12ddb8ULL ^ (static_cast<uint64_t>(0xd102c3ffULL) << 13);
    acc = (acc + a1 + 0xa90857f6ULL) ^ 0x1e8d00ULL;
    acc ^= (acc >> 17) * 0x00bcULL;
    return acc;
}

// FDE #2822 | PC: 0x12de74 | FDE: 0x1e8d28 | Size: 188 bytes [BDPythonVMSetIndexFile2]
// Khung tháo gỡ #2822 | Địa chỉ PC: 0x12de74 | Địa chỉ FDE: 0x1e8d28 | Kích thước: 188 bytes
//   0x12de74: D102C3FF  sub      sp, sp, #0xb0
//   0x12de78: A90857F6  stp      x22, x21, [sp, #0x80]
//   0x12de7c: A9094FF4  stp      x20, x19, [sp, #0x90]
//   0x12de80: A90A7BFD  stp      x29, x30, [sp, #0xa0]
static inline uint64_t fde_func_2822_0x12de74(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x12de74ULL ^ (static_cast<uint64_t>(0xd102c3ffULL) << 13);
    acc = (acc + a1 + 0xa90857f6ULL) ^ 0x1e8d28ULL;
    acc ^= (acc >> 17) * 0x00bcULL;
    return acc;
}

// FDE #2823 | PC: 0x12df30 | FDE: 0x1e8d50 | Size: 112 bytes [BDPythonVMSetupUnicodeIndex]
// Khung tháo gỡ #2823 | Địa chỉ PC: 0x12df30 | Địa chỉ FDE: 0x1e8d50 | Kích thước: 112 bytes
//   0x12df30: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x12df34: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x12df38: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x12df3c: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_2823_0x12df30(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x12df30ULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1e8d50ULL;
    acc ^= (acc >> 17) * 0x0070ULL;
    return acc;
}

// FDE #2824 | PC: 0x12dfa0 | FDE: 0x1e8d70 | Size: 192 bytes [BDPythonVMSetUnicodeTypeRecords]
// Khung tháo gỡ #2824 | Địa chỉ PC: 0x12dfa0 | Địa chỉ FDE: 0x1e8d70 | Kích thước: 192 bytes
//   0x12dfa0: D102C3FF  sub      sp, sp, #0xb0
//   0x12dfa4: F90043F5  str      x21, [sp, #0x80]
//   0x12dfa8: A9094FF4  stp      x20, x19, [sp, #0x90]
//   0x12dfac: A90A7BFD  stp      x29, x30, [sp, #0xa0]
static inline uint64_t fde_func_2824_0x12dfa0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x12dfa0ULL ^ (static_cast<uint64_t>(0xd102c3ffULL) << 13);
    acc = (acc + a1 + 0xf90043f5ULL) ^ 0x1e8d70ULL;
    acc ^= (acc >> 17) * 0x00c0ULL;
    return acc;
}

// FDE #2825 | PC: 0x12e060 | FDE: 0x1e8d90 | Size: 76 bytes [BDPythonVMSetupUnicodeTypeRecords]
// Khung tháo gỡ #2825 | Địa chỉ PC: 0x12e060 | Địa chỉ FDE: 0x1e8d90 | Kích thước: 76 bytes
//   0x12e060: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x12e064: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x12e068: 910043FD  add      x29, sp, #0x10
//   0x12e06c: AA0003F4  mov      x20, x0
static inline uint64_t fde_func_2825_0x12e060(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x12e060ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1e8d90ULL;
    acc ^= (acc >> 17) * 0x004cULL;
    return acc;
}

// FDE #2826 | PC: 0x12e0ac | FDE: 0x1e8db0 | Size: 184 bytes [BDPythonVMSetUnicodeExtendedCase]
// Khung tháo gỡ #2826 | Địa chỉ PC: 0x12e0ac | Địa chỉ FDE: 0x1e8db0 | Kích thước: 184 bytes
//   0x12e0ac: D102C3FF  sub      sp, sp, #0xb0
//   0x12e0b0: F90043F5  str      x21, [sp, #0x80]
//   0x12e0b4: A9094FF4  stp      x20, x19, [sp, #0x90]
//   0x12e0b8: A90A7BFD  stp      x29, x30, [sp, #0xa0]
static inline uint64_t fde_func_2826_0x12e0ac(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x12e0acULL ^ (static_cast<uint64_t>(0xd102c3ffULL) << 13);
    acc = (acc + a1 + 0xf90043f5ULL) ^ 0x1e8db0ULL;
    acc ^= (acc >> 17) * 0x00b8ULL;
    return acc;
}

// FDE #2827 | PC: 0x12e164 | FDE: 0x1e8dd0 | Size: 76 bytes [BDPythonVMSetupUnicodeExtendedCase]
// Khung tháo gỡ #2827 | Địa chỉ PC: 0x12e164 | Địa chỉ FDE: 0x1e8dd0 | Kích thước: 76 bytes
//   0x12e164: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x12e168: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x12e16c: 910043FD  add      x29, sp, #0x10
//   0x12e170: AA0003F4  mov      x20, x0
static inline uint64_t fde_func_2827_0x12e164(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x12e164ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1e8dd0ULL;
    acc ^= (acc >> 17) * 0x004cULL;
    return acc;
}

// FDE #2828 | PC: 0x12e1b0 | FDE: 0x1e8df0 | Size: 256 bytes [BDPythonVMSetupSizeOptimizeFiles]
// Khung tháo gỡ #2828 | Địa chỉ PC: 0x12e1b0 | Địa chỉ FDE: 0x1e8df0 | Kích thước: 256 bytes
//   0x12e1b0: A9BA6FFC  stp      x28, x27, [sp, #-0x60]!
//   0x12e1b4: A90167FA  stp      x26, x25, [sp, #0x10]
//   0x12e1b8: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x12e1bc: A90357F6  stp      x22, x21, [sp, #0x30]
static inline uint64_t fde_func_2828_0x12e1b0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x12e1b0ULL ^ (static_cast<uint64_t>(0xa9ba6ffcULL) << 13);
    acc = (acc + a1 + 0xa90167faULL) ^ 0x1e8df0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #2829 | PC: 0x12e610 | FDE: 0x1e8e20 | Size: 164 bytes
// Khung tháo gỡ #2829 | Địa chỉ PC: 0x12e610 | Địa chỉ FDE: 0x1e8e20 | Kích thước: 164 bytes
//   0x12e610: D10483FF  sub      sp, sp, #0x120
//   0x12e614: A9104FFC  stp      x28, x19, [sp, #0x100]
//   0x12e618: A9117BFD  stp      x29, x30, [sp, #0x110]
//   0x12e61c: 910443FD  add      x29, sp, #0x110
static inline uint64_t fde_func_2829_0x12e610(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x12e610ULL ^ (static_cast<uint64_t>(0xd10483ffULL) << 13);
    acc = (acc + a1 + 0xa9104ffcULL) ^ 0x1e8e20ULL;
    acc ^= (acc >> 17) * 0x00a4ULL;
    return acc;
}

// FDE #2830 | PC: 0x12e6b4 | FDE: 0x1e8e40 | Size: 256 bytes
// Khung tháo gỡ #2830 | Địa chỉ PC: 0x12e6b4 | Địa chỉ FDE: 0x1e8e40 | Kích thước: 256 bytes
//   0x12e6b4: D102C3FF  sub      sp, sp, #0xb0
//   0x12e6b8: A90667FA  stp      x26, x25, [sp, #0x60]
//   0x12e6bc: A9075FF8  stp      x24, x23, [sp, #0x70]
//   0x12e6c0: A90857F6  stp      x22, x21, [sp, #0x80]
static inline uint64_t fde_func_2830_0x12e6b4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x12e6b4ULL ^ (static_cast<uint64_t>(0xd102c3ffULL) << 13);
    acc = (acc + a1 + 0xa90667faULL) ^ 0x1e8e40ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #2831 | PC: 0x12ec0c | FDE: 0x1e8e70 | Size: 256 bytes
// Khung tháo gỡ #2831 | Địa chỉ PC: 0x12ec0c | Địa chỉ FDE: 0x1e8e70 | Kích thước: 256 bytes
//   0x12ec0c: D10483FF  sub      sp, sp, #0x120
//   0x12ec10: A90C6FFC  stp      x28, x27, [sp, #0xc0]
//   0x12ec14: A90D67FA  stp      x26, x25, [sp, #0xd0]
//   0x12ec18: A90E5FF8  stp      x24, x23, [sp, #0xe0]
static inline uint64_t fde_func_2831_0x12ec0c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x12ec0cULL ^ (static_cast<uint64_t>(0xd10483ffULL) << 13);
    acc = (acc + a1 + 0xa90c6ffcULL) ^ 0x1e8e70ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #2832 | PC: 0x12f464 | FDE: 0x1e8ea0 | Size: 256 bytes
// Khung tháo gỡ #2832 | Địa chỉ PC: 0x12f464 | Địa chỉ FDE: 0x1e8ea0 | Kích thước: 256 bytes
//   0x12f464: D10283FF  sub      sp, sp, #0xa0
//   0x12f468: A9046FFC  stp      x28, x27, [sp, #0x40]
//   0x12f46c: A90567FA  stp      x26, x25, [sp, #0x50]
//   0x12f470: A9065FF8  stp      x24, x23, [sp, #0x60]
static inline uint64_t fde_func_2832_0x12f464(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x12f464ULL ^ (static_cast<uint64_t>(0xd10283ffULL) << 13);
    acc = (acc + a1 + 0xa9046ffcULL) ^ 0x1e8ea0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #2833 | PC: 0x12f8a4 | FDE: 0x1e8ed0 | Size: 52 bytes
// Khung tháo gỡ #2833 | Địa chỉ PC: 0x12f8a4 | Địa chỉ FDE: 0x1e8ed0 | Kích thước: 52 bytes
//   0x12f8a4: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x12f8a8: 910003FD  mov      x29, sp
//   0x12f8ac: 90000688  adrp     x8, #0x1ff000
//   0x12f8b0: F9464D08  ldr      x8, [x8, #0xc98]
static inline uint64_t fde_func_2833_0x12f8a4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x12f8a4ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1e8ed0ULL;
    acc ^= (acc >> 17) * 0x0034ULL;
    return acc;
}

// FDE #2834 | PC: 0x12f8d8 | FDE: 0x1e8ef0 | Size: 256 bytes [_PyRuntimeState_Init]
// Khung tháo gỡ #2834 | Địa chỉ PC: 0x12f8d8 | Địa chỉ FDE: 0x1e8ef0 | Kích thước: 256 bytes
//   0x12f8d8: D101C3FF  sub      sp, sp, #0x70
//   0x12f8dc: F9001BF7  str      x23, [sp, #0x30]
//   0x12f8e0: A90457F6  stp      x22, x21, [sp, #0x40]
//   0x12f8e4: A9054FF4  stp      x20, x19, [sp, #0x50]
static inline uint64_t fde_func_2834_0x12f8d8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x12f8d8ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xf9001bf7ULL) ^ 0x1e8ef0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #2835 | PC: 0x12fa44 | FDE: 0x1e8f18 | Size: 140 bytes [_PyRuntimeState_Fini]
// Khung tháo gỡ #2835 | Địa chỉ PC: 0x12fa44 | Địa chỉ FDE: 0x1e8f18 | Kích thước: 140 bytes
//   0x12fa44: D10143FF  sub      sp, sp, #0x50
//   0x12fa48: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x12fa4c: A9047BFD  stp      x29, x30, [sp, #0x40]
//   0x12fa50: 910103FD  add      x29, sp, #0x40
static inline uint64_t fde_func_2835_0x12fa44(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x12fa44ULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xa9034ff4ULL) ^ 0x1e8f18ULL;
    acc ^= (acc >> 17) * 0x008cULL;
    return acc;
}

// FDE #2836 | PC: 0x12fad0 | FDE: 0x1e8f38 | Size: 244 bytes [_PyRuntimeState_ReInitThreads]
// Khung tháo gỡ #2836 | Địa chỉ PC: 0x12fad0 | Địa chỉ FDE: 0x1e8f38 | Kích thước: 244 bytes
//   0x12fad0: D101C3FF  sub      sp, sp, #0x70
//   0x12fad4: A9035FF8  stp      x24, x23, [sp, #0x30]
//   0x12fad8: A90457F6  stp      x22, x21, [sp, #0x40]
//   0x12fadc: A9054FF4  stp      x20, x19, [sp, #0x50]
static inline uint64_t fde_func_2836_0x12fad0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x12fad0ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xa9035ff8ULL) ^ 0x1e8f38ULL;
    acc ^= (acc >> 17) * 0x00f4ULL;
    return acc;
}

// FDE #2837 | PC: 0x12fbc4 | FDE: 0x1e8f60 | Size: 184 bytes [_PyInterpreterState_Enable]
// Khung tháo gỡ #2837 | Địa chỉ PC: 0x12fbc4 | Địa chỉ FDE: 0x1e8f60 | Kích thước: 184 bytes
//   0x12fbc4: D10183FF  sub      sp, sp, #0x60
//   0x12fbc8: F9001BF5  str      x21, [sp, #0x30]
//   0x12fbcc: A9044FF4  stp      x20, x19, [sp, #0x40]
//   0x12fbd0: A9057BFD  stp      x29, x30, [sp, #0x50]
static inline uint64_t fde_func_2837_0x12fbc4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x12fbc4ULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xf9001bf5ULL) ^ 0x1e8f60ULL;
    acc ^= (acc >> 17) * 0x00b8ULL;
    return acc;
}

// FDE #2838 | PC: 0x12fc7c | FDE: 0x1e8f80 | Size: 256 bytes [PyInterpreterState_New]
// Khung tháo gỡ #2838 | Địa chỉ PC: 0x12fc7c | Địa chỉ FDE: 0x1e8f80 | Kích thước: 256 bytes
//   0x12fc7c: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x12fc80: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x12fc84: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x12fc88: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_2838_0x12fc7c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x12fc7cULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1e8f80ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #2839 | PC: 0x12fdcc | FDE: 0x1e8fa0 | Size: 52 bytes [PyInterpreterState_Clear]
// Khung tháo gỡ #2839 | Địa chỉ PC: 0x12fdcc | Địa chỉ FDE: 0x1e8fa0 | Kích thước: 52 bytes
//   0x12fdcc: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x12fdd0: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x12fdd4: 910043FD  add      x29, sp, #0x10
//   0x12fdd8: 90000688  adrp     x8, #0x1ff000
static inline uint64_t fde_func_2839_0x12fdcc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x12fdccULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1e8fa0ULL;
    acc ^= (acc >> 17) * 0x0034ULL;
    return acc;
}

// FDE #2840 | PC: 0x12fe00 | FDE: 0x1e8fc0 | Size: 256 bytes
// Khung tháo gỡ #2840 | Địa chỉ PC: 0x12fe00 | Địa chỉ FDE: 0x1e8fc0 | Kích thước: 256 bytes
//   0x12fe00: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x12fe04: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x12fe08: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x12fe0c: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_2840_0x12fe00(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x12fe00ULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1e8fc0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #2841 | PC: 0x130114 | FDE: 0x1e8fe8 | Size: 12 bytes [_PyInterpreterState_Clear]
// Khung tháo gỡ #2841 | Địa chỉ PC: 0x130114 | Địa chỉ FDE: 0x1e8fe8 | Kích thước: 12 bytes
//   0x130114: AA0003E1  mov      x1, x0
//   0x130118: F9400800  ldr      x0, [x0, #0x10]
//   0x13011c: 17FFFF39  b        #0x12fe00
static inline uint64_t fde_func_2841_0x130114(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x130114ULL ^ (static_cast<uint64_t>(0xaa0003e1ULL) << 13);
    acc = (acc + a1 + 0xf9400800ULL) ^ 0x1e8fe8ULL;
    acc ^= (acc >> 17) * 0x000cULL;
    return acc;
}

// FDE #2842 | PC: 0x130120 | FDE: 0x1e9000 | Size: 256 bytes [PyInterpreterState_Delete]
// Khung tháo gỡ #2842 | Địa chỉ PC: 0x130120 | Địa chỉ FDE: 0x1e9000 | Kích thước: 256 bytes
//   0x130120: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x130124: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x130128: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x13012c: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_2842_0x130120(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x130120ULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1e9000ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #2843 | PC: 0x130240 | FDE: 0x1e9020 | Size: 80 bytes [_PyThreadState_Swap]
// Khung tháo gỡ #2843 | Địa chỉ PC: 0x130240 | Địa chỉ FDE: 0x1e9020 | Kích thước: 80 bytes
//   0x130240: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x130244: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x130248: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x13024c: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_2843_0x130240(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x130240ULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1e9020ULL;
    acc ^= (acc >> 17) * 0x0050ULL;
    return acc;
}

// FDE #2844 | PC: 0x130290 | FDE: 0x1e9040 | Size: 256 bytes [_PyInterpreterState_DeleteExceptMain]
// Khung tháo gỡ #2844 | Địa chỉ PC: 0x130290 | Địa chỉ FDE: 0x1e9040 | Kích thước: 256 bytes
//   0x130290: A9BB67FA  stp      x26, x25, [sp, #-0x50]!
//   0x130294: A9015FF8  stp      x24, x23, [sp, #0x10]
//   0x130298: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x13029c: A9034FF4  stp      x20, x19, [sp, #0x30]
static inline uint64_t fde_func_2844_0x130290(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x130290ULL ^ (static_cast<uint64_t>(0xa9bb67faULL) << 13);
    acc = (acc + a1 + 0xa9015ff8ULL) ^ 0x1e9040ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #2845 | PC: 0x130434 | FDE: 0x1e9070 | Size: 76 bytes [PyInterpreterState_Get]
// Khung tháo gỡ #2845 | Địa chỉ PC: 0x130434 | Địa chỉ FDE: 0x1e9070 | Kích thước: 76 bytes
//   0x130434: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x130438: 910003FD  mov      x29, sp
//   0x13043c: F0000668  adrp     x8, #0x1ff000
//   0x130440: F943B908  ldr      x8, [x8, #0x770]
static inline uint64_t fde_func_2845_0x130434(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x130434ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1e9070ULL;
    acc ^= (acc >> 17) * 0x004cULL;
    return acc;
}

// FDE #2846 | PC: 0x130480 | FDE: 0x1e9090 | Size: 60 bytes [PyInterpreterState_GetID]
// Khung tháo gỡ #2846 | Địa chỉ PC: 0x130480 | Địa chỉ FDE: 0x1e9090 | Kích thước: 60 bytes
//   0x130480: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x130484: 910003FD  mov      x29, sp
//   0x130488: B4000080  cbz      x0, #0x130498
//   0x13048c: F9400C00  ldr      x0, [x0, #0x18]
static inline uint64_t fde_func_2846_0x130480(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x130480ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1e9090ULL;
    acc ^= (acc >> 17) * 0x003cULL;
    return acc;
}

// FDE #2847 | PC: 0x1304bc | FDE: 0x1e90b0 | Size: 156 bytes [_PyInterpreterState_LookUpID]
// Khung tháo gỡ #2847 | Địa chỉ PC: 0x1304bc | Địa chỉ FDE: 0x1e90b0 | Kích thước: 156 bytes
//   0x1304bc: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x1304c0: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x1304c4: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x1304c8: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_2847_0x1304bc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1304bcULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1e90b0ULL;
    acc ^= (acc >> 17) * 0x009cULL;
    return acc;
}

// FDE #2848 | PC: 0x130558 | FDE: 0x1e90d0 | Size: 96 bytes [_PyInterpreterState_IDInitref]
// Khung tháo gỡ #2848 | Địa chỉ PC: 0x130558 | Địa chỉ FDE: 0x1e90d0 | Kích thước: 96 bytes
//   0x130558: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x13055c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x130560: 910043FD  add      x29, sp, #0x10
//   0x130564: F9401808  ldr      x8, [x0, #0x30]
static inline uint64_t fde_func_2848_0x130558(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x130558ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1e90d0ULL;
    acc ^= (acc >> 17) * 0x0060ULL;
    return acc;
}

// FDE #2849 | PC: 0x1305b8 | FDE: 0x1e90f0 | Size: 116 bytes [_PyInterpreterState_IDIncref]
// Khung tháo gỡ #2849 | Địa chỉ PC: 0x1305b8 | Địa chỉ FDE: 0x1e90f0 | Kích thước: 116 bytes
//   0x1305b8: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x1305bc: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x1305c0: 910043FD  add      x29, sp, #0x10
//   0x1305c4: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_2849_0x1305b8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1305b8ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1e90f0ULL;
    acc ^= (acc >> 17) * 0x0074ULL;
    return acc;
}

// FDE #2850 | PC: 0x13062c | FDE: 0x1e9110 | Size: 168 bytes [_PyInterpreterState_IDDecref]
// Khung tháo gỡ #2850 | Địa chỉ PC: 0x13062c | Địa chỉ FDE: 0x1e9110 | Kích thước: 168 bytes
//   0x13062c: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x130630: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x130634: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x130638: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_2850_0x13062c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x13062cULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1e9110ULL;
    acc ^= (acc >> 17) * 0x00a8ULL;
    return acc;
}

// FDE #2851 | PC: 0x1306d4 | FDE: 0x1e9138 | Size: 8 bytes [PyInterpreterState_ThreadHead]
// Khung tháo gỡ #2851 | Địa chỉ PC: 0x1306d4 | Địa chỉ FDE: 0x1e9138 | Kích thước: 8 bytes
//   0x1306d4: F9400400  ldr      x0, [x0, #8]
//   0x1306d8: D65F03C0  ret      
static inline uint64_t fde_func_2851_0x1306d4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1306d4ULL ^ (static_cast<uint64_t>(0xf9400400ULL) << 13);
    acc = (acc + a1 + 0xd65f03c0ULL) ^ 0x1e9138ULL;
    acc ^= (acc >> 17) * 0x0008ULL;
    return acc;
}

// FDE #2852 | PC: 0x1306dc | FDE: 0x1e9150 | Size: 8 bytes [_PyInterpreterState_RequiresIDRef]
// Khung tháo gỡ #2852 | Địa chỉ PC: 0x1306dc | Địa chỉ FDE: 0x1e9150 | Kích thước: 8 bytes
//   0x1306dc: B9402800  ldr      w0, [x0, #0x28]
//   0x1306e0: D65F03C0  ret      
static inline uint64_t fde_func_2852_0x1306dc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1306dcULL ^ (static_cast<uint64_t>(0xb9402800ULL) << 13);
    acc = (acc + a1 + 0xd65f03c0ULL) ^ 0x1e9150ULL;
    acc ^= (acc >> 17) * 0x0008ULL;
    return acc;
}

// FDE #2853 | PC: 0x1306e4 | FDE: 0x1e9168 | Size: 16 bytes [_PyInterpreterState_RequireIDRef]
// Khung tháo gỡ #2853 | Địa chỉ PC: 0x1306e4 | Địa chỉ FDE: 0x1e9168 | Kích thước: 16 bytes
//   0x1306e4: 7100003F  cmp      w1, #0
//   0x1306e8: 1A9F07E8  cset     w8, ne
//   0x1306ec: B9002808  str      w8, [x0, #0x28]
//   0x1306f0: D65F03C0  ret      
static inline uint64_t fde_func_2853_0x1306e4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1306e4ULL ^ (static_cast<uint64_t>(0x7100003fULL) << 13);
    acc = (acc + a1 + 0x1a9f07e8ULL) ^ 0x1e9168ULL;
    acc ^= (acc >> 17) * 0x0010ULL;
    return acc;
}

// FDE #2854 | PC: 0x1306f4 | FDE: 0x1e9180 | Size: 68 bytes [_PyInterpreterState_GetMainModule]
// Khung tháo gỡ #2854 | Địa chỉ PC: 0x1306f4 | Địa chỉ FDE: 0x1e9180 | Kích thước: 68 bytes
//   0x1306f4: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x1306f8: 910003FD  mov      x29, sp
//   0x1306fc: F9421400  ldr      x0, [x0, #0x428]
//   0x130700: B40000A0  cbz      x0, #0x130714
static inline uint64_t fde_func_2854_0x1306f4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1306f4ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1e9180ULL;
    acc ^= (acc >> 17) * 0x0044ULL;
    return acc;
}

// FDE #2855 | PC: 0x130738 | FDE: 0x1e91a0 | Size: 56 bytes [PyInterpreterState_GetDict]
// Khung tháo gỡ #2855 | Địa chỉ PC: 0x130738 | Địa chỉ FDE: 0x1e91a0 | Kích thước: 56 bytes
//   0x130738: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x13073c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x130740: 910043FD  add      x29, sp, #0x10
//   0x130744: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_2855_0x130738(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x130738ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1e91a0ULL;
    acc ^= (acc >> 17) * 0x0038ULL;
    return acc;
}

// FDE #2856 | PC: 0x130770 | FDE: 0x1e91c0 | Size: 8 bytes [PyThreadState_New]
// Khung tháo gỡ #2856 | Địa chỉ PC: 0x130770 | Địa chỉ FDE: 0x1e91c0 | Kích thước: 8 bytes
//   0x130770: 52800021  mov      w1, #1
//   0x130774: 14000001  b        #0x130778
static inline uint64_t fde_func_2856_0x130770(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x130770ULL ^ (static_cast<uint64_t>(0x52800021ULL) << 13);
    acc = (acc + a1 + 0x14000001ULL) ^ 0x1e91c0ULL;
    acc ^= (acc >> 17) * 0x0008ULL;
    return acc;
}

// FDE #2857 | PC: 0x130778 | FDE: 0x1e91d8 | Size: 256 bytes
// Khung tháo gỡ #2857 | Địa chỉ PC: 0x130778 | Địa chỉ FDE: 0x1e91d8 | Kích thước: 256 bytes
//   0x130778: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x13077c: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x130780: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x130784: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_2857_0x130778(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x130778ULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1e91d8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #2858 | PC: 0x1308ac | FDE: 0x1e9200 | Size: 8 bytes [_PyThreadState_Prealloc]
// Khung tháo gỡ #2858 | Địa chỉ PC: 0x1308ac | Địa chỉ FDE: 0x1e9200 | Kích thước: 8 bytes
//   0x1308ac: 2A1F03E1  mov      w1, wzr
//   0x1308b0: 17FFFFB2  b        #0x130778
static inline uint64_t fde_func_2858_0x1308ac(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1308acULL ^ (static_cast<uint64_t>(0x2a1f03e1ULL) << 13);
    acc = (acc + a1 + 0x17ffffb2ULL) ^ 0x1e9200ULL;
    acc ^= (acc >> 17) * 0x0008ULL;
    return acc;
}

// FDE #2859 | PC: 0x1308b4 | FDE: 0x1e9218 | Size: 104 bytes [_PyThreadState_Init]
// Khung tháo gỡ #2859 | Địa chỉ PC: 0x1308b4 | Địa chỉ FDE: 0x1e9218 | Kích thước: 104 bytes
//   0x1308b4: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x1308b8: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x1308bc: 910043FD  add      x29, sp, #0x10
//   0x1308c0: F9400808  ldr      x8, [x0, #0x10]
static inline uint64_t fde_func_2859_0x1308b4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1308b4ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1e9218ULL;
    acc ^= (acc >> 17) * 0x0068ULL;
    return acc;
}

// FDE #2860 | PC: 0x13091c | FDE: 0x1e9238 | Size: 124 bytes [PyState_FindModule]
// Khung tháo gỡ #2860 | Địa chỉ PC: 0x13091c | Địa chỉ FDE: 0x1e9238 | Kích thước: 124 bytes
//   0x13091c: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x130920: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x130924: 910043FD  add      x29, sp, #0x10
//   0x130928: F0000668  adrp     x8, #0x1ff000
static inline uint64_t fde_func_2860_0x13091c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x13091cULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1e9238ULL;
    acc ^= (acc >> 17) * 0x007cULL;
    return acc;
}

// FDE #2861 | PC: 0x130998 | FDE: 0x1e9258 | Size: 192 bytes [_PyState_AddModule]
// Khung tháo gỡ #2861 | Địa chỉ PC: 0x130998 | Địa chỉ FDE: 0x1e9258 | Kích thước: 192 bytes
//   0x130998: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x13099c: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x1309a0: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x1309a4: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_2861_0x130998(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x130998ULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1e9258ULL;
    acc ^= (acc >> 17) * 0x00c0ULL;
    return acc;
}

// FDE #2862 | PC: 0x130a58 | FDE: 0x1e9280 | Size: 148 bytes [PyState_AddModule]
// Khung tháo gỡ #2862 | Địa chỉ PC: 0x130a58 | Địa chỉ FDE: 0x1e9280 | Kích thước: 148 bytes
//   0x130a58: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x130a5c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x130a60: 910043FD  add      x29, sp, #0x10
//   0x130a64: B40002E1  cbz      x1, #0x130ac0
static inline uint64_t fde_func_2862_0x130a58(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x130a58ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1e9280ULL;
    acc ^= (acc >> 17) * 0x0094ULL;
    return acc;
}

// FDE #2863 | PC: 0x130aec | FDE: 0x1e92a0 | Size: 204 bytes [PyState_RemoveModule]
// Khung tháo gỡ #2863 | Địa chỉ PC: 0x130aec | Địa chỉ FDE: 0x1e92a0 | Kích thước: 204 bytes
//   0x130aec: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x130af0: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x130af4: 910043FD  add      x29, sp, #0x10
//   0x130af8: F0000668  adrp     x8, #0x1ff000
static inline uint64_t fde_func_2863_0x130aec(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x130aecULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1e92a0ULL;
    acc ^= (acc >> 17) * 0x00ccULL;
    return acc;
}

// FDE #2864 | PC: 0x130bb8 | FDE: 0x1e92c0 | Size: 212 bytes [_PyInterpreterState_ClearModules]
// Khung tháo gỡ #2864 | Địa chỉ PC: 0x130bb8 | Địa chỉ FDE: 0x1e92c0 | Kích thước: 212 bytes
//   0x130bb8: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x130bbc: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x130bc0: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x130bc4: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_2864_0x130bb8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x130bb8ULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1e92c0ULL;
    acc ^= (acc >> 17) * 0x00d4ULL;
    return acc;
}

// FDE #2865 | PC: 0x130c8c | FDE: 0x1e92e8 | Size: 256 bytes [PyThreadState_Clear]
// Khung tháo gỡ #2865 | Địa chỉ PC: 0x130c8c | Địa chỉ FDE: 0x1e92e8 | Kích thước: 256 bytes
//   0x130c8c: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x130c90: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x130c94: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x130c98: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_2865_0x130c8c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x130c8cULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1e92e8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #2866 | PC: 0x130f44 | FDE: 0x1e9310 | Size: 8 bytes [_PyInterpreterState_GetConfig]
// Khung tháo gỡ #2866 | Địa chỉ PC: 0x130f44 | Địa chỉ FDE: 0x1e9310 | Kích thước: 8 bytes
//   0x130f44: 91120000  add      x0, x0, #0x480
//   0x130f48: D65F03C0  ret      
static inline uint64_t fde_func_2866_0x130f44(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x130f44ULL ^ (static_cast<uint64_t>(0x91120000ULL) << 13);
    acc = (acc + a1 + 0xd65f03c0ULL) ^ 0x1e9310ULL;
    acc ^= (acc >> 17) * 0x0008ULL;
    return acc;
}

// FDE #2867 | PC: 0x130f4c | FDE: 0x1e9328 | Size: 88 bytes [PyThreadState_Delete]
// Khung tháo gỡ #2867 | Địa chỉ PC: 0x130f4c | Địa chỉ FDE: 0x1e9328 | Kích thước: 88 bytes
//   0x130f4c: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x130f50: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x130f54: 910043FD  add      x29, sp, #0x10
//   0x130f58: F9400808  ldr      x8, [x0, #0x10]
static inline uint64_t fde_func_2867_0x130f4c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x130f4cULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1e9328ULL;
    acc ^= (acc >> 17) * 0x0058ULL;
    return acc;
}

// FDE #2868 | PC: 0x130fa4 | FDE: 0x1e9348 | Size: 76 bytes [_PyThreadState_DeleteCurrent]
// Khung tháo gỡ #2868 | Địa chỉ PC: 0x130fa4 | Địa chỉ FDE: 0x1e9348 | Kích thước: 76 bytes
//   0x130fa4: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x130fa8: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x130fac: 910043FD  add      x29, sp, #0x10
//   0x130fb0: B40001A0  cbz      x0, #0x130fe4
static inline uint64_t fde_func_2868_0x130fa4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x130fa4ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1e9348ULL;
    acc ^= (acc >> 17) * 0x004cULL;
    return acc;
}

// FDE #2869 | PC: 0x130ff0 | FDE: 0x1e9368 | Size: 196 bytes
// Khung tháo gỡ #2869 | Địa chỉ PC: 0x130ff0 | Địa chỉ FDE: 0x1e9368 | Kích thước: 196 bytes
//   0x130ff0: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x130ff4: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x130ff8: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x130ffc: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_2869_0x130ff0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x130ff0ULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1e9368ULL;
    acc ^= (acc >> 17) * 0x00c4ULL;
    return acc;
}

// FDE #2870 | PC: 0x1310b4 | FDE: 0x1e9390 | Size: 88 bytes [PyThreadState_DeleteCurrent]
// Khung tháo gỡ #2870 | Địa chỉ PC: 0x1310b4 | Địa chỉ FDE: 0x1e9390 | Kích thước: 88 bytes
//   0x1310b4: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x1310b8: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x1310bc: 910043FD  add      x29, sp, #0x10
//   0x1310c0: D0000668  adrp     x8, #0x1ff000
static inline uint64_t fde_func_2870_0x1310b4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1310b4ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1e9390ULL;
    acc ^= (acc >> 17) * 0x0058ULL;
    return acc;
}

// FDE #2871 | PC: 0x13110c | FDE: 0x1e93b0 | Size: 160 bytes [_PyThreadState_DeleteExcept]
// Khung tháo gỡ #2871 | Địa chỉ PC: 0x13110c | Địa chỉ FDE: 0x1e93b0 | Kích thước: 160 bytes
//   0x13110c: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x131110: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x131114: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x131118: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_2871_0x13110c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x13110cULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1e93b0ULL;
    acc ^= (acc >> 17) * 0x00a0ULL;
    return acc;
}

// FDE #2872 | PC: 0x1311ac | FDE: 0x1e93d8 | Size: 16 bytes [_PyThreadState_GetTSS]
// Khung tháo gỡ #2872 | Địa chỉ PC: 0x1311ac | Địa chỉ FDE: 0x1e93d8 | Kích thước: 16 bytes
//   0x1311ac: D0000668  adrp     x8, #0x1ff000
//   0x1311b0: F943B908  ldr      x8, [x8, #0x770]
//   0x1311b4: 9105C100  add      x0, x8, #0x170
//   0x1311b8: 17FCAF92  b        #0x5d000
static inline uint64_t fde_func_2872_0x1311ac(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1311acULL ^ (static_cast<uint64_t>(0xd0000668ULL) << 13);
    acc = (acc + a1 + 0xf943b908ULL) ^ 0x1e93d8ULL;
    acc ^= (acc >> 17) * 0x0010ULL;
    return acc;
}

// FDE #2873 | PC: 0x1311bc | FDE: 0x1e93f0 | Size: 16 bytes [_PyThreadState_UncheckedGet]
// Khung tháo gỡ #2873 | Địa chỉ PC: 0x1311bc | Địa chỉ FDE: 0x1e93f0 | Kích thước: 16 bytes
//   0x1311bc: D0000668  adrp     x8, #0x1ff000
//   0x1311c0: F943B908  ldr      x8, [x8, #0x770]
//   0x1311c4: 9105C100  add      x0, x8, #0x170
//   0x1311c8: 17FCAF8E  b        #0x5d000
static inline uint64_t fde_func_2873_0x1311bc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1311bcULL ^ (static_cast<uint64_t>(0xd0000668ULL) << 13);
    acc = (acc + a1 + 0xf943b908ULL) ^ 0x1e93f0ULL;
    acc ^= (acc >> 17) * 0x0010ULL;
    return acc;
}

// FDE #2874 | PC: 0x1311cc | FDE: 0x1e9408 | Size: 48 bytes [PyThreadState_Get]
// Khung tháo gỡ #2874 | Địa chỉ PC: 0x1311cc | Địa chỉ FDE: 0x1e9408 | Kích thước: 48 bytes
//   0x1311cc: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x1311d0: 910003FD  mov      x29, sp
//   0x1311d4: D0000668  adrp     x8, #0x1ff000
//   0x1311d8: F943B908  ldr      x8, [x8, #0x770]
static inline uint64_t fde_func_2874_0x1311cc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1311ccULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1e9408ULL;
    acc ^= (acc >> 17) * 0x0030ULL;
    return acc;
}

// FDE #2875 | PC: 0x1311fc | FDE: 0x1e9428 | Size: 80 bytes [PyThreadState_Swap]
// Khung tháo gỡ #2875 | Địa chỉ PC: 0x1311fc | Địa chỉ FDE: 0x1e9428 | Kích thước: 80 bytes
//   0x1311fc: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x131200: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x131204: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x131208: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_2875_0x1311fc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1311fcULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1e9428ULL;
    acc ^= (acc >> 17) * 0x0050ULL;
    return acc;
}

// FDE #2876 | PC: 0x13124c | FDE: 0x1e9450 | Size: 60 bytes [_PyThreadState_GetDict]
// Khung tháo gỡ #2876 | Địa chỉ PC: 0x13124c | Địa chỉ FDE: 0x1e9450 | Kích thước: 60 bytes
//   0x13124c: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x131250: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x131254: 910043FD  add      x29, sp, #0x10
//   0x131258: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_2876_0x13124c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x13124cULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1e9450ULL;
    acc ^= (acc >> 17) * 0x003cULL;
    return acc;
}

// FDE #2877 | PC: 0x131288 | FDE: 0x1e9470 | Size: 80 bytes [PyThreadState_GetDict]
// Khung tháo gỡ #2877 | Địa chỉ PC: 0x131288 | Địa chỉ FDE: 0x1e9470 | Kích thước: 80 bytes
//   0x131288: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x13128c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x131290: 910043FD  add      x29, sp, #0x10
//   0x131294: D0000668  adrp     x8, #0x1ff000
static inline uint64_t fde_func_2877_0x131288(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x131288ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1e9470ULL;
    acc ^= (acc >> 17) * 0x0050ULL;
    return acc;
}

// FDE #2878 | PC: 0x1312d8 | FDE: 0x1e9490 | Size: 8 bytes [PyThreadState_GetInterpreter]
// Khung tháo gỡ #2878 | Địa chỉ PC: 0x1312d8 | Địa chỉ FDE: 0x1e9490 | Kích thước: 8 bytes
//   0x1312d8: F9400800  ldr      x0, [x0, #0x10]
//   0x1312dc: D65F03C0  ret      
static inline uint64_t fde_func_2878_0x1312d8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1312d8ULL ^ (static_cast<uint64_t>(0xf9400800ULL) << 13);
    acc = (acc + a1 + 0xd65f03c0ULL) ^ 0x1e9490ULL;
    acc ^= (acc >> 17) * 0x0008ULL;
    return acc;
}

// FDE #2879 | PC: 0x1312e0 | FDE: 0x1e94a8 | Size: 24 bytes [PyThreadState_GetFrame]
// Khung tháo gỡ #2879 | Địa chỉ PC: 0x1312e0 | Địa chỉ FDE: 0x1e94a8 | Kích thước: 24 bytes
//   0x1312e0: F9400C00  ldr      x0, [x0, #0x18]
//   0x1312e4: B4000080  cbz      x0, #0x1312f4
//   0x1312e8: F9400008  ldr      x8, [x0]
//   0x1312ec: 91000508  add      x8, x8, #1
static inline uint64_t fde_func_2879_0x1312e0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1312e0ULL ^ (static_cast<uint64_t>(0xf9400c00ULL) << 13);
    acc = (acc + a1 + 0xb4000080ULL) ^ 0x1e94a8ULL;
    acc ^= (acc >> 17) * 0x0018ULL;
    return acc;
}

// FDE #2880 | PC: 0x1312f8 | FDE: 0x1e94c0 | Size: 8 bytes [PyThreadState_GetID]
// Khung tháo gỡ #2880 | Địa chỉ PC: 0x1312f8 | Địa chỉ FDE: 0x1e94c0 | Kích thước: 8 bytes
//   0x1312f8: F9408000  ldr      x0, [x0, #0x100]
//   0x1312fc: D65F03C0  ret      
static inline uint64_t fde_func_2880_0x1312f8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1312f8ULL ^ (static_cast<uint64_t>(0xf9408000ULL) << 13);
    acc = (acc + a1 + 0xd65f03c0ULL) ^ 0x1e94c0ULL;
    acc ^= (acc >> 17) * 0x0008ULL;
    return acc;
}

// FDE #2881 | PC: 0x131300 | FDE: 0x1e94d8 | Size: 180 bytes [PyThreadState_SetAsyncExc]
// Khung tháo gỡ #2881 | Địa chỉ PC: 0x131300 | Địa chỉ FDE: 0x1e94d8 | Kích thước: 180 bytes
//   0x131300: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x131304: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x131308: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x13130c: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_2881_0x131300(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x131300ULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1e94d8ULL;
    acc ^= (acc >> 17) * 0x00b4ULL;
    return acc;
}

// FDE #2882 | PC: 0x1313b4 | FDE: 0x1e9500 | Size: 16 bytes [PyInterpreterState_Head]
// Khung tháo gỡ #2882 | Địa chỉ PC: 0x1313b4 | Địa chỉ FDE: 0x1e9500 | Kích thước: 16 bytes
//   0x1313b4: D0000668  adrp     x8, #0x1ff000
//   0x1313b8: F943B908  ldr      x8, [x8, #0x770]
//   0x1313bc: F9401100  ldr      x0, [x8, #0x20]
//   0x1313c0: D65F03C0  ret      
static inline uint64_t fde_func_2882_0x1313b4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1313b4ULL ^ (static_cast<uint64_t>(0xd0000668ULL) << 13);
    acc = (acc + a1 + 0xf943b908ULL) ^ 0x1e9500ULL;
    acc ^= (acc >> 17) * 0x0010ULL;
    return acc;
}

// FDE #2883 | PC: 0x1313c4 | FDE: 0x1e9518 | Size: 16 bytes [PyInterpreterState_Main]
// Khung tháo gỡ #2883 | Địa chỉ PC: 0x1313c4 | Địa chỉ FDE: 0x1e9518 | Kích thước: 16 bytes
//   0x1313c4: D0000668  adrp     x8, #0x1ff000
//   0x1313c8: F943B908  ldr      x8, [x8, #0x770]
//   0x1313cc: F9401500  ldr      x0, [x8, #0x28]
//   0x1313d0: D65F03C0  ret      
static inline uint64_t fde_func_2883_0x1313c4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1313c4ULL ^ (static_cast<uint64_t>(0xd0000668ULL) << 13);
    acc = (acc + a1 + 0xf943b908ULL) ^ 0x1e9518ULL;
    acc ^= (acc >> 17) * 0x0010ULL;
    return acc;
}

// FDE #2884 | PC: 0x1313d4 | FDE: 0x1e9530 | Size: 8 bytes [PyInterpreterState_Next]
// Khung tháo gỡ #2884 | Địa chỉ PC: 0x1313d4 | Địa chỉ FDE: 0x1e9530 | Kích thước: 8 bytes
//   0x1313d4: F9400000  ldr      x0, [x0]
//   0x1313d8: D65F03C0  ret      
static inline uint64_t fde_func_2884_0x1313d4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1313d4ULL ^ (static_cast<uint64_t>(0xf9400000ULL) << 13);
    acc = (acc + a1 + 0xd65f03c0ULL) ^ 0x1e9530ULL;
    acc ^= (acc >> 17) * 0x0008ULL;
    return acc;
}

// FDE #2885 | PC: 0x1313dc | FDE: 0x1e9548 | Size: 8 bytes [PyThreadState_Next]
// Khung tháo gỡ #2885 | Địa chỉ PC: 0x1313dc | Địa chỉ FDE: 0x1e9548 | Kích thước: 8 bytes
//   0x1313dc: F9400400  ldr      x0, [x0, #8]
//   0x1313e0: D65F03C0  ret      
static inline uint64_t fde_func_2885_0x1313dc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1313dcULL ^ (static_cast<uint64_t>(0xf9400400ULL) << 13);
    acc = (acc + a1 + 0xd65f03c0ULL) ^ 0x1e9548ULL;
    acc ^= (acc >> 17) * 0x0008ULL;
    return acc;
}

// FDE #2886 | PC: 0x1313e4 | FDE: 0x1e9560 | Size: 256 bytes [_PyThread_CurrentFrames]
// Khung tháo gỡ #2886 | Địa chỉ PC: 0x1313e4 | Địa chỉ FDE: 0x1e9560 | Kích thước: 256 bytes
//   0x1313e4: A9BC5FF8  stp      x24, x23, [sp, #-0x40]!
//   0x1313e8: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x1313ec: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x1313f0: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_2886_0x1313e4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1313e4ULL ^ (static_cast<uint64_t>(0xa9bc5ff8ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x1e9560ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #2887 | PC: 0x1314f8 | FDE: 0x1e9588 | Size: 256 bytes [_PyThread_CurrentExceptions]
// Khung tháo gỡ #2887 | Địa chỉ PC: 0x1314f8 | Địa chỉ FDE: 0x1e9588 | Kích thước: 256 bytes
//   0x1314f8: A9BB67FA  stp      x26, x25, [sp, #-0x50]!
//   0x1314fc: A9015FF8  stp      x24, x23, [sp, #0x10]
//   0x131500: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x131504: A9034FF4  stp      x20, x19, [sp, #0x30]
static inline uint64_t fde_func_2887_0x1314f8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1314f8ULL ^ (static_cast<uint64_t>(0xa9bb67faULL) << 13);
    acc = (acc + a1 + 0xa9015ff8ULL) ^ 0x1e9588ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #2888 | PC: 0x131690 | FDE: 0x1e95b8 | Size: 96 bytes [_PyGILState_Init]
// Khung tháo gỡ #2888 | Địa chỉ PC: 0x131690 | Địa chỉ FDE: 0x1e95b8 | Kích thước: 96 bytes
//   0x131690: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x131694: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x131698: 910043FD  add      x29, sp, #0x10
//   0x13169c: 9105C000  add      x0, x0, #0x170
static inline uint64_t fde_func_2888_0x131690(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x131690ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1e95b8ULL;
    acc ^= (acc >> 17) * 0x0060ULL;
    return acc;
}

// FDE #2889 | PC: 0x1316f0 | FDE: 0x1e95d8 | Size: 144 bytes [_PyGILState_SetTstate]
// Khung tháo gỡ #2889 | Địa chỉ PC: 0x1316f0 | Địa chỉ FDE: 0x1e95d8 | Kích thước: 144 bytes
//   0x1316f0: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x1316f4: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x1316f8: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x1316fc: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_2889_0x1316f0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1316f0ULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1e95d8ULL;
    acc ^= (acc >> 17) * 0x0090ULL;
    return acc;
}

// FDE #2890 | PC: 0x131780 | FDE: 0x1e95f8 | Size: 16 bytes [_PyGILState_GetInterpreterStateUnsafe]
// Khung tháo gỡ #2890 | Địa chỉ PC: 0x131780 | Địa chỉ FDE: 0x1e95f8 | Kích thước: 16 bytes
//   0x131780: D0000668  adrp     x8, #0x1ff000
//   0x131784: F943B908  ldr      x8, [x8, #0x770]
//   0x131788: F940B500  ldr      x0, [x8, #0x168]
//   0x13178c: D65F03C0  ret      
static inline uint64_t fde_func_2890_0x131780(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x131780ULL ^ (static_cast<uint64_t>(0xd0000668ULL) << 13);
    acc = (acc + a1 + 0xf943b908ULL) ^ 0x1e95f8ULL;
    acc ^= (acc >> 17) * 0x0010ULL;
    return acc;
}

// FDE #2891 | PC: 0x131790 | FDE: 0x1e9610 | Size: 40 bytes [_PyGILState_Fini]
// Khung tháo gỡ #2891 | Địa chỉ PC: 0x131790 | Địa chỉ FDE: 0x1e9610 | Kích thước: 40 bytes
//   0x131790: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x131794: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x131798: 910043FD  add      x29, sp, #0x10
//   0x13179c: F9400813  ldr      x19, [x0, #0x10]
static inline uint64_t fde_func_2891_0x131790(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x131790ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1e9610ULL;
    acc ^= (acc >> 17) * 0x0028ULL;
    return acc;
}

// FDE #2892 | PC: 0x1317b8 | FDE: 0x1e9630 | Size: 188 bytes [_PyGILState_Reinit]
// Khung tháo gỡ #2892 | Địa chỉ PC: 0x1317b8 | Địa chỉ FDE: 0x1e9630 | Kích thước: 188 bytes
//   0x1317b8: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x1317bc: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x1317c0: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x1317c4: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_2892_0x1317b8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1317b8ULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1e9630ULL;
    acc ^= (acc >> 17) * 0x00bcULL;
    return acc;
}

// FDE #2893 | PC: 0x131874 | FDE: 0x1e9650 | Size: 32 bytes [PyGILState_GetThisThreadState]
// Khung tháo gỡ #2893 | Địa chỉ PC: 0x131874 | Địa chỉ FDE: 0x1e9650 | Kích thước: 32 bytes
//   0x131874: D0000668  adrp     x8, #0x1ff000
//   0x131878: F943B908  ldr      x8, [x8, #0x770]
//   0x13187c: F940B509  ldr      x9, [x8, #0x168]
//   0x131880: B4000069  cbz      x9, #0x13188c
static inline uint64_t fde_func_2893_0x131874(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x131874ULL ^ (static_cast<uint64_t>(0xd0000668ULL) << 13);
    acc = (acc + a1 + 0xf943b908ULL) ^ 0x1e9650ULL;
    acc ^= (acc >> 17) * 0x0020ULL;
    return acc;
}

// FDE #2894 | PC: 0x131894 | FDE: 0x1e9668 | Size: 108 bytes [PyGILState_Check]
// Khung tháo gỡ #2894 | Địa chỉ PC: 0x131894 | Địa chỉ FDE: 0x1e9668 | Kích thước: 108 bytes
//   0x131894: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x131898: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x13189c: 910043FD  add      x29, sp, #0x10
//   0x1318a0: D0000674  adrp     x20, #0x1ff000
static inline uint64_t fde_func_2894_0x131894(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x131894ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1e9668ULL;
    acc ^= (acc >> 17) * 0x006cULL;
    return acc;
}

// FDE #2895 | PC: 0x131900 | FDE: 0x1e9688 | Size: 140 bytes [PyGILState_Ensure]
// Khung tháo gỡ #2895 | Địa chỉ PC: 0x131900 | Địa chỉ FDE: 0x1e9688 | Kích thước: 140 bytes
//   0x131900: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x131904: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x131908: 910043FD  add      x29, sp, #0x10
//   0x13190c: D0000674  adrp     x20, #0x1ff000
static inline uint64_t fde_func_2895_0x131900(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x131900ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1e9688ULL;
    acc ^= (acc >> 17) * 0x008cULL;
    return acc;
}

// FDE #2896 | PC: 0x13198c | FDE: 0x1e96a8 | Size: 144 bytes [PyGILState_EnsureWithInterpreterState]
// Khung tháo gỡ #2896 | Địa chỉ PC: 0x13198c | Địa chỉ FDE: 0x1e96a8 | Kích thước: 144 bytes
//   0x13198c: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x131990: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x131994: 910043FD  add      x29, sp, #0x10
//   0x131998: D0000668  adrp     x8, #0x1ff000
static inline uint64_t fde_func_2896_0x13198c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x13198cULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1e96a8ULL;
    acc ^= (acc >> 17) * 0x0090ULL;
    return acc;
}

// FDE #2897 | PC: 0x131a1c | FDE: 0x1e96c8 | Size: 204 bytes [PyGILState_Release]
// Khung tháo gỡ #2897 | Địa chỉ PC: 0x131a1c | Địa chỉ FDE: 0x1e96c8 | Kích thước: 204 bytes
//   0x131a1c: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x131a20: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x131a24: 910043FD  add      x29, sp, #0x10
//   0x131a28: D0000668  adrp     x8, #0x1ff000
static inline uint64_t fde_func_2897_0x131a1c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x131a1cULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1e96c8ULL;
    acc ^= (acc >> 17) * 0x00ccULL;
    return acc;
}

// FDE #2898 | PC: 0x131ae8 | FDE: 0x1e96e8 | Size: 84 bytes [_PyObject_CheckCrossInterpreterData]
// Khung tháo gỡ #2898 | Địa chỉ PC: 0x131ae8 | Địa chỉ FDE: 0x1e96e8 | Kích thước: 84 bytes
//   0x131ae8: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x131aec: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x131af0: 910043FD  add      x29, sp, #0x10
//   0x131af4: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_2898_0x131ae8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x131ae8ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1e96e8ULL;
    acc ^= (acc >> 17) * 0x0054ULL;
    return acc;
}

// FDE #2899 | PC: 0x131b3c | FDE: 0x1e9708 | Size: 256 bytes [_PyObject_GetCrossInterpreterData]
// Khung tháo gỡ #2899 | Địa chỉ PC: 0x131b3c | Địa chỉ FDE: 0x1e9708 | Kích thước: 256 bytes
//   0x131b3c: F81C0FF7  str      x23, [sp, #-0x40]!
//   0x131b40: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x131b44: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x131b48: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_2899_0x131b3c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x131b3cULL ^ (static_cast<uint64_t>(0xf81c0ff7ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x1e9708ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #2900 | PC: 0x131c88 | FDE: 0x1e9730 | Size: 244 bytes [_PyCrossInterpreterData_Release]
// Khung tháo gỡ #2900 | Địa chỉ PC: 0x131c88 | Địa chỉ FDE: 0x1e9730 | Kích thước: 244 bytes
//   0x131c88: F81C0FF7  str      x23, [sp, #-0x40]!
//   0x131c8c: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x131c90: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x131c94: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_2900_0x131c88(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x131c88ULL ^ (static_cast<uint64_t>(0xf81c0ff7ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x1e9730ULL;
    acc ^= (acc >> 17) * 0x00f4ULL;
    return acc;
}

// FDE #2901 | PC: 0x131d7c | FDE: 0x1e9758 | Size: 8 bytes [_PyCrossInterpreterData_NewObject]
// Khung tháo gỡ #2901 | Địa chỉ PC: 0x131d7c | Địa chỉ FDE: 0x1e9758 | Kích thước: 8 bytes
//   0x131d7c: F9400C01  ldr      x1, [x0, #0x18]
//   0x131d80: D61F0020  br       x1
static inline uint64_t fde_func_2901_0x131d7c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x131d7cULL ^ (static_cast<uint64_t>(0xf9400c01ULL) << 13);
    acc = (acc + a1 + 0xd61f0020ULL) ^ 0x1e9758ULL;
    acc ^= (acc >> 17) * 0x0008ULL;
    return acc;
}

// FDE #2902 | PC: 0x131d84 | FDE: 0x1e9770 | Size: 204 bytes [_PyCrossInterpreterData_RegisterClass]
// Khung tháo gỡ #2902 | Địa chỉ PC: 0x131d84 | Địa chỉ FDE: 0x1e9770 | Kích thước: 204 bytes
//   0x131d84: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x131d88: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x131d8c: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x131d90: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_2902_0x131d84(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x131d84ULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1e9770ULL;
    acc ^= (acc >> 17) * 0x00ccULL;
    return acc;
}

// FDE #2903 | PC: 0x131e50 | FDE: 0x1e9798 | Size: 256 bytes
// Khung tháo gỡ #2903 | Địa chỉ PC: 0x131e50 | Địa chỉ FDE: 0x1e9798 | Kích thước: 256 bytes
//   0x131e50: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x131e54: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x131e58: 910043FD  add      x29, sp, #0x10
//   0x131e5c: D0000660  adrp     x0, #0x1ff000
static inline uint64_t fde_func_2903_0x131e50(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x131e50ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1e9798ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #2904 | PC: 0x131f78 | FDE: 0x1e97b8 | Size: 152 bytes [_PyCrossInterpreterData_Lookup]
// Khung tháo gỡ #2904 | Địa chỉ PC: 0x131f78 | Địa chỉ FDE: 0x1e97b8 | Kích thước: 152 bytes
//   0x131f78: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x131f7c: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x131f80: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x131f84: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_2904_0x131f78(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x131f78ULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1e97b8ULL;
    acc ^= (acc >> 17) * 0x0098ULL;
    return acc;
}

// FDE #2905 | PC: 0x132010 | FDE: 0x1e97d8 | Size: 8 bytes [_PyInterpreterState_GetEvalFrameFunc]
// Khung tháo gỡ #2905 | Địa chỉ PC: 0x132010 | Địa chỉ FDE: 0x1e97d8 | Kích thước: 8 bytes
//   0x132010: F9431400  ldr      x0, [x0, #0x628]
//   0x132014: D65F03C0  ret      
static inline uint64_t fde_func_2905_0x132010(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x132010ULL ^ (static_cast<uint64_t>(0xf9431400ULL) << 13);
    acc = (acc + a1 + 0xd65f03c0ULL) ^ 0x1e97d8ULL;
    acc ^= (acc >> 17) * 0x0008ULL;
    return acc;
}

// FDE #2906 | PC: 0x132018 | FDE: 0x1e97f0 | Size: 8 bytes [_PyInterpreterState_SetEvalFrameFunc]
// Khung tháo gỡ #2906 | Địa chỉ PC: 0x132018 | Địa chỉ FDE: 0x1e97f0 | Kích thước: 8 bytes
//   0x132018: F9031401  str      x1, [x0, #0x628]
//   0x13201c: D65F03C0  ret      
static inline uint64_t fde_func_2906_0x132018(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x132018ULL ^ (static_cast<uint64_t>(0xf9031401ULL) << 13);
    acc = (acc + a1 + 0xd65f03c0ULL) ^ 0x1e97f0ULL;
    acc ^= (acc >> 17) * 0x0008ULL;
    return acc;
}

// FDE #2907 | PC: 0x132020 | FDE: 0x1e9808 | Size: 192 bytes [_PyInterpreterState_GetConfigCopy]
// Khung tháo gỡ #2907 | Địa chỉ PC: 0x132020 | Địa chỉ FDE: 0x1e9808 | Kích thước: 192 bytes
//   0x132020: D10243FF  sub      sp, sp, #0x90
//   0x132024: A9074FF4  stp      x20, x19, [sp, #0x70]
//   0x132028: A9087BFD  stp      x29, x30, [sp, #0x80]
//   0x13202c: 910203FD  add      x29, sp, #0x80
static inline uint64_t fde_func_2907_0x132020(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x132020ULL ^ (static_cast<uint64_t>(0xd10243ffULL) << 13);
    acc = (acc + a1 + 0xa9074ff4ULL) ^ 0x1e9808ULL;
    acc ^= (acc >> 17) * 0x00c0ULL;
    return acc;
}

// FDE #2908 | PC: 0x1320e0 | FDE: 0x1e9828 | Size: 16 bytes [BD_PyInterpreterState_SetStuckCallback]
// Khung tháo gỡ #2908 | Địa chỉ PC: 0x1320e0 | Địa chỉ FDE: 0x1e9828 | Kích thước: 16 bytes
//   0x1320e0: 5296A108  mov      w8, #0xb508
//   0x1320e4: 72A00028  movk     w8, #1, lsl #16
//   0x1320e8: F8286801  str      x1, [x0, x8]
//   0x1320ec: D65F03C0  ret      
static inline uint64_t fde_func_2908_0x1320e0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1320e0ULL ^ (static_cast<uint64_t>(0x5296a108ULL) << 13);
    acc = (acc + a1 + 0x72a00028ULL) ^ 0x1e9828ULL;
    acc ^= (acc >> 17) * 0x0010ULL;
    return acc;
}

// FDE #2909 | PC: 0x1320f0 | FDE: 0x1e9840 | Size: 100 bytes [BD_Py_CheckStuckCallback]
// Khung tháo gỡ #2909 | Địa chỉ PC: 0x1320f0 | Địa chỉ FDE: 0x1e9840 | Kích thước: 100 bytes
//   0x1320f0: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x1320f4: 910003FD  mov      x29, sp
//   0x1320f8: B0000668  adrp     x8, #0x1ff000
//   0x1320fc: F943B908  ldr      x8, [x8, #0x770]
static inline uint64_t fde_func_2909_0x1320f0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1320f0ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1e9840ULL;
    acc ^= (acc >> 17) * 0x0064ULL;
    return acc;
}

// FDE #2910 | PC: 0x132154 | FDE: 0x1e9860 | Size: 40 bytes [_Py_GetConfig]
// Khung tháo gỡ #2910 | Địa chỉ PC: 0x132154 | Địa chỉ FDE: 0x1e9860 | Kích thước: 40 bytes
//   0x132154: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x132158: 910003FD  mov      x29, sp
//   0x13215c: B0000668  adrp     x8, #0x1ff000
//   0x132160: F943B908  ldr      x8, [x8, #0x770]
static inline uint64_t fde_func_2910_0x132154(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x132154ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1e9860ULL;
    acc ^= (acc >> 17) * 0x0028ULL;
    return acc;
}

// FDE #2911 | PC: 0x13217c | FDE: 0x1e9880 | Size: 96 bytes [PyPitayaPackage_InitLock]
// Khung tháo gỡ #2911 | Địa chỉ PC: 0x13217c | Địa chỉ FDE: 0x1e9880 | Kích thước: 96 bytes
//   0x13217c: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x132180: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x132184: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x132188: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_2911_0x13217c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x13217cULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1e9880ULL;
    acc ^= (acc >> 17) * 0x0060ULL;
    return acc;
}

// FDE #2912 | PC: 0x1321dc | FDE: 0x1e98a0 | Size: 64 bytes [BDPythonVM_PyThreadStateSetPitayaPackage]
// Khung tháo gỡ #2912 | Địa chỉ PC: 0x1321dc | Địa chỉ FDE: 0x1e98a0 | Kích thước: 64 bytes
//   0x1321dc: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x1321e0: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x1321e4: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x1321e8: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_2912_0x1321dc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1321dcULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1e98a0ULL;
    acc ^= (acc >> 17) * 0x0040ULL;
    return acc;
}

// FDE #2913 | PC: 0x13221c | FDE: 0x1e98c0 | Size: 88 bytes [_bd_simple_profile_get_info_map]
// Khung tháo gỡ #2913 | Địa chỉ PC: 0x13221c | Địa chỉ FDE: 0x1e98c0 | Kích thước: 88 bytes
//   0x13221c: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x132220: 910003FD  mov      x29, sp
//   0x132224: B0000668  adrp     x8, #0x1ff000
//   0x132228: F943B908  ldr      x8, [x8, #0x770]
static inline uint64_t fde_func_2913_0x13221c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x13221cULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1e98c0ULL;
    acc ^= (acc >> 17) * 0x0058ULL;
    return acc;
}

// FDE #2914 | PC: 0x132274 | FDE: 0x1e98e0 | Size: 100 bytes [_bd_simple_profile_set_info_map]
// Khung tháo gỡ #2914 | Địa chỉ PC: 0x132274 | Địa chỉ FDE: 0x1e98e0 | Kích thước: 100 bytes
//   0x132274: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x132278: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x13227c: 910043FD  add      x29, sp, #0x10
//   0x132280: B0000668  adrp     x8, #0x1ff000
static inline uint64_t fde_func_2914_0x132274(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x132274ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1e98e0ULL;
    acc ^= (acc >> 17) * 0x0064ULL;
    return acc;
}

// FDE #2915 | PC: 0x1322d8 | FDE: 0x1e9900 | Size: 24 bytes
// Khung tháo gỡ #2915 | Địa chỉ PC: 0x1322d8 | Địa chỉ FDE: 0x1e9900 | Kích thước: 24 bytes
//   0x1322d8: 90000008  adrp     x8, #0x132000
//   0x1322dc: 9111B108  add      x8, x8, #0x46c
//   0x1322e0: 2A1F03E0  mov      w0, wzr
//   0x1322e4: F900003F  str      xzr, [x1]
static inline uint64_t fde_func_2915_0x1322d8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1322d8ULL ^ (static_cast<uint64_t>(0x90000008ULL) << 13);
    acc = (acc + a1 + 0x9111b108ULL) ^ 0x1e9900ULL;
    acc ^= (acc >> 17) * 0x0018ULL;
    return acc;
}

// FDE #2916 | PC: 0x1322f0 | FDE: 0x1e9918 | Size: 116 bytes
// Khung tháo gỡ #2916 | Địa chỉ PC: 0x1322f0 | Địa chỉ FDE: 0x1e9918 | Kích thước: 116 bytes
//   0x1322f0: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x1322f4: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x1322f8: 910043FD  add      x29, sp, #0x10
//   0x1322fc: AA0103F3  mov      x19, x1
static inline uint64_t fde_func_2916_0x1322f0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1322f0ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1e9918ULL;
    acc ^= (acc >> 17) * 0x0074ULL;
    return acc;
}

// FDE #2917 | PC: 0x132364 | FDE: 0x1e9938 | Size: 124 bytes
// Khung tháo gỡ #2917 | Địa chỉ PC: 0x132364 | Địa chỉ FDE: 0x1e9938 | Kích thước: 124 bytes
//   0x132364: F81D0FF5  str      x21, [sp, #-0x30]!
//   0x132368: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x13236c: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x132370: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_2917_0x132364(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x132364ULL ^ (static_cast<uint64_t>(0xf81d0ff5ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1e9938ULL;
    acc ^= (acc >> 17) * 0x007cULL;
    return acc;
}

// FDE #2918 | PC: 0x1323e0 | FDE: 0x1e9958 | Size: 140 bytes
// Khung tháo gỡ #2918 | Địa chỉ PC: 0x1323e0 | Địa chỉ FDE: 0x1e9958 | Kích thước: 140 bytes
//   0x1323e0: A9BE4FF4  stp      x20, x19, [sp, #-0x20]!
//   0x1323e4: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x1323e8: 910043FD  add      x29, sp, #0x10
//   0x1323ec: AA0003F4  mov      x20, x0
static inline uint64_t fde_func_2918_0x1323e0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1323e0ULL ^ (static_cast<uint64_t>(0xa9be4ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x1e9958ULL;
    acc ^= (acc >> 17) * 0x008cULL;
    return acc;
}

// FDE #2919 | PC: 0x13246c | FDE: 0x1e9978 | Size: 24 bytes
// Khung tháo gỡ #2919 | Địa chỉ PC: 0x13246c | Địa chỉ FDE: 0x1e9978 | Kích thước: 24 bytes
//   0x13246c: B0000660  adrp     x0, #0x1ff000
//   0x132470: F945F000  ldr      x0, [x0, #0xbe0]
//   0x132474: F9400008  ldr      x8, [x0]
//   0x132478: 91000508  add      x8, x8, #1
static inline uint64_t fde_func_2919_0x13246c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x13246cULL ^ (static_cast<uint64_t>(0xb0000660ULL) << 13);
    acc = (acc + a1 + 0xf945f000ULL) ^ 0x1e9978ULL;
    acc ^= (acc >> 17) * 0x0018ULL;
    return acc;
}

// FDE #2920 | PC: 0x132484 | FDE: 0x1e9990 | Size: 8 bytes
// Khung tháo gỡ #2920 | Địa chỉ PC: 0x132484 | Địa chỉ FDE: 0x1e9990 | Kích thước: 8 bytes
//   0x132484: F9400000  ldr      x0, [x0]
//   0x132488: 17FCA07E  b        #0x5a680
static inline uint64_t fde_func_2920_0x132484(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x132484ULL ^ (static_cast<uint64_t>(0xf9400000ULL) << 13);
    acc = (acc + a1 + 0x17fca07eULL) ^ 0x1e9990ULL;
    acc ^= (acc >> 17) * 0x0008ULL;
    return acc;
}

// FDE #2921 | PC: 0x13248c | FDE: 0x1e99a8 | Size: 12 bytes
// Khung tháo gỡ #2921 | Địa chỉ PC: 0x13248c | Địa chỉ FDE: 0x1e99a8 | Kích thước: 12 bytes
//   0x13248c: F9400008  ldr      x8, [x0]
//   0x132490: A9400500  ldp      x0, x1, [x8]
//   0x132494: 17FC9B23  b        #0x59120
static inline uint64_t fde_func_2921_0x13248c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x13248cULL ^ (static_cast<uint64_t>(0xf9400008ULL) << 13);
    acc = (acc + a1 + 0xa9400500ULL) ^ 0x1e99a8ULL;
    acc ^= (acc >> 17) * 0x000cULL;
    return acc;
}

// FDE #2922 | PC: 0x132498 | FDE: 0x1e99c0 | Size: 16 bytes
// Khung tháo gỡ #2922 | Địa chỉ PC: 0x132498 | Địa chỉ FDE: 0x1e99c0 | Kích thước: 16 bytes
//   0x132498: F9400008  ldr      x8, [x0]
//   0x13249c: B9400100  ldr      w0, [x8]
//   0x1324a0: A9408901  ldp      x1, x2, [x8, #8]
//   0x1324a4: 17FCA64B  b        #0x5bdd0
static inline uint64_t fde_func_2922_0x132498(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x132498ULL ^ (static_cast<uint64_t>(0xf9400008ULL) << 13);
    acc = (acc + a1 + 0xb9400100ULL) ^ 0x1e99c0ULL;
    acc ^= (acc >> 17) * 0x0010ULL;
    return acc;
}

// FDE #2923 | PC: 0x1324a8 | FDE: 0x1e99d8 | Size: 184 bytes [_PyRun_AnyFileObject]
// Khung tháo gỡ #2923 | Địa chỉ PC: 0x1324a8 | Địa chỉ FDE: 0x1e99d8 | Kích thước: 184 bytes
//   0x1324a8: A9BC5FF8  stp      x24, x23, [sp, #-0x40]!
//   0x1324ac: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x1324b0: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x1324b4: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_2923_0x1324a8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x1324a8ULL ^ (static_cast<uint64_t>(0xa9bc5ff8ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x1e99d8ULL;
    acc ^= (acc >> 17) * 0x00b8ULL;
    return acc;
}

// FDE #2924 | PC: 0x132560 | FDE: 0x1e9a00 | Size: 24 bytes [PyErr_Print]
// Khung tháo gỡ #2924 | Địa chỉ PC: 0x132560 | Địa chỉ FDE: 0x1e9a00 | Kích thước: 24 bytes
//   0x132560: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x132564: 910003FD  mov      x29, sp
//   0x132568: 97FC9C96  bl       #0x597c0
//   0x13256c: 52800021  mov      w1, #1
static inline uint64_t fde_func_2924_0x132560(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x132560ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x1e9a00ULL;
    acc ^= (acc >> 17) * 0x0018ULL;
    return acc;
}

// FDE #2925 | PC: 0x132578 | FDE: 0x1e9a20 | Size: 256 bytes [_PyRun_SimpleFileObject]
// Khung tháo gỡ #2925 | Địa chỉ PC: 0x132578 | Địa chỉ FDE: 0x1e9a20 | Kích thước: 256 bytes
//   0x132578: D10243FF  sub      sp, sp, #0x90
//   0x13257c: A9036FFC  stp      x28, x27, [sp, #0x30]
//   0x132580: A90467FA  stp      x26, x25, [sp, #0x40]
//   0x132584: A9055FF8  stp      x24, x23, [sp, #0x50]
static inline uint64_t fde_func_2925_0x132578(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x132578ULL ^ (static_cast<uint64_t>(0xd10243ffULL) << 13);
    acc = (acc + a1 + 0xa9036ffcULL) ^ 0x1e9a20ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #2926 | PC: 0x132b28 | FDE: 0x1e9a50 | Size: 164 bytes [PyRun_AnyFileExFlags]
// Khung tháo gỡ #2926 | Địa chỉ PC: 0x132b28 | Địa chỉ FDE: 0x1e9a50 | Kích thước: 164 bytes
//   0x132b28: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x132b2c: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x132b30: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x132b34: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_2926_0x132b28(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x132b28ULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1e9a50ULL;
    acc ^= (acc >> 17) * 0x00a4ULL;
    return acc;
}

// FDE #2927 | PC: 0x132bcc | FDE: 0x1e9a78 | Size: 256 bytes
// Khung tháo gỡ #2927 | Địa chỉ PC: 0x132bcc | Địa chỉ FDE: 0x1e9a78 | Kích thước: 256 bytes
//   0x132bcc: A9BD57F6  stp      x22, x21, [sp, #-0x30]!
//   0x132bd0: A9014FF4  stp      x20, x19, [sp, #0x10]
//   0x132bd4: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x132bd8: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_2927_0x132bcc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x132bccULL ^ (static_cast<uint64_t>(0xa9bd57f6ULL) << 13);
    acc = (acc + a1 + 0xa9014ff4ULL) ^ 0x1e9a78ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Shard 2 Dispatcher / Bộ điều phối phân mảnh 2
uint64_t execute_fde_shard_2(uint32_t fde_idx, uint64_t a0, uint64_t a1) {
    switch (fde_idx) {
        case 2464: return fde_func_2464_0x10c2e4(a0, a1);
        case 2465: return fde_func_2465_0x10c374(a0, a1);
        case 2466: return fde_func_2466_0x10c518(a0, a1);
        case 2467: return fde_func_2467_0x10c544(a0, a1);
        case 2468: return fde_func_2468_0x10c5b4(a0, a1);
        case 2469: return fde_func_2469_0x10c5bc(a0, a1);
        case 2470: return fde_func_2470_0x10c5e4(a0, a1);
        case 2471: return fde_func_2471_0x10c650(a0, a1);
        case 2472: return fde_func_2472_0x10c6c4(a0, a1);
        case 2473: return fde_func_2473_0x10c6dc(a0, a1);
        case 2474: return fde_func_2474_0x10c7b0(a0, a1);
        case 2475: return fde_func_2475_0x10c7b8(a0, a1);
        case 2476: return fde_func_2476_0x10c7e0(a0, a1);
        case 2477: return fde_func_2477_0x10ca44(a0, a1);
        case 2478: return fde_func_2478_0x10ca68(a0, a1);
        case 2479: return fde_func_2479_0x10caa4(a0, a1);
        case 2480: return fde_func_2480_0x10caf4(a0, a1);
        case 2481: return fde_func_2481_0x10cb88(a0, a1);
        case 2482: return fde_func_2482_0x10cc04(a0, a1);
        case 2483: return fde_func_2483_0x10ccac(a0, a1);
        case 2484: return fde_func_2484_0x10cd64(a0, a1);
        case 2485: return fde_func_2485_0x10cecc(a0, a1);
        case 2486: return fde_func_2486_0x10d008(a0, a1);
        case 2487: return fde_func_2487_0x10d0a0(a0, a1);
        case 2488: return fde_func_2488_0x10d1e0(a0, a1);
        case 2489: return fde_func_2489_0x10d29c(a0, a1);
        case 2490: return fde_func_2490_0x10d310(a0, a1);
        case 2491: return fde_func_2491_0x10d354(a0, a1);
        case 2492: return fde_func_2492_0x10d39c(a0, a1);
        case 2493: return fde_func_2493_0x10d3b8(a0, a1);
        case 2494: return fde_func_2494_0x10d51c(a0, a1);
        case 2495: return fde_func_2495_0x10d588(a0, a1);
        case 2496: return fde_func_2496_0x10d5a8(a0, a1);
        case 2497: return fde_func_2497_0x10d744(a0, a1);
        case 2498: return fde_func_2498_0x10d778(a0, a1);
        case 2499: return fde_func_2499_0x10d7d8(a0, a1);
        case 2500: return fde_func_2500_0x10d854(a0, a1);
        case 2501: return fde_func_2501_0x10d8a8(a0, a1);
        case 2502: return fde_func_2502_0x10d9b4(a0, a1);
        case 2503: return fde_func_2503_0x10da70(a0, a1);
        case 2504: return fde_func_2504_0x10dc4c(a0, a1);
        case 2505: return fde_func_2505_0x10dd38(a0, a1);
        case 2506: return fde_func_2506_0x10ddac(a0, a1);
        case 2507: return fde_func_2507_0x10de6c(a0, a1);
        case 2508: return fde_func_2508_0x10e3e0(a0, a1);
        case 2509: return fde_func_2509_0x10e980(a0, a1);
        case 2510: return fde_func_2510_0x10e98c(a0, a1);
        case 2511: return fde_func_2511_0x10e994(a0, a1);
        case 2512: return fde_func_2512_0x10eaa8(a0, a1);
        case 2513: return fde_func_2513_0x10eab4(a0, a1);
        case 2514: return fde_func_2514_0x10f360(a0, a1);
        case 2515: return fde_func_2515_0x10f364(a0, a1);
        case 2516: return fde_func_2516_0x10f3c4(a0, a1);
        case 2517: return fde_func_2517_0x10f514(a0, a1);
        case 2518: return fde_func_2518_0x10f574(a0, a1);
        case 2519: return fde_func_2519_0x10f94c(a0, a1);
        case 2520: return fde_func_2520_0x10f9e8(a0, a1);
        case 2521: return fde_func_2521_0x10fa84(a0, a1);
        case 2522: return fde_func_2522_0x10fb48(a0, a1);
        case 2523: return fde_func_2523_0x10fc0c(a0, a1);
        case 2524: return fde_func_2524_0x10fcac(a0, a1);
        case 2525: return fde_func_2525_0x110290(a0, a1);
        case 2526: return fde_func_2526_0x110330(a0, a1);
        case 2527: return fde_func_2527_0x1103bc(a0, a1);
        case 2528: return fde_func_2528_0x110448(a0, a1);
        case 2529: return fde_func_2529_0x110498(a0, a1);
        case 2530: return fde_func_2530_0x110560(a0, a1);
        case 2531: return fde_func_2531_0x111170(a0, a1);
        case 2532: return fde_func_2532_0x111238(a0, a1);
        case 2533: return fde_func_2533_0x1112cc(a0, a1);
        case 2534: return fde_func_2534_0x111360(a0, a1);
        case 2535: return fde_func_2535_0x11143c(a0, a1);
        case 2536: return fde_func_2536_0x111518(a0, a1);
        case 2537: return fde_func_2537_0x1115b0(a0, a1);
        case 2538: return fde_func_2538_0x111e80(a0, a1);
        case 2539: return fde_func_2539_0x111f18(a0, a1);
        case 2540: return fde_func_2540_0x111fb8(a0, a1);
        case 2541: return fde_func_2541_0x112058(a0, a1);
        case 2542: return fde_func_2542_0x1120b8(a0, a1);
        case 2543: return fde_func_2543_0x112798(a0, a1);
        case 2544: return fde_func_2544_0x112b1c(a0, a1);
        case 2545: return fde_func_2545_0x112c1c(a0, a1);
        case 2546: return fde_func_2546_0x112d48(a0, a1);
        case 2547: return fde_func_2547_0x112e48(a0, a1);
        case 2548: return fde_func_2548_0x112eb8(a0, a1);
        case 2549: return fde_func_2549_0x112f28(a0, a1);
        case 2550: return fde_func_2550_0x112f70(a0, a1);
        case 2551: return fde_func_2551_0x112f74(a0, a1);
        case 2552: return fde_func_2552_0x114c34(a0, a1);
        case 2553: return fde_func_2553_0x114dd4(a0, a1);
        case 2554: return fde_func_2554_0x114df4(a0, a1);
        case 2555: return fde_func_2555_0x114e14(a0, a1);
        case 2556: return fde_func_2556_0x1150ac(a0, a1);
        case 2557: return fde_func_2557_0x1150b8(a0, a1);
        case 2558: return fde_func_2558_0x1150c4(a0, a1);
        case 2559: return fde_func_2559_0x1150d0(a0, a1);
        case 2560: return fde_func_2560_0x115124(a0, a1);
        case 2561: return fde_func_2561_0x115128(a0, a1);
        case 2562: return fde_func_2562_0x115134(a0, a1);
        case 2563: return fde_func_2563_0x115148(a0, a1);
        case 2564: return fde_func_2564_0x1151c4(a0, a1);
        case 2565: return fde_func_2565_0x1152b8(a0, a1);
        case 2566: return fde_func_2566_0x1153c8(a0, a1);
        case 2567: return fde_func_2567_0x115498(a0, a1);
        case 2568: return fde_func_2568_0x1154b8(a0, a1);
        case 2569: return fde_func_2569_0x11553c(a0, a1);
        case 2570: return fde_func_2570_0x115630(a0, a1);
        case 2571: return fde_func_2571_0x115680(a0, a1);
        case 2572: return fde_func_2572_0x115750(a0, a1);
        case 2573: return fde_func_2573_0x1157f4(a0, a1);
        case 2574: return fde_func_2574_0x115898(a0, a1);
        case 2575: return fde_func_2575_0x1158b4(a0, a1);
        case 2576: return fde_func_2576_0x115a8c(a0, a1);
        case 2577: return fde_func_2577_0x115b10(a0, a1);
        case 2578: return fde_func_2578_0x115bb4(a0, a1);
        case 2579: return fde_func_2579_0x115c28(a0, a1);
        case 2580: return fde_func_2580_0x115ce0(a0, a1);
        case 2581: return fde_func_2581_0x115d44(a0, a1);
        case 2582: return fde_func_2582_0x115dc0(a0, a1);
        case 2583: return fde_func_2583_0x115e00(a0, a1);
        case 2584: return fde_func_2584_0x115e10(a0, a1);
        case 2585: return fde_func_2585_0x115e30(a0, a1);
        case 2586: return fde_func_2586_0x115f64(a0, a1);
        case 2587: return fde_func_2587_0x115fa8(a0, a1);
        case 2588: return fde_func_2588_0x115fec(a0, a1);
        case 2589: return fde_func_2589_0x117090(a0, a1);
        case 2590: return fde_func_2590_0x1170a0(a0, a1);
        case 2591: return fde_func_2591_0x117240(a0, a1);
        case 2592: return fde_func_2592_0x1172b4(a0, a1);
        case 2593: return fde_func_2593_0x117344(a0, a1);
        case 2594: return fde_func_2594_0x11748c(a0, a1);
        case 2595: return fde_func_2595_0x1174dc(a0, a1);
        case 2596: return fde_func_2596_0x11753c(a0, a1);
        case 2597: return fde_func_2597_0x1176f4(a0, a1);
        case 2598: return fde_func_2598_0x1176fc(a0, a1);
        case 2599: return fde_func_2599_0x117830(a0, a1);
        case 2600: return fde_func_2600_0x1178f0(a0, a1);
        case 2601: return fde_func_2601_0x117980(a0, a1);
        case 2602: return fde_func_2602_0x117b7c(a0, a1);
        case 2603: return fde_func_2603_0x117dac(a0, a1);
        case 2604: return fde_func_2604_0x117dfc(a0, a1);
        case 2605: return fde_func_2605_0x117e58(a0, a1);
        case 2606: return fde_func_2606_0x117edc(a0, a1);
        case 2607: return fde_func_2607_0x117fb8(a0, a1);
        case 2608: return fde_func_2608_0x118164(a0, a1);
        case 2609: return fde_func_2609_0x118aa8(a0, a1);
        case 2610: return fde_func_2610_0x118b18(a0, a1);
        case 2611: return fde_func_2611_0x118c58(a0, a1);
        case 2612: return fde_func_2612_0x118eb4(a0, a1);
        case 2613: return fde_func_2613_0x118ec0(a0, a1);
        case 2614: return fde_func_2614_0x119010(a0, a1);
        case 2615: return fde_func_2615_0x119150(a0, a1);
        case 2616: return fde_func_2616_0x119284(a0, a1);
        case 2617: return fde_func_2617_0x1192d4(a0, a1);
        case 2618: return fde_func_2618_0x119424(a0, a1);
        case 2619: return fde_func_2619_0x119504(a0, a1);
        case 2620: return fde_func_2620_0x1195e8(a0, a1);
        case 2621: return fde_func_2621_0x119608(a0, a1);
        case 2622: return fde_func_2622_0x119630(a0, a1);
        case 2623: return fde_func_2623_0x1196c4(a0, a1);
        case 2624: return fde_func_2624_0x1197bc(a0, a1);
        case 2625: return fde_func_2625_0x1198ac(a0, a1);
        case 2626: return fde_func_2626_0x119940(a0, a1);
        case 2627: return fde_func_2627_0x1199f0(a0, a1);
        case 2628: return fde_func_2628_0x119adc(a0, a1);
        case 2629: return fde_func_2629_0x119b94(a0, a1);
        case 2630: return fde_func_2630_0x119d64(a0, a1);
        case 2631: return fde_func_2631_0x119e00(a0, a1);
        case 2632: return fde_func_2632_0x119e9c(a0, a1);
        case 2633: return fde_func_2633_0x119fe4(a0, a1);
        case 2634: return fde_func_2634_0x11a140(a0, a1);
        case 2635: return fde_func_2635_0x11a2ac(a0, a1);
        case 2636: return fde_func_2636_0x11a364(a0, a1);
        case 2637: return fde_func_2637_0x11a3d4(a0, a1);
        case 2638: return fde_func_2638_0x11a968(a0, a1);
        case 2639: return fde_func_2639_0x11abf4(a0, a1);
        case 2640: return fde_func_2640_0x11ac00(a0, a1);
        case 2641: return fde_func_2641_0x11ac14(a0, a1);
        case 2642: return fde_func_2642_0x11ac38(a0, a1);
        case 2643: return fde_func_2643_0x11ac50(a0, a1);
        case 2644: return fde_func_2644_0x11ac60(a0, a1);
        case 2645: return fde_func_2645_0x11ac70(a0, a1);
        case 2646: return fde_func_2646_0x11ac80(a0, a1);
        case 2647: return fde_func_2647_0x11acf8(a0, a1);
        case 2648: return fde_func_2648_0x11ad4c(a0, a1);
        case 2649: return fde_func_2649_0x11ae70(a0, a1);
        case 2650: return fde_func_2650_0x11af74(a0, a1);
        case 2651: return fde_func_2651_0x11af80(a0, a1);
        case 2652: return fde_func_2652_0x11aff4(a0, a1);
        case 2653: return fde_func_2653_0x11b088(a0, a1);
        case 2654: return fde_func_2654_0x11b160(a0, a1);
        case 2655: return fde_func_2655_0x11b1e0(a0, a1);
        case 2656: return fde_func_2656_0x11b284(a0, a1);
        case 2657: return fde_func_2657_0x11b2a0(a0, a1);
        case 2658: return fde_func_2658_0x11b4d8(a0, a1);
        case 2659: return fde_func_2659_0x11b574(a0, a1);
        case 2660: return fde_func_2660_0x11b620(a0, a1);
        case 2661: return fde_func_2661_0x11b6b4(a0, a1);
        case 2662: return fde_func_2662_0x11b780(a0, a1);
        case 2663: return fde_func_2663_0x11b864(a0, a1);
        case 2664: return fde_func_2664_0x11be8c(a0, a1);
        case 2665: return fde_func_2665_0x11d190(a0, a1);
        case 2666: return fde_func_2666_0x11def4(a0, a1);
        case 2667: return fde_func_2667_0x11dfbc(a0, a1);
        case 2668: return fde_func_2668_0x11e118(a0, a1);
        case 2669: return fde_func_2669_0x11e2ec(a0, a1);
        case 2670: return fde_func_2670_0x11e5ec(a0, a1);
        case 2671: return fde_func_2671_0x11e670(a0, a1);
        case 2672: return fde_func_2672_0x11e704(a0, a1);
        case 2673: return fde_func_2673_0x11e794(a0, a1);
        case 2674: return fde_func_2674_0x11e864(a0, a1);
        case 2675: return fde_func_2675_0x120828(a0, a1);
        case 2676: return fde_func_2676_0x120830(a0, a1);
        case 2677: return fde_func_2677_0x121000(a0, a1);
        case 2678: return fde_func_2678_0x1213e0(a0, a1);
        case 2679: return fde_func_2679_0x1214bc(a0, a1);
        case 2680: return fde_func_2680_0x121574(a0, a1);
        case 2681: return fde_func_2681_0x1215fc(a0, a1);
        case 2682: return fde_func_2682_0x12197c(a0, a1);
        case 2683: return fde_func_2683_0x121a94(a0, a1);
        case 2684: return fde_func_2684_0x123f48(a0, a1);
        case 2685: return fde_func_2685_0x123fc8(a0, a1);
        case 2686: return fde_func_2686_0x124050(a0, a1);
        case 2687: return fde_func_2687_0x1241a4(a0, a1);
        case 2688: return fde_func_2688_0x124244(a0, a1);
        case 2689: return fde_func_2689_0x1242e4(a0, a1);
        case 2690: return fde_func_2690_0x1243b0(a0, a1);
        case 2691: return fde_func_2691_0x124570(a0, a1);
        case 2692: return fde_func_2692_0x12457c(a0, a1);
        case 2693: return fde_func_2693_0x124598(a0, a1);
        case 2694: return fde_func_2694_0x124afc(a0, a1);
        case 2695: return fde_func_2695_0x124c4c(a0, a1);
        case 2696: return fde_func_2696_0x124e44(a0, a1);
        case 2697: return fde_func_2697_0x1263e4(a0, a1);
        case 2698: return fde_func_2698_0x1264dc(a0, a1);
        case 2699: return fde_func_2699_0x1265fc(a0, a1);
        case 2700: return fde_func_2700_0x126714(a0, a1);
        case 2701: return fde_func_2701_0x1267b4(a0, a1);
        case 2702: return fde_func_2702_0x1268d0(a0, a1);
        case 2703: return fde_func_2703_0x1268f4(a0, a1);
        case 2704: return fde_func_2704_0x126988(a0, a1);
        case 2705: return fde_func_2705_0x126a78(a0, a1);
        case 2706: return fde_func_2706_0x126b6c(a0, a1);
        case 2707: return fde_func_2707_0x126c18(a0, a1);
        case 2708: return fde_func_2708_0x126cc8(a0, a1);
        case 2709: return fde_func_2709_0x126d20(a0, a1);
        case 2710: return fde_func_2710_0x126ebc(a0, a1);
        case 2711: return fde_func_2711_0x126f14(a0, a1);
        case 2712: return fde_func_2712_0x126ff0(a0, a1);
        case 2713: return fde_func_2713_0x127034(a0, a1);
        case 2714: return fde_func_2714_0x1270a4(a0, a1);
        case 2715: return fde_func_2715_0x127114(a0, a1);
        case 2716: return fde_func_2716_0x127164(a0, a1);
        case 2717: return fde_func_2717_0x12721c(a0, a1);
        case 2718: return fde_func_2718_0x127ba4(a0, a1);
        case 2719: return fde_func_2719_0x127ce0(a0, a1);
        case 2720: return fde_func_2720_0x127e30(a0, a1);
        case 2721: return fde_func_2721_0x127f00(a0, a1);
        case 2722: return fde_func_2722_0x127f88(a0, a1);
        case 2723: return fde_func_2723_0x128248(a0, a1);
        case 2724: return fde_func_2724_0x1282e0(a0, a1);
        case 2725: return fde_func_2725_0x1283a0(a0, a1);
        case 2726: return fde_func_2726_0x128650(a0, a1);
        case 2727: return fde_func_2727_0x128660(a0, a1);
        case 2728: return fde_func_2728_0x1288fc(a0, a1);
        case 2729: return fde_func_2729_0x128da0(a0, a1);
        case 2730: return fde_func_2730_0x128edc(a0, a1);
        case 2731: return fde_func_2731_0x128ef0(a0, a1);
        case 2732: return fde_func_2732_0x128f88(a0, a1);
        case 2733: return fde_func_2733_0x129028(a0, a1);
        case 2734: return fde_func_2734_0x1290c8(a0, a1);
        case 2735: return fde_func_2735_0x1290d8(a0, a1);
        case 2736: return fde_func_2736_0x1290e8(a0, a1);
        case 2737: return fde_func_2737_0x1290f8(a0, a1);
        case 2738: return fde_func_2738_0x129108(a0, a1);
        case 2739: return fde_func_2739_0x129118(a0, a1);
        case 2740: return fde_func_2740_0x129128(a0, a1);
        case 2741: return fde_func_2741_0x129318(a0, a1);
        case 2742: return fde_func_2742_0x1294dc(a0, a1);
        case 2743: return fde_func_2743_0x129544(a0, a1);
        case 2744: return fde_func_2744_0x129600(a0, a1);
        case 2745: return fde_func_2745_0x129760(a0, a1);
        case 2746: return fde_func_2746_0x129784(a0, a1);
        case 2747: return fde_func_2747_0x129794(a0, a1);
        case 2748: return fde_func_2748_0x129830(a0, a1);
        case 2749: return fde_func_2749_0x129af8(a0, a1);
        case 2750: return fde_func_2750_0x129ba4(a0, a1);
        case 2751: return fde_func_2751_0x129bd8(a0, a1);
        case 2752: return fde_func_2752_0x129bf8(a0, a1);
        case 2753: return fde_func_2753_0x129c18(a0, a1);
        case 2754: return fde_func_2754_0x129c3c(a0, a1);
        case 2755: return fde_func_2755_0x129c94(a0, a1);
        case 2756: return fde_func_2756_0x129d48(a0, a1);
        case 2757: return fde_func_2757_0x129d8c(a0, a1);
        case 2758: return fde_func_2758_0x12a094(a0, a1);
        case 2759: return fde_func_2759_0x12a114(a0, a1);
        case 2760: return fde_func_2760_0x12a1c0(a0, a1);
        case 2761: return fde_func_2761_0x12a870(a0, a1);
        case 2762: return fde_func_2762_0x12a9b4(a0, a1);
        case 2763: return fde_func_2763_0x12aa50(a0, a1);
        case 2764: return fde_func_2764_0x12aaa0(a0, a1);
        case 2765: return fde_func_2765_0x12ab4c(a0, a1);
        case 2766: return fde_func_2766_0x12ab94(a0, a1);
        case 2767: return fde_func_2767_0x12ab9c(a0, a1);
        case 2768: return fde_func_2768_0x12acfc(a0, a1);
        case 2769: return fde_func_2769_0x12ad10(a0, a1);
        case 2770: return fde_func_2770_0x12ad18(a0, a1);
        case 2771: return fde_func_2771_0x12ad4c(a0, a1);
        case 2772: return fde_func_2772_0x12ad50(a0, a1);
        case 2773: return fde_func_2773_0x12ad5c(a0, a1);
        case 2774: return fde_func_2774_0x12afe0(a0, a1);
        case 2775: return fde_func_2775_0x12b090(a0, a1);
        case 2776: return fde_func_2776_0x12b0a0(a0, a1);
        case 2777: return fde_func_2777_0x12b0d0(a0, a1);
        case 2778: return fde_func_2778_0x12b0f4(a0, a1);
        case 2779: return fde_func_2779_0x12b10c(a0, a1);
        case 2780: return fde_func_2780_0x12b11c(a0, a1);
        case 2781: return fde_func_2781_0x12b12c(a0, a1);
        case 2782: return fde_func_2782_0x12b188(a0, a1);
        case 2783: return fde_func_2783_0x12b1e8(a0, a1);
        case 2784: return fde_func_2784_0x12b1f0(a0, a1);
        case 2785: return fde_func_2785_0x12b2e8(a0, a1);
        case 2786: return fde_func_2786_0x12b3f0(a0, a1);
        case 2787: return fde_func_2787_0x12b4cc(a0, a1);
        case 2788: return fde_func_2788_0x12b678(a0, a1);
        case 2789: return fde_func_2789_0x12b6d0(a0, a1);
        case 2790: return fde_func_2790_0x12b724(a0, a1);
        case 2791: return fde_func_2791_0x12b72c(a0, a1);
        case 2792: return fde_func_2792_0x12b840(a0, a1);
        case 2793: return fde_func_2793_0x12bd38(a0, a1);
        case 2794: return fde_func_2794_0x12be5c(a0, a1);
        case 2795: return fde_func_2795_0x12beb0(a0, a1);
        case 2796: return fde_func_2796_0x12beb8(a0, a1);
        case 2797: return fde_func_2797_0x12bff8(a0, a1);
        case 2798: return fde_func_2798_0x12c250(a0, a1);
        case 2799: return fde_func_2799_0x12c41c(a0, a1);
        case 2800: return fde_func_2800_0x12cb78(a0, a1);
        case 2801: return fde_func_2801_0x12cc30(a0, a1);
        case 2802: return fde_func_2802_0x12cccc(a0, a1);
        case 2803: return fde_func_2803_0x12ccd0(a0, a1);
        case 2804: return fde_func_2804_0x12ced8(a0, a1);
        case 2805: return fde_func_2805_0x12cee0(a0, a1);
        case 2806: return fde_func_2806_0x12d064(a0, a1);
        case 2807: return fde_func_2807_0x12d09c(a0, a1);
        case 2808: return fde_func_2808_0x12d334(a0, a1);
        case 2809: return fde_func_2809_0x12d368(a0, a1);
        case 2810: return fde_func_2810_0x12d844(a0, a1);
        case 2811: return fde_func_2811_0x12d984(a0, a1);
        case 2812: return fde_func_2812_0x12d998(a0, a1);
        case 2813: return fde_func_2813_0x12d9cc(a0, a1);
        case 2814: return fde_func_2814_0x12da04(a0, a1);
        case 2815: return fde_func_2815_0x12da14(a0, a1);
        case 2816: return fde_func_2816_0x12da8c(a0, a1);
        case 2817: return fde_func_2817_0x12db04(a0, a1);
        case 2818: return fde_func_2818_0x12db5c(a0, a1);
        case 2819: return fde_func_2819_0x12dbd4(a0, a1);
        case 2820: return fde_func_2820_0x12dc1c(a0, a1);
        case 2821: return fde_func_2821_0x12ddb8(a0, a1);
        case 2822: return fde_func_2822_0x12de74(a0, a1);
        case 2823: return fde_func_2823_0x12df30(a0, a1);
        case 2824: return fde_func_2824_0x12dfa0(a0, a1);
        case 2825: return fde_func_2825_0x12e060(a0, a1);
        case 2826: return fde_func_2826_0x12e0ac(a0, a1);
        case 2827: return fde_func_2827_0x12e164(a0, a1);
        case 2828: return fde_func_2828_0x12e1b0(a0, a1);
        case 2829: return fde_func_2829_0x12e610(a0, a1);
        case 2830: return fde_func_2830_0x12e6b4(a0, a1);
        case 2831: return fde_func_2831_0x12ec0c(a0, a1);
        case 2832: return fde_func_2832_0x12f464(a0, a1);
        case 2833: return fde_func_2833_0x12f8a4(a0, a1);
        case 2834: return fde_func_2834_0x12f8d8(a0, a1);
        case 2835: return fde_func_2835_0x12fa44(a0, a1);
        case 2836: return fde_func_2836_0x12fad0(a0, a1);
        case 2837: return fde_func_2837_0x12fbc4(a0, a1);
        case 2838: return fde_func_2838_0x12fc7c(a0, a1);
        case 2839: return fde_func_2839_0x12fdcc(a0, a1);
        case 2840: return fde_func_2840_0x12fe00(a0, a1);
        case 2841: return fde_func_2841_0x130114(a0, a1);
        case 2842: return fde_func_2842_0x130120(a0, a1);
        case 2843: return fde_func_2843_0x130240(a0, a1);
        case 2844: return fde_func_2844_0x130290(a0, a1);
        case 2845: return fde_func_2845_0x130434(a0, a1);
        case 2846: return fde_func_2846_0x130480(a0, a1);
        case 2847: return fde_func_2847_0x1304bc(a0, a1);
        case 2848: return fde_func_2848_0x130558(a0, a1);
        case 2849: return fde_func_2849_0x1305b8(a0, a1);
        case 2850: return fde_func_2850_0x13062c(a0, a1);
        case 2851: return fde_func_2851_0x1306d4(a0, a1);
        case 2852: return fde_func_2852_0x1306dc(a0, a1);
        case 2853: return fde_func_2853_0x1306e4(a0, a1);
        case 2854: return fde_func_2854_0x1306f4(a0, a1);
        case 2855: return fde_func_2855_0x130738(a0, a1);
        case 2856: return fde_func_2856_0x130770(a0, a1);
        case 2857: return fde_func_2857_0x130778(a0, a1);
        case 2858: return fde_func_2858_0x1308ac(a0, a1);
        case 2859: return fde_func_2859_0x1308b4(a0, a1);
        case 2860: return fde_func_2860_0x13091c(a0, a1);
        case 2861: return fde_func_2861_0x130998(a0, a1);
        case 2862: return fde_func_2862_0x130a58(a0, a1);
        case 2863: return fde_func_2863_0x130aec(a0, a1);
        case 2864: return fde_func_2864_0x130bb8(a0, a1);
        case 2865: return fde_func_2865_0x130c8c(a0, a1);
        case 2866: return fde_func_2866_0x130f44(a0, a1);
        case 2867: return fde_func_2867_0x130f4c(a0, a1);
        case 2868: return fde_func_2868_0x130fa4(a0, a1);
        case 2869: return fde_func_2869_0x130ff0(a0, a1);
        case 2870: return fde_func_2870_0x1310b4(a0, a1);
        case 2871: return fde_func_2871_0x13110c(a0, a1);
        case 2872: return fde_func_2872_0x1311ac(a0, a1);
        case 2873: return fde_func_2873_0x1311bc(a0, a1);
        case 2874: return fde_func_2874_0x1311cc(a0, a1);
        case 2875: return fde_func_2875_0x1311fc(a0, a1);
        case 2876: return fde_func_2876_0x13124c(a0, a1);
        case 2877: return fde_func_2877_0x131288(a0, a1);
        case 2878: return fde_func_2878_0x1312d8(a0, a1);
        case 2879: return fde_func_2879_0x1312e0(a0, a1);
        case 2880: return fde_func_2880_0x1312f8(a0, a1);
        case 2881: return fde_func_2881_0x131300(a0, a1);
        case 2882: return fde_func_2882_0x1313b4(a0, a1);
        case 2883: return fde_func_2883_0x1313c4(a0, a1);
        case 2884: return fde_func_2884_0x1313d4(a0, a1);
        case 2885: return fde_func_2885_0x1313dc(a0, a1);
        case 2886: return fde_func_2886_0x1313e4(a0, a1);
        case 2887: return fde_func_2887_0x1314f8(a0, a1);
        case 2888: return fde_func_2888_0x131690(a0, a1);
        case 2889: return fde_func_2889_0x1316f0(a0, a1);
        case 2890: return fde_func_2890_0x131780(a0, a1);
        case 2891: return fde_func_2891_0x131790(a0, a1);
        case 2892: return fde_func_2892_0x1317b8(a0, a1);
        case 2893: return fde_func_2893_0x131874(a0, a1);
        case 2894: return fde_func_2894_0x131894(a0, a1);
        case 2895: return fde_func_2895_0x131900(a0, a1);
        case 2896: return fde_func_2896_0x13198c(a0, a1);
        case 2897: return fde_func_2897_0x131a1c(a0, a1);
        case 2898: return fde_func_2898_0x131ae8(a0, a1);
        case 2899: return fde_func_2899_0x131b3c(a0, a1);
        case 2900: return fde_func_2900_0x131c88(a0, a1);
        case 2901: return fde_func_2901_0x131d7c(a0, a1);
        case 2902: return fde_func_2902_0x131d84(a0, a1);
        case 2903: return fde_func_2903_0x131e50(a0, a1);
        case 2904: return fde_func_2904_0x131f78(a0, a1);
        case 2905: return fde_func_2905_0x132010(a0, a1);
        case 2906: return fde_func_2906_0x132018(a0, a1);
        case 2907: return fde_func_2907_0x132020(a0, a1);
        case 2908: return fde_func_2908_0x1320e0(a0, a1);
        case 2909: return fde_func_2909_0x1320f0(a0, a1);
        case 2910: return fde_func_2910_0x132154(a0, a1);
        case 2911: return fde_func_2911_0x13217c(a0, a1);
        case 2912: return fde_func_2912_0x1321dc(a0, a1);
        case 2913: return fde_func_2913_0x13221c(a0, a1);
        case 2914: return fde_func_2914_0x132274(a0, a1);
        case 2915: return fde_func_2915_0x1322d8(a0, a1);
        case 2916: return fde_func_2916_0x1322f0(a0, a1);
        case 2917: return fde_func_2917_0x132364(a0, a1);
        case 2918: return fde_func_2918_0x1323e0(a0, a1);
        case 2919: return fde_func_2919_0x13246c(a0, a1);
        case 2920: return fde_func_2920_0x132484(a0, a1);
        case 2921: return fde_func_2921_0x13248c(a0, a1);
        case 2922: return fde_func_2922_0x132498(a0, a1);
        case 2923: return fde_func_2923_0x1324a8(a0, a1);
        case 2924: return fde_func_2924_0x132560(a0, a1);
        case 2925: return fde_func_2925_0x132578(a0, a1);
        case 2926: return fde_func_2926_0x132b28(a0, a1);
        case 2927: return fde_func_2927_0x132bcc(a0, a1);
        default: return 0ULL;
    }
}