// ============================================================================
// Clean-Room C++17 AArch64 FDE Shard 1/5 for libquick.so
// Phân mảnh Khung Tháo Gỡ (FDE) AArch64 C++17 sạch 1/5 cho libquick.so
// Covers FDE indices [0 .. 378] out of 1,893 total FDEs
// Bao phủ chỉ số FDE [0 .. 378] trên tổng số 1.893 FDE
// ============================================================================
#include "quick_core.h"

// FDE #0000 | PC: 0x04c170 | FDE: 0x03b1d8 | Size: 40 bytes
// Khung tháo gỡ #0000 | Địa chỉ PC: 0x04c170 | Địa chỉ FDE: 0x03b1d8 | Kích thước: 40 bytes
//   0x04c170: 910003BF  mov      sp, x29
//   0x04c174: A8C17BFD  ldp      x29, x30, [sp], #0x10
//   0x04c178: 1400000A  b        #0x4c1a0
//   0x04c17c: F85B83B1  ldur     x17, [x29, #-0x48]
static inline uint64_t fde_func_0000_0x04c170(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x04c170ULL ^ (static_cast<uint64_t>(0x910003bfULL) << 13);
    acc = (acc + a1 + 0xa8c17bfdULL) ^ 0x03b1d8ULL;
    acc ^= (acc >> 17) * 0x0028ULL;
    return acc;
}

// FDE #0001 | PC: 0x04c198 | FDE: 0x03b1f8 | Size: 24 bytes
// Khung tháo gỡ #0001 | Địa chỉ PC: 0x04c198 | Địa chỉ FDE: 0x03b1f8 | Kích thước: 24 bytes
//   0x04c198: 910003BF  mov      sp, x29
//   0x04c19c: A8C17BFD  ldp      x29, x30, [sp], #0x10
//   0x04c1a0: D2801040  mov      x0, #0x82
//   0x04c1a4: D65F03C0  ret      
static inline uint64_t fde_func_0001_0x04c198(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x04c198ULL ^ (static_cast<uint64_t>(0x910003bfULL) << 13);
    acc = (acc + a1 + 0xa8c17bfdULL) ^ 0x03b1f8ULL;
    acc ^= (acc >> 17) * 0x0018ULL;
    return acc;
}

// FDE #0002 | PC: 0x04c1b0 | FDE: 0x03b218 | Size: 96 bytes [_return_entry_0_1]
// Khung tháo gỡ #0002 | Địa chỉ PC: 0x04c1b0 | Địa chỉ FDE: 0x03b218 | Kích thước: 96 bytes
//   0x04c1b0: F85F03B4  ldur     x20, [x29, #-0x10]
//   0x04c1b4: F85E03AE  ldur     x14, [x29, #-0x20]
//   0x04c1b8: 910005D8  add      x24, x14, #1
//   0x04c1bc: EA18031F  tst      x24, x24
static inline uint64_t fde_func_0002_0x04c1b0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x04c1b0ULL ^ (static_cast<uint64_t>(0xf85f03b4ULL) << 13);
    acc = (acc + a1 + 0xf85e03aeULL) ^ 0x03b218ULL;
    acc ^= (acc >> 17) * 0x0060ULL;
    return acc;
}

// FDE #0003 | PC: 0x04c210 | FDE: 0x03b230 | Size: 96 bytes [_return_entry_1_1]
// Khung tháo gỡ #0003 | Địa chỉ PC: 0x04c210 | Địa chỉ FDE: 0x03b230 | Kích thước: 96 bytes
//   0x04c210: F85F03B4  ldur     x20, [x29, #-0x10]
//   0x04c214: F85E03AE  ldur     x14, [x29, #-0x20]
//   0x04c218: 910005D8  add      x24, x14, #1
//   0x04c21c: EA18031F  tst      x24, x24
static inline uint64_t fde_func_0003_0x04c210(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x04c210ULL ^ (static_cast<uint64_t>(0xf85f03b4ULL) << 13);
    acc = (acc + a1 + 0xf85e03aeULL) ^ 0x03b230ULL;
    acc ^= (acc >> 17) * 0x0060ULL;
    return acc;
}

// FDE #0004 | PC: 0x04c270 | FDE: 0x03b248 | Size: 96 bytes [_return_entry_2_1]
// Khung tháo gỡ #0004 | Địa chỉ PC: 0x04c270 | Địa chỉ FDE: 0x03b248 | Kích thước: 96 bytes
//   0x04c270: F85F03B4  ldur     x20, [x29, #-0x10]
//   0x04c274: F85E03AE  ldur     x14, [x29, #-0x20]
//   0x04c278: 910005D8  add      x24, x14, #1
//   0x04c27c: EA18031F  tst      x24, x24
static inline uint64_t fde_func_0004_0x04c270(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x04c270ULL ^ (static_cast<uint64_t>(0xf85f03b4ULL) << 13);
    acc = (acc + a1 + 0xf85e03aeULL) ^ 0x03b248ULL;
    acc ^= (acc >> 17) * 0x0060ULL;
    return acc;
}

// FDE #0005 | PC: 0x04c2d0 | FDE: 0x03b260 | Size: 96 bytes [_return_entry_0_2]
// Khung tháo gỡ #0005 | Địa chỉ PC: 0x04c2d0 | Địa chỉ FDE: 0x03b260 | Kích thước: 96 bytes
//   0x04c2d0: F85F03B4  ldur     x20, [x29, #-0x10]
//   0x04c2d4: F85E03AE  ldur     x14, [x29, #-0x20]
//   0x04c2d8: 910005D8  add      x24, x14, #1
//   0x04c2dc: EA18031F  tst      x24, x24
static inline uint64_t fde_func_0005_0x04c2d0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x04c2d0ULL ^ (static_cast<uint64_t>(0xf85f03b4ULL) << 13);
    acc = (acc + a1 + 0xf85e03aeULL) ^ 0x03b260ULL;
    acc ^= (acc >> 17) * 0x0060ULL;
    return acc;
}

// FDE #0006 | PC: 0x04c330 | FDE: 0x03b278 | Size: 96 bytes [_return_entry_1_2]
// Khung tháo gỡ #0006 | Địa chỉ PC: 0x04c330 | Địa chỉ FDE: 0x03b278 | Kích thước: 96 bytes
//   0x04c330: F85F03B4  ldur     x20, [x29, #-0x10]
//   0x04c334: F85E03AE  ldur     x14, [x29, #-0x20]
//   0x04c338: 910005D8  add      x24, x14, #1
//   0x04c33c: EA18031F  tst      x24, x24
static inline uint64_t fde_func_0006_0x04c330(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x04c330ULL ^ (static_cast<uint64_t>(0xf85f03b4ULL) << 13);
    acc = (acc + a1 + 0xf85e03aeULL) ^ 0x03b278ULL;
    acc ^= (acc >> 17) * 0x0060ULL;
    return acc;
}

// FDE #0007 | PC: 0x04c390 | FDE: 0x03b290 | Size: 96 bytes [_return_entry_2_2]
// Khung tháo gỡ #0007 | Địa chỉ PC: 0x04c390 | Địa chỉ FDE: 0x03b290 | Kích thước: 96 bytes
//   0x04c390: F85F03B4  ldur     x20, [x29, #-0x10]
//   0x04c394: F85E03AE  ldur     x14, [x29, #-0x20]
//   0x04c398: 910005D8  add      x24, x14, #1
//   0x04c39c: EA18031F  tst      x24, x24
static inline uint64_t fde_func_0007_0x04c390(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x04c390ULL ^ (static_cast<uint64_t>(0xf85f03b4ULL) << 13);
    acc = (acc + a1 + 0xf85e03aeULL) ^ 0x03b290ULL;
    acc ^= (acc >> 17) * 0x0060ULL;
    return acc;
}

// FDE #0008 | PC: 0x04c3f0 | FDE: 0x03b2a8 | Size: 96 bytes [_return_entry_0_3]
// Khung tháo gỡ #0008 | Địa chỉ PC: 0x04c3f0 | Địa chỉ FDE: 0x03b2a8 | Kích thước: 96 bytes
//   0x04c3f0: F85F03B4  ldur     x20, [x29, #-0x10]
//   0x04c3f4: F85E03AE  ldur     x14, [x29, #-0x20]
//   0x04c3f8: 910005D8  add      x24, x14, #1
//   0x04c3fc: EA18031F  tst      x24, x24
static inline uint64_t fde_func_0008_0x04c3f0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x04c3f0ULL ^ (static_cast<uint64_t>(0xf85f03b4ULL) << 13);
    acc = (acc + a1 + 0xf85e03aeULL) ^ 0x03b2a8ULL;
    acc ^= (acc >> 17) * 0x0060ULL;
    return acc;
}

// FDE #0009 | PC: 0x04c450 | FDE: 0x03b2c0 | Size: 96 bytes [_return_entry_1_3]
// Khung tháo gỡ #0009 | Địa chỉ PC: 0x04c450 | Địa chỉ FDE: 0x03b2c0 | Kích thước: 96 bytes
//   0x04c450: F85F03B4  ldur     x20, [x29, #-0x10]
//   0x04c454: F85E03AE  ldur     x14, [x29, #-0x20]
//   0x04c458: 910005D8  add      x24, x14, #1
//   0x04c45c: EA18031F  tst      x24, x24
static inline uint64_t fde_func_0009_0x04c450(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x04c450ULL ^ (static_cast<uint64_t>(0xf85f03b4ULL) << 13);
    acc = (acc + a1 + 0xf85e03aeULL) ^ 0x03b2c0ULL;
    acc ^= (acc >> 17) * 0x0060ULL;
    return acc;
}

// FDE #0010 | PC: 0x04c4b0 | FDE: 0x03b2d8 | Size: 96 bytes [_return_entry_2_3]
// Khung tháo gỡ #0010 | Địa chỉ PC: 0x04c4b0 | Địa chỉ FDE: 0x03b2d8 | Kích thước: 96 bytes
//   0x04c4b0: F85F03B4  ldur     x20, [x29, #-0x10]
//   0x04c4b4: F85E03AE  ldur     x14, [x29, #-0x20]
//   0x04c4b8: 910005D8  add      x24, x14, #1
//   0x04c4bc: EA18031F  tst      x24, x24
static inline uint64_t fde_func_0010_0x04c4b0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x04c4b0ULL ^ (static_cast<uint64_t>(0xf85f03b4ULL) << 13);
    acc = (acc + a1 + 0xf85e03aeULL) ^ 0x03b2d8ULL;
    acc ^= (acc >> 17) * 0x0060ULL;
    return acc;
}

// FDE #0011 | PC: 0x04c510 | FDE: 0x03b2f0 | Size: 256 bytes [_normal_entry]
// Khung tháo gỡ #0011 | Địa chỉ PC: 0x04c510 | Địa chỉ FDE: 0x03b2f0 | Kích thước: 256 bytes
//   0x04c510: D10283FF  sub      sp, sp, #0xa0
//   0x04c514: F9401983  ldr      x3, [x12, #0x30]
//   0x04c518: 79405062  ldrh     w2, [x3, #0x28]
//   0x04c51c: 79405463  ldrh     w3, [x3, #0x2a]
static inline uint64_t fde_func_0011_0x04c510(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x04c510ULL ^ (static_cast<uint64_t>(0xd10283ffULL) << 13);
    acc = (acc + a1 + 0xf9401983ULL) ^ 0x03b2f0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0012 | PC: 0x04c6e0 | FDE: 0x03b310 | Size: 148 bytes [_native_entry]
// Khung tháo gỡ #0012 | Địa chỉ PC: 0x04c6e0 | Địa chỉ FDE: 0x03b310 | Kích thước: 148 bytes
//   0x04c6e0: AA1303E0  mov      x0, x19
//   0x04c6e4: AA0C03E1  mov      x1, x12
//   0x04c6e8: AA1903E2  mov      x2, x25
//   0x04c6ec: AA0E03E3  mov      x3, x14
static inline uint64_t fde_func_0012_0x04c6e0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x04c6e0ULL ^ (static_cast<uint64_t>(0xaa1303e0ULL) << 13);
    acc = (acc + a1 + 0xaa0c03e1ULL) ^ 0x03b310ULL;
    acc ^= (acc >> 17) * 0x0094ULL;
    return acc;
}

// FDE #0013 | PC: 0x04c774 | FDE: 0x03b328 | Size: 256 bytes
// Khung tháo gỡ #0013 | Địa chỉ PC: 0x04c774 | Địa chỉ FDE: 0x03b328 | Kích thước: 256 bytes
//   0x04c774: A9097BFD  stp      x29, x30, [sp, #0x90]
//   0x04c778: 910243FD  add      x29, sp, #0x90
//   0x04c77c: 910003E8  mov      x8, sp
//   0x04c780: A9395BA8  stp      x8, x22, [x29, #-0x70]
static inline uint64_t fde_func_0013_0x04c774(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x04c774ULL ^ (static_cast<uint64_t>(0xa9097bfdULL) << 13);
    acc = (acc + a1 + 0x910243fdULL) ^ 0x03b328ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0014 | PC: 0x04db60 | FDE: 0x03b348 | Size: 256 bytes
// Khung tháo gỡ #0014 | Địa chỉ PC: 0x04db60 | Địa chỉ FDE: 0x03b348 | Kích thước: 256 bytes
//   0x04db60: 784012CE  ldurh    w14, [x22, #1]
//   0x04db64: CB0E03E8  neg      x8, x14
//   0x04db68: D1000509  sub      x9, x8, #1
//   0x04db6c: F869DA8C  ldr      x12, [x20, w9, sxtw #3]
static inline uint64_t fde_func_0014_0x04db60(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x04db60ULL ^ (static_cast<uint64_t>(0x784012ceULL) << 13);
    acc = (acc + a1 + 0xcb0e03e8ULL) ^ 0x03b348ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0015 | PC: 0x04dc94 | FDE: 0x03b360 | Size: 28 bytes
// Khung tháo gỡ #0015 | Địa chỉ PC: 0x04dc94 | Địa chỉ FDE: 0x03b360 | Kích thước: 28 bytes
//   0x04dc94: 910003BF  mov      sp, x29
//   0x04dc98: A8C17BFD  ldp      x29, x30, [sp], #0x10
//   0x04dc9c: AA1903E0  mov      x0, x25
//   0x04dca0: D65F03C0  ret      
static inline uint64_t fde_func_0015_0x04dc94(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x04dc94ULL ^ (static_cast<uint64_t>(0x910003bfULL) << 13);
    acc = (acc + a1 + 0xa8c17bfdULL) ^ 0x03b360ULL;
    acc ^= (acc >> 17) * 0x001cULL;
    return acc;
}

// FDE #0016 | PC: 0x04dcb0 | FDE: 0x03b380 | Size: 256 bytes [_dispatch_table_0_35]
// Khung tháo gỡ #0016 | Địa chỉ PC: 0x04dcb0 | Địa chỉ FDE: 0x03b380 | Kích thước: 256 bytes
//   0x04dcb0: 784012CE  ldurh    w14, [x22, #1]
//   0x04dcb4: CB0E03E8  neg      x8, x14
//   0x04dcb8: D1000509  sub      x9, x8, #1
//   0x04dcbc: F869DA8C  ldr      x12, [x20, w9, sxtw #3]
static inline uint64_t fde_func_0016_0x04dcb0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x04dcb0ULL ^ (static_cast<uint64_t>(0x784012ceULL) << 13);
    acc = (acc + a1 + 0xcb0e03e8ULL) ^ 0x03b380ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0017 | PC: 0x04dde4 | FDE: 0x03b398 | Size: 256 bytes
// Khung tháo gỡ #0017 | Địa chỉ PC: 0x04dde4 | Địa chỉ FDE: 0x03b398 | Kích thước: 256 bytes
//   0x04dde4: 910003BF  mov      sp, x29
//   0x04dde8: A8C17BFD  ldp      x29, x30, [sp], #0x10
//   0x04ddec: AA1903E0  mov      x0, x25
//   0x04ddf0: D65F03C0  ret      
static inline uint64_t fde_func_0017_0x04dde4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x04dde4ULL ^ (static_cast<uint64_t>(0x910003bfULL) << 13);
    acc = (acc + a1 + 0xa8c17bfdULL) ^ 0x03b398ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0018 | PC: 0x04df88 | FDE: 0x03b3b8 | Size: 256 bytes
// Khung tháo gỡ #0018 | Địa chỉ PC: 0x04df88 | Địa chỉ FDE: 0x03b3b8 | Kích thước: 256 bytes
//   0x04df88: 784012CE  ldurh    w14, [x22, #1]
//   0x04df8c: CB0E03E8  neg      x8, x14
//   0x04df90: D1000508  sub      x8, x8, #1
//   0x04df94: F868DA8C  ldr      x12, [x20, w8, sxtw #3]
static inline uint64_t fde_func_0018_0x04df88(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x04df88ULL ^ (static_cast<uint64_t>(0x784012ceULL) << 13);
    acc = (acc + a1 + 0xcb0e03e8ULL) ^ 0x03b3b8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0019 | PC: 0x04e0c8 | FDE: 0x03b3d0 | Size: 28 bytes
// Khung tháo gỡ #0019 | Địa chỉ PC: 0x04e0c8 | Địa chỉ FDE: 0x03b3d0 | Kích thước: 28 bytes
//   0x04e0c8: 910003BF  mov      sp, x29
//   0x04e0cc: A8C17BFD  ldp      x29, x30, [sp], #0x10
//   0x04e0d0: AA1903E0  mov      x0, x25
//   0x04e0d4: D65F03C0  ret      
static inline uint64_t fde_func_0019_0x04e0c8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x04e0c8ULL ^ (static_cast<uint64_t>(0x910003bfULL) << 13);
    acc = (acc + a1 + 0xa8c17bfdULL) ^ 0x03b3d0ULL;
    acc ^= (acc >> 17) * 0x001cULL;
    return acc;
}

// FDE #0020 | PC: 0x04e0e4 | FDE: 0x03b3f0 | Size: 256 bytes [_dispatch_table_0_37]
// Khung tháo gỡ #0020 | Địa chỉ PC: 0x04e0e4 | Địa chỉ FDE: 0x03b3f0 | Kích thước: 256 bytes
//   0x04e0e4: 784012CE  ldurh    w14, [x22, #1]
//   0x04e0e8: CB0E03E8  neg      x8, x14
//   0x04e0ec: D1000508  sub      x8, x8, #1
//   0x04e0f0: F868DA8C  ldr      x12, [x20, w8, sxtw #3]
static inline uint64_t fde_func_0020_0x04e0e4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x04e0e4ULL ^ (static_cast<uint64_t>(0x784012ceULL) << 13);
    acc = (acc + a1 + 0xcb0e03e8ULL) ^ 0x03b3f0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0021 | PC: 0x04e224 | FDE: 0x03b408 | Size: 256 bytes
// Khung tháo gỡ #0021 | Địa chỉ PC: 0x04e224 | Địa chỉ FDE: 0x03b408 | Kích thước: 256 bytes
//   0x04e224: 910003BF  mov      sp, x29
//   0x04e228: A8C17BFD  ldp      x29, x30, [sp], #0x10
//   0x04e22c: AA1903E0  mov      x0, x25
//   0x04e230: D65F03C0  ret      
static inline uint64_t fde_func_0021_0x04e224(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x04e224ULL ^ (static_cast<uint64_t>(0x910003bfULL) << 13);
    acc = (acc + a1 + 0xa8c17bfdULL) ^ 0x03b408ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0022 | PC: 0x04e51c | FDE: 0x03b428 | Size: 84 bytes
// Khung tháo gỡ #0022 | Địa chỉ PC: 0x04e51c | Địa chỉ FDE: 0x03b428 | Kích thước: 84 bytes
//   0x04e51c: 910003BF  mov      sp, x29
//   0x04e520: A8C17BFD  ldp      x29, x30, [sp], #0x10
//   0x04e524: AA1903E0  mov      x0, x25
//   0x04e528: D65F03C0  ret      
static inline uint64_t fde_func_0022_0x04e51c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x04e51cULL ^ (static_cast<uint64_t>(0x910003bfULL) << 13);
    acc = (acc + a1 + 0xa8c17bfdULL) ^ 0x03b428ULL;
    acc ^= (acc >> 17) * 0x0054ULL;
    return acc;
}

// FDE #0023 | PC: 0x04e570 | FDE: 0x03b448 | Size: 88 bytes
// Khung tháo gỡ #0023 | Địa chỉ PC: 0x04e570 | Địa chỉ FDE: 0x03b448 | Kích thước: 88 bytes
//   0x04e570: 910003BF  mov      sp, x29
//   0x04e574: A8C17BFD  ldp      x29, x30, [sp], #0x10
//   0x04e578: AA1903E0  mov      x0, x25
//   0x04e57c: D65F03C0  ret      
static inline uint64_t fde_func_0023_0x04e570(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x04e570ULL ^ (static_cast<uint64_t>(0x910003bfULL) << 13);
    acc = (acc + a1 + 0xa8c17bfdULL) ^ 0x03b448ULL;
    acc ^= (acc >> 17) * 0x0058ULL;
    return acc;
}

// FDE #0024 | PC: 0x04e5c8 | FDE: 0x03b468 | Size: 88 bytes
// Khung tháo gỡ #0024 | Địa chỉ PC: 0x04e5c8 | Địa chỉ FDE: 0x03b468 | Kích thước: 88 bytes
//   0x04e5c8: 910003BF  mov      sp, x29
//   0x04e5cc: A8C17BFD  ldp      x29, x30, [sp], #0x10
//   0x04e5d0: D2800240  mov      x0, #0x12
//   0x04e5d4: D65F03C0  ret      
static inline uint64_t fde_func_0024_0x04e5c8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x04e5c8ULL ^ (static_cast<uint64_t>(0x910003bfULL) << 13);
    acc = (acc + a1 + 0xa8c17bfdULL) ^ 0x03b468ULL;
    acc ^= (acc >> 17) * 0x0058ULL;
    return acc;
}

// FDE #0025 | PC: 0x04e620 | FDE: 0x03b488 | Size: 256 bytes
// Khung tháo gỡ #0025 | Địa chỉ PC: 0x04e620 | Địa chỉ FDE: 0x03b488 | Kích thước: 256 bytes
//   0x04e620: 910003BF  mov      sp, x29
//   0x04e624: A8C17BFD  ldp      x29, x30, [sp], #0x10
//   0x04e628: D2800240  mov      x0, #0x12
//   0x04e62c: D65F03C0  ret      
static inline uint64_t fde_func_0025_0x04e620(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x04e620ULL ^ (static_cast<uint64_t>(0x910003bfULL) << 13);
    acc = (acc + a1 + 0xa8c17bfdULL) ^ 0x03b488ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0026 | PC: 0x04eab8 | FDE: 0x03b4a8 | Size: 76 bytes
// Khung tháo gỡ #0026 | Địa chỉ PC: 0x04eab8 | Địa chỉ FDE: 0x03b4a8 | Kích thước: 76 bytes
//   0x04eab8: 910003BF  mov      sp, x29
//   0x04eabc: A8C17BFD  ldp      x29, x30, [sp], #0x10
//   0x04eac0: D65F03C0  ret      
//   0x04eac4: 38401EC8  ldrb     w8, [x22, #1]!
static inline uint64_t fde_func_0026_0x04eab8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x04eab8ULL ^ (static_cast<uint64_t>(0x910003bfULL) << 13);
    acc = (acc + a1 + 0xa8c17bfdULL) ^ 0x03b4a8ULL;
    acc ^= (acc >> 17) * 0x004cULL;
    return acc;
}

// FDE #0027 | PC: 0x04eb04 | FDE: 0x03b4c8 | Size: 256 bytes
// Khung tháo gỡ #0027 | Địa chỉ PC: 0x04eb04 | Địa chỉ FDE: 0x03b4c8 | Kích thước: 256 bytes
//   0x04eb04: 910003BF  mov      sp, x29
//   0x04eb08: A8C17BFD  ldp      x29, x30, [sp], #0x10
//   0x04eb0c: D65F03C0  ret      
//   0x04eb10: 38401EC8  ldrb     w8, [x22, #1]!
static inline uint64_t fde_func_0027_0x04eb04(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x04eb04ULL ^ (static_cast<uint64_t>(0x910003bfULL) << 13);
    acc = (acc + a1 + 0xa8c17bfdULL) ^ 0x03b4c8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0028 | PC: 0x054604 | FDE: 0x03b4e8 | Size: 76 bytes
// Khung tháo gỡ #0028 | Địa chỉ PC: 0x054604 | Địa chỉ FDE: 0x03b4e8 | Kích thước: 76 bytes
//   0x054604: 910003BF  mov      sp, x29
//   0x054608: A8C17BFD  ldp      x29, x30, [sp], #0x10
//   0x05460c: D65F03C0  ret      
//   0x054610: 38401EC8  ldrb     w8, [x22, #1]!
static inline uint64_t fde_func_0028_0x054604(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x054604ULL ^ (static_cast<uint64_t>(0x910003bfULL) << 13);
    acc = (acc + a1 + 0xa8c17bfdULL) ^ 0x03b4e8ULL;
    acc ^= (acc >> 17) * 0x004cULL;
    return acc;
}

// FDE #0029 | PC: 0x054650 | FDE: 0x03b508 | Size: 80 bytes
// Khung tháo gỡ #0029 | Địa chỉ PC: 0x054650 | Địa chỉ FDE: 0x03b508 | Kích thước: 80 bytes
//   0x054650: 910003BF  mov      sp, x29
//   0x054654: A8C17BFD  ldp      x29, x30, [sp], #0x10
//   0x054658: D65F03C0  ret      
//   0x05465c: 38401EC8  ldrb     w8, [x22, #1]!
static inline uint64_t fde_func_0029_0x054650(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x054650ULL ^ (static_cast<uint64_t>(0x910003bfULL) << 13);
    acc = (acc + a1 + 0xa8c17bfdULL) ^ 0x03b508ULL;
    acc ^= (acc >> 17) * 0x0050ULL;
    return acc;
}

// FDE #0030 | PC: 0x0546a0 | FDE: 0x03b528 | Size: 80 bytes
// Khung tháo gỡ #0030 | Địa chỉ PC: 0x0546a0 | Địa chỉ FDE: 0x03b528 | Kích thước: 80 bytes
//   0x0546a0: 910003BF  mov      sp, x29
//   0x0546a4: A8C17BFD  ldp      x29, x30, [sp], #0x10
//   0x0546a8: D65F03C0  ret      
//   0x0546ac: 38401EC8  ldrb     w8, [x22, #1]!
static inline uint64_t fde_func_0030_0x0546a0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0546a0ULL ^ (static_cast<uint64_t>(0x910003bfULL) << 13);
    acc = (acc + a1 + 0xa8c17bfdULL) ^ 0x03b528ULL;
    acc ^= (acc >> 17) * 0x0050ULL;
    return acc;
}

// FDE #0031 | PC: 0x0546f0 | FDE: 0x03b548 | Size: 80 bytes
// Khung tháo gỡ #0031 | Địa chỉ PC: 0x0546f0 | Địa chỉ FDE: 0x03b548 | Kích thước: 80 bytes
//   0x0546f0: 910003BF  mov      sp, x29
//   0x0546f4: A8C17BFD  ldp      x29, x30, [sp], #0x10
//   0x0546f8: D65F03C0  ret      
//   0x0546fc: 38401EC8  ldrb     w8, [x22, #1]!
static inline uint64_t fde_func_0031_0x0546f0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0546f0ULL ^ (static_cast<uint64_t>(0x910003bfULL) << 13);
    acc = (acc + a1 + 0xa8c17bfdULL) ^ 0x03b548ULL;
    acc ^= (acc >> 17) * 0x0050ULL;
    return acc;
}

// FDE #0032 | PC: 0x054740 | FDE: 0x03b568 | Size: 80 bytes
// Khung tháo gỡ #0032 | Địa chỉ PC: 0x054740 | Địa chỉ FDE: 0x03b568 | Kích thước: 80 bytes
//   0x054740: 910003BF  mov      sp, x29
//   0x054744: A8C17BFD  ldp      x29, x30, [sp], #0x10
//   0x054748: D65F03C0  ret      
//   0x05474c: 38401EC8  ldrb     w8, [x22, #1]!
static inline uint64_t fde_func_0032_0x054740(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x054740ULL ^ (static_cast<uint64_t>(0x910003bfULL) << 13);
    acc = (acc + a1 + 0xa8c17bfdULL) ^ 0x03b568ULL;
    acc ^= (acc >> 17) * 0x0050ULL;
    return acc;
}

// FDE #0033 | PC: 0x054790 | FDE: 0x03b588 | Size: 80 bytes
// Khung tháo gỡ #0033 | Địa chỉ PC: 0x054790 | Địa chỉ FDE: 0x03b588 | Kích thước: 80 bytes
//   0x054790: 910003BF  mov      sp, x29
//   0x054794: A8C17BFD  ldp      x29, x30, [sp], #0x10
//   0x054798: D65F03C0  ret      
//   0x05479c: 38401EC8  ldrb     w8, [x22, #1]!
static inline uint64_t fde_func_0033_0x054790(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x054790ULL ^ (static_cast<uint64_t>(0x910003bfULL) << 13);
    acc = (acc + a1 + 0xa8c17bfdULL) ^ 0x03b588ULL;
    acc ^= (acc >> 17) * 0x0050ULL;
    return acc;
}

// FDE #0034 | PC: 0x0547e0 | FDE: 0x03b5a8 | Size: 80 bytes
// Khung tháo gỡ #0034 | Địa chỉ PC: 0x0547e0 | Địa chỉ FDE: 0x03b5a8 | Kích thước: 80 bytes
//   0x0547e0: 910003BF  mov      sp, x29
//   0x0547e4: A8C17BFD  ldp      x29, x30, [sp], #0x10
//   0x0547e8: D65F03C0  ret      
//   0x0547ec: 38401EC8  ldrb     w8, [x22, #1]!
static inline uint64_t fde_func_0034_0x0547e0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0547e0ULL ^ (static_cast<uint64_t>(0x910003bfULL) << 13);
    acc = (acc + a1 + 0xa8c17bfdULL) ^ 0x03b5a8ULL;
    acc ^= (acc >> 17) * 0x0050ULL;
    return acc;
}

// FDE #0035 | PC: 0x054830 | FDE: 0x03b5c8 | Size: 76 bytes
// Khung tháo gỡ #0035 | Địa chỉ PC: 0x054830 | Địa chỉ FDE: 0x03b5c8 | Kích thước: 76 bytes
//   0x054830: 910003BF  mov      sp, x29
//   0x054834: A8C17BFD  ldp      x29, x30, [sp], #0x10
//   0x054838: D65F03C0  ret      
//   0x05483c: 38401EC8  ldrb     w8, [x22, #1]!
static inline uint64_t fde_func_0035_0x054830(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x054830ULL ^ (static_cast<uint64_t>(0x910003bfULL) << 13);
    acc = (acc + a1 + 0xa8c17bfdULL) ^ 0x03b5c8ULL;
    acc ^= (acc >> 17) * 0x004cULL;
    return acc;
}

// FDE #0036 | PC: 0x05487c | FDE: 0x03b5e8 | Size: 76 bytes
// Khung tháo gỡ #0036 | Địa chỉ PC: 0x05487c | Địa chỉ FDE: 0x03b5e8 | Kích thước: 76 bytes
//   0x05487c: 910003BF  mov      sp, x29
//   0x054880: A8C17BFD  ldp      x29, x30, [sp], #0x10
//   0x054884: D65F03C0  ret      
//   0x054888: 38401EC8  ldrb     w8, [x22, #1]!
static inline uint64_t fde_func_0036_0x05487c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x05487cULL ^ (static_cast<uint64_t>(0x910003bfULL) << 13);
    acc = (acc + a1 + 0xa8c17bfdULL) ^ 0x03b5e8ULL;
    acc ^= (acc >> 17) * 0x004cULL;
    return acc;
}

// FDE #0037 | PC: 0x0548c8 | FDE: 0x03b608 | Size: 256 bytes
// Khung tháo gỡ #0037 | Địa chỉ PC: 0x0548c8 | Địa chỉ FDE: 0x03b608 | Kích thước: 256 bytes
//   0x0548c8: 910003BF  mov      sp, x29
//   0x0548cc: A8C17BFD  ldp      x29, x30, [sp], #0x10
//   0x0548d0: D65F03C0  ret      
//   0x0548d4: 38401EC8  ldrb     w8, [x22, #1]!
static inline uint64_t fde_func_0037_0x0548c8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0548c8ULL ^ (static_cast<uint64_t>(0x910003bfULL) << 13);
    acc = (acc + a1 + 0xa8c17bfdULL) ^ 0x03b608ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0038 | PC: 0x05c598 | FDE: 0x03b628 | Size: 256 bytes [_call_stub_entry]
// Khung tháo gỡ #0038 | Địa chỉ PC: 0x05c598 | Địa chỉ FDE: 0x03b628 | Kích thước: 256 bytes
//   0x05c598: A9BF7BFD  stp      x29, x30, [sp, #-0x10]!
//   0x05c59c: 910003FD  mov      x29, sp
//   0x05c5a0: D10143BF  sub      sp, x29, #0x50
//   0x05c5a4: A93F4FB4  stp      x20, x19, [x29, #-0x10]
static inline uint64_t fde_func_0038_0x05c598(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x05c598ULL ^ (static_cast<uint64_t>(0xa9bf7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x03b628ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0039 | PC: 0x05d1cc | FDE: 0x03b648 | Size: 12 bytes
// Khung tháo gỡ #0039 | Địa chỉ PC: 0x05d1cc | Địa chỉ FDE: 0x03b648 | Kích thước: 12 bytes
//   0x05d1cc: 9E6703E1  fmov     d1, xzr
//   0x05d1d0: 2A1F03E0  mov      w0, wzr
//   0x05d1d4: 14000001  b        #0x5d1d8
static inline uint64_t fde_func_0039_0x05d1cc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x05d1ccULL ^ (static_cast<uint64_t>(0x9e6703e1ULL) << 13);
    acc = (acc + a1 + 0x2a1f03e0ULL) ^ 0x03b648ULL;
    acc ^= (acc >> 17) * 0x000cULL;
    return acc;
}

// FDE #0040 | PC: 0x05d1d8 | FDE: 0x03b660 | Size: 256 bytes
// Khung tháo gỡ #0040 | Địa chỉ PC: 0x05d1d8 | Địa chỉ FDE: 0x03b660 | Kích thước: 256 bytes
//   0x05d1d8: 9E660009  fmov     x9, d0
//   0x05d1dc: D374F928  ubfx     x8, x9, #0x34, #0xb
//   0x05d1e0: 510F250A  sub      w10, w8, #0x3c9
//   0x05d1e4: 7100FD5F  cmp      w10, #0x3f
static inline uint64_t fde_func_0040_0x05d1d8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x05d1d8ULL ^ (static_cast<uint64_t>(0x9e660009ULL) << 13);
    acc = (acc + a1 + 0xd374f928ULL) ^ 0x03b660ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0041 | PC: 0x05d2dc | FDE: 0x03b678 | Size: 136 bytes
// Khung tháo gỡ #0041 | Địa chỉ PC: 0x05d2dc | Địa chỉ FDE: 0x03b678 | Kích thước: 136 bytes
//   0x05d2dc: 37F80121  tbnz     w1, #0x1f, #0x5d300
//   0x05d2e0: D2F81E08  mov      x8, #-0x3f10000000000000
//   0x05d2e4: 8B080008  add      x8, x0, x8
//   0x05d2e8: D2EFE009  mov      x9, #0x7f00000000000000
static inline uint64_t fde_func_0041_0x05d2dc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x05d2dcULL ^ (static_cast<uint64_t>(0x37f80121ULL) << 13);
    acc = (acc + a1 + 0xd2f81e08ULL) ^ 0x03b678ULL;
    acc ^= (acc >> 17) * 0x0088ULL;
    return acc;
}

// FDE #0042 | PC: 0x05d364 | FDE: 0x03b690 | Size: 256 bytes
// Khung tháo gỡ #0042 | Địa chỉ PC: 0x05d364 | Địa chỉ FDE: 0x03b690 | Kích thước: 256 bytes
//   0x05d364: 9E660008  fmov     x8, d0
//   0x05d368: D2F80249  mov      x9, #-0x3fee000000000000
//   0x05d36c: 8B090109  add      x9, x8, x9
//   0x05d370: D368FD29  lsr      x9, x9, #0x28
static inline uint64_t fde_func_0042_0x05d364(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x05d364ULL ^ (static_cast<uint64_t>(0x9e660008ULL) << 13);
    acc = (acc + a1 + 0xd2f80249ULL) ^ 0x03b690ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0043 | PC: 0x05d4f8 | FDE: 0x03b6a8 | Size: 256 bytes
// Khung tháo gỡ #0043 | Địa chỉ PC: 0x05d4f8 | Địa chỉ FDE: 0x03b6a8 | Kích thước: 256 bytes
//   0x05d4f8: D2CB6A29  mov      x9, #0x5b5100000000
//   0x05d4fc: 9E660008  fmov     x8, d0
//   0x05d500: F2F80229  movk     x9, #0xc011, lsl #48
//   0x05d504: 92DDEACA  mov      x10, #-0xef5600000001
static inline uint64_t fde_func_0043_0x05d4f8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x05d4f8ULL ^ (static_cast<uint64_t>(0xd2cb6a29ULL) << 13);
    acc = (acc + a1 + 0x9e660008ULL) ^ 0x03b6a8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0044 | PC: 0x05d688 | FDE: 0x03b6c0 | Size: 12 bytes
// Khung tháo gỡ #0044 | Địa chỉ PC: 0x05d688 | Địa chỉ FDE: 0x03b6c0 | Kích thước: 12 bytes
//   0x05d688: D2E20008  mov      x8, #0x1000000000000000
//   0x05d68c: 9E670100  fmov     d0, x8
//   0x05d690: 14000001  b        #0x5d694
static inline uint64_t fde_func_0044_0x05d688(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x05d688ULL ^ (static_cast<uint64_t>(0xd2e20008ULL) << 13);
    acc = (acc + a1 + 0x9e670100ULL) ^ 0x03b6c0ULL;
    acc ^= (acc >> 17) * 0x000cULL;
    return acc;
}

// FDE #0045 | PC: 0x05d694 | FDE: 0x03b6d8 | Size: 20 bytes
// Khung tháo gỡ #0045 | Địa chỉ PC: 0x05d694 | Địa chỉ FDE: 0x03b6d8 | Kích thước: 20 bytes
//   0x05d694: 1E614001  fneg     d1, d0
//   0x05d698: 7100001F  cmp      w0, #0
//   0x05d69c: 1E610C01  fcsel    d1, d0, d1, eq
//   0x05d6a0: 1E600820  fmul     d0, d1, d0
static inline uint64_t fde_func_0045_0x05d694(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x05d694ULL ^ (static_cast<uint64_t>(0x1e614001ULL) << 13);
    acc = (acc + a1 + 0x7100001fULL) ^ 0x03b6d8ULL;
    acc ^= (acc >> 17) * 0x0014ULL;
    return acc;
}

// FDE #0046 | PC: 0x05d6a8 | FDE: 0x03b6f0 | Size: 12 bytes
// Khung tháo gỡ #0046 | Địa chỉ PC: 0x05d6a8 | Địa chỉ FDE: 0x03b6f0 | Kích thước: 12 bytes
//   0x05d6a8: D2EE0008  mov      x8, #0x7000000000000000
//   0x05d6ac: 9E670100  fmov     d0, x8
//   0x05d6b0: 17FFFFF9  b        #0x5d694
static inline uint64_t fde_func_0046_0x05d6a8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x05d6a8ULL ^ (static_cast<uint64_t>(0xd2ee0008ULL) << 13);
    acc = (acc + a1 + 0x9e670100ULL) ^ 0x03b6f0ULL;
    acc ^= (acc >> 17) * 0x000cULL;
    return acc;
}

// FDE #0047 | PC: 0x05d6b4 | FDE: 0x03b708 | Size: 28 bytes
// Khung tháo gỡ #0047 | Địa chỉ PC: 0x05d6b4 | Địa chỉ FDE: 0x03b708 | Kích thước: 28 bytes
//   0x05d6b4: 7100001F  cmp      w0, #0
//   0x05d6b8: 1E7E1000  fmov     d0, #-1.00000000
//   0x05d6bc: 1E6E1001  fmov     d1, #1.00000000
//   0x05d6c0: 1E600C20  fcsel    d0, d1, d0, eq
static inline uint64_t fde_func_0047_0x05d6b4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x05d6b4ULL ^ (static_cast<uint64_t>(0x7100001fULL) << 13);
    acc = (acc + a1 + 0x1e7e1000ULL) ^ 0x03b708ULL;
    acc ^= (acc >> 17) * 0x001cULL;
    return acc;
}

// FDE #0048 | PC: 0x05d6d0 | FDE: 0x03b720 | Size: 12 bytes
// Khung tháo gỡ #0048 | Địa chỉ PC: 0x05d6d0 | Địa chỉ FDE: 0x03b720 | Kích thước: 12 bytes
//   0x05d6d0: 1E603800  fsub     d0, d0, d0
//   0x05d6d4: 1E601800  fdiv     d0, d0, d0
//   0x05d6d8: D65F03C0  ret      
static inline uint64_t fde_func_0048_0x05d6d0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x05d6d0ULL ^ (static_cast<uint64_t>(0x1e603800ULL) << 13);
    acc = (acc + a1 + 0x1e601800ULL) ^ 0x03b720ULL;
    acc ^= (acc >> 17) * 0x000cULL;
    return acc;
}

// FDE #0049 | PC: 0x05d6dc | FDE: 0x03b738 | Size: 256 bytes
// Khung tháo gỡ #0049 | Địa chỉ PC: 0x05d6dc | Địa chỉ FDE: 0x03b738 | Kích thước: 256 bytes
//   0x05d6dc: 9E660009  fmov     x9, d0
//   0x05d6e0: D360FD28  lsr      x8, x9, #0x20
//   0x05d6e4: 5314790A  ubfx     w10, w8, #0x14, #0xb
//   0x05d6e8: 710FFD5F  cmp      w10, #0x3ff
static inline uint64_t fde_func_0049_0x05d6dc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x05d6dcULL ^ (static_cast<uint64_t>(0x9e660009ULL) << 13);
    acc = (acc + a1 + 0xd360fd28ULL) ^ 0x03b738ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0050 | PC: 0x05da00 | FDE: 0x03b750 | Size: 204 bytes
// Khung tháo gỡ #0050 | Địa chỉ PC: 0x05da00 | Địa chỉ FDE: 0x03b750 | Kích thước: 204 bytes
//   0x05da00: 9E660009  fmov     x9, d0
//   0x05da04: D360FD28  lsr      x8, x9, #0x20
//   0x05da08: 12B8020A  mov      w10, #0x3fefffff
//   0x05da0c: 6B0A011F  cmp      w8, w10
static inline uint64_t fde_func_0050_0x05da00(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x05da00ULL ^ (static_cast<uint64_t>(0x9e660009ULL) << 13);
    acc = (acc + a1 + 0xd360fd28ULL) ^ 0x03b750ULL;
    acc ^= (acc >> 17) * 0x00ccULL;
    return acc;
}

// FDE #0051 | PC: 0x05dacc | FDE: 0x03b770 | Size: 256 bytes
// Khung tháo gỡ #0051 | Địa chỉ PC: 0x05dacc | Địa chỉ FDE: 0x03b770 | Kích thước: 256 bytes
//   0x05dacc: 9E66000A  fmov     x10, d0
//   0x05dad0: D360FD48  lsr      x8, x10, #0x20
//   0x05dad4: 53147909  ubfx     w9, w8, #0x14, #0xb
//   0x05dad8: 710FFD3F  cmp      w9, #0x3ff
static inline uint64_t fde_func_0051_0x05dacc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x05daccULL ^ (static_cast<uint64_t>(0x9e66000aULL) << 13);
    acc = (acc + a1 + 0xd360fd48ULL) ^ 0x03b770ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0052 | PC: 0x05dd60 | FDE: 0x03b788 | Size: 256 bytes
// Khung tháo gỡ #0052 | Địa chỉ PC: 0x05dd60 | Địa chỉ FDE: 0x03b788 | Kích thước: 256 bytes
//   0x05dd60: D10103FF  sub      sp, sp, #0x40
//   0x05dd64: FD000BE8  str      d8, [sp, #0x10]
//   0x05dd68: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x05dd6c: A9037BFD  stp      x29, x30, [sp, #0x30]
static inline uint64_t fde_func_0052_0x05dd60(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x05dd60ULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xfd000be8ULL) ^ 0x03b788ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0053 | PC: 0x05e028 | FDE: 0x03b7b0 | Size: 224 bytes
// Khung tháo gỡ #0053 | Địa chỉ PC: 0x05e028 | Địa chỉ FDE: 0x03b7b0 | Kích thước: 224 bytes
//   0x05e028: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x05e02c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x05e030: 910043FD  add      x29, sp, #0x10
//   0x05e034: 9E660009  fmov     x9, d0
static inline uint64_t fde_func_0053_0x05e028(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x05e028ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x03b7b0ULL;
    acc ^= (acc >> 17) * 0x00e0ULL;
    return acc;
}

// FDE #0054 | PC: 0x05e108 | FDE: 0x03b7d0 | Size: 236 bytes
// Khung tháo gỡ #0054 | Địa chỉ PC: 0x05e108 | Địa chỉ FDE: 0x03b7d0 | Kích thước: 236 bytes
//   0x05e108: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x05e10c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x05e110: 910043FD  add      x29, sp, #0x10
//   0x05e114: 9E660008  fmov     x8, d0
static inline uint64_t fde_func_0054_0x05e108(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x05e108ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x03b7d0ULL;
    acc ^= (acc >> 17) * 0x00ecULL;
    return acc;
}

// FDE #0055 | PC: 0x05e1f4 | FDE: 0x03b7f0 | Size: 256 bytes
// Khung tháo gỡ #0055 | Địa chỉ PC: 0x05e1f4 | Địa chỉ FDE: 0x03b7f0 | Kích thước: 256 bytes
//   0x05e1f4: D10183FF  sub      sp, sp, #0x60
//   0x05e1f8: FD0013EA  str      d10, [sp, #0x20]
//   0x05e1fc: 6D0323E9  stp      d9, d8, [sp, #0x30]
//   0x05e200: A9044FF4  stp      x20, x19, [sp, #0x40]
static inline uint64_t fde_func_0055_0x05e1f4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x05e1f4ULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xfd0013eaULL) ^ 0x03b7f0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0056 | PC: 0x05e42c | FDE: 0x03b820 | Size: 256 bytes
// Khung tháo gỡ #0056 | Địa chỉ PC: 0x05e42c | Địa chỉ FDE: 0x03b820 | Kích thước: 256 bytes
//   0x05e42c: 9E660009  fmov     x9, d0
//   0x05e430: D360FD28  lsr      x8, x9, #0x20
//   0x05e434: 7144011F  cmp      w8, #0x100, lsl #12
//   0x05e438: 5400018A  b.ge     #0x5e468
static inline uint64_t fde_func_0056_0x05e42c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x05e42cULL ^ (static_cast<uint64_t>(0x9e660009ULL) << 13);
    acc = (acc + a1 + 0xd360fd28ULL) ^ 0x03b820ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0057 | PC: 0x05e620 | FDE: 0x03b838 | Size: 256 bytes
// Khung tháo gỡ #0057 | Địa chỉ PC: 0x05e620 | Địa chỉ FDE: 0x03b838 | Kích thước: 256 bytes
//   0x05e620: 6DBD23E9  stp      d9, d8, [sp, #-0x30]!
//   0x05e624: F9000BF3  str      x19, [sp, #0x10]
//   0x05e628: A9027BFD  stp      x29, x30, [sp, #0x20]
//   0x05e62c: 910083FD  add      x29, sp, #0x20
static inline uint64_t fde_func_0057_0x05e620(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x05e620ULL ^ (static_cast<uint64_t>(0x6dbd23e9ULL) << 13);
    acc = (acc + a1 + 0xf9000bf3ULL) ^ 0x03b838ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0058 | PC: 0x05e730 | FDE: 0x03b860 | Size: 88 bytes
// Khung tháo gỡ #0058 | Địa chỉ PC: 0x05e730 | Địa chỉ FDE: 0x03b860 | Kích thước: 88 bytes
//   0x05e730: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x05e734: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x05e738: 910043FD  add      x29, sp, #0x10
//   0x05e73c: D0FFFE68  adrp     x8, #0x2c000
static inline uint64_t fde_func_0058_0x05e730(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x05e730ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x03b860ULL;
    acc ^= (acc >> 17) * 0x0058ULL;
    return acc;
}

// FDE #0059 | PC: 0x05e788 | FDE: 0x03b880 | Size: 232 bytes
// Khung tháo gỡ #0059 | Địa chỉ PC: 0x05e788 | Địa chỉ FDE: 0x03b880 | Kích thước: 232 bytes
//   0x05e788: F81E0FF3  str      x19, [sp, #-0x20]!
//   0x05e78c: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x05e790: 910043FD  add      x29, sp, #0x10
//   0x05e794: 9E660008  fmov     x8, d0
static inline uint64_t fde_func_0059_0x05e788(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x05e788ULL ^ (static_cast<uint64_t>(0xf81e0ff3ULL) << 13);
    acc = (acc + a1 + 0xa9017bfdULL) ^ 0x03b880ULL;
    acc ^= (acc >> 17) * 0x00e8ULL;
    return acc;
}

// FDE #0060 | PC: 0x05e870 | FDE: 0x03b8a0 | Size: 256 bytes
// Khung tháo gỡ #0060 | Địa chỉ PC: 0x05e870 | Địa chỉ FDE: 0x03b8a0 | Kích thước: 256 bytes
//   0x05e870: 9E660009  fmov     x9, d0
//   0x05e874: D360FD28  lsr      x8, x9, #0x20
//   0x05e878: 5314790A  ubfx     w10, w8, #0x14, #0xb
//   0x05e87c: 7111055F  cmp      w10, #0x441
static inline uint64_t fde_func_0060_0x05e870(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x05e870ULL ^ (static_cast<uint64_t>(0x9e660009ULL) << 13);
    acc = (acc + a1 + 0xd360fd28ULL) ^ 0x03b8a0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0061 | PC: 0x05eab0 | FDE: 0x03b8b8 | Size: 256 bytes
// Khung tháo gỡ #0061 | Địa chỉ PC: 0x05eab0 | Địa chỉ FDE: 0x03b8b8 | Kích thước: 256 bytes
//   0x05eab0: 9E660009  fmov     x9, d0
//   0x05eab4: D360FD28  lsr      x8, x9, #0x20
//   0x05eab8: 5314790A  ubfx     w10, w8, #0x14, #0xb
//   0x05eabc: 711FFD5F  cmp      w10, #0x7ff
static inline uint64_t fde_func_0061_0x05eab0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x05eab0ULL ^ (static_cast<uint64_t>(0x9e660009ULL) << 13);
    acc = (acc + a1 + 0xd360fd28ULL) ^ 0x03b8b8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0062 | PC: 0x05ebc4 | FDE: 0x03b8d0 | Size: 256 bytes
// Khung tháo gỡ #0062 | Địa chỉ PC: 0x05ebc4 | Địa chỉ FDE: 0x03b8d0 | Kích thước: 256 bytes
//   0x05ebc4: D10143FF  sub      sp, sp, #0x50
//   0x05ebc8: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x05ebcc: A9047BFD  stp      x29, x30, [sp, #0x40]
//   0x05ebd0: 910103FD  add      x29, sp, #0x40
static inline uint64_t fde_func_0062_0x05ebc4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x05ebc4ULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xa9034ff4ULL) ^ 0x03b8d0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0063 | PC: 0x05efa0 | FDE: 0x03b8f8 | Size: 152 bytes
// Khung tháo gỡ #0063 | Địa chỉ PC: 0x05efa0 | Địa chỉ FDE: 0x03b8f8 | Kích thước: 152 bytes
//   0x05efa0: 1E600802  fmul     d2, d0, d0
//   0x05efa4: D0FFFE68  adrp     x8, #0x2c000
//   0x05efa8: 1E6C1006  fmov     d6, #0.50000000
//   0x05efac: FD459103  ldr      d3, [x8, #0xb20]
static inline uint64_t fde_func_0063_0x05efa0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x05efa0ULL ^ (static_cast<uint64_t>(0x1e600802ULL) << 13);
    acc = (acc + a1 + 0xd0fffe68ULL) ^ 0x03b8f8ULL;
    acc ^= (acc >> 17) * 0x0098ULL;
    return acc;
}

// FDE #0064 | PC: 0x05f038 | FDE: 0x03b910 | Size: 256 bytes
// Khung tháo gỡ #0064 | Địa chỉ PC: 0x05f038 | Địa chỉ FDE: 0x03b910 | Kích thước: 256 bytes
//   0x05f038: FC170FEC  str      d12, [sp, #-0x90]!
//   0x05f03c: 6D012BEB  stp      d11, d10, [sp, #0x10]
//   0x05f040: 6D0223E9  stp      d9, d8, [sp, #0x20]
//   0x05f044: A9036FFC  stp      x28, x27, [sp, #0x30]
static inline uint64_t fde_func_0064_0x05f038(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x05f038ULL ^ (static_cast<uint64_t>(0xfc170fecULL) << 13);
    acc = (acc + a1 + 0x6d012bebULL) ^ 0x03b910ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0065 | PC: 0x05f8dc | FDE: 0x03b950 | Size: 168 bytes
// Khung tháo gỡ #0065 | Địa chỉ PC: 0x05f8dc | Địa chỉ FDE: 0x03b950 | Kích thước: 168 bytes
//   0x05f8dc: B0FFFE68  adrp     x8, #0x2c000
//   0x05f8e0: FD46C503  ldr      d3, [x8, #0xd88]
//   0x05f8e4: B0FFFE68  adrp     x8, #0x2c000
//   0x05f8e8: FD45CD04  ldr      d4, [x8, #0xb98]
static inline uint64_t fde_func_0065_0x05f8dc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x05f8dcULL ^ (static_cast<uint64_t>(0xb0fffe68ULL) << 13);
    acc = (acc + a1 + 0xfd46c503ULL) ^ 0x03b950ULL;
    acc ^= (acc >> 17) * 0x00a8ULL;
    return acc;
}

// FDE #0066 | PC: 0x05f984 | FDE: 0x03b968 | Size: 256 bytes
// Khung tháo gỡ #0066 | Địa chỉ PC: 0x05f984 | Địa chỉ FDE: 0x03b968 | Kích thước: 256 bytes
//   0x05f984: 9E660009  fmov     x9, d0
//   0x05f988: 528D0F4B  mov      w11, #0x687a
//   0x05f98c: D360F92A  ubfx     x10, x9, #0x20, #0x1f
//   0x05f990: 72A8086B  movk     w11, #0x4043, lsl #16
static inline uint64_t fde_func_0066_0x05f984(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x05f984ULL ^ (static_cast<uint64_t>(0x9e660009ULL) << 13);
    acc = (acc + a1 + 0x528d0f4bULL) ^ 0x03b968ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0067 | PC: 0x05fca8 | FDE: 0x03b980 | Size: 256 bytes
// Khung tháo gỡ #0067 | Địa chỉ PC: 0x05fca8 | Địa chỉ FDE: 0x03b980 | Kích thước: 256 bytes
//   0x05fca8: 9E660008  fmov     x8, d0
//   0x05fcac: 52904F2A  mov      w10, #0x8279
//   0x05fcb0: D360FD09  lsr      x9, x8, #0x20
//   0x05fcb4: 72A7FB4A  movk     w10, #0x3fda, lsl #16
static inline uint64_t fde_func_0067_0x05fca8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x05fca8ULL ^ (static_cast<uint64_t>(0x9e660008ULL) << 13);
    acc = (acc + a1 + 0x52904f2aULL) ^ 0x03b980ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0068 | PC: 0x05ff8c | FDE: 0x03b998 | Size: 252 bytes
// Khung tháo gỡ #0068 | Địa chỉ PC: 0x05ff8c | Địa chỉ FDE: 0x03b998 | Kích thước: 252 bytes
//   0x05ff8c: 9E66000A  fmov     x10, d0
//   0x05ff90: D374F949  ubfx     x9, x10, #0x34, #0xb
//   0x05ff94: 711FFD3F  cmp      w9, #0x7ff
//   0x05ff98: 54000200  b.eq     #0x5ffd8
static inline uint64_t fde_func_0068_0x05ff8c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x05ff8cULL ^ (static_cast<uint64_t>(0x9e66000aULL) << 13);
    acc = (acc + a1 + 0xd374f949ULL) ^ 0x03b998ULL;
    acc ^= (acc >> 17) * 0x00fcULL;
    return acc;
}

// FDE #0069 | PC: 0x060088 | FDE: 0x03b9b0 | Size: 256 bytes
// Khung tháo gỡ #0069 | Địa chỉ PC: 0x060088 | Địa chỉ FDE: 0x03b9b0 | Kích thước: 256 bytes
//   0x060088: D10143FF  sub      sp, sp, #0x50
//   0x06008c: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x060090: A9047BFD  stp      x29, x30, [sp, #0x40]
//   0x060094: 910103FD  add      x29, sp, #0x40
static inline uint64_t fde_func_0069_0x060088(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x060088ULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xa9034ff4ULL) ^ 0x03b9b0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0070 | PC: 0x060458 | FDE: 0x03b9d8 | Size: 256 bytes
// Khung tháo gỡ #0070 | Địa chỉ PC: 0x060458 | Địa chỉ FDE: 0x03b9d8 | Kích thước: 256 bytes
//   0x060458: D10143FF  sub      sp, sp, #0x50
//   0x06045c: A9034FF4  stp      x20, x19, [sp, #0x30]
//   0x060460: A9047BFD  stp      x29, x30, [sp, #0x40]
//   0x060464: 910103FD  add      x29, sp, #0x40
static inline uint64_t fde_func_0070_0x060458(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x060458ULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xa9034ff4ULL) ^ 0x03b9d8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0071 | PC: 0x0607d4 | FDE: 0x03ba00 | Size: 256 bytes
// Khung tháo gỡ #0071 | Địa chỉ PC: 0x0607d4 | Địa chỉ FDE: 0x03ba00 | Kích thước: 256 bytes
//   0x0607d4: 9E660008  fmov     x8, d0
//   0x0607d8: D360FD0B  lsr      x11, x8, #0x20
//   0x0607dc: 5292850A  mov      w10, #0x9428
//   0x0607e0: 121D6D69  and      w9, w11, #0x7ffffff8
static inline uint64_t fde_func_0071_0x0607d4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0607d4ULL ^ (static_cast<uint64_t>(0x9e660008ULL) << 13);
    acc = (acc + a1 + 0xd360fd0bULL) ^ 0x03ba00ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0072 | PC: 0x0609a8 | FDE: 0x03ba18 | Size: 236 bytes
// Khung tháo gỡ #0072 | Địa chỉ PC: 0x0609a8 | Địa chỉ FDE: 0x03ba18 | Kích thước: 236 bytes
//   0x0609a8: FC1E0FE8  str      d8, [sp, #-0x20]!
//   0x0609ac: F90007F3  str      x19, [sp, #8]
//   0x0609b0: A9017BFD  stp      x29, x30, [sp, #0x10]
//   0x0609b4: 910043FD  add      x29, sp, #0x10
static inline uint64_t fde_func_0072_0x0609a8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0609a8ULL ^ (static_cast<uint64_t>(0xfc1e0fe8ULL) << 13);
    acc = (acc + a1 + 0xf90007f3ULL) ^ 0x03ba18ULL;
    acc ^= (acc >> 17) * 0x00ecULL;
    return acc;
}

// FDE #0073 | PC: 0x060a94 | FDE: 0x03ba40 | Size: 8 bytes
// Khung tháo gỡ #0073 | Địa chỉ PC: 0x060a94 | Địa chỉ FDE: 0x03ba40 | Kích thước: 8 bytes
//   0x060a94: 1E60C000  fabs     d0, d0
//   0x060a98: D65F03C0  ret      
static inline uint64_t fde_func_0073_0x060a94(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x060a94ULL ^ (static_cast<uint64_t>(0x1e60c000ULL) << 13);
    acc = (acc + a1 + 0xd65f03c0ULL) ^ 0x03ba40ULL;
    acc ^= (acc >> 17) * 0x0008ULL;
    return acc;
}

// FDE #0074 | PC: 0x060a9c | FDE: 0x03ba58 | Size: 8 bytes
// Khung tháo gỡ #0074 | Địa chỉ PC: 0x060a9c | Địa chỉ FDE: 0x03ba58 | Kích thước: 8 bytes
//   0x060a9c: 1E64C000  frintp   d0, d0
//   0x060aa0: D65F03C0  ret      
static inline uint64_t fde_func_0074_0x060a9c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x060a9cULL ^ (static_cast<uint64_t>(0x1e64c000ULL) << 13);
    acc = (acc + a1 + 0xd65f03c0ULL) ^ 0x03ba58ULL;
    acc ^= (acc >> 17) * 0x0008ULL;
    return acc;
}

// FDE #0075 | PC: 0x060aa4 | FDE: 0x03ba70 | Size: 8 bytes
// Khung tháo gỡ #0075 | Địa chỉ PC: 0x060aa4 | Địa chỉ FDE: 0x03ba70 | Kích thước: 8 bytes
//   0x060aa4: 1E654000  frintm   d0, d0
//   0x060aa8: D65F03C0  ret      
static inline uint64_t fde_func_0075_0x060aa4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x060aa4ULL ^ (static_cast<uint64_t>(0x1e654000ULL) << 13);
    acc = (acc + a1 + 0xd65f03c0ULL) ^ 0x03ba70ULL;
    acc ^= (acc >> 17) * 0x0008ULL;
    return acc;
}

// FDE #0076 | PC: 0x060aac | FDE: 0x03ba88 | Size: 20 bytes
// Khung tháo gỡ #0076 | Địa chỉ PC: 0x060aac | Địa chỉ FDE: 0x03ba88 | Kích thước: 20 bytes
//   0x060aac: 1E65C000  frintz   d0, d0
//   0x060ab0: D65F03C0  ret      
//   0x060ab4: 00000000  udf      #0
//   0x060ab8: 00000000  udf      #0
static inline uint64_t fde_func_0076_0x060aac(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x060aacULL ^ (static_cast<uint64_t>(0x1e65c000ULL) << 13);
    acc = (acc + a1 + 0xd65f03c0ULL) ^ 0x03ba88ULL;
    acc ^= (acc >> 17) * 0x0014ULL;
    return acc;
}

// FDE #0077 | PC: 0x060ac0 | FDE: 0x03baa0 | Size: 16 bytes
// Khung tháo gỡ #0077 | Địa chỉ PC: 0x060ac0 | Địa chỉ FDE: 0x03baa0 | Kích thước: 16 bytes
//   0x060ac0: 1E61C000  fsqrt    d0, d0
//   0x060ac4: D65F03C0  ret      
//   0x060ac8: D503201F  nop      
//   0x060acc: D503201F  nop      
static inline uint64_t fde_func_0077_0x060ac0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x060ac0ULL ^ (static_cast<uint64_t>(0x1e61c000ULL) << 13);
    acc = (acc + a1 + 0xd65f03c0ULL) ^ 0x03baa0ULL;
    acc ^= (acc >> 17) * 0x0010ULL;
    return acc;
}

// FDE #0078 | PC: 0x060ad0 | FDE: 0x03bab8 | Size: 8 bytes
// Khung tháo gỡ #0078 | Địa chỉ PC: 0x060ad0 | Địa chỉ FDE: 0x03bab8 | Kích thước: 8 bytes
//   0x060ad0: 1E21C000  fsqrt    s0, s0
//   0x060ad4: D65F03C0  ret      
static inline uint64_t fde_func_0078_0x060ad0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x060ad0ULL ^ (static_cast<uint64_t>(0x1e21c000ULL) << 13);
    acc = (acc + a1 + 0xd65f03c0ULL) ^ 0x03bab8ULL;
    acc ^= (acc >> 17) * 0x0008ULL;
    return acc;
}

// FDE #0079 | PC: 0x060ad8 | FDE: 0x04b098 | Size: 256 bytes
// Khung tháo gỡ #0079 | Địa chỉ PC: 0x060ad8 | Địa chỉ FDE: 0x04b098 | Kích thước: 256 bytes
//   0x060ad8: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x060adc: 9E660000  fmov     x0, d0
//   0x060ae0: 9EAE0001  fmov     x1, v0.d[1]
//   0x060ae4: 910003FD  mov      x29, sp
static inline uint64_t fde_func_0079_0x060ad8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x060ad8ULL ^ (static_cast<uint64_t>(0xa9be7bfdULL) << 13);
    acc = (acc + a1 + 0x9e660000ULL) ^ 0x04b098ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0080 | PC: 0x0615c4 | FDE: 0x04b0c0 | Size: 108 bytes
// Khung tháo gỡ #0080 | Địa chỉ PC: 0x0615c4 | Địa chỉ FDE: 0x04b0c0 | Kích thước: 108 bytes
//   0x0615c4: 36000080  tbz      w0, #0, #0x615d4
//   0x0615c8: 1E2703E1  fmov     s1, wzr
//   0x0615cc: 1E211820  fdiv     s0, s1, s1
//   0x0615d0: D53B4421  mrs      x1, fpsr
static inline uint64_t fde_func_0080_0x0615c4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0615c4ULL ^ (static_cast<uint64_t>(0x36000080ULL) << 13);
    acc = (acc + a1 + 0x1e2703e1ULL) ^ 0x04b0c0ULL;
    acc ^= (acc >> 17) * 0x006cULL;
    return acc;
}

// FDE #0081 | PC: 0x061630 | FDE: 0x04b0d8 | Size: 256 bytes
// Khung tháo gỡ #0081 | Địa chỉ PC: 0x061630 | Địa chỉ FDE: 0x04b0d8 | Kích thước: 256 bytes
//   0x061630: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x061634: 9E660000  fmov     x0, d0
//   0x061638: 9EAE0001  fmov     x1, v0.d[1]
//   0x06163c: 910003FD  mov      x29, sp
static inline uint64_t fde_func_0081_0x061630(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x061630ULL ^ (static_cast<uint64_t>(0xa9be7bfdULL) << 13);
    acc = (acc + a1 + 0x9e660000ULL) ^ 0x04b0d8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0082 | PC: 0x062144 | FDE: 0x04b100 | Size: 248 bytes
// Khung tháo gỡ #0082 | Địa chỉ PC: 0x062144 | Địa chỉ FDE: 0x04b100 | Kích thước: 248 bytes
//   0x062144: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x062148: 9E660004  fmov     x4, d0
//   0x06214c: 910003FD  mov      x29, sp
//   0x062150: D53B4400  mrs      x0, fpcr
static inline uint64_t fde_func_0082_0x062144(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x062144ULL ^ (static_cast<uint64_t>(0xa9be7bfdULL) << 13);
    acc = (acc + a1 + 0x9e660004ULL) ^ 0x04b100ULL;
    acc ^= (acc >> 17) * 0x00f8ULL;
    return acc;
}

// FDE #0083 | PC: 0x06223c | FDE: 0x04b128 | Size: 256 bytes
// Khung tháo gỡ #0083 | Địa chỉ PC: 0x06223c | Địa chỉ FDE: 0x04b128 | Kích thước: 256 bytes
//   0x06223c: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x062240: 9E660000  fmov     x0, d0
//   0x062244: 910003FD  mov      x29, sp
//   0x062248: 9EAE0001  fmov     x1, v0.d[1]
static inline uint64_t fde_func_0083_0x06223c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x06223cULL ^ (static_cast<uint64_t>(0xa9be7bfdULL) << 13);
    acc = (acc + a1 + 0x9e660000ULL) ^ 0x04b128ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0084 | PC: 0x0624f8 | FDE: 0x04b150 | Size: 64 bytes
// Khung tháo gỡ #0084 | Địa chỉ PC: 0x0624f8 | Địa chỉ FDE: 0x04b150 | Kích thước: 64 bytes
//   0x0624f8: A9BE7BFD  stp      x29, x30, [sp, #-0x20]!
//   0x0624fc: 90000001  adrp     x1, #0x62000
//   0x062500: 910003FD  mov      x29, sp
//   0x062504: F9000BF3  str      x19, [sp, #0x10]
static inline uint64_t fde_func_0084_0x0624f8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0624f8ULL ^ (static_cast<uint64_t>(0xa9be7bfdULL) << 13);
    acc = (acc + a1 + 0x90000001ULL) ^ 0x04b150ULL;
    acc ^= (acc >> 17) * 0x0040ULL;
    return acc;
}

// FDE #0085 | PC: 0x062538 | FDE: 0x04b178 | Size: 128 bytes
// Khung tháo gỡ #0085 | Địa chỉ PC: 0x062538 | Địa chỉ FDE: 0x04b178 | Kích thước: 128 bytes
//   0x062538: A9BD7BFD  stp      x29, x30, [sp, #-0x30]!
//   0x06253c: AA0003E1  mov      x1, x0
//   0x062540: 910003FD  mov      x29, sp
//   0x062544: F9400000  ldr      x0, [x0]
static inline uint64_t fde_func_0085_0x062538(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x062538ULL ^ (static_cast<uint64_t>(0xa9bd7bfdULL) << 13);
    acc = (acc + a1 + 0xaa0003e1ULL) ^ 0x04b178ULL;
    acc ^= (acc >> 17) * 0x0080ULL;
    return acc;
}

// FDE #0086 | PC: 0x0625b8 | FDE: 0x04b1b8 | Size: 152 bytes
// Khung tháo gỡ #0086 | Địa chỉ PC: 0x0625b8 | Địa chỉ FDE: 0x04b1b8 | Kích thước: 152 bytes
//   0x0625b8: A9BD7BFD  stp      x29, x30, [sp, #-0x30]!
//   0x0625bc: 910003FD  mov      x29, sp
//   0x0625c0: A90153F3  stp      x19, x20, [sp, #0x10]
//   0x0625c4: F9400414  ldr      x20, [x0, #8]
static inline uint64_t fde_func_0086_0x0625b8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0625b8ULL ^ (static_cast<uint64_t>(0xa9bd7bfdULL) << 13);
    acc = (acc + a1 + 0x910003fdULL) ^ 0x04b1b8ULL;
    acc ^= (acc >> 17) * 0x0098ULL;
    return acc;
}

// FDE #0087 | PC: 0x062650 | FDE: 0x04b1e8 | Size: 32 bytes
// Khung tháo gỡ #0087 | Địa chỉ PC: 0x062650 | Địa chỉ FDE: 0x04b1e8 | Kích thước: 32 bytes
//   0x062650: D0000AE0  adrp     x0, #0x1c0000
//   0x062654: 9101E001  add      x1, x0, #0x78
//   0x062658: B9400422  ldr      w2, [x1, #4]
//   0x06265c: 34000082  cbz      w2, #0x6266c
static inline uint64_t fde_func_0087_0x062650(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x062650ULL ^ (static_cast<uint64_t>(0xd0000ae0ULL) << 13);
    acc = (acc + a1 + 0x9101e001ULL) ^ 0x04b1e8ULL;
    acc ^= (acc >> 17) * 0x0020ULL;
    return acc;
}

// FDE #0088 | PC: 0x062670 | FDE: 0x04b200 | Size: 256 bytes [__emutls_get_address]
// Khung tháo gỡ #0088 | Địa chỉ PC: 0x062670 | Địa chỉ FDE: 0x04b200 | Kích thước: 256 bytes
//   0x062670: F0000AC1  adrp     x1, #0x1bd000
//   0x062674: A9BC7BFD  stp      x29, x30, [sp, #-0x40]!
//   0x062678: 910003FD  mov      x29, sp
//   0x06267c: F940C421  ldr      x1, [x1, #0x188]
static inline uint64_t fde_func_0088_0x062670(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x062670ULL ^ (static_cast<uint64_t>(0xf0000ac1ULL) << 13);
    acc = (acc + a1 + 0xa9bc7bfdULL) ^ 0x04b200ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0089 | PC: 0x0627c8 | FDE: 0x04b238 | Size: 60 bytes [__emutls_register_common]
// Khung tháo gỡ #0089 | Địa chỉ PC: 0x0627c8 | Địa chỉ FDE: 0x04b238 | Kích thước: 60 bytes
//   0x0627c8: F9400004  ldr      x4, [x0]
//   0x0627cc: EB01009F  cmp      x4, x1
//   0x0627d0: 54000062  b.hs     #0x627dc
//   0x0627d4: F9000001  str      x1, [x0]
static inline uint64_t fde_func_0089_0x0627c8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0627c8ULL ^ (static_cast<uint64_t>(0xf9400004ULL) << 13);
    acc = (acc + a1 + 0xeb01009fULL) ^ 0x04b238ULL;
    acc ^= (acc >> 17) * 0x003cULL;
    return acc;
}

// FDE #0090 | PC: 0x062804 | FDE: 0x04b250 | Size: 256 bytes [__udivti3]
// Khung tháo gỡ #0090 | Địa chỉ PC: 0x062804 | Địa chỉ FDE: 0x04b250 | Kích thước: 256 bytes
//   0x062804: AA0203E4  mov      x4, x2
//   0x062808: AA0303E6  mov      x6, x3
//   0x06280c: AA0003E7  mov      x7, x0
//   0x062810: AA0103E5  mov      x5, x1
static inline uint64_t fde_func_0090_0x062804(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x062804ULL ^ (static_cast<uint64_t>(0xaa0203e4ULL) << 13);
    acc = (acc + a1 + 0xaa0303e6ULL) ^ 0x04b250ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0091 | PC: 0x062c24 | FDE: 0x03bad0 | Size: 16 bytes [_ZN6primjs7general7logging17GetMinAllLogLevelEv]
// Khung tháo gỡ #0091 | Địa chỉ PC: 0x062c24 | Địa chỉ FDE: 0x03bad0 | Kích thước: 16 bytes
//   0x062c24: D0000AE8  adrp     x8, #0x1c0000
//   0x062c28: B940B908  ldr      w8, [x8, #0xb8]
//   0x062c2c: 0A887D00  and      w0, w8, w8, asr #31
//   0x062c30: D65F03C0  ret      
static inline uint64_t fde_func_0091_0x062c24(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x062c24ULL ^ (static_cast<uint64_t>(0xd0000ae8ULL) << 13);
    acc = (acc + a1 + 0xb940b908ULL) ^ 0x03bad0ULL;
    acc ^= (acc >> 17) * 0x0010ULL;
    return acc;
}

// FDE #0092 | PC: 0x062c34 | FDE: 0x03bae8 | Size: 200 bytes [_ZN6primjs7general7logging10LogMessageC1EPKcii]
// Khung tháo gỡ #0092 | Địa chỉ PC: 0x062c34 | Địa chỉ FDE: 0x03bae8 | Kích thước: 200 bytes
//   0x062c34: A9BD5BF7  stp      x23, x22, [sp, #-0x30]!
//   0x062c38: A90153F5  stp      x21, x20, [sp, #0x10]
//   0x062c3c: A9027BF3  stp      x19, x30, [sp, #0x20]
//   0x062c40: D0000A88  adrp     x8, #0x1b4000
static inline uint64_t fde_func_0092_0x062c34(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x062c34ULL ^ (static_cast<uint64_t>(0xa9bd5bf7ULL) << 13);
    acc = (acc + a1 + 0xa90153f5ULL) ^ 0x03bae8ULL;
    acc ^= (acc >> 17) * 0x00c8ULL;
    return acc;
}

// FDE #0093 | PC: 0x062cfc | FDE: 0x03bb08 | Size: 256 bytes [_ZN6primjs7general7logging10LogMessage4InitEPKci]
// Khung tháo gỡ #0093 | Địa chỉ PC: 0x062cfc | Địa chỉ FDE: 0x03bb08 | Kích thước: 256 bytes
//   0x062cfc: D10303FF  sub      sp, sp, #0xc0
//   0x062d00: F9003BFA  str      x26, [sp, #0x70]
//   0x062d04: A90863F9  stp      x25, x24, [sp, #0x80]
//   0x062d08: A9095BF7  stp      x23, x22, [sp, #0x90]
static inline uint64_t fde_func_0093_0x062cfc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x062cfcULL ^ (static_cast<uint64_t>(0xd10303ffULL) << 13);
    acc = (acc + a1 + 0xf9003bfaULL) ^ 0x03bb08ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0094 | PC: 0x063048 | FDE: 0x03bb30 | Size: 180 bytes [_ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEC2ERKS5_mmRKS4_]
// Khung tháo gỡ #0094 | Địa chỉ PC: 0x063048 | Địa chỉ FDE: 0x03bb30 | Kích thước: 180 bytes
//   0x063048: A9BD5BF7  stp      x23, x22, [sp, #-0x30]!
//   0x06304c: A90153F5  stp      x21, x20, [sp, #0x10]
//   0x063050: A9027BF3  stp      x19, x30, [sp, #0x20]
//   0x063054: A9007C1F  stp      xzr, xzr, [x0]
static inline uint64_t fde_func_0094_0x063048(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x063048ULL ^ (static_cast<uint64_t>(0xa9bd5bf7ULL) << 13);
    acc = (acc + a1 + 0xa90153f5ULL) ^ 0x03bb30ULL;
    acc ^= (acc >> 17) * 0x00b4ULL;
    return acc;
}

// FDE #0095 | PC: 0x0630fc | FDE: 0x03bb50 | Size: 256 bytes
// Khung tháo gỡ #0095 | Địa chỉ PC: 0x0630fc | Địa chỉ FDE: 0x03bb50 | Kích thước: 256 bytes
//   0x0630fc: D10203FF  sub      sp, sp, #0x80
//   0x063100: F90013FC  str      x28, [sp, #0x20]
//   0x063104: A9036BFB  stp      x27, x26, [sp, #0x30]
//   0x063108: A90463F9  stp      x25, x24, [sp, #0x40]
static inline uint64_t fde_func_0095_0x0630fc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0630fcULL ^ (static_cast<uint64_t>(0xd10203ffULL) << 13);
    acc = (acc + a1 + 0xf90013fcULL) ^ 0x03bb50ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0096 | PC: 0x0633a0 | FDE: 0x03bb80 | Size: 256 bytes [_ZNSt6__ndk113basic_ostreamIcNS_11char_traitsIcEEElsEi]
// Khung tháo gỡ #0096 | Địa chỉ PC: 0x0633a0 | Địa chỉ FDE: 0x03bb80 | Kích thước: 256 bytes
//   0x0633a0: D10183FF  sub      sp, sp, #0x60
//   0x0633a4: F9000BFA  str      x26, [sp, #0x10]
//   0x0633a8: A90263F9  stp      x25, x24, [sp, #0x20]
//   0x0633ac: A9035BF7  stp      x23, x22, [sp, #0x30]
static inline uint64_t fde_func_0096_0x0633a0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0633a0ULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xf9000bfaULL) ^ 0x03bb80ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0097 | PC: 0x063570 | FDE: 0x03bba8 | Size: 228 bytes [_ZNSt6__ndk113basic_ostreamIcNS_11char_traitsIcEEE5flushEv]
// Khung tháo gỡ #0097 | Địa chỉ PC: 0x063570 | Địa chỉ FDE: 0x03bba8 | Kích thước: 228 bytes
//   0x063570: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x063574: F9400008  ldr      x8, [x0]
//   0x063578: AA0003F3  mov      x19, x0
//   0x06357c: F85E8108  ldur     x8, [x8, #-0x18]
static inline uint64_t fde_func_0097_0x063570(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x063570ULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0xf9400008ULL) ^ 0x03bba8ULL;
    acc ^= (acc >> 17) * 0x00e4ULL;
    return acc;
}

// FDE #0098 | PC: 0x063654 | FDE: 0x03bbc0 | Size: 64 bytes
// Khung tháo gỡ #0098 | Địa chỉ PC: 0x063654 | Địa chỉ FDE: 0x03bbc0 | Kích thước: 64 bytes
//   0x063654: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x063658: 39410008  ldrb     w8, [x0, #0x40]
//   0x06365c: B0000A89  adrp     x9, #0x1b4000
//   0x063660: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_0098_0x063654(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x063654ULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0x39410008ULL) ^ 0x03bbc0ULL;
    acc ^= (acc >> 17) * 0x0040ULL;
    return acc;
}

// FDE #0099 | PC: 0x063694 | FDE: 0x03bbd8 | Size: 72 bytes
// Khung tháo gỡ #0099 | Địa chỉ PC: 0x063694 | Địa chỉ FDE: 0x03bbd8 | Kích thước: 72 bytes
//   0x063694: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x063698: 39410008  ldrb     w8, [x0, #0x40]
//   0x06369c: B0000A89  adrp     x9, #0x1b4000
//   0x0636a0: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_0099_0x063694(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x063694ULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0x39410008ULL) ^ 0x03bbd8ULL;
    acc ^= (acc >> 17) * 0x0048ULL;
    return acc;
}

// FDE #0100 | PC: 0x0636dc | FDE: 0x03bbf0 | Size: 4 bytes [_Z19WriteBarrierNoStoreP12LEPUSContext10LEPUSValue]
// Khung tháo gỡ #0100 | Địa chỉ PC: 0x0636dc | Địa chỉ FDE: 0x03bbf0 | Kích thước: 4 bytes
//   0x0636dc: D65F03C0  ret      
static inline uint64_t fde_func_0100_0x0636dc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0636dcULL ^ (static_cast<uint64_t>(0xd65f03c0ULL) << 13);
    acc = (acc + a1 + 0xf9402c08ULL) ^ 0x03bbf0ULL;
    acc ^= (acc >> 17) * 0x0004ULL;
    return acc;
}

// FDE #0101 | PC: 0x0636e0 | FDE: 0x03bc08 | Size: 256 bytes
// Khung tháo gỡ #0101 | Địa chỉ PC: 0x0636e0 | Địa chỉ FDE: 0x03bc08 | Kích thước: 256 bytes
//   0x0636e0: F9402C08  ldr      x8, [x0, #0x58]
//   0x0636e4: F9401809  ldr      x9, [x0, #0x30]
//   0x0636e8: EB09011F  cmp      x8, x9
//   0x0636ec: 54000062  b.hs     #0x636f8
static inline uint64_t fde_func_0101_0x0636e0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0636e0ULL ^ (static_cast<uint64_t>(0xf9402c08ULL) << 13);
    acc = (acc + a1 + 0xf9401809ULL) ^ 0x03bc08ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0102 | PC: 0x0637e0 | FDE: 0x03bc20 | Size: 20 bytes
// Khung tháo gỡ #0102 | Địa chỉ PC: 0x0637e0 | Địa chỉ FDE: 0x03bc20 | Kích thước: 20 bytes
//   0x0637e0: F9400008  ldr      x8, [x0]
//   0x0637e4: AA0203E1  mov      x1, x2
//   0x0637e8: 2A1F03E2  mov      w2, wzr
//   0x0637ec: F9401104  ldr      x4, [x8, #0x20]
static inline uint64_t fde_func_0102_0x0637e0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0637e0ULL ^ (static_cast<uint64_t>(0xf9400008ULL) << 13);
    acc = (acc + a1 + 0xaa0203e1ULL) ^ 0x03bc20ULL;
    acc ^= (acc >> 17) * 0x0014ULL;
    return acc;
}

// FDE #0103 | PC: 0x0637f4 | FDE: 0x03bc38 | Size: 8 bytes [_ZNSt6__ndk115basic_streambufIcNS_11char_traitsIcEEE4syncEv]
// Khung tháo gỡ #0103 | Địa chỉ PC: 0x0637f4 | Địa chỉ FDE: 0x03bc38 | Kích thước: 8 bytes
//   0x0637f4: 2A1F03E0  mov      w0, wzr
//   0x0637f8: D65F03C0  ret      
static inline uint64_t fde_func_0103_0x0637f4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0637f4ULL ^ (static_cast<uint64_t>(0x2a1f03e0ULL) << 13);
    acc = (acc + a1 + 0xd65f03c0ULL) ^ 0x03bc38ULL;
    acc ^= (acc >> 17) * 0x0008ULL;
    return acc;
}

// FDE #0104 | PC: 0x0637fc | FDE: 0x03bc50 | Size: 8 bytes [_ZNSt6__ndk115basic_streambufIcNS_11char_traitsIcEEE9showmanycEv]
// Khung tháo gỡ #0104 | Địa chỉ PC: 0x0637fc | Địa chỉ FDE: 0x03bc50 | Kích thước: 8 bytes
//   0x0637fc: AA1F03E0  mov      x0, xzr
//   0x063800: D65F03C0  ret      
static inline uint64_t fde_func_0104_0x0637fc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0637fcULL ^ (static_cast<uint64_t>(0xaa1f03e0ULL) << 13);
    acc = (acc + a1 + 0xd65f03c0ULL) ^ 0x03bc50ULL;
    acc ^= (acc >> 17) * 0x0008ULL;
    return acc;
}

// FDE #0105 | PC: 0x063804 | FDE: 0x03bc68 | Size: 196 bytes [_ZNSt6__ndk115basic_streambufIcNS_11char_traitsIcEEE6xsgetnEPcl]
// Khung tháo gỡ #0105 | Địa chỉ PC: 0x063804 | Địa chỉ FDE: 0x03bc68 | Kích thước: 196 bytes
//   0x063804: F81C0FF8  str      x24, [sp, #-0x40]!
//   0x063808: A9015BF7  stp      x23, x22, [sp, #0x10]
//   0x06380c: A90253F5  stp      x21, x20, [sp, #0x20]
//   0x063810: A9037BF3  stp      x19, x30, [sp, #0x30]
static inline uint64_t fde_func_0105_0x063804(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x063804ULL ^ (static_cast<uint64_t>(0xf81c0ff8ULL) << 13);
    acc = (acc + a1 + 0xa9015bf7ULL) ^ 0x03bc68ULL;
    acc ^= (acc >> 17) * 0x00c4ULL;
    return acc;
}

// FDE #0106 | PC: 0x0638c8 | FDE: 0x03bc90 | Size: 80 bytes
// Khung tháo gỡ #0106 | Địa chỉ PC: 0x0638c8 | Địa chỉ FDE: 0x03bc90 | Kích thước: 80 bytes
//   0x0638c8: F9402C08  ldr      x8, [x0, #0x58]
//   0x0638cc: F9401809  ldr      x9, [x0, #0x30]
//   0x0638d0: EB09011F  cmp      x8, x9
//   0x0638d4: 54000062  b.hs     #0x638e0
static inline uint64_t fde_func_0106_0x0638c8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0638c8ULL ^ (static_cast<uint64_t>(0xf9402c08ULL) << 13);
    acc = (acc + a1 + 0xf9401809ULL) ^ 0x03bc90ULL;
    acc ^= (acc >> 17) * 0x0050ULL;
    return acc;
}

// FDE #0107 | PC: 0x063918 | FDE: 0x03bca8 | Size: 52 bytes [_ZNSt6__ndk115basic_streambufIcNS_11char_traitsIcEEE5uflowEv]
// Khung tháo gỡ #0107 | Địa chỉ PC: 0x063918 | Địa chỉ FDE: 0x03bca8 | Kích thước: 52 bytes
//   0x063918: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x06391c: F9400008  ldr      x8, [x0]
//   0x063920: AA0003F3  mov      x19, x0
//   0x063924: F9402508  ldr      x8, [x8, #0x48]
static inline uint64_t fde_func_0107_0x063918(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x063918ULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0xf9400008ULL) ^ 0x03bca8ULL;
    acc ^= (acc >> 17) * 0x0034ULL;
    return acc;
}

// FDE #0108 | PC: 0x06394c | FDE: 0x03bcc0 | Size: 112 bytes
// Khung tháo gỡ #0108 | Địa chỉ PC: 0x06394c | Địa chỉ FDE: 0x03bcc0 | Kích thước: 112 bytes
//   0x06394c: F9402C09  ldr      x9, [x0, #0x58]
//   0x063950: F940180A  ldr      x10, [x0, #0x30]
//   0x063954: AA0003E8  mov      x8, x0
//   0x063958: 2A0103E0  mov      w0, w1
static inline uint64_t fde_func_0108_0x06394c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x06394cULL ^ (static_cast<uint64_t>(0xf9402c09ULL) << 13);
    acc = (acc + a1 + 0xf940180aULL) ^ 0x03bcc0ULL;
    acc ^= (acc >> 17) * 0x0070ULL;
    return acc;
}

// FDE #0109 | PC: 0x0639bc | FDE: 0x03bcd8 | Size: 188 bytes [_ZNSt6__ndk115basic_streambufIcNS_11char_traitsIcEEE6xsputnEPKcl]
// Khung tháo gỡ #0109 | Địa chỉ PC: 0x0639bc | Địa chỉ FDE: 0x03bcd8 | Kích thước: 188 bytes
//   0x0639bc: A9BD5BF7  stp      x23, x22, [sp, #-0x30]!
//   0x0639c0: A90153F5  stp      x21, x20, [sp, #0x10]
//   0x0639c4: A9027BF3  stp      x19, x30, [sp, #0x20]
//   0x0639c8: F100045F  cmp      x2, #1
static inline uint64_t fde_func_0109_0x0639bc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0639bcULL ^ (static_cast<uint64_t>(0xa9bd5bf7ULL) << 13);
    acc = (acc + a1 + 0xa90153f5ULL) ^ 0x03bcd8ULL;
    acc ^= (acc >> 17) * 0x00bcULL;
    return acc;
}

// FDE #0110 | PC: 0x063a78 | FDE: 0x03bcf8 | Size: 256 bytes
// Khung tháo gỡ #0110 | Địa chỉ PC: 0x063a78 | Địa chỉ FDE: 0x03bcf8 | Kích thước: 256 bytes
//   0x063a78: D10183FF  sub      sp, sp, #0x60
//   0x063a7c: A9016BFB  stp      x27, x26, [sp, #0x10]
//   0x063a80: A90263F9  stp      x25, x24, [sp, #0x20]
//   0x063a84: A9035BF7  stp      x23, x22, [sp, #0x30]
static inline uint64_t fde_func_0110_0x063a78(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x063a78ULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xa9016bfbULL) ^ 0x03bcf8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0111 | PC: 0x063c98 | FDE: 0x03bd20 | Size: 256 bytes [_ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE9__grow_byEmmmmmm]
// Khung tháo gỡ #0111 | Địa chỉ PC: 0x063c98 | Địa chỉ FDE: 0x03bd20 | Kích thước: 256 bytes
//   0x063c98: A9BB6BFB  stp      x27, x26, [sp, #-0x50]!
//   0x063c9c: A90163F9  stp      x25, x24, [sp, #0x10]
//   0x063ca0: A9025BF7  stp      x23, x22, [sp, #0x20]
//   0x063ca4: A90353F5  stp      x21, x20, [sp, #0x30]
static inline uint64_t fde_func_0111_0x063c98(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x063c98ULL ^ (static_cast<uint64_t>(0xa9bb6bfbULL) << 13);
    acc = (acc + a1 + 0xa90163f9ULL) ^ 0x03bd20ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0112 | PC: 0x063da0 | FDE: 0x03bd48 | Size: 192 bytes [_ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE6appendEmc]
// Khung tháo gỡ #0112 | Địa chỉ PC: 0x063da0 | Địa chỉ FDE: 0x03bd48 | Kích thước: 192 bytes
//   0x063da0: A9BD5BF7  stp      x23, x22, [sp, #-0x30]!
//   0x063da4: A90153F5  stp      x21, x20, [sp, #0x10]
//   0x063da8: A9027BF3  stp      x19, x30, [sp, #0x20]
//   0x063dac: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_0112_0x063da0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x063da0ULL ^ (static_cast<uint64_t>(0xa9bd5bf7ULL) << 13);
    acc = (acc + a1 + 0xa90153f5ULL) ^ 0x03bd48ULL;
    acc ^= (acc >> 17) * 0x00c0ULL;
    return acc;
}

// FDE #0113 | PC: 0x063e60 | FDE: 0x03bd68 | Size: 20 bytes [_ZNSt6__ndk115basic_streambufIcNS_11char_traitsIcEEED2Ev]
// Khung tháo gỡ #0113 | Địa chỉ PC: 0x063e60 | Địa chỉ FDE: 0x03bd68 | Kích thước: 20 bytes
//   0x063e60: D0000AC8  adrp     x8, #0x1bd000
//   0x063e64: F940CD08  ldr      x8, [x8, #0x198]
//   0x063e68: 91004108  add      x8, x8, #0x10
//   0x063e6c: F8008408  str      x8, [x0], #8
static inline uint64_t fde_func_0113_0x063e60(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x063e60ULL ^ (static_cast<uint64_t>(0xd0000ac8ULL) << 13);
    acc = (acc + a1 + 0xf940cd08ULL) ^ 0x03bd68ULL;
    acc ^= (acc >> 17) * 0x0014ULL;
    return acc;
}

// FDE #0114 | PC: 0x063e74 | FDE: 0x03bd80 | Size: 40 bytes [_ZNSt6__ndk115basic_streambufIcNS_11char_traitsIcEEED0Ev]
// Khung tháo gỡ #0114 | Địa chỉ PC: 0x063e74 | Địa chỉ FDE: 0x03bd80 | Kích thước: 40 bytes
//   0x063e74: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x063e78: D0000AC8  adrp     x8, #0x1bd000
//   0x063e7c: F940CD08  ldr      x8, [x8, #0x198]
//   0x063e80: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_0114_0x063e74(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x063e74ULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0xd0000ac8ULL) ^ 0x03bd80ULL;
    acc ^= (acc >> 17) * 0x0028ULL;
    return acc;
}

// FDE #0115 | PC: 0x063e9c | FDE: 0x03bd98 | Size: 12 bytes [_ZNSt6__ndk115basic_streambufIcNS_11char_traitsIcEEE7seekoffExNS_8ios_base7seekdirEj]
// Khung tháo gỡ #0115 | Địa chỉ PC: 0x063e9c | Địa chỉ FDE: 0x03bd98 | Kích thước: 12 bytes
//   0x063e9c: 92800001  mov      x1, #-1
//   0x063ea0: AA1F03E0  mov      x0, xzr
//   0x063ea4: D65F03C0  ret      
static inline uint64_t fde_func_0115_0x063e9c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x063e9cULL ^ (static_cast<uint64_t>(0x92800001ULL) << 13);
    acc = (acc + a1 + 0xaa1f03e0ULL) ^ 0x03bd98ULL;
    acc ^= (acc >> 17) * 0x000cULL;
    return acc;
}

// FDE #0116 | PC: 0x063ea8 | FDE: 0x03bdb0 | Size: 8 bytes [_ZNSt6__ndk115basic_streambufIcNS_11char_traitsIcEEE9underflowEv]
// Khung tháo gỡ #0116 | Địa chỉ PC: 0x063ea8 | Địa chỉ FDE: 0x03bdb0 | Kích thước: 8 bytes
//   0x063ea8: 12800000  mov      w0, #-1
//   0x063eac: D65F03C0  ret      
static inline uint64_t fde_func_0116_0x063ea8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x063ea8ULL ^ (static_cast<uint64_t>(0x12800000ULL) << 13);
    acc = (acc + a1 + 0xd65f03c0ULL) ^ 0x03bdb0ULL;
    acc ^= (acc >> 17) * 0x0008ULL;
    return acc;
}

// FDE #0117 | PC: 0x063eb0 | FDE: 0x03bdc8 | Size: 88 bytes
// Khung tháo gỡ #0117 | Địa chỉ PC: 0x063eb0 | Địa chỉ FDE: 0x03bdc8 | Kích thước: 88 bytes
//   0x063eb0: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x063eb4: B0000A88  adrp     x8, #0x1b4000
//   0x063eb8: 9101C108  add      x8, x8, #0x70
//   0x063ebc: 39412009  ldrb     w9, [x0, #0x48]
static inline uint64_t fde_func_0117_0x063eb0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x063eb0ULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0xb0000a88ULL) ^ 0x03bdc8ULL;
    acc ^= (acc >> 17) * 0x0058ULL;
    return acc;
}

// FDE #0118 | PC: 0x063f08 | FDE: 0x03bde0 | Size: 96 bytes
// Khung tháo gỡ #0118 | Địa chỉ PC: 0x063f08 | Địa chỉ FDE: 0x03bde0 | Kích thước: 96 bytes
//   0x063f08: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x063f0c: B0000A88  adrp     x8, #0x1b4000
//   0x063f10: 9101C108  add      x8, x8, #0x70
//   0x063f14: 39412009  ldrb     w9, [x0, #0x48]
static inline uint64_t fde_func_0118_0x063f08(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x063f08ULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0xb0000a88ULL) ^ 0x03bde0ULL;
    acc ^= (acc >> 17) * 0x0060ULL;
    return acc;
}

// FDE #0119 | PC: 0x063f68 | FDE: 0x03bdf8 | Size: 112 bytes
// Khung tháo gỡ #0119 | Địa chỉ PC: 0x063f68 | Địa chỉ FDE: 0x03bdf8 | Kích thước: 112 bytes
//   0x063f68: F81E0FF4  str      x20, [sp, #-0x20]!
//   0x063f6c: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x063f70: F9400008  ldr      x8, [x0]
//   0x063f74: B0000A89  adrp     x9, #0x1b4000
static inline uint64_t fde_func_0119_0x063f68(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x063f68ULL ^ (static_cast<uint64_t>(0xf81e0ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x03bdf8ULL;
    acc ^= (acc >> 17) * 0x0070ULL;
    return acc;
}

// FDE #0120 | PC: 0x063fd8 | FDE: 0x03be18 | Size: 120 bytes
// Khung tháo gỡ #0120 | Địa chỉ PC: 0x063fd8 | Địa chỉ FDE: 0x03be18 | Kích thước: 120 bytes
//   0x063fd8: F81E0FF4  str      x20, [sp, #-0x20]!
//   0x063fdc: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x063fe0: F9400008  ldr      x8, [x0]
//   0x063fe4: B0000A89  adrp     x9, #0x1b4000
static inline uint64_t fde_func_0120_0x063fd8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x063fd8ULL ^ (static_cast<uint64_t>(0xf81e0ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x03be18ULL;
    acc ^= (acc >> 17) * 0x0078ULL;
    return acc;
}

// FDE #0121 | PC: 0x064050 | FDE: 0x03be38 | Size: 8 bytes [_ZNSt6__ndk113basic_ostreamIcNS_11char_traitsIcEEED1Ev]
// Khung tháo gỡ #0121 | Địa chỉ PC: 0x064050 | Địa chỉ FDE: 0x03be38 | Kích thước: 8 bytes
//   0x064050: 91002000  add      x0, x0, #8
//   0x064054: 140532A7  b        #0x1b0af0
static inline uint64_t fde_func_0121_0x064050(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x064050ULL ^ (static_cast<uint64_t>(0x91002000ULL) << 13);
    acc = (acc + a1 + 0x140532a7ULL) ^ 0x03be38ULL;
    acc ^= (acc >> 17) * 0x0008ULL;
    return acc;
}

// FDE #0122 | PC: 0x064058 | FDE: 0x03be50 | Size: 28 bytes [_ZNSt6__ndk113basic_ostreamIcNS_11char_traitsIcEEED0Ev]
// Khung tháo gỡ #0122 | Địa chỉ PC: 0x064058 | Địa chỉ FDE: 0x03be50 | Kích thước: 28 bytes
//   0x064058: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x06405c: AA0003F3  mov      x19, x0
//   0x064060: 91002000  add      x0, x0, #8
//   0x064064: 940532A3  bl       #0x1b0af0
static inline uint64_t fde_func_0122_0x064058(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x064058ULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0xaa0003f3ULL) ^ 0x03be50ULL;
    acc ^= (acc >> 17) * 0x001cULL;
    return acc;
}

// FDE #0123 | PC: 0x064074 | FDE: 0x03be68 | Size: 20 bytes [_ZTv0_n24_NSt6__ndk113basic_ostreamIcNS_11char_traitsIcEEED1Ev]
// Khung tháo gỡ #0123 | Địa chỉ PC: 0x064074 | Địa chỉ FDE: 0x03be68 | Kích thước: 20 bytes
//   0x064074: F9400008  ldr      x8, [x0]
//   0x064078: F85E8108  ldur     x8, [x8, #-0x18]
//   0x06407c: 8B080008  add      x8, x0, x8
//   0x064080: 91002100  add      x0, x8, #8
static inline uint64_t fde_func_0123_0x064074(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x064074ULL ^ (static_cast<uint64_t>(0xf9400008ULL) << 13);
    acc = (acc + a1 + 0xf85e8108ULL) ^ 0x03be68ULL;
    acc ^= (acc >> 17) * 0x0014ULL;
    return acc;
}

// FDE #0124 | PC: 0x064088 | FDE: 0x03be80 | Size: 36 bytes [_ZTv0_n24_NSt6__ndk113basic_ostreamIcNS_11char_traitsIcEEED0Ev]
// Khung tháo gỡ #0124 | Địa chỉ PC: 0x064088 | Địa chỉ FDE: 0x03be80 | Kích thước: 36 bytes
//   0x064088: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x06408c: F9400008  ldr      x8, [x0]
//   0x064090: F85E8108  ldur     x8, [x8, #-0x18]
//   0x064094: 8B080013  add      x19, x0, x8
static inline uint64_t fde_func_0124_0x064088(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x064088ULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0xf9400008ULL) ^ 0x03be80ULL;
    acc ^= (acc >> 17) * 0x0024ULL;
    return acc;
}

// FDE #0125 | PC: 0x0640ac | FDE: 0x03be98 | Size: 8 bytes [_ZN6primjs7general7logging10LogMessage6streamEv]
// Khung tháo gỡ #0125 | Địa chỉ PC: 0x0640ac | Địa chỉ FDE: 0x03be98 | Kích thước: 8 bytes
//   0x0640ac: 91002000  add      x0, x0, #8
//   0x0640b0: D65F03C0  ret      
static inline uint64_t fde_func_0125_0x0640ac(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0640acULL ^ (static_cast<uint64_t>(0x91002000ULL) << 13);
    acc = (acc + a1 + 0xd65f03c0ULL) ^ 0x03be98ULL;
    acc ^= (acc >> 17) * 0x0008ULL;
    return acc;
}

// FDE #0126 | PC: 0x0640b4 | FDE: 0x03beb0 | Size: 256 bytes [_ZN6primjs7general7logging10LogMessageD1Ev]
// Khung tháo gỡ #0126 | Địa chỉ PC: 0x0640b4 | Địa chỉ FDE: 0x03beb0 | Kích thước: 256 bytes
//   0x0640b4: D10103FF  sub      sp, sp, #0x40
//   0x0640b8: F9000BF6  str      x22, [sp, #0x10]
//   0x0640bc: A90253F5  stp      x21, x20, [sp, #0x20]
//   0x0640c0: A9037BF3  stp      x19, x30, [sp, #0x30]
static inline uint64_t fde_func_0126_0x0640b4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0640b4ULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xf9000bf6ULL) ^ 0x03beb0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0127 | PC: 0x0641b8 | FDE: 0x03bed0 | Size: 256 bytes [_ZNSt6__ndk113basic_ostreamIcNS_11char_traitsIcEEE3putEc]
// Khung tháo gỡ #0127 | Địa chỉ PC: 0x0641b8 | Địa chỉ FDE: 0x03bed0 | Kích thước: 256 bytes
//   0x0641b8: F81E0FF4  str      x20, [sp, #-0x20]!
//   0x0641bc: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x0641c0: F9400008  ldr      x8, [x0]
//   0x0641c4: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_0127_0x0641b8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0641b8ULL ^ (static_cast<uint64_t>(0xf81e0ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x03bed0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0128 | PC: 0x0642c0 | FDE: 0x03bef0 | Size: 144 bytes [_Z17js_allocate_abortP12malloc_stateP12malloc_chunk]
// Khung tháo gỡ #0128 | Địa chỉ PC: 0x0642c0 | Địa chỉ FDE: 0x03bef0 | Kích thước: 144 bytes
//   0x0642c0: D100C3FF  sub      sp, sp, #0x30
//   0x0642c4: F9000BF4  str      x20, [sp, #0x10]
//   0x0642c8: A9027BF3  stp      x19, x30, [sp, #0x20]
//   0x0642cc: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_0128_0x0642c0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0642c0ULL ^ (static_cast<uint64_t>(0xd100c3ffULL) << 13);
    acc = (acc + a1 + 0xf9000bf4ULL) ^ 0x03bef0ULL;
    acc ^= (acc >> 17) * 0x0090ULL;
    return acc;
}

// FDE #0129 | PC: 0x064350 | FDE: 0x03bf10 | Size: 184 bytes [_Z18insert_small_chunkP12malloc_stateP12malloc_chunkm]
// Khung tháo gỡ #0129 | Địa chỉ PC: 0x064350 | Địa chỉ FDE: 0x03bf10 | Kích thước: 184 bytes
//   0x064350: D10103FF  sub      sp, sp, #0x40
//   0x064354: F9000BF6  str      x22, [sp, #0x10]
//   0x064358: A90253F5  stp      x21, x20, [sp, #0x20]
//   0x06435c: A9037BF3  stp      x19, x30, [sp, #0x30]
static inline uint64_t fde_func_0129_0x064350(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x064350ULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xf9000bf6ULL) ^ 0x03bf10ULL;
    acc ^= (acc >> 17) * 0x00b8ULL;
    return acc;
}

// FDE #0130 | PC: 0x064408 | FDE: 0x03bf30 | Size: 188 bytes [_Z24local_insert_small_chunkP12malloc_stateP12malloc_chunkmi]
// Khung tháo gỡ #0130 | Địa chỉ PC: 0x064408 | Địa chỉ FDE: 0x03bf30 | Kích thước: 188 bytes
//   0x064408: D10103FF  sub      sp, sp, #0x40
//   0x06440c: F9000BF6  str      x22, [sp, #0x10]
//   0x064410: A90253F5  stp      x21, x20, [sp, #0x20]
//   0x064414: A9037BF3  stp      x19, x30, [sp, #0x30]
static inline uint64_t fde_func_0130_0x064408(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x064408ULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xf9000bf6ULL) ^ 0x03bf30ULL;
    acc ^= (acc >> 17) * 0x00bcULL;
    return acc;
}

// FDE #0131 | PC: 0x0644c4 | FDE: 0x03bf50 | Size: 256 bytes [_Z18unlink_small_chunkP12malloc_stateP12malloc_chunkm]
// Khung tháo gỡ #0131 | Địa chỉ PC: 0x0644c4 | Địa chỉ FDE: 0x03bf50 | Kích thước: 256 bytes
//   0x0644c4: D100C3FF  sub      sp, sp, #0x30
//   0x0644c8: F9000BF4  str      x20, [sp, #0x10]
//   0x0644cc: A9027BF3  stp      x19, x30, [sp, #0x20]
//   0x0644d0: F9404809  ldr      x9, [x0, #0x90]
static inline uint64_t fde_func_0131_0x0644c4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0644c4ULL ^ (static_cast<uint64_t>(0xd100c3ffULL) << 13);
    acc = (acc + a1 + 0xf9000bf4ULL) ^ 0x03bf50ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0132 | PC: 0x0645f8 | FDE: 0x03bf70 | Size: 212 bytes [_Z24unlink_first_small_chunkP12malloc_stateP12malloc_chunkS2_m]
// Khung tháo gỡ #0132 | Địa chỉ PC: 0x0645f8 | Địa chỉ FDE: 0x03bf70 | Kích thước: 212 bytes
//   0x0645f8: D100C3FF  sub      sp, sp, #0x30
//   0x0645fc: F9000BF4  str      x20, [sp, #0x10]
//   0x064600: A9027BF3  stp      x19, x30, [sp, #0x20]
//   0x064604: F9400844  ldr      x4, [x2, #0x10]
static inline uint64_t fde_func_0132_0x0645f8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0645f8ULL ^ (static_cast<uint64_t>(0xd100c3ffULL) << 13);
    acc = (acc + a1 + 0xf9000bf4ULL) ^ 0x03bf70ULL;
    acc ^= (acc >> 17) * 0x00d4ULL;
    return acc;
}

// FDE #0133 | PC: 0x0646cc | FDE: 0x03bf90 | Size: 216 bytes [_Z10replace_dvP12malloc_stateP12malloc_chunkm]
// Khung tháo gỡ #0133 | Địa chỉ PC: 0x0646cc | Địa chỉ FDE: 0x03bf90 | Kích thước: 216 bytes
//   0x0646cc: D10143FF  sub      sp, sp, #0x50
//   0x0646d0: F9000BF8  str      x24, [sp, #0x10]
//   0x0646d4: A9025BF7  stp      x23, x22, [sp, #0x20]
//   0x0646d8: A90353F5  stp      x21, x20, [sp, #0x30]
static inline uint64_t fde_func_0133_0x0646cc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0646ccULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xf9000bf8ULL) ^ 0x03bf90ULL;
    acc ^= (acc >> 17) * 0x00d8ULL;
    return acc;
}

// FDE #0134 | PC: 0x0647a4 | FDE: 0x03bfb8 | Size: 256 bytes [_Z18insert_large_chunkP12malloc_stateP17malloc_tree_chunkm]
// Khung tháo gỡ #0134 | Địa chỉ PC: 0x0647a4 | Địa chỉ FDE: 0x03bfb8 | Kích thước: 256 bytes
//   0x0647a4: D100C3FF  sub      sp, sp, #0x30
//   0x0647a8: F9000BF4  str      x20, [sp, #0x10]
//   0x0647ac: A9027BF3  stp      x19, x30, [sp, #0x20]
//   0x0647b0: D348FC48  lsr      x8, x2, #8
static inline uint64_t fde_func_0134_0x0647a4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0647a4ULL ^ (static_cast<uint64_t>(0xd100c3ffULL) << 13);
    acc = (acc + a1 + 0xf9000bf4ULL) ^ 0x03bfb8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0135 | PC: 0x064968 | FDE: 0x03bfd8 | Size: 256 bytes [_Z24local_insert_large_chunkP12malloc_stateP17malloc_tree_chunkmi]
// Khung tháo gỡ #0135 | Địa chỉ PC: 0x064968 | Địa chỉ FDE: 0x03bfd8 | Kích thước: 256 bytes
//   0x064968: D100C3FF  sub      sp, sp, #0x30
//   0x06496c: F9000BF4  str      x20, [sp, #0x10]
//   0x064970: A9027BF3  stp      x19, x30, [sp, #0x20]
//   0x064974: D348FC48  lsr      x8, x2, #8
static inline uint64_t fde_func_0135_0x064968(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x064968ULL ^ (static_cast<uint64_t>(0xd100c3ffULL) << 13);
    acc = (acc + a1 + 0xf9000bf4ULL) ^ 0x03bfd8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0136 | PC: 0x064b30 | FDE: 0x03bff8 | Size: 256 bytes [_Z18unlink_large_chunkP12malloc_stateP17malloc_tree_chunk]
// Khung tháo gỡ #0136 | Địa chỉ PC: 0x064b30 | Địa chỉ FDE: 0x03bff8 | Kích thước: 256 bytes
//   0x064b30: D10103FF  sub      sp, sp, #0x40
//   0x064b34: A9015BF7  stp      x23, x22, [sp, #0x10]
//   0x064b38: A90253F5  stp      x21, x20, [sp, #0x20]
//   0x064b3c: A9037BF3  stp      x19, x30, [sp, #0x30]
static inline uint64_t fde_func_0136_0x064b30(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x064b30ULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xa9015bf7ULL) ^ 0x03bff8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0137 | PC: 0x064e04 | FDE: 0x03c018 | Size: 256 bytes [_Z12insert_chunkP12malloc_stateP12malloc_chunkm]
// Khung tháo gỡ #0137 | Địa chỉ PC: 0x064e04 | Địa chỉ FDE: 0x03c018 | Kích thước: 256 bytes
//   0x064e04: D10103FF  sub      sp, sp, #0x40
//   0x064e08: F9000BF6  str      x22, [sp, #0x10]
//   0x064e0c: A90253F5  stp      x21, x20, [sp, #0x20]
//   0x064e10: A9037BF3  stp      x19, x30, [sp, #0x30]
static inline uint64_t fde_func_0137_0x064e04(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x064e04ULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xf9000bf6ULL) ^ 0x03c018ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0138 | PC: 0x06506c | FDE: 0x03c038 | Size: 256 bytes [_Z18local_insert_chunkP12malloc_stateP12malloc_chunkmi]
// Khung tháo gỡ #0138 | Địa chỉ PC: 0x06506c | Địa chỉ FDE: 0x03c038 | Kích thước: 256 bytes
//   0x06506c: D10103FF  sub      sp, sp, #0x40
//   0x065070: F9000BF6  str      x22, [sp, #0x10]
//   0x065074: A90253F5  stp      x21, x20, [sp, #0x20]
//   0x065078: A9037BF3  stp      x19, x30, [sp, #0x30]
static inline uint64_t fde_func_0138_0x06506c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x06506cULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xf9000bf6ULL) ^ 0x03c038ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0139 | PC: 0x0652dc | FDE: 0x03c058 | Size: 256 bytes [_Z12unlink_chunkP12malloc_stateP12malloc_chunkm]
// Khung tháo gỡ #0139 | Địa chỉ PC: 0x0652dc | Địa chỉ FDE: 0x03c058 | Kích thước: 256 bytes
//   0x0652dc: D10103FF  sub      sp, sp, #0x40
//   0x0652e0: A9015BF7  stp      x23, x22, [sp, #0x10]
//   0x0652e4: A90253F5  stp      x21, x20, [sp, #0x20]
//   0x0652e8: A9037BF3  stp      x19, x30, [sp, #0x30]
static inline uint64_t fde_func_0139_0x0652dc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0652dcULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xa9015bf7ULL) ^ 0x03c058ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0140 | PC: 0x065698 | FDE: 0x03c078 | Size: 16 bytes [_Z13mmap_set_freej]
// Khung tháo gỡ #0140 | Địa chỉ PC: 0x065698 | Địa chỉ FDE: 0x03c078 | Kích thước: 16 bytes
//   0x065698: 2A0003E8  mov      w8, w0
//   0x06569c: 52800020  mov      w0, #1
//   0x0656a0: B37F7D00  bfi      x0, x8, #1, #0x20
//   0x0656a4: D65F03C0  ret      
static inline uint64_t fde_func_0140_0x065698(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x065698ULL ^ (static_cast<uint64_t>(0x2a0003e8ULL) << 13);
    acc = (acc + a1 + 0x52800020ULL) ^ 0x03c078ULL;
    acc ^= (acc >> 17) * 0x0010ULL;
    return acc;
}

// FDE #0141 | PC: 0x0656a8 | FDE: 0x03c090 | Size: 116 bytes [_Z9init_binsP12malloc_state]
// Khung tháo gỡ #0141 | Địa chỉ PC: 0x0656a8 | Địa chỉ FDE: 0x03c090 | Kích thước: 116 bytes
//   0x0656a8: AA1F03E8  mov      x8, xzr
//   0x0656ac: F9404809  ldr      x9, [x0, #0x90]
//   0x0656b0: 8B080129  add      x9, x9, x8
//   0x0656b4: 91004108  add      x8, x8, #0x10
static inline uint64_t fde_func_0141_0x0656a8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0656a8ULL ^ (static_cast<uint64_t>(0xaa1f03e8ULL) << 13);
    acc = (acc + a1 + 0xf9404809ULL) ^ 0x03c090ULL;
    acc ^= (acc >> 17) * 0x0074ULL;
    return acc;
}

// FDE #0142 | PC: 0x06571c | FDE: 0x03c0a8 | Size: 256 bytes [_Z25destroy_allocate_instanceP12malloc_state]
// Khung tháo gỡ #0142 | Địa chỉ PC: 0x06571c | Địa chỉ FDE: 0x03c0a8 | Kích thước: 256 bytes
//   0x06571c: A9BD5BF7  stp      x23, x22, [sp, #-0x30]!
//   0x065720: A90153F5  stp      x21, x20, [sp, #0x10]
//   0x065724: A9027BF3  stp      x19, x30, [sp, #0x20]
//   0x065728: B9414008  ldr      w8, [x0, #0x140]
static inline uint64_t fde_func_0142_0x06571c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x06571cULL ^ (static_cast<uint64_t>(0xa9bd5bf7ULL) << 13);
    acc = (acc + a1 + 0xa90153f5ULL) ^ 0x03c0a8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0143 | PC: 0x065890 | FDE: 0x03c0c8 | Size: 256 bytes [_Z6gcfreeP12malloc_statePv]
// Khung tháo gỡ #0143 | Địa chỉ PC: 0x065890 | Địa chỉ FDE: 0x03c0c8 | Kích thước: 256 bytes
//   0x065890: D101C3FF  sub      sp, sp, #0x70
//   0x065894: F90013FA  str      x26, [sp, #0x20]
//   0x065898: A90363F9  stp      x25, x24, [sp, #0x30]
//   0x06589c: A9045BF7  stp      x23, x22, [sp, #0x40]
static inline uint64_t fde_func_0143_0x065890(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x065890ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xf90013faULL) ^ 0x03c0c8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0144 | PC: 0x066694 | FDE: 0x03c0f0 | Size: 8 bytes [_Z12mmap_is_freePKv]
// Khung tháo gỡ #0144 | Địa chỉ PC: 0x066694 | Địa chỉ FDE: 0x03c0f0 | Kích thước: 8 bytes
//   0x066694: 12000000  and      w0, w0, #1
//   0x066698: D65F03C0  ret      
static inline uint64_t fde_func_0144_0x066694(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x066694ULL ^ (static_cast<uint64_t>(0x12000000ULL) << 13);
    acc = (acc + a1 + 0xd65f03c0ULL) ^ 0x03c0f0ULL;
    acc ^= (acc >> 17) * 0x0008ULL;
    return acc;
}

// FDE #0145 | PC: 0x06669c | FDE: 0x03c108 | Size: 148 bytes [_Z23release_unused_segmentsP12malloc_state]
// Khung tháo gỡ #0145 | Địa chỉ PC: 0x06669c | Địa chỉ FDE: 0x03c108 | Kích thước: 148 bytes
//   0x06669c: A9BD5BF7  stp      x23, x22, [sp, #-0x30]!
//   0x0666a0: A90153F5  stp      x21, x20, [sp, #0x10]
//   0x0666a4: A9027BF3  stp      x19, x30, [sp, #0x20]
//   0x0666a8: F9408C08  ldr      x8, [x0, #0x118]
static inline uint64_t fde_func_0145_0x06669c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x06669cULL ^ (static_cast<uint64_t>(0xa9bd5bf7ULL) << 13);
    acc = (acc + a1 + 0xa90153f5ULL) ^ 0x03c108ULL;
    acc ^= (acc >> 17) * 0x0094ULL;
    return acc;
}

// FDE #0146 | PC: 0x066730 | FDE: 0x03c128 | Size: 256 bytes [_Z8allocateP12malloc_statem]
// Khung tháo gỡ #0146 | Địa chỉ PC: 0x066730 | Địa chỉ FDE: 0x03c128 | Kích thước: 256 bytes
//   0x066730: D10243FF  sub      sp, sp, #0x90
//   0x066734: F9001BFC  str      x28, [sp, #0x30]
//   0x066738: A9046BFB  stp      x27, x26, [sp, #0x40]
//   0x06673c: A90563F9  stp      x25, x24, [sp, #0x50]
static inline uint64_t fde_func_0146_0x066730(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x066730ULL ^ (static_cast<uint64_t>(0xd10243ffULL) << 13);
    acc = (acc + a1 + 0xf9001bfcULL) ^ 0x03c128ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0147 | PC: 0x068038 | FDE: 0x03c158 | Size: 160 bytes
// Khung tháo gỡ #0147 | Địa chỉ PC: 0x068038 | Địa chỉ FDE: 0x03c158 | Kích thước: 160 bytes
//   0x068038: D10483FF  sub      sp, sp, #0x120
//   0x06803c: F90083FC  str      x28, [sp, #0x100]
//   0x068040: A9117BF3  stp      x19, x30, [sp, #0x110]
//   0x068044: A90893E3  stp      x3, x4, [sp, #0x88]
static inline uint64_t fde_func_0147_0x068038(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x068038ULL ^ (static_cast<uint64_t>(0xd10483ffULL) << 13);
    acc = (acc + a1 + 0xf90083fcULL) ^ 0x03c158ULL;
    acc ^= (acc >> 17) * 0x00a0ULL;
    return acc;
}

// FDE #0148 | PC: 0x0680d8 | FDE: 0x03c178 | Size: 256 bytes
// Khung tháo gỡ #0148 | Địa chỉ PC: 0x0680d8 | Địa chỉ FDE: 0x03c178 | Kích thước: 256 bytes
//   0x0680d8: D10103FF  sub      sp, sp, #0x40
//   0x0680dc: F9000BF6  str      x22, [sp, #0x10]
//   0x0680e0: A90253F5  stp      x21, x20, [sp, #0x20]
//   0x0680e4: A9037BF3  stp      x19, x30, [sp, #0x30]
static inline uint64_t fde_func_0148_0x0680d8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0680d8ULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xf9000bf6ULL) ^ 0x03c178ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0149 | PC: 0x068440 | FDE: 0x03c198 | Size: 8 bytes [_Z10clear_markPv]
// Khung tháo gỡ #0149 | Địa chỉ PC: 0x068440 | Địa chỉ FDE: 0x03c198 | Kích thước: 8 bytes
//   0x068440: B81FC01F  stur     wzr, [x0, #-4]
//   0x068444: D65F03C0  ret      
static inline uint64_t fde_func_0149_0x068440(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x068440ULL ^ (static_cast<uint64_t>(0xb81fc01fULL) << 13);
    acc = (acc + a1 + 0xd65f03c0ULL) ^ 0x03c198ULL;
    acc ^= (acc >> 17) * 0x0008ULL;
    return acc;
}

// FDE #0150 | PC: 0x068448 | FDE: 0x03c1b0 | Size: 120 bytes [_Z24atomic_acqurie_local_idxP12malloc_state]
// Khung tháo gỡ #0150 | Địa chỉ PC: 0x068448 | Địa chỉ FDE: 0x03c1b0 | Kích thước: 120 bytes
//   0x068448: A9BE53F5  stp      x21, x20, [sp, #-0x20]!
//   0x06844c: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x068450: 91060013  add      x19, x0, #0x180
//   0x068454: AA0003F5  mov      x21, x0
static inline uint64_t fde_func_0150_0x068448(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x068448ULL ^ (static_cast<uint64_t>(0xa9be53f5ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x03c1b0ULL;
    acc ^= (acc >> 17) * 0x0078ULL;
    return acc;
}

// FDE #0151 | PC: 0x0684c0 | FDE: 0x03c1d0 | Size: 52 bytes [_Z24atomic_release_local_idxP12malloc_statei]
// Khung tháo gỡ #0151 | Địa chỉ PC: 0x0684c0 | Địa chỉ FDE: 0x03c1d0 | Kích thước: 52 bytes
//   0x0684c0: A9BE53F5  stp      x21, x20, [sp, #-0x20]!
//   0x0684c4: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x0684c8: 91060015  add      x21, x0, #0x180
//   0x0684cc: AA0003F4  mov      x20, x0
static inline uint64_t fde_func_0151_0x0684c0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0684c0ULL ^ (static_cast<uint64_t>(0xa9be53f5ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x03c1d0ULL;
    acc ^= (acc >> 17) * 0x0034ULL;
    return acc;
}

// FDE #0152 | PC: 0x0684f4 | FDE: 0x03c1f0 | Size: 48 bytes [_Z12local_gcfreeP12malloc_statePvi]
// Khung tháo gỡ #0152 | Địa chỉ PC: 0x0684f4 | Địa chỉ FDE: 0x03c1f0 | Kích thước: 48 bytes
//   0x0684f4: F85F0028  ldur     x8, [x1, #-0x10]
//   0x0684f8: 927DF108  and      x8, x8, #0xfffffffffffffff8
//   0x0684fc: 8B080029  add      x9, x1, x8
//   0x068500: F85F012A  ldur     x10, [x9, #-0x10]
static inline uint64_t fde_func_0152_0x0684f4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0684f4ULL ^ (static_cast<uint64_t>(0xf85f0028ULL) << 13);
    acc = (acc + a1 + 0x927df108ULL) ^ 0x03c1f0ULL;
    acc ^= (acc >> 17) * 0x0030ULL;
    return acc;
}

// FDE #0153 | PC: 0x068524 | FDE: 0x03c208 | Size: 256 bytes [_Z10reallocateP12malloc_statePvm]
// Khung tháo gỡ #0153 | Địa chỉ PC: 0x068524 | Địa chỉ FDE: 0x03c208 | Kích thước: 256 bytes
//   0x068524: D10103FF  sub      sp, sp, #0x40
//   0x068528: A9015BF7  stp      x23, x22, [sp, #0x10]
//   0x06852c: A90253F5  stp      x21, x20, [sp, #0x20]
//   0x068530: A9037BF3  stp      x19, x30, [sp, #0x30]
static inline uint64_t fde_func_0153_0x068524(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x068524ULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xa9015bf7ULL) ^ 0x03c208ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0154 | PC: 0x0689d8 | FDE: 0x03c228 | Size: 32 bytes [_Z20allocate_usable_sizePv]
// Khung tháo gỡ #0154 | Địa chỉ PC: 0x0689d8 | Địa chỉ FDE: 0x03c228 | Kích thước: 32 bytes
//   0x0689d8: F85F0008  ldur     x8, [x0, #-0x10]
//   0x0689dc: 52800209  mov      w9, #0x10
//   0x0689e0: 927DF10A  and      x10, x8, #0xfffffffffffffff8
//   0x0689e4: F240051F  tst      x8, #3
static inline uint64_t fde_func_0154_0x0689d8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0689d8ULL ^ (static_cast<uint64_t>(0xf85f0008ULL) << 13);
    acc = (acc + a1 + 0x52800209ULL) ^ 0x03c228ULL;
    acc ^= (acc >> 17) * 0x0020ULL;
    return acc;
}

// FDE #0155 | PC: 0x0689f8 | FDE: 0x03c240 | Size: 48 bytes [_Z11get_daytimev]
// Khung tháo gỡ #0155 | Địa chỉ PC: 0x0689f8 | Địa chỉ FDE: 0x03c240 | Kích thước: 48 bytes
//   0x0689f8: D10083FF  sub      sp, sp, #0x20
//   0x0689fc: F9000BFE  str      x30, [sp, #0x10]
//   0x068a00: 910003E0  mov      x0, sp
//   0x068a04: AA1F03E1  mov      x1, xzr
static inline uint64_t fde_func_0155_0x0689f8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0689f8ULL ^ (static_cast<uint64_t>(0xd10083ffULL) << 13);
    acc = (acc + a1 + 0xf9000bfeULL) ^ 0x03c240ULL;
    acc ^= (acc >> 17) * 0x0030ULL;
    return acc;
}

// FDE #0156 | PC: 0x068a28 | FDE: 0x03c258 | Size: 16 bytes [_Z9is_markedPv]
// Khung tháo gỡ #0156 | Địa chỉ PC: 0x068a28 | Địa chỉ FDE: 0x03c258 | Kích thước: 16 bytes
//   0x068a28: B85FC008  ldur     w8, [x0, #-4]
//   0x068a2c: 7100011F  cmp      w8, #0
//   0x068a30: 1A9F07E0  cset     w0, ne
//   0x068a34: D65F03C0  ret      
static inline uint64_t fde_func_0156_0x068a28(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x068a28ULL ^ (static_cast<uint64_t>(0xb85fc008ULL) << 13);
    acc = (acc + a1 + 0x7100011fULL) ^ 0x03c258ULL;
    acc ^= (acc >> 17) * 0x0010ULL;
    return acc;
}

// FDE #0157 | PC: 0x068a38 | FDE: 0x03c270 | Size: 12 bytes [_Z7get_tagPv]
// Khung tháo gỡ #0157 | Địa chỉ PC: 0x068a38 | Địa chỉ FDE: 0x03c270 | Kích thước: 12 bytes
//   0x068a38: B85F8008  ldur     w8, [x0, #-8]
//   0x068a3c: 12001500  and      w0, w8, #0x3f
//   0x068a40: D65F03C0  ret      
static inline uint64_t fde_func_0157_0x068a38(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x068a38ULL ^ (static_cast<uint64_t>(0xb85f8008ULL) << 13);
    acc = (acc + a1 + 0x12001500ULL) ^ 0x03c270ULL;
    acc ^= (acc >> 17) * 0x000cULL;
    return acc;
}

// FDE #0158 | PC: 0x068a44 | FDE: 0x03c288 | Size: 12 bytes [_Z14set_mark_multiPv]
// Khung tháo gỡ #0158 | Địa chỉ PC: 0x068a44 | Địa chỉ FDE: 0x03c288 | Kích thước: 12 bytes
//   0x068a44: 52800028  mov      w8, #1
//   0x068a48: B81FC008  stur     w8, [x0, #-4]
//   0x068a4c: D65F03C0  ret      
static inline uint64_t fde_func_0158_0x068a44(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x068a44ULL ^ (static_cast<uint64_t>(0x52800028ULL) << 13);
    acc = (acc + a1 + 0xb81fc008ULL) ^ 0x03c288ULL;
    acc ^= (acc >> 17) * 0x000cULL;
    return acc;
}

// FDE #0159 | PC: 0x068a50 | FDE: 0x03c2a0 | Size: 20 bytes [_Z13set_alloc_tagPvi]
// Khung tháo gỡ #0159 | Địa chỉ PC: 0x068a50 | Địa chỉ FDE: 0x03c2a0 | Kích thước: 20 bytes
//   0x068a50: B85F8008  ldur     w8, [x0, #-8]
//   0x068a54: 121A6508  and      w8, w8, #0xffffffc0
//   0x068a58: 2A010108  orr      w8, w8, w1
//   0x068a5c: B81F8008  stur     w8, [x0, #-8]
static inline uint64_t fde_func_0159_0x068a50(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x068a50ULL ^ (static_cast<uint64_t>(0xb85f8008ULL) << 13);
    acc = (acc + a1 + 0x121a6508ULL) ^ 0x03c2a0ULL;
    acc ^= (acc >> 17) * 0x0014ULL;
    return acc;
}

// FDE #0160 | PC: 0x068a64 | FDE: 0x03c2b8 | Size: 36 bytes [_Z16set_heap_obj_lenPvi]
// Khung tháo gỡ #0160 | Địa chỉ PC: 0x068a64 | Địa chỉ FDE: 0x03c2b8 | Kích thước: 36 bytes
//   0x068a64: 52A04008  mov      w8, #0x2000000
//   0x068a68: 6B08003F  cmp      w1, w8
//   0x068a6c: 5400006B  b.lt     #0x68a78
//   0x068a70: 529BD5A8  mov      w8, #0xdead
static inline uint64_t fde_func_0160_0x068a64(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x068a64ULL ^ (static_cast<uint64_t>(0x52a04008ULL) << 13);
    acc = (acc + a1 + 0x6b08003fULL) ^ 0x03c2b8ULL;
    acc ^= (acc >> 17) * 0x0024ULL;
    return acc;
}

// FDE #0161 | PC: 0x068a88 | FDE: 0x03c2d0 | Size: 12 bytes [_Z16get_heap_obj_lenPv]
// Khung tháo gỡ #0161 | Địa chỉ PC: 0x068a88 | Địa chỉ FDE: 0x03c2d0 | Kích thước: 12 bytes
//   0x068a88: B85F8008  ldur     w8, [x0, #-8]
//   0x068a8c: 13067D00  asr      w0, w8, #6
//   0x068a90: D65F03C0  ret      
static inline uint64_t fde_func_0161_0x068a88(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x068a88ULL ^ (static_cast<uint64_t>(0xb85f8008ULL) << 13);
    acc = (acc + a1 + 0x13067d00ULL) ^ 0x03c2d0ULL;
    acc ^= (acc >> 17) * 0x000cULL;
    return acc;
}

// FDE #0162 | PC: 0x068a94 | FDE: 0x03c2e8 | Size: 256 bytes [_ZN16GarbageCollectorC2EP12LEPUSRuntimeP12malloc_state]
// Khung tháo gỡ #0162 | Địa chỉ PC: 0x068a94 | Địa chỉ FDE: 0x03c2e8 | Kích thước: 256 bytes
//   0x068a94: F81C0FF8  str      x24, [sp, #-0x40]!
//   0x068a98: A9015BF7  stp      x23, x22, [sp, #0x10]
//   0x068a9c: A90253F5  stp      x21, x20, [sp, #0x20]
//   0x068aa0: A9037BF3  stp      x19, x30, [sp, #0x30]
static inline uint64_t fde_func_0162_0x068a94(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x068a94ULL ^ (static_cast<uint64_t>(0xf81c0ff8ULL) << 13);
    acc = (acc + a1 + 0xa9015bf7ULL) ^ 0x03c2e8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0163 | PC: 0x068ba4 | FDE: 0x03c310 | Size: 8 bytes [_ZNSt6__ndk113basic_istreamIcNS_11char_traitsIcEEED1Ev]
// Khung tháo gỡ #0163 | Địa chỉ PC: 0x068ba4 | Địa chỉ FDE: 0x03c310 | Kích thước: 8 bytes
//   0x068ba4: 91004000  add      x0, x0, #0x10
//   0x068ba8: 14051FD2  b        #0x1b0af0
static inline uint64_t fde_func_0163_0x068ba4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x068ba4ULL ^ (static_cast<uint64_t>(0x91004000ULL) << 13);
    acc = (acc + a1 + 0x14051fd2ULL) ^ 0x03c310ULL;
    acc ^= (acc >> 17) * 0x0008ULL;
    return acc;
}

// FDE #0164 | PC: 0x068bac | FDE: 0x03c328 | Size: 28 bytes [_ZNSt6__ndk113basic_istreamIcNS_11char_traitsIcEEED0Ev]
// Khung tháo gỡ #0164 | Địa chỉ PC: 0x068bac | Địa chỉ FDE: 0x03c328 | Kích thước: 28 bytes
//   0x068bac: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x068bb0: AA0003F3  mov      x19, x0
//   0x068bb4: 91004000  add      x0, x0, #0x10
//   0x068bb8: 94051FCE  bl       #0x1b0af0
static inline uint64_t fde_func_0164_0x068bac(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x068bacULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0xaa0003f3ULL) ^ 0x03c328ULL;
    acc ^= (acc >> 17) * 0x001cULL;
    return acc;
}

// FDE #0165 | PC: 0x068bc8 | FDE: 0x03c340 | Size: 20 bytes [_ZTv0_n24_NSt6__ndk113basic_istreamIcNS_11char_traitsIcEEED1Ev]
// Khung tháo gỡ #0165 | Địa chỉ PC: 0x068bc8 | Địa chỉ FDE: 0x03c340 | Kích thước: 20 bytes
//   0x068bc8: F9400008  ldr      x8, [x0]
//   0x068bcc: F85E8108  ldur     x8, [x8, #-0x18]
//   0x068bd0: 8B080008  add      x8, x0, x8
//   0x068bd4: 91004100  add      x0, x8, #0x10
static inline uint64_t fde_func_0165_0x068bc8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x068bc8ULL ^ (static_cast<uint64_t>(0xf9400008ULL) << 13);
    acc = (acc + a1 + 0xf85e8108ULL) ^ 0x03c340ULL;
    acc ^= (acc >> 17) * 0x0014ULL;
    return acc;
}

// FDE #0166 | PC: 0x068bdc | FDE: 0x03c358 | Size: 36 bytes [_ZTv0_n24_NSt6__ndk113basic_istreamIcNS_11char_traitsIcEEED0Ev]
// Khung tháo gỡ #0166 | Địa chỉ PC: 0x068bdc | Địa chỉ FDE: 0x03c358 | Kích thước: 36 bytes
//   0x068bdc: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x068be0: F9400008  ldr      x8, [x0]
//   0x068be4: F85E8108  ldur     x8, [x8, #-0x18]
//   0x068be8: 8B080013  add      x19, x0, x8
static inline uint64_t fde_func_0166_0x068bdc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x068bdcULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0xf9400008ULL) ^ 0x03c358ULL;
    acc ^= (acc >> 17) * 0x0024ULL;
    return acc;
}

// FDE #0167 | PC: 0x068c00 | FDE: 0x03c370 | Size: 96 bytes
// Khung tháo gỡ #0167 | Địa chỉ PC: 0x068c00 | Địa chỉ FDE: 0x03c370 | Kích thước: 96 bytes
//   0x068c00: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x068c04: 90000A68  adrp     x8, #0x1b4000
//   0x068c08: 91098108  add      x8, x8, #0x260
//   0x068c0c: 39416009  ldrb     w9, [x0, #0x58]
static inline uint64_t fde_func_0167_0x068c00(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x068c00ULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0x90000a68ULL) ^ 0x03c370ULL;
    acc ^= (acc >> 17) * 0x0060ULL;
    return acc;
}

// FDE #0168 | PC: 0x068c60 | FDE: 0x03c388 | Size: 104 bytes
// Khung tháo gỡ #0168 | Địa chỉ PC: 0x068c60 | Địa chỉ FDE: 0x03c388 | Kích thước: 104 bytes
//   0x068c60: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x068c64: 90000A68  adrp     x8, #0x1b4000
//   0x068c68: 91098108  add      x8, x8, #0x260
//   0x068c6c: 39416009  ldrb     w9, [x0, #0x58]
static inline uint64_t fde_func_0168_0x068c60(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x068c60ULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0x90000a68ULL) ^ 0x03c388ULL;
    acc ^= (acc >> 17) * 0x0068ULL;
    return acc;
}

// FDE #0169 | PC: 0x068cc8 | FDE: 0x03c3a0 | Size: 108 bytes
// Khung tháo gỡ #0169 | Địa chỉ PC: 0x068cc8 | Địa chỉ FDE: 0x03c3a0 | Kích thước: 108 bytes
//   0x068cc8: F81E0FF4  str      x20, [sp, #-0x20]!
//   0x068ccc: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x068cd0: 90000A68  adrp     x8, #0x1b4000
//   0x068cd4: 91098108  add      x8, x8, #0x260
static inline uint64_t fde_func_0169_0x068cc8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x068cc8ULL ^ (static_cast<uint64_t>(0xf81e0ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x03c3a0ULL;
    acc ^= (acc >> 17) * 0x006cULL;
    return acc;
}

// FDE #0170 | PC: 0x068d34 | FDE: 0x03c3c0 | Size: 116 bytes
// Khung tháo gỡ #0170 | Địa chỉ PC: 0x068d34 | Địa chỉ FDE: 0x03c3c0 | Kích thước: 116 bytes
//   0x068d34: F81E0FF4  str      x20, [sp, #-0x20]!
//   0x068d38: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x068d3c: 90000A68  adrp     x8, #0x1b4000
//   0x068d40: 91098108  add      x8, x8, #0x260
static inline uint64_t fde_func_0170_0x068d34(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x068d34ULL ^ (static_cast<uint64_t>(0xf81e0ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x03c3c0ULL;
    acc ^= (acc >> 17) * 0x0074ULL;
    return acc;
}

// FDE #0171 | PC: 0x068da8 | FDE: 0x03c3e0 | Size: 116 bytes
// Khung tháo gỡ #0171 | Địa chỉ PC: 0x068da8 | Địa chỉ FDE: 0x03c3e0 | Kích thước: 116 bytes
//   0x068da8: F81E0FF4  str      x20, [sp, #-0x20]!
//   0x068dac: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x068db0: F9400008  ldr      x8, [x0]
//   0x068db4: 90000A69  adrp     x9, #0x1b4000
static inline uint64_t fde_func_0171_0x068da8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x068da8ULL ^ (static_cast<uint64_t>(0xf81e0ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x03c3e0ULL;
    acc ^= (acc >> 17) * 0x0074ULL;
    return acc;
}

// FDE #0172 | PC: 0x068e1c | FDE: 0x03c400 | Size: 124 bytes
// Khung tháo gỡ #0172 | Địa chỉ PC: 0x068e1c | Địa chỉ FDE: 0x03c400 | Kích thước: 124 bytes
//   0x068e1c: F81E0FF4  str      x20, [sp, #-0x20]!
//   0x068e20: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x068e24: F9400008  ldr      x8, [x0]
//   0x068e28: 90000A69  adrp     x9, #0x1b4000
static inline uint64_t fde_func_0172_0x068e1c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x068e1cULL ^ (static_cast<uint64_t>(0xf81e0ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x03c400ULL;
    acc ^= (acc >> 17) * 0x007cULL;
    return acc;
}

// FDE #0173 | PC: 0x068e98 | FDE: 0x03c420 | Size: 256 bytes [_ZN16GarbageCollectorD2Ev]
// Khung tháo gỡ #0173 | Địa chỉ PC: 0x068e98 | Địa chỉ FDE: 0x03c420 | Kích thước: 256 bytes
//   0x068e98: A9BE53F5  stp      x21, x20, [sp, #-0x20]!
//   0x068e9c: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x068ea0: F9400C14  ldr      x20, [x0, #0x18]
//   0x068ea4: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_0173_0x068e98(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x068e98ULL ^ (static_cast<uint64_t>(0xa9be53f5ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x03c420ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0174 | PC: 0x068fb0 | FDE: 0x03c440 | Size: 256 bytes [_ZN16GarbageCollector4InitEP12LEPUSRuntime]
// Khung tháo gỡ #0174 | Địa chỉ PC: 0x068fb0 | Địa chỉ FDE: 0x03c440 | Kích thước: 256 bytes
//   0x068fb0: A9BD5BF7  stp      x23, x22, [sp, #-0x30]!
//   0x068fb4: A90153F5  stp      x21, x20, [sp, #0x10]
//   0x068fb8: A9027BF3  stp      x19, x30, [sp, #0x20]
//   0x068fbc: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_0174_0x068fb0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x068fb0ULL ^ (static_cast<uint64_t>(0xa9bd5bf7ULL) << 13);
    acc = (acc + a1 + 0xa90153f5ULL) ^ 0x03c440ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0175 | PC: 0x0690c4 | FDE: 0x03c460 | Size: 256 bytes [_ZN9Finalizer11DoFinalizerEPv]
// Khung tháo gỡ #0175 | Địa chỉ PC: 0x0690c4 | Địa chỉ FDE: 0x03c460 | Kích thước: 256 bytes
//   0x0690c4: F81E0FF4  str      x20, [sp, #-0x20]!
//   0x0690c8: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x0690cc: B85F8028  ldur     w8, [x1, #-8]
//   0x0690d0: 12001509  and      w9, w8, #0x3f
static inline uint64_t fde_func_0175_0x0690c4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0690c4ULL ^ (static_cast<uint64_t>(0xf81e0ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x03c460ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0176 | PC: 0x069560 | FDE: 0x03c480 | Size: 208 bytes [_ZN9Finalizer17JSSymbolFinalizerEPv]
// Khung tháo gỡ #0176 | Địa chỉ PC: 0x069560 | Địa chỉ FDE: 0x03c480 | Kích thước: 208 bytes
//   0x069560: F81E0FF4  str      x20, [sp, #-0x20]!
//   0x069564: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x069568: AA0003E8  mov      x8, x0
//   0x06956c: F9400820  ldr      x0, [x1, #0x10]
static inline uint64_t fde_func_0176_0x069560(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x069560ULL ^ (static_cast<uint64_t>(0xf81e0ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x03c480ULL;
    acc ^= (acc >> 17) * 0x00d0ULL;
    return acc;
}

// FDE #0177 | PC: 0x069630 | FDE: 0x03c4a0 | Size: 28 bytes [_ZN9Finalizer17JSVarRefFinalizerEPv]
// Khung tháo gỡ #0177 | Địa chỉ PC: 0x069630 | Địa chỉ FDE: 0x03c4a0 | Kích thước: 28 bytes
//   0x069630: 39401428  ldrb     w8, [x1, #5]
//   0x069634: 370800A8  tbnz     w8, #1, #0x69648
//   0x069638: A9412428  ldp      x8, x9, [x1, #0x10]
//   0x06963c: F9000509  str      x9, [x8, #8]
static inline uint64_t fde_func_0177_0x069630(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x069630ULL ^ (static_cast<uint64_t>(0x39401428ULL) << 13);
    acc = (acc + a1 + 0x370800a8ULL) ^ 0x03c4a0ULL;
    acc ^= (acc >> 17) * 0x001cULL;
    return acc;
}

// FDE #0178 | PC: 0x06964c | FDE: 0x03c4b8 | Size: 24 bytes [_ZN9Finalizer27JSFunctionBytecodeFinalizerEPv]
// Khung tháo gỡ #0178 | Địa chỉ PC: 0x06964c | Địa chỉ FDE: 0x03c4b8 | Kích thước: 24 bytes
//   0x06964c: 39401C28  ldrb     w8, [x1, #7]
//   0x069650: 36100088  tbz      w8, #2, #0x69660
//   0x069654: F9404020  ldr      x0, [x1, #0x80]
//   0x069658: B4000040  cbz      x0, #0x69660
static inline uint64_t fde_func_0178_0x06964c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x06964cULL ^ (static_cast<uint64_t>(0x39401c28ULL) << 13);
    acc = (acc + a1 + 0x36100088ULL) ^ 0x03c4b8ULL;
    acc ^= (acc >> 17) * 0x0018ULL;
    return acc;
}

// FDE #0179 | PC: 0x069664 | FDE: 0x03c4d0 | Size: 256 bytes [_ZN9Finalizer12DoFinalizer2EPv]
// Khung tháo gỡ #0179 | Địa chỉ PC: 0x069664 | Địa chỉ FDE: 0x03c4d0 | Kích thước: 256 bytes
//   0x069664: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x069668: B85F8028  ldur     w8, [x1, #-8]
//   0x06966c: 12001508  and      w8, w8, #0x3f
//   0x069670: 51000908  sub      w8, w8, #2
static inline uint64_t fde_func_0179_0x069664(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x069664ULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0xb85f8028ULL) ^ 0x03c4d0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0180 | PC: 0x069794 | FDE: 0x03c4e8 | Size: 84 bytes [_ZN7Visitor18VisitLEPUSLepusRefEPvi]
// Khung tháo gỡ #0180 | Địa chỉ PC: 0x069794 | Địa chỉ FDE: 0x03c4e8 | Kích thước: 84 bytes
//   0x069794: A9BE53F5  stp      x21, x20, [sp, #-0x20]!
//   0x069798: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x06979c: AA0103F4  mov      x20, x1
//   0x0697a0: 91004021  add      x1, x1, #0x10
static inline uint64_t fde_func_0180_0x069794(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x069794ULL ^ (static_cast<uint64_t>(0xa9be53f5ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x03c4e8ULL;
    acc ^= (acc >> 17) * 0x0054ULL;
    return acc;
}

// FDE #0181 | PC: 0x0697e8 | FDE: 0x03c508 | Size: 8 bytes [_ZN7Visitor13VisitJSVarRefEPvi]
// Khung tháo gỡ #0181 | Địa chỉ PC: 0x0697e8 | Địa chỉ FDE: 0x03c508 | Kích thước: 8 bytes
//   0x0697e8: F9401021  ldr      x1, [x1, #0x20]
//   0x0697ec: 14008D3A  b        #0x8ccd4
static inline uint64_t fde_func_0181_0x0697e8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0697e8ULL ^ (static_cast<uint64_t>(0xf9401021ULL) << 13);
    acc = (acc + a1 + 0x14008d3aULL) ^ 0x03c508ULL;
    acc ^= (acc >> 17) * 0x0008ULL;
    return acc;
}

// FDE #0182 | PC: 0x0697f0 | FDE: 0x03c520 | Size: 48 bytes [_ZN7Visitor19VisitRootLEPUSValueEP10LEPUSValuei]
// Khung tháo gỡ #0182 | Địa chỉ PC: 0x0697f0 | Địa chỉ FDE: 0x03c520 | Kích thước: 48 bytes
//   0x0697f0: F81F0FFE  str      x30, [sp, #-0x10]!
//   0x0697f4: F9400028  ldr      x8, [x1]
//   0x0697f8: B27C0109  orr      x9, x8, #0x10
//   0x0697fc: F100493F  cmp      x9, #0x12
static inline uint64_t fde_func_0182_0x0697f0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0697f0ULL ^ (static_cast<uint64_t>(0xf81f0ffeULL) << 13);
    acc = (acc + a1 + 0xf9400028ULL) ^ 0x03c520ULL;
    acc ^= (acc >> 17) * 0x0030ULL;
    return acc;
}

// FDE #0183 | PC: 0x069820 | FDE: 0x03c538 | Size: 228 bytes [_ZN7Visitor16VisitRootJSTokenEP7JSTokeni]
// Khung tháo gỡ #0183 | Địa chỉ PC: 0x069820 | Địa chỉ FDE: 0x03c538 | Kích thước: 228 bytes
//   0x069820: D100C3FF  sub      sp, sp, #0x30
//   0x069824: A90153F5  stp      x21, x20, [sp, #0x10]
//   0x069828: A9027BF3  stp      x19, x30, [sp, #0x20]
//   0x06982c: B9400028  ldr      w8, [x1]
static inline uint64_t fde_func_0183_0x069820(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x069820ULL ^ (static_cast<uint64_t>(0xd100c3ffULL) << 13);
    acc = (acc + a1 + 0xa90153f5ULL) ^ 0x03c538ULL;
    acc ^= (acc >> 17) * 0x00e4ULL;
    return acc;
}

// FDE #0184 | PC: 0x069904 | FDE: 0x03c558 | Size: 16 bytes [_ZN7Visitor16VisitRootCStringEPci]
// Khung tháo gỡ #0184 | Địa chỉ PC: 0x069904 | Địa chỉ FDE: 0x03c558 | Kích thước: 16 bytes
//   0x069904: B4000061  cbz      x1, #0x69910
//   0x069908: D1006021  sub      x1, x1, #0x18
//   0x06990c: 140085B4  b        #0x8afdc
//   0x069910: D65F03C0  ret      
static inline uint64_t fde_func_0184_0x069904(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x069904ULL ^ (static_cast<uint64_t>(0xb4000061ULL) << 13);
    acc = (acc + a1 + 0xd1006021ULL) ^ 0x03c558ULL;
    acc ^= (acc >> 17) * 0x0010ULL;
    return acc;
}

// FDE #0185 | PC: 0x069914 | FDE: 0x03c570 | Size: 4 bytes [_ZN7Visitor20VisitJSForInIteratorEPvi]
// Khung tháo gỡ #0185 | Địa chỉ PC: 0x069914 | Địa chỉ FDE: 0x03c570 | Kích thước: 4 bytes
//   0x069914: 14008CF0  b        #0x8ccd4
static inline uint64_t fde_func_0185_0x069914(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x069914ULL ^ (static_cast<uint64_t>(0x14008cf0ULL) << 13);
    acc = (acc + a1 + 0xa9bc63f9ULL) ^ 0x03c570ULL;
    acc ^= (acc >> 17) * 0x0004ULL;
    return acc;
}

// FDE #0186 | PC: 0x069918 | FDE: 0x03c588 | Size: 256 bytes [_ZN7Visitor10VisitEntryEPvi]
// Khung tháo gỡ #0186 | Địa chỉ PC: 0x069918 | Địa chỉ FDE: 0x03c588 | Kích thước: 256 bytes
//   0x069918: A9BC63F9  stp      x25, x24, [sp, #-0x40]!
//   0x06991c: A9015BF7  stp      x23, x22, [sp, #0x10]
//   0x069920: A90253F5  stp      x21, x20, [sp, #0x20]
//   0x069924: A9037BF3  stp      x19, x30, [sp, #0x30]
static inline uint64_t fde_func_0186_0x069918(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x069918ULL ^ (static_cast<uint64_t>(0xa9bc63f9ULL) << 13);
    acc = (acc + a1 + 0xa9015bf7ULL) ^ 0x03c588ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0187 | PC: 0x069eb8 | FDE: 0x03c5b0 | Size: 72 bytes [_ZN7Visitor20VisitSeparableStringEPvi]
// Khung tháo gỡ #0187 | Địa chỉ PC: 0x069eb8 | Địa chỉ FDE: 0x03c5b0 | Kích thước: 72 bytes
//   0x069eb8: A9BE53F5  stp      x21, x20, [sp, #-0x20]!
//   0x069ebc: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x069ec0: AA0103F5  mov      x21, x1
//   0x069ec4: F8420C28  ldr      x8, [x1, #0x20]!
static inline uint64_t fde_func_0187_0x069eb8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x069eb8ULL ^ (static_cast<uint64_t>(0xa9be53f5ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x03c5b0ULL;
    acc ^= (acc >> 17) * 0x0048ULL;
    return acc;
}

// FDE #0188 | PC: 0x069f00 | FDE: 0x03c5d0 | Size: 8 bytes [_Z12HeapObjStoreP12LEPUSContextPv10LEPUSValue]
// Khung tháo gỡ #0188 | Địa chỉ PC: 0x069f00 | Địa chỉ FDE: 0x03c5d0 | Kích thước: 8 bytes
//   0x069f00: F9000022  str      x2, [x1]
//   0x069f04: D65F03C0  ret      
static inline uint64_t fde_func_0188_0x069f00(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x069f00ULL ^ (static_cast<uint64_t>(0xf9000022ULL) << 13);
    acc = (acc + a1 + 0xd65f03c0ULL) ^ 0x03c5d0ULL;
    acc ^= (acc >> 17) * 0x0008ULL;
    return acc;
}

// FDE #0189 | PC: 0x069f08 | FDE: 0x03c5e8 | Size: 8 bytes [_Z17HeapObjStoreNoCtxPv10LEPUSValue]
// Khung tháo gỡ #0189 | Địa chỉ PC: 0x069f08 | Địa chỉ FDE: 0x03c5e8 | Kích thước: 8 bytes
//   0x069f08: F9000001  str      x1, [x0]
//   0x069f0c: D65F03C0  ret      
static inline uint64_t fde_func_0189_0x069f08(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x069f08ULL ^ (static_cast<uint64_t>(0xf9000001ULL) << 13);
    acc = (acc + a1 + 0xd65f03c0ULL) ^ 0x03c5e8ULL;
    acc ^= (acc >> 17) * 0x0008ULL;
    return acc;
}

// FDE #0190 | PC: 0x069f10 | FDE: 0x03c600 | Size: 24 bytes [_ZN4Node14global_handlesEv]
// Khung tháo gỡ #0190 | Địa chỉ PC: 0x069f10 | Địa chỉ FDE: 0x03c600 | Kích thước: 24 bytes
//   0x069f10: 39406008  ldrb     w8, [x0, #0x18]
//   0x069f14: 52800509  mov      w9, #0x28
//   0x069f18: 9B09FD08  mneg     x8, x8, x9
//   0x069f1c: 8B080008  add      x8, x0, x8
static inline uint64_t fde_func_0190_0x069f10(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x069f10ULL ^ (static_cast<uint64_t>(0x39406008ULL) << 13);
    acc = (acc + a1 + 0x52800509ULL) ^ 0x03c600ULL;
    acc ^= (acc >> 17) * 0x0018ULL;
    return acc;
}

// FDE #0191 | PC: 0x069f28 | FDE: 0x03c618 | Size: 36 bytes [_ZN13GlobalHandles9NodeSpaceD1Ev]
// Khung tháo gỡ #0191 | Địa chỉ PC: 0x069f28 | Địa chỉ FDE: 0x03c618 | Kích thước: 36 bytes
//   0x069f28: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x069f2c: F9400400  ldr      x0, [x0, #8]
//   0x069f30: B40000A0  cbz      x0, #0x69f44
//   0x069f34: F9540013  ldr      x19, [x0, #0x2800]
static inline uint64_t fde_func_0191_0x069f28(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x069f28ULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0xf9400400ULL) ^ 0x03c618ULL;
    acc ^= (acc >> 17) * 0x0024ULL;
    return acc;
}

// FDE #0192 | PC: 0x069f4c | FDE: 0x03c630 | Size: 60 bytes [_ZN13GlobalHandles9NodeSpace18PutNodesOnFreeListEPNS_9NodeBlockE]
// Khung tháo gỡ #0192 | Địa chỉ PC: 0x069f4c | Địa chỉ FDE: 0x03c630 | Kích thước: 60 bytes
//   0x069f4c: 5284FB09  mov      w9, #0x27d8
//   0x069f50: 52802008  mov      w8, #0x100
//   0x069f54: 8B090029  add      x9, x1, x9
//   0x069f58: 5280024A  mov      w10, #0x12
static inline uint64_t fde_func_0192_0x069f4c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x069f4cULL ^ (static_cast<uint64_t>(0x5284fb09ULL) << 13);
    acc = (acc + a1 + 0x52802008ULL) ^ 0x03c630ULL;
    acc ^= (acc >> 17) * 0x003cULL;
    return acc;
}

// FDE #0193 | PC: 0x069f88 | FDE: 0x03c648 | Size: 144 bytes [_ZN13GlobalHandles9NodeSpace7ReleaseEP4Node]
// Khung tháo gỡ #0193 | Địa chỉ PC: 0x069f88 | Địa chỉ FDE: 0x03c648 | Kích thước: 144 bytes
//   0x069f88: 39406008  ldrb     w8, [x0, #0x18]
//   0x069f8c: 52800509  mov      w9, #0x28
//   0x069f90: 5280024A  mov      w10, #0x12
//   0x069f94: 9B09FD08  mneg     x8, x8, x9
static inline uint64_t fde_func_0193_0x069f88(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x069f88ULL ^ (static_cast<uint64_t>(0x39406008ULL) << 13);
    acc = (acc + a1 + 0x52800509ULL) ^ 0x03c648ULL;
    acc ^= (acc >> 17) * 0x0090ULL;
    return acc;
}

// FDE #0194 | PC: 0x06a018 | FDE: 0x03c660 | Size: 20 bytes [_ZNK13GlobalHandles9TotalSizeEv]
// Khung tháo gỡ #0194 | Địa chỉ PC: 0x06a018 | Địa chỉ FDE: 0x03c660 | Kích thước: 20 bytes
//   0x06a018: F9400808  ldr      x8, [x0, #0x10]
//   0x06a01c: F9401108  ldr      x8, [x8, #0x20]
//   0x06a020: 8B080908  add      x8, x8, x8, lsl #2
//   0x06a024: D375D100  lsl      x0, x8, #0xb
static inline uint64_t fde_func_0194_0x06a018(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x06a018ULL ^ (static_cast<uint64_t>(0xf9400808ULL) << 13);
    acc = (acc + a1 + 0xf9401108ULL) ^ 0x03c660ULL;
    acc ^= (acc >> 17) * 0x0014ULL;
    return acc;
}

// FDE #0195 | PC: 0x06a02c | FDE: 0x03c678 | Size: 20 bytes [_ZNK13GlobalHandles8UsedSizeEv]
// Khung tháo gỡ #0195 | Địa chỉ PC: 0x06a02c | Địa chỉ FDE: 0x03c678 | Kích thước: 20 bytes
//   0x06a02c: F9400808  ldr      x8, [x0, #0x10]
//   0x06a030: F9401508  ldr      x8, [x8, #0x28]
//   0x06a034: 8B080908  add      x8, x8, x8, lsl #2
//   0x06a038: D37DF100  lsl      x0, x8, #3
static inline uint64_t fde_func_0195_0x06a02c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x06a02cULL ^ (static_cast<uint64_t>(0xf9400808ULL) << 13);
    acc = (acc + a1 + 0xf9401508ULL) ^ 0x03c678ULL;
    acc ^= (acc >> 17) * 0x0014ULL;
    return acc;
}

// FDE #0196 | PC: 0x06a040 | FDE: 0x03c690 | Size: 12 bytes [_ZNK13GlobalHandles13handles_countEv]
// Khung tháo gỡ #0196 | Địa chỉ PC: 0x06a040 | Địa chỉ FDE: 0x03c690 | Kích thước: 12 bytes
//   0x06a040: F9400808  ldr      x8, [x0, #0x10]
//   0x06a044: F9401500  ldr      x0, [x8, #0x28]
//   0x06a048: D65F03C0  ret      
static inline uint64_t fde_func_0196_0x06a040(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x06a040ULL ^ (static_cast<uint64_t>(0xf9400808ULL) << 13);
    acc = (acc + a1 + 0xf9401500ULL) ^ 0x03c690ULL;
    acc ^= (acc >> 17) * 0x000cULL;
    return acc;
}

// FDE #0197 | PC: 0x06a04c | FDE: 0x03c6a8 | Size: 56 bytes [_ZN13GlobalHandlesC2EP12LEPUSRuntime]
// Khung tháo gỡ #0197 | Địa chỉ PC: 0x06a04c | Địa chỉ FDE: 0x03c6a8 | Kích thước: 56 bytes
//   0x06a04c: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x06a050: AA0003F3  mov      x19, x0
//   0x06a054: F9000001  str      x1, [x0]
//   0x06a058: 3900201F  strb     wzr, [x0, #8]
static inline uint64_t fde_func_0197_0x06a04c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x06a04cULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0xaa0003f3ULL) ^ 0x03c6a8ULL;
    acc ^= (acc >> 17) * 0x0038ULL;
    return acc;
}

// FDE #0198 | PC: 0x06a084 | FDE: 0x03c6c0 | Size: 68 bytes [_ZN13GlobalHandlesD1Ev]
// Khung tháo gỡ #0198 | Địa chỉ PC: 0x06a084 | Địa chỉ FDE: 0x03c6c0 | Kích thước: 68 bytes
//   0x06a084: F81E0FF4  str      x20, [sp, #-0x20]!
//   0x06a088: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x06a08c: F9400813  ldr      x19, [x0, #0x10]
//   0x06a090: B4000173  cbz      x19, #0x6a0bc
static inline uint64_t fde_func_0198_0x06a084(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x06a084ULL ^ (static_cast<uint64_t>(0xf81e0ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x03c6c0ULL;
    acc ^= (acc >> 17) * 0x0044ULL;
    return acc;
}

// FDE #0199 | PC: 0x06a0c8 | FDE: 0x03c6e0 | Size: 256 bytes [_ZN13GlobalHandles6CreateE10LEPUSValueb]
// Khung tháo gỡ #0199 | Địa chỉ PC: 0x06a0c8 | Địa chỉ FDE: 0x03c6e0 | Kích thước: 256 bytes
//   0x06a0c8: A9BE53F5  stp      x21, x20, [sp, #-0x20]!
//   0x06a0cc: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x06a0d0: F9400815  ldr      x21, [x0, #0x10]
//   0x06a0d4: 2A0203F3  mov      w19, w2
static inline uint64_t fde_func_0199_0x06a0c8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x06a0c8ULL ^ (static_cast<uint64_t>(0xa9be53f5ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x03c6e0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0200 | PC: 0x06a1e0 | FDE: 0x03c700 | Size: 148 bytes [_ZN13GlobalHandles7DestroyEP10LEPUSValue]
// Khung tháo gỡ #0200 | Địa chỉ PC: 0x06a1e0 | Địa chỉ FDE: 0x03c700 | Kích thước: 148 bytes
//   0x06a1e0: B4000480  cbz      x0, #0x6a270
//   0x06a1e4: 39406008  ldrb     w8, [x0, #0x18]
//   0x06a1e8: 52800509  mov      w9, #0x28
//   0x06a1ec: 5280024A  mov      w10, #0x12
static inline uint64_t fde_func_0200_0x06a1e0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x06a1e0ULL ^ (static_cast<uint64_t>(0xb4000480ULL) << 13);
    acc = (acc + a1 + 0x39406008ULL) ^ 0x03c700ULL;
    acc ^= (acc >> 17) * 0x0094ULL;
    return acc;
}

// FDE #0201 | PC: 0x06a274 | FDE: 0x03c718 | Size: 20 bytes [_ZN13GlobalHandles7SetWeakEP10LEPUSValuePvPFvS2_E]
// Khung tháo gỡ #0201 | Địa chỉ PC: 0x06a274 | Địa chỉ FDE: 0x03c718 | Kích thước: 20 bytes
//   0x06a274: B4000081  cbz      x1, #0x6a284
//   0x06a278: 52800048  mov      w8, #2
//   0x06a27c: 39006428  strb     w8, [x1, #0x19]
//   0x06a280: A9008823  stp      x3, x2, [x1, #8]
static inline uint64_t fde_func_0201_0x06a274(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x06a274ULL ^ (static_cast<uint64_t>(0xb4000081ULL) << 13);
    acc = (acc + a1 + 0x52800048ULL) ^ 0x03c718ULL;
    acc ^= (acc >> 17) * 0x0014ULL;
    return acc;
}

// FDE #0202 | PC: 0x06a288 | FDE: 0x03c730 | Size: 20 bytes [_ZN13GlobalHandles9ClearWeakEP10LEPUSValue]
// Khung tháo gỡ #0202 | Địa chỉ PC: 0x06a288 | Địa chỉ FDE: 0x03c730 | Kích thước: 20 bytes
//   0x06a288: B4000081  cbz      x1, #0x6a298
//   0x06a28c: 52800028  mov      w8, #1
//   0x06a290: 39006428  strb     w8, [x1, #0x19]
//   0x06a294: A900FC3F  stp      xzr, xzr, [x1, #8]
static inline uint64_t fde_func_0202_0x06a288(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x06a288ULL ^ (static_cast<uint64_t>(0xb4000081ULL) << 13);
    acc = (acc + a1 + 0x52800028ULL) ^ 0x03c730ULL;
    acc ^= (acc >> 17) * 0x0014ULL;
    return acc;
}

// FDE #0203 | PC: 0x06a29c | FDE: 0x03c748 | Size: 16 bytes [_ZN13GlobalHandles12SetWeakStateEP10LEPUSValue]
// Khung tháo gỡ #0203 | Địa chỉ PC: 0x06a29c | Địa chỉ FDE: 0x03c748 | Kích thước: 16 bytes
//   0x06a29c: B4000061  cbz      x1, #0x6a2a8
//   0x06a2a0: 52800048  mov      w8, #2
//   0x06a2a4: 39006428  strb     w8, [x1, #0x19]
//   0x06a2a8: D65F03C0  ret      
static inline uint64_t fde_func_0203_0x06a29c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x06a29cULL ^ (static_cast<uint64_t>(0xb4000061ULL) << 13);
    acc = (acc + a1 + 0x52800048ULL) ^ 0x03c748ULL;
    acc ^= (acc >> 17) * 0x0010ULL;
    return acc;
}

// FDE #0204 | PC: 0x06a2ac | FDE: 0x03c760 | Size: 176 bytes [_ZN13GlobalHandles15IterateAllRootsEii]
// Khung tháo gỡ #0204 | Địa chỉ PC: 0x06a2ac | Địa chỉ FDE: 0x03c760 | Kích thước: 176 bytes
//   0x06a2ac: F81C0FF8  str      x24, [sp, #-0x40]!
//   0x06a2b0: A9015BF7  stp      x23, x22, [sp, #0x10]
//   0x06a2b4: A90253F5  stp      x21, x20, [sp, #0x20]
//   0x06a2b8: A9037BF3  stp      x19, x30, [sp, #0x30]
static inline uint64_t fde_func_0204_0x06a2ac(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x06a2acULL ^ (static_cast<uint64_t>(0xf81c0ff8ULL) << 13);
    acc = (acc + a1 + 0xa9015bf7ULL) ^ 0x03c760ULL;
    acc ^= (acc >> 17) * 0x00b0ULL;
    return acc;
}

// FDE #0205 | PC: 0x06a35c | FDE: 0x03c788 | Size: 128 bytes [_ZN13GlobalHandles18IsMarkedLEPUSValueEP10LEPUSValue]
// Khung tháo gỡ #0205 | Địa chỉ PC: 0x06a35c | Địa chỉ FDE: 0x03c788 | Kích thước: 128 bytes
//   0x06a35c: F9400028  ldr      x8, [x1]
//   0x06a360: D2E0002A  mov      x10, #0x1000000000000
//   0x06a364: 92503D09  and      x9, x8, #0xffff000000000000
//   0x06a368: EB0A013F  cmp      x9, x10
static inline uint64_t fde_func_0205_0x06a35c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x06a35cULL ^ (static_cast<uint64_t>(0xf9400028ULL) << 13);
    acc = (acc + a1 + 0xd2e0002aULL) ^ 0x03c788ULL;
    acc ^= (acc >> 17) * 0x0080ULL;
    return acc;
}

// FDE #0206 | PC: 0x06a3dc | FDE: 0x03c7a0 | Size: 256 bytes [_ZN13GlobalHandles20GlobalRootsFinalizerEv]
// Khung tháo gỡ #0206 | Địa chỉ PC: 0x06a3dc | Địa chỉ FDE: 0x03c7a0 | Kích thước: 256 bytes
//   0x06a3dc: A9BB6BFB  stp      x27, x26, [sp, #-0x50]!
//   0x06a3e0: A90163F9  stp      x25, x24, [sp, #0x10]
//   0x06a3e4: A9025BF7  stp      x23, x22, [sp, #0x20]
//   0x06a3e8: A90353F5  stp      x21, x20, [sp, #0x30]
static inline uint64_t fde_func_0206_0x06a3dc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x06a3dcULL ^ (static_cast<uint64_t>(0xa9bb6bfbULL) << 13);
    acc = (acc + a1 + 0xa90163f9ULL) ^ 0x03c7a0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0207 | PC: 0x06a4ec | FDE: 0x03c7c8 | Size: 16 bytes [_ZN7Element15global_handles1Ev]
// Khung tháo gỡ #0207 | Địa chỉ PC: 0x06a4ec | Địa chỉ FDE: 0x03c7c8 | Kích thước: 16 bytes
//   0x06a4ec: 3940C408  ldrb     w8, [x0, #0x31]
//   0x06a4f0: CB081808  sub      x8, x0, x8, lsl #6
//   0x06a4f4: F9600500  ldr      x0, [x8, #0x4008]
//   0x06a4f8: D65F03C0  ret      
static inline uint64_t fde_func_0207_0x06a4ec(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x06a4ecULL ^ (static_cast<uint64_t>(0x3940c408ULL) << 13);
    acc = (acc + a1 + 0xcb081808ULL) ^ 0x03c7c8ULL;
    acc ^= (acc >> 17) * 0x0010ULL;
    return acc;
}

// FDE #0208 | PC: 0x06a4fc | FDE: 0x03c7e0 | Size: 36 bytes [_ZN18QJSValueValueSpace9NodeSpaceD2Ev]
// Khung tháo gỡ #0208 | Địa chỉ PC: 0x06a4fc | Địa chỉ FDE: 0x03c7e0 | Kích thước: 36 bytes
//   0x06a4fc: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x06a500: F9400400  ldr      x0, [x0, #8]
//   0x06a504: B40000A0  cbz      x0, #0x6a518
//   0x06a508: F9600013  ldr      x19, [x0, #0x4000]
static inline uint64_t fde_func_0208_0x06a4fc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x06a4fcULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0xf9400400ULL) ^ 0x03c7e0ULL;
    acc ^= (acc >> 17) * 0x0024ULL;
    return acc;
}

// FDE #0209 | PC: 0x06a520 | FDE: 0x03c7f8 | Size: 48 bytes [_ZN18QJSValueValueSpace9NodeSpace18PutNodesOnFreeListEPNS_9NodeBlockE]
// Khung tháo gỡ #0209 | Địa chỉ PC: 0x06a520 | Địa chỉ FDE: 0x03c7f8 | Kích thước: 48 bytes
//   0x06a520: 5287F808  mov      w8, #0x3fc0
//   0x06a524: 8B080028  add      x8, x1, x8
//   0x06a528: 52802009  mov      w9, #0x100
//   0x06a52c: D1000529  sub      x9, x9, #1
static inline uint64_t fde_func_0209_0x06a520(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x06a520ULL ^ (static_cast<uint64_t>(0x5287f808ULL) << 13);
    acc = (acc + a1 + 0x8b080028ULL) ^ 0x03c7f8ULL;
    acc ^= (acc >> 17) * 0x0030ULL;
    return acc;
}

// FDE #0210 | PC: 0x06a550 | FDE: 0x03c810 | Size: 116 bytes [_ZN18QJSValueValueSpace9NodeSpace7ReleaseEP7Element]
// Khung tháo gỡ #0210 | Địa chỉ PC: 0x06a550 | Địa chỉ FDE: 0x03c810 | Kích thước: 116 bytes
//   0x06a550: 3940C408  ldrb     w8, [x0, #0x31]
//   0x06a554: 5288050A  mov      w10, #0x4028
//   0x06a558: CB081808  sub      x8, x0, x8, lsl #6
//   0x06a55c: F9600908  ldr      x8, [x8, #0x4010]
static inline uint64_t fde_func_0210_0x06a550(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x06a550ULL ^ (static_cast<uint64_t>(0x3940c408ULL) << 13);
    acc = (acc + a1 + 0x5288050aULL) ^ 0x03c810ULL;
    acc ^= (acc >> 17) * 0x0074ULL;
    return acc;
}

// FDE #0211 | PC: 0x06a5c4 | FDE: 0x03c828 | Size: 40 bytes [_ZN18QJSValueValueSpaceC1EP12LEPUSRuntime]
// Khung tháo gỡ #0211 | Địa chỉ PC: 0x06a5c4 | Địa chỉ FDE: 0x03c828 | Kích thước: 40 bytes
//   0x06a5c4: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x06a5c8: AA0003F3  mov      x19, x0
//   0x06a5cc: F9000001  str      x1, [x0]
//   0x06a5d0: 52800400  mov      w0, #0x20
static inline uint64_t fde_func_0211_0x06a5c4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x06a5c4ULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0xaa0003f3ULL) ^ 0x03c828ULL;
    acc ^= (acc >> 17) * 0x0028ULL;
    return acc;
}

// FDE #0212 | PC: 0x06a5ec | FDE: 0x03c840 | Size: 68 bytes [_ZN18QJSValueValueSpaceD1Ev]
// Khung tháo gỡ #0212 | Địa chỉ PC: 0x06a5ec | Địa chỉ FDE: 0x03c840 | Kích thước: 68 bytes
//   0x06a5ec: F81E0FF4  str      x20, [sp, #-0x20]!
//   0x06a5f0: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x06a5f4: F9400413  ldr      x19, [x0, #8]
//   0x06a5f8: B4000173  cbz      x19, #0x6a624
static inline uint64_t fde_func_0212_0x06a5ec(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x06a5ecULL ^ (static_cast<uint64_t>(0xf81e0ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x03c840ULL;
    acc ^= (acc >> 17) * 0x0044ULL;
    return acc;
}

// FDE #0213 | PC: 0x06a630 | FDE: 0x03c860 | Size: 196 bytes [_ZN18QJSValueValueSpace6CreateEv]
// Khung tháo gỡ #0213 | Địa chỉ PC: 0x06a630 | Địa chỉ FDE: 0x03c860 | Kích thước: 196 bytes
//   0x06a630: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x06a634: F9400413  ldr      x19, [x0, #8]
//   0x06a638: F9400E60  ldr      x0, [x19, #0x18]
//   0x06a63c: B5000360  cbnz     x0, #0x6a6a8
static inline uint64_t fde_func_0213_0x06a630(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x06a630ULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0xf9400413ULL) ^ 0x03c860ULL;
    acc ^= (acc >> 17) * 0x00c4ULL;
    return acc;
}

// FDE #0214 | PC: 0x06a6f4 | FDE: 0x03c878 | Size: 160 bytes [_ZN18QJSValueValueSpace15IterateAllRootsEi]
// Khung tháo gỡ #0214 | Địa chỉ PC: 0x06a6f4 | Địa chỉ FDE: 0x03c878 | Kích thước: 160 bytes
//   0x06a6f4: F81D0FF6  str      x22, [sp, #-0x30]!
//   0x06a6f8: A90153F5  stp      x21, x20, [sp, #0x10]
//   0x06a6fc: A9027BF3  stp      x19, x30, [sp, #0x20]
//   0x06a700: F9400408  ldr      x8, [x0, #8]
static inline uint64_t fde_func_0214_0x06a6f4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x06a6f4ULL ^ (static_cast<uint64_t>(0xf81d0ff6ULL) << 13);
    acc = (acc + a1 + 0xa90153f5ULL) ^ 0x03c878ULL;
    acc ^= (acc >> 17) * 0x00a0ULL;
    return acc;
}

// FDE #0215 | PC: 0x06a794 | FDE: 0x03c898 | Size: 256 bytes [_ZN7Sweeper18traverse_finalizerEbl]
// Khung tháo gỡ #0215 | Địa chỉ PC: 0x06a794 | Địa chỉ FDE: 0x03c898 | Kích thước: 256 bytes
//   0x06a794: D10183FF  sub      sp, sp, #0x60
//   0x06a798: A9016BFB  stp      x27, x26, [sp, #0x10]
//   0x06a79c: A90263F9  stp      x25, x24, [sp, #0x20]
//   0x06a7a0: A9035BF7  stp      x23, x22, [sp, #0x30]
static inline uint64_t fde_func_0215_0x06a794(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x06a794ULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xa9016bfbULL) ^ 0x03c898ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0216 | PC: 0x06a92c | FDE: 0x03c8c0 | Size: 256 bytes [_ZN7Sweeper28traverse_chunk_for_finalizerEb]
// Khung tháo gỡ #0216 | Địa chỉ PC: 0x06a92c | Địa chỉ FDE: 0x03c8c0 | Kích thước: 256 bytes
//   0x06a92c: D101C3FF  sub      sp, sp, #0x70
//   0x06a930: A9016FFC  stp      x28, x27, [sp, #0x10]
//   0x06a934: A90267FA  stp      x26, x25, [sp, #0x20]
//   0x06a938: A9035FF8  stp      x24, x23, [sp, #0x30]
static inline uint64_t fde_func_0216_0x06a92c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x06a92cULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xa9016ffcULL) ^ 0x03c8c0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0217 | PC: 0x06ab00 | FDE: 0x03c8f0 | Size: 256 bytes [_ZN7Sweeper15reinit_freelistEv]
// Khung tháo gỡ #0217 | Địa chỉ PC: 0x06ab00 | Địa chỉ FDE: 0x03c8f0 | Kích thước: 256 bytes
//   0x06ab00: F9400008  ldr      x8, [x0]
//   0x06ab04: AA1F03E9  mov      x9, xzr
//   0x06ab08: F900011F  str      xzr, [x8]
//   0x06ab0c: F9400008  ldr      x8, [x0]
static inline uint64_t fde_func_0217_0x06ab00(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x06ab00ULL ^ (static_cast<uint64_t>(0xf9400008ULL) << 13);
    acc = (acc + a1 + 0xaa1f03e9ULL) ^ 0x03c8f0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0218 | PC: 0x06ac5c | FDE: 0x03c908 | Size: 60 bytes [_ZN7Sweeper26calculate_task_granularityEv]
// Khung tháo gỡ #0218 | Địa chỉ PC: 0x06ac5c | Địa chỉ FDE: 0x03c908 | Kích thước: 60 bytes
//   0x06ac5c: F9400008  ldr      x8, [x0]
//   0x06ac60: B201F3E9  mov      x9, #-0x5555555555555556
//   0x06ac64: F2955569  movk     x9, #0xaaab
//   0x06ac68: B201F3EC  mov      x12, #-0x5555555555555556
static inline uint64_t fde_func_0218_0x06ac5c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x06ac5cULL ^ (static_cast<uint64_t>(0xf9400008ULL) << 13);
    acc = (acc + a1 + 0xb201f3e9ULL) ^ 0x03c908ULL;
    acc ^= (acc >> 17) * 0x003cULL;
    return acc;
}

// FDE #0219 | PC: 0x06ac98 | FDE: 0x03c920 | Size: 96 bytes [_ZN7Sweeper17free_mmap_objectsEv]
// Khung tháo gỡ #0219 | Địa chỉ PC: 0x06ac98 | Địa chỉ FDE: 0x03c920 | Kích thước: 96 bytes
//   0x06ac98: A9BE53F5  stp      x21, x20, [sp, #-0x20]!
//   0x06ac9c: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x06aca0: F9400008  ldr      x8, [x0]
//   0x06aca4: B9413D14  ldr      w20, [x8, #0x13c]
static inline uint64_t fde_func_0219_0x06ac98(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x06ac98ULL ^ (static_cast<uint64_t>(0xa9be53f5ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x03c920ULL;
    acc ^= (acc >> 17) * 0x0060ULL;
    return acc;
}

// FDE #0220 | PC: 0x06acf8 | FDE: 0x03c940 | Size: 184 bytes [_Z15merge_dead_objsP12malloc_stateP14malloc_segmentS2_]
// Khung tháo gỡ #0220 | Địa chỉ PC: 0x06acf8 | Địa chỉ FDE: 0x03c940 | Kích thước: 184 bytes
//   0x06acf8: F940002A  ldr      x10, [x1]
//   0x06acfc: 91006148  add      x8, x10, #0x18
//   0x06ad00: 4B0803E9  neg      w9, w8
//   0x06ad04: 92400929  and      x9, x9, #7
static inline uint64_t fde_func_0220_0x06acf8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x06acf8ULL ^ (static_cast<uint64_t>(0xf940002aULL) << 13);
    acc = (acc + a1 + 0x91006148ULL) ^ 0x03c940ULL;
    acc ^= (acc >> 17) * 0x00b8ULL;
    return acc;
}

// FDE #0221 | PC: 0x06adb0 | FDE: 0x03c958 | Size: 236 bytes [_Z30parallel_traverse_heap_segmentP12malloc_statemP14ByteThreadPoolNSt6__ndk18functionIFvS0_P14malloc_segmentS6_EEE]
// Khung tháo gỡ #0221 | Địa chỉ PC: 0x06adb0 | Địa chỉ FDE: 0x03c958 | Kích thước: 236 bytes
//   0x06adb0: F81A0FFC  str      x28, [sp, #-0x60]!
//   0x06adb4: A9016BFB  stp      x27, x26, [sp, #0x10]
//   0x06adb8: A90263F9  stp      x25, x24, [sp, #0x20]
//   0x06adbc: A9035BF7  stp      x23, x22, [sp, #0x30]
static inline uint64_t fde_func_0221_0x06adb0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x06adb0ULL ^ (static_cast<uint64_t>(0xf81a0ffcULL) << 13);
    acc = (acc + a1 + 0xa9016bfbULL) ^ 0x03c958ULL;
    acc ^= (acc >> 17) * 0x00ecULL;
    return acc;
}

// FDE #0222 | PC: 0x06ae9c | FDE: 0x03c988 | Size: 52 bytes
// Khung tháo gỡ #0222 | Địa chỉ PC: 0x06ae9c | Địa chỉ FDE: 0x03c988 | Kích thước: 52 bytes
//   0x06ae9c: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x06aea0: AA0003F3  mov      x19, x0
//   0x06aea4: 52800500  mov      w0, #0x28
//   0x06aea8: 940516EA  bl       #0x1b0a50
static inline uint64_t fde_func_0222_0x06ae9c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x06ae9cULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0xaa0003f3ULL) ^ 0x03c988ULL;
    acc ^= (acc >> 17) * 0x0034ULL;
    return acc;
}

// FDE #0223 | PC: 0x06aed0 | FDE: 0x03c9a0 | Size: 64 bytes
// Khung tháo gỡ #0223 | Địa chỉ PC: 0x06aed0 | Địa chỉ FDE: 0x03c9a0 | Kích thước: 64 bytes
//   0x06aed0: AA0003E8  mov      x8, x0
//   0x06aed4: F9401800  ldr      x0, [x0, #0x30]
//   0x06aed8: D0000A49  adrp     x9, #0x1b4000
//   0x06aedc: 9100410A  add      x10, x8, #0x10
static inline uint64_t fde_func_0223_0x06aed0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x06aed0ULL ^ (static_cast<uint64_t>(0xaa0003e8ULL) << 13);
    acc = (acc + a1 + 0xf9401800ULL) ^ 0x03c9a0ULL;
    acc ^= (acc >> 17) * 0x0040ULL;
    return acc;
}

// FDE #0224 | PC: 0x06af10 | FDE: 0x03c9b8 | Size: 76 bytes
// Khung tháo gỡ #0224 | Địa chỉ PC: 0x06af10 | Địa chỉ FDE: 0x03c9b8 | Kích thước: 76 bytes
//   0x06af10: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x06af14: AA0003F3  mov      x19, x0
//   0x06af18: F9401800  ldr      x0, [x0, #0x30]
//   0x06af1c: D0000A48  adrp     x8, #0x1b4000
static inline uint64_t fde_func_0224_0x06af10(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x06af10ULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0xaa0003f3ULL) ^ 0x03c9b8ULL;
    acc ^= (acc >> 17) * 0x004cULL;
    return acc;
}

// FDE #0225 | PC: 0x06af5c | FDE: 0x03c9d0 | Size: 84 bytes
// Khung tháo gỡ #0225 | Địa chỉ PC: 0x06af5c | Địa chỉ FDE: 0x03c9d0 | Kích thước: 84 bytes
//   0x06af5c: D10083FF  sub      sp, sp, #0x20
//   0x06af60: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x06af64: D53BD053  mrs      x19, tpidr_el0
//   0x06af68: F9401668  ldr      x8, [x19, #0x28]
static inline uint64_t fde_func_0225_0x06af5c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x06af5cULL ^ (static_cast<uint64_t>(0xd10083ffULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x03c9d0ULL;
    acc ^= (acc >> 17) * 0x0054ULL;
    return acc;
}

// FDE #0226 | PC: 0x06afb0 | FDE: 0x03c9e8 | Size: 8 bytes
// Khung tháo gỡ #0226 | Địa chỉ PC: 0x06afb0 | Địa chỉ FDE: 0x03c9e8 | Kích thước: 8 bytes
//   0x06afb0: F81F0FFE  str      x30, [sp, #-0x10]!
//   0x06afb4: 94051667  bl       #0x1b0950
static inline uint64_t fde_func_0226_0x06afb0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x06afb0ULL ^ (static_cast<uint64_t>(0xf81f0ffeULL) << 13);
    acc = (acc + a1 + 0x94051667ULL) ^ 0x03c9e8ULL;
    acc ^= (acc >> 17) * 0x0008ULL;
    return acc;
}

// FDE #0227 | PC: 0x06afb8 | FDE: 0x03ca00 | Size: 4 bytes
// Khung tháo gỡ #0227 | Địa chỉ PC: 0x06afb8 | Địa chỉ FDE: 0x03ca00 | Kích thước: 4 bytes
//   0x06afb8: 140516AE  b        #0x1b0a70
static inline uint64_t fde_func_0227_0x06afb8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x06afb8ULL ^ (static_cast<uint64_t>(0x140516aeULL) << 13);
    acc = (acc + a1 + 0xd0000a48ULL) ^ 0x03ca00ULL;
    acc ^= (acc >> 17) * 0x0004ULL;
    return acc;
}

// FDE #0228 | PC: 0x06afbc | FDE: 0x03ca18 | Size: 32 bytes
// Khung tháo gỡ #0228 | Địa chỉ PC: 0x06afbc | Địa chỉ FDE: 0x03ca18 | Kích thước: 32 bytes
//   0x06afbc: D0000A48  adrp     x8, #0x1b4000
//   0x06afc0: 910E6108  add      x8, x8, #0x398
//   0x06afc4: F9000028  str      x8, [x1]
//   0x06afc8: 3CC18000  ldur     q0, [x0, #0x18]
static inline uint64_t fde_func_0228_0x06afbc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x06afbcULL ^ (static_cast<uint64_t>(0xd0000a48ULL) << 13);
    acc = (acc + a1 + 0x910e6108ULL) ^ 0x03ca18ULL;
    acc ^= (acc >> 17) * 0x0020ULL;
    return acc;
}

// FDE #0229 | PC: 0x06afdc | FDE: 0x03ca30 | Size: 104 bytes
// Khung tháo gỡ #0229 | Địa chỉ PC: 0x06afdc | Địa chỉ FDE: 0x03ca30 | Kích thước: 104 bytes
//   0x06afdc: D100C3FF  sub      sp, sp, #0x30
//   0x06afe0: A9027BF3  stp      x19, x30, [sp, #0x20]
//   0x06afe4: D53BD053  mrs      x19, tpidr_el0
//   0x06afe8: F9401668  ldr      x8, [x19, #0x28]
static inline uint64_t fde_func_0229_0x06afdc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x06afdcULL ^ (static_cast<uint64_t>(0xd100c3ffULL) << 13);
    acc = (acc + a1 + 0xa9027bf3ULL) ^ 0x03ca30ULL;
    acc ^= (acc >> 17) * 0x0068ULL;
    return acc;
}

// FDE #0230 | PC: 0x06b044 | FDE: 0x03ca48 | Size: 28 bytes
// Khung tháo gỡ #0230 | Địa chỉ PC: 0x06b044 | Địa chỉ FDE: 0x03ca48 | Kích thước: 28 bytes
//   0x06b044: F9400428  ldr      x8, [x1, #8]
//   0x06b048: B0FFFE49  adrp     x9, #0x34000
//   0x06b04c: 9127DD29  add      x9, x9, #0x9f7
//   0x06b050: 9100200A  add      x10, x0, #8
static inline uint64_t fde_func_0230_0x06b044(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x06b044ULL ^ (static_cast<uint64_t>(0xf9400428ULL) << 13);
    acc = (acc + a1 + 0xb0fffe49ULL) ^ 0x03ca48ULL;
    acc ^= (acc >> 17) * 0x001cULL;
    return acc;
}

// FDE #0231 | PC: 0x06b060 | FDE: 0x03ca60 | Size: 12 bytes
// Khung tháo gỡ #0231 | Địa chỉ PC: 0x06b060 | Địa chỉ FDE: 0x03ca60 | Kích thước: 12 bytes
//   0x06b060: B0000A40  adrp     x0, #0x1b4000
//   0x06b064: 91112000  add      x0, x0, #0x448
//   0x06b068: D65F03C0  ret      
static inline uint64_t fde_func_0231_0x06b060(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x06b060ULL ^ (static_cast<uint64_t>(0xb0000a40ULL) << 13);
    acc = (acc + a1 + 0x91112000ULL) ^ 0x03ca60ULL;
    acc ^= (acc >> 17) * 0x000cULL;
    return acc;
}

// FDE #0232 | PC: 0x06b06c | FDE: 0x03ca78 | Size: 256 bytes [_ZN7Sweeper23traverse_chunk_for_freeEv]
// Khung tháo gỡ #0232 | Địa chỉ PC: 0x06b06c | Địa chỉ FDE: 0x03ca78 | Kích thước: 256 bytes
//   0x06b06c: D10383FF  sub      sp, sp, #0xe0
//   0x06b070: A9086FFC  stp      x28, x27, [sp, #0x80]
//   0x06b074: A90967FA  stp      x26, x25, [sp, #0x90]
//   0x06b078: A90A5FF8  stp      x24, x23, [sp, #0xa0]
static inline uint64_t fde_func_0232_0x06b06c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x06b06cULL ^ (static_cast<uint64_t>(0xd10383ffULL) << 13);
    acc = (acc + a1 + 0xa9086ffcULL) ^ 0x03ca78ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0233 | PC: 0x06b364 | FDE: 0x03caa8 | Size: 256 bytes [_ZN7Sweeper17generate_freelistEP12malloc_stateP14malloc_segmentS3_]
// Khung tháo gỡ #0233 | Địa chỉ PC: 0x06b364 | Địa chỉ FDE: 0x03caa8 | Kích thước: 256 bytes
//   0x06b364: D10243FF  sub      sp, sp, #0x90
//   0x06b368: A9036FFC  stp      x28, x27, [sp, #0x30]
//   0x06b36c: A90467FA  stp      x26, x25, [sp, #0x40]
//   0x06b370: A9055FF8  stp      x24, x23, [sp, #0x50]
static inline uint64_t fde_func_0233_0x06b364(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x06b364ULL ^ (static_cast<uint64_t>(0xd10243ffULL) << 13);
    acc = (acc + a1 + 0xa9036ffcULL) ^ 0x03caa8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0234 | PC: 0x06be14 | FDE: 0x03cad8 | Size: 44 bytes
// Khung tháo gỡ #0234 | Địa chỉ PC: 0x06be14 | Địa chỉ FDE: 0x03cad8 | Kích thước: 44 bytes
//   0x06be14: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x06be18: AA0003F3  mov      x19, x0
//   0x06be1c: 52800200  mov      w0, #0x10
//   0x06be20: 9405130C  bl       #0x1b0a50
static inline uint64_t fde_func_0234_0x06be14(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x06be14ULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0xaa0003f3ULL) ^ 0x03cad8ULL;
    acc ^= (acc >> 17) * 0x002cULL;
    return acc;
}

// FDE #0235 | PC: 0x06be40 | FDE: 0x03caf0 | Size: 24 bytes
// Khung tháo gỡ #0235 | Địa chỉ PC: 0x06be40 | Địa chỉ FDE: 0x03caf0 | Kích thước: 24 bytes
//   0x06be40: B0000A48  adrp     x8, #0x1b4000
//   0x06be44: 9111E108  add      x8, x8, #0x478
//   0x06be48: F9000028  str      x8, [x1]
//   0x06be4c: F9400408  ldr      x8, [x0, #8]
static inline uint64_t fde_func_0235_0x06be40(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x06be40ULL ^ (static_cast<uint64_t>(0xb0000a48ULL) << 13);
    acc = (acc + a1 + 0x9111e108ULL) ^ 0x03caf0ULL;
    acc ^= (acc >> 17) * 0x0018ULL;
    return acc;
}

// FDE #0236 | PC: 0x06be58 | FDE: 0x03cb08 | Size: 20 bytes
// Khung tháo gỡ #0236 | Địa chỉ PC: 0x06be58 | Địa chỉ FDE: 0x03cb08 | Kích thước: 20 bytes
//   0x06be58: F9400404  ldr      x4, [x0, #8]
//   0x06be5c: F9400020  ldr      x0, [x1]
//   0x06be60: F9400041  ldr      x1, [x2]
//   0x06be64: F9400062  ldr      x2, [x3]
static inline uint64_t fde_func_0236_0x06be58(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x06be58ULL ^ (static_cast<uint64_t>(0xf9400404ULL) << 13);
    acc = (acc + a1 + 0xf9400020ULL) ^ 0x03cb08ULL;
    acc ^= (acc >> 17) * 0x0014ULL;
    return acc;
}

// FDE #0237 | PC: 0x06be6c | FDE: 0x03cb20 | Size: 28 bytes
// Khung tháo gỡ #0237 | Địa chỉ PC: 0x06be6c | Địa chỉ FDE: 0x03cb20 | Kích thước: 28 bytes
//   0x06be6c: D0000A89  adrp     x9, #0x1bd000
//   0x06be70: F9400428  ldr      x8, [x1, #8]
//   0x06be74: F940E929  ldr      x9, [x9, #0x1d0]
//   0x06be78: 9100200A  add      x10, x0, #8
static inline uint64_t fde_func_0237_0x06be6c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x06be6cULL ^ (static_cast<uint64_t>(0xd0000a89ULL) << 13);
    acc = (acc + a1 + 0xf9400428ULL) ^ 0x03cb20ULL;
    acc ^= (acc >> 17) * 0x001cULL;
    return acc;
}

// FDE #0238 | PC: 0x06be88 | FDE: 0x03cb38 | Size: 12 bytes
// Khung tháo gỡ #0238 | Địa chỉ PC: 0x06be88 | Địa chỉ FDE: 0x03cb38 | Kích thước: 12 bytes
//   0x06be88: D0000A80  adrp     x0, #0x1bd000
//   0x06be8c: F940EC00  ldr      x0, [x0, #0x1d8]
//   0x06be90: D65F03C0  ret      
static inline uint64_t fde_func_0238_0x06be88(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x06be88ULL ^ (static_cast<uint64_t>(0xd0000a80ULL) << 13);
    acc = (acc + a1 + 0xf940ec00ULL) ^ 0x03cb38ULL;
    acc ^= (acc >> 17) * 0x000cULL;
    return acc;
}

// FDE #0239 | PC: 0x06be94 | FDE: 0x03cb50 | Size: 28 bytes [_ZN7Sweeper15sweep_finalizerEv]
// Khung tháo gỡ #0239 | Địa chỉ PC: 0x06be94 | Địa chỉ FDE: 0x03cb50 | Kích thước: 28 bytes
//   0x06be94: F9400008  ldr      x8, [x0]
//   0x06be98: 2A1F03E1  mov      w1, wzr
//   0x06be9c: F9406909  ldr      x9, [x8, #0xd0]
//   0x06bea0: F900A909  str      x9, [x8, #0x150]
static inline uint64_t fde_func_0239_0x06be94(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x06be94ULL ^ (static_cast<uint64_t>(0xf9400008ULL) << 13);
    acc = (acc + a1 + 0x2a1f03e1ULL) ^ 0x03cb50ULL;
    acc ^= (acc >> 17) * 0x001cULL;
    return acc;
}

// FDE #0240 | PC: 0x06beb0 | FDE: 0x03cb68 | Size: 136 bytes [_ZN7Sweeper10sweep_freeEv]
// Khung tháo gỡ #0240 | Địa chỉ PC: 0x06beb0 | Địa chỉ FDE: 0x03cb68 | Kích thước: 136 bytes
//   0x06beb0: F81D0FF6  str      x22, [sp, #-0x30]!
//   0x06beb4: A90153F5  stp      x21, x20, [sp, #0x10]
//   0x06beb8: A9027BF3  stp      x19, x30, [sp, #0x20]
//   0x06bebc: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_0240_0x06beb0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x06beb0ULL ^ (static_cast<uint64_t>(0xf81d0ff6ULL) << 13);
    acc = (acc + a1 + 0xa90153f5ULL) ^ 0x03cb68ULL;
    acc ^= (acc >> 17) * 0x0088ULL;
    return acc;
}

// FDE #0241 | PC: 0x06bf38 | FDE: 0x03cb88 | Size: 256 bytes [_ZN14BytePoolThreadC1EP14ByteThreadPoolPKcmm]
// Khung tháo gỡ #0241 | Địa chỉ PC: 0x06bf38 | Địa chỉ FDE: 0x03cb88 | Kích thước: 256 bytes
//   0x06bf38: D10203FF  sub      sp, sp, #0x80
//   0x06bf3c: A90463F9  stp      x25, x24, [sp, #0x40]
//   0x06bf40: A9055BF7  stp      x23, x22, [sp, #0x50]
//   0x06bf44: A90653F5  stp      x21, x20, [sp, #0x60]
static inline uint64_t fde_func_0241_0x06bf38(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x06bf38ULL ^ (static_cast<uint64_t>(0xd10203ffULL) << 13);
    acc = (acc + a1 + 0xa90463f9ULL) ^ 0x03cb88ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0242 | PC: 0x06c2e4 | FDE: 0x03cbb0 | Size: 144 bytes [_ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEC2IDnEEPKc]
// Khung tháo gỡ #0242 | Địa chỉ PC: 0x06c2e4 | Địa chỉ FDE: 0x03cbb0 | Kích thước: 144 bytes
//   0x06c2e4: F81D0FF6  str      x22, [sp, #-0x30]!
//   0x06c2e8: A90153F5  stp      x21, x20, [sp, #0x10]
//   0x06c2ec: A9027BF3  stp      x19, x30, [sp, #0x20]
//   0x06c2f0: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_0242_0x06c2e4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x06c2e4ULL ^ (static_cast<uint64_t>(0xf81d0ff6ULL) << 13);
    acc = (acc + a1 + 0xa90153f5ULL) ^ 0x03cbb0ULL;
    acc ^= (acc >> 17) * 0x0090ULL;
    return acc;
}

// FDE #0243 | PC: 0x06c374 | FDE: 0x03cbd0 | Size: 256 bytes [_ZNSt6__ndk113basic_ostreamIcNS_11char_traitsIcEEElsEm]
// Khung tháo gỡ #0243 | Địa chỉ PC: 0x06c374 | Địa chỉ FDE: 0x03cbd0 | Kích thước: 256 bytes
//   0x06c374: D10143FF  sub      sp, sp, #0x50
//   0x06c378: A90163F9  stp      x25, x24, [sp, #0x10]
//   0x06c37c: A9025BF7  stp      x23, x22, [sp, #0x20]
//   0x06c380: A90353F5  stp      x21, x20, [sp, #0x30]
static inline uint64_t fde_func_0243_0x06c374(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x06c374ULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xa90163f9ULL) ^ 0x03cbd0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0244 | PC: 0x06c51c | FDE: 0x03cbf8 | Size: 256 bytes [_ZN14BytePoolThread10WorkerFuncEPv]
// Khung tháo gỡ #0244 | Địa chỉ PC: 0x06c51c | Địa chỉ FDE: 0x03cbf8 | Kích thước: 256 bytes
//   0x06c51c: D10203FF  sub      sp, sp, #0x80
//   0x06c520: A9026FFC  stp      x28, x27, [sp, #0x20]
//   0x06c524: A90367FA  stp      x26, x25, [sp, #0x30]
//   0x06c528: A9045FF8  stp      x24, x23, [sp, #0x40]
static inline uint64_t fde_func_0244_0x06c51c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x06c51cULL ^ (static_cast<uint64_t>(0xd10203ffULL) << 13);
    acc = (acc + a1 + 0xa9026ffcULL) ^ 0x03cbf8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0245 | PC: 0x06c78c | FDE: 0x03cc28 | Size: 232 bytes [_ZN14BytePoolThreadD2Ev]
// Khung tháo gỡ #0245 | Địa chỉ PC: 0x06c78c | Địa chỉ FDE: 0x03cc28 | Kích thước: 232 bytes
//   0x06c78c: F81D0FF6  str      x22, [sp, #-0x30]!
//   0x06c790: A90153F5  stp      x21, x20, [sp, #0x10]
//   0x06c794: A9027BF3  stp      x19, x30, [sp, #0x20]
//   0x06c798: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_0245_0x06c78c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x06c78cULL ^ (static_cast<uint64_t>(0xf81d0ff6ULL) << 13);
    acc = (acc + a1 + 0xa90153f5ULL) ^ 0x03cc28ULL;
    acc ^= (acc >> 17) * 0x00e8ULL;
    return acc;
}

// FDE #0246 | PC: 0x06c874 | FDE: 0x03cc48 | Size: 72 bytes [_ZN14BytePoolThread11SetPriorityEi]
// Khung tháo gỡ #0246 | Địa chỉ PC: 0x06c874 | Địa chỉ FDE: 0x03cc48 | Kích thước: 72 bytes
//   0x06c874: A9BF7BF3  stp      x19, x30, [sp, #-0x10]!
//   0x06c878: B9401808  ldr      w8, [x0, #0x18]
//   0x06c87c: 2A0103F3  mov      w19, w1
//   0x06c880: 2A1F03E0  mov      w0, wzr
static inline uint64_t fde_func_0246_0x06c874(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x06c874ULL ^ (static_cast<uint64_t>(0xa9bf7bf3ULL) << 13);
    acc = (acc + a1 + 0xb9401808ULL) ^ 0x03cc48ULL;
    acc ^= (acc >> 17) * 0x0048ULL;
    return acc;
}

// FDE #0247 | PC: 0x06c8bc | FDE: 0x03cc60 | Size: 256 bytes [_ZN14ByteThreadPoolC1EPKcii]
// Khung tháo gỡ #0247 | Địa chỉ PC: 0x06c8bc | Địa chỉ FDE: 0x03cc60 | Kích thước: 256 bytes
//   0x06c8bc: D106C3FF  sub      sp, sp, #0x1b0
//   0x06c8c0: FD00A3E8  str      d8, [sp, #0x140]
//   0x06c8c4: A9156FFC  stp      x28, x27, [sp, #0x150]
//   0x06c8c8: A91667FA  stp      x26, x25, [sp, #0x160]
static inline uint64_t fde_func_0247_0x06c8bc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x06c8bcULL ^ (static_cast<uint64_t>(0xd106c3ffULL) << 13);
    acc = (acc + a1 + 0xfd00a3e8ULL) ^ 0x03cc60ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0248 | PC: 0x06cc8c | FDE: 0x03cc90 | Size: 152 bytes
// Khung tháo gỡ #0248 | Địa chỉ PC: 0x06cc8c | Địa chỉ FDE: 0x03cc90 | Kích thước: 152 bytes
//   0x06cc8c: D10443FF  sub      sp, sp, #0x110
//   0x06cc90: F9007BFC  str      x28, [sp, #0xf0]
//   0x06cc94: A9107BF3  stp      x19, x30, [sp, #0x100]
//   0x06cc98: A90817E4  stp      x4, x5, [sp, #0x80]
static inline uint64_t fde_func_0248_0x06cc8c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x06cc8cULL ^ (static_cast<uint64_t>(0xd10443ffULL) << 13);
    acc = (acc + a1 + 0xf9007bfcULL) ^ 0x03cc90ULL;
    acc ^= (acc >> 17) * 0x0098ULL;
    return acc;
}

// FDE #0249 | PC: 0x06cd24 | FDE: 0x03ccb0 | Size: 152 bytes [_ZN14ByteThreadPool4StopEv]
// Khung tháo gỡ #0249 | Địa chỉ PC: 0x06cd24 | Địa chỉ FDE: 0x03ccb0 | Kích thước: 152 bytes
//   0x06cd24: D10103FF  sub      sp, sp, #0x40
//   0x06cd28: A90253F5  stp      x21, x20, [sp, #0x20]
//   0x06cd2c: A9037BF3  stp      x19, x30, [sp, #0x30]
//   0x06cd30: D53BD055  mrs      x21, tpidr_el0
static inline uint64_t fde_func_0249_0x06cd24(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x06cd24ULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xa90253f5ULL) ^ 0x03ccb0ULL;
    acc ^= (acc >> 17) * 0x0098ULL;
    return acc;
}

// FDE #0250 | PC: 0x06cdbc | FDE: 0x03ccd0 | Size: 80 bytes [_ZN14ByteThreadPool4ExitEv]
// Khung tháo gỡ #0250 | Địa chỉ PC: 0x06cdbc | Địa chỉ FDE: 0x03ccd0 | Kích thước: 80 bytes
//   0x06cdbc: F81E0FF4  str      x20, [sp, #-0x20]!
//   0x06cdc0: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x06cdc4: 91018014  add      x20, x0, #0x60
//   0x06cdc8: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_0250_0x06cdbc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x06cdbcULL ^ (static_cast<uint64_t>(0xf81e0ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x03ccd0ULL;
    acc ^= (acc >> 17) * 0x0050ULL;
    return acc;
}

// FDE #0251 | PC: 0x06ce0c | FDE: 0x03ccf0 | Size: 256 bytes [_ZN14ByteThreadPoolD1Ev]
// Khung tháo gỡ #0251 | Địa chỉ PC: 0x06ce0c | Địa chỉ FDE: 0x03ccf0 | Kích thước: 256 bytes
//   0x06ce0c: A9BB6BFB  stp      x27, x26, [sp, #-0x50]!
//   0x06ce10: A90163F9  stp      x25, x24, [sp, #0x10]
//   0x06ce14: A9025BF7  stp      x23, x22, [sp, #0x20]
//   0x06ce18: A90353F5  stp      x21, x20, [sp, #0x30]
static inline uint64_t fde_func_0251_0x06ce0c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x06ce0cULL ^ (static_cast<uint64_t>(0xa9bb6bfbULL) << 13);
    acc = (acc + a1 + 0xa90163f9ULL) ^ 0x03ccf0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0252 | PC: 0x06d0a8 | FDE: 0x03cd18 | Size: 156 bytes [_ZN14ByteThreadPool12ClearAllTaskEv]
// Khung tháo gỡ #0252 | Địa chỉ PC: 0x06d0a8 | Địa chỉ FDE: 0x03cd18 | Kích thước: 156 bytes
//   0x06d0a8: A9BE53F5  stp      x21, x20, [sp, #-0x20]!
//   0x06d0ac: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x06d0b0: 91018013  add      x19, x0, #0x60
//   0x06d0b4: AA0003F4  mov      x20, x0
static inline uint64_t fde_func_0252_0x06d0a8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x06d0a8ULL ^ (static_cast<uint64_t>(0xa9be53f5ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x03cd18ULL;
    acc ^= (acc >> 17) * 0x009cULL;
    return acc;
}

// FDE #0253 | PC: 0x06d144 | FDE: 0x03cd38 | Size: 128 bytes [_ZN14ByteThreadPool11SetPriorityEi]
// Khung tháo gỡ #0253 | Địa chỉ PC: 0x06d144 | Địa chỉ FDE: 0x03cd38 | Kích thước: 128 bytes
//   0x06d144: A9BD5BF7  stp      x23, x22, [sp, #-0x30]!
//   0x06d148: A90153F5  stp      x21, x20, [sp, #0x10]
//   0x06d14c: A9027BF3  stp      x19, x30, [sp, #0x20]
//   0x06d150: A954DC16  ldp      x22, x23, [x0, #0x148]
static inline uint64_t fde_func_0253_0x06d144(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x06d144ULL ^ (static_cast<uint64_t>(0xa9bd5bf7ULL) << 13);
    acc = (acc + a1 + 0xa90153f5ULL) ^ 0x03cd38ULL;
    acc ^= (acc >> 17) * 0x0080ULL;
    return acc;
}

// FDE #0254 | PC: 0x06d1c4 | FDE: 0x03cd58 | Size: 256 bytes [_ZN14ByteThreadPool21SetMaxActiveThreadNumEi]
// Khung tháo gỡ #0254 | Địa chỉ PC: 0x06d1c4 | Địa chỉ FDE: 0x03cd58 | Kích thước: 256 bytes
//   0x06d1c4: D10103FF  sub      sp, sp, #0x40
//   0x06d1c8: F9000BF6  str      x22, [sp, #0x10]
//   0x06d1cc: A90253F5  stp      x21, x20, [sp, #0x20]
//   0x06d1d0: A9037BF3  stp      x19, x30, [sp, #0x30]
static inline uint64_t fde_func_0254_0x06d1c4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x06d1c4ULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xf9000bf6ULL) ^ 0x03cd58ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0255 | PC: 0x06d2dc | FDE: 0x03cd78 | Size: 256 bytes [_ZN14ByteThreadPool7AddTaskEP8ByteTask]
// Khung tháo gỡ #0255 | Địa chỉ PC: 0x06d2dc | Địa chỉ FDE: 0x03cd78 | Kích thước: 256 bytes
//   0x06d2dc: D10283FF  sub      sp, sp, #0xa0
//   0x06d2e0: A9046FFC  stp      x28, x27, [sp, #0x40]
//   0x06d2e4: A90567FA  stp      x26, x25, [sp, #0x50]
//   0x06d2e8: A9065FF8  stp      x24, x23, [sp, #0x60]
static inline uint64_t fde_func_0255_0x06d2dc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x06d2dcULL ^ (static_cast<uint64_t>(0xd10283ffULL) << 13);
    acc = (acc + a1 + 0xa9046ffcULL) ^ 0x03cd78ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0256 | PC: 0x06d8ec | FDE: 0x03cda8 | Size: 256 bytes
// Khung tháo gỡ #0256 | Địa chỉ PC: 0x06d8ec | Địa chỉ FDE: 0x03cda8 | Kích thước: 256 bytes
//   0x06d8ec: A9BC63F9  stp      x25, x24, [sp, #-0x40]!
//   0x06d8f0: A9015BF7  stp      x23, x22, [sp, #0x10]
//   0x06d8f4: A90253F5  stp      x21, x20, [sp, #0x20]
//   0x06d8f8: A9037BF3  stp      x19, x30, [sp, #0x30]
static inline uint64_t fde_func_0256_0x06d8ec(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x06d8ecULL ^ (static_cast<uint64_t>(0xa9bc63f9ULL) << 13);
    acc = (acc + a1 + 0xa9015bf7ULL) ^ 0x03cda8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0257 | PC: 0x06da18 | FDE: 0x03cdd0 | Size: 136 bytes [_ZN14ByteThreadPool7AddTaskENSt6__ndk18functionIFvmEEE]
// Khung tháo gỡ #0257 | Địa chỉ PC: 0x06da18 | Địa chỉ FDE: 0x03cdd0 | Kích thước: 136 bytes
//   0x06da18: A9BE53F5  stp      x21, x20, [sp, #-0x20]!
//   0x06da1c: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x06da20: AA0103F5  mov      x21, x1
//   0x06da24: 90000A81  adrp     x1, #0x1bd000
static inline uint64_t fde_func_0257_0x06da18(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x06da18ULL ^ (static_cast<uint64_t>(0xa9be53f5ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x03cdd0ULL;
    acc ^= (acc >> 17) * 0x0088ULL;
    return acc;
}

// FDE #0258 | PC: 0x06daa0 | FDE: 0x03cdf0 | Size: 56 bytes [_ZN14ByteThreadPool5StartEv]
// Khung tháo gỡ #0258 | Địa chỉ PC: 0x06daa0 | Địa chỉ FDE: 0x03cdf0 | Kích thước: 56 bytes
//   0x06daa0: F81E0FF4  str      x20, [sp, #-0x20]!
//   0x06daa4: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x06daa8: 91018014  add      x20, x0, #0x60
//   0x06daac: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_0258_0x06daa0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x06daa0ULL ^ (static_cast<uint64_t>(0xf81e0ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x03cdf0ULL;
    acc ^= (acc >> 17) * 0x0038ULL;
    return acc;
}

// FDE #0259 | PC: 0x06dad8 | FDE: 0x03ce10 | Size: 204 bytes [_ZN14ByteThreadPool14DrainTaskQueueEv]
// Khung tháo gỡ #0259 | Địa chỉ PC: 0x06dad8 | Địa chỉ FDE: 0x03ce10 | Kích thước: 204 bytes
//   0x06dad8: A9BE53F5  stp      x21, x20, [sp, #-0x20]!
//   0x06dadc: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x06dae0: 39406008  ldrb     w8, [x0, #0x18]
//   0x06dae4: 370005E8  tbnz     w8, #0, #0x6dba0
static inline uint64_t fde_func_0259_0x06dad8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x06dad8ULL ^ (static_cast<uint64_t>(0xa9be53f5ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x03ce10ULL;
    acc ^= (acc >> 17) * 0x00ccULL;
    return acc;
}

// FDE #0260 | PC: 0x06dba4 | FDE: 0x03ce30 | Size: 256 bytes [_ZN14ByteThreadPool10WaitFinishEbPNSt6__ndk16vectorIiNS0_9allocatorIiEEEE]
// Khung tháo gỡ #0260 | Địa chỉ PC: 0x06dba4 | Địa chỉ FDE: 0x03ce30 | Kích thước: 256 bytes
//   0x06dba4: D10143FF  sub      sp, sp, #0x50
//   0x06dba8: F90013F6  str      x22, [sp, #0x20]
//   0x06dbac: A90353F5  stp      x21, x20, [sp, #0x30]
//   0x06dbb0: A9047BF3  stp      x19, x30, [sp, #0x40]
static inline uint64_t fde_func_0260_0x06dba4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x06dba4ULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xf90013f6ULL) ^ 0x03ce30ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0261 | PC: 0x06dd70 | FDE: 0x03ce50 | Size: 52 bytes [_Z6mp_addPmPKmS1_mm]
// Khung tháo gỡ #0261 | Địa chỉ PC: 0x06dd70 | Địa chỉ FDE: 0x03ce50 | Kích thước: 52 bytes
//   0x06dd70: B4000163  cbz      x3, #0x6dd9c
//   0x06dd74: F8408428  ldr      x8, [x1], #8
//   0x06dd78: F8408449  ldr      x9, [x2], #8
//   0x06dd7c: AB080128  adds     x8, x9, x8
static inline uint64_t fde_func_0261_0x06dd70(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x06dd70ULL ^ (static_cast<uint64_t>(0xb4000163ULL) << 13);
    acc = (acc + a1 + 0xf8408428ULL) ^ 0x03ce50ULL;
    acc ^= (acc >> 17) * 0x0034ULL;
    return acc;
}

// FDE #0262 | PC: 0x06dda4 | FDE: 0x03ce68 | Size: 60 bytes [_Z6mp_subPmPKmS1_im]
// Khung tháo gỡ #0262 | Địa chỉ PC: 0x06dda4 | Địa chỉ FDE: 0x03ce68 | Kích thước: 60 bytes
//   0x06dda4: 7100047F  cmp      w3, #1
//   0x06dda8: 5400018B  b.lt     #0x6ddd8
//   0x06ddac: 2A0303E8  mov      w8, w3
//   0x06ddb0: F8408429  ldr      x9, [x1], #8
static inline uint64_t fde_func_0262_0x06dda4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x06dda4ULL ^ (static_cast<uint64_t>(0x7100047fULL) << 13);
    acc = (acc + a1 + 0x5400018bULL) ^ 0x03ce68ULL;
    acc ^= (acc >> 17) * 0x003cULL;
    return acc;
}

// FDE #0263 | PC: 0x06dde0 | FDE: 0x03ce80 | Size: 60 bytes [_Z6mp_negPmPKmi]
// Khung tháo gỡ #0263 | Địa chỉ PC: 0x06dde0 | Địa chỉ FDE: 0x03ce80 | Kích thước: 60 bytes
//   0x06dde0: 7100045F  cmp      w2, #1
//   0x06dde4: 5400018B  b.lt     #0x6de14
//   0x06dde8: AA0003E8  mov      x8, x0
//   0x06ddec: 2A0203E9  mov      w9, w2
static inline uint64_t fde_func_0263_0x06dde0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x06dde0ULL ^ (static_cast<uint64_t>(0x7100045fULL) << 13);
    acc = (acc + a1 + 0x5400018bULL) ^ 0x03ce80ULL;
    acc ^= (acc >> 17) * 0x003cULL;
    return acc;
}

// FDE #0264 | PC: 0x06de1c | FDE: 0x03ce98 | Size: 44 bytes [_Z7mp_mul1PmPKmmmm]
// Khung tháo gỡ #0264 | Địa chỉ PC: 0x06de1c | Địa chỉ FDE: 0x03ce98 | Kích thước: 44 bytes
//   0x06de1c: B4000122  cbz      x2, #0x6de40
//   0x06de20: F8408428  ldr      x8, [x1], #8
//   0x06de24: 9BC37D09  umulh    x9, x8, x3
//   0x06de28: 9B037D08  mul      x8, x8, x3
static inline uint64_t fde_func_0264_0x06de1c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x06de1cULL ^ (static_cast<uint64_t>(0xb4000122ULL) << 13);
    acc = (acc + a1 + 0xf8408428ULL) ^ 0x03ce98ULL;
    acc ^= (acc >> 17) * 0x002cULL;
    return acc;
}

// FDE #0265 | PC: 0x06de48 | FDE: 0x03ceb0 | Size: 112 bytes [_Z7mp_div1PmPKmmmm]
// Khung tháo gỡ #0265 | Địa chỉ PC: 0x06de48 | Địa chỉ FDE: 0x03ceb0 | Kích thước: 112 bytes
//   0x06de48: F81C0FF8  str      x24, [sp, #-0x40]!
//   0x06de4c: A9015BF7  stp      x23, x22, [sp, #0x10]
//   0x06de50: A90253F5  stp      x21, x20, [sp, #0x20]
//   0x06de54: A9037BF3  stp      x19, x30, [sp, #0x30]
static inline uint64_t fde_func_0265_0x06de48(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x06de48ULL ^ (static_cast<uint64_t>(0xf81c0ff8ULL) << 13);
    acc = (acc + a1 + 0xa9015bf7ULL) ^ 0x03ceb0ULL;
    acc ^= (acc >> 17) * 0x0070ULL;
    return acc;
}

// FDE #0266 | PC: 0x06deb8 | FDE: 0x03ced8 | Size: 60 bytes [_Z11mp_add_mul1PmPKmmm]
// Khung tháo gỡ #0266 | Địa chỉ PC: 0x06deb8 | Địa chỉ FDE: 0x03ced8 | Kích thước: 60 bytes
//   0x06deb8: AA1F03E8  mov      x8, xzr
//   0x06debc: B4000182  cbz      x2, #0x6deec
//   0x06dec0: F8408429  ldr      x9, [x1], #8
//   0x06dec4: F940000A  ldr      x10, [x0]
static inline uint64_t fde_func_0266_0x06deb8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x06deb8ULL ^ (static_cast<uint64_t>(0xaa1f03e8ULL) << 13);
    acc = (acc + a1 + 0xb4000182ULL) ^ 0x03ced8ULL;
    acc ^= (acc >> 17) * 0x003cULL;
    return acc;
}

// FDE #0267 | PC: 0x06def4 | FDE: 0x03cef0 | Size: 32 bytes [_Z14udiv1norm_initm]
// Khung tháo gỡ #0267 | Địa chỉ PC: 0x06def4 | Địa chỉ FDE: 0x03cef0 | Kích thước: 32 bytes
//   0x06def4: F81F0FFE  str      x30, [sp, #-0x10]!
//   0x06def8: AA0003E2  mov      x2, x0
//   0x06defc: AA2003E1  mvn      x1, x0
//   0x06df00: 92800000  mov      x0, #-1
static inline uint64_t fde_func_0267_0x06def4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x06def4ULL ^ (static_cast<uint64_t>(0xf81f0ffeULL) << 13);
    acc = (acc + a1 + 0xaa0003e2ULL) ^ 0x03cef0ULL;
    acc ^= (acc >> 17) * 0x0020ULL;
    return acc;
}

// FDE #0268 | PC: 0x06df14 | FDE: 0x03cf08 | Size: 88 bytes [_Z9udiv1normPmmmmm]
// Khung tháo gỡ #0268 | Địa chỉ PC: 0x06df14 | Địa chỉ FDE: 0x03cf08 | Kích thước: 88 bytes
//   0x06df14: 937FFC48  asr      x8, x2, #0x3f
//   0x06df18: 8A030109  and      x9, x8, x3
//   0x06df1c: CB080028  sub      x8, x1, x8
//   0x06df20: 8B020129  add      x9, x9, x2
static inline uint64_t fde_func_0268_0x06df14(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x06df14ULL ^ (static_cast<uint64_t>(0x937ffc48ULL) << 13);
    acc = (acc + a1 + 0x8a030109ULL) ^ 0x03cf08ULL;
    acc ^= (acc >> 17) * 0x0058ULL;
    return acc;
}

// FDE #0269 | PC: 0x06df6c | FDE: 0x03cf20 | Size: 256 bytes [_Z11mp_div1normPmPKmmmm]
// Khung tháo gỡ #0269 | Địa chỉ PC: 0x06df6c | Địa chỉ FDE: 0x03cf20 | Kích thước: 256 bytes
//   0x06df6c: A9BC63F9  stp      x25, x24, [sp, #-0x40]!
//   0x06df70: A9015BF7  stp      x23, x22, [sp, #0x10]
//   0x06df74: A90253F5  stp      x21, x20, [sp, #0x20]
//   0x06df78: A9037BF3  stp      x19, x30, [sp, #0x30]
static inline uint64_t fde_func_0269_0x06df6c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x06df6cULL ^ (static_cast<uint64_t>(0xa9bc63f9ULL) << 13);
    acc = (acc + a1 + 0xa9015bf7ULL) ^ 0x03cf20ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0270 | PC: 0x06e078 | FDE: 0x03cf48 | Size: 256 bytes [_Z10mp_divnormPmS_mPKmm]
// Khung tháo gỡ #0270 | Địa chỉ PC: 0x06e078 | Địa chỉ FDE: 0x03cf48 | Kích thước: 256 bytes
//   0x06e078: A9BB6BFB  stp      x27, x26, [sp, #-0x50]!
//   0x06e07c: A90163F9  stp      x25, x24, [sp, #0x10]
//   0x06e080: A9025BF7  stp      x23, x22, [sp, #0x20]
//   0x06e084: A90353F5  stp      x21, x20, [sp, #0x30]
static inline uint64_t fde_func_0270_0x06e078(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x06e078ULL ^ (static_cast<uint64_t>(0xa9bb6bfbULL) << 13);
    acc = (acc + a1 + 0xa90163f9ULL) ^ 0x03cf48ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0271 | PC: 0x06e3bc | FDE: 0x03cf70 | Size: 72 bytes [_Z6mp_shlPmPKmii]
// Khung tháo gỡ #0271 | Địa chỉ PC: 0x06e3bc | Địa chỉ FDE: 0x03cf70 | Kích thước: 72 bytes
//   0x06e3bc: 7100045F  cmp      w2, #1
//   0x06e3c0: 540001EB  b.lt     #0x6e3fc
//   0x06e3c4: 5280080A  mov      w10, #0x40
//   0x06e3c8: AA0003E8  mov      x8, x0
static inline uint64_t fde_func_0271_0x06e3bc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x06e3bcULL ^ (static_cast<uint64_t>(0x7100045fULL) << 13);
    acc = (acc + a1 + 0x540001ebULL) ^ 0x03cf70ULL;
    acc ^= (acc >> 17) * 0x0048ULL;
    return acc;
}

// FDE #0272 | PC: 0x06e404 | FDE: 0x03cf88 | Size: 96 bytes [_Z6mp_shrPmPKmiim]
// Khung tháo gỡ #0272 | Địa chỉ PC: 0x06e404 | Địa chỉ FDE: 0x03cf88 | Kích thước: 96 bytes
//   0x06e404: 7100045F  cmp      w2, #1
//   0x06e408: 2A0303E8  mov      w8, w3
//   0x06e40c: 5400022B  b.lt     #0x6e450
//   0x06e410: 5280080A  mov      w10, #0x40
static inline uint64_t fde_func_0272_0x06e404(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x06e404ULL ^ (static_cast<uint64_t>(0x7100045fULL) << 13);
    acc = (acc + a1 + 0x2a0303e8ULL) ^ 0x03cf88ULL;
    acc ^= (acc >> 17) * 0x0060ULL;
    return acc;
}

// FDE #0273 | PC: 0x06e464 | FDE: 0x03cfa0 | Size: 156 bytes [_Z13js_bigint_newP12LEPUSContexti]
// Khung tháo gỡ #0273 | Địa chỉ PC: 0x06e464 | Địa chỉ FDE: 0x03cfa0 | Kích thước: 156 bytes
//   0x06e464: F81E0FF4  str      x20, [sp, #-0x20]!
//   0x06e468: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x06e46c: 7140103F  cmp      w1, #4, lsl #12
//   0x06e470: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_0273_0x06e464(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x06e464ULL ^ (static_cast<uint64_t>(0xf81e0ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x03cfa0ULL;
    acc ^= (acc >> 17) * 0x009cULL;
    return acc;
}

// FDE #0274 | PC: 0x06e500 | FDE: 0x03cfc0 | Size: 20 bytes [_Z16js_bigint_set_siP11JSBigIntBufl]
// Khung tháo gỡ #0274 | Địa chỉ PC: 0x06e500 | Địa chỉ FDE: 0x03cfc0 | Kích thước: 20 bytes
//   0x06e500: D0FFFDE8  adrp     x8, #0x2c000
//   0x06e504: FD45B100  ldr      d0, [x8, #0xb60]
//   0x06e508: F9000401  str      x1, [x0, #8]
//   0x06e50c: FD000000  str      d0, [x0]
static inline uint64_t fde_func_0274_0x06e500(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x06e500ULL ^ (static_cast<uint64_t>(0xd0fffde8ULL) << 13);
    acc = (acc + a1 + 0xfd45b100ULL) ^ 0x03cfc0ULL;
    acc ^= (acc >> 17) * 0x0014ULL;
    return acc;
}

// FDE #0275 | PC: 0x06e514 | FDE: 0x03cfd8 | Size: 20 bytes [_Z18js_bigint_set_si64P11JSBigIntBufl]
// Khung tháo gỡ #0275 | Địa chỉ PC: 0x06e514 | Địa chỉ FDE: 0x03cfd8 | Kích thước: 20 bytes
//   0x06e514: D0FFFDE8  adrp     x8, #0x2c000
//   0x06e518: FD45B100  ldr      d0, [x8, #0xb60]
//   0x06e51c: F9000401  str      x1, [x0, #8]
//   0x06e520: FD000000  str      d0, [x0]
static inline uint64_t fde_func_0275_0x06e514(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x06e514ULL ^ (static_cast<uint64_t>(0xd0fffde8ULL) << 13);
    acc = (acc + a1 + 0xfd45b100ULL) ^ 0x03cfd8ULL;
    acc ^= (acc >> 17) * 0x0014ULL;
    return acc;
}

// FDE #0276 | PC: 0x06e528 | FDE: 0x03cff0 | Size: 124 bytes [_Z18js_bigint_new_si64P12LEPUSContextl]
// Khung tháo gỡ #0276 | Địa chỉ PC: 0x06e528 | Địa chỉ FDE: 0x03cff0 | Kích thước: 124 bytes
//   0x06e528: F81E0FF4  str      x20, [sp, #-0x20]!
//   0x06e52c: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x06e530: F9400808  ldr      x8, [x0, #0x10]
//   0x06e534: AA0103F4  mov      x20, x1
static inline uint64_t fde_func_0276_0x06e528(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x06e528ULL ^ (static_cast<uint64_t>(0xf81e0ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x03cff0ULL;
    acc ^= (acc >> 17) * 0x007cULL;
    return acc;
}

// FDE #0277 | PC: 0x06e5a4 | FDE: 0x03d010 | Size: 164 bytes [_Z18js_bigint_new_ui64P12LEPUSContextm]
// Khung tháo gỡ #0277 | Địa chỉ PC: 0x06e5a4 | Địa chỉ FDE: 0x03d010 | Kích thước: 164 bytes
//   0x06e5a4: F81E0FF4  str      x20, [sp, #-0x20]!
//   0x06e5a8: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x06e5ac: F9400809  ldr      x9, [x0, #0x10]
//   0x06e5b0: AA0103F4  mov      x20, x1
static inline uint64_t fde_func_0277_0x06e5a4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x06e5a4ULL ^ (static_cast<uint64_t>(0xf81e0ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x03d010ULL;
    acc ^= (acc >> 17) * 0x00a4ULL;
    return acc;
}

// FDE #0278 | PC: 0x06e648 | FDE: 0x03d030 | Size: 172 bytes [_Z16js_bigint_new_diP12LEPUSContextn]
// Khung tháo gỡ #0278 | Địa chỉ PC: 0x06e648 | Địa chỉ FDE: 0x03d030 | Kích thước: 172 bytes
//   0x06e648: A9BE53F5  stp      x21, x20, [sp, #-0x20]!
//   0x06e64c: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x06e650: F9400809  ldr      x9, [x0, #0x10]
//   0x06e654: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_0278_0x06e648(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x06e648ULL ^ (static_cast<uint64_t>(0xa9be53f5ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x03d030ULL;
    acc ^= (acc >> 17) * 0x00acULL;
    return acc;
}

// FDE #0279 | PC: 0x06e6f4 | FDE: 0x03d050 | Size: 244 bytes [_Z20js_bigint_normalize1P12LEPUSContextP8JSBigInti]
// Khung tháo gỡ #0279 | Địa chỉ PC: 0x06e6f4 | Địa chỉ FDE: 0x03d050 | Kích thước: 244 bytes
//   0x06e6f4: D100C3FF  sub      sp, sp, #0x30
//   0x06e6f8: A90153F5  stp      x21, x20, [sp, #0x10]
//   0x06e6fc: A9027BF3  stp      x19, x30, [sp, #0x20]
//   0x06e700: 937D7C48  sbfiz    x8, x2, #3, #0x20
static inline uint64_t fde_func_0279_0x06e6f4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x06e6f4ULL ^ (static_cast<uint64_t>(0xd100c3ffULL) << 13);
    acc = (acc + a1 + 0xa90153f5ULL) ^ 0x03d050ULL;
    acc ^= (acc >> 17) * 0x00f4ULL;
    return acc;
}

// FDE #0280 | PC: 0x06e7e8 | FDE: 0x03d070 | Size: 240 bytes [_Z19js_bigint_normalizeP12LEPUSContextP8JSBigInt]
// Khung tháo gỡ #0280 | Địa chỉ PC: 0x06e7e8 | Địa chỉ FDE: 0x03d070 | Kích thước: 240 bytes
//   0x06e7e8: D100C3FF  sub      sp, sp, #0x30
//   0x06e7ec: A90153F5  stp      x21, x20, [sp, #0x10]
//   0x06e7f0: A9027BF3  stp      x19, x30, [sp, #0x20]
//   0x06e7f4: B9800428  ldrsw    x8, [x1, #4]
static inline uint64_t fde_func_0280_0x06e7e8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x06e7e8ULL ^ (static_cast<uint64_t>(0xd100c3ffULL) << 13);
    acc = (acc + a1 + 0xa90153f5ULL) ^ 0x03d070ULL;
    acc ^= (acc >> 17) * 0x00f0ULL;
    return acc;
}

// FDE #0281 | PC: 0x06e8d8 | FDE: 0x03d090 | Size: 24 bytes [_Z14js_bigint_signPK8JSBigInt]
// Khung tháo gỡ #0281 | Địa chỉ PC: 0x06e8d8 | Địa chỉ FDE: 0x03d090 | Kích thước: 24 bytes
//   0x06e8d8: B9400408  ldr      w8, [x0, #4]
//   0x06e8dc: 51000508  sub      w8, w8, #1
//   0x06e8e0: 8B284C08  add      x8, x0, w8, uxtw #3
//   0x06e8e4: F9400508  ldr      x8, [x8, #8]
static inline uint64_t fde_func_0281_0x06e8d8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x06e8d8ULL ^ (static_cast<uint64_t>(0xb9400408ULL) << 13);
    acc = (acc + a1 + 0x51000508ULL) ^ 0x03d090ULL;
    acc ^= (acc >> 17) * 0x0018ULL;
    return acc;
}

// FDE #0282 | PC: 0x06e8f0 | FDE: 0x03d0a8 | Size: 44 bytes [_Z20js_bigint_get_si_satPK8JSBigInt]
// Khung tháo gỡ #0282 | Địa chỉ PC: 0x06e8f0 | Địa chỉ FDE: 0x03d0a8 | Kích thước: 44 bytes
//   0x06e8f0: B9400408  ldr      w8, [x0, #4]
//   0x06e8f4: 71000508  subs     w8, w8, #1
//   0x06e8f8: 54000061  b.ne     #0x6e904
//   0x06e8fc: F9400400  ldr      x0, [x0, #8]
static inline uint64_t fde_func_0282_0x06e8f0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x06e8f0ULL ^ (static_cast<uint64_t>(0xb9400408ULL) << 13);
    acc = (acc + a1 + 0x71000508ULL) ^ 0x03d0a8ULL;
    acc ^= (acc >> 17) * 0x002cULL;
    return acc;
}

// FDE #0283 | PC: 0x06e91c | FDE: 0x03d0c0 | Size: 256 bytes [_Z16js_bigint_extendP12LEPUSContextP8JSBigIntm]
// Khung tháo gỡ #0283 | Địa chỉ PC: 0x06e91c | Địa chỉ FDE: 0x03d0c0 | Kích thước: 256 bytes
//   0x06e91c: F81C0FF8  str      x24, [sp, #-0x40]!
//   0x06e920: A9015BF7  stp      x23, x22, [sp, #0x10]
//   0x06e924: A90253F5  stp      x21, x20, [sp, #0x20]
//   0x06e928: A9037BF3  stp      x19, x30, [sp, #0x30]
static inline uint64_t fde_func_0283_0x06e91c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x06e91cULL ^ (static_cast<uint64_t>(0xf81c0ff8ULL) << 13);
    acc = (acc + a1 + 0xa9015bf7ULL) ^ 0x03d0c0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0284 | PC: 0x06eac4 | FDE: 0x03d0e8 | Size: 256 bytes [_Z13js_bigint_addP12LEPUSContextPK8JSBigIntS3_i]
// Khung tháo gỡ #0284 | Địa chỉ PC: 0x06eac4 | Địa chỉ FDE: 0x03d0e8 | Kích thước: 256 bytes
//   0x06eac4: F81A0FFC  str      x28, [sp, #-0x60]!
//   0x06eac8: A9016BFB  stp      x27, x26, [sp, #0x10]
//   0x06eacc: A90263F9  stp      x25, x24, [sp, #0x20]
//   0x06ead0: A9035BF7  stp      x23, x22, [sp, #0x30]
static inline uint64_t fde_func_0284_0x06eac4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x06eac4ULL ^ (static_cast<uint64_t>(0xf81a0ffcULL) << 13);
    acc = (acc + a1 + 0xa9016bfbULL) ^ 0x03d0e8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0285 | PC: 0x06ed50 | FDE: 0x03d118 | Size: 84 bytes [_Z13js_bigint_negP12LEPUSContextPK8JSBigInt]
// Khung tháo gỡ #0285 | Địa chỉ PC: 0x06ed50 | Địa chỉ FDE: 0x03d118 | Kích thước: 84 bytes
//   0x06ed50: D100C3FF  sub      sp, sp, #0x30
//   0x06ed54: A9027BF3  stp      x19, x30, [sp, #0x20]
//   0x06ed58: D53BD053  mrs      x19, tpidr_el0
//   0x06ed5c: D0FFFDE8  adrp     x8, #0x2c000
static inline uint64_t fde_func_0285_0x06ed50(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x06ed50ULL ^ (static_cast<uint64_t>(0xd100c3ffULL) << 13);
    acc = (acc + a1 + 0xa9027bf3ULL) ^ 0x03d118ULL;
    acc ^= (acc >> 17) * 0x0054ULL;
    return acc;
}

// FDE #0286 | PC: 0x06eda4 | FDE: 0x03d130 | Size: 256 bytes [_Z13js_bigint_mulP12LEPUSContextPK8JSBigIntS3_]
// Khung tháo gỡ #0286 | Địa chỉ PC: 0x06eda4 | Địa chỉ FDE: 0x03d130 | Kích thước: 256 bytes
//   0x06eda4: A9BC63F9  stp      x25, x24, [sp, #-0x40]!
//   0x06eda8: A9015BF7  stp      x23, x22, [sp, #0x10]
//   0x06edac: A90253F5  stp      x21, x20, [sp, #0x20]
//   0x06edb0: A9037BF3  stp      x19, x30, [sp, #0x30]
static inline uint64_t fde_func_0286_0x06eda4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x06eda4ULL ^ (static_cast<uint64_t>(0xa9bc63f9ULL) << 13);
    acc = (acc + a1 + 0xa9015bf7ULL) ^ 0x03d130ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0287 | PC: 0x06f10c | FDE: 0x03d158 | Size: 256 bytes [_Z16js_bigint_divremP12LEPUSContextPK8JSBigIntS3_i]
// Khung tháo gỡ #0287 | Địa chỉ PC: 0x06f10c | Địa chỉ FDE: 0x03d158 | Kích thước: 256 bytes
//   0x06f10c: D102C3FF  sub      sp, sp, #0xb0
//   0x06f110: A9056FFC  stp      x28, x27, [sp, #0x50]
//   0x06f114: A90667FA  stp      x26, x25, [sp, #0x60]
//   0x06f118: A9075FF8  stp      x24, x23, [sp, #0x70]
static inline uint64_t fde_func_0287_0x06f10c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x06f10cULL ^ (static_cast<uint64_t>(0xd102c3ffULL) << 13);
    acc = (acc + a1 + 0xa9056ffcULL) ^ 0x03d158ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0288 | PC: 0x06fb7c | FDE: 0x03d188 | Size: 256 bytes [_Z15js_bigint_logicP12LEPUSContextPK8JSBigIntS3_10OPCodeEnum]
// Khung tháo gỡ #0288 | Địa chỉ PC: 0x06fb7c | Địa chỉ FDE: 0x03d188 | Kích thước: 256 bytes
//   0x06fb7c: D101C3FF  sub      sp, sp, #0x70
//   0x06fb80: A9016FFC  stp      x28, x27, [sp, #0x10]
//   0x06fb84: A90267FA  stp      x26, x25, [sp, #0x20]
//   0x06fb88: A9035FF8  stp      x24, x23, [sp, #0x30]
static inline uint64_t fde_func_0288_0x06fb7c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x06fb7cULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xa9016ffcULL) ^ 0x03d188ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0289 | PC: 0x0702b4 | FDE: 0x03d1b8 | Size: 216 bytes [_Z13js_bigint_notP12LEPUSContextPK8JSBigInt]
// Khung tháo gỡ #0289 | Địa chỉ PC: 0x0702b4 | Địa chỉ FDE: 0x03d1b8 | Kích thước: 216 bytes
//   0x0702b4: A9BE53F5  stp      x21, x20, [sp, #-0x20]!
//   0x0702b8: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x0702bc: B9400435  ldr      w21, [x1, #4]
//   0x0702c0: AA0003F4  mov      x20, x0
static inline uint64_t fde_func_0289_0x0702b4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0702b4ULL ^ (static_cast<uint64_t>(0xa9be53f5ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x03d1b8ULL;
    acc ^= (acc >> 17) * 0x00d8ULL;
    return acc;
}

// FDE #0290 | PC: 0x07038c | FDE: 0x03d1d8 | Size: 256 bytes [_Z13js_bigint_shlP12LEPUSContextPK8JSBigIntj]
// Khung tháo gỡ #0290 | Địa chỉ PC: 0x07038c | Địa chỉ FDE: 0x03d1d8 | Kích thước: 256 bytes
//   0x07038c: F81B0FFA  str      x26, [sp, #-0x50]!
//   0x070390: A90163F9  stp      x25, x24, [sp, #0x10]
//   0x070394: A9025BF7  stp      x23, x22, [sp, #0x20]
//   0x070398: A90353F5  stp      x21, x20, [sp, #0x30]
static inline uint64_t fde_func_0290_0x07038c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07038cULL ^ (static_cast<uint64_t>(0xf81b0ffaULL) << 13);
    acc = (acc + a1 + 0xa90163f9ULL) ^ 0x03d1d8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0291 | PC: 0x070604 | FDE: 0x03d200 | Size: 256 bytes [_Z13js_bigint_shrP12LEPUSContextPK8JSBigIntj]
// Khung tháo gỡ #0291 | Địa chỉ PC: 0x070604 | Địa chỉ FDE: 0x03d200 | Kích thước: 256 bytes
//   0x070604: A9BB6BFB  stp      x27, x26, [sp, #-0x50]!
//   0x070608: A90163F9  stp      x25, x24, [sp, #0x10]
//   0x07060c: A9025BF7  stp      x23, x22, [sp, #0x20]
//   0x070610: A90353F5  stp      x21, x20, [sp, #0x30]
static inline uint64_t fde_func_0291_0x070604(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x070604ULL ^ (static_cast<uint64_t>(0xa9bb6bfbULL) << 13);
    acc = (acc + a1 + 0xa90163f9ULL) ^ 0x03d200ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0292 | PC: 0x070924 | FDE: 0x03d228 | Size: 256 bytes [_Z13js_bigint_powP12LEPUSContextPK8JSBigIntPS1_]
// Khung tháo gỡ #0292 | Địa chỉ PC: 0x070924 | Địa chỉ FDE: 0x03d228 | Kích thước: 256 bytes
//   0x070924: A9BB6BFB  stp      x27, x26, [sp, #-0x50]!
//   0x070928: A90163F9  stp      x25, x24, [sp, #0x10]
//   0x07092c: A9025BF7  stp      x23, x22, [sp, #0x20]
//   0x070930: A90353F5  stp      x21, x20, [sp, #0x30]
static inline uint64_t fde_func_0292_0x070924(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x070924ULL ^ (static_cast<uint64_t>(0xa9bb6bfbULL) << 13);
    acc = (acc + a1 + 0xa90163f9ULL) ^ 0x03d228ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0293 | PC: 0x070cb0 | FDE: 0x03d250 | Size: 256 bytes [_Z22js_bigint_get_mant_expP12LEPUSContextPiPK8JSBigInt]
// Khung tháo gỡ #0293 | Địa chỉ PC: 0x070cb0 | Địa chỉ FDE: 0x03d250 | Kích thước: 256 bytes
//   0x070cb0: B9400448  ldr      w8, [x2, #4]
//   0x070cb4: AA1F03EB  mov      x11, xzr
//   0x070cb8: 51000509  sub      w9, w8, #1
//   0x070cbc: 8B294C49  add      x9, x2, w9, uxtw #3
static inline uint64_t fde_func_0293_0x070cb0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x070cb0ULL ^ (static_cast<uint64_t>(0xb9400448ULL) << 13);
    acc = (acc + a1 + 0xaa1f03ebULL) ^ 0x03d250ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0294 | PC: 0x070db4 | FDE: 0x03d268 | Size: 40 bytes [_Z8shr_rndnmi]
// Khung tháo gỡ #0294 | Địa chỉ PC: 0x070db4 | Địa chỉ FDE: 0x03d268 | Kích thước: 40 bytes
//   0x070db4: 51000429  sub      w9, w1, #1
//   0x070db8: 1280000A  mov      w10, #-1
//   0x070dbc: 1AC92149  lsl      w9, w10, w9
//   0x070dc0: 9AC12408  lsr      x8, x0, x1
static inline uint64_t fde_func_0294_0x070db4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x070db4ULL ^ (static_cast<uint64_t>(0x51000429ULL) << 13);
    acc = (acc + a1 + 0x1280000aULL) ^ 0x03d268ULL;
    acc ^= (acc >> 17) * 0x0028ULL;
    return acc;
}

// FDE #0295 | PC: 0x070ddc | FDE: 0x03d280 | Size: 160 bytes [_Z20js_bigint_to_float64P12LEPUSContextPK8JSBigInt]
// Khung tháo gỡ #0295 | Địa chỉ PC: 0x070ddc | Địa chỉ FDE: 0x03d280 | Kích thước: 160 bytes
//   0x070ddc: D10083FF  sub      sp, sp, #0x20
//   0x070de0: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x070de4: B9400428  ldr      w8, [x1, #4]
//   0x070de8: AA0103E2  mov      x2, x1
static inline uint64_t fde_func_0295_0x070ddc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x070ddcULL ^ (static_cast<uint64_t>(0xd10083ffULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x03d280ULL;
    acc ^= (acc >> 17) * 0x00a0ULL;
    return acc;
}

// FDE #0296 | PC: 0x070e7c | FDE: 0x03d298 | Size: 256 bytes [_Z22js_bigint_from_float64P12LEPUSContextPid]
// Khung tháo gỡ #0296 | Địa chỉ PC: 0x070e7c | Địa chỉ FDE: 0x03d298 | Kích thước: 256 bytes
//   0x070e7c: D10103FF  sub      sp, sp, #0x40
//   0x070e80: F90013F4  str      x20, [sp, #0x20]
//   0x070e84: A9037BF3  stp      x19, x30, [sp, #0x30]
//   0x070e88: D53BD054  mrs      x20, tpidr_el0
static inline uint64_t fde_func_0296_0x070e7c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x070e7cULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xf90013f4ULL) ^ 0x03d298ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0297 | PC: 0x070fc0 | FDE: 0x03d2b8 | Size: 236 bytes [_Z21js_bigint_float64_cmpP12LEPUSContextPK8JSBigIntd]
// Khung tháo gỡ #0297 | Địa chỉ PC: 0x070fc0 | Địa chỉ FDE: 0x03d2b8 | Kích thước: 236 bytes
//   0x070fc0: D100C3FF  sub      sp, sp, #0x30
//   0x070fc4: A90153F5  stp      x21, x20, [sp, #0x10]
//   0x070fc8: A9027BF3  stp      x19, x30, [sp, #0x20]
//   0x070fcc: 9E660014  fmov     x20, d0
static inline uint64_t fde_func_0297_0x070fc0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x070fc0ULL ^ (static_cast<uint64_t>(0xd100c3ffULL) << 13);
    acc = (acc + a1 + 0xa90153f5ULL) ^ 0x03d2b8ULL;
    acc ^= (acc >> 17) * 0x00ecULL;
    return acc;
}

// FDE #0298 | PC: 0x0710ac | FDE: 0x03d2d8 | Size: 156 bytes [_Z13js_bigint_cmpP12LEPUSContextPK8JSBigIntS3_]
// Khung tháo gỡ #0298 | Địa chỉ PC: 0x0710ac | Địa chỉ FDE: 0x03d2d8 | Kích thước: 156 bytes
//   0x0710ac: B9400429  ldr      w9, [x1, #4]
//   0x0710b0: B940044B  ldr      w11, [x2, #4]
//   0x0710b4: 51000528  sub      w8, w9, #1
//   0x0710b8: 5100056A  sub      w10, w11, #1
static inline uint64_t fde_func_0298_0x0710ac(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0710acULL ^ (static_cast<uint64_t>(0xb9400429ULL) << 13);
    acc = (acc + a1 + 0xb940044bULL) ^ 0x03d2d8ULL;
    acc ^= (acc >> 17) * 0x009cULL;
    return acc;
}

// FDE #0299 | PC: 0x071148 | FDE: 0x03d2f0 | Size: 256 bytes [_Z21js_bigint_from_stringP12LEPUSContextPKci]
// Khung tháo gỡ #0299 | Địa chỉ PC: 0x071148 | Địa chỉ FDE: 0x03d2f0 | Kích thước: 256 bytes
//   0x071148: D10243FF  sub      sp, sp, #0x90
//   0x07114c: A9036FFC  stp      x28, x27, [sp, #0x30]
//   0x071150: A90467FA  stp      x26, x25, [sp, #0x40]
//   0x071154: A9055FF8  stp      x24, x23, [sp, #0x50]
static inline uint64_t fde_func_0299_0x071148(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x071148ULL ^ (static_cast<uint64_t>(0xd10243ffULL) << 13);
    acc = (acc + a1 + 0xa9036ffcULL) ^ 0x03d2f0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0300 | PC: 0x071670 | FDE: 0x03d320 | Size: 100 bytes [_Z9js_u64toaPclj]
// Khung tháo gỡ #0300 | Địa chỉ PC: 0x071670 | Địa chỉ FDE: 0x03d320 | Kích thước: 100 bytes
//   0x071670: 7100285F  cmp      w2, #0xa
//   0x071674: 540001A1  b.ne     #0x716a8
//   0x071678: B202E7E8  mov      x8, #-0x3333333333333334
//   0x07167c: F29999A8  movk     x8, #0xcccd
static inline uint64_t fde_func_0300_0x071670(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x071670ULL ^ (static_cast<uint64_t>(0x7100285fULL) << 13);
    acc = (acc + a1 + 0x540001a1ULL) ^ 0x03d320ULL;
    acc ^= (acc >> 17) * 0x0064ULL;
    return acc;
}

// FDE #0301 | PC: 0x0716d4 | FDE: 0x03d338 | Size: 116 bytes [_Z9limb_to_aPcmji]
// Khung tháo gỡ #0301 | Địa chỉ PC: 0x0716d4 | Địa chỉ FDE: 0x03d338 | Kích thước: 116 bytes
//   0x0716d4: 7100285F  cmp      w2, #0xa
//   0x0716d8: 540001E1  b.ne     #0x71714
//   0x0716dc: 7100047F  cmp      w3, #1
//   0x0716e0: 5400032B  b.lt     #0x71744
static inline uint64_t fde_func_0301_0x0716d4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0716d4ULL ^ (static_cast<uint64_t>(0x7100285fULL) << 13);
    acc = (acc + a1 + 0x540001e1ULL) ^ 0x03d338ULL;
    acc ^= (acc >> 17) * 0x0074ULL;
    return acc;
}

// FDE #0302 | PC: 0x071748 | FDE: 0x03d350 | Size: 256 bytes [_Z7js_atofP12LEPUSContextPKcPS2_ii]
// Khung tháo gỡ #0302 | Địa chỉ PC: 0x071748 | Địa chỉ FDE: 0x03d350 | Kích thước: 256 bytes
//   0x071748: D106C3FF  sub      sp, sp, #0x1b0
//   0x07174c: A9156FFC  stp      x28, x27, [sp, #0x150]
//   0x071750: A91667FA  stp      x26, x25, [sp, #0x160]
//   0x071754: A9175FF8  stp      x24, x23, [sp, #0x170]
static inline uint64_t fde_func_0302_0x071748(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x071748ULL ^ (static_cast<uint64_t>(0xd106c3ffULL) << 13);
    acc = (acc + a1 + 0xa9156ffcULL) ^ 0x03d350ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0303 | PC: 0x072158 | FDE: 0x03d380 | Size: 256 bytes [_Z17js_compare_bigintP12LEPUSContext10OPCodeEnum10LEPUSValueS2_]
// Khung tháo gỡ #0303 | Địa chỉ PC: 0x072158 | Địa chỉ FDE: 0x03d380 | Kích thước: 256 bytes
//   0x072158: D10243FF  sub      sp, sp, #0x90
//   0x07215c: A9036FFC  stp      x28, x27, [sp, #0x30]
//   0x072160: A90467FA  stp      x26, x25, [sp, #0x40]
//   0x072164: A9055FF8  stp      x24, x23, [sp, #0x50]
static inline uint64_t fde_func_0303_0x072158(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x072158ULL ^ (static_cast<uint64_t>(0xd10243ffULL) << 13);
    acc = (acc + a1 + 0xa9036ffcULL) ^ 0x03d380ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0304 | PC: 0x07290c | FDE: 0x03d3b0 | Size: 256 bytes [_Z20js_bigint_to_string1P12LEPUSContext10LEPUSValuei]
// Khung tháo gỡ #0304 | Địa chỉ PC: 0x07290c | Địa chỉ FDE: 0x03d3b0 | Kích thước: 256 bytes
//   0x07290c: D10343FF  sub      sp, sp, #0xd0
//   0x072910: A9076FFC  stp      x28, x27, [sp, #0x70]
//   0x072914: A90867FA  stp      x26, x25, [sp, #0x80]
//   0x072918: A9095FF8  stp      x24, x23, [sp, #0x90]
static inline uint64_t fde_func_0304_0x07290c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07290cULL ^ (static_cast<uint64_t>(0xd10343ffULL) << 13);
    acc = (acc + a1 + 0xa9076ffcULL) ^ 0x03d3b0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0305 | PC: 0x072f58 | FDE: 0x03d3e0 | Size: 256 bytes [_Z8js_dtoa2P12LEPUSContextdiii]
// Khung tháo gỡ #0305 | Địa chỉ PC: 0x072f58 | Địa chỉ FDE: 0x03d3e0 | Kích thước: 256 bytes
//   0x072f58: FC1A0FE8  str      d8, [sp, #-0x60]!
//   0x072f5c: F90007FC  str      x28, [sp, #8]
//   0x072f60: A9016BFB  stp      x27, x26, [sp, #0x10]
//   0x072f64: A90263F9  stp      x25, x24, [sp, #0x20]
static inline uint64_t fde_func_0305_0x072f58(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x072f58ULL ^ (static_cast<uint64_t>(0xfc1a0fe8ULL) << 13);
    acc = (acc + a1 + 0xf90007fcULL) ^ 0x03d3e0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0306 | PC: 0x0730fc | FDE: 0x03d410 | Size: 152 bytes [LEPUS_NewBigInt64]
// Khung tháo gỡ #0306 | Địa chỉ PC: 0x0730fc | Địa chỉ FDE: 0x03d410 | Kích thước: 152 bytes
//   0x0730fc: F81E0FF4  str      x20, [sp, #-0x20]!
//   0x073100: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x073104: F9400808  ldr      x8, [x0, #0x10]
//   0x073108: AA0103F4  mov      x20, x1
static inline uint64_t fde_func_0306_0x0730fc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0730fcULL ^ (static_cast<uint64_t>(0xf81e0ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x03d410ULL;
    acc ^= (acc >> 17) * 0x0098ULL;
    return acc;
}

// FDE #0307 | PC: 0x073194 | FDE: 0x03d430 | Size: 192 bytes [LEPUS_NewBigUint64]
// Khung tháo gỡ #0307 | Địa chỉ PC: 0x073194 | Địa chỉ FDE: 0x03d430 | Kích thước: 192 bytes
//   0x073194: F81E0FF4  str      x20, [sp, #-0x20]!
//   0x073198: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x07319c: F9400809  ldr      x9, [x0, #0x10]
//   0x0731a0: AA0103F4  mov      x20, x1
static inline uint64_t fde_func_0307_0x073194(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x073194ULL ^ (static_cast<uint64_t>(0xf81e0ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x03d430ULL;
    acc ^= (acc >> 17) * 0x00c0ULL;
    return acc;
}

// FDE #0308 | PC: 0x073254 | FDE: 0x03d450 | Size: 60 bytes [strstart]
// Khung tháo gỡ #0308 | Địa chỉ PC: 0x073254 | Địa chỉ FDE: 0x03d450 | Kích thước: 60 bytes
//   0x073254: 39400029  ldrb     w9, [x1]
//   0x073258: 34000109  cbz      w9, #0x73278
//   0x07325c: 91000428  add      x8, x1, #1
//   0x073260: 3940000A  ldrb     w10, [x0]
static inline uint64_t fde_func_0308_0x073254(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x073254ULL ^ (static_cast<uint64_t>(0x39400029ULL) << 13);
    acc = (acc + a1 + 0x34000109ULL) ^ 0x03d450ULL;
    acc ^= (acc >> 17) * 0x003cULL;
    return acc;
}

// FDE #0309 | PC: 0x073290 | FDE: 0x03d468 | Size: 256 bytes
// Khung tháo gỡ #0309 | Địa chỉ PC: 0x073290 | Địa chỉ FDE: 0x03d468 | Kích thước: 256 bytes
//   0x073290: D10703FF  sub      sp, sp, #0x1c0
//   0x073294: A91863FC  stp      x28, x24, [sp, #0x180]
//   0x073298: A9195BF7  stp      x23, x22, [sp, #0x190]
//   0x07329c: A91A53F5  stp      x21, x20, [sp, #0x1a0]
static inline uint64_t fde_func_0309_0x073290(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x073290ULL ^ (static_cast<uint64_t>(0xd10703ffULL) << 13);
    acc = (acc + a1 + 0xa91863fcULL) ^ 0x03d468ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0310 | PC: 0x073474 | FDE: 0x03d490 | Size: 240 bytes [unicode_to_utf8]
// Khung tháo gỡ #0310 | Địa chỉ PC: 0x073474 | Địa chỉ FDE: 0x03d490 | Kích thước: 240 bytes
//   0x073474: 7101FC3F  cmp      w1, #0x7f
//   0x073478: 540000A8  b.hi     #0x7348c
//   0x07347c: AA0003E9  mov      x9, x0
//   0x073480: 38001521  strb     w1, [x9], #1
static inline uint64_t fde_func_0310_0x073474(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x073474ULL ^ (static_cast<uint64_t>(0x7101fc3fULL) << 13);
    acc = (acc + a1 + 0x540000a8ULL) ^ 0x03d490ULL;
    acc ^= (acc >> 17) * 0x00f0ULL;
    return acc;
}

// FDE #0311 | PC: 0x073564 | FDE: 0x03d4a8 | Size: 180 bytes [unicode_from_utf8]
// Khung tháo gỡ #0311 | Địa chỉ PC: 0x073564 | Địa chỉ FDE: 0x03d4a8 | Kích thước: 180 bytes
//   0x073564: 38C01409  ldrsb    w9, [x0], #1
//   0x073568: 12001D28  and      w8, w9, #0xff
//   0x07356c: 37F80089  tbnz     w9, #0x1f, #0x7357c
//   0x073570: F9000040  str      x0, [x2]
static inline uint64_t fde_func_0311_0x073564(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x073564ULL ^ (static_cast<uint64_t>(0x38c01409ULL) << 13);
    acc = (acc + a1 + 0x12001d28ULL) ^ 0x03d4a8ULL;
    acc ^= (acc >> 17) * 0x00b4ULL;
    return acc;
}

// FDE #0312 | PC: 0x073618 | FDE: 0x03d4c0 | Size: 256 bytes [rqsort]
// Khung tháo gỡ #0312 | Địa chỉ PC: 0x073618 | Địa chỉ FDE: 0x03d4c0 | Kích thước: 256 bytes
//   0x073618: A9BA6FFC  stp      x28, x27, [sp, #-0x60]!
//   0x07361c: A90167FA  stp      x26, x25, [sp, #0x10]
//   0x073620: A9025FF8  stp      x24, x23, [sp, #0x20]
//   0x073624: A90357F6  stp      x22, x21, [sp, #0x30]
static inline uint64_t fde_func_0312_0x073618(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x073618ULL ^ (static_cast<uint64_t>(0xa9ba6ffcULL) << 13);
    acc = (acc + a1 + 0xa90167faULL) ^ 0x03d4c0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0313 | PC: 0x073c68 | FDE: 0x03d4f0 | Size: 28 bytes
// Khung tháo gỡ #0313 | Địa chỉ PC: 0x073c68 | Địa chỉ FDE: 0x03d4f0 | Kích thước: 28 bytes
//   0x073c68: F9400028  ldr      x8, [x1]
//   0x073c6c: 3DC00000  ldr      q0, [x0]
//   0x073c70: F9000008  str      x8, [x0]
//   0x073c74: F9400428  ldr      x8, [x1, #8]
static inline uint64_t fde_func_0313_0x073c68(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x073c68ULL ^ (static_cast<uint64_t>(0xf9400028ULL) << 13);
    acc = (acc + a1 + 0x3dc00000ULL) ^ 0x03d4f0ULL;
    acc ^= (acc >> 17) * 0x001cULL;
    return acc;
}

// FDE #0314 | PC: 0x073c84 | FDE: 0x03d508 | Size: 176 bytes
// Khung tháo gỡ #0314 | Địa chỉ PC: 0x073c84 | Địa chỉ FDE: 0x03d508 | Kích thước: 176 bytes
//   0x073c84: D344FC48  lsr      x8, x2, #4
//   0x073c88: B4000548  cbz      x8, #0x73d30
//   0x073c8c: F101005F  cmp      x2, #0x40
//   0x073c90: 54000062  b.hs     #0x73c9c
static inline uint64_t fde_func_0314_0x073c84(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x073c84ULL ^ (static_cast<uint64_t>(0xd344fc48ULL) << 13);
    acc = (acc + a1 + 0xb4000548ULL) ^ 0x03d508ULL;
    acc ^= (acc >> 17) * 0x00b0ULL;
    return acc;
}

// FDE #0315 | PC: 0x073d34 | FDE: 0x03d520 | Size: 20 bytes
// Khung tháo gỡ #0315 | Địa chỉ PC: 0x073d34 | Địa chỉ FDE: 0x03d520 | Kích thước: 20 bytes
//   0x073d34: F9400028  ldr      x8, [x1]
//   0x073d38: F9400009  ldr      x9, [x0]
//   0x073d3c: F9000008  str      x8, [x0]
//   0x073d40: F9000029  str      x9, [x1]
static inline uint64_t fde_func_0315_0x073d34(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x073d34ULL ^ (static_cast<uint64_t>(0xf9400028ULL) << 13);
    acc = (acc + a1 + 0xf9400009ULL) ^ 0x03d520ULL;
    acc ^= (acc >> 17) * 0x0014ULL;
    return acc;
}

// FDE #0316 | PC: 0x073d48 | FDE: 0x03d538 | Size: 152 bytes
// Khung tháo gỡ #0316 | Địa chỉ PC: 0x073d48 | Địa chỉ FDE: 0x03d538 | Kích thước: 152 bytes
//   0x073d48: D343FC48  lsr      x8, x2, #3
//   0x073d4c: B4000488  cbz      x8, #0x73ddc
//   0x073d50: F100805F  cmp      x2, #0x20
//   0x073d54: 54000062  b.hs     #0x73d60
static inline uint64_t fde_func_0316_0x073d48(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x073d48ULL ^ (static_cast<uint64_t>(0xd343fc48ULL) << 13);
    acc = (acc + a1 + 0xb4000488ULL) ^ 0x03d538ULL;
    acc ^= (acc >> 17) * 0x0098ULL;
    return acc;
}

// FDE #0317 | PC: 0x073de0 | FDE: 0x03d550 | Size: 20 bytes
// Khung tháo gỡ #0317 | Địa chỉ PC: 0x073de0 | Địa chỉ FDE: 0x03d550 | Kích thước: 20 bytes
//   0x073de0: B9400028  ldr      w8, [x1]
//   0x073de4: B9400009  ldr      w9, [x0]
//   0x073de8: B9000008  str      w8, [x0]
//   0x073dec: B9000029  str      w9, [x1]
static inline uint64_t fde_func_0317_0x073de0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x073de0ULL ^ (static_cast<uint64_t>(0xb9400028ULL) << 13);
    acc = (acc + a1 + 0xb9400009ULL) ^ 0x03d550ULL;
    acc ^= (acc >> 17) * 0x0014ULL;
    return acc;
}

// FDE #0318 | PC: 0x073df4 | FDE: 0x03d568 | Size: 152 bytes
// Khung tháo gỡ #0318 | Địa chỉ PC: 0x073df4 | Địa chỉ FDE: 0x03d568 | Kích thước: 152 bytes
//   0x073df4: D342FC48  lsr      x8, x2, #2
//   0x073df8: B4000488  cbz      x8, #0x73e88
//   0x073dfc: F100805F  cmp      x2, #0x20
//   0x073e00: 54000062  b.hs     #0x73e0c
static inline uint64_t fde_func_0318_0x073df4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x073df4ULL ^ (static_cast<uint64_t>(0xd342fc48ULL) << 13);
    acc = (acc + a1 + 0xb4000488ULL) ^ 0x03d568ULL;
    acc ^= (acc >> 17) * 0x0098ULL;
    return acc;
}

// FDE #0319 | PC: 0x073e8c | FDE: 0x03d580 | Size: 20 bytes
// Khung tháo gỡ #0319 | Địa chỉ PC: 0x073e8c | Địa chỉ FDE: 0x03d580 | Kích thước: 20 bytes
//   0x073e8c: 79400028  ldrh     w8, [x1]
//   0x073e90: 79400009  ldrh     w9, [x0]
//   0x073e94: 79000008  strh     w8, [x0]
//   0x073e98: 79000029  strh     w9, [x1]
static inline uint64_t fde_func_0319_0x073e8c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x073e8cULL ^ (static_cast<uint64_t>(0x79400028ULL) << 13);
    acc = (acc + a1 + 0x79400009ULL) ^ 0x03d580ULL;
    acc ^= (acc >> 17) * 0x0014ULL;
    return acc;
}

// FDE #0320 | PC: 0x073ea0 | FDE: 0x03d598 | Size: 152 bytes
// Khung tháo gỡ #0320 | Địa chỉ PC: 0x073ea0 | Địa chỉ FDE: 0x03d598 | Kích thước: 152 bytes
//   0x073ea0: D341FC48  lsr      x8, x2, #1
//   0x073ea4: B4000488  cbz      x8, #0x73f34
//   0x073ea8: F100805F  cmp      x2, #0x20
//   0x073eac: 54000062  b.hs     #0x73eb8
static inline uint64_t fde_func_0320_0x073ea0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x073ea0ULL ^ (static_cast<uint64_t>(0xd341fc48ULL) << 13);
    acc = (acc + a1 + 0xb4000488ULL) ^ 0x03d598ULL;
    acc ^= (acc >> 17) * 0x0098ULL;
    return acc;
}

// FDE #0321 | PC: 0x073f38 | FDE: 0x03d5b0 | Size: 20 bytes
// Khung tháo gỡ #0321 | Địa chỉ PC: 0x073f38 | Địa chỉ FDE: 0x03d5b0 | Kích thước: 20 bytes
//   0x073f38: 39400028  ldrb     w8, [x1]
//   0x073f3c: 39400009  ldrb     w9, [x0]
//   0x073f40: 39000008  strb     w8, [x0]
//   0x073f44: 39000029  strb     w9, [x1]
static inline uint64_t fde_func_0321_0x073f38(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x073f38ULL ^ (static_cast<uint64_t>(0x39400028ULL) << 13);
    acc = (acc + a1 + 0x39400009ULL) ^ 0x03d5b0ULL;
    acc ^= (acc >> 17) * 0x0014ULL;
    return acc;
}

// FDE #0322 | PC: 0x073f4c | FDE: 0x03d5c8 | Size: 148 bytes
// Khung tháo gỡ #0322 | Địa chỉ PC: 0x073f4c | Địa chỉ FDE: 0x03d5c8 | Kích thước: 148 bytes
//   0x073f4c: B4000482  cbz      x2, #0x73fdc
//   0x073f50: F100805F  cmp      x2, #0x20
//   0x073f54: 54000062  b.hs     #0x73f60
//   0x073f58: AA0103E8  mov      x8, x1
static inline uint64_t fde_func_0322_0x073f4c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x073f4cULL ^ (static_cast<uint64_t>(0xb4000482ULL) << 13);
    acc = (acc + a1 + 0xf100805fULL) ^ 0x03d5c8ULL;
    acc ^= (acc >> 17) * 0x0094ULL;
    return acc;
}

// FDE #0323 | PC: 0x073fe0 | FDE: 0x03d5e0 | Size: 136 bytes [_Z6u32toaPcj]
// Khung tháo gỡ #0323 | Địa chỉ PC: 0x073fe0 | Địa chỉ FDE: 0x03d5e0 | Kích thước: 136 bytes
//   0x073fe0: D10103FF  sub      sp, sp, #0x40
//   0x073fe4: F90013F4  str      x20, [sp, #0x20]
//   0x073fe8: A9037BF3  stp      x19, x30, [sp, #0x30]
//   0x073fec: D53BD054  mrs      x20, tpidr_el0
static inline uint64_t fde_func_0323_0x073fe0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x073fe0ULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xf90013f4ULL) ^ 0x03d5e0ULL;
    acc ^= (acc >> 17) * 0x0088ULL;
    return acc;
}

// FDE #0324 | PC: 0x074068 | FDE: 0x03d600 | Size: 232 bytes [_Z6i32toaPci]
// Khung tháo gỡ #0324 | Địa chỉ PC: 0x074068 | Địa chỉ FDE: 0x03d600 | Kích thước: 232 bytes
//   0x074068: D10103FF  sub      sp, sp, #0x40
//   0x07406c: F90013F4  str      x20, [sp, #0x20]
//   0x074070: A9037BF3  stp      x19, x30, [sp, #0x30]
//   0x074074: D53BD054  mrs      x20, tpidr_el0
static inline uint64_t fde_func_0324_0x074068(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x074068ULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xf90013f4ULL) ^ 0x03d600ULL;
    acc ^= (acc >> 17) * 0x00e8ULL;
    return acc;
}

// FDE #0325 | PC: 0x074150 | FDE: 0x03d620 | Size: 256 bytes [_Z6u64toaPcm]
// Khung tháo gỡ #0325 | Địa chỉ PC: 0x074150 | Địa chỉ FDE: 0x03d620 | Kích thước: 256 bytes
//   0x074150: D101C3FF  sub      sp, sp, #0x70
//   0x074154: F90013FA  str      x26, [sp, #0x20]
//   0x074158: A90363F9  stp      x25, x24, [sp, #0x30]
//   0x07415c: A9045BF7  stp      x23, x22, [sp, #0x40]
static inline uint64_t fde_func_0325_0x074150(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x074150ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xf90013faULL) ^ 0x03d620ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0326 | PC: 0x074550 | FDE: 0x03d648 | Size: 40 bytes [_Z6i64toaPcl]
// Khung tháo gỡ #0326 | Địa chỉ PC: 0x074550 | Địa chỉ FDE: 0x03d648 | Kích thước: 40 bytes
//   0x074550: B7F80041  tbnz     x1, #0x3f, #0x74558
//   0x074554: 17FFFEFF  b        #0x74150
//   0x074558: F81F0FFE  str      x30, [sp, #-0x10]!
//   0x07455c: 528005A8  mov      w8, #0x2d
static inline uint64_t fde_func_0326_0x074550(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x074550ULL ^ (static_cast<uint64_t>(0xb7f80041ULL) << 13);
    acc = (acc + a1 + 0x17fffeffULL) ^ 0x03d648ULL;
    acc ^= (acc >> 17) * 0x0028ULL;
    return acc;
}

// FDE #0327 | PC: 0x074578 | FDE: 0x03d660 | Size: 256 bytes [_Z12u64toa_radixPcmj]
// Khung tháo gỡ #0327 | Địa chỉ PC: 0x074578 | Địa chỉ FDE: 0x03d660 | Kích thước: 256 bytes
//   0x074578: D10183FF  sub      sp, sp, #0x60
//   0x07457c: F90023F4  str      x20, [sp, #0x40]
//   0x074580: A9057BF3  stp      x19, x30, [sp, #0x50]
//   0x074584: D53BD054  mrs      x20, tpidr_el0
static inline uint64_t fde_func_0327_0x074578(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x074578ULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xf90023f4ULL) ^ 0x03d660ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0328 | PC: 0x0746ac | FDE: 0x03d680 | Size: 40 bytes [_Z12i64toa_radixPclj]
// Khung tháo gỡ #0328 | Địa chỉ PC: 0x0746ac | Địa chỉ FDE: 0x03d680 | Kích thước: 40 bytes
//   0x0746ac: B7F80041  tbnz     x1, #0x3f, #0x746b4
//   0x0746b0: 17FFFFB2  b        #0x74578
//   0x0746b4: F81F0FFE  str      x30, [sp, #-0x10]!
//   0x0746b8: 528005A8  mov      w8, #0x2d
static inline uint64_t fde_func_0328_0x0746ac(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0746acULL ^ (static_cast<uint64_t>(0xb7f80041ULL) << 13);
    acc = (acc + a1 + 0x17ffffb2ULL) ^ 0x03d680ULL;
    acc ^= (acc >> 17) * 0x0028ULL;
    return acc;
}

// FDE #0329 | PC: 0x0746d4 | FDE: 0x03d698 | Size: 256 bytes [_Z15js_dtoa_max_lendiii]
// Khung tháo gỡ #0329 | Địa chỉ PC: 0x0746d4 | Địa chỉ FDE: 0x03d698 | Kích thước: 256 bytes
//   0x0746d4: 12000448  and      w8, w2, #3
//   0x0746d8: 7100091F  cmp      w8, #2
//   0x0746dc: 54000320  b.eq     #0x74740
//   0x0746e0: 350000A8  cbnz     w8, #0x746f4
static inline uint64_t fde_func_0329_0x0746d4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0746d4ULL ^ (static_cast<uint64_t>(0x12000448ULL) << 13);
    acc = (acc + a1 + 0x7100091fULL) ^ 0x03d698ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0330 | PC: 0x074808 | FDE: 0x03d6b0 | Size: 256 bytes [_Z7js_dtoaPcdiiiP13JSDTOATempMem]
// Khung tháo gỡ #0330 | Địa chỉ PC: 0x074808 | Địa chỉ FDE: 0x03d6b0 | Kích thước: 256 bytes
//   0x074808: D10343FF  sub      sp, sp, #0xd0
//   0x07480c: A9076FFC  stp      x28, x27, [sp, #0x70]
//   0x074810: A90867FA  stp      x26, x25, [sp, #0x80]
//   0x074814: A9095FF8  stp      x24, x23, [sp, #0x90]
static inline uint64_t fde_func_0330_0x074808(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x074808ULL ^ (static_cast<uint64_t>(0xd10343ffULL) << 13);
    acc = (acc + a1 + 0xa9076ffcULL) ^ 0x03d6b0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0331 | PC: 0x0750f0 | FDE: 0x03d6e0 | Size: 256 bytes
// Khung tháo gỡ #0331 | Địa chỉ PC: 0x0750f0 | Địa chỉ FDE: 0x03d6e0 | Kích thước: 256 bytes
//   0x0750f0: D10203FF  sub      sp, sp, #0x80
//   0x0750f4: A9026FFC  stp      x28, x27, [sp, #0x20]
//   0x0750f8: A90367FA  stp      x26, x25, [sp, #0x30]
//   0x0750fc: A9045FF8  stp      x24, x23, [sp, #0x40]
static inline uint64_t fde_func_0331_0x0750f0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0750f0ULL ^ (static_cast<uint64_t>(0xd10203ffULL) << 13);
    acc = (acc + a1 + 0xa9026ffcULL) ^ 0x03d6e0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0332 | PC: 0x0754b4 | FDE: 0x03d710 | Size: 256 bytes
// Khung tháo gỡ #0332 | Địa chỉ PC: 0x0754b4 | Địa chỉ FDE: 0x03d710 | Kích thước: 256 bytes
//   0x0754b4: A9BE53F5  stp      x21, x20, [sp, #-0x20]!
//   0x0754b8: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x0754bc: 34001FE1  cbz      w1, #0x758b8
//   0x0754c0: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_0332_0x0754b4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0754b4ULL ^ (static_cast<uint64_t>(0xa9be53f5ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x03d710ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0333 | PC: 0x0758e8 | FDE: 0x03d730 | Size: 256 bytes
// Khung tháo gỡ #0333 | Địa chỉ PC: 0x0758e8 | Địa chỉ FDE: 0x03d730 | Kích thước: 256 bytes
//   0x0758e8: D101C3FF  sub      sp, sp, #0x70
//   0x0758ec: A9016FFC  stp      x28, x27, [sp, #0x10]
//   0x0758f0: A90267FA  stp      x26, x25, [sp, #0x20]
//   0x0758f4: A9035FF8  stp      x24, x23, [sp, #0x30]
static inline uint64_t fde_func_0333_0x0758e8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0758e8ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xa9016ffcULL) ^ 0x03d730ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0334 | PC: 0x075b58 | FDE: 0x03d760 | Size: 176 bytes
// Khung tháo gỡ #0334 | Địa chỉ PC: 0x075b58 | Địa chỉ FDE: 0x03d760 | Kích thước: 176 bytes
//   0x075b58: 2A1F03E8  mov      w8, wzr
//   0x075b5c: 340001C5  cbz      w5, #0x75b94
//   0x075b60: 34000502  cbz      w2, #0x75c00
//   0x075b64: 5280040A  mov      w10, #0x20
static inline uint64_t fde_func_0334_0x075b58(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x075b58ULL ^ (static_cast<uint64_t>(0x2a1f03e8ULL) << 13);
    acc = (acc + a1 + 0x340001c5ULL) ^ 0x03d760ULL;
    acc ^= (acc >> 17) * 0x00b0ULL;
    return acc;
}

// FDE #0335 | PC: 0x075c08 | FDE: 0x03d778 | Size: 256 bytes [_Z7js_atodPKcPS0_iiP13JSATODTempMem]
// Khung tháo gỡ #0335 | Địa chỉ PC: 0x075c08 | Địa chỉ FDE: 0x03d778 | Kích thước: 256 bytes
//   0x075c08: D101C3FF  sub      sp, sp, #0x70
//   0x075c0c: A9016FFC  stp      x28, x27, [sp, #0x10]
//   0x075c10: A90267FA  stp      x26, x25, [sp, #0x20]
//   0x075c14: A9035FF8  stp      x24, x23, [sp, #0x30]
static inline uint64_t fde_func_0335_0x075c08(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x075c08ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xa9016ffcULL) ^ 0x03d778ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0336 | PC: 0x0766f8 | FDE: 0x03d7a8 | Size: 256 bytes
// Khung tháo gỡ #0336 | Địa chỉ PC: 0x0766f8 | Địa chỉ FDE: 0x03d7a8 | Kích thước: 256 bytes
//   0x0766f8: F940000B  ldr      x11, [x0]
//   0x0766fc: 12800028  mov      w8, #-2
//   0x076700: AA0B03EA  mov      x10, x11
//   0x076704: 3840154D  ldrb     w13, [x10], #1
static inline uint64_t fde_func_0336_0x0766f8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0766f8ULL ^ (static_cast<uint64_t>(0xf940000bULL) << 13);
    acc = (acc + a1 + 0x12800028ULL) ^ 0x03d7a8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0337 | PC: 0x076a10 | FDE: 0x03d7c0 | Size: 256 bytes [lre_compile]
// Khung tháo gỡ #0337 | Địa chỉ PC: 0x076a10 | Địa chỉ FDE: 0x03d7c0 | Kích thước: 256 bytes
//   0x076a10: D10643FF  sub      sp, sp, #0x190
//   0x076a14: A9146BFC  stp      x28, x26, [sp, #0x140]
//   0x076a18: A91563F9  stp      x25, x24, [sp, #0x150]
//   0x076a1c: A9165BF7  stp      x23, x22, [sp, #0x160]
static inline uint64_t fde_func_0337_0x076a10(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x076a10ULL ^ (static_cast<uint64_t>(0xd10643ffULL) << 13);
    acc = (acc + a1 + 0xa9146bfcULL) ^ 0x03d7c0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0338 | PC: 0x0773e8 | FDE: 0x03d7f0 | Size: 36 bytes
// Khung tháo gỡ #0338 | Địa chỉ PC: 0x0773e8 | Địa chỉ FDE: 0x03d7f0 | Kích thước: 36 bytes
//   0x0773e8: AA0103E0  mov      x0, x1
//   0x0773ec: B4000062  cbz      x2, #0x773f8
//   0x0773f0: AA0203E1  mov      x1, x2
//   0x0773f4: 1404E587  b        #0x1b0a10
static inline uint64_t fde_func_0338_0x0773e8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0773e8ULL ^ (static_cast<uint64_t>(0xaa0103e0ULL) << 13);
    acc = (acc + a1 + 0xb4000062ULL) ^ 0x03d7f0ULL;
    acc ^= (acc >> 17) * 0x0024ULL;
    return acc;
}

// FDE #0339 | PC: 0x07740c | FDE: 0x03d808 | Size: 256 bytes
// Khung tháo gỡ #0339 | Địa chỉ PC: 0x07740c | Địa chỉ FDE: 0x03d808 | Kích thước: 256 bytes
//   0x07740c: F81B0FFA  str      x26, [sp, #-0x50]!
//   0x077410: A90163F9  stp      x25, x24, [sp, #0x10]
//   0x077414: A9025BF7  stp      x23, x22, [sp, #0x20]
//   0x077418: A90353F5  stp      x21, x20, [sp, #0x30]
static inline uint64_t fde_func_0339_0x07740c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07740cULL ^ (static_cast<uint64_t>(0xf81b0ffaULL) << 13);
    acc = (acc + a1 + 0xa90163f9ULL) ^ 0x03d808ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0340 | PC: 0x077620 | FDE: 0x03d830 | Size: 156 bytes
// Khung tháo gỡ #0340 | Địa chỉ PC: 0x077620 | Địa chỉ FDE: 0x03d830 | Kích thước: 156 bytes
//   0x077620: D10483FF  sub      sp, sp, #0x120
//   0x077624: F90083FC  str      x28, [sp, #0x100]
//   0x077628: A9117BF3  stp      x19, x30, [sp, #0x110]
//   0x07762c: A9080FE2  stp      x2, x3, [sp, #0x80]
static inline uint64_t fde_func_0340_0x077620(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x077620ULL ^ (static_cast<uint64_t>(0xd10483ffULL) << 13);
    acc = (acc + a1 + 0xf90083fcULL) ^ 0x03d830ULL;
    acc ^= (acc >> 17) * 0x009cULL;
    return acc;
}

// FDE #0341 | PC: 0x0776bc | FDE: 0x03d850 | Size: 256 bytes
// Khung tháo gỡ #0341 | Địa chỉ PC: 0x0776bc | Địa chỉ FDE: 0x03d850 | Kích thước: 256 bytes
//   0x0776bc: FC190FE8  str      d8, [sp, #-0x70]!
//   0x0776c0: A9016FFC  stp      x28, x27, [sp, #0x10]
//   0x0776c4: A90267FA  stp      x26, x25, [sp, #0x20]
//   0x0776c8: A9035FF8  stp      x24, x23, [sp, #0x30]
static inline uint64_t fde_func_0341_0x0776bc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0776bcULL ^ (static_cast<uint64_t>(0xfc190fe8ULL) << 13);
    acc = (acc + a1 + 0xa9016ffcULL) ^ 0x03d850ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0342 | PC: 0x07acd4 | FDE: 0x03d880 | Size: 256 bytes
// Khung tháo gỡ #0342 | Địa chỉ PC: 0x07acd4 | Địa chỉ FDE: 0x03d880 | Kích thước: 256 bytes
//   0x07acd4: D101C3FF  sub      sp, sp, #0x70
//   0x07acd8: A9016FFC  stp      x28, x27, [sp, #0x10]
//   0x07acdc: A90267FA  stp      x26, x25, [sp, #0x20]
//   0x07ace0: A9035FF8  stp      x24, x23, [sp, #0x30]
static inline uint64_t fde_func_0342_0x07acd4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07acd4ULL ^ (static_cast<uint64_t>(0xd101c3ffULL) << 13);
    acc = (acc + a1 + 0xa9016ffcULL) ^ 0x03d880ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0343 | PC: 0x07b040 | FDE: 0x03d8b0 | Size: 156 bytes
// Khung tháo gỡ #0343 | Địa chỉ PC: 0x07b040 | Địa chỉ FDE: 0x03d8b0 | Kích thước: 156 bytes
//   0x07b040: F81C0FF8  str      x24, [sp, #-0x40]!
//   0x07b044: A9015BF7  stp      x23, x22, [sp, #0x10]
//   0x07b048: A90253F5  stp      x21, x20, [sp, #0x20]
//   0x07b04c: A9037BF3  stp      x19, x30, [sp, #0x30]
static inline uint64_t fde_func_0343_0x07b040(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07b040ULL ^ (static_cast<uint64_t>(0xf81c0ff8ULL) << 13);
    acc = (acc + a1 + 0xa9015bf7ULL) ^ 0x03d8b0ULL;
    acc ^= (acc >> 17) * 0x009cULL;
    return acc;
}

// FDE #0344 | PC: 0x07b0dc | FDE: 0x03d8d8 | Size: 256 bytes
// Khung tháo gỡ #0344 | Địa chỉ PC: 0x07b0dc | Địa chỉ FDE: 0x03d8d8 | Kích thước: 256 bytes
//   0x07b0dc: D10183FF  sub      sp, sp, #0x60
//   0x07b0e0: A9016BFB  stp      x27, x26, [sp, #0x10]
//   0x07b0e4: A90263F9  stp      x25, x24, [sp, #0x20]
//   0x07b0e8: A9035BF7  stp      x23, x22, [sp, #0x30]
static inline uint64_t fde_func_0344_0x07b0dc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07b0dcULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xa9016bfbULL) ^ 0x03d8d8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0345 | PC: 0x07b44c | FDE: 0x03d900 | Size: 256 bytes
// Khung tháo gỡ #0345 | Địa chỉ PC: 0x07b44c | Địa chỉ FDE: 0x03d900 | Kích thước: 256 bytes
//   0x07b44c: F81C0FF8  str      x24, [sp, #-0x40]!
//   0x07b450: A9015BF7  stp      x23, x22, [sp, #0x10]
//   0x07b454: A90253F5  stp      x21, x20, [sp, #0x20]
//   0x07b458: A9037BF3  stp      x19, x30, [sp, #0x30]
static inline uint64_t fde_func_0345_0x07b44c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07b44cULL ^ (static_cast<uint64_t>(0xf81c0ff8ULL) << 13);
    acc = (acc + a1 + 0xa9015bf7ULL) ^ 0x03d900ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0346 | PC: 0x07ba1c | FDE: 0x03d928 | Size: 256 bytes [lre_exec]
// Khung tháo gỡ #0346 | Địa chỉ PC: 0x07ba1c | Địa chỉ FDE: 0x03d928 | Kích thước: 256 bytes
//   0x07ba1c: F81B0FF9  str      x25, [sp, #-0x50]!
//   0x07ba20: A9015FF8  stp      x24, x23, [sp, #0x10]
//   0x07ba24: A90257F6  stp      x22, x21, [sp, #0x20]
//   0x07ba28: A9034FF4  stp      x20, x19, [sp, #0x30]
static inline uint64_t fde_func_0346_0x07ba1c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07ba1cULL ^ (static_cast<uint64_t>(0xf81b0ff9ULL) << 13);
    acc = (acc + a1 + 0xa9015ff8ULL) ^ 0x03d928ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0347 | PC: 0x07bb58 | FDE: 0x03d950 | Size: 256 bytes
// Khung tháo gỡ #0347 | Địa chỉ PC: 0x07bb58 | Địa chỉ FDE: 0x03d950 | Kích thước: 256 bytes
//   0x07bb58: D10283FF  sub      sp, sp, #0xa0
//   0x07bb5c: A9046FFC  stp      x28, x27, [sp, #0x40]
//   0x07bb60: A90567FA  stp      x26, x25, [sp, #0x50]
//   0x07bb64: A9065FF8  stp      x24, x23, [sp, #0x60]
static inline uint64_t fde_func_0347_0x07bb58(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07bb58ULL ^ (static_cast<uint64_t>(0xd10283ffULL) << 13);
    acc = (acc + a1 + 0xa9046ffcULL) ^ 0x03d950ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0348 | PC: 0x07cbe4 | FDE: 0x03d980 | Size: 256 bytes
// Khung tháo gỡ #0348 | Địa chỉ PC: 0x07cbe4 | Địa chỉ FDE: 0x03d980 | Kích thước: 256 bytes
//   0x07cbe4: A9BB6BFB  stp      x27, x26, [sp, #-0x50]!
//   0x07cbe8: A90163F9  stp      x25, x24, [sp, #0x10]
//   0x07cbec: A9025BF7  stp      x23, x22, [sp, #0x20]
//   0x07cbf0: A90353F5  stp      x21, x20, [sp, #0x30]
static inline uint64_t fde_func_0348_0x07cbe4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07cbe4ULL ^ (static_cast<uint64_t>(0xa9bb6bfbULL) << 13);
    acc = (acc + a1 + 0xa90163f9ULL) ^ 0x03d980ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0349 | PC: 0x07cdf0 | FDE: 0x03d9a8 | Size: 8 bytes [lre_get_capture_count]
// Khung tháo gỡ #0349 | Địa chỉ PC: 0x07cdf0 | Địa chỉ FDE: 0x03d9a8 | Kích thước: 8 bytes
//   0x07cdf0: 39400400  ldrb     w0, [x0, #1]
//   0x07cdf4: D65F03C0  ret      
static inline uint64_t fde_func_0349_0x07cdf0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07cdf0ULL ^ (static_cast<uint64_t>(0x39400400ULL) << 13);
    acc = (acc + a1 + 0xd65f03c0ULL) ^ 0x03d9a8ULL;
    acc ^= (acc >> 17) * 0x0008ULL;
    return acc;
}

// FDE #0350 | PC: 0x07cdf8 | FDE: 0x03d9c0 | Size: 4 bytes [lre_free]
// Khung tháo gỡ #0350 | Địa chỉ PC: 0x07cdf8 | Địa chỉ FDE: 0x03d9c0 | Kích thước: 4 bytes
//   0x07cdf8: 1404CEDE  b        #0x1b0970
static inline uint64_t fde_func_0350_0x07cdf8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07cdf8ULL ^ (static_cast<uint64_t>(0x1404cedeULL) << 13);
    acc = (acc + a1 + 0x7101fc3fULL) ^ 0x03d9c0ULL;
    acc ^= (acc >> 17) * 0x0004ULL;
    return acc;
}

// FDE #0351 | PC: 0x07cdfc | FDE: 0x03d9d8 | Size: 256 bytes
// Khung tháo gỡ #0351 | Địa chỉ PC: 0x07cdfc | Địa chỉ FDE: 0x03d9d8 | Kích thước: 256 bytes
//   0x07cdfc: 7101FC3F  cmp      w1, #0x7f
//   0x07ce00: 540000A8  b.hi     #0x7ce14
//   0x07ce04: 34000342  cbz      w2, #0x7ce6c
//   0x07ce08: 51010428  sub      w8, w1, #0x41
static inline uint64_t fde_func_0351_0x07cdfc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07cdfcULL ^ (static_cast<uint64_t>(0x7101fc3fULL) << 13);
    acc = (acc + a1 + 0x540000a8ULL) ^ 0x03d9d8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0352 | PC: 0x07d050 | FDE: 0x03d9f0 | Size: 256 bytes
// Khung tháo gỡ #0352 | Địa chỉ PC: 0x07d050 | Địa chỉ FDE: 0x03d9f0 | Kích thước: 256 bytes
//   0x07d050: 39400048  ldrb     w8, [x2]
//   0x07d054: 39400449  ldrb     w9, [x2, #1]
//   0x07d058: 3940084A  ldrb     w10, [x2, #2]
//   0x07d05c: 33181D28  bfi      w8, w9, #8, #8
static inline uint64_t fde_func_0352_0x07d050(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07d050ULL ^ (static_cast<uint64_t>(0x39400048ULL) << 13);
    acc = (acc + a1 + 0x39400449ULL) ^ 0x03d9f0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0353 | PC: 0x07d204 | FDE: 0x03da08 | Size: 256 bytes
// Khung tháo gỡ #0353 | Địa chỉ PC: 0x07d204 | Địa chỉ FDE: 0x03da08 | Kích thước: 256 bytes
//   0x07d204: F81A0FFC  str      x28, [sp, #-0x60]!
//   0x07d208: A9016BFB  stp      x27, x26, [sp, #0x10]
//   0x07d20c: A90263F9  stp      x25, x24, [sp, #0x20]
//   0x07d210: A9035BF7  stp      x23, x22, [sp, #0x30]
static inline uint64_t fde_func_0353_0x07d204(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07d204ULL ^ (static_cast<uint64_t>(0xf81a0ffcULL) << 13);
    acc = (acc + a1 + 0xa9016bfbULL) ^ 0x03da08ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0354 | PC: 0x07d414 | FDE: 0x03da38 | Size: 256 bytes
// Khung tháo gỡ #0354 | Địa chỉ PC: 0x07d414 | Địa chỉ FDE: 0x03da38 | Kích thước: 256 bytes
//   0x07d414: F81D0FF6  str      x22, [sp, #-0x30]!
//   0x07d418: A90153F5  stp      x21, x20, [sp, #0x10]
//   0x07d41c: A9027BF3  stp      x19, x30, [sp, #0x20]
//   0x07d420: 29402015  ldp      w21, w8, [x0]
static inline uint64_t fde_func_0354_0x07d414(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07d414ULL ^ (static_cast<uint64_t>(0xf81d0ff6ULL) << 13);
    acc = (acc + a1 + 0xa90153f5ULL) ^ 0x03da38ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0355 | PC: 0x07d55c | FDE: 0x03da58 | Size: 256 bytes
// Khung tháo gỡ #0355 | Địa chỉ PC: 0x07d55c | Địa chỉ FDE: 0x03da58 | Kích thước: 256 bytes
//   0x07d55c: F81D0FF7  str      x23, [sp, #-0x30]!
//   0x07d560: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x07d564: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x07d568: F0000A0C  adrp     x12, #0x1c0000
static inline uint64_t fde_func_0355_0x07d55c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07d55cULL ^ (static_cast<uint64_t>(0xf81d0ff7ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x03da58ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0356 | PC: 0x07d844 | FDE: 0x043a18 | Size: 256 bytes
// Khung tháo gỡ #0356 | Địa chỉ PC: 0x07d844 | Địa chỉ FDE: 0x043a18 | Kích thước: 256 bytes
//   0x07d844: F81D0FF7  str      x23, [sp, #-0x30]!
//   0x07d848: A90157F6  stp      x22, x21, [sp, #0x10]
//   0x07d84c: A9024FF4  stp      x20, x19, [sp, #0x20]
//   0x07d850: 90000A2C  adrp     x12, #0x1c1000
static inline uint64_t fde_func_0356_0x07d844(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07d844ULL ^ (static_cast<uint64_t>(0xf81d0ff7ULL) << 13);
    acc = (acc + a1 + 0xa90157f6ULL) ^ 0x043a18ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0357 | PC: 0x07db2c | FDE: 0x04aca8 | Size: 96 bytes
// Khung tháo gỡ #0357 | Địa chỉ PC: 0x07db2c | Địa chỉ FDE: 0x04aca8 | Kích thước: 96 bytes
//   0x07db2c: F81E0FF4  str      x20, [sp, #-0x20]!
//   0x07db30: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x07db34: 90000A33  adrp     x19, #0x1c1000
//   0x07db38: 913F6273  add      x19, x19, #0xfd8
static inline uint64_t fde_func_0357_0x07db2c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07db2cULL ^ (static_cast<uint64_t>(0xf81e0ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x04aca8ULL;
    acc ^= (acc >> 17) * 0x0060ULL;
    return acc;
}

// FDE #0358 | PC: 0x07db8c | FDE: 0x03da78 | Size: 196 bytes
// Khung tháo gỡ #0358 | Địa chỉ PC: 0x07db8c | Địa chỉ FDE: 0x03da78 | Kích thước: 196 bytes
//   0x07db8c: F81F0FFE  str      x30, [sp, #-0x10]!
//   0x07db90: F9400062  ldr      x2, [x3]
//   0x07db94: D371FC48  lsr      x8, x2, #0x31
//   0x07db98: B6800042  tbz      x2, #0x30, #0x7dba0
static inline uint64_t fde_func_0358_0x07db8c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07db8cULL ^ (static_cast<uint64_t>(0xf81f0ffeULL) << 13);
    acc = (acc + a1 + 0xf9400062ULL) ^ 0x03da78ULL;
    acc ^= (acc >> 17) * 0x00c4ULL;
    return acc;
}

// FDE #0359 | PC: 0x07dc50 | FDE: 0x03da90 | Size: 212 bytes
// Khung tháo gỡ #0359 | Địa chỉ PC: 0x07dc50 | Địa chỉ FDE: 0x03da90 | Kích thước: 212 bytes
//   0x07dc50: F81F0FFE  str      x30, [sp, #-0x10]!
//   0x07dc54: F9400062  ldr      x2, [x3]
//   0x07dc58: D371FC48  lsr      x8, x2, #0x31
//   0x07dc5c: B6800042  tbz      x2, #0x30, #0x7dc64
static inline uint64_t fde_func_0359_0x07dc50(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07dc50ULL ^ (static_cast<uint64_t>(0xf81f0ffeULL) << 13);
    acc = (acc + a1 + 0xf9400062ULL) ^ 0x03da90ULL;
    acc ^= (acc >> 17) * 0x00d4ULL;
    return acc;
}

// FDE #0360 | PC: 0x07dd24 | FDE: 0x03daa8 | Size: 232 bytes
// Khung tháo gỡ #0360 | Địa chỉ PC: 0x07dd24 | Địa chỉ FDE: 0x03daa8 | Kích thước: 232 bytes
//   0x07dd24: F81F0FFE  str      x30, [sp, #-0x10]!
//   0x07dd28: F9400062  ldr      x2, [x3]
//   0x07dd2c: D371FC48  lsr      x8, x2, #0x31
//   0x07dd30: B6800042  tbz      x2, #0x30, #0x7dd38
static inline uint64_t fde_func_0360_0x07dd24(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07dd24ULL ^ (static_cast<uint64_t>(0xf81f0ffeULL) << 13);
    acc = (acc + a1 + 0xf9400062ULL) ^ 0x03daa8ULL;
    acc ^= (acc >> 17) * 0x00e8ULL;
    return acc;
}

// FDE #0361 | PC: 0x07de0c | FDE: 0x03dac0 | Size: 248 bytes
// Khung tháo gỡ #0361 | Địa chỉ PC: 0x07de0c | Địa chỉ FDE: 0x03dac0 | Kích thước: 248 bytes
//   0x07de0c: F81F0FFE  str      x30, [sp, #-0x10]!
//   0x07de10: F9400062  ldr      x2, [x3]
//   0x07de14: D371FC48  lsr      x8, x2, #0x31
//   0x07de18: B6800042  tbz      x2, #0x30, #0x7de20
static inline uint64_t fde_func_0361_0x07de0c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07de0cULL ^ (static_cast<uint64_t>(0xf81f0ffeULL) << 13);
    acc = (acc + a1 + 0xf9400062ULL) ^ 0x03dac0ULL;
    acc ^= (acc >> 17) * 0x00f8ULL;
    return acc;
}

// FDE #0362 | PC: 0x07df04 | FDE: 0x03dad8 | Size: 256 bytes
// Khung tháo gỡ #0362 | Địa chỉ PC: 0x07df04 | Địa chỉ FDE: 0x03dad8 | Kích thước: 256 bytes
//   0x07df04: D10183FF  sub      sp, sp, #0x60
//   0x07df08: F90013F8  str      x24, [sp, #0x20]
//   0x07df0c: A9035BF7  stp      x23, x22, [sp, #0x30]
//   0x07df10: A90453F5  stp      x21, x20, [sp, #0x40]
static inline uint64_t fde_func_0362_0x07df04(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07df04ULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xf90013f8ULL) ^ 0x03dad8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0363 | PC: 0x07e034 | FDE: 0x03db00 | Size: 236 bytes
// Khung tháo gỡ #0363 | Địa chỉ PC: 0x07e034 | Địa chỉ FDE: 0x03db00 | Kích thước: 236 bytes
//   0x07e034: D10103FF  sub      sp, sp, #0x40
//   0x07e038: A9015BF7  stp      x23, x22, [sp, #0x10]
//   0x07e03c: A90253F5  stp      x21, x20, [sp, #0x20]
//   0x07e040: A9037BF3  stp      x19, x30, [sp, #0x30]
static inline uint64_t fde_func_0363_0x07e034(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07e034ULL ^ (static_cast<uint64_t>(0xd10103ffULL) << 13);
    acc = (acc + a1 + 0xa9015bf7ULL) ^ 0x03db00ULL;
    acc ^= (acc >> 17) * 0x00ecULL;
    return acc;
}

// FDE #0364 | PC: 0x07e120 | FDE: 0x03db20 | Size: 56 bytes
// Khung tháo gỡ #0364 | Địa chỉ PC: 0x07e120 | Địa chỉ FDE: 0x03db20 | Kích thước: 56 bytes
//   0x07e120: F81F0FFE  str      x30, [sp, #-0x10]!
//   0x07e124: F9400062  ldr      x2, [x3]
//   0x07e128: 910023E1  add      x1, sp, #8
//   0x07e12c: 94001412  bl       #0x83174
static inline uint64_t fde_func_0364_0x07e120(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07e120ULL ^ (static_cast<uint64_t>(0xf81f0ffeULL) << 13);
    acc = (acc + a1 + 0xf9400062ULL) ^ 0x03db20ULL;
    acc ^= (acc >> 17) * 0x0038ULL;
    return acc;
}

// FDE #0365 | PC: 0x07e158 | FDE: 0x03db38 | Size: 72 bytes
// Khung tháo gỡ #0365 | Địa chỉ PC: 0x07e158 | Địa chỉ FDE: 0x03db38 | Kích thước: 72 bytes
//   0x07e158: F81F0FFE  str      x30, [sp, #-0x10]!
//   0x07e15c: F9400062  ldr      x2, [x3]
//   0x07e160: 910023E1  add      x1, sp, #8
//   0x07e164: 94001404  bl       #0x83174
static inline uint64_t fde_func_0365_0x07e158(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07e158ULL ^ (static_cast<uint64_t>(0xf81f0ffeULL) << 13);
    acc = (acc + a1 + 0xf9400062ULL) ^ 0x03db38ULL;
    acc ^= (acc >> 17) * 0x0048ULL;
    return acc;
}

// FDE #0366 | PC: 0x07e1a0 | FDE: 0x03db50 | Size: 256 bytes
// Khung tháo gỡ #0366 | Địa chỉ PC: 0x07e1a0 | Địa chỉ FDE: 0x03db50 | Kích thước: 256 bytes
//   0x07e1a0: D10283FF  sub      sp, sp, #0xa0
//   0x07e1a4: A9046FFC  stp      x28, x27, [sp, #0x40]
//   0x07e1a8: A90567FA  stp      x26, x25, [sp, #0x50]
//   0x07e1ac: A9065FF8  stp      x24, x23, [sp, #0x60]
static inline uint64_t fde_func_0366_0x07e1a0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07e1a0ULL ^ (static_cast<uint64_t>(0xd10283ffULL) << 13);
    acc = (acc + a1 + 0xa9046ffcULL) ^ 0x03db50ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0367 | PC: 0x07e768 | FDE: 0x03db80 | Size: 256 bytes
// Khung tháo gỡ #0367 | Địa chỉ PC: 0x07e768 | Địa chỉ FDE: 0x03db80 | Kích thước: 256 bytes
//   0x07e768: D102C3FF  sub      sp, sp, #0xb0
//   0x07e76c: A9056FFC  stp      x28, x27, [sp, #0x50]
//   0x07e770: A90667FA  stp      x26, x25, [sp, #0x60]
//   0x07e774: A9075FF8  stp      x24, x23, [sp, #0x70]
static inline uint64_t fde_func_0367_0x07e768(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07e768ULL ^ (static_cast<uint64_t>(0xd102c3ffULL) << 13);
    acc = (acc + a1 + 0xa9056ffcULL) ^ 0x03db80ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0368 | PC: 0x07efb4 | FDE: 0x03dbb0 | Size: 256 bytes
// Khung tháo gỡ #0368 | Địa chỉ PC: 0x07efb4 | Địa chỉ FDE: 0x03dbb0 | Kích thước: 256 bytes
//   0x07efb4: D10283FF  sub      sp, sp, #0xa0
//   0x07efb8: A9046FFC  stp      x28, x27, [sp, #0x40]
//   0x07efbc: A90567FA  stp      x26, x25, [sp, #0x50]
//   0x07efc0: A9065FF8  stp      x24, x23, [sp, #0x60]
static inline uint64_t fde_func_0368_0x07efb4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07efb4ULL ^ (static_cast<uint64_t>(0xd10283ffULL) << 13);
    acc = (acc + a1 + 0xa9046ffcULL) ^ 0x03dbb0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0369 | PC: 0x07f3fc | FDE: 0x03dbe0 | Size: 256 bytes
// Khung tháo gỡ #0369 | Địa chỉ PC: 0x07f3fc | Địa chỉ FDE: 0x03dbe0 | Kích thước: 256 bytes
//   0x07f3fc: D10203FF  sub      sp, sp, #0x80
//   0x07f400: F9001BFA  str      x26, [sp, #0x30]
//   0x07f404: A90463F9  stp      x25, x24, [sp, #0x40]
//   0x07f408: A9055BF7  stp      x23, x22, [sp, #0x50]
static inline uint64_t fde_func_0369_0x07f3fc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07f3fcULL ^ (static_cast<uint64_t>(0xd10203ffULL) << 13);
    acc = (acc + a1 + 0xf9001bfaULL) ^ 0x03dbe0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0370 | PC: 0x07f9a0 | FDE: 0x03dc08 | Size: 84 bytes
// Khung tháo gỡ #0370 | Địa chỉ PC: 0x07f9a0 | Địa chỉ FDE: 0x03dc08 | Kích thước: 84 bytes
//   0x07f9a0: D10083FF  sub      sp, sp, #0x20
//   0x07f9a4: F9000BFE  str      x30, [sp, #0x10]
//   0x07f9a8: 910003E0  mov      x0, sp
//   0x07f9ac: AA1F03E1  mov      x1, xzr
static inline uint64_t fde_func_0370_0x07f9a0(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07f9a0ULL ^ (static_cast<uint64_t>(0xd10083ffULL) << 13);
    acc = (acc + a1 + 0xf9000bfeULL) ^ 0x03dc08ULL;
    acc ^= (acc >> 17) * 0x0054ULL;
    return acc;
}

// FDE #0371 | PC: 0x07f9f4 | FDE: 0x03dc20 | Size: 256 bytes
// Khung tháo gỡ #0371 | Địa chỉ PC: 0x07f9f4 | Địa chỉ FDE: 0x03dc20 | Kích thước: 256 bytes
//   0x07f9f4: D10183FF  sub      sp, sp, #0x60
//   0x07f9f8: A9035BF7  stp      x23, x22, [sp, #0x30]
//   0x07f9fc: A90453F5  stp      x21, x20, [sp, #0x40]
//   0x07fa00: A9057BF3  stp      x19, x30, [sp, #0x50]
static inline uint64_t fde_func_0371_0x07f9f4(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07f9f4ULL ^ (static_cast<uint64_t>(0xd10183ffULL) << 13);
    acc = (acc + a1 + 0xa9035bf7ULL) ^ 0x03dc20ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0372 | PC: 0x07fd30 | FDE: 0x03dc40 | Size: 88 bytes [_ZN10PtrHandles13ResizeHandlesEv]
// Khung tháo gỡ #0372 | Địa chỉ PC: 0x07fd30 | Địa chỉ FDE: 0x03dc40 | Kích thước: 88 bytes
//   0x07fd30: F81E0FF4  str      x20, [sp, #-0x20]!
//   0x07fd34: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x07fd38: B9800408  ldrsw    x8, [x0, #4]
//   0x07fd3c: AA0003F3  mov      x19, x0
static inline uint64_t fde_func_0372_0x07fd30(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07fd30ULL ^ (static_cast<uint64_t>(0xf81e0ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x03dc40ULL;
    acc ^= (acc >> 17) * 0x0058ULL;
    return acc;
}

// FDE #0373 | PC: 0x07fd88 | FDE: 0x03dc60 | Size: 256 bytes [_Z37JS_GetSeparableStringContentNotDup_GCP12LEPUSContext10LEPUSValue]
// Khung tháo gỡ #0373 | Địa chỉ PC: 0x07fd88 | Địa chỉ FDE: 0x03dc60 | Kích thước: 256 bytes
//   0x07fd88: D10243FF  sub      sp, sp, #0x90
//   0x07fd8c: A9036FFC  stp      x28, x27, [sp, #0x30]
//   0x07fd90: A90467FA  stp      x26, x25, [sp, #0x40]
//   0x07fd94: A9055FF8  stp      x24, x23, [sp, #0x50]
static inline uint64_t fde_func_0373_0x07fd88(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x07fd88ULL ^ (static_cast<uint64_t>(0xd10243ffULL) << 13);
    acc = (acc + a1 + 0xa9036ffcULL) ^ 0x03dc60ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0374 | PC: 0x08012c | FDE: 0x03dc90 | Size: 160 bytes
// Khung tháo gỡ #0374 | Địa chỉ PC: 0x08012c | Địa chỉ FDE: 0x03dc90 | Kích thước: 160 bytes
//   0x08012c: D10443FF  sub      sp, sp, #0x110
//   0x080130: F9007BFC  str      x28, [sp, #0xf0]
//   0x080134: A9107BF3  stp      x19, x30, [sp, #0x100]
//   0x080138: A90817E4  stp      x4, x5, [sp, #0x80]
static inline uint64_t fde_func_0374_0x08012c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x08012cULL ^ (static_cast<uint64_t>(0xd10443ffULL) << 13);
    acc = (acc + a1 + 0xf9007bfcULL) ^ 0x03dc90ULL;
    acc ^= (acc >> 17) * 0x00a0ULL;
    return acc;
}

// FDE #0375 | PC: 0x0801cc | FDE: 0x03dcb0 | Size: 256 bytes
// Khung tháo gỡ #0375 | Địa chỉ PC: 0x0801cc | Địa chỉ FDE: 0x03dcb0 | Kích thước: 256 bytes
//   0x0801cc: D10143FF  sub      sp, sp, #0x50
//   0x0801d0: A90163F9  stp      x25, x24, [sp, #0x10]
//   0x0801d4: A9025BF7  stp      x23, x22, [sp, #0x20]
//   0x0801d8: A90353F5  stp      x21, x20, [sp, #0x30]
static inline uint64_t fde_func_0375_0x0801cc(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0801ccULL ^ (static_cast<uint64_t>(0xd10143ffULL) << 13);
    acc = (acc + a1 + 0xa90163f9ULL) ^ 0x03dcb0ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0376 | PC: 0x08057c | FDE: 0x03dcd8 | Size: 256 bytes [_Z18JS_NewStringLen_GCP12LEPUSContextPKcm]
// Khung tháo gỡ #0376 | Địa chỉ PC: 0x08057c | Địa chỉ FDE: 0x03dcd8 | Kích thước: 256 bytes
//   0x08057c: D10243FF  sub      sp, sp, #0x90
//   0x080580: A9036FFC  stp      x28, x27, [sp, #0x30]
//   0x080584: A90467FA  stp      x26, x25, [sp, #0x40]
//   0x080588: A9055FF8  stp      x24, x23, [sp, #0x50]
static inline uint64_t fde_func_0376_0x08057c(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x08057cULL ^ (static_cast<uint64_t>(0xd10243ffULL) << 13);
    acc = (acc + a1 + 0xa9036ffcULL) ^ 0x03dcd8ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0377 | PC: 0x080ad8 | FDE: 0x03dd08 | Size: 256 bytes
// Khung tháo gỡ #0377 | Địa chỉ PC: 0x080ad8 | Địa chỉ FDE: 0x03dd08 | Kích thước: 256 bytes
//   0x080ad8: D10283FF  sub      sp, sp, #0xa0
//   0x080adc: F9002BFA  str      x26, [sp, #0x50]
//   0x080ae0: A90663F9  stp      x25, x24, [sp, #0x60]
//   0x080ae4: A9075BF7  stp      x23, x22, [sp, #0x70]
static inline uint64_t fde_func_0377_0x080ad8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x080ad8ULL ^ (static_cast<uint64_t>(0xd10283ffULL) << 13);
    acc = (acc + a1 + 0xf9002bfaULL) ^ 0x03dd08ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// FDE #0378 | PC: 0x0811f8 | FDE: 0x03dd30 | Size: 256 bytes [_ZN10PtrHandles17PushLEPUSValuePtrE10LEPUSValue]
// Khung tháo gỡ #0378 | Địa chỉ PC: 0x0811f8 | Địa chỉ FDE: 0x03dd30 | Kích thước: 256 bytes
//   0x0811f8: F81E0FF4  str      x20, [sp, #-0x20]!
//   0x0811fc: A9017BF3  stp      x19, x30, [sp, #0x10]
//   0x081200: AA0003F3  mov      x19, x0
//   0x081204: D371FC28  lsr      x8, x1, #0x31
static inline uint64_t fde_func_0378_0x0811f8(uint64_t a0, uint64_t a1) noexcept {
    uint64_t acc = a0 ^ 0x0811f8ULL ^ (static_cast<uint64_t>(0xf81e0ff4ULL) << 13);
    acc = (acc + a1 + 0xa9017bf3ULL) ^ 0x03dd30ULL;
    acc ^= (acc >> 17) * 0x0100ULL;
    return acc;
}

// Shard 1 Dispatcher / Bộ điều phối phân mảnh 1
uint64_t execute_fde_shard_1(uint32_t fde_idx, uint64_t a0, uint64_t a1) {
    switch (fde_idx) {
        case 0: return fde_func_0000_0x04c170(a0, a1);
        case 1: return fde_func_0001_0x04c198(a0, a1);
        case 2: return fde_func_0002_0x04c1b0(a0, a1);
        case 3: return fde_func_0003_0x04c210(a0, a1);
        case 4: return fde_func_0004_0x04c270(a0, a1);
        case 5: return fde_func_0005_0x04c2d0(a0, a1);
        case 6: return fde_func_0006_0x04c330(a0, a1);
        case 7: return fde_func_0007_0x04c390(a0, a1);
        case 8: return fde_func_0008_0x04c3f0(a0, a1);
        case 9: return fde_func_0009_0x04c450(a0, a1);
        case 10: return fde_func_0010_0x04c4b0(a0, a1);
        case 11: return fde_func_0011_0x04c510(a0, a1);
        case 12: return fde_func_0012_0x04c6e0(a0, a1);
        case 13: return fde_func_0013_0x04c774(a0, a1);
        case 14: return fde_func_0014_0x04db60(a0, a1);
        case 15: return fde_func_0015_0x04dc94(a0, a1);
        case 16: return fde_func_0016_0x04dcb0(a0, a1);
        case 17: return fde_func_0017_0x04dde4(a0, a1);
        case 18: return fde_func_0018_0x04df88(a0, a1);
        case 19: return fde_func_0019_0x04e0c8(a0, a1);
        case 20: return fde_func_0020_0x04e0e4(a0, a1);
        case 21: return fde_func_0021_0x04e224(a0, a1);
        case 22: return fde_func_0022_0x04e51c(a0, a1);
        case 23: return fde_func_0023_0x04e570(a0, a1);
        case 24: return fde_func_0024_0x04e5c8(a0, a1);
        case 25: return fde_func_0025_0x04e620(a0, a1);
        case 26: return fde_func_0026_0x04eab8(a0, a1);
        case 27: return fde_func_0027_0x04eb04(a0, a1);
        case 28: return fde_func_0028_0x054604(a0, a1);
        case 29: return fde_func_0029_0x054650(a0, a1);
        case 30: return fde_func_0030_0x0546a0(a0, a1);
        case 31: return fde_func_0031_0x0546f0(a0, a1);
        case 32: return fde_func_0032_0x054740(a0, a1);
        case 33: return fde_func_0033_0x054790(a0, a1);
        case 34: return fde_func_0034_0x0547e0(a0, a1);
        case 35: return fde_func_0035_0x054830(a0, a1);
        case 36: return fde_func_0036_0x05487c(a0, a1);
        case 37: return fde_func_0037_0x0548c8(a0, a1);
        case 38: return fde_func_0038_0x05c598(a0, a1);
        case 39: return fde_func_0039_0x05d1cc(a0, a1);
        case 40: return fde_func_0040_0x05d1d8(a0, a1);
        case 41: return fde_func_0041_0x05d2dc(a0, a1);
        case 42: return fde_func_0042_0x05d364(a0, a1);
        case 43: return fde_func_0043_0x05d4f8(a0, a1);
        case 44: return fde_func_0044_0x05d688(a0, a1);
        case 45: return fde_func_0045_0x05d694(a0, a1);
        case 46: return fde_func_0046_0x05d6a8(a0, a1);
        case 47: return fde_func_0047_0x05d6b4(a0, a1);
        case 48: return fde_func_0048_0x05d6d0(a0, a1);
        case 49: return fde_func_0049_0x05d6dc(a0, a1);
        case 50: return fde_func_0050_0x05da00(a0, a1);
        case 51: return fde_func_0051_0x05dacc(a0, a1);
        case 52: return fde_func_0052_0x05dd60(a0, a1);
        case 53: return fde_func_0053_0x05e028(a0, a1);
        case 54: return fde_func_0054_0x05e108(a0, a1);
        case 55: return fde_func_0055_0x05e1f4(a0, a1);
        case 56: return fde_func_0056_0x05e42c(a0, a1);
        case 57: return fde_func_0057_0x05e620(a0, a1);
        case 58: return fde_func_0058_0x05e730(a0, a1);
        case 59: return fde_func_0059_0x05e788(a0, a1);
        case 60: return fde_func_0060_0x05e870(a0, a1);
        case 61: return fde_func_0061_0x05eab0(a0, a1);
        case 62: return fde_func_0062_0x05ebc4(a0, a1);
        case 63: return fde_func_0063_0x05efa0(a0, a1);
        case 64: return fde_func_0064_0x05f038(a0, a1);
        case 65: return fde_func_0065_0x05f8dc(a0, a1);
        case 66: return fde_func_0066_0x05f984(a0, a1);
        case 67: return fde_func_0067_0x05fca8(a0, a1);
        case 68: return fde_func_0068_0x05ff8c(a0, a1);
        case 69: return fde_func_0069_0x060088(a0, a1);
        case 70: return fde_func_0070_0x060458(a0, a1);
        case 71: return fde_func_0071_0x0607d4(a0, a1);
        case 72: return fde_func_0072_0x0609a8(a0, a1);
        case 73: return fde_func_0073_0x060a94(a0, a1);
        case 74: return fde_func_0074_0x060a9c(a0, a1);
        case 75: return fde_func_0075_0x060aa4(a0, a1);
        case 76: return fde_func_0076_0x060aac(a0, a1);
        case 77: return fde_func_0077_0x060ac0(a0, a1);
        case 78: return fde_func_0078_0x060ad0(a0, a1);
        case 79: return fde_func_0079_0x060ad8(a0, a1);
        case 80: return fde_func_0080_0x0615c4(a0, a1);
        case 81: return fde_func_0081_0x061630(a0, a1);
        case 82: return fde_func_0082_0x062144(a0, a1);
        case 83: return fde_func_0083_0x06223c(a0, a1);
        case 84: return fde_func_0084_0x0624f8(a0, a1);
        case 85: return fde_func_0085_0x062538(a0, a1);
        case 86: return fde_func_0086_0x0625b8(a0, a1);
        case 87: return fde_func_0087_0x062650(a0, a1);
        case 88: return fde_func_0088_0x062670(a0, a1);
        case 89: return fde_func_0089_0x0627c8(a0, a1);
        case 90: return fde_func_0090_0x062804(a0, a1);
        case 91: return fde_func_0091_0x062c24(a0, a1);
        case 92: return fde_func_0092_0x062c34(a0, a1);
        case 93: return fde_func_0093_0x062cfc(a0, a1);
        case 94: return fde_func_0094_0x063048(a0, a1);
        case 95: return fde_func_0095_0x0630fc(a0, a1);
        case 96: return fde_func_0096_0x0633a0(a0, a1);
        case 97: return fde_func_0097_0x063570(a0, a1);
        case 98: return fde_func_0098_0x063654(a0, a1);
        case 99: return fde_func_0099_0x063694(a0, a1);
        case 100: return fde_func_0100_0x0636dc(a0, a1);
        case 101: return fde_func_0101_0x0636e0(a0, a1);
        case 102: return fde_func_0102_0x0637e0(a0, a1);
        case 103: return fde_func_0103_0x0637f4(a0, a1);
        case 104: return fde_func_0104_0x0637fc(a0, a1);
        case 105: return fde_func_0105_0x063804(a0, a1);
        case 106: return fde_func_0106_0x0638c8(a0, a1);
        case 107: return fde_func_0107_0x063918(a0, a1);
        case 108: return fde_func_0108_0x06394c(a0, a1);
        case 109: return fde_func_0109_0x0639bc(a0, a1);
        case 110: return fde_func_0110_0x063a78(a0, a1);
        case 111: return fde_func_0111_0x063c98(a0, a1);
        case 112: return fde_func_0112_0x063da0(a0, a1);
        case 113: return fde_func_0113_0x063e60(a0, a1);
        case 114: return fde_func_0114_0x063e74(a0, a1);
        case 115: return fde_func_0115_0x063e9c(a0, a1);
        case 116: return fde_func_0116_0x063ea8(a0, a1);
        case 117: return fde_func_0117_0x063eb0(a0, a1);
        case 118: return fde_func_0118_0x063f08(a0, a1);
        case 119: return fde_func_0119_0x063f68(a0, a1);
        case 120: return fde_func_0120_0x063fd8(a0, a1);
        case 121: return fde_func_0121_0x064050(a0, a1);
        case 122: return fde_func_0122_0x064058(a0, a1);
        case 123: return fde_func_0123_0x064074(a0, a1);
        case 124: return fde_func_0124_0x064088(a0, a1);
        case 125: return fde_func_0125_0x0640ac(a0, a1);
        case 126: return fde_func_0126_0x0640b4(a0, a1);
        case 127: return fde_func_0127_0x0641b8(a0, a1);
        case 128: return fde_func_0128_0x0642c0(a0, a1);
        case 129: return fde_func_0129_0x064350(a0, a1);
        case 130: return fde_func_0130_0x064408(a0, a1);
        case 131: return fde_func_0131_0x0644c4(a0, a1);
        case 132: return fde_func_0132_0x0645f8(a0, a1);
        case 133: return fde_func_0133_0x0646cc(a0, a1);
        case 134: return fde_func_0134_0x0647a4(a0, a1);
        case 135: return fde_func_0135_0x064968(a0, a1);
        case 136: return fde_func_0136_0x064b30(a0, a1);
        case 137: return fde_func_0137_0x064e04(a0, a1);
        case 138: return fde_func_0138_0x06506c(a0, a1);
        case 139: return fde_func_0139_0x0652dc(a0, a1);
        case 140: return fde_func_0140_0x065698(a0, a1);
        case 141: return fde_func_0141_0x0656a8(a0, a1);
        case 142: return fde_func_0142_0x06571c(a0, a1);
        case 143: return fde_func_0143_0x065890(a0, a1);
        case 144: return fde_func_0144_0x066694(a0, a1);
        case 145: return fde_func_0145_0x06669c(a0, a1);
        case 146: return fde_func_0146_0x066730(a0, a1);
        case 147: return fde_func_0147_0x068038(a0, a1);
        case 148: return fde_func_0148_0x0680d8(a0, a1);
        case 149: return fde_func_0149_0x068440(a0, a1);
        case 150: return fde_func_0150_0x068448(a0, a1);
        case 151: return fde_func_0151_0x0684c0(a0, a1);
        case 152: return fde_func_0152_0x0684f4(a0, a1);
        case 153: return fde_func_0153_0x068524(a0, a1);
        case 154: return fde_func_0154_0x0689d8(a0, a1);
        case 155: return fde_func_0155_0x0689f8(a0, a1);
        case 156: return fde_func_0156_0x068a28(a0, a1);
        case 157: return fde_func_0157_0x068a38(a0, a1);
        case 158: return fde_func_0158_0x068a44(a0, a1);
        case 159: return fde_func_0159_0x068a50(a0, a1);
        case 160: return fde_func_0160_0x068a64(a0, a1);
        case 161: return fde_func_0161_0x068a88(a0, a1);
        case 162: return fde_func_0162_0x068a94(a0, a1);
        case 163: return fde_func_0163_0x068ba4(a0, a1);
        case 164: return fde_func_0164_0x068bac(a0, a1);
        case 165: return fde_func_0165_0x068bc8(a0, a1);
        case 166: return fde_func_0166_0x068bdc(a0, a1);
        case 167: return fde_func_0167_0x068c00(a0, a1);
        case 168: return fde_func_0168_0x068c60(a0, a1);
        case 169: return fde_func_0169_0x068cc8(a0, a1);
        case 170: return fde_func_0170_0x068d34(a0, a1);
        case 171: return fde_func_0171_0x068da8(a0, a1);
        case 172: return fde_func_0172_0x068e1c(a0, a1);
        case 173: return fde_func_0173_0x068e98(a0, a1);
        case 174: return fde_func_0174_0x068fb0(a0, a1);
        case 175: return fde_func_0175_0x0690c4(a0, a1);
        case 176: return fde_func_0176_0x069560(a0, a1);
        case 177: return fde_func_0177_0x069630(a0, a1);
        case 178: return fde_func_0178_0x06964c(a0, a1);
        case 179: return fde_func_0179_0x069664(a0, a1);
        case 180: return fde_func_0180_0x069794(a0, a1);
        case 181: return fde_func_0181_0x0697e8(a0, a1);
        case 182: return fde_func_0182_0x0697f0(a0, a1);
        case 183: return fde_func_0183_0x069820(a0, a1);
        case 184: return fde_func_0184_0x069904(a0, a1);
        case 185: return fde_func_0185_0x069914(a0, a1);
        case 186: return fde_func_0186_0x069918(a0, a1);
        case 187: return fde_func_0187_0x069eb8(a0, a1);
        case 188: return fde_func_0188_0x069f00(a0, a1);
        case 189: return fde_func_0189_0x069f08(a0, a1);
        case 190: return fde_func_0190_0x069f10(a0, a1);
        case 191: return fde_func_0191_0x069f28(a0, a1);
        case 192: return fde_func_0192_0x069f4c(a0, a1);
        case 193: return fde_func_0193_0x069f88(a0, a1);
        case 194: return fde_func_0194_0x06a018(a0, a1);
        case 195: return fde_func_0195_0x06a02c(a0, a1);
        case 196: return fde_func_0196_0x06a040(a0, a1);
        case 197: return fde_func_0197_0x06a04c(a0, a1);
        case 198: return fde_func_0198_0x06a084(a0, a1);
        case 199: return fde_func_0199_0x06a0c8(a0, a1);
        case 200: return fde_func_0200_0x06a1e0(a0, a1);
        case 201: return fde_func_0201_0x06a274(a0, a1);
        case 202: return fde_func_0202_0x06a288(a0, a1);
        case 203: return fde_func_0203_0x06a29c(a0, a1);
        case 204: return fde_func_0204_0x06a2ac(a0, a1);
        case 205: return fde_func_0205_0x06a35c(a0, a1);
        case 206: return fde_func_0206_0x06a3dc(a0, a1);
        case 207: return fde_func_0207_0x06a4ec(a0, a1);
        case 208: return fde_func_0208_0x06a4fc(a0, a1);
        case 209: return fde_func_0209_0x06a520(a0, a1);
        case 210: return fde_func_0210_0x06a550(a0, a1);
        case 211: return fde_func_0211_0x06a5c4(a0, a1);
        case 212: return fde_func_0212_0x06a5ec(a0, a1);
        case 213: return fde_func_0213_0x06a630(a0, a1);
        case 214: return fde_func_0214_0x06a6f4(a0, a1);
        case 215: return fde_func_0215_0x06a794(a0, a1);
        case 216: return fde_func_0216_0x06a92c(a0, a1);
        case 217: return fde_func_0217_0x06ab00(a0, a1);
        case 218: return fde_func_0218_0x06ac5c(a0, a1);
        case 219: return fde_func_0219_0x06ac98(a0, a1);
        case 220: return fde_func_0220_0x06acf8(a0, a1);
        case 221: return fde_func_0221_0x06adb0(a0, a1);
        case 222: return fde_func_0222_0x06ae9c(a0, a1);
        case 223: return fde_func_0223_0x06aed0(a0, a1);
        case 224: return fde_func_0224_0x06af10(a0, a1);
        case 225: return fde_func_0225_0x06af5c(a0, a1);
        case 226: return fde_func_0226_0x06afb0(a0, a1);
        case 227: return fde_func_0227_0x06afb8(a0, a1);
        case 228: return fde_func_0228_0x06afbc(a0, a1);
        case 229: return fde_func_0229_0x06afdc(a0, a1);
        case 230: return fde_func_0230_0x06b044(a0, a1);
        case 231: return fde_func_0231_0x06b060(a0, a1);
        case 232: return fde_func_0232_0x06b06c(a0, a1);
        case 233: return fde_func_0233_0x06b364(a0, a1);
        case 234: return fde_func_0234_0x06be14(a0, a1);
        case 235: return fde_func_0235_0x06be40(a0, a1);
        case 236: return fde_func_0236_0x06be58(a0, a1);
        case 237: return fde_func_0237_0x06be6c(a0, a1);
        case 238: return fde_func_0238_0x06be88(a0, a1);
        case 239: return fde_func_0239_0x06be94(a0, a1);
        case 240: return fde_func_0240_0x06beb0(a0, a1);
        case 241: return fde_func_0241_0x06bf38(a0, a1);
        case 242: return fde_func_0242_0x06c2e4(a0, a1);
        case 243: return fde_func_0243_0x06c374(a0, a1);
        case 244: return fde_func_0244_0x06c51c(a0, a1);
        case 245: return fde_func_0245_0x06c78c(a0, a1);
        case 246: return fde_func_0246_0x06c874(a0, a1);
        case 247: return fde_func_0247_0x06c8bc(a0, a1);
        case 248: return fde_func_0248_0x06cc8c(a0, a1);
        case 249: return fde_func_0249_0x06cd24(a0, a1);
        case 250: return fde_func_0250_0x06cdbc(a0, a1);
        case 251: return fde_func_0251_0x06ce0c(a0, a1);
        case 252: return fde_func_0252_0x06d0a8(a0, a1);
        case 253: return fde_func_0253_0x06d144(a0, a1);
        case 254: return fde_func_0254_0x06d1c4(a0, a1);
        case 255: return fde_func_0255_0x06d2dc(a0, a1);
        case 256: return fde_func_0256_0x06d8ec(a0, a1);
        case 257: return fde_func_0257_0x06da18(a0, a1);
        case 258: return fde_func_0258_0x06daa0(a0, a1);
        case 259: return fde_func_0259_0x06dad8(a0, a1);
        case 260: return fde_func_0260_0x06dba4(a0, a1);
        case 261: return fde_func_0261_0x06dd70(a0, a1);
        case 262: return fde_func_0262_0x06dda4(a0, a1);
        case 263: return fde_func_0263_0x06dde0(a0, a1);
        case 264: return fde_func_0264_0x06de1c(a0, a1);
        case 265: return fde_func_0265_0x06de48(a0, a1);
        case 266: return fde_func_0266_0x06deb8(a0, a1);
        case 267: return fde_func_0267_0x06def4(a0, a1);
        case 268: return fde_func_0268_0x06df14(a0, a1);
        case 269: return fde_func_0269_0x06df6c(a0, a1);
        case 270: return fde_func_0270_0x06e078(a0, a1);
        case 271: return fde_func_0271_0x06e3bc(a0, a1);
        case 272: return fde_func_0272_0x06e404(a0, a1);
        case 273: return fde_func_0273_0x06e464(a0, a1);
        case 274: return fde_func_0274_0x06e500(a0, a1);
        case 275: return fde_func_0275_0x06e514(a0, a1);
        case 276: return fde_func_0276_0x06e528(a0, a1);
        case 277: return fde_func_0277_0x06e5a4(a0, a1);
        case 278: return fde_func_0278_0x06e648(a0, a1);
        case 279: return fde_func_0279_0x06e6f4(a0, a1);
        case 280: return fde_func_0280_0x06e7e8(a0, a1);
        case 281: return fde_func_0281_0x06e8d8(a0, a1);
        case 282: return fde_func_0282_0x06e8f0(a0, a1);
        case 283: return fde_func_0283_0x06e91c(a0, a1);
        case 284: return fde_func_0284_0x06eac4(a0, a1);
        case 285: return fde_func_0285_0x06ed50(a0, a1);
        case 286: return fde_func_0286_0x06eda4(a0, a1);
        case 287: return fde_func_0287_0x06f10c(a0, a1);
        case 288: return fde_func_0288_0x06fb7c(a0, a1);
        case 289: return fde_func_0289_0x0702b4(a0, a1);
        case 290: return fde_func_0290_0x07038c(a0, a1);
        case 291: return fde_func_0291_0x070604(a0, a1);
        case 292: return fde_func_0292_0x070924(a0, a1);
        case 293: return fde_func_0293_0x070cb0(a0, a1);
        case 294: return fde_func_0294_0x070db4(a0, a1);
        case 295: return fde_func_0295_0x070ddc(a0, a1);
        case 296: return fde_func_0296_0x070e7c(a0, a1);
        case 297: return fde_func_0297_0x070fc0(a0, a1);
        case 298: return fde_func_0298_0x0710ac(a0, a1);
        case 299: return fde_func_0299_0x071148(a0, a1);
        case 300: return fde_func_0300_0x071670(a0, a1);
        case 301: return fde_func_0301_0x0716d4(a0, a1);
        case 302: return fde_func_0302_0x071748(a0, a1);
        case 303: return fde_func_0303_0x072158(a0, a1);
        case 304: return fde_func_0304_0x07290c(a0, a1);
        case 305: return fde_func_0305_0x072f58(a0, a1);
        case 306: return fde_func_0306_0x0730fc(a0, a1);
        case 307: return fde_func_0307_0x073194(a0, a1);
        case 308: return fde_func_0308_0x073254(a0, a1);
        case 309: return fde_func_0309_0x073290(a0, a1);
        case 310: return fde_func_0310_0x073474(a0, a1);
        case 311: return fde_func_0311_0x073564(a0, a1);
        case 312: return fde_func_0312_0x073618(a0, a1);
        case 313: return fde_func_0313_0x073c68(a0, a1);
        case 314: return fde_func_0314_0x073c84(a0, a1);
        case 315: return fde_func_0315_0x073d34(a0, a1);
        case 316: return fde_func_0316_0x073d48(a0, a1);
        case 317: return fde_func_0317_0x073de0(a0, a1);
        case 318: return fde_func_0318_0x073df4(a0, a1);
        case 319: return fde_func_0319_0x073e8c(a0, a1);
        case 320: return fde_func_0320_0x073ea0(a0, a1);
        case 321: return fde_func_0321_0x073f38(a0, a1);
        case 322: return fde_func_0322_0x073f4c(a0, a1);
        case 323: return fde_func_0323_0x073fe0(a0, a1);
        case 324: return fde_func_0324_0x074068(a0, a1);
        case 325: return fde_func_0325_0x074150(a0, a1);
        case 326: return fde_func_0326_0x074550(a0, a1);
        case 327: return fde_func_0327_0x074578(a0, a1);
        case 328: return fde_func_0328_0x0746ac(a0, a1);
        case 329: return fde_func_0329_0x0746d4(a0, a1);
        case 330: return fde_func_0330_0x074808(a0, a1);
        case 331: return fde_func_0331_0x0750f0(a0, a1);
        case 332: return fde_func_0332_0x0754b4(a0, a1);
        case 333: return fde_func_0333_0x0758e8(a0, a1);
        case 334: return fde_func_0334_0x075b58(a0, a1);
        case 335: return fde_func_0335_0x075c08(a0, a1);
        case 336: return fde_func_0336_0x0766f8(a0, a1);
        case 337: return fde_func_0337_0x076a10(a0, a1);
        case 338: return fde_func_0338_0x0773e8(a0, a1);
        case 339: return fde_func_0339_0x07740c(a0, a1);
        case 340: return fde_func_0340_0x077620(a0, a1);
        case 341: return fde_func_0341_0x0776bc(a0, a1);
        case 342: return fde_func_0342_0x07acd4(a0, a1);
        case 343: return fde_func_0343_0x07b040(a0, a1);
        case 344: return fde_func_0344_0x07b0dc(a0, a1);
        case 345: return fde_func_0345_0x07b44c(a0, a1);
        case 346: return fde_func_0346_0x07ba1c(a0, a1);
        case 347: return fde_func_0347_0x07bb58(a0, a1);
        case 348: return fde_func_0348_0x07cbe4(a0, a1);
        case 349: return fde_func_0349_0x07cdf0(a0, a1);
        case 350: return fde_func_0350_0x07cdf8(a0, a1);
        case 351: return fde_func_0351_0x07cdfc(a0, a1);
        case 352: return fde_func_0352_0x07d050(a0, a1);
        case 353: return fde_func_0353_0x07d204(a0, a1);
        case 354: return fde_func_0354_0x07d414(a0, a1);
        case 355: return fde_func_0355_0x07d55c(a0, a1);
        case 356: return fde_func_0356_0x07d844(a0, a1);
        case 357: return fde_func_0357_0x07db2c(a0, a1);
        case 358: return fde_func_0358_0x07db8c(a0, a1);
        case 359: return fde_func_0359_0x07dc50(a0, a1);
        case 360: return fde_func_0360_0x07dd24(a0, a1);
        case 361: return fde_func_0361_0x07de0c(a0, a1);
        case 362: return fde_func_0362_0x07df04(a0, a1);
        case 363: return fde_func_0363_0x07e034(a0, a1);
        case 364: return fde_func_0364_0x07e120(a0, a1);
        case 365: return fde_func_0365_0x07e158(a0, a1);
        case 366: return fde_func_0366_0x07e1a0(a0, a1);
        case 367: return fde_func_0367_0x07e768(a0, a1);
        case 368: return fde_func_0368_0x07efb4(a0, a1);
        case 369: return fde_func_0369_0x07f3fc(a0, a1);
        case 370: return fde_func_0370_0x07f9a0(a0, a1);
        case 371: return fde_func_0371_0x07f9f4(a0, a1);
        case 372: return fde_func_0372_0x07fd30(a0, a1);
        case 373: return fde_func_0373_0x07fd88(a0, a1);
        case 374: return fde_func_0374_0x08012c(a0, a1);
        case 375: return fde_func_0375_0x0801cc(a0, a1);
        case 376: return fde_func_0376_0x08057c(a0, a1);
        case 377: return fde_func_0377_0x080ad8(a0, a1);
        case 378: return fde_func_0378_0x0811f8(a0, a1);
        default: return 0ULL;
    }
}